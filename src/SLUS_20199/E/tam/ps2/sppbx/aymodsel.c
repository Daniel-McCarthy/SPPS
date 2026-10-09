#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi
#pragma dont_inline on

// SCE types ///////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));
// Spinit.c dependencies ////////////////////////////////////////

// Size: 0x1C, DWARF: 0xA933E (Equivalent to Parameter (Dwarf: 0xFA5FE))
typedef struct CharacterParameters
{
    signed int ollie; // Offset: 0x0, DWARF: 0xA935A
    signed int spin; // Offset: 0x4, DWARF: 0xA937C
    signed int speed; // Offset: 0x8, DWARF: 0xA939D
    signed int landing; // Offset: 0xC, DWARF: 0xA93BF
    signed int balance; // Offset: 0x10, DWARF: 0xA93E3
    signed int stability; // Offset: 0x14, DWARF: 0xA9407
    signed int stance; // Offset: 0x18, DWARF: 0xA942D
} CharacterParameters;

// Static data /////////////////////////////////////////////////

// aymodsel.c structs //////////////////////////////////////////

// Size: 0x1C, DWARF: 0xFBF0E
typedef struct VayModeDat
{
    signed int count; // Offset: 0x0, DWARF: 0xFBF2A
    signed int step; // Offset: 0x4, DWARF: 0xFBF4C
    signed int next; // Offset: 0x8, DWARF: 0xFBF6D
    signed int mode; // Offset: 0xC, DWARF: 0xFBF8E
    signed int type; // Offset: 0x10, DWARF: 0xFBFAF
    signed int confFlg; // Offset: 0x14, DWARF: 0xFBFD0
    signed int comstep; // Offset: 0x18, DWARF: 0xFBFF4
} VayModeDat;

// Size: 0x60, DWARF: 0xFACDC
typedef struct VakSnowFall
{
    signed int num; // Offset: 0x0, DWARF: 0xFACF8
    signed int count; // Offset: 0x4, DWARF: 0xFAD18
    float mat[4][4]; // Offset: 0x10, DWARF: 0xFAD3A
    float* pos[4]; // Offset: 0x50, DWARF: 0xFAD5C
} VakSnowFall;

// Size: 0x18, DWARF: 0xFC61B
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0xFC637
    signed int month; // Offset: 0x4, DWARF: 0xFC658
    signed int day; // Offset: 0x8, DWARF: 0xFC67A
    signed int hour; // Offset: 0xC, DWARF: 0xFC69A
    signed int minute; // Offset: 0x10, DWARF: 0xFC6BB
    signed int second; // Offset: 0x14, DWARF: 0xFC6DE
} Clock; 

// Size: 0x38, DWARF: 0xF72A4
typedef struct File
{
    // Size: 0x18, DWARF: 0xFC61B
    Clock clock; // Offset: 0x0, DWARF: 0xF72BF
    char name[32]; // Offset: 0x18, DWARF: 0xF72E3
} File;

 // Size: 0x20, DWARF: 0xF6EBC
typedef struct Record
{
    signed int chr_no; // Offset: 0x0, DWARF: 0xF6ED7
    unsigned long score; // Offset: 0x8, DWARF: 0xF6EFA
    char name[16]; // Offset: 0x10, DWARF: 0xF6F1C
} Record;

// Size: 0x4, DWARF: 0xF7355
typedef struct BestTime
{
    unsigned int time; // Offset: 0x0, DWARF: 0xF7370
} BestTime;

// Size: 0x24, DWARF: 0xF790A
typedef struct KeyConfig
{
    signed int vibration; // Offset: 0x0, DWARF: 0xF7926
    signed int spin_l; // Offset: 0x4, DWARF: 0xF794C
    signed int spin_r; // Offset: 0x8, DWARF: 0xF796F
    signed int stance; // Offset: 0xC, DWARF: 0xF7992
    signed int revert; // Offset: 0x10, DWARF: 0xF79B5
    signed int grind; // Offset: 0x14, DWARF: 0xF79D8
    signed int grab; // Offset: 0x18, DWARF: 0xF79FA
    signed int jump; // Offset: 0x1C, DWARF: 0xF7A1B
    signed int flip; // Offset: 0x20, DWARF: 0xF7A3C
} KeyConfig;

// Size: 0x30, DWARF: 0xF92EE
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0xF930A
    signed int always_sp; // Offset: 0x4, DWARF: 0xF932B
    signed int perfect_b; // Offset: 0x8, DWARF: 0xF9351
    signed int super_spin; // Offset: 0xC, DWARF: 0xF9377
    signed int half_g; // Offset: 0x10, DWARF: 0xF939E
    signed int fast_motion; // Offset: 0x14, DWARF: 0xF93C1
    signed int super_speed; // Offset: 0x18, DWARF: 0xF93E9
    signed int big_head; // Offset: 0x1C, DWARF: 0xF9411
    signed int metallic; // Offset: 0x20, DWARF: 0xF9436
    signed int mirror; // Offset: 0x24, DWARF: 0xF945B
    signed int replay_view; // Offset: 0x28, DWARF: 0xF947E
    signed int partition; // Offset: 0x2C, DWARF: 0xF94A6
} Cheats;

// Size: 0x48, DWARF: 0xFA01C
typedef struct Bgm //: E:\tam\ps2\sppbx\main.c
{
    signed int table[16]; // Offset: 0x0, DWARF: 0xFA038
    signed int disable; // Offset: 0x40, DWARF: 0xFA05C
    signed int random; // Offset: 0x44, DWARF: 0xFA080
} Bgm;

// Size: 0x8, DWARF: 0xF8F5B
typedef struct Volume //: E:\tam\ps2\sppbx\main.c
{
    signed int se; // Offset: 0x0, DWARF: 0xF8F77
    signed int bgm; // Offset: 0x4, DWARF: 0xF8F96
} Volume;

// Size: 0x114, DWARF: 0xFA389
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0xF790A
    KeyConfig key_config[2]; // Offset: 0x0, DWARF: 0xFA3A5
    // Size: 0x30, DWARF: 0xF92EE
    Cheats enable; // Offset: 0x48, DWARF: 0xFA3CE
    // Size: 0x30, DWARF: 0xF92EE
    Cheats cheats; // Offset: 0x78, DWARF: 0xFA3F3
    // Size: 0x8, DWARF: 0xF8F5B
    Volume volume; // Offset: 0xA8, DWARF: 0xFA418
    char name[16]; // Offset: 0xB0, DWARF: 0xFA43D
    signed int divide; // Offset: 0xC0, DWARF: 0xFA460
    signed int tutorial; // Offset: 0xC4, DWARF: 0xFA483
    // Size: 0x48, DWARF: 0xFA01C
    Bgm bgm; // Offset: 0xC8, DWARF: 0xFA4A8
    unsigned int movie; // Offset: 0x110, DWARF: 0xFA4CA
} VspenvOption;

// Size: 0x1C, DWARF: 0xFA5FE
typedef struct Parameter
{
    signed int ollie; // Offset: 0x0, DWARF: 0xFA61A
    signed int spin; // Offset: 0x4, DWARF: 0xFA63C
    signed int speed; // Offset: 0x8, DWARF: 0xFA65D
    signed int landing; // Offset: 0xC, DWARF: 0xFA67F
    signed int balance; // Offset: 0x10, DWARF: 0xFA6A3
    signed int stability; // Offset: 0x14, DWARF: 0xFA6C7
    signed int stance; // Offset: 0x18, DWARF: 0xFA6ED
} Parameter;

// Size: 0x10, DWARF: 0xFAFB4
typedef struct BoardParam
{
    signed int speed; // Offset: 0x0, DWARF: 0xFAFD0
    signed int stability; // Offset: 0x4, DWARF: 0xFAFF2
    signed int balance; // Offset: 0x8, DWARF: 0xFB018
    signed int turning; // Offset: 0xC, DWARF: 0xFB03C
} BoardParam;

// Size: 0x74, DWARF: 0xFADF6
typedef struct Character
{
    signed int secret; // Offset: 0x0, DWARF: 0xFAE12
    unsigned int board; // Offset: 0x4, DWARF: 0xFAE35
    unsigned int course; // Offset: 0x8, DWARF: 0xFAE57
    signed int rem_point; // Offset: 0xC, DWARF: 0xFAE7A
    signed int old_brd_no; // Offset: 0x10, DWARF: 0xFAEA0
    signed int old_wear_no; // Offset: 0x14, DWARF: 0xFAEC7
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0xFAEEF
    signed int soft[8]; // Offset: 0x38, DWARF: 0xFAF18
    // Size: 0x1C, DWARF: 0xFA5FE
    Parameter parameter; // Offset: 0x58, DWARF: 0xFAF3B
} Character;

