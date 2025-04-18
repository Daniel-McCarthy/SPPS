// main.c context
// Last updated 4/17/2025
// SPPS NTSC-U 201.99 Final

extern signed int _fbss;

typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;
typedef unsigned int u_int;
typedef __int128 int128;
typedef __int128 s128;
typedef unsigned __int128 u_int128;

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop)<<15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim)<<47) | ((unsigned long)(flg)<<58) | ((unsigned long)(nreg)<<60))

#define SCE_GIF_PACKED_AD   0x0e

#define ABORT() asm(".word 0x0000000d")
#define VIF1_FBRST      ((volatile unsigned int *)(0x10003c10))
#define GIF_CTRL        ((volatile unsigned int *)(0x10003000))

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// SCE includes /////////////////////////////////////////////////////////////////////
void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0ScaleVector(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0SubVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0UnitMatrix(sceVu0FMATRIX a);

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);

// Size: 0x10, DWARF: 0x55B
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0, DWARF: 0x57A
    unsigned char mark; // Offset: 0x2, DWARF: 0x59A
    unsigned char id; // Offset: 0x3, DWARF: 0x5BB
    struct _sceDmaTag* next; // Offset: 0x4, DWARF: 0x5DA
    unsigned int p[2]; // Offset: 0x8, DWARF: 0x600
} _sceDmaTag;

// Size: 0x10, DWARF: 0xE7A
typedef struct sceGifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0xF7F3F, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0xF7F6B, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0xF7F95, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0xF7FC1, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0xF7FEA, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0xF8014, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0xF803F, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0xF8069, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0xF8094, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0xF80C0, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0xF80EC, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0xF8118, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0xF8144, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0xF8170, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0xF819C, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0xF81C8, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0xF81F4, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0xF8220, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0xF824C, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0xF8279, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0xF82A6, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0xF82D3, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0xF8300, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0xF832D, Bit Offset: 60, Bit Size: 4
} sceGifTag __attribute__((aligned(16)));

// Static data /////////////////////////////////////////////////////////

// spfree.c structs ////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0x1F1C
typedef struct VgmsysVif1Pkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x1F38
    __int128* pBase; // Offset: 0x4, DWARF: 0x1F60
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x1F85
    unsigned int* pVifCode; // Offset: 0xC, DWARF: 0x1FAC
    unsigned int numlen; // Offset: 0x10, DWARF: 0x1FD4
    unsigned long* pGifTag; // Offset: 0x14, DWARF: 0x1FF7
    unsigned int pad12; // Offset: 0x18, DWARF: 0x201E
    unsigned int pad13; // Offset: 0x1C, DWARF: 0x2040
} VgmsysVif1Pkt;

// Size: 0x10, DWARF: 0x6EF
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x70A
    __int128* pBase; // Offset: 0x4, DWARF: 0x732
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x757
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0x77E
} VgmsysGifPkt;

// Size: 0x10, DWARF: 0x915
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x930
    unsigned int addr; // Offset: 0x4, DWARF: 0x953
    unsigned int z; // Offset: 0x8, DWARF: 0x974
    unsigned int _pad; // Offset: 0xC, DWARF: 0x992
} ATag;

// Size: 0x20, DWARF: 0xCC2
typedef struct VgmsysAbuf
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0xCDD
    unsigned int natag; // Offset: 0x4, DWARF: 0xD01
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0xD23
    unsigned int npkt; // Offset: 0xC, DWARF: 0xD46
    // Size: 0x10, DWARF: 0x915
    ATag* atag; // Offset: 0x10, DWARF: 0xD67
    // Size: 0x10, DWARF: 0x915
    ATag* curatag; // Offset: 0x14, DWARF: 0xD8D
    __int128* pkt; // Offset: 0x18, DWARF: 0xDB6
    __int128* curpkt; // Offset: 0x1C, DWARF: 0xDD9
} VgmsysAbuf;

// Size: 0x20, DWARF: 0x22B0
typedef struct VspenvDemo
{
    unsigned long time_out; // Offset: 0x0, DWARF: 0x22CC
    unsigned long play_time_out; // Offset: 0x8, DWARF: 0x22F1
    signed int usr_end; // Offset: 0x10, DWARF: 0x231B
    signed int to; // Offset: 0x14, DWARF: 0x233F
    signed int play_to; // Offset: 0x18, DWARF: 0x235E
    signed int demo; // Offset: 0x1C, DWARF: 0x2382
} VspenvDemo;

// Size: 0x8, DWARF: 0x37AE
typedef struct VgmsysClock
{
    unsigned char stat; // Offset: 0x0, DWARF: 0x37CA
    unsigned char second; // Offset: 0x1, DWARF: 0x37EB
    unsigned char minute; // Offset: 0x2, DWARF: 0x380E
    unsigned char hour; // Offset: 0x3, DWARF: 0x3831
    unsigned char pad; // Offset: 0x4, DWARF: 0x3852
    unsigned char day; // Offset: 0x5, DWARF: 0x3872
    unsigned char month; // Offset: 0x6, DWARF: 0x3892
    unsigned char year; // Offset: 0x7, DWARF: 0x38B4
} VgmsysClock;

// Size: 0x8, DWARF: 0xB20
typedef struct Test
{
    unsigned long ATE : 1; // Offset: 0x0, DWARF: 0xB3B, Bit Offset: 0, Bit Size: 1
    unsigned long ATST : 3; // Offset: 0x0, DWARF: 0xB65, Bit Offset: 1, Bit Size: 3
    unsigned long AREF : 8; // Offset: 0x0, DWARF: 0xB90, Bit Offset: 4, Bit Size: 8
    unsigned long AFAIL : 2; // Offset: 0x0, DWARF: 0xBBB, Bit Offset: 12, Bit Size: 2
    unsigned long DATE : 1; // Offset: 0x0, DWARF: 0xBE7, Bit Offset: 14, Bit Size: 1
    unsigned long DATM : 1; // Offset: 0x0, DWARF: 0xC12, Bit Offset: 15, Bit Size: 1
    unsigned long ZTE : 1; // Offset: 0x0, DWARF: 0xC3D, Bit Offset: 16, Bit Size: 1
    unsigned long ZTST : 2; // Offset: 0x0, DWARF: 0xC67, Bit Offset: 17, Bit Size: 2
    unsigned long pad19 : 45; // Offset: 0x0, DWARF: 0xC92, Bit Offset: 19, Bit Size: 45
} Test;

// Size: 0x8, DWARF: 0x208A
typedef struct XYZ
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x20A6, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x20CE, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 32; // Offset: 0x0, DWARF: 0x20F6, Bit Offset: 32, Bit Size: 32
} XYZ;

// Size: 0x8, DWARF: 0x3A79
typedef struct Color
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x3A95, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x3ABD, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x3AE5, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0x3B0D, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0x3B35
} Color;

// Size: 0x8, DWARF: 0x2C10
typedef struct sceGsPrim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0x2C2C, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0x2C57, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0x2C81, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0x2CAB, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0x2CD5, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0x2CFF, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0x2D29, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0x2D53, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0x2D7E, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0x2DA8, Bit Offset: 11, Bit Size: 53
} sceGsPrim;

