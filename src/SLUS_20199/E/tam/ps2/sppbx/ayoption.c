// ayoption.c context
// Last updated 3/24/2025
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
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi
#pragma dont_inline on
#pragma padloop off

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

// ayoption.c structs ////////////////////////////////////////////////////////////////////

// Size: 0xE0, DWARF: 0x11E05D
typedef struct VayOptData
{
    signed int count; // Offset: 0x0, DWARF: 0x11E079
    signed int step; // Offset: 0x4, DWARF: 0x11E09B
    signed int select[4]; // Offset: 0x8, DWARF: 0x11E0BC
    signed int next; // Offset: 0x18, DWARF: 0x11E0E1
    signed int disp[4]; // Offset: 0x1C, DWARF: 0x11E102
    signed int dispSel[4]; // Offset: 0x2C, DWARF: 0x11E125
    signed int dispflg; // Offset: 0x3C, DWARF: 0x11E14B
    signed int movecnt; // Offset: 0x40, DWARF: 0x11E16F
    signed int moveflg; // Offset: 0x44, DWARF: 0x11E193
    char name[4]; // Offset: 0x48, DWARF: 0x11E1B7
    signed int se; // Offset: 0x4C, DWARF: 0x11E1DA
    signed int seflg; // Offset: 0x50, DWARF: 0x11E1F9
    signed int vib; // Offset: 0x54, DWARF: 0x11E21B
    signed int track; // Offset: 0x58, DWARF: 0x11E23B
    signed int trackcnt; // Offset: 0x5C, DWARF: 0x11E25D
    signed int trackdial; // Offset: 0x60, DWARF: 0x11E282
    signed int spcnt; // Offset: 0x64, DWARF: 0x11E2A8
    signed int lv[3]; // Offset: 0x68, DWARF: 0x11E2CA
    float spsize; // Offset: 0x74, DWARF: 0x11E2EB
    float scrY; // Offset: 0x78, DWARF: 0x11E30E
    signed int padlist[8]; // Offset: 0x7C, DWARF: 0x11E32F
    signed int movieFlg[17]; // Offset: 0x9C, DWARF: 0x11E355
} VayOptData;

// Size: 0x10, DWARF: 0x11BD26
typedef struct TexData
{
    signed short tofs; // Offset: 0x0, DWARF: 0x11BD41
    signed short cofs; // Offset: 0x2, DWARF: 0x11BD62
    signed short width; // Offset: 0x4, DWARF: 0x11BD83
    signed short height; // Offset: 0x6, DWARF: 0x11BDA5
    signed short tw; // Offset: 0x8, DWARF: 0x11BDC8
    signed short th; // Offset: 0xA, DWARF: 0x11BDE7
    signed short image_bit; // Offset: 0xC, DWARF: 0x11BE06
    signed short clut_bit; // Offset: 0xE, DWARF: 0x11BE2C
} TexData;

// Size: 0x4, DWARF: 0x120FE7
typedef struct Course
{
    signed int no; // Offset: 0x0, DWARF: 0x121003
} Course;

// Size: 0x10, DWARF: 0x11F8F4
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x11F910
    __int128* pBase; // Offset: 0x4, DWARF: 0x11F938
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x11F95D
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0x11F984
} VgmsysGifPkt;

// Size: 0x1C, DWARF: 0x11FBFC
typedef struct Chr_Param
{
    signed int ollie; // Offset: 0x0, DWARF: 0x11FC18
    signed int spin; // Offset: 0x4, DWARF: 0x11FC3A
    signed int speed; // Offset: 0x8, DWARF: 0x11FC5B
    signed int landing; // Offset: 0xC, DWARF: 0x11FC7D
    signed int balance; // Offset: 0x10, DWARF: 0x11FCA1
    signed int stability; // Offset: 0x14, DWARF: 0x11FCC5
    signed int stance; // Offset: 0x18, DWARF: 0x11FCEB
} Chr_Param;

// Size: 0x10, DWARF: 0x120175
typedef struct Brd_Param
{
    signed int speed; // Offset: 0x0, DWARF: 0x120191
    signed int stability; // Offset: 0x4, DWARF: 0x1201B3
    signed int balance; // Offset: 0x8, DWARF: 0x1201D9
    signed int turning; // Offset: 0xC, DWARF: 0x1201FD
} Brd_Param;

// Size: 0x3C, DWARF: 0x1209ED
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x120A09
    signed int player; // Offset: 0x4, DWARF: 0x120A28
    signed int wear; // Offset: 0x8, DWARF: 0x120A4B
    signed int board; // Offset: 0xC, DWARF: 0x120A6C
    // Size: 0x1C, DWARF: 0x11FBFC
    Chr_Param chr_param; // Offset: 0x10, DWARF: 0x120A8E
    // Size: 0x10, DWARF: 0x120175
    Brd_Param brd_param; // Offset: 0x2C, DWARF: 0x120AB6
} Character;

// Size: 0x74, DWARF: 0x11FF68
typedef struct Character_Career
{
    signed int secret; // Offset: 0x0, DWARF: 0x11FF84
    unsigned int board; // Offset: 0x4, DWARF: 0x11FFA7
    unsigned int course; // Offset: 0x8, DWARF: 0x11FFC9
    signed int rem_point; // Offset: 0xC, DWARF: 0x11FFEC
    signed int old_brd_no; // Offset: 0x10, DWARF: 0x120012
    signed int old_wear_no; // Offset: 0x14, DWARF: 0x120039
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x120061
    signed int soft[8]; // Offset: 0x38, DWARF: 0x12008A
    // Size: 0x1C, DWARF: 0x11FBFC
    Chr_Param parameter; // Offset: 0x58, DWARF: 0x1200AD
} Character_Career;

// Size: 0x18, DWARF: 0x121181
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x12119D
    signed int game_mode; // Offset: 0x4, DWARF: 0x1211C4
    signed int match_rule; // Offset: 0x8, DWARF: 0x1211EA
    signed int divide; // Offset: 0xC, DWARF: 0x121211
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x121234
} Mode;

// Size: 0xA0, DWARF: 0x11FDFC
typedef struct Game
{
    // Size: 0x4, DWARF: 0x120FE7
    Course course; // Offset: 0x0, DWARF: 0x11FE18
    // Size: 0x3C, DWARF: 0x1209ED
    Character character[2]; // Offset: 0x4, DWARF: 0x11FE3D
    // Size: 0x18, DWARF: 0x121181
    Mode mode; // Offset: 0x7C, DWARF: 0x11FE65
    signed int language; // Offset: 0x94, DWARF: 0x11FE88
    signed int ending; // Offset: 0x98, DWARF: 0x11FEAD
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x11FED0
} Game;

// Size: 0x60, DWARF: 0x11C043
typedef struct VaytblCredit
{
    char str[64]; // Offset: 0x0, DWARF: 0x11C05E
    signed int col[4]; // Offset: 0x40, DWARF: 0x11C080
    float size; // Offset: 0x50, DWARF: 0x11C0A2
    float ofs; // Offset: 0x54, DWARF: 0x11C0C3
} VaytblCredit;

// Size: 0x18, DWARF: 0x121B4A
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0x121B66
    signed int month; // Offset: 0x4, DWARF: 0x121B87
    signed int day; // Offset: 0x8, DWARF: 0x121BA9
    signed int hour; // Offset: 0xC, DWARF: 0x121BC9
    signed int minute; // Offset: 0x10, DWARF: 0x121BEA
    signed int second; // Offset: 0x14, DWARF: 0x121C0D
} Clock;

// Size: 0xEC, DWARF: 0x120CA6
typedef struct Create_Character
{
    // Size: 0x74, DWARF: 0x11FF68
    Character_Career character; // Offset: 0x0, DWARF: 0x120CC2
    // Size: 0x1C, DWARF: 0x11FBFC
    Chr_Param init_param; // Offset: 0x74, DWARF: 0x120CEA
    // Size: 0x18, DWARF: 0x121B4A
    Clock clock; // Offset: 0x90, DWARF: 0x120D13
    char name[16]; // Offset: 0xA8, DWARF: 0x120D37
    signed int age; // Offset: 0xB8, DWARF: 0x120D5A
    signed int sex; // Offset: 0xBC, DWARF: 0x120D7A
    signed int face; // Offset: 0xC0, DWARF: 0x120D9A
    signed int hair; // Offset: 0xC4, DWARF: 0x120DBB
    signed int hair_color; // Offset: 0xC8, DWARF: 0x120DDC
    signed int body; // Offset: 0xCC, DWARF: 0x120E03
    signed int body_color; // Offset: 0xD0, DWARF: 0x120E24
    signed int pants; // Offset: 0xD4, DWARF: 0x120E4B
    signed int pants_color; // Offset: 0xD8, DWARF: 0x120E6D
    signed int glove; // Offset: 0xDC, DWARF: 0x120E95
    signed int boots; // Offset: 0xE0, DWARF: 0x120EB7
    signed int board_type; // Offset: 0xE4, DWARF: 0x120ED9
    signed int trick_type; // Offset: 0xE8, DWARF: 0x120F00
} Create_Character;

// Size: 0x8, DWARF: 0x121832
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0, DWARF: 0x12184E
} CourseGap;

// Size: 0x38, DWARF: 0x11C12F
typedef struct File
{
    // Size: 0x18, DWARF: 0x121B4A
    Clock clock; // Offset: 0x0, DWARF: 0x11C14A
    char name[32]; // Offset: 0x18, DWARF: 0x11C16E
} File;

// Size: 0x20, DWARF: 0x11B653
typedef struct Record
{
    signed int chr_no; // Offset: 0x0, DWARF: 0x11B66E
    unsigned long score; // Offset: 0x8, DWARF: 0x11B691
    char name[16]; // Offset: 0x10, DWARF: 0x11B6B3
} Record;

// Size: 0xEF8, DWARF: 0x121026
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0x11FF68
    Character_Career character[12]; // Offset: 0x0, DWARF: 0x121042
    // Size: 0xEC, DWARF: 0x120CA6
    Create_Character create_character[10]; // Offset: 0x570, DWARF: 0x12106A
    // Size: 0x8, DWARF: 0x121832
    CourseGap course[8]; // Offset: 0xEA8, DWARF: 0x121099
    signed int tour_round; // Offset: 0xEE8, DWARF: 0x1210BE
    signed int old_char; // Offset: 0xEEC, DWARF: 0x1210E5
    signed int first_clear; // Offset: 0xEF0, DWARF: 0x12110A
} VspenvSecret;

// Size: 0x4, DWARF: 0x11C350
typedef struct Best_Time
{
    unsigned int time; // Offset: 0x0, DWARF: 0x11C36C
} Best_Time;

// Size: 0x48, DWARF: 0x11F782
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0x11F79E
    signed int disable; // Offset: 0x40, DWARF: 0x11F7C2
    signed int random; // Offset: 0x44, DWARF: 0x11F7E6
} Bgm;

// Size: 0x8, DWARF: 0x11E3A6
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0x11E3C2
    signed int bgm; // Offset: 0x4, DWARF: 0x11E3E1
} Volume;

// Size: 0x30, DWARF: 0x11E890
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x11E8AC
    signed int always_sp; // Offset: 0x4, DWARF: 0x11E8CD
    signed int perfect_b; // Offset: 0x8, DWARF: 0x11E8F3
    signed int super_spin; // Offset: 0xC, DWARF: 0x11E919
    signed int half_g; // Offset: 0x10, DWARF: 0x11E940
    signed int fast_motion; // Offset: 0x14, DWARF: 0x11E963
    signed int super_speed; // Offset: 0x18, DWARF: 0x11E98B
    signed int big_head; // Offset: 0x1C, DWARF: 0x11E9B3
    signed int metallic; // Offset: 0x20, DWARF: 0x11E9D8
    signed int mirror; // Offset: 0x24, DWARF: 0x11E9FD
    signed int replay_view; // Offset: 0x28, DWARF: 0x11EA20
    signed int partition; // Offset: 0x2C, DWARF: 0x11EA48
} Cheats;

// Size: 0x24, DWARF: 0x11C9D1
typedef struct Key_Config
{
    signed int vibration; // Offset: 0x0, DWARF: 0x11C9ED
    signed int spin_l; // Offset: 0x4, DWARF: 0x11CA13
    signed int spin_r; // Offset: 0x8, DWARF: 0x11CA36
    signed int stance; // Offset: 0xC, DWARF: 0x11CA59
    signed int revert; // Offset: 0x10, DWARF: 0x11CA7C
    signed int grind; // Offset: 0x14, DWARF: 0x11CA9F
    signed int grab; // Offset: 0x18, DWARF: 0x11CAC1
    signed int jump; // Offset: 0x1C, DWARF: 0x11CAE2
    signed int flip; // Offset: 0x20, DWARF: 0x11CB03
} Key_Config;

// Size: 0x114, DWARF: 0x11F9AF
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0x11C9D1
    Key_Config key_config[2]; // Offset: 0x0, DWARF: 0x11F9CB
    // Size: 0x30, DWARF: 0x11E890
    Cheats enable; // Offset: 0x48, DWARF: 0x11F9F4
    // Size: 0x30, DWARF: 0x11E890
    Cheats cheats; // Offset: 0x78, DWARF: 0x11FA19
    // Size: 0x8, DWARF: 0x11E3A6
    Volume volume; // Offset: 0xA8, DWARF: 0x11FA3E
    char name[16]; // Offset: 0xB0, DWARF: 0x11FA63
    signed int divide; // Offset: 0xC0, DWARF: 0x11FA86
    signed int tutorial; // Offset: 0xC4, DWARF: 0x11FAA9
    // Size: 0x48, DWARF: 0x11F782
    Bgm bgm; // Offset: 0xC8, DWARF: 0x11FACE
    unsigned int movie; // Offset: 0x110, DWARF: 0x11FAF0
} VspenvOption;

// Size: 0x8, DWARF: 0x11D7A1
typedef struct Pad_Data
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x11D7BD
    signed char lh; // Offset: 0x2, DWARF: 0x11D7DD
    signed char lv; // Offset: 0x3, DWARF: 0x11D7FC
    signed int analog; // Offset: 0x4, DWARF: 0x11D81B
} Pad_Data;

// Size: 0x1668, DWARF: 0x11C4A6
typedef struct MemCard
{
    // Size: 0x38, DWARF: 0x11C12F
    File file; // Offset: 0x0, DWARF: 0x11C4C2
    // Size: 0x20, DWARF: 0x11B653
    Record record[8][6]; // Offset: 0x38, DWARF: 0x11C4E5
    // Size: 0x4, DWARF: 0x11C350
    Best_Time best_time[8]; // Offset: 0x638, DWARF: 0x11C50A
    // Size: 0x114, DWARF: 0x11F9AF
    VspenvOption option; // Offset: 0x658, DWARF: 0x11C532
    // Size: 0xEF8, DWARF: 0x121026
    VspenvSecret secret; // Offset: 0x770, DWARF: 0x11C557
} MemCard;

// Size: 0x1690, DWARF: 0x11C1B9
typedef struct VaySelData
{
    signed int count; // Offset: 0x0, DWARF: 0x11C1D4
    signed int bocount; // Offset: 0x4, DWARF: 0x11C1F6
    signed int step; // Offset: 0x8, DWARF: 0x11C21A
    signed int nextMode; // Offset: 0xC, DWARF: 0x11C23B
    signed int mode; // Offset: 0x10, DWARF: 0x11C260
    // Size: 0x1668, DWARF: 0x11C4A6
    MemCard mc; // Offset: 0x18, DWARF: 0x11C281
    signed int bgmdiff; // Offset: 0x1680, DWARF: 0x11C2A2
    signed int bgm; // Offset: 0x1684, DWARF: 0x11C2C6
    signed int vcID; // Offset: 0x1688, DWARF: 0x11C2E6
    signed int vcTO; // Offset: 0x168C, DWARF: 0x11C307
} VaySelData;

// Size: 0x20, DWARF: 0x11DACB
typedef struct Key_Input
{
    signed int id; // Offset: 0x0, DWARF: 0x11DAE7
    unsigned int now; // Offset: 0x4, DWARF: 0x11DB06
    unsigned int status; // Offset: 0x8, DWARF: 0x11DB26
    unsigned int press; // Offset: 0xC, DWARF: 0x11DB49
    signed char right_h; // Offset: 0x10, DWARF: 0x11DB6B
    signed char right_v; // Offset: 0x11, DWARF: 0x11DB8F
    signed char left_h; // Offset: 0x12, DWARF: 0x11DBB3
    signed char left_v; // Offset: 0x13, DWARF: 0x11DBD6
    unsigned char l_right; // Offset: 0x14, DWARF: 0x11DBF9
    unsigned char l_left; // Offset: 0x15, DWARF: 0x11DC1D
    unsigned char l_up; // Offset: 0x16, DWARF: 0x11DC40
    unsigned char l_down; // Offset: 0x17, DWARF: 0x11DC61
    unsigned char r_up; // Offset: 0x18, DWARF: 0x11DC84
    unsigned char r_right; // Offset: 0x19, DWARF: 0x11DCA5
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x11DCC9
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x11DCEC
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x11DD0F
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x11DD2F
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x11DD4F
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x11DD6F
} Key_Input;

// Size: 0x60, DWARF: 0x11F5F3
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0x11DACB
    Key_Input now; // Offset: 0x0, DWARF: 0x11F60F
    // Size: 0x20, DWARF: 0x11DACB
    Key_Input old; // Offset: 0x20, DWARF: 0x11F631
    unsigned int port; // Offset: 0x40, DWARF: 0x11F653
    unsigned int slot; // Offset: 0x44, DWARF: 0x11F674
    unsigned int mode; // Offset: 0x48, DWARF: 0x11F695
    unsigned int trg; // Offset: 0x4C, DWARF: 0x11F6B6
    unsigned int rev; // Offset: 0x50, DWARF: 0x11F6D6
    unsigned int cnt; // Offset: 0x54, DWARF: 0x11F6F6
    unsigned int rep; // Offset: 0x58, DWARF: 0x11F716
    signed int state; // Offset: 0x5C, DWARF: 0x11F736
} VgmsysPad;

// Size: 0x2DCEC, DWARF: 0x11E54A
typedef struct Replay
{
    // Size: 0x38, DWARF: 0x11C12F
    File file; // Offset: 0x0, DWARF: 0x11E566
    signed int pid; // Offset: 0x38, DWARF: 0x11E589
    signed int num_frame; // Offset: 0x3C, DWARF: 0x11E5A9
    unsigned int game_time; // Offset: 0x40, DWARF: 0x11E5CF
    signed int endrun_frame; // Offset: 0x44, DWARF: 0x11E5F5
    // Size: 0x8, DWARF: 0x11D7A1
    Pad_Data pad_data[23400]; // Offset: 0x48, DWARF: 0x11E61E
    // Size: 0x24, DWARF: 0x11C9D1
    Key_Config key; // Offset: 0x2DB88, DWARF: 0x11E645
    // Size: 0xEC, DWARF: 0x120CA6
    Create_Character character; // Offset: 0x2DBAC, DWARF: 0x11E667
    // Size: 0x30, DWARF: 0x11E890
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0x11E68F
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0x11E6B4
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0x11E6D7
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0x11E6FA
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0x11E71E
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0x11E741
    // Size: 0x10, DWARF: 0x120175
    Brd_Param brd_param; // Offset: 0x2DCDC, DWARF: 0x11E767
} Replay;

// Size: 0x5D0E0, DWARF: 0x11F4F6
typedef struct VspenvEnv
{
    // Size: 0xA0, DWARF: 0x11FDFC
    Game game; // Offset: 0x0, DWARF: 0x11F512
    // Size: 0x1668, DWARF: 0x11C4A6
    MemCard mc; // Offset: 0xA0, DWARF: 0x11F535
    // Size: 0x2DCEC, DWARF: 0x11E54A
    Replay replay[2]; // Offset: 0x1708, DWARF: 0x11F556
} VspenvEnv;

// Size: 0x10, DWARF: 0x11D4CB
typedef struct A_Tag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x11D4E7
    unsigned int addr; // Offset: 0x4, DWARF: 0x11D50A
    unsigned int z; // Offset: 0x8, DWARF: 0x11D52B
    unsigned int _pad; // Offset: 0xC, DWARF: 0x11D549
} A_Tag;

// Size: 0x20, DWARF: 0x11DE5B
typedef struct VgmsysAbuf
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0x11DE77
    unsigned int natag; // Offset: 0x4, DWARF: 0x11DE9B
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0x11DEBD
    unsigned int npkt; // Offset: 0xC, DWARF: 0x11DEE0
    // Size: 0x10, DWARF: 0x11D4CB
    A_Tag* atag; // Offset: 0x10, DWARF: 0x11DF01
    // Size: 0x10, DWARF: 0x11D4CB
    A_Tag* curatag; // Offset: 0x14, DWARF: 0x11DF27
    __int128* pkt; // Offset: 0x18, DWARF: 0x11DF50
    __int128* curpkt; // Offset: 0x1C, DWARF: 0x11DF73
} VgmsysAbuf;

// Size: 0x20, DWARF: 0x11ED49
typedef struct Mdl_Data
{
    float pos[4]; // Offset: 0x0, DWARF: 0x11ED65
    float rot[4]; // Offset: 0x10, DWARF: 0x11ED87
} Mdl_Data;

// Size: 0x10, DWARF: 0x1202D4
typedef struct Pos
{
    unsigned int type; // Offset: 0x0, DWARF: 0x1202F0
    float frame; // Offset: 0x4, DWARF: 0x120311
    signed short flg; // Offset: 0x8, DWARF: 0x120333
    signed short non; // Offset: 0xA, DWARF: 0x120353
    float* data[4]; // Offset: 0xC, DWARF: 0x120373
} Pos;

// Size: 0xF0, DWARF: 0x11C580
typedef struct Seq
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0x11C59C
    signed int loop; // Offset: 0x4, DWARF: 0x11C5C1
    signed int mode; // Offset: 0x8, DWARF: 0x11C5E2
    signed int write_flg; // Offset: 0xC, DWARF: 0x11C603
    signed int now_local_id; // Offset: 0x10, DWARF: 0x11C629
    signed int now_top_id; // Offset: 0x14, DWARF: 0x11C652
    signed int next_local_id; // Offset: 0x18, DWARF: 0x11C679
    signed int next_top_id; // Offset: 0x1C, DWARF: 0x11C6A3
    // Size: 0x20, DWARF: 0x11ED49
    Mdl_Data* mdl_data; // Offset: 0x20, DWARF: 0x11C6CB
    float now_frame; // Offset: 0x24, DWARF: 0x11C6F5
    float next_frame; // Offset: 0x28, DWARF: 0x11C71B
    float ratio; // Offset: 0x2C, DWARF: 0x11C742
    // Size: 0x10, DWARF: 0x1202D4
    Pos* now_pos_address; // Offset: 0x30, DWARF: 0x11C764
    // Size: 0x10, DWARF: 0x1202D4
    Pos* now_rot_address; // Offset: 0x34, DWARF: 0x11C795
    // Size: 0x10, DWARF: 0x1202D4
    Pos* next_pos_address; // Offset: 0x38, DWARF: 0x11C7C6
    // Size: 0x10, DWARF: 0x1202D4
    Pos* next_rot_address; // Offset: 0x3C, DWARF: 0x11C7F8
    float nowDir[4]; // Offset: 0x40, DWARF: 0x11C82A
    float nowTrans[4]; // Offset: 0x50, DWARF: 0x11C84F
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0x11C876
    float pos[4]; // Offset: 0xA0, DWARF: 0x11C89F
    float quat[4]; // Offset: 0xB0, DWARF: 0x11C8C1
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0x11C8E4
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0x11C90A
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0x11C930
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0x11C95B
    signed int pad[2]; // Offset: 0xE8, DWARF: 0x11C985
} Seq;

