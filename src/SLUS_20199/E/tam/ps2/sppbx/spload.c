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
typedef unsigned __int128 __uint128;
typedef unsigned __int128 uint128;
typedef unsigned __int128 u128;

#define ABORT() asm(".word 0x0000000d")

// Pragma //////////////////////////////////////////////////////////////////////////////
#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop)<<15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim)<<47) | ((unsigned long)(flg)<<58) | ((unsigned long)(nreg)<<60))

#define SCE_GS_SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix) \
    ((unsigned long)(prim) | ((unsigned long)(iip)<<3) | ((unsigned long)(tme)<<4) | \
    ((unsigned long)(fge)<<5) | ((unsigned long)(abe)<<6) | ((unsigned long)(aa1)<<7) | \
    ((unsigned long)(fst)<<8) | ((unsigned long)(ctxt)<<9) | ((unsigned long)(fix)<<10))

#define SCE_GS_SET_RGBAQ(r, g, b, a, q) \
    ((unsigned long)(r) | ((unsigned long)(g)<<8) | ((unsigned long)(b)<<16) | \
    ((unsigned long)(a)<<24) | ((unsigned long)(q)<<32))

#define SCE_GS_SET_UV(u, v) ((unsigned long)(u) | ((unsigned long)(v)<<16))

#define SCE_GS_SET_XYZ(x, y, z) \
    ((unsigned long)(x) | ((unsigned long)(y)<<16) | ((unsigned long)(z)<<32))

#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.

// SCE types //////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// Static data /////////////////////////////////////////////////

// spload.c structs //////////////////////////////////////////

// Size: 0x30, DWARF: 0xAEA95
typedef struct VsploadSystem
{
    unsigned long counter; // Offset: 0x0, DWARF: 0xAEAB1
    unsigned long counter2; // Offset: 0x8, DWARF: 0xAEAD5
    signed int start; // Offset: 0x10, DWARF: 0xAEAFA
    signed int end; // Offset: 0x14, DWARF: 0xAEB1C
    signed int disp; // Offset: 0x18, DWARF: 0xAEB3C
    signed int next_module; // Offset: 0x1C, DWARF: 0xAEB5D
    signed int sound_data; // Offset: 0x20, DWARF: 0xAEB85
    signed int freeride_no; // Offset: 0x24, DWARF: 0xAEBAC
    signed int init_chr_no[2]; // Offset: 0x28, DWARF: 0xAEBD4
} VsploadSystem;

// Size: 0x4, DWARF: 0xAFF5A
typedef struct Course //: <unknown type 0xB0008>
{
    signed int no; // Offset: 0x0, DWARF: 0xAFF76
} Course; // Offset: 0x0, DWARF: 0xAEECA

// Size: 0x8, DWARF: 0xB0B65
typedef struct Course2
{
    unsigned long gap; // Offset: 0x0, DWARF: 0xB0B81
} Course2;

// Size: 0x3BC, DWARF: 0xAD1A1
typedef struct Course3
{
    unsigned int* base_link; // Offset: 0x0, DWARF: 0xAD1BD
    unsigned int* draw_link; // Offset: 0x4, DWARF: 0xAD1E6
    unsigned int* dfar_link; // Offset: 0x8, DWARF: 0xAD20F
    unsigned int* dnear_link; // Offset: 0xC, DWARF: 0xAD238
    unsigned int* butd_link; // Offset: 0x10, DWARF: 0xAD262
    unsigned int* dutd_link; // Offset: 0x14, DWARF: 0xAD28B
    unsigned int* outd_link; // Offset: 0x18, DWARF: 0xAD2B4
    unsigned int* base[10]; // Offset: 0x1C, DWARF: 0xAD2DD
    unsigned int* draw[10]; // Offset: 0x44, DWARF: 0xAD300
    unsigned int* dfar[10]; // Offset: 0x6C, DWARF: 0xAD323
    unsigned int* dnear[10]; // Offset: 0x94, DWARF: 0xAD346
    unsigned int* base_utd[10]; // Offset: 0xBC, DWARF: 0xAD36A
    unsigned int* draw_utd[10]; // Offset: 0xE4, DWARF: 0xAD391
    unsigned int* object; // Offset: 0x10C, DWARF: 0xAD3B8
    unsigned int* obj_utd[96]; // Offset: 0x110, DWARF: 0xAD3DE
    unsigned int* alpha; // Offset: 0x290, DWARF: 0xAD404
    unsigned int* alpha_utd; // Offset: 0x294, DWARF: 0xAD429
    unsigned int* bg_utd[2]; // Offset: 0x298, DWARF: 0xAD452
    __int128* bg_umd; // Offset: 0x2A0, DWARF: 0xAD477
    unsigned int* hit; // Offset: 0x2A4, DWARF: 0xAD49D
    unsigned int* vector; // Offset: 0x2A8, DWARF: 0xAD4C0
    unsigned int* rail; // Offset: 0x2AC, DWARF: 0xAD4E6
    unsigned int* bonk; // Offset: 0x2B0, DWARF: 0xAD50A
    unsigned int* event_link; // Offset: 0x2B4, DWARF: 0xAD52E
    __int128* event_uad; // Offset: 0x2B8, DWARF: 0xAD558
    __int128* event_umd[32]; // Offset: 0x2BC, DWARF: 0xAD581
    unsigned int* event_utd[32]; // Offset: 0x33C, DWARF: 0xAD5A9
} Course3;

// Size: 0x1C, DWARF: 0xAEC73
typedef struct CharacterParameters
{
    signed int ollie; // Offset: 0x0, DWARF: 0xAEC8F
    signed int spin; // Offset: 0x4, DWARF: 0xAECB1
    signed int speed; // Offset: 0x8, DWARF: 0xAECD2
    signed int landing; // Offset: 0xC, DWARF: 0xAECF4
    signed int balance; // Offset: 0x10, DWARF: 0xAED18
    signed int stability; // Offset: 0x14, DWARF: 0xAED3C
    signed int stance; // Offset: 0x18, DWARF: 0xAED62
} CharacterParameters;

// Size: 0x10, DWARF: 0xAF499
typedef struct BoardParameters
{
    signed int speed; // Offset: 0x0, DWARF: 0xAF4B5
    signed int stability; // Offset: 0x4, DWARF: 0xAF4D7
    signed int balance; // Offset: 0x8, DWARF: 0xAF4FD
    signed int turning; // Offset: 0xC, DWARF: 0xAF521
} BoardParameters;

// Size: 0x3C, DWARF: 0xAFB24
typedef struct CharacterState
{
    signed int no; // Offset: 0x0, DWARF: 0xAFB40
    signed int player; // Offset: 0x4, DWARF: 0xAFB5F
    signed int wear; // Offset: 0x8, DWARF: 0xAFB82
    signed int board; // Offset: 0xC, DWARF: 0xAFBA3
    // Size: 0x1C, DWARF: 0xAEC73
    CharacterParameters chr_param; // Offset: 0x10, DWARF: 0xAFBC5
    // Size: 0x10, DWARF: 0xAF499
    BoardParameters brd_param; // Offset: 0x2C, DWARF: 0xAFBED
} CharacterState;

// Size: 0x18, DWARF: 0xB02DC
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0xB02F8
    signed int game_mode; // Offset: 0x4, DWARF: 0xB031F
    signed int match_rule; // Offset: 0x8, DWARF: 0xB0345
    signed int divide; // Offset: 0xC, DWARF: 0xB036C
    signed int handicap[2]; // Offset: 0x10, DWARF: 0xB038F
} Mode;

// Size: 0xA0, DWARF: 0xAEEAE
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0xAFF5A
    Course course; // Offset: 0x0, DWARF: 0xAEECA
    // Size: 0x3C, DWARF: 0xAFB24
    CharacterState character[2]; // Offset: 0x4, DWARF: 0xAEEEF
    // Size: 0x18, DWARF: 0xB02DC
    Mode mode; // Offset: 0x7C, DWARF: 0xAEF17
    signed int language; // Offset: 0x94, DWARF: 0xAEF3A
    signed int ending; // Offset: 0x98, DWARF: 0xAEF5F
    signed int bgm_no; // Offset: 0x9C, DWARF: 0xAEF82
} VspenvGame;

// Size: 0x18, DWARF: 0xB0D75
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0xB0D91
    signed int month; // Offset: 0x4, DWARF: 0xB0DB2
    signed int day; // Offset: 0x8, DWARF: 0xB0DD4
    signed int hour; // Offset: 0xC, DWARF: 0xB0DF4
    signed int minute; // Offset: 0x10, DWARF: 0xB0E15
    signed int second; // Offset: 0x14, DWARF: 0xB0E38
} Clock;

// Size: 0x38, DWARF: 0xB1447
typedef struct File
{
    // Size: 0x18, DWARF: 0xB0D75
    Clock clock; // Offset: 0x0, DWARF: 0xB1463
    char name[32]; // Offset: 0x18, DWARF: 0xB1487
} File;

// Size: 0x20, DWARF: 0xB1111
typedef struct Record
{
    signed int chr_no; // Offset: 0x0, DWARF: 0xB112D
    unsigned long score; // Offset: 0x8, DWARF: 0xB1150
    char name[16]; // Offset: 0x10, DWARF: 0xB1172
} Record;

// Size: 0x4, DWARF: 0xAB6D4
typedef struct BestTime
{
    unsigned int time; // Offset: 0x0, DWARF: 0xAB6EF
} BestTime;

// Size: 0x24, DWARF: 0xAC235
typedef struct KeyConfig
{
    signed int vibration; // Offset: 0x0, DWARF: 0xAC250
    signed int spin_l; // Offset: 0x4, DWARF: 0xAC276
    signed int spin_r; // Offset: 0x8, DWARF: 0xAC299
    signed int stance; // Offset: 0xC, DWARF: 0xAC2BC
    signed int revert; // Offset: 0x10, DWARF: 0xAC2DF
    signed int grind; // Offset: 0x14, DWARF: 0xAC302
    signed int grab; // Offset: 0x18, DWARF: 0xAC324
    signed int jump; // Offset: 0x1C, DWARF: 0xAC345
    signed int flip; // Offset: 0x20, DWARF: 0xAC366
} KeyConfig;

// Size: 0x30, DWARF: 0xACF01
typedef struct Cheats //: <unknown type 0xA0008>
{
    signed int kids; // Offset: 0x0, DWARF: 0xACF1D
    signed int always_sp; // Offset: 0x4, DWARF: 0xACF3E
    signed int perfect_b; // Offset: 0x8, DWARF: 0xACF64
    signed int super_spin; // Offset: 0xC, DWARF: 0xACF8A
    signed int half_g; // Offset: 0x10, DWARF: 0xACFB1
    signed int fast_motion; // Offset: 0x14, DWARF: 0xACFD4
    signed int super_speed; // Offset: 0x18, DWARF: 0xACFFC
    signed int big_head; // Offset: 0x1C, DWARF: 0xAD024
    signed int metallic; // Offset: 0x20, DWARF: 0xAD049
    signed int mirror; // Offset: 0x24, DWARF: 0xAD06E
    signed int replay_view; // Offset: 0x28, DWARF: 0xAD091
    signed int partition; // Offset: 0x2C, DWARF: 0xAD0B9
} Cheats;

// Size: 0x8, DWARF: 0xACA4B
typedef struct Volume //: signed int
{
    signed int se; // Offset: 0x0, DWARF: 0xACA67 // Sound Effects Volume
    signed int bgm; // Offset: 0x4, DWARF: 0xACA86 // Background Music Volume
} Volume;

// Size: 0x48, DWARF: 0xAE469
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0xAE485
    signed int disable; // Offset: 0x40, DWARF: 0xAE4A9
    signed int random; // Offset: 0x44, DWARF: 0xAE4CD
} Bgm;

// Size: 0x114, DWARF: 0xAE84B
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0xAC235
    KeyConfig key_config[2]; // Offset: 0x0, DWARF: 0xAE867
    // Size: 0x30, DWARF: 0xACF01
    Cheats enable; // Offset: 0x48, DWARF: 0xAE890
    // Size: 0x30, DWARF: 0xACF01
    Cheats cheats; // Offset: 0x78, DWARF: 0xAE8B5
    // Size: 0x8, DWARF: 0xACA4B
    Volume volume; // Offset: 0xA8, DWARF: 0xAE8DA
    char name[16]; // Offset: 0xB0, DWARF: 0xAE8FF
    signed int divide; // Offset: 0xC0, DWARF: 0xAE922
    signed int tutorial; // Offset: 0xC4, DWARF: 0xAE945
    // Size: 0x48, DWARF: 0xAE469
    Bgm bgm; // Offset: 0xC8, DWARF: 0xAE96A
    unsigned int movie; // Offset: 0x110, DWARF: 0xAE98C
} VspenvOption;

// Size: 0x74, DWARF: 0xAF08B
typedef struct Character
{
    signed int secret; // Offset: 0x0, DWARF: 0xAF0A7
    unsigned int board; // Offset: 0x4, DWARF: 0xAF0CA
    unsigned int course; // Offset: 0x8, DWARF: 0xAF0EC
    signed int rem_point; // Offset: 0xC, DWARF: 0xAF10F
    signed int old_brd_no; // Offset: 0x10, DWARF: 0xAF135
    signed int old_wear_no; // Offset: 0x14, DWARF: 0xAF15C
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0xAF184
    signed int soft[8]; // Offset: 0x38, DWARF: 0xAF1AD
    // Size: 0x1C, DWARF: 0xAEC73
    CharacterParameters parameter; // Offset: 0x58, DWARF: 0xAF1D0
} Character;

// Size: 0xEC, DWARF: 0xABF3E
typedef struct CreateCharacter
{
    // Size: 0x74, DWARF: 0xAF08B
    Character character; // Offset: 0x0, DWARF: 0xABF59
    // Size: 0x1C, DWARF: 0xAEC73
    CharacterParameters init_param; // Offset: 0x74, DWARF: 0xABF81
    // Size: 0x18, DWARF: 0xB0D75
    Clock clock; // Offset: 0x90, DWARF: 0xABFAA
    char name[16]; // Offset: 0xA8, DWARF: 0xABFCE
    signed int age; // Offset: 0xB8, DWARF: 0xABFF1
    signed int sex; // Offset: 0xBC, DWARF: 0xAC011
    signed int face; // Offset: 0xC0, DWARF: 0xAC031
    signed int hair; // Offset: 0xC4, DWARF: 0xAC052
    signed int hair_color; // Offset: 0xC8, DWARF: 0xAC073
    signed int body; // Offset: 0xCC, DWARF: 0xAC09A
    signed int body_color; // Offset: 0xD0, DWARF: 0xAC0BB
    signed int pants; // Offset: 0xD4, DWARF: 0xAC0E2
    signed int pants_color; // Offset: 0xD8, DWARF: 0xAC104
    signed int glove; // Offset: 0xDC, DWARF: 0xAC12C
    signed int boots; // Offset: 0xE0, DWARF: 0xAC14E
    signed int board_type; // Offset: 0xE4, DWARF: 0xAC170
    signed int trick_type; // Offset: 0xE8, DWARF: 0xAC197
} CreateCharacter;

// Size: 0xEF8, DWARF: 0xAFF99
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0xAF08B
    Character character[12]; // Offset: 0x0, DWARF: 0xAFFB5
    // Size: 0xEC, DWARF: 0xABF3E
    CreateCharacter create_character[10]; // Offset: 0x570, DWARF: 0xAFFDD
    // Size: 0x8, DWARF: 0xB0B65
    Course2 course[8]; // Offset: 0xEA8, DWARF: 0xB000C
    signed int tour_round; // Offset: 0xEE8, DWARF: 0xB0031
    signed int old_char; // Offset: 0xEEC, DWARF: 0xB0058
    signed int first_clear; // Offset: 0xEF0, DWARF: 0xB007D
} VspenvSecret;

// Size: 0x8, DWARF: 0xAC797
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0xAC7B3
    signed char lh; // Offset: 0x2, DWARF: 0xAC7D3
    signed char lv; // Offset: 0x3, DWARF: 0xAC7F2
    signed int analog; // Offset: 0x4, DWARF: 0xAC811
} PadData;

// Size: 0x1668, DWARF: 0xABE65
typedef struct MemCard
{
    // Size: 0x38, DWARF: 0xB1447
    File file; // Offset: 0x0, DWARF: 0xABE80
    // Size: 0x20, DWARF: 0xB1111
    Record record[8][6]; // Offset: 0x38, DWARF: 0xABEA3
    // Size: 0x4, DWARF: 0xAB6D4
    BestTime best_time[8]; // Offset: 0x638, DWARF: 0xABEC8
    // Size: 0x114, DWARF: 0xAE84B
    VspenvOption option; // Offset: 0x658, DWARF: 0xABEF0
    // Size: 0xEF8, DWARF: 0xAFF99
    VspenvSecret secret; // Offset: 0x770, DWARF: 0xABF15
} MemCard;

// Size: 0x2DCEC, DWARF: 0xACBB7
typedef struct VspenvReplay
{
    // Size: 0x38, DWARF: 0xB1447
    File file; // Offset: 0x0, DWARF: 0xACBD3
    signed int pid; // Offset: 0x38, DWARF: 0xACBF6
    signed int num_frame; // Offset: 0x3C, DWARF: 0xACC16
    unsigned int game_time; // Offset: 0x40, DWARF: 0xACC3C
    signed int endrun_frame; // Offset: 0x44, DWARF: 0xACC62
    // Size: 0x8, DWARF: 0xAC797
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0xACC8B
    // Size: 0x24, DWARF: 0xAC235
    KeyConfig key; // Offset: 0x2DB88, DWARF: 0xACCB2
    // Size: 0xEC, DWARF: 0xABF3E
    CreateCharacter character; // Offset: 0x2DBAC, DWARF: 0xACCD4
    // Size: 0x30, DWARF: 0xACF01
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0xACCFC
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0xACD21
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0xACD44
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0xACD67
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0xACD8B
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0xACDAE
    // Size: 0x10, DWARF: 0xAF499
    BoardParameters brd_param; // Offset: 0x2DCDC, DWARF: 0xACDD4
} VspenvReplay;

// Size: 0x10, DWARF: 0xAC496
typedef struct VspDispVsScore
{
    signed int win; // Offset: 0x0, DWARF: 0xAC4B1
    signed int lose; // Offset: 0x4, DWARF: 0xAC4D1
    signed int draw; // Offset: 0x8, DWARF: 0xAC4F2
    signed int res; // Offset: 0xC, DWARF: 0xAC513
} VspDispVsScore;

// Size: 0x5D0E0, DWARF: 0xAE320
typedef struct VspenvEnv
{
    // Size: 0xA0, DWARF: 0xAEEAE
    VspenvGame game; // Offset: 0x0, DWARF: 0xAE33C
    // Size: 0x1668, DWARF: 0xABE65
    MemCard mc; // Offset: 0xA0, DWARF: 0xAE35F
    // Size: 0x2DCEC, DWARF: 0xACBB7
    VspenvReplay replay[2]; // Offset: 0x1708, DWARF: 0xAE380
} VspenvEnv;

// Size: 0x64, DWARF: 0xAE09B
typedef struct VsploadSoundData
{
    signed int retry; // Offset: 0x0, DWARF: 0xAE0B7
    unsigned int sq_addr; // Offset: 0x4, DWARF: 0xAE0D9
    unsigned int bd_addr; // Offset: 0x8, DWARF: 0xAE0FD
    unsigned int hd_addr; // Offset: 0xC, DWARF: 0xAE121
    signed int sq_trans; // Offset: 0x10, DWARF: 0xAE145
    signed int sq_no; // Offset: 0x14, DWARF: 0xAE16A
    signed int sq_error; // Offset: 0x18, DWARF: 0xAE18C
    signed int vc_trans[6]; // Offset: 0x1C, DWARF: 0xAE1B1
    unsigned int vc_addr[6]; // Offset: 0x34, DWARF: 0xAE1D8
    unsigned int vc_size[6]; // Offset: 0x4C, DWARF: 0xAE1FE
} VsploadSoundData;

// Size: 0x9C, DWARF: 0xAB761
typedef struct VsploadGameEtc
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xAB77C
    unsigned char* replay_camera; // Offset: 0x4, DWARF: 0xAB7A0
    unsigned char* intro_camera; // Offset: 0x8, DWARF: 0xAB7CD
    unsigned char* accelerate; // Offset: 0xC, DWARF: 0xAB7F9
    unsigned char* group; // Offset: 0x10, DWARF: 0xAB823
    unsigned int* vib_link[2]; // Offset: 0x14, DWARF: 0xAB848
    char* vib_com[16]; // Offset: 0x1C, DWARF: 0xAB86F
    char* vib_evt[16]; // Offset: 0x5C, DWARF: 0xAB895
} VsploadGameEtc;

// Size: 0x20, DWARF: 0xADB17
typedef struct ModelData
{
    float pos[4]; // Offset: 0x0, DWARF: 0xADB33
    float rot[4]; // Offset: 0x10, DWARF: 0xADB55
} ModelData;

// Size: 0x10, DWARF: 0xAF572
typedef struct Pos
{
    unsigned int type; // Offset: 0x0, DWARF: 0xAF58E
    float frame; // Offset: 0x4, DWARF: 0xAF5AF
    signed short flg; // Offset: 0x8, DWARF: 0xAF5D1
    signed short non; // Offset: 0xA, DWARF: 0xAF5F1
    sceVu0FVECTOR* data; // Offset: 0xC, DWARF: 0xAF611
} Pos;

// Size: 0xF0, DWARF: 0xABA3B
typedef struct Seq
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0xABA56
    signed int loop; // Offset: 0x4, DWARF: 0xABA7B
    signed int mode; // Offset: 0x8, DWARF: 0xABA9C
    signed int write_flg; // Offset: 0xC, DWARF: 0xABABD
    signed int now_local_id; // Offset: 0x10, DWARF: 0xABAE3
    signed int now_top_id; // Offset: 0x14, DWARF: 0xABB0C
    signed int next_local_id; // Offset: 0x18, DWARF: 0xABB33
    signed int next_top_id; // Offset: 0x1C, DWARF: 0xABB5D
    // Size: 0x20, DWARF: 0xADB17
    ModelData* mdl_data; // Offset: 0x20, DWARF: 0xABB85
    float now_frame; // Offset: 0x24, DWARF: 0xABBAF
    float next_frame; // Offset: 0x28, DWARF: 0xABBD5
    float ratio; // Offset: 0x2C, DWARF: 0xABBFC
    // Size: 0x10, DWARF: 0xAF572
    Pos* now_pos_address; // Offset: 0x30, DWARF: 0xABC1E
    // Size: 0x10, DWARF: 0xAF572
    Pos* now_rot_address; // Offset: 0x34, DWARF: 0xABC4F
    // Size: 0x10, DWARF: 0xAF572
    Pos* next_pos_address; // Offset: 0x38, DWARF: 0xABC80
    // Size: 0x10, DWARF: 0xAF572
    Pos* next_rot_address; // Offset: 0x3C, DWARF: 0xABCB2
    float nowDir[4]; // Offset: 0x40, DWARF: 0xABCE4
    float nowTrans[4]; // Offset: 0x50, DWARF: 0xABD09
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0xABD30
    float pos[4]; // Offset: 0xA0, DWARF: 0xABD59
    float quat[4]; // Offset: 0xB0, DWARF: 0xABD7B
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0xABD9E
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0xABDC4
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0xABDEA
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0xABE15
    signed int pad[2]; // Offset: 0xE8, DWARF: 0xABE3F
} Seq;

// Size: 0x230, DWARF: 0xBD1F1
typedef struct IkParam // : float[4][4]
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

// Size: 0x2E0, DWARF: 0xAC584
typedef struct Ctrl
{
    float rot[4]; // Offset: 0x0, DWARF: 0xAC59F
    float trans[4]; // Offset: 0x10, DWARF: 0xAC5C1
    float scale[4]; // Offset: 0x20, DWARF: 0xAC5E5
    float matrix[4][4]; // Offset: 0x30, DWARF: 0xAC609
    float revision[4][4]; // Offset: 0x70, DWARF: 0xAC62E
    // Size: 0x230, DWARF: 0xAF662
    IkParam ikparam; // Offset: 0xB0, DWARF: 0xAC655
} Ctrl;

