typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long s64;
typedef unsigned long u64;
typedef float f32;
typedef double f64;
typedef unsigned int u_int;
typedef __int128 int128;
typedef __int128 s128;
typedef unsigned __int128 u_int128;

#define ABORT() asm(".word 0x0000000d")

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop)<<15) | ((u64)(pre) << 46) | \
    ((u64)(prim)<<47) | ((u64)(flg)<<58) | ((u64)(nreg)<<60))

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
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
void sceVu0CopyVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2); // (Copies vec2 onto vec)
void sceVu0AddVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);

// nmdraw.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x15488E
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x107E1A
    __int128* pBase; // Offset: 0x4, DWARF: 0x107E42
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x107E67
    unsigned long* psceGifTag; // Offset: 0xC, DWARF: 0x107E8E
} VgmsysGifPkt;

// Size: 0x20, DWARF: 0x155AF9
typedef struct Fade
{
    signed int cnt; // Offset: 0x0, DWARF: 0x134BB4
    signed int flag; // Offset: 0x4, DWARF: 0x134BD4
    signed int type; // Offset: 0x8, DWARF: 0x134BF5
    signed int col; // Offset: 0xC, DWARF: 0x134C16
    signed int max; // Offset: 0x10, DWARF: 0x134C36
    signed int res[3]; // Offset: 0x14, DWARF: 0x134C56
} Fade;

// Size: 0x10, DWARF: 0x154240
typedef struct Tex
{
    signed short tofs; // Offset: 0x0, DWARF: 0x133E30
    signed short cofs; // Offset: 0x2, DWARF: 0x133E51
    signed short width; // Offset: 0x4, DWARF: 0x133E72
    signed short height; // Offset: 0x6, DWARF: 0x133E94
    signed short tw; // Offset: 0x8, DWARF: 0x133EB7
    signed short th; // Offset: 0xA, DWARF: 0x133ED6
    signed short image_bit; // Offset: 0xC, DWARF: 0x133EF5
    signed short clut_bit; // Offset: 0xE, DWARF: 0x133F1B
} Tex;

// Size: 0x40, DWARF: 0x1571B6
typedef struct Key
{
    sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x1351BA
    // Size: 0x10, DWARF: 0x133E14
    Tex* data; // Offset: 0x10, DWARF: 0x1351DC
    signed int button; // Offset: 0x14, DWARF: 0x135202
    signed int message; // Offset: 0x18, DWARF: 0x135225
    signed int cnt; // Offset: 0x1C, DWARF: 0x135249
    signed int center; // Offset: 0x20, DWARF: 0x135269
    signed int language; // Offset: 0x24, DWARF: 0x13528C
    signed int mode; // Offset: 0x28, DWARF: 0x1352B1
    signed int res[2]; // Offset: 0x2C, DWARF: 0x1352D2
} Key;

// Size: 0x10, DWARF: 0x13C672
typedef struct TexOption
{
    signed int sprite; // Offset: 0x0, DWARF: 0x13C68E
    signed int bil; // Offset: 0x4, DWARF: 0x13C6B1
    float width; // Offset: 0x8, DWARF: 0x13C6D1
    float height; // Offset: 0xC, DWARF: 0x13C6F3
} TexOption;

// Size: 0x70, DWARF: 0x15571F
typedef struct DispBar
{
    sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x13635C
    signed int col[4][4]; // Offset: 0x10, DWARF: 0x13637E
    // Size: 0x10, DWARF: 0x13C672
    TexOption option; // Offset: 0x50, DWARF: 0x1363A0
    signed int type; // Offset: 0x60, DWARF: 0x1363C5
    signed int res[3]; // Offset: 0x64, DWARF: 0x1363E6
} DispBar;

// Size: 0x60, DWARF: 0x1546D1
typedef struct Time
{
    float pos[4]; // Offset: 0x0, DWARF: 0x1370D9
    signed int col[4][4]; // Offset: 0x10, DWARF: 0x1370FB
    signed int frame; // Offset: 0x50, DWARF: 0x13711D
    signed int type; // Offset: 0x54, DWARF: 0x13713F
    signed int size[2]; // Offset: 0x58, DWARF: 0x137160
} Time;

// Size: 0x70, DWARF: 0x153FE5
typedef struct Point
{
    float pos[4]; // Offset: 0x0, DWARF: 0x138010
    signed int col[4][4]; // Offset: 0x10, DWARF: 0x138032
    signed int point; // Offset: 0x50, DWARF: 0x138054
    signed int type; // Offset: 0x54, DWARF: 0x138076
    signed int size[2]; // Offset: 0x58, DWARF: 0x138097
    signed int flat; // Offset: 0x60, DWARF: 0x1380BA
    signed int base; // Offset: 0x64, DWARF: 0x1380DB
    signed int language; // Offset: 0x68, DWARF: 0x1380FC
    signed int res; // Offset: 0x6C, DWARF: 0x138121
} Point;

// Size: 0x30, DWARF: 0x154135
typedef struct Check
{
    float pos[4]; // Offset: 0x0, DWARF: 0x136AB0
    // Size: 0x10, DWARF: 0x133E14
    Tex* data; // Offset: 0x10, DWARF: 0x136AD2
    signed int cnt; // Offset: 0x14, DWARF: 0x136AF8
    signed int res[3]; // Offset: 0x18, DWARF: 0x136B18
} Check;

// Size: 0x30, DWARF: 0x139290
typedef struct Allow
{
    float pos[4]; // Offset: 0x0, DWARF: 0x1392AC
    // Size: 0x10, DWARF: 0x133E14
    Tex* data; // Offset: 0x10, DWARF: 0x1392CE
    signed int abe; // Offset: 0x14, DWARF: 0x1392F4
    signed int type; // Offset: 0x18, DWARF: 0x139314
    float width; // Offset: 0x1C, DWARF: 0x139335
    float height; // Offset: 0x20, DWARF: 0x139357
} Allow;

// Size: 0x40, DWARF: 0x155BDD
typedef struct DispBalance
{
    sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x13A09E
    // Size: 0x10, DWARF: 0x133E14
    Tex* data; // Offset: 0x10, DWARF: 0x13A0C0
    sceVu0FVECTOR ratio; // Offset: 0x20, DWARF: 0x13A0E6
    signed int abe; // Offset: 0x30, DWARF: 0x13A10A
    signed int type; // Offset: 0x34, DWARF: 0x13A12A
    float per; // Offset: 0x38, DWARF: 0x13A14B
    signed int res; // Offset: 0x3C, DWARF: 0x13A16B
} DispBalance;

// Size: 0x50, DWARF: 0x155ED2
typedef struct Meter
{
    float pos[4]; // Offset: 0x0, DWARF: 0x13AE12
    signed int col[2][4]; // Offset: 0x10, DWARF: 0x13AE34
    float ratio; // Offset: 0x30, DWARF: 0x13AE56
    float per; // Offset: 0x34, DWARF: 0x13AE78
    signed int type; // Offset: 0x38, DWARF: 0x13AE98
    signed int frame; // Offset: 0x3C, DWARF: 0x13AEB9
    signed int shadow; // Offset: 0x40, DWARF: 0x13AEDB
    signed int div; // Offset: 0x44, DWARF: 0x13AEFE
    float div_per; // Offset: 0x48, DWARF: 0x13AF1E
    signed int res; // Offset: 0x4C, DWARF: 0x13AF42
} Meter;

// Size: 0x70, DWARF: 0x155CEA
typedef struct Ice
{
    sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x13BCA9
    // Size: 0x10, DWARF: 0x133E14
    Tex* data; // Offset: 0x10, DWARF: 0x13BCCB
    signed int col[4][4] __attribute__((aligned(16))); // Offset: 0x20, DWARF: 0x13BCF1
    float width; // Offset: 0x60, DWARF: 0x13BD13
    float height; // Offset: 0x64, DWARF: 0x13BD35
    signed int pack; // Offset: 0x68, DWARF: 0x13BD58
    signed int res; // Offset: 0x6C, DWARF: 0x13BD79
} Ice;

// Size: 0x20, DWARF: 0x157749
typedef struct PadState
{
    signed int id; // Offset: 0x0, DWARF: 0x140E59
    unsigned int now; // Offset: 0x4, DWARF: 0x140E78
    unsigned int status; // Offset: 0x8, DWARF: 0x140E98
    unsigned int press; // Offset: 0xC, DWARF: 0x140EBB
    signed char right_h; // Offset: 0x10, DWARF: 0x140EDD
    signed char right_v; // Offset: 0x11, DWARF: 0x140F01
    signed char left_h; // Offset: 0x12, DWARF: 0x140F25
    signed char left_v; // Offset: 0x13, DWARF: 0x140F48
    unsigned char l_right; // Offset: 0x14, DWARF: 0x140F6B
    unsigned char l_left; // Offset: 0x15, DWARF: 0x140F8F
    unsigned char l_up; // Offset: 0x16, DWARF: 0x140FB2
    unsigned char l_down; // Offset: 0x17, DWARF: 0x140FD3
    unsigned char r_up; // Offset: 0x18, DWARF: 0x140FF6
    unsigned char r_right; // Offset: 0x19, DWARF: 0x141017
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x14103B
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x14105E
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x141081
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x1410A1
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x1410C1
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x1410E1
} PadState;

// Size: 0x60, DWARF: 0x15541D
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0x140E3C
    PadState now; // Offset: 0x0, DWARF: 0x1358F5
    // Size: 0x20, DWARF: 0x140E3C
    PadState old; // Offset: 0x20, DWARF: 0x135917
    unsigned int port; // Offset: 0x40, DWARF: 0x135939
    unsigned int slot; // Offset: 0x44, DWARF: 0x13595A
    unsigned int mode; // Offset: 0x48, DWARF: 0x13597B
    unsigned int trg; // Offset: 0x4C, DWARF: 0x13599C
    unsigned int rev; // Offset: 0x50, DWARF: 0x1359BC
    unsigned int cnt; // Offset: 0x54, DWARF: 0x1359DC
    unsigned int rep; // Offset: 0x58, DWARF: 0x1359FC
    signed int state; // Offset: 0x5C, DWARF: 0x135A1C
} VgmsysPad;

// Size: 0x30, DWARF: 0x1567F6
typedef struct Dual
{
    float pos[4]; // Offset: 0x0, DWARF: 0x13ED48
    // Size: 0x10, DWARF: 0x133E14
    Tex* data; // Offset: 0x10, DWARF: 0x13ED6A
    // Size: 0x60, DWARF: 0x1358D9
    VgmsysPad* ope; // Offset: 0x14, DWARF: 0x13ED90
    signed int abe; // Offset: 0x18, DWARF: 0x13EDB5
    float ratio; // Offset: 0x1C, DWARF: 0x13EDD5
    signed int res[2]; // Offset: 0x20, DWARF: 0x13EDF7
} Dual;

// Size: 0x90, DWARF: 0x154992
typedef struct Poly
{
    float vertex[4][4]; // Offset: 0x0, DWARF: 0x140CD8
    signed int col[4][4]; // Offset: 0x40, DWARF: 0x140CFD
    // Size: 0x10, DWARF: 0x13C672
    TexOption option; // Offset: 0x80, DWARF: 0x140D1F
} Poly;

// Size: 0xB0, DWARF: 0x15608F
typedef struct DispTex
{
    // Size: 0x10, DWARF: 0x133E14
    Tex* data; // Offset: 0x0, DWARF: 0x13F372
    signed int tex_size[2]; // Offset: 0x4, DWARF: 0x13F398
    signed int tex_uv[2]; // Offset: 0xC, DWARF: 0x13F3BF
    sceVu0FMATRIX vertex; // Offset: 0x20, DWARF: 0x13F3E4
    signed int col[4][4]; // Offset: 0x60, DWARF: 0x13F409
    // Size: 0x10, DWARF: 0x13C672
    TexOption option; // Offset: 0xA0, DWARF: 0x13F42B
} DispTex;

