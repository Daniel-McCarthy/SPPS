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

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// SCE Functions
void sceVu0SubVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0UnitMatrix(sceVu0FMATRIX a);
void sceVu0RotMatrixX(sceVu0FMATRIX a, sceVu0FMATRIX b, float rot);
void sceVu0RotMatrixY(sceVu0FMATRIX a, sceVu0FMATRIX b, float rot);
void sceVu0RotMatrixZ(sceVu0FMATRIX a, sceVu0FMATRIX b, float rot);
void sceVu0ApplyMatrix(sceVu0FVECTOR a, sceVu0FMATRIX b, sceVu0FVECTOR c);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);

#define ABORT() asm(".word 0x0000000d")

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on  // Trunc will be used instead of fptosi

// SCE includes /////////////////////////////////////////////////////////////////////
void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);
void sceVu0RotMatrix(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, sceVu0FVECTOR rot);
void sceVu0TransposeMatrix(sceVu0FMATRIX mat, sceVu0FMATRIX mat2);
void sceVu0ApplyMatrix(sceVu0FVECTOR vec, sceVu0FMATRIX mat,sceVu0FVECTOR vec2);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0ScaleVector(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0MulVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2, sceVu0FVECTOR vec3);
void sceVu0SubVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0UnitMatrix(sceVu0FMATRIX a);
void sceVu0CopyVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2); // (Copies vec2 onto vec)
void sceVu0AddVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0UnitMatrix(sceVu0FMATRIX mat);
void sceVu0Normalize(sceVu0FVECTOR vec, sceVu0FVECTOR vec2);

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);
float sinf(float a);

// Ctrl Struct / Event struct ////////////
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

typedef enum Tumble_Type
{
    ettNormal,
    ettTotter,
    ettTumbleS,
    ettTumbleL,
    ettTumbleF,
    ettTumbleN
} Tumble_Type; // Offset: 0x2A0, DWARF: 0x168A79

typedef enum Tumble_Way
{
    etwLeft,
    etwRight,
    etwFoward,
    etwBack
} Tumble_Way; // Offset: 0x2A4, DWARF: 0x168AA3

typedef enum ESP_Spin_Way
{
    espNoSpin,
    espTurnLeft,
    espTurnRight,
    espTurnLeftFast,
    espTurnRightFast
} ESP_Spin_Way; // Offset: 0x18, DWARF: 0x16B1F5

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

// DWARF: 0x16B665
typedef enum Stance_Change
{
    escNoAction,
    escTurnLeft,
    escTurnRight
} Stance_Change; // Offset: 0x14, DWARF: 0x16B1C9

// DWARF: 0x16C19D
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

// DWARF: 0x16DD0D
typedef enum Key_Way
{
    ekwNone,
    ekwLeft,
    ekwRight
} Key_Way; // Offset: 0x2C, DWARF: 0x16B2BC

// DWARF: 0x16C5FB
typedef enum Acceleration_Brake
{
    eraNone,
    eraAccel,
    eraBrake,
    eraAccelLeft,
    eraAccelRight
} Acceleration_Brake; // Offset: 0x0, DWARF: 0x16EEC0

// DWARF: 0x16E4C8
typedef enum Jump_Strength
{
    erjNone,
    erjWeak,
    erjMiddle,
    erjStrong,
    erjNollie,
    erjStart
} Jump_Strength; // Offset: 0x8, DWARF: 0x16EF0E

// DWARF: 0x16D3F3
typedef enum ERSC_Stance_Change
{
    erscNone,
    erscTurnLeft,
    erscTurnRight
} ERSC_Stance_Change; // Offset: 0xC, DWARF: 0x16EF31

// DWARF: 0x16DAF8
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

// DWARF: 0x16C51A
typedef enum Landing_Bonus
{
    elbNormal,
    elbPerfect,
    elbSloppy
} Landing_Bonus; // Offset: 0x24, DWARF: 0x16CB5A

// DWARF: 0x16C76D
typedef enum ETS_Trick_State
{
    etsNormal,
    etsFlip,
    etsManual,
    etsGrind,
    etsPlant,
    etsRevert
} ETS_Trick_State; // Offset: 0x5D4, DWARF: 0x169BF9

// DWARF: 0x16D779
typedef enum Trick_Link_State
{
    elsNone,
    elsLinking,
    elsSuccess,
    elsFailure
} Trick_Link_State; // Offset: 0x5E0, DWARF: 0x169C72

// Size: 0x8, DWARF: 0x168106
typedef struct Pad
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x168121
    signed char lh; // Offset: 0x2, DWARF: 0x168141
    signed char lv; // Offset: 0x3, DWARF: 0x168160
    signed int analog; // Offset: 0x4, DWARF: 0x16817F
} Pad;

// Size: 0x60, DWARF: 0x16E55B
typedef struct Pos
{
    float pos[4]; // Offset: 0x0, DWARF: 0x16E577
    float cross[4]; // Offset: 0x10, DWARF: 0x16E599
    float normal[4]; // Offset: 0x20, DWARF: 0x16E5BD
    signed int hit; // Offset: 0x30, DWARF: 0x16E5E2
    signed int material; // Offset: 0x34, DWARF: 0x16E602
    signed int halfpipe; // Offset: 0x38, DWARF: 0x16E627
    signed int ripping; // Offset: 0x3C, DWARF: 0x16E64C
    signed int bonk; // Offset: 0x40, DWARF: 0x16E670
    signed int low_g; // Offset: 0x44, DWARF: 0x16E691
    signed int no; // Offset: 0x48, DWARF: 0x16E6B3
    float len2; // Offset: 0x4C, DWARF: 0x16E6D2
    signed int type; // Offset: 0x50, DWARF: 0x16E6F3
    int padding[3]; // not originally in struct but pads struct to expected 0x60
} Pos;

// Size: 0x3C, DWARF: 0x16B0EF
typedef struct Inp // : E:\tam\ps2\sppbx\main.c
{
    signed int turn; // Offset: 0x0, DWARF: 0x16B10B
    signed int turn_x; // Offset: 0x4, DWARF: 0x16B12C
    signed int quick_turn; // Offset: 0x8, DWARF: 0x16B14F
    // DWARF: 0x16DD52
    Acceleration_State accel_state; // Offset: 0xC, DWARF: 0x16B176
    // DWARF: 0x16F2BB
    Jump_State jump_state; // Offset: 0x10, DWARF: 0x16B1A0
    // DWARF: 0x16B665
    Stance_Change stance_change; // Offset: 0x14, DWARF: 0x16B1C9
    // DWARF: 0x16D48D
    ESP_Spin_Way spin_way; // Offset: 0x18, DWARF: 0x16B1F5
    // DWARF: 0x16C19D
    Trick_Command command; // Offset: 0x1C, DWARF: 0x16B21C
    signed int cmd_mot_id; // Offset: 0x20, DWARF: 0x16B242
    signed int cmd_mot_nloop; // Offset: 0x24, DWARF: 0x16B269
    signed int cmd_trick_no; // Offset: 0x28, DWARF: 0x16B293
    // DWARF: 0x16DD0D
    Key_Way keyway; // Offset: 0x2C, DWARF: 0x16B2BC
    signed int tumble_speed_up; // Offset: 0x30, DWARF: 0x16B2E1
    signed int accel_speed; // Offset: 0x34, DWARF: 0x16B30D
    signed int stop_speed; // Offset: 0x38, DWARF: 0x16B335
} Inp;

// Size: 0x48, DWARF: 0x16EEA4
typedef struct Req
{
    // DWARF: 0x16C5FB
    Acceleration_Brake accel_brake; // Offset: 0x0, DWARF: 0x16EEC0
    signed int sitting; // Offset: 0x4, DWARF: 0x16EEEA
    // DWARF: 0x16E4C8
    Jump_Strength jump; // Offset: 0x8, DWARF: 0x16EF0E
    // DWARF: 0x16D3F3
    ERSC_Stance_Change stance_change; // Offset: 0xC, DWARF: 0x16EF31
    // DWARF: 0x16DAF8
    ERC_Command command; // Offset: 0x10, DWARF: 0x16EF5D
    signed int cmd_mot_id; // Offset: 0x14, DWARF: 0x16EF83
    signed int cmd_mot_nloop; // Offset: 0x18, DWARF: 0x16EFAA
    signed int cmd_trick_no; // Offset: 0x1C, DWARF: 0x16EFD4
    signed int end_fall; // Offset: 0x20, DWARF: 0x16EFFD
    signed int trick_no; // Offset: 0x24, DWARF: 0x16F022
    signed int flip_no; // Offset: 0x28, DWARF: 0x16F047
    signed int grind_no; // Offset: 0x2C, DWARF: 0x16F06B
    signed int plant_no; // Offset: 0x30, DWARF: 0x16F090
    signed int bonk_no; // Offset: 0x34, DWARF: 0x16F0B5
    signed int manual_no; // Offset: 0x38, DWARF: 0x16F0D9
    signed int revert_no; // Offset: 0x3C, DWARF: 0x16F0FF
    signed int jump_no; // Offset: 0x40, DWARF: 0x16F125
    signed int sptrk_id; // Offset: 0x44, DWARF: 0x16F149
} Req;

// Size: 0x30, DWARF: 0x16E19B
typedef struct Plane
{
    float cross[4]; // Offset: 0x0, DWARF: 0x16E1B7
    float normal[4]; // Offset: 0x10, DWARF: 0x16E1DB
    unsigned short material; // Offset: 0x20, DWARF: 0x16E200
    unsigned short attribute; // Offset: 0x22, DWARF: 0x16E225
    signed short almighty1; // Offset: 0x24, DWARF: 0x16E24B
    signed short almighty2; // Offset: 0x26, DWARF: 0x16E271
    signed short almighty3; // Offset: 0x28, DWARF: 0x16E297
    signed short slidable; // Offset: 0x2A, DWARF: 0x16E2BD
    signed int available; // Offset: 0x2C, DWARF: 0x16E2E2
} Plane;

 // Size: 0x1F0, DWARF: 0x16E7E8
typedef struct Sbcore
{
    float nextpos[4]; // Offset: 0x0, DWARF: 0x16E804
    float speed[4]; // Offset: 0x10, DWARF: 0x16E82A
    float rot_pole; // Offset: 0x20, DWARF: 0x16E84E
    float max_relief_gap; // Offset: 0x24, DWARF: 0x16E873
    signed int freefoot; // Offset: 0x28, DWARF: 0x16E89E
    float limit_ang_down; // Offset: 0x2C, DWARF: 0x16E8C3
    float limit_ang_up; // Offset: 0x30, DWARF: 0x16E8EE
    signed int set_sp_normal; // Offset: 0x34, DWARF: 0x16E917
    float pos_head[4] __attribute__((aligned (16))); // Offset: 0x40, DWARF: 0x16E941
    float pos_hip[4]; // Offset: 0x50, DWARF: 0x16E968
    signed int move_head; // Offset: 0x60, DWARF: 0x16E98E
    float ang_slidable_limit; // Offset: 0x64, DWARF: 0x16E9B4
    float pos[4] __attribute__((aligned (16))); // Offset: 0x70, DWARF: 0x16E9E3
    float pole[4]; // Offset: 0x80, DWARF: 0x16EA05
    float sp_normal[4]; // Offset: 0x90, DWARF: 0x16EA28
    signed int sliding; // Offset: 0xA0, DWARF: 0x16EA50
    float relief_gap; // Offset: 0xA4, DWARF: 0x16EA74
    float touch_posy; // Offset: 0xA8, DWARF: 0x16EA9B
    float const_max_relief_gap; // Offset: 0xAC, DWARF: 0x16EAC2
    float const_under_foot; // Offset: 0xB0, DWARF: 0x16EAF3
    signed int const_keep_normal; // Offset: 0xB4, DWARF: 0x16EB20
    float height; // Offset: 0xB8, DWARF: 0x16EB4E
    signed int cnt_keep_normal; // Offset: 0xBC, DWARF: 0x16EB71
    signed int move; // Offset: 0xC0, DWARF: 0x16EB9D
    // Size: 0x30, DWARF: 0x16E19B
    Plane plane_hit; // Offset: 0xD0, DWARF: 0x16EBBE
    // Size: 0x30, DWARF: 0x16E19B
    Plane plane_sliding; // Offset: 0x100, DWARF: 0x16EBE6
    // Size: 0x30, DWARF: 0x16E19B
    Plane plane_beneath; // Offset: 0x130, DWARF: 0x16EC12
    // Size: 0x30, DWARF: 0x16E19B
    Plane plane_body; // Offset: 0x160, DWARF: 0x16EC3E
    // Size: 0x30, DWARF: 0x16E19B
    Plane plane_hit_buff; // Offset: 0x190, DWARF: 0x16EC67
    // Size: 0x30, DWARF: 0x16E19B
    Plane plane_pre_hit; // Offset: 0x1C0, DWARF: 0x16EC94
} Sbcore;

// Size: 0x14, DWARF: 0x16ED0C
typedef struct Balance
{
    float balance; // Offset: 0x0, DWARF: 0x16ED28
    float lean; // Offset: 0x4, DWARF: 0x16ED4C
    float lean_dir; // Offset: 0x8, DWARF: 0x16ED6D
    signed int released; // Offset: 0xC, DWARF: 0x16ED92
    signed int cnt_free; // Offset: 0x10, DWARF: 0x16EDB7
} Balance;

// Size: 0x24, DWARF: 0x16B853
typedef struct Param2
{
    signed int ollie; // Offset: 0x0, DWARF: 0x16B86F
    signed int spin; // Offset: 0x4, DWARF: 0x16B891
    signed int speed; // Offset: 0x8, DWARF: 0x16B8B2
    signed int landing; // Offset: 0xC, DWARF: 0x16B8D4
    signed int landing_switch; // Offset: 0x10, DWARF: 0x16B8F8
    signed int balance; // Offset: 0x14, DWARF: 0x16B923
    signed int quickness; // Offset: 0x18, DWARF: 0x16B947
    signed int power; // Offset: 0x1C, DWARF: 0x16B96D
    signed int turning; // Offset: 0x20, DWARF: 0x16B98F
} Param2;

// Size: 0x1C, DWARF: 0x16D2B9
typedef struct Character_Param
{
    signed int ollie; // Offset: 0x0, DWARF: 0x16D2D5
    signed int spin; // Offset: 0x4, DWARF: 0x16D2F7
    signed int speed; // Offset: 0x8, DWARF: 0x16D318
    signed int landing; // Offset: 0xC, DWARF: 0x16D33A
    signed int balance; // Offset: 0x10, DWARF: 0x16D35E
    signed int stability; // Offset: 0x14, DWARF: 0x16D382
    signed int stance; // Offset: 0x18, DWARF: 0x16D3A8
} Character_Param;

// Size: 0x10, DWARF: 0x16DA24
typedef struct Board_Param
{
    signed int speed; // Offset: 0x0, DWARF: 0x16DA40
    signed int stability; // Offset: 0x4, DWARF: 0x16DA62
    signed int balance; // Offset: 0x8, DWARF: 0x16DA88
    signed int turning; // Offset: 0xC, DWARF: 0x16DAAC
} Board_Param;

// Size: 0x3C, DWARF: 0x167640
typedef struct Rider_State
{
    signed int no; // Offset: 0x0, DWARF: 0x16765B
    signed int player; // Offset: 0x4, DWARF: 0x16767A
    signed int wear; // Offset: 0x8, DWARF: 0x16769D
    signed int board; // Offset: 0xC, DWARF: 0x1676BE
    // Size: 0x1C, DWARF: 0x16D2B9
    Character_Param chr_param; // Offset: 0x10, DWARF: 0x1676E0
    // Size: 0x10, DWARF: 0x16DA24
    Board_Param brd_param; // Offset: 0x2C, DWARF: 0x167708
} Rider_State;

// Size: 0x60, DWARF: 0x168242
typedef struct Col
{
    float normal[4]; // Offset: 0x0, DWARF: 0x16825E
    float point[4]; // Offset: 0x10, DWARF: 0x168283
    sceVu0FVECTOR* vertex; // Offset: 0x20, DWARF: 0x1682A7
    unsigned int attr; // Offset: 0x24, DWARF: 0x1682CF
    signed int nvertex; // Offset: 0x28, DWARF: 0x1682F0
    signed int no; // Offset: 0x2C, DWARF: 0x168314
    float len; // Offset: 0x30, DWARF: 0x168333
    signed int rail_no; // Offset: 0x34, DWARF: 0x168353
    signed int obj_no; // Offset: 0x38, DWARF: 0x168377
    signed int obj_attr; // Offset: 0x3C, DWARF: 0x16839A
    signed int obj_type; // Offset: 0x40, DWARF: 0x1683BF
    signed int res[4]; // Offset: 0x44, DWARF: 0x1683E4
    s32 padding[3];
} Col;

// Size: 0x98, DWARF: 0x16C9D1
typedef struct TrickLink
{
    signed int trick_link; // Offset: 0x0, DWARF: 0x16C9ED
    signed int trg_start_link; // Offset: 0x4, DWARF: 0x16CA14
    signed int trg_end_link; // Offset: 0x8, DWARF: 0x16CA3F
    signed int trg_get_pts; // Offset: 0xC, DWARF: 0x16CA68
    signed int spenv_get_trick_no; // Offset: 0x10, DWARF: 0x16CA90
    signed int pre_cnt_link; // Offset: 0x14, DWARF: 0x16CABF
    signed int cnt_link; // Offset: 0x18, DWARF: 0x16CAE8
    signed int cnt_trick; // Offset: 0x1C, DWARF: 0x16CB0D
    unsigned int last_point; // Offset: 0x20, DWARF: 0x16CB33
    // DWARF: 0x16C51A
    Landing_Bonus is_bonus_landing; // Offset: 0x24, DWARF: 0x16CB5A
    signed int is_bonus_switch; // Offset: 0x28, DWARF: 0x16CB89
    signed int is_bonus_spin; // Offset: 0x2C, DWARF: 0x16CBB5
    signed int is_bonus_airtime; // Offset: 0x30, DWARF: 0x16CBDF
    signed int set_top_cnt_link; // Offset: 0x34, DWARF: 0x16CC0C
    signed int added_nollie; // Offset: 0x38, DWARF: 0x16CC39
    signed int added_airtime; // Offset: 0x3C, DWARF: 0x16CC62
    signed int trg_trick; // Offset: 0x40, DWARF: 0x16CC8C
    unsigned int pts_current_trick; // Offset: 0x44, DWARF: 0x16CCB2
    unsigned int pts_current_hold; // Offset: 0x48, DWARF: 0x16CCE0
    unsigned int pts_current_spin; // Offset: 0x4C, DWARF: 0x16CD0D
    unsigned int pts_trick; // Offset: 0x50, DWARF: 0x16CD3A
    unsigned int pts_gap; // Offset: 0x54, DWARF: 0x16CD60
    signed int cnt_total_hold; // Offset: 0x58, DWARF: 0x16CD84
    signed int spin_ang; // Offset: 0x5C, DWARF: 0x16CDAF
    signed int last_spin_ang; // Offset: 0x60, DWARF: 0x16CDD4
    signed int airtime_frame; // Offset: 0x64, DWARF: 0x16CDFE
    unsigned int current_set_tp; // Offset: 0x68, DWARF: 0x16CE28
    unsigned int current_set_tp_rate; // Offset: 0x6C, DWARF: 0x16CE53
    signed int link_rate; // Offset: 0x70, DWARF: 0x16CE83
    unsigned int link_trick_point; // Offset: 0x74, DWARF: 0x16CEA9
    unsigned int total_trick_point; // Offset: 0x78, DWARF: 0x16CED6
    unsigned int last_link_trick_point; // Offset: 0x7C, DWARF: 0x16CF04
    unsigned int get_point; // Offset: 0x80, DWARF: 0x16CF36
    signed int total_trick_num; // Offset: 0x84, DWARF: 0x16CF5C
    signed int best_link_num; // Offset: 0x88, DWARF: 0x16CF88
    unsigned int best_link_pts; // Offset: 0x8C, DWARF: 0x16CFB2
    signed int get_the_best; // Offset: 0x90, DWARF: 0x16CFDC
    signed int pre_spin_ang; // Offset: 0x94, DWARF: 0x16D005
} TrickLink;

// Size: 0x10, DWARF: 0x16742C
typedef struct Cmd
{
    signed short type; // Offset: 0x0, DWARF: 0x167447
    char way1; // Offset: 0x2, DWARF: 0x167468
    char way2; // Offset: 0x3, DWARF: 0x167489
    char way3; // Offset: 0x4, DWARF: 0x1674AA
    char way4; // Offset: 0x5, DWARF: 0x1674CB
    unsigned short fin_button; // Offset: 0x6, DWARF: 0x1674EC
    char rev_button; // Offset: 0x8, DWARF: 0x167513
    char inp_fin_button; // Offset: 0x9, DWARF: 0x16753A
    char left_count; // Offset: 0xA, DWARF: 0x167565
    char fin_left_count; // Offset: 0xB, DWARF: 0x16758C
    char step; // Offset: 0xC, DWARF: 0x1675B7
    char ok; // Offset: 0xD, DWARF: 0x1675D8
    char passtime; // Offset: 0xE, DWARF: 0x1675F7
    char tmp; // Offset: 0xF, DWARF: 0x16761C
} Cmd;

