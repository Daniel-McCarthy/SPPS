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
#pragma divbyzerocheck on
#pragma fast_fptosi on
#pragma dont_inline on

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


// Static data ///////////////////////////////////////////////////////////////////////

// aycreate.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x17B7CF
typedef struct _sceDmaTag 
{
    unsigned short qwc; // Offset: 0x0, DWARF: 0x17B7EE
    unsigned char mark; // Offset: 0x2, DWARF: 0x17B80E
    unsigned char id; // Offset: 0x3, DWARF: 0x17B82F
    struct _sceDmaTag* next; // Offset: 0x4, DWARF: 0x17B84E
    unsigned int p[2]; // Offset: 0x8, DWARF: 0x17B874
} _sceDmaTag;

// Size: 0x1C, DWARF: 0x17DAF2
typedef struct Character_Parameter
{
    signed int ollie; // Offset: 0x0, DWARF: 0x17DB0E
    signed int spin; // Offset: 0x4, DWARF: 0x17DB30
    signed int speed; // Offset: 0x8, DWARF: 0x17DB51
    signed int landing; // Offset: 0xC, DWARF: 0x17DB73
    signed int balance; // Offset: 0x10, DWARF: 0x17DB97
    signed int stability; // Offset: 0x14, DWARF: 0x17DBBB
    signed int stance; // Offset: 0x18, DWARF: 0x17DBE1
} Character_Parameter;

// Size: 0x74, DWARF: 0x17E133
typedef struct Character_State
{
    signed int secret; // Offset: 0x0, DWARF: 0x17E14F
    unsigned int board; // Offset: 0x4, DWARF: 0x17E172
    unsigned int course; // Offset: 0x8, DWARF: 0x17E194
    signed int rem_point; // Offset: 0xC, DWARF: 0x17E1B7
    signed int old_brd_no; // Offset: 0x10, DWARF: 0x17E1DD
    signed int old_wear_no; // Offset: 0x14, DWARF: 0x17E204
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x17E22C
    signed int soft[8]; // Offset: 0x38, DWARF: 0x17E255
    // Size: 0x1C, DWARF: 0x17DAF2
    Character_Parameter parameter; // Offset: 0x58, DWARF: 0x17E278
} Character_State;

// Size: 0x18, DWARF: 0x1800BF
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0x1800DB
    signed int month; // Offset: 0x4, DWARF: 0x1800FC
    signed int day; // Offset: 0x8, DWARF: 0x18011E
    signed int hour; // Offset: 0xC, DWARF: 0x18013E
    signed int minute; // Offset: 0x10, DWARF: 0x18015F
    signed int second; // Offset: 0x14, DWARF: 0x180182
} Clock;

// Size: 0xEC, DWARF: 0x179681
typedef struct Created_Character
{
    // Size: 0x74, DWARF: 0x17E133
    Character_State character; // Offset: 0x0, DWARF: 0x17969D
    // Size: 0x1C, DWARF: 0x17DAF2
    Character_Parameter init_param; // Offset: 0x74, DWARF: 0x1796C5
    // Size: 0x18, DWARF: 0x1800BF
    Clock clock; // Offset: 0x90, DWARF: 0x1796EE
    char name[16]; // Offset: 0xA8, DWARF: 0x179712
    signed int age; // Offset: 0xB8, DWARF: 0x179735
    signed int sex; // Offset: 0xBC, DWARF: 0x179755
    signed int face; // Offset: 0xC0, DWARF: 0x179775
    signed int hair; // Offset: 0xC4, DWARF: 0x179796
    signed int hair_color; // Offset: 0xC8, DWARF: 0x1797B7
    signed int body; // Offset: 0xCC, DWARF: 0x1797DE
    signed int body_color; // Offset: 0xD0, DWARF: 0x1797FF
    signed int pants; // Offset: 0xD4, DWARF: 0x179826
    signed int pants_color; // Offset: 0xD8, DWARF: 0x179848
    signed int glove; // Offset: 0xDC, DWARF: 0x179870
    signed int boots; // Offset: 0xE0, DWARF: 0x179892
    signed int board_type; // Offset: 0xE4, DWARF: 0x1798B4
    signed int trick_type; // Offset: 0xE8, DWARF: 0x1798DB
} Created_Character;

// Size: 0x80, DWARF: 0x17A997
typedef struct VayCreate
{
    signed int count; // Offset: 0x0, DWARF: 0x17A9B3
    signed int step; // Offset: 0x4, DWARF: 0x17A9D5
    signed int meskind; // Offset: 0x8, DWARF: 0x17A9F6
    signed int moveFlg; // Offset: 0xC, DWARF: 0x17AA1A
    signed int moveCnt; // Offset: 0x10, DWARF: 0x17AA3E
    signed int moveDir; // Offset: 0x14, DWARF: 0x17AA62
    signed int select[4]; // Offset: 0x18, DWARF: 0x17AA86
    signed int disp; // Offset: 0x28, DWARF: 0x17AAAB
    signed int dispsel; // Offset: 0x2C, DWARF: 0x17AACC
    signed int nextSelect; // Offset: 0x30, DWARF: 0x17AAF0
    signed int confFlg; // Offset: 0x34, DWARF: 0x17AB17
    signed int confBoard; // Offset: 0x38, DWARF: 0x17AB3B
    // Size: 0xEC, DWARF: 0x179681
    Created_Character* chara; // Offset: 0x3C, DWARF: 0x17AB61
    signed int sex; // Offset: 0x40, DWARF: 0x17AB88
    signed int stance; // Offset: 0x44, DWARF: 0x17ABA8
    signed int trickFlg; // Offset: 0x48, DWARF: 0x17ABCB
    signed int app[11]; // Offset: 0x4C, DWARF: 0x17ABF0
    char rem[6]; // Offset: 0x78, DWARF: 0x17AC12
} VayCreate;

// Size: 0x10, DWARF: 0x17D813
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x17D82F
    __int128* pBase; // Offset: 0x4, DWARF: 0x17D857
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x17D87C
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0x17D8A3
} VgmsysGifPkt;

// Size: 0x38, DWARF: 0x179071
typedef struct File
{
    // Size: 0x18, DWARF: 0x1800BF
    Clock clock; // Offset: 0x0, DWARF: 0x17908C
    char name[32]; // Offset: 0x18, DWARF: 0x1790B0
} File;

// Size: 0x20, DWARF: 0x178A0E
typedef struct Record
{
    signed int chr_no; // Offset: 0x0, DWARF: 0x178A29
    unsigned long score; // Offset: 0x8, DWARF: 0x178A4C
    char name[16]; // Offset: 0x10, DWARF: 0x178A6E
} Record;

// Size: 0x4, DWARF: 0x1793C9
typedef struct Best_Time
{
    unsigned int time; // Offset: 0x0, DWARF: 0x1793E5
} Best_Time; 

// Size: 0x24, DWARF: 0x179EF6
typedef struct Key_Config
{
    signed int vibration; // Offset: 0x0, DWARF: 0x179F12
    signed int spin_l; // Offset: 0x4, DWARF: 0x179F38
    signed int spin_r; // Offset: 0x8, DWARF: 0x179F5B
    signed int stance; // Offset: 0xC, DWARF: 0x179F7E
    signed int revert; // Offset: 0x10, DWARF: 0x179FA1
    signed int grind; // Offset: 0x14, DWARF: 0x179FC4
    signed int grab; // Offset: 0x18, DWARF: 0x179FE6
    signed int jump; // Offset: 0x1C, DWARF: 0x17A007
    signed int flip; // Offset: 0x20, DWARF: 0x17A028
} Key_Config;

// Size: 0x30, DWARF: 0x17C09F
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x17C0BB
    signed int always_sp; // Offset: 0x4, DWARF: 0x17C0DC
    signed int perfect_b; // Offset: 0x8, DWARF: 0x17C102
    signed int super_spin; // Offset: 0xC, DWARF: 0x17C128
    signed int half_g; // Offset: 0x10, DWARF: 0x17C14F
    signed int fast_motion; // Offset: 0x14, DWARF: 0x17C172
    signed int super_speed; // Offset: 0x18, DWARF: 0x17C19A
    signed int big_head; // Offset: 0x1C, DWARF: 0x17C1C2
    signed int metallic; // Offset: 0x20, DWARF: 0x17C1E7
    signed int mirror; // Offset: 0x24, DWARF: 0x17C20C
    signed int replay_view; // Offset: 0x28, DWARF: 0x17C22F
    signed int partition; // Offset: 0x2C, DWARF: 0x17C257
} Cheats;

// Size: 0x8, DWARF: 0x17BBB4
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0x17BBD0
    signed int bgm; // Offset: 0x4, DWARF: 0x17BBEF
} Volume;

// Size: 0x48, DWARF: 0x17D6A1
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0x17D6BD
    signed int disable; // Offset: 0x40, DWARF: 0x17D6E1
    signed int random; // Offset: 0x44, DWARF: 0x17D705
} Bgm;

// Size: 0x114, DWARF: 0x17D8CE
typedef struct Option
{
    // Size: 0x24, DWARF: 0x179EF6
    Key_Config key_config[2]; // Offset: 0x0, DWARF: 0x17D8EA
    // Size: 0x30, DWARF: 0x17C09F
    Cheats enable; // Offset: 0x48, DWARF: 0x17D913
    // Size: 0x30, DWARF: 0x17C09F
    Cheats cheats; // Offset: 0x78, DWARF: 0x17D938
    // Size: 0x8, DWARF: 0x17BBB4
    Volume volume; // Offset: 0xA8, DWARF: 0x17D95D
    char name[16]; // Offset: 0xB0, DWARF: 0x17D982
    signed int divide; // Offset: 0xC0, DWARF: 0x17D9A5
    signed int tutorial; // Offset: 0xC4, DWARF: 0x17D9C8
    // Size: 0x48, DWARF: 0x17D6A1
    Bgm bgm; // Offset: 0xC8, DWARF: 0x17D9ED
    unsigned int movie; // Offset: 0x110, DWARF: 0x17DA0F
} Option;

// Size: 0x8, DWARF: 0x17FEFC
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0, DWARF: 0x17FF18
} CourseGap;

// Size: 0xEF8, DWARF: 0x17F3D4
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0x17E133
    Character_State character[12]; // Offset: 0x0, DWARF: 0x17F3F0
    // Size: 0xEC, DWARF: 0x179681
    Created_Character create_character[10]; // Offset: 0x570, DWARF: 0x17F418
    // Size: 0x8, DWARF: 0x17FEFC
    CourseGap course[8]; // Offset: 0xEA8, DWARF: 0x17F447
    signed int tour_round; // Offset: 0xEE8, DWARF: 0x17F46C
    signed int old_char; // Offset: 0xEEC, DWARF: 0x17F493
    signed int first_clear; // Offset: 0xEF0, DWARF: 0x17F4B8
} VspenvSecret;

// Size: 0x1668, DWARF: 0x17997E
typedef struct Memcard
{
    // Size: 0x38, DWARF: 0x179071
    File file; // Offset: 0x0, DWARF: 0x17999A
    // Size: 0x20, DWARF: 0x178A0E
    Record record[8][6]; // Offset: 0x38, DWARF: 0x1799BD
    // Size: 0x4, DWARF: 0x1793C9
    Best_Time best_time[8]; // Offset: 0x638, DWARF: 0x1799E2
    // Size: 0x114, DWARF: 0x17D8CE
    Option option; // Offset: 0x658, DWARF: 0x179A0A
    // Size: 0xEF8, DWARF: 0x17F3D4
    VspenvSecret secret; // Offset: 0x770, DWARF: 0x179A2F
} Memcard;

// Size: 0x1690, DWARF: 0x17BC98
typedef struct VaySelData
{
    signed int count; // Offset: 0x0, DWARF: 0x17BCB4
    signed int bocount; // Offset: 0x4, DWARF: 0x17BCD6
    signed int step; // Offset: 0x8, DWARF: 0x17BCFA
    signed int nextMode; // Offset: 0xC, DWARF: 0x17BD1B
    signed int mode; // Offset: 0x10, DWARF: 0x17BD40
    // Size: 0x1668, DWARF: 0x17997E
    Memcard mc; // Offset: 0x18, DWARF: 0x17BD61
    signed int bgmdiff; // Offset: 0x1680, DWARF: 0x17BD82
    signed int bgm; // Offset: 0x1684, DWARF: 0x17BDA6
    signed int vcID; // Offset: 0x1688, DWARF: 0x17BDC6
    signed int vcTO; // Offset: 0x168C, DWARF: 0x17BDE7
} VaySelData;

// Size: 0x4, DWARF: 0x17F118
typedef struct Chcr
{
    unsigned int DIR : 1; // Offset: 0x0, DWARF: 0x17F134, Bit Offset: 0, Bit Size: 1
    unsigned int p0 : 1; // Offset: 0x0, DWARF: 0x17F15E, Bit Offset: 1, Bit Size: 1
    unsigned int MOD : 2; // Offset: 0x0, DWARF: 0x17F187, Bit Offset: 2, Bit Size: 2
    unsigned int ASP : 2; // Offset: 0x0, DWARF: 0x17F1B1, Bit Offset: 4, Bit Size: 2
    unsigned int TTE : 1; // Offset: 0x0, DWARF: 0x17F1DB, Bit Offset: 6, Bit Size: 1
    unsigned int TIE : 1; // Offset: 0x0, DWARF: 0x17F205, Bit Offset: 7, Bit Size: 1
    unsigned int STR : 1; // Offset: 0x0, DWARF: 0x17F22F, Bit Offset: 8, Bit Size: 1
    unsigned int p1 : 7; // Offset: 0x0, DWARF: 0x17F259, Bit Offset: 9, Bit Size: 7
    unsigned int TAG : 16; // Offset: 0x0, DWARF: 0x17F282, Bit Offset: 16, Bit Size: 16
} Chcr;

// Size: 0x90, DWARF: 0x17A5B3
typedef struct DmaGif
{
    // Size: 0x4, DWARF: 0x17F118
    Chcr chcr; // Offset: 0x0, DWARF: 0x17A5CF
    unsigned int p0[3]; // Offset: 0x4, DWARF: 0x17A5F2
    void* madr; // Offset: 0x10, DWARF: 0x17A613
    unsigned int p1[3]; // Offset: 0x14, DWARF: 0x17A637
    unsigned int qwc; // Offset: 0x20, DWARF: 0x17A658
    unsigned int p2[3]; // Offset: 0x24, DWARF: 0x17A678
    _sceDmaTag* tadr; // Offset: 0x30, DWARF: 0x17A699
    unsigned int p3[3]; // Offset: 0x34, DWARF: 0x17A6BF
    void* as0; // Offset: 0x40, DWARF: 0x17A6E0
    unsigned int p4[3]; // Offset: 0x44, DWARF: 0x17A703
    void* as1; // Offset: 0x50, DWARF: 0x17A724
    unsigned int p5[3]; // Offset: 0x54, DWARF: 0x17A747
    unsigned int p6[4]; // Offset: 0x60, DWARF: 0x17A768
    unsigned int p7[4]; // Offset: 0x70, DWARF: 0x17A789
    void* sadr; // Offset: 0x80, DWARF: 0x17A7AA
    unsigned int p8[3]; // Offset: 0x84, DWARF: 0x17A7CE
} DmaGif;

// Size: 0x8, DWARF: 0x17FCDE
typedef struct PMode
{
    unsigned int EN1 : 1; // Offset: 0x0, DWARF: 0x17FCFA, Bit Offset: 0, Bit Size: 1
    unsigned int EN2 : 1; // Offset: 0x0, DWARF: 0x17FD24, Bit Offset: 1, Bit Size: 1
    unsigned int CRTMD : 3; // Offset: 0x0, DWARF: 0x17FD4E, Bit Offset: 2, Bit Size: 3
    unsigned int MMOD : 1; // Offset: 0x0, DWARF: 0x17FD7A, Bit Offset: 5, Bit Size: 1
    unsigned int AMOD : 1; // Offset: 0x0, DWARF: 0x17FDA5, Bit Offset: 6, Bit Size: 1
    unsigned int SLBG : 1; // Offset: 0x0, DWARF: 0x17FDD0, Bit Offset: 7, Bit Size: 1
    unsigned int ALP : 8; // Offset: 0x0, DWARF: 0x17FDFB, Bit Offset: 8, Bit Size: 8
    unsigned int p0 : 16; // Offset: 0x0, DWARF: 0x17FE25, Bit Offset: 16, Bit Size: 16
    unsigned int p1; // Offset: 0x4, DWARF: 0x17FE4E
} PMode;

// Size: 0x8, DWARF: 0x17A865
typedef struct SMode
{
    unsigned int INT : 1; // Offset: 0x0, DWARF: 0x17A881, Bit Offset: 0, Bit Size: 1
    unsigned int FFMD : 1; // Offset: 0x0, DWARF: 0x17A8AB, Bit Offset: 1, Bit Size: 1
    unsigned int DPMS : 2; // Offset: 0x0, DWARF: 0x17A8D6, Bit Offset: 2, Bit Size: 2
    unsigned int p0 : 28; // Offset: 0x0, DWARF: 0x17A901, Bit Offset: 4, Bit Size: 28
    unsigned int p1; // Offset: 0x4, DWARF: 0x17A92A
} SMode;

// Size: 0x8, DWARF: 0x1781F0
typedef struct DispFb
{
    unsigned int FBP : 9; // Offset: 0x0, DWARF: 0x17820B, Bit Offset: 0, Bit Size: 9
    unsigned int FBW : 6; // Offset: 0x0, DWARF: 0x178235, Bit Offset: 9, Bit Size: 6
    unsigned int PSM : 5; // Offset: 0x0, DWARF: 0x17825F, Bit Offset: 15, Bit Size: 5
    unsigned int p0 : 12; // Offset: 0x0, DWARF: 0x178289, Bit Offset: 20, Bit Size: 12
    unsigned int DBX : 11; // Offset: 0x4, DWARF: 0x1782B2, Bit Offset: 0, Bit Size: 11
    unsigned int DBY : 11; // Offset: 0x4, DWARF: 0x1782DC, Bit Offset: 11, Bit Size: 11
    unsigned int p1 : 10; // Offset: 0x4, DWARF: 0x178306, Bit Offset: 22, Bit Size: 10
} DispFb;

// Size: 0x8, DWARF: 0x17C3D4
typedef struct Display
{
    unsigned int DX : 12; // Offset: 0x0, DWARF: 0x17C3F0, Bit Offset: 0, Bit Size: 12
    unsigned int DY : 11; // Offset: 0x0, DWARF: 0x17C419, Bit Offset: 12, Bit Size: 11
    unsigned int MAGH : 4; // Offset: 0x0, DWARF: 0x17C442, Bit Offset: 23, Bit Size: 4
    unsigned int MAGV : 2; // Offset: 0x0, DWARF: 0x17C46D, Bit Offset: 27, Bit Size: 2
    unsigned int p0 : 3; // Offset: 0x0, DWARF: 0x17C498, Bit Offset: 29, Bit Size: 3
    unsigned int DW : 12; // Offset: 0x4, DWARF: 0x17C4C1, Bit Offset: 0, Bit Size: 12
    unsigned int DH : 11; // Offset: 0x4, DWARF: 0x17C4EA, Bit Offset: 12, Bit Size: 11
    unsigned int p1 : 9; // Offset: 0x4, DWARF: 0x17C513, Bit Offset: 23, Bit Size: 9
} Display;