// Size: 0x10, DWARF: 0xEB4D6
typedef struct sceGifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0x22B50, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0x22B7C, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x22BA6, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0x22BD2, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0x22BFB, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0x22C25, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0x22C50, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0x22C7A, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0x22CA5, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0x22CD1, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0x22CFD, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0x22D29, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0x22D55, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0x22D81, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0x22DAD, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0x22DD9, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0x22E05, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0x22E31, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0x22E5D, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0x22E8A, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0x22EB7, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0x22EE4, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0x22F11, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0x22F3E, Bit Offset: 60, Bit Size: 4
} sceGifTag __attribute__((aligned(16)));

// Size: 0x10, DWARF: 0x1541DE
// Size: 0x10, DWARF: 0xEBA4A
typedef union GifTag
{
    // Size: 0x10, DWARF: 0xEB4D6
    sceGifTag sce; // Offset: 0x0, DWARF: 0xEBA66
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0xEBA88
} GifTag;

// Size: 0x8, DWARF: 0xEC97B
typedef struct Prim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0xEC997, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0xEC9C2, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0xEC9EC, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0xECA16, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0xECA40, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0xECA6A, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0xECA94, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0xECABE, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0xECAE9, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0xECB13, Bit Offset: 11, Bit Size: 53
} Prim;

// Size: 0x8, DWARF: 0x15464B
typedef union Prim_Ul
{
    // Size: 0x8, DWARF: 0xEC97B
    Prim sce; // Offset: 0x0, DWARF: 0xEC06E
    unsigned long ul; // Offset: 0x0, DWARF: 0xEC090
} Prim_Ul;

// Size: 0x8, DWARF: 0xEDD00
typedef struct RGBAQ
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0xEDD1C, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0xEDD44, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0xEDD6C, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0xEDD94, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0xEDDBC
} RGBAQ;

// Size: 0x8, DWARF: 0x15480A
typedef union RGBAQ_Ul
{
    // Size: 0x8, DWARF: 0xEDD00
    RGBAQ sce; // Offset: 0x0, DWARF: 0xEC270
    unsigned long ul; // Offset: 0x0, DWARF: 0xEC292
} RGBAQ_Ul;

// Size: 0x8, DWARF: 0xEC4FE
typedef struct XYZF
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0xEC75D, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0xEC785, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 24; // Offset: 0x0, DWARF: 0xEC7AD, Bit Offset: 32, Bit Size: 24
    unsigned long F : 8; // Offset: 0x0, DWARF: 0xEC7D5, Bit Offset: 56, Bit Size: 8
} XYZF;

// Size: 0x8, DWARF: 0x154A1E
typedef union XYZF_Ul
{
    // Size: 0x8, DWARF: 0xEC741
    XYZF sce; // Offset: 0x0, DWARF: 0xEC51A
    unsigned long ul; // Offset: 0x0, DWARF: 0xEC53C
} XYZF_Ul;

// Size: 0x40, DWARF: 0x154AEF
typedef struct Poly3
{
    // Size: 0x10, DWARF: 0xEBA4A
    GifTag giftag; // Offset: 0x0, DWARF: 0xEAB15
    // Size: 0x8, DWARF: 0xEC052
    Prim_Ul prim; // Offset: 0x10, DWARF: 0xEAB3A
    // Size: 0x8, DWARF: 0xEC254
    RGBAQ_Ul rgbaq0; // Offset: 0x18, DWARF: 0xEAB5D
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf0; // Offset: 0x20, DWARF: 0xEAB82
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf1; // Offset: 0x28, DWARF: 0xEABA6
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf2; // Offset: 0x30, DWARF: 0xEABCA
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf3; // Offset: 0x38, DWARF: 0xEABEE
} Poly3;

// Size: 0x8, DWARF: 0x156F05
typedef struct sceGsAlpha
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0xFB774, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0xFB79C, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0xFB7C4, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0xFB7EC, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0xFB814, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0xFB83F, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0xFB869, Bit Offset: 40, Bit Size: 24
} sceGsAlpha;

// Size: 0x8, DWARF: 0x15580F
typedef union Alpha
{
    // Size: 0x8, DWARF: 0xED96F
    sceGsAlpha sce; // Offset: 0x0, DWARF: 0xECB5F
    unsigned long ul; // Offset: 0x0, DWARF: 0xECB81
} Alpha;

// Size: 0x20, DWARF: 0x155E44
typedef struct Alpha_Tag
{
    // Size: 0x10, DWARF: 0xEBA4A
    GifTag giftag; // Offset: 0x0, DWARF: 0xEBDC8
    // Size: 0x8, DWARF: 0xECB43
    Alpha alpha; // Offset: 0x10, DWARF: 0xEBDED
    signed long reg_addr; // Offset: 0x18, DWARF: 0xEBE11
} Alpha_Tag;

// Size: 0x8, DWARF: 0x155894
typedef struct sceGsTex0
{
    unsigned long TBP0 : 14; // Offset: 0x0, DWARF: 0xF8A65, Bit Offset: 0, Bit Size: 14
    unsigned long TBW : 6; // Offset: 0x0, DWARF: 0xF8A90, Bit Offset: 14, Bit Size: 6
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0xF8ABA, Bit Offset: 20, Bit Size: 6
    unsigned long TW : 4; // Offset: 0x0, DWARF: 0xF8AE4, Bit Offset: 26, Bit Size: 4
    unsigned long TH : 4; // Offset: 0x0, DWARF: 0xF8B0D, Bit Offset: 30, Bit Size: 4
    unsigned long TCC : 1; // Offset: 0x0, DWARF: 0xF8B36, Bit Offset: 34, Bit Size: 1
    unsigned long TFX : 2; // Offset: 0x0, DWARF: 0xF8B60, Bit Offset: 35, Bit Size: 2
    unsigned long CBP : 14; // Offset: 0x0, DWARF: 0xF8B8A, Bit Offset: 37, Bit Size: 14
    unsigned long CPSM : 4; // Offset: 0x0, DWARF: 0xF8BB4, Bit Offset: 51, Bit Size: 4
    unsigned long CSM : 1; // Offset: 0x0, DWARF: 0xF8BDF, Bit Offset: 55, Bit Size: 1
    unsigned long CSA : 5; // Offset: 0x0, DWARF: 0xF8C09, Bit Offset: 56, Bit Size: 5
    unsigned long CLD : 3; // Offset: 0x0, DWARF: 0xF8C33, Bit Offset: 61, Bit Size: 3
} sceGsTex0;

// Size: 0x8, DWARF: 0x1555D0
typedef union Tex_Ul
{
    // Size: 0x8, DWARF: 0xEBE3A
    sceGsTex0 sce; // Offset: 0x0, DWARF: 0xEC912
    unsigned long ul; // Offset: 0x0, DWARF: 0xEC934
} Tex_Ul;

// Size: 0x8, DWARF: 0x1545F0
typedef struct scest
{
    float S; // Offset: 0x0, DWARF: 0xEE548
    float T; // Offset: 0x4, DWARF: 0xEE566
} scest;

// Size: 0x8, DWARF: 0x154E4B
typedef struct sceuv
{
    unsigned long U : 14; // Offset: 0x0, DWARF: 0xEAD1F, Bit Offset: 0, Bit Size: 14
    unsigned long pad14 : 2; // Offset: 0x0, DWARF: 0xEAD47, Bit Offset: 14, Bit Size: 2
    unsigned long V : 14; // Offset: 0x0, DWARF: 0xEAD73, Bit Offset: 16, Bit Size: 14
    unsigned long pad30 : 34; // Offset: 0x0, DWARF: 0xEAD9B, Bit Offset: 30, Bit Size: 34
} sceuv;

// Size: 0x8, DWARF: 0x154F37
typedef union STUV
{
    // Size: 0x8, DWARF: 0xEE52C
    scest scest; // Offset: 0x0, DWARF: 0xEC843
    // Size: 0x8, DWARF: 0xEAD04
    sceuv sceuv; // Offset: 0x0, DWARF: 0xEC867
    unsigned long ul; // Offset: 0x0, DWARF: 0xEC88B
} STUV;

// Size: 0x80, DWARF: 0x154C0C
typedef struct Poly6
{
    // Size: 0x10, DWARF: 0x1541DE
    GifTag sceGifTag; // Offset: 0x0, DWARF: 0x154C28
    // Size: 0x8, DWARF: 0x15464B
    Prim_Ul prim; // Offset: 0x10, DWARF: 0x154C4D
    // Size: 0x8, DWARF: 0x1555D0
    Tex_Ul tex0; // Offset: 0x18, DWARF: 0x154C70
    // Size: 0x8, DWARF: 0x154F37
    STUV stuv0; // Offset: 0x20, DWARF: 0x154C93
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq0; // Offset: 0x28, DWARF: 0x154CB7
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf0; // Offset: 0x30, DWARF: 0x154CDC
    // Size: 0x8, DWARF: 0x154F37
    STUV stuv1; // Offset: 0x38, DWARF: 0x154D00
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq1; // Offset: 0x40, DWARF: 0x154D24
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf1; // Offset: 0x48, DWARF: 0x154D49
    // Size: 0x8, DWARF: 0x154F37
    STUV stuv2; // Offset: 0x50, DWARF: 0x154D6D
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq2; // Offset: 0x58, DWARF: 0x154D91
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf2; // Offset: 0x60, DWARF: 0x154DB6
    // Size: 0x8, DWARF: 0x154F37
    STUV stuv3; // Offset: 0x68, DWARF: 0x154DDA
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq3; // Offset: 0x70, DWARF: 0x154DFE
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf3; // Offset: 0x78, DWARF: 0x154E23
} Poly6;

// Size: 0x70, DWARF: 0x154401
typedef struct Poly4
{
    // Size: 0x10, DWARF: 0xEBA4A
    GifTag giftag; // Offset: 0x0, DWARF: 0xEBAED
    // Size: 0x8, DWARF: 0xEC052
    Prim_Ul prim; // Offset: 0x10, DWARF: 0xEBB12
    // Size: 0x8, DWARF: 0xEC8F6
    Tex_Ul tex0; // Offset: 0x18, DWARF: 0xEBB35
    // Size: 0x8, DWARF: 0xEC254
    RGBAQ_Ul rgbaq0; // Offset: 0x20, DWARF: 0xEBB58
    // Size: 0x8, DWARF: 0xEC827
    STUV stuv0; // Offset: 0x28, DWARF: 0xEBB7D
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf0; // Offset: 0x30, DWARF: 0xEBBA1
    // Size: 0x8, DWARF: 0xEC827
    STUV stuv1; // Offset: 0x38, DWARF: 0xEBBC5
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf1; // Offset: 0x40, DWARF: 0xEBBE9
    // Size: 0x8, DWARF: 0xEC827
    STUV stuv2; // Offset: 0x48, DWARF: 0xEBC0D
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf2; // Offset: 0x50, DWARF: 0xEBC31
    // Size: 0x8, DWARF: 0xEC827
    STUV stuv3; // Offset: 0x58, DWARF: 0xEBC55
    // Size: 0x8, DWARF: 0xEC4FE
    XYZF_Ul xyzf3; // Offset: 0x60, DWARF: 0xEBC79
    unsigned long nop; // Offset: 0x68, DWARF: 0xEBC9D
} Poly4;

// Size: 0x10, DWARF: 0x157310
typedef struct Pack
{
    float left; // Offset: 0x0, DWARF: 0x15732C
    float right; // Offset: 0x4, DWARF: 0x15734D
    signed int res[2]; // Offset: 0x8, DWARF: 0x15736F
} Pack;