// Size: 0x2580, DWARF: 0x168520
typedef struct Act
{
    // Size: 0x1F0, DWARF: 0x16E7E8
    Sbcore sbcore; // Offset: 0x0, DWARF: 0x16853C
    // Size: 0x30, DWARF: 0x16E19B
    Plane wall; // Offset: 0x1F0, DWARF: 0x168561
    signed int cnt_freefoot; // Offset: 0x220, DWARF: 0x168584
    signed int cnt_turn; // Offset: 0x224, DWARF: 0x1685AD
    signed int cnt_sitting; // Offset: 0x228, DWARF: 0x1685D2
    signed int cnt_spinkey; // Offset: 0x22C, DWARF: 0x1685FA
    signed int cnt_d2c; // Offset: 0x230, DWARF: 0x168622
    signed int cnt_to_rail; // Offset: 0x234, DWARF: 0x168646
    signed int cnt_grind; // Offset: 0x238, DWARF: 0x16866E
    signed int cnt_real_grind; // Offset: 0x23C, DWARF: 0x168694
    signed int cnt_manual; // Offset: 0x240, DWARF: 0x1686BF
    signed int cnt_total_grind; // Offset: 0x244, DWARF: 0x1686E6
    signed int cnt_total_manual; // Offset: 0x248, DWARF: 0x168712
    signed int cnt_plant; // Offset: 0x24C, DWARF: 0x16873F
    signed int cnt_holding; // Offset: 0x250, DWARF: 0x168765
    signed int cnt_planttumble; // Offset: 0x254, DWARF: 0x16878D
    signed int cnt_plant2grind; // Offset: 0x258, DWARF: 0x1687B9
    signed int cnt_tumble; // Offset: 0x25C, DWARF: 0x1687E5
    signed int cnt_nospin; // Offset: 0x260, DWARF: 0x16880C
    signed int cnt_brake; // Offset: 0x264, DWARF: 0x168833
    signed int cnt_backward; // Offset: 0x268, DWARF: 0x168859
    signed int cnt_no_bodyhit; // Offset: 0x26C, DWARF: 0x168882
    signed int cnt_hokan; // Offset: 0x270, DWARF: 0x1688AD
    signed int jump_air; // Offset: 0x274, DWARF: 0x1688D3
    signed int def_goofy; // Offset: 0x278, DWARF: 0x1688F8
    signed int goofy; // Offset: 0x27C, DWARF: 0x16891E
    signed int fakie; // Offset: 0x280, DWARF: 0x168940
    // DWARF: 0x16EDE0
    Sliding_State sliding_state; // Offset: 0x284, DWARF: 0x168962
    // DWARF: 0x16EDE0
    Sliding_State pre_state; // Offset: 0x288, DWARF: 0x16898E
    signed int nollie; // Offset: 0x28C, DWARF: 0x1689B6
    signed int big_ollie; // Offset: 0x290, DWARF: 0x1689D9
    signed int super_ollie; // Offset: 0x294, DWARF: 0x1689FF
    signed int plant_to_fakie; // Offset: 0x298, DWARF: 0x168A27
    signed int trick_keep; // Offset: 0x29C, DWARF: 0x168A52
    // DWARF: 0x1681CA
    Tumble_Type tumble_type; // Offset: 0x2A0, DWARF: 0x168A79
    // DWARF: 0x16C25C
    Tumble_Way tumble_way; // Offset: 0x2A4, DWARF: 0x168AA3
    signed int trg_hopup; // Offset: 0x2A8, DWARF: 0x168ACC
    signed int trg_jumpup; // Offset: 0x2AC, DWARF: 0x168AF2
    signed int trg_touch; // Offset: 0x2B0, DWARF: 0x168B19
    signed int trg_bonk; // Offset: 0x2B4, DWARF: 0x168B3F
    signed int trg_boost; // Offset: 0x2B8, DWARF: 0x168B64
    signed int trg_rewind; // Offset: 0x2BC, DWARF: 0x168B8A
    signed int trg_hit_wall; // Offset: 0x2C0, DWARF: 0x168BB1
    signed int no_approach_speed; // Offset: 0x2C4, DWARF: 0x168BDA
    signed int hop_vertical_plane; // Offset: 0x2C8, DWARF: 0x168C08
    signed int touch_perfect; // Offset: 0x2CC, DWARF: 0x168C37
    signed int grind_jump; // Offset: 0x2D0, DWARF: 0x168C61
    signed int grind_tumble; // Offset: 0x2D4, DWARF: 0x168C88
    signed int hips; // Offset: 0x2D8, DWARF: 0x168CB1
    signed int trg_onair_with_over_hp; // Offset: 0x2DC, DWARF: 0x168CD2
    // DWARF: 0x1681CA
    Tumble_Type trg_tumble_type; // Offset: 0x2E0, DWARF: 0x168D05
    // DWARF: 0x16C25C
    Tumble_Way trg_tumble_way; // Offset: 0x2E4, DWARF: 0x168D33
    signed int trg_tumble_body; // Offset: 0x2E8, DWARF: 0x168D60
    signed int end_grind; // Offset: 0x2EC, DWARF: 0x168D8C
    signed int end_manual; // Offset: 0x2F0, DWARF: 0x168DB2
    signed int end_sliding; // Offset: 0x2F4, DWARF: 0x168DD9
    float max_relief_gap; // Offset: 0x2F8, DWARF: 0x168E01
    float relief_gap; // Offset: 0x2FC, DWARF: 0x168E2C
    float slant; // Offset: 0x300, DWARF: 0x168E53
    float side_slant; // Offset: 0x304, DWARF: 0x168E75
    float sp_slant; // Offset: 0x308, DWARF: 0x168E9C
    float sp_side_slant; // Offset: 0x30C, DWARF: 0x168EC1
    float ofs_updown; // Offset: 0x310, DWARF: 0x168EEB
    float target_way; // Offset: 0x314, DWARF: 0x168F12
    float* pre_rail_list; // Offset: 0x318, DWARF: 0x168F39 //float[4]
    float* rail_list; // Offset: 0x31C, DWARF: 0x168F68 //float[4]
    signed int num_rail_vertex; // Offset: 0x320, DWARF: 0x168F93
    signed int rail_id; // Offset: 0x324, DWARF: 0x168FBF
    signed int rail_no; // Offset: 0x328, DWARF: 0x168FE3
    float rail_pos[4] __attribute__((aligned (16))); // Offset: 0x330, DWARF: 0x169007
    // Size: 0x14, DWARF: 0x16ED0C
    Balance gr_balance; // Offset: 0x340, DWARF: 0x16902E
    float gr_enter_ang; // Offset: 0x354, DWARF: 0x169057
    signed int gr_reset_lean; // Offset: 0x358, DWARF: 0x169080
    signed int trg_grind_name; // Offset: 0x35C, DWARF: 0x1690AA
    signed int gr_grind_no; // Offset: 0x360, DWARF: 0x1690D5
    signed int gr_cnt_kissed; // Offset: 0x364, DWARF: 0x1690FD
    signed int gr_is_reverse; // Offset: 0x368, DWARF: 0x169127
    signed int gr_back_accel; // Offset: 0x36C, DWARF: 0x169151
    signed int trg_change_grind; // Offset: 0x370, DWARF: 0x16917B
    signed int changed_grind; // Offset: 0x374, DWARF: 0x1691A8
    signed int disaster; // Offset: 0x378, DWARF: 0x1691D2
    signed int first_grind; // Offset: 0x37C, DWARF: 0x1691F7
    signed int gr_no_jump; // Offset: 0x380, DWARF: 0x16921F
    signed int hp_air; // Offset: 0x384, DWARF: 0x169246
    signed int pre_hp_air; // Offset: 0x388, DWARF: 0x169269
    signed int halfpiping; // Offset: 0x38C, DWARF: 0x169290
    signed int pre_halfpiping; // Offset: 0x390, DWARF: 0x1692B7
    signed int over_hp; // Offset: 0x394, DWARF: 0x1692E2
    signed int hp_jump; // Offset: 0x398, DWARF: 0x169306
    signed int hp_adj_roty; // Offset: 0x39C, DWARF: 0x16932A
    sceVu0FVECTOR hp_normal; // Offset: 0x3A0, DWARF: 0x169352
    sceVu0FVECTOR hp_cross; // Offset: 0x3B0, DWARF: 0x16937A
    signed int manual_ready; // Offset: 0x3C0, DWARF: 0x1693A1
    signed int manual_ready_no; // Offset: 0x3C4, DWARF: 0x1693CA
    signed int manual_cnt_to_play; // Offset: 0x3C8, DWARF: 0x1693F6
    // Size: 0x14, DWARF: 0x16ED0C
    Balance manu_balance; // Offset: 0x3CC, DWARF: 0x169425
    signed int manu_reset_lean; // Offset: 0x3E0, DWARF: 0x169450
    signed int bonk_ready; // Offset: 0x3E4, DWARF: 0x16947C
    signed int bonk_ready_no; // Offset: 0x3E8, DWARF: 0x1694A3
    signed int bonk_goto; // Offset: 0x3EC, DWARF: 0x1694CD
    sceVu0FVECTOR bonk_point; // Offset: 0x3F0, DWARF: 0x1694F3
    sceVu0FVECTOR bonk_presp; // Offset: 0x400, DWARF: 0x16951C
    signed int revert_cnt_ready; // Offset: 0x410, DWARF: 0x169545
    signed int revert_ready_no; // Offset: 0x414, DWARF: 0x169572
    signed int plant_air; // Offset: 0x418, DWARF: 0x16959E
    float plant_normal[4] __attribute__((aligned (16))); // Offset: 0x420, DWARF: 0x1695C4
    float max_height; // Offset: 0x430, DWARF: 0x1695EF
    signed int big_air; // Offset: 0x434, DWARF: 0x169616
    signed int cnt_onair; // Offset: 0x438, DWARF: 0x16963A
    signed int cnt_onair2; // Offset: 0x43C, DWARF: 0x169660
    signed int cnt_nothit; // Offset: 0x440, DWARF: 0x169687
    signed int tumble_se_id; // Offset: 0x444, DWARF: 0x1696AE
    float jump_rot_pole; // Offset: 0x448, DWARF: 0x1696D7
    float last_rot_pole; // Offset: 0x44C, DWARF: 0x169701
    // DWARF: 0x16D48D
    ESP_Spin_Way last_spin_way; // Offset: 0x450, DWARF: 0x16972B
    float pos_waist[4] __attribute__((aligned (16))); // Offset: 0x460, DWARF: 0x169757
    float pos_disp[4]; // Offset: 0x470, DWARF: 0x16977F
    float shadow_posy; // Offset: 0x480, DWARF: 0x1697A6
    float max_speed; // Offset: 0x484, DWARF: 0x1697CE
    float cmn_max_speed; // Offset: 0x488, DWARF: 0x1697F4
    float now_max_speed; // Offset: 0x48C, DWARF: 0x16981E
    // Size: 0x24, DWARF: 0x16B853
    Param2 param; // Offset: 0x490, DWARF: 0x169848
    // Size: 0x1C, DWARF: 0x16D2B9
    Character_Param chr_param_x10; // Offset: 0x4B4, DWARF: 0x16986C
    // Size: 0x10, DWARF: 0x16DA24
    Board_Param brd_param_x10; // Offset: 0x4D0, DWARF: 0x169898
    signed int mot_finish; // Offset: 0x4E0, DWARF: 0x1698C4
    signed int mot_grabing; // Offset: 0x4E4, DWARF: 0x1698EB
    signed int mot_flipping; // Offset: 0x4E8, DWARF: 0x169913
    signed int mot_spflipping; // Offset: 0x4EC, DWARF: 0x16993C
    signed int mot_grinding; // Offset: 0x4F0, DWARF: 0x169967
    signed int mot_planting; // Offset: 0x4F4, DWARF: 0x169990
    signed int mot_manualing; // Offset: 0x4F8, DWARF: 0x1699B9
    signed int mot_reverting; // Offset: 0x4FC, DWARF: 0x1699E3
    signed int mot_bonking; // Offset: 0x500, DWARF: 0x169A0D
    signed int mot_tumbling; // Offset: 0x504, DWARF: 0x169A35
    signed int mot_reserve_tumble_standup; // Offset: 0x508, DWARF: 0x169A5E
    signed int mot_tumble_standup; // Offset: 0x50C, DWARF: 0x169A95
    signed int mot_tumble_standup_already; // Offset: 0x510, DWARF: 0x169AC4
    signed int mot_end_tumble; // Offset: 0x514, DWARF: 0x169AFB
    float mot_flip_rot[4] __attribute__((aligned (16))); // Offset: 0x520, DWARF: 0x169B26
    float mot_flip_roty_base; // Offset: 0x530, DWARF: 0x169B51
    signed int mot_flip_mode; // Offset: 0x534, DWARF: 0x169B80
    // Size: 0x98, DWARF: 0x16C9D1
    TrickLink trick_link; // Offset: 0x538, DWARF: 0x169BAA
    signed int trk_doing; // Offset: 0x5D0, DWARF: 0x169BD3
    // DWARF: 0x16C76D
    ETS_Trick_State trk_state; // Offset: 0x5D4, DWARF: 0x169BF9
    signed int trk_grab_no; // Offset: 0x5D8, DWARF: 0x169C21
    signed int trk_trick_no; // Offset: 0x5DC, DWARF: 0x169C49
    // DWARF: 0x16D779
    Trick_Link_State trk_link_state; // Offset: 0x5E0, DWARF: 0x169C72
    signed int num_set_gap; // Offset: 0x5E4, DWARF: 0x169C9F
    signed short set_gap[64]; // Offset: 0x5E8, DWARF: 0x169CC7
    signed int special_num; // Offset: 0x668, DWARF: 0x169CED
    signed int special_charge; // Offset: 0x66C, DWARF: 0x169D15
    signed int special_charge_cnt; // Offset: 0x670, DWARF: 0x169D40
    signed int special_charge_maxcnt; // Offset: 0x674, DWARF: 0x169D6F
    signed int special_left_time; // Offset: 0x678, DWARF: 0x169DA1
    signed int special_total_time; // Offset: 0x67C, DWARF: 0x169DCF
    signed int special_remainder_tp; // Offset: 0x680, DWARF: 0x169DFE
    signed int boost; // Offset: 0x684, DWARF: 0x169E2F
    signed int boost_num; // Offset: 0x688, DWARF: 0x169E51
    signed int boost_charge; // Offset: 0x68C, DWARF: 0x169E77
    signed int boost_left_time; // Offset: 0x690, DWARF: 0x169EA0
    signed int boost_total_time; // Offset: 0x694, DWARF: 0x169ECC
    signed int balance_cnt_adj; // Offset: 0x698, DWARF: 0x169EF9
    float balance_ang_adj; // Offset: 0x69C, DWARF: 0x169F25
    float balance_roty_adj; // Offset: 0x6A0, DWARF: 0x169F51
    signed int balance_bigair; // Offset: 0x6A4, DWARF: 0x169F7E
    float balance_pole[4] __attribute__((aligned (16))); // Offset: 0x6B0, DWARF: 0x169FA9
    float hang_rate; // Offset: 0x6C0, DWARF: 0x169FD4
    signed int num_hit; // Offset: 0x6C4, DWARF: 0x169FFA
    signed int num_vec; // Offset: 0x6C8, DWARF: 0x16A01E
    signed int num_obj; // Offset: 0x6CC, DWARF: 0x16A042
    // Size: 0x60, DWARF: 0x168242
    Col col_hit[16]; // Offset: 0x6D0, DWARF: 0x16A066
    // Size: 0x60, DWARF: 0x168242
    Col col_vec[16]; // Offset: 0xCD0, DWARF: 0x16A08C
    // Size: 0x60, DWARF: 0x168242
    Col col_obj[16]; // Offset: 0x12D0, DWARF: 0x16A0B2
    signed int reserve_tumble; // Offset: 0x18D0, DWARF: 0x16A0D8
    float reserve_tumble_ang; // Offset: 0x18D4, DWARF: 0x16A103
    float reserve_tumble_speed; // Offset: 0x18D8, DWARF: 0x16A132
    // DWARF: 0x1681CA
    Tumble_Type reserve_tumble_type; // Offset: 0x18DC, DWARF: 0x16A163
    signed int reserve_trick_no[16]; // Offset: 0x18E0, DWARF: 0x16A195
    signed int reserve_trick_is_flip[16]; // Offset: 0x1920, DWARF: 0x16A1C4
    signed int reserve_trick_is_special[16]; // Offset: 0x1960, DWARF: 0x16A1F8
    signed int num_reserve_trick; // Offset: 0x19A0, DWARF: 0x16A22F
    signed int top_reserve_trick; // Offset: 0x19A4, DWARF: 0x16A25D
    signed int reserve_stance_change; // Offset: 0x19A8, DWARF: 0x16A28B
    signed int num_reserve_grab; // Offset: 0x19AC, DWARF: 0x16A2BD
    unsigned char num_play_trick[2][160]; // Offset: 0x19B0, DWARF: 0x16A2EA
    unsigned char num_play_trick_in_link[2][160]; // Offset: 0x1AF0, DWARF: 0x16A317
    sceVu0FMATRIX mat_head; // Offset: 0x1C30, DWARF: 0x16A34C
    float mat_hip[4][4]; // Offset: 0x1C70, DWARF: 0x16A373
    // Size: 0x60, DWARF: 0x168242
    Col col_rail; // Offset: 0x1CB0, DWARF: 0x16A399
    // Size: 0x60, DWARF: 0x168242
    Col col_plant; // Offset: 0x1D10, DWARF: 0x16A3C0
    // Size: 0x60, DWARF: 0x168242
    Col col_hp; // Offset: 0x1D70, DWARF: 0x16A3E8
    // Size: 0x60, DWARF: 0x168242
    Col col_zhp; // Offset: 0x1DD0, DWARF: 0x16A40D
    sceVu0FVECTOR recover_pos; // Offset: 0x1E30, DWARF: 0x16A433
    float recover_roty; // Offset: 0x1E40, DWARF: 0x16A45D
    float recover_speed; // Offset: 0x1E44, DWARF: 0x16A486
    signed int recover; // Offset: 0x1E48, DWARF: 0x16A4B0
    signed int trg_recovered; // Offset: 0x1E4C, DWARF: 0x16A4D4
    signed int reserve_fall; // Offset: 0x1E50, DWARF: 0x16A4FE
    signed int cnt_fall; // Offset: 0x1E54, DWARF: 0x16A527
    signed int cnt_warp; // Offset: 0x1E58, DWARF: 0x16A54C
    signed int water_manual; // Offset: 0x1E5C, DWARF: 0x16A571
    signed int sptrk[2]; // Offset: 0x1E60, DWARF: 0x16A59A
    signed int num_total_gap; // Offset: 0x1E68, DWARF: 0x16A5BE
    signed int num_total_break; // Offset: 0x1E6C, DWARF: 0x16A5E8
    signed int reserve_quit; // Offset: 0x1E70, DWARF: 0x16A614
    signed int allow_tlink; // Offset: 0x1E74, DWARF: 0x16A63D
    signed int no_trick; // Offset: 0x1E78, DWARF: 0x16A665
    signed int trg_quit; // Offset: 0x1E7C, DWARF: 0x16A68A
    signed int cnt_quit; // Offset: 0x1E80, DWARF: 0x16A6AF
    signed int cnt_reserve_quit; // Offset: 0x1E84, DWARF: 0x16A6D4
    signed int pass_finish_line; // Offset: 0x1E88, DWARF: 0x16A701
    signed int pass_finish_line2; // Offset: 0x1E8C, DWARF: 0x16A72E
    signed int wait_motion; // Offset: 0x1E90, DWARF: 0x16A75C
    signed int wait_vs; // Offset: 0x1E94, DWARF: 0x16A784
    signed int noheight_reflect; // Offset: 0x1E98, DWARF: 0x16A7A8
    signed int cnt_noheight_reflect; // Offset: 0x1E9C, DWARF: 0x16A7D5
    signed int cnt_brank_noheight_reflect; // Offset: 0x1EA0, DWARF: 0x16A806
    signed int forced_bailout; // Offset: 0x1EA4, DWARF: 0x16A83D
    signed int cnt_hit_wall; // Offset: 0x1EA8, DWARF: 0x16A868
    signed int cnt_brank_hit_wall; // Offset: 0x1EAC, DWARF: 0x16A891
    signed int cnt_forced_bailout; // Offset: 0x1EB0, DWARF: 0x16A8C0
    float last_hit_plane[10][4] __attribute__((aligned (16))); // Offset: 0x1EC0, DWARF: 0x16A8EF
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_trick[25]; // Offset: 0x1F60, DWARF: 0x16A91C
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_flip[25]; // Offset: 0x20F0, DWARF: 0x16A944
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_grind[13]; // Offset: 0x2280, DWARF: 0x16A96B
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_plant[9]; // Offset: 0x2350, DWARF: 0x16A993
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_bonk[9]; // Offset: 0x23E0, DWARF: 0x16A9BB
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_manual[9]; // Offset: 0x2470, DWARF: 0x16A9E2
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_jump[4]; // Offset: 0x2500, DWARF: 0x16AA0B
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_sptrk[2]; // Offset: 0x2540, DWARF: 0x16AA32
    // Size: 0x10, DWARF: 0x16742C
    Cmd cmd_revert[2]; // Offset: 0x2560, DWARF: 0x16AA5A
} Act;

// Size: 0x2C, DWARF: 0x16DF3B
typedef struct MotFrames
{
    signed int id; // Offset: 0x0, DWARF: 0x16DF57
    signed int uad; // Offset: 0x4, DWARF: 0x16DF76
    signed int num_frame; // Offset: 0x8, DWARF: 0x16DF96
    signed int frame; // Offset: 0xC, DWARF: 0x16DFBC
    signed int target_frame; // Offset: 0x10, DWARF: 0x16DFDE
    signed int nloop; // Offset: 0x14, DWARF: 0x16E007
    signed int inter_frame; // Offset: 0x18, DWARF: 0x16E029
    signed int inter_count; // Offset: 0x1C, DWARF: 0x16E051
    signed int brend; // Offset: 0x20, DWARF: 0x16E079
    float adj_rot; // Offset: 0x24, DWARF: 0x16E09B
    signed int cannot_control; // Offset: 0x28, DWARF: 0x16E0BF
} MotFrames;

// Size: 0x20, DWARF: 0x16E73E
typedef struct KeyList
{
    float rot[4]; // Offset: 0x0, DWARF: 0x16E75A
    signed int frame; // Offset: 0x10, DWARF: 0x16E77C
    signed int pad; // Offset: 0x14, DWARF: 0x16E79E
} KeyList;

// DWARF: 0x16ECC4
typedef enum FlipMode
{
    eflReady,
    eflFlipping,
    eflEnd
} FlipMode;

// Size: 0x50, DWARF: 0x16F172
typedef struct Flip
{
    // Size: 0x20, DWARF: 0x16E73E
    KeyList* key_list; // Offset: 0x0, DWARF: 0x16F18E
    char padding[11]; // pads now to the expected 0x10 offset, not originally in struct
    // Size: 0x20, DWARF: 0x16E73E
    KeyList now; // Offset: 0x10, DWARF: 0x16F1B8
    signed int num_key; // Offset: 0x30, DWARF: 0x16F1DA
    signed int num_frame; // Offset: 0x34, DWARF: 0x16F1FE
    // DWARF: 0x16ECC4
    FlipMode flipmode; // Offset: 0x38, DWARF: 0x16F224
    signed int mot_id; // Offset: 0x3C, DWARF: 0x16F24B
    signed int play_mot; // Offset: 0x40, DWARF: 0x16F26E
    int padding2[5]; // not originally in struct, pads to intended 0x50 size.
} Flip __attribute__((aligned(16)));