// Size: 0x8, DWARF: 0x17C97E
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x17C99A, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x17C9C2, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x17C9EA, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, DWARF: 0x17CA12, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4, DWARF: 0x17CA3B
} BgColor;

// Size: 0x28, DWARF: 0x17BF19
typedef struct Disp
{
    // Size: 0x8, DWARF: 0x17FCDE
    PMode pmode; // Offset: 0x0, DWARF: 0x17BF35
    // Size: 0x8, DWARF: 0x17A865
    SMode smode2; // Offset: 0x8, DWARF: 0x17BF59
    // Size: 0x8, DWARF: 0x1781F0
    DispFb dispfb; // Offset: 0x10, DWARF: 0x17BF7E
    // Size: 0x8, DWARF: 0x17C3D4
    Display display; // Offset: 0x18, DWARF: 0x17BFA3
    // Size: 0x8, DWARF: 0x17C97E
    BgColor bgcolor; // Offset: 0x20, DWARF: 0x17BFC9
} Disp;

// Size: 0x10, DWARF: 0x17A0E4
typedef struct GifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0x17A100, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0x17A12C, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x17A156, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0x17A182, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0x17A1AB, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0x17A1D5, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0x17A200, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0x17A22A, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0x17A255, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0x17A281, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0x17A2AD, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0x17A2D9, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0x17A305, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0x17A331, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0x17A35D, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0x17A389, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0x17A3B5, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0x17A3E1, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0x17A40D, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0x17A43A, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0x17A467, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0x17A494, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0x17A4C1, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0x17A4EE, Bit Offset: 60, Bit Size: 4
} GifTag;

// Size: 0x10, DWARF: 0x17AEA3
typedef union GifTagUl
{
    // Size: 0x10, DWARF: 0x17A0E4
    GifTag sce; // Offset: 0x0, DWARF: 0x17AEBF
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0x17AEE1
} GifTagUl;

// Size: 0x8, DWARF: 0x17FB90
typedef struct Frame
{
    unsigned long FBP : 9; // Offset: 0x0, DWARF: 0x17FBAC, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 7; // Offset: 0x0, DWARF: 0x17FBD6, Bit Offset: 9, Bit Size: 7
    unsigned long FBW : 6; // Offset: 0x0, DWARF: 0x17FC02, Bit Offset: 16, Bit Size: 6
    unsigned long pad22 : 2; // Offset: 0x0, DWARF: 0x17FC2C, Bit Offset: 22, Bit Size: 2
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x17FC58, Bit Offset: 24, Bit Size: 6
    unsigned long pad30 : 2; // Offset: 0x0, DWARF: 0x17FC82, Bit Offset: 30, Bit Size: 2
    unsigned long FBMSK : 32; // Offset: 0x0, DWARF: 0x17FCAE, Bit Offset: 32, Bit Size: 32
} Frame;

// Size: 0x8, DWARF: 0x17CB23
typedef struct ZBuf
{
    unsigned long ZBP : 9; // Offset: 0x0, DWARF: 0x17CB3F, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 15; // Offset: 0x0, DWARF: 0x17CB69, Bit Offset: 9, Bit Size: 15
    unsigned long PSM : 4; // Offset: 0x0, DWARF: 0x17CB95, Bit Offset: 24, Bit Size: 4
    unsigned long pad28 : 4; // Offset: 0x0, DWARF: 0x17CBBF, Bit Offset: 28, Bit Size: 4
    unsigned long ZMSK : 1; // Offset: 0x0, DWARF: 0x17CBEB, Bit Offset: 32, Bit Size: 1
    unsigned long pad33 : 31; // Offset: 0x0, DWARF: 0x17CC16, Bit Offset: 33, Bit Size: 31
} ZBuf;

// Size: 0x8, DWARF: 0x17ADD7
typedef struct XyOffset
{
    unsigned long OFX : 16; // Offset: 0x0, DWARF: 0x17ADF3, Bit Offset: 0, Bit Size: 16
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x17AE1D, Bit Offset: 16, Bit Size: 16
    unsigned long OFY : 16; // Offset: 0x0, DWARF: 0x17AE49, Bit Offset: 32, Bit Size: 16
    unsigned long pad48 : 16; // Offset: 0x0, DWARF: 0x17AE73, Bit Offset: 48, Bit Size: 16
} XyOffset;

// Size: 0x8, DWARF: 0x17F765
typedef struct Scissor
{
    unsigned long SCAX0 : 11; // Offset: 0x0, DWARF: 0x17F781, Bit Offset: 0, Bit Size: 11
    unsigned long pad11 : 5; // Offset: 0x0, DWARF: 0x17F7AD, Bit Offset: 11, Bit Size: 5
    unsigned long SCAX1 : 11; // Offset: 0x0, DWARF: 0x17F7D9, Bit Offset: 16, Bit Size: 11
    unsigned long pad27 : 5; // Offset: 0x0, DWARF: 0x17F805, Bit Offset: 27, Bit Size: 5
    unsigned long SCAY0 : 11; // Offset: 0x0, DWARF: 0x17F831, Bit Offset: 32, Bit Size: 11
    unsigned long pad43 : 5; // Offset: 0x0, DWARF: 0x17F85D, Bit Offset: 43, Bit Size: 5
    unsigned long SCAY1 : 11; // Offset: 0x0, DWARF: 0x17F889, Bit Offset: 48, Bit Size: 11
    unsigned long pad59 : 5; // Offset: 0x0, DWARF: 0x17F8B5, Bit Offset: 59, Bit Size: 5
} Scissor;

// Size: 0x8, DWARF: 0x17E523
typedef struct PrModeCont
{
    unsigned long AC : 1; // Offset: 0x0, DWARF: 0x17E53F, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x17E568, Bit Offset: 1, Bit Size: 63
} PrModeCont;

// Size: 0x8, DWARF: 0x179906
typedef struct ColClamp
{
    unsigned long CLAMP : 1; // Offset: 0x0, DWARF: 0x179922, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x17994E, Bit Offset: 1, Bit Size: 63
} ColClamp;

// Size: 0x8, DWARF: 0x17E795
typedef struct Dthe
{
    unsigned long DTHE : 1; // Offset: 0x0, DWARF: 0x17E7B1, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x17E7DC, Bit Offset: 1, Bit Size: 63
} Dthe;

// Size: 0x8, DWARF: 0x178BB1
typedef struct Test
{
    unsigned long ATE : 1; // Offset: 0x0, DWARF: 0x178BCC, Bit Offset: 0, Bit Size: 1
    unsigned long ATST : 3; // Offset: 0x0, DWARF: 0x178BF6, Bit Offset: 1, Bit Size: 3
    unsigned long AREF : 8; // Offset: 0x0, DWARF: 0x178C21, Bit Offset: 4, Bit Size: 8
    unsigned long AFAIL : 2; // Offset: 0x0, DWARF: 0x178C4C, Bit Offset: 12, Bit Size: 2
    unsigned long DATE : 1; // Offset: 0x0, DWARF: 0x178C78, Bit Offset: 14, Bit Size: 1
    unsigned long DATM : 1; // Offset: 0x0, DWARF: 0x178CA3, Bit Offset: 15, Bit Size: 1
    unsigned long ZTE : 1; // Offset: 0x0, DWARF: 0x178CCE, Bit Offset: 16, Bit Size: 1
    unsigned long ZTST : 2; // Offset: 0x0, DWARF: 0x178CF8, Bit Offset: 17, Bit Size: 2
    unsigned long pad19 : 45; // Offset: 0x0, DWARF: 0x178D23, Bit Offset: 19, Bit Size: 45
} Test;

// Size: 0x80, DWARF: 0x17C6F0
typedef struct Draw
{
    // Size: 0x8, DWARF: 0x17FB90
    Frame frame1; // Offset: 0x0, DWARF: 0x17C70C
    unsigned long frame1addr; // Offset: 0x8, DWARF: 0x17C731
    // Size: 0x8, DWARF: 0x17CB23
    ZBuf zbuf1; // Offset: 0x10, DWARF: 0x17C758
    signed long zbuf1addr; // Offset: 0x18, DWARF: 0x17C77C
    // Size: 0x8, DWARF: 0x17ADD7
    XyOffset xyoffset1; // Offset: 0x20, DWARF: 0x17C7A2
    signed long xyoffset1addr; // Offset: 0x28, DWARF: 0x17C7CA
    // Size: 0x8, DWARF: 0x17F765
    Scissor scissor1; // Offset: 0x30, DWARF: 0x17C7F4
    signed long scissor1addr; // Offset: 0x38, DWARF: 0x17C81B
    // Size: 0x8, DWARF: 0x17E523
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x17C844
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x17C86D
    // Size: 0x8, DWARF: 0x179906
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x17C898
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x17C8BF
    // Size: 0x8, DWARF: 0x17E795
    Dthe dthe; // Offset: 0x60, DWARF: 0x17C8E8
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x17C90B
    // Size: 0x8, DWARF: 0x178BB1
    Test test1; // Offset: 0x70, DWARF: 0x17C930
    signed long test1addr; // Offset: 0x78, DWARF: 0x17C954
} Draw;

// Size: 0x80, DWARF: 0x17DCA1
typedef struct Draw2
{
    // Size: 0x8, DWARF: 0x17FB90
    Frame frame2; // Offset: 0x0, DWARF: 0x17DCBD
    unsigned long frame2addr; // Offset: 0x8, DWARF: 0x17DCE2
    // Size: 0x8, DWARF: 0x17CB23
    ZBuf zbuf2; // Offset: 0x10, DWARF: 0x17DD09
    signed long zbuf2addr; // Offset: 0x18, DWARF: 0x17DD2D
    // Size: 0x8, DWARF: 0x17ADD7
    XyOffset xyoffset2; // Offset: 0x20, DWARF: 0x17DD53
    signed long xyoffset2addr; // Offset: 0x28, DWARF: 0x17DD7B
    // Size: 0x8, DWARF: 0x17F765
    Scissor scissor2; // Offset: 0x30, DWARF: 0x17DDA5
    signed long scissor2addr; // Offset: 0x38, DWARF: 0x17DDCC
    // Size: 0x8, DWARF: 0x17E523
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x17DDF5
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x17DE1E
    // Size: 0x8, DWARF: 0x179906
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x17DE49
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x17DE70
    // Size: 0x8, DWARF: 0x17E795
    Dthe dthe; // Offset: 0x60, DWARF: 0x17DE99
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x17DEBC
    // Size: 0x8, DWARF: 0x178BB1
    Test test2; // Offset: 0x70, DWARF: 0x17DEE1
    signed long test2addr; // Offset: 0x78, DWARF: 0x17DF05
} Draw2;

// Size: 0x8, DWARF: 0x17D20D
typedef struct Prim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0x17D229, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0x17D254, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0x17D27E, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0x17D2A8, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0x17D2D2, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0x17D2FC, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0x17D326, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0x17D350, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0x17D37B, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0x17D3A5, Bit Offset: 11, Bit Size: 53
} Prim;

// Size: 0x8, DWARF: 0x17B898
typedef union PrimUl
{
    // Size: 0x8, DWARF: 0x17D20D
    Prim sce; // Offset: 0x0, DWARF: 0x17B8B4
    unsigned long ul; // Offset: 0x0, DWARF: 0x17B8D6
} PrimUl;

// Size: 0x8, DWARF: 0x17B08B
typedef struct Tex
{
    unsigned long TBP0 : 14; // Offset: 0x0, DWARF: 0x17B0A7, Bit Offset: 0, Bit Size: 14
    unsigned long TBW : 6; // Offset: 0x0, DWARF: 0x17B0D2, Bit Offset: 14, Bit Size: 6
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x17B0FC, Bit Offset: 20, Bit Size: 6
    unsigned long TW : 4; // Offset: 0x0, DWARF: 0x17B126, Bit Offset: 26, Bit Size: 4
    unsigned long TH : 4; // Offset: 0x0, DWARF: 0x17B14F, Bit Offset: 30, Bit Size: 4
    unsigned long TCC : 1; // Offset: 0x0, DWARF: 0x17B178, Bit Offset: 34, Bit Size: 1
    unsigned long TFX : 2; // Offset: 0x0, DWARF: 0x17B1A2, Bit Offset: 35, Bit Size: 2
    unsigned long CBP : 14; // Offset: 0x0, DWARF: 0x17B1CC, Bit Offset: 37, Bit Size: 14
    unsigned long CPSM : 4; // Offset: 0x0, DWARF: 0x17B1F6, Bit Offset: 51, Bit Size: 4
    unsigned long CSM : 1; // Offset: 0x0, DWARF: 0x17B221, Bit Offset: 55, Bit Size: 1
    unsigned long CSA : 5; // Offset: 0x0, DWARF: 0x17B24B, Bit Offset: 56, Bit Size: 5
    unsigned long CLD : 3; // Offset: 0x0, DWARF: 0x17B275, Bit Offset: 61, Bit Size: 3
} Tex;

// Size: 0x8, DWARF: 0x17CA5E
typedef union TexUl
{
    // Size: 0x8, DWARF: 0x17B08B
    Tex sce; // Offset: 0x0, DWARF: 0x17CA7A
    unsigned long ul; // Offset: 0x0, DWARF: 0x17CA9C
} TexUl;

// Size: 0x8, DWARF: 0x17EDE7
typedef struct RGBAQ
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x17EE03, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x17EE2B, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x17EE53, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0x17EE7B, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0x17EEA3
} RGBAQ;

// Size: 0x8, DWARF: 0x17BC13
typedef union RGBAQ_Ul
{
    // Size: 0x8, DWARF: 0x17EDE7
    RGBAQ sce; // Offset: 0x0, DWARF: 0x17BC2F
    unsigned long ul; // Offset: 0x0, DWARF: 0x17BC51
} RGBAQ_Ul;

// Size: 0x8, DWARF: 0x18021A
typedef struct St
{
    float S; // Offset: 0x0, DWARF: 0x180236
    float T; // Offset: 0x4, DWARF: 0x180254
} St;

// Size: 0x8, DWARF: 0x1794A1
typedef struct Uv
{
    unsigned long U : 14; // Offset: 0x0, DWARF: 0x1794BD, Bit Offset: 0, Bit Size: 14
    unsigned long pad14 : 2; // Offset: 0x0, DWARF: 0x1794E5, Bit Offset: 14, Bit Size: 2
    unsigned long V : 14; // Offset: 0x0, DWARF: 0x179511, Bit Offset: 16, Bit Size: 14
    unsigned long pad30 : 34; // Offset: 0x0, DWARF: 0x179539, Bit Offset: 30, Bit Size: 34
} Uv;

// Size: 0x8, DWARF: 0x17C566
typedef union STUV_Ul
{
    // Size: 0x8, DWARF: 0x18021A
    St scest; // Offset: 0x0, DWARF: 0x17C582
    // Size: 0x8, DWARF: 0x1794A1
    Uv sceuv; // Offset: 0x0, DWARF: 0x17C5A6
    unsigned long ul; // Offset: 0x0, DWARF: 0x17C5CA
} STUV_Ul;

// Size: 0x8, DWARF: 0x17C314
typedef struct Xyzf
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x17C330, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x17C358, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 24; // Offset: 0x0, DWARF: 0x17C380, Bit Offset: 32, Bit Size: 24
    unsigned long F : 8; // Offset: 0x0, DWARF: 0x17C3A8, Bit Offset: 56, Bit Size: 8
} Xyzf;

  // Size: 0x8, DWARF: 0x17C03E
typedef union XyzfUl
{
    // Size: 0x8, DWARF: 0x17C314
    Xyzf sce; // Offset: 0x0, DWARF: 0x17C05A
    unsigned long ul; // Offset: 0x0, DWARF: 0x17C07C
} XyzfUl;

// Size: 0x70, DWARF: 0x17B2A3
typedef struct Poly
{
    // Size: 0x10, DWARF: 0x17AEA3
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x17B2BF
    // Size: 0x8, DWARF: 0x17B898
    PrimUl prim; // Offset: 0x10, DWARF: 0x17B2E4
    // Size: 0x8, DWARF: 0x17CA5E
    TexUl tex0; // Offset: 0x18, DWARF: 0x17B307
    // Size: 0x8, DWARF: 0x17BC13
    RGBAQ_Ul rgbaq0; // Offset: 0x20, DWARF: 0x17B32A
    // Size: 0x8, DWARF: 0x17C566
    STUV_Ul stuv0; // Offset: 0x28, DWARF: 0x17B34F
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf0; // Offset: 0x30, DWARF: 0x17B373
    // Size: 0x8, DWARF: 0x17C566
    STUV_Ul stuv1; // Offset: 0x38, DWARF: 0x17B397
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf1; // Offset: 0x40, DWARF: 0x17B3BB
    // Size: 0x8, DWARF: 0x17C566
    STUV_Ul stuv2; // Offset: 0x48, DWARF: 0x17B3DF
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf2; // Offset: 0x50, DWARF: 0x17B403
    // Size: 0x8, DWARF: 0x17C566
    STUV_Ul stuv3; // Offset: 0x58, DWARF: 0x17B427
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf3; // Offset: 0x60, DWARF: 0x17B44B
    unsigned long nop; // Offset: 0x68, DWARF: 0x17B46F
} Poly;

// Size: 0x8, DWARF: 0x17E5E3
typedef struct Alpha
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0x17E5FF, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0x17E627, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0x17E64F, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0x17E677, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0x17E69F, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0x17E6CA, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0x17E6F4, Bit Offset: 40, Bit Size: 24
} Alpha;

// Size: 0x8, DWARF: 0x17D3D5
typedef union AlphaUl
{
    // Size: 0x8, DWARF: 0x17E5E3
    Alpha sce; // Offset: 0x0, DWARF: 0x17D3F1
    unsigned long ul; // Offset: 0x0, DWARF: 0x17D413
} AlphaUl;

// Size: 0x20, DWARF: 0x17D436
typedef struct AlphaTag
{
    // Size: 0x10, DWARF: 0x17AEA3
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x17D452
    // Size: 0x8, DWARF: 0x17D3D5
    AlphaUl alpha; // Offset: 0x10, DWARF: 0x17D477
    signed long reg_addr; // Offset: 0x18, DWARF: 0x17D49B
} AlphaTag;

// Size: 0x10, DWARF: 0x178D53
typedef struct TexData
{
    signed short tofs; // Offset: 0x0, DWARF: 0x178D6E
    signed short cofs; // Offset: 0x2, DWARF: 0x178D8F
    signed short width; // Offset: 0x4, DWARF: 0x178DB0
    signed short height; // Offset: 0x6, DWARF: 0x178DD2
    signed short tw; // Offset: 0x8, DWARF: 0x178DF5
    signed short th; // Offset: 0xA, DWARF: 0x178E14
    signed short image_bit; // Offset: 0xC, DWARF: 0x178E33
    signed short clut_bit; // Offset: 0xE, DWARF: 0x178E59
} TexData;

// Size: 0x20, DWARF: 0x17CABF
typedef struct Mdl_Data
{
    float pos[4]; // Offset: 0x0, DWARF: 0x17CADB
    float rot[4]; // Offset: 0x10, DWARF: 0x17CAFD
} Mdl_Data;

// Size: 0x10, DWARF: 0x17E436
typedef struct Pos_Address
{
    unsigned int type; // Offset: 0x0, DWARF: 0x17E452
    float frame; // Offset: 0x4, DWARF: 0x17E473
    signed short flg; // Offset: 0x8, DWARF: 0x17E495
    signed short non; // Offset: 0xA, DWARF: 0x17E4B5
    float* data[4]; // Offset: 0xC, DWARF: 0x17E4D5
} Pos_Address;