// Size: 0x1A0, DWARF: 0xB0F88
typedef struct Sctrl //: signed int[3]
{
    signed int type; // Offset: 0x0, DWARF: 0xB0FA4
    float power; // Offset: 0x4, DWARF: 0xB0FC5
    float dir; // Offset: 0x8, DWARF: 0xB0FE7
    float cnt; // Offset: 0xC, DWARF: 0xB1007
    float head[4]; // Offset: 0x10, DWARF: 0xB1027
    float preHead[4]; // Offset: 0x20, DWARF: 0xB104A
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0xB1070
    float g_vector[4]; // Offset: 0x170, DWARF: 0xB109A
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0xB10C1
    signed int pad[3]; // Offset: 0x194, DWARF: 0xB10EB
} Sctrl;

// Size: 0x10, DWARF: 0xAB90C
typedef struct Tex
{
    signed short tofs; // Offset: 0x0, DWARF: 0xAB927
    signed short cofs; // Offset: 0x2, DWARF: 0xAB948
    signed short width; // Offset: 0x4, DWARF: 0xAB969
    signed short height; // Offset: 0x6, DWARF: 0xAB98B
    signed short tw; // Offset: 0x8, DWARF: 0xAB9AE
    signed short th; // Offset: 0xA, DWARF: 0xAB9CD
    signed short image_bit; // Offset: 0xC, DWARF: 0xAB9EC
    signed short clut_bit; // Offset: 0xE, DWARF: 0xABA12
} Tex;

// Size: 0x20, DWARF: 0xB0BEF
// Size: 0x20, DWARF: 0xD019D
typedef struct Utd
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0xB0C0B
    // Size: 0x10, DWARF: 0xAB90C
    Tex* tex; // Offset: 0x4, DWARF: 0xB0C2E
    signed int ntex; // Offset: 0x8, DWARF: 0xB0C53
    signed int offset; // Offset: 0xC, DWARF: 0xB0C74
    signed int block; // Offset: 0x10, DWARF: 0xB0C97
    unsigned int* frame; // Offset: 0x14, DWARF: 0xB0CB9
    signed int res[2]; // Offset: 0x18, DWARF: 0xB0CDE
} Utd;

// Size: 0x90, DWARF: 0xACAAA
typedef struct Change
{
    sceVu0FMATRIX original; // Offset: 0x0, DWARF: 0xACAC6
    sceVu0FMATRIX original2; // Offset: 0x40, DWARF: 0xACAED
    sceVu0FMATRIX* address; // Offset: 0x80, DWARF: 0xACB15
    sceVu0FMATRIX* address2; // Offset: 0x84, DWARF: 0xACB3E
    signed int pad[2]; // Offset: 0x88, DWARF: 0xACB68
} Change;

// Size: 0x4B0, DWARF: 0xB11E6
typedef struct Soft
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xB1202
    __int128* umd; // Offset: 0x4, DWARF: 0xB1226
    __int128* smd; // Offset: 0x8, DWARF: 0xB1249
    unsigned int* utd; // Offset: 0xC, DWARF: 0xB126C
    // Size: 0x10, DWARF: 0xAB90C
    Tex* tex; // Offset: 0x10, DWARF: 0xB128F
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* seq; // Offset: 0x14, DWARF: 0xB12B4
    signed int block; // Offset: 0x18, DWARF: 0xB12D9
    unsigned int* frame; // Offset: 0x1C, DWARF: 0xB12FB
    signed int res; // Offset: 0x20, DWARF: 0xB1320
    // Size: 0x2E0, DWARF: 0xAC584
    Ctrl ctrl; // Offset: 0x30, DWARF: 0xB1340
    // Size: 0x1A0, DWARF: 0xB0F88
    Sctrl sctrl; // Offset: 0x310, DWARF: 0xB1363
} Soft;

// Size: 0x500, DWARF: 0xAD7FD
typedef struct VsploadGame2D
{
    // Size: 0x20, DWARF: 0xB0BEF
    Utd game; // Offset: 0x0, DWARF: 0xAD819
    // Size: 0x20, DWARF: 0xB0BEF
    Utd result; // Offset: 0x20, DWARF: 0xAD83C
    // Size: 0x4B0, DWARF: 0xB11E6
    Soft soft; // Offset: 0x40, DWARF: 0xAD861
    __int128* board_umd; // Offset: 0x4F0, DWARF: 0xAD884
    unsigned int* board_utd; // Offset: 0x4F4, DWARF: 0xAD8AD
    unsigned int* ayboard_utd; // Offset: 0x4F8, DWARF: 0xAD8D6
    // Size: 0x10, DWARF: 0xAB90C
    Tex* board_tex; // Offset: 0x4FC, DWARF: 0xAD901
} VsploadGame2D;

// Size: 0x20, DWARF: 0xAE619
typedef struct ReadData
{
    signed int* addr; // Offset: 0x0, DWARF: 0xAE635
    signed short que_no; // Offset: 0x4, DWARF: 0xAE659
    signed short no; // Offset: 0x6, DWARF: 0xAE67C
    signed short tail; // Offset: 0x8, DWARF: 0xAE69B
    signed short id; // Offset: 0xA, DWARF: 0xAE6BC
    signed short align; // Offset: 0xC, DWARF: 0xAE6DB
    signed short ee_iop; // Offset: 0xE, DWARF: 0xAE6FD
    void(*func)(void*, signed int, signed int, signed int, signed int); // Offset: 0x10, DWARF: 0xAE720
    signed int src[3]; // Offset: 0x14, DWARF: 0xAE746
} ReadData;

// Size: 0x10, DWARF: 0xBCA3C
typedef struct PosAddress //: const volatile float[4]
{
    unsigned int type; // Offset: 0x0, DWARF: 0xBCA58
    float frame; // Offset: 0x4, DWARF: 0xBCA79
    signed short flg; // Offset: 0x8, DWARF: 0xBCA9B
    signed short non; // Offset: 0xA, DWARF: 0xBCABB
    sceVu0FVECTOR* data; // Offset: 0xC, DWARF: 0xBCADB
} PosAddress;


// Size: 0x90, DWARF: 0xBA905
typedef struct ModelChange
{
    sceVu0FMATRIX original; // Offset: 0x0, DWARF: 0xBA920
    sceVu0FMATRIX original2; // Offset: 0x40, DWARF: 0xBA947
    sceVu0FMATRIX* address; // Offset: 0x80, DWARF: 0xBA96F
    sceVu0FMATRIX* address2; // Offset: 0x84, DWARF: 0xBA998
    signed int pad[2]; // Offset: 0x88, DWARF: 0xBA9C2
} ModelChange;

// Size: 0x1A0, DWARF: 0xBBA84
typedef struct SmdCtrl // : signed int[3]
{
    signed int type; // Offset: 0x0, DWARF: 0xBBAA0
    float power; // Offset: 0x4, DWARF: 0xBBAC1
    float dir; // Offset: 0x8, DWARF: 0xBBAE3
    float cnt; // Offset: 0xC, DWARF: 0xBBB03
    float head[4]; // Offset: 0x10, DWARF: 0xBBB23
    float preHead[4]; // Offset: 0x20, DWARF: 0xBBB46
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0xBBB6C
    float g_vector[4]; // Offset: 0x170, DWARF: 0xBBB96
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0xBBBBD
    signed int pad[3]; // Offset: 0x194, DWARF: 0xBBBE7
} SmdCtrl;

// Size: 0x2E0, DWARF: 0xC6434
typedef struct ModelCtrl // Size: 0x230, DWARF: 0xCE030
{
    float rot[4]; // Offset: 0x0, DWARF: 0xC6450
    float trans[4]; // Offset: 0x10, DWARF: 0xC6472
    float scale[4]; // Offset: 0x20, DWARF: 0xC6496
    float matrix[4][4]; // Offset: 0x30, DWARF: 0xC64BA
    float revision[4][4]; // Offset: 0x70, DWARF: 0xC64DF
    // Size: 0x230, DWARF: 0xCE030
    IkParam ikparam; // Offset: 0xB0, DWARF: 0xC6506
} ModelCtrl;

// Size: 0x1A0, DWARF: 0xCC282
typedef struct SCtrl //: signed int[3]
{
    signed int type; // Offset: 0x0, DWARF: 0xCC29E
    float power; // Offset: 0x4, DWARF: 0xCC2BF
    float dir; // Offset: 0x8, DWARF: 0xCC2E1
    float cnt; // Offset: 0xC, DWARF: 0xCC301
    float head[4]; // Offset: 0x10, DWARF: 0xCC321
    float preHead[4]; // Offset: 0x20, DWARF: 0xCC344
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0xCC36A
    float g_vector[4]; // Offset: 0x170, DWARF: 0xCC394
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0xCC3BB
    signed int pad[3]; // Offset: 0x194, DWARF: 0xCC3E5
} SCtrl;

// Size: 0x960, DWARF: 0xC2738, 0xBED22
typedef struct Model
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xC2753
    unsigned char* vmd[2]; // Offset: 0x4, DWARF: 0xC2777
    // Size: 0xF0, DWARF: 0xC5DDA
    Seq* seq; // Offset: 0xC, DWARF: 0xC2799
    // Size: 0x2E0, DWARF: 0xC6434
    ModelCtrl ctrl[2]; // Offset: 0x10, DWARF: 0xC27BE
    // Size: 0x1A0, DWARF: 0xCC282
    SCtrl sctrl[2]; // Offset: 0x5D0, DWARF: 0xC27E1
    // Size: 0x20, DWARF: 0xD019D
    Utd utd[2]; // Offset: 0x910, DWARF: 0xC2805
    // Size: 0x90, DWARF: 0xC6A35
    Change* change[2]; // Offset: 0x950, DWARF: 0xC2827
} Model;

// Size: 0x12F0, DWARF: 0xC7295, 0xB9FFE
typedef struct Cd //: unsigned long[2] // Same as vsploadCharacter (and Cd from spfree.c)
{
    // Size: 0x960, DWARF: 0xC2738
    Model model[2]; // Offset: 0x0, DWARF: 0xC72B1
    unsigned int* link; // Offset: 0x12C0, DWARF: 0xC72D5
    __int128* regular_uad; // Offset: 0x12C4, DWARF: 0xC72F9
    __int128* fakie_uad; // Offset: 0x12C8, DWARF: 0xC7324
    __int128* goal_uad; // Offset: 0x12CC, DWARF: 0xC734D
    __int128* mode_uad; // Offset: 0x12D0, DWARF: 0xC7375
    unsigned long envmap_tex0[2]; // Offset: 0x12D8, DWARF: 0xC739D
} Cd;

// Size: 0x10, DWARF: 0xAD0E3
typedef struct VsploadGameCommon // Size: 0x9C, DWARF: 0xAB761
{
    // Size: 0x3BC, DWARF: 0xAD1A1
    Course3* course; // Offset: 0x0, DWARF: 0xAD0FF
    // Size: 0x12F0, DWARF: 0xAD5FC
    Cd* character; // Offset: 0x4, DWARF: 0xAD127
    // Size: 0x500, DWARF: 0xAD7FD
    VsploadGame2D* game; // Offset: 0x8, DWARF: 0xAD152
    // Size: 0x9C, DWARF: 0xAB761
    VsploadGameEtc* etc; // Offset: 0xC, DWARF: 0xAD178
} VsploadGameCommon;

// Size: 0x10, DWARF: 0xAC886
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0xAC8A2
    __int128* pBase; // Offset: 0x4, DWARF: 0xAC8CA
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0xAC8EF
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0xAC916
} VgmsysGifPkt;

// Size: 0x260, DWARF: 0xAF2FB
typedef struct VsploadCommon // Size: 0x10, DWARF: 0xAB90C
{
    signed int offset; // Offset: 0x0, DWARF: 0xAF317
    unsigned int* font; // Offset: 0x4, DWARF: 0xAF33A
    // Size: 0x10, DWARF: 0xAB90C
    Tex* font_tex; // Offset: 0x8, DWARF: 0xAF35E
    unsigned int* effect; // Offset: 0xC, DWARF: 0xAF388
    // Size: 0x10, DWARF: 0xAB90C
    Tex* effect_tex; // Offset: 0x10, DWARF: 0xAF3AE
    unsigned int* load; // Offset: 0x14, DWARF: 0xAF3DA
    // Size: 0x10, DWARF: 0xAB90C
    Tex* load_tex; // Offset: 0x18, DWARF: 0xAF3FE
    signed int profile; // Offset: 0x1C, DWARF: 0xAF428
    // Size: 0x10, DWARF: 0xAB90C
    Tex sponsor[29]; // Offset: 0x20, DWARF: 0xAF44C
    // Size: 0x10, DWARF: 0xAB90C
    Tex face[7]; // Offset: 0x1F0, DWARF: 0xAF472
} VsploadCommon;

// Size: 0x960, DWARF: 0xAC67F
typedef struct CharacterModel // Size: 0x90, DWARF: 0xACAAA
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xAC69A
    unsigned char* vmd[2]; // Offset: 0x4, DWARF: 0xAC6BE
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* seq; // Offset: 0xC, DWARF: 0xAC6E0
    // Size: 0x2E0, DWARF: 0xAC584
    Ctrl ctrl[2]; // Offset: 0x10, DWARF: 0xAC705
    // Size: 0x1A0, DWARF: 0xB0F88
    SCtrl sctrl[2]; // Offset: 0x5D0, DWARF: 0xAC728
    // Size: 0x20, DWARF: 0xB0BEF
    Utd utd[2]; // Offset: 0x910, DWARF: 0xAC74C
    // Size: 0x90, DWARF: 0xACAAA
    Change* change[2]; // Offset: 0x950, DWARF: 0xAC76E
} CharacterModel;

// Size: 0x378, DWARF: 0xADBC6
typedef struct CreateCharacterModel
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xADBE2
    __int128* face_umd[9]; // Offset: 0x4, DWARF: 0xADC06
    unsigned int* face_utd[9]; // Offset: 0x28, DWARF: 0xADC2D
    // Size: 0x10, DWARF: 0xAB90C
    Tex* face_tex[9]; // Offset: 0x4C, DWARF: 0xADC54
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* face_seq[9]; // Offset: 0x70, DWARF: 0xADC7B
    __int128* hair_umd[4][2]; // Offset: 0x94, DWARF: 0xADCA2
    unsigned int* hair_utd[4][4][2]; // Offset: 0xB4, DWARF: 0xADCC9
    // Size: 0x10, DWARF: 0xAB90C
    Tex* hair_tex[4][2]; // Offset: 0x134, DWARF: 0xADCF0
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* hair_seq[4]; // Offset: 0x154, DWARF: 0xADD17
    __int128* body_umd[5]; // Offset: 0x164, DWARF: 0xADD3E
    unsigned int* body_utd[5][9]; // Offset: 0x178, DWARF: 0xADD65
    // Size: 0x10, DWARF: 0xAB90C
    Tex* body_tex[5]; // Offset: 0x22C, DWARF: 0xADD8C
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* body_seq[5]; // Offset: 0x240, DWARF: 0xADDB3
    __int128* pants_umd[5]; // Offset: 0x254, DWARF: 0xADDDA
    unsigned int* pants_utd[5][8]; // Offset: 0x268, DWARF: 0xADE02
    // Size: 0x10, DWARF: 0xAB90C
    Tex* pants_tex[5]; // Offset: 0x308, DWARF: 0xADE2A
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* pants_seq[5]; // Offset: 0x31C, DWARF: 0xADE52
    __int128* glove_umd; // Offset: 0x330, DWARF: 0xADE7A
    unsigned int* glove_utd[4]; // Offset: 0x334, DWARF: 0xADEA3
    // Size: 0x10, DWARF: 0xAB90C
    Tex* glove_tex; // Offset: 0x344, DWARF: 0xADECB
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* glove_seq; // Offset: 0x348, DWARF: 0xADEF6
    __int128* boots_umd; // Offset: 0x34C, DWARF: 0xADF21
    unsigned int* boots_utd[4]; // Offset: 0x350, DWARF: 0xADF4A
    // Size: 0x10, DWARF: 0xAB90C
    Tex* boots_tex; // Offset: 0x360, DWARF: 0xADF72
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* boots_seq; // Offset: 0x364, DWARF: 0xADF9D
    __int128* board_umd; // Offset: 0x368, DWARF: 0xADFC8
    unsigned int* board_utd; // Offset: 0x36C, DWARF: 0xADFF1
    // Size: 0x10, DWARF: 0xAB90C
    Tex* board_tex; // Offset: 0x370, DWARF: 0xAE01A
    // Size: 0xF0, DWARF: 0xABA3B
    Seq* board_seq; // Offset: 0x374, DWARF: 0xAE045
} CreateCharacterModel;

// Size: 0x16720, DWARF: 0xB0405
typedef struct VsploadSelect
{
    unsigned int* link[2]; // Offset: 0x0, DWARF: 0xB0421
    signed int offset; // Offset: 0x8, DWARF: 0xB0444
    unsigned int* env_utd; // Offset: 0xC, DWARF: 0xB0467
    // Size: 0x10, DWARF: 0xAB90C
    Tex* env_tex; // Offset: 0x10, DWARF: 0xB048E
    unsigned int* select_utd; // Offset: 0x14, DWARF: 0xB04B7
    unsigned int* selmov_utd; // Offset: 0x18, DWARF: 0xB04E1
    unsigned int* sponsor_utd; // Offset: 0x1C, DWARF: 0xB050B
    // Size: 0x10, DWARF: 0xAB90C
    Tex* sponsor_tex; // Offset: 0x20, DWARF: 0xB0536
    unsigned int* medal_utd; // Offset: 0x24, DWARF: 0xB0563
    // Size: 0x10, DWARF: 0xAB90C
    Tex* medal_tex; // Offset: 0x28, DWARF: 0xB058C
    __int128* medal_umd[3]; // Offset: 0x2C, DWARF: 0xB05B7
    __int128* board_umd; // Offset: 0x38, DWARF: 0xB05DF
    unsigned char* board_vmd; // Offset: 0x3C, DWARF: 0xB0608
    unsigned int* board_utd; // Offset: 0x40, DWARF: 0xB0631
    unsigned int* ayboard_utd; // Offset: 0x44, DWARF: 0xB065A
    // Size: 0x10, DWARF: 0xAB90C
    Tex* board_tex; // Offset: 0x48, DWARF: 0xB0685
    unsigned int* emblem_utd; // Offset: 0x4C, DWARF: 0xB06B0
    // Size: 0x10, DWARF: 0xAB90C
    Tex* emblem_tex; // Offset: 0x50, DWARF: 0xB06DA
    __int128* emblem_umd[2]; // Offset: 0x54, DWARF: 0xB0706
    __int128* select_uad; // Offset: 0x5C, DWARF: 0xB072F
    // Size: 0x960, DWARF: 0xAC67F
    CharacterModel character[12][3]; // Offset: 0x60, DWARF: 0xB0759
    // Size: 0x378, DWARF: 0xADBC6
    CreateCharacterModel create_chr[2]; // Offset: 0x151E0, DWARF: 0xB0781
    unsigned int* cr_arm_utd; // Offset: 0x158D0, DWARF: 0xB07AA
    unsigned int* cr_leg_utd; // Offset: 0x158D4, DWARF: 0xB07D4
    unsigned int* cr_arm_f_utd; // Offset: 0x158D8, DWARF: 0xB07FE
    // Size: 0x4B0, DWARF: 0xB11E6
    Soft game; // Offset: 0x158E0, DWARF: 0xB082A
    // Size: 0x4B0, DWARF: 0xB11E6
    Soft wheel; // Offset: 0x15D90, DWARF: 0xB084D
    // Size: 0x4B0, DWARF: 0xB11E6
    Soft param; // Offset: 0x16240, DWARF: 0xB0871
    __int128* pad_umd[9]; // Offset: 0x166F0, DWARF: 0xB0895
    unsigned int* pad_utd; // Offset: 0x16714, DWARF: 0xB08BB
    // Size: 0x10, DWARF: 0xAB90C
    Tex* pad_tex; // Offset: 0x16718, DWARF: 0xB08E2
} VsploadSelect;

// Size: 0x10, DWARF: 0xAFED2
typedef struct VsploadMovie
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0xAFEEE
    signed int offset; // Offset: 0x4, DWARF: 0xAFF11
    signed int res[2]; // Offset: 0x8, DWARF: 0xAFF34
} VsploadMovie;

// Size: 0x60, DWARF: 0xADA05
typedef struct VsploadVibration
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xADA21
    char* data[23]; // Offset: 0x4, DWARF: 0xADA45
} VsploadVibration;

// Size: 0x1C, DWARF: 0xACE73
typedef struct VsploadIcon
{
    unsigned int* link; // Offset: 0x0, DWARF: 0xACE8F
    unsigned int* system[3]; // Offset: 0x4, DWARF: 0xACEB3
    unsigned int* replay[3]; // Offset: 0x10, DWARF: 0xACED8
} VsploadIcon;

// Size: 0x10, DWARF: 0xAF272
typedef struct VsploadReplayHead
{
    signed int pnum; // Offset: 0x0, DWARF: 0xAF28E
    signed int handicap[2]; // Offset: 0x4, DWARF: 0xAF2AF
    signed int rule; // Offset: 0xC, DWARF: 0xAF2D6
} VsploadReplayHead;

// Size: 0x10, DWARF: 0xADA93, 0xAB80F
typedef struct DataBlock
{
    signed int addr; // Offset: 0x0, DWARF: 0xADAAF
    signed int size; // Offset: 0x4, DWARF: 0xADAD0
    signed int res[2]; // Offset: 0x8, DWARF: 0xADAF1
} DataBlock;

 // Size: 0x10, DWARF: 0xAD732, 0xAAB5B
typedef struct DataHead
{
    char magic[4]; // Offset: 0x0, DWARF: 0xAD74E
    signed int ver; // Offset: 0x4, DWARF: 0xAD772
    signed int num; // Offset: 0x8, DWARF: 0xAD792
    signed int res; // Offset: 0xC, DWARF: 0xAD7B2
} DataHead; 

// Size: 0x8, DWARF: 0xAE2B3, 0xABB08
typedef struct Data // Size: 0x10, DWARF: 0xADA93
{
    // Size: 0x10, DWARF: 0xAD732
    DataHead* head; // Offset: 0x0, DWARF: 0xAE2CF
    // Size: 0x10, DWARF: 0xADA93
    DataBlock* block; // Offset: 0x4, DWARF: 0xAE2F5
} Data;

// Size: 0xE8, DWARF: 0xB0117
typedef struct VsploadCreate
{
    unsigned char* vmd[14]; // Offset: 0x0, DWARF: 0xB0133
    signed int size[14]; // Offset: 0x38, DWARF: 0xB0155
    unsigned int* utd[7]; // Offset: 0x70, DWARF: 0xB0178
    unsigned int* alpha_utd[7]; // Offset: 0x8C, DWARF: 0xB019A
    signed int ntex[7]; // Offset: 0xA8, DWARF: 0xB01C2
    signed int alpha_ntex[7]; // Offset: 0xC4, DWARF: 0xB01E5
    unsigned int* arm_utd; // Offset: 0xE0, DWARF: 0xB020E
    unsigned int* leg_utd; // Offset: 0xE4, DWARF: 0xB0235
} VsploadCreate;

//// Variables ////////////////////////////////////////////////

