#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// spr.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x3F13C
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0
    unsigned char mark; // Offset: 0x2
    unsigned char id; // Offset: 0x3
    struct _sceDmaTag* next; // Offset: 0x4
    unsigned int p[2]; // Offset: 0x8
} _sceDmaTag;

// Size: 0x4, DWARF: 0x3EFA5
typedef struct Chcr
{
    unsigned int DIR : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned int p0 : 1; // Offset: 0x0, Bit Offset: 1, Bit Size: 1
    unsigned int MOD : 2; // Offset: 0x0, Bit Offset: 2, Bit Size: 2
    unsigned int ASP : 2; // Offset: 0x0, Bit Offset: 4, Bit Size: 2
    unsigned int TTE : 1; // Offset: 0x0, Bit Offset: 6, Bit Size: 1
    unsigned int TIE : 1; // Offset: 0x0, Bit Offset: 7, Bit Size: 1
    unsigned int STR : 1; // Offset: 0x0, Bit Offset: 8, Bit Size: 1
    unsigned int p1 : 7; // Offset: 0x0, Bit Offset: 9, Bit Size: 7
    unsigned int TAG : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
} Chcr;

// Size: 0x90, DWARF: 0x3ED42
typedef struct Spr
{
    Chcr chcr; // Offset: 0x0
    unsigned int p0[3]; // Offset: 0x4
    void* madr; // Offset: 0x10
    unsigned int p1[3]; // Offset: 0x14
    unsigned int qwc; // Offset: 0x20
    unsigned int p2[3]; // Offset: 0x24
    _sceDmaTag* tadr; // Offset: 0x30
    unsigned int p3[3]; // Offset: 0x34
    void* as0; // Offset: 0x40
    unsigned int p4[3]; // Offset: 0x44
    void* as1; // Offset: 0x50
    unsigned int p5[3]; // Offset: 0x54
    unsigned int p6[4]; // Offset: 0x60
    unsigned int p7[4]; // Offset: 0x70
    void* sadr; // Offset: 0x80
    unsigned int p8[3]; // Offset: 0x84
} Spr;

// SCE includes /////////////////////////////////////////////////////////////////////
Spr* sceDmaGetChan(int id);
void sceDmaSendN(Spr* send, void* address, int size);

// DWARF: 0x3F37A
// Address: 0x141AA0
void ulsprMemcpy(__int128* dst /* 0x40(r29) */, __int128* src /* 0x50(r29) */, signed int qwc /* 0x60(r29) */) {
    Spr* from_spr; // r16
    Spr* to_spr; // r17
    void* spr; // r18

    from_spr = sceDmaGetChan(8);
    to_spr = sceDmaGetChan(9);
    spr = 0;
    to_spr->sadr = spr;
    from_spr->sadr = spr;
    sceDmaSendN(to_spr, (void*)((s32)src & 0xFFFFFFF), qwc);
    sceDmaSync(to_spr, 0, 0);
    sceDmaRecvN(from_spr, (void*)((s32)dst & 0xFFFFFFF), qwc);
    sceDmaSync(from_spr, 0, 0);
}