// Size: 0x230, DWARF: 0x12052B
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

// Size: 0x2E0, DWARF: 0x11D3CF
typedef struct UmdCtrl
{
    float rot[4]; // Offset: 0x0, DWARF: 0x7CF35
    float trans[4]; // Offset: 0x10, DWARF: 0x7CF57
    float scale[4]; // Offset: 0x20, DWARF: 0x7CF7B
    float matrix[4][4]; // Offset: 0x30, DWARF: 0x7CF9F
    float revision[4][4]; // Offset: 0x70, DWARF: 0x7CFC4
    // Size: 0x230, DWARF: 0x81827
    IkParam ikparam; // Offset: 0xB0, DWARF: 0x7CFEB
} UmdCtrl;

// Size: 0x1A0, DWARF: 0x11B4CB
typedef struct SCtrl
{
    signed int type; // Offset: 0x0, DWARF: 0x11B4E6
    float power; // Offset: 0x4, DWARF: 0x11B507
    float dir; // Offset: 0x8, DWARF: 0x11B529
    float cnt; // Offset: 0xC, DWARF: 0x11B549
    float head[4]; // Offset: 0x10, DWARF: 0x11B569
    float preHead[4]; // Offset: 0x20, DWARF: 0x11B58C
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0x11B5B2
    float g_vector[4]; // Offset: 0x170, DWARF: 0x11B5DC
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0x11B603
    signed int pad[3]; // Offset: 0x194, DWARF: 0x11B62D
} SCtrl;

// Size: 0x20, DWARF: 0x121956
typedef struct Utd
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0x121972
    // Size: 0x10, DWARF: 0x11BD26
    TexData* tex; // Offset: 0x4, DWARF: 0x121995
    signed int ntex; // Offset: 0x8, DWARF: 0x1219BA
    signed int offset; // Offset: 0xC, DWARF: 0x1219DB
    signed int block; // Offset: 0x10, DWARF: 0x1219FE
    unsigned int* frame; // Offset: 0x14, DWARF: 0x121A20
    signed int res[2]; // Offset: 0x18, DWARF: 0x121A45
} Utd;

// Size: 0x90, DWARF: 0x11E466
typedef struct Change
{
    sceVu0FMATRIX original; // Offset: 0x0, DWARF: 0x11E482
    sceVu0FMATRIX original2; // Offset: 0x40, DWARF: 0x11E4A9
    sceVu0FMATRIX* address; // Offset: 0x80, DWARF: 0x11E4D1
    sceVu0FMATRIX* address2; // Offset: 0x84, DWARF: 0x11E4FA
    signed int pad[2]; // Offset: 0x88, DWARF: 0x11E524
} Change;

// Size: 0x960, DWARF: 0x11D5F5
typedef struct Character_Mdl
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x11D611
    unsigned char* vmd[2]; // Offset: 0x4, DWARF: 0x11D635
    // Size: 0xF0, DWARF: 0x11C580
    Seq* seq; // Offset: 0xC, DWARF: 0x11D657
    // Size: 0x2E0, DWARF: 0x11D3CF
    UmdCtrl ctrl[2]; // Offset: 0x10, DWARF: 0x11D67C
    // Size: 0x1A0, DWARF: 0x11B4CB
    SCtrl sctrl[2]; // Offset: 0x5D0, DWARF: 0x11D69F
    // Size: 0x20, DWARF: 0x121956
    Utd utd[2]; // Offset: 0x910, DWARF: 0x11D6C3
    // Size: 0x90, DWARF: 0x11E466
    Change* change[2]; // Offset: 0x950, DWARF: 0x11D6E5
} Character_Mdl;

// Size: 0x378, DWARF: 0x11EDF8
typedef struct Create_Chr
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x11EE14
    __int128* face_umd[9]; // Offset: 0x4, DWARF: 0x11EE38
    unsigned int* face_utd[9]; // Offset: 0x28, DWARF: 0x11EE5F
    // Size: 0x10, DWARF: 0x11BD26
    TexData* face_tex[9]; // Offset: 0x4C, DWARF: 0x11EE86
    // Size: 0xF0, DWARF: 0x11C580
    Seq* face_seq[9]; // Offset: 0x70, DWARF: 0x11EEAD
    __int128* hair_umd[4][2]; // Offset: 0x94, DWARF: 0x11EED4
    unsigned int* hair_utd[4][4][2]; // Offset: 0xB4, DWARF: 0x11EEFB
    // Size: 0x10, DWARF: 0x11BD26
    TexData* hair_tex[4][2]; // Offset: 0x134, DWARF: 0x11EF22
    // Size: 0xF0, DWARF: 0x11C580
    Seq* hair_seq[4]; // Offset: 0x154, DWARF: 0x11EF49
    __int128* body_umd[5]; // Offset: 0x164, DWARF: 0x11EF70
    unsigned int* body_utd[5][9]; // Offset: 0x178, DWARF: 0x11EF97
    // Size: 0x10, DWARF: 0x11BD26
    TexData* body_tex[5]; // Offset: 0x22C, DWARF: 0x11EFBE
    // Size: 0xF0, DWARF: 0x11C580
    Seq* body_seq[5]; // Offset: 0x240, DWARF: 0x11EFE5
    __int128* pants_umd[5]; // Offset: 0x254, DWARF: 0x11F00C
    unsigned int* pants_utd[5][8]; // Offset: 0x268, DWARF: 0x11F034
    // Size: 0x10, DWARF: 0x11BD26
    TexData* pants_tex[5]; // Offset: 0x308, DWARF: 0x11F05C
    // Size: 0xF0, DWARF: 0x11C580
    Seq* pants_seq[5]; // Offset: 0x31C, DWARF: 0x11F084
    __int128* glove_umd; // Offset: 0x330, DWARF: 0x11F0AC
    unsigned int* glove_utd[4]; // Offset: 0x334, DWARF: 0x11F0D5
    // Size: 0x10, DWARF: 0x11BD26
    TexData* glove_tex; // Offset: 0x344, DWARF: 0x11F0FD
    // Size: 0xF0, DWARF: 0x11C580
    Seq* glove_seq; // Offset: 0x348, DWARF: 0x11F128
    __int128* boots_umd; // Offset: 0x34C, DWARF: 0x11F153
    unsigned int* boots_utd[4]; // Offset: 0x350, DWARF: 0x11F17C
    // Size: 0x10, DWARF: 0x11BD26
    TexData* boots_tex; // Offset: 0x360, DWARF: 0x11F1A4
    // Size: 0xF0, DWARF: 0x11C580
    Seq* boots_seq; // Offset: 0x364, DWARF: 0x11F1CF
    __int128* board_umd; // Offset: 0x368, DWARF: 0x11F1FA
    unsigned int* board_utd; // Offset: 0x36C, DWARF: 0x11F223
    // Size: 0x10, DWARF: 0x11BD26
    TexData* board_tex; // Offset: 0x370, DWARF: 0x11F24C
    // Size: 0xF0, DWARF: 0x11C580
    Seq* board_seq; // Offset: 0x374, DWARF: 0x11F277
} Create_Chr;

// Size: 0x4B0, DWARF: 0x11BE7B
typedef struct Game2
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x11BE96
    __int128* umd; // Offset: 0x4, DWARF: 0x11BEBA
    __int128* smd; // Offset: 0x8, DWARF: 0x11BEDD
    unsigned int* utd; // Offset: 0xC, DWARF: 0x11BF00
    // Size: 0x10, DWARF: 0x11BD26
    TexData* tex; // Offset: 0x10, DWARF: 0x11BF23
    // Size: 0xF0, DWARF: 0x11C580
    Seq* seq; // Offset: 0x14, DWARF: 0x11BF48
    signed int block; // Offset: 0x18, DWARF: 0x11BF6D
    unsigned int* frame; // Offset: 0x1C, DWARF: 0x11BF8F
    signed int res; // Offset: 0x20, DWARF: 0x11BFB4
    // Size: 0x2E0, DWARF: 0x11D3CF
    UmdCtrl ctrl; // Offset: 0x30, DWARF: 0x11BFD4
    // Size: 0x1A0, DWARF: 0x11B4CB
    SCtrl sctrl; // Offset: 0x310, DWARF: 0x11BFF7
} Game2;

// Size: 0x16720, DWARF: 0x11B7F6
typedef struct Data
{
    unsigned int* link[2]; // Offset: 0x0, DWARF: 0x11B811
    signed int offset; // Offset: 0x8, DWARF: 0x11B834
    unsigned int* env_utd; // Offset: 0xC, DWARF: 0x11B857
    // Size: 0x10, DWARF: 0x11BD26
    TexData* env_tex; // Offset: 0x10, DWARF: 0x11B87E
    unsigned int* select_utd; // Offset: 0x14, DWARF: 0x11B8A7
    unsigned int* selmov_utd; // Offset: 0x18, DWARF: 0x11B8D1
    unsigned int* sponsor_utd; // Offset: 0x1C, DWARF: 0x11B8FB
    // Size: 0x10, DWARF: 0x11BD26
    TexData* sponsor_tex; // Offset: 0x20, DWARF: 0x11B926
    unsigned int* medal_utd; // Offset: 0x24, DWARF: 0x11B953
    // Size: 0x10, DWARF: 0x11BD26
    TexData* medal_tex; // Offset: 0x28, DWARF: 0x11B97C
    __int128* medal_umd[3]; // Offset: 0x2C, DWARF: 0x11B9A7
    __int128* board_umd; // Offset: 0x38, DWARF: 0x11B9CF
    unsigned char* board_vmd; // Offset: 0x3C, DWARF: 0x11B9F8
    unsigned int* board_utd; // Offset: 0x40, DWARF: 0x11BA21
    unsigned int* ayboard_utd; // Offset: 0x44, DWARF: 0x11BA4A
    // Size: 0x10, DWARF: 0x11BD26
    TexData* board_tex; // Offset: 0x48, DWARF: 0x11BA75
    unsigned int* emblem_utd; // Offset: 0x4C, DWARF: 0x11BAA0
    // Size: 0x10, DWARF: 0x11BD26
    TexData* emblem_tex; // Offset: 0x50, DWARF: 0x11BACA
    __int128* emblem_umd[2]; // Offset: 0x54, DWARF: 0x11BAF6
    __int128* select_uad; // Offset: 0x5C, DWARF: 0x11BB1F
    // Size: 0x960, DWARF: 0x11D5F5
    Character_Mdl character[12][3]; // Offset: 0x60, DWARF: 0x11BB49
    // Size: 0x378, DWARF: 0x11EDF8
    Create_Chr create_chr[2]; // Offset: 0x151E0, DWARF: 0x11BB71
    unsigned int* cr_arm_utd; // Offset: 0x158D0, DWARF: 0x11BB9A
    unsigned int* cr_leg_utd; // Offset: 0x158D4, DWARF: 0x11BBC4
    unsigned int* cr_arm_f_utd; // Offset: 0x158D8, DWARF: 0x11BBEE
    // Size: 0x4B0, DWARF: 0x11BE7B
    Game2 game; // Offset: 0x158E0, DWARF: 0x11BC1A
    // Size: 0x4B0, DWARF: 0x11BE7B
    Game2 wheel; // Offset: 0x15D90, DWARF: 0x11BC3D
    // Size: 0x4B0, DWARF: 0x11BE7B
    Game2 param; // Offset: 0x16240, DWARF: 0x11BC61
    __int128* pad_umd[9]; // Offset: 0x166F0, DWARF: 0x11BC85
    unsigned int* pad_utd; // Offset: 0x16714, DWARF: 0x11BCAB
    // Size: 0x10, DWARF: 0x11BD26
    TexData* pad_tex; // Offset: 0x16718, DWARF: 0x11BCD2
} Data;

// Size: 0xE0, DWARF: 0x1216F3
typedef struct ModelData
{
    signed int col[4][4]; // Offset: 0x0, DWARF: 0x12170F
    signed int vert[4][4]; // Offset: 0x40, DWARF: 0x121731
    signed int uv[4]; // Offset: 0x80, DWARF: 0x121754
    float stq[4][4]; // Offset: 0x90, DWARF: 0x121775
    // Size: 0x10, DWARF: 0x11BD26
    TexData* texdata; // Offset: 0xD0, DWARF: 0x121797
    unsigned long psmt; // Offset: 0xD8, DWARF: 0x1217C0
} ModelData;

// Size: 0x10, DWARF: 0x11CB75
typedef struct sceGifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0x11CB91, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0x11CBBD, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x11CBE7, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0x11CC13, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0x11CC3C, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0x11CC66, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0x11CC91, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0x11CCBB, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0x11CCE6, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0x11CD12, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0x11CD3E, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0x11CD6A, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0x11CD96, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0x11CDC2, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0x11CDEE, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0x11CE1A, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0x11CE46, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0x11CE72, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0x11CE9E, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0x11CECB, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0x11CEF8, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0x11CF25, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0x11CF52, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0x11CF7F, Bit Offset: 60, Bit Size: 4
} sceGifTag __attribute__((aligned(16)));

// Size: 0x10, DWARF: 0x11D56E
typedef union Giftag
{
    // Size: 0x10, DWARF: 0xF7F23
    sceGifTag sce; // Offset: 0x0, DWARF: 0xF8657
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0xF8679
} Giftag;


// Size: 0x8, DWARF: 0x12039D
typedef struct sceGsAlpha
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0x1203B9, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0x1203E1, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0x120409, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0x120431, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0x120459, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0x120484, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0x1204AE, Bit Offset: 40, Bit Size: 24
} sceGsAlpha;

// Size: 0x8, DWARF: 0x11F495
typedef union Alpha
{
    // Size: 0x8, DWARF: 0x12039D
    sceGsAlpha sce; // Offset: 0x0, DWARF: 0xF9F88
    unsigned long ul; // Offset: 0x0, DWARF: 0xF9FAA
} Alpha;

// Size: 0x20, DWARF: 0x11D341
typedef struct Alpha2
{
    // Size: 0x10, DWARF: 0x11CB75
    Giftag giftag; // Offset: 0x0, DWARF: 0xF7E41
    // Size: 0x8, DWARF: 0x11F495
    Alpha alpha; // Offset: 0x10, DWARF: 0xF7E66
    signed long reg_addr; // Offset: 0x18, DWARF: 0xF7E8A
} Alpha2;

// Size: 0x8, DWARF: 0x11F2A6
typedef struct sceGsPrim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0x11F2C2, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0x11F2ED, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0x11F317, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0x11F341, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0x11F36B, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0x11F395, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0x11F3BF, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0x11F3E9, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0x11F414, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0x11F43E, Bit Offset: 11, Bit Size: 53
} sceGsPrim;

// Size: 0x8, DWARF: 0x11DDFA
typedef union Prim
{
    // Size: 0x8, DWARF: 0x11F2A6
    sceGsPrim sce; // Offset: 0x0, DWARF: 0xF8FD6
    unsigned long ul; // Offset: 0x0, DWARF: 0xF8FF8
} Prim;

// Size: 0x8, DWARF: 0x11D868
typedef struct sceGsTex0
{
    unsigned long TBP0 : 14; // Offset: 0x0, DWARF: 0x11D884, Bit Offset: 0, Bit Size: 14
    unsigned long TBW : 6; // Offset: 0x0, DWARF: 0x11D8AF, Bit Offset: 14, Bit Size: 6
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x11D8D9, Bit Offset: 20, Bit Size: 6
    unsigned long TW : 4; // Offset: 0x0, DWARF: 0x11D903, Bit Offset: 26, Bit Size: 4
    unsigned long TH : 4; // Offset: 0x0, DWARF: 0x11D92C, Bit Offset: 30, Bit Size: 4
    unsigned long TCC : 1; // Offset: 0x0, DWARF: 0x11D955, Bit Offset: 34, Bit Size: 1
    unsigned long TFX : 2; // Offset: 0x0, DWARF: 0x11D97F, Bit Offset: 35, Bit Size: 2
    unsigned long CBP : 14; // Offset: 0x0, DWARF: 0x11D9A9, Bit Offset: 37, Bit Size: 14
    unsigned long CPSM : 4; // Offset: 0x0, DWARF: 0x11D9D3, Bit Offset: 51, Bit Size: 4
    unsigned long CSM : 1; // Offset: 0x0, DWARF: 0x11D9FE, Bit Offset: 55, Bit Size: 1
    unsigned long CSA : 5; // Offset: 0x0, DWARF: 0x11DA28, Bit Offset: 56, Bit Size: 5
    unsigned long CLD : 3; // Offset: 0x0, DWARF: 0x11DA52, Bit Offset: 61, Bit Size: 3
} sceGsTex0;

// Size: 0x8, DWARF: 0x11ECE8
typedef union Tex
{
    // Size: 0x8, DWARF: 0x11D868
    sceGsTex0 sce; // Offset: 0x0, DWARF: 0xF9C62
    unsigned long ul; // Offset: 0x0, DWARF: 0xF9C84
} Tex;

// Size: 0x8, DWARF: 0x120B06
typedef struct Color
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x120B22, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x120B4A, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x120B72, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0x120B9A, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0x120BC2
} Color;

// Size: 0x8, DWARF: 0x11E405
typedef union RGBAQ
{
    // Size: 0x8, DWARF: 0xFB90F
    Color sce; // Offset: 0x0, DWARF: 0xF92A9
    unsigned long ul; // Offset: 0x0, DWARF: 0xF92CB
} RGBAQ;

// Size: 0x8, DWARF: 0x121CC9
typedef struct scest
{
    float S; // Offset: 0x0, DWARF: 0xF6BC5
    float T; // Offset: 0x4, DWARF: 0xF6BE3
} scest;

// Size: 0x8, DWARF: 0x11C3DE
typedef struct sceuv
{
    unsigned long U : 14; // Offset: 0x0, DWARF: 0x11C3FA, Bit Offset: 0, Bit Size: 14
    unsigned long pad14 : 2; // Offset: 0x0, DWARF: 0x11C422, Bit Offset: 14, Bit Size: 2
    unsigned long V : 14; // Offset: 0x0, DWARF: 0x11C44E, Bit Offset: 16, Bit Size: 14
    unsigned long pad30 : 34; // Offset: 0x0, DWARF: 0x11C476, Bit Offset: 30, Bit Size: 34
} sceuv;

// Size: 0x8, DWARF: 0x11EBC6
typedef union stuv0
{
    // Size: 0x8, DWARF: 0x121CC9
    scest scest; // Offset: 0x0, DWARF: 0x11EBE2
    // Size: 0x8, DWARF: 0x11C3DE
    sceuv sceuv; // Offset: 0x0, DWARF: 0x11EC06
    unsigned long ul; // Offset: 0x0, DWARF: 0x11EC2A
} stuv0;

// Size: 0x8, DWARF: 0x11EAE0
typedef struct Coords
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x11EAFC, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x11EB24, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 24; // Offset: 0x0, DWARF: 0x11EB4C, Bit Offset: 32, Bit Size: 24
    unsigned long F : 8; // Offset: 0x0, DWARF: 0x11EB74, Bit Offset: 56, Bit Size: 8
} Coords;

// Size: 0x8, DWARF: 0x11E82F
typedef union XYZF
{
    // Size: 0x8, DWARF: 0x11EAE0
    Coords sce; // Offset: 0x0, DWARF: 0x11E84B
    unsigned long ul; // Offset: 0x0, DWARF: 0x11E86D
} XYZF;

// Size: 0x70, DWARF: 0x11D020
typedef struct Poly
{
    // Size: 0x10, DWARF: 0x11D56E
    Giftag giftag; // Offset: 0x0, DWARF: 0x11D03C
    // Size: 0x8, DWARF: 0x11DDFA
    Prim prim; // Offset: 0x10, DWARF: 0x11D061
    // Size: 0x8, DWARF: 0x11ECE8
    Tex tex0; // Offset: 0x18, DWARF: 0x11D084
    // Size: 0x8, DWARF: 0x11E405
    RGBAQ rgbaq0; // Offset: 0x20, DWARF: 0x11D0A7
    // Size: 0x8, DWARF: 0x11EBC6
    stuv0 stuv0; // Offset: 0x28, DWARF: 0x11D0CC
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf0; // Offset: 0x30, DWARF: 0x11D0F0
    // Size: 0x8, DWARF: 0x11EBC6
    stuv0 stuv1; // Offset: 0x38, DWARF: 0x11D114
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf1; // Offset: 0x40, DWARF: 0x11D138
    // Size: 0x8, DWARF: 0x11EBC6
    stuv0 stuv2; // Offset: 0x48, DWARF: 0x11D15C
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf2; // Offset: 0x50, DWARF: 0x11D180
    // Size: 0x8, DWARF: 0x11EBC6
    stuv0 stuv3; // Offset: 0x58, DWARF: 0x11D1A4
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf3; // Offset: 0x60, DWARF: 0x11D1C8
    unsigned long nop; // Offset: 0x68, DWARF: 0x11D1EC
} Poly;

// Size: 0x10, DWARF: 0x11B3E3
typedef struct FData
{
    float dx; // Offset: 0x0, DWARF: 0x11B3FE
    float dy; // Offset: 0x4, DWARF: 0x11B41D
    signed int size; // Offset: 0x8, DWARF: 0x11B43C
    signed int value; // Offset: 0xC, DWARF: 0x11B45D
} FData;

// Size: 0x2, DWARF: 0x120249
typedef struct ActData
{
    unsigned char act0; // Offset: 0x0, DWARF: 0x120265
    unsigned char act1; // Offset: 0x1, DWARF: 0x120286
} ActData;

// Size: 0x60, DWARF: 0x11DD93
typedef struct VibData
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x11DDAF
    char* data[23]; // Offset: 0x4, DWARF: 0x11DDD3
} VibData;

// Size: 0xC, DWARF: 0x12150E
typedef struct Fog
{
    signed int enable; // Offset: 0x0, DWARF: 0x12152A
    float a; // Offset: 0x4, DWARF: 0x12154D
    float b; // Offset: 0x8, DWARF: 0x12156B
} Fog;

// Size: 0x8, DWARF: 0x1215FE
typedef struct EnvMap
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x12161A
} EnvMap;

// Size: 0x8, DWARF: 0x12168C
typedef struct Toon
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x1216A8
} Toon;

// Size: 0x120, DWARF: 0x12125F
typedef struct MdlEnv
{
    float world_view[4][4]; // Offset: 0x0, DWARF: 0x12127B
    float view_screen[4][4]; // Offset: 0x40, DWARF: 0x1212A4
    float normal_light[4][4]; // Offset: 0x80, DWARF: 0x1212CE
    float light_color[4][4]; // Offset: 0xC0, DWARF: 0x1212F9
    // Size: 0xC, DWARF: 0x12150E
    Fog fog; // Offset: 0x100, DWARF: 0x121323
    union
    {
        // Size: 0x8, DWARF: 0x1215FE
        EnvMap envmap; // Offset: 0x110, DWARF: 0x121345
        // Size: 0x8, DWARF: 0x12168C
        Toon toon; // Offset: 0x110, DWARF: 0x12136A
    } toonlink;
} MdlEnv;

