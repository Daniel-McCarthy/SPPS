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
#pragma dont_inline on // Allows generation of break instructions on division by variables that risk div by 0.

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

// Static data ///////////////////////////////////////////////////////////////////////

// ayresult.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x60, DWARF: 0x191BB2
typedef struct VaytblEnding
{
    char str[64]; // Offset: 0x0, DWARF: 0x191BCE
    sceVu0IVECTOR col; // Offset: 0x40, DWARF: 0x191BF0
    float size; // Offset: 0x50, DWARF: 0x191C12
    float ofs; // Offset: 0x54, DWARF: 0x191C33
} VaytblEnding;

// Size: 0x1F0, DWARF: 0x19074D
typedef struct VayResData
{
    signed int resKind; // Offset: 0x0, DWARF: 0x190769
    signed int ret; // Offset: 0x4, DWARF: 0x19078D
    signed int count; // Offset: 0x8, DWARF: 0x1907AD
    signed int bgcnt; // Offset: 0xC, DWARF: 0x1907CF
    signed int step; // Offset: 0x10, DWARF: 0x1907F1
    signed int nextStep; // Offset: 0x14, DWARF: 0x190812
    signed int next; // Offset: 0x18, DWARF: 0x190837
    signed int movecnt; // Offset: 0x1C, DWARF: 0x190858
    signed int menu; // Offset: 0x20, DWARF: 0x19087C
    signed int stat; // Offset: 0x24, DWARF: 0x19089D
    signed int rem[5]; // Offset: 0x28, DWARF: 0x1908BE
    signed int select[2]; // Offset: 0x3C, DWARF: 0x1908E0
    signed int save; // Offset: 0x44, DWARF: 0x190905
    signed int chara[2]; // Offset: 0x48, DWARF: 0x190926
    signed int wear[2][22]; // Offset: 0x50, DWARF: 0x19094A
    signed int board[2][22]; // Offset: 0x100, DWARF: 0x19096D
    signed int handi[2]; // Offset: 0x1B0, DWARF: 0x190991
    signed int decide[2]; // Offset: 0x1B8, DWARF: 0x1909B5
    signed int rotcnt[2]; // Offset: 0x1C0, DWARF: 0x1909DA
    signed int cs; // Offset: 0x1C8, DWARF: 0x1909FF
    signed int type; // Offset: 0x1CC, DWARF: 0x190A1E
    signed int rule; // Offset: 0x1D0, DWARF: 0x190A3F
    signed int envChara[2]; // Offset: 0x1D4, DWARF: 0x190A60
    signed int envCs; // Offset: 0x1DC, DWARF: 0x190A87
    signed int decideflg; // Offset: 0x1E0, DWARF: 0x190AA9
    signed int decidecnt; // Offset: 0x1E4, DWARF: 0x190ACF
    signed int conf; // Offset: 0x1E8, DWARF: 0x190AF5
    float scrY; // Offset: 0x1EC, DWARF: 0x190B16
} VayResData;

// Size: 0x1C, DWARF: 0x190B61
typedef struct Parameter
{
    signed int ollie; // Offset: 0x0, DWARF: 0x190B7D
    signed int spin; // Offset: 0x4, DWARF: 0x190B9F
    signed int speed; // Offset: 0x8, DWARF: 0x190BC0
    signed int landing; // Offset: 0xC, DWARF: 0x190BE2
    signed int balance; // Offset: 0x10, DWARF: 0x190C06
    signed int stability; // Offset: 0x14, DWARF: 0x190C2A
    signed int stance; // Offset: 0x18, DWARF: 0x190C50
} Parameter;

// Size: 0x74, DWARF: 0x191176
typedef struct Character
{
    signed int secret; // Offset: 0x0, DWARF: 0x191192
    unsigned int board; // Offset: 0x4, DWARF: 0x1911B5
    unsigned int course; // Offset: 0x8, DWARF: 0x1911D7
    signed int rem_point; // Offset: 0xC, DWARF: 0x1911FA
    signed int old_brd_no; // Offset: 0x10, DWARF: 0x191220
    signed int old_wear_no; // Offset: 0x14, DWARF: 0x191247
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x19126F
    signed int soft[8]; // Offset: 0x38, DWARF: 0x191298
    // Size: 0x1C, DWARF: 0x190B61
    Parameter parameter; // Offset: 0x58, DWARF: 0x1912BB
} Character;

// Size: 0x18, DWARF: 0x192BA7
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0x192BC3
    signed int month; // Offset: 0x4, DWARF: 0x192BE4
    signed int day; // Offset: 0x8, DWARF: 0x192C06
    signed int hour; // Offset: 0xC, DWARF: 0x192C26
    signed int minute; // Offset: 0x10, DWARF: 0x192C47
    signed int second; // Offset: 0x14, DWARF: 0x192C6A
} Clock;

// Size: 0xEC, DWARF: 0x191E04
typedef struct Create_Character
{
    // Size: 0x74, DWARF: 0x191176
    Character character; // Offset: 0x0, DWARF: 0x191E20
    // Size: 0x1C, DWARF: 0x190B61
    Parameter init_param; // Offset: 0x74, DWARF: 0x191E48
    // Size: 0x18, DWARF: 0x192BA7
    Clock clock; // Offset: 0x90, DWARF: 0x191E71
    char name[16]; // Offset: 0xA8, DWARF: 0x191E95
    signed int age; // Offset: 0xB8, DWARF: 0x191EB8
    signed int sex; // Offset: 0xBC, DWARF: 0x191ED8
    signed int face; // Offset: 0xC0, DWARF: 0x191EF8
    signed int hair; // Offset: 0xC4, DWARF: 0x191F19
    signed int hair_color; // Offset: 0xC8, DWARF: 0x191F3A
    signed int body; // Offset: 0xCC, DWARF: 0x191F61
    signed int body_color; // Offset: 0xD0, DWARF: 0x191F82
    signed int pants; // Offset: 0xD4, DWARF: 0x191FA9
    signed int pants_color; // Offset: 0xD8, DWARF: 0x191FCB
    signed int glove; // Offset: 0xDC, DWARF: 0x191FF3
    signed int boots; // Offset: 0xE0, DWARF: 0x192015
    signed int board_type; // Offset: 0xE4, DWARF: 0x192037
    signed int trick_type; // Offset: 0xE8, DWARF: 0x19205E
} Create_Character;

// Size: 0x8, DWARF: 0x192B43
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0, DWARF: 0x192B5F
} CourseGap;

// Size: 0xEF8, DWARF: 0x192305
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0x191176
    Character character[12]; // Offset: 0x0, DWARF: 0x192321
    // Size: 0xEC, DWARF: 0x191E04
    Create_Character create_character[10]; // Offset: 0x570, DWARF: 0x192349
    // Size: 0x8, DWARF: 0x192B43
    CourseGap course[8]; // Offset: 0xEA8, DWARF: 0x192378
    signed int tour_round; // Offset: 0xEE8, DWARF: 0x19239D
    signed int old_char; // Offset: 0xEEC, DWARF: 0x1923C4
    signed int first_clear; // Offset: 0xEF0, DWARF: 0x1923E9
} VspenvSecret;

// Size: 0x38, DWARF: 0x18D790
typedef struct File
{
    // Size: 0x18, DWARF: 0x192BA7
    Clock clock; // Offset: 0x0, DWARF: 0x18D7AB
    char name[32]; // Offset: 0x18, DWARF: 0x18D7CF
} File;

// Size: 0x8, DWARF: 0x18E96E
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x18E98A
    signed char lh; // Offset: 0x2, DWARF: 0x18E9AA
    signed char lv; // Offset: 0x3, DWARF: 0x18E9C9
    signed int analog; // Offset: 0x4, DWARF: 0x18E9E8
} PadData;

// Size: 0x24, DWARF: 0x18DC80
typedef struct Key
{
    signed int vibration; // Offset: 0x0, DWARF: 0x18DC9C
    signed int spin_l; // Offset: 0x4, DWARF: 0x18DCC2
    signed int spin_r; // Offset: 0x8, DWARF: 0x18DCE5
    signed int stance; // Offset: 0xC, DWARF: 0x18DD08
    signed int revert; // Offset: 0x10, DWARF: 0x18DD2B
    signed int grind; // Offset: 0x14, DWARF: 0x18DD4E
    signed int grab; // Offset: 0x18, DWARF: 0x18DD70
    signed int jump; // Offset: 0x1C, DWARF: 0x18DD91
    signed int flip; // Offset: 0x20, DWARF: 0x18DDB2
} Key;

// Size: 0x30, DWARF: 0x18F47C
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x18F498
    signed int always_sp; // Offset: 0x4, DWARF: 0x18F4B9
    signed int perfect_b; // Offset: 0x8, DWARF: 0x18F4DF
    signed int super_spin; // Offset: 0xC, DWARF: 0x18F505
    signed int half_g; // Offset: 0x10, DWARF: 0x18F52C
    signed int fast_motion; // Offset: 0x14, DWARF: 0x18F54F
    signed int super_speed; // Offset: 0x18, DWARF: 0x18F577
    signed int big_head; // Offset: 0x1C, DWARF: 0x18F59F
    signed int metallic; // Offset: 0x20, DWARF: 0x18F5C4
    signed int mirror; // Offset: 0x24, DWARF: 0x18F5E9
    signed int replay_view; // Offset: 0x28, DWARF: 0x18F60C
    signed int partition; // Offset: 0x2C, DWARF: 0x18F634
} Cheats;

// Size: 0x10, DWARF: 0x1913CC
typedef struct Brd_Param
{
    signed int speed; // Offset: 0x0, DWARF: 0x1913E8
    signed int stability; // Offset: 0x4, DWARF: 0x19140A
    signed int balance; // Offset: 0x8, DWARF: 0x191430
    signed int turning; // Offset: 0xC, DWARF: 0x191454
} Brd_Param;

// Size: 0x2DCEC, DWARF: 0x18F13B
typedef struct VspenvReplay
{
    // Size: 0x38, DWARF: 0x18D790
    File file; // Offset: 0x0, DWARF: 0x18F157
    signed int pid; // Offset: 0x38, DWARF: 0x18F17A
    signed int num_frame; // Offset: 0x3C, DWARF: 0x18F19A
    unsigned int game_time; // Offset: 0x40, DWARF: 0x18F1C0
    signed int endrun_frame; // Offset: 0x44, DWARF: 0x18F1E6
    // Size: 0x8, DWARF: 0x18E96E
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0x18F20F
    // Size: 0x24, DWARF: 0x18DC80
    Key key; // Offset: 0x2DB88, DWARF: 0x18F236
    // Size: 0xEC, DWARF: 0x191E04
    Create_Character character; // Offset: 0x2DBAC, DWARF: 0x18F258
    // Size: 0x30, DWARF: 0x18F47C
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0x18F280
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0x18F2A5
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0x18F2C8
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0x18F2EB
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0x18F30F
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0x18F332
    // Size: 0x10, DWARF: 0x1913CC
    Brd_Param brd_param; // Offset: 0x2DCDC, DWARF: 0x18F358
} VspenvReplay;

// Size: 0x4, DWARF: 0x1922C6
typedef struct Course
{
    signed int no; // Offset: 0x0, DWARF: 0x1922E2
} Course;

// Size: 0x1C, DWARF: 0x190B61
typedef struct Chr_Param
{
    signed int ollie; // Offset: 0x0, DWARF: 0x190B7D
    signed int spin; // Offset: 0x4, DWARF: 0x190B9F
    signed int speed; // Offset: 0x8, DWARF: 0x190BC0
    signed int landing; // Offset: 0xC, DWARF: 0x190BE2
    signed int balance; // Offset: 0x10, DWARF: 0x190C06
    signed int stability; // Offset: 0x14, DWARF: 0x190C2A
    signed int stance; // Offset: 0x18, DWARF: 0x190C50
} Chr_Param;

// Size: 0x3C, DWARF: 0x191929
typedef struct Character_Selection
{
    signed int no; // Offset: 0x0, DWARF: 0x191945
    signed int player; // Offset: 0x4, DWARF: 0x191964
    signed int wear; // Offset: 0x8, DWARF: 0x191987
    signed int board; // Offset: 0xC, DWARF: 0x1919A8
    // Size: 0x1C, DWARF: 0x190B61
    Chr_Param chr_param; // Offset: 0x10, DWARF: 0x1919CA
    // Size: 0x10, DWARF: 0x1913CC
    Brd_Param brd_param; // Offset: 0x2C, DWARF: 0x1919F2
} Character_Selection;

// Size: 0x18, DWARF: 0x192462
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x19247E
    signed int game_mode; // Offset: 0x4, DWARF: 0x1924A5
    signed int match_rule; // Offset: 0x8, DWARF: 0x1924CB
    signed int divide; // Offset: 0xC, DWARF: 0x1924F2
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x192515
} Mode;

// Size: 0xA0, DWARF: 0x190F54
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x1922C6
    Course course; // Offset: 0x0, DWARF: 0x190F70
    // Size: 0x3C, DWARF: 0x191929
    Character_Selection character[2]; // Offset: 0x4, DWARF: 0x190F95
    // Size: 0x18, DWARF: 0x192462
    Mode mode; // Offset: 0x7C, DWARF: 0x190FBD
    signed int language; // Offset: 0x94, DWARF: 0x190FE0
    signed int ending; // Offset: 0x98, DWARF: 0x191005
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x191028
} VspenvGame;

// Size: 0x8, DWARF: 0x18F02F
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0x18F04B
    signed int bgm; // Offset: 0x4, DWARF: 0x18F06A
} Volume;

// Size: 0x48, DWARF: 0x190458
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0x190474
    signed int disable; // Offset: 0x40, DWARF: 0x190498
    signed int random; // Offset: 0x44, DWARF: 0x1904BC
} Bgm;

// Size: 0x114, DWARF: 0x190599
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0x18DC80
    Key key_config[2]; // Offset: 0x0, DWARF: 0x1905B5
    // Size: 0x30, DWARF: 0x18F47C
    Cheats enable; // Offset: 0x48, DWARF: 0x1905DE
    // Size: 0x30, DWARF: 0x18F47C
    Cheats cheats; // Offset: 0x78, DWARF: 0x190603
    // Size: 0x8, DWARF: 0x18F02F
    Volume volume; // Offset: 0xA8, DWARF: 0x190628
    char name[16]; // Offset: 0xB0, DWARF: 0x19064D
    signed int divide; // Offset: 0xC0, DWARF: 0x190670
    signed int tutorial; // Offset: 0xC4, DWARF: 0x190693
    // Size: 0x48, DWARF: 0x190458
    Bgm bgm; // Offset: 0xC8, DWARF: 0x1906B8
    unsigned int movie; // Offset: 0x110, DWARF: 0x1906DA
} VspenvOption;

// Size: 0x4, DWARF: 0x18D8A7
typedef struct BestTime
{
    unsigned int time; // Offset: 0x0, DWARF: 0x18D8C2
} BestTime;

// Size: 0x20, DWARF: 0x18D3EA
typedef struct VspenvRecord
{
    signed int chr_no; // Offset: 0x0, DWARF: 0x18D405
    unsigned long score; // Offset: 0x8, DWARF: 0x18D428
    char name[16]; // Offset: 0x10, DWARF: 0x18D44A
} VspenvRecord;

// Size: 0xEF8, DWARF: 0x192305
typedef struct MemCard
{
    // Size: 0x38, DWARF: 0x18D790
    File file; // Offset: 0x0, DWARF: 0x103D27
    // Size: 0x20, DWARF: 0x18D3EA
    VspenvRecord record[8][6]; // Offset: 0x38, DWARF: 0x103D4A
    // Size: 0x4, DWARF: 0x18D8A7
    BestTime best_time[8]; // Offset: 0x638, DWARF: 0x103D6F
    // Size: 0x114, DWARF: 0x190599
    VspenvOption option; // Offset: 0x658, DWARF: 0x103D97
    // Size: 0xEF8, DWARF: 0x10A075
    VspenvSecret secret; // Offset: 0x770, DWARF: 0x103DBC
} MemCard;

// Size: 0x5D0E0, DWARF: 0x19021C
typedef struct VspenvEnv
{
    // Size: 0xA0, DWARF: 0x190F54
    VspenvGame game; // Offset: 0x0, DWARF: 0x190238
    // Size: 0x1668, DWARF: 0x18DBA6
    MemCard mc; // Offset: 0xA0, DWARF: 0x19025B
    // Size: 0x2DCEC, DWARF: 0x18F13B
    VspenvReplay replay[2]; // Offset: 0x1708, DWARF: 0x19027C
} VspenvEnv;

// Size: 0x20, DWARF: 0x18EC4B
typedef struct PadInputs
{
    signed int id; // Offset: 0x0, DWARF: 0x18EC67
    unsigned int now; // Offset: 0x4, DWARF: 0x18EC86
    unsigned int status; // Offset: 0x8, DWARF: 0x18ECA6
    unsigned int press; // Offset: 0xC, DWARF: 0x18ECC9
    signed char right_h; // Offset: 0x10, DWARF: 0x18ECEB
    signed char right_v; // Offset: 0x11, DWARF: 0x18ED0F
    signed char left_h; // Offset: 0x12, DWARF: 0x18ED33
    signed char left_v; // Offset: 0x13, DWARF: 0x18ED56
    unsigned char l_right; // Offset: 0x14, DWARF: 0x18ED79
    unsigned char l_left; // Offset: 0x15, DWARF: 0x18ED9D
    unsigned char l_up; // Offset: 0x16, DWARF: 0x18EDC0
    unsigned char l_down; // Offset: 0x17, DWARF: 0x18EDE1
    unsigned char r_up; // Offset: 0x18, DWARF: 0x18EE04
    unsigned char r_right; // Offset: 0x19, DWARF: 0x18EE25
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x18EE49
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x18EE6C
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x18EE8F
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x18EEAF
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x18EECF
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x18EEEF
} PadInputs;

// Size: 0x60, DWARF: 0x1902C9
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0x18EC4B
    PadInputs now; // Offset: 0x0, DWARF: 0x1902E5
    // Size: 0x20, DWARF: 0x18EC4B
    PadInputs old; // Offset: 0x20, DWARF: 0x190307
    unsigned int port; // Offset: 0x40, DWARF: 0x190329
    unsigned int slot; // Offset: 0x44, DWARF: 0x19034A
    unsigned int mode; // Offset: 0x48, DWARF: 0x19036B
    unsigned int trg; // Offset: 0x4C, DWARF: 0x19038C
    unsigned int rev; // Offset: 0x50, DWARF: 0x1903AC
    unsigned int cnt; // Offset: 0x54, DWARF: 0x1903CC
    unsigned int rep; // Offset: 0x58, DWARF: 0x1903EC
    signed int state; // Offset: 0x5C, DWARF: 0x19040C
} VgmsysPad;

// Size: 0x10, DWARF: 0x18D330
typedef struct Packet
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x18D34B
    __int128* pBase; // Offset: 0x4, DWARF: 0x18D373
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x18D398
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0x18D3BF
} Packet;

// Size: 0x10, DWARF: 0x18F684
typedef struct TexData
{
    signed short tofs; // Offset: 0x0, DWARF: 0x18F6A0
    signed short cofs; // Offset: 0x2, DWARF: 0x18F6C1
    signed short width; // Offset: 0x4, DWARF: 0x18F6E2
    signed short height; // Offset: 0x6, DWARF: 0x18F704
    signed short tw; // Offset: 0x8, DWARF: 0x18F727
    signed short th; // Offset: 0xA, DWARF: 0x18F746
    signed short image_bit; // Offset: 0xC, DWARF: 0x18F765
    signed short clut_bit; // Offset: 0xE, DWARF: 0x18F78B
} TexData;

// Size: 0x20, DWARF: 0x1914C4
typedef struct Utd
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0x1914E0
    // Size: 0x10, DWARF: 0x18F684
    TexData* tex; // Offset: 0x4, DWARF: 0x191503
    signed int ntex; // Offset: 0x8, DWARF: 0x191528
    signed int offset; // Offset: 0xC, DWARF: 0x191549
    signed int block; // Offset: 0x10, DWARF: 0x19156C
    unsigned int* frame; // Offset: 0x14, DWARF: 0x19158E
    signed int res[2]; // Offset: 0x18, DWARF: 0x1915B3
} Utd;

// Size: 0x20, DWARF: 0x18D58D
typedef struct MdlData
{
    sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x18D5A8
    sceVu0FVECTOR rot; // Offset: 0x10, DWARF: 0x18D5CA
} MdlData;

// Size: 0x10, DWARF: 0x18F921
typedef struct Address
{
    unsigned int type; // Offset: 0x0, DWARF: 0x18F93D
    float frame; // Offset: 0x4, DWARF: 0x18F95E
    signed short flg; // Offset: 0x8, DWARF: 0x18F980
    signed short non; // Offset: 0xA, DWARF: 0x18F9A0
    sceVu0FVECTOR* data; // Offset: 0xC, DWARF: 0x18F9C0
} Address;

