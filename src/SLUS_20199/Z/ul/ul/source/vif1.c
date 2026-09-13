#include "common.h"
#include "types.h"

// vif1.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0
    unsigned char mark; // Offset: 0x2
    unsigned char id; // Offset: 0x3
    struct _sceDmaTag* next; // Offset: 0x4
    unsigned int p[2]; // Offset: 0x8
} _sceDmaTag;

// Size: 0x4
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

// Size: 0x90
typedef struct DmaVif
{
    // Size: 0x4
    Chcr chcr; // Offset: 0x0
    unsigned int p0[3]; // Offset: 0x4
    void* madr; // Offset: 0x10
    unsigned int p1[3]; // Offset: 0x14
    unsigned int qwc; // Offset: 0x20
    unsigned int p2[3]; // Offset: 0x24
    // Size: 0x10
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
} DmaVif;

// Size: 0x360
typedef struct VulsysSystem
{
    unsigned int KeepMemSize; // Offset: 0x0
    signed int Pal; // Offset: 0x4
    signed int Interlace; // Offset: 0x8
    signed short ScreenMode; // Offset: 0xC
    signed short ScreenWidth; // Offset: 0xE
    signed short ScreenHeight; // Offset: 0x10
    signed short ScreenYofs; // Offset: 0x12
    signed int EvenOdd; // Offset: 0x14
    unsigned long Frame; // Offset: 0x18
    signed int PadInit; // Offset: 0x20
    // Size: 0x90
    DmaVif* DmaGif; // Offset: 0x24
    // Size: 0x90
    DmaVif* DmaVif0; // Offset: 0x28
    // Size: 0x90
    DmaVif* DmaVif1; // Offset: 0x2C
    unsigned char DBuff[0x330]; // Offset: 0x30
} VulsysSystem;

// SCE includes /////////////////////////////////////////////////////////////////////
void FlushCache(signed int mode);
void sceDmaSend(DmaVif* dmaVif, void* tag);
signed int sceDmaSync(DmaVif* dmaVif, signed int mode, signed int flag);

//// Globals /////////////////////////////////////////////////////////////////////////

extern VulsysSystem vulsysSystem; // Address: 0x2F3A50

// Address: 0x1373F0
void ulvif1DmaSend(__int128* dma) {
    FlushCache(0);
    sceDmaSend(vulsysSystem.DmaVif1, dma);
}

// Address: 0x137430
void ulvif1DmaWait() {
    sceDmaSync(vulsysSystem.DmaVif1, 0, 0);
}