// Size: 0xF0, DWARF: 0x179A58
typedef struct Seq
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0x179A74
    signed int loop; // Offset: 0x4, DWARF: 0x179A99
    signed int mode; // Offset: 0x8, DWARF: 0x179ABA
    signed int write_flg; // Offset: 0xC, DWARF: 0x179ADB
    signed int now_local_id; // Offset: 0x10, DWARF: 0x179B01
    signed int now_top_id; // Offset: 0x14, DWARF: 0x179B2A
    signed int next_local_id; // Offset: 0x18, DWARF: 0x179B51
    signed int next_top_id; // Offset: 0x1C, DWARF: 0x179B7B
    // Size: 0x20, DWARF: 0x17CABF
    Mdl_Data* mdl_data; // Offset: 0x20, DWARF: 0x179BA3
    float now_frame; // Offset: 0x24, DWARF: 0x179BCD
    float next_frame; // Offset: 0x28, DWARF: 0x179BF3
    float ratio; // Offset: 0x2C, DWARF: 0x179C1A
    // Size: 0x10, DWARF: 0x17E436
    Pos_Address* now_pos_address; // Offset: 0x30, DWARF: 0x179C3C
    // Size: 0x10, DWARF: 0x17E436
    Pos_Address* now_rot_address; // Offset: 0x34, DWARF: 0x179C6D
    // Size: 0x10, DWARF: 0x17E436
    Pos_Address* next_pos_address; // Offset: 0x38, DWARF: 0x179C9E
    // Size: 0x10, DWARF: 0x17E436
    Pos_Address* next_rot_address; // Offset: 0x3C, DWARF: 0x179CD0
    float nowDir[4]; // Offset: 0x40, DWARF: 0x179D02
    float nowTrans[4]; // Offset: 0x50, DWARF: 0x179D27
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0x179D4E
    float pos[4]; // Offset: 0xA0, DWARF: 0x179D77
    float quat[4]; // Offset: 0xB0, DWARF: 0x179D99
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0x179DBC
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0x179DE2
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0x179E08
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0x179E33
    signed int pad[2]; // Offset: 0xE8, DWARF: 0x179E5D
} Seq;

// Size: 0x230, DWARF: 0x17E80C
typedef struct IkParam
{
    float rot[4]; // Offset: 0x0, DWARF: 0xCE04C
    float trans[4]; // Offset: 0x10, DWARF: 0xCE06E
    float off_trans[2][4]; // Offset: 0x20, DWARF: 0xCE092
    sceVu0FMATRIX* boardMat; // Offset: 0x40, DWARF: 0xCE0BA
    sceVu0FMATRIX* board_local; // Offset: 0x44, DWARF: 0xCE0E4
    sceVu0FMATRIX* thighMatL; // Offset: 0x48, DWARF: 0xCE111
    sceVu0FMATRIX* thighMatR; // Offset: 0x4C, DWARF: 0xCE13C
    sceVu0FMATRIX* calfMatL; // Offset: 0x50, DWARF: 0xCE167
    sceVu0FMATRIX* calfMatR; // Offset: 0x54, DWARF: 0xCE191
    sceVu0FMATRIX* footMatL; // Offset: 0x58, DWARF: 0xCE1BB
    sceVu0FMATRIX* footMatR; // Offset: 0x5C, DWARF: 0xCE1E5
    sceVu0FMATRIX* toeMatL; // Offset: 0x60, DWARF: 0xCE20F
    sceVu0FMATRIX* toeMatR; // Offset: 0x64, DWARF: 0xCE238
    float thighLength[2]; // Offset: 0x68, DWARF: 0xCE261
    float shinLength[2]; // Offset: 0x70, DWARF: 0xCE28B
    signed int flg; // Offset: 0x78, DWARF: 0xCE2B4
    signed int pad; // Offset: 0x7C, DWARF: 0xCE2D4
    sceVu0FMATRIX footL; // Offset: 0x80, DWARF: 0xCE2F4
    sceVu0FMATRIX footR; // Offset: 0xC0, DWARF: 0xCE318
    sceVu0FMATRIX toeL; // Offset: 0x100, DWARF: 0xCE33C
    sceVu0FMATRIX toeR; // Offset: 0x140, DWARF: 0xCE35F
    float off_trans_toe[2][4]; // Offset: 0x180, DWARF: 0xCE382
    float thighLength_toe[2]; // Offset: 0x1A0, DWARF: 0xCE3AE
    float shinLength_toe[2]; // Offset: 0x1A8, DWARF: 0xCE3DC
    sceVu0FMATRIX board; // Offset: 0x1B0, DWARF: 0xCE409
    sceVu0FMATRIX board_world; // Offset: 0x1F0, DWARF: 0xCE42D
} IkParam;

// Size: 0x2E0, DWARF: 0x17AC38
typedef struct Ctrl
{
    float rot[4]; // Offset: 0x0, DWARF: 0x17AC54
    float trans[4]; // Offset: 0x10, DWARF: 0x17AC76
    float scale[4]; // Offset: 0x20, DWARF: 0x17AC9A
    float matrix[4][4]; // Offset: 0x30, DWARF: 0x17ACBE
    float revision[4][4]; // Offset: 0x70, DWARF: 0x17ACE3
    // Size: 0x230, DWARF: 0x17E80C
    IkParam ikparam; // Offset: 0xB0, DWARF: 0x17AD0A
} Ctrl;

// Size: 0x1A0, DWARF: 0x178886
typedef struct SCtrl
{
    signed int type; // Offset: 0x0, DWARF: 0x1788A1
    float power; // Offset: 0x4, DWARF: 0x1788C2
    float dir; // Offset: 0x8, DWARF: 0x1788E4
    float cnt; // Offset: 0xC, DWARF: 0x178904
    float head[4]; // Offset: 0x10, DWARF: 0x178924
    float preHead[4]; // Offset: 0x20, DWARF: 0x178947
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0x17896D
    float g_vector[4]; // Offset: 0x170, DWARF: 0x178997
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0x1789BE
    signed int pad[3]; // Offset: 0x194, DWARF: 0x1789E8
} SCtrl;

// Size: 0x20, DWARF: 0x17FF62
typedef struct Utd
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0x17FF7E
    // Size: 0x10, DWARF: 0x178D53
    TexData* tex; // Offset: 0x4, DWARF: 0x17FFA1
    signed int ntex; // Offset: 0x8, DWARF: 0x17FFC6
    signed int offset; // Offset: 0xC, DWARF: 0x17FFE7
    signed int block; // Offset: 0x10, DWARF: 0x18000A
    unsigned int* frame; // Offset: 0x14, DWARF: 0x18002C
    signed int res[2]; // Offset: 0x18, DWARF: 0x180051
} Utd;

// Size: 0x90, DWARF: 0x17BE0C
typedef struct Change
{
    sceVu0FMATRIX original; // Offset: 0x0, DWARF: 0xACAC6
    sceVu0FMATRIX original2; // Offset: 0x40, DWARF: 0xACAED
    sceVu0FMATRIX* address; // Offset: 0x80, DWARF: 0xACB15
    sceVu0FMATRIX* address2; // Offset: 0x84, DWARF: 0xACB3E
    signed int pad[2]; // Offset: 0x88, DWARF: 0xACB68
} Change;

// Size: 0x960, DWARF: 0x17AF06
typedef struct Character
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x17AF22
    unsigned char* vmd[2]; // Offset: 0x4, DWARF: 0x17AF46
    // Size: 0xF0, DWARF: 0x179A58
    Seq* seq; // Offset: 0xC, DWARF: 0x17AF68
    // Size: 0x2E0, DWARF: 0x17AC38
    Ctrl ctrl[2]; // Offset: 0x10, DWARF: 0x17AF8D
    // Size: 0x1A0, DWARF: 0x178886
    SCtrl sctrl[2]; // Offset: 0x5D0, DWARF: 0x17AFB0
    // Size: 0x20, DWARF: 0x17FF62
    Utd utd[2]; // Offset: 0x910, DWARF: 0x17AFD4
    // Size: 0x90, DWARF: 0x17BE0C
    Change* change[2]; // Offset: 0x950, DWARF: 0x17AFF6
} Character;

// Size: 0x4B0, DWARF: 0x178E82
typedef struct Soft
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x178E9D
    __int128* umd; // Offset: 0x4, DWARF: 0x178EC1
    __int128* smd; // Offset: 0x8, DWARF: 0x178EE4
    unsigned int* utd; // Offset: 0xC, DWARF: 0x178F07
    // Size: 0x10, DWARF: 0x178D53
    TexData* tex; // Offset: 0x10, DWARF: 0x178F2A
    // Size: 0xF0, DWARF: 0x179A58
    Seq* seq; // Offset: 0x14, DWARF: 0x178F4F
    signed int block; // Offset: 0x18, DWARF: 0x178F74
    unsigned int* frame; // Offset: 0x1C, DWARF: 0x178F96
    signed int res; // Offset: 0x20, DWARF: 0x178FBB
    // Size: 0x2E0, DWARF: 0x17AC38
    Ctrl ctrl; // Offset: 0x30, DWARF: 0x178FDB
    // Size: 0x1A0, DWARF: 0x178886
    SCtrl sctrl; // Offset: 0x310, DWARF: 0x178FFE
} Soft;

// Size: 0x378, DWARF: 0x17CC46
typedef struct Create_Chr
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x17CC62
    __int128* face_umd[9]; // Offset: 0x4, DWARF: 0x17CC86
    unsigned int* face_utd[9]; // Offset: 0x28, DWARF: 0x17CCAD
    // Size: 0x10, DWARF: 0x178D53
    TexData* face_tex[9]; // Offset: 0x4C, DWARF: 0x17CCD4
    // Size: 0xF0, DWARF: 0x179A58
    Seq* face_seq[9]; // Offset: 0x70, DWARF: 0x17CCFB
    __int128* hair_umd[4][2]; // Offset: 0x94, DWARF: 0x17CD22
    unsigned int* hair_utd[4][4][2]; // Offset: 0xB4, DWARF: 0x17CD49
    // Size: 0x10, DWARF: 0x178D53
    TexData* hair_tex[4][2]; // Offset: 0x134, DWARF: 0x17CD70
    // Size: 0xF0, DWARF: 0x179A58
    Seq* hair_seq[4]; // Offset: 0x154, DWARF: 0x17CD97
    __int128* body_umd[5]; // Offset: 0x164, DWARF: 0x17CDBE
    unsigned int* body_utd[5][9]; // Offset: 0x178, DWARF: 0x17CDE5
    // Size: 0x10, DWARF: 0x178D53
    TexData* body_tex[5]; // Offset: 0x22C, DWARF: 0x17CE0C
    // Size: 0xF0, DWARF: 0x179A58
    Seq* body_seq[5]; // Offset: 0x240, DWARF: 0x17CE33
    __int128* pants_umd[5]; // Offset: 0x254, DWARF: 0x17CE5A
    unsigned int* pants_utd[5][8]; // Offset: 0x268, DWARF: 0x17CE82
    // Size: 0x10, DWARF: 0x178D53
    TexData* pants_tex[5]; // Offset: 0x308, DWARF: 0x17CEAA
    // Size: 0xF0, DWARF: 0x179A58
    Seq* pants_seq[5]; // Offset: 0x31C, DWARF: 0x17CED2
    __int128* glove_umd; // Offset: 0x330, DWARF: 0x17CEFA
    unsigned int* glove_utd[4]; // Offset: 0x334, DWARF: 0x17CF23
    // Size: 0x10, DWARF: 0x178D53
    TexData* glove_tex; // Offset: 0x344, DWARF: 0x17CF4B
    // Size: 0xF0, DWARF: 0x179A58
    Seq* glove_seq; // Offset: 0x348, DWARF: 0x17CF76
    __int128* boots_umd; // Offset: 0x34C, DWARF: 0x17CFA1
    unsigned int* boots_utd[4]; // Offset: 0x350, DWARF: 0x17CFCA
    // Size: 0x10, DWARF: 0x178D53
    TexData* boots_tex; // Offset: 0x360, DWARF: 0x17CFF2
    // Size: 0xF0, DWARF: 0x179A58
    Seq* boots_seq; // Offset: 0x364, DWARF: 0x17D01D
    __int128* board_umd; // Offset: 0x368, DWARF: 0x17D048
    unsigned int* board_utd; // Offset: 0x36C, DWARF: 0x17D071
    // Size: 0x10, DWARF: 0x178D53
    TexData* board_tex; // Offset: 0x370, DWARF: 0x17D09A
    // Size: 0xF0, DWARF: 0x179A58
    Seq* board_seq; // Offset: 0x374, DWARF: 0x17D0C5
} Create_Chr;

// Size: 0x16720, DWARF: 0x17837D
typedef struct LoadData
{
    unsigned int* link[2]; // Offset: 0x0, DWARF: 0x178398
    signed int offset; // Offset: 0x8, DWARF: 0x1783BB
    unsigned int* env_utd; // Offset: 0xC, DWARF: 0x1783DE
    // Size: 0x10, DWARF: 0x178D53
    TexData* env_tex; // Offset: 0x10, DWARF: 0x178405
    unsigned int* select_utd; // Offset: 0x14, DWARF: 0x17842E
    unsigned int* selmov_utd; // Offset: 0x18, DWARF: 0x178458
    unsigned int* sponsor_utd; // Offset: 0x1C, DWARF: 0x178482
    // Size: 0x10, DWARF: 0x178D53
    TexData* sponsor_tex; // Offset: 0x20, DWARF: 0x1784AD
    unsigned int* medal_utd; // Offset: 0x24, DWARF: 0x1784DA
    // Size: 0x10, DWARF: 0x178D53
    TexData* medal_tex; // Offset: 0x28, DWARF: 0x178503
    __int128* medal_umd[3]; // Offset: 0x2C, DWARF: 0x17852E
    __int128* board_umd; // Offset: 0x38, DWARF: 0x178556
    unsigned char* board_vmd; // Offset: 0x3C, DWARF: 0x17857F
    unsigned int* board_utd; // Offset: 0x40, DWARF: 0x1785A8
    unsigned int* ayboard_utd; // Offset: 0x44, DWARF: 0x1785D1
    // Size: 0x10, DWARF: 0x178D53
    TexData* board_tex; // Offset: 0x48, DWARF: 0x1785FC
    unsigned int* emblem_utd; // Offset: 0x4C, DWARF: 0x178627
    // Size: 0x10, DWARF: 0x178D53
    TexData* emblem_tex; // Offset: 0x50, DWARF: 0x178651
    __int128* emblem_umd[2]; // Offset: 0x54, DWARF: 0x17867D
    __int128* select_uad; // Offset: 0x5C, DWARF: 0x1786A6
    // Size: 0x960, DWARF: 0x17AF06
    Character character[12][3]; // Offset: 0x60, DWARF: 0x1786D0
    // Size: 0x378, DWARF: 0x17CC46
    Create_Chr create_chr[2]; // Offset: 0x151E0, DWARF: 0x1786F8
    unsigned int* cr_arm_utd; // Offset: 0x158D0, DWARF: 0x178721
    unsigned int* cr_leg_utd; // Offset: 0x158D4, DWARF: 0x17874B
    unsigned int* cr_arm_f_utd; // Offset: 0x158D8, DWARF: 0x178775
    // Size: 0x4B0, DWARF: 0x178E82
    Soft game; // Offset: 0x158E0, DWARF: 0x1787A1
    // Size: 0x4B0, DWARF: 0x178E82
    Soft wheel; // Offset: 0x15D90, DWARF: 0x1787C4
    // Size: 0x4B0, DWARF: 0x178E82
    Soft param; // Offset: 0x16240, DWARF: 0x1787E8
    __int128* pad_umd[9]; // Offset: 0x166F0, DWARF: 0x17880C
    unsigned int* pad_utd; // Offset: 0x16714, DWARF: 0x178832
    // Size: 0x10, DWARF: 0x178D53
    TexData* pad_tex; // Offset: 0x16718, DWARF: 0x178859
} LoadData;

// Size: 0x8, DWARF: 0x17BB1C
typedef struct Xyz
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x17BB38, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x17BB60, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 32; // Offset: 0x0, DWARF: 0x17BB88, Bit Offset: 32, Bit Size: 32
} Xyz;

// Size: 0x60, DWARF: 0x17EF17
typedef struct Clear
{
    // Size: 0x8, DWARF: 0x178BB1
    Test testa; // Offset: 0x0, DWARF: 0x17EF33
    signed long testaaddr; // Offset: 0x8, DWARF: 0x17EF57
    // Size: 0x8, DWARF: 0x17D20D
    Prim prim; // Offset: 0x10, DWARF: 0x17EF7D
    signed long primaddr; // Offset: 0x18, DWARF: 0x17EFA0
    // Size: 0x8, DWARF: 0x17EDE7
    RGBAQ rgbaq; // Offset: 0x20, DWARF: 0x17EFC5
    signed long rgbaqaddr; // Offset: 0x28, DWARF: 0x17EFE9
    // Size: 0x8, DWARF: 0x17BB1C
    Xyz xyz2a; // Offset: 0x30, DWARF: 0x17F00F
    signed long xyz2aaddr; // Offset: 0x38, DWARF: 0x17F033
    // Size: 0x8, DWARF: 0x17BB1C
    Xyz xyz2b; // Offset: 0x40, DWARF: 0x17F059
    signed long xyz2baddr; // Offset: 0x48, DWARF: 0x17F07D
    // Size: 0x8, DWARF: 0x178BB1
    Test testb; // Offset: 0x50, DWARF: 0x17F0A3
    signed long testbaddr; // Offset: 0x58, DWARF: 0x17F0C7
} Clear;

// Size: 0x330, DWARF: 0x18029C
typedef struct DBuff
{
    // Size: 0x28, DWARF: 0x17BF19
    Disp disp[2]; // Offset: 0x0, DWARF: 0x1802B8
    // Size: 0x10, DWARF: 0x17A0E4
    GifTag giftag0; // Offset: 0x50, DWARF: 0x1802DB
    // Size: 0x80, DWARF: 0x17C6F0
    Draw draw01; // Offset: 0x60, DWARF: 0x180301
    // Size: 0x80, DWARF: 0x17DCA1
    Draw2 draw02; // Offset: 0xE0, DWARF: 0x180326
    // Size: 0x60, DWARF: 0x17EF17
    Clear clear0; // Offset: 0x160, DWARF: 0x18034B
    // Size: 0x10, DWARF: 0x17A0E4
    GifTag giftag1; // Offset: 0x1C0, DWARF: 0x180370
    // Size: 0x80, DWARF: 0x17C6F0
    Draw draw11; // Offset: 0x1D0, DWARF: 0x180396
    // Size: 0x80, DWARF: 0x17DCA1
    Draw2 draw12; // Offset: 0x250, DWARF: 0x1803BB
    // Size: 0x60, DWARF: 0x17EF17
    Clear clear1; // Offset: 0x2D0, DWARF: 0x1803E0
} DBuff;