// Size: 0xF0, DWARF: 0x18E4FB
typedef struct Seq
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0x18E517
    signed int loop; // Offset: 0x4, DWARF: 0x18E53C
    signed int mode; // Offset: 0x8, DWARF: 0x18E55D
    signed int write_flg; // Offset: 0xC, DWARF: 0x18E57E
    signed int now_local_id; // Offset: 0x10, DWARF: 0x18E5A4
    signed int now_top_id; // Offset: 0x14, DWARF: 0x18E5CD
    signed int next_local_id; // Offset: 0x18, DWARF: 0x18E5F4
    signed int next_top_id; // Offset: 0x1C, DWARF: 0x18E61E
    // Size: 0x20, DWARF: 0x18D58D
    MdlData* mdl_data; // Offset: 0x20, DWARF: 0x18E646
    float now_frame; // Offset: 0x24, DWARF: 0x18E670
    float next_frame; // Offset: 0x28, DWARF: 0x18E696
    float ratio; // Offset: 0x2C, DWARF: 0x18E6BD
    // Size: 0x10, DWARF: 0x18F921
    Address* now_pos_address; // Offset: 0x30, DWARF: 0x18E6DF
    // Size: 0x10, DWARF: 0x18F921
    Address* now_rot_address; // Offset: 0x34, DWARF: 0x18E710
    // Size: 0x10, DWARF: 0x18F921
    Address* next_pos_address; // Offset: 0x38, DWARF: 0x18E741
    // Size: 0x10, DWARF: 0x18F921
    Address* next_rot_address; // Offset: 0x3C, DWARF: 0x18E773
    sceVu0FVECTOR nowDir; // Offset: 0x40, DWARF: 0x18E7A5
    sceVu0FVECTOR nowTrans; // Offset: 0x50, DWARF: 0x18E7CA
    sceVu0FMATRIX now_matrix; // Offset: 0x60, DWARF: 0x18E7F1
    sceVu0FVECTOR pos; // Offset: 0xA0, DWARF: 0x18E81A
    sceVu0FVECTOR quat; // Offset: 0xB0, DWARF: 0x18E83C
    sceVu0FVECTOR pre_pos; // Offset: 0xC0, DWARF: 0x18E85F
    sceVu0FVECTOR pre_rot; // Offset: 0xD0, DWARF: 0x18E885
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0x18E8AB
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0x18E8D6
    signed int pad[2]; // Offset: 0xE8, DWARF: 0x18E900
} Seq;

// Size: 0x230, DWARF: 0x18FAE2
typedef struct IkParam
{
    sceVu0FVECTOR rot; // Offset: 0x0, DWARF: 0x18FAFE
    sceVu0FVECTOR trans; // Offset: 0x10, DWARF: 0x18FB20
    float off_trans[2][4]; // Offset: 0x20, DWARF: 0x18FB44
    sceVu0FMATRIX* boardMat; // Offset: 0x40, DWARF: 0x18FB6C
    sceVu0FMATRIX* board_local; // Offset: 0x44, DWARF: 0x18FB96
    sceVu0FMATRIX* thighMatL; // Offset: 0x48, DWARF: 0x18FBC3
    sceVu0FMATRIX* thighMatR; // Offset: 0x4C, DWARF: 0x18FBEE
    sceVu0FMATRIX* calfMatL; // Offset: 0x50, DWARF: 0x18FC19
    sceVu0FMATRIX* calfMatR; // Offset: 0x54, DWARF: 0x18FC43
    sceVu0FMATRIX* footMatL; // Offset: 0x58, DWARF: 0x18FC6D
    sceVu0FMATRIX* footMatR; // Offset: 0x5C, DWARF: 0x18FC97
    sceVu0FMATRIX* toeMatL; // Offset: 0x60, DWARF: 0x18FCC1
    sceVu0FMATRIX* toeMatR; // Offset: 0x64, DWARF: 0x18FCEA
    float thighLength[2]; // Offset: 0x68, DWARF: 0x18FD13
    float shinLength[2]; // Offset: 0x70, DWARF: 0x18FD3D
    signed int flg; // Offset: 0x78, DWARF: 0x18FD66
    signed int pad; // Offset: 0x7C, DWARF: 0x18FD86
    sceVu0FMATRIX footL; // Offset: 0x80, DWARF: 0x18FDA6
    sceVu0FMATRIX footR; // Offset: 0xC0, DWARF: 0x18FDCA
    sceVu0FMATRIX toeL; // Offset: 0x100, DWARF: 0x18FDEE
    sceVu0FMATRIX toeR; // Offset: 0x140, DWARF: 0x18FE11
    float off_trans_toe[2][4]; // Offset: 0x180, DWARF: 0x18FE34
    float thighLength_toe[2]; // Offset: 0x1A0, DWARF: 0x18FE60
    float shinLength_toe[2]; // Offset: 0x1A8, DWARF: 0x18FE8E
    sceVu0FMATRIX board; // Offset: 0x1B0, DWARF: 0x18FEBB
    sceVu0FMATRIX board_world; // Offset: 0x1F0, DWARF: 0x18FEDF
} IkParam;

// Size: 0x2E0, DWARF: 0x1927FA
typedef struct SoftCtrl
{
    sceVu0FVECTOR rot; // Offset: 0x0, DWARF: 0x192816
    sceVu0FVECTOR trans; // Offset: 0x10, DWARF: 0x192838
    sceVu0FVECTOR scale; // Offset: 0x20, DWARF: 0x19285C
    sceVu0FMATRIX matrix; // Offset: 0x30, DWARF: 0x192880
    sceVu0FMATRIX revision; // Offset: 0x70, DWARF: 0x1928A5
    // Size: 0x230, DWARF: 0x18FAE2
    IkParam ikparam; // Offset: 0xB0, DWARF: 0x1928CC
} SoftCtrl;

// Size: 0x1A0, DWARF: 0x191C7B
typedef struct SCtrl
{
    signed int type; // Offset: 0x0, DWARF: 0x191C97
    float power; // Offset: 0x4, DWARF: 0x191CB8
    float dir; // Offset: 0x8, DWARF: 0x191CDA
    float cnt; // Offset: 0xC, DWARF: 0x191CFA
    sceVu0FVECTOR head; // Offset: 0x10, DWARF: 0x191D1A
    sceVu0FVECTOR preHead; // Offset: 0x20, DWARF: 0x191D3D
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0x191D63
    sceVu0FVECTOR g_vector; // Offset: 0x170, DWARF: 0x191D8D
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0x191DB4
    signed int pad[3]; // Offset: 0x194, DWARF: 0x191DDE
} SCtrl;

// Size: 0x4B0, DWARF: 0x192089
typedef struct Soft
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x1920A5
    __int128* umd; // Offset: 0x4, DWARF: 0x1920C9
    __int128* smd; // Offset: 0x8, DWARF: 0x1920EC
    unsigned int* utd; // Offset: 0xC, DWARF: 0x19210F
    // Size: 0x10, DWARF: 0x18F684
    TexData* tex; // Offset: 0x10, DWARF: 0x192132
    // Size: 0xF0, DWARF: 0x18E4FB
    Seq* seq; // Offset: 0x14, DWARF: 0x192157
    signed int block; // Offset: 0x18, DWARF: 0x19217C
    unsigned int* frame; // Offset: 0x1C, DWARF: 0x19219E
    signed int res; // Offset: 0x20, DWARF: 0x1921C3
    // Size: 0x2E0, DWARF: 0x1927FA
    SoftCtrl ctrl; // Offset: 0x30, DWARF: 0x1921E3
    // Size: 0x1A0, DWARF: 0x191C7B
    SCtrl sctrl; // Offset: 0x310, DWARF: 0x192206
} Soft;

// Size: 0x500, DWARF: 0x18D5F0
typedef struct Data
{
    // Size: 0x20, DWARF: 0x1914C4
    Utd game; // Offset: 0x0, DWARF: 0x18D60B
    // Size: 0x20, DWARF: 0x1914C4
    Utd result; // Offset: 0x20, DWARF: 0x18D62E
    // Size: 0x4B0, DWARF: 0x192089
    Soft soft; // Offset: 0x40, DWARF: 0x18D653
    __int128* board_umd; // Offset: 0x4F0, DWARF: 0x18D676
    unsigned int* board_utd; // Offset: 0x4F4, DWARF: 0x18D69F
    unsigned int* ayboard_utd; // Offset: 0x4F8, DWARF: 0x18D6C8
    // Size: 0x10, DWARF: 0x18F684
    TexData* board_tex; // Offset: 0x4FC, DWARF: 0x18D6F3
} Data;

// Size: 0xE0, DWARF: 0x190DCB
typedef struct QuadData
{
    signed int col[4][4]; // Offset: 0x0, DWARF: 0x190DE7
    signed int vert[4][4]; // Offset: 0x40, DWARF: 0x190E09
    signed int uv[4]; // Offset: 0x80, DWARF: 0x190E2C
    sceVu0FMATRIX stq; // Offset: 0x90, DWARF: 0x190E4D
    // Size: 0x10, DWARF: 0x18F684
    TexData* texdata; // Offset: 0xD0, DWARF: 0x190E6F
    unsigned long psmt; // Offset: 0xD8, DWARF: 0x190E98
} QuadData;

// Size: 0x10, DWARF: 0x18DDD7
typedef struct GifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0x18DDF3, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0x18DE1F, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x18DE49, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0x18DE75, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0x18DE9E, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0x18DEC8, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0x18DEF3, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0x18DF1D, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0x18DF48, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0x18DF74, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0x18DFA0, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0x18DFCC, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0x18DFF8, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0x18E024, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0x18E050, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0x18E07C, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0x18E0A8, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0x18E0D4, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0x18E100, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0x18E12D, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0x18E15A, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0x18E187, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0x18E1B4, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0x18E1E1, Bit Offset: 60, Bit Size: 4
} GifTag;

// Size: 0x10, DWARF: 0x18E498
typedef union GifTagUl
{
    // Size: 0x10, DWARF: 0x18DDD7
    GifTag sce; // Offset: 0x0, DWARF: 0x18E4B4
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0x18E4D6
} GifTagUl;

// Size: 0x8, DWARF: 0x191649
typedef struct Alpha
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0x191665, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0x19168D, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0x1916B5, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0x1916DD, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0x191705, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0x191730, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0x19175A, Bit Offset: 40, Bit Size: 24
} Alpha;

// Size: 0x8, DWARF: 0x190121
typedef union AlphaUl
{
    // Size: 0x8, DWARF: 0x191649
    Alpha sce; // Offset: 0x0, DWARF: 0x19013D
    unsigned long ul; // Offset: 0x0, DWARF: 0x19015F
} AlphaUl;

// Size: 0x20, DWARF: 0x18D81A
typedef struct AlphaTag
{
    // Size: 0x10, DWARF: 0x18E498
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x18D835
    // Size: 0x8, DWARF: 0x190121
    AlphaUl alpha; // Offset: 0x10, DWARF: 0x18D85A
    signed long reg_addr; // Offset: 0x18, DWARF: 0x18D87E
} AlphaTag;

// Size: 0x8, DWARF: 0x18FF33
typedef struct Prim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0x18FF4F, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0x18FF7A, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0x18FFA4, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0x18FFCE, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0x18FFF8, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0x190022, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0x19004C, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0x190076, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0x1900A1, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0x1900CB, Bit Offset: 11, Bit Size: 53
} Prim;

// Size: 0x8, DWARF: 0x18EF13
typedef union PrimUl
{
    // Size: 0x8, DWARF: 0x18FF33
    Prim sce; // Offset: 0x0, DWARF: 0x18EF2F
    unsigned long ul; // Offset: 0x0, DWARF: 0x18EF51
} PrimUl;

// Size: 0x8, DWARF: 0x18EA0F
typedef struct Tex0
{
    unsigned long TBP0 : 14; // Offset: 0x0, DWARF: 0x18EA2B, Bit Offset: 0, Bit Size: 14
    unsigned long TBW : 6; // Offset: 0x0, DWARF: 0x18EA56, Bit Offset: 14, Bit Size: 6
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x18EA80, Bit Offset: 20, Bit Size: 6
    unsigned long TW : 4; // Offset: 0x0, DWARF: 0x18EAAA, Bit Offset: 26, Bit Size: 4
    unsigned long TH : 4; // Offset: 0x0, DWARF: 0x18EAD3, Bit Offset: 30, Bit Size: 4
    unsigned long TCC : 1; // Offset: 0x0, DWARF: 0x18EAFC, Bit Offset: 34, Bit Size: 1
    unsigned long TFX : 2; // Offset: 0x0, DWARF: 0x18EB26, Bit Offset: 35, Bit Size: 2
    unsigned long CBP : 14; // Offset: 0x0, DWARF: 0x18EB50, Bit Offset: 37, Bit Size: 14
    unsigned long CPSM : 4; // Offset: 0x0, DWARF: 0x18EB7A, Bit Offset: 51, Bit Size: 4
    unsigned long CSM : 1; // Offset: 0x0, DWARF: 0x18EBA5, Bit Offset: 55, Bit Size: 1
    unsigned long CSA : 5; // Offset: 0x0, DWARF: 0x18EBCF, Bit Offset: 56, Bit Size: 5
    unsigned long CLD : 3; // Offset: 0x0, DWARF: 0x18EBF9, Bit Offset: 61, Bit Size: 3
} Tex0;

// Size: 0x8, DWARF: 0x18FA5D
typedef union Tex0Ul
{
    // Size: 0x8, DWARF: 0x18EA0F
    Tex0 sce; // Offset: 0x0, DWARF: 0x18FA79
    unsigned long ul; // Offset: 0x0, DWARF: 0x18FA9B
} Tex0Ul;

// Size: 0x8, DWARF: 0x191A66
typedef struct Rgbaq0
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x191A82, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x191AAA, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x191AD2, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0x191AFA, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0x191B22
} Rgbaq0;

// Size: 0x8, DWARF: 0x18F08E
typedef union Rgbaq0Ul
{
    // Size: 0x8, DWARF: 0x191A66
    Rgbaq0 sce; // Offset: 0x0, DWARF: 0x18F0AA
    unsigned long ul; // Offset: 0x0, DWARF: 0x18F0CC
} Rgbaq0Ul;

// Size: 0x8, DWARF: 0x192CDD
typedef struct Scest
{
    float S; // Offset: 0x0, DWARF: 0x192CF9
    float T; // Offset: 0x4, DWARF: 0x192D17
} Scest;

// Size: 0x8, DWARF: 0x18D934
typedef struct Sceuv
{
    unsigned long U : 14; // Offset: 0x0, DWARF: 0x18D94F, Bit Offset: 0, Bit Size: 14
    unsigned long pad14 : 2; // Offset: 0x0, DWARF: 0x18D977, Bit Offset: 14, Bit Size: 2
    unsigned long V : 14; // Offset: 0x0, DWARF: 0x18D9A3, Bit Offset: 16, Bit Size: 14
    unsigned long pad30 : 34; // Offset: 0x0, DWARF: 0x18D9CB, Bit Offset: 30, Bit Size: 34
} Sceuv;

// Size: 0x8, DWARF: 0x18F89A
typedef union Stuv0
{
    // Size: 0x8, DWARF: 0x192CDD
    Scest scest; // Offset: 0x0, DWARF: 0x18F8B6
    // Size: 0x8, DWARF: 0x18D934
    Sceuv sceuv; // Offset: 0x0, DWARF: 0x18F8DA
    unsigned long ul; // Offset: 0x0, DWARF: 0x18F8FE
} Stuv0;

// Size: 0x8, DWARF: 0x18F7B4
typedef struct Xyzf0
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x18F7D0, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x18F7F8, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 24; // Offset: 0x0, DWARF: 0x18F820, Bit Offset: 32, Bit Size: 24
    unsigned long F : 8; // Offset: 0x0, DWARF: 0x18F848, Bit Offset: 56, Bit Size: 8
} Xyzf0;

// Size: 0x8, DWARF: 0x18F3F7
typedef union Xyzf0Ul
{
    // Size: 0x8, DWARF: 0x18F7B4
    Xyzf0 sce; // Offset: 0x0, DWARF: 0x18F413
    unsigned long ul; // Offset: 0x0, DWARF: 0x18F435
} Xyzf0Ul;

// Size: 0x70, DWARF: 0x18E284
typedef struct Poly
{
    // Size: 0x10, DWARF: 0x18E498
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x18E2A0
    // Size: 0x8, DWARF: 0x18EF13
    PrimUl prim; // Offset: 0x10, DWARF: 0x18E2C5
    // Size: 0x8, DWARF: 0x18FA5D
    Tex0Ul tex0; // Offset: 0x18, DWARF: 0x18E2E8
    // Size: 0x8, DWARF: 0x18F08E
    Rgbaq0Ul rgbaq0; // Offset: 0x20, DWARF: 0x18E30B
    // Size: 0x8, DWARF: 0x18F89A
    Stuv0 stuv0; // Offset: 0x28, DWARF: 0x18E330
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf0; // Offset: 0x30, DWARF: 0x18E354
    // Size: 0x8, DWARF: 0x18F89A
    Stuv0 stuv1; // Offset: 0x38, DWARF: 0x18E378
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf1; // Offset: 0x40, DWARF: 0x18E39C
    // Size: 0x8, DWARF: 0x18F89A
    Stuv0 stuv2; // Offset: 0x48, DWARF: 0x18E3C0
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf2; // Offset: 0x50, DWARF: 0x18E3E4
    // Size: 0x8, DWARF: 0x18F89A
    Stuv0 stuv3; // Offset: 0x58, DWARF: 0x18E408
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf3; // Offset: 0x60, DWARF: 0x18E42C
    unsigned long nop; // Offset: 0x68, DWARF: 0x18E450
} Poly;

// Size: 0x10, DWARF: 0x1917D4
typedef struct FData
{
    float dx; // Offset: 0x0, DWARF: 0x1917F0
    float dy; // Offset: 0x4, DWARF: 0x19180F
    signed int size; // Offset: 0x8, DWARF: 0x19182E
    signed int value; // Offset: 0xC, DWARF: 0x19184F
} FData;

// Size: 0x40, DWARF: 0x18D471
typedef struct Poly2
{
    // Size: 0x10, DWARF: 0x18E498
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x18D48C
    // Size: 0x8, DWARF: 0x18EF13
    PrimUl prim; // Offset: 0x10, DWARF: 0x18D4B1
    // Size: 0x8, DWARF: 0x18F08E
    Rgbaq0Ul rgbaq0; // Offset: 0x18, DWARF: 0x18D4D4
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf0; // Offset: 0x20, DWARF: 0x18D4F9
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf1; // Offset: 0x28, DWARF: 0x18D51D
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf2; // Offset: 0x30, DWARF: 0x18D541
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf3; // Offset: 0x38, DWARF: 0x18D565
} Poly2;

// Size: 0xC, DWARF: 0x19277B
typedef struct Fog
{
    signed int enable; // Offset: 0x0, DWARF: 0x192797
    float a; // Offset: 0x4, DWARF: 0x1927BA
    float b; // Offset: 0x8, DWARF: 0x1927D8
} Fog;

// Size: 0x8, DWARF: 0x192990
typedef struct EnvMap
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x1929AC
} EnvMap;

// Size: 0x8, DWARF: 0x192A6A
typedef struct Toon
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x192A86
} Toon;

// Size: 0x120, DWARF: 0x192540
typedef struct MdlEnv
{
    sceVu0FMATRIX world_view; // Offset: 0x0, DWARF: 0x19255C
    sceVu0FMATRIX view_screen; // Offset: 0x40, DWARF: 0x192585
    sceVu0FMATRIX normal_light; // Offset: 0x80, DWARF: 0x1925AF
    sceVu0FMATRIX light_color; // Offset: 0xC0, DWARF: 0x1925DA
    // Size: 0xC, DWARF: 0x19277B
    Fog fog; // Offset: 0x100, DWARF: 0x192604
    union
    {
        // Size: 0x8, DWARF: 0x192990
        EnvMap envmap; // Offset: 0x110, DWARF: 0x192626
        // Size: 0x8, DWARF: 0x192A6A
        Toon toon; // Offset: 0x110, DWARF: 0x19264B
    } toonlink;
} MdlEnv;

// Size: 0x60, DWARF: 0x18D9FB
typedef struct PolyG
{
    // Size: 0x10, DWARF: 0x18E498
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x18DA16
    // Size: 0x8, DWARF: 0x18EF13
    PrimUl prim; // Offset: 0x10, DWARF: 0x18DA3B
    // Size: 0x8, DWARF: 0x18F08E
    Rgbaq0Ul rgbaq0; // Offset: 0x18, DWARF: 0x18DA5E
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf0; // Offset: 0x20, DWARF: 0x18DA83
    // Size: 0x8, DWARF: 0x18F08E
    Rgbaq0Ul rgbaq1; // Offset: 0x28, DWARF: 0x18DAA7
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf1; // Offset: 0x30, DWARF: 0x18DACC
    // Size: 0x8, DWARF: 0x18F08E
    Rgbaq0Ul rgbaq2; // Offset: 0x38, DWARF: 0x18DAF0
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf2; // Offset: 0x40, DWARF: 0x18DB15
    // Size: 0x8, DWARF: 0x18F08E
    Rgbaq0Ul rgbaq3; // Offset: 0x48, DWARF: 0x18DB39
    // Size: 0x8, DWARF: 0x18F3F7
    Xyzf0Ul xyzf3; // Offset: 0x50, DWARF: 0x18DB5E
    unsigned long nop; // Offset: 0x58, DWARF: 0x18DB82
} PolyG;

//// Variables ///////////////////////////////////////////////////////////////////////

static // Size: 0x60, DWARF: 0x191BB2
VaytblEnding vaytblEnding[3]; // Address: 0x2D0530
// Size: 0x1F0, DWARF: 0x19074D
VayResData* vayResData; // Address: 0x2E7F1C
// Size: 0xEF8, DWARF: 0x192305
VspenvSecret* vspenvSecret; // Address: 0x2E7B04
// Size: 0x2DCEC, DWARF: 0x18F13B
VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
// Size: 0x10, DWARF: 0x1913CC
Brd_Param vsptblBoardParam[12][7]; // Address: 0x2B72B0
// Size: 0x5D0E0, DWARF: 0x19021C
VspenvEnv vspenvEnv; // Address: 0x3474D0
// Size: 0x114, DWARF: 0x190599
VspenvOption* vspenvOption; // Address: 0x2E7B10
// Size: 0x60, DWARF: 0x1902C9
VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30
// Size: 0xA0, DWARF: 0x190F54
VspenvGame* vspenvGame; // Address: 0x2E7B14
char* vsptblLevelGoalStr[8][3]; // Address: 0x3A45E0
char* vsptblCourseName[24]; // Address: 0x2B5A00
signed int vsptblLevelGoalValue[8][7]; // Address: 0x2B6A60
char* vsptblCharacterName[12]; // Address: 0x2B5880
// Size: 0x20, DWARF: 0x18D3EA
VspenvRecord* vspenvRecord[8][6]; // Address: 0x347410
signed int vayParamMax[12][6]; // Address: 0x2C7C10
char* vsptblBoardName[12][7]; // Address: 0x2B58B0
// Size: 0x60, DWARF: 0x191BB2
VaytblEnding vaytblCredit[652]; // Address: 0x2B8790

