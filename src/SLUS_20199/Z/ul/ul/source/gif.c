#include "common.h"
#include "types.h"

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop)<<15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim)<<47) | ((unsigned long)(flg)<<58) | ((unsigned long)(nreg)<<60))

#define SCE_GIF_PACKED_AD   0x0e

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// gif.c structs ////////////////////////////////////////////////////////////////////

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
typedef struct DmaGif
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
} DmaGif;

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
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4
} BgColor;

// Size: 0x28
typedef struct Disp
{
    // Size: 0x8
    PMode pmode; // Offset: 0x0
    // Size: 0x8
    SMode smode2; // Offset: 0x8
    // Size: 0x8
    DispFb dispfb; // Offset: 0x10
    // Size: 0x8
    Display display; // Offset: 0x18
    // Size: 0x8
    BgColor bgcolor; // Offset: 0x20
} Disp;

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
typedef struct XyOffset
{
    unsigned long OFX : 16; // Offset: 0x0, Bit Offset: 0, Bit Size: 16
    unsigned long pad16 : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
    unsigned long OFY : 16; // Offset: 0x0, Bit Offset: 32, Bit Size: 16
    unsigned long pad48 : 16; // Offset: 0x0, Bit Offset: 48, Bit Size: 16
} XyOffset;

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
typedef struct PrModeCont
{
    unsigned long AC : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} PrModeCont;

// Size: 0x8
typedef struct ColClamp
{
    unsigned long CLAMP : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} ColClamp;

// Size: 0x8
typedef struct Dthe
{
    unsigned long DTHE : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, Bit Offset: 1, Bit Size: 63
} Dthe;

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

// Size: 0x80
typedef struct Draw
{
    // Size: 0x8
    Frame frame1; // Offset: 0x0
    unsigned long frame1addr; // Offset: 0x8
    // Size: 0x8
    ZBuf zbuf1; // Offset: 0x10
    signed long zbuf1addr; // Offset: 0x18
    // Size: 0x8
    XyOffset xyoffset1; // Offset: 0x20
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
} Draw;

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
    XyOffset xyoffset2; // Offset: 0x20
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
typedef struct Xyzf
{
    unsigned long X : 16; // Offset: 0x0, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 24; // Offset: 0x0, Bit Offset: 32, Bit Size: 24
    unsigned long F : 8; // Offset: 0x0, Bit Offset: 56, Bit Size: 8
} Xyzf;

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
    Xyzf xyz2a; // Offset: 0x30
    signed long xyz2aaddr; // Offset: 0x38
    // Size: 0x8
    Xyzf xyz2b; // Offset: 0x40
    signed long xyz2baddr; // Offset: 0x48
    // Size: 0x8
    Test testb; // Offset: 0x50
    signed long testbaddr; // Offset: 0x58
} Clear;

// Size: 0x330
typedef struct DBuff
{
    // Size: 0x28
    Disp disp[2]; // Offset: 0x0
    // Size: 0x10
    GifTag giftag0; // Offset: 0x50
    // Size: 0x80
    Draw draw01; // Offset: 0x60
    // Size: 0x80
    Draw2 draw02; // Offset: 0xE0
    // Size: 0x60
    Clear clear0; // Offset: 0x160
    // Size: 0x10
    GifTag giftag1; // Offset: 0x1C0
    // Size: 0x80
    Draw draw11; // Offset: 0x1D0
    // Size: 0x80
    Draw2 draw12; // Offset: 0x250
    // Size: 0x60
    Clear clear1; // Offset: 0x2D0
} DBuff;

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
    DmaGif* DmaGif; // Offset: 0x24
    // Size: 0x90
    DmaGif* DmaVif0; // Offset: 0x28
    // Size: 0x90
    DmaGif* DmaVif1; // Offset: 0x2C
    // Size: 0x330
    DBuff DBuff; // Offset: 0x30
} VulsysSystem;

// Size: 0x10
typedef struct VspLocalGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0
    __int128* pBase; // Offset: 0x4
    __int128* pDmaTag; // Offset: 0x8
    unsigned long* pGifTag; // Offset: 0xC
} VspLocalGifPkt;
//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0x360
extern VulsysSystem vulsysSystem; // Address: 0x2F3A50

// SCE includes /////////////////////////////////////////////////////////////////////
void sceDmaSend(DmaGif* dmaVif, void* tag);
void sceGifPkAddGsAD(VspLocalGifPkt* pkt, unsigned int addr, unsigned long data);

//// Function Declarations ///////////////////////////////////////////////////////////

void ulgifTermPacket(VspLocalGifPkt* pkt);
void ulgifDmaSend(VspLocalGifPkt* pkt);
void ulgifDmaWait();
__int128* ulgifAddCNTReserve(VspLocalGifPkt* pkt, signed int qwc);
void ulgifAddSetGsRegister(VspLocalGifPkt* pkt, signed int gs_reg, unsigned long data);
void ulgifAddCNTSetGsRegister(VspLocalGifPkt* pkt, signed int gs_reg, unsigned long data);

//// Function Definitions ////////////////////////////////////////////////////////////

// Address: 0x12AA20
void ulgifTermPacket(VspLocalGifPkt* pkt /* 0x10(r29) */) {
    sceGifPkEnd(pkt, 0, 0, 0);
    sceGifPkTerminate(pkt);
}

// Address: 0x12AA60
void ulgifDmaSend(VspLocalGifPkt* pkt /* 0x10(r29) */) {
    FlushCache(0);
    sceDmaSend(vulsysSystem.DmaGif, pkt->pBase);
}

// Address: 0x12AAA0
void ulgifDmaWait() {
    sceDmaSync(vulsysSystem.DmaGif, 0, 0);
}

// Address: 0x12AAD0
__int128* ulgifAddCNTReserve(VspLocalGifPkt* pkt /* 0x20(r29) */, signed int qwc /* 0x30(r29) */) {
    __int128* p; // r16

    sceGifPkCnt(pkt, 0, 0, 0);
    p = (__int128*)sceGifPkReserve(pkt, qwc * 4);
    sceGifPkTerminate(pkt);
    return p;
}

// Address: 0x12AB40
void ulgifAddSetGsRegister(VspLocalGifPkt* pkt /* 0x20(r29) */, signed int gs_reg /* 0x30(r29) */, unsigned long data /* 0x40(r29) */) {
    __int128 giftag; // 0x10(r29)

    ((long*)&giftag)[0] = SCE_GIF_SET_TAG(0, 1, 0, 0, 0, 1);
    ((long*)&giftag)[1] = SCE_GIF_PACKED_AD;
    sceGifPkOpenGifTag(pkt, giftag);
    sceGifPkAddGsAD(pkt, gs_reg, data);
    sceGifPkCloseGifTag(pkt);
}

// Address: 0x12ABC0
void ulgifAddCNTSetGsRegister(VspLocalGifPkt* pkt /* 0x10(r29) */, signed int gs_reg /* 0x20(r29) */, unsigned long data /* 0x30(r29) */) {
    sceGifPkCnt(pkt, 0, 0, 0);
    ulgifAddSetGsRegister(pkt, gs_reg, data);
    sceGifPkTerminate(pkt);
}