// Size: 0x60, DWARF: 0x3D39
typedef struct Clear
{
    // Size: 0x8, DWARF: 0xB20
    Test testa; // Offset: 0x0, DWARF: 0x3D55
    signed long testaaddr; // Offset: 0x8, DWARF: 0x3D79
    // Size: 0x8, DWARF: 0x2C10
    sceGsPrim prim; // Offset: 0x10, DWARF: 0x3D9F
    signed long primaddr; // Offset: 0x18, DWARF: 0x3DC2
    // Size: 0x8, DWARF: 0x3A79
    Color rgbaq; // Offset: 0x20, DWARF: 0x3DE7
    signed long rgbaqaddr; // Offset: 0x28, DWARF: 0x3E0B
    // Size: 0x8, DWARF: 0x208A
    XYZ xyz2a; // Offset: 0x30, DWARF: 0x3E31
    signed long xyz2aaddr; // Offset: 0x38, DWARF: 0x3E55
    // Size: 0x8, DWARF: 0x208A
    XYZ xyz2b; // Offset: 0x40, DWARF: 0x3E7B
    signed long xyz2baddr; // Offset: 0x48, DWARF: 0x3E9F
    // Size: 0x8, DWARF: 0xB20
    Test testb; // Offset: 0x50, DWARF: 0x3EC5
    signed long testbaddr; // Offset: 0x58, DWARF: 0x3EE9
} Clear;

// Size: 0x8, DWARF: 0x38D9
typedef struct Dthe
{
    unsigned long DTHE : 1; // Offset: 0x0, DWARF: 0x38F5, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x3920, Bit Offset: 1, Bit Size: 63
} Dthe;

// Size: 0x8, DWARF: 0xE03
typedef struct ColClamp
{
    unsigned long CLAMP : 1; // Offset: 0x0, DWARF: 0xE1E, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0xE4A, Bit Offset: 1, Bit Size: 63
} ColClamp;

// Size: 0x8, DWARF: 0x35F8
typedef struct PrModeCont
{
    unsigned long AC : 1; // Offset: 0x0, DWARF: 0x3614, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x363D, Bit Offset: 1, Bit Size: 63
} PrModeCont;

// Size: 0x8, DWARF: 0x42A7
typedef struct Scissor
{
    unsigned long SCAX0 : 11; // Offset: 0x0, DWARF: 0x42C3, Bit Offset: 0, Bit Size: 11
    unsigned long pad11 : 5; // Offset: 0x0, DWARF: 0x42EF, Bit Offset: 11, Bit Size: 5
    unsigned long SCAX1 : 11; // Offset: 0x0, DWARF: 0x431B, Bit Offset: 16, Bit Size: 11
    unsigned long pad27 : 5; // Offset: 0x0, DWARF: 0x4347, Bit Offset: 27, Bit Size: 5
    unsigned long SCAY0 : 11; // Offset: 0x0, DWARF: 0x4373, Bit Offset: 32, Bit Size: 11
    unsigned long pad43 : 5; // Offset: 0x0, DWARF: 0x439F, Bit Offset: 43, Bit Size: 5
    unsigned long SCAY1 : 11; // Offset: 0x0, DWARF: 0x43CB, Bit Offset: 48, Bit Size: 11
    unsigned long pad59 : 5; // Offset: 0x0, DWARF: 0x43F7, Bit Offset: 59, Bit Size: 5
} Scissor;

// Size: 0x8, DWARF: 0x1DE4
typedef struct XYOffset
{
    unsigned long OFX : 16; // Offset: 0x0, DWARF: 0x1E00, Bit Offset: 0, Bit Size: 16
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x1E2A, Bit Offset: 16, Bit Size: 16
    unsigned long OFY : 16; // Offset: 0x0, DWARF: 0x1E56, Bit Offset: 32, Bit Size: 16
    unsigned long pad48 : 16; // Offset: 0x0, DWARF: 0x1E80, Bit Offset: 48, Bit Size: 16
} XYOffset;

// Size: 0x8, DWARF: 0x2955
typedef struct Zbuf
{
    unsigned long ZBP : 9; // Offset: 0x0, DWARF: 0x2971, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 15; // Offset: 0x0, DWARF: 0x299B, Bit Offset: 9, Bit Size: 15
    unsigned long PSM : 4; // Offset: 0x0, DWARF: 0x29C7, Bit Offset: 24, Bit Size: 4
    unsigned long pad28 : 4; // Offset: 0x0, DWARF: 0x29F1, Bit Offset: 28, Bit Size: 4
    unsigned long ZMSK : 1; // Offset: 0x0, DWARF: 0x2A1D, Bit Offset: 32, Bit Size: 1
    unsigned long pad33 : 31; // Offset: 0x0, DWARF: 0x2A48, Bit Offset: 33, Bit Size: 31
} Zbuf;

// Size: 0x8, DWARF: 0x46D9
typedef struct Frame
{
    unsigned long FBP : 9; // Offset: 0x0, DWARF: 0x46F5, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 7; // Offset: 0x0, DWARF: 0x471F, Bit Offset: 9, Bit Size: 7
    unsigned long FBW : 6; // Offset: 0x0, DWARF: 0x474B, Bit Offset: 16, Bit Size: 6
    unsigned long pad22 : 2; // Offset: 0x0, DWARF: 0x4775, Bit Offset: 22, Bit Size: 2
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x47A1, Bit Offset: 24, Bit Size: 6
    unsigned long pad30 : 2; // Offset: 0x0, DWARF: 0x47CB, Bit Offset: 30, Bit Size: 2
    unsigned long FBMSK : 32; // Offset: 0x0, DWARF: 0x47F7, Bit Offset: 32, Bit Size: 32
} Frame;

// Size: 0x80, DWARF: 0x25AE
typedef struct Draw
{
    // Size: 0x8, DWARF: 0x46D9
    Frame frame1; // Offset: 0x0, DWARF: 0x25CA
    unsigned long frame1addr; // Offset: 0x8, DWARF: 0x25EF
    // Size: 0x8, DWARF: 0x2955
    Zbuf zbuf1; // Offset: 0x10, DWARF: 0x2616
    signed long zbuf1addr; // Offset: 0x18, DWARF: 0x263A
    // Size: 0x8, DWARF: 0x1DE4
    XYOffset xyoffset1; // Offset: 0x20, DWARF: 0x2660
    signed long xyoffset1addr; // Offset: 0x28, DWARF: 0x2688
    // Size: 0x8, DWARF: 0x42A7
    Scissor scissor1; // Offset: 0x30, DWARF: 0x26B2
    signed long scissor1addr; // Offset: 0x38, DWARF: 0x26D9
    // Size: 0x8, DWARF: 0x35F8
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x2702
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x272B
    // Size: 0x8, DWARF: 0xE03
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x2756
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x277D
    // Size: 0x8, DWARF: 0x38D9
    Dthe dthe; // Offset: 0x60, DWARF: 0x27A6
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x27C9
    // Size: 0x8, DWARF: 0xB20
    Test test1; // Offset: 0x70, DWARF: 0x27EE
    signed long test1addr; // Offset: 0x78, DWARF: 0x2812
} Draw;