//// Function Declarations ///////////////////////////////////////////////////////////

void ayResultInit();
signed int ayResultFrame(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
void ayResultEnd();
void ayResultClear();
static signed int ayCheckLoad();
static void aySelHeadDraw(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayDrawMenu(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayDrawGoals(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void aySetKeyOparate(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayDrawCsLogo(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayDrawScore(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayDrawStats(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayAddStats();
static void ayDrawConfirm(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayDrawSave(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static signed int ayDrawChange(// Size: 0x10, DWARF: 0x18D330
Packet* packet);
static void ayDrawChWear(// Size: 0x10, DWARF: 0x18D330
Packet* packet, float dx, float dy, signed int flg, signed int no);
static void ayDrawChBoard(// Size: 0x10, DWARF: 0x18D330
Packet* packet, float dx, float dy, signed int flg, signed int no);
static void ayDrawChCs(// Size: 0x10, DWARF: 0x18D330
Packet* packet, float dx, float dy, signed int flg);
static void ayDrawChPlayer(// Size: 0x10, DWARF: 0x18D330
Packet* packet, float dx, float dy, signed int flg, signed int no);
static void ayDrawChHandi(// Size: 0x10, DWARF: 0x18D330
Packet* packet, float dx, float dy, signed int flg, signed int no);
static void ayDrawChRule(// Size: 0x10, DWARF: 0x18D330
Packet* packet, float dx, float dy, signed int flg, signed int kind);
static void ayDrawBackBoard(// Size: 0x10, DWARF: 0x18D330
Packet* packet, float dx, float dy, signed int flg);
static signed int ayChangeCharID(signed int no);
static signed int ayDrawEnding(// Size: 0x10, DWARF: 0x18D330
Packet* packet);

//// Function Definitions ////////////////////////////////////////////////////////////

void* memcpy(void* dest, const void* src, signed int size);
void ayCalcHandiParam();
signed int ayCalcNextID(signed int now, signed int limit, signed int dir);
float ayCalcTotalMove(signed int frame, signed int count, float totalmove, signed int type);
void ayDrawBG(Packet* packet, TexData* texData, signed int col, signed int mark);
signed int ayDrawCredits(Packet* packet, VaytblEnding* namelst, float* dy, signed int num);
void ayDrawKeyOparate(signed int kind, signed int count, signed int flg, TexData* texData, Packet* packet);
float ayDrawNum(Packet* packet, FData* data, signed int flg);
void ayFontInit(signed int x, signed int y, signed int* fcol);
void ayFontInitmin();
signed int ayMcCareerSave(Packet* packet);
signed int ayMcGetStep();
signed int ayMcReplaySave(Packet* packet);
void ayMcSetSaveFileID();
void ayMcSysEnd();
void ayMcSysInit();
void aySetPolyComF4(Poly2* poly, QuadData* data);
void aySetPolyComFT4(Poly* poly, QuadData* data, signed int flg);
void aySetPolyComG4(PolyG* poly, QuadData* data);
void aySetRepData(signed int pnum);
void aySetVert(signed int* vert, float* xy, signed int z);
signed int nmbgmChange2(signed int fade, signed int num, signed int tbl);
void nmbgmSetOptNext(signed int next);
void nmbgmSetOptRand(signed int rand);
signed int nmbgmStop(signed int fade);
void nmdispTransTex(Packet* packet);
void nmfontFPrint(Packet* packet, char* str, signed int x, signed int y);
void nmfontFPrintF(Packet* packet, char* str, float* pos);
void nmfontGPrint(Packet* packet, char* str, signed int x, signed int y);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);
void nmfontInitOption();
void nmfontSetBil(signed int flag);
void nmfontSetCol(signed int* col);
void nmfontSetPack(signed int flag);
void nmfontSetSize(signed int width, signed int height);
signed int nmsndExit(signed int fade);
signed int nmvcPlay(signed int res, signed int group, signed int num);
signed int nmvcPlayButton(signed int num);
signed int nmvcPlayCursor(signed int num);
void spSetFade(signed int per, signed int col);
Data* sploadGetGame2D();
void sploadSetCharacterTexture(signed int no);
void ul3dScaleMatrixXYZ(float* mat, float sx, float sy, float sz);
void ulFree(void* p);
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void* ulgifAddCNTReserve(Packet* pkt, signed int qwc);
void ulpadSetAnaRef(signed int flag);
void ulpadSetRepFrame(signed int frame);
void ulpktInitALPHA(AlphaTag* pkt, signed int ctext);
signed int ulstdSprintf(char* buf, char* fmt, ...);
void ultexResetTex(signed int offset);
void ultexTransTexTag(Packet* packet, unsigned int* addr, TexData* data, signed int no);
void sceVu0UnitMatrix(sceVu0FMATRIX m);
void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR tv);
void aySetCamMatrix(float* worldScr, float* worldView, float* viewScr);
void aySetLightMatrix(float* nLight, float* lightCol, float acol, float lcol);
unsigned int ulmdlDrawModelPkt(unsigned int* pkt, void* abuf, MdlEnv* mdlenv, float* matrix, __int128* model, signed int drawmode);
void sceGifPkCnt(Packet* p, unsigned int a, unsigned int b, unsigned int c);
void sceGifPkReserve(Packet* p, unsigned int size);
void sceGifPkTerminate(Packet* p);

void ayResultInit(void) {
    vayResData = (void*)ulMalloc(0x1F0, 0, 0);
    ayResultClear();
    vayResData->ret = 0;
    ayMcSysInit();
    ulpadSetRepFrame(0xA);
}

signed int ayResultFrame(Packet* packet) {
    signed int flg; // r16 // s0
    signed int ii; // r17 // s1
    signed int pno; // r18 // s2
    signed int board; // r19 // s3
    signed int next; // r20 // s4
    signed int button; // r21 // s5
    unsigned int pad; // r22 // s6
    signed int pnum; // r23 // s7
    signed int ret; // r30 // s8
    TexData texData; // 0xA0(r29)
    signed int tmp; // 0xB4(r29)
    signed int frnum; // 0xB8(r29)
    Data* data; // 0xBC(r29)
    ret = 0;
    next = 0;
    pnum = 1;
    pad = vgmsysPad[0]->trg;
    if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
        pad |= vgmsysPad[1]->trg;
        pnum = 2;
    }
    for (ii = 0; ii < 2; ii++) {
        if (vayResData->decide[ii] == -1) {
            vayResData->decide[ii] = 0;
        }
    }
    data = sploadGetGame2D();
    ultexResetTex(data->result.offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(packet, data->result.utd, &texData, 0);
    ayDrawBG(packet, &texData, 0x80, 0);
    switch (vayResData->step) {
    case 33:
        tmp = ayDrawEnding(packet);
        if (vayResData->count < 0x21) {
            if (vayResData->count == 0) {
                nmbgmSetOptNext(0);
                nmbgmSetOptRand(0);
                nmbgmChange2(0, 0xD, 0);
            }
            spSetFade(0x80 - (vayResData->count * 4), 0xFF);
        } else {
            if (tmp == -1) {
                nmbgmStop(0x10);
                next = 1;
                vayResData->step = 0x22;
            }
            if ((vgmsysPad[0]->trg & 0x40) || (vgmsysPad[0]->trg & 0x10) || (vgmsysPad[0]->trg & 0x800)) {
                nmvcPlayButton(2);
                nmbgmStop(0x10);
                next = 1;
                vayResData->step = 0x22;
            }
        }
        break;
    case 34:
        ayDrawEnding(packet);
        spSetFade(vayResData->count * 4, 0xFF);
        if (vayResData->count == 0x20) {
            next = 1;
            vayResData->step = (u32) vayResData->nextStep;
        }
        break;
    case 0:
        ayDrawMenu(packet);
        if (vayResData->count == 0) {
            nmbgmSetOptNext(0);
            nmbgmSetOptRand(0);
            nmbgmChange2(0, 0xC, 0);
        }
        if (vayResData->resKind == 0) {
            frnum = 0x20;
        } else {
            frnum = 0x10;
        }
        if (vayResData->count == (frnum + 0x20)) {
            next = 1;
            vayResData->step = 1;
            ulpadSetAnaRef(1);
        }
        if (vayResData->count < 0x21) {
            spSetFade(0x80 - (vayResData->count * 4), 0xFF);
        }
        break;
    case 1:
        ayDrawMenu(packet);
        if ((vayResData->decideflg == -1) && (vayResData->movecnt == -1)) {
            if (pad & 0x40) {
                next = 1;
                switch (vayResData->menu) {
                case 0:             
                    button = 0;
                    vayResData->step = 2;
                    vayResData->ret = 1;
                    break;
                case 1:             
                    button = 0;
                    vayResData->step = 6;
                    vayResData->select[1] = 0;
                    vayResData->select[0] = 0;
                    vayResData->decide[1] = 0;
                    vayResData->decide[0] = 0;
                    break;
                case 2:             
                    switch (vayResData->resKind) {
                    case 1:
                    case 0:
                        button = 0;
                        vayResData->step = 2;
                        vayResData->ret = 3;
                        break;
                    case 2:
                        button = 0;
                        vayResData->step = 0xC;
                        break;
                    case 3:
                        button = 0;
                        vayResData->decideflg = 0;
                        vayResData->decidecnt = 0;
                        vayResData->conf = 1;
                        break;
                    }
                    break;
                case 3:             
                    if (vayResData->resKind != 0) {
                        button = 0;
                        vayResData->decideflg = 0;
                        vayResData->decidecnt = 0;
                        vayResData->conf = 1;
                    } else {
                        vayResData->step = 3;
                        button = 0;
                    }
                    break;
                case 4:             
                    button = 0;
                    vayResData->step = 0xC;
                    break;
                case 5:             
                    button = 0;
                    vayResData->step = 9;
                    break;
                case 6:             
                    button = 0;
                    vayResData->step = 0xF;
                    break;
                case 7:             
                    button = 0;
                    vayResData->decideflg = 0;
                    vayResData->decidecnt = 0;
                    vayResData->conf = 1;
                    break;
                }
                nmvcPlayButton(button);
            }
        } else if ((vayResData->decideflg == 1) && (vayResData->decidecnt == -1)) {
            if (pad & 0x40) {
                nmvcPlayButton(0);
                if (vayResData->conf == 0) {
                    vayResData->step = 2;
                    vayResData->ret = 4;
                    vayResData->movecnt = -1;
                    vayResData->count = 0;
                    nmsndExit(0x10);
                }
                vayResData->decidecnt = 0;
                vayResData->decideflg = 2;
            } else if (pad & 0x10) {
                nmvcPlayButton(2);
                vayResData->decidecnt = 0;
                vayResData->decideflg = 2;
            }
        }
        break;
    case 2:
        ayDrawMenu(packet);
        if (vayResData->count == 0) {
            if (vayResData->ret == 1) {
                vayResData->count = vayResData->resKind;
                if (vayResData->ret == 3) {
                    nmbgmStop(0x10);
                }
            } else {
                nmsndExit(0x10);
            }
            nmbgmSetOptRand(vspenvOption->bgm.random);
        }
        if ((vayResData->ret == 1) || (vayResData->ret == 3)) {
            spSetFade(vayResData->count * 4, 0xFF);
        } else {
            spSetFade(vayResData->count * 4, 0);
        }
        if (vayResData->count == 0x20) {
            ulpadSetAnaRef(0);
            ret = vayResData->ret;
        }
        break;
    case 3:
        ayDrawMenu(packet);
        ayDrawGoals(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 4;
        }
        break;
    case 4:
        ayDrawGoals(packet);
        if (pad & 0x10) {
            nmvcPlayButton(2);
            next = 1;
            vayResData->step = 5;
        }
        break;
    case 5:
        ayDrawMenu(packet);
        ayDrawGoals(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 1;
        }
        break;
    case 6:
        ayDrawChange(packet);
        ayDrawMenu(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
                vayResData->step = 0x13;
            } else {
                vayResData->step = 7;
            }
        }
        break;
    case 7:
    case 19:
        next = ayDrawChange(packet);
        break;
    case 18:
        ayDrawChange(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 7;
            vayResData->select[1] = 0;
            vayResData->select[0] = 0;
            vayResData->decide[1] = 0;
            vayResData->decide[0] = 0;
        }
        break;
    case 8:
        ayDrawChange(packet);
        ayDrawMenu(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 1;
        }
        break;
    case 31:
        ayDrawChange(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 0x13;
            vayResData->select[1] = 0;
            vayResData->select[0] = 0;
            vayResData->decide[1] = 0;
            vayResData->decide[0] = 0;
        }
        break;
    case 30:
        ayDrawChange(packet);
        if (vayResData->count == 0) {
            if ((vayResData->ret == 1) || (vayResData->ret == 3)) {
                nmbgmStop(0x10);
            } else {
                nmsndExit(0x10);
            }
            nmbgmSetOptRand(vspenvOption->bgm.random);
        }
        if (vayResData->ret == 1) {
            spSetFade(vayResData->count * 4, 0xFF);
        } else {
            spSetFade(vayResData->count * 4, 0);
        }
        if (vayResData->count == 0x20) {
            if ((vayResData->ret == 1) && ((sploadSetCharacterTexture(0), (vayResData->resKind == 1)) || (vayResData->resKind == 3))) {
                sploadSetCharacterTexture(1);
            }
            ret = vayResData->ret;
            ulpadSetAnaRef(0);
        }
        break;
    case 9:
    case 12:
        ayDrawMenu(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            if (vayResData->step == 9) {
                vayResData->step = 0xA;
            } else {
                ayMcSetSaveFileID();
                vayResData->step = 0xD;
            }
        }
        break;
    case 10:
        if (ayMcReplaySave(packet) == 1) {
            next = 1;
            vayResData->step = 0xB;
        }
        break;
    case 13:
        if (ayMcCareerSave(packet) > 0) {
            next = 1;
            vayResData->step = 0xE;
        }
        break;
    case 11:
    case 14:
        ayDrawMenu(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 1;
        }
        break;
    case 15:
        ayDrawMenu(packet);
        ayDrawScore(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 0x10;
        }
        break;
    case 16:
        ayDrawScore(packet);
        if (pad & 0x10) {
            nmvcPlayButton(2);
            next = 1;
            vayResData->step = 0x11;
        }
        break;
    case 17:
        ayDrawMenu(packet);
        ayDrawScore(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 1;
        }
        break;
    case 20:
        if (vayResData->count == 0) {
            nmbgmSetOptNext(0);
            nmbgmSetOptRand(0);
            nmbgmChange2(0, 0xC, 0);
        }
        ayDrawStats(packet);
        if (vayResData->count == 0x48) {
            next = 1;
            vayResData->step = 0x15;
            ulpadSetAnaRef(1);
        }
        if (vayResData->count < 0x21) {
            spSetFade(0x80 - vayResData->count * 4, 0xFF);
        }
        break;
    case 21:
        ayDrawStats(packet);
        if (vayResData->decideflg == 1) {
            if (vayResData->decidecnt == -1) {
                if (pad & 0x40) {
                    nmvcPlayButton(0);
                    if (vayResData->conf == 0) {
                        vayResData->step = 0x16;
                        vayResData->movecnt = -1;
                        vayResData->count = 0;
                        ayAddStats();
                    }
                    vayResData->decidecnt = 0;
                    vayResData->decideflg = 2;
                } else if (pad & 0x10) {
                    nmvcPlayButton(2);
                    vayResData->decidecnt = 0;
                    vayResData->decideflg = 2;
                }
            }
        }
        break;
    case 27:
        ayDrawSave(packet);
        /* fallthrough */
    case 25:
        ayDrawMenu(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 1;
        }
        break;
    case 23:
        ayDrawSave(packet);
        if (vayResData->count == 0) {
            nmbgmSetOptNext(0);
            nmbgmSetOptRand(0);
            nmbgmChange2(0, 0xC, 0);
        }
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 0x18;
            ulpadSetAnaRef(1);
            ayMcSetSaveFileID();
        }
        if (vayResData->count < 0x21) {
            spSetFade(0x80 - (vayResData->count * 4), 0xFF);
        }
        break;
    case 22:
        ayDrawSave(packet);
        ayDrawStats(packet);
        if (vayResData->count == 0x30) {
            next = 1;
            vayResData->step = 0x18;
        }
        break;
    case 24:
        ayDrawSave(packet);
        if ((pad & 0x40) && (vayResData->movecnt == -1)) {
            nmvcPlayButton(0);
            if (vayResData->save == 0) {
                vayResData->step = 0x1D;
            } else {
                vayResData->step = 0x1B;
            }
            next = 1;
        }
        break;
    case 29:
        ayDrawSave(packet);
        if (vayResData->count == 0x26) {
            next = 1;
            vayResData->step = 0x1C;
        }
        break;
    case 28:
        tmp = ayMcCareerSave(packet);
        if (tmp == 1) {
            next = 1;
            vayResData->step = 0x19;
        } else if (tmp == 2) {
            next = 1;
            vayResData->step = 0x1A;
        }
        break;
    case 26:
        ayDrawSave(packet);
        if (vayResData->count == 0x2C) {
            next = 1;
            vayResData->step = 0x18;
        }
        break;
    }
    if (vayResData->decideflg != -1) {
        ayDrawConfirm(packet);
    }
    if (next == 0) {
        vayResData->count++;
    } else {
        vayResData->count = 0;
    }
    vayResData->bgcnt++;
    if ((s32) vayResData->step < 0x21) {
        aySelHeadDraw(packet);
        aySetKeyOparate(packet);
    }
    if ((ret == 1) || (ret == 2) || (ret == 5)) {
        for (ii = 0; ii < pnum; ii++) {
            pno = ayChangeCharID(vayResData->chara[ii]);
            if (pno < 0xC) {
                flg = vspenvSecret->character[pno].board;
            } else {
                flg = vspenvSecret->create_character[pno - 0xC].character.board;
            }
            for (board = 0; flg >= 2; board++) {
                flg = flg / 2;
            }
            if (pno < 0xC) {
                memcpy(&vspenvEnv.game.character[ii].chr_param, &vspenvSecret->character[pno].parameter, 0x1C);
                memcpy(&vspenvEnv.game.character[ii].brd_param, &vsptblBoardParam[pno][board], 0x10);
                memcpy(&vspenvReplay[ii]->character, &vspenvSecret->character[pno], 0x74);
            } else {
                memcpy(&vspenvEnv.game.character[ii].chr_param, &vspenvSecret->create_character[pno - 0xC].character.parameter, 0x1C);
                memcpy(&vspenvEnv.game.character[ii].brd_param, &vsptblBoardParam[vspenvSecret->create_character[pno - 0xC].board_type][board], 0x10);
                memcpy(&vspenvReplay[ii]->character, &vspenvSecret->create_character[pno - 0xC], 0xEC);
            }
        }
        if (pnum == 2) {
            ayCalcHandiParam();
        }
        aySetRepData(pnum);
    }
    return ret;
}

void ayResultEnd(void) {
    ulFree(vayResData);
    ayMcSysEnd();
}

void ayResultClear() {
    signed int jj; // r16 // s0
    signed int ii; // r17 // s1
    signed int pno; // r18 // s2
    signed int tmp; // r19 // s3
    signed int cnum; // r20 // s4
    signed int pnum; // r22 // s6
    signed int point; // r23 // s7

    for (ii = 0, cnum = 0; ii < 10; ii++) {
        if (vspenvSecret->create_character[ii].character.secret == 1) {
            cnum++;
        }
    }
    switch (vspenvGame->mode.game_mode) {
    case 0:
        vayResData->resKind = 0;
        pno = vspenvGame->character[0].no;
        if (pno < 0xC) {
            point = vspenvSecret->character[pno].rem_point;
        } else {
            point = vspenvSecret->create_character[pno - 0xC].character.rem_point;
        }
        if (vspenvGame->ending != 0) {
            vayResData->step = 0x21;
            if (point > 0) {
                vayResData->nextStep = 0x14;
            } else {
                vayResData->nextStep = 0x17;
            }
            vspenvGame->ending = 0;
        } else {
            if (point > 0) {
                vayResData->step = 0x14;
            } else {
                vayResData->step = 0x17;
            }
        }
        vayResData->cs = vspenvGame->course.no;
        pnum = 1;
        break;
    case 1:
        if (vspenvGame->mode.match_rule == 3) {
            vayResData->resKind = 3;
        } else {
            vayResData->resKind = 1;
        }
        vayResData->step = 0;
        vayResData->cs = vspenvGame->course.no;
        pnum = 2;
        break;
    case 2:
        vayResData->resKind = 2;
        vayResData->step = 0x17;
        vayResData->cs = vspenvGame->course.no;
        pnum = 1;
        break;
    }
    if (vayResData->ret == 3) {
        vayResData->step = 0;
    } else {
        vayResData->menu = 0;
    }
    vayResData->count = 0;
    vayResData->bgcnt = 0;
    vayResData->scrY = 0.0f;
    vayResData->next = 0;
    vayResData->save = 0;
    vayResData->movecnt = -1;
    vayResData->stat = 0;
    vayResData->decideflg = -1;
    vayResData->decidecnt = 0;
    vayResData->conf = 0;
    for (ii = 0; ii < 5; ii++) {
        vayResData->rem[ii] = 0;
    }
    vayResData->rotcnt[1] = 0;
    vayResData->rotcnt[0] = 0;
    for (ii = 0; ii < pnum; ii++) {
        pno = vspenvGame->character[ii].no;
        if (pno < 0xA) {
            vayResData->chara[ii] = pno;
        } else if (pno < 0xC) {
            vayResData->chara[ii] = pno + cnum;
        } else {
            pno -= 0xC;
            for (jj = 0, tmp = 0; jj < pno; jj++) {
                if (vspenvSecret->create_character[jj].character.secret == 1) {
                    tmp++;
                }
            }
            vayResData->chara[ii] = tmp + 0xA;
        }
        vayResData->envChara[ii] = vayResData->chara[ii];
        for (jj = 0; jj < 0x16; jj++) {
            vayResData->wear[ii][jj] = 0;
            vayResData->board[ii][jj] = 0;
        }
        vayResData->wear[ii][vayResData->chara[ii]] = vspenvGame->character[ii].wear;
        vayResData->board[ii][vayResData->chara[ii]] = vspenvGame->character[ii].board;
        vayResData->handi[ii] = vspenvGame->mode.handicap[ii];
    }
    vayResData->envCs = vayResData->cs;
    if (pnum == 2) {
        vayResData->rule = vspenvGame->mode.match_rule;
    }
}

static s32 ayCheckLoad(void) {
    signed int ii; // r16 // s0
    signed int pno; // r17 // s1
    signed int ret; // r18 // s2
    signed int pnum; // r19 // s3

    ret = 1;
    if (vspenvGame->mode.game_mode == 1) {
        pnum = 2;
        vspenvGame->mode.match_rule = (s32) vayResData->rule;
        if (vayResData->rule < 2) {
            vspenvGame->mode.divide = (s32) vspenvOption->divide;
        } else {
            vspenvGame->mode.divide = 0;
        }
    } else {
        pnum = 1;
    }
    for (ii = 0; ii < pnum; ii++) {
        pno = ayChangeCharID(vayResData->chara[ii]);
        if (vayResData->chara[ii] != vayResData->envChara[ii]) {
            vspenvGame->character[ii].no = pno;
            if (vspenvGame->mode.game_mode != 1) {
                vspenvSecret->old_char = (s32) vayResData->chara[0];
            }
            ret = 2;
            if (pno >= 0xC) {
                vspenvGame->character[ii].wear = 0;
            }
        }
        if ((vayResData->wear[ii][vayResData->chara[ii]] != vspenvGame->character[ii].wear) && (pno < 0xC)) {
            vspenvGame->character[ii].wear = vayResData->wear[ii][vayResData->chara[ii]];
            if (vspenvGame->mode.game_mode != 1) {
                vspenvSecret->character[vayResData->chara[ii]].old_wear_no = vayResData->wear[ii][vayResData->chara[ii]];
            }
            ret = 2;
        }
        if (vayResData->board[ii][vayResData->chara[ii]] != vspenvGame->character[ii].board) {
            vspenvGame->character[ii].board = (s32) vayResData->board[ii][vayResData->chara[ii]];
            if (pno < 0xC) {
                if (vspenvGame->mode.game_mode != 1) {
                    vspenvSecret->character[pno].old_brd_no = (s32) vayResData->board[ii][vayResData->chara[ii]];
                }
            } else if (vspenvGame->mode.game_mode != 1) {
                vspenvSecret->create_character[pno - 0xC].character.old_brd_no = (s32) vayResData->board[ii][vayResData->chara[ii]];
            }
        }
        if (vayResData->handi[ii] != vspenvGame->mode.handicap[ii]) {
            vspenvGame->mode.handicap[ii] = vayResData->handi[ii];
        }
    }
    if (vayResData->cs != vayResData->envCs) {
        switch (vayResData->resKind) {
        case 0:
            vspenvGame->course.no = (s32) vayResData->cs;
            vspenvGame->mode.game_mode = 0;
            ret = 5;
            break;
        default:
            vspenvGame->course.no = (s32) vayResData->cs;
            ret = 2;
            break;
        }
    }
    if ((vayResData->resKind == 0) && (ret == 2)) {
        ret = 5;
    }
    return ret;
}

static void aySelHeadDraw(// Size: 0x10, DWARF: 0x18D330
Packet* packet) {
    signed int unused1;
    signed int unused2;
    signed int unused3;
    signed int texno; // r16 // s0
    signed int moveType; // r17 // s1
    signed int count; // r18 // s2
    signed int col; // r19 // s3
    Data* loaddata; // r20 // s4
    void* addr; // r21 // s5
    Poly* poly; // r22 // s6
    AlphaTag* alpha; // r23 // s7
    QuadData data; // 0xA0(r29)
    sceVu0FVECTOR xy; // 0x180(r29)
    TexData texData; // 0x190(r29)
    float dx; // 0x1A4(r29)

    count = vayResData->count;
    moveType = 0;
    loaddata = sploadGetGame2D();
    ultexResetTex(loaddata->result.offset);
    texData.tofs = -1;
    texData.cofs = -1;
    switch (vayResData->step) {
    case 0:
        moveType = 1;
        texno = 4;
        break;
    case 25:
    case 27:
        moveType = 2;
        texno = -2;
        break;
    case 1:
        moveType = 0;
        texno = 4;
        break;
    case 2:
        moveType = 3;
        texno = 4;
        break;
    case 3:
        moveType = 2;
        texno = 1;
        break;
    case 4:
        moveType = 0;
        texno = 1;
        break;
    case 5:
        moveType = 2;
        texno = -1;
        break;
    case 15:
        moveType = 2;
        texno = 0;
        break;
    case 16:
        moveType = 0;
        texno = 0;
        break;
    case 17:
        moveType = 4;
        if (count < 0x10) {
            texno = 0;
        } else {
            texno = 4;
        }
        break;
    case 9:
        moveType = 2;
        texno = 3;
        break;
    case 10:
        moveType = 0;
        texno = 3;
        break;
    case 11:
        moveType = 2;
        texno = -3;
        break;
    case 12:
        moveType = 2;
        texno = 2;
        break;
    case 13:
    case 24:
    case 26:
    case 28:
    case 29:
        moveType = 0;
        texno = 2;
        break;
    case 14:
        moveType = 2;
        texno = -2;
        break;
    case 6:
        moveType = 2;
        texno = 5;
        break;
    case 7:
    case 18:
    case 19:
    case 31:
        moveType = 0;
        texno = 5;
        break;
    case 8:
        moveType = 2;
        texno = -5;
        break;
    case 30:
        moveType = 3;
        texno = 5;
        break;
    case 20:
        moveType = 1;
        texno = 7;
        break;
    case 21:
        moveType = 0;
        texno = 7;
        break;
    case 22:
        moveType = 2;
        texno = -7;
        break;
    case 23:
        moveType = 1;
        texno = 2;
        break;
    }
    if (moveType == 2) {
        if (texno < 0) {
            if (count < 0x10) {
                texno = -texno;
            } else if (vayResData->step == 0x16) {
                texno = 2;
            } else {
                texno = 4;
            }
        } else if (count < 0x10) {
            texno = 4;
        }
    }
    ultexTransTexTag(packet, loaddata->result.utd, &texData, texno / 4 + 0x25);
    data.uv[0] = 0, data.uv[1] = (texno % 4) << 6, data.uv[2] = 0x100, data.uv[3] = data.uv[1] + 0x40;
    switch (moveType) {
    case 0:
        dx = 354.0f;
        col = 0x80;
        break;
    case 1:
        if (count < 0x20) {
            col = (count << 7) / 32;
            dx = -286.0f + ayCalcTotalMove(0x21, count, 640.0f, 1);
        } else {
            dx = 354.0f;
            col = 0x80;
        }
        break;
    case 2:
    case 4:
        if (count < 0x10) {
            col = 0x80 - (count * 8);
            dx = 354.0f + ayCalcTotalMove(0x11, count, 640.0f, 3);
        } else if (count < 0x20) {
            col = (count - 0x10) * 8;
            dx = -286.0f + ayCalcTotalMove(0x11, count - 0x10, 640.0f, 1);
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
    addr = ulgifAddCNTReserve(packet, 9);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.texdata = &texData;
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
    xy[0] = dx, xy[1] = 8.0f, xy[2] = 256.0f + dx, xy[3] = 40.0f;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    data.psmt = 0x14;
    aySetPolyComFT4(poly, &data, 1);
}

static void ayDrawMenu(Packet* packet) {
    signed int unused1;
    signed int unused2;
    signed int ii; // r16 // s0
    signed int count = vayResData->count; // r17 // s1
    signed int size; // r18 // s2
    signed int frame; // r19 // s3
    signed int mx; // r20 // s4
    signed int no; // r21 // s5
    signed int disp; // r22 // s6
    char* menuList[3][8] = {
        {
            "RETRY"        /*@468*/,
            "CHANGE"       /*@469*/,
            "WATCH REPLAY" /*@470*/,
            "LEVEL GOALS"  /*@471*/,
            "SAVE CAREER"  /*@472*/,
            "SAVE REPLAY"  /*@473*/,
            "HIGH SCORES"  /*@474*/,
            "QUIT"         /*@475*/
        }, {
            "NEUER VERSUCH"          /*@476*/,
            "\x90""NDERN"            /*@477*/,
            "WIEDERHOLUNG ANSEHEN"   /*@478*/,
            "LEVELZIELE"             /*@479*/,
            "KARRIERE SPEICHERN"     /*@480*/,
            "WIEDERHOLUNG SPEICHERN" /*@481*/,
            "HIGHSCORES"             /*@482*/,
            "BEENDEN"                /*@483*/
        }, {
            "REESSAYER"               /*@484*/,
            "MODIFIER"                /*@485*/,
            "VOIR LA VIDEO"           /*@486*/,
            "OBJECTIFS DU NIVEAU"     /*@487*/,
            "SAUVEGARDER LA CARRIERE" /*@488*/,
            "SAUVEGARDER LA VIDEO"    /*@489*/,
            "MEILLEURS SCORES"        /*@490*/,
            "QUITTER"                 /*@491*/
        }
    }; // 0xA0(r29) @492
    char** menu = menuList[vspenvGame->language]; // r23 // s7
    char id[4][8] = {{8, 1, 2, 3, 4, 5, 6, 7}, {4, 1, 2, 7, 0, 0, 0, 0}, {4, 1, 4, 7, 0, 0, 0, 0}, {3, 1, 7, 0, 0, 0, 0, 0}}; // 0x100(r29) // @493
    signed int fcol[4]; // 0x120(r29)
    sceVu0FVECTOR fpos = {0.0f, 0.0f, 16777215.0f, 1.0f}; // 0x130(r29) // @494
    float dx; // 0x144(r29)
    float dy; // 0x148(r29)
    unsigned int pad = vgmsysPad[0]->rep; // 0x14C(r29)

    if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
        pad |= vgmsysPad[1]->rep;
    }
    dx = dy = 0.0f;
    switch (vayResData->step) {
    case 0:
        mx = 1;
        if (count == 0) {
            nmvcPlay(0x1A, 5, 2);
        }
        break;
    case 1:
        mx = 0;
        if (vayResData->movecnt == -1) {
            if (vayResData->decideflg == -1) {
                if (pad & 0x1000) {
                    nmvcPlayCursor(1);
                    vayResData->movecnt = 0;
                    if (vayResData->menu == 0) {
                        vayResData->menu = id[vayResData->resKind][0] - 1;
                    } else {
                        vayResData->menu--;
                    }
                }
                if (pad & 0x4000) {
                    nmvcPlayCursor(1);
                    vayResData->movecnt = 0;
                    if (vayResData->menu == id[vayResData->resKind][0] - 1) {
                        vayResData->menu = 0;
                    } else {
                        vayResData->menu++;
                    }
                }
            }
        } else {
            vayResData->movecnt++;
            if (vayResData->movecnt == 4) {
                vayResData->movecnt = -1;
            }
        }
        break;
    case 2:
        if (count == 0) {
            nmvcPlay(0x1B, 5, 3);
        }
        mx = 2;
        break;
    case 3:
    case 0xF:
    case 9:
    case 0xC:
    case 6:
        if (count == 0) {
            nmvcPlay(0x1B, 5, 3);
        }
        mx = 3;
        break;
    case 5:
    case 0x11:
    case 0xB:
    case 0xE:
    case 8:
    case 0x19:
    case 0x1B:
        if (count == 0x10) {
            nmvcPlay(0x1A, 5, 2);
        }
        mx = 4;
        break;
    }
    ayFontInitmin();
    for (ii = 0; ii < id[vayResData->resKind][0]; ii++) {
        if (ii == 0) {
            disp = 0;
        } else {
            disp = id[vayResData->resKind][ii];
        }
        switch (mx) {
        case 1:
            if (count < (ii + 1) * 4) {
                dx = -640.0f;
            } else if (count < (ii + 1) * 4 + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x21, count - (ii + 1) * 4, 640.0f, 1);
            }
            break;
        case 2:
        case 3:
            if (ii < vayResData->menu) {
                no = ii;
            } else {
                no = ii - 1;
            }
            if (mx == 2) {
                frame = 1;
            } else {
                frame = 2;
            }
            if (vayResData->menu == ii) {
                dx = 0.0f;
            } else {
                dy = 0.0f;
                if (count < (no + 1) * 4 / frame) {
                    dx = 0.0f;
                } else if (count < 0x20 / frame + (no + 1) * 4 / frame) {
                    dx = ayCalcTotalMove(0x20 / frame + 1, count - (no + 1) * 4 / frame, 640.0f, 3);
                } else {
                    dx = 640.0f;
                }
            }
            break;
        case 4:
            if (count < (ii + 1) * 4 / 2 + 0x10) {
                dx = -640.0f;
            } else if (count < (ii + 1) * 4 / 2 + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, count - 0x10 - (ii + 1) * 4 / 2, 640.0f, 1);
            } else {
                dx = 0.0f;
            }
            break;
        }
        if (ii == vayResData->menu) {
            fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            if (vayResData->movecnt == -1) {
                if ((mx == 2) || (mx == 3)) {
                    size = count / 2 + 0x1C;
                    dy = (float)count * ((float)frame * (100.0f + (float)(ii << 5) - (float)size / 2.0f - 48.0f) / 32.0f);
                    if (count < 0x20) {
                        fcol[3] = 0x80 - (count << 7) / 32;
                    } else {
                        fcol[3] = 0;
                    }
                } else {
                    size = 0x1C;
                }
            } else if (vayResData->movecnt < 2) {
                size = vayResData->movecnt * 2 + 0x1C;
            } else {
                size = 0x24 - vayResData->movecnt * 2;
            }
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }
        nmfontSetSize(size, size);
        fpos[0] = 320.0f + dx - (float)(nmfontGetPackStrLen(menu[disp], size, 0) / 2);
        fpos[1] = 100.0f + (float)(ii << 5) - (float)size / 2.0f - dy;
        nmfontSetCol(fcol);
        nmfontFPrintF(packet, menu[disp], fpos);
    }
}

static void ayDrawGoals(Packet* packet) {
    signed int count = vayResData->count; // r21 // s5
    signed int cs = vspenvGame->course.no; // r20 // s4
    char str[64]; // 0xA0(r29)
    char* goalList[3][10] = {{"BOARDER SCORE", "PRO SCORE", "SICK SCORE", "FINISH BEFORE ", " WITH ", "COLLECT THE %s LOGOS", "FIND THE SECRET SPONSOR", "TOTAL SPONSORS     %d/%d", " PTS", " PTS"}, {"BOARDER-SCORE", "PROFI-SCORE", "HAMMER-SCORE", "BEENDE UNTER ", " MIT ", "FINDE DIE %s-LOGOS!", "FINDE DEN VERSTECKTEN SPONSOR!", "SPONSOREN GESAMT     %d/%d", " PKTE", " PKTE!"}, {"SCORE DU SNOWBOARDER", "SCORE PRO", "SCORE DE FOU", "FINIS AVANT ", " AVEC ", "TROUVE LES LOGOS DE %s.", "TROUVE LE SPONSOR SECRET.", "NB DE SPONSORS     %d/%d", " PTS", " PTS."}}; // 0xE0(r29)
    char** goal = goalList[vspenvGame->language]; // r19 // s3
    sceVu0IMATRIX fcol; // 0x160(r29)
    FData fdata; // 0x1A0(r29)
    unsigned int level; // 0x1BC(r29)
    signed int ii; // r16 // s0
    signed int lx; // r17 // s1
    signed int dx; // r18 // s2
    signed int soft; // r22 // s6
    signed int lnum; // r23 // s7

    ayDrawCsLogo(packet);
    lnum = 10;
    nmfontInitOption();
    nmfontSetBil(1);
    fdata.size = 0x10;
    if (vspenvGame->character[0].no < 0xC) {
        for (ii = 0, soft = 0; ii < 8; ii++) {
            soft += vspenvSecret->character[vspenvGame->character[0].no].soft[ii];
        }
        level = vspenvSecret->character[vspenvGame->character[0].no].level_goal[cs];
    } else {
        for (ii = 0, soft = 0; ii < 8; ii++) {
            soft += vspenvSecret->create_character[vspenvGame->character[0].no - 0xC].character.soft[ii];
        }
        level = vspenvSecret->create_character[vspenvGame->character[0].no - 0xC].character.level_goal[cs];
    }
    for (ii = 0; ii < lnum; ii++) {
        switch (vayResData->step) {
        case 3:
            if (count < (ii + 2) * 4 / 2 + 0x10) {
                dx = -0x280;
            } else if (count < (ii + 2) * 4 / 2 + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, (signed int)(count - 0x10 - (ii + 2) * 4 / 2), 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 4:
            dx = 0;
            break;
        case 5:
            if (count < (ii + 2) * 4 / 2) {
                dx = 0;
            } else if (count < (ii + 2) * 4 / 2 + 0x10) {
                dx = ayCalcTotalMove(0x11, count - (ii + 2) * 4 / 2, 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        }
        if (ii == lnum - 1) {
            nmfontSetSize(0x14, 0x1C);
            fcol[0][0] = 0x80, fcol[0][1] = 0x80, fcol[0][2] = 0x40, fcol[0][3] = 0x80;
            fcol[1][0] = 0x80, fcol[1][1] = 0x80, fcol[1][2] = 0x40, fcol[1][3] = 0x80;
            fcol[2][0] = 0x80, fcol[2][1] = 0x80, fcol[2][2] = 0x80, fcol[2][3] = 0x80;
            fcol[3][0] = 0x80, fcol[3][1] = 0x80, fcol[3][2] = 0x80, fcol[3][3] = 0x80;
            nmfontSetCol(fcol[0]);
            ulstdSprintf(str, goal[7], soft, 0x48);
            nmfontGPrint(packet, str, dx + 0x140 - nmfontGetPackStrLen(str, 0x14, 0) / 2, 0x162);
        } else {
            nmfontSetSize(0x10, 0x10);
            if ((1 << ii) & level) {
                fcol[0][0] = 0x40, fcol[0][1] = 0x40, fcol[0][2] = 0x40, fcol[0][3] = 0x80;
            } else {
                fcol[0][0] = 0x80, fcol[0][1] = 0x80, fcol[0][2] = 0x80, fcol[0][3] = 0x80;
            }
            nmfontSetCol(fcol[0]);
            if (ii < 3) {
                nmfontSetPack(1);
                nmfontFPrint(packet, goal[ii], dx + 0x3C, 82.0f + (float)(ii * 24));
                lx = dx + 0x244 - nmfontGetPackStrLen(goal[8], 0x10, 0);
                nmfontFPrint(packet, goal[8], lx, 82.0f + (float)(ii * 24));
                fdata.value = vsptblLevelGoalValue[cs][ii];
                fdata.dx = (float)lx;
                fdata.dy = 82.0f + (float)(ii * 24);
                ayDrawNum(packet, &fdata, 1);
            } else if (ii == 3) {
                nmfontSetPack(1);
                nmfontFPrint(packet, goal[3], dx + 0x3C, 82.0f + (float)(ii * 24));
                lx = dx + 0x3C + nmfontGetPackStrLen(goal[3], 0x10, 0);
                ulstdSprintf(str, "%d", vsptblLevelGoalValue[cs][3] / 60);
                nmfontSetPack(0);
                nmfontFPrint(packet, str, lx, 82.0f + (float)(ii * 24));
                lx += 0x10;
                nmfontSetPack(1);
                nmfontFPrint(packet, ":", lx, 82.0f + (float)(ii * 24));
                lx += nmfontGetPackStrLen(":", 0x10, 0);
                ulstdSprintf(str, "%02d", vsptblLevelGoalValue[cs][3] % 60);
                nmfontSetPack(0);
                nmfontFPrint(packet, str, lx, 82.0f + (float)(ii * 24));
                lx += 0x20;
                nmfontSetPack(1);
                nmfontFPrint(packet, goal[4], lx, 82.0f + (float)(ii * 24));
                lx += nmfontGetPackStrLen(goal[4], 0x10, 0);
                fdata.value = vsptblLevelGoalValue[cs][4];
                fdata.dx = (float)lx;
                fdata.dy = 82.0f + (float)(ii * 24);
                lx = ayDrawNum(packet, &fdata, 0);
                nmfontSetPack(1);
                nmfontFPrint(packet, goal[9], lx, 82.0f + (float)(ii * 24));
            } else if (ii == 4) {
                nmfontSetPack(1);
                ulstdSprintf(str, goal[5], vsptblCourseName[cs + 0x10]);
                nmfontFPrint(packet, str, dx + 0x3C, 82.0f + (float)(ii * 24));
            } else if (ii == 5) {
                nmfontSetPack(1);
                nmfontFPrint(packet, goal[6], dx + 0x3C, 82.0f + (float)(ii * 24));
            } else {
                nmfontFPrint(packet, vsptblLevelGoalStr[cs][ii - 6], dx + 0x3C, 82.0f + (float)(ii * 24));
            }
        }
    }
}

static void aySetKeyOparate(Packet* packet) {
    signed int flg; // r16 // s0
    signed int kind; // r17 // s1
    signed int count; // r18 // s2
    Data* data; // r19 // s3
    signed int pno; // r20 // s4
    signed int point; // r21 // s5
    TexData texData; // 0x70(r29)

    count = vayResData->count;
    data = sploadGetGame2D();
    ultexResetTex(data->result.offset);
    texData.tofs = -1;
    texData.cofs = -1;
    nmdispTransTex(packet);
    memcpy(&texData, data->game.tex, 0x10);
    switch (vayResData->step) {
    case 0:
    case 0x17:
        kind = 0;
        if (count < 0x20) {
            flg = -2;
        } else {
            flg = 0;
        }
        break;
    case 3:
    case 0xF:
        if (count < 0x10) {
            kind = 0;
            flg = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            kind = 3;
            flg = -1;
        } else {
            kind = 3;
            flg = 0;
        }
        break;
    case 5:
    case 0x11:
        if (count < 0x10) {
            kind = 3;
            flg = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            kind = 0;
            flg = -1;
        } else {
            kind = 0;
            flg = 0;
        }
        break;
    case 4:
    case 0x10:
        kind = 3;
        flg = 0;
        break;
    case 9:
    case 0xC:
        if (count < 0x10) {
            kind = 0;
            flg = 1;
        } else {
            flg = 10;
        }
        break;
    case 0xA:
    case 0xD:
    case 0x1C:
        flg = 0;
        switch (ayMcGetStep()) {
        case 4:
            kind = 0;
            break;
        case 5:
            kind = 4;
            break;
        case 10:
            kind = 1;
            break;
        default:
            flg = 10;
            break;
        }
        break;
    case 0xB:
    case 0xE:
        if (count < 0x10) {
            flg = 10;
        } else if (count < 0x20) {
            count -= 0x10;
            flg = -1;
            kind = 0;
        } else {
            kind = 0;
            flg = 0;
        }
        break;
    case 6:
        if (count < 0x10) {
            kind = 0;
            flg = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
                kind = 1;
            } else {
                kind = 0x12;
            }
            flg = -1;
        } else {
            if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
                kind = 1;
            } else {
                kind = 0x12;
            }
            flg = 0;
        }
        break;
    case 8:
        if (count < 0x10) {
            if ((vayResData->step == 0x1F) || (vayResData->resKind == 0) || (vayResData->resKind == 2)) {
                kind = 0x12;
            } else {
                kind = 1;
            }
            flg = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            kind = 0;
            flg = -1;
        } else {
            kind = 0;
            flg = 0;
        }
        break;
    case 7:
        flg = 0;
        kind = 0x12;
        break;
    case 0x13:
        kind = 1;
        flg = 0;
        break;
    case 0x1F:
        if (count < 0x10) {
            kind = 0x12;
            flg = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            kind = 1;
            flg = -1;
        } else {
            kind = 1;
            flg = 0;
        }
        break;
    case 0x12:
        if (count < 0x10) {
            kind = 1;
            flg = 1;
        } else if (count < 0x20) {
            count -= 0x10;
            kind = 0x12;
            flg = -1;
        } else {
            kind = 0x12;
            flg = 0;
        }
        break;
    case 0x1E:
        flg = 0;
        kind = 0x12;
        break;
    case 0x14:
        flg = 10;
        break;
    case 0x15:
        switch (vayResData->decideflg) {
        case -1:
            flg = 0;
            pno = vspenvGame->character[0].no;
            if (pno < 0xC) {
                point = vspenvSecret->character[pno].rem_point;
            } else {
                point = vspenvSecret->create_character[pno - 0xC].character.rem_point;
            }
            if (point == 0) {
                kind = 0;
            } else {
                flg = 10;
            }
            break;
        case 0:
        case 1:
        case 2:
            kind = 0;
            flg = 0;
            break;
        }
        break;
    case 0x19:
    case 0x1A:
        kind = 0;
        if (count < 0x20) {
            count = count / 2;
            flg = -1;
        } else {
            flg = 0;
        }
        break;
    case 0x1D:
        if (count < 0x20) {
            count = count / 2;
            kind = 0;
            flg = 1;
        } else {
            flg = 10;
        }
        break;
    default:
        flg = 0;
        kind = 0;
        break;
    }
    if (flg != 10) {
        ayDrawKeyOparate(kind, count, flg, &texData, packet);
    }
}

static void ayDrawCsLogo(Packet* packet) {
    signed int unused1;
    signed int unused2;
    signed int dx; // r16 // s0
    signed int count; // r17 // s1
    void* addr; // r18 // s2
    signed int cs; // r19 // s3
    Data* loaddata; // r20 // s4
    Poly* poly; // r22 // s6
    AlphaTag* alpha; // r23 // s7
    QuadData data; // 0xA0(r29)
    sceVu0FVECTOR xy; // 0x180(r29)
    signed short cssize[8][2] = {{0xC8, 0x48}, {0x100, 0x52}, {0xC0, 0x58}, {0xC2, 0x58}, {0x100, 0x48}, {0xDC, 0x48}, {0xC2, 0x60}, {0xAC, 0x62}}; // 0x190(r29)

    count = vayResData->count;
    cs = vspenvGame->course.no;
    loaddata = sploadGetGame2D();
    nmdispTransTex(packet);
    addr = ulgifAddCNTReserve(packet, 9);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.texdata = loaddata->game.tex + 8;
    data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x40;
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x80;
    switch (vayResData->step) {
    case 3:
    case 0xF:
        if (count < 0x12) {
            dx = -0x280;
        } else if (count < 0x22) {
            dx = -640.0f + ayCalcTotalMove(0x11, count - 0x12, 640.0f, 1);
        } else {
            dx = 0;
        }
        break;
    case 4:
    case 0x10:
        dx = 0;
        break;
    case 5:
    case 0x11:
        if (count < 2) {
            dx = 0;
        } else if (count < 0x12) {
            dx = ayCalcTotalMove(0x11, count - 2, 640.0f, 3);
        } else {
            dx = 0x280;
        }
        break;
    }
    xy[0] = 320.0f + (float)dx - (float)cssize[cs][0], xy[1] = 112.0f - (float)cssize[cs][1] / 2.0f, xy[2] = 512.0f + xy[0], xy[3] = 128.0f + xy[1];
    aySetVert(data.vert[0], xy, 1);
    data.psmt = 0x14;
    aySetPolyComFT4(poly, &data, 1);
}

static void ayDrawScore(Packet* packet) {
    signed int count = vayResData->count; // r18 // s2
    signed int fcol[4]; // 0xA0(r29)
    char* rankList[3][6] = {{"1ST", "2ND", "3RD", "4TH", "5TH", "6TH"}, {"1.", "2.", "3.", "4.", "5.", "6."}, {"1ER", "2EME", "3EME", "4EME", "5EME", "6EME"}}; // 0xB0(r29)
    char** rank = rankList[vspenvGame->language]; // r23 // s7
    VspenvRecord* rec = vspenvRecord[vspenvGame->course.no][0]; // r20 // s4
    FData fdata; // 0x100(r29)
    signed int ii; // r16 // s0
    signed int dx; // r17 // s1
    signed int dy; // r19 // s3

    ayDrawCsLogo(packet);
    ayFontInit(0x12, 0x18, 0);
    fdata.size = 0x12;
    for (ii = 0; ii < 6; ii++) {
        switch (vayResData->step) {
        case 0xF:
            if ((count == 0x10) && (ii == 0)) {
                nmvcPlay(0x1A, 5, 2);
            }
            if (count < (ii + 2) * 4 / 2 + 0x10) {
                dx = -0x280;
            } else if (count < (ii + 2) * 4 / 2 + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x11, count - 0x10 - (ii + 2) * 4 / 2, 640.0f, 1);
            } else {
                dx = 0;
            }
            break;
        case 0x10:
            dx = 0;
            break;
        case 0x11:
            if ((count == 0) && (ii == 0)) {
                nmvcPlay(0x1B, 5, 3);
            }
            if (count < (ii + 2) * 4 / 2) {
                dx = 0;
            } else if (count < (ii + 2) * 4 / 2 + 0x10) {
                dx = ayCalcTotalMove(0x11, count - (ii + 2) * 4 / 2, 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        }
        dy = 110.0f + (float)(ii * 40);
        nmfontSetPack(0);
        fcol[0] = 0x80, fcol[1] = ii * 64 / 5 + 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
        nmfontSetCol(fcol);
        nmfontFPrint(packet, rank[ii], dx + 0x20, dy);
        fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        nmfontSetCol(fcol);
        nmfontFPrint(packet, rec[ii].name, dx + 0x68, dy);
        nmfontSetPack(1);
        if (rec[ii].chr_no < 0xC) {
            nmfontFPrint(packet, (char*)vsptblCharacterName[rec[ii].chr_no], dx + 0xB0, dy);
        } else {
            nmfontFPrint(packet, vspenvSecret->create_character[rec[ii].chr_no - 0xC].name, dx + 0xB0, dy);
        }
        fdata.value = rec[ii].score;
        fdata.dx = 604.0f + (float)dx;
        fdata.dy = (float)dy;
        ayDrawNum(packet, &fdata, 1);
    }
}

static void ayDrawStats(Packet* packet) {
    AlphaTag* alpha; // 0x214(r29)
    void* addr; // 0x218(r29)
    float dx; // 0x21C(r29)
    signed int count = vayResData->count; // 0x220(r29)
    QuadData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    char* menuList[3][5] = {{"OLLIE", "SPIN", "SPEED", "LANDING", "BALANCE"}, {"OLLIE", "SPIN", "TEMPO", "LANDUNG", "BALANCE"}, {"OLLIE", "ROTATION", "VITESSE", "RECEPTION", "EQUILIBRE"}}; // 0x190(r29)
    char** menu = menuList[vspenvGame->language]; // 0x224(r29)
    char* strList[3][3] = {{"DISTRIBUTE ALL POINTS.", "REMAINING POINTS", "REMAINING POINT"}, {"ALLE PUNKTE VERTEILEN.", "PUNKTE \224BRIG", "PUNKT \224BRIG"}, {"REPARTIR TOUS LES PTS.", "POINTS RESTANTS", "POINT RESTANT"}}; // 0x1D0(r29)
    char** str = strList[vspenvGame->language]; // 0x228(r29)
    signed int fcol[4]; // 0x200(r29)
    char pts[4]; // 0x22C(r29)
    signed int pno = vspenvGame->character[0].no; // 0x230(r29)
    signed int* param; // 0x234(r29)
    signed int* point; // 0x238(r29)
    signed int* max; // 0x23C(r29)
    signed int create; // 0x240(r29)
    signed int jj; // r16 // s0
    signed int ii; // r17 // s1
    signed int tmp; // r18 // s2
    signed int polnum; // r19 // s3
    Poly2* poly; // r20 // s4
    signed int col; // r21 // s5

    if (pno >= 0xC) {
        create = 1;
        param = (signed int*)&vspenvSecret->create_character[pno - 0xC].character.parameter;
        point = &vspenvSecret->create_character[pno - 0xC].character.rem_point;
        max = vayParamMax[10];
    } else {
        create = 0;
        param = (signed int*)&vspenvSecret->character[pno].parameter;
        point = &vspenvSecret->character[pno].rem_point;
        max = vayParamMax[pno];
    }
    ayFontInitmin();
    if ((vayResData->step == 0x15) && (vayResData->decideflg == -1)) {
        if (vgmsysPad[0]->rep & 0x4000) {
            nmvcPlayCursor(1);
            if (vayResData->stat == 4) {
                vayResData->stat = 0;
            } else {
                vayResData->stat++;
            }
        } else if (vgmsysPad[0]->rep & 0x1000) {
            nmvcPlayCursor(1);
            if (vayResData->stat == 0) {
                vayResData->stat = 4;
            } else {
                vayResData->stat--;
            }
        } else if ((vgmsysPad[0]->rep & 0x8000) && (vayResData->rem[vayResData->stat] > 0)) {
            nmvcPlayCursor(1);
            vayResData->rem[vayResData->stat]--;
            (*point)++;
        } else if ((vgmsysPad[0]->rep & 0x2000) && (*point > 0) && (vayResData->rem[vayResData->stat] + param[vayResData->stat] < max[vayResData->stat])) {
            nmvcPlayCursor(1);
            vayResData->rem[vayResData->stat]++;
            (*point)--;
        } else if ((vgmsysPad[0]->trg & 0x40) && (*point == 0)) {
            nmvcPlayButton(0);
            vayResData->decideflg = 0;
            vayResData->decidecnt = 0;
            vayResData->conf = 1;
        }
    }
    for (ii = 0; ii < 8; ii++) {
        switch (vayResData->step) {
        case 0x14:
            if ((count == 0) && (ii == 0)) {
                nmvcPlay(0x1A, 5, 2);
            }
            if (count < (ii + 1) * 4) {
                dx = -640.0f;
            } else if (count < (ii + 1) * 4 + 0x20) {
                dx = -640.0f + ayCalcTotalMove(0x21, count - (ii + 1) * 4, 640.0f, 1);
            } else {
                dx = 0.0f;
            }
            break;
        case 0x15:
            dx = 0.0f;
            break;
        case 0x16:
            if ((count == 0) && (ii == 0)) {
                nmvcPlay(0x1B, 5, 3);
            }
            if (count < (ii + 1) * 4 / 2) {
                dx = 0.0f;
            } else if (count < (ii + 1) * 4 / 2 + 0x10) {
                dx = ayCalcTotalMove(0x11, count - (ii + 1) * 4 / 2, 640.0f, 3);
            } else {
                dx = 640.0f;
            }
            break;
        }
        if (ii == 0) {
            fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            nmfontSetSize(0x1C, 0x1C);
            if (create) {
                nmfontFPrint(packet, vspenvSecret->create_character[pno - 0xC].name, 320.0f + dx - (float)(nmfontGetPackStrLen(vspenvSecret->create_character[pno - 0xC].name, 0x1C, 0) / 2), 0x54);
            } else {
                nmfontFPrint(packet, vsptblCharacterName[pno], 320.0f + dx - (float)(nmfontGetPackStrLen(vsptblCharacterName[pno], 0x1C, 0) / 2), 0x54);
            }
        } else if (ii == 6) {
            fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            nmfontSetSize(0x14, 0x14);
            nmfontFPrint(packet, str[0], 320.0f + dx - (float)(nmfontGetPackStrLen(str[0], 0x14, 0) / 2), 0x138);
        } else if (ii == 7) {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            if (*point == 1) {
                nmfontFPrint(packet, str[2], 290.0f + dx - (float)(nmfontGetPackStrLen(str[2], 0x14, 0) / 2), 0x152);
            } else {
                nmfontFPrint(packet, str[1], 290.0f + dx - (float)(nmfontGetPackStrLen(str[1], 0x14, 0) / 2), 0x152);
            }
            nmfontSetSize(0x18, 0x18);
            fcol[0] = 0x80, fcol[1] = 0x20, fcol[2] = 0, fcol[3] = 0x80;
            nmfontSetCol(fcol);
            ulstdSprintf(pts, " %2d", *point);
            nmfontFPrint(packet, pts, 290.0f + dx + (float)(nmfontGetPackStrLen(str[1], 0x14, 0) / 2), 0x150);
        } else {
            polnum = max[ii - 1];
            if (ii - 1 == vayResData->stat) {
                addr = ulgifAddCNTReserve(packet, ((signed int)((polnum + 1) * 0x40 + 0x20) + 0xF) >> 4);
            } else {
                addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x40 + 0x20) + 0xF) >> 4);
            }
            alpha = ((AlphaTag*)addr)++;
            ulpktInitALPHA(alpha, 1);
            poly = addr;
            if (ii - 1 == vayResData->stat) {
                data.col[0][0] = 0x80, data.col[0][1] = 0x40, data.col[0][2] = 0x80, data.col[0][3] = 0x40;
                xy[0] = 60.0f + dx, xy[1] = 63.0f + 15.0f * (float)(ii - 1), xy[2] = 580.0f + dx, xy[3] = 12.0f + xy[1];
                aySetVert(data.vert[0], xy, 1);
                aySetPolyComF4(poly, &data);
                poly++;
            }
            data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
            for (jj = 0; jj < polnum; jj++) {
                xy[0] = 220.0f + dx + 32.0f * (float)jj, xy[1] = 65.0f + 15.0f * (float)(ii - 1), xy[2] = 26.0f + xy[0], xy[3] = 8.0f + xy[1];
                aySetVert(data.vert[0], xy, 0xFFFFFF);
                aySetPolyComF4(poly + jj, &data);
            }
            polnum = param[ii - 1];
            addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x40 + 0x20) + 0xF) >> 4);
            alpha = ((AlphaTag*)addr)++;
            ulpktInitALPHA(alpha, 1);
            poly = addr;
            for (jj = 0; jj < polnum; jj++) {
                if (jj % 2 == 1) {
                    data.col[0][0] = 0xFE, data.col[0][1] = jj * 5 + 0xC4, data.col[0][2] = jj * 16 + 0x5F, data.col[0][3] = 0x80;
                } else {
                    data.col[0][0] = jj * 6 + 0xBB, data.col[0][1] = jj * 5 + 0xC4, data.col[0][2] = 0xFF, data.col[0][3] = 0x80;
                }
                xy[0] = 220.0f + dx + 32.0f * (float)jj, xy[1] = 65.0f + 15.0f * (float)(ii - 1), xy[2] = 26.0f + xy[0], xy[3] = 8.0f + xy[1];
                aySetVert(data.vert[0], xy, 0xFFFFFF);
                aySetPolyComF4(poly + jj, &data);
            }
            polnum = vayResData->rem[ii - 1];
            if (polnum > 0) {
                addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x40 + 0x20) + 0xF) >> 4);
                alpha = ((AlphaTag*)addr)++;
                ulpktInitALPHA(alpha, 1);
                poly = addr;
                col = vayResData->bgcnt % 0x40;
                if (col < 0x20) {
                    col = col * 4;
                } else {
                    col = 0x80 - (col - 0x20) * 4;
                }
                for (jj = 0; jj < polnum; jj++) {
                    tmp = jj + param[ii - 1];
                    if (tmp % 2 == 1) {
                        data.col[0][0] = 0xFE, data.col[0][1] = tmp * 5 + 0xC4, data.col[0][2] = tmp * 16 + 0x5F, data.col[0][3] = col;
                    } else {
                        data.col[0][0] = tmp * 6 + 0xBB, data.col[0][1] = tmp * 5 + 0xC4, data.col[0][2] = 0xFF, data.col[0][3] = col;
                    }
                    xy[0] = 220.0f + dx + 32.0f * (float)tmp, xy[1] = 65.0f + 15.0f * (float)(ii - 1), xy[2] = 26.0f + xy[0], xy[3] = 8.0f + xy[1];
                    aySetVert(data.vert[0], xy, 0xFFFFFF);
                    aySetPolyComF4(poly + jj, &data);
                }
            }
            if (ii % 2 == 1) {
                fcol[0] = 0x7F, fcol[1] = 0x62, fcol[2] = 0x30, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x5E, fcol[1] = 0x62, fcol[2] = 0x80, fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            nmfontSetSize(0x12, 0x16);
            nmfontFPrint(packet, menu[ii - 1], 140.0f + dx - (float)(nmfontGetPackStrLen(menu[ii - 1], 0x12, 0) / 2), (ii - 1) * 30 + 0x7E);
        }
    }
}