// Size: 0x40, DWARF: 0x11B6DA
typedef struct Poly2
{
    // Size: 0x10, DWARF: 0x11D56E
    Giftag giftag; // Offset: 0x0, DWARF: 0x11B6F5
    // Size: 0x8, DWARF: 0x11DDFA
    Prim prim; // Offset: 0x10, DWARF: 0x11B71A
    // Size: 0x8, DWARF: 0x11E405
    RGBAQ rgbaq0; // Offset: 0x18, DWARF: 0x11B73D
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf0; // Offset: 0x20, DWARF: 0x11B762
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf1; // Offset: 0x28, DWARF: 0x11B786
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf2; // Offset: 0x30, DWARF: 0x11B7AA
    // Size: 0x8, DWARF: 0x11E82F
    XYZF xyzf3; // Offset: 0x38, DWARF: 0x11B7CE
} Poly2;

//// Variables ///////////////////////////////////////////////////////////////////////

static char* vbgmtblMusic[12] = { "NEW DISEASE", "THIS IS NOT", "COURAGE", "WHEN YOU LIE", "DEAD CELL", "MAD FOR IT", "NATURAL HIGH", "DON'T BE AFRAID", "BOMBSHELL", "INSIDE YOU", "MOUTH FOR WAR", "THE EVIL POWERS OF ROCK 'N' ROLL" }; // Address: 0x2CCE50
static char* vbgmtblArtist[12] = { "SPINESHANK", "STATIC X", "ALIEN ANT FARM", "ORANGE 9MM", "PAPA ROACH", "SHOOTYZ GROOVE", "INSOLENCE", "STEREOMUD", "POWERMAN 5000", "GODHEAD", "PANTERA", "SUPERSUCKERS" }; // Address: 0x2CCE80
// Size: 0xE0, DWARF: 0x11E05D
VayOptData* vayOptData; // Address: 0x2E7BF8
signed int vayStateFlg; // Address: 0x2E7BB8
// Size: 0x5D0E0, DWARF: 0x11F4F6
VspenvEnv vspenvEnv; // Address: 0x3474D0
// Size: 0x114, DWARF: 0x11F9AF
VspenvOption* vspenvOption; // Address: 0x2E7B10
// Size: 0x60, DWARF: 0x11F5F3
VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30
// Size: 0x1690, DWARF: 0x11C1B9
VaySelData* vaySelData; // Address: 0x2E7BB4
// Size: 0x60, DWARF: 0x11C043
VaytblCredit vaytblCredit[652]; // Address: 0x2B8790
// Size: 0x10, DWARF: 0x11F8F4
VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
signed int vayMovKind; // Address: 0x2E7BE0
// Size: 0xA0, DWARF: 0x11FDFC
Game* vspenvGame; // Address: 0x2E7B14
char* vsptblMovieName[15]; // Address: 0x2B7F40
char* vsptblCheats[10]; // Address: 0x3A45B0
// Size: 0xEF8, DWARF: 0x121026
VspenvSecret* vspenvSecret; // Address: 0x2E7B04
char* vsptblCharacterName[12]; // Address: 0x2B5880
char* vsptblCourseName[24]; // Address: 0x2B5A00
// Size: 0x20, DWARF: 0x11B653
Record* vspenvRecord[8][6]; // Address: 0x347410
signed int vsptblCourseParam[8][5]; // Address: 0x2B77F0
signed int vsptblGapPoint[8][64]; // Address: 0x2B6260
char* vsptblGapList[8][64]; // Address: 0x2B5A60
// Size: 0x20, DWARF: 0x11DE5B
VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0

//// Function Declarations ///////////////////////////////////////////////////////////
s32 ulstdSprintf(char* buf, char* fmt, ...);
__int128* ulgifAddCNTReserve(VgmsysGifPkt* pkt, signed int qwc);
void ulpktInitALPHA(Alpha2* pkt, signed int ctext);
void aySetVert(signed int* vert, float* xy, signed int z);
void aySetPolyComF4(Poly2* poly, ModelData* data);
void aySetPolyComFT4(Poly* poly, ModelData* data, signed int flg);
void ultexResetTex(signed int offset);
void ultexTransTexTag(VgmsysGifPkt* packet, unsigned int* addr, TexData* data, signed int no);
Data* sploadGetSelectData();
signed int nmvcPlayCursor(signed int num);
signed int ayCalcNextID(signed int id, signed int max, signed int add);
float ayCalcTotalMove(signed int frame, signed int count, float totalmove, signed int type);
float ayDrawNum(VgmsysGifPkt* packet, FData* data, signed int flg);
void nmfontInitOption();
void ayFontInitmin();
signed int nmvcPlay(signed int type, signed int no, signed int vol);
signed int nmvcPlayButton(signed int type);
signed int nmbgmCheckQue();
signed int ayMcGetStep();
void ayDrawBG(VgmsysGifPkt* packet, TexData* texData, signed int col, signed int mark);
signed int ayDrawCredits(VgmsysGifPkt* packet, VaytblCredit* namelst, float* dy, signed int num);
signed int ayMcCareerLoad(VgmsysGifPkt* packet);
signed int ayMcCareerSave(VgmsysGifPkt* packet);
void ayMcSetSaveFileID();
float cosf(float x);
float sinf(float x);
signed int nmvcSetExterVol(signed int vol);
signed int nmsqSetExterMVol(signed int vol);
void sceVu0FTOI4Vector(sceVu0IVECTOR v0, sceVu0FVECTOR v1);
float sqrtf(float x);
void ulpadStopDual(signed int port, signed int slot, signed int num);
void ulpadInitDual(char* addr, signed int port, signed int slot, signed int num);
VibData* sploadGetVibrationData();
void aySetCamMatrix(float (*worldScr)[4], float (*worldView)[4], float (*viewScr)[4]);
void aySetLightMatrix(float (*nLight)[4], float (*lightCol)[4], float acol, float lcol);
ActData ulpadGetActData(signed int port, signed int slot, signed int num);
signed int ultexGetNTex(unsigned int* addr);
void ul3dScaleMatrixXYZ(float (*mat)[4], float sx, float sy, float sz);
void sceGifPkCnt(VgmsysGifPkt* p, unsigned int a, unsigned int b, unsigned int c);
void sceGifPkReserve(VgmsysGifPkt* p, unsigned int size);
void sceGifPkTerminate(VgmsysGifPkt* p);
unsigned int ulmdlDrawModelPkt(unsigned int* pkt, VgmsysAbuf* abuf, MdlEnv* mdlenv, float (*matrix)[4], __int128* model, signed int drawmode);
signed int ayMcReplayLoad(VgmsysGifPkt* packet, signed int unused1);
signed int nmbgmSelect(signed int num, signed int tbl);
signed int nmbgmSetSelectTbl(signed int* tbl, signed int skip);
signed int nmbgmSetExterVol(signed int vol);
void nmbgmSetOptNext(signed int next);
signed int nmbgmPlay();
signed int nmbgmExit(signed int fade);
signed int nmbgmGetLevel(signed int dir);
signed int nmsqPlaySelect();
signed int nmsqStopSelect(signed int fade);
void ulpadSetDual(signed int port, signed int slot, signed int mode);
signed int rand();
void ayDrawKeyOparate(signed int kind, signed int count, signed int flg, TexData* texData, VgmsysGifPkt* packet);
signed int nmbgmGetSelect();
signed int nmbgmChange(signed int type, signed int no, signed int flg);
void nmfontFPrintF(VgmsysGifPkt* packet, char* str, float* pos);
void nmfontSetBil(signed int flag);
void nmfontSetPack(signed int flag);
void nmfontSetCol(signed int* col);
void nmfontSetSize(signed int width, signed int height);
void nmfontFPrint(VgmsysGifPkt* packet, char* str, signed int x, signed int y);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);

void ayOptionInit();
static signed int ayGetExponent(signed int no);
signed int ayOptionFrame();
static void ayOptSetEnv();
static void ayOptGetEnv();
void ayOptionEnd();
void ayOptionClear();
static void aySetMovFlg();
static void ayDrawSound();
static void aySelHeadDraw();
static void ayDrawOptItem();
static void ayDrawSubOptItem(signed int unused1, signed int x, signed int y, signed int alpha);
static void ayDrawSOptItem();
static void ayDrawOptChar();
static void ayDrawCheat();
static signed int ayDrawEdit();
static void ayCalcScore();
static void ayDrawScore(signed int cs, signed int mx, signed int count);
static void ayCalcGap();
static void ayDrawGap(signed int cs, signed int mx, signed int count, signed int num);
static void ayDrawKeyConfig();
static void aySetKeyDiff(signed int no, signed int key);
static void ayOptBlackOut();
static void aySetKeyOparate();

//// Function Definitions ////////////////////////////////////////////////////////////

// DWARF: 0x121E14
// Address: 0x1C7530
// Size: 0x204
void ayOptionInit() {
    vayOptData = (void*)ulMalloc(0xE0, 0, 0);
    ayOptionClear();
    ulpadSetDual(0, 0, vspenvEnv.mc.option.key_config[0].vibration);
    ulpadSetDual(1, 0, vspenvEnv.mc.option.key_config[1].vibration);
    if (vayStateFlg != -1) {
        nmsqPlaySelect();
        switch (vayStateFlg / 100000) {
        case 0:
            vayOptData->step = 0x1B;
            break;
        case 1:
            vayOptData->step = 1;
            break;
        }
        vayOptData->disp[0] = vayStateFlg % 10;
        vayOptData->dispSel[0] = (vayStateFlg / 10) % 10;
        vayOptData->disp[1] = (vayStateFlg / 100) % 100;
        vayOptData->dispSel[1] = (vayStateFlg / 10000) % 10;
        vayOptData->select[0] = 9;
        vayOptData->select[1] = vayOptData->disp[1] + vayOptData->dispSel[1];
    }
    ayMcSysInit();
}

// DWARF: 0x121EDF
// Address: 0x1C7740
// Size: 0x7C
s32 ayGetExponent(signed int no) {
    signed int ii; // r16

    if (no <= 0) {
        return -1;
    }

    ii = 0;
    while (no > 1) {
        no /= 2;

        ii++;
    }
    
    return ii;
}

// DWARF: 0x121FE1
// Address: 0x1C77C0
// Size: 0x1E48
signed int ayOptionFrame() {
    signed int ret = 0; // r21
    signed int next = 0; // r17
    signed int mc; // r30
    signed int ii; // r16
    signed int tmp; // r18
    char power[4] = { 1, 3, 0, 2 }; // 0x100(r29)
    char pad[4] = { 2, 0, 3, 1 }; // 0x104(r29)
    signed int list[4]; // 0xA0(r29)
    signed int cheat; // r20
    signed int* selflg; // r22
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* data; // r23
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0xB0(r29)
    signed int table[16]; // 0xC0(r29)
    signed int disable; // r19

    data = sploadGetSelectData();

    if ((!vayOptData->step != 0x12) || (((vayOptData->step != 0x11) || (vayOptData->count < 0x20)) && ((vayOptData->step != 0x13) || (vayOptData->count >= 0x20)))) {
        ultexResetTex(data->offset);
        texData.tofs = -1;
        texData.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData, 0);
        ayDrawBG(vgmsysGifPkt, &texData, 0x80, 0);
    }

    if ((!vayOptData->step != 0x21) || (((vayOptData->step != 0x20) || (vayOptData->count < 0x20)) && ((vayOptData->step != 0x22) || (vayOptData->count >= 0x20)))) {
        aySetKeyOparate();
    }

    switch (vayOptData->step) {
    case 0:
        aySelHeadDraw();
        ayDrawOptItem();
        if (vayOptData->count == 0x3C) {
            next = 1;
            vayOptData->step = 1;
        }
        break;
    case 1:
    case 3:
    case 4:
    case 0x2E:
        aySelHeadDraw();
        ayDrawOptItem();
        if ((vgmsysPad[0]->trg & 0x40) && (vayOptData->movecnt == -1) && (vaySelData->bocount == -1)) {
            if (vayOptData->step == 1) {
                switch (vayOptData->select[0]) {
                case 0:
                    nmvcPlayButton(0);
                    vayOptData->step = 5;
                    break;
                case 1:
                    nmvcPlayButton(0);
                    vayOptData->step = 8;
                    ayOptSetEnv();
                    break;
                case 2:
                    cheat = 0;
                    selflg = &vspenvOption->enable.kids;
                    for (ii = 0; ii < 0xA; ii++) {
                        if (selflg[ii]) {
                            cheat = 1;
                            break;
                        }
                    }
                    if (cheat) {
                        nmvcPlayButton(0);
                        vayOptData->step = 0x28;
                    } else {
                        nmvcPlayButton(3);
                    }
                    break;
                case 3:
                    nmvcPlayButton(0);
                    vayOptData->step = 0x2E;
                    break;
                case 4:
                    nmvcPlayButton(0);
                    vayOptData->step = 0xE;
                    vayOptData->select[2] = vayOptData->select[3] = 0;
                    break;
                case 5:
                    nmvcPlayButton(0);
                    vayOptData->step = 0x14;
                    break;
                case 6:
                    nmvcPlayButton(0);
                    vayOptData->step = 0x1D;
                    break;
                case 7:
                    nmvcPlayButton(0);
                    vayOptData->step = 0x1A;
                    ayOptSetEnv();
                    break;
                case 8:
                    nmvcPlayButton(0);
                    vayOptData->track = 0;
                    vayOptData->spcnt = -1;
                    vayOptData->lv[2] = nmbgmGetLevel(0);
                    vayOptData->lv[0] = vayOptData->lv[1] = 0;
                    vayOptData->step = 0x11;
                    nmsqStopSelect(0x20);
                    break;
                case 9:
                    nmvcPlayButton(0);
                    vayOptData->step = 0x2B;
                    nmsqStopSelect(0x2E);
                    vayOptData->moveflg = -1;
                    break;
                case 10:
                    nmvcPlayButton(0);
                    vayOptData->step = 4;
                    break;
                case 11:
                    nmvcPlayButton(0);
                    vayOptData->step = 3;
                    break;
                case 12:
                    nmvcPlayButton(0);
                    vayOptData->step = 0xB;
                    break;
                case 13:
                    nmvcPlayButton(0);
                    vayOptData->step = 0x20;
                    vayOptData->scrY = 0.0f;
                    tmp = rand() % 8;
                    vayOptData->track = tmp;
                    nmsqStopSelect(0x20);
                    break;
                case 14:
                    nmvcPlayButton(0);
                    vayMovKind = 0x11;
                    vayOptData->step = 0x25;
                    vayStateFlg = (vayOptData->disp[0] + (vayOptData->dispSel[0] * 10)) + 100000;
                    ayOptSetEnv();
                    ret = 0xF;
                    break;
                }
                vayOptData->select[1] = vayOptData->disp[1] = vayOptData->dispSel[1] = 0;
            } else {
                nmvcPlayButton(0);
                vayOptData->step = 1;
            }
            next = 1;
        } else if ((vgmsysPad[0]->trg & 0x10) && (vayOptData->movecnt == -1) && (vaySelData->bocount == -1)) {
            if (vayOptData->step == 1) {
                nmvcPlayButton(2);
                ayOptSetEnv();
                ret = 0xB;
                next = 1;
            } else {
                nmvcPlayButton(2);
                vayOptData->step = 1;
            }
        }
        break;
    case 5:
    case 8:
    case 0x1D:
        aySelHeadDraw();
        ayDrawOptItem();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step++;
            if (vayOptData->step == 9) {
                ayMcSetSaveFileID();
            }
        }
        break;
    case 7:
    case 10:
    case 0x1F:
        aySelHeadDraw();
        ayDrawOptItem();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 1;
        }
        break;
    case 6:
        aySelHeadDraw();
        mc = ayMcCareerLoad(vgmsysGifPkt);
        if (mc > 0) {
            next = 1;
            if (mc == 1) {
                vaySelData->bgmdiff = vaySelData->bgm - vspenvEnv.mc.option.volume.bgm;
                nmbgmSetExterVol(vspenvEnv.mc.option.volume.bgm);
                ayOptGetEnv();
                aySetMovFlg();
            }
            vayOptData->step = 7;
        }
        break;
    case 9:
        aySelHeadDraw();
        if (ayMcCareerSave(vgmsysGifPkt) > 0) {
            next = 1;
            vayOptData->step = 7;
        }
        break;
    case 0x1E:
        aySelHeadDraw();
        tmp = ayMcReplayLoad(vgmsysGifPkt, 0);
        if (tmp == 1) {
            next = 1;
            vayOptData->step = 0x1F;
        } else if (tmp == 2) {
            ret = 0x12;
            next = 1;
            vayOptData->step = 0x27;
            vayStateFlg = (vayOptData->disp[0] + (vayOptData->dispSel[0] * 10)) + 100000;
        }
        break;
    case 0x27:
        aySelHeadDraw();
        break;
    case 0xB:
        aySelHeadDraw();
        ayDrawOptItem();
        ayDrawSOptItem();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 0xC;
        }
        break;
    case 0xC:
        ayDrawSOptItem();
        aySelHeadDraw();
        if (vayOptData->movecnt == -1) {
            if (vgmsysPad[0]->trg & 0x40) {
                if (vayOptData->select[1] == 0) {
                    nmvcPlayButton(0);
                    next = 1;
                    vayOptData->step = 0x17;
                    vayOptData->select[2] = 0;
                    vayOptData->vib = vspenvEnv.mc.option.key_config[0].vibration;
                    list[0] = vspenvOption->key_config[0].spin_l;
                    list[1] = vspenvOption->key_config[0].revert;
                    list[2] = vspenvOption->key_config[0].spin_r;
                    list[3] = vspenvOption->key_config[0].stance;
                    for (ii = 0; ii < 4; ii++) {
                        tmp = ayGetExponent(list[ii]);
                        if (tmp != -1) {
                            vayOptData->padlist[power[tmp]] = ii;
                        }
                    }
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[1]->trg & 0x40) {
                if (vayOptData->select[1] == 1) {
                    nmvcPlayButton(0);
                    next = 1;
                    vayOptData->step = 0x17;
                    vayOptData->select[2] = 0;
                    vayOptData->vib = vspenvEnv.mc.option.key_config[1].vibration;
                    list[0] = vspenvOption->key_config[1].spin_l;
                    list[1] = vspenvOption->key_config[1].revert;
                    list[2] = vspenvOption->key_config[1].spin_r;
                    list[3] = vspenvOption->key_config[1].stance;
                    for (ii = 0; ii < 4; ii++) {
                        tmp = ayGetExponent(list[ii]);
                        if (tmp != -1) {
                            vayOptData->padlist[power[tmp]] = ii;
                        }
                    }
                } else {
                    nmvcPlayButton(3);
                }
            } else if ((vgmsysPad[0]->trg & 0x10) || (vgmsysPad[1]->trg & 0x10)) {
                nmvcPlayButton(2);
                next = 1;
                vayOptData->step = 0xD;
            }
        }
        break;
    case 0xD:
        aySelHeadDraw();
        ayDrawSOptItem();
        ayDrawOptItem();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 1;
        }
        break;
    case 0x1A:
        aySelHeadDraw();
        ayDrawOptItem();
        ayDrawOptChar();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 0x1B;
        }
        break;
    case 0x1C:
        aySelHeadDraw();
        ayDrawOptItem();
        ayDrawOptChar();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 1;
        }
        break;
    case 0x1B:
        aySelHeadDraw();
        ayDrawOptChar();
        if ((vgmsysPad[0]->trg & 0x40) && (vayOptData->movecnt == -1)) {
            if (vayOptData->movieFlg[vayOptData->select[1]]) {
                nmvcPlayButton(0);
                next = 1;
                vayMovKind = vayOptData->select[1];
                vayStateFlg = (vayOptData->dispSel[1] * 10000) + ((vayOptData->disp[0] + (vayOptData->dispSel[0] * 10)) + (vayOptData->disp[1] * 100));
                ret = 0xF;
                vayOptData->step = 0x23;
            } else {
                nmvcPlayButton(3);
            }
        } else if ((vgmsysPad[0]->trg & 0x10) && (vayOptData->movecnt == -1)) {
            nmvcPlayButton(2);
            next = 1;
            vayOptData->step = 0x1C;
        }
        break;
    case 0x23:
        aySelHeadDraw();
        ayDrawOptChar();
        break;
    case 0x24:
        aySelHeadDraw();
        ayDrawOptChar();
        if (vayOptData->count == 0x3C) {
            next = 1;
            vayOptData->step = 0x1B;
        }
        break;
    case 0x25:
        aySelHeadDraw();
        ayDrawOptItem();
        break;
    case 0x26:
        aySelHeadDraw();
        ayDrawOptItem();
        if (vayOptData->count == 0x3C) {
            next = 1;
            vayOptData->step = 1;
        }
        break;
    case 0x11:
    case 0x20:
        if (vayOptData->count < 0x20) {
            aySelHeadDraw();
            ayDrawOptItem();
        } else {
            if (vayOptData->count == 0x20) {
                if (vayOptData->step == 0x20) {
                    for (ii = 0; ii < 0x10; ii++) {
                        table[ii] = ii;
                    }
                    disable = 0;
                    for (ii = 0; ii < 0xC; ii++) {
                        disable ^= 1 << ii;
                    }
                    nmbgmSetOptNext(1);
                    nmbgmSetSelectTbl(table, disable);
                }
                nmbgmSelect(vayOptData->track, 0);
                nmbgmPlay();
            }
            if (vayOptData->step == 0x11) {
                ayDrawSound();
            } else {
                ayDrawCredits(vgmsysGifPkt, vaytblCredit, &vayOptData->scrY, 0x28C);
            }
            if (vayOptData->count == 0x40) {
                next = 1;
                vayOptData->step++;
            }
        }
        ayOptBlackOut();
        break;
    case 0x12:
        ayDrawSound();
        if ((vayOptData->movecnt == -1) && (vayOptData->trackcnt == -1)) {
            if ((vgmsysPad[0]->trg & 0x40) && (vayOptData->select[1] == 3)) {
                nmvcPlayButton(0);
                nmbgmExit(0x20);
                next = 1;
                vayOptData->step = 0x13;
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                nmbgmExit(0x20);
                next = 1;
                vayOptData->step = 0x13;
            }
        }
        break;
    case 0x21:
        if (ayDrawCredits(vgmsysGifPkt, vaytblCredit, &vayOptData->scrY, 0x28C) == -1) {
            nmbgmExit(0x20);
            next = 1;
            vayOptData->step = 0x22;
        }
        if ((vgmsysPad[0]->trg & 0x40) || (vgmsysPad[0]->trg & 0x10) || (vgmsysPad[0]->trg & 0x800)) {
            nmvcPlayButton(2);
            nmbgmExit(0x20);
            next = 1;
            vayOptData->step = 0x22;
        }
        break;
    case 0x13:
    case 0x22:
        if (vayOptData->count < 0x20) {
            if (vayOptData->step == 0x13) {
                ayDrawSound();
            } else {
                ayDrawCredits(vgmsysGifPkt, vaytblCredit, &vayOptData->scrY, 0x28C);
            }
        } else {
            aySelHeadDraw();
            ayDrawOptItem();
            if (vayOptData->count == 0x20) {
                nmsqPlaySelect();
            } else if (vayOptData->count == 0x5C) {
                next = 1;
                vayOptData->step = 1;
                nmbgmSetSelectTbl(vspenvOption->bgm.table, vspenvOption->bgm.disable);
            }
        }
        if (vayOptData->count < 0x40) {
            ayOptBlackOut();
        }
        break;
    case 0x14:
        aySelHeadDraw();
        ayDrawOptItem();
        ayCalcScore();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 0x15;
            vayOptData->select[2] = 0;
        }
        break;
    case 0x16:
        aySelHeadDraw();
        ayDrawOptItem();
        ayCalcScore();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 1;
            vayOptData->select[2] = 0;
        }
        break;
    case 0x15:
        aySelHeadDraw();
        ayCalcScore();
        if ((vgmsysPad[0]->trg & 0x10) && (vayOptData->movecnt == -1)) {
            nmvcPlayButton(2);
            next = 1;
            vayOptData->step = 0x16;
        }
        break;
    case 0xE:
        aySelHeadDraw();
        ayDrawOptItem();
        ayCalcGap();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 0xF;
        }
        break;
    case 0x10:
        ayDrawOptItem();
        aySelHeadDraw();
        ayCalcGap();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 1;
            vayOptData->select[2] = 0;
        }
        break;
    case 0xF:
        aySelHeadDraw();
        ayCalcGap();
        if ((vgmsysPad[0]->trg & 0x10) && (vayOptData->movecnt == -1)) {
            nmvcPlayButton(2);
            next = 1;
            vayOptData->step = 0x10;
        }
        break;
    case 0x17:
        ayDrawSOptItem();
        aySelHeadDraw();
        ayDrawKeyConfig();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 0x18;
        }
        break;
    case 0x19:
        ayDrawSOptItem();
        aySelHeadDraw();
        ayDrawKeyConfig();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 0xC;
        }
        break;
    case 0x18:
        ayDrawSOptItem();
        aySelHeadDraw();
        ayDrawKeyConfig();
        if ((vgmsysPad[vayOptData->select[1]]->trg & 0x40) && (vayOptData->movecnt == -1) && (vaySelData->bocount == -1)) {
            if (vayOptData->select[2] == 5) {
                nmvcPlayButton(0);
                for (ii = 0; ii < 4; ii++) {
                    vayOptData->padlist[ii] = ii;
                }
                if (vgmsysPad[vayOptData->select[1]]->state == 2) {
                    vayOptData->vib = 0;
                } else {
                    vayOptData->vib = 1;
                    ulpadSetDual(vayOptData->select[1], 0, 1);
                }
            } else if (vayOptData->select[2] == 6) {
                nmvcPlayButton(0);
                next = 1;
                vayOptData->step = 0x19;
                vspenvOption->key_config[vayOptData->select[1]].vibration = vayOptData->vib;
                ulpadSetDual(vayOptData->select[1], 0, vayOptData->vib);
                for (ii = 0; ii < 4; ii++) {
                    switch (vayOptData->padlist[ii]) {
                    case 0:
                        vspenvOption->key_config[vayOptData->select[1]].spin_l = 1 << pad[ii];
                        break;
                    case 1:
                        vspenvOption->key_config[vayOptData->select[1]].revert = 1 << pad[ii];
                        break;
                    case 2:
                        vspenvOption->key_config[vayOptData->select[1]].spin_r = 1 << pad[ii];
                        break;
                    case 3:
                        vspenvOption->key_config[vayOptData->select[1]].stance = 1 << pad[ii];
                        break;
                    }
                }
            }
        } else if ((vgmsysPad[vayOptData->select[1]]->trg & 0x10) && (vayOptData->movecnt == -1) && (vaySelData->bocount == -1)) {
            nmvcPlayButton(2);
            tmp = vayOptData->padlist[vayOptData->select[2]];
            aySetKeyDiff(0, tmp);
            next = 1;
            vayOptData->step = 0x19;
            vspenvOption->key_config[vayOptData->select[1]].vibration = vayOptData->vib;
            for (ii = 0; ii < 4; ii++) {
                switch (vayOptData->padlist[ii]) {
                case 0:
                    vspenvOption->key_config[vayOptData->select[1]].spin_l = 1 << pad[ii];
                    break;
                case 1:
                    vspenvOption->key_config[vayOptData->select[1]].revert = 1 << pad[ii];
                    break;
                case 2:
                    vspenvOption->key_config[vayOptData->select[1]].spin_r = 1 << pad[ii];
                    break;
                case 3:
                    vspenvOption->key_config[vayOptData->select[1]].stance = 1 << pad[ii];
                    break;
                }
            }
        }
        break;
    case 0x28:
        aySelHeadDraw();
        ayDrawOptItem();
        ayDrawCheat();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 0x29;
        }
        break;
    case 0x2A:
        aySelHeadDraw();
        ayDrawOptItem();
        ayDrawCheat();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 1;
        }
        break;
    case 0x29:
        aySelHeadDraw();
        ayDrawCheat();
        if ((vgmsysPad[0]->trg & 0x40) && (vayOptData->movecnt == -1)) {
            if (vayOptData->select[1] == 0xA) {
                nmvcPlayButton(0);
                vspenvOption->cheats.kids = 0;
                vspenvOption->cheats.half_g = 0;
                vspenvOption->cheats.perfect_b = 0;
                vspenvOption->cheats.always_sp = 0;
                vspenvOption->cheats.super_spin = 0;
                vspenvOption->cheats.super_speed = 0;
                vspenvOption->cheats.fast_motion = 0;
                vspenvOption->cheats.replay_view = 0;
                vspenvOption->cheats.big_head = 0;
                vspenvOption->cheats.mirror = 0;
                vspenvOption->cheats.metallic = 0;
                vspenvOption->cheats.partition = 0;
            } else if (vayOptData->select[1] == 0xB) {
                nmvcPlayButton(0);
                next = 1;
                vayOptData->step = 0x2A;
            }
        } else if ((vgmsysPad[0]->trg & 0x10) && (vayOptData->movecnt == -1)) {
            nmvcPlayButton(2);
            next = 1;
            vayOptData->step = 0x2A;
        }
        break;
    case 0x2B:
        aySelHeadDraw();
        ayDrawOptItem();
        ayDrawEdit();
        if (vayOptData->count == 0x2E) {
            nmbgmSelect(vspenvOption->bgm.table[0], 0);
            nmbgmPlay();
            next = 1;
            vayOptData->step = 0x2C;
        }
        break;
    case 0x2D:
        ayDrawOptItem();
        aySelHeadDraw();
        ayDrawEdit();
        if (vayOptData->count == 0x2E) {
            next = 1;
            vayOptData->step = 1;
            nmsqPlaySelect();
        }
        break;
    case 0x2C:
        aySelHeadDraw();
        next = ayDrawEdit();
        if (next == 1) {
            vayOptData->step = 0x2D;
            nmbgmExit(0x2E);
        }
        break;
    }

    if (!next) {
        vayOptData->count = (vayOptData->count + 1) & 0xFFFFFF;
    } else {
        vayOptData->count = 0;
    }

    return ret;
}