// Size: 0x3C, DWARF: 0xFB663
typedef struct Character2
{
    signed int no; // Offset: 0x0, DWARF: 0xFB67F
    signed int player; // Offset: 0x4, DWARF: 0xFB69E
    signed int wear; // Offset: 0x8, DWARF: 0xFB6C1
    signed int board; // Offset: 0xC, DWARF: 0xFB6E2
    // Size: 0x1C, DWARF: 0xFA5FE
    Parameter chr_param; // Offset: 0x10, DWARF: 0xFB704
    // Size: 0x10, DWARF: 0xFAFB4
    BoardParam brd_param; // Offset: 0x2C, DWARF: 0xFB72C
} Character2;

// Size: 0xEC, DWARF: 0xFB9ED
typedef struct CreateCharacter
{
    // Size: 0x74, DWARF: 0xFADF6
    Character character; // Offset: 0x0, DWARF: 0xFBA09
    // Size: 0x1C, DWARF: 0xFA5FE
    Parameter init_param; // Offset: 0x74, DWARF: 0xFBA31
    // Size: 0x18, DWARF: 0xFC61B
    Clock clock; // Offset: 0x90, DWARF: 0xFBA5A
    char name[16]; // Offset: 0xA8, DWARF: 0xFBA7E
    signed int age; // Offset: 0xB8, DWARF: 0xFBAA1
    signed int sex; // Offset: 0xBC, DWARF: 0xFBAC1
    signed int face; // Offset: 0xC0, DWARF: 0xFBAE1
    signed int hair; // Offset: 0xC4, DWARF: 0xFBB02
    signed int hair_color; // Offset: 0xC8, DWARF: 0xFBB23
    signed int body; // Offset: 0xCC, DWARF: 0xFBB4A
    signed int body_color; // Offset: 0xD0, DWARF: 0xFBB6B
    signed int pants; // Offset: 0xD4, DWARF: 0xFBB92
    signed int pants_color; // Offset: 0xD8, DWARF: 0xFBBB4
    signed int glove; // Offset: 0xDC, DWARF: 0xFBBDC
    signed int boots; // Offset: 0xE0, DWARF: 0xFBBFE
    signed int board_type; // Offset: 0xE4, DWARF: 0xFBC20
    signed int trick_type; // Offset: 0xE8, DWARF: 0xFBC47
} CreateCharacter;

// Size: 0x8, DWARF: 0xFC40B
typedef struct Course
{
    unsigned long gap; // Offset: 0x0, DWARF: 0xFC427
} Course;

// Size: 0x4, DWARF: 0xFBCBD
typedef struct Course2 //: E:\tam\ps2\sppbx\main.c
{
    signed int no; // Offset: 0x0, DWARF: 0xFBCD9
} Course2;

// Size: 0xEF8, DWARF: 0xFBCFC
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0xFADF6
    Character character[12]; // Offset: 0x0, DWARF: 0xFBD18
    // Size: 0xEC, DWARF: 0xFB9ED
    CreateCharacter create_character[10]; // Offset: 0x570, DWARF: 0xFBD40
    // Size: 0x8, DWARF: 0xFC40B
    Course course[8]; // Offset: 0xEA8, DWARF: 0xFBD6F
    signed int tour_round; // Offset: 0xEE8, DWARF: 0xFBD94
    signed int old_char; // Offset: 0xEEC, DWARF: 0xFBDBB
    signed int first_clear; // Offset: 0xEF0, DWARF: 0xFBDE0
} VspenvSecret;

// Size: 0x1668, DWARF: 0xF77E5
typedef struct MemCard
{
    // Size: 0x38, DWARF: 0xF72A4
    File file; // Offset: 0x0, DWARF: 0xF7800
    // Size: 0x20, DWARF: 0xF6EBC
    Record record[8][6]; // Offset: 0x38, DWARF: 0xF7823
    // Size: 0x4, DWARF: 0xF7355
    BestTime best_time[8]; // Offset: 0x638, DWARF: 0xF7848
    // Size: 0x114, DWARF: 0xFA389
    VspenvOption option; // Offset: 0x658, DWARF: 0xF7870
    // Size: 0xEF8, DWARF: 0xFBCFC
    VspenvSecret secret; // Offset: 0x770, DWARF: 0xF7895
} MemCard;

// Size: 0x1690, DWARF: 0xF7131
typedef struct VaySelData
{
    signed int count; // Offset: 0x0, DWARF: 0xF714C
    signed int bocount; // Offset: 0x4, DWARF: 0xF716E
    signed int step; // Offset: 0x8, DWARF: 0xF7192
    signed int nextMode; // Offset: 0xC, DWARF: 0xF71B3
    signed int mode; // Offset: 0x10, DWARF: 0xF71D8
    // Size: 0x1668, DWARF: 0xF77E5
    MemCard mc; // Offset: 0x18, DWARF: 0xF71F9
    signed int bgmdiff; // Offset: 0x1680, DWARF: 0xF721A
    signed int bgm; // Offset: 0x1684, DWARF: 0xF723E
    signed int vcID; // Offset: 0x1688, DWARF: 0xF725E
    signed int vcTO; // Offset: 0x168C, DWARF: 0xF727F
} VaySelData;

// Size: 0x18, DWARF: 0xFBE30
typedef struct Mode //: E:\tam\ps2\sppbx\main.c
{
    signed int num_player; // Offset: 0x0, DWARF: 0xFBE4C
    signed int game_mode; // Offset: 0x4, DWARF: 0xFBE73
    signed int match_rule; // Offset: 0x8, DWARF: 0xFBE99
    signed int divide; // Offset: 0xC, DWARF: 0xFBEC0
    signed int handicap[2]; // Offset: 0x10, DWARF: 0xFBEE3
} Mode;

// Size: 0xA0, DWARF: 0xFC1AC
typedef struct Game
{
    // Size: 0x4, DWARF: 0xFBCBD
    Course2 course; // Offset: 0x0, DWARF: 0xFC1C8
    // Size: 0x3C, DWARF: 0xFB663
    Character2 character[2]; // Offset: 0x4, DWARF: 0xFC1ED
    // Size: 0x18, DWARF: 0xFBE30
    Mode mode; // Offset: 0x7C, DWARF: 0xFC215
    signed int language; // Offset: 0x94, DWARF: 0xFC238
    signed int ending; // Offset: 0x98, DWARF: 0xFC25D
    signed int bgm_no; // Offset: 0x9C, DWARF: 0xFC280
} Game;

// Size: 0x8, DWARF: 0xF8573
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0xF858F
    signed char lh; // Offset: 0x2, DWARF: 0xF85AF
    signed char lv; // Offset: 0x3, DWARF: 0xF85CE
    signed int analog; // Offset: 0x4, DWARF: 0xF85ED
} PadData;

// Size: 0x2DCEC, DWARF: 0xF9044
typedef struct Replay //: E:\tam\ps2\sppbx\main.c
{
    // Size: 0x38, DWARF: 0xF72A4
    File file; // Offset: 0x0, DWARF: 0xF9060
    signed int pid; // Offset: 0x38, DWARF: 0xF9083
    signed int num_frame; // Offset: 0x3C, DWARF: 0xF90A3
    unsigned int game_time; // Offset: 0x40, DWARF: 0xF90C9
    signed int endrun_frame; // Offset: 0x44, DWARF: 0xF90EF
    // Size: 0x8, DWARF: 0xF8573
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0xF9118
    // Size: 0x24, DWARF: 0xF790A
    KeyConfig key; // Offset: 0x2DB88, DWARF: 0xF913F
    // Size: 0xEC, DWARF: 0xFB9ED
    CreateCharacter character; // Offset: 0x2DBAC, DWARF: 0xF9161
    // Size: 0x30, DWARF: 0xF92EE
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0xF9189
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0xF91AE
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0xF91D1
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0xF91F4
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0xF9218
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0xF923B
    // Size: 0x10, DWARF: 0xFAFB4
    BoardParam brd_param; // Offset: 0x2DCDC, DWARF: 0xF9261
} Replay;

// Size: 0x5D0E0, DWARF: 0xF9CCE
typedef struct VspenvEnv //: E:\tam\ps2\sppbx\main.c
{
    // Size: 0xA0, DWARF: 0xFC1AC
    Game game; // Offset: 0x0, DWARF: 0xF9CEA
    // Size: 0x1668, DWARF: 0xF77E5
    MemCard mc; // Offset: 0xA0, DWARF: 0xF9D0D
    // Size: 0x2DCEC, DWARF: 0xF9044
    Replay replay[2]; // Offset: 0x1708, DWARF: 0xF9D2E
} VspenvEnv;

// Size: 0x10, DWARF: 0xFA2CE
typedef struct VgmsysGifPkt //: E:\tam\ps2\sppbx\main.c
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0xFA2EA
    __int128* pBase; // Offset: 0x4, DWARF: 0xFA312
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0xFA337
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0xFA35E
} VgmsysGifPkt;