// Size: 0x80, DWARF: 0x3070
typedef struct Draw2
{
    // Size: 0x8, DWARF: 0x46D9
    Frame frame2; // Offset: 0x0, DWARF: 0x308C
    unsigned long frame2addr; // Offset: 0x8, DWARF: 0x30B1
    // Size: 0x8, DWARF: 0x2955
    Zbuf zbuf2; // Offset: 0x10, DWARF: 0x30D8
    signed long zbuf2addr; // Offset: 0x18, DWARF: 0x30FC
    // Size: 0x8, DWARF: 0x1DE4
    XYOffset xyoffset2; // Offset: 0x20, DWARF: 0x3122
    signed long xyoffset2addr; // Offset: 0x28, DWARF: 0x314A
    // Size: 0x8, DWARF: 0x42A7
    Scissor scissor2; // Offset: 0x30, DWARF: 0x3174
    signed long scissor2addr; // Offset: 0x38, DWARF: 0x319B
    // Size: 0x8, DWARF: 0x35F8
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x31C4
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x31ED
    // Size: 0x8, DWARF: 0xE03
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x3218
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x323F
    // Size: 0x8, DWARF: 0x38D9
    Dthe dthe; // Offset: 0x60, DWARF: 0x3268
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x328B
    // Size: 0x8, DWARF: 0xB20
    Test test2; // Offset: 0x70, DWARF: 0x32B0
    signed long test2addr; // Offset: 0x78, DWARF: 0x32D4
} Draw2;

// Size: 0x8, DWARF: 0x2875
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x2891, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x28B9, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x28E1, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, DWARF: 0x2909, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4, DWARF: 0x2932
} BgColor;

// Size: 0x8, DWARF: 0x23A7, 0x3BCD
typedef struct Display
{
    unsigned int DX : 12; // Offset: 0x0, DWARF: 0x23C3, Bit Offset: 0, Bit Size: 12
    unsigned int DY : 11; // Offset: 0x0, DWARF: 0x23EC, Bit Offset: 12, Bit Size: 11
    unsigned int MAGH : 4; // Offset: 0x0, DWARF: 0x2415, Bit Offset: 23, Bit Size: 4
    unsigned int MAGV : 2; // Offset: 0x0, DWARF: 0x2440, Bit Offset: 27, Bit Size: 2
    unsigned int p0 : 3; // Offset: 0x0, DWARF: 0x246B, Bit Offset: 29, Bit Size: 3
    unsigned int DW : 12; // Offset: 0x4, DWARF: 0x2494, Bit Offset: 0, Bit Size: 12
    unsigned int DH : 11; // Offset: 0x4, DWARF: 0x24BD, Bit Offset: 12, Bit Size: 11
    unsigned int p1 : 9; // Offset: 0x4, DWARF: 0x24E6, Bit Offset: 23, Bit Size: 9
} Display;

// Size: 0x8, DWARF: 0x9DD, 0x2DD8
typedef struct DispFb
{
    unsigned int FBP : 9; // Offset: 0x0, DWARF: 0x9F8, Bit Offset: 0, Bit Size: 9
    unsigned int FBW : 6; // Offset: 0x0, DWARF: 0xA22, Bit Offset: 9, Bit Size: 6
    unsigned int PSM : 5; // Offset: 0x0, DWARF: 0xA4C, Bit Offset: 15, Bit Size: 5
    unsigned int p0 : 12; // Offset: 0x0, DWARF: 0xA76, Bit Offset: 20, Bit Size: 12
    unsigned int DBX : 11; // Offset: 0x4, DWARF: 0xA9F, Bit Offset: 0, Bit Size: 11
    unsigned int DBY : 11; // Offset: 0x4, DWARF: 0xAC9, Bit Offset: 11, Bit Size: 11
    unsigned int p1 : 10; // Offset: 0x4, DWARF: 0xAF3, Bit Offset: 22, Bit Size: 10
} DispFb;

// Size: 0x8, DWARF: 0x174C
typedef struct SMode
{
    unsigned int INT : 1; // Offset: 0x0, DWARF: 0x1768, Bit Offset: 0, Bit Size: 1
    unsigned int FFMD : 1; // Offset: 0x0, DWARF: 0x1792, Bit Offset: 1, Bit Size: 1
    unsigned int DPMS : 2; // Offset: 0x0, DWARF: 0x17BD, Bit Offset: 2, Bit Size: 2
    unsigned int p0 : 28; // Offset: 0x0, DWARF: 0x17E8, Bit Offset: 4, Bit Size: 28
    unsigned int p1; // Offset: 0x4, DWARF: 0x1811
} SMode;

// Size: 0x8, DWARF: 0x4827
typedef struct PMode
{
    unsigned int EN1 : 1; // Offset: 0x0, DWARF: 0x4843, Bit Offset: 0, Bit Size: 1
    unsigned int EN2 : 1; // Offset: 0x0, DWARF: 0x486D, Bit Offset: 1, Bit Size: 1
    unsigned int CRTMD : 3; // Offset: 0x0, DWARF: 0x4897, Bit Offset: 2, Bit Size: 3
    unsigned int MMOD : 1; // Offset: 0x0, DWARF: 0x48C3, Bit Offset: 5, Bit Size: 1
    unsigned int AMOD : 1; // Offset: 0x0, DWARF: 0x48EE, Bit Offset: 6, Bit Size: 1
    unsigned int SLBG : 1; // Offset: 0x0, DWARF: 0x4919, Bit Offset: 7, Bit Size: 1
    unsigned int ALP : 8; // Offset: 0x0, DWARF: 0x4944, Bit Offset: 8, Bit Size: 8
    unsigned int p0 : 16; // Offset: 0x0, DWARF: 0x496E, Bit Offset: 16, Bit Size: 16
    unsigned int p1; // Offset: 0x4, DWARF: 0x4997
} PMode;

// Size: 0x28, DWARF: 0x216A
typedef struct DispType
{
    // Size: 0x8, DWARF: 0x4827
    PMode pmode; // Offset: 0x0, DWARF: 0x2186
    // Size: 0x8, DWARF: 0x174C
    SMode smode2; // Offset: 0x8, DWARF: 0x21AA
    // Size: 0x8, DWARF: 0x9DD
    DispFb dispfb; // Offset: 0x10, DWARF: 0x21CF
    // Size: 0x8, DWARF: 0x23A7
    Display display; // Offset: 0x18, DWARF: 0x21F4
    // Size: 0x8, DWARF: 0x2875
    BgColor bgcolor; // Offset: 0x20, DWARF: 0x221A
} DispType;

// Size: 0x330, DWARF: 0x7A9
typedef struct DBuffType
{
    // Size: 0x28, DWARF: 0x216A
    DispType disp[2]; // Offset: 0x0, DWARF: 0x7C4
    // Size: 0x10, DWARF: 0xE7A
    sceGifTag giftag0; // Offset: 0x50, DWARF: 0x7E7
    // Size: 0x80, DWARF: 0x25AE
    Draw draw01; // Offset: 0x60, DWARF: 0x80D
    // Size: 0x80, DWARF: 0x3070
    Draw2 draw02; // Offset: 0xE0, DWARF: 0x832
    // Size: 0x60, DWARF: 0x3D39
    Clear clear0; // Offset: 0x160, DWARF: 0x857
    // Size: 0x10, DWARF: 0xE7A
    sceGifTag giftag1; // Offset: 0x1C0, DWARF: 0x87C
    // Size: 0x80, DWARF: 0x25AE
    Draw draw11; // Offset: 0x1D0, DWARF: 0x8A2
    // Size: 0x80, DWARF: 0x3070
    Draw2 draw12; // Offset: 0x250, DWARF: 0x8C7
    // Size: 0x60, DWARF: 0x3D39
    Clear clear1; // Offset: 0x2D0, DWARF: 0x8EC
} DBuffType;

