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
void sceVu0CopyVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0Normalize(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0MulVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);

//////// vspRider Struct ///////////////////////////////////////////////

// Size: 0x30, DWARF: 0x7DAC1, 0x1C06F9
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x7DADD
    signed int always_sp; // Offset: 0x4, DWARF: 0x7DAFE
    signed int perfect_b; // Offset: 0x8, DWARF: 0x7DB24
    signed int super_spin; // Offset: 0xC, DWARF: 0x7DB4A
    signed int half_g; // Offset: 0x10, DWARF: 0x7DB71
    signed int fast_motion; // Offset: 0x14, DWARF: 0x7DB94
    signed int super_speed; // Offset: 0x18, DWARF: 0x7DBBC
    signed int big_head; // Offset: 0x1C, DWARF: 0x7DBE4
    signed int metallic; // Offset: 0x20, DWARF: 0x7DC09
    signed int mirror; // Offset: 0x24, DWARF: 0x7DC2E
    signed int replay_view; // Offset: 0x28, DWARF: 0x7DC51
    signed int partition; // Offset: 0x2C, DWARF: 0x7DC79
} Cheats;

// Size: 0x28, DWARF: 0x7DEB2
typedef struct Param {
    signed int quickness; // Offset: 0x0, DWARF: 0x7DECE
    signed int jump_power; // Offset: 0x4, DWARF: 0x7DEF4
    signed int turning; // Offset: 0x8, DWARF: 0x7DF1B
    signed int sit_turning; // Offset: 0xC, DWARF: 0x7DF3F
    signed int quick_turning; // Offset: 0x10, DWARF: 0x7DF67
    signed int max_speed; // Offset: 0x14, DWARF: 0x7DF91
    signed int cmn_max_speed; // Offset: 0x18, DWARF: 0x7DFB7
    signed int spin; // Offset: 0x1C, DWARF: 0x7DFE1
    signed int grind; // Offset: 0x20, DWARF: 0x7E002
    signed int landing; // Offset: 0x24, DWARF: 0x7E024
} Param;

// Size: 0x24, DWARF: 0x7C294
typedef struct Param2 // (Includes additional stats not able to be set by player, like power/quickness)
{
    signed int ollie; // Offset: 0x0, DWARF: 0x7C2B0
    signed int spin; // Offset: 0x4, DWARF: 0x7C2D2
    signed int speed; // Offset: 0x8, DWARF: 0x7C2F3
    signed int landing; // Offset: 0xC, DWARF: 0x7C315
    signed int landing_switch; // Offset: 0x10, DWARF: 0x7C339
    signed int balance; // Offset: 0x14, DWARF: 0x7C364
    signed int quickness; // Offset: 0x18, DWARF: 0x7C388
    signed int power; // Offset: 0x1C, DWARF: 0x7C3AE
    signed int turning; // Offset: 0x20, DWARF: 0x7C3D0
} Param2;

// Size: 0x10, DWARF: 0x7A1DB, 0x16DA24
typedef struct Board_Param
{
    signed int speed; // Offset: 0x0, DWARF: 0x7A1F7
    signed int stability; // Offset: 0x4, DWARF: 0x7A219
    signed int balance; // Offset: 0x8, DWARF: 0x7A23F
    signed int turning; // Offset: 0xC, DWARF: 0x7A263
} Board_Param;

// Size: 0x1C, DWARF: 0x7C601, 0x16D2B9
typedef struct Character_Param
{
    signed int ollie; // Offset: 0x0, DWARF: 0x7C61D
    signed int spin; // Offset: 0x4, DWARF: 0x7C63F
    signed int speed; // Offset: 0x8, DWARF: 0x7C660
    signed int landing; // Offset: 0xC, DWARF: 0x7C682
    signed int balance; // Offset: 0x10, DWARF: 0x7C6A6
    signed int stability; // Offset: 0x14, DWARF: 0x7C6CA
    signed int stance; // Offset: 0x18, DWARF: 0x7C6F0
} Character_Param;

// Size: 0x14, DWARF: 0x7C447
typedef struct Balance
{
    float balance; // Offset: 0x0, DWARF: 0x7C463
    float lean; // Offset: 0x4, DWARF: 0x7C487
    float lean_dir; // Offset: 0x8, DWARF: 0x7C4A8
    signed int released; // Offset: 0xC, DWARF: 0x7C4CD
    signed int cnt_free; // Offset: 0x10, DWARF: 0x7C4F2
} Balance;

// Size: 0x30, DWARF: 0x79C3C, 0x1737CD
typedef struct Plane
{
    float cross[4]; // Offset: 0x0, DWARF: 0x79C58
    float normal[4]; // Offset: 0x10, DWARF: 0x79C7C
    unsigned short material; // Offset: 0x20, DWARF: 0x79CA1
    unsigned short attribute; // Offset: 0x22, DWARF: 0x79CC6
    signed short almighty1; // Offset: 0x24, DWARF: 0x79CEC
    signed short almighty2; // Offset: 0x26, DWARF: 0x79D12
    signed short almighty3; // Offset: 0x28, DWARF: 0x79D38
    signed short slidable; // Offset: 0x2A, DWARF: 0x79D5E
    signed int available; // Offset: 0x2C, DWARF: 0x79D83
} Plane;

// Size: 0x60, DWARF: 0x75E44
typedef struct Col
{
    float normal[4]; // Offset: 0x0, DWARF: 0x75E5F
    float point[4]; // Offset: 0x10, DWARF: 0x75E84
    sceVu0FVECTOR* vertex; // Offset: 0x20, DWARF: 0x75EA8 // float*[4]
    unsigned int attr; // Offset: 0x24, DWARF: 0x75ED0
    signed int nvertex; // Offset: 0x28, DWARF: 0x75EF1
    signed int no; // Offset: 0x2C, DWARF: 0x75F15
    float len; // Offset: 0x30, DWARF: 0x75F34
    signed int rail_no; // Offset: 0x34, DWARF: 0x75F54
    signed int obj_no; // Offset: 0x38, DWARF: 0x75F78
    signed int obj_attr; // Offset: 0x3C, DWARF: 0x75F9B
    signed int obj_type; // Offset: 0x40, DWARF: 0x75FC0
    signed int res[4]; // Offset: 0x44, DWARF: 0x75FE5
    char padding[12]; // Not normally in the struct, but pads to make it the expected size.
} Col;

// Size: 0x60, DWARF: 0x79DD3, 0x16E55B
typedef struct Pos
{
    float pos[4]; // Offset: 0x0, DWARF: 0x79DEF
    float cross[4]; // Offset: 0x10, DWARF: 0x79E11
    float normal[4]; // Offset: 0x20, DWARF: 0x79E35
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

// DWARF: 0x1C3C55
typedef enum FlowMode
{
    efmIntro,
    efmHorseReady,
    efmReady,
    efmPlay,
    efmEnd,
    efmRepReady,
    efmReplay,
    efmRepEnd,
    efmResult
} FlowMode;

// DWARF: 0x7EA91, 0x1C52E1
typedef enum Ripside
{
    ersNoRip,
    ersLeft,
    ersRight
} Ripside;

typedef enum Restart
{
    ersNone,
    ersNormal,
    ersReplay
} Restart;

// Size: 0x10, DWARF: 0x7A4D2
typedef struct Cmd
{
    signed short type; // Offset: 0x0, DWARF: 0x7A4EE
    char way1; // Offset: 0x2, DWARF: 0x7A50F
    char way2; // Offset: 0x3, DWARF: 0x7A530
    char way3; // Offset: 0x4, DWARF: 0x7A551
    char way4; // Offset: 0x5, DWARF: 0x7A572
    unsigned short fin_button; // Offset: 0x6, DWARF: 0x7A593
    char rev_button; // Offset: 0x8, DWARF: 0x7A5BA
    char inp_fin_button; // Offset: 0x9, DWARF: 0x7A5E1
    char left_count; // Offset: 0xA, DWARF: 0x7A60C
    char fin_left_count; // Offset: 0xB, DWARF: 0x7A633
    char step; // Offset: 0xC, DWARF: 0x7A65E
    char ok; // Offset: 0xD, DWARF: 0x7A67F
    char passtime; // Offset: 0xE, DWARF: 0x7A69E
    char tmp; // Offset: 0xF, DWARF: 0x7A6C3
} Cmd;

// Size: 0x48, DWARF: 0x7C763, 0x16EEA4
typedef struct Req
{
    // DWARF: 0x80E2D
    Acceleration_Brake accel_brake; // Offset: 0x0, DWARF: 0x7C77F
    signed int sitting; // Offset: 0x4, DWARF: 0x7C7A9
    // DWARF: 0x7BAC5
    Jump_Strength jump; // Offset: 0x8, DWARF: 0x7C7CD
    // DWARF: 0x81681
    ERSC_Stance_Change stance_change; // Offset: 0xC, DWARF: 0x7C7F0
    // DWARF: 0x821D6
    ERC_Command command; // Offset: 0x10, DWARF: 0x7C81C
    signed int cmd_mot_id; // Offset: 0x14, DWARF: 0x7C842
    signed int cmd_mot_nloop; // Offset: 0x18, DWARF: 0x7C869
    signed int cmd_trick_no; // Offset: 0x1C, DWARF: 0x7C893
    signed int end_fall; // Offset: 0x20, DWARF: 0x7C8BC
    signed int trick_no; // Offset: 0x24, DWARF: 0x7C8E1
    signed int flip_no; // Offset: 0x28, DWARF: 0x7C906
    signed int grind_no; // Offset: 0x2C, DWARF: 0x7C92A
    signed int plant_no; // Offset: 0x30, DWARF: 0x7C94F
    signed int bonk_no; // Offset: 0x34, DWARF: 0x7C974
    signed int manual_no; // Offset: 0x38, DWARF: 0x7C998
    signed int revert_no; // Offset: 0x3C, DWARF: 0x7C9BE
    signed int jump_no; // Offset: 0x40, DWARF: 0x7C9E4
    signed int sptrk_id; // Offset: 0x44, DWARF: 0x7CA08
} Req;

// Size: 0x3C, DWARF: 0x7600B, 0x16B0EF
typedef struct Inp
{
    signed int turn; // Offset: 0x0, DWARF: 0x76026
    signed int turn_x; // Offset: 0x4, DWARF: 0x76047
    signed int quick_turn; // Offset: 0x8, DWARF: 0x7606A
    // DWARF: 0x7909A
    Acceleration_State accel_state; // Offset: 0xC, DWARF: 0x76091
    // DWARF: 0x7CC36
    Jump_State jump_state; // Offset: 0x10, DWARF: 0x760BB
    // DWARF: 0x7ECA8
    Stance_Change stance_change; // Offset: 0x14, DWARF: 0x760E4
    // DWARF: 0x8178B
    ESP_Spin_Way spin_way; // Offset: 0x18, DWARF: 0x76110
    // DWARF: 0x7F831
    Trick_Command command; // Offset: 0x1C, DWARF: 0x76137
    signed int cmd_mot_id; // Offset: 0x20, DWARF: 0x7615D
    signed int cmd_mot_nloop; // Offset: 0x24, DWARF: 0x76184
    signed int cmd_trick_no; // Offset: 0x28, DWARF: 0x761AE
    // DWARF: 0x79055
    Key_Way keyway; // Offset: 0x2C, DWARF: 0x761D7
    signed int tumble_speed_up; // Offset: 0x30, DWARF: 0x761FC
    signed int accel_speed; // Offset: 0x34, DWARF: 0x76228
    signed int stop_speed; // Offset: 0x38, DWARF: 0x76250
} Inp;

// Size: 0x98, DWARF: 0x791A9
typedef struct TrickLink
{
    signed int trick_link; // Offset: 0x0, DWARF: 0x791C4
    signed int trg_start_link; // Offset: 0x4, DWARF: 0x791EB
    signed int trg_end_link; // Offset: 0x8, DWARF: 0x79216
    signed int trg_get_pts; // Offset: 0xC, DWARF: 0x7923F
    signed int spenv_get_trick_no; // Offset: 0x10, DWARF: 0x79267
    signed int pre_cnt_link; // Offset: 0x14, DWARF: 0x79296
    signed int cnt_link; // Offset: 0x18, DWARF: 0x792BF
    signed int cnt_trick; // Offset: 0x1C, DWARF: 0x792E4
    unsigned int last_point; // Offset: 0x20, DWARF: 0x7930A
    // DWARF: 0x807AE
    Landing_Bonus is_bonus_landing; // Offset: 0x24, DWARF: 0x79331
    signed int is_bonus_switch; // Offset: 0x28, DWARF: 0x79360
    signed int is_bonus_spin; // Offset: 0x2C, DWARF: 0x7938C
    signed int is_bonus_airtime; // Offset: 0x30, DWARF: 0x793B6
    signed int set_top_cnt_link; // Offset: 0x34, DWARF: 0x793E3
    signed int added_nollie; // Offset: 0x38, DWARF: 0x79410
    signed int added_airtime; // Offset: 0x3C, DWARF: 0x79439
    signed int trg_trick; // Offset: 0x40, DWARF: 0x79463
    unsigned int pts_current_trick; // Offset: 0x44, DWARF: 0x79489
    unsigned int pts_current_hold; // Offset: 0x48, DWARF: 0x794B7
    unsigned int pts_current_spin; // Offset: 0x4C, DWARF: 0x794E4
    unsigned int pts_trick; // Offset: 0x50, DWARF: 0x79511
    unsigned int pts_gap; // Offset: 0x54, DWARF: 0x79537
    signed int cnt_total_hold; // Offset: 0x58, DWARF: 0x7955B
    signed int spin_ang; // Offset: 0x5C, DWARF: 0x79586
    signed int last_spin_ang; // Offset: 0x60, DWARF: 0x795AB
    signed int airtime_frame; // Offset: 0x64, DWARF: 0x795D5
    unsigned int current_set_tp; // Offset: 0x68, DWARF: 0x795FF
    unsigned int current_set_tp_rate; // Offset: 0x6C, DWARF: 0x7962A
    signed int link_rate; // Offset: 0x70, DWARF: 0x7965A
    unsigned int link_trick_point; // Offset: 0x74, DWARF: 0x79680
    unsigned int total_trick_point; // Offset: 0x78, DWARF: 0x796AD
    unsigned int last_link_trick_point; // Offset: 0x7C, DWARF: 0x796DB
    unsigned int get_point; // Offset: 0x80, DWARF: 0x7970D
    signed int total_trick_num; // Offset: 0x84, DWARF: 0x79733
    signed int best_link_num; // Offset: 0x88, DWARF: 0x7975F
    unsigned int best_link_pts; // Offset: 0x8C, DWARF: 0x79789
    signed int get_the_best; // Offset: 0x90, DWARF: 0x797B3
    signed int pre_spin_ang; // Offset: 0x94, DWARF: 0x797DC
} TrickLink;

// Size: 0x8, DWARF: 0x168106
typedef struct Pad
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x168121
    signed char lh; // Offset: 0x2, DWARF: 0x168141
    signed char lv; // Offset: 0x3, DWARF: 0x168160
    signed int analog; // Offset: 0x4, DWARF: 0x16817F
} Pad;

// Size: 0x1F0, DWARF: 0x7B067
typedef struct Sbcore
{
    float nextpos[4]; // Offset: 0x0, DWARF: 0x7B083
    float speed[4]; // Offset: 0x10, DWARF: 0x7B0A9
    float rot_pole; // Offset: 0x20, DWARF: 0x7B0CD
    float max_relief_gap; // Offset: 0x24, DWARF: 0x7B0F2
    signed int freefoot; // Offset: 0x28, DWARF: 0x7B11D
    float limit_ang_down; // Offset: 0x2C, DWARF: 0x7B142
    float limit_ang_up; // Offset: 0x30, DWARF: 0x7B16D
    signed int set_sp_normal; // Offset: 0x34, DWARF: 0x7B196
    float pos_head[4] __attribute__((aligned(16))); // Offset: 0x40, DWARF: 0x7B1C0
    float pos_hip[4]; // Offset: 0x50, DWARF: 0x7B1E7
    signed int move_head; // Offset: 0x60, DWARF: 0x7B20D
    float ang_slidable_limit; // Offset: 0x64, DWARF: 0x7B233
    float pos[4] __attribute__((aligned(16))); // Offset: 0x70, DWARF: 0x7B262
    float pole[4]; // Offset: 0x80, DWARF: 0x7B284
    float sp_normal[4]; // Offset: 0x90, DWARF: 0x7B2A7
    signed int sliding; // Offset: 0xA0, DWARF: 0x7B2CF
    float relief_gap; // Offset: 0xA4, DWARF: 0x7B2F3
    float touch_posy; // Offset: 0xA8, DWARF: 0x7B31A
    float const_max_relief_gap; // Offset: 0xAC, DWARF: 0x7B341
    float const_under_foot; // Offset: 0xB0, DWARF: 0x7B372
    signed int const_keep_normal; // Offset: 0xB4, DWARF: 0x7B39F
    float height; // Offset: 0xB8, DWARF: 0x7B3CD
    signed int cnt_keep_normal; // Offset: 0xBC, DWARF: 0x7B3F0
    signed int move; // Offset: 0xC0, DWARF: 0x7B41C
    // Size: 0x30, DWARF: 0x79C3C
    Plane plane_hit __attribute__((aligned(16))); // Offset: 0xD0, DWARF: 0x7B43D
    // Size: 0x30, DWARF: 0x79C3C
    Plane plane_sliding; // Offset: 0x100, DWARF: 0x7B465
    // Size: 0x30, DWARF: 0x79C3C
    Plane plane_beneath; // Offset: 0x130, DWARF: 0x7B491
    // Size: 0x30, DWARF: 0x79C3C
    Plane plane_body; // Offset: 0x160, DWARF: 0x7B4BD
    // Size: 0x30, DWARF: 0x79C3C
    Plane plane_hit_buff; // Offset: 0x190, DWARF: 0x7B4E6
    // Size: 0x30, DWARF: 0x79C3C
    Plane plane_pre_hit; // Offset: 0x1C0, DWARF: 0x7B513
} Sbcore;