// Size: 0x20, DWARF: 0xF86EA
typedef struct PadState
{
    signed int id; // Offset: 0x0, DWARF: 0xF8706
    unsigned int now; // Offset: 0x4, DWARF: 0xF8725
    unsigned int status; // Offset: 0x8, DWARF: 0xF8745
    unsigned int press; // Offset: 0xC, DWARF: 0xF8768
    signed char right_h; // Offset: 0x10, DWARF: 0xF878A
    signed char right_v; // Offset: 0x11, DWARF: 0xF87AE
    signed char left_h; // Offset: 0x12, DWARF: 0xF87D2
    signed char left_v; // Offset: 0x13, DWARF: 0xF87F5
    unsigned char l_right; // Offset: 0x14, DWARF: 0xF8818
    unsigned char l_left; // Offset: 0x15, DWARF: 0xF883C
    unsigned char l_up; // Offset: 0x16, DWARF: 0xF885F
    unsigned char l_down; // Offset: 0x17, DWARF: 0xF8880
    unsigned char r_up; // Offset: 0x18, DWARF: 0xF88A3
    unsigned char r_right; // Offset: 0x19, DWARF: 0xF88C4
    unsigned char r_down; // Offset: 0x1A, DWARF: 0xF88E8
    unsigned char r_left; // Offset: 0x1B, DWARF: 0xF890B
    unsigned char r_1; // Offset: 0x1C, DWARF: 0xF892E
    unsigned char l_1; // Offset: 0x1D, DWARF: 0xF894E
    unsigned char r_2; // Offset: 0x1E, DWARF: 0xF896E
    unsigned char l_2; // Offset: 0x1F, DWARF: 0xF898E
} PadState;

// Size: 0x60, DWARF: 0xFA0A7
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0xF86EA
    PadState now; // Offset: 0x0, DWARF: 0xFA0C3
    // Size: 0x20, DWARF: 0xF86EA
    PadState old; // Offset: 0x20, DWARF: 0xFA0E5
    unsigned int port; // Offset: 0x40, DWARF: 0xFA107
    unsigned int slot; // Offset: 0x44, DWARF: 0xFA128
    unsigned int mode; // Offset: 0x48, DWARF: 0xFA149
    unsigned int trg; // Offset: 0x4C, DWARF: 0xFA16A
    unsigned int rev; // Offset: 0x50, DWARF: 0xFA18A
    unsigned int cnt; // Offset: 0x54, DWARF: 0xFA1AA
    unsigned int rep; // Offset: 0x58, DWARF: 0xFA1CA
    signed int state; // Offset: 0x5C, DWARF: 0xFA1EA
} VgmsysPad;

// Size: 0x10, DWARF: 0xF6D8D
typedef struct TexData
{
    signed short tofs; // Offset: 0x0, DWARF: 0xF6DA8
    signed short cofs; // Offset: 0x2, DWARF: 0xF6DC9
    signed short width; // Offset: 0x4, DWARF: 0xF6DEA
    signed short height; // Offset: 0x6, DWARF: 0xF6E0C
    signed short tw; // Offset: 0x8, DWARF: 0xF6E2F
    signed short th; // Offset: 0xA, DWARF: 0xF6E4E
    signed short image_bit; // Offset: 0xC, DWARF: 0xF6E6D
    signed short clut_bit; // Offset: 0xE, DWARF: 0xF6E93
} TexData;

// Size: 0x20, DWARF: 0xF970E
typedef struct MdlData //: //E:\tam\ps2\sppbx\main.c
{
    float pos[4]; // Offset: 0x0, DWARF: 0xF972A
    float rot[4]; // Offset: 0x10, DWARF: 0xF974C
} MdlData;

// Size: 0x10, DWARF: 0xFB08D
typedef struct PosAddress
{
    unsigned int type; // Offset: 0x0, DWARF: 0xFB0A9
    float frame; // Offset: 0x4, DWARF: 0xFB0CA
    signed short flg; // Offset: 0x8, DWARF: 0xFB0EC
    signed short non; // Offset: 0xA, DWARF: 0xFB10C
    float* data[4]; // Offset: 0xC, DWARF: 0xFB12C
} PosAddress;

// Size: 0xF0, DWARF: 0xF73BB
typedef struct Seq
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0xF73D6
    signed int loop; // Offset: 0x4, DWARF: 0xF73FB
    signed int mode; // Offset: 0x8, DWARF: 0xF741C
    signed int write_flg; // Offset: 0xC, DWARF: 0xF743D
    signed int now_local_id; // Offset: 0x10, DWARF: 0xF7463
    signed int now_top_id; // Offset: 0x14, DWARF: 0xF748C
    signed int next_local_id; // Offset: 0x18, DWARF: 0xF74B3
    signed int next_top_id; // Offset: 0x1C, DWARF: 0xF74DD
    // Size: 0x20, DWARF: 0xF970E
    MdlData* mdl_data; // Offset: 0x20, DWARF: 0xF7505
    float now_frame; // Offset: 0x24, DWARF: 0xF752F
    float next_frame; // Offset: 0x28, DWARF: 0xF7555
    float ratio; // Offset: 0x2C, DWARF: 0xF757C
    // Size: 0x10, DWARF: 0xFB08D
    PosAddress* now_pos_address; // Offset: 0x30, DWARF: 0xF759E
    // Size: 0x10, DWARF: 0xFB08D
    PosAddress* now_rot_address; // Offset: 0x34, DWARF: 0xF75CF
    // Size: 0x10, DWARF: 0xFB08D
    PosAddress* next_pos_address; // Offset: 0x38, DWARF: 0xF7600
    // Size: 0x10, DWARF: 0xFB08D
    PosAddress* next_rot_address; // Offset: 0x3C, DWARF: 0xF7632
    float nowDir[4]; // Offset: 0x40, DWARF: 0xF7664
    float nowTrans[4]; // Offset: 0x50, DWARF: 0xF7689
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0xF76B0
    float pos[4]; // Offset: 0xA0, DWARF: 0xF76D9
    float quat[4]; // Offset: 0xB0, DWARF: 0xF76FB
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0xF771E
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0xF7744
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0xF776A
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0xF7795
    signed int pad[2]; // Offset: 0xE8, DWARF: 0xF77BF
} Seq;

// Size: 0x230, DWARF: 0xFB1A1
typedef struct Ikparam
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
} Ikparam;

// Size: 0x2E0, DWARF: 0xF835E
typedef struct Ctrl //: E:\tam\ps2\sppbx\main.c
{
    float rot[4]; // Offset: 0x0, DWARF: 0xF837A
    float trans[4]; // Offset: 0x10, DWARF: 0xF839C
    float scale[4]; // Offset: 0x20, DWARF: 0xF83C0
    float matrix[4][4]; // Offset: 0x30, DWARF: 0xF83E4
    float revision[4][4]; // Offset: 0x70, DWARF: 0xF8409
    // Size: 0x230, DWARF: 0xFB1A1
    Ikparam ikparam; // Offset: 0xB0, DWARF: 0xF8430
} Ctrl;

// Size: 0x1A0, DWARF: 0xF6C05
typedef struct SCtrl
{
    signed int type; // Offset: 0x0, DWARF: 0xF6C20
    float power; // Offset: 0x4, DWARF: 0xF6C41
    float dir; // Offset: 0x8, DWARF: 0xF6C63
    float cnt; // Offset: 0xC, DWARF: 0xF6C83
    float head[4]; // Offset: 0x10, DWARF: 0xF6CA3
    float preHead[4]; // Offset: 0x20, DWARF: 0xF6CC6
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0xF6CEC
    float g_vector[4]; // Offset: 0x170, DWARF: 0xF6D16
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0xF6D3D
    signed int pad[3]; // Offset: 0x194, DWARF: 0xF6D67
} SCtrl;

// Size: 0x20, DWARF: 0xFC46F
typedef struct Utd
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0xFC48B
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* tex; // Offset: 0x4, DWARF: 0xFC4AE
    signed int ntex; // Offset: 0x8, DWARF: 0xFC4D3
    signed int offset; // Offset: 0xC, DWARF: 0xFC4F4
    signed int block; // Offset: 0x10, DWARF: 0xFC517
    unsigned int* frame; // Offset: 0x14, DWARF: 0xFC539
    signed int res[2]; // Offset: 0x18, DWARF: 0xFC55E
} Utd;

// Size: 0x90, DWARF: 0xF8E77
typedef struct Change //: E:\tam\ps2\sppbx\main.c
{
    float original[4][4]; // Offset: 0x0, DWARF: 0xF8E93
    float original2[4][4]; // Offset: 0x40, DWARF: 0xF8EBA
    float* address[4][4]; // Offset: 0x80, DWARF: 0xF8EE2
    float* address2[4][4]; // Offset: 0x84, DWARF: 0xF8F0B
    signed int pad[2]; // Offset: 0x88, DWARF: 0xF8F35
} Change;

