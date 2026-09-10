#include "common.h"
#include "types.h"

#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((unsigned long)(ate) | ((unsigned long)(atst)<<1) | ((unsigned long)(aref)<<4) | \
    ((unsigned long)(afail)<<12) | ((unsigned long)(date)<<14) | ((unsigned long)(datm)<<15) | \
    ((unsigned long)(zte)<<16) | ((unsigned long)(ztst)<<17))

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// akSpSub.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0
    unsigned char mark; // Offset: 0x2
    unsigned char id; // Offset: 0x3
    struct _sceDmaTag* next; // Offset: 0x4
    unsigned int p[2]; // Offset: 0x8
} _sceDmaTag;

// Size: 0x10
typedef struct sceGifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, Bit Offset: 60, Bit Size: 4
} sceGifTag __attribute__((aligned(16)));

// Size: 0x8
typedef struct Test
{
    unsigned long ATE : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long ATST : 3; // Offset: 0x0, Bit Offset: 1, Bit Size: 3
    unsigned long AREF : 8; // Offset: 0x0, Bit Offset: 4, Bit Size: 8
    unsigned long AFAIL : 2; // Offset: 0x0, Bit Offset: 12, Bit Size: 2
    unsigned long DATE : 1; // Offset: 0x0, Bit Offset: 14, Bit Size: 1
    unsigned long DATM : 1; // Offset: 0x0, Bit Offset: 15, Bit Size: 1
    unsigned long ZTE : 1; // Offset: 0x0, Bit Offset: 16, Bit Size: 1
    unsigned long ZTST : 2; // Offset: 0x0, Bit Offset: 17, Bit Size: 2
    unsigned long pad19 : 45; // Offset: 0x0, Bit Offset: 19, Bit Size: 45
} Test;

// Size: 0x8
typedef struct XYZ
{
    unsigned long X : 16; // Offset: 0x0, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 32; // Offset: 0x0, Bit Offset: 32, Bit Size: 32
} XYZ;

// Size: 0x8
typedef struct Color
{
    unsigned int R : 8; // Offset: 0x0, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4
} Color;

// Size: 0x8
typedef struct sceGsPrim
{
    unsigned long PRIM : 3; // Offset: 0x0, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, Bit Offset: 11, Bit Size: 53
} sceGsPrim;

// Size: 0x60
typedef struct Clear
{
    // Size: 0x8
    Test testa; // Offset: 0x0
    signed long testaaddr; // Offset: 0x8
    // Size: 0x8
    sceGsPrim prim; // Offset: 0x10
    signed long primaddr; // Offset: 0x18
    // Size: 0x8
    Color rgbaq; // Offset: 0x20
    signed long rgbaqaddr; // Offset: 0x28
    // Size: 0x8
    XYZ xyz2a; // Offset: 0x30
    signed long xyz2aaddr; // Offset: 0x38
    // Size: 0x8
    XYZ xyz2b; // Offset: 0x40
    signed long xyz2baddr; // Offset: 0x48
    // Size: 0x8
    Test testb; // Offset: 0x50
    signed long testbaddr; // Offset: 0x58
} Clear;

// Size: 0x8
typedef struct Dthe
{
    unsigned long DTHE : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} Dthe;

// Size: 0x8
typedef struct ColClamp
{
    unsigned long CLAMP : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} ColClamp;

// Size: 0x8
typedef struct PrModeCont
{
    unsigned long AC : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} PrModeCont;

// Size: 0x8
typedef struct Scissor
{
    unsigned long SCAX0 : 11; // Offset: 0x0, Bit Offset: 0, Bit Size: 11
    unsigned long pad11 : 5; // Offset: 0x0, Bit Offset: 11, Bit Size: 5
    unsigned long SCAX1 : 11; // Offset: 0x0, Bit Offset: 16, Bit Size: 11
    unsigned long pad27 : 5; // Offset: 0x0, Bit Offset: 27, Bit Size: 5
    unsigned long SCAY0 : 11; // Offset: 0x0, Bit Offset: 32, Bit Size: 11
    unsigned long pad43 : 5; // Offset: 0x0, Bit Offset: 43, Bit Size: 5
    unsigned long SCAY1 : 11; // Offset: 0x0, Bit Offset: 48, Bit Size: 11
    unsigned long pad59 : 5; // Offset: 0x0, Bit Offset: 59, Bit Size: 5
} Scissor;