// Size: 0x2580, DWARF: 0x76810
typedef struct Act
{
    // Size: 0x1F0, DWARF: 0x7B067
    Sbcore sbcore; // Offset: 0x0, DWARF: 0x7682B
    // Size: 0x30, DWARF: 0x79C3C
    Plane wall; // Offset: 0x1F0, DWARF: 0x76850
    signed int cnt_freefoot; // Offset: 0x220, DWARF: 0x76873
    signed int cnt_turn; // Offset: 0x224, DWARF: 0x7689C
    signed int cnt_sitting; // Offset: 0x228, DWARF: 0x768C1
    signed int cnt_spinkey; // Offset: 0x22C, DWARF: 0x768E9
    signed int cnt_d2c; // Offset: 0x230, DWARF: 0x76911
    signed int cnt_to_rail; // Offset: 0x234, DWARF: 0x76935
    signed int cnt_grind; // Offset: 0x238, DWARF: 0x7695D
    signed int cnt_real_grind; // Offset: 0x23C, DWARF: 0x76983
    signed int cnt_manual; // Offset: 0x240, DWARF: 0x769AE
    signed int cnt_total_grind; // Offset: 0x244, DWARF: 0x769D5
    signed int cnt_total_manual; // Offset: 0x248, DWARF: 0x76A01
    signed int cnt_plant; // Offset: 0x24C, DWARF: 0x76A2E
    signed int cnt_holding; // Offset: 0x250, DWARF: 0x76A54
    signed int cnt_planttumble; // Offset: 0x254, DWARF: 0x76A7C
    signed int cnt_plant2grind; // Offset: 0x258, DWARF: 0x76AA8
    signed int cnt_tumble; // Offset: 0x25C, DWARF: 0x76AD4
    signed int cnt_nospin; // Offset: 0x260, DWARF: 0x76AFB
    signed int cnt_brake; // Offset: 0x264, DWARF: 0x76B22
    signed int cnt_backward; // Offset: 0x268, DWARF: 0x76B48
    signed int cnt_no_bodyhit; // Offset: 0x26C, DWARF: 0x76B71
    signed int cnt_hokan; // Offset: 0x270, DWARF: 0x76B9C
    signed int jump_air; // Offset: 0x274, DWARF: 0x76BC2
    signed int def_goofy; // Offset: 0x278, DWARF: 0x76BE7
    signed int goofy; // Offset: 0x27C, DWARF: 0x76C0D
    signed int fakie; // Offset: 0x280, DWARF: 0x76C2F
    // DWARF: 0x7C53F
    Sliding_State sliding_state; // Offset: 0x284, DWARF: 0x76C51
    // DWARF: 0x7C53F
    Sliding_State pre_state; // Offset: 0x288, DWARF: 0x76C7D
    signed int nollie; // Offset: 0x28C, DWARF: 0x76CA5
    signed int big_ollie; // Offset: 0x290, DWARF: 0x76CC8
    signed int super_ollie; // Offset: 0x294, DWARF: 0x76CEE
    signed int plant_to_fakie; // Offset: 0x298, DWARF: 0x76D16
    signed int trick_keep; // Offset: 0x29C, DWARF: 0x76D41
    // DWARF: 0x7E931
    Tumble_Type tumble_type; // Offset: 0x2A0, DWARF: 0x76D68
    // DWARF: 0x7FF3C
    Tumble_Way tumble_way; // Offset: 0x2A4, DWARF: 0x76D92
    signed int trg_hopup; // Offset: 0x2A8, DWARF: 0x76DBB
    signed int trg_jumpup; // Offset: 0x2AC, DWARF: 0x76DE1
    signed int trg_touch; // Offset: 0x2B0, DWARF: 0x76E08
    signed int trg_bonk; // Offset: 0x2B4, DWARF: 0x76E2E
    signed int trg_boost; // Offset: 0x2B8, DWARF: 0x76E53
    signed int trg_rewind; // Offset: 0x2BC, DWARF: 0x76E79
    signed int trg_hit_wall; // Offset: 0x2C0, DWARF: 0x76EA0
    signed int no_approach_speed; // Offset: 0x2C4, DWARF: 0x76EC9
    signed int hop_vertical_plane; // Offset: 0x2C8, DWARF: 0x76EF7
    signed int touch_perfect; // Offset: 0x2CC, DWARF: 0x76F26
    signed int grind_jump; // Offset: 0x2D0, DWARF: 0x76F50
    signed int grind_tumble; // Offset: 0x2D4, DWARF: 0x76F77
    signed int hips; // Offset: 0x2D8, DWARF: 0x76FA0
    signed int trg_onair_with_over_hp; // Offset: 0x2DC, DWARF: 0x76FC1
    // DWARF: 0x7E931
    Tumble_Type trg_tumble_type; // Offset: 0x2E0, DWARF: 0x76FF4
    // DWARF: 0x7FF3C
    Tumble_Way trg_tumble_way; // Offset: 0x2E4, DWARF: 0x77022
    signed int trg_tumble_body; // Offset: 0x2E8, DWARF: 0x7704F
    signed int end_grind; // Offset: 0x2EC, DWARF: 0x7707B
    signed int end_manual; // Offset: 0x2F0, DWARF: 0x770A1
    signed int end_sliding; // Offset: 0x2F4, DWARF: 0x770C8
    float max_relief_gap; // Offset: 0x2F8, DWARF: 0x770F0
    float relief_gap; // Offset: 0x2FC, DWARF: 0x7711B
    float slant; // Offset: 0x300, DWARF: 0x77142
    float side_slant; // Offset: 0x304, DWARF: 0x77164
    float sp_slant; // Offset: 0x308, DWARF: 0x7718B
    float sp_side_slant; // Offset: 0x30C, DWARF: 0x771B0
    float ofs_updown; // Offset: 0x310, DWARF: 0x771DA
    float target_way; // Offset: 0x314, DWARF: 0x77201
    sceVu0FVECTOR* pre_rail_list; // Offset: 0x318, DWARF: 0x77228 // float*[4]
    sceVu0FVECTOR* rail_list; // Offset: 0x31C, DWARF: 0x77257 // float*[4]
    signed int num_rail_vertex; // Offset: 0x320, DWARF: 0x77282
    signed int rail_id; // Offset: 0x324, DWARF: 0x772AE
    signed int rail_no; // Offset: 0x328, DWARF: 0x772D2
    sceVu0FVECTOR rail_pos __attribute__((aligned(16))); // Offset: 0x330, DWARF: 0x772F6
    // Size: 0x14, DWARF: 0x7C447
    Balance gr_balance; // Offset: 0x340, DWARF: 0x7731D
    float gr_enter_ang; // Offset: 0x354, DWARF: 0x77346
    signed int gr_reset_lean; // Offset: 0x358, DWARF: 0x7736F
    signed int trg_grind_name; // Offset: 0x35C, DWARF: 0x77399
    signed int gr_grind_no; // Offset: 0x360, DWARF: 0x773C4
    signed int gr_cnt_kissed; // Offset: 0x364, DWARF: 0x773EC
    signed int gr_is_reverse; // Offset: 0x368, DWARF: 0x77416
    signed int gr_back_accel; // Offset: 0x36C, DWARF: 0x77440
    signed int trg_change_grind; // Offset: 0x370, DWARF: 0x7746A
    signed int changed_grind; // Offset: 0x374, DWARF: 0x77497
    signed int disaster; // Offset: 0x378, DWARF: 0x774C1
    signed int first_grind; // Offset: 0x37C, DWARF: 0x774E6
    signed int gr_no_jump; // Offset: 0x380, DWARF: 0x7750E
    signed int hp_air; // Offset: 0x384, DWARF: 0x77535
    signed int pre_hp_air; // Offset: 0x388, DWARF: 0x77558
    signed int halfpiping; // Offset: 0x38C, DWARF: 0x7757F
    signed int pre_halfpiping; // Offset: 0x390, DWARF: 0x775A6
    signed int over_hp; // Offset: 0x394, DWARF: 0x775D1
    signed int hp_jump; // Offset: 0x398, DWARF: 0x775F5
    signed int hp_adj_roty; // Offset: 0x39C, DWARF: 0x77619
    sceVu0FVECTOR hp_normal; // Offset: 0x3A0, DWARF: 0x77641
    sceVu0FVECTOR hp_cross; // Offset: 0x3B0, DWARF: 0x77669
    signed int manual_ready; // Offset: 0x3C0, DWARF: 0x77690
    signed int manual_ready_no; // Offset: 0x3C4, DWARF: 0x776B9
    signed int manual_cnt_to_play; // Offset: 0x3C8, DWARF: 0x776E5
    // Size: 0x14, DWARF: 0x7C447
    Balance manu_balance; // Offset: 0x3CC, DWARF: 0x77714
    signed int manu_reset_lean; // Offset: 0x3E0, DWARF: 0x7773F
    signed int bonk_ready; // Offset: 0x3E4, DWARF: 0x7776B
    signed int bonk_ready_no; // Offset: 0x3E8, DWARF: 0x77792
    signed int bonk_goto; // Offset: 0x3EC, DWARF: 0x777BC
    sceVu0FVECTOR bonk_point; // Offset: 0x3F0, DWARF: 0x777E2
    sceVu0FVECTOR bonk_presp; // Offset: 0x400, DWARF: 0x7780B
    signed int revert_cnt_ready; // Offset: 0x410, DWARF: 0x77834
    signed int revert_ready_no; // Offset: 0x414, DWARF: 0x77861
    signed int plant_air; // Offset: 0x418, DWARF: 0x7788D
    sceVu0FVECTOR plant_normal __attribute__((aligned(16))); // Offset: 0x420, DWARF: 0x778B3
    float max_height; // Offset: 0x430, DWARF: 0x778DE
    signed int big_air; // Offset: 0x434, DWARF: 0x77905
    signed int cnt_onair; // Offset: 0x438, DWARF: 0x77929
    signed int cnt_onair2; // Offset: 0x43C, DWARF: 0x7794F
    signed int cnt_nothit; // Offset: 0x440, DWARF: 0x77976
    signed int tumble_se_id; // Offset: 0x444, DWARF: 0x7799D
    float jump_rot_pole; // Offset: 0x448, DWARF: 0x779C6
    float last_rot_pole; // Offset: 0x44C, DWARF: 0x779F0
    // DWARF: 0x8178B
    ESP_Spin_Way last_spin_way; // Offset: 0x450, DWARF: 0x77A1A
    sceVu0FVECTOR pos_waist __attribute__((aligned(16))); // Offset: 0x460, DWARF: 0x77A46
    float pos_disp[4]; // Offset: 0x470, DWARF: 0x77A6E
    float shadow_posy; // Offset: 0x480, DWARF: 0x77A95
    float max_speed; // Offset: 0x484, DWARF: 0x77ABD
    float cmn_max_speed; // Offset: 0x488, DWARF: 0x77AE3
    float now_max_speed; // Offset: 0x48C, DWARF: 0x77B0D
    // Size: 0x24, DWARF: 0x7C294
    Param2 param; // Offset: 0x490, DWARF: 0x77B37
    // Size: 0x1C, DWARF: 0x7C601
    Character_Param chr_param_x10; // Offset: 0x4B4, DWARF: 0x77B5B
    // Size: 0x10, DWARF: 0x7A1DB
    Board_Param brd_param_x10; // Offset: 0x4D0, DWARF: 0x77B87
    signed int mot_finish; // Offset: 0x4E0, DWARF: 0x77BB3
    signed int mot_grabing; // Offset: 0x4E4, DWARF: 0x77BDA
    signed int mot_flipping; // Offset: 0x4E8, DWARF: 0x77C02
    signed int mot_spflipping; // Offset: 0x4EC, DWARF: 0x77C2B
    signed int mot_grinding; // Offset: 0x4F0, DWARF: 0x77C56
    signed int mot_planting; // Offset: 0x4F4, DWARF: 0x77C7F
    signed int mot_manualing; // Offset: 0x4F8, DWARF: 0x77CA8
    signed int mot_reverting; // Offset: 0x4FC, DWARF: 0x77CD2
    signed int mot_bonking; // Offset: 0x500, DWARF: 0x77CFC
    signed int mot_tumbling; // Offset: 0x504, DWARF: 0x77D24
    signed int mot_reserve_tumble_standup; // Offset: 0x508, DWARF: 0x77D4D
    signed int mot_tumble_standup; // Offset: 0x50C, DWARF: 0x77D84
    signed int mot_tumble_standup_already; // Offset: 0x510, DWARF: 0x77DB3
    signed int mot_end_tumble; // Offset: 0x514, DWARF: 0x77DEA
    sceVu0FVECTOR mot_flip_rot __attribute__((aligned(16))); // Offset: 0x520, DWARF: 0x77E15
    float mot_flip_roty_base; // Offset: 0x530, DWARF: 0x77E40
    signed int mot_flip_mode; // Offset: 0x534, DWARF: 0x77E6F
    // Size: 0x98, DWARF: 0x791A9
    TrickLink trick_link; // Offset: 0x538, DWARF: 0x77E99
    signed int trk_doing; // Offset: 0x5D0, DWARF: 0x77EC2
    // DWARF: 0x80EBF
    ETS_Trick_State trk_state; // Offset: 0x5D4, DWARF: 0x77EE8
    signed int trk_grab_no; // Offset: 0x5D8, DWARF: 0x77F10
    signed int trk_trick_no; // Offset: 0x5DC, DWARF: 0x77F38
    // DWARF: 0x81DE1
    Trick_Link_State trk_link_state; // Offset: 0x5E0, DWARF: 0x77F61
    signed int num_set_gap; // Offset: 0x5E4, DWARF: 0x77F8E
    signed short set_gap[64]; // Offset: 0x5E8, DWARF: 0x77FB6
    signed int special_num; // Offset: 0x668, DWARF: 0x77FDC
    signed int special_charge; // Offset: 0x66C, DWARF: 0x78004
    signed int special_charge_cnt; // Offset: 0x670, DWARF: 0x7802F
    signed int special_charge_maxcnt; // Offset: 0x674, DWARF: 0x7805E
    signed int special_left_time; // Offset: 0x678, DWARF: 0x78090
    signed int special_total_time; // Offset: 0x67C, DWARF: 0x780BE
    signed int special_remainder_tp; // Offset: 0x680, DWARF: 0x780ED
    signed int boost; // Offset: 0x684, DWARF: 0x7811E
    signed int boost_num; // Offset: 0x688, DWARF: 0x78140
    signed int boost_charge; // Offset: 0x68C, DWARF: 0x78166
    signed int boost_left_time; // Offset: 0x690, DWARF: 0x7818F
    signed int boost_total_time; // Offset: 0x694, DWARF: 0x781BB
    signed int balance_cnt_adj; // Offset: 0x698, DWARF: 0x781E8
    float balance_ang_adj; // Offset: 0x69C, DWARF: 0x78214
    float balance_roty_adj; // Offset: 0x6A0, DWARF: 0x78240
    signed int balance_bigair; // Offset: 0x6A4, DWARF: 0x7826D
    sceVu0FVECTOR balance_pole __attribute__((aligned(16))); // Offset: 0x6B0, DWARF: 0x78298
    float hang_rate; // Offset: 0x6C0, DWARF: 0x782C3
    signed int num_hit; // Offset: 0x6C4, DWARF: 0x782E9
    signed int num_vec; // Offset: 0x6C8, DWARF: 0x7830D
    signed int num_obj; // Offset: 0x6CC, DWARF: 0x78331
    // Size: 0x60, DWARF: 0x75E44
    Col col_hit[0x10]; // Offset: 0x6D0, DWARF: 0x78355
    // Size: 0x60, DWARF: 0x75E44
    Col col_vec[0x10]; // Offset: 0xCD0, DWARF: 0x7837B
    // Size: 0x60, DWARF: 0x75E44
    Col col_obj[0x10]; // Offset: 0x12D0, DWARF: 0x783A1
    signed int reserve_tumble; // Offset: 0x18D0, DWARF: 0x783C7
    float reserve_tumble_ang; // Offset: 0x18D4, DWARF: 0x783F2
    float reserve_tumble_speed; // Offset: 0x18D8, DWARF: 0x78421
    // DWARF: 0x7E931
    Tumble_Type reserve_tumble_type; // Offset: 0x18DC, DWARF: 0x78452
    signed int reserve_trick_no[16]; // Offset: 0x18E0, DWARF: 0x78484
    signed int reserve_trick_is_flip[16]; // Offset: 0x1920, DWARF: 0x784B3
    signed int reserve_trick_is_special[16]; // Offset: 0x1960, DWARF: 0x784E7
    signed int num_reserve_trick; // Offset: 0x19A0, DWARF: 0x7851E
    signed int top_reserve_trick; // Offset: 0x19A4, DWARF: 0x7854C
    signed int reserve_stance_change; // Offset: 0x19A8, DWARF: 0x7857A
    signed int num_reserve_grab; // Offset: 0x19AC, DWARF: 0x785AC
    unsigned char num_play_trick[2][160]; // Offset: 0x19B0, DWARF: 0x785D9
    unsigned char num_play_trick_in_link[2][160]; // Offset: 0x1AF0, DWARF: 0x78606
    sceVu0FMATRIX mat_head; // Offset: 0x1C30, DWARF: 0x7863B
    float mat_hip[4][4]; // Offset: 0x1C70, DWARF: 0x78662
    // Size: 0x60, DWARF: 0x75E44
    Col col_rail; // Offset: 0x1CB0, DWARF: 0x78688
    // Size: 0x60, DWARF: 0x75E44
    Col col_plant; // Offset: 0x1D10, DWARF: 0x786AF
    // Size: 0x60, DWARF: 0x75E44
    Col col_hp; // Offset: 0x1D70, DWARF: 0x786D7
    // Size: 0x60, DWARF: 0x75E44
    Col col_zhp; // Offset: 0x1DD0, DWARF: 0x786FC
    sceVu0FVECTOR recover_pos; // Offset: 0x1E30, DWARF: 0x78722
    float recover_roty; // Offset: 0x1E40, DWARF: 0x7874C
    float recover_speed; // Offset: 0x1E44, DWARF: 0x78775
    signed int recover; // Offset: 0x1E48, DWARF: 0x7879F
    signed int trg_recovered; // Offset: 0x1E4C, DWARF: 0x787C3
    signed int reserve_fall; // Offset: 0x1E50, DWARF: 0x787ED
    signed int cnt_fall; // Offset: 0x1E54, DWARF: 0x78816
    signed int cnt_warp; // Offset: 0x1E58, DWARF: 0x7883B
    signed int water_manual; // Offset: 0x1E5C, DWARF: 0x78860
    signed int sptrk[2]; // Offset: 0x1E60, DWARF: 0x78889
    signed int num_total_gap; // Offset: 0x1E68, DWARF: 0x788AD
    signed int num_total_break; // Offset: 0x1E6C, DWARF: 0x788D7
    signed int reserve_quit; // Offset: 0x1E70, DWARF: 0x78903
    signed int allow_tlink; // Offset: 0x1E74, DWARF: 0x7892C
    signed int no_trick; // Offset: 0x1E78, DWARF: 0x78954
    signed int trg_quit; // Offset: 0x1E7C, DWARF: 0x78979
    signed int cnt_quit; // Offset: 0x1E80, DWARF: 0x7899E
    signed int cnt_reserve_quit; // Offset: 0x1E84, DWARF: 0x789C3
    signed int pass_finish_line; // Offset: 0x1E88, DWARF: 0x789F0
    signed int pass_finish_line2; // Offset: 0x1E8C, DWARF: 0x78A1D
    signed int wait_motion; // Offset: 0x1E90, DWARF: 0x78A4B
    signed int wait_vs; // Offset: 0x1E94, DWARF: 0x78A73
    signed int noheight_reflect; // Offset: 0x1E98, DWARF: 0x78A97
    signed int cnt_noheight_reflect; // Offset: 0x1E9C, DWARF: 0x78AC4
    signed int cnt_brank_noheight_reflect; // Offset: 0x1EA0, DWARF: 0x78AF5
    signed int forced_bailout; // Offset: 0x1EA4, DWARF: 0x78B2C
    signed int cnt_hit_wall; // Offset: 0x1EA8, DWARF: 0x78B57
    signed int cnt_brank_hit_wall; // Offset: 0x1EAC, DWARF: 0x78B80
    signed int cnt_forced_bailout; // Offset: 0x1EB0, DWARF: 0x78BAF
    float last_hit_plane[10][4] __attribute__((aligned(16))); // Offset: 0x1EC0, DWARF: 0x78BDE
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_trick[25]; // Offset: 0x1F60, DWARF: 0x78C0B
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_flip[25]; // Offset: 0x20F0, DWARF: 0x78C33
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_grind[13]; // Offset: 0x2280, DWARF: 0x78C5A
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_plant[9]; // Offset: 0x2350, DWARF: 0x78C82
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_bonk[9]; // Offset: 0x23E0, DWARF: 0x78CAA
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_manual[9]; // Offset: 0x2470, DWARF: 0x78CD1
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_jump[4]; // Offset: 0x2500, DWARF: 0x78CFA
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_sptrk[2]; // Offset: 0x2540, DWARF: 0x78D21
    // Size: 0x10, DWARF: 0x7A4D2
    Cmd cmd_revert[2]; // Offset: 0x2560, DWARF: 0x78D49
} Act;