// Size: 0x190, DWARF: 0x1677E9
typedef struct Mot
{
    // Size: 0x2C, DWARF: 0x16DF3B
    MotFrames now; // Offset: 0x0, DWARF: 0x167804
    // Size: 0x2C, DWARF: 0x16DF3B
    MotFrames next; // Offset: 0x2C, DWARF: 0x167826
    // Size: 0x2C, DWARF: 0x16DF3B
    MotFrames pre; // Offset: 0x58, DWARF: 0x167849
    // Size: 0x2C, DWARF: 0x16DF3B
    MotFrames pre2; // Offset: 0x84, DWARF: 0x16786B
    // Size: 0x2C, DWARF: 0x16DF3B
    MotFrames now2; // Offset: 0xB0, DWARF: 0x16788E
    // Size: 0x2C, DWARF: 0x16DF3B
    MotFrames next2; // Offset: 0xDC, DWARF: 0x1678B1
    // Size: 0x50, DWARF: 0x16F172
    Flip flip; // Offset: 0x110, DWARF: 0x1678D5
    signed int cnt_ik_foot; // Offset: 0x160, DWARF: 0x1678F8
    signed int freemotion; // Offset: 0x164, DWARF: 0x167920
    signed int ik; // Offset: 0x168, DWARF: 0x167947
    signed int reserve_schange; // Offset: 0x16C, DWARF: 0x167966
    signed int reserve_brending_schange; // Offset: 0x170, DWARF: 0x167992
    signed int motion_speed; // Offset: 0x174, DWARF: 0x1679C7
    signed int mot_sp_flip; // Offset: 0x178, DWARF: 0x1679F0
    signed int trg_to_calc_flip; // Offset: 0x17C, DWARF: 0x167A18
    signed int to_calc_flip; // Offset: 0x180, DWARF: 0x167A45
    // int padding[7]; // not originally in struct, this pads the struct to the intended 0x190 size
} Mot;

// DWARF: 0x16840A
typedef enum Ripside
{
    ersNoRip,
    ersLeft,
    ersRight
} Ripside;

// Size: 0x190, DWARF: 0x16B9B7
typedef struct Cam
{
    float pre_speed[4]; // Offset: 0x0, DWARF: 0x16B9D3
    float now_speed[4]; // Offset: 0x10, DWARF: 0x16B9FB
    float normal_speed[4]; // Offset: 0x20, DWARF: 0x16BA23
    float rot[4]; // Offset: 0x30, DWARF: 0x16BA4E
    float pos_waist[4]; // Offset: 0x40, DWARF: 0x16BA70
    float pos_disp[4]; // Offset: 0x50, DWARF: 0x16BA98
    // Size: 0x60, DWARF: 0x16E55B
    Pos pos __attribute__((aligned (16))); // Offset: 0x60, DWARF: 0x16BABF
    // Size: 0x60, DWARF: 0x16E55B
    Pos prepos __attribute__((aligned (16))); // Offset: 0xC0, DWARF: 0x16BAE1
    // DWARF: 0x16840A
    Ripside ripside; // Offset: 0x120, DWARF: 0x16BB06
    // DWARF: 0x16EDE0
    Sliding_State sliding_state; // Offset: 0x124, DWARF: 0x16BB2C
    // DWARF: 0x16EDE0
    Sliding_State pre_state; // Offset: 0x128, DWARF: 0x16BB58
    // DWARF: 0x16EDE0
    Sliding_State pre_tumble_state; // Offset: 0x12C, DWARF: 0x16BB80
    float max_height; // Offset: 0x130, DWARF: 0x16BBAF
    signed int cnt_onair; // Offset: 0x134, DWARF: 0x16BBD6
    signed int cnt_turn; // Offset: 0x138, DWARF: 0x16BBFC
    float max_speed; // Offset: 0x13C, DWARF: 0x16BC21
    signed int hp_air; // Offset: 0x140, DWARF: 0x16BC47
    float splen_prejump; // Offset: 0x144, DWARF: 0x16BC6A
    // DWARF: 0x1681CA
    Tumble_Type tumble_type; // Offset: 0x148, DWARF: 0x16BC94
    // DWARF: 0x16C25C
    Tumble_Way tumble_way; // Offset: 0x14C, DWARF: 0x16BCBE
    // DWARF: 0x1681CA
    Tumble_Type trg_tumble_type; // Offset: 0x150, DWARF: 0x16BCE7
    signed int trg_tumble_standup; // Offset: 0x154, DWARF: 0x16BD15
    float grind_enter_ang; // Offset: 0x158, DWARF: 0x16BD44
    signed int trick_link; // Offset: 0x15C, DWARF: 0x16BD70
    signed int trg_start_endmot; // Offset: 0x160, DWARF: 0x16BD97
    signed int trg_recovered; // Offset: 0x164, DWARF: 0x16BDC4
    signed int trg_hopup; // Offset: 0x168, DWARF: 0x16BDEE
    signed int trg_jumpup; // Offset: 0x16C, DWARF: 0x16BE14
    signed int trg_touch; // Offset: 0x170, DWARF: 0x16BE3B
    signed int trg_boost; // Offset: 0x174, DWARF: 0x16BE61
    signed int bonk_goto; // Offset: 0x178, DWARF: 0x16BE87
    signed int trg_plant; // Offset: 0x17C, DWARF: 0x16BEAD
    signed int grind_goto; // Offset: 0x180, DWARF: 0x16BED3
    signed int padding[3]; // not originally in struct, pads size to 0x190
} Cam;

// Size: 0x14, DWARF: 0x16D54F
typedef struct Se
{
    float splen; // Offset: 0x0, DWARF: 0x16D56B
    float rot_pole; // Offset: 0x4, DWARF: 0x16D58D
    float anggap_sp_brd; // Offset: 0x8, DWARF: 0x16D5B2
    float anggap_board_rot; // Offset: 0xC, DWARF: 0x16D5DC
    signed int side_slide; // Offset: 0x10, DWARF: 0x16D609
} Se __attribute__((aligned(16)));

// Size: 0x24, DWARF: 0x167A72
typedef struct Key
{
    signed int vibration; // Offset: 0x0, DWARF: 0x167A8D
    signed int spin_l; // Offset: 0x4, DWARF: 0x167AB3
    signed int spin_r; // Offset: 0x8, DWARF: 0x167AD6
    signed int stance; // Offset: 0xC, DWARF: 0x167AF9
    signed int revert; // Offset: 0x10, DWARF: 0x167B1C
    signed int grind; // Offset: 0x14, DWARF: 0x167B3F
    signed int grab; // Offset: 0x18, DWARF: 0x167B61
    signed int jump; // Offset: 0x1C, DWARF: 0x167B82
    signed int flip; // Offset: 0x20, DWARF: 0x167BA3
} Key;

// Size: 0x30, DWARF: 0x167BEE
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x167C09
    signed int always_sp; // Offset: 0x4, DWARF: 0x167C2A
    signed int perfect_b; // Offset: 0x8, DWARF: 0x167C50
    signed int super_spin; // Offset: 0xC, DWARF: 0x167C76
    signed int half_g; // Offset: 0x10, DWARF: 0x167C9D
    signed int fast_motion; // Offset: 0x14, DWARF: 0x167CC0
    signed int super_speed; // Offset: 0x18, DWARF: 0x167CE8
    signed int big_head; // Offset: 0x1C, DWARF: 0x167D10
    signed int metallic; // Offset: 0x20, DWARF: 0x167D35
    signed int mirror; // Offset: 0x24, DWARF: 0x167D5A
    signed int replay_view; // Offset: 0x28, DWARF: 0x167D7D
    signed int partition; // Offset: 0x2C, DWARF: 0x167DA5
} Cheats;

// Size: 0x30, DWARF: 0x16C801
typedef struct ScreenInfo
{
    float aspect_x; // Offset: 0x0, DWARF: 0x16C81D
    float aspect_y; // Offset: 0x4, DWARF: 0x16C842
    float center_x; // Offset: 0x8, DWARF: 0x16C867
    float center_y; // Offset: 0xC, DWARF: 0x16C88C
    float clip_vol_x; // Offset: 0x10, DWARF: 0x16C8B1
    float clip_vol_y; // Offset: 0x14, DWARF: 0x16C8D8
    float min_z; // Offset: 0x18, DWARF: 0x16C8FF
    float max_z; // Offset: 0x1C, DWARF: 0x16C921
    float near_z; // Offset: 0x20, DWARF: 0x16C943
    float far_z; // Offset: 0x24, DWARF: 0x16C966
    float screen_z; // Offset: 0x28, DWARF: 0x16C988
    float res; // Offset: 0x2C, DWARF: 0x16C9AD
} ScreenInfo;

// Size: 0x20, DWARF: 0x16D961
typedef struct Fog
{
    float min; // Offset: 0x0, DWARF: 0x16D97D
    float max; // Offset: 0x4, DWARF: 0x16D99D
    float far; // Offset: 0x8, DWARF: 0x16D9BD
    float near; // Offset: 0xC, DWARF: 0x16D9DD
    signed int col[4]; // Offset: 0x10, DWARF: 0x16D9FE
} Fog;

// Size: 0x140, DWARF: 0x16DBF7
typedef struct Matrix
{
    sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x16DC13
    sceVu0FMATRIX local_light; // Offset: 0x40, DWARF: 0x16DC3E
    sceVu0FMATRIX light_color; // Offset: 0x80, DWARF: 0x16DC68
    sceVu0FMATRIX local_clip; // Offset: 0xC0, DWARF: 0x16DC92
    sceVu0FMATRIX clip_screen; // Offset: 0x100, DWARF: 0x16DCBB
} Matrix;

// Size: 0x340, DWARF: 0x167DF5
typedef struct SysMat
{
    // Size: 0x30, DWARF: 0x16C801
    ScreenInfo scr_info; // Offset: 0x0, DWARF: 0x167E10
    // Size: 0x20, DWARF: 0x16D961
    Fog fog; // Offset: 0x30, DWARF: 0x167E37
    // Size: 0x140, DWARF: 0x16DBF7
    Matrix matrix; // Offset: 0x50, DWARF: 0x167E59
    sceVu0FMATRIX world_screen; // Offset: 0x190, DWARF: 0x167E7E
    sceVu0FMATRIX world_view; // Offset: 0x1D0, DWARF: 0x167EA9
    sceVu0FMATRIX view_screen; // Offset: 0x210, DWARF: 0x167ED2
    sceVu0FMATRIX light_color; // Offset: 0x250, DWARF: 0x167EFC
    sceVu0FMATRIX normal_light; // Offset: 0x290, DWARF: 0x167F26
    sceVu0FMATRIX view_clip; // Offset: 0x2D0, DWARF: 0x167F51
    sceVu0FVECTOR cam_rot; // Offset: 0x310, DWARF: 0x167F79
    sceVu0FVECTOR cam_trans; // Offset: 0x320, DWARF: 0x167F9F
    float view_angle; // Offset: 0x330, DWARF: 0x167FC7
} SysMat;

// Size: 0x2C00, DWARF: 0x16AA87
typedef struct Ctrl
{
    float rot[4]; // Offset: 0x0, DWARF: 0x16AAA3
    float speed[4]; // Offset: 0x10, DWARF: 0x16AAC5
    float pole[4]; // Offset: 0x20, DWARF: 0x16AAE9
    float nor_pole[4]; // Offset: 0x30, DWARF: 0x16AB0C
    float disp_pole[4]; // Offset: 0x40, DWARF: 0x16AB33
    float rot_pole; // Offset: 0x50, DWARF: 0x16AB5B
    float disp_rot_pole; // Offset: 0x54, DWARF: 0x16AB80
    float disp_rot_foot; // Offset: 0x58, DWARF: 0x16ABAA
    signed int disp_rot_foot_is_x; // Offset: 0x5C, DWARF: 0x16ABD4
    float disp_pos[4]; // Offset: 0x60, DWARF: 0x16AC03
    float disp_pos_ofs[4]; // Offset: 0x70, DWARF: 0x16AC2A
    float disp_rot_z_ofs; // Offset: 0x80, DWARF: 0x16AC55
    float slant_pole; // Offset: 0x84, DWARF: 0x16AC80
    float splen; // Offset: 0x88, DWARF: 0x16ACA7
    float splenxz; // Offset: 0x8C, DWARF: 0x16ACC9
    // Size: 0x60, DWARF: 0x16E55B
    Pos prepos2 __attribute__((aligned (16))); // Offset: 0x90, DWARF: 0x16ACED
    // Size: 0x60, DWARF: 0x16E55B
    Pos prepos __attribute__((aligned (16))); // Offset: 0xF0, DWARF: 0x16AD13
    // Size: 0x60, DWARF: 0x16E55B
    Pos nowpos __attribute__((aligned (16))); // Offset: 0x150, DWARF: 0x16AD38
    // Size: 0x60, DWARF: 0x16E55B
    Pos nextpos __attribute__((aligned (16))); // Offset: 0x1B0, DWARF: 0x16AD5D
    // Size: 0x8, DWARF: 0x168106
    Pad nowpad __attribute__((aligned (16))); // Offset: 0x210, DWARF: 0x16AD83
    // Size: 0x8, DWARF: 0x168106
    Pad prepad; // Offset: 0x218, DWARF: 0x16ADA8
    // Size: 0x3C, DWARF: 0x16B0EF
    Inp nowinp; // Offset: 0x220, DWARF: 0x16ADCD
    // Size: 0x3C, DWARF: 0x16B0EF
    Inp preinp; // Offset: 0x25C, DWARF: 0x16ADF2
    // Size: 0x48, DWARF: 0x16EEA4
    Req nowreq; // Offset: 0x298, DWARF: 0x16AE17
    // Size: 0x48, DWARF: 0x16EEA4
    Req prereq; // Offset: 0x2E0, DWARF: 0x16AE3C
    // Size: 0x2580, DWARF: 0x168520
    Act act; // Offset: 0x330, DWARF: 0x16AE61
    // Size: 0x190, DWARF: 0x1677E9
    Mot mot; // Offset: 0x28B0, DWARF: 0x16AE83
    // Size: 0x190, DWARF: 0x16B9B7
    Cam cam; // Offset: 0x2A40, DWARF: 0x16AEA5
    // Size: 0x14, DWARF: 0x16D54F
    Se se __attribute__((aligned(16))); // Offset: 0x2BD0, DWARF: 0x16AEC7
    // Size: 0x3C, DWARF: 0x167640
    Rider_State* param; // Offset: 0x2BE4, DWARF: 0x16AEE8
    // Size: 0x24, DWARF: 0x167A72
    Key* key; // Offset: 0x2BE8, DWARF: 0x16AF0F
    // Size: 0x30, DWARF: 0x167BEE
    Cheats* cheats; // Offset: 0x2BEC, DWARF: 0x16AF34
    // Size: 0x340, DWARF: 0x167DF5
    SysMat* sys_mat; // Offset: 0x2BF0, DWARF: 0x16AF5C
} Ctrl;

// Size: 0x34, DWARF: 0x1671F4
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x16720F
    signed int player; // Offset: 0x4, DWARF: 0x16722E
    signed int base_attr; // Offset: 0x8, DWARF: 0x167251
    signed int nvector; // Offset: 0xC, DWARF: 0x167277
    signed int nhit; // Offset: 0x10, DWARF: 0x16729B
    signed int nobj; // Offset: 0x14, DWARF: 0x1672BC
    signed int rail; // Offset: 0x18, DWARF: 0x1672DD
    signed int old_rail; // Offset: 0x1C, DWARF: 0x1672FE
    signed int res; // Offset: 0x20, DWARF: 0x167323
    // Size: 0x60, DWARF: 0x168242
    Col* vector; // Offset: 0x24, DWARF: 0x167343
    // Size: 0x60, DWARF: 0x168242
    Col* hit; // Offset: 0x28, DWARF: 0x16736B
    // Size: 0x60, DWARF: 0x168242
    Col* object; // Offset: 0x2C, DWARF: 0x167390
    // Size: 0x2C00, DWARF: 0x16AA87
    Ctrl* ctrl; // Offset: 0x30, DWARF: 0x1673B8
} Character; // Offset: 0x10, DWARF: 0x16779A

// Size: 0x10, DWARF: 0x16F421
typedef struct Course
{
    // Size: 0x20, DWARF: 0x16D961
    Fog* fog; // Offset: 0x0, DWARF: 0x16F43D
    signed int no; // Offset: 0x4, DWARF: 0x16F462
    signed int res[2]; // Offset: 0x8, DWARF: 0x16F481
} Course;

// Size: 0x14, DWARF: 0x16B6B6
typedef struct Game
{
    signed int player; // Offset: 0x0, DWARF: 0x16B6D2
    signed int nplayer; // Offset: 0x4, DWARF: 0x16B6F5
    signed int pause; // Offset: 0x8, DWARF: 0x16B719
    signed int mode; // Offset: 0xC, DWARF: 0x16B73B
    signed int wid; // Offset: 0x10, DWARF: 0x16B75C
} Game;

// Size: 0x8C, DWARF: 0x16775A
typedef struct Event
{
    // Size: 0x10, DWARF: 0x16F421
    Course course; // Offset: 0x0, DWARF: 0x167775
    // Size: 0x34, DWARF: 0x1671F4
    Character character[2]; // Offset: 0x10, DWARF: 0x16779A
    // Size: 0x14, DWARF: 0x16B6B6
    Game game; // Offset: 0x78, DWARF: 0x1677C2
} Event;

// Size: 0xA0, DWARF: 0x16D032
typedef struct Vspev01SmokeInfo
{
    float vec[4]; // Offset: 0x0, DWARF: 0x16D04E
    float normal[4]; // Offset: 0x10, DWARF: 0x16D070
    float mov[4]; // Offset: 0x20, DWARF: 0x16D095
    float size[4]; // Offset: 0x30, DWARF: 0x16D0B7
    float szadd[4]; // Offset: 0x40, DWARF: 0x16D0DA
    float gravity[4]; // Offset: 0x50, DWARF: 0x16D0FE
    signed int col[4]; // Offset: 0x60, DWARF: 0x16D124
    float acc; // Offset: 0x70, DWARF: 0x16D146
    float tld; // Offset: 0x74, DWARF: 0x16D166
    signed int abe; // Offset: 0x78, DWARF: 0x16D186
    signed int add; // Offset: 0x7C, DWARF: 0x16D1A6
    signed int sub; // Offset: 0x80, DWARF: 0x16D1C6
    unsigned int frm; // Offset: 0x84, DWARF: 0x16D1E6
    unsigned int state; // Offset: 0x88, DWARF: 0x16D206
    unsigned long time; // Offset: 0x90, DWARF: 0x16D228
    int padding[2]; // not originally in struct, but pads struct to size 0xA0
} Vspev01SmokeInfo;

// Size: 0x10, DWARF: 0x16B535
typedef struct TexData
{
    signed short tofs; // Offset: 0x0, DWARF: 0x16B551
    signed short cofs; // Offset: 0x2, DWARF: 0x16B572
    signed short width; // Offset: 0x4, DWARF: 0x16B593
    signed short height; // Offset: 0x6, DWARF: 0x16B5B5
    signed short tw; // Offset: 0x8, DWARF: 0x16B5D8
    signed short th; // Offset: 0xA, DWARF: 0x16B5F7
    signed short image_bit; // Offset: 0xC, DWARF: 0x16B616
    signed short clut_bit; // Offset: 0xE, DWARF: 0x16B63C
} TexData;

// Size: 0x10, DWARF: 0x168450
typedef struct TexGroup
{
    signed int group; // Offset: 0x0, DWARF: 0x16846C
    signed int no; // Offset: 0x4, DWARF: 0x16848E
    signed int tex_no; // Offset: 0x8, DWARF: 0x1684AD
    // Size: 0x10, DWARF: 0x16B535
    TexData* data; // Offset: 0xC, DWARF: 0x1684D0
} TexGroup;

// Size: 0x28, DWARF: 0x16B780
typedef struct Vspev01Shutter
{
    // Size: 0x10, DWARF: 0x168450
    TexGroup src; // Offset: 0x0, DWARF: 0x16B79C
    // Size: 0x10, DWARF: 0x168450
    TexGroup work; // Offset: 0x10, DWARF: 0x16B7BE
    signed int scroll_x; // Offset: 0x20, DWARF: 0x16B7E1
    signed int scroll_y; // Offset: 0x24, DWARF: 0x16B806
} Vspev01Shutter;

// Size: 0x10, DWARF: 0x16D7D2
typedef union T3
{
    unsigned __int128 ul128; // Offset: 0x0, DWARF: 0x16D7EE
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0x16D810
    unsigned int ui[4]; // Offset: 0x0, DWARF: 0x16D831
    unsigned short us[8]; // Offset: 0x0, DWARF: 0x16D852
    unsigned char uc[16]; // Offset: 0x0, DWARF: 0x16D873
    signed __int128 sl128; // Offset: 0x0, DWARF: 0x16D894
    signed long sl[2]; // Offset: 0x0, DWARF: 0x16D8B6
    signed int si[4]; // Offset: 0x0, DWARF: 0x16D8D7
    signed short ss[8]; // Offset: 0x0, DWARF: 0x16D8F8
    signed char sc[16]; // Offset: 0x0, DWARF: 0x16D919
    float fvec[4]; // Offset: 0x0, DWARF: 0x16D93A
} T3;

// Size: 0x80, DWARF: 0x16B360
typedef struct SmokeBuf
{
    float vec[4]; // Offset: 0x0, DWARF: 0x16B37C
    float mov[4]; // Offset: 0x10, DWARF: 0x16B39E
    float size[4]; // Offset: 0x20, DWARF: 0x16B3C0
    float szadd[4]; // Offset: 0x30, DWARF: 0x16B3E3
    float gravity[4]; // Offset: 0x40, DWARF: 0x16B407
    signed int col[4]; // Offset: 0x50, DWARF: 0x16B42D
    signed int abe; // Offset: 0x60, DWARF: 0x16B44F
    signed int abe_; // Offset: 0x64, DWARF: 0x16B46F
    signed int add; // Offset: 0x68, DWARF: 0x16B490
    signed int sub; // Offset: 0x6C, DWARF: 0x16B4B0
    float acc; // Offset: 0x70, DWARF: 0x16B4D0
    char f0; // Offset: 0x74, DWARF: 0x16B4F0
    char entry; // Offset: 0x75, DWARF: 0x16B50F
} SmokeBuf;

// Size: 0x20, DWARF: 0x16C2FB
typedef struct Vspev01Smoke
{
    // Size: 0x10, DWARF: 0x16D7D2
    T3 t3; // Offset: 0x0, DWARF: 0x16C317
    // Size: 0x80, DWARF: 0x16B360
    SmokeBuf* buf; // Offset: 0x10, DWARF: 0x16C338
    unsigned int size; // Offset: 0x14, DWARF: 0x16C35D
    unsigned int max; // Offset: 0x18, DWARF: 0x16C37E
    unsigned int index; // Offset: 0x1C, DWARF: 0x16C39E
} Vspev01Smoke;

// Size: 0x70, DWARF: 0x16C02F
typedef struct EventMdl
{
    float pos[4]; // Offset: 0x0, DWARF: 0x16C04B
    float matrix[4][4]; // Offset: 0x10, DWARF: 0x16C06D
    signed int no; // Offset: 0x50, DWARF: 0x16C092
    signed int id; // Offset: 0x54, DWARF: 0x16C0B1
    float frame; // Offset: 0x58, DWARF: 0x16C0D0
    signed int draw; // Offset: 0x5C, DWARF: 0x16C0F2
    signed int light; // Offset: 0x60, DWARF: 0x16C113
    signed int old_id; // Offset: 0x64, DWARF: 0x16C135
    signed int cnt; // Offset: 0x68, DWARF: 0x16C158
    signed int flag; // Offset: 0x6C, DWARF: 0x16C178
} EventMdl;

