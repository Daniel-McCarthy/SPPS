# Summary

RAW refers to several types of raw data stored in an `DATA.DAT` entry that isn't a LINK container and isn't a VMD model. Roughly half the archive data is raw data: UTD textures, sound banks, vibration patterns, and the course components for collision, rails, paths and object placement.

Unfortunately these don't have identifiers/magic numbers.  The game knows what an entry is because a hardcoded index asked for it. A raw data is only meaningful once you know which of the game's init functions it was going to be handed to/handled by.

While most of the raw data entries start with a float of `1.0`, it's not used/checked as any kind of identifier, but it's worth nothing when checking over the raw data.

The rest of this page will go over the course components stored as raw data. Textures however are described in specificity at [UTD.md](UTD.md).

# The raw component block grid

Five of the raw course components - Alpha, Object, Hit, Vector and Bonk - open with the same 16-byte header the terrain sections use, because they're all fit to the same in-game course world grid:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Float (1.0) |
| 0x04 | 2 bytes | Course number (course index + 1) |
| 0x06 | 2 bytes | Total block count, always `size_x * size_y` |
| 0x08 | 2 bytes | Grid width in blocks (`size_x`) |
| 0x0A | 2 bytes | Grid height in blocks (`size_y`) |
| 0x0C | 2 bytes | Grid origin in blocks, on world X |
| 0x0E | 2 bytes | Grid origin in blocks, on world Z |

A grid cell is 600 units square. `tmcrsGetArea` converts a world position into a cell and `tmcrsChangeNo` turns that cell into a block index, so any query only ever retrieves the one block the query point lands in. Every component of a course uses these grid sizes/spacing. For example, Donner Ski Ranch is a 16x35 grid with it;s origin at block `(-8, -27)` for all it's course components.

Alpha, Hit, Vector and Bonk follow the header with one `u32` per block (each byte is an offset of that block's data relative to the section start, or 0 if the block is empty).

Their four init functions (`tmcrsInitAlpha`, `tmcrsInitHit`, `tmcrsInitVector` and `tmcrsInitBonk`) are written identically, only changing which global they write to:

```c
s32 tmcrsInitHit(void *data) {
    vtmcrsHitData.top_addr = 0;
    if (data == NULL) return -1;
    vtmcrsHitData.top_addr = data;
    vtmcrsHitData.head  = data;
    vtmcrsHitData.block = (u32 *)((u8 *)data + 0x10);
    for (ii = 0; ii < vtmcrsHitData.head->nblock; ii++)
        if (vtmcrsHitData.block[ii])
            vtmcrsHitData.block[ii] += (u32)data; 
    return 0;
}
```

This is the same indexing scheme the LINK containers use, with main difference being that an offset zero offset signifying which to ignore.

## Bonk Data

Bonk holds the objects that the bonk trick can be done on, thus simple nad not used as much as the other components.

Each non-empty block is a 16 byte header followed by a flat array of records:

```
+0x00  u32  count      number of records in this block
+0x04  12 bytes        reserved, always 0
+0x10  records         count * 16 byte records
```

Each record defines a spherical collider with a position and radius:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | X |
| 0x04 | 4 bytes | Y |
| 0x08 | 4 bytes | Z |
| 0x0C | 4 bytes | Collision Radius |

`tmcrsGetBonkCollision` does the check to see where the player is in relation to the spherical bonk collider to determine if the character is within it.

The bonk data fits within the `0x10 + (count * 0x10)` sizing, one after another. There can be 0 filled padding afterwards to fit into the sector size. zero padding to the entry's sector size left at the end.

## Vector Data

Vector data is the paths/routes that objects follow allong. This can be for cameras, scripted animation paths, or other moving objects such as the lifts/trams.  the routes the game follows for cameras and moving objects. It's read by `tmcrsGetVectorCollision` and `tmcrsGetVectorCollisionSub`.

Each non-empty block is a flat array of 48 byte records. The record count is stored in the first word of *every* record, so the loader can read it from the block's first four bytes and then start walking:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00 | 4 bytes | Number of records in this block (repeated in every record) |
| 0x04 | 4 bytes | Path attribute |
| 0x08 | 8 bytes | Reserved, always 0 |
| 0x10 | 16 bytes | Segment start point (X, Y, Z, 1.0) |
| 0x20 | 16 bytes | Segment end point (X, Y, Z, 1.0) |

So a record is one *segment* of a path, not one path. Records chain together such that each segment's end point is the next one's starting point until a path finishes and the next record begins somewhere else. Across the seven courses that have Vector data, The path attribute at `+0x04` is used to determine when a path has finished.

Every block is exactly `count * 0x30` bytes.

## Hit Data

Hit is the course's collision geometry and is considerably large in data size. It's the largest of the raw data course components.

The container is the same block block grid above. While it hasn't yet been documented it is known that it gets handled by the following function `David_GetHitCollision2` which retrieves a block via the position using `tmcrsChangeNo`, reads the block's first word as a record count, then uploads the rays to VU0 with `David_PutRaysInVU0`, and hands the block to `David_CheckHitData`, which does the actual intersection calculations with VU0 instructions.

## Alpha Data

Alpha holds the course's alpha-blended geometry (once again using the same block grid). It's initialised by `tmcrsInitAlpha` and drawn by `tmcrsDrawAlpha` with its own texture set from the AlphaUtd entry. Each block starts with a count, and the geometry is submitted through the same VIF/VU0 path the terrain uses. It's not yet fully documented.

## Rail Data

Rail data is the only course component that isn't gridded by blocks. More can be read about it here: [course_data.md](../course/course_data.md#rail-data).

# Other raw data

Beyond course components there are other forms of raw data that is interpreted by the game's functions rather than identified in the `.DAT` file. Below is some of the forms of raw data that aren't course components.

| Entries | Content |
|---------|---------|
| Textures | UTD containers are either bare or as blocks inside a LINK. They're in [UTD.md](UTD.md) format. |
| Sound and voice data | Read by  `sploadSetSound`, misc. sound effects or other needed sounds. |
| Vibration patterns | Vibration data contained in [LINK](Link.md) containers, 16 blocks each |

# Notes

- Because the init functions rewrite block offsets into pointers in place, anything that reads a course section back out of memory sees absolute addresses where the disc has offsets.