static void ayAddStats() {
    signed int ii; // r16 // s0
    signed int* param; // r17 // s1
    signed int pno; // r18 // s2

    pno = vspenvGame->character[0].no;
    if (pno >= 0xC) {
        param = (signed int*)&vspenvSecret->create_character[pno - 0xC].character.parameter;
    } else {
        param = (signed int*)&vspenvSecret->character[pno].parameter;
    }
    for (ii = 0; ii < 5; ii++) {
        param[ii] += vayResData->rem[ii];
        vayResData->rem[ii] = 0;
    }
}

static void ayDrawConfirm(Packet* packet) {
    signed int unused1;
    signed int unused2;
    signed int unused3;
    signed int unused4;
    signed int unused5;
    signed int unused6;
    signed int unused7;
    signed int count = vayResData->decidecnt; // r17 // s1
    char* strList[3][3] = {{"ARE YOU SURE?", "YES", "NO"}, {"BIST DU SICHER?", "JA", "NEIN"}, {"TU ES SUR ?", "OUI", "NON"}}; // 0xA0(r29)
    char** str = strList[vspenvGame->language]; // r20 // s4
    signed int fcol[2][4] = {{0x80, 0x80, 0x80, 0x80}, {0x80, 0x60, 0x40, 0x80}}; // 0xD0(r29)
    QuadData data; // 0xF0(r29)
    float xy[4]; // 0x1D0(r29)
    Poly2* poly; // 0x1E0(r29)
    AlphaTag* alpha; // 0x1E4(r29)
    signed int ii; // r16 // s0
    signed int dx; // r18 // s2
    signed int size; // r19 // s3
    signed int col; // r21 // s5
    void* addr; // r22 // s6

    switch (vayResData->decideflg) {
    case 0:
        if (count == 0) {
            nmvcPlay(0x1A, 5, 2);
        }
        if (count < 0x10) {
            col = count * 4;
        } else {
            col = 0x40;
        }
        if (count == 0x14) {
            vayResData->decideflg = 1;
            vayResData->decidecnt = -1;
        }
        break;
    case 1:
        col = 0x40;
        break;
    case 2:
        if (count == 0) {
            nmvcPlay(0x1B, 5, 3);
        }
        if (count < 0x10) {
            col = 0x40 - count * 4;
        } else {
            col = 0;
        }
        if (count == 0x14) {
            vayResData->decideflg = -1;
        }
        break;
    }
    addr = ulgifAddCNTReserve(packet, 6);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.col[0][0] = 0, data.col[0][1] = 0, data.col[0][2] = 0, data.col[0][3] = col;
    xy[0] = 0.0f, xy[1] = 0.0f, xy[2] = 640.0f, xy[3] = 224.0f;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComF4(poly, &data);
    count = vayResData->decidecnt;
    if (vayResData->decideflg == 1) {
        if (vayResData->decidecnt == -1) {
            if ((vgmsysPad[0]->rep & 0x1000) || (vgmsysPad[0]->rep & 0x4000) || (((vayResData->resKind == 1) || (vayResData->resKind == 3)) && ((vgmsysPad[1]->rep & 0x1000) || (vgmsysPad[1]->rep & 0x4000)))) {
                nmvcPlayCursor(1);
                vayResData->decidecnt = 0;
                vayResData->conf ^= 1;
            }
        } else {
            vayResData->decidecnt++;
            if (vayResData->decidecnt == 4) {
                vayResData->decidecnt = -1;
            }
        }
    } else {
        vayResData->decidecnt++;
    }
    ayFontInitmin();
    for (ii = 0; ii < 3; ii++) {
        switch (vayResData->decideflg) {
        case 0:
            if (count < ii * 2) {
                dx = -0x280;
            } else if (count < ii * 2 + 0x10) {
                dx = ayCalcTotalMove(0x11, count - ii * 2, 640.0f, 1) - 640.0f;
            } else {
                dx = 0;
            }
            break;
        case 1:
            dx = 0;
            break;
        case 2:
            if (count < ii * 2) {
                dx = 0;
            } else if (count < ii * 2 + 0x10) {
                dx = ayCalcTotalMove(0x11, count - ii * 2, 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        default:
            dx = 0x280;
            break;
        }
        if (ii == vayResData->conf + 1) {
            if ((vayResData->decideflg != 1) || (count == -1)) {
                size = 0x16;
            } else {
                size = 0x18;
            }
            nmfontSetCol(fcol[1]);
        } else {
            size = 0x14;
            nmfontSetCol(fcol[0]);
        }
        nmfontSetSize(size, size);
        nmfontFPrint(packet, str[ii], dx + (0x140 - nmfontGetPackStrLen(str[ii], size, 0) / 2), (ii + 1) * 3 / 2 * 24 + 0xC2 - size / 2);
    }
}

static void ayDrawSave(Packet* packet) {
    signed int count = vayResData->count; // r17 // s1
    char* strList[3][3] = {{"SAVE CAREER?", "YES", "NO"}, {"KARRIERE SPEICHERN?", "JA", "NEIN"}, {"SAUVEGARDER LA CARRIERE?", "OUI", "NON"}}; // 0x80(r29)
    char** str = strList[vspenvGame->language]; // r20 // s4
    signed int fcol[2][4] = {{0x80, 0x80, 0x80, 0x80}, {0x80, 0x60, 0x40, 0x80}}; // 0xB0(r29)
    signed int ii; // r16 // s0
    signed int dx; // r18 // s2
    signed int size; // r19 // s3

    if (vayResData->step == 0x18) {
        if (vayResData->movecnt == -1) {
            if ((vgmsysPad[0]->rep & 0x1000) || (vgmsysPad[0]->rep & 0x4000)) {
                nmvcPlayCursor(1);
                vayResData->save ^= 1;
                vayResData->movecnt = 0;
            }
        } else {
            vayResData->movecnt++;
            if (vayResData->movecnt == 4) {
                vayResData->movecnt = -1;
            }
        }
    }
    ayFontInitmin();
    for (ii = 0; ii < 3; ii++) {
        switch (vayResData->step) {
        case 0x16:
        case 0x1A:
            if ((count == 0) && (ii == 0)) {
                nmvcPlay(0x1A, 5, 2);
            }
            if (count < ii * 2 + 0x10) {
                dx = -0x280;
            } else if (count < ii * 2 + 0x20) {
                dx = ayCalcTotalMove(0x11, (signed int)(count - 0x10 - ii * 2), 640.0f, 1) - 640.0f;
            } else {
                dx = 0;
            }
            break;
        case 0x17:
            if ((count == 0) && (ii == 0)) {
                nmvcPlay(0x1A, 5, 2);
            }
            if (count < (ii + 1) * 4) {
                dx = -0x280;
            } else if (count < (ii + 1) * 4 + 0x20) {
                dx = ayCalcTotalMove(0x21, count - (ii + 1) * 4, 640.0f, 1) - 640.0f;
            } else {
                dx = 0;
            }
            break;
        case 0x18:
            dx = 0;
            break;
        case 0x1B:
        case 0x1D:
            if ((count == 0) && (ii == 0)) {
                nmvcPlay(0x1B, 5, 3);
            }
            if (count < ii * 2) {
                dx = 0;
            } else if (count < ii * 2 + 0x10) {
                dx = ayCalcTotalMove(0x11, count - ii * 2, 640.0f, 3);
            } else {
                dx = 0x280;
            }
            break;
        }
        if (ii == vayResData->save + 1) {
            if (vayResData->movecnt == -1) {
                size = 0x16;
            } else {
                size = 0x18;
            }
            nmfontSetCol(fcol[1]);
        } else {
            size = 0x14;
            nmfontSetCol(fcol[0]);
        }
        nmfontSetSize(size, size);
        nmfontFPrint(packet, str[ii], dx + (0x140 - nmfontGetPackStrLen(str[ii], size, 0) / 2), (ii + 1) * 3 / 2 * 24 + 0xC2 - size / 2);
    }
}

static signed int ayDrawChange(Packet* packet) {
    signed int ii; // r16 // s0
    signed int jj; // r17 // s1
    signed int cnum; // r18 // s2
    signed int pno; // r20 // s4
    signed int pnum; // r21 // s5
    signed int selnum; // r22 // s6
    signed int kindFlg; // r23 // s7
    signed int ret = 0; // r30 // fp
    signed int count = vayResData->count; // r19 // s3
    float dx[7]; // 0xA0(r29)
    signed int select[4]; // 0xC0(r29)
    signed int* crsr[2]; // 0xE8(r29)
    signed int next = vayResData->step; // 0xF8(r29)
    signed int button[2] = {1, 1}; // 0xF0(r29)
    signed int move = 0; // 0xFC(r29)
    char* strList[3][2] = {{"WAITING FOR", "OTHER PLAYER"}, {"WARTE AUF", "ANDEREN SPIELER"}, {"EN ATTENTE", "D'AUTRES JOUEURS"}}; // 0xD0(r29)
    char** str = strList[vspenvGame->language]; // 0x100(r29)

    switch (vayResData->resKind) {
    case 0:
        pnum = 1;
        kindFlg = 0;
        selnum = 2;
        select[1] = 1;
        select[2] = 2;
        select[0] = 3;
        crsr[0] = &vayResData->select[0];
        break;
    case 2:
        pnum = 1;
        selnum = 3;
        kindFlg = 2;
        select[1] = 0;
        select[2] = 1;
        select[3] = 2;
        select[0] = 3;
        crsr[0] = &vayResData->select[0];
        break;
    case 1:
    case 3:
        pnum = 2;
        kindFlg = 1;
        if (vayResData->step == 0x13) {
            selnum = 2;
            select[1] = 5;
            select[2] = 6;
            select[0] = 3;
            crsr[0] = crsr[1] = &vayResData->select[0];
        } else {
            selnum = 3;
            select[0] = 0;
            select[1] = 1;
            select[2] = 2;
            select[3] = 4;
            crsr[0] = &vayResData->select[0];
            crsr[1] = &vayResData->select[1];
        }
        break;
    }
    switch (vayResData->step) {
    case 6:
        if (count == 0x10) {
            nmvcPlay(0x1A, 5, 2);
        }
        for (ii = 0; ii < 4; ii++) {
            if (count < (ii + 1) * 4 + 0x10) {
                dx[ii] = -640.0f;
            } else if (count < (ii + 1) * 4 + 0x20) {
                dx[ii] = -640.0f + ayCalcTotalMove(0x11, count - 0x10 - (ii + 1) * 4, 640.0f, 1);
            } else {
                dx[ii] = 0.0f;
            }
        }
        break;
    case 7:
    case 0x13:
        for (ii = 0; ii < 7; ii++) {
            dx[ii] = 0.0f;
        }
        for (ii = 0; ii < pnum; ii++) {
            if (vayResData->decide[ii] != 1) {
                if (vgmsysPad[ii]->rep & 0x1000) {
                    if (*crsr[ii] == 0) {
                        if ((vayResData->step == 0x13) && (vayResData->rule >= 2)) {
                            *crsr[ii] = selnum - 1;
                        } else {
                            *crsr[ii] = selnum;
                        }
                    } else if ((ayChangeCharID(vayResData->chara[ii]) >= 0xC) && (vayResData->step != 0x13)) {
                        if (kindFlg != 2) {
                            if (*crsr[ii] == 2) {
                                *crsr[ii] = 0;
                            } else {
                                (*crsr[ii])--;
                            }
                        } else {
                            if (*crsr[ii] == 3) {
                                *crsr[ii] = 1;
                            } else {
                                (*crsr[ii])--;
                            }
                        }
                    } else {
                        (*crsr[ii])--;
                    }
                    nmvcPlayCursor(1);
                    button[ii] = 0;
                } else if (vgmsysPad[ii]->rep & 0x4000) {
                    if ((selnum == *crsr[ii]) || ((vayResData->step == 0x13) && (vayResData->rule >= 2) && (selnum - 1 == *crsr[ii]))) {
                        *crsr[ii] = 0;
                    } else if ((ayChangeCharID(vayResData->chara[ii]) >= 0xC) && (vayResData->step != 0x13)) {
                        if (kindFlg != 2) {
                            if (*crsr[ii] == 0) {
                                *crsr[ii] = 2;
                            } else {
                                (*crsr[ii])++;
                            }
                        } else {
                            if (*crsr[ii] == 1) {
                                *crsr[ii] = 3;
                            } else {
                                (*crsr[ii])++;
                            }
                        }
                    } else {
                        (*crsr[ii])++;
                    }
                    nmvcPlayCursor(1);
                    button[ii] = 0;
                } else if (vgmsysPad[ii]->rep & 0x8000) {
                    move = -1;
                    switch (select[*crsr[ii]]) {
                    case 0:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        vayResData->chara[ii]--;
                        for (jj = 0, cnum = 0; jj < 10; jj++) {
                            if (vspenvSecret->create_character[jj].character.secret != 0) {
                                cnum++;
                            }
                        }
                        if (vayResData->chara[ii] < 0) {
                            vayResData->chara[ii] = cnum + 0xB;
                            for (jj = 0xC; jj > 0xA; jj--) {
                                if (vspenvSecret->character[jj - 1].secret != 0) {
                                    break;
                                }
                                vayResData->chara[ii]--;
                            }
                        } else if ((vayResData->chara[ii] == cnum + 0xA) && (vspenvSecret->character[10].secret == 0)) {
                            vayResData->chara[ii]--;
                        }
                        if ((pnum == 2) && (vayResData->chara[ii] == vayResData->chara[ii ^ 1])) {
                            if (vayResData->wear[ii][vayResData->chara[ii]] == vayResData->wear[ii ^ 1][vayResData->chara[ii]]) {
                                if (vayResData->chara[ii] >= cnum + 0xA) {
                                    vayResData->wear[ii][vayResData->chara[ii ^ 1]] ^= 1;
                                } else if (vayResData->wear[ii][vayResData->chara[ii]] == 2) {
                                    vayResData->wear[ii][vayResData->chara[ii]] = 0;
                                } else {
                                    vayResData->wear[ii][vayResData->chara[ii]]++;
                                }
                            }
                        }
                        break;
                    case 1:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        if (vayResData->wear[ii][vayResData->chara[ii]] == 0) {
                            if (vayResData->chara[ii] < 10) {
                                vayResData->wear[ii][vayResData->chara[ii]] = 2;
                            } else {
                                vayResData->wear[ii][vayResData->chara[ii]] = 1;
                            }
                        } else {
                            vayResData->wear[ii][vayResData->chara[ii]]--;
                        }
                        if ((pnum == 2) && (vayResData->chara[ii] == vayResData->chara[ii ^ 1])) {
                            if (vayResData->wear[ii][vayResData->chara[ii]] == vayResData->wear[ii ^ 1][vayResData->chara[ii]]) {
                                if (vayResData->chara[ii] >= 10) {
                                    vayResData->wear[ii][vayResData->chara[ii]] ^= 1;
                                } else if (vayResData->wear[ii][vayResData->chara[ii]] == 0) {
                                    vayResData->wear[ii][vayResData->chara[ii]] = 2;
                                } else {
                                    vayResData->wear[ii][vayResData->chara[ii]]--;
                                }
                            }
                        }
                        break;
                    case 2:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        if (vayResData->board[ii][vayResData->chara[ii]] == 0) {
                            pno = ayChangeCharID(vayResData->chara[ii]);
                            if (((pno < 0xC) && (vspenvSecret->character[pno].board & 0x40)) || ((pno >= 0xC) && (vspenvSecret->create_character[pno - 0xC].character.board & 0x40))) {
                                vayResData->board[ii][vayResData->chara[ii]] = 6;
                            } else {
                                vayResData->board[ii][vayResData->chara[ii]] = 5;
                            }
                        } else {
                            vayResData->board[ii][vayResData->chara[ii]]--;
                        }
                        break;
                    case 3:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        vayResData->cs = ayCalcNextID(vayResData->cs, 8, -1);
                        break;
                    case 4:
                        if (vayResData->handi[ii] > 0) {
                            nmvcPlayCursor(1);
                            button[ii] = 0;
                            vayResData->handi[ii]--;
                        }
                        break;
                    case 5:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        if (vayResData->rule == 0) {
                            vayResData->rule = 3;
                        } else {
                            vayResData->rule--;
                        }
                        break;
                    case 6:
                        if (vayResData->rule < 3) {
                            nmvcPlayCursor(1);
                            button[ii] = 0;
                            vspenvOption->divide ^= 1;
                        } else {
                            nmvcPlayButton(3);
                        }
                        break;
                    }
                } else if (vgmsysPad[ii]->rep & 0x2000) {
                    move = 1;
                    switch (select[*crsr[ii]]) {
                    case 0:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        for (jj = 0, cnum = 0; jj < 10; jj++) {
                            if (vspenvSecret->create_character[jj].character.secret != 0) {
                                cnum++;
                            }
                        }
                        vayResData->chara[ii]++;
                        if (vayResData->chara[ii] == cnum + 0xC) {
                            vayResData->chara[ii] = 0;
                        }
                        if ((vayResData->chara[ii] == cnum + 0xA) && (vspenvSecret->character[10].secret == 0)) {
                            vayResData->chara[ii]++;
                        }
                        if ((vayResData->chara[ii] == cnum + 0xB) && (vspenvSecret->character[11].secret == 0)) {
                            vayResData->chara[ii] = 0;
                        }
                        if ((pnum == 2) && (vayResData->chara[ii] == vayResData->chara[ii ^ 1])) {
                            if (vayResData->wear[ii][vayResData->chara[ii]] == vayResData->wear[ii ^ 1][vayResData->chara[ii]]) {
                                if (vayResData->chara[ii] >= cnum + 0xA) {
                                    vayResData->wear[ii][vayResData->chara[ii ^ 1]] ^= 1;
                                } else if (vayResData->wear[ii][vayResData->chara[ii]] == 2) {
                                    vayResData->wear[ii][vayResData->chara[ii]] = 0;
                                } else {
                                    vayResData->wear[ii][vayResData->chara[ii]]++;
                                }
                            }
                        }
                        break;
                    case 1:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        if ((vayResData->chara[ii] < 10) && (vayResData->wear[ii][vayResData->chara[ii]] == 2)) {
                            vayResData->wear[ii][vayResData->chara[ii]] = 0;
                        } else if ((vayResData->chara[ii] >= 10) && (vayResData->wear[ii][vayResData->chara[ii]] == 1)) {
                            vayResData->wear[ii][vayResData->chara[ii]] = 0;
                        } else {
                            vayResData->wear[ii][vayResData->chara[ii]]++;
                        }
                        if ((pnum == 2) && (vayResData->chara[ii] == vayResData->chara[ii ^ 1])) {
                            if (vayResData->wear[ii][vayResData->chara[ii]] == vayResData->wear[ii ^ 1][vayResData->chara[ii]]) {
                                if (vayResData->chara[ii] >= 10) {
                                    vayResData->wear[ii][vayResData->chara[ii]] ^= 1;
                                } else if (vayResData->wear[ii][vayResData->chara[ii]] == 0) {
                                    vayResData->wear[ii][vayResData->chara[ii]] = 2;
                                } else {
                                    vayResData->wear[ii][vayResData->chara[ii]]--;
                                }
                            }
                        }
                        break;
                    case 2:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        if (vayResData->board[ii][vayResData->chara[ii]] == 5) {
                            pno = ayChangeCharID(vayResData->chara[ii]);
                            if (((pno < 0xC) && (vspenvSecret->character[pno].board & 0x40)) || ((pno >= 0xC) && (vspenvSecret->create_character[pno - 0xC].character.board & 0x40))) {
                                vayResData->board[ii][vayResData->chara[ii]] = 6;
                            } else {
                                vayResData->board[ii][vayResData->chara[ii]] = 0;
                            }
                        } else if (vayResData->board[ii][vayResData->chara[ii]] == 6) {
                            vayResData->board[ii][vayResData->chara[ii]] = 0;
                        } else {
                            vayResData->board[ii][vayResData->chara[ii]]++;
                        }
                        break;
                    case 3:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        vayResData->cs = ayCalcNextID(vayResData->cs, 8, 1);
                        break;
                    case 4:
                        if (vayResData->handi[ii] < 10) {
                            nmvcPlayCursor(1);
                            button[ii] = 0;
                            vayResData->handi[ii]++;
                        }
                        break;
                    case 5:
                        nmvcPlayCursor(1);
                        button[ii] = 0;
                        if (vayResData->rule == 3) {
                            vayResData->rule = 0;
                        } else {
                            vayResData->rule++;
                        }
                        break;
                    case 6:
                        if (vayResData->rule < 3) {
                            nmvcPlayCursor(1);
                            button[ii] = 0;
                            vspenvOption->divide ^= 1;
                        } else {
                            nmvcPlayButton(3);
                        }
                        break;
                    }
                }
            }
        }
        break;
    case 0x12:
        if (count == 0) {
            nmvcPlay(0x1B, 5, 3);
        }
        for (ii = 0; ii < 3; ii++) {
            if (count < ii * 4) {
                dx[ii] = 0.0f;
            } else if (count < ii * 4 + 0x10) {
                dx[ii] = ayCalcTotalMove(0x11, count - ii * 4, 640.0f, 3);
            } else {
                dx[ii] = -640.0f;
            }
        }
        if (count == 0x10) {
            nmvcPlay(0x1A, 5, 2);
        }
        for (ii = 0; ii < 4; ii++) {
            if (count < ii * 4 + 0x10) {
                dx[ii + 3] = -640.0f;
            } else if (count < ii * 4 + 0x20) {
                dx[ii + 3] = -640.0f + ayCalcTotalMove(0x11, count - 0x10 - ii * 4, 640.0f, 1);
            } else {
                dx[ii + 3] = 0.0f;
            }
        }
        break;
    case 8:
        if (count == 0) {
            nmvcPlay(0x1B, 5, 3);
        }
        for (ii = 0; ii < 7; ii++) {
            if (count < (ii % 4 + 1) * 4) {
                dx[ii] = 0.0f;
            } else if (count < (ii % 4 + 1) * 4 + 0x10) {
                dx[ii] = ayCalcTotalMove(0x11, count - (ii % 4 + 1) * 4, 640.0f, 3);
            } else {
                dx[ii] = -640.0f;
            }
        }
        break;
    case 0x1F:
        if (count == 0) {
            nmvcPlay(0x1B, 5, 3);
        }
        for (ii = 0; ii < 4; ii++) {
            if (count < ii * 4) {
                dx[ii] = 0.0f;
            } else if (count < ii * 4 + 0x10) {
                dx[ii] = ayCalcTotalMove(0x11, count - ii * 4, 640.0f, 3);
            } else {
                dx[ii] = -640.0f;
            }
        }
        if (count == 0x10) {
            nmvcPlay(0x1A, 5, 2);
        }
        for (ii = 0; ii < 3; ii++) {
            if (count < ii * 4 + 0x10) {
                dx[ii + 4] = -640.0f;
            } else if (count < ii * 4 + 0x20) {
                dx[ii + 4] = -640.0f + ayCalcTotalMove(0x11, count - 0x10 - ii * 4, 640.0f, 1);
            } else {
                dx[ii + 4] = 0.0f;
            }
        }
        break;
    case 0x1E:
        if (count == 0) {
            nmvcPlay(0x1B, 5, 3);
        }
        for (ii = 0; ii < 7; ii++) {
            if (count < (ii % 4 + 1) * 4) {
                dx[ii] = 0.0f;
            } else if (count < (ii % 4 + 1) * 4 + 0x20) {
                dx[ii] = ayCalcTotalMove(0x21, count - (ii % 4 + 1) * 4, 640.0f, 3);
            } else {
                dx[ii] = -640.0f;
            }
        }
        break;
    }
    switch (vayResData->resKind) {
    case 0:
        ayDrawChCs(packet, 44.0f + dx[0], 58.0f, vayResData->select[0] == 0);
        ayDrawChWear(packet, 74.0f + dx[1], 96.0f, vayResData->select[0] == 1, 0);
        ayDrawChBoard(packet, 104.0f + dx[2], 134.0f, vayResData->select[0] == 2, 0);
        break;
    case 2:
        ayDrawChCs(packet, 34.0f + dx[0], 44.0f, vayResData->select[0] == 0);
        ayDrawChPlayer(packet, 56.0f + dx[1], 80.0f, vayResData->select[0] == 1, 0);
        ayDrawChWear(packet, 78.0f + dx[2], 116.0f, vayResData->select[0] == 2, 0);
        ayDrawChBoard(packet, 100.0f + dx[3], 152.0f, vayResData->select[0] == 3, 0);
        break;
    case 1:
    case 3:
        switch (vayResData->step) {
        case 0x12:
            ayDrawChCs(packet, 44.0f + dx[0], 58.0f, (vayResData->select[0] == 0) || (vayResData->select[1] == 0));
            ayDrawChRule(packet, 74.0f + dx[1], 96.0f, (vayResData->select[0] == 1) || (vayResData->select[1] == 1), 0);
            ayDrawChRule(packet, 104.0f + dx[2], 134.0f, (vayResData->select[0] == 2) || (vayResData->select[1] == 2), 1);
            ayDrawChPlayer(packet, 15.0f + dx[3], 54.0f, 1, 0);
            ayDrawChWear(packet, 30.0f + dx[4], 88.0f, 0, 0);
            ayDrawChBoard(packet, 45.0f + dx[5], 122.0f, 0, 0);
            ayDrawChHandi(packet, 60.0f + dx[6], 156.0f, 0, 0);
            ayDrawChPlayer(packet, 290.0f + dx[3], 54.0f, 1, 1);
            ayDrawChWear(packet, 305.0f + dx[4], 88.0f, 0, 1);
            ayDrawChBoard(packet, 320.0f + dx[5], 122.0f, 0, 1);
            ayDrawChHandi(packet, 335.0f + dx[6], 156.0f, 0, 1);
            break;
        case 7:
            ayDrawChPlayer(packet, 15.0f + dx[0], 54.0f, vayResData->select[0] == 0, 0);
            ayDrawChWear(packet, 30.0f + dx[1], 88.0f, vayResData->select[0] == 1, 0);
            ayDrawChBoard(packet, 45.0f + dx[2], 122.0f, vayResData->select[0] == 2, 0);
            ayDrawChHandi(packet, 60.0f + dx[3], 156.0f, vayResData->select[0] == 3, 0);
            ayDrawChPlayer(packet, 290.0f + dx[0], 54.0f, vayResData->select[1] == 0, 1);
            ayDrawChWear(packet, 305.0f + dx[1], 88.0f, vayResData->select[1] == 1, 1);
            ayDrawChBoard(packet, 320.0f + dx[2], 122.0f, vayResData->select[1] == 2, 1);
            ayDrawChHandi(packet, 335.0f + dx[3], 156.0f, vayResData->select[1] == 3, 1);
            break;
        case 0x1F:
            ayDrawChPlayer(packet, 15.0f + dx[0], 54.0f, vayResData->select[0] == 0, 0);
            ayDrawChWear(packet, 30.0f + dx[1], 88.0f, vayResData->select[0] == 1, 0);
            ayDrawChBoard(packet, 45.0f + dx[2], 122.0f, vayResData->select[0] == 2, 0);
            ayDrawChHandi(packet, 60.0f + dx[3], 156.0f, vayResData->select[0] == 3, 0);
            ayDrawChPlayer(packet, 290.0f + dx[0], 54.0f, vayResData->select[1] == 0, 1);
            ayDrawChWear(packet, 305.0f + dx[1], 88.0f, vayResData->select[1] == 1, 1);
            ayDrawChBoard(packet, 320.0f + dx[2], 122.0f, vayResData->select[1] == 2, 1);
            ayDrawChHandi(packet, 335.0f + dx[3], 156.0f, vayResData->select[1] == 3, 1);
            ayDrawChCs(packet, 44.0f + dx[4], 58.0f, 1);
            ayDrawChRule(packet, 74.0f + dx[5], 96.0f, 0, 0);
            ayDrawChRule(packet, 104.0f + dx[6], 134.0f, 0, 1);
            break;
        case 6:
            ayDrawChCs(packet, 44.0f + dx[0], 58.0f, 1);
            ayDrawChRule(packet, 74.0f + dx[1], 96.0f, 0, 0);
            ayDrawChRule(packet, 104.0f + dx[2], 134.0f, 0, 1);
            break;
        case 0x13:
        case 8:
            ayDrawChCs(packet, 44.0f + dx[0], 58.0f, vayResData->select[0] == 0);
            ayDrawChRule(packet, 74.0f + dx[1], 96.0f, vayResData->select[0] == 1, 0);
            ayDrawChRule(packet, 104.0f + dx[2], 134.0f, vayResData->select[0] == 2, 1);
            break;
        case 0x1E:
            ayDrawChPlayer(packet, 15.0f + dx[0], 54.0f, vayResData->select[0] == 0, 0);
            ayDrawChWear(packet, 30.0f + dx[1], 88.0f, vayResData->select[0] == 1, 0);
            ayDrawChBoard(packet, 45.0f + dx[2], 122.0f, vayResData->select[0] == 2, 0);
            ayDrawChHandi(packet, 60.0f + dx[3], 156.0f, vayResData->select[0] == 3, 0);
            ayDrawChPlayer(packet, 290.0f + dx[0], 54.0f, vayResData->select[1] == 0, 1);
            ayDrawChWear(packet, 305.0f + dx[1], 88.0f, vayResData->select[1] == 1, 1);
            ayDrawChBoard(packet, 320.0f + dx[2], 122.0f, vayResData->select[1] == 2, 1);
            ayDrawChHandi(packet, 335.0f + dx[3], 156.0f, vayResData->select[1] == 3, 1);
            break;
        }
        break;
    }
    if (vayResData->step == 7) {
        for (ii = 0; ii < pnum; ii++) {
            if ((vgmsysPad[ii]->trg & 0x40) && button[ii]) {
                if (vayResData->decide[ii] == 0) {
                    nmvcPlayButton(0);
                    if ((kindFlg == 1) && (vayResData->decide[ii ^ 1] != 1)) {
                        vayResData->decide[ii] = 1;
                        vayResData->select[ii] = -1;
                    } else {
                        vayResData->step = 0x1E;
                        vayResData->ret = ayCheckLoad();
                        ret = 1;
                    }
                } else if (vayResData->decide[ii] == -1) {
                    nmvcPlayButton(3);
                }
            } else if ((vgmsysPad[ii]->trg & 0x10) && button[ii] && (vayResData->decide[ii ^ 1] != 1)) {
                nmvcPlayButton(2);
                if (vayResData->decide[ii] == 1) {
                    vayResData->decide[ii] = 0;
                    vayResData->select[ii] = 0;
                } else {
                    if (kindFlg == 1) {
                        if (vayResData->decide[ii ^ 1] != 1) {
                            vayResData->step = 0x1F;
                        }
                    } else {
                        vayResData->step = 8;
                    }
                    ret = 1;
                }
            }
        }
    } else if (vayResData->step == 0x13) {
        for (ii = 0; ii < 2; ii++) {
            if ((vgmsysPad[ii]->trg & 0x40) && button[ii]) {
                if (vayResData->decide[ii] == 0) {
                    nmvcPlayButton(0);
                    vayResData->step = 0x12;
                    vayResData->decide[ii ^ 1] = 0;
                    ret = 1;
                } else if (vayResData->decide[ii] == -1) {
                    nmvcPlayButton(3);
                }
            } else if ((vgmsysPad[ii]->trg & 0x10) && button[ii]) {
                nmvcPlayButton(2);
                vayResData->step = 8;
                ret = 1;
            }
        }
    }
    for (ii = 0; ii < pnum; ii++) {
        if ((vayResData->decide[ii] == 1) && (vayResData->step != 0x1E)) {
            ayFontInit(0x14, 0x14, 0);
            nmfontFPrint(packet, str[0], ii * 300 + 0x1E, 0xC8);
            nmfontFPrint(packet, str[1], ii * 300 + 0x32, 0xE0);
        }
    }
    return ret;
}

static void ayDrawChWear(Packet* packet, float dx, float dy, signed int flg, signed int no) {
    signed int id = 0; // r17 // s1
    void* addr; // r23 // s7
    TexData texData[2]; // 0xA0(r29)
    QuadData data; // 0xC0(r29)
    float xy[4]; // 0x1A0(r29)
    char* nameList[3] = {"STYLE A", "STIL A", "STYLE A"}; // 0x1B8(r29)
    char* name = nameList[vspenvGame->language]; // r30 // fp
    signed int len[3] = {6, 5, 6}; // 0x1C8(r29)
    AlphaTag* alpha; // 0x1D8(r29)
    signed int pno; // 0x1DC(r29)
    signed int vsflg; // 0x1E0(r29)
    signed int nflg; // 0x1E4(r29)
    float diff; // 0x1E8(r29)
    signed int ii; // r16 // s0
    Data* loaddata; // r19 // s3
    Poly* poly; // r20 // s4
    signed int polnum; // r21 // s5
    signed int aflg; // r22 // s6

    if (((vayResData->step == 7) || (vayResData->step == 0x13)) && flg) {
        aflg = 1;
    } else {
        aflg = 0;
    }
    if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
        diff = 157.0f;
        vsflg = 1;
    } else {
        diff = 290.0f;
        vsflg = 0;
    }
    loaddata = sploadGetGame2D();
    ultexResetTex(loaddata->result.offset);
    for (ii = 0; ii < 2; ii++) {
        texData[ii].tofs = texData[ii].cofs = -1;
    }
    pno = ayChangeCharID(vayResData->chara[no]);
    if (pno < 0xC) {
        nflg = 1;
        ultexTransTexTag(packet, loaddata->result.utd, &texData[0], vayResData->wear[no][vayResData->chara[no]] + (pno * 3 + 1));
        if (aflg) {
            polnum = 4;
            nmdispTransTex(packet);
        } else {
            polnum = 2;
        }
    } else {
        nflg = 0;
        ultexTransTexTag(packet, loaddata->result.utd, &texData[0], 0x29);
        polnum = 2;
    }
    if (no == 1) {
        polnum--;
    } else {
        ultexTransTexTag(packet, loaddata->result.utd, &texData[1], 0x27);
    }
    ayDrawBackBoard(packet, dx, dy, vsflg);
    addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x70 + 0x20) + 0xF) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    if (flg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    } else {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
    }
    data.psmt = 0x14;
    if (no == 0) {
        data.texdata = &texData[1];
        data.uv[0] = 0, data.uv[1] = 0x20, data.uv[2] = 0x80, data.uv[3] = 0x40;
        xy[0] = dx, xy[1] = dy, xy[2] = 128.0f + dx, xy[3] = 16.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly, &data, 1);
        id = 1;
    }
    data.texdata = &texData[0];
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;
    xy[0] = dx + diff, xy[1] = dy, xy[2] = 64.0f + xy[0], xy[3] = 32.0f + dy;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly + id, &data, 1);
    id++;
    if (nflg) {
        ayFontInit(0x10, 0x10, data.col[0]);
        name[len[vspenvGame->language]] = (signed char)vayResData->wear[no][vayResData->chara[no]] + 0x41;
        nmfontFPrint(packet, name, dx, 48.0f + 2.0f * dy);
    }
    if (aflg) {
        data.texdata = loaddata->game.tex + 1;
        for (ii = 0; ii < 2; ii++) {
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = ii * 32 + 0x20, data.uv[3] = 0x40;
            xy[0] = 112.0f * (float)ii + (dx + diff - 40.0f), xy[1] = 8.0f + dy, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(poly + (ii + id), &data, 1);
        }
    }
}