// Size: 0x8
typedef struct XYOffset
{
    unsigned long OFX : 16; // Offset: 0x0, Bit Offset: 0, Bit Size: 16
    unsigned long pad16 : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
    unsigned long OFY : 16; // Offset: 0x0, Bit Offset: 32, Bit Size: 16
    unsigned long pad48 : 16; // Offset: 0x0, Bit Offset: 48, Bit Size: 16
} XYOffset;

// Size: 0x8
typedef struct Zbuf
{
    unsigned long ZBP : 9; // Offset: 0x0, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 15; // Offset: 0x0, Bit Offset: 9, Bit Size: 15
    unsigned long PSM : 4; // Offset: 0x0, Bit Offset: 24, Bit Size: 4
    unsigned long pad28 : 4; // Offset: 0x0, Bit Offset: 28, Bit Size: 4
    unsigned long ZMSK : 1; // Offset: 0x0, Bit Offset: 32, Bit Size: 1
    unsigned long pad33 : 31; // Offset: 0x0, Bit Offset: 33, Bit Size: 31
} Zbuf;

// Size: 0x8
typedef struct Frame
{
    unsigned long FBP : 9; // Offset: 0x0, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 7; // Offset: 0x0, Bit Offset: 9, Bit Size: 7
    unsigned long FBW : 6; // Offset: 0x0, Bit Offset: 16, Bit Size: 6
    unsigned long pad22 : 2; // Offset: 0x0, Bit Offset: 22, Bit Size: 2
    unsigned long PSM : 6; // Offset: 0x0, Bit Offset: 24, Bit Size: 6
    unsigned long pad30 : 2; // Offset: 0x0, Bit Offset: 30, Bit Size: 2
    unsigned long FBMSK : 32; // Offset: 0x0, Bit Offset: 32, Bit Size: 32
} Frame;

// Size: 0x8
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4
} BgColor;

// Size: 0x8, 0x3BCD
typedef struct Display
{
    unsigned int DX : 12; // Offset: 0x0, Bit Offset: 0, Bit Size: 12
    unsigned int DY : 11; // Offset: 0x0, Bit Offset: 12, Bit Size: 11
    unsigned int MAGH : 4; // Offset: 0x0, Bit Offset: 23, Bit Size: 4
    unsigned int MAGV : 2; // Offset: 0x0, Bit Offset: 27, Bit Size: 2
    unsigned int p0 : 3; // Offset: 0x0, Bit Offset: 29, Bit Size: 3
    unsigned int DW : 12; // Offset: 0x4, Bit Offset: 0, Bit Size: 12
    unsigned int DH : 11; // Offset: 0x4, Bit Offset: 12, Bit Size: 11
    unsigned int p1 : 9; // Offset: 0x4, Bit Offset: 23, Bit Size: 9
} Display;

// Size: 0x8, 0x2DD8
typedef struct DispFb
{
    unsigned int FBP : 9; // Offset: 0x0, Bit Offset: 0, Bit Size: 9
    unsigned int FBW : 6; // Offset: 0x0, Bit Offset: 9, Bit Size: 6
    unsigned int PSM : 5; // Offset: 0x0, Bit Offset: 15, Bit Size: 5
    unsigned int p0 : 12; // Offset: 0x0, Bit Offset: 20, Bit Size: 12
    unsigned int DBX : 11; // Offset: 0x4, Bit Offset: 0, Bit Size: 11
    unsigned int DBY : 11; // Offset: 0x4, Bit Offset: 11, Bit Size: 11
    unsigned int p1 : 10; // Offset: 0x4, Bit Offset: 22, Bit Size: 10
} DispFb;

// Size: 0x8
typedef struct SMode
{
    unsigned int INT : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned int FFMD : 1; // Offset: 0x0, Bit Offset: 1, Bit Size: 1
    unsigned int DPMS : 2; // Offset: 0x0, Bit Offset: 2, Bit Size: 2
    unsigned int p0 : 28; // Offset: 0x0, Bit Offset: 4, Bit Size: 28
    unsigned int p1; // Offset: 0x4
} SMode;

// Size: 0x8
typedef struct PMode
{
    unsigned int EN1 : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned int EN2 : 1; // Offset: 0x0, Bit Offset: 1, Bit Size: 1
    unsigned int CRTMD : 3; // Offset: 0x0, Bit Offset: 2, Bit Size: 3
    unsigned int MMOD : 1; // Offset: 0x0, Bit Offset: 5, Bit Size: 1
    unsigned int AMOD : 1; // Offset: 0x0, Bit Offset: 6, Bit Size: 1
    unsigned int SLBG : 1; // Offset: 0x0, Bit Offset: 7, Bit Size: 1
    unsigned int ALP : 8; // Offset: 0x0, Bit Offset: 8, Bit Size: 8
    unsigned int p0 : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
    unsigned int p1; // Offset: 0x4
} PMode;

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