// Size: 0x60, DWARF: 0x157395
typedef struct Poly5
{
    // Size: 0x10, DWARF: 0x1541DE
    GifTag sceGifTag; // Offset: 0x0, DWARF: 0x1573B1
    // Size: 0x8, DWARF: 0x15464B
    Prim_Ul prim; // Offset: 0x10, DWARF: 0x1573D6
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq0; // Offset: 0x18, DWARF: 0x1573F9
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf0; // Offset: 0x20, DWARF: 0x15741E
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq1; // Offset: 0x28, DWARF: 0x157442
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf1; // Offset: 0x30, DWARF: 0x157467
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq2; // Offset: 0x38, DWARF: 0x15748B
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf2; // Offset: 0x40, DWARF: 0x1574B0
    // Size: 0x8, DWARF: 0x15480A
    RGBAQ_Ul rgbaq3; // Offset: 0x48, DWARF: 0x1574D4
    // Size: 0x8, DWARF: 0x154A1E
    RGBAQ_Ul xyzf3; // Offset: 0x50, DWARF: 0x1574F9
    unsigned long nop; // Offset: 0x58, DWARF: 0x15751D
} Poly5;


//// Variables ///////////////////////////////////////////////////////////////////////

extern signed int vsppScrHeight; // Address: 0x2E7708
extern signed int vsppScrWidth; // Address: 0x2E7704
static float vnmdrawScrRate[4]; // Address: 0x3C6A30
static float vnmdrawScrSize[4]; // Address: 0x3C6A40

//// Function Declarations ///////////////////////////////////////////////////////////

void nmdrawFade(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x20, DWARF: 0x155AF9
Fade* info);
void nmdrawKeyOperate(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x40, DWARF: 0x1571B6
Key* info);
void nmdrawBar(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x70, DWARF: 0x15571F
DispBar* info);
void nmdrawTime(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x60, DWARF: 0x1546D1
Time* info);
void nmdrawPoint(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x70, DWARF: 0x153FE5
Point* info);
float nmdrawGetPointLen(// Size: 0x70, DWARF: 0x153FE5
Point* info);
void nmdrawCheck(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x30, DWARF: 0x154135
Check* info);
void nmdrawAllow(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x30, DWARF: 0x155631
Allow* info);
void nmdrawBalance2(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x40, DWARF: 0x155BDD
DispBalance* info);
void nmdrawMeter(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x50, DWARF: 0x155ED2
Meter* info);
void nmdrawIceFont(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, char* str, // Size: 0x70, DWARF: 0x155CEA
Ice* info);
void nmdrawDual(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x30, DWARF: 0x1567F6
Dual* info);
void nmdrawInit();
void nmdrawFLineStrip(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x90, DWARF: 0x154992
Poly* info);
void nmdrawFPoly(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x90, DWARF: 0x1562BF
Poly* info);
void nmdrawGPoly(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x90, DWARF: 0x1562BF
Poly* info);
void nmdrawFTex(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0xB0, DWARF: 0x15608F
DispTex* info);
void nmdrawSwitchTest(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, signed int flag);
static void nmdrawSwitchBil(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, signed int flag);
static void nmdrawChangeVertex(float* vertex);
static void nmdrawInitLSF4(// Size: 0x40, DWARF: 0x154AEF
Poly3* pkt, signed int ctext);

// Additional function includes
Pack nmfontGetPackOfs(signed int rank, signed int file, signed int type);
void sceVu0FTOI4Vector(sceVu0IVECTOR vec, sceVu0FVECTOR vec2);
void nmfontChangeVertex(float* vertex);
unsigned long ultexGetTEX0(Tex* data);
__int128* ulgifAddCNTReserve(VgmsysGifPkt* pkt, signed int qwc);
void ulpktInitALPHA(Alpha_Tag* pkt, signed int ctext);
void nmfontSwitchBil(VgmsysGifPkt* packet, signed int flag);
void nmfontFPrintF(VgmsysGifPkt* packet, char* str, float* pos);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);
void nmfontSetBil(signed int flag);
void nmfontSetCol(signed int* col);
void nmfontSetFCol(signed int r, signed int g, signed int b, signed int a);
void nmfontSetScrRate(signed int type);
void nmfontSetSize(signed int width, signed int height);
void nmfontSetType(signed int type);
void ulpktInitF4(void* pkt, signed int ctext);
void ulpktInitFT4(void* pkt, signed int ctext, signed int fst);
void ulpktInitG4(void* pkt, signed int ctext);
void ulpktInitGT4(void* pkt, signed int ctext, signed int fst);
signed int ulstdSprintf(char* buf, char* fmt, ...);
void sceVu0ApplyMatrix(sceVu0FVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1);
void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR tv);
unsigned int strlen(const char* s);
void nmfontInitOption(void);
void nmfontSetPack(signed int flag);
float nmfontGetStrFLen(char* str, float width);
float nmfontGetPackStrFLen(char* str, float width, signed int type);

//// Function Definitions ////////////////////////////////////////////////////////////

// DWARF: 0x157AB6
// Address: 0x20ECC0
// Size: 0x134
// void nmdrawFade(// Size: 0x10, DWARF: 0x15488E
void nmdrawFade(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x20, DWARF: 0x155AF9
Fade* info) {
    // Size: 0x90, DWARF: 0x1562BF
    Poly poly; // 0x10(r29)

    poly.vertex[0][0] = 0.0f;
    poly.vertex[0][1] = 0.0f;
    poly.vertex[0][2] = 1.0f;
    if (info->col == 0) {
        poly.col[0][0] = 0xFF;
        poly.col[0][1] = 0xFF;
        poly.col[0][2] = 0xFF;
    } else {
        poly.col[0][0] = 0;
        poly.col[0][1] = 0;
        poly.col[0][2] = 0;
    }
    if (info->flag == 0) {
        poly.col[0][3] = 0x80 - (info->cnt << 7) / info->max;
    } else {
        poly.col[0][3] = (info->cnt << 7) / info->max;
    }
    poly.option.sprite = 1;
    poly.option.width = 640.0f;
    poly.option.height = 448.0f;
    nmdrawFPoly(packet, &poly);
}

// DWARF: 0x157BF1
// Address: 0x20EE00
// Size: 0x804
void nmdrawKeyOperate(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x40, DWARF: 0x1571B6
Key* info) {
    s128 temp_v1;
    s128* var_a1;
    s128* var_v0;
    s32 temp_a1;
    s32 temp_a2;
    s32 var_a0;
    u8 temp_a0;
    u8 temp_v0_10;
    u8 temp_v0_5;
    u8 temp_v0_6;
    u8 temp_v0_7;
    u8 temp_v0_8;
    u8 temp_v0_9;

    char str_tmp[256]; // 0x50(r29)
    float pos_tmp[4]; // 0x150(r29)
    // Size: 0xB0, DWARF: 0x15608F
    DispTex tex; // 0x160(r29)
    char button_tsize[10][2] = {
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x30},
        {0x30, 0x20},
    }; // 0x210(r29) // @45
    s32* button_tsize_ptr = &button_tsize;
    char button_tuv[10][2] = {
        {0x00, 0x00},
        {0x20, 0x00},
        {0x00, 0x20},
        {0x20, 0x20},
        {0x40, 0x00},
        {0x60, 0x00},
        {0x40, 0x20},
        {0x60, 0x20},
        {0x00, 0x40},
        {0x20, 0x40}
    }; // 0x230(r29) // @46
    s32* button_tuv_ptr = &button_tuv;
    char button_size[10][2] = {
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x20},
        {0x20, 0x30},
        {0x30, 0x20},
    }; // 0x250(r29) // @47
    s32* button_size_ptr = &button_size;
    char* message_lst[3][10] = {
        {
            "ACCEPT" /*@48*/,
            "CONTINUE"  /*@49*/,
            "SELECT" /*@50*/,
            "CHANGE" /*@51*/,
            "BACK" /*@52*/,
            "SCROLL" /*@53*/,
            "ZOOM" /*@54*/,
            "PLAY SPEED" /*@55*/,
            "PRESS" /*@56*/,
            "TO PLAY" /*@57*/
        },
        {
            "OK" /*@58*/,
            "WEITER"  /*@59*/,
            "W\x90HLEN" /*@60*/,
            "\x90NDERN" /*@61*/,
            "ZUR\x94""CK" /*@62*/,
            "SCROLL" /*@53*/,
            "ZOOM" /*@54*/,
            "SPIELTEMPO" /*@63*/,
            "" /*@64*/,
            "ZUM START DR\x94""CKEN" /*@65*/,
        },
        {
            "ACCEPTER" /*@66*/,
            "CONTINUER" /*@67*/,
            "SELECTIONNER" /*@68*/,
            "MODIFIER"  /*@69*/,
            "RETOUR" /*@70*/,
            "SCROLL" /*@53*/,
            "ZOOM" /*@54*/,
            "VITESSE DE LECTURE" /*@71*/,
            "APPUIE SUR" /*@72*/,
            "POUR COMMENCER" /*@73*/,
        }
    }; // 0x270(r29) // @74
    s32* message_lst_ptr = &message_lst;
    float tmp; // 0x2EC(r29)
    tex.data = info->data;
    tex.tex_size[0] = button_tsize[info->button][0];
    tex.tex_size[1] = button_tsize[info->button][1];
    tex.tex_uv[0] = button_tuv[info->button][0];
    tex.tex_uv[1] = button_tuv[info->button][1];
    tex.col[0][0] = 0x80;
    tex.col[0][1] = 0x80;
    tex.col[0][2] = 0x80;
    if (info->mode == 0) {
        tex.col[0][3] = ((info->cnt << 7) / 5);
    } else {
        tex.col[0][3] = 0x80 - ((info->cnt << 7) / 5);
    }
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = button_size[info->button][0];
    tex.option.height = button_size[info->button][1];
    nmfontInitOption();
    nmfontSetSize(0xC, 0x14);
    nmfontSetPack(1);
    nmfontSetShadow(1);
    nmfontSetBil(1);
    nmfontSetCol(&tex.col[0][0]);
    nmfontSetScrRate(1);
    switch (info->message) {
    case 8:
        ulstdSprintf(str_tmp, " %s %s", message_lst[info->language][info->message], message_lst[info->language][info->message + 1]);
        if (info->center == 1) {
            tmp = button_size[info->button][0] + (f32)nmfontGetPackStrLen(str_tmp, 0xC, 0);
            pos_tmp[0] = info->pos[0] - (tmp / 2.0f);
        } else {
            pos_tmp[0] = info->pos[0];
        }
        pos_tmp[1] = info->pos[1] - 10.0f;
        ulstdSprintf(str_tmp, "%s ", message_lst[info->language][info->message]);
        tmp = nmfontGetPackStrLen(str_tmp, 0xC, 0);
        nmfontFPrintF(packet, str_tmp, pos_tmp);
        tex.vertex[0][0] = pos_tmp[0] + tmp;
        tex.vertex[0][1] = info->pos[1] - (button_size[info->button][1] / 2.0f);
        nmdrawFTex(packet, &tex);
        pos_tmp[0] = tex.vertex[0][0] + button_size[info->button][0];
        pos_tmp[1] = info->pos[1] - 10.0f;
        ulstdSprintf(str_tmp, " %s", message_lst[info->language][info->message + 1]);
        nmfontFPrintF(packet, str_tmp, pos_tmp);
        break;
    default:
        ulstdSprintf(str_tmp, " %s", message_lst[info->language][info->message]);
        if (info->center == 1) {
            tmp = button_size[info->button][0] + (f32)nmfontGetPackStrLen(str_tmp, 0xC, 0);
            pos_tmp[0] = info->pos[0] - (tmp / 2.0f);
        } else {
            pos_tmp[0] = info->pos[0];
        }
        tex.vertex[0][0] = pos_tmp[0];
        tex.vertex[0][1] = info->pos[1] - (button_size[info->button][1] / 2.0f);
        nmdrawFTex(packet, &tex);
        pos_tmp[0] += tex.option.width;
        pos_tmp[1] = info->pos[1] - 10.0f;
        nmfontFPrintF(packet, str_tmp, pos_tmp);
        break;
    }
}

