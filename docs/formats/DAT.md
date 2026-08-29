# Summary

The `DATA.DAT` file is a custom archive format used by all versions of Shaun Palmer's Pro Snowboarder (SPPS) to package game assets (level data, models, textures, and other data). It's structured into 2048 byte sectors for efficient reading with CD/DVD seeking reads.

The file consists of a header, an array of entry descriptors, and the data of all files. The header is 16 bytes and contains a version number, the number of entries, the offset to the sectored data area, and a reserved field. Each entry descriptor is 8 bytes, containing the offset and size of a file's data in sectors.

The `*.DAT*` file does not include file names nor identifiers for the entries. The game at times hardcodes memory locations in the `.DAT` file and attributes helpful names to that section of data, but there is no such information in the archive.

The game accesses `DATA.DAT` via functions in `cdvd.c`, which correspond to the `VuldvdHead` and `VuldvdData` structures.

This file is stored in the root of the game disc as `DATA.DAT` (though can be in folders for the demo releases).

# Overview

The file consists of three main parts:
1. A fixed-size header
2. An array of entry descriptors
3. The actual data which is stored into 2048 byte sectors

## Header Structure

The header is 16 bytes (0x10) in size and located at the very beginning of the file:

| Offset | Size | Description |
|--------|------|-------------|
| 0x00   | 4 bytes | Version number (always 1?) |
| 0x04   | 4 bytes | Number of entries in the archive |
| 0x08   | 4 bytes | Offset to the sectored data area |
| 0x0C   | 4 bytes | Reserved/padding (always 0?) |

*Note: All values are stored in little-endian format.*

## Entry Descriptors

Following the header, there is an array of entry descriptors, one for each file in the archive. Each descriptor is 8 bytes (0x08):

| Offset | Size | Description |
|--------|------|-------------|
| 0x00   | 4 bytes | Offset of the file's data (in sectors from start of file) |
| 0x04   | 4 bytes | Size of the file's data (in sectors) |

The number of descriptors matches the `num` field in the header.
The data is sectored however the size may result in the data covering multiple sectors or be less than the sector size causing it to pad to the start of the next sector.

## Data Area

The actual file data begins at the offset specified in the header (converted from sectors to bytes by multiplying by the 2048 byte sector size). Each entry's data is stored contiguously in the order they appear in the entry table.

To locate a specific file's data:
- Byte offset = (entry.offset × 2048)
- Size in bytes = (entry.size × 2048)

## Sector Alignment

The format uses 2048 byte sectors, matching the PS2's CD/DVD sector size. This alignment optimizes data retrieval for disk reads. Note that the header and entry table themselves are not aligned, but all file data within the archive starts on sector boundaries.

## Usage in SPPS

The game accesses `DATA.DAT` through CD/DVD read functions in `cdvd.c`. The header structure corresponds to the `VuldvdHead` and `VuldvdData` structures used by the game's file system layer. When the game needs a specific resource, it:
1. Looks up the entry by index (known from internal tables)
2. Calculates the data location using the sector-based offsets and sizes
3. Reads the raw data directly from the archive

An entry's data will be one of a few container formats: [LINK.md](LINK.md) for the `FL!!` multiblock wrapper, [VMD.md](DAT_Entry_Formats/VMD.md) for model data, [UTD.md](DAT_Entry_Formats/UTD.md) for texture data, [RAW.md](DAT_Entry_Formats/RAW.md) for everything else, and [course/course_data.md](course/course_data.md) for how a level's course components are structured together.
