#include "common.h"

// Size: 0x10, DWARF: 0xB5FF6
typedef struct DataHead
{
    char magic[4]; // Offset: 0x0, DWARF: 0xB6011
    signed int ver; // Offset: 0x4, DWARF: 0xB6035
    signed int num; // Offset: 0x8, DWARF: 0xB6055
    signed int res; // Offset: 0xC, DWARF: 0xB6075
} DataHead;

// Size: 0x10, DWARF: 0xB5F07
typedef struct DataBlock
{
    signed int addr; // Offset: 0x0, DWARF: 0xB5F22
    signed int size; // Offset: 0x4, DWARF: 0xB5F43
    signed int res[2]; // Offset: 0x8, DWARF: 0xB5F64
} DataBlock;

// Size: 0x8, DWARF: 0xB5F8A
typedef struct Data
{
    // Size: 0x10, DWARF: 0xB5FF6
    DataHead* head; // Offset: 0x0, DWARF: 0xB5FA5
    // Size: 0x10, DWARF: 0xB5F07
    DataBlock* block; // Offset: 0x4, DWARF: 0xB5FCB
} Data;

//// Function Declarations ///////////////////////////////////////////////////////////

void tmlinkMappingData(unsigned int addr, Data* data);

// DWARF: 0xB613A
// Address: 0x197440
// Size: 0x88
void tmlinkMappingData(unsigned int addr, Data* data) {
    signed int ii; // r16

    data->head = (DataHead*)addr;
    data->block = (DataBlock* ) (addr + 0x10);
    for (ii = 0; ii < data->head->num; ii++) {
        data->block[ii].addr += addr;
    }
}
