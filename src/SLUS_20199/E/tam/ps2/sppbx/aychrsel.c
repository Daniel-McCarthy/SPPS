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
#pragma fast_fptosi on
#pragma dont_inline on

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));


// Static data ///////////////////////////////////////////////////////////////////////

// aychrsel.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x1057D6
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0, DWARF: 0x1057F5
    unsigned char mark; // Offset: 0x2, DWARF: 0x105815
    unsigned char id; // Offset: 0x3, DWARF: 0x105836
    struct _sceDmaTag* next; // Offset: 0x4, DWARF: 0x105855
    unsigned int p[2]; // Offset: 0x8, DWARF: 0x10587B
} _sceDmaTag;

// Size: 0x90, DWARF: 0x105AB2
typedef struct tag_ulcodCOORDINATE
{
    struct tag_ulcodCOORDINATE* super; // Offset: 0x0, DWARF: 0x105ADA
    unsigned int flag; // Offset: 0x4, DWARF: 0x105B01
    unsigned int id; // Offset: 0x8, DWARF: 0x105B22
    signed int parent; // Offset: 0xC, DWARF: 0x105B41
    float mat[4][4]; // Offset: 0x10, DWARF: 0x105B64
    float tmp[4][4]; // Offset: 0x50, DWARF: 0x105B86
} tag_ulcodCOORDINATE;

// Size: 0x1C, DWARF: 0x108227
typedef struct CharacterParameters
{
    signed int ollie; // Offset: 0x0, DWARF: 0x108243
    signed int spin; // Offset: 0x4, DWARF: 0x108265
    signed int speed; // Offset: 0x8, DWARF: 0x108286
    signed int landing; // Offset: 0xC, DWARF: 0x1082A8
    signed int balance; // Offset: 0x10, DWARF: 0x1082CC
    signed int stability; // Offset: 0x14, DWARF: 0x1082F0
    signed int stance; // Offset: 0x18, DWARF: 0x108316
} CharacterParameters;

// Size: 0x74, DWARF: 0x1088AE
typedef struct Character
{
    signed int secret; // Offset: 0x0, DWARF: 0x1088CA
    unsigned int board; // Offset: 0x4, DWARF: 0x1088ED
    unsigned int course; // Offset: 0x8, DWARF: 0x10890F
    signed int rem_point; // Offset: 0xC, DWARF: 0x108932
    signed int old_brd_no; // Offset: 0x10, DWARF: 0x108958
    signed int old_wear_no; // Offset: 0x14, DWARF: 0x10897F
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x1089A7
    signed int soft[8]; // Offset: 0x38, DWARF: 0x1089D0
    // Size: 0x1C, DWARF: 0x108227
    CharacterParameters parameter; // Offset: 0x58, DWARF: 0x1089F3
} Character;

// Size: 0x18, DWARF: 0x10AFD9
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0x10AFF5
    signed int month; // Offset: 0x4, DWARF: 0x10B016
    signed int day; // Offset: 0x8, DWARF: 0x10B038
    signed int hour; // Offset: 0xC, DWARF: 0x10B058
    signed int minute; // Offset: 0x10, DWARF: 0x10B079
    signed int second; // Offset: 0x14, DWARF: 0x10B09C
} Clock;

// Size: 0xEC, DWARF: 0x109837
typedef struct CreatedCharacter
{
    // Size: 0x74, DWARF: 0x1088AE
    Character character; // Offset: 0x0, DWARF: 0x109853
    // Size: 0x1C, DWARF: 0x108227
    CharacterParameters init_param; // Offset: 0x74, DWARF: 0x10987B
    // Size: 0x18, DWARF: 0x10AFD9
    Clock clock; // Offset: 0x90, DWARF: 0x1098A4
    char name[16]; // Offset: 0xA8, DWARF: 0x1098C8
    signed int age; // Offset: 0xB8, DWARF: 0x1098EB
    signed int sex; // Offset: 0xBC, DWARF: 0x10990B
    signed int face; // Offset: 0xC0, DWARF: 0x10992B
    signed int hair; // Offset: 0xC4, DWARF: 0x10994C
    signed int hair_color; // Offset: 0xC8, DWARF: 0x10996D
    signed int body; // Offset: 0xCC, DWARF: 0x109994
    signed int body_color; // Offset: 0xD0, DWARF: 0x1099B5
    signed int pants; // Offset: 0xD4, DWARF: 0x1099DC
    signed int pants_color; // Offset: 0xD8, DWARF: 0x1099FE
    signed int glove; // Offset: 0xDC, DWARF: 0x109A26
    signed int boots; // Offset: 0xE0, DWARF: 0x109A48
    signed int board_type; // Offset: 0xE4, DWARF: 0x109A6A
    signed int trick_type; // Offset: 0xE8, DWARF: 0x109A91
} CreatedCharacter;

// Size: 0x8, DWARF: 0x10ACB1
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0, DWARF: 0x10ACCD
} CourseGap;

// Size: 0xEF8, DWARF: 0x10A075
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0x1088AE
    Character character[12]; // Offset: 0x0, DWARF: 0x10A091
    // Size: 0xEC, DWARF: 0x109837
    CreatedCharacter create_character[10]; // Offset: 0x570, DWARF: 0x10A0B9
    // Size: 0x8, DWARF: 0x10ACB1
    CourseGap course[8]; // Offset: 0xEA8, DWARF: 0x10A0E8
    signed int tour_round; // Offset: 0xEE8, DWARF: 0x10A10D
    signed int old_char; // Offset: 0xEEC, DWARF: 0x10A134
    signed int first_clear; // Offset: 0xEF0, DWARF: 0x10A159
} VspenvSecret;

// Size: 0x4, DWARF: 0x10A012
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0x10A02E
} CourseNo;

// Size: 0x10, DWARF: 0x108AB4
typedef struct BoardParameters
{
    signed int speed; // Offset: 0x0, DWARF: 0x108AD0
    signed int stability; // Offset: 0x4, DWARF: 0x108AF2
    signed int balance; // Offset: 0x8, DWARF: 0x108B18
    signed int turning; // Offset: 0xC, DWARF: 0x108B3C
} BoardParameters;

// Size: 0x3C, DWARF: 0x1094FF
typedef struct CharacterState
{
    signed int no; // Offset: 0x0, DWARF: 0x10951B
    signed int player; // Offset: 0x4, DWARF: 0x10953A
    signed int wear; // Offset: 0x8, DWARF: 0x10955D
    signed int board; // Offset: 0xC, DWARF: 0x10957E
    // Size: 0x1C, DWARF: 0x108227
    CharacterParameters chr_param; // Offset: 0x10, DWARF: 0x1095A0
    // Size: 0x10, DWARF: 0x108AB4
    BoardParameters brd_param; // Offset: 0x2C, DWARF: 0x1095C8
} CharacterState;

// Size: 0x18, DWARF: 0x10A23E
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x10A25A
    signed int game_mode; // Offset: 0x4, DWARF: 0x10A281
    signed int match_rule; // Offset: 0x8, DWARF: 0x10A2A7
    signed int divide; // Offset: 0xC, DWARF: 0x10A2CE
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x10A2F1
} Mode;

// Size: 0xA0, DWARF: 0x1086FA
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x10A012
    CourseNo course; // Offset: 0x0, DWARF: 0x108716
    // Size: 0x3C, DWARF: 0x1094FF
    CharacterState character[2]; // Offset: 0x4, DWARF: 0x10873B
    // Size: 0x18, DWARF: 0x10A23E
    Mode mode; // Offset: 0x7C, DWARF: 0x108763
    signed int language; // Offset: 0x94, DWARF: 0x108786
    signed int ending; // Offset: 0x98, DWARF: 0x1087AB
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x1087CE
} VspenvGame;

// Size: 0x10, DWARF: 0x107DFE
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x107E1A
    __int128* pBase; // Offset: 0x4, DWARF: 0x107E42
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x107E67
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0x107E8E
} VgmsysGifPkt;

// Size: 0x38, DWARF: 0x10341E
typedef struct File
{
    // Size: 0x18, DWARF: 0x10AFD9
    Clock clock; // Offset: 0x0, DWARF: 0x10343A
    char name[32]; // Offset: 0x18, DWARF: 0x10345E
} File;

// Size: 0x20, DWARF: 0x1025A7
typedef struct Record
{
    signed int chr_no; // Offset: 0x0, DWARF: 0x1025C2
    unsigned long score; // Offset: 0x8, DWARF: 0x1025E5
    char name[16]; // Offset: 0x10, DWARF: 0x102607
} Record;

// Size: 0x4, DWARF: 0x103A62
typedef struct BestTime
{
    unsigned int time; // Offset: 0x0, DWARF: 0x103A7E
} BestTime;

// Size: 0x24, DWARF: 0x103E0B
typedef struct KeyConfig
{
    signed int vibration; // Offset: 0x0, DWARF: 0x103E27
    signed int spin_l; // Offset: 0x4, DWARF: 0x103E4D
    signed int spin_r; // Offset: 0x8, DWARF: 0x103E70
    signed int stance; // Offset: 0xC, DWARF: 0x103E93
    signed int revert; // Offset: 0x10, DWARF: 0x103EB6
    signed int grind; // Offset: 0x14, DWARF: 0x103ED9
    signed int grab; // Offset: 0x18, DWARF: 0x103EFB
    signed int jump; // Offset: 0x1C, DWARF: 0x103F1C
    signed int flip; // Offset: 0x20, DWARF: 0x103F3D
} KeyConfig;

// Size: 0x30, DWARF: 0x106383
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x10639F
    signed int always_sp; // Offset: 0x4, DWARF: 0x1063C0
    signed int perfect_b; // Offset: 0x8, DWARF: 0x1063E6
    signed int super_spin; // Offset: 0xC, DWARF: 0x10640C
    signed int half_g; // Offset: 0x10, DWARF: 0x106433
    signed int fast_motion; // Offset: 0x14, DWARF: 0x106456
    signed int super_speed; // Offset: 0x18, DWARF: 0x10647E
    signed int big_head; // Offset: 0x1C, DWARF: 0x1064A6
    signed int metallic; // Offset: 0x20, DWARF: 0x1064CB
    signed int mirror; // Offset: 0x24, DWARF: 0x1064F0
    signed int replay_view; // Offset: 0x28, DWARF: 0x106513
    signed int partition; // Offset: 0x2C, DWARF: 0x10653B
} Cheats;

// Size: 0x8, DWARF: 0x105D2B
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0x105D47
    signed int bgm; // Offset: 0x4, DWARF: 0x105D66
} Volume;

// Size: 0x48, DWARF: 0x1077F6
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0x107812
    signed int disable; // Offset: 0x40, DWARF: 0x107836
    signed int random; // Offset: 0x44, DWARF: 0x10785A
} Bgm;

// Size: 0x114, DWARF: 0x107EDD
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0x103E0B
    KeyConfig key_config[2]; // Offset: 0x0, DWARF: 0x107EF9
    // Size: 0x30, DWARF: 0x106383
    Cheats enable; // Offset: 0x48, DWARF: 0x107F22
    // Size: 0x30, DWARF: 0x106383
    Cheats cheats; // Offset: 0x78, DWARF: 0x107F47
    // Size: 0x8, DWARF: 0x105D2B
    Volume volume; // Offset: 0xA8, DWARF: 0x107F6C
    char name[16]; // Offset: 0xB0, DWARF: 0x107F91
    signed int divide; // Offset: 0xC0, DWARF: 0x107FB4
    signed int tutorial; // Offset: 0xC4, DWARF: 0x107FD7
    // Size: 0x48, DWARF: 0x1077F6
    Bgm bgm; // Offset: 0xC8, DWARF: 0x107FFC
    unsigned int movie; // Offset: 0x110, DWARF: 0x10801E
} VspenvOption;

// Size: 0x1668, DWARF: 0x103D0B
typedef struct MemCard
{
    // Size: 0x38, DWARF: 0x10341E
    File file; // Offset: 0x0, DWARF: 0x103D27
    // Size: 0x20, DWARF: 0x1025A7
    Record record[8][6]; // Offset: 0x38, DWARF: 0x103D4A
    // Size: 0x4, DWARF: 0x103A62
    BestTime best_time[8]; // Offset: 0x638, DWARF: 0x103D6F
    // Size: 0x114, DWARF: 0x107EDD
    VspenvOption option; // Offset: 0x658, DWARF: 0x103D97
    // Size: 0xEF8, DWARF: 0x10A075
    VspenvSecret secret; // Offset: 0x770, DWARF: 0x103DBC
} MemCard;

// Size: 0x1690, DWARF: 0x1034A9
typedef struct VaySelData
{
    signed int count; // Offset: 0x0, DWARF: 0x1034C5
    signed int bocount; // Offset: 0x4, DWARF: 0x1034E7
    signed int step; // Offset: 0x8, DWARF: 0x10350B
    signed int nextMode; // Offset: 0xC, DWARF: 0x10352C
    signed int mode; // Offset: 0x10, DWARF: 0x103551
    // Size: 0x1668, DWARF: 0x103D0B
    MemCard mc; // Offset: 0x18, DWARF: 0x103572
    signed int bgmdiff; // Offset: 0x1680, DWARF: 0x103593
    signed int bgm; // Offset: 0x1684, DWARF: 0x1035B7
    signed int vcID; // Offset: 0x1688, DWARF: 0x1035D7
    signed int vcTO; // Offset: 0x168C, DWARF: 0x1035F8
} VaySelData;

// Size: 0x10, DWARF: 0x1028EC
typedef struct Tex
{
    signed short tofs; // Offset: 0x0, DWARF: 0x102907
    signed short cofs; // Offset: 0x2, DWARF: 0x102928
    signed short width; // Offset: 0x4, DWARF: 0x102949
    signed short height; // Offset: 0x6, DWARF: 0x10296B
    signed short tw; // Offset: 0x8, DWARF: 0x10298E
    signed short th; // Offset: 0xA, DWARF: 0x1029AD
    signed short image_bit; // Offset: 0xC, DWARF: 0x1029CC
    signed short clut_bit; // Offset: 0xE, DWARF: 0x1029F2
} Tex;

// Size: 0x8, DWARF: 0x104D00
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x104D1C
    signed char lh; // Offset: 0x2, DWARF: 0x104D3C
    signed char lv; // Offset: 0x3, DWARF: 0x104D5B
    signed int analog; // Offset: 0x4, DWARF: 0x104D7A
} PadData;

// Size: 0x2DCEC, DWARF: 0x105F3F
typedef struct Replay
{
    // Size: 0x38, DWARF: 0x10341E
    File file; // Offset: 0x0, DWARF: 0x105F5B
    signed int pid; // Offset: 0x38, DWARF: 0x105F7E
    signed int num_frame; // Offset: 0x3C, DWARF: 0x105F9E
    unsigned int game_time; // Offset: 0x40, DWARF: 0x105FC4
    signed int endrun_frame; // Offset: 0x44, DWARF: 0x105FEA
    // Size: 0x8, DWARF: 0x104D00
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0x106013
    // Size: 0x24, DWARF: 0x103E0B
    KeyConfig key; // Offset: 0x2DB88, DWARF: 0x10603A
    // Size: 0xEC, DWARF: 0x109837
    CreatedCharacter character; // Offset: 0x2DBAC, DWARF: 0x10605C
    // Size: 0x30, DWARF: 0x106383
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0x106084
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0x1060A9
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0x1060CC
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0x1060EF
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0x106113
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0x106136
    // Size: 0x10, DWARF: 0x108AB4
    BoardParameters brd_param; // Offset: 0x2DCDC, DWARF: 0x10615C
} Replay;

// Size: 0x5D0E0, DWARF: 0x107546
typedef struct VspenvEnv
{
    // Size: 0xA0, DWARF: 0x1086FA
    VspenvGame game; // Offset: 0x0, DWARF: 0x107562
    // Size: 0x1668, DWARF: 0x103D0B
    MemCard mc; // Offset: 0xA0, DWARF: 0x107585
    // Size: 0x2DCEC, DWARF: 0x105F3F
    Replay replay[2]; // Offset: 0x1708, DWARF: 0x1075A6
} VspenvEnv;

// Size: 0x190, DWARF: 0x10791B
typedef struct VayChrData
{
    signed int count; // Offset: 0x0, DWARF: 0x107937
    signed int step; // Offset: 0x4, DWARF: 0x107959
    signed int loadFlg; // Offset: 0x8, DWARF: 0x10797A
    signed int padCnt; // Offset: 0xC, DWARF: 0x10799E
    signed int charMove; // Offset: 0x10, DWARF: 0x1079C1
    signed int chara; // Offset: 0x14, DWARF: 0x1079E6
    signed int charType; // Offset: 0x18, DWARF: 0x107A08
    signed int soft; // Offset: 0x1C, DWARF: 0x107A2D
    signed int wear[22]; // Offset: 0x20, DWARF: 0x107A4E
    signed int board[22]; // Offset: 0x78, DWARF: 0x107A71
    signed int boardMax[22]; // Offset: 0xD0, DWARF: 0x107A95
    signed int course; // Offset: 0x128, DWARF: 0x107ABC
    signed int select; // Offset: 0x12C, DWARF: 0x107ADF
    signed int moveCnt; // Offset: 0x130, DWARF: 0x107B02
    signed int nextSelect; // Offset: 0x134, DWARF: 0x107B26
    signed int moveDir; // Offset: 0x138, DWARF: 0x107B4D
    signed int handicap[2]; // Offset: 0x13C, DWARF: 0x107B71
    signed int capAccept[2]; // Offset: 0x144, DWARF: 0x107B98
    signed int player; // Offset: 0x14C, DWARF: 0x107BC0
    signed int csFlg; // Offset: 0x150, DWARF: 0x107BE3
    signed int csCnt; // Offset: 0x154, DWARF: 0x107C05
    signed int csiENo; // Offset: 0x158, DWARF: 0x107C27
    signed int csiNo; // Offset: 0x15C, DWARF: 0x107C4A
    signed int spID; // Offset: 0x160, DWARF: 0x107C6C
    float motFrame; // Offset: 0x164, DWARF: 0x107C8D
    signed int nowMot; // Offset: 0x168, DWARF: 0x107CB2
    signed int motFlg; // Offset: 0x16C, DWARF: 0x107CD5
    signed int rollCnt; // Offset: 0x170, DWARF: 0x107CF8
    signed int boCnt; // Offset: 0x174, DWARF: 0x107D1C
    signed int charaFlg; // Offset: 0x178, DWARF: 0x107D3E
    signed int boardFlg; // Offset: 0x17C, DWARF: 0x107D63
    // Size: 0x10, DWARF: 0x1028EC
    Tex mapTex; // Offset: 0x180, DWARF: 0x107D88
} VayChrData;

// Size: 0x20, DWARF: 0x10550E
typedef struct PadStatus
{
    signed int id; // Offset: 0x0, DWARF: 0x10552A
    unsigned int now; // Offset: 0x4, DWARF: 0x105549
    unsigned int status; // Offset: 0x8, DWARF: 0x105569
    unsigned int press; // Offset: 0xC, DWARF: 0x10558C
    signed char right_h; // Offset: 0x10, DWARF: 0x1055AE
    signed char right_v; // Offset: 0x11, DWARF: 0x1055D2
    signed char left_h; // Offset: 0x12, DWARF: 0x1055F6
    signed char left_v; // Offset: 0x13, DWARF: 0x105619
    unsigned char l_right; // Offset: 0x14, DWARF: 0x10563C
    unsigned char l_left; // Offset: 0x15, DWARF: 0x105660
    unsigned char l_up; // Offset: 0x16, DWARF: 0x105683
    unsigned char l_down; // Offset: 0x17, DWARF: 0x1056A4
    unsigned char r_up; // Offset: 0x18, DWARF: 0x1056C7
    unsigned char r_right; // Offset: 0x19, DWARF: 0x1056E8
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x10570C
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x10572F
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x105752
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x105772
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x105792
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x1057B2
} PadStatus;

// Size: 0x60, DWARF: 0x107667
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0x10550E
    PadStatus now; // Offset: 0x0, DWARF: 0x107683
    // Size: 0x20, DWARF: 0x10550E
    PadStatus old; // Offset: 0x20, DWARF: 0x1076A5
    unsigned int port; // Offset: 0x40, DWARF: 0x1076C7
    unsigned int slot; // Offset: 0x44, DWARF: 0x1076E8
    unsigned int mode; // Offset: 0x48, DWARF: 0x107709
    unsigned int trg; // Offset: 0x4C, DWARF: 0x10772A
    unsigned int rev; // Offset: 0x50, DWARF: 0x10774A
    unsigned int cnt; // Offset: 0x54, DWARF: 0x10776A
    unsigned int rep; // Offset: 0x58, DWARF: 0x10778A
    signed int state; // Offset: 0x5C, DWARF: 0x1077AA
} VgmsysPad;

// Size: 0x10, DWARF: 0x104A4E
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x104A6A
    unsigned int addr; // Offset: 0x4, DWARF: 0x104A8D
    unsigned int z; // Offset: 0x8, DWARF: 0x104AAE
    unsigned int _pad; // Offset: 0xC, DWARF: 0x104ACC
} ATag;

// Size: 0x20, DWARF: 0x10594A
typedef struct VgmsysAbuf
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0x105966
    unsigned int natag; // Offset: 0x4, DWARF: 0x10598A
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0x1059AC
    unsigned int npkt; // Offset: 0xC, DWARF: 0x1059CF
    // Size: 0x10, DWARF: 0x104A4E
    ATag* atag; // Offset: 0x10, DWARF: 0x1059F0
    // Size: 0x10, DWARF: 0x104A4E
    ATag* curatag; // Offset: 0x14, DWARF: 0x105A16
    __int128* pkt; // Offset: 0x18, DWARF: 0x105A3F
    __int128* curpkt; // Offset: 0x1C, DWARF: 0x105A62
} VgmsysAbuf;

// Size: 0x4, DWARF: 0x109D7F
typedef struct Chcr
{
    unsigned int DIR : 1; // Offset: 0x0, DWARF: 0x109D9B, Bit Offset: 0, Bit Size: 1
    unsigned int p0 : 1; // Offset: 0x0, DWARF: 0x109DC5, Bit Offset: 1, Bit Size: 1
    unsigned int MOD : 2; // Offset: 0x0, DWARF: 0x109DEE, Bit Offset: 2, Bit Size: 2
    unsigned int ASP : 2; // Offset: 0x0, DWARF: 0x109E18, Bit Offset: 4, Bit Size: 2
    unsigned int TTE : 1; // Offset: 0x0, DWARF: 0x109E42, Bit Offset: 6, Bit Size: 1
    unsigned int TIE : 1; // Offset: 0x0, DWARF: 0x109E6C, Bit Offset: 7, Bit Size: 1
    unsigned int STR : 1; // Offset: 0x0, DWARF: 0x109E96, Bit Offset: 8, Bit Size: 1
    unsigned int p1 : 7; // Offset: 0x0, DWARF: 0x109EC0, Bit Offset: 9, Bit Size: 7
    unsigned int TAG : 16; // Offset: 0x0, DWARF: 0x109EE9, Bit Offset: 16, Bit Size: 16
} Chcr;

// Size: 0x90, DWARF: 0x104434
typedef struct Dma
{
    // Size: 0x4, DWARF: 0x109D7F
    Chcr chcr; // Offset: 0x0, DWARF: 0x104450
    unsigned int p0[3]; // Offset: 0x4, DWARF: 0x104473
    void* madr; // Offset: 0x10, DWARF: 0x104494
    unsigned int p1[3]; // Offset: 0x14, DWARF: 0x1044B8
    unsigned int qwc; // Offset: 0x20, DWARF: 0x1044D9
    unsigned int p2[3]; // Offset: 0x24, DWARF: 0x1044F9
    _sceDmaTag* tadr; // Offset: 0x30, DWARF: 0x10451A
    unsigned int p3[3]; // Offset: 0x34, DWARF: 0x104540
    void* as0; // Offset: 0x40, DWARF: 0x104561
    unsigned int p4[3]; // Offset: 0x44, DWARF: 0x104584
    void* as1; // Offset: 0x50, DWARF: 0x1045A5
    unsigned int p5[3]; // Offset: 0x54, DWARF: 0x1045C8
    unsigned int p6[4]; // Offset: 0x60, DWARF: 0x1045E9
    unsigned int p7[4]; // Offset: 0x70, DWARF: 0x10460A
    void* sadr; // Offset: 0x80, DWARF: 0x10462B
    unsigned int p8[3]; // Offset: 0x84, DWARF: 0x10464F
} Dma;

// Size: 0x8, DWARF: 0x10A952
typedef struct PMode
{
    unsigned int EN1 : 1; // Offset: 0x0, DWARF: 0x10A96E, Bit Offset: 0, Bit Size: 1
    unsigned int EN2 : 1; // Offset: 0x0, DWARF: 0x10A998, Bit Offset: 1, Bit Size: 1
    unsigned int CRTMD : 3; // Offset: 0x0, DWARF: 0x10A9C2, Bit Offset: 2, Bit Size: 3
    unsigned int MMOD : 1; // Offset: 0x0, DWARF: 0x10A9EE, Bit Offset: 5, Bit Size: 1
    unsigned int AMOD : 1; // Offset: 0x0, DWARF: 0x10AA19, Bit Offset: 6, Bit Size: 1
    unsigned int SLBG : 1; // Offset: 0x0, DWARF: 0x10AA44, Bit Offset: 7, Bit Size: 1
    unsigned int ALP : 8; // Offset: 0x0, DWARF: 0x10AA6F, Bit Offset: 8, Bit Size: 8
    unsigned int p0 : 16; // Offset: 0x0, DWARF: 0x10AA99, Bit Offset: 16, Bit Size: 16
    unsigned int p1; // Offset: 0x4, DWARF: 0x10AAC2
} PMode;

