#include "common.h"
#include "types.h"

#define SCE_DMA_VIF0        0
#define SCE_DMA_VIF1        1
#define SCE_DMA_GIF         2

// SCE types ///////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));
typedef struct DBuff sceGsDBuffDc;

// Size: 0x10
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0
    unsigned char mark; // Offset: 0x2
    unsigned char id; // Offset: 0x3
    struct _sceDmaTag* next; // Offset: 0x4
    unsigned int p[2]; // Offset: 0x8
} _sceDmaTag;

// Static data /////////////////////////////////////////////////////////

// system.c structs ////////////////////////////////////////////////////

// Size: 0x4
typedef struct VulsysScrArea
{
    signed short vx; // Offset: 0x0
    signed short vy; // Offset: 0x2
} VulsysScrArea;

// Size: 0x14
typedef struct Env
{
    unsigned char sts; // Offset: 0x0
    unsigned char std; // Offset: 0x1
    unsigned char mfd; // Offset: 0x2
    unsigned char rcycle; // Offset: 0x3
    unsigned short express; // Offset: 0x4
    unsigned short notify; // Offset: 0x6
    unsigned short sqwc; // Offset: 0x8
    unsigned short tqwc; // Offset: 0xA
    void* rbadr; // Offset: 0xC
    unsigned int rbmsk; // Offset: 0x10
} Env;

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
typedef struct RGBAQ
{
    unsigned int R : 8; // Offset: 0x0, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4
} RGBAQ;

// Size: 0x8
typedef struct Prim
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
} Prim;

// Size: 0x60
typedef struct Clear
{
    // Size: 0x8
    Test testa; // Offset: 0x0
    signed long testaaddr; // Offset: 0x8
    // Size: 0x8
    Prim prim; // Offset: 0x10
    signed long primaddr; // Offset: 0x18
    // Size: 0x8
    RGBAQ rgbaq; // Offset: 0x20
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
typedef struct ZBuf
{
    unsigned long ZBP : 9; // Offset: 0x0, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 15; // Offset: 0x0, Bit Offset: 9, Bit Size: 15
    unsigned long PSM : 4; // Offset: 0x0, Bit Offset: 24, Bit Size: 4
    unsigned long pad28 : 4; // Offset: 0x0, Bit Offset: 28, Bit Size: 4
    unsigned long ZMSK : 1; // Offset: 0x0, Bit Offset: 32, Bit Size: 1
    unsigned long pad33 : 31; // Offset: 0x0, Bit Offset: 33, Bit Size: 31
} ZBuf;

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

// Size: 0x80
typedef struct Draw2
{
    // Size: 0x8
    Frame frame2; // Offset: 0x0
    unsigned long frame2addr; // Offset: 0x8
    // Size: 0x8
    ZBuf zbuf2; // Offset: 0x10
    signed long zbuf2addr; // Offset: 0x18
    // Size: 0x8
    XYOffset xyoffset2; // Offset: 0x20
    signed long xyoffset2addr; // Offset: 0x28
    // Size: 0x8
    Scissor scissor2; // Offset: 0x30
    signed long scissor2addr; // Offset: 0x38
    // Size: 0x8
    PrModeCont prmodecont; // Offset: 0x40
    signed long prmodecontaddr; // Offset: 0x48
    // Size: 0x8
    ColClamp colclamp; // Offset: 0x50
    signed long colclampaddr; // Offset: 0x58
    // Size: 0x8
    Dthe dthe; // Offset: 0x60
    signed long dtheaddr; // Offset: 0x68
    // Size: 0x8
    Test test2; // Offset: 0x70
    signed long test2addr; // Offset: 0x78
} Draw2;

// Size: 0x80
typedef struct Draw1
{
    // Size: 0x8
    Frame frame1; // Offset: 0x0
    unsigned long frame1addr; // Offset: 0x8
    // Size: 0x8
    ZBuf zbuf1; // Offset: 0x10
    signed long zbuf1addr; // Offset: 0x18
    // Size: 0x8
    XYOffset xyoffset1; // Offset: 0x20
    signed long xyoffset1addr; // Offset: 0x28
    // Size: 0x8
    Scissor scissor1; // Offset: 0x30
    signed long scissor1addr; // Offset: 0x38
    // Size: 0x8
    PrModeCont prmodecont; // Offset: 0x40
    signed long prmodecontaddr; // Offset: 0x48
    // Size: 0x8
    ColClamp colclamp; // Offset: 0x50
    signed long colclampaddr; // Offset: 0x58
    // Size: 0x8
    Dthe dthe; // Offset: 0x60
    signed long dtheaddr; // Offset: 0x68
    // Size: 0x8
    Test test1; // Offset: 0x70
    signed long test1addr; // Offset: 0x78
} Draw1;

// Size: 0x10
typedef struct GifTag
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
} GifTag;