// Size: 0x4, DWARF: 0x3F13
typedef struct Chcr
{
    unsigned int DIR : 1; // Offset: 0x0, DWARF: 0x3F2F, Bit Offset: 0, Bit Size: 1
    unsigned int p0 : 1; // Offset: 0x0, DWARF: 0x3F59, Bit Offset: 1, Bit Size: 1
    unsigned int MOD : 2; // Offset: 0x0, DWARF: 0x3F82, Bit Offset: 2, Bit Size: 2
    unsigned int ASP : 2; // Offset: 0x0, DWARF: 0x3FAC, Bit Offset: 4, Bit Size: 2
    unsigned int TTE : 1; // Offset: 0x0, DWARF: 0x3FD6, Bit Offset: 6, Bit Size: 1
    unsigned int TIE : 1; // Offset: 0x0, DWARF: 0x4000, Bit Offset: 7, Bit Size: 1
    unsigned int STR : 1; // Offset: 0x0, DWARF: 0x402A, Bit Offset: 8, Bit Size: 1
    unsigned int p1 : 7; // Offset: 0x0, DWARF: 0x4054, Bit Offset: 9, Bit Size: 7
    unsigned int TAG : 16; // Offset: 0x0, DWARF: 0x407D, Bit Offset: 16, Bit Size: 16
} Chcr;

// Size: 0x90, DWARF: 0x12B4
typedef struct DmaVif
{
    // Size: 0x4, DWARF: 0x3F13
    Chcr chcr; // Offset: 0x0, DWARF: 0x12CF
    unsigned int p0[3]; // Offset: 0x4, DWARF: 0x12F2
    void* madr; // Offset: 0x10, DWARF: 0x1313
    unsigned int p1[3]; // Offset: 0x14, DWARF: 0x1337
    unsigned int qwc; // Offset: 0x20, DWARF: 0x1358
    unsigned int p2[3]; // Offset: 0x24, DWARF: 0x1378
    _sceDmaTag* tadr; // Offset: 0x30, DWARF: 0x1399
    unsigned int p3[3]; // Offset: 0x34, DWARF: 0x13BF
    void* as0; // Offset: 0x40, DWARF: 0x13E0
    unsigned int p4[3]; // Offset: 0x44, DWARF: 0x1403
    void* as1; // Offset: 0x50, DWARF: 0x1424
    unsigned int p5[3]; // Offset: 0x54, DWARF: 0x1447
    unsigned int p6[4]; // Offset: 0x60, DWARF: 0x1468
    unsigned int p7[4]; // Offset: 0x70, DWARF: 0x1489
    void* sadr; // Offset: 0x80, DWARF: 0x14AA
    unsigned int p8[3]; // Offset: 0x84, DWARF: 0x14CE
} DmaVif;

// Size: 0x360, DWARF: 0x14F3
typedef struct VulsysSystem
{
    unsigned int KeepMemSize; // Offset: 0x0, DWARF: 0x150F
    signed int Pal; // Offset: 0x4, DWARF: 0x1537
    signed int Interlace; // Offset: 0x8, DWARF: 0x1557
    signed short ScreenMode; // Offset: 0xC, DWARF: 0x157D
    signed short ScreenWidth; // Offset: 0xE, DWARF: 0x15A4
    signed short ScreenHeight; // Offset: 0x10, DWARF: 0x15CC
    signed short ScreenYofs; // Offset: 0x12, DWARF: 0x15F5
    signed int EvenOdd; // Offset: 0x14, DWARF: 0x161C
    unsigned long Frame; // Offset: 0x18, DWARF: 0x1640
    signed int PadInit; // Offset: 0x20, DWARF: 0x1662
    // Size: 0x90, DWARF: 0x12B4
    DmaVif* DmaGif; // Offset: 0x24, DWARF: 0x1686
    // Size: 0x90, DWARF: 0x12B4
    DmaVif* DmaVif0; // Offset: 0x28, DWARF: 0x16AE
    // Size: 0x90, DWARF: 0x12B4
    DmaVif* DmaVif1; // Offset: 0x2C, DWARF: 0x16D7
    // Size: 0x330, DWARF: 0x7A9
    DBuffType DBuff; // Offset: 0x30, DWARF: 0x1700
} VulsysSystem;

// Size: 0x1, DWARF: 0x624
typedef struct Flag
{
    unsigned int filter : 1; // Offset: 0x0, DWARF: 0x63F, Bit Offset: 0, Bit Size: 1
    unsigned int dither : 1; // Offset: 0x0, DWARF: 0x66C, Bit Offset: 1, Bit Size: 1
    unsigned int oddeven : 1; // Offset: 0x0, DWARF: 0x699, Bit Offset: 2, Bit Size: 1
} Flag;

// Size: 0x8, DWARF: 0x3B57
typedef struct Fba
{
    unsigned long FBA : 1; // Offset: 0x0, DWARF: 0x3B73, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x3B9D, Bit Offset: 1, Bit Size: 63
} Fba;

// Size: 0x8, DWARF: 0x34D6
typedef struct TexA
{
    unsigned long TA0 : 8; // Offset: 0x0, DWARF: 0x34F2, Bit Offset: 0, Bit Size: 8
    unsigned long pad08 : 7; // Offset: 0x0, DWARF: 0x351C, Bit Offset: 8, Bit Size: 7
    unsigned long AEM : 1; // Offset: 0x0, DWARF: 0x3548, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x3572, Bit Offset: 16, Bit Size: 16
    unsigned long TA1 : 8; // Offset: 0x0, DWARF: 0x359E, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0x35C8, Bit Offset: 40, Bit Size: 24
} TexA;

// Size: 0x8, DWARF: 0x2537
typedef struct Pabe
{
    unsigned long PABE : 1; // Offset: 0x0, DWARF: 0x2553, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x257E, Bit Offset: 1, Bit Size: 63
} Pabe;

// Size: 0x8, DWARF: 0x366D
typedef struct Alpha2
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0x3689, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0x36B1, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0x36D9, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0x3701, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0x3729, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0x3754, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0x377E, Bit Offset: 40, Bit Size: 24
} Alpha2;

// Size: 0x60, DWARF: 0x32FE
typedef struct Alpha
{
    // Size: 0x8, DWARF: 0x366D
    Alpha2 alpha1; // Offset: 0x0, DWARF: 0x331A
    signed long alpha1addr; // Offset: 0x8, DWARF: 0x333F
    // Size: 0x8, DWARF: 0x366D
    Alpha2 alpha2; // Offset: 0x10, DWARF: 0x3366
    signed long alpha2addr; // Offset: 0x18, DWARF: 0x338B
    // Size: 0x8, DWARF: 0x2537
    Pabe pabe; // Offset: 0x20, DWARF: 0x33B2
    signed long pabeaddr; // Offset: 0x28, DWARF: 0x33D5
    // Size: 0x8, DWARF: 0x34D6
    TexA texa; // Offset: 0x30, DWARF: 0x33FA
    signed long texaaddr; // Offset: 0x38, DWARF: 0x341D
    // Size: 0x8, DWARF: 0x3B57
    Fba fba1; // Offset: 0x40, DWARF: 0x3442
    signed long fba1addr; // Offset: 0x48, DWARF: 0x3465
    // Size: 0x8, DWARF: 0x3B57
    Fba fba2; // Offset: 0x50, DWARF: 0x348A
    signed long fba2addr; // Offset: 0x58, DWARF: 0x34AD
} Alpha;