// Size: 0x1
typedef struct Flag
{
    unsigned int filter : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned int dither : 1; // Offset: 0x0, Bit Offset: 1, Bit Size: 1
    unsigned int oddeven : 1; // Offset: 0x0, Bit Offset: 2, Bit Size: 1
} Flag;

// Size: 0x8
typedef struct Fba
{
    unsigned long FBA : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} Fba;

// Size: 0x8
typedef struct TexA
{
    unsigned long TA0 : 8; // Offset: 0x0, Bit Offset: 0, Bit Size: 8
    unsigned long pad08 : 7; // Offset: 0x0, Bit Offset: 8, Bit Size: 7
    unsigned long AEM : 1; // Offset: 0x0, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
    unsigned long TA1 : 8; // Offset: 0x0, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, Bit Offset: 40, Bit Size: 24
} TexA;

// Size: 0x8
typedef struct Pabe
{
    unsigned long PABE : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} Pabe;

// Size: 0x8
typedef struct Alpha2
{
    unsigned long A : 2; // Offset: 0x0, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, Bit Offset: 40, Bit Size: 24
} Alpha2;

// Size: 0x60
typedef struct Alpha
{
    // Size: 0x8
    Alpha2 alpha1; // Offset: 0x0
    signed long alpha1addr; // Offset: 0x8
    // Size: 0x8
    Alpha2 alpha2; // Offset: 0x10
    signed long alpha2addr; // Offset: 0x18
    // Size: 0x8
    Pabe pabe; // Offset: 0x20
    signed long pabeaddr; // Offset: 0x28
    // Size: 0x8
    TexA texa; // Offset: 0x30
    signed long texaaddr; // Offset: 0x38
    // Size: 0x8
    Fba fba1; // Offset: 0x40
    signed long fba1addr; // Offset: 0x48
    // Size: 0x8
    Fba fba2; // Offset: 0x50
    signed long fba2addr; // Offset: 0x58
} Alpha;

// Size: 0x8
typedef struct Dimx
{
    unsigned long DIMX00 : 3; // Offset: 0x0, Bit Offset: 0, Bit Size: 3
    unsigned long pad00 : 1; // Offset: 0x0, Bit Offset: 3, Bit Size: 1
    unsigned long DIMX01 : 3; // Offset: 0x0, Bit Offset: 4, Bit Size: 3
    unsigned long pad01 : 1; // Offset: 0x0, Bit Offset: 7, Bit Size: 1
    unsigned long DIMX02 : 3; // Offset: 0x0, Bit Offset: 8, Bit Size: 3
    unsigned long pad02 : 1; // Offset: 0x0, Bit Offset: 11, Bit Size: 1
    unsigned long DIMX03 : 3; // Offset: 0x0, Bit Offset: 12, Bit Size: 3
    unsigned long pad03 : 1; // Offset: 0x0, Bit Offset: 15, Bit Size: 1
    unsigned long DIMX10 : 3; // Offset: 0x0, Bit Offset: 16, Bit Size: 3
    unsigned long pad10 : 1; // Offset: 0x0, Bit Offset: 19, Bit Size: 1
    unsigned long DIMX11 : 3; // Offset: 0x0, Bit Offset: 20, Bit Size: 3
    unsigned long pad11 : 1; // Offset: 0x0, Bit Offset: 23, Bit Size: 1
    unsigned long DIMX12 : 3; // Offset: 0x0, Bit Offset: 24, Bit Size: 3
    unsigned long pad12 : 1; // Offset: 0x0, Bit Offset: 27, Bit Size: 1
    unsigned long DIMX13 : 3; // Offset: 0x0, Bit Offset: 28, Bit Size: 3
    unsigned long pad13 : 1; // Offset: 0x0, Bit Offset: 31, Bit Size: 1
    unsigned long DIMX20 : 3; // Offset: 0x0, Bit Offset: 32, Bit Size: 3
    unsigned long pad20 : 1; // Offset: 0x0, Bit Offset: 35, Bit Size: 1
    unsigned long DIMX21 : 3; // Offset: 0x0, Bit Offset: 36, Bit Size: 3
    unsigned long pad21 : 1; // Offset: 0x0, Bit Offset: 39, Bit Size: 1
    unsigned long DIMX22 : 3; // Offset: 0x0, Bit Offset: 40, Bit Size: 3
    unsigned long pad22 : 1; // Offset: 0x0, Bit Offset: 43, Bit Size: 1
    unsigned long DIMX23 : 3; // Offset: 0x0, Bit Offset: 44, Bit Size: 3
    unsigned long pad23 : 1; // Offset: 0x0, Bit Offset: 47, Bit Size: 1
    unsigned long DIMX30 : 3; // Offset: 0x0, Bit Offset: 48, Bit Size: 3
    unsigned long pad30 : 1; // Offset: 0x0, Bit Offset: 51, Bit Size: 1
    unsigned long DIMX31 : 3; // Offset: 0x0, Bit Offset: 52, Bit Size: 3
    unsigned long pad31 : 1; // Offset: 0x0, Bit Offset: 55, Bit Size: 1
    unsigned long DIMX32 : 3; // Offset: 0x0, Bit Offset: 56, Bit Size: 3
    unsigned long pad32 : 1; // Offset: 0x0, Bit Offset: 59, Bit Size: 1
    unsigned long DIMX33 : 3; // Offset: 0x0, Bit Offset: 60, Bit Size: 3
    unsigned long pad33 : 1; // Offset: 0x0, Bit Offset: 63, Bit Size: 1
} Dimx;