// Size: 0x960, DWARF: 0xF845A
typedef struct Character3 //: E:\tam\ps2\sppbx\main.c
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xF8476
    unsigned char* vmd[2]; // Offset: 0x4, DWARF: 0xF849A
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* seq; // Offset: 0xC, DWARF: 0xF84BC
    // Size: 0x2E0, DWARF: 0xF835E
    Ctrl ctrl[2]; // Offset: 0x10, DWARF: 0xF84E1
    // Size: 0x1A0, DWARF: 0xF6C05
    SCtrl sctrl[2]; // Offset: 0x5D0, DWARF: 0xF8504
    // Size: 0x20, DWARF: 0xFC46F
    Utd utd[2]; // Offset: 0x910, DWARF: 0xF8528
    // Size: 0x90, DWARF: 0xF8E77
    Change* change[2]; // Offset: 0x950, DWARF: 0xF854A
} Character3;

// Size: 0x378, DWARF: 0xF9772
typedef struct CreateCharacter2
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xF978E
    __int128* face_umd[9]; // Offset: 0x4, DWARF: 0xF97B2
    unsigned int* face_utd[9]; // Offset: 0x28, DWARF: 0xF97D9
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* face_tex[9]; // Offset: 0x4C, DWARF: 0xF9800
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* face_seq[9]; // Offset: 0x70, DWARF: 0xF9827
    __int128* hair_umd[4][2]; // Offset: 0x94, DWARF: 0xF984E
    unsigned int* hair_utd[4][4][2]; // Offset: 0xB4, DWARF: 0xF9875
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* hair_tex[4][2]; // Offset: 0x134, DWARF: 0xF989C
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* hair_seq[4]; // Offset: 0x154, DWARF: 0xF98C3
    __int128* body_umd[5]; // Offset: 0x164, DWARF: 0xF98EA
    unsigned int* body_utd[5][9]; // Offset: 0x178, DWARF: 0xF9911
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* body_tex[5]; // Offset: 0x22C, DWARF: 0xF9938
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* body_seq[5]; // Offset: 0x240, DWARF: 0xF995F
    __int128* pants_umd[5]; // Offset: 0x254, DWARF: 0xF9986
    unsigned int* pants_utd[5][8]; // Offset: 0x268, DWARF: 0xF99AE
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* pants_tex[5]; // Offset: 0x308, DWARF: 0xF99D6
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* pants_seq[5]; // Offset: 0x31C, DWARF: 0xF99FE
    __int128* glove_umd; // Offset: 0x330, DWARF: 0xF9A26
    unsigned int* glove_utd[4]; // Offset: 0x334, DWARF: 0xF9A4F
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* glove_tex; // Offset: 0x344, DWARF: 0xF9A77
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* glove_seq; // Offset: 0x348, DWARF: 0xF9AA2
    __int128* boots_umd; // Offset: 0x34C, DWARF: 0xF9ACD
    unsigned int* boots_utd[4]; // Offset: 0x350, DWARF: 0xF9AF6
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* boots_tex; // Offset: 0x360, DWARF: 0xF9B1E
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* boots_seq; // Offset: 0x364, DWARF: 0xF9B49
    __int128* board_umd; // Offset: 0x368, DWARF: 0xF9B74
    unsigned int* board_utd; // Offset: 0x36C, DWARF: 0xF9B9D
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* board_tex; // Offset: 0x370, DWARF: 0xF9BC6
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* board_seq; // Offset: 0x374, DWARF: 0xF9BF1
} CreateCharacter2;

// Size: 0x4B0, DWARF: 0xF6F43
typedef struct Game2
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xF6F5E
    __int128* umd; // Offset: 0x4, DWARF: 0xF6F82
    __int128* smd; // Offset: 0x8, DWARF: 0xF6FA5
    unsigned int* utd; // Offset: 0xC, DWARF: 0xF6FC8
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* tex; // Offset: 0x10, DWARF: 0xF6FEB
    // Size: 0xF0, DWARF: 0xF73BB
    Seq* seq; // Offset: 0x14, DWARF: 0xF7010
    signed int block; // Offset: 0x18, DWARF: 0xF7035
    unsigned int* frame; // Offset: 0x1C, DWARF: 0xF7057
    signed int res; // Offset: 0x20, DWARF: 0xF707C
    // Size: 0x2E0, DWARF: 0xF835E
    Ctrl ctrl; // Offset: 0x30, DWARF: 0xF709C
    // Size: 0x1A0, DWARF: 0xF6C05
    SCtrl sctrl; // Offset: 0x310, DWARF: 0xF70BF
} Game2;

// Size: 0x16720, DWARF: 0xFA7AB
typedef struct LoadData
{
    unsigned int* link[2]; // Offset: 0x0, DWARF: 0xFA7C7
    signed int offset; // Offset: 0x8, DWARF: 0xFA7EA
    unsigned int* env_utd; // Offset: 0xC, DWARF: 0xFA80D
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* env_tex; // Offset: 0x10, DWARF: 0xFA834
    unsigned int* select_utd; // Offset: 0x14, DWARF: 0xFA85D
    unsigned int* selmov_utd; // Offset: 0x18, DWARF: 0xFA887
    unsigned int* sponsor_utd; // Offset: 0x1C, DWARF: 0xFA8B1
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* sponsor_tex; // Offset: 0x20, DWARF: 0xFA8DC
    unsigned int* medal_utd; // Offset: 0x24, DWARF: 0xFA909
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* medal_tex; // Offset: 0x28, DWARF: 0xFA932
    __int128* medal_umd[3]; // Offset: 0x2C, DWARF: 0xFA95D
    __int128* board_umd; // Offset: 0x38, DWARF: 0xFA985
    unsigned char* board_vmd; // Offset: 0x3C, DWARF: 0xFA9AE
    unsigned int* board_utd; // Offset: 0x40, DWARF: 0xFA9D7
    unsigned int* ayboard_utd; // Offset: 0x44, DWARF: 0xFAA00
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* board_tex; // Offset: 0x48, DWARF: 0xFAA2B
    unsigned int* emblem_utd; // Offset: 0x4C, DWARF: 0xFAA56
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* emblem_tex; // Offset: 0x50, DWARF: 0xFAA80
    __int128* emblem_umd[2]; // Offset: 0x54, DWARF: 0xFAAAC
    __int128* select_uad; // Offset: 0x5C, DWARF: 0xFAAD5
    // Size: 0x960, DWARF: 0xF845A
    Character3 character[12][3]; // Offset: 0x60, DWARF: 0xFAAFF
    // Size: 0x378, DWARF: 0xF9772
    CreateCharacter2 create_chr[2]; // Offset: 0x151E0, DWARF: 0xFAB27
    unsigned int* cr_arm_utd; // Offset: 0x158D0, DWARF: 0xFAB50
    unsigned int* cr_leg_utd; // Offset: 0x158D4, DWARF: 0xFAB7A
    unsigned int* cr_arm_f_utd; // Offset: 0x158D8, DWARF: 0xFABA4
    // Size: 0x4B0, DWARF: 0xF6F43
    Game2 game; // Offset: 0x158E0, DWARF: 0xFABD0
    // Size: 0x4B0, DWARF: 0xF6F43
    Game2 wheel; // Offset: 0x15D90, DWARF: 0xFABF3
    // Size: 0x4B0, DWARF: 0xF6F43
    Game2 param; // Offset: 0x16240, DWARF: 0xFAC17
    __int128* pad_umd[9]; // Offset: 0x166F0, DWARF: 0xFAC3B
    unsigned int* pad_utd; // Offset: 0x16714, DWARF: 0xFAC61
    // Size: 0x10, DWARF: 0xF6D8D
    TexData* pad_tex; // Offset: 0x16718, DWARF: 0xFAC88
} LoadData;

// Size: 0x10, DWARF: 0xFC06A
typedef struct RepHead
{
    signed int pnum; // Offset: 0x0, DWARF: 0xFC086
    signed int handicap[2]; // Offset: 0x4, DWARF: 0xFC0A7
    signed int rule; // Offset: 0xC, DWARF: 0xFC0CE
} RepHead;

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
// Size: 0xE0, DWARF: 0x179569

typedef struct PolyGT4
{
    GifTagUl giftag; // Offset: 0x0
    PrimUl prim; // Offset: 0x10
    TexUl tex0; // Offset: 0x18
    STUV_Ul stuv0; // Offset: 0x20
    RGBAQ_Ul rgbaq0; // Offset: 0x28
    XyzfUl xyzf0; // Offset: 0x30
    STUV_Ul stuv1; // Offset: 0x38
    RGBAQ_Ul rgbaq1; // Offset: 0x40
    XyzfUl xyzf1; // Offset: 0x48
    STUV_Ul stuv2; // Offset: 0x50
    RGBAQ_Ul rgbaq2; // Offset: 0x58
    XyzfUl xyzf2; // Offset: 0x60
    STUV_Ul stuv3; // Offset: 0x68
    RGBAQ_Ul rgbaq3; // Offset: 0x70
    XyzfUl xyzf3; // Offset: 0x78
} PolyGT4;