// Size: 0x30, DWARF: 0xAEA95
static VsploadSystem vsploadSystem; // Address: 0x3BD2C0
// Size: 0x5D0E0, DWARF: 0xAE320
extern VspenvEnv vspenvEnv; // Address: 0x3474D0
// Size: 0x10, DWARF: 0xAC496
extern VspDispVsScore vspDispVsScore; // Address: 0x3BD4A0
// Size: 0x64, DWARF: 0xAE09B
static VsploadSoundData vsploadSoundData; // Address: 0x3BD2F0
// Size: 0x10, DWARF: 0xAD0E3
static VsploadGameCommon vsploadGameCommon; // Address: 0x3A68A0
// Size: 0x9C, DWARF: 0xAB761
static VsploadGameEtc vsploadGameEtc; // Address: 0x3A4C50
// Size: 0x500, DWARF: 0xAD7FD
static VsploadGame2D vsploadGame2D; // Address: 0x3A4CF0
// Size: 0x3BC, DWARF: 0xAD1A1
static Course3 vsploadCourse; // Address: 0x3A51F0
// Size: 0x12F0, DWARF: 0xAD5FC
static Cd vsploadCharacter; // Address: 0x3A55B0
extern void(*vgmsysEndFunc)(signed int, signed int); // Address: 0x2E79AC
void(sploadEnd)(signed int, signed int); // Address: 0x18AB60
extern signed int(*vgmsysFrameFunc)(signed int); // Address: 0x2E79B0
signed int(sploadFrame)(signed int); // Address: 0x18A8E0
// Size: 0x10, DWARF: 0xAC886
extern VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
// Size: 0x260, DWARF: 0xAF2FB
static VsploadCommon vsploadCommon; // Address: 0x3BD060
// Size: 0xA0, DWARF: 0xAEEAE
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
static signed int vsploadDemoNo; // Address: 0x2E7B18
extern signed int vsppScrWidth; // Address: 0x2E7704
extern signed int vsppScrHeight; // Address: 0x2E7708
extern char* vsptblLevelGoalStr[8][3]; // Address: 0x3A45E0
extern char* vsptblCourseName[24]; // Address: 0x2B5A00
extern signed int vsptblLevelGoalValue[8][7]; // Address: 0x2B6A60
// Size: 0xEF8, DWARF: 0xAFF99
extern VspenvSecret* vspenvSecret; // Address: 0x2E7B04
// Size: 0x1C, DWARF: 0xAEC73
extern CharacterParameters vsptblCharacterParam[12]; // Address: 0x2B7160 // Note: Contains stats/parameters and stance of each character.
extern char* vsptblTrickName[160]; // Address: 0x2B6C60
extern char* vsptblCharacterName[12]; // Address: 0x2B5880
// Size: 0x16720, DWARF: 0xB0405
static VsploadSelect vsploadSelect; // Address: 0x3A68B0
// Size: 0xE8, DWARF: 0xB0117
static VsploadCreate vsploadCreate[2]; // Address: 0x3A4660
// Size: 0x60, DWARF: 0xADA05
static VsploadVibration vsploadVibration; // Address: 0x3BCFE0
// Size: 0x1C, DWARF: 0xACE73
static VsploadIcon vsploadIcon; // Address: 0x3BD040
void(sploadGetAddr)(void*, signed int, signed int, signed int, signed int); // Address: 0x18E5D0
// Size: 0x10, DWARF: 0xAFED2
static VsploadMovie vsploadMovie; // Address: 0x3BCFD0
static unsigned char* vsploadDemoData; // Address: 0x2E7B1C
// Size: 0x20, DWARF: 0xB0BEF
static Utd vsploadEnvMap; // Address: 0x3A4640
// Size: 0x2DCEC, DWARF: 0xACBB7
extern VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
void(sploadGetCreateAddr)(void*, signed int, signed int, signed int, signed int); // Address: 0x18E760
void(sploadSetSoundAddr)(void*, signed int, signed int, signed int, signed int); // Address: 0x18E600
// Size: 0x10, DWARF: 0xAF272
static VsploadReplayHead vsploadReplayHead; // Address: 0x3A4830
// Size: 0x10, DWARF: 0xAC886
static VgmsysGifPkt vsploadLocalPacket; // Address: 0x3A4C40
static __int128 vsploadLocalAddr[64]; // Address: 0x3A4840
extern signed int vtmcrsDivideNum[4]; // Address: 0x307EB0
// Size: 0x114, DWARF: 0xAE84B
extern VspenvOption* vspenvOption; // Address: 0x2E7B10

signed int sploadInit(signed int modnum);
static signed int sploadFrame(signed int modnum);
// static void sploadEnd(signed int modnum);
static void sploadDrawNowLoading(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet, signed int type, float y_pos);
static void sploadDrawLevelGoal(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet, signed int chr_no, signed int crs_no);
void sploadDrawProfile(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet, signed int chr_no, float y_pos, signed int select);
static void sploadDrawRule(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet, signed int rule);
static void sploadDrawMater(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet, float per, float y);
static void sploadDrawFace(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet, signed int chr_no, float x, float y);

static void sploadDrawSponsor(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet, signed int chr_no, float y, signed int select);
// static void sploadGetAddr(void* addr, signed int src0);
static void sploadSetSoundAddr(void* addr, signed int size, signed int type, signed int group, signed int no);
static void sploadGetCreateAddr(void* addr, signed int size, signed int player, signed int type, signed int data);
static signed int sploadCheckSoundData();
static void sploadCommon();
static void sploadMovie();
signed int nmvcGetDataState(signed int group);
signed int nmsqGetWaveState(signed int num);
static void sploadSelect();
static void sploadGameCommon();
static void sploadSetGame2D();
static void sploadSetGameEtc();
static void sploadSetCharacter();
static void sploadSetCreateCharacter(signed int player);
static void sploadSetCourse(signed int no, signed int chr);
static void sploadSetSound(signed int type, signed int no, signed int player);
static void sploadInitCommon();
static void sploadInitMovie();
static void sploadInitSelect();
static void sploadInitGameCommon();
static void sploadInitGame2D();
static void sploadInitGameEtc();
static void sploadInitCharacter();
static signed int sploadInitCreateCharacter(signed int player, signed int offset);
static void sploadInitCourse();
void sploadFreeMovie();
void sploadFreeSelect();
void sploadFreeGameCommon();
static void sploadFreeGame2D();
static void sploadFreeGameEtc();
static void sploadFreeCharacter();
static void sploadFreeCourse();
void sploadLoadSCharacter(signed int chr_no);
signed int sploadCheckSCharacter();
void sploadSetSCharacter(signed int chr_no);
void sploadFreeSCharacter(signed int chr_no);
void sploadSetCharacterTexture(signed int no);
// Size: 0x10, DWARF: 0xAF272
VsploadReplayHead* sploadGetRapHead();
// Size: 0x1C, DWARF: 0xACE73
VsploadIcon* sploadGetIconData();
// Size: 0x60, DWARF: 0xADA05
VsploadVibration* sploadGetVibrationData();
// Size: 0x10, DWARF: 0xAFED2
VsploadMovie* sploadGetMovieData();
// Size: 0x16720, DWARF: 0xB0405
VsploadSelect* sploadGetSelectData();
// Size: 0x12F0, DWARF: 0xAD5FC
Cd* sploadGetCharacter();
// Size: 0x500, DWARF: 0xAD7FD
VsploadGame2D* sploadGetGame2D();
// Size: 0x9C, DWARF: 0xAB761
VsploadGameEtc* sploadGetGameEtc();
signed int sploadGetCommonOffset();
signed int sploadInit(signed int modnum /* 0x20(r29) */);
static signed int sploadFrame(signed int modnum /* 0x30(r29) */);
// static void sploadEnd(signed int modnum /* 0x10(r29) */);
static void sploadDrawNowLoading(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet /* 0x190(r29) */, signed int type /* 0x1A0(r29) */, float y_pos /* 0x1B0(r29) */);

// DWARF: 0xB1BCF
// Address: 0x18B230
// Size: 0xCD0
static void sploadDrawLevelGoal(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet /* 0x240(r29) */, signed int chr_no /* 0x250(r29) */, signed int crs_no /* 0x260(r29) */);

// DWARF: 0xB1EA5
// Address: 0x18BF00
// Size: 0xA18
void sploadDrawProfile(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet /* 0x320(r29) */, signed int chr_no /* 0x330(r29) */, float y_pos /* 0x340(r29) */, signed int select /* 0x350(r29) */);

// DWARF: 0xB21B5
// Address: 0x18C920
// Size: 0x764
static void sploadDrawRule(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet /* 0x220(r29) */, signed int rule /* 0x230(r29) */);

// DWARF: 0xB2540
// Address: 0x18D090
// Size: 0x78C
static void sploadDrawMater(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet /* 0x70(r29) */, float per /* 0x80(r29) */, float y /* 0x90(r29) */);

// DWARF: 0xB2752
// Address: 0x18D820
// Size: 0x5B0
static void sploadDrawFace(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet /* 0x50(r29) */, signed int chr_no /* 0x60(r29) */, float x /* 0x70(r29) */, float y /* 0x80(r29) */);

// DWARF: 0xB2968
// Address: 0x18DDD0
// Size: 0x7F4
static void sploadDrawSponsor(// Size: 0x10, DWARF: 0xAC886
VgmsysGifPkt* packet /* 0xB0(r29) */, signed int chr_no /* 0xC0(r29) */, float y /* 0xD0(r29) */, signed int select /* 0xE0(r29) */);

// DWARF: 0xB2C20
// Address: 0x18E5D0
// Size: 0x24
// static void sploadGetAddr(void* addr /* r29 */, signed int src0 /* 0x20(r29) */);

// DWARF: 0xB2D19
// Address: 0x18E600
// Size: 0x160
static void sploadSetSoundAddr(void* addr /* 0x10(r29) */, signed int size /* 0x20(r29) */, signed int type /* 0x30(r29) */, signed int group /* 0x40(r29) */, signed int no /* 0x50(r29) */);

// DWARF: 0xB2EA0
// Address: 0x18E760
// Size: 0x1C8
static void sploadGetCreateAddr(void* addr /* r29 */, signed int size /* 0x10(r29) */, signed int player /* 0x20(r29) */, signed int type /* 0x30(r29) */, signed int data /* 0x40(r29) */);

// DWARF: 0xB301B
// Address: 0x18E930
// Size: 0x158
static signed int sploadCheckSoundData();

// DWARF: 0xB3145
// Address: 0x18EA90
// Size: 0x144
static void sploadCommon();

// DWARF: 0xB324B
// Address: 0x18EBE0
// Size: 0x80
static void sploadMovie();

// DWARF: 0xB3340
// Address: 0x18EC60
// Size: 0xD0C
static void sploadSelect();

// DWARF: 0xB34CC
// Address: 0x18F970
// Size: 0x1CC
static void sploadGameCommon();

// DWARF: 0xB3639
// Address: 0x18FB40
// Size: 0x240
static void sploadSetGame2D();

// DWARF: 0xB3736
// Address: 0x18FD80
// Size: 0xDC
static void sploadSetGameEtc();

// DWARF: 0xB3834
// Address: 0x18FE60
// Size: 0x584
static void sploadSetCharacter();

// DWARF: 0xB399C
// Address: 0x1903F0
// Size: 0x624
static void sploadSetCreateCharacter(signed int player /* 0xA0(r29) */);

// 
// DWARF: 0xB3B8C
// Address: 0x190A20
// Size: 0x7E0
static void sploadSetCourse(signed int no /* 0x270(r29) */, signed int chr /* 0x280(r29) */);

// DWARF: 0xB3D3E
// Address: 0x191200
// Size: 0x318
static void sploadSetSound(signed int type /* 0x30(r29) */, signed int no /* 0x40(r29) */, signed int player /* 0x50(r29) */);

// DWARF: 0xB3EAC
// Address: 0x191520
// Size: 0x284
static void sploadInitCommon();
// DWARF: 0xB4007
// Address: 0x1917B0
// Size: 0x38
static void sploadInitMovie();

// DWARF: 0xB40CF
// Address: 0x1917F0
// Size: 0x18D0
static void sploadInitSelect();

// DWARF: 0xB4290
// Address: 0x1930C0
// Size: 0x38
static void sploadInitGameCommon();

// DWARF: 0xB4351
// Address: 0x193100
// Size: 0x26C
static void sploadInitGame2D();

// DWARF: 0xB4416
// Address: 0x193370
// Size: 0x148
static void sploadInitGameEtc();
// DWARF: 0xB4536
// Address: 0x1934C0
// Size: 0xC64
static void sploadInitCharacter();

// DWARF: 0xB4703
// Address: 0x194130
// Size: 0xDD8
static signed int sploadInitCreateCharacter(signed int player /* 0xA0(r29) */, signed int offset /* 0xB0(r29) */);

// DWARF: 0xB4A01
// Address: 0x194F10
// Size: 0x644
static void sploadInitCourse();

// DWARF: 0xB4B30
// Address: 0x195560
// Size: 0x30
void sploadFreeMovie();

// DWARF: 0xB4BF4
// Address: 0x195590
// Size: 0x90C
void sploadFreeSelect();

// DWARF: 0xB4D5B
// Address: 0x195EA0
// Size: 0x38
void sploadFreeGameCommon();

// DWARF: 0xB4E1C
// Address: 0x195EE0
// Size: 0xD8
static void sploadFreeGame2D();

// DWARF: 0xB4EE1
// Address: 0x195FC0
// Size: 0x50
static void sploadFreeGameEtc();

// DWARF: 0xB4FA7
// Address: 0x196010
// Size: 0x314
static void sploadFreeCharacter();

// DWARF: 0xB50DB
// Address: 0x196330
// Size: 0x100
static void sploadFreeCourse();

// DWARF: 0xB51A0
// Address: 0x196430
// Size: 0x380
void sploadLoadSCharacter(signed int chr_no /* 0x60(r29) */);

// DWARF: 0xB5358
// Address: 0x1967B0
// Size: 0x58
signed int sploadCheckSCharacter();

// DWARF: 0xB5455
// Address: 0x196810
// Size: 0x278
void sploadSetSCharacter(signed int chr_no /* 0x50(r29) */);

// DWARF: 0xB5607
// Address: 0x196A90
// Size: 0x3B8
void sploadFreeSCharacter(signed int chr_no /* 0x20(r29) */);

// DWARF: 0xB572A
// Address: 0x196E50
// Size: 0x560
void sploadSetCharacterTexture(signed int no /* 0x40(r29) */);

// Size: 0x10, DWARF: 0xAF272
VsploadReplayHead* sploadGetRapHead();
// Size: 0x1C, DWARF: 0xACE73
VsploadIcon* sploadGetIconData();
// Size: 0x60, DWARF: 0xADA05
VsploadVibration* sploadGetVibrationData();
// Size: 0x10, DWARF: 0xAFED2
VsploadMovie* sploadGetMovieData();
// Size: 0x16720, DWARF: 0xB0405
VsploadSelect* sploadGetSelectData();
Cd* sploadGetCharacter();
VsploadGame2D* sploadGetGame2D();
// Size: 0x9C, DWARF: 0xAB761
VsploadGameEtc* sploadGetGameEtc();
signed int sploadGetCommonOffset();

// IRX export magic
#define EXPORT_MAGIC	0x41c00000

// Includes ///////////////////////////////////////////////////////////////////////////

void ultexTransTexTag(VgmsysGifPkt* packet, unsigned int* addr, Tex* data, signed int no);
void nmfontGPrintF(VgmsysGifPkt* packet, char* str, float* pos);
void nmfontFPrintF(VgmsysGifPkt* packet, char* str, float* pos);
float uldvdCheckReadPer_DRIVE(void);
void* memcpy(void* dst, const void* src, unsigned int n);
Change* maModelChangeInit(__int128* mdl_data);
void maMdlMotionInitEnd(Seq* seq);
signed int ultexGetNTex(unsigned int* addr);
void gmsysSetScreenMode_on_play(void);
void gmsysSetScreenMode_normal(void);
void nmdispInit(void);
signed int ultexSetAlign(void);
signed int ultexGetOffset(void);
signed int nmsndCheckExit(void);
void tmetcEnd(void);
void tmcrsEnd(void);
void nmfontInitOption(void);
void ultexSetTexPath3(VgmsysGifPkt* packet, unsigned int* addr, signed int offset, signed int block);
signed int ulstdSprintf(char* buf, char* fmt, ...);
void ulmdlInitModel(__int128* model);
void ulgifDmaSend(VgmsysGifPkt* pkt);
void tmetcInit(unsigned char* acc, unsigned char* grp);
void spfxSetTexData(void* texdata);
signed int nmvcSetData(signed int group, signed int addr);
signed int nmsqSetWave(signed int num, signed int hd_addr, signed int bd_addr);
signed int nmsqSetSq(signed int num, signed int addr);
void nmfontSetType(signed int type);
void nmfontSetTexData(void* data, signed int type);
void nmfontSetSize(signed int width, signed int height);
void nmfontSetPack(signed int flag);
void nmfontSetLang(signed int type);
void nmfontSetCol(signed int* col);
signed int nmfontGetStrLen(char* str, signed int width);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);
void nmdispInitMatchScore(void* score);
void maModelChangeInitEnd(void* ctrl);
void maCreateModelFree(unsigned char* mdl_data);
signed int ulvumdlInitModel(unsigned char* model, Tex* texdata1, Tex* texdata2);
signed int ultexGetUseBlock(unsigned int* addr);
signed int ultexGetUseMemory(signed int block);
void ultexTransTex(unsigned int* addr, Tex* info);
unsigned int* ultexGetTex(unsigned int* addr, signed int offset, signed int block);
unsigned long ultexGetTEX0(Tex* data);
unsigned long* sceGifPkReserve(VgmsysGifPkt* packet, signed int qwc);
void sceVu0UnitMatrix(sceVu0FMATRIX mat);
void tmlinkMappingData(unsigned int addr, Data* data);
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void maMdlMotionMap(__int128* uad);
Seq* maMdlMotionInit(__int128* motion_data, signed int id);
void maVuMdlIKInit(__int128* mdl_data, ModelCtrl* ctrl);
void maModelChangeSet(Change* ctrl, signed int mode);
void maSecMotionInit(__int128 * mdl_data, SCtrl* ctrl);
unsigned char* maCreateModelLink(unsigned char** mdl_data, signed int* file_size, signed int* text_num, signed int* alpha_num, signed int num);
void ultexResetTex(signed int offset); // (From tmcrs.c)
void ulFree(void* p);
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);

signed int sploadInit(signed int modnum) {
    signed int ii; // r16

    *vgmsysFrameFunc = &sploadFrame;
    *vgmsysEndFunc = &sploadEnd;
    gmsysSetScreenMode_normal();
    vsploadSystem.counter = 0;
    vsploadSystem.counter2 = 0;
    vsploadSystem.start = 0;
    vsploadSystem.end = 0;
    vsploadSystem.disp = 1;
    vsploadSystem.sound_data = 0;
    vsploadGameCommon.character = &vsploadCharacter;
    vsploadGameCommon.course = &vsploadCourse;
    vsploadGameCommon.game = &vsploadGame2D;
    vsploadGameCommon.etc = &vsploadGameEtc;
    for (ii = 0; ii < 6; ii++) {
        vsploadSoundData.vc_trans[ii] = 0;
        vsploadSoundData.vc_addr[ii] = 0;
        vsploadSoundData.vc_size[ii] = 0;
    }
    vsploadSoundData.retry = 0;
    vsploadSoundData.sq_error = 0;
    vsploadSoundData.sq_trans = 0;
    vsploadSoundData.sq_no = 0;
    switch (modnum) {
    case 0:
        sploadCommon();
        vsploadSystem.next_module = 7;
        vsploadSystem.disp = 0;
        break;
    case 7:
        sploadMovie();
        vsploadSystem.next_module = 0x16;
        vsploadSystem.disp = 0;
        break;
    case 1:
        sploadSelect();
        vsploadSystem.next_module = 0x10;
        nmdispInitMatchScore(&vspDispVsScore);
        break;
    default:
        sploadGameCommon();
        switch (vspenvEnv.game.mode.game_mode) {
        case 0:
            if (modnum == 2) {
                vsploadSystem.next_module = 0x11;
            } else if (modnum == 5) {
                vsploadSystem.next_module = 0x14;
            } else if (modnum == 6) {
                vsploadSystem.next_module = 0x15;
            }
            break;
        case 1:
            if (modnum == 6) {
                vsploadSystem.next_module = 0x15;
            } else {
                vsploadSystem.next_module = 0x12;
            }
            break;
        case 2:
            if (modnum == 5) {
                vsploadSystem.next_module = 0x14;
            } else {
                vsploadSystem.next_module = 0x13;
            }
            break;
        }
        break;
    }
    return modnum;
}

static signed int sploadFrame(signed int modnum) {
    signed int tmp;
    signed int ret;

    ret = 0;
    sceGifPkReset(vgmsysGifPkt);
    if (vsploadSystem.start == 0) {
        if (nmsndCheckExit() == 0) {
            uldvdStartReadData_DRIVE();
            vsploadSystem.start = 1;
        }
    } else if (vsploadSystem.end == 0) {
        ret = uldvdCheckFinish_DRIVE();
        if (ret == 0) {
            vsploadSystem.end = 1;
        }
    } else if (sploadCheckSoundData() == 1) {
        if (vsploadSystem.counter2 > 2) {
            if (modnum == 6) {
                while (1) {
                    tmp = rand() % 8;
                    if (tmp == vsploadDemoNo) {
                        continue;
                    }
                    vsploadDemoNo = tmp;
                    break;
                }
            }
            modnum = vsploadSystem.next_module;
        } else {
            vsploadSystem.counter2 += 1;
        }
    }
    if ((vsploadSystem.disp == 1) && (vsploadSystem.end == 0)) {
        sploadDrawNowLoading(vgmsysGifPkt, 0, 0.0f);
        if ((modnum != 1) && (modnum != 6) && (modnum != 5)) {
            switch (vspenvEnv.game.mode.game_mode) {
            case 0:
                sploadDrawLevelGoal(vgmsysGifPkt, vspenvGame->character[0].no, vspenvGame->course.no);
                break;
            case 1:
                sploadDrawRule(vgmsysGifPkt, vspenvGame->mode.match_rule);
                break;
            case 2:
                if (vsploadCommon.profile == 1) {
                    sploadDrawProfile(vgmsysGifPkt, vsploadSystem.freeride_no, 0.0f, 0);
                }
                break;
            }
        }
    }
    vsploadSystem.counter += 1;
    ulgifTermPacket(vgmsysGifPkt);
    ulgifDmaSend(vgmsysGifPkt);
    return modnum;
}

void sploadEnd(signed int modnum, int arg2) {
    switch (modnum) {
    case 0:
        sploadInitCommon();
        break;
    case 7:
        sploadInitMovie();
        break;
    case 1:
        sploadInitSelect();
        break;
    default:
        gmsysSetScreenMode_on_play();
        sploadInitGameCommon();
        break;
    }
    vsploadCommon.profile = 0;
}

