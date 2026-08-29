# Summary

UTD is the game's texture container. It has no magic number / identifier. It's simply a `*.DAT*` entry that gets handed to the `ultex*` functions in `TEX.s`. The source only ever refers to these texture entries as `utd` pointers, so that's the name used here. 

A UTD entry has a header header in the form of a a table of texture entries, and then a stream of pixel data with palettes mixed into it. The pixels are stored as the GS wants them, so loading a texture is is simply a DMA transfer. `ultexTransTex` walks the entries and issues a `sceGsSetDefLoadImage`/`sceGsExecLoadImage` pair per texture.

# Overview

```
Header (16 bytes)
Entry table (num * 16 bytes)
Data stream (pixels (with CLUTs) interleaved)
```

## Header Structure

| Offset | Size | Description |
|--------|------|-------------|
| 0x00   | 4 bytes | Float (1.0) |
| 0x04   | 4 bytes | Number of entries (`num`) |
| 0x08   | 4 bytes | Mipmap level |
| 0x0C   | 4 bytes | Number of GS blocks the whole container occupies |


The mipmap levels of zero indicate a plain texture and handling of the texture is adjusted. If there is a positive non-zero mipmap level then `ultexTransTex` dispatches to `ultexTransTexNonMipMap` or `ultexTransTexMipMap` if there is none.

The block count is added to the global GS memory cursor (`vultexSystem`) once the container has been transferred, which is how consecutive containers stack up in VRAM without a real allocator.

## Entry Table

The entry table starts immediately after the header at `+0x10`, with one 16-byte record per entry:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 2 bytes | Destination X in GS memory, relative to the current cursor |
| 0x02 | 2 bytes | Destination Y in GS memory, relative to the current cursor |
| 0x04 | 2 bytes | Width in pixels |
| 0x06 | 2 bytes | Height in pixels |
| 0x08 | 4 bytes | Unused |
| 0x0C | 2 bytes | Bits per pixel |
| 0x0E | 2 bytes | Bits per palette entry |

Bits per pixel maps onto a GS pixel storage mode:

| Value | GS PSM | Meaning |
|-------|--------|---------|
| 32 (0x20) | `PSMCT32` | 32 bit direct colour |
| 16 (0x10) | `PSMCT16` | 16 bit direct colour |
| 8  (0x08) | `PSMT8`   | 8 bit paletted |
| 4  (0x04) | `PSMT4`   | 4 bit paletted |

In practice the archive's in-game textures are all paletted, via `PSMT4` or `PSMT8`.

## Payload

The pixel stream starts right after the entry table, at `header + 0x10 + (num * 0x10)`. Each entry consumes

```
byte_size = ceil(width * height * bpp / 8)
```

bytes, followed by its palette if it has one. There are no per-entry offsets, so entries have to be walked in order (you can't jump directly to entry `n`).

### Pixel layout

The pixels are a structured left to right and top to bottom, not pre-swizzled into GS page/block/column order. For `PSMT8` that's one byte per pixel; for `PSMT4`, one nibble per pixel with the low nibble first.

While the textures *do* get swizzled, the textures get DMA'd directly and the swizzle happens in hardware. `sceGsSetDefLoadImage` builds a GIF image-mode transfer, and the GS does the page/block reordering itself as it writes the linear source buffer.

### Palettes

The palette bit depth field at `+0x0E` says how a palette is stored, rather than the palette format:

| Value | Meaning |
|-------|---------|
| 16 (0x10) | Palette colours are 16-bit (`PSMCT16`) |
| 32 (0x20) | Palette colours are 32-bit (`PSMCT32`) |
| Anything else | No palette |

The number of colours comes from the *pixel* format instead: 16 for `PSMT4`, 256 for `PSMT8`. So a palette is 0x20, 0x40, 0x200 or 0x400 bytes depending on the combination.

Alpha depends on the palette depth, and the 16-bit case is not what you'd expect. In a 32-bit palette the fourth byte is the alpha value directly, in the PS2 convention where 0x80 is fully opaque. In a 16-bit (ABGR1555) palette the single top bit is only a selector into the GS `TEXA` register, and the game programs `TEXA` during GS init in `gmsysInitGsRegister`, with `TA0 = 0x80` and `TA1 = 0x00`:

| Top bit | Resulting alpha |
|---------|-----------------|
| clear | 0x80 - fully opaque |
| set   | 0x00 - fully transparent |


## Mipmaps

When the header's mipmap level is *n*, each logical texture occupies `n + 1` consecutive entries, best queality first, so texture *t* starts at entry `t * (n + 1)`.

`ultexTransTexMipMap` walks the entries with the same running payload cursor as the non-mipmap path, but only processes the palette after a texture's last (smallest) level:

```c
if (index % (header->mipmap_level + 1) == header->mipmap_level) {
    /* transfer CLUT */
}
```

so one palette is stored per texture and every level of that texture shares it:

```
[level 0 pixels][level 1 pixels] ... [level n pixels][palette]
```


## Notes

- Formats `PSMCT32` and`PSMCT16` are valid but have not yet been spotted and everything has been paletted.
- Course texture data is wrapped one level up in a LINK container (see [LINK.md](LINK.md)): the BUtd, DUtd and OUtd course components are `FL!!` containers whose blocks are UTD data, paired by index with the terrain sections they texture. AlphaUtd and the two BgUtd entries are bare UTD data with no wrapper.