// DWARF: 0x12234D
// Address: 0x1C9610
// Size: 0x58
static void ayOptSetEnv() {
    ulstdSprintf(vspenvEnv.mc.option.name, "%s", vayOptData->name);
    vspenvEnv.mc.option.volume.se = vayOptData->se;
    vspenvEnv.mc.option.volume.bgm = vaySelData->bgm;
}

// DWARF: 0x122417
// Address: 0x1C9670
// Size: 0x60
static void ayOptGetEnv() {
    ulstdSprintf(vayOptData->name, "%s", vspenvEnv.mc.option.name);
    vayOptData->se = vayOptData->seflg = vspenvEnv.mc.option.volume.se;
    nmvcSetExterVol(vayOptData->se);
}

// DWARF: 0x1224DD
// Address: 0x1C96D0
// Size: 0x2C
void ayOptionEnd() {
    ulFree(vayOptData);
    ayMcSysEnd();
}

// DWARF: 0x12259F
// Address: 0x1C9700
// Size: 0xC0
void ayOptionClear() {
    signed int ii; // r16

    vayOptData->count = 0;
    vayOptData->step = 0;
    vayOptData->movecnt = -1;
    vayOptData->track = 0;
    vayOptData->trackcnt = -1;
    vayOptData->trackdial = 0;
    vayOptData->spcnt = -1;
    for(ii = 0; ii < 4; ii++) {
        vayOptData->select[ii] = 0;
        vayOptData->disp[ii] = 0;
        vayOptData->dispSel[ii] = 0;
    }
    ayOptGetEnv();
    aySetMovFlg();
}

// DWARF: 0x122695
// Address: 0x1C97C0
// Size: 0xBC
static void aySetMovFlg() {
    signed int ii; // r16

    for (ii = 0; ii < 2; ii++) {
        vayOptData->movieFlg[ii] = 1;
    }
    for (ii = 0; ii < 0xF; ii++) {
        if (vspenvOption->movie & (1 << ii)) {
            vayOptData->movieFlg[ii + 2] = 1;
        } else {
            vayOptData->movieFlg[ii + 2] = 0;
        }
    }
}

// DWARF: 0x12277D
// Address: 0x1C9880
// Size: 0x1BF8
static void ayDrawSound() {
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // r18
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // 0x39C(r29)
    void* addr; // 0x3A0(r29)
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xD0(r29)
    float vert[4][4]; // 0x1B0(r29)
    float xy[4]; // 0x1F0(r29)
    float rotvert[4][2]; // 0x200(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData[10]; // 0x220(r29)
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // r19
    signed int ii; // r17
    signed int jj; // r16
    signed int count = vayOptData->count; // 0x3A4(r29)
    float pos[9][2] = { { 56.0f, 25.0f }, { 520.0f, 36.0f }, { 520.0f, 64.0f }, { 520.0f, 92.0f }, { 276.0f, 172.0f }, { 330.0f, 172.0f }, { 386.0f, 172.0f }, { 428.0f, 156.0f }, { 606.0f, 172.0f } }; // 0x2C0(r29)
    float size; // 0x3A8(r29)
    float rot[3]; // 0x390(r29)
    float cosT; // 0x3AC(r29)
    float sinT; // 0x3B0(r29)
    char* levelList[3][4] = { { "SFX LEVEL", "MUSIC LEVEL", "SELECT TRACK", "BACK" }, { "SOUNDEFFEKTE", "MUSIK", "SONG W\x90" "HLEN", "ZUR\x94" "K" }, { "EFFETS SON", "MUSIQUE", "CHOISIR LA PISTE", "RETOUR" } }; // 0x310(r29)
    char** level = levelList[vspenvGame->language]; // 0x3B4(r29)
    char str[64]; // 0x340(r29)
    signed int fcol[4]; // 0x380(r29)

    if (vayOptData->step == 0x12) {
        if ((vayOptData->trackcnt > -2) && (vayOptData->movecnt == -1)) {
            if (vgmsysPad[0]->rep & 0x1000) {
                if (vayOptData->select[1] == 0) {
                    vayOptData->select[1] = 3;
                    nmvcSetExterVol(vayOptData->se);
                } else {
                    vayOptData->select[1]--;
                }
                if (vayOptData->track != nmbgmGetSelect()) {
                    nmbgmChange(0x10, vayOptData->track, 0);
                    vayOptData->trackcnt = -3;
                } else {
                    vayOptData->trackcnt = -1;
                }
                nmvcPlayCursor(1);
            } else if (vgmsysPad[0]->rep & 0x4000) {
                if (vayOptData->select[1] == 3) {
                    vayOptData->select[1] = 0;
                } else {
                    if (vayOptData->select[1] == 0) {
                        nmvcSetExterVol(vayOptData->se);
                    }
                    vayOptData->select[1]++;
                }
                if (vayOptData->track != nmbgmGetSelect()) {
                    nmbgmChange(0x10, vayOptData->track, 0);
                    vayOptData->trackcnt = -3;
                } else {
                    vayOptData->trackcnt = -1;
                }
                nmvcPlayCursor(1);
            } else if (vgmsysPad[0]->cnt & 0x8000) {
                switch (vayOptData->select[1]) {
                case 0:
                    if (vayOptData->se > 0) {
                        vayOptData->se--;
                    }
                    break;
                case 1:
                    if (vaySelData->bgm > 0) {
                        vaySelData->bgm--;
                        nmbgmSetExterVol(vaySelData->bgm);
                        nmsqSetExterMVol(vaySelData->bgm);
                    }
                    break;
                case 2:
                    vayOptData->movecnt = 0;
                    vayOptData->moveflg = -1;
                    vayOptData->trackcnt = -1;
                    break;
                }
            } else if (vgmsysPad[0]->cnt & 0x2000) {
                switch (vayOptData->select[1]) {
                case 0:
                    if (vayOptData->se < 0xFF) {
                        vayOptData->se++;
                    }
                    break;
                case 1:
                    if (vaySelData->bgm < 0xFF) {
                        vaySelData->bgm++;
                        nmbgmSetExterVol(vaySelData->bgm);
                        nmsqSetExterMVol(vaySelData->bgm);
                    }
                    break;
                case 2:
                    vayOptData->movecnt = 0;
                    vayOptData->moveflg = 1;
                    vayOptData->trackcnt = -1;
                    break;
                }
            }
        } else {
            if (vayOptData->movecnt >= 0) {
                vayOptData->movecnt++;
                if (vayOptData->movecnt == 8) {
                    vayOptData->track += vayOptData->moveflg;
                    if (vayOptData->track == -1) {
                        vayOptData->track = 0xB;
                    } else if (vayOptData->track == 0xC) {
                        vayOptData->track = 0;
                    }
                    vayOptData->movecnt = -1;
                    vayOptData->trackdial += vayOptData->moveflg;
                    if (vayOptData->trackdial < 0) {
                        vayOptData->trackdial = 7;
                    } else if (vayOptData->trackdial > 7) {
                        vayOptData->trackdial = 0;
                    }
                }
            }
            if (vayOptData->trackcnt == -2) {
                if (vayOptData->track != nmbgmGetSelect()) {
                    nmbgmChange(0x10, vayOptData->track, 0);
                    vayOptData->trackcnt = -3;
                } else {
                    vayOptData->trackcnt = -1;
                }
            } else if ((vayOptData->trackcnt == -3) && (nmbgmCheckQue() == 0)) {
                vayOptData->trackcnt = -1;
            }
        }

        if ((vgmsysPad[0]->rev & 0x2000) || (vgmsysPad[0]->rev & 0x8000)) {
            if (vayOptData->select[1] == 0) {
                if (vayOptData->seflg != vayOptData->se) {
                    nmvcSetExterVol(vayOptData->se);
                    nmvcPlayButton(4);
                    vayOptData->seflg = vayOptData->se;
                }
            } else if (vayOptData->select[1] == 2) {
                vayOptData->trackcnt = 0;
            }
        }

        if (vayOptData->trackcnt >= 0) {
            vayOptData->trackcnt++;
            if (vayOptData->trackcnt == 0x1E) {
                vayOptData->trackcnt = -2;
            }
        }
    }

    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    for (ii = 0; ii < 9; ii++) {
        texData[ii].tofs = -1;
        texData[ii].cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[ii], ii + 0x11);
    }
    texData[9].tofs = -1;
    texData[9].cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[9], 0x29);

    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x8E);

    alpha = ((Alpha2*)addr)++;
    ulpktInitALPHA(alpha, 1);

    poly = addr;

    data.texdata = &texData[0];
    data.psmt = 0x13;
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    xy[0] = 0.0f, xy[1] = 0.0f, xy[2] = 640.0f, xy[3] = 224.0f;
    aySetVert(data.vert[0], xy, 1);
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x200, data.uv[3] = 0x200;
    aySetPolyComFT4(&poly[0], &data, 1);

    data.psmt = 0x14;
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;

    data.texdata = &texData[5];
    xy[0] = pos[0][0] - 32.0f, xy[1] = pos[0][1] - 16.0f, xy[2] = 32.0f + pos[0][0], xy[3] = 16.0f + pos[0][1];
    aySetVert(data.vert[0], xy, 1);
    aySetPolyComFT4(&poly[1], &data, 1);

    vayOptData->lv[0] = vayOptData->lv[1];
    vayOptData->lv[1] = vayOptData->lv[2];
    vayOptData->lv[2] = nmbgmGetLevel(0);
    if (vayOptData->spcnt == -1) {
        if ((vayOptData->lv[0] < vayOptData->lv[1]) && (vayOptData->lv[1] > vayOptData->lv[2]) && (vayOptData->lv[2] > 0xBB8)) {
            vayOptData->spcnt = 0;
            vayOptData->spsize = (vayOptData->lv[2] + (vaySelData->bgm * 100)) / 8000.0f;
        }
        data.texdata = &texData[7];
        size = 32.0f;
    } else {
        data.texdata = &texData[6];
        if (vayOptData->spcnt < 2) {
            size = 32.0f + ((vayOptData->spsize * vayOptData->spcnt) / 2.0f);
        } else {
            size = 32.0f + ((vayOptData->spsize * (4 - vayOptData->spcnt)) / 2.0f);
        }
        vayOptData->spcnt++;
        if (vayOptData->spcnt == 4) {
            vayOptData->spcnt = -1;
        }
    }

    xy[0] = pos[0][0] - size, xy[1] = pos[0][1] - (size / 2.0f), xy[2] = pos[0][0] + size, xy[3] = pos[0][1] + (size / 2.0f);
    aySetVert(data.vert[0], xy, 1);
    aySetPolyComFT4(&poly[2], &data, 1);

    rot[0] = 0.016362458f * (vayOptData->se - 0x80);
    rot[1] = 0.016362458f * (vaySelData->bgm - 0x80);
    rot[2] = (3.141592f * vayOptData->trackdial) / 4.0f;
    if (vayOptData->movecnt != -1) {
        rot[2] += (0.09817475f * vayOptData->movecnt) * vayOptData->moveflg;
    }
    if (rot[2] > 3.141592f) {
        rot[2] -= 6.283184f;
    } else if (rot[2] < -3.141592f) {
        rot[2] += 6.283184f;
    }

    nmfontInitOption();
    nmfontSetBil(1);
    for (ii = 0; ii < 3; ii++) {
        nmfontSetPack(1);
        nmfontSetSize(0x10, 0x18);
        if (ii == vayOptData->select[1]) {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        } else {
            fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
        }
        nmfontSetCol(fcol);
        nmfontFPrint(vgmsysGifPkt, level[ii], 0x9C, (ii * 56) + 0x44);

        if (ii == 2) {
            data.texdata = &texData[3];
        } else {
            data.texdata = &texData[1];
        }
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        xy[0] = pos[ii + 1][0] - 32.0f, xy[1] = pos[ii + 1][1] - 16.0f, xy[2] = 32.0f + pos[ii + 1][0], xy[3] = 16.0f + pos[ii + 1][1];
        aySetVert(data.vert[0], xy, 1);
        aySetPolyComFT4(&poly[ii + 3], &data, 1);

        if (ii == 2) {
            data.texdata = &texData[4];
        } else {
            data.texdata = &texData[2];
        }
        cosT = cosf(rot[ii]);
        sinT = sinf(rot[ii]);
        rotvert[0][0] = (-32.0f * cosT) + (32.0f * sinT);
        rotvert[0][1] = (-16.0f * sinT) - (16.0f * cosT);
        rotvert[1][0] = (32.0f * cosT) + (32.0f * sinT);
        rotvert[1][1] = (16.0f * sinT) - (16.0f * cosT);
        rotvert[2][0] = (-32.0f * cosT) - (32.0f * sinT);
        rotvert[2][1] = (-16.0f * sinT) + (16.0f * cosT);
        rotvert[3][0] = (32.0f * cosT) - (32.0f * sinT);
        rotvert[3][1] = (16.0f * sinT) + (16.0f * cosT);

        for (jj = 0; jj < 4; jj++) {
            vert[jj][0] = rotvert[jj][0] + pos[ii + 1][0];
            vert[jj][1] = rotvert[jj][1] + pos[ii + 1][1];
            vert[jj][0] += 1728.0f;
            vert[jj][1] += 1936.0f;
            sceVu0FTOI4Vector(data.vert[jj], vert[jj]);
            data.vert[jj][2] = 1;
        }
        aySetPolyComFT4(&poly[ii + 6], &data, 1);

        for (jj = 0; jj < 4; jj++) {
            vert[jj][0] = rotvert[jj][0] + pos[ii + 4][0];
            vert[jj][1] = rotvert[jj][1] + pos[ii + 4][1];
            vert[jj][0] += 1728.0f;
            vert[jj][1] += 1936.0f;
            sceVu0FTOI4Vector(data.vert[jj], vert[jj]);
            data.vert[jj][2] = 1;
        }
        aySetPolyComFT4(&poly[ii + 9], &data, 1);

        data.texdata = &texData[8];
        if (vayOptData->select[1] == ii) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        } else {
            data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
        }

        if (ii == 2) {
            if (vayOptData->select[1] == 2) {
                fcol[0] = 0x80, fcol[1] = 0, fcol[2] = 0, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x40, fcol[1] = 0, fcol[2] = 0, fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            nmfontSetPack(0);
            nmfontSetSize(0x18, 0x18);
            ulstdSprintf(str, "%2d", vayOptData->track + 1);
            nmfontFPrint(vgmsysGifPkt, str, 0x1B8, (2.0f * pos[3][1]) - 6.0f);
            data.uv[0] = 0, data.uv[1] = 0x20, data.uv[2] = 0x30, data.uv[3] = 0x30;
            xy[0] = 546.0f, xy[1] = pos[3][1], xy[2] = 594.0f, xy[3] = 8.0f + pos[3][1];
            aySetVert(data.vert[0], xy, 1);
            aySetPolyComFT4(&poly[16], &data, 1);
        } else {
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x30, data.uv[3] = 0x10;
            xy[0] = 446.0f, xy[1] = pos[ii + 1][1], xy[2] = 494.0f, xy[3] = 8.0f + pos[ii + 1][1];
            aySetVert(data.vert[0], xy, 1);
            aySetPolyComFT4(&poly[ii + 12], &data, 1);
            data.uv[0] = 0, data.uv[1] = 0x10, data.uv[2] = 0x30, data.uv[3] = 0x20;
            xy[0] = 546.0f, xy[1] = pos[ii + 1][1], xy[2] = 594.0f, xy[3] = 8.0f + pos[ii + 1][1];
            aySetVert(data.vert[0], xy, 1);
            aySetPolyComFT4(&poly[ii + 14], &data, 1);
        }
    }

    nmfontSetPack(1);
    nmfontSetSize(0x10, 0x18);
    if (vayOptData->select[1] == 3) {
        fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
    } else {
        fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
    }
    nmfontSetCol(fcol);
    nmfontFPrint(vgmsysGifPkt, level[3], 0x9C, 0x100);

    data.texdata = &texData[9];
    if (vayOptData->select[1] == 3) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0;
    } else {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    }
    for (ii = 0; ii < 2; ii++) {
        xy[0] = 400.0f + (200.0f * ii), xy[1] = pos[vayOptData->select[1] + 1][1] - 6.0f, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
        aySetVert(data.vert[0], xy, 1);
        data.uv[0] = ii << 5, data.uv[1] = 0x20, data.uv[2] = (ii << 5) + 0x20, data.uv[3] = 0x40;
        aySetPolyComFT4(&poly[ii + 17], &data, 1);
    }

    data.texdata = &texData[8];
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    xy[0] = pos[7][0] + (14.166667f * vayOptData->track), xy[1] = pos[7][1], xy[2] = 7.0f + xy[0], xy[3] = pos[8][1];
    if (vayOptData->movecnt != -1) {
        xy[0] += (1.7708334f * vayOptData->movecnt) * vayOptData->moveflg;
        if (xy[0] < pos[7][0]) {
            xy[0] += 170.0f;
        }
        xy[2] = 7.0f + xy[0];
    }
    aySetVert(data.vert[0], xy, 1);
    data.uv[0] = 0x39, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x20;
    aySetPolyComFT4(&poly[19], &data, 1);

    if (vayOptData->select[1] == 2) {
        fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
    } else {
        fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
    }
    nmfontSetCol(fcol);
    nmfontSetPack(1);
    nmfontSetSize(0x10, 0x12);
    ulstdSprintf(str, "%s -%s-", vbgmtblMusic[vayOptData->track], vbgmtblArtist[vayOptData->track]);
    nmfontFPrint(vgmsysGifPkt, str, 0x26C - nmfontGetPackStrLen(str, 0x10, 0), 0xD6);
}