// Size: 0x8, DWARF: 0x1834
typedef struct Dimx
{
    unsigned long DIMX00 : 3; // Offset: 0x0, DWARF: 0x1850, Bit Offset: 0, Bit Size: 3
    unsigned long pad00 : 1; // Offset: 0x0, DWARF: 0x187D, Bit Offset: 3, Bit Size: 1
    unsigned long DIMX01 : 3; // Offset: 0x0, DWARF: 0x18A9, Bit Offset: 4, Bit Size: 3
    unsigned long pad01 : 1; // Offset: 0x0, DWARF: 0x18D6, Bit Offset: 7, Bit Size: 1
    unsigned long DIMX02 : 3; // Offset: 0x0, DWARF: 0x1902, Bit Offset: 8, Bit Size: 3
    unsigned long pad02 : 1; // Offset: 0x0, DWARF: 0x192F, Bit Offset: 11, Bit Size: 1
    unsigned long DIMX03 : 3; // Offset: 0x0, DWARF: 0x195B, Bit Offset: 12, Bit Size: 3
    unsigned long pad03 : 1; // Offset: 0x0, DWARF: 0x1988, Bit Offset: 15, Bit Size: 1
    unsigned long DIMX10 : 3; // Offset: 0x0, DWARF: 0x19B4, Bit Offset: 16, Bit Size: 3
    unsigned long pad10 : 1; // Offset: 0x0, DWARF: 0x19E1, Bit Offset: 19, Bit Size: 1
    unsigned long DIMX11 : 3; // Offset: 0x0, DWARF: 0x1A0D, Bit Offset: 20, Bit Size: 3
    unsigned long pad11 : 1; // Offset: 0x0, DWARF: 0x1A3A, Bit Offset: 23, Bit Size: 1
    unsigned long DIMX12 : 3; // Offset: 0x0, DWARF: 0x1A66, Bit Offset: 24, Bit Size: 3
    unsigned long pad12 : 1; // Offset: 0x0, DWARF: 0x1A93, Bit Offset: 27, Bit Size: 1
    unsigned long DIMX13 : 3; // Offset: 0x0, DWARF: 0x1ABF, Bit Offset: 28, Bit Size: 3
    unsigned long pad13 : 1; // Offset: 0x0, DWARF: 0x1AEC, Bit Offset: 31, Bit Size: 1
    unsigned long DIMX20 : 3; // Offset: 0x0, DWARF: 0x1B18, Bit Offset: 32, Bit Size: 3
    unsigned long pad20 : 1; // Offset: 0x0, DWARF: 0x1B45, Bit Offset: 35, Bit Size: 1
    unsigned long DIMX21 : 3; // Offset: 0x0, DWARF: 0x1B71, Bit Offset: 36, Bit Size: 3
    unsigned long pad21 : 1; // Offset: 0x0, DWARF: 0x1B9E, Bit Offset: 39, Bit Size: 1
    unsigned long DIMX22 : 3; // Offset: 0x0, DWARF: 0x1BCA, Bit Offset: 40, Bit Size: 3
    unsigned long pad22 : 1; // Offset: 0x0, DWARF: 0x1BF7, Bit Offset: 43, Bit Size: 1
    unsigned long DIMX23 : 3; // Offset: 0x0, DWARF: 0x1C23, Bit Offset: 44, Bit Size: 3
    unsigned long pad23 : 1; // Offset: 0x0, DWARF: 0x1C50, Bit Offset: 47, Bit Size: 1
    unsigned long DIMX30 : 3; // Offset: 0x0, DWARF: 0x1C7C, Bit Offset: 48, Bit Size: 3
    unsigned long pad30 : 1; // Offset: 0x0, DWARF: 0x1CA9, Bit Offset: 51, Bit Size: 1
    unsigned long DIMX31 : 3; // Offset: 0x0, DWARF: 0x1CD5, Bit Offset: 52, Bit Size: 3
    unsigned long pad31 : 1; // Offset: 0x0, DWARF: 0x1D02, Bit Offset: 55, Bit Size: 1
    unsigned long DIMX32 : 3; // Offset: 0x0, DWARF: 0x1D2E, Bit Offset: 56, Bit Size: 3
    unsigned long pad32 : 1; // Offset: 0x0, DWARF: 0x1D5B, Bit Offset: 59, Bit Size: 1
    unsigned long DIMX33 : 3; // Offset: 0x0, DWARF: 0x1D87, Bit Offset: 60, Bit Size: 3
    unsigned long pad33 : 1; // Offset: 0x0, DWARF: 0x1DB4, Bit Offset: 63, Bit Size: 1
} Dimx;

// Size: 0x40, DWARF: 0x2F1C
typedef struct Cmn
{
    // Size: 0x8, DWARF: 0x35F8
    PrModeCont prmodecont; // Offset: 0x0, DWARF: 0x2F38
    signed long prmodecontaddr; // Offset: 0x8, DWARF: 0x2F61
    // Size: 0x8, DWARF: 0xE03
    ColClamp colclamp; // Offset: 0x10, DWARF: 0x2F8C
    signed long colclampaddr; // Offset: 0x18, DWARF: 0x2FB3
    // Size: 0x8, DWARF: 0x38D9
    Dthe dthe; // Offset: 0x20, DWARF: 0x2FDC
    signed long dtheaddr; // Offset: 0x28, DWARF: 0x2FFF
    // Size: 0x8, DWARF: 0x1834
    Dimx dimx; // Offset: 0x30, DWARF: 0x3024
    signed long dimxaddr; // Offset: 0x38, DWARF: 0x3047
} Cmn;

// Size: 0x50, DWARF: 0x2A78
typedef struct FBuf
{
    // Size: 0x8, DWARF: 0x46D9
    Frame frame; // Offset: 0x0, DWARF: 0x2A94
    unsigned long frameaddr; // Offset: 0x8, DWARF: 0x2AB8
    // Size: 0x8, DWARF: 0x2955
    Zbuf zbuf; // Offset: 0x10, DWARF: 0x2ADE
    signed long zbufaddr; // Offset: 0x18, DWARF: 0x2B01
    // Size: 0x8, DWARF: 0x1DE4
    XYOffset xyoffset; // Offset: 0x20, DWARF: 0x2B26
    signed long xyoffsetaddr; // Offset: 0x28, DWARF: 0x2B4D
    // Size: 0x8, DWARF: 0x42A7
    Scissor scissor; // Offset: 0x30, DWARF: 0x2B76
    signed long scissoraddr; // Offset: 0x38, DWARF: 0x2B9C
    // Size: 0x8, DWARF: 0xB20
    Test test; // Offset: 0x40, DWARF: 0x2BC4
    signed long testaddr; // Offset: 0x48, DWARF: 0x2BE7
} FBuf;

// Size: 0x1B0, DWARF: 0x40F8
typedef struct Draw3
{
    // Size: 0x10, DWARF: 0xE7A
    sceGifTag giftag; // Offset: 0x0, DWARF: 0x4114
    // Size: 0x50, DWARF: 0x2A78
    FBuf fbuf[2]; // Offset: 0x10, DWARF: 0x4139
    // Size: 0x40, DWARF: 0x2F1C
    Cmn cmn; // Offset: 0xB0, DWARF: 0x415C
    // Size: 0x60, DWARF: 0x32FE
    Alpha alpha; // Offset: 0xF0, DWARF: 0x417E
    // Size: 0x60, DWARF: 0x3D39
    Clear clear; // Offset: 0x150, DWARF: 0x41A2
} Draw3;