// Size: 0x40, DWARF: 0x16C3C4
// Size: 0x40
typedef struct WorldScreen
{
    float m[4][4];
} WorldScreen;

typedef struct Vspev01Ski
{
    signed int no; // Offset: 0x0, DWARF: 0x16C3E0
    signed int cnt; // Offset: 0x4, DWARF: 0x16C3FF
    signed int flag; // Offset: 0x8, DWARF: 0x16C41F
    float angle; // Offset: 0xC, DWARF: 0x16C440
    float now_angle; // Offset: 0x10, DWARF: 0x16C462
    signed int res[3]; // Offset: 0x14, DWARF: 0x16C488
    float rot[4]; // Offset: 0x20, DWARF: 0x16C4AA
    float trans[4]; // Offset: 0x30, DWARF: 0x16C4CC
} Vspev01Ski;

// Size: 0x30, DWARF: 0x16BEFE
typedef struct Vspev01Lift
{
    signed int no; // Offset: 0x0, DWARF: 0x16BF1A
    signed int cnt; // Offset: 0x4, DWARF: 0x16BF39
    float add; // Offset: 0x8, DWARF: 0x16BF59
    signed int pos; // Offset: 0xC, DWARF: 0x16BF79
    float rot[4]; // Offset: 0x10, DWARF: 0x16BF99
    float trans[4]; // Offset: 0x20, DWARF: 0x16BFBB
} Vspev01Lift;

// Size: 0x4, DWARF: 0x16E114
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0x16E130
} CourseNo;

// Size: 0x18, DWARF: 0x16E330
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x16E34C
    signed int game_mode; // Offset: 0x4, DWARF: 0x16E373
    signed int match_rule; // Offset: 0x8, DWARF: 0x16E399
    signed int divide; // Offset: 0xC, DWARF: 0x16E3C0
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x16E3E3
} Mode;

// Size: 0xA0, DWARF: 0x16D658
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x16E114
    CourseNo course; // Offset: 0x0, DWARF: 0x16D674
    // Size: 0x3C, DWARF: 0x167640
    Rider_State character[2]; // Offset: 0x4, DWARF: 0x16D699
    // Size: 0x18, DWARF: 0x16E330
    Mode mode; // Offset: 0x7C, DWARF: 0x16D6C1
    signed int language; // Offset: 0x94, DWARF: 0x16D6E4
    signed int ending; // Offset: 0x98, DWARF: 0x16D709
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x16D72C
} VspenvGame;

// Size: 0x30, DWARF: 0x16C664
typedef struct Vspev01Object
{
    signed short no; // Offset: 0x0, DWARF: 0x16C680
    signed short player; // Offset: 0x2, DWARF: 0x16C69F
    signed int cnt; // Offset: 0x4, DWARF: 0x16C6C2
    signed int flag; // Offset: 0x8, DWARF: 0x16C6E2
    float tmp; // Offset: 0xC, DWARF: 0x16C703
    float rot[4]; // Offset: 0x10, DWARF: 0x16C723
    float trans[4]; // Offset: 0x20, DWARF: 0x16C745
} Vspev01Object;

// Size: 0x10, DWARF: 0x168018
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x168033
    unsigned int addr; // Offset: 0x4, DWARF: 0x168056
    unsigned int z; // Offset: 0x8, DWARF: 0x168077
    unsigned int _pad; // Offset: 0xC, DWARF: 0x168095
} ATag;

// Size: 0x20, DWARF: 0x16AF89
typedef struct VgmsysAbuf
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0x16AFA5
    unsigned int natag; // Offset: 0x4, DWARF: 0x16AFC9
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0x16AFEB
    unsigned int npkt; // Offset: 0xC, DWARF: 0x16B00E
    // Size: 0x10, DWARF: 0x168018
    ATag* atag; // Offset: 0x10, DWARF: 0x16B02F
    // Size: 0x10, DWARF: 0x168018
    ATag* curatag; // Offset: 0x14, DWARF: 0x16B055
    __int128* pkt; // Offset: 0x18, DWARF: 0x16B07E
    __int128* curpkt; // Offset: 0x1C, DWARF: 0x16B0A1
} VgmsysAbuf;

///////////////////////////////

static float vspev01Lift1Pos[50][4]; // Address: 0x2CF040
static float vspev01Lift2Pos[30][4]; // Address: 0x2CF360
static signed int vspev01Length; // Address: 0x2E7880
static signed int vspev01Shift; // Address: 0x2E7EC0
static signed int vspev01Dram[12][2]; // Address: 0x2E42B0
static // Size: 0xA0, DWARF: 0x16D032
Vspev01SmokeInfo vspev01SmokeInfo[4][2]; // Address: 0x2CF540
float vspev01AnimFrame; // Address: 0x2E7F10
// Size: 0x28, DWARF: 0x16B780
Vspev01Shutter vspev01Shutter[3]; // Address: 0x3C6E20
// Size: 0x20, DWARF: 0x16C2FB
Vspev01Smoke vspev01Smoke; // Address: 0x3C6E00

// Size: 0x70, DWARF: 0x16C02F
EventMdl* vspev01EventMdl; // Address: 0x2E7F0C
// Size: 0x40, DWARF: 0x16C3C4
Vspev01Ski* vspev01Ski; // Address: 0x2E7EF4
// Size: 0x30, DWARF: 0x16BEFE
Vspev01Lift* vspev01Lift2; // Address: 0x2E7EF8
// Size: 0x30, DWARF: 0x16BEFE
Vspev01Lift* vspev01Lift1; // Address: 0x2E7EFC
signed int vspev01LoopVol[2]; // Address: 0x2E7EC8
signed int vspev01LoopID[2]; // Address: 0x2E7ED0
signed int vspev01LogoEvCam; // Address: 0x2E7EF0
// Size: 0xA0, DWARF: 0x16D658
VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x30, DWARF: 0x16C664
Vspev01Object vspev01Logo[6]; // Address: 0x3C6FC0
// Size: 0x20, DWARF: 0x16AF89
VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0
// vspev01Slow tracks how many slow signs have been destroyed for the level objective.
signed int vspev01Slow; // Address: 0x2E7ED8
signed int vspev01CameraCounter; // Address: 0x2E7EEC
signed int vspev01CameraFlag; // Address: 0x2E7EE8
// Size: 0x30, DWARF: 0x16C664
Vspev01Object vspev01Camera[4]; // Address: 0x3C6F00
// Size: 0x70, DWARF: 0x16C02F
EventMdl* vspev01CameraMdl; // Address: 0x2E7F08
// Size: 0x70, DWARF: 0x16C02F
EventMdl* vspev01TowerMdl; // Address: 0x2E7F04
// Size: 0x30, DWARF: 0x16C664
Vspev01Object vspev01LiftMan[2]; // Address: 0x3C6EA0
// Size: 0x70, DWARF: 0x16C02F
EventMdl* vspev01LiftManMdl; // Address: 0x2E7F00
signed int vspev01LiftManVoice[2]; // Address: 0x2E7EE0