// Size: 0xE0, DWARF: 0xFC2CD
typedef struct Data
{
    signed int col[4][4]; // Offset: 0x0, DWARF: 0xFC2E9
    signed int vert[4][4]; // Offset: 0x40, DWARF: 0xFC30B
    signed int uv[4]; // Offset: 0x80, DWARF: 0xFC32E
    float stq[4][4]; // Offset: 0x90, DWARF: 0xFC34F
    TexData* texdata; // Offset: 0xD0, DWARF: 0xFC371
    unsigned long psmt; // Offset: 0xD8, DWARF: 0xFC39A
} Data;

//// External function prototypes ////////////////////////////////
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void ulFree(void* p);
void* memcpy(void* dest, const void* src, unsigned int count);
LoadData* sploadGetSelectData();
void ultexResetTex(signed int offset);
signed int nmvcPlayCursor(signed int num);
signed int ayCalcNextID(signed int now, signed int limit, signed int dir);
void ultexTransTexTag(VgmsysGifPkt* packet, unsigned int* addr, TexData* data, signed int no);
signed int ayMcGetStep();
AlphaTag* ulgifAddCNTReserve(VgmsysGifPkt* pkt, signed int qwc);
void ulpktInitALPHA(AlphaTag* pkt, signed int ctext);
void aySetVert(signed int* vert, float* xy, signed int z);
void ayDrawBG(VgmsysGifPkt* packet, TexData* texData, signed int col, signed int mark);
void ayBlackOutDraw(signed int col);
signed int ayMcCareerLoad(VgmsysGifPkt* packet);
void aySetGameData(signed int randFlg, signed int pnum);
RepHead* sploadGetRapHead();
void akselSnowFall(VgmsysGifPkt* pkt, signed int texofs, unsigned int* texadr, VakSnowFall* sf, unsigned int z, unsigned long alpha);
signed int nmvcPlayButton(signed int num);
signed int nmsqPlaySelect();
signed int nmsndExitSel(signed int fade);
signed int nmbgmSetExterVol(signed int vol);
signed int nmvcSetExterVol(signed int vol);
void ayOptionClear();
void aySetPolyComGT4(PolyGT4* poly, Data* data, signed int flg);
void aySetCamMatrix(float* worldScr, float* worldView, float* viewScr);
void sceVu0FTOI4Vector(sceVu0IVECTOR vec, sceVu0FVECTOR vec2);
void sceVu0DivVector(float* v0, float* v1, float q);
void sceVu0ApplyMatrix(sceVu0FVECTOR a, sceVu0FMATRIX b, sceVu0FVECTOR c);
void sceVu0UnitMatrix(sceVu0FMATRIX m);
void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR v);
void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);
void ul3dScaleMatrixXYZ(float (*mat)[4], float sx, float sy, float sz);
void aySetPolyComFT4(Poly* poly, Data* data, signed int flg);
float ayCalcTotalMove(signed int frame, signed int count, float totalmove, signed int type);
void ayDrawKeyOparate(signed int kind, signed int count, signed int flg, TexData* texData, VgmsysGifPkt* packet);
signed int nmvcPlay(signed int res, signed int group, signed int num);
void spinitInitRecord();
void spinitInitCharacter(Character* character, signed int sw, Parameter* param);
void akselInitSnowFall(VakSnowFall* snow, signed int num);
void akselFreeSnowFall(VakSnowFall* snow);

//// Function Declarations ///////////////////////////////////////////////////////////

void ayModeSelInit(void);
signed int ayModeSelFrame(void);
void ayModeSelEnd(void);
static void ayDrawMovie(signed int col);
static void aySetKeyOparate(void);
static void aySetMode(void);
static void ayDrawMode(void);
static void ayDrawMark(unsigned int* utd, signed int ofs, signed int col);
static void ayReleaseCommand(signed int kind);
static void ayReleaseCheat(void);
static void ayReleaseGap(void);
static void ayReleaseMovie(void);
static void ayReleaseChara(Character* chara, signed int id, signed int kind);

//// Variables ///////////////////////////////////////////////////////////////////////

extern VspenvEnv vspenvEnv; // Address: 0x3474D0
extern VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
extern VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30
extern signed int vayStateFlg; // Address: 0x2E7BB8
extern VaySelData* vaySelData; // Address: 0x2E7BB4
extern signed int vayMovKind; // Address: 0x2E7BE0
extern VspenvOption* vspenvOption; // Address: 0x2E7B10
extern VspenvSecret* vspenvSecret; // Address: 0x2E7B04
extern Parameter vsptblCharacterParam[12]; // Address: 0x2B7160
extern signed int vsptblCourseParam[8][5]; // Address: 0x2B77F0
extern signed int vayParamMax[12][6]; // Address: 0x2C7C10

// Size: 0x60, DWARF: 0xFACDC
VakSnowFall vakSnowFall; // Address: 0x3C0BE0
signed int vayDemoSwitch; // Address: 0x2E7BD4
signed int vayNewCareer; // Address: 0x2E7BD0
signed int vayMovCount; // Address: 0x2E7BCC
// Size: 0x1C, DWARF: 0xFBF0E
VayModeDat* vayModeData; // Address: 0x2E7BC8

//// Function Definitions ////////////////////////////////////////////////////////////

void ayModeSelInit(void) {
    vayModeData = (VayModeDat*)ulMalloc(0x1C, 0, 0);
    vayModeData->count = 0;
    vayModeData->step = 4;
    vayModeData->next = 0;
    vayModeData->mode = 0;
    vayModeData->type = 0;
    if (vayStateFlg != -1) {
        vayModeData->step = 0;
        vayModeData->mode = 4;
    }
    akselInitSnowFall(&vakSnowFall, 0x1E);
    vayMovCount = 0;
    vayModeData->comstep = 0;
}

