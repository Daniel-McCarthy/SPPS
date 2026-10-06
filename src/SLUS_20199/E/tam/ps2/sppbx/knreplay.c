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

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Prevent calling fptosi on float to int conversions.

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

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);

// Static data ///////////////////////////////////////////////////////////////////////

// knreplay.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x1C0, DWARF: 0x16020C
typedef struct Camera
{
    signed short p_type[5]; // Offset: 0x0, DWARF: 0x160228
    signed short o_type[5]; // Offset: 0xA, DWARF: 0x16024D
    signed short p_num[5]; // Offset: 0x14, DWARF: 0x160272
    signed short o_num[5]; // Offset: 0x1E, DWARF: 0x160296
    signed short p_offs[5]; // Offset: 0x28, DWARF: 0x1602BA
    signed short o_offs[5]; // Offset: 0x32, DWARF: 0x1602DF
    signed short pad[2]; // Offset: 0x3C, DWARF: 0x160304
    float data[24][4]; // Offset: 0x40, DWARF: 0x160326
} Camera;

// Size: 0x50, DWARF: 0x15DA03
typedef struct CameraTransform
{
    sceVu0FVECTOR rot; // Offset: 0x0, DWARF: 0x15DA1E
    sceVu0FVECTOR trans; // Offset: 0x10, DWARF: 0x15DA40
    sceVu0FVECTOR obj; // Offset: 0x20, DWARF: 0x15DA64
    sceVu0FVECTOR aim; // Offset: 0x30, DWARF: 0x15DA86
    sceVu0FVECTOR up; // Offset: 0x40, DWARF: 0x15DAA8
} CameraTransform;

// Size: 0xC0, DWARF: 0x15CB8F
typedef struct VknReplay
{
    float old_pos[3][4]; // Offset: 0x0, DWARF: 0x15CBAA
    float old_obj[3][4]; // Offset: 0x30, DWARF: 0x15CBD0
    float dis[4]; // Offset: 0x60, DWARF: 0x15CBF6
    float shake[4]; // Offset: 0x70, DWARF: 0x15CC18
    // Size: 0x50, DWARF: 0x15DA03
    CameraTransform* core; // Offset: 0x80, DWARF: 0x15CC3C
    float wide; // Offset: 0x84, DWARF: 0x15CC62
    float t_cnt1; // Offset: 0x88, DWARF: 0x15CC83
    float t_cnt2; // Offset: 0x8C, DWARF: 0x15CCA6
    float shake_cnt; // Offset: 0x90, DWARF: 0x15CCC9
    float eff6; // Offset: 0x94, DWARF: 0x15CCEF
    signed short shake_flg; // Offset: 0x98, DWARF: 0x15CD10
    signed short t_flg1; // Offset: 0x9A, DWARF: 0x15CD36
    signed short t_flg2; // Offset: 0x9C, DWARF: 0x15CD59
    signed short now_cube; // Offset: 0x9E, DWARF: 0x15CD7C
    signed short now_block; // Offset: 0xA0, DWARF: 0x15CDA1
    signed short old_cube; // Offset: 0xA2, DWARF: 0x15CDC7
    signed short old_block; // Offset: 0xA4, DWARF: 0x15CDEC
    signed short effect; // Offset: 0xA6, DWARF: 0x15CE12
    signed short cam_cnt; // Offset: 0xA8, DWARF: 0x15CE35
    signed short cam_cnt2; // Offset: 0xAA, DWARF: 0x15CE59
    signed short blur; // Offset: 0xAC, DWARF: 0x15CE7E
    signed short hit; // Offset: 0xAE, DWARF: 0x15CE9F
    signed short eyes_flg; // Offset: 0xB0, DWARF: 0x15CEBF
    signed short event; // Offset: 0xB2, DWARF: 0x15CEE4
    signed short event_on; // Offset: 0xB4, DWARF: 0x15CF06
    signed short change; // Offset: 0xB6, DWARF: 0x15CF2B
    signed short def_cam; // Offset: 0xB8, DWARF: 0x15CF4E
    signed short tumble_flg; // Offset: 0xBA, DWARF: 0x15CF72
    signed short interpol; // Offset: 0xBC, DWARF: 0x15CF99
    signed short pad; // Offset: 0xBE, DWARF: 0x15CFBE
} VknReplay;

// Size: 0xA0, DWARF: 0x15A3DC
typedef struct VknIntro
{
    float p[4][4]; // Offset: 0x0, DWARF: 0x15A3F7
    float o[4][4]; // Offset: 0x40, DWARF: 0x15A417
    // Size: 0x50, DWARF: 0x15DA03
    CameraTransform* core; // Offset: 0x80, DWARF: 0x15A437
    float p_cnt; // Offset: 0x84, DWARF: 0x15A45D
    float o_cnt; // Offset: 0x88, DWARF: 0x15A47F
    float add_t; // Offset: 0x8C, DWARF: 0x15A4A1
    float add_a; // Offset: 0x90, DWARF: 0x15A4C3
    unsigned short cam_num; // Offset: 0x94, DWARF: 0x15A4E5
    unsigned short cut; // Offset: 0x96, DWARF: 0x15A509
    unsigned short cut_frame; // Offset: 0x98, DWARF: 0x15A529
    unsigned short frame; // Offset: 0x9A, DWARF: 0x15A54F
    unsigned short pad[2]; // Offset: 0x9C, DWARF: 0x15A571
} VknIntro;

// Size: 0x2B0, DWARF: 0x15E450
typedef struct VknIntro_Top
{
    char head[4]; // Offset: 0x0, DWARF: 0x15E46C
    signed short version; // Offset: 0x4, DWARF: 0x15E48F
    signed short pad[5]; // Offset: 0x6, DWARF: 0x15E4B3
    signed short p_type[8]; // Offset: 0x10, DWARF: 0x15E4D5
    signed short o_type[8]; // Offset: 0x20, DWARF: 0x15E4FA
    float p[5][4][4]; // Offset: 0x30, DWARF: 0x15E51F
    float o[5][4][4]; // Offset: 0x170, DWARF: 0x15E53F
} VknIntro_Top;

// Size: 0x4, DWARF: 0x160AA7
typedef struct Course
{
    signed int no; // Offset: 0x0, DWARF: 0x160AC3
} Course; 

// Size: 0x1C, DWARF: 0x15FB51
typedef struct CharacterParams
{
    signed int ollie; // Offset: 0x0, DWARF: 0x15FB6D
    signed int spin; // Offset: 0x4, DWARF: 0x15FB8F
    signed int speed; // Offset: 0x8, DWARF: 0x15FBB0
    signed int landing; // Offset: 0xC, DWARF: 0x15FBD2
    signed int balance; // Offset: 0x10, DWARF: 0x15FBF6
    signed int stability; // Offset: 0x14, DWARF: 0x15FC1A
    signed int stance; // Offset: 0x18, DWARF: 0x15FC40
} CharacterParams;

// Size: 0x10, DWARF: 0x16034D
typedef struct BoardParams
{
    signed int speed; // Offset: 0x0, DWARF: 0x160369
    signed int stability; // Offset: 0x4, DWARF: 0x16038B
    signed int balance; // Offset: 0x8, DWARF: 0x1603B1
    signed int turning; // Offset: 0xC, DWARF: 0x1603D5
} BoardParams;

// Size: 0x3C, DWARF: 0x160640
typedef struct CharacterConfiguration
{
    signed int no; // Offset: 0x0, DWARF: 0x16065C
    signed int player; // Offset: 0x4, DWARF: 0x16067B
    signed int wear; // Offset: 0x8, DWARF: 0x16069E
    signed int board; // Offset: 0xC, DWARF: 0x1606BF
    // Size: 0x1C, DWARF: 0x15FB51
    CharacterParams chr_param; // Offset: 0x10, DWARF: 0x1606E1
    // Size: 0x10, DWARF: 0x16034D
    BoardParams brd_param; // Offset: 0x2C, DWARF: 0x160709
} CharacterConfiguration;

// Size: 0x18, DWARF: 0x160E44
typedef struct GameMode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x160E60
    signed int game_mode; // Offset: 0x4, DWARF: 0x160E87
    signed int match_rule; // Offset: 0x8, DWARF: 0x160EAD
    signed int divide; // Offset: 0xC, DWARF: 0x160ED4
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x160EF7
} GameMode;

// Size: 0xA0, DWARF: 0x15FECB
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x160AA7
    Course course; // Offset: 0x0, DWARF: 0x15FEE7
    // Size: 0x3C, DWARF: 0x160640
    CharacterConfiguration character[2]; // Offset: 0x4, DWARF: 0x15FF0C
    // Size: 0x18, DWARF: 0x160E44
    GameMode mode; // Offset: 0x7C, DWARF: 0x15FF34
    signed int language; // Offset: 0x94, DWARF: 0x15FF57
    signed int ending; // Offset: 0x98, DWARF: 0x15FF7C
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x15FF9F
} VspenvGame;

// Size: 0x40, DWARF: 0x15FDA7
typedef struct VknEvent
{
    float obst_pos[3][4]; // Offset: 0x0, DWARF: 0x15FDC3
    signed int event_on[3]; // Offset: 0x30, DWARF: 0x15FDEA
    signed int pad; // Offset: 0x3C, DWARF: 0x15FE11
} VknEvent;

// Size: 0xB0, DWARF: 0x15DAF3
typedef struct CameraAttributes
{
    float c_ope[4][4]; // Offset: 0x0, DWARF: 0x15DB0E
    float o_ope[4][4]; // Offset: 0x40, DWARF: 0x15DB32
    float cam_dis[4]; // Offset: 0x80, DWARF: 0x15DB56
    float obj_dis[4]; // Offset: 0x90, DWARF: 0x15DB7C
    float vision; // Offset: 0xA0, DWARF: 0x15DBA2
    float scrz; // Offset: 0xA4, DWARF: 0x15DBC5
    signed char sub_type; // Offset: 0xA8, DWARF: 0x15DBE6
    signed char cam_type; // Offset: 0xA9, DWARF: 0x15DC0B
    signed char obj_type; // Offset: 0xAA, DWARF: 0x15DC30
    signed char attr; // Offset: 0xAB, DWARF: 0x15DC55
    signed char effect; // Offset: 0xAC, DWARF: 0x15DC76
    signed char hit; // Offset: 0xAD, DWARF: 0x15DC99
    signed char sub_type2; // Offset: 0xAE, DWARF: 0x15DCB9
    signed char event; // Offset: 0xAF, DWARF: 0x15DCDF
} CameraAttributes;

// Size: 0xF0, DWARF: 0x15CFE2
typedef struct VknBlock
{
    signed short x[15]; // Offset: 0x0, DWARF: 0x15CFFD
    signed short y[15]; // Offset: 0x1E, DWARF: 0x15D01D
    signed short num; // Offset: 0x3C, DWARF: 0x15D03D
    signed short pad; // Offset: 0x3E, DWARF: 0x15D05D
    // Size: 0xB0, DWARF: 0x15DAF3
    CameraAttributes cam; // Offset: 0x40, DWARF: 0x15D07D
} VknBlock;

// Size: 0x10, DWARF: 0x160D4D
typedef struct VknHead
{
    char head[4]; // Offset: 0x0, DWARF: 0x160D69
    signed short crs_no; // Offset: 0x4, DWARF: 0x160D8C
    signed short ccam_num; // Offset: 0x6, DWARF: 0x160DAF
    signed short bcam_num; // Offset: 0x8, DWARF: 0x160DD4
    signed short ecam_num; // Offset: 0xA, DWARF: 0x160DF9
    signed short pad[2]; // Offset: 0xC, DWARF: 0x160E1E
} VknHead;

// Size: 0xE0, DWARF: 0x15FCFA
typedef struct VknCube
{
    float trans[4]; // Offset: 0x0, DWARF: 0x15FD16
    float rot[4]; // Offset: 0x10, DWARF: 0x15FD3A
    float volume[4]; // Offset: 0x20, DWARF: 0x15FD5C
    // Size: 0xB0, DWARF: 0x15DAF3
    CameraAttributes cam; // Offset: 0x30, DWARF: 0x15FD81
} VknCube;

// Size: 0x30, DWARF: 0x15F369
typedef struct ScreenInfo
{
    float aspect_x; // Offset: 0x0, DWARF: 0x15F385
    float aspect_y; // Offset: 0x4, DWARF: 0x15F3AA
    float center_x; // Offset: 0x8, DWARF: 0x15F3CF
    float center_y; // Offset: 0xC, DWARF: 0x15F3F4
    float clip_vol_x; // Offset: 0x10, DWARF: 0x15F419
    float clip_vol_y; // Offset: 0x14, DWARF: 0x15F440
    float min_z; // Offset: 0x18, DWARF: 0x15F467
    float max_z; // Offset: 0x1C, DWARF: 0x15F489
    float near_z; // Offset: 0x20, DWARF: 0x15F4AB
    float far_z; // Offset: 0x24, DWARF: 0x15F4CE
    float screen_z; // Offset: 0x28, DWARF: 0x15F4F0
    float res; // Offset: 0x2C, DWARF: 0x15F515
} ScreenInfo;

// Size: 0x20, DWARF: 0x15F890
typedef struct Fog
{
    float min; // Offset: 0x0, DWARF: 0x15F8AC
    float max; // Offset: 0x4, DWARF: 0x15F8CC
    float far; // Offset: 0x8, DWARF: 0x15F8EC
    float near; // Offset: 0xC, DWARF: 0x15F90C
    signed int col[4]; // Offset: 0x10, DWARF: 0x15F92D
} Fog;

// Size: 0x140, DWARF: 0x15FFC6
typedef struct Matrix
{
    sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x15FFE2
    sceVu0FMATRIX local_light; // Offset: 0x40, DWARF: 0x16000D
    sceVu0FMATRIX light_color; // Offset: 0x80, DWARF: 0x160037
    sceVu0FMATRIX local_clip; // Offset: 0xC0, DWARF: 0x160061
    sceVu0FMATRIX clip_screen; // Offset: 0x100, DWARF: 0x16008A
} Matrix;

// Size: 0x340, DWARF: 0x15F953
typedef struct VspSystemMatrix
{
    // Size: 0x30, DWARF: 0x15F369
    ScreenInfo scr_info; // Offset: 0x0, DWARF: 0x15F96F
    // Size: 0x20, DWARF: 0x15F890
    Fog fog; // Offset: 0x30, DWARF: 0x15F996
    // Size: 0x140, DWARF: 0x15FFC6
    Matrix matrix; // Offset: 0x50, DWARF: 0x15F9B8
    sceVu0FMATRIX world_screen; // Offset: 0x190, DWARF: 0x15F9DD
    sceVu0FMATRIX world_view; // Offset: 0x1D0, DWARF: 0x15FA08
    sceVu0FMATRIX view_screen; // Offset: 0x210, DWARF: 0x15FA31
    sceVu0FMATRIX light_color; // Offset: 0x250, DWARF: 0x15FA5B
    sceVu0FMATRIX normal_light; // Offset: 0x290, DWARF: 0x15FA85
    sceVu0FMATRIX view_clip; // Offset: 0x2D0, DWARF: 0x15FAB0
    sceVu0FVECTOR cam_rot; // Offset: 0x310, DWARF: 0x15FAD8
    sceVu0FVECTOR cam_trans; // Offset: 0x320, DWARF: 0x15FAFE
    float view_angle; // Offset: 0x330, DWARF: 0x15FB26
} VspSystemMatrix;

// Size: 0x30, DWARF: 0x15E87E
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x15E89A
    signed int always_sp; // Offset: 0x4, DWARF: 0x15E8BB
    signed int perfect_b; // Offset: 0x8, DWARF: 0x15E8E1
    signed int super_spin; // Offset: 0xC, DWARF: 0x15E907
    signed int half_g; // Offset: 0x10, DWARF: 0x15E92E
    signed int fast_motion; // Offset: 0x14, DWARF: 0x15E951
    signed int super_speed; // Offset: 0x18, DWARF: 0x15E979
    signed int big_head; // Offset: 0x1C, DWARF: 0x15E9A1
    signed int metallic; // Offset: 0x20, DWARF: 0x15E9C6
    signed int mirror; // Offset: 0x24, DWARF: 0x15E9EB
    signed int replay_view; // Offset: 0x28, DWARF: 0x15EA0E
    signed int partition; // Offset: 0x2C, DWARF: 0x15EA36
} Cheats;

// Size: 0x24, DWARF: 0x15D0A3
typedef struct KeyConfig
{
    signed int vibration; // Offset: 0x0, DWARF: 0x15D0BE
    signed int spin_l; // Offset: 0x4, DWARF: 0x15D0E4
    signed int spin_r; // Offset: 0x8, DWARF: 0x15D107
    signed int stance; // Offset: 0xC, DWARF: 0x15D12A
    signed int revert; // Offset: 0x10, DWARF: 0x15D14D
    signed int grind; // Offset: 0x14, DWARF: 0x15D170
    signed int grab; // Offset: 0x18, DWARF: 0x15D192
    signed int jump; // Offset: 0x1C, DWARF: 0x15D1B3
    signed int flip; // Offset: 0x20, DWARF: 0x15D1D4
} KeyConfig;

// Size: 0x60, DWARF: 0x160B0C
typedef struct Pos
{
    sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x79DEF
    sceVu0FVECTOR cross; // Offset: 0x10, DWARF: 0x79E11
    sceVu0FVECTOR normal; // Offset: 0x20, DWARF: 0x79E35
    signed int hit; // Offset: 0x30, DWARF: 0x79E5A
    signed int material; // Offset: 0x34, DWARF: 0x79E7A
    signed int halfpipe; // Offset: 0x38, DWARF: 0x79E9F
    signed int ripping; // Offset: 0x3C, DWARF: 0x79EC4
    signed int bonk; // Offset: 0x40, DWARF: 0x79EE8
    signed int low_g; // Offset: 0x44, DWARF: 0x79F09
    signed int no; // Offset: 0x48, DWARF: 0x79F2B
    float len2; // Offset: 0x4C, DWARF: 0x79F4A
    signed int type; // Offset: 0x50, DWARF: 0x79F6B
    char padding[12]; // Not normally part of the struct, but pads a missing 8 bytes.
} Pos;