// Size: 0x38, DWARF: 0x3950
typedef struct Disp
{
    // Size: 0x8, DWARF: 0x4827
    PMode pmode; // Offset: 0x0, DWARF: 0x396C
    // Size: 0x8, DWARF: 0x174C
    SMode smode2; // Offset: 0x8, DWARF: 0x3990
    // Size: 0x8, DWARF: 0x2DD8
    DispFb dispfb1; // Offset: 0x10, DWARF: 0x39B5
    // Size: 0x8, DWARF: 0x3BCD
    Display display1; // Offset: 0x18, DWARF: 0x39DB
    // Size: 0x8, DWARF: 0x9DD
    DispFb dispfb2; // Offset: 0x20, DWARF: 0x3A02
    // Size: 0x8, DWARF: 0x23A7
    Display display2; // Offset: 0x28, DWARF: 0x3A28
    // Size: 0x8, DWARF: 0x2875
    BgColor bgcolor; // Offset: 0x30, DWARF: 0x3A4F
} Disp;

// Size: 0x790, DWARF: 0x447F
typedef struct VgmsysFrameBuffer
{
    // Size: 0x38, DWARF: 0x3950
    Disp disp[3]; // Offset: 0x0, DWARF: 0x449B
    // Size: 0x1B0, DWARF: 0x40F8
    Draw3 draw[4]; // Offset: 0xB0, DWARF: 0x44BE
    unsigned short nbuf; // Offset: 0x770, DWARF: 0x44E1
    unsigned short idx; // Offset: 0x772, DWARF: 0x4502
    unsigned short count; // Offset: 0x774, DWARF: 0x4522
    unsigned short psm; // Offset: 0x776, DWARF: 0x4544
    unsigned short zpsm; // Offset: 0x778, DWARF: 0x4564
    signed short w; // Offset: 0x77A, DWARF: 0x4585
    signed short h; // Offset: 0x77C, DWARF: 0x45A3
    signed short cx; // Offset: 0x77E, DWARF: 0x45C1
    signed short cy; // Offset: 0x780, DWARF: 0x45E0
    unsigned short ztest; // Offset: 0x782, DWARF: 0x45FF
    unsigned short mode; // Offset: 0x784, DWARF: 0x4621
    // Size: 0x1, DWARF: 0x624
    Flag flag; // Offset: 0x786, DWARF: 0x4642
} VgmsysFrameBuffer;

// Size: 0x14, DWARF: 0x4238
typedef struct VgmsysGifPktBuff
{
    // Size: 0x10, DWARF: 0x6EF
    VgmsysGifPkt Packet; // Offset: 0x0, DWARF: 0x4254
    __int128* PacketBuff; // Offset: 0x10, DWARF: 0x4279
} VgmsysGifPktBuff;

//// Variables /////////////////////////////////////////////////////////

static signed int vgmsysScrMode; // Address: 0x2E7700
static signed int vgmsysNextScrMode; // Address: 0x2E7980
static signed int vgmsysPreScrMode; // Address: 0x2E7984
static void(* vgmsysSetScreenMode[3])(); // Address: 0x2B2DF0
signed int vsppScrWidth; // Address: 0x2E7704
signed int vsppScrHeight; // Address: 0x2E7708
static unsigned int vgmsysScrChangeCol; // Address: 0x2E7988
static signed int vgmsysDivide30Frame; // Address: 0x2E798C
static signed int vgmsysDivideActiveWid; // Address: 0x2E7990
static signed int vgmsysDivideType; // Address: 0x2E7994
static signed int vgmsysDivideLine; // Address: 0x2E7998
static signed int vsppMediaType; // Address: 0x2E770C
signed int vgmsysPadPausePid; // Address: 0x2E7B2C
void(*vgmsysEndFunc)(signed int, signed int); // Address: 0x2E79AC
signed int(*vgmsysFrameFunc)(signed int); // Address: 0x2E79B0
void(* vgmsysInitFunc[32])(signed int); // Address: 0x2EEA90
// Size: 0x20, DWARF: 0x1F1C
VgmsysVif1Pkt* vgmsysVif1Pkt; // Address: 0x2E79C8
// Size: 0x10, DWARF: 0x6EF
VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
// Size: 0x20, DWARF: 0x1F1C
VgmsysVif1Pkt _vgmsysVif1Pkt; // Address: 0x2EF2A0
// Size: 0x14, DWARF: 0x4238
VgmsysGifPktBuff _vgmsysGifPkt; // Address: 0x2EF2C0
// Size: 0x790, DWARF: 0x447F
VgmsysFrameBuffer vgmsysFrameBuffer; // Address: 0x2EEB10
// Size: 0x360, DWARF: 0x14F3
VulsysSystem vulsysSystem; // Address: 0x2F3A50
signed int vgmsysBlurPow; // Address: 0x2E79A8
signed int vgmsysWndBlurPow[2]; // Address: 0x2E79A0
// Size: 0x8, DWARF: 0x37AE
VgmsysClock vgmsysClock; // Address: 0x2E79B8
// Size: 0x20, DWARF: 0x22B0
VspenvDemo vspenvDemo; // Address: 0x3473D0
// Size: 0x20, DWARF: 0xCC2
VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0
__int128* vgmsysAbufmem; // Address: 0x2E79C4
signed int _stack[]; // Address: 0x1FF0000
signed int _end[]; // Address: 0x3C9900

signed int main();
static void gmsysTotalInit();
static void gmsysInitIop(signed int first);
void gmsysSetModule(signed int mod_no, void(*modinit)(signed int));
static void gmsysInitGsRegister();
void gmsysSetScreenMode_normal();
void gmsysSetScreenMode_on_play();
static void gmsysSetScrMode__normal();
static void gmsysSetScrMode__depth_of_field();
static void gmsysSetScrMode__anti_alias();
void gmsysResetBlurPow();
void gmsysSetBlurPow(signed int pow);
void gmsysSetWndBlurPow(signed int wid, signed int pow);
void gmsysSetScrChangeColor(unsigned char r, unsigned char g, unsigned char b);
void gmsysSetScrFlipMode(signed int div30fr);
void gmsysSetScrActiveWnd(signed int wid);
void gmsysSetScrDivType(signed int type);
void gmsysSetScrDivLine(signed int line);

// Other included functions
signed int ulgraphSetDefFrameBuff(VgmsysFrameBuffer* fb, unsigned short psm, unsigned short zpsm, signed short w, signed short h, unsigned short ztest, unsigned short mode);