// Size: 0x140, DWARF: 0x16DBF7
typedef struct Matrix
{
    sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x16DC13
    sceVu0FMATRIX local_light; // Offset: 0x40, DWARF: 0x16DC3E
    sceVu0FMATRIX light_color; // Offset: 0x80, DWARF: 0x16DC68
    sceVu0FMATRIX local_clip; // Offset: 0xC0, DWARF: 0x16DC92
    sceVu0FMATRIX clip_screen; // Offset: 0x100, DWARF: 0x16DCBB
} Matrix;

// Size: 0x20, DWARF: 0x16D961
typedef struct Fog
{
    float min; // Offset: 0x0, DWARF: 0x16D97D
    float max; // Offset: 0x4, DWARF: 0x16D99D
    float far; // Offset: 0x8, DWARF: 0x16D9BD
    float near; // Offset: 0xC, DWARF: 0x16D9DD
    signed int col[4]; // Offset: 0x10, DWARF: 0x16D9FE
} Fog;

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

// Size: 0x14, DWARF: 0x16D54F
typedef struct Se
{
    float splen; // Offset: 0x0, DWARF: 0x16D56B
    float rot_pole; // Offset: 0x4, DWARF: 0x16D58D
    float anggap_sp_brd; // Offset: 0x8, DWARF: 0x16D5B2
    float anggap_board_rot; // Offset: 0xC, DWARF: 0x16D5DC
    signed int side_slide; // Offset: 0x10, DWARF: 0x16D609
} Se __attribute__((aligned(16)));

// Size: 0x190, DWARF: 0x16B9B7
typedef struct Cam // Offset 2A40
{
    float pre_speed[4]; // Offset: 0x0, DWARF: 0x16B9D3
    float now_speed[4]; // Offset: 0x10, DWARF: 0x16B9FB
    float normal_speed[4]; // Offset: 0x20, DWARF: 0x16BA23
    float rot[4]; // Offset: 0x30, DWARF: 0x16BA4E
    float pos_waist[4]; // Offset: 0x40, DWARF: 0x16BA70
    float pos_disp[4]; // Offset: 0x50, DWARF: 0x16BA98
    // Size: 0x60, DWARF: 0x16E55B
    Pos pos; // Offset: 0x60, DWARF: 0x16BABF
    // Size: 0x60, DWARF: 0x16E55B
    Pos prepos; // Offset: 0xC0, DWARF: 0x16BAE1
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
} Cam;

// DWARF: 0x16ECC4
typedef enum FlipMode
{
    eflReady,
    eflFlipping,
    eflEnd
} FlipMode;

// Size: 0x20, DWARF: 0x16E73E
typedef struct KeyList
{
    float rot[4]; // Offset: 0x0, DWARF: 0x16E75A
    signed int frame; // Offset: 0x10, DWARF: 0x16E77C
    signed int pad; // Offset: 0x14, DWARF: 0x16E79E
    char padding[4]; // Not originally in struct
} KeyList;

// Size: 0x50, DWARF: 0x16F172
typedef struct Flip // Offset 28B0 + 110 = 29C0
{
    // Size: 0x20, DWARF: 0x16E73E
    KeyList* key_list; // Offset: 0x0, DWARF: 0x16F18E
    // Size: 0x20, DWARF: 0x16E73E
    KeyList now; // Offset: 0x10, DWARF: 0x16F1B8
    signed int num_key; // Offset: 0x30, DWARF: 0x16F1DA
    signed int num_frame; // Offset: 0x34, DWARF: 0x16F1FE
    // DWARF: 0x16ECC4
    FlipMode flipmode; // Offset: 0x38, DWARF: 0x16F224
    signed int mot_id; // Offset: 0x3C, DWARF: 0x16F24B
    signed int play_mot; // Offset: 0x40, DWARF: 0x16F26E
    int padding[7]; // Not originally in struct
} Flip __attribute__((aligned (16)));

// Size: 0x2C, DWARF: 0x16DF3B
typedef struct MotFrames // Offset 0x28B0
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

// Size: 0x190, DWARF: 0x1677E9, 0x7D5BF
typedef struct Mot // Offset 28B0
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
} Mot;

// Size: 0x2C00, DWARF: 0x16AA87, 0xBAAA7, 0x7627B
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

// Size: 0x20, DWARF: 0x7EE12, 0xBA133
typedef struct ModelData
{
    float pos[4]; // Offset: 0x0, DWARF: 0xBA14E
    float rot[4]; // Offset: 0x10, DWARF: 0xBA170
}  ModelData;

// Size: 0x10, DWARF: 0x813DF, 0xBCA3C
typedef struct PosAddress //: const volatile float[4]
{
    unsigned int type; // Offset: 0x0, DWARF: 0xBCA58
    float frame; // Offset: 0x4, DWARF: 0xBCA79
    signed short flg; // Offset: 0x8, DWARF: 0xBCA9B
    signed short non; // Offset: 0xA, DWARF: 0xBCABB
    float* data[4]; // Offset: 0xC, DWARF: 0xBCADB
} PosAddress;

// Size: 0x140, DWARF: 0x7DA36
typedef struct Wind
{
    signed int count[8][3] __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x7DA52
    signed int speed[8][3]; // Offset: 0x60, DWARF: 0x7DA76
    float wave[8][4]; // Offset: 0xC0, DWARF: 0x7DA9A
} Wind;

// Size: 0x8, DWARF: 0x7E8D5
typedef struct EnvFog
{
    float a; // Offset: 0x0, DWARF: 0x7E8F1
    float b; // Offset: 0x4, DWARF: 0x7E90F
} EnvFog;


// Size: 0xF0, DWARF: 0x80315, 0xBB2C0
typedef struct Seq
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0xBB2DC
    signed int loop; // Offset: 0x4, DWARF: 0xBB301
    signed int mode; // Offset: 0x8, DWARF: 0xBB322
    signed int write_flg; // Offset: 0xC, DWARF: 0xBB343
    signed int now_local_id; // Offset: 0x10, DWARF: 0xBB369
    signed int now_top_id; // Offset: 0x14, DWARF: 0xBB392
    signed int next_local_id; // Offset: 0x18, DWARF: 0xBB3B9
    signed int next_top_id; // Offset: 0x1C, DWARF: 0xBB3E3
    // Size: 0x20, DWARF: 0xBA133
    ModelData* mdl_data; // Offset: 0x20, DWARF: 0xBB40B
    float now_frame; // Offset: 0x24, DWARF: 0xBB435
    float next_frame; // Offset: 0x28, DWARF: 0xBB45B
    float ratio; // Offset: 0x2C, DWARF: 0xBB482
    // Size: 0x10, DWARF: 0xBCA3C
    PosAddress* now_pos_address; // Offset: 0x30, DWARF: 0xBB4A4
    // Size: 0x10, DWARF: 0xBCA3C
    PosAddress* now_rot_address; // Offset: 0x34, DWARF: 0xBB4D5
    // Size: 0x10, DWARF: 0xBCA3C
    PosAddress* next_pos_address; // Offset: 0x38, DWARF: 0xBB506
    // Size: 0x10, DWARF: 0xBCA3C
    PosAddress* next_rot_address; // Offset: 0x3C, DWARF: 0xBB538
    float nowDir[4]; // Offset: 0x40, DWARF: 0xBB56A
    float nowTrans[4]; // Offset: 0x50, DWARF: 0xBB58F
    sceVu0FMATRIX now_matrix; // Offset: 0x60, DWARF: 0xBB5B6
    float pos[4]; // Offset: 0xA0, DWARF: 0xBB5DF
    float quat[4]; // Offset: 0xB0, DWARF: 0xBB601
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0xBB624
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0xBB64A
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0xBB670
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0xBB69B
    signed int pad[2]; // Offset: 0xE8, DWARF: 0xBB6C5
} Seq;

// Size: 0x8, DWARF: 0x7EB45
typedef struct EnvMap
{
    unsigned long tex0; // Offset: 0x0, DWARF: 0x7EB61
} EnvMap;

// Size: 0x160, DWARF: 0x7D512
typedef struct Vmenv
{
    unsigned int enable; // Offset: 0x0, DWARF: 0x7D52E
    // Size: 0x140, DWARF: 0x7DA36
    Wind wind; // Offset: 0x10, DWARF: 0x7D551
    // Size: 0x8, DWARF: 0x7E8D5
    EnvFog fog; // Offset: 0x150, DWARF: 0x7D574
    // Size: 0x8, DWARF: 0x7EB45
    EnvMap envmap; // Offset: 0x158, DWARF: 0x7D596
} Vmenv;

// Size: 0x230, DWARF: 0xFB1A1, 0x81827
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

// Size: 0x2E0, DWARF: 0x7CF19
typedef struct UmdCtrl
{
    float rot[4]; // Offset: 0x0, DWARF: 0x7CF35
    float trans[4]; // Offset: 0x10, DWARF: 0x7CF57
    float scale[4]; // Offset: 0x20, DWARF: 0x7CF7B
    sceVu0FMATRIX matrix; // Offset: 0x30, DWARF: 0x7CF9F
    sceVu0FMATRIX revision; // Offset: 0x70, DWARF: 0x7CFC4
    // Size: 0x230, DWARF: 0x81827
    IkParam ikparam; // Offset: 0xB0, DWARF: 0x7CFEB
} UmdCtrl;

// Size: 0x24, DWARF: 0x80BCF
typedef struct UadList
{
    __int128* regular; // Offset: 0x0, DWARF: 0x80BEB
    __int128* fakie; // Offset: 0x4, DWARF: 0x80C12
    __int128* trick; // Offset: 0x8, DWARF: 0x80C37
    __int128* special; // Offset: 0xC, DWARF: 0x80C5C
    __int128* special2; // Offset: 0x10, DWARF: 0x80C83
    __int128* special3; // Offset: 0x14, DWARF: 0x80CAB
    __int128* special4; // Offset: 0x18, DWARF: 0x80CD3
    __int128* special5; // Offset: 0x1C, DWARF: 0x80CFB
    __int128* special6; // Offset: 0x20, DWARF: 0x80D23
} UadList;

// Size: 0x1A0, DWARF: 0x7C011
typedef struct SmdCtrl
{
    signed int type; // Offset: 0x0, DWARF: 0x7C02D
    float power; // Offset: 0x4, DWARF: 0x7C04E
    float dir; // Offset: 0x8, DWARF: 0x7C070
    float cnt; // Offset: 0xC, DWARF: 0x7C090
    float head[4]; // Offset: 0x10, DWARF: 0x7C0B0
    float preHead[4]; // Offset: 0x20, DWARF: 0x7C0D3
    float tail_matrix[5][4][4]; // Offset: 0x30, DWARF: 0x7C0F9
    float g_vector[4]; // Offset: 0x170, DWARF: 0x7C123
    unsigned int* tailAddress[5]; // Offset: 0x180, DWARF: 0x7C14A
    signed int pad[3]; // Offset: 0x194, DWARF: 0x7C174
} SmdCtrl;

// Size: 0x90, DWARF: 0x7BE99
typedef struct ModelChange
{
    sceVu0FMATRIX original; // Offset: 0x0, DWARF: 0x7BEB5
    sceVu0FMATRIX original2; // Offset: 0x40, DWARF: 0x7BEDC
    sceVu0FMATRIX* address; // Offset: 0x80, DWARF: 0x7BF04
    sceVu0FMATRIX* address2; // Offset: 0x84, DWARF: 0x7BF2D
    signed int pad[2]; // Offset: 0x88, DWARF: 0x7BF57
} ModelChange;