// Size: 0x8, DWARF: 0x15DE68
typedef struct Pad
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x168121
    signed char lh; // Offset: 0x2, DWARF: 0x168141
    signed char lv; // Offset: 0x3, DWARF: 0x168160
    signed int analog; // Offset: 0x4, DWARF: 0x16817F
} Pad;

// DWARF: 0x161774
typedef enum Sliding_State
{
    essSliding,
    essSitting,
    essStandUp,
    essOnAir,
    essManual,
    essGrind,
    essPlant,
    essRevert,
    essTumble
} Sliding_State;

// DWARF: 0x15A364
typedef enum Tumble_Type
{
    ettNormal,
    ettTotter,
    ettTumbleS,
    ettTumbleL,
    ettTumbleF,
    ettTumbleN
} Tumble_Type; // Offset: 0x2A0, DWARF: 0x168A79

// DWARF: 0x15E6FE
typedef enum Tumble_Way
{
    etwLeft,
    etwRight,
    etwFoward,
    etwBack
} Tumble_Way; // Offset: 0x2A4, DWARF: 0x168AA3

// DWARF: 0x15F669
typedef enum ESP_Spin_Way
{
    espNoSpin,
    espTurnLeft,
    espTurnRight,
    espTurnLeftFast,
    espTurnRightFast
} ESP_Spin_Way; // Offset: 0x18, DWARF: 0x16B1F5

// DWARF: 0x1600FD
typedef enum Acceleration_State
{
    easNormal,
    easAccel,
    easBrake,
    easBrakeTotter,
    easBrakeTumbleS,
    easBrakeTumbleL,
    easAccelLeft,
    easAccelRight,
    easSitAccel,
    easPlantAccel,
    easLowSpAccel,
    easBackAccel,
    easStartAccel,
    easBoostAccel
} Acceleration_State; // Offset: 0xC, DWARF: 0x16B176

// DWARF: 0x161C77
typedef enum Jump_State
{
    ejsSliding,
    ejsSitting,
    ejsStandUp,
    ejsOnAir,
    ejsJumpUpW,
    ejsJumpUpM,
    ejsJumpUpS,
    ejsJumpUpNollie,
    ejsJumpUpStart
} Jump_State; // Offset: 0x10, DWARF: 0x16B1A0

// DWARF: 0x15D9B2
typedef enum Stance_Change
{
    escNoAction,
    escTurnLeft,
    escTurnRight
} Stance_Change; // Offset: 0x14, DWARF: 0x16B1C9

// DWARF: 0x15E5F5
typedef enum Trick_Command
{
    ecmdNone,
    ecmdTrick,
    ecmdFlip,
    ecmdGrind,
    ecmdPlant,
    ecmdBonk,
    ecmdManual,
    ecmdRevert,
    ecmdHpCancel,
    ecmdTumble,
    ecmdEndFall
} Trick_Command; // Offset: 0x1C, DWARF: 0x16B21C

// DWARF: 0x1600B8
typedef enum Key_Way
{
    ekwNone,
    ekwLeft,
    ekwRight
} Key_Way; // Offset: 0x2C, DWARF: 0x16B2BC

// DWARF: 0x15EAAC
typedef enum Acceleration_Brake
{
    eraNone,
    eraAccel,
    eraBrake,
    eraAccelLeft,
    eraAccelRight
} Acceleration_Brake; // Offset: 0x0, DWARF: 0x16EEC0

// DWARF: 0x160A38
typedef enum Jump_Strength
{
    erjNone,
    erjWeak,
    erjMiddle,
    erjStrong,
    erjNollie,
    erjStart
} Jump_Strength; // Offset: 0x8, DWARF: 0x16EF0E

// DWARF: 0x15F5A8
typedef enum ERSC_Stance_Change
{
    erscNone,
    erscTurnLeft,
    erscTurnRight
} ERSC_Stance_Change; // Offset: 0xC, DWARF: 0x16EF31

// DWARF: 0x15FC67
typedef enum ERC_Command
{
    ercNone,
    ercTrick,
    ercFlip,
    ercGrind,
    ercPlant,
    ercBonk,
    ercManual,
    ercRevert,
    ercJump
} ERC_Command; // Offset: 0x10, DWARF: 0x16EF5D

// DWARF: 0x15E80D
typedef enum Landing_Bonus
{
    elbNormal,
    elbPerfect,
    elbSloppy
} Landing_Bonus; // Offset: 0x24, DWARF: 0x16CB5A

// DWARF: 0x15EB15
typedef enum ETS_Trick_State
{
    etsNormal,
    etsFlip,
    etsManual,
    etsGrind,
    etsPlant,
    etsRevert
} ETS_Trick_State; // Offset: 0x5D4, DWARF: 0x169BF9

// DWARF: 0x15F837
typedef enum Trick_Link_State
{
    elsNone,
    elsLinking,
    elsSuccess,
    elsFailure
} Trick_Link_State; // Offset: 0x5E0, DWARF: 0x169C72

// Size: 0x3C, DWARF: 0x15D71E
typedef struct Inp
{
    signed int turn; // Offset: 0x0, DWARF: 0x15D739
    signed int turn_x; // Offset: 0x4, DWARF: 0x15D75A
    signed int quick_turn; // Offset: 0x8, DWARF: 0x15D77D
    // DWARF: 0x1600FD
    Acceleration_State accel_state; // Offset: 0xC, DWARF: 0x15D7A4
    // DWARF: 0x161C77
    Jump_State jump_state; // Offset: 0x10, DWARF: 0x15D7CE
    // DWARF: 0x15D9B2
    Stance_Change stance_change; // Offset: 0x14, DWARF: 0x15D7F7
    // DWARF: 0x15F669
    ESP_Spin_Way spin_way; // Offset: 0x18, DWARF: 0x15D823
    // DWARF: 0x15E5F5
    Trick_Command command; // Offset: 0x1C, DWARF: 0x15D84A
    signed int cmd_mot_id; // Offset: 0x20, DWARF: 0x15D870
    signed int cmd_mot_nloop; // Offset: 0x24, DWARF: 0x15D897
    signed int cmd_trick_no; // Offset: 0x28, DWARF: 0x15D8C1
    // DWARF: 0x1600B8
    Key_Way keyway; // Offset: 0x2C, DWARF: 0x15D8EA
    signed int tumble_speed_up; // Offset: 0x30, DWARF: 0x15D90F
    signed int accel_speed; // Offset: 0x34, DWARF: 0x15D93B
    signed int stop_speed; // Offset: 0x38, DWARF: 0x15D963
} Inp;

// Size: 0x48, DWARF: 0x161838
typedef struct Req
{
    // DWARF: 0x15EAAC
    Acceleration_Brake accel_brake; // Offset: 0x0, DWARF: 0x161854
    signed int sitting; // Offset: 0x4, DWARF: 0x16187E
    // DWARF: 0x160A38
    Jump_Strength jump; // Offset: 0x8, DWARF: 0x1618A2
    // DWARF: 0x15F5A8
    ERSC_Stance_Change stance_change; // Offset: 0xC, DWARF: 0x1618C5
    // DWARF: 0x15FC67
    ERC_Command command; // Offset: 0x10, DWARF: 0x1618F1
    signed int cmd_mot_id; // Offset: 0x14, DWARF: 0x161917
    signed int cmd_mot_nloop; // Offset: 0x18, DWARF: 0x16193E
    signed int cmd_trick_no; // Offset: 0x1C, DWARF: 0x161968
    signed int end_fall; // Offset: 0x20, DWARF: 0x161991
    signed int trick_no; // Offset: 0x24, DWARF: 0x1619B6
    signed int flip_no; // Offset: 0x28, DWARF: 0x1619DB
    signed int grind_no; // Offset: 0x2C, DWARF: 0x1619FF
    signed int plant_no; // Offset: 0x30, DWARF: 0x161A24
    signed int bonk_no; // Offset: 0x34, DWARF: 0x161A49
    signed int manual_no; // Offset: 0x38, DWARF: 0x161A6D
    signed int revert_no; // Offset: 0x3C, DWARF: 0x161A93
    signed int jump_no; // Offset: 0x40, DWARF: 0x161AB9
    signed int sptrk_id; // Offset: 0x44, DWARF: 0x161ADD
} Req;

// Size: 0x30, DWARF: 0x1607C7
typedef struct Plane
{
    sceVu0FVECTOR cross; // Offset: 0x0, DWARF: 0x1607E3
    sceVu0FVECTOR normal; // Offset: 0x10, DWARF: 0x160807
    unsigned short material; // Offset: 0x20, DWARF: 0x16082C
    unsigned short attribute; // Offset: 0x22, DWARF: 0x160851
    signed short almighty1; // Offset: 0x24, DWARF: 0x160877
    signed short almighty2; // Offset: 0x26, DWARF: 0x16089D
    signed short almighty3; // Offset: 0x28, DWARF: 0x1608C3
    signed short slidable; // Offset: 0x2A, DWARF: 0x1608E9
    signed int available; // Offset: 0x2C, DWARF: 0x16090E
} Plane;

// Size: 0x1F0, DWARF: 0x161134
typedef struct Sbcore
{
    sceVu0FVECTOR nextpos; // Offset: 0x0, DWARF: 0x161150
    sceVu0FVECTOR speed; // Offset: 0x10, DWARF: 0x161176
    float rot_pole; // Offset: 0x20, DWARF: 0x16119A
    float max_relief_gap; // Offset: 0x24, DWARF: 0x1611BF
    signed int freefoot; // Offset: 0x28, DWARF: 0x1611EA
    float limit_ang_down; // Offset: 0x2C, DWARF: 0x16120F
    float limit_ang_up; // Offset: 0x30, DWARF: 0x16123A
    signed int set_sp_normal; // Offset: 0x34, DWARF: 0x161263
    sceVu0FVECTOR pos_head __attribute__((aligned(16))); // Offset: 0x40, DWARF: 0x16128D
    sceVu0FVECTOR pos_hip; // Offset: 0x50, DWARF: 0x1612B4
    signed int move_head; // Offset: 0x60, DWARF: 0x1612DA
    float ang_slidable_limit; // Offset: 0x64, DWARF: 0x161300
    sceVu0FVECTOR pos __attribute__((aligned(16))); // Offset: 0x70, DWARF: 0x16132F
    sceVu0FVECTOR pole; // Offset: 0x80, DWARF: 0x161351
    sceVu0FVECTOR sp_normal; // Offset: 0x90, DWARF: 0x161374
    signed int sliding; // Offset: 0xA0, DWARF: 0x16139C
    float relief_gap; // Offset: 0xA4, DWARF: 0x1613C0
    float touch_posy; // Offset: 0xA8, DWARF: 0x1613E7
    float const_max_relief_gap; // Offset: 0xAC, DWARF: 0x16140E
    float const_under_foot; // Offset: 0xB0, DWARF: 0x16143F
    signed int const_keep_normal; // Offset: 0xB4, DWARF: 0x16146C
    float height; // Offset: 0xB8, DWARF: 0x16149A
    signed int cnt_keep_normal; // Offset: 0xBC, DWARF: 0x1614BD
    signed int move; // Offset: 0xC0, DWARF: 0x1614E9
    // Size: 0x30, DWARF: 0x1607C7
    Plane plane_hit __attribute__((aligned(16))); // Offset: 0xD0, DWARF: 0x16150A
    // Size: 0x30, DWARF: 0x1607C7
    Plane plane_sliding; // Offset: 0x100, DWARF: 0x161532
    // Size: 0x30, DWARF: 0x1607C7
    Plane plane_beneath; // Offset: 0x130, DWARF: 0x16155E
    // Size: 0x30, DWARF: 0x1607C7
    Plane plane_body; // Offset: 0x160, DWARF: 0x16158A
    // Size: 0x30, DWARF: 0x1607C7
    Plane plane_hit_buff; // Offset: 0x190, DWARF: 0x1615B3
    // Size: 0x30, DWARF: 0x1607C7
    Plane plane_pre_hit; // Offset: 0x1C0, DWARF: 0x1615E0
} Sbcore;

// Size: 0x14, DWARF: 0x1616A0
typedef struct Balance
{
    float balance; // Offset: 0x0, DWARF: 0x1616BC
    float lean; // Offset: 0x4, DWARF: 0x1616E0
    float lean_dir; // Offset: 0x8, DWARF: 0x161701
    signed int released; // Offset: 0xC, DWARF: 0x161726
    signed int cnt_free; // Offset: 0x10, DWARF: 0x16174B
} Balance;

// Size: 0x24, DWARF: 0x15DD05
typedef struct RiderParams
{
    signed int ollie; // Offset: 0x0, DWARF: 0x15DD20
    signed int spin; // Offset: 0x4, DWARF: 0x15DD42
    signed int speed; // Offset: 0x8, DWARF: 0x15DD63
    signed int landing; // Offset: 0xC, DWARF: 0x15DD85
    signed int landing_switch; // Offset: 0x10, DWARF: 0x15DDA9
    signed int balance; // Offset: 0x14, DWARF: 0x15DDD4
    signed int quickness; // Offset: 0x18, DWARF: 0x15DDF8
    signed int power; // Offset: 0x1C, DWARF: 0x15DE1E
    signed int turning; // Offset: 0x20, DWARF: 0x15DE40
} RiderParams;

// Size: 0x98, DWARF: 0x15EBA9
typedef struct TrickLink
{
    signed int trick_link; // Offset: 0x0, DWARF: 0x15EBC5
    signed int trg_start_link; // Offset: 0x4, DWARF: 0x15EBEC
    signed int trg_end_link; // Offset: 0x8, DWARF: 0x15EC17
    signed int trg_get_pts; // Offset: 0xC, DWARF: 0x15EC40
    signed int spenv_get_trick_no; // Offset: 0x10, DWARF: 0x15EC68
    signed int pre_cnt_link; // Offset: 0x14, DWARF: 0x15EC97
    signed int cnt_link; // Offset: 0x18, DWARF: 0x15ECC0
    signed int cnt_trick; // Offset: 0x1C, DWARF: 0x15ECE5
    unsigned int last_point; // Offset: 0x20, DWARF: 0x15ED0B
    // DWARF: 0x15E80D
    Landing_Bonus is_bonus_landing; // Offset: 0x24, DWARF: 0x15ED32
    signed int is_bonus_switch; // Offset: 0x28, DWARF: 0x15ED61
    signed int is_bonus_spin; // Offset: 0x2C, DWARF: 0x15ED8D
    signed int is_bonus_airtime; // Offset: 0x30, DWARF: 0x15EDB7
    signed int set_top_cnt_link; // Offset: 0x34, DWARF: 0x15EDE4
    signed int added_nollie; // Offset: 0x38, DWARF: 0x15EE11
    signed int added_airtime; // Offset: 0x3C, DWARF: 0x15EE3A
    signed int trg_trick; // Offset: 0x40, DWARF: 0x15EE64
    unsigned int pts_current_trick; // Offset: 0x44, DWARF: 0x15EE8A
    unsigned int pts_current_hold; // Offset: 0x48, DWARF: 0x15EEB8
    unsigned int pts_current_spin; // Offset: 0x4C, DWARF: 0x15EEE5
    unsigned int pts_trick; // Offset: 0x50, DWARF: 0x15EF12
    unsigned int pts_gap; // Offset: 0x54, DWARF: 0x15EF38
    signed int cnt_total_hold; // Offset: 0x58, DWARF: 0x15EF5C
    signed int spin_ang; // Offset: 0x5C, DWARF: 0x15EF87
    signed int last_spin_ang; // Offset: 0x60, DWARF: 0x15EFAC
    signed int airtime_frame; // Offset: 0x64, DWARF: 0x15EFD6
    unsigned int current_set_tp; // Offset: 0x68, DWARF: 0x15F000
    unsigned int current_set_tp_rate; // Offset: 0x6C, DWARF: 0x15F02B
    signed int link_rate; // Offset: 0x70, DWARF: 0x15F05B
    unsigned int link_trick_point; // Offset: 0x74, DWARF: 0x15F081
    unsigned int total_trick_point; // Offset: 0x78, DWARF: 0x15F0AE
    unsigned int last_link_trick_point; // Offset: 0x7C, DWARF: 0x15F0DC
    unsigned int get_point; // Offset: 0x80, DWARF: 0x15F10E
    signed int total_trick_num; // Offset: 0x84, DWARF: 0x15F134
    signed int best_link_num; // Offset: 0x88, DWARF: 0x15F160
    unsigned int best_link_pts; // Offset: 0x8C, DWARF: 0x15F18A
    signed int get_the_best; // Offset: 0x90, DWARF: 0x15F1B4
    signed int pre_spin_ang; // Offset: 0x94, DWARF: 0x15F1DD
} TrickLink;

// Size: 0x60, DWARF: 0x160F6C
typedef struct Col
{
    sceVu0FVECTOR normal; // Offset: 0x0, DWARF: 0x160F88
    sceVu0FVECTOR point; // Offset: 0x10, DWARF: 0x160FAD
    sceVu0FVECTOR* vertex; // Offset: 0x20, DWARF: 0x160FD1
    unsigned int attr; // Offset: 0x24, DWARF: 0x160FF9
    signed int nvertex; // Offset: 0x28, DWARF: 0x16101A
    signed int no; // Offset: 0x2C, DWARF: 0x16103E
    float len; // Offset: 0x30, DWARF: 0x16105D
    signed int rail_no; // Offset: 0x34, DWARF: 0x16107D
    signed int obj_no; // Offset: 0x38, DWARF: 0x1610A1
    signed int obj_attr; // Offset: 0x3C, DWARF: 0x1610C4
    signed int obj_type; // Offset: 0x40, DWARF: 0x1610E9
    signed int res[4]; // Offset: 0x44, DWARF: 0x16110E
} Col;