static void sploadDrawNowLoading(VgmsysGifPkt* packet, signed int type, float y_pos) {
    signed int len; // r19
    signed int tmp; // r17
    float pos[4]; // 0x50(r29)
    signed int disp_pos[4]; // 0x60(r29)
    signed int color[4]; // 0x70(r29)
    float per; // 0x18C(r29)
    unsigned long* addr; // r16
    char str_tmp[256]; // 0x80(r29)
    char* load_tbl[3] = { "   NOW LOADING...", "   LADEN ...", "CHARGEMENT EN COURS" }; // 0x180(r29)
    s32* ptr1 = (s32*)&load_tbl;

    (void)ptr1;
    (void)ptr1;
    pos[0] = 0.0f;
    pos[1] = y_pos;
    pos[2] = 0.0f;
    pos[3] = 1.0f;
    sceVu0FTOI4Vector(disp_pos, pos);
    nmfontInitOption();
    if ((vsploadSystem.counter % 120) < 60) {
        tmp = vsploadSystem.counter % 60;
    } else {
        tmp = 120 - vsploadSystem.counter;
    }
    color[0] = 0x80;
    color[1] = 0x80;
    color[2] = 0x80;
    color[3] = (tmp * 0x80) / 60;
    nmfontSetCol(color);
    if (type != 0) {
        per = 100.0f;
    } else {
        ultexResetTex(vsploadCommon.offset);
        ultexTransTex(vsploadCommon.load, vsploadCommon.load_tex);
        sceGsSyncPath(0, 0);
        per = uldvdCheckReadPer_DRIVE();
    }
    sceGifPkCnt(packet, 0, 0, 0);
    addr = sceGifPkReserve(packet, 0x1C);
    *addr++ = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 12);
    *addr++ = 0xF53535353610;
    *addr++ = SCE_GS_SET_PRIM(4, 0, 1, 0, 0, 0, 1, 0, 0);
    *addr++ = SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000);
    *addr++ = ultexGetTEX0(vsploadCommon.load_tex);
    *addr++ = SCE_GS_SET_UV(0, 0);
    *addr++ = SCE_GS_SET_XYZ((0x800 - (vsppScrWidth / 2)) << 4, ((0x800 - (vsppScrHeight / 2)) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(vsploadCommon.load_tex->width * 16, 0);
    *addr++ = SCE_GS_SET_XYZ(((vsppScrWidth / 2) + 0x800) << 4, ((0x800 - (vsppScrHeight / 2)) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(0, vsploadCommon.load_tex->height * 16);
    *addr++ = SCE_GS_SET_XYZ((0x800 - (vsppScrWidth / 2)) << 4, (((vsppScrHeight / 2) + 0x800) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(vsploadCommon.load_tex->width * 16, vsploadCommon.load_tex->height * 16);
    *addr++ = SCE_GS_SET_XYZ(((vsppScrWidth / 2) + 0x800) << 4, (((vsppScrHeight / 2) + 0x800) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = 0;
    sceGifPkTerminate(packet);
    if (type == 0) {
        sploadDrawMater(packet, per, y_pos);
        ulstdSprintf(str_tmp, "%s", load_tbl[vspenvGame->language]);
        len = strlen(str_tmp);
        pos[0] = (vsppScrWidth - (len * 24)) / 2;
        pos[1] = 400.0f;
        nmfontSetSize(0x18, 0x18);
        nmfontFPrintF(packet, str_tmp, pos);
    } else {
    }
}

static void sploadDrawLevelGoal(VgmsysGifPkt* packet, signed int chr_no, signed int crs_no) {
    signed int ii; // r17
    signed int len; // r16
    signed int million; // r19
    signed int col[4][4]; // 0x60(r29)
    float pos[4]; // 0xA0(r29)
    char str_tmp[256]; // 0xB0(r29)
    char** pstr; // r18
    char* lang_tbl[3][11] = {
        { "Level Goals", "BOARDER SCORE", "PRO SCORE", "SICK SCORE", "FINISH BEFORE ", " WITH ", "COLLECT THE ", " LOGOS", "FIND THE SECRET SPONSOR", " PTS", " PTS" },
        { "Level Ziele", "BOARDER-SCORE", "PROFI-SCORE", "HAMMER-SCORE", "BEENDE UNTER ", " MIT ", "FINDE DIE ", "-LOGOS!", "FINDE DEN VERSTECKTEN SPONSOR!", " PKTE", " PKTN!" },
        { "Obj. niveau", "SCORE DU SNOWBOARDER", "SCORE PRO", "SCORE DE FOU", "FINIS AVANT ", " AVEC ", "TROUVE LES LOGOS DE ", ".", "TROUVE LE SPONSOR SECRET.", " PTS", " PTS." }
    }; // 0x1B0(r29)
    s32* ptr1 = (s32*)&lang_tbl;

    pstr = lang_tbl[vspenvGame->language];
    nmfontInitOption();
    nmfontSetShadow(1);
    nmfontSetSize(0x20, 0x20);
    nmfontSetType(1);
    nmfontSetPack(1);
    ulstdSprintf(str_tmp, "%s", pstr[0]);
    len = nmfontGetPackStrLen(str_tmp, 0x20, 1);
    pos[0] = (vsppScrWidth - len) / 2;
    pos[1] = 16.0f;
    col[0][0] = 0x40;
    col[0][1] = 0x40;
    col[0][2] = 0x80;
    col[0][3] = 0x80;
    col[1][0] = 0x40;
    col[1][1] = 0x40;
    col[1][2] = 0x80;
    col[1][3] = 0x80;
    col[2][0] = 0x80;
    col[2][1] = 0x80;
    col[2][2] = 0x80;
    col[2][3] = 0x80;
    col[3][0] = 0x80;
    col[3][1] = 0x80;
    col[3][2] = 0x80;
    col[3][3] = 0x80;
    nmfontSetCol(&col[0][0]);
    nmfontGPrintF(packet, str_tmp, pos);
    pos[1] += 48.0f;
    col[0][0] = 0x40;
    col[0][1] = 0x40;
    col[0][2] = 0x40;
    col[0][3] = 0x80;
    for (ii = 0; ii < 9; ii++) {
        pos[0] = 60.0f;
        nmfontInitOption();
        nmfontSetShadow(1);
        nmfontSetPack(1);
        if (chr_no < 0xC) {
            if (vspenvSecret->character[chr_no].level_goal[crs_no] & (1 << ii)) {
                nmfontSetCol(&col[0][0]);
            }
        } else {
            if (vspenvSecret->create_character[chr_no - 0xC].character.level_goal[crs_no] & (1 << ii)) {
                nmfontSetCol(&col[0][0]);
            } else {
            }
        }
        switch (ii) {
        case 0:
        case 1:
        case 2:
            if ((vsptblLevelGoalValue[crs_no][ii] / 1000000) > 0) {
                million = 1;
            } else {
                million = 0;
            }
            len = 0x158;
            nmfontFPrintF(packet, pstr[ii + 1], pos);
            pos[0] += len;
            nmfontSetPack(0);
            ulstdSprintf(str_tmp, "%01d", vsptblLevelGoalValue[crs_no][ii] / 1000000);
            len = nmfontGetStrLen(str_tmp, 0x10);
            if (million == 1) {
                nmfontFPrintF(packet, str_tmp, pos);
            }
            pos[0] += len;
            nmfontSetPack(1);
            len = nmfontGetPackStrLen(",", 0x10, 0);
            if (million == 1) {
                nmfontFPrintF(packet, ",", pos);
            }
            pos[0] += len;
            nmfontSetPack(0);
            if (million == 1) {
                ulstdSprintf(str_tmp, "%03d", (vsptblLevelGoalValue[crs_no][ii] / 1000) % 1000);
            } else {
                ulstdSprintf(str_tmp, "%3d", (vsptblLevelGoalValue[crs_no][ii] / 1000) % 1000);
            }
            len = nmfontGetStrLen(str_tmp, 0x10);
            nmfontFPrintF(packet, str_tmp, pos);
            pos[0] += len;
            nmfontSetPack(1);
            len = nmfontGetPackStrLen(",", 0x10, 0);
            nmfontFPrintF(packet, ",", pos);
            pos[0] += len;
            nmfontSetPack(0);
            len = nmfontGetStrLen(str_tmp, 0x10);
            ulstdSprintf(str_tmp, "%03d", vsptblLevelGoalValue[crs_no][ii] % 1000);
            nmfontFPrintF(packet, str_tmp, pos);
            pos[0] += len;
            nmfontSetPack(1);
            nmfontFPrintF(packet, pstr[9], pos);
            break;
        case 3:
            len = nmfontGetPackStrLen(pstr[4], 0x10, 0);
            nmfontFPrintF(packet, pstr[4], pos);
            pos[0] += len;
            nmfontSetPack(0);
            ulstdSprintf(str_tmp, "%d", vsptblLevelGoalValue[crs_no][3] / 60);
            nmfontFPrintF(packet, str_tmp, pos);
            pos[0] += 16.0f;
            nmfontSetPack(1);
            len = nmfontGetPackStrLen(":", 0x10, 0);
            nmfontFPrintF(packet, ":", pos);
            pos[0] += len;
            nmfontSetPack(0);
            ulstdSprintf(str_tmp, "%02d", vsptblLevelGoalValue[crs_no][3] % 60);
            nmfontFPrintF(packet, str_tmp, pos);
            pos[0] += 32.0f;
            nmfontSetPack(1);
            len = nmfontGetPackStrLen(pstr[5], 0x10, 0);
            nmfontFPrintF(packet, pstr[5], pos);
            pos[0] += len;
            nmfontSetPack(0);
            ulstdSprintf(str_tmp, "%d", vsptblLevelGoalValue[crs_no][4] / 1000);
            len = nmfontGetStrLen(str_tmp, 0x10);
            nmfontFPrintF(packet, str_tmp, pos);
            pos[0] += len;
            nmfontSetPack(1);
            len = nmfontGetPackStrLen(",", 0x10, 0);
            nmfontFPrintF(packet, ",", pos);
            pos[0] += len;
            nmfontSetPack(0);
            ulstdSprintf(str_tmp, "%03d", vsptblLevelGoalValue[crs_no][4] % 1000);
            len = nmfontGetStrLen(str_tmp, 0x10);
            nmfontFPrintF(packet, str_tmp, pos);
            pos[0] += len;
            nmfontSetPack(1);
            nmfontFPrintF(packet, pstr[10], pos);
            break;
        case 4:
            ulstdSprintf(str_tmp, "%s%s%s", pstr[6], vsptblCourseName[crs_no + 16], pstr[7]);
            nmfontFPrintF(packet, str_tmp, pos);
            break;
        case 5:
            nmfontFPrintF(packet, pstr[8], pos);
            break;
        default:
            ulstdSprintf(str_tmp, "%s", vsptblLevelGoalStr[crs_no][ii - 6]);
            nmfontFPrintF(packet, str_tmp, pos);
            break;
        }
        pos[1] += 24.0f;
    }
}

void sploadDrawProfile(VgmsysGifPkt* packet, s32 chr_no, float y_pos, s32 select) {
    signed int ii; // r16
    char** pinfo; // r17
    signed int len; // r20
    // s32 tmp2;
    char str_tmp[256]; // 0x60(r29)
    char* info_tbl[3][6] = {
        { "BIRTH DATE", "HOME TOWN", "SPECIAL TRICKS", "              ", "", "STANCE" },
        { "GEBURTSDATUM", "WOHNORT", "SPEZIALTRICKS", "              ", "", "FUSSSTELLUNG" },
        { "DATE DE NAISSANCE", "VILLE NATALE", "TRICKS SPECIAUX", "              ", "", "POSITION" }
    }; // 0x160(r29)
    s32* ptr1 = &info_tbl;
    char* profile_tbl[3][12][2] = {
    {
        { "11/14/68", "SOUTH LAKE TAHOE, CA" },
        { " 6/15/79", "MAMMOTH LAKES, CA" },
        { " 1/25/71", "WEST COVINA, CA" },
        { " 9/3/86", "SAN DIEGO. CA" },
        { " 3/14/78", "BEND, OREGON" },
        { " 6/15/74", "VERNON, BC, CANADA" },
        { " 2/10/79", "BENNINGTON, VERMONT" },
        { " 8/20/75", "MAMMOTH LAKES, CA" },
        { " 4/1/76", "SKELLEFTEA, SWEDEN" },
        { " 2/1/78", "HELSINKI, FINLAND" },
        { " 8/8/77", "LONG BEACH, CA" },
        { " 5/11/78", "SANTA ANA, CA" }
    },
    {
        { "14/11/68", "SOUTH LAKE TAHOE, CA" },
        { "15/6/79", "MAMMOTH LAKES, CA" },
        { "25/1/71", "WEST COVINA, CA" },
        { " 3/9/86", "SAN DIEGO. CA" },
        { "14/3/78", "BEND, OREGON" },
        { "15/6/74", "VERNON, BC, KANADA" },
        { "10/2/79", "BENNINGTON, VERMONT" },
        { "20/8/75", "MAMMOTH LAKES, CA" },
        { " 1/4/76", "SKELLEFTEA, SCHWEDEN" },
        { " 1/2/78", "HELSINKI, FINNLAND" },
        { " 8/8/77", "LONG BEACH, CA" },
        { "11/5/78", "SANTA ANA, CA" }
    },
    {
        { "11/14/68", "SOUTH LAKE TAHOE, CA" },
        { " 6/15/79", "MAMMOTH LAKES, CA" },
        { " 1/25/71", "WEST COVINA, CA" },
        { " 9/3/86", "SAN DIEGO. CA" },
        { " 3/14/78", "BEND, OREGON" },
        { " 6/15/74", "VERNON, BC, CANADA" },
        { " 2/10/79", "BENNINGTON, VERMONT" },
        { " 8/20/75", "MAMMOTH LAKES, CA" },
        { " 4/1/76", "SKELLEFTEA, SWEDEN" },
        { " 2/1/78", "HELSINKI, FINLAND" },
        { " 8/8/77", "LONG BEACH, CA" },
        { " 5/11/78", "SANTA ANA, CA" }
    }
    }; // 0x1B0(r29)
    s32* ptr2 = &profile_tbl;
    signed int col[4][4]; // 0x2D0(r29)
    float pos[4]; // 0x310(r29)

    (void)ptr1;
    (void)ptr1;
    (void)ptr2;
    (void)ptr2;
    pinfo = info_tbl[vspenvGame->language];
    
    pos[0] = 0.0f;
    pos[1] = y_pos;
    pos[2] = 0.0f;
    pos[3] = 1.0f;
    if (select == 1) {
        ultexResetTex(vsploadCommon.offset);
        for (ii = 0; ii < ultexGetNTex(vsploadCommon.load); ii++) {
            vsploadCommon.load_tex[ii].tofs = -1;
            vsploadCommon.load_tex[ii].cofs = -1;
            ultexTransTexTag(packet, vsploadCommon.load, &vsploadCommon.load_tex[ii], ii);
        }
        vsploadCommon.face[chr_no / 2].tofs = -1;
        vsploadCommon.face[chr_no / 2].cofs = -1;
        ultexTransTexTag(vgmsysGifPkt, vsploadSelect.select_utd, &vsploadCommon.face[chr_no / 2], chr_no/2 + 0x2E);
        for (ii = 0; ii < 0x1D; ii++) {
            vsploadCommon.sponsor[ii].tofs = -1;
            vsploadCommon.sponsor[ii].cofs = -1;
            ultexTransTexTag(vgmsysGifPkt, vsploadSelect.sponsor_utd, &vsploadCommon.sponsor[ii], ii);
        }
        sploadDrawNowLoading(vgmsysGifPkt, 1, y_pos);
    } else {
    }
    nmfontInitOption();
    nmfontSetSize(0x20, 0x20);
    col[0][0] = 0x40;
    col[0][1] = 0x40;
    col[0][2] = 0x80;
    col[0][3] = 0x80;
    col[1][0] = 0x40;
    col[1][1] = 0x40;
    col[1][2] = 0x80;
    col[1][3] = 0x80;
    col[2][0] = 0x80;
    col[2][1] = 0x80;
    col[2][2] = 0x80;
    col[2][3] = 0x80;
    col[3][0] = 0x80;
    col[3][1] = 0x80;
    col[3][2] = 0x80;
    col[3][3] = 0x80;
    nmfontSetCol(&col[0][0]);
    nmfontSetType(1);
    nmfontSetPack(1);
    len = nmfontGetPackStrLen(vsptblCharacterName[chr_no], 0x20, 1);
    pos[0] = (vsppScrWidth - len) / 2;
    pos[1] = 16.0f + (2.0f * y_pos);
    nmfontGPrintF(packet, vsptblCharacterName[chr_no], &pos[0]);
    nmfontInitOption();
    pos[1] += 40.0f;
    for (ii = 0; ii < 4; ii++) {
        col[0][0] = 0x80;
        col[0][1] = 0x80;
        col[0][2] = 0x40;
        col[0][3] = 0x80;
        col[1][0] = 0x80;
        col[1][1] = 0x80;
        col[1][2] = 0x40;
        col[1][3] = 0x80;
        col[2][0] = 0x80;
        col[2][1] = 0x80;
        col[2][2] = 0x80;
        col[2][3] = 0x80;
        col[3][0] = 0x80;
        col[3][1] = 0x80;
        col[3][2] = 0x80;
        col[3][3] = 0x80;
        nmfontSetSize(0x14, 0x14);
        nmfontSetCol(&col[0][0]);
        nmfontSetPack(1);
        pos[0] = 168.0f;
        nmfontGPrintF(packet, pinfo[ii], &pos[0]);
        // nmfontGPrintF(packet, *(temp_s1 + (ii * 4)), &pos[0]);
        col[0][0] = 0x80;
        col[0][1] = 0x80;
        col[0][2] = 0x80;
        col[0][3] = 0x80;
        col[1][0] = 0x80;
        col[1][1] = 0x80;
        col[1][2] = 0x80;
        col[1][3] = 0x80;
        col[2][0] = 0x80;
        col[2][1] = 0x80;
        col[2][2] = 0x80;
        col[2][3] = 0x80;
        col[3][0] = 0x80;
        col[3][1] = 0x80;
        col[3][2] = 0x80;
        col[3][3] = 0x80;
        nmfontSetSize(0x10, 0x10);
        nmfontSetCol(&col[0][0]);
        nmfontSetPack(1);
        if (ii < 2) {
            ulstdSprintf(&str_tmp, "%s", profile_tbl[vspenvGame->language][chr_no][ii]);
        } else {
            ulstdSprintf(&str_tmp, "%s", vsptblTrickName[ii + ((chr_no * 2) + 0x52)]);
        }
        pos[0] += 64.0f;
        pos[1] += 22.0f;
        nmfontGPrintF(packet, &str_tmp, &pos[0]);
        pos[0] -= 64.0f;
        pos[1] -= 22.0f;
        if (ii == 2) {
            pos[1] += 24.0f;
        } else {
            pos[1] += 40.0f;
        }
    }
    col[0][0] = 0x80;
    col[0][1] = 0x80;
    col[0][2] = 0x40;
    col[0][3] = 0x80;
    col[1][0] = 0x80;
    col[1][1] = 0x80;
    col[1][2] = 0x40;
    col[1][3] = 0x80;
    col[2][0] = 0x80;
    col[2][1] = 0x80;
    col[2][2] = 0x80;
    col[2][3] = 0x80;
    col[3][0] = 0x80;
    col[3][1] = 0x80;
    col[3][2] = 0x80;
    col[3][3] = 0x80;
    nmfontInitOption();
    nmfontSetSize(0x14, 0x14);
    nmfontSetCol(&col);
    nmfontSetPack(1);
    pos[1] = 176.0f + (2.0f * y_pos);
    pos[0] = 16.0f;
    nmfontGPrintF(packet, pinfo[5], &pos[0]);
    // nmfontGPrintF(packet, temp_s1->unk14, &pos[0]);
    if (vsptblCharacterParam[chr_no].stance == 0) {
        ulstdSprintf(str_tmp, "REGULAR");
    } else {
        ulstdSprintf(str_tmp, "GOOFY");
    }
    col[0][0] = 0x80;
    col[0][1] = 0x80;
    col[0][2] = 0x80;
    col[0][3] = 0x80;
    col[1][0] = 0x80;
    col[1][1] = 0x80;
    col[1][2] = 0x80;
    col[1][3] = 0x80;
    col[2][0] = 0x80;
    col[2][1] = 0x80;
    col[2][2] = 0x80;
    col[2][3] = 0x80;
    col[3][0] = 0x80;
    col[3][1] = 0x80;
    col[3][2] = 0x80;
    col[3][3] = 0x80;
    nmfontSetSize(0x10, 0x10);
    nmfontSetCol(&col[0][0]);
    pos[0] += 32.0f;
    pos[1] += 22.0f;
    nmfontGPrintF(packet, &str_tmp, &pos[0]);
    sploadDrawFace(packet, chr_no, 24.0f, y_pos);
    sploadDrawSponsor(packet, chr_no, y_pos, select);
}

static void sploadDrawRule(VgmsysGifPkt* packet, signed int rule) {
    signed int col[4][4]; // 0xA0(r29)
    float pos[4]; // 0xE0(r29)
    signed int ii; // r17
    signed int jj; // r16
    signed int len; // r18
    signed int chr_no; // r20
    float pos_tbl[2] = { 80.0f, (vsppScrWidth - 0x80) - 80.0f }; // 0x210(r29)
    s32* ptr1 = (s32*)&pos_tbl;
    char str_tmp[2]; // 0x21C(r29)
    char* rule_tbl_lang[3][4] = {
        { "FREESTYLE", "PALMER X", "PUSH", "HORSE" },
        { "FREESTYLE", "PALMER X", "PUSH", "LOSER" },
        { "FREESTYLE", "PALMER X", "DUEL", "PENDU" }
    }; // 0xF0(r29)
    s32* ptr2 = (s32*)&rule_tbl_lang;
    char* rule_tbl2_lang[3][20] = {
        { "PLAYER WITH THE HIGHEST SCORE WINS", "LINK TRICKS TO SCORE BIG POINTS", "", "", "", "FIRST ONE TO FINISH WINS", "LAND TRICKS TO GET BOOST", "PRESS THE \200 BUTTON TO BOOST", "", "", "LAND TRICKS TO PUSH YOUR OPPONENT", "OFF THE SCREEN", "", "", "", "FAIL TO MATCH OR BEAT YOUR OPPONENT'S", "SCORE AND GET A LETTER", "GET ALL LETTERS FIRST AND YOU LOSE", "", "" },
        { "WER AM MEISTEN PUNKTE HAT, GEWINNT.", "LANDE SO VIELE TRICKS WIE M\222GLICH.", "", "", "", "DER ERSTE IM ZIEL GEWINNT.", "F\224R MEHR TEMPO LANDE TRICKS", "ODER DR\224CKE DIE \200-TASTE.", "", "", "LANDE TRICKS, UM DEINEN GEGNER", "ABZUDR\220NGEN.", "", "", "", "KANNST DU DIE PUNKTE DEINES GEGNERS", "NICHT AUSGLEICHEN ODER \224BERBIETEN,", "ERH\220LTST DU EINEN BUCHSTABEN.", "WER ZUERST ALLE BUCHSTABEN HAT,", "IST DER LOSER." },
        { "CELUI QUI A LE MEILLEUR SCORE", "GAGNE. COMBINE LES TRICKS POUR", "AMELIORER TON SCORE.", "", "", "LE PREMIER ARRIVE GAGNE.", "PLACE DES TRICKS POUR", "ACCELERER. APPUIE SUR LA", "TOUCHE \200 A TERRE POUR", "ACCELERER.", "PLACE DES TRICKS POUR", "POUSSER TON ADVERSAIRE", "HORS DE L'ECRAN.", "", "", "SI TU NE FAIS PAS MIEUX QUE TON", "ADVERSAIRE TU AS UNE LETTRE", "SI TU AS TOUTES LES LETTRES EN", "PREMIER, TU PERDS", "" }
    }; // 0x120(r29)
    s32* ptr3 = (s32*)&rule_tbl2_lang;
    char** rule_tbl = &rule_tbl_lang[vspenvGame->language][0]; // r21
    char** rule_tbl2 = rule_tbl2_lang[vspenvGame->language]; // r19

    nmfontInitOption();
    nmfontSetShadow(1);
    nmfontSetSize(0x20, 0x20);
    nmfontSetType(1);
    nmfontSetPack(1);
    len = nmfontGetPackStrLen(rule_tbl[rule], 0x20, 1);
    pos[0] = (vsppScrWidth - len) / 2;
    pos[1] = 16.0f;
    col[0][0] = 0x40;
    col[0][1] = 0x40;
    col[0][2] = 0x80;
    col[0][3] = 0x80;
    col[1][0] = 0x40;
    col[1][1] = 0x40;
    col[1][2] = 0x80;
    col[1][3] = 0x80;
    col[2][0] = 0x80;
    col[2][1] = 0x80;
    col[2][2] = 0x80;
    col[2][3] = 0x80;
    col[3][0] = 0x80;
    col[3][1] = 0x80;
    col[3][2] = 0x80;
    col[3][3] = 0x80;
    nmfontSetCol(&col[0][0]);
    nmfontGPrintF(packet, (char*)rule_tbl[rule], pos);
    pos[1] += 64.0f;
    nmfontInitOption();
    nmfontSetSize(0x14, 0x14);
    nmfontSetPack(1);
    for (ii = 0; ii < 5; ii++) {
        len = nmfontGetPackStrLen(rule_tbl2[ii + (rule * 5)], 0x14, 0);
        pos[0] = (vsppScrWidth - len) / 2;
        len = strlen(rule_tbl2[ii + (rule * 5)]);
        for (jj = 0; jj < len; jj++) {
            str_tmp[0] = rule_tbl2[ii + (rule * 5)][jj];
            str_tmp[1] = 0;
            if (str_tmp[0] == 0x80) {
                col[0][0] = 0x80;
                col[0][1] = 0x40;
                col[0][2] = 0x40;
                col[0][3] = 0x80;
                col[1][0] = 0x80;
                col[1][1] = 0x40;
                col[1][2] = 0x40;
                col[1][3] = 0x80;
                col[2][0] = 0x80;
                col[2][1] = 0x40;
                col[2][2] = 0x40;
                col[2][3] = 0x80;
                col[3][0] = 0x80;
                col[3][1] = 0x40;
                col[3][2] = 0x40;
                col[3][3] = 0x80;
            } else {
                col[0][0] = 0x80;
                col[0][1] = 0x80;
                col[0][2] = 0x80;
                col[0][3] = 0x80;
                col[1][0] = 0x80;
                col[1][1] = 0x80;
                col[1][2] = 0x80;
                col[1][3] = 0x80;
                col[2][0] = 0x80;
                col[2][1] = 0x80;
                col[2][2] = 0x80;
                col[2][3] = 0x80;
                col[3][0] = 0x80;
                col[3][1] = 0x80;
                col[3][2] = 0x80;
                col[3][3] = 0x80;
            }
            nmfontSetCol(&col[0][0]);
            nmfontGPrintF(packet, str_tmp, pos);
            pos[0] += nmfontGetPackStrLen(str_tmp, 0x14, 0);
        }
        pos[1] += 24.0f;
    }
    if (vsploadCommon.profile == 1) {
        nmfontInitOption();
        nmfontSetShadow(1);
        nmfontSetSize(0x20, 0x20);
        nmfontSetType(1);
        nmfontSetPack(1);
        len = nmfontGetPackStrLen("VS", 0x20, 1);
        pos[0] = (vsppScrWidth - len) / 2;
        pos[1] = 240.0f;
        col[0][0] = 0x80;
        col[0][1] = 0x40;
        col[0][2] = 0x40;
        col[0][3] = 0x80;
        col[1][0] = 0x80;
        col[1][1] = 0x40;
        col[1][2] = 0x40;
        col[1][3] = 0x80;
        col[2][0] = 0x80;
        col[2][1] = 0x80;
        col[2][2] = 0x40;
        col[2][3] = 0x80;
        col[3][0] = 0x80;
        col[3][1] = 0x80;
        col[3][2] = 0x40;
        col[3][3] = 0x80;
        nmfontSetCol(&col[0][0]);
        nmfontGPrintF(packet, "VS", pos);
        for (ii = 0; ii < 2; ii++) {
            if (vspenvGame->character[ii].no < 0xC) {
                chr_no = vspenvGame->character[ii].no;
            } else {
                chr_no = vspenvGame->character[ii].no - 0xC;
                if (vspenvSecret->create_character[chr_no].sex == 0) {
                    chr_no = 0xD;
                } else {
                    chr_no = 0xC;
                }
            }
            sploadDrawFace(packet, chr_no, pos_tbl[ii], 88.0f);
        }
    } else {
    }
}

static void sploadDrawMater(VgmsysGifPkt* packet, float per, float y) {
    unsigned long* addr; // r16
    float pos[4]; // 0x40(r29)
    signed int disp_pos[4]; // 0x50(r29)
    float width; // 0x6C(r29)

    pos[0] = (0x800 - (vsppScrWidth / 2)) + ((vsppScrWidth - vsploadCommon.load_tex[1].width) / 2);
    pos[1] = y + ((0x7B0 - (vsppScrHeight / 2)) + vsppScrHeight);
    sceVu0FTOI4Vector(disp_pos, pos);
    sceGifPkCnt(packet, 0, 0, 0);
    addr = sceGifPkReserve(packet, 0x1C);
    *addr++ = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 12);
    *addr++ = 0xF53535353610;
    *addr++ = SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 1, 0, 0);
    *addr++ = SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000);
    *addr++ = ultexGetTEX0(&vsploadCommon.load_tex[1]);
    *addr++ = SCE_GS_SET_UV(0, 0);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0], disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(vsploadCommon.load_tex[1].width * 16, 0);
    *addr++ = SCE_GS_SET_XYZ((vsploadCommon.load_tex[1].width << 4) + disp_pos[0], disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(0, vsploadCommon.load_tex[1].height * 16);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0], ((vsploadCommon.load_tex[1].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(vsploadCommon.load_tex[1].width * 16, vsploadCommon.load_tex[1].height * 16);
    *addr++ = SCE_GS_SET_XYZ((vsploadCommon.load_tex[1].width << 4) + disp_pos[0], ((vsploadCommon.load_tex[1].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = 0;
    sceGifPkTerminate(packet);
    width = 16.0f * ((vsploadCommon.load_tex[2].width * per) / 100.0f);
    sceGifPkCnt(packet, 0, 0, 0);
    addr = sceGifPkReserve(packet, 0x1C);
    *addr++ = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 12);
    *addr++ = 0xF53535353610;
    *addr++ = SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 1, 0, 0);
    *addr++ = SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000);
    *addr++ = ultexGetTEX0(&vsploadCommon.load_tex[2]);
    *addr++ = SCE_GS_SET_UV(0, 0);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0], disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV((unsigned int)width, 0);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0] + (unsigned int)width, disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(0, vsploadCommon.load_tex[2].height * 16);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0], ((vsploadCommon.load_tex[2].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV((unsigned int)width, vsploadCommon.load_tex[2].height * 16);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0] + (unsigned int)width, ((vsploadCommon.load_tex[2].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = 0;
    sceGifPkTerminate(packet);
}

static void sploadDrawFace(VgmsysGifPkt* packet, signed int chr_no, float x, float y) {
    float pos[4];
    signed int disp_pos[4];
    signed int uv[2];
    unsigned long* addr;

    pos[0] = (float)(0x800 - (vsppScrWidth / 2)) + x;
    pos[1] = (float)(0x800 - (vsppScrHeight / 2)) + y;
    sceVu0FTOI4Vector(disp_pos, pos);
    uv[0] = (chr_no % 2) * (vsploadCommon.face[chr_no / 2].width / 2);
    uv[1] = 0;
    chr_no = chr_no / 2;
    sceGifPkCnt(packet, 0, 0, 0);
    addr = sceGifPkReserve(packet, 0x1C);
    *addr++ = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 12);
    *addr++ = 0xF53535353610;
    *addr++ = SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 1, 0, 0);
    *addr++ = SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000);
    *addr++ = ultexGetTEX0(&vsploadCommon.face[chr_no]);
    *addr++ = SCE_GS_SET_UV(uv[0] * 16, uv[1] * 16);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0], disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV((uv[0] + (vsploadCommon.face[chr_no].width / 2)) * 16, uv[1] * 16);
    *addr++ = SCE_GS_SET_XYZ(((vsploadCommon.face[chr_no].width / 2) << 4) + disp_pos[0], disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV(uv[0] * 16, (uv[1] + vsploadCommon.face[chr_no].height) * 16);
    *addr++ = SCE_GS_SET_XYZ(disp_pos[0], ((vsploadCommon.face[chr_no].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = SCE_GS_SET_UV((uv[0] + (vsploadCommon.face[chr_no].width / 2)) * 16, (uv[1] + vsploadCommon.face[chr_no].height) * 16);
    *addr++ = SCE_GS_SET_XYZ(((vsploadCommon.face[chr_no].width / 2) << 4) + disp_pos[0], ((vsploadCommon.face[chr_no].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
    *addr++ = 0;
    sceGifPkTerminate(packet);
}

static void sploadDrawSponsor(VgmsysGifPkt* packet, signed int chr_no, float y, signed int select) {
    signed int ii; // r17
    signed int tmp; // r18
    signed int sp_id[3]; // 0xA0(r29)
    signed int sp_num[12] = { 2, 2, 2, 3, 2, 2, 2, 3, 2, 2, 3, 2 }; // 0x50(r29)
    s32* ptr1 = (s32*)&sp_num;
    unsigned long* addr; // r16
    float pos[4]; // 0x80(r29)
    signed int disp_pos[4]; // 0x90(r29)

    if (chr_no == 12) {
        chr_no = 11;
    }
    sp_id[0] = chr_no;
    switch (chr_no) {
    case 0:
        sp_id[1] = 13;
        break;
    case 1:
        sp_id[1] = 14;
        break;
    case 2:
        sp_id[1] = 15;
        break;
    case 3:
        if (select == 1) {
            sp_id[1] = 17;
            sp_id[2] = 16;
        } else {
            sp_id[1] = 16;
            sp_id[2] = 17;
        }
        break;
    case 4:
        sp_id[1] = 18;
        break;
    case 5:
        sp_id[1] = 19;
        break;
    case 6:
        sp_id[1] = 20;
        break;
    case 7:
        sp_id[1] = 22;
        sp_id[2] = 21;
        break;
    case 8:
        sp_id[1] = 23;
        break;
    case 9:
        sp_id[1] = 24;
        break;
    case 10:
        sp_id[1] = 25;
        sp_id[2] = 26;
        break;
    case 11:
        sp_id[1] = 27;
        break;
    }
    for (ii = 0; ii < sp_num[chr_no]; ii++) {
        tmp = vsploadCommon.sponsor[0].width * sp_num[chr_no];
        pos[0] = ((0x800 - (vsppScrWidth / 2)) + ((vsppScrWidth - tmp) / 2)) + (vsploadCommon.sponsor[sp_id[ii]].width * ii);
        pos[1] = y + ((0x788 - (vsppScrHeight / 2)) + vsppScrHeight);
        if (sp_num[chr_no] == 3) {
            switch (ii) {
            case 0:
                pos[0] += 50.0f;
                break;
            case 1:
                if (select == 1) {
                    (void)select;
                    break;
                }
                pos[1] -= 12.0f;
                break;
            case 2:
                pos[0] -= 50.0f;
                break;
            }
        } else {
            switch (ii) {
            case 0:
                pos[0] -= 40.0f;
                pos[1] += 4.0f;
                break;
            case 1:
                pos[0] += 40.0f;
                pos[1] += 4.0f;
                break;
            }
        }
        sceVu0FTOI4Vector(disp_pos, pos);
        sceGifPkCnt(packet, 0, 0, 0);
        addr = sceGifPkReserve(packet, 0x1C);
        *addr++ = SCE_GIF_SET_TAG(1, 1, 0, 0, 1, 12);
        *addr++ = 0xF53535353610;
        *addr++ = SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 1, 0, 0);
        *addr++ = SCE_GS_SET_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000);
        *addr++ = ultexGetTEX0(&vsploadCommon.sponsor[sp_id[ii]]);
        *addr++ = SCE_GS_SET_UV(0, 0);
        *addr++ = SCE_GS_SET_XYZ(disp_pos[0], disp_pos[1], 0xFFFFFF);
        *addr++ = SCE_GS_SET_UV(vsploadCommon.sponsor[sp_id[ii]].width * 16, 0);
        *addr++ = SCE_GS_SET_XYZ((vsploadCommon.sponsor[sp_id[ii]].width << 4) + disp_pos[0], disp_pos[1], 0xFFFFFF);
        *addr++ = SCE_GS_SET_UV(0, vsploadCommon.sponsor[sp_id[ii]].height * 16);
        *addr++ = SCE_GS_SET_XYZ(disp_pos[0], ((vsploadCommon.sponsor[sp_id[ii]].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
        *addr++ = SCE_GS_SET_UV(vsploadCommon.sponsor[sp_id[ii]].width * 16, vsploadCommon.sponsor[sp_id[ii]].height * 16);
        *addr++ = SCE_GS_SET_XYZ((vsploadCommon.sponsor[sp_id[ii]].width << 4) + disp_pos[0], ((vsploadCommon.sponsor[sp_id[ii]].height / 2) << 4) + disp_pos[1], 0xFFFFFF);
        *addr++ = 0;
        sceGifPkTerminate(packet);
    }
}

void sploadGetAddr(void* addr, int arg1, int src0, int arg3, int arg4) {
    *(int*)src0 = (int)addr;
}

void sploadSetSoundAddr(void* addr, signed int size, signed int type, signed int group, signed int no) {
    switch (type) {
        case 0:
            nmvcSetData(group, (s32)addr);
            vsploadSoundData.vc_trans[group] = 1;
            vsploadSoundData.vc_addr[group] = (s32)addr;
            vsploadSoundData.vc_size[group] = size;
            break;
        case 1:
            break;
        
        case 2:
            vsploadSoundData.sq_addr = (s32)addr;
            nmsqSetSq(no, (s32)vsploadSoundData.sq_addr);
            break;
        case 3:
            vsploadSoundData.hd_addr = (s32)addr;
            break;
        case 4:
            vsploadSoundData.bd_addr = (s32)addr;
            vsploadSoundData.sq_error = nmsqSetWave(no, (s32)vsploadSoundData.hd_addr, (s32)vsploadSoundData.bd_addr);
            vsploadSoundData.sq_trans = 1;
            vsploadSoundData.sq_no = no;
            break;
    }
}

void sploadGetCreateAddr(void* addr /* r29 */, signed int size /* 0x10(r29) */, signed int player /* 0x20(r29) */, signed int type /* 0x30(r29) */, signed int data /* 0x40(r29) */) {
    if (data == 0) {
        vsploadCreate[player].vmd[type] = addr;
        vsploadCreate[player].size[type] = size;
        return;
    }
    if (data == 1) {
        vsploadCreate[player].utd[type] = addr;
        return;
    }
    if (data == 2) {
        vsploadCreate[player].alpha_utd[type] = addr;
        return;
    }
    if (data == 3) {
        vsploadCreate[player].arm_utd = addr;
        return;
    }
    if (data == 4) {
        vsploadCreate[player].leg_utd = addr;
        return;
    }
}

static signed int sploadCheckSoundData() {
    signed int ret;
    signed int ii;

    ret = 1;
    for (ii = 0; ii < 6; ii++) {
        if (vsploadSoundData.vc_trans[ii] == 1) {
            if (nmvcGetDataState(ii) == 0) {
                ret = 0;
            } else {
                vsploadSoundData.vc_addr[ii] = 0;
            }
        }
    }
    if (vsploadSoundData.sq_trans == 1) {
        if (nmsqGetWaveState(vsploadSoundData.sq_no) == 0) {
            ret = 0;
            if ((vsploadSoundData.retry % 0x78) == 0) {
                vsploadSoundData.sq_error = nmsqSetWave(vsploadSoundData.sq_no, (s32)vsploadSoundData.hd_addr, (s32)vsploadSoundData.bd_addr);
            }
        } else {
            vsploadSoundData.hd_addr = 0;
            vsploadSoundData.bd_addr = 0;
        }
    }
    if (ret == 0) {
        vsploadSoundData.retry += 1;
    }
    return ret;
}

void sploadCommon() {
    // Size: 0x20, DWARF: 0xAE619
    ReadData read_data; // 0x10(r29)

    vsploadDemoNo = 0;
    vsploadIcon.link = (int*)0;
    vsploadVibration.link = (int*)0;
    vsploadCommon.load = (int*)0;
    vsploadCommon.font = (int*)0;
    vsploadCommon.effect =(int*)0;
    read_data.addr = 0;
    read_data.tail = 0;
    read_data.align = 0;
    read_data.ee_iop = 0;
    read_data.func = &sploadGetAddr;
    read_data.id = 1;
    read_data.no = 5;
    read_data.src[0] = (int)&vsploadIcon.link;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.id = 1;
    read_data.no = 6;
    read_data.src[0] = (int)&vsploadVibration.link;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.no = 4;
    read_data.src[0] = (int)&vsploadCommon.load;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.id = 0;
    read_data.no = vspenvGame->language;
    read_data.src[0] = (int)&vsploadCommon.font;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.id = 0;
    read_data.no = 3;
    read_data.src[0] = (int)&vsploadCommon.effect;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
}

void sploadSelect() {
    signed int kk; // r16
    signed int jj; // r17
    signed int ii; // r18
    // Size: 0x20, DWARF: 0xAE619
    ReadData read_data; // 0x40(r29)

    vsploadSelect.select_uad = 0;
    vsploadSelect.link[0] = 0;
    vsploadSelect.link[1] = 0;
    vsploadSelect.sponsor_tex = 0;
    vsploadSelect.board_tex = 0;
    vsploadSelect.medal_tex = 0;
    vsploadSelect.game.tex = 0;
    vsploadSelect.emblem_tex = 0;
    vsploadSelect.wheel.tex = 0;
    vsploadSelect.param.tex = 0;
    vsploadSelect.pad_tex = 0;
    for (ii = 0; ii < 0xC; ii++) {
        for (jj = 0; jj < 3; jj++) {
            vsploadSelect.character[ii][jj].link = 0;
            vsploadSelect.character[ii][jj].vmd[0] = 0;
            vsploadSelect.character[ii][jj].vmd[1] = 0;
            vsploadSelect.character[ii][jj].seq = 0;
            vsploadSelect.character[ii][jj].seq = 0;
            for (kk = 0; kk < 2; kk++) {
                vsploadSelect.character[ii][jj].utd[kk].utd = 0;
                vsploadSelect.character[ii][jj].utd[kk].tex = 0;
                vsploadSelect.character[ii][jj].utd[kk].frame = 0;
            }
        }
    }
    vsploadDemoData = 0;
    vsploadSelect.cr_arm_utd = 0;
    vsploadSelect.cr_leg_utd = 0;
    vsploadSelect.cr_arm_f_utd = 0;
    for (ii = 0; ii < 2; ii++) {
        vsploadSelect.create_chr[ii].link = 0;
        for (jj = 0; jj < 9; jj++) {
            vsploadSelect.create_chr[ii].face_umd[jj] = 0;
            vsploadSelect.create_chr[ii].face_utd[jj] = 0;
            vsploadSelect.create_chr[ii].face_tex[jj] = 0;
            vsploadSelect.create_chr[ii].face_seq[jj] = 0;
        }
        for (jj = 0; jj < 4; jj++) {
            vsploadSelect.create_chr[ii].hair_umd[jj][0] = 0;
            vsploadSelect.create_chr[ii].hair_umd[jj][1] = 0;
            for (kk = 0; kk < 4; kk++) {
                vsploadSelect.create_chr[ii].hair_utd[jj][kk][0] = 0;
                vsploadSelect.create_chr[ii].hair_utd[jj][kk][1] = 0;
            }
            vsploadSelect.create_chr[ii].hair_tex[jj][0] = 0;
            vsploadSelect.create_chr[ii].hair_tex[jj][1] = 0;
            vsploadSelect.create_chr[ii].hair_seq[jj] = 0;
        }
        for (jj = 0; jj < 5; jj++) {
            vsploadSelect.create_chr[ii].body_umd[jj] = 0;
            for (kk = 0; kk < 9; kk++) {
                vsploadSelect.create_chr[ii].body_utd[jj][kk] = 0;
            }
            vsploadSelect.create_chr[ii].body_tex[jj] = 0;
            // var_a1 = &vsploadSelect;
            vsploadSelect.create_chr[ii].body_seq[jj] = 0;
        }
        for (jj = 0; jj < 5; jj++) {
            vsploadSelect.create_chr[ii].pants_umd[jj] = 0;
            for (kk = 0; kk < 8; kk++) {
                vsploadSelect.create_chr[ii].pants_utd[jj][kk] = 0;
            }
            vsploadSelect.create_chr[ii].pants_tex[jj] = 0;
            vsploadSelect.create_chr[ii].pants_seq[jj] = 0;
        }
        vsploadSelect.create_chr[ii].glove_umd = 0;
        for (jj = 0; jj < 4; jj++) {
            vsploadSelect.create_chr[ii].glove_utd[jj] = 0;
        }
        vsploadSelect.create_chr[ii].glove_tex = 0;
        vsploadSelect.create_chr[ii].glove_seq = 0;
        vsploadSelect.create_chr[ii].boots_umd = 0;
        for (jj = 0; jj < 4; jj++) {
            vsploadSelect.create_chr[ii].boots_utd[jj] = 0;
        }
        vsploadSelect.create_chr[ii].boots_tex = 0;
        vsploadSelect.create_chr[ii].boots_seq = 0;
        vsploadSelect.create_chr[ii].board_umd = 0;
        vsploadSelect.create_chr[ii].board_utd = 0;
        vsploadSelect.create_chr[ii].board_tex = 0;
        vsploadSelect.create_chr[ii].board_seq = 0;
    }
    read_data.addr = 0;
    read_data.tail = 0;
    read_data.id = 1;
    read_data.align = 0;
    read_data.ee_iop = 0;
    read_data.func = &sploadGetAddr;
    read_data.tail = 1;
    read_data.id = 0;
    read_data.no = 0x12A;
    read_data.src[0] = (int)&vsploadSelect.select_uad;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    sploadSetSound(2, 0, 0);
    read_data.tail = 0;
    read_data.id = 1;
    if (vspenvGame->language == 0) {
        read_data.no = 0x1A;
    } else if (vspenvGame->language == 1) {
        read_data.no = 0x1B;
    } else if (vspenvGame->language == 2) {
        read_data.no = 0x1C;
    }
    read_data.src[0] = (int)&vsploadSelect.link;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    sploadSetSound(0, 0, 0);
    sploadSetSound(1, 0, 0);
    read_data.no = 0x12B;
    read_data.src[0] = (int)&vsploadSelect.create_chr[0];
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.no = 0x12C;
    read_data.src[0] = (int)&vsploadSelect.create_chr[1];
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.no = 0x12D;
    read_data.src[0] = (int)&vsploadSelect.cr_arm_utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.no = 0x12E;
    read_data.src[0] = (int)&vsploadSelect.cr_leg_utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.no = 0x12F;
    read_data.src[0] = (int)&vsploadSelect.cr_arm_f_utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.tail = 1;
    read_data.id = 0;
    read_data.no = 0x1D;
    read_data.src[0] = (int)&vsploadSelect.link[1];
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.no = 0x2E1;
    read_data.src[0] = (int)&vsploadSelect.env_utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
    read_data.no = vsploadDemoNo + 0x12;
    read_data.src[0] = (int)&vsploadDemoData;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
}

static void sploadMovie() {
    ReadData read_data;

    vsploadMovie.utd = 0;
    read_data.addr = 0;
    read_data.tail = 0;
    read_data.id = 1;
    read_data.align = 0;
    read_data.ee_iop = 0;
    read_data.func = &sploadGetAddr;
    sploadSetSound(0, 0, 0);
    read_data.no = 0x11;
    read_data.src[0] = (int)&vsploadMovie.utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data.addr);
}

void sploadGameCommon() {
    signed int ii; // r16
    signed int chr_no; // r17
    char* tmp;
    signed int type_tbl[12] = {
        0, 0, 0, 2,
        1, 0, 0, 1,
        0, 0, 0, 0
    }; // 0x40(r29)

    (void)chr_no;

    tmp = &type_tbl;
    sploadSetSound(0, 0, 0);
    sploadSetGameEtc();
    sploadSetSound(5, vspenvGame->course.no, 0);
    sploadSetGame2D();
    for (ii = 0; ii < vspenvEnv.game.mode.num_player; ii++) {
        if (vspenvEnv.game.character[ii].no < 0xC) {
            sploadSetSound(4, type_tbl[vspenvGame->character[ii].no], ii);
        } else if (vspenvSecret->create_character[chr_no = vspenvEnv.game.character[ii].no - 0xC].sex == 0) {
            sploadSetSound(4, 0, ii);
        } else {
            sploadSetSound(4, 1, ii);
        }
    }
    sploadSetCharacter();
    sploadSetSound(3, 0, 0);
    sploadSetCourse(vspenvGame->course.no, vspenvEnv.game.character[0].no);
}

void sploadSetGame2D() {
    // Size: 0x20, DWARF: 0xADD43
    ReadData read_data; // 0x10(r29)

    vsploadGame2D.game.utd = 0;
    vsploadGame2D.game.tex = 0;
    vsploadGame2D.game.frame = 0;
    vsploadGame2D.result.utd = 0;
    vsploadGame2D.result.tex = 0;
    vsploadGame2D.result.frame = 0;
    vsploadGame2D.soft.utd = 0;
    vsploadGame2D.soft.tex = 0;
    vsploadGame2D.soft.umd = 0;
    vsploadGame2D.board_umd = 0;
    vsploadGame2D.board_utd = 0;
    vsploadGame2D.board_tex = 0;
    vsploadGame2D.ayboard_utd = 0;
    read_data.addr = 0;
    read_data.tail = 1;
    read_data.id = 0;
    read_data.align = 0;
    read_data.ee_iop = 0;
    read_data.func = sploadGetAddr; // 0x20
    read_data.no = vspenvGame->course.no + 0x1E;
    read_data.src[0] = (int)&vsploadGame2D;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.tail = 0;
    read_data.id = 1;
    if (vspenvGame->language == 0) {
        read_data.no = 0x27;
    } else if (vspenvGame->language == 1) {
        read_data.no = 0x28;
    } else if (vspenvGame->language == 2) {
        read_data.no = 0x29;
    }
    read_data.src[0] = (int)&vsploadGame2D.result.utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.tail = 0;
    read_data.id = 1;
    read_data.no = 0x2D;
    read_data.src[0] = (int)&vsploadGame2D.soft.umd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.tail = 0;
    read_data.id = 1;
    read_data.no = 0x2E;
    read_data.src[0] = (int)&vsploadGame2D.soft.utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.no = 0x2A;
    read_data.src[0] = (int)&vsploadGame2D.board_umd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.no = 0x2B;
    read_data.src[0] = (int)&vsploadGame2D.board_utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.no = 0x2C;
    read_data.src[0] = (int)&vsploadGame2D.ayboard_utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
}

void sploadSetGameEtc() {
    // Size: 0x20, DWARF: 0xADD43
    struct //: E:\tam\ps2\sppbx\main.c
    {
        signed int* addr; // Offset: 0x0, DWARF: 0xADD5F
        signed short que_no; // Offset: 0x4, DWARF: 0xADD83
        signed short no; // Offset: 0x6, DWARF: 0xADDA6
        signed short tail; // Offset: 0x8, DWARF: 0xADDC5
        signed short id; // Offset: 0xA, DWARF: 0xADDE6
        signed short align; // Offset: 0xC, DWARF: 0xADE05
        signed short ee_iop; // Offset: 0xE, DWARF: 0xADE27
        void(*func)(void*, signed int, signed int, signed int, signed int); // Offset: 0x10, DWARF: 0xADE4A
        signed int src[3]; // Offset: 0x14, DWARF: 0xADE70
    } read_data; // 0x10(r29)

    vsploadGameEtc.link = 0;
    read_data.addr = 0;
    read_data.tail = 0; // 0x18
    read_data.id = 1; // 0x1A
    read_data.align = 0; // 0x1C
    read_data.ee_iop = 0; // 0x1E
    read_data.func = sploadGetAddr; // 0x20
    read_data.no = vspenvGame->course.no + 0x2F;
    read_data.src[0] = (int)&vsploadGameEtc;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    vsploadGameEtc.vib_link[0] = 0;
    vsploadGameEtc.vib_link[1] = 0;
    read_data.no = 7;
    read_data.src[0] = (int)&vsploadGameEtc.vib_link;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.no = vspenvGame->course.no + 8;
    read_data.src[0] = (int)&vsploadGameEtc.vib_link[1];
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
}

void sploadSetCharacter() {
    ////////////////////////////////
    // Expected variables:
    signed int jj; // r16
    signed int ii; // r17
    // Size: 0x20, DWARF: 0xADD43
    struct //: E:\tam\ps2\sppbx\main.c
    {
        signed int* addr; // Offset: 0x0, DWARF: 0xADD5F
        signed short que_no; // Offset: 0x4, DWARF: 0xADD83
        signed short no; // Offset: 0x6, DWARF: 0xADDA6
        signed short tail; // Offset: 0x8, DWARF: 0xADDC5
        signed short id; // Offset: 0xA, DWARF: 0xADDE6
        signed short align; // Offset: 0xC, DWARF: 0xADE05
        signed short ee_iop; // Offset: 0xE, DWARF: 0xADE27
        void(*func)(void*, signed int, signed int, signed int, signed int); // Offset: 0x10, DWARF: 0xADE4A
        signed int src[3]; // Offset: 0x14, DWARF: 0xADE70
    } read_data; // 0x30(r29)
    //////////////////////////////
    

    for (ii = 0; ii < 2; ii++) {
        vsploadCharacter.model[ii].link = 0;
        vsploadCharacter.model[ii].vmd[0] = 0;
        vsploadCharacter.model[ii].vmd[1] = 0;
        vsploadCharacter.model[ii].seq = 0;
        vsploadCharacter.model[ii].seq = 0;
        for (jj = 0; jj < 2; jj++) {
            vsploadCharacter.model[ii].utd[jj].utd = 0;
            vsploadCharacter.model[ii].utd[jj].tex = 0;
            vsploadCharacter.model[ii].utd[jj].frame = 0;
        }
    }
    vsploadCharacter.link = 0;
    vsploadCharacter.regular_uad = 0;
    vsploadCharacter.fakie_uad = 0;
    vsploadCharacter.goal_uad = 0;
    vsploadCharacter.mode_uad = 0;
    for (ii = 0; ii < 2; ii++) {
        for (jj = 0; jj < 7; jj++) {
            vsploadCreate[ii].vmd[jj] = 0;
            vsploadCreate[ii].utd[jj] = 0;
            vsploadCreate[ii].alpha_utd[jj] = 0;
            vsploadCreate[ii].size[jj] = 0;
            vsploadCreate[ii].ntex[jj] = 0;
            vsploadCreate[ii].alpha_ntex[jj] = 0;
        }
        vsploadCreate[ii].arm_utd = 0;
        vsploadCreate[ii].leg_utd = 0;
    }
    read_data.addr = 0;
    read_data.align = 0;
    read_data.ee_iop = 0;
    read_data.tail = 0;
    read_data.id = 1;
    read_data.func = sploadGetAddr;
    for (ii = 0; ii < vspenvGame->mode.num_player; ii++) {
        if (vspenvReplay[ii]->cheats.metallic == 1) {
            if (vspenvGame->character[ii].no < 0xC) {
                read_data.no = vspenvGame->character[ii].wear + ((vspenvGame->character[ii].no * 3) + 0x2BD);
                read_data.src[0] = (int)&vsploadCharacter.model[ii].link;
                read_data.src[1] = 0;
                read_data.src[2] = 0;
                uldvdReadData_DRIVE(&read_data);
            } else {
                sploadSetCreateCharacter(ii);
            }
        } else if (vspenvGame->character[ii].no < 0xC) {
            read_data.no = vspenvGame->character[ii].wear + ((vspenvGame->character[ii].no * 3) + 0x299);
            read_data.src[0] = (int)&vsploadCharacter.model[ii].link;
            read_data.src[1] = 0;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(&read_data);
        } else {
            sploadSetCreateCharacter(ii);
        }
    }
    read_data.no = 0x128;
    read_data.src[0] = (int)&vsploadCharacter.link;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
    read_data.no = 0x2E1;
    read_data.src[0] = (int)&vsploadEnvMap.utd;
    read_data.src[1] = 0;
    read_data.src[2] = 0;
    uldvdReadData_DRIVE(&read_data);
}

void sploadSetCreateCharacter(signed int player) {
    // Size: 0xEC, DWARF: 0xABF3E
    CreateCharacter* create; // r16
    signed int ii; // r17c
    signed int chr_no; // r18
    signed int read_no[14]; // 0x40(r29)
    // Size: 0x20, DWARF: 0xAE619
    ReadData read_data; // 0x80(r29)

    chr_no = vspenvGame->character[player].no - 0xC;
    create = &vspenvReplay[player]->character;
    read_data.addr = 0;
    read_data.align = 0;
    read_data.ee_iop = 0;
    read_data.tail = 1;
    read_data.id = 1; 
    read_data.func = sploadGetCreateAddr;
    read_data.src[0] = player;
    read_data.src[2] = 0;
    if (create->sex == 0) {
        if (vspenvReplay[player]->cheats.metallic == 1) {
            read_no[1] = create->face + 0x139;
            read_no[2] = create->body + 0x150;
            read_no[3] = create->pants + 0x187;
            read_no[4] = 0x1B5;
            read_no[5] = 0x1BB;
            read_no[0] = 0x1C1;
            read_no[6] = create->hair + 0x1C7;
            read_no[8] = create->face + 0x139;
            read_no[9] = create->body + 0x150;
            read_no[10] = create->pants + 0x187;
            read_no[11] = 0x1B5;
            read_no[12] = 0x1BB;
            read_no[7] = 0x1C1;
            read_no[13] = create->hair + 0x1C7;
        } else {
            read_no[1] = create->face + 0x130;
            read_no[2] = create->body + 0x14B;
            read_no[3] = create->pants + 0x182;
            read_no[4] = 0x1B4;
            read_no[5] = 0x1BA;
            read_no[0] = 0x1C0;
            read_no[6] = create->hair + 0x1C3;
            read_no[8] = create->face + 0x130;
            read_no[9] = create->body + 0x14B;
            read_no[10] = create->pants + 0x182;
            read_no[11] = 0x1B4;
            read_no[12] = 0x1BA;
            read_no[7] = 0x1C0;
            read_no[13] = create->hair + 0x1CB;
        }
    } else if (vspenvReplay[player]->cheats.metallic == 1) {
        read_no[1] = create->face + 0x1F8;
        read_no[2] = create->body + 0x20E;
        read_no[3] = create->pants + 0x23A;
        read_no[4] = 0x25F;
        read_no[5] = 0x265;
        read_no[0] = 0x26B;
        read_no[6] = create->hair + 0x271;
        read_no[8] = create->face + 0x1F8;
        read_no[9] = create->body + 0x20E;
        read_no[10] = create->pants + 0x23A;
        read_no[11] = 0x25F;
        read_no[12] = 0x265;
        read_no[7] = 0x26B;
        read_no[13] = create->hair + 0x271;
    } else {
        read_no[1] = create->face + 0x1EF;
        read_no[2] = create->body + 0x20A;
        read_no[3] = create->pants + 0x236;
        read_no[4] = 0x25E;
        read_no[5] = 0x264;
        read_no[0] = 0x26A;
        read_no[6] = create->hair + 0x26D;
        read_no[8] = create->face + 0x1EF;
        read_no[9] = create->body + 0x20A;
        read_no[10] = create->pants + 0x236;
        read_no[11] = 0x25E;
        read_no[12] = 0x264;
        read_no[7] = 0x26A;
        read_no[13] = create->hair + 0x275;
    }
    for (ii = 0; ii < 0xE; ii++) {
        read_data.no = read_no[ii];
        read_data.src[1] = ii;
        uldvdReadData_DRIVE(&read_data);
    }
    if (vspenvReplay[player]->cheats.metallic == 1) {
        read_data.src[2] = 1;
        read_data.no = 0x2E1;
        read_data.src[1] = 0;
        uldvdReadData_DRIVE(&read_data);
        return;
    }
    read_data.src[2] = 1;
    if (create->sex == 0) {
        read_no[1] = create->face + 0x142;
        read_no[2] = create->body_color + ((create->body * 9) + 0x155);
        read_no[3] = create->pants_color + ((create->pants * 8) + 0x18C);
        read_no[4] = create->glove + 0x1B6;
        read_no[5] = create->boots + 0x1BC;
        read_no[0] = 0x1C2;
        read_no[6] = create->hair_color + ((create->hair * 4) + 0x1CF);
    } else {
        read_no[1] = create->face + 0x201;
        read_no[2] = create->body_color + ((create->body * 9) + 0x212);
        read_no[3] = create->pants_color + ((create->pants * 8) + 0x23E);
        read_no[4] = create->glove + 0x260;
        read_no[5] = create->boots + 0x266;
        read_no[0] = 0x26C;
        read_no[6] = create->hair_color + ((create->hair * 4) + 0x279);
    }
    for (ii = 0; ii < 7; ii++) {
        read_data.no = read_no[ii];
        read_data.src[1] = ii;
        uldvdReadData_DRIVE(&read_data);
    }
    if (create->sex == 0) {
        read_data.no = 0x12D;
        read_data.src[2] = 3;
        uldvdReadData_DRIVE(&read_data);
        read_data.no = 0x12E;
        read_data.src[2] = 4;
        uldvdReadData_DRIVE(&read_data);
    } else {
        read_data.no = 0x12F;
        read_data.src[2] = 3;
        uldvdReadData_DRIVE(&read_data);
        read_data.no = 0x12E;
        read_data.src[2] = 4;
        uldvdReadData_DRIVE(&read_data);
    }
    if (create->sex == 0) {
        read_data.no = create->hair_color + ((create->hair * 4) + 0x1DF);
    } else {
        read_data.no = create->hair_color + ((create->hair * 4) + 0x289);
    }
    read_data.src[1] = 6;
    read_data.src[2] = 2;
    uldvdReadData_DRIVE(&read_data);
}

void sploadSetCourse(int no, int chr) {
    ////////////////////////////////////////////////////
    // Expected variables:
    signed int character; // r16
    signed int tmp; // not in dwarf
    // // Size: 0x20, DWARF: 0xADD43
    ReadData read_data; // 0x30(r29)
    signed int crs_tbl[8][17] = {
        //Base  Draw   DFar    Dnear  Butd   Dutd   Object Outd   [Alpha Utd]  [Bg utd Umd] Event  Hit    Vector Rail   Bonk
        // 0    1      2       3      4      5      6      7      8      9      10    11    12     13     14     15     16
        { 0x53, 0x54,  0x56,   0x55,  0x59,  0x5A,  0x58,  0x68,  0x57,  0x67,  0x38, 0x3A, 0x120, 0x69,  0x6A,  0x6B,  0x6C  }, // 0: Donner Ski Ranch
        { 0x6D, 0x6E,  0x70,   0x6F,  0x73,  0x74,  0x72,  0x82,  0x71,  0x81,  0x3B, 0x3D, 0x121, 0x83,  0x84,  0x85,  0x86  }, // 1: Aspen
        { 0x87, 0x88,  0x8A,   0x89,  0x8D,  0x8E,  0x8C,  0x9C,  0x8B,  0x9B,  0x3E, 0x40, 0x122, 0x9D,  0x9E,  0x9F,  0xA0  }, // 2: Kirkwood
        { 0xA1, 0xA2,  0xA4,   0xA3,  0xA7,  0xA8,  0xA6,  0xB6,  0xA5,  0xB5,  0x41, 0x43, 0x123, 0xB7,  0xB8,  0xB9,  0xBA  }, // 3: Heavenly
        { 0xBB, 0xBC,  0xBE,   0xBD,  0xC1,  0xC2,  0xC0,  0xD0,  0xBF,  0xCF,  0x44, 0x46, 0x124, 0xD1,  0xD2,  0xD3,  -1    }, // 4: Snowbird
        { 0xD4, 0xD5,  0xD7,   0xD6,  0xDA,  0xDB,  0xD9,  0xE9,  0xD8,  0xE8,  0x47, 0x49, 0x125, 0xEA,  0xEB,  0xEC,  0xED  }, // 5: Squaw Valley USA
        { 0xEE, 0xEF,  0xF1,   0xF0,  0xF4,  0xF5,  0xF3,  0x103, 0xF2,  0x102, 0x4A, 0x4C, 0x126, 0x104, 0x105, 0x106, 0x107 }, // 6: Mt. Hood Meadows Ski Resort
        { 0x108, 0x109, 0x10B, 0x10A, 0x10E, 0x10F, 0x10D, 0x11D, 0x10C, 0x11C, 0x4D, 0x4F, 0x127, 0x11E, -1,    0x11F, -1    }, // 7: Gotcha Glacier
    }; // 0x50(r29)
    ///////////////////////////////////////////////////////

    tmp = (int)&crs_tbl;
    
    vsploadCourse.base_link     = 0;
    vsploadCourse.draw_link     = 0;
    vsploadCourse.dfar_link     = 0;
    vsploadCourse.dnear_link    = 0;
    vsploadCourse.butd_link     = 0;
    vsploadCourse.dutd_link     = 0;
    vsploadCourse.outd_link     = 0;
    vsploadCourse.object        = 0;
    vsploadCourse.alpha         = 0;
    vsploadCourse.alpha_utd     = 0;
    vsploadCourse.bg_utd[0]     = 0;
    vsploadCourse.bg_utd[1]     = 0;
    vsploadCourse.bg_umd        = 0;
    vsploadCourse.hit           = 0;
    vsploadCourse.vector        = 0;
    vsploadCourse.rail          = 0;
    vsploadCourse.bonk          = 0;
    vsploadCourse.event_link    = 0;
    read_data.addr              = 0;
    read_data.tail              = 0;
    read_data.id                = 1;
    read_data.align             = 0;
    read_data.ee_iop            = 0;
    read_data.func = &sploadGetAddr;
    if (0xC < chr) {
        character = 0xC;
    } else {
        character = chr;
    }
    if (crs_tbl[no][0] != -1) {
        read_data.no = crs_tbl[no][0];
        read_data.src[0] = (int)&vsploadCourse.base_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][1] != -1) {
        read_data.no = crs_tbl[no][1];
        read_data.src[0] = (int)&vsploadCourse.draw_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][2] != -1) {
        read_data.no = crs_tbl[no][2];
        read_data.src[0] = (int)&vsploadCourse.dfar_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    // Dutd (Building/non-terrain textures?)
    if (crs_tbl[no][3] != -1) {
        read_data.no = crs_tbl[no][3];
        read_data.src[0] = (int)&vsploadCourse.dnear_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][8] != -1) {
        read_data.no = crs_tbl[no][8];
        read_data.src[0] = (int)&vsploadCourse.alpha;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    // Object Collision (not terrain)
    if (crs_tbl[no][13] != -1) {
        read_data.no = crs_tbl[no][13];
        read_data.src[0] = (int)&vsploadCourse.hit;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][14] != -1) {
        read_data.no = crs_tbl[no][14];
        read_data.src[0] = (int)&vsploadCourse.vector;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][15] != -1) {
        read_data.no = crs_tbl[no][15];
        read_data.src[0] = (int)&vsploadCourse.rail;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][16] != -1) {
        read_data.no = crs_tbl[no][16];
        read_data.src[0] = (int)&vsploadCourse.bonk;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][6] != -1) {
        read_data.no = crs_tbl[no][6];
        read_data.src[0] = (int)&vsploadCourse.object;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][12] != -1) {
        read_data.no = crs_tbl[no][12];
        read_data.src[0] = (int)&vsploadCourse.event_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][10] != -1) {
        read_data.no = crs_tbl[no][10];
        read_data.src[0] = (int)&vsploadCourse.bg_utd[0];
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
        read_data.no = crs_tbl[no][10] + 1;
        read_data.src[0] = (int)&vsploadCourse.bg_utd[1];
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
        read_data.no = crs_tbl[no][11];
        read_data.src[0] = (int)&vsploadCourse.bg_umd;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][9] != -1) {
        read_data.no = crs_tbl[no][9];
        read_data.src[0] = (int)&vsploadCourse.alpha_utd;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    // Outd (Primarily environment prop textures)
    if (crs_tbl[no][7] != -1) {
        read_data.no = crs_tbl[no][7];
        read_data.src[0] = (int)&vsploadCourse.outd_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][5] != -1) {
        read_data.no = crs_tbl[no][5] + character;
        read_data.src[0] = (int)&vsploadCourse.dutd_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    if (crs_tbl[no][4] != -1) {
        read_data.no = crs_tbl[no][4];
        read_data.src[0] = (int)&vsploadCourse.butd_link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
}

static void sploadSetSound(signed int type /* 0x30(r29) */, signed int no /* 0x40(r29) */, signed int player /* 0x50(r29) */) {
    // Size: 0x20, DWARF: 0xAE619
    ReadData read_data; // 0x10(r29)
    read_data.addr = 0;

    read_data.tail = 1;
    read_data.id = 0;
    read_data.align = 0;
    read_data.ee_iop = 1;
    read_data.func = sploadSetSoundAddr;

    switch (type) {
        case 0:
            read_data.no = 0x2E2;
            read_data.src[0] = 0;
            read_data.src[1] = 0;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            break;
        case 1:
            read_data.no = 0x2E3;
            read_data.src[0] = 0;
            read_data.src[1] = 1;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            break;
        case 2:
            read_data.no = 0x303;
            read_data.src[0] = 2;
            read_data.src[1] = 0;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            read_data.no = 0x302;
            read_data.src[0] = 3;
            read_data.src[1] = 0;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            read_data.no = 0x301;
            read_data.src[0] = 4;
            read_data.src[1] = 0;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            break;
        case 3:
            read_data.no = 0x2E5;
            read_data.src[0] = 0;
            read_data.src[1] = 5;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            read_data.no = 0x2E4;
            read_data.src[0] = 0;
            read_data.src[1] = 3;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            break;
        case 4:
            read_data.no = no + 0x304;
            read_data.src[0] = 0;
            if (player)
                read_data.src[1] = 2;
            else {
                read_data.src[1] = 1;
            }
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            break;
        case 5:
            if (vspenvGame->language == 0) {
                // English language
                read_data.no = no + 0x2E6;
            } else if (vspenvGame->language == 1) {
                // German Language
                read_data.no = no  + 0x2EF;
            } else if (vspenvGame->language == 2) {
                // French language
                read_data.no = no  + 0x2F8;
            }
            read_data.src[0] = 0;
            read_data.src[1] = 4;
            read_data.src[2] = 0;
            uldvdReadData_DRIVE(read_data);
            vsploadSystem.sound_data++;
            break;
    }
}

static void sploadInitCommon() {
    signed int ii;
    signed int tnum;
    Data data;

    ultexResetTex(0x2800);
    tnum = ultexGetNTex(vsploadCommon.font);
    vsploadCommon.font_tex = (void*)ulMalloc(tnum * 0x10, 0, 0);
    ultexTransTex(vsploadCommon.font, vsploadCommon.font_tex);
    for (ii = 0; ii < tnum; ii++) {
        nmfontSetTexData(&vsploadCommon.font_tex[ii], ii);
    }
    nmfontSetLang(vspenvGame->language);
    ulFree(vsploadCommon.font);
    ulFree(vsploadCommon.font_tex);
    tnum = ultexGetNTex(vsploadCommon.effect);
    vsploadCommon.effect_tex = (void*)ulMalloc(tnum * 0x10, 0, 0);
    ultexTransTex(vsploadCommon.effect, vsploadCommon.effect_tex);
    spfxSetTexData(vsploadCommon.effect_tex);
    ulFree(vsploadCommon.effect);
    vsploadCommon.offset = ultexSetAlign();
    tnum = ultexGetNTex(vsploadCommon.load);
    vsploadCommon.load_tex = (void*)ulMalloc(tnum * 0x10, 0, 0);
    ultexTransTex(vsploadCommon.load, vsploadCommon.load_tex);
    if (vsploadIcon.link != 0) {
        tmlinkMappingData((unsigned int)vsploadIcon.link, &data);
        vsploadIcon.system[0] = (unsigned int*)data.block[0].addr;
        vsploadIcon.system[1] = (unsigned int*)data.block[1].addr;
        vsploadIcon.system[2] = (unsigned int*)data.block[2].addr;
        vsploadIcon.replay[0] = (unsigned int*)data.block[3].addr;
        vsploadIcon.replay[1] = (unsigned int*)data.block[4].addr;
        vsploadIcon.replay[2] = (unsigned int*)data.block[5].addr;
    }
    tmlinkMappingData((unsigned int)vsploadVibration.link, &data);
    for (ii = 0; ii < data.head->num; ii++) {
        vsploadVibration.data[ii] = (char*)data.block[ii].addr;
    }
}

void sploadInitMovie() {
    ultexResetTex(vsploadCommon.offset);
    vsploadMovie.offset = ultexSetAlign();
}

static void sploadInitSelect(void) {
    signed int ii; // r18
    signed int jj; // r16
    signed int kk; // r17
    Data data; // 0x58(r29)
    unsigned char* tmp; // r19

    if (vsploadDemoData != 0) {
        tmp = vsploadDemoData;
        memcpy(&vsploadReplayHead, tmp, 0x10);
        tmp += 0x10;
        for (ii = 0; ii < 2; ii++) {
            memcpy(vspenvReplay[ii], tmp, 0x2DCEC);
            tmp += 0x2DCEC;
        }
        ulFree(vsploadDemoData);
    }
    sceGifPkReset(vgmsysGifPkt);
    ultexResetTex(vsploadCommon.offset);
    vsploadSelect.offset = ultexSetAlign();
    maMdlMotionMap(vsploadSelect.select_uad);
    tmlinkMappingData((unsigned int)vsploadSelect.link[0], &data);
    vsploadSelect.select_utd = (unsigned int*)data.block[0].addr;
    vsploadSelect.selmov_utd = (unsigned int*)data.block[1].addr;
    vsploadSelect.sponsor_utd = (unsigned int*)data.block[2].addr;
    vsploadSelect.sponsor_tex = ulMalloc(ultexGetNTex(vsploadSelect.sponsor_utd) * 0x10, 0, 0);
    ultexResetTex(vsploadSelect.offset);
    ultexTransTex(vsploadSelect.sponsor_utd, vsploadSelect.sponsor_tex);
    vsploadSelect.board_umd = (__int128*)data.block[3].addr;
    vsploadSelect.board_vmd = (unsigned char*)data.block[4].addr;
    vsploadSelect.board_utd = (unsigned int*)data.block[5].addr;
    vsploadSelect.ayboard_utd = (unsigned int*)data.block[6].addr;
    vsploadSelect.board_tex = ulMalloc(ultexGetNTex(vsploadSelect.board_utd) * 0x10, 0, 0);
    ultexResetTex(vsploadSelect.offset);
    ultexTransTex(vsploadSelect.board_utd, vsploadSelect.board_tex);
    ulmdlInitModel(vsploadSelect.board_umd);
    ulmdlSetModelTexture(vsploadSelect.board_umd, vsploadSelect.board_tex);
    ulvumdlInitModel(vsploadSelect.board_vmd, vsploadSelect.board_tex, 0);
    if (vsploadSelect.link[1] != 0) {
        tmlinkMappingData((unsigned int)vsploadSelect.link[1], &data);
        vsploadSelect.pad_utd = (unsigned int*)data.block[0].addr;
        vsploadSelect.pad_tex = ulMalloc(ultexGetNTex(vsploadSelect.pad_utd) * 0x10, 0, 0);
        ultexResetTex(vsploadSelect.offset);
        ultexTransTex(vsploadSelect.pad_utd, vsploadSelect.pad_tex);
        for (ii = 0; ii < 9; ii++) {
            vsploadSelect.pad_umd[ii] = (__int128*)data.block[ii + 1].addr;
            ulmdlInitModel(vsploadSelect.pad_umd[ii]);
            ulmdlSetModelTexture(vsploadSelect.pad_umd[ii], vsploadSelect.pad_tex);
        }
    }
    for (ii = 0; ii < 2; ii++) {
        tmlinkMappingData((unsigned int)vsploadSelect.create_chr[ii].link, &data);
        for (jj = 0; jj < 9; jj++) {
            vsploadSelect.create_chr[ii].face_umd[jj] = (__int128*)data.block[jj].addr;
            vsploadSelect.create_chr[ii].face_utd[jj] = (unsigned int*)data.block[jj + 9].addr;
            vsploadSelect.create_chr[ii].face_tex[jj] = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].face_utd[jj]) * 0x10, 0, 0);
            ultexResetTex(vsploadSelect.offset);
            ultexTransTex(vsploadSelect.create_chr[ii].face_utd[jj], vsploadSelect.create_chr[ii].face_tex[jj]);
            ulvumdlInitModel(vsploadSelect.create_chr[ii].face_umd[jj], vsploadSelect.create_chr[ii].face_tex[jj], 0);
            vsploadSelect.create_chr[ii].face_seq[jj] = maMdlMotionInit(vsploadSelect.select_uad, 0);
        }
        for (jj = 0; jj < 4; jj++) {
            vsploadSelect.create_chr[ii].hair_umd[jj][0] = (__int128*)data.block[jj + 0x16].addr;
            vsploadSelect.create_chr[ii].hair_umd[jj][1] = (__int128*)data.block[jj + 0x12].addr;
            for (kk = 0; kk < 4; kk++) {
                vsploadSelect.create_chr[ii].hair_utd[jj][kk][0] = (unsigned int*)data.block[kk + 0x1A + (jj * 4)].addr;
                vsploadSelect.create_chr[ii].hair_utd[jj][kk][1] = (unsigned int*)data.block[kk + 0x2A + (jj * 4)].addr;
            }
            vsploadSelect.create_chr[ii].hair_tex[jj][0] = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].hair_utd[jj][0][0]) * 0x10, 0, 0);
            vsploadSelect.create_chr[ii].hair_tex[jj][1] = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].hair_utd[jj][0][1]) * 0x10, 0, 0);
            ultexResetTex(vsploadSelect.offset);
            ultexTransTex(vsploadSelect.create_chr[ii].hair_utd[jj][0][0], vsploadSelect.create_chr[ii].hair_tex[jj][0]);
            ultexResetTex(vsploadSelect.offset);
            ultexTransTex(vsploadSelect.create_chr[ii].hair_utd[jj][0][1], vsploadSelect.create_chr[ii].hair_tex[jj][1]);
            ulvumdlInitModel(vsploadSelect.create_chr[ii].hair_umd[jj][0], vsploadSelect.create_chr[ii].hair_tex[jj][0], vsploadSelect.create_chr[ii].hair_tex[jj][1]);
            ulvumdlInitModel(vsploadSelect.create_chr[ii].hair_umd[jj][1], vsploadSelect.create_chr[ii].hair_tex[jj][0], vsploadSelect.create_chr[ii].hair_tex[jj][1]);
            vsploadSelect.create_chr[ii].hair_seq[jj] = maMdlMotionInit(vsploadSelect.select_uad, 0);
        }
        for (jj = 0; jj < 5; jj++) {
            vsploadSelect.create_chr[ii].body_umd[jj] = (__int128*)data.block[jj + 0x3A].addr;
            for (kk = 0; kk < 9; kk++) {
                vsploadSelect.create_chr[ii].body_utd[jj][kk] = (unsigned int*)data.block[kk + 0x3F + (jj * 9)].addr;
            }
            vsploadSelect.create_chr[ii].body_tex[jj] = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].body_utd[jj][0]) * 0x10, 0, 0);
            ultexResetTex(vsploadSelect.offset);
            ultexTransTex(vsploadSelect.create_chr[ii].body_utd[jj][0], vsploadSelect.create_chr[ii].body_tex[jj]);
            ulvumdlInitModel(vsploadSelect.create_chr[ii].body_umd[jj], vsploadSelect.create_chr[ii].body_tex[jj], 0);
            vsploadSelect.create_chr[ii].body_seq[jj] = maMdlMotionInit(vsploadSelect.select_uad, 0);
        }
        for (jj = 0; jj < 5; jj++) {
            vsploadSelect.create_chr[ii].pants_umd[jj] = (__int128*)data.block[jj + 0x6C].addr;
            for (kk = 0; kk < 8; kk++) {
                vsploadSelect.create_chr[ii].pants_utd[jj][kk] = (unsigned int*)data.block[kk + 0x71 + (jj * 8)].addr;
            }
            vsploadSelect.create_chr[ii].pants_tex[jj] = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].pants_utd[jj][0]) * 0x10, 0, 0);
            ultexResetTex(vsploadSelect.offset);
            ultexTransTex(vsploadSelect.create_chr[ii].pants_utd[jj][0], vsploadSelect.create_chr[ii].pants_tex[jj]);
            ulvumdlInitModel(vsploadSelect.create_chr[ii].pants_umd[jj], vsploadSelect.create_chr[ii].pants_tex[jj], 0);
            vsploadSelect.create_chr[ii].pants_seq[jj] = maMdlMotionInit(vsploadSelect.select_uad, 0);
        }
        vsploadSelect.create_chr[ii].glove_umd = (__int128*)data.block[0x99].addr;
        for (jj = 0; jj < 4; jj++) {
            vsploadSelect.create_chr[ii].glove_utd[jj] = (unsigned int*)data.block[jj + 0x9A].addr;
        }
        vsploadSelect.create_chr[ii].glove_tex = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].glove_utd[0]) * 0x10, 0, 0);
        ultexResetTex(vsploadSelect.offset);
        ultexTransTex(vsploadSelect.create_chr[ii].glove_utd[0], vsploadSelect.create_chr[ii].glove_tex);
        ulvumdlInitModel(vsploadSelect.create_chr[ii].glove_umd, vsploadSelect.create_chr[ii].glove_tex, 0);
        vsploadSelect.create_chr[ii].glove_seq = maMdlMotionInit(vsploadSelect.select_uad, 0);
        vsploadSelect.create_chr[ii].boots_umd = (__int128*)data.block[0x9E].addr;
        for (jj = 0; jj < 4; jj++) {
            vsploadSelect.create_chr[ii].boots_utd[jj] = (unsigned int*)data.block[jj + 0x9F].addr;
        }
        vsploadSelect.create_chr[ii].boots_tex = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].boots_utd[0]) * 0x10, 0, 0);
        ultexResetTex(vsploadSelect.offset);
        ultexTransTex(vsploadSelect.create_chr[ii].boots_utd[0], vsploadSelect.create_chr[ii].boots_tex);
        ulvumdlInitModel(vsploadSelect.create_chr[ii].boots_umd, vsploadSelect.create_chr[ii].boots_tex, 0);
        vsploadSelect.create_chr[ii].boots_seq = maMdlMotionInit(vsploadSelect.select_uad, 0);
        vsploadSelect.create_chr[ii].board_umd = (__int128*)data.block[0xA3].addr;
        vsploadSelect.create_chr[ii].board_utd = (unsigned int*)data.block[0xA4].addr;
        vsploadSelect.create_chr[ii].board_tex = ulMalloc(ultexGetNTex(vsploadSelect.create_chr[ii].board_utd) * 0x10, 0, 0);
        ultexResetTex(vsploadSelect.offset);
        ultexTransTex(vsploadSelect.create_chr[ii].board_utd, vsploadSelect.create_chr[ii].board_tex);
        ulvumdlInitModel(vsploadSelect.create_chr[ii].board_umd, vsploadSelect.create_chr[ii].board_tex, 0);
        vsploadSelect.create_chr[ii].board_seq = maMdlMotionInit(vsploadSelect.select_uad, 0);
    }
    vsploadSelect.env_tex = ulMalloc(ultexGetNTex(vsploadSelect.env_utd) * 0x10, 0, 0);
    ultexResetTex(0x3F00);
    ultexTransTex(vsploadSelect.env_utd, vsploadSelect.env_tex);
    ultexResetTex(vsploadSelect.offset);
}