// Size: 0x360, DWARF: 0x179124
typedef struct VulsysSystem
{
    unsigned int KeepMemSize; // Offset: 0x0, DWARF: 0x17913F
    signed int Pal; // Offset: 0x4, DWARF: 0x179167
    signed int Interlace; // Offset: 0x8, DWARF: 0x179187
    signed short ScreenMode; // Offset: 0xC, DWARF: 0x1791AD
    signed short ScreenWidth; // Offset: 0xE, DWARF: 0x1791D4
    signed short ScreenHeight; // Offset: 0x10, DWARF: 0x1791FC
    signed short ScreenYofs; // Offset: 0x12, DWARF: 0x179225
    signed int EvenOdd; // Offset: 0x14, DWARF: 0x17924C
    unsigned long Frame; // Offset: 0x18, DWARF: 0x179270
    signed int PadInit; // Offset: 0x20, DWARF: 0x179292
    // Size: 0x90, DWARF: 0x17A5B3
    DmaGif* DmaGif; // Offset: 0x24, DWARF: 0x1792B6
    // Size: 0x90, DWARF: 0x17A5B3
    DmaGif* DmaVif0; // Offset: 0x28, DWARF: 0x1792DE
    // Size: 0x90, DWARF: 0x17A5B3
    DmaGif* DmaVif1; // Offset: 0x2C, DWARF: 0x179307
    // Size: 0x330, DWARF: 0x18029C
    DBuff DBuff; // Offset: 0x30, DWARF: 0x179330
} VulsysSystem;

// Size: 0x10, DWARF: 0x17AD34
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x17AD50
    unsigned int addr; // Offset: 0x4, DWARF: 0x17AD73
    unsigned int z; // Offset: 0x8, DWARF: 0x17AD94
    unsigned int _pad; // Offset: 0xC, DWARF: 0x17ADB2
} ATag;

// Size: 0x20, DWARF: 0x17B943
typedef struct VgmsysAbuf
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0x17B95F
    unsigned int natag; // Offset: 0x4, DWARF: 0x17B983
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0x17B9A5
    unsigned int npkt; // Offset: 0xC, DWARF: 0x17B9C8
    // Size: 0x10, DWARF: 0x17AD34
    ATag* atag; // Offset: 0x10, DWARF: 0x17B9E9
    // Size: 0x10, DWARF: 0x17AD34
    ATag* curatag; // Offset: 0x14, DWARF: 0x17BA0F
    __int128* pkt; // Offset: 0x18, DWARF: 0x17BA38
    __int128* curpkt; // Offset: 0x1C, DWARF: 0x17BA5B
} VgmsysAbuf;

// Size: 0x20, DWARF: 0x17B4E1
typedef struct Pad_State
{
    signed int id; // Offset: 0x0, DWARF: 0x17B4FD
    unsigned int now; // Offset: 0x4, DWARF: 0x17B51C
    unsigned int status; // Offset: 0x8, DWARF: 0x17B53C
    unsigned int press; // Offset: 0xC, DWARF: 0x17B55F
    signed char right_h; // Offset: 0x10, DWARF: 0x17B581
    signed char right_v; // Offset: 0x11, DWARF: 0x17B5A5
    signed char left_h; // Offset: 0x12, DWARF: 0x17B5C9
    signed char left_v; // Offset: 0x13, DWARF: 0x17B5EC
    unsigned char l_right; // Offset: 0x14, DWARF: 0x17B60F
    unsigned char l_left; // Offset: 0x15, DWARF: 0x17B633
    unsigned char l_up; // Offset: 0x16, DWARF: 0x17B656
    unsigned char l_down; // Offset: 0x17, DWARF: 0x17B677
    unsigned char r_up; // Offset: 0x18, DWARF: 0x17B69A
    unsigned char r_right; // Offset: 0x19, DWARF: 0x17B6BB
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x17B6DF
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x17B702
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x17B725
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x17B745
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x17B765
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x17B785
} Pad_State;

// Size: 0x60, DWARF: 0x17D538
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0x17B4E1
    Pad_State now; // Offset: 0x0, DWARF: 0x17D554
    // Size: 0x20, DWARF: 0x17B4E1
    Pad_State old; // Offset: 0x20, DWARF: 0x17D576
    unsigned int port; // Offset: 0x40, DWARF: 0x17D598
    unsigned int slot; // Offset: 0x44, DWARF: 0x17D5B9
    unsigned int mode; // Offset: 0x48, DWARF: 0x17D5DA
    unsigned int trg; // Offset: 0x4C, DWARF: 0x17D5FB
    unsigned int rev; // Offset: 0x50, DWARF: 0x17D61B
    unsigned int cnt; // Offset: 0x54, DWARF: 0x17D63B
    unsigned int rep; // Offset: 0x58, DWARF: 0x17D65B
    signed int state; // Offset: 0x5C, DWARF: 0x17D67B
} VgmsysPad;

// Size: 0x4, DWARF: 0x17F395
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0x17F3B1
} CourseNo;

// Size: 0x10, DWARF: 0x17E315
typedef struct Board_Param
{
    signed int speed; // Offset: 0x0, DWARF: 0x17E331
    signed int stability; // Offset: 0x4, DWARF: 0x17E353
    signed int balance; // Offset: 0x8, DWARF: 0x17E379
    signed int turning; // Offset: 0xC, DWARF: 0x17E39D
} Board_Param;

// Size: 0x3C, DWARF: 0x17ECA8
typedef struct GameCharacter
{
    signed int no; // Offset: 0x0, DWARF: 0x17ECC4
    signed int player; // Offset: 0x4, DWARF: 0x17ECE3
    signed int wear; // Offset: 0x8, DWARF: 0x17ED06
    signed int board; // Offset: 0xC, DWARF: 0x17ED27
    // Size: 0x1C, DWARF: 0x17DAF2
    Character_Parameter chr_param; // Offset: 0x10, DWARF: 0x17ED49
    // Size: 0x10, DWARF: 0x17E315
    Board_Param brd_param; // Offset: 0x2C, DWARF: 0x17ED71
} GameCharacter;

// Size: 0x18, DWARF: 0x17F508
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x17F524
    signed int game_mode; // Offset: 0x4, DWARF: 0x17F54B
    signed int match_rule; // Offset: 0x8, DWARF: 0x17F571
    signed int divide; // Offset: 0xC, DWARF: 0x17F598
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x17F5BB
} Mode;

// Size: 0xA0, DWARF: 0x17DF7F
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x17F395
    CourseNo course; // Offset: 0x0, DWARF: 0x17DF9B
    // Size: 0x3C, DWARF: 0x17ECA8
    GameCharacter character[2]; // Offset: 0x4, DWARF: 0x17DFC0
    // Size: 0x18, DWARF: 0x17F508
    Mode mode; // Offset: 0x7C, DWARF: 0x17DFE8
    signed int language; // Offset: 0x94, DWARF: 0x17E00B
    signed int ending; // Offset: 0x98, DWARF: 0x17E030
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x17E053
} VspenvGame;

// Size: 0xE0, DWARF: 0x179569
typedef struct Data
{
    signed int col[4][4]; // Offset: 0x0, DWARF: 0x179585
    signed int vert[4][4]; // Offset: 0x40, DWARF: 0x1795A7
    signed int uv[4]; // Offset: 0x80, DWARF: 0x1795CA
    float stq[4][4]; // Offset: 0x90, DWARF: 0x1795EB
    // Size: 0x10, DWARF: 0x178D53
    TexData* texdata; // Offset: 0xD0, DWARF: 0x17960D
    unsigned long psmt; // Offset: 0xD8, DWARF: 0x179636
} Data;

// Size: 0xC, DWARF: 0x17F957
typedef struct Fog
{
    signed int enable; // Offset: 0x0, DWARF: 0x17F973
    float a; // Offset: 0x4, DWARF: 0x17F996
    float b; // Offset: 0x8, DWARF: 0x17F9B4
} Fog;

// Size: 0x8, DWARF: 0x17FB2B
typedef struct EnvMap
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x17FB47
} EnvMap;

// Size: 0x8, DWARF: 0x17FE97
typedef struct Toon
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x17FEB3
} Toon;

// Size: 0x120, DWARF: 0x17F5E6
typedef struct MdlEnv
{
    float world_view[4][4]; // Offset: 0x0, DWARF: 0x17F602
    float view_screen[4][4]; // Offset: 0x40, DWARF: 0x17F62B
    float normal_light[4][4]; // Offset: 0x80, DWARF: 0x17F655
    float light_color[4][4]; // Offset: 0xC0, DWARF: 0x17F680
    // Size: 0xC, DWARF: 0x17F957
    Fog fog; // Offset: 0x100, DWARF: 0x17F6AA
    union
    {
        // Size: 0x8, DWARF: 0x17FB2B
        EnvMap envmap; // Offset: 0x110, DWARF: 0x17F6CC
        // Size: 0x8, DWARF: 0x17FE97
        Toon toon; // Offset: 0x110, DWARF: 0x17F6F1
    } toonlink;
} MdlEnv;

// Size: 0x40, DWARF: 0x17D0F4
typedef struct Poly2
{
    // Size: 0x10, DWARF: 0x17AEA3
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x17D110
    // Size: 0x8, DWARF: 0x17B898
    PrimUl prim; // Offset: 0x10, DWARF: 0x17D135
    // Size: 0x8, DWARF: 0x17BC13
    RGBAQ_Ul rgbaq0; // Offset: 0x18, DWARF: 0x17D158
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf0; // Offset: 0x20, DWARF: 0x17D17D
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf1; // Offset: 0x28, DWARF: 0x17D1A1
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf2; // Offset: 0x30, DWARF: 0x17D1C5
    unsigned long nop; // Offset: 0x38, DWARF: 0x17D1E9
} Poly2;

// Size: 0x40, DWARF: 0x178A95
typedef struct Poly3
{
    // Size: 0x10, DWARF: 0x17AEA3
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x178AB0
    // Size: 0x8, DWARF: 0x17B898
    PrimUl prim; // Offset: 0x10, DWARF: 0x178AD5
    // Size: 0x8, DWARF: 0x17BC13
    RGBAQ_Ul rgbaq0; // Offset: 0x18, DWARF: 0x178AF8
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf0; // Offset: 0x20, DWARF: 0x178B1D
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf1; // Offset: 0x28, DWARF: 0x178B41
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf2; // Offset: 0x30, DWARF: 0x178B65
    // Size: 0x8, DWARF: 0x17C03E
    XyzfUl xyzf3; // Offset: 0x38, DWARF: 0x178B89
} Poly3;

//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0x80, DWARF: 0x17A997
VayCreate* vayCreate; // Address: 0x2E7F14
// Size: 0x10, DWARF: 0x17D813
VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
// Size: 0x1690, DWARF: 0x17BC98
VaySelData* vaySelData; // Address: 0x2E7BB4
// Size: 0x360, DWARF: 0x179124
VulsysSystem vulsysSystem; // Address: 0x2F3A50
// Size: 0x20, DWARF: 0x17B943
VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0
// Size: 0x60, DWARF: 0x17D538
VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30
// Size: 0xEF8, DWARF: 0x17F3D4
VspenvSecret* vspenvSecret; // Address: 0x2E7B04
// Size: 0xA0, DWARF: 0x17DF7F
VspenvGame* vspenvGame; // Address: 0x2E7B14
signed int vayParamMax[12][6]; // Address: 0x2C7C10

//// Function Declarations ///////////////////////////////////////////////////////////

void ayCreateInit();
signed int ayCreateFrame();
void ayCreateClear();
static void aySetCharPtr();
static void aySetCharParts();
void ayCreateEnd();
static void ayDrawHead();
static void ayDrawFileList();
static void ayDrawChara();
static void ayDrawNameEntry();
static void ayDrawWheelItem();
static void ayDrawMain(// Size: 0x10, DWARF: 0x178D53
TexData* texData);
static void ayDrawPerson(// Size: 0x10, DWARF: 0x178D53
TexData* texData);
static void ayDrawBuild(// Size: 0x10, DWARF: 0x178D53
TexData* texData);
static void ayDrawParam(// Size: 0x10, DWARF: 0x178D53
TexData* texData);
static float ayCalcBarMove(signed int count, signed int id);
static void ayDrawRem();
static signed int ayDrawConfirm();
static void aySetKeyOparate();
static signed int ayGetTricktype(char* name);

//// Function Definitions ///////////////////////////////////////////////////////////

void* memcpy(void* dest, const void* src, signed int size);
signed int ayCalcNextID(signed int now, signed int limit, signed int dir);
float ayCalcTotalMove(signed int frame, signed int count, float totalmove, signed int type);
void ayBlackOutDraw(signed int col);
void ayDrawBG(VgmsysGifPkt* packet, TexData* texData, signed int col, signed int mark);
void ayDrawCreateChara(Created_Character* chara, MdlEnv* mdlEnv, float* mat, signed int count);
void ayDrawKeyOparate(signed int kind, signed int count, signed int flg, TexData* texData, VgmsysGifPkt* packet);
void ayFontInit(signed int x, signed int y, signed int* fcol);
signed int ayMcCareerSave(VgmsysGifPkt* packet);
signed int ayMcGetStep();
void ayMcSetSaveFileID();
void aySetCamMatrix(float* worldScr, float* worldView, float* viewScr);
void aySetLightMatrix(float* nLight, float* lightCol, float acol, float lcol);
void aySetMotFlg(signed int mot);
void aySetPolyComF3(Poly2* poly, float* pos, signed int flg, signed int col);
void aySetPolyComF4(Poly3* poly, Data* data);
void aySetPolyComFT4(Poly* poly, Data* data, signed int flg);
void aySetTimeStr(char* str, Clock* data);
void aySetVert(signed int* vert, float* xy, signed int z);
void nmfontFPrint(VgmsysGifPkt* packet, char* str, signed int x, signed int y);
void nmfontFPrintF(VgmsysGifPkt* packet, char* str, float* pos);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);
void nmfontInitOption();
void nmfontSetBil(signed int flag);
void nmfontSetCol(signed int* col);
void nmfontSetPack(signed int flag);
void nmfontSetSize(signed int width, signed int height);
signed int nmvcPlay(signed int res, signed int group, signed int num);
signed int nmvcPlayButton(signed int num);
signed int nmvcPlayCursor(signed int num);
void spinitInitCreateCharacter(Created_Character* character);
void spinitGetCreateClock(signed int no);
LoadData* sploadGetSelectData();
void sceGifPkReset(void* p);
signed int sceDmaSync(DmaGif* d0, signed int mode, signed int timeout);
void sceGsSyncPath(signed int mode, unsigned short timeout);
void sceVu0UnitMatrix(sceVu0FMATRIX m);
void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR tv);
void ul3dScaleMatrixXYZ(float* mat, float sx, float sy, float sz);
void ulFree(void* p);
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void* ulgifAddCNTReserve(VgmsysGifPkt* pkt, signed int qwc);
void ulgifDmaSend(VgmsysGifPkt* pkt);
void ulgifTermPacket(VgmsysGifPkt* pkt);
void ulgraphAlphaDrawPacket(DmaGif* dmagif, VgmsysAbuf* abuf);
void ulgraphAlphaSortPacket(VgmsysAbuf* abuf);
void ulpktInitALPHA(AlphaTag* pkt, signed int ctext);
signed int ulstdSprintf(char* buf, char* fmt, ...);
void ultexResetTex(signed int offset);
void ultexTransTexTag(VgmsysGifPkt* packet, unsigned int* addr, TexData* data, signed int no);

// Matched 100%: https://decomp.me/scratch/joUCQ
void ayCreateInit() {
    vayCreate = (void*)ulMalloc(0x80, 0, 0);
    ayCreateClear();
}