// Size: 0x40
typedef struct Cmn
{
    // Size: 0x8
    PrModeCont prmodecont; // Offset: 0x0
    signed long prmodecontaddr; // Offset: 0x8
    // Size: 0x8
    ColClamp colclamp; // Offset: 0x10
    signed long colclampaddr; // Offset: 0x18
    // Size: 0x8
    Dthe dthe; // Offset: 0x20
    signed long dtheaddr; // Offset: 0x28
    // Size: 0x8
    Dimx dimx; // Offset: 0x30
    signed long dimxaddr; // Offset: 0x38
} Cmn;

// Size: 0x50
typedef struct FBuf
{
    // Size: 0x8
    Frame frame; // Offset: 0x0
    unsigned long frameaddr; // Offset: 0x8
    // Size: 0x8
    Zbuf zbuf; // Offset: 0x10
    signed long zbufaddr; // Offset: 0x18
    // Size: 0x8
    XYOffset xyoffset; // Offset: 0x20
    signed long xyoffsetaddr; // Offset: 0x28
    // Size: 0x8
    Scissor scissor; // Offset: 0x30
    signed long scissoraddr; // Offset: 0x38
    // Size: 0x8
    Test test; // Offset: 0x40
    signed long testaddr; // Offset: 0x48
} FBuf;

// Size: 0x1B0
typedef struct Draw3
{
    // Size: 0x10
    sceGifTag giftag; // Offset: 0x0
    // Size: 0x50
    FBuf fbuf[2]; // Offset: 0x10
    // Size: 0x40
    Cmn cmn; // Offset: 0xB0
    // Size: 0x60
    Alpha alpha; // Offset: 0xF0
    // Size: 0x60
    Clear clear; // Offset: 0x150
} Draw3;

// Size: 0x38
typedef struct Disp
{
    // Size: 0x8
    PMode pmode; // Offset: 0x0
    // Size: 0x8
    SMode smode2; // Offset: 0x8
    // Size: 0x8
    DispFb dispfb1; // Offset: 0x10
    // Size: 0x8
    Display display1; // Offset: 0x18
    // Size: 0x8
    DispFb dispfb2; // Offset: 0x20
    // Size: 0x8
    Display display2; // Offset: 0x28
    // Size: 0x8
    BgColor bgcolor; // Offset: 0x30
} Disp;

// Size: 0x790
typedef struct VgmsysFrameBuffer
{
    // Size: 0x38
    Disp disp[3]; // Offset: 0x0
    // Size: 0x1B0
    Draw3 draw[4]; // Offset: 0xB0
    unsigned short nbuf; // Offset: 0x770
    unsigned short idx; // Offset: 0x772
    unsigned short count; // Offset: 0x774
    unsigned short psm; // Offset: 0x776
    unsigned short zpsm; // Offset: 0x778
    signed short w; // Offset: 0x77A
    signed short h; // Offset: 0x77C
    signed short cx; // Offset: 0x77E
    signed short cy; // Offset: 0x780
    unsigned short ztest; // Offset: 0x782
    unsigned short mode; // Offset: 0x784
    // Size: 0x1
    Flag flag; // Offset: 0x786
} VgmsysFrameBuffer;