// DWARF: 0x157EA8
// Address: 0x20F610
// Size: 0x3B8
void nmdrawBar(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x70, DWARF: 0x15571F
DispBar* info) {
    signed int i; // r16
    // Size: 0x90, DWARF: 0x1562BF
    Poly poly; // 0x20(r29)

    switch (info->type) {
    case 0:
        poly.vertex[0][0] = info->pos[0];
        poly.vertex[0][1] = info->pos[1] / 2.0f;
        poly.vertex[1][0] = info->pos[0] + info->option.width;
        poly.vertex[1][1] = info->pos[1] / 2.0f;
        poly.vertex[2][0] = info->pos[0];
        poly.vertex[2][1] = (info->pos[1] + info->option.height) / 2.0f;
        poly.vertex[3][0] = info->pos[0] + info->option.width;
        poly.vertex[3][1] = (info->pos[1] + info->option.height) / 2.0f;
        break;
    case 1:
        poly.vertex[0][0] = info->pos[0];
        poly.vertex[0][1] = info->pos[1] / 2.0f;
        poly.vertex[1][0] = info->pos[0] + info->option.width;
        poly.vertex[1][1] = info->pos[1] / 2.0f;
        poly.vertex[2][0] = info->pos[0] - (info->option.height / 2.0f);
        poly.vertex[2][1] = (info->pos[1] + info->option.height) / 2.0f;
        poly.vertex[3][0] = info->pos[0] + (info->option.width - (info->option.height / 2.0f));
        poly.vertex[3][1] = (info->pos[1] + info->option.height) / 2.0f;
        break;
    case 2:
        poly.vertex[0][0] = info->pos[0];
        poly.vertex[0][1] = info->pos[1] / 2.0f;
        poly.vertex[1][0] = info->pos[0] + info->option.width;
        poly.vertex[1][1] = info->pos[1] / 2.0f;
        poly.vertex[2][0] = info->pos[0];
        poly.vertex[2][1] = (info->pos[1] + info->option.height) / 2.0f;
        poly.vertex[3][0] = info->pos[0] + (info->option.width + (info->option.height / 2.0f));
        poly.vertex[3][1] = (info->pos[1] + info->option.height) / 2.0f;
        break;
    }
    poly.option.sprite = 0;
    for (i = 0; i < 4; i++) {
        poly.col[i][0] = info->col[i][0];
        poly.col[i][1] = info->col[i][1];
        poly.col[i][2] = info->col[i][2];
        poly.col[i][3] = info->col[i][3];
    }
    nmdrawGPoly(packet, &poly);
}

// DWARF: 0x15800F
// Address: 0x20F9D0
// Size: 0x194
void nmdrawTime(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x60, DWARF: 0x1546D1
Time* info) {
    signed int min; // r16
    signed int sec; // r17
    signed int rest; // r18
    char str_tmp[256]; // 0x40(r29)

    nmfontInitOption();
    nmfontSetShadow(1);
    nmfontSetBil(1);
    nmfontSetType(info->type);
    nmfontSetSize(info->size[0], info->size[1]);
    nmfontSetCol(info->col);
    nmfontSetScrRate(1);
    if (info->frame < 0) {
        ulstdSprintf(&str_tmp, " -'--\"---");
    } else {
        min = (info->frame / 60000);
        if (0x63 < min) {
            min = 0x63;
        }
        sec = ((info->frame % 60000) / 1000);
        rest = info->frame % 1000;
        ulstdSprintf(&str_tmp, "%2d'%02d\"%03d", min, sec, rest);
    }
    nmfontGPrintF(packet, &str_tmp, info);
}

// DWARF: 0x1581DB
// Address: 0x20FB70
// Size: 0xDD8
void nmdrawPoint(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x70, DWARF: 0x153FE5
Point* info) {
    signed int million; // r16
    signed int thousand; // r17
    signed int rest; // r18
    char str_tmp[256]; // 0x50(r29)
    float pos_tmp[4]; // 0x150(r29)
    char* word_tbl[3] = {
        ",", ",", ","
    }; // 0x160(r29) // @137
    s32* word_tbl_ptr = &word_tbl;
    float tmp; // 0x16C(r29)

    nmfontInitOption();
    nmfontSetBil(1);
    nmfontSetType(info->type);
    nmfontSetSize(info->size[0], info->size[1]);
    if (info->flat == 1) {
        nmfontSetFCol(info->col[0][0], info->col[0][1], info->col[0][2], info->col[0][3]);
    } else {
        nmfontSetCol(info->col);
    }
    nmfontSetScrRate(1);
    sceVu0CopyVector(pos_tmp, info->pos);
    million = info->point / 1000000;
    thousand = (info->point % 1000000) / 1000;
    rest = (info->point % 1000000) % 1000;

    switch (info->base) {
    case 0:
        if (million > 0) {
            nmfontSetPack(0);
            ulstdSprintf(&str_tmp, "%d", million);
            tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
            nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            pos_tmp[0] += tmp;
            nmfontSetPack(1);
            ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);
            tmp = nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            pos_tmp[0] += tmp;
        }
        if ((million > 0) || (thousand > 0)) {
            nmfontSetPack(0);
            if (million > 0) {
                ulstdSprintf(&str_tmp, "%03d", thousand);
            } else {
                ulstdSprintf(&str_tmp, "%d", thousand);
            }

            tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            pos_tmp[0] += tmp;
            nmfontSetPack(1);
            ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);
            tmp = nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            pos_tmp[0] += tmp;
        }
        nmfontSetPack(0);
        if ((million > 0) || (thousand > 0)) {
            ulstdSprintf(&str_tmp, "%03d", rest);
        } else {
            ulstdSprintf(&str_tmp, "%d", rest);
        }

        tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
        if (info->flat == 1) {
            nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            return;
        }
        nmfontGPrintF(packet, &str_tmp, &pos_tmp);
        return;
    case 1:
        nmfontSetPack(0);
        if ((million > 0) || (thousand > 0)) {
            ulstdSprintf(&str_tmp, "%03d", rest);
        } else {
            ulstdSprintf(&str_tmp, "%d", rest);
        }

        tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
        pos_tmp[0] -= tmp;
        if (info->flat == 1) {
            nmfontFPrintF(packet, &str_tmp, &pos_tmp);
        } else {
            nmfontGPrintF(packet, &str_tmp, &pos_tmp);
        }
        if ((million > 0) || (thousand > 0)) {
            nmfontSetPack(1);
            ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);
            tmp = nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);
            pos_tmp[0] -= tmp;
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            nmfontSetPack(0);
            if (million > 0) {
                ulstdSprintf(&str_tmp, "%03d", thousand);
            } else {
                ulstdSprintf(&str_tmp, "%d", thousand);
            }

            tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
            pos_tmp[0] -= tmp;
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
        }
        if (million > 0) {
            nmfontSetPack(1);
            ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);
            tmp = nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);

            pos_tmp[0] -= tmp;
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            nmfontSetPack(0);
            ulstdSprintf(&str_tmp, "%d", million);
            tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);

            pos_tmp[0] -= tmp;
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
                return;
            }
            nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            return;
        }
        break;
    case 2:
        tmp = nmdrawGetPointLen(info);
        pos_tmp[0] -= tmp / 2.0f;
        if (million > 0) {
            nmfontSetPack(0);
            ulstdSprintf(&str_tmp, "%d", million);
            tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            pos_tmp[0] += tmp;
            nmfontSetPack(1);
            ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);

            tmp = nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            pos_tmp[0] += tmp;
        }
        if (million > 0 || thousand > 0) {
            nmfontSetPack(0);
            if (million > 0) {
                ulstdSprintf(&str_tmp, "%03d", thousand);
            } else {
                ulstdSprintf(&str_tmp, "%d", thousand);
            }
            tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            pos_tmp[0] += tmp;
            nmfontSetPack(1);
            ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);

            tmp = nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);
            if (info->flat == 1) {
                nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            } else {
                nmfontGPrintF(packet, &str_tmp, &pos_tmp);
            }
            pos_tmp[0] += tmp;
        }
        nmfontSetPack(0);
        if ((million > 0) || (thousand > 0)) {
            ulstdSprintf(&str_tmp, "%03d", rest);
        } else {
            ulstdSprintf(&str_tmp, "%d", rest);
        }
        tmp = nmfontGetStrFLen(&str_tmp, info->size[0]);
        if (info->flat == 1) {
            nmfontFPrintF(packet, &str_tmp, &pos_tmp);
            return;
        }
        nmfontGPrintF(packet, &str_tmp, &pos_tmp);
        break;
    }
}

// DWARF: 0x15843D
// Address: 0x210950
// Size: 0x308
f32 nmdrawGetPointLen(// Size: 0x70, DWARF: 0x153FE5
Point* info) {
    signed int million; // r16
    signed int thousand; // r17
    signed int rest; // r18
    char str_tmp[256]; // 0x50(r29)
    char* word_tbl[3] = {
        ",", ",", ","
    }; // 0x150(r29) // @232
    s32* word_tbl_ptr = &word_tbl;
    float length; // 0x15C(r29)

    length = 0.0f;
    million = (info->point / 1000000);
    thousand = (info->point % 1000000) / 1000;
    rest = (info->point % 1000000) % 1000;
    if (million > 0) {
        ulstdSprintf(&str_tmp, "%d", million);
        length += nmfontGetStrFLen(&str_tmp, info->size[0]);
        ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);
        length += nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);
    }
    if (million > 0 || thousand > 0) {
        if (million > 0) {
            ulstdSprintf(&str_tmp, "%03d", thousand);
        } else {
            ulstdSprintf(&str_tmp, "%d", thousand);
        }
        length += nmfontGetStrFLen(&str_tmp, info->size[0]);
        ulstdSprintf(&str_tmp, "%s", word_tbl[info->language]);
        length += nmfontGetPackStrFLen(&str_tmp, info->size[0], info->type);
    }
    if (million > 0 || thousand > 0) {
        ulstdSprintf(&str_tmp, "%03d", rest);
    } else {
        ulstdSprintf(&str_tmp, "%d", rest);
    }
    length = length + nmfontGetStrFLen(&str_tmp, info->size[0]);
    return length;
}

// DWARF: 0x158650
// Address: 0x210C60
// Size: 0x140
void nmdrawCheck(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x30, DWARF: 0x154135
Check* info) {
    // Size: 0xB0, DWARF: 0x15608F
    DispTex tex; // 0x20(r29)
    char size_tbl[6] = {
        '\f', 0x11, 0x16, 0x1B, ' ', ' '
    }; // 0xD8(r29) // @250
    s32* size_tbl_ptr = &size_tbl;

    tex.data = info->data;
    tex.tex_size[0] = size_tbl[info->cnt];
    tex.tex_size[1] = 0x20;
    tex.tex_uv[0] = 0x20;
    tex.tex_uv[1] = 0x60;
    tex.col[0][0] = 0x80;
    tex.col[0][1] = 0x80;
    tex.col[0][2] = 0x80;
    tex.col[0][3] = 0x80;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = size_tbl[info->cnt];
    tex.option.height = 32.0f;
    tex.vertex[0][0] = info->pos[0];
    tex.vertex[0][1] = info->pos[1] - 16.0f;
    nmdrawFTex(packet, &tex);
}

// DWARF: 0x1587C7
// Address: 0x210DA0
// Size: 0x100
void nmdrawAllow(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x30, DWARF: 0x155631
Allow* info) {
    // Size: 0xB0, DWARF: 0x15608F
    DispTex tex; // 0x20(r29)
    char uv_tbl[4][2] = {
        {0x00, 0x00},
        {0x20, 0x00},
        {0x00, 0x20},
        {0x20, 0x20}
    }; // 0xD8(r29) // @258
    s32* uv_tbl_ptr = &uv_tbl;

    tex.data = info->data;
    tex.tex_size[0] = 0x20;
    tex.tex_size[1] = 0x20;
    tex.tex_uv[0] = uv_tbl[info->type][0];
    tex.tex_uv[1] = uv_tbl[info->type][1];
    tex.col[0][0] = 0x80;
    tex.col[0][1] = 0x80;
    tex.col[0][2] = 0x80;
    tex.col[0][3] = info->abe;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = info->width;
    tex.option.height = info->height;
    tex.vertex[0][0] = info->pos[0];
    tex.vertex[0][1] = info->pos[1];
    nmdrawFTex(packet, &tex);
}