signed int ayCreateFrame() {
    signed int ret = 0; // r19
    signed int next = 0; // r16
    signed int ii; // r17
    signed int mc; // r20
    TexData texData[3]; // 0x70(r29)
    LoadData* data; // r18
    signed int bg; // r21

    data = sploadGetSelectData();
    ultexResetTex(data->offset);
    for (ii = 0; ii < 3; ii++) {
        texData[ii].tofs = -1;
        texData[ii].cofs = -1;
    }
    ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData[0], 0);
    ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData[1], 2);
    ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData[2], 0x39);
    if ((vayCreate->step < 2) || ((vayCreate->step == 2) && (vayCreate->count < 0x10)) || ((vayCreate->step == 4) && (vayCreate->count >= 0x10))) {
        bg = 0;
        ayDrawBG(vgmsysGifPkt, &texData[0], 0x80, 0);
        ayDrawFileList();
    } else {
        bg = 1;
        ayDrawBG(vgmsysGifPkt, &texData[0], 0x80, 1);
        if ((vayCreate->step == 9) || (vayCreate->step == 0xB) || (vayCreate->step == 0xF)) {
            ayDrawHead();
        }
        ayDrawChara();
    }
    switch (vayCreate->step) {
    case 0:
        if (vayCreate->count == 0x40) {
            next = 1;
            vayCreate->step = 1;
        }
        break;
    case 1:
        if ((vaySelData->bocount == -1) && (vayCreate->confFlg == -1)) {
            if (vgmsysPad[0]->trg & 0x40) {
                nmvcPlayButton(0);
                vayCreate->select[2] = 0;
                vayCreate->select[1] = 0;
                if (vspenvSecret->create_character[vayCreate->select[0]].character.secret == 1) {
                    vayCreate->confBoard = 0;
                    vayCreate->confFlg = 1;
                    vayCreate->moveCnt = 0;
                    vayCreate->moveFlg = -1;
                    vayCreate->meskind = 0;
                } else {
                    vayCreate->step = 2;
                    aySetCharPtr();
                    vayCreate->trickFlg = 0;
                    next = 1;
                }
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                ret = 0xB;
                next = 1;
            } else if (vgmsysPad[0]->trg & 0x20) {
                if (vspenvSecret->create_character[vayCreate->select[0]].character.secret == 1) {
                    nmvcPlayButton(0);
                    vayCreate->confBoard = 0;
                    vayCreate->confFlg = 1;
                    vayCreate->moveCnt = 0;
                    vayCreate->moveFlg = -1;
                    vayCreate->meskind = 4;
                } else {
                    nmvcPlayButton(3);
                }
            }
        }
        break;
    case 2:
        if (vayCreate->count >= 0x10) {
            ayDrawMain(&texData[2]);
            if (vayCreate->count == 0x20) {
                next = 1;
                vayCreate->step = 3;
            }
        }
        if (vayCreate->count == 0x10) {
            spinitInitCreateCharacter(&vspenvSecret->create_character[vayCreate->select[0]]);
        }
        break;
    case 4:
        if (vayCreate->count < 0x10) {
            ayDrawMain(&texData[2]);
        } else if (vayCreate->count == 0x20) {
            next = 1;
            vayCreate->step = 1;
        }
        break;
    case 3:
        ayDrawMain(&texData[2]);
        if (vaySelData->bocount == -1) {
            if ((vgmsysPad[0]->trg & 0x40) && (vayCreate->confFlg == -1)) {
                switch (vayCreate->select[1]) {
                case 0:
                    nmvcPlayButton(0);
                    vayCreate->step = 5;
                    if (vayCreate->select[2] == 0xC) {
                        vayCreate->select[3] = 0x4A;
                    } else {
                        vayCreate->select[3] = 0;
                    }
                    break;
                case 3:
                    vayCreate->moveFlg = -1;
                    vayCreate->moveDir = 0;
                    vayCreate->moveCnt = 0;
                    vayCreate->dispsel = 0;
                    vayCreate->disp = 0;
                case 1:
                    nmvcPlayButton(0);
                    vayCreate->step = 8;
                    vayCreate->select[3] = 0;
                    vayCreate->sex = vayCreate->chara->sex;
                    vayCreate->stance = vayCreate->chara->character.parameter.stance;
                    break;
                case 2:
                    nmvcPlayButton(0);
                    vayCreate->step = 9;
                    vayCreate->select[3] = 0;
                    aySetMotFlg(5);
                    vayCreate->moveFlg = -1;
                    vayCreate->moveDir = 0;
                    vayCreate->moveCnt = 0;
                    vayCreate->dispsel = 0;
                    vayCreate->disp = 0;
                    break;
                case 4:
                    if ((vayCreate->select[2] == 0) || (vayCreate->trickFlg == 0)) {
                        nmvcPlayButton(3);
                    } else {
                        nmvcPlayButton(0);
                        vayCreate->confBoard = 0;
                        vayCreate->moveCnt = 0;
                        vayCreate->moveFlg = -1;
                        if (vayCreate->chara->character.rem_point == 0) {
                            vayCreate->meskind = 2;
                            vayCreate->confFlg = 0;
                        } else {
                            vayCreate->meskind = 3;
                            vayCreate->confFlg = 1;
                        }
                    }
                    break;
                }
                next = 1;
            } else if ((vgmsysPad[0]->trg & 0x10) && (vayCreate->confFlg == -1)) {
                nmvcPlayButton(2);
                vayCreate->confBoard = 0;
                vayCreate->confFlg = 1;
                vayCreate->moveCnt = 0;
                vayCreate->moveFlg = -1;
                vayCreate->meskind = 1;
            }
        }
        break;
    case 5:
        ayDrawMain(&texData[2]);
        vayCreate->confBoard = vayCreate->count;
        if (vayCreate->count == 0x10) {
            next = 1;
            vayCreate->step = 6;
        }
        break;
    case 7:
        ayDrawMain(&texData[2]);
        vayCreate->confBoard = 0x10 - vayCreate->count;
        if (vayCreate->count == 0x10) {
            vayCreate->confBoard = -1;
            next = 1;
            vayCreate->step = 3;
        }
        break;
    case 6:
        ayDrawMain(&texData[2]);
        vayCreate->confBoard = 0x10;
        break;
    case 0x10:
        ayDrawMain(&texData[2]);
        if (vayCreate->count == 0x10) {
            next = 1;
            ayMcSetSaveFileID();
            vayCreate->step = 0x11;
        }
        break;
    case 0x11:
        ayDrawMain(&texData[2]);
        break;
    case 0x12:
        ayDrawMain(&texData[2]);
        if (vayCreate->count == 0x10) {
            next = 1;
            vayCreate->step = 3;
            vayCreate->moveCnt = 0;
            vayCreate->moveFlg = -1;
            vayCreate->meskind = 2;
            vayCreate->confFlg = 0;
        }
        break;
    case 9:
        if (vayCreate->count < 8) {
            ayDrawMain(&texData[2]);
        } else {
            ayDrawBuild(&texData[2]);
        }
        if (vayCreate->count == 0x10) {
            next = 1;
            vayCreate->step = 0xB;
        }
        break;
    case 0xF:
        if (vayCreate->count < 8) {
            ayDrawBuild(&texData[2]);
        } else {
            ayDrawMain(&texData[2]);
        }
        if (vayCreate->count == 0x10) {
            next = 1;
            vayCreate->step = 3;
            aySetMotFlg(0);
        }
        break;
    case 0xB:
        ayDrawBuild(&texData[2]);
        if (vayCreate->moveFlg == -1) {
            if (vgmsysPad[0]->trg & 0x40) {
                nmvcPlayButton(0);
                vayCreate->step = 0xF;
                next = 1;
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                vayCreate->step = 0xF;
                next = 1;
            }
        }
        break;
    case 8:
        if (vayCreate->count < 8) {
            ayDrawMain(&texData[2]);
        } else if (vayCreate->select[1] == 3) {
            ayDrawRem();
            ayDrawParam(&texData[2]);
        } else {
            ayDrawPerson(&texData[2]);
        }
        if (vayCreate->count == 0x10) {
            next = 1;
            switch (vayCreate->select[1]) {
            case 1:
                vayCreate->step = 0xA;
                break;
            case 3:
                vayCreate->step = 0xC;
                break;
            }
        }
        break;
    case 0xE:
        if (vayCreate->count < 8) {
            if (vayCreate->select[1] == 3) {
                ayDrawRem();
                ayDrawParam(&texData[2]);
            } else {
                ayDrawPerson(&texData[2]);
            }
        } else {
            ayDrawMain(&texData[2]);
        }
        if (vayCreate->count == 0x10) {
            next = 1;
            vayCreate->step = 3;
            aySetMotFlg(0);
        }
        break;
    case 0xA:
        ayDrawPerson(&texData[2]);
        if (vgmsysPad[0]->trg & 0x40) {
            nmvcPlayButton(0);
            vayCreate->step = 0xE;
            next = 1;
        } else if (vgmsysPad[0]->trg & 0x10) {
            nmvcPlayButton(2);
            vayCreate->step = 0xE;
            next = 1;
        }
        break;
    case 0xC:
        ayDrawRem();
        ayDrawParam(&texData[2]);
        if (vgmsysPad[0]->trg & 0x40) {
            nmvcPlayButton(0);
            vayCreate->step = 0xE;
            next = 1;
        } else if (vgmsysPad[0]->trg & 0x10) {
            nmvcPlayButton(2);
            vayCreate->step = 0xE;
            next = 1;
        }
        break;
    }
    if (next == 0) {
        vayCreate->count = (vayCreate->count + 1) & 0xFFFFFF;
    } else {
        vayCreate->count = 0;
    }
    if (bg) {
        ayDrawWheelItem();
    }
    if (vayCreate->confBoard != -1) {
        if (vayCreate->confBoard < 0x10) {
            ayBlackOutDraw(vayCreate->confBoard * 4);
        } else {
            ayBlackOutDraw(0x40);
        }
        ulgifTermPacket(vgmsysGifPkt);
        ulgifDmaSend(vgmsysGifPkt);
        sceGsSyncPath(0, 0);
        sceGifPkReset(vgmsysGifPkt);
        sceDmaSync(vulsysSystem.DmaGif, 0, 0);
        ulgraphAlphaSortPacket(vgmsysAbuf);
        ulgraphAlphaDrawPacket(vulsysSystem.DmaGif, vgmsysAbuf);
        sceDmaSync(vulsysSystem.DmaGif, 0, 0);
    }
    aySetKeyOparate();
    if ((vayCreate->step != 9) && (vayCreate->step != 0xB) && (vayCreate->step != 0xF)) {
        ayDrawHead();
    }
    if ((vayCreate->step >= 5) && (vayCreate->step < 8)) {
        ayDrawNameEntry();
    }
    if ((vayCreate->step == 0x11) && (vaySelData->bocount == -1)) {
        mc = ayMcCareerSave(vgmsysGifPkt);
        if (mc == 1) {
            vayCreate->count = 0;
            ret = 0xB;
        } else if (mc == 2) {
            vayCreate->step = 0x12;
            vayCreate->count = 0;
        }
    }
    if (vayCreate->confFlg > -1) {
        ret = ayDrawConfirm();
    }
    if ((vayCreate->step == 2) || (vayCreate->step == 4)) {
        if (vayCreate->count < 0x10) {
            ayBlackOutDraw(vayCreate->count << 3);
        } else {
            ayBlackOutDraw(0x80 - (vayCreate->count - 0x10) * 8);
        }
    }
    return ret;
}

// Matched 100%: https://decomp.me/scratch/XXDfa
void ayCreateClear() {
    signed int ii; // r16

    vayCreate->count = 0;
    vayCreate->step = 0;
    vayCreate->moveFlg = -1;
    vayCreate->moveDir = 0;
    vayCreate->moveCnt = 0;
    for (ii = 0; ii < 4; ii++) {
        vayCreate->select[ii] = 0;
    }
    for (ii = 0; ii < 6; ii++) {
        vayCreate->rem[ii] = 0;
    }
    vayCreate->disp = 0;
    vayCreate->dispsel = 0;
    vayCreate->nextSelect = 0;
    vayCreate->confFlg = -1;
    vayCreate->confBoard = -1;
    vayCreate->trickFlg = 0;
}

// Matched 100%: https://decomp.me/scratch/LrP41
static void aySetCharPtr() {
    signed int ii; // r16
    // Size: 0xEC, DWARF: 0x179681
    Created_Character* chara; // r17

    chara = &vspenvSecret->create_character[vayCreate->select[0]];
    vayCreate->chara = chara;
    for (ii = 0; ii < 0xB; ii++) {
        vayCreate->app[ii] = 0;
    }
    spinitInitCreateCharacter(chara);
}

// Matched 100%: https://decomp.me/scratch/HF77D
static void aySetCharParts() {
    // Size: 0xEC, DWARF: 0x179681
    Created_Character* chara; // r16

    chara = vayCreate->chara;
    chara->hair = vayCreate->app[0];
    chara->hair_color = vayCreate->app[1];
    chara->face = vayCreate->app[2];
    chara->body = vayCreate->app[3];
    chara->pants = vayCreate->app[3];
    chara->body_color = (vayCreate->app[5] + (vayCreate->app[4] * 4));
    chara->pants_color = (vayCreate->app[7] + (vayCreate->app[6] * 4));
    chara->glove = vayCreate->app[8];
    chara->boots = vayCreate->app[9];
    chara->board_type = vayCreate->app[10];
}

// Matched 100%: https://decomp.me/scratch/ABLeI
void ayCreateEnd() {
    ulFree(vayCreate);
}

static void ayDrawHead() {
    Poly* poly; // r21
    AlphaTag* alpha; // r22
    void* addr; // r19
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    TexData texData; // 0x190(r29)
    LoadData* loaddata; // r16
    signed int col = 0x80; // r20
    float dx; // 0x1A4(r29)
    signed int count = vayCreate->count; // r17
    signed int moveType = 0; // r18

    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    switch (vayCreate->step) {
    case 0x0:
        moveType = 1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0xA);
        data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        if (count < 0x1C) {
            col = (count << 7) / 0x1C;
        }
        break;
    case 0x1:
        moveType = 0;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0xA);
        data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        break;
    case 0x2:
        moveType = 2;
        if (count < 0x10) {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0xA);
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        } else {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        }
        break;
    case 0x4:
        moveType = 2;
        if (count < 0x10) {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        } else {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0xA);
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        }
        break;
    case 0x3:
        moveType = 0;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        break;
    case 0x5:
        moveType = 4;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        if (count < 8) {
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        } else {
            data.uv[0] = 0, data.uv[1] = 0xC0, data.uv[2] = 0x100, data.uv[3] = 0x100;
        }
        break;
    case 0x7:
        moveType = 4;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        if (count < 8) {
            data.uv[0] = 0, data.uv[1] = 0xC0, data.uv[2] = 0x100, data.uv[3] = 0x100;
        } else {
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        }
        break;
    case 0x6:
        moveType = 0;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        data.uv[0] = 0, data.uv[1] = 0xC0, data.uv[2] = 0x100, data.uv[3] = 0x100;
        break;
    case 0x10:
        moveType = 4;
        if (count < 8) {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        } else {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 7);
            data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
        }
        break;
    case 0x11:
        moveType = 0;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 7);
        data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
        break;
    case 0x12:
        moveType = 4;
        if (count < 8) {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 7);
            data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
        } else {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        }
        break;
    case 0x9:
        moveType = 4;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        if (count < 8) {
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        } else {
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        }
        break;
    case 0xF:
        moveType = 4;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        if (count < 8) {
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        } else {
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        }
        break;
    case 0xB:
        moveType = 0;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        break;
    case 0x8:
        moveType = 4;
        if (count < 8) {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        } else {
            switch (vayCreate->select[1]) {
            case 1:
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
                data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
                break;
            case 3:
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0xA);
                data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
                break;
            }
        }
        break;
    case 0xE:
        moveType = 4;
        if (count < 8) {
            switch (vayCreate->select[1]) {
            case 1:
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
                data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
                break;
            case 3:
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0xA);
                data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
                break;
            }
        } else {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        }
        break;
    case 0xA:
        moveType = 0;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 9);
        data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
        break;
    case 0xC:
        moveType = 0;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0xA);
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        break;
    }
    switch (moveType) {
    case 0:
        dx = 0.0f;
        break;
    case 1:
        if (count < 0x1C) {
            dx = -640.0f + ayCalcTotalMove(0x1D, (signed int)(count), 640.0f, 3);
        } else {
            dx = 0.0f;
        }
        break;
    case 2:
        if (count < 0x10) {
            dx = ayCalcTotalMove(0x11, count, 420.0f, 1);
        } else {
            dx = 420.0f - ayCalcTotalMove(0x11, count - 0x10, 420.0f, 3);
        }
        break;
    case 4:
        if (count < 8) {
            dx = ayCalcTotalMove(9, count, 420.0f, 1);
        } else {
            dx = 420.0f - ayCalcTotalMove(9, count - 8, 420.0f, 3);
        }
        break;
    }
    dx += 354.0f;
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 9);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.texdata = &texData;
    data.psmt = 0x14;
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
    xy[0] = dx, xy[1] = 5.0f, xy[2] = 256.0f + dx, xy[3] = 37.0f;
    if ((vayCreate->step == 9) || (vayCreate->step == 0xB) || (vayCreate->step == 0xF)) {
        aySetVert(data.vert[0], xy, 1);
    } else {
        aySetVert(data.vert[0], xy, 0xFFFFFF);
    }
    aySetPolyComFT4(poly, &data, 1);
}

static void ayDrawFileList() {
    signed int unused1;
    signed int ii; // r16
    signed int count = vayCreate->count; // r17
    signed int dx[12]; // 0xA0(r29)
    signed int fcol[4]; // 0xD0(r29)
    char* strList[3] = {"CREATE A", "NEU A", "CREER A"}; // 0x148(r29)
    char* str = strList[vspenvGame->language]; // r20
    signed int len[3] = {7, 4, 6}; // 0x158(r29)
    char date[32]; // 0xE0(r29)
    Created_Character* create; // r18
    char* mesList[3][5] = {{"CUSTOM BOARDER ROSTER", "FILE", "NAME ENTRY", "DATE", "NO DATA"}, {"EIGENEN BOARDER W\x8AHLEN", "DATEI", "NAMENSEINGABE", "DATUM", "KEINE DATEN"}, {"CHOIX SNOWBOARDER PERSO.", "FICHIER", "ENTREE NOM", "DATE", "AUCUNE DONNEE"}}; // 0x100(r29)
    char** mes = mesList[vspenvGame->language]; // r19

    switch (vayCreate->step) {
    case 0:
        for (ii = 0; ii < 0xC; ii++) {
            if (count < (ii + 1) * 3) {
                dx[ii] = -0x280;
            } else if (count < (ii + 1) * 3 + 0x1C) {
                dx[ii] = -640.0f + ayCalcTotalMove(0x1D, count - (ii + 1) * 3, 640.0f, 3);
            } else {
                dx[ii] = 0;
            }
        }
        break;
    case 1:
        for (ii = 0; ii < 0xC; ii++) {
            dx[ii] = 0;
        }
        if ((vayCreate->confFlg == -1) && (vaySelData->bocount == -1)) {
            if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                if (vayCreate->select[0] == 0) {
                    vayCreate->select[0] = 9;
                } else {
                    vayCreate->select[0]--;
                }
            } else if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                if (vayCreate->select[0] == 9) {
                    vayCreate->select[0] = 0;
                } else {
                    vayCreate->select[0]++;
                }
            }
        }
        break;
    case 2:
        for (ii = 0; ii < 0xC; ii++) {
            if (count < (ii + 1) * 3) {
                dx[ii] = 0;
            } else if (count < (ii + 1) * 3 + 0x1C) {
                dx[ii] = ayCalcTotalMove(0x1D, count - (ii + 1) * 3, 640.0f, 3);
            } else {
                dx[ii] = 0x280;
            }
        }
        break;
    case 4:
        for (ii = 0; ii < 0xC; ii++) {
            dx[ii] = 0;
        }
        break;
    }
    fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
    ayFontInit(0x1C, 0x1C, fcol);
    nmfontFPrint(vgmsysGifPkt, mes[0], dx[0] + 0x140 - nmfontGetPackStrLen(mes[0], 0x1C, 0) / 2, 0x4E);
    fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
    nmfontSetCol(fcol);
    nmfontSetSize(0x12, 0x12);
    nmfontFPrint(vgmsysGifPkt, mes[1], dx[1] + 0x64 - nmfontGetPackStrLen(mes[1], 0x12, 0) / 2, 0x70);
    nmfontFPrint(vgmsysGifPkt, mes[2], dx[1] + 0x102 - nmfontGetPackStrLen(mes[2], 0x12, 0) / 2, 0x70);
    nmfontFPrint(vgmsysGifPkt, mes[3], dx[1] + 0x1E0 - nmfontGetPackStrLen(mes[3], 0x12, 0) / 2, 0x70);
    nmfontSetSize(0x10, 0x10);
    for (ii = 0; ii < 0xA; ii++) {
        create = &vspenvSecret->create_character[ii];
        if (vayCreate->select[0] == ii) {
            fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
        } else {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }
        nmfontSetCol(fcol);
        str[len[vspenvGame->language]] = ii + 0x41;
        nmfontFPrint(vgmsysGifPkt, str, dx[ii + 2] + 0x64 - nmfontGetPackStrLen(str, 0x10, 0) / 2, ii * 0x14 + 0x8A);
        if (create->character.secret == 0) {
            nmfontFPrint(vgmsysGifPkt, mes[4], dx[ii + 2] + 0x17C - nmfontGetPackStrLen(mes[4], 0x10, 0) / 2, ii * 0x14 + 0x8A);
        } else {
            nmfontFPrint(vgmsysGifPkt, create->name, dx[ii + 2] + 0x102 - nmfontGetPackStrLen(create->name, 0x10, 0) / 2, ii * 0x14 + 0x8A);
            aySetTimeStr(date, &create->clock);
            nmfontFPrint(vgmsysGifPkt, date, dx[ii + 2] + 0x1E0 - nmfontGetPackStrLen(date, 0x10, 0) / 2, ii * 0x14 + 0x8A);
        }
    }
}