void sploadInitGameCommon() {
    sploadInitGame2D();
    sploadInitCharacter();
    sploadInitCourse();
    sploadInitGameEtc();
}

void sploadInitGame2D() {
    vsploadGame2D.game.offset = 0x3C00;
    vsploadGame2D.game.ntex = (int)ultexGetNTex(vsploadGame2D.game.utd);
    vsploadGame2D.game.tex = (void*)ulMalloc(vsploadGame2D.game.ntex * 0x10, 0, 0);
    ultexResetTex(vsploadGame2D.game.offset);
    vsploadGame2D.game.block = ultexGetUseBlock(vsploadGame2D.game.utd);
    vsploadGame2D.game.frame = (void*)ulMalloc(ultexGetUseMemory(vsploadGame2D.game.block), 0, 0);
    ultexTransTex(vsploadGame2D.game.utd, vsploadGame2D.game.tex);
    ultexGetTex(vsploadGame2D.game.frame, vsploadGame2D.game.offset, vsploadGame2D.game.block);
    ulFree(vsploadGame2D.game.utd);
    nmdispInit();
    vsploadGame2D.soft.tex = (void*)ulMalloc(ultexGetNTex(vsploadGame2D.soft.utd) * 0x10, 0, 0);
    ultexResetTex(vsploadGame2D.game.offset);
    ultexTransTex(vsploadGame2D.soft.utd, vsploadGame2D.soft.tex);
    ulmdlInitModel(vsploadGame2D.soft.umd);
    ulmdlSetModelTexture(vsploadGame2D.soft.umd, vsploadGame2D.soft.tex);
    vsploadGame2D.result.offset = 0x3000;
    vsploadGame2D.result.ntex = ultexGetNTex(vsploadGame2D.result.utd);
    vsploadGame2D.result.tex = (void*)ulMalloc(vsploadGame2D.result.ntex * 0x10, 0, 0);
    ultexResetTex(vsploadGame2D.result.offset);
    ultexTransTex(vsploadGame2D.result.utd, vsploadGame2D.result.tex);
    vsploadGame2D.board_tex = ulMalloc(ultexGetNTex(vsploadGame2D.board_utd) * 0x10, 0, 0);
    ultexResetTex(vsploadGame2D.result.offset);
    ultexTransTex(vsploadGame2D.board_utd, vsploadGame2D.board_tex);
    ulmdlInitModel(vsploadGame2D.board_umd);
    ulmdlSetModelTexture(vsploadGame2D.board_umd, vsploadGame2D.board_tex);
}