// Size: 0x8, DWARF: 0x10470A
typedef struct SMode
{
    unsigned int INT : 1; // Offset: 0x0, DWARF: 0x104726, Bit Offset: 0, Bit Size: 1
    unsigned int FFMD : 1; // Offset: 0x0, DWARF: 0x104750, Bit Offset: 1, Bit Size: 1
    unsigned int DPMS : 2; // Offset: 0x0, DWARF: 0x10477B, Bit Offset: 2, Bit Size: 2
    unsigned int p0 : 28; // Offset: 0x0, DWARF: 0x1047A6, Bit Offset: 4, Bit Size: 28
    unsigned int p1; // Offset: 0x4, DWARF: 0x1047CF
} SMode;

// Size: 0x8, DWARF: 0x1021CC
typedef struct DispFb
{
    unsigned int FBP : 9; // Offset: 0x0, DWARF: 0x1021E7, Bit Offset: 0, Bit Size: 9
    unsigned int FBW : 6; // Offset: 0x0, DWARF: 0x102211, Bit Offset: 9, Bit Size: 6
    unsigned int PSM : 5; // Offset: 0x0, DWARF: 0x10223B, Bit Offset: 15, Bit Size: 5
    unsigned int p0 : 12; // Offset: 0x0, DWARF: 0x102265, Bit Offset: 20, Bit Size: 12
    unsigned int DBX : 11; // Offset: 0x4, DWARF: 0x10228E, Bit Offset: 0, Bit Size: 11
    unsigned int DBY : 11; // Offset: 0x4, DWARF: 0x1022B8, Bit Offset: 11, Bit Size: 11
    unsigned int p1 : 10; // Offset: 0x4, DWARF: 0x1022E2, Bit Offset: 22, Bit Size: 10
} DispFb;

// Size: 0x8, DWARF: 0x106691
typedef struct Display
{
    unsigned int DX : 12; // Offset: 0x0, DWARF: 0x1066AD, Bit Offset: 0, Bit Size: 12
    unsigned int DY : 11; // Offset: 0x0, DWARF: 0x1066D6, Bit Offset: 12, Bit Size: 11
    unsigned int MAGH : 4; // Offset: 0x0, DWARF: 0x1066FF, Bit Offset: 23, Bit Size: 4
    unsigned int MAGV : 2; // Offset: 0x0, DWARF: 0x10672A, Bit Offset: 27, Bit Size: 2
    unsigned int p0 : 3; // Offset: 0x0, DWARF: 0x106755, Bit Offset: 29, Bit Size: 3
    unsigned int DW : 12; // Offset: 0x4, DWARF: 0x10677E, Bit Offset: 0, Bit Size: 12
    unsigned int DH : 11; // Offset: 0x4, DWARF: 0x1067A7, Bit Offset: 12, Bit Size: 11
    unsigned int p1 : 9; // Offset: 0x4, DWARF: 0x1067D0, Bit Offset: 23, Bit Size: 9
} Display;

// Size: 0x8, DWARF: 0x106BA7
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x106BC3, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x106BEB, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x106C13, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, DWARF: 0x106C3B, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4, DWARF: 0x106C64
} BgColor;

// Size: 0x28, DWARF: 0x1061B1
typedef struct Disp
{
    // Size: 0x8, DWARF: 0x10A952
    PMode pmode; // Offset: 0x0, DWARF: 0x1061CD
    // Size: 0x8, DWARF: 0x10470A
    SMode smode2; // Offset: 0x8, DWARF: 0x1061F1
    // Size: 0x8, DWARF: 0x1021CC
    DispFb dispfb; // Offset: 0x10, DWARF: 0x106216
    // Size: 0x8, DWARF: 0x106691
    Display display; // Offset: 0x18, DWARF: 0x10623B
    // Size: 0x8, DWARF: 0x106BA7
    BgColor bgcolor; // Offset: 0x20, DWARF: 0x106261
} Disp;

// Size: 0x10, DWARF: 0x103FD3
typedef struct GifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0x103FEF, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0x10401B, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x104045, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0x104071, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0x10409A, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0x1040C4, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0x1040EF, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0x104119, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0x104144, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0x104170, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0x10419C, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0x1041C8, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0x1041F4, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0x104220, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0x10424C, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0x104278, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0x1042A4, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0x1042D0, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0x1042FC, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0x104329, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0x104356, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0x104383, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0x1043B0, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0x1043DD, Bit Offset: 60, Bit Size: 4
} GifTag;

// Size: 0x10, DWARF: 0x104AF1
typedef union GifTagUl
{
    // Size: 0x10, DWARF: 0x103FD3
    GifTag sce; // Offset: 0x0, DWARF: 0x104B0D
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0x104B2F
} GifTagUl;

// Size: 0x8, DWARF: 0x10731D
typedef struct Prim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0x107339, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0x107364, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0x10738E, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0x1073B8, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0x1073E2, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0x10740C, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0x107436, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0x107460, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0x10748B, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0x1074B5, Bit Offset: 11, Bit Size: 53
} Prim;

// Size: 0x8, DWARF: 0x10589F
typedef union PrimUl
{
    // Size: 0x8, DWARF: 0x10731D
    Prim sce; // Offset: 0x0, DWARF: 0x1058BB
    unsigned long ul; // Offset: 0x0, DWARF: 0x1058DD
} PrimUl;

// Size: 0x8, DWARF: 0x1052CF
typedef struct sceGsTex0
{
    unsigned long TBP0 : 14; // Offset: 0x0, DWARF: 0x1052EB, Bit Offset: 0, Bit Size: 14
    unsigned long TBW : 6; // Offset: 0x0, DWARF: 0x105316, Bit Offset: 14, Bit Size: 6
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x105340, Bit Offset: 20, Bit Size: 6
    unsigned long TW : 4; // Offset: 0x0, DWARF: 0x10536A, Bit Offset: 26, Bit Size: 4
    unsigned long TH : 4; // Offset: 0x0, DWARF: 0x105393, Bit Offset: 30, Bit Size: 4
    unsigned long TCC : 1; // Offset: 0x0, DWARF: 0x1053BC, Bit Offset: 34, Bit Size: 1
    unsigned long TFX : 2; // Offset: 0x0, DWARF: 0x1053E6, Bit Offset: 35, Bit Size: 2
    unsigned long CBP : 14; // Offset: 0x0, DWARF: 0x105410, Bit Offset: 37, Bit Size: 14
    unsigned long CPSM : 4; // Offset: 0x0, DWARF: 0x10543A, Bit Offset: 51, Bit Size: 4
    unsigned long CSM : 1; // Offset: 0x0, DWARF: 0x105465, Bit Offset: 55, Bit Size: 1
    unsigned long CSA : 5; // Offset: 0x0, DWARF: 0x10548F, Bit Offset: 56, Bit Size: 5
    unsigned long CLD : 3; // Offset: 0x0, DWARF: 0x1054B9, Bit Offset: 61, Bit Size: 3
} sceGsTex0;

// Size: 0x8, DWARF: 0x106C87
typedef union sceGsTex0Ul
{
    // Size: 0x8, DWARF: 0x1052CF
    sceGsTex0 sce; // Offset: 0x0, DWARF: 0x106CA3
    unsigned long ul; // Offset: 0x0, DWARF: 0x106CC5
} sceGsTex0Ul;

// Size: 0x8, DWARF: 0x109730
typedef struct RGBAQ
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x10974C, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x109774, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x10979C, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0x1097C4, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0x1097EC
} RGBAQ;

// Size: 0x8, DWARF: 0x105DB0
typedef union RGBAQUl
{
    // Size: 0x8, DWARF: 0x109730
    RGBAQ sce; // Offset: 0x0, DWARF: 0x105DCC
    unsigned long ul; // Offset: 0x0, DWARF: 0x105DEE
} RGBAQUl;

// Size: 0x8, DWARF: 0x10A804
typedef struct Frame
{
    unsigned long FBP : 9; // Offset: 0x0, DWARF: 0x10A820, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 7; // Offset: 0x0, DWARF: 0x10A84A, Bit Offset: 9, Bit Size: 7
    unsigned long FBW : 6; // Offset: 0x0, DWARF: 0x10A876, Bit Offset: 16, Bit Size: 6
    unsigned long pad22 : 2; // Offset: 0x0, DWARF: 0x10A8A0, Bit Offset: 22, Bit Size: 2
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x10A8CC, Bit Offset: 24, Bit Size: 6
    unsigned long pad30 : 2; // Offset: 0x0, DWARF: 0x10A8F6, Bit Offset: 30, Bit Size: 2
    unsigned long FBMSK : 32; // Offset: 0x0, DWARF: 0x10A922, Bit Offset: 32, Bit Size: 32
} Frame;

// Size: 0x8, DWARF: 0x106D4C
typedef struct ZBuf
{
    unsigned long ZBP : 9; // Offset: 0x0, DWARF: 0x106D68, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 15; // Offset: 0x0, DWARF: 0x106D92, Bit Offset: 9, Bit Size: 15
    unsigned long PSM : 4; // Offset: 0x0, DWARF: 0x106DBE, Bit Offset: 24, Bit Size: 4
    unsigned long pad28 : 4; // Offset: 0x0, DWARF: 0x106DE8, Bit Offset: 28, Bit Size: 4
    unsigned long ZMSK : 1; // Offset: 0x0, DWARF: 0x106E14, Bit Offset: 32, Bit Size: 1
    unsigned long pad33 : 31; // Offset: 0x0, DWARF: 0x106E3F, Bit Offset: 33, Bit Size: 31
} ZBuf;

// Size: 0x8, DWARF: 0x104982
typedef struct XYOffset
{
    unsigned long OFX : 16; // Offset: 0x0, DWARF: 0x10499E, Bit Offset: 0, Bit Size: 16
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x1049C8, Bit Offset: 16, Bit Size: 16
    unsigned long OFY : 16; // Offset: 0x0, DWARF: 0x1049F4, Bit Offset: 32, Bit Size: 16
    unsigned long pad48 : 16; // Offset: 0x0, DWARF: 0x104A1E, Bit Offset: 48, Bit Size: 16
} XYOffset;

// Size: 0x8, DWARF: 0x10A31C
typedef struct Scissor
{
    unsigned long SCAX0 : 11; // Offset: 0x0, DWARF: 0x10A338, Bit Offset: 0, Bit Size: 11
    unsigned long pad11 : 5; // Offset: 0x0, DWARF: 0x10A364, Bit Offset: 11, Bit Size: 5
    unsigned long SCAX1 : 11; // Offset: 0x0, DWARF: 0x10A390, Bit Offset: 16, Bit Size: 11
    unsigned long pad27 : 5; // Offset: 0x0, DWARF: 0x10A3BC, Bit Offset: 27, Bit Size: 5
    unsigned long SCAY0 : 11; // Offset: 0x0, DWARF: 0x10A3E8, Bit Offset: 32, Bit Size: 11
    unsigned long pad43 : 5; // Offset: 0x0, DWARF: 0x10A414, Bit Offset: 43, Bit Size: 5
    unsigned long SCAY1 : 11; // Offset: 0x0, DWARF: 0x10A440, Bit Offset: 48, Bit Size: 11
    unsigned long pad59 : 5; // Offset: 0x0, DWARF: 0x10A46C, Bit Offset: 59, Bit Size: 5
} Scissor;

// Size: 0x8, DWARF: 0x108CC2
typedef struct PrModeCont
{
    unsigned long AC : 1; // Offset: 0x0, DWARF: 0x108CDE, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x108D07, Bit Offset: 1, Bit Size: 63
} PrModeCont;

// Size: 0x8, DWARF: 0x103C93
typedef struct ColClamp
{
    unsigned long CLAMP : 1; // Offset: 0x0, DWARF: 0x103CAF, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x103CDB, Bit Offset: 1, Bit Size: 63
} ColClamp;

// Size: 0x8, DWARF: 0x108E9F
typedef struct Dthe
{
    unsigned long DTHE : 1; // Offset: 0x0, DWARF: 0x108EBB, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x108EE6, Bit Offset: 1, Bit Size: 63
} Dthe;

// Size: 0x8, DWARF: 0x10274A
typedef struct Test
{
    unsigned long ATE : 1; // Offset: 0x0, DWARF: 0x102765, Bit Offset: 0, Bit Size: 1
    unsigned long ATST : 3; // Offset: 0x0, DWARF: 0x10278F, Bit Offset: 1, Bit Size: 3
    unsigned long AREF : 8; // Offset: 0x0, DWARF: 0x1027BA, Bit Offset: 4, Bit Size: 8
    unsigned long AFAIL : 2; // Offset: 0x0, DWARF: 0x1027E5, Bit Offset: 12, Bit Size: 2
    unsigned long DATE : 1; // Offset: 0x0, DWARF: 0x102811, Bit Offset: 14, Bit Size: 1
    unsigned long DATM : 1; // Offset: 0x0, DWARF: 0x10283C, Bit Offset: 15, Bit Size: 1
    unsigned long ZTE : 1; // Offset: 0x0, DWARF: 0x102867, Bit Offset: 16, Bit Size: 1
    unsigned long ZTST : 2; // Offset: 0x0, DWARF: 0x102891, Bit Offset: 17, Bit Size: 2
    unsigned long pad19 : 45; // Offset: 0x0, DWARF: 0x1028BC, Bit Offset: 19, Bit Size: 45
} Test;

// Size: 0x80, DWARF: 0x106919
typedef struct Draw
{
    // Size: 0x8, DWARF: 0x10A804
    Frame frame1; // Offset: 0x0, DWARF: 0x106935
    unsigned long frame1addr; // Offset: 0x8, DWARF: 0x10695A
    // Size: 0x8, DWARF: 0x106D4C
    ZBuf zbuf1; // Offset: 0x10, DWARF: 0x106981
    signed long zbuf1addr; // Offset: 0x18, DWARF: 0x1069A5
    // Size: 0x8, DWARF: 0x104982
    XYOffset xyoffset1; // Offset: 0x20, DWARF: 0x1069CB
    signed long xyoffset1addr; // Offset: 0x28, DWARF: 0x1069F3
    // Size: 0x8, DWARF: 0x10A31C
    Scissor scissor1; // Offset: 0x30, DWARF: 0x106A1D
    signed long scissor1addr; // Offset: 0x38, DWARF: 0x106A44
    // Size: 0x8, DWARF: 0x108CC2
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x106A6D
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x106A96
    // Size: 0x8, DWARF: 0x103C93
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x106AC1
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x106AE8
    // Size: 0x8, DWARF: 0x108E9F
    Dthe dthe; // Offset: 0x60, DWARF: 0x106B11
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x106B34
    // Size: 0x8, DWARF: 0x10274A
    Test test1; // Offset: 0x70, DWARF: 0x106B59
    signed long test1addr; // Offset: 0x78, DWARF: 0x106B7D
} Draw;

// Size: 0x80, DWARF: 0x1083D4
typedef struct Draw2
{
    // Size: 0x8, DWARF: 0x10A804
    Frame frame2; // Offset: 0x0, DWARF: 0x1083F0
    unsigned long frame2addr; // Offset: 0x8, DWARF: 0x108415
    // Size: 0x8, DWARF: 0x106D4C
    ZBuf zbuf2; // Offset: 0x10, DWARF: 0x10843C
    signed long zbuf2addr; // Offset: 0x18, DWARF: 0x108460
    // Size: 0x8, DWARF: 0x104982
    XYOffset xyoffset2; // Offset: 0x20, DWARF: 0x108486
    signed long xyoffset2addr; // Offset: 0x28, DWARF: 0x1084AE
    // Size: 0x8, DWARF: 0x10A31C
    Scissor scissor2; // Offset: 0x30, DWARF: 0x1084D8
    signed long scissor2addr; // Offset: 0x38, DWARF: 0x1084FF
    // Size: 0x8, DWARF: 0x108CC2
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x108528
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x108551
    // Size: 0x8, DWARF: 0x103C93
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x10857C
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x1085A3
    // Size: 0x8, DWARF: 0x108E9F
    Dthe dthe; // Offset: 0x60, DWARF: 0x1085CC
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x1085EF
    // Size: 0x8, DWARF: 0x10274A
    Test test2; // Offset: 0x70, DWARF: 0x108614
    signed long test2addr; // Offset: 0x78, DWARF: 0x108638
} Draw2;

// Size: 0x8, DWARF: 0x105C93
typedef struct XYZ
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x105CAF, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x105CD7, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 32; // Offset: 0x0, DWARF: 0x105CFF, Bit Offset: 32, Bit Size: 32
} XYZ;

// Size: 0x60, DWARF: 0x109B58
typedef struct Clear
{
    // Size: 0x8, DWARF: 0x10274A
    Test testa; // Offset: 0x0, DWARF: 0x109B74
    signed long testaaddr; // Offset: 0x8, DWARF: 0x109B98
    // Size: 0x8, DWARF: 0x10731D
    Prim prim; // Offset: 0x10, DWARF: 0x109BBE
    signed long primaddr; // Offset: 0x18, DWARF: 0x109BE1
    // Size: 0x8, DWARF: 0x109730
    RGBAQ rgbaq; // Offset: 0x20, DWARF: 0x109C06
    signed long rgbaqaddr; // Offset: 0x28, DWARF: 0x109C2A
    // Size: 0x8, DWARF: 0x105C93
    XYZ xyz2a; // Offset: 0x30, DWARF: 0x109C50
    signed long xyz2aaddr; // Offset: 0x38, DWARF: 0x109C74
    // Size: 0x8, DWARF: 0x105C93
    XYZ xyz2b; // Offset: 0x40, DWARF: 0x109C9A
    signed long xyz2baddr; // Offset: 0x48, DWARF: 0x109CBE
    // Size: 0x8, DWARF: 0x10274A
    Test testb; // Offset: 0x50, DWARF: 0x109CE4
    signed long testbaddr; // Offset: 0x58, DWARF: 0x109D08
} Clear;

// Size: 0x330, DWARF: 0x10B34B
typedef struct DBuff
{
    // Size: 0x28, DWARF: 0x1061B1
    Disp disp[2]; // Offset: 0x0, DWARF: 0x10B367
    // Size: 0x10, DWARF: 0x103FD3
    GifTag giftag0; // Offset: 0x50, DWARF: 0x10B38A
    // Size: 0x80, DWARF: 0x106919
    Draw draw01; // Offset: 0x60, DWARF: 0x10B3B0
    // Size: 0x80, DWARF: 0x1083D4
    Draw2 draw02; // Offset: 0xE0, DWARF: 0x10B3D5
    // Size: 0x60, DWARF: 0x109B58
    Clear clear0; // Offset: 0x160, DWARF: 0x10B3FA
    // Size: 0x10, DWARF: 0x103FD3
    GifTag giftag1; // Offset: 0x1C0, DWARF: 0x10B41F
    // Size: 0x80, DWARF: 0x106919
    Draw draw11; // Offset: 0x1D0, DWARF: 0x10B445
    // Size: 0x80, DWARF: 0x1083D4
    Draw2 draw12; // Offset: 0x250, DWARF: 0x10B46A
    // Size: 0x60, DWARF: 0x109B58
    Clear clear1; // Offset: 0x2D0, DWARF: 0x10B48F
} DBuff;

// Size: 0x360, DWARF: 0x1037C1
typedef struct VulsysSystem
{
    unsigned int KeepMemSize; // Offset: 0x0, DWARF: 0x1037DD
    signed int Pal; // Offset: 0x4, DWARF: 0x103805
    signed int Interlace; // Offset: 0x8, DWARF: 0x103825
    signed short ScreenMode; // Offset: 0xC, DWARF: 0x10384B
    signed short ScreenWidth; // Offset: 0xE, DWARF: 0x103872
    signed short ScreenHeight; // Offset: 0x10, DWARF: 0x10389A
    signed short ScreenYofs; // Offset: 0x12, DWARF: 0x1038C3
    signed int EvenOdd; // Offset: 0x14, DWARF: 0x1038EA
    unsigned long Frame; // Offset: 0x18, DWARF: 0x10390E
    signed int PadInit; // Offset: 0x20, DWARF: 0x103930
    // Size: 0x90, DWARF: 0x104434
    Dma* DmaGif; // Offset: 0x24, DWARF: 0x103954
    // Size: 0x90, DWARF: 0x104434
    Dma* DmaVif0; // Offset: 0x28, DWARF: 0x10397C
    // Size: 0x90, DWARF: 0x104434
    Dma* DmaVif1; // Offset: 0x2C, DWARF: 0x1039A5
    // Size: 0x330, DWARF: 0x10B34B
    DBuff DBuff; // Offset: 0x30, DWARF: 0x1039CE
} VulsysSystem;

// Size: 0x20, DWARF: 0x1080DD
typedef struct VgmsysVif1Pkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x1080F9
    __int128* pBase; // Offset: 0x4, DWARF: 0x108121
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x108146
    unsigned int* pVifCode; // Offset: 0xC, DWARF: 0x10816D
    unsigned int numlen; // Offset: 0x10, DWARF: 0x108195
    unsigned long* pGifTag; // Offset: 0x14, DWARF: 0x1081B8
    unsigned int pad12; // Offset: 0x18, DWARF: 0x1081DF
    unsigned int pad13; // Offset: 0x1C, DWARF: 0x108201
} VgmsysVif1Pkt;

// Size: 0xC, DWARF: 0x10A5EF
typedef struct Fog
{
    signed int enable; // Offset: 0x0, DWARF: 0x10A60B
    float a; // Offset: 0x4, DWARF: 0x10A62E
    float b; // Offset: 0x8, DWARF: 0x10A64C
} Fog;

// Size: 0x8, DWARF: 0x10A7C3, 0x10361D
typedef struct EnvMap
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x10A7DF
} EnvMap;

// Size: 0x8, DWARF: 0x10AB0B
typedef struct Toon
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x10AB27
} Toon;

// Size: 0x120, DWARF: 0x1032EC
typedef struct MdlEnv
{
    float world_view[4][4]; // Offset: 0x0, DWARF: 0x103308
    float view_screen[4][4]; // Offset: 0x40, DWARF: 0x103331
    float normal_light[4][4]; // Offset: 0x80, DWARF: 0x10335B
    float light_color[4][4]; // Offset: 0xC0, DWARF: 0x103386
    // Size: 0xC, DWARF: 0x10A5EF
    Fog fog; // Offset: 0x100, DWARF: 0x1033B0
    union
    {
        // Size: 0x8, DWARF: 0x10A7C3
        EnvMap envmap; // Offset: 0x110, DWARF: 0x1033D2
        // Size: 0x8, DWARF: 0x10AB0B
        Toon toon; // Offset: 0x110, DWARF: 0x1033F7
    };
} MdlEnv;

// Size: 0x230, DWARF: 0x108F16
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

// Size: 0x20, DWARF: 0x106CE8
typedef struct ModelData
{
    float pos[4]; // Offset: 0x0, DWARF: 0xBA14E
    float rot[4]; // Offset: 0x10, DWARF: 0xBA170
}  ModelData;

// Size: 0x10, DWARF: 0x108BD5
typedef struct PosAddress
{
    unsigned int type; // Offset: 0x0, DWARF: 0xBCA58
    float frame; // Offset: 0x4, DWARF: 0xBCA79
    signed short flg; // Offset: 0x8, DWARF: 0xBCA9B
    signed short non; // Offset: 0xA, DWARF: 0xBCABB
    float* data[4]; // Offset: 0xC, DWARF: 0xBCADB
} PosAddress;

// Size: 0xF0, DWARF: 0x102E9D
typedef struct SeqData
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0x102EB9
    signed int loop; // Offset: 0x4, DWARF: 0x102EDE
    signed int mode; // Offset: 0x8, DWARF: 0x102EFF
    signed int write_flg; // Offset: 0xC, DWARF: 0x102F20
    signed int now_local_id; // Offset: 0x10, DWARF: 0x102F46
    signed int now_top_id; // Offset: 0x14, DWARF: 0x102F6F
    signed int next_local_id; // Offset: 0x18, DWARF: 0x102F96
    signed int next_top_id; // Offset: 0x1C, DWARF: 0x102FC0
    // Size: 0x20, DWARF: 0x106CE8
    ModelData* mdl_data; // Offset: 0x20, DWARF: 0x102FE8
    float now_frame; // Offset: 0x24, DWARF: 0x103012
    float next_frame; // Offset: 0x28, DWARF: 0x103038
    float ratio; // Offset: 0x2C, DWARF: 0x10305F
    // Size: 0x10, DWARF: 0x108BD5
    PosAddress* now_pos_address; // Offset: 0x30, DWARF: 0x103081
    // Size: 0x10, DWARF: 0x108BD5
    PosAddress* now_rot_address; // Offset: 0x34, DWARF: 0x1030B2
    // Size: 0x10, DWARF: 0x108BD5
    PosAddress* next_pos_address; // Offset: 0x38, DWARF: 0x1030E3
    // Size: 0x10, DWARF: 0x108BD5
    PosAddress* next_rot_address; // Offset: 0x3C, DWARF: 0x103115
    float nowDir[4]; // Offset: 0x40, DWARF: 0x103147
    float nowTrans[4]; // Offset: 0x50, DWARF: 0x10316C
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0x103193
    float pos[4]; // Offset: 0xA0, DWARF: 0x1031BC
    float quat[4]; // Offset: 0xB0, DWARF: 0x1031DE
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0x103201
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0x103227
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0x10324D
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0x103278
    signed int pad[2]; // Offset: 0xE8, DWARF: 0x1032A2
} SeqData;

// Size: 0x2E0, DWARF: 0x104860
typedef struct ModelCtrl
{
    float rot[4]; // Offset: 0x0, DWARF: 0x10487C
    float trans[4]; // Offset: 0x10, DWARF: 0x10489E
    float scale[4]; // Offset: 0x20, DWARF: 0x1048C2
    float matrix[4][4]; // Offset: 0x30, DWARF: 0x1048E6
    float revision[4][4]; // Offset: 0x70, DWARF: 0x10490B
    // Size: 0x230, DWARF: 0x108F16
    IkParam ikparam; // Offset: 0xB0, DWARF: 0x104932
} ModelCtrl;