// Size: 0x8
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4
} BgColor;

// Size: 0x8
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

// Size: 0x8
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

// Size: 0x28
typedef struct Disp2
{
    PMode pmode; // Offset: 0x0
    // Size: 0x8
    SMode smode2; // Offset: 0x8
    // Size: 0x8
    DispFb dispfb; // Offset: 0x10
    // Size: 0x8
    Display display; // Offset: 0x18
    // Size: 0x8
    BgColor bgcolor; // Offset: 0x20
} Disp2;

// Size: 0x330
typedef struct DBuff
{
    // Size: 0x28
    Disp2 disp[2]; // Offset: 0x0
    // Size: 0x10
    GifTag giftag0; // Offset: 0x50
    // Size: 0x80
    Draw1 draw01; // Offset: 0x60
    // Size: 0x80
    Draw2 draw02; // Offset: 0xE0
    // Size: 0x60
    Clear clear0; // Offset: 0x160
    // Size: 0x10
    GifTag giftag1; // Offset: 0x1C0
    // Size: 0x80
    Draw1 draw11; // Offset: 0x1D0
    // Size: 0x80
    Draw2 draw12; // Offset: 0x250
    // Size: 0x60
    Clear clear1; // Offset: 0x2D0
} DBuff;

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
    // Size: 0x330
    DBuff DBuff; // Offset: 0x30
} VulsysSystem;
// SCE includes /////////////////////////////////////////////////////////////////////
void sceGsSetDefDBuffDc(sceGsDBuffDc* db, short psm, short w, short h, short ztest, short zpsm, short clear);
DmaVif* sceDmaGetChan(int id);

//// Variables /////////////////////////////////////////////////////////

// Size: 0x4
static const VulsysScrArea vulsysScrArea[2][5] = { // Address: 0x2D9870
    { { 256, 224 }, { 320, 224 }, { 384, 224 }, { 512, 224 }, { 640, 224 } },
    { { 256, 288 }, { 320, 288 }, { 384, 288 }, { 512, 288 }, { 640, 288 } },
};

unsigned char vulsysFlg_dispString; // Address: 0x2E7A00
// Size: 0x360
VulsysSystem vulsysSystem; // Address: 0x2F3A50

//// Function Declarations ///////////////////////////////////////////////////////////

void ulsysInitSystem(signed short mode, signed int interlace, signed int pal);
static void ulsysSetScreenMode(signed int mode, signed int interlace, signed int pal);

//// Function Definitions ////////////////////////////////////////////////////////////