void sploadInitGameEtc() {
    signed int ii; // r16
    // Size: 0x8, DWARF: 0xABB08
    Data data; // 0x28(r29)

    tmlinkMappingData((unsigned int)vsploadGameEtc.link, &data);
    vsploadGameEtc.intro_camera = (unsigned char*)data.block[0].addr;
    vsploadGameEtc.replay_camera = (unsigned char*)data.block[1].addr;
    vsploadGameEtc.accelerate = (unsigned char*)data.block[2].addr;
    vsploadGameEtc.group = (unsigned char*)data.block[3].addr;
    tmetcInit(vsploadGameEtc.accelerate, vsploadGameEtc.group);
    tmlinkMappingData((unsigned int)vsploadGameEtc.vib_link[0], &data);
    for (ii = 0; ii < data.head->num; ii++) {
        vsploadGameEtc.vib_com[ii] = (char*)data.block[ii].addr;
    }
    tmlinkMappingData((unsigned int)vsploadGameEtc.vib_link[1], &data);
    for (ii = 0; ii < data.head->num; ii++) {
        vsploadGameEtc.vib_evt[ii] = (char*)data.block[ii].addr;
    }
}

void sploadInitCharacter() {
    signed int ii; // r16
    signed int jj; // r17
    signed int offset; // r18
    s32* env_tbl_ptr;
    signed int env_tbl[8] = {
        3, 4, 3, 5,
        3, 5, 3, 3
    }; // 0x50(r29)
    // Size: 0x8, DWARF: 0xABB08
    Data data; // 0x78(r29)

    env_tbl_ptr = &env_tbl;
    tmlinkMappingData((s32)vsploadCharacter.link, &data);
    vsploadCharacter.regular_uad = (s32*)data.block[0].addr;
    vsploadCharacter.fakie_uad = (s32*)data.block[1].addr;
    vsploadCharacter.goal_uad = (s32*)data.block[2].addr;
    vsploadCharacter.mode_uad = (s32*)data.block[3].addr;
    maMdlMotionMap(vsploadCharacter.regular_uad);
    maMdlMotionMap(vsploadCharacter.fakie_uad);
    maMdlMotionMap(vsploadCharacter.goal_uad);
    maMdlMotionMap(vsploadCharacter.mode_uad);
    vsploadEnvMap.ntex = ultexGetNTex(vsploadEnvMap.utd);
    vsploadEnvMap.block = ultexGetUseBlock(vsploadEnvMap.utd);
    vsploadEnvMap.tex = (void*)ulMalloc(vsploadEnvMap.ntex * 0x10, 0, 0);
    offset = 0x3C00;
    for (ii = 0; ii < vspenvGame->mode.num_player; ii++) {
        vsploadSystem.init_chr_no[ii] = vspenvGame->character[ii].no;
        if (vspenvGame->character[ii].no < 0xC) {
            tmlinkMappingData((s32)vsploadCharacter.model[ii].link, &data);
            vsploadCharacter.model[ii].vmd[0] = (unsigned char*)data.block[0].addr;
            vsploadCharacter.model[ii].vmd[1] = (unsigned char*)data.block[1].addr;
            vsploadCharacter.model[ii].utd[0].utd = (s32*)data.block[2].addr;
            if (vspenvReplay[ii]->cheats.metallic == 0) {
                vsploadCharacter.model[ii].utd[1].utd = (s32*)data.block[3].addr;
            }
            for (jj = 0; jj < 2; jj++) {
                if (vsploadCharacter.model[ii].utd[jj].utd) {
                    vsploadCharacter.model[ii].utd[jj].ntex = ultexGetNTex(vsploadCharacter.model[ii].utd[jj].utd);
                    vsploadCharacter.model[ii].utd[jj].tex = ulMalloc(ultexGetNTex(vsploadCharacter.model[ii].utd[jj].utd) * 0x10, 0, 0);
                    if (jj == 0) {
                        vsploadCharacter.model[ii].utd[jj].block = (signed int) (vsploadEnvMap.block + ultexGetUseBlock(vsploadCharacter.model[ii].utd[jj].utd));
                        vsploadCharacter.model[ii].utd[jj].frame = ulMalloc(ultexGetUseMemory(vsploadCharacter.model[ii].utd[jj].block), 0, 0);
                        vsploadCharacter.model[ii].utd[jj].offset = 0x3C00;
                        sploadSetCharacterTexture(ii);
                    } else {
                        vsploadCharacter.model[ii].utd[jj].block = ultexGetUseBlock(vsploadCharacter.model[ii].utd[jj].utd);
                        vsploadCharacter.model[ii].utd[jj].frame = ulMalloc(ultexGetUseMemory(vsploadCharacter.model[ii].utd[jj].block), 0, 0);
                        vsploadCharacter.model[ii].utd[jj].offset = offset;
                        ultexResetTex(offset);
                        ultexTransTex(vsploadCharacter.model[ii].utd[jj].utd, vsploadCharacter.model[ii].utd[jj].tex);
                        sceGsSyncPath(0, 0);
                        ultexGetTex(vsploadCharacter.model[ii].utd[jj].frame, vsploadCharacter.model[ii].utd[jj].offset, vsploadCharacter.model[ii].utd[jj].block);
                        offset = ultexSetAlign();
                    }
                }
            }
        } else {
            offset = sploadInitCreateCharacter(ii, offset);
        }
        if (vspenvReplay[ii]->cheats.metallic == 1) {
            vsploadCharacter.envmap_tex0[ii] = ultexGetTEX0(&vsploadCharacter.model[ii].utd[0].tex[vspenvGame->character[ii].wear]);
        } else {
            vsploadCharacter.envmap_tex0[ii] = ultexGetTEX0(&vsploadEnvMap.tex[env_tbl[vspenvGame->course.no]]);
        }
        vsploadCharacter.model[ii].seq = maMdlMotionInit(vsploadCharacter.regular_uad, 0);
        ulvumdlInitModel(vsploadCharacter.model[ii].vmd[0], vsploadCharacter.model[ii].utd[0].tex, vsploadCharacter.model[ii].utd[1].tex);
        sceVu0UnitMatrix(vsploadCharacter.model[ii].ctrl[0].matrix);
        maVuMdlIKInit((__int128*)vsploadCharacter.model[ii].vmd[0], vsploadCharacter.model[ii].ctrl);
        maSecMotionInit((__int128*)vsploadCharacter.model[ii].vmd[0], &vsploadCharacter.model[ii].sctrl[0]);
        ulvumdlInitModel(vsploadCharacter.model[ii].vmd[1], vsploadCharacter.model[ii].utd[0].tex, vsploadCharacter.model[ii].utd[1].tex);
        sceVu0UnitMatrix(vsploadCharacter.model[ii].ctrl[1].matrix);
        maVuMdlIKInit((__int128*)vsploadCharacter.model[ii].vmd[1], &vsploadCharacter.model[ii].ctrl[1]);
        maSecMotionInit((__int128*)vsploadCharacter.model[ii].vmd[1], &vsploadCharacter.model[ii].sctrl[1]);
        vsploadCharacter.model[ii].change[0] = 0;
        vsploadCharacter.model[ii].change[0] = maModelChangeInit((__int128*)vsploadCharacter.model[ii].vmd[0]);
        maModelChangeSet(vsploadCharacter.model[ii].change[0], 0);
        vsploadCharacter.model[ii].change[1] = 0;
        vsploadCharacter.model[ii].change[1] = maModelChangeInit((__int128*)vsploadCharacter.model[ii].vmd[1]);
        maModelChangeSet(vsploadCharacter.model[ii].change[1], 0);
    }
}