static void ayDrawChBoard(Packet* packet, float dx, float dy, signed int flg, signed int no) {
    AlphaTag* alpha; // 0x3DC(r29)
    void* addr; // 0x3E0(r29)
    signed int id = 0; // 0x3E4(r29)
    signed int count = vayResData->count; // r18 // s2
    TexData texData[2]; // 0xA0(r29)
    QuadData data; // 0xC0(r29)
    float xy[4]; // 0x1A0(r29)
    MdlEnv mdlEnv; // 0x1B0(r29)
    sceVu0FMATRIX mat; // 0x2D0(r29)
    sceVu0FVECTOR trans = {0.0f, 80.0f, 0.0f, 1.0f}; // 0x310(r29)
    sceVu0FVECTOR rot = {1.5707964f, 0.0f, 0.0f, 1.0f}; // 0x320(r29)
    sceVu0FMATRIX worldScr; // 0x330(r29)
    char* mesList[3][4] = {{"NEED %d SPONSORS", "TO UNLOCK BOARD", "UNLOCK IN", "CAREER MODE"}, {"%d SPONSOREN ZUM FREISCHALTEN", "DES BOARD BEN\x92TIGT", "IM KARRIERE-MODUS", "FREISPIELEN"}, {"%d SPONSORS NECESSAIRES POUR", "DEVERROUILLER CE PLANCHE", "DEVERROUILLER EN", "MODE CARRIERE"}}; // 0x370(r29)
    char** mes = mesList[vspenvGame->language]; // r20 // s4
    char str[32]; // 0x3A0(r29)
    signed int soft[6] = {0, 8, 0x11, 0x1A, 0x23, 0x2D}; // 0x3C0(r29)
    Poly* poly; // r30 // fp
    signed int pno; // 0x3E8(r29)
    signed int board; // 0x3EC(r29)
    signed int vsflg; // 0x3F0(r29)
    float diff; // 0x3F4(r29)
    float scale; // 0x3F8(r29)
    signed int aflg; // 0x3FC(r29)
    signed int ii; // r16 // s0
    signed int movef; // r17 // s1
    Data* loaddata; // r19 // s3
    signed int brdflg; // r21 // s5
    signed int polnum; // r23 // s7

    if (((vayResData->step == 7) || (vayResData->step == 0x13)) && flg) {
        aflg = 1;
    } else {
        aflg = 0;
    }
    if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
        diff = 68.0f;
        vsflg = 1;
    } else {
        diff = 216.0f;
        vsflg = 0;
    }
    loaddata = sploadGetGame2D();
    pno = ayChangeCharID(vayResData->chara[no]);
    if (pno < 0xC) {
        board = pno;
        brdflg = (1 << vayResData->board[no][vayResData->chara[no]]) & vspenvSecret->character[pno].board;
    } else {
        board = vspenvSecret->create_character[pno - 0xC].board_type;
        brdflg = vspenvSecret->create_character[pno - 0xC].character.board & (1 << vayResData->board[no][vayResData->chara[no]]);
    }
    ayDrawBackBoard(packet, dx, dy, vsflg);
    aySetCamMatrix(worldScr[0], mdlEnv.world_view[0], mdlEnv.view_screen[0]);
    if (flg && brdflg) {
        aySetLightMatrix(mdlEnv.normal_light[0], mdlEnv.light_color[0], 0.4f, 0.1f);
    } else {
        aySetLightMatrix(mdlEnv.normal_light[0], mdlEnv.light_color[0], 0.2f, 0.01f);
    }
    if (vayResData->resKind == 2) {
        movef = 0x10;
    } else {
        movef = 0xC;
    }
    switch (vayResData->resKind) {
    case 2:
    case 0:
        scale = 9.37f;
        switch (vayResData->step) {
        case 6:
            if (count < movef + 0x10) {
                trans[0] = -714.0f;
            } else if (count < movef + 0x20) {
                trans[0] = -714.0f + ayCalcTotalMove(0x11, count - 0x10 - movef, 806.0f, 1);
            } else {
                trans[0] = 92.0f;
            }
            break;
        case 7:
            trans[0] = 92.0f;
            if (flg && brdflg) {
                rot[0] = rot[0] + 0.020943947f * (float)(vayResData->rotcnt[no] % 300);
                if (!(rot[0] < 3.141592f)) {
                    rot[0] = rot[0] - 6.283184f;
                }
                vayResData->rotcnt[no]++;
            } else {
                vayResData->rotcnt[no] = 0;
            }
            break;
        case 8:
            if (count < movef) {
                trans[0] = 92.0f;
            } else if (count < movef + 0x10) {
                trans[0] = 92.0f + ayCalcTotalMove(0x11, count - movef, 806.0f, 3);
            } else {
                trans[0] = 428.0f;
            }
            break;
        case 0x1E:
            if (count < movef) {
                trans[0] = 92.0f;
            } else if (count < movef + 0x20) {
                trans[0] = 92.0f + ayCalcTotalMove(0x21, count - movef, 806.0f, 3);
            } else {
                trans[0] = 428.0f;
            }
            break;
        }
        if (vayResData->resKind == 2) {
            trans[1] = 115.0f;
            trans[0] = trans[0] - 5.0f;
        }
        break;
    case 1:
    case 3:
        trans[1] = 62.0f;
        scale = 7.56f;
        switch (vayResData->step) {
        case 0x12:
            movef -= 4;
            if (count < movef + 0x10) {
                trans[0] = -890.0f + 268.0f * (float)no;
            } else if (count < movef + 0x20) {
                trans[0] = -890.0f + 268.0f * (float)no + ayCalcTotalMove(0x11, count - 0x10 - movef, 776.0f, 1);
            } else {
                trans[0] = -114.0f + 268.0f * (float)no;
            }
            break;
        case 7:
            trans[0] = -114.0f + 268.0f * (float)no;
            if (flg && brdflg) {
                rot[0] = rot[0] + 0.020943947f * (float)(vayResData->rotcnt[no] % 300);
                if (!(rot[0] < 3.141592f)) {
                    rot[0] = rot[0] - 6.283184f;
                }
                vayResData->rotcnt[no]++;
            } else {
                vayResData->rotcnt[no] = 0;
            }
            break;
        case 0x1F:
            movef -= 4;
            if (count < movef) {
                trans[0] = -114.0f + 268.0f * (float)no;
            } else if (count < movef + 0x10) {
                trans[0] = -114.0f + 268.0f * (float)no + ayCalcTotalMove(0x11, count - movef, 776.0f, 3);
            } else {
                trans[0] = 388.0f + 268.0f * (float)no;
            }
            break;
        case 0x1E:
            if (count < movef) {
                trans[0] = -114.0f + 268.0f * (float)no;
            } else if (count < movef + 0x20) {
                trans[0] = -114.0f + 268.0f * (float)no + ayCalcTotalMove(0x21, count - movef, 776.0f, 3);
            } else {
                trans[0] = 388.0f + 268.0f * (float)no;
            }
            break;
        }
        break;
    }
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixX(mat, mat, rot[0]);
    sceVu0RotMatrixY(mat, mat, rot[1]);
    sceVu0RotMatrixZ(mat, mat, rot[2]);
    sceVu0TransMatrix(mat, mat, trans);
    ul3dScaleMatrixXYZ(mat[0], scale, scale, scale);
    if (vayResData->board[no][vayResData->chara[no]] >= 6) {
        ultexTransTexTag(packet, loaddata->ayboard_utd, loaddata->board_tex, vayResData->board[no][vayResData->chara[no]] + 0x42);
    } else if (brdflg) {
        ultexTransTexTag(packet, loaddata->ayboard_utd, loaddata->board_tex, vayResData->board[no][vayResData->chara[no]] + board * 6);
    } else {
        ultexTransTexTag(packet, loaddata->ayboard_utd, loaddata->board_tex, 0x49);
    }
    mdlEnv.fog.enable = 0;
    sceGifPkCnt(packet, 0, 0, 0);
    sceGifPkReserve(packet, ulmdlDrawModelPkt(packet->pCurrent, 0, &mdlEnv, mat[0], loaddata->board_umd, 1));
    sceGifPkTerminate(packet);
    ultexResetTex(loaddata->result.offset);
    for (ii = 0; ii < 2; ii++) {
        texData[ii].tofs = texData[ii].cofs = -1;
    }
    if (aflg) {
        polnum = 3;
        nmdispTransTex(packet);
    } else {
        polnum = 1;
    }
    if (brdflg == 0) {
        polnum++;
        ultexTransTexTag(packet, loaddata->result.utd, &texData[1], 0x29);
        vayResData->decide[no] = -1;
    }
    if (no == 1) {
        polnum--;
    } else {
        ultexTransTexTag(packet, loaddata->result.utd, &texData[0], 0x27);
    }
    if (polnum > 0) {
        addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x70 + 0x20) + 0xF) >> 4);
        alpha = ((AlphaTag*)addr)++;
        ulpktInitALPHA(alpha, 1);
        poly = addr;
    }
    if (flg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    } else {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
    }
    data.psmt = 0x14;
    data.texdata = &texData[0];
    if (no == 0) {
        data.uv[0] = 0, data.uv[1] = 0x60, data.uv[2] = 0x80, data.uv[3] = 0x80;
        xy[0] = dx, xy[1] = dy, xy[2] = 128.0f + dx, xy[3] = 16.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly, &data, 1);
        id = 1;
    }
    if (aflg) {
        data.texdata = loaddata->game.tex + 1;
        for (ii = 0; ii < 2; ii++) {
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = ii * 32 + 0x20, data.uv[3] = 0x40;
            if (vsflg) {
                xy[0] = 52.0f + dx + 182.0f * (float)ii, xy[1] = 14.0f + dy, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
            } else {
                xy[0] = 180.0f + dx + 230.0f * (float)ii, xy[1] = 8.0f + dy, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
            }
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(poly + (id + ii), &data, 1);
        }
    }
    ayFontInit(0x10, 0x10, data.col[0]);
    if (brdflg == 0) {
        data.texdata = &texData[1];
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;
        xy[0] = 64.0f + (dx + diff), xy[1] = dy, xy[2] = 64.0f + xy[0], xy[3] = 32.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (polnum - 1), &data, 1);
        if (vayResData->board[no][vayResData->chara[no]] < 6) {
            if (vayResData->resKind == 0) {
                ulstdSprintf(str, mes[0], soft[vayResData->board[no][vayResData->chara[no]]]);
                nmfontFPrint(packet, str, 96.0f + (dx + diff) - (float)(nmfontGetPackStrLen(str, 0x10, 0) / 2), 16.0f + 2.0f * dy);
                nmfontFPrint(packet, mes[1], 96.0f + (dx + diff) - (float)(nmfontGetPackStrLen(mes[1], 0x10, 0) / 2), 32.0f + 2.0f * dy);
            } else {
                nmfontFPrint(packet, mes[2], 96.0f + (dx + diff) - (float)(nmfontGetPackStrLen(mes[2], 0x10, 0) / 2), 16.0f + 2.0f * dy);
                nmfontFPrint(packet, mes[3], 96.0f + (dx + diff) - (float)(nmfontGetPackStrLen(mes[3], 0x10, 0) / 2), 32.0f + 2.0f * dy);
            }
        }
    }
    if ((vayResData->board[no][vayResData->chara[no]] >= 6) && (brdflg == 0)) {
        nmfontFPrint(packet, "???", dx, 48.0f + 2.0f * dy);
    } else {
        nmfontFPrint(packet, vsptblBoardName[board][vayResData->board[no][vayResData->chara[no]]], dx, 48.0f + 2.0f * dy);
    }
}