// Size: 0x10, DWARF: 0x161DDF
typedef struct CommandTrick
{
    signed short type; // Offset: 0x0, DWARF: 0x161DFB
    char way1; // Offset: 0x2, DWARF: 0x161E1C
    char way2; // Offset: 0x3, DWARF: 0x161E3D
    char way3; // Offset: 0x4, DWARF: 0x161E5E
    char way4; // Offset: 0x5, DWARF: 0x161E7F
    unsigned short fin_button; // Offset: 0x6, DWARF: 0x161EA0
    char rev_button; // Offset: 0x8, DWARF: 0x161EC7
    char inp_fin_button; // Offset: 0x9, DWARF: 0x161EEE
    char left_count; // Offset: 0xA, DWARF: 0x161F19
    char fin_left_count; // Offset: 0xB, DWARF: 0x161F40
    char step; // Offset: 0xC, DWARF: 0x161F6B
    char ok; // Offset: 0xD, DWARF: 0x161F8C
    char passtime; // Offset: 0xE, DWARF: 0x161FAB
    char tmp; // Offset: 0xF, DWARF: 0x161FD0
} CommandTrick;

// Size: 0x2580, DWARF: 0x15A603
typedef struct Act
{
    // Size: 0x1F0, DWARF: 0x161134
    Sbcore sbcore; // Offset: 0x0, DWARF: 0x15A61E
    // Size: 0x30, DWARF: 0x1607C7
    Plane wall; // Offset: 0x1F0, DWARF: 0x15A643
    signed int cnt_freefoot; // Offset: 0x220, DWARF: 0x15A666
    signed int cnt_turn; // Offset: 0x224, DWARF: 0x15A68F
    signed int cnt_sitting; // Offset: 0x228, DWARF: 0x15A6B4
    signed int cnt_spinkey; // Offset: 0x22C, DWARF: 0x15A6DC
    signed int cnt_d2c; // Offset: 0x230, DWARF: 0x15A704
    signed int cnt_to_rail; // Offset: 0x234, DWARF: 0x15A728
    signed int cnt_grind; // Offset: 0x238, DWARF: 0x15A750
    signed int cnt_real_grind; // Offset: 0x23C, DWARF: 0x15A776
    signed int cnt_manual; // Offset: 0x240, DWARF: 0x15A7A1
    signed int cnt_total_grind; // Offset: 0x244, DWARF: 0x15A7C8
    signed int cnt_total_manual; // Offset: 0x248, DWARF: 0x15A7F4
    signed int cnt_plant; // Offset: 0x24C, DWARF: 0x15A821
    signed int cnt_holding; // Offset: 0x250, DWARF: 0x15A847
    signed int cnt_planttumble; // Offset: 0x254, DWARF: 0x15A86F
    signed int cnt_plant2grind; // Offset: 0x258, DWARF: 0x15A89B
    signed int cnt_tumble; // Offset: 0x25C, DWARF: 0x15A8C7
    signed int cnt_nospin; // Offset: 0x260, DWARF: 0x15A8EE
    signed int cnt_brake; // Offset: 0x264, DWARF: 0x15A915
    signed int cnt_backward; // Offset: 0x268, DWARF: 0x15A93B
    signed int cnt_no_bodyhit; // Offset: 0x26C, DWARF: 0x15A964
    signed int cnt_hokan; // Offset: 0x270, DWARF: 0x15A98F
    signed int jump_air; // Offset: 0x274, DWARF: 0x15A9B5
    signed int def_goofy; // Offset: 0x278, DWARF: 0x15A9DA
    signed int goofy; // Offset: 0x27C, DWARF: 0x15AA00
    signed int fakie; // Offset: 0x280, DWARF: 0x15AA22
    // DWARF: 0x161774
    Sliding_State sliding_state; // Offset: 0x284, DWARF: 0x15AA44
    // DWARF: 0x161774
    Sliding_State pre_state; // Offset: 0x288, DWARF: 0x15AA70
    signed int nollie; // Offset: 0x28C, DWARF: 0x15AA98
    signed int big_ollie; // Offset: 0x290, DWARF: 0x15AABB
    signed int super_ollie; // Offset: 0x294, DWARF: 0x15AAE1
    signed int plant_to_fakie; // Offset: 0x298, DWARF: 0x15AB09
    signed int trick_keep; // Offset: 0x29C, DWARF: 0x15AB34
    // DWARF: 0x15A364
    Tumble_Type tumble_type; // Offset: 0x2A0, DWARF: 0x15AB5B
    // DWARF: 0x15E6FE
    Tumble_Way tumble_way; // Offset: 0x2A4, DWARF: 0x15AB85
    signed int trg_hopup; // Offset: 0x2A8, DWARF: 0x15ABAE
    signed int trg_jumpup; // Offset: 0x2AC, DWARF: 0x15ABD4
    signed int trg_touch; // Offset: 0x2B0, DWARF: 0x15ABFB
    signed int trg_bonk; // Offset: 0x2B4, DWARF: 0x15AC21
    signed int trg_boost; // Offset: 0x2B8, DWARF: 0x15AC46
    signed int trg_rewind; // Offset: 0x2BC, DWARF: 0x15AC6C
    signed int trg_hit_wall; // Offset: 0x2C0, DWARF: 0x15AC93
    signed int no_approach_speed; // Offset: 0x2C4, DWARF: 0x15ACBC
    signed int hop_vertical_plane; // Offset: 0x2C8, DWARF: 0x15ACEA
    signed int touch_perfect; // Offset: 0x2CC, DWARF: 0x15AD19
    signed int grind_jump; // Offset: 0x2D0, DWARF: 0x15AD43
    signed int grind_tumble; // Offset: 0x2D4, DWARF: 0x15AD6A
    signed int hips; // Offset: 0x2D8, DWARF: 0x15AD93
    signed int trg_onair_with_over_hp; // Offset: 0x2DC, DWARF: 0x15ADB4
    // DWARF: 0x15A364
    Tumble_Type trg_tumble_type; // Offset: 0x2E0, DWARF: 0x15ADE7
    // DWARF: 0x15E6FE
    Tumble_Way trg_tumble_way; // Offset: 0x2E4, DWARF: 0x15AE15
    signed int trg_tumble_body; // Offset: 0x2E8, DWARF: 0x15AE42
    signed int end_grind; // Offset: 0x2EC, DWARF: 0x15AE6E
    signed int end_manual; // Offset: 0x2F0, DWARF: 0x15AE94
    signed int end_sliding; // Offset: 0x2F4, DWARF: 0x15AEBB
    float max_relief_gap; // Offset: 0x2F8, DWARF: 0x15AEE3
    float relief_gap; // Offset: 0x2FC, DWARF: 0x15AF0E
    float slant; // Offset: 0x300, DWARF: 0x15AF35
    float side_slant; // Offset: 0x304, DWARF: 0x15AF57
    float sp_slant; // Offset: 0x308, DWARF: 0x15AF7E
    float sp_side_slant; // Offset: 0x30C, DWARF: 0x15AFA3
    float ofs_updown; // Offset: 0x310, DWARF: 0x15AFCD
    float target_way; // Offset: 0x314, DWARF: 0x15AFF4
    sceVu0FVECTOR* pre_rail_list; // Offset: 0x318, DWARF: 0x15B01B
    sceVu0FVECTOR* rail_list; // Offset: 0x31C, DWARF: 0x15B04A
    signed int num_rail_vertex; // Offset: 0x320, DWARF: 0x15B075
    signed int rail_id; // Offset: 0x324, DWARF: 0x15B0A1
    signed int rail_no; // Offset: 0x328, DWARF: 0x15B0C5
    sceVu0FVECTOR rail_pos __attribute__((aligned(16))); // Offset: 0x330, DWARF: 0x15B0E9
    // Size: 0x14, DWARF: 0x1616A0
    Balance gr_balance; // Offset: 0x340, DWARF: 0x15B110
    float gr_enter_ang; // Offset: 0x354, DWARF: 0x15B139
    signed int gr_reset_lean; // Offset: 0x358, DWARF: 0x15B162
    signed int trg_grind_name; // Offset: 0x35C, DWARF: 0x15B18C
    signed int gr_grind_no; // Offset: 0x360, DWARF: 0x15B1B7
    signed int gr_cnt_kissed; // Offset: 0x364, DWARF: 0x15B1DF
    signed int gr_is_reverse; // Offset: 0x368, DWARF: 0x15B209
    signed int gr_back_accel; // Offset: 0x36C, DWARF: 0x15B233
    signed int trg_change_grind; // Offset: 0x370, DWARF: 0x15B25D
    signed int changed_grind; // Offset: 0x374, DWARF: 0x15B28A
    signed int disaster; // Offset: 0x378, DWARF: 0x15B2B4
    signed int first_grind; // Offset: 0x37C, DWARF: 0x15B2D9
    signed int gr_no_jump; // Offset: 0x380, DWARF: 0x15B301
    signed int hp_air; // Offset: 0x384, DWARF: 0x15B328
    signed int pre_hp_air; // Offset: 0x388, DWARF: 0x15B34B
    signed int halfpiping; // Offset: 0x38C, DWARF: 0x15B372
    signed int pre_halfpiping; // Offset: 0x390, DWARF: 0x15B399
    signed int over_hp; // Offset: 0x394, DWARF: 0x15B3C4
    signed int hp_jump; // Offset: 0x398, DWARF: 0x15B3E8
    signed int hp_adj_roty; // Offset: 0x39C, DWARF: 0x15B40C
    sceVu0FVECTOR hp_normal; // Offset: 0x3A0, DWARF: 0x15B434
    sceVu0FVECTOR hp_cross; // Offset: 0x3B0, DWARF: 0x15B45C
    signed int manual_ready; // Offset: 0x3C0, DWARF: 0x15B483
    signed int manual_ready_no; // Offset: 0x3C4, DWARF: 0x15B4AC
    signed int manual_cnt_to_play; // Offset: 0x3C8, DWARF: 0x15B4D8
    // Size: 0x14, DWARF: 0x1616A0
    Balance manu_balance; // Offset: 0x3CC, DWARF: 0x15B507
    signed int manu_reset_lean; // Offset: 0x3E0, DWARF: 0x15B532
    signed int bonk_ready; // Offset: 0x3E4, DWARF: 0x15B55E
    signed int bonk_ready_no; // Offset: 0x3E8, DWARF: 0x15B585
    signed int bonk_goto; // Offset: 0x3EC, DWARF: 0x15B5AF
    sceVu0FVECTOR bonk_point; // Offset: 0x3F0, DWARF: 0x15B5D5
    sceVu0FVECTOR bonk_presp; // Offset: 0x400, DWARF: 0x15B5FE
    signed int revert_cnt_ready; // Offset: 0x410, DWARF: 0x15B627
    signed int revert_ready_no; // Offset: 0x414, DWARF: 0x15B654
    signed int plant_air; // Offset: 0x418, DWARF: 0x15B680
    sceVu0FVECTOR plant_normal __attribute__((aligned(16))); // Offset: 0x420, DWARF: 0x15B6A6
    float max_height; // Offset: 0x430, DWARF: 0x15B6D1
    signed int big_air; // Offset: 0x434, DWARF: 0x15B6F8
    signed int cnt_onair; // Offset: 0x438, DWARF: 0x15B71C
    signed int cnt_onair2; // Offset: 0x43C, DWARF: 0x15B742
    signed int cnt_nothit; // Offset: 0x440, DWARF: 0x15B769
    signed int tumble_se_id; // Offset: 0x444, DWARF: 0x15B790
    float jump_rot_pole; // Offset: 0x448, DWARF: 0x15B7B9
    float last_rot_pole; // Offset: 0x44C, DWARF: 0x15B7E3
    // DWARF: 0x15F669
    ESP_Spin_Way last_spin_way; // Offset: 0x450, DWARF: 0x15B80D
    sceVu0FVECTOR pos_waist __attribute__((aligned(16))); // Offset: 0x460, DWARF: 0x15B839
    sceVu0FVECTOR pos_disp; // Offset: 0x470, DWARF: 0x15B861
    float shadow_posy; // Offset: 0x480, DWARF: 0x15B888
    float max_speed; // Offset: 0x484, DWARF: 0x15B8B0
    float cmn_max_speed; // Offset: 0x488, DWARF: 0x15B8D6
    float now_max_speed; // Offset: 0x48C, DWARF: 0x15B900
    // Size: 0x24, DWARF: 0x15DD05
    RiderParams param; // Offset: 0x490, DWARF: 0x15B92A
    // Size: 0x1C, DWARF: 0x15FB51
    CharacterParams chr_param_x10; // Offset: 0x4B4, DWARF: 0x15B94E
    // Size: 0x10, DWARF: 0x16034D
    BoardParams brd_param_x10; // Offset: 0x4D0, DWARF: 0x15B97A
    signed int mot_finish; // Offset: 0x4E0, DWARF: 0x15B9A6
    signed int mot_grabing; // Offset: 0x4E4, DWARF: 0x15B9CD
    signed int mot_flipping; // Offset: 0x4E8, DWARF: 0x15B9F5
    signed int mot_spflipping; // Offset: 0x4EC, DWARF: 0x15BA1E
    signed int mot_grinding; // Offset: 0x4F0, DWARF: 0x15BA49
    signed int mot_planting; // Offset: 0x4F4, DWARF: 0x15BA72
    signed int mot_manualing; // Offset: 0x4F8, DWARF: 0x15BA9B
    signed int mot_reverting; // Offset: 0x4FC, DWARF: 0x15BAC5
    signed int mot_bonking; // Offset: 0x500, DWARF: 0x15BAEF
    signed int mot_tumbling; // Offset: 0x504, DWARF: 0x15BB17
    signed int mot_reserve_tumble_standup; // Offset: 0x508, DWARF: 0x15BB40
    signed int mot_tumble_standup; // Offset: 0x50C, DWARF: 0x15BB77
    signed int mot_tumble_standup_already; // Offset: 0x510, DWARF: 0x15BBA6
    signed int mot_end_tumble; // Offset: 0x514, DWARF: 0x15BBDD
    float mot_flip_rot[4] __attribute__((aligned(16))); // Offset: 0x520, DWARF: 0x15BC08
    float mot_flip_roty_base; // Offset: 0x530, DWARF: 0x15BC33
    signed int mot_flip_mode; // Offset: 0x534, DWARF: 0x15BC62
    // Size: 0x98, DWARF: 0x15EBA9
    TrickLink trick_link; // Offset: 0x538, DWARF: 0x15BC8C
    signed int trk_doing; // Offset: 0x5D0, DWARF: 0x15BCB5
    // DWARF: 0x15EB15
    ETS_Trick_State trk_state; // Offset: 0x5D4, DWARF: 0x15BCDB
    signed int trk_grab_no; // Offset: 0x5D8, DWARF: 0x15BD03
    signed int trk_trick_no; // Offset: 0x5DC, DWARF: 0x15BD2B
    // DWARF: 0x15F837
    Trick_Link_State trk_link_state; // Offset: 0x5E0, DWARF: 0x15BD54
    signed int num_set_gap; // Offset: 0x5E4, DWARF: 0x15BD81
    signed short set_gap[64]; // Offset: 0x5E8, DWARF: 0x15BDA9
    signed int special_num; // Offset: 0x668, DWARF: 0x15BDCF
    signed int special_charge; // Offset: 0x66C, DWARF: 0x15BDF7
    signed int special_charge_cnt; // Offset: 0x670, DWARF: 0x15BE22
    signed int special_charge_maxcnt; // Offset: 0x674, DWARF: 0x15BE51
    signed int special_left_time; // Offset: 0x678, DWARF: 0x15BE83
    signed int special_total_time; // Offset: 0x67C, DWARF: 0x15BEB1
    signed int special_remainder_tp; // Offset: 0x680, DWARF: 0x15BEE0
    signed int boost; // Offset: 0x684, DWARF: 0x15BF11
    signed int boost_num; // Offset: 0x688, DWARF: 0x15BF33
    signed int boost_charge; // Offset: 0x68C, DWARF: 0x15BF59
    signed int boost_left_time; // Offset: 0x690, DWARF: 0x15BF82
    signed int boost_total_time; // Offset: 0x694, DWARF: 0x15BFAE
    signed int balance_cnt_adj; // Offset: 0x698, DWARF: 0x15BFDB
    float balance_ang_adj; // Offset: 0x69C, DWARF: 0x15C007
    float balance_roty_adj; // Offset: 0x6A0, DWARF: 0x15C033
    signed int balance_bigair; // Offset: 0x6A4, DWARF: 0x15C060
    float balance_pole[4] __attribute__((aligned(16))); // Offset: 0x6B0, DWARF: 0x15C08B
    float hang_rate; // Offset: 0x6C0, DWARF: 0x15C0B6
    signed int num_hit; // Offset: 0x6C4, DWARF: 0x15C0DC
    signed int num_vec; // Offset: 0x6C8, DWARF: 0x15C100
    signed int num_obj; // Offset: 0x6CC, DWARF: 0x15C124
    // Size: 0x60, DWARF: 0x160F6C
    Col col_hit[16]; // Offset: 0x6D0, DWARF: 0x15C148
    // Size: 0x60, DWARF: 0x160F6C
    Col col_vec[16]; // Offset: 0xCD0, DWARF: 0x15C16E
    // Size: 0x60, DWARF: 0x160F6C
    Col col_obj[16]; // Offset: 0x12D0, DWARF: 0x15C194
    signed int reserve_tumble; // Offset: 0x18D0, DWARF: 0x15C1BA
    float reserve_tumble_ang; // Offset: 0x18D4, DWARF: 0x15C1E5
    float reserve_tumble_speed; // Offset: 0x18D8, DWARF: 0x15C214
    // DWARF: 0x15A364
    Tumble_Type reserve_tumble_type; // Offset: 0x18DC, DWARF: 0x15C245
    signed int reserve_trick_no[16]; // Offset: 0x18E0, DWARF: 0x15C277
    signed int reserve_trick_is_flip[16]; // Offset: 0x1920, DWARF: 0x15C2A6
    signed int reserve_trick_is_special[16]; // Offset: 0x1960, DWARF: 0x15C2DA
    signed int num_reserve_trick; // Offset: 0x19A0, DWARF: 0x15C311
    signed int top_reserve_trick; // Offset: 0x19A4, DWARF: 0x15C33F
    signed int reserve_stance_change; // Offset: 0x19A8, DWARF: 0x15C36D
    signed int num_reserve_grab; // Offset: 0x19AC, DWARF: 0x15C39F
    unsigned char num_play_trick[2][160]; // Offset: 0x19B0, DWARF: 0x15C3CC
    unsigned char num_play_trick_in_link[2][160]; // Offset: 0x1AF0, DWARF: 0x15C3F9
    float mat_head[4][4]; // Offset: 0x1C30, DWARF: 0x15C42E
    float mat_hip[4][4]; // Offset: 0x1C70, DWARF: 0x15C455
    // Size: 0x60, DWARF: 0x160F6C
    Col col_rail; // Offset: 0x1CB0, DWARF: 0x15C47B
    // Size: 0x60, DWARF: 0x160F6C
    Col col_plant; // Offset: 0x1D10, DWARF: 0x15C4A2
    // Size: 0x60, DWARF: 0x160F6C
    Col col_hp; // Offset: 0x1D70, DWARF: 0x15C4CA
    // Size: 0x60, DWARF: 0x160F6C
    Col col_zhp; // Offset: 0x1DD0, DWARF: 0x15C4EF
    float recover_pos[4]; // Offset: 0x1E30, DWARF: 0x15C515
    float recover_roty; // Offset: 0x1E40, DWARF: 0x15C53F
    float recover_speed; // Offset: 0x1E44, DWARF: 0x15C568
    signed int recover; // Offset: 0x1E48, DWARF: 0x15C592
    signed int trg_recovered; // Offset: 0x1E4C, DWARF: 0x15C5B6
    signed int reserve_fall; // Offset: 0x1E50, DWARF: 0x15C5E0
    signed int cnt_fall; // Offset: 0x1E54, DWARF: 0x15C609
    signed int cnt_warp; // Offset: 0x1E58, DWARF: 0x15C62E
    signed int water_manual; // Offset: 0x1E5C, DWARF: 0x15C653
    signed int sptrk[2]; // Offset: 0x1E60, DWARF: 0x15C67C
    signed int num_total_gap; // Offset: 0x1E68, DWARF: 0x15C6A0
    signed int num_total_break; // Offset: 0x1E6C, DWARF: 0x15C6CA
    signed int reserve_quit; // Offset: 0x1E70, DWARF: 0x15C6F6
    signed int allow_tlink; // Offset: 0x1E74, DWARF: 0x15C71F
    signed int no_trick; // Offset: 0x1E78, DWARF: 0x15C747
    signed int trg_quit; // Offset: 0x1E7C, DWARF: 0x15C76C
    signed int cnt_quit; // Offset: 0x1E80, DWARF: 0x15C791
    signed int cnt_reserve_quit; // Offset: 0x1E84, DWARF: 0x15C7B6
    signed int pass_finish_line; // Offset: 0x1E88, DWARF: 0x15C7E3
    signed int pass_finish_line2; // Offset: 0x1E8C, DWARF: 0x15C810
    signed int wait_motion; // Offset: 0x1E90, DWARF: 0x15C83E
    signed int wait_vs; // Offset: 0x1E94, DWARF: 0x15C866
    signed int noheight_reflect; // Offset: 0x1E98, DWARF: 0x15C88A
    signed int cnt_noheight_reflect; // Offset: 0x1E9C, DWARF: 0x15C8B7
    signed int cnt_brank_noheight_reflect; // Offset: 0x1EA0, DWARF: 0x15C8E8
    signed int forced_bailout; // Offset: 0x1EA4, DWARF: 0x15C91F
    signed int cnt_hit_wall; // Offset: 0x1EA8, DWARF: 0x15C94A
    signed int cnt_brank_hit_wall; // Offset: 0x1EAC, DWARF: 0x15C973
    signed int cnt_forced_bailout; // Offset: 0x1EB0, DWARF: 0x15C9A2
    float last_hit_plane[10][4] __attribute__((aligned(16))); // Offset: 0x1EC0, DWARF: 0x15C9D1
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_trick[25]; // Offset: 0x1F60, DWARF: 0x15C9FE
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_flip[25]; // Offset: 0x20F0, DWARF: 0x15CA26
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_grind[13]; // Offset: 0x2280, DWARF: 0x15CA4D
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_plant[9]; // Offset: 0x2350, DWARF: 0x15CA75
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_bonk[9]; // Offset: 0x23E0, DWARF: 0x15CA9D
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_manual[9]; // Offset: 0x2470, DWARF: 0x15CAC4
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_jump[4]; // Offset: 0x2500, DWARF: 0x15CAED
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_sptrk[2]; // Offset: 0x2540, DWARF: 0x15CB14
    // Size: 0x10, DWARF: 0x161DDF
    CommandTrick cmd_revert[2]; // Offset: 0x2560, DWARF: 0x15CB3C
} Act;

