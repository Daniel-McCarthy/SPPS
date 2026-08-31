# Summary

The game stores each of its 8 courses as a collection of 17 distinct data components. Courses are contained within the `DATA.DAT` file as are the textures and models. The game uses a hardcoded table (`crs_tbl`) to map course numbers and component types to specific entries in the archive.

## Course Table (`crs_tbl`)

The table `s32 crs_tbl[8][17]` is defined in `sploadSetCourse`. Each row corresponds to a course (0-7), and each column to a specific component type (Base, Draw, Vector, Rail, Bonk, etc.). The value at `crs_tbl[course][component]` is the index of the `DATA.DAT` entry that holds that component's data for the given course. A `-1` indicates that the component isn't used by or provided for that course.

The column order below comes from reading `sploadSetCourse` itself - which `vsploadCourse` field each column is loaded into - cross-checked against `tmcrsInit`, which reads those same fields back at fixed struct offsets (`+0x2A4` Hit, `+0x2A8` Vector, `+0x2AC` Rail, `+0x2B0` Bonk) to hand them to `tmcrsInitHit`/`tmcrsInitVector`/`tmcrsInitRail`/`tmcrsInitBonk`.

## Component Types

| Column | Component | Format | Description |
|--------|-----------|--------|-------------|
| 0  | Base     | LINK | Core course geometry/terrain and collision data. |
| 1  | Draw     | LINK | Core course objects (e.g. buildings/fences/props/towers/non-terrain course models). |
| 2  | DFar     | LINK | Far-scene low LOD objects (low poly trees/fences/objects etc.) |
| 3  | DNear    | LINK | Near-scene high LOD objects (additional detail objects loaded in near scene, higher poly trees) |
| 4  | BUtd     | LINK | Building UTD texture data, one set per Base section. |
| 5  | DUtd     | LINK | Detail UTD texture data (non-terrain), one set per Draw/DFar/DNear section. |
| 6  | Object   | RAW  | Object model data. |
| 7  | OUtd     | LINK | Object UTD texture data. |
| 8  | Alpha    | RAW  | Alpha-blended draw geometry. |
| 9  | AlphaUtd | UTD  | Alpha UTD texture data. |
| 10 | BgUtd0/1 | UTD  | Background UTD texture data. This column loads *two* consecutive entries, `index` and `index + 1`. |
| 11 | BgUmd    | VMD  | Background model data. |
| 12 | Event    | LINK | Event-specific course data: an animation block followed by alternating model/texture pairs for animated course objects. |
| 13 | Hit      | RAW  | Collision data. |
| 14 | Vector   | RAW  | Animation paths for objects or cameras. |
| 15 | Rail     | RAW  | Grindable rail spline data - see [Rail Data](#rail-data) below. |
| 16 | Bonk     | RAW  | Objects that the player can collide with for tricks. |

The Dutd lookup (column 5) is the one entry index the game adjusts at load time: it's offset by the playable character, so the detail texture set changes with who you're riding as.

### Course to entry mapping

Entry indices for the US final archive (`SLUS_201.99`). `-1` means the course doesn't use that component.

| Course | Base | Draw | DFar | DNear | BUtd | DUtd | Object | OUtd | Alpha | AlphaUtd | BgUtd0 | BgUtd1 | BgUmd | Event | Hit | Vector | Rail | Bonk |
|--------|------|------|------|-------|------|------|--------|------|-------|----------|--------|--------|-------|-------|-----|--------|------|------|
| 0 Donner Ski Ranch | 0x53 | 0x54 | 0x56 | 0x55 | 0x59 | 0x5A | 0x58 | 0x68 | 0x57 | 0x67 | 0x38 | 0x39 | 0x3A | 0x120 | 0x69 | 0x6A | 0x6B | 0x6C |
| 1 Aspen | 0x6D | 0x6E | 0x70 | 0x6F | 0x73 | 0x74 | 0x72 | 0x82 | 0x71 | 0x81 | 0x3B | 0x3C | 0x3D | 0x121 | 0x83 | 0x84 | 0x85 | 0x86 |
| 2 Kirkwood | 0x87 | 0x88 | 0x8A | 0x89 | 0x8D | 0x8E | 0x8C | 0x9C | 0x8B | 0x9B | 0x3E | 0x3F | 0x40 | 0x122 | 0x9D | 0x9E | 0x9F | 0xA0 |
| 3 Heavenly | 0xA1 | 0xA2 | 0xA4 | 0xA3 | 0xA7 | 0xA8 | 0xA6 | 0xB6 | 0xA5 | 0xB5 | 0x41 | 0x42 | 0x43 | 0x123 | 0xB7 | 0xB8 | 0xB9 | 0xBA |
| 4 Snowbird | 0xBB | 0xBC | 0xBE | 0xBD | 0xC1 | 0xC2 | 0xC0 | 0xD0 | 0xBF | 0xCF | 0x44 | 0x45 | 0x46 | 0x124 | 0xD1 | 0xD2 | 0xD3 | -1 |
| 5 Squaw Valley USA | 0xD4 | 0xD5 | 0xD7 | 0xD6 | 0xDA | 0xDB | 0xD9 | 0xE9 | 0xD8 | 0xE8 | 0x47 | 0x48 | 0x49 | 0x125 | 0xEA | 0xEB | 0xEC | 0xED |
| 6 Mt. Hood Meadows | 0xEE | 0xEF | 0xF1 | 0xF0 | 0xF4 | 0xF5 | 0xF3 | 0x103 | 0xF2 | 0x102 | 0x4A | 0x4B | 0x4C | 0x126 | 0x104 | 0x105 | 0x106 | 0x107 |
| 7 Gotcha Glacier | 0x108 | 0x109 | 0x10B | 0x10A | 0x10E | 0x10F | 0x10D | 0x11D | 0x10C | 0x11C | 0x4D | 0x4E | 0x4F | 0x127 | 0x11E | -1 | 0x11F | -1 |

Snowbird has no Bonk data, and Gotcha Glacier has neither Vector nor Bonk.

## Data Layout

Each course component is stored as a separate data blob in `DATA.DAT`. The game loads these data blobs sequentially when initializing a course:
1. `sploadSetCourse` reads the `crs_tbl` row for the selected course.
2. For each positive index (not -1) in that row, it calls the DVD read function to extract the corresponding `DATA.DAT` entry.
3. The raw data is then passed to specialized initialization functions (e.g., `tmcrsInitEvent`, `knCoreInit`) that parse the blob into internal structures.

## Container Formats

`DATA.DAT` entries aren't all the same kind of file. Four shapes cover everything a course loads, and the game tells them apart by what asked for the entry rather than by sniffing it - nothing at runtime probes an unknown blob to work out what it is.

| Format | Identifier | Holds |
|--------|---------------|-------|
| LINK | `FL!!` magic | A generic wrapper around several sub-blocks of any other format. |
| VMD  | `VMD\x02` magic | Models: meshes, materials and a skeleton. |
| UTD  | No identifier but starts with float `1.0` | Textures, ready to DMA into GS local memory. |
| RAW  | No identifier butstarts with float `1.0` | Everything else: collision, rails, paths, object placement. |

LINK containers take up the majority of `.DAT` entries, followed by VMD, and then RAW as most common. Most VMD and UTD data lives inside LINK containers rather than at the top level.

The `1.0` at the start of a UTD or RAW entry is recognizable but not an identifier and not read.

Detailed layouts live in their own documents:

- [LINK.md](../LINK.md) - the `FL!!` LINK container
- [VMD.md](../VMD.md) - model containers
- [UTD.md](../UTD.md) - texture containers
- [RAW.md](../RAW.md) - the raw course components: the block grid they share, plus Bonk, Vector, Hit and Alpha
- [DAT.md](../DAT.md) - the `DATA.DAT` archive itself

### Grid partitioned raw sections

Five of the raw course components (Object, Alpha, Hit, Vector and Bonk) open with the same 16 byte header the terrain sections use, followed by one `u32` per block pointing at that block's payload. They're all mapped to the same world grid the collision code uses. Each query only touches the single block that grid block lands in. The grid is split up by 600 unit sections and the levels are split up along that grid. For example, Donner Ski Ranch's grid is 16x35 blocks with its origin at block (-8, -27), and all of the course components adhere to that grid layout.

The exception is the rail data as it's the only raw data component that isn't girdded, it instead defines it's own shape.

[RAW.md](../RAW.md) has the header layout, the init routine, and what's known of each component's structure/data.

## Rail Data

Rail data holds every grindable edge in a course (e.g. rooftops, handrails, lift cables, fences, etc.). It's loaded by `tmcrsInitRail` and checked against the rider's position by `tmcrsGetRailCollision`, both in `tmcrs.c`.

### Container header (16 bytes)

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Always float `1.0` |
| 0x04 | 4 bytes | Course number (course index + 1) |
| 0x08 | 4 bytes | Number of rail records that follow |
| 0x0C | 4 bytes | Always 0 |

The count is the only field that gets read. `tmcrsInitRail` stores the pointer, allocates a `count`-length array of `u32` enable flags and sets them all to 1. `tmcrsSetRailCollision(no, val)` flips one and `tmcrsResetRailCollision` turns them all back on. That array is how the game disables individual rails while a run is in progress.

### Rail record

Records are packed back to back from offset `0x10`, each `0x10 + point_count * 0x10` bytes long. There's no index table thus the rails need to be walked in order. It's not possible to jump to index `x` in the rail record (which is what `tmcrsGetRailCollision` does, skipping past individual rails it's not checking).

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 2 bytes | Minimum grid X cell spanned by this rail |
| 0x02 | 2 bytes | Maximum grid X cell |
| 0x04 | 2 bytes | Maximum grid Z cell |
| 0x06 | 2 bytes | Minimum grid Z cell |
| 0x08 | 2 bytes | Flags (see below) |
| 0x0A | 2 bytes | Number of points in this rail's polyline |
| 0x0C | 4 bytes | Reserved (always 0) |
| 0x10 | 16 bytes each | The points |

Note the field order on the X and Z pairs is mirrored: X is min then max, Z is max then min.

The four grid fields are a quick way to check for the right rail. Since caller has already converted the rider's position into the same 600 unit grid the terrain uses, `tmcrsGetRailCollision` can check a rail with four 16 bit integer compares before doing any floating point work. 

Points are 16 bytes, laid out as an `sceVu0FVECTOR`:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | X |
| 0x04 | 4 bytes | Y |
| 0x08 | 4 bytes | Z |
| 0x0C | 4 bytes | W, always 1.0 |

Coordinates are in the same world space and scale as the terrain. Rails are always the same width, thus there is no attribute for width in the format.

## Notes

- The course data does not include textures directly. Textures are referenced by ID and looked up in a separate texture database (also in `DATA.DAT`).