signed int spev01Init(// Size: 0x8C, DWARF: 0x16775A
Event* event);
signed int spev01ResetEvent(// Size: 0x8C, DWARF: 0x16775A
Event* event);
signed int spev01MainEvent(// Size: 0x8C, DWARF: 0x16775A
Event* event);
signed int spev01PlayerEvent(// Size: 0x8C, DWARF: 0x16775A
Event* event);
signed int spev01DrawEvent(// Size: 0x8C, DWARF: 0x16775A
Event* event);
signed int spev01DrawPlayerEvent(Event* event);
signed int spev01FinishPlayerEvent(// Size: 0x8C, DWARF: 0x16775A
Event* event);
void spev01End();
static void spev01ResetLevelGoals();
static signed int spev01CheckLevelGoals(// Size: 0x8C, DWARF: 0x16775A
Event* event);
static void spev01ResetGaps();
static signed int spev01CheckGaps(// Size: 0x8C, DWARF: 0x16775A
Event* event);
static signed int spev01CheckGrindGaps(// Size: 0x8C, DWARF: 0x16775A
Event* event);
static signed int spev01CheckPlantGaps(// Size: 0x8C, DWARF: 0x16775A
Event* event);
static signed int spev01CheckGap_A1(Event* event, signed int player, signed int no);
static signed int spev01CheckGap_A2(Event* event, signed int player, signed int no);
static signed int spev01CheckGap_A4(Event* event, signed int player, signed int no, signed int rail);
static signed int spev01CheckGap_A5(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_A6(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_A7(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_A8(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_A10(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_M1(Character* character, signed int player, signed int no);
static signed int spev01CheckGap_O2_1(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_O2_2(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_O2_3(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static signed int spev01CheckGap_O2_4(// Size: 0x34, DWARF: 0x1671F4
Character* character, signed int player, signed int no);
static void spev01ResetObject(signed int vs);
static void spev01ResetLift1();
static void spev01MoveLift1(signed int no);
static void spev01ResetLift2();
static void spev01MoveLift2(signed int no);
static void spev01RollGear();
static void spev01ResetSki();
static void spev01TumbleSki();
static void spev01ResetLogo();
static void spev01FallLogo(// Size: 0x8C, DWARF: 0x16775A
Event* event);
static void spev01ResetDram();
static void spev01ResetWindow();
static void spev01ChangeWindow(signed int no);
static void spev01ResetCamera();
static void spev01MoveCamera(// Size: 0x8C, DWARF: 0x16775A
Event* event);
static signed int spev01CheckCamera(signed int no);
static void spev01ResetTower(signed int vs);
static void spev01MoveTower(// Size: 0x8C, DWARF: 0x16775A
Event* event);
static void spev01SetTowerCollision();
static void spev01ResetLiftMan(signed int vs);
static void spev01MoveLiftMan(// Size: 0x8C, DWARF: 0x16775A
Event* event);

// Included Functions /////////////////////////////////////
void tmevSetDrawLength(float length, signed int player);
float tmevGetDrawLength(signed int player);
signed int nmeventPlayLoop(signed int id, signed int num);
float tmcrsGetDrawLength();
void tmcrsSetObjectBonk(signed int no, float len, signed int bonk);
void tmcrsSetObjectAttr(signed int no, signed int attr);

signed int tmevGetFlag(signed int no);
void akevInitLensFlare(unsigned int type, float* pos, unsigned int backz, unsigned int rgb);
void akevWaterSplash(signed int pn, float* pos);
void knCameraEventAllReset(signed int id);
void knCameraSetFixRotation(float* rot, signed int id);
void knEventEnd();
void knEventSetCameraObj(float* obj);
void knEventSetCameraPos(float* pos);
void knEventStart();
void knReplaySetObstPos(float* pos, signed int flg, signed int id);
void ktactSetRecover(signed int pid, float* pos, float roty, float speed, signed int warp);
signed int nmactGetVoiceVol(signed int id);
void nmdispInputLevelCount(signed int now, signed int total, signed int num);
signed int nmeventPlay(signed int id, signed int num);
signed int nmeventPlay2(signed int id, signed int num);
signed int nmeventPlayVoice(signed int id, signed int num);
signed int nmvcSetInterVol(signed int res, signed int vol, signed int pan);
void nmvcSetOptVol(signed int vol, signed int pan);
void spEnterEventCameraMode();
void spExitEventCameraMode();
void tievCalcSmoke(Vspev01Smoke* pobj);
void tievInitSmoke(Vspev01Smoke* pobj, signed int num);
void tmcrsBreakObject(signed int no, float* dir);
void tmcrsCalcObjectUnit(signed int no);
signed int tmcrsGetObjectBonk(signed int no);
signed int tmcrsGetObjectDrawFlag(signed int no);
signed int tmcrsGetObjectPosition(float* position, signed int no);
void tmcrsGetTexData(Vspev01Shutter* group);
void tmcrsMoveObject(signed int no, float* rot, float* trans, signed int local);
void tmcrsResetAllObject();
void tmcrsResetEventModel(signed int num, EventMdl* param);
signed int tmcrsSetHitCollision(signed int no, signed int attr, signed int base);
void tmcrsSetMipMapLength(signed int len, signed int shift);
void tmcrsSetObjectScissorFlag(signed int no, signed int scissor);
void tmcrsSetRailCollision(signed int no, signed int collision);
void tmcrsSetScrollTex();
signed int tmevGetEventMdlHit(Ctrl* rider, float len, signed int no, signed int flag);
signed int tmevGetFinish(signed int player);
void tmevResetICounter(signed int no);
void tmevSet1PlayObject(signed int no);
void tmevSetAmbient(float* ambient, signed int player);
void tmevSetCourseLogo(signed int no);
void tmevSetFog(signed int fog, signed int player);
void tmevSetLevelGoal(signed int player, signed int no);
void tmevSetLightVector(float* light_color, float* normal_light, signed int id, signed int player);
void tmevSetSponsor(signed int sp_no, signed int obj_no);
void tmevSetVib(Event* event, signed int type, signed int no, signed int id);
void tmevSetVibPlayer(Event* event, signed int type, signed int no, signed int id, signed int player);
void tmevSetViewAngle(float view_angle, signed int player);
void tmevSetVsObject(signed int no);
void tmevSetVsWarpObject(signed int no);
void tmevSetWarpArrow(signed int no);
void tmevSetWarpNo(signed int no, signed int se);
void tmevStartICounter(signed int no);
void ulFree(void* p);
float tmcrsGetEventModelFrame(signed int no, signed int id);
void knEventSetShake(float power, float rate);
void tmevSetHorsePosition(float x, float y, float z, float angle);
void tmevSetStartPosition(float x, float y, float z, float angle, signed int player);
void tmevSetWarp(float* rec_pos, float angle, signed int hit, signed int se, float speed);
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void tmcrsSetObjectBound(signed int no, signed int sw);
void tmcrsSetObjectWeight(signed int no, signed int weight);
void tmcrsSetObjectDrawFlag(signed int no, signed int draw);
void tievSetSmoke(Vspev01Smoke* pobj, Vspev01SmokeInfo* info);
void tievFreeSmoke(Vspev01Smoke* pobj);
void tievDrawSmoke(Vspev01Smoke* pobj, VgmsysAbuf* pulA, sceVu0FMATRIX matWS);
signed int tmevGetICounter(signed int no);
void tmevStopICounter(signed int no);
void tmevSetFlag(signed int no, signed int value);
void tmevSetGap(signed int player, signed int no);

//// Functions /////////////////////////////////////////////////////////////////

signed int spev01Init(Event* event) {
    signed int ii; // r16
    float dir[4]; // 0x20(r29)
    float warp[4]; // 0x30(r29)

    vspev01Lift1 = (Vspev01Lift*)ulMalloc(0x180, 0, 0);
    vspev01Lift2 = (Vspev01Lift*)ulMalloc(0x1E0, 0, 0);
    vspev01Ski = (Vspev01Ski*)ulMalloc(0x380, 0, 0);
    vspev01EventMdl = (EventMdl*)ulMalloc(0x310, 0, 0);
    dir[0] = -1.0f;
    dir[1] = -0.5f;
    dir[2] = 0.0f;
    dir[3] = 1.0f;
    akevInitLensFlare(3, &dir[0], 0x1100, 0x808080);
    tievInitSmoke(&vspev01Smoke, 0x64);
    for (ii = 0; ii < 3; ii++) {
        vspev01Shutter[ii].src.group = 2;
        vspev01Shutter[ii].src.no = 0;
        vspev01Shutter[ii].src.tex_no = ii + 9;
        vspev01Shutter[ii].work.group = 2;
        vspev01Shutter[ii].work.no = 0;
        vspev01Shutter[ii].work.tex_no = ii + 0xC;
        tmcrsGetTexData(&vspev01Shutter[ii]);
        tmcrsGetTexData(&vspev01Shutter[ii].work.group);
    }
    warp[0] = 825.3f;
    warp[1] = 639.9f;
    warp[2] = -541.4f;
    warp[3] = 1.0f;
    tmevSetWarp(warp, 0.0031415922f, 0x270, 0x1E, 0.0f);
    warp[0] = 815.1f;
    warp[1] = 1292.7f;
    warp[2] = -2100.6f;
    warp[3] = 1.0f;
    tmevSetWarp(warp, 0.03735004f, 0x271, 0x1E, 0.0f);
    warp[0] = -226.545f;
    warp[1] = -363.421f;
    warp[2] = -73.709f;
    warp[3] = 1.0f;
    tmevSetWarp(warp, -0.09599309f, 0x26D, 0x1D, 0.0f);
    warp[0] = -1693.6f;
    warp[1] = -233.2f;
    warp[2] = 434.9f;
    warp[3] = 1.0f;
    tmevSetWarp(warp, -0.9053021f, 0x25D, 0x1D, 0.0f);
    if (1 <event->game.nplayer) {
        tmevSetStartPosition(-1681.7f, -233.0f, 453.4f, -0.9693557f, 0);
        tmevSetStartPosition(-1706.7f, -233.1f, 414.3f, -0.950157f, 1);
    } else {
        tmevSetStartPosition(-1693.6f, -233.2f, 434.9f, -0.9053021f, 0);
    }

    tmevSetHorsePosition(-1693.6f, -233.2f, 434.9f, -0.9135f); //48c-4b0
    tmevSetHorsePosition(461.3f, 1094.6f, -1485.6f, -0.2817f); //4b8 - 4ec
    tmevSetHorsePosition(825.4f, 652.0f, -577.8f, 0.0029670594f); // 4f0 - 520
    tmevSetHorsePosition(1517.9f, 2266.6f, -5620.0f, 0.0788f); // 524 - 558
    tmevSetHorsePosition(-280.6f, 2312.0f, -4669.5f, 0.31f); // 55c - 590
    tmevSetHorsePosition(-1395.0f, 2896.0f, -6968.0f, 0.69813159f); // 594 - 5c4
    tmevSetHorsePosition(-1718.2f, 3513.4f, -8227.3f, -0.5118f); // 5c8 - 5fc
    tmevSetHorsePosition(772.4f, 4087.4f, -10219.6f, 0.0239f); // 600 - 634
    tmevSetHorsePosition(255.0f, 1396.0f, -2658.2f, -0.016755156f); // 634 - 668
    tmevSetHorsePosition(224.2f, 2341.2f, -6084.8f, 0.38711395f); // 66C - 6a0
    tmevSetHorsePosition(801.4f, 3429.0f, -8095.1f, 0.42655837f); // 6a4 - 6d8
    tmevSetHorsePosition(-237.3f, 4086.4f, -9897.7f, 0.04520402f); // 6dc - 710
    vspev01AnimFrame = 80.0f;
    return 0;
}

s32 spev01ResetEvent(Event* event) {
    signed int ii; // r16
    signed int vs; // r17
    float light_color[4]; // 0x30(r29)
    float normal_light[4]; // 0x40(r29)
    float ambient[4]; // 0x50(r29)

    vspev01LogoEvCam = 0;
    if (event->game.nplayer < 2) {
        vs = 0;
    } else {
        vs = 1;
    }
    tmevSetDrawLength(3600.0f, 0);
    tmevSetDrawLength(3600.0f, 1);
    for (ii = 0; ii < 2; ii++) {
        ambient[0] = 0.3f;
        ambient[1] = 0.3f;
        ambient[2] = 0.3f;
        ambient[3] = 0.0f;
        tmevSetAmbient(&ambient[0], ii);
        normal_light[0] = 1.0f;
        normal_light[1] = 0.5f;
        normal_light[2] = 0.0f;
        normal_light[3] = 1.0f;
        light_color[0] = 0.6f;
        light_color[1] = 0.6f;
        light_color[2] = 0.6f;
        light_color[3] = 1.0f;
        tmevSetLightVector(&light_color[0], &normal_light[0], 0, ii);
        normal_light[0] = -1.0f;
        normal_light[1] = -0.5f;
        normal_light[2] = 0.0f;
        normal_light[3] = 1.0f;
        light_color[0] = 0.2f;
        light_color[1] = 0.2f;
        light_color[2] = 0.2f;
        light_color[3] = 1.0f;
        tmevSetLightVector(&light_color[0], &normal_light[0], 1, ii);
    }
    event->course.fog->near = (f32) (tmevGetDrawLength(0) - 2400.0f);
    event->course.fog->far = tmevGetDrawLength(0);
    event->course.fog->max = 255.0f;
    event->course.fog->min = 64.0f;
    event->course.fog->col[0] = 0x60;
    event->course.fog->col[1] = 0x60;
    event->course.fog->col[2] = 0x70;
    event->course.fog->col[3] = 0x80;
    tmevSetFog(0, 0);
    tmevSetFog(0, 1);
    spev01ResetLevelGoals();
    spev01ResetGaps();
    spev01ResetObject(vs);
    tmcrsSetMipMapLength(vspev01Length, vspev01Shift);
    nmvcSetOptVol(0, 0);
    *vspev01LoopID = nmeventPlayLoop(0, 9);
    *vspev01LoopVol = 0;
    nmvcSetInterVol(*vspev01LoopID, *vspev01LoopVol, 0);
    for (ii = 0; ii < 3; ii++) {
        vspev01Shutter[ii].scroll_x = 0;
        vspev01Shutter[ii].scroll_y = 0;
    }
    return 0;
}

s32 spev01MainEvent(Event* event) {
    signed int jj; // r16
    signed int ii; // r17
    s32* lift_ptr;
    float lift_pos[4][4] = {
        { 839.731f, 736.913f, -955.304f, 1.0f },
        { 839.478f, 1748.0179f, -4042.944f, 1.0f },
        { 688.513f, 1298.698f, -2826.22f, 1.0f },
        { 687.62598f, 2462.762f, -6403.785f, 1.0f },
    }; // 0x50(r29)
    float tmp[4]; // 0x90(r29)
    float len; // 0xAC(r29)

    lift_ptr = &lift_pos;

    if (event->game.pause == 0) {
        for (ii = 0; ii < 8; ii++) {
            spev01MoveLift1(ii);
        }
        for (ii = 0; ii < 0xA; ii++) {
            spev01MoveLift2(ii);
        }
        spev01RollGear();
        spev01TumbleSki();
        spev01FallLogo(event);
        if (event->game.nplayer == 1) {
            spev01MoveTower(event);
        }
        spev01MoveCamera(event);
        if (event->game.nplayer < 2) {
            spev01MoveLiftMan(event);
        }
        if (tmevGetFlag(0x7F) == 1) {
            if (tmevGetICounter(0x3F) % 4 == 0) {
                vspev01Shutter[0].scroll_y++;
            }
            if (tmevGetICounter(0x3F) % 8 == 0) {
                vspev01Shutter[1].scroll_y++;
            }
            if (tmevGetICounter(0x3F) % 0x10 == 0) {
                vspev01Shutter[2].scroll_y++;
            }
            if (tmevGetICounter(0x3F) >= 0x100) {
                tmevSetFlag(0x7F, 2);
                nmvcSetOptVol(0, 0);
                vspev01LoopVol[0] = 0;
                vspev01LoopID[0] = nmeventPlayLoop(0, 9);
                nmvcSetInterVol(vspev01LoopID[0], vspev01LoopVol[0], 0);
            }
        }
        len = 1.677e7f;
        for (ii = 0; ii < event->game.nplayer; ii++) {
            if ((1 >= event->game.nplayer) || (vspenvGame->mode.match_rule != 3 /*MatchHorse*/) || (ii == event->game.player)) {
                for (jj = 0; jj < 4; jj++) {
                    sceVu0SubVector(tmp, event->character[ii].ctrl->sys_mat->cam_trans, lift_pos[jj]);
                    sceVu0MulVector(tmp, tmp, tmp);
                    if (tmp[0] + tmp[1] + tmp[2] < len) {
                        len = tmp[0] + tmp[1] + tmp[2];
                    }
                }
            }
        }
        if (tmevGetFlag(0x7F) != 1) {
            if (len < 90000.0f) {
                vspev01LoopVol[0] = (((int)(90000.0f - len) * 0xFF) / 90000);
            } else {
                vspev01LoopVol[0] = 0;
            }
            nmvcSetInterVol(vspev01LoopID[0], vspev01LoopVol[0], 0);
        }
    }
    if (event->game.pause == 0 && ((event->game.nplayer == 1) || (vspenvGame->mode.match_rule == 3))) {
        for (ii = 0; ii < 4; ii++) {
            sceVu0SubVector(tmp, vspev01SmokeInfo[ii][0].vec, event->character[event->game.player].ctrl->sys_mat->cam_trans);
            sceVu0MulVector(tmp, tmp, tmp);
            len = tmp[0] + tmp[2];
            if (len <= tmcrsGetDrawLength() * tmcrsGetDrawLength()) {
                tievSetSmoke(&vspev01Smoke, &vspev01SmokeInfo[ii][0]);
                tievSetSmoke(&vspev01Smoke, &vspev01SmokeInfo[ii][1]);
            }
        }
        tievCalcSmoke(&vspev01Smoke);
    }
    tmcrsSetScrollTex(vspev01Shutter[0]);
    tmcrsSetScrollTex(vspev01Shutter[1]);
    tmcrsSetScrollTex(vspev01Shutter[2]);
    return 0;
}

s32 spev01PlayerEvent(Event* event) {
    signed int player; // r16
    signed int jj; // r17
    signed int ii; // r18
    float pos1[4]; // 0x50(r29)
    float pos2[4]; // 0x60(r29)
    float tmp[4]; // 0x70(r29)
    float no_pos[2][4] = {
        { -899.79999f, 4688.1f, -12399.1f, 1.0f },
        { -933.59998f, 4686.0f, -12396.2f, 1.0f }
    }; // 0x80(r29)
    s32* no_pos_ptr = &no_pos;
    float angle; // 0xAC(r29)

    // event = event; // B0
    player = event->game.player;
    if (tmevGetFlag(0x7F) == 0) {
        if ((event->character[player].rail == 0x157) || (event->character[player].rail == 0x158)) {
            nmvcSetOptVol(0, 0);
            vspev01LoopID[1] = nmeventPlayLoop(0, 4);
            vspev01LoopVol[1] = 0x80;
            nmvcSetInterVol(vspev01LoopID[1], vspev01LoopVol[1], 0);
            tmevSetFlag(0x7F, 1);
            tmevStartICounter(0x3F);
        } else {
            tmcrsSetHitCollision(0x14A, 7, 0);
        }
    }
    if (event->game.pause == 0) {
        if (1 < event->game.nplayer) {
            tmcrsSetHitCollision(0x26F, 0, 7);
        }
        if ((event->game.mode == 1) && (event->game.nplayer == 1)) {
            spev01CheckLevelGoals(event);
        }
        spev01CheckGaps(event);
        if (event->character[player].rail == 0x146) {
            for (ii = 0; ii < 0xE; ii++) {
                if (vspev01Ski[ii].flag == 0) {
                    vspev01Ski[ii].flag = 1;
                }
            }
        }
        if ((event->character[player].rail == 0x150) && (vspev01Logo->flag == 0)) {
            vspev01Logo->flag = 1;
            vspev01Logo->player = player;
        }
        for (ii = 0; ii < event->character[player].nhit; ii++) {
            if (event->game.nplayer < 2) {
                if ((event->character[player].hit[ii].no == 0x25D) && (tmevGetFlag(0x7C) == 4)) {
                    tmevSetFlag(0x7C, 5);
                }
            }
            if (event->character[player].hit[ii].no == 0x25E) {
                ktactSetRecover(player, no_pos[player], 0, 50.0f, 0);
                nmeventPlay(player, 0x13);
                tmevSetVib(event, 1, 1, 7);
                tmp[0] = 0.0f;
                tmp[1] = -13.0f;
                tmp[2] = 0.0f;
                tmp[3] = 1.0f;
                sceVu0AddVector(tmp, tmp, event->character[player].ctrl->nowpos.pos);
                akevWaterSplash(player, &tmp);
            } else if (event->character[player].hit[ii].no == 0x25B) {
                tmevSetDrawLength(3540.0f, player);
            } else {
                if (event->character[player].hit[ii].no == 0x25C) {
                    tmevSetDrawLength(3600.0f, player);
                } else {
                    if (event->character[player].hit[ii].no == 0x26B) {
                        tmevSetViewAngle(0.95993096f, player);
                    } else {
                        if (event->character[player].hit[ii].no == 0x26C) {
                            tmevSetViewAngle(-1.0f, player);
                        } else if (event->character[player].hit[ii].no == 0x259) {
                            pos1[0] = -251.784f;
                            pos1[1] = 3093.5f;
                            pos1[2] = -7999.23f;
                            pos1[3] = 1.0f;
                            pos2[0] = -286.583f;
                            pos2[1] = 3127.028f;
                            pos2[2] = -8103.234f;
                            pos2[3] = 1.0f;
                            sceVu0SubVector(tmp, pos2, pos1);
                            angle = atan2f(tmp[0], tmp[2]);
                            tmp[0] = -0.5f;
                            tmp[1] = angle;
                            tmp[2] = 0.0f;
                            tmp[3] = 1.0f;
                            knCameraSetFixRotation(tmp, player);
                        } else {
                            if (event->character[player].hit[ii].no == 0x25A) {
                                knCameraEventAllReset(player);
                            }
                        }
                    }
                }
            }
        }
        for (ii = 0; ii < event->character[player].nobj; ii++) {
            switch (event->character[player].object[ii].obj_type) {
            case 0x48:
            case 0x49:
            case 0x4A:
            case 0x4B:
            case 0x4C:
                nmeventPlay(player, ((tmevGetICounter(0)) % 3) + 0x16);
                tmevSetVib(event, 0, 1, 7);
                break;
            case 0x22:
            case 0x19:
            case 0x1A:
            case 0x1B:
            case 0x23:
            case 0x24:
                nmeventPlay(player, 0xE);
                tmevSetVib(event, 0, 2, 7);
                break;
            case 0x13:
                nmeventPlay(player, 7);
                tmevSetVib(event, 0, 3, 7);
                break;
            case 0x12:
                nmeventPlay(player, 7);
                tmevSetVib(event, 0, 3, 7);
                break;
            case 0x2:
                nmeventPlay(player, 0xF);
                tmevSetVib(event, 0, 0, 7);
                break;
            case 0x20:
                nmeventPlay(player, 0x11);
                tmevSetVib(event, 0, 2, 7);
                break;
            case 0x2D:
            case 0x2E:
                spev01ChangeWindow(event->character[player].object[ii].obj_no);
                nmeventPlay(player, 6);
                tmevSetVib(event, 0, 2, 7);
                break;
            case 0x14:
                if ((event->character[player].ctrl->act.trg_bonk == 1) && (tmcrsGetObjectBonk(event->character[player].object[ii].obj_no) == 1)) {
                    for (jj = 0; jj < 0xC; jj++) {
                        if (event->character[player].object[ii].obj_no == vspev01Dram[jj][0]) {
                            tmcrsSetObjectDrawFlag(vspev01Dram[jj][0], 0);
                            tmcrsSetObjectDrawFlag(vspev01Dram[jj][1], 1);
                        }
                    }
                } else {
                    tmcrsSetObjectBonk(event->character[player].object[ii].obj_no, 0, 0);
                }
                nmeventPlay(player, 0x10);
                tmevSetVib(event, 0, 0, 7);
                break;
            case 0x15:
                nmeventPlay(player, 0x10);
                tmevSetVib(event, 0, 0, 7);
                break;
            case 0x3:
                nmeventPlay(player, 8);
                tmevSetVib(event, 0, 2, 7);
                break;
            case 0x11:
            case 0x17:
                if (event->character[player].object[ii].obj_no == 0x8E) {
                    tmcrsSetRailCollision(0x14A, 0);
                }
                /* fallthrough */
            case 0x5:
            case 0x4:
                nmeventPlay(player, 0xB);
                tmevSetVib(event, 0, 2, 7);
                break;
            case 0x1F:
                nmeventPlay(player, 0xD);
                tmevSetVib(event, 0, 1, 7);
                break;
            case 0x16:
                nmeventPlay(player, 0x12);
                tmevSetVib(event, 0, 4, 7);
                break;
            }
        }
        spev01SetTowerCollision();
    }
    return 0;
}

signed int spev01DrawEvent(Event* event) {
    sceVu0FMATRIX world_screen; // 0x10(r29)

    if (event->game.pause == 0);
    if ((event->game.nplayer == 1) || (vspenvGame->mode.match_rule == 3)) {
        *(WorldScreen*)world_screen = *(WorldScreen*)event->character[event->game.player].ctrl->sys_mat->world_screen;
        tievDrawSmoke(&vspev01Smoke, vgmsysAbuf, world_screen);
    }
    return 0;
}

signed int spev01DrawPlayerEvent(Event* event) {
    return 0;
}

signed int spev01FinishPlayerEvent(Event* event) {
    tmevSetDrawLength(4200.0f, event->game.player);
    return 0;
}

void spev01End() {
    ulFree(vspev01Lift1);
    ulFree(vspev01Lift2);
    ulFree(vspev01Ski);
    ulFree(vspev01EventMdl);
    tievFreeSmoke(&vspev01Smoke);
}

void spev01ResetLevelGoals() {
    vspev01Slow = 0;
}

s32 spev01CheckLevelGoals(Event* event) {
    signed int jj; // r16
    signed int ii; // r17
    signed int player; // r18
    s32* unusedTblPtr;
    signed int tbl[5] = {
        20, 21, 22, 23, 24
    }; // 0x50(r29)

    unusedTblPtr = &tbl;;
    player = event->game.player;
    for (ii = 0; ii < event->character[player].nobj; ii++) {
        for (jj = 0; jj < 5; jj++) {
            if (tbl[jj] == event->character[player].object[ii].obj_no) {
                vspev01Slow += 1;
                if (vspev01Slow == 5) {
                    tmevSetLevelGoal(0, 6);
                } else {
                    nmdispInputLevelCount(vspev01Slow, 5, 6);
                }
            }
        }
    }
    if (tmevGetFlag(0x7E) == 1) {
        if (event->character[player].ctrl->act.trk_link_state == 2) {
            tmevSetLevelGoal(0, 7);
            tmevSetFlag(0x7E, 2);
            tmevStopICounter(0x3E);
            tmevResetICounter(0x3E);
        } else if (event->character[player].ctrl->act.trk_link_state == 3) {
            tmevSetFlag(0x7E, 0);
            tmevStopICounter(0x3E);
            tmevResetICounter(0x3E);
        }
    } else if (tmevGetFlag(0x7E) == 0) {
        if ((event->character[player].rail  == 0x17A) && (event->character[player].ctrl->act.trk_trick_no == 0x32)) {
            tmevStartICounter(0x3E);
            if (0x3C < tmevGetICounter(0x3E)) {
                tmevSetFlag(0x7E, 1);
                tmevStopICounter(0x3E);
                tmevResetICounter(0x3E);
            }
        } else {
            tmevStopICounter(0x3E);
            tmevResetICounter(0x3E);
        }
    }
    return 0;
}

void spev01ResetGaps(void) {
}

s32 spev01CheckGaps(Event* event) {

    signed int player; // r16
    signed int ii; // r17

    // event = event; // sp30
    player = event->game.player;
    if (((event->character[player].base_attr & 0xF) == 8) && (event->character[player].ctrl->act.sliding_state == 4)) {
        tmevStartICounter(player + 7);
    } else {
        if ((event->character[player].ctrl->act.sliding_state != 3) && (event->character[player].ctrl->act.sliding_state != 2)) {
            tmevResetICounter(player + 7);
        } else {
            tmevStopICounter(player + 7);
            tmevResetICounter(player + 7);
        }
    }
    if (tmevGetICounter(player + 7) == 0x3C) {
        tmevSetGap(player, 0xC);
    }
    for (ii = 0; ii < event->character[player].nhit; ii++) {
        if (event->character[player].hit[ii].no >= 0x64) {
            switch (event->character[player].hit[ii].no) {                      /* irregular */
            case 0x64:
            case 0x65:
                spev01CheckGap_A1(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x66:
            case 0x67:
                spev01CheckGap_A2(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x6B:
                spev01CheckGap_A4(&event->character[player], player, event->character[player].hit[ii].no, event->character[player].old_rail);
                break;
            case 0x6C:
            case 0x6D:
                spev01CheckGap_A5(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x72:
            case 0x73:
                spev01CheckGap_A6(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x6E:
                spev01CheckGap_A7(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x68:
            case 0x69:
                spev01CheckGap_A8(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x71:
            case 0x74:
                spev01CheckGap_A10(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0xC9:
            case 0xCA:
            case 0xCB:
            case 0xCC:
                spev01CheckGap_M1(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x1F6:
            case 0x1F7:
                spev01CheckGap_O2_1(&event->character[player], player, event->character[player].hit[ii].no);
                /* fallthrough */
            case 0x1F8:
            case 0x200:
                spev01CheckGap_O2_2(&event->character[player], player, event->character[player].hit[ii].no);
                /* fallthrough */
            case 0x1FD:
            case 0x1FF:
                spev01CheckGap_O2_3(&event->character[player], player, event->character[player].hit[ii].no);
                /* fallthrough */
            case 0x1FA:
            case 0x1FC:
                spev01CheckGap_O2_4(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            }
        }
    }
    for (ii = 0; ii < event->character[player].nobj; ii++) {
        if ((event->character[player].object[ii].obj_type == 0x14) && (event->character[player].ctrl->act.trg_bonk == 1)) {
            tmevSetGap(player, 0xD);
        }
        if ((event->character[player].object[ii].obj_type == 0xF) || (event->character[player].object[ii].obj_type == 0xE)) {
            if (event->character[player].ctrl->act.trg_bonk == 1) {
                tmevSetGap(player, 0x19);
            }
        }
        if ((event->character[player].object[ii].obj_type == 0x16) && (event->character[player].ctrl->act.trg_bonk == 1) && (tmevGetFlag(player + 0x3A) == 2)) {
            tmevSetGap(player, 0x28);
        } else {
            if (event->character[player].object[ii].obj_type == 0x22) {
                tmevSetGap(player, 2);
            } else if (event->character[player].ctrl->act.sliding_state == 4) {
                if (event->character[player].object[ii].obj_type == 3) {
                    tmevSetFlag(player + 0x12, tmevGetFlag(player + 0x12) + 1);
                    if (tmevGetFlag(player + 0x12) == 3) {
                        tmevSetGap(player, 0xB);
                    }
                }
            } else if (event->character[player].old_rail == 0x171) {
                if ((event->character[player].ctrl->act.cnt_to_rail <= 0) && ((event->character[player].object[ii].obj_type == 0x2D) || (event->character[player].object[ii].obj_type == 0x2E))) {
                    tmevSetGap(player, 0x2F);
                }
            }
        }
    }
    spev01CheckGrindGaps(event);
    spev01CheckPlantGaps(event);
    spev01CheckGap_A5(&event->character[player], player, -1);
    spev01CheckGap_A7(&event->character[player], player, -1);
    spev01CheckGap_A6(&event->character[player], player, -1);
    spev01CheckGap_A8(&event->character[player], player, -1);
    spev01CheckGap_A10(&event->character[player], player, -1);
    spev01CheckGap_O2_1(&event->character[player], player, -1);
    spev01CheckGap_O2_2(&event->character[player], player, -1);
    spev01CheckGap_O2_3(&event->character[player], player, -1);
    spev01CheckGap_O2_4(&event->character[player], player, -1);
    if ((event->character[player].ctrl->act.sliding_state != 3) || (event->character[player].ctrl->act.trg_bonk != 0)) {
        tmevSetFlag(player, 0);
        tmevSetFlag(player + 2, 0);
        tmevSetFlag(player + 6, 0);
    }
    if (event->character[player].ctrl->act.sliding_state != 4) {
        tmevSetFlag(player + 0x10, 0);
    }
    return 0;
}

s32 spev01CheckGrindGaps(// Size: 0x8C, DWARF: 0x16775A
    Event* event) {
    signed int player; // r16
    signed int ii; // r17
    signed int ret = 0; // r18

    player = event->game.player;
    if ((event->character[player].ctrl->act.sliding_state == essGrind) && ((event->character[player].old_rail == -1) || (event->character[player].old_rail != event->character[player].rail))) {
        switch (event->character[player].rail) {
        case 0x17B:
            if (tmevGetFlag(player + 0xC) != 0) {
                tmevSetFlag(player + 0xC, 0);
                tmevSetGap(player, 8);
                ret = 1;
            }
            break;
        case 0x14B:
            tmevResetICounter(player + 1);
            tmevStartICounter(player + 1);
            break;
        case 0x17A:
            tmevResetICounter(player + 3);
            tmevStartICounter(player + 3);
            break;
        case 0x141:
            tmevSetFlag(player + 0x14, 1);
            break;
        case 0x142:
            if (tmevGetFlag(player + 0x14) == 1) {
                tmevSetFlag(player + 0x14, 0);
                tmevSetGap(player, 0x10);
                ret = 1;
            }
            break;
        case 0x14C:
            tmevSetFlag(player + 0x16, 1);
            break;
        case 0x14D:
            if (tmevGetFlag(player + 0x16) == 1) {
                tmevSetFlag(player + 0x16, 2);
            }
            break;
        case 0x14E:
            if (tmevGetFlag(player + 0x16) == 2) {
                tmevSetFlag(player + 0x16, 0);
                tmevSetGap(player, 0x11);
                ret = 1;
            }
            break;
        case 0x143:
            tmevSetFlag(player + 0x18, 1);
            break;
        case 0x144:
            if (tmevGetFlag(player + 0x18) == 1) {
                tmevSetFlag(player + 0x18, 0);
                tmevSetGap(player, 0x12);
                ret = 1;
            }
            break;
        case 0x146:
            if (tmevGetFlag(player + 0x1A) == 0) {
                tmevSetGap(player, 0x13);
                tmevSetFlag(0x1A, 1);
                tmevSetFlag(0x1B, 1);
                ret = 1;
            }
            break;
        case 0x145:
            if (tmevGetFlag(player + 0x1C) != 3) {
                tmevSetFlag(player + 0x1C, 1);
            }
            break;
        case 0x14F:
            if (tmevGetFlag(player + 0x1C) == 1) {
                tmevSetFlag(player + 0x1C, 2);
            }
            break;
        case 0x150:
            if (tmevGetFlag(player + 0x1C) == 2) {
                tmevSetFlag(0x1C, 3);
                tmevSetFlag(0x1D, 3);
                tmevSetGap(player, 0x14);
                ret = 1;
            }
            break;
        case 0x157:
        case 0x158:
            if (tmevGetFlag(player + 0x1E) == 0) {
                tmevSetGap(player, 0x15);
                tmevSetFlag(0x1E, 1);
                tmevSetFlag(0x1F, 1);
            }
            break;
        case 0x153:
        case 0x154:
        case 0x159:
        case 0x15A:
            tmevSetGap(player, 0x16);
            ret = 1;
            break;
        case 0x151:
            tmevResetICounter(player + 5);
            tmevStartICounter(player + 5);
            if (tmevGetFlag(player + 0x36) == 1) {
                tmevSetFlag(player + 0x36, 0);
                tmevSetGap(player, 0x25);
                ret = 1;
            }
            break;
        case 0x155:
        case 0x15C:
            tmevSetFlag(player + 0x20, 1);
            break;
        case 0x156:
            if (tmevGetFlag(player + 0x20) == 1) {
                tmevSetFlag(player + 0x20, 0);
                tmevSetGap(player, 0x18);
                ret = 1;
            }
            break;
        case 0x175:
        case 0x176:
            tmevSetFlag(player + 0x22, 1);
            break;
        case 0x163:
        case 0x15D:
            tmevSetFlag(player + 0x24, 1);
            break;
        case 0x15E:
        case 0x15F:
            if (tmevGetFlag(player + 0x24) == 1) {
                tmevSetFlag(player + 0x24, 2);
            }
            break;
        case 0x160:
            if (tmevGetFlag(player + 0x24) == 2) {
                tmevSetFlag(player + 0x24, 0);
                tmevSetGap(player, 0x1B);
                ret = 1;
            }
            break;
        case 0x140:
            if (tmevGetFlag(player + 0x26) != 0) {
                tmevSetFlag(player + 0x26, 0);
                tmevSetGap(player, 0x1C);
                ret = 1;
            }
            break;
        case 0x50:
            tmevSetGap(player, 0x1E);
            ret = 1;
            break;
        case 0x16A:
        case 0x16B:
            tmevSetFlag(player + 0x2A, 1);
            break;
        case 0x164:
        case 0x165:
            if (tmevGetFlag(player + 0x2A) == 1) {
                tmevSetFlag(player + 0x2A, 2);
            }
            break;
        case 0x166:
            if (tmevGetFlag(player + 0x2A) == 2) {
                tmevSetFlag(player + 0x2A, 0);
                tmevSetGap(player, 0x1F);
                ret = 1;
            }
            break;
        case 0x167:
            tmevSetFlag(player + 0x2C, 1);
            break;
        case 0x168:
            tmevSetGap(player, 0x20);
            ret = 1;
            break;
        case 0x10A:
            if (tmevGetFlag(player + 0x2E) == 0) {
                tmevSetFlag(player + 0x2E, 1);
            }
            if (tmevGetFlag(player + 0x2E) == 4) {
                tmevSetFlag(player + 0x2E, 5);
                tmevSetGap(player, 0x21);
                ret = 1;
            }
            break;
        case 0x152:
            if (tmevGetFlag(player + 0x2E) == 1) {
                tmevSetFlag(player + 0x2E, 2);
            }
            if (tmevGetFlag(player + 0x2E) == 3) {
                tmevSetFlag(player + 0x2E, 4);
            }
            break;
        case 0x10B:
            if (tmevGetFlag(player + 0x2E) == 0) {
                tmevSetFlag(player + 0x2E, 3);
            }
            if (tmevGetFlag(player + 0x2E) == 2) {
                tmevSetFlag(player + 0x2E, 5);
                tmevSetGap(player, 0x21);
                ret = 1;
            }
            break;
        case 0x10C:
            if (tmevGetFlag(player + 0x32) == 0) {
                tmevSetFlag(player + 0x32, 1);
            }
            if (tmevGetFlag(player + 0x32) == 4) {
                tmevSetFlag(player + 0x32, 5);
                tmevSetGap(player, 0x23);
                ret = 1;
            }
            break;
        case 0x169:
            if (tmevGetFlag(player + 0x32) == 1) {
                tmevSetFlag(player + 0x32, 2);
            }
            if (tmevGetFlag(player + 0x32) == 3) {
                tmevSetFlag(player + 0x32, 4);
            }
            if (tmevGetFlag(player + 0x38) == 1) {
                tmevSetFlag(player + 0x38, 0);
                tmevSetGap(player, 0x26);
                ret = 1;
            }
            break;
        case 0x10D:
            if (tmevGetFlag(player + 0x32) == 0) {
                tmevSetFlag(player + 0x32, 3);
            }
            if (tmevGetFlag(player + 0x32) == 2) {
                tmevSetFlag(player + 0x32, 5);
                tmevSetGap(player, 0x23);
                ret = 1;
            }
            break;
        case 0x16C:
            tmevSetFlag(player + 0x34, 1);
            break;
        case 0x16D:
            if (tmevGetFlag(player + 0x34) == 1) {
                tmevSetFlag(player + 0x34, 0);
                tmevSetGap(player, 0x24);
                ret = 1;
            }
            break;
        case 0x16E:
            tmevSetGap(player, 0x27);
            ret = 1;
            break;
        case 0x16F:
            tmevSetFlag(player + 0x3A, 1);
            break;
        case 0x170:
            if (tmevGetFlag(player + 0x3A) == 1) {
                tmevSetFlag(player + 0x3A, 2);
            }
            break;
        case 0x147:
            if (tmevGetFlag(player + 0x3C) == 1) {
                tmevSetFlag(player + 0x3C, 0);
                tmevSetGap(player, 0x29);
                ret = 1;
            }
            break;
        case 0x148:
            if (tmevGetFlag(player + 0x3E) == 1) {
                tmevSetFlag(player + 0x3E, 0);
                tmevSetGap(player, 0x2A);
                ret = 1;
            }
            break;
        }
    } else {
        if (event->character[player].ctrl->act.sliding_state == essGrind) {
            if ((event->character[player].rail == 0x14B) && (tmevGetICounter(player + 1) >= 0x3C)) {
                tmevSetGap(player, 0xE);
                tmevStopICounter(player + 1);
                tmevResetICounter(player + 1);
                ret = 1;
            }
            if ((event->character[player].rail == 0x17A) && (tmevGetICounter(player + 3) >= 0x3C)) {
                tmevSetGap(player, 0xF);
                // temp_a1_5 = player + 3;
                tmevStopICounter(player + 3);
                tmevResetICounter(player + 3);
                ret = 1;
            }
            if ((event->character[player].rail == 0x151) && (tmevGetICounter(player + 5) >= 0x3C)) {
                tmevSetGap(player, 0x17);
                // temp_a1_7 = player + 5;
                tmevStopICounter(player + 5);
                tmevResetICounter(player + 5);
                ret = 1;
            }
        } else if (event->character[player].old_rail == -1) {
            tmevStopICounter(player + 1);
            tmevResetICounter(player + 1);
            tmevStopICounter(player + 3);
            tmevResetICounter(player + 3);
            tmevSetFlag(player + 0x14, 0);
            tmevSetFlag(player + 0x16, 0);
            tmevSetFlag(player + 0x18, 0);
            if (tmevGetFlag(player + 0x1C) != 3) {
                tmevSetFlag(player + 0x1C, 0);
            }
            tmevStopICounter(player + 5);
            tmevResetICounter(player + 5);
            tmevSetFlag(player + 0x20, 0);
            tmevSetFlag(player + 0x22, 0);
            tmevSetFlag(player + 0x24, 0);
            tmevSetFlag(player + 0x28, 0);
            tmevSetFlag(player + 0x2A, 0);
            tmevSetFlag(player + 0x2C, 0);
            tmevSetFlag(player + 0x2E, 0);
            tmevSetFlag(player + 0x30, 0);
            tmevSetFlag(player + 0x32, 0);
            tmevSetFlag(player + 0x34, 0);
            tmevSetFlag(player + 0x3A, 0);
        }
    }
    if ((event->character[player].ctrl->act.sliding_state != essOnAir) || (event->character[player].ctrl->act.trg_bonk == 1)) {
        tmevSetFlag(player + 0xC, 0);
        tmevSetFlag(player + 0x26, 0);
        tmevSetFlag(player + 0x36, 0);
        tmevSetFlag(player + 0x38, 0);
        tmevSetFlag(player + 0x3C, 0);
        tmevSetFlag(player + 0x3E, 0);
    }
    for (ii = 0; ii < event->character[player].nhit; ii++) {
        if (event->character[player].hit[ii].no == 0x6F) {
            tmevSetFlag(player + 0xC, 1);
        }
        if ((event->character[player].hit[ii].no == 0x269) && (tmevGetFlag(player + 0x22) == 1)) {
            tmevSetFlag(player + 0x22, 0);
            tmevSetGap(player, 0x1A);
            ret = 1;
        }
        if (event->character[player].hit[ii].no == 0x151) {
            tmevSetFlag(player + 0x26, 1);
        }
        if (event->character[player].hit[ii].no == 0x155) {
            tmevSetFlag(player + 0x28, 1);
        } else {
            if (event->character[player].hit[ii].no == 0x156) {
                if (tmevGetFlag(player + 0x28) == 1) {
                    tmevSetFlag(player + 0x28, 0);
                    tmevSetGap(player, 0x1D);
                    ret = 1;
                }
            }
        }
        if (event->character[player].hit[ii].no == 0x15E && tmevGetFlag(player + 0x2C) == 1 && event->character[player].ctrl->act.trg_bonk == 1) {
            tmevSetFlag(player + 0x2C, 2);
        }
        if (event->character[player].hit[ii].no == 0x164) {
            tmevSetFlag(player + 0x30, 1);
        } else if (event->character[player].hit[ii].no == 0x165 && tmevGetFlag(player + 0x30) == 1) {
            tmevSetFlag(player + 0x30, 0);
            tmevSetGap(player, 0x22);
            ret = 1;
        }
        if (event->character[player].hit[ii].no == 0x173) {
            tmevSetFlag(player + 0x30, 2);
        } else {
            if (event->character[player].hit[ii].no == 0x174 && (tmevGetFlag(player + 0x30) == 2)) {
                tmevSetFlag(player + 0x30, 0);
                tmevSetGap(player, 0x22);
                ret = 1;
            }
        }
        if (event->character[player].hit[ii].no == 0x166) {
            tmevSetFlag(player + 0x30, 1);
        } else {
            if (event->character[player].hit[ii].no == 0x167 && (tmevGetFlag(player + 0x30) == 1)) {
                tmevSetFlag(player + 0x30, 0);
                tmevSetGap(player, 0x22);
                ret = 1;
            }
        }
        if (event->character[player].hit[ii].no == 0x175) {
            tmevSetFlag(player + 0x30, 2);
        } else {
            if ((event->character[player].hit[ii].no == 0x176) && (tmevGetFlag(player + 0x30) == 2)) {
                tmevSetFlag(player + 0x30, 0);
                tmevSetGap(player, 0x22);
                ret = 1;
            }
        }
        if (event->character[player].hit[ii].no == 0x16A) {
            tmevSetFlag(player + 0x36, 1);
        }
        if (event->character[player].hit[ii].no == 0x16B) {
            tmevSetFlag(player + 0x38, 1);
        }
        if (event->character[player].hit[ii].no == 0x16F) {
            tmevSetFlag(player + 0x3C, 1);
        }
        if (event->character[player].hit[ii].no == 0x171) {
            tmevSetFlag(player + 0x3E, 1);
        }
    }
    return ret;
}

signed int spev01CheckPlantGaps(// Size: 0x8C, DWARF: 0x16775A
    Event* event) {
    signed int player; // r16
    signed int ret = 0; // r18
    signed int ii; // r17

    player = event->game.player;
    for (ii = 0; ii < event->character[player].nhit; ii++) {
        if (event->character[player].hit[ii].no >= 0x64) {
            if (event->character[player].hit[ii].no == 0x194) {
                tmevSetFlag(player + 0x40, 1);
            } else if (event->character[player].hit[ii].no == 0x195) {
                tmevSetFlag(player + 0x40, 0);
            }
        }
    }
    if ((event->character[player].ctrl->act.sliding_state == essPlant) && (event->character[player].old_rail == -1)) {
        switch (event->character[player].rail) {
        case 0x11B:
            tmevSetGap(player, 0x2B);
            break;
        case 0x118:
        case 0x119:
        case 0x11A:
            tmevSetGap(player, 0x2C);
            break;
        case 0x10E:
            if (tmevGetFlag(player + 0x40) != 0) {
                tmevSetGap(player, 0x2D);
            }
            break;
        case 0x117:
            tmevSetGap(player, 0x2E);
            break;
        }
    }
    return ret;
}

signed int spev01CheckGap_A1(Event* event, signed int player, signed int no) {
    signed int ret; // r16

    ret = 0;
    if ((tmevGetFlag(player) == 1) && (no == 0x65)) {
        tmevSetGap(player, 0);
        tmevSetFlag(player, 0);
        ret = 1;
    } else if (no == 0x64) {
        tmevSetFlag(player, 1);
    }
    return ret;
}

signed int spev01CheckGap_A2(Event* event, signed int player, signed int no) {
    signed int ret;

    ret = 0;
    if ((tmevGetFlag(player + 2) == 1) && (no == 0x67)) {
        tmevSetGap(player, 1);
        tmevSetFlag(player + 2, 0);
        ret = 1;
    } else if (no == 0x66) {
        tmevSetFlag(player + 2, 1);
    }
    return ret;
}

signed int spev01CheckGap_A4(Event* event, signed int player, signed int no, signed int rail) {
    signed int ret;

    ret = 0;
    if ((no == 0x6B) && (rail == 0x149)) {
        tmevSetGap(player, 3);
        ret = 1;
    }
    return ret;
}

signed int spev01CheckGap_A5(Character* character, signed int player, signed int no) {
    signed int ret;

    ret = 0;
    if (tmevGetFlag(player + 4) == 2) {
        if (no == 0x6D) {
            tmevSetGap(player, 4);
            tmevSetFlag(player + 4, 0);
            ret = 1;
        } else if ((character->ctrl->act.sliding_state != 3) || (character->ctrl->act.trg_bonk == 1)) {
            tmevSetFlag(player + 4, 1);
        }
    } else if (tmevGetFlag(player + 4) == 1) {
        if (character->ctrl->act.sliding_state == 3) {
            tmevSetFlag(player + 4, 2);
        }
    } else if (no == 0x6C) {
        tmevSetFlag(player + 4, 1);
    }
    return ret;
}

signed int spev01CheckGap_A6(Character* character, signed int player, signed int no) {
    signed int ret; // r16

    ret = 0;
    if (tmevGetFlag(player + 6) == 1) {
        if (no == 0x73) {
            tmevSetGap(player, 5);
            tmevSetFlag(player + 6, 0);
            ret = 1;
        }
    } else if (no == 0x72) {
        tmevSetFlag(player + 6, 1);
    }
    if ((tmevGetFlag(player + 6) == 1) && (character->ctrl->act.hp_air == 0)) {
        tmevSetFlag(player + 6, 0);
    }
    return ret;
}

signed int spev01CheckGap_A7(Character* character, signed int player, signed int no) {
    signed int ret; // r16
    ret = 0;
    if (tmevGetFlag(player + 8) == 1) {
        if ((character->ctrl->act.sliding_state == essSliding) || (character->ctrl->act.sliding_state == essManual)) {
            if ((character->base_attr & 0xF) != 8) {
                tmevSetGap(player, 6);
                tmevSetFlag(player + 8, 0);
                ret = 1;
            } else {
                tmevSetFlag(player + 8, 0);
            }
        } else if (character->ctrl->act.sliding_state != 3) {
            tmevSetFlag(player + 8, 0);
        }
    } else if (no == 0x6E) {
        tmevSetFlag(player + 8, 1);
    }
    return ret;
}

signed int spev01CheckGap_A8(Character* character, signed int player, signed int no) {
    signed int ret = 0; // r16

    if (tmevGetFlag(player + 0xA) == 1) {
        if (no == 0x69) {
            tmevSetGap(player, 7);
            tmevSetFlag(player + 0xA, 0);
            ret = 1;
        }
    } else if (no == 0x68) {
        tmevSetFlag(player + 0xA, 1);
    }
    if ((tmevGetFlag(player + 0xA) == 1) && (character->ctrl->act.hp_air == 0)) {
        tmevSetFlag(player + 0xA, 0);
    }
    return ret;
}

signed int spev01CheckGap_A10(Character* character, signed int player, signed int no) {
    signed int ret;

    ret = 0;
    if (tmevGetFlag(player + 0xE) == 1) {
        if (no == 0x74) {
            tmevSetGap(player, 9);
            tmevSetFlag(player + 0xE, 0);
            ret = 1;
        }
    } else if (no == 0x71) {
        tmevSetFlag(player + 0xE, 1);
    }
    if ((tmevGetFlag(player + 0xE) == 1) && (character->ctrl->act.hp_air == 0)) {
        tmevSetFlag(player + 0xE, 0);
    }
    return ret;
}

signed int spev01CheckGap_M1(Character* character, signed int player, signed int no) {
    signed int ret;

    ret = 0;
    if ((tmevGetFlag(player + 0x10) == 1) && (no == 0xCA)) {
        tmevSetGap(player, 0xA);
        tmevSetFlag(player + 0x10, 0);
        ret = 1;
    } else if ((tmevGetFlag(player + 0x10) == 2) && (no == 0xCC)) {
        tmevSetGap(player, 0xA);
        tmevSetFlag(player + 0x10, 0);
        ret = 1;
    } else if (no == 0xC9) {
        tmevSetFlag(player + 0x10, 1);
    } else if (no == 0xCB) {
        tmevSetFlag(player + 0x10, 2);
    }
    return ret;
}

signed int spev01CheckGap_O2_1(Character* character, signed int player, signed int no) {
    // First Camera goal gap check
    signed int ret = 0;

    if (tmevGetFlag(player + 0x42) != 2) {
        if (no == 0x1F7) {
            if (tmevGetFlag(player + 0x42) == 1) {
                tmevSetFlag(player + 0x42, 0);
            } else {
                tmevSetFlag(player + 0x42, 1);
            }
        } else if (tmevGetFlag(player + 0x42) == 1) {
            if ((character->ctrl->act.sliding_state != 3) || (character->ctrl->act.trg_bonk == 1)) {
                tmevSetFlag(player + 0x42, 0);
            } else if (((character->ctrl->act.trk_doing == 1) || (character->ctrl->act.trick_link.is_bonus_spin != 0)) && (spev01CheckCamera(0) == 1)) {
                tmevSetGap(player, 0x30);
                tmevSetFlag(player + 0x42, 2);
                ret = 1;
                nmeventPlay(player, 5);
                if (!(vspev01CameraFlag & 1)) {
                    vspev01CameraFlag |= 1;
                    vspev01CameraCounter += 1;
                    if (vspev01CameraCounter == 4) {
                        tmevSetLevelGoal(player, 8);
                    } else {
                        nmdispInputLevelCount(vspev01CameraCounter, 4, 8);
                    }
                }
            }
        }
    } else if (no == 0x1F7) {
        tmevSetFlag(player + 0x42, 0);
    }
    return ret;
}

signed int spev01CheckGap_O2_2(Character* character, signed int player, signed int no) {
    signed int ret = 0;

    if (tmevGetFlag(player + 0x44) != 2) {
        if (no == 0x200) {
            if (tmevGetFlag(player + 0x44) == 1) {
                tmevSetFlag(player + 0x44, 0);
            } else {
                tmevSetFlag(player + 0x44, 1);
            }
        } else if ((tmevGetFlag(player + 0x44) == 1) && ((character->ctrl->act.sliding_state == 6) || ((character->ctrl->act.sliding_state == 3) && ((character->ctrl->act.trk_doing == 1) || (character->ctrl->act.trick_link.is_bonus_spin != 0)))) && (spev01CheckCamera(1) == 1)) {
            tmevSetGap(player, 0x30);
            tmevSetFlag(player + 0x44, 2);
            nmeventPlay(player, 5);
            ret = 1;
            if (!(vspev01CameraFlag & 2)) {
                vspev01CameraFlag |= 2;
                vspev01CameraCounter += 1;
                if (vspev01CameraCounter == 4) {
                    tmevSetLevelGoal(player, 8);
                } else {
                    nmdispInputLevelCount(vspev01CameraCounter, 4, 8);
                }
            }
        }
    } else if (no == 0x200) {
        tmevSetFlag(player + 0x44, 0);
    }
    return ret;
}

signed int spev01CheckGap_O2_3(Character* character, signed int player, signed int no) {
    signed int ret = 0;

    if (tmevGetFlag(player + 0x46) != 2) {
        if (no == 0x1FF) {
            if (tmevGetFlag(player + 0x46) == 1) {
                tmevSetFlag(player + 0x46, 0);
            } else {
                tmevSetFlag(player + 0x46, 1);
            }
        } else if ((tmevGetFlag(player + 0x46) == 1) && ((character->ctrl->act.trk_doing == 1) || (character->ctrl->act.trick_link.is_bonus_spin != 0)) && (spev01CheckCamera(2) == 1)) {
            tmevSetGap(player, 0x30);
            tmevSetFlag(player + 0x46, 2);
            nmeventPlay(player, 5);
            ret = 1;
            if (!(vspev01CameraFlag & 4)) {
                vspev01CameraFlag |= 4;
                vspev01CameraCounter += 1;
                if (vspev01CameraCounter == 4) {
                    tmevSetLevelGoal(player, 8);
                } else {
                    nmdispInputLevelCount(vspev01CameraCounter, 4, 8);
                }
            }
        }
    } else if (no == 0x1FF) {
        tmevSetFlag(player + 0x46, 0);
    }
    return ret;
}

signed int spev01CheckGap_O2_4(Character* character, signed int player, signed int no) {
    signed int ret = 0;
    
    if (tmevGetFlag(player + 0x48) != 2) {
        if (no == 0x1FC) {
            if (tmevGetFlag(player + 0x48) == 1) {
                tmevSetFlag(player + 0x48, 0);
            } else {
                tmevSetFlag(player + 0x48, 1);
            }
        } else if (tmevGetFlag(player + 0x48) == 1) {
            if ((character->ctrl->act.sliding_state == essGrind) && (spev01CheckCamera(3) == 1)) {
                tmevSetGap(player, 0x30);
                tmevSetFlag(player + 0x48, 2);
                nmeventPlay(player, 5);
                ret = 1;
                if (!(vspev01CameraFlag & 8)) {
                    vspev01CameraFlag |= 8;
                    vspev01CameraCounter += 1;
                    if (vspev01CameraCounter == 4) {
                        tmevSetLevelGoal(player, 8);
                    } else {
                        nmdispInputLevelCount(vspev01CameraCounter, 4, 8);
                    }
                }
            } else {
                tmevSetFlag(player + 0x48, 0);
            }
        }
    } else if (no == 0x1FC) {
        tmevSetFlag(player + 0x48, 0);
    }
    return ret;
}

static void spev01ResetObject(s32 vs) {
    signed int ii; // r16
    s32* tbl_ptr;
    signed int sp_tbl[22] = {
        0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1, 0xe2, 0xe3,
        0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb,
        0xec, 0xed, 0xee, 0xef
    }; // 0x30(r29)

    tbl_ptr = &sp_tbl;
    tmcrsResetAllObject();
    spev01ResetLift1();
    spev01ResetLift2();
    spev01ResetSki();
    spev01ResetLogo();
    spev01ResetDram();
    spev01ResetCamera();
    spev01ResetLiftMan(vs);
    spev01ResetTower(vs);
    spev01ResetWindow();
    tmevSetCourseLogo(0xD8);
    tmevSetCourseLogo(0xD9);
    tmevSetCourseLogo(0xDA);
    tmevSetCourseLogo(0xDB);
    if ((vs == 1) && (vspenvGame->mode.match_rule != 3)) {
        tmcrsSetObjectDrawFlag(0xF7, 0);
        tmcrsSetObjectDrawFlag(0xF8, 0);
        tmcrsSetObjectDrawFlag(0xF9, 0);
        tmcrsSetObjectDrawFlag(0xFA, 0);
        tmcrsSetObjectDrawFlag(0xFB, 0);
        tmcrsSetObjectDrawFlag(0xFC, 0);
        tmcrsSetObjectDrawFlag(0xFD, 0);
        tmcrsSetObjectDrawFlag(0xFE, 0);
        tmcrsSetObjectDrawFlag(0xFF, 0);
        tmcrsSetObjectDrawFlag(0x100, 0);
        tmcrsSetObjectDrawFlag(0x101, 0);
        tmcrsSetObjectDrawFlag(0x102, 0);
        tmcrsSetObjectDrawFlag(0x103, 0);
        tmcrsSetObjectDrawFlag(0x104, 0);
        tmcrsSetObjectDrawFlag(0x105, 0);
        tmcrsSetObjectDrawFlag(0x106, 0);
    }
    for (ii = 0; ii < 0x16; ii++) {
        tmevSetSponsor(ii, sp_tbl[ii]);
    }
    for (ii = 0; ii < 7; ii++) {
        tmcrsSetObjectBonk((signed int)(ii + 0x54), 0, 1);
    }
    for (ii = 0; ii < 0x20; ii++) {
        tmcrsSetObjectBound(ii + 0x97, 1);
    }
    for (ii = 0; ii < 0x19; ii++) {
        tmcrsSetObjectBound(ii + 0x75, 1);
        tmcrsSetObjectScissorFlag(ii + 0x75, 1);
        tmcrsSetObjectBonk((signed int)(ii + 0x75), 7.0f, 1);
        tmcrsSetObjectWeight(ii + 0x75, 2);
    }
    tmcrsSetObjectScissorFlag(0x8E, 1);
    tmcrsSetObjectScissorFlag(0x8F, 1);
    tmcrsSetObjectScissorFlag(0xC3, 1);
    tmcrsSetObjectScissorFlag(0xC4, 1);
    tmcrsSetObjectScissorFlag(0xC5, 1);
    tmcrsSetObjectScissorFlag(0xC6, 1);
    tmcrsSetObjectScissorFlag(0xC7, 1);
    tmcrsSetObjectScissorFlag(0xBD, 1);
    tmcrsSetObjectScissorFlag(0xBE, 1);
    tmcrsSetObjectScissorFlag(0xB7, 1);
    tmcrsSetObjectScissorFlag(0xB8, 1);
    tmcrsResetEventModel(7, vspev01EventMdl);
    tmevSetWarpArrow(0xBF);
    tmevSetWarpArrow(0xC0);
    tmevSetWarpArrow(0xC1);
    tmevSetWarpArrow(0xC2);
    tmevSetVsObject(0xBD);
    tmevSetVsObject(0xC7);
    tmevSet1PlayObject(0xC0);
    tmevSet1PlayObject(0xC1);
    tmevSet1PlayObject(0xC2);
    tmevSet1PlayObject(0xC3);
    tmevSet1PlayObject(0xC4);
    tmevSet1PlayObject(0xC5);
    tmevSet1PlayObject(0xC6);
    tmevSet1PlayObject(0xBE);
    tmevSetVsWarpObject(0xBF);
    tmevSetVsWarpObject(0xC7);
    tmevSetWarpNo(0x26E, 0x1D);
    tmevSetWarpNo(0x272, 0x1D);
}

void spev01ResetLift1() {
    float tmp[4]; // 0x30(r29)
    float len; // 0x48(r29)
    float angle; // 0x4C(r29)
    signed int jj; // r17
    signed int ii; // r16

    vspev01Lift1[0].no = 0x3B;
    vspev01Lift1[1].no = 0x3C;
    vspev01Lift1[2].no = 0x3D;
    vspev01Lift1[3].no = 0x3E;
    vspev01Lift1[4].no = 0x3F;
    vspev01Lift1[5].no = 0x40;
    vspev01Lift1[6].no = 0x41;
    vspev01Lift1[7].no = 0x42;
    len = 0.0f;
    for (ii = 0; ii < 0x32; ii++) {
        sceVu0SubVector(tmp, &vspev01Lift1Pos[(ii + 1) % 50], &vspev01Lift1Pos[ii]);
        sceVu0MulVector(tmp, tmp, tmp);
        len += sqrtf(tmp[0] + tmp[1] + tmp[2]);
    }
    for (ii = 0; ii < 8; ii++) {
        vspev01Lift1[ii].cnt = 0;
        vspev01Lift1[ii].add = (float) (len / 10800.0f);
        vspev01Lift1[ii].pos = 1;
        tmcrsGetObjectPosition(&tmp, vspev01Lift1[ii].no);
        sceVu0SubVector(tmp, &vspev01Lift1Pos[vspev01Lift1[ii].pos], &tmp);
        angle = atan2f(tmp[0], tmp[2]);
        vspev01Lift1[ii].rot[0] = 0.0f;
        vspev01Lift1[ii].rot[1] = angle;
        vspev01Lift1[ii].rot[2] = 0.0f;
        vspev01Lift1[ii].rot[3] = 1.0f;
        vspev01Lift1[ii].trans[0] = 0.0f;
        vspev01Lift1[ii].trans[1] = 0.0f;
        vspev01Lift1[ii].trans[2] = 0.0f;
        vspev01Lift1[ii].trans[3] = 1.0f;
        tmcrsSetObjectAttr(vspev01Lift1[ii].no, 0x8001);
        tmcrsSetObjectBonk(vspev01Lift1[ii].no, -40.0f, 1);
    }
    for (ii = 0; ii < 8; ii++) {
        for (jj = 0; jj < (ii * 0x546); jj++) {
            spev01MoveLift1(ii);
            tmcrsCalcObjectUnit(vspev01Lift1[ii].no);
        }
    }
}

void spev01MoveLift1(signed int no) {
    float position[4]; // 0x10(r29)
    float rot[4]; // 0x20(r29)
    float matrix[4][4]; // 0x30(r29)
    float angle; // 0x70(r29)
    float tmp; // 0x74(r29)

    tmcrsGetObjectPosition(&position[0], vspev01Lift1[no].no);
    sceVu0SubVector(position, &vspev01Lift1Pos[vspev01Lift1[no].pos], position);
    angle = atan2f(position[0], position[2]);
    tmp = (angle - vspev01Lift1[no].rot[1]) < -3.141592f ? 6.283184f + (angle - vspev01Lift1[no].rot[1]) : ((angle - vspev01Lift1[no].rot[1]) > 3.141592f) ? (angle - vspev01Lift1[no].rot[1]) - 6.283184f : angle - vspev01Lift1[no].rot[1];
    if ((tmp > 1.570796f) || (tmp < -1.570796f) || (tmp == 0.0f)) {
        vspev01Lift1[no].pos = (signed int) ((signed int) (vspev01Lift1[no].pos + 1) % 50);
        tmcrsGetObjectPosition(&position[0], vspev01Lift1[no].no);
        sceVu0SubVector(&position[0], &vspev01Lift1Pos[vspev01Lift1[no].pos], &position[0]);
        angle = atan2f(position[0], position[2]);
        tmp = (angle - vspev01Lift1[no].rot[1]) < -3.141592f ? 6.283184f + (angle - vspev01Lift1[no].rot[1]) : ((angle - vspev01Lift1[no].rot[1]) > 3.141592f) ? (angle - vspev01Lift1[no].rot[1]) - 6.283184f : angle - vspev01Lift1[no].rot[1];
    }
    if (tmp > 0.015f) {
        tmp = 0.015f;
    } else if (tmp < -0.015f) {
        tmp = -0.015f;
    }
    rot[0] = 0.0f;
    rot[1] = tmp;
    rot[2] = 0.0f;
    rot[3] = 1.0f;
    vspev01Lift1[no].rot[1] = (tmp + vspev01Lift1[no].rot[1]) < -3.141592f ? 6.283184f + (tmp + vspev01Lift1[no].rot[1]) : ((tmp + vspev01Lift1[no].rot[1]) > 3.141592f) ? (tmp + vspev01Lift1[no].rot[1]) - 6.283184f : tmp + vspev01Lift1[no].rot[1];
    tmp = sqrtf((position[0] * position[0]) + (position[2] * position[2]));
    angle = -atan2f(position[1], tmp);
    vspev01Lift1[no].rot[0] = angle;
    position[0] = 0.0f;
    position[1] = 0.0f;
    position[2] = vspev01Lift1[no].add;
    position[3] = 1.0f;
    sceVu0UnitMatrix(&matrix);
    sceVu0RotMatrixX(&matrix, &matrix, vspev01Lift1[no].rot[0]);
    sceVu0ApplyMatrix(&position[0], &matrix, &position[0]);
    tmcrsMoveObject(vspev01Lift1[no].no, &rot[0], &position[0], 1);
}

void spev01ResetLift2() {
    float temp_f0;
    signed int var_s0;

    signed int ii; // r16
    signed int jj; // r17
    float tmp[4]; // 0x30(r29)
    float len; // 0x48(r29)
    float angle; // 0x4C(r29)

    vspev01Lift2[0].no = 0x31;
    vspev01Lift2[1].no = 0x32;
    vspev01Lift2[2].no = 0x33;
    vspev01Lift2[3].no = 0x34;
    vspev01Lift2[4].no = 0x35;
    vspev01Lift2[5].no = 0x36;
    vspev01Lift2[6].no = 0x37;
    vspev01Lift2[7].no = 0x38;
    vspev01Lift2[8].no = 0x39;
    vspev01Lift2[9].no = 0x3A;
    len = 0.0f;
    for (ii = 0; ii < 0x1E; ii++) {
        sceVu0SubVector(&tmp[0], &vspev01Lift2Pos[(ii + 1) % 30], &vspev01Lift2Pos[ii]);
        sceVu0MulVector(&tmp[0], &tmp[0], &tmp[0]);
        len += sqrtf(tmp[0] + tmp[1] + tmp[2]);
    }
    for (ii = 0; ii < 0xA; ii++) {
        vspev01Lift2[ii].cnt = 0;
        vspev01Lift2[ii].add = (float) (len / 10800.0f);
        vspev01Lift2[ii].pos = 1;
        tmcrsGetObjectPosition(&tmp[0], vspev01Lift2[ii].no);
        sceVu0SubVector(&tmp[0], &vspev01Lift2Pos[vspev01Lift2[ii].pos], &tmp[0]);
        angle = -atan2f(tmp[0], tmp[2]);
        vspev01Lift2[ii].rot[0] = 0.0f;
        vspev01Lift2[ii].rot[1] = angle;
        vspev01Lift2[ii].rot[2] = 0.0f;
        vspev01Lift2[ii].rot[3] = 1.0f;
        vspev01Lift2[ii].trans[0] = 0.0f;
        vspev01Lift2[ii].trans[1] = 0.0f;
        vspev01Lift2[ii].trans[2] = 0.0f;
        vspev01Lift2[ii].trans[3] = 1.0f;
        tmcrsSetObjectAttr(vspev01Lift2[ii].no, 0x8001);
        tmcrsSetObjectBonk(vspev01Lift2[ii].no, -40.0f, 1);
    }
    for (ii = 0; ii < 0xA; ii++) {
        for (jj = 0; jj < (ii * 0x438); jj++) {
            spev01MoveLift2(ii);
            tmcrsCalcObjectUnit(vspev01Lift2[ii].no);
        }
    }
}

void spev01MoveLift2(signed int no) {
    float position[4]; // 0x10(r29)
    float rot[4]; // 0x20(r29)
    float matrix[4][4]; // 0x30(r29)
    float angle; // 0x70(r29)
    float tmp; // 0x74(r29)

    tmcrsGetObjectPosition(&position, vspev01Lift2[no].no);
    sceVu0SubVector(position, &vspev01Lift2Pos[vspev01Lift2[no].pos], position);
    angle = atan2f(position[0], position[2]);
    tmp = (angle - vspev01Lift2[no].rot[1]) < -3.141592f ? 6.283184f + (angle - vspev01Lift2[no].rot[1]) : ((angle - vspev01Lift2[no].rot[1]) > 3.141592f) ? (angle - vspev01Lift2[no].rot[1]) - 6.283184f : angle - vspev01Lift2[no].rot[1];
    if ((tmp > 1.570796f) || (tmp < -1.570796f)) {
        vspev01Lift2[no].pos = (signed int) ((signed int) (vspev01Lift2[no].pos + 1) % 30);
        tmcrsGetObjectPosition(&position, vspev01Lift2[no].no);
        sceVu0SubVector(&position, &vspev01Lift2Pos[vspev01Lift2[no].pos], &position);
        angle = atan2f(position[0], position[2]);
        tmp = (angle - vspev01Lift2[no].rot[1]) < -3.141592f ? 6.283184f + (angle - vspev01Lift2[no].rot[1]) : ((angle - vspev01Lift2[no].rot[1]) > 3.141592f) ? (angle - vspev01Lift2[no].rot[1]) - 6.283184f : angle - vspev01Lift2[no].rot[1];
    }
    if ((tmp > 0.02f)) {
        tmp = 0.02f;
    } else if (tmp < -0.02f) {
        tmp = -0.02f;
    }
    rot[0] = 0.0f;
    rot[1] = tmp;
    rot[2] = 0.0f;
    rot[3] = 1.0f;
    vspev01Lift2[no].rot[1] = (tmp + vspev01Lift2[no].rot[1]) < -3.141592f ? 6.283184f + (tmp + vspev01Lift2[no].rot[1]) : ((tmp + vspev01Lift2[no].rot[1]) > 3.141592f) ? (tmp + vspev01Lift2[no].rot[1]) - 6.283184f : tmp + vspev01Lift2[no].rot[1];
    tmp = sqrtf((position[0] * position[0]) + (position[2] * position[2]));
    angle = -atan2f(position[1], tmp);
    vspev01Lift2[no].rot[0] = angle;
    position[0] = 0.0f;
    position[1] = 0.0f;
    position[2] = vspev01Lift2[no].add;
    position[3] = 1.0f;
    sceVu0UnitMatrix(&matrix);
    sceVu0RotMatrixX(&matrix, &matrix, vspev01Lift2[no].rot[0]);
    sceVu0ApplyMatrix(&position, &matrix, &position);
    tmcrsMoveObject(vspev01Lift2[no].no, &rot, &position, 1);
}

void spev01RollGear() {
    float rot[4]; // 0x20(r29)
    float trans[4]; // 0x30(r29)
    signed int ii; // r16

    rot[0] = 0.0f;
    rot[1] = 0.01f;
    rot[2] = 0.0f;
    rot[3] = 1.0f;
    trans[0] = 0.0f;
    trans[1] = 0.0f;
    trans[2] = 0.0f;
    trans[3] = 1.0f;
    for (ii = 0; ii < 4; ii++) {
        tmcrsMoveObject(ii + 0x43, &rot, &trans, 1);
    }
}

void spev01ResetSki() {
    signed int ii; // r16

    vspev01Ski[0].no = 3;
    vspev01Ski[1].no = 4;
    vspev01Ski[0].angle = 1.5184362f;
    vspev01Ski[1].angle = 1.5184362f;
    vspev01Ski[2].no = 5;
    vspev01Ski[3].no = 6;
    vspev01Ski[2].angle = 1.5184362f;
    vspev01Ski[3].angle = 1.5184362f;
    vspev01Ski[4].no = 7;
    vspev01Ski[5].no = 0;
    vspev01Ski[4].angle = 1.5184362f;
    vspev01Ski[5].angle = 1.5184362f;
    vspev01Ski[6].no = 1;
    vspev01Ski[7].no = 2;
    vspev01Ski[6].angle = 1.5184362f;
    vspev01Ski[7].angle = 1.5184362f;
    vspev01Ski[8].no = 0xA;
    vspev01Ski[9].no = 0xB;
    vspev01Ski[8].angle = 2.0943947f;
    vspev01Ski[9].angle = 2.0943947f;
    vspev01Ski[10].no = 0xC;
    vspev01Ski[11].no = 0xD;
    vspev01Ski[10].angle = 2.0943947f;
    vspev01Ski[11].angle = 2.0943947f;
    vspev01Ski[12].no = 8;
    vspev01Ski[13].no = 9;
    vspev01Ski[12].angle = 2.0943947f;
    vspev01Ski[13].angle = 2.0943947f;
    for (ii = 0; ii < 0xE; ii++) {
        vspev01Ski[ii].cnt = 0;
        vspev01Ski[ii].flag = 0;
        vspev01Ski[ii].now_angle = 0.0f;
        vspev01Ski[ii].rot[0] = 0.0f;
        vspev01Ski[ii].rot[1] = 0.0f;
        vspev01Ski[ii].rot[2] = 0.01f;
        vspev01Ski[ii].rot[3] = 1.0f;
        vspev01Ski[ii].trans[0] = 0.0f;
        vspev01Ski[ii].trans[1] = 0.0f;
        vspev01Ski[ii].trans[2] = 0.0f;
        vspev01Ski[ii].trans[3] = 1.0f;
    }
}

void spev01TumbleSki() {
    signed int ii; // r16

    for (ii = 0; ii < 0xE; ii++) {
        if (vspev01Ski[ii].flag == 1) {
            vspev01Ski[ii].rot[2] += (0.0001f * (float) vspev01Ski[ii].cnt);
            if ((vspev01Ski[ii].now_angle + vspev01Ski[ii].rot[2]) < vspev01Ski[ii].angle) {
                vspev01Ski[ii].now_angle += (float)vspev01Ski[ii].rot[2];
            } else if (vspev01Ski[ii].now_angle < vspev01Ski[ii].angle) {
                vspev01Ski[ii].rot[2] = (float) (vspev01Ski[ii].angle - vspev01Ski[ii].now_angle);
                if (ii == 0) {
                    nmeventPlay(0, 0xA);
                }
                vspev01Ski[ii].flag = 2;
            }
            tmcrsMoveObject(vspev01Ski[ii].no, vspev01Ski[ii].rot, vspev01Ski[ii].trans, 0);
            vspev01Ski[ii].cnt += 1;
        }
    }
}

void spev01ResetLogo() {
    signed int ii; // r16

    vspev01Logo[0].no = 0x25;
    vspev01Logo[1].no = 0x26;
    vspev01Logo[2].no = 0x27;
    vspev01Logo[3].no = 0x28;
    vspev01Logo[4].no = 0x29;
    vspev01Logo[5].no = 0x2A;
    for (ii = 0; ii < 6; ii++) {
        vspev01Logo[ii].player = 0;
        vspev01Logo[ii].cnt = 0;
        vspev01Logo[ii].flag = 0;
        vspev01Logo[ii].tmp = 0.0f;
        vspev01Logo[ii].rot[0] = 0.0f;
        vspev01Logo[ii].rot[1] = 0.0f;
        vspev01Logo[ii].rot[2] = 0.0f;
        vspev01Logo[ii].rot[3] = 1.0f;
        vspev01Logo[ii].trans[0] = 0.0f;
        vspev01Logo[ii].trans[1] = 0.0f;
        vspev01Logo[ii].trans[2] = 0.0f;
        vspev01Logo[ii].trans[3] = 1.0f;
    }
}

void spev01FallLogo(Event* event) {
    int temp_v0;
    int var_v1;

    float dir[4]; // 0x20(r29)
    float cam_pos[4]; // 0x30(r29)
    float cam_rot[4]; // 0x40(r29)
    signed int ii; // r16

    if (vspev01Logo[4].flag != 0) {
        cam_pos[0] = 510.0f;
        cam_pos[1] = 4290.0f;
        cam_pos[2] = -11487.0f;
        cam_pos[3] = 1.0f;
        cam_rot[0] = 0.35f;
        cam_rot[1] = 1.72f;
        cam_rot[2] = 0.0f;
        cam_rot[3] = 1.0f;
    } else {
        cam_pos[0] = 634.0f;
        cam_pos[1] = 4177.0f;
        cam_pos[2] = -11295.0f;
        cam_pos[3] = 1.0f;
        cam_rot[0] = -1.0f;
        cam_rot[1] = 2.14f;
        cam_rot[2] = 0.0f;
        cam_rot[3] = 1.0f;
    }
    dir[0] = 0.0f;
    dir[1] = -5.0f;
    dir[2] = 0.0f;
    dir[3] = 1.0f;
    for (ii = 0; ii < 6; ii++) {
        if (vspev01Logo[ii].flag == 1) {
            vspev01Logo[ii].trans[0] = 0.0f;
            vspev01Logo[ii].trans[1] = (float) (0.098f * (float) vspev01Logo[ii].cnt);
            vspev01Logo[ii].trans[2] = 0.0f;
            vspev01Logo[ii].trans[3] = 1.0f;
            tmcrsMoveObject(vspev01Logo[ii].no, vspev01Logo[ii].rot, vspev01Logo[ii].trans, 0);
            vspev01Logo[ii].tmp += (float) (vspev01Logo[ii].trans[1]);
            if (vspev01Logo[ii].tmp >= 53.0f) {
                tmcrsBreakObject(vspev01Logo[ii].no, &dir);
                tmevSetVibPlayer(event, 1, 2, 7, vspev01Logo[0].player);
                vspev01Logo[ii].flag = 2;
                if (tmevGetICounter(0) % 2 != 0) {
                    nmeventPlay2(vspev01Logo[ii].player, 6);
                } else {
                    nmeventPlay2(vspev01Logo[ii].player, 0xB);
                }
            }
            vspev01Logo[ii].cnt += 1;
            if (((ii + 1) != 6) && (vspev01Logo[ii].cnt == 0x14)) {
                vspev01Logo[ii+1].player = (short) vspev01Logo[ii].player;
                vspev01Logo[ii+1].flag = 1;
            }
        }
    }
}

void spev01ResetDram() {
    signed int ii;

    for (ii = 0; ii < 0xC; ii++) {
        tmcrsSetObjectBound(ii + 0x5D, 1);
        tmcrsSetObjectWeight(ii + 0x5D, 2);
        tmcrsSetObjectBonk(ii + 0x5D, 12.0f, 1);
        tmcrsSetObjectBound(ii + 0x69, 1);
        tmcrsSetObjectWeight(ii + 0x69, 2);
        tmcrsSetObjectDrawFlag(ii + 0x69, 0);
    }
}

void spev01ResetWindow() {
    tmcrsSetObjectDrawFlag(0xD0, 0);
    tmcrsSetObjectDrawFlag(0xD1, 0);
    tmcrsSetObjectDrawFlag(0xD2, 0);
    tmcrsSetObjectDrawFlag(0xD3, 0);
    tmcrsSetObjectDrawFlag(0xD4, 0);
    tmcrsSetObjectDrawFlag(0xD5, 0);
    tmcrsSetObjectDrawFlag(0xD6, 0);
    tmcrsSetObjectDrawFlag(0xD7, 0);
    tmcrsSetObjectScissorFlag(0xC8, 1);
    tmcrsSetObjectScissorFlag(0xC9, 1);
    tmcrsSetObjectScissorFlag(0xCA, 1);
    tmcrsSetObjectScissorFlag(0xCB, 1);
    tmcrsSetObjectScissorFlag(0xCC, 1);
    tmcrsSetObjectScissorFlag(0xCD, 1);
    tmcrsSetObjectScissorFlag(0xCE, 1);
    tmcrsSetObjectScissorFlag(0xCF, 1);
    tmcrsSetObjectScissorFlag(0xD0, 1);
    tmcrsSetObjectScissorFlag(0xD1, 1);
    tmcrsSetObjectScissorFlag(0xD2, 1);
    tmcrsSetObjectScissorFlag(0xD3, 1);
    tmcrsSetObjectScissorFlag(0xD4, 1);
    tmcrsSetObjectScissorFlag(0xD5, 1);
    tmcrsSetObjectScissorFlag(0xD6, 1);
    tmcrsSetObjectScissorFlag(0xD7, 1);
}

void spev01ChangeWindow(signed int no) {
    signed int obj_no; // r16

    switch (no) {
    case 0xC8:
        obj_no = 0xD0;
        break;
    case 0xC9:
        obj_no = 0xD1;
        break;
    case 0xCA:
        obj_no = 0xD2;
        break;
    case 0xCB:
        obj_no = 0xD3;
        break;
    case 0xCC:
        obj_no = 0xD4;
        break;
    case 0xCD:
        obj_no = 0xD5;
        break;
    case 0xCE:
        obj_no = 0xD6;
        break;
    case 0xCF:
        obj_no = 0xD7;
        break;
    }
    tmcrsSetObjectDrawFlag(obj_no, 1);
}

void spev01ResetCamera() {
    signed int ii; // r16
    s32* trans_ptr;
    float trans[4][4] = {
        { 535.354f, 1288.171f, -2206.5569f, 1.0f },
        { -254.634f, 2091.877f, -3993.137f, 1.0f },
        { 1544.606f, 3120.3899f, -7994.724f, 1.0f },
        { -460.476f, 4713.7319f, -12852.641f, 1.0f } 
    }; // 0x30(r29)
    trans_ptr = &trans;

    vspev01CameraCounter = 0;
    vspev01CameraFlag = 0;
    vspev01CameraMdl = vspev01EventMdl;
    for (ii = 0; ii < 4; ii++) {
        sceVu0CopyVector(vspev01Camera[ii].trans, trans[ii]);
        vspev01Camera[ii].rot[0] = 0.0f;
        vspev01Camera[ii].rot[1] = 0.0f;
        vspev01Camera[ii].rot[2] = 0.0f;
        vspev01Camera[ii].rot[3] = 1.0f;
        vspev01Camera[ii].cnt = 0;
        vspev01Camera[ii].flag = 0;
        vspev01Camera[ii].tmp = 0.0f;
        vspev01Camera[ii].no = 0;
        vspev01CameraMdl[ii].no = 0;
        vspev01CameraMdl[ii].id = 2;
        vspev01CameraMdl[ii].frame = 0.0f;
        vspev01CameraMdl[ii].draw = 0;
        vspev01CameraMdl[ii].light = 1;
        sceVu0UnitMatrix(vspev01CameraMdl[ii].matrix);
        sceVu0RotMatrixY(vspev01CameraMdl[ii].matrix, vspev01CameraMdl[ii].matrix, vspev01Camera[ii].tmp);
        sceVu0TransMatrix(vspev01CameraMdl[ii].matrix, vspev01CameraMdl[ii].matrix, vspev01Camera[ii].trans);
    }
}

void spev01MoveCamera(Event* event) {
    signed int ii; // r16 // s0
    signed int jj; // r17 // s1
    signed int id; // r18 // s2
    signed int cnt; // r19 // s3
    Ctrl* rider; // r20 // s4
    signed int player; // r21 // s5
    signed int sprt_tbl[4] = {
        0x2B, 0x2C, 0x2E, 0x2D
    }; // 0x80(r29)
    s32* sprt_tbl_ptr = &sprt_tbl;
    float tmp[4]; // 0x90(r29)
    float len[2];// __attribute__((aligned(16))); // 0xA0(r29)
    float angle; // 0xA8(r29)
    float frame; // 0xAC(r29)

    for (ii = 0; ii < 4; ii++) {
        len[0] = 1.6777e7f;
        len[1] = 1.6777e7f;
        for (jj = 0; jj < event->game.nplayer; jj++) {
            if ((event->game.nplayer <= 1) || (vspenvGame->mode.match_rule != 3) || (jj == event->game.player)) {
                sceVu0SubVector(tmp, &vspev01Camera[ii].trans, event->character[jj].ctrl->nowpos.pos);
                sceVu0MulVector(tmp, tmp, tmp);
                len[jj] = tmp[0] + tmp[2];
            }
        }
        if ((1 < event->game.nplayer) && (vspenvGame->mode.match_rule == 3)) {
            rider = event->character[event->game.player].ctrl;
            player = event->game.player;
        } else {
            rider = event->character[0].ctrl;
            player = 0;
            if (len[1] < len[0] && (1 < event->game.nplayer)) {
                rider = event->character[1].ctrl;
                player = 1;
            }
        }
        id = 2;
        frame = tmcrsGetEventModelFrame(0, id);
        cnt = ((frame + 60.0f) - 1.0f) / vspev01AnimFrame;
        frame = vspev01AnimFrame * (tmevGetICounter(0) % cnt);
        if (frame > tmcrsGetEventModelFrame(0, id)) {
            frame = tmcrsGetEventModelFrame(0, id);
        }
        sceVu0SubVector(tmp, &vspev01Camera[ii].trans, &rider->nowpos.pos[0]);
        angle = atan2f(tmp[0], tmp[2]);
        sceVu0MulVector(tmp, tmp, tmp);
        if ((tmevGetEventMdlHit(rider, 10.0f, ii, 0) == 1) && (tmcrsGetObjectDrawFlag(sprt_tbl[ii]) == 0)) {
            if (vspev01Camera[ii].flag != 2) {
                vspev01Camera[ii].cnt = 0;
                nmvcSetOptVol(nmactGetVoiceVol(0), 0);
                nmeventPlay(player, 0xC);
                tmevSetVib(event, 0, 5, 7);
            }
            if (ii == tmevGetFlag(0x7C)) {
                tmevSetFlag(0x7C, ii + 1);
            } else {
                if ((vspev01Camera[ii].flag != 2) && (event->game.nplayer <= 1)) {
                    tmevSetFlag(0x7C, 0);
                }
            }
            vspev01Camera[ii].flag = 2;
        }
        if (vspev01Camera[ii].flag == 0) {
            if ((vspev01CameraMdl[ii].old_id != 2) && (vspev01Camera[ii].cnt != 0)) {
                id = 3;
                frame = vspev01AnimFrame * (float) vspev01Camera[ii].cnt;
                if ((frame > tmcrsGetEventModelFrame(0, id))) {
                    frame = tmcrsGetEventModelFrame(0, id);
                }
                if ((event->game.pause == 0) && (vspev01Camera[ii].cnt > 0)) {
                    vspev01Camera[ii].cnt -= 1;
                }
            } else {
                id = 2;
                if (event->game.pause == 0) {
                    vspev01Camera[ii].cnt += 1;
                    if (cnt < vspev01Camera[ii].cnt) {
                        vspev01Camera[ii].cnt = 0;
                    }
                }
            }
            if (event->game.pause == 0) {
                vspev01Camera[ii].tmp = angle;
            }
            if (len[player] < 62500.0f) {
                vspev01Camera[ii].flag = 1;
                vspev01Camera[ii].cnt = 0;
            }
        } else if (vspev01Camera[ii].flag == 1) {
            id = 3;
            frame = tmcrsGetEventModelFrame(0, id);
            cnt = ((60.0f + frame) - 1.0f) / vspev01AnimFrame;
            frame = vspev01AnimFrame * vspev01Camera[ii].cnt;
            if ((frame > tmcrsGetEventModelFrame(0, id))) {
                frame = tmcrsGetEventModelFrame(0, id);
            }
            if (event->game.pause == 0) {
                vspev01Camera[ii].tmp = angle;
                if (vspev01Camera[ii].cnt < cnt) {
                    vspev01Camera[ii].cnt += 1;
                }
            }
            if ((len[player] > 62500.0f)) {
                vspev01Camera[ii].flag = 0;
            }
        } else if (vspev01Camera[ii].flag == 2) {
            id = 4;
            frame = tmcrsGetEventModelFrame(0, id);
            cnt = ((60.0f + frame) - 1.0f) / vspev01AnimFrame;
            frame = vspev01AnimFrame * vspev01Camera[ii].cnt;
            if ((frame > tmcrsGetEventModelFrame(0, id))) {
                frame = tmcrsGetEventModelFrame(0, id);
            }
            if ((vspev01Camera[ii].cnt < cnt) && (event->game.pause == 0)) {
                vspev01Camera[ii].cnt += 1;
            }
        }
        sceVu0SubVector(tmp, &vspev01Camera[ii].trans, rider->sys_mat->cam_trans);
        sceVu0MulVector(tmp, tmp, tmp);
        if (tmp[0] + tmp[1] + tmp[2] < 160000.0f) {
            sceVu0UnitMatrix(vspev01CameraMdl[ii].matrix);
            sceVu0RotMatrixY(vspev01CameraMdl[ii].matrix, vspev01CameraMdl[ii].matrix, vspev01CameraMdl[ii].pos[0]);
            sceVu0TransMatrix(vspev01CameraMdl[ii].matrix, vspev01CameraMdl[ii].matrix, &vspev01Camera[ii].trans);
            vspev01CameraMdl[ii].frame = frame;
            vspev01CameraMdl[ii].id = id;
            if ((id == 4) && (vspev01CameraMdl[ii].draw == 0)) {
                vspev01CameraMdl[ii].draw = 0;
            } else {
                vspev01CameraMdl[ii].draw = 1;
                vspev01CameraMdl[ii].light = 1;
            }
            tmcrsSetObjectDrawFlag(sprt_tbl[ii], 0);
        } else {
            vspev01CameraMdl[ii].draw = 0;
            vspev01CameraMdl[ii].id = 2;
            vspev01CameraMdl[ii].old_id = 2;
            if (id != 4) {
                tmcrsSetObjectDrawFlag(sprt_tbl[ii], 1);
            }
        }
    }
}

signed int spev01CheckCamera(signed int no) {
    return vspev01Camera[no].flag;
}

void spev01ResetTower(signed int vs) {
    vspev01TowerMdl = &vspev01EventMdl[4];
    vspev01TowerMdl->no = 1;
    vspev01TowerMdl->id = 5;
    vspev01TowerMdl->frame = 0.0f;
    vspev01TowerMdl->draw = 0;
    vspev01TowerMdl->light = 0;
    sceVu0UnitMatrix(vspev01TowerMdl->matrix);
    tmcrsSetObjectScissorFlag(0x94, 1);
    tmcrsSetObjectScissorFlag(0x90, 1);
    tmcrsSetObjectScissorFlag(0x96, 1);
    tmcrsSetObjectScissorFlag(0x95, 1);
    tmcrsSetRailCollision(0x173, 0);
    tmcrsSetRailCollision(0x174, 0);
    tmcrsSetObjectDrawFlag(0x90, 0);
    tmcrsSetObjectDrawFlag(0x95, 0);
    tmcrsSetObjectDrawFlag(0x91, 0);
    tmcrsSetObjectDrawFlag(0x92, 0);
    tmcrsSetObjectDrawFlag(0x93, 0);
    if (vs == 1) {
        tmcrsSetObjectDrawFlag(0x94, 0);
        tmcrsSetObjectDrawFlag(0x96, 0);
        tmcrsSetObjectDrawFlag(0x90, 1);
        tmcrsSetObjectDrawFlag(0x95, 1);
        tmcrsSetObjectDrawFlag(0x91, 1);
        tmcrsSetObjectDrawFlag(0x92, 1);
        tmcrsSetObjectDrawFlag(0x93, 1);
        tmcrsSetRailCollision(0x173, 1);
        tmcrsSetRailCollision(0x174, 1);
        tmevSetFlag(0x7C, 7);
    }
}

void spev01MoveTower(Event* event) {
    float pos1[4]; // 0x40(r29)
    float pos2[4]; // 0x50(r29)
    signed int sw; // r16
    signed int cnt; // r17
    float frame; // 0x6C(r29)

    sw = 0;
    pos1[0] = -388.25f;
    pos1[1] = 660.25f;
    pos1[2] = -946.18f;
    pos1[3] = 1.0f;
    pos2[0] = -358.21f;
    pos2[1] = 630.89f;
    pos2[2] = -919.04f;
    pos2[3] = 1.0f;
    if (tmevGetFinish(0) != 1) {
        if (tmevGetFlag(0x7C) == 5) {
            tmcrsSetObjectDrawFlag(0x94, 0);
            tmcrsSetObjectDrawFlag(0x96, 0);
            tmcrsSetRailCollision(0x173, 1);
            tmcrsSetRailCollision(0x174, 1);
            tmcrsSetHitCollision(0x260, 0, 0xC009);
            tmcrsSetHitCollision(0x261, 0, 9);
            tmcrsSetHitCollision(0x264, 9, 0);
            tmcrsSetHitCollision(0x265, 8, 0);
            vspev01TowerMdl->draw = 1;
            tmevStartICounter(0x3D);
            if (tmevGetICounter(0x3D) == 0xB4) {
                spEnterEventCameraMode();
                knEventStart();
                knEventSetCameraPos(&pos1[0]);
                knEventSetCameraObj(&pos2[0]);
                nmeventPlay2(0, 0x15);
                tmevSetFlag(0x7C, 6);
                tmevResetICounter(0x3D);
            }
            sw = 1;
        } else if (tmevGetFlag(0x7C) == 6) {
            frame = tmcrsGetEventModelFrame(1, 5);
            cnt = ((60.0f + frame) - 1.0f) / vspev01AnimFrame;
            vspev01TowerMdl->frame = vspev01AnimFrame * (tmevGetICounter(0x3D) % cnt);
            if (vspev01TowerMdl->frame > frame) {
                vspev01TowerMdl->frame = frame;
            }
            sw = 1;
            if ((signed int)(0.57 * (float)cnt) == tmevGetICounter(0x3D)) {
                nmeventPlay2(0, 0x14);
                tmevSetVib(event, 1, 0, 7);
                knEventSetShake(5.0f, 0.9f);
                tmevSetFlag(0x7D, 1);
            }
            if (cnt == tmevGetICounter(0x3D)) {
                tmevSetFlag(0x7D, 0);
                spExitEventCameraMode();
                knEventEnd();
                tmevSetFlag(0x7C, 7);
                tmcrsSetObjectDrawFlag(0x90, 1);
                tmcrsSetObjectDrawFlag(0x95, 1);
                tmcrsSetObjectDrawFlag(0x91, 1);
                tmcrsSetObjectDrawFlag(0x92, 1);
                tmcrsSetObjectDrawFlag(0x93, 1);
                vspev01TowerMdl->draw = 0;
                tmevStopICounter(0x3D);
                tmevResetICounter(0x3D);
                sw = 0;
            }
        }
        knReplaySetObstPos(0, sw, 0);
    }
}

void spev01SetTowerCollision() {
    if (tmevGetFlag(0x7C) > 4) {
        tmcrsSetHitCollision(0x260, 0, 0xC009);
        tmcrsSetHitCollision(0x261, 0, 9);
        tmcrsSetHitCollision(0x264, 9, 0);
        tmcrsSetHitCollision(0x265, 8, 0);
        return;
    }
    tmcrsSetHitCollision(0x25F, 0, 9);
    tmcrsSetHitCollision(0x262, 9, 0);
    tmcrsSetHitCollision(0x263, 8, 0);
}

void spev01ResetLiftMan(int vs) {
    signed int ii; // r16
    s32* tbl_ptr;
    signed int tbl[2] = {
        0x2F, 0x30
    }; // 0x38(r29)

    tbl_ptr = &tbl;
    vspev01LiftManMdl = &vspev01EventMdl[5];
    for (ii = 0; ii < 2; ii++) {
        vspev01LiftManVoice[ii] = 0;
        vspev01LiftMan[ii].trans[0] = 0.0f;
        vspev01LiftMan[ii].trans[1] = 0.0f;
        vspev01LiftMan[ii].trans[2] = 0.0f;
        vspev01LiftMan[ii].trans[3] = 1.0f;
        tmcrsGetObjectPosition(vspev01LiftMan[ii].trans, tbl[ii]);
        vspev01LiftMan[ii].trans[1] += 10.0f;
        vspev01LiftMan[ii].cnt = 0;
        vspev01LiftMan[ii].flag = 0;
        vspev01LiftMan[ii].tmp = 0.0f;
        vspev01LiftMan[ii].no = 0;
        vspev01LiftManMdl[ii].no = 2;
        vspev01LiftManMdl[ii].id = 7;
        vspev01LiftManMdl[ii].frame = 0.0f;
        vspev01LiftManMdl[ii].draw = 0;
        vspev01LiftManMdl[ii].light = 1;
        sceVu0UnitMatrix(vspev01LiftManMdl[ii].matrix);
        sceVu0RotMatrixY(vspev01LiftManMdl[ii].matrix, vspev01LiftManMdl[ii].matrix, vspev01LiftMan[ii].tmp);
        sceVu0TransMatrix(vspev01LiftManMdl[ii].matrix, vspev01LiftManMdl[ii].matrix, vspev01LiftMan[ii].trans);
        tmcrsSetObjectDrawFlag(tbl[ii], 0);
    }
}

void spev01MoveLiftMan(// Size: 0x8C, DWARF: 0x16775A
    Event* event) {
    // Size: 0x2C00, DWARF: 0x16AA87
    Ctrl* rider; // r21
    signed int ii; // r16
    signed int jj; // r17
    signed int id; // r18
    signed int player; // r19
    signed int cnt; // r20

    float tmp[4]; // 0x80(r29)
    signed int tbl[2] = { /* @1263 */
        0x4E49454E, 0
    }; // 0x98(r29)
    float len[2]; // 0xA0(r29)
    float angle; // 0xA8(r29)
    float frame; // 0xAC(r29)
    s32* tbl_ptr = &tbl;

    // event = event; // b0
    for (ii = 0; ii < 2; ii++) {
        len[0] = 1.6777e7f;
        len[1] = 1.6777e7f;
        for (jj = 0; jj < event->game.nplayer; jj++) {
            if ((event->game.nplayer <= 1) || (vspenvGame->mode.match_rule != 3) || (jj == event->game.player)) {
                sceVu0SubVector(tmp, vspev01LiftMan[ii].trans, event->character[jj].ctrl->nowpos.pos);
                sceVu0MulVector(tmp, tmp, tmp);
                len[jj] = tmp[0] + tmp[2];
            }
        }
        if ((1 < event->game.nplayer) && (vspenvGame->mode.match_rule == 3)) {
            rider = event->character[event->game.player].ctrl;
            player = event->game.player;
        } else {
            rider = event->character[0].ctrl;
            player = 0;
            if ((len[1] < len[0]) && (1 < event->game.nplayer)) {
                rider = event->character[1].ctrl;
                player = 1;
            }
        }
        id = 7;
        // temp_f0 = tmcrsGetEventModelFrame(2, id);
        frame = tmcrsGetEventModelFrame(2, id);
        cnt = ((60.0f + frame) - 1.0f) / vspev01AnimFrame;
        frame = vspev01AnimFrame * (tmevGetICounter(0) % cnt);
        if ((frame > tmcrsGetEventModelFrame(2, id))) {
            frame = tmcrsGetEventModelFrame(2, id);
        }
        sceVu0SubVector(tmp, vspev01LiftMan[ii].trans, rider->nowpos.pos);
        angle = atan2f(tmp[0], tmp[2]);
        sceVu0MulVector(tmp, tmp, tmp);
        if ((tmevGetEventMdlHit(rider, 10.0f, ii + 5, 0) == 1) && (tmcrsGetObjectDrawFlag(tbl[ii]) == 0)) {
            if (vspev01LiftMan[ii].flag != 3) {
                vspev01LiftMan[ii].cnt = 0;
                nmvcSetOptVol(nmactGetVoiceVol(0), 0);
                nmeventPlayVoice(player, 0x1C);
                tmevSetVib(event, 0, 5, 7);
            }
            vspev01LiftMan[ii].flag = 3;
        }
        if (len[player] < 10000.0f) {
            if ((vspev01LiftManVoice[ii] == 0) && (vspev01LiftMan[ii].flag != 3) && (tmcrsGetObjectDrawFlag(tbl[ii]) == 0)) {
                nmeventPlayVoice(player, (tmevGetICounter(0) % 3) + 0x19);
                vspev01LiftManVoice[ii] = 1;
            }
        } else {
            vspev01LiftManVoice[ii] = 0;
        }
        if (vspev01LiftMan[ii].flag == 0) {
            if ((vspev01LiftManMdl[ii].old_id != 7) && (vspev01LiftMan[ii].cnt != 0)) {
                id = 7;
                frame = vspev01AnimFrame * vspev01LiftMan[ii].cnt;
                if ((frame > tmcrsGetEventModelFrame(2, id))) {
                    frame = tmcrsGetEventModelFrame(2, id);
                }
                if ((event->game.pause == 0) && (vspev01LiftMan[ii].cnt > 0)) {
                    vspev01LiftMan[ii].cnt--;
                }
            } else {
                id = 7;
                if (event->game.pause == 0) {
                    vspev01LiftMan[ii].cnt++;
                    if (cnt < vspev01LiftMan[ii].cnt) {
                        vspev01LiftMan[ii].cnt = 0;
                    }
                }
            }
            if (event->game.pause == 0) {
                vspev01LiftMan[ii].tmp = angle;
            }
            if ((len[player] < 40000.0f) && (tmcrsGetObjectDrawFlag(tbl[ii]) == 0)) {
                vspev01LiftMan[ii].flag = 1;
                vspev01LiftMan[ii].cnt = 0;
            }
        } else {
            if (vspev01LiftMan[ii].flag == 1) {
                id = 0;
                frame = tmcrsGetEventModelFrame(2, id);
                cnt = ((60.0f + frame) - 1.0f) / vspev01AnimFrame;
                frame = vspev01AnimFrame * vspev01LiftMan[ii].cnt;
                if ((frame > tmcrsGetEventModelFrame(2, id))) {
                    frame = tmcrsGetEventModelFrame(2, id);
                }
                if (event->game.pause == 0) {
                    vspev01LiftMan[ii].tmp = angle;
                    if (cnt < vspev01LiftMan[ii].cnt) {
                        vspev01LiftMan[ii].cnt++;
                    } else {
                        vspev01LiftMan[ii].flag = 2;
                        vspev01LiftMan[ii].cnt = 0;
                    }
                }
                if ((len[player] > 40000.0f)) {
                    vspev01LiftMan[ii].flag = 0;
                }
            } else if (vspev01LiftMan[ii].flag == 2) {
                id = 1;
                frame = tmcrsGetEventModelFrame(2, id);
                cnt = ((60.0f + frame) - 1.0f) / vspev01AnimFrame;
                frame = vspev01AnimFrame * vspev01LiftMan[ii].cnt;
                if ((frame > tmcrsGetEventModelFrame(2, id))) {
                    frame = tmcrsGetEventModelFrame(2, id);
                }
                if (event->game.pause == 0) {
                    vspev01LiftMan[ii].tmp = angle;
                    vspev01LiftMan[ii].cnt++;
                    if (cnt < vspev01LiftMan[ii].cnt) {
                        vspev01LiftMan[ii].cnt = 0;
                    }
                }
                if ((len[player] > 40000.0f)) {
                    vspev01LiftMan[ii].flag = 0;
                }
            } else if (vspev01LiftMan[ii].flag == 3) {
                id = 6;
                frame = tmcrsGetEventModelFrame(2, id);
                cnt = ((60.0f + frame) - 1.0f) / vspev01AnimFrame;
                frame = vspev01AnimFrame * vspev01LiftMan[ii].cnt;
                if ((frame > tmcrsGetEventModelFrame(2, id))) {
                    frame = tmcrsGetEventModelFrame(2, id);
                }
                if ((event->game.pause == 0) && (vspev01LiftMan[ii].cnt < cnt)) {
                    vspev01LiftMan[ii].cnt++;
                }
            }
        }
        sceVu0SubVector(tmp, vspev01LiftMan[ii].trans, rider->sys_mat->cam_trans);
        sceVu0MulVector(tmp, tmp, tmp);
        if ((tmp[0] + tmp[1] + tmp[2]) < 160000.0f) {
            sceVu0UnitMatrix(vspev01LiftManMdl[ii].matrix);
            sceVu0RotMatrixY(vspev01LiftManMdl[ii].matrix, vspev01LiftManMdl[ii].matrix, vspev01LiftMan[ii].tmp);
            sceVu0TransMatrix(vspev01LiftManMdl[ii].matrix, vspev01LiftManMdl[ii].matrix, vspev01LiftMan[ii].trans);
            vspev01LiftManMdl[ii].frame = frame;
            vspev01LiftManMdl[ii].id = id;
            vspev01LiftManMdl[ii].draw = 1;
            tmcrsSetObjectDrawFlag(tbl[ii], 0);
        } else {
            vspev01LiftMan[ii].flag = 0;
            vspev01LiftManMdl[ii].draw = 0;
            vspev01LiftManMdl[ii].id = 7;
            vspev01LiftManMdl[ii].old_id = 7;
            tmcrsSetObjectDrawFlag(tbl[ii], 1);
        }
    }
}
