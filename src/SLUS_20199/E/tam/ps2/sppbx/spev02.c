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

//////// vspRider Struct ///////////////////////////////////////////////
// Last updated: 08/14/2024

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

// spev02.c structs ////////////////////////////////////////////////////////////////////

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
    float pos[4]; // Offset: 0x30, DWARF: 0x1CCC69
    float pos2[4]; // Offset: 0x40, DWARF: 0x1CCC8B
    float mov[4]; // Offset: 0x50, DWARF: 0x1CCCAE
    float mov2[4]; // Offset: 0x60, DWARF: 0x1CCCD0
    float acc[4]; // Offset: 0x70, DWARF: 0x1CCCF3
    float dec[4]; // Offset: 0x80, DWARF: 0x1CCD15
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

// Size: 0x60, DWARF: 0x1CE3B9
typedef struct Vspev02Smoke
{
    signed int num; // Offset: 0x0, DWARF: 0x1CE3D5
    signed int _max; // Offset: 0x4, DWARF: 0x1CE3F5
    // Size: 0x50, DWARF: 0x1CDE58
    Data data[1]; // Offset: 0x10, DWARF: 0x1CE416
} Vspev02Smoke;

// Size: 0x70, DWARF: 0x1CC2E3
typedef struct Vspev02EventMdl
{
    float pos[4]; // Offset: 0x0, DWARF: 0x1CC2FF
    sceVu0FMATRIX matrix; // Offset: 0x10, DWARF: 0x1CC321
    signed int no; // Offset: 0x50, DWARF: 0x1CC346
    signed int id; // Offset: 0x54, DWARF: 0x1CC365
    float frame; // Offset: 0x58, DWARF: 0x1CC384
    signed int draw; // Offset: 0x5C, DWARF: 0x1CC3A6
    signed int light; // Offset: 0x60, DWARF: 0x1CC3C7
    signed int old_id; // Offset: 0x64, DWARF: 0x1CC3E9
    signed int cnt; // Offset: 0x68, DWARF: 0x1CC40C
    signed int flag; // Offset: 0x6C, DWARF: 0x1CC42C
} Vspev02EventMdl;

// Size: 0x30, DWARF: 0x1C82D9
typedef struct Vspev02Lift
{
    signed int no; // Offset: 0x0, DWARF: 0x1C82F4
    signed int pos; // Offset: 0x4, DWARF: 0x1C8313
    float add; // Offset: 0x8, DWARF: 0x1C8333
    signed int res; // Offset: 0xC, DWARF: 0x1C8353
    float rot[4]; // Offset: 0x10, DWARF: 0x1C8373
    float trans[4]; // Offset: 0x20, DWARF: 0x1C8395
} Vspev02Lift;

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

// Size: 0x10, DWARF: 0x1CC767
typedef struct Vspev02SeLift
{
    signed int id; // Offset: 0x0, DWARF: 0x1CC783
    signed int vol; // Offset: 0x4, DWARF: 0x1CC7A2
    signed int num; // Offset: 0x8, DWARF: 0x1CC7C2
    signed int res; // Offset: 0xC, DWARF: 0x1CC7E2
} Vspev02SeLift;

// Size: 0x30, DWARF: 0x1CC1D6
typedef struct Vspev02Gond
{
    signed int no; // Offset: 0x0, DWARF: 0x1CC1F2
    signed int pos; // Offset: 0x4, DWARF: 0x1CC211
    signed int state; // Offset: 0x8, DWARF: 0x1CC231
    float add; // Offset: 0xC, DWARF: 0x1CC253
    float rot[4]; // Offset: 0x10, DWARF: 0x1CC273
    float trans[4]; // Offset: 0x20, DWARF: 0x1CC295
} Vspev02Gond;

// Size: 0x30, DWARF: 0x1C8782
typedef struct Vspev02Gear
{
    signed int no; // Offset: 0x0, DWARF: 0x1C879D
    signed int cnt; // Offset: 0x4, DWARF: 0x1C87BC
    signed int flag; // Offset: 0x8, DWARF: 0x1C87DC
    float tmp; // Offset: 0xC, DWARF: 0x1C87FD
    float rot[4]; // Offset: 0x10, DWARF: 0x1C881D
    float trans[4]; // Offset: 0x20, DWARF: 0x1C883F
} Vspev02Gear;

// Size: 0x70, DWARF: 0x1CC2E3
typedef struct Vspev02WagonMdl
{
    float pos[4]; // Offset: 0x0, DWARF: 0x1CC2FF
    sceVu0FMATRIX matrix; // Offset: 0x10, DWARF: 0x1CC321
    signed int no; // Offset: 0x50, DWARF: 0x1CC346
    signed int id; // Offset: 0x54, DWARF: 0x1CC365
    float frame; // Offset: 0x58, DWARF: 0x1CC384
    signed int draw; // Offset: 0x5C, DWARF: 0x1CC3A6
    signed int light; // Offset: 0x60, DWARF: 0x1CC3C7
    signed int old_id; // Offset: 0x64, DWARF: 0x1CC3E9
    signed int cnt; // Offset: 0x68, DWARF: 0x1CC40C
    signed int flag; // Offset: 0x6C, DWARF: 0x1CC42C
} Vspev02WagonMdl;

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

// Size: 0x50, DWARF: 0x1CC90B
typedef struct Vspev02Light
{
    float light_color[2][4]; // Offset: 0x0, DWARF: 0x1CC927
    float normal_light[2][4]; // Offset: 0x20, DWARF: 0x1CC951
    float ambient[4]; // Offset: 0x40, DWARF: 0x1CC97C
} Vspev02Light;

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

// Size: 0xC, DWARF: 0x1CD448
typedef struct Vspev02Debug
{
    signed int item; // Offset: 0x0, DWARF: 0x1CD464
    signed int res[2]; // Offset: 0x4, DWARF: 0x1CD485
} Vspev02Debug;



//// Variables ////////////////////////////////////////////////////////////////////////

static float vspev02LiftPos[32][4]; // Address: 0x2D1FC0
static float vspev02Gond1Pos[7][4]; // Address: 0x2D21C0
static float vspev02Gond2Pos[7][4]; // Address: 0x2D2230
static float vspev02HorsePos[12][4]; // Address: 0x2E6740
static signed int vspev02Lamp[11][2]; // Address: 0x2E6800
// Size: 0x60, DWARF: 0x1CE3B9
Vspev02Smoke* vspev02Smoke; // Address: 0x2E7FDC
// Size: 0x70, DWARF: 0x1CC2E3
Vspev02EventMdl* vspev02EventMdl; // Address: 0x2E7FEC
// Size: 0x30, DWARF: 0x1C82D9
Vspev02Lift* vspev02Lift; // Address: 0x2E7FF4
void(*vtmevWarp)(Event*); // Address: 0x2E7B90
void(spev02MatchWarp)(Event*); // Address: 0x273A70
float vspev02View[2]; // Address: 0x2E7FC8
// Size: 0x20, DWARF: 0x1CB6E8
VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0
// Size: 0x10, DWARF: 0x1CC767
Vspev02SeLift vspev02SeLift; // Address: 0x3C7620
float vspev02LiftAdd; // Address: 0x2E7FF0
// Size: 0x30, DWARF: 0x1CC1D6
Vspev02Gond vspev02Gond1; // Address: 0x3C77B0
// Size: 0x30, DWARF: 0x1CC1D6
Vspev02Gond vspev02Gond2; // Address: 0x3C7780
// Size: 0x30, DWARF: 0x1C8782
Vspev02Gear vspev02Gear[3]; // Address: 0x3C77E0
// Size: 0x10, DWARF: 0x1CC767
Vspev02SeLift vspev02SeWagon; // Address: 0x3C7610
// Size: 0x70, DWARF: 0x1CC2E3
Vspev02WagonMdl* vspev02WagonMdl; // Address: 0x2E7FE8
// Size: 0x10, DWARF: 0x1CC767
Vspev02SeLift vspev02SeYuppie[5]; // Address: 0x3C75C0
// Size: 0x30, DWARF: 0x1C8782
Vspev02Gear vspev02Yuppie[5]; // Address: 0x3C7690
// Size: 0x70, DWARF: 0x1CC2E3
Vspev02WagonMdl* vspev02YuppieMdl; // Address: 0x2E7FE4
signed int vspev02YuppieCnt; // Address: 0x2E7FF8
// Size: 0xA0, DWARF: 0x1CDBE3
VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x30, DWARF: 0x1C8782
Vspev02Gear vspev02Staff[2]; // Address: 0x3C7630
// Size: 0x70, DWARF: 0x1CC2E3
Vspev02WagonMdl* vspev02StaffMdl; // Address: 0x2E7FE0
signed int vspev02SpoutCnt; // Address: 0x2E8020
signed int vspev02CafeCnt; // Address: 0x2E8024
signed int vspev02PipeCnt[2]; // Address: 0x2E8000
signed int vspev02LampCnt[2]; // Address: 0x2E8008
signed int vspev02ChairCnt[2]; // Address: 0x2E8010
signed int vspev02GlassCnt[2]; // Address: 0x2E8018
// Size: 0xC0, DWARF: 0x1CCACB
Info* vspev02SnowSpout2; // Address: 0x2E7FD4
// Size: 0xC0, DWARF: 0x1CCACB
Info* vspev02SnowSpout1; // Address: 0x2E7FD8
// Size: 0xC0, DWARF: 0x1CCACB
Info* vspev02WagonClash; // Address: 0x2E7FD0
// Size: 0x50, DWARF: 0x1CC90B
Vspev02Light vspev02Light[2]; // Address: 0x3C7520
// Size: 0x60, DWARF: 0x1CC539
VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30
// Size: 0xC, DWARF: 0x1CD448
Vspev02Debug vspev02Debug; // Address: 0x0

// spev02.c function declarations ///////////////////////////////////////