// DWARF: 0x15893C
// Address: 0x210EA0
// Size: 0xCB4
void nmdrawBalance2(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x40, DWARF: 0x155BDD
DispBalance* info) {
    signed int i; // r16
    float meter_ver[4][4]; // 0x50(r29)
    float allow_ver[4][4]; // 0x90(r29)
    signed int tex_uv[3][2] = {
        {0x00, 0x00},
        {0x00, 0x40},
        {0x00, 0x80}
    }; // 0xD0(r29) // @308
    s32* tex_uv_ptr = &tex_uv;
    signed int tex_size[2][2] = {
        {0x100, 0x040},
        {0x020, 0x020}
    }; // 0xF0(r29) // @309
    s32* tex_size_ptr = &tex_size;
    float size[2][2] = {
        {256.0f, 64.0f},
        {32.0f, 32.0f}
    }; // 0x100(r29) // @310
    s32* size_ptr = &size;
    // Size: 0xB0, DWARF: 0x15608F
    DispTex tex; // 0x110(r29)
    float mat_tmp[4][4]; // 0x1C0(r29)
    float trans[4]; // 0x200(r29)
    float rot[4]; // 0x210(r29)
    float ofs; // 0x22C(r29)

    ofs = (3.0f * info->ratio[0]) / 4.0f;
    sceVu0UnitMatrix(mat_tmp);
    trans[0] = 0.0f;
    trans[1] = 0.0f;
    trans[2] = 0.0f;
    trans[3] = 1.0f;
    sceVu0TransMatrix(mat_tmp, mat_tmp, &trans[0]);
    if (info->type == 0) {
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = -1.57463f;
        rot[3] = 1.0f;
        sceVu0RotMatrixX(mat_tmp, mat_tmp, rot[0]);
        sceVu0RotMatrixY(mat_tmp, mat_tmp, rot[1]);
        sceVu0RotMatrixZ(mat_tmp, mat_tmp, rot[2]);
    }
    tex.data = info->data;
    tex.option.sprite = 0;
    tex.option.bil = 1;
    tex.option.width = size[0][0] * ofs;
    tex.option.height = size[0][1] * ofs;
    tex.tex_size[0] = tex_size[0][0] / 2.0f;
    tex.tex_size[1] = tex_size[0][1];
    if (info->per < 0.0f) {
        tex.col[0][0] = (int)(64.0f * -info->per) + 64;
        tex.col[0][1] = 0x80 - (int)(64.0f * -info->per);
    } else {
        tex.col[0][0] = (int)(64.0f * info->per) + 64;
        tex.col[0][1] = 0x80 - (int)(64.0f * info->per);
    }
    tex.col[0][2] = 0x40;
    tex.col[0][3] = (info->abe * 3) / 4;
    tex.tex_uv[0] = tex_uv[1][0];
    tex.tex_uv[1] = tex_uv[1][1];
    meter_ver[0][0] = -tex.option.width / 2.0f;
    meter_ver[0][1] = -tex.option.height / 2.0f;
    meter_ver[0][2] = 0.0f;
    meter_ver[0][3] = 1.0f;
    meter_ver[1][0] = 0.0f;
    meter_ver[1][1] = -tex.option.height / 2.0f;
    meter_ver[1][2] = 0.0f;
    meter_ver[1][3] = 1.0f;
    meter_ver[2][0] = -tex.option.width / 2.0f;
    meter_ver[2][1] = tex.option.height / 2.0f;
    meter_ver[2][2] = 0.0f;
    meter_ver[2][3] = 1.0f;
    meter_ver[3][0] = 0.0f;
    meter_ver[3][1] = tex.option.height / 2.0f;
    meter_ver[3][2] = 0.0f;
    meter_ver[3][3] = 1.0f;
    for (i = 0; i < 4; i++) {
        sceVu0ApplyMatrix(tex.vertex[i], mat_tmp, meter_ver[i]);
        tex.vertex[i][0] += info->pos[0];
        tex.vertex[i][1] += info->pos[1];
    }
    nmdrawFTex(packet, &tex);
    tex.tex_uv[0] = tex_uv[1][0] + tex.tex_size[0];
    tex.tex_uv[1] = tex_uv[1][1];
    meter_ver[0][0] = 0.0f;
    meter_ver[0][1] = -tex.option.height / 2.0f;
    meter_ver[0][2] = 0.0f;
    meter_ver[0][3] = 1.0f;
    meter_ver[1][0] = tex.option.width / 2.0f;
    meter_ver[1][1] = -tex.option.height / 2.0f;
    meter_ver[1][2] = 0.0f;
    meter_ver[1][3] = 1.0f;
    meter_ver[2][0] = 0.0f;
    meter_ver[2][1] = tex.option.height / 2.0f;
    meter_ver[2][2] = 0.0f;
    meter_ver[2][3] = 1.0f;
    meter_ver[3][0] = tex.option.width / 2.0f;
    meter_ver[3][1] = tex.option.height / 2.0f;
    meter_ver[3][2] = 0.0f;
    meter_ver[3][3] = 1.0f;
    for (i = 0; i < 4; i++) {
        sceVu0ApplyMatrix(tex.vertex[i], mat_tmp, meter_ver[i]);
        tex.vertex[i][0] += info->pos[0];
        tex.vertex[i][1] += info->pos[1];
    }
    nmdrawFTex(packet, &tex);
    tex.data = info->data;
    tex.option.sprite = 0;
    tex.option.bil = 1;
    tex.option.width = size[0][0] * ofs;
    tex.option.height = size[0][1] * ofs;
    tex.col[0][0] = 0x20;
    tex.col[0][1] = 0x20;
    tex.col[0][2] = 0x20;
    tex.col[0][3] = info->abe;
    tex.tex_size[0] = tex_size[0][0];
    tex.tex_size[1] = tex_size[0][1];
    tex.tex_uv[0] = tex_uv[0][0];
    tex.tex_uv[1] = tex_uv[0][1];
    meter_ver[0][0] = -tex.option.width / 2.0f;
    meter_ver[0][1] = -tex.option.height / 2.0f;
    meter_ver[0][2] = 0.0f;
    meter_ver[0][3] = 1.0f;
    meter_ver[1][0] = tex.option.width / 2.0f;
    meter_ver[1][1] = -tex.option.height / 2.0f;
    meter_ver[1][2] = 0.0f;
    meter_ver[1][3] = 1.0f;
    meter_ver[2][0] = -tex.option.width / 2.0f;
    meter_ver[2][1] = tex.option.height / 2.0f;
    meter_ver[2][2] = 0.0f;
    meter_ver[2][3] = 1.0f;
    meter_ver[3][0] = tex.option.width / 2.0f;
    meter_ver[3][1] = tex.option.height / 2.0f;
    meter_ver[3][2] = 0.0f;
    meter_ver[3][3] = 1.0f;
    for (i = 0; i < 4; i++) {
        sceVu0ApplyMatrix(tex.vertex[i], mat_tmp, meter_ver[i]);
        tex.vertex[i][0] += info->pos[0];
        tex.vertex[i][1] += info->pos[1];
    }
    nmdrawFTex(packet, &tex);
    sceVu0UnitMatrix(mat_tmp);
    trans[0] = 0.0f;
    trans[1] = -190.0f * ofs;
    trans[2] = 0.0f;
    trans[3] = 1.0f;
    sceVu0TransMatrix(mat_tmp, mat_tmp, &trans[0]);
    if (info->type == 0) {
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = -1.57463f;
        rot[3] = 1.0f;
    } else {
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = 0.0f;
        rot[3] = 1.0f;
    }
    rot[2] += 0.69983554f * info->per;
    sceVu0RotMatrixX(mat_tmp, mat_tmp, rot[0]);
    sceVu0RotMatrixY(mat_tmp, mat_tmp, rot[1]);
    sceVu0RotMatrixZ(mat_tmp, mat_tmp, rot[2]);
    tex.data = info->data;
    tex.option.sprite = 0;
    tex.option.bil = 1;
    tex.option.width = size[1][0] * ofs;
    tex.option.height = size[1][0] * ofs;
    tex.col[0][0] = 0x80;
    tex.col[0][1] = 0x80;
    tex.col[0][2] = 0x80;
    tex.col[0][3] = info->abe;
    tex.tex_size[0] = tex_size[1][0];
    tex.tex_size[1] = tex_size[1][1];
    tex.tex_uv[0] = tex_uv[2][0];
    tex.tex_uv[1] = tex_uv[2][1];
    allow_ver[0][0] = -tex.option.width / 2.0f;
    allow_ver[0][1] = -tex.option.height / 2.0f;
    allow_ver[0][2] = 0.0f;
    allow_ver[0][3] = 1.0f;
    allow_ver[1][0] = tex.option.width / 2.0f;
    allow_ver[1][1] = -tex.option.height / 2.0f;
    allow_ver[1][2] = 0.0f;
    allow_ver[1][3] = 1.0f;
    allow_ver[2][0] = -tex.option.width / 2.0f;
    allow_ver[2][1] = tex.option.height / 2.0f;
    allow_ver[2][2] = 0.0f;
    allow_ver[2][3] = 1.0f;
    allow_ver[3][0] = tex.option.width / 2.0f;
    allow_ver[3][1] = tex.option.height / 2.0f;
    allow_ver[3][2] = 0.0f;
    allow_ver[3][3] = 1.0f;
    for (i = 0; i < 4; i++) {
        sceVu0ApplyMatrix(tex.vertex[i], mat_tmp, allow_ver[i]);
        tex.vertex[i][0] += info->pos[0];
        tex.vertex[i][1] += info->pos[1];
        if (info->type == 0) {
            tex.vertex[i][0] += ((190.0f * ofs) - tex.option.width);
        } else {
            tex.vertex[i][1] += ((190.0f * ofs) - tex.option.height);
        }
    }
    nmdrawFTex(packet, &tex);
}