signed int main() {
    signed int temp_v1;
    signed int temp_v1_2;
    
    signed int mod_no; // r16 $s0
    signed int first_boot; // r17 $s1
    signed int next_mod_no; // r17 $s1
    signed int oddeven; // r18 $s2
    signed int x; // r18 $s2
    signed int y; // r18 $s2
    signed int pow0; // r10 $t2
    signed int pow1; // r19 $s3

    mod_no = -1;
    next_mod_no = 0;
    first_boot = 1;
    vspenvDemo.time_out = 0xE10;
    vspenvDemo.play_time_out = 0x3840;
    vspenvDemo.demo = 0;
    gmsysTotalInit();
    gmsysInitIop(first_boot);
    sceCdReadClock(&vgmsysClock);
    srand(vgmsysClock.second + (vgmsysClock.minute * vgmsysClock.hour));
    akSrandf(rand());
    spinitInit();
    next_mod_no = 0;
    gmsysPadInit();
    ulmcSysInit(1);
    ulsdInit();
    nmsndInit();
    ulmov2InitMovie();
    sceGsSyncV(0);
    while (1) {
        sceGsSyncPath(0, 0);
        *VIF1_FBRST = 1;
        *GIF_CTRL = 1;
        if (ulmov2IsPlaying() == 0) {
            if (_fbss != vgmsysScrMode) {
                vgmsysSetScreenMode[_fbss]();
                oddeven = (sceGsSyncV(0) != 0) ^ 1;
                ulgraphCleanFrameBuff(vulsysSystem.DmaGif, &vgmsysFrameBuffer, vgmsysScrChangeCol);
                ulgraphFlipFrameBuff(vulsysSystem.DmaGif, &vgmsysFrameBuffer, oddeven);
                vgmsysPreScrMode = vgmsysScrMode;
                vgmsysScrMode = _fbss;
            } else {
                ulgraphCopyDrawToDispBuffer(vulsysSystem.DmaGif, &vgmsysFrameBuffer);
                if (vgmsysScrMode == 2) {
                    ulgraphEffectDepthOfField(vulsysSystem.DmaGif, &vgmsysFrameBuffer, ((vsppScrWidth + 64 - 1) / 64) * ((vsppScrHeight + 32 - 1) / 32) * 0x20 * 3, 0x6000, 0x40808080, 0x2000, 0x40808080);
                }
                switch (vgmsysDivideType) {
                case 1:
                    x = vgmsysDivideLine;
                    if (vgmsysBlurPow == 0) {
                        pow0 = vgmsysWndBlurPow[0];
                        pow1 = vgmsysWndBlurPow[1];
                    } else {
                        pow0 = vgmsysBlurPow;
                        pow1 = vgmsysBlurPow;
                    }
                    akfxMotionBlur(vulsysSystem.DmaGif, &vgmsysFrameBuffer, 0, 0, x, vsppScrHeight, pow0, 0);
                    akfxMotionBlur(vulsysSystem.DmaGif, &vgmsysFrameBuffer, x, 0, vsppScrWidth-x, vsppScrHeight, pow1, 0);
                    break;
                case 2:
                    y = vgmsysDivideLine;
                    if (vgmsysBlurPow == 0) {
                        pow0 = vgmsysWndBlurPow[0];
                        pow1 = vgmsysWndBlurPow[1];
                    } else {
                        pow0 = vgmsysBlurPow;
                        pow1 = vgmsysBlurPow;
                    }
                    akfxMotionBlur(vulsysSystem.DmaGif, &vgmsysFrameBuffer, 0, 0, vsppScrWidth, y, pow0, 0);
                    akfxMotionBlur(vulsysSystem.DmaGif, &vgmsysFrameBuffer, 0, y, vsppScrWidth, vsppScrHeight-y, pow1, 0);
                    break;
                default:
                case 0:
                    if (vgmsysBlurPow == 0) {
                        pow0 = vgmsysWndBlurPow[0];
                    } else {
                        pow0 = vgmsysBlurPow;
                    }
                    akfxMotionBlur(vulsysSystem.DmaGif, &vgmsysFrameBuffer, 0, 0, vsppScrWidth, vsppScrHeight, pow0, 0);
                    break;
                }
                
                oddeven = (sceGsSyncV(0) != 0) ^ 1;
                if ((vgmsysDivideType != 0) && (vgmsysPreScrMode != vgmsysScrMode)) {
                    ulgraphCleanFrameBuff(vulsysSystem.DmaGif, &vgmsysFrameBuffer, vgmsysScrChangeCol);
                }
                aksubFlipFrameBuff(vulsysSystem.DmaGif, &vgmsysFrameBuffer, oddeven, (vgmsysDivide30Frame != 0) ^ 1);
                vgmsysPreScrMode = vgmsysScrMode;
            }
        } else {
            ulmov2EndFrame();
        }
        vgmsysGifPkt = &_vgmsysGifPkt.Packet;
        vgmsysVif1Pkt = &_vgmsysVif1Pkt;
        sceGifPkReset(vgmsysGifPkt);
        sceVif1PkReset(vgmsysVif1Pkt);
        ulmcServer();
        gmsysPadMain();
        gmsysInitGsRegister();
        if (next_mod_no != mod_no) {
            if (next_mod_no < 0) {
                next_mod_no = -next_mod_no - 1;
            }
            mod_no = next_mod_no;
            vgmsysFrameFunc = 0;
            vgmsysEndFunc = 0;
            if (vgmsysInitFunc[mod_no] != 0) {
                vgmsysInitFunc[mod_no](mod_no);
            } else {
                ulstdPrintf("<No vgmsysInitFunc[%d]>\n", mod_no);
                ABORT();
            }
        }
        if (vgmsysFrameFunc != 0) {
            next_mod_no = vgmsysFrameFunc(mod_no);
        } else {
            ulstdPrintf("<No vgmsysFrameFunc>\n");
            ABORT();
        }
        if ((next_mod_no != mod_no) && (vgmsysEndFunc != 0)) {
            vgmsysEndFunc(mod_no, 0);
        }
        if (vgmsysPadPausePid < 0) {
            nmsndFrame(0);
            continue;
        }
        nmsndFrame(1);
    }
}

static void gmsysTotalInit() {
    signed int i; // r16 $s0
    void* heapend; // r17 $s1
    void* top_gifpkt; // r18 $s2
    void* heapstart; // r19 $s3
    unsigned int heap1size; // r20 $s4
    void* top_vif1pkt; // r21 $s5
    signed int texbp; // r22 $s6

    heapstart = &_end;
    heapend = (void*)((int)&_stack + 0xFFF80000);
    heap1size = 0x01800000;
    top_gifpkt = heapend;
    top_vif1pkt = (void*)((int)top_gifpkt + 0x40000);
    
    ulInitHeap(heapstart, heapend, heap1size);
    ulsysInitSystem(4, 1, 0); // Pal Mode = 0
    vulsysSystem.DBuff.draw01.dthe.DTHE = 1;
    vulsysSystem.DBuff.draw11.dthe.DTHE = 1;
    vulsysSystem.DBuff.draw02.dthe.DTHE = 1;
    vulsysSystem.DBuff.draw12.dthe.DTHE = 1;
    texbp = ulgraphSetDefFrameBuff(&vgmsysFrameBuffer, 0, 0x31, vsppScrWidth, vsppScrHeight, 2, 0x210);
    sceGsSetDefDBuffDc(&vulsysSystem.DBuff, 0, 0x280, 0xE0, 3, 0x31, 1);
    _vgmsysGifPkt.PacketBuff = top_gifpkt;
    sceGifPkInit(&_vgmsysGifPkt, _vgmsysGifPkt.PacketBuff);
    sceGifPkReset(&_vgmsysGifPkt);
    vgmsysGifPkt = &_vgmsysGifPkt.Packet;
    sceVif1PkInit(&_vgmsysVif1Pkt, top_vif1pkt);
    sceVif1PkReset(&_vgmsysVif1Pkt);
    vgmsysVif1Pkt = &_vgmsysVif1Pkt;
    vgmsysAbufmem = (void*)ulMalloc(0x53FE0, 0, 1);
    vgmsysAbuf = (void*)ulgraphAlphaInitBuf(vgmsysAbufmem, 0x5DC, 0x4E20);
    for (i = 0; i < 0x20; i++) {
        vgmsysInitFunc[i] = 0;
    }
    vgmsysFrameFunc = 0;
    vgmsysEndFunc = 0;
    gmsysResetBlurPow();
    sceGsSetHalfOffset(&vulsysSystem.DBuff.draw01, 0x800, 0x800, 0);
    sceGsSetHalfOffset2(&vulsysSystem.DBuff.draw02, 0x800, 0x800, 0);
    sceGsSetHalfOffset(&vulsysSystem.DBuff.draw11, 0x800, 0x800, 0);
    sceGsSetHalfOffset2(&vulsysSystem.DBuff.draw12, 0x800, 0x800, 0);
    FlushCache(0);
    sceGsSwapDBuffDc(&vulsysSystem.DBuff, 0);
    while (*(signed int* )0x1000A000 & 0x100) {}
    sceGsSwapDBuffDc(&vulsysSystem.DBuff, 1);
    while (*(signed int* )0x1000A000 & 0x100) {}
    sceGsSyncPath(0, 0);
}