static signed int sploadInitCreateCharacter(signed int player, signed int offset) {
    signed int ii;
    signed int tmp;
    CreateCharacter* create;
    signed int nblock;
    signed int alpha_nblock;
    signed int ntex;
    signed int alpha_ntex;
    signed int arm_id;
    signed int leg_id;

    create = &vspenvReplay[player]->character;
    ntex = 0;
    alpha_ntex = 0;
    nblock = 0;
    alpha_nblock = 0;
    for (ii = 0; ii < 7; ii++) {
        if (vsploadCreate[player].utd[ii]) {
            vsploadCreate[player].ntex[ii] = ultexGetNTex(vsploadCreate[player].utd[ii]);
            ntex += vsploadCreate[player].ntex[ii];
            nblock += ultexGetUseBlock(vsploadCreate[player].utd[ii]);
        }
        if (vsploadCreate[player].alpha_utd[ii]) {
            vsploadCreate[player].alpha_ntex[ii] = ultexGetNTex(vsploadCreate[player].alpha_utd[ii]);
            alpha_ntex += vsploadCreate[player].alpha_ntex[ii];
            alpha_nblock += ultexGetUseBlock(vsploadCreate[player].alpha_utd[ii]);
        }
    }
    nblock = nblock + vsploadEnvMap.block;
    vsploadCharacter.model[player].utd[0].tex = (void*)ulMalloc(ntex * 0x10, 0, 0);
    vsploadCharacter.model[player].utd[0].frame = (void*)ulMalloc(ultexGetUseMemory(nblock), 0, 0);
    vsploadCharacter.model[player].utd[1].tex = (void*)ulMalloc(alpha_ntex * 0x10, 0, 0);
    vsploadCharacter.model[player].utd[1].frame = (void*)ulMalloc(ultexGetUseMemory(alpha_nblock), 0, 0);
    ultexResetTex(0x3C00);
    tmp = 0;
    for (ii = 0; ii < 7; ii++) {
        if (vsploadCreate[player].utd[ii]) {
            ultexTransTex(vsploadCreate[player].utd[ii], &vsploadCharacter.model[player].utd[0].tex[tmp]);
            tmp += vsploadCreate[player].ntex[ii];
            if (ii == 2) {
                arm_id = tmp - 1;
            }
            if (ii == 3) {
                leg_id = tmp - 1;
            }
        }
    }
    ultexTransTex(vsploadEnvMap.utd, vsploadEnvMap.tex);
    if ((create->sex == 0) && (create->body == 2) && (vspenvReplay[player]->cheats.metallic == 0)) {
        sceGifPkInit(&vsploadLocalPacket, vsploadLocalAddr);
        sceGifPkReset(&vsploadLocalPacket);
        ultexTransTexTag(&vsploadLocalPacket, vsploadCreate[player].arm_utd, &vsploadCharacter.model[player].utd[0].tex[arm_id], create->face);
        ultexTransTexTag(&vsploadLocalPacket, vsploadCreate[player].leg_utd, &vsploadCharacter.model[player].utd[0].tex[leg_id], create->face);
        ulgifTermPacket(&vsploadLocalPacket);
        FlushCache(0);
        ulgifDmaSend(&vsploadLocalPacket);
        sceGsSyncPath(0, 0);
    }
    if ((create->sex == 1) && (create->body == 2) && (vspenvReplay[player]->cheats.metallic == 0)) {
        sceGifPkInit(&vsploadLocalPacket, vsploadLocalAddr);
        sceGifPkReset(&vsploadLocalPacket);
        ultexTransTexTag(&vsploadLocalPacket, vsploadCreate[player].arm_utd, &vsploadCharacter.model[player].utd[0].tex[arm_id], create->face);
        ulgifTermPacket(&vsploadLocalPacket);
        FlushCache(0);
        ulgifDmaSend(&vsploadLocalPacket);
        sceGsSyncPath(0, 0);
    }
    vsploadCharacter.model[player].utd[0].offset = 0x3C00;
    vsploadCharacter.model[player].utd[0].block = nblock;
    ultexGetTex(vsploadCharacter.model[player].utd[0].frame, vsploadCharacter.model[player].utd[0].offset, vsploadCharacter.model[player].utd[0].block);
    sploadSetCharacterTexture(player);
    ultexResetTex(offset);
    tmp = 0;
    for (ii = 0; ii < 7; ii++) {
        if (vsploadCreate[player].alpha_utd[ii]) {
            ultexTransTex(vsploadCreate[player].alpha_utd[ii], &vsploadCharacter.model[player].utd[1].tex[tmp]);
            tmp += vsploadCreate[player].alpha_ntex[ii];
        }
    }
    vsploadCharacter.model[player].utd[1].offset = offset;
    vsploadCharacter.model[player].utd[1].block = alpha_nblock;
    ultexGetTex(vsploadCharacter.model[player].utd[1].frame, vsploadCharacter.model[player].utd[1].offset, vsploadCharacter.model[player].utd[1].block);
    vsploadCharacter.model[player].vmd[0] = maCreateModelLink(vsploadCreate[player].vmd, vsploadCreate[player].size, vsploadCreate[player].ntex, vsploadCreate[player].alpha_ntex, 7);
    vsploadCharacter.model[player].vmd[1] = maCreateModelLink(&vsploadCreate[player].vmd[7], &vsploadCreate[player].size[7], vsploadCreate[player].ntex, vsploadCreate[player].alpha_ntex, 7);
    for (ii = 0; ii < 0xE; ii++) {
        ulFree(vsploadCreate[player].vmd[ii]);
    }
    for (ii = 0; ii < 7; ii++) {
        ulFree(vsploadCreate[player].utd[ii]);
        ulFree(vsploadCreate[player].alpha_utd[ii]);
    }
    ulFree(vsploadCreate[player].arm_utd);
    ulFree(vsploadCreate[player].leg_utd);
    offset = ultexGetOffset();
    return offset;
}