signed int ayModeSelFrame(void) {
    signed int ii; // r16
    signed int count; // r17
    signed int next; // r18
    LoadData* data; // r19
    RepHead* repHead; // r20
    signed int ret; // r21
    unsigned int command; // r22
    signed int col; // r23
    signed int step; // r30
    TexData texData[2]; // 0xA0(r29)
    signed int mc; // 0xCC(r29)

    ret = 0;
    next = 0;
    step = vayModeData->step;
    count = vayModeData->count;
    command = vgmsysPad[0]->cnt & 0xFFCF;
    data = sploadGetSelectData();
    if (step != 4) {
        if ((step == 5) && (count < 0x20)) {
            col = count << 2;
        } else {
            col = 0x80;
        }
        ultexResetTex(data->offset);
        for (ii = 0; ii < 2; ii++) {
            texData[ii].tofs = -1;
            texData[ii].cofs = -1;
        }
        ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData[0], 0);
        ultexTransTexTag(vgmsysGifPkt, data->select_utd, &texData[1], 2);
        ayDrawBG(vgmsysGifPkt, &texData[0], col, 1);
        akselSnowFall(vgmsysGifPkt, data->offset, data->select_utd, &vakSnowFall, 0xFFFFFF, col / 2);
        ayDrawMovie(col / 4 * 3);
        if (step != 3) {
            ayDrawMode();
        }
    }
    ayDrawMark(data->select_utd, data->offset, col);
    switch (step) {
    case 4:
        if (count == 0) {
            nmvcPlay(2, 1, 0);
            nmsqPlaySelect();
        } else if (count == 0x40) {
            next = 1;
            vayModeData->step = 5;
        }
        if (vgmsysPad[0]->trg & 0x800) {
            vayModeData->step = 0;
            next = 1;
        }
        break;
    case 5:
        if (count == 0) {
            nmvcPlay(3, 1, 1);
        } else if (count == 0x40) {
            nmvcPlay(4, 1, 2);
        } else if (count == 0x80) {
            nmvcPlay(2, 1, 3);
        }
        if (count == 0x90) {
            next = 1;
            vayModeData->step = 0;
        }
        if (vgmsysPad[0]->trg & 0x800) {
            vayModeData->step = 0;
            next = 1;
        }
        break;
    case 0:
        if ((vgmsysPad[0]->trg & 0x40) && (vaySelData->bocount == -1)) {
            if (!(vayModeData->confFlg & (1 << vayModeData->mode))) {
                nmvcPlayButton(0);
                next = 1;
                switch (vayModeData->mode) {
                case 0:
                    vayModeData->step = 7;
                    if (vayNewCareer == 0) {
                        vayModeData->type = 1;
                    } else {
                        vayModeData->type = 0;
                    }
                    break;
                case 1:
                    vayModeData->step = 7;
                    vayModeData->type = 0;
                    break;
                case 2:
                    ret = 0xB;
                    vayModeData->next = 1;
                    break;
                case 3:
                    ret = 0xE;
                    vaySelData->mode = 4;
                    vayModeData->next = 1;
                    break;
                case 4:
                    ret = 0xD;
                    ayOptionClear();
                    vayModeData->next = 1;
                    break;
                }
            } else {
                nmvcPlayButton(3);
            }
        }
        if ((vayModeData->mode == 4) && (vayModeData->comstep >= 0)) {
            if (command == 0x2001) {
                ayReleaseCommand(0);
            } else if (command == 0x2004) {
                ayReleaseCommand(1);
            } else if (command == 0x8001) {
                ayReleaseCommand(2);
            } else if (command == 0x8004) {
                ayReleaseCommand(3);
            } else if (command == 0x8008) {
                ayReleaseCommand(4);
            } else if (command == 0x2008) {
                ayReleaseCommand(5);
            } else if (command == 0x2002) {
                ayReleaseCommand(6);
            }
        } else if (vayModeData->comstep != 0) {
            if (vgmsysPad[0]->cnt == 0xFFFF0000) {
                vayModeData->comstep = 0;
            }
        }
        if (!(((vgmsysPad[0]->state == 2) || (vgmsysPad[0]->state == 6)) && (vgmsysPad[0]->cnt != 0xFFFF0000)) && !(((vgmsysPad[1]->state == 2) || (vgmsysPad[1]->state == 6)) && (vgmsysPad[1]->cnt != 0xFFFF0000))) {
            vayMovCount++;
        } else {
            vayMovCount = 0;
        }
        if (vayMovCount == 0x708) {
            vaySelData->bocount = 0;
            if (vayDemoSwitch != 0) {
                vaySelData->nextMode = 0xF;
                vayMovKind = 1;
            } else {
                vaySelData->nextMode = 0x13;
                repHead = sploadGetRapHead();
                aySetGameData(1, repHead->pnum);
                if (repHead->pnum == 2) {
                    vspenvEnv.game.mode.match_rule = repHead->rule;
                    vspenvEnv.game.mode.handicap[0] = repHead->handicap[0];
                    vspenvEnv.game.mode.handicap[1] = repHead->handicap[1];
                }
            }
            vayDemoSwitch ^= 1;
            nmsndExitSel(0x10);
        }
        break;
    case 7:
        if (count == 0x20) {
            next = 1;
            vayModeData->step = 1;
        }
        break;
    case 6:
        if (count == 0x20) {
            next = step = 1;
            vayModeData->step = 0;
        }
        break;
    case 1:
        if (vaySelData->bocount == -1) {
            if (vgmsysPad[0]->trg & 0x40) {
                if (!(vayModeData->confFlg & (1 << vayModeData->type))) {
                    next = 1;
                    nmvcPlayButton(0);
                    if ((vayModeData->mode == 0) && (vayModeData->type == 2)) {
                        vayModeData->step = 0xB;
                    } else {
                        ret = 0xB;
                        vayModeData->next = 1;
                    }
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[0]->trg & 0x10) {
                next = 1;
                vayModeData->step = 6;
                nmvcPlayButton(2);
            }
        }
        break;
    case 11:
        ayBlackOutDraw(count << 1);
        if (count == 0x20) {
            next = 1;
            vayModeData->step = 3;
        }
        break;
    case 3:
        ayBlackOutDraw(0x40);
        if (vaySelData->bocount == -1) {
            mc = ayMcCareerLoad(vgmsysGifPkt);
            if (mc == 1) {
                vaySelData->bgmdiff = vaySelData->bgm - vspenvEnv.mc.option.volume.bgm;
                nmbgmSetExterVol(vspenvEnv.mc.option.volume.bgm);
                nmvcSetExterVol(vspenvEnv.mc.option.volume.se);
                ret = 0xB;
            } else if (mc == 2) {
                next = 1;
                vayModeData->step = 0xA;
            }
        }
        break;
    case 10:
        ayBlackOutDraw(0x40 - (count << 1));
        if (count == 0x20) {
            next = 1;
            vayModeData->step = 1;
        }
        break;
    }
    if (next == 0) {
        vayModeData->count = (count + 1) & 0xFFFFFF;
    } else {
        vayModeData->count = 0;
    }
    aySetKeyOparate();
    if (ret == 0xB) {
        aySetMode();
    }
    if (vaySelData->bocount == 0x1F) {
        vayModeData->next = 0;
        if (vayModeData->step == 3) {
            vayModeData->step = 1;
        }
    }
    return ret;
}

void ayModeSelEnd(void) {
    ulFree(vayModeData);
    akselFreeSnowFall(&vakSnowFall);
}

static void ayDrawMovie(signed int col) {
    LoadData* loaddata; // r22
    signed int rollcnt; // r20
    signed int jj; // r16
    signed int ii; // r17
    void* addr; // r23
    PolyGT4* poly; // r21
    Data data; // 0xA0(r29)
    TexData texData; // 0x180(r29)
    float vert[8][4] = {{-256.0f, -64.0f, 0.0f, 1.0f}, {-192.0f, -64.0f, 0.0f, 1.0f}, {192.0f, -64.0f, 0.0f, 1.0f}, {256.0f, -64.0f, 0.0f, 1.0f}, {-256.0f, 64.0f, 0.0f, 1.0f}, {-192.0f, 64.0f, 0.0f, 1.0f}, {192.0f, 64.0f, 0.0f, 1.0f}, {256.0f, 64.0f, 0.0f, 1.0f}}; // 0x190(r29)
    float stq[8][4] = {{0.0f, 0.0f, 1.0f, 0.0f}, {0.125f, 0.0f, 1.0f, 0.0f}, {0.875f, 0.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.25f, 1.0f, 0.0f}, {0.125f, 0.25f, 1.0f, 0.0f}, {0.875f, 0.25f, 1.0f, 0.0f}, {1.0f, 0.25f, 1.0f, 0.0f}}; // 0x210(r29)
    float mat[4][4]; // 0x290(r29)
    sceVu0FVECTOR trans; // 0x2D0(r29)
    sceVu0FVECTOR rot; // 0x2E0(r29)
    float worldScr[4][4]; // 0x2F0(r29)
    float worldView[4][4]; // 0x330(r29)
    float viewScr[4][4]; // 0x370(r29)
    AlphaTag* alpha; // 0x3B8(r29)
    float q; // 0x3BC(r29)
    signed int count; // 0x3C0(r29)

    count = vayModeData->count;
    rollcnt = vaySelData->count;
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->selmov_utd, &texData, rollcnt / 12 % 15);
    aySetCamMatrix(worldScr, worldView, viewScr);
    addr = ulgifAddCNTReserve(vgmsysGifPkt, 0x1A);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    rot[0] = -0.02f, rot[1] = -0.52f, rot[2] = -0.38f, rot[3] = 1.0f;
    trans[0] = 109.0f, trans[1] = -84.0f, trans[2] = 8.0f, trans[3] = 1.0f;
    for (ii = 0; ii < 8; ii++) {
        stq[ii][1] += 0.25f * (float)(rollcnt / 3 % 4);
    }
    if (rollcnt > 0x200) {
        rollcnt = rollcnt % 0x200;
    }
    for (ii = 0; ii < 8; ii++) {
        stq[ii][0] += 0.001953125f * (float)rollcnt;
    }
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixX(mat, mat, rot[0]);
    sceVu0RotMatrixY(mat, mat, rot[1]);
    sceVu0RotMatrixZ(mat, mat, rot[2]);
    sceVu0TransMatrix(mat, mat, trans);
    ul3dScaleMatrixXYZ(mat, 1.5f, 1.5f, 1.5f);
    for (ii = 0; ii < 8; ii++) {
        sceVu0ApplyMatrix(vert[ii], mat, vert[ii]);
        vert[ii][3] = 1.0f;
        sceVu0ApplyMatrix(vert[ii], worldScr, vert[ii]);
        q = vert[ii][3];
        sceVu0DivVector(stq[ii], stq[ii], q);
        sceVu0DivVector(vert[ii], vert[ii], q);
    }
    poly = addr;
    data.texdata = &texData;
    data.psmt = 0x14;
    for (ii = 0; ii < 3; ii++) {
        sceVu0FTOI4Vector(data.vert[0], vert[ii]);
        sceVu0FTOI4Vector(data.vert[1], vert[ii + 1]);
        sceVu0FTOI4Vector(data.vert[2], vert[ii + 4]);
        sceVu0FTOI4Vector(data.vert[3], vert[ii + 5]);
        data.stq[0][0] = stq[ii][0], data.stq[0][1] = stq[ii][1], data.stq[0][2] = stq[ii][2], data.stq[0][3] = stq[ii][3];
        data.stq[1][0] = stq[ii + 1][0], data.stq[1][1] = stq[ii + 1][1], data.stq[1][2] = stq[ii + 1][2], data.stq[1][3] = stq[ii + 1][3];
        data.stq[2][0] = stq[ii + 4][0], data.stq[2][1] = stq[ii + 4][1], data.stq[2][2] = stq[ii + 4][2], data.stq[2][3] = stq[ii + 4][3];
        data.stq[3][0] = stq[ii + 5][0], data.stq[3][1] = stq[ii + 5][1], data.stq[3][2] = stq[ii + 5][2], data.stq[3][3] = stq[ii + 5][3];
        for (jj = 0; jj < 4; jj++) {
            data.vert[jj][2] = 1;
            if (((ii == 0) && (jj % 2 == 0)) || ((ii == 2) && (jj % 2 == 1))) {
                data.col[jj][0] = 0x80, data.col[jj][1] = 0x80, data.col[jj][2] = 0x80, data.col[jj][3] = 0;
            } else {
                data.col[jj][0] = 0x80, data.col[jj][1] = 0x80, data.col[jj][2] = 0x80, data.col[jj][3] = col;
            }
        }
        aySetPolyComGT4(poly + ii, &data, 0);
    }
}