static void ayDrawChCs(Packet* packet, float dx, float dy, signed int flg) {
    TexData texData[3]; // 0xA0(r29)
    QuadData data; // 0xD0(r29)
    float xy[4]; // 0x1B0(r29)
    char* mesList[3][4] = {{"NEED %d SPONSORS", "TO UNLOCK LEVEL", "UNLOCK IN", "CAREER MODE"}, {"%d SPONSOREN ZUM FREISCHALTEN", "DES LEVEL BEN\x92TIGT", "IM KARRIERE-MODUS", "FREISPIELEN"}, {"%d SPONSORS NECESSAIRES POUR", "DEVERROUILLER CE NIVEAU", "DEVERROUILLER EN", "MODE CARRIERE"}}; // 0x1C0(r29)
    char** mes = mesList[vspenvGame->language]; // r17 // s1
    char str[32]; // 0x1F0(r29)
    signed int soft[8] = {0, 4, 9, 0xF, 0x16, 0x1D, 0x25, 0x2E}; // 0x210(r29)
    signed int pno; // r30 // fp
    AlphaTag* alpha; // 0x238(r29)
    void* addr; // 0x23C(r29)
    signed int aflg; // 0x240(r29)
    signed int ii; // r16 // s0
    Poly* poly; // r19 // s3
    Data* loaddata; // r20 // s4
    signed int csflg; // r21 // s5
    signed int cs; // r22 // s6
    signed int polnum; // r23 // s7

    if (((vayResData->step == 7) || (vayResData->step == 0x13)) && flg) {
        aflg = 1;
    } else {
        aflg = 0;
    }
    loaddata = sploadGetGame2D();
    ultexResetTex(loaddata->result.offset);
    for (ii = 0; ii < 3; ii++) {
        texData[ii].tofs = texData[ii].cofs = -1;
    }
    cs = vayResData->cs;
    if (vayResData->resKind == 0) {
        pno = ayChangeCharID(vayResData->chara[0]);
        if (pno < 0xC) {
            csflg = vspenvSecret->character[pno].course;
        } else {
            csflg = vspenvSecret->create_character[pno - 0xC].character.course;
        }
        csflg = csflg & (1 << cs);
    } else {
        csflg = vspenvSecret->tour_round & (1 << cs);
    }
    ultexTransTexTag(packet, loaddata->result.utd, &texData[0], 0x28);
    ultexTransTexTag(packet, loaddata->result.utd, &texData[1], cs / 2 + 0x39);
    if (aflg) {
        polnum = 4;
        nmdispTransTex(packet);
    } else {
        polnum = 2;
    }
    if (csflg == 0) {
        polnum++;
        ultexTransTexTag(packet, loaddata->result.utd, &texData[2], 0x29);
        vayResData->decide[0] = vayResData->decide[1] = -1;
    }
    ayDrawBackBoard(packet, dx, dy, 0);
    addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x70 + 0x20) + 0xF) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    if (flg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    } else {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
    }
    data.psmt = 0x14;
    data.texdata = &texData[0];
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x20;
    xy[0] = dx, xy[1] = dy, xy[2] = 128.0f + dx, xy[3] = 16.0f + dy;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly, &data, 1);
    ayFontInit(0x10, 0x10, data.col[0]);
    nmfontFPrint(packet, (char*)vsptblCourseName[cs], dx, 48.0f + 2.0f * dy);
    data.texdata = &texData[1];
    if (csflg == 0) {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
    }
    data.uv[0] = 0, data.uv[1] = (cs % 2) << 6, data.uv[2] = 0x80, data.uv[3] = data.uv[1] + 0x40;
    xy[0] = 258.0f + dx, xy[1] = dy, xy[2] = 386.0f + dx, xy[3] = 32.0f + dy;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly + 1, &data, 1);
    if (aflg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        data.texdata = loaddata->game.tex + 1;
        for (ii = 0; ii < 2; ii++) {
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = ii * 32 + 0x20, data.uv[3] = 0x40;
            xy[0] = 218.0f + dx + 180.0f * (float)ii, xy[1] = 8.0f + dy, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(poly + (ii + 2), &data, 1);
        }
    }
    if (csflg == 0) {
        if (flg) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        } else {
            data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
        }
        data.texdata = &texData[2];
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;
        xy[0] = 290.0f + dx, xy[1] = dy, xy[2] = 354.0f + dx, xy[3] = 32.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (polnum - 1), &data, 1);
        if (vayResData->resKind == 0) {
            ulstdSprintf(str, mes[0], soft[vayResData->cs]);
            nmfontFPrint(packet, str, 322.0f + dx - (float)(nmfontGetPackStrLen(str, 0x10, 0) / 2), 16.0f + 2.0f * dy);
            nmfontFPrint(packet, mes[1], 322.0f + dx - (float)(nmfontGetPackStrLen(mes[1], 0x10, 0) / 2), 32.0f + 2.0f * dy);
        } else {
            nmfontFPrint(packet, mes[2], 322.0f + dx - (float)(nmfontGetPackStrLen(mes[2], 0x10, 0) / 2), 16.0f + 2.0f * dy);
            nmfontFPrint(packet, mes[3], 322.0f + dx - (float)(nmfontGetPackStrLen(mes[3], 0x10, 0) / 2), 32.0f + 2.0f * dy);
        }
    }
}

