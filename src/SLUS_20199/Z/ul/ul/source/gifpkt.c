#include "common.h"
#include "types.h"

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop)<<15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim)<<47) | ((unsigned long)(flg)<<58) | ((unsigned long)(nreg)<<60))

#define SCE_GIF_PACKED_AD   0x0e

// gifpkt.c structs /////////////////////////////////////////////////////////////////

// Size: 0x20
typedef struct UlpktALPHA
{
    unsigned long ul[4]; // Offset: 0x0
} UlpktALPHA;

// Size: 0x40
typedef struct UlpktF3
{
    unsigned long ul[8]; // Offset: 0x0
} UlpktF3;

// Size: 0x50
typedef struct UlpktG3
{
    unsigned long ul[10]; // Offset: 0x0
} UlpktG3;

// Size: 0x20
typedef struct UlpktF4
{
    unsigned long ul[4]; // Offset: 0x0
} UlpktF4;

// Size: 0x60
typedef struct UlpktG4
{
    unsigned long ul[12]; // Offset: 0x0
} UlpktG4;

// Size: 0x70
typedef struct UlpktFT4
{
    unsigned long ul[14]; // Offset: 0x0
} UlpktFT4;

// Size: 0x20
typedef struct UlpktGT4
{
    unsigned long ul[4]; // Offset: 0x0
} UlpktGT4;

//// Function Declarations //////////////////////////////////////////////////////////

void ulpktInitALPHA(UlpktALPHA* pkt, signed int ctext);
void ulpktInitF3(UlpktF3* pkt, signed int ctext);
void ulpktInitG3(UlpktG3* pkt, signed int ctext);
void ulpktInitF4(UlpktF4* pkt, signed int ctext);
void ulpktInitG4(UlpktG4* pkt, signed int ctext);
void ulpktInitFT4(UlpktFT4* pkt, signed int ctext, signed int fst);
void ulpktInitGT4(UlpktGT4* pkt, signed int ctext, signed int fst);

//// Functions //////////////////////////////////////////////////////////////////////

void ulpktInitALPHA(UlpktALPHA* pkt, signed int ctext)
{
    pkt->ul[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 1);
    pkt->ul[1] = SCE_GIF_PACKED_AD;
    pkt->ul[2] = 0x44;
    pkt->ul[3] = ctext == 0 ? 0x42 : 0x43;
}

void ulpktInitF3(UlpktF3* pkt, signed int ctext)
{
    pkt->ul[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 6);
    pkt->ul[1] = 0xF44410;
    pkt->ul[2] = ((unsigned long)ctext << 9) | 0x3;
    pkt->ul[7] = 0;
}

void ulpktInitG3(UlpktG3* pkt, signed int ctext)
{
    pkt->ul[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 8);
    pkt->ul[1] = 0xF4141410;
    pkt->ul[2] = ((unsigned long)ctext << 9) | 0xB;
    pkt->ul[9] = 0;
}

void ulpktInitF4(UlpktF4* pkt, signed int ctext)
{
    pkt->ul[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 6);
    pkt->ul[1] = 0x444410;
    pkt->ul[2] = ((unsigned long)ctext << 9) | 0x4;
}

void ulpktInitG4(UlpktG4* pkt, signed int ctext)
{
    pkt->ul[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 0xA);
    pkt->ul[1] = 0xF414141410;
    pkt->ul[2] = ((unsigned long)ctext << 9) | 0xC;
    pkt->ul[11] = 0;
}

void ulpktInitFT4(UlpktFT4* pkt, signed int ctext, signed int fst)
{
    pkt->ul[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 0xC);
    if (fst == 0) {
        pkt->ul[1] = ctext == 0 ? 0xF42424242160 : 0xF42424242170;
    } else {
        pkt->ul[1] = ctext == 0 ? 0xF43434343160 : 0xF43434343170;
    }
    pkt->ul[2] = (((unsigned long)fst << 8) | 0x14) | ((unsigned long)ctext << 9);
    pkt->ul[13] = 0;
}

void ulpktInitGT4(UlpktGT4* pkt, signed int ctext, signed int fst)
{
    pkt->ul[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 0xE);
    if (fst == 0) {
        pkt->ul[1] = ctext == 0 ? 0x41241241241260 : 0x41241241241270;
    } else {
        pkt->ul[1] = ctext == 0 ? 0x41341341341360 : 0x41341341341370;
    }
    pkt->ul[2] = (((unsigned long)fst << 8) | 0x1C) | ((unsigned long)ctext << 9);
}