// Size: 0x2A30, DWARF: 0x7F8F0
typedef struct Disp
{
    void* umd; // Offset: 0x0, DWARF: 0x7F90C
    void* utd; // Offset: 0x4, DWARF: 0x7F92F
    // Size: 0xF0, DWARF: 0x80315
    Seq* seq; // Offset: 0x8, DWARF: 0x7F952
    // Size: 0x24, DWARF: 0x80BCF
    UadList uad_list; // Offset: 0xC, DWARF: 0x7F977
    // Size: 0x160, DWARF: 0x7D512
    Vmenv vmenv; // Offset: 0x30, DWARF: 0x7F99E
    // Size: 0x2E0, DWARF: 0x7CF19
    UmdCtrl* umd_ctrl; // Offset: 0x190, DWARF: 0x7F9C2
    // Size: 0x1A0, DWARF: 0x7C011
    SmdCtrl* smd_ctrl; // Offset: 0x194, DWARF: 0x7F9EC
    // Size: 0x90, DWARF: 0x7BE99
    ModelChange* model_change; // Offset: 0x198, DWARF: 0x7FA16
    float scale; // Offset: 0x19C, DWARF: 0x7FA44
    // Size: 0x2580, DWARF: 0x76810
    Act act; // Offset: 0x1A0, DWARF: 0x7FA66
    // Size: 0x60, DWARF: 0x79DD3
    Pos nowpos; // Offset: 0x2720, DWARF: 0x7FA88
    // Size: 0x60, DWARF: 0x79DD3
    Pos prepos __attribute__((aligned(16))); // Offset: 0x2780, DWARF: 0x7FAAD
    // Size: 0x3C, DWARF: 0x7600B
    Inp nowinp __attribute__((aligned(16))); // Offset: 0x27E0, DWARF: 0x7FAD2
    float speed[4] __attribute__((aligned(16))); // Offset: 0x2820, DWARF: 0x7FAF7
    float splen; // Offset: 0x2830, DWARF: 0x7FB1B
    float splenxz; // Offset: 0x2834, DWARF: 0x7FB3D
    float shadow_posy; // Offset: 0x2838, DWARF: 0x7FB61
    signed int disp_char; // Offset: 0x283C, DWARF: 0x7FB89
    signed int disp_shadow; // Offset: 0x2840, DWARF: 0x7FBAF
    signed int in_screen; // Offset: 0x2844, DWARF: 0x7FBD7
    signed int reset_effect2; // Offset: 0x2848, DWARF: 0x7FBFD
    signed int detail; // Offset: 0x284C, DWARF: 0x7FC27
    signed int set_sub_data; // Offset: 0x2850, DWARF: 0x7FC4A
    signed int sub_detail; // Offset: 0x2854, DWARF: 0x7FC73
    void* sub_umd; // Offset: 0x2858, DWARF: 0x7FC9A
    // Size: 0x2E0, DWARF: 0x7CF19
    UmdCtrl* sub_umd_ctrl; // Offset: 0x285C, DWARF: 0x7FCC1
    // Size: 0x1A0, DWARF: 0x7C011
    SmdCtrl* sub_smd_ctrl; // Offset: 0x2860, DWARF: 0x7FCEF
    float normal_light0[4] __attribute__((aligned(16))); // Offset: 0x2870, DWARF: 0x7FD1D
    float normal_light1[4]; // Offset: 0x2880, DWARF: 0x7FD49
    float normal_light2[4]; // Offset: 0x2890, DWARF: 0x7FD75
    float light_color0[4]; // Offset: 0x28A0, DWARF: 0x7FDA1
    float light_color1[4]; // Offset: 0x28B0, DWARF: 0x7FDCC
    float light_color2[4]; // Offset: 0x28C0, DWARF: 0x7FDF7
    float ambient[4]; // Offset: 0x28D0, DWARF: 0x7FE22
    float shadow[4]; // Offset: 0x28E0, DWARF: 0x7FE48
    sceVu0FMATRIX mat_base_lw; // Offset: 0x28F0, DWARF: 0x7FE6D
    sceVu0FMATRIX mat_board; // Offset: 0x2930, DWARF: 0x7FE97
    sceVu0FMATRIX mat_hand_l; // Offset: 0x2970, DWARF: 0x7FEBF
    sceVu0FMATRIX mat_hand_r; // Offset: 0x29B0, DWARF: 0x7FEE8
    sceVu0FMATRIX mat_head; // Offset: 0x29F0, DWARF: 0x7FF11
} Disp;

// Size: 0x5640, DWARF: 0x78FAB, 0x1BFCC8 // vspRider from  ktact.c
typedef struct Rider
{
    // Size: 0x2A30, DWARF: 0x7F8F0, 0xBB1F1
    Disp disp; // Offset: 0x0, DWARF: 0x78FC6
    // Size: 0x2C00, DWARF: 0x7627B
    Ctrl ctrl; // Offset: 0x2A30, DWARF: 0x78FE9
    // char padding[48]; // This does not exist in the original struct, this is added to match the expected offsets. Ctrl is supposed to be size 0x2C00.
    signed int pid; // Offset: 0x5630, DWARF: 0x7900C
    signed int secondly; // Offset: 0x5634, DWARF: 0x7902C
} Rider;

// spev08.c structs ////////////////////////////////////////////////////////////////////

// Size: 0xC0, DWARF: 0x1CCACB
typedef struct Info
{
    signed int freq; // Offset: 0x0, DWARF: 0x1CCAE7
    signed int ttl; // Offset: 0x4, DWARF: 0x1CCB08
    signed int ttl2; // Offset: 0x8, DWARF: 0x1CCB28
    float sx; // Offset: 0xC, DWARF: 0x1CCB49
    float sy; // Offset: 0x10, DWARF: 0x1CCB68
    float sx2; // Offset: 0x14, DWARF: 0x1CCB87
    float sy2; // Offset: 0x18, DWARF: 0x1CCBA7
    float sx3; // Offset: 0x1C, DWARF: 0x1CCBC7
    float sy3; // Offset: 0x20, DWARF: 0x1CCBE7
    signed int fin; // Offset: 0x24, DWARF: 0x1CCC07
    signed int fout; // Offset: 0x28, DWARF: 0x1CCC27
    float zofs; // Offset: 0x2C, DWARF: 0x1CCC48
    sceVu0FVECTOR pos; // Offset: 0x30, DWARF: 0x1CCC69
    sceVu0FVECTOR pos2; // Offset: 0x40, DWARF: 0x1CCC8B
    sceVu0FVECTOR mov; // Offset: 0x50, DWARF: 0x1CCCAE
    sceVu0FVECTOR mov2; // Offset: 0x60, DWARF: 0x1CCCD0
    sceVu0FVECTOR acc; // Offset: 0x70, DWARF: 0x1CCCF3
    sceVu0FVECTOR dec; // Offset: 0x80, DWARF: 0x1CCD15
    unsigned long alpha; // Offset: 0x90, DWARF: 0x1CCD37
    unsigned long tex0; // Offset: 0x98, DWARF: 0x1CCD59
    signed int rgba[4]; // Offset: 0xA0, DWARF: 0x1CCD7A
    unsigned int count; // Offset: 0xB0, DWARF: 0x1CCD9D
} Info;

// Size: 0x50, DWARF: 0x1CDE58
typedef struct Data
{
    // Size: 0xC0, DWARF: 0x1CCACB
    Info* info; // Offset: 0x0, DWARF: 0x1CDE74
    float pos[4]; // Offset: 0x10, DWARF: 0x1CDE9A
    float mov[4]; // Offset: 0x20, DWARF: 0x1CDEBC
    float sx; // Offset: 0x30, DWARF: 0x1CDEDE
    float sy; // Offset: 0x34, DWARF: 0x1CDEFD
    float speed; // Offset: 0x38, DWARF: 0x1CDF1C
    signed int count; // Offset: 0x3C, DWARF: 0x1CDF3E
    signed int ttl; // Offset: 0x40, DWARF: 0x1CDF60
} Data;

// Size: 0x10, DWARF: 0x1CFA2A
typedef struct Course
{
    // Size: 0x20, DWARF: 0x1CDCDE
    Fog* fog; // Offset: 0x0, DWARF: 0x1CFA46
    signed int no; // Offset: 0x4, DWARF: 0x1CFA6B
    signed int res[2]; // Offset: 0x8, DWARF: 0x1CFA8A
} Course;

// Size: 0x14, DWARF: 0x1CB82A
typedef struct Game
{
    signed int player; // Offset: 0x0, DWARF: 0x1CB846
    signed int nplayer; // Offset: 0x4, DWARF: 0x1CB869
    signed int pause; // Offset: 0x8, DWARF: 0x1CB88D
    signed int mode; // Offset: 0xC, DWARF: 0x1CB8AF
    signed int wid; // Offset: 0x10, DWARF: 0x1CB8D0
} Game;

// Size: 0x34, DWARF: 0x1CBFE7
typedef struct Character //_anon17
{
	int no; // Offset: 0x0, DWARF: 0x1CC003
	int player; // Offset: 0x4, DWARF: 0x1CC022
	int base_attr; // Offset: 0x8, DWARF: 0x1CC045
	int nvector; // Offset: 0xC, DWARF: 0x1CC06B
	int nhit; // Offset: 0x10, DWARF: 0x1CC08F
	int nobj; // Offset: 0x14, DWARF: 0x1CC0B0
	int rail; // Offset: 0x18, DWARF: 0x1CC0D1
	int old_rail; // Offset: 0x1C, DWARF: 0x1CC0F2
	int res; // Offset: 0x20, DWARF: 0x1CC117
    // Size: 0x60, DWARF: 0x1CEAF4
	Col* vector; // Offset: 0x24, DWARF: 0x1CC137
    // Size: 0x60, DWARF: 0x1CEAF4
	Col* hit; // Offset: 0x28, DWARF: 0x1CC15F
    // Size: 0x60, DWARF: 0x1CEAF4
	Col* object; // Offset: 0x2C, DWARF: 0x1CC184
    // Size: 0x2C00, DWARF: 0x1CAF24
	Ctrl* ctrl; // Offset: 0x30, DWARF: 0x1CC1AC
} Character;

// Size: 0x8C, DWARF: 0x1C8027
typedef struct Event {
    // Size: 0x10, DWARF: 0x1CFA2A
	Course course; // Offset: 0x0, DWARF: 0x1C8042
    // Size: 0x34, DWARF: 0x1CBFE7
	Character character[2]; // Offset: 0x10, DWARF: 0x1C8067
    // Size: 0x14, DWARF: 0x1CB82A
	Game game; // Offset: 0x78, DWARF: 0x1C808F
} Event;

// Size: 0x10, DWARF: 0x1C86E0
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x1C86FB
    unsigned int addr; // Offset: 0x4, DWARF: 0x1C871E
    unsigned int z; // Offset: 0x8, DWARF: 0x1C873F
    unsigned int _pad; // Offset: 0xC, DWARF: 0x1C875D
} ATag;

// Size: 0x20, DWARF: 0x1CB6E8
typedef struct VgmsysAbuf //: const volatile <unknown type 0x1CA510>
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0x1CB704
    unsigned int natag; // Offset: 0x4, DWARF: 0x1CB728
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0x1CB74A
    unsigned int npkt; // Offset: 0xC, DWARF: 0x1CB76D
    // Size: 0x10, DWARF: 0x1C86E0
    ATag* atag; // Offset: 0x10, DWARF: 0x1CB78E
    // Size: 0x10, DWARF: 0x1C86E0
    ATag* curatag; // Offset: 0x14, DWARF: 0x1CB7B4
    __int128* pkt; // Offset: 0x18, DWARF: 0x1CB7DD
    __int128* curpkt; // Offset: 0x1C, DWARF: 0x1CB800
} VgmsysAbuf;

// Size: 0x4, DWARF: 0x1CE8D6
typedef struct Course2
{
    signed int no; // Offset: 0x0, DWARF: 0x1CE8F2
} Course2;

// Size: 0x18, DWARF: 0x1CE9A7
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x1CE9C3
    signed int game_mode; // Offset: 0x4, DWARF: 0x1CE9EA
    signed int match_rule; // Offset: 0x8, DWARF: 0x1CEA10
    signed int divide; // Offset: 0xC, DWARF: 0x1CEA37
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x1CEA5A
} Mode;

// Size: 0x3C, DWARF: 0x167640
typedef struct Character2
{
    signed int no; // Offset: 0x0, DWARF: 0x16765B
    signed int player; // Offset: 0x4, DWARF: 0x16767A
    signed int wear; // Offset: 0x8, DWARF: 0x16769D
    signed int board; // Offset: 0xC, DWARF: 0x1676BE
    // Size: 0x1C, DWARF: 0x16D2B9
    Character_Param chr_param; // Offset: 0x10, DWARF: 0x1676E0
    // Size: 0x10, DWARF: 0x16DA24
    Board_Param brd_param; // Offset: 0x2C, DWARF: 0x167708
} Character2;

typedef struct VspenvGame // VspenvGame // _anon29
{
	Course2 course;
	Character2 character[2];
	Mode mode;
	int language;
	int ending;
	int bgm_no;
} VspenvGame;

// Size: 0x20, DWARF: 0x1CFB1E
typedef struct PadInput
{
    signed int id; // Offset: 0x0, DWARF: 0x1CFB3A
    unsigned int now; // Offset: 0x4, DWARF: 0x1CFB59
    unsigned int status; // Offset: 0x8, DWARF: 0x1CFB79
    unsigned int press; // Offset: 0xC, DWARF: 0x1CFB9C
    signed char right_h; // Offset: 0x10, DWARF: 0x1CFBBE
    signed char right_v; // Offset: 0x11, DWARF: 0x1CFBE2
    signed char left_h; // Offset: 0x12, DWARF: 0x1CFC06
    signed char left_v; // Offset: 0x13, DWARF: 0x1CFC29
    unsigned char l_right; // Offset: 0x14, DWARF: 0x1CFC4C
    unsigned char l_left; // Offset: 0x15, DWARF: 0x1CFC70
    unsigned char l_up; // Offset: 0x16, DWARF: 0x1CFC93
    unsigned char l_down; // Offset: 0x17, DWARF: 0x1CFCB4
    unsigned char r_up; // Offset: 0x18, DWARF: 0x1CFCD7
    unsigned char r_right; // Offset: 0x19, DWARF: 0x1CFCF8
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x1CFD1C
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x1CFD3F
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x1CFD62
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x1CFD82
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x1CFDA2
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x1CFDC2
} PadInput;

// Size: 0x60, DWARF: 0x1CC539
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0x1CFB1E
    PadInput now; // Offset: 0x0, DWARF: 0x1CC555
    // Size: 0x20, DWARF: 0x1CFB1E
    PadInput old; // Offset: 0x20, DWARF: 0x1CC577
    unsigned int port; // Offset: 0x40, DWARF: 0x1CC599
    unsigned int slot; // Offset: 0x44, DWARF: 0x1CC5BA
    unsigned int mode; // Offset: 0x48, DWARF: 0x1CC5DB
    unsigned int trg; // Offset: 0x4C, DWARF: 0x1CC5FC
    unsigned int rev; // Offset: 0x50, DWARF: 0x1CC61C
    unsigned int cnt; // Offset: 0x54, DWARF: 0x1CC63C
    unsigned int rep; // Offset: 0x58, DWARF: 0x1CC65C
    signed int state; // Offset: 0x5C, DWARF: 0x1CC67C
}* VgmsysPad;

// Size: 0x60, DWARF: 0x1B78E0
typedef struct Smoke
{
    signed int num; // Offset: 0x0, DWARF: 0x1B78FC
    signed int _max; // Offset: 0x4, DWARF: 0x1B791C
    // Size: 0x50, DWARF: 0x1B80B8
    Data data[1]; // Offset: 0x10, DWARF: 0x1B793D
} Smoke;

// Size: 0x70, DWARF: 0x1B6395
typedef struct EventMdl
{
    float pos[4]; // Offset: 0x0, DWARF: 0x1B63B1
    sceVu0FMATRIX matrix; // Offset: 0x10, DWARF: 0x1B63D3
    signed int no; // Offset: 0x50, DWARF: 0x1B63F8
    signed int id; // Offset: 0x54, DWARF: 0x1B6417
    float frame; // Offset: 0x58, DWARF: 0x1B6436
    signed int draw; // Offset: 0x5C, DWARF: 0x1B6458
    signed int light; // Offset: 0x60, DWARF: 0x1B6479
    signed int old_id; // Offset: 0x64, DWARF: 0x1B649B
    signed int cnt; // Offset: 0x68, DWARF: 0x1B64BE
    signed int flag; // Offset: 0x6C, DWARF: 0x1B64DE
} EventMdl;

// Size: 0x8, DWARF: 0x1B7EA4
typedef struct Sound
{
    signed int id; // Offset: 0x0, DWARF: 0x1B7EC0
    signed int vol; // Offset: 0x4, DWARF: 0x1B7EDF
} Sound;

// Size: 0x1230, DWARF: 0x1B76EA
typedef struct Vspev08EventData
{
    // Size: 0x60, DWARF: 0x1B78E0
    Smoke* particle; // Offset: 0x0, DWARF: 0x1B7706
    // Size: 0xC0, DWARF: 0x1B6B0B
    Info snowmachine[11][2]; // Offset: 0x10, DWARF: 0x1B7730
    // Size: 0x70, DWARF: 0x1B6395
    EventMdl evmdl[3]; // Offset: 0x1090, DWARF: 0x1B775A
    float lmdir[3][4]; // Offset: 0x11E0, DWARF: 0x1B777E
    // Size: 0x8, DWARF: 0x1B7EA4
    Sound sound[3]; // Offset: 0x1210, DWARF: 0x1B77A2
} Vspev08EventData;