static void ayDrawChPlayer(Packet* packet, float dx, float dy, signed int flg, signed int no) {
    signed int id = 0; // r17 // s1
    TexData texData[3]; // 0xA0(r29)
    QuadData data; // 0xD0(r29)
    float xy[4]; // 0x1B0(r29)
    AlphaTag* alpha; // r30 // fp
    signed int vsflg; // 0x1D4(r29)
    float diff; // 0x1D8(r29)
    char* name; // 0x1DC(r29)
    char secret[4] = "???"; // 0x1E0(r29)
    char* demo[3] = {"UNAVAILABLE IN DEMO", "NICHT IN DEMO VERF\x94GBAR", "INDISPONIBLE EN DEMO"}; // 0x1C8(r29)
    signed int chrFlg; // 0x1E4(r29)
    signed int aflg; // 0x1E8(r29)
    signed int ii; // r16 // s0
    Data* loaddata; // r18 // s2
    Poly* poly; // r19 // s3
    signed int pno; // r21 // s5
    signed int polnum; // r22 // s6
    void* addr; // r23 // s7

    if (((vayResData->step == 7) || (vayResData->step == 0x13)) && flg) {
        aflg = 1;
    } else {
        aflg = 0;
    }
    loaddata = sploadGetGame2D();
    ultexResetTex(loaddata->result.offset);
    for (ii = 0; ii < 3; ii++) {
        texData[ii].tofs = texData[ii].cofs = -1;
    }
    if ((vayResData->resKind == 1) || (vayResData->resKind == 3)) {
        diff = 157.0f;
        vsflg = 1;
        polnum = 1;
        ultexTransTexTag(packet, loaddata->result.utd, &texData[2], 0x38);
    } else {
        diff = 290.0f;
        vsflg = 0;
        polnum = 0;
    }
    if (aflg) {
        polnum += 4;
        nmdispTransTex(packet);
    } else {
        polnum += 2;
    }
    pno = ayChangeCharID(vayResData->chara[no]);
    if (pno < 0xC) {
        ultexTransTexTag(packet, loaddata->result.utd, &texData[1], pno + 0x2A);
        name = vsptblCharacterName[pno];
        chrFlg = vspenvSecret->character[pno].secret;
    } else {
        ultexTransTexTag(packet, loaddata->result.utd, &texData[1], vspenvSecret->create_character[pno - 0xC].sex + 0x36);
        name = vspenvSecret->create_character[pno - 0xC].name;
        chrFlg = vspenvSecret->create_character[pno - 0xC].character.secret;
    }
    if (no == 1) {
        polnum--;
    } else {
        ultexTransTexTag(packet, loaddata->result.utd, &texData[0], 0x27);
    }
    ayDrawBackBoard(packet, dx, dy, vsflg);
    addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x70 + 0x20) + 0xF) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.psmt = 0x14;
    if (vsflg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        data.texdata = &texData[2];
        data.uv[0] = 0, data.uv[1] = no << 5, data.uv[2] = 0x80, data.uv[3] = data.uv[1] + 0x20;
        xy[0] = 150.0f + dx, xy[1] = dy - 14.0f, xy[2] = 278.0f + dx, xy[3] = 2.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly, &data, 1);
        id++;
    }
    if (flg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    } else {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
    }
    if (no == 0) {
        data.texdata = &texData[0];
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x20;
        xy[0] = dx, xy[1] = dy, xy[2] = 128.0f + dx, xy[3] = 16.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + id, &data, 1);
        id++;
    }
    data.texdata = &texData[1];
    if (chrFlg == 0) {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
    }
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;
    xy[0] = dx + diff, xy[1] = dy, xy[2] = 64.0f + xy[0], xy[3] = 32.0f + dy;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly + id, &data, 1);
    id++;
    if (flg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
    } else {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
    }
    if (aflg) {
        data.texdata = loaddata->game.tex + 1;
        for (ii = 0; ii < 2; ii++) {
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = ii * 32 + 0x20, data.uv[3] = 0x40;
            xy[0] = 112.0f * (float)ii + (dx + diff - 40.0f), xy[1] = 8.0f + dy, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(poly + (ii + id), &data, 1);
        }
    }
    if (chrFlg == 0) {
        vayResData->decide[no] = -1;
        texData[0].tofs = texData[0].cofs = -1;
        ultexTransTexTag(packet, loaddata->result.utd, &texData[0], 0x29);
        addr = ulgifAddCNTReserve(packet, 9);
        alpha = ((AlphaTag*)addr)++;
        ulpktInitALPHA(alpha, 1);
        poly = addr;
        data.psmt = 0x14;
        data.texdata = &texData[0];
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;
        xy[0] = dx + diff, xy[1] = dy, xy[2] = 64.0f + xy[0], xy[3] = 32.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly, &data, 1);
        ayFontInit(0x10, 0x10, data.col[0]);
        nmfontFPrint(packet, demo[vspenvGame->language], 32.0f + (dx + diff) - (float)(nmfontGetPackStrLen(demo[vspenvGame->language], 0x10, 0) / 2), 24.0f + 2.0f * dy);
    }
    ayFontInit(0x10, 0x10, data.col[0]);
    nmfontFPrint(packet, name, dx, 48.0f + 2.0f * dy);
}

