# Summary

LINK is a genric data container type for any data that is made of multiple components, (e.g. models, textures) It's identified by the magic identifier `FL!!` and more than half of the `DATA.DAT` entries are LINK containers, housing most of the games models and textures (though not *all*),

The format is follows this structure: a header, a table of data blocks, followed by the data blocks. The `.DAT` file doesn't contain information on the contents of these `LINK` data blocks as the game hardcodes it's expected locations an the functions that request it know what to expect. For example, one function may be expecting character models in blocks 0-3, and another function may be expecting level model data in blocks 4 through 6 as a random example.

The code calls these `Data`/`Link` structures, whhich they're handled in `tmlink.c`.

# Overview

```
Header (16 bytes)
Block table (num * 16 bytes)
Block data
```

## Header Structure

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Magic Number: `FL!!` (0x21214C46) |
| 0x04 | 4 bytes | Version (always 1) |
| 0x08 | 4 bytes | Number of blocks |
| 0x0C | 4 bytes | Reserved |

## Block Table

One 16 byte descriptor per block, starting at `+0x10`:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Offset of the block's data, relative to the start of the container |
| 0x04 | 4 bytes | Size of the block's data in bytes |
| 0x08 | 8 bytes | Reserved |

## Loading Link Data

`tmlinkMappingData` is the whole of the format's runtime handling. It records the header and block table addresses, then rewrites every block offset into an absolute pointer:

```c
void tmlinkMappingData(void *addr, Link *data) {
    data->head  = addr;
    data->block = (Block *)((u8 *)addr + 0x10);
    for (ii = 0; ii < data->head->num; ii++)
        data->block[ii].addr += (u32)addr;
}
```

Function callers then use `data.block[i].addr` and `.size` directly. This data indexing strategy is similar to what's done in [VMD.md](VMD.md) containers and it's own internal data tables/strucutres. This also implies they're intentionally kept to a similar size so that they can be addressed and indexed in a fixed array.

## Where Link data is used

| Container | Blocks |
|-----------|--------|
| Course Base/Draw/DFar/DNear | One terrain component to each |
| Course BUtd/DUtd/OUtd | UTD texture containers, paired to indices with the terrain sections |
| Course Event | Animation data, then alternating model and texture pairs |
| Character wear  | Block 0 is the VMD model, blocks 2 and 3 the normal and alternate UTD textures |
| Create-a-rider parts | One part model plus it's textures |
| Vibration data | 16 small blocks of rumble patterns |
| GameEtc | Four blocks of per-course miscellaneous data |

See [course_data.md](course/course_data.md) for how the course components fit together, and [VMD.md](VMD.md) / [UTD.md](UTD.md) for common data formats inside the blocks.