// Size: 0x2C, DWARF: 0x160445
typedef struct MotFrames
{
    signed int id; // Offset: 0x0, DWARF: 0x160461
    signed int uad; // Offset: 0x4, DWARF: 0x160480
    signed int num_frame; // Offset: 0x8, DWARF: 0x1604A0
    signed int frame; // Offset: 0xC, DWARF: 0x1604C6
    signed int target_frame; // Offset: 0x10, DWARF: 0x1604E8
    signed int nloop; // Offset: 0x14, DWARF: 0x160511
    signed int inter_frame; // Offset: 0x18, DWARF: 0x160533
    signed int inter_count; // Offset: 0x1C, DWARF: 0x16055B
    signed int brend; // Offset: 0x20, DWARF: 0x160583
    float adj_rot; // Offset: 0x24, DWARF: 0x1605A5
    signed int cannot_control; // Offset: 0x28, DWARF: 0x1605C9
} MotFrames;

// Size: 0x20, DWARF: 0x160CC9
typedef struct KeyList
{
    float rot[4]; // Offset: 0x0, DWARF: 0x160CE5
    signed int frame; // Offset: 0x10, DWARF: 0x160D07
    signed int pad; // Offset: 0x14, DWARF: 0x160D29
} KeyList;

// DWARF: 0x161610
typedef enum FlipMode
{
    eflReady,
    eflFlipping,
    eflEnd
} FlipMode;

// Size: 0x50, DWARF: 0x161B52
typedef struct Flip
{
    // Size: 0x20, DWARF: 0x160CC9
    KeyList* key_list; // Offset: 0x0, DWARF: 0x161B6E
    // Size: 0x20, DWARF: 0x160CC9
    KeyList now; // Offset: 0x10, DWARF: 0x161B98
    signed int num_key; // Offset: 0x30, DWARF: 0x161BBA
    signed int num_frame; // Offset: 0x34, DWARF: 0x161BDE
    // DWARF: 0x161610
    FlipMode flipmode; // Offset: 0x38, DWARF: 0x161C04
    signed int mot_id; // Offset: 0x3C, DWARF: 0x161C2B
    signed int play_mot; // Offset: 0x40, DWARF: 0x161C4E
    int padding[7]; // Not originally in struct
} Flip __attribute__((aligned (16)));

// Size: 0x190, DWARF: 0x16201A
typedef struct Mot
{
    // Size: 0x2C, DWARF: 0x160445
    MotFrames now; // Offset: 0x0, DWARF: 0x162036
    // Size: 0x2C, DWARF: 0x160445
    MotFrames next; // Offset: 0x2C, DWARF: 0x162058
    // Size: 0x2C, DWARF: 0x160445
    MotFrames pre; // Offset: 0x58, DWARF: 0x16207B
    // Size: 0x2C, DWARF: 0x160445
    MotFrames pre2; // Offset: 0x84, DWARF: 0x16209D
    // Size: 0x2C, DWARF: 0x160445
    MotFrames now2; // Offset: 0xB0, DWARF: 0x1620C0
    // Size: 0x2C, DWARF: 0x160445
    MotFrames next2; // Offset: 0xDC, DWARF: 0x1620E3
    // Size: 0x50, DWARF: 0x161B52
    Flip flip; // Offset: 0x110, DWARF: 0x162107
    signed int cnt_ik_foot __attribute__((aligned(16))); // Offset: 0x160, DWARF: 0x16212A
    signed int freemotion; // Offset: 0x164, DWARF: 0x162152
    signed int ik; // Offset: 0x168, DWARF: 0x162179
    signed int reserve_schange; // Offset: 0x16C, DWARF: 0x162198
    signed int reserve_brending_schange; // Offset: 0x170, DWARF: 0x1621C4
    signed int motion_speed; // Offset: 0x174, DWARF: 0x1621F9
    signed int mot_sp_flip; // Offset: 0x178, DWARF: 0x162222
    signed int trg_to_calc_flip; // Offset: 0x17C, DWARF: 0x16224A
    signed int to_calc_flip; // Offset: 0x180, DWARF: 0x162277
} Mot;

// DWARF: 0x15A597
typedef enum Ripside
{
    ersNoRip,
    ersLeft,
    ersRight
} Ripside;

// Size: 0x190, DWARF: 0x15DF09
typedef struct Cam
{
    float pre_speed[4]; // Offset: 0x0, DWARF: 0x15DF25
    float now_speed[4]; // Offset: 0x10, DWARF: 0x15DF4D
    float normal_speed[4]; // Offset: 0x20, DWARF: 0x15DF75
    float rot[4]; // Offset: 0x30, DWARF: 0x15DFA0
    float pos_waist[4]; // Offset: 0x40, DWARF: 0x15DFC2
    float pos_disp[4]; // Offset: 0x50, DWARF: 0x15DFEA
    // Size: 0x60, DWARF: 0x160B0C
    Pos pos; // Offset: 0x60, DWARF: 0x15E011
    // Size: 0x60, DWARF: 0x160B0C
    Pos prepos; // Offset: 0xC0, DWARF: 0x15E033
    // DWARF: 0x15A597
    Ripside ripside; // Offset: 0x120, DWARF: 0x15E058
    // DWARF: 0x161774
    Sliding_State sliding_state; // Offset: 0x124, DWARF: 0x15E07E
    // DWARF: 0x161774
    Sliding_State pre_state; // Offset: 0x128, DWARF: 0x15E0AA
    // DWARF: 0x161774
    Sliding_State pre_tumble_state; // Offset: 0x12C, DWARF: 0x15E0D2
    float max_height; // Offset: 0x130, DWARF: 0x15E101
    signed int cnt_onair; // Offset: 0x134, DWARF: 0x15E128
    signed int cnt_turn; // Offset: 0x138, DWARF: 0x15E14E
    float max_speed; // Offset: 0x13C, DWARF: 0x15E173
    signed int hp_air; // Offset: 0x140, DWARF: 0x15E199
    float splen_prejump; // Offset: 0x144, DWARF: 0x15E1BC
    // DWARF: 0x15A364
    Tumble_Type tumble_type; // Offset: 0x148, DWARF: 0x15E1E6
    // DWARF: 0x15E6FE
    Tumble_Way tumble_way; // Offset: 0x14C, DWARF: 0x15E210
    // DWARF: 0x15A364
    Tumble_Type trg_tumble_type; // Offset: 0x150, DWARF: 0x15E239
    signed int trg_tumble_standup; // Offset: 0x154, DWARF: 0x15E267
    float grind_enter_ang; // Offset: 0x158, DWARF: 0x15E296
    signed int trick_link; // Offset: 0x15C, DWARF: 0x15E2C2
    signed int trg_start_endmot; // Offset: 0x160, DWARF: 0x15E2E9
    signed int trg_recovered; // Offset: 0x164, DWARF: 0x15E316
    signed int trg_hopup; // Offset: 0x168, DWARF: 0x15E340
    signed int trg_jumpup; // Offset: 0x16C, DWARF: 0x15E366
    signed int trg_touch; // Offset: 0x170, DWARF: 0x15E38D
    signed int trg_boost; // Offset: 0x174, DWARF: 0x15E3B3
    signed int bonk_goto; // Offset: 0x178, DWARF: 0x15E3D9
    signed int trg_plant; // Offset: 0x17C, DWARF: 0x15E3FF
    signed int grind_goto; // Offset: 0x180, DWARF: 0x15E425
} Cam;

// Size: 0x14, DWARF: 0x15F708
typedef struct Se
{
    float splen; // Offset: 0x0, DWARF: 0x15F724
    float rot_pole; // Offset: 0x4, DWARF: 0x15F746
    float anggap_sp_brd; // Offset: 0x8, DWARF: 0x15F76B
    float anggap_board_rot; // Offset: 0xC, DWARF: 0x15F795
    signed int side_slide; // Offset: 0x10, DWARF: 0x15F7C2
} Se;

// Size: 0x2C00, DWARF: 0x15D1F9
typedef struct Ctrl
{
    float rot[4]; // Offset: 0x0, DWARF: 0x15D214
    float speed[4]; // Offset: 0x10, DWARF: 0x15D236
    float pole[4]; // Offset: 0x20, DWARF: 0x15D25A
    float nor_pole[4]; // Offset: 0x30, DWARF: 0x15D27D
    float disp_pole[4]; // Offset: 0x40, DWARF: 0x15D2A4
    float rot_pole; // Offset: 0x50, DWARF: 0x15D2CC
    float disp_rot_pole; // Offset: 0x54, DWARF: 0x15D2F1
    float disp_rot_foot; // Offset: 0x58, DWARF: 0x15D31B
    signed int disp_rot_foot_is_x; // Offset: 0x5C, DWARF: 0x15D345
    float disp_pos[4]; // Offset: 0x60, DWARF: 0x15D374
    float disp_pos_ofs[4]; // Offset: 0x70, DWARF: 0x15D39B
    float disp_rot_z_ofs; // Offset: 0x80, DWARF: 0x15D3C6
    float slant_pole; // Offset: 0x84, DWARF: 0x15D3F1
    float splen; // Offset: 0x88, DWARF: 0x15D418
    float splenxz; // Offset: 0x8C, DWARF: 0x15D43A
    // Size: 0x60, DWARF: 0x160B0C
    Pos prepos2 __attribute__((aligned (16))); // Offset: 0x90, DWARF: 0x15D45E
    // Size: 0x60, DWARF: 0x160B0C
    Pos prepos __attribute__((aligned (16))); // Offset: 0xF0, DWARF: 0x15D484
    // Size: 0x60, DWARF: 0x160B0C
    Pos nowpos __attribute__((aligned (16))); // Offset: 0x150, DWARF: 0x15D4A9
    // Size: 0x60, DWARF: 0x160B0C
    Pos nextpos __attribute__((aligned (16))); // Offset: 0x1B0, DWARF: 0x15D4CE
    // Size: 0x8, DWARF: 0x15DE68
    Pad nowpad __attribute__((aligned (16))); // Offset: 0x210, DWARF: 0x15D4F4
    // Size: 0x8, DWARF: 0x15DE68
    Pad prepad; // Offset: 0x218, DWARF: 0x15D519
    // Size: 0x3C, DWARF: 0x15D71E
    Inp nowinp; // Offset: 0x220, DWARF: 0x15D53E
    // Size: 0x3C, DWARF: 0x15D71E
    Inp preinp; // Offset: 0x25C, DWARF: 0x15D563
    // Size: 0x48, DWARF: 0x161838
    Req nowreq; // Offset: 0x298, DWARF: 0x15D588
    // Size: 0x48, DWARF: 0x161838
    Req prereq; // Offset: 0x2E0, DWARF: 0x15D5AD
    // Size: 0x2580, DWARF: 0x15A603
    Act act; // Offset: 0x330, DWARF: 0x15D5D2
    // Size: 0x190, DWARF: 0x16201A
    Mot mot; // Offset: 0x28B0, DWARF: 0x15D5F4
    // Size: 0x190, DWARF: 0x15DF09
    Cam cam; // Offset: 0x2A40, DWARF: 0x15D616
    // Size: 0x14, DWARF: 0x15F708
    Se se __attribute__((aligned(16))); // Offset: 0x2BD0, DWARF: 0x15D638
    // Size: 0x3C, DWARF: 0x160640
    CharacterConfiguration* param; // Offset: 0x2BE4, DWARF: 0x15D659
    // Size: 0x24, DWARF: 0x15D0A3
    KeyConfig* key; // Offset: 0x2BE8, DWARF: 0x15D680
    // Size: 0x30, DWARF: 0x15E87E
    Cheats* cheats; // Offset: 0x2BEC, DWARF: 0x15D6A5
    // Size: 0x340, DWARF: 0x15F953
    VspSystemMatrix* sys_mat; // Offset: 0x2BF0, DWARF: 0x15D6CD
} Ctrl;

// Same as VsploadGameEtc from SpLoad.c, referenced by call to sploadGetGameEtc() in knIntroInit (Same as VsploadGameEtc)
// Size: 0x9C, DWARF: 0x15F20A
typedef struct VsploadGameEtc
{
    unsigned int* link; // Offset: 0x0, DWARF: 0x15F226
    unsigned char* replay_camera; // Offset: 0x4, DWARF: 0x15F24A
    unsigned char* intro_camera; // Offset: 0x8, DWARF: 0x15F277
    unsigned char* accelerate; // Offset: 0xC, DWARF: 0x15F2A3
    unsigned char* group; // Offset: 0x10, DWARF: 0x15F2CD
    unsigned int* vib_link[2]; // Offset: 0x14, DWARF: 0x15F2F2
    char* vib_com[16]; // Offset: 0x1C, DWARF: 0x15F319
    char* vib_evt[16]; // Offset: 0x5C, DWARF: 0x15F33F
} VsploadGameEtc;