static void ayDrawChHandi(Packet* packet, float dx, float dy, signed int flg, signed int no) {
    Poly* poly; // 0x20C(r29)
    AlphaTag* alpha; // 0x210(r29)
    signed int id = 0; // 0x214(r29)
    TexData texData; // 0xA0(r29)
    QuadData data; // 0xB0(r29)
    float xy[4]; // 0x190(r29)
    signed int col[2][4]; // 0x1A0(r29)
    char str[32]; // 0x1C0(r29)
    char* handiList[3][3] = {{"-%d", "NO CHANGE", "+%d"}, {"-%d", "KEINE \x90NDERUNG", "+%d"}, {"-%d", "AUCUN CHANGEMENT", "+%d"}}; // 0x1E0(r29)
    signed int ii; // r16 // s0
    Poly2* poly2; // r19 // s3
    char** handi = handiList[vspenvGame->language]; // r20 // s4
    void* addr; // r21 // s5
    Data* loaddata; // r22 // s6
    signed int polnum; // r23 // s7

    loaddata = sploadGetGame2D();
    ultexResetTex(loaddata->result.offset);
    texData.tofs = texData.cofs = -1;
    if (no == 1) {
        polnum = 0;
    } else {
        polnum = 1;
        ultexTransTexTag(packet, loaddata->result.utd, &texData, 0x28);
    }
    ayDrawBackBoard(packet, dx, dy, 1);
    addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x70 + 0x2A0) + 0xF) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    if (no == 0) {
        poly = ((Poly*)addr)++;
        if (flg) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        } else {
            data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
        }
        data.psmt = 0x14;
        data.texdata = &texData;
        data.uv[0] = 0, data.uv[1] = 0x20, data.uv[2] = 0x80, data.uv[3] = 0x40;
        xy[0] = dx, xy[1] = dy, xy[2] = 128.0f + dx, xy[3] = 16.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly, &data, 1);
    }
    poly2 = addr;
    if (vayResData->handi[no] < 5) {
        col[0][0] = 0x98, col[0][1] = 0xDE, col[0][2] = 0xFF, col[0][3] = 0x80;
    } else if (vayResData->handi[no] == 5) {
        col[0][0] = 0xFF, col[0][1] = 0xDD, col[0][2] = 0x95, col[0][3] = 0x80;
    } else {
        col[0][0] = 0xFF, col[0][1] = 0x83, col[0][2] = 0x2E, col[0][3] = 0x80;
    }
    if (flg) {
        col[1][0] = 0x80, col[1][1] = 0x80, col[1][2] = 0x80, col[1][3] = 0x80;
    } else {
        col[1][0] = 0x40, col[1][1] = 0x40, col[1][2] = 0x40, col[1][3] = 0x80;
        col[0][0] /= 2;
        col[0][1] /= 2;
        col[0][2] /= 2;
    }
    for (ii = 0; ii < 10; ii++) {
        xy[0] = 8.0f * (float)(ii / 5) + (40.0f + dx + 18.0f * (float)ii), xy[1] = 16.0f + dy, xy[2] = 14.0f + xy[0], xy[3] = 7.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        if (ii < vayResData->handi[no]) {
            data.col[0][0] = col[0][0], data.col[0][1] = col[0][1], data.col[0][2] = col[0][2], data.col[0][3] = col[0][3];
        } else {
            data.col[0][0] = col[1][0], data.col[0][1] = col[1][1], data.col[0][2] = col[1][2], data.col[0][3] = col[1][3];
        }
        aySetPolyComF4(poly2 + ii, &data);
    }
    if (vayResData->handi[no] < 5) {
        ulstdSprintf(str, handi[0], 5 - vayResData->handi[no]);
    } else if (vayResData->handi[no] == 5) {
        ulstdSprintf(str, handi[1]);
    } else {
        ulstdSprintf(str, handi[2], vayResData->handi[no] - 5);
    }
    ayFontInit(0x10, 0x10, col[1]);
    nmfontFPrint(packet, str, 134.0f + dx - (float)(nmfontGetPackStrLen(str, 0x10, 0) / 2), 48.0f + 2.0f * dy);
}

static void ayDrawChRule(Packet* packet, float dx, float dy, signed int flg, signed int kind) {
    TexData texData[2]; // 0xA0(r29)
    QuadData data; // 0xC0(r29)
    float xy[4]; // 0x1A0(r29)
    signed int col[4]; // 0x1B0(r29)
    char* ruleList[3][6] = {{"FREESTYLE", "PALMER X", "PUSH", "HORSE", "VERTICAL", "HORIZONTAL"}, {"FREESTYLE", "PALMER X", "PUSH", "LOSER", "VERTICAL", "HORIZONTAL"}, {"FREESTYLE", "PALMER X", "DUEL", "PENDU", "VERTICAL", "HORIZONTAL"}}; // 0x1C0(r29)
    AlphaTag* alpha; // 0x214(r29)
    signed int ii; // r16 // s0
    Poly* poly; // r18 // s2
    Data* loaddata; // r19 // s3
    char** rule = ruleList[vspenvGame->language]; // r20 // s4
    signed int id; // r21 // s5
    signed int polnum; // r22 // s6
    signed int aflg; // r23 // s7
    void* addr; // r30 // fp

    if (((vayResData->step == 7) || (vayResData->step == 0x13)) && flg) {
        aflg = 1;
    } else {
        aflg = 0;
    }
    loaddata = sploadGetGame2D();
    ultexResetTex(loaddata->result.offset);
    for (ii = 0; ii < 2; ii++) {
        texData[ii].tofs = texData[ii].cofs = -1;
    }
    ultexTransTexTag(packet, loaddata->result.utd, &texData[0], kind + 0x27);
    ultexTransTexTag(packet, loaddata->result.utd, &texData[1], 0x29);
    ayDrawBackBoard(packet, dx, dy, 0);
    if (aflg) {
        polnum = 3;
    } else {
        polnum = 1;
    }
    if ((kind == 1) && (vayResData->rule >= 2)) {
        polnum++;
    }
    addr = ulgifAddCNTReserve(packet, ((signed int)(polnum * 0x70 + 0x20) + 0xF) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    if (flg) {
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        col[0] = 0x80, col[1] = 0x80, col[2] = 0x80, col[3] = 0x80;
    } else {
        data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = 0x80;
        col[0] = 0x40, col[1] = 0x40, col[2] = 0x40, col[3] = 0x80;
    }
    data.psmt = 0x14;
    data.texdata = &texData[0];
    data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x80, data.uv[3] = 0x60;
    xy[0] = dx, xy[1] = dy, xy[2] = 128.0f + dx, xy[3] = 16.0f + dy;
    aySetVert(data.vert[0], xy, 0xFFFFFF);
    aySetPolyComFT4(poly, &data, 1);
    id = 1;
    if (aflg) {
        nmdispTransTex(packet);
        data.texdata = loaddata->game.tex + 1;
        for (ii = 0; ii < 2; ii++) {
            data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = ii * 32 + 0x20, data.uv[3] = 0x40;
            xy[0] = 203.0f + dx + 200.0f * (float)ii, xy[1] = 16.0f + dy, xy[2] = 32.0f + xy[0], xy[3] = 16.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            aySetPolyComFT4(poly + (id + ii), &data, 1);
        }
    }
    ayFontInit(0x10, 0x10, col);
    if (kind == 0) {
        nmfontFPrint(packet, rule[vayResData->rule], 320.0f + (dx - (float)(nmfontGetPackStrLen(rule[vayResData->rule], 0x10, 0) / 2)), 40.0f + 2.0f * dy);
    } else if (vayResData->rule < 2) {
        nmfontFPrint(packet, rule[vspenvOption->divide + 4], 320.0f + (dx - (float)(nmfontGetPackStrLen(rule[vspenvOption->divide + 4], 0x10, 0) / 2)), 40.0f + 2.0f * dy);
    } else {
        data.texdata = &texData[1];
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x40, data.uv[3] = 0x40;
        xy[0] = 290.0f + dx, xy[1] = dy, xy[2] = 354.0f + dx, xy[3] = 32.0f + dy;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + (polnum - 1), &data, 1);
    }
}

static void ayDrawBackBoard(Packet* packet, float dx, float dy, signed int flg) {
    void* addr; // r16 // s0
    PolyG* polyg; // r17 // s1
    Poly2* poly2; // r18 // s2
    AlphaTag* alpha; // r19 // s3
    QuadData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)

    addr = ulgifAddCNTReserve(packet, 0x12);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly2 = ((Poly2*)addr)++;
    data.col[0][0] = 0xFF, data.col[0][1] = 0xFF, data.col[0][2] = 0xFF, data.col[0][3] = 0x20;
    if (flg) {
        xy[0] = 46.0f + dx, xy[1] = dy, xy[2] = 222.0f + dx, xy[3] = 32.0f + dy;
    } else {
        xy[0] = 90.0f + dx, xy[1] = dy, xy[2] = 394.0f + dx, xy[3] = 32.0f + dy;
    }
    aySetVert(data.vert[0], xy, 1);
    aySetPolyComF4(poly2, &data);
    polyg = addr;
    data.col[0][0] = 0xFF, data.col[0][1] = 0xFF, data.col[0][2] = 0xFF, data.col[0][3] = 0;
    data.col[1][0] = 0xFF, data.col[1][1] = 0xFF, data.col[1][2] = 0xFF, data.col[1][3] = 0x20;
    data.col[2][0] = 0xFF, data.col[2][1] = 0xFF, data.col[2][2] = 0xFF, data.col[2][3] = 0;
    data.col[3][0] = 0xFF, data.col[3][1] = 0xFF, data.col[3][2] = 0xFF, data.col[3][3] = 0x20;
    if (flg) {
        xy[0] = dx, xy[1] = dy, xy[2] = 46.0f + dx, xy[3] = 32.0f + dy;
    } else {
        xy[0] = dx, xy[1] = dy, xy[2] = 90.0f + dx, xy[3] = 32.0f + dy;
    }
    aySetVert(data.vert[0], xy, 1);
    aySetPolyComG4(polyg, &data);
    data.col[0][0] = 0xFF, data.col[0][1] = 0xFF, data.col[0][2] = 0xFF, data.col[0][3] = 0x20;
    data.col[1][0] = 0xFF, data.col[1][1] = 0xFF, data.col[1][2] = 0xFF, data.col[1][3] = 0;
    data.col[2][0] = 0xFF, data.col[2][1] = 0xFF, data.col[2][2] = 0xFF, data.col[2][3] = 0x20;
    data.col[3][0] = 0xFF, data.col[3][1] = 0xFF, data.col[3][2] = 0xFF, data.col[3][3] = 0;
    if (flg) {
        xy[0] = 222.0f + dx, xy[1] = dy, xy[2] = 268.0f + dx, xy[3] = 32.0f + dy;
    } else {
        xy[0] = 394.0f + dx, xy[1] = dy, xy[2] = 484.0f + dx, xy[3] = 32.0f + dy;
    }
    aySetVert(data.vert[0], xy, 1);
    aySetPolyComG4(polyg + 1, &data);
}

static signed int ayChangeCharID(signed int no) {
    signed int ii; // r16 // s0
    signed int tmp; // r17 // s1

    if (no < 0xA) {
        return no;
    }
    for (ii = 0, tmp = 9; ii < 10; ii++) {
        if (vspenvSecret->create_character[ii].character.secret == 1) {
            tmp++;
            if (tmp == no) {
                return ii + 0xC;
            }
        }
    }
    return no - tmp + 9;
}

static signed int ayDrawEnding(Packet* packet) {
    VaytblEnding name[655]; // 0x20(r29)
    signed int ret; // r16 // s0

    memcpy(&name[0], vaytblEnding, 0x120);
    memcpy(&name[3], vaytblCredit, 0xF480);
    ret = ayDrawCredits(packet, name, &vayResData->scrY, 0x28F);
    return ret;
}