static void aySetKeyOparate(void) {
    LoadData* loaddata; // r19
    TexData texData; // 0x50(r29)
    signed int flg; // r16
    signed int count; // r18
    signed int kind; // r17

    count = vayModeData->count;
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    texData.tofs = -1;
    texData.cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData, 0x28);
    switch (vayModeData->step) {
    case 4:
        flg = 10;
        break;
    case 5:
        if (count < 0x70) {
            flg = 10;
        } else {
            flg = -2;
            kind = 0;
            count -= 0x70;
        }
        break;
    case 0:
        flg = 0;
        kind = 0;
        break;
    case 7:
        if (count < 0x10) {
            flg = 1;
            kind = 0;
        } else {
            flg = -1;
            kind = 1;
            count -= 0x10;
        }
        break;
    case 6:
        if (count < 0x10) {
            flg = 1;
            kind = 1;
        } else {
            flg = -1;
            kind = 0;
            count -= 0x10;
        }
        break;
    case 1:
        flg = 0;
        kind = 1;
        break;
    case 3:
        flg = 0;
        if (ayMcGetStep() == 6) {
            kind = 1;
        } else if (ayMcGetStep() == 8) {
            kind = 0;
        } else {
            flg = 10;
        }
        break;
    case 11:
        if (count < 0x10) {
            flg = 1;
            kind = 1;
        } else {
            flg = 10;
        }
        break;
    case 10:
        if (count < 0x10) {
            flg = 10;
        } else {
            flg = 1;
            kind = 1;
        }
        break;
    }
    if (flg != 10) {
        ayDrawKeyOparate(kind, count, flg, &texData, vgmsysGifPkt);
    }
}

static void aySetMode(void) {
    Character* character; // r17
    signed int ii; // r16

    switch (vayModeData->mode) {
    case 0:
        if (vayModeData->type == 1) {
            vaySelData->mode = 1;
        } else {
            vaySelData->mode = 0;
        }
        vspenvEnv.game.mode.num_player = 1;
        vspenvEnv.game.mode.game_mode = 0;
        break;
    case 1:
        vaySelData->mode = 2;
        vspenvEnv.game.mode.num_player = 2;
        vspenvEnv.game.mode.match_rule = vayModeData->type;
        vspenvEnv.game.mode.game_mode = 1;
        break;
    case 2:
        vaySelData->mode = 3;
        vspenvEnv.game.mode.num_player = 1;
        vspenvEnv.game.mode.game_mode = 2;
        break;
    }
    if ((vayModeData->mode == 0) && (vayModeData->type == 1)) {
        memcpy(&vaySelData->mc, &vspenvEnv.mc, 0x1668);
        spinitInitRecord();
        for (ii = 0; ii < 0xA; ii++) {
            spinitInitCharacter(&vspenvSecret[0].character[ii], vspenvSecret[0].character[ii].secret, &vsptblCharacterParam[ii]);
        }
        for (ii = 0xA; ii < 0xC; ii++) {
            spinitInitCharacter(&vspenvSecret[0].character[ii], 0, &vsptblCharacterParam[ii]);
        }
        for (ii = 0; ii < 0xA; ii++) {
            character = &vspenvSecret[0].create_character[ii].character;
            spinitInitCharacter(character, character->secret, &vspenvSecret->create_character[ii].init_param);
        }
        for (ii = 0; ii < 8; ii++) {
            vspenvSecret->course[ii].gap = 0;
        }
        vspenvSecret->old_char = 0;
        vspenvSecret->tour_round = 1;
        vspenvOption->movie = 0;
    }
}

static void ayDrawMode(void) {
    signed int ii; // r16
    signed int count; // r17
    signed int col; // r18
    signed int type; // r19
    signed int step; // r20
    signed int* select; // r21
    LoadData* loaddata; // r22
    signed int blackFlg; // r23
    signed int lnum; // r30
    Poly* poly; // 0x220(r29)
    AlphaTag* alpha; // 0x224(r29)
    void* addr; // 0x228(r29)
    float size; // 0x22C(r29)
    signed int key; // 0x230(r29)
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    signed int uv[5][4]; // 0x190(r29)
    TexData texData[4]; // 0x1E0(r29)

    col = 0x80;
    size = 0.0f;
    count = vayModeData->count;
    step = vayModeData->step;
    loaddata = sploadGetSelectData();
    ultexResetTex(loaddata->offset);
    for (ii = 0; ii < 4; ii++) {
        texData[ii].tofs = -1;
        texData[ii].cofs = -1;
    }
    switch (step) {
    case 5:
        key = 0;
        type = 0;
        break;
    case 0:
        key = 1;
        type = 0;
        break;
    case 7:
        key = 0;
        if (count < 0x10) {
            type = 0;
            col = 0x80 - (count << 3);
        } else {
            type = 1;
            col = (count - 0x10) << 3;
        }
        break;
    case 6:
        key = 0;
        if (count < 0x10) {
            type = 1;
            col = 0x80 - (count << 3);
        } else {
            type = 0;
            col = (count - 0x10) << 3;
        }
        break;
    case 1:
        key = 1;
        type = 1;
        break;
    case 11:
        key = 0;
        type = 1;
        if (count < 0x10) {
            col = 0x80 - (count << 3);
        } else {
            col = 0;
        }
        break;
    case 10:
        key = 0;
        type = 1;
        if (count < 0x10) {
            col = 0;
        } else {
            col = (count - 0x10) << 3;
        }
        break;
    }
    switch (type) {
    case 0:
        select = &vayModeData->mode;
        lnum = 5;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[0], 0xB);
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 0xC);
        for (ii = 0; ii < 5; ii++) {
            uv[ii][0] = 0, uv[ii][1] = ii * 0x32, uv[ii][2] = 0x100, uv[ii][3] = uv[ii][1] + 0x32;
        }
        blackFlg = 0;
        if ((vgmsysPad[1]->state != 2) && (vgmsysPad[1]->state != 6)) {
            blackFlg |= 2;
        }
        break;
    case 1:
        select = &vayModeData->type;
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[0], 0xD);
        ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[1], 0xE);
        if (vayModeData->mode == 0) {
            lnum = 3;
            for (ii = 0; ii < 3; ii++) {
                uv[ii][0] = 0, uv[ii][1] = ii * 0x32 + 0x64, uv[ii][2] = 0x100, uv[ii][3] = uv[ii][1] + 0x32;
            }
            blackFlg = 0;
            if (vayNewCareer == 0) {
                blackFlg |= 1;
            }
        } else {
            lnum = 4;
            type = 2;
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[2], 0xF);
            ultexTransTexTag(vgmsysGifPkt, loaddata->select_utd, &texData[3], 0x10);
            for (ii = 0; ii < 4; ii++) {
                uv[ii][0] = 0, uv[ii][1] = (ii % 2) * 0x32, uv[ii][2] = 0x100, uv[ii][3] = uv[ii][1] + 0x32;
            }
            blackFlg = 0;
        }
        break;
    }
    if ((key != 0) && (vaySelData->bocount == -1)) {
        if (vgmsysPad[0]->rep & 0x1000) {
            nmvcPlayCursor(1);
            *select = ayCalcNextID(*select, lnum, -1);
        } else if (vgmsysPad[0]->rep & 0x4000) {
            nmvcPlayCursor(1);
            *select = ayCalcNextID(*select, lnum, 1);
        }
    }
    vayModeData->confFlg = blackFlg;
    addr = ulgifAddCNTReserve(vgmsysGifPkt, (signed int)(lnum * 0x70 + 0x20 + 0xFU) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.psmt = 0x14;
    for (ii = 0; ii < lnum; ii++) {
        if (step == 5) {
            if (count < ii * 6 + 0x40) {
                col = 0;
            } else if (count < ii * 6 + 0x50) {
                col = (count - 0x40 - ii * 6) << 3;
            } else if (count < ii * 6 + 0x60) {
                col = 0x80 - ((count - 0x50 - ii * 6) << 3);
            } else if (count < 0x80) {
                col = 0;
            } else {
                col = (count - 0x80) << 3;
            }
        }
        if (ii == *select) {
            if (((step == 7) || (step == 0xB)) && (count < 0x10)) {
                size = (float)count / 2.0f;
            } else if ((vaySelData->bocount != -1) && (vayModeData->next != 0)) {
                size = (float)vaySelData->bocount / 2.0f;
                col = 0x80 - (vaySelData->bocount << 2);
            }
            if ((type == 2) && (ii >= 2)) {
                data.texdata = &texData[3];
            } else {
                data.texdata = &texData[1];
            }
        } else {
            size = 0.0f;
            if ((vaySelData->bocount != -1) && (vayModeData->next != 0)) {
                col = 0x80;
            }
            if ((type == 2) && (ii >= 2)) {
                data.texdata = &texData[2];
            } else {
                data.texdata = &texData[0];
            }
        }
        if (blackFlg & (1 << ii)) {
            data.col[0][0] = 0x40, data.col[0][1] = 0x40, data.col[0][2] = 0x40, data.col[0][3] = col;
        } else {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
        }
        data.uv[0] = uv[ii][0], data.uv[1] = uv[ii][1], data.uv[2] = uv[ii][2], data.uv[3] = uv[ii][3];
        xy[0] = 344.0f, xy[1] = 80.0f + 25.0f * (float)ii - size / 2.0f, xy[2] = 256.0f + xy[0], xy[3] = 25.0f + xy[1] + size;
        aySetVert(data.vert[0], xy, 0xFFFFFE);
        aySetPolyComFT4(poly + ii, &data, 1);
    }
}