//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0x1C0, DWARF: 0x16020C
static Camera vknIntro_ChrCamData = {
    { 3, 2, 1, 1, 1 },
    { 3, 0, 1, 1, 0 },
    { 4, 4, 2, 2, 2 },
    { 4, 1, 2, 2, 1 },
    { 0, 4, 8, 10, 12 },
    { 14, 18, 19, 21, 23 },
    { 0, 0 },
    {
        { 10.61f, -4.78f, -27.03f, 1.0f },
        { 4.91f, 1.52f, -21.63f, 1.0f },
        { -13.09f, 3.94f, -17.5f, 1.0f },
        { -22.67f, -4.78f, -13.34f, 1.0f },
        { -26.47f, -6.9f, 21.58f, 1.0f },
        { -35.81f, -11.69f, -10.95f, 1.0f },
        { -10.51f, -19.51f, -33.15f, 1.0f },
        { 7.34f, -28.52f, -28.04f, 1.0f },
        { 19.59f, -15.16f, -25.38f, 1.0f },
        { 19.61f, 3.12f, -27.85f, 1.0f },
        { -1.35f, -7.11f, -15.49f, 1.0f },
        { 0.06f, 1.57f, -36.73f, 1.0f },
        { 55.2f, -30.57f, 62.52f, 1.0f },
        { -60.57f, -32.07f, 65.78f, 1.0f },
        { 11.69f, -14.14f, 22.06f, 1.0f },
        { 5.96f, -15.54f, 25.34f, 1.0f },
        { 3.21f, -12.79f, 26.69f, 1.0f },
        { 6.42f, -11.07f, 26.81f, 1.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f },
        { -8.4f, 6.27f, 10.06f, 1.0f },
        { -5.84f, -10.62f, 12.38f, 1.0f },
        { -4.44f, -26.01f, 30.69f, 1.0f },
        { -3.02f, -17.32f, 9.45f, 1.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    }
}; // Address: 0x2CEE40
// Size: 0x50, DWARF: 0x15DA03
static CameraTransform vknMainData[2]; // Address: 0x3C6D60
// Size: 0xC0, DWARF: 0x15CB8F
static VknReplay vknReplay[2]; // Address: 0x3C6BE0
// Size: 0xA0, DWARF: 0x15A3DC
static VknIntro vknIntro[2]; // Address: 0x3C6AA0
// Size: 0x40, DWARF: 0x15FDA7
static VknEvent vknEvent; // Address: 0x3C6A60
// Size: 0xA0, DWARF: 0x15FECB
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x10, DWARF: 0x160D4D
static VknHead* vknHead; // Address: 0x2E7EBC
// Size: 0xE0, DWARF: 0x15FCFA
static VknCube* vknCube; // Address: 0x2E7EB8
// Size: 0xF0, DWARF: 0x15CFE2
static VknBlock* vknBlock; // Address: 0x2E7EB4
// Size: 0x2B0, DWARF: 0x15E450
static VknIntro_Top* vknIntro_Top; // Address: 0x2E7EB0
// Size: 0x340, DWARF: 0x15F953
extern VspSystemMatrix vspSystemMatrix[2]; // Address: 0x3BF6B0

//// Function Declarations ///////////////////////////////////////////////////////////

VsploadGameEtc* sploadGetGameEtc();
float cosf(float a);
float sinf(float a);
int rand(void);
void* memcpy(void* dst, const void* src, unsigned int len);
void* memset(void* dst, int c, unsigned int len);
void sceVu0ApplyMatrix(sceVu0FVECTOR a, sceVu0FMATRIX b, sceVu0FVECTOR c);
float sceVu0InnerProduct(sceVu0FVECTOR vec1, sceVu0FVECTOR vec2);
void sceVu0InterVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, float r);
void sceVu0InversMatrix(sceVu0FMATRIX a, sceVu0FMATRIX b);
void sceVu0MulVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2, sceVu0FVECTOR vec3);
void sceVu0Normalize(sceVu0FVECTOR a, sceVu0FVECTOR b);
void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR v);
void gmsysSetBlurPow(signed int pow);
void tmcrsGetArea(signed int* x, signed int* y, float* pos);
void knCoreSubVectorXYZ(float* out, float* v1, float* v2);
void knCoreBezier(float* V, float t, float* v0, float* v1, float* v2, float* v3);
void knCoreSpline1(float* V, float t, float* v0, float* v1, float* v2, float* v3);
void knCoreGetAngle(float* rot, float* trans, float* obj);
signed int knCoreGetBaseHit(Col* near_hit, float* pos1, float* pos2);
signed int knCoreGetCourseHit(Col* near_hit, float* pos1, float* pos2);
signed int knCoreGetHitHit(Col* near_hit, float* pos1, float* pos2);
void knCoreInitRand(signed int seed);
float knCoreRand();
void knCoreSetWState(CameraTransform* data, signed int num);
void knEventEnd();
signed int knEventGet();
static void knReplayGetLen(float* len, float* pos1, float* pos2);
void knIntroInit(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr);
signed int knIntroMain(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, unsigned int frame, signed int num);
static void knIntroSetData(// Size: 0xA0, DWARF: 0x15A3DC
VknIntro* it, signed int cam_num);
static void knIntroSetData2(// Size: 0xA0, DWARF: 0x15A3DC
VknIntro* it, // Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr);
static void knIntroRotCamera(float* point, float list1[4], float list2[4], float cnt);
void knReplayInit(Ctrl* ctrl);
signed int knReplayMain(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, signed int num, signed int unused1);
static signed int knReplayResetCheck(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
static signed int knReplayStatusCheck(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, signed short attr);
static signed int knReplayGetCube(float* pos, // Size: 0xE0, DWARF: 0x15FCFA
VknCube* box);
static signed int knReplayGetBlock(signed int bx, signed int by, // Size: 0xF0, DWARF: 0x15CFE2
VknBlock* block);
static void knReplayInterPol(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
void knReplaySetObstPos(float* pos, signed int flg, signed int id);
static void knReplayCtrlCameraMain(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data);
static void knReplayResetCamera(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data);
static void knReplayCtrlView(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data);
static void knReplayCtrlObj(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data);
static void knReplayCtrlEffect(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
static void knReplayCtrlEvent(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
static void knReplayTumbleSpecial(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
static void knReplayInitDefaultCamera(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
static void knReplayCtrlDefaultCamera(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
static void knReplayBlur(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep);
static void knReplayRelative(float* point, // Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, signed int type);
static void knReplayRotRelative(float* point, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, float* chr_pos, float* chr_rot);
static void knReplayPointToPoint(float* point, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, sceVu0FMATRIX ope, float* chr_pos, signed int type);
static void knReplayBetweenPoint(float* point, float* a, float* b, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, signed int type);
static void knReplayPointApproach(float* point, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, float* chr_pos);
static void knReplayCharForward(float* point, // Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, float* dis);
static void knReplayCharRotCamera(float* point, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, float* axis, float* chr_pos, float* dis);
static signed int knReplayAxisMove(float* point, sceVu0FMATRIX list, float* chr_pos);
static void knReplayFixRot(float* obj, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data);
static void knReplayCharFrameIn(float* obj, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, float* chr_pos, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, signed int type);
static void knReplayCameraShakeTYPE1(float* pos, float* p1, float* rot, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, float power, float rate);
static void knReplayCameraShakeTYPE2(float* pos, float* p1, float* rot, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, float power, float unused1);
static void knReplayAxisRotMatrix(sceVu0FMATRIX mat, float ang, float* axis);
static void knReplayGetLenScale(float* out, float* len, float dis);

//// Function Definitions ////////////////////////////////////////////////////////////


void knIntroInit(// Size: 0x2C00, DWARF: 0x15D1F9
    Ctrl* chr /* 0x30(r29) */) {
    signed int i; // r16
    // Size: 0x9C, DWARF: 0x15F20A
    VsploadGameEtc* addr = sploadGetGameEtc(); // r17 // Gets SpLoad's VsploadGameEtc

    vknIntro_Top = addr->intro_camera;
    for (i = 0; i < 2; i++) {
        memset(&vknIntro[i], 0, 0xA0);
        vknIntro[i].core = (void* ) (&vknMainData[i]);
        vknIntro[i].cut = 0xFFFF;
        sceVu0CopyVector(vknIntro[i].core->trans, chr->cam.pos_disp);
        vknIntro[i].core->up[0] = 0.0f;
        vknIntro[i].core->up[1] = 1.0f;
        vknIntro[i].core->up[2] = 0.0f;
        vknIntro[i].core->up[3] = 1.0f;
        vknIntro[i].core->aim[0] = 0.0f;
        vknIntro[i].core->aim[1] = 0.0f;
        vknIntro[i].core->aim[2] = 1.0f;
        vknIntro[i].core->aim[3] = 1.0f;
    }
}

signed int knIntroMain(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* 0x130(r29) */, unsigned int frame /* 0x140(r29) */, signed int num /* 0x150(r29) */) {
    static signed short cut_max[2] = { 10, 6 }; // 0x2E7878
    signed int cut; // r18
    signed int hit; // r23
    signed short p_type; // r20
    signed short o_type; // r21
    float sub[4]; // 0x90(r29)
    float vec[4]; // 0xA0(r29)
    float tmp1[4]; // 0xB0(r29)
    float tmp2[4]; // 0xC0(r29)
    // Size: 0xA0, DWARF: 0x15A3DC
    VknIntro* it; // r16
    signed short cut_frame; // r22
    // Size: 0x50, DWARF: 0x15DA03
    CameraTransform* core; // r17
    // Size: 0x60, DWARF: 0x160F6C
    Col cross; // 0xD0(r29)
    signed int num_p; // r19

    it = &vknIntro[num];
    core = it->core;
    num_p = vspenvGame->mode.num_player - 1;
    if ((frame % 120) == 0) {
        it->cut++;
        if (it->cut >= (cut_max[num_p] * 2)) {
            it->cut = 0;
        }
        cut_frame = 120;
        it->add_t = 1.0f / cut_frame;
        it->add_a = 3.1415927f / cut_frame;
        it->frame = 0;
    }
    if (frame >= 120.0f) {
        if (it->frame < 36.0f) {
            gmsysSetBlurPow((128.0f * (36.0f - it->frame)) / 36.0f);
        }
    }
    if ((it->cut % 2) == 0) {
        cut = (it->cut % cut_max[num_p]) >> 1;
        if (it->frame == 0) {
            knIntroSetData(it, cut);
        }
        p_type = vknIntro_Top->p_type[cut];
        o_type = vknIntro_Top->o_type[cut];
        core->up[0] = 0.0f;
        core->up[1] = 1.0f;
        core->up[2] = 0.0f;
        core->up[3] = 1.0f;
    } else {
        if (it->frame == 0) {
            it->cam_num = ((it->cut % cut_max[num_p]) - 1) >> 1;
            knIntroSetData2(it, chr);
        }
        p_type = vknIntro_ChrCamData.p_type[it->cam_num];
        o_type = vknIntro_ChrCamData.o_type[it->cam_num];
        sceVu0CopyVector(core->up, chr->disp_pole);
        sceVu0ScaleVector(core->up, core->up, -1.0f);
        core->up[3] = -1.0f;
    }
    switch (p_type) {
    case 0:
        sceVu0CopyVector(core->trans, it->p[0]);
        break;
    case 1:
        sceVu0InterVectorXYZ(core->trans, it->p[1], it->p[0], it->add_t * it->frame);
        break;
    case 2:
        knCoreSpline1(core->trans, it->p_cnt, it->p[0], it->p[1], it->p[2], it->p[3]);
        it->p_cnt += it->add_t;
        break;
    case 3:
        knCoreBezier(core->trans, it->p_cnt, it->p[0], it->p[1], it->p[2], it->p[3]);
        it->p_cnt += it->add_t;
        break;
    case 4:
        knIntroRotCamera(core->trans, it->p[0], it->o[0], it->p_cnt);
        it->p_cnt -= it->add_a;
        break;
    case 5:
        knIntroRotCamera(core->trans, it->p[0], it->o[0], it->p_cnt);
        it->p_cnt += it->add_a;
        break;
    case 6:
        knIntroRotCamera(core->trans, it->p[0], it->o[0], it->p_cnt);
        it->p_cnt -= it->add_a;
        knCoreSubVectorXYZ(vec, it->p[1], it->p[0]);
        sceVu0ScaleVectorXYZ(vec, vec, it->add_t * it->frame);
        core->trans[1] = it->p[0][1] + vec[1];
        break;
    case 7:
        knIntroRotCamera(core->trans, it->p[0], it->o[0], it->p_cnt);
        it->p_cnt += it->add_a;
        knCoreSubVectorXYZ(vec, it->p[1], it->p[0]);
        sceVu0ScaleVectorXYZ(vec, vec, it->add_t * it->frame);
        core->trans[1] = it->p[0][1] + vec[1];
        break;
    }
    knCoreSubVectorXYZ(sub, core->trans, it->p[0]);
    switch (o_type) {
    case 0:
        sceVu0CopyVector(core->obj, it->o[0]);
        break;
    case 1:
        sceVu0InterVectorXYZ(core->obj, it->o[1], it->o[0], it->add_t * it->frame);
        break;
    case 2:
        knCoreSpline1(core->obj, it->o_cnt, it->o[0], it->o[1], it->o[2], it->o[3]);
        it->o_cnt += it->add_t;
        break;
    case 3:
        knCoreBezier(core->obj, it->o_cnt, it->o[0], it->o[1], it->o[2], it->o[3]);
        it->o_cnt += it->add_t;
        break;
    case 4:
        knIntroRotCamera(core->obj, it->o[0], it->p[0], it->o_cnt);
        it->o_cnt += it->add_a;
        break;
    case 5:
        knIntroRotCamera(core->obj, it->o[0], it->p[0], it->o_cnt);
        it->o_cnt -= it->add_a;
        break;
    case 6:
        knIntroRotCamera(core->obj, it->o[0], it->p[0], it->o_cnt);
        it->o_cnt += it->add_a;
        knCoreSubVectorXYZ(vec, it->o[1], it->o[0]);
        sceVu0ScaleVectorXYZ(vec, vec, it->add_t * it->frame);
        core->obj[1] = it->o[0][1] + vec[1];
        break;
    case 7:
        knIntroRotCamera(core->obj, it->o[0], it->p[0], it->o_cnt);
        it->o_cnt -= it->add_a;
        knCoreSubVectorXYZ(vec, it->o[1], it->o[0]);
        sceVu0ScaleVectorXYZ(vec, vec, it->add_t * it->frame);
        core->obj[1] = it->o[0][1] + vec[1];
        break;
    case 8:
        knCoreAddVectorXYZ(core->obj, it->o[0], sub);
        break;
    }
    sceVu0CopyVector(tmp1, core->trans);
    sceVu0CopyVector(tmp2, core->trans);
    tmp1[1] -= 100.0f;
    tmp2[1] += 1000.0f;
    hit = knCoreGetCourseHit(&cross, tmp1, tmp2);
    if (hit && (it->cut % 2)) {
        if (core->trans[1] > (cross.point[1] - 3.0f)) {
            sceVu0CopyVector(core->trans, cross.point);
            core->trans[1] -= 3.0f;
        }
    }
    knCoreGetAngle(core->rot, core->trans, core->obj);
    core->rot[2] = 0.0f;
    knCoreSetWState(it->core, num);
    it->frame++;
    return it->cut;
}

asm void knCoreSubVectorXYZ(float* out, float* v1, float* v2) {
        lqc2 $vf3, 0x0($a1);
        lqc2 $vf4, 0x0($a2);
        vsub.xyz $vf5, $vf3, $vf4;
        vmove.w $vf5, $vf0;
        sqc2 $vf5, 0x0($a0);
        jr $ra;
        nop;
}

void knIntroSetData(// Size: 0xA0, DWARF: 0x15A3DC
VknIntro* it /* 0x30(r29) */, s32 cam_num /* 0x40(r29) */) {
    signed short p_type = vknIntro_Top->p_type[cam_num]; // r16
    signed short o_type = vknIntro_Top->o_type[cam_num]; // r17

    memcpy(it->p, vknIntro_Top->p[cam_num], 0x40);
    memcpy(it->o, vknIntro_Top->o[cam_num], 0x40);
    it->p_cnt = 0.0f;
    it->o_cnt = 0.0f;
}

void knIntroSetData2(// Size: 0xA0, DWARF: 0x15A3DC
VknIntro* it /* 0xD0(r29) */, // Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* 0xE0(r29) */) {
    signed int i; // r16
    // Size: 0x1C0, DWARF: 0x16020C
    Camera* cam = &vknIntro_ChrCamData; // r17
    signed short p_offs; // r18
    signed short o_offs; // r19
    signed short p_type = cam->p_type[it->cam_num]; // r20
    signed short o_type = cam->o_type[it->cam_num]; // r21
    float dis[4]; // 0x70(r29)
    float rot[4]; // 0x80(r29)
    float mat[4][4]; // 0x90(r29)

    sceVu0CopyVector(&rot, chr->cam.rot);
    rot[0] = -rot[0];
    knCoreRotMatrix(&mat, &rot);
    
    p_offs = cam->p_offs[it->cam_num];
    for (i = 0; i < cam->p_num[it->cam_num]; i++) {
        sceVu0CopyVector(&dis, &cam->data[p_offs + i]);
        sceVu0ApplyMatrix(&dis, &mat, &dis);
        knCoreAddVectorXYZ(it->p[i], chr->nowpos.pos, &dis);
    }
    
    o_offs = cam->o_offs[it->cam_num];
    for (i = 0; i < cam->o_num[it->cam_num]; i++) {
        sceVu0CopyVector(&dis, &cam->data[o_offs + i]);
        sceVu0ApplyMatrix(&dis, &mat, &dis);
        knCoreAddVectorXYZ(it->o[i], chr->nowpos.pos, &dis);
    }
    it->p_cnt = 0.0f;
    it->o_cnt = 0.0f;
}

static void knIntroRotCamera(float* point /* r18 */, float list1[4] /* r17 */, float list2[4] /* r16 */, float cnt) {
    static float axis[4] = { 0.0f, 1.0f, 0.0f, 1.0f }; // 0x2CF000
    float ang; // 0xA0(r29)
    float mat[4][4]; // 0x50(r29)
    float sub[4]; // 0x90(r29)
    float xz; // r1
    float sq_tmp; // 0xA0(r29)

    xz = 0.0f;
    knCoreSubVectorXYZ(sub, list2, list1);
    sq_tmp = atan2f(sub[2], sub[0]);
    if ((sq_tmp + cnt) > 3.1415927f) {
        sq_tmp = (sq_tmp + cnt) - 6.2831855f;
    } else if ((sq_tmp + cnt) < -3.1415927f) {
        sq_tmp = 6.2831855f + (sq_tmp + cnt);
    } else {
        sq_tmp = sq_tmp + cnt;
    }
    knReplayAxisRotMatrix(mat, sq_tmp, axis);
    sceVu0MulVector(sub, sub, sub);
    sq_tmp = sub[0] + sub[2];
    asm("sqrt.s xz, sq_tmp");
    sub[0] = 0.0f;
    sub[1] = 0.0f;
    sub[2] = xz;
    sub[3] = 1.0f;
    sceVu0ApplyMatrix(sub, mat, sub);
    knCoreAddVectorXYZ(point, list2, sub);
    point[1] = list1[1];
}

void knReplayInit(Ctrl* ctrl) {
    signed int i; // r16
    // Size: 0xC0, DWARF: 0x15CB8F
    VknReplay* rep = &vknReplay; // r17
    unsigned char* top; // r18
    // Size: 0x9C, DWARF: 0x15F20A
    VsploadGameEtc* addr = sploadGetGameEtc(); // r19

    top = addr->replay_camera;
    vknHead = top;
    top += 0x10;
    vknCube = top;
    top = &((VknCube*)top)[vknHead->ccam_num];
    vknBlock = top;
    for (i = 0; i < 2; i++) {
        memset(&rep[i], 0, 0xC0);
        rep[i].core = (void*)(&vknMainData[i]);
        rep[i].core->aim[0] = 0.0f;
        rep[i].core->aim[1] = 0.0f;
        rep[i].core->aim[2] = 1.0f;
        rep[i].core->aim[3] = 1.0f;
        rep[i].core->up[0] = 0.0f;
        rep[i].core->up[1] = 1.0f;
        rep[i].core->up[2] = 0.0f;
        rep[i].core->up[3] = 1.0f;
        rep[i].wide = 400.0f;
        rep[i].now_cube = rep[i].old_cube = rep[i].now_block = rep[i].old_block = rep[i].cam_cnt = rep[i].cam_cnt2 = -1;
        knCoreSetWState(rep[i].core, i);
    }
    memset(&vknEvent, 0, 0x40);
    knCoreInitRand(1);
    knEventEnd();
}

signed int knReplayMain(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* 0x140(r29) */, signed int num /* 0x150(r29) */, signed int unused1) {
    signed int i; // r17
    signed int check; // r18
    signed int bx; // 0x134(r29)
    signed int by; // 0x138(r29)
    signed int hit; // r20
    signed char event_num; // r22
    signed char now_group; // r23
    signed char old_group; // r30
    float random; // 0x13C(r29)
    float chr_pos[4]; // 0xA0(r29)
    float tmp[4]; // 0xB0(r29)
    float tmp2[4]; // 0xC0(r29)
    // Size: 0x60, DWARF: 0x160F6C
    Col cross; // 0xD0(r29)
    // Size: 0xC0, DWARF: 0x15CB8F
    VknReplay* rep; // r16
    // Size: 0x340, DWARF: 0x15F953
    VspSystemMatrix* mat; // r21
    // Size: 0x50, DWARF: 0x15DA03
    CameraTransform* core; // r19

    hit = 0;
    rep = &vknReplay[num];
    mat = &vspSystemMatrix[num];
    core = rep->core;
    if (knEventGet()) {
        return 1;
    }
    rep->wide = 0.0f;
    rep->eyes_flg = 0;
    rep->interpol = 1;
    sceVu0CopyVector(chr_pos, chr->nowpos.pos);
    tmcrsGetArea(&bx, &by, chr_pos);
    rep->now_cube = rep->now_block = -1;
    rep->now_cube = knReplayGetCube(chr_pos, vknCube);
    if (rep->now_cube > 0) {
        check = knReplayStatusCheck(chr, vknCube[rep->now_cube].cam.attr);
        if (check == 0) {
            rep->now_cube = -1;
        }
    }
    if (rep->now_cube < 0) {
        rep->now_cube = -1;
        for (i = 0; i < vknHead->bcam_num; i++) {
            check = knReplayGetBlock(bx, by, &vknBlock[i]);
            if (check == 1) {
                rep->now_block = i;
                break;
            }
        }
    }
    if ((rep->cam_cnt > 30.0f) || (rep->cam_cnt == -1)) {
        check = knReplayResetCheck(rep);
        switch (check) {
        case 1:
            rep->effect = vknCube[rep->now_cube].cam.effect;
            event_num = vknCube[rep->now_cube].cam.event & 0xF;
            now_group = vknCube[rep->now_cube].cam.event & 0xF0;
            old_group = vknCube[rep->old_cube].cam.event & 0xF0;
            if (event_num != 0) {
                rep->event = event_num + (vspenvGame->course.no * 3);
            } else {
                rep->event = 0;
            }
            if (now_group == 0) {
                knReplayResetCamera(rep, &vknCube[rep->now_cube].cam);
                break;
            }
            if (now_group != old_group) {
                knReplayResetCamera(rep, &vknCube[rep->now_cube].cam);
                break;
            }
            rep->now_cube = rep->old_cube;
            break;
        case 2:
            rep->effect = vknBlock[rep->now_block].cam.effect;
            knReplayResetCamera(rep, &vknBlock[rep->now_cube].cam);
            rep->event = 0;
            break;
        case 3:
            random = knCoreRand();
            random *= 100.0f;
            rep->def_cam = random;
            rep->def_cam = rep->def_cam % 9;
            knReplayInitDefaultCamera(rep);
            knReplayResetCamera(rep, &vknBlock[rep->now_cube].cam);
            rep->event = 0;
            break;
        }
    } else {
        rep->now_cube = rep->old_cube;
        rep->now_block = rep->old_block;
    }
    if (rep->now_cube >= 0) {
        knReplayCtrlCameraMain(chr, rep, &vknCube[rep->now_cube].cam);
    } else if (rep->now_block >= 0) {
        knReplayCtrlCameraMain(chr, rep, &vknBlock[rep->now_block].cam);
    } else {
        knReplayCtrlDefaultCamera(chr, rep);
    }
    knReplayCtrlEvent(chr, rep);
    gmsysSetBlurPow(rep->blur);
    knReplayCtrlEffect(chr, rep);
    if (rep->interpol == 1) {
        knReplayTumbleSpecial(chr, rep);
    }
    if (rep->hit != 1) {
        sceVu0CopyVector(tmp, core->trans);
        if (rep->hit < 7) {
            tmp[1] -= 150.0f;
        }
        sceVu0CopyVector(tmp2, core->trans);
        tmp2[1] += 15000.0f;
        switch (rep->hit) {
        case 0:
        case 2:
        case 7:
            hit = knCoreGetCourseHit(&cross, tmp, tmp2);
            break;
        case 3:
        case 5:
            hit = knCoreGetBaseHit(&cross, tmp, tmp2);
            break;
        case 4:
        case 6:
            hit = knCoreGetHitHit(&cross, tmp, tmp2);
            break;
        }
        if ((hit == 1) || (hit == 2)) {
            switch (rep->hit) {
            case 0:
            case 3:
            case 4:
                if (core->trans[1] > (cross.point[1] - 10.0f)) {
                    sceVu0CopyVector(core->trans, cross.point);
                    core->trans[1] -= 10.0f;
                }
                break;
            case 2:
            case 5:
            case 6:
            case 7:
                sceVu0CopyVector(core->trans, cross.point);
                core->trans[1] -= 10.0f;
                break;
            }
        }
    }
    knReplayInterPol(rep);
    if (rep->eyes_flg == 0) {
        knCoreGetAngle(core->rot, core->trans, core->obj);
    }
    knCoreSetWState(rep->core, num);
    if (rep->eff6 != 0.0f) {
        mat->scr_info.screen_z = 400.0f + rep->eff6;
    } else {
        mat->scr_info.screen_z = 400.0f + rep->wide;
    }
    rep->cam_cnt++;
    rep->cam_cnt2++;
    rep->old_cube = rep->now_cube;
    rep->old_block = rep->now_block;
    i = 1;
    return i;
}

s32 knReplayResetCheck(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep) {
    signed int flg = 0; // r16

    if (rep->now_cube != rep->old_cube) {
        if (rep->now_cube != -1) {
            return 1;
        }
        flg++;
    }
    if (rep->now_block != rep->old_block) {
        if (rep->now_block != -1) {
            return 2;
        }
        flg++;
    }
    if (flg != 0) {
        return 3;
    }
    if (rep->now_cube == -1 && rep->now_block == -1 && rep->cam_cnt > 300.0f) {
        return 3;
    }
    return 0;
}

static s32 knReplayStatusCheck(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, signed short attr) {
    // DWARF: 0x161774
    Sliding_State slide = chr->cam.sliding_state; // r16
    signed int hp_air = chr->cam.hp_air; // r17
    signed int link = chr->cam.trick_link; // r18
    
    if (attr == 0)
        return 1;

    if (link == 1)
        return 1;

    if (hp_air == 1) {
        if (attr == 1)
            return 1;
    } else if (slide == essGrind && attr == 2) {
        return 1;
    }
    return 0;
}

static signed int knReplayGetCube(float* pos /* r21 */, // Size: 0xE0, DWARF: 0x15FCFA
VknCube* box /* r20 */) {
    static float length[4] = { 1000.0f, 1000.0f, 1000.0f, 1.0f }; // 0x2CF010
    signed int i; // r16
    signed int num; // r18
    signed int ret; // r17
    float mat[4][4]; // 0x70(r29)
    float v1[4]; // 0xB0(r29)
    float v2[4]; // 0xC0(r29)
    // Size: 0xE0, DWARF: 0x15FCFA
    VknCube* now;

    ret = -1;
    for (i = 0; i < vknHead->ccam_num; i++) {
        now = &box[i];
        num = 1;
        asm(
            la      v0,length;
            lqc2    $vf3,0(pos);
            lqc2    $vf4,0(now);
            vsub.xyz $vf5xyz,$vf3xyz,$vf4xyz;
            vabs.xyz $vf5xyz,$vf5xyz;
            lqc2    $vf6,0(v0);
            vsub.xyz $vf7xyz,$vf6xyz,$vf5xyz;
            vnop;
            vnop;
            vnop;
            vnop;
            cfc2    v0,$vi16;
            andi    v0,v0,0x2;
            bgtz    v0,_knReplayGetCube_l1;
            b       _knReplayGetCube_l2;
        _knReplayGetCube_l1:
            cfc2    num,$vi0;
        _knReplayGetCube_l2:
        );
        if (num != 0) {
            sceVu0UnitMatrix(mat);
            sceVu0RotMatrixZ(mat, mat, now->rot[2]);
            sceVu0RotMatrixX(mat, mat, now->rot[0]);
            sceVu0RotMatrixY(mat, mat, now->rot[1]);
            sceVu0TransMatrix(mat, mat, now->trans);
            sceVu0InversMatrix(mat, mat);
            sceVu0ScaleVector(v1, now->volume, -0.5f);
            sceVu0ScaleVector(v2, now->volume, 0.5f);
            pos[3] = 1.0f;
            asm(
                addiu   v0,sp,0x70;
                addiu   v1,sp,0xb0;
                addiu   a0,sp,0xc0;
                lqc2    $vf3,0(v0);
                lqc2    $vf4,0x10(v0);
                lqc2    $vf5,0x20(v0);
                lqc2    $vf6,0x30(v0);
                lqc2    $vf7,0(pos);
                vmulax.xyzw $ACCxyzw,$vf3xyzw,$vf7x;
                vmadday.xyzw $ACCxyzw,$vf4xyzw,$vf7y;
                vmaddaz.xyzw $ACCxyzw,$vf5xyzw,$vf7z;
                vmaddw.xyzw $vf10xyzw,$vf6xyzw,$vf7w;
                lqc2    $vf11,0(v1);
                lqc2    $vf12,0(a0);
                ctc2    zero,$vi16;
                vsub.xyz $vf15xyz,$vf10xyz,$vf11xyz;
                vsub.xyz $vf16xyz,$vf12xyz,$vf10xyz;
                vnop;
                vnop;
                vnop;
                vnop;
                cfc2    v0,$vi16;
                andi    v0,v0,0x80;
                bgtz    v0,_knReplayGetCube_l3;
                b       _knReplayGetCube_l4;
            _knReplayGetCube_l3:
                cfc2    num,$vi0;
                nop;
            _knReplayGetCube_l4:
            );
            if (num != 0) {
                ret = i;
            }
        }
    }
    return ret;
}

static signed int knReplayGetBlock(signed int bx /* 0x10(r29) */, signed int by /* 0x20(r29) */, // Size: 0xF0, DWARF: 0x15CFE2
VknBlock* block /* 0x30(r29) */) {
    signed int i; // r16

    for (i = 0; i < block->num; i++) {
        if (bx == block->x[i]) {
            if (block->y[i] == by) {
                return 1;
            }
        }
    }
    return 0;
}

static void knReplayInterPol(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep) {
    // Size: 0x50, DWARF: 0x15DA03
    CameraTransform* core; // r17
    static float rate = 0.9f; // rate$310 0x2E787C

    core = rep->core;
    switch (rep->cam_cnt2) {
    case -1:
        break;
    case 0:
        rep->cam_cnt2 = 0;
        {
            register float* unused1 = core->trans;
            register float* unused2 = core->obj;
            register float* unused3 = rep->old_obj[0];

            asm(
                lqc2    $vf3,0(unused1);
                sqc2    $vf3,0(rep);
                sqc2    $vf3,0x10(rep);
                sqc2    $vf3,0x20(rep);
                lqc2    $vf4,0(unused2);
                sqc2    $vf4,0(unused3);
                sqc2    $vf4,0x10(unused3);
                sqc2    $vf4,0x20(unused3);
            );
        }
        break;
    case 1:
        sceVu0InterVectorXYZ(core->trans, core->trans, rep->old_pos[0], rate);
        sceVu0InterVectorXYZ(core->obj, core->obj, rep->old_obj[0], rate);
        break;
    case 2:
        knCoreBezier(core->trans, rate, rep->old_pos[1], rep->old_pos[1], rep->old_pos[0], core->trans);
        knCoreBezier(core->obj, rate, rep->old_obj[1], rep->old_obj[1], rep->old_obj[0], core->obj);
        break;
    default:
        knCoreBezier(core->trans, rate, rep->old_pos[2], rep->old_pos[1], rep->old_pos[0], core->trans);
        knCoreBezier(core->obj, rate, rep->old_obj[2], rep->old_obj[1], rep->old_obj[0], core->obj);
        break;
    }
    sceVu0CopyVector(rep->old_pos[2], rep->old_pos[1]);
    sceVu0CopyVector(rep->old_pos[1], rep->old_pos[0]);
    sceVu0CopyVector(rep->old_pos[0], core->trans);
    sceVu0CopyVector(rep->old_obj[2], rep->old_obj[1]);
    sceVu0CopyVector(rep->old_obj[1], rep->old_obj[0]);
    sceVu0CopyVector(rep->old_obj[0], core->obj);
}

void knReplaySetObstPos(float* pos, signed int flg, signed int id) {
    id = id % 3;
    if (pos != 0) {
        sceVu0CopyVector(&vknEvent.obst_pos[id], pos);
    }
    vknEvent.event_on[id] = flg;
}

void knReplayCtrlCameraMain(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data) {
    knReplayCtrlView(chr, rep, cam_data);
    knReplayCtrlObj(chr, rep, cam_data);
}

static void knReplayResetCamera(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x30(r29) */, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data /* 0x40(r29) */) {
    signed short tmp; // r16
    float random; // 0x2C(r29)

    rep->cam_cnt = 0;
    rep->cam_cnt2 = 0;
    rep->t_cnt1 = 0.0f;
    rep->t_cnt2 = 0.0f;
    rep->t_flg1 = 0;
    rep->t_flg2 = 0;
    rep->shake_cnt = 0.0f;
    rep->shake_flg = 0;
    rep->wide = 0.0f;
    rep->eff6 = 0.0f;
    rep->change = 0;
    if (cam_data->cam_type == 0x19) {
        do {
            random = knCoreRand();
            tmp = (short)(100.0f * random);
            rep->change = tmp % 4;
        } while (cam_data->c_ope[rep->change][3] == 0.0f);
    }
}

static void knReplayCtrlView(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* 0x70(r29) */, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x80(r29) */, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data /* 0x90(r29) */) {
    signed int type; // r16
    float rate; // 0x48(r29)
    float chr_pos[4]; // 0x20(r29)
    float len[4]; // 0x30(r29)
    float test; // 0x4C(r29)

    rep->hit = cam_data->hit;
    sceVu0CopyVector(chr_pos, chr->cam.pos_disp);
    switch (cam_data->cam_type) {
    case 0:
        sceVu0AddVector(rep->core->trans, chr_pos, cam_data->cam_dis);
        rep->core->trans[3] = 1.0f;
        break;
    case 1:
        rep->hit = 1;
        sceVu0CopyVector(rep->core->trans, cam_data->c_ope[0]);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        type = cam_data->cam_type - 2;
        knReplayPointToPoint(rep->core->trans, rep, cam_data, cam_data->c_ope, chr_pos, type);
        break;
    case 8:
        knReplayAxisMove(rep->core->trans, cam_data->c_ope, chr_pos);
        break;
    case 9:
        sceVu0CopyVector(rep->core->trans, cam_data->c_ope[1]);
        rep->core->trans[1] = chr_pos[1];
        sceVu0AddVector(rep->core->trans, rep->core->trans, cam_data->cam_dis);
        break;
    case 10:
        knReplayCharRotCamera(rep->core->trans, rep, chr->disp_pole, chr_pos, cam_data->cam_dis);
        if (cam_data->sub_type != 0) {
            rep->t_cnt1 = ((rep->t_cnt1 + (0.01f * cam_data->sub_type)) > 3.1415927f) ? ((rep->t_cnt1 + (0.01f * cam_data->sub_type)) - 6.2831855f) : (((rep->t_cnt1 + (0.01f * cam_data->sub_type)) < -3.1415927f) ? (6.2831855f + (rep->t_cnt1 + (0.01f * cam_data->sub_type))) : (rep->t_cnt1 + (0.01f * cam_data->sub_type)));
        } else {
            rep->t_cnt1 = ((0.02f + rep->t_cnt1) > 3.1415927f) ? ((0.02f + rep->t_cnt1) - 6.2831855f) : (((0.02f + rep->t_cnt1) < -3.1415927f) ? (6.2831855f + (0.02f + rep->t_cnt1)) : (0.02f + rep->t_cnt1));
        }
        break;
    case 11:
        knReplayCharRotCamera(rep->core->trans, rep, chr->disp_pole, chr_pos, cam_data->cam_dis);
        if (cam_data->sub_type != 0) {
            rep->t_cnt1 = ((rep->t_cnt1 - (0.01f * cam_data->sub_type)) > 3.1415927f) ? ((rep->t_cnt1 - (0.01f * cam_data->sub_type)) - 6.2831855f) : (((rep->t_cnt1 - (0.01f * cam_data->sub_type)) < -3.1415927f) ? (6.2831855f + (rep->t_cnt1 - (0.01f * cam_data->sub_type))) : (rep->t_cnt1 - (0.01f * cam_data->sub_type)));
        } else {
            rep->t_cnt1 = ((rep->t_cnt1 - 0.02f) > 3.1415927f) ? ((rep->t_cnt1 - 0.02f) - 6.2831855f) : (((rep->t_cnt1 - 0.02f) < -3.1415927f) ? (6.2831855f + (rep->t_cnt1 - 0.02f)) : (rep->t_cnt1 - 0.02f));
        }
        break;
    case 12:
        sceVu0AddVector(rep->core->trans, chr_pos, cam_data->cam_dis);
        rate = 2.0f * chr->cam.now_speed[1];
        if (rate >= 35.0f) {
            rate = 35.0f;
        } else if (rate <= -35.0f) {
            rate = -35.0f;
        }
        rep->core->trans[1] = chr_pos[1] - rate;
        break;
    case 13:
        knReplayBetweenPoint(rep->core->trans, cam_data->c_ope[0], chr_pos, cam_data, 0);
        knReplayGetLen(len, chr_pos, rep->core->trans);
        if (len[3] < 15.0f) {
            knReplayGetLenScale(len, len, 15.0f);
            knCoreAddVectorXYZ(rep->core->trans, chr_pos, len);
        }
        break;
    case 14:
        knReplayBetweenPoint(rep->core->trans, chr_pos, cam_data->c_ope[0], cam_data, 1);
        knReplayGetLen(len, chr_pos, rep->core->trans);
        if (len[3] > 50.0f) {
            knReplayGetLenScale(len, len, 50.0f);
            knCoreAddVectorXYZ(rep->core->trans, chr_pos, len);
        }
        break;
    case 15:
        rep->hit = 1;
        sceVu0CopyVector(rep->core->trans, cam_data->c_ope[0]);
        knReplayGetLen(len, cam_data->c_ope[1], cam_data->c_ope[0]);
        test = len[3];
        knReplayGetLen(len, cam_data->c_ope[0], chr_pos);
        if (len[3] > test) {
            knReplayGetLenScale(len, len, test);
        }
        knCoreAddVectorXYZ(rep->core->trans, cam_data->c_ope[0], len);
        break;
    case 16:
        knReplayCharForward(rep->core->trans, chr, cam_data->cam_dis);
        break;
    case 17:
        knReplayAxisMove(rep->core->trans, cam_data->c_ope, chr_pos);
        rep->core->trans[1] = cam_data->c_ope[3][1];
        break;
    case 18:
        sceVu0CopyVector(rep->core->trans, cam_data->c_ope[1]);
        rep->core->trans[1] = chr_pos[1];
        sceVu0AddVector(rep->core->trans, rep->core->trans, cam_data->cam_dis);
        knReplayBetweenPoint(rep->core->trans, rep->core->trans, chr_pos, cam_data, 0);
        break;
    case 19:
        if (cam_data->sub_type == 0) {
            rate = 30.0f;
        } else {
            rate = 5.0f * cam_data->sub_type;
        }
        if (rep->cam_cnt < rate) {
            sceVu0AddVector(rep->core->trans, chr_pos, cam_data->c_ope[0]);
        } else if (rep->cam_cnt < (2.0f * rate)) {
            sceVu0AddVector(rep->core->trans, chr_pos, cam_data->c_ope[1]);
        } else if (rep->cam_cnt < (3.0f * rate)) {
            sceVu0AddVector(rep->core->trans, chr_pos, cam_data->c_ope[2]);
        } else {
            sceVu0AddVector(rep->core->trans, chr_pos, cam_data->c_ope[3]);
        }
        rep->cam_cnt2 = 0;
        rep->core->trans[3] = 1.0f;
        break;
    case 20:
        knReplayRotRelative(rep->core->trans, cam_data, chr_pos, chr->rot);
        break;
    case 21:
        knReplayAxisMove(rep->core->trans, cam_data->c_ope, chr_pos);
        rate = 0.5f;
        knReplayBetweenPoint(rep->core->trans, rep->core->trans, chr_pos, cam_data, 0);
        break;
    case 22:
        knReplayRelative(rep->core->trans, chr, rep, cam_data, 0);
        break;
    case 23:
        knReplayRelative(rep->core->trans, chr, rep, cam_data, 1);
        break;
    case 24:
        knReplayPointApproach(rep->core->trans, rep, cam_data, chr_pos);
        break;
    case 25:
        rep->hit = 1;
        sceVu0CopyVector(rep->core->trans, cam_data->c_ope[rep->change]);
        break;
    }
    rep->wide = cam_data->scrz;
}



static void knReplayGetLen(float* len /* r16 */, float* pos1 /* r2 */, float* pos2 /* r6 */) {
    float r; // 0x20(r29)
    float l; // 0x20(r29)

    r = 0.0f;
    sceVu0SubVector(len, pos2, pos1);
    l = sceVu0InnerProduct(len, len);
    asm("sqrt.s r, l");
    len[3] = r;
}

static void knReplayCtrlObj(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* 0x50(r29)*/, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x60(r29) */, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data /* 0x70(r29) */) {
    signed int type; // r16
    sceVu0FVECTOR chr_pos; // 0x20(r29)
    sceVu0FVECTOR tmp; // 0x30(r29)
    float rate; // 0x4C(r29)

    sceVu0CopyVector(chr_pos, chr->cam.pos_disp);
    switch(cam_data->obj_type) {
    case 0:
        sceVu0CopyVector(rep->core->obj, chr_pos);
        break;
    case 1:
        sceVu0CopyVector(rep->core->obj, cam_data->o_ope[0]);
        break;
    case 2:
        knCoreAddVectorXYZ(rep->core->obj, chr_pos, cam_data->o_ope);
        break;
    case 3:
        rep->eyes_flg = 1;
        knReplayFixRot(rep->core->obj, rep, cam_data);
        break;
    case 4:
        if (cam_data->sub_type2 == '\0') {
            rate = 30.0f;
        } else {
            rate = (cam_data->sub_type2) * 5.0f;
        }
        if (rep->cam_cnt < rate) {
            sceVu0AddVector(rep->core->obj,chr_pos,cam_data->o_ope[0]);
        } else if (rep->cam_cnt < rate * 2.0f) {
            sceVu0AddVector(rep->core->obj,chr_pos,cam_data->o_ope[1]);
        } else if (rep->cam_cnt < rate * 3.0f) {
            sceVu0AddVector(rep->core->obj,chr_pos,cam_data->o_ope[2]);
        } else {
            sceVu0AddVector(rep->core->obj, chr_pos, cam_data->o_ope[3]);
        }
        rep->core->obj[3] = 1.0f;
        break;
    case 5:
    case 6:
        knReplayCharFrameIn(rep->core->obj,rep,chr_pos,cam_data, cam_data->obj_type + -5);
        break;
    case 7:
        knReplayAxisMove(rep->core->obj, cam_data->o_ope, chr_pos);
        break;
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
        type = (cam_data->obj_type) - 8;
        type |= 0x10;
        knReplayPointToPoint (rep->core->obj, rep, cam_data, cam_data->o_ope, chr_pos, type);
        break;
    case 0xe:
        if (rep->cam_cnt == 0) {
            sceVu0CopyVector(rep->core->obj, chr_pos);
        } else {
            sceVu0SubVector(tmp, chr_pos,rep->core->obj);
            sceVu0ScaleVectorXYZ(tmp, tmp, 0.8f);
            sceVu0AddVector(rep->core->obj, rep->core->obj, tmp);
        }
        break;
    }
}

static void knReplayCtrlEffect(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x40(r29) */) {
    float len[4]; // 0x10(r29)
    float sub; // 0x2C(r29)

    knReplayBlur(rep);
    if (rep->effect & 4) {
        knCoreSubVectorXYZ(len, rep->core->trans, rep->old_pos[0]);
        sceVu0ScaleVector(len, len, 0.7f);
        knCoreAddVectorXYZ(rep->core->trans, rep->old_pos[0], len);
        if (rep->cam_cnt2 < 2) {
            rep->cam_cnt2 = 2;
        }
    }
    if (rep->effect & 8) {
        knReplayCameraShakeTYPE1(rep->core->obj, rep->core->obj, rep->core->rot, rep, 15.0f, 1.0f);
    }
    if (rep->effect & 0x10) {
        knReplayCameraShakeTYPE2(rep->core->obj, rep->core->obj, rep->core->rot, rep, 20.0f, 1.0f);
    }
    if (rep->effect & 0x20) {
        if (rep->old_pos[0][1] < rep->core->trans[1]) {
            if (rep->cam_cnt != 0) {
                rep->core->trans[1] = rep->old_pos[0][1];
            }
        }
    }
    if (rep->effect & 0x40) {
        sub = 0.005f * rep->wide;
        rep->eff6 += sub;
        if (rep->wide > 0.0f) {
            if (rep->eff6 > rep->wide) {
                rep->eff6 = rep->wide;
            }
        } else {
            if (rep->eff6 < rep->wide) {
                rep->eff6 = rep->wide;
            }
        }
    }
}

static void knReplayCtrlEvent(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* 0x50(r29) */, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x60(r29) */) {
    signed int flg; // r16
    signed int event_num; // r17
    float dis[4]; // 0x30(r29)
    float tmp[4]; // 0x40(r29)

    flg = 0;
    event_num = rep->event - 1;
    switch (event_num) {
    case 0:
        if (vknEvent.event_on[0] == 1) {
        }
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        if (vknEvent.event_on[0] == 1) {
            knReplayGetLen(dis, chr->cam.pos_disp, vknEvent.obst_pos[0]);
            knReplayGetLenScale(dis, dis, 30.0f);
            sceVu0AddVector(rep->core->trans, vknEvent.obst_pos[0], dis);
            sceVu0CopyVector(rep->core->obj, chr->cam.pos_disp);
            rep->core->trans[3] = 1.0f;
            rep->core->obj[3] = 1.0f;
            rep->hit = 0;
        }
        break;
    case 7:
        if (vknEvent.event_on[1] == 1) {
            sceVu0CopyVector(rep->core->obj, chr->nowpos.pos);
            rep->core->trans[0] = rep->core->obj[0] - 3.44f;
            rep->core->trans[1] = rep->core->obj[1] - 6.84f;
            rep->core->trans[2] = rep->core->obj[2] - 39.08f;
        }
        break;
    case 8:
        if (vknEvent.event_on[2] == 1) {
            flg = 1;
            sceVu0SubVector(tmp, chr->cam.pos_disp, vknEvent.obst_pos[2]);
            sceVu0MulVector(dis, tmp, tmp);
            dis[3] = dis[2] + (dis[0] + dis[1]);
            if ((chr->cam.pos_disp[2] < -6075.0f) && (dis[3] > 15000.0f)) {
                knReplayGetLen(dis, vknEvent.obst_pos[2], chr->cam.pos_disp);
                knReplayGetLenScale(dis, dis, 20.0f);
                sceVu0AddVector(rep->core->trans, chr->cam.pos_disp, dis);
                sceVu0CopyVector(rep->core->obj, vknEvent.obst_pos[2]);
                rep->core->trans[3] = 1.0f;
                rep->core->obj[3] = 1.0f;
                rep->hit = 0;
            } else {
                rep->core->trans[0] = 1876.75f;
                rep->core->trans[1] = 2623.06f;
                rep->core->trans[2] = -6075.4f;
                rep->core->trans[3] = 1.0f;
                sceVu0ScaleVector(tmp, tmp, 0.5f);
                sceVu0AddVector(rep->core->obj, vknEvent.obst_pos[2], tmp);
                rep->core->obj[3] = 1.0f;
            }
        } else {
            flg = 1;
        }
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        sceVu0SubVector(dis, chr->nowpos.pos, vknEvent.obst_pos[0]);
        sceVu0MulVector(dis, dis, dis);
        dis[3] = dis[2] + (dis[0] + dis[1]);
        if (dis[3] < 50000.0f) {
            rep->core->trans[0] = -80.53f;
            rep->core->trans[1] = 5304.91f;
            rep->core->trans[2] = -7550.64f;
            rep->core->trans[3] = 1.0f;
            sceVu0CopyVector(rep->core->obj, vknEvent.obst_pos[0]);
            rep->core->obj[3] = 1.0f;
            rep->hit = 0;
        }
        break;
    case 13:
        sceVu0SubVector(tmp, chr->nowpos.pos, vknEvent.obst_pos[0]);
        sceVu0MulVector(dis, tmp, tmp);
        dis[3] = dis[2] + (dis[0] + dis[1]);
        if (dis[3] < 50000.0f) {
            sceVu0ScaleVector(tmp, tmp, 0.5f);
            tmp[3] = 0.0f;
            sceVu0AddVector(rep->core->obj, vknEvent.obst_pos[0], tmp);
            sceVu0CopyVector(rep->core->trans, rep->core->obj);
            rep->core->trans[1] += 28.0f;
            rep->core->trans[2] -= 140.0f;
            rep->core->trans[3] = rep->core->obj[3] = 1.0f;
            rep->hit = 0;
        }
        break;
    case 14:
        break;
    case 15:
        break;
    case 16:
        break;
    case 17:
        break;
    case 18:
        break;
    case 19:
        break;
    case 20:
        break;
    case 21:
        break;
    case 22:
        break;
    case 23:
        break;
    case 24:
        break;
    case 25:
        break;
    case 26:
        break;
    }
    event_num = rep->event_on;
    if (event_num != flg) {
        rep->cam_cnt2 = 0;
    }
    rep->event_on = flg;
}

void knReplayTumbleSpecial(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep) {
    if (chr->cam.trg_tumble_type == 3) {
        rep->tumble_flg++;
        if (rep->tumble_flg >= 4) {
            rep->tumble_flg = (s16) (100.0f * knCoreRand());
            rep->tumble_flg = (s16) ((rep->tumble_flg % 5) + 0x64);
            rep->interpol = 0;
        }
    }
    if (rep->tumble_flg >= 0x64) {
        if (chr->cam.tumble_type == 3) {
            sceVu0CopyVector(rep->core->obj, chr->cam.pos_disp);
            rep->core->obj[3] = 1.0f;
            sceVu0CopyVector(rep->core->trans, rep->core->obj);

            switch (rep->tumble_flg % 5) {
            case 0:
                rep->core->trans[0] = (f32) (20.0f + rep->core->obj[0]);
                break;
            case 1:
                rep->core->trans[0] = (f32) (rep->core->obj[0] - 20.0f);
                break;
            case 2:
                rep->core->trans[1] = (f32) (rep->core->obj[1] - 20.0f);
                break;
            case 3:
                rep->core->trans[2] = (f32) (20.0f + rep->core->obj[2]);
                break;
            case 4:
                rep->core->trans[2] = (f32) (rep->core->obj[2] - 20.0f);
                break;
            }
            rep->hit = 0;
            rep->effect = 0;
            return;
        }
        rep->tumble_flg = 0;
        rep->interpol = 0;
    }
}

static void knReplayInitDefaultCamera(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x30(r29) */) {
    signed int tmp; // r16
    float random; // 0x2C(r29)

    switch (rep->def_cam) {
    case 0:
        rep->dis[0] = 0.0f;
        rep->dis[1] = -20.0f;
        rep->dis[2] = 40.0f;
        rep->dis[3] = 1.0f;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        if (rep->def_cam < 5) {
            random = knCoreRand();
            rep->dis[0] = 15.0f + (30.0f * random);
            random = knCoreRand();
            rep->dis[2] = 15.0f + (30.0f * random);
        } else {
            random = knCoreRand();
            rep->dis[0] = 25.0f + (20.0f * random);
            random = knCoreRand();
            rep->dis[2] = 25.0f + (20.0f * random);
        }
        tmp = rep->def_cam;
        if (rep->def_cam > 5) {
            tmp -= 4;
        }
        if (tmp > 2) {
            rep->dis[0] = -rep->dis[0];
        }
        if ((tmp % 2) == 0) {
            rep->dis[2] = -rep->dis[2];
        }
        break;
    }
}

static void knReplayCtrlDefaultCamera(// Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* 0x60(r29) */, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x70(r29) */) {
    static float dis[4] = { 0.0f, -20.0f, 40.0f, 1.0f }; // 0x2CF020
    float pole[4]; // 0x10(r29)
    float tmp_dis[4]; // 0x20(r29)
    float p1[4]; // 0x30(r29)
    float p2[4]; // 0x40(r29)

    switch (rep->def_cam) {
    case 0:
        sceVu0CopyVector(pole, chr->disp_pole);
        pole[1] = -1.0f;
        knReplayCharRotCamera(rep->core->trans, rep, pole, chr->cam.pos_disp, dis);
        rep->t_cnt1 = ((0.01f + rep->t_cnt1) > 3.1415927f) ? ((0.01f + rep->t_cnt1) - 6.2831855f) : (((0.01f + rep->t_cnt1) < -3.1415927f) ? (6.2831855f + (0.01f + rep->t_cnt1)) : (0.01f + rep->t_cnt1));
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        sceVu0AddVector(rep->core->trans, chr->cam.pos_disp, rep->dis);
        rep->core->trans[1] -= 15.0f;
        rep->core->trans[3] = 1.0f;
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        sceVu0ScaleVector(tmp_dis, rep->dis, 0.5f);
        sceVu0AddVector(p1, chr->cam.pos_disp, rep->dis);
        sceVu0AddVector(p2, chr->cam.pos_disp, tmp_dis);
        knCoreBezier(rep->core->trans, rep->t_cnt1, p1, p1, p2, p2);
        if (rep->t_flg1 == 0) {
            rep->t_cnt1 += 0.005f;
            if (rep->t_cnt1 > 1.0f) {
                rep->t_flg1 ^= 1;
            }
        } else {
            rep->t_cnt1 -= 0.005f;
            if (rep->t_cnt1 < 0.0f) {
                rep->t_flg1 ^= 1;
            }
        }
        break;
    }
    sceVu0CopyVector(rep->core->obj, chr->cam.pos_disp);
    if (rep->blur > 0) {
        rep->blur -= 5;
        if (rep->blur < 0) {
            rep->blur = 0;
        }
    }
    rep->hit = 0;
    rep->effect = 0;
}

void knReplayBlur(// Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep) {
    signed int check = 3; // r16

    if ((rep->effect & 1) && (1 < rep->cam_cnt)) {
        rep->blur += 2;
        if (0x55 < rep->blur) {
            rep->blur = 0x55;
        }
    }
    if ((rep->effect & 2) && (1 < rep->cam_cnt)) {
        rep->blur += 0xA;
        if (0x64 < rep->blur) {
            rep->blur = 0x64;
        }
    }
    if (!(rep->effect & check) && (rep->blur > 0)) {
        rep->blur -= 5;
        if (rep->blur < 0) {
            rep->blur = 0;
        }
    }
}

static void knReplayRelative(float* point, // Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, signed int type) {
    float sp[4]; // 0x10(r29)
    float rate; // 0x2C(r29)
    static float old[4]; // old$648 0x3C6A50

    if (rep->cam_cnt == 0) {
        sceVu0AddVector(point, chr->nowpos.pos, cam_data->cam_dis);
        sceVu0CopyVector(&old, chr->cam.pos.pos);
    } else {
        knCoreSubVectorXYZ(&sp, chr->nowpos.pos, chr->prepos.pos);
        if (type == 0) {
            rate = 1.25f;
        } else {
            rate = 0.75f;
        }
        sceVu0ScaleVectorXYZ(&sp, &sp, rate);
        knCoreAddVectorXYZ(point, rep->core->trans, &sp);
    }
    point[3] = 1.0f;
    rep->cam_cnt2 = 0;
}

static void knReplayRotRelative(float* point, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, float* chr_pos, float* chr_rot) {
    float tmp[4]; // 0x10(r29)
    float mat[4][4]; // 0x20(r29)

    knCoreRotMatrix(&mat, chr_rot);
    sceVu0CopyVector(&tmp, cam_data);
    tmp[3] = 1.0f;
    sceVu0ApplyMatrix(&tmp, &mat, &tmp);
    knCoreAddVectorXYZ(point, chr_pos, &tmp);
}

static void knReplayPointToPoint(float* point /* 0xA0(r29) */, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0xB0(r29) */, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data /* 0xC0(r29) */, sceVu0FMATRIX ope /* 0xD0(r29) */, float* chr_pos /* 0xE0(r29) */, signed int type /* 0xF0(r29) */) {

    signed int i; // r16
    signed char sub_type; // r17
    signed int move; // r18
    signed int type2; // r19
    float p[4][4]; // 0x50(r29)
    float t; // 0x98(r29)
    float f; // 0x9C(r29)

    t = 0.0f;
    memcpy(&p, ope, 0x40);
    type2 = type & 0xF;
    if (type2 >= 3) {
        for (i = 0; i < 4; i++) {
            sceVu0AddVector(p[i], chr_pos, ope[i]);
        }
    }
    switch (type) {
    case 0:
    case 3:
        knCoreBezier(point, rep->t_cnt1, p[0], p[0], p[1], p[1]);
        sub_type = cam_data->sub_type;
        break;
    case 1:
    case 4:
        knCoreSpline1(point, rep->t_cnt1, p[0], p[1], p[2], p[3]);
        sub_type = cam_data->sub_type;
        break;
    case 2:
    case 5:
        knCoreBezier(point, rep->t_cnt1,  p[0], p[1], p[2], p[3]);
        sub_type = cam_data->sub_type;
        break;
    case 16:
    case 19:
        knCoreBezier(point, rep->t_cnt2, p[0], p[0], p[1], p[1]);
        sub_type = cam_data->sub_type2;
        break;
    case 17:
    case 20:
        knCoreSpline1(point, rep->t_cnt2, p[0], p[1], p[2], p[3]);
        sub_type = cam_data->sub_type2;
        break;
    case 18:
    case 21:
        knCoreBezier(point, rep->t_cnt2,  p[0], p[1], p[2], p[3]);
        sub_type = cam_data->sub_type2;
        break;
    }
    f = ((sub_type - 1) % 10) + 1;
    if (sub_type < 0xB) {
        move = 0;
        if (sub_type == 0) {
            f = 0.005f;
        } else {
            f = 1.0f / (30.0f * f);
        }
    } else if (sub_type < 0x15) {
        move = 1;
        f = 1.0f / (30.0f * f);
    }
    switch (move) {
    case 0:
        if (type & 0x10) {
            rep->t_cnt2 += f;
            if (rep->t_cnt2 > 1.0f) {
                rep->t_cnt2 = 1.0f;
                return;
            }
        } else {
            rep->t_cnt1 += f;
            if (rep->t_cnt1 > 1.0f) {
                rep->t_cnt1 = 1.0f;
                return;
            }
        }
        break;
    case 1:
        if (type & 0x10) {
            if (rep->t_flg2 == 0) {
                rep->t_cnt2 += f;
                if (rep->t_cnt2 > 1.0f) {
                    rep->t_flg2 ^= 1;
                    return;
                }
            } else {
                rep->t_cnt2 -= f;
                if (rep->t_cnt2 < 0.0f) {
                    rep->t_flg2 ^= 1;
                    return;
                }
            }
        } else if (rep->t_flg1 == 0) {
            rep->t_cnt1 += f;
            if (rep->t_cnt1 > 1.0f) {
                rep->t_flg1 ^= 1;
                return;
            }
        } else {
            rep->t_cnt1 -= f;
            if (rep->t_cnt1 < 0.0f) {
                rep->t_flg1 ^= 1;
            }
        }
        break;
    }
}

static void knReplayBetweenPoint(float* point, float* a, float* b, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data, signed int type) {
    float dis[4]; // 0x10(r29)
    float len_rate; // 0x2C(r29)

    if (type == 0) {
        if (cam_data->sub_type == 0) {
            len_rate = 0.5f;
        } else {
            len_rate = 0.05f * cam_data->sub_type;
            len_rate = 1.0f - len_rate;
        }
    } else if (cam_data->sub_type == 0) {
        len_rate = 1.5f;
    } else {
        len_rate = 0.05f * cam_data->sub_type;
        len_rate = 1.0f - len_rate;
        len_rate += 1.0f;
    }
    knCoreSubVectorXYZ(&dis, a, b);
    sceVu0ScaleVector(&dis, &dis, len_rate);
    knCoreAddVectorXYZ(point, b, &dis);
}

void knReplayPointApproach(sceVu0FVECTOR unused, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* 0x50(r29) */, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data /* 0x60(r29) */, float* chr_pos /* 0x70(r29) */) {
    signed int move; // r16
    float len[4]; // 0x20(r29)
    float f; // 0x3C(r29)

    f = (((cam_data->sub_type - 1) % 10) + 1);
    if (cam_data->sub_type < 0xB) {
        move = 0;
        if (cam_data->sub_type == 0) {
            f = 0.005f;
        } else {
            f = 1.0f / (30.0f * f);
        }
    }
    if ((rep->change) == 0) {
        rep->t_cnt1 += f;
        if ((rep->t_cnt1 > 1.0f)) {
            rep->t_cnt1 = 1.0f;
        }
        knCoreBezier(rep->core->trans, rep->t_cnt1, cam_data->c_ope[0], cam_data->c_ope[0], chr_pos, chr_pos);
        knReplayGetLen(&len, chr_pos, rep->core->trans);
        if (len[3] < 25.0f) {
            knReplayGetLenScale(&len, &len, 25.0);
            sceVu0CopyVector(rep->dis, &len);
            rep->change = 1;
        }
    } else {
        knCoreAddVectorXYZ(rep->core->trans, chr_pos, rep->dis);
    }
}

static void knReplayCharForward(float* point /* r18 */, // Size: 0x2C00, DWARF: 0x15D1F9
Ctrl* chr /* r17 */, float* dis /* r6 */) {
    float rot[4]; // 0x40(r29)
    float tmp[4]; // 0x50(r29)
    float dis2[4]; // 0x60(r29)
    float sp[4]; // 0x70(r29)
    float mat[4][4]; // 0x80(r29)
    float sq_tmp; // 0xC0(r29)
    float xz;
    signed int slide; // r16

    xz = 0.0f;
    slide = chr->cam.sliding_state;
    sceVu0MulVector(tmp, dis, dis);
    sq_tmp = tmp[0] + tmp[2];
    asm("sqrt.s xz, sq_tmp");
    dis2[0] = 0.0f;
    dis2[1] = 0.0f;
    dis2[2] = xz;
    dis2[3] = 1.0f;
    sceVu0CopyVector(rot, chr->cam.rot);
    if ((3.1415927f + rot[1]) > 3.1415927f) {
        sq_tmp = (3.1415927f + rot[1]) - 6.2831855f;
    } else if ((3.1415927f + rot[1]) < -3.1415927f) {
        sq_tmp = 6.2831855f + (3.1415927f + rot[1]);
    } else {
        sq_tmp = 3.1415927f + rot[1];
    }
    rot[1] = sq_tmp;
    if (slide == 3) {
        sceVu0CopyVector(sp, chr->cam.now_speed);
        sp[1] = 0.0f;
        sp[3] = 1.0f;
        sceVu0Normalize(sp, sp);
        rot[1] = atan2f(sp[0], sp[2]);
    }
    knCoreRotMatrix(mat, rot);
    sceVu0ApplyMatrix(tmp, mat, dis2);
    knCoreAddVectorXYZ(point, chr->cam.pos.pos, tmp);
}

static void knReplayCharRotCamera(float* point, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, float* axis, float* chr_pos, float* dis) {
    float mat[4][4]; // 0x10(r29)
    float dis2[4]; // 0x50(r29)

    knReplayAxisRotMatrix(&mat, rep->t_cnt1, axis);
    sceVu0ApplyMatrix(&dis2, &mat, dis);
    knCoreAddVectorXYZ(point, chr_pos, &dis2);
}

static s32 knReplayAxisMove(float* point, sceVu0FMATRIX list, float* chr_pos) {
    float v1[4]; // 0x10(r29)
    float v2[4]; // 0x20(r29)

    sceVu0SubVector(&v1, list[2], list[1]);
    sceVu0Normalize(&v1, &v1);
    sceVu0SubVector(&v2, chr_pos, list[1]);
    sceVu0MulVector(&v2, &v1, &v2);
    sceVu0ScaleVector(point, &v1, v2[2] + (v2[0] + v2[1]));
    sceVu0AddVector(point, point, list[1]);
    point[1] = chr_pos[1];
    sceVu0AddVector(point, point, list);
    return 1;
}

static void knReplayFixRot(float* obj, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data) {
    float mat[4][4]; // 0x20(r29)
    float dis[4] = {
        0.0f,
        0.0f,
        20.0f,
        1.0f
    }; // 0x60(r29) @771
    s32* dis_ptr = &dis;

    knCoreRotMatrix(&mat, cam_data->o_ope);
    sceVu0ApplyMatrix(&dis, &mat, &dis);
    knCoreAddVectorXYZ(obj, rep->core->trans, &dis);
    sceVu0CopyVector(rep->core->rot, cam_data->o_ope[0]);
}

static void knReplayCharFrameIn(float* obj /* sp40 */, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep /* sp50*/, float* chr_pos /* sp60 */, // Size: 0xB0, DWARF: 0x15DAF3
CameraAttributes* cam_data /* sp70 */, signed int type /* sp80 */) {
    float pos1[4]; // 0x10(r29)
    float pos2[4]; // 0x20(r29)
    float dis[4]; // 0x30(r29)

    switch(type) {
        case 0:
        case 1:
            knCoreAddVectorXYZ(pos1, chr_pos, cam_data->o_ope);
            sceVu0CopyVector(dis, cam_data->o_ope[0]);
            dis[3] = 1.0f;
        break;
    }

    if (type % 2 == 0) {
        sceVu0CopyVector(pos2, chr_pos);
    } else {
        knCoreSubVectorXYZ(pos2, chr_pos, dis);
    }
    knCoreBezier(obj, rep->t_cnt2, pos1, pos1, pos2, pos2);
    rep->t_cnt2 += 0.01f;
    if (rep->t_cnt2 > 1.0f) {
        rep->t_cnt2 = 1.0f;
    }
}

static void knReplayCameraShakeTYPE1(float* pos, float* p1, float* rot, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, float power, float rate) {
    signed int i; // r16
    float mat[4][4]; // 0x20(r29)
    float point[6][4]; // 0x60(r29)
    float pow; // 0xC0(r29)
    float pow2; // 0xC4(r29)
    float pow3; // 0xC8(r29)
    float ope_rate; // 0xCC(r29)

    pow = power;

    pow = pow * rate;
    pow2 = 0.5f * pow;
    pow3 = pow / 3.0f;

    point[0][0] = 0.0f; point[0][1] = pow2; point[0][2] = 0.0f; point[0][3] = 1.0f;
    point[1][0] = pow2; point[1][1] = pow3; point[1][2] = 0.0f; point[1][3] = 1.0f;
    point[2][0] = -pow2; point[2][1] = -pow3; point[2][2] = 0.0f; point[2][3] = 1.0f;
    point[3][0] = 0.0f; point[3][1] = -pow2; point[3][2] = 0.0f; point[3][3] = 1.0f;
    point[4][0] = pow2; point[4][1] = -pow3; point[4][2] = 0.0f; point[4][3] = 1.0f;
    point[5][0] = -pow2; point[5][1] = pow3; point[5][2] = 0.0f; point[5][3] = 1.0f;

    knCoreRotMatrix(mat, rot);
    for (i = 0; i < 6; i++) {
        sceVu0ApplyMatrix(point[i], mat, point[i]);
        knCoreAddVectorXYZ(point[i], p1, point[i]);
    }
    if (rep->shake_flg == 0) {
        knCoreBezier(pos, rep->shake_cnt, point[0], point[1], point[2], point[3]);
    } else {
        knCoreBezier(pos, rep->shake_cnt, point[3], point[4], point[5], point[0]);
    }

    ope_rate = 0.001f * ((rand() % 10) + 10);

    rep->shake_cnt += ope_rate;
    if (rep->shake_cnt > 1.0f) {
        rep->shake_flg ^= 1;
        rep->shake_cnt = 0.0f;
    }
}

static void knReplayCameraShakeTYPE2(float* pos, float* p1, float* rot, // Size: 0xC0, DWARF: 0x15CB8F
VknReplay* rep, float power, float unused1) {
    float mat[4][4]; // 0x10(r29)
    float point[4]; // 0x50(r29)
    float pow; // 0x68(r29)
    float pow2; // 0x6C(r29)
    float ope_rate; // 0x70(r29)
    float r; // 0x74(r29)

    pow = power;

    pow2 = 0.5f * pow;

    point[0] = 0.0f; point[1] = pow2; point[2] = 0.0f; point[3] = 1.0f;

    knCoreRotMatrix(mat, rot);
    sceVu0ApplyMatrix(point, mat, point);

    r = sinf(rep->shake_cnt);
    sceVu0ScaleVector(point, point, r);

    knCoreAddVectorXYZ(pos, p1, point);

    ope_rate = 0.001f * ((rand() % 10) + 30);
    rep->shake_cnt = ((rep->shake_cnt + ope_rate) > 3.1415927f) ? ((rep->shake_cnt + ope_rate) - 6.2831855f) : (((rep->shake_cnt + ope_rate) < -3.1415927f) ? (6.2831855f + (rep->shake_cnt + ope_rate)) : (rep->shake_cnt + ope_rate));
}

static void knReplayAxisRotMatrix(sceVu0FMATRIX mat, float ang, float* axis) {
    float axis2[4]; // 0x10(r29)
    float cosa; // 0x2C(r29)
    float sina; // 0x30(r29)
    float axis01; // 0x34(r29)
    float axis02; // 0x38(r29)
    float axis12; // 0x3C(r29)

    cosa = cosf(ang);
    sina = sinf(ang);
    axis01 = axis[0] * axis[1];
    axis02 = axis[0] * axis[2];
    axis12 = axis[1] * axis[2];

    sceVu0MulVector(axis2, axis, axis);

    mat[0][0] = cosa + ((1.0f - cosa) * axis2[0]);
    mat[0][1] = ((1.0f - cosa) * axis01) - (sina * axis[2]);
    mat[0][2] = ((1.0f - cosa) * axis02) + (sina * axis[1]);
    mat[0][3] = 0.0f;
    mat[1][0] = ((1.0f - cosa) * axis01) + (sina * axis[2]);
    mat[1][1] = cosa + ((1.0f - cosa) * axis2[1]);
    mat[1][2] = ((1.0f - cosa) * axis12) - (sina * axis[0]);
    mat[1][3] = 0.0f;
    mat[2][0] = ((1.0f - cosa) * axis02) + (sina * axis[1]);
    mat[2][1] = ((1.0f - cosa) * axis12) - (sina * axis[0]);
    mat[2][2] = cosa + ((1.0f - cosa) * axis2[2]);
    mat[2][3] = 0.0f;
    mat[3][0] = 0.0f; mat[3][1] = 0.0f; mat[3][2] = 0.0f; mat[3][3] = 1.0f;
}

static void knReplayGetLenScale(float* out /* r17 */, float* len /* r16 */, float dis) {
    float scale; // 0x40(r29)
    float tmp2; // 0x40(r29)
    float tmp1;

    scale = 1.0f;
    tmp1 = dis * dis;
    tmp2 = sceVu0InnerProduct(len, len);
    tmp1 = tmp1 / tmp2;
    asm("sqrt.s scale, tmp1");
    sceVu0ScaleVectorXYZ(out, len, scale);
}