// Size: 0x1A0, DWARF: 0x1023F9
typedef struct ModelSCtrl
{
    signed int type; // Offset: 0x0, DWARF: 0x102414
    float power; // Offset: 0x4, DWARF: 0x102435
    float dir; // Offset: 0x8, DWARF: 0x102457
    float cnt; // Offset: 0xC, DWARF: 0x102477
    float head[4]; // Offset: 0x10, DWARF: 0x102497
    float preHead[4]; // Offset: 0x20, DWARF: 0x1024BA
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0x1024E0
    float g_vector[4]; // Offset: 0x170, DWARF: 0x10250A
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0x102531
    signed int pad[3]; // Offset: 0x194, DWARF: 0x10255B
} ModelSCtrl;

// Size: 0x20, DWARF: 0x10ADA9
typedef struct Utd
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0x10ADC5
    // Size: 0x10, DWARF: 0x1028EC
    Tex* tex; // Offset: 0x4, DWARF: 0x10ADE8
    signed int ntex; // Offset: 0x8, DWARF: 0x10AE0D
    signed int offset; // Offset: 0xC, DWARF: 0x10AE2E
    signed int block; // Offset: 0x10, DWARF: 0x10AE51
    unsigned int* frame; // Offset: 0x14, DWARF: 0x10AE73
    signed int res[2]; // Offset: 0x18, DWARF: 0x10AE98
} Utd;

// Size: 0x90, DWARF: 0x105E5B
typedef struct Change
{
    float original[4][4]; // Offset: 0x0, DWARF: 0x105E77
    float original2[4][4]; // Offset: 0x40, DWARF: 0x105E9E
    float* address[4][4]; // Offset: 0x80, DWARF: 0x105EC6
    float* address2[4][4]; // Offset: 0x84, DWARF: 0x105EEF
    signed int pad[2]; // Offset: 0x88, DWARF: 0x105F19
} Change;

// Size: 0x960, DWARF: 0x104BC3
typedef struct CharacterModel
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x104BDF
    unsigned char* vmd[2]; // Offset: 0x4, DWARF: 0x104C03
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* seq; // Offset: 0xC, DWARF: 0x104C25
    // Size: 0x2E0, DWARF: 0x104860
    ModelCtrl ctrl[2]; // Offset: 0x10, DWARF: 0x104C4A
    // Size: 0x1A0, DWARF: 0x1023F9
    ModelSCtrl sctrl[2]; // Offset: 0x5D0, DWARF: 0x104C6D
    // Size: 0x20, DWARF: 0x10ADA9
    Utd utd[2]; // Offset: 0x910, DWARF: 0x104C91
    // Size: 0x90, DWARF: 0x105E5B
    Change* change[2]; // Offset: 0x950, DWARF: 0x104CB3
} CharacterModel;

// Size: 0x378, DWARF: 0x106E6F
typedef struct CreatedCharacterModel
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x106E8B
    __int128* face_umd[9]; // Offset: 0x4, DWARF: 0x106EAF
    unsigned int* face_utd[9]; // Offset: 0x28, DWARF: 0x106ED6
    // Size: 0x10, DWARF: 0x1028EC
    Tex* face_tex[9]; // Offset: 0x4C, DWARF: 0x106EFD
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* face_seq[9]; // Offset: 0x70, DWARF: 0x106F24
    __int128* hair_umd[4][2]; // Offset: 0x94, DWARF: 0x106F4B
    unsigned int* hair_utd[4][4][2]; // Offset: 0xB4, DWARF: 0x106F72
    // Size: 0x10, DWARF: 0x1028EC
    Tex* hair_tex[4][2]; // Offset: 0x134, DWARF: 0x106F99
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* hair_seq[4]; // Offset: 0x154, DWARF: 0x106FC0
    __int128* body_umd[5]; // Offset: 0x164, DWARF: 0x106FE7
    unsigned int* body_utd[5][9]; // Offset: 0x178, DWARF: 0x10700E
    // Size: 0x10, DWARF: 0x1028EC
    Tex* body_tex[5]; // Offset: 0x22C, DWARF: 0x107035
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* body_seq[5]; // Offset: 0x240, DWARF: 0x10705C
    __int128* pants_umd[5]; // Offset: 0x254, DWARF: 0x107083
    unsigned int* pants_utd[5][8]; // Offset: 0x268, DWARF: 0x1070AB
    // Size: 0x10, DWARF: 0x1028EC
    Tex* pants_tex[5]; // Offset: 0x308, DWARF: 0x1070D3
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* pants_seq[5]; // Offset: 0x31C, DWARF: 0x1070FB
    __int128* glove_umd; // Offset: 0x330, DWARF: 0x107123
    unsigned int* glove_utd[4]; // Offset: 0x334, DWARF: 0x10714C
    // Size: 0x10, DWARF: 0x1028EC
    Tex* glove_tex; // Offset: 0x344, DWARF: 0x107174
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* glove_seq; // Offset: 0x348, DWARF: 0x10719F
    __int128* boots_umd; // Offset: 0x34C, DWARF: 0x1071CA
    unsigned int* boots_utd[4]; // Offset: 0x350, DWARF: 0x1071F3
    // Size: 0x10, DWARF: 0x1028EC
    Tex* boots_tex; // Offset: 0x360, DWARF: 0x10721B
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* boots_seq; // Offset: 0x364, DWARF: 0x107246
    __int128* board_umd; // Offset: 0x368, DWARF: 0x107271
    unsigned int* board_utd; // Offset: 0x36C, DWARF: 0x10729A
    // Size: 0x10, DWARF: 0x1028EC
    Tex* board_tex; // Offset: 0x370, DWARF: 0x1072C3
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* board_seq; // Offset: 0x374, DWARF: 0x1072EE
} CreatedCharacterModel;

// Size: 0x4B0, DWARF: 0x102C30
typedef struct VnmdispSoftData
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x102C4B
    __int128* umd; // Offset: 0x4, DWARF: 0x102C6F
    __int128* smd; // Offset: 0x8, DWARF: 0x102C92
    unsigned int* utd; // Offset: 0xC, DWARF: 0x102CB5
    // Size: 0x10, DWARF: 0x1028EC
    Tex* tex; // Offset: 0x10, DWARF: 0x102CD8
    // Size: 0xF0, DWARF: 0x102E9D
    SeqData* seq; // Offset: 0x14, DWARF: 0x102CFD
    signed int block; // Offset: 0x18, DWARF: 0x102D22
    unsigned int* frame; // Offset: 0x1C, DWARF: 0x102D44
    signed int res; // Offset: 0x20, DWARF: 0x102D69
    // Size: 0x2E0, DWARF: 0x104860
    ModelCtrl ctrl; // Offset: 0x30, DWARF: 0x102D89
    // Size: 0x1A0, DWARF: 0x1023F9
    ModelSCtrl sctrl; // Offset: 0x310, DWARF: 0x102DAC
} VnmdispSoftData;

// Size: 0x16720, DWARF: 0x104DA1
typedef struct LoadData
{
    unsigned int* link[2]; // Offset: 0x0, DWARF: 0x104DBD
    signed int offset; // Offset: 0x8, DWARF: 0x104DE0
    unsigned int* env_utd; // Offset: 0xC, DWARF: 0x104E03
    // Size: 0x10, DWARF: 0x1028EC
    Tex* env_tex; // Offset: 0x10, DWARF: 0x104E2A
    unsigned int* select_utd; // Offset: 0x14, DWARF: 0x104E53
    unsigned int* selmov_utd; // Offset: 0x18, DWARF: 0x104E7D
    unsigned int* sponsor_utd; // Offset: 0x1C, DWARF: 0x104EA7
    // Size: 0x10, DWARF: 0x1028EC
    Tex* sponsor_tex; // Offset: 0x20, DWARF: 0x104ED2
    unsigned int* medal_utd; // Offset: 0x24, DWARF: 0x104EFF
    // Size: 0x10, DWARF: 0x1028EC
    Tex* medal_tex; // Offset: 0x28, DWARF: 0x104F28
    __int128* medal_umd[3]; // Offset: 0x2C, DWARF: 0x104F53
    __int128* board_umd; // Offset: 0x38, DWARF: 0x104F7B
    unsigned char* board_vmd; // Offset: 0x3C, DWARF: 0x104FA4
    unsigned int* board_utd; // Offset: 0x40, DWARF: 0x104FCD
    unsigned int* ayboard_utd; // Offset: 0x44, DWARF: 0x104FF6
    // Size: 0x10, DWARF: 0x1028EC
    Tex* board_tex; // Offset: 0x48, DWARF: 0x105021
    unsigned int* emblem_utd; // Offset: 0x4C, DWARF: 0x10504C
    // Size: 0x10, DWARF: 0x1028EC
    Tex* emblem_tex; // Offset: 0x50, DWARF: 0x105076
    __int128* emblem_umd[2]; // Offset: 0x54, DWARF: 0x1050A2
    __int128* select_uad; // Offset: 0x5C, DWARF: 0x1050CB
    // Size: 0x960, DWARF: 0x104BC3
    CharacterModel character[12][3]; // Offset: 0x60, DWARF: 0x1050F5
    // Size: 0x378, DWARF: 0x106E6F
    CreatedCharacterModel create_chr[2]; // Offset: 0x151E0, DWARF: 0x10511D
    unsigned int* cr_arm_utd; // Offset: 0x158D0, DWARF: 0x105146
    unsigned int* cr_leg_utd; // Offset: 0x158D4, DWARF: 0x105170
    unsigned int* cr_arm_f_utd; // Offset: 0x158D8, DWARF: 0x10519A
    // Size: 0x4B0, DWARF: 0x102C30
    VnmdispSoftData game; // Offset: 0x158E0, DWARF: 0x1051C6
    // Size: 0x4B0, DWARF: 0x102C30
    VnmdispSoftData wheel; // Offset: 0x15D90, DWARF: 0x1051E9
    // Size: 0x4B0, DWARF: 0x102C30
    VnmdispSoftData param; // Offset: 0x16240, DWARF: 0x10520D
    __int128* pad_umd[9]; // Offset: 0x166F0, DWARF: 0x105231
    unsigned int* pad_utd; // Offset: 0x16714, DWARF: 0x105257
    // Size: 0x10, DWARF: 0x1028EC
    Tex* pad_tex; // Offset: 0x16718, DWARF: 0x10527E
} LoadData;

// Size: 0xE0, DWARF: 0x10AB4C
typedef struct VertexData
{
    signed int col[4][4]; // Offset: 0x0, DWARF: 0x10AB68
    signed int vert[4][4]; // Offset: 0x40, DWARF: 0x10AB8A
    signed int uv[4]; // Offset: 0x80, DWARF: 0x10ABAD
    float stq[4][4]; // Offset: 0x90, DWARF: 0x10ABCE
    // Size: 0x10, DWARF: 0x1028EC
    Tex* texdata; // Offset: 0xD0, DWARF: 0x10ABF0
    unsigned long psmt; // Offset: 0xD8, DWARF: 0x10AC19
} VertexData;

// Size: 0x8, DWARF: 0x108D37
typedef struct sceGSAlpha
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0x108D53, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0x108D7B, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0x108DA3, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0x108DCB, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0x108DF3, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0x108E1E, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0x108E48, Bit Offset: 40, Bit Size: 24
} sceGSAlpha;

// Size: 0x8, DWARF: 0x1074E5
typedef union GSAlphaUl
{
    // Size: 0x8, DWARF: 0x108D37
    sceGSAlpha sce; // Offset: 0x0, DWARF: 0x107501
    unsigned long ul; // Offset: 0x0, DWARF: 0x107523
} GSAlphaUl;

// Size: 0x20, DWARF: 0x103B17
typedef struct Alpha
{
    // Size: 0x10, DWARF: 0x104AF1
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x103B33
    // Size: 0x8, DWARF: 0x1074E5
    GSAlphaUl alpha; // Offset: 0x10, DWARF: 0x103B58
    signed long reg_addr; // Offset: 0x18, DWARF: 0x103B7C
} Alpha;

// Size: 0x8, DWARF: 0x10B27D
typedef struct SceST
{
    float S; // Offset: 0x0, DWARF: 0x10B299
    float T; // Offset: 0x4, DWARF: 0x10B2B7
} SceST;

// Size: 0x8, DWARF: 0x103BCB
typedef struct SceUV
{
    unsigned long U : 14; // Offset: 0x0, DWARF: 0x103BE7, Bit Offset: 0, Bit Size: 14
    unsigned long pad14 : 2; // Offset: 0x0, DWARF: 0x103C0F, Bit Offset: 14, Bit Size: 2
    unsigned long V : 14; // Offset: 0x0, DWARF: 0x103C3B, Bit Offset: 16, Bit Size: 14
    unsigned long pad30 : 34; // Offset: 0x0, DWARF: 0x103C63, Bit Offset: 30, Bit Size: 34
} SceUV;

// Size: 0x8, DWARF: 0x106823
typedef union Stuv
{
    // Size: 0x8, DWARF: 0x10B27D
    SceST scest; // Offset: 0x0, DWARF: 0x10683F
    // Size: 0x8, DWARF: 0x103BCB
    SceUV sceuv; // Offset: 0x0, DWARF: 0x106863
    unsigned long ul; // Offset: 0x0, DWARF: 0x106887
} Stuv;

// Size: 0x8, DWARF: 0x1065D1
typedef struct XYZF
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x1065ED, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x106615, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 24; // Offset: 0x0, DWARF: 0x10663D, Bit Offset: 32, Bit Size: 24
    unsigned long F : 8; // Offset: 0x0, DWARF: 0x106665, Bit Offset: 56, Bit Size: 8
} XYZF;

// Size: 0x8, DWARF: 0x106322
typedef union XYZFUl
{
    // Size: 0x8, DWARF: 0x1065D1
    XYZF sce; // Offset: 0x0, DWARF: 0x10633E
    unsigned long ul; // Offset: 0x0, DWARF: 0x106360
} XYZFUl;

// Size: 0x70, DWARF: 0x102A1B
typedef struct Poly
{
    // Size: 0x10, DWARF: 0x104AF1
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x102A36
    // Size: 0x8, DWARF: 0x10589F
    PrimUl prim; // Offset: 0x10, DWARF: 0x102A5B
    // Size: 0x8, DWARF: 0x106C87
    sceGsTex0Ul tex0; // Offset: 0x18, DWARF: 0x102A7E
    // Size: 0x8, DWARF: 0x105DB0
    RGBAQUl rgbaq0; // Offset: 0x20, DWARF: 0x102AA1
    // Size: 0x8, DWARF: 0x106823
    Stuv stuv0; // Offset: 0x28, DWARF: 0x102AC6
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf0; // Offset: 0x30, DWARF: 0x102AEA
    // Size: 0x8, DWARF: 0x106823
    Stuv stuv1; // Offset: 0x38, DWARF: 0x102B0E
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf1; // Offset: 0x40, DWARF: 0x102B32
    // Size: 0x8, DWARF: 0x106823
    Stuv stuv2; // Offset: 0x48, DWARF: 0x102B56
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf2; // Offset: 0x50, DWARF: 0x102B7A
    // Size: 0x8, DWARF: 0x106823
    Stuv stuv3; // Offset: 0x58, DWARF: 0x102B9E
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf3; // Offset: 0x60, DWARF: 0x102BC2
    unsigned long nop; // Offset: 0x68, DWARF: 0x102BE6
} Poly;

// Size: 0x40, DWARF: 0x10262E
typedef struct Poly2
{
    // Size: 0x10, DWARF: 0x104AF1
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x102649
    // Size: 0x8, DWARF: 0x10589F
    PrimUl prim; // Offset: 0x10, DWARF: 0x10266E
    // Size: 0x8, DWARF: 0x105DB0
    RGBAQUl rgbaq0; // Offset: 0x18, DWARF: 0x102691
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf0; // Offset: 0x20, DWARF: 0x1026B6
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf1; // Offset: 0x28, DWARF: 0x1026DA
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf2; // Offset: 0x30, DWARF: 0x1026FE
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf3; // Offset: 0x38, DWARF: 0x102722
} Poly2;

// Size: 0x50, DWARF: 0x10365E
typedef struct Poly3
{
    // Size: 0x10, DWARF: 0x104AF1
    GifTagUl giftag; // Offset: 0x0, DWARF: 0x10367A
    // Size: 0x8, DWARF: 0x10589F
    PrimUl prim; // Offset: 0x10, DWARF: 0x10369F
    // Size: 0x8, DWARF: 0x105DB0
    RGBAQUl rgbaq0; // Offset: 0x18, DWARF: 0x1036C2
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf0; // Offset: 0x20, DWARF: 0x1036E7
    // Size: 0x8, DWARF: 0x105DB0
    RGBAQUl rgbaq1; // Offset: 0x28, DWARF: 0x10370B
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf1; // Offset: 0x30, DWARF: 0x103730
    // Size: 0x8, DWARF: 0x105DB0
    RGBAQUl rgbaq2; // Offset: 0x38, DWARF: 0x103754
    // Size: 0x8, DWARF: 0x106322
    XYZFUl xyzf2; // Offset: 0x40, DWARF: 0x103779
    unsigned long nop; // Offset: 0x48, DWARF: 0x10379D
} Poly3;

// Size: 0x10, DWARF: 0x10230F
typedef struct FData
{
    float dx; // Offset: 0x0, DWARF: 0x10232A
    float dy; // Offset: 0x4, DWARF: 0x102349
    signed int size; // Offset: 0x8, DWARF: 0x102368
    signed int value; // Offset: 0xC, DWARF: 0x102389
} FData;

// Size: 0x20, DWARF: 0x109341
typedef struct ModelObjData
{
    signed int size; // Offset: 0x0, DWARF: 0x10935D
    unsigned int mode; // Offset: 0x4, DWARF: 0x10937E
    signed int nprim; // Offset: 0x8, DWARF: 0x10939F
    signed int blend; // Offset: 0xC, DWARF: 0x1093C1
    signed int ver; // Offset: 0x10, DWARF: 0x1093E3
    signed int nor; // Offset: 0x14, DWARF: 0x109403
    signed int rgba; // Offset: 0x18, DWARF: 0x109423
    signed int stq; // Offset: 0x1C, DWARF: 0x109444
} ModelObjData;

// Size: 0x10, DWARF: 0x109F3B
typedef struct ModelObj
{
    signed int nblock; // Offset: 0x0, DWARF: 0x109F57
    // Size: 0x20, DWARF: 0x109341
    ModelObjData* data; // Offset: 0x4, DWARF: 0x109F7A
    signed int _pad[2]; // Offset: 0x8, DWARF: 0x109FA0
} ModelObj;

// Size: 0x20, DWARF: 0x109618
typedef struct ModelHead
{
    char id[3]; // Offset: 0x0, DWARF: 0x109634
    char version; // Offset: 0x3, DWARF: 0x109655
    signed int nobj; // Offset: 0x4, DWARF: 0x109679
    // Size: 0x10, DWARF: 0x109F3B
    ModelObj* obj; // Offset: 0x8, DWARF: 0x10969A
    signed int ncoord; // Offset: 0xC, DWARF: 0x1096BF
    tag_ulcodCOORDINATE* coord; // Offset: 0x10, DWARF: 0x1096E2
    signed int _pad[3]; // Offset: 0x14, DWARF: 0x109709
} ModelHead;

// Size: 0x140, DWARF: 0x10B1CE
typedef struct Wind
{
    signed int count[8][3] __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x10B1EA
    signed int speed[8][3]; // Offset: 0x60, DWARF: 0x10B20E
    float wave[8][4]; // Offset: 0xC0, DWARF: 0x10B232
} Wind;

// Size: 0x8, DWARF: 0x102DF8
typedef struct Fog2
{
    float a; // Offset: 0x0, DWARF: 0x102E13
    float b; // Offset: 0x4, DWARF: 0x102E31
} Fog2;

// Size: 0x160, DWARF: 0x10AF2C
typedef struct ModelEnv
{
    unsigned int enable; // Offset: 0x0, DWARF: 0x10AF48
    // Size: 0x140, DWARF: 0x10B1CE
    Wind wind; // Offset: 0x10, DWARF: 0x10AF6B
    // Size: 0x8, DWARF: 0x102DF8
    Fog2 fog; // Offset: 0x150, DWARF: 0x10AF8E
    // Size: 0x8, DWARF: 0x10361D
    EnvMap envmap; // Offset: 0x158, DWARF: 0x10AFB0
} ModelEnv;

//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0x74, DWARF: 0x1088AE
Character* vayCharData[22]; // Address: 0x3C0C40
// Size: 0x5D0E0, DWARF: 0x107546
VspenvEnv vspenvEnv; // Address: 0x3474D0
// Size: 0x190, DWARF: 0x10791B
VayChrData* vayChrData; // Address: 0x2E7BE4
// Size: 0x1690, DWARF: 0x1034A9
VaySelData* vaySelData; // Address: 0x2E7BB4
// Size: 0xA0, DWARF: 0x1086FA
VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x10, DWARF: 0x107DFE
VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
// Size: 0x60, DWARF: 0x107667
VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30
// Size: 0xEF8, DWARF: 0x10A075
VspenvSecret* vspenvSecret; // Address: 0x2E7B04
// Size: 0x114, DWARF: 0x107EDD
VspenvOption* vspenvOption; // Address: 0x2E7B10
// Size: 0x20, DWARF: 0x10594A
VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0
// Size: 0x360, DWARF: 0x1037C1
VulsysSystem vulsysSystem; // Address: 0x2F3A50
signed int vayParamMax[12][6]; // Address: 0x2C7C10
// Size: 0x10, DWARF: 0x108AB4
BoardParameters vsptblBoardParam[12][7]; // Address: 0x2B72B0
char* vsptblCharacterName[12]; // Address: 0x2B5880
char* vsptblBoardName[12][7]; // Address: 0x2B58B0
// Size: 0x20, DWARF: 0x1080DD
VgmsysVif1Pkt* vgmsysVif1Pkt; // Address: 0x2E79C8
char* vsptblLevelGoalStr[8][3]; // Address: 0x3A45E0
char* vsptblCourseName[24]; // Address: 0x2B5A00
signed int vsptblLevelGoalValue[8][7]; // Address: 0x2B6A60

// Size: 0x50
typedef struct AyPolyPkt3
{
    __int128 q[5]; // Offset: 0x0
} AyPolyPkt3;

// Size: 0x40
typedef struct AyPolyPkt4
{
    __int128 q[4]; // Offset: 0x0
} AyPolyPkt4;

// Size: 0x20
typedef struct AyAlphaPkt
{
    __int128 q[2]; // Offset: 0x0
} AyAlphaPkt;

// Size: 0x70
typedef struct AyPolyPkt
{
    __int128 q[7]; // Offset: 0x0
} AyPolyPkt;

// Size: 0x8
typedef struct EnvFog
{
    float a; // Offset: 0x0
    float b; // Offset: 0x4
} EnvFog;

// Size: 0x160
typedef struct Vmenv
{
    unsigned int enable; // Offset: 0x0
    Wind wind; // Offset: 0x10
    EnvFog fog; // Offset: 0x150
    EnvMap envmap; // Offset: 0x158
} Vmenv;

// Size: 0xE0
typedef struct AyPolyData
{
    signed int rgba[4]; // Offset: 0x0
    unsigned char pad0[0x30]; // Offset: 0x10
    signed int vert[16]; // Offset: 0x40
    signed int uv[4]; // Offset: 0x80
    signed int stq[16]; // Offset: 0x90
    Tex* texData; // Offset: 0xD0
    unsigned char pad1[0x4]; // Offset: 0xD4
    unsigned long flag; // Offset: 0xD8
} AyPolyData;

//// Function Declarations ///////////////////////////////////////////////////////////


void ayCharSelInit();
signed int ayCharSelFrame();
void ayCharSelEnd();
void ayCharSelClear();
static void ayCalcSoftNum(signed int no);
static void ayDrawChar();
static void aySelBoardDraw();
static void aySelHeadDraw();
static void aySelItemDraw();
static void ayParamDraw();
static void ayCsInfoDraw();
static void ayCsImageDraw();
static void aySetUpDraw();
static void ayNameDraw();
static signed int ayHandicapDraw();
static void aySetKeyOparate();
static signed int ayClassifyChara(signed int id);
static void aySetCharEnv(signed int no);

