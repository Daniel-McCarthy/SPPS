# Summary

VMD is the game's model container storing: meshes, their materials, and a skeleton. Fortunately it does have an identifier/magic number: the four bytes `VMD\x02`. The identifier is checked checked one byte at a time at the top of `ulvumdlInitModel`.

The model format pre-built stream of VIF packets that gets DMA'd straight into the VU0 pipeline, and its layout is defined by the `vuprgDrawModel` assembly microprogram embedded into the binary rather than C code.

# Overview

```
Header (20 bytes)
Type table (type_count * 16 bytes)
  Mesh chain (variable length, one per mesh)
    Material table (material_count * 32 bytes)
    VIF packet stream (consumed by the VU0 microprogram)
Joint table (joint_count * 144 bytes)
```

## Header Structure

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Magic identifier `VMD\x02` |
| 0x04 | 4 bytes | Number of types |
| 0x08 | 4 bytes | Offset to the type table, in units of 16 bytes |
| 0x0C | 4 bytes | Number of joints |
| 0x10 | 4 bytes | Offset to the joint table, in units of 16 bytes |

Both offsets are multiplied by 16 and added to the container's base address and written back in place to pointers when the model loads (similar to what's done for the LINK containers and their block offsets).

## Types

A "type" is a group of meshes. Each record is 16 bytes:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Number of meshes in this type |
| 0x04 | 4 bytes | Offset to the mesh chain, in units of 16 bytes|

The offset of Type records with a mesh count of zero resolve back to the container base and are just unused slots. Simple prop objects will tend to have a single type and joint where characters will have several types for a skeleton.

## Meshes

Meshes are variable length and chained rather than indexed. Each starts with a 32 byte header, and the next mesh sits at `cursor + 0x20 + (qword_count * 16)`.

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Number of 16-byte qwords following the header |
| 0x04 | 4 bytes | Flags |
| 0x08 | 4 bytes | Number of materials |
| 0x0C | 20 bytes | Not read by code; DMA'd to the VU0 as part of the setup |

The qword count covers everything after the header, materials included. Two known flag bits:

- `0x2` selects which of two equivalent VIF submission paths `ulvumdlDrawModel` uses.
- `0x30000` (either of two bits) picks which of the two texture descriptor arrays passed into the model to resolve materials against, and also suppresses drawing: `ulvumdlDrawModel` skips a mesh with this set entirely thus submitting no geometry. Materials are still resolved at load time.

Those skipped meshes are common and a number of models have at least one. The bytesafter their material table aren't geometry. It's not currently clear what the data is nor the purpose.

## Materials

Material records are 32 bytes and sit at the front of the mesh's qword stream, one per material:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 2 bytes | Texture index before loading |
| 0x00 | 8 bytes | The resolved 64-bit GS `TEX0` register, after loading |
| 0x08 | 4 bytes | Number of vertices in this material's strip |
| 0x0C | 4 bytes | Joint binding: `4 * joint_index`, or 0xFFFFFFFF for a skinned mesh |

At load time `ulvumdlInitModel` walks the material list, reads the texture index, looks the texture up in the UTD descriptor array with `ultexGetTEX0`, and writes the resulting register value back over the index.

Each material is drawn as its own independent GS triangle strip, not as a slice of one strip spanning the mesh. The VU0 draw loop has an outer per-material counter around an inner per-vertex loop, and issues an `xgkick` at the end of each material before moving to the next.

The vertex count at `+0x08` is the length of that material's strip.

### Joint binding

A mesh is attached to the skeleton in one of two ways, and which one applies is a property of the mesh:

- **Rigid meshes** take their joint from the material record's `+0x0C` field. The stored value is `4 * joint_index`, which a VU memory address rather than a real index. The VU code adds fixed offsets to it to reach that joint's view/clip, world and normal matrices.
- **Skinned meshes** carry 0xFFFFFFFF in every material and take a joint per vertex from an extra control stream instead.

## Joints

Joint records are 144 (0x90) bytes each. Each is passed to `ulcodLinkCoordinate` at load to link it to it's parent, building the skeleton that `aVuMdlCoord` later traverses upwards to build matrices. Then `ulvumdlDrawModel` reads them back with `ulcodGetLwMatrix` at the same stride. The  layout of a joint record hasn't been fully documented but appear similar to other matrix structures.

## Vertex data

The rest of a mesh's qword stream is a VIF packet stream. UNPACK commands interleaved with packed vertex data, addressed to VU memory. `ulvumdlDrawModel` uploads the `vuprgDrawModel` microprogram and sends two setup qwords built from the mesh header. Then references the stream directly with `sceVif1PkRef`.

The microprogram is VU0 machine code embedded in the (`vuprgDrawModel` at 0x002A8000 in the US final).

Rigid meshes use four streams per vertex: position, normal, a third attribute, and UVs. Skinned meshes add a leading control stream of joint addresses.

### Blend skinning

Most meshes are skinned across more than one joint. In that case the control stream holds several joint addresses per vertex, terminated by a `-1`, and the position and normal streams hold one sample per influence rather than one per final vertex.

The VU0 blend loop transforms each sample by its own joint's matrix, multiplies the result by the W component of that sample's position, and accumulates:

```
vertex = sum over influences of weight_i * (joint_matrix_i * position_i)
```


## Notes

- Traversing mesh chain is the only way to enumerate meshes. There's no count of bytes or index table.
- Texture indices resolve against a descriptor array derived from a UTD container (see [UTD.md](UTD.md)), which must therefore be loaded before the model that uses it.