static void ayDrawChara() {
    signed int ii; // r16
    signed int count = vayCreate->count; // r17
    MdlEnv mdlEnv; // 0x70(r29)
    sceVu0FMATRIX mat; // 0x190(r29)
    float trans[4] = {90.0f, 132.0f, -100.0f, 1.0f}; // 0x1D0(r29)
    float rot[4] = {0.0f, 0.0f, 0.0f, 1.0f}; // 0x1E0(r29)
    float scale = 13.0f; // 0x318(r29)
    float translist[11][4] = {{159.0f, 579.0f, 152.0f, 1.0f}, {159.0f, 579.0f, 152.0f, 1.0f}, {159.0f, 579.0f, 152.0f, 1.0f}, {240.0f, 456.0f, 410.0f, 1.0f}, {240.0f, 456.0f, 410.0f, 1.0f}, {240.0f, 456.0f, 410.0f, 1.0f}, {196.0f, 210.0f, 239.0f, 1.0f}, {196.0f, 210.0f, 239.0f, 1.0f}, {180.0f, 337.0f, 176.0f, 1.0f}, {181.0f, 51.0f, 176.0f, 1.0f}, {90.0f, 132.0f, -100.0f, 1.0f}}; // 0x1F0(r29)
    float scalelist[11] = {34.0f, 34.0f, 34.0f, 34.0f, 34.0f, 34.0f, 34.0f, 34.0f, 34.0f, 34.0f, 13.0f}; // 0x2A0(r29)
    sceVu0FMATRIX worldScr; // 0x2D0(r29)

    aySetCamMatrix(worldScr, &mdlEnv, &mdlEnv.view_screen);
    aySetLightMatrix(mdlEnv.normal_light, mdlEnv.light_color, 0.2f, 0.25f);
    switch (vayCreate->step) {
    case 9:
        for (ii = 0; ii < 3; ii++) {
            trans[ii] += (translist[0][ii] - trans[ii]) * count / 16.0f;
        }
        scale += count * (scalelist[0] - scale) / 16.0f;
        break;
    case 15:
        for (ii = 0; ii < 3; ii++) {
            trans[ii] = translist[vayCreate->select[3]][ii] + count * (trans[ii] - translist[vayCreate->select[3]][ii]) / 16.0f;
        }
        scale = scalelist[vayCreate->select[3]] + count * (scale - scalelist[vayCreate->select[3]]) / 16.0f;
        break;
    case 11:
        if ((vayCreate->moveFlg == -1) || (vayCreate->moveFlg == 0xA)) {
            trans[0] = translist[vayCreate->select[3]][0], trans[1] = translist[vayCreate->select[3]][1], trans[2] = translist[vayCreate->select[3]][2], trans[3] = translist[vayCreate->select[3]][3];
            scale = scalelist[vayCreate->select[3]];
        } else {
            for (ii = 0; ii < 3; ii++) {
                trans[ii] = translist[vayCreate->select[3] - vayCreate->moveDir][ii] + vayCreate->moveCnt * (translist[vayCreate->select[3]][ii] - translist[vayCreate->select[3] - vayCreate->moveDir][ii]) / 8.0f;
            }
            scale = scalelist[vayCreate->select[3] - vayCreate->moveDir] + vayCreate->moveCnt * (scalelist[vayCreate->select[3]] - scalelist[vayCreate->select[3] - vayCreate->moveDir]) / 8.0f;
        }
        break;
    }
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixX(mat, mat, rot[0]);
    sceVu0RotMatrixY(mat, mat, rot[1]);
    sceVu0RotMatrixZ(mat, mat, rot[2]);
    sceVu0TransMatrix(mat, mat, trans);
    ul3dScaleMatrixXYZ(mat, scale, scale, scale);
    if (vayCreate->chara->sex == 1) {
        ul3dScaleMatrixXYZ(mat, 0.95f, 0.95f, 0.95f);
    }
    mdlEnv.fog.enable = 0;
    ayDrawCreateChara(vayCreate->chara, &mdlEnv, mat, vayCreate->count);
}

static void ayDrawNameEntry() {
    char str[4]; // 0xFC(r29)
    signed int ii; // r16
    signed int alpha[2]; // 0xD8(r29)
    signed int size; // r18
    signed int fcol[4]; // 0xA0(r29)
    signed int count = vayCreate->count; // 0x100(r29)
    char* entrylist[3] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,.!?'$+-=/",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,.!?'$+-=/\x90\x91\x92\x93\x94\x95\x96",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,.!?'$+-=/\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9A\x9B\x9C\x9D\x9E\x8E\x8F~\x7F\x9F"
    }; // 0xE0(r29)
    char* charlist = entrylist[vspenvGame->language]; // 0x104(r29)
    char* strList[3][3] = {{"SPC", "DEL", "END"}, {"SPC", "DEL", "END"}, {"SPC", "DEL", "END"}}; // 0xB0(r29)
    char** list = strList[vspenvGame->language]; // 0x108(r29)
    signed int totallist[3] = {74, 81, 94}; // 0xF0(r29)
    signed int total = totallist[vspenvGame->language]; // r17
    signed int lnum = (total + 2) / 13 + 1; // 0x10C(r29)
    signed int rest = total % 13; // r19

    nmfontInitOption();
    nmfontSetBil(1);
    switch (vayCreate->step) {
    case 5:
        alpha[0] = alpha[1] = count * 8;
        break;
    case 7:
        alpha[0] = alpha[1] = (0x10 - count) * 8;
        break;
    case 6:
        alpha[0] = 0x80;
        alpha[1] = count % 0x40;
        if (alpha[1] < 0x20) {
            alpha[1] *= 4;
        } else {
            alpha[1] = (0x40 - alpha[1]) * 4;
        }
        if (vayCreate->confFlg == -1) {
            if (vgmsysPad[0]->trg & 0x40) {
                if (vayCreate->select[3] == total - 2) {
                    if (vayCreate->select[2] == 0) {
                        nmvcPlayButton(3);
                    } else {
                        nmvcPlayButton(0);
                        vayCreate->chara->name[vayCreate->select[2]] = 0x20;
                        vayCreate->select[2] += 1;
                        if (vayCreate->select[2] == 0xC) {
                            vayCreate->select[3] = total;
                        }
                    }
                } else if (vayCreate->select[3] == total - 1) {
                    if (vayCreate->select[2] == 0) {
                        nmvcPlayButton(3);
                    } else {
                        nmvcPlayButton(2);
                        vayCreate->select[2]--;
                        vayCreate->chara->name[vayCreate->select[2]] = 0;
                    }
                } else if (vayCreate->select[3] == total) {
                    if (vayCreate->select[2] == 0) {
                        nmvcPlayButton(3);
                    } else {
                        nmvcPlayButton(0);
                        vayCreate->step = 7;
                        vayCreate->count = 0;
                        if (vayCreate->trickFlg == 0) {
                            vayCreate->trickFlg = 1;
                            vayCreate->chara->trick_type = ayGetTricktype(vayCreate->chara->name);
                        }
                    }
                } else {
                    nmvcPlayButton(0);
                    vayCreate->chara->name[vayCreate->select[2]] = charlist[vayCreate->select[3]];
                    vayCreate->select[2]++;
                    if (vayCreate->select[2] == 0xC) {
                        vayCreate->select[3] = total;
                    }
                }
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                vayCreate->step = 7;
                vayCreate->count = 0;
                if ((vayCreate->select[2] != 0) && (vayCreate->trickFlg == 0)) {
                    vayCreate->trickFlg = 1;
                    vayCreate->chara->trick_type = ayGetTricktype(vayCreate->chara->name);
                }
            } else if (vgmsysPad[0]->rep & 0x1000) {
                if (vayCreate->select[2] < 0xC) {
                    nmvcPlayCursor(1);
                    if (vayCreate->select[3] < rest - 2) {
                        vayCreate->select[3] += (lnum - 1) * 13;
                    } else if (vayCreate->select[3] < rest) {
                        vayCreate->select[3] = total - 2;
                    } else if (vayCreate->select[3] < rest + 2) {
                        vayCreate->select[3] = total - 1;
                    } else if (vayCreate->select[3] < rest + 4) {
                        vayCreate->select[3] = total;
                    } else if (vayCreate->select[3] < 0xD) {
                        vayCreate->select[3] += (lnum - 2) * 13;
                    } else if (vayCreate->select[3] == total - 1) {
                        vayCreate->select[3] -= 0xC;
                    } else if (vayCreate->select[3] == total) {
                        vayCreate->select[3] -= 0xB;
                    } else {
                        vayCreate->select[3] -= 0xD;
                    }
                }
            } else if (vgmsysPad[0]->rep & 0x4000) {
                if (vayCreate->select[2] < 0xC) {
                    nmvcPlayCursor(1);
                    if (vayCreate->select[3] >= (lnum - 1) * 13) {
                        if (vayCreate->select[3] == total - 1) {
                            vayCreate->select[3] = rest;
                        } else if (vayCreate->select[3] == total) {
                            vayCreate->select[3] = rest + 2;
                        } else {
                            vayCreate->select[3] = vayCreate->select[3] % 13;
                        }
                    } else if (vayCreate->select[3] >= (lnum - 2) * 13) {
                        if (vayCreate->select[3] % 13 < rest - 2) {
                            vayCreate->select[3] += 0xD;
                        } else if (vayCreate->select[3] % 13 < rest) {
                            vayCreate->select[3] = total - 2;
                        } else if (vayCreate->select[3] % 13 < rest + 2) {
                            vayCreate->select[3] = total - 1;
                        } else if (vayCreate->select[3] % 13 < rest + 4) {
                            vayCreate->select[3] = total;
                        } else {
                            vayCreate->select[3] = vayCreate->select[3] % 13;
                        }
                    } else {
                        vayCreate->select[3] += 0xD;
                    }
                }
            } else if (vgmsysPad[0]->rep & 0x2000) {
                nmvcPlayCursor(1);
                if (vayCreate->select[2] < 0xC) {
                    if (vayCreate->select[3] < total - lnum) {
                        if (vayCreate->select[3] % 13 == 0xC) {
                            vayCreate->select[3] -= 0xC;
                        } else {
                            vayCreate->select[3]++;
                        }
                    } else if (vayCreate->select[3] == total) {
                        vayCreate->select[3] -= total % 13;
                    } else {
                        vayCreate->select[3]++;
                    }
                } else if (vayCreate->select[3] == total) {
                    vayCreate->select[3] = total - 1;
                } else {
                    vayCreate->select[3] = total;
                }
            } else if (vgmsysPad[0]->rep & 0x8000) {
                nmvcPlayCursor(1);
                if (vayCreate->select[2] < 0xC) {
                    if (vayCreate->select[3] < total - rest) {
                        if (vayCreate->select[3] % 13 == 0) {
                            vayCreate->select[3] += 0xC;
                        } else {
                            vayCreate->select[3]--;
                        }
                    } else if (vayCreate->select[3] % 13 == 0) {
                        vayCreate->select[3] += rest;
                    } else {
                        vayCreate->select[3]--;
                    }
                } else if (vayCreate->select[3] == total) {
                    vayCreate->select[3] = total - 1;
                } else {
                    vayCreate->select[3] = total;
                }
            }
        }
        break;
    }
    nmfontSetSize(0x14, 0x14);
    nmfontSetPack(0);
    for (ii = 0; ii < 0xC; ii++) {
        if (vayCreate->select[2] == ii) {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = alpha[1];
        } else {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = alpha[0];
        }
        nmfontSetCol(fcol);
        if (vayCreate->chara->name[ii] == 0) {
            str[0] = 0x5F;
        } else {
            str[0] = vayCreate->chara->name[ii];
        }
        str[1] = 0;
        nmfontFPrint(vgmsysGifPkt, str, ii * 0x14 + 0xC8, 0x4E);
    }
    for (ii = 0; ii <= total - 3; ii++) {
        if (vayCreate->select[3] == ii) {
            size = 0x18;
            fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = alpha[1];
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = alpha[0];
        }
        nmfontSetSize(size, size);
        nmfontSetCol(fcol);
        str[0] = charlist[ii];
        nmfontFPrint(vgmsysGifPkt, str, ii % 13 * 0x24 + 0x64, ii / 13 * 0x24 + 0x74 - (size - 0x14) / 2);
    }
    nmfontSetPack(1);
    for (ii = 0; ii < 3; ii++) {
        if (vayCreate->select[3] == ii + total - 2) {
            size = 0x18;
            fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = alpha[1];
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = alpha[0];
        }
        nmfontSetSize(size, size);
        nmfontSetCol(fcol);
        ulstdSprintf(str, "%s", list[ii]);
        nmfontFPrint(vgmsysGifPkt, str, (total + ii * 2 - 2) % 13 * 0x24 + 0x64, (total + ii * 2 - 2) / 13 * 0x24 + 0x74 - (size - 0x14) / 2);
    }
}

static void ayDrawWheelItem() {
    Poly* poly; // r21
    AlphaTag* alpha; // r22
    void* addr; // r20
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    signed int col; // r17
    signed int count; // r18
    TexData texData[2]; // 0x190(r29)
    LoadData* loaddata; // r16
    signed int kind = 0; // r19

    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData[0].tofs = texData[1].tofs = -1;
    texData[0].cofs = texData[1].cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[0], 3);
    data.psmt = 0x14;
    switch (vayCreate->step) {
    case 8:
        count = vayCreate->count;
        if (vayCreate->select[1] == 1) {
            if (count < 8) {
                col = 0x80 - (count << 4);
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
                data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
                xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
            } else {
                data.uv[0] = (vayCreate->chara->sex ^ 1) << 7, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x80, data.uv[3] = 0x100;
                xy[0] = 50.0f, xy[1] = 9.0f, xy[2] = 128.0f + xy[0], xy[3] = 128.0f + xy[1];
                data.psmt = 0x13;
                col = (count - 8) << 4;
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 0x34);
            }
        } else {
            col = 0x80;
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
            xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
        }
        break;
    case 0xA:
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 0x34);
        data.psmt = 0x13;
        xy[0] = 50.0f, xy[1] = 9.0f, xy[2] = 128.0f + xy[0], xy[3] = 128.0f + xy[1];
        data.uv[0] = (vayCreate->chara->sex ^ 1) << 7, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x80, data.uv[3] = 0x100;
        if (vayCreate->select[3] == 0) {
            if (vayCreate->moveFlg < 0) {
                col = 0x80;
            } else if (vayCreate->moveFlg < 4) {
                col = 0x80 - (vayCreate->moveFlg << 5);
            } else {
                col = (vayCreate->moveFlg - 4) << 5;
            }
        } else {
            col = 0x80;
        }
        break;
    case 0xE:
        count = vayCreate->count;
        if (vayCreate->select[1] == 1) {
            if (count < 8) {
                col = 0x80 - (count << 4);
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 0x34);
                data.uv[0] = (vayCreate->chara->sex ^ 1) << 7, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x80, data.uv[3] = 0x100;
                xy[0] = 50.0f, xy[1] = 9.0f, xy[2] = 128.0f + xy[0], xy[3] = 128.0f + xy[1];
                data.psmt = 0x13;
            } else {
                col = (count - 8) << 4;
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
                data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
                xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
            }
        } else {
            col = 0x80;
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
            xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
        }
        break;
    case 0xB:
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
        if ((vayCreate->select[3] == 0xA) || (vayCreate->select[3] - vayCreate->moveDir == 0xA)) {
            if (vayCreate->moveFlg == -1) {
                data.psmt = 0x13;
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayCreate->app[10] + 0x1E);
                xy[0] = 56.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                col = 0x80;
                kind = 1;
            } else if (vayCreate->moveFlg == 0xA) {
                data.psmt = 0x13;
                count = vayCreate->moveCnt;
                xy[0] = 56.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                kind = 1;
                if (count < 4) {
                    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayCreate->app[10] + 0x1E - vayCreate->moveDir);
                    col = 0x80 - (count << 8) / 8;
                } else {
                    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayCreate->app[10] + 0x1E);
                    col = (count - 4 << 8) / 8;
                }
            } else {
                count = vayCreate->moveCnt;
                if (vayCreate->moveDir < 0) {
                    if (count < 4) {
                        data.psmt = 0x13;
                        xy[0] = 56.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayCreate->app[10] + 0x1E);
                        col = 0x80 - (vayCreate->moveCnt << 7) / 8;
                        kind = 1;
                    } else {
                        xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
                        col = (vayCreate->moveCnt << 7) / 8;
                    }
                } else {
                    if (count < 4) {
                        xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                        col = 0x80 - (vayCreate->moveCnt << 7) / 8;
                        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
                    } else {
                        data.psmt = 0x13;
                        xy[0] = 56.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayCreate->app[10] + 0x1E);
                        col = (vayCreate->moveCnt << 7) / 8;
                        kind = 1;
                    }
                }
            }
        } else {
            xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
            col = 0x80;
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
        }
        break;
    case 0xF:
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
        if (vayCreate->select[3] == 0xA) {
            count = vayCreate->count;
            if (count < 8) {
                xy[0] = 56.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayCreate->app[10] + 0x1E);
                col = 0x80 - (vayCreate->count << 4);
                kind = 1;
            } else {
                xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
                count = vayCreate->count;
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
            }
        } else {
            xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
            col = 0x80;
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
        }
        break;
    default:
        col = 0x80;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 1);
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
        xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
        break;
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.texdata = &texData[1];
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly + kind, &data, 1);
    data.texdata = &texData[0];
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x100;
    xy[0] = 0.0f, xy[1] = 0.0f, xy[2] = 256.0f, xy[3] = 128.0f;
    data.psmt = 0x14;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly + (kind ^ 1), &data, 1);
}

static void ayDrawMain(TexData* texData) {
    Poly* poly; // r19
    AlphaTag* alpha; // 0x1E4(r29)
    void* addr; // 0x1E8(r29)
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    float dx; // 0x1EC(r29)
    signed int col[4]; // 0x190(r29)
    signed int ii; // r16
    signed int count = vayCreate->count; // r17
    char* strList[3][5] = {{"ENTER NAME", "PERSONAL DATA", "BUILD", "STATS", "SAVE&CONTINUE"}, {"NAME EINGEBEN", "PERS\x92NLICHE DATEN", "AUSSEHEN", "STATISTIKEN", "SPEICHERN&WEITER"}, {"ENTRER NOM", "DONNEES PERSO", "APPARENCE", "STATS", "SAUV. ET CONTINUER"}};
    char** str = strList[vspenvGame->language]; // r18

    if ((vayCreate->step == 3) && (vaySelData->bocount == -1) && (vayCreate->confFlg == -1)) {
        if (vgmsysPad[0]->rep & 0x1000) {
            nmvcPlayCursor(1);
            vayCreate->select[1] = ayCalcNextID(vayCreate->select[1], 5, -1);
        } else if (vgmsysPad[0]->rep & 0x4000) {
            nmvcPlayCursor(1);
            vayCreate->select[1] = ayCalcNextID(vayCreate->select[1], 5, 1);
        }
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x48);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.psmt = 0x14;
    data.texdata = texData;
    for (ii = 0; ii < 5; ii++) {
        if (vayCreate->select[1] == ii) {
            col[0] = 0x78, col[1] = 0x50, col[2] = 0x2C, col[3] = 0x80;
        } else {
            col[0] = 0x80, col[1] = 0x80, col[2] = 0x80, col[3] = 0x80;
        }
        if ((ii == 4) && ((vayCreate->trickFlg == 0) || (vayCreate->select[2] == 0))) {
            col[0] = col[0] / 2;
            col[1] = col[1] / 2;
            col[2] = col[2] / 2;
        }
        data.col[0][0] = col[0], data.col[0][1] = col[1], data.col[0][2] = col[2], data.col[0][3] = col[3];
        switch (vayCreate->step) {
        case 2:
        case 4:
            if (count < ii) {
                dx = 0.0f;
            } else if (count < ii + 8) {
                dx = ayCalcTotalMove(9, count - ii, -256.0f, 3);
            } else if (count < ii + 0x10) {
                dx = -256.0f;
            } else if (count < ii + 0x18) {
                dx = ayCalcTotalMove(9, count - ii - 0x10, 256.0f, 1) - 256.0f;
            } else {
                dx = 0.0f;
            }
            break;
        case 0xE:
        case 0xF:
        case 8:
        case 9:
            dx = ayCalcBarMove(count, ii);
            break;
        default:
            dx = 0.0f;
            break;
        }
        data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0x100, data.uv[3] = 0x80;
        xy[0] = dx, xy[1] = 97.0f + 20.0f * (float)ii, xy[2] = 256.0f + dx, xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFE);
        aySetPolyComFT4(poly + ii * 2, &data, 1);
        data.uv[0] = 0, data.uv[1] = 0x21, data.uv[2] = 0x100, data.uv[3] = 0x40;
        xy[0] = dx, xy[1] = 96.0f + 20.0f * (float)ii, xy[2] = 256.0f + dx, xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (ii * 2 + 1), &data, 1);
        ayFontInit(0xE, 0x14, col);
        xy[0] = 216.0f + dx - (float)nmfontGetPackStrLen(str[ii], 0xE, 0), xy[1] = 198.0f + 40.0f * (float)ii, xy[2] = 16777215.0f, xy[3] = 1.0f;
        nmfontFPrintF(vgmsysGifPkt, str[ii], xy);
    }
}