// Size: 0x10, DWARF: 0x1B5A41
typedef struct TexData
{
    signed short tofs; // Offset: 0x0, DWARF: 0x1B5A5D
    signed short cofs; // Offset: 0x2, DWARF: 0x1B5A7E
    signed short width; // Offset: 0x4, DWARF: 0x1B5A9F
    signed short height; // Offset: 0x6, DWARF: 0x1B5AC1
    signed short tw; // Offset: 0x8, DWARF: 0x1B5AE4
    signed short th; // Offset: 0xA, DWARF: 0x1B5B03
    signed short image_bit; // Offset: 0xC, DWARF: 0x1B5B22
    signed short clut_bit; // Offset: 0xE, DWARF: 0x1B5B48
} TexData;

// Size: 0x10, DWARF: 0x1B2ABA
typedef struct TexInfo
{
    signed int group; // Offset: 0x0, DWARF: 0x1B2AD6
    signed int no; // Offset: 0x4, DWARF: 0x1B2AF8
    signed int tex_no; // Offset: 0x8, DWARF: 0x1B2B17
    // Size: 0x10, DWARF: 0x1B5A41
    TexData* data; // Offset: 0xC, DWARF: 0x1B2B3A
} TexInfo;

// Size: 0x28, DWARF: 0x1B5C3B
typedef struct TexScroll
{
    // Size: 0x10, DWARF: 0x1B2ABA
    TexInfo src; // Offset: 0x0, DWARF: 0x1B5C57
    // Size: 0x10, DWARF: 0x1B2ABA
    TexInfo work; // Offset: 0x10, DWARF: 0x1B5C79
    signed int scroll_x; // Offset: 0x20, DWARF: 0x1B5C9C
    signed int scroll_y; // Offset: 0x24, DWARF: 0x1B5CC1
} TexScroll;

// Size: 0x20, DWARF: 0x20FC5B
typedef struct TexScrInfo
{
    signed int texnum; // Offset: 0x0, DWARF: 0x20FC77
    signed int dmynum; // Offset: 0x4, DWARF: 0x20FC9A
    signed int dx; // Offset: 0x8, DWARF: 0x20FCBD
    signed int dy; // Offset: 0xC, DWARF: 0x20FCDC
    signed int tw; // Offset: 0x10, DWARF: 0x20FCFB
    signed int th; // Offset: 0x14, DWARF: 0x20FD1A
    signed int tx; // Offset: 0x18, DWARF: 0x20FD39
    signed int ty; // Offset: 0x1C, DWARF: 0x20FD58
} TexScrInfo;

//// Variables ////////////////////////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0x1CB6E8
extern VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0
// Size: 0xA0, DWARF: 0x1CDBE3
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x60, DWARF: 0x1CC539
extern VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30

static TexScrInfo vspev08TexScrInfo[6] = {
    { 0, 9, 0, 16, 0, 0, 0, 0 },
    { 1, 10, 0, 8, 0, 0, 0, 0 },
    { 2, 11, 0, 4, 0, 0, 0, 0 },
    { 6, 12, 0, 16, 0, 0, 0, 0 },
    { 7, 13, 0, 8, 0, 0, 0, 0 },
    { 8, 14, 0, 4, 0, 0, 0, 0 }
}; // Address: 0x2D1730

static float vspev08SnowMachinePos[11][2][4] = {
    { { -1275.4f, 8330.8f, -13696.8f, 0.0f }, { 1.7f, -1.0f, -6.5f, 0.0f } },
    { { -475.3f, 8330.8f, -13696.8f, 0.0f }, { -1.7f, -1.0f, -6.5f, 0.0f } },
    { { -262.1f, 2843.0f, -5975.7f, 0.0f }, { 5.0f, -1.0f, -5.0f, 0.0f } },
    { { 1004.8f, 4043.8f, -8199.8f, 0.0f }, { -7.0f, -1.0f, 0.0f, 0.0f } },
    { { 1004.8f, 4299.1f, -8599.7f, 0.0f }, { -7.0f, -1.0f, 0.0f, 0.0f } },
    { { 1004.8f, 4542.8f, -8999.8f, 0.0f }, { -7.0f, -1.0f, 0.0f, 0.0f } },
    { { 1004.8f, 6734.5f, -12600.2f, 0.0f }, { -7.0f, -1.0f, 0.0f, 0.0f } },
    { { 1004.8f, 6888.0f, -12999.2f, 0.0f }, { -7.0f, -1.0f, 0.0f, 0.0f } },
    { { -1788.0f, 8174.4f, -14072.9f, 0.0f }, { 7.0f, -1.0f, 0.0f, 0.0f } },
    { { -1104.2f, 5597.3f, -10429.5f, 0.0f }, { 4.0f, -0.5f, 4.0f, 0.0f } },
    { { -603.4f, 5774.6f, -10930.6f, 0.0f }, { 4.0f, -0.5f, 4.0f, 0.0f } }
}; // Address: 0x2D17F0

static Info vspev08BridgeSmokeInfo[2] = {
    { 384, 60, 70, 6000.0f, 6000.0f, 4000.0f, 4000.0f, 30.0f, 30.0f, 10, 60, 1.2f, { 543.0f, 3062.0f, -5343.0f, 1.0f }, { 70.0f, 30.0f, 120.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { 0.3f, 0.5f, 0.3f, 0.0f }, { 0.0f, 0.04f, 0.0f, 0.0f }, { 0.99f, 0.99f, 0.99f, 1.0f }, 0x44, 0x0, { 128, 128, 128, 32 }, 0 },
    { 512, 100, 60, 10000.0f, 10000.0f, 5000.0f, 5000.0f, 100.0f, 100.0f, 10, 80, 1.2f, { 546.0f, 3323.0f, -5331.0f, 1.0f }, { 110.0f, 50.0f, 110.0f, 0.0f }, { 0.0f, 0.0f, 0.0f, 0.0f }, { 2.5f, 0.9f, 2.5f, 0.0f }, { 0.0f, 0.01f, 0.0f, 0.0f }, { 0.99f, 0.99f, 0.99f, 1.0f }, 0x44, 0x0, { 128, 128, 128, 32 }, 0 }
}; // Address: 0x2D1950

static const signed int vspev08BoundObject[4][2] = {
    { 0, 6 },
    { 8, 6 },
    { 61, 40 },
    { -1, -1 }
}; // Address: 0x2E5E60

static const signed int vspev08ObjectSe[25][3] = {
    { 1, 2, 0 },
    { 20, 3, 1 },
    { 19, 23, 1 },
    { 18, 23, 1 },
    { 0, 20, 1 },
    { 24, 7, 1 },
    { 30, 0, 2 },
    { 22, 0, 2 },
    { 31, 0, 2 },
    { 8, 4, 2 },
    { 13, 4, 2 },
    { 14, 22, 2 },
    { 15, 4, 2 },
    { 27, 4, 2 },
    { 16, 4, 2 },
    { 25, -1, 2 },
    { 26, -1, 2 },
    { 21, 0, 2 },
    { 3, 11, 3 },
    { 2, 11, 3 },
    { 7, 1, 3 },
    { 5, 8, 3 },
    { 6, 8, 3 },
    { 12, 8, 3 },
    { -1, -1, -1 }
};

static const signed int vspev08GlassSe[3] = { 4, 21, 22 };

static const Info vspev08SnowMachineInfo0[2] = {
    { 48, 90, 50, 3500.0f, 3500.0f, 1000.0f, 1000.0f, 250.0f, 250.0f, 3, 120, 1.2f, { 570.0f, 4065.0f, -10436.0f, 1.0f }, { 1.0f, -1.0f, 1.0f, 0.0f }, { 4.0f, -0.8f, -3.0f, 0.0f }, { 1.0f, 0.4f, 1.0f, 0.0f }, { 0.0f, 0.04f, 0.0f, 0.0f }, { 0.98f, 1.0f, 0.98f, 1.0f }, 0x44, 0x0, { 128, 128, 128, 128 }, 0 },
    { 8, 100, 50, 3500.0f, 3500.0f, 1000.0f, 1000.0f, 250.0f, 250.0f, 3, 120, 1.2f, { 570.0f, 4065.0f, -10436.0f, 1.0f }, { 1.0f, -1.0f, 1.0f, 0.0f }, { 4.0f, -0.8f, -3.0f, 0.0f }, { 1.0f, 0.4f, 1.0f, 0.0f }, { 0.0f, 0.04f, 0.0f, 0.0f }, { 0.98f, 1.0f, 0.98f, 1.0f }, 0x44, 0x0, { 128, 128, 128, 128 }, 0 }
};

// Size: 0x1230, DWARF: 0x1B76EA
Vspev08EventData* vspev08EventData; // Address: 0x2E7F90
// Size: 0x28, DWARF: 0x1B5C3B
TexScroll vspev08TexScrool[6]; // Address: 0x3C7430


// spev08.c function declarations ///////////////////////////////////////

signed int spev08Init(Event* event /* 0x30(r29) */);
signed int spev08ResetEvent(Event* event /* 0x30(r29) */);
signed int spev08MainEvent(Event* event /* 0x70(r29) */);
signed int spev08PlayerEvent(Event* event);
signed int spev08DrawEvent(Event* event);
signed int spev08DrawPlayerEvent(Event* event);
signed int spev08FinishPlayerEvent(Event* event);
void spev08End();
static void spev08ResetObject(Event* event);
static void spev08CheckHit(Event* event, signed int unused1);
static void spev08CheckRail(Event* event);
static void spev08CheckObject(Event* event, signed int unused1);
static void spev08CheckHandPlant(Event* event);
static void spev08CheckClearFlag1(Event* event);
static void spev08CheckClearFlag2(Event* event, signed int unused1);
static signed int spev08ActionEV03(Event* event, signed int count);
static void spev08CheckEV16(signed int n);
static signed int spev08ActionEV16(Event* event, signed int count);
static signed int spev08ActionEV19(Event* event, signed int count);
static void spev08SetLoopSound(Event* event);
static void spev08Liftman(Event* event, signed int no);
void tmevSetHorsePosition(float x, float y, float z, float angle);
void tmevSetStartPosition(float x, float y, float z, float angle, signed int player);
void tmevSetWarpPosition(float x, float y, float z, float angle, signed int player);
void tmevSetDrawLength(float length, signed int player);
void tmevSetViewAngle(float view_angle, signed int player);
void tmevSetAmbient(float* ambient, signed int player);
void tmevSetLightVector(float* light_color, float* normal_light, signed int id, signed int player);
void tmevSetVib(Event* event, signed int type, signed int no, signed int id);
float tmcrsGetEventModelFrame(signed int no, signed int id);
void tmcrsSetObjectHitLength(float length);
void tmcrsBreakObject(signed int no, float* dir);
void tmcrsMoveObject2(signed int no, float* rot, float* trans);
signed int tmcrsGetObjectPosition(float* position, signed int no);
void* spfxGetTexData(void);
unsigned long ultexGetTEX0(void* data);
void knEventSetShake(float power, float rate);
void knEventSetCameraPos(float* pos);
void knEventSetCameraObj(float* obj);
void ktactSetRecover(signed int pid, float* pos, float roty, float speed, signed int warp);
void akevInitLensFlare(unsigned int type, float* pos, unsigned int backz, unsigned int rgb);
signed int akevCheckDistance(float* pos1, float* pos2, float dis2);
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);

signed int spev08Init(Event* event) {
    static float dir[4] = { -0.4f, -0.4f, -0.8f, 0.0f };
    signed int i; // r17
    signed int j; // r16

    if (event->game.nplayer > 1) {
        tmevSetStartPosition(16.6f, -92.5f, -2.7f, 0.0013962635f, 0);
        tmevSetStartPosition(-18.8f, -92.5f, -2.6f, -0.045204025f, 1);
        tmevSetWarpPosition(16.6f, -92.5f, -2.7f, 0.0013962635f, 0);
        tmevSetWarpPosition(-18.8f, -92.5f, -2.6f, -0.045204025f, 1);
    } else {
        tmevSetStartPosition(0.0f, 0.0f, 0.0f, 0.0f, 0);
    }
    tmevSetHorsePosition(0.0f, 0.0f, 0.0f, 0.0f);
    tmevSetHorsePosition(576.7f, 595.4f, -602.1f, -0.21868975f);
    tmevSetHorsePosition(-432.5f, 3905.1f, -6804.2f, 0.29147f);
    tmevSetHorsePosition(597.2f, 4766.7f, -7137.7f, 0.36110866f);
    tmevSetHorsePosition(821.5f, 5267.8f, -8225.7f, 0.0047123893f);
    tmevSetHorsePosition(-1103.9f, 5223.7f, -8359.4f, 0.009424779f);
    tmevSetHorsePosition(-873.5f, 7860.8f, -12349.9f, 0.002617994f);
    tmevSetHorsePosition(612.6f, 2154.9f, -2520.6f, 0.019722221f);
    tmevSetHorsePosition(648.4f, 6791.0f, -11998.0f, 0.031590458f);
    tmevSetHorsePosition(-13.0f, 2392.0f, -3324.9f, 0.0010471976f);
    tmevSetHorsePosition(-603.2f, 1972.8f, -2153.3f, 0.24347344f);
    tmevSetHorsePosition(-2.7f, 5165.6f, -7988.7f, 0.115017205f);
    vspev08EventData = (Vspev08EventData*)ulMalloc(0x1230, 0, 0);
    akevInitLensFlare(3, dir, 0x1100, 0x808080);
    akevInitTextureScroll(vspev08TexScrool, vspev08TexScrInfo, 6);
    vspev08EventData->particle = (Smoke*)akevInitSmoke(300);
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            vspev08EventData->snowmachine[i][j] = vspev08SnowMachineInfo0[j];
            sceVu0CopyVector(vspev08EventData->snowmachine[i][j].pos, vspev08SnowMachinePos[i][0]);
            sceVu0CopyVector(vspev08EventData->snowmachine[i][j].mov, vspev08SnowMachinePos[i][1]);
        }
        vspev08EventData->snowmachine[i][0].tex0 = ultexGetTEX0((char*)spfxGetTexData() + 0x190);
        vspev08EventData->snowmachine[i][1].tex0 = ultexGetTEX0((char*)spfxGetTexData() + 0x1A0);
    }
    vspev08BridgeSmokeInfo[0].tex0 = vspev08BridgeSmokeInfo[1].tex0 = ultexGetTEX0((char*)spfxGetTexData() + 0x190);
    return 0;
}

signed int spev08ResetEvent(Event* event) {
    static float light[5][4] = {
        { 0.7f, 0.6f, 0.6f, 0.0f },
        { 0.8f, 1.0f, 0.3f, 0.0f },
        { 0.2f, 0.2f, 0.3f, 0.0f },
        { -0.4f, 1.0f, -0.8f, 0.0f },
        { 0.2f, 0.2f, 0.2f, 0.0f }
    };
    signed int i; // r17
    signed int j; // r16

    tmevSetDrawLength(3700.0f, 0);
    tmevSetDrawLength(3700.0f, 1);
    event->course.fog->near = 1900.0f;
    event->course.fog->far = 3300.0f;
    event->course.fog->max = 255.0f;
    event->course.fog->min = 0.0f;
    event->course.fog->col[0] = 0x40;
    event->course.fog->col[1] = 0x40;
    event->course.fog->col[2] = 0x40;
    event->course.fog->col[3] = 0x80;
    tmevSetBGFog(1, 0);
    tmevSetBGFog(1, 1);
    tmcrsSetMipMapLength(0x91, 0);
    spev08ResetObject(event);
    akevResetTextureScroll(vspev08TexScrool, vspev08TexScrInfo, 6);
    akevResetSmoke(vspev08EventData->particle);
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 2; j++) {
            akevResetSmokeInfo(&vspev08EventData->snowmachine[i][j]);
        }
    }
    akevResetSmokeInfo(&vspev08BridgeSmokeInfo[0]);
    akevResetSmokeInfo(&vspev08BridgeSmokeInfo[1]);
    tmevSetLightVector(light[0], light[1], 0, 0);
    tmevSetLightVector(light[0], light[1], 0, 1);
    tmevSetLightVector(light[2], light[3], 1, 0);
    tmevSetLightVector(light[2], light[3], 1, 1);
    tmevSetAmbient(light[4], 0);
    tmevSetAmbient(light[4], 1);
    vspev08EventData->sound[0].id = nmeventPlayLoop(0, 5);
    vspev08EventData->sound[1].id = nmeventPlayLoop(1, 6);
    vspev08EventData->sound[2].id = nmeventPlayLoop(2, 0xD);
    for (i = 0; i < 3; i++) {
        vspev08EventData->sound[i].vol = 0;
        nmvcSetInterVol(vspev08EventData->sound[i].id, vspev08EventData->sound[i].vol, 0);
    }
    return 0;
}