// Included functions ////////////////////////////////////////////////////////////////
void ayFontInit(signed int x, signed int y, signed int* fcol);
void aySetVert(signed int* vert, float* xy, signed int z);
void aySetPolyComFT4(AyPolyPkt* poly, AyPolyData* data, signed int flg);
LoadData* sploadGetSelectData();
void ultexResetTex(signed int offset);
void ultexTransTexTag(VgmsysGifPkt* packet, unsigned int* addr, Tex* data, signed int no);
AyAlphaPkt* ulgifAddCNTReserve(VgmsysGifPkt* pkt, signed int qwc);
void ulpktInitALPHA(AyAlphaPkt* pkt, signed int ctext);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);
void nmfontFPrintF(VgmsysGifPkt* packet, char* str, float* pos);
void nmfontGPrintF(VgmsysGifPkt* packet, char* str, float* pos);
void nmfontSetPack(signed int flag);
void nmfontSetCol(signed int* col);
void aySetPolyComF4(AyPolyPkt4* poly, AyPolyData* data);
void nmfontFPrint(VgmsysGifPkt* packet, char* str, signed int x, signed int y);
void sceVu0UnitMatrix(float* m);
void sceVu0RotMatrixX(float* m0, float* m1, float rot);
void sceVu0RotMatrixY(float* m0, float* m1, float rot);
void sceVu0RotMatrixZ(float* m0, float* m1, float rot);
void sceVu0TransMatrix(float* m0, float* m1, float* tv);
void ul3dScaleMatrixXYZ(float* mat, float sx, float sy, float sz);
void aySetCamMatrix(float* worldScr, float* worldView, float* viewScr);
void aySetLightMatrix(float* nLight, float* lightCol, float acol, float lcol);
unsigned int ulmdlDrawModelPkt(unsigned int* pkt, VgmsysAbuf* abuf, MdlEnv* mdlenv, float* matrix, __int128* model, signed int drawmode);
void sceGifPkCnt(VgmsysGifPkt* p, unsigned int a, unsigned int b, unsigned int c);
void sceGifPkReserve(VgmsysGifPkt* p, unsigned int size);
void sceGifPkTerminate(VgmsysGifPkt* p);
void aySetPolyComG3(AyPolyPkt3* poly, float* pos, signed int flg, signed int col);
signed int ayCalcNextID(signed int now, signed int limit, signed int dir);
signed int nmvcPlayButton(signed int num);
signed int nmvcPlayCursor(signed int num);
void sploadFreeSCharacter(signed int chr_no);
void sploadLoadSCharacter(signed int chr_no);
signed int sploadCheckSCharacter();
void sploadSetSCharacter(signed int chr_no);
float ayCalcTotalMove(signed int frame, signed int count, float totalmove, signed int type);
void ayFontInitmin();
void ayCalcHandiParam();
void ayDrawBG(VgmsysGifPkt* packet, Tex* texData, signed int col, signed int mark);
void sploadDrawProfile(VgmsysGifPkt* packet, signed int chr_no, float y_pos, signed int select);
void ayBlackOutDraw(signed int col);
signed int nmvcPlay(signed int res, signed int group, signed int num);
void ayDrawKeyOparate(signed int kind, signed int count, signed int flg, Tex* texData, VgmsysGifPkt* packet);
void nmfontSetType(signed int type);
void nmfontSetSize(signed int width, signed int height);
void nmfontGPrint(VgmsysGifPkt* packet, char* str, signed int x, signed int y);
float ayDrawNum(VgmsysGifPkt* packet, FData* data, signed int flg);
signed int ulstdSprintf(char* buf, char* fmt, ...);
signed int ultexGetNTex(unsigned int* addr);
void ulgifTermPacket(VgmsysGifPkt* pkt);
void ulgifDmaSend(VgmsysGifPkt* pkt);
float maGetMdlMotionFrame(unsigned int* total_data, signed int id);
void maMdlMotionDirect(unsigned int* total_data, SeqData* seq, signed int id, float frame);
void maMdlMotionRealBrendDirect(unsigned int* total_data, SeqData* seq, signed int flg, signed int next_id, float next_frame, float ratio);
signed int maVuMdlMotionCtrl(__int128* mdl_data, __int128* motion_data, SeqData* seq, __int128** total_data);
void ulvumdlInitVerShadeWind(Vmenv* vmenv);
unsigned long ultexGetTEX0(void* data);
void ulcodInitCoordinate(tag_ulcodCOORDINATE* coord, tag_ulcodCOORDINATE* super);
void sceVu0CopyMatrix(float* dst, float* src);
void ulcodSetWvMatrix(float* wv);
void ulcodSetVsMatrix(float* vs);
void sceVif1PkCnt(VgmsysVif1Pkt* pkt, signed int flg);
void ulvumdlDrawModel(VgmsysVif1Pkt* vif1pkt, VgmsysAbuf* abuf, tag_ulcodCOORDINATE* coord, float* nl, float* lcmat, __int128* model, Vmenv* env);
void sceVif1PkEnd(VgmsysVif1Pkt* pkt, signed int flg);
void sceVif1PkTerminate(VgmsysVif1Pkt* pkt);
unsigned long* sceVif1PkReserve(VgmsysVif1Pkt* pkt, signed int qwc);
void FlushCache(signed int mode);
signed int sceDmaSync(Dma* d0, signed int mode, signed int timeout);
void sceDmaSend(Dma* d0, void* tag);
void ulvif1DmaWait();
void sceVif1PkReset(VgmsysVif1Pkt* pkt);
signed int rand();
void ulgifDmaWait();
VgmsysGifPkt* sceGifPkReset(VgmsysGifPkt* pkt);
void ulgraphAlphaSortPacket(VgmsysAbuf* abuf);
void ulgraphAlphaDrawPacket(Dma* dmagif, VgmsysAbuf* abuf);

static void aySetCsFlg();
void ayDrawCreateChara(// Size: 0xEC, DWARF: 0x109837
CreatedCharacter* chara, // Size: 0x120, DWARF: 0x1032EC
MdlEnv* mdlEnv, float* mat[4], signed int count);
static void ayDrawMotModel(__int128* modelData, // Size: 0xF0, DWARF: 0x102E9D
SeqData* seqData, // Size: 0x120, DWARF: 0x1032EC
MdlEnv* mdlEnv, float* mat[4], signed int flg, signed int sex, signed int count);
void aySetMotFlg(signed int mot);
static signed int ayCalcCharNext(signed int now, signed int dir);
static void ayLevelGoalDraw(// Size: 0x16720, DWARF: 0x104DA1
LoadData* loaddata);

// Function Definitions /////////////////////////////////////////////////////////////


void* memcpy(void* dest, const void* src, s32 size);

// aychrsel.c

void ayCharSelInit() {
    signed int ii; // r16

    vayChrData = (VayChrData*)ulMalloc(0x190, 0, 0);
    for (ii = 0; ii < 0xA; ii++) {
        vayCharData[ii] = &vspenvEnv.mc.secret.character[ii];
    }
    for (ii = 0; ii < 0xA; ii++) {
        vayCharData[ii + 0xA] = &vspenvEnv.mc.secret.create_character[ii];
    }
    for (ii = 0; ii < 2; ii++) {
        vayCharData[ii + 0x14] = &vspenvEnv.mc.secret.character[ii + 0xA];
    }
    ayCharSelClear();
}

signed int ayCharSelFrame() {
    signed int ret = 0; // r23 // s7
    signed int next = 0; // r17 // s1
    signed int player = vayChrData->player; // r20 // s4
    signed int chara = vayChrData->chara; // r18 // s2
    signed int fcol[4]; // 0xA0(r29)
    Tex texData[2]; // 0xB0(r29)
    char* load[3] = {"NOW LOADING", "LADEN ...", "CHARGEMENT EN COURS"}; // 0xD0(r29)
    signed int col; // 0xDC(r29)
    float dy; // 0xE0(r29)
    signed int sex; // 0xE4(r29)
    signed int count = vayChrData->count; // r19 // s3
    LoadData* data; // r21 // s5
    signed int ch; // r22 // s6
    signed int bocnt; // r30 // fp
    signed int ii; // r16 // s0

    (void)chara;
    (void)chara;
    (void)chara;
    data = sploadGetSelectData();
    ultexResetTex(data->offset);
    for (ii = 0; ii < 2; ii++) {
        texData[ii].tofs = -1;
        texData[ii].cofs = -1;
    }
    ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData[0], 0);
    ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData[1], 2);
    if (((vayChrData->step == 8) && ((vayChrData->boCnt == -1) || (vayChrData->boCnt >= 0x10))) || (vayChrData->step == 9) || ((vayChrData->step == 10) && (vayChrData->boCnt != -1) && (vayChrData->boCnt < 0x10))) {
        ayDrawBG(vgmsysGifPkt, texData, 0x80, 0);
    } else {
        ayDrawBG(vgmsysGifPkt, texData, 0x80, 1);
    }
    aySelHeadDraw();
    switch (vayChrData->charType) {
    case 0:
        ch = chara;
        break;
    case 1:
        ch = chara + 2;
        break;
    case 2:
        ch = chara - 10;
        break;
    }
    switch (vayChrData->step) {
    case 0:
        aySelItemDraw();
        ayDrawChar();
        aySelBoardDraw();
        ayParamDraw();
        ayNameDraw();
        aySetUpDraw();
        if (vayChrData->loadFlg == 1) {
            if (vayChrData->charType == 2) {
                chara -= 10;
            }
            if (vayChrData->count == 0) {
                sploadLoadSCharacter(chara);
            } else if (!sploadCheckSCharacter()) {
                sploadSetSCharacter(chara);
                vayChrData->loadFlg = 0;
                next = 1;
                vayChrData->step = 1;
            }
        }
        if (vayChrData->count == 0x40) {
            if (vayChrData->loadFlg != 0) {
                next = 2;
            } else {
                next = 1;
                vayChrData->step = 1;
            }
        }
        break;
    case 1:
        aySelItemDraw();
        ayDrawChar();
        aySelBoardDraw();
        ayParamDraw();
        ayNameDraw();
        aySetUpDraw();
        if ((vaySelData->bocount == -1) && (vayChrData->boCnt == -1) && (vayChrData->loadFlg == 0)) {
            if (vayChrData->motFlg == 0) {
                if (vayChrData->moveCnt == -1) {
                    if (vgmsysPad[player]->trg & 0x40) {
                        if (vayChrData->charaFlg && vayChrData->boardFlg) {
                            nmvcPlayButton(0);
                            aySetCsFlg();
                            ayCalcSoftNum(vayChrData->chara);
                            vayChrData->course = 0;
                            if (ayClassifyChara(chara) == 1) {
                                sex = vspenvSecret->create_character[chara - 10].sex;
                            } else if ((chara == 4) || (chara == 7)) {
                                sex = 1;
                            } else {
                                sex = 0;
                            }
                            if (sex == 1) {
                                vayChrData->nowMot = 0;
                            } else {
                                vayChrData->nowMot = 2;
                            }
                            vayChrData->motFlg = 1;
                            vayChrData->motFrame = 0.0f;
                        } else {
                            nmvcPlayButton(3);
                        }
                    } else if (vgmsysPad[player]->trg & 0x10) {
                        nmvcPlayButton(2);
                        next = 1;
                        if ((vaySelData->mode == 2) && (vayChrData->player == 1)) {
                            vayChrData->step = 7;
                        } else {
                            ret = 0xC;
                        }
                    } else if (vgmsysPad[player]->trg & 0x20) {
                        if ((vayChrData->charType != 1) && vayChrData->charaFlg) {
                            nmvcPlayButton(0);
                            next = 1;
                            vayChrData->step = 0xB;
                        } else {
                            nmvcPlayButton(3);
                        }
                    }
                }
            } else if (vayChrData->motFlg == 3) {
                if ((vgmsysPad[player]->trg & 0x40) || (vgmsysPad[player]->trg & 0x10)) {
                    if ((vaySelData->mode == 2) && (vayChrData->player == 0)) {
                        vayChrData->step = 6;
                        next = 1;
                    } else {
                        vayChrData->boCnt = 0;
                    }
                }
            }
        } else {
            if (vayChrData->boCnt == 0x10) {
                vayChrData->step = 2;
                next = 1;
            }
        }
        break;
    case 6:
        aySelItemDraw();
        ayDrawChar();
        aySelBoardDraw();
        ayParamDraw();
        ayNameDraw();
        aySetUpDraw();
        if (vayChrData->count == 8) {
            aySetCharEnv(0);
            switch (vayChrData->charType) {
            case 0:
                sploadFreeSCharacter(vayChrData->chara);
                break;
            case 2:
                sploadFreeSCharacter(vayChrData->chara - 10);
                break;
            }
            sploadLoadSCharacter(0);
            vayChrData->loadFlg = 1;
            vayChrData->chara = 0;
            vayChrData->charType = 0;
            vayChrData->select = 0;
            vayChrData->player = 1;
            vayChrData->nowMot = 3;
            vayChrData->motFlg = 0;
            vayChrData->motFrame = 0.0f;
            vayChrData->charMove = 0;
            for (ii = 0; ii < 0x16; ii++) {
                if (vspenvEnv.game.character[0].wear == 0) {
                    if (((vspenvEnv.game.character[0].no < 0xA) && (vspenvEnv.game.character[0].no == ii)) || ((vspenvEnv.game.character[0].no < 0xC) && (vspenvEnv.game.character[0].no == ii - 10))) {
                        vayChrData->wear[ii] = 1;
                    } else {
                        vayChrData->wear[ii] = 0;
                    }
                } else {
                    vayChrData->wear[ii] = 0;
                }
                vayChrData->board[ii] = 0;
            }
        } else if (vayChrData->count >= 0x10) {
            if (vayChrData->loadFlg == 0) {
                next = 1;
                vayChrData->step = 1;
            } else {
                next = 2;
            }
        }
        if (vayChrData->loadFlg == 1) {
            if (!sploadCheckSCharacter()) {
                sploadSetSCharacter(0);
                vayChrData->loadFlg = 0;
            }
        }
        break;
    case 7:
        aySelItemDraw();
        ayDrawChar();
        aySelBoardDraw();
        ayParamDraw();
        ayNameDraw();
        aySetUpDraw();
        if (vayChrData->count == 8) {
            switch (vayChrData->charType) {
            case 0:
                sploadFreeSCharacter(vayChrData->chara);
                break;
            case 2:
                sploadFreeSCharacter(vayChrData->chara - 10);
                break;
            }
            if (vspenvEnv.game.character[0].no < 0xA) {
                vayChrData->chara = chara = vspenvEnv.game.character[0].no;
                vayChrData->loadFlg = 1;
                sploadLoadSCharacter(vspenvEnv.game.character[0].no);
                vayChrData->charType = 0;
            } else if (vspenvEnv.game.character[0].no < 0xC) {
                vayChrData->chara = chara = vspenvEnv.game.character[0].no + 10;
                vayChrData->loadFlg = 1;
                sploadLoadSCharacter(vspenvEnv.game.character[0].no);
                vayChrData->charType = 2;
            } else {
                chara = vayChrData->chara = vspenvEnv.game.character[0].no - 2;
                vayChrData->loadFlg = 0;
                vayChrData->charType = 1;
            }
            for (ii = 0; ii < 0x16; ii++) {
                vayChrData->wear[ii] = 0;
                vayChrData->board[ii] = 0;
            }
            vayChrData->wear[vayChrData->chara] = vspenvEnv.game.character[0].wear;
            vayChrData->board[vayChrData->chara] = vspenvEnv.game.character[0].board;
            vayChrData->player = 0;
            vayChrData->select = 0;
            vayChrData->motFrame = 0.0f;
            vayChrData->charMove = 0;
        } else if (vayChrData->count >= 0x10) {
            if (vayChrData->loadFlg == 0) {
                next = 1;
                vayChrData->step = 1;
            } else {
                next = 2;
            }
        }
        if (vayChrData->loadFlg == 1) {
            if (!sploadCheckSCharacter()) {
                if (vayChrData->charType == 2) {
                    chara -= 10;
                }
                sploadSetSCharacter(chara);
                vayChrData->loadFlg = 0;
            }
        }
        break;
    case 2:
        aySelItemDraw();
        if ((vaySelData->mode == 0) || (vaySelData->mode == 1)) {
            ayCsInfoDraw();
        }
        ayCsImageDraw();
        ayNameDraw();
        if ((vaySelData->bocount == -1) && (vayChrData->boCnt == -1) && (vayChrData->moveCnt == -1)) {
            if ((vgmsysPad[0]->trg & 0x40) || (vgmsysPad[player]->trg & 0x40)) {
                if (vayChrData->csFlg & (1 << vayChrData->course)) {
                    if (vaySelData->mode != 2) {
                        vaySelData->vcID = nmvcPlay(3, 1, 6);
                        aySetCharEnv(0);
                        vspenvEnv.game.course.no = vayChrData->course;
                        vspenvEnv.game.mode.num_player = 1;
                        ret = 0xB;
                    } else {
                        nmvcPlayButton(0);
                        next = 1;
                        vayChrData->step = 8;
                        vayChrData->boCnt = 0;
                        aySetCharEnv(1);
                        vayChrData->handicap[0] = vayChrData->handicap[1] = 5;
                        vayChrData->capAccept[1] = 0;
                        vayChrData->capAccept[0] = 0;
                        vspenvEnv.game.course.no = vayChrData->course;
                    }
                } else {
                    nmvcPlayButton(3);
                }
            } else if ((vgmsysPad[0]->trg & 0x10) || (vgmsysPad[player]->trg & 0x10)) {
                nmvcPlayButton(2);
                vayChrData->boCnt = 0;
            } else if (vgmsysPad[0]->trg & 0x20) {
                if ((vaySelData->mode == 0) || (vaySelData->mode == 1)) {
                    if (vayChrData->csFlg & (1 << vayChrData->course)) {
                        nmvcPlayButton(0);
                        next = 1;
                        vayChrData->step = 3;
                    } else {
                        nmvcPlayButton(3);
                    }
                }
            }
        } else if (vayChrData->boCnt == 0x10) {
            vayChrData->step = 1;
            vayChrData->nowMot = 3;
            vayChrData->motFlg = 0;
            vayChrData->motFrame = 0.0f;
            vayChrData->charMove = 0;
            next = 1;
        }
        break;
    case 3:
        aySelItemDraw();
        ayCsInfoDraw();
        ayCsImageDraw();
        ayNameDraw();
        ayLevelGoalDraw(data);
        if (vayChrData->count == 1) {
            nmvcPlay(3, 1, 7);
        } else if (vayChrData->count == 0x20) {
            next = 1;
            vayChrData->step = 4;
        }
        break;
    case 5:
        aySelItemDraw();
        ayCsInfoDraw();
        ayCsImageDraw();
        ayNameDraw();
        ayLevelGoalDraw(data);
        if (vayChrData->count == 0x10) {
            next = 1;
            vayChrData->step = 2;
        }
        break;
    case 4:
        ayLevelGoalDraw(data);
        if ((vaySelData->bocount == -1) && (vgmsysPad[0]->trg & 0x10)) {
            nmvcPlayButton(2);
            next = 1;
            vayChrData->step = 5;
        }
        break;
    case 8:
        if ((vayChrData->boCnt != -1) && (vayChrData->boCnt < 0x10)) {
            aySelItemDraw();
            ayCsImageDraw();
            ayNameDraw();
        } else {
            ayHandicapDraw();
        }
        if (vayChrData->count == 0x20) {
            next = 1;
            vayChrData->step = 9;
        }
        break;
    case 9:
        ret = ayHandicapDraw();
        break;
    case 10:
        if ((vayChrData->boCnt != -1) && (vayChrData->boCnt < 0x10)) {
            ayHandicapDraw();
        } else {
            aySelItemDraw();
            ayCsImageDraw();
            ayNameDraw();
        }
        if (vayChrData->count == 0x20) {
            next = 1;
            vayChrData->step = 2;
        }
        break;
    case 11:
        aySelItemDraw();
        ayDrawChar();
        aySelBoardDraw();
        ayParamDraw();
        ayNameDraw();
        aySetUpDraw();
        if (count < 0x10) {
            dy = ayCalcTotalMove(0x11, count, 224.0f, 3) - 224.0f;
        } else if (count < 0x15) {
            count -= 0x10;
            dy = -ayCalcTotalMove(6, count, 12.0f, 1);
        } else if (count < 0x1A) {
            count = count - 0x15;
            dy = ayCalcTotalMove(6, count, 12.0f, 3) - 12.0f;
        } else if (count < 0x1D) {
            count -= 0x1A;
            dy = -ayCalcTotalMove(4, count, 6.0f, 1);
        } else {
            count -= 0x1D;
            dy = ayCalcTotalMove(4, count, 6.0f, 3) - 6.0f;
        }
        sploadDrawProfile(vgmsysGifPkt, ch, dy, 1);
        if (vayChrData->count == 1) {
            nmvcPlay(3, 1, 7);
        } else if (vayChrData->count == 0x20) {
            next = 1;
            vayChrData->step = 0xC;
        }
        break;
    case 13:
        aySelItemDraw();
        ayDrawChar();
        aySelBoardDraw();
        ayParamDraw();
        ayNameDraw();
        aySetUpDraw();
        dy = -ayCalcTotalMove(0x11, count, 224.0f, 3);
        sploadDrawProfile(vgmsysGifPkt, ch, dy, 1);
        if (vayChrData->count == 0x10) {
            next = 1;
            vayChrData->step = 1;
        }
        break;
    case 12:
        sploadDrawProfile(vgmsysGifPkt, ch, 0.0f, 1);
        if ((vaySelData->bocount == -1) && (vgmsysPad[player]->trg & 0x10)) {
            nmvcPlayButton(2);
            next = 1;
            vayChrData->step = 0xD;
        }
        break;
    }
    if (vayChrData->loadFlg == 1) {
        fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        ayFontInit(0x10, 0x10, fcol);
        nmfontFPrint(vgmsysGifPkt, load[vspenvGame->language], 0x15E, 0xC8);
    }
    if (vayChrData->loadFlg == 4) {
        vayChrData->loadFlg = 0;
    }
    if (next == 0) {
        vayChrData->count = (vayChrData->count + 1) & 0xFFFFFF;
    } else if (next == 1) {
        vayChrData->count = 0;
    }
    aySetKeyOparate();
    if (vayChrData->boCnt >= 0) {
        vayChrData->boCnt++;
        bocnt = vayChrData->boCnt;
        if (bocnt < 0x10) {
            col = bocnt * 8;
        } else {
            col = 0x80 - (bocnt - 0x10) * 8;
            if (bocnt == 0x20) {
                vayChrData->boCnt = -1;
            }
        }
        ayBlackOutDraw(col);
    }
    count = vaySelData->bocount;
    if (count == 0x1F) {
        switch (vayChrData->charType) {
        case 0:
            sploadFreeSCharacter(vayChrData->chara);
            break;
        case 2:
            sploadFreeSCharacter(vayChrData->chara - 10);
            break;
        }
    }
    return ret;
}

void ayCharSelEnd(void) {
    ulFree(vayChrData);
}

void ayCharSelClear() {
    signed int board; // r16
    signed int ii; // r17
    signed int jj; // r18

    vayChrData->count = 0;
    vayChrData->boCnt = -1;
    vayChrData->rollCnt = 0;
    vayChrData->step = 0;
    vayChrData->padCnt = -1;
    vayChrData->moveCnt = -1;
    vayChrData->moveDir = 0;
    vayChrData->charMove = 0;
    vayChrData->select = 0;
    if (vaySelData->mode == 2) {
        vayChrData->chara = 0;
        vayChrData->charType = 0;
        for (ii = 0; ii < 0x16; ii++) {
            vayChrData->wear[ii] = 0;
            vayChrData->board[ii] = 0;
        }
        vayChrData->loadFlg = 1;
    } else {
        if (vspenvSecret->old_char < 0xA) {
            vayChrData->chara = vspenvSecret->old_char;
            vayChrData->charType = 0;
            vayChrData->loadFlg = 1;
        } else if (vspenvSecret->old_char < 0xC) {
            vayChrData->chara = (vspenvSecret->old_char + 0xA);
            vayChrData->charType = 2;
            vayChrData->loadFlg = 1;
        } else {
            vayChrData->chara = (vspenvSecret->old_char - 2);
            vayChrData->charType = 1;
            vayChrData->loadFlg = 0;
        }
        for (ii = 0; ii < 0x16; ii++) {
            vayChrData->wear[ii] = vayCharData[ii]->old_wear_no;
            vayChrData->board[ii] = vayCharData[ii]->old_brd_no;
        }
    }
    for (ii = 0; ii < 0x16; ii++) {
        board = vayCharData[ii]->board;
        for (jj = 1; board >= 2; jj++) {
            board /= 2;
        }
        vayChrData->boardMax[ii] = jj;
    }
    vayChrData->handicap[0] = vayChrData->handicap[1] = 5;
    vayChrData->capAccept[1] = 0;
    vayChrData->capAccept[0] = 0;
    vayChrData->player = 0;
    vayChrData->csFlg = 0;
    vayChrData->csiENo = 0;
    vayChrData->csiNo = 0;
    vayChrData->csCnt = 0;
    vayChrData->course = 0;
    vayChrData->spID = 0;
    vayChrData->motFrame = 0.0f;
    vayChrData->nowMot = 3;
    vayChrData->motFlg = 0;
    vayChrData->charaFlg = 1;
    vayChrData->boardFlg = 1;
}

void ayCalcSoftNum(s32 no) {
    signed int ii; // r16
    vayChrData->soft = 0;
    for (ii = 0; ii < 8; ii++) {
        vayChrData->soft += vayCharData[no]->soft[ii];
    }
}