static void ayDrawPerson(TexData* texData) {
    Poly* poly; // r17
    Poly2* poly2; // r19
    AlphaTag* alpha; // 0x224(r29)
    void* addr; // 0x228(r29)
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    float dx; // 0x22C(r29)
    signed int col[4]; // 0x190(r29)
    signed int ii; // r16
    signed int count = vayCreate->count; // 0x230(r29)
    char* strList[3][3] = {{"SEX", "AGE", "STANCE"}, {"GESCHLECHT", "ALTER", "FUSSSTELLUNG"}, {"SEXE", "AGE", "POSITION"}}; // 0x1A0(r29)
    char** str = strList[vspenvGame->language]; // r18
    char* itemList[3][2][2] = {{{"MALE", "FEMALE"}, {"REGULAR", "GOOFY"}}, {{"M\x90NNLICH", "WEIBLICH"}, {"REGULAR", "GOOFY"}}, {{"HOMME", "FEMME"}, {"REGULAR", "GOOFY"}}}; // 0x1D0(r29)
    char* item[2][2]; // 0x200(r29)
    char age[4]; // 0x234(r29)
    float wxlst[3] = {0.0f, 58.0f, 0.0f}; // 0x218(r29)
    float wx = wxlst[vspenvGame->language]; // 0x238(r29)

    item = itemList[vspenvGame->language];

    if (vayCreate->step == 0xA) {
        if (vayCreate->moveFlg == -1) {
            if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                vayCreate->select[3] = ayCalcNextID(vayCreate->select[3], 3, -1);
            } else if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                vayCreate->select[3] = ayCalcNextID(vayCreate->select[3], 3, 1);
            } else if (vgmsysPad[0]->rep & 0x8000) {
                switch (vayCreate->select[3]) {
                case 0:
                    nmvcPlayCursor(1);
                    vayCreate->moveFlg = 0;
                    break;
                case 1:
                    if (vayCreate->chara->age >= 0xE) {
                        nmvcPlayCursor(1);
                        vayCreate->chara->age--;
                    }
                    break;
                case 2:
                    nmvcPlayCursor(1);
                    vayCreate->chara->character.parameter.stance ^= 1;
                    break;
                }
            } else if (vgmsysPad[0]->rep & 0x2000) {
                switch (vayCreate->select[3]) {
                case 0:
                    nmvcPlayCursor(1);
                    vayCreate->moveFlg = 0;
                    break;
                case 1:
                    if (vayCreate->chara->age < 0x1E) {
                        nmvcPlayCursor(1);
                        vayCreate->chara->age++;
                    }
                    break;
                case 2:
                    nmvcPlayCursor(1);
                    vayCreate->chara->character.parameter.stance ^= 1;
                    break;
                }
            }
        } else {
            vayCreate->moveFlg++;
            if (vayCreate->moveFlg == 4) {
                vayCreate->chara->sex ^= 1;
            } else if (vayCreate->moveFlg == 8) {
                vayCreate->moveFlg = -1;
            }
        }
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x49);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    poly2 = addr = poly + 9;
    data.psmt = 0x14;
    data.texdata = texData;
    for (ii = 0; ii < 3; ii++) {
        switch (vayCreate->step) {
        case 0xE:
        case 8:
            dx = ayCalcBarMove(count, ii);
            break;
        default:
            dx = 0.0f;
            break;
        }
        if (vayCreate->select[3] == ii) {
            col[0] = 0x78, col[1] = 0x50, col[2] = 0x2C, col[3] = 0x80;
            xy[0] = 140.0f + (dx + wx), xy[1] = 105.0f + 24.0f * (float)ii, xy[2] = 8.0f + xy[0], xy[3] = 6.0f + xy[1];
            aySetPolyComF3(poly2, xy, 0, 0x80);
            xy[0] = 242.0f + (dx + wx), xy[1] = 105.0f + 24.0f * (float)ii, xy[2] = 8.0f + xy[0], xy[3] = 6.0f + xy[1];
            aySetPolyComF3(poly2 + 1, xy, 1, 0x80);
        } else {
            col[0] = 0x80, col[1] = 0x80, col[2] = 0x80, col[3] = 0x80;
        }
        data.col[0][0] = col[0], data.col[0][1] = col[1], data.col[0][2] = col[2], data.col[0][3] = col[3];
        data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0x100, data.uv[3] = 0x80;
        xy[0] = dx, xy[1] = 97.0f + 24.0f * (float)ii, xy[2] = 256.0f + (dx + wx), xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFE);
        aySetPolyComFT4(poly + ii * 3, &data, 1);
        data.uv[0] = 0, data.uv[1] = 0x41, data.uv[2] = 0xD2, data.uv[3] = 0x60;
        xy[0] = dx + wx - 58.0f, xy[1] = 100.0f + 24.0f * (float)ii, xy[2] = 210.0f + xy[0], xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (ii * 3 + 1), &data, 1);
        data.uv[0] = 0xEC, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x20;
        xy[0] = 294.0f + dx + wx - 58.0f, xy[1] = 100.0f + 24.0f * (float)ii, xy[2] = 20.0f + xy[0], xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (ii * 3 + 2), &data, 1);
        ayFontInit(0x10, 0x14, col);
        xy[0] = 120.0f + dx + wx - (float)nmfontGetPackStrLen(str[ii], 0x10, 0), xy[1] = 206.0f + 48.0f * (float)ii, xy[2] = 16777215.0f, xy[3] = 1.0f;
        nmfontFPrintF(vgmsysGifPkt, str[ii], xy);
        nmfontSetSize(0xC, 0x14);
        switch (ii) {
        case 0:
            xy[0] = 194.0f + dx + wx - (float)nmfontGetPackStrLen(item[0][vayCreate->chara->sex], 0xC, 0) / 2.0f, xy[1] = 206.0f + 48.0f * (float)ii, xy[2] = 16777215.0f, xy[3] = 1.0f;
            nmfontFPrintF(vgmsysGifPkt, item[0][vayCreate->chara->sex], xy);
            break;
        case 1:
            ulstdSprintf(age, "%d", vayCreate->chara->age);
            xy[0] = 180.0f + dx + wx, xy[1] = 206.0f + 48.0f * (float)ii, xy[2] = 16777215.0f, xy[3] = 1.0f;
            nmfontFPrintF(vgmsysGifPkt, age, xy);
            break;
        case 2:
            xy[0] = 194.0f + dx + wx - (float)nmfontGetPackStrLen(item[1][vayCreate->chara->character.parameter.stance], 0xC, 0) / 2.0f, xy[1] = 206.0f + 48.0f * (float)ii, xy[2] = 16777215.0f, xy[3] = 1.0f;
            nmfontFPrintF(vgmsysGifPkt, item[1][vayCreate->chara->character.parameter.stance], xy);
            break;
        }
    }
}

static void ayDrawBuild(TexData* texData) {
    Poly* poly; // r19
    Poly2* poly2; // r21
    AlphaTag* alpha; // 0x950(r29)
    void* addr; // r22
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    float dx; // 0x954(r29)
    float dy = 0.0f; // 0x958(r29)
    signed int col[4]; // 0x190(r29)
    signed int a; // r18
    LoadData* loaddata; // 0x95C(r29)
    TexData tex; // 0x1A0(r29)
    signed int ii; // r16
    signed int tmp; // r17
    signed int count = vayCreate->count; // 0x960(r29)
    char selnum[11] = {4, 4, 9, 4, 2, 4, 2, 4, 4, 4, 10}; // 0x930(r29)
    char* strList[3][11] = {{"HAIR", "HAIR COLOR", "FACE", "BUILD", "JACKET", "JACKET COLOR", "PANTS", "PANTS COLOR", "GLOVES", "BOOTS", "BOARD"}, {"HAAR", "HAARFARBE", "GESICHT", "OUTFIT", "JACKE", "JACKENFARBE", "HOSE", "HOSENFARBE", "HANDSCHUHE", "STIEFEL", "BOARD"}, {"CHEVEUX", "COULEUR CHEVEUX", "VISAGE", "APPARENCE", "BLOUSON", "COULEUR BLOUSON", "PANTALON", "COULEUR PANTALON", "GANTS", "BOOTS", "PLANCHE"}}; // 0x1B0(r29)
    char** str = strList[vspenvGame->language]; // r20
    char* itemList[3][11][10] = {{{"TYPE1", "TYPE2", "TYPE3", "TYPE4"}, {"COLOR1", "COLOR2", "COLOR3", "COLOR4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4", "TYPE5", "TYPE6", "TYPE7", "TYPE8", "TYPE9"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4", "TYPE5"}, {"TYPE1", "TYPE2"}, {"COLOR1", "COLOR2", "COLOR3", "COLOR4"}, {"TYPE1", "TYPE2"}, {"COLOR1", "COLOR2", "COLOR3", "COLOR4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4", "TYPE5", "TYPE6", "TYPE7", "TYPE8", "TYPE9", "TYPE10"}}, {{"TYP1", "TYP2", "TYP3", "TYP4"}, {"FARBE1", "FARBE2", "FARBE3", "FARBE4"}, {"TYP1", "TYP2", "TYP3", "TYP4", "TYP5", "TYP6", "TYP7", "TYP8", "TYP9"}, {"TYP1", "TYP2", "TYP3", "TYP4", "TYP5"}, {"TYP1", "TYP2"}, {"FARBE1", "FARBE2", "FARBE3", "FARBE4"}, {"TYP1", "TYP2"}, {"FARBE1", "FARBE2", "FARBE3", "FARBE4"}, {"TYP1", "TYP2", "TYP3", "TYP4"}, {"TYP1", "TYP2", "TYP3", "TYP4"}, {"TYP1", "TYP2", "TYP3", "TYP4", "TYP5", "TYP6", "TYP7", "TYP8", "TYP9", "TYP10"}}, {{"TYPE1", "TYPE2", "TYPE3", "TYPE4"}, {"COULEUR1", "COULEUR2", "COULEUR3", "COULEUR4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4", "TYPE5", "TYPE6", "TYPE7", "TYPE8", "TYPE9"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4", "TYPE5"}, {"TYPE1", "TYPE2"}, {"COULEUR1", "COULEUR2", "COULEUR3", "COULEUR4"}, {"TYPE1", "TYPE2"}, {"COULEUR1", "COULEUR2", "COULEUR3", "COULEUR4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4"}, {"TYPE1", "TYPE2", "TYPE3", "TYPE4", "TYPE5", "TYPE6", "TYPE7", "TYPE8", "TYPE9", "TYPE10"}}}; // 0x240(r29)
    char* item[11][10]; // 0x770(r29)
    float wxlst[3] = {28.0f, 28.0f, 58.0f}; // 0x940(r29)
    float wx = wxlst[vspenvGame->language]; // 0x964(r29)

    item = itemList[vspenvGame->language];
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    tex.tofs = -1;
    tex.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &tex, 0x2A);
    if (vayCreate->step == 0xB) {
        if (vayCreate->moveFlg == -1) {
            if ((vgmsysPad[0]->rep & 0x1000) && (vayCreate->select[3] > 0)) {
                nmvcPlayCursor(1);
                vayCreate->moveDir = -1;
                vayCreate->select[3]--;
                if (vayCreate->dispsel > 0) {
                    vayCreate->dispsel--;
                    vayCreate->moveFlg = 0;
                } else {
                    vayCreate->moveFlg = 1;
                }
            } else if ((vgmsysPad[0]->rep & 0x4000) && (vayCreate->select[3] < 10)) {
                nmvcPlayCursor(1);
                vayCreate->moveDir = 1;
                vayCreate->select[3]++;
                if (vayCreate->dispsel < 4) {
                    vayCreate->dispsel++;
                    vayCreate->moveFlg = 0;
                } else {
                    vayCreate->moveFlg = 1;
                }
            } else if (vgmsysPad[0]->rep & 0x8000) {
                nmvcPlayCursor(1);
                tmp = vayCreate->select[3];
                if ((tmp == 3) && (vayCreate->chara->sex == 1)) {
                    vayCreate->app[tmp] = ayCalcNextID(vayCreate->app[tmp], 4, -1);
                } else {
                    vayCreate->app[tmp] = ayCalcNextID(vayCreate->app[tmp], selnum[tmp], -1);
                }
                aySetCharParts();
                if (vayCreate->select[3] == 0xA) {
                    if (vayCreate->app[10] == 9) {
                        vayCreate->moveDir = 9;
                    } else {
                        vayCreate->moveDir = -1;
                    }
                    vayCreate->moveFlg = 0xA;
                }
            } else if (vgmsysPad[0]->rep & 0x2000) {
                nmvcPlayCursor(1);
                tmp = vayCreate->select[3];
                if ((tmp == 3) && (vayCreate->chara->sex == 1)) {
                    vayCreate->app[tmp] = ayCalcNextID(vayCreate->app[tmp], 4, 1);
                } else {
                    vayCreate->app[tmp] = ayCalcNextID(vayCreate->app[tmp], selnum[tmp], 1);
                }
                aySetCharParts();
                if (vayCreate->select[3] == 0xA) {
                    if (vayCreate->app[10] == 0) {
                        vayCreate->moveDir = -9;
                    } else {
                        vayCreate->moveDir = 1;
                    }
                    vayCreate->moveFlg = 0xA;
                }
            }
        } else {
            vayCreate->moveCnt++;
            if (vayCreate->moveFlg == 1) {
                if (vayCreate->moveCnt == 1) {
                    vayCreate->disp += vayCreate->moveDir;
                }
                if (vayCreate->moveDir < 0) {
                    dy = 20.0f * (float)(vayCreate->moveFlg * vayCreate->moveCnt) / 8.0f - 20.0f;
                } else {
                    dy = 20.0f + -(20.0f * (float)(vayCreate->moveFlg * vayCreate->moveCnt)) / 8.0f;
                }
            }
            if (vayCreate->moveCnt == 8) {
                vayCreate->moveCnt = 0;
                vayCreate->moveDir = 0;
                vayCreate->moveFlg = -1;
                dy = 0.0f;
            }
        }
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x81);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    ((Poly*)addr) += 17;
    poly2 = addr;
    data.psmt = 0x14;
    data.texdata = texData;
    for (ii = 0; ii < 5; ii++) {
        tmp = ii + vayCreate->disp;
        switch (vayCreate->step) {
        case 0xF:
        case 9:
            dx = ayCalcBarMove(count, ii);
            break;
        default:
            dx = 0.0f;
            break;
        }
        if (vayCreate->dispsel == ii) {
            if (dy == 0.0f) {
                a = 0x80;
            } else {
                a = vayCreate->moveCnt << 4;
            }
            col[0] = 0x78, col[1] = 0x50, col[2] = 0x2C, col[3] = a;
            xy[0] = 140.0f + (dx + wx), xy[1] = 105.0f + 20.0f * (float)ii + dy, xy[2] = 8.0f + xy[0], xy[3] = 6.0f + xy[1];
            aySetPolyComF3(poly2, xy, 0, a);
            xy[0] = 242.0f + (dx + wx), xy[1] = 105.0f + 20.0f * (float)ii + dy, xy[2] = 8.0f + xy[0], xy[3] = 6.0f + xy[1];
            aySetPolyComF3(poly2 + 1, xy, 1, a);
        } else {
            col[0] = 0x80, col[1] = 0x80, col[2] = 0x80, col[3] = 0x80;
        }
        data.col[0][0] = col[0], data.col[0][1] = col[1], data.col[0][2] = col[2], data.col[0][3] = col[3];
        data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0x100, data.uv[3] = 0x80;
        xy[0] = dx, xy[1] = 97.0f + 20.0f * (float)ii + dy, xy[2] = 256.0f + (dx + wx), xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFE);
        aySetPolyComFT4(poly + ii * 3, &data, 1);
        data.uv[0] = 0, data.uv[1] = 0x41, data.uv[2] = 0xD2, data.uv[3] = 0x60;
        xy[0] = dx + wx - 58.0f, xy[1] = 100.0f + 20.0f * (float)ii + dy, xy[2] = 210.0f + xy[0], xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (ii * 3 + 1), &data, 1);
        data.uv[0] = 0xEC, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x20;
        xy[0] = 294.0f + dx + wx - 58.0f, xy[1] = 100.0f + 20.0f * (float)ii + dy, xy[2] = 20.0f + xy[0], xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (ii * 3 + 2), &data, 1);
        ayFontInit(0xC, 0x14, col);
        xy[0] = 120.0f + dx + wx - (float)nmfontGetPackStrLen(str[tmp], 0xC, 0), xy[1] = 198.0f + 40.0f * (float)ii + 2.0f * dy, xy[2] = 16777215.0f, xy[3] = 1.0f;
        nmfontFPrintF(vgmsysGifPkt, str[tmp], xy);
        ayFontInit(0xC, 0x14, col);
        xy[0] = 194.0f + dx + wx - (float)nmfontGetPackStrLen(item[tmp][vayCreate->app[tmp]], 0xC, 0) / 2.0f;
        nmfontFPrintF(vgmsysGifPkt, item[tmp][vayCreate->app[tmp]], xy);
    }
    data.texdata = &tex;
    if (vayCreate->step == 0xB) {
        a = vaySelData->count % 0x80;
        if (a < 0x40) {
            a = a * 2;
        } else {
            a = 0x80 - (a - 0x40) * 2;
        }
    } else {
        a = 0;
    }
    for (ii = 0; ii < 2; ii++) {
        if (((vayCreate->disp == 0) && (ii == 0)) || ((vayCreate->disp == 6) && (ii == 1))) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0;
        } else {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = a;
        }
        data.uv[0] = ii << 5, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x20;
        xy[0] = 256.0f + wx, xy[1] = 96.0f + 80.0f * (float)ii, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 1);
        aySetPolyComFT4(poly + (ii + 15), &data, 1);
    }
    if (dy != 0.0f) {
        data.texdata = texData;
        addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x17);
        alpha = ((AlphaTag*)addr)++;
        ulpktInitALPHA(alpha, 1);
        poly = addr;
        if (dy > 0.0f) {
            tmp = vayCreate->disp - 1;
            xy[0] = dx, xy[1] = 77.0f + dy, xy[2] = 256.0f + (dx + wx), xy[3] = 16.0f + xy[1];
        } else {
            tmp = vayCreate->disp + 5;
            xy[0] = dx, xy[1] = 197.0f + dy, xy[2] = 256.0f + (dx + wx), xy[3] = 16.0f + xy[1];
        }
        col[0] = 0x80, col[1] = 0x80, col[2] = 0x80, col[3] = 0x80 - (vayCreate->moveCnt << 4);
        data.col[0][0] = col[0], data.col[0][1] = col[1], data.col[0][2] = col[2], data.col[0][3] = col[3];
        dx = 0.0f;
        data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0x100, data.uv[3] = 0x80;
        aySetVert(data.vert[0], xy, 0xFFFFFE);
        aySetPolyComFT4(poly, &data, 1);
        data.uv[0] = 0, data.uv[1] = 0x41, data.uv[2] = 0xD2, data.uv[3] = 0x60;
        xy[0] = dx + wx - 58.0f, xy[1] = xy[1] - 1.0f, xy[2] = 210.0f + xy[0], xy[3] = xy[3] - 1.0f;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + 1, &data, 1);
        data.uv[0] = 0xEC, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x20;
        xy[0] = 294.0f + dx + wx - 58.0f, xy[2] = 20.0f + xy[0];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + 2, &data, 1);
        ayFontInit(0xC, 0x14, col);
        xy[0] = 120.0f + dx + wx - (float)nmfontGetPackStrLen(str[tmp], 0xC, 0), xy[1] = 6.0f + 2.0f * xy[1], xy[2] = 16777215.0f, xy[3] = 1.0f;
        nmfontFPrintF(vgmsysGifPkt, str[tmp], xy);
        ayFontInit(0xC, 0x14, col);
        xy[0] = 194.0f + dx + wx - (float)nmfontGetPackStrLen(item[tmp][vayCreate->app[tmp]], 0xC, 0) / 2.0f;
        nmfontFPrintF(vgmsysGifPkt, item[tmp][vayCreate->app[tmp]], xy);
    }
}