// Address: 0x136F20
void ulsysInitSystem(signed short mode /* 0x30(r29) */, signed int interlace /* 0x40(r29) */, signed int pal /* 0x50(r29) */) {
    Env env; // 0x10(r29)

    sceDevGifReset();
    sceDevVif0Reset();
    sceDevVu0Reset();
    sceDevVif1Reset();
    sceDevVu1Reset();
    sceGsResetPath();
    sceDmaReset(1);
    sceVpu0Reset();
    if (pal == 0) {
        sceGsResetGraph(0, 1, 2, 1);
    } else {
        sceGsResetGraph(0, 1, 3, 1);
    }
    sceDmaGetEnv(&env);
    sceDmaPutEnv(&env);
    vulsysSystem.DmaGif = sceDmaGetChan(SCE_DMA_GIF);
    vulsysSystem.DmaVif0 = sceDmaGetChan(SCE_DMA_VIF0);
    vulsysSystem.DmaVif1 = sceDmaGetChan(SCE_DMA_VIF1);
    vulsysSystem.DmaGif->chcr.TTE = 1;
    vulsysSystem.DmaVif0->chcr.TTE = 1;
    vulsysSystem.DmaVif1->chcr.TTE = 1;

    vulsysSystem.Pal = pal;
    vulsysSystem.EvenOdd = 0;
    vulsysSystem.Frame = 0;
    vulsysSystem.PadInit = 0;
    ulsysSetScreenMode((mode), interlace, pal);
    sceGsSetDefDBuffDc(&vulsysSystem.DBuff, 0, vulsysSystem.ScreenWidth, vulsysSystem.ScreenHeight, 3, 0x31, 1);
    vulsysSystem.DBuff.disp[0].dispfb.FBP = 0;
    vulsysSystem.DBuff.disp[1].dispfb.FBP = 0x1680 / 64;
    vulsysSystem.DBuff.draw01.frame1.FBP = 0x1680 / 64;
    vulsysSystem.DBuff.draw01.zbuf1.ZBP = 0x2d00 / 64;
    vulsysSystem.DBuff.draw11.frame1.FBP = 0;
    vulsysSystem.DBuff.draw11.zbuf1.ZBP = 0x2d00 / 64;
    vulsysSystem.DBuff.draw02.frame2.FBP = 0x1680 / 64;
    vulsysSystem.DBuff.draw02.zbuf2.ZBP = 0x2d00 / 64;
    vulsysSystem.DBuff.draw12.frame2.FBP = 0;
    vulsysSystem.DBuff.draw12.zbuf2.ZBP = 0x2d00 / 64;
    FlushCache(0);
    ulstdPrintf("dispenv.dispfb=%d, %d\n", vulsysSystem.DBuff.disp[0].dispfb.FBP, vulsysSystem.DBuff.disp[1].dispfb.FBP);
    ulstdPrintf("drawenv.draw0.FBP=%d, %d\n", vulsysSystem.DBuff.draw01.frame1.FBP, vulsysSystem.DBuff.draw02.frame2.FBP);
    ulstdPrintf("drawenv.draw1.FBP=%d, %d\n", vulsysSystem.DBuff.draw11.frame1.FBP, vulsysSystem.DBuff.draw12.frame2.FBP);
    ulstdPrintf("drawenv.draw0.ZBP=%d, %d\n", vulsysSystem.DBuff.draw01.zbuf1.ZBP, vulsysSystem.DBuff.draw02.zbuf2.ZBP);
    ulstdPrintf("drawenv.draw1.ZBP=%d, %d\n", vulsysSystem.DBuff.draw11.zbuf1.ZBP, vulsysSystem.DBuff.draw12.zbuf2.ZBP);
    vulsysFlg_dispString = 0xFF;
}

// Address: 0x137340
static void ulsysSetScreenMode(signed int mode /* 0x20(r29) */, signed int interlace /* 0x30(r29) */, signed int pal /* 0x40(r29) */) {
    const VulsysScrArea* screen; // r16
    signed int offset;

    screen = &vulsysScrArea[pal][mode];
    vulsysSystem.Interlace = interlace;
    vulsysSystem.ScreenMode = mode;
    vulsysSystem.ScreenWidth = screen->vx;
    vulsysSystem.ScreenHeight = screen->vy;
    if (pal == 0) {
        offset = 0;
    } else {
        offset = 0x10;
    }
    vulsysSystem.ScreenYofs = offset;
}