signed int spev08MainEvent(Event* event) {
    signed int i; // r17
    signed int j; // r16
    signed int c; // r19
    signed int f; // r20
    sceVu0FVECTOR* cpos; // r18
    float z; // 0x64(r29)
    float cdl; // 0x68(r29)
    float fog; // 0x6C(r29)

    akSrandf(rand());
    cpos = &event->character[event->game.player].ctrl->sys_mat->cam_trans;
    if (event->game.pause == 0) {
        if ((event->game.nplayer == 1) || (vspenvGame->mode.match_rule == 3)) {
            akevCalcTextureScroll(vspev08TexScrool, vspev08TexScrInfo, 6);
        }
        for (i = 0; i < 11; i++) {
            if ((event->game.mode == 0) || ((tmevGetFlag(i + 0x27) == 0) && (akevCheckDistance(*cpos, vspev08SnowMachinePos[i][0], 2250000.0f) != 0))) {
                for (j = 0; j < 2; j++) {
                    akevBlowupSmoke(vspev08EventData->particle, &vspev08EventData->snowmachine[i][j]);
                }
            }
        }
        f = tmevGetFlag(0x1E);
        if (f & 4) {
            spev08ActionEV03(event, -1);
            tmcrsSetHitCollision(0x22, 0, 0xC009);
            tmcrsSetHitCollision(0x27, 0, 9);
            tmcrsSetHitCollision(0x28, 0, 0xC009);
        } else if (f == 3) {
            c = tmevGetICounter(5) + 1;
            if (c == 1) {
                tmevSetFlag(0x30, 1);
                tmevSetFlag(0x31, 1);
                spEnterEventCameraMode();
                knEventStart();
            }
            if (spev08ActionEV03(event, c) != 0) {
                tmevSetFlag(0x1E, 7);
                spExitEventCameraMode();
                knEventEnd();
                tmcrsSetRailCollision(0xD7, 0);
                tmcrsSetRailCollision(0x13, 0);
                tmcrsSetRailCollision(0x14, 0);
                tmcrsSetRailCollision(0xD8, 0);
                tmcrsSetRailCollision(0xBF, 1);
                tmcrsSetRailCollision(0x15, 1);
                tmcrsSetRailCollision(0x16, 1);
                tmcrsSetRailCollision(0xD9, 1);
                tmcrsSetRailCollision(0x296, 0);
                tmcrsSetRailCollision(0x295, 1);
            }
        } else {
            tmcrsSetHitCollision(0x20, 0x20, 0xC009);
            tmcrsSetHitCollision(0x25, 0, 9);
            tmcrsSetHitCollision(0x26, 0, 0xC009);
            tmcrsSetHitCollision(0x53, 0, 0xC004);
            tmcrsSetHitCollision(0x54, 0, 9);
        }
        f = tmevGetFlag(0x1F);
        if (f & 4) {
            spev08ActionEV16(event, -1);
            tmcrsSetHitCollision(0x2F, 0, 9);
            tmcrsSetHitCollision(0x30, 0, 0xC004);
            tmcrsSetHitCollision(0x31, 0, 0xC009);
        } else if (f == 3) {
            c = tmevGetICounter(6) + 1;
            if (c == 1) {
                spEnterEventCameraMode();
                knEventStart();
            }
            if (spev08ActionEV16(event, c) != 0) {
                tmevSetFlag(0x1F, 4);
                spExitEventCameraMode();
                knEventEnd();
                tmcrsSetRailCollision(0x26C, 1);
                tmcrsSetRailCollision(0x26D, 1);
                if ((event->game.mode == 1) && (event->game.nplayer == 1)) {
                    tmevSetLevelGoal(event->game.player, 7);
                }
            }
        } else {
            tmcrsSetHitCollision(0x5A, 0x5A, 0xC009);
            tmcrsSetHitCollision(0x5B, 0x5B, 0xC009);
            tmcrsSetHitCollision(0x2D, 0, 9);
            tmcrsSetHitCollision(0x2E, 0, 0xC004);
        }
        switch (tmevGetFlag(0x20)) {
        case 1:
            c = tmevGetICounter(7) + 1;
            if (c == 1) {
                spEnterEventCameraMode();
                knEventStart();
            }
            if (spev08ActionEV19(event, c) != 0) {
                tmevSetFlag(0x20, 2);
                spExitEventCameraMode();
                knEventEnd();
                tmcrsSetRailCollision(0x58, 0);
                tmcrsSetRailCollision(0xC2, 0);
                tmcrsSetRailCollision(0x59, 1);
                tmcrsSetRailCollision(0x5A, 1);
                tmcrsSetRailCollision(0x5B, 1);
                tmcrsSetRailCollision(0x5C, 1);
                tmcrsSetRailCollision(0x24F, 1);
                tmcrsSetRailCollision(0x250, 1);
                tmcrsSetRailCollision(0x251, 1);
                if ((event->game.mode == 1) && (event->game.nplayer == 1)) {
                    tmevSetLevelGoal(event->game.player, 6);
                }
            }
            break;
        case 2:
            spev08ActionEV19(event, -1);
            tmcrsSetHitCollision(0x2C, 0, 0xC009);
            tmcrsSetHitCollision(0x2B, 0, 9);
            tmcrsSetHitCollision(0x190, 0, 0x809);
            tmcrsSetHitCollision(0x191, 0, 0xC809);
            break;
        default:
            tmcrsSetHitCollision(0x2A, 0x2A, 0xC009);
            tmcrsSetHitCollision(0x29, 0, 9);
            tmcrsSetHitCollision(0x1C2, 0, 9);
            break;
        }
        spev08Liftman(event, 0);
        spev08Liftman(event, 1);
        spev08Liftman(event, 2);
        if (event->game.nplayer > 1) {
            tmcrsSetHitCollision(0xC8, 0, 9);
        }
        akevCalcSmoke(vspev08EventData->particle);
    }
    if ((event->game.nplayer == 1) || (vspenvGame->mode.match_rule == 3)) {
        akevSetTextureScroll(vspev08TexScrool, 6);
    }
    spev08SetLoopSound(event);
    if ((*cpos)[2] >= -10000.0f) {
        z = 0.0f;
    } else if ((*cpos)[2] >= -13000.0f) {
        z = ((*cpos)[2] - -10000.0f) / -3000.0f;
    } else {
        z = 1.0f;
    }
    cdl = 3700.0f;
    fog = 255.0f * z;
    tmevSetDrawLength(cdl, event->game.player);
    event->course.fog->min = fog;
    return 0;
}

signed int spev08PlayerEvent(Event* event) {
    signed int player = event->game.player; // r16
    signed int mcnt; // r17
    sceVu0FVECTOR* cpos = &event->character[event->game.player].ctrl->sys_mat->cam_trans; // r18

    if (event->game.pause == 0) {
        if (event->character[player].ctrl->act.sliding_state == 4) {
            tmevStartICounter((player * 2) + 1);
        } else {
            tmevStopICounter((player * 2) + 1);
            tmevResetICounter((player * 2) + 1);
        }
        mcnt = tmevGetICounter((player * 2) + 1);
        spev08CheckClearFlag1(event);
        spev08CheckHit(event, mcnt);
        spev08CheckRail(event);
        spev08CheckObject(event, mcnt);
        spev08CheckHandPlant(event);
        spev08CheckClearFlag2(event, mcnt);
        if ((event->game.nplayer < 2) && (tmevGetFlag(0x23) == 0) && (event->game.mode == 1) && (tmevGetICounter(0) == 0x78)) {
            tmevSetFlag(0x23, 1);
            tmevResetICounter(8);
            tmevStartICounter(8);
        }
        tmevSetViewAngle(((*cpos)[2] < -3200.0f) ? -1.0f : 3.1415f, player);
    }
    return 0;
}

signed int spev08DrawEvent(Event* event) {
    sceVu0FMATRIX* wsmat; // r16

    wsmat = (event->character[event->game.player].ctrl->sys_mat->world_screen);
    akevDrawSmoke(vspev08EventData->particle, vgmsysAbuf, wsmat, event->course.fog);
    return 0;
}

signed int spev08DrawPlayerEvent(Event* event) {
    return 0;
}

signed int spev08FinishPlayerEvent(Event* event) {
    return 0;
}

void spev08End() {
    ulFree(vspev08EventData);
    akevFreeSmoke(vspev08EventData->particle);
}

static void spev08ResetObject(Event* event) {
    static const signed int sp_tbl[22] = { 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255 };
    static const signed int ScissorObj[50] = { 178, 40, 39, 41, 28, 29, 42, 54, 228, 35, 36, 37, 38, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 162, 163, 53, 148, 149, 150, 151, 152, 153, 155, 156, 157, 158, 159, 160, 122, 233, 0, 1, 2, 3, 169, 170, 171, 172, 173, -1 };
    static const signed int DisableObj[3] = { 178, 39, -1 };
    static const signed int DisableRail[15] = { 191, 21, 22, 217, 661, 89, 90, 91, 92, 591, 592, 593, 620, 621, -1 };
    static const signed int Warp1P[8] = { 256, 257, 226, 227, 165, 166, 167, 168 };
    signed int i; // r16
    signed int j; // r17

    tmcrsResetAllObject();
    tmcrsSetObjectHitLength(200.0f);
    for (i = 0; i < 22; i++) {
        tmevSetSponsor(i, sp_tbl[i]);
    }
    tmevSetCourseLogo(0x18);
    tmevSetCourseLogo(0x19);
    tmevSetCourseLogo(0x1A);
    tmevSetCourseLogo(0x1B);
    tmevSetWarpArrow(0xA5);
    tmevSetWarpArrow(0xA6);
    tmevSetWarpArrow(0xA4);
    tmevSetWarpArrow(0xA7);
    tmevSetWarpArrow(0xA8);
    tmevSetVsWarpObject(0xE1);
    tmevSetVsWarpObject(0xA4);
    tmevSetVsWarpObject(0xE5);
    tmevSetVsObject(0x102);
    tmevSetVsObject(0xE1);
    tmevSetVsObject(0xA4);
    tmevSetVsObject(0xE5);
    tmevSetWarpNo(0xCB, 0x1D);
    for (i = 0; vspev08BoundObject[i][0] >= 0; i++) {
        for (j = 0; j < vspev08BoundObject[i][1]; j++) {
            tmcrsSetObjectBound(j + vspev08BoundObject[i][0], 1);
        }
    }
    for (i = 0; ScissorObj[i] >= 0; i++) {
        tmcrsSetObjectScissorFlag(ScissorObj[i], 1);
    }
    for (i = 0; DisableObj[i] >= 0; i++) {
        tmcrsSetObjectDrawFlag(DisableObj[i], 0);
    }
    for (i = 0; DisableRail[i] >= 0; i++) {
        tmcrsSetRailCollision(DisableRail[i], 0);
    }
    for (i = 0; i < 3; i++) {
        vspev08EventData->evmdl[i].no = 0;
        vspev08EventData->evmdl[i].id = 3;
        vspev08EventData->evmdl[i].frame = 0.0f;
        vspev08EventData->evmdl[i].draw = 0;
        vspev08EventData->evmdl[i].light = 1;
        sceVu0UnitMatrix(vspev08EventData->evmdl[i].matrix);
    }
    tmcrsResetEventModel(3, vspev08EventData->evmdl);
    if (event->game.nplayer < 2) {
        for (i = 0; i < 4; i++) {
            tmcrsSetObjectScissorFlag(Warp1P[i], 1);
        }
        if (tmevGetLevelGoalFlag(7) != 0) {
            tmevSetFlag(0x1F, 7);
            tmcrsSetRailCollision(0x26C, 1);
            tmcrsSetRailCollision(0x26D, 1);
        }
        if (tmevGetLevelGoalFlag(6) != 0) {
            tmevSetFlag(0x20, 2);
            tmcrsSetRailCollision(0x58, 0);
            tmcrsSetRailCollision(0xC2, 0);
            tmcrsSetRailCollision(0x59, 1);
            tmcrsSetRailCollision(0x5A, 1);
            tmcrsSetRailCollision(0x5B, 1);
            tmcrsSetRailCollision(0x5C, 1);
        }
    } else {
        for (i = 0; i < 8; i++) {
            tmcrsSetObjectDrawFlag(Warp1P[i], 0);
        }
        tmcrsSetObjectScissorFlag(0xE1, 1);
        tmcrsSetObjectScissorFlag(0x102, 1);
        tmcrsSetObjectDrawFlag(0x2D, 0);
        tmcrsSetObjectDrawFlag(0x2E, 0);
        tmcrsSetObjectDrawFlag(0x2F, 0);
        tmcrsSetObjectDrawFlag(0x1F, 0);
        tmcrsSetObjectDrawFlag(0x20, 0);
        tmcrsSetObjectDrawFlag(0x21, 0);
        tmcrsSetObjectDrawFlag(0x22, 0);
        tmcrsSetObjectDrawFlag(0xA, 0);
        tmcrsSetObjectDrawFlag(0xB, 0);
        tmcrsSetObjectDrawFlag(0xC, 0);
        tmcrsSetObjectDrawFlag(0xD, 0);
        tmcrsSetObjectDrawFlag(0xE, 0);
        tmcrsSetObjectDrawFlag(0xF, 0);
        tmcrsSetObjectDrawFlag(0x10, 0);
        tmcrsSetObjectDrawFlag(0x11, 0);
        tmcrsSetObjectDrawFlag(0x12, 0);
        tmcrsSetObjectDrawFlag(0x13, 0);
        tmcrsSetObjectDrawFlag(0x14, 0);
        tmcrsSetObjectDrawFlag(0x15, 0);
        tmcrsSetObjectDrawFlag(0x16, 0);
        tmcrsSetObjectDrawFlag(0x17, 0);
        tmcrsSetObjectDrawFlag(0x74, 0);
        tmcrsSetObjectDrawFlag(0x75, 0);
        tmcrsSetObjectDrawFlag(4, 0);
        tmcrsSetObjectDrawFlag(5, 0);
        tmcrsSetObjectDrawFlag(6, 0);
        tmcrsSetObjectDrawFlag(7, 0);
        tmevSetFlag(0x1E, 7);
        tmcrsSetRailCollision(0xD7, 0);
        tmcrsSetRailCollision(0x13, 0);
        tmcrsSetRailCollision(0x14, 0);
        tmcrsSetRailCollision(0xD8, 0);
        tmcrsSetRailCollision(0xBF, 1);
        tmcrsSetRailCollision(0x15, 1);
        tmcrsSetRailCollision(0x16, 1);
        tmcrsSetRailCollision(0xD9, 1);
        tmcrsSetRailCollision(0x296, 0);
        tmcrsSetRailCollision(0x295, 1);
        tmcrsSetObjectDrawFlag(0xE4, 0);
        tmcrsSetObjectDrawFlag(0x23, 0);
        tmcrsSetObjectDrawFlag(0x24, 0);
        tmcrsSetObjectDrawFlag(0x25, 0);
        tmcrsSetObjectDrawFlag(0x26, 0);
        tmevSetFlag(0x30, 1);
        tmevSetFlag(0x31, 1);
        tmevSetFlag(0x1F, 7);
        tmcrsSetRailCollision(0x26C, 1);
        tmcrsSetRailCollision(0x26D, 1);
        tmevSetFlag(0x2A, 1);
        tmevSetFlag(0x2B, 1);
        tmevSetFlag(0x2C, 1);
        tmevSetFlag(0x20, 2);
        tmcrsSetRailCollision(0x58, 0);
        tmcrsSetRailCollision(0xC2, 0);
        tmcrsSetRailCollision(0x59, 1);
        tmcrsSetRailCollision(0x5A, 1);
        tmcrsSetRailCollision(0x5B, 1);
        tmcrsSetRailCollision(0x5C, 1);
    }
}

static const signed int Gap2Hit[2][4] = {
    { 50, 51, 0, 0 },
    { -1, -1, -1, -1 }
};

static const signed int Gap2HpHit[3][4] = {
    { 55, 56, 1, 7 },
    { 67, 68, 3, 12 },
    { -1, -1, -1, -1 }
};