// DWARF: 0x122C24
// Address: 0x1CB480
// Size: 0x6F4
static void aySelHeadDraw() {
    signed int texno; // r16
    signed int moveType; // r17
    signed int count; // r18
    float dx; // 0x1A4(r29)
    signed int col; // r19
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // r20
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0x190(r29)
    void* addr; // r21
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // r22
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // r23

    (void)poly;

    count = vayOptData->count;
    moveType = 0;

    loaddata = sploadGetSelectData();

    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;

    switch (vayOptData->step) {
    case 0x0:
    case 0x26:
        moveType = 1;
        texno = 7;
        break;
    case 0x1:
    case 0x3:
    case 0x4:
    case 0x2E:
        moveType = 0;
        texno = 7;
        break;
    case 0x5:
        moveType = 2;
        texno = 0xC;
        break;
    case 0x6:
        moveType = 0;
        texno = 0xC;
        break;
    case 0x7:
        moveType = 2;
        texno = -0xC;
        break;
    case 0x8:
        moveType = 2;
        texno = 0xD;
        break;
    case 0x9:
        moveType = 0;
        texno = 0xD;
        break;
    case 0xA:
        moveType = 2;
        texno = -0xD;
        break;
    case 0x1D:
        moveType = 2;
        texno = 0xF;
        break;
    case 0x1E:
    case 0x27:
        moveType = 0;
        texno = 0xF;
        break;
    case 0x1F:
        moveType = 2;
        texno = -0xF;
        break;
    case 0xB:
    case 0xC:
    case 0xD:
        if (vayOptData->step == 0xC) {
            moveType = 0;
        } else {
            moveType = 2;
        }

        if (vayOptData->select[0] == 5) {
            texno = 8;
        } else {
            texno = 0xB;
        }

        if (vayOptData->step == 0xD) {
            texno = -texno;
        }
        break;
    case 0xE:
        moveType = 2;
        texno = 9;
        break;
    case 0xF:
        moveType = 0;
        texno = 9;
        break;
    case 0x10:
        moveType = 2;
        texno = -0x9;
        break;
    case 0x11:
        if (count < 0x20) {
            moveType = 3;
            texno = 7;
        } else {
            count -= 0x20;
            moveType = 1;
            texno = 0xD;
        }
        break;
    case 0x12:
        moveType = 0;
        texno = 0xD;
        break;
    case 0x13:
        if (count < 0x20) {
            moveType = 3;
            texno = 0xD;
        } else {
            count -= 0x20;
            moveType = 1;
            texno = 7;
        }
        break;
    case 0x14:
        moveType = 2;
        texno = 8;
        break;
    case 0x15:
        moveType = 0;
        texno = 8;
        break;
    case 0x16:
        moveType = 2;
        texno = -0x8;
        break;
    case 0x17:
    case 0x18:
    case 0x19:
        moveType = 0;
        texno = 0xB;
        break;
    case 0x1A:
    case 0x1B:
    case 0x1C:
        if (vayOptData->step == 0x1B) {
            moveType = 0;
        } else {
            moveType = 2;
        }

        if (vayOptData->select[0] == 3) {
            texno = 9;
        } else {
            texno = 0xE;
        }

        if (vayOptData->step == 0x1C) {
            texno = -texno;
        }
        break;
    case 0x23:
        moveType = 3;
        texno = 0xE;
        break;
    case 0x24:
        moveType = 1;
        texno = 0xE;
        break;
    case 0x25:
        moveType = 3;
        texno = 7;
        break;
    case 0x20:
        moveType = 3;
        texno = 7;
        break;
    case 0x22:
        count -= 0x20;
        moveType = 1;
        texno = 7;
        break;
    case 0x28:
        moveType = 2;
        texno = 0x10;
        break;
    case 0x29:
        moveType = 0;
        texno = 0x10;
        break;
    case 0x2A:
        moveType = 2;
        texno = -0x10;
        break;
    case 0x2B:
        moveType = 2;
        texno = 0x13;
        break;
    case 0x2C:
        moveType = 0;
        texno = 0x13;
        break;
    case 0x2D:
        moveType = 2;
        texno = -0x13;
        break;
    }

    if (moveType == 2) {
        if (texno < 0) {
            if (count < 0x10) {
                texno = -texno;
            } else {
                texno = 7;
            }
        } else if (count < 0x10) {
            texno = 7;
        }
    }

    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, (texno / 4) + 4);
    data.uv[0] = 0, data.uv[1] = (texno % 4) << 6, data.uv[2] = 0x100, data.uv[3] = data.uv[1] + 0x40;

    switch (moveType) {
    case 0:
        dx = 354.0f;
        col = 0x80;
        break;
    case 1:
        if (count < 0x20) {
            col = count * 4;
            dx = -286.0f + ayCalcTotalMove(0x21, count, 640.0f, 1);
        } else {
            dx = 354.0f;
            col = 0x80;
        }
        break;
    case 2:
        if (count < 0x10) {
            col = 0x80 - (count * 8);
            dx = 354.0f + ayCalcTotalMove(0x11, count, 640.0f, 3);
        } else if (count < 0x20) {
            col = (count - 0x10) * 8;
            dx = -286.0f + ayCalcTotalMove(0x11, (signed int)(count - 0x10), 640.0f, 1);
        } else {
            dx = 354.0f;
            col = 0x80;
        }
        break;
    case 3:
        col = 0x80 - (count * 4);
        dx = 354.0f + ayCalcTotalMove(0x21, count, 640.0f, 3);
        break;
    }

    addr = ulgifAddCNTReserve(vgmsysGifPkt, 9);

    alpha = (Alpha2*)addr;
    addr = alpha + 1;
    ulpktInitALPHA(alpha, 1);

    poly = addr;
    data.texdata = &texData;
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
    xy[0] = dx, xy[1] = 5.0f, xy[2] = 256.0f + dx, xy[3] = 37.0f;
    aySetVert(data.vert[0], xy, 1);
    data.psmt = 0x14;
    aySetPolyComFT4(poly, &data, 1);
}