static void ayDrawChar() {
    signed int count = vayChrData->count; // r23 // s7
    MdlEnv mdlEnv; // 0xA0(r29)
    float mat[4][4]; // 0x1C0(r29)
    float trans[4]; // 0x200(r29)
    float rot[4] = {1.570796f, 0.0f, -1.570796f, 1.0f}; // 0x210(r29)
    float worldScr[16]; // 0x220(r29)
    float scale = 13.0f; // 0x264(r29)
    signed int mcount; // r20 // s4
    signed int select; // r22 // s6
    float acol; // 0x268(r29)
    signed int size; // r21 // s5
    signed int chara; // r16 // s0
    signed int ii; // r17 // s1
    signed int wear; // r19 // s3
    LoadData* data; // r18 // s2

    mcount = vayChrData->moveCnt;
    select = vayChrData->select;
    aySetCamMatrix(worldScr, mdlEnv.world_view[0], mdlEnv.view_screen[0]);
    chara = vayChrData->chara;
    wear = vayChrData->wear[vayChrData->chara];
    switch (vayChrData->step) {
    case 0:
        trans[0] = 115.0f, trans[1] = 120.0f, trans[2] = -53.0f, trans[3] = 1.0f;
        acol = 0.25f;
        break;
    case 1:
    case 0xB:
    case 0xD:
        if (vayChrData->motFlg > 0) {
            mcount = vayChrData->charMove;
            acol = 0.25f;
            if (mcount < 10) {
                if (select == 2) {
                    trans[0] = 161.0f - 5.0f * (float)mcount;
                    trans[1] = 110.0f - 0.8f * (float)mcount;
                    trans[2] = 100.0f - 10.0f * (float)mcount;
                } else {
                    trans[0] = 115.0f - 0.4f * (float)mcount;
                    trans[1] = 120.0f - 1.8f * (float)mcount;
                    trans[2] = -53.0f + 5.3f * (float)mcount;
                }
                vayChrData->charMove++;
            } else {
                trans[0] = 111.0f, trans[1] = 102.0f, trans[2] = 0.0f, trans[3] = 1.0f;
            }
        } else if ((mcount != -1) && (select == 2) && ((vayChrData->moveDir == 10) || (vayChrData->moveDir == -10))) {
            trans[0] = 115.0f + 5.75f * (float)mcount;
            trans[1] = 120.0f - 1.25f * (float)mcount;
            trans[2] = -53.0f + 19.125f * (float)mcount;
            acol = 0.1f;
        } else if ((mcount != -1) && (((select == 0) && ((vayChrData->moveDir == 10) || ((vayChrData->charType == 1) && (vayChrData->moveDir == -10)))) || ((select == 1) && (vayChrData->moveDir == -10)))) {
            trans[0] = 161.0f - 5.75f * (float)mcount;
            trans[1] = 110.0f + 1.25f * (float)mcount;
            trans[2] = 100.0f - 19.125f * (float)mcount;
            acol = 0.25f;
        } else if (select == 2) {
            trans[0] = 161.0f, trans[1] = 110.0f, trans[2] = 100.0f, trans[3] = 1.0f;
            acol = 0.1f;
        } else {
            trans[0] = 115.0f, trans[1] = 120.0f, trans[2] = -53.0f, trans[3] = 1.0f;
            acol = 0.25f;
        }
        if (vayChrData->loadFlg == 1) {
            if (!sploadCheckSCharacter()) {
                if (vayChrData->charType == 2) {
                    sploadSetSCharacter(chara - 10);
                } else {
                    sploadSetSCharacter(chara);
                }
                vayChrData->loadFlg = 0;
                vayChrData->charMove = 0;
            }
        }
        break;
    case 6:
        acol = 0.25f;
        if (count < 9) {
            trans[0] = 111.0f, trans[1] = 102.0f, trans[2] = 0.0f, trans[3] = 1.0f;
        } else {
            trans[0] = 115.0f, trans[1] = 120.0f, trans[2] = -53.0f, trans[3] = 1.0f;
        }
        break;
    case 7:
        if (count < 9) {
            if (vayChrData->select == 2) {
                acol = 0.1f;
                trans[0] = 161.0f, trans[1] = 110.0f, trans[2] = 100.0f, trans[3] = 1.0f;
            } else {
                acol = 0.25f;
                trans[0] = 115.0f, trans[1] = 120.0f, trans[2] = -53.0f, trans[3] = 1.0f;
            }
        } else {
            acol = 0.25f;
            trans[0] = 115.0f, trans[1] = 120.0f, trans[2] = -53.0f, trans[3] = 1.0f;
        }
        break;
    }
    trans[3] = 1.0f;
    if (vayChrData->padCnt != -1) {
        vayChrData->padCnt++;
        if (vayChrData->padCnt > 0x1E) {
            vayChrData->padCnt = -1;
            ii = vayChrData->charType;
            switch (ii) {
            case 0:
                sploadLoadSCharacter(vayChrData->chara);
                vayChrData->loadFlg = 1;
                break;
            case 2:
                sploadLoadSCharacter(vayChrData->chara - 10);
                vayChrData->loadFlg = 1;
                break;
            case 1:
                vayChrData->loadFlg = 0;
                scale = 0.0f;
                break;
            }
        }
    }
    sceVu0UnitMatrix(mat[0]);
    sceVu0RotMatrixX(mat[0], mat[0], rot[0]);
    sceVu0RotMatrixY(mat[0], mat[0], rot[1]);
    sceVu0RotMatrixZ(mat[0], mat[0], rot[2]);
    sceVu0TransMatrix(mat[0], mat[0], trans);
    ul3dScaleMatrixXYZ(mat[0], scale, scale, scale);
    if (vayChrData->charaFlg == 0) {
        acol = acol / 2.0f;
    }
    aySetLightMatrix(mdlEnv.normal_light[0], mdlEnv.light_color[0], acol, 0.2f);
    if (((vayChrData->step != 0) || (vayChrData->count >= 0x20)) && (vayChrData->loadFlg == 0)) {
        switch (vayChrData->charType) {
        case 2:
            if (vayCharData[chara]->secret != 1) {
                break;
            }
            chara = chara - 10;
        case 0:
            data = sploadGetSelectData();
            mdlEnv.fog.enable = 0;
            if (chara == 3) {
                ul3dScaleMatrixXYZ(mat[0], 0.9f, 0.9f, 0.9f);
            } else if ((chara == 4) || (chara == 7)) {
                ul3dScaleMatrixXYZ(mat[0], 0.95f, 0.95f, 0.95f);
            }
            if ((vspenvOption->enable.big_head & vspenvOption->cheats.big_head) && !(vspenvOption->enable.kids & vspenvOption->cheats.kids)) {
                ul3dScaleMatrixXYZ(mat[0], 0.9f, 0.9f, 0.9f);
            }
            if (vspenvOption->enable.metallic & vspenvOption->cheats.metallic) {
                ultexResetTex(data->offset);
                vayChrData->mapTex.tofs = vayChrData->mapTex.cofs = -1;
                ultexTransTexTag(vgmsysGifPkt, data->select_utd, &vayChrData->mapTex, wear + 0x35);
                if ((chara == 4) || (chara == 7)) {
                    ayDrawMotModel(data->character[chara][wear].vmd[0], data->character[chara][wear].seq, &mdlEnv, mat, 2, 1, vayChrData->count);
                } else {
                    ayDrawMotModel(data->character[chara][wear].vmd[0], data->character[chara][wear].seq, &mdlEnv, mat, 2, 0, vayChrData->count);
                }
            } else {
                size = ultexGetNTex(data->character[chara][wear].utd[0].utd);
                for (ii = 0; ii < size; ii++) {
                    ultexTransTexTag(vgmsysGifPkt, data->character[chara][wear].utd[0].utd, data->character[chara][wear].utd[0].tex + ii, ii);
                }
                if ((select == 4) || (select == 7)) {
                    ayDrawMotModel(data->character[chara][wear].vmd[0], data->character[chara][wear].seq, &mdlEnv, mat, 2, 1, vayChrData->count);
                } else {
                    ayDrawMotModel(data->character[chara][wear].vmd[0], data->character[chara][wear].seq, &mdlEnv, mat, 2, 0, vayChrData->count);
                }
                size = ultexGetNTex(data->character[chara][wear].utd[1].utd);
                for (ii = 0; ii < size; ii++) {
                    ultexTransTexTag(vgmsysGifPkt, data->character[chara][wear].utd[1].utd, data->character[chara][wear].utd[1].tex + ii, ii);
                }
            }
            ulgifTermPacket(vgmsysGifPkt);
            ulgifDmaSend(vgmsysGifPkt);
            ulgifDmaWait();
            sceGifPkReset(vgmsysGifPkt);
            ulgraphAlphaSortPacket(vgmsysAbuf);
            ulgraphAlphaDrawPacket(vulsysSystem.DmaGif, vgmsysAbuf);
            ulgifDmaWait();
            vayChrData->motFrame += 80.0f;
            break;
        case 1:
            if (vspenvEnv.mc.secret.create_character[chara - 10].sex == 1) {
                ul3dScaleMatrixXYZ(mat[0], 0.95f, 0.95f, 0.95f);
            }
            if ((vspenvOption->enable.big_head & vspenvOption->cheats.big_head) && !(vspenvOption->enable.kids & vspenvOption->cheats.kids)) {
                ul3dScaleMatrixXYZ(mat[0], 0.9f, 0.9f, 0.9f);
            }
            mdlEnv.fog.enable = 0;
            ayDrawCreateChara(&vspenvEnv.mc.secret.create_character[chara - 10], &mdlEnv, mat, vayChrData->count);
            break;
        }
    }
}

static void aySelBoardDraw() {
    signed int count = vayChrData->count; // r22 // s6
    signed int selFlg = vayChrData->boardFlg; // r23 // s7
    signed int soft[7] = {0, 10, 20, 30, 40, 50, 90}; // 0xA0(r29)
    MdlEnv mdlEnv; // 0xC0(r29)
    float mat[4][4]; // 0x1E0(r29)
    float trans[4]; // 0x220(r29)
    float scale = 13.0f; // 0x280(r29)
    float acol; // 0x284(r29)
    float rot[4] = {1.570796f, 0.0f, -1.570796f, 1.0f}; // 0x230(r29)
    float worldScr[16]; // 0x240(r29)
    signed int mcount; // r16 // s0
    signed int select; // r17 // s1
    signed int chara; // r18 // s2
    signed int boardID; // r19 // s3
    LoadData* data; // r20 // s4
    signed int board; // r21 // s5

    mcount = vayChrData->moveCnt;
    select = vayChrData->select;
    aySetCamMatrix(worldScr, mdlEnv.world_view[0], mdlEnv.view_screen[0]);
    chara = vayChrData->chara;
    board = vayChrData->board[chara];
    switch (vayChrData->step) {
    case 0:
        trans[0] = 10.0f, trans[1] = -14.0f, trans[2] = 102.0f, trans[3] = 1.0f;
        acol = 0.1f;
        break;
    case 1:
    case 0xB:
    case 0xD:
        if (vayChrData->motFlg > 0) {
            acol = 0.4f;
            mcount = vayChrData->charMove;
            if (mcount < 10) {
                trans[0] = 10.0f;
                trans[1] = -14.0f - 0.6f * (float)mcount;
                if (select == 2) {
                    trans[2] = -39.0f + 3.9f * (float)mcount;
                } else {
                    trans[2] = 102.0f - 10.2f * (float)mcount;
                }
            } else {
                trans[0] = 10.0f, trans[1] = -20.0f, trans[2] = 0.0f, trans[3] = 1.0f;
            }
        } else if ((mcount != -1) && (select == 2) && ((vayChrData->moveDir == 10) || (vayChrData->moveDir == -10))) {
            trans[0] = 10.0f;
            trans[1] = -14.0f;
            trans[2] = 102.0f - 17.625f * (float)mcount;
            acol = 0.4f;
        } else if ((mcount != -1) && (((select == 0) && ((vayChrData->moveDir == 10) || ((vayChrData->charType == 1) && (vayChrData->moveDir == -10)))) || ((select == 1) && (vayChrData->moveDir == -10)))) {
            trans[0] = 10.0f;
            trans[1] = -14.0f;
            trans[2] = -39.0f + 17.625f * (float)mcount;
            acol = 0.1f;
        } else if (select == 2) {
            trans[0] = 10.0f, trans[1] = -14.0f, trans[2] = -39.0f, trans[3] = 1.0f;
            acol = 0.4f;
        } else {
            trans[0] = 10.0f, trans[1] = -14.0f, trans[2] = 102.0f, trans[3] = 1.0f;
            acol = 0.1f;
        }
        break;
    case 6:
        if (count < 9) {
            trans[0] = 10.0f, trans[1] = -20.0f, trans[2] = 0.0f, trans[3] = 1.0f;
            acol = 0.4f;
        } else {
            trans[0] = 10.0f, trans[1] = -14.0f, trans[2] = 102.0f, trans[3] = 1.0f;
            acol = 0.1f;
        }
        break;
    case 7:
        if (count < 9) {
            if (select == 2) {
                trans[0] = 10.0f, trans[1] = -14.0f, trans[2] = -39.0f, trans[3] = 1.0f;
                acol = 0.4f;
            } else {
                trans[0] = 10.0f, trans[1] = -14.0f, trans[2] = 102.0f, trans[3] = 1.0f;
                acol = 0.1f;
            }
        } else {
            acol = 0.1f;
            trans[0] = 10.0f, trans[1] = -14.0f, trans[2] = 102.0f, trans[3] = 1.0f;
        }
        break;
    }
    trans[3] = 1.0f;
    if (board == 6) {
        boardID = 0x48;
    } else if (selFlg == 0) {
        boardID = 0x49;
        acol = acol / 2.0f;
    } else if (chara < 10) {
        boardID = board + chara * 6;
    } else if (chara < 0x14) {
        boardID = board + vspenvEnv.mc.secret.create_character[chara - 10].board_type * 6;
    } else {
        boardID = board + (chara - 10) * 6;
    }
    if ((selFlg == 1) && (select == 2) && ((mcount == -1) || (vayChrData->moveDir == 1) || (vayChrData->moveDir == -1))) {
        rot[0] = 1.570796f + 0.020943947f * (float)(vayChrData->rollCnt % 300);
        vayChrData->rollCnt = (vayChrData->rollCnt + 1) & 0xFFFFFF;
        if (!(rot[0] <= 3.141592f)) {
            rot[0] = rot[0] - 6.283184f;
        }
    }
    sceVu0UnitMatrix(mat[0]);
    sceVu0RotMatrixX(mat[0], mat[0], rot[0]);
    sceVu0RotMatrixY(mat[0], mat[0], rot[1]);
    sceVu0RotMatrixZ(mat[0], mat[0], rot[2]);
    sceVu0TransMatrix(mat[0], mat[0], trans);
    ul3dScaleMatrixXYZ(mat[0], scale, scale, scale);
    aySetLightMatrix(mdlEnv.normal_light[0], mdlEnv.light_color[0], acol, 0.1f);
    if (((vayChrData->step != 0) || (vayChrData->count >= 0x20)) && (vayChrData->loadFlg == 0)) {
        data = sploadGetSelectData();
        ultexTransTexTag(vgmsysGifPkt, data->ayboard_utd, data->board_tex, boardID);
        mdlEnv.fog.enable = 0;
        sceGifPkCnt(vgmsysGifPkt, 0, 0, 0);
        sceGifPkReserve(vgmsysGifPkt, ulmdlDrawModelPkt((unsigned int*)vgmsysGifPkt->pCurrent, vgmsysAbuf, &mdlEnv, mat[0], data->board_umd, 1));
        sceGifPkTerminate(vgmsysGifPkt);
    }
}

static void aySelHeadDraw() {
    signed int id; // r16 // s0
    LoadData* loaddata; // r17 // s1
    signed int count; // r18 // s2
    void* addr; // r19 // s3
    AyPolyPkt* poly; // r20 // s4
    AyAlphaPkt* alpha; // r21 // s5
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    Tex texData; // 0x190(r29)
    float dx; // 0x1A4(r29)

    count = vayChrData->count;
    id = 4;
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    switch (vayChrData->step) {
    case 0:
        if (vaySelData->mode == 2) {
            data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
        } else {
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        }
        if (count < 0x20) {
            dx = 640.0f;
        } else if (count < 0x40) {
            dx = 640.0f + ayCalcTotalMove(0x21, count - 0x20, -286.0f, 1);
        } else {
            dx = 354.0f;
        }
        break;
    case 1:
    case 0xB:
    case 0xD:
        if (vaySelData->mode == 2) {
            if (vayChrData->player == 0) {
                data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
            } else {
                data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
            }
        } else {
            data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x40;
        }
        if (vayChrData->boCnt == -1) {
            dx = 354.0f;
        } else if (vayChrData->boCnt < 0x10) {
            dx = 354.0f + ayCalcTotalMove(0x11, vayChrData->boCnt, 286.0f, 3);
        } else {
            dx = 640.0f + ayCalcTotalMove(0x11, vayChrData->boCnt - 0x10, -286.0f, 1);
        }
        break;
    case 6:
    case 7:
        if (vayChrData->player == 0) {
            data.uv[0] = 0, data.uv[1] = 0x40, data.uv[2] = 0x100, data.uv[3] = 0x80;
        } else {
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        }
        if (vayChrData->count < 8) {
            dx = 354.0f + ayCalcTotalMove(9, vayChrData->count, 286.0f, 3);
        } else if (vayChrData->count < 0x10) {
            dx = 640.0f + ayCalcTotalMove(9, vayChrData->count - 8, -286.0f, 1);
        } else {
            dx = 354.0f;
        }
        break;
    case 2:
    case 3:
    case 5:
        data.uv[0] = 0, data.uv[1] = 0xC0, data.uv[2] = 0x100, data.uv[3] = 0x100;
        if (vayChrData->boCnt == -1) {
            dx = 354.0f;
        } else if (vayChrData->boCnt < 0x10) {
            dx = 354.0f + ayCalcTotalMove(0x11, vayChrData->boCnt, 286.0f, 3);
        } else {
            dx = 640.0f + ayCalcTotalMove(0x11, vayChrData->boCnt - 0x10, -286.0f, 1);
        }
        break;
    case 8:
        if (vayChrData->boCnt == -1) {
            id = 5;
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
            dx = 354.0f;
        } else if (vayChrData->boCnt < 0x10) {
            data.uv[0] = 0, data.uv[1] = 0xC0, data.uv[2] = 0x100, data.uv[3] = 0x100;
            dx = 354.0f + ayCalcTotalMove(0x11, vayChrData->boCnt, 286.0f, 3);
        } else {
            id = 5;
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
            dx = 640.0f + ayCalcTotalMove(0x11, vayChrData->boCnt - 0x10, -286.0f, 1);
        }
        break;
    case 0xA:
        if (vayChrData->boCnt == -1) {
            data.uv[0] = 0, data.uv[1] = 0xC0, data.uv[2] = 0x100, data.uv[3] = 0x100;
            dx = 354.0f;
        } else if (vayChrData->boCnt < 0x10) {
            id = 5;
            data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
            dx = 354.0f + ayCalcTotalMove(0x11, vayChrData->boCnt, 286.0f, 3);
        } else {
            data.uv[0] = 0, data.uv[1] = 0xC0, data.uv[2] = 0x100, data.uv[3] = 0x100;
            dx = 640.0f + ayCalcTotalMove(0x11, vayChrData->boCnt - 0x10, -286.0f, 1);
        }
        break;
    case 9:
        id = 5;
        data.uv[0] = 0, data.uv[1] = 0x80, data.uv[2] = 0x100, data.uv[3] = 0xC0;
        dx = 354.0f;
        break;
    }
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, id);
    xy[0] = dx, xy[1] = 5.0f, xy[2] = 256.0f + dx, xy[3] = 37.0f;
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 9);
    alpha = ((AyAlphaPkt*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.texData = &texData;
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    aySetVert(data.vert, xy, 1);
    data.flag = 0x14;
    aySetPolyComFT4(poly, &data, 1);
}

static void aySelItemDraw() {
    unsigned int pad = vgmsysPad[0]->rep; // r30 // fp
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    float xy2[4]; // 0x190(r29)
    signed int uv[4]; // 0x1A0(r29)
    Tex texData[2]; // 0x1B0(r29)
    signed int wrsp[13] = {0xC, 0xE, 0xF, 0x10, 0x12, 0x13, 0x14, 0x15, 0x17, 0x18, 0x19, 0x1B, 0}; // 0x1D0(r29)
    AyAlphaPkt* alpha; // 0x208(r29)
    void* addr; // 0x20C(r29)
    signed int count; // r16 // s0
    LoadData* loaddata; // r17 // s1
    signed int col; // r18 // s2
    signed int kind; // r19 // s3
    signed int tmp; // r20 // s4
    signed int select; // r21 // s5
    signed int id; // r22 // s6
    AyPolyPkt* poly; // r23 // s7

    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData[0].tofs = texData[1].tofs = -1;
    texData[0].cofs = texData[1].cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[0], 3);
    kind = 0;
    switch (vayChrData->step) {
    case 0:
        count = vayChrData->count - 0x20;
        if (count < 0) {
            col = 0;
        } else if (count < 0x20) {
            col = count * 4;
        } else {
            col = 0x80;
        }
        break;
    case 1:
    case 0xB:
    case 0xD:
        if ((vayChrData->moveCnt != -1) && ((vayChrData->moveDir == -10) || (vayChrData->moveDir == 10))) {
            count = vayChrData->moveCnt;
            if (count < 4) {
                if (vayChrData->charType == 1) {
                    if (vayChrData->select == 0) {
                        select = 2;
                    } else {
                        select = 0;
                    }
                } else {
                    select = ayCalcNextID(vayChrData->select, 3, -vayChrData->moveDir / 10);
                }
                col = 0x80 - count * 31;
            } else {
                select = vayChrData->select;
                col = (count - 4) * 31;
            }
        } else {
            select = vayChrData->select;
            col = 0x80;
        }
        switch (select) {
        case 0:
            kind = 0;
            if ((vayChrData->moveCnt != -1) && ((vayChrData->moveDir == -1) || (vayChrData->moveDir == 1))) {
                count = vayChrData->moveCnt;
                if (count < 4) {
                    tmp = 0x80 - count * 31;
                } else {
                    tmp = (count - 4) * 31;
                }
                if (tmp < col) {
                    col = tmp;
                }
            }
            break;
        case 1:
            kind = 1;
            if ((vayChrData->chara == 0) || (vayChrData->chara == 3) || (vayChrData->chara == 7) || (vayChrData->chara == 0x14)) {
                count = vayChrData->count % 0xBC;
                select = vayChrData->motFlg;
                if (select == 0) {
                    if (count < 0xB4) {
                        tmp = 0x80;
                    } else if (count < 0xB8) {
                        tmp = 0x80 - (count - 0xB4) * 32;
                    } else {
                        if (count == 0xB8) {
                            vayChrData->spID ^= 1;
                        }
                        tmp = (count - 0xB8) * 32;
                    }
                } else {
                    tmp = 0x80;
                }
                if (tmp < col) {
                    col = tmp;
                }
            }
            switch (vayChrData->charType) {
            case 0:
                ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->spID + wrsp[vayChrData->chara]);
                break;
            case 2:
                ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->spID + wrsp[vayChrData->chara - 10]);
                break;
            }
            break;
        case 2:
            kind = 1;
            switch (vayChrData->charType) {
            case 0:
                ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->chara);
                break;
            case 1:
                ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vspenvEnv.mc.secret.create_character[vayChrData->chara - 10].board_type);
                break;
            case 2:
                ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->chara - 10);
                break;
            }
            break;
        }
        break;
    case 2:
        select = vaySelData->mode;
        if (select == 2) {
            pad |= vgmsysPad[1]->rep;
        }
        if (vayChrData->moveCnt == -1) {
            if ((vaySelData->bocount == -1) && (vayChrData->boCnt == -1)) {
                if (pad & 0x8000) {
                    nmvcPlayCursor(1);
                    vayChrData->nextSelect = ayCalcNextID(vayChrData->course, 8, -1);
                    vayChrData->moveCnt = 0;
                    vayChrData->moveDir = -1;
                } else if (pad & 0x2000) {
                    nmvcPlayCursor(1);
                    vayChrData->nextSelect = ayCalcNextID(vayChrData->course, 8, 1);
                    vayChrData->moveCnt = 0;
                    pad = 1;
                    vayChrData->moveDir = pad;
                }
            }
            col = 0x80;
        } else {
            vayChrData->moveCnt++;
            if (vayChrData->moveCnt == 8) {
                count = -1;
                vayChrData->moveCnt = count;
                vayChrData->moveDir = 0;
            } else if (vayChrData->moveCnt == 4) {
                vayChrData->course = vayChrData->nextSelect;
            }
            count = vayChrData->moveCnt;
            if (count < 4) {
                col = 0x80 - count * 31;
            } else {
                col = (count - 4) * 31;
            }
        }
        kind = 2;
        break;
    case 3:
    case 4:
    case 5:
    case 8:
    case 10:
        kind = 2;
        col = 0x80;
        break;
    case 6:
        count = vayChrData->count;
        select = vayChrData->select;
        if (count < 8) {
            col = 0x80 - count * 16;
            switch (select) {
            case 0:
                kind = 0;
                break;
            case 1:
                switch (vayChrData->charType) {
                case 0:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->spID + wrsp[vayChrData->chara]);
                    break;
                case 1:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], wrsp[12]);
                    break;
                case 2:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->spID + wrsp[vayChrData->chara - 10]);
                    break;
                }
                kind = 1;
                break;
            case 2:
                switch (vayChrData->charType) {
                case 0:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->chara);
                    break;
                case 1:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vspenvEnv.mc.secret.create_character[vayChrData->chara - 10].board_type);
                    break;
                case 2:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->chara - 10);
                    break;
                }
                kind = 1;
                break;
            }
        } else {
            if (count < 0x10) {
                col = (count - 8) * 16;
            } else {
                col = 0x80;
            }
            kind = 0;
        }
        break;
    case 7:
        count = vayChrData->count;
        select = vayChrData->select;
        if (count < 8) {
            col = 0x80 - count * 16;
            switch (select) {
            case 0:
                kind = 0;
                break;
            case 1:
                switch (vayChrData->charType) {
                case 0:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->spID + wrsp[vayChrData->chara]);
                    break;
                case 1:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], wrsp[12]);
                    break;
                case 2:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->spID + wrsp[vayChrData->chara - 10]);
                    break;
                }
                kind = 1;
                break;
            case 2:
                switch (vayChrData->charType) {
                case 0:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->chara);
                    break;
                case 1:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vspenvEnv.mc.secret.create_character[vayChrData->chara - 10].board_type);
                    break;
                case 2:
                    ultexTransTexTag(vgmsysGifPkt, loaddata->sponsor_utd, &texData[1], vayChrData->chara - 10);
                    break;
                }
                kind = 1;
                break;
            }
        } else {
            if (count < 0x10) {
                col = (count - 8) * 16;
            } else {
                col = 0x80;
            }
            kind = 0;
        }
        break;
    }
    switch (kind) {
    case 0:
        id = vayChrData->chara;
        switch (vayChrData->charType) {
        case 2:
            id -= 10;
            break;
        case 1:
            id = (vspenvSecret->create_character[id - 10].sex ^ 1) + 0xC;
            break;
        }
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], id / 2 + 0x2E);
        uv[0] = (id % 2) * 128, uv[1] = 0, uv[2] = uv[0] + 0x80, uv[3] = 0x100;
        xy2[0] = 50.0f, xy2[1] = 9.0f, xy2[2] = 128.0f + xy2[0], xy2[3] = 128.0f + xy2[1];
        data.flag = 0x13;
        break;
    case 2:
        tmp = vayChrData->course + 0x3C;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], tmp);
        uv[0] = 0, uv[1] = 0, uv[2] = 0x100, uv[3] = 0x80;
    case 1:
        uv[0] = 0, uv[1] = 0, uv[2] = 0x100, uv[3] = 0x80;
        xy2[0] = -14.0f, xy2[1] = 22.0f, xy2[2] = 242.0f, xy2[3] = 86.0f;
        data.flag = 0x14;
        break;
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);
    alpha = ((AyAlphaPkt*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.texData = &texData[0];
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x100;
    xy[0] = 0.0f, xy[1] = 0.0f, xy[2] = 256.0f, xy[3] = 128.0f;
    data.flag = 0x14;
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    if (kind == 0) {
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(poly + 1, &data, 1);
    } else {
        aySetVert(data.vert, xy, 0xFFFFFE);
        aySetPolyComFT4(poly, &data, 1);
    }
    data.texData = &texData[1];
    data.uv[0] = uv[0], data.uv[1] = uv[1], data.uv[2] = uv[2], data.uv[3] = uv[3];
    if (((kind == 0) && (vayChrData->charaFlg == 0)) || ((kind == 2) && !(vayChrData->csFlg & (1 << vayChrData->course)))) {
        data.rgba[0] = 0x40, data.rgba[1] = 0x40, data.rgba[2] = 0x40, data.rgba[3] = col;
    } else {
        data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = col;
    }
    if (kind == 0) {
        aySetVert(data.vert, xy2, 0xFFFFFE);
        aySetPolyComFT4(poly, &data, 1);
    } else {
        aySetVert(data.vert, xy2, 0xFFFFFF);
        aySetPolyComFT4(poly + 1, &data, 1);
    }
}

static void ayParamDraw() {
    signed int count = vayChrData->moveCnt; // r30 // fp
    AyAlphaPkt* alpha; // 0x268(r29)
    LoadData* loaddata; // 0x26C(r29)
    signed int select = vayChrData->select; // 0x270(r29)
    signed int num; // 0x274(r29)
    signed int total; // 0x278(r29)
    signed int chara; // 0x27C(r29)
    char** paramStr; // 0x280(r29)
    float dx; // 0x284(r29)
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    Tex texData; // 0x190(r29)
    signed int param[5]; // 0x1A0(r29)
    signed int max[5]; // 0x1C0(r29)
    char* paramP[3][5] = {{"ollie", "spin", "speed", "landing", "balance"}, {"Ollie", "Spin", "Tempo", "Landung", "Balance"}, {"ollie", "rotation", "vitesse", "r\223ception", "equilibre"}}; // 0x1E0(r29)
    char* paramB[3][4] = {{"speed", "stability", "balance", "turning"}, {"Tempo", "Stabilit\221t", "Balance", "Drehung"}, {"vitesse", "stabilit\223", "equilibre", "carr\223s"}}; // 0x220(r29)
    signed int fcol[4] = {0x80, 0x80, 0x80, 0x80}; // 0x250(r29)
    signed int col[2]; // 0x260(r29)
    signed int ii; // r16 // s0
    signed int jj; // r17 // s1
    AyPolyPkt4* poly2; // r18 // s2
    void* addr; // r21 // s5
    signed int* tmp; // r22 // s6
    AyPolyPkt* poly; // r23 // s7

    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x39);
    switch (vayChrData->step) {
    case 0:
    case 1:
    case 0xB:
    case 0xD:
        if ((count != -1) && (select == 2) && ((vayChrData->moveDir == 10) || (vayChrData->moveDir == -10))) {
            if (count < 4) {
                select = 0;
                col[0] = col[1] = 0x80 - count * 31;
            } else {
                col[0] = col[1] = (count - 4) * 31;
            }
            break;
        }
        if ((count != -1) && (((select == 0) && ((vayChrData->moveDir == 10) || ((vayChrData->charType == 1) && (vayChrData->moveDir == -10)))) || ((select == 1) && (vayChrData->moveDir == -10)))) {
            if (count < 4) {
                select = 2;
                col[0] = col[1] = 0x80 - count * 31;
            } else {
                col[0] = col[1] = (count - 4) * 31;
            }
            break;
        }
        col[0] = col[1] = 0x80;
        if ((count != -1) && (((select == 0) || (select == 2)) && ((vayChrData->moveDir == -1) || (vayChrData->moveDir == 1)))) {
            if (count < 4) {
                col[1] = 0x80 - count * 31;
            } else {
                col[1] = (count - 4) * 31;
            }
        }
        chara = vayChrData->chara;
        if ((select == 2) && (vayChrData->nextSelect < vayChrData->boardMax[chara]) && (vayChrData->board[chara] < vayChrData->boardMax[chara])) {
            col[1] = 0x80;
        }
        break;
    case 6:
    case 7:
        if (vayChrData->count < 8) {
            col[0] = 0x80 - vayChrData->count * 16;
        } else if (vayChrData->count < 0x10) {
            col[0] = (vayChrData->count - 8) * 16;
        } else {
            col[0] = 0x80;
        }
        col[1] = col[0];
        break;
    }
    data.flag = 0x14;
    data.texData = &texData;
    if (select == 2) {
        num = 4;
        if (vayChrData->boardFlg) {
            switch (vayChrData->charType) {
            case 0:
                tmp = (signed int*)&vsptblBoardParam[vayChrData->chara][vayChrData->boardMax[vayChrData->chara] - 1];
                break;
            case 1:
                tmp = (signed int*)&vsptblBoardParam[vspenvSecret->create_character[vayChrData->chara - 10].board_type][vayChrData->boardMax[vayChrData->chara] - 1];
                break;
            case 2:
                tmp = (signed int*)&vsptblBoardParam[vayChrData->chara - 10][vayChrData->boardMax[vayChrData->chara] - 1];
                break;
            }
        } else {
            switch (vayChrData->charType) {
            case 0:
                tmp = (signed int*)&vsptblBoardParam[vayChrData->chara][vayChrData->board[vayChrData->chara]];
                break;
            case 1:
                tmp = (signed int*)&vsptblBoardParam[vspenvSecret->create_character[vayChrData->chara - 10].board_type][vayChrData->board[vayChrData->chara]];
                break;
            case 2:
                tmp = (signed int*)&vsptblBoardParam[vayChrData->chara - 10][vayChrData->board[vayChrData->chara]];
                break;
            }
        }
        for (ii = 0; ii < 4; ii++) {
            param[ii] = tmp[ii];
            max[ii] = 10;
        }
        total = 0x28;
        paramStr = paramB[vspenvGame->language];
    } else {
        num = 5;
        tmp = (signed int*)&vayCharData[vayChrData->chara]->parameter;
        if (vayChrData->charaFlg) {
            for (ii = 0; ii < 5; ii++) {
                param[ii] = tmp[ii];
            }
        } else {
            for (ii = 0; ii < 5; ii++) {
                param[ii] = 0;
            }
        }
        switch (vayChrData->charType) {
        case 0:
            tmp = vayParamMax[vayChrData->chara];
            break;
        case 1:
            tmp = vayParamMax[10];
            break;
        case 2:
            tmp = vayParamMax[vayChrData->chara - 10];
            break;
        }
        for (ii = 0; ii < 5; ii++) {
            max[ii] = tmp[ii];
        }
        total = tmp[5];
        paramStr = paramP[vspenvGame->language];
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, ((s32)(num * 224 + 0x20) + total * 0x40 + 0xF) >> 4);
    alpha = ((AyAlphaPkt*)addr)++;
    ulpktInitALPHA(alpha, 1);
    fcol[3] = col[0];
    ayFontInit(0x10, 0x14, fcol);
    for (ii = 0; ii < num; ii++) {
        if (vayChrData->step == 0) {
            if (vayChrData->count < ii * 4 + 0x10) {
                dx = -256.0f;
            } else if (vayChrData->count < ii * 4 + 0x20) {
                dx = -256.0f + ayCalcTotalMove(0x11, vayChrData->count - 0x10 - ii * 6, 256.0f, 1);
            } else {
                dx = 0.0f;
            }
        } else {
            dx = 0.0f;
        }
        poly = ((AyPolyPkt*)addr)++;
        data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0x100, data.uv[3] = 0x80;
        data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = col[0];
        xy[0] = dx, xy[1] = 97.0f + 20.0f * (float)ii, xy[2] = 256.0f + dx, xy[3] = 16.0f + xy[1];
        aySetVert(data.vert, xy, 0xFFFFFE);
        aySetPolyComFT4(poly, &data, 1);
        poly = ((AyPolyPkt*)addr)++;
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x20;
        xy[0] = dx, xy[1] = 96.0f + 20.0f * (float)ii, xy[2] = 256.0f + dx, xy[3] = 16.0f + xy[1];
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(poly, &data, 1);
        for (jj = 0; jj < max[ii]; jj++) {
            poly2 = ((AyPolyPkt4*)addr)++;
            if (jj < param[ii]) {
                data.rgba[0] = 0xFF, data.rgba[1] = 0x80, data.rgba[2] = 0x20, data.rgba[3] = col[1];
            } else {
                data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = col[1];
            }
            xy[0] = 156.0f + dx + 8.0f * (float)jj, xy[1] = 101.0f + 20.0f * (float)ii, xy[2] = 5.0f + xy[0], xy[3] = 9.0f + xy[1];
            aySetVert(data.vert, xy, 0xFFFFFF);
            aySetPolyComF4(poly2, &data);
        }
        xy[0] = (120.0f + dx) - (float)nmfontGetPackStrLen(paramStr[ii], 0x10, 0), xy[1] = 198.0f + 40.0f * (float)ii, xy[2] = 16777215.0f, xy[3] = 1.0f;
        nmfontFPrintF(vgmsysGifPkt, paramStr[ii], xy);
    }
}