static void spev08CheckHit(Event* event, signed int unused1) {
    static const struct {
        signed int hit;
        signed int gap;
    } AirGapHit[6] = {
        { 300, 1 },
        { 301, 2 },
        { 302, 3 },
        { 303, 4 },
        { 304, 5 },
        { -1, -1 }
    };
    static const struct {
        signed int hit;
        signed int gap;
    } JumpGapHit[5] = {
        { 54, 6 },
        { 57, 8 },
        { 58, 9 },
        { 65, 11 },
        { -1, -1 }
    };
    static const struct {
        signed int hit;
        signed int gap;
    } GrindGapHit[6] = {
        { 75, 30 },
        { 76, 31 },
        { 77, 32 },
        { 78, 33 },
        { 79, 34 },
        { -1, -1 }
    };
    static const struct {
        signed int hit;
        signed int flag;
    } SnowmachineHit[4] = {
        { 71, 39 },
        { 81, 40 },
        { 80, 41 },
        { -1, -1 }
    };
    static float grasscrash[4] = { 0.0f, 0.0f, -5.0f, 0.0f };
    static float warppos[3][4] = {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { -888.4f, 731.4f, -946.1f, -0.7731809f },
        { 800.6f, 1760.7f, -1469.7f, -0.006283186f }
    };
    signed int player = event->game.player; // r17
    signed int i; // r20
    signed int j; // r16
    signed int hit; // r18
    signed int bonk = event->character[player].ctrl->act.trg_bonk; // r23
    signed int onair = (event->character[player].ctrl->act.sliding_state == 3) || bonk; // r21
    signed int jump = event->character[player].ctrl->act.jump_air; // 0xA4(r29)
    signed int hp = event->character[player].ctrl->act.hp_air; // r22
    signed int rail = event->character[player].rail; // 0xA8(r29)
    signed int orail = event->character[player].old_rail; // r30
    signed int f; // 0xAC(r29)
    signed int n; // r19

    for (i = 0; i < event->character[player].nhit; i++) {
        hit = event->character[player].hit[i].no;
        n = tmevGetFlag((player * 15) + 0xD);
        for (j = 0; AirGapHit[j].hit >= 0; j++) {
            if ((hit == AirGapHit[j].hit) && !(n & (1 << j))) {
                tmevSetGap(player, AirGapHit[j].gap);
                n |= 1 << j;
            }
        }
        tmevSetFlag((player * 15) + 0xD, n);
        n = tmevGetFlag((player * 15) + 0xE);
        if (jump && onair) {
            for (j = 0; JumpGapHit[j].hit >= 0; j++) {
                if ((hit == JumpGapHit[j].hit) && !(n & (1 << j))) {
                    tmevSetGap(player, JumpGapHit[j].gap);
                    n |= 1 << j;
                }
            }
        }
        tmevSetFlag((player * 15) + 0xE, n);
        if (rail >= 0) {
            n = tmevGetFlag((player * 15) + 0xA);
            if (hit == GrindGapHit[n].hit) {
                tmevSetGap(player, GrindGapHit[n].gap);
                tmevSetFlag((player * 15) + 0xA, n + 1);
            }
        }
        for (j = 0; Gap2Hit[j][0] >= 0; j++) {
            if ((hit == Gap2Hit[j][0]) && (tmevGetFlag(Gap2Hit[j][2] + (player * 15)) == 0) && onair) {
                tmevSetFlag(Gap2Hit[j][2] + (player * 15), 1);
            } else if ((tmevGetFlag(Gap2Hit[j][2] + (player * 15)) == 1) && (hit == Gap2Hit[j][1])) {
                tmevSetGap(player, Gap2Hit[j][3]);
                tmevSetFlag(Gap2Hit[j][2] + (player * 15), 0);
            }
        }
        for (j = 0; Gap2HpHit[j][0] >= 0; j++) {
            if ((hit == Gap2HpHit[j][0]) && (tmevGetFlag(Gap2HpHit[j][2] + (player * 15)) == 0) && onair) {
                tmevSetFlag(Gap2HpHit[j][2] + (player * 15), 1);
            } else if ((tmevGetFlag(Gap2HpHit[j][2] + (player * 15)) == 1) && (hit == Gap2HpHit[j][1]) && hp) {
                tmevSetGap(player, Gap2HpHit[j][3]);
                tmevSetFlag(Gap2HpHit[j][2] + (player * 15), 0);
            }
        }
        if (bonk) {
            for (i = 0; SnowmachineHit[i].hit >= 0; i++) {
                if (hit == SnowmachineHit[i].hit) {
                    tmevSetFlag(i + 0x27, !tmevGetFlag(i + 0x27));
                }
            }
        }
        switch (hit) {
        case 0x1F:
            if (tmevGetFlag(0x23) == 0) {
                tmevSetFlag(0x23, 1);
                tmevResetICounter(8);
                tmevStartICounter(8);
            }
            break;
        case 0x52:
        case 0x24:
            if (bonk) {
                nmeventPlay(event->game.player, 0xC);
                if (tmevGetFlag(0x22) != 0) {
                    tmcrsSetObjectDrawFlag(0x28, 1);
                    tmcrsSetObjectDrawFlag(0x27, 0);
                    tmcrsSetObjectDrawFlag(0xB2, 0);
                    tmevSetFlag(0x22, 0);
                } else {
                    tmcrsSetObjectDrawFlag(0x28, 0);
                    tmcrsSetObjectDrawFlag(0x27, 1);
                    tmcrsSetObjectDrawFlag(0xB2, 1);
                    tmevSetFlag(0x22, 1);
                    if (tmevGetFlag((player * 15) + 8) == 0) {
                        tmevSetGap(player, 0x16);
                        tmevSetFlag((player * 15) + 8, 1);
                    }
                }
            }
            break;
        case 0x20:
            f = tmevGetFlag(0x1E);
            if (bonk && (tmevGetFlag(0x1E) == 0)) {
                tmevSetFlag(0x1E, 3);
                tmevSetGap(player, 0x15);
                tmevResetICounter(5);
                tmevStartICounter(5);
                tmcrsSetRailCollision(0xD7, 0);
                tmcrsSetRailCollision(0x13, 0);
                tmcrsSetRailCollision(0x14, 0);
                tmcrsSetRailCollision(0xD8, 0);
                tmcrsSetRailCollision(0x296, 0);
            }
            break;
        case 0x2A:
            if (bonk && (tmevGetFlag(0x20) == 0)) {
                tmevSetGap(player, 0x13);
                tmevSetFlag((player * 15) + 0x21, 2);
            }
            break;
        case 0x48:
            tmevSetFlag(0x23, 0);
            tmevStopICounter(8);
            tmevResetICounter(8);
            break;
        case 0x49:
        case 0x5D:
            if ((event->game.nplayer == 1) && (tmevGetFlag(0x24) == 0)) {
                tmevSetFlag(0x24, (hit == 0x49) ? 1 : 2);
                tmevResetICounter(9);
                tmevStartICounter(9);
            }
            break;
        case 0x5A:
        case 0x5B:
            if (bonk) {
                spev08CheckEV16(hit - 0x5A);
            }
            break;
        case 0xC9:
        case 0xCA:
        case 0xCC:
        case 0xCD:
            if (event->game.nplayer < 2) {
                n = (hit == 0xCC) ? 1 : ((hit == 0xCD) ? 0 : 2);
                ktactSetRecover(player, warppos[n], warppos[n][3], 0.0f, 1);
                nmeventPlayWarp(player, 0x1C);
            }
            break;
        case 0x12C:
        case 0x12D:
        case 0x12E:
        case 0x12F:
        case 0x130:
            if (orail >= 0) {
                f = tmevGetFlag(0x25);
                n = hit - 0x12C;
                tmevSetFlag(0x25, f | (1 << n));
            }
            break;
        case 0x3C:
            if (onair && jump) {
                tmevSetFlag((player * 15) + 2, 1);
            }
            break;
        case 0x3B:
            if ((tmevGetFlag((player * 15) + 2) != 0) && ((orail == 0xC5) || (orail == 0xC6) || (orail == 0xC7) || (orail == 0xC8))) {
                tmevSetGap(player, 0xA);
                tmevSetFlag((player * 15) + 2, 0);
            }
            break;
        case 0x192:
            if (hp) {
                tmevSetGap(player, 0xD);
            }
            break;
        case 0x226:
            if (tmevGetFlag(0x32) == 0) {
                tmcrsBreakObject(0xA2, grasscrash);
                nmeventPlay(event->game.player, 4);
                tmevSetFlag(0x32, 1);
            }
            break;
        case 0x227:
            if (tmevGetFlag(0x33) == 0) {
                tmcrsBreakObject(0xA3, grasscrash);
                nmeventPlay(event->game.player, 4);
                tmevSetFlag(0x33, 1);
            }
            break;
        case 0x258:
            tmevSetFlag((player * 15) + 9, 1);
            break;
        case 0x259:
            if (tmevGetFlag((player * 15) + 9) == 1) {
                tmevSetFlag((player * 15) + 9, 2);
            }
            break;
        case 0x25A:
            if (tmevGetFlag((player * 15) + 9) == 2) {
                tmevSetGap(player, 0x1B);
                tmevSetFlag((player * 15) + 9, 0);
            }
            break;
        }
    }
}

static void spev08CheckRail(Event* event) {
    static const struct {
        signed int rail;
        signed int gap;
    } GapRail[3] = {
        { 24, 14 },
        { 94, 14 },
        { -1, -1 }
    };
    signed int player = event->game.player; // r17
    signed int rail = event->character[player].rail; // r20
    signed int orail = event->character[player].old_rail; // r19
    signed int bonk = event->character[player].ctrl->act.trg_bonk; // r23
    signed int onair = (event->character[player].ctrl->act.sliding_state == 3) || bonk; // 0xA0(r29)
    signed int i; // r18
    signed int f; // r16
    signed int n; // r21

    if (rail >= 0) {
        f = tmevGetFlag(0x25);
        for (i = 0; i < 5; i++) {
            if (f & (1 << i)) {
                f = tmevGetFlag(0x26);
                if (!(f & (1 << i))) {
                    f |= 1 << i;
                    if (f < 0x1F) {
                        n = !!(f & 0x10) + !!(f & 8) + !!(f & 4) + !!(f & 2) + !!(f & 1);
                        if ((event->game.mode == 1) && (event->game.nplayer == 1)) {
                            nmdispInputLevelCount(n, 5, 8);
                        }
                    } else if (f == 0x1F) {
                        if ((event->game.mode == 1) && (event->game.nplayer == 1)) {
                            tmevSetLevelGoal(player, 8);
                        }
                        f = 0xFF;
                    }
                    tmevSetFlag(0x26, f);
                }
            }
        }
    }
    if (rail >= 0) {
        ktactSetAccelOnGrind(player, !(rail == 0xDC));
        if (rail != orail) {
            switch (rail) {
            case 0x64:
            case 0x57:
            case 0x65:
            case 0x26E:
            case 0x26F:
                if (tmevGetFlag(player * 15) != 0) {
                    tmevSetGap(player, 0);
                    tmevSetFlag(player * 15, 0);
                }
                break;
            case 0x19:
            case 0x1A:
            case 0x1B:
            case 0x1C:
            case 0x1D:
            case 0x1E:
            case 0x1F:
                f = tmevGetFlag((player * 15) + 4) + 1;
                tmevSetFlag((player * 15) + 4, f);
                if (f == 3) {
                    tmevSetGap(player, 0xF);
                }
                break;
            case 0x21:
            case 0x22:
                if (orail == 0x20) {
                    tmevSetGap(player, 0x10);
                }
                break;
            case 0x23:
            case 0x24:
            case 0x25:
            case 0x26:
            case 0x27:
            case 0x28:
            case 0x29:
            case 0x2A:
            case 0x2B:
            case 0x2C:
            case 0x2D:
            case 0x2E:
            case 0x2F:
            case 0x30:
            case 0x31:
            case 0x32:
                f = tmevGetFlag((player * 15) + 5) + 1;
                tmevSetFlag((player * 15) + 5, f);
                if (f == 3) {
                    tmevSetGap(player, 0x11);
                }
                break;
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x38:
            case 0x39:
            case 0x3A:
            case 0x3B:
            case 0x3C:
            case 0x3D:
            case 0x3E:
            case 0x3F:
            case 0x40:
            case 0x41:
            case 0x42:
            case 0x43:
            case 0x44:
                f = tmevGetFlag((player * 15) + 6) + 1;
                tmevSetFlag((player * 15) + 6, f);
                if (f == 5) {
                    tmevSetGap(player, 0x12);
                }
                break;
            case 0x46:
            case 0x6B:
            case 0x6C:
            case 0x6D:
            case 0x6E:
            case 0x6F:
            case 0x70:
            case 0x71:
            case 0x72:
            case 0x73:
                f = tmevGetFlag((player * 15) + 7) + 1;
                tmevSetFlag((player * 15) + 7, f);
                if (f == 4) {
                    tmevSetGap(player, 0x14);
                }
                break;
            case 0x81:
            case 0x82:
            case 0x83:
            case 0x84:
            case 0x85:
            case 0x86:
            case 0xC3:
            case 0xC4:
                if ((tmevGetFlag((player * 15) + 2) != 0) && ((orail == 0xC5) || (orail == 0xC6) || (orail == 0xC7) || (orail == 0xC8))) {
                    tmevSetGap(player, 0xA);
                    tmevSetFlag((player * 15) + 2, 0);
                }
                break;
            case 0x58:
            case 0xC2:
                if (tmevGetFlag(0x20) == 0) {
                    tmevSetFlag((player * 15) + 0x21, 1);
                    tmevResetICounter((player * 2) + 2);
                    tmevStartICounter((player * 2) + 2);
                }
                break;
            default:
                for (i = 0; GapRail[i].rail >= 0; i++) {
                    if (rail == GapRail[i].rail) {
                        tmevSetGap(player, GapRail[i].gap);
                    }
                }
                break;
            }
        } else if ((tmevGetFlag((player * 15) + 0x21) == 1) && (tmevGetICounter((player * 2) + 2) >= 0x78)) {
            tmevResetICounter((player * 2) + 2);
            tmevStopICounter((player * 2) + 2);
            tmevSetGap(player, 0x13);
            tmevSetFlag((player * 15) + 0x21, 2);
        }
    } else {
        if (tmevGetFlag((player * 15) + 0x21) == 2) {
            tmevSetFlag(0x20, 1);
            tmevResetICounter(7);
            tmevStartICounter(7);
            tmcrsSetRailCollision(0x58, 0);
            tmcrsSetRailCollision(0xC2, 0);
        }
        tmevSetFlag((player * 15) + 0x21, 0);
        if ((f = 0, orail == 0x255) || (f = 0, orail == 0x256) || (f = 1, orail == 0x257) || (f = 1, orail == 0x258)) {
            spev08CheckEV16(f);
        }
    }
}

static void spev08CheckObject(Event* event, signed int unused1) {
    static const struct {
        signed int obj;
        signed int gap;
        signed int flag;
    } GapObj[4] = {
        { 53, 28, 0 },
        { 43, 29, 1 },
        { 44, 29, 1 },
        { -1, -1, 0 }
    };
    signed int player = event->game.player; // r17
    signed int i; // r20
    signed int j; // r16
    Col* obj; // r18
    signed int bonk = event->character[player].ctrl->act.trg_bonk; // r22
    signed int f; // r19

    obj = event->character[player].object;
    for (i = 0; i < event->character[player].nobj; i++, obj++) {
        for (j = 0; vspev08ObjectSe[j][0] >= 0; j++) {
            if (obj->obj_type == vspev08ObjectSe[j][0]) {
                if (vspev08ObjectSe[j][1] >= 0) {
                    nmeventPlay(player, vspev08ObjectSe[j][1]);
                }
                if (vspev08ObjectSe[j][2] >= 0) {
                    tmevSetVib(event, 0, vspev08ObjectSe[j][2], 7);
                }
            }
        }
        f = tmevGetFlag((player * 15) + 0xB);
        for (j = 0; GapObj[j].obj >= 0; j++) {
            if ((obj->obj_no == GapObj[j].obj) && !(f & (1 << GapObj[j].flag))) {
                tmevSetGap(player, GapObj[j].gap);
                tmevSetFlag((player * 15) + 0xB, f | (1 << GapObj[j].flag));
            }
        }
        switch (obj->obj_no) {
        case 0x1C:
            tmcrsSetRailCollision(0x11, 0);
            break;
        case 0x1D:
            tmcrsSetRailCollision(0x10, 0);
            break;
        case 0x2A:
            tmcrsSetRailCollision(0x12, 0);
            break;
        case 0x76:
            tmcrsSetRailCollision(0x25F, 0);
            break;
        case 0x77:
            tmcrsSetRailCollision(0x260, 0);
            break;
        case 0x78:
            tmcrsSetRailCollision(0x25D, 0);
            break;
        case 0x79:
            tmcrsSetRailCollision(0x25E, 0);
            break;
        default:
            switch (obj->obj_type) {
            case 0x19:
            case 0x1A:
                j = tmevGetFlag(0x34);
                nmeventPlay(player, vspev08GlassSe[j]);
                tmevSetFlag(0x34, (j + 1) % 3);
                break;
            }
            break;
        }
    }
}

static void spev08CheckHandPlant(Event* event) {
    signed int player = event->game.player; // r16
    signed int rail = event->character[player].rail; // r17
    signed int orail = event->character[player].old_rail; // r18

    if ((event->character[player].ctrl->act.sliding_state == 6) && (orail == -1)) {
        switch (rail) {
        case 0xBD:
        case 0xBE:
            tmevSetGap(player, 0x17);
            break;
        case 0x47:
            tmevSetGap(player, 0x18);
            break;
        case 0x48:
        case 0:
        case 0x7E:
            tmevSetGap(player, 0x19);
            break;
        case 0x74:
        case 0x75:
        case 0x76:
        case 0x77:
        case 0x78:
        case 0x79:
        case 0x7A:
        case 0x7B:
        case 0x7C:
        case 0x7D:
        case 0x6E:
        case 0x6F:
            tmevSetGap(player, 0x1A);
            break;
        }
    }
}

static void spev08CheckClearFlag1(Event* event) {
    signed int player = event->game.player; // r16
    signed int trklnk = event->character[player].ctrl->act.trk_link_state == 1; // r17

    if (!trklnk) {
        tmevSetFlag((player * 15) + 0xB, 0);
    }
}

static void spev08CheckClearFlag2(Event* event, signed int unused1) {
    signed int i; // r17
    signed int player = event->game.player; // r16
    signed int bonk = event->character[player].ctrl->act.trg_bonk; // r19
    signed int onair = (event->character[player].ctrl->act.sliding_state == 3) || bonk; // r20
    signed int onair2 = !event->character[player].ctrl->nowpos.hit; // r21
    signed int rail = event->character[player].rail; // r22
    signed int orail = event->character[player].old_rail; // r23

    if (!onair) {
        for (i = 0; Gap2Hit[i][2] >= 0; i++) {
            tmevSetFlag(Gap2Hit[i][2] + (player * 15), 0);
        }
        tmevSetFlag((player * 15) + 2, 0);
        tmevSetFlag((player * 15) + 8, 0);
        tmevSetFlag(0x25, 0);
        tmevSetFlag((player * 15) + 0xD, 0);
        tmevSetFlag((player * 15) + 0xE, 0);
    }
    if (!onair2) {
        tmevSetFlag((player * 15) + 9, 0);
    }
    if ((rail < 0) && (orail < 0)) {
        tmevSetFlag((player * 15) + 4, 0);
        tmevSetFlag((player * 15) + 5, 0);
        tmevSetFlag((player * 15) + 6, 0);
        tmevSetFlag((player * 15) + 7, 0);
        tmevSetFlag((player * 15) + 0xA, 0);
    }
}