// DWARF: 0x122F39
// Address: 0x1CBB80
// Size: 0x1B74
static void ayDrawOptItem() {
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // 0x2B4(r29)
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // 0x2B8(r29)
    void* addr; // 0x2BC(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0xA0(r29)
    signed int arrAlpha; // 0x2C0(r29)
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xB0(r29)
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // 0x2C4(r29)
    float xy[4]; // 0x190(r29)
    float pos[4]; // 0x1A0(r29)
    signed int ii; // r16
    signed int jj; // r17
    signed int count = vayOptData->count; // r21
    char* itemList[3][15] = { { "LOAD DATA", "SAVE DATA", "CHEATS", "SPLIT SCREEN", "GAP CHECKLIST", "HIGH SCORES", "WATCH REPLAY", "MOVIES", "SOUND LEVELS", "EDIT PLAYLIST", "TUTORIAL", "HIGH SCORE NAME", "CONTROLS", "CREDITS", "O2 PREVIEWS" }, { "DATEN LADEN", "DATEN SPEICHERN", "CHEATS", "GETEILTES BILD", "GAP-CHECKLISTE", "HIGHSCORES", "WIEDERHOLUNG ANSEHEN", "FILME", "LAUTST\x90" "RKE", "SONGLISTE \x90" "NDERN", "TUTORIAL", "HIGHSCORE-NAME", "STEUERUNG", "CREDITS", "O2-PREVIEWS" }, { "CHARGER LES DONNEES", "SAUVEGARDER LES DONNEES", "CHEATS", "ECRAN PARTAGE", "LISTE DES GAPS", "MEILLEURS SCORES", "REGARDER VIDEO", "CINEMATIQUES", "VOLUMES AUDIO", "MODIFIER LA PLAYLIST", "DIDACTICIEL", "MEILLEUR SCORE", "COMMANDES", "CREDITS", "DEMOS O2" } }; // 0x1B0(r29)
    char** item = itemList[vspenvGame->language]; // 0x2C8(r29)
    char* swList[3][4] = { { "VERT", "HORZ", "OFF", "ON" }, { "VERT.", "HORIZ.", "AUS", "EIN" }, { "VERT", "HORIZ", "NON", "OUI" } }; // 0x270(r29)
    char** sw = swList[vspenvGame->language]; // 0x2CC(r29)
    signed int dispID; // r20
    signed int dx; // r19
    signed int sx; // 0x2D0(r29)
    signed int dy; // r22
    signed int size; // r18
    signed int mx; // 0x2D4(r29)
    signed int id; // r23
    signed int fcol[4]; // 0x2A0(r29)
    signed int* selflg; // r30

    loaddata = sploadGetSelectData();

    switch (vayOptData->step) {
    case 0:
    case 0x26:
        mx = 1;
        dy = 0;
        break;
    case 1:
        mx = 0;
        if (vayOptData->movecnt == -1) {
            dy = 0;
            if (vaySelData->bocount == -1) {
                if ((vgmsysPad[0]->rep & 0x1000) && ((vayOptData->dispSel[0] > 0) || (vayOptData->disp[0] > 0))) {
                    nmvcPlayCursor(1);
                    vayOptData->movecnt = 0;
                    vayOptData->moveflg = 0;
                    if (vayOptData->dispSel[0] == 0) {
                        vayOptData->dispflg = -1;
                        vayOptData->disp[0]--;
                        dy = 0x20;
                    } else {
                        vayOptData->dispflg = 0;
                        vayOptData->dispSel[0]--;
                    }
                } else if ((vgmsysPad[0]->rep & 0x4000) && ((vayOptData->dispSel[0] < 6) || (vayOptData->disp[0] < 8))) {
                    nmvcPlayCursor(1);
                    vayOptData->movecnt = 0;
                    vayOptData->moveflg = 2;
                    if (vayOptData->dispSel[0] == 6) {
                        vayOptData->dispflg = 1;
                        vayOptData->disp[0]++;
                        dy = -0x20;
                    } else {
                        vayOptData->dispSel[0]++;
                        vayOptData->dispflg = 0;
                    }
                }
            }
        } else {
            if (vayOptData->dispflg) {
                dy = ((vayOptData->moveflg - 1) * (vayOptData->movecnt * 8)) - (vayOptData->dispflg * 32);
            } else {
                dy = 0;
            }
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 4) {
                vayOptData->movecnt = -1;
                dy = 0;
            }
        }

        ultexResetTex(loaddata->offset);
        texData.tofs = -1;
        texData.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x29);

        addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);

        alpha = ((Alpha2*)addr)++;
        ulpktInitALPHA(alpha, 1);

        poly = addr;
        data.texdata = &texData;
        data.psmt = 0x14;

        arrAlpha = vaySelData->count % 0x80;
        if (arrAlpha < 0x40) {
            arrAlpha *= 2;
        } else {
            arrAlpha = 0x80 - ((arrAlpha - 0x40) * 2);
        }

        for (ii = 0; ii < 2; ii++) {
            if (((vayOptData->disp[0] == 0) && (ii == 0)) || ((vayOptData->disp[0] == 8) && (ii == 1))) {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0;
            } else {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = arrAlpha;
            }
            data.uv[0] = ii * 32, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x20;
            xy[0] = 256.0f, xy[1] = 29.0f + (148.0f * ii), xy[2] = 384.0f, xy[3] = 8.0f + xy[1];
            aySetVert(&data.vert[0][0], xy, 1);
            aySetPolyComFT4(&poly[ii], &data, 1);
        }
        break;
    case 4:
        mx = 0;
        dy = 0;
        if ((vaySelData->bocount == -1) && ((vgmsysPad[0]->rep & 0x2000) || (vgmsysPad[0]->rep & 0x8000))) {
            nmvcPlayCursor(1);
            vspenvOption->tutorial ^= 1;
        }
        break;
    case 0x2E:
        mx = 0;
        dy = 0;
        if ((vaySelData->bocount == -1) && ((vgmsysPad[0]->rep & 0x2000) || (vgmsysPad[0]->rep & 0x8000))) {
            nmvcPlayCursor(1);
            vspenvOption->divide ^= 1;
        }
        break;
    case 3:
        mx = 0;
        if (vaySelData->bocount == -1) {
            if (vgmsysPad[0]->rep & 0x2000) {
                nmvcPlayCursor(1);
                if (vayOptData->select[1] == 2) {
                    vayOptData->select[1] = 0;
                } else {
                    vayOptData->select[1] += 1;
                }
            } else if (vgmsysPad[0]->rep & 0x8000) {
                nmvcPlayCursor(1);
                if (vayOptData->select[1] == 0) {
                    vayOptData->select[1] = 2;
                } else {
                    vayOptData->select[1] -= 1;
                }
            } else if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                if (vayOptData->name[vayOptData->select[1]] == 'A') {
                    vayOptData->name[vayOptData->select[1]] = '9';
                } else if (vayOptData->name[vayOptData->select[1]] == '0') {
                    vayOptData->name[vayOptData->select[1]] = 'z';
                } else if (vayOptData->name[vayOptData->select[1]] == 'a') {
                    vayOptData->name[vayOptData->select[1]] = 'Z';
                } else {
                    vayOptData->name[vayOptData->select[1]] -= 1;
                }
            } else if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                if (vayOptData->name[vayOptData->select[1]] == '9') {
                    vayOptData->name[vayOptData->select[1]] = 'A';
                } else if (vayOptData->name[vayOptData->select[1]] == 'Z') {
                    vayOptData->name[vayOptData->select[1]] = 'a';
                } else if (vayOptData->name[vayOptData->select[1]] == 'z') {
                    vayOptData->name[vayOptData->select[1]] = '0';
                } else {
                    vayOptData->name[vayOptData->select[1]]++;
                }
            }
        }
        dy = 0;
        break;
    case 5:
    case 8:
    case 0x1D:
    case 0xB:
    case 0x1A:
    case 0x28:
    case 0xE:
    case 0x14:
    case 0x2B:
        mx = 2;
        dy = 0;
        break;
    case 7:
    case 0xA:
    case 0x1F:
    case 0xD:
    case 0x1C:
    case 0x2A:
    case 0x10:
    case 0x16:
    case 0x2D:
        mx = 3;
        dy = 0;
        break;
    case 0x25:
    case 0x20:
    case 0x11:
        mx = 4;
        dy = 0;
        break;
    case 0x22:
    case 0x13:
        count -= 0x20;
        mx = 1;
        dy = 0;
        break;
    default:
        mx = 0;
        dy = 0;
        break;
    }

    vayOptData->select[0] = vayOptData->dispSel[0] + *vayOptData->disp;

    ayFontInitmin();

    for (ii = 0; ii < 7; ii++) {
        dispID = *vayOptData->disp + ii;
        switch (mx) {
        case 0:
            dx = 0;
            break;
        case 1:
            if (count < (ii + 1) * 4) {
                dx = -0x280;
            } else if (count < ((ii + 1) * 4) + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x21, count - ((ii + 1) * 4), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 2:
            if (dispID < vayOptData->select[0]) {
                id = ii;
            } else {
                id = ii - 1;
            }
            if (vayOptData->select[0] == dispID) {
                dx = 0;
            } else if (count < ((id + 1) * 4) / 2) {
                dx = 0;
            } else if (count < (((id + 1) * 4) / 2) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - (((id + 1) * 4) / 2), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        case 3:
            if (count < (((ii + 1) * 4) / 2) + 0x10) {
                dx = -0x280;
            } else if (count < (((ii + 1) * 4) / 2) + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, (count - 0x10) - (((ii + 1) * 4) / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 4:
            if (dispID < vayOptData->select[0]) {
                id = ii;
            } else {
                id = ii - 1;
            }
            if (vayOptData->select[0] == dispID) {
                dx = 0;
            } else if (count < (id + 1) * 4) {
                dx = 0;
            } else if (count < ((id + 1) * 4) + 0x20) {
                dx = ayCalcTotalMove(0x21, count - ((id + 1) * 4), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        }

        sx = dx + 0x208;

        if (((vayOptData->step <= 1) || (vayOptData->step >= 5)) && (vayOptData->step != 0x2E) && (vayOptData->select[0] == dispID)) {
            if (vayOptData->movecnt == -1) {
                size = 0x1C;
            } else if (vayOptData->movecnt < 2) {
                size = (vayOptData->movecnt * 2) + 0x1C;
            } else {
                size = 0x24 - (vayOptData->movecnt * 2);
            }
            fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }

        nmfontSetSize(size, size);
        dx -= nmfontGetPackStrLen(item[dispID], size, 0) / 2;

        if (((dy > 0) && (ii == 0)) || ((dy < 0) && (ii == 6))) {
            fcol[3] = vayOptData->movecnt << 5;
        }

        if (((mx == 2) || (mx == 4)) && (vayOptData->select[0] == dispID)) {
            if (count < 0x20) {
                fcol[3] = 0x80 - (count * 4);
                nmfontSetCol(fcol);
                size += count / 2;
                nmfontSetSize(size, size);
                pos[0] = 320.0f - (nmfontGetPackStrLen(item[dispID], size, 0) / 2.0f), pos[1] = (((118.0f + (ii << 5)) - dy) - (size / 2.0f)) - (count * ((((size / 2.0f) + (118.0f + (ii << 5))) - 74.0f) / 32.0f)), pos[2] = 16777215.0f, pos[3] = 0.0f;
                nmfontFPrintF(vgmsysGifPkt, item[dispID], pos);
            }
        } else {
            if (dispID == 2) {
                selflg = &vspenvOption->enable.kids;
                for (jj = 0; jj < 0xA; jj++) {
                    if (selflg[jj]) {
                        break;
                    }
                }
                if (jj == 0xA) {
                    fcol[0] /= 2;
                    fcol[1] /= 2;
                    fcol[2] /= 2;
                }
            }
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, item[dispID], dx + 0x140, ((118.0f + (ii << 5)) - dy) - (size / 2));
        }

        if (dispID == 3) {
            if (vayOptData->step == 0x2E) {
                size = 0x1C;
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                size = 0x14;
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = fcol[3];
            }
            nmfontSetSize(size, size);
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, sw[vspenvOption->divide], (sx + 0x1E) - (nmfontGetPackStrLen(sw[vspenvOption->divide], size, 0) / 2), ((118.0f + (ii << 5)) - dy) - (size / 2));
        } else if (dispID == 10) {
            if (vayOptData->step == 4) {
                size = 0x1C;
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                size = 0x14;
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = fcol[3];
            }
            nmfontSetSize(size, size);
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, sw[vspenvOption->tutorial + 2], (sx + 0x1E) - (nmfontGetPackStrLen(sw[vspenvOption->tutorial + 2], size, 0) / 2), ((118.0f + (ii << 5)) - dy) - (size / 2));
        } else if (dispID == 11) {
            ayDrawSubOptItem(dispID, sx, (118.0f + (ii << 5)) - dy, fcol[3]);
        }
    }

    if (dy != 0) {
        if (dy < 0) {
            dispID = vayOptData->disp[0] - 1;
            dy = (86.0f - dy) - 10.0f;
        } else if (dy > 0) {
            dispID = vayOptData->disp[0] + 7;
            dy = (342.0f - dy) - 10.0f;
        }
        dx = nmfontGetPackStrLen(item[dispID], 0x14, 0) / 2;
        fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80 - (vayOptData->movecnt << 5);
        if (dispID == 2) {
            selflg = &vspenvOption->enable.kids;
            for (jj = 0; jj < 0xA; jj++) {
                if (selflg[jj]) {
                    break;
                }
            }
            if (jj == 0xA) {
                fcol[0] /= 2;
                fcol[1] /= 2;
                fcol[2] /= 2;
            }
        }
        nmfontSetCol(fcol);
        nmfontSetSize(0x14, 0x14);
        nmfontFPrint(vgmsysGifPkt, item[dispID], 0x140 - dx, dy);
        if (dispID == 3) {
            nmfontFPrint(vgmsysGifPkt, sw[vspenvOption->divide], (sx + 0x1E) - (nmfontGetPackStrLen(sw[vspenvOption->divide], 0x14, 0) / 2), dy);
        } else if (dispID == 10) {
            nmfontFPrint(vgmsysGifPkt, sw[vspenvOption->tutorial + 2], (sx + 0x1E) - (nmfontGetPackStrLen(sw[vspenvOption->tutorial + 2], 0x14, 0) / 2), dy);
        } else if (dispID == 11) {
            ayDrawSubOptItem(dispID, 0x208, dy + 10, fcol[3]);
        }
    }
}

// // DWARF: 0x123454
// // Address: 0x1CD700
// // Size: 0x1DC
static void ayDrawSubOptItem(signed int unused1, signed int x, signed int y, signed int alpha) {
    signed int ii; // r16
    signed int size; // r17
    signed int dx; // r18
    signed int arrAlpha; // r19
    signed int fcol[4]; // 0x80(r29)
    char str[8]; // 0x98(r29)

    arrAlpha = vaySelData->count % 0x80;
    if (arrAlpha < 0x40) {
        arrAlpha *= 2;
    } else {
        arrAlpha = 0x80 - ((arrAlpha - 0x40) * 2);
    }
    nmfontSetPack(0);
    str[1] = 0;
    for (ii = 0, dx = x; ii < 3; ii++) {
        dx = x + (ii * 0x18);
        if ((vayOptData->step == 3) && (vayOptData->select[1] == ii)) {
            fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = arrAlpha;
            size = 0x1C;
            dx -= 4;
        } else {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = alpha;
            size = 0x14;
        }
        nmfontSetCol(&fcol);
        nmfontSetSize(size, size);
        str[0] = vayOptData->name[ii];
        nmfontFPrint(vgmsysGifPkt, &str, dx, y - (size / 2));
    }
    nmfontSetPack(1);
}

// // DWARF: 0x1236D3
// // Address: 0x1CD8E0
// // Size: 0xE10
static void ayDrawSOptItem() {
    float pos[4]; // 0xA0(r29)
    signed int ii; // r16
    signed int jj; // r19
    signed int count = vayOptData->count; // r18
    char* itemList[3][2] = { { "PLAYER 1", "PLAYER 2" }, { "SPIELER 1", "SPIELER 2" }, { "JOUEUR 1", "JOUEUR 2" } }; // 0xB0(r29)
    char** item = itemList[vspenvGame->language]; // r21
    signed int dx; // r20
    signed int size; // r17
    signed int mx; // r22
    float dy; // 0xE0(r29)
    float cy; // 0xE4(r29)
    float col; // 0xE8(r29)
    signed int fcol[4]; // 0xD0(r29)

    switch (vayOptData->step) {
    case 0xB:
        mx = 1;
        break;
    case 0xC:
        mx = 0;
        if (vayOptData->movecnt == -1) {
            if (vaySelData->bocount == -1) {
                if ((vgmsysPad[0]->rep & 0x1000) || (vgmsysPad[0]->rep & 0x4000) || (vgmsysPad[1]->rep & 0x1000) || (vgmsysPad[1]->rep & 0x4000)) {
                    nmvcPlayCursor(1);
                    vayOptData->movecnt = 0;
                    vayOptData->select[1] ^= 1;
                }
            }
        } else {
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 4) {
                vayOptData->movecnt = -1;
            }
        }
        break;
    case 0xD:
        mx = 2;
        break;
    case 0x14:
    case 0x17:
        mx = 3;
        break;
    case 0x15:
    case 0x18:
        mx = 4;
        break;
    case 0x16:
    case 0x19:
        mx = 5;
        break;
    }

    ayFontInitmin();
    for (ii = 0; ii < 2; ii++) {
        switch (mx) {
        case 0:
            dx = 0;
            break;
        case 1:
            if (count < ((ii + 1) * 4) + 0x10) {
                dx = -0x280;
            } else if (count < ((ii + 1) * 4) + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, (count - 0x10) - ((ii + 1) * 4), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 2:
            if (count < (ii + 1) * 4) {
                dx = 0;
            } else if (count < ((ii + 1) * 4) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - ((ii + 1) * 4), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        case 3:
            if (count < 4) {
                dx = 0;
            } else if (count < 0x14) {
                dx = ayCalcTotalMove(0x11, count - 4, 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        case 4:
            dx = 0;
            break;
        case 5:
            if (count < 0x14) {
                dx = -0x280;
            } else if (count < 0x24) {
                dx = -640.0f + ayCalcTotalMove(0x11, count - 0x14, 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        }

        if (vayOptData->select[1] == ii) {
            if (vayOptData->movecnt == -1) {
                size = 0x1C;
            } else if (vayOptData->movecnt < 2) {
                size = (vayOptData->movecnt * 2) + 0x1C;
            } else {
                size = 0x24 - (vayOptData->movecnt * 2);
            }

            if (mx == 3) {
                col = count * 64;
                col /= 46.0f;
                fcol[0] = 128.0f - col;
                col = 32.0f * count;
                col /= 46.0f;
                fcol[1] = 96.0f - col;
                col = count * 64;
                col /= 46.0f;
                fcol[2] = 64.0f + col;
                fcol[3] = 0x80;
            } else if (mx == 4) {
                fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
                size = 0x1C;
            } else if (mx == 5) {
                col = count * 64;
                col /= 46.0f;
                fcol[0] = 64.0f + col;
                col = 32.0f * count;
                col /= 46.0f;
                fcol[1] = 64.0f + col;
                col = count * 64;
                col /= 46.0f;
                fcol[2] = 128.0f - col;
                fcol[3] = 0x80;
            } else {
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            }
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }

        if ((vgmsysPad[ii]->state != 2) && (vgmsysPad[ii]->state != 6)) {
            for (jj = 0; jj < 3; jj++) {
                fcol[jj] /= 2;
            }
        }

        if ((mx == 3) && (vayOptData->select[1] == ii)) {
            nmfontSetCol(fcol);
            nmfontSetSize(size, size);
            cy = (214.0f + (ii * 32)) - (size / 2.0f);
            dy = cy - ayCalcTotalMove(0x2F, count, cy - 74.0f, 0);
            pos[0] = 320.0f - (nmfontGetPackStrLen(item[ii], size, 0) / 2.0f), pos[1] = dy, pos[2] = 16777215.0f, pos[3] = 0.0f;
            nmfontFPrintF(vgmsysGifPkt, item[ii], pos);
        } else if (mx == 4) {
            if (vayOptData->select[1] == ii) {
                nmfontSetCol(fcol);
                nmfontSetSize(size, size);
                dx -= nmfontGetPackStrLen(item[ii], size, 0) / 2;
                nmfontFPrint(vgmsysGifPkt, item[ii], dx + 0x140, 0x4A);
            }
        } else if ((mx == 5) && (vayOptData->select[1] == ii)) {
            nmfontSetCol(fcol);
            nmfontSetSize(size, size);
            cy = (214.0f + (ii * 32)) - (size / 2.0f);
            dy = 74.0f + ayCalcTotalMove(0x2F, count, cy - 74.0f, 0);
            pos[0] = 320.0f - (nmfontGetPackStrLen(item[ii], size, 0) / 2.0f), pos[1] = dy, pos[2] = 16777215.0f, pos[3] = 0.0f;
            nmfontFPrintF(vgmsysGifPkt, item[ii], pos);
        } else if ((mx == 2) && (vayOptData->step != 0xD) && (vayOptData->select[1] == ii)) {
            fcol[3] = 0x80 - (count * 18);
            size += count / 2;
            nmfontSetCol(fcol);
            nmfontSetSize(size, size);
            pos[0] = 320.0f - (nmfontGetPackStrLen(item[ii], size, 0) / 2.0f), pos[1] = ((214.0f + (ii * 32)) - (size / 2.0f)) - (count * (14.0f + ((((size / 2.0f) + (214.0f + (ii * 32))) - 74.0f) / 32.0f))), pos[2] = 16777215.0f, pos[3] = 0.0f;
            nmfontFPrintF(vgmsysGifPkt, item[ii], pos);
        } else {
            nmfontSetCol(fcol);
            nmfontSetSize(size, size);
            dx -= nmfontGetPackStrLen(item[ii], size, 0) / 2;
            nmfontFPrint(vgmsysGifPkt, item[ii], dx + 0x140, (214.0f + (ii * 32)) - (size / 2));
        }
    }
}

// // DWARF: 0x123A01
// // Address: 0x1CE6F0
// // Size: 0x1780
static void ayDrawOptChar() {
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // 0x23C(r29)
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // 0x240(r29)
    void* addr; // 0x244(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0xA0(r29)
    signed int arrAlpha; // 0x248(r29)
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xB0(r29)
    float xy[4]; // 0x190(r29)
    float pos[4]; // 0x1A0(r29)
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // 0x24C(r29)
    signed int ii; // r16
    signed int count = vayOptData->count; // r18
    signed int dispID; // r19
    signed int dx; // r20
    signed int dy; // r23
    signed int size; // r17
    signed int mx; // r22
    signed int id; // r30
    signed int col; // r21
    signed int cy; // 0x250(r29)
    signed int limit; // 0x254(r29)
    signed int fcol[4]; // 0x1B0(r29)
    char* movieList[3][3] = { { "ACTIVISION LOGO", "INTRO", "???" }, { "ACTIVISION-LOGO", "INTRO", "???" }, { "LOGO ACTIVISION", "INTRO", "???" } }; // 0x1C0(r29)
    char** movie = movieList[vspenvGame->language]; // 0x258(r29)
    char* list[17]; // 0x1F0(r29)

    loaddata = sploadGetSelectData();

    for (ii = 0; ii < 0x11; ii++) {
        if (vayOptData->movieFlg[ii]) {
            if (ii < 2) {
                list[ii] = movie[ii];
            } else {
                list[ii] = vsptblMovieName[ii - 2];
            }
        } else {
            list[ii] = movie[2];
        }
    }

    limit = 10;

    switch (vayOptData->step) {
    case 0x1A:
        mx = 1;
        dy = 0;
        break;
    case 0x1B:
        mx = 0;
        if (vayOptData->movecnt == -1) {
            dy = 0;
            if ((vgmsysPad[0]->rep & 0x1000) && ((vayOptData->dispSel[1] > 0) || (vayOptData->disp[1] > 0))) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = 0;
                if (vayOptData->dispSel[1] == 0) {
                    vayOptData->dispflg = -1;
                    vayOptData->disp[1]--;
                    dy = 0x20;
                } else {
                    vayOptData->dispflg = 0;
                    vayOptData->dispSel[1]--;
                }
            }
            if ((vgmsysPad[0]->rep & 0x4000) && ((vayOptData->dispSel[1] < 6) || (vayOptData->disp[1] < limit))) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = 2;
                if (vayOptData->dispSel[1] == 6) {
                    vayOptData->dispflg = 1;
                    vayOptData->disp[1]++;
                    dy = -0x20;
                } else {
                    vayOptData->dispSel[1]++;
                    vayOptData->dispflg = 0;
                }
            }
        } else {
            if (vayOptData->dispflg) {
                dy = ((vayOptData->moveflg - 1) * (vayOptData->movecnt * 8)) - (vayOptData->dispflg * 32);
            } else {
                dy = 0;
            }
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 4) {
                vayOptData->movecnt = -1;
                dy = 0;
            }
        }

        ultexResetTex(loaddata->offset);
        texData.tofs = -1;
        texData.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x29);

        addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);

        alpha = ((Alpha2*)addr)++;
        ulpktInitALPHA(alpha, 1);

        poly = addr;
        data.texdata = &texData;
        data.psmt = 0x14;

        arrAlpha = vaySelData->count % 0x80;
        if (arrAlpha < 0x40) {
            arrAlpha *= 2;
        } else {
            arrAlpha = 0x80 - ((arrAlpha - 0x40) * 2);
        }

        for (ii = 0; ii < 2; ii++) {
            if (((vayOptData->disp[1] == 0) && (ii == 0)) || ((vayOptData->disp[1] == limit) && (ii == 1))) {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0;
            } else {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = arrAlpha;
            }
            data.uv[0] = ii * 32, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x20;
            xy[0] = 256.0f, xy[1] = 29.0f + (148.0f * ii), xy[2] = 384.0f, xy[3] = 8.0f + xy[1];
            aySetVert(data.vert[0], xy, 1);
            aySetPolyComFT4(&poly[ii], &data, 1);
        }
        break;
    case 0x1C:
        mx = 2;
        dy = 0;
        break;
    case 0x23:
        mx = 4;
        dy = 0;
        break;
    case 0x24:
        mx = 5;
        dy = 0;
        break;
    case 0xE:
        mx = 6;
        dy = 0;
        break;
    case 0xF:
        mx = 7;
        dy = 0;
        break;
    case 0x10:
        mx = 8;
        dy = 0;
        break;
    }

    vayOptData->select[1] = vayOptData->dispSel[1] + vayOptData->disp[1];

    ayFontInitmin();
    for (ii = 0; ii < 7; ii++) {
        dispID = vayOptData->disp[1] + ii;
        switch (mx) {
        case 0:
            dx = 0;
            break;
        case 1:
        case 8:
            if (count < (((ii + 1) * 4) / 2) + 0x10) {
                dx = -0x280;
            } else if (count < (((ii + 1) * 4) / 2) + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, (count - 0x10) - (((ii + 1) * 4) / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 2:
        case 3:
        case 6:
            if (dispID < vayOptData->select[1]) {
                id = ii;
            } else {
                id = ii - 1;
            }
            if ((mx != 2) && (vayOptData->select[1] == dispID)) {
                dx = 0;
            } else if (count < ((id + 1) * 4) / 2) {
                dx = 0;
            } else if (count < (((id + 1) * 4) / 2) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - (((id + 1) * 4) / 2), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        case 4:
            if (dispID < vayOptData->select[1]) {
                id = ii;
            } else {
                id = ii - 1;
            }
            if ((mx == 3) && (vayOptData->select[1] == dispID)) {
                dx = 0;
            } else if (count < (id + 1) * 4) {
                dx = 0;
            } else if (count < ((id + 1) * 4) + 0x20) {
                dx = ayCalcTotalMove(0x21, count - ((id + 1) * 4), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        case 5:
            if (count < (((ii + 1) * 4) / 2) + 0x10) {
                dx = -0x280;
            } else if (count < (((ii + 1) * 4) / 2) + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, (count - 0x10) - (((ii + 1) * 4) / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 7:
            dx = 0;
            break;
        }

        if (vayOptData->select[1] == dispID) {
            if (vayOptData->movecnt == -1) {
                size = 0x1C;
            } else if (vayOptData->movecnt < 2) {
                size = (vayOptData->movecnt * 2) + 0x1C;
            } else {
                size = 0x24 - (vayOptData->movecnt * 2);
            }

            if (mx == 6) {
                col = count << 6;
                col /= 46;
                fcol[0] = 0x80 - col;
                col = 32.0f * count;
                col /= 46;
                fcol[1] = 0x60 - col;
                col = count << 6;
                col /= 46;
                fcol[2] = col + 0x40;
                fcol[3] = 0x80;
            } else if (mx == 7) {
                fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
                size = 0x1C;
            } else if (mx == 8) {
                col = count << 6;
                col /= 46;
                fcol[0] = col + 0x40;
                col = 32.0f * count;
                col /= 46;
                fcol[1] = col + 0x40;
                col = count << 6;
                col /= 46;
                fcol[2] = 0x80 - col;
                fcol[3] = 0x80;
            } else {
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            }
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }

        if (!vayOptData->movieFlg[dispID]) {
            fcol[0] /= 2;
            fcol[1] /= 2;
            fcol[2] /= 2;
        }

        if (((dy > 0) && (ii == 0)) || ((dy < 0) && (ii == 6))) {
            fcol[3] = vayOptData->movecnt << 5;
        }

        if ((mx == 6) && (vayOptData->select[1] == dispID)) {
            nmfontSetCol(fcol);
            nmfontSetSize(size, size);
            cy = ((118.0f + (ii << 5)) - dy) - (size / 2);
            pos[0] = 320.0f - (nmfontGetPackStrLen(list[dispID], size, 0) / 2.0f), pos[1] = cy - ayCalcTotalMove(0x2F, count, cy - 74.0f, 0), pos[2] = 16777215.0f, pos[3] = 0.0f;
            nmfontFPrintF(vgmsysGifPkt, (char*)list[dispID], pos);
        } else if (mx == 7) {
            if (vayOptData->select[1] == dispID) {
                nmfontSetCol(fcol);
                nmfontSetSize(size, size);
                dx = nmfontGetPackStrLen(list[dispID], size, 0) / 2;
                nmfontFPrint(vgmsysGifPkt, (char*)list[dispID], 0x140 - dx, 0x4A);
            }
        } else if ((mx == 8) && (vayOptData->select[1] == dispID)) {
            nmfontSetCol(fcol);
            nmfontSetSize(size, size);
            cy = ((118.0f + (ii << 5)) - dy) - (size / 2);
            pos[0] = 320.0f - (nmfontGetPackStrLen(list[dispID], size, 0) / 2.0f), pos[1] = 74.0f + ayCalcTotalMove(0x2F, count, cy - 74.0f, 0), pos[2] = 16777215.0f, pos[3] = 0.0f;
            nmfontFPrintF(vgmsysGifPkt, (char*)list[dispID], pos);
        } else if (((mx == 3) || (mx == 4)) && (vayOptData->select[1] == dispID)) {
            if (count < 0x20) {
                fcol[3] = 0x80 - (count * 4);
                nmfontSetCol(fcol);
                size += count / 2;
                nmfontSetSize(size, size);
                pos[0] = 320.0f - (nmfontGetPackStrLen(list[dispID], size, 0) / 2.0f), pos[1] = (((118.0f + (ii << 5)) - dy) - (size / 2.0f)) - (count * ((((size / 2.0f) + (118.0f + (ii << 5))) - 74.0f) / 32.0f)), pos[2] = 16777215.0f, pos[3] = 0.0f;
                nmfontFPrintF(vgmsysGifPkt, (char*)list[dispID], pos);
            }
        } else {
            nmfontSetSize(size, size);
            dx -= nmfontGetPackStrLen(list[dispID], size, 0) / 2;
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, (char*)list[dispID], dx + 0x140, ((118.0f + (ii << 5)) - dy) - (size / 2));
        }
    }

    if (dy != 0) {
        if (dy < 0) {
            dispID = vayOptData->disp[1] - 1;
            dy = (86.0f - dy) - 10.0f;
        } else if (dy > 0) {
            dispID = vayOptData->disp[1] + 7;
            dy = (342.0f - dy) - 10.0f;
        }
        dx = nmfontGetPackStrLen(list[dispID], 0x14, 0) / 2;
        if (vayOptData->movieFlg[dispID]) {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80 - (vayOptData->movecnt << 5);
        } else {
            fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80 - (vayOptData->movecnt << 5);
        }
        nmfontSetCol(fcol);
        nmfontSetSize(0x14, 0x14);
        nmfontFPrint(vgmsysGifPkt, (char*)list[dispID], 0x140 - dx, dy);
    }
}

// // DWARF: 0x123EF1
// // Address: 0x1CFE70
// // Size: 0x13F8
static void ayDrawCheat() {
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // r30
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // 0x1E8(r29)
    void* addr; // 0x1EC(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0xA0(r29)
    signed int arrAlpha; // 0x1F0(r29)
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xB0(r29)
    float xy[4]; // 0x190(r29)
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // 0x1F4(r29)
    signed int ii; // r17
    signed int jj; // r16
    signed int count = vayOptData->count; // 0x1F8(r29)
    signed int dispID; // r19
    signed int dx; // r23
    signed int dy; // r18
    signed int size; // r22
    signed int mx; // 0x1FC(r29)
    signed int id; // 0x200(r29)
    signed int fcol[4]; // 0x1A0(r29)
    signed int* selflg; // 0x204(r29)
    signed int* swflg; // 0x208(r29)
    char* swList[3][2] = { { "OFF", "ON" }, { "AUS", "EIN" }, { "NON", "OUI" } }; // 0x1B0(r29)
    char** sw = swList[vspenvGame->language]; // 0x20C(r29)
    char* strList[3][2] = { { "RESET TO DEFAULTS", "BACK" }, { "ZUR\x94" "CKSETZEN", "ZUR\x94" "CK" }, { "REGLAGES PAR DEFAUT", "RETOUR" } }; // 0x1D0(r29)
    char** str = strList[vspenvGame->language]; // 0x210(r29)

    selflg = &vspenvOption->enable.kids;
    swflg = &vspenvOption->cheats.kids;

    loaddata = sploadGetSelectData();

    switch (vayOptData->step) {
    case 0x28:
        mx = 1;
        dy = 0;
        break;
    case 0x29:
        mx = 0;
        if (vayOptData->movecnt == -1) {
            dy = 0;
            if ((vgmsysPad[0]->rep & 0x1000) && ((vayOptData->dispSel[1] > 0) || (vayOptData->disp[1] > 0))) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = 0;
                vayOptData->select[1]--;
                if (vayOptData->dispSel[1] == 0) {
                    vayOptData->dispflg = -1;
                    vayOptData->disp[1]--;
                    dy = 0x20;
                } else {
                    vayOptData->dispflg = 0;
                    vayOptData->dispSel[1]--;
                }
            } else if ((vgmsysPad[0]->rep & 0x4000) && ((vayOptData->dispSel[1] < 6) || (vayOptData->disp[1] < 5))) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = 2;
                vayOptData->select[1]++;
                if (vayOptData->dispSel[1] == 6) {
                    vayOptData->dispflg = 1;
                    vayOptData->disp[1]++;
                    dy = -0x20;
                } else {
                    vayOptData->dispSel[1]++;
                    vayOptData->dispflg = 0;
                }
            } else if (((vgmsysPad[0]->rep & 0x8000) || (vgmsysPad[0]->rep & 0x2000)) && selflg[vayOptData->select[1]] && (vayOptData->select[1] < 0xA)) {
                nmvcPlayCursor(1);
                swflg[vayOptData->select[1]] ^= 1;
            }
        } else {
            if (vayOptData->dispflg) {
                dy = ((vayOptData->moveflg - 1) * (vayOptData->movecnt * 8)) - (vayOptData->dispflg * 32);
            } else {
                dy = 0;
            }
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 4) {
                vayOptData->movecnt = -1;
                dy = 0;
            }
        }

        ultexResetTex(loaddata->offset);
        texData.tofs = -1;
        texData.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x29);

        addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);

        alpha = ((Alpha2*)addr)++;
        ulpktInitALPHA(alpha, 1);

        poly = addr;
        data.texdata = &texData;
        data.psmt = 0x14;

        arrAlpha = vaySelData->count % 0x80;
        if (arrAlpha < 0x40) {
            arrAlpha *= 2;
        } else {
            arrAlpha = 0x80 - ((arrAlpha - 0x40) * 2);
        }

        for (ii = 0; ii < 2; ii++) {
            if (((vayOptData->disp[1] == 0) && (ii == 0)) || ((vayOptData->disp[1] == 5) && (ii == 1))) {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0;
            } else {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = arrAlpha;
            }
            data.uv[0] = ii * 32, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x20;
            xy[0] = 256.0f, xy[1] = 29.0f + (148.0f * ii), xy[2] = 384.0f, xy[3] = 8.0f + xy[1];
            aySetVert(&data.vert[0][0], xy, 1);
            aySetPolyComFT4(&poly[ii], &data, 1);
        }
        break;
    case 0x2A:
        mx = 2;
        dy = 0;
        break;
    }

    ayFontInitmin();
    for (ii = 0; ii < 7; ii++) {
        dispID = vayOptData->disp[1] + ii;
        switch (mx) {
        case 0:
            dx = 0;
            break;
        case 1:
            if (count < (((ii + 1) * 4) / 2) + 0x10) {
                dx = -0x280;
            } else if (count < (((ii + 1) * 4) / 2) + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, (signed int)((count - 0x10) - (((ii + 1) * 4) / 2)), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 2:
            if ((mx != 3) || (dispID < vayOptData->select[1])) {
                id = ii;
            } else {
                id = ii - 1;
            }
            if ((mx != 2) && (vayOptData->select[1] == dispID)) {
                dx = 0;
            } else if (count < ((id + 1) * 4) / 2) {
                dx = 0;
            } else if (count < (((id + 1) * 4) / 2) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - (((id + 1) * 4) / 2), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        }

        if (vayOptData->select[1] == dispID) {
            if (vayOptData->movecnt == -1) {
                size = 0x18;
            } else if (vayOptData->movecnt < 2) {
                size = vayOptData->movecnt + 0x18;
            } else {
                size = 0x1C - vayOptData->movecnt;
            }
            fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }

        if (((dy > 0) && (ii == 0)) || ((dy < 0) && (ii == 6))) {
            fcol[3] = vayOptData->movecnt << 5;
        }

        nmfontSetSize(size, size);
        if (dispID < 0xA) {
            if (selflg[dispID]) {
                nmfontSetCol(fcol);
                nmfontFPrint(vgmsysGifPkt, (char*)vsptblCheats[dispID], (dx + 0x118) - (nmfontGetPackStrLen(vsptblCheats[dispID], size, 0) / 2), ((118.0f + (ii << 5)) - dy) - (size / 2));
                nmfontFPrint(vgmsysGifPkt, sw[swflg[dispID]], (dx + 0x208) - (nmfontGetPackStrLen(sw[swflg[dispID]], size, 0) / 2), ((118.0f + (ii << 5)) - dy) - (size / 2));
                if ((vayOptData->select[1] == dispID) && (vayOptData->step == 0x29)) {
                    ultexResetTex(loaddata->offset);
                    texData.tofs = -1;
                    texData.cofs = -1;
                    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x2A);

                    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);

                    alpha = ((Alpha2*)addr)++;
                    ulpktInitALPHA(alpha, 1);

                    poly = addr;
                    data.texdata = &texData;
                    data.psmt = 0x14;
                    for (jj = 0; jj < 2; jj++) {
                        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = fcol[3];
                        data.uv[0] = jj * 32, data.uv[1] = 0x20, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x40;
                        xy[0] = 448.0f + (112.0f * jj), xy[1] = (((118.0f + (ii << 5)) - dy) / 2.0f) - 8.0f, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
                        aySetVert(data.vert[0], xy, 1);
                        aySetPolyComFT4(&poly[jj], &data, 1);
                    }
                }
            } else {
                fcol[0] /= 2;
                fcol[1] /= 2;
                fcol[2] /= 2;
                nmfontSetCol(fcol);
                nmfontFPrint(vgmsysGifPkt, "? ? ?", (dx + 0x140) - (nmfontGetPackStrLen("? ? ?", size, 0) / 2), ((118.0f + (ii << 5)) - dy) - (size / 2));
            }
        } else {
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, str[dispID - 0xA], (dx + 0x140) - (nmfontGetPackStrLen(str[dispID - 0xA], size, 0) / 2), ((118.0f + (ii << 5)) - dy) - (size / 2));
        }
    }

    if (dy != 0) {
        if (dy < 0) {
            dispID = vayOptData->disp[1] - 1;
            dy = (86.0f - dy) - 10.0f;
        } else if (dy > 0) {
            dispID = vayOptData->disp[1] + 7;
            dy = (342.0f - dy) - 10.0f;
        }
        nmfontSetSize(0x14, 0x14);
        fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80 - (vayOptData->movecnt << 5);
        if (dispID < 0xA) {
            if (selflg[dispID]) {
                nmfontSetCol(fcol);
                nmfontFPrint(vgmsysGifPkt, (char*)vsptblCheats[dispID], 0x118 - (nmfontGetPackStrLen(vsptblCheats[dispID], 0x14, 0) / 2), dy);
                nmfontFPrint(vgmsysGifPkt, sw[swflg[dispID]], 0x208 - (nmfontGetPackStrLen(sw[swflg[dispID]], 0x14, 0) / 2), dy);
            } else {
                fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80 - (vayOptData->movecnt << 5);
                nmfontSetCol(fcol);
                nmfontFPrint(vgmsysGifPkt, "? ? ?", 0x140 - (nmfontGetPackStrLen("? ? ?", 0x14, 0) / 2), dy);
            }
        } else {
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, str[dispID - 0xA], (dx + 0x140) - (nmfontGetPackStrLen(str[dispID - 0xA], size, 0) / 2), dy);
        }
    }
}

// // DWARF: 0x1243F7
// // Address: 0x1D1270
// // Size: 0x118C
static signed int ayDrawEdit() {
    signed int ret = 0; // 0x208(r29)
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // r30
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // 0x20C(r29)
    void* addr; // r23
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0xB0(r29)
    signed int arrAlpha; // 0x210(r29)
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xC0(r29)
    float xy[4]; // 0x1A0(r29)
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // 0x214(r29)
    signed int ii; // r16
    signed int count = vayOptData->count; // r21
    signed int dx; // r17
    signed int dy; // r19
    signed int size; // r18
    signed int mx; // 0x218(r29)
    signed int no = 1; // 0x21C(r29)
    signed int id; // r20
    signed int checkFlg; // r22
    signed int fcol[4]; // 0x1B0(r29)
    char* swList[3][2] = { { "OFF", "ON" }, { "AUS", "EIN" }, { "OFF", "ON" } }; // 0x1C0(r29)
    char** sw = swList[vspenvGame->language]; // 0x220(r29)
    char* strList[3][3] = { { "SHUFFLE", "RESET TO DEFAULTS", "BACK" }, { "SHUFFLE", "ZUR\x94" "CKSETZEN", "ZUR\x94" "CK" }, { "SHUFFLE", "REGLAGES PAR DEFAUT", "RETOUR" } }; // 0x1E0(r29)
    char** str = strList[vspenvGame->language]; // 0x224(r29)
    char musicID[4]; // 0x228(r29)

    loaddata = sploadGetSelectData();

    switch (vayOptData->step) {
    case 0x2B:
        mx = 1;
        break;
    case 0x2C:
        mx = 0;
        if ((vayOptData->movecnt == -1) && (vayOptData->moveflg == -1) && (vayOptData->trackcnt > -2)) {
            if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->trackcnt = -1;
                if (vayOptData->select[1] == 0) {
                    vayOptData->select[1] = 0xE;
                } else {
                    vayOptData->select[1]--;
                }
            } else if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->trackcnt = -1;
                if (vayOptData->select[1] == 0xE) {
                    vayOptData->select[1] = 0;
                } else {
                    vayOptData->select[1]++;
                }
            } else if (vgmsysPad[0]->rep & 0x8000) {
                vayOptData->trackcnt = -1;
                if (vayOptData->select[1] < 0xC) {
                    nmvcPlayCursor(1);
                    if (vspenvOption->bgm.table[vayOptData->select[1]] == 0) {
                        vspenvOption->bgm.table[vayOptData->select[1]] = 0xB;
                    } else {
                        vspenvOption->bgm.table[vayOptData->select[1]]--;
                    }
                } else if (vayOptData->select[1] == 0xC) {
                    nmvcPlayCursor(1);
                    vspenvOption->bgm.random ^= 1;
                }
            } else if (vgmsysPad[0]->rep & 0x2000) {
                vayOptData->trackcnt = -1;
                if (vayOptData->select[1] < 0xC) {
                    nmvcPlayCursor(1);
                    if (vspenvOption->bgm.table[vayOptData->select[1]] == 0xB) {
                        vspenvOption->bgm.table[vayOptData->select[1]] = 0;
                    } else {
                        vspenvOption->bgm.table[vayOptData->select[1]]++;
                    }
                } else if (vayOptData->select[1] == 0xC) {
                    nmvcPlayCursor(1);
                    vspenvOption->bgm.random ^= 1;
                }
            } else if (vgmsysPad[0]->trg & 0x40) {
                if (vayOptData->select[1] < 0xC) {
                    if (vspenvOption->bgm.disable & (1 << vayOptData->select[1])) {
                        nmvcPlay(2, 1, 8);
                    } else {
                        nmvcPlayButton(2);
                    }
                    vspenvOption->bgm.disable ^= 1 << vayOptData->select[1];
                    vayOptData->moveflg = 0;
                } else if (vayOptData->select[1] == 0xD) {
                    nmvcPlayButton(0);
                    vspenvOption->bgm.random = 0;
                    vspenvOption->bgm.disable = -1;
                    for (ii = 0; ii < 0xC; ii++) {
                        vspenvOption->bgm.table[ii] = ii;
                        vspenvOption->bgm.disable ^= 1 << ii;
                    }
                } else if ((vayOptData->select[1] == 0xE) && (vayOptData->trackcnt == -1)) {
                    nmvcPlayButton(0);
                    ret = 1;
                }
            } else if ((vgmsysPad[0]->trg & 0x10) && (vayOptData->trackcnt == -1)) {
                nmvcPlayButton(2);
                ret = 1;
            }
        } else if (vayOptData->movecnt != -1) {
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 4) {
                vayOptData->movecnt = -1;
            }
        } else if (vayOptData->moveflg != -1) {
            vayOptData->moveflg++;
            if (vayOptData->moveflg == 4) {
                vayOptData->moveflg = -1;
            }
        } else if ((vayOptData->trackcnt == -3) && (nmbgmCheckQue() == 0)) {
            vayOptData->trackcnt = -1;
        }

        if ((vayOptData->trackcnt == -1) && ((vgmsysPad[0]->rev & 0x2000) || (vgmsysPad[0]->rev & 0x8000) || (vgmsysPad[0]->rev & 0x1000) || (vgmsysPad[0]->rev & 0x4000))) {
            vayOptData->trackcnt = 0;
        }

        if (vayOptData->trackcnt >= 0) {
            vayOptData->trackcnt++;
            if (vayOptData->trackcnt == 0x1E) {
                if ((vayOptData->select[1] < 0xC) && (vspenvOption->bgm.table[vayOptData->select[1]] != nmbgmGetSelect())) {
                    nmbgmChange(8, vspenvOption->bgm.table[vayOptData->select[1]], 0);
                    vayOptData->trackcnt = -3;
                } else {
                    vayOptData->trackcnt = -1;
                }
            }
        }

        if (vayOptData->select[1] < 0xD) {
            ultexResetTex(loaddata->offset);
            texData.tofs = -1;
            texData.cofs = -1;
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x29);

            addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);

            alpha = ((Alpha2*)addr)++;
            ulpktInitALPHA(alpha, 1);

            poly = addr;
            data.texdata = &texData;
            data.psmt = 0x14;

            arrAlpha = vaySelData->count % 0x80;
            if (arrAlpha < 0x40) {
                arrAlpha *= 2;
            } else {
                arrAlpha = 0x80 - ((arrAlpha - 0x40) * 2);
            }

            for (ii = 0; ii < 2; ii++) {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = arrAlpha;
                data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x40;
                xy[0] = 22.0f + (568.0f * ii), xy[1] = 44.5f + (9.0f * vayOptData->select[1]), xy[2] = 22.0f + xy[0], xy[3] = 11.0f + xy[1];
                aySetVert(data.vert[0], xy, 1);
                aySetPolyComFT4(poly + ii, &data, 1);
            }
        }
        break;
    case 0x2D:
        mx = 2;
        break;
    }

    ayFontInitmin();
    for (ii = 0; ii < 0xF; ii++) {
        switch (mx) {
        case 0:
            dx = 0;
            break;
        case 1:
            if (count < (ii + 1) + 0x10) {
                dx = -0x280;
            } else if (count < (ii + 1) + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, (count - 0x10) - (ii + 1), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 2:
            if (count < ii + 1) {
                dx = 0;
            } else if (count < (ii + 1) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - (ii + 1), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        }

        if (vayOptData->select[1] == ii) {
            if (vayOptData->movecnt != -1) {
                size = 0x14;
            } else {
                size = 0x10;
            }
            fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
        } else {
            size = 0x10;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }

        nmfontSetSize(0x10, size);
        nmfontSetCol(fcol);
        dy = 18.0f + ((74.0f + (ii * 18)) - ((size - 0x10) / 2));

        if (ii < 0xC) {
            if (!(vspenvOption->bgm.disable & (1 << ii))) {
                checkFlg = 1;
            } else {
                checkFlg = 0;
            }

            id = vspenvOption->bgm.table[ii];

            if (checkFlg) {
                ulstdSprintf(musicID, "%2d", no);
                no++;
            } else {
                ulstdSprintf(musicID, " -");
            }

            nmfontFPrint(vgmsysGifPkt, musicID, dx + 0x32, dy);

            if (nmfontGetPackStrLen(vbgmtblMusic[id], 0xE, 0) > 0x104) {
                nmfontSetSize(0xC, size);
            } else {
                nmfontSetSize(0xE, size);
            }
            nmfontFPrint(vgmsysGifPkt, (char*)vbgmtblMusic[id], dx + 0x64, dy);

            nmfontSetSize(0xE, size);
            nmfontFPrint(vgmsysGifPkt, (char*)vbgmtblArtist[id], dx + 0x19A, dy);

            nmfontSetSize(0x10, 0x10);
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, "\x83", dx + 0x50, dy + ((size - 0x10) / 2));

            if (checkFlg) {
                ultexResetTex(loaddata->offset);
                texData.tofs = -1;
                texData.cofs = -1;
                ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x28);

                addr = ulgifAddCNTReserve(vgmsysGifPkt, 9);

                alpha = ((Alpha2*)addr)++;
                ulpktInitALPHA(alpha, 1);

                poly = addr;
                data.texdata = &texData;
                data.psmt = 0x14;

                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
                if ((vayOptData->moveflg == -1) || (vayOptData->select[1] != ii)) {
                    data.uv[0] = 0x20, data.uv[1] = 0x60, data.uv[2] = 0x40, data.uv[3] = 0x80;
                    xy[0] = 74.0f + dx, xy[1] = 42.0f + (9.0f * ii), xy[2] = 24.0f + xy[0], xy[3] = 12.0f + xy[1];
                } else {
                    data.uv[0] = 0x20, data.uv[1] = 0x60, data.uv[2] = (vayOptData->moveflg * 5) + 0x2C, data.uv[3] = 0x80;
                    xy[0] = 74.0f + dx, xy[1] = 42.0f + (9.0f * ii), xy[2] = (8.0f + xy[0]) + (4.0f * vayOptData->moveflg), xy[3] = 12.0f + xy[1];
                }
                aySetVert(data.vert[0], xy, 0xFFFFFF);
                aySetPolyComFT4(poly, &data, 1);
            }
        } else {
            id = ii - 0xC;
            nmfontFPrint(vgmsysGifPkt, str[id], dx + 0x50, dy);
            if (id == 0) {
                nmfontFPrint(vgmsysGifPkt, sw[vspenvOption->bgm.random], dx + 0xC8, dy);
            }
        }
    }

    return ret;
}