static void ayCsInfoDraw() {
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    float pos[4]; // 0x190(r29)
    Tex texData; // 0x1A0(r29)
    char* titleList[3][3] = {{"SPONSORS", "LEVEL", "TOTAL"}, {"SPONSOREN", "LEVEL", "GESAMT"}, {"SPONSORS", "NIVEAU", "TOTAL"}}; // 0x1B0(r29)
    char** title = titleList[vspenvGame->language]; // r18 // s2
    signed int fcol[4] = {0x80, 0x80, 0x80, 0x80}; // 0x1E0(r29)
    char str[8]; // 0x1F0(r29)
    AyAlphaPkt* alpha; // 0x1F8(r29)
    signed int ii; // r16 // s0
    AyPolyPkt* poly; // r17 // s1
    void* addr; // r19 // s3
    LoadData* loaddata; // r23 // s7

    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x39);
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x25);
    alpha = ((AyAlphaPkt*)addr)++;
    ulpktInitALPHA(alpha, 1);
    data.texData = &texData;
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    data.flag = 0x14;
    ayFontInit(0x10, 0x14, fcol);
    for (ii = 0; ii < 3; ii++) {
        poly = ((AyPolyPkt*)addr)++;
        xy[0] = 0.0f, xy[1] = 114.0f + 22.0f * (float)ii, xy[2] = 256.0f, xy[3] = 16.0f + xy[1];
        if (ii == 0) {
            data.uv[0] = 0, data.uv[1] = 0x21, data.uv[2] = 0x100, data.uv[3] = 0x40;
            pos[0] = 176.0f - (float)nmfontGetPackStrLen(title[0], 0x10, 0), pos[1] = 236.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
        } else {
            data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0x100, data.uv[3] = 0x80;
        }
        aySetVert(data.vert, xy, 0xFFFFFE);
        aySetPolyComFT4(poly, &data, 1);
        poly = ((AyPolyPkt*)addr)++;
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x20;
        pos[0] = 190.0f, pos[1] = 236.0f + 44.0f * (float)ii, pos[2] = 16777215.0f, pos[3] = 1.0f;
        nmfontFPrintF(vgmsysGifPkt, "/", pos);
        pos[0] = 120.0f - (float)nmfontGetPackStrLen(title[ii], 0x10, 0);
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(poly, &data, 1);
        nmfontSetPack(1);
        nmfontFPrintF(vgmsysGifPkt, title[ii], pos);
        nmfontSetPack(0);
        if (ii == 1) {
            if (vayChrData->moveCnt != -1) {
                if (vayChrData->moveCnt < 4) {
                    fcol[3] = 0x80 - vayChrData->moveCnt * 31;
                } else {
                    fcol[3] = (vayChrData->moveCnt - 4) * 31;
                }
            } else {
                fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            ulstdSprintf(str, "%2d", vayCharData[vayChrData->chara]->soft[vayChrData->course]);
            pos[0] = 156.0f;
            nmfontFPrintF(vgmsysGifPkt, str, pos);
            fcol[3] = 0x80;
            nmfontSetCol(fcol);
            ulstdSprintf(str, "%2d", 9);
            pos[0] = 200.0f;
            nmfontFPrintF(vgmsysGifPkt, str, pos);
        } else if (ii == 2) {
            ulstdSprintf(str, "%2d", vayChrData->soft);
            pos[0] = 156.0f;
            nmfontFPrintF(vgmsysGifPkt, str, pos);
            ulstdSprintf(str, "%2d", 0x48);
            pos[0] = 200.0f;
            nmfontFPrintF(vgmsysGifPkt, str, pos);
        }
    }
}