// DWARF: 0x158C4F
// Address: 0x211B60
// Size: 0x7C8
void nmdrawMeter(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x50, DWARF: 0x155ED2
Meter* info) {
    // Size: 0x90, DWARF: 0x154992
    Poly line; // 0x10(r29)
    // Size: 0x70, DWARF: 0x15571F
    DispBar bar; // 0xA0(r29)

    if (info->frame == 1) {
        if (info->shadow == 1) {
            line.vertex[0][0] = 4.0f + info->pos[0];
            line.vertex[0][1] = 2.0f + (info->pos[1] - 8.0f);
            line.vertex[1][0] = 4.0f + info->pos[0];
            line.vertex[1][1] = 2.0f + info->pos[1];
            line.vertex[2][0] = 4.0f + (16.0f + (info->pos[0] + (96.0f * info->ratio)));
            line.vertex[2][1] = 2.0f + info->pos[1];
            line.vertex[3][0] = 4.0f + (16.0f + (info->pos[0] + (96.0f * info->ratio)));
            line.vertex[3][1] = 2.0f + (info->pos[1] - 8.0f);
            line.col[0][0] = 0;
            line.col[0][1] = 0;
            line.col[0][2] = 0;
            line.col[0][3] = 0x80;
            nmdrawFLineStrip(packet, &line);
        }
        line.vertex[0][0] = info->pos[0];
        line.vertex[0][1] = info->pos[1] - 8.0f;
        line.vertex[1][0] = info->pos[0];
        line.vertex[1][1] = info->pos[1];
        line.vertex[2][0] = 16.0f + (info->pos[0] + (96.0f * info->ratio));
        line.vertex[2][1] = info->pos[1];
        line.vertex[3][0] = 16.0f + (info->pos[0] + (96.0f * info->ratio));
        line.vertex[3][1] = info->pos[1] - 8.0f;
        line.col[0][0] = 0xFF;
        line.col[0][1] = 0xFF;
        line.col[0][2] = 0xFF;
        line.col[0][3] = 0x80;
        nmdrawFLineStrip(packet, &line);
    }
    if (info->per > 0.0f) {
        bar.option.height = 12.0f;
        bar.type = info->type;
        bar.option.width = (96.0f * info->ratio * info->per) / 100.0f;
        if (info->shadow == 1) {
            bar.pos[0] = 12.0f + info->pos[0];
            bar.pos[1] = 2.0f + (info->pos[1] - 16.0f);
            bar.col[0][0] = 0;
            bar.col[0][1] = 0;
            bar.col[0][2] = 0;
            bar.col[0][3] = 0x80;
            bar.col[1][0] = 0;
            bar.col[1][1] = 0;
            bar.col[1][2] = 0;
            bar.col[1][3] = 0x80;
            bar.col[2][0] = 0;
            bar.col[2][1] = 0;
            bar.col[2][2] = 0;
            bar.col[2][3] = 0x80;
            bar.col[3][0] = 0;
            bar.col[3][1] = 0;
            bar.col[3][2] = 0;
            bar.col[3][3] = 0x80;
            nmdrawBar(packet, &bar);
        }
        if (info->div == 0) {
            bar.pos[0] = 8.0f + info->pos[0];
            bar.pos[1] = info->pos[1] - 16.0f;
            bar.col[0][0] = info->col[0][0];
            bar.col[0][1] = info->col[0][1];
            bar.col[0][2] = info->col[0][2];
            bar.col[0][3] = info->col[0][3];
            bar.col[1][0] = info->col[1][0];
            bar.col[1][1] = info->col[1][1];
            bar.col[1][2] = info->col[1][2];
            bar.col[1][3] = info->col[1][3];
            bar.col[2][0] = info->col[0][0];
            bar.col[2][1] = info->col[0][1];
            bar.col[2][2] = info->col[0][2];
            bar.col[2][3] = info->col[0][3];
            bar.col[3][0] = info->col[1][0];
            bar.col[3][1] = info->col[1][1];
            bar.col[3][2] = info->col[1][2];
            bar.col[3][3] = info->col[1][3];
            nmdrawBar(packet, &bar);
            return;
        }
        bar.type = 0;
        bar.option.width = info->div_per * (96.0f * info->ratio * (info->per / 100.0f));
        bar.pos[0] = 8.0f + info->pos[0];
        bar.pos[1] = info->pos[1] - 16.0f;
        if (info->div_per > 0.0f) {
            bar.col[0][0] = info->col[0][0];
            bar.col[0][1] = info->col[0][1];
            bar.col[0][2] = info->col[0][2];
            bar.col[0][3] = info->col[0][3];
            bar.col[1][0] = info->col[1][0];
            bar.col[1][1] = info->col[1][1];
            bar.col[1][2] = info->col[1][2];
            bar.col[1][3] = info->col[1][3];
            bar.col[2][0] = info->col[0][0];
            bar.col[2][1] = info->col[0][1];
            bar.col[2][2] = info->col[0][2];
            bar.col[2][3] = info->col[0][3];
            bar.col[3][0] = info->col[1][0];
            bar.col[3][1] = info->col[1][1];
            bar.col[3][2] = info->col[1][2];
            bar.col[3][3] = info->col[1][3];
            nmdrawBar(packet, &bar);
        }
        bar.type = info->type;
        bar.pos[0] = 8.0f + info->pos[0] + bar.option.width;
        if (info->div_per < 1.0f) {
            bar.option.width = (1.0f - info->div_per) * (96.0f * info->ratio * (info->per / 100.0f));
            bar.col[0][0] = info->col[1][0];
            bar.col[0][1] = info->col[1][1];
            bar.col[0][2] = info->col[1][2];
            bar.col[0][3] = info->col[1][3];
            bar.col[1][0] = info->col[0][0];
            bar.col[1][1] = info->col[0][1];
            bar.col[1][2] = info->col[0][2];
            bar.col[1][3] = info->col[0][3];
            bar.col[2][0] = info->col[1][0];
            bar.col[2][1] = info->col[1][1];
            bar.col[2][2] = info->col[1][2];
            bar.col[2][3] = info->col[1][3];
            bar.col[3][0] = info->col[0][0];
            bar.col[3][1] = info->col[0][1];
            bar.col[3][2] = info->col[0][2];
            bar.col[3][3] = info->col[0][3];
            nmdrawBar(packet, &bar);
        }
    }
}

// DWARF: 0x158DB2
// Address: 0x212330
// Size: 0x814
void nmdrawIceFont(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, char* str, // Size: 0x70, DWARF: 0x155CEA
Ice* info) {
    signed int j; // r16 // s0
    // Size: 0x80, DWARF: 0x154C0C
    Poly6* poly; // r17 // s1
    signed int i; // r18 // s2
    signed int rank; // r19 // s3
    signed int file; // r20 // s4
    unsigned int str_len; // r21 // s5
    void* addr; // r22 // s6
    // Size: 0x10, DWARF: 0x154240
    Tex* tex_data; // r23 // s7
    // Size: 0x20, DWARF: 0x155E44
    Alpha_Tag* alpha; // r30 // s8
    float bpos[4][4]; // 0xA0(r29)
    float bpos2[4][4]; // 0xE0(r29)
    signed int ipos[4][4]; // 0x120(r29)
    // Size: 0x10, DWARF: 0x157310
    Pack pack; // 0x160(r29)
    signed int uv[2]; // 0x170(r29)
    float rate; // 0x178(r29)
    signed int qwc; // 0x17C(r29)

    str_len = strlen(str);
    if (str_len) {
        nmfontSwitchBil(packet, 1);
        qwc = ((s32)((str_len * sizeof(Poly6)) + sizeof(Alpha_Tag)) + 0xF) >> 4;
        addr = (void*)ulgifAddCNTReserve(packet, qwc);
        alpha = addr;
        addr = alpha + 1;
        ulpktInitALPHA(alpha, 1);
        tex_data = info->data;
        rate = info->width / 16.0f;
        bpos[0][0] = info->pos[0];
        bpos[0][1] = info->pos[1] / 2.0f;
        bpos[1][0] = info->pos[0] + info->width;
        bpos[1][1] = info->pos[1] / 2.0f;
        bpos[2][0] = info->pos[0];
        bpos[2][1] = (info->pos[1] + info->height) / 2.0f;
        bpos[3][0] = info->pos[0] + info->width;
        bpos[3][1] = (info->pos[1] + info->height) / 2.0f;
        for (i = 0; i < str_len; i++) {
            rank = (str[i] - 0x20) % 16;
            file = (str[i] - 0x20) / 16;
            uv[0] = rank * 0x10;
            uv[1] = file * 0x10;
            if (info->pack == 1) {
                pack = nmfontGetPackOfs(rank, file, 0);
                pack.left *= rate;
                pack.right *= rate;
                for (j = 0; j < 4; j++) {
                    bpos[j][0] -= pack.left;
                }
            } else {
                pack.left = 0.0f;
                pack.right = 0.0f;
            }
            for (j = 0; j < 4; j++) {
                bpos2[j][0] = (f32) bpos[j][0];
                bpos2[j][1] = (f32) bpos[j][1];
                nmfontChangeVertex(bpos2[j]);
                sceVu0FTOI4Vector(ipos[j], bpos2[j]);
                ipos[j][2] = 0xFFFFFF;
            }
            poly = addr;
            addr = poly + 1;
            ulpktInitGT4(poly, 1, 1);
            if (i == (str_len - 1)) {
                poly->sceGifTag.sce.EOP = 1;
            } else {
                poly->sceGifTag.sce.EOP = 0;
            }
            poly->prim.sce.ABE = 1;
            poly->tex0.ul = ultexGetTEX0(tex_data);
            poly->rgbaq0.ul = ((s64)info->col[0][3] << 0x18 | (((s64)info->col[0][2] << 0x10) | ((s64)info->col[0][0] | ((s64)info->col[0][1] << 8))));
            poly->rgbaq1.ul = (((((s64) info->col[1][3])) << 0x18) | ((((s64) ((s64) info->col[1][2])) << 0x10) | (((s64) ((s64) info->col[1][0])) | (((s64) ((s64) info->col[1][1])) << 8))));
            poly->rgbaq2.ul = (((((s64) info->col[2][3])) << 0x18) | ((((s64) ((s64) info->col[2][2])) << 0x10) | (((s64) ((s64) info->col[2][0])) | (((s64) ((s64) info->col[2][1])) << 8))));
            poly->rgbaq3.ul = (((((s64) info->col[3][3])) << 0x18) | ((((s64) ((s64) info->col[3][2])) << 0x10) | (((s64) ((s64) info->col[3][0])) | (((s64) ((s64) info->col[3][1])) << 8))));
            poly->stuv0.ul = (((s64) (((uv[0] * 0x10) + 8))) | (((s64) (((uv[1] * 0x10) + 8))) << 0x10));
            poly->stuv1.ul = (((s64) ((((uv[0] + 0x10) * 0x10) + 8))) | (((s64) (((uv[1] * 0x10) + 8))) << 0x10));
            poly->stuv2.ul = (((((uv[0] * 0x10) + 8))) | (((s64) ((((uv[1] + 0x10) * 0x10) + 8))) << 0x10));
            // poly->stuv3.ul = (((((uv[0] + 0x10) * 0x10) + 8))) | ((((s64) ((uv[1] + 0x10) * 0x10))) + 8) << 0x10));
            poly->stuv3.ul = ((((((uv[0] + 0x10) * 0x10) + 8))) | (((s64) ((((uv[1] + 0x10) * 0x10) + 8))) << 0x10));
            poly->xyzf0.ul = ((s64)ipos[0][2] << 0x20) | ((s64)ipos[0][0] | ((s64)ipos[0][1] << 0x10));
            poly->xyzf1.ul = ((s64)ipos[1][2] << 0x20) | ((s64)ipos[1][0] | ((s64)ipos[1][1] << 0x10));
            poly->xyzf2.ul = ((s64)ipos[2][2] << 0x20) | ((s64)ipos[2][0] | ((s64)ipos[2][1] << 0x10));
            poly->xyzf3.ul = ((s64)ipos[3][2] << 0x20) | ((s64)ipos[3][0] | ((s64)ipos[3][1] << 0x10));
            if (info->pack == 1) {
                for (j = 0; j < 4; j++) {
                    bpos[j][0] += (info->width - pack.right);
                }
            } else {
                for (j = 0; j < 4; j++) {
                    bpos[j][0] += info->width;
                }
            }
        }
        nmfontSwitchBil(packet, 0);
    }
}