// // DWARF: 0x1248F1
// // Address: 0x1D2400
// // Size: 0x4DC
static void ayCalcScore() {
    signed int ii; // r16
    signed int col; // r17
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // r20
    signed int count; // r21
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // r22
    void* addr; // r23
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // r30
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0x190(r29)

    count = vayOptData->count;

    switch (vayOptData->step) {
    case 0x14:
        if (count >= 0x10) {
            ayDrawScore(0, -2, count - 0x10);
        }
        break;
    case 0x15:
        if (vayOptData->movecnt == -1) {
            ayDrawScore(vayOptData->select[2], 0, 0);
            if (vgmsysPad[0]->cnt & 0x2000) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = 1;
                vayOptData->next = ayCalcNextID(vayOptData->select[2], 8, 1);
            } else if (vgmsysPad[0]->cnt & 0x8000) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = -1;
                vayOptData->next = ayCalcNextID(vayOptData->select[2], 8, -1);
            }
        } else {
            if (vayOptData->movecnt < 0x10) {
                ayDrawScore(vayOptData->select[2], vayOptData->moveflg, vayOptData->movecnt);
            } else if (vayOptData->movecnt < 0x1E) {
                ayDrawScore(vayOptData->select[2], vayOptData->moveflg, vayOptData->movecnt);
                ayDrawScore(vayOptData->next, vayOptData->moveflg * 2, vayOptData->movecnt - 0x10);
            } else {
                ayDrawScore(vayOptData->next, vayOptData->moveflg * 2, vayOptData->movecnt - 0x10);
            }
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 0x2E) {
                vayOptData->movecnt = -1;
                vayOptData->select[2] = vayOptData->next;
            }
        }
        break;
    case 0x16:
        if (count < 0x10) {
            ayDrawScore(vayOptData->select[2], -1, count);
        }
        break;
    }

    loaddata = sploadGetSelectData();
    if ((vayOptData->step == 0x15) && (vayOptData->movecnt == -1)) {
        col = vaySelData->count % 0x80;
        if (col < 0x40) {
            col *= 2;
        } else {
            col = 0x80 - ((col - 0x40) * 2);
        }

        ultexResetTex(loaddata->offset);
        texData.tofs = -1;
        texData.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x29);

        addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);

        alpha = (Alpha2*)addr;
        addr = alpha + 1;
        ulpktInitALPHA(alpha, 1);

        poly = addr;
        data.texdata = &texData;
        data.psmt = 0x14;
        for (ii = 0; ii < 2; ii++) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x40;
            xy[0] = 20.0f + (590.0f * ii), xy[1] = 96.0f, xy[2] = 16.0f + xy[0], xy[3] = 32.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(&poly[ii], &data, 1);
        }
    }
}

// // DWARF: 0x124BC1
// // Address: 0x1D28E0
// // Size: 0x738
static void ayDrawScore(signed int cs, signed int mx, signed int count) {
    signed int ii; // r16
    signed int dx; // r17
    signed int dy; // r18
    // Size: 0x20, DWARF: 0x11B653
    Record* rec; // r19
    signed int fcol[4]; // 0xA0(r29)
    char* rankList[3][6] = { { "1ST", "2ND", "3RD", "4TH", "5TH", "6TH" }, { "1.", "2.", "3.", "4.", "5.", "6." }, { "1ER", "2EME", "3EME", "4EME", "5EME", "6EME" } }; // 0xB0(r29)
    char** rank = &(*rankList[vspenvGame->language]); // r23
    // Size: 0x10, DWARF: 0x11B3E3
    FData fdata; // 0x100(r29)

    rec = &(*vspenvRecord[cs])[0];

    nmfontInitOption();
    nmfontSetBil(1);
    fdata.size = 0x12;

    for (ii = 0; ii < 7; ii++) {
        switch (mx) {
        case 0:
            dx = 0;
            break;
        case 1:
            if (count < (ii * 4) / 2) {
                dx = 0;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = -ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 3);
            } else {
                dx = -0x280;
            }
            break;
        case 2:
            if (count < (ii * 4) / 2) {
                dx = 0x280;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = 640.0f - ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case -1:
            if (count < (ii * 4) / 2) {
                dx = 0;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        case -2:
            if (count < (ii * 4) / 2) {
                dx = -0x280;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = -640.0f + ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        }

        if (ii == 0) {
            nmfontSetPack(1);
            fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            nmfontSetSize(0x1C, 0x1C);
            nmfontFPrint(vgmsysGifPkt, (char*)vsptblCourseName[cs], dx + 0x28, 0x58);
        } else {
            nmfontSetSize(0x12, 0x18);
            dy = 136.0f + ((ii - 1) * 36);
            nmfontSetPack(0);
            fcol[0] = 0x80, fcol[1] = (((ii - 1) * 64) / 5) + 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, rank[ii - 1], dx + 0x28, dy);
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, rec[ii - 1].name, dx + 0x72, dy);
            nmfontSetPack(1);
            if (rec[ii - 1].chr_no < 0xC) {
                nmfontFPrint(vgmsysGifPkt, (char*)vsptblCharacterName[rec[ii - 1].chr_no], dx + 0xBC, dy);
            } else {
                nmfontFPrint(vgmsysGifPkt, vspenvSecret->create_character[rec[ii - 1].chr_no - 0xC].name, dx + 0xBC, dy);
            }
            fdata.value = rec[ii - 1].score;
            fdata.dx = 604.0f + dx;
            fdata.dy = dy;
            ayDrawNum(vgmsysGifPkt, &fdata, 1);
        }
    }
}

// // DWARF: 0x124EB9
// // Address: 0x1D3020
// // Size: 0x7B4
static void ayCalcGap() {
    signed int ii; // r16
    signed int col; // r17
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // r18
    signed int count; // r30
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0x190(r29)
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // 0x1AC(r29)
    void* addr; // 0x1B0(r29)
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // 0x1B4(r29)

    count = vayOptData->count;

    switch (vayOptData->step) {
    case 0xE:
        if (count >= 10) {
            ayDrawGap(0, -2, count - 10, 0);
        }
        break;
    case 0xF:
        if (vayOptData->movecnt == -1) {
            ayDrawGap(vayOptData->select[2], 0, 0, vayOptData->select[3]);
            if (vgmsysPad[0]->cnt & 0x2000) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = 1;
                vayOptData->next = ayCalcNextID(vayOptData->select[2], 8, 1);
            } else if (vgmsysPad[0]->cnt & 0x8000) {
                nmvcPlayCursor(1);
                vayOptData->movecnt = 0;
                vayOptData->moveflg = -1;
                vayOptData->next = ayCalcNextID(vayOptData->select[2], 8, -1);
            } else if ((vgmsysPad[0]->rep & 0x1000) && (vayOptData->select[3] > 0)) {
                nmvcPlayCursor(1);
                vayOptData->select[3]--;
            } else if ((vgmsysPad[0]->rep & 0x4000) && (vayOptData->select[3] < vsptblCourseParam[vayOptData->select[2]][4] - 11)) {
                nmvcPlayCursor(1);
                vayOptData->select[3]++;
            }
        } else {
            if (vayOptData->movecnt < 0x10) {
                ayDrawGap(vayOptData->select[2], vayOptData->moveflg, vayOptData->movecnt, vayOptData->select[3]);
            } else if (vayOptData->movecnt < 0x28) {
                ayDrawGap(vayOptData->select[2], vayOptData->moveflg, vayOptData->movecnt, vayOptData->select[3]);
                ayDrawGap(vayOptData->next, vayOptData->moveflg * 2, vayOptData->movecnt - 0x10, 0);
            } else {
                ayDrawGap(vayOptData->next, vayOptData->moveflg * 2, vayOptData->movecnt - 0x10, 0);
            }
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 0x38) {
                vayOptData->movecnt = -1;
                vayOptData->select[2] = vayOptData->next;
                vayOptData->disp[2] = 0;
                vayOptData->dispSel[2] = 0;
                vayOptData->select[3] = 0;
            }
        }
        break;
    case 0x10:
        if (count < 0x27) {
            ayDrawGap(vayOptData->select[2], -1, count, vayOptData->select[3]);
        }
        break;
    }

    loaddata = sploadGetSelectData();
    if ((vayOptData->step == 0xF) && ((vayOptData->movecnt == -1) || ((vayOptData->moveflg != 1) && (vayOptData->moveflg != -1)))) {
        col = vaySelData->count % 0x80;
        if (col < 0x40) {
            col *= 2;
        } else {
            col = 0x80 - ((col - 0x40) * 2);
        }

        ultexResetTex(loaddata->offset);
        texData.tofs = -1;
        texData.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x29);

        addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x1E);

        alpha = ((Alpha2*)addr)++;
        ulpktInitALPHA(alpha, 1);

        poly = addr;
        data.texdata = &texData;
        data.psmt = 0x14;
        for (ii = 0; ii < 2; ii++) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x40;
            xy[0] = 20.0f + (590.0f * ii), xy[1] = 96.0f, xy[2] = 16.0f + xy[0], xy[3] = 32.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(&poly[ii], &data, 1);
        }

        for (ii = 0; ii < 2; ii++) {
            if (((vayOptData->select[3] == 0) && (ii == 0)) || ((vayOptData->select[3] == vsptblCourseParam[vayOptData->select[2]][4] - 11) && (ii == 1))) {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0;
            } else {
                data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
            }
            data.uv[0] = ii * 32, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x20;
            xy[0] = 288.0f, xy[1] = 55.0f + (130.0f * ii), xy[2] = 64.0f + xy[0], xy[3] = 8.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(&poly[ii + 2], &data, 1);
        }
    }
}