void sploadInitCourse() {
    // Size: 0x8, DWARF: 0xABB08
    Data data; // 0x28(r29)
    signed int ii; // r16

    tmlinkMappingData((unsigned int)vsploadCourse.base_link, &data);
    for (ii = 0; ii < 0xA; ii++) {
        if (ii < data.head->num) {
            vsploadCourse.base[ii] = (unsigned int*)(data.block[ii].addr);
        } else {
            vsploadCourse.base[ii] = 0;
        }
    }
    tmlinkMappingData((unsigned int)vsploadCourse.butd_link, &data);
    
    for (ii = 0; ii < 0xA; ii++) {
        if (ii < data.head->num) {
            vsploadCourse.base_utd[ii] = (unsigned int*)(data.block[ii].addr);
        } else {
            vsploadCourse.base_utd[ii] = 0;
        }
    }
    *vtmcrsDivideNum = data.head->num;
    tmlinkMappingData((unsigned int)vsploadCourse.draw_link, &data);
    
    for (ii = 0; ii < 0xA; ii++) {
        if (ii < data.head->num) {
            vsploadCourse.draw[ii] = (unsigned int*)(data.block[ii].addr);
        } else {
            vsploadCourse.draw[ii] = 0;
        }
    }
    if (vsploadCourse.dfar_link != 0) {
        tmlinkMappingData((unsigned int)vsploadCourse.dfar_link, &data);
        
        for (ii = 0; ii < 0xA; ii++) {
            if (ii < data.head->num) {
                vsploadCourse.dfar[ii] = (unsigned int*)(data.block[ii].addr);
            } else {
                vsploadCourse.dfar[ii] = 0;
            }
        }
    } else {
        for (ii = 0; ii < 0xA; ii++) {
            vsploadCourse.dfar[ii] = 0;
        }
    }
    if (vsploadCourse.dnear_link != 0) {
        tmlinkMappingData((unsigned int)vsploadCourse.dnear_link, &data);
        for (ii = 0; ii < 0xA; ii++) {
            if (ii < data.head->num) {
                vsploadCourse.dnear[ii] = (unsigned int*)(data.block[ii].addr);
            } else {
                vsploadCourse.dnear[ii] = 0;
            }
        }
    } else {
        for (ii = 0; ii < 0xA; ii++) {
            vsploadCourse.dnear[ii] = 0;
        }
    }
    tmlinkMappingData((unsigned int)vsploadCourse.dutd_link, &data);
    for (ii = 0; ii < 0xA; ii++) {
        if (ii < data.head->num) {
            vsploadCourse.draw_utd[ii] = (unsigned int*)data.block[ii].addr;
        } else {
            vsploadCourse.draw_utd[ii] = 0;
        }
    }
    vtmcrsDivideNum[1] = data.head->num;
    vtmcrsDivideNum[2] = 0;
    if (vsploadCourse.outd_link != 0) {
        tmlinkMappingData((unsigned int)vsploadCourse.outd_link, &data);
        for (ii = 0; ii < 0x60; ii++) {
            if (ii < data.head->num) {
                vsploadCourse.obj_utd[ii] = (unsigned int*)data.block[ii].addr;
            } else {
                vsploadCourse.obj_utd[ii] = 0;
            }
        }
        vtmcrsDivideNum[2] = data.head->num;
    }
    vtmcrsDivideNum[3] = 0;
    if (vsploadCourse.event_link != 0) {
        tmlinkMappingData((unsigned int)vsploadCourse.event_link, &data);
        vsploadCourse.event_uad = (unsigned int*)data.block[0].addr;
        for (ii = 0; ii < 0x20; ii++) {
            if (ii < (data.head->num - 1) / 2) {
                vsploadCourse.event_umd[ii] = (unsigned int*)data.block[(ii * 2) + 1].addr;
                vsploadCourse.event_utd[ii] = (unsigned int*)data.block[(ii * 2) + 2].addr;
            } else {
                vsploadCourse.event_umd[ii] = 0;
                vsploadCourse.event_utd[ii] = 0;
            }
        }
        vtmcrsDivideNum[3] = (data.head->num - 1) / 2;;
    } else {
        vsploadCourse.event_uad = 0;
    }
    ultexResetTex(vsploadCommon.offset);
    tmcrsInit(vsploadGameCommon.course, vspenvReplay[0]->cheats.mirror);
}

void sploadFreeMovie() {
    ulFree(vsploadMovie.utd);
    vsploadMovie.utd = 0;
}

void sploadFreeSelect() {

    signed int chr_no; // r18
    signed int jj; // r16
    signed int ii; // r17

    if ((vspenvGame->mode.game_mode == 2) || (vspenvGame->mode.game_mode == 1)) {
        vsploadCommon.profile = 1;
        sceGsSyncPath(0, 0);
        sceGifPkReset(vgmsysGifPkt);
        ultexResetTex(vsploadCommon.offset);
        ultexTransTex(vsploadCommon.load, 0);
        if (vspenvGame->mode.game_mode == 2) {
            if (vspenvGame->character[0].no >= 0xC) {
                vsploadSystem.freeride_no = rand() % 10;
                vsploadCommon.profile = 0;
            } else {
                vsploadSystem.freeride_no = vspenvGame->character[0].no;
            }
            chr_no = vsploadSystem.freeride_no;
            vsploadCommon.face[chr_no / 2].tofs = -1;
            vsploadCommon.face[chr_no / 2].cofs = -1;
            ultexTransTexTag(vgmsysGifPkt, vsploadSelect.select_utd, &vsploadCommon.face[chr_no / 2], (chr_no / 2) + 0x2E);
        } else {
            for (ii = 0; ii < vspenvGame->mode.num_player; ii++) {
                if (vspenvGame->character[ii].no >= 0xC) {
                    chr_no = 0xC;
                } else {
                    chr_no = vspenvGame->character[ii].no;
                }
                vsploadCommon.face[chr_no / 2].tofs = -1;
                vsploadCommon.face[chr_no / 2].cofs = -1;
                ultexTransTexTag(vgmsysGifPkt, vsploadSelect.select_utd, &vsploadCommon.face[chr_no / 2], (chr_no / 2) + 0x2E);

            }
        }
        for (ii = 0; ii < 0x1D; ii++) {
            vsploadCommon.sponsor[ii].tofs = -1;
            vsploadCommon.sponsor[ii].cofs = -1;
            ultexTransTexTag(vgmsysGifPkt, vsploadSelect.sponsor_utd, &vsploadCommon.sponsor[ii], ii);
        }
        ulgifTermPacket(vgmsysGifPkt);
        ulgifDmaSend(vgmsysGifPkt);
        sceGsSyncPath(0, 0);
    }
    ulFree(vsploadSelect.select_uad);
    ulFree((signed int* ) vsploadSelect.link[0]);
    ulFree((signed int* ) vsploadSelect.link[1]);
    ulFree((signed int* ) vsploadSelect.sponsor_tex);
    ulFree((signed int* ) vsploadSelect.board_tex);
    ulFree((signed int* ) vsploadSelect.medal_tex);
    ulFree((signed int* ) vsploadSelect.game.tex);
    ulFree((signed int* ) vsploadSelect.emblem_tex);
    ulFree((signed int* ) vsploadSelect.wheel.tex);
    ulFree((signed int* ) vsploadSelect.param.tex);
    ulFree((signed int* ) vsploadSelect.pad_tex);
    ulFree((signed int* ) vsploadSelect.cr_arm_utd);
    ulFree((signed int* ) vsploadSelect.cr_leg_utd);
    ulFree((signed int* ) vsploadSelect.cr_arm_f_utd);
    for (ii = 0; ii < 2; ii++) {
        ulFree((signed int*)vsploadSelect.create_chr[ii].link);
        for (jj = 0; jj < 9; jj++) {
            ulFree(vsploadSelect.create_chr[ii].face_tex[jj]);
            maMdlMotionInitEnd(vsploadSelect.create_chr[ii].face_seq[jj]);
        }
        for (jj = 0; jj < 4; jj++) {
            ulFree(vsploadSelect.create_chr[ii].hair_tex[jj][0]);
            ulFree(vsploadSelect.create_chr[ii].hair_tex[jj][1]);
            maMdlMotionInitEnd(vsploadSelect.create_chr[ii].hair_seq[jj]);
        }
        for (jj = 0; jj < 5; jj++) {
            ulFree(vsploadSelect.create_chr[ii].body_tex[jj]);
            maMdlMotionInitEnd(vsploadSelect.create_chr[ii].body_seq[jj]);
        }
        for (jj = 0; jj < 5; jj++) {
            ulFree(vsploadSelect.create_chr[ii].pants_tex[jj]);
            maMdlMotionInitEnd(vsploadSelect.create_chr[ii].pants_seq[jj]);
        }
        ulFree(vsploadSelect.create_chr[ii].glove_tex);
        maMdlMotionInitEnd(vsploadSelect.create_chr[ii].glove_seq);
        ulFree(vsploadSelect.create_chr[ii].boots_tex);
        maMdlMotionInitEnd(vsploadSelect.create_chr[ii].boots_seq);
        ulFree(vsploadSelect.create_chr[ii].board_tex);
        maMdlMotionInitEnd(vsploadSelect.create_chr[ii].board_seq);
    }
    ulFree((signed int* ) vsploadSelect.env_utd);
    ulFree((s32*)&vsploadSelect.env_tex->tofs);
    vsploadSelect.env_utd = 0; // NULL;
    vsploadSelect.env_tex = 0; // NULL;
}

void sploadFreeGameCommon(void) {
    sploadFreeGameEtc();
    sploadFreeGame2D();
    sploadFreeCourse();
    sploadFreeCharacter();
}

void sploadFreeGame2D() {
    ulFree(vsploadGame2D.game.tex);
    ulFree(vsploadGame2D.game.frame);
    ulFree(vsploadGame2D.soft.utd);
    ulFree(vsploadGame2D.soft.tex);
    ulFree(vsploadGame2D.soft.umd);
    ulFree(vsploadGame2D.result.utd);
    ulFree(vsploadGame2D.result.tex);
    ulFree(vsploadGame2D.result.frame);
    ulFree(vsploadGame2D.board_umd);
    ulFree(vsploadGame2D.board_utd);
    ulFree(vsploadGame2D.board_tex);
    ulFree(vsploadGame2D.ayboard_utd);
}

void sploadFreeGameEtc(void) {
    tmetcEnd();
    ulFree(vsploadGameEtc.link);
    ulFree(vsploadGameEtc.vib_link[0]);
    ulFree(vsploadGameEtc.vib_link[1]);
}

void sploadFreeCharacter() {
    signed int jj; // r16
    signed int ii; // r17
    
    for (ii = 0; ii < vspenvGame->mode.num_player; ii++) {
        if (vsploadCharacter.model[ii].link != 0) {
            ulFree(vsploadCharacter.model[ii].link);
            maMdlMotionInitEnd(&vsploadCharacter.model[ii].seq->model_id);
            for (jj = 0; jj < 2; jj++) {
                ulFree(vsploadCharacter.model[ii].utd[jj].tex); // 914
                ulFree(vsploadCharacter.model[ii].utd[jj].frame); // 918
            }
        } else if (vsploadSystem.init_chr_no[ii] >= 0xC) {
            maCreateModelFree(vsploadCharacter.model[ii].vmd[0]); // 0x4
            maCreateModelFree(vsploadCharacter.model[ii].vmd[1]); // 0x8
            maMdlMotionInitEnd(vsploadCharacter.model[ii].seq);
            for (jj = 0; jj < 2; jj++) {
                ulFree(vsploadCharacter.model[ii].utd[jj].tex); // 914
                ulFree(vsploadCharacter.model[ii].utd[jj].frame); // 924
            }
        }
        maModelChangeInitEnd(vsploadCharacter.model[ii].change[0]); // 950
        maModelChangeInitEnd(vsploadCharacter.model[ii].change[1]); // 954
    }
    ulFree(vsploadCharacter.link);
    ulFree(vsploadEnvMap.utd);
    ulFree(vsploadEnvMap.tex);
}

void sploadFreeCourse(void) {
    tmcrsEnd();
    ulFree(vsploadCourse.base_link);
    ulFree(vsploadCourse.draw_link);
    ulFree(vsploadCourse.dfar_link);
    ulFree(vsploadCourse.dnear_link);
    ulFree(vsploadCourse.object);
    ulFree(vsploadCourse.event_umd[0x15]);
    ulFree(vsploadCourse.event_umd[0x17]);
    ulFree(vsploadCourse.event_umd[0x18]);
    ulFree(vsploadCourse.event_umd[0x19]);
    ulFree(vsploadCourse.event_umd[0x1A]);
    ulFree(vsploadCourse.event_umd[0x1B]);
    ulFree(vsploadCourse.event_umd[0x1C]);
    ulFree(vsploadCourse.event_umd[0x1D]);
    ulFree(vsploadCourse.event_umd[0x1E]);
}

void sploadLoadSCharacter(signed int chr_no) {

    /////////////////////////////
    // Expected variables:
    signed int kk; // r16
    signed int jj; // r17
    signed int ii; // r18
    // Size: 0x20, DWARF: 0xADD43
    ReadData read_data; // 0x40(r29)
    /////////////////////////////

    vsploadSystem.end = 0;

    for (ii = 0; ii < 0xC; ii++) {
        for (jj = 0; jj < 3; jj++) {
            vsploadSelect.character[ii][jj].link = 0;
            vsploadSelect.character[ii][jj].vmd[0] = 0;
            vsploadSelect.character[ii][jj].vmd[1] = 0;
            vsploadSelect.character[ii][jj].seq = 0;
            vsploadSelect.character[ii][jj].seq = 0;
            for (kk = 0; kk < 2; kk++) {
                vsploadSelect.character[ii][jj].utd[kk].utd = 0; // 970
                vsploadSelect.character[ii][jj].utd[kk].tex = 0; // 974
                vsploadSelect.character[ii][jj].utd[kk].frame = 0; // 978
            }
        }
    }
    read_data.addr = 0;
    read_data.tail = 1;
    read_data.id = 1;
    read_data.align = 0;
    read_data.ee_iop = 0;
    read_data.func = sploadGetAddr;
    for (ii = 0; ii < 3; ii++) {
        if (vspenvOption->cheats.metallic == 1) {
            read_data.no = ii + 0x2BD + ((short) chr_no * 3);
        } else {
            read_data.no = ii + 0x299 + ((short) chr_no * 3);
        }
        read_data.src[0] = (int)&vsploadSelect.character[chr_no][ii].link;
        read_data.src[1] = 0;
        read_data.src[2] = 0;
        uldvdReadData_DRIVE(&read_data);
    }
    uldvdStartReadData_DRIVE();
}

signed int sploadCheckSCharacter() {
    signed int ret = 0;
    if (vsploadSystem.end == 0) {
        ret = uldvdCheckFinish_DRIVE();
        if (ret == 0) {
            vsploadSystem.end = 1;
        }
    }
    return ret;
}

void sploadSetSCharacter(s32 chr_no) {
    // Size: 0x960, DWARF: 0xAC67F
    CharacterModel* model; // r16
    signed int jj; // r17
    signed int ii; // r18
    // Size: 0x8, DWARF: 0xAE2B3
    Data data; // 0x48(r29) // uses a magic number?

    // chr_no = chr_no; // 50
    for (ii = 0; ii < 3; ii++) {
        model = &vsploadSelect.character[chr_no][ii];
        ultexResetTex(vsploadSelect.offset);
        tmlinkMappingData((unsigned int)model->link, &data);
        model->vmd[0] = (unsigned char*)data.block[0].addr;
        model->utd[0].utd = (unsigned int*)data.block[2].addr;
        if (vspenvOption->cheats.metallic == 0) {
            model->utd[1].utd = (unsigned int*)data.block[3].addr;
        }
        for (jj = 0; jj < 2; jj++) {
            if (model->utd[jj].utd != 0) {
                model->utd[jj].offset = ultexGetOffset();
                model->utd[jj].ntex = ultexGetNTex(model->utd[jj].utd);
                model->utd[jj].block = ultexGetUseBlock(model->utd[jj].utd);
                model->utd[jj].frame = (unsigned int*)ulMalloc(ultexGetUseMemory(model->utd[jj].block), 0, 1);
                model->utd[jj].tex = (unsigned int*)ulMalloc(model->utd[jj].ntex * 0x10, 0, 0);
                ultexTransTex(model->utd[jj].utd, model->utd[jj].tex);
                ultexGetTex(model->utd[jj].frame, model->utd[jj].offset, model->utd[jj].block);
            }
        }
        ulvumdlInitModel(model->vmd[0], model->utd[0].tex, model->utd[1].tex);
        model->seq = (Seq*)maMdlMotionInit(vsploadSelect.select_uad, 0);
        maSecMotionInit(model->vmd[0], 0);
        model->change[0] = 0;
        model->change[0] = maModelChangeInit(model->vmd[0]);
        maModelChangeSet(model->change[0], 2);
    }
}

void sploadFreeSCharacter(signed int chr_no) {
    signed int ii; // r16

    for (ii = 0; ii < 3; ii++) {
        ulFree(vsploadSelect.character[chr_no][ii].link);
        vsploadSelect.character[chr_no][ii].link = 0;
        ulFree(vsploadSelect.character[chr_no][ii].utd[0].tex);
        vsploadSelect.character[chr_no][ii].utd[0].tex = 0;
        ulFree(vsploadSelect.character[chr_no][ii].utd[1].tex);
        vsploadSelect.character[chr_no][ii].utd[1].tex = 0;
        ulFree(vsploadSelect.character[chr_no][ii].utd[0].frame);
        vsploadSelect.character[chr_no][ii].utd[0].frame = 0;
        ulFree(vsploadSelect.character[chr_no][ii].utd[1].frame);
        vsploadSelect.character[chr_no][ii].utd[1].frame = 0;
        maMdlMotionInitEnd(vsploadSelect.character[chr_no][ii].seq);
        maModelChangeInitEnd(vsploadSelect.character[chr_no][ii].change[0]);
        vsploadSelect.character[chr_no][ii].change[0] = 0;
    }
}

void sploadSetCharacterTexture(signed int no) {
    signed int brd_no; // r16 // s0
    // Size: 0x18, DWARF: 0xAA4EF
    CreateCharacter* create; // r17 // s1
    signed int chr_no; // r18 // s2

    if ((s32)vspenvGame->character[no].no < 0xC) {
        if (vspenvGame->character[no].board == 6) {
            brd_no = 0x48;
            brd_no = 0x48;
        } else {
            brd_no = vspenvGame->character[no].board + (vspenvGame->character[no].no * 6);
        }
        ultexResetTex(vsploadCharacter.model[no].utd[0].offset);
        ultexTransTex(vsploadCharacter.model[no].utd[0].utd, vsploadCharacter.model[no].utd[0].tex);
        ultexTransTex(vsploadEnvMap.utd, vsploadEnvMap.tex);
        if (vspenvReplay[0]->cheats.metallic == 0) {
            sceGifPkInit(&vsploadLocalPacket, vsploadLocalAddr);
            sceGifPkReset(&vsploadLocalPacket);
            ultexTransTexTag(&vsploadLocalPacket, vsploadGame2D.ayboard_utd, vsploadCharacter.model[no].utd[0].tex + (ultexGetNTex(vsploadCharacter.model[no].utd[0].utd) - 1), brd_no);
            ulgifTermPacket(&vsploadLocalPacket);
            ulgifDmaSend(&vsploadLocalPacket);
            sceGsSyncPath(0, 0);
        }
        ultexGetTex(vsploadCharacter.model[no].utd[0].frame, vsploadCharacter.model[no].utd[0].offset, vsploadCharacter.model[no].utd[0].block);
        return;
    }
    chr_no = vspenvGame->character[no].no - 12;
    create = &vspenvReplay[no]->character;
    if (vspenvGame->character[no].board == 6) {
        brd_no = 0x48;
        brd_no = 0x48;
    } else {
        brd_no = vspenvGame->character[no].board + (create->board_type * 6);
    }
    if (vspenvReplay[0]->cheats.metallic == 0) {
        sceGifPkInit(&vsploadLocalPacket, vsploadLocalAddr);
        sceGifPkReset(&vsploadLocalPacket);
        ultexSetTexPath3(&vsploadLocalPacket, vsploadCharacter.model[no].utd[0].frame, vsploadCharacter.model[no].utd[0].offset, vsploadCharacter.model[no].utd[0].block);
        ultexTransTexTag(&vsploadLocalPacket, vsploadGame2D.ayboard_utd, vsploadCharacter.model[no].utd[0].tex, brd_no);
        brd_no = ulgifTermPacket(&vsploadLocalPacket);
        ulgifDmaSend(&vsploadLocalPacket);
        sceGsSyncPath(0, 0);
        ultexGetTex(vsploadCharacter.model[no].utd[0].frame, vsploadCharacter.model[no].utd[0].offset, vsploadCharacter.model[no].utd[0].block);
    }
}



VsploadReplayHead* sploadGetRapHead(void) {
    return &vsploadReplayHead;
}

VsploadIcon* sploadGetIconData(void) {
    return &vsploadIcon;
}

VsploadVibration* sploadGetVibrationData() {
    return &vsploadVibration;
}

VsploadMovie* sploadGetMovieData(void) {
    return &vsploadMovie;
}

VsploadSelect* sploadGetSelectData() {
    return &vsploadSelect;
}

VsploadGame2D* sploadGetGame2D() {
    return &vsploadGame2D;
}

VsploadGameEtc* sploadGetGameEtc() {
    return &vsploadGameEtc;
}

Cd* sploadGetCharacter() {
    return &vsploadCharacter;
}

signed int sploadGetCommonOffset() {
    return vsploadCommon.offset;
}