static void ayDrawMark(unsigned int* utd, signed int ofs, signed int col) {
    signed int count; // r16
    signed int polnum; // r18
    Data data; // 0xA0(r29)
    float xy[4]; // 0x180(r29)
    TexData texData[2]; // 0x190(r29)
    void* addr; // r19
    AlphaTag* alpha; // r20
    Poly* poly; // r17

    count = vayModeData->count;
    if (vayModeData->step == 4) {
        if (count < 0x20) {
            polnum = 1;
        } else {
            polnum = 2;
        }
    } else {
        polnum = 2;
    }
    ultexResetTex(ofs);
    texData[0].tofs = texData[1].tofs = -1;
    texData[0].cofs = texData[1].cofs = -1;
    ultexTransTexTag(vgmsysGifPkt, utd, &texData[0], 1);
    ultexTransTexTag(vgmsysGifPkt, utd, &texData[1], 3);
    addr = ulgifAddCNTReserve(vgmsysGifPkt, (signed int)(polnum * 0x70 + 0x20 + 0xFU) >> 4);
    alpha = ((AlphaTag*)addr)++;
    ulpktInitALPHA(alpha, 1);
    poly = addr;
    data.texdata = &texData[0];
    data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x80, data.uv[3] = 0x80;
    data.psmt = 0x13;
    switch (vayModeData->step) {
    case 4:
        xy[0] = (float)(0x140 - (count + 0x20)), xy[1] = (float)(0x70 - (count / 2 + 0x10)), xy[2] = 64.0f + xy[0] + 2.0f * (float)count, xy[3] = 32.0f + xy[1] + (float)count;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        if (count < 0x20) {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = count << 2;
            aySetPolyComFT4(poly, &data, 1);
        } else {
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = (0x40 - count) << 2;
            aySetPolyComFT4(poly + 1, &data, 1);
            xy[0] = 256.0f, xy[1] = 80.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
            aySetVert(data.vert[0], xy, 0xFFFFFF);
            data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
            aySetPolyComFT4(poly, &data, 1);
        }
        break;
    case 5:
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        if (count < 0x40) {
            xy[0] = 256.0f - ayCalcTotalMove(0x40, count, 206.0f, 1), xy[1] = 80.0f - ayCalcTotalMove(0x40, count, 58.0f, 3), xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
        } else {
            xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
        }
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + 1, &data, 1);
        break;
    default:
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = 0x80;
        xy[0] = 50.0f, xy[1] = 22.0f, xy[2] = 128.0f + xy[0], xy[3] = 64.0f + xy[1];
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        aySetPolyComFT4(poly + 1, &data, 1);
        break;
    }
    if (vayModeData->step != 4) {
        data.texdata = &texData[1];
        data.uv[0] = 0, data.uv[1] = 0, data.uv[2] = 0x100, data.uv[3] = 0x100;
        data.psmt = 0x14;
        xy[0] = 0.0f, xy[1] = 0.0f, xy[2] = 256.0f, xy[3] = 128.0f;
        aySetVert(data.vert[0], xy, 0xFFFFFF);
        data.col[0][0] = 0x80, data.col[0][1] = 0x80, data.col[0][2] = 0x80, data.col[0][3] = col;
        aySetPolyComFT4(poly, &data, 1);
    }
}

static void ayReleaseCommand(signed int kind) {
    signed int ii; // r16
    unsigned int command[4] = {0x10, 0x10, 0x20, 0x10}; // 0x30(r29)

    if (vayModeData->comstep < 4) {
        if (vgmsysPad[0]->trg & command[vayModeData->comstep]) {
            vayModeData->comstep++;
        } else if (vgmsysPad[0]->trg) {
            vayModeData->comstep = 0;
        }
    }
    if (vayModeData->comstep == 4) {
        nmvcPlay(3, 1, 6);
        vayNewCareer = 1;
        switch (kind) {
        case 0:
            ayReleaseCheat();
            break;
        case 4:
            ayReleaseMovie();
            break;
        case 3:
            vspenvSecret->character[10].secret = 1;
            vspenvSecret->character[11].secret = 1;
            break;
        case 6:
            ayReleaseGap();
            ayReleaseCheat();
            ayReleaseMovie();
            vspenvSecret->character[10].secret = 1;
            vspenvSecret->character[11].secret = 1;
        case 5:
            vspenvSecret->tour_round = 0xFF;
        case 1:
        case 2:
            for (ii = 0; ii < 0xC; ii++) {
                if (vspenvSecret->character[ii].secret) {
                    ayReleaseChara(&vspenvSecret->character[ii], ii, kind);
                }
            }
            for (ii = 0; ii < 0xA; ii++) {
                if (vspenvSecret->create_character[ii].character.secret) {
                    ayReleaseChara(&vspenvSecret->create_character[ii].character, 0xA, kind);
                }
            }
            break;
        }
        vayModeData->comstep = 0;
    }
}

static void ayReleaseCheat(void) {
    vspenvOption->enable.kids = 1;
    vspenvOption->enable.half_g = 1;
    vspenvOption->enable.perfect_b = 1;
    vspenvOption->enable.always_sp = 1;
    vspenvOption->enable.super_spin = 1;
    vspenvOption->enable.super_speed = 1;
    vspenvOption->enable.fast_motion = 1;
    vspenvOption->enable.replay_view = 1;
    vspenvOption->enable.big_head = 1;
    vspenvOption->enable.mirror = 1;
    vspenvOption->enable.metallic = 1;
    vspenvOption->enable.partition = 1;
}

static void ayReleaseGap(void) {
    unsigned long flg; // r17
    signed int num; // r18
    signed int jj; // r16
    signed int ii; // r19
    signed int unused1;

    for (ii = 0; ii < 8; ii++) {
        num = vsptblCourseParam[ii][4];
        jj = 0;
        flg = 0;
        unused1 = 0;
        for (; jj < num; jj++) {
            flg |= ((unsigned long)1 << (long)jj);
        }
        vspenvSecret->course[ii].gap = flg;
    }
}

static void ayReleaseMovie(void) {
    signed int ii; // r16

    for (ii = 0; ii < 0xF; ii++) {
        vspenvOption->movie |= (1 << ii);
    }
}

static void ayReleaseChara(Character* chara, signed int id, signed int kind) {
    signed int* param; // r17
    signed int ii; // r16

    if ((kind == 1) || (kind == 6)) {
        param = (int*)&chara->parameter;
        for (ii = 0; ii < 5; ii++) {
            param[ii] = vayParamMax[id][ii];
        }
    }
    if ((kind == 2) || (kind == 6)) {
        chara->board = 0x7F;
    }
    if ((kind == 5) || (kind == 6)) {
        chara->course = 0xFF;
    }
    if (kind == 6) {
        for (ii = 0; ii < 8; ii++) {
            chara->level_goal[ii] = 0x1FF;
            chara->soft[ii] = 9;
        }
    }
}
