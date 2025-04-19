// tmlink.c context
// Last updated 9/16/2024
// SPPS NTSC-U 201.99 Final

typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;
typedef unsigned int u_int;
typedef __int128 int128;
typedef __int128 s128;
typedef unsigned __int128 u_int128;

#define ABORT() asm(".word 0x0000000d")

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));


// Static data ///////////////////////////////////////////////////////////////////////

// tmlink.c structs ////////////////////////////////////////////////////////////////////

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

//// Variables ///////////////////////////////////////////////////////////////////////

//// Function Declarations ///////////////////////////////////////////////////////////

void tmlinkMappingData(unsigned int addr, // Size: 0x8, DWARF: 0xB5F8A
Data* data);

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