// SCE includes /////////////////////////////////////////////////////////////////////
void sceVu0MulMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FMATRIX m2);
void sceVu0ApplyMatrix(sceVu0FVECTOR v0, sceVu0FMATRIX m, sceVu0FVECTOR v1);
void sceVu0ScaleVector(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0FTOI4Vector(sceVu0IVECTOR iv, sceVu0FVECTOR fv);

// UL includes //////////////////////////////////////////////////////////////////////
void ulgraphFlipFrameBuff(DmaVif* dmagif, VgmsysFrameBuffer* fb, signed int oddeven);

//// Function Declarations ///////////////////////////////////////////////////////////

void aksubFlipFrameBuff(DmaVif* dmagif, VgmsysFrameBuffer* fb, signed int oddeven, signed int clr);
signed int aksubClipScreen(sceVu0FMATRIX wsmat, sceVu0FMATRIX mat, float width, float height1, float height2, signed int wid, signed int divmode, float center);

//// Globals /////////////////////////////////////////////////////////////////////////

extern signed int vsppScrWidth; // Address: 0x2E7704
extern signed int vsppScrHeight; // Address: 0x2E7708

// Address: 0x2A1DF0
// Size: 0xC8
void aksubFlipFrameBuff(DmaVif* dmagif, VgmsysFrameBuffer* fb, signed int oddeven, signed int clr) {
    Draw3* draw; // r16
    unsigned long testa; // r17

    draw = &fb->draw[(fb->idx + 1) % fb->nbuf];
    testa = *(unsigned long*)&draw->clear.testa;
    if (clr == 0) {
        *(unsigned long*)&draw->clear.testa = SCE_GS_SET_TEST(1, 0, 0, 2, 0, 0, 1, 1);
    }
    ulgraphFlipFrameBuff(dmagif, fb, oddeven);
    *(unsigned long*)&draw->clear.testa = testa;
}

// Address: 0x2A1EC0
// Size: 0x4EC
signed int aksubClipScreen(sceVu0FMATRIX wsmat, sceVu0FMATRIX mat, float width, float height1, float height2, signed int wid, signed int divmode, float center) {
    signed int in; // r18
    float x1; // 0x134(r29)
    float y1; // 0x138(r29)
    float x2; // 0x13C(r29)
    float y2; // 0x140(r29)
    signed int i; // r16
    sceVu0FMATRIX mat2; // 0x60(r29)
    sceVu0FVECTOR fv; // 0xA0(r29)
    sceVu0IVECTOR iv[8]; // 0xB0(r29)
    unsigned char f; // r17
    unsigned char flag; // r19
    unsigned char flag2; // r20

    width *= 0.5f;
    sceVu0MulMatrix(mat2, wsmat, mat);
    x1 = 2048.0f - vsppScrWidth / 2.0f;
    x2 = 2048.0f + vsppScrWidth / 2.0f;
    y1 = 2048.0f - vsppScrHeight / 2.0f;
    y2 = 2048.0f + vsppScrHeight / 2.0f;
    if (divmode == 1) {
        if (wid == 0) {
            x2 = x1 + center;
        } else {
            x1 = x1 + center;
        }
    } else if (divmode == 2) {
        if (wid == 0) {
            y2 = y1 + center;
        } else {
            y1 = y1 + center;
        }
    }
    in = 0;
    flag = 0;
    flag2 = 0xF;
    for (i = 0; i < 8; i++) {
        fv[0] = (i & 1) ? width : -width;
        fv[1] = (i & 2) ? height2 : height1;
        fv[2] = (i & 4) ? width : -width;
        fv[3] = 1.0f;
        sceVu0ApplyMatrix(fv, mat2, fv);
        sceVu0ScaleVector(fv, fv, 1.0f / fv[3]);
        sceVu0FTOI4Vector(iv[i], fv);
        if (fv[2] < 0.0f || fv[2] > 16777216.0f) {
            in = -1;
            break;
        }
        if (fv[0] < 0.0f || fv[0] > 4095.0f || fv[1] < 0.0f || fv[1] > 4095.0f) {
            iv[i][3] = 0x8000;
        }
        f = (fv[0] < x1) | ((fv[0] > x2) << 1) | ((fv[1] < y1) << 2) | ((fv[1] > y2) << 3);
        flag |= f;
        flag2 &= f;
        if (f == 0) {
            in = 1;
        }
    }
    if (in < 0) {
        in = 0;
    } else if (in == 0) {
        if (((flag & 5) & ((flag >> 1) & 5)) && flag2 == 0) {
            in = 1;
        }
    }
    return in;
}