static void gmsysInitIop(signed int first) {
    char ioprp[256]; // 0x10(r29)

    // first = first; // 110
    sceSifInitRpc(0);
    uldvdInitCdvd_DRIVE(vsppMediaType);
    if (first == 1) {
        ulstdSprintf(&ioprp, "cdrom0:\\MODULES\\%s;1", "IOPRP234.IMG"); // @141, @142
        while (sceSifRebootIop(&ioprp) == 0) {}
        while (sceSifSyncIop() == 0) {}
        sceSifInitRpc(0);
        sceSifInitIopHeap();
        sceSifLoadFileReset();
        uldvdInitCdvd_DRIVE(vsppMediaType);
        sceFsReset();
        while (sceSifLoadModule("cdrom0:\\MODULES\\SIO2MAN.IRX;1", 0, 0) < 0) {} // @142
        while (sceSifLoadModule("cdrom0:\\MODULES\\PADMAN.IRX;1", 0, 0) < 0)  {} // @144
        while (sceSifLoadModule("cdrom0:\\MODULES\\MCMAN.IRX;1", 0, 0) < 0)   {} // @145
        while (sceSifLoadModule("cdrom0:\\MODULES\\MCSERV.IRX;1", 0, 0) < 0)  {} // @146
        while (sceSifLoadModule("cdrom0:\\MODULES\\LIBSD.IRX;1", 0, 0) < 0)   {} // @147
        while (sceSifLoadModule("cdrom0:\\MODULES\\SDRDRV.IRX;1", 0, 0) < 0)  {} // @148
        while (sceSifLoadModule("cdrom0:\\MODULES\\MODMIDI.IRX;1", 0, 0) < 0) {} // @149
        while (sceSifLoadModule("cdrom0:\\MODULES\\MODSESQ.IRX;1", 0, 0) < 0) {} // @150
        while (sceSifLoadModule("cdrom0:\\MODULES\\MODHSYN.IRX;1", 0, 0) < 0) {} // @151
        while (sceSifLoadModule("cdrom0:\\MODULES\\ULMSD.IRX;1", 0, 0) < 0)   {} // @152
    }
}

void gmsysSetModule(signed int mod_no, void(*modinit)(signed int)) {
    if (mod_no >= 0 && mod_no < 0x20) {
        vgmsysInitFunc[mod_no] = modinit;
    }
}

static void gmsysInitGsRegister() {
    long tmp;
    // Size: 0x10, DWARF: 0x6EF
    VgmsysGifPkt* packet; // r16 $s0
    __int128 giftagAD; // 0x30(r29)

    packet = vgmsysGifPkt;
    
    ((long*)&giftagAD)[0] = SCE_GIF_SET_TAG(0, 1, 0, 0, 0, 1);
    ((long*)&giftagAD)[1] = tmp = SCE_GIF_PACKED_AD;
    
    FlushCache(0);
    sceGifPkReset(packet);
    sceGifPkCnt(packet, 0, 0, 0);
    sceGifPkOpenGifTag(packet, giftagAD);
    sceGifPkAddGsAD(packet, 0x42, 0x44);
    sceGifPkAddGsAD(packet, 0x43, 0x44);
    sceGifPkAddGsAD(packet, 0x49, 0);
    sceGifPkAddGsAD(packet, 0x3B, 0x80);
    sceGifPkAddGsAD(packet, 0x14, 0x60);
    sceGifPkAddGsAD(packet, 0x15, 0x60);
    sceGifPkAddGsAD(packet, 0x3F, 0);
    sceGifPkCloseGifTag(packet);
    sceGifPkEnd(packet, 0, 0, 0);
    sceGifPkTerminate(packet);
    ulgifDmaSend(packet);
    ulgifDmaWait();
}

void gmsysSetScreenMode_normal() {
    _fbss = 0;
}

void gmsysSetScreenMode_on_play() {
    _fbss = 1;
}

static void gmsysSetScrMode__normal() {
    vsppScrWidth = 640;
    vsppScrHeight = 224;
    vgmsysFrameBuffer.flag.filter = 0;
    ulgraphSetDefFrameBuff(&vgmsysFrameBuffer, 0, 0x31, vsppScrWidth, vsppScrHeight, 2, 0x210);
}

static void gmsysSetScrMode__depth_of_field(void) {
    vsppScrWidth = 640;
    vsppScrHeight = 224;
    vgmsysFrameBuffer.flag.filter = 0;
    ulgraphSetDefFrameBuff(&vgmsysFrameBuffer, 0, 0x31, vsppScrWidth, vsppScrHeight, 2, 0x210);
}

static void gmsysSetScrMode__anti_alias(void) {
    vsppScrWidth = 512;
    vsppScrHeight = 448;
    vgmsysFrameBuffer.flag.filter = 1;
    ulgraphSetDefFrameBuff(&vgmsysFrameBuffer, 0, 0x31, vsppScrWidth, vsppScrHeight, 2, 0x211);
}

void gmsysResetBlurPow() {
    signed int i; // r16
    vgmsysBlurPow = 0;
    for (i = 0; i < 2; i++) {
        vgmsysWndBlurPow[i] = 0;
    }
}

void gmsysSetBlurPow(signed int pow) {
    if (pow < 0) {
        pow = 0;
    }
    if (0x80 < pow) {
        pow = 0x80;
    }
    vgmsysBlurPow = pow;
}

void gmsysSetWndBlurPow(signed int wid, signed int pow) {
    if (pow < 0) {
        pow = 0;
    }
    if (0x80 < pow) {
        pow = 0x80;
    }
    vgmsysWndBlurPow[wid] = pow;
}

void gmsysSetScrChangeColor(unsigned char r, unsigned char g, unsigned char b) {
    vgmsysScrChangeCol = b | (r << 16 | g << 8);
}

void gmsysSetScrFlipMode(signed int div30fr) {
    vgmsysDivide30Frame = div30fr;
}

void gmsysSetScrActiveWnd(signed int wid) {
    if (vgmsysDivide30Frame != 0) {
        vgmsysDivideActiveWid = wid;
    }
}

void gmsysSetScrDivType(signed int type) {
    if (type < 0 || 2 < type) {
        type = 0;
    }
    vgmsysDivideType = type;
}

void gmsysSetScrDivLine(signed int line) {
    if (vgmsysDivideType == 1) {
        if (line < 0) {
            line = 0;
        }
        if (line > vsppScrWidth) {
            line = vsppScrWidth;
        }
        vgmsysDivideLine = line;
        return;
    }
    else if (vgmsysDivideType == 2) {
        if (line < 0) {
            line = 0;
        }
        if (line > vsppScrHeight) {
            line = vsppScrHeight;
        }
        vgmsysDivideLine = line;
        return;
    }
}

// Other included functions
signed int ulgraphSetDefFrameBuff(VgmsysFrameBuffer* fb, unsigned short psm, unsigned short zpsm, signed short w, signed short h, unsigned short ztest, unsigned short mode);