static void ayCsImageDraw() {
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    Tex texData[3]; // 0x190(r29)
    signed int count = vayChrData->count; // r20 // s4
    signed int mcount = vayChrData->moveCnt; // r30 // fp
    char* mesList[3][4] = {{"SPONSORS", "NEEDED TO UNLOCK:", "UNLOCK IN", "CAREER MODE"}, {"SPONSOREN BEN\222TIGT ZUM", "FREISCHALTEN VON:", "IM KARRIERE-MODUS", "FREISPIELEN"}, {"SPONSORS NECESSAIRESPOUR", "DEVERROUILLER:", "DEVERROUILLER EN", "MODE CARRIERE"}}; // 0x1C0(r29)
    char** mes = mesList[vspenvGame->language]; // r17 // s1
    signed int fcol[4]; // 0x1F0(r29)
    signed int soft[8] = {0, 4, 9, 15, 22, 29, 37, 46}; // 0x200(r29)
    signed int col[3]; // 0x220(r29)
    AyPolyPkt4* poly2; // 0x22C(r29)
    AyAlphaPkt* alpha; // 0x230(r29)
    signed int tmp; // 0x234(r29)
    signed int no; // 0x238(r29)
    char str[4]; // 0x23C(r29)
    LoadData* loaddata; // r22 // s6
    signed int size; // r18 // s2
    signed int ii; // r16 // s0
    void* addr; // r23 // s7
    AyPolyPkt* poly; // r21 // s5

    col[2] = 0x80;
    count = vayChrData->csCnt;
    if (count % 128 == 0) {
        vayChrData->csiENo = vayChrData->course;
        vayChrData->csiNo++;
        if (vayChrData->csiNo == 6) {
            vayChrData->csiNo = 0;
        }
    }
    if ((count / 32) % 4 == 0) {
        count = count % 32;
        col[0] = count * 4;
        col[1] = 0x80 - count * 4;
        size = count;
    } else {
        col[0] = 0x80;
        col[1] = 0;
        size = 0;
    }
    if (mcount != -1) {
        if (mcount < 4) {
            tmp = 0x80 - mcount * 31;
        } else {
            tmp = (mcount - 4) * 31;
        }
        if (tmp < col[0]) {
            col[0] = tmp;
        }
    }
    col[2] = col[0];
    vayChrData->csCnt = (vayChrData->csCnt + 1) & 0xFFFFFF;
    no = vayChrData->csiNo - 1;
    if (no < 0) {
        no = 5;
    }
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    for (ii = 0; ii < 3; ii++) {
        texData[ii].tofs = texData[ii].cofs = -1;
    }
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[0], vayChrData->course * 6 + 0x44 + vayChrData->csiNo);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayChrData->csiENo * 6 + 0x44 + no);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[2], 0x29);
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x22);
    alpha = ((AyAlphaPkt*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly2 = ((AyPolyPkt4*)addr)++;
    data.rgba[0] = 0, data.rgba[1] = 0, data.rgba[2] = 0, data.rgba[3] = col[2];
    xy[0] = 362.0f, xy[1] = 73.0f, xy[2] = 554.0f, xy[3] = 137.0f;
    aySetVert(data.vert, xy, 0xFFFFFF);
    aySetPolyComF4(poly2, &data);
    poly = addr;
    data.flag = 0x14;
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    data.texData = &texData[2];
    for (ii = 0; ii < 2; ii++) {
        data.uv[0] = ii * 32, data.uv[1] = 0x20, data.uv[2] = ii * 32 + 0x20, data.uv[3] = 0x40;
        xy[0] = 302.0f + 256.0f * (float)ii, xy[1] = 91.0f, xy[2] = 32.0f + xy[0], xy[3] = 107.0f;
        aySetVert(data.vert, xy, 0xFFFFFE);
        aySetPolyComFT4(&poly[ii], &data, 1);
    }
    if (vayChrData->csFlg & (1 << vayChrData->course)) {
        data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = col[0];
    } else {
        data.rgba[0] = 0x40, data.rgba[1] = 0x40, data.rgba[2] = 0x40, data.rgba[3] = col[0];
    }
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
    data.texData = &texData[0];
    if (vspenvOption->enable.mirror & vspenvOption->cheats.mirror) {
        xy[0] = 542.0f, xy[1] = 67.0f, xy[2] = 350.0f, xy[3] = 131.0f;
    } else {
        xy[0] = 350.0f, xy[1] = 67.0f, xy[2] = 542.0f, xy[3] = 131.0f;
    }
    aySetVert(data.vert, xy, 0xFFFFFF);
    aySetPolyComFT4(&poly[2], &data, 1);
    data.texData = &texData[1];
    if (vayChrData->csFlg & (1 << vayChrData->csiENo)) {
        data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = col[1];
    } else {
        data.rgba[0] = 0x40, data.rgba[1] = 0x40, data.rgba[2] = 0x40, data.rgba[3] = col[1];
    }
    if (vspenvOption->enable.mirror & vspenvOption->cheats.mirror) {
        xy[0] = 542.0f + (float)size, xy[1] = 67.0f - (float)size / 2.0f, xy[2] = 350.0f - (float)size, xy[3] = 131.0f + (float)size / 2.0f;
    } else {
        xy[0] = 350.0f - (float)size, xy[1] = 67.0f - (float)size / 2.0f, xy[2] = 542.0f + (float)size, xy[3] = 131.0f + (float)size / 2.0f;
    }
    aySetVert(data.vert, xy, 0xFFFFFF);
    aySetPolyComFT4(&poly[3], &data, 1);
    if (!(vayChrData->csFlg & (1 << vayChrData->course))) {
        fcol[0] = 0x20, fcol[1] = 0x4C, fcol[2] = 0x70, fcol[3] = col[2];
        ayFontInit(0x14, 0x18, fcol);
        if ((vaySelData->mode == 0) || (vaySelData->mode == 1)) {
            nmfontFPrint(vgmsysGifPkt, mes[0], 0x1C0 - nmfontGetPackStrLen(mes[0], 0x14, 0) / 2, 0xA0);
            nmfontFPrint(vgmsysGifPkt, mes[1], 0x1C0 - nmfontGetPackStrLen(mes[1], 0x14, 0) / 2, 0xBE);
            ulstdSprintf(str, "%d", soft[vayChrData->course]);
            nmfontFPrint(vgmsysGifPkt, str, 0x1C0 - nmfontGetPackStrLen(str, 0x14, 0) / 2, 0xDC);
        } else {
            nmfontFPrint(vgmsysGifPkt, mes[2], 0x1C0 - nmfontGetPackStrLen(mes[2], 0x14, 0) / 2, 0xA0);
            nmfontFPrint(vgmsysGifPkt, mes[3], 0x1C0 - nmfontGetPackStrLen(mes[3], 0x14, 0) / 2, 0xBE);
        }
    }
}

static void aySetUpDraw() {
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    Tex texData; // 0x190(r29)
    signed int col[3]; // 0x1A0(r29)
    AyPolyPkt* poly; // 0x1B0(r29)
    AyAlphaPkt* alpha; // 0x1B4(r29)
    void* addr; // 0x1B8(r29)
    LoadData* loaddata; // 0x1BC(r29)
    signed int tmp; // 0x1C0(r29)
    signed int ii; // r16 // s0
    signed int chara; // r17 // s1
    signed int count; // r18 // s2
    AyPolyPkt3* poly3; // r19 // s3
    signed int player; // r30 // fp

    count = vayChrData->moveCnt;
    player = vayChrData->player;
    chara = vayChrData->chara;
    if (vayChrData->step == 0) {
        count = vayChrData->count - 0x20;
        for (ii = 0; ii < 3; ii++) {
            if (count < ii * 4) {
                col[ii] = 0;
            } else if (count < ii * 4 + 0x10) {
                col[ii] = (count - ii * 4) * 8;
            } else {
                col[ii] = 0x80;
            }
        }
    } else {
        for (ii = 0; ii < 3; ii++) {
            col[ii] = 0x80;
        }
        if ((vayChrData->step == 1) && (vaySelData->bocount == -1)) {
            if (vayChrData->moveCnt == -1) {
                if ((vayChrData->loadFlg != 1) && (vayChrData->motFlg == 0)) {
                    if ((vgmsysPad[player]->rep & 0x4000) && (vayChrData->loadFlg == 0)) {
                        if (vayChrData->boardFlg && vayChrData->charaFlg) {
                            nmvcPlayCursor(1);
                            vayChrData->select = ayCalcNextID(vayChrData->select, 3, 1);
                            if ((vayChrData->charType == 1) && (vayChrData->select == 1)) {
                                vayChrData->select = 2;
                            }
                            vayChrData->moveCnt = 0;
                            vayChrData->rollCnt = 0;
                            vayChrData->moveDir = 10;
                        } else {
                            nmvcPlayButton(3);
                        }
                    } else if ((vgmsysPad[player]->rep & 0x1000) && (vayChrData->loadFlg == 0)) {
                        if (vayChrData->boardFlg && vayChrData->charaFlg) {
                            nmvcPlayCursor(1);
                            vayChrData->select = ayCalcNextID(vayChrData->select, 3, -1);
                            if ((vayChrData->charType == 1) && (vayChrData->select == 1)) {
                                vayChrData->select = 0;
                            }
                            vayChrData->moveCnt = 0;
                            vayChrData->rollCnt = 0;
                            vayChrData->moveDir = -10;
                        } else {
                            nmvcPlayButton(3);
                        }
                    } else if (vgmsysPad[player]->rep & 0x8000) {
                        nmvcPlayCursor(1);
                        switch (vayChrData->select) {
                        case 0:
                            vayChrData->nextSelect = ayCalcCharNext(chara, -1);
                            vayChrData->moveCnt = 0;
                            vayChrData->padCnt = 0;
                            break;
                        case 1:
                            if (vayChrData->charType == 2) {
                                vayChrData->wear[chara] ^= 1;
                            } else {
                                vayChrData->wear[chara] = ayCalcNextID(vayChrData->wear[chara], 3, -1);
                            }
                            if (player == 1) {
                                if (vayChrData->charType == 2) {
                                    if ((chara - 10 == vspenvEnv.game.character[0].no) && (vayChrData->wear[chara] == vspenvEnv.game.character[0].wear)) {
                                        vayChrData->wear[chara] ^= 1;
                                    }
                                } else if ((chara == vspenvEnv.game.character[0].no) && (vayChrData->wear[chara] == vspenvEnv.game.character[0].wear)) {
                                    vayChrData->wear[chara] = ayCalcNextID(vayChrData->wear[chara], 3, -1);
                                }
                            }
                            break;
                        case 2:
                            vayChrData->nextSelect = ayCalcNextID(vayChrData->board[chara], 7, -1);
                            if ((vayChrData->nextSelect == 6) && !((1 << vayChrData->nextSelect) & vayCharData[chara]->board)) {
                                vayChrData->nextSelect = 5;
                            }
                            vayChrData->moveCnt = 0;
                            vayChrData->moveDir = -1;
                            break;
                        }
                    } else if (vgmsysPad[player]->rep & 0x2000) {
                        nmvcPlayCursor(1);
                        switch (vayChrData->select) {
                        case 0:
                            vayChrData->nextSelect = ayCalcCharNext(chara, 1);
                            vayChrData->moveCnt = 0;
                            vayChrData->padCnt = 0;
                            break;
                        case 1:
                            if (vayChrData->charType == 2) {
                                vayChrData->wear[chara] ^= 1;
                            } else {
                                vayChrData->wear[chara] = ayCalcNextID(vayChrData->wear[chara], 3, 1);
                            }
                            if (player == 1) {
                                if (vayChrData->charType == 2) {
                                    if ((chara - 10 == vspenvEnv.game.character[0].no) && (vayChrData->wear[chara] == vspenvEnv.game.character[0].wear)) {
                                        vayChrData->wear[chara] ^= 1;
                                    }
                                } else if ((chara == vspenvEnv.game.character[0].no) && (vayChrData->wear[chara] == vspenvEnv.game.character[0].wear)) {
                                    vayChrData->wear[chara] = ayCalcNextID(vayChrData->wear[chara], 3, 1);
                                }
                            }
                            break;
                        case 2:
                            vayChrData->nextSelect = ayCalcNextID(vayChrData->board[chara], 7, 1);
                            vayChrData->moveCnt = 0;
                            if ((vayChrData->nextSelect == 6) && !((1 << vayChrData->nextSelect) & vayCharData[chara]->board)) {
                                vayChrData->nextSelect = 0;
                            }
                            vayChrData->moveDir = 1;
                            break;
                        }
                    }
                }
            } else {
                vayChrData->moveCnt++;
                if (vayChrData->moveCnt == 8) {
                    vayChrData->moveCnt = -1;
                    vayChrData->moveDir = 0;
                } else if (vayChrData->moveCnt == 4) {
                    if ((vayChrData->moveDir == -1) || (vayChrData->moveDir == 1)) {
                        if (vayChrData->select == 0) {
                            if (vayChrData->loadFlg == 0) {
                                switch (vayChrData->charType) {
                                case 0:
                                    sploadFreeSCharacter(chara);
                                    break;
                                case 2:
                                    sploadFreeSCharacter(chara - 10);
                                    break;
                                }
                            }
                            tmp = vayChrData->chara;
                            vayChrData->chara = vayChrData->nextSelect;
                            vayChrData->nextSelect = tmp;
                            vayChrData->charType = ayClassifyChara(vayChrData->chara);
                            vayChrData->loadFlg = 3;
                            vayChrData->charaFlg = vayCharData[vayChrData->chara]->secret;
                            vayChrData->spID = 0;
                        } else if (vayChrData->select == 2) {
                            tmp = vayChrData->board[chara];
                            vayChrData->board[chara] = vayChrData->nextSelect;
                            vayChrData->nextSelect = tmp;
                            if ((1 << vayChrData->board[chara]) & vayCharData[chara]->board) {
                                vayChrData->boardFlg = 1;
                            } else {
                                vayChrData->boardFlg = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x38);
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x21);
    alpha = ((AyAlphaPkt*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    addr = (char*)addr + 0x150;
    poly3 = addr;
    data.flag = 0x13;
    data.texData = &texData;
    for (ii = 0; ii < 3; ii++) {
        if (ii == vayChrData->select) {
            data.uv[0] = ii * 0x50, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x50, data.uv[3] = 0x80;
            xy[0] = 528.0f, xy[1] = 76.0f + 52.0f * (float)ii, xy[2] = 540.0f, xy[3] = 8.0f + xy[1];
            aySetPolyComG3(poly3, xy, 0, col[ii]);
            xy[0] = 620.0f, xy[1] = 76.0f + 52.0f * (float)ii, xy[2] = 632.0f, xy[3] = 8.0f + xy[1];
            aySetPolyComG3(poly3 + 1, xy, 1, col[ii]);
        } else {
            data.uv[0] = ii * 0x50, data.uv[1] = 0x80, data.uv[2] = data.uv[0] + 0x50, data.uv[3] = 0x100;
        }
        if ((vayChrData->charType == 1) && (ii == 1)) {
            data.rgba[0] = 0x40, data.rgba[1] = 0x40, data.rgba[2] = 0x40, data.rgba[3] = col[ii];
        } else {
            data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = col[ii];
        }
        xy[0] = 540.0f, xy[1] = 48.0f + 52.0f * (float)ii, xy[2] = 80.0f + xy[0], xy[3] = 64.0f + xy[1];
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(&poly[ii], &data, 1);
    }
}

static void ayNameDraw() {
    signed int fcol[4][4] = {{0x50, 0x6C, 0x78, 0x80}, {0x50, 0x6C, 0x78, 0x80}, {0x20, 0x4C, 0x70, 0x80}, {0x20, 0x4C, 0x70, 0x80}}; // 0xA0(r29)
    float pos[4] = {0.0f, 362.0f, 16777215.0f, 1.0f}; // 0xE0(r29)
    char name[64]; // 0xF0(r29)
    signed int chara = vayChrData->chara; // r23 // s7
    char* stance[2] = {"REGULAR", "GOOFY"}; // 0x1A8(r29)
    signed int id = chara; // r18 // s2
    signed int count = vayChrData->moveCnt; // r21 // s5
    signed int select = vayChrData->select; // r30 // fp
    signed int col = 0x80; // r20 // s4
    signed int soft[7] = {0, 8, 17, 26, 35, 45, 55}; // 0x130(r29)
    char* mesList[3][4] = {{"SPONSORS", "NEEDED TO UNLOCK:", "UNLOCK IN", "CAREER MODE"}, {"SPONSOREN BEN\x92TIGT ZUM", "FREISCHALTEN VON:", "IM KARRIERE-MODUS", "FREISPIELEN"}, {"SPONSORS", "NEEDED TO UNLOCK:", "DEVERROUILLER EN", "MODE CARRIERE"}}; // 0x150(r29)
    char** mes = mesList[vspenvGame->language]; // r22 // s6
    char* place[8] = {"Norden, CA", "Aspen, CO", "Kirkwood, CA", "South Lake Tahoe, CA", "Snowbird, UT", "Tahoe City, CA", "Mt. Hood, OR", "Anaheim, CA"}; // 0x180(r29)
    signed int colFlg; // r19 // s3
    signed int ii; // r16 // s0
    signed int jj; // r17 // s1

    switch (vayChrData->step) {
    case 0:
        if (vayChrData->count < 0x20) {
            col = 0;
        } else if (vayChrData->count < 0x40) {
            col = (vayChrData->count - 0x20) * 4;
        } else {
            col = 0x80;
        }
        switch (vayChrData->charType) {
        case 2:
            id = id - 10;
        case 0:
            ulstdSprintf(name, "%s", vsptblCharacterName[id]);
            colFlg = 1;
            break;
        case 1:
            id = chara - 10;
            ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
            colFlg = 1;
            break;
        }
        break;
    case 1:
    case 0xB:
    case 0xD:
        switch (vayChrData->charType) {
        case 2:
            id = id - 10;
        case 0:
            if ((count != -1) && (select == 2)) {
                if ((vayChrData->moveDir == 10) || (vayChrData->moveDir == -10)) {
                    if (count < 4) {
                        ulstdSprintf(name, "%s", vsptblCharacterName[id]);
                        col = 0x80 - count * 31;
                        colFlg = 1;
                    } else {
                        ulstdSprintf(name, "%s", vsptblBoardName[id][vayChrData->board[chara]]);
                        col = (count - 4) * 31;
                        colFlg = 0;
                    }
                } else {
                    ulstdSprintf(name, "%s", vsptblBoardName[id][vayChrData->board[chara]]);
                    if (count < 4) {
                        col = 0x80 - count * 31;
                    } else {
                        col = (count - 4) * 31;
                    }
                    colFlg = 0;
                }
            } else if ((count != -1) && (((select == 0) && (vayChrData->moveDir == 10)) || ((select == 1) && (vayChrData->moveDir == -10)))) {
                if (count < 4) {
                    ulstdSprintf(name, "%s", vsptblBoardName[id][vayChrData->board[chara]]);
                    colFlg = 0;
                    col = 0x80 - count * 31;
                } else {
                    ulstdSprintf(name, "%s", vsptblCharacterName[id]);
                    colFlg = 1;
                    col = (count - 4) * 31;
                }
            } else if ((count != -1) && (select == 0) && ((vayChrData->moveDir == -1) || (vayChrData->moveDir == 1))) {
                ulstdSprintf(name, "%s", vsptblCharacterName[id]);
                if (count < 4) {
                    col = 0x80 - count * 31;
                } else {
                    col = (count - 4) * 31;
                }
                colFlg = 1;
            } else if (select == 2) {
                ulstdSprintf(name, "%s", vsptblBoardName[id][vayChrData->board[chara]]);
                colFlg = 0;
            } else {
                ulstdSprintf(name, "%s", vsptblCharacterName[id]);
                colFlg = 1;
            }
            break;
        case 1:
            id = chara - 10;
            if ((count != -1) && (select == 2)) {
                if ((vayChrData->moveDir == 10) || (vayChrData->moveDir == -10)) {
                    if (count < 4) {
                        ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
                        col = 0x80 - count * 31;
                        colFlg = 1;
                    } else {
                        ulstdSprintf(name, "%s", vsptblBoardName[vspenvEnv.mc.secret.create_character[id].board_type][vayChrData->board[chara]]);
                        colFlg = 0;
                        col = (count - 4) * 31;
                    }
                } else {
                    ulstdSprintf(name, "%s", vsptblBoardName[vspenvEnv.mc.secret.create_character[id].board_type][vayChrData->board[chara]]);
                    if (count < 4) {
                        col = 0x80 - count * 31;
                    } else {
                        col = (count - 4) * 31;
                    }
                    colFlg = 0;
                }
            } else if ((count != -1) && (select == 0)) {
                if (count < 4) {
                    if ((vayChrData->moveDir == -1) || (vayChrData->moveDir == 1)) {
                        ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
                        col = 0x80 - count * 31;
                        colFlg = 1;
                    } else {
                        ulstdSprintf(name, "%s", vsptblBoardName[vspenvEnv.mc.secret.create_character[id].board_type][vayChrData->board[chara]]);
                        colFlg = 0;
                        col = 0x80 - count * 31;
                    }
                } else {
                    ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
                    col = (count - 4) * 31;
                    colFlg = 1;
                }
            } else if (select == 2) {
                ulstdSprintf(name, "%s", vsptblBoardName[vspenvEnv.mc.secret.create_character[id].board_type][vayChrData->board[chara]]);
                colFlg = 0;
            } else {
                ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
                colFlg = 1;
            }
            break;
        }
        break;
    case 6:
        if (vayChrData->count < 8) {
            col = 0x80 - vayChrData->count * 16;
            switch (vayChrData->charType) {
            case 2:
                id = id - 10;
            case 0:
                if (select == 2) {
                    ulstdSprintf(name, "%s", vsptblBoardName[id][vayChrData->board[chara]]);
                    colFlg = 0;
                } else {
                    ulstdSprintf(name, "%s", vsptblCharacterName[id]);
                    colFlg = 1;
                }
                break;
            case 1:
                id = chara - 10;
                if (select == 2) {
                    ulstdSprintf(name, "%s", vsptblBoardName[vspenvEnv.mc.secret.create_character[id].board_type][vayChrData->board[chara]]);
                    colFlg = 0;
                } else {
                    ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
                    colFlg = 1;
                }
                break;
            }
        } else {
            if (vayChrData->count < 0x10) {
                col = (vayChrData->count - 8) * 16;
            } else {
                col = 0x80;
            }
            ulstdSprintf(name, "%s", vsptblCharacterName[0]);
            colFlg = 1;
        }
        break;
    case 7:
        if (vayChrData->count < 8) {
            col = 0x80 - vayChrData->count * 16;
            switch (vayChrData->charType) {
            case 2:
                id = id - 10;
            case 0:
                if (select == 2) {
                    ulstdSprintf(name, "%s", vsptblBoardName[id][vayChrData->board[chara]]);
                    colFlg = 0;
                } else {
                    ulstdSprintf(name, "%s", vsptblCharacterName[id]);
                    colFlg = 1;
                }
                break;
            case 1:
                id = chara - 10;
                if (select == 2) {
                    ulstdSprintf(name, "%s", vsptblBoardName[vspenvEnv.mc.secret.create_character[id].board_type][vayChrData->board[chara]]);
                    colFlg = 0;
                } else {
                    ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
                    colFlg = 1;
                }
                break;
            }
        } else {
            if (vayChrData->count < 0x10) {
                col = (vayChrData->count - 8) * 16;
            } else {
                col = 0x80;
            }
            switch (vayChrData->charType) {
            case 2:
                id = id - 10;
            case 0:
                ulstdSprintf(name, "%s", vsptblCharacterName[id]);
                break;
            case 1:
                id = chara - 10;
                ulstdSprintf(name, "%s", vspenvEnv.mc.secret.create_character[id].name);
                break;
            }
            colFlg = 1;
        }
        break;
    case 2:
    case 3:
    case 5:
    case 8:
    case 0xA:
        colFlg = 2;
        ulstdSprintf(name, "%s", place[vayChrData->course]);
        if (count != -1) {
            if (count < 4) {
                col = 0x80 - count * 31;
            } else {
                col = (count - 4) * 31;
            }
        } else {
            col = 0x80;
        }
        break;
    }
    if (colFlg == 0) {
        pos[0] = 370.0f - (float)nmfontGetPackStrLen(name, 0x14, 0) / 2.0f;
    } else {
        pos[0] = 400.0f - (float)nmfontGetPackStrLen(name, 0x14, 0) / 2.0f;
    }
    ayFontInitmin();
    nmfontSetType(0);
    nmfontSetSize(0x14, 0x18);
    for (ii = 0; ii < 4; ii++) {
        fcol[ii][3] = col;
    }
    if (((colFlg == 0) && (vayChrData->boardFlg == 0)) || ((colFlg == 1) && (vayChrData->charaFlg == 0)) || ((colFlg == 2) && !(vayChrData->csFlg & (1 << vayChrData->course)))) {
        for (ii = 0; ii < 4; ii++) {
            for (jj = 0; jj < 3; jj++) {
                fcol[ii][jj] /= 2;
            }
        }
    }
    nmfontSetCol(fcol[0]);
    nmfontGPrintF(vgmsysGifPkt, name, pos);
    if ((colFlg == 0) && (vayChrData->boardFlg == 0)) {
        fcol[0][0] = 0x20, fcol[0][1] = 0x4C, fcol[0][2] = 0x70, fcol[0][3] = col;
        ayFontInit(0x14, 0x14, fcol[0]);
        if ((vaySelData->mode == 0) || (vaySelData->mode == 1)) {
            for (ii = 0; ii < 2; ii++) {
                nmfontFPrint(vgmsysGifPkt, mes[ii], 0x145 - (id = nmfontGetPackStrLen(mes[ii], 0x14, 0) / 2), 0xA0 + ii * 24);
            }
            ulstdSprintf(name, "%d", soft[vayChrData->board[vayChrData->chara]]);
            nmfontFPrint(vgmsysGifPkt, name, 0x145 - nmfontGetPackStrLen(name, 0x14, 0) / 2, 0xE8);
        } else {
            for (ii = 0; ii < 2; ii++) {
                nmfontFPrint(vgmsysGifPkt, mes[ii + 2], 0x145 - nmfontGetPackStrLen(mes[ii + 2], 0x14, 0) / 2, 0xA0 + ii * 24);
            }
        }
    }
}

static signed int ayHandicapDraw() {
    signed int count = vayChrData->boCnt; // r23 // s7
    AyPolyPkt3* poly3; // 0x314(r29)
    AyAlphaPkt* alpha; // 0x318(r29)
    void* addr; // 0x31C(r29)
    signed int ret = 0; // 0x320(r29)
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    float pos[4]; // 0x190(r29)
    Tex texData[7]; // 0x1A0(r29)
    char name[2][32]; // 0x210(r29)
    char* strList[3][3] = {{"WAITING FOR", "OTHER PLAYER", "NO CHANGE"}, {"WARTE AUF", "ANDEREN SPIELER", "KEINE \x90NDERUNG"}, {"EN ATTENTE", "D'AUTRES JOUEURS", "AUCUN CHANGEMENT"}}; // 0x250(r29)
    char** str = strList[vspenvGame->language]; // r18 // s2
    signed int fcol[4][4] = {{0x50, 0x6C, 0x78, 0x80}, {0x50, 0x6C, 0x78, 0x80}, {0x20, 0x4C, 0x70, 0x80}, {0x20, 0x4C, 0x70, 0x80}}; // 0x280(r29)
    signed int col[2][4]; // 0x2C0(r29)
    signed int id[2]; // 0x2E0(r29)
    signed int tex[2]; // 0x2E8(r29)
    signed int size[2]; // 0x2F0(r29)
    float dx[3]; // 0x2F8(r29)
    float wxlst[3] = {0.0f, 58.0f, 58.0f}; // 0x308(r29)
    float wx = wxlst[vspenvGame->language]; // 0x324(r29)
    signed int jj; // r17 // s1
    signed int ii; // r16 // s0
    LoadData* loaddata; // r30 // fp
    AyPolyPkt* poly; // r21 // s5
    AyPolyPkt4* poly2; // r22 // s6

    for (ii = 0; ii < 2; ii++) {
        id[ii] = vspenvEnv.game.character[ii].no;
        if (id[ii] < 0xC) {
            ulstdSprintf(name[ii], "%s", vsptblCharacterName[id[ii]]);
            tex[ii] = id[ii];
        } else {
            ulstdSprintf(name[ii], "%s", vspenvEnv.mc.secret.create_character[id[ii] - 0xC].name);
            tex[ii] = (vspenvEnv.mc.secret.create_character[id[ii] - 0xC].sex ^ 1) + 0xC;
        }
    }
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    for (ii = 0; ii < 7; ii++) {
        texData[ii].tofs = -1;
        texData[ii].cofs = -1;
    }
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[0], 2);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 3);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[2], tex[0] / 2 + 0x2E);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[3], tex[1] / 2 + 0x2E);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[4], 0x39);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[5], 0x2C);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[6], 0x2D);
    switch (vayChrData->step) {
    case 8:
        count = count - 0x10;
        for (ii = 0; ii < 3; ii++) {
            if (count == -0x11) {
                dx[ii] = 0.0f;
            } else if (count < ii * 3) {
                dx[ii] = -256.0f;
            } else if (count < ii * 3 + 10) {
                dx[ii] = -256.0f + ayCalcTotalMove(0xB, count - ii * 3, 256.0f, 1);
            } else {
                dx[ii] = 0.0f;
            }
        }
        break;
    case 9:
        for (ii = 0; ii < 3; ii++) {
            dx[ii] = 0.0f;
        }
        if (vaySelData->bocount == -1) {
            for (ii = 0; ii < 2; ii++) {
                if ((vgmsysPad[ii]->rep & 0x8000) && (vayChrData->handicap[ii] > 0) && (vayChrData->capAccept[ii] == 0)) {
                    nmvcPlayCursor(1);
                    vayChrData->handicap[ii]--;
                } else if ((vgmsysPad[ii]->rep & 0x2000) && (vayChrData->handicap[ii] < 10) && (vayChrData->capAccept[ii] == 0)) {
                    nmvcPlayCursor(1);
                    vayChrData->handicap[ii]++;
                } else if (vgmsysPad[ii]->trg & 0x40) {
                    if (vayChrData->capAccept[ii] == 0) {
                        if (vayChrData->capAccept[ii ^ 1] == 1) {
                            vaySelData->vcID = nmvcPlay(3, 1, 6);
                            vspenvEnv.game.mode.handicap[0] = vayChrData->handicap[0];
                            vspenvEnv.game.mode.handicap[1] = vayChrData->handicap[1];
                            if (vspenvEnv.game.mode.match_rule >= 2) {
                                vspenvEnv.game.mode.divide = 0;
                            } else {
                                vspenvEnv.game.mode.divide = vspenvOption->divide;
                            }
                            ayCalcHandiParam();
                            ret = 0xB;
                        } else {
                            nmvcPlayButton(0);
                            vayChrData->capAccept[ii] = 1;
                        }
                    }
                } else if (vgmsysPad[ii]->trg & 0x10) {
                    if (vayChrData->capAccept[ii] == 0) {
                        if (vayChrData->capAccept[ii ^ 1] == 0) {
                            nmvcPlayButton(2);
                            vayChrData->boCnt = 0;
                            vayChrData->step = 0xA;
                            vayChrData->count = -1;
                        }
                    } else {
                        nmvcPlayButton(2);
                        vayChrData->capAccept[ii] = 0;
                    }
                }
            }
        }
        break;
    case 0xA:
        for (ii = 0; ii < 3; ii++) {
            dx[ii] = 0.0f;
        }
        break;
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0xCF);
    alpha = ((AyAlphaPkt*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    addr = (char*)addr + 0x690;
    poly2 = addr;
    addr = (char*)addr + 0x500;
    poly3 = addr;
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    data.texData = &texData[0];
    data.flag = 0x13;
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x100;
    for (ii = 0; ii < 2; ii++) {
        xy[0] = 14.0f + 384.0f * (float)ii, xy[1] = 55.0f, xy[2] = 256.0f + xy[0], xy[3] = 128.0f + xy[1];
        aySetVert(data.vert, xy, 1);
        aySetPolyComFT4(&poly[ii], &data, 1);
    }
    data.flag = 0x13;
    for (ii = 0; ii < 2; ii++) {
        data.uv[0] = (tex[ii] % 2) * 0x80, data.uv[1] = 0, data.uv[2] = data.uv[0] + 0x80, data.uv[3] = 0x100;
        data.texData = &texData[ii + 2];
        if (vayChrData->step == 8) {
            data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = count * 8;
        } else if (vayChrData->capAccept[ii] == 0) {
            data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
        } else {
            data.rgba[0] = 0x40, data.rgba[1] = 0x40, data.rgba[2] = 0x40, data.rgba[3] = 0x80;
            ayFontInitmin();
            nmfontSetSize(0x10, 0x10);
            for (jj = 0; jj < 2; jj++) {
                pos[0] = 128.0f + 384.0f * (float)ii - (float)nmfontGetPackStrLen(str[jj], 0x10, 0) / 2.0f, pos[1] = 202.0f + 16.0f * (float)jj, pos[2] = 16777215.0f, pos[3] = 1.0f;
                nmfontFPrintF(vgmsysGifPkt, str[jj], pos);
            }
        }
        xy[0] = 64.0f + 384.0f * (float)ii, xy[1] = 64.0f, xy[2] = 128.0f + xy[0], xy[3] = 128.0f + xy[1];
        aySetVert(data.vert, xy, 0xFFFFFE);
        aySetPolyComFT4(&poly[ii + 2], &data, 1);
        ayFontInit(0x14, 0x1A, fcol[0]);
        if (ii == 0) {
            pos[0] = 14.0f + dx[0], pos[1] = 308.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
        } else {
            pos[0] = dx[0] + (626.0f - (float)nmfontGetPackStrLen(name[1], 0x14, 0)), pos[1] = 308.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
        }
        nmfontGPrintF(vgmsysGifPkt, name[ii], pos);
    }
    data.texData = &texData[1];
    data.flag = 0x14;
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x100;
    for (ii = 0; ii < 2; ii++) {
        xy[0] = 14.0f + 384.0f * (float)ii, xy[1] = 55.0f, xy[2] = 256.0f + xy[0], xy[3] = 128.0f + xy[1];
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(&poly[ii + 4], &data, 1);
    }
    data.texData = &texData[3];
    data.flag = 0x14;
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    data.uv[0] = 0, data.uv[1] = 0x61, data.uv[2] = 0xFF, data.uv[3] = 0x7F;
    for (ii = 0; ii < 2; ii++) {
        if (ii == 0) {
            xy[0] = dx[1], xy[1] = 170.0f, xy[2] = 256.0f + (xy[0] + wx), xy[3] = 16.0f + xy[1];
        } else {
            xy[0] = 58.0f + (326.0f - dx[1]) - wx, xy[1] = 170.0f, xy[2] = 256.0f + (xy[0] + wx), xy[3] = 16.0f + xy[1];
        }
        aySetVert(data.vert, xy, 0xFFFFFE);
        aySetPolyComFT4(&poly[ii + 6], &data, 1);
    }
    data.uv[0] = 0, data.uv[1] = 0x41, data.uv[2] = 0xD2, data.uv[3] = 0x60;
    for (ii = 0; ii < 2; ii++) {
        if (ii == 0) {
            xy[0] = dx[1] + wx - 58.0f, xy[1] = 169.0f, xy[2] = 210.0f + xy[0], xy[3] = 16.0f + xy[1];
        } else {
            xy[0] = 58.0f + (640.0f - dx[1]) - wx, xy[1] = 169.0f, xy[2] = xy[0] - 210.0f, xy[3] = 16.0f + xy[1];
        }
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(&poly[ii + 8], &data, 1);
    }
    data.uv[0] = 0xEC, data.uv[1] = 0, data.uv[2] = 0xFF, data.uv[3] = 0x1F;
    for (ii = 0; ii < 2; ii++) {
        if (ii == 0) {
            xy[0] = 294.0f + dx[1] + wx - 58.0f, xy[1] = 169.0f, xy[2] = 20.0f + xy[0], xy[3] = 16.0f + xy[1];
        } else {
            xy[0] = 58.0f + (346.0f - dx[1]) - wx, xy[1] = 169.0f, xy[2] = xy[0] - 20.0f, xy[3] = 16.0f + xy[1];
        }
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(&poly[ii + 10], &data, 1);
    }
    xy[0] = 137.0f + (dx[1] + wx), xy[1] = 174.0f, xy[2] = 10.0f + xy[0], xy[3] = 8.0f + xy[1];
    aySetPolyComG3(poly3, xy, 0, 0x80);
    xy[0] = 241.0f + (dx[1] + wx), xy[1] = 174.0f, xy[2] = 10.0f + xy[0], xy[3] = 8.0f + xy[1];
    aySetPolyComG3(poly3 + 1, xy, 1, 0x80);
    xy[0] = 58.0f + (332.0f - dx[1]) - wx, xy[1] = 174.0f, xy[2] = 10.0f + xy[0], xy[3] = 8.0f + xy[1];
    aySetPolyComG3(poly3 + 2, xy, 0, 0x80);
    xy[0] = 58.0f + (436.0f - dx[1]) - wx, xy[1] = 174.0f, xy[2] = 10.0f + xy[0], xy[3] = 8.0f + xy[1];
    aySetPolyComG3(poly3 + 3, xy, 1, 0x80);
    data.texData = &texData[6];
    for (ii = 0; ii < 2; ii++) {
        data.uv[0] = 0, data.uv[1] = ii * 32, data.uv[2] = 0x80, data.uv[3] = data.uv[1] + 0x20;
        if (ii == 0) {
            xy[0] = 64.0f + dx[2], xy[1] = 47.0f, xy[2] = 128.0f + xy[0], xy[3] = 16.0f + xy[1];
        } else {
            xy[0] = 448.0f - dx[2], xy[1] = 47.0f, xy[2] = 128.0f + xy[0], xy[3] = 16.0f + xy[1];
        }
        aySetVert(data.vert, xy, 0xFFFFFF);
        aySetPolyComFT4(&poly[ii + 12], &data, 1);
    }
    data.flag = 0x13;
    data.texData = &texData[5];
    if (vayChrData->step == 8) {
        data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = count * 8;
    } else {
        data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    }
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
    xy[0] = 256.0f, xy[1] = 66.0f, xy[2] = 384.0f, xy[3] = 130.0f;
    aySetVert(data.vert, xy, 0xFFFFFF);
    aySetPolyComFT4(poly + 14, &data, 1);
    col[1][0] = 0x80, col[1][1] = 0x80, col[1][2] = 0x80, col[1][3] = 0x80;
    for (ii = 0; ii < 2; ii++) {
        if (vayChrData->handicap[ii] < 5) {
            size[ii] = 0x14;
            col[0][0] = 0x98, col[0][1] = 0xDE, col[0][2] = 0xFF, col[0][3] = 0x80;
            ulstdSprintf(name[ii], "-%d", 5 - vayChrData->handicap[ii]);
        } else if (vayChrData->handicap[ii] == 5) {
            size[ii] = 0xC;
            col[0][0] = 0xFF, col[0][1] = 0xDD, col[0][2] = 0x95, col[0][3] = 0x80;
            ulstdSprintf(name[ii], str[2]);
        } else {
            size[ii] = 0x14;
            col[0][0] = 0xFF, col[0][1] = 0x83, col[0][2] = 0x2E, col[0][3] = 0x80;
            ulstdSprintf(name[ii], "+%d", vayChrData->handicap[ii] - 5);
        }
        for (jj = 0; jj < 10; jj++) {
            if (ii == 0) {
                xy[0] = 214.0f + dx[1] + 8.0f * (float)jj + wx - 58.0f, xy[1] = 173.0f, xy[2] = 5.0f + xy[0], xy[3] = 9.0f + xy[1];
            } else {
                xy[0] = 58.0f + (350.0f - dx[1] + 8.0f * (float)jj) - wx, xy[1] = 173.0f, xy[2] = 5.0f + xy[0], xy[3] = 9.0f + xy[1];
            }
            if (jj < vayChrData->handicap[ii]) {
                data.rgba[0] = col[0][0], data.rgba[1] = col[0][1], data.rgba[2] = col[0][2], data.rgba[3] = col[0][3];
            } else {
                data.rgba[0] = col[1][0], data.rgba[1] = col[1][1], data.rgba[2] = col[1][2], data.rgba[3] = col[1][3];
            }
            aySetVert(data.vert, xy, 0xFFFFFF);
            aySetPolyComF4(&poly2[ii * 10 + jj], &data);
        }
    }
    ayFontInitmin();
    nmfontSetSize(size[0], 0x14);
    pos[0] = 120.0f + (dx[1] + wx) - (float)nmfontGetPackStrLen(name[0], size[0], 0), pos[1] = 344.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
    nmfontGPrintF(vgmsysGifPkt, name[0], pos);
    nmfontSetSize(size[1], 0x14);
    pos[0] = 520.0f - wx, pos[1] = 344.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
    nmfontGPrintF(vgmsysGifPkt, name[1], pos);
    return ret;
}

static void aySetKeyOparate() {
    LoadData* loaddata; // r19 // s3
    Tex texData; // 0x50(r29)
    signed int flg; // r18 // s2
    signed int count; // r16 // s0
    signed int kind; // r17 // s1

    count = vayChrData->count;
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x28);
    switch (vayChrData->step) {
    case 0:
    case 1:
    case 6:
    case 7:
        flg = 0;
        kind = 5;
        break;
    case 8:
    case 9:
    case 0xA:
        flg = 0;
        kind = 1;
        break;
    case 2:
        flg = 0;
        kind = 2;
        break;
    case 3:
        if (count < 0x10) {
            flg = 1;
            kind = 2;
        } else {
            flg = -1;
            kind = 3;
            count -= 0x10;
        }
        break;
    case 5:
        if (count < 8) {
            count = count * 2;
            flg = 1;
            kind = 3;
        } else {
            flg = -1;
            kind = 2;
            count = (count - 8) * 2;
        }
        break;
    case 4:
    case 0xC:
        kind = 3;
        flg = 0;
        break;
    case 0xB:
        if (count < 0x10) {
            flg = 1;
            kind = 5;
        } else {
            flg = -1;
            kind = 3;
            count -= 0x10;
        }
        break;
    case 0xD:
        if (count < 8) {
            count = count * 2;
            flg = 1;
            kind = 3;
        } else {
            flg = -1;
            kind = 5;
            count = (count - 8) * 2;
        }
        break;
    }
    if ((vaySelData->mode != 0) && (vaySelData->mode != 1) && (kind == 2)) {
        kind = 1;
    }
    if (flg != 10) {
        ayDrawKeyOparate(kind, count, flg, &texData, vgmsysGifPkt);
    }
}

s32 ayClassifyChara(s32 id) {
    if (id < 0xA) {
        return 0;
    }
    if (id < 0x14) {
        return 1;
    }
    if (id < 0x16) {
        return 2;
    }
    return -1;
}

void aySetCharEnv(s32 no) {
    signed int tmp; // r16
    signed int board; // r17

    switch (ayClassifyChara(vayChrData->chara)) {
    case 0:
        tmp = board = vayChrData->chara;
        break;
    case 1:
        tmp = vayChrData->chara + 2;
        board = vspenvEnv.mc.secret.create_character[vayChrData->chara - 0xA].board_type;
        break;
    case 2:
        board = vayChrData->chara - 0xA;
        tmp = board;
        break;
    }
    vspenvEnv.game.character[no].no = tmp;
    vspenvEnv.game.character[no].player = no;
    vspenvEnv.game.character[no].wear = vayChrData->wear[vayChrData->chara];
    vspenvEnv.game.character[no].board = vayChrData->board[vayChrData->chara];
    memcpy(&vspenvEnv.game.character[no].chr_param, &vayCharData[vayChrData->chara]->parameter, 0x1C);
    memcpy(&vspenvEnv.game.character[no].brd_param, &vsptblBoardParam[board][vayChrData->boardMax[vayChrData->chara] - 1], 0x10);
    if (vaySelData->mode != 2) {
        vspenvSecret->old_char = tmp;
        vayCharData[vayChrData->chara]->old_wear_no = vayChrData->wear[vayChrData->chara];
        vayCharData[vayChrData->chara]->old_brd_no = vayChrData->board[vayChrData->chara];
    }
}

void aySetCsFlg() {
    switch (vaySelData->mode) {
    case 0:
    case 1:
        vayChrData->csFlg = vayCharData[vayChrData->chara]->course;
        return;
    case 2:
    case 3:
        vayChrData->csFlg = vspenvSecret->tour_round;
        return;
    }
}

void ayDrawCreateChara(CreatedCharacter* chara, MdlEnv* mdlEnv, float* mat[4], signed int count) {
    signed int metal; // r20 // s4
    CreatedCharacterModel* data; // r17 // s1
    LoadData* seldata; // r19 // s3
    signed int ii; // r16 // s0
    signed int size; // r18 // s2

    seldata = sploadGetSelectData();
    data = &seldata->create_chr[chara->sex];
    metal = 0;
    if (metal) {
        ultexResetTex(seldata->offset);
        vayChrData->mapTex.tofs = vayChrData->mapTex.cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, seldata->select_utd, &vayChrData->mapTex, 0x35);
    } else {
        size = ultexGetNTex(data->face_utd[chara->face]);
        for (ii = 0; ii < size; ii++) {
            ultexTransTexTag(vgmsysGifPkt, data->face_utd[chara->face], data->face_tex[chara->face] + ii, ii);
        }
    }
    ayDrawMotModel(data->face_umd[chara->face], data->face_seq[chara->face], mdlEnv, mat, 0, chara->sex, count);
    if (!metal) {
        size = ultexGetNTex(data->body_utd[chara->body][chara->body_color]);
        if (chara->body == 2) {
            size--;
            if (chara->sex == 0) {
                ultexTransTexTag(vgmsysGifPkt, seldata->cr_arm_utd, data->body_tex[chara->body] + size, chara->face);
            } else {
                ultexTransTexTag(vgmsysGifPkt, seldata->cr_arm_f_utd, data->body_tex[chara->body] + size, chara->face);
            }
        }
        for (ii = 0; ii < size; ii++) {
            ultexTransTexTag(vgmsysGifPkt, data->body_utd[chara->body][chara->body_color], data->body_tex[chara->body] + ii, ii);
        }
    }
    ayDrawMotModel(data->body_umd[chara->body], data->body_seq[chara->body], mdlEnv, mat, 0, chara->sex, count);
    if (!metal) {
        size = ultexGetNTex(data->pants_utd[chara->pants][chara->pants_color]);
        if ((chara->sex == 0) && (chara->body == 2)) {
            size--;
            ultexTransTexTag(vgmsysGifPkt, seldata->cr_leg_utd, data->pants_tex[chara->body] + size, chara->face);
        }
        for (ii = 0; ii < size; ii++) {
            ultexTransTexTag(vgmsysGifPkt, data->pants_utd[chara->pants][chara->pants_color], data->pants_tex[chara->pants] + ii, ii);
        }
    }
    ayDrawMotModel(data->pants_umd[chara->pants], data->pants_seq[chara->pants], mdlEnv, mat, 0, chara->sex, count);
    if (!metal) {
        size = ultexGetNTex(data->glove_utd[chara->glove]);
        for (ii = 0; ii < size; ii++) {
            ultexTransTexTag(vgmsysGifPkt, data->glove_utd[chara->glove], data->glove_tex + ii, ii);
        }
    }
    ayDrawMotModel(data->glove_umd, data->glove_seq, mdlEnv, mat, 0, chara->sex, count);
    if (!metal) {
        size = ultexGetNTex(data->boots_utd[chara->boots]);
        for (ii = 0; ii < size; ii++) {
            ultexTransTexTag(vgmsysGifPkt, data->boots_utd[chara->boots], data->boots_tex + ii, ii);
        }
    }
    ayDrawMotModel(data->boots_umd, data->boots_seq, mdlEnv, mat, 0, chara->sex, count);
    if (!metal) {
        size = ultexGetNTex(data->hair_utd[chara->hair][chara->hair_color][0]);
        for (ii = 0; ii < size; ii++) {
            ultexTransTexTag(vgmsysGifPkt, data->hair_utd[chara->hair][chara->hair_color][0], data->hair_tex[chara->hair][0] + ii, ii);
        }
    }
    ayDrawMotModel(data->hair_umd[chara->hair][0], data->hair_seq[chara->hair], mdlEnv, mat, 1, chara->sex, count);
    if (!metal) {
        size = ultexGetNTex(data->hair_utd[chara->hair][chara->hair_color][1]);
        for (ii = 0; ii < size; ii++) {
            ultexTransTexTag(vgmsysGifPkt, data->hair_utd[chara->hair][chara->hair_color][1], data->hair_tex[chara->hair][1] + ii, ii);
        }
    }
    ulgifTermPacket(vgmsysGifPkt);
    ulgifDmaSend(vgmsysGifPkt);
    ulgifDmaWait();
    sceGifPkReset(vgmsysGifPkt);
    ulgraphAlphaSortPacket(vgmsysAbuf);
    ulgraphAlphaDrawPacket(vulsysSystem.DmaGif, vgmsysAbuf);
    ulgifDmaWait();
    vayChrData->motFrame += 80.0f;
}

static void ayDrawMotModel(__int128* modelData, SeqData* seqData, MdlEnv* mdlEnv, float* mat[4], signed int flg, signed int sex, signed int count) {
    tag_ulcodCOORDINATE coord; // 0x90(r29)
    Vmenv model_env; // 0x120(r29)
    unsigned char motlist[7] = {4, 5, 6, 7, 8, 1, 9}; // 0x288(r29)
    __int128* motData;
    unsigned char motlistK[3] = {4, 5, 1}; // 0x298(r29)
    float ratio; // 0x29C(r29)
    float* f; // r17 // s1
    __int128* mhead; // r19 // s3
    signed int j; // r16 // s0
    signed int i; // r18 // s2
    LoadData* data; // r20 // s4
    unsigned long* pktAddr; // r21 // s5

    data = sploadGetSelectData();
    motData = data->select_uad;
    ulvumdlInitVerShadeWind(&model_env);
    if (vspenvOption->enable.metallic & vspenvOption->cheats.metallic) {
        model_env.enable = 8;
        model_env.envmap.tex0 = ultexGetTEX0(&vayChrData->mapTex);
    } else {
        model_env.enable = 0;
        if (data->env_tex) {
            model_env.envmap.tex0 = ultexGetTEX0(&data->env_tex[3]);
        }
    }
    ulgifTermPacket(vgmsysGifPkt);
    ulgifDmaSend(vgmsysGifPkt);
    ulgifDmaWait();
    switch (vayChrData->motFlg) {
    case 0:
        if (!(vayChrData->motFrame < maGetMdlMotionFrame((unsigned int*)&motData, vayChrData->nowMot))) {
            vayChrData->motFrame = 0.0f;
            if ((count > 0x2D0) && (count < 0x438)) {
                if ((vspenvOption->enable.big_head & vspenvOption->cheats.big_head) && (vspenvOption->enable.kids & vspenvOption->cheats.kids)) {
                    vayChrData->nowMot = motlistK[rand() % 3];
                } else if (sex == 0) {
                    vayChrData->nowMot = motlist[rand() % 7];
                } else {
                    vayChrData->nowMot = motlist[rand() % 6];
                }
                vayChrData->count = 0;
            } else {
                vayChrData->nowMot = 3;
            }
        }
        maMdlMotionDirect((unsigned int*)&motData, seqData, vayChrData->nowMot, vayChrData->motFrame);
        break;
    case 1:
        maMdlMotionRealBrendDirect((unsigned int*)&motData, seqData, 1, vayChrData->nowMot, vayChrData->motFrame, 0.0f);
        if (flg) {
            vayChrData->motFlg = 2;
        }
        break;
    case 2:
        ratio = (0.1f * vayChrData->motFrame) / 80.0f;
        if (!(ratio < 1.0f)) {
            ratio = 1.0f;
            vayChrData->motFlg = 3;
        }
        maMdlMotionRealBrendDirect((unsigned int*)&motData, seqData, 0, vayChrData->nowMot, vayChrData->motFrame, ratio);
        break;
    case 3:
        maMdlMotionDirect((unsigned int*)&motData, seqData, vayChrData->nowMot, vayChrData->motFrame);
        if (!(vayChrData->motFrame < maGetMdlMotionFrame((unsigned int*)&motData, vayChrData->nowMot))) {
            vayChrData->motFlg = 4;
        } else if (!(vayChrData->motFrame < maGetMdlMotionFrame((unsigned int*)&motData, vayChrData->nowMot) - 1280.0f)) {
            if ((vaySelData->mode == 2) && (vayChrData->player == 0)) {
                if (vayChrData->step == 1) {
                    vayChrData->step = 6;
                    vayChrData->count = 0;
                }
            } else if (vayChrData->boCnt == -1) {
                vayChrData->boCnt = 0;
            }
        }
        break;
    case 4:
        maMdlMotionDirect((unsigned int*)&motData, seqData, vayChrData->nowMot, maGetMdlMotionFrame((unsigned int*)&motData, vayChrData->nowMot));
        break;
    case 5:
        if (!(vayChrData->motFrame < maGetMdlMotionFrame((unsigned int*)&motData, vayChrData->nowMot))) {
            vayChrData->motFrame = 0.0f;
            vayChrData->nowMot = 3;
        }
        maMdlMotionDirect((unsigned int*)&motData, seqData, vayChrData->nowMot, vayChrData->motFrame);
        break;
    }
    maVuMdlMotionCtrl(modelData, data->select_uad, seqData, &motData);
    ulcodInitCoordinate(&coord, 0);
    sceVu0CopyMatrix(coord.mat[0], mat[0]);
    coord.flag = 0;
    ulcodSetWvMatrix(mdlEnv->world_view[0]);
    ulcodSetVsMatrix(mdlEnv->view_screen[0]);
    sceVif1PkCnt(vgmsysVif1Pkt, 0);
    mhead = modelData;
    for (i = 0; i < *(signed int*)((char*)mhead + 0xC); i++) {
        if (*(signed int*)(*(char**)((char*)mhead + 0x10) + i * 0x90 + 8) == 0x3E8) {
            f = (float*)(*(char**)((char*)mhead + 0x10) + i * 0x90 + 0x10);
            for (j = 0; j < 16; j++) {
                f[j] = 0.0f;
            }
        }
    }
    ulvumdlDrawModel(vgmsysVif1Pkt, vgmsysAbuf, &coord, mdlEnv->normal_light[0], mdlEnv->light_color[0], modelData, &model_env);
    sceVif1PkEnd(vgmsysVif1Pkt, 0);
    sceVif1PkTerminate(vgmsysVif1Pkt);
    pktAddr = sceVif1PkReserve(vgmsysVif1Pkt, 4);
    *pktAddr++ = 0x70000000;
    *pktAddr++ = 0;
    FlushCache(0);
    vulsysSystem.DmaVif1->chcr.STR = 1;
    sceDmaSync(vulsysSystem.DmaVif1, 0, 0);
    sceDmaSend(vulsysSystem.DmaVif1, vgmsysVif1Pkt->pBase);
    ulvif1DmaWait();
    sceGifPkReset(vgmsysGifPkt);
    sceVif1PkReset(vgmsysVif1Pkt);
}

void aySetMotFlg(s32 mot) {
    vayChrData->motFlg = mot;
}

s32 ayCalcCharNext(s32 now, s32 dir) {
    signed int ret; // r16
    ret = ayCalcNextID(now, 0x16, dir);
    while (0xA <= ret && vayCharData[ret]->secret == 0) {
        ret = ayCalcNextID(ret, 0x16, dir);
    }
    return ret;
}

static void ayLevelGoalDraw(LoadData* loaddata) {
    AyPolyData data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    Tex texData[2]; // 0x190(r29)
    char str[64]; // 0x1B0(r29)
    signed int count = vayChrData->count; // r19 // s3
    char* goalList[3][10] = {{"BOARDER SCORE", "PRO SCORE", "SICK SCORE", "FINISH BEFORE ", " WITH ", "COLLECT THE %s LOGOS", "FIND THE SECRET SPONSOR", "Level Goals", " PTS", " PTS"},
                             {"BOARDER-SCORE", "PROFI-SCORE", "HAMMER-SCORE", "BEENDE UNTER ", " MIT ", "FINDE DIE %s-LOGOS!", "FINDE DEN VERSTECKTEN SPONSOR!", "Levelziele", " PKTE", " PKTE!"},
                             {"SCORE DU SNOWBOARDER", "SCORE PRO", "SCORE DE FOU", "FINIS AVANT ", " AVEC ", "TROUVE LES LOGOS DE %s.", "TROUVE LE SPONSOR SECRET.", "Obj. Niveau", " PTS", " PTS."}}; // 0x1F0(r29)
    signed int fcol[4][4]; // 0x270(r29)
    FData fdata; // 0x2B0(r29)
    float dy; // 0x2C0(r29)
    signed int ii; // r16 // s0
    signed int dx; // r17 // s1
    char** goal; // r18 // s2
    unsigned int level; // r20 // s4
    void* addr; // r21 // s5
    AyPolyPkt* poly; // r22 // s6
    AyAlphaPkt* alpha; // r30 // fp

    goal = goalList[vspenvGame->language];
    ultexResetTex(loaddata->offset);
    for (ii = 0; ii < 2; ii++) {
        texData[ii].tofs = -1;
        texData[ii].cofs = -1;
    }
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[0], 0x3B);
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], vayChrData->course + 0x3C);
    switch (vayChrData->step) {
    case 3:
        if (count < 0x10) {
            dy = ayCalcTotalMove(0x11, count, 224.0f, 3) - 224.0f;
        } else if (count < 0x15) {
            count -= 0x10;
            dy = -ayCalcTotalMove(6, count, 12.0f, 1);
        } else if (count < 0x1A) {
            count -= 0x15;
            dy = ayCalcTotalMove(6, count, 12.0f, 3) - 12.0f;
        } else if (count < 0x1D) {
            count -= 0x1A;
            dy = -ayCalcTotalMove(4, count, 6.0f, 1);
        } else {
            count -= 0x1D;
            dy = ayCalcTotalMove(4, count, 6.0f, 3) - 6.0f;
        }
        break;
    case 4:
        dy = 0.0f;
        break;
    case 5:
        dy = -ayCalcTotalMove(0x11, count, 224.0f, 3);
        break;
    }
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x10);
    alpha = addr;
    addr = (char*)alpha + 0x20;
    ulpktInitALPHA(alpha, 1);
    data.rgba[0] = 0x80, data.rgba[1] = 0x80, data.rgba[2] = 0x80, data.rgba[3] = 0x80;
    data.flag = 0x13;
    poly = addr;
    data.texData = &texData[0];
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x200, data.uv[3] = 0x200;
    xy[0] = 0.0f, xy[1] = dy, xy[2] = 640.0f, xy[3] = 224.0f + dy;
    aySetVert(data.vert, xy, 0xFFFFFF);
    aySetPolyComFT4(poly, &data, 1);
    data.texData = &texData[1];
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x80;
    xy[0] = 192.0f, xy[1] = 140.0f + dy, xy[2] = 448.0f, xy[3] = 204.0f + dy;
    aySetVert(data.vert, xy, 0xFFFFFF);
    aySetPolyComFT4(poly + 1, &data, 1);
    ayFontInitmin();
    nmfontSetType(1);
    nmfontSetSize(0x20, 0x20);
    fcol[0][0] = 0x40, fcol[0][1] = 0x40, fcol[0][2] = 0x80, fcol[0][3] = 0x80;
    fcol[1][0] = 0x40, fcol[1][1] = 0x40, fcol[1][2] = 0x80, fcol[1][3] = 0x80;
    fcol[2][0] = 0x80, fcol[2][1] = 0x80, fcol[2][2] = 0x80, fcol[2][3] = 0x80;
    fcol[3][0] = 0x80, fcol[3][1] = 0x80, fcol[3][2] = 0x80, fcol[3][3] = 0x80;
    nmfontSetCol(fcol[0]);
    nmfontGPrint(vgmsysGifPkt, goal[7], 0x140 - nmfontGetPackStrLen(goal[7], 0x20, 1) / 2, (signed int)(16.0f + 2.0f * dy));
    nmfontSetType(0);
    nmfontSetSize(0x10, 0x10);
    fdata.size = 0x10;
    fcol[0][0] = 0x80, fcol[0][1] = 0x80, fcol[0][2] = 0x80, fcol[0][3] = 0x80;
    fcol[1][0] = 0x40, fcol[1][1] = 0x40, fcol[1][2] = 0x40, fcol[1][3] = 0x80;
    switch (ayClassifyChara(vayChrData->chara)) {
    case 0:
        level = vspenvSecret->character[vayChrData->chara].level_goal[vayChrData->course];
        break;
    case 1:
        level = vspenvSecret->create_character[vayChrData->chara - 10].character.level_goal[vayChrData->course];
        break;
    case 2:
        level = vspenvSecret->character[vayChrData->chara - 10].level_goal[vayChrData->course];
        break;
    }
    for (ii = 0; ii < 9; ii++) {
        if (level & (1 << ii)) {
            nmfontSetCol(fcol[1]);
        } else {
            nmfontSetCol(fcol[0]);
        }
        if (ii < 3) {
            nmfontSetPack(1);
            nmfontFPrint(vgmsysGifPkt, goal[ii], 0x3C, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
            dx = 0x244 - nmfontGetPackStrLen(goal[8], 0x10, 0);
            nmfontFPrint(vgmsysGifPkt, goal[8], dx, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
            fdata.value = vsptblLevelGoalValue[vayChrData->course][ii];
            fdata.dx = (float)dx;
            fdata.dy = 64.0f + 2.0f * dy + (float)(ii * 24);
            ayDrawNum(vgmsysGifPkt, &fdata, 1);
        } else if (ii == 3) {
            nmfontSetPack(1);
            nmfontFPrint(vgmsysGifPkt, goal[3], 0x3C, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
            dx = nmfontGetPackStrLen(goal[3], 0x10, 0) + 0x3C;
            ulstdSprintf(str, "%d", vsptblLevelGoalValue[vayChrData->course][3] / 60);
            nmfontSetPack(0);
            nmfontFPrint(vgmsysGifPkt, str, dx, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
            dx += 0x10;
            nmfontSetPack(1);
            nmfontFPrint(vgmsysGifPkt, ":", dx, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
            dx += nmfontGetPackStrLen(":", 0x10, 0);
            ulstdSprintf(str, "%02d", vsptblLevelGoalValue[vayChrData->course][3] % 60);
            nmfontSetPack(0);
            nmfontFPrint(vgmsysGifPkt, str, dx, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
            dx += 0x20;
            nmfontSetPack(1);
            nmfontFPrint(vgmsysGifPkt, goal[4], dx, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
            dx += nmfontGetPackStrLen(goal[4], 0x10, 0);
            fdata.value = vsptblLevelGoalValue[vayChrData->course][4];
            fdata.dx = (float)dx;
            fdata.dy = 64.0f + 2.0f * dy + (float)(ii * 24);
            dx = ayDrawNum(vgmsysGifPkt, &fdata, 0);
            nmfontSetPack(1);
            nmfontFPrint(vgmsysGifPkt, goal[9], dx, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
        } else if (ii == 4) {
            nmfontSetPack(1);
            ulstdSprintf(str, goal[5], vsptblCourseName[vayChrData->course + 0x10]);
            nmfontFPrint(vgmsysGifPkt, str, 0x3C, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
        } else if (ii == 5) {
            nmfontSetPack(1);
            nmfontFPrint(vgmsysGifPkt, goal[6], 0x3C, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
        } else {
            nmfontFPrint(vgmsysGifPkt, vsptblLevelGoalStr[vayChrData->course][ii - 6], 0x3C, (signed int)(64.0f + 2.0f * dy + (float)(ii * 24)));
        }
    }
}