// // DWARF: 0x12519D
// // Address: 0x1D37E0
// // Size: 0x7CC
static void ayDrawGap(signed int cs, signed int mx, signed int count, signed int num) {
    signed int ii; // r16
    signed int dx; // r17
    signed int dy; // r19
    char str[32]; // 0xA0(r29)
    signed int fcol[4]; // 0xC0(r29)
    // Size: 0x10, DWARF: 0x11B3E3
    FData fdata; // 0xD0(r29)
    char* totalList[3] = { "%d OF %d GAPS", "%d VON %d GAPS", "%d / %d GAPS" }; // 0xE8(r29)
    char* total = totalList[vspenvGame->language]; // 0xF4(r29)
    unsigned long gap = vspenvSecret->course[cs].gap; // r21
    signed int csgap = vsptblCourseParam[cs][4]; // r18
    signed int gapnum = 0; // r20

    for (ii = 0; ii < csgap; ii++) {
        if (gap & ((unsigned long)1 << (long)ii)) {
            gapnum += 1;
        }
    }

    nmfontInitOption();
    nmfontSetBil(1);
    fdata.size = 0x10;

    for (ii = 0; (ii < 0xC) && (ii < csgap + 1); ii++) {
        switch (mx) {
        case 0:
            dx = 0;
            break;
        case 1:
            if (count < (ii * 4) / 2) {
                dx = 0;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = -ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 3);
            } else {
                dx = -0x280;
            }
            break;
        case 2:
            if (count < (ii * 4) / 2) {
                dx = 0x280;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = 640.0f - ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case -1:
            if (count < (ii * 4) / 2) {
                dx = 0;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        case -2:
            if (count < (ii * 4) / 2) {
                dx = -0x280;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = -640.0f + ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        default:
            dx = 0;
            break;
        }

        if (ii == 0) {
            nmfontSetPack(1);
            fcol[0] = 0x80, fcol[1] = 0x20, fcol[2] = 0, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            nmfontSetSize(0x16, 0x16);
            nmfontFPrint(vgmsysGifPkt, (char*)vsptblCourseName[cs], (dx + 0xB4) - (nmfontGetPackStrLen(vsptblCourseName[cs], 0x16, 0) / 2), 0x52);
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            ulstdSprintf(str, total, gapnum, csgap);
            nmfontFPrint(vgmsysGifPkt, str, dx + (0x262 - nmfontGetPackStrLen(str, 0x16, 0)), 0x52);
        } else {
            nmfontSetPack(1);
            nmfontSetSize(0x10, 0x10);
            dy = 130.0f + ((ii - 1) * 22);
            if (gap & ((unsigned long)1 << (long)((ii + num) - 1))) {
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, (char*)vsptblGapList[cs][(ii + num) - 1], dx + 0x50, dy);
            fdata.value = vsptblGapPoint[cs][(ii + num) - 1];
            fdata.dx = 560.0f + dx;
            fdata.dy = dy;
            ayDrawNum(vgmsysGifPkt, &fdata, 1);
        }
    }
}


// DWARF: 0x125528
// Address: 0x1D3FB0
// Size: 0x1DB0
static void ayDrawKeyConfig() {
    // Size: 0x120, DWARF: 0x12125F
    MdlEnv mdlEnv; // 0xA0(r29)
    float mat[4][4]; // 0x1C0(r29)
    float trans[4] = { 150.0f, -4.0f, 149.0f, 1.0f }; // 0x200(r29)
    float rot[4] = { 1.403189f, 0.0f, 0.0f, 1.0f }; // 0x210(r29)
    float worldScr[4][4]; // 0x220(r29)
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // r21
    signed int movebutton; // r23
    signed int ii; // r16
    signed int size; // r18
    signed int tmp; // 0x440(r29)
    signed int count = vayOptData->count; // r19
    signed int mx; // 0x444(r29)
    signed int dx; // r17
    signed int lx; // r22
    signed int vibFlg; // 0x448(r29)
    signed int player = vayOptData->select[1]; // r30
    // Size: 0x60, DWARF: 0x11DD93
    VibData* vibdata; // 0x44C(r29)
    // Size: 0x2, DWARF: 0x120249
    ActData actdata; // 0x450(r29)
    signed int fcol[4]; // 0x260(r29)
    char* grab[3][8] = { { "SPIN LEFT", "REVERT&SWITCH", "SPIN RIGHT", "REVERT&SWITCH", "SLIDE&PLANT", "GRAB", "JUMP&BONK", "FLIP" }, { "SPIN LINKS", "REVERT&SWITCH", "SPIN RECHTS", "REVERT&SWITCH", "SLIDE&PLANT", "GRAB", "SPRINGEN & BONKEN", "FLIP" }, { "GAUCHE", "INVERSE ET CHANGEMENT", "DROITE", "INVERSE ET CHANGEMENT", "SLIDE ET PLANT", "GRAB", "SAUT ET BONK", "FLIP" } }; // 0x270(r29)
    char** grablist = grab[vspenvGame->language]; // 0x454(r29)
    char* itemList[3][2] = { { "RESET TO DEFAULTS", "BACK" }, { "ZUR\x94" "CKSETZEN", "ZUR\x94" "CK" }, { "REINITIALISATION", "RETOUR" } }; // 0x2D0(r29)
    char** item = itemList[vspenvGame->language]; // 0x458(r29)
    char* button[8] = { "\x82", "\x80", "\x81", "\x83", "L1", "L2", "R1", "R2" }; // 0x2F0(r29)
    char* strList[3][4] = { { "BUTTON:", "VIBRATION:", "ON", "OFF" }, { "-TASTE: ", "VIBRATION: ", "EIN", "AUS" }, { "TOUCHE:", "VIBRATIONS:", "OUI", "NON" } }; // 0x310(r29)
    char** str = strList[vspenvGame->language]; // r20
    // Size: 0x70, DWARF: 0x11D020
    Poly* poly; // 0x45C(r29)
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // 0x460(r29)
    void* addr; // 0x464(r29)
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0x340(r29)
    float xy[4]; // 0x420(r29)
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0x430(r29)
    signed int arrAlpha; // 0x468(r29)

    if (vgmsysPad[player]->state == 2) {
        vibFlg = 0;
        if (vayOptData->select[2] == 8) {
            vayOptData->select[2] = 9;
            nmvcPlayCursor(1);
            vayOptData->movecnt = 0;
            vayOptData->moveflg = 1;
        }
        if (vayOptData->vib == 1) {
            vayOptData->vib = 0;
            ulpadStopDual(player, 0, 0);
            ulpadSetDual(player, 0, 0);
        }
    } else {
        vibFlg = 1;
    }

    vibdata = sploadGetVibrationData();

    aySetCamMatrix(worldScr, mdlEnv.world_view, mdlEnv.view_screen);
    aySetLightMatrix(mdlEnv.normal_light, mdlEnv.light_color, 0.4f, 0.2f);

    switch (vayOptData->step) {
    case 0x17:
        count -= 0x16;
        mx = 0;
        movebutton = -1;
        if (count < 0) {
            trans[0] = -702.0f;
        } else if (count < 0x10) {
            trans[0] = ayCalcTotalMove(0x11, count, 852.0f, 1) - 672.0f;
        } else {
            trans[0] = 150.0f;
            rot[0] += 0.15579712f * (count - 0x10);
        }
        break;
    case 0x18:
        if (vayOptData->select[2] < 4) {
            rot[0] = 2.649566f;
        }
        mx = 1;

        if (vayOptData->movecnt == -1) {
            if (vaySelData->bocount == -1) {
                if (vgmsysPad[player]->rep & 0x1000) {
                    nmvcPlayCursor(1);
                    vayOptData->movecnt = 0;
                    vayOptData->moveflg = -1;
                    if (vayOptData->select[2] == 0) {
                        vayOptData->select[2] = 6;
                    } else if (vayOptData->select[2] < 4) {
                        tmp = vayOptData->padlist[vayOptData->select[2]];
                        aySetKeyDiff(0, tmp);
                        vayOptData->select[2]--;
                    } else if (vayOptData->select[2] == 5) {
                        if (!vibFlg) {
                            vayOptData->select[2] = 3;
                        } else {
                            vayOptData->select[2]--;
                        }
                    } else {
                        vayOptData->select[2]--;
                    }
                } else if (vgmsysPad[player]->rep & 0x4000) {
                    nmvcPlayCursor(1);
                    vayOptData->movecnt = 0;
                    vayOptData->moveflg = 1;
                    if (vayOptData->select[2] < 3) {
                        tmp = vayOptData->padlist[vayOptData->select[2]];
                        aySetKeyDiff(0, tmp);
                        vayOptData->select[2]++;
                    } else if (vayOptData->select[2] == 3) {
                        tmp = vayOptData->padlist[vayOptData->select[2]];
                        aySetKeyDiff(0, tmp);
                        if (!vibFlg) {
                            vayOptData->select[2] = 5;
                        } else {
                            vayOptData->select[2]++;
                        }
                    } else if (vayOptData->select[2] == 6) {
                        vayOptData->select[2] = 0;
                    } else {
                        vayOptData->select[2]++;
                    }
                } else if (vgmsysPad[player]->rep & 0x2000) {
                    if (vayOptData->select[2] < 4) {
                        nmvcPlayCursor(1);
                        if (vayOptData->padlist[vayOptData->select[2]] < 3) {
                            vayOptData->padlist[vayOptData->select[2]]++;
                        } else {
                            vayOptData->padlist[vayOptData->select[2]] = 0;
                        }
                    } else if (vayOptData->select[2] == 4) {
                        nmvcPlayCursor(1);
                        if (vayOptData->vib == 1) {
                            ulpadStopDual(player, 0, 0);
                            ulpadSetDual(player, 0, 0);
                            vayOptData->vib = 0;
                        } else {
                            ulpadSetDual(player, 0, 1);
                            vayOptData->vib = 1;
                            ulpadInitDual(vibdata->data[0], player, 0, 0);
                        }
                    }
                } else if (vgmsysPad[player]->rep & 0x8000) {
                    if (vayOptData->select[2] < 4) {
                        nmvcPlayCursor(1);
                        if (vayOptData->padlist[vayOptData->select[2]] > 0) {
                            vayOptData->padlist[vayOptData->select[2]]--;
                        } else {
                            vayOptData->padlist[vayOptData->select[2]] = 3;
                        }
                    } else if (vayOptData->select[2] == 4) {
                        nmvcPlayCursor(1);
                        if (vayOptData->vib == 1) {
                            ulpadStopDual(player, 0, 0);
                            ulpadSetDual(player, 0, 0);
                            vayOptData->vib = 0;
                        } else {
                            ulpadSetDual(player, 0, 1);
                            vayOptData->vib = 1;
                            ulpadInitDual(vibdata->data[0], player, 0, 0);
                        }
                    }
                }
            }
        } else {
            if (((vayOptData->moveflg == -1) && (vayOptData->select[2] == 3)) || ((vayOptData->moveflg == 1) && (vayOptData->select[2] == 0))) {
                rot[0] = 1.403189f + ((1.246377f * vayOptData->movecnt) / 4.0f);
            } else if (((vayOptData->moveflg == 1) && (vayOptData->select[2] == 4)) || ((vayOptData->moveflg == -1) && (vayOptData->select[2] == 6))) {
                rot[0] = 2.649566f - ((1.246377f * vayOptData->movecnt) / 4.0f);
            }
            vayOptData->movecnt++;
            if (vayOptData->movecnt == 4) {
                vayOptData->movecnt = -1;
            }
        }

        if (vayOptData->select[2] < 4) {
            movebutton = vayOptData->select[2] + 1;
        } else {
            movebutton = -1;
        }

        actdata = ulpadGetActData(player, 0, 0);
        if (actdata.act1 != 0) {
            rot[1] = 0.001f * ((unsigned char)actdata.act1 - 0.5f);
        }
        if (actdata.act0 != 0) {
            rot[2] = 0.005f * ((vayOptData->count % 8) - 4);
        }
        break;
    case 0x19:
        if (count < 0x14) {
            if (vayOptData->select[2] < 4) {
                rot[0] = 2.649566f - (0.051932376f * count);
            }
            trans[0] = 150.0f;
        } else if (count < 0x24) {
            trans[0] = 150.0f + ayCalcTotalMove(0x11, count - 0x14, 552.0f, 3);
        } else {
            trans[0] = 702.0f;
        }
        mx = 2;
        movebutton = -1;
        break;
    }

    loaddata = sploadGetSelectData();

    size = ultexGetNTex(loaddata->pad_utd);
    ultexResetTex(loaddata->offset);
    for (ii = 0; ii < size; ii++) {
        if ((movebutton > 0) && (ii == movebutton + 5)) {
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &loaddata->pad_tex[ii], movebutton + 0x19);
        } else {
            ultexTransTexTag(vgmsysGifPkt, loaddata->pad_utd, &loaddata->pad_tex[ii], ii);
        }
    }

    mdlEnv.fog.enable = 0;
    for (ii = 0; ii < 9; ii++) {
        if (movebutton == ii) {
            dx = count % 0x40;
            if (dx >= 0x20) {
                dx = 0x40 - dx;
            }
            if (ii > 0) {
                trans[1] += sqrtf(dx / 5.0f);
                trans[2] += sqrtf(dx / 5.0f);
            } else {
                trans[2] += dx / 8.0f;
            }
        } else {
            trans[1] = 0.0f;
            trans[2] = 149.0f;
        }

        sceVu0UnitMatrix(mat);
        sceVu0RotMatrixX(mat, mat, rot[0]);
        sceVu0RotMatrixY(mat, mat, rot[1]);
        sceVu0RotMatrixZ(mat, mat, rot[2]);
        sceVu0TransMatrix(mat, mat, trans);
        ul3dScaleMatrixXYZ(mat, 0.75f, 0.75f, 0.75f);

        sceGifPkCnt(vgmsysGifPkt, 0, 0, 0);
        sceGifPkReserve(vgmsysGifPkt, ulmdlDrawModelPkt((unsigned int*)vgmsysGifPkt->pCurrent, vgmsysAbuf, &mdlEnv, mat, loaddata->pad_umd[ii], 1));
        sceGifPkTerminate(vgmsysGifPkt);
    }

    if ((vayOptData->step == 0x18) && (vayOptData->select[2] < 5)) {
        ultexResetTex(loaddata->offset);
        texData.tofs = -1;
        texData.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x29);

        addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);

        alpha = ((Alpha2*)addr)++;
        ulpktInitALPHA(alpha, 1);

        arrAlpha = vaySelData->count % 0x80;
        if (arrAlpha < 0x40) {
            arrAlpha *= 2;
        } else {
            arrAlpha = 0x80 - ((arrAlpha - 0x40) * 2);
        }

        poly = addr;
        data.texdata = &texData;
        data.psmt = 0x14;
        for (ii = 0; ii < 2; ii++) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = arrAlpha;
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = data.uv[0] + 0x20, data.uv[3] = 0x40;
            if (vspenvGame->language == 2) {
                xy[0] = 450.0f * ii, xy[1] = 51.0f + (((vayOptData->select[2] + 4) * 24) / 2.0f), xy[2] = 24.0f + xy[0], xy[3] = 12.0f + xy[1];
            } else {
                xy[0] = 350.0f * ii, xy[1] = 51.0f + (((vayOptData->select[2] + 4) * 24) / 2.0f), xy[2] = 24.0f + xy[0], xy[3] = 12.0f + xy[1];
            }
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(&poly[ii], &data, 1);
        }
    }

    ayFontInitmin();
    for (ii = 0; ii < 0xB; ii++) {
        switch (mx) {
        case 0:
            if (count < (ii * 4) / 2) {
                dx = -0x320;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = -800.0f + ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 640.0f, 1);
            } else {
                dx = -0xA0;
            }
            break;
        case 1:
            dx = -0xA0;
            break;
        case 2:
            if (count < (ii * 4) / 2) {
                dx = -0xA0;
            } else if (count < ((ii * 4) / 2) + 0x10) {
                dx = ayCalcTotalMove(0x11, count - ((ii * 4) / 2), 800.0f, 3) - 160.0f;
            } else {
                dx = 0x280;
            }
            break;
        }

        if (ii < 4) {
            fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
            nmfontSetSize(0x10, 0x10);
            nmfontSetCol(fcol);
            lx = (dx + 0x140) - nmfontGetPackStrLen(str[0], 0x10, 0);
            nmfontFPrint(vgmsysGifPkt, button[ii], (lx - 0x10) - (nmfontGetPackStrLen(button[ii], 0x10, 0) / 2), 106.0f + (ii * 24));
            nmfontFPrint(vgmsysGifPkt, str[0], lx, 106.0f + (ii * 24));
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, grablist[ii + 4], dx + 0x140, 106.0f + (ii * 24));
        } else if (ii < 8) {
            if (ii == vayOptData->select[2] + 4) {
                if (vayOptData->movecnt != -1) {
                    size = 0x14;
                } else {
                    size = 0x10;
                }
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                size = 0x10;
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            }
            nmfontSetSize(0x10, size);
            nmfontSetCol(fcol);
            lx = (dx + 0x140) - nmfontGetPackStrLen(str[0], 0x10, 0);
            nmfontFPrint(vgmsysGifPkt, button[ii], (lx - 0x10) - (nmfontGetPackStrLen(button[ii], 0x10, 0) / 2), (106.0f + (ii * 24)) - ((size - 0x10) / 2));
            nmfontFPrint(vgmsysGifPkt, str[0], lx, (106.0f + (ii * 24)) - ((size - 0x10) / 2));
            nmfontSetCol(fcol);
            nmfontFPrint(vgmsysGifPkt, grablist[vayOptData->padlist[ii - 4]], dx + 0x140, (106.0f + (ii * 24)) - ((size - 0x10) / 2));
        } else {
            if (vayOptData->select[2] == ii - 4) {
                if (vayOptData->movecnt != -1) {
                    size = 0x14;
                } else {
                    size = 0x10;
                }
                if (!vibFlg && (ii == 8)) {
                    fcol[0] = 0x40, fcol[1] = 0x30, fcol[2] = 0x20, fcol[3] = 0x80;
                } else {
                    fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
                }
            } else {
                size = 0x10;
                if (!vibFlg && (ii == 8)) {
                    fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
                } else {
                    fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
                }
            }
            nmfontSetSize(0x10, size);
            nmfontSetCol(fcol);
            if (ii == 8) {
                nmfontFPrint(vgmsysGifPkt, str[1], (dx + 0x140) - nmfontGetPackStrLen(str[1], 0x10, 0), (106.0f + (ii * 24)) - ((size - 0x10) / 2));
                if (vayOptData->vib == 1) {
                    nmfontFPrint(vgmsysGifPkt, str[2], dx + 0x140, (106.0f + (ii * 24)) - ((size - 0x10) / 2));
                } else {
                    nmfontFPrint(vgmsysGifPkt, str[3], dx + 0x140, (106.0f + (ii * 24)) - ((size - 0x10) / 2));
                }
            } else {
                nmfontFPrint(vgmsysGifPkt, item[ii - 9], (dx + 0x140) - (nmfontGetPackStrLen(item[ii - 9], 0x10, 0) / 2), (106.0f + (ii * 24)) - ((size - 0x10) / 2));
            }
        }
    }
}

// // DWARF: 0x125BA8
// // Address: 0x1D5D60
// // Size: 0x128
static void aySetKeyDiff(signed int no, signed int key) {
    signed int jj; // r16
    signed int useFlg; // r17
    signed int ii; // r18

    for (ii = no; ii < no + 4; ii++) {
        if ((vayOptData->padlist[ii] == key) && (ii != vayOptData->select[2])) {
            useFlg = 0;
            for (jj = no; jj < no + 4; jj++) {
                useFlg |= 1 << (vayOptData->padlist[jj] - no);
            }
            for (jj = 0; jj < 4; jj++) {
                if (!(useFlg & (1 << jj))) {
                    vayOptData->padlist[ii] = jj + no;
                    return;
                }
            }
            break;
        }
    }
}

// // DWARF: 0x125D36
// // Address: 0x1D5E90
// // Size: 0x120
static void ayOptBlackOut() {
    signed int count; // r16
    signed int col; // r18
    // Size: 0xE0, DWARF: 0x1216F3
    ModelData data; // 0x70(r29)
    float xy[4]; // 0x150(r29)
    void* addr; // r17
    // Size: 0x40, DWARF: 0x11B6DA
    Poly2* poly; // r19
    // Size: 0x20, DWARF: 0x11D341
    Alpha2* alpha; // r20

    (void)poly;

    count = vayOptData->count;

    addr = ulgifAddCNTReserve(vgmsysGifPkt, 6);

    alpha = (Alpha2*)addr;
    addr = alpha + 1;
    ulpktInitALPHA(alpha, 1);

    if (count < 0x20) {
        col = count * 4;
    } else {
        count -= 0x20;
        col = 0x80 - (count * 4);
    }

    data.col[0][0] = 0, data.col[0][1] = 0, data.col[0][2] = 0, data.col[0][3] = col;
    poly = addr;
    xy[0] = 0.0f, xy[1] = 0.0f, xy[2] = 640.0f, xy[3] = 224.0f;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComF4(poly, &data);
}
 
// // DWARF: 0x125F5E
// // Address: 0x1D5FB0
// // Size: 0x63C
static void aySetKeyOparate() {
    signed int kind; // r16
    signed int flg; // r17
    signed int count; // r18
    // Size: 0x16720, DWARF: 0x11B7F6
    Data* loaddata; // r19
    // Size: 0x10, DWARF: 0x11BD26
    TexData texData; // 0x50(r29)

    count = vayOptData->count;
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);

    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x28);

    switch (vayOptData->step) {
    case 0x5:
    case 0x8:
    case 0x1D:
        if (count < 0x20) {
            count /= 2;
            flg = 1;
            kind = 1;
        } else {
            flg = 0xA;
        }
        break;
    case 0x6:
        flg = 0;
        if (ayMcGetStep() == 6) {
            kind = 1;
        } else if (ayMcGetStep() == 8) {
            kind = 0;
        } else {
            flg = 0xA;
        }
        break;
    case 0x1E:
        flg = 0;
        if (ayMcGetStep() == 6) {
            kind = 1;
        } else if (ayMcGetStep() == 9) {
            kind = 0;
        } else {
            flg = 0xA;
        }
        break;
    case 0x9:
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
            flg = 0xA;
            break;
        }
        break;
    case 0x7:
    case 0xA:
    case 0x1F:
        if (count < 0x1E) {
            flg = 0xA;
        } else {
            count -= 0x1E;
            flg = -1;
            kind = 1;
        }
        break;
    case 0xE:
    case 0x14:
    case 0x28:
        if (count < 0xE) {
            flg = 0;
            kind = 1;
        } else if (count < 0x1E) {
            count -= 0xE;
            flg = 1;
            kind = 1;
        } else {
            count -= 0x1E;
            flg = -1;
            kind = 3;
        }
        break;
    case 0x10:
    case 0x16:
        if (count < 0xE) {
            flg = 0;
            kind = 3;
        } else if (count < 0x1C) {
            count -= 0xE;
            flg = 1;
            kind = 3;
        } else {
            count -= 0x1C;
            flg = -1;
            kind = 1;
        }
        break;
    case 0x11:
        flg = 0;
        if (count < 0x20) {
            kind = 1;
        } else {
            kind = 3;
        }
        break;
    case 0x12:
        flg = 0;
        if (vayOptData->select[1] == 3) {
            kind = 1;
        } else {
            kind = 3;
        }
        break;
    case 0x13:
        flg = 0;
        if (count < 0x20) {
            if (vayOptData->select[1] == 3) {
                kind = 1;
            } else {
                kind = 3;
            }
        } else {
            kind = 1;
        }
        break;
    case 0xF:
    case 0x15:
        flg = 0;
        kind = 3;
        break;
    case 0x17:
        if (count < 0x10) {
            flg = 1;
            kind = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            flg = -1;
            kind = 3;
        } else {
            flg = 0;
            kind = 3;
        }
        break;
    case 0x18:
        flg = 0;
        if (vayOptData->select[2] < 5) {
            kind = 3;
        } else {
            kind = 1;
        }
        break;
    case 0x19:
        if (vayOptData->select[2] >= 5) {
            flg = 0;
            kind = 1;
        } else if (count < 0x10) {
            flg = 1;
            kind = 3;
        } else if (count < 0x20) {
            count -= 0x10;
            flg = -1;
            kind = 1;
        } else {
            flg = 0;
            kind = 1;
        }
        break;
    case 0x20:
        kind = 1;
        flg = 0;
        if (count >= 0x20) {
            flg = 0xA;
        }
        break;
    case 0x22:
        kind = 1;
        flg = 0;
        if (count < 0x20) {
            flg = 0xA;
        }
        break;
    case 0x21:
        flg = 0xA;
        break;
    case 0x29:
        flg = 0;
        if (vayOptData->select[1] < 0xA) {
            kind = 3;
        } else {
            kind = 1;
        }
        break;
    case 0x2A:
        if (vayOptData->select[1] >= 0xA) {
            kind = 1;
            flg = 0;
        } else if (count < 0xE) {
            flg = 0;
            kind = 3;
        } else if (count < 0x1C) {
            count -= 0xE;
            flg = 1;
            kind = 3;
        } else {
            count -= 0x1C;
            flg = -1;
            kind = 1;
        }
        break;
    case 0x27:
        flg = 0xA;
        break;
    case 0x2B:
        if (count < 0x10) {
            flg = 1;
            kind = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            flg = -1;
            kind = 6;
        } else {
            flg = 0;
            kind = 6;
        }
        break;
    case 0x2C:
        flg = 0;
        kind = 6;
        break;
    case 0x2D:
        if (count < 0x10) {
            flg = 1;
            kind = 6;
        } else if (count < 0x20) {
            count -= 0x10;
            flg = -1;
            kind = 1;
        } else {
            flg = 0;
            kind = 1;
        }
        break;
    default:
        flg = 0;
        kind = 1;
        break;
    }

    if (flg != 0xA) {
        ayDrawKeyOparate(kind, count, flg, &texData, vgmsysGifPkt);
    }
}