// DWARF: 0x1591C6
// Address: 0x212B50
// Size: 0xE6C
void nmdrawDual(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x30, DWARF: 0x1567F6
Dual* info) {
    // Size: 0xB0, DWARF: 0x15608F
    DispTex tex; // 0x10(r29)

    tex.data = info->data;
    tex.tex_size[0] = 0xE0;
    tex.tex_size[1] = 0xA0;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0;
    tex.col[0][0] = 0x80;
    tex.col[0][1] = 0x80;
    tex.col[0][2] = 0x80;
    tex.col[0][3] = (info->abe * 2) / 3;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = (f32) tex.tex_size[0] * info->ratio;
    tex.option.height = (f32) tex.tex_size[1] * info->ratio;
    tex.vertex[0][0] = info->pos[0];
    tex.vertex[0][1] = info->pos[1];
    nmdrawFTex(packet, &tex);
    tex.data = info->data;
    tex.col[0][0] = 0x80;
    tex.col[0][1] = 0x40;
    tex.col[0][2] = 0x40;
    tex.col[0][3] = info->abe;
    tex.tex_size[0] = 0x10;
    tex.tex_size[1] = 0x10;
    tex.option.width = (f32) tex.tex_size[0] * info->ratio;
    tex.option.height = (f32) tex.tex_size[1] * info->ratio;
    if (info->ope->now.now & 0x4000) {
        tex.tex_uv[0] = 0x10;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (39.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (75.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 0x2000) {
        tex.tex_uv[0] = 0x10;
        tex.tex_uv[1] = 0xB0;
        tex.vertex[0][0] = info->pos[0] + (51.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (63.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 0x1000) {
        tex.tex_uv[0] = 0;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (38.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (52.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 0x8000) {
        tex.tex_uv[0] = 0;
        tex.tex_uv[1] = 0xB0;
        tex.vertex[0][0] = info->pos[0] + (27.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (63.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 0x20) {
        tex.tex_uv[0] = 0x40;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (184.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (63.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 0x80) {
        tex.tex_uv[0] = 0x40;
        tex.tex_uv[1] = 0xB0;
        tex.vertex[0][0] = info->pos[0] + (153.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (63.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 0x40) {
        tex.tex_uv[0] = 0x50;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (168.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (79.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 0x10) {
        tex.tex_uv[0] = 0x50;
        tex.tex_uv[1] = 0xB0;
        tex.vertex[0][0] = info->pos[0] + (169.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (48.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    tex.tex_size[0] = 0x20;
    tex.tex_size[1] = 0x10;
    tex.option.width = (f32) tex.tex_size[0] * info->ratio;
    tex.option.height = (f32) tex.tex_size[1] * info->ratio;
    if (info->ope->now.now & 4) {
        tex.tex_uv[0] = 0x20;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (32.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (10.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 1) {
        tex.tex_uv[0] = 0x20;
        tex.tex_uv[1] = 0xB0;
        tex.vertex[0][0] = info->pos[0] + (32.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + info->ratio;
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 8) {
        tex.tex_uv[0] = 0x20;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (161.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (10.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.now & 2) {
        tex.tex_uv[0] = 0x20;
        tex.tex_uv[1] = 0xB0;
        tex.vertex[0][0] = info->pos[0] + (161.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + info->ratio;
        nmdrawFTex(packet, &tex);
    }
    if (info->ope->now.left_v > 0x3F) {
        if (info->ope->now.left_h > 0x3F) {
            tex.tex_size[0] = 0x30;
            tex.tex_size[1] = 0x30;
            tex.option.width = (f32) tex.tex_size[0] * info->ratio;
            tex.option.height = (f32) tex.tex_size[1] * info->ratio;
            tex.tex_uv[0] = 0xA0;
            tex.tex_uv[1] = 0xA0;
            tex.vertex[0][0] = info->pos[0] + (54.0f * info->ratio);
            tex.vertex[0][1] = info->pos[1] + (81.0f * info->ratio);
            nmdrawFTex(packet, &tex);
            return;
        }
        if (info->ope->now.left_h < -0x3F) {
            tex.tex_size[0] = 0x30;
            tex.tex_size[1] = 0x30;
            tex.option.width = (f32) tex.tex_size[0] * info->ratio;
            tex.option.height = (f32) tex.tex_size[1] * info->ratio;
            tex.tex_uv[0] = 0xD0;
            tex.tex_uv[1] = 0xA0;
            tex.vertex[0][0] = info->pos[0] + (58.0f * info->ratio);
            tex.vertex[0][1] = info->pos[1] + (81.0f * info->ratio);
            nmdrawFTex(packet, &tex);
            return;
        }
        tex.tex_size[0] = 0x20;
        tex.tex_size[1] = 0x30;
        tex.option.width = (f32) tex.tex_size[0] * info->ratio;
        tex.option.height = (f32) tex.tex_size[1] * info->ratio;
        tex.tex_uv[0] = 0x60;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (64.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (79.0f * info->ratio);
        nmdrawFTex(packet, &tex);
        return;
    }
    if (info->ope->now.left_v < -0x3F) {
        if (info->ope->now.left_h > 0x3F) {
            tex.tex_size[0] = 0x30;
            tex.tex_size[1] = 0x30;
            tex.option.width = (f32) tex.tex_size[0] * info->ratio;
            tex.option.height = (f32) tex.tex_size[1] * info->ratio;
            tex.tex_uv[0] = 0xA0;
            tex.tex_uv[1] = 0xD0;
            tex.vertex[0][0] = info->pos[0] + (54.0f * info->ratio);
            tex.vertex[0][1] = info->pos[1] + (85.0f * info->ratio);
            nmdrawFTex(packet, &tex);
            return;
        }
        if (info->ope->now.left_h < -0x3F) {
            tex.tex_size[0] = 0x30;
            tex.tex_size[1] = 0x30;
            tex.option.width = (f32) tex.tex_size[0] * info->ratio;
            tex.option.height = (f32) tex.tex_size[1] * info->ratio;
            tex.tex_uv[0] = 0xD0;
            tex.tex_uv[1] = 0xD0;
            tex.vertex[0][0] = info->pos[0] + (59.0f * info->ratio);
            tex.vertex[0][1] = info->pos[1] + (85.0f * info->ratio);
            nmdrawFTex(packet, &tex);
            return;
        }
        tex.tex_size[0] = 0x20;
        tex.tex_size[1] = 0x30;
        tex.option.width = (f32) tex.tex_size[0] * info->ratio;
        tex.option.height = (f32) tex.tex_size[1] * info->ratio;
        tex.tex_uv[0] = 0x80;
        tex.tex_uv[1] = 0xA0;
        tex.vertex[0][0] = info->pos[0] + (64.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (87.0f * info->ratio);
        nmdrawFTex(packet, &tex);
        return;
    }
    tex.tex_size[0] = 0x30;
    tex.tex_size[1] = 0x20;
    tex.option.width = (f32) tex.tex_size[0] * info->ratio;
    tex.option.height = (f32) tex.tex_size[1] * info->ratio;
    if (info->ope->now.left_h > 0x3F) {
        tex.tex_uv[0] = 0x30;
        tex.tex_uv[1] = 0xC0;
        tex.vertex[0][0] = info->pos[0] + (51.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (90.0f * info->ratio);
        nmdrawFTex(packet, &tex);
        return;
    }
    if (info->ope->now.left_h < -0x3F) {
        tex.tex_uv[0] = 0;
        tex.tex_uv[1] = 0xC0;
        tex.vertex[0][0] = info->pos[0] + (61.0f * info->ratio);
        tex.vertex[0][1] = info->pos[1] + (90.0f * info->ratio);
        nmdrawFTex(packet, &tex);
    }
}

// DWARF: 0x159300
// Address: 0x2139C0
// Size: 0x64
void nmdrawInit(void) {
    vnmdrawScrSize[0] = 512.0f;
    vnmdrawScrSize[1] = 448.0f;
    vnmdrawScrRate[0] = vnmdrawScrSize[0] / 640.0f;
    vnmdrawScrRate[1] = vnmdrawScrSize[1] / 224.0f;
}

// DWARF: 0x1593AA
// Address: 0x213A30
// Size: 0x2B8
void nmdrawFLineStrip(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet /* 0xE0(r29) */, // Size: 0x90, DWARF: 0x154992
Poly* info /* 0xF0(r29) */) {
    signed int i; // r16
    // Size: 0x40, DWARF: 0x154AEF
    Poly3* poly; // r17
    void* addr; // r18
    signed int qwc; // r19
    // Size: 0x20, DWARF: 0x155E44
    Alpha_Tag* alpha; // r20
    float vertex[4][4]; // 0x60(r29)
    signed int xyz[4][4]; // 0xA0(r29)

    (void)qwc;

    qwc = 6;
    addr = (void*)ulgifAddCNTReserve(packet, qwc);
    alpha = addr;
    addr = alpha + 1;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    addr = poly + 1;
    nmdrawInitLSF4(poly, 1);
    poly->giftag.sce.EOP = 1;
    poly->prim.sce.ABE = 1;
    poly->rgbaq0.ul = ((s64)info->col[0][3] << 0x18) | (((s64)info->col[0][2] << 0x10) | ((s64)info->col[0][0] | ((s64)info->col[0][1] << 8)));
    for (i = 0; i < 4; i++) {
        vertex[i][0] = (f32) info->vertex[i][0];
        vertex[i][1] = (f32) (info->vertex[i][1] / 2.0f);
        nmdrawChangeVertex(vertex[i]);
        sceVu0FTOI4Vector(xyz[i], vertex[i]);
        xyz[i][2] = 0xFFFFFF;
    }
    poly->xyzf0.ul = ((s64)xyz[0][2] << 0x20) | ((s64)xyz[0][0] | (s64)xyz[0][1] << 0x10);
    poly->xyzf1.ul = ((s64)xyz[1][2] << 0x20) | ((s64)xyz[1][0] | (s64)xyz[1][1] << 0x10);
    poly->xyzf2.ul = ((s64)xyz[2][2] << 0x20) | ((s64)xyz[2][0] | (s64)xyz[2][1] << 0x10);
    poly->xyzf3.ul = ((s64)xyz[3][2] << 0x20) | ((s64)xyz[3][0] | (s64)xyz[3][1] << 0x10);
}

// DWARF: 0x15960E
// Address: 0x213CF0
// Size: 0x3E0
void nmdrawFPoly(VgmsysGifPkt* packet, Poly* info) {
    signed int i; // r16
    // Size: 0x40, DWARF: 0x154AEF
    Poly3* poly; // r17
    void* addr; // r18
    signed int qwc; // r19
    // Size: 0x20, DWARF: 0x155E44
    Alpha_Tag* alpha; // r20
    float vertex[4][4]; // r29+0x60
    signed int xyz[4][4]; // r29+0xA0

    (void)qwc;

    qwc = 6;
    addr = ulgifAddCNTReserve(packet, qwc);
    alpha = addr;
    addr = alpha + 1;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    addr = poly + 1;
    ulpktInitF4(poly, 1);
    poly->giftag.sce.EOP = 1;
    poly->prim.sce.ABE = 1;
    poly->rgbaq0.ul = (((s64) ((s64) info->col[0][3]) << 0x18) | (((s64) ((s64) info->col[0][2]) << 0x10) | ((s64) ((s64) info->col[0][0]) | ((s64) ((s64) info->col[0][1]) << 8))));
    if (info->option.sprite == 1) {
        vertex[0][0] = info->vertex[0][0];
        vertex[0][1] = info->vertex[0][1] / 2.0f;
        vertex[1][0] = info->vertex[0][0] + info->option.width;
        vertex[1][1] = info->vertex[0][1] / 2.0f;
        vertex[2][0] = info->vertex[0][0];
        vertex[2][1] = (info->vertex[0][1] + info->option.height) / 2.0f;
        vertex[3][0] = info->vertex[0][0] + info->option.width;
        vertex[3][1] = (info->vertex[0][1] + info->option.height) / 2.0f;
    } else {
        sceVu0CopyVector(&vertex[0][0], info->vertex[0]);
        sceVu0CopyVector(&vertex[1][0], info->vertex[1]);
        sceVu0CopyVector(&vertex[2][0], info->vertex[2]);
        sceVu0CopyVector(&vertex[3][0], info->vertex[3]);
    }
    for (i = 0; i < 4; i++) {
        nmdrawChangeVertex(vertex[i]);
        sceVu0FTOI4Vector(xyz[i], vertex[i]);
        if (info->vertex[0][2] == 0.0f) {
            xyz[i][2] = 0;
        } else {
            xyz[i][2] = 0xFFFFFF;
        }
    }
    poly->xyzf0.ul = ((s64) ((s64) xyz[0][2]) << 0x20) | ((s64) xyz[0][0] | ((s64) ((s64) xyz[0][1]) << 0x10));
    poly->xyzf1.ul = ((s64) ((s64) xyz[1][2]) << 0x20) | ((s64) ((s64) xyz[1][0]) | ((s64) ((s64) xyz[1][1]) << 0x10));
    poly->xyzf2.ul = (((s64) ((s64) xyz[2][2]) << 0x20) | ((s64) ((s64) xyz[2][0]) | ((s64) ((s64) xyz[2][1]) << 0x10)));
    poly->xyzf3.ul = (((s64) ((s64) xyz[3][2]) << 0x20) | ((s64) ((s64) xyz[3][0]) | ((s64) ((s64) xyz[3][1]) << 0x10)));
}

// DWARF: 0x15986D
// Address: 0x2140D0
// Size: 0x4C0
void nmdrawGPoly(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0x90, DWARF: 0x1562BF
Poly* info) {
    signed int i; // r16 // s0
    // Size: 0x60, DWARF: 0x157395
    Poly5* poly; // r17 // s1
    void* addr; // r18 // s2
    signed int qwc; // r19 // s3
    // Size: 0x20, DWARF: 0x155E44
    Alpha_Tag* alpha; // r20 // s4
    float vertex[4][4]; // 0x60(r29)
    signed int xyz[4][4]; // 0xA0(r29)

    (void)qwc;

    qwc = 8;
    addr = ulgifAddCNTReserve(packet, qwc);
    alpha = addr;
    addr = alpha + 1;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    addr = poly + 1;
    ulpktInitG4(poly, 1);
    poly->sceGifTag.sce.EOP = 1;
    poly->prim.sce.ABE = 1;
    poly->rgbaq0.ul = ((((s64) info->col[0][3]) << 0x18) | ((((s64) info->col[0][2]) << 0x10) | (((s64) info->col[0][0]) | (((s64) info->col[0][1]) << 8))));
    poly->rgbaq1.ul = ((((s64) info->col[1][3]) << 0x18) | ((((s64) info->col[1][2]) << 0x10) | (((s64) info->col[1][0]) | (((s64) info->col[1][1]) << 8))));
    poly->rgbaq2.ul = ((((s64) info->col[2][3]) << 0x18) | ((((s64) info->col[2][2]) << 0x10) | (((s64) info->col[2][0]) | (((s64) info->col[2][1]) << 8))));
    poly->rgbaq3.ul = ((((s64) info->col[3][3]) << 0x18) | ((((s64) info->col[3][2]) << 0x10) | (((s64) info->col[3][0]) | (((s64) info->col[3][1]) << 8))));
    if (info->option.sprite == 1) {
        vertex[0][0] = info->vertex[0][0];
        vertex[0][1] = info->vertex[0][1] / 2.0f;
        vertex[1][0] = info->vertex[0][0] + info->option.width;
        vertex[1][1] = info->vertex[0][1] / 2.0f;
        vertex[2][0] = info->vertex[0][0];
        vertex[2][1] = (info->vertex[0][1] + info->option.height) / 2.0f;
        vertex[3][0] = info->vertex[0][0] + info->option.width;
        vertex[3][1] = (info->vertex[0][1] + info->option.height) / 2.0f;
    } else {
        sceVu0CopyVector(&vertex[0][0], info->vertex[0]);
        sceVu0CopyVector(&vertex[1][0], info->vertex[1]);
        sceVu0CopyVector(&vertex[2][0], info->vertex[2]);
        sceVu0CopyVector(&vertex[3][0], info->vertex[3]);
    }
    for (i = 0; i < 4; i++) {
        nmdrawChangeVertex(vertex[i]);
        sceVu0FTOI4Vector(xyz[i], vertex[i]);
        xyz[i][2] = 0xFFFFFF;
    }
    poly->xyzf0.ul = ((((s64) xyz[0][2]) << 0x20) | (((s64) xyz[0][0]) | (((s64) xyz[0][1]) << 0x10)));
    poly->xyzf1.ul = ((((s64) xyz[1][2]) << 0x20) | (((s64) xyz[1][0]) | (((s64) xyz[1][1]) << 0x10)));
    poly->xyzf2.ul = ((((s64) xyz[2][2]) << 0x20) | (((s64) xyz[2][0]) | (((s64) xyz[2][1]) << 0x10)));
    poly->xyzf3.ul = ((((s64) xyz[3][2]) << 0x20) | (((s64) xyz[3][0]) | (((s64) xyz[3][1]) << 0x10)));
}

// DWARF: 0x159ACC
// Address: 0x214590
// Size: 0x56C
void nmdrawFTex(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, // Size: 0xB0, DWARF: 0x15608F
DispTex* info) {
    signed int i; // r16 // s0
    // Size: 0x70, DWARF: 0x154401
    Poly4* poly; // r17 // s1
    void* addr; // r18 // s2
    signed int qwc; // r19 // s3
    // Size: 0x20, DWARF: 0x155E44
    Alpha_Tag* alpha; // r20 // s4
    float vertex[4][4]; // 0x60(r29)
    signed int xyz[4][4]; // 0xA0(r29)

    (void)qwc;

    if (info->option.bil == 1) {
        nmdrawSwitchBil(packet, 1);
    }
    qwc = 9;
    addr = ulgifAddCNTReserve(packet, qwc);
    alpha = addr;
    addr = alpha + 1;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    addr = poly + 1;
    ulpktInitFT4(poly, 1, 1);
    poly->giftag.sce.EOP = 1;
    poly->prim.sce.ABE = 1;
    poly->tex0.ul = ultexGetTEX0(info->data);
    poly->stuv0.ul = ((s64) (((info->tex_uv[0] * 0x10) + 8)) | ((s64) (((info->tex_uv[1] * 0x10) + 8)) << 0x10));
    poly->stuv1.ul = (((s64) (((info->tex_uv[1] * 0x10) + 8)) << 0x10) | ((s64) (((info->tex_uv[0] + info->tex_size[0]) * 0x10) + 8)));
    poly->stuv2.ul = ((s64) (((info->tex_uv[0] * 0x10) + 8)) | (((s64) (((info->tex_uv[1] + info->tex_size[1]) * 0x10) + 8)) << 0x10));
    poly->stuv3.ul = (((s64) (((info->tex_uv[0] + info->tex_size[0]) * 0x10) + 8)) | (((s64) (((info->tex_uv[1] + info->tex_size[1]) * 0x10) + 8)) << 0x10));
    poly->rgbaq0.ul = ((((s64) info->col[0][3]) << 0x18) | ((((s64) info->col[0][2]) << 0x10) | (((s64) info->col[0][0]) | (((s64) info->col[0][1]) << 8))));
    if (info->option.sprite == 1) {
        vertex[0][0] = info->vertex[0][0];
        vertex[0][1] = info->vertex[0][1] / 2.0f;
        vertex[1][0] = info->vertex[0][0] + info->option.width;
        vertex[1][1] = info->vertex[0][1] / 2.0f;
        vertex[2][0] = info->vertex[0][0];
        vertex[2][1] = (info->vertex[0][1] + info->option.height) / 2.0f;
        vertex[3][0] = info->vertex[0][0] + info->option.width;
        vertex[3][1] = (info->vertex[0][1] + info->option.height) / 2.0f;
    } else {
        vertex[0][0] = info->vertex[0][0];
        vertex[0][1] = info->vertex[0][1] / 2.0f;
        vertex[1][0] = info->vertex[1][0];
        vertex[1][1] = info->vertex[1][1] / 2.0f;
        vertex[2][0] = info->vertex[2][0];
        vertex[2][1] = info->vertex[2][1] / 2.0f;
        vertex[3][0] = info->vertex[3][0];
        vertex[3][1] = info->vertex[3][1] / 2.0f;
    }
    for (i = 0; i < 4; i++) {
        nmdrawChangeVertex(vertex[i]);
        sceVu0FTOI4Vector(xyz[i], vertex[i]);
        xyz[i][2] = 0xFFFFFF;
    }
    poly->xyzf0.ul = ((((s64) xyz[0][2]) << 0x20) | (((s64) xyz[0][0]) | (((s64) xyz[0][1]) << 0x10)));
    poly->xyzf1.ul = ((((s64) xyz[1][2]) << 0x20) | (((s64) xyz[1][0]) | (((s64) xyz[1][1]) << 0x10)));
    poly->xyzf2.ul = ((((s64) xyz[2][2]) << 0x20) | (((s64) xyz[2][0]) | (((s64) xyz[2][1]) << 0x10)));
    poly->xyzf3.ul = ((((s64) xyz[3][2]) << 0x20) | (((s64) xyz[3][0]) | (((s64) xyz[3][1]) << 0x10)));
    if (info->option.bil == 1) {
        nmdrawSwitchBil(packet, 0);
    }
}

// DWARF: 0x159D2A
// Address: 0x214B00
// Size: 0x110
void nmdrawSwitchTest(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, signed int flag) {
    __int128 sceGifTag; // 0x10(r29)

    if (flag == 0) {
        ((long*)&sceGifTag)[0] = SCE_GIF_SET_TAG(0,1,0,0,4,0);
        ((long*)&sceGifTag)[1] = 0xE;
        sceGifPkCnt(packet, 0, 0, 0);
        sceGifPkOpenGifTag(packet, sceGifTag);
        sceGifPkAddGsAD(packet, 0x48, 0x50000);
        sceGifPkCloseGifTag(packet);
        return;
    }
    if (flag == 1) {
        ((long*)&sceGifTag)[0] = SCE_GIF_SET_TAG(0,0,0,0,4,0);
        ((long*)&sceGifTag)[1] = 0xE;
        sceGifPkCnt(packet, 0, 0, 0);
        sceGifPkOpenGifTag(packet, sceGifTag);
        sceGifPkAddGsAD(packet, 0x48, 0x30000);
        sceGifPkCloseGifTag(packet);
        return;
    }
}

// DWARF: 0x159E66
// Address: 0x214C10
// Size: 0x110
void nmdrawSwitchBil(// Size: 0x10, DWARF: 0x15488E
VgmsysGifPkt* packet, signed int flag) {
    __int128 sceGifTag; // 0x10(r29)
    if (flag == 0) {
        ((long*)&sceGifTag)[0] = SCE_GIF_SET_TAG(0,1,0,0,4,0);
        ((long*)&sceGifTag)[1] = 0xE;
        sceGifPkCnt(packet, 0, 0, 0);
        sceGifPkOpenGifTag(packet, sceGifTag);
        sceGifPkAddGsAD(packet, 0x15, 0);
        sceGifPkCloseGifTag(packet);
        return;
    }
    if (flag == 1) {
        ((long*)&sceGifTag)[0] = SCE_GIF_SET_TAG(0,0,0,0,4,0);
        ((long*)&sceGifTag)[1] = 0xE;
        sceGifPkCnt(packet, 0, 0, 0);
        sceGifPkOpenGifTag(packet, sceGifTag);
        sceGifPkAddGsAD(packet, 0x15, 0x60);
        sceGifPkCloseGifTag(packet);
        return;
    }
}

// DWARF: 0x159FA1
// Address: 0x214D20
// Size: 0x9C
extern sceVu0FVECTOR vnmdrawScrRate;
extern sceVu0FVECTOR vnmdrawScrSize;

void nmdrawChangeVertex(float* vertex) {
    vertex[0] = (f32) ((2048.0f - (vnmdrawScrSize[0] / 2.0f)) + (vertex[0] * vnmdrawScrRate[0]));
    vertex[1] = (f32) ((2048.0f - (vnmdrawScrSize[1] / 2.0f)) + (vertex[1] * vnmdrawScrRate[1]));
}

// DWARF: 0x15A087
// Address: 0x214DC0
// Size: 0x58
void nmdrawInitLSF4(// Size: 0x40, DWARF: 0x154AEF
Poly3* pkt, signed int ctext) {
    pkt->giftag.ul[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 6);
    pkt->giftag.ul[1] = 0x444410;
    pkt->prim.ul = ((s64)ctext << 9) | 2;
}