static void ayDrawParam(TexData* texData) {
    Poly* poly; // 0x1F8(r29)
    Poly3* poly2; // r23
    Poly2* poly3; // 0x1FC(r29)
    AlphaTag* alpha; // 0x200(r29)
    void* addr; // 0x204(r29)
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    float dx; // 0x208(r29)
    signed int col[4]; // 0x190(r29)
    signed int blink[4]; // 0x1A0(r29)
    signed int ii; // r16
    signed int jj; // r17
    signed int tmp; // r30
    signed int count = vayCreate->count; // 0x20C(r29)
    signed int bcol; // 0x210(r29)
    signed int* param; // r18
    signed int* max; // r22
    char* strList[3][5] = {{"ENTER NAME", "PERSONAL DATA", "BUILD", "STATS", "SAVE&CONTINUE"}, {"NAME EINGEBEN", "PERS\x92NLICHE DATEN", "AUSSEHEN", "STATISTIKEN", "SPEICHERN&WEITER"}, {"ENTRER NOM", "DONNEES PERSO", "APPARENCE", "STATS", "SAUV. ET CONTINUER"}}; // 0x1B0(r29)
    char** str = strList[vspenvGame->language]; // 0x214(r29)

    param = &vayCreate->chara->character.parameter;
    max = vayParamMax[10];
    tmp = vayCreate->select[3];
    if (vayCreate->step == 0xC) {
        if (vgmsysPad[0]->rep & 0x1000) {
            nmvcPlayCursor(1);
            tmp = vayCreate->select[3] = ayCalcNextID(tmp, 5, -1);
        } else if (vgmsysPad[0]->rep & 0x4000) {
            nmvcPlayCursor(1);
            tmp = vayCreate->select[3] = ayCalcNextID(tmp, 5, 1);
        } else if ((vgmsysPad[0]->rep & 0x8000) && (vayCreate->rem[tmp] > 0)) {
            nmvcPlayCursor(1);
            vayCreate->rem[tmp]--;
            vayCreate->chara->character.rem_point++;
        } else if ((vgmsysPad[0]->rep & 0x2000) && (vayCreate->rem[tmp] + param[tmp] < 5) && (vayCreate->chara->character.rem_point > 0)) {
            nmvcPlayCursor(1);
            vayCreate->rem[tmp]++;
            vayCreate->chara->character.rem_point--;
        }
    }
    bcol = count % 0x40;
    if (bcol < 0x20) {
        blink[0] = 0x80 + bcol * 127 / 32, blink[1] = 0x80, blink[2] = 0x80 - bcol * 96 / 32, blink[3] = 0x80;
    } else {
        bcol -= 0x20;
        blink[0] = 0xFF - bcol * 127 / 32, blink[1] = 0x80, blink[2] = bcol * 96 / 32 + 0x20, blink[3] = 0x80;
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, ((signed int)(max[5] * 0x40 + 0x500) + 0xF) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    ((Poly*)addr) += 10;
    poly2 = addr;
    ((Poly3*)addr) += max[5];
    poly3 = addr;
    data.psmt = 0x14;
    data.texdata = texData;
    for (ii = 0; ii < 5; ii++) {
        switch (vayCreate->step) {
        case 0xE:
        case 8:
            dx = ayCalcBarMove(count, ii);
            break;
        default:
            dx = 0.0f;
            break;
        }
        if (tmp == ii) {
            col[0] = 0x78, col[1] = 0x50, col[2] = 0x2C, col[3] = 0x80;
            xy[0] = 142.0f + dx, xy[1] = 101.0f + 20.0f * (float)ii, xy[2] = 150.0f + dx, xy[3] = 6.0f + xy[1];
            aySetPolyComF3(poly3, xy, 0, 0x80);
            xy[0] = 242.0f + dx, xy[1] = 101.0f + 20.0f * (float)ii, xy[2] = 250.0f + dx, xy[3] = 6.0f + xy[1];
            aySetPolyComF3(poly3 + 1, xy, 1, 0x80);
        } else {
            col[0] = 0x80, col[1] = 0x80, col[2] = 0x80, col[3] = 0x80;
        }
        data.col[0][0] = col[0], data.col[0][1] = col[1], data.col[0][2] = col[2], data.col[0][3] = col[3];
        data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0x100, data.uv[3] = 0x80;
        xy[0] = dx, xy[1] = 97.0f + 20.0f * (float)ii, xy[2] = 256.0f + dx, xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFE);
        aySetPolyComFT4(poly + ii * 2, &data, 1);
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x20;
        xy[0] = dx, xy[1] = 96.0f + 20.0f * (float)ii, xy[2] = 256.0f + dx, xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (ii * 2 + 1), &data, 1);
        ayFontInit(0x10, 0x14, col);
        xy[0] = 120.0f + dx - (float)nmfontGetPackStrLen(str[ii], 0x10, 0), xy[1] = 198.0f + 40.0f * (float)ii, xy[2] = 16777215.0f, xy[3] = 1.0f;
        nmfontFPrintF(vgmsysGifPkt, str[ii], xy);
        for (jj = 0; jj < max[ii]; jj++) {
            if (jj < param[ii]) {
                data.col[0][0] = 0xFF, data.col[0][1] = 0x80, data.col[0][2] = 0x20, data.col[0][3] = 0x80;
            } else if (jj < vayCreate->rem[ii] + param[ii]) {
                data.col[0][0] = blink[0], data.col[0][1] = blink[1], data.col[0][2] = blink[2], data.col[0][3] = blink[3];
            } else {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
            }
            xy[0] = 156.0f + dx + 8.0f * (float)jj, xy[1] = 101.0f + 20.0f * (float)ii, xy[2] = 5.0f + xy[0], xy[3] = 9.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComF4(poly2 + jj, &data);
        }
        poly2 += max[ii];
    }
}

static float ayCalcBarMove(signed int count, signed int id) {
    float dx; // 0x1C(r29)

    if (count < id) {
        dx = 0.0f;
    } else if (count < id + 4) {
        dx = ayCalcTotalMove(5, count - id, -256.0f, 3);
    } else if (count < id + 8) {
        dx = -256.0f;
    } else if (count < id + 12) {
        dx = ayCalcTotalMove(5, count - id - 8, 256.0f, 1) - 256.0f;
    } else {
        dx = 0.0f;
    }
    return dx;
}

static void ayDrawRem() {
    Poly* poly; // r20
    AlphaTag* alpha; // r21
    void* addr; // r18
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    TexData texData; // 0x190(r29)
    LoadData* loaddata; // r17
    signed int col; // r16
    signed int rem = vayCreate->chara->character.rem_point; // r19
    signed int fcol[4]; // 0x1A0(r29)
    char str[4]; // 0x1B4(r29)

    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x2B);
    switch (vayCreate->step) {
    case 8:
        col = (vayCreate->count - 8) * 16;
        break;
    case 0xE:
        col = 0x80 - vayCreate->count * 16;
        break;
    default:
        col = 0x80;
        break;
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 9);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.psmt = 0x14;
    fcol[0] = 0x80, fcol[1] = 0x20, fcol[2] = 0, fcol[3] = col;
    ayFontInit(0x10, 0x14, fcol);
    data.texdata = &texData;
    if (rem == 1) {
        data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x80, data.uv[3] = 0x80;
    } else {
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x40;
    }
    xy[0] = 270.0f, xy[1] = 177.0f, xy[2] = 398.0f, xy[3] = 209.0f;
    ulstdSprintf(str, "%2d", rem);
    nmfontFPrint(vgmsysGifPkt, str, 0x182 - nmfontGetPackStrLen(str, 0x10, 0), 0x168);
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly, &data, 1);
}

static signed int ayDrawConfirm() {
    signed int ret = 0; // r20
    signed int col[2][4] = {{0x80, 0x80, 0x80, 0x80}, {0x80, 0x60, 0x40, 0x80}}; // 0x90(r29)
    signed int ii; // r16
    signed int size; // r17
    char* str[4]; // 0xB0(r29)
    char name[16]; // 0xC0(r29)
    char* mesList[3][10] = {{"OVERWRITE EXISTING DATA?", "ALL DATA FOR THIS BOARDER", "WILL BE LOST! EXIT ANYWAY?", "SAVE BOARDER INTO CAREER?", "", "ARE YOU SURE YOU WANT TO CONTINUE?", "YOUR UNUSED POINTS WILL BE LOST!", "ARE YOU SURE YOU WANT TO DELETE", "%s?", ""}, {"BESTEHENDE DATEN \x94" "BERSCHREIBEN?", "ALLE DATEN F\x94R DIESEN BOARDER", "WERDEN GEL\x92SCHT. TROTZDEM VERLASSEN?", "BOARDER ZU KARRIERE SPEICHERN?", "", "SICHER FORTFAHREN?", "RESTLICHE PUNKTE GEHEN VERLOREN!", "WILLST DU SICHER L\x92SCHEN:", "%s?", ""}, {"ECRASER LES DONNEES EXISTANTES?", "TOUTES LES DONNEES DE CE SNOWBOARDER", "SERONT PERDUES! QUITTER?", "SAUVEGARDER LE SNOWBOARDER", "", "VEUX-TU VRAIMENT CONTINUER?", "TES POINTS INUTILISES SERONT PERDUS!", "VEUX-TU VRAIMENT SUPPRIMER", "%s?", "EN CARRIERE?"}}; // 0xD0(r29)
    char** mes = mesList[vspenvGame->language]; // r18
    char* confList[3][2] = {{"YES", "NO"}, {"JA", "NEIN"}, {"OUI", "NON"}}; // 0x150(r29)
    char** conf = confList[vspenvGame->language]; // r19
    float dx[4]; // 0x170(r29)

    str[2] = conf[0];
    str[3] = conf[1];
    switch (vayCreate->meskind) {
    case 0:
        str[0] = mes[0];
        str[1] = mes[4];
        break;
    case 1:
        str[0] = mes[1];
        str[1] = mes[2];
        break;
    case 2:
        str[0] = mes[3];
        str[1] = mes[9];
        break;
    case 3:
        str[0] = mes[5];
        str[1] = mes[6];
        break;
    case 4:
        str[0] = mes[7];
        str[1] = mes[8];
        break;
    }
    if (vayCreate->moveCnt < 0x10) {
        for (ii = 0; ii < 4; ii++) {
            if (vayCreate->moveCnt < ii) {
                dx[ii] = -640.0f;
            } else if (vayCreate->moveCnt < ii + 0xD) {
                dx[ii] = ayCalcTotalMove(0xE, vayCreate->moveCnt - ii, 640.0f, 1) - 640.0f;
            } else {
                dx[ii] = 0.0f;
            }
        }
        vayCreate->moveCnt++;
        if (vayCreate->confBoard < 0x10) {
            vayCreate->confBoard++;
        }
    } else if (vayCreate->moveCnt == 0x10) {
        for (ii = 0; ii < 4; ii++) {
            dx[ii] = 0.0f;
        }
        if (vayCreate->moveFlg == -1) {
            if ((vgmsysPad[0]->rep & 0x1000) || (vgmsysPad[0]->rep & 0x4000)) {
                nmvcPlayCursor(1);
                vayCreate->confFlg ^= 1;
                vayCreate->moveFlg = 0;
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                vayCreate->moveCnt = 0x11;
                vayCreate->nextSelect = vayCreate->step;
            } else if (vgmsysPad[0]->trg & 0x40) {
                nmvcPlayButton(0);
                vayCreate->moveCnt = 0x11;
                if (vayCreate->confFlg == 0) {
                    switch (vayCreate->meskind) {
                    case 0:
                        vayCreate->nextSelect = 2;
                        aySetCharPtr();
                        if (vspenvSecret->old_char == vayCreate->select[0] + 0xC) {
                            vspenvSecret->old_char = 0;
                        }
                        break;
                    case 1:
                        vayCreate->nextSelect = 4;
                        vayCreate->chara->character.secret = 0;
                        for (ii = 0; ii < 5; ii++) {
                            vayCreate->rem[ii] = 0;
                        }
                        break;
                    case 2:
                        vayCreate->nextSelect = 0x10;
                        vayCreate->chara->character.secret = 1;
                        spinitGetCreateClock(vayCreate->select[0]);
                        vayCreate->chara->character.parameter.ollie += vayCreate->rem[0];
                        vayCreate->chara->character.parameter.spin += vayCreate->rem[1];
                        vayCreate->chara->character.parameter.speed += vayCreate->rem[2];
                        vayCreate->chara->character.parameter.landing += vayCreate->rem[3];
                        vayCreate->chara->character.parameter.balance += vayCreate->rem[4];
                        for (ii = 0; ii < 5; ii++) {
                            vayCreate->rem[ii] = 0;
                        }
                        memcpy(&vayCreate->chara->init_param, &vayCreate->chara->character.parameter, 0x1C);
                        break;
                    case 3:
                        vayCreate->moveCnt = 0x10;
                        vayCreate->meskind = 2;
                        vayCreate->chara->character.rem_point = 0;
                        break;
                    case 4:
                        vayCreate->nextSelect = vayCreate->step;
                        spinitInitCreateCharacter(&vspenvSecret->create_character[vayCreate->select[0]]);
                        if (vspenvSecret->old_char == vayCreate->select[0] + 0xC) {
                            vspenvSecret->old_char = 0;
                        }
                        break;
                    }
                } else {
                    if (vayCreate->meskind == 2) {
                        ret = 0xB;
                        vayCreate->chara->character.secret = 1;
                        spinitGetCreateClock(vayCreate->select[0]);
                        vayCreate->chara->character.parameter.ollie += vayCreate->rem[0];
                        vayCreate->chara->character.parameter.spin += vayCreate->rem[1];
                        vayCreate->chara->character.parameter.speed += vayCreate->rem[2];
                        vayCreate->chara->character.parameter.landing += vayCreate->rem[3];
                        vayCreate->chara->character.parameter.balance += vayCreate->rem[4];
                        for (ii = 0; ii < 5; ii++) {
                            vayCreate->rem[ii] = 0;
                        }
                        memcpy(&vayCreate->chara->init_param, &vayCreate->chara->character.parameter, 0x1C);
                    }
                    vayCreate->nextSelect = vayCreate->step;
                }
            }
        } else {
            vayCreate->moveFlg++;
            if (vayCreate->moveFlg == 4) {
                vayCreate->moveFlg = -1;
            }
        }
    } else {
        for (ii = 0; ii < 4; ii++) {
            if (vayCreate->moveCnt < ii + 0x11) {
                dx[ii] = 0.0f;
            } else if (vayCreate->moveCnt < ii + 0x1E) {
                dx[ii] = ayCalcTotalMove(0xE, vayCreate->moveCnt - 0x11 - ii, -640.0f, 1);
            } else {
                dx[ii] = -640.0f;
            }
        }
        vayCreate->moveCnt++;
        vayCreate->confBoard--;
        if (vayCreate->moveCnt == 0x20) {
            vayCreate->confBoard = -1;
            vayCreate->confFlg = -1;
            vayCreate->step = vayCreate->nextSelect;
            vayCreate->count = 0;
        }
        if (vayCreate->nextSelect == 0x10) {
            vayCreate->confBoard = 0x10;
        }
    }
    nmfontInitOption();
    nmfontSetPack(1);
    for (ii = 0; ii < 4; ii++) {
        if (vayCreate->confFlg + 2 == ii) {
            if (vayCreate->moveFlg == -1) {
                size = 0x16;
            } else {
                size = 0x18;
            }
            nmfontSetCol(col[1]);
        } else {
            size = 0x14;
            nmfontSetCol(col[0]);
        }
        nmfontSetSize(size, size);
        if ((vayCreate->meskind == 4) && (ii == 1)) {
            ulstdSprintf(name, "%s?", vspenvSecret->create_character[vayCreate->select[0]].name);
            nmfontFPrint(vgmsysGifPkt, name, dx[ii] + (float)(0x140 - nmfontGetPackStrLen(name, size, 0) / 2), ii * 3 / 2 * 0x18 + 0xC2);
        } else {
            nmfontFPrint(vgmsysGifPkt, str[ii], dx[ii] + (float)(0x140 - nmfontGetPackStrLen(str[ii], size, 0) / 2), ii * 3 / 2 * 0x18 + 0xC2);
        }
    }
    return ret;
}

static void aySetKeyOparate() {
    signed int kind; // r16
    signed int count = vayCreate->count; // r18
    signed int flg = 0xA; // r17
    TexData texData; // 0x50(r29)
    LoadData* loaddata = sploadGetSelectData(); // r19

    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x28);
    switch (vayCreate->step) {
    case 0:
        count = count / 2;
        flg = -2;
        kind = 4;
        break;
    case 1:
        flg = 0;
        kind = 4;
        break;
    case 2:
        flg = 0;
        if (count < 0x10) {
            kind = 4;
        } else {
            kind = 1;
        }
        break;
    case 4:
        flg = 0;
        if (count < 0x10) {
            kind = 1;
        } else {
            kind = 4;
        }
        break;
    case 0x11:
        flg = 0;
        switch (ayMcGetStep()) {
        case 4:
            kind = 0;
            break;
        case 5:
            kind = 4;
            break;
        case 0xA:
            kind = 1;
            break;
        default:
            flg = 10;
            break;
        }
        break;
    default:
        flg = 0;
        kind = 1;
        break;
    }
    if (flg != 10) {
        ayDrawKeyOparate(kind, count, flg, &texData, vgmsysGifPkt);
    }
}

static signed int ayGetTricktype(char* name) {
    signed int jj; // r16
    char ch; // r17
    signed int cal = 0; // r18
    signed int ii; // r19
    char list[12] = {
        ',', '.', '!', '?',
        '#', '$', '+', '-',
        '=', '/', ' ', '\0'
    }; // 0x50(r29)

    for (ii = 0; name[ii] != 0; ii++) {
        ch = name[ii];
        
        // Converts each A-Z, a-z, 0-9 character into a number 0-9
        // Or if none of those, based on the special character used.
        if (ch >= 'A' && ch <= 'Z') {
            cal += (ch - 'A') % 10;
        } else if (ch >= 'a' && ch <= 'z') {
            cal += (ch - 'a') % 10;
        } else if ((ch >= '0') && (ch <= '9')) {
            cal += (ch - '0') % 10;
        } else {
            // Searches for the exact special character used
            // and uses it's index as the 0-9 value (with modulo).
            for (jj = 0; 11 > jj; jj++) {
                if (ch == list[jj]) {
                    cal += jj % 10;
                    break;
                }
            }
        }
    }

    // Depending on the final value, selects from a
    // set of 10 options.
    return cal % 10;
}