signed int spev02Init(Event* event /* 0x30(r29) */);
signed int spev02ResetEvent(Event* event /* 0x20(r29) */);
signed int spev02MainEvent(Event* event /* 0x30(r29) */);
signed int spev02PlayerEvent(Event* event /* 0x20(r29) */);
signed int spev02DrawEvent(Event* event /* 0x20(r29) */);
signed int spev02DrawPlayerEvent();
signed int spev02FinishPlayerEvent(Event* event /* 0x20(r29) */);
void spev02End();
static void spev02ResetObject(Event* event /* 0x20(r29) */);
static void spev02ResetLift();
static void spev02MoveLift(signed int no /* 0x90(r29) */, signed int reset /* 0xA0(r29) */);
static void spev02ResetGond1();
static void spev02MoveGond1();
static void spev02TurnGond1();
static void spev02ResetGond2();
static void spev02MoveGond2();
static void spev02TurnGond2();
static void spev02ResetGear();
static void spev02TurnGear();
static void spev02ResetWagon(Event* event /* 0x10(r29) */);
static void spev02CheckWagon(Event* event /* 0x40(r29) */);
static void spev02MoveWagon(Event* event /* 0x20(r29) */);
static void spev02ResetYuppie(Event* event);
static void spev02MoveYuppie(Event* event /* 0x130(r29) */);
static void spev02ResetStaff(Event* event /* 0x40(r29) */);
static void spev02CheckStaff(Event* event /* 0x80(r29) */);
static void spev02PlayEffect(Event* event /* 0x40(r29) */);
static void spev02SeLift(Event* event /* 0x50(r29) */);
static void spev02ResetLevelGoals();
static void spev02CheckLevelGoals(Event* event /* 0x40(r29) */);
static void spev02ResetGaps();
static void spev02CheckGaps(Event* event /* 0x20(r29) */);
static void spev02CheckAirGaps(Event* event /* 0x30(r29) */);
static void spev02CheckGap_A8(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_A9(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_A10(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_A11(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_A12(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckManualGaps(Event* event /* 0x30(r29) */);
static void spev02CheckGap_M1(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_M2(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGrindGaps(Event* event /* 0x30(r29) */);
static void spev02CheckGap_G1(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G2(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G3(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G4(Character* character, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G5(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G6(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G10(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_G11(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G12(Character* character /* 0x30(r29) */, signed int player /* 0x40(r29) */);
static void spev02CheckGap_G13(Character* character, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G14(Character* character /* 0x10(r29) */, signed int player /* 0x20(r29) */);
static void spev02CheckGap_G16(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_G18(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_G19(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_G21(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_G22(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_G23(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckGap_G24(Character* character, signed int player /* 0x20(r29) */, signed int no /* 0x30(r29) */);
static void spev02CheckLipGaps(Event* event /* 0x20(r29) */);
static void spev02CheckOtherGaps(Event* event /* 0x10(r29) */);
static void spev02InitSnowSpout();
static void spev02ResetSnowSpout();
static void spev02PlayerSnowSpout(Event* event /* 0x80(r29) */);
static void spev02EndSnowSpout();
static void spev02InitWagonClash();
static void spev02ResetWagonClash();
static void spev02PlayerWagonClash(Event* event);
static void spev02EndWagonClash();
static void spev02ResetLight(signed int player /* 0x10(r29) */);
static void spev02CheckWarp(Event* event /* 0x40(r29) */);
static void spev02MatchWarp();
static void spev02CheckDraw(Event* event /* 0x30(r29) */);

void tmevSetHorsePosition(float x, float y, float z, float angle);
void tmevSetStartPosition(float x, float y, float z, float angle, signed int player);
void* spfxGetTexData(void);
unsigned long ultexGetTEX0(void* data);
signed int tmevGetEventMdlHit(Ctrl* rider, signed int no, signed int unused1, float len);
void knEventSetCameraPos(float* pos);
void knEventSetCameraObj(float* obj);
void ktactSetRecover(signed int pid, float* pos, float roty, float speed, signed int warp);
void tmcrsMoveObject(signed int no, float* rot, float* trans, signed int local);
void tmevSetAmbient(float* ambient, signed int player);
void tmevSetLightVector(float* light_color, float* normal_light, signed int id, signed int player);
void akevInitLensFlare(unsigned int type, float* pos, unsigned int backz, unsigned int rgb);
void tmevSetVib(Event* event, signed int type, signed int no, signed int id);

// spev02.c
signed int spev02Init(Event* event) {
    signed int i; // r16
    float tmp[4]; // 0x20(r29)

    vspev02Lift = (Vspev02Lift*)ulMalloc(0x1E0, 0, 0);
    vspev02EventMdl = (Vspev02EventMdl*)ulMalloc(0x380, 0, 0);
    if (event->game.nplayer == 1) {
        tmevSetStartPosition(1.6f, -1013.3f, 1298.3f, 0.031939523f, 0);
    } else {
        tmevSetStartPosition(24.0f, -1011.9f, 1298.1f, 0.013962632f, 0);
        tmevSetStartPosition(-24.0f, -1014.6, 1298.1f, 0.04345869f, 1);
    }
    for (i = 0; i < 12; i++) {
        tmevSetHorsePosition(vspev02HorsePos[i][0], vspev02HorsePos[i][1], vspev02HorsePos[i][2], (vspev02HorsePos[i][3] * 3.141592f) / 180.0f);
    }
    vspev02Smoke = (Vspev02Smoke*)akevInitSmoke(0x32);
    tmp[0] = 1.0f;
    tmp[1] = 0.2f;
    tmp[2] = -1.0f;
    tmp[3] = 1.0f;
    akevInitLensFlare(3, &tmp[0], 0x1100, 0x405060);
    spev02InitSnowSpout();
    spev02InitWagonClash();
    return 0;
}

void tmevSetDrawLength(float length, signed int player);
void tmevSetViewAngle(float view_angle, signed int player);
void akevChangeSnowSplashColor(signed int pn, signed int r, signed int g, signed int b, signed int a);

// spev02.c
signed int spev02ResetEvent(Event* event) {
    signed int i; // r16
    
    for (i = 0; i < event->game.nplayer; i++) {
        tmevSetDrawLength(3600.0f, i);
        tmevSetFog(0, i);
        akevChangeSnowSplashColor(i, 0x80, 0x6E, 0x60, 0x60);
        spev02ResetLight(i);
        vspev02View[i] = -1.0f;
    }
    spev02ResetObject(event);
    spev02ResetWagon(event);
    spev02ResetYuppie(event);
    spev02ResetStaff(event);
    tmcrsResetEventModel(8, vspev02EventMdl);
    spev02ResetLevelGoals();
    spev02ResetGaps();
    vtmevWarp = &spev02MatchWarp;
    akevResetSmoke(vspev02Smoke);
    spev02ResetSnowSpout();
    spev02ResetWagonClash();
    return 0;
}

s32 spev02MainEvent(Event* event) {
    signed int i; // r16
    signed int tmp; // r17

    if (event->game.pause == 0) {
        for (i = 0; i < 0xA; i++) {
            spev02MoveLift(i, 0);
        }
        if (event->game.mode != 0) {
            spev02MoveGond1(event);
            spev02MoveGond2(event);
        }
        spev02TurnGear();
        spev02MoveWagon(event);
        spev02MoveYuppie(event);
        spev02CheckStaff(event);
        akevCalcSmoke(vspev02Smoke);
        spev02SeLift(event);
        if (1 < event->game.nplayer) {
            tmcrsSetHitCollision(0x258, 0, 9);
        }
    }
    if (event->game.mode == 0) {
        tmp = tmevGetIntroCut();
        switch (tmp) {
            case 0: 
                for (i = 0; i < 5; i++) {
                    tmevSetFlag(i + 0x51, 0);
                }
                break;
            default:
                break;
        }  
    }
    return 0;
}

s32 spev02PlayerEvent(Event* event) {
    signed int player = event->game.player; // r16

    if (event->game.pause == 0) {
        spev02CheckLevelGoals(event);
        spev02CheckWarp(event);
        spev02CheckDraw(event);
        spev02CheckGaps(event);
        spev02CheckWagon(event);
        spev02PlayEffect(event);
        spev02PlayerSnowSpout(event);
    }
    return 0;
}

signed int spev02DrawEvent(Event* event) {
    sceVu0FMATRIX* wsmat; // r16
    
    wsmat = (event->character[event->game.player].ctrl->sys_mat->world_screen);
    akevDrawSmoke(vspev02Smoke, vgmsysAbuf, wsmat, event->course.fog);
    return 0;
}

signed int spev02DrawPlayerEvent(Event* event) {
    return 0;
}

signed int spev02FinishPlayerEvent(Event* event) {
    signed int player = event->game.player; // r16
    tmevSetFlag(player + 0x5A, 1);
    return 0;
}

void spev02End() {
    ulFree(vspev02Lift);
    ulFree(vspev02EventMdl);
    akevFreeSmoke(vspev02Smoke);
    spev02EndSnowSpout();
    spev02EndWagonClash();
}

void tmcrsSetObjectAttr(signed int no, signed int attr);
void tmcrsSetObjectBonk(signed int no, float len, signed int bonk);
signed int tmcrsGetObjectPosition(float* position, signed int no);
float atan2f(float a, float b);
float sqrtf(float a);

// spev02.c
static void spev02ResetObject(Event* event) {
    static signed int sp_tbl[22] = {
        0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA,
        0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2,
        0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8
    };
    signed int i;

    tmcrsResetAllObject();
    for (i = 0; i < 0x16; i++) {
        tmevSetSponsor(i, sp_tbl[i]);
    }
    tmevSetCourseLogo(0x5D);
    tmevSetCourseLogo(0x5E);
    tmevSetCourseLogo(0x5F);
    tmevSetCourseLogo(0x60);
    tmevSetWarpArrow(0x64);
    tmevSetWarpArrow(0x65);
    tmevSetWarpArrow(0x66);
    tmevSet1PlayObject(0x63);
    tmevSet1PlayObject(0x9F);
    tmevSet1PlayObject(0x65);
    tmevSet1PlayObject(0x66);
    tmevSet1PlayObject(0x68);
    tmevSet1PlayObject(0x95);
    tmevSet1PlayObject(0x62);
    tmevSetVsObject(0x61);
    tmevSetVsObject(0x6B);
    tmevSetVsObject(0x6C);
    tmevSetVsObject(0x6D);
    tmevSetVsObject(0x6E);
    tmevSetVsObject(0x6F);
    tmevSetVsObject(0x70);
    tmevSetVsObject(0xA0);
    tmevSetVsWarpObject(0x67);
    tmevSetVsWarpObject(0x64);
    tmevSetVsWarpObject(0xA0);
    tmevSetWarpNo(0x20, 0x23);
    tmcrsSetObjectScissorFlag(0x8A, 0x1);
    tmcrsSetObjectScissorFlag(0x88, 0x1);
    tmcrsSetObjectScissorFlag(0x89, 0x1);
    tmcrsSetObjectScissorFlag(0x7F, 0x1);
    tmcrsSetObjectScissorFlag(0x80, 0x1);
    tmcrsSetObjectScissorFlag(0x7E, 0x1);
    tmcrsSetObjectScissorFlag(0x81, 0x1);
    tmcrsSetObjectScissorFlag(0x82, 0x1);
    tmcrsSetObjectScissorFlag(0x83, 0x1);
    tmcrsSetObjectScissorFlag(0x84, 0x1);
    tmcrsSetObjectScissorFlag(0x85, 0x1);
    tmcrsSetObjectScissorFlag(0x86, 0x1);
    tmcrsSetObjectScissorFlag(0x87, 0x1);
    tmcrsSetObjectScissorFlag(0x8B, 0x1);
    tmcrsSetObjectScissorFlag(0x8C, 0x1);
    tmcrsSetObjectScissorFlag(0x8D, 0x1);
    tmcrsSetObjectScissorFlag(0x8E, 0x1);
    tmcrsSetObjectScissorFlag(0x8F, 0x1);
    tmcrsSetObjectScissorFlag(0x90, 0x1);
    tmcrsSetObjectScissorFlag(0x92, 0x1);
    tmcrsSetObjectScissorFlag(0x93, 0x1);
    tmcrsSetObjectScissorFlag(0x94, 0x1);
    tmcrsSetObjectScissorFlag(0x91, 0x1);
    tmcrsSetObjectScissorFlag(0x46, 0x1);
    tmcrsSetObjectScissorFlag(0x47, 0x1);
    tmcrsSetObjectScissorFlag(0x71, 0x1);
    tmcrsSetObjectScissorFlag(0x72, 0x1);
    tmcrsSetObjectScissorFlag(0x62, 0x1);
    tmcrsSetObjectScissorFlag(0x61, 0x1);
    tmcrsSetObjectScissorFlag(0x6B, 0x1);
    tmcrsSetObjectScissorFlag(0x6C, 0x1);
    tmcrsSetObjectScissorFlag(0x6D, 0x1);
    tmcrsSetObjectScissorFlag(0x6E, 0x1);
    tmcrsSetObjectScissorFlag(0x6F, 0x1);
    tmcrsSetObjectScissorFlag(0x70, 0x1);
    tmcrsSetObjectScissorFlag(0x63, 0x1);
    tmcrsSetObjectScissorFlag(0x67, 0x1);
    tmcrsSetObjectScissorFlag(0x9F, 0x1);
    tmcrsSetObjectScissorFlag(0x66, 0x1);
    tmcrsSetObjectScissorFlag(0x6A, 0x1);
    tmcrsSetObjectScissorFlag(0x69, 0x1);
    spev02ResetLift();
    spev02ResetGond1();
    spev02ResetGond2();
    spev02ResetGear();
    if (1 < event->game.nplayer) {
        tmcrsSetRailCollision(0xA2, 0);
        tmcrsSetRailCollision(0x170, 0);
        tmcrsSetObjectAttr(0x61, 0x1);
    }
}

void spev02ResetLift() {
    signed int i; // r16
    signed int j; // r17
    float tmp[4]; // 0x30(r29)
    float len; // 0x48(r29)
    float ang; // 0x4C(r29)

    len = 0.0f;
    for (i = 0; i < 0x20; i++) {
        sceVu0SubVector(&tmp, &vspev02LiftPos[((i + 1)) % 0x20], vspev02LiftPos[i]);
        sceVu0MulVector(&tmp, &tmp, &tmp);
        len += sqrtf(tmp[0] + tmp[1] + tmp[2]);
    }
    vspev02LiftAdd = len / 10800.0f;
    for (i = 0; i < 0xA; i++) {
        vspev02Lift[i].no = i + 0x48;
        vspev02Lift[i].pos = 1;
        vspev02Lift[i].add = (float) vspev02LiftAdd;
        tmcrsGetObjectPosition(tmp, vspev02Lift[i].no);
        sceVu0SubVector(&tmp, &vspev02LiftPos[vspev02Lift[i].pos], &tmp);
        ang = atan2f(tmp[0], tmp[2]);
        vspev02Lift[i].rot[0] = 0.0f;
        vspev02Lift[i].rot[1] = ang;
        vspev02Lift[i].rot[2] = 0.0f;
        vspev02Lift[i].rot[3] = 1.0f;
        vspev02Lift[i].trans[0] = 0.0f;
        vspev02Lift[i].trans[1] = 0.0f;
        vspev02Lift[i].trans[2] = 0.0f;
        vspev02Lift[i].trans[3] = 1.0f;
        tmcrsSetObjectAttr(vspev02Lift[i].no, 1);
        tmcrsSetObjectBonk((&vspev02Lift[i])->no, -40.0f, 1);
    }
    for (i = 0; i < 0xA; i++) {
        for (j = 0; j < (i * 0x438); j++) {
            spev02MoveLift(i, 1);
            tmcrsCalcObjectUnit(vspev02Lift[i].no);
        }
    }
    vspev02SeLift.id = -1;
    vspev02SeLift.vol = 0;
}

void tmcrsSetObjectAttr(signed int no, signed int attr);
void tmcrsSetObjectBonk(signed int no, float len, signed int bonk);
void tmcrsSetObjectBonkLength(signed int no, float len);
float tmcrsGetEventModelFrame(signed int no, signed int id);
void knEventSetShake(float power, float rate);
float atan2f(float a, float b);
float sqrtf(float a);

// spev02.c
static void spev02MoveLift(signed int no, signed int reset) {
    float pos[4];
    float rot[4];
    sceVu0FMATRIX mat;
    float tmp;
    float ang;

    tmcrsGetObjectPosition(pos, vspev02Lift[no].no);
    sceVu0SubVector(pos, vspev02LiftPos[vspev02Lift[no].pos], pos);
    ang = atan2f(pos[0], pos[2]);
    tmp = (ang - vspev02Lift[no].rot[1] < -3.14159203f) ? 6.28318405f + (ang - vspev02Lift[no].rot[1]) : ((ang - vspev02Lift[no].rot[1] > 3.14159203f) ? (ang - vspev02Lift[no].rot[1]) - 6.28318405f : ang - vspev02Lift[no].rot[1]);
    if ((tmp > 1.57079601f) || (tmp < -1.57079601f)) {
        vspev02Lift[no].pos = (vspev02Lift[no].pos + 1) % 0x20;
        tmcrsGetObjectPosition(pos, vspev02Lift[no].no);
        sceVu0SubVector(pos, vspev02LiftPos[vspev02Lift[no].pos], pos);
        ang = atan2f(pos[0], pos[2]);
        tmp = (ang - vspev02Lift[no].rot[1] < -3.14159203f) ? 6.28318405f + (ang - vspev02Lift[no].rot[1]) : ((ang - vspev02Lift[no].rot[1] > 3.14159203f) ? (ang - vspev02Lift[no].rot[1]) - 6.28318405f : ang - vspev02Lift[no].rot[1]);
    }
    if (tmp > 0.0149999997f) {
        tmp = 0.0149999997f;
    } else if (tmp < -0.0149999997f) {
        tmp = -0.0149999997f;
    } else {
        tmp = 0;
    }
    rot[0] = 0;
    rot[1] = tmp;
    rot[2] = 0;
    rot[3] = 1.0f;
    vspev02Lift[no].rot[1] = (tmp + vspev02Lift[no].rot[1] < -3.14159203f) ? 6.28318405f + (tmp + vspev02Lift[no].rot[1]) : ((tmp + vspev02Lift[no].rot[1] > 3.14159203f) ? (tmp + vspev02Lift[no].rot[1]) - 6.28318405f : tmp + vspev02Lift[no].rot[1]);
    tmp = sqrtf(pos[0] * pos[0] + pos[2] * pos[2]);
    ang = -atan2f(pos[1], tmp);
    vspev02Lift[no].rot[0] = ang;
    if (reset == 1) {
        vspev02Lift[no].add = vspev02LiftAdd;
    } else if ((0x17 < vspev02Lift[no].pos) || (vspev02Lift[no].pos < 2)) {
        vspev02Lift[no].add = vspev02LiftAdd / 5.0f;
    } else {
        vspev02Lift[no].add = vspev02LiftAdd;
    }
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = vspev02Lift[no].add;
    pos[3] = 1.0f;
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixX(mat, mat, vspev02Lift[no].rot[0]);
    sceVu0RotMatrixY(mat, mat, vspev02Lift[no].rot[1]);
    sceVu0ApplyMatrix(pos, mat, pos);
    tmcrsMoveObject(vspev02Lift[no].no, rot, pos, 0);
}

void spev02ResetGond1() {
    signed int i; // r16
    float tmp[4]; // 0x20(r29)
    float len; // 0x38(r29)
    float ang; // 0x3C(r29)

    len = 0.0f;
    for (i = 0; i < 7; i++) {
        sceVu0SubVector(&tmp, &vspev02Gond1Pos[(i + 1) % 7], &vspev02Gond1Pos[i]);
        sceVu0MulVector(&tmp, &tmp, &tmp);
        len += sqrtf(tmp[0] + tmp[1] + tmp[2]);
    }
    vspev02Gond1.no = 0x46;
    vspev02Gond1.pos = 1;
    vspev02Gond1.state = 0.0f;
    vspev02Gond1.add = len / 7200.0f;
    tmcrsGetObjectPosition(&tmp, vspev02Gond1.no);
    sceVu0SubVector(&tmp, &vspev02Gond1Pos[vspev02Gond1.pos], &tmp);
    ang = atan2f(tmp[0], tmp[2]);
    vspev02Gond1.rot[0] = 0.0f;
    vspev02Gond1.rot[1] = ang;
    vspev02Gond1.rot[2] = 0.0f;
    vspev02Gond1.rot[3] = 1.0f;
    vspev02Gond1.trans[0] = 0.0f;
    vspev02Gond1.trans[1] = 0.0f;
    vspev02Gond1.trans[2] = 0.0f;
    vspev02Gond1.trans[3] = 1.0f;
    tmcrsSetObjectAttr(vspev02Gond1.no, 1);
    tmcrsSetObjectBonk(vspev02Gond1.no, -40.0f, 1);
    tmcrsSetObjectBonkLength(vspev02Gond1.no, 30.0f);
}

void sceVu0RotMatrixX(sceVu0FMATRIX a, sceVu0FMATRIX b, float x);
void sceVu0RotMatrixY(sceVu0FMATRIX a, sceVu0FMATRIX b, float y);
float atan2f(float a, float b);
float sqrtf(float a);

// spev02.c
void spev02MoveGond1(s32 unused) {
    float tmp[4]; // 0x10(r29)
    float pos[4]; // 0x20(r29)
    sceVu0FVECTOR rot; // 0x30(r29)
    sceVu0FVECTOR trans; // 0x40(r29)
    sceVu0FMATRIX mat; // 0x50(r29)
    float ang; // 0x9C(r29)

    tmcrsGetObjectPosition(&pos, vspev02Gond1.no);
    switch (vspev02Gond1.state) {
    case 0:
        sceVu0SubVector(&tmp, &vspev02Gond1Pos[vspev02Gond1.pos], &pos);
        ang = atan2f(tmp[0], tmp[2]);
        ang = (ang - (float) vspev02Gond1.rot[1]) < -3.141592f
            ? 6.283184f + (ang - (float) vspev02Gond1.rot[1])
            : ((ang - (float) vspev02Gond1.rot[1]) > 3.141592f)
            ? (ang - (float) vspev02Gond1.rot[1]) - 6.283184f
            : ang - (float) vspev02Gond1.rot[1];
        if ((ang > 1.570796f) || (ang < -1.570796f)) {
            vspev02Gond1.pos++;
            if (vspev02Gond1.pos == 7) {
                spev02TurnGond1();
                tmevStartICounter(0x3E);
                vspev02Gond1.state = 1;
                return;
            }
        }
        if (ang > 0.015f) {
            ang = 0.015f;
        } else if (ang < -0.015f) {
            ang = -0.015f;
        }
        rot[0] = 0.0f;
        rot[1] = ang;
        rot[2] = 0.0f;
        rot[3] = 1.0f;
        vspev02Gond1.rot[1] = ((float) vspev02Gond1.rot[1] + ang) < -3.141592f
            ? 6.283184f + ((float) vspev02Gond1.rot[1] + ang)
            : (((float) vspev02Gond1.rot[1] + ang) > 3.141592f)
            ? ((float) vspev02Gond1.rot[1] + ang) - 6.283184f
            : (float) vspev02Gond1.rot[1] + ang;
        ang = sqrtf((tmp[0] * tmp[0]) + (tmp[2] * tmp[2]));
        vspev02Gond1.rot[0] = -atan2f(tmp[1], ang);
        tmp[0] = 0.0f;
        tmp[1] = 0.0f;
        tmp[2] = vspev02Gond1.add;
        tmp[3] = 1.0f;
        sceVu0UnitMatrix(mat);
        sceVu0RotMatrixX(mat, mat, vspev02Gond1.rot[0]);
        sceVu0RotMatrixY(mat, mat, vspev02Gond1.rot[1]);
        sceVu0ApplyMatrix(&trans[0], mat, tmp);
        tmcrsMoveObject(vspev02Gond1.no, &rot, &trans[0], 0);
        return;
    case 2:
        sceVu0SubVector(&tmp, &vspev02Gond1Pos[vspev02Gond1.pos], &pos);
        ang = atan2f(tmp[0], tmp[2]);
        ang = (ang - (float) vspev02Gond1.rot[1]) < -3.141592f
            ? 6.283184f + (ang - (float) vspev02Gond1.rot[1])
            : ((ang - (float) vspev02Gond1.rot[1]) > 3.141592f)
            ? (ang - (float) vspev02Gond1.rot[1]) - 6.283184f
            : ang - (float) vspev02Gond1.rot[1];
        if ((ang > 1.570796f) || (ang < -1.570796f)) {
            vspev02Gond1.pos = vspev02Gond1.pos - 1;
            if (vspev02Gond1.pos < 0) {
                spev02TurnGond1();
                tmevStartICounter(0x3E);
                vspev02Gond1.state = 3;
                return;
            }
        }
        if (ang > 0.015f) {
            ang = 0.015f;
        } else if (ang < -0.015f) {
            ang = -0.015f;
        }
        rot[0] = 0.0f;
        rot[1] = ang;
        rot[2] = 0.0f;
        rot[3] = 1.0f;
        vspev02Gond1.rot[1] = ((float) vspev02Gond1.rot[1] + ang) < -3.141592f
            ? 6.283184f + ((float) vspev02Gond1.rot[1] + ang)
            : (((float) vspev02Gond1.rot[1] + ang) > 3.141592f)
            ? ((float) vspev02Gond1.rot[1] + ang) - 6.283184f
            : (float) vspev02Gond1.rot[1] + ang;
        ang = sqrtf(tmp[0] * tmp[0] + tmp[2] * tmp[2]);
        vspev02Gond1.rot[0] = -atan2f(tmp[1], ang);
        tmp[0] = 0.0f;
        tmp[1] = 0.0f;
        tmp[2] = vspev02Gond1.add;
        tmp[3] = 1.0f;
        sceVu0UnitMatrix(mat);
        sceVu0RotMatrixX(mat, mat, vspev02Gond1.rot[0]);
        sceVu0RotMatrixY(mat, mat, vspev02Gond1.rot[1]);
        sceVu0ApplyMatrix(&trans[0], &mat, &tmp);
        tmcrsMoveObject(vspev02Gond1.no, &rot, &trans[0], 0);
        return;
    default:
        trans[0] = 0.0f;
        trans[1] = 0.0f;
        trans[2] = 0.0f;
        trans[3] = 1.0f;
        if (tmevGetICounter(0x3E) == 0x12C) {
            if (vspev02Gond1.state == 1) {
                vspev02Gond1.state = 2;
            } else {
                vspev02Gond1.state = 0;
            }
            tmevStopICounter(0x3E);
            tmevResetICounter(0x3E);
        }
        return;
    }
}

void tmcrsResetObject(signed int no);
float atan2f(float a, float b);

// spev02.c
void spev02TurnGond1(void) {
    float tmp[4]; // 0x10(r29)
    float ang; // 0x2C(r29)

    if (vspev02Gond1.state == 0) {
        vspev02Gond1.pos = 5;
    } else {
        tmcrsResetObject(vspev02Gond1.no);
        vspev02Gond1.pos = 1;
    }
    tmcrsGetObjectPosition(&tmp, vspev02Gond1.no);
    sceVu0SubVector(&tmp, &vspev02Gond1Pos[vspev02Gond1.pos], &tmp);
    ang = atan2f(tmp[0], tmp[2]);
    vspev02Gond1.rot[0] = 0;
    vspev02Gond1.rot[1] = ang;
    vspev02Gond1.rot[2] = 0;
    vspev02Gond1.rot[3] = 1.0f;
    vspev02Gond1.trans[0] = 0;
    vspev02Gond1.trans[1] = 0;
    vspev02Gond1.trans[2] = 0;
    vspev02Gond1.trans[3] = 1.0f;
}

void tmcrsSetObjectBonk(signed int no, float len, signed int bonk);
signed int tmcrsGetObjectPosition(float* position, signed int no);
void tmcrsSetObjectBonkLength(signed int no, float len);
void tmcrsSetObjectAttr(signed int no, signed int attr);
float atan2f(float a, float b);
float sqrtf(float a);

// spev02.c
void spev02ResetGond2() {
    signed int i; // r16
    float tmp[4]; // 0x20(r29)
    float len; // 0x38(r29)
    float ang; // 0x3C(r29)

    len = 0.0f;
    for (i = 0; i < 7; i++) {
        sceVu0SubVector(&tmp, &vspev02Gond2Pos[(i + 1) % 7], &vspev02Gond2Pos[i]);
        sceVu0MulVector(&tmp, &tmp, &tmp);
        len += sqrtf(tmp[0] + tmp[1] + tmp[2]);
    }
    vspev02Gond2.no = 0x47;
    vspev02Gond2.pos = 0x1;
    vspev02Gond2.state = 0.0f;
    vspev02Gond2.add = len / 7200.0f;
    tmcrsGetObjectPosition(tmp, vspev02Gond2.no);
    sceVu0SubVector(&tmp, vspev02Gond2Pos[vspev02Gond2.pos], &tmp);
    ang = atan2f(tmp[0], tmp[2]);
    vspev02Gond2.rot[0] = 0.0f;
    vspev02Gond2.rot[1] = ang;
    vspev02Gond2.rot[2] = 0.0f;
    vspev02Gond2.rot[3] = 1.0f;
    vspev02Gond2.trans[0] = 0.0f;
    vspev02Gond2.trans[1] = 0.0f;
    vspev02Gond2.trans[2] = 0.0f;
    vspev02Gond2.trans[3] = 1.0f;
    tmcrsSetObjectAttr(vspev02Gond2.no, 1);
    tmcrsSetObjectBonk(vspev02Gond2.no, -40.0f, 1);
    tmcrsSetObjectBonkLength(vspev02Gond2.no, 30.0f);
}

static void spev02MoveGond2();
static void spev02TurnGond2();
static void spev02ResetGond2();
void spev02MoveGond2(s32 unused) {
    float tmp[4]; // 0x10(r29)
    float pos[4]; // 0x20(r29)
    sceVu0FVECTOR trans; // 0x30(r29)
    sceVu0FVECTOR rot; // 0x40(r29)
    sceVu0FMATRIX mat; // 0x50(r29)
    float ang; // 0x9C(r29)

    tmcrsGetObjectPosition(&pos, vspev02Gond2.no);
    switch (vspev02Gond2.state) {
    case 0:
        sceVu0SubVector(&tmp, &vspev02Gond2Pos[vspev02Gond2.pos], &pos);
        ang = atan2f(tmp[0], tmp[2]);
        ang = (ang - (float) vspev02Gond2.rot[1]) < -3.141592f
            ? 6.283184f + (ang - (float) vspev02Gond2.rot[1])
            : ((ang - (float) vspev02Gond2.rot[1]) > 3.141592f)
            ? (ang - (float) vspev02Gond2.rot[1]) - 6.283184f
            : ang - (float) vspev02Gond2.rot[1];
        if ((ang > 1.570796f) || (ang < -1.570796f)) {
            vspev02Gond2.pos++;
            if (vspev02Gond2.pos == 7) {
                spev02TurnGond2();
                tmevStartICounter(0x3F);
                vspev02Gond2.state = 1;
                return;
            }
        }
        if (ang > 0.015f) {
            ang = 0.015f;
        } else if (ang < -0.015f) {
            ang = -0.015f;
        }
        rot[0] = 0.0f;
        rot[1] = ang;
        rot[2] = 0.0f;
        rot[3] = 1.0f;
        vspev02Gond2.rot[1] = ((float) vspev02Gond2.rot[1] + ang) < -3.141592f
            ? 6.283184f + ((float) vspev02Gond2.rot[1] + ang)
            : (((float) vspev02Gond2.rot[1] + ang) > 3.141592f)
            ? ((float) vspev02Gond2.rot[1] + ang) - 6.283184f
            : (float) vspev02Gond2.rot[1] + ang;
        ang = sqrtf((tmp[0] * tmp[0]) + (tmp[2] * tmp[2]));
        vspev02Gond2.rot[0] = -atan2f(tmp[1], ang);
        tmp[0] = 0.0f;
        tmp[1] = 0.0f;
        tmp[2] = vspev02Gond2.add;
        tmp[3] = 1.0f;
        sceVu0UnitMatrix(mat);
        sceVu0RotMatrixX(mat, mat, vspev02Gond2.rot[0]);
        sceVu0RotMatrixY(mat, mat, vspev02Gond2.rot[1]);
        sceVu0ApplyMatrix(&trans[0], mat, tmp);
        tmcrsMoveObject(vspev02Gond2.no, &rot, &trans[0], 0);
        return;
    case 2:
        sceVu0SubVector(&tmp, &vspev02Gond2Pos[vspev02Gond2.pos], &pos);
        ang = atan2f(tmp[0], tmp[2]);
        ang = (ang - (float) vspev02Gond2.rot[1]) < -3.141592f
            ? 6.283184f + (ang - (float) vspev02Gond2.rot[1])
            : ((ang - (float) vspev02Gond2.rot[1]) > 3.141592f)
            ? (ang - (float) vspev02Gond2.rot[1]) - 6.283184f
            : ang - (float) vspev02Gond2.rot[1];
        if ((ang > 1.570796f) || (ang < -1.570796f)) {
            vspev02Gond2.pos = vspev02Gond2.pos - 1;
            if (vspev02Gond2.pos < 0) {
                spev02TurnGond2();
                tmevStartICounter(0x3F);
                vspev02Gond2.state = 3;
                return;
            }
        }
        if (ang > 0.015f) {
            ang = 0.015f;
        } else if (ang < -0.015f) {
            ang = -0.015f;
        }
        rot[0] = 0.0f;
        rot[1] = ang;
        rot[2] = 0.0f;
        rot[3] = 1.0f;
        vspev02Gond2.rot[1] = ((float) vspev02Gond2.rot[1] + ang) < -3.141592f
            ? 6.283184f + ((float) vspev02Gond2.rot[1] + ang)
            : (((float) vspev02Gond2.rot[1] + ang) > 3.141592f)
            ? ((float) vspev02Gond2.rot[1] + ang) - 6.283184f
            : (float) vspev02Gond2.rot[1] + ang;
        ang = sqrtf(tmp[0] * tmp[0] + tmp[2] * tmp[2]);
        vspev02Gond2.rot[0] = -atan2f(tmp[1], ang);
        tmp[0] = 0.0f;
        tmp[1] = 0.0f;
        tmp[2] = vspev02Gond2.add;
        tmp[3] = 1.0f;
        sceVu0UnitMatrix(mat);
        sceVu0RotMatrixX(mat, mat, vspev02Gond2.rot[0]);
        sceVu0RotMatrixY(mat, mat, vspev02Gond2.rot[1]);
        sceVu0ApplyMatrix(&trans[0], &mat, &tmp);
        tmcrsMoveObject(vspev02Gond2.no, &rot, &trans[0], 0);
        return;
    default:
        trans[0] = 0.0f;
        trans[1] = 0.0f;
        trans[2] = 0.0f;
        trans[3] = 1.0f;
        if (tmevGetICounter(0x3F) == 0x12C) {
            if (vspev02Gond2.state == 1) {
                vspev02Gond2.state = 2;
            } else {
                vspev02Gond2.state = 0;
            }
            tmevStopICounter(0x3F);
            tmevResetICounter(0x3F);
        }
        return;
    }
}

static void spev02TurnGond2(void) {
    float tmp[4]; // 0x10(r29)
    float ang; // 0x2C(r29)

    if (vspev02Gond2.state == 0) {
        vspev02Gond2.pos = 5;
    } else {
        tmcrsResetObject(vspev02Gond2.no);
        vspev02Gond2.pos = 1;
    }
    tmcrsGetObjectPosition(&tmp, vspev02Gond2.no);
    sceVu0SubVector(&tmp, &vspev02Gond2Pos[vspev02Gond2.pos], &tmp);
    ang = atan2f(tmp[0], tmp[2]);
    vspev02Gond2.rot[0] = 0;
    vspev02Gond2.rot[1] = ang;
    vspev02Gond2.rot[2] = 0;
    vspev02Gond2.rot[3] = 1.0f;
    vspev02Gond2.trans[0] = 0;
    vspev02Gond2.trans[1] = 0;
    vspev02Gond2.trans[2] = 0;
    vspev02Gond2.trans[3] = 1.0f;
}

static void spev02ResetGear() {
    signed int ii;

    for (ii = 0; ii < 2; ii++) {
        vspev02Gear[ii].no = ii + 0x71;
        vspev02Gear[ii].rot[0] = 0;
        vspev02Gear[ii].rot[1] = 0.01f;
        vspev02Gear[ii].rot[2] = 0;
        vspev02Gear[ii].rot[3] = 1.0f;
        vspev02Gear[ii].trans[0] = 0;
        vspev02Gear[ii].trans[1] = 0;
        vspev02Gear[ii].trans[2] = 0;
        vspev02Gear[ii].trans[3] = 1.0f;
    }
}

static void spev02TurnGear() {
    signed int ii;

    for (ii = 0; ii < 2; ii++) {
        tmcrsMoveObject(vspev02Gear[ii].no, vspev02Gear[ii].rot, vspev02Gear[ii].trans, 0);
    }
}

static void spev02ResetWagon(Event* event) {
    vspev02WagonMdl = (Vspev02WagonMdl*)vspev02EventMdl;
    vspev02WagonMdl->no = 0;
    vspev02WagonMdl->id = 2;
    vspev02WagonMdl->frame = 0;
    vspev02WagonMdl->draw = 0;
    vspev02WagonMdl->light = 0;
    sceVu0UnitMatrix(vspev02WagonMdl->matrix);
    if (event->game.nplayer == 1) {
        tmcrsSetObjectDrawFlag(0x6A, 1);
        tmcrsSetObjectAttr(0x6A, 1);
        tmcrsSetObjectBonk(0x6A, 35.0f, 1);
        tmcrsSetObjectBonkLength(0x6A, 30.0f);
        tmcrsSetObjectDrawFlag(0x69, 0);
        tmcrsSetRailCollision(0x1C5, 0);
        tmcrsSetRailCollision(0x1C4, 0);
        tmcrsSetObjectAttr(0x69, 1);
        tmcrsSetObjectBonk(0x69, 35.0f, 1);
        tmcrsSetObjectBonkLength(0x69, 30.0f);
    } else {
        tmcrsSetObjectDrawFlag(0x6A, 0);
        tmcrsSetRailCollision(0x1B4, 0);
        tmcrsSetRailCollision(0x1B5, 0);
        tmcrsSetObjectDrawFlag(0x69, 1);
        tmcrsSetObjectBonk(0x69, 35.0f, 1);
        tmcrsSetObjectBonkLength(0x69, 30.0f);
    }
    vspev02SeWagon.id = -1;
    vspev02SeWagon.vol = 0;
}

static void spev02CheckWagon(Event* event) {
    float tmp[4];
    signed int player;
    signed int ii;

    if (event->game.nplayer == 1) {
        player = event->game.player;
        switch (tmevGetFlag(0x45)) {
        case 0:
            for (ii = 0; ii < event->character[player].nhit; ii++) {
                if (event->character[player].hit[ii].no >= 0x64) {
                    if (event->character[player].ctrl->act.trg_bonk == 1) {
                        if (event->character[player].hit[ii].no == 0x19B) {
                            if (tmevGetFlag(0x45) == 0) {
                                spEnterEventCameraMode();
                                knEventStart();
                                tmp[0] = 579.69f;
                                tmp[1] = 2050.33f;
                                tmp[2] = -4931.75f;
                                tmp[3] = 1.0f;
                                knEventSetCameraPos(tmp);
                                tmp[0] = 542.43f;
                                tmp[1] = 2073.89f;
                                tmp[2] = -4955.35f;
                                tmp[3] = 1.0f;
                                knEventSetCameraObj(tmp);
                                tmevSetFlag(0x45, 1);
                                tmevStartICounter(0x3C);
                                tmcrsSetObjectDrawFlag(0x6A, 0);
                                vspev02WagonMdl->draw = 1;
                                tmcrsSetRailCollision(0x1B4, 0);
                                tmcrsSetRailCollision(0x1B5, 0);
                                tmcrsSetRailCollision(0x1C5, 1);
                                tmcrsSetRailCollision(0x1C4, 1);
                                nmeventPlay2(player, 5);
                                tmevSetVib(event, 1, 1, 6);
                            }
                        }
                    }
                }
            }
            break;
        case 1:
            tmevGetEventMdlHit(event->character[player].ctrl, 0, 1, 50.0f);
            break;
        }
    }
}

static void spev02MoveWagon(Event* event) {
    signed int player;

    if (event->game.nplayer == 1) {
        player = event->game.player;
        switch (tmevGetFlag(0x45)) {
        case 0:
            tmcrsSetHitCollision(0x19A, 0, 7);
            tmcrsSetHitCollision(0x19B, 0x19B, 0xC007);
            break;
        case 1:
            vspev02WagonMdl->frame = tmevGetICounter(0x3C) * 80.0f;
            if (vspev02WagonMdl->frame == tmcrsGetEventModelFrame(vspev02WagonMdl->no, vspev02WagonMdl->id)) {
                spExitEventCameraMode();
                knEventEnd();
                tmevSetFlag(0x45, 2);
                tmevStopICounter(0x3C);
                tmevResetICounter(0x3C);
                tmcrsSetObjectDrawFlag(0x69, 1);
                vspev02WagonMdl->draw = 0;
            } else if (tmevGetICounter(0x3C) == 0xAC) {
                tmevSetFlag(0x46, 1);
                tmevStartICounter(0x3D);
                knEventSetShake(3.0f, 0.5f);
                nmeventPlay2(player, 6);
                tmevSetVib(event, 1, 0, 6);
            }
            break;
        case 2:
            tmcrsSetHitCollision(0x19C, 0, 7);
            tmcrsSetHitCollision(0x19D, 0x19D, 0xC007);
            break;
        }
        spev02PlayerWagonClash(event);
    } else {
        tmcrsSetHitCollision(0x19C, 0, 7);
        tmcrsSetHitCollision(0x19D, 0x19D, 0xC007);
    }
}

static void spev02ResetYuppie(Event* event) {
    signed int mdl_no[5] = {
        1, 1, 2, 2, 2
    };
    s32* mdl_no_ptr = &mdl_no;
    signed int anim_no[5] = {
        5, 5, 7, 7, 7
    };
    s32* anim_no_ptr = &anim_no;
    signed int sprt_tbl[5] = {
        0x9A, 0x99, 0x96, 0x97, 0x98
    };
    s32* sprt_tbl_ptr = &sprt_tbl;
    signed int i;

    vspev02YuppieMdl = (Vspev02WagonMdl*)&vspev02EventMdl[1];
    for (i = 0; i < 5; i++) {
        tmcrsGetObjectPosition(vspev02Yuppie[i].trans, sprt_tbl[i]);
        vspev02Yuppie[i].trans[1] += 10.0f;
        vspev02Yuppie[i].rot[0] = 0;
        vspev02Yuppie[i].rot[1] = 0;
        vspev02Yuppie[i].rot[2] = 0;
        vspev02Yuppie[i].rot[3] = 1.0f;
        vspev02Yuppie[i].cnt = 0;
        vspev02Yuppie[i].flag = 0;
        vspev02Yuppie[i].tmp = 0;
        vspev02Yuppie[i].no = i + 1;
        vspev02YuppieMdl[i].no = mdl_no[i];
        vspev02YuppieMdl[i].id = anim_no[i];
        vspev02YuppieMdl[i].old_id = anim_no[i];
        vspev02YuppieMdl[i].frame = 0;
        vspev02YuppieMdl[i].draw = 0;
        vspev02YuppieMdl[i].light = 1;
        sceVu0UnitMatrix(vspev02YuppieMdl[i].matrix);
        sceVu0UnitMatrix(vspev02YuppieMdl[i].matrix);
        sceVu0RotMatrixY(vspev02YuppieMdl[i].matrix, vspev02YuppieMdl[i].matrix, vspev02Yuppie[i].tmp);
        sceVu0TransMatrix(vspev02YuppieMdl[i].matrix, vspev02YuppieMdl[i].matrix, vspev02Yuppie[i].trans);
        tmcrsSetObjectDrawFlag(sprt_tbl[i], 1);
        tmevSetFlag(i + 0x47, 0);
        tmevSetFlag(i + 0x51, 0);
        tmevStopICounter(i + 6);
        tmevResetICounter(i + 6);
        vspev02SeYuppie[i].id = -1;
        vspev02SeYuppie[i].vol = 0;
        vspev02SeYuppie[i].num = 0;
    }
}

static void spev02MoveYuppie(Event* event) {
    float tmp[4];
    signed int anim_no[5] = {
        6, 6, 8, 8, 8
    };
    s32* anim_no_ptr = &anim_no;
    signed int vc_no[5][2] = {
        { 0xB, 0x10 }, { 0xB, 0x10 }, { 0x15, 0x1A }, { 0x15, 0x1A }, { 0x15, 0x1A }
    };
    s32* vc_no_ptr = &vc_no;
    signed int sprt_tbl[5] = {
        0x9A, 0x99, 0x96, 0x97, 0x98
    };
    s32* sprt_tbl_ptr = &sprt_tbl;
    signed int hit_no[5] = {
        0x321, 0x322, 0x323, 0x324, 0x325
    };
    s32* hit_no_ptr = &hit_no;
    float len;
    signed int i;
    signed int j;
    signed int player;
    signed int search_vc;

    for (i = 0; i < 5; i++) {
        len = 160000.0f;
        player = -1;
        if ((vspenvGame->mode.game_mode == 1) && (vspenvGame->mode.match_rule == 3)) {
            sceVu0SubVector(tmp, vspev02Yuppie[i].trans, event->character[event->game.player].ctrl->sys_mat->cam_trans);
            sceVu0MulVector(tmp, tmp, tmp);
            if (tmp[0] + tmp[1] + tmp[2] < len) {
                len = tmp[0] + tmp[1] + tmp[2];
                player = event->game.player;
            }
        } else {
            for (j = 0; j < event->game.nplayer; j++) {
                sceVu0SubVector(tmp, vspev02Yuppie[i].trans, event->character[j].ctrl->sys_mat->cam_trans);
                sceVu0MulVector(tmp, tmp, tmp);
                if (tmp[0] + tmp[1] + tmp[2] < len) {
                    len = tmp[0] + tmp[1] + tmp[2];
                    player = j;
                }
            }
        }
        if (vspev02SeYuppie[i].id >= 0) {
            if (nmvcGetState(vspev02SeYuppie[i].id) == 1) {
                vspev02SeYuppie[i].id = -1;
            }
        } else {
            if (tmevGetFlag(i + 0x51) == 0) {
                if (len < 22500.0f) {
                    if (tmevGetFlag(player + 0x5A) == 0) {
                        do {
                            search_vc = tmevGetICounter(0) % 5;
                        } while (vspev02SeYuppie[i].num == search_vc + vc_no[i][0]);
                        if (event->game.mode == 0) {
                            vspev02SeYuppie[i].id = nmeventPlay2(player, search_vc + vc_no[i][0]);
                        } else {
                            vspev02SeYuppie[i].id = nmeventPlay(player, search_vc + vc_no[i][0]);
                        }
                        tmevSetFlag(i + 0x51, 1);
                    }
                }
            }
        }
        switch (tmevGetFlag(i + 0x47)) {
        case 0:
            if (len < 160000.0f) {
                tmevSetFlag(i + 0x47, 1);
                tmevStartICounter(i + 6);
                tmcrsSetObjectDrawFlag(sprt_tbl[i], 0);
                vspev02YuppieMdl[i].draw = 1;
            }
            break;
        case 1:
            if (len < 160000.0f) {
                vspev02YuppieMdl[i].frame = tmevGetICounter(i + 6) * 80.0f;
                if (vspev02YuppieMdl[i].frame == tmcrsGetEventModelFrame(vspev02YuppieMdl[i].no, vspev02YuppieMdl[i].id)) {
                    if (tmevGetFlag(player + 0x5A) == 0) {
                        if (vspev02SeYuppie[i].id < 0) {
                            if (len < 22500.0f) {
                                if (tmevGetICounter(0) % 2 != 0) {
                                    search_vc = tmevGetICounter(0) % 5;
                                    if (vspev02SeYuppie[i].num == search_vc + vc_no[i][0]) {
                                        search_vc = (search_vc + 1) % 5;
                                    }
                                    vspev02SeYuppie[i].id = nmeventPlay(player, search_vc + vc_no[i][0]);
                                    vspev02SeYuppie[i].num = search_vc + vc_no[i][0];
                                }
                            }
                        }
                    }
                    tmevResetICounter(i + 6);
                }
                sceVu0SubVector(tmp, vspev02Yuppie[i].trans, event->character[player].ctrl->nowpos.pos);
                vspev02Yuppie[i].tmp = atan2f(tmp[0], tmp[2]);
                sceVu0UnitMatrix(vspev02YuppieMdl[i].matrix);
                sceVu0UnitMatrix(vspev02YuppieMdl[i].matrix);
                sceVu0RotMatrixY(vspev02YuppieMdl[i].matrix, vspev02YuppieMdl[i].matrix, vspev02Yuppie[i].tmp);
                sceVu0TransMatrix(vspev02YuppieMdl[i].matrix, vspev02YuppieMdl[i].matrix, vspev02Yuppie[i].trans);
                if (tmevGetEventMdlHit(event->character[player].ctrl, vspev02Yuppie[i].no, 0, 10.0f) == 1) {
                    search_vc = tmevGetICounter(0) % 5;
                    if (vspev02SeYuppie[i].id < 0) {
                        nmeventPlay(player, search_vc + vc_no[i][1]);
                    } else {
                        nmvcPlay(vspev02SeYuppie[i].id, 4, search_vc + vc_no[i][1]);
                    }
                    tmevSetVib(event, 0, 5, 7);
                    tmevSetFlag(i + 0x47, 2);
                    tmevResetICounter(i + 6);
                    vspev02YuppieMdl[i].frame = 0;
                    vspev02YuppieMdl[i].id = anim_no[i];
                }
            } else {
                tmevSetFlag(i + 0x47, 0);
                tmevStopICounter(i + 6);
                tmevResetICounter(i + 6);
                tmcrsSetObjectDrawFlag(sprt_tbl[i], 1);
                vspev02YuppieMdl[i].draw = 0;
            }
            break;
        case 2:
            if (len < 160000.0f) {
                vspev02YuppieMdl[i].frame = tmevGetICounter(i + 6) * 80.0f;
                if (vspev02YuppieMdl[i].frame == tmcrsGetEventModelFrame(vspev02YuppieMdl[i].no, vspev02YuppieMdl[i].id)) {
                    tmevStopICounter(i + 6);
                }
            } else {
                tmevSetFlag(i + 0x47, 3);
                tmevStopICounter(i + 6);
                tmevResetICounter(i + 6);
                vspev02YuppieMdl[i].draw = 0;
            }
            break;
        }
        if (event->game.mode == 1) {
            if (event->game.nplayer == 1) {
                player = event->game.player;
                switch (tmevGetFlag(i + 0x4C)) {
                case 0:
                    for (j = 0; j < event->character[player].nhit; j++) {
                        if (event->character[player].hit[j].no >= 0x64) {
                            if (event->character[player].hit[j].no == hit_no[i]) {
                                if (tmevGetFlag(i + 0x47) < 2) {
                                    tmevSetFlag(i + 0x4C, 1);
                                    vspev02YuppieCnt++;
                                    if (vspev02YuppieCnt == 5) {
                                        tmevSetLevelGoal(player, 8);
                                    } else {
                                        nmdispInputLevelCount(vspev02YuppieCnt, 5, 8);
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}

static void spev02ResetStaff(Event* event) {
    signed int sprt_tbl[2] = {
        0xA1, 0xA2
    };
    s32* sprt_tbl_ptr = &sprt_tbl;
    signed int i;

    vspev02StaffMdl = (Vspev02WagonMdl*)&vspev02EventMdl[6];
    for (i = 0; i < 2; i++) {
        tmcrsGetObjectPosition(vspev02Staff[i].trans, sprt_tbl[i]);
        vspev02Staff[i].trans[1] += 10.0f;
        vspev02Staff[i].rot[0] = 0;
        vspev02Staff[i].rot[1] = 0;
        vspev02Staff[i].rot[2] = 0;
        vspev02Staff[i].rot[3] = 1.0f;
        vspev02Staff[i].cnt = 0;
        vspev02Staff[i].flag = 0;
        vspev02Staff[i].tmp = 0;
        vspev02Staff[i].no = i + 6;
        vspev02StaffMdl[i].no = 3;
        vspev02StaffMdl[i].id = 4;
        vspev02StaffMdl[i].frame = 0;
        vspev02StaffMdl[i].draw = 0;
        vspev02StaffMdl[i].light = 1;
        sceVu0UnitMatrix(vspev02StaffMdl[i].matrix);
        sceVu0UnitMatrix(vspev02StaffMdl[i].matrix);
        sceVu0RotMatrixY(vspev02StaffMdl[i].matrix, vspev02StaffMdl[i].matrix, vspev02Staff[i].tmp);
        sceVu0TransMatrix(vspev02StaffMdl[i].matrix, vspev02StaffMdl[i].matrix, vspev02Staff[i].trans);
        if ((event->game.nplayer == 1) || ((vspenvGame->mode.game_mode == 1) && (vspenvGame->mode.match_rule == 3))) {
            tmcrsSetObjectDrawFlag(sprt_tbl[i], 1);
        } else {
            tmcrsSetObjectDrawFlag(sprt_tbl[i], 0);
        }
        tmevSetFlag(i + 0x56, 0);
    }
}

static void spev02CheckStaff(Event* event) {
    float tmp[4];
    signed int sprt_tbl[2] = {
        0xA1, 0xA2
    };
    s32* sprt_tbl_ptr = &sprt_tbl;
    float cam_len;
    float player_len;
    signed int i;
    signed int j;
    signed int player;
    signed int vc_num;

    if ((event->game.nplayer == 1) || ((vspenvGame->mode.game_mode == 1) && (vspenvGame->mode.match_rule == 3))) {
        for (i = 0; i < 2; i++) {
            cam_len = 160000.0f;
            player = -1;
            if ((vspenvGame->mode.game_mode == 1) && (vspenvGame->mode.match_rule == 3)) {
                sceVu0SubVector(tmp, vspev02Staff[i].trans, event->character[event->game.player].ctrl->sys_mat->cam_trans);
                sceVu0MulVector(tmp, tmp, tmp);
                if (tmp[0] + tmp[1] + tmp[2] < cam_len) {
                    cam_len = tmp[0] + tmp[1] + tmp[2];
                    player = event->game.player;
                    sceVu0SubVector(tmp, vspev02Staff[i].trans, event->character[event->game.player].ctrl->nowpos.pos);
                    sceVu0MulVector(tmp, tmp, tmp);
                    player_len = tmp[0] + tmp[1] + tmp[2];
                }
            } else {
                for (j = 0; j < event->game.nplayer; j++) {
                    sceVu0SubVector(tmp, vspev02Staff[i].trans, event->character[j].ctrl->sys_mat->cam_trans);
                    sceVu0MulVector(tmp, tmp, tmp);
                    if (tmp[0] + tmp[1] + tmp[2] < cam_len) {
                        cam_len = tmp[0] + tmp[1] + tmp[2];
                        player = j;
                        sceVu0SubVector(tmp, vspev02Staff[i].trans, event->character[j].ctrl->nowpos.pos);
                        sceVu0MulVector(tmp, tmp, tmp);
                        player_len = tmp[0] + tmp[1] + tmp[2];
                    }
                }
            }
            switch (tmevGetFlag(i + 0x56)) {
            case 0:
                if (cam_len < 160000.0f) {
                    tmevSetFlag(i + 0x56, 1);
                    tmevStartICounter(i + 0xB);
                    tmcrsSetObjectDrawFlag(sprt_tbl[i], 0);
                    vspev02StaffMdl[i].id = 4;
                    vspev02StaffMdl[i].draw = 1;
                }
                break;
            case 1:
                if (cam_len < 160000.0f) {
                    vspev02StaffMdl[i].frame = tmevGetICounter(i + 0xB) * 80.0f;
                    if (vspev02StaffMdl[i].frame == tmcrsGetEventModelFrame(vspev02StaffMdl[i].no, vspev02StaffMdl[i].id)) {
                        tmevResetICounter(i + 0xB);
                    }
                    if (cam_len < 90000.0f) {
                        tmevSetFlag(i + 0x56, 2);
                        if (tmevGetFlag(player + 0x5A) == 0) {
                            tmevSetFlag(i + 0x58, 0);
                        }
                        tmevResetICounter(i + 0xB);
                        vspev02StaffMdl[i].id = 0;
                        vspev02StaffMdl[i].frame = 0;
                    }
                } else {
                    tmevSetFlag(i + 0x56, 0);
                    tmevStopICounter(i + 0xB);
                    tmevResetICounter(i + 0xB);
                    tmcrsSetObjectDrawFlag(sprt_tbl[i], 1);
                    vspev02StaffMdl[i].draw = 0;
                }
                break;
            case 2:
                if (cam_len < 160000.0f) {
                    vspev02StaffMdl[i].frame = tmevGetICounter(i + 0xB) * 80.0f;
                    if (vspev02StaffMdl[i].frame == tmcrsGetEventModelFrame(vspev02StaffMdl[i].no, vspev02StaffMdl[i].id)) {
                        tmevResetICounter(i + 0xB);
                        if (cam_len < 90000.0f) {
                            tmevSetFlag(i + 0x56, 3);
                            vspev02StaffMdl[i].frame = 0;
                            vspev02StaffMdl[i].id = 1;
                        } else {
                            tmevSetFlag(i + 0x56, 1);
                            vspev02StaffMdl[i].frame = 0;
                            vspev02StaffMdl[i].id = 4;
                        }
                    }
                } else {
                    tmevSetFlag(i + 0x56, 0);
                    tmevStopICounter(i + 0xB);
                    tmevResetICounter(i + 0xB);
                    tmcrsSetObjectDrawFlag(sprt_tbl[i], 1);
                    vspev02StaffMdl[i].draw = 0;
                }
                break;
            case 3:
                if (cam_len < 160000.0f) {
                    vspev02StaffMdl[i].frame = tmevGetICounter(i + 0xB) * 80.0f;
                    if (vspev02StaffMdl[i].frame == tmcrsGetEventModelFrame(vspev02StaffMdl[i].no, vspev02StaffMdl[i].id)) {
                        tmevResetICounter(i + 0xB);
                        if (cam_len > 90000.0f) {
                            tmevSetFlag(i + 0x56, 1);
                            tmevSetFlag(i + 0x58, 0);
                            vspev02StaffMdl[i].frame = 0;
                            vspev02StaffMdl[i].id = 4;
                        }
                    }
                } else {
                    tmevSetFlag(i + 0x56, 0);
                    tmevStopICounter(i + 0xB);
                    tmevResetICounter(i + 0xB);
                    tmcrsSetObjectDrawFlag(sprt_tbl[i], 1);
                    vspev02StaffMdl[i].draw = 0;
                }
                break;
            case 4:
                if (cam_len < 160000.0f) {
                    vspev02StaffMdl[i].frame = tmevGetICounter(i + 0xB) * 80.0f;
                    if (vspev02StaffMdl[i].frame == tmcrsGetEventModelFrame(vspev02StaffMdl[i].no, vspev02StaffMdl[i].id)) {
                        tmevStopICounter(i + 0xB);
                    }
                } else {
                    tmevSetFlag(i + 0x56, 0);
                    tmevStopICounter(i + 0xB);
                    tmevResetICounter(i + 0xB);
                    tmcrsSetObjectDrawFlag(sprt_tbl[i], 1);
                    vspev02StaffMdl[i].frame = 0;
                    vspev02StaffMdl[i].draw = 0;
                    vspev02StaffMdl[i].id = 4;
                    vspev02StaffMdl[i].old_id = 4;
                }
                break;
            }
            if (tmevGetFlag(i + 0x58) == 0) {
                if (player >= 0) {
                    if (player_len < 22500.0f) {
                        vc_num = tmevGetICounter(0) % 3 + 0x1F;
                        nmeventPlayVoice(player, vc_num);
                        tmevSetFlag(i + 0x58, 1);
                    }
                }
            }
            if (player >= 0) {
                if (tmevGetFlag(i + 0x56) > 0) {
                    if (tmevGetFlag(i + 0x56) < 4) {
                        sceVu0SubVector(tmp, vspev02Staff[i].trans, event->character[player].ctrl->nowpos.pos);
                        vspev02Staff[i].tmp = atan2f(tmp[0], tmp[2]);
                        sceVu0UnitMatrix(vspev02StaffMdl[i].matrix);
                        sceVu0UnitMatrix(vspev02StaffMdl[i].matrix);
                        sceVu0RotMatrixY(vspev02StaffMdl[i].matrix, vspev02StaffMdl[i].matrix, vspev02Staff[i].tmp);
                        sceVu0TransMatrix(vspev02StaffMdl[i].matrix, vspev02StaffMdl[i].matrix, vspev02Staff[i].trans);
                        if (tmevGetEventMdlHit(event->character[player].ctrl, (&vspev02Staff[i])->no, 0, 10.0f) == 1) {
                            nmeventPlayVoice(player, 0x22);
                            tmevSetVib(event, 0, 5, 7);
                            tmevSetFlag(i + 0x56, 4);
                            tmevResetICounter(i + 0xB);
                            vspev02StaffMdl[i].frame = 0;
                            vspev02StaffMdl[i].id = 3;
                        }
                    }
                }
            }
        }
    }
}

static void spev02PlayEffect(Event* event) {
    signed int player;
    signed int ii;
    signed int jj;

    player = event->game.player;
    for (ii = 0; ii < event->character[player].nobj; ii++) {
        switch (event->character[player].object[ii].obj_type) {
        case 0x1D:
        case 0x19:
        case 0x1C:
        case 0x1B:
        case 0x1A:
            nmeventPlay(player, 0);
            tmevSetVib(event, 0, 2, 7);
            break;
        case 0x1:
            nmeventPlay(player, 1);
            tmevSetVib(event, 0, 3, 7);
            break;
        case 0x2:
            nmeventPlay(player, 7);
            tmevSetVib(event, 0, 3, 7);
            break;
        case 0x5:
            nmeventPlay(player, 4);
            tmevSetVib(event, 0, 1, 7);
            for (jj = 0; jj < 0xB; jj++) {
                if (vspev02Lamp[jj][0] == event->character[0].object[ii].obj_no) {
                    tmcrsSetObjectDrawFlag(vspev02Lamp[jj][1], 0);
                }
            }
            break;
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
            nmeventPlay(player, tmevGetICounter(0) % 3 + 8);
            tmevSetVib(event, 0, 1, 7);
            break;
        case 0x21:
            nmeventPlay(player, 1);
            tmevSetVib(event, 0, 2, 7);
            break;
        }
    }
}

static void spev02SeLift(Event* event) {
    static float lift_pos[3][4] = {
        { 244.853f, 807.823f, -1264.265f, 1.0f },
        { 1082.27f, 1651.51f, -4022.38f, 1.0f },
        { -240.649f, 4219.606f, -8986.3877f, 1.0f }
    };
    float tmp[4];
    float len;
    signed int j;
    signed int i;

    len = 90000.0f;
    if ((vspenvGame->mode.game_mode == 1) && (vspenvGame->mode.match_rule == 3)) {
        for (j = 0; j < 2; j++) {
            sceVu0SubVector(tmp, event->character[event->game.player].ctrl->sys_mat->cam_trans, lift_pos[j]);
            sceVu0MulVector(tmp, tmp, tmp);
            if (tmp[0] + tmp[1] + tmp[2] < len) {
                len = tmp[0] + tmp[1] + tmp[2];
            }
        }
        if (tmevGetFlag(0x7E) != 0) {
            sceVu0SubVector(tmp, event->character[event->game.player].ctrl->sys_mat->cam_trans, lift_pos[2]);
            sceVu0MulVector(tmp, tmp, tmp);
            if (tmp[0] + tmp[1] + tmp[2] < len) {
                len = tmp[0] + tmp[1] + tmp[2];
            }
        }
    } else {
        for (i = 0; i < event->game.nplayer; i++) {
            for (j = 0; j < 2; j++) {
                sceVu0SubVector(tmp, event->character[i].ctrl->sys_mat->cam_trans, lift_pos[j]);
                sceVu0MulVector(tmp, tmp, tmp);
                if (tmp[0] + tmp[1] + tmp[2] < len) {
                    len = tmp[0] + tmp[1] + tmp[2];
                }
            }
            if (tmevGetFlag(0x7E) != 0) {
                sceVu0SubVector(tmp, event->character[i].ctrl->sys_mat->cam_trans, lift_pos[2]);
                sceVu0MulVector(tmp, tmp, tmp);
                if (tmp[0] + tmp[1] + tmp[2] < len) {
                    len = tmp[0] + tmp[1] + tmp[2];
                }
            }
        }
    }
    if (len < 90000.0f) {
        vspev02SeLift.vol = (signed int)(90000.0f - len) * 255 / 90000;
        if (vspev02SeLift.vol < 0) {
            vspev02SeLift.vol = 0;
        } else if (0xFF < vspev02SeLift.vol) {
            vspev02SeLift.vol = 0xFF;
        }
        if (vspev02SeLift.id < 0) {
            nmvcSetOptVol(vspev02SeLift.vol, 0);
            vspev02SeLift.id = nmeventPlayLoop(0, 2);
        } else {
            nmvcSetInterVol(vspev02SeLift.id, vspev02SeLift.vol, 0);
        }
    } else {
        if (vspev02SeLift.id > 0) {
            nmeventStop(vspev02SeLift.id);
            vspev02SeLift.id = -1;
            vspev02SeLift.vol = 0;
        }
    }
}

void spev02ResetLevelGoals(void) {
    vspev02CafeCnt = 0;
    vspev02SpoutCnt = 0;
}

static void spev02CheckLevelGoals(Event* event) {
    static signed int cafe_tbl[5] = {
        0x41, 0x42, 0x43, 0x44, 0x45
    };
    signed int player;
    signed int ii;
    signed int jj;

    player = event->game.player;
    for (ii = 0; ii < event->character[player].nobj; ii++) {
        for (jj = 0; jj < 5; jj++) {
            if (cafe_tbl[jj] == event->character[player].object[ii].obj_no) {
                if (event->game.mode == 1) {
                    if (event->game.nplayer == 1) {
                        vspev02CafeCnt++;
                        if (vspev02CafeCnt == 5) {
                            tmevSetLevelGoal(player, 6);
                            vspev02CafeCnt = 0;
                        } else {
                            nmdispInputLevelCount(vspev02CafeCnt, 5, 6);
                        }
                    }
                }
            }
        }
        if (event->character[player].ctrl->act.trg_bonk == 1) {
            if (event->character[player].object[ii].obj_type == 3) {
                tmevSetLevelGoal(player, 7);
            }
        }
    }
}

void spev02ResetGaps() {
    signed int i;

    for (i = 0; i < 2; i++) {
        vspev02GlassCnt[i] = 0;
        vspev02ChairCnt[i] = 0;
        vspev02LampCnt[i] = 0;
        vspev02PipeCnt[i] = 0;
    }
    vspev02YuppieCnt = 0;
}

static void spev02CheckGaps(Event* event) {
    signed int player;

    player = event->game.player;
    spev02CheckAirGaps(event);
    spev02CheckManualGaps(event);
    spev02CheckGrindGaps(event);
    spev02CheckLipGaps(event);
    spev02CheckOtherGaps(event);
    if ((event->character[player].ctrl->act.sliding_state != essOnAir) || (event->character[player].ctrl->act.trg_bonk == 1)) {
        tmevSetFlag(player, 0);
        tmevSetFlag(player + 0x2, 0);
        tmevSetFlag(player + 0x4, 0);
        tmevSetFlag(player + 0x6, 0);
        tmevSetFlag(player + 0x8, 0);
        tmevSetFlag(player + 0xA, 0);
        tmevSetFlag(player + 0xC, 0);
        tmevSetFlag(player + 0xE, 0);
        tmevSetFlag(player + 0x10, 0);
        tmevSetFlag(player + 0x14, 0);
    }
    if (event->character[player].ctrl->act.sliding_state != essManual) {
        tmevSetFlag(player + 0x18, 0);
        vspev02GlassCnt[player] = 0;
        vspev02ChairCnt[player] = 0;
    }
    if ((event->character[player].ctrl->act.sliding_state == essSliding) || (event->character[player].ctrl->act.sliding_state == essManual)) {
        tmevSetFlag(player + 0x12, 0);
        tmevSetFlag(player + 0x16, 0);
        tmevSetFlag(player + 0x30, 0);
        tmevSetFlag(player + 0x36, 0);
        tmevSetFlag(player + 0x3A, 0);
    }
    if (event->character[player].ctrl->act.trg_bonk == 1) {
        tmevSetFlag(player + 0x12, 0);
        tmevSetFlag(player + 0x16, 0);
        tmevSetFlag(player + 0x1A, 0);
        tmevSetFlag(player + 0x1C, 0);
        tmevSetFlag(player + 0x1E, 0);
        tmevSetFlag(player + 0x20, 0);
        tmevSetFlag(player + 0x22, 0);
        tmevSetFlag(player + 0x24, 0);
        tmevSetFlag(player + 0x26, 0);
        tmevSetFlag(player + 0x28, 0);
        tmevSetFlag(player + 0x2A, 0);
        tmevSetFlag(player + 0x2C, 0);
        tmevSetFlag(player + 0x2E, 0);
        tmevSetFlag(player + 0x32, 0);
        tmevSetFlag(player + 0x34, 0);
        tmevSetFlag(player + 0x36, 0);
        tmevSetFlag(player + 0x3A, 0);
        vspev02LampCnt[player] = 0;
        vspev02PipeCnt[player] = 0;
    }
}

static void spev02CheckAirGaps(Event* event) {
    signed int player;
    signed int ii;

    player = event->game.player;
    for (ii = 0; ii < event->character[player].nhit; ii++) {
        if (event->character[player].hit[ii].no >= 0x64) {
            switch (event->character[player].hit[ii].no) {
            case 0x65:
                if (tmevGetFlag(player) == 0) {
                    if (event->character[player].ctrl->act.sliding_state == essOnAir) {
                        tmevSetGap(player, 0);
                        tmevSetFlag(player, 1);
                    }
                }
                break;
            case 0x66:
                if (tmevGetFlag(player + 0x2) == 0) {
                    if (event->character[player].ctrl->act.sliding_state == essOnAir) {
                        tmevSetGap(player, 1);
                        tmevSetFlag(player + 0x2, 1);
                    }
                }
                break;
            case 0x67:
                if (tmevGetFlag(player + 0x4) == 0) {
                    if (event->character[player].ctrl->act.sliding_state == essOnAir) {
                        tmevSetGap(player, 2);
                        tmevSetFlag(player + 0x4, 1);
                    }
                }
                break;
            case 0x68:
                if (tmevGetFlag(player + 0x6) == 0) {
                    if (event->character[player].ctrl->act.sliding_state == essOnAir) {
                        tmevSetGap(player, 3);
                        tmevSetFlag(player + 0x6, 1);
                    }
                }
                break;
            case 0x69:
                if (tmevGetFlag(player + 0x8) == 0) {
                    if (event->character[player].ctrl->act.sliding_state == essOnAir) {
                        tmevSetGap(player, 4);
                        tmevSetFlag(player + 0x8, 1);
                    }
                }
                break;
            case 0x6A:
                if (tmevGetFlag(player + 0xA) == 0) {
                    if (event->character[player].ctrl->act.sliding_state == essOnAir) {
                        tmevSetGap(player, 5);
                        tmevSetFlag(player + 0xA, 1);
                    }
                }
                break;
            case 0x6B:
                if (tmevGetFlag(player + 0xC) == 0) {
                    if (event->character[player].ctrl->act.sliding_state == essOnAir) {
                        tmevSetGap(player, 6);
                        tmevSetFlag(player + 0xC, 1);
                    }
                }
                break;
            case 0x6C:
            case 0x6D:
            case 0x6E:
            case 0x6F:
                spev02CheckGap_A8(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x1F4:
            case 0x1F5:
                spev02CheckGap_A9(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            case 0x26C:
                tmevSetFlag(player + 0x12, 1);
                break;
            case 0x26D:
            case 0x26E:
                spev02CheckGap_A11(&event->character[player], player, event->character[player].hit[ii].no);
                break;
            }
        }
    }
    if (event->character[player].ctrl->act.sliding_state == essGrind) {
        if ((event->character[player].old_rail == -1) || (event->character[player].old_rail != event->character[player].rail)) {
            spev02CheckGap_A10(&event->character[player], player, event->character[player].rail);
            spev02CheckGap_A12(&event->character[player], player, event->character[player].rail);
        }
    }
}

static void spev02CheckGap_A8(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x6C:
        tmevSetFlag(player + 0xE, 1);
        break;
    case 0x6D:
        if (tmevGetFlag(player + 0xE) == 1) {
            if (character->ctrl->act.sliding_state != essGrind) {
                if (character->ctrl->act.hp_air == 1) {
                    tmevSetGap(player, 0x7);
                    tmevSetFlag(player + 0xE, 0);
                }
            }
        }
        break;
    case 0x6E:
        tmevSetFlag(player + 0xE, 2);
        break;
    case 0x6F:
        if (tmevGetFlag(player + 0xE) == 2) {
            if (character->ctrl->act.sliding_state != essGrind) {
                if (character->ctrl->act.hp_air == 1) {
                    tmevSetGap(player, 0x7);
                    tmevSetFlag(player + 0xE, 0);
                }
            }
        }
        break;
    }
}

static void spev02CheckGap_A9(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x1F4:
        tmevSetFlag(player + 0x10, 1);
        break;
    case 0x1F5:
        if (tmevGetFlag(player + 0x10) == 1) {
            tmevSetGap(player, 0x8);
            tmevSetFlag(player + 0x10, 0);
        }
        break;
    }
}

static void spev02CheckGap_A10(Character* character, signed int player, signed int no) {
    if (tmevGetFlag(player + 0x12) == 1) {
        switch (no) {
        case 0x215:
        case 0x26:
            tmevSetGap(player, 0x9);
            tmevSetFlag(player + 0x12, 0);
            break;
        default:
            tmevSetFlag(player + 0x12, 0);
            break;
        }
    }
}

static void spev02CheckGap_A11(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x26D:
        tmevSetFlag(player + 0x14, 1);
        break;
    case 0x26E:
        if (tmevGetFlag(player + 0x14) == 1) {
            tmevSetGap(player, 0xA);
            tmevSetFlag(player + 0x14, 0);
        }
        break;
    }
}

static void spev02CheckGap_A12(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x216:
    case 0x217:
        tmevSetFlag(player + 0x16, 1);
        break;
    default:
        if (tmevGetFlag(player + 0x16) == 1) {
            if ((no == 0x198) || (no == 0x19B) || (no == 0x199) || (no == 0x19A) || (no == 0x19C) || (no == 0x19D) || (no == 0x19E) || (no == 0x19F) || (no == 0x1A0) || (no == 0x1A1) || (no == 0x155) || (no == 0x157) || (no == 0x1A6) || (no == 0x1A5) || (no == 0x1A4) || (no == 0x1A3) || (no == 0x1A2) || (no == 0x158) || (no == 0x1AB) || (no == 0x1AA) || (no == 0x1A9) || (no == 0x1A8) || (no == 0x1A7) || (no == 0x156) || (no == 0x1AC)) {
                tmevSetGap(player, 0xB);
                tmevSetFlag(player + 0x16, 0);
            } else {
                tmevSetFlag(player + 0x16, 0);
            }
        }
        break;
    }
}

static void spev02CheckManualGaps(Event* event) {
    signed int player;
    signed int ii;

    player = event->game.player;
    if (event->character[player].ctrl->act.sliding_state == essManual) {
        for (ii = 0; ii < event->character[player].nobj; ii++) {
            switch (event->character[player].object[ii].obj_type) {
            case 0x19:
                spev02CheckGap_M1(&event->character[player], player, event->character[player].object[ii].obj_no);
                break;
            case 0x1D:
                spev02CheckGap_M2(&event->character[player], player, event->character[player].object[ii].obj_no);
                break;
            }
        }
    }
}

static void spev02CheckGap_M1(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x7F:
    case 0x80:
    case 0x7E:
        vspev02GlassCnt[player]++;
        if (vspev02GlassCnt[player] == 3) {
            tmevSetGap(player, 0xC);
            vspev02GlassCnt[player] = 0;
        }
        break;
    }
}

static void spev02CheckGap_M2(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x92:
    case 0x91:
        tmevSetFlag(player + 0x18, 1);
        break;
    case 0x93:
    case 0x94:
        if (tmevGetFlag(player + 0x18) == 1) {
            tmevSetGap(player, 0xD);
            tmevSetFlag(player + 0x18, 0);
        }
        break;
    }
}

static void spev02CheckGrindGaps(Event* event) {
    signed int player;
    signed int ii;

    player = event->game.player;
    if ((event->character[player].ctrl->act.sliding_state == essGrind) && ((event->character[player].old_rail == -1) || (event->character[player].old_rail != event->character[player].rail))) {
        switch (event->character[player].rail) {
        case 0x15A:
            tmevSetFlag(player + 0x20, 1);
            break;
        case 0x18E:
        case 0x18F:
        case 0x190:
        case 0x119:
            tmevSetGap(player, 0x15);
            break;
        case 0x170:
            tmevSetFlag(player + 0x2A, 1);
            break;
        case 0x1B2:
        case 0x1B1:
            spev02CheckGap_G14(&event->character[player], player);
            break;
        case 0x1AD:
            tmevSetGap(player, 0x1C);
            break;
        case 0x1B0:
            tmevSetFlag(player + 0x2E, 1);
            break;
        }
        spev02CheckGap_G1(&event->character[player], player);
        spev02CheckGap_G2(&event->character[player], player);
        spev02CheckGap_G3(&event->character[player], player);
        spev02CheckGap_G5(&event->character[player], player);
        spev02CheckGap_G6(&event->character[player], player);
        spev02CheckGap_G10(&event->character[player], player, event->character[player].rail);
        spev02CheckGap_G11(&event->character[player], player);
        spev02CheckGap_G19(&event->character[player], player, event->character[player].rail);
        spev02CheckGap_G21(&event->character[player], player, event->character[player].rail);
        spev02CheckGap_G22(&event->character[player], player, event->character[player].rail);
        spev02CheckGap_G23(&event->character[player], player, event->character[player].rail);
        spev02CheckGap_G24(&event->character[player], player, event->character[player].rail);
    } else if (event->character[player].ctrl->act.sliding_state == essGrind) {
        for (ii = 0; ii < event->character[player].nhit; ii++) {
            if (event->character[player].hit[ii].no >= 0x64) {
                switch (event->character[player].hit[ii].no) {
                case 0xC9:
                    spev02CheckGap_G4(&event->character[player], player);
                    break;
                case 0xD2:
                    spev02CheckGap_G13(&event->character[player], player);
                    break;
                case 0xD3:
                case 0xD4:
                    spev02CheckGap_G16(&event->character[player], player, event->character[player].hit[ii].no);
                    break;
                }
            }
        }
    } else if (event->character[player].old_rail == -1) {
        tmevSetFlag(player + 0x1A, 0);
        tmevSetFlag(player + 0x1C, 0);
        tmevSetFlag(player + 0x1E, 0);
        tmevSetFlag(player + 0x20, 0);
        tmevSetFlag(player + 0x22, 0);
        tmevSetFlag(player + 0x24, 0);
        tmevSetFlag(player + 0x26, 0);
        tmevSetFlag(player + 0x28, 0);
        tmevSetFlag(player + 0x2A, 0);
        tmevSetFlag(player + 0x2C, 0);
        tmevSetFlag(player + 0x2E, 0);
        tmevSetFlag(player + 0x32, 0);
        tmevSetFlag(player + 0x34, 0);
        vspev02PipeCnt[player] = 0;
        vspev02LampCnt[player] = 0;
    }
    spev02CheckGap_G12(&event->character[player], player);
    for (ii = 0; ii < event->character[player].nhit; ii++) {
        if (event->character[player].hit[ii].no >= 0x64) {
            if (event->character[player].ctrl->act.trg_bonk == 1) {
                switch (event->character[player].hit[ii].no) {
                case 0x12F:
                    tmevSetGap(player, 0x14);
                    break;
                case 0x130:
                    tmevSetGap(player, 0x16);
                    break;
                }
                spev02CheckGap_G18(&event->character[player], player, event->character[player].hit[ii].no);
            } else {
                switch (event->character[player].hit[ii].no) {
                case 0x28A:
                    tmevSetFlag(player + 0x36, 1);
                    break;
                case 0x28B:
                    tmevSetFlag(player + 0x3A, 1);
                    break;
                }
            }
        }
    }
    if (event->character[player].ctrl->act.trg_bonk == 1) {
        for (ii = 0; ii < event->character[player].nobj; ii++) {
            switch (event->character[player].object[ii].obj_type) {
            case 0x3:
                tmevSetGap(player, 0x1E);
                break;
            case 0x4:
                tmevSetGap(player, 0x21);
                break;
            }
        }
    }
}

static void spev02CheckGap_G1(Character* character, signed int player) {
    switch (character->rail) {
    case 0x12:
        tmevSetFlag(player + 0x1A, 1);
        break;
    case 0x18:
        if (tmevGetFlag(player + 0x1A) == 1) {
            tmevSetFlag(player + 0x1A, 2);
        }
        break;
    case 0x14:
        if (tmevGetFlag(player + 0x1A) == 2) {
            tmevSetGap(player, 0xE);
            tmevSetFlag(player + 0x1A, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x1A, 0);
        break;
    }
}

static void spev02CheckGap_G2(Character* character, signed int player) {
    switch (character->rail) {
    case 0x19:
        tmevSetFlag(player + 0x1C, 1);
        break;
    case 0x107:
    case 0x178:
        if (tmevGetFlag(player + 0x1C) == 1) {
            tmevSetGap(player, 0xF);
            tmevSetFlag(player + 0x1C, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x1C, 0);
        break;
    }
}

static void spev02CheckGap_G3(Character* character, signed int player) {
    switch (character->rail) {
    case 0x9:
        tmevSetFlag(player + 0x1E, 1);
        break;
    case 0x17B:
        if (tmevGetFlag(player + 0x1E) == 1) {
            tmevSetFlag(player + 0x1E, 2);
        }
        break;
    case 0x17C:
        if (tmevGetFlag(player + 0x1E) == 2) {
            tmevSetGap(player, 0x10);
            tmevSetFlag(player + 0x1E, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x1E, 0);
        break;
    }
}

static void spev02CheckGap_G4(Character* character, signed int player) {
    if (tmevGetFlag(player + 0x20) == 1) {
        tmevSetGap(player, 0x11);
        tmevSetFlag(player + 0x20, 0);
    }
}

static void spev02CheckGap_G5(Character* character, signed int player) {
    switch (character->rail) {
    case 0x17E:
        tmevSetFlag(player + 0x22, 1);
        break;
    case 0x17F:
        if (tmevGetFlag(player + 0x22) == 1) {
            tmevSetFlag(player + 0x22, 2);
        }
        break;
    case 0:
        if (tmevGetFlag(player + 0x22) == 2) {
            tmevSetGap(player, 0x12);
            tmevSetFlag(player + 0x22, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x22, 0);
        break;
    }
}

static void spev02CheckGap_G6(Character* character, signed int player) {
    switch (character->rail) {
    case 0x18B:
    case 0x18A:
        if (tmevGetFlag(player + 0x24) == 0) {
            tmevSetFlag(player + 0x24, 1);
            tmevSetGap(player, 0x13);
        }
        break;
    }
}

static void spev02CheckGap_G10(Character* character, signed int player, signed int no) {
    if ((no == 0x198) || (no == 0x19B) || (no == 0x199) || (no == 0x19A) || (no == 0x19C) || (no == 0x19D) || (no == 0x19E) || (no == 0x19F) || (no == 0x1A0) || (no == 0x1A1) || (no == 0x155) || (no == 0x157) || (no == 0x1A6) || (no == 0x1A5) || (no == 0x1A4) || (no == 0x1A3) || (no == 0x1A2) || (no == 0x158) || (no == 0x1AB) || (no == 0x1AA) || (no == 0x1A9) || (no == 0x1A8) || (no == 0x1A7) || (no == 0x156) || (no == 0x1AC)) {
        vspev02PipeCnt[player]++;
        if (vspev02PipeCnt[player] == 3) {
            tmevSetGap(player, 0x17);
        }
    } else {
        vspev02PipeCnt[player] = 0;
    }
}

static void spev02CheckGap_G11(Character* character, signed int player) {
    switch (character->rail) {
    case 0x1AF:
    case 0x1AE:
        if (tmevGetFlag(player + 0x26) == 0) {
            tmevSetFlag(player + 0x26, 1);
            tmevSetGap(player, 0x18);
        }
        break;
    }
}

static void spev02CheckGap_G12(Character* character, signed int player) {
    signed int ii;
    signed int jj;

    for (ii = 0; ii < character->nobj; ii++) {
        for (jj = 0; jj < 4; jj++) {
            if (vspev02Lamp[jj][0] == character->object[ii].obj_no) {
                if (character->ctrl->act.sliding_state == essGrind) {
                    if (character->rail == 0x16F) {
                        vspev02LampCnt[player]++;
                        if (vspev02LampCnt[player] == 4) {
                            tmevSetGap(player, 0x19);
                            tmevSetFlag(player + 0x28, 0);
                            vspev02LampCnt[player] = 0;
                        }
                    }
                }
            }
        }
    }
}

static void spev02CheckGap_G13(Character* character, signed int player) {
    if (tmevGetFlag(player + 0x2A) == 1) {
        tmevSetGap(player, 0x1A);
        tmevSetFlag(player + 0x2A, 0);
    }
}

static void spev02CheckGap_G14(Character* character, signed int player) {
    switch (character->rail) {
    case 0x1B2:
    case 0x1B1:
        if (tmevGetFlag(player + 0x2C) == 0) {
            tmevSetFlag(player + 0x2C, 1);
            tmevSetGap(player, 0x1B);
        }
        break;
    }
}

static void spev02CheckGap_G16(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0xD3:
        if (tmevGetFlag(player + 0x2E) == 1) {
            tmevSetFlag(player + 0x2E, 2);
        }
        break;
    case 0xD4:
        if (tmevGetFlag(player + 0x2E) == 2) {
            tmevSetGap(player, 0x1D);
            tmevSetFlag(player + 0x2E, 0);
        }
        break;
    }
}

static void spev02CheckGap_G18(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x139:
        if (tmevGetFlag(player + 0x30) == 0) {
            tmevSetFlag(player + 0x30, 1);
        }
        break;
    case 0x13A:
        if (tmevGetFlag(player + 0x30) == 1) {
            tmevSetFlag(player + 0x30, 2);
        }
        break;
    case 0x13B:
        if (tmevGetFlag(player + 0x30) == 2) {
            tmevSetGap(player, 0x1F);
            tmevSetFlag(player + 0x30, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x30, 0);
        break;
    }
}

static void spev02CheckGap_G19(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x1BC:
        if (tmevGetFlag(player + 0x32) == 0) {
            tmevSetFlag(player + 0x32, 1);
        }
        break;
    case 0x1BD:
        if (tmevGetFlag(player + 0x32) == 1) {
            tmevSetFlag(player + 0x32, 2);
        }
        break;
    case 0x1BE:
        if (tmevGetFlag(player + 0x32) == 2) {
            tmevSetGap(player, 0x20);
            tmevSetFlag(player + 0x32, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x32, 0);
        break;
    }
}

void spev02CheckGap_G21(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x107:
        if (tmevGetFlag(player + 0x34) == 0) {
            tmevSetFlag(player + 0x34, 1);
            return;
        }
        break;
    case 0x9:
        if (tmevGetFlag(player + 0x34) == 1) {
            tmevSetGap(player, 0x22);
            tmevSetFlag(player + 0x34, 0);
            return;
        }
        break;
    default:
        tmevSetFlag(player + 0x34, 0);
        break;
    }
}

void spev02CheckGap_G22(Character* character, signed int player, signed int no) {
    if (tmevGetFlag(player + 0x36) == 1) {
        if ((no == 0x198) || (no == 0x19B) || (no == 0x199) || (no == 0x19A) || (no == 0x19C) || (no == 0x19D) || (no == 0x19E) || (no == 0x19F) || (no == 0x1A0) || (no == 0x1A1) || (no == 0x155) || (no == 0x157) || (no == 0x1A6) || (no == 0x1A5) || (no == 0x1A4) || (no == 0x1A3) || (no == 0x1A2) || (no == 0x158) || (no == 0x1AB) || (no == 0x1AA) || (no == 0x1A9) || (no == 0x1A8) || (no == 0x1A7) || (no == 0x156) || (no == 0x1AC)) {
            tmevSetGap(player, 0x23);
        }
        tmevSetFlag(player + 0x36, 0);
    }
}

static void spev02CheckGap_G23(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x193:
        if (tmevGetFlag(player + 0x38) == 0) {
            tmevSetFlag(player + 0x38, 1);
        }
        break;
    case 0x195:
        if (tmevGetFlag(player + 0x38) == 1) {
            tmevSetGap(player, 0x24);
            tmevSetFlag(player + 0x38, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x38, 0);
        break;
    }
}

static void spev02CheckGap_G24(Character* character, signed int player, signed int no) {
    switch (no) {
    case 0x212:
        if (tmevGetFlag(player + 0x3A) == 1) {
            tmevSetFlag(player + 0x3A, 2);
        }
        break;
    case 0x213:
        if (tmevGetFlag(player + 0x3A) == 2) {
            tmevSetFlag(player + 0x3A, 3);
        }
        break;
    case 0x214:
        if (tmevGetFlag(player + 0x3A) == 3) {
            tmevSetGap(player, 0x25);
            tmevSetFlag(player + 0x3A, 0);
        }
        break;
    default:
        tmevSetFlag(player + 0x3A, 0);
        break;
    }
}

static void spev02CheckLipGaps(Event* event) {
    signed int player;

    player = event->game.player;
    if (event->character[player].ctrl->act.sliding_state == essPlant) {
        if (event->character[player].old_rail == -1) {
            switch (event->character[player].rail) {
            case 0xA6:
            case 0x1B3:
                tmevSetGap(player, 0x26);
                break;
            }
        }
    }
}

static void spev02CheckOtherGaps(Event* event) {
    signed int player;

    player = event->game.player;
}

static void spev02InitSnowSpout() {
    vspev02SnowSpout1 = (Info*)ulMalloc(0xC0, 0, 0);
    vspev02SnowSpout2 = (Info*)ulMalloc(0xC0, 0, 0);
    vspev02SnowSpout1->freq = 0x30;
    vspev02SnowSpout2->freq = 0x8;
    vspev02SnowSpout1->ttl = 0x5A;
    vspev02SnowSpout1->ttl2 = 0x32;
    vspev02SnowSpout2->ttl = 0x64;
    vspev02SnowSpout2->ttl2 = 0x32;
    vspev02SnowSpout1->sx = 3500.0f;
    vspev02SnowSpout1->sy = 3500.0f;
    vspev02SnowSpout2->sx = 3500.0f;
    vspev02SnowSpout2->sy = 3500.0f;
    vspev02SnowSpout1->sx2 = 1000.0f;
    vspev02SnowSpout1->sy2 = 1000.0f;
    vspev02SnowSpout2->sx2 = 1000.0f;
    vspev02SnowSpout2->sy2 = 1000.0f;
    vspev02SnowSpout1->sx3 = 250.0f;
    vspev02SnowSpout1->sy3 = 250.0f;
    vspev02SnowSpout2->sx3 = 250.0f;
    vspev02SnowSpout2->sy3 = 250.0f;
    vspev02SnowSpout1->fin = 0x3;
    vspev02SnowSpout1->fout = 0x78;
    vspev02SnowSpout2->fin = 0x3;
    vspev02SnowSpout2->fout = 0x78;
    vspev02SnowSpout1->zofs = 1.20000005f;
    vspev02SnowSpout2->zofs = 1.20000005f;
    vspev02SnowSpout1->pos[0] = 1255.98096f;
    vspev02SnowSpout1->pos[1] = 1680.10095f;
    vspev02SnowSpout1->pos[2] = -3949.94995f;
    vspev02SnowSpout1->pos[3] = 1.0f;
    vspev02SnowSpout2->pos[0] = 1255.98096f;
    vspev02SnowSpout2->pos[1] = 1680.10095f;
    vspev02SnowSpout2->pos[2] = -3949.94995f;
    vspev02SnowSpout2->pos[3] = 1.0f;
    vspev02SnowSpout1->pos2[0] = 1.0f;
    vspev02SnowSpout1->pos2[1] = -1.0f;
    vspev02SnowSpout1->pos2[2] = 1.0f;
    vspev02SnowSpout1->pos2[3] = 1.0f;
    vspev02SnowSpout2->pos2[0] = 1.0f;
    vspev02SnowSpout2->pos2[1] = -1.0f;
    vspev02SnowSpout2->pos2[2] = 1.0f;
    vspev02SnowSpout2->pos2[3] = 1.0f;
    vspev02SnowSpout1->mov[0] = 0;
    vspev02SnowSpout1->mov[1] = -0.800000012f;
    vspev02SnowSpout1->mov[2] = -6.0f;
    vspev02SnowSpout1->mov[3] = 1.0f;
    vspev02SnowSpout2->mov[0] = 0;
    vspev02SnowSpout2->mov[1] = -0.800000012f;
    vspev02SnowSpout2->mov[2] = -6.0f;
    vspev02SnowSpout2->mov[3] = 1.0f;
    vspev02SnowSpout1->mov2[0] = 1.0f;
    vspev02SnowSpout1->mov2[1] = 0.400000006f;
    vspev02SnowSpout1->mov2[2] = 1.0f;
    vspev02SnowSpout1->mov2[3] = 1.0f;
    vspev02SnowSpout2->mov2[0] = 1.0f;
    vspev02SnowSpout2->mov2[1] = 0.400000006f;
    vspev02SnowSpout2->mov2[2] = 1.0f;
    vspev02SnowSpout2->mov2[3] = 1.0f;
    vspev02SnowSpout1->acc[0] = 0;
    vspev02SnowSpout1->acc[1] = 0.0199999996f;
    vspev02SnowSpout1->acc[2] = 0;
    vspev02SnowSpout1->acc[3] = 1.0f;
    vspev02SnowSpout2->acc[0] = 0;
    vspev02SnowSpout2->acc[1] = 0.0199999996f;
    vspev02SnowSpout2->acc[2] = 0;
    vspev02SnowSpout2->acc[3] = 1.0f;
    vspev02SnowSpout1->dec[0] = 0.980000019f;
    vspev02SnowSpout1->dec[1] = 1.0f;
    vspev02SnowSpout1->dec[2] = 0.980000019f;
    vspev02SnowSpout1->dec[3] = 1.0f;
    vspev02SnowSpout2->dec[0] = 0.980000019f;
    vspev02SnowSpout2->dec[1] = 1.0f;
    vspev02SnowSpout2->dec[2] = 0.980000019f;
    vspev02SnowSpout2->dec[3] = 1.0f;
    vspev02SnowSpout1->alpha = 0x44;
    vspev02SnowSpout2->alpha = 0x44;
    vspev02SnowSpout1->tex0 = ultexGetTEX0((char*)spfxGetTexData() + 0x190);
    vspev02SnowSpout2->tex0 = ultexGetTEX0((char*)spfxGetTexData() + 0x1A0);
    vspev02SnowSpout1->rgba[0] = 0x80;
    vspev02SnowSpout1->rgba[1] = 0x6E;
    vspev02SnowSpout1->rgba[2] = 0x60;
    vspev02SnowSpout1->rgba[3] = 0x60;
    vspev02SnowSpout2->rgba[0] = 0x80;
    vspev02SnowSpout2->rgba[1] = 0x6E;
    vspev02SnowSpout2->rgba[2] = 0x60;
    vspev02SnowSpout2->rgba[3] = 0x60;
    vspev02SnowSpout1->count = 0;
    vspev02SnowSpout2->count = 0;
}

void spev02ResetSnowSpout() {
    akevResetSmokeInfo(vspev02SnowSpout1);
    akevResetSmokeInfo(vspev02SnowSpout2);
}

static void spev02PlayerSnowSpout(Event* event) {
    static float pos[5][4] = {
        { 1255.980957f, 1680.100952f, -3949.949951f, 1.0f },
        { -505.9140015f, 3815.072998f, -8082.421875f, 1.0f },
        { -829.3779907f, 4503.979004f, -9462.970703f, 1.0f },
        { -150.5130005f, 1160.687012f, -1982.762939f, 1.0f },
        { 223.6699982f, 1798.262939f, -4028.452881f, 1.0f }
    };
    static float mov[5][4] = {
        { 0.0f, -2.799999952f, -6.0f, 1.0f },
        { 4.0f, -2.799999952f, 3.0f, 1.0f },
        { 2.0f, -2.799999952f, -5.0f, 1.0f },
        { -2.0f, -2.799999952f, -5.0f, 1.0f },
        { 0.0f, -2.799999952f, -6.0f, 1.0f }
    };
    float tmp[4];
    signed int hit_no[5] = {
        0x12E, 0x136, 0x138, 0x13C, 0x13D
    };
    s32* hit_no_ptr = &hit_no;
    signed int player;
    signed int i;
    signed int j;

    player = event->game.player;
    for (i = 0; i < event->character[player].nhit; i++) {
        if (event->character[player].hit[i].no >= 0x64) {
            if (event->character[player].ctrl->act.trg_bonk == 1) {
                for (j = 0; j < 5; j++) {
                    if (event->character[player].hit[i].no == hit_no[j]) {
                        if (tmevGetFlag(j + 0x40) == 0) {
                            tmevSetFlag(j + 0x40, 1);
                        } else if (tmevGetFlag(j + 0x40) == 3) {
                            tmevSetFlag(j + 0x40, 1);
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 5; i++) {
        switch (tmevGetFlag(i + 0x40)) {
        case 1:
            tmevStartICounter(i + 1);
            tmevSetFlag(i + 0x40, 2);
            nmeventPlay(player, 3);
            tmevSetVib(event, 0, 1, 7);
            break;
        case 2:
            if (tmevGetICounter(i + 1) == 0x3C) {
                tmevSetFlag(i + 0x40, 3);
                tmevStopICounter(i + 1);
                tmevResetICounter(i + 1);
            } else {
                sceVu0SubVector(tmp, event->character[player].ctrl->sys_mat->cam_trans, pos[i]);
                sceVu0MulVector(tmp, tmp, tmp);
                if (tmp[0] + tmp[1] + tmp[2] < 1000000.0f) {
                    vspev02SnowSpout1->pos[0] = pos[i][0];
                    vspev02SnowSpout1->pos[1] = pos[i][1];
                    vspev02SnowSpout1->pos[2] = pos[i][2];
                    vspev02SnowSpout1->pos[3] = 1.0f;
                    vspev02SnowSpout2->pos[0] = pos[i][0];
                    vspev02SnowSpout2->pos[1] = pos[i][1];
                    vspev02SnowSpout2->pos[2] = pos[i][2];
                    vspev02SnowSpout2->pos[3] = 1.0f;
                    vspev02SnowSpout1->mov[0] = mov[i][0];
                    vspev02SnowSpout1->mov[1] = mov[i][1];
                    vspev02SnowSpout1->mov[2] = mov[i][2];
                    vspev02SnowSpout1->mov[3] = 1.0f;
                    vspev02SnowSpout2->mov[0] = mov[i][0];
                    vspev02SnowSpout2->mov[1] = mov[i][1];
                    vspev02SnowSpout2->mov[2] = mov[i][2];
                    vspev02SnowSpout2->mov[3] = 1.0f;
                    akevBlowupSmoke(vspev02Smoke, vspev02SnowSpout1);
                    akevBlowupSmoke(vspev02Smoke, vspev02SnowSpout2);
                }
            }
            break;
        }
    }
}

void spev02EndSnowSpout() {
    ulFree(vspev02SnowSpout1);
    ulFree(vspev02SnowSpout2);
}

static void spev02InitWagonClash() {
    vspev02WagonClash = (Info*)ulMalloc(0xC0, 0, 0);
    vspev02WagonClash->freq = 0x96;
    vspev02WagonClash->ttl = 0x3C;
    vspev02WagonClash->ttl2 = 0x28;
    vspev02WagonClash->sx = 28000.0f;
    vspev02WagonClash->sy = 14000.0f;
    vspev02WagonClash->sx2 = 13333.333f;
    vspev02WagonClash->sy2 = 6666.6665f;
    vspev02WagonClash->sx3 = 150.0f;
    vspev02WagonClash->sy3 = 50.0f;
    vspev02WagonClash->fin = 0x1;
    vspev02WagonClash->fout = 0x32;
    vspev02WagonClash->zofs = 1.20000005f;
    vspev02WagonClash->pos[0] = 266.270996f;
    vspev02WagonClash->pos[1] = 2265.83789f;
    vspev02WagonClash->pos[2] = -5154.33887f;
    vspev02WagonClash->pos[3] = 1.0f;
    vspev02WagonClash->pos2[0] = 30.0f;
    vspev02WagonClash->pos2[1] = 10.0f;
    vspev02WagonClash->pos2[2] = 30.0f;
    vspev02WagonClash->pos2[3] = 1.0f;
    vspev02WagonClash->mov[0] = 0;
    vspev02WagonClash->mov[1] = -0.5f;
    vspev02WagonClash->mov[2] = 0;
    vspev02WagonClash->mov[3] = 1.0f;
    vspev02WagonClash->mov2[0] = 6.0f;
    vspev02WagonClash->mov2[1] = 1.0f;
    vspev02WagonClash->mov2[2] = 6.0f;
    vspev02WagonClash->mov2[3] = 1.0f;
    vspev02WagonClash->acc[0] = 0;
    vspev02WagonClash->acc[1] = 0;
    vspev02WagonClash->acc[2] = 0;
    vspev02WagonClash->acc[3] = 1.0f;
    vspev02WagonClash->dec[0] = 0.970000029f;
    vspev02WagonClash->dec[1] = 0.970000029f;
    vspev02WagonClash->dec[2] = 0.970000029f;
    vspev02WagonClash->dec[3] = 1.0f;
    vspev02WagonClash->alpha = 0x44;
    vspev02WagonClash->tex0 = ultexGetTEX0((char*)spfxGetTexData() + 0x190);
    vspev02WagonClash->rgba[0] = 0x80;
    vspev02WagonClash->rgba[1] = 0x6E;
    vspev02WagonClash->rgba[2] = 0x60;
    vspev02WagonClash->rgba[3] = 0x30;
    vspev02WagonClash->count = 0;
}

void spev02ResetWagonClash() {
    akevResetSmokeInfo(vspev02WagonClash);
}

static void spev02PlayerWagonClash(Event* event) {
    switch (tmevGetFlag(0x46)) {
    case 1:
        if (tmevGetICounter(0x3D) < 0xA) {
            akevBlowupSmoke(vspev02Smoke, vspev02WagonClash);
        } else {
            tmevSetFlag(0x46, 0);
            tmevStopICounter(0x3D);
            tmevResetICounter(0x3D);
        }
        break;
    }
}

void spev02EndWagonClash() {
    ulFree(vspev02WagonClash);
}

void spev02ResetLight(signed int player) {
    // signed int player;

    // player = player;
    vspev02Light[player].light_color[0][0] = 0.36f;
    vspev02Light[player].light_color[0][1] = 0.27f;
    vspev02Light[player].light_color[0][2] = 0.26f;
    vspev02Light[player].light_color[0][3] = 1.0f;
    vspev02Light[player].normal_light[0][0] = -1.0f;
    vspev02Light[player].normal_light[0][1] = 1.0f;
    vspev02Light[player].normal_light[0][2] = 1.0f;
    vspev02Light[player].normal_light[0][3] = 1.0f;
    vspev02Light[player].light_color[1][0] = 0.0f;
    vspev02Light[player].light_color[1][1] = 0.0f;
    vspev02Light[player].light_color[1][2] = 0.0f;
    vspev02Light[player].light_color[1][3] = 1.0f;
    vspev02Light[player].normal_light[1][0] = 0.0f;
    vspev02Light[player].normal_light[1][1] = 0.0f;
    vspev02Light[player].normal_light[1][2] = 0.0f;
    vspev02Light[player].normal_light[1][3] = 1.0f;
    vspev02Light[player].ambient[0] = 0.1f;
    vspev02Light[player].ambient[1] = 0.06f;
    vspev02Light[player].ambient[2] = 0.03f;
    vspev02Light[player].ambient[3] = 0.0f;
    tmevSetLightVector(vspev02Light[player].light_color[0], vspev02Light[player].normal_light[0], 0, player);
    tmevSetLightVector(vspev02Light[player].light_color[0], vspev02Light[player].normal_light[0], 1, player);
    tmevSetAmbient(vspev02Light[player].ambient, player);
}

static void spev02CheckWarp(Event* event) {
    float tmp[4];
    signed int player;
    signed int i;

    if (event->game.nplayer == 1) {
        player = event->game.player;
        for (i = 0; i < event->character[player].nhit; i++) {
            switch (event->character[player].hit[i].no) {
            case 0x1F:
                tmp[0] = 1.6f;
                tmp[1] = -1013.3f;
                tmp[2] = 1298.3f;
                tmp[3] = 1.0f;
                ktactSetRecover(player, tmp, 0.031939523f, 0, 1);
                spev02ResetYuppie(event);
                nmeventPlayWarp(player, 0x23);
                break;
            case 0x20:
                tmp[0] = -1646.2f;
                tmp[1] = 3490.9f;
                tmp[2] = -7187.0f;
                tmp[3] = 1.0f;
                ktactSetRecover(player, tmp, -0.86795205f, 0, 1);
                spev02ResetYuppie(event);
                nmeventPlayWarp(player, 0x24);
                break;
            case 0x21:
                tmp[0] = 416.6f;
                tmp[1] = 524.0f;
                tmp[2] = -264.2f;
                tmp[3] = 1.0f;
                ktactSetRecover(player, tmp, 0.52778745f, 0, 1);
                spev02ResetYuppie(event);
                nmeventPlayWarp(player, 0x25);
                break;
            }
        }
    }
}

void spev02MatchWarp(Event* event) {
}

static void spev02CheckDraw(Event* event) {
    signed int player;
    signed int ii;

    player = event->game.player;
    for (ii = 0; ii < event->character[player].nhit; ii++) {
        switch (event->character[player].hit[ii].no) {
        case 0x387:
            if (tmevGetFlag(player + 0x3C) == 0) {
                tmevSetFlag(player + 0x3C, 1);
                tmevSetDrawLength(3000.0f, player);
            }
            break;
        case 0x388:
            if (tmevGetFlag(player + 0x3C) == 1) {
                tmevSetFlag(player + 0x3C, 0);
                tmevSetDrawLength(3600.0f, player);
            }
            break;
        case 0x385:
            if (event->game.mode == 1) {
                if (tmevGetFlag(player + 0x3E) == 0) {
                    tmevSetFlag(player + 0x3E, 1);
                    tmevSetViewAngle(0.95993096f, player);
                }
            }
            break;
        case 0x389:
            if (event->game.mode == 1) {
                if (tmevGetFlag(player + 0x3E) == 0) {
                    tmevSetFlag(player + 0x3E, 1);
                    tmevSetViewAngle(1.4f, player);
                }
            }
            break;
        case 0x386:
        case 0x38A:
            if (event->game.mode == 1) {
                if (tmevGetFlag(player + 0x3E) == 1) {
                    tmevSetFlag(player + 0x3E, 0);
                    tmevSetViewAngle(-1.0f, player);
                }
            }
            break;
        }
    }
}