static signed int spev08ActionEV03(Event* event, signed int count) {
    static float cam[2][4] = {
        { -706.8f, 5975.3f, -10848.0f, 0.0f },
        { -753.5f, 5977.1f, -10830.0f, 0.0f }
    };
    static float grasscrash[4] = { 0.0f, 20.0f, 0.0f, 0.0f };
    sceVu0FVECTOR r; // 0x20(r29)
    sceVu0FVECTOR t; // 0x30(r29)
    sceVu0FVECTOR r2; // 0x40(r29)
    sceVu0FVECTOR t2; // 0x50(r29)
    signed int ret = 0; // r16

    r[0] = r[1] = r[2] = r[3] = 0.0f;
    t[0] = t[1] = t[2] = t[3] = 0.0f;
    if (count > 0) {
        knEventSetCameraPos(cam[0]);
        knEventSetCameraObj(cam[1]);
        r2[0] = r2[1] = r2[2] = r2[3] = 0.0f;
        t2[0] = t2[1] = t2[2] = t2[3] = 0.0f;
        if (count < 0xC) {
            if (count == 1) {
                knEventSetShake(2.0f, 0.7f);
                akevResetEffect2(event->game.player);
                nmeventPlay2(event->game.player, 0x10);
            }
        } else {
            count -= 0xC;
            if (count < 0x5A) {
                r[0] = -0.13089968f * ((float)count / 90.0f) * ((float)count / 90.0f);
                if (count == 0) {
                    tmevSetFlag(0x30, 1);
                    tmevSetFlag(0x31, 1);
                }
            } else {
                count -= 0x5A;
                r[0] = -0.13089968f;
                r2[0] = 0.8333333f * (-0.017452778f * count);
                t2[1] = 150.0f * ((float)count / 30.0f) * ((float)count / 30.0f);
                t2[2] = 12.0f * ((float)count / 30.0f);
                if (count == 0) {
                    knEventSetShake(5.0f, 0.7f);
                    tmevSetVib(event, 1, 0, 7);
                    tmcrsBreakObject(0x23, grasscrash);
                    tmcrsBreakObject(0x24, grasscrash);
                    tmcrsBreakObject(0x25, grasscrash);
                    tmcrsBreakObject(0x26, grasscrash);
                    nmeventPlay2(event->game.player, 0xF);
                    nmeventPlay2(event->game.player, 4);
                }
                if (count >= 0x3C) {
                    tmcrsSetObjectDrawFlag(0xE4, 0);
                    ret = 1;
                }
            }
        }
        tmcrsMoveObject2(0xE4, r2, t2);
    } else {
        r[0] = -0.13089968f;
    }
    tmcrsMoveObject2(0x36, r, t);
    return ret;
}

static void spev08CheckEV16(signed int n) {
    signed int f = tmevGetFlag(0x1F); // r16

    if (!(f & 4) && !(f & (1 << n))) {
        f |= 1 << n;
        tmevSetFlag(0x1F, f);
        if (f == 3) {
            tmevResetICounter(6);
            tmevStartICounter(6);
        } else {
            nmdispInputLevelCount(1, 2, 7);
        }
    }
}

static signed int spev08ActionEV16(Event* event, signed int count) {
    static float cam[2][4] = {
        { 371.7f, 3424.6f, -5329.9f, 0.0f },
        { 393.0f, 3389.2f, -5358.1f, 0.0f }
    };
    sceVu0FVECTOR r; // 0x20(r29)
    sceVu0FVECTOR t; // 0x30(r29)
    signed int ret = 0; // r16

    r[0] = r[1] = r[2] = r[3] = 0.0f;
    t[0] = t[1] = t[2] = t[3] = 0.0f;
    if (count > 0) {
        knEventSetCameraPos(cam[0]);
        knEventSetCameraObj(cam[1]);
        if (count < 0x28) {
            if (count == 1) {
                knEventSetShake(2.0f, 0.7f);
                akevResetEffect2(event->game.player);
                nmeventPlay2(event->game.player, 0x11);
            }
            if ((count > 1) && (count < 0x1E)) {
                akevBlowupSmoke(vspev08EventData->particle, &vspev08BridgeSmokeInfo[0]);
            }
        } else {
            count -= 0x28;
            if (count < 0x5A) {
                r[0] = -0.3054326f * ((float)count / 90.0f) * ((float)count / 90.0f);
            } else {
                count -= 0x5A;
                r[0] = -0.3054326f;
                if (count == 0) {
                    knEventSetShake(5.0f, 0.7f);
                    tmevSetVib(event, 1, 0, 7);
                    nmeventPlay2(event->game.player, 0xF);
                }
                if ((count > 1) && (count < 0xF)) {
                    akevBlowupSmoke(vspev08EventData->particle, &vspev08BridgeSmokeInfo[1]);
                }
                if (count >= 0x3C) {
                    ret = 1;
                }
            }
        }
    } else {
        r[0] = -0.3054326f;
    }
    tmcrsMoveObject2(0x29, r, t);
    return ret;
}

static signed int spev08ActionEV19(Event* event, signed int count) {
    static float cam[2][4] = {
        { -429.0f, 6339.0f, -10743.0f, 0.0f },
        { -412.8f, 6362.1f, -10784.0f, 0.0f }
    };
    sceVu0FVECTOR r1; // 0x20(r29)
    sceVu0FVECTOR r2; // 0x30(r29)
    sceVu0FVECTOR t1; // 0x40(r29)
    sceVu0FVECTOR t2; // 0x50(r29)
    signed int ret = 0; // r16

    r1[0] = r1[1] = r1[2] = r1[3] = 0.0f;
    t1[0] = t1[1] = t1[2] = t1[3] = 0.0f;
    r2[0] = r2[1] = r2[2] = r2[3] = 0.0f;
    t2[0] = t2[1] = t2[2] = t2[3] = 0.0f;
    if (count > 0) {
        knEventSetCameraPos(cam[0]);
        knEventSetCameraObj(cam[1]);
        if (count < 0xC) {
            if (count == 1) {
                knEventSetShake(0.15f, 1.02f);
                akevResetEffect2(event->game.player);
                nmeventPlay2(event->game.player, 0x12);
            }
        } else {
            if ((count -= 0xC) < 0xB4) {
                r1[0] = 1.5707963f * ((float)count / 180.0f) * ((float)count / 180.0f);
            } else {
                if ((count -= 0xB4) < 0x50) {
                    r1[0] = 1.5707963f;
                    if (count == 0) {
                        knEventSetShake(6.0f, 0.7f);
                        tmevSetVib(event, 1, 0, 7);
                        nmeventPlay2(event->game.player, 0x13);
                    }
                    t2[1] = 1000.0f * ((float)(count + 0x14) / 100.0f) * ((float)(count + 0x14) / 100.0f);
                } else {
                    if ((count -= 0x50) < 0x32) {
                        r1[0] = 1.5707963f;
                        t2[1] = 1000.0f;
                        if (count == 0) {
                            knEventSetShake(4.0f, 0.7f);
                            tmevSetVib(event, 1, 0, 7);
                            nmeventPlay2(event->game.player, 0xF);
                        }
                    } else {
                        ret = 1;
                    }
                }
            }
        }
    } else {
        r1[0] = 1.5707963f;
        t2[1] = 1000.0f;
    }
    tmcrsMoveObject2(0x7A, r1, t1);
    tmcrsMoveObject2(0xE9, r2, t2);
    return ret;
}

static void spev08SetLoopSound(Event* event) {
    static struct {
        signed int n;
        sceVu0FVECTOR pos;
    } pos[31] = {
        { 0, { -1275.0f, 8327.0f, -13680.0f, 0.0f } },
        { 0, { -464.0f, 8330.0f, -13679.0f, 0.0f } },
        { 1, { -297.0f, 2844.0f, -5960.0f, 0.0f } },
        { 2, { 892.0f, 1910.0f, -2119.0f, 0.0f } },
        { 2, { 892.0f, 2061.0f, -2501.0f, 0.0f } },
        { 2, { 892.0f, 2220.0f, -2883.0f, 0.0f } },
        { 2, { 892.0f, 2375.0f, -3268.0f, 0.0f } },
        { 2, { 892.0f, 2500.0f, -3655.0f, 0.0f } },
        { 2, { 892.0f, 2615.0f, -4043.0f, 0.0f } },
        { 2, { 892.0f, 2784.0f, -4430.0f, 0.0f } },
        { 2, { 892.0f, 2973.0f, -4879.0f, 0.0f } },
        { 2, { 786.0f, 5454.0f, -9779.0f, 0.0f } },
        { 2, { 689.0f, 5365.0f, -9682.0f, 0.0f } },
        { 2, { 478.0f, 5223.0f, -9467.0f, 0.0f } },
        { 2, { 276.0f, 5188.0f, -9269.0f, 0.0f } },
        { 2, { -40.0f, 5119.0f, -8952.0f, 0.0f } },
        { 2, { -209.0f, 5066.0f, -8780.0f, 0.0f } },
        { 2, { -296.0f, 4971.0f, -8697.0f, 0.0f } },
        { 2, { -535.0f, 4830.0f, -8459.0f, 0.0f } },
        { 2, { -635.0f, 4809.0f, -8358.0f, 0.0f } },
        { 2, { -800.0f, 4736.0f, -8192.0f, 0.0f } },
        { 2, { -984.0f, 4581.0f, -8006.0f, 0.0f } },
        { 2, { -810.0f, 8341.0f, -13402.0f, 0.0f } },
        { 2, { -810.0f, 8475.0f, -13619.0f, 0.0f } },
        { 2, { -810.0f, 8525.0f, -13854.0f, 0.0f } },
        { 2, { -810.0f, 8664.0f, -14094.0f, 0.0f } },
        { 2, { -939.0f, 8336.0f, -13396.0f, 0.0f } },
        { 2, { -939.0f, 8470.0f, -13619.0f, 0.0f } },
        { 2, { -939.0f, 8518.0f, -13847.0f, 0.0f } },
        { 2, { -939.0f, 8670.0f, -14095.0f, 0.0f } },
        { -1, { 0.0f, 0.0f, 0.0f, 0.0f } }
    };
    signed int i; // r17
    signed int j; // r16
    float d[3]; // 0x60(r29)
    float l; // 0x70(r29)
    signed int nplayer = event->game.nplayer; // r19
    sceVu0FVECTOR* cpos = &event->character[event->game.player].ctrl->sys_mat->cam_trans; // r18
    sceVu0FVECTOR fv; // 0x50(r29)

    d[0] = d[1] = d[2] = 4294967296.0f;
    for (i = 0; i < nplayer; i++) {
        if ((nplayer <= 1) || (vspenvGame->mode.match_rule != 3) || (i == event->game.player)) {
            for (j = 0; pos[j].n >= 0; j++) {
                if ((j >= 3) || (tmevGetFlag(j + 0x27) == 0)) {
                    sceVu0SubVector(fv, pos[j].pos, *cpos);
                    sceVu0MulVector(fv, fv, fv);
                    l = fv[2] + (fv[0] + fv[1]);
                    if (d[pos[j].n] > l) {
                        d[pos[j].n] = l;
                    }
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        l = (256.0f * (160000.0f - d[i])) / 160000.0f;
        l = (l > 0.0f) ? l : 0.0f;
        l = l - vspev08EventData->sound[i].vol;
        l = (l > 32.0f) ? 32.0f : ((l < -32.0f) ? -32.0f : l);
        vspev08EventData->sound[i].vol += l;
        nmvcSetInterVol(vspev08EventData->sound[i].id, vspev08EventData->sound[i].vol, 0);
    }
}

static void spev08Liftman(Event* event, signed int no) {
    static const struct {
        signed int obj;
        signed int flag;
        signed int vflag;
        signed int counter;
    } liftman[3] = {
        { 230, 53, 56, 10 },
        { 231, 54, 57, 11 },
        { 232, 55, 58, 12 }
    };
    signed int player; // r21
    sceVu0FVECTOR* ppos; // r22
    sceVu0FVECTOR* cpos; // r30
    sceVu0FVECTOR opos; // 0xA0(r29)
    sceVu0FVECTOR fv; // 0xB0(r29)
    float cd; // 0xC8(r29)
    float pd; // 0xCC(r29)
    signed int flag; // r18
    signed int vcnt; // r19
    signed int count; // r17
    EventMdl* mdl = &vspev08EventData->evmdl[no]; // r16
    signed int v; // r20

    if ((event->game.nplayer == 2) && (vspenvGame->mode.match_rule != 3)) {
        tmcrsSetObjectDrawFlag(liftman[no].obj, 0);
        mdl->draw = 0;
        return;
    }
    player = event->game.player;
    ppos = &event->character[player].ctrl->nowpos.pos;
    cpos = &event->character[event->game.player].ctrl->sys_mat->cam_trans;
    tmcrsGetObjectPosition(opos, liftman[no].obj);
    opos[1] += 10.0f;
    sceVu0SubVector(fv, *cpos, opos);
    sceVu0MulVector(fv, fv, fv);
    cd = fv[2] + (fv[0] + fv[1]);
    sceVu0SubVector(fv, *ppos, opos);
    sceVu0MulVector(fv, fv, fv);
    pd = fv[2] + (fv[0] + fv[1]);
    flag = tmevGetFlag(liftman[no].flag);
    vcnt = tmevGetFlag(liftman[no].vflag);
    count = tmevGetICounter(liftman[no].counter);
    if (cd > 160000.0f) {
        tmcrsSetObjectDrawFlag(liftman[no].obj, 1);
        mdl->draw = 0;
        tmevStopICounter(liftman[no].counter);
        tmevResetICounter(liftman[no].counter);
        flag = 0;
    } else {
        if (flag == 0) {
            tmevStartICounter(liftman[no].counter);
            flag = 1;
            count = 0;
        }
        tmcrsSetObjectDrawFlag(liftman[no].obj, 0);
        mdl->draw = 1;
        sceVu0UnitMatrix(mdl->matrix);
        sceVu0CopyVector(mdl->matrix[3], opos);
        mdl->matrix[3][3] = 1.0f;
        if (flag < 4) {
            sceVu0SubVector(fv, opos, *ppos);
            fv[1] = fv[3] = 0.0f;
            sceVu0Normalize(vspev08EventData->lmdir[no], fv);
        }
        mdl->matrix[0][0] = vspev08EventData->lmdir[no][2];
        mdl->matrix[2][2] = vspev08EventData->lmdir[no][2];
        mdl->matrix[2][0] = vspev08EventData->lmdir[no][0];
        mdl->matrix[0][2] = -vspev08EventData->lmdir[no][0];
        switch (flag) {
        case 1:
            if (count >= (tmcrsGetEventModelFrame(0, 3) / 80.0f)) {
                tmevResetICounter(liftman[no].counter);
                count = 0;
            }
            mdl->id = mdl->old_id = 3;
            mdl->frame = 80.0f * count;
            if (pd < 40000.0f) {
                flag++;
                tmevResetICounter(liftman[no].counter);
            }
            break;
        case 2:
            mdl->id = 0;
            mdl->frame = 80.0f * count;
            if (count >= ((tmcrsGetEventModelFrame(0, 0) / 80.0f) - 1.0f)) {
                flag++;
                tmevResetICounter(liftman[no].counter);
            }
            break;
        case 3:
            if (count >= (tmcrsGetEventModelFrame(0, 1) / 80.0f)) {
                tmevResetICounter(liftman[no].counter);
                count = 0;
            }
            mdl->id = 1;
            mdl->frame = 80.0f * count;
            if (pd < 100.0f) {
                flag++;
                tmevResetICounter(liftman[no].counter);
                nmeventPlayVoice(player, 0x1B);
                tmevSetVib(event, 0, 5, 7);
            }
            break;
        case 4:
            if (count >= (tmcrsGetEventModelFrame(0, 2) / 80.0f)) {
                tmevStopICounter(liftman[no].counter);
                count = tmcrsGetEventModelFrame(0, 2) / 80.0f;
            }
            mdl->id = 2;
            mdl->frame = 80.0f * count;
            break;
        }
    }
    if ((flag < 4) && (pd < 10000.0f) && (vcnt == 0)) {
        v = 255.0f / (cd / 40000.0f);
        v = (v > 0xFF) ? 0xFF : v;
        nmvcSetInterVol(nmeventPlayVoice(player, (tmevGetICounter(0) % 3) + 0x18), v, 0);
        vcnt = 1;
    }
    if (pd > 22500.0f) {
        vcnt = 0;
    }
    tmevSetFlag(liftman[no].flag, flag);
    tmevSetFlag(liftman[no].vflag, vcnt);
}
