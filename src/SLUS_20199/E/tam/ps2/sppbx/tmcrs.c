typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;
typedef unsigned int u_int;
typedef __int128 int128;
typedef __int128 s128;
typedef unsigned __int128 u_int128;

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on
#pragma fast_fptosi on // Emit cvt.w.s inline instead of calling __fixsfdi/fptosi. // Allows conversion from matrix to float** and vector to float* types.

// SCE types ///////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__ ((aligned(16)));
typedef int sceVu0IMATRIX[4][4] __attribute__ ((aligned(16)));
typedef float sceVu0FVECTOR[4] __attribute__ ((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__ ((aligned(16)));

// Size: 0x10, DWARF: 0x41DA5
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0, DWARF: 0x41DC4
    unsigned char mark; // Offset: 0x2, DWARF: 0x41DE4
    unsigned char id; // Offset: 0x3, DWARF: 0x41E05
    struct _sceDmaTag* next; // Offset: 0x4, DWARF: 0x41E24
    unsigned int p[2]; // Offset: 0x8, DWARF: 0x41E4A
} _sceDmaTag;

void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);

// Static data /////////////////////////////////////////////////////////

//////// vspRider Struct ///////////////////////////////////////////////
// Last updated: 08/14/2024

// Size: 0x30, DWARF: 0x7DAC1, 0x1C06F9, 0x43519
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

// Size: 0x60, DWARF: 0x75E44, 0x42032
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
    float rail_pos[4] __attribute__((aligned(16))); // Offset: 0x330, DWARF: 0x772F6
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
    float hp_normal[4]; // Offset: 0x3A0, DWARF: 0x77641
    float hp_cross[4]; // Offset: 0x3B0, DWARF: 0x77669
    signed int manual_ready; // Offset: 0x3C0, DWARF: 0x77690
    signed int manual_ready_no; // Offset: 0x3C4, DWARF: 0x776B9
    signed int manual_cnt_to_play; // Offset: 0x3C8, DWARF: 0x776E5
    // Size: 0x14, DWARF: 0x7C447
    Balance manu_balance; // Offset: 0x3CC, DWARF: 0x77714
    signed int manu_reset_lean; // Offset: 0x3E0, DWARF: 0x7773F
    signed int bonk_ready; // Offset: 0x3E4, DWARF: 0x7776B
    signed int bonk_ready_no; // Offset: 0x3E8, DWARF: 0x77792
    signed int bonk_goto; // Offset: 0x3EC, DWARF: 0x777BC
    float bonk_point[4]; // Offset: 0x3F0, DWARF: 0x777E2
    float bonk_presp[4]; // Offset: 0x400, DWARF: 0x7780B
    signed int revert_cnt_ready; // Offset: 0x410, DWARF: 0x77834
    signed int revert_ready_no; // Offset: 0x414, DWARF: 0x77861
    signed int plant_air; // Offset: 0x418, DWARF: 0x7788D
    float plant_normal[4] __attribute__((aligned(16))); // Offset: 0x420, DWARF: 0x778B3
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
    float pos_waist[4] __attribute__((aligned(16))); // Offset: 0x460, DWARF: 0x77A46
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
    float mot_flip_rot[4] __attribute__((aligned(16))); // Offset: 0x520, DWARF: 0x77E15
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
    float balance_pole[4] __attribute__((aligned(16))); // Offset: 0x6B0, DWARF: 0x78298
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
    float mat_head[4][4]; // Offset: 0x1C30, DWARF: 0x7863B
    float mat_hip[4][4]; // Offset: 0x1C70, DWARF: 0x78662
    // Size: 0x60, DWARF: 0x75E44
    Col col_rail; // Offset: 0x1CB0, DWARF: 0x78688
    // Size: 0x60, DWARF: 0x75E44
    Col col_plant; // Offset: 0x1D10, DWARF: 0x786AF
    // Size: 0x60, DWARF: 0x75E44
    Col col_hp; // Offset: 0x1D70, DWARF: 0x786D7
    // Size: 0x60, DWARF: 0x75E44
    Col col_zhp; // Offset: 0x1DD0, DWARF: 0x786FC
    float recover_pos[4]; // Offset: 0x1E30, DWARF: 0x78722
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

// Size: 0x140, DWARF: 0x16DBF7, 0x4BFF1
typedef struct Matrix
{
    sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x16DC13
    sceVu0FMATRIX local_light; // Offset: 0x40, DWARF: 0x16DC3E
    sceVu0FMATRIX light_color; // Offset: 0x80, DWARF: 0x16DC68
    sceVu0FMATRIX local_clip; // Offset: 0xC0, DWARF: 0x16DC92
    sceVu0FMATRIX clip_screen; // Offset: 0x100, DWARF: 0x16DCBB
} Matrix;

// Size: 0x20, DWARF: 0x16D961, 0x4C173
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
    float world_screen[4][4]; // Offset: 0x190, DWARF: 0x167E7E
    float world_view[4][4]; // Offset: 0x1D0, DWARF: 0x167EA9
    float view_screen[4][4]; // Offset: 0x210, DWARF: 0x167ED2
    float light_color[4][4]; // Offset: 0x250, DWARF: 0x167EFC
    float normal_light[4][4]; // Offset: 0x290, DWARF: 0x167F26
    float view_clip[4][4]; // Offset: 0x2D0, DWARF: 0x167F51
    float cam_rot[4]; // Offset: 0x310, DWARF: 0x167F79
    float cam_trans[4]; // Offset: 0x320, DWARF: 0x167F9F
    float view_angle; // Offset: 0x330, DWARF: 0x167FC7
} SysMat;

// Size: 0x24, DWARF: 0x167A72, 0x4297F
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

// Size: 0x190, DWARF: 0x1677E9
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

// Size: 0x2C00, DWARF: 0x16AA87, 0xBAAA7
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

// Size: 0x10, DWARF: 0x813DF, 0xBCA3C, PosAddress
typedef struct PosAddress //: const volatile float[4]
{
    unsigned int type; // Offset: 0x0, DWARF: 0xBCA58
    float frame; // Offset: 0x4, DWARF: 0xBCA79
    signed short flg; // Offset: 0x8, DWARF: 0xBCA9B
    signed short non; // Offset: 0xA, DWARF: 0xBCABB
    float* data[4]; // Offset: 0xC, DWARF: 0xBCADB
} PosAddress;

// Size: 0x140, DWARF: 0x7DA36, 0x4FC97
typedef struct Wind
{
    signed int count[8][3] __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x7DA52
    signed int speed[8][3]; // Offset: 0x60, DWARF: 0x7DA76
    float wave[8][4]; // Offset: 0xC0, DWARF: 0x7DA9A
} Wind;

// Size: 0x8, DWARF: 0x7E8D5, 0x5033E
typedef struct EnvFog
{
    float a; // Offset: 0x0, DWARF: 0x7E8F1
    float b; // Offset: 0x4, DWARF: 0x7E90F
} EnvFog;

// Size: 0xF0, DWARF: 0x80315, 0xBB2C0, 0x4A20A
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
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0xBB5B6
    float pos[4]; // Offset: 0xA0, DWARF: 0xBB5DF
    float quat[4]; // Offset: 0xB0, DWARF: 0xBB601
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0xBB624
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0xBB64A
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0xBB670
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0xBB69B
    signed int pad[2]; // Offset: 0xE8, DWARF: 0xBB6C5
} Seq;

// Size: 0x8, DWARF: 0x7EB45, EnvMap
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
    float matrix[4][4]; // Offset: 0x30, DWARF: 0x7CF9F
    float revision[4][4]; // Offset: 0x70, DWARF: 0x7CFC4
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
    float original[4][4]; // Offset: 0x0, DWARF: 0x7BEB5
    float original2[4][4]; // Offset: 0x40, DWARF: 0x7BEDC
    float* address[4][4]; // Offset: 0x80, DWARF: 0x7BF04
    float* address2[4][4]; // Offset: 0x84, DWARF: 0x7BF2D
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
    float mat_base_lw[4][4]; // Offset: 0x28F0, DWARF: 0x7FE6D
    float mat_board[4][4]; // Offset: 0x2930, DWARF: 0x7FE97
    float mat_hand_l[4][4]; // Offset: 0x2970, DWARF: 0x7FEBF
    float mat_hand_r[4][4]; // Offset: 0x29B0, DWARF: 0x7FEE8
    float mat_head[4][4]; // Offset: 0x29F0, DWARF: 0x7FF11
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

// tmcrs.c structs ////////////////////////////////////////////////////

// Size: 0x90, DWARF: 0x41F14
typedef struct tag_ulcodCOORDINATE
{
    struct tag_ulcodCOORDINATE* super; // Offset: 0x0, DWARF: 0x41F3C
    unsigned int flag; // Offset: 0x4, DWARF: 0x41F63
    unsigned int id; // Offset: 0x8, DWARF: 0x41F84
    signed int parent; // Offset: 0xC, DWARF: 0x41FA3
    float mat[4][4]; // Offset: 0x10, DWARF: 0x41FC6
    float tmp[4][4]; // Offset: 0x50, DWARF: 0x41FE8
} tag_ulcodCOORDINATE;

// Size: 0x10, DWARF: 0x44340
typedef struct Collision
{
    signed int num; // Offset: 0x0, DWARF: 0x4435C
    signed int nvertex; // Offset: 0x4, DWARF: 0x4437C
    unsigned short type; // Offset: 0x8, DWARF: 0x443A0
    unsigned short no; // Offset: 0xA, DWARF: 0x443C1
    signed int flag; // Offset: 0xC, DWARF: 0x443E0
} Collision;

// Size: 0x60, DWARF: 0x42032
// typedef struct Col
// {
//     float normal[4]; // Offset: 0x0, DWARF: 0x4204D
//     float point[4]; // Offset: 0x10, DWARF: 0x42072
//     float* vertex[4]; // Offset: 0x20, DWARF: 0x42096
//     unsigned int attr; // Offset: 0x24, DWARF: 0x420BE
//     signed int nvertex; // Offset: 0x28, DWARF: 0x420DF
//     signed int no; // Offset: 0x2C, DWARF: 0x42103
//     float len; // Offset: 0x30, DWARF: 0x42122
//     signed int rail_no; // Offset: 0x34, DWARF: 0x42142
//     signed int obj_no; // Offset: 0x38, DWARF: 0x42166
//     signed int obj_attr; // Offset: 0x3C, DWARF: 0x42189
//     signed int obj_type; // Offset: 0x40, DWARF: 0x421AE
//     signed int res[4]; // Offset: 0x44, DWARF: 0x421D3
// } Col;

// Size: 0x10, DWARF: 0x4334C
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x43368
    unsigned int addr; // Offset: 0x4, DWARF: 0x4338B
    unsigned int z; // Offset: 0x8, DWARF: 0x433AC
    unsigned int _pad; // Offset: 0xC, DWARF: 0x433CA
} ATag;

// Size: 0x20, DWARF: 0x44176
typedef struct Alpha
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0x44192
    unsigned int natag; // Offset: 0x4, DWARF: 0x441B6
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0x441D8
    unsigned int npkt; // Offset: 0xC, DWARF: 0x441FB
    // Size: 0x10, DWARF: 0x4334C
    ATag* atag; // Offset: 0x10, DWARF: 0x4421C
    // Size: 0x10, DWARF: 0x4334C
    ATag* curatag; // Offset: 0x14, DWARF: 0x44242
    __int128* pkt; // Offset: 0x18, DWARF: 0x4426B
    __int128* curpkt; // Offset: 0x1C, DWARF: 0x4428E
} Alpha;

// Size: 0x20, DWARF: 0x4225E
typedef struct Vif1Packet
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x42279
    __int128* pBase; // Offset: 0x4, DWARF: 0x422A1
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x422C6
    unsigned int* pVifCode; // Offset: 0xC, DWARF: 0x422ED
    unsigned int numlen; // Offset: 0x10, DWARF: 0x42315
    unsigned long* pGifTag; // Offset: 0x14, DWARF: 0x42338
    unsigned int pad12; // Offset: 0x18, DWARF: 0x4235F
    unsigned int pad13; // Offset: 0x1C, DWARF: 0x42381
} Vif1Packet;

// Size: 0x10, DWARF: 0x4988E
typedef struct GifPacket
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0x498AA
    __int128* pBase; // Offset: 0x4, DWARF: 0x498D2
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0x498F7
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0x4991E
} GifPacket;

// Duplicated in vspRider section
// Size: 0x20, DWARF: 0x4C173
// typedef struct Fog
// {
//     float min; // Offset: 0x0, DWARF: 0x4C18F
//     float max; // Offset: 0x4, DWARF: 0x4C1AF
//     float far; // Offset: 0x8, DWARF: 0x4C1CF
//     float near; // Offset: 0xC, DWARF: 0x4C1EF
//     signed int col[4]; // Offset: 0x10, DWARF: 0x4C210
// } Fog;

// Duplicated in vspRider section
// // Size: 0x140, DWARF: 0x4BFF1
// typedef struct Matrix
// {
//     sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x4C00D
//     sceVu0FMATRIX local_light; // Offset: 0x40, DWARF: 0x4C038
//     sceVu0FMATRIX light_color; // Offset: 0x80, DWARF: 0x4C062
//     sceVu0FMATRIX local_clip; // Offset: 0xC0, DWARF: 0x4C08C
//     sceVu0FMATRIX clip_screen; // Offset: 0x100, DWARF: 0x4C0B5
// } Matrix;

// Size: 0x30, DWARF: 0x4B2B9
typedef struct Screen
{
    float aspect_x; // Offset: 0x0, DWARF: 0x4B2D5
    float aspect_y; // Offset: 0x4, DWARF: 0x4B2FA
    float center_x; // Offset: 0x8, DWARF: 0x4B31F
    float center_y; // Offset: 0xC, DWARF: 0x4B344
    float clip_vol_x; // Offset: 0x10, DWARF: 0x4B369
    float clip_vol_y; // Offset: 0x14, DWARF: 0x4B390
    float min_z; // Offset: 0x18, DWARF: 0x4B3B7
    float max_z; // Offset: 0x1C, DWARF: 0x4B3D9
    float near_z; // Offset: 0x20, DWARF: 0x4B3FB
    float far_z; // Offset: 0x24, DWARF: 0x4B41E
    float screen_z; // Offset: 0x28, DWARF: 0x4B440
    float res; // Offset: 0x2C, DWARF: 0x4B465
} Screen;

// Size: 0x340, DWARF: 0x43A4F
typedef struct VspSystemMatrix
{
    // Size: 0x30, DWARF: 0x4B2B9
    Screen scr_info; // Offset: 0x0, DWARF: 0x43A6B
    // Size: 0x20, DWARF: 0x4C173
    Fog fog; // Offset: 0x30, DWARF: 0x43A92
    // Size: 0x140, DWARF: 0x4BFF1
    Matrix matrix; // Offset: 0x50, DWARF: 0x43AB4
    float world_screen[4][4]; // Offset: 0x190, DWARF: 0x43AD9
    float world_view[4][4]; // Offset: 0x1D0, DWARF: 0x43B04
    float view_screen[4][4]; // Offset: 0x210, DWARF: 0x43B2D
    float light_color[4][4]; // Offset: 0x250, DWARF: 0x43B57
    float normal_light[4][4]; // Offset: 0x290, DWARF: 0x43B81
    float view_clip[4][4]; // Offset: 0x2D0, DWARF: 0x43BAC
    float cam_rot[4]; // Offset: 0x310, DWARF: 0x43BD4
    float cam_trans[4]; // Offset: 0x320, DWARF: 0x43BFA
    float view_angle; // Offset: 0x330, DWARF: 0x43C22
} VspSystemMatrix;

// Duplicated in vspRider section
// Size: 0x30, DWARF: 0x43519
// typedef struct Cheats
// {
//     signed int kids; // Offset: 0x0, DWARF: 0x43535
//     signed int always_sp; // Offset: 0x4, DWARF: 0x43556
//     signed int perfect_b; // Offset: 0x8, DWARF: 0x4357C
//     signed int super_spin; // Offset: 0xC, DWARF: 0x435A2
//     signed int half_g; // Offset: 0x10, DWARF: 0x435C9
//     signed int fast_motion; // Offset: 0x14, DWARF: 0x435EC
//     signed int super_speed; // Offset: 0x18, DWARF: 0x43614
//     signed int big_head; // Offset: 0x1C, DWARF: 0x4363C
//     signed int metallic; // Offset: 0x20, DWARF: 0x43661
//     signed int mirror; // Offset: 0x24, DWARF: 0x43686
//     signed int replay_view; // Offset: 0x28, DWARF: 0x436A9
//     signed int partition; // Offset: 0x2C, DWARF: 0x436D1
// } Cheats;

// Duplicated in vspRider section
// Size: 0x24, DWARF: 0x4297F
// typedef struct Key
// {
//     signed int vibration; // Offset: 0x0, DWARF: 0x4299A
//     signed int spin_l; // Offset: 0x4, DWARF: 0x429C0
//     signed int spin_r; // Offset: 0x8, DWARF: 0x429E3
//     signed int stance; // Offset: 0xC, DWARF: 0x42A06
//     signed int revert; // Offset: 0x10, DWARF: 0x42A29
//     signed int grind; // Offset: 0x14, DWARF: 0x42A4C
//     signed int grab; // Offset: 0x18, DWARF: 0x42A6E
//     signed int jump; // Offset: 0x1C, DWARF: 0x42A8F
//     signed int flip; // Offset: 0x20, DWARF: 0x42AB0
// } Key;

// Size: 0x1C, DWARF: 0x4C4F1
typedef struct CharacterParam
{
    signed int ollie; // Offset: 0x0, DWARF: 0x4C50D
    signed int spin; // Offset: 0x4, DWARF: 0x4C52F
    signed int speed; // Offset: 0x8, DWARF: 0x4C550
    signed int landing; // Offset: 0xC, DWARF: 0x4C572
    signed int balance; // Offset: 0x10, DWARF: 0x4C596
    signed int stability; // Offset: 0x14, DWARF: 0x4C5BA
    signed int stance; // Offset: 0x18, DWARF: 0x4C5E0
} CharacterParam;

// Size: 0x10, DWARF: 0x4D1F1
typedef struct BoardParam
{
    signed int speed; // Offset: 0x0, DWARF: 0x4D20D
    signed int stability; // Offset: 0x4, DWARF: 0x4D22F
    signed int balance; // Offset: 0x8, DWARF: 0x4D255
    signed int turning; // Offset: 0xC, DWARF: 0x4D279
} BoardParam;

// Size: 0x3C, DWARF: 0x42DCB
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x42DE7
    signed int player; // Offset: 0x4, DWARF: 0x42E06
    signed int wear; // Offset: 0x8, DWARF: 0x42E29
    signed int board; // Offset: 0xC, DWARF: 0x42E4A
    // Size: 0x1C, DWARF: 0x4C4F1
    CharacterParam chr_param; // Offset: 0x10, DWARF: 0x42E6C
    // Size: 0x10, DWARF: 0x4D1F1
    BoardParam brd_param; // Offset: 0x2C, DWARF: 0x42E94
} Character;

// Size: 0x18, DWARF: 0x4E423
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x4E43F
    signed int game_mode; // Offset: 0x4, DWARF: 0x4E466
    signed int match_rule; // Offset: 0x8, DWARF: 0x4E48C
    signed int divide; // Offset: 0xC, DWARF: 0x4E4B3
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x4E4D6
} Mode;

// Size: 0x4, DWARF: 0x4E2EA
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0x4E306
} CourseNo;

// Size: 0xA0, DWARF: 0x4CB94
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x4E2EA
    CourseNo course; // Offset: 0x0, DWARF: 0x4CBB0
    // Size: 0x3C, DWARF: 0x42DCB
    Character character[2]; // Offset: 0x4, DWARF: 0x4CBD5
    // Size: 0x18, DWARF: 0x4E423
    Mode mode; // Offset: 0x7C, DWARF: 0x4CBFD
    signed int language; // Offset: 0x94, DWARF: 0x4CC20
    signed int ending; // Offset: 0x98, DWARF: 0x4CC45
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x4CC68
} VspenvGame;

// Size: 0x310, DWARF: 0x43D99
typedef struct Hit
{
    signed int counter; // Offset: 0x0, DWARF: 0x43DB5
    signed int res[3]; // Offset: 0x4, DWARF: 0x43DD9
    signed int hit[64]; // Offset: 0x10, DWARF: 0x43DFB
    signed int attr[64]; // Offset: 0x110, DWARF: 0x43E1D
    signed int base[64]; // Offset: 0x210, DWARF: 0x43E40
} Hit;

// Size: 0x364, DWARF: 0x4C83D
typedef struct VtmcrsSystem
{
    signed int crs_no; // Offset: 0x0, DWARF: 0x4C859
    signed int nblock; // Offset: 0x4, DWARF: 0x4C87C
    signed int npoly[2]; // Offset: 0x8, DWARF: 0x4C89F
    signed int nvertex[2]; // Offset: 0x10, DWARF: 0x4C8C3
    signed int auto_cnt; // Offset: 0x18, DWARF: 0x4C8E9
    signed int auto_draw; // Offset: 0x1C, DWARF: 0x4C90E
    signed int fog; // Offset: 0x20, DWARF: 0x4C934
    signed int mirror; // Offset: 0x24, DWARF: 0x4C954
    unsigned short* crs_poly[2]; // Offset: 0x28, DWARF: 0x4C977
    unsigned short* crs_vertex[2]; // Offset: 0x30, DWARF: 0x4C99E
    unsigned short* draw_block; // Offset: 0x38, DWARF: 0x4C9C7
    signed int draw_nblock; // Offset: 0x3C, DWARF: 0x4C9F1
    float draw_len; // Offset: 0x40, DWARF: 0x4CA19
    signed int mipmdl_level; // Offset: 0x44, DWARF: 0x4CA3E
    unsigned int i_counter; // Offset: 0x48, DWARF: 0x4CA67
    signed int f_counter; // Offset: 0x4C, DWARF: 0x4CA8D
    float view_angle; // Offset: 0x50, DWARF: 0x4CAB3
    // Size: 0x310, DWARF: 0x43D99
    Hit hit; // Offset: 0x54, DWARF: 0x4CADA
} VtmcrsSystem;

// Size: 0x8, DWARF: 0x43EB4
typedef struct Test
{
    unsigned long ATE : 1; // Offset: 0x0, DWARF: 0x43ED0, Bit Offset: 0, Bit Size: 1
    unsigned long ATST : 3; // Offset: 0x0, DWARF: 0x43EFA, Bit Offset: 1, Bit Size: 3
    unsigned long AREF : 8; // Offset: 0x0, DWARF: 0x43F25, Bit Offset: 4, Bit Size: 8
    unsigned long AFAIL : 2; // Offset: 0x0, DWARF: 0x43F50, Bit Offset: 12, Bit Size: 2
    unsigned long DATE : 1; // Offset: 0x0, DWARF: 0x43F7C, Bit Offset: 14, Bit Size: 1
    unsigned long DATM : 1; // Offset: 0x0, DWARF: 0x43FA7, Bit Offset: 15, Bit Size: 1
    unsigned long ZTE : 1; // Offset: 0x0, DWARF: 0x43FD2, Bit Offset: 16, Bit Size: 1
    unsigned long ZTST : 2; // Offset: 0x0, DWARF: 0x43FFC, Bit Offset: 17, Bit Size: 2
    unsigned long pad19 : 45; // Offset: 0x0, DWARF: 0x44027, Bit Offset: 19, Bit Size: 45
} Test;

// Size: 0x8, DWARF: 0x4E771
typedef struct Dthe
{
    unsigned long DTHE : 1; // Offset: 0x0, DWARF: 0x4E78D, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x4E7B8, Bit Offset: 1, Bit Size: 63
} Dthe;

// Size: 0x8, DWARF: 0x471C5
typedef struct ColClamp
{
    unsigned long CLAMP : 1; // Offset: 0x0, DWARF: 0x471E1, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x4720D, Bit Offset: 1, Bit Size: 63
} ColClamp;

// Size: 0x8, DWARF: 0x4E6D8
typedef struct PrModeCont
{
    unsigned long AC : 1; // Offset: 0x0, DWARF: 0x4E6F4, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0x4E71D, Bit Offset: 1, Bit Size: 63
} PrModeCont;

// Size: 0x8, DWARF: 0x4FB16
typedef struct Scissor
{
    unsigned long SCAX0 : 11; // Offset: 0x0, DWARF: 0x4FB33, Bit Offset: 0, Bit Size: 11
    unsigned long pad11 : 5; // Offset: 0x0, DWARF: 0x4FB5F, Bit Offset: 11, Bit Size: 5
    unsigned long SCAX1 : 11; // Offset: 0x0, DWARF: 0x4FB8B, Bit Offset: 16, Bit Size: 11
    unsigned long pad27 : 5; // Offset: 0x0, DWARF: 0x4FBB7, Bit Offset: 27, Bit Size: 5
    unsigned long SCAY0 : 11; // Offset: 0x0, DWARF: 0x4FBE3, Bit Offset: 32, Bit Size: 11
    unsigned long pad43 : 5; // Offset: 0x0, DWARF: 0x4FC0F, Bit Offset: 43, Bit Size: 5
    unsigned long SCAY1 : 11; // Offset: 0x0, DWARF: 0x4FC3B, Bit Offset: 48, Bit Size: 11
    unsigned long pad59 : 5; // Offset: 0x0, DWARF: 0x4FC67, Bit Offset: 59, Bit Size: 5
} Scissor;

// Size: 0x8, DWARF: 0x48BD1
typedef struct XYOffset
{
    unsigned long OFX : 16; // Offset: 0x0, DWARF: 0x48BED, Bit Offset: 0, Bit Size: 16
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x48C17, Bit Offset: 16, Bit Size: 16
    unsigned long OFY : 16; // Offset: 0x0, DWARF: 0x48C43, Bit Offset: 32, Bit Size: 16
    unsigned long pad48 : 16; // Offset: 0x0, DWARF: 0x48C6D, Bit Offset: 48, Bit Size: 16
} XYOffset;

// Size: 0x8, DWARF: 0x4C386
typedef struct ZBuf
{
    unsigned long ZBP : 9; // Offset: 0x0, DWARF: 0x4C3A2, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 15; // Offset: 0x0, DWARF: 0x4C3CC, Bit Offset: 9, Bit Size: 15
    unsigned long PSM : 4; // Offset: 0x0, DWARF: 0x4C3F8, Bit Offset: 24, Bit Size: 4
    unsigned long pad28 : 4; // Offset: 0x0, DWARF: 0x4C422, Bit Offset: 28, Bit Size: 4
    unsigned long ZMSK : 1; // Offset: 0x0, DWARF: 0x4C44E, Bit Offset: 32, Bit Size: 1
    unsigned long pad33 : 31; // Offset: 0x0, DWARF: 0x4C479, Bit Offset: 33, Bit Size: 31
} ZBuf;

// Size: 0x8, DWARF: 0x505B9
typedef struct Frame
{
    unsigned long FBP : 9; // Offset: 0x0, DWARF: 0x505D6, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 7; // Offset: 0x0, DWARF: 0x50600, Bit Offset: 9, Bit Size: 7
    unsigned long FBW : 6; // Offset: 0x0, DWARF: 0x5062C, Bit Offset: 16, Bit Size: 6
    unsigned long pad22 : 2; // Offset: 0x0, DWARF: 0x50656, Bit Offset: 22, Bit Size: 2
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0x50682, Bit Offset: 24, Bit Size: 6
    unsigned long pad30 : 2; // Offset: 0x0, DWARF: 0x506AC, Bit Offset: 30, Bit Size: 2
    unsigned long FBMSK : 32; // Offset: 0x0, DWARF: 0x506D8, Bit Offset: 32, Bit Size: 32
} Frame;

// Size: 0x80, DWARF: 0x4BD3F
typedef struct Draw1
{
    // Size: 0x8, DWARF: 0x505B9
    Frame frame1; // Offset: 0x0, DWARF: 0x4BD5B
    unsigned long frame1addr; // Offset: 0x8, DWARF: 0x4BD80
    // Size: 0x8, DWARF: 0x4C386
    ZBuf zbuf1; // Offset: 0x10, DWARF: 0x4BDA7
    signed long zbuf1addr; // Offset: 0x18, DWARF: 0x4BDCB
    // Size: 0x8, DWARF: 0x48BD1
    XYOffset xyoffset1; // Offset: 0x20, DWARF: 0x4BDF1
    signed long xyoffset1addr; // Offset: 0x28, DWARF: 0x4BE19
    // Size: 0x8, DWARF: 0x4FB16
    Scissor scissor1; // Offset: 0x30, DWARF: 0x4BE43
    signed long scissor1addr; // Offset: 0x38, DWARF: 0x4BE6A
    // Size: 0x8, DWARF: 0x4E6D8
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x4BE93
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x4BEBC
    // Size: 0x8, DWARF: 0x471C5
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x4BEE7
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x4BF0E
    // Size: 0x8, DWARF: 0x4E771
    Dthe dthe; // Offset: 0x60, DWARF: 0x4BF37
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x4BF5A
    // Size: 0x8, DWARF: 0x43EB4
    Test test1; // Offset: 0x70, DWARF: 0x4BF7F
    signed long test1addr; // Offset: 0x78, DWARF: 0x4BFA3
} Draw1;

// Size: 0x80, DWARF: 0x4D7F0
typedef struct Draw2
{
    // Size: 0x8, DWARF: 0x505B9
    Frame frame2; // Offset: 0x0, DWARF: 0x4D80C
    unsigned long frame2addr; // Offset: 0x8, DWARF: 0x4D831
    // Size: 0x8, DWARF: 0x4C386
    ZBuf zbuf2; // Offset: 0x10, DWARF: 0x4D858
    signed long zbuf2addr; // Offset: 0x18, DWARF: 0x4D87C
    // Size: 0x8, DWARF: 0x48BD1
    XYOffset xyoffset2; // Offset: 0x20, DWARF: 0x4D8A2
    signed long xyoffset2addr; // Offset: 0x28, DWARF: 0x4D8CA
    // Size: 0x8, DWARF: 0x4FB16
    Scissor scissor2; // Offset: 0x30, DWARF: 0x4D8F4
    signed long scissor2addr; // Offset: 0x38, DWARF: 0x4D91B
    // Size: 0x8, DWARF: 0x4E6D8
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0x4D944
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0x4D96D
    // Size: 0x8, DWARF: 0x471C5
    ColClamp colclamp; // Offset: 0x50, DWARF: 0x4D998
    signed long colclampaddr; // Offset: 0x58, DWARF: 0x4D9BF
    // Size: 0x8, DWARF: 0x4E771
    Dthe dthe; // Offset: 0x60, DWARF: 0x4D9E8
    signed long dtheaddr; // Offset: 0x68, DWARF: 0x4DA0B
    // Size: 0x8, DWARF: 0x43EB4
    Test test2; // Offset: 0x70, DWARF: 0x4DA30
    signed long test2addr; // Offset: 0x78, DWARF: 0x4DA54
} Draw2;

// Size: 0x8, DWARF: 0x4C62D
typedef struct Prim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0x4C649, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0x4C674, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0x4C69E, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0x4C6C8, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0x4C6F2, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0x4C71C, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0x4C746, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0x4C770, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0x4C79B, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0x4C7C5, Bit Offset: 11, Bit Size: 53
} Prim;

// Size: 0x8, DWARF: 0x4EA5A
typedef struct RGBAQ
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x4EA76, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x4EA9E, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x4EAC6, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0x4EAEE, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0x4EB16
} RGBAQ;

// Size: 0x8, DWARF: 0x4A67F
typedef struct XYZ
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0x4A69B, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0x4A6C3, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 32; // Offset: 0x0, DWARF: 0x4A6EB, Bit Offset: 32, Bit Size: 32
} XYZ;

// Size: 0x10, DWARF: 0x477A5
typedef struct GifTag
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0x477C1, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0x477ED, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0x47817, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0x47843, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0x4786C, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0x47896, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0x478C1, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0x478EB, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0x47916, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0x47942, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0x4796E, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0x4799A, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0x479C6, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0x479F2, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0x47A1E, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0x47A4A, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0x47A76, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0x47AA2, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0x47ACE, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0x47AFB, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0x47B28, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0x47B55, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0x47B82, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0x47BAF, Bit Offset: 60, Bit Size: 4
} GifTag;

// Size: 0x60, DWARF: 0x4F1ED
typedef struct Clear
{
    // Size: 0x8, DWARF: 0x43EB4
    Test testa; // Offset: 0x0, DWARF: 0x4F209
    signed long testaaddr; // Offset: 0x8, DWARF: 0x4F22D
    // Size: 0x8, DWARF: 0x4C62D
    Prim prim; // Offset: 0x10, DWARF: 0x4F253
    signed long primaddr; // Offset: 0x18, DWARF: 0x4F276
    // Size: 0x8, DWARF: 0x4EA5A
    RGBAQ rgbaq; // Offset: 0x20, DWARF: 0x4F29B
    signed long rgbaqaddr; // Offset: 0x28, DWARF: 0x4F2BF
    // Size: 0x8, DWARF: 0x4A67F
    XYZ xyz2a; // Offset: 0x30, DWARF: 0x4F2E5
    signed long xyz2aaddr; // Offset: 0x38, DWARF: 0x4F309
    // Size: 0x8, DWARF: 0x4A67F
    XYZ xyz2b; // Offset: 0x40, DWARF: 0x4F32F
    signed long xyz2baddr; // Offset: 0x48, DWARF: 0x4F353
    // Size: 0x8, DWARF: 0x43EB4
    Test testb; // Offset: 0x50, DWARF: 0x4F379
    signed long testbaddr; // Offset: 0x58, DWARF: 0x4F39D
} Clear;

// Size: 0x8, DWARF: 0x4C25C
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0x4C278, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0x4C2A0, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0x4C2C8, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, DWARF: 0x4C2F0, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4, DWARF: 0x4C319
} BgColor;

// Size: 0x8, DWARF: 0x4B0E4
typedef struct Display
{
    unsigned int DX : 12; // Offset: 0x0, DWARF: 0x4B100, Bit Offset: 0, Bit Size: 12
    unsigned int DY : 11; // Offset: 0x0, DWARF: 0x4B129, Bit Offset: 12, Bit Size: 11
    unsigned int MAGH : 4; // Offset: 0x0, DWARF: 0x4B152, Bit Offset: 23, Bit Size: 4
    unsigned int MAGV : 2; // Offset: 0x0, DWARF: 0x4B17D, Bit Offset: 27, Bit Size: 2
    unsigned int p0 : 3; // Offset: 0x0, DWARF: 0x4B1A8, Bit Offset: 29, Bit Size: 3
    unsigned int DW : 12; // Offset: 0x4, DWARF: 0x4B1D1, Bit Offset: 0, Bit Size: 12
    unsigned int DH : 11; // Offset: 0x4, DWARF: 0x4B1FA, Bit Offset: 12, Bit Size: 11
    unsigned int p1 : 9; // Offset: 0x4, DWARF: 0x4B223, Bit Offset: 23, Bit Size: 9
} Display;

// Size: 0x8, DWARF: 0x43722
typedef struct DispFb
{
    unsigned int FBP : 9; // Offset: 0x0, DWARF: 0x4373E, Bit Offset: 0, Bit Size: 9
    unsigned int FBW : 6; // Offset: 0x0, DWARF: 0x43768, Bit Offset: 9, Bit Size: 6
    unsigned int PSM : 5; // Offset: 0x0, DWARF: 0x43792, Bit Offset: 15, Bit Size: 5
    unsigned int p0 : 12; // Offset: 0x0, DWARF: 0x437BC, Bit Offset: 20, Bit Size: 12
    unsigned int DBX : 11; // Offset: 0x4, DWARF: 0x437E5, Bit Offset: 0, Bit Size: 11
    unsigned int DBY : 11; // Offset: 0x4, DWARF: 0x4380F, Bit Offset: 11, Bit Size: 11
    unsigned int p1 : 10; // Offset: 0x4, DWARF: 0x43839, Bit Offset: 22, Bit Size: 10
} DispFb;

// Size: 0x8, DWARF: 0x485F6
typedef struct SMode
{
    unsigned int INT : 1; // Offset: 0x0, DWARF: 0x48612, Bit Offset: 0, Bit Size: 1
    unsigned int FFMD : 1; // Offset: 0x0, DWARF: 0x4863C, Bit Offset: 1, Bit Size: 1
    unsigned int DPMS : 2; // Offset: 0x0, DWARF: 0x48667, Bit Offset: 2, Bit Size: 2
    unsigned int p0 : 28; // Offset: 0x0, DWARF: 0x48692, Bit Offset: 4, Bit Size: 28
    unsigned int p1; // Offset: 0x4, DWARF: 0x486BB
} SMode;

// Size: 0x8, DWARF: 0x5074A
typedef struct PMode
{
    unsigned int EN1 : 1; // Offset: 0x0, DWARF: 0x50767, Bit Offset: 0, Bit Size: 1
    unsigned int EN2 : 1; // Offset: 0x0, DWARF: 0x50791, Bit Offset: 1, Bit Size: 1
    unsigned int CRTMD : 3; // Offset: 0x0, DWARF: 0x507BB, Bit Offset: 2, Bit Size: 3
    unsigned int MMOD : 1; // Offset: 0x0, DWARF: 0x507E7, Bit Offset: 5, Bit Size: 1
    unsigned int AMOD : 1; // Offset: 0x0, DWARF: 0x50812, Bit Offset: 6, Bit Size: 1
    unsigned int SLBG : 1; // Offset: 0x0, DWARF: 0x5083D, Bit Offset: 7, Bit Size: 1
    unsigned int ALP : 8; // Offset: 0x0, DWARF: 0x50868, Bit Offset: 8, Bit Size: 8
    unsigned int p0 : 16; // Offset: 0x0, DWARF: 0x50892, Bit Offset: 16, Bit Size: 16
    unsigned int p1; // Offset: 0x4, DWARF: 0x508BB
} PMode;

// Size: 0x28, DWARF: 0x4A7D2
typedef struct Disp_Type
{
    // Size: 0x8, DWARF: 0x5074A
    PMode pmode; // Offset: 0x0, DWARF: 0x4A7EE
    // Size: 0x8, DWARF: 0x485F6
    SMode smode2; // Offset: 0x8, DWARF: 0x4A812
    // Size: 0x8, DWARF: 0x43722
    DispFb dispfb; // Offset: 0x10, DWARF: 0x4A837
    // Size: 0x8, DWARF: 0x4B0E4
    Display display; // Offset: 0x18, DWARF: 0x4A85C
    // Size: 0x8, DWARF: 0x4C25C
    BgColor bgcolor; // Offset: 0x20, DWARF: 0x4A882
} Disp_Type;

// Size: 0x330, DWARF: 0x431BB
typedef struct DBuff
{
    // Size: 0x28, DWARF: 0x4A7D2
    Disp_Type disp[2]; // Offset: 0x0, DWARF: 0x431D7
    // Size: 0x10, DWARF: 0x477A5
    GifTag giftag0; // Offset: 0x50, DWARF: 0x431FA
    // Size: 0x80, DWARF: 0x4BD3F
    Draw1 draw01; // Offset: 0x60, DWARF: 0x43220
    // Size: 0x80, DWARF: 0x4D7F0
    Draw2 draw02; // Offset: 0xE0, DWARF: 0x43245
    // Size: 0x60, DWARF: 0x4F1ED
    Clear clear0; // Offset: 0x160, DWARF: 0x4326A
    // Size: 0x10, DWARF: 0x477A5
    struct
    GifTag giftag1; // Offset: 0x1C0, DWARF: 0x4328F
    // Size: 0x80, DWARF: 0x4BD3F
    Draw1 draw11; // Offset: 0x1D0, DWARF: 0x432B5
    // Size: 0x80, DWARF: 0x4D7F0
    Draw2 draw12; // Offset: 0x250, DWARF: 0x432DA
    // Size: 0x60, DWARF: 0x4F1ED
    Clear clear1; // Offset: 0x2D0, DWARF: 0x432FF
} DBuff;

// Size: 0x4, DWARF: 0x4F3ED
typedef struct Chcr
{
    unsigned int DIR : 1; // Offset: 0x0, DWARF: 0x4F409, Bit Offset: 0, Bit Size: 1
    unsigned int p0 : 1; // Offset: 0x0, DWARF: 0x4F433, Bit Offset: 1, Bit Size: 1
    unsigned int MOD : 2; // Offset: 0x0, DWARF: 0x4F45C, Bit Offset: 2, Bit Size: 2
    unsigned int ASP : 2; // Offset: 0x0, DWARF: 0x4F486, Bit Offset: 4, Bit Size: 2
    unsigned int TTE : 1; // Offset: 0x0, DWARF: 0x4F4B0, Bit Offset: 6, Bit Size: 1
    unsigned int TIE : 1; // Offset: 0x0, DWARF: 0x4F4DA, Bit Offset: 7, Bit Size: 1
    unsigned int STR : 1; // Offset: 0x0, DWARF: 0x4F504, Bit Offset: 8, Bit Size: 1
    unsigned int p1 : 7; // Offset: 0x0, DWARF: 0x4F52E, Bit Offset: 9, Bit Size: 7
    unsigned int TAG : 16; // Offset: 0x0, DWARF: 0x4F557, Bit Offset: 16, Bit Size: 16
} Chcr;

// Size: 0x90, DWARF: 0x48007
typedef struct DmaVif
{
    // Size: 0x4, DWARF: 0x4F3ED
    Chcr chcr; // Offset: 0x0, DWARF: 0x48023
    unsigned int p0[3]; // Offset: 0x4, DWARF: 0x48046
    void* madr; // Offset: 0x10, DWARF: 0x48067
    unsigned int p1[3]; // Offset: 0x14, DWARF: 0x4808B
    unsigned int qwc; // Offset: 0x20, DWARF: 0x480AC
    unsigned int p2[3]; // Offset: 0x24, DWARF: 0x480CC
    _sceDmaTag* tadr; // Offset: 0x30, DWARF: 0x480ED
    unsigned int p3[3]; // Offset: 0x34, DWARF: 0x48113
    void* as0; // Offset: 0x40, DWARF: 0x48134
    unsigned int p4[3]; // Offset: 0x44, DWARF: 0x48157
    void* as1; // Offset: 0x50, DWARF: 0x48178
    unsigned int p5[3]; // Offset: 0x54, DWARF: 0x4819B
    unsigned int p6[4]; // Offset: 0x60, DWARF: 0x481BC
    unsigned int p7[4]; // Offset: 0x70, DWARF: 0x481DD
    void* sadr; // Offset: 0x80, DWARF: 0x481FE
    unsigned int p8[3]; // Offset: 0x84, DWARF: 0x48222
} DmaVif;

// Size: 0x360, DWARF: 0x4839D
typedef struct VulsysSystem
{
    unsigned int KeepMemSize; // Offset: 0x0, DWARF: 0x483B9
    signed int Pal; // Offset: 0x4, DWARF: 0x483E1
    signed int Interlace; // Offset: 0x8, DWARF: 0x48401
    signed short ScreenMode; // Offset: 0xC, DWARF: 0x48427
    signed short ScreenWidth; // Offset: 0xE, DWARF: 0x4844E
    signed short ScreenHeight; // Offset: 0x10, DWARF: 0x48476
    signed short ScreenYofs; // Offset: 0x12, DWARF: 0x4849F
    signed int EvenOdd; // Offset: 0x14, DWARF: 0x484C6
    unsigned long Frame; // Offset: 0x18, DWARF: 0x484EA
    signed int PadInit; // Offset: 0x20, DWARF: 0x4850C
    // Size: 0x90, DWARF: 0x48007
    DmaVif* DmaGif; // Offset: 0x24, DWARF: 0x48530
    // Size: 0x90, DWARF: 0x48007
    DmaVif* DmaVif0; // Offset: 0x28, DWARF: 0x48558
    // Size: 0x90, DWARF: 0x48007
    DmaVif* DmaVif1; // Offset: 0x2C, DWARF: 0x48581
    // Size: 0x330, DWARF: 0x431BB
    DBuff DBuff; // Offset: 0x30, DWARF: 0x485AA
} VulsysSystem;

// Size: 0x10, DWARF: 0x48247
typedef struct TexData
{
    signed short tofs; // Offset: 0x0, DWARF: 0x48263
    signed short cofs; // Offset: 0x2, DWARF: 0x48284
    signed short width; // Offset: 0x4, DWARF: 0x482A5
    signed short height; // Offset: 0x6, DWARF: 0x482C7
    signed short tw; // Offset: 0x8, DWARF: 0x482EA
    signed short th; // Offset: 0xA, DWARF: 0x48309
    signed short image_bit; // Offset: 0xC, DWARF: 0x48328
    signed short clut_bit; // Offset: 0xE, DWARF: 0x4834E
} TexData;

// Size: 0x20, DWARF: 0x44578
typedef struct Texture
{
    signed int offset; // Offset: 0x0, DWARF: 0x44594
    signed int ntex; // Offset: 0x4, DWARF: 0x445B7
    signed int nblock; // Offset: 0x8, DWARF: 0x445D8
    signed int mipmap_level; // Offset: 0xC, DWARF: 0x445FB
    signed int mipmap; // Offset: 0x10, DWARF: 0x44624
    unsigned int* frame; // Offset: 0x14, DWARF: 0x44647
    unsigned int* addr; // Offset: 0x18, DWARF: 0x4466C
    // Size: 0x10, DWARF: 0x48247
    TexData* data; // Offset: 0x1C, DWARF: 0x44690
} Texture;

// Size: 0x1070, DWARF: 0x48702
typedef struct VtmcrsTexSystem
{
    // Size: 0x20, DWARF: 0x44578
    Texture base[10]; // Offset: 0x0, DWARF: 0x4871E
    // Size: 0x20, DWARF: 0x44578
    Texture draw[10]; // Offset: 0x140, DWARF: 0x48741
    // Size: 0x20, DWARF: 0x44578
    Texture object[96]; // Offset: 0x280, DWARF: 0x48764
    signed int object_alpha[96]; // Offset: 0xE80, DWARF: 0x48789
    // Size: 0x20, DWARF: 0x44578
    Texture alpha; // Offset: 0x1000, DWARF: 0x487B4
    signed int nbase; // Offset: 0x1020, DWARF: 0x487D8
    signed int ndraw; // Offset: 0x1024, DWARF: 0x487FA
    signed int nobject; // Offset: 0x1028, DWARF: 0x4881C
    signed int nevent; // Offset: 0x102C, DWARF: 0x48840
    signed int intc_handle; // Offset: 0x1030, DWARF: 0x48863
    signed int dmac_handle; // Offset: 0x1034, DWARF: 0x4888B
    signed int vif1; // Offset: 0x1038, DWARF: 0x488B3
    signed int gif; // Offset: 0x103C, DWARF: 0x488D4
    signed int tri_mipmap; // Offset: 0x1040, DWARF: 0x488F4
    signed int tex_no; // Offset: 0x1044, DWARF: 0x4891B
    signed int flag; // Offset: 0x1048, DWARF: 0x4893E
    signed int mipmap[2]; // Offset: 0x104C, DWARF: 0x4895F
    signed int mipmap_level[2]; // Offset: 0x1054, DWARF: 0x48984
    signed int mipmap_process; // Offset: 0x105C, DWARF: 0x489AF
    signed int coef; // Offset: 0x1060, DWARF: 0x489DA
    signed int shift; // Offset: 0x1064, DWARF: 0x489FB
    signed int scroll_num; // Offset: 0x1068, DWARF: 0x48A1D
    signed int anim_num; // Offset: 0x106C, DWARF: 0x48A44
} VtmcrsTexSystem;

// Size: 0x10, DWARF: 0x4F934
typedef struct RailDataHead
{
    float ver; // Offset: 0x0, DWARF: 0x4F951
    signed int crs_no; // Offset: 0x4, DWARF: 0x4F971
    signed int num; // Offset: 0x8, DWARF: 0x4F994
    signed int res; // Offset: 0xC, DWARF: 0x4F9B4
} RailDataHead;

// Size: 0x10, DWARF: 0x4F837
typedef struct VtmcrsRailData
{
    unsigned int top_addr; // Offset: 0x0, DWARF: 0x4F854
    // Size: 0x10, DWARF: 0x4F934
    RailDataHead* head; // Offset: 0x4, DWARF: 0x4F879
    signed int* collision; // Offset: 0x8, DWARF: 0x4F89F
    signed int res; // Offset: 0xC, DWARF: 0x4F8C8
} VtmcrsRailData;

// Size: 0x10, DWARF: 0x4D31E
typedef struct ModelHeadData
{
    float ver; // Offset: 0x0, DWARF: 0x4D33A
    signed short crs_no; // Offset: 0x4, DWARF: 0x4D35A
    signed short nblock; // Offset: 0x6, DWARF: 0x4D37D
    signed short size_x; // Offset: 0x8, DWARF: 0x4D3A0
    signed short size_y; // Offset: 0xA, DWARF: 0x4D3C3
    signed short offset_x; // Offset: 0xC, DWARF: 0x4D3E6
    signed short offset_y; // Offset: 0xE, DWARF: 0x4D40B
} ModelHeadData;

// Size: 0x10, DWARF: 0x4FD23
typedef struct VtmcrsBonkData
{
    unsigned int top_addr; // Offset: 0x0, DWARF: 0x4FD40
    // Size: 0x10, DWARF: 0x4D31E
    ModelHeadData* head; // Offset: 0x4, DWARF: 0x4FD65
    unsigned int* block; // Offset: 0x8, DWARF: 0x4FD8B
    signed int res; // Offset: 0xC, DWARF: 0x4FDB0
} VtmcrsBonkData;

// Size: 0x10, DWARF: 0x4F082
typedef struct VtmcrsVectorData
{
    unsigned int top_addr; // Offset: 0x0, DWARF: 0x4F09E
    // Size: 0x10, DWARF: 0x4D31E
    ModelHeadData* head; // Offset: 0x4, DWARF: 0x4F0C3
    unsigned int* block; // Offset: 0x8, DWARF: 0x4F0E9
    signed int res; // Offset: 0xC, DWARF: 0x4F10E
} VtmcrsVectorData;

// Size: 0x10, DWARF: 0x4E80C
typedef struct VtmcrsHitData
{
    unsigned int top_addr; // Offset: 0x0, DWARF: 0x4E828
    // Size: 0x10, DWARF: 0x4D31E
    ModelHeadData* head; // Offset: 0x4, DWARF: 0x4E84D
    unsigned int* block; // Offset: 0x8, DWARF: 0x4E873
    signed int res; // Offset: 0xC, DWARF: 0x4E898
} VtmcrsHitData;

// Size: 0x10, DWARF: 0x4E329
typedef struct VtmcrsModel
{
    unsigned int top_addr; // Offset: 0x0, DWARF: 0x4E345
    // Size: 0x10, DWARF: 0x4D31E
    ModelHeadData* head; // Offset: 0x4, DWARF: 0x4E36A
    unsigned int* block; // Offset: 0x8, DWARF: 0x4E390
    signed int res; // Offset: 0xC, DWARF: 0x4E3B5
} VtmcrsModel;

// Size: 0x20, DWARF: 0x46FE0
typedef struct ObjectHeadData
{
    float ver; // Offset: 0x0, DWARF: 0x46FFC
    signed short crs_no; // Offset: 0x4, DWARF: 0x4701C
    signed short nblock; // Offset: 0x6, DWARF: 0x4703F
    signed short size_x; // Offset: 0x8, DWARF: 0x47062
    signed short size_y; // Offset: 0xA, DWARF: 0x47085
    signed short offset_x; // Offset: 0xC, DWARF: 0x470A8
    signed short offset_y; // Offset: 0xE, DWARF: 0x470CD
    signed int ntype; // Offset: 0x10, DWARF: 0x470F2
    signed int num; // Offset: 0x14, DWARF: 0x47114
    signed int data; // Offset: 0x18, DWARF: 0x47134
    signed int ndata; // Offset: 0x1C, DWARF: 0x47155
} ObjectHeadData;

// Size: 0x10, DWARF: 0x41E92
typedef struct Data
{
    signed int num; // Offset: 0x0, DWARF: 0x41EAD
    signed int size; // Offset: 0x4, DWARF: 0x41ECD
    signed int res[2]; // Offset: 0x8, DWARF: 0x41EEE
} Data;

// Size: 0x20, DWARF: 0x442B8
typedef struct Bounds
{
    float max[4]; // Offset: 0x0, DWARF: 0x442D4
    float min[4]; // Offset: 0x10, DWARF: 0x442F6
} Bounds;

// Size: 0x10, DWARF: 0x4395D
typedef struct TexBody
{
    signed long tex_id; // Offset: 0x0, DWARF: 0x43979
    signed short nprim; // Offset: 0x8, DWARF: 0x4399C
    unsigned short size; // Offset: 0xA, DWARF: 0x439BE
    unsigned short attr; // Offset: 0xC, DWARF: 0x439DF
    signed short alpha; // Offset: 0xE, DWARF: 0x43A00
} TexBody;

// Size: 0x10, DWARF: 0x44057
typedef struct Prim2
{
    signed int nvertex; // Offset: 0x0, DWARF: 0x44073
    signed int flag; // Offset: 0x4, DWARF: 0x44097
    signed int res[2]; // Offset: 0x8, DWARF: 0x440B8
} Prim2;

// Size: 0x30, DWARF: 0x44405
typedef struct Vertex
{
    float vertex[4]; // Offset: 0x0, DWARF: 0x44421
    float stq[4]; // Offset: 0x10, DWARF: 0x44446
    signed int rgba[4]; // Offset: 0x20, DWARF: 0x44468
} Vertex;

// Size: 0xC, DWARF: 0x433EF
typedef struct HitRes
{
    // Size: 0x60, DWARF: 0x42032
    Col** collision; // Offset: 0x0, DWARF: 0x4340B
    signed int* ret; // Offset: 0x4, DWARF: 0x43437
    // Size: 0x310, DWARF: 0x43D99
    Hit* hit; // Offset: 0x8, DWARF: 0x4345A
} HitRes;

// Size: 0x330, DWARF: 0x46F48
typedef struct BaseRes
{
    // Size: 0x60, DWARF: 0x42032
    Col collisions[8]; // Offset: 0x0, DWARF: 0x46F64
    signed int rets[8]; // Offset: 0x300, DWARF: 0x46F8D
    // Size: 0x20, DWARF: 0x442B8
    Bounds* firstBound; // Offset: 0x320, DWARF: 0x46FB0
} BaseRes;

// Size: 0x30, DWARF: 0x4243D
typedef struct CourseParam
{
    // Size: 0x30, DWARF: 0x4B2B9
    Screen* screen; // Offset: 0x0, DWARF: 0x42458
    // Size: 0x140, DWARF: 0x4BFF1
    Matrix* matrix; // Offset: 0x4, DWARF: 0x42480
    // Size: 0x20, DWARF: 0x4C173
    Fog* fog; // Offset: 0x8, DWARF: 0x424A8
    sceVu0FVECTOR* camera_position; // Offset: 0xC, DWARF: 0x424CD
    sceVu0FVECTOR* camera_rotation; // Offset: 0x10, DWARF: 0x424FE
    // Size: 0x10, DWARF: 0x4988E
    GifPacket* gif_packet; // Offset: 0x14, DWARF: 0x4252F
    // Size: 0x20, DWARF: 0x4225E
    Vif1Packet* vif1_packet; // Offset: 0x18, DWARF: 0x4255B
    // Size: 0x20, DWARF: 0x44176
    Alpha* alpha; // Offset: 0x1C, DWARF: 0x42588
    float view_angle; // Offset: 0x20, DWARF: 0x425AF
    signed int player; // Offset: 0x24, DWARF: 0x425D6
    signed int res[2]; // Offset: 0x28, DWARF: 0x425F9
} CourseParam;

// Size: 0x20, DWARF: 0x421F9
typedef struct Offset
{
    float trans[4]; // Offset: 0x0, DWARF: 0x42214
    float rot[4]; // Offset: 0x10, DWARF: 0x42238
} Offset;

// Size: 0x20, DWARF: 0x4E1A2
typedef struct GVertex
{
    void* vertex; // Offset: 0x0, DWARF: 0x4E1BE
    void* normal; // Offset: 0x4, DWARF: 0x4E1E6
    void* rgba; // Offset: 0x8, DWARF: 0x4E20E
    void* stq; // Offset: 0xC, DWARF: 0x4E234
    float width; // Offset: 0x10, DWARF: 0x4E259
    float height; // Offset: 0x14, DWARF: 0x4E27B
    signed int res[2]; // Offset: 0x18, DWARF: 0x4E29E
} GVertex;

// Size: 0x30, DWARF: 0x4E928
typedef struct GPrim
{
    unsigned long prim; // Offset: 0x0, DWARF: 0x4E944
    unsigned long tex; // Offset: 0x8, DWARF: 0x4E965
    unsigned long tex1; // Offset: 0x10, DWARF: 0x4E985
    unsigned long alpha; // Offset: 0x18, DWARF: 0x4E9A6
    unsigned long test; // Offset: 0x20, DWARF: 0x4E9C8
    unsigned int scissor; // Offset: 0x28, DWARF: 0x4E9E9
    // Size: 0x20, DWARF: 0x4C173
    Fog* fog; // Offset: 0x2C, DWARF: 0x4EA0D
} GPrim;

// Size: 0x3BC, DWARF: 0x49410
typedef struct CourseData
{
    unsigned int* base_link; // Offset: 0x0, DWARF: 0x4942C
    unsigned int* draw_link; // Offset: 0x4, DWARF: 0x49455
    unsigned int* dfar_link; // Offset: 0x8, DWARF: 0x4947E
    unsigned int* dnear_link; // Offset: 0xC, DWARF: 0x494A7
    unsigned int* butd_link; // Offset: 0x10, DWARF: 0x494D1
    unsigned int* dutd_link; // Offset: 0x14, DWARF: 0x494FA
    unsigned int* outd_link; // Offset: 0x18, DWARF: 0x49523
    unsigned int* base[10]; // Offset: 0x1C, DWARF: 0x4954C
    unsigned int* draw[10]; // Offset: 0x44, DWARF: 0x4956F
    unsigned int* dfar[10]; // Offset: 0x6C, DWARF: 0x49592
    unsigned int* dnear[10]; // Offset: 0x94, DWARF: 0x495B5
    unsigned int* base_utd[10]; // Offset: 0xBC, DWARF: 0x495D9
    unsigned int* draw_utd[10]; // Offset: 0xE4, DWARF: 0x49600
    unsigned int* object; // Offset: 0x10C, DWARF: 0x49627
    unsigned int* obj_utd[96]; // Offset: 0x110, DWARF: 0x4964D
    unsigned int* alpha; // Offset: 0x290, DWARF: 0x49673
    unsigned int* alpha_utd; // Offset: 0x294, DWARF: 0x49698
    unsigned int* bg_utd[2]; // Offset: 0x298, DWARF: 0x496C1
    __int128* bg_umd; // Offset: 0x2A0, DWARF: 0x496E6
    unsigned int* hit; // Offset: 0x2A4, DWARF: 0x4970C
    unsigned int* vector; // Offset: 0x2A8, DWARF: 0x4972F
    unsigned int* rail; // Offset: 0x2AC, DWARF: 0x49755
    unsigned int* bonk; // Offset: 0x2B0, DWARF: 0x49779
    unsigned int* event_link; // Offset: 0x2B4, DWARF: 0x4979D
    __int128* event_uad; // Offset: 0x2B8, DWARF: 0x497C7
    __int128* event_umd[32]; // Offset: 0x2BC, DWARF: 0x497F0
    unsigned int* event_utd[32]; // Offset: 0x33C, DWARF: 0x49818
} CourseData;

// Size: 0x70, DWARF: 0x4AA2B
typedef struct CourseDrawParam
{
    float pos[4]; // Offset: 0x0, DWARF: 0x4AA47
    float matrix[4][4]; // Offset: 0x10, DWARF: 0x4AA69
    signed int no; // Offset: 0x50, DWARF: 0x4AA8E
    signed int id; // Offset: 0x54, DWARF: 0x4AAAD
    float frame; // Offset: 0x58, DWARF: 0x4AACC
    signed int draw; // Offset: 0x5C, DWARF: 0x4AAEE
    signed int light; // Offset: 0x60, DWARF: 0x4AB0F
    signed int old_id; // Offset: 0x64, DWARF: 0x4AB31
    signed int cnt; // Offset: 0x68, DWARF: 0x4AB54
    signed int flag; // Offset: 0x6C, DWARF: 0x4AB74
} CourseDrawParam;

// Duplicated in vspRider section
// Size: 0x140, DWARF: 0x4FC97
// typedef struct Wind
// {
//     signed int count[8][3]; // Offset: 0x0, DWARF: 0x4FCB4
//     signed int speed[8][3]; // Offset: 0x60, DWARF: 0x4FCD8
//     float wave[8][4]; // Offset: 0xC0, DWARF: 0x4FCFC
// } Wind;

// Duplicated in vspRider section
// Size: 0x8, DWARF: 0x5033E
// typedef struct Fog2
// {
//     float a; // Offset: 0x0, DWARF: 0x5035B
//     float b; // Offset: 0x4, DWARF: 0x50379
// } Fog2;

// Duplicated in vspRider section
// Size: 0x8, DWARF: 0x50708
// typedef struct EnvMap
// {
//     unsigned long tex0; // Offset: 0x0, DWARF: 0x50725
// } EnvMap;

// Size: 0x160, DWARF: 0x4FA68
typedef struct MdlEnv
{
    unsigned int enable; // Offset: 0x0, DWARF: 0x4FA85
    // Size: 0x140, DWARF: 0x4FC97
    Wind wind; // Offset: 0x10, DWARF: 0x4FAA8
    // Size: 0x8, DWARF: 0x5033E
    EnvFog fog; // Offset: 0x150, DWARF: 0x4FACB
    // Size: 0x8, DWARF: 0x50708
    EnvMap envmap; // Offset: 0x158, DWARF: 0x4FAED
} MdlEnv;

// Size: 0x10, DWARF: 0x4D45B
typedef struct TextureGroup
{
    signed int group; // Offset: 0x0, DWARF: 0x4D477
    signed int no; // Offset: 0x4, DWARF: 0x4D499
    signed int tex_no; // Offset: 0x8, DWARF: 0x4D4B8
    // Size: 0x10, DWARF: 0x48247
    TexData* data; // Offset: 0xC, DWARF: 0x4D4DB
} TextureGroup;

// Size: 0x28, DWARF: 0x4D651
typedef struct ScrollingTextureData
{
    // Size: 0x10, DWARF: 0x4D45B
    TextureGroup src; // Offset: 0x0, DWARF: 0x4D66D
    // Size: 0x10, DWARF: 0x4D45B
    TextureGroup work; // Offset: 0x10, DWARF: 0x4D68F
    signed int scroll_x; // Offset: 0x20, DWARF: 0x4D6B2
    signed int scroll_y; // Offset: 0x24, DWARF: 0x4D6D7
} ScrollingTextureData;

// Size: 0x20, DWARF: 0x474AE
typedef struct ObjectType
{
    signed int type; // Offset: 0x0, DWARF: 0x474CA
    // Size: 0x10, DWARF: 0x41E92
    Data* draw; // Offset: 0x4, DWARF: 0x474EB
    // Size: 0x10, DWARF: 0x44340
    Collision* collision; // Offset: 0x8, DWARF: 0x47511
    // Size: 0x10, DWARF: 0x41E92
    Data* divide; // Offset: 0xC, DWARF: 0x4753C
    signed int divide_num; // Offset: 0x10, DWARF: 0x47564
    signed int bound; // Offset: 0x14, DWARF: 0x4758B
    signed int res[2]; // Offset: 0x18, DWARF: 0x475AD
} ObjectType;

// Size: 0x30, DWARF: 0x47692
typedef struct ObjectData
{
    signed int type; // Offset: 0x0, DWARF: 0x476AE
    signed int block; // Offset: 0x4, DWARF: 0x476CF
    signed short sprite; // Offset: 0x8, DWARF: 0x476F1
    signed short light; // Offset: 0xA, DWARF: 0x47714
    signed short color; // Offset: 0xC, DWARF: 0x47736
    signed short alpha; // Offset: 0xE, DWARF: 0x47758
    // Size: 0x20, DWARF: 0x421F9
    Offset position; // Offset: 0x10, DWARF: 0x4777A
} ObjectData;

// Size: 0x120, DWARF: 0x47C07
typedef struct LocalObjectData
{
    signed int draw; // Offset: 0x0, DWARF: 0x47C23
    signed int hit; // Offset: 0x4, DWARF: 0x47C44
    signed int calc; // Offset: 0x8, DWARF: 0x47C64
    signed int divide; // Offset: 0xC, DWARF: 0x47C85
    signed int bound; // Offset: 0x10, DWARF: 0x47CA8
    signed int local; // Offset: 0x14, DWARF: 0x47CCA
    signed int scissor; // Offset: 0x18, DWARF: 0x47CEC
    signed int cnt; // Offset: 0x1C, DWARF: 0x47D10
    signed int gravity; // Offset: 0x20, DWARF: 0x47D30
    signed int obj_attr; // Offset: 0x24, DWARF: 0x47D54
    sceVu0FMATRIX* divide_mat; // Offset: 0x28, DWARF: 0x47D79
    sceVu0FVECTOR* divide_trans; // Offset: 0x2C, DWARF: 0x47DA5
    sceVu0FVECTOR* divide_rot; // Offset: 0x30, DWARF: 0x47DD3
    float radius; // Offset: 0x34, DWARF: 0x47DFF
    float weight; // Offset: 0x38, DWARF: 0x47E22
    signed int bonk; // Offset: 0x3C, DWARF: 0x47E45
    sceVu0FVECTOR bonk_len; // Offset: 0x40, DWARF: 0x47E66
    float bonk_suction_len; // Offset: 0x50, DWARF: 0x47E8D
    signed int abs; // Offset: 0x54, DWARF: 0x47EBA
    signed int xyz; // Offset: 0x58, DWARF: 0x47EDA
    signed int matrix; // Offset: 0x5C, DWARF: 0x47EFA
    sceVu0FVECTOR trans; // Offset: 0x60, DWARF: 0x47F1D
    sceVu0FVECTOR rot; // Offset: 0x70, DWARF: 0x47F41
    sceVu0FVECTOR position; // Offset: 0x80, DWARF: 0x47F63
    sceVu0FVECTOR rotation; // Offset: 0x90, DWARF: 0x47F8A
    sceVu0FMATRIX local_world; // Offset: 0xA0, DWARF: 0x47FB1
    sceVu0FMATRIX local_mat; // Offset: 0xE0, DWARF: 0x47FDB
} LocalObjectData;

// Size: 0x28, DWARF: 0x44700
typedef struct VtmcrsObjectData
{
    unsigned int top_addr; // Offset: 0x0, DWARF: 0x4471C
    // Size: 0x20, DWARF: 0x46FE0
    ObjectHeadData* head; // Offset: 0x4, DWARF: 0x44741
    // Size: 0x20, DWARF: 0x474AE
    ObjectType** type; // Offset: 0x8, DWARF: 0x44767
    // Size: 0x30, DWARF: 0x47692
    ObjectData* data; // Offset: 0xC, DWARF: 0x4478E
    // Size: 0x120, DWARF: 0x47C07
    LocalObjectData* local; // Offset: 0x10, DWARF: 0x447B4
    float hit_length; // Offset: 0x14, DWARF: 0x447DB
    float draw_length; // Offset: 0x18, DWARF: 0x44802
    signed int res; // Offset: 0x1C, DWARF: 0x4482A
    signed short* nobj; // Offset: 0x20, DWARF: 0x4484A
    signed short** block; // Offset: 0x24, DWARF: 0x4486E
} VtmcrsObjectData;

// Size: 0x14, DWARF: 0x4A8F6
typedef struct VtmcrsEventSystem
{
    signed int cnt; // Offset: 0x0, DWARF: 0x4A912
    signed int res[3]; // Offset: 0x4, DWARF: 0x4A932
    // Size: 0x70, DWARF: 0x4AA2B
    CourseDrawParam* param; // Offset: 0x10, DWARF: 0x4A954
} VtmcrsEventSystem;

// Size: 0x60, DWARF: 0x4CDEB
typedef struct VtmcrsBG
{
    signed int color[4]; // Offset: 0x0, DWARF: 0x4CE07
    // Size: 0x20, DWARF: 0x44578
    Texture tex[2]; // Offset: 0x10, DWARF: 0x4CE2B
    __int128* umd; // Offset: 0x50, DWARF: 0x4CE4D
    signed int fog; // Offset: 0x54, DWARF: 0x4CE70
    signed int draw; // Offset: 0x58, DWARF: 0x4CE90
    signed int no; // Offset: 0x5C, DWARF: 0x4CEB1
} VtmcrsBG;

// Size: 0x10, DWARF: 0x4DAC6
// typedef struct Address
// {
//     unsigned int type; // Offset: 0x0, DWARF: 0x4DAE2
//     float frame; // Offset: 0x4, DWARF: 0x4DB03
//     signed short flg; // Offset: 0x8, DWARF: 0x4DB25
//     signed short non; // Offset: 0xA, DWARF: 0x4DB45
//     float* data[4]; // Offset: 0xC, DWARF: 0x4DB65
// } Address;

// Size: 0x20, DWARF: 0x4A9C7
typedef struct Mdl_Data
{
    float pos[4]; // Offset: 0x0, DWARF: 0x4A9E3
    float rot[4]; // Offset: 0x10, DWARF: 0x4AA05
} Mdl_Data;

// Size: 0x30, DWARF: 0x49A2C
typedef struct VtmcrsEventModel
{
    // Size: 0x20, DWARF: 0x44578
    Texture tex; // Offset: 0x0, DWARF: 0x49A48
    __int128* uad; // Offset: 0x20, DWARF: 0x49A6A
    __int128* umd; // Offset: 0x24, DWARF: 0x49A8D
    // Size: 0xF0, DWARF: 0x4A20A
    Seq* seq; // Offset: 0x28, DWARF: 0x49AB0
    signed int alpha; // Offset: 0x2C, DWARF: 0x49AD5
} VtmcrsEventModel;

// Size: 0x10, DWARF: 0x4D726
typedef struct TexBody2
{
    unsigned int tex_id[2]; // Offset: 0x0, DWARF: 0x4D742
    unsigned short nprim; // Offset: 0x8, DWARF: 0x4D767
    unsigned short size; // Offset: 0xA, DWARF: 0x4D789
    unsigned short attr; // Offset: 0xC, DWARF: 0x4D7AA
    unsigned short pad2; // Offset: 0xE, DWARF: 0x4D7CB
} TexBody2;

// Size: 0x10, DWARF: 0x43D12
typedef struct BonkData
{
    signed int nvertex; // Offset: 0x0, DWARF: 0x43D2E
    signed int type; // Offset: 0x4, DWARF: 0x43D52
    signed int res[2]; // Offset: 0x8, DWARF: 0x43D73
} BonkData;

// Size: 0x10, DWARF: 0x426EB
typedef struct RailData
{
    signed short left; // Offset: 0x0, DWARF: 0x42706
    signed short right; // Offset: 0x2, DWARF: 0x42727
    signed short top; // Offset: 0x4, DWARF: 0x42749
    signed short bottom; // Offset: 0x6, DWARF: 0x42769
    signed short type; // Offset: 0x8, DWARF: 0x4278C
    signed short nvertex; // Offset: 0xA, DWARF: 0x427AD
    signed short res[2]; // Offset: 0xC, DWARF: 0x427D1
} RailData;

// Size: 0x10, DWARF: 0x42643
typedef struct VectorColData
{
    signed int num; // Offset: 0x0, DWARF: 0x4265E
    signed int type; // Offset: 0x4, DWARF: 0x4267E
    signed int res[2]; // Offset: 0x8, DWARF: 0x4269F
} VectorColData;

//// Variables /////////////////////////////////////////////////////////

signed int vtmcrsDivideNum[4]; // Address: 0x307EB0
// Size: 0x1070, DWARF: 0x48702
VtmcrsTexSystem vtmcrsTexSystem; // Address: 0x306800
unsigned int ltmasmSendPrgVu0[]; // Address: 0x2A9340
// Size: 0x360, DWARF: 0x4839D
VulsysSystem vulsysSystem; // Address: 0x2F3A50
// Size: 0x364, DWARF: 0x4C83D
VtmcrsSystem vtmcrsSystem; // Address: 0x307B40
// Size: 0xA0, DWARF: 0x4CB94
VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x10, DWARF: 0x4F837
VtmcrsRailData vtmcrsRailData; // Address: 0x307880
// Size: 0x10, DWARF: 0x4E329
VtmcrsModel vtmcrsBaseModel[10]; // Address: 0x307AA0
// Size: 0x10, DWARF: 0x4E329
VtmcrsModel vtmcrsDrawModel[3][10]; // Address: 0x3078C0
// Size: 0x10, DWARF: 0x4E329
VtmcrsModel vtmcrsAlphaModel; // Address: 0x3078B0
// Size: 0x10, DWARF: 0x4E80C
VtmcrsHitData vtmcrsHitData; // Address: 0x3078A0
// Size: 0x10, DWARF: 0x4F082
VtmcrsVectorData vtmcrsVectorData; // Address: 0x307890
// Size: 0x10, DWARF: 0x4FD23
VtmcrsBonkData vtmcrsBonkData; // Address: 0x307870
signed int vgmsysPadPausePid; // Address: 0x2E7B2C
unsigned int ltmasmSendMatrix[]; // Address: 0x2AF4D0
float ltmasmPrimitive[]; // Address: 0x2AF4F8
unsigned int ltmasmSendPrgVu1NonFog[]; // Address: 0x2AB670
unsigned int ltmasmSendPrgVu1[]; // Address: 0x2A9CE0
float ltmasmClipScreenMatrix[]; // Address: 0x2AF5D0
float ltmasmLocalClipMatrix[]; // Address: 0x2AF588
float ltmasmLocalScreenMatrix[]; // Address: 0x2AF540
// Size: 0x28, DWARF: 0x44700
VtmcrsObjectData vtmcrsObjectData; // Address: 0x305D70
__int128 vtmcrsLocalPacketAddr[256]; // Address: 0x304750
// Size: 0x10, DWARF: 0x4988E
GifPacket vtmcrsLocalPacket; // Address: 0x304740
// Size: 0x14, DWARF: 0x4A8F6
VtmcrsEventSystem vtmcrsEventSystem; // Address: 0x305750
// Size: 0x30, DWARF: 0x49A2C
VtmcrsEventModel vtmcrsEventModel[32]; // Address: 0x305770
// Size: 0x28, DWARF: 0x4D651
ScrollingTextureData vtmcrsAnimTexData[32]; // Address: 0x305E00
// Size: 0x28, DWARF: 0x4D651
ScrollingTextureData vtmcrsScrollTexData[32]; // Address: 0x306300
signed int(tmcrsTexIntrFunc)(signed int); // Address: 0x1484D0
// Size: 0x60, DWARF: 0x4CDEB
VtmcrsBG vtmcrsBG; // Address: 0x305DA0
// Size: 0x340, DWARF: 0x43A4F
VspSystemMatrix vspSystemMatrix[2]; // Address: 0x3BF6B0
unsigned int ltmasmSendPrgVu1NonFogObj[]; // Address: 0x2ACE20
unsigned int ltmasmSendPrgVu1Obj[]; // Address: 0x2AE0F0
// Size: 0x5640, DWARF: 0x4388C
Rider* vspRider[8]; // Address: 0x3BD480
// Size: 0x20, DWARF: 0x442B8
Bounds g_davidBodyBounds[1024]; // Address: 0x2FC740
unsigned short g_davidBodyBoundIndices[16][1024]; // Address: 0x2F4740
unsigned char g_davidCellSizes[16][16]; // Address: 0x0
unsigned short g_davidCells[16][16][16]; // Address: 0x0
signed int g_davidCellY; // Address: 0x0
signed int g_davidMinCellY; // Address: 0x0
signed int g_davidCellX; // Address: 0x0
signed int g_davidMinCellX; // Address: 0x0

// Function Declarations ////////////////////////////////////////////////

s32 tmcrsInit(CourseData* data, s32 mirror);
void tmcrsEnd();
void tmcrsReset();
void tmcrsFinish();
static signed int tmcrsInitBase(unsigned int** addr);
static signed int tmcrsInitDraw(unsigned int** addr, signed int type);
static s32 tmcrsInitAlpha(unsigned int addr);
static s32 tmcrsInitHit(unsigned int addr);
static s32 tmcrsInitVector(unsigned int addr);
static s32 tmcrsInitRail(unsigned int addr);
static signed int tmcrsInitBonk(unsigned int addr);
signed int tmcrsDraw(// Size: 0x30, DWARF: 0x4243D
CourseParam* param);
void tmcrsSetDrawLength(float length);
float tmcrsGetDrawLength();
static signed int tmcrsDrawBase(// Size: 0x30, DWARF: 0x4243D
CourseParam* param);
static signed int tmcrsDrawDraw(// Size: 0x30, DWARF: 0x4243D
CourseParam* param);
static signed int tmcrsDrawAlpha(// Size: 0x30, DWARF: 0x4243D
CourseParam* param);
static void tmcrsSetRegister(// Size: 0x30, DWARF: 0x4243D
CourseParam* param, signed int type);
signed int tmcrsGetBaseCollision(// Size: 0x60, DWARF: 0x42032
Col* collision, signed int x, signed int y, float* src, float* dst);
signed int tmcrsGetHitCollision(Col* collision, signed int x, signed int y, float* src, float* dst);
signed int tmcrsGetVectorCollision(// Size: 0x60, DWARF: 0x42032
Col* collision, signed int x, signed int y, float* src, float* dst);
signed int tmcrsGetRailCollision(// Size: 0x60, DWARF: 0x42032
Col* rail, // Size: 0x60, DWARF: 0x42032
Col* half_pipe, signed int x, signed int y, float* position, float* src, float* dst);
signed int tmcrsGetBonkCollision(// Size: 0x60, DWARF: 0x42032
Col* collision, signed int x, signed int y, float* position);
static void tmcrsMakeCollisionMatrix(sceVu0FMATRIX matrix, float* vert1, float* vert2, float* vert3);
static signed int tmcrsCheckCollisionBound(float* src, float* dst, float* vert0, float* vert1, float* vert2);
static signed int tmcrsGetCollisionSub(float* pos, float* normal, sceVu0FMATRIX matrix, float* src, float* dst);
static signed int tmcrsGetVectorCollisionSub(// Size: 0x60, DWARF: 0x42032
Col* collision, float* vertex1, float* vertex2, float* src, float* dst);
static signed int tmcrsInitTex(// Size: 0x3BC, DWARF: 0x49410
CourseData* data);
void tmcrsTransTex(// Size: 0x10, DWARF: 0x4988E
GifPacket* packet);
static unsigned long tmcrsGetTex1Register(signed int type);
static s32 tmcrsTexIntrFunc(signed int a);
void tmcrsTransAlphaTex(// Size: 0x10, DWARF: 0x4988E
GifPacket* packet);
static void tmcrsEndTex();
static void tmcrsStartTex();
static void tmcrsFinishTex();
static void tmcrsSetMipMapProcess(signed int process);
void tmcrsSetMipMapLength(signed int len, signed int shift);
// Size: 0x10, DWARF: 0x48247
TexData* tmcrsGetTexData(TextureGroup* group);
void tmcrsResetScrollAnimTex();
void tmcrsSetScrollTex(ScrollingTextureData* input);
static void tmcrsScrollTex(GifPacket* packet, ScrollingTextureData* texData);
static void tmcrsAnimTex(GifPacket* packet, ScrollingTextureData* texData);
void tmcrsSetDrawMipMapNo(signed int no);
static s32 tmcrsInitBG(unsigned int** utd, int128* umd);
void tmcrsSetBGFog(s32 fog);
void tmcrsSetBGDrawFlag(s32 sw);
void tmcrsSetBGColor(s32 r, s32 g, s32 b);
void tmcrsSetBGNo(s32 no);
s32 tmcrsDrawBG(CourseParam* param);
static void tmcrsEndBG();
static signed int tmcrsInitObject(unsigned int addr);
static s32 tmcrsCheckObjectAlpha(s32 no);
static void tmcrsMappingObjectTexture();
void tmcrsResetAllObject();
void tmcrsResetObject(s32 no);
void tmcrsSetObjectDrawLength(f32 length);
void tmcrsSetObjectHitLength(f32 length);
void tmcrsSetObjectBound(s32 no, s32 sw);
void tmcrsSetObjectWeight(s32 no, s32 weight);
s32 tmcrsGetObjectPosition(float* position, s32 no);
void tmcrsSetObjectBonk(s32 no, float len, s32 bonk);
void tmcrsSetObjectBonkLength(s32 no, float len);
s32 tmcrsGetObjectBonk(s32 no);
void tmcrsSetObjectAttr(s32 no, s32 attr);
void tmcrsSetObjectDrawFlag(s32 no, s32 draw);
s32 tmcrsGetObjectDrawFlag(s32 no);
void tmcrsSetObjectScissorFlag(s32 no, s32 scissor);
void tmcrsMoveObject(s32 no, float* rot, float* trans, s32 local);
void tmcrsMoveObject2(s32 no, float* rot, float* trans);
void tmcrsMoveObject2XYZ(s32 no, float* rot, float* trans);
void tmcrsMoveObjectMat(s32 no, sceVu0FMATRIX matrix);
s32 tmcrsGetObjectCollision(Col* collision, float* src, float* dst);
signed int tmcrsCheckObjectCollision(float* src, float* dst);
s32 tmcrsGetObjectBonkCollision(Col* collision , f32* pos );
void tmcrsCalcObject();
void tmcrsCalcObjectUnit(s32 no);
static void tmcrsCalcObjectAbs(s32 no);
static void tmcrsCalcObjectMatrix(s32 no);
static void tmcrsCalcObjectLocal(s32 no);
static void tmcrsCalcObjectWorld(s32 no);
static void tmcrsCalcObjectBound(s32 no);
static void tmcrsCalcObjectDivide(s32 no );
static void tmcrsCalcObjectGravity(s32 no);
void tmcrsBreakObject(signed int no, float* dir);
void tmcrsGetObjectLight(float* light_color, float* light_vector, float* pos);
static signed int tmcrsDrawObject(// Size: 0x30, DWARF: 0x4243D
CourseParam* param);
static signed int tmcrsDrawObjectVIF1(CourseParam* param, sceVu0FMATRIX matrix, Data* data, signed int sc);
static signed int tmcrsDrawObjectDivideVIF1(CourseParam* param, sceVu0FMATRIX* matrix, Data* data, signed int num, signed int sc);
static s32 tmcrsDrawObjectSprite( CourseParam* param , sceVu0FMATRIX matrix , Data* data );
static s32 tmcrsDrawObjectAlpha( CourseParam* param , sceVu0FMATRIX matrix , Data* data , signed int sc );
static s32 tmcrsDrawObjectDivideAlpha( CourseParam* param , sceVu0FMATRIX* matrix , Data* data , signed int num , signed int sc );
static void tmcrsSetObjectBlockData();
static void tmcrsEndObject();
static s32 tmcrsInitEvent(CourseData* data, s32 offset);
static void tmcrsEndEvent();
void tmcrsResetEventModel(s32 num, CourseDrawParam* param);
f32 tmcrsGetEventModelFrame(s32 no, s32 id);
void tmcrsDrawEventModel(CourseParam* param);
void tmcrsCalcEventModel();
s32 tmcrsGetEventModelHit(float* pos, s32 no, float len);
void tmcrsSetFog(s32 fog);
void tmcrsGetArea(s32* x, s32* y, float* pos);
void tmcrsGetCenterPos(s32 x, s32 y, float* pos);
s32 tmcrsChangeNo(s32 x, s32 y);
void tmcrsResetRailCollision();
void tmcrsSetRailCollision(s32 no, s32 collision);
void tmcrsResetHitCollision();
s32 tmcrsSetHitCollision(s32 no, s32 attr, s32 base);
static signed int tmcrsGetDrawArea(// Size: 0x30, DWARF: 0x4243D
CourseParam* param, signed int x, signed int y);
static s32 tmcrsCheckDrawArea(CourseParam* param, s32 x, s32 y);
void tmcrsSetViewAngle(f32 angle);
void tmcrsSetMipModelLevel(s32 block);
signed int David_CheckBaseBlock();
void David_PutRaysInVU0();
signed int David_GetBaseCollision2(// Size: 0x60, DWARF: 0x42032
Col* collision, signed int* ret, signed int x, signed int y, signed int num);
signed int David_CheckHitData();
signed int David_GetHitCollision2(// Size: 0x60, DWARF: 0x42032
Col** collision, signed int* ret, signed int x, signed int y, sceVu0FVECTOR* src, sceVu0FVECTOR* dst, signed int num);
void David_tmcrsInitBlockBound();
signed int David_tmcrsGetObjectCollision2(// Size: 0x60, DWARF: 0x42032
Col** collision, signed int* ret, sceVu0FVECTOR* src, sceVu0FVECTOR* dst, signed int num);
signed int David_tmcrsGetObjectCollision(// Size: 0x60, DWARF: 0x42032
Col* collision, float* src, float* dst);


// SCE types ///////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// Size: 0x10, DWARF: 0xF7F23
typedef struct sceGifTag //: const <unknown type 0x3C>
{
    unsigned long NLOOP : 15; // Offset: 0x0, DWARF: 0xF7F3F, Bit Offset: 0, Bit Size: 15
    unsigned long EOP : 1; // Offset: 0x0, DWARF: 0xF7F6B, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0xF7F95, Bit Offset: 16, Bit Size: 16
    unsigned long id : 14; // Offset: 0x0, DWARF: 0xF7FC1, Bit Offset: 32, Bit Size: 14
    unsigned long PRE : 1; // Offset: 0x0, DWARF: 0xF7FEA, Bit Offset: 46, Bit Size: 1
    unsigned long PRIM : 11; // Offset: 0x0, DWARF: 0xF8014, Bit Offset: 47, Bit Size: 11
    unsigned long FLG : 2; // Offset: 0x0, DWARF: 0xF803F, Bit Offset: 58, Bit Size: 2
    unsigned long NREG : 4; // Offset: 0x0, DWARF: 0xF8069, Bit Offset: 60, Bit Size: 4
    unsigned long REGS0 : 4; // Offset: 0x8, DWARF: 0xF8094, Bit Offset: 0, Bit Size: 4
    unsigned long REGS1 : 4; // Offset: 0x8, DWARF: 0xF80C0, Bit Offset: 4, Bit Size: 4
    unsigned long REGS2 : 4; // Offset: 0x8, DWARF: 0xF80EC, Bit Offset: 8, Bit Size: 4
    unsigned long REGS3 : 4; // Offset: 0x8, DWARF: 0xF8118, Bit Offset: 12, Bit Size: 4
    unsigned long REGS4 : 4; // Offset: 0x8, DWARF: 0xF8144, Bit Offset: 16, Bit Size: 4
    unsigned long REGS5 : 4; // Offset: 0x8, DWARF: 0xF8170, Bit Offset: 20, Bit Size: 4
    unsigned long REGS6 : 4; // Offset: 0x8, DWARF: 0xF819C, Bit Offset: 24, Bit Size: 4
    unsigned long REGS7 : 4; // Offset: 0x8, DWARF: 0xF81C8, Bit Offset: 28, Bit Size: 4
    unsigned long REGS8 : 4; // Offset: 0x8, DWARF: 0xF81F4, Bit Offset: 32, Bit Size: 4
    unsigned long REGS9 : 4; // Offset: 0x8, DWARF: 0xF8220, Bit Offset: 36, Bit Size: 4
    unsigned long REGS10 : 4; // Offset: 0x8, DWARF: 0xF824C, Bit Offset: 40, Bit Size: 4
    unsigned long REGS11 : 4; // Offset: 0x8, DWARF: 0xF8279, Bit Offset: 44, Bit Size: 4
    unsigned long REGS12 : 4; // Offset: 0x8, DWARF: 0xF82A6, Bit Offset: 48, Bit Size: 4
    unsigned long REGS13 : 4; // Offset: 0x8, DWARF: 0xF82D3, Bit Offset: 52, Bit Size: 4
    unsigned long REGS14 : 4; // Offset: 0x8, DWARF: 0xF8300, Bit Offset: 56, Bit Size: 4
    unsigned long REGS15 : 4; // Offset: 0x8, DWARF: 0xF832D, Bit Offset: 60, Bit Size: 4
} sceGifTag __attribute__((aligned(16)));
// Size: 0x8, DWARF: 0xFB758
typedef struct sceGsAlpha
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0xFB774, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0xFB79C, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0xFB7C4, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0xFB7EC, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0xFB814, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0xFB83F, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0xFB869, Bit Offset: 40, Bit Size: 24
} sceGsAlpha;

// Size: 0x8, DWARF: 0xF9D57
typedef struct sceGsPrim
{
    unsigned long PRIM : 3; // Offset: 0x0, DWARF: 0xF9D73, Bit Offset: 0, Bit Size: 3
    unsigned long IIP : 1; // Offset: 0x0, DWARF: 0xF9D9E, Bit Offset: 3, Bit Size: 1
    unsigned long TME : 1; // Offset: 0x0, DWARF: 0xF9DC8, Bit Offset: 4, Bit Size: 1
    unsigned long FGE : 1; // Offset: 0x0, DWARF: 0xF9DF2, Bit Offset: 5, Bit Size: 1
    unsigned long ABE : 1; // Offset: 0x0, DWARF: 0xF9E1C, Bit Offset: 6, Bit Size: 1
    unsigned long AA1 : 1; // Offset: 0x0, DWARF: 0xF9E46, Bit Offset: 7, Bit Size: 1
    unsigned long FST : 1; // Offset: 0x0, DWARF: 0xF9E70, Bit Offset: 8, Bit Size: 1
    unsigned long CTXT : 1; // Offset: 0x0, DWARF: 0xF9E9A, Bit Offset: 9, Bit Size: 1
    unsigned long FIX : 1; // Offset: 0x0, DWARF: 0xF9EC5, Bit Offset: 10, Bit Size: 1
    unsigned long pad11 : 53; // Offset: 0x0, DWARF: 0xF9EEF, Bit Offset: 11, Bit Size: 53
} sceGsPrim;

// Size: 0x8, DWARF: 0xF8A49
typedef struct sceGsTex0 //: const <unknown type 0x3D>
{
    unsigned long TBP0 : 14; // Offset: 0x0, DWARF: 0xF8A65, Bit Offset: 0, Bit Size: 14
    unsigned long TBW : 6; // Offset: 0x0, DWARF: 0xF8A90, Bit Offset: 14, Bit Size: 6
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0xF8ABA, Bit Offset: 20, Bit Size: 6
    unsigned long TW : 4; // Offset: 0x0, DWARF: 0xF8AE4, Bit Offset: 26, Bit Size: 4
    unsigned long TH : 4; // Offset: 0x0, DWARF: 0xF8B0D, Bit Offset: 30, Bit Size: 4
    unsigned long TCC : 1; // Offset: 0x0, DWARF: 0xF8B36, Bit Offset: 34, Bit Size: 1
    unsigned long TFX : 2; // Offset: 0x0, DWARF: 0xF8B60, Bit Offset: 35, Bit Size: 2
    unsigned long CBP : 14; // Offset: 0x0, DWARF: 0xF8B8A, Bit Offset: 37, Bit Size: 14
    unsigned long CPSM : 4; // Offset: 0x0, DWARF: 0xF8BB4, Bit Offset: 51, Bit Size: 4
    unsigned long CSM : 1; // Offset: 0x0, DWARF: 0xF8BDF, Bit Offset: 55, Bit Size: 1
    unsigned long CSA : 5; // Offset: 0x0, DWARF: 0xF8C09, Bit Offset: 56, Bit Size: 5
    unsigned long CLD : 3; // Offset: 0x0, DWARF: 0xF8C33, Bit Offset: 61, Bit Size: 3
} sceGsTex0;

// Size: 0x8, DWARF: 0xF6BAA
typedef struct scest
{
    float S; // Offset: 0x0, DWARF: 0xF6BC5
    float T; // Offset: 0x4, DWARF: 0xF6BE3
} scest;

// Size: 0x8, DWARF: 0xF7CC7
typedef struct sceuv
{
    unsigned long U : 14; // Offset: 0x0, DWARF: 0xF7CE3, Bit Offset: 0, Bit Size: 14
    unsigned long pad14 : 2; // Offset: 0x0, DWARF: 0xF7D0B, Bit Offset: 14, Bit Size: 2
    unsigned long V : 14; // Offset: 0x0, DWARF: 0xF7D37, Bit Offset: 16, Bit Size: 14
    unsigned long pad30 : 34; // Offset: 0x0, DWARF: 0xF7D5F, Bit Offset: 30, Bit Size: 34
} sceuv;

typedef struct sceDmaTag {
	unsigned short qwc;
	unsigned char mark;
	unsigned char id;
	struct sceDmaTag* next;
	unsigned int p[2];
} sceDmaTag __attribute__((aligned(16)));

typedef unsigned long u_long;
unsigned int *sceGifPkReserve(void *pPacket, unsigned int count);

// GIF Registers /////////////////////////////////////////
#define GIF_REG_CTRL  *(volatile unsigned int *)0x10003000
#define GIF_REG_MODE  *(volatile unsigned int *)0x10003010
#define GIF_REG_STAT  *(volatile unsigned int *)0x10003020
#define GIF_REG_TAG0  *(volatile unsigned int *)0x10003040
#define GIF_REG_TAG1  *(volatile unsigned int *)0x10003050
#define GIF_REG_TAG2  *(volatile unsigned int *)0x10003060
#define GIF_REG_TAG3  *(volatile unsigned int *)0x10003070
#define GIF_REG_CNT   *(volatile unsigned int *)0x10003080
#define GIF_REG_P3CNT *(volatile unsigned int *)0x10003090
#define GIF_REG_P3TAG *(volatile unsigned int *)0x100030A0

// VIF Regiters ///////////////////////////////////////
#define VIF0_STAT  *(volatile unsigned int *)0x10003800
#define VIF0_FBRST *(volatile unsigned int *)0x10003810
#define VIF0_ERR   *(volatile unsigned int *)0x10003820
#define VIF0_MARK  *(volatile unsigned int *)0x10003830
#define VIF0_CYCLE *(volatile unsigned int *)0x10003840
#define VIF0_MODE  *(volatile unsigned int *)0x10003850
#define VIF0_NUM   *(volatile unsigned int *)0x10003860
#define VIF0_MASK  *(volatile unsigned int *)0x10003870
#define VIF0_CODE  *(volatile unsigned int *)0x10003880
#define VIF0_ITOPS *(volatile unsigned int *)0x10003890
#define VIF0_ITOP  *(volatile unsigned int *)0x100038d0
#define VIF0_TOP   *(volatile unsigned int *)0x100038e0
#define VIF0_R0    *(volatile unsigned int *)0x10003900
#define VIF0_R1    *(volatile unsigned int *)0x10003910
#define VIF0_R2    *(volatile unsigned int *)0x10003920
#define VIF0_R3    *(volatile unsigned int *)0x10003930
#define VIF0_C0    *(volatile unsigned int *)0x10003940
#define VIF0_C1    *(volatile unsigned int *)0x10003950
#define VIF0_C2    *(volatile unsigned int *)0x10003960
#define VIF0_C3    *(volatile unsigned int *)0x10003970
 
#define VIF1_STAT  *(volatile unsigned int *)0x10003c00
#define ABORT() asm(".word 0x0000000d")
#define ExitHandler() asm { sync; ei }
#define ACCEL(addr) ((((unsigned int)(addr)) & 0x0FFFFFFF) | 0x30000000)
#define VIF1_FBRST *(volatile unsigned int *)0x10003c10
#define VIF1_ERR   *(volatile unsigned int *)0x10003c20
#define VIF1_MARK  *(volatile unsigned int *)0x10003c30
#define VIF1_CYCLE *(volatile unsigned int *)0x10003c40
#define VIF1_MODE  *(volatile unsigned int *)0x10003c50
#define VIF1_NUM   *(volatile unsigned int *)0x10003c60
#define VIF1_MASK  *(volatile unsigned int *)0x10003c70
#define VIF1_CODE  *(volatile unsigned int *)0x10003c80
#define VIF1_ITOPS *(volatile unsigned int *)0x10003c90
#define VIF1_BASE  *(volatile unsigned int *)0x10003ca0
#define VIF1_OFST  *(volatile unsigned int *)0x10003cb0
#define VIF1_TOPS  *(volatile unsigned int *)0x10003cc0
#define VIF1_ITOP  *(volatile unsigned int *)0x10003cd0
#define VIF1_TOP   *(volatile unsigned int *)0x10003ce0
#define VIF1_R0    *(volatile unsigned int *)0x10003d00
#define VIF1_R1    *(volatile unsigned int *)0x10003d10
#define VIF1_R2    *(volatile unsigned int *)0x10003d20
#define VIF1_R3    *(volatile unsigned int *)0x10003d30
#define VIF1_C0    *(volatile unsigned int *)0x10003d40
#define VIF1_C1    *(volatile unsigned int *)0x10003d50
#define VIF1_C2    *(volatile unsigned int *)0x10003d60
#define VIF1_C3    *(volatile unsigned int *)0x10003d70
 

/* GS registers address */
/*-- vertex info. reg--*/
#define SCE_GS_PRIM         0x00
#define SCE_GS_RGBAQ        0x01
#define SCE_GS_ST           0x02
#define SCE_GS_UV           0x03
#define SCE_GS_XYZF2        0x04
#define SCE_GS_XYZ2         0x05
#define SCE_GS_FOG          0x0a
#define SCE_GS_XYZF3        0x0c
#define SCE_GS_XYZ3         0x0d
#define SCE_GS_XYOFFSET_1   0x18
#define SCE_GS_XYOFFSET_2   0x19
#define SCE_GS_PRMODECONT   0x1a

/*-- drawing attribute reg. --*/
#define SCE_GS_PRMODE       0x1b
#define SCE_GS_TEX0_1       0x06
#define SCE_GS_TEX0_2       0x07
#define SCE_GS_TEX1_1       0x14
#define SCE_GS_TEX1_2       0x15
#define SCE_GS_TEX2_1       0x16
#define SCE_GS_TEX2_2       0x17
#define SCE_GS_TEXCLUT      0x1c
#define SCE_GS_SCANMSK      0x22
#define SCE_GS_MIPTBP1_1    0x34
#define SCE_GS_MIPTBP1_2    0x35
#define SCE_GS_MIPTBP2_1    0x36
#define SCE_GS_MIPTBP2_2    0x37
#define SCE_GS_CLAMP_1      0x08
#define SCE_GS_CLAMP_2      0x09
#define SCE_GS_TEXA         0x3b
#define SCE_GS_FOGCOL       0x3d
#define SCE_GS_TEXFLUSH     0x3f

/*-- pixel operation reg. --*/
#define SCE_GS_SCISSOR_1    0x40
#define SCE_GS_SCISSOR_2    0x41
#define SCE_GS_ALPHA_1      0x42
#define SCE_GS_ALPHA_2      0x43
#define SCE_GS_DIMX         0x44
#define SCE_GS_DTHE         0x45
#define SCE_GS_COLCLAMP     0x46
#define SCE_GS_TEST_1       0x47
#define SCE_GS_TEST_2       0x48
#define SCE_GS_PABE         0x49
#define SCE_GS_FBA_1        0x4a
#define SCE_GS_FBA_2        0x4b

/*-- buffer reg. --*/
#define SCE_GS_FRAME_1      0x4c
#define SCE_GS_FRAME_2      0x4d
#define SCE_GS_ZBUF_1       0x4e
#define SCE_GS_ZBUF_2       0x4f

/*-- inter-buffer transfer reg. --*/
#define SCE_GS_BITBLTBUF	0x50
#define SCE_GS_TRXPOS		0x51
#define SCE_GS_TRXREG		0x52
#define SCE_GS_TRXDIR		0x53
#define SCE_GS_HWREG		0x54

/*-- other reg. --*/
#define SCE_GS_SIGNAL		0x60
#define SCE_GS_FINISH		0x61
#define SCE_GS_LABEL		0x62
#define SCE_GS_NOP		0x7f

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u_long)(nloop) | ((u_long)(eop)<<15) | ((u_long)(pre) << 46) | \
    ((u_long)(prim)<<47) | ((u_long)(flg)<<58) | ((u_long)(nreg)<<60))

#define SCE_GIF_CLEAR_TAG(tp) \
    (*(u_long128 *)(tp) = (u_long128)0)

#define SCE_GIF_PACKED      0
#define SCE_GIF_REGLIST     1
#define SCE_GIF_IMAGE       2
#define SCE_GIF_PACKED_AD   0x0e

#define SCE_GS_SET_ALPHA_1  SCE_GS_SET_ALPHA
#define SCE_GS_SET_ALPHA_2  SCE_GS_SET_ALPHA
#define SCE_GS_SET_ALPHA(a, b, c, d, fix) \
    ((u_long)(a)       | ((u_long)(b) << 2)     | ((u_long)(c) << 4) | \
    ((u_long)(d) << 6) | ((u_long)(fix) << 32))

#define SCE_GS_SET_TEST_1 SCE_GS_SET_TEST
#define SCE_GS_SET_TEST_2 SCE_GS_SET_TEST
#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u_long)(ate)         | ((u_long)(atst) << 1) | \
    ((u_long)(aref) << 4)  | ((u_long)(afail) << 12) | \
    ((u_long)(date) << 14) | ((u_long)(datm) << 15) | \
    ((u_long)(zte) << 16)  | ((u_long)(ztst) << 17))

#define SCE_GS_SET_ZBUF_1   SCE_GS_SET_ZBUF
#define SCE_GS_SET_ZBUF_2   SCE_GS_SET_ZBUF
#define SCE_GS_SET_ZBUF(zbp, psm, zmsk) \
    ((u_long)(zbp) | ((u_long)(psm) << 24) | \
    ((u_long)(zmsk) << 32))

#define SCE_GS_SET_BITBLTBUF(sbp, sbw, spsm, dbp, dbw, dpsm) \
	((u_long)(sbp)         | ((u_long)(sbw) << 16) | \
	((u_long)(spsm) << 24) | ((u_long)(dbp) << 32) | \
	((u_long)(dbw) << 48)  | ((u_long)(dpsm) << 56))

#define SCE_GS_SET_TRXPOS(ssax, ssay, dsax, dsay, dir) \
	((u_long)(ssax)        | ((u_long)(ssay) << 16) | \
	((u_long)(dsax) << 32) | ((u_long)(dsay) << 48) | \
	((u_long)(dir) << 59))

#define SCE_GS_SET_TRXREG(rrw, rrh) \
	((u_long)(rrw) | ((u_long)(rrh) << 32))

#define SCE_GS_SET_TRXDIR(xdr) ((u_long)(xdr))

#define	SCE_GS_SET_TEXFLUSH()    0

#define	SCE_GS_FALSE			(0)
#define	SCE_GS_TRUE			(1)

#define SCE_GS_ZNOUSE			(0)
#define SCE_GS_ZALWAYS			(1)
#define SCE_GS_ZGEQUAL			(2)
#define SCE_GS_ZGREATER			(3)

#define SCE_GS_PSMCT32			(0)
#define SCE_GS_PSMCT24			(1)
#define SCE_GS_PSMCT16			(2)
#define SCE_GS_PSMCT16S			(10)
#define SCE_GS_PSMT8			(19)
#define SCE_GS_PSMT4			(20)
#define SCE_GS_PSMT8H			(27)
#define SCE_GS_PSMT4HL			(36)
#define SCE_GS_PSMT4HH			(44)
#define SCE_GS_PSMZ32			(48)
#define SCE_GS_PSMZ24			(49)
#define SCE_GS_PSMZ16			(50)
#define SCE_GS_PSMZ16S			(58)

#define SCE_GS_ALPHA_NEVER		(0)
#define SCE_GS_ALPHA_ALWAYS		(1)
#define SCE_GS_ALPHA_LESS		(2)
#define SCE_GS_ALPHA_LEQUAL		(3)
#define SCE_GS_ALPHA_EQUAL		(4)
#define SCE_GS_ALPHA_GEQUAL		(5)
#define SCE_GS_ALPHA_GREATER		(6)
#define SCE_GS_ALPHA_NOTEQUAL		(7)

#define	SCE_GS_AFAIL_KEEP		(0)
#define	SCE_GS_AFAIL_FB_ONLY		(1)
#define SCE_GS_AFAIL_ZB_ONLY		(2)
#define SCE_GS_AFAIL_RGB_ONLY		(3)

#define SCE_GS_DEPTH_NEVER		(0)
#define SCE_GS_DEPTH_ALWAYS		(1)
#define SCE_GS_DEPTH_GEQUAL		(2)
#define SCE_GS_DEPTH_GREATER		(3)

#define SCE_GS_ALPHA_CS			(0)
#define SCE_GS_ALPHA_CD			(1)
#define SCE_GS_ALPHA_ZERO		(2)

#define SCE_GS_ALPHA_AS			(0)
#define SCE_GS_ALPHA_AD			(1)
#define SCE_GS_ALPHA_FIX		(2)

void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void sceVu0TransposeMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1);
Seq* maMdlMotionInit(int128* motion_data, signed int id);
void ulFree(void* p);
unsigned long ultexGetTEX0(TexData* data);
float maGetMdlMotionFrame(unsigned int* total_data, signed int id);
unsigned int* ultexGetTex(unsigned int* addr, signed int offset, signed int block);
void tmgraphRTPSpriteAddAlphaBufT__(Alpha* alpha, float screen_z, GVertex* data, Matrix* matrix, GPrim* prim);
void maMdlMotionDirect(unsigned int* total_data, Seq* seq, signed int id, float frame);
void maMdlMotionRealBrendDirect(unsigned int* total_data, Seq* seq, signed int flg, signed int next_id, float next_frame, float ratio);
void DIntr(void);
void sceVu0InterVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, float t);
float sqrtf(float x);
float atan2f(float y, float x);
signed int rand(void);
void* memcpy(void* dst, const void* src, unsigned int n);
void sceVif1PkCnt(Vif1Packet* pkt, signed int flg);
void sceVif1PkOpenDirectHLCode(Vif1Packet* pkt, signed int flg);
unsigned long* sceVif1PkReserve(Vif1Packet* pkt, signed int qwc);
void sceVif1PkCloseDirectHLCode(Vif1Packet* pkt);
void sceVif1PkTerminate(Vif1Packet* pkt);
signed int AddDmacHandler(signed int channel, signed int (*handler)(signed int), signed int next);
signed int EnableDmac(signed int channel);
signed int AddIntcHandler(signed int cause, signed int (*handler)(signed int), signed int next);
signed int EnableIntc(signed int cause);

//// Function Declarations //////////////////////////////////////////////////////////

void sceDmaSend(DmaVif *dmaVif, void* tag);
void sceVu0CopyVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0MulVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void sceVu0Normalize(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0ScaleVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float s);
void sceVu0SubVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);

//// Functions //////////////////////////////////////////////////////////////////////

s32 tmcrsInit(CourseData* data, s32 mirror) {
    signed int ii; // r16
    signed int jj; // r17
    signed int offset; // r18

    vtmcrsSystem.crs_no = vspenvGame->course.no;
    vtmcrsSystem.nblock = 0;
    vtmcrsSystem.auto_cnt = 0;
    vtmcrsSystem.auto_draw = 1;
    vtmcrsSystem.fog = 1;
    for (ii = 0; ii < 2; ii++) {
        vtmcrsSystem.npoly[ii] = 0;
        vtmcrsSystem.nvertex[ii] = 0;
        vtmcrsSystem.crs_poly[ii] = 0;
        vtmcrsSystem.crs_vertex[ii] = 0;
    }
    vtmcrsSystem.draw_block = 0;
    vtmcrsSystem.draw_nblock = 0;
    vtmcrsSystem.draw_len = 3600.0f;
    vtmcrsSystem.mipmdl_level = 4;
    vtmcrsSystem.mirror = mirror;
    
    if (data->base) {
        vtmcrsSystem.nblock = ((signed short*)(data->base[0]))[3];
    } else {
        return -1;
    }

    vtmcrsSystem.draw_block = (unsigned short*)ulMalloc(vtmcrsSystem.nblock * 2, 0, 0);
    for (ii = 0; ii < 2; ii++) {
        vtmcrsSystem.crs_poly[ii] = (unsigned short*)ulMalloc(vtmcrsSystem.nblock * 2, 1, 1);
        vtmcrsSystem.crs_vertex[ii] = (unsigned short*)ulMalloc(vtmcrsSystem.nblock * 2, 1, 1);
    }
    for (ii = 0; ii < 2; ii++) {
        for (jj = 0; jj < vtmcrsSystem.nblock; jj++) {
            vtmcrsSystem.crs_poly[ii][jj] = 0;
            vtmcrsSystem.crs_vertex[ii][jj] = 0;
        }
    }
    sceDmaSend(vulsysSystem.DmaVif0, (void*)&ltmasmSendPrgVu0);
    sceGsSyncPath(0, 0);
    tmcrsInitBG(data->bg_utd, data->bg_umd);
    tmcrsInitObject((s32)data->object);
    if (data->object) {
        for (ii = 0; ii < vtmcrsDivideNum[2]; ii++) {
            vtmcrsTexSystem.object_alpha[ii] = tmcrsCheckObjectAlpha(ii);
        }
    }
    offset = tmcrsInitTex(data);
    tmcrsInitBase(data->base);
    tmcrsInitDraw(data->draw, 0);
    tmcrsInitDraw(data->dfar, 1);
    tmcrsInitDraw(data->dnear, 2);
    tmcrsInitAlpha((s32)data->alpha);
    tmcrsInitHit((s32)data->hit);
    tmcrsInitVector((s32)data->vector);
    tmcrsInitRail((s32)data->rail);
    tmcrsInitBonk((s32)data->bonk);
    if (data->object) {
        tmcrsMappingObjectTexture();
    }
    tmcrsSetObjectBlockData();
    tmcrsInitEvent(data, offset);
    David_tmcrsInitBlockBound();
    return 0;
}

void tmcrsEnd() {
    signed int ii; // r16

    for (ii = 0; ii < 2; ii++) {
        ulFree(vtmcrsSystem.crs_poly[ii]);
        ulFree(vtmcrsSystem.crs_vertex[ii]);
    }
    ulFree(vtmcrsSystem.draw_block);
    ulFree(vtmcrsRailData.collision);
    tmcrsEndBG();
    tmcrsEndTex();
    tmcrsEndObject();
    tmcrsEndEvent();
}

void tmcrsReset() {
    vtmcrsSystem.i_counter = 0;
    vtmcrsSystem.f_counter = 0;
    vtmcrsSystem.view_angle = -1.0f;
}

void tmcrsFinish() {
    tmcrsFinishTex();
}

static signed int tmcrsInitBase(unsigned int** addr) {
    Prim2* prim; // r16
    Vertex* vert; // r17
    signed int mm; // r18
    signed int ll; // r19
    signed int jj; // r20
    TexBody* body; // r21
    signed int ii; // r22
    signed int kk; // r23
    Data* bdata; // r30

    if (*addr == 0) {
        return -1;
    }
    for (ii = 0; ii < vtmcrsDivideNum[0]; ii++) {
        vtmcrsBaseModel[ii].top_addr = 0;
        vtmcrsBaseModel[ii].top_addr = (unsigned int)addr[ii];
        vtmcrsBaseModel[ii].head = (ModelHeadData*)vtmcrsBaseModel[ii].top_addr;
        vtmcrsBaseModel[ii].block = (unsigned int*)(vtmcrsBaseModel[ii].top_addr + 0x10);
        for (jj = 0; jj < vtmcrsBaseModel[ii].head->nblock; jj++) {
            if (vtmcrsBaseModel[ii].block[jj] != 0) {
                vtmcrsBaseModel[ii].block[jj] = (unsigned int)vtmcrsBaseModel[ii].block[jj] + vtmcrsBaseModel[ii].top_addr;
                bdata = (Data*)vtmcrsBaseModel[ii].block[jj];
                body = (TexBody*)(vtmcrsBaseModel[ii].block[jj] + 0x20);
                for (kk = 0; kk < bdata->num; kk++) {
                    body->tex_id = ultexGetTEX0(&vtmcrsTexSystem.base[ii].data[body->tex_id * (vtmcrsTexSystem.base[ii].mipmap_level + 1)]);
                    prim = (Prim2*)((char*)body + 0x10);
                    for (ll = 0; ll < body->nprim; ll++) {
                        vtmcrsSystem.crs_poly[0][jj] += prim->nvertex - 2;
                        vtmcrsSystem.crs_vertex[0][jj] += prim->nvertex;
                        vert = (Vertex*)((char*)prim + 0x10);
                        for (mm = 0; mm < prim->nvertex; mm++) {
                            vert->rgba[3] = 0x80;
                            vert++;
                        }
                        prim = (Prim2*)((char*)&prim[1] + prim->nvertex * 0x30);
                    }
                    body = (TexBody*)((char*)prim + 0x20);
                }
            }
        }
    }
    return 0;
}

static signed int tmcrsInitDraw(unsigned int** addr, signed int type) {
    unsigned int tex0[2]; // 0xA8(r29)
    unsigned int* vert; // r16
    signed int tmp; // r17
    TexBody2* body; // r18
    signed int ll; // r19
    signed int jj; // r20
    Data* bdata; // r21
    unsigned char* addr_tmp; // r22
    signed int ii; // r23
    signed int kk; // r30

    if (*addr == 0) {
        vtmcrsDrawModel[type][0].top_addr = 0;
        return -1;
    }
    for (ii = 0; ii < vtmcrsDivideNum[1]; ii++) {
        vtmcrsDrawModel[type][ii].top_addr = 0;
        vtmcrsDrawModel[type][ii].top_addr = (unsigned int)addr[ii];
        vtmcrsDrawModel[type][ii].head = (ModelHeadData*)vtmcrsDrawModel[type][ii].top_addr;
        vtmcrsDrawModel[type][ii].block = (unsigned int*)(vtmcrsDrawModel[type][ii].top_addr + 0x10);
        for (jj = 0; jj < vtmcrsDrawModel[type][ii].head->nblock; jj++) {
            if (vtmcrsDrawModel[type][ii].block[jj] != 0) {
                vtmcrsDrawModel[type][ii].block[jj] =
                    (unsigned int)vtmcrsDrawModel[type][ii].block[jj] + vtmcrsDrawModel[type][ii].top_addr;
                bdata = (Data*)vtmcrsDrawModel[type][ii].block[jj];
                addr_tmp = (unsigned char*)bdata + 0x10;
                bdata->size = 0;
                for (kk = 0; kk < bdata->num; kk++) {
                    bdata->size += 4;
                    addr_tmp += 4;
                    body = (TexBody2*)addr_tmp;
                    *(unsigned long*)tex0 = ultexGetTEX0(&vtmcrsTexSystem.draw[ii].data[body->tex_id[0] * (vtmcrsTexSystem.draw[ii].mipmap_level + 1)]);
                    body->tex_id[0] = tex0[0];
                    body->tex_id[1] = tex0[1];
                    vtmcrsSystem.crs_poly[1][jj] += body->nprim & 0xFF;
                    vtmcrsSystem.crs_vertex[1][jj] += body->nprim & 0xFF;
                    vert = (unsigned int*)((char*)body + 0x18);
                    tmp = 0;
                    for (ll = 0; ll < (body->nprim & 0xFF); ll++) {
                        if (vert[3] != 0) {
                            vtmcrsSystem.crs_poly[1][jj] -= 2;
                            tmp += vert[3];
                        }
                        vert += 4;
                    }
                    body->pad2 = 0;
                    body->attr = 0;
                    tmp = 0x10;
                    bdata->size += tmp;
                    addr_tmp += tmp;
                    tmp = body->nprim & 0xFF;
                    tmp = tmp * 27 + 0x18;
                    tmp = (tmp + 3) / 4 * 4;
                    bdata->size += tmp;
                    addr_tmp += tmp;
                    body->size = (unsigned int)tmp + 0x10;
                }
                bdata->size = (bdata->size + 0xF) / 16 * 16;
            }
        }
    }
    return 0;
}

static s32 tmcrsInitAlpha(unsigned int addr) {
    // Size: 0x30, DWARF: 0x44405
    Vertex* vert; // r16
    // Size: 0x10, DWARF: 0x4395D
    TexBody* body; // r17
    // Size: 0x10, DWARF: 0x44057
    signed int ll; // r18
    Prim2* prim; // r19
    signed int ii; // r20
    signed int kk; // r21
    signed int jj; // r22
    // Size: 0x10, DWARF: 0x41E92
    Data* bdata; // r23

    vtmcrsAlphaModel.top_addr = 0;
    if (addr == 0) {
        return -1;
    }
    vtmcrsAlphaModel.top_addr = addr;
    vtmcrsAlphaModel.head = (s32*)vtmcrsAlphaModel.top_addr;
    vtmcrsAlphaModel.block = (unsigned int*)((int)vtmcrsAlphaModel.top_addr + 0x10);
    for (ii = 0; ii < vtmcrsAlphaModel.head->nblock; ii++) {
        if (vtmcrsAlphaModel.block[ii] != 0) {
            vtmcrsAlphaModel.block[ii] = ((s32)(unsigned int*)vtmcrsAlphaModel.block[ii] + vtmcrsAlphaModel.top_addr);
            prim = (Prim2*)vtmcrsAlphaModel.block[ii];
            body = (TexBody*)vtmcrsAlphaModel.block[ii] + 1;
            for (jj = 0; jj < prim->nvertex; jj++) {
                body->tex_id = ultexGetTEX0(&vtmcrsTexSystem.alpha.data[body->tex_id * (vtmcrsTexSystem.alpha.mipmap_level + 1)]);
                bdata = body + 1;
                for (kk = 0; kk < body->nprim; kk++) {
                    // temp_v1 = vtmcrsSystem.crs_poly[1][ii];
                    vtmcrsSystem.crs_poly[1][ii] += (bdata->num - 2);
                    // temp_a0 = vtmcrsSystem.crs_vertex[1][ii];
                    vtmcrsSystem.crs_vertex[1][ii] += bdata->num;
                    vert = bdata + 1;
                    for (ll = 0; ll < (s32) bdata->num; ll++) {
                        if (body->alpha == 0) {
                            vert->rgba[3] = 0x40;
                        } else if (body->alpha == 1) {
                            vert->rgba[3] = 0x40;
                        } else if (body->alpha == 2) {
                            vert->rgba[3] = 0x80;
                        } else if (body->alpha == 3) {
                            vert->rgba[3] = 0x80;
                        } else if (body->alpha == 4) {
                            vert->rgba[3] = 0x20;
                        } else if (body->alpha == 5) {
                            vert->rgba[3] = 0x80;
                        } else {
                            vert->rgba[3] = 0x80;
                        }
                        vert++;
                    }
                    bdata = (void*)((int)(bdata + 1) + (bdata->num * 0x30));
                }
                body = bdata;
            }
        }
    }
    return 0;
}

static s32 tmcrsInitHit(unsigned int addr) {
    signed int ii; // r16

    vtmcrsHitData.top_addr = 0;
    if (addr == 0) {
        return -1;
    }
    vtmcrsHitData.top_addr = addr;
    vtmcrsHitData.head = (s32*)vtmcrsHitData.top_addr;
    vtmcrsHitData.block = (s32*)(vtmcrsHitData.top_addr + 0x10);
    for (ii = 0; ii < vtmcrsHitData.head->nblock; ii++) {
        if (vtmcrsHitData.block[ii] != 0) {
            vtmcrsHitData.block[ii] = ((s32)(unsigned int*)vtmcrsHitData.block[ii] + vtmcrsHitData.top_addr);
        }
    }
    return 0;
}

static s32 tmcrsInitVector(unsigned int addr) {
    signed int ii; // r16

    vtmcrsVectorData.top_addr = 0;
    if (addr == 0) {
        return -1;
    }
    vtmcrsVectorData.top_addr = addr;
    vtmcrsVectorData.head = (s32*)vtmcrsVectorData.top_addr;
    vtmcrsVectorData.block = (s32*)(vtmcrsVectorData.top_addr + 0x10);
    for (ii = 0; ii < vtmcrsVectorData.head->nblock; ii++) {
        if (vtmcrsVectorData.block[ii] != 0) {
            vtmcrsVectorData.block[ii] = ((s32)(unsigned int*)vtmcrsVectorData.block[ii] + vtmcrsVectorData.top_addr);
        }
    }
    return 0;
}

static s32 tmcrsInitRail(unsigned int addr) {
    signed int ii; // r16

    vtmcrsRailData.top_addr = 0;
    vtmcrsRailData.collision = 0;
    if (addr == 0) {
        return -1;
    }
    vtmcrsRailData.top_addr = addr;
    vtmcrsRailData.head = (s32*)vtmcrsRailData.top_addr;
    vtmcrsRailData.collision = ulMalloc(vtmcrsRailData.head->num * 4, 0, 0);
    for (ii = 0; ii < vtmcrsRailData.head->num; ii++) {
        vtmcrsRailData.collision[ii] = 1;
    }
    return 0;
}

static signed int tmcrsInitBonk(unsigned int addr) {
    signed int ii; // r16

    vtmcrsBonkData.top_addr = 0;
    if (addr == 0) {
        return -1;
    }
    vtmcrsBonkData.top_addr = addr;
    vtmcrsBonkData.head = (ModelHeadData*)vtmcrsBonkData.top_addr;
    vtmcrsBonkData.block = (unsigned int*)((int)vtmcrsBonkData.top_addr + 0x10);
    for (ii = 0; ii < (vtmcrsBonkData.head->nblock); ii++) {
        if (vtmcrsBonkData.block[ii] != 0) {
            vtmcrsBonkData.block[ii] = (((s32)(unsigned int*)vtmcrsBonkData.block[ii]) + vtmcrsBonkData.top_addr);
        }
    }
    return 0;
}

signed int tmcrsDraw(CourseParam* param) {
    unsigned long* addr; // r16
    signed int x_pos; // 0x20(r29)
    signed int y_pos; // 0x24(r29)
    float fog_a; // 0x28(r29)
    float fog_b; // 0x2C(r29)

    tmgraphGetFogCoef(&fog_a, &fog_b, param->fog);
    ltmasmPrimitive[11] = fog_a;
    ltmasmPrimitive[15] = fog_b;
    memcpy(ltmasmLocalScreenMatrix, param->matrix, 0x40);
    memcpy(ltmasmLocalClipMatrix, (char*)param->matrix + 0xC0, 0x40);
    memcpy(ltmasmClipScreenMatrix, (char*)param->matrix + 0x100, 0x40);
    tmcrsGetArea(&x_pos, &y_pos, param->camera_position[0]);
    tmcrsGetDrawArea(param, x_pos, y_pos);
    sceVif1PkReset(param->vif1_packet);
    param->vif1_packet->pBase = (__int128*)(((unsigned int)param->vif1_packet->pBase & 0x0FFFFFFF) | 0x30000000);
    param->vif1_packet->pCurrent = (unsigned int*)(((unsigned int)param->vif1_packet->pCurrent & 0x0FFFFFFF) | 0x30000000);
    addr = sceVif1PkReserve(param->vif1_packet, 8);
    if (vtmcrsSystem.fog == 1) {
        *addr++ = *(unsigned long*)ltmasmSendPrgVu1;
        ((unsigned int*)ltmasmPrimitive)[5] = 0x303E4000;
        ((unsigned int*)ltmasmPrimitive)[9] = 0x303EC000;
    } else {
        *addr++ = *(unsigned long*)ltmasmSendPrgVu1NonFog;
        ((unsigned int*)ltmasmPrimitive)[5] = 0x302E4000;
        ((unsigned int*)ltmasmPrimitive)[9] = 0x302EC000;
    }
    *addr++ = 0;
    *addr++ = *(unsigned long*)ltmasmSendMatrix;
    *addr++ = 0;
    tmcrsSetRegister(param, 0);
    tmcrsDrawBase(param);
    tmcrsSetMipMapProcess(4);
    tmcrsSetRegister(param, 1);
    tmcrsDrawDraw(param);
    tmcrsSetMipMapProcess(5);
    tmcrsDrawObject(param);
    addr = sceVif1PkReserve(param->vif1_packet, 4);
    *addr++ = 0x70000000;
    *addr++ = 0;
    if (vgmsysPadPausePid < 0 && vspenvGame->mode.num_player == 2) {
        tmcrsCalcObject();
        vtmcrsSystem.i_counter += 1;
        vtmcrsSystem.f_counter += 1.0f;
        tmcrsSetObjectBlockData();
    }
    tmcrsDrawAlpha(param);
    ulgifDmaWait();
    ulvif1DmaWait();
    tmcrsStartTex();
    param->vif1_packet->pBase = (__int128*)((unsigned int)param->vif1_packet->pBase & 0x0FFFFFFF);
    param->vif1_packet->pCurrent = (unsigned int*)((unsigned int)param->vif1_packet->pCurrent & 0x0FFFFFFF);
    vulsysSystem.DmaVif1->chcr.TTE = 1;
    sceDmaSend(vulsysSystem.DmaVif1, param->vif1_packet->pBase);
    if (vgmsysPadPausePid < 0 && vspenvGame->mode.num_player == 1) {
        tmcrsCalcObject();
        vtmcrsSystem.i_counter += 1;
        vtmcrsSystem.f_counter += 1.0f;
        tmcrsSetObjectBlockData();
    }
    return 0;
}

void tmcrsSetDrawLength(float length) {
    vtmcrsSystem.draw_len = length;
    vtmcrsObjectData.draw_length = length;
}

float tmcrsGetDrawLength() {
    return vtmcrsSystem.draw_len;
}

static signed int tmcrsDrawBase(CourseParam* param) {
    unsigned short scissor; // r19
    unsigned long* addr; // r22
    unsigned int* block_addr; // r23
    signed int block; // r21
    signed int kk; // r17
    signed int jj; // r20
    signed int ii; // r30
    TexBody* body; // r16
    Data* data; // r18

    if (vtmcrsBaseModel[0].top_addr == 0) {
        return 0;
    }
    for (ii = 0; ii < vtmcrsDivideNum[0]; ii++) {
        block_addr = vtmcrsBaseModel[ii].block;
        for (jj = 0; jj < vtmcrsSystem.draw_nblock; jj++) {
            block = vtmcrsSystem.draw_block[jj] & 0xFFF;
            if (block_addr[block] != 0) {
                data = (Data*)block_addr[block];
                body = (TexBody*)((char*)block_addr[block] + 0x20);
                scissor = 0;
                if (vtmcrsSystem.draw_block[jj] & 0x8000) {
                    scissor = 0x8000;
                }
                addr = sceVif1PkReserve(param->vif1_packet, 4);
                for (kk = 0; kk < data->num; kk++) {
                    body->attr &= 0x7FFF;
                    body->attr |= scissor;
                    body = (TexBody*)((char*)body + body->size + 0x20);
                }
                *addr++ = ((data->size >> 4) | 0x30000000) |
                          (((unsigned long)(unsigned int)data + 0x10) << 32);
                *addr++ = 0;
            }
        }
        addr = sceVif1PkReserve(param->vif1_packet, 8);
        *addr++ = 0x10000001;
        *addr++ = 0;
        *addr++ = 0;
        *addr++ = (unsigned long)0x9300 << 16;
    }
    return 0;
}

static signed int tmcrsDrawDraw(CourseParam* param) {
    TexBody2* body; // r16
    signed int ll; // r17
    Data* data; // r18
    unsigned short scissor; // r19
    signed int kk; // r20
    signed int block; // r21
    unsigned long* addr; // r22
    unsigned int* block_addr; // r23
    signed int jj; // r30
    signed int ii; // 0xAC(r29)

    if (vtmcrsDrawModel[0][0].top_addr == 0) {
        return 0;
    }
    for (ii = 0; ii < vtmcrsDivideNum[1]; ii++) {
        if (ii >= vtmcrsDivideNum[1] - vtmcrsTexSystem.tri_mipmap) {
            sceVif1PkCnt(param->vif1_packet, 0);
            sceVif1PkOpenDirectHLCode(param->vif1_packet, 0);
            addr = sceVif1PkReserve(param->vif1_packet, 8);
            *addr++ = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
            *addr++ = SCE_GIF_PACKED_AD;
            *addr++ = ((unsigned long)vtmcrsTexSystem.mipmap_level[1] << 2) | 0x20 | 0x140 | 0x200 |
                      ((unsigned long)vtmcrsTexSystem.shift << 19) |
                      ((unsigned long)vtmcrsTexSystem.coef << 32);
            *addr++ = 0x14;
            sceVif1PkCloseDirectHLCode(param->vif1_packet);
            sceVif1PkTerminate(param->vif1_packet);
        }
        for (jj = 0; jj < 3; jj++) {
            if (vtmcrsDrawModel[jj][0].top_addr != 0) {
                block_addr = vtmcrsDrawModel[jj][ii].block;
                for (kk = 0; kk < vtmcrsSystem.draw_nblock; kk++) {
                    if (vtmcrsSystem.draw_block[kk] & 0x4000) {
                        if (jj == 1) {
                            continue;
                        }
                    } else {
                        if (jj == 2) {
                            continue;
                        }
                    }
                    block = vtmcrsSystem.draw_block[kk] & 0xFFF;
                    if (block_addr[block] != 0) {
                        data = (Data*)block_addr[block];
                        body = (TexBody2*)((char*)block_addr[block] + 0x14);
                        scissor = 0;
                        if (vtmcrsSystem.draw_block[kk] & 0x8000) {
                            scissor = 0x8000;
                        }
                        for (ll = 0; ll < data->num; ll++) {
                            body->attr &= 0x7FFF;
                            body->attr |= scissor;
                            body = (TexBody2*)((char*)body + body->size + 0x4);
                        }
                        addr = sceVif1PkReserve(param->vif1_packet, 4);
                        *addr++ = ((data->size >> 4) | 0x30000000) |
                                  (((unsigned long)(unsigned int)data + 0x10) << 32);
                        *addr++ = 0;
                    }
                }
            }
        }
        addr = sceVif1PkReserve(param->vif1_packet, 8);
        *addr++ = 0x10000001;
        *addr++ = 0;
        *addr++ = 0;
        *addr++ = (unsigned long)0x9300 << 16;
    }
    sceVif1PkCnt(param->vif1_packet, 0);
    sceVif1PkOpenDirectHLCode(param->vif1_packet, 0);
    addr = sceVif1PkReserve(param->vif1_packet, 8);
    *addr++ = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
    *addr++ = SCE_GIF_PACKED_AD;
    *addr++ = ((unsigned long)vtmcrsTexSystem.mipmap_level[1] << 2) | 0x20 | 0x140 | 0x200 |
              ((unsigned long)vtmcrsTexSystem.shift << 19) |
              ((unsigned long)vtmcrsTexSystem.coef << 32);
    *addr++ = 0x14;
    sceVif1PkCloseDirectHLCode(param->vif1_packet);
    sceVif1PkTerminate(param->vif1_packet);
    return 0;
}

static signed int tmcrsDrawAlpha(CourseParam* param) {
    GPrim gprim; // 0xA0(r29)
    GVertex gvertex[32]; // 0xD0(r29)
    unsigned int* block_addr; // 0x4DC(r29)
    signed int ll; // r16
    Vertex* vertex; // r17
    Prim2* prim; // r18
    signed int kk; // r19
    TexBody* body; // r20
    signed int jj; // r21
    Data* data; // r22
    signed int ii; // r23
    signed int block; // r30
    static const unsigned long alpha_tbl[7] = {
        0x44, 0x44, 0x8000000068, 0x80000000A1, 0x2000000068, 0x44, 0x44
    };

    if (vtmcrsAlphaModel.top_addr == 0) {
        return 0;
    }
    block_addr = vtmcrsAlphaModel.block;
    for (ii = 0; ii < vtmcrsSystem.draw_nblock; ii++) {
        block = vtmcrsSystem.draw_block[ii] & 0xFFF;
        if (block_addr[block] != 0) {
            data = (Data*)block_addr[block];
            body = (TexBody*)((char*)block_addr[block] + 0x10);
            if (vtmcrsSystem.draw_block[ii] & 0x8000) {
                gprim.scissor = 1;
            } else {
                gprim.scissor = 0;
            }
            for (jj = 0; jj < data->num; jj++) {
                gprim.test = 0x50000;
                gprim.tex = body->tex_id;
                gprim.tex1 = tmcrsGetTex1Register(1);
                gprim.prim = 0x25C;
                gprim.alpha = alpha_tbl[body->alpha];
                prim = (Prim2*)((char*)body + 0x10);
                for (kk = 0; kk < body->nprim; kk++) {
                    vertex = (Vertex*)((char*)prim + 0x10);
                    for (ll = 0; ll < prim->nvertex; ll++) {
                        gvertex[ll].vertex = vertex->vertex;
                        gvertex[ll].stq = vertex->stq;
                        gvertex[ll].rgba = vertex->rgba;
                        vertex++;
                    }
                    tmgraphRTPAddAlphaBufG_T__(param->alpha, prim->nvertex, gvertex, param->matrix, &gprim);
                    prim = (Prim2*)vertex;
                }
                body = (TexBody*)vertex;
            }
        }
    }
    return 0;
}

static void tmcrsSetRegister(CourseParam* param, signed int type) {
    unsigned long* pk_addr; // r16

    sceVif1PkCnt(param->vif1_packet, 0);
    sceVif1PkOpenDirectHLCode(param->vif1_packet, 0);
    pk_addr = sceVif1PkReserve(param->vif1_packet, 0x14);
    *pk_addr++ = SCE_GIF_SET_TAG(4, 1, 0, 0, 0, 1);
    *pk_addr++ = SCE_GIF_PACKED_AD;
    *pk_addr++ = 0x5160B;
    *pk_addr++ = 0x47;
    *pk_addr++ = (unsigned long)param->fog->col[0] | ((unsigned long)param->fog->col[1] << 8) |
                 ((unsigned long)param->fog->col[2] << 16);
    *pk_addr++ = 0x3D;
    *pk_addr++ = tmcrsGetTex1Register(type);
    *pk_addr++ = 0x14;
    *pk_addr++ = 0;
    *pk_addr++ = 0x8;
    sceVif1PkCloseDirectHLCode(param->vif1_packet);
    sceVif1PkTerminate(param->vif1_packet);
}

signed int tmcrsGetBaseCollision(Col* collision, signed int x, signed int y, float* src, float* dst) {
    sceVu0FVECTOR tmp; // 0xA0(r29)
    Col col_tmp; // 0xB0(r29)
    sceVu0FMATRIX matrix; // 0x110(r29)
    Vertex* vertex; // r16
    Prim2* prim; // r19
    TexBody* body; // r20
    Data* data; // r30
    signed int ii; // 0x158(r29)
    signed int block; // 0x15C(r29)
    signed int ll; // r17
    signed int flag; // r18
    signed int ret; // r21
    signed int kk; // r22
    signed int jj; // r23

    ret = 0;
    collision->len = 16777000.0f;
    if (vtmcrsBaseModel[0].top_addr == 0) {
        return ret;
    }
    block = tmcrsChangeNo(x, y);
    if (block < 0 || !(block < vtmcrsBaseModel[0].head->nblock)) {
        return ret;
    }
    for (ii = 0; ii < vtmcrsDivideNum[0]; ii++) {
        if (vtmcrsBaseModel[ii].block[block] != 0) {
            data = (Data*)vtmcrsBaseModel[ii].block[block];
            body = (TexBody*)((char*)data + 0x20);
            for (jj = 0; jj < data->num; jj++) {
                prim = (Prim2*)((char*)body + 0x10);
                for (kk = 0; kk < body->nprim; kk++) {
                    vertex = (Vertex*)((char*)prim + 0x10);
                    flag = prim->flag;
                    for (ll = 0; ll < prim->nvertex - 2; ll++) {
                        if (tmcrsCheckCollisionBound(src, dst, vertex[0].vertex, vertex[1].vertex, vertex[2].vertex) == 1) {
                            if (flag) {
                                tmcrsMakeCollisionMatrix(matrix, vertex[0].vertex, vertex[2].vertex, vertex[1].vertex);
                            } else {
                                tmcrsMakeCollisionMatrix(matrix, vertex[0].vertex, vertex[1].vertex, vertex[2].vertex);
                            }
                            if (tmcrsGetCollisionSub(col_tmp.point, col_tmp.normal, matrix, src, dst) == 1) {
                                ret++;
                                col_tmp.normal[3] = 1.0f;
                                col_tmp.point[3] = 1.0f;
                                sceVu0SubVector(tmp, col_tmp.point, src);
                                sceVu0MulVector(tmp, tmp, tmp);
                                if (collision->len > tmp[0] + tmp[1] + tmp[2]) {
                                    memcpy(collision, &col_tmp, 0x60);
                                    collision->attr = body->attr & 0x7FFF;
                                    collision->len = tmp[0] + tmp[1] + tmp[2];
                                }
                            }
                        }
                        flag ^= 1;
                        vertex = (Vertex*)((char*)vertex + 0x30);
                    }
                    vertex += 2;
                    prim = (Prim2*)vertex;
                }
                body = (TexBody*)((char*)vertex + 0x20);
            }
        }
    }
    return ret;
}

signed int tmcrsGetHitCollision(Col* collision, signed int x, signed int y, float* src, float* dst) {
    Collision* data ; // r16
    sceVu0FMATRIX* vertex; // r17
    signed int kk; // r18
    signed int block; // r19
    signed int ii; // r20
    signed int jj; // r21
    signed int flag; // r22
    signed int attr; // r23
    signed int cnt; // r30
    sceVu0FVECTOR tmp; // 0xA0(r29)
    sceVu0FMATRIX matrix; // 0xB0(r29)
    sceVu0FVECTOR src_tmp; // 0xF0(r29)
    sceVu0FVECTOR dst_tmp; // 0x100(r29)
    signed int ret; // 0x118(r29)
    signed int base; // 0x11C(r29)

    if (0) {
        // This block's content can be anything and it'd just mess the stack
        // left it as (void) regardles, but worth to keep in mind the if(0) bit
        (void)vertex;
        (void)data;
        (void)kk;
        (void)block;
        (void)ii;
        (void)jj;
        (void)flag;
        (void)attr;
        (void)cnt;
        (void)tmp;
        (void)matrix;
        (void)base;
    }
    
    sceVu0CopyVector(src_tmp, src);
    sceVu0CopyVector(dst_tmp, dst);
    David_GetHitCollision2((Col**)&collision, (signed int*)&ret, (unsigned int)x, (unsigned int)y, src_tmp, dst_tmp, 1);
    return ret;
}

signed int tmcrsGetVectorCollision(Col* collision, signed int x, signed int y, float* src, float* dst) {
    sceVu0FVECTOR* vertex; // r17
    sceVu0FVECTOR tmp; // 0x70(r29)
    VectorColData* data; // r18
    signed int block; // r21
    signed int ret; // r16
    signed int cnt; // r20
    signed int ii; // r19

    ret = 0;
    if (vtmcrsVectorData.top_addr == 0) {
        return ret;
    }
    block = tmcrsChangeNo(x, y);
    if (block < 0 || block >= vtmcrsVectorData.head->nblock || vtmcrsVectorData.block[block] == 0) {
        return ret;
    }
    data = (VectorColData*)vtmcrsVectorData.block[block];
    cnt = data->num;
    for (ii = 0; ii < cnt; ii++) {
        vertex = (sceVu0FVECTOR*)((char*)data + 0x10);
        if (tmcrsGetVectorCollisionSub(&collision[ret], vertex[0], vertex[1], src, dst)) {
            sceVu0SubVector(tmp, collision[ret].point, src);
            sceVu0MulVector(tmp, tmp, tmp);
            collision[ret].attr = data->type;
            collision[ret].len = tmp[0] + tmp[1] + tmp[2];
            collision[ret].vertex = vertex;
            collision[ret].no = 0;
            ret++;
        }
        vertex += 2;
        data = (VectorColData*)vertex;
    }
    return ret;
}

signed int tmcrsGetRailCollision(Col* rail, Col* half_pipe, signed int x, signed int y, float* position, float* src, float* dst) {
    sceVu0FVECTOR normal; // 0x80(r29)
    sceVu0FVECTOR tmp; // 0x90(r29)
    signed int kk; // r16
    signed int jj; // r17
    sceVu0FVECTOR* vertex; // r18
    signed int ret; // r19
    RailData* data; // r20
    signed int hp_cnt; // r21
    signed int ii; // r22

    ret = 0;
    hp_cnt = 0;
    if (vtmcrsRailData.top_addr == 0) {
        return ret;
    }
    data = (RailData*)(vtmcrsRailData.top_addr + 0x10);
    for (ii = 0; ii < vtmcrsRailData.head->num; ii++) {
        if (vtmcrsRailData.collision[ii] == 0) {
            data = (RailData*)((char*)&data[1] + data->nvertex * 16);
            continue;
        }
        if (x < data->left || x > data->right || y < data->bottom || y > data->top) {
            data = (RailData*)((char*)&data[1] + data->nvertex * 16);
            continue;
        }
        vertex = (sceVu0FVECTOR*)((char*)data + 0x10);
        for (jj = 0; jj < data->nvertex - 1; jj++) {
            if (data->type & 0x4000) {
                if (tmcrsGetVectorCollisionSub(&half_pipe[hp_cnt], vertex[jj], vertex[jj + 1], src, dst)) {
                    half_pipe[hp_cnt].attr = data->type;
                    half_pipe[hp_cnt].no = jj;
                    half_pipe[hp_cnt].nvertex = data->nvertex;
                    half_pipe[hp_cnt].vertex = vertex;
                    hp_cnt++;
                }
            }
            sceVu0SubVector(normal, vertex[jj + 1], vertex[jj]);
            sceVu0Normalize(normal, normal);
            sceVu0SubVector(tmp, position, vertex[jj]);
            sceVu0MulVector(tmp, normal, tmp);
            sceVu0ScaleVector(tmp, normal, tmp[0] + tmp[1] + tmp[2]);
            sceVu0AddVector(rail[ret].point, tmp, vertex[jj]);
            sceVu0SubVector(tmp, rail[ret].point, position);
            sceVu0MulVector(tmp, tmp, tmp);
            if (tmp[0] + tmp[1] + tmp[2] <= 225.0f) {
                for (kk = 0; kk < 3; kk++) {
                    if (vertex[jj][kk] > vertex[jj + 1][kk]) {
                        if (vertex[jj][kk] < rail[ret].point[kk]) {
                            break;
                        }
                        if (vertex[jj + 1][kk] <= rail[ret].point[kk]) {
                        } else {
                            break;
                        }
                    } else {
                        if (vertex[jj][kk] > rail[ret].point[kk]) {
                            break;
                        }
                        if (vertex[jj + 1][kk] < rail[ret].point[kk]) {
                            break;
                        }
                    }
                }
                if (kk == 3) {
                    rail[ret].no = jj;
                    rail[ret].nvertex = data->nvertex;
                    rail[ret].vertex = vertex;
                    rail[ret].attr = data->type;
                    rail[ret].len = tmp[0] + tmp[1] + tmp[2];
                    rail[ret].rail_no = ii;
                    ret++;
                }
            }
        }
        sceVu0SubVector(tmp, vertex[0], position);
        sceVu0MulVector(tmp, tmp, tmp);
        if (tmp[0] + tmp[1] + tmp[2] < 225.0f) {
            sceVu0CopyVector(rail[ret].point, vertex[0]);
            rail[ret].no = 0;
            rail[ret].nvertex = data->nvertex;
            rail[ret].vertex = vertex;
            rail[ret].attr = data->type;
            rail[ret].len = tmp[0] + tmp[1] + tmp[2];
            rail[ret].rail_no = ii;
            ret++;
        }
        sceVu0SubVector(tmp, vertex[data->nvertex - 1], position);
        sceVu0MulVector(tmp, tmp, tmp);
        if (tmp[0] + tmp[1] + tmp[2] < 225.0f) {
            sceVu0CopyVector(rail[ret].point, vertex[data->nvertex - 1]);
            rail[ret].no = data->nvertex - 1;
            rail[ret].nvertex = data->nvertex;
            rail[ret].vertex = vertex;
            rail[ret].attr = data->type;
            rail[ret].len = tmp[0] + tmp[1] + tmp[2];
            rail[ret].rail_no = ii;
            ret++;
        }
        data = (RailData*)((char*)&data[1] + data->nvertex * 16);
    }
    return ret | (hp_cnt << 16);
}

signed int tmcrsGetBonkCollision(Col* collision, signed int x, signed int y, float* position) {
    float len; // 0x7C(r29)
    sceVu0FVECTOR* vertex; // r17
    sceVu0FVECTOR tmp; // 0x60(r29)
    BonkData* data; // r19
    signed int block; // r20
    signed int ret; // r18
    signed int ii; // r16

    ret = 0;
    if (vtmcrsBonkData.top_addr == 0) {
        return ret;
    }
    block = tmcrsChangeNo(x, y);
    if (block < 0 || block >= vtmcrsBonkData.head->nblock || vtmcrsBonkData.block[block] == 0) {
        return ret;
    }
    data = (BonkData*)vtmcrsBonkData.block[block];
    vertex = (sceVu0FVECTOR*)((char*)data + 0x10);
    for (ii = 0; ii < data->nvertex; ii++) {
        if (vertex[ii][3] == 1.0f) {
            len = 400.0f;
        } else {
            len = vertex[ii][3] * vertex[ii][3];
        }
        sceVu0SubVector(tmp, vertex[ii], position);
        sceVu0MulVector(tmp, tmp, tmp);
        if (tmp[0] + tmp[1] + tmp[2] < len) {
            collision[ret].attr = data->type;
            collision[ret].len = tmp[0] + tmp[1] + tmp[2];
            sceVu0CopyVector(collision[ret].point, vertex[ii]);
            ret++;
        }
    }
    return ret;
}

static void tmcrsMakeCollisionMatrix(sceVu0FMATRIX matrix, float* vert1, float* vert2, float* vert3) {
    asm (
        paddub  v0,a0,zero;
        lqc2 $vf1, 0($a1);
        lqc2 $vf2, 0($a2);
        lqc2 $vf3, 0($a3);
        vcallms 0x390; // calls VU0 microprogram
        // Returning values from VU0 to matrix
        qmfc2.i $a2, $vf0;
        sqc2 $vf7, 0x30($v0);
        sqc2 $vf8, 0($v0);
        sqc2 $vf9, 0x10($v0);
        sqc2 $vf10, 0x20($v0);
        // Negating every the last value in each vector in the matrix
        lwc1 $f0,0xc(v0);
        neg.s   $f0,$f0;
        swc1    $f0,0xc(v0);

        lwc1    $f0,0x1c(v0);
        neg.s   $f0,$f0;
        swc1    $f0,0x1c(v0);
        
        lwc1    $f0,0x2c(v0);
        neg.s   $f0,$f0;
        swc1    $f0,0x2c(v0);
        
        lwc1    $f0,0x3c(v0);
        neg.s   $f0,$f0;
        swc1    $f0,0x3c(v0);
        
        paddub  a0,v0,zero;
        paddub  a1,v0,zero;
        jal     sceVu0TransposeMatrix;

    );
}

static signed int tmcrsCheckCollisionBound(float* src, float* dst, float* vert0, float* vert1, float* vert2) {
    signed int ret; // r2

    ret = 0;
    asm (
        lqc2 $vf1, 0x0(src);
        lqc2 $vf2, 0x0(dst);
        lqc2 $vf3, 0x0(vert0);
        lqc2 $vf4, 0x0(vert1);
        lqc2 $vf5, 0x0(vert2);
        vcallms 0x4A8;
        qmfc2.i $a2, $vf0;
        cfc2.ni ret, $vi3;
    );
    return ret;
}

static signed int tmcrsGetCollisionSub(float* pos, float* normal, sceVu0FMATRIX matrix, float* src, float* dst) {
    signed int ret; // r16
    sceVu0FVECTOR tmp1; // 0x50(r29)

    ret = 0;
    src[3] = 1.0f;
    dst[3] = 1.0f;
    asm (
        paddub v0, pos, zero;
        lqc2 $vf1, 0x0(matrix);
        lqc2 $vf2, 0x10(matrix);
        lqc2 $vf3, 0x20(matrix);
        lqc2 $vf4, 0x30(matrix);
        lqc2 $vf5, 0x0(src);
        lqc2 $vf6, 0x0(dst);
        vcallms 0x548;
        qmfc2.i $a2, $vf0;
        sqc2 $vf29, 0x0(normal);
        sqc2 $vf30, 0x0(v0);
    );
    if (normal[3] == 1.0f) {
        ret = 1;
        tmp1[0] = matrix[0][3];
        tmp1[1] = matrix[1][3];
        tmp1[2] = matrix[2][3];
        tmp1[3] = matrix[3][3];
        sceVu0Normalize(normal, tmp1);
    }
    return ret;
}

static signed int tmcrsGetVectorCollisionSub(Col* collision, float* vertex1, float* vertex2, float* src, float* dst) {
    sceVu0FVECTOR dvert0; // 0x20(r29)
    sceVu0FVECTOR dvert1; // 0x30(r29)
    float len0; // 0x4C(r29)
    float len1; // 0x50(r29)
    float a; // 0x54(r29)
    float b; // 0x58(r29)
    float rate; // 0x5C(r29)
    signed int ii; // r16

    for (ii = 0; ii < 3; ii++) {
        if (ii == 1) {
            continue;
        }
        if (src[ii] > dst[ii]) {
            if (src[ii] < vertex1[ii] && src[ii] < vertex2[ii]) {
                break;
            }
            if (dst[ii] > vertex1[ii] && dst[ii] > vertex2[ii]) {
                break;
            }
        } else {
            if (src[ii] > vertex1[ii] && src[ii] > vertex2[ii]) {
                break;
            }
            if (dst[ii] < vertex1[ii] && dst[ii] < vertex2[ii]) {
                break;
            }
        }
    }
    if (ii != 3) {
        return 0;
    }
    sceVu0SubVector(dvert0, dst, src);
    sceVu0SubVector(dvert1, vertex1, vertex2);
    if (dvert1[0] * dvert0[2] - dvert0[0] * dvert1[2] == 0.0f) {
        return 0;
    }
    if (vertex1[0] - vertex2[0] != 0.0f) {
        a = (vertex1[2] - vertex2[2]) / (vertex1[0] - vertex2[0]);
        b = vertex1[2] - a * vertex1[0];
        len0 = b + (a * src[0] - src[2]);
        len1 = b + (a * dst[0] - dst[2]);
    } else {
        len0 = src[0] - vertex1[0];
        len1 = dst[0] - vertex1[0];
    }
    if (len0 * len1 > 0.0f) {
        return 0;
    }
    if (len0 == 0.0f) {
        return 0;
    }
    if (len0 < 0.0f) {
        len0 = -len0;
    }
    if (len1 < 0.0f) {
        len1 = -len1;
    }
    rate = len1 / (len0 + len1);
    sceVu0InterVector(collision->point, src, dst, rate);
    collision->point[3] = 1.0f;
    return 1;
}

static signed int tmcrsInitTex(CourseData* data) {
    signed int ii; // r16
    unsigned char* tmp; // r17
    signed int cnt; // r18
    signed int offset; // r19

    cnt = 0;
    vtmcrsTexSystem.nbase = vtmcrsDivideNum[0];
    vtmcrsTexSystem.ndraw = vtmcrsDivideNum[1];
    vtmcrsTexSystem.nobject = vtmcrsDivideNum[2];
    vtmcrsTexSystem.mipmap_process = 5;
    vtmcrsTexSystem.tri_mipmap = 1;
    vtmcrsTexSystem.coef = -0x87;
    vtmcrsTexSystem.shift = 0;
    vtmcrsTexSystem.scroll_num = 0;
    vtmcrsTexSystem.anim_num = 0;

    for (ii = 0; ii < 10; ii++) {
        vtmcrsTexSystem.base[ii].frame = 0;
        vtmcrsTexSystem.base[ii].data = 0;
        vtmcrsTexSystem.draw[ii].frame = 0;
        vtmcrsTexSystem.draw[ii].data = 0;
    }
    for (ii = 0; ii < 96; ii++) {
        vtmcrsTexSystem.object[ii].frame = 0;
        vtmcrsTexSystem.object[ii].data = 0;
    }
    vtmcrsTexSystem.alpha.frame = 0;
    vtmcrsTexSystem.alpha.data = 0;

    for (ii = 0; ii < vtmcrsTexSystem.nbase; ii++) {
        vtmcrsTexSystem.base[ii].addr = data->base_utd[ii];
        vtmcrsTexSystem.base[ii].ntex = ultexGetNTex(vtmcrsTexSystem.base[ii].addr);
        vtmcrsTexSystem.base[ii].nblock = ultexGetUseBlock(vtmcrsTexSystem.base[ii].addr);
        vtmcrsTexSystem.base[ii].mipmap_level = ultexGetMipMapLevel(vtmcrsTexSystem.base[ii].addr);
        vtmcrsTexSystem.base[ii].mipmap = ultexGetMipMap(vtmcrsTexSystem.base[ii].addr);
        if (cnt % 2) {
            vtmcrsTexSystem.base[ii].offset = 0x3400;
        } else {
            vtmcrsTexSystem.base[ii].offset = 0x2C00;
        }
        vtmcrsTexSystem.base[ii].frame = (void*)ulMalloc(ultexGetUseMemory(vtmcrsTexSystem.base[ii].nblock), 1, 0);
        vtmcrsTexSystem.base[ii].data = (void*)ulMalloc(vtmcrsTexSystem.base[ii].ntex * 0x10, 1, 0);
        ultexResetTex(vtmcrsTexSystem.base[ii].offset);
        ultexTransTex(vtmcrsTexSystem.base[ii].addr, vtmcrsTexSystem.base[ii].data);
        ultexGetTex(vtmcrsTexSystem.base[ii].frame, vtmcrsTexSystem.base[ii].offset, vtmcrsTexSystem.base[ii].nblock);
        cnt++;
    }
    ulFree(data->butd_link);

    for (ii = 0; ii < vtmcrsTexSystem.nbase; ii++) {
        tmp = (void*)ulMalloc(ultexGetUseMemory(vtmcrsTexSystem.base[ii].nblock), 1, 1);
        memcpy(tmp, vtmcrsTexSystem.base[ii].frame, ultexGetUseMemory(vtmcrsTexSystem.base[ii].nblock));
        ulFree(vtmcrsTexSystem.base[ii].frame);
        vtmcrsTexSystem.base[ii].frame = (void*)tmp;
        tmp = (void*)ulMalloc(vtmcrsTexSystem.base[ii].ntex * 0x10, 1, 1);
        memcpy(tmp, vtmcrsTexSystem.base[ii].data, vtmcrsTexSystem.base[ii].ntex * 0x10);
        ulFree(vtmcrsTexSystem.base[ii].data);
        vtmcrsTexSystem.base[ii].data = (void*)tmp;
    }

    for (ii = 0; ii < vtmcrsTexSystem.ndraw; ii++) {
        vtmcrsTexSystem.draw[ii].addr = data->draw_utd[ii];
        vtmcrsTexSystem.draw[ii].ntex = ultexGetNTex(vtmcrsTexSystem.draw[ii].addr);
        vtmcrsTexSystem.draw[ii].nblock = ultexGetUseBlock(vtmcrsTexSystem.draw[ii].addr);
        vtmcrsTexSystem.draw[ii].mipmap_level = ultexGetMipMapLevel(vtmcrsTexSystem.draw[ii].addr);
        vtmcrsTexSystem.draw[ii].mipmap = ultexGetMipMap(vtmcrsTexSystem.draw[ii].addr);
        if (cnt % 2) {
            vtmcrsTexSystem.draw[ii].offset = 0x3400;
        } else {
            vtmcrsTexSystem.draw[ii].offset = 0x2C00;
        }
        vtmcrsTexSystem.draw[ii].frame = (void*)ulMalloc(ultexGetUseMemory(vtmcrsTexSystem.draw[ii].nblock), 1, 0);
        vtmcrsTexSystem.draw[ii].data = (void*)ulMalloc(vtmcrsTexSystem.draw[ii].ntex * 0x10, 1, 0);
        ultexResetTex(vtmcrsTexSystem.draw[ii].offset);
        ultexTransTex(vtmcrsTexSystem.draw[ii].addr, vtmcrsTexSystem.draw[ii].data);
        ultexGetTex(vtmcrsTexSystem.draw[ii].frame, vtmcrsTexSystem.draw[ii].offset, vtmcrsTexSystem.draw[ii].nblock);
        cnt++;
    }
    ulFree(data->dutd_link);

    for (ii = 0; ii < vtmcrsTexSystem.ndraw; ii++) {
        tmp = (void*)ulMalloc(ultexGetUseMemory(vtmcrsTexSystem.draw[ii].nblock), 1, 1);
        memcpy(tmp, vtmcrsTexSystem.draw[ii].frame, ultexGetUseMemory(vtmcrsTexSystem.draw[ii].nblock));
        ulFree(vtmcrsTexSystem.draw[ii].frame);
        vtmcrsTexSystem.draw[ii].frame = (void*)tmp;
        tmp = (void*)ulMalloc(vtmcrsTexSystem.draw[ii].ntex * 0x10, 1, 1);
        memcpy(tmp, vtmcrsTexSystem.draw[ii].data, vtmcrsTexSystem.draw[ii].ntex * 0x10);
        ulFree(vtmcrsTexSystem.draw[ii].data);
        vtmcrsTexSystem.draw[ii].data = (void*)tmp;
    }

    offset = 0x2C00;
    for (ii = 0; ii < vtmcrsTexSystem.nobject; ii++) {
        vtmcrsTexSystem.object[ii].addr = data->obj_utd[ii];
        vtmcrsTexSystem.object[ii].ntex = ultexGetNTex(vtmcrsTexSystem.object[ii].addr);
        vtmcrsTexSystem.object[ii].nblock = ultexGetUseBlock(vtmcrsTexSystem.object[ii].addr);
        vtmcrsTexSystem.object[ii].mipmap_level = ultexGetMipMapLevel(vtmcrsTexSystem.object[ii].addr);
        vtmcrsTexSystem.object[ii].mipmap = ultexGetMipMap(vtmcrsTexSystem.object[ii].addr);
        if (vtmcrsTexSystem.object_alpha[ii] == 0) {
            vtmcrsTexSystem.object[ii].offset = 0x3400;
        } else {
            vtmcrsTexSystem.object[ii].offset = offset;
        }
        vtmcrsTexSystem.object[ii].frame = (void*)ulMalloc(ultexGetUseMemory(vtmcrsTexSystem.object[ii].nblock), 1, 0);
        vtmcrsTexSystem.object[ii].data = (void*)ulMalloc(vtmcrsTexSystem.object[ii].ntex * 0x10, 1, 0);
        ultexResetTex(vtmcrsTexSystem.object[ii].offset);
        ultexTransTex(vtmcrsTexSystem.object[ii].addr, vtmcrsTexSystem.object[ii].data);
        ultexGetTex(vtmcrsTexSystem.object[ii].frame, vtmcrsTexSystem.object[ii].offset, vtmcrsTexSystem.object[ii].nblock);
        if (vtmcrsTexSystem.object_alpha[ii] == 1) {
            offset = ultexSetAlign();
        }
    }
    ulFree(data->outd_link);

    for (ii = 0; ii < vtmcrsTexSystem.nobject; ii++) {
        tmp = (void*)ulMalloc(ultexGetUseMemory(vtmcrsTexSystem.object[ii].nblock), 1, 1);
        memcpy(tmp, vtmcrsTexSystem.object[ii].frame, ultexGetUseMemory(vtmcrsTexSystem.object[ii].nblock));
        ulFree(vtmcrsTexSystem.object[ii].frame);
        vtmcrsTexSystem.object[ii].frame = (void*)tmp;
        tmp = (void*)ulMalloc(vtmcrsTexSystem.object[ii].ntex * 0x10, 1, 1);
        memcpy(tmp, vtmcrsTexSystem.object[ii].data, vtmcrsTexSystem.object[ii].ntex * 0x10);
        ulFree(vtmcrsTexSystem.object[ii].data);
        vtmcrsTexSystem.object[ii].data = (void*)tmp;
    }

    if (data->alpha_utd) {
        vtmcrsTexSystem.alpha.addr = data->alpha_utd;
        vtmcrsTexSystem.alpha.ntex = ultexGetNTex(vtmcrsTexSystem.alpha.addr);
        vtmcrsTexSystem.alpha.nblock = ultexGetUseBlock(vtmcrsTexSystem.alpha.addr);
        vtmcrsTexSystem.alpha.mipmap_level = ultexGetMipMapLevel(vtmcrsTexSystem.alpha.addr);
        vtmcrsTexSystem.alpha.mipmap = ultexGetMipMap(vtmcrsTexSystem.alpha.addr);
        vtmcrsTexSystem.alpha.offset = offset;
        vtmcrsTexSystem.alpha.frame = (void*)ulMalloc(ultexGetUseMemory(vtmcrsTexSystem.alpha.nblock), 1, 1);
        vtmcrsTexSystem.alpha.data = (void*)ulMalloc(vtmcrsTexSystem.alpha.ntex * 0x10, 1, 1);
        ultexResetTex(vtmcrsTexSystem.alpha.offset);
        ultexTransTex(vtmcrsTexSystem.alpha.addr, vtmcrsTexSystem.alpha.data);
        ultexGetTex(vtmcrsTexSystem.alpha.frame, vtmcrsTexSystem.alpha.offset, vtmcrsTexSystem.alpha.nblock);
        ulFree(data->alpha_utd);
        cnt++;
        offset = ultexSetAlign();
    }

    vtmcrsTexSystem.mipmap[0] = vtmcrsTexSystem.base[0].mipmap;
    vtmcrsTexSystem.mipmap_level[0] = vtmcrsTexSystem.base[0].mipmap_level;
    vtmcrsTexSystem.mipmap[1] = vtmcrsTexSystem.draw[0].mipmap;
    vtmcrsTexSystem.mipmap_level[1] = vtmcrsTexSystem.draw[0].mipmap_level;
    return offset;
}

void tmcrsTransTex(GifPacket* packet) {
    vtmcrsTexSystem.tex_no = 0;
    ultexSetTexPath3(packet, vtmcrsTexSystem.base[0].frame, vtmcrsTexSystem.base[0].offset, vtmcrsTexSystem.base[0].nblock);
    vtmcrsTexSystem.tex_no += 1;
    if (vtmcrsTexSystem.base[1].frame) {
        ultexSetTexPath3(packet, vtmcrsTexSystem.base[1].frame, vtmcrsTexSystem.base[1].offset, vtmcrsTexSystem.base[1].nblock);
        vtmcrsTexSystem.tex_no += 1;
    } else {
        ultexSetTexPath3(packet, vtmcrsTexSystem.draw[0].frame, vtmcrsTexSystem.draw[0].offset, vtmcrsTexSystem.draw[0].nblock);
        vtmcrsTexSystem.tex_no += 1;
    }
    vtmcrsTexSystem.flag = 0;
    vtmcrsTexSystem.vif1 = 0;
    vtmcrsTexSystem.gif = 1;
}

static unsigned long tmcrsGetTex1Register(signed int type) {
    unsigned long ret; // r16

    if (vtmcrsTexSystem.mipmap[type] == 1) {
        ret = ((unsigned long)vtmcrsTexSystem.mipmap_level[type] << 2) | 0x20 |
              ((unsigned long)vtmcrsTexSystem.mipmap_process << 6) | 0x200 |
              ((unsigned long)vtmcrsTexSystem.shift << 19) |
              ((unsigned long)vtmcrsTexSystem.coef << 32);
    } else {
        ret = 0x220;
    }
    return ret;
}

static s32 tmcrsTexIntrFunc(signed int a) {
    signed int tmp; // r2
    unsigned int addr; // r5
    
    DIntr();
    if (a == 5) {
        vtmcrsTexSystem.vif1 = 1;
    } else if (a == 2) {
        vtmcrsTexSystem.gif = 1;
    }
    if ((vtmcrsTexSystem.gif == 1) && (vtmcrsTexSystem.vif1 == 1)) {
        tmp = vtmcrsTexSystem.tex_no - (vtmcrsTexSystem.nbase + vtmcrsTexSystem.ndraw);
        ulgifDmaWait();
        if (vtmcrsTexSystem.tex_no < (vtmcrsTexSystem.nbase + vtmcrsTexSystem.ndraw)) {
            addr = (int)vtmcrsLocalPacketAddr;
            addr = ACCEL(addr);
            sceGifPkInit(&vtmcrsLocalPacket, (__int128*)addr);
            sceGifPkReset(&vtmcrsLocalPacket);
            if (vtmcrsTexSystem.tex_no < vtmcrsTexSystem.nbase) {
                ultexSetTexPath3(&vtmcrsLocalPacket, vtmcrsTexSystem.base[vtmcrsTexSystem.tex_no].frame, vtmcrsTexSystem.base[vtmcrsTexSystem.tex_no].offset, vtmcrsTexSystem.base[vtmcrsTexSystem.tex_no].nblock);
            } else {
                ultexSetTexPath3(&vtmcrsLocalPacket, vtmcrsTexSystem.draw[vtmcrsTexSystem.tex_no - vtmcrsTexSystem.nbase].frame, vtmcrsTexSystem.draw[vtmcrsTexSystem.tex_no - vtmcrsTexSystem.nbase].offset, vtmcrsTexSystem.draw[vtmcrsTexSystem.tex_no - vtmcrsTexSystem.nbase].nblock);
            }
            sceGifPkEnd(&vtmcrsLocalPacket, 0, 0, 0x80000000);
            sceGifPkTerminate(&vtmcrsLocalPacket);
            sceDmaSend(vulsysSystem.DmaGif, &vtmcrsLocalPacketAddr);
        }
        vtmcrsTexSystem.tex_no++;
        vtmcrsTexSystem.gif = 0;
        vtmcrsTexSystem.vif1 = 0;
        VIF1_FBRST |= 8;
    } else if (vtmcrsTexSystem.vif1 == 1 && (vtmcrsTexSystem.tex_no > (vtmcrsTexSystem.nbase + vtmcrsTexSystem.ndraw))) {
        VIF1_FBRST |= 8;
    }
    vtmcrsTexSystem.flag++;
    ExitHandler();
    return 0;
}

void tmcrsTransAlphaTex(GifPacket* packet) {
    signed int ii; // r16

    for (ii = 0; ii < vtmcrsDivideNum[2]; ii++) {
        if (vtmcrsTexSystem.object_alpha[ii] == 1) {
            ultexSetTexPath3(packet, vtmcrsTexSystem.object[ii].frame, vtmcrsTexSystem.object[ii].offset, vtmcrsTexSystem.object[ii].nblock);
        }
    }
    if (vtmcrsTexSystem.alpha.frame) {
        ultexSetTexPath3(packet, vtmcrsTexSystem.alpha.frame, vtmcrsTexSystem.alpha.offset, vtmcrsTexSystem.alpha.nblock);
        for (ii = 0; ii < vtmcrsTexSystem.scroll_num; ii++) {
            if (vtmcrsScrollTexData[ii].src.group == 2 && vtmcrsScrollTexData[ii].src.no == 0) {
                tmcrsScrollTex(packet, &vtmcrsScrollTexData[ii]);
            }
        }
        for (ii = 0; ii < vtmcrsTexSystem.anim_num; ii++) {
            if (vtmcrsAnimTexData[ii].src.group == 2 && vtmcrsAnimTexData[ii].src.no == 0) {
                tmcrsAnimTex(packet, &vtmcrsAnimTexData[ii]);
            }
        }
    }
    for (ii = 0; ii < vtmcrsEventSystem.cnt; ii++) {
        if (vtmcrsEventSystem.param[ii].draw == 0);
        if (vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].alpha == 1) {
            ultexSetTexPath3(packet,
                vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].tex.frame,
                vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].tex.offset,
                vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].tex.nblock);
        }
    }
}

static void tmcrsEndTex(void) {
    signed int ii; // r16

    for (ii = 0; ii < 10; ii++) {
        ulFree(vtmcrsTexSystem.base[ii].frame);
        ulFree(vtmcrsTexSystem.base[ii].data);
        ulFree(vtmcrsTexSystem.draw[ii].frame);
        ulFree(vtmcrsTexSystem.draw[ii].data);
    }
    for (ii = 0; ii < 96; ii++) {
        ulFree(vtmcrsTexSystem.object[ii].frame);
        ulFree(vtmcrsTexSystem.object[ii].data);
    }
    ulFree(vtmcrsTexSystem.alpha.frame);
    ulFree(vtmcrsTexSystem.alpha.data);
}

static void tmcrsStartTex(void) {
    vtmcrsTexSystem.dmac_handle = AddDmacHandler(2, tmcrsTexIntrFunc, 0);
    EnableDmac(2);
    vtmcrsTexSystem.intc_handle = AddIntcHandler(5, tmcrsTexIntrFunc, 0);
    EnableIntc(5);
    GIF_REG_MODE = 4;
}

static void tmcrsFinishTex() {
    DisableDmac(2);
    RemoveDmacHandler(2, vtmcrsTexSystem.dmac_handle);
    DisableIntc(5);
    RemoveIntcHandler(5, vtmcrsTexSystem.intc_handle);
    GIF_REG_MODE = 0;
}

static void tmcrsSetMipMapProcess(signed int process) {
    vtmcrsTexSystem.mipmap_process = process;
}

void tmcrsSetMipMapLength(signed int len, signed int shift) {
    vtmcrsTexSystem.coef = -len;
    vtmcrsTexSystem.shift = shift;
}

TexData* tmcrsGetTexData(TextureGroup* group) {
    group->data = 0;
    switch (group->group) {
    case 0:
        if (group->no < vtmcrsTexSystem.nbase) {
            group->data = vtmcrsTexSystem.base[group->no].data;
        }
        break;
    case 1:
        if (group->no < vtmcrsTexSystem.ndraw) {
            group->data = vtmcrsTexSystem.draw[group->no].data;
        }
        break;
    case 2:
        if (group->no <= 0) {
            group->data = vtmcrsTexSystem.alpha.data;
        }
        break;
    case 3:
        if (group->no < vtmcrsTexSystem.nobject) {
            group->data = vtmcrsTexSystem.object[group->no].data;
        }
        break;
    }
    return group->data;
}

void tmcrsResetScrollAnimTex() {
    vtmcrsTexSystem.scroll_num = 0;
    vtmcrsTexSystem.anim_num = 0;
}

void tmcrsSetScrollTex(ScrollingTextureData* input) {
    // Size: 0x28, DWARF: 0x4D651
    ScrollingTextureData data; // 0x10(r29)
    data = *input;
    memcpy(&vtmcrsScrollTexData[vtmcrsTexSystem.scroll_num], &data, 0x28);
    vtmcrsTexSystem.scroll_num++;
}

static void tmcrsScrollTex(GifPacket* packet, ScrollingTextureData* texData) {
    signed int pixel; // r17 $s1
    signed int x_ofs[2]; // 0x60(r29)
    signed int y_ofs[2]; // 0x68(r29)
    unsigned long* addr; // r16 $s0
    // Size: 0x28, DWARF: 0x4D651
    ScrollingTextureData data; // 0x30(r29)
    
    data = *texData;
    
    if (data.scroll_x != 0) {
        x_ofs[0] = data.src.data[data.src.tex_no].width - data.scroll_x;
        x_ofs[1] = data.scroll_x;
        y_ofs[0] = 0;
        y_ofs[1] = data.src.data[data.src.tex_no].height;
    } else {
        x_ofs[0] = 0;
        x_ofs[1] = data.src.data[data.src.tex_no].width;
        y_ofs[0] = data.src.data[data.src.tex_no].height - data.scroll_y;
        y_ofs[1] = data.scroll_y;
    }
    
    switch (data.src.data[data.src.tex_no].image_bit) {
    case 4:
        pixel = SCE_GS_PSMT4;
        break;
    case 8:
        pixel = SCE_GS_PSMT8;
        break;
    }
    
    sceGifPkCnt(packet, 0, 0, 0);
    addr = (unsigned long*)sceGifPkReserve(packet, 0x18);
    *addr++ = SCE_GIF_SET_TAG(5, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    *addr++ = SCE_GIF_PACKED_AD;
    *addr++ = SCE_GS_SET_BITBLTBUF(data.src.data[data.src.tex_no].tofs, data.src.data[data.src.tex_no].width / 64, pixel, data.work.data[data.work.tex_no].tofs, data.work.data[data.work.tex_no].width / 64, pixel);
    *addr++ = SCE_GS_BITBLTBUF;
    *addr++ = SCE_GS_SET_TRXPOS(data.scroll_x, data.scroll_y, 0, 0, 0);
    *addr++ = SCE_GS_TRXPOS;
    *addr++ = SCE_GS_SET_TRXREG(data.src.data[data.src.tex_no].width - data.scroll_x, data.src.data[data.src.tex_no].height - data.scroll_y);
    *addr++ = SCE_GS_TRXREG;
    *addr++ = SCE_GS_SET_TRXDIR(2); // VRAM-VRAM there's no define for this, idk why
    *addr++ = SCE_GS_TRXDIR;
    *addr++ = SCE_GS_SET_TEXFLUSH();
    *addr++ = SCE_GS_TEXFLUSH;
    
    addr = (unsigned long*)sceGifPkReserve(packet, 0x18);
    *addr++ = SCE_GIF_SET_TAG(5, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    *addr++ = SCE_GIF_PACKED_AD;
    *addr++ = SCE_GS_SET_BITBLTBUF(data.src.data[data.src.tex_no].tofs, data.src.data[data.src.tex_no].width / 64, pixel, data.work.data[data.work.tex_no].tofs, data.work.data[data.work.tex_no].width / 64, pixel);
    *addr++ = SCE_GS_BITBLTBUF;
    *addr++ = SCE_GS_SET_TRXPOS(0, 0, x_ofs[0], y_ofs[0], 0);
    *addr++ = SCE_GS_TRXPOS;
    *addr++ = SCE_GS_SET_TRXREG(x_ofs[1], y_ofs[1]);
    *addr++ = SCE_GS_TRXREG;
    *addr++ = SCE_GS_SET_TRXDIR(2); // VRAM-VRAM there's no define for this, idk why
    *addr++ = SCE_GS_TRXDIR;
    *addr++ = SCE_GS_SET_TEXFLUSH();
    *addr++ = SCE_GS_TEXFLUSH;
    
    addr = (unsigned long*)sceGifPkReserve(packet, 0x18);
    *addr++ = SCE_GIF_SET_TAG(5, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    *addr++ = SCE_GIF_PACKED_AD;
    *addr++ = SCE_GS_SET_BITBLTBUF(data.work.data[data.work.tex_no].tofs, data.work.data[data.work.tex_no].width / 64, pixel, data.src.data[data.src.tex_no].tofs, data.src.data[data.src.tex_no].width / 64, pixel);
    *addr++ = SCE_GS_BITBLTBUF;
    *addr++ = SCE_GS_SET_TRXPOS(0, 0, 0, 0, 0);
    *addr++ = SCE_GS_TRXPOS;
    *addr++ = SCE_GS_SET_TRXREG(data.src.data[data.src.tex_no].width, data.src.data[data.src.tex_no].height);
    *addr++ = SCE_GS_TRXREG;
    *addr++ = SCE_GS_SET_TRXDIR(2); // VRAM-VRAM there's no define for this, idk why
    *addr++ = SCE_GS_TRXDIR;
    *addr++ = SCE_GS_SET_TEXFLUSH();
    *addr++ = SCE_GS_TEXFLUSH;
    sceGifPkTerminate(packet);
}

static void tmcrsAnimTex(GifPacket* packet, ScrollingTextureData* texData) {
    unsigned long* addr; // r16 $s0
    signed int pixel; // r17 $s1
    // Size: 0x28, DWARF: 0x4D651
    ScrollingTextureData data; // 0x30(r29)
    
    data = *texData;
    switch (data.src.data[data.src.tex_no].image_bit) {
    case 4:
        pixel = SCE_GS_PSMT4;
        break;
    case 8:
        pixel = SCE_GS_PSMT8;
        break;
    }
    
    sceGifPkCnt(packet, 0, 0, 0);
    addr = (unsigned long*)sceGifPkReserve(packet, 0x18);
    *addr++ = SCE_GIF_SET_TAG(5, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_PACKED, 1);
    *addr++ = SCE_GIF_PACKED_AD;
    *addr++ = SCE_GS_SET_BITBLTBUF(data.src.data[data.src.tex_no].tofs, data.src.data[data.src.tex_no].width / 64, pixel, data.work.data[data.work.tex_no].tofs, data.work.data[data.work.tex_no].width / 64, pixel);
    *addr++ = SCE_GS_BITBLTBUF;
    *addr++ = SCE_GS_SET_TRXPOS(0, 0, 0, 0, 0);
    *addr++ = SCE_GS_TRXPOS;
    *addr++ = SCE_GS_SET_TRXREG(data.src.data[data.src.tex_no].width, data.src.data[data.src.tex_no].height);
    *addr++ = SCE_GS_TRXREG;
    *addr++ = SCE_GS_SET_TRXDIR(2); // VRAM-VRAM there's no define for this, idk why
    *addr++ = SCE_GS_TRXDIR;
    *addr++ = SCE_GS_SET_TEXFLUSH();
    *addr++ = SCE_GS_TEXFLUSH;
    sceGifPkTerminate(packet);
}

void tmcrsSetDrawMipMapNo(signed int no) {
    vtmcrsTexSystem.tri_mipmap = no;
}

static s32 tmcrsInitBG(unsigned int** utd, int128* umd) {
    signed int ii; // r16
    vtmcrsBG.draw = 1;
    vtmcrsBG.fog = 0;
    vtmcrsBG.no = 0;
    for (ii = 0; ii < 2; ii++) {
        vtmcrsBG.tex[ii].offset = 0x3C00;
        vtmcrsBG.tex[ii].addr = 0;
        vtmcrsBG.tex[ii].frame = 0;
    }
    if (utd == 0) {
        vtmcrsBG.umd = 0;
        return -1;
    }
    vtmcrsBG.tex[0].addr = utd[0];
    vtmcrsBG.tex[1].addr = utd[1];
    vtmcrsBG.umd = umd;
    for (ii = 0; ii < 2; ii++) {
        vtmcrsBG.tex[ii].ntex = ultexGetNTex(vtmcrsBG.tex[ii].addr);
        vtmcrsBG.tex[ii].nblock = ultexGetUseBlock(vtmcrsBG.tex[ii].addr);
        vtmcrsBG.tex[ii].frame = (void*)ulMalloc(ultexGetUseMemory(vtmcrsBG.tex[ii].nblock), 0, 0);
        vtmcrsBG.tex[ii].data = (void*)ulMalloc(vtmcrsBG.tex[ii].ntex * 0x10, 0, 0);
        ultexResetTex(vtmcrsBG.tex[ii].offset);
        ultexTransTex(utd[ii], vtmcrsBG.tex[ii].data);
        ultexGetTex(vtmcrsBG.tex[ii].frame, vtmcrsBG.tex[ii].offset, vtmcrsBG.tex[ii].nblock);
    }
    ulvumdlInitModel(vtmcrsBG.umd, vtmcrsBG.tex[0].data, vtmcrsBG.tex[0].data);
    for (ii = 0; ii < 2; ii++) {
        ulFree(vtmcrsBG.tex[ii].data);
    }
    tmcrsSetBGColor(0x80, 0x80, 0x80);
    return 0;
}

void tmcrsSetBGFog(s32 fog) {
    vtmcrsBG.fog = fog;
}

void tmcrsSetBGDrawFlag(s32 sw) {
    vtmcrsBG.draw = sw;
}

void tmcrsSetBGColor(s32 r, s32 g, s32 b) {
    vtmcrsBG.color[0] = r;
    vtmcrsBG.color[1] = g;
    vtmcrsBG.color[2] = b;
    vtmcrsBG.color[3] = 128;
}

void tmcrsSetBGNo(s32 no) {
    vtmcrsBG.no = no;
}

s32 tmcrsDrawBG(CourseParam* param) {
    signed int ii; // r16
    sceVu0FMATRIX matrix; // 0x20(r29)
    // Size: 0x160, DWARF: 0x4FA68
    Vmenv mdlenv; // 0x60(r29)
    tag_ulcodCOORDINATE coord; // 0x1C0(r29)
    sceVu0FMATRIX light_color; // 0x250(r29)

    if (vtmcrsBG.draw == 0 || vtmcrsBG.tex[0].addr == 0) {
        return -1;
    }
    sceVu0UnitMatrix(&matrix);
    sceVu0TransMatrix(&matrix, &matrix, param->camera_position);
    ulcodInitCoordinate(&coord, 0);
    sceVu0CopyMatrix(&coord.mat, &matrix);
    coord.flag = 0;
    ulcodSetWvMatrix(&vspSystemMatrix[param->player].world_view);
    ulcodSetVsMatrix(&vspSystemMatrix[param->player].view_screen);
    for (ii = 0; ii < 3; ii++) {
        light_color[ii][0] = 0.0f;
        light_color[ii][1] = 0.0f;
        light_color[ii][2] = 0.0f;
        light_color[ii][3] = 1.0f;
    }
    light_color[3][0] = 0.5f;
    light_color[3][1] = 0.5f;
    light_color[3][2] = 0.5f;
    light_color[3][3] = 1.0f;
    if (vtmcrsBG.fog == 1) {
        mdlenv.enable = 2;
        tmgraphGetFogCoef(&mdlenv.fog.a, &mdlenv.fog.b, param->fog);
    } else {
        mdlenv.enable = 0;
    }
    ultexSetTexPath2(param->vif1_packet, vtmcrsBG.tex[vtmcrsBG.no].frame, vtmcrsBG.tex[vtmcrsBG.no].offset, vtmcrsBG.tex[vtmcrsBG.no].nblock);
    ulvumdlDrawModel(param->vif1_packet, 0, &coord, &vspSystemMatrix[param->player].normal_light, light_color, (__int128*)vtmcrsBG.umd, &mdlenv);
    return 0;
}

static void tmcrsEndBG() {
    ulFree(vtmcrsBG.tex[0].frame);
    ulFree(vtmcrsBG.tex[1].frame);
}

static signed int tmcrsInitObject(unsigned int addr) {
    signed int div_num; // 0xA4(r29)
    Vertex* vert; // r16
    TexBody* body; // r17
    Prim2* prim; // r18
    signed int mm; // r19
    signed int ll; // r20
    signed int kk; // r21
    signed int jj; // r22
    Data* data; // r23
    signed int ii; // r30

    vtmcrsObjectData.top_addr = 0;
    vtmcrsObjectData.type = 0;
    vtmcrsObjectData.data = 0;
    tmcrsSetObjectHitLength(300.0f);
    tmcrsSetObjectDrawLength(3600.0f);
    if (addr == 0) {
        return -1;
    }
    vtmcrsObjectData.top_addr = addr;
    vtmcrsObjectData.head = (ObjectHeadData*)vtmcrsObjectData.top_addr;
    vtmcrsObjectData.head->data += vtmcrsObjectData.top_addr;
    vtmcrsObjectData.type = (ObjectType**)ulMalloc(vtmcrsObjectData.head->ntype * 32, 0, 0);
    vtmcrsObjectData.local = (LocalObjectData*)ulMalloc(vtmcrsObjectData.head->num * 288, 0, 0);
    addr += 0x20;
    for (ii = 0; ii < vtmcrsObjectData.head->ntype; ii++) {
        vtmcrsObjectData.type[ii] = (ObjectType*)addr;
        addr += 0x20;
        addr += vtmcrsObjectData.type[ii]->divide_num * 32;
        if (vtmcrsObjectData.type[ii]->draw != 0) {
            vtmcrsObjectData.type[ii]->draw = (Data*)((unsigned int)vtmcrsObjectData.type[ii]->draw + vtmcrsObjectData.top_addr);
            data = vtmcrsObjectData.type[ii]->draw;
            body = (TexBody*)((char*)data + 0x10);
            for (jj = 0; jj < data->num; jj++) {
                prim = (Prim2*)((char*)body + 0x10);
                for (kk = 0; kk < body->nprim; kk++) {
                    vert = (Vertex*)((char*)prim + 0x10);
                    for (ll = 0; ll < prim->nvertex; ll++) {
                        if (body->alpha == 1) {
                            vert->rgba[3] = 0x40;
                        } else if (body->alpha == 2) {
                            vert->rgba[3] = 0x80;
                        } else if (body->alpha == 3) {
                            vert->rgba[3] = 0x80;
                        } else if (body->alpha == 4) {
                            vert->rgba[3] = 0x20;
                        } else if (body->alpha == 5) {
                            vert->rgba[3] = 0x80;
                        } else {
                            vert->rgba[3] = 0x80;
                        }
                        vert++;
                    }
                    prim = (Prim2*)((char*)&prim[1] + prim->nvertex * 0x30);
                }
                body = (TexBody*)prim;
            }
        }
        if (vtmcrsObjectData.type[ii]->collision != 0) {
            vtmcrsObjectData.type[ii]->collision = (Collision*)((unsigned int)vtmcrsObjectData.type[ii]->collision + vtmcrsObjectData.top_addr);
        }
        if (vtmcrsObjectData.type[ii]->divide_num != 0) {
            vtmcrsObjectData.type[ii]->divide = (Data*)((unsigned int)vtmcrsObjectData.type[ii]->divide + vtmcrsObjectData.top_addr);
            data = vtmcrsObjectData.type[ii]->divide;
            for (jj = 0; jj < vtmcrsObjectData.type[ii]->divide_num; jj++) {
                body = (TexBody*)((char*)data + 0x10);
                for (kk = 0; kk < data->num; kk++) {
                    prim = (Prim2*)((char*)body + 0x10);
                    for (ll = 0; ll < body->nprim; ll++) {
                        vert = (Vertex*)((char*)prim + 0x10);
                        for (mm = 0; mm < prim->nvertex; mm++) {
                            if (body->alpha == 1) {
                                vert->rgba[3] = 0x40;
                            } else if (body->alpha == 2) {
                                vert->rgba[3] = 0x80;
                            } else if (body->alpha == 3) {
                                vert->rgba[3] = 0x80;
                            } else if (body->alpha == 4) {
                                vert->rgba[3] = 0x20;
                            } else if (body->alpha == 5) {
                                vert->rgba[3] = 0x80;
                            } else {
                                vert->rgba[3] = 0x80;
                            }
                            vert++;
                        }
                        prim = (Prim2*)((char*)&prim[1] + prim->nvertex * 0x30);
                    }
                    body = (TexBody*)prim;
                }
                data = (Data*)body;
            }
        }
        vtmcrsObjectData.type[ii]->bound = 0;
    }
    vtmcrsObjectData.data = (ObjectData*)addr;
    for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
        for (jj = 0; jj < 3; jj++) {
            vtmcrsObjectData.data[ii].position.rot[jj] =
                (vtmcrsObjectData.data[ii].position.rot[jj] < -3.141592f)
                    ? (6.283184f + vtmcrsObjectData.data[ii].position.rot[jj])
                    : ((vtmcrsObjectData.data[ii].position.rot[jj] > 3.141592f)
                        ? (vtmcrsObjectData.data[ii].position.rot[jj] - 6.283184f)
                        : vtmcrsObjectData.data[ii].position.rot[jj]);
        }
        div_num = vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->divide_num;
        if (div_num == 0) {
            vtmcrsObjectData.local[ii].divide_mat = 0;
            vtmcrsObjectData.local[ii].divide_trans = 0;
            vtmcrsObjectData.local[ii].divide_rot = 0;
        } else {
            vtmcrsObjectData.local[ii].divide_mat = (sceVu0FMATRIX*)ulMalloc(div_num * 64, 0, 0);
            vtmcrsObjectData.local[ii].divide_trans = (sceVu0FVECTOR*)ulMalloc(div_num * 16, 0, 0);
            vtmcrsObjectData.local[ii].divide_rot = (sceVu0FVECTOR*)ulMalloc(div_num * 16, 0, 0);
        }
    }
    return 0;
}

static s32 tmcrsCheckObjectAlpha(s32 no) {
    // Size: 0x10, DWARF: 0x44057
    Prim2* prim; // r16
    // Size: 0x10, DWARF: 0x4395D
    TexBody* body; // r18
    // Size: 0x10, DWARF: 0x41E92
    Data* data; // r21
    signed int ret; // r19
    signed int jj; // r17
    signed int ii; // 

    ret = 0;
    data = vtmcrsObjectData.type[no]->draw;
    body = (TexBody*)((int)data + 0x10);
    for (ii = 0; ii < data->num; ii++) {
        prim = (Prim2*)((int)body + 0x10);
        if (body->alpha) {
            ret = 1;
            break;
        } else {
            ret = 0;
            for (jj = 0; jj < body->nprim; jj++) {
                prim = (Prim2*)((int)prim + 0x10 + (prim->nvertex * 0x30));
            }
            body = (TexBody*)prim;
        }
    }
    return ret;
}

static void tmcrsMappingObjectTexture() {
    // Size: 0x10, DWARF: 0x44057
    Prim2* prim; // r16 $s0
    // Size: 0x10, DWARF: 0x4395D
    TexBody* body; // r18 $s2
    // Size: 0x10, DWARF: 0x41E92
    Data* data; // r21
    signed int ll; // r17
    signed int kk; // r19
    signed int jj; // r22
    signed int ii; // r20

    for (ii = 0; ii < vtmcrsObjectData.head->ntype; ii++) {
        data = vtmcrsObjectData.type[ii]->draw;
        body = (TexBody*)(data + 0x1);
        for (jj = 0; jj < data->num; jj++) {
            body->tex_id = ultexGetTEX0(&vtmcrsTexSystem.object[ii].data[body->tex_id * (vtmcrsTexSystem.object[ii].mipmap_level + 1)]);
            prim = (Prim2*)(body + 0x1);
            for (kk = 0; kk < body->nprim; kk++) {
                prim = (void*)((int)(prim + 1) + (prim->nvertex * 0x30));
            }
            body = (TexBody*)prim;
        }
        if (vtmcrsObjectData.type[ii]->divide_num != 0) {
            data = vtmcrsObjectData.type[ii]->divide;
            for (jj = 0; jj < vtmcrsObjectData.type[ii]->divide_num; jj++) {
                body = (TexBody*)((int)data + 0x10);
                for (kk = 0; kk < data->num; kk++) {
                    body->tex_id = ultexGetTEX0(&vtmcrsTexSystem.object[ii].data[body->tex_id * (vtmcrsTexSystem.object[ii].mipmap_level + 1)]);
                    prim = (Prim2*)(body + 0x1);
                    for (ll = 0; ll < ((body->nprim)); ll++) {
                        prim = (void*)((int)(prim + 1) + (prim->nvertex * 0x30));
                    }
                    body = (TexBody*)prim;
                }
                data = (Data*)body;
            }
        }
    }
    tmcrsResetAllObject();
    vtmcrsObjectData.nobj = (void*)ulMalloc(vtmcrsBaseModel[0].head->nblock * 2, 0, 0);
    vtmcrsObjectData.block = (void*)ulMalloc(vtmcrsBaseModel[0].head->nblock * 4, 0, 0);
    for (ii = 0; ii < vtmcrsBaseModel[0].head->nblock; ii++) {
        vtmcrsObjectData.block[ii] = (void*)ulMalloc(0x80, 0, 0);
    }
}

void tmcrsResetAllObject() {
    signed int ii; // r16

    if (vtmcrsObjectData.top_addr != 0) {
        for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
            tmcrsResetObject(ii);
        }
    }
}

void tmcrsResetObject(s32 no) {
    signed int x; // 0x18(r29)
    signed int y; // 0x1C(r29)

    sceVu0UnitMatrix(vtmcrsObjectData.local[no].local_world);
    sceVu0RotMatrixX(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[0]);
    sceVu0RotMatrixY(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[1]);
    sceVu0RotMatrixZ(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[2]);
    sceVu0TransMatrix(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.trans);
    sceVu0CopyVector(vtmcrsObjectData.local[no].position, vtmcrsObjectData.data[no].position.trans);
    sceVu0CopyVector(vtmcrsObjectData.local[no].rotation, vtmcrsObjectData.data[no].position.rot);
    tmcrsGetArea(&x, &y, vtmcrsObjectData.local[no].position);
    vtmcrsObjectData.data[no].block = tmcrsChangeNo(x, y);
    vtmcrsObjectData.local[no].draw = 1;
    vtmcrsObjectData.local[no].calc = 0;
    vtmcrsObjectData.local[no].divide = 0;
    vtmcrsObjectData.local[no].bound = 0;
    vtmcrsObjectData.local[no].scissor = 0;
    vtmcrsObjectData.local[no].abs = 0;
    vtmcrsObjectData.local[no].cnt = 0;
    vtmcrsObjectData.local[no].gravity = 0;
    vtmcrsObjectData.local[no].obj_attr = 0;
    vtmcrsObjectData.local[no].radius = 0.0f;
    vtmcrsObjectData.local[no].weight = 1.0f;
    vtmcrsObjectData.local[no].hit = 0;
    vtmcrsObjectData.local[no].bonk = 0;
    vtmcrsObjectData.local[no].bonk_len[0] = 0.0f;
    vtmcrsObjectData.local[no].bonk_len[1] = 0.0f;
    vtmcrsObjectData.local[no].bonk_len[2] = 0.0f;
    vtmcrsObjectData.local[no].bonk_len[3] = 1.0f;
    vtmcrsObjectData.local[no].bonk_suction_len = 400.0f;
    vtmcrsObjectData.local[no].rot[0] = 0.0f;
    vtmcrsObjectData.local[no].rot[1] = 0.0f;
    vtmcrsObjectData.local[no].rot[2] = 0.0f;
    vtmcrsObjectData.local[no].rot[3] = 1.0f;
    vtmcrsObjectData.local[no].trans[0] = 0.0f;
    vtmcrsObjectData.local[no].trans[1] = 0.0f;
    vtmcrsObjectData.local[no].trans[2] = 0.0f;
    vtmcrsObjectData.local[no].trans[3] = 1.0f;
}

void tmcrsSetObjectDrawLength(f32 length) {
    vtmcrsObjectData.draw_length = length;
}

void tmcrsSetObjectHitLength(f32 length) {
    vtmcrsObjectData.hit_length = length * length;
}

void tmcrsSetObjectBound(s32 no, s32 sw) {
    vtmcrsObjectData.type[vtmcrsObjectData.data[no].type]->bound = sw;
    if (sw == 1) {
        vtmcrsObjectData.local[no].obj_attr = 2;
        return;
    }
    vtmcrsObjectData.local[no].obj_attr = 0;
    vtmcrsObjectData.local[no].radius = 0.0f;
}

void tmcrsSetObjectWeight(s32 no, s32 weight) {
    vtmcrsObjectData.local[no].weight = (f32) weight;
}

s32 tmcrsGetObjectPosition(float* position, s32 no) {
    if (vtmcrsObjectData.top_addr == 0) {
        return -1;
    }
    sceVu0CopyVector(position, vtmcrsObjectData.local[no].position);
    return vtmcrsObjectData.data[no].block;
}

void tmcrsSetObjectBonk(s32 no, float len, s32 bonk) {
    if (bonk == 1) {
        vtmcrsObjectData.local[no].bonk = 1;
        vtmcrsObjectData.local[no].bonk_len[1] = len;
        return;
    }
    vtmcrsObjectData.local[no].bonk = 0;
    vtmcrsObjectData.local[no].bonk_len[1] = 0.0f;
}

void tmcrsSetObjectBonkLength(s32 no, float len) {
    vtmcrsObjectData.local[no].bonk_suction_len = len * len;
}

s32 tmcrsGetObjectBonk(s32 no) {
    return vtmcrsObjectData.local[no].bonk;
}

void tmcrsSetObjectAttr(s32 no, s32 attr) {
    vtmcrsObjectData.local[no].obj_attr = attr;
}

void tmcrsSetObjectDrawFlag(s32 no, s32 draw) {
    vtmcrsObjectData.local[no].draw = draw;
}

s32 tmcrsGetObjectDrawFlag(s32 no) {
    return vtmcrsObjectData.local[no].draw;
}

void tmcrsSetObjectScissorFlag(s32 no, s32 scissor) {
    vtmcrsObjectData.local[no].scissor = scissor;
}

void tmcrsMoveObject(s32 no, float* rot, float* trans, s32 local) {
    if (local == 1) {
        vtmcrsObjectData.local[no].trans[0] = (f32) -trans[0];
        vtmcrsObjectData.local[no].trans[1] = (f32) -trans[2];
        vtmcrsObjectData.local[no].trans[2] = (f32) -trans[1];
        vtmcrsObjectData.local[no].trans[3] = 1.0f;
        vtmcrsObjectData.local[no].rot[0] = (f32) rot[0];
        vtmcrsObjectData.local[no].rot[1] = (f32) -rot[1];
        vtmcrsObjectData.local[no].rot[2] = (f32) -rot[2];
        vtmcrsObjectData.local[no].rot[3] = 1.0f;
    } else {
        sceVu0CopyVector(vtmcrsObjectData.local[no].trans, trans);
        vtmcrsObjectData.local[no].rot[0] = (f32) rot[0];
        vtmcrsObjectData.local[no].rot[1] = (f32) -rot[2];
        vtmcrsObjectData.local[no].rot[2] = (f32) -rot[1];
        vtmcrsObjectData.local[no].rot[3] = 1.0f;
    }
    vtmcrsObjectData.local[no].local = local;
    vtmcrsObjectData.local[no].abs = 0;
    vtmcrsObjectData.local[no].matrix = 0;
    vtmcrsObjectData.local[no].calc = 1;
}

void tmcrsMoveObject2(s32 no, float* rot, float* trans) {
    if (vtmcrsObjectData.local[no].divide == 0 && vtmcrsObjectData.local[no].bound == 0) {
        sceVu0CopyVector(vtmcrsObjectData.local[no].trans, trans);
        vtmcrsObjectData.local[no].rot[0] = (f32) rot[0];
        vtmcrsObjectData.local[no].rot[1] = (f32) -rot[2];
        vtmcrsObjectData.local[no].rot[2] = (f32) -rot[1];
        vtmcrsObjectData.local[no].rot[3] = 1.0f;
        vtmcrsObjectData.local[no].matrix = 0;
        vtmcrsObjectData.local[no].abs = 1;
        vtmcrsObjectData.local[no].xyz = 0;
        vtmcrsObjectData.local[no].calc = 1;
    }
}

void tmcrsMoveObject2XYZ(s32 no, float* rot, float* trans) {
    if ((vtmcrsObjectData.local[no].divide == 0) && (vtmcrsObjectData.local[no].bound == 0)) {
        sceVu0CopyVector(vtmcrsObjectData.local[no].trans, trans);
        vtmcrsObjectData.local[no].rot[0] = (f32) rot[0];
        vtmcrsObjectData.local[no].rot[1] = (f32) -rot[2];
        vtmcrsObjectData.local[no].rot[2] = (f32) -rot[1];
        vtmcrsObjectData.local[no].rot[3] = 1.0f;
        vtmcrsObjectData.local[no].matrix = 0;
        vtmcrsObjectData.local[no].abs = 1;
        vtmcrsObjectData.local[no].xyz = 1;
        vtmcrsObjectData.local[no].calc = 1;
    }
}

void tmcrsMoveObjectMat(s32 no, sceVu0FMATRIX matrix) {
    if ((vtmcrsObjectData.local[no].divide == 0) && (vtmcrsObjectData.local[no].bound == 0)) {
        sceVu0CopyMatrix(vtmcrsObjectData.local[no].local_mat, matrix);
        vtmcrsObjectData.local[no].matrix = 1;
        vtmcrsObjectData.local[no].abs = 0;
        vtmcrsObjectData.local[no].xyz = 0;
        vtmcrsObjectData.local[no].calc = 1;
    }
}

s32 tmcrsGetObjectCollision(Col* collision, float* src, float* dst) {
    signed int kk; // r16 // s0
    signed int ret; // r17 // s1
    // Size: 0x10, DWARF: 0x44340
    Collision* hit_data; // r18 // s2
    signed int ii; // r19 // s3
    signed int flag; // r20 // s4
    sceVu0FVECTOR* src_vert; // r21 // s5
    signed int jj; // r22 // s6
    signed int cnt; // r23 // s7
    signed int obj; // r30 // s8
    signed int xy[2][2]; // 0xA0(r29)
    sceVu0FVECTOR tmp; // 0xB0(r29)
    sceVu0FVECTOR dst_vert[32]; // 0xC0(r29)
    sceVu0FMATRIX matrix; // 0x2C0(r29)
    sceVu0IVECTOR block; // 0x300(r29)
    signed int x; // 0x314(r29)
    signed int y; // 0x318(r29)
    signed int no; // 0x31C(r29)

    // collision = collision; // 320
    // src = src; // 330
    // dst = dst; // 340
    if (vtmcrsObjectData.top_addr == 0) {
        return -1;
    }
    ret = 0;
    tmcrsGetArea(&x, &y, src);
    tmcrsGetCenterPos(x, y, tmp);
    sceVu0SubVector(&tmp, src, &tmp);
    xy[0][0] = x;
    xy[0][1] = y;
    if (tmp[0] < 0.0f) {
        xy[1][0] = x - 1;
    } else {
        xy[1][0] = x + 1;
    }
    if (tmp[2] < 0.0f) {
        xy[1][1] = y - 1;
    } else {
        xy[1][1] = y + 1;
    }
    block[0] = tmcrsChangeNo(xy[0][0], xy[0][1]);
    block[1] = tmcrsChangeNo(xy[1][0], xy[0][1]);
    block[2] = tmcrsChangeNo(xy[0][0], xy[1][1]);
    block[3] = tmcrsChangeNo(xy[1][0], xy[1][1]);
    for (no = 0; no < 4; no++) {
        if (block[no] != -1) {
            for (ii = 0; ii < vtmcrsObjectData.nobj[block[no]]; ii++) {
                obj = vtmcrsObjectData.block[block[no]][ii];
                sceVu0SubVector(&tmp, vtmcrsObjectData.local[obj].position, src);
                sceVu0MulVector(&tmp, &tmp, &tmp);
                if ((tmp[0] + tmp[1] + tmp[2]) <= vtmcrsObjectData.hit_length) {
                    hit_data = vtmcrsObjectData.type[vtmcrsObjectData.data[obj].type]->collision;
                    if ((hit_data) && (vtmcrsObjectData.local[obj].bound != 1) && (vtmcrsObjectData.local[obj].divide != 1) && (vtmcrsObjectData.local[obj].draw)) {
                        cnt = hit_data->num;
                        for (jj = 0; jj < cnt; jj++) {
                            flag = hit_data->flag;
                            src_vert = hit_data + 1;
                            for (kk = 0; kk < hit_data->nvertex; kk++) {
                                sceVu0ApplyMatrix(dst_vert[kk], vtmcrsObjectData.local[obj].local_world, src_vert[kk]);//temp_s5 + (kk * 0x10));
                            }
                            for (kk = 0; kk < (hit_data->nvertex - 2); kk++) {
                                if (tmcrsCheckCollisionBound(src, dst, dst_vert[kk], dst_vert[kk + 1], dst_vert[kk + 2]) == 1) {
                                    if (flag) {
                                        tmcrsMakeCollisionMatrix(matrix, dst_vert[kk], dst_vert[kk + 2], dst_vert[kk + 1]);
                                    } else {
                                        tmcrsMakeCollisionMatrix(matrix, dst_vert[kk], dst_vert[kk + 1], dst_vert[kk + 2]);
                                    }
                                    if (tmcrsGetCollisionSub(collision[ret].point, collision[ret].normal, matrix, src, dst) == 1) {
                                        sceVu0SubVector(&tmp, collision[ret].point, src);
                                        sceVu0MulVector(&tmp, &tmp, &tmp);
                                        collision[ret].obj_type = vtmcrsObjectData.data[obj].type;
                                        collision[ret].obj_no = obj;
                                        collision[ret].obj_attr = vtmcrsObjectData.local[obj].obj_attr;
                                        collision[ret].attr = hit_data->type;
                                        collision[ret].no = hit_data->no;
                                        collision[ret].len = tmp[0] + tmp[1] + tmp[2];
                                        collision[ret].normal[3] = 1.0f;
                                        collision[ret].point[3] = 1.0f;
                                        ret += 1;
                                        continue;
                                    }
                                }
                                flag ^= 1;
                            }
                            hit_data = &src_vert[hit_data->nvertex];
                        }
                    }
                }
            }
        }
    }
    return ret;
}

signed int tmcrsCheckObjectCollision(float* src, float* dst) {
    signed int ii; // r16
    signed int kk; // r17
    signed int ll; // r18
    signed int flag; // r19
    // Size: 0x20, DWARF: 0x421F9
    Offset* offset; // r20
    // Size: 0x10, DWARF: 0x44340
    Collision* hit_data; // r23
    signed int ret; // r30
    signed int random; // r3
    float random1;
    float random2;
    signed int jj; // 0xB0(r29)
    signed int cnt; // 0xC0(r29)
    sceVu0FVECTOR* src_vert; // 0xD0(r29)
    signed int xy[2][2]; // 0xE0(r29)
    sceVu0FVECTOR normal; // 0xF0(r29)
    sceVu0FVECTOR position; // 0x100(r29)
    sceVu0FVECTOR rot; // 0x110(r29)
    sceVu0FVECTOR trans; // 0x120(r29)
    sceVu0FVECTOR tmp; // 0x130(r29)
    sceVu0FVECTOR dst_vert[32]; // 0x140(r29)
    sceVu0FMATRIX matrix; // 0x340(r29)
    signed int tmp_xy[2]; // 0x380(r29)
    signed int x; // 0x388(r29)
    signed int y; // 0x38C(r29)

    ret = 0;
    if (vtmcrsObjectData.top_addr == 0) {
        return -1;
    }
    tmcrsGetArea(&x, &y, src);
    tmcrsGetCenterPos(x, y, tmp);
    sceVu0SubVector(&tmp, src, &tmp);
    xy[0][0] = x;
    xy[0][1] = y;
    if (tmp[0] < 0.0f) {
        xy[1][0] = x - 1;
    } else {
        xy[1][0] = x + 1;
    }
    if (tmp[2] < 0.0f) {
        xy[1][1] = y - 1;
    } else {
        xy[1][1] = y + 1;
    }
    for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
        hit_data = vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->collision;
        if (hit_data == 0) {
            continue;
        }
        if (vtmcrsObjectData.local[ii].bound == 1) {
            continue;
        }
        if (vtmcrsObjectData.local[ii].divide == 1) {
            continue;
        }
        if (vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->divide_num == 0) {
            if (vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->bound == 0) {
                continue;
            }
        }
        if (vtmcrsObjectData.local[ii].draw == 0) {
            continue;
        }
        tmcrsGetArea(&tmp_xy[0], &tmp_xy[1], vtmcrsObjectData.local[ii].position);
        if (xy[0][0] > xy[1][0]) {
            if (xy[0][0] < tmp_xy[0] || xy[1][0] > tmp_xy[0]) {
                continue;
            }
        } else {
            if (xy[0][0] > tmp_xy[0]) {
                continue;
            }
            if (xy[1][0] < tmp_xy[0]) {
                continue;
            }
        }
        if (xy[0][1] > xy[1][1]) {
            if (xy[0][1] < tmp_xy[1] || xy[1][1] > tmp_xy[1]) {
                continue;
            }
        } else {
            if (xy[0][1] > tmp_xy[1]) {
                continue;
            }
            if (xy[1][1] < tmp_xy[1]) {
                continue;
            }
        }
        sceVu0SubVector(&tmp, vtmcrsObjectData.local[ii].position, src);
        sceVu0MulVector(&tmp, &tmp, &tmp);
        if ((tmp[0] + tmp[1] + tmp[2]) > vtmcrsObjectData.hit_length) {
            continue;
        }
        cnt = hit_data->num;
        for (jj = 0; jj < cnt; jj++) {
            flag = hit_data->flag;
            src_vert = hit_data + 1;
            for (kk = 0; kk < hit_data->nvertex; kk++) {
                sceVu0ApplyMatrix(dst_vert[kk], vtmcrsObjectData.local[ii].local_world, src_vert[kk]);
            }
            for (kk = 0; kk < hit_data->nvertex - 2; kk++) {
                if (flag) {
                    {
                        sceVu0FVECTOR* vert0 = &dst_vert[kk];
                        sceVu0FVECTOR* vert1 = &dst_vert[kk + 2];
                        sceVu0FVECTOR* vert2 = &dst_vert[kk + 1];

                        asm (
                            lqc2 $vf1, 0x0(src);
                            lqc2 $vf2, 0x0(dst);
                            lqc2 $vf3, 0x0(vert0);
                            lqc2 $vf4, 0x0(vert1);
                            lqc2 $vf5, 0x0(vert2);
                            vmax.xyz $vf12, $vf1, $vf2;
                            vmini.xyz $vf13, $vf1, $vf2;
                            vcallms 0x0;
                            qmfc2.i $a2, $vf0;
                            la v0, normal;
                            sqc2 $vf29, 0x0(v0);
                            la v0, position;
                            sqc2 $vf30, 0x0(v0);
                        );
                    }
                } else {
                    {
                        sceVu0FVECTOR* vert0 = &dst_vert[kk];
                        sceVu0FVECTOR* vert1 = &dst_vert[kk + 1];
                        sceVu0FVECTOR* vert2 = &dst_vert[kk + 2];

                        asm (
                            lqc2 $vf1, 0x0(src);
                            lqc2 $vf2, 0x0(dst);
                            lqc2 $vf3, 0x0(vert0);
                            lqc2 $vf4, 0x0(vert1);
                            lqc2 $vf5, 0x0(vert2);
                            vmax.xyz $vf12, $vf1, $vf2;
                            vmini.xyz $vf13, $vf1, $vf2;
                            vcallms 0x0;
                            qmfc2.i $a2, $vf0;
                            la v0, normal;
                            sqc2 $vf29, 0x0(v0);
                            la v0, position;
                            sqc2 $vf30, 0x0(v0);
                        );
                    }
                }
                if (1.0f == normal[3]) {
                    rot[0] = 0.0f;
                    rot[1] = (((float)(vtmcrsSystem.i_counter % 80) - 40.0f) / 100.0f) < -3.141592f
                        ? 6.283184f + (((float)(vtmcrsSystem.i_counter % 80) - 40.0f) / 100.0f)
                        : ((((float)(vtmcrsSystem.i_counter % 80) - 40.0f) / 100.0f) > 3.141592f ? (((float)(vtmcrsSystem.i_counter % 80) - 40.0f) / 100.0f) - 6.283184f : (((float)(vtmcrsSystem.i_counter % 80) - 40.0f) / 100.0f));
                    rot[2] = 0.0f;
                    rot[3] = 1.0f;
                    sceVu0UnitMatrix(matrix);
                    sceVu0RotMatrix(matrix, matrix, rot);
                    sceVu0SubVector(&trans, dst, src);
                    sceVu0MulVector(&tmp, &trans, &trans);
                    trans[0] = trans[0];
                    trans[1] = -((1.0f - vtmcrsObjectData.local[ii].weight) + sqrtf(tmp[0] + tmp[1] + tmp[2])) / 2.0f;
                    trans[2] = trans[2];
                    trans[3] = 1.0f;
                    if (trans[1] > 0.0f) {
                        trans[1] = 0.0f;
                    }
                    sceVu0ApplyMatrix(&trans, matrix, &trans);
                    if (vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->bound == 1) {
                        vtmcrsObjectData.local[ii].bound = 1;
                    } else {
                        trans[1] /= 4.0f;
                        vtmcrsObjectData.local[ii].divide = 1;
                        offset = (Offset*)((char*)vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type] + 0x20);
                        for (ll = 0; ll < vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->divide_num; ll++) {
                            random = rand() % 200;
                            random1 = (float)random / 100.0f - 1.0f;
                            random = rand() % 200;
                            random2 = (float)random / 100.0f - 1.0f;
                            random1 = (random1 + (trans[1] * trans[1]) / 256.0f) < -3.141592f
                                ? 6.283184f + (random1 + (trans[1] * trans[1]) / 256.0f)
                                : ((random1 + (trans[1] * trans[1]) / 256.0f) > 3.141592f ? (random1 + (trans[1] * trans[1]) / 256.0f) - 6.283184f : (random1 + (trans[1] * trans[1]) / 256.0f));
                            random2 = (random2 + (trans[1] * trans[1]) / 256.0f) < -3.141592f
                                ? 6.283184f + (random2 + (trans[1] * trans[1]) / 256.0f)
                                : ((random2 + (trans[1] * trans[1]) / 256.0f) > 3.141592f ? (random2 + (trans[1] * trans[1]) / 256.0f) - 6.283184f : (random2 + (trans[1] * trans[1]) / 256.0f));
                            vtmcrsObjectData.local[ii].divide_rot[ll][0] = random1;
                            vtmcrsObjectData.local[ii].divide_rot[ll][1] = random2;
                            vtmcrsObjectData.local[ii].divide_rot[ll][2] = 0.0f;
                            vtmcrsObjectData.local[ii].divide_rot[ll][3] = 1.0f;
                            random = rand() % 100;
                            vtmcrsObjectData.local[ii].divide_trans[ll][0] = (float)random / 10.0f + offset[ll].trans[0];
                            random = rand() % 100;
                            vtmcrsObjectData.local[ii].divide_trans[ll][1] = (float)random / 10.0f + offset[ll].trans[1];
                            random = rand() % 100;
                            vtmcrsObjectData.local[ii].divide_trans[ll][2] = (float)random / 10.0f + offset[ll].trans[2];
                            vtmcrsObjectData.local[ii].divide_trans[ll][3] = 1.0f;
                            sceVu0UnitMatrix(matrix);
                            sceVu0RotMatrix(matrix, matrix, vtmcrsObjectData.local[ii].divide_rot[ll]);
                            sceVu0MulMatrix(vtmcrsObjectData.local[ii].divide_mat[ll], vtmcrsObjectData.local[ii].local_world, matrix);
                            sceVu0AddVector(vtmcrsObjectData.local[ii].divide_mat[ll][3], vtmcrsObjectData.local[ii].divide_mat[ll][3], vtmcrsObjectData.local[ii].trans);
                            vtmcrsObjectData.local[ii].divide_mat[ll][3][3] = 1.0f;
                        }
                        tmcrsCalcObjectDivide(ii);
                        ret++;
                    }
                    random = vtmcrsSystem.i_counter % 100;
                    random1 = (random < 50) ? 1.0f : -1.0f;
                    random = vtmcrsSystem.i_counter % 100;
                    random2 = (random < 50) ? 1.0f : -1.0f;
                    random1 = (random1 * ((trans[1] * trans[1]) / 32.0f)) < -3.141592f
                        ? 6.283184f + (random1 * ((trans[1] * trans[1]) / 32.0f))
                        : ((random1 * ((trans[1] * trans[1]) / 32.0f)) > 3.141592f ? (random1 * ((trans[1] * trans[1]) / 32.0f)) - 6.283184f : (random1 * ((trans[1] * trans[1]) / 32.0f)));
                    random2 = (random2 * ((trans[1] * trans[1]) / 32.0f)) < -3.141592f
                        ? 6.283184f + (random2 * ((trans[1] * trans[1]) / 32.0f))
                        : ((random2 * ((trans[1] * trans[1]) / 32.0f)) > 3.141592f ? (random2 * ((trans[1] * trans[1]) / 32.0f)) - 6.283184f : (random2 * ((trans[1] * trans[1]) / 32.0f)));
                    rot[0] = random1;
                    rot[1] = random2;
                    rot[2] = 0.0f;
                    rot[3] = 1.0f;
                    if (0.0f != vtmcrsObjectData.local[ii].radius) {
                        if (vtmcrsSystem.i_counter % 100 < 50) {
                            rot[0] = 0.09817475f;
                        } else {
                            rot[0] = -0.09817475f;
                        }
                    }
                    tmcrsMoveObject(ii, rot, trans, 0);
                } else {
                    flag ^= 1;
                }
            }
            hit_data = (Collision*)&src_vert[hit_data->nvertex];
        }
    }
    return ret;
}

s32 tmcrsGetObjectBonkCollision(Col* collision /*sp80*/, f32* pos /*sp90*/) {
    signed int ii; // r16
    signed int ret; // r17
    // Size: 0x10, DWARF: 0x44340
    Collision* hit_data; // r18
    signed int xy[2][2]; // 0x40(r29)
    float position[4]; // 0x50(r29)
    float tmp[4]; // 0x60(r29)
    signed int tmp_xy[2]; // 0x70(r29)
    signed int x; // 0x78(r29)
    signed int y; // 0x7C(r29)

    ret = 0;
    if (vtmcrsObjectData.top_addr == 0) {
        return -1;
    }
    tmcrsGetArea(&x, &y, pos);
    tmcrsGetCenterPos(x, y, tmp);
    sceVu0SubVector(tmp, pos, tmp);
    xy[0][0] = x;
    xy[0][1] = y;
    if (tmp[0] < 0.0f) {
        xy[1][0] = x - 1;
    } else {
        xy[1][0] = x + 1;
    }
    if (tmp[2] < 0.0f) {
        xy[1][1] = y - 1;
    } else {
        xy[1][1] = y + 1;
    }
    for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
        if (vtmcrsObjectData.local[ii].bonk) {
            hit_data = vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->collision;
            if ((vtmcrsObjectData.local[ii].bound != 1) && (vtmcrsObjectData.local[ii].divide != 1) && (vtmcrsObjectData.local[ii].draw != 0)) {
                tmcrsGetArea(&tmp_xy[0], &tmp_xy[1], vtmcrsObjectData.local[ii].position);

                if (xy[0][0] > xy[1][0]) {
                    if (xy[0][0] < tmp_xy[0] || xy[1][0] > tmp_xy[0])
                        continue;
                }
                else if ((xy[0][0] > tmp_xy[0]) || (xy[1][0] < tmp_xy[0])) 
                    continue;

                if (xy[0][1] > xy[1][1]) {
                    if (xy[0][1] < tmp_xy[1] || xy[1][1] > tmp_xy[1])
                        continue;
                } else if ((xy[0][1] > tmp_xy[1]) || (xy[1][1] < tmp_xy[1]))
                    continue;

                sceVu0CopyVector(&position[0], vtmcrsObjectData.local[ii].position);
                position[0] += vtmcrsObjectData.local[ii].bonk_len[0];
                position[2] += vtmcrsObjectData.local[ii].bonk_len[2];
                position[1] -= vtmcrsObjectData.local[ii].bonk_len[1];
                sceVu0SubVector(tmp, &position[0], pos);
                sceVu0MulVector(tmp, tmp, tmp);
                if ((tmp[0] + tmp[1] + tmp[2]) < vtmcrsObjectData.local[ii].bonk_suction_len) {
                    collision[ret].len = (tmp[0] + tmp[1] + tmp[2]);
                    sceVu0CopyVector(collision[ret].point, &position[0]);
                    ret += 1;
                }                
            }
        }
    }
    return ret;
}

void tmcrsCalcObject() {
    signed int ii; // r16

    if (vtmcrsObjectData.top_addr != 0) {
        for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
            tmcrsCalcObjectUnit(ii);
        }
    }
}

void tmcrsCalcObjectUnit(s32 no) {
    signed int x; // 0x18(r29)
    signed int y; // 0x1C(r29)

    if (vtmcrsObjectData.top_addr != 0) {
        if (vtmcrsObjectData.local[no].bound == 1) {
            vtmcrsObjectData.local[no].calc = 1;
        }
        if (vtmcrsObjectData.local[no].divide == 1) {
            vtmcrsObjectData.local[no].calc = 1;
        }
        if (vtmcrsObjectData.local[no].calc != 0) {
            if (vtmcrsObjectData.local[no].abs == 1) {
                tmcrsCalcObjectAbs(no);
            } else if (vtmcrsObjectData.local[no].matrix == 1) {
                tmcrsCalcObjectMatrix(no);
            } else if (vtmcrsObjectData.local[no].local == 1) {
                tmcrsCalcObjectLocal(no);
            } else {
                tmcrsCalcObjectWorld(no);
            }
            tmcrsGetArea(&x, &y, vtmcrsObjectData.local[no].position);
            vtmcrsObjectData.data[no].block = tmcrsChangeNo(x, y);
            vtmcrsObjectData.local[no].calc = 0;
        }
    }
}

static void tmcrsCalcObjectAbs(s32 no) {
    float matrix[4][4]; // 0x10(r29)

    sceVu0UnitMatrix(vtmcrsObjectData.local[no].local_world);
    sceVu0RotMatrixX(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[0]);
    sceVu0RotMatrixY(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[1]);
    sceVu0RotMatrixZ(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[2]);
    sceVu0TransMatrix(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.trans);
    sceVu0UnitMatrix(&matrix);
    if (vtmcrsObjectData.local[no].xyz == 1) {
        sceVu0RotMatrixX(&matrix, &matrix, vtmcrsObjectData.local[no].rot[0]);
        sceVu0RotMatrixY(&matrix, &matrix, vtmcrsObjectData.local[no].rot[1]);
        sceVu0RotMatrixZ(&matrix, &matrix, vtmcrsObjectData.local[no].rot[2]);
    } else {
        sceVu0RotMatrix(&matrix, &matrix, vtmcrsObjectData.local[no].rot);
    }
    sceVu0AddVector(vtmcrsObjectData.local[no].local_world[3], vtmcrsObjectData.local[no].local_world[3], vtmcrsObjectData.local[no].trans);
    vtmcrsObjectData.local[no].local_world[3][3] = 1.0f;
    sceVu0MulMatrix(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, &matrix);
    sceVu0CopyVector(vtmcrsObjectData.local[no].position, vtmcrsObjectData.local[no].local_world[3]);
}

static void tmcrsCalcObjectMatrix(s32 no) {
    sceVu0UnitMatrix(vtmcrsObjectData.local[no].local_world);
    sceVu0RotMatrixX(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[0]);
    sceVu0RotMatrixY(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[1]);
    sceVu0RotMatrixZ(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.data[no].position.rot[2]);
    sceVu0MulMatrix(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_mat, vtmcrsObjectData.local[no].local_world);
    sceVu0CopyVector(vtmcrsObjectData.local[no].position, vtmcrsObjectData.local[no].local_world[3]);
}

static void tmcrsCalcObjectLocal(s32 no) {
    // s32 no;
    // f32 tmp3[3];
    // f32 tmp3[2];
    // f32 tmp3[1];
    // f32 tmp3[0];
    // f32 tmp2[3];
    // f32 tmp2[2];
    // ? matrix;
    // ? tmp;
    s32 var_a2;

    float tmp[4]; // 0x10(r29)
    float matrix[4][4]; // 0x20(r29)
    float tmp2[4]; // Not in dwarf, but needed for sp60
    float tmp3[4]; // Not in dwarf, but  needed for sp70

    // no = no; // 80
    if (vtmcrsObjectData.local[no].rotation[0] + (vtmcrsObjectData.local[no].rot[0]) < -3.141592f) {
        // var_a2 = no;
        tmp2[2] = 6.283184f + (vtmcrsObjectData.local[no].rotation[0] + vtmcrsObjectData.local[no].rot[0]);
    } else {
        // var_a2 = no * 9;
        if ((vtmcrsObjectData.local[no].rotation[0] + vtmcrsObjectData.local[no].rot[0]) > 3.141592f) {
            tmp2[3] = (vtmcrsObjectData.local[no].rotation[0] + vtmcrsObjectData.local[no].rot[0]) - 6.283184f;
        } else {
            // var_a2 = vtmcrsObjectData.local;
            tmp2[3] = vtmcrsObjectData.local[no].rotation[0] + vtmcrsObjectData.local[no].rot[0];
        }
        tmp2[2] = tmp2[3];
    }
    vtmcrsObjectData.local[no].rotation[0] = tmp2[2];
    if ((vtmcrsObjectData.local[no].rotation[1] + vtmcrsObjectData.local[no].rot[2]) < -3.141592f) {
        // var_a2 = no;
        tmp3[0] = 6.283184f + (vtmcrsObjectData.local[no].rotation[1] + vtmcrsObjectData.local[no].rot[2]);
    } else {
        if ((vtmcrsObjectData.local[no].rotation[1] + vtmcrsObjectData.local[no].rot[2]) > 3.141592f) {
            tmp3[1] = (vtmcrsObjectData.local[no].rotation[1] + vtmcrsObjectData.local[no].rot[2]) - 6.283184f;
        } else {
            tmp3[1] = vtmcrsObjectData.local[no].rotation[1] + vtmcrsObjectData.local[no].rot[2];
        }
        tmp3[0] = tmp3[1];
    }
    vtmcrsObjectData.local[no].rotation[1] = tmp3[0];
    if ((vtmcrsObjectData.local[no].rotation[2] + vtmcrsObjectData.local[no].rot[1]) < -3.141592f) {
        tmp3[2] = 6.283184f + (vtmcrsObjectData.local[no].rotation[2] + vtmcrsObjectData.local[no].rot[1]);
    } else {
        if ((vtmcrsObjectData.local[no].rotation[2] + vtmcrsObjectData.local[no].rot[1]) > 3.141592f) {
            tmp3[3] = (vtmcrsObjectData.local[no].rotation[2] + vtmcrsObjectData.local[no].rot[1]) - 6.283184f;
        } else {
            tmp3[3] = vtmcrsObjectData.local[no].rotation[2] + vtmcrsObjectData.local[no].rot[1];
        }
        tmp3[2] = tmp3[3];
    }
    vtmcrsObjectData.local[no].rotation[2] = tmp3[2];
    vtmcrsObjectData.local[no].rotation[3] = 1.0f;
    sceVu0UnitMatrix(&matrix);
    sceVu0RotMatrix(&matrix, &matrix, vtmcrsObjectData.local[no].rotation);
    sceVu0ApplyMatrix(&tmp, &matrix, vtmcrsObjectData.local[no].trans);
    sceVu0AddVector(vtmcrsObjectData.local[no].position, &tmp, vtmcrsObjectData.local[no].position);
    sceVu0UnitMatrix(vtmcrsObjectData.local[no].local_world);
    sceVu0RotMatrix(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].rotation);
    sceVu0TransMatrix(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].position);
}

static void tmcrsCalcObjectWorld(s32 no) {
    float matrix[4][4]; // 0x10(r29)

    sceVu0UnitMatrix(&matrix);
    sceVu0RotMatrix(&matrix, &matrix, vtmcrsObjectData.local[no].rot);
    sceVu0AddVector(vtmcrsObjectData.local[no].local_world[3], vtmcrsObjectData.local[no].local_world[3], vtmcrsObjectData.local[no].trans);
    vtmcrsObjectData.local[no].local_world[3][3] = 1.0f;
    sceVu0MulMatrix(vtmcrsObjectData.local[no].local_world, vtmcrsObjectData.local[no].local_world, &matrix);
    if (vtmcrsObjectData.local[no].bound == 1) {
        tmcrsCalcObjectBound(no);
    } else if (vtmcrsObjectData.local[no].divide == 1) {
        tmcrsCalcObjectDivide(no);
    }
    sceVu0CopyVector(vtmcrsObjectData.local[no].position, vtmcrsObjectData.local[no].local_world[3]);
}

static void tmcrsCalcObjectBound(s32 no) {
    signed int ii; // r16
    signed int col_tbl[4][2]; // 0x20(r29)
    sceVu0FVECTOR pos; // 0x40(r29)
    // Size: 0x60, DWARF: 0x42032
    // struct
    // {
    //     float normal[4]; // Offset: 0x0, DWARF: 0x4204D
    //     float point[4]; // Offset: 0x10, DWARF: 0x42072
    //     float* vertex[4]; // Offset: 0x20, DWARF: 0x42096
    //     unsigned int attr; // Offset: 0x24, DWARF: 0x420BE
    //     signed int nvertex; // Offset: 0x28, DWARF: 0x420DF
    //     signed int no; // Offset: 0x2C, DWARF: 0x42103
    //     float len; // Offset: 0x30, DWARF: 0x42122
    //     signed int rail_no; // Offset: 0x34, DWARF: 0x42142
    //     signed int obj_no; // Offset: 0x38, DWARF: 0x42166
    //     signed int obj_attr; // Offset: 0x3C, DWARF: 0x42189
    //     signed int obj_type; // Offset: 0x40, DWARF: 0x421AE
    //     signed int res[4]; // Offset: 0x44, DWARF: 0x421D3
    Col collision; // 0x50(r29)
    signed int x; // 0xB8(r29)
    signed int y; // 0xBC(r29)

    // no = no; // c0
    tmcrsGetArea(&x, &y, vtmcrsObjectData.local[no].position);
    col_tbl[0][0] = x;
    col_tbl[0][1] = y;
    col_tbl[2][0] = x;
    col_tbl[1][1] = y;
    tmcrsGetCenterPos(x, y, &pos);
    sceVu0SubVector(pos, vtmcrsObjectData.local[no].position, pos);
    if (pos[0] < 0.0f) {
        col_tbl[1][0] = x - 1;
        col_tbl[3][0] = x - 1;
    } else {
        col_tbl[1][0] = x + 1;
        col_tbl[3][0] = x + 1;
    }
    if (pos[2] < 0.0f) {
        col_tbl[2][1] = y - 1;
        col_tbl[3][1] = y - 1;
    } else {
        col_tbl[2][1] = y + 1;
        col_tbl[3][1] = y + 1;
    }
    for (ii = 0; ii < 4; ii++) {

        if (tmcrsGetBaseCollision(&collision, col_tbl[ii][0], col_tbl[ii][1], vtmcrsObjectData.local[no].position, vtmcrsObjectData.local[no].local_world[3]) != 0) {
            break;
        }
    }
    if (ii != 4) {
        if (vtmcrsObjectData.local[no].radius != 0.0f) {
            collision.point[1] -= vtmcrsObjectData.local[no].radius;
            vtmcrsObjectData.local[no].cnt = 0;
            vtmcrsObjectData.local[no].gravity = 0;
            vtmcrsObjectData.local[no].bound = 0;
            vtmcrsObjectData.local[no].trans[0] = 0.0f;
            vtmcrsObjectData.local[no].trans[1] = 0.0f;
            vtmcrsObjectData.local[no].trans[2] = 0.0f;
            vtmcrsObjectData.local[no].trans[3] = 1.0f;
            vtmcrsObjectData.local[no].rot[0] = 0.0f;
            vtmcrsObjectData.local[no].rot[1] = 0.0f;
            vtmcrsObjectData.local[no].rot[2] = 0.0f;
            vtmcrsObjectData.local[no].rot[3] = 1.0f;
            collision.point[3] = 1.0f;
            sceVu0CopyVector(vtmcrsObjectData.local[no].local_world[3], &collision.point);
            return;
        }
        vtmcrsObjectData.local[no].cnt = 0;
        vtmcrsObjectData.local[no].gravity = 0;
        vtmcrsObjectData.local[no].bound = 0;
        vtmcrsObjectData.local[no].trans[0] = 0.0f;
        vtmcrsObjectData.local[no].trans[1] = 0.0f;
        vtmcrsObjectData.local[no].trans[2] = 0.0f;
        vtmcrsObjectData.local[no].trans[3] = 1.0f;
        vtmcrsObjectData.local[no].rot[0] = 0.0f;
        vtmcrsObjectData.local[no].rot[1] = 0.0f;
        vtmcrsObjectData.local[no].rot[2] = 0.0f;
        vtmcrsObjectData.local[no].rot[3] = 1.0f;
        collision.point[3] = 1.0f;
        sceVu0CopyVector(vtmcrsObjectData.local[no].local_world[3], &collision.point);
        return;
    }
    tmcrsCalcObjectGravity(no);
    if (vtmcrsObjectData.local[no].radius != 0.0f) {
        if (vtmcrsObjectData.local[no].cnt == 0x10 || vtmcrsObjectData.local[no].hit == 1) {
            vtmcrsObjectData.local[no].rot[0] = 0.0f;
            vtmcrsObjectData.local[no].rot[1] = 0.0f;
            vtmcrsObjectData.local[no].rot[2] = 0.0f;
            vtmcrsObjectData.local[no].rot[3] = 1.0f;
            vtmcrsObjectData.local[no].hit = 1;
        }
    }
    vtmcrsObjectData.local[no].cnt++;
}

static void tmcrsCalcObjectDivide(s32 no /* s3 */) {
    // Size: 0x20, DWARF: 0x421F9
    Offset* offset; // r3 
    signed int ii; // r16 // s0
    signed int type; // r17 // s1
    signed int loop; // r18 // s2
    sceVu0FMATRIX matrix; // 0x50(r29)
    sceVu0FVECTOR trans; // 0x90(r29)

    tmcrsCalcObjectGravity(no);
    type = vtmcrsObjectData.data[no].type;
    offset = &vtmcrsObjectData.type[type][1].type;
    
    for (ii = 0; ii < vtmcrsObjectData.type[type]->divide_num; ii++) {
        sceVu0UnitMatrix(matrix);
        trans[0] = vtmcrsObjectData.local[no].divide_trans[ii][0] + (vtmcrsObjectData.local[no].cnt * vtmcrsObjectData.local[no].divide_trans[ii][0] * 0.1f);
        trans[1] = vtmcrsObjectData.local[no].divide_trans[ii][1] + (vtmcrsObjectData.local[no].cnt * vtmcrsObjectData.local[no].divide_trans[ii][1] * 0.1f);
        trans[2] = vtmcrsObjectData.local[no].divide_trans[ii][2] + (vtmcrsObjectData.local[no].cnt * vtmcrsObjectData.local[no].divide_trans[ii][2] * 0.1f);
        trans[3] = 1.0f;
        sceVu0CopyMatrix(vtmcrsObjectData.local[no].divide_mat[ii], vtmcrsObjectData.local[no].local_world);
        sceVu0RotMatrixX(matrix, matrix, vtmcrsObjectData.local[no].rotation[0]);
        sceVu0RotMatrixY(matrix, matrix, vtmcrsObjectData.local[no].rotation[1]);
        sceVu0RotMatrixZ(matrix, matrix, vtmcrsObjectData.local[no].rotation[2]);
        for (loop = 0; loop < 3; loop++) {
            if (vtmcrsObjectData.local[no].rotation[loop] <= 3.141592f && vtmcrsObjectData.local[no].rotation[loop] >= -3.141592f) {
            } else {
                printf("error\n");
                ABORT();
            }
            if (vtmcrsObjectData.local[no].divide_rot[ii][loop] > 3.141592f || vtmcrsObjectData.local[no].divide_rot[ii][loop] < -3.141592f) {
                printf("error\n");
                ABORT();
            }
        }
        sceVu0ApplyMatrix(&trans[0], matrix, &trans[0]);
        sceVu0RotMatrix(matrix, matrix, vtmcrsObjectData.local[no].divide_rot[ii]);
        sceVu0MulMatrix(vtmcrsObjectData.local[no].divide_mat[ii], vtmcrsObjectData.local[no].local_world, matrix);
        sceVu0AddVector(vtmcrsObjectData.local[no].divide_mat[ii][3], vtmcrsObjectData.local[no].divide_mat[ii][3], &trans[0]);
        vtmcrsObjectData.local[no].divide_mat[ii][3][3] = 1.0f;
    }
    vtmcrsObjectData.local[no].cnt += 1;
    if (vtmcrsObjectData.local[no].cnt >= 0x78) {
        vtmcrsObjectData.local[no].draw = 0;
        vtmcrsObjectData.local[no].divide = 0;
    }
}

static void tmcrsCalcObjectGravity(s32 no) {
    float tmp[4]; // 0x10(r29)

    vtmcrsObjectData.local[no].gravity++;
    sceVu0CopyVector(&tmp, vtmcrsObjectData.local[no].trans);
    vtmcrsObjectData.local[no].trans[1] += ((0.98f * vtmcrsObjectData.local[no].gravity) / 90.0f);
    if ((tmp[1] < 0.0f) && (vtmcrsObjectData.local[no].trans[1] > 0.0f)) {
        vtmcrsObjectData.local[no].trans[1] = 0.0f;
        vtmcrsObjectData.local[no].gravity = 0;
    }
}

void tmcrsBreakObject(signed int no, float* dir) {
    sceVu0FVECTOR trans; // 0x40(r29)
    sceVu0FVECTOR rot; // 0x50(r29)
    sceVu0FVECTOR tmp; // 0x60(r29)
    float random1; // 0x78(r29)
    float random2; // 0x7C(r29)
    signed int ii; // r16
    signed int random; // r17
    Offset* offset; // r18

    if (vtmcrsObjectData.local[no].divide == 1) {
        return;
    }
    sceVu0MulVector(tmp, dir, dir);
    trans[0] = dir[0];
    trans[1] = -sqrtf(tmp[0] + tmp[1] + tmp[2]) / 8.0f;
    trans[2] = dir[2];
    trans[3] = 1.0f;
    if (dir[1] > 0.0f) {
        trans[1] = -trans[1];
    }
    vtmcrsObjectData.local[no].divide = 1;
    offset = (Offset*)((char*)vtmcrsObjectData.type[vtmcrsObjectData.data[no].type] + 0x20);
    for (ii = 0; ii < vtmcrsObjectData.type[vtmcrsObjectData.data[no].type]->divide_num; ii++) {
        random = vtmcrsSystem.i_counter % 200;
        random1 = (float)random / 100.0f - 1.0f;
        random = vtmcrsSystem.i_counter % 200;
        random2 = (float)random / 100.0f - 1.0f;
        random1 = (random1 + trans[1] * trans[1] / 256.0f < -3.141592f) ? (6.283184f + (random1 + trans[1] * trans[1] / 256.0f))
            : ((random1 + trans[1] * trans[1] / 256.0f > 3.141592f) ? ((random1 + trans[1] * trans[1] / 256.0f) - 6.283184f) : random1 + trans[1] * trans[1] / 256.0f);
        random2 = (random2 + trans[1] * trans[1] / 256.0f < -3.141592f) ? (6.283184f + (random2 + trans[1] * trans[1] / 256.0f))
            : ((random2 + trans[1] * trans[1] / 256.0f > 3.141592f) ? ((random2 + trans[1] * trans[1] / 256.0f) - 6.283184f) : random2 + trans[1] * trans[1] / 256.0f);
        vtmcrsObjectData.local[no].divide_rot[ii][0] = random1;
        vtmcrsObjectData.local[no].divide_rot[ii][1] = random2;
        vtmcrsObjectData.local[no].divide_rot[ii][2] = 0.0f;
        vtmcrsObjectData.local[no].divide_rot[ii][3] = 1.0f;
        random = rand() % 100;
        vtmcrsObjectData.local[no].divide_trans[ii][0] = (float)random / 10.0f + offset[ii].trans[0];
        random = rand() % 100;
        vtmcrsObjectData.local[no].divide_trans[ii][1] = (float)random / 10.0f + offset[ii].trans[1];
        random = rand() % 100;
        vtmcrsObjectData.local[no].divide_trans[ii][2] = (float)random / 10.0f + offset[ii].trans[2];
        vtmcrsObjectData.local[no].divide_trans[ii][3] = 1.0f;
    }
    random = vtmcrsSystem.i_counter % 100;
    if (random < 50) {
        random1 = 1.0f;
    } else {
        random1 = -1.0f;
    }
    random = vtmcrsSystem.i_counter % 100;
    if (random < 50) {
        random2 = 1.0f;
    } else {
        random2 = -1.0f;
    }
    random1 = (random1 * (trans[1] * trans[1] / 128.0f) < -3.141592f) ? (6.283184f + (random1 * (trans[1] * trans[1] / 128.0f)))
            : ((random1 * (trans[1] * trans[1] / 128.0f) > 3.141592f) ? ((random1 * (trans[1] * trans[1] / 128.0f)) - 6.283184f) : random1 * (trans[1] * trans[1] / 128.0f));
    random2 = (random2 * (trans[1] * trans[1] / 128.0f) < -3.141592f) ? (6.283184f + (random2 * (trans[1] * trans[1] / 128.0f)))
            : ((random2 * (trans[1] * trans[1] / 128.0f) > 3.141592f) ? ((random2 * (trans[1] * trans[1] / 128.0f)) - 6.283184f) : random2 * (trans[1] * trans[1] / 128.0f));
    rot[0] = random1;
    rot[1] = random2;
    rot[2] = 0.0f;
    rot[3] = 1.0f;
    tmcrsCalcObjectDivide(no);
    tmcrsMoveObject(no, rot, trans, 0);
}

void tmcrsGetObjectLight(float* light_color, float* light_vector, float* pos) {
    signed int ii; // r16 $s0
    signed int col_index; // r17 $s1
    signed int length_index; // r18 $s2
    sceVu0FVECTOR tmp; // 0x60(r29)
    sceVu0FVECTOR normal; // 0x70(r29)
    float ftmp; // 0xCC(r29)
    float length[3] = {
        10000.0f,
        40000.0f,
        250000.0f
    }; // 0xC0(r29)
    float* unused1 = &length;
    sceVu0FMATRIX col_tbl = {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.5f, 0.4f, 0.4f, 0.0f },
        { 0.5f, 0.2f, 0.2f, 0.0f },
        { 0.2f, 0.2f, 0.5f, 0.0f }
    }; // 0x80(r29)
    float* unused2 = &col_tbl;

    light_color[0] = 0.0f;
    light_color[1] = 0.0f;
    light_color[2] = 0.0f;
    light_color[3] = 0.0f;
    light_vector[0] = 0.0f;
    light_vector[1] = 0.0f;
    light_vector[2] = 0.0f;
    light_vector[3] = 1.0f;
    ftmp = 1.6777e7f;
    col_index = 0;
    if (vtmcrsObjectData.top_addr != 0) {
        for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
            if ((vtmcrsObjectData.data[ii].light) && (vtmcrsObjectData.local[ii].draw != 0)) {
                sceVu0SubVector(&normal, pos, vtmcrsObjectData.local[ii].position);
                sceVu0MulVector(&tmp, &normal, &normal);
                if (((tmp[0] + tmp[1] + tmp[2]) < ftmp) && (tmp[0] + tmp[1] + tmp[2]) < (length[(((vtmcrsObjectData.data[ii].light)) - 1)])) {
                    col_index = vtmcrsObjectData.data[ii].color;
                    length_index = vtmcrsObjectData.data[ii].light - 1;
                    ftmp = tmp[0] + tmp[1] + tmp[2];
                    sceVu0Normalize(light_vector, &normal);
                }
            }
        }
        if (col_index != 0) {
            ftmp = (length[length_index] - ftmp) / length[length_index];
            sceVu0ScaleVector(light_color, col_tbl[col_index], ftmp);
        }
    }
}

static signed int tmcrsDrawObject(CourseParam* param) {
    signed int ii; // r16
    signed int type; // r17
    Data* data; // r18
    unsigned long* addr; // r19
    signed int old_type; // r20
    sceVu0FVECTOR tmp; // 0x60(r29)

    addr = sceVif1PkReserve(param->vif1_packet, 8);
    if (vtmcrsSystem.fog == 1) {
        *addr++ = *(unsigned long*)ltmasmSendPrgVu1Obj;
    } else {
        *addr++ = *(unsigned long*)ltmasmSendPrgVu1NonFogObj;
    }
    *addr++ = 0;
    *addr++ = *(unsigned long*)ltmasmSendMatrix;
    *addr++ = 0;
    if (vtmcrsObjectData.top_addr == 0) {
        return -1;
    }
    type = -1;
    old_type = -1;
    for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
        if (vtmcrsObjectData.local[ii].draw != 0) {
            sceVu0SubVector(tmp, param->camera_position[0], vtmcrsObjectData.local[ii].position);
            sceVu0MulVector(tmp, tmp, tmp);
            if (tmp[0] + tmp[1] + tmp[2] <= vtmcrsObjectData.draw_length * vtmcrsObjectData.draw_length) {
                if (type != vtmcrsObjectData.data[ii].type) {
                    type = vtmcrsObjectData.data[ii].type;
                    if (!vtmcrsObjectData.data[ii].alpha) {
                        addr = sceVif1PkReserve(param->vif1_packet, 8);
                        *addr++ = 0x10000001;
                        *addr++ = 0;
                        *addr++ = 0;
                        *addr++ = 0x11000000;
                        ultexSetTexPath2(param->vif1_packet, vtmcrsTexSystem.object[type].frame, vtmcrsTexSystem.object[type].offset, vtmcrsTexSystem.object[type].nblock);
                    }
                }
                if (vtmcrsObjectData.data[ii].alpha) {
                    if (vtmcrsObjectData.local[ii].divide == 1) {
                        data = vtmcrsObjectData.type[type]->divide;
                        tmcrsDrawObjectDivideAlpha(param, vtmcrsObjectData.local[ii].divide_mat, data, vtmcrsObjectData.type[type]->divide_num, vtmcrsObjectData.local[ii].scissor);
                    } else {
                        data = vtmcrsObjectData.type[type]->draw;
                        if (vtmcrsObjectData.data[ii].sprite) {
                            tmcrsDrawObjectSprite(param, vtmcrsObjectData.local[ii].local_world, data);
                        } else {
                            tmcrsDrawObjectAlpha(param, vtmcrsObjectData.local[ii].local_world, data, vtmcrsObjectData.local[ii].scissor);
                        }
                    }
                } else {
                    if (vtmcrsObjectData.local[ii].divide == 1) {
                        data = vtmcrsObjectData.type[type]->divide;
                        tmcrsDrawObjectDivideVIF1(param, vtmcrsObjectData.local[ii].divide_mat, data, vtmcrsObjectData.type[type]->divide_num, vtmcrsObjectData.local[ii].scissor);
                    } else {
                        data = vtmcrsObjectData.type[type]->draw;
                        if (vtmcrsObjectData.data[ii].sprite) {
                            tmcrsDrawObjectSprite(param, vtmcrsObjectData.local[ii].local_world, data);
                        } else {
                            tmcrsDrawObjectVIF1(param, vtmcrsObjectData.local[ii].local_world, data, vtmcrsObjectData.local[ii].scissor);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

static signed int tmcrsDrawObjectVIF1(CourseParam* param, sceVu0FMATRIX matrix, Data* data, signed int sc) {
    unsigned short scissor; // r20
    unsigned long* addr; // r16
    unsigned int size; // r18
    signed int ii; // r19
    TexBody* body; // r17

    body = (TexBody*)((char*)data + 0x10);
    if (sc == 1) {
        scissor = 0x8000;
    } else {
        scissor = 0;
    }

    addr = sceVif1PkReserve(param->vif1_packet, 8);
    *addr++ = 0x10000001;
    *addr++ = 0;
    *addr++ = 0;
    *addr++ = 0x11000000;

    addr = sceVif1PkReserve(param->vif1_packet, 4);
    *addr++ = ((unsigned long)(unsigned int)matrix << 32) | 0x30000004;
    *addr++ = (unsigned long)0x6C044004 << 32;

    addr = sceVif1PkReserve(param->vif1_packet, data->num * 12);
    for (ii = 0; ii < data->num; ii++) {
        body->attr &= 0x7FFF;
        body->attr |= scissor;
        size = body->size >> 4;
        *addr++ = (unsigned long)(size | 0x30000000) | ((unsigned long)(unsigned int)body << 32);
        *addr++ = (unsigned long)((size << 16) | 0x6C00C000) << 32;
        *addr++ = 0x10000001;
        *addr++ = 0;
        *addr++ = 0;
        *addr++ = (unsigned long)0x17000000 << 32;
        body = (TexBody*)((char*)body + body->size);
    }
    return 0;
}

static signed int tmcrsDrawObjectDivideVIF1(CourseParam* param, sceVu0FMATRIX* matrix, Data* data, signed int num, signed int sc) {
    unsigned short scissor; // r20
    unsigned long* addr; // r16
    unsigned int size; // r18
    signed int jj; // r19
    signed int ii; // r21
    TexBody* body; // r17

    if (sc == 1) {
        scissor = 0x8000;
    } else {
        scissor = 0;
    }
    for (ii = 0; ii < num; ii++) {
        body = (TexBody*)((char*)data + 0x10);

        addr = sceVif1PkReserve(param->vif1_packet, 8);
        *addr++ = 0x10000001;
        *addr++ = 0;
        *addr++ = 0;
        *addr++ = 0x11000000;

        addr = sceVif1PkReserve(param->vif1_packet, 4);
        *addr++ = ((unsigned long)(unsigned int)matrix[ii] << 32) | 0x30000004;
        *addr++ = (unsigned long)0x6C044004 << 32;

        addr = sceVif1PkReserve(param->vif1_packet, data->num * 12);
        for (jj = 0; jj < data->num; jj++) {
            body->attr &= 0x7FFF;
            body->attr |= scissor;
            size = body->size >> 4;
            *addr++ = (unsigned long)(size | 0x30000000) | ((unsigned long)(unsigned int)body << 32);
            *addr++ = (unsigned long)((size << 16) | 0x6C00C000) << 32;
            *addr++ = 0x10000001;
            *addr++ = 0;
            *addr++ = 0;
            *addr++ = (unsigned long)0x17000000 << 32;
            body = (TexBody*)((char*)body + body->size);
        }
        data = (Data*)body;
    }
    return 0;
}

static s32 tmcrsDrawObjectSprite(// Size: 0x30, DWARF: 0x4243D
CourseParam* param /*sp240*/, sceVu0FMATRIX matrix /*sp250*/, // Size: 0x10, DWARF: 0x41E92
Data* data /*sp260*/) {
    signed int ii; // r16 // s0
    // Size: 0x30, DWARF: 0x44405
    Vertex* vertex; // r17 // s1
    // Size: 0x10, DWARF: 0x4395D
    TexBody* body; // r18 // s2
    // Size: 0x140, DWARF: 0x4BFF1
    Matrix gmatrix; // 0x40(r29)
    // Size: 0x30, DWARF: 0x4E928
    GPrim gprim; // 0x180(r29)
    // Size: 0x20, DWARF: 0x4E1A2
    GVertex gvertex[4]; // 0x1B0(r29)
    sceVu0FVECTOR pos; // 0x230(r29)
    static unsigned long alpha_tbl[7]; // 0x2D9BC0 // alpha_tbl$1857

    pos[0] = 0.0f;
    pos[1] = 0.0f;
    pos[2] = 0.0f;
    pos[3] = 1.0f;
    body = data + 1;
    vertex = body + 2;
    gprim.test = 0x50000;
    gprim.prim = 0x25C;
    gprim.tex = body->tex_id;
    gprim.tex1 = tmcrsGetTex1Register(1);
    gprim.alpha = alpha_tbl[body->alpha];
    gprim.scissor = 0;
    memcpy(&gmatrix, param->matrix, 0x140);
    sceVu0MulMatrix(&gmatrix, &gmatrix, matrix);
    sceVu0MulMatrix(&gmatrix.local_clip, &gmatrix.local_clip, matrix);
    gvertex[0].width = 2.0f * vertex->vertex[0];
    gvertex[0].height = 2.0f * vertex->vertex[2];
    if ((gvertex[0].height > 0.0f)) {
        gvertex[0].height = -gvertex[0].height;
    }
    if (gvertex[0].width < 0.0f) {
        gvertex[0].width = -gvertex[0].width;
    }
    gvertex[0].vertex = pos;
    for (ii = 0; ii < 4; ii++) {
        gvertex[ii].rgba = vertex[ii].rgba;
        gvertex[ii].stq = vertex[ii].stq;
    }
    tmgraphRTPSpriteAddAlphaBufT__(param->alpha, param->screen->screen_z, &gvertex, &gmatrix, &gprim);
    return 0;
}

static s32 tmcrsDrawObjectAlpha(// Size: 0x30, DWARF: 0x4243D
CourseParam* param /*sp5E0*/, sceVu0FMATRIX matrix /*sp5F0*/, // Size: 0x10, DWARF: 0x41E92
Data* data /*sp600*/, signed int sc /*sp610*/) {
    signed int kk; // r16 // s0
    // Size: 0x30, DWARF: 0x44405
    Vertex* vertex; // r17 // s1
    // Size: 0x10, DWARF: 0x44057
    Prim2* prim; // r18 // s2
    // Size: 0x10, DWARF: 0x4395D
    TexBody* body; // r19 // s3
    signed int jj; // r20 // s4
    signed int ii; // r21 // s5
    // Size: 0x30, DWARF: 0x4E928
    GPrim gprim; // 0x70(r29)
    // Size: 0x20, DWARF: 0x4E1A2
    GVertex gvertex[32]; // 0xA0(r29)
    // Size: 0x140, DWARF: 0x4BFF1
    Matrix gmatrix; // 0x4A0(r29)
    static unsigned long alpha_tbl[7]; // 0x2D9C00 // alpha_tbl$1871

    body = data + 0x1;
    gprim.test = 0x50000;
    gprim.tex1 = tmcrsGetTex1Register(1);
    memcpy(&gmatrix, param->matrix, 0x140);
    sceVu0MulMatrix(&gmatrix, &gmatrix, matrix);
    sceVu0MulMatrix(&gmatrix.local_clip, &gmatrix.local_clip, matrix);
    for (ii = 0; ii < data->num; ii++) {
        prim = body + 1;
        for (jj = 0; jj < body->nprim; jj++) {
            gprim.tex = body->tex_id;
            if (body->alpha) {
                gprim.prim = 0x25C;
            } else {
                gprim.prim = 0x21C;
            }
            gprim.alpha = alpha_tbl[body->alpha];
            if (sc == 1) {
                gprim.scissor = 1;
            } else {
                gprim.scissor = 0;
            }
            vertex = prim + 0x1;
            for (kk = 0; kk < prim->nvertex; kk++) {
                gvertex[kk].vertex = vertex;
                gvertex[kk].stq = (Prim2*)vertex + 1;
                gvertex[kk].rgba = (Prim2*)vertex + 2;
                vertex += 1;
            }
            tmgraphRTPAddAlphaBufG_T__(param->alpha, prim->nvertex, &gvertex, &gmatrix, &gprim);
            prim = vertex;
        }
        body = vertex;
    }
    return 0;
}

static s32 tmcrsDrawObjectDivideAlpha(// Size: 0x30, DWARF: 0x4243D
CourseParam* param /*sp5F0*/, sceVu0FMATRIX* matrix /*sp600*/, // Size: 0x10, DWARF: 0x41E92
Data* data /*sp610*/, signed int num /*sp620*/, signed int sc /*sp630*/) {
    signed int ll; // r16 // s0
    // Size: 0x30, DWARF: 0x44405
    Vertex* vertex; // r17 // s1
    // Size: 0x10, DWARF: 0x44057
    Prim2* prim; // r18 // s2
    signed int kk; // r19 // s3
    // Size: 0x10, DWARF: 0x4395D
    TexBody* body; // r20 // s4
    signed int jj; // r21 // s5
    signed int ii; // r22 // s6
    // Size: 0x30, DWARF: 0x4E928
    GPrim gprim; // 0x80(r29)
    // Size: 0x20, DWARF: 0x4E1A2
    GVertex gvertex[32]; // 0xB0(r29)
    // Size: 0x140, DWARF: 0x4BFF1
    Matrix gmatrix; // 0x4B0(r29)
    static unsigned long alpha_tbl[7]; // 0x2D9C40 // alpha_tbl$1897

    for (ii = 0; ii < num; ii++) {
        body = data + 1;
        gprim.test = 0x50000;
        gprim.tex1 = tmcrsGetTex1Register(1);
        if (sc == 1) {
            gprim.scissor = 1;
        } else {
            gprim.scissor = 0;
        }
        memcpy(&gmatrix, param->matrix, 0x140);
        sceVu0MulMatrix(&gmatrix, &gmatrix, matrix[ii]);
        sceVu0MulMatrix(&gmatrix.local_clip, &gmatrix.local_clip, matrix[ii]);
        for (jj = 0; jj < data->num; jj++) {
            prim = body + 1;
            gprim.tex = body->tex_id;
            if (body->alpha) {
                gprim.prim = 0x25C;
            } else {
                gprim.prim = 0x21C;
            }
            gprim.alpha = alpha_tbl[body->alpha];
            for (kk = 0; kk < body->nprim; kk++) {
                vertex = prim + 1;
                for (ll = 0; ll < prim->nvertex; ll++) {
                    gvertex[ll].vertex = vertex;
                    gvertex[ll].stq = (Prim2*)vertex + 1;
                    gvertex[ll].rgba = (Prim2*)vertex + 2;
                    vertex += 1;
                }
                tmgraphRTPAddAlphaBufG_T__(param->alpha, prim->nvertex, &gvertex, &gmatrix, &gprim);
                prim = vertex;
            }
            body = vertex;
        }
        data = body;
    }
    return 0;
}

static void tmcrsSetObjectBlockData() {
    signed int ii; // r16
    signed int block; // r17
    float pos[4]; // 0x30(r29)
    signed int x; // 0x48(r29)
    signed int y; // 0x4C(r29)

    for (ii = 0; ii < (vtmcrsBaseModel[0].head[0].nblock); ii++) {
        vtmcrsObjectData.nobj[ii] = 0;
    }
    for (ii = 0; ii < vtmcrsObjectData.head[0].num; ii++) {
        tmcrsGetObjectPosition(&pos, ii);
        tmcrsGetArea(&x, &y, &pos);
        block = tmcrsChangeNo(x, y);
        if (block != -1) {
            vtmcrsObjectData.block[block][vtmcrsObjectData.nobj[block]] = ii;
            vtmcrsObjectData.nobj[block]++;
        }
    }
}

static void tmcrsEndObject() {
    signed int ii; // r16

    if (vtmcrsObjectData.top_addr) {
        for (ii = 0; ii < vtmcrsObjectData.head->num; ii++) {
            ulFree(vtmcrsObjectData.local[ii].divide_mat);
            ulFree(vtmcrsObjectData.local[ii].divide_trans);
            ulFree(vtmcrsObjectData.local[ii].divide_rot);
        }
        ulFree(vtmcrsObjectData.type);
        ulFree(vtmcrsObjectData.local);
        for (ii = 0; ii < vtmcrsBaseModel[0].head->nblock; ii++) {
            ulFree(vtmcrsObjectData.block[ii]);
        }
        ulFree(vtmcrsObjectData.block);
        ulFree(vtmcrsObjectData.nobj);
    }
}

static s32 tmcrsInitEvent(CourseData* data, s32 offset) {
    signed int ii; // r16
    signed int crs_tbl[8] = { 0, 0, 2, 0, 0, 0, 0, 0 }; // 0x30(r29)
    s32* crs_tbl_ptr = &crs_tbl;

    for (ii = 0; ii < 0x20; ii++) {
        vtmcrsEventModel[ii].uad = 0;
        vtmcrsEventModel[ii].umd = 0;
        vtmcrsEventModel[ii].tex.addr = 0;
        vtmcrsEventModel[ii].tex.frame = 0;
    }
    vtmcrsEventSystem.param = 0;
    vtmcrsEventSystem.cnt = 0;
    if (data->event_uad == 0) {
        return -1;
    }
    maMdlMotionMap(data->event_uad);
    for (ii = 0; ii < vtmcrsDivideNum[3]; ii++) {
        vtmcrsEventModel[ii].uad = data->event_uad;
        vtmcrsEventModel[ii].umd = data->event_umd[ii];
        vtmcrsEventModel[ii].tex.addr = data->event_utd[ii];
        vtmcrsEventModel[ii].tex.offset = 0x3C00;
        vtmcrsEventModel[ii].alpha = 0;
        if (vtmcrsSystem.crs_no == 2) {
            if (ii == 2) {
                vtmcrsEventModel[ii].tex.offset = offset;
                vtmcrsEventModel[ii].alpha = 1;
            }
        } else if ((vtmcrsSystem.crs_no == 4) && (ii == 0)) {
            vtmcrsEventModel[ii].tex.offset = offset;
            vtmcrsEventModel[ii].alpha = 1;
        }
        vtmcrsEventModel[ii].tex.ntex = ultexGetNTex(vtmcrsEventModel[ii].tex.addr);
        vtmcrsEventModel[ii].tex.nblock = ultexGetUseBlock(vtmcrsEventModel[ii].tex.addr);
        vtmcrsEventModel[ii].tex.frame = ulMalloc(ultexGetUseMemory(vtmcrsEventModel[ii].tex.nblock), 0, 0);
        vtmcrsEventModel[ii].tex.data = ulMalloc(ultexGetNTex(vtmcrsEventModel[ii].tex.addr) * 0x10, 0, 0);
        ultexResetTex(vtmcrsEventModel[ii].tex.offset);
        ultexTransTex(vtmcrsEventModel[ii].tex.addr, vtmcrsEventModel[ii].tex.data);
        ultexGetTex(vtmcrsEventModel[ii].tex.frame, vtmcrsEventModel[ii].tex.offset, vtmcrsEventModel[ii].tex.nblock);
        ulvumdlInitModel((unsigned char*)vtmcrsEventModel[ii].umd, vtmcrsEventModel[ii].tex.data, vtmcrsEventModel[ii].tex.data);
        ulFree(vtmcrsEventModel[ii].tex.data);
        vtmcrsEventModel[ii].seq = maMdlMotionInit(vtmcrsEventModel[ii].uad, crs_tbl[vtmcrsSystem.crs_no]);
    }
    return 0;
}

static void tmcrsEndEvent() {
    signed int ii; // r16

    for (ii = 0; ii < vtmcrsDivideNum[3]; ii++) {
        maMdlMotionInitEnd(vtmcrsEventModel[ii].seq);
        ulFree(vtmcrsEventModel[ii].tex.frame);
    }
}

void tmcrsResetEventModel(s32 num, CourseDrawParam* param) {
    signed int ii; // r16
    
    vtmcrsEventSystem.cnt = num;
    vtmcrsEventSystem.param = param;
    for (ii = 0; ii < vtmcrsEventSystem.cnt; ii++) {
        vtmcrsEventSystem.param[ii].old_id = vtmcrsEventSystem.param[ii].id;
        vtmcrsEventSystem.param[ii].cnt = 0;
        vtmcrsEventSystem.param[ii].flag = 0;
        vtmcrsEventSystem.param[ii].pos[0] = 0.0f;
        vtmcrsEventSystem.param[ii].pos[1] = 0.0f;
        vtmcrsEventSystem.param[ii].pos[2] = 0.0f;
        vtmcrsEventSystem.param[ii].pos[3] = 1.0f;
    }
}

f32 tmcrsGetEventModelFrame(s32 no, s32 id) {
    unsigned int tmp = (u32)vtmcrsEventModel[no].uad; // 0x18(r29)
    float frame = maGetMdlMotionFrame(&tmp, id); // 0x1C(r29)
    return frame;
}

void tmcrsDrawEventModel(CourseParam* param) {
    signed int jj; // r16
    signed int ii; // r17
    // Size: 0x160, DWARF: 0x4FA68
    Vmenv mdlenv; // 0x30(r29)
    tag_ulcodCOORDINATE coord; // 0x190(r29)
    float light_color[4][4]; // 0x220(r29)
    float normal_light[4][4]; // 0x260(r29)

    if (vtmcrsEventSystem.param == 0) {
        return;
    }
    
    tmcrsCalcEventModel();
    for (ii = 0; ii < vtmcrsEventSystem.cnt; ++ii) {
        if (vtmcrsEventSystem.param[ii].draw != 0) {
            ulcodInitCoordinate(&coord.super, 0);
            ulcodSetWvMatrix(&vspSystemMatrix[param->player].world_view);
            ulcodSetVsMatrix(&vspSystemMatrix[param->player].view_screen);
            sceVu0CopyMatrix(&coord.mat, vtmcrsEventSystem.param[ii].matrix);
            coord.flag = 0;
            mdlenv.enable = 2;
            tmgraphGetFogCoef(&mdlenv.fog, &mdlenv.fog.b, param->fog);
            for (jj = 0; jj < 3; jj++) {
                light_color[jj][0] = 0.0f;
                light_color[jj][1] = 0.0f;
                light_color[jj][2] = 0.0f;
                light_color[jj][3] = 1.0f;
            }
            light_color[3][0] = 0.5f;
            light_color[3][1] = 0.5f;
            light_color[3][2] = 0.5f;
            light_color[3][3] = 1.0f;
            if (vtmcrsEventSystem.param[ii].light == 1) {
                sceVu0LightColorMatrix(&light_color, vspRider[param->player]->disp.light_color0, vspRider[param->player]->disp.light_color1, vspRider[param->player]->disp.light_color2, vspRider[param->player]->disp.ambient);
                light_color[3][0] = 0.4f;
                light_color[3][1] = 0.4f;
                light_color[3][2] = 0.4f;
                light_color[3][3] = 1.0f;
            }
            sceVu0NormalLightMatrix(&normal_light, vspRider[param->player]->disp.normal_light0, vspRider[param->player]->disp.normal_light1, vspRider[param->player]->disp.normal_light2);
            light_color[2][0] = 0.0f;
            light_color[2][1] = 0.0f;
            light_color[2][2] = 0.0f;
            light_color[2][3] = 1.0f;
            if (vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].alpha == 0) {
                ultexSetTexPath2(param->vif1_packet, vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].tex.frame, vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].tex.offset, vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].tex.nblock);
            }
            ulvumdlDrawModel(param->vif1_packet, param->alpha, &coord, normal_light, light_color, (__int128*)vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].umd, &mdlenv);
        }
    }
}

void tmcrsCalcEventModel() {
    signed int ii; // r16
    float matrix[4][4]; // 0x20(r29)
    unsigned int tmp; // 0x6C(r29)

    maSetModelScaleCancel(1);
    for (ii = 0; ii < vtmcrsEventSystem.cnt; ii++) {
        if (vtmcrsEventSystem.param[ii].draw) {
            tmp = (s32)vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].uad;
            if (vtmcrsEventSystem.param[ii].old_id != vtmcrsEventSystem.param[ii].id) {
                if (vtmcrsEventSystem.param[ii].cnt == 0) {
                    vtmcrsEventSystem.param[ii].flag = 1;
                }
                maMdlMotionRealBrendDirect(&tmp, vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].seq, vtmcrsEventSystem.param[ii].flag, vtmcrsEventSystem.param[ii].id, vtmcrsEventSystem.param[ii].frame, (vtmcrsEventSystem.param[ii].cnt * 0.2f));
                vtmcrsEventSystem.param[ii].flag = 0;
                vtmcrsEventSystem.param[ii].cnt++;
                if (5 < vtmcrsEventSystem.param[ii].cnt) {
                    vtmcrsEventSystem.param[ii].cnt = 0;
                    vtmcrsEventSystem.param[ii].old_id = vtmcrsEventSystem.param[ii].id;
                }
            } else {
                maMdlMotionDirect(&tmp, vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].seq, vtmcrsEventSystem.param[ii].id, vtmcrsEventSystem.param[ii].frame);
            }
            maVuMdlMotionCtrl(vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].umd, vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].uad, vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].seq, (unsigned int*)&tmp);
            sceVu0UnitMatrix(&matrix);
            if (ulvumdlGetMatrix(&matrix, (__int128*)vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].umd, 0) == 0) {
                ulvumdlGetMatrix(&matrix, (__int128*)vtmcrsEventModel[vtmcrsEventSystem.param[ii].no].umd, 0x3E9);
            }
            sceVu0AddVector(vtmcrsEventSystem.param[ii], &matrix[3], vtmcrsEventSystem.param[ii].matrix[3]);
        }
    }
    maSetModelScaleCancel(0);
}

s32 tmcrsGetEventModelHit(float* pos, s32 no, float len) {
    signed int ret = 0; // r16
    float tmp[4]; // 0x20(r29)
    
    sceVu0SubVector(&tmp, pos, vtmcrsEventSystem.param[no].pos);
    sceVu0MulVector(&tmp, &tmp, &tmp);
    if (tmp[0] + tmp[1] + tmp[2] < (len * len)) {
        ret = 1;
    }
    return ret;
}

void tmcrsSetFog(s32 fog) {
    vtmcrsSystem.fog = fog;
}

void tmcrsGetArea(s32* x, s32* y, float* pos) {
    if (pos[0] > 0.0f) {
        *x = (300.0f + pos[0]) / 600.0f;
    } else {
        *x = (pos[0] - 300.0f) / 600.0f;
    }
    if (pos[2] > 0.0f) {
        *y = (300.0f + pos[2]) / 600.0f;
        return;
    }
    *y = (pos[2] - 300.0f) / 600.0f;
}

void tmcrsGetCenterPos(s32 x, s32 y, float* pos) {
    pos[0] = (600.0f * x);
    pos[1] = 0.0f;
    pos[2] = (600.0f * y);
    pos[3] = 1.0f;
}

s32 tmcrsChangeNo(s32 x, s32 y) {
    signed int ret; // r16
    signed int tmp_x; // r17
    signed int tmp_y; // r18

    tmp_x = x - vtmcrsBaseModel[0].head->offset_x;
    tmp_y = y - vtmcrsBaseModel[0].head->offset_y;
    if ((tmp_x <= vtmcrsBaseModel[0].head->size_x) && (tmp_y <= vtmcrsBaseModel[0].head->size_y) && (tmp_x >= 0) && (tmp_y >= 0)) {
        ret = (x -vtmcrsBaseModel[0].head->offset_x) + ((vtmcrsBaseModel[0].head->size_x * (y -vtmcrsBaseModel[0].head->offset_y)));
    } else {
        ret = -1;
    }
    return ret;
}

void tmcrsResetRailCollision() {
    signed int ii; // r16

    if (vtmcrsRailData.top_addr != 0) {
        for (ii = 0; ii < vtmcrsRailData.head->num; ii++) {
            vtmcrsRailData.collision[ii] = 1;
        }
    }
}

void tmcrsSetRailCollision(s32 no, s32 collision) {
    vtmcrsRailData.collision[no] = collision;
}

void tmcrsResetHitCollision() {
    signed int ii; // r16
    for (ii = 0; ii < 0x40; ii++) {
        vtmcrsSystem.hit.hit[ii] = -1;
        vtmcrsSystem.hit.attr[ii] = -1;
        vtmcrsSystem.hit.base[ii] = -1;
    }
    vtmcrsSystem.hit.counter = 0;
}

s32 tmcrsSetHitCollision(s32 no, s32 attr, s32 base) {
    signed int ret; // r16

    if (vtmcrsSystem.hit.counter < 0x40) {
        vtmcrsSystem.hit.hit[vtmcrsSystem.hit.counter] = no;
        vtmcrsSystem.hit.attr[vtmcrsSystem.hit.counter] = attr;
        vtmcrsSystem.hit.base[vtmcrsSystem.hit.counter] = base;
        vtmcrsSystem.hit.counter++;
        ret = 0;
    } else {
        ret = -1;
    }
    return ret;
}

static signed int tmcrsGetDrawArea(CourseParam* param, signed int x, signed int y) {
    sceVu0FVECTOR pos; // 0x60(r29)
    signed int len; // r20
    signed int block; // r17
    signed int cnt; // r19
    signed int jj; // r16
    signed int ii; // r18

    cnt = 0;
    vtmcrsSystem.draw_nblock = 0;
    len = vtmcrsSystem.draw_len / 600.0f;
    block = tmcrsChangeNo(x, y);
    tmcrsGetCenterPos(x, y, pos);
    sceVu0SubVector(pos, param->camera_position[0], pos);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block | 0x8000;
        if (vtmcrsSystem.mipmdl_level > 0) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x + 1, y);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[0] > 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x - 1, y);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[0] < 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x, y + 1);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[2] > 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x, y - 1);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[2] < 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x + 1, y + 1);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[0] > 0.0f && pos[2] > 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x + 1, y - 1);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[0] > 0.0f && pos[2] < 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x - 1, y + 1);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[0] < 0.0f && pos[2] > 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    block = tmcrsChangeNo(x - 1, y - 1);
    if (block >= 0 && block < vtmcrsSystem.nblock) {
        vtmcrsSystem.draw_block[cnt] = block;
        if (pos[0] < 0.0f && pos[2] < 0.0f) {
            vtmcrsSystem.draw_block[cnt] |= 0x8000;
        }
        if (vtmcrsSystem.mipmdl_level >= 2) {
            vtmcrsSystem.draw_block[cnt] |= 0x4000;
        }
        cnt++;
    }
    for (ii = 0; ii < len; ii++) {
        for (jj = 0; jj < len; jj++) {
            if (ii < 2 && jj < 2) {
                continue;
            }
            if (tmcrsCheckDrawArea(param, x + jj, y + ii)) {
                block = tmcrsChangeNo(x + jj, y + ii);
                if (block >= 0 && block < vtmcrsSystem.nblock) {
                    vtmcrsSystem.draw_block[cnt] = block;
                    if (ii < vtmcrsSystem.mipmdl_level && jj < vtmcrsSystem.mipmdl_level) {
                        vtmcrsSystem.draw_block[cnt] |= 0x4000;
                    }
                    cnt++;
                }
            }
            if (jj) {
                if (tmcrsCheckDrawArea(param, x - jj, y + ii)) {
                    block = tmcrsChangeNo(x - jj, y + ii);
                    if (block >= 0 && block < vtmcrsSystem.nblock) {
                        vtmcrsSystem.draw_block[cnt] = block;
                        if (ii < vtmcrsSystem.mipmdl_level && jj < vtmcrsSystem.mipmdl_level) {
                            vtmcrsSystem.draw_block[cnt] |= 0x4000;
                        }
                        cnt++;
                    }
                }
            }
            if (ii) {
                if (tmcrsCheckDrawArea(param, x + jj, y - ii)) {
                    block = tmcrsChangeNo(x + jj, y - ii);
                    if (block >= 0 && block < vtmcrsSystem.nblock) {
                        vtmcrsSystem.draw_block[cnt] = block;
                        if (ii < vtmcrsSystem.mipmdl_level && jj < vtmcrsSystem.mipmdl_level) {
                            vtmcrsSystem.draw_block[cnt] |= 0x4000;
                        }
                        cnt++;
                    }
                }
                if (jj) {
                    if (tmcrsCheckDrawArea(param, x - jj, y - ii)) {
                        block = tmcrsChangeNo(x - jj, y - ii);
                        if (block >= 0 && block < vtmcrsSystem.nblock) {
                            vtmcrsSystem.draw_block[cnt] = block;
                            if (ii < vtmcrsSystem.mipmdl_level && jj < vtmcrsSystem.mipmdl_level) {
                                vtmcrsSystem.draw_block[cnt] |= 0x4000;
                            }
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    vtmcrsSystem.draw_nblock = cnt;
    return 0;
}

static s32 tmcrsCheckDrawArea(CourseParam* param, s32 x, s32 y) {
    signed int ret; // r16
    float center[4]; // 0x20(r29)
    float tmp[4]; // 0x30(r29)
    float angle; // 0x40(r29)
    float view_angle; // 0x44(r29)

    ret = 0;
    tmcrsGetCenterPos(x, y, &center);
    sceVu0SubVector(&tmp, &center, param->camera_position[0]);
    angle = atan2f(tmp[0], tmp[2]);
    if (vtmcrsSystem.view_angle == -1.0f) {
        view_angle = 0.5f + param->view_angle;
    } else {
        view_angle = vtmcrsSystem.view_angle;
    }
    angle = (angle - (*param->camera_rotation)[1]) < -3.141592f
        ? 6.283184f + (angle - (*param->camera_rotation)[1])
        : ((angle - (*param->camera_rotation)[1]) > 3.141592f)
            ? (angle - (*param->camera_rotation)[1]) - 6.283184f
            : angle - (*param->camera_rotation)[1];
    if ((angle < view_angle) && (angle > -view_angle)) {
        ret = 1;
    }
    return ret;
}

void tmcrsSetViewAngle(f32 angle) {
    vtmcrsSystem.view_angle = angle;
}

void tmcrsSetMipModelLevel(s32 block) {
    vtmcrsSystem.mipmdl_level = block;
}

asm signed int David_CheckBaseBlock() {
        sw $s0, -0x4($sp);
        sw $s1, -0x8($sp);
        sw $s2, -0xC($sp);
        sw $s3, -0x10($sp);
        sw $s4, -0x14($sp);
        sw $s5, -0x18($sp);
        sw $s6, -0x1C($sp);
        sw $s7, -0x20($sp);
        or $v0, $0, $0;
        addi $a2, $a2, -0x1;
        ori $t7, $zero, 0xE0;
    nextblock:
        lw $t1, 0x320($a0);
        nop;
        lqc2 $vf1, 0x0($t1);
        lqc2 $vf2, 0x10($t1);
        vcallms 0x7A8;
        vnop;
        cfc2.ni $t6, $vi2;
        nop;
        nop;
        beq $t6, $t7, inbound;
        nop;
        lhu $t1, 0xA($a1);
        nop;
        b nextloop;
        addu $a1, $a1, $t1;
    inbound:
        lhu $t1, 0x8($a1);
        lhu $v1, 0xC($a1);
        addiu $t0, $a1, 0x10;
        addi $t1, $t1, -0x1;
        andi $v1, $v1, 0x7FFF;
    nextprim:
        lw $t3, 0x0($t0);
        lw $t4, 0x4($t0);
        addiu $t2, $t0, 0x10;
        addi $t3, $t3, -0x3;
        lqc2 $vf1, 0x0($t2);
        lqc2 $vf2, 0x30($t2);
        beqz $t4, notflipped;
        nop;
        vmove.xyzw $vf31, $vf1;
        vmove.xyzw $vf1, $vf2;
        vmove.xyzw $vf2, $vf31;
    notflipped:
        lqc2 $vf3, 0x60($t2);
        addiu $t2, $t2, 0x30;
        vcallms 0x658;
        vnop;
        cfc2.ni $t6, $vi2;
        nop;
        nop;
        bne $t6, $t7, nexttri;
        nop;
        qmfc2.ni $s0, $vf7;
        qmfc2.ni $s1, $vf8;
        qmfc2.ni $s2, $vf9;
        qmfc2.ni $s3, $vf10;
        pextlw $s4, $s1, $s0;
        pextuw $s5, $s1, $s0;
        pextlw $s6, $s3, $s2;
        pextuw $s7, $s3, $s2;
        pcpyld $s0, $s6, $s4;
        pcpyud $s1, $s4, $s6;
        pcpyld $s2, $s7, $s5;
        pcpyud $s3, $s5, $s7;
        qmtc2.ni $s0, $vf7;
        qmtc2.ni $s1, $vf8;
        qmtc2.ni $s2, $vf9;
        qmtc2.ni $s3, $vf10;
        addi $t5, $a3, -0x1;
        visub $vi1, $vi1, $vi1;
        addiu $t8, $a0, 0x0;
        addiu $t9, $a0, 0x300;
    nextray:
        lqc2 $vf16, 0x30($t8);
        vcallms 0x7F0;
        vnop;
        cfc2.ni $t6, $vi3;
        lw $at, 0x0($t9);
        nop;
        beqz $t6, rayadvance;
        addi $at, $at, 0x1;
        cfc2.ni $t6, $vi2;
        sw $at, 0x0($t9);
        ori $v0, $v0, 0x1;
        beqz $t6, rayadvance;
        nop;
        sw $v1, 0x24($t8);
        vmove.x $vf16, $vf12;
        sqc2 $vf16, 0x30($t8);
        sqc2 $vf14, 0x10($t8);
        sqc2 $vf13, 0x0($t8);
    rayadvance:
        addiu $t9, $t9, 0x4;
        addiu $t8, $t8, 0x60;
        bnez $t5, nextray;
        addi $t5, $t5, -0x1;
    nexttri:
        bnez $t4, swapped;
        nop;
        vmove.xyzw $vf1, $vf3;
        b tridone;
        nop;
    swapped:
        vmove.xyzw $vf2, $vf3;
    tridone:
        xori $t4, $t4, 0x1;
        bnez $t3, notflipped;
        addi $t3, $t3, -0x1;
        addiu $t0, $t2, 0x60;
        bnez $t1, nextprim;
        addi $t1, $t1, -0x1;
        addi $a1, $t0, 0x20;
    nextloop:
        bnez $a2, nextblock;
        addi $a2, $a2, -0x1;
        lw $s0, -0x4($sp);
        lw $s1, -0x8($sp);
        lw $s2, -0xC($sp);
        lw $s3, -0x10($sp);
        lw $s4, -0x14($sp);
        lw $s5, -0x18($sp);
        lw $s6, -0x1C($sp);
        lw $s7, -0x20($sp);
        jr $ra;
        nop;
}

asm void David_PutRaysInVU0() {
        addi $a2, $a2, -0x1;
        visub $vi1, $vi1, $vi1;
        lqc2 $vf1, 0x0($a0);
        lqc2 $vf2, 0x0($a1);
        addiu $a0, $a0, 0x10;
        addiu $a1, $a1, 0x10;
        vmax.xyz $vf29, $vf1, $vf2;
        vmini.xyz $vf30, $vf1, $vf2;
        vmove.w $vf1, $vf0;
        vmove.w $vf2, $vf0;
        vsqi.xyzw $vf1, ($vi1++);
        vsqi.xyzw $vf2, ($vi1++);
        beqz $a2, done;
        addi $a2, $a2, -0x1;
    nextray:
        lqc2 $vf1, 0x0($a0);
        lqc2 $vf2, 0x0($a1);
        addiu $a0, $a0, 0x10;
        addiu $a1, $a1, 0x10;
        vmax.xyz $vf29, $vf29, $vf1;
        vmini.xyz $vf30, $vf30, $vf1;
        vmax.xyz $vf29, $vf29, $vf2;
        vmini.xyz $vf30, $vf30, $vf2;
        vmove.w $vf1, $vf0;
        vmove.w $vf2, $vf0;
        vsqi.xyzw $vf1, ($vi1++);
        vsqi.xyzw $vf2, ($vi1++);
        bnez $a2, nextray;
        addi $a2, $a2, -0x1;
    done:
        jr $ra;
        nop;
}

signed int David_GetBaseCollision2(Col* collision, signed int* ret, signed int x, signed int y, signed int num) {
    BaseRes* baseRes; // r17
    Data* data; // r19
    signed int block; // r18
    signed int ii; // r16
    signed int hit; // r20

    baseRes = (BaseRes*)0x70000000;
    hit = 0;
    for (ii = 0; ii < num; ii++) {
        baseRes->collisions[ii].len = 16777000.0f;
        baseRes->rets[ii] = 0;
    }
    if (vtmcrsBaseModel[0].top_addr == 0) {
        return hit;
    }
    block = tmcrsChangeNo(x, y);
    if (block < 0 || !(block < vtmcrsBaseModel[0].head->nblock)) {
        return hit;
    }
    for (ii = 0; ii < vtmcrsDivideNum[0]; ii++) {
        if (vtmcrsBaseModel[ii].block[block] != 0) {
            data = (Data*)vtmcrsBaseModel[ii].block[block];
            baseRes->firstBound = &g_davidBodyBounds[g_davidBodyBoundIndices[ii][block]];
            if (David_CheckBaseBlock(baseRes, (Data*)((char*)data + 0x20), data->num, num)) {
                hit = 1;
            }
        }
    }
    for (ii = 0; ii < num; ii++) {
        ret[ii] = baseRes->rets[ii];
        memcpy(&collision[ii], &baseRes->collisions[ii], 0x60);
    }
    return hit;
}

asm signed int David_CheckHitData() {
        sw $s0, -0x4($sp);
        sw $s1, -0x8($sp);
        sw $s2, -0xC($sp);
        sw $s3, -0x10($sp);
        sw $s4, -0x14($sp);
        sw $s5, -0x18($sp);
        sw $s6, -0x1C($sp);
        sw $s7, -0x20($sp);
        lw $v1, 0x8($a2);
        lw $t3, 0x0($a2);
        lw $a2, 0x4($a2);
        ori $t7, $zero, 0xE0;
        or $v0, $0, $0;
        addi $a1, $a1, -0x1;
    nextblock:
        lw $t1, 0x4($a0);
        lw $t2, 0xC($a0);
        addiu $t0, $a0, 0x10;
        lqc2 $vf1, 0x0($t0);
        lqc2 $vf2, 0x10($t0);
        addiu $t0, $t0, 0x20;
        beqz $t2, noswap;
        addi $t1, $t1, -0x3;
        vmove.xyzw $vf3, $vf1;
        vmove.xyzw $vf1, $vf2;
        vmove.xyzw $vf2, $vf3;
    noswap:
        lqc2 $vf3, 0x0($t0);
        addiu $t0, $t0, 0x10;
        vcallms 0x658;
        vnop;
        cfc2.ni $t6, $vi2;
        nop;
        nop;
        bne $t6, $t7, nexttri;
        nop;
        qmfc2.ni $s0, $vf7;
        qmfc2.ni $s1, $vf8;
        qmfc2.ni $s2, $vf9;
        qmfc2.ni $s3, $vf10;
        pextlw $s4, $s1, $s0;
        pextuw $s5, $s1, $s0;
        pextlw $s6, $s3, $s2;
        pextuw $s7, $s3, $s2;
        pcpyld $s0, $s6, $s4;
        pcpyud $s1, $s4, $s6;
        pcpyld $s2, $s7, $s5;
        pcpyud $s3, $s5, $s7;
        qmtc2.ni $s0, $vf7;
        qmtc2.ni $s1, $vf8;
        qmtc2.ni $s2, $vf9;
        qmtc2.ni $s3, $vf10;
        addi $t5, $a3, -0x1;
        visub $vi1, $vi1, $vi1;
        add $t4, $0, $0;
        vmove.xyzw $vf16, $vf0;
    nextray:
        vcallms 0x7F0;
        vnop;
        cfc2.ni $t6, $vi3;
        nop;
        nop;
        beqz $t6, rayadvance;
        nop;
        ori $v0, $v0, 0x1;
        addu $t6, $t4, $a2;
        lw $t6, 0x0($t6);
        addu $t8, $t4, $t3;
        lw $t8, 0x0($t8);
        sll $t9, $t6, 6;
        sll $at, $t6, 5;
        addu $t9, $t9, $at;
        addu $t8, $t8, $t9;
        addi $t6, $t6, 0x1;
        addu $t9, $t4, $a2;
        sw $t6, 0x0($t9);
        lqc2 $vf18, 0x30($t8);
        sqc2 $vf13, 0x0($t8);
        sqc2 $vf14, 0x10($t8);
        vmove.x $vf18, $vf12;
        sqc2 $vf18, 0x30($t8);
        addi $s5, $0, -0x1;
        lw $t6, 0x0($v1);
        lhu $s3, 0xA($a0);
        addiu $s0, $v1, 0x10;
        addiu $s1, $s0, 0x100;
        addiu $s2, $s1, 0x100;
        beqz $t6, matched;
        addi $t6, $t6, -0x1;
    scan:
        lw $s4, 0x0($s0);
        bne $s3, $s4, scannext;
        nop;
        lw $s5, 0x0($s1);
        b matched;
        lw $s6, 0x0($s2);
    scannext:
        addiu $s0, $s0, 0x4;
        addiu $s1, $s1, 0x4;
        addiu $s2, $s2, 0x4;
        bnez $t6, scan;
        addi $t6, $t6, -0x1;
    matched:
        addi $at, $s5, 0x1;
        beqz $at, notmatched;
        nop;
        sw $s5, 0x2C($t8);
        b rayadvance;
        sw $s6, 0x24($t8);
    notmatched:
        lhu $at, 0x8($a0);
        sw $s3, 0x2C($t8);
        sw $at, 0x24($t8);
    rayadvance:
        addi $t4, $t4, 0x4;
        bnez $t5, nextray;
        addi $t5, $t5, -0x1;
    nexttri:
        bnez $t2, swapped;
        xori $t2, $t2, 0x1;
        vmove.xyzw $vf1, $vf3;
        b tridone;
        nop;
    swapped:
        vmove.xyzw $vf2, $vf3;
    tridone:
        bnez $t1, noswap;
        addi $t1, $t1, -0x1;
        addu $a0, $t0, $zero;
        bnez $a1, nextblock;
        addi $a1, $a1, -0x1;
        lw $s0, -0x4($sp);
        lw $s1, -0x8($sp);
        lw $s2, -0xC($sp);
        lw $s3, -0x10($sp);
        lw $s4, -0x14($sp);
        lw $s5, -0x18($sp);
        lw $s6, -0x1C($sp);
        lw $s7, -0x20($sp);
        jr $ra;
        nop;
}

signed int David_GetHitCollision2(Col** collision, signed int* ret, signed int x, signed int y, sceVu0FVECTOR* src, sceVu0FVECTOR* dst, signed int num) {
    HitRes hitRes; // 0x50(r29)
    Collision* data; // r19
    signed int hit; // r17
    signed int ii; // r16
    signed int block; // r18

    hit = 0;
    for (ii = 0; ii < num; ii++) {
        ret[ii] = 0;
    }
    if (vtmcrsHitData.top_addr == 0) {
        return hit;
    }
    block = tmcrsChangeNo(x, y);
    if (block < 0 || block >= vtmcrsHitData.head->nblock || vtmcrsHitData.block[block] == 0) {
        return hit;
    }
    David_PutRaysInVU0(src, dst, num);
    data = (Collision*)vtmcrsHitData.block[block];
    hitRes.collision = collision;
    hitRes.ret = ret;
    hitRes.hit = &vtmcrsSystem.hit;
    hit = David_CheckHitData(data, data->num, &hitRes, num);
    return hit;
}

void David_tmcrsInitBlockBound() {
    signed int ii; // 0x9C(r29)
    signed int boundI; // 0xA0(r29)
    signed int block; // 0xA4(r29)
    Data* data; // 0xA8(r29)
    signed int trap; // 0xAC(r29)
    signed int vv; // r16
    Vertex* vertex; // r17
    Bounds* boundPtr; // r18
    signed int ll; // r19
    Prim2* prim; // r20
    signed int kk; // r21
    TexBody* body; // r22
    signed int jj; // r23
    signed int size; // r30

    boundI = 0;
    for (ii = 0; ii < vtmcrsDivideNum[0]; ii++) {
        for (block = 0; block < vtmcrsBaseModel[ii].head->nblock; block++) {
            if (vtmcrsBaseModel[ii].block[block] != 0) {
                if (boundI >= 0x400);
                if (block >= 0x401);
                g_davidBodyBoundIndices[ii][block] = boundI;
                boundPtr = &g_davidBodyBounds[boundI];
                boundI++;
                boundPtr->max[0] = -16000000.0f;
                boundPtr->max[1] = -16000000.0f;
                boundPtr->max[2] = -16000000.0f;
                boundPtr->max[3] = 1.0f;
                boundPtr->min[0] = 16000000.0f;
                boundPtr->min[1] = 16000000.0f;
                boundPtr->min[2] = 16000000.0f;
                boundPtr->min[3] = 1.0f;
                data = (Data*)vtmcrsBaseModel[ii].block[block];
                body = (TexBody*)((char*)data + 0x20);
                for (jj = 0; jj < data->num; jj++) {
                    prim = (Prim2*)((char*)body + 0x10);
                    size = body->size;
                    if (size & 0xF) {
                        trap = 0;
                    }
                    for (kk = 0; kk < body->nprim; kk++) {
                        vertex = (Vertex*)((char*)prim + 0x10);
                        for (ll = 0; ll < prim->nvertex; ll++) {
                            for (vv = 0; vv < 3; vv++) {
                                if (vertex->vertex[vv] > boundPtr->max[vv]) {
                                    boundPtr->max[vv] = vertex->vertex[vv];
                                }
                                if (vertex->vertex[vv] < boundPtr->min[vv]) {
                                    boundPtr->min[vv] = vertex->vertex[vv];
                                }
                            }
                            vertex++;
                        }
                        prim = (Prim2*)vertex;
                    }
                    body = (TexBody*)((char*)prim + 0x20);
                }
            }
        }
    }
}

signed int David_tmcrsGetObjectCollision2(Col** collision, signed int* ret, sceVu0FVECTOR* src, sceVu0FVECTOR* dst, signed int num) {
    signed int ii; // r16
    signed int hit; // r17

    hit = 0;
    for (ii = 0; ii < num; ii++) {
        ret[ii] = 0;
        ret[ii] = David_tmcrsGetObjectCollision(collision[ii], src[ii], dst[ii]);
        if (ret[ii] > 0) {
            hit = 1;
        }
    }
    return hit;
}

signed int David_tmcrsGetObjectCollision(Col* collision, float* src, float* dst) {
    signed int xy[2][2]; // 0xA0(r29)
    sceVu0FVECTOR tmp; // 0xB0(r29)
    sceVu0FVECTOR dst_vert[32]; // 0xC0(r29)
    sceVu0FMATRIX matrix; // 0x2C0(r29)
    signed int block[4]; // 0x300(r29)
    signed int x; // 0x314(r29)
    signed int y; // 0x318(r29)
    signed int no; // 0x31C(r29)
    signed int kk; // r16
    signed int ret; // r17
    Collision* hit_data; // r18
    signed int ii; // r19
    signed int flag; // r20
    sceVu0FVECTOR* src_vert; // r21
    signed int jj; // r22
    signed int cnt; // r23
    signed int obj; // r30

    if (vtmcrsObjectData.top_addr == 0) {
        return -1;
    }
    ret = 0;
    tmcrsGetArea(&x, &y, src);
    tmcrsGetCenterPos(x, y, tmp);
    sceVu0SubVector(tmp, src, tmp);
    xy[0][0] = x;
    xy[0][1] = y;
    if (tmp[0] < 0.0f) {
        xy[1][0] = x - 1;
    } else {
        xy[1][0] = x + 1;
    }
    if (tmp[2] < 0.0f) {
        xy[1][1] = y - 1;
    } else {
        xy[1][1] = y + 1;
    }
    block[0] = tmcrsChangeNo(xy[0][0], xy[0][1]);
    block[1] = tmcrsChangeNo(xy[1][0], xy[0][1]);
    block[2] = tmcrsChangeNo(xy[0][0], xy[1][1]);
    block[3] = tmcrsChangeNo(xy[1][0], xy[1][1]);
    for (no = 0; no < 4; no++) {
        if (block[no] == -1) {
            continue;
        }
        for (obj = 0; obj < vtmcrsObjectData.nobj[block[no]]; obj++) {
            ii = vtmcrsObjectData.block[block[no]][obj];
            sceVu0SubVector(tmp, vtmcrsObjectData.local[ii].position, src);
            sceVu0MulVector(tmp, tmp, tmp);
            if (tmp[0] + tmp[1] + tmp[2] <= vtmcrsObjectData.hit_length) {
                hit_data = vtmcrsObjectData.type[vtmcrsObjectData.data[ii].type]->collision;
                if (hit_data == 0) {
                    continue;
                }
                if (vtmcrsObjectData.local[ii].bound == 1) {
                    continue;
                }
                if (vtmcrsObjectData.local[ii].divide == 1) {
                    continue;
                }
                if (vtmcrsObjectData.local[ii].draw == 0) {
                    continue;
                }
                cnt = hit_data->num;
                for (jj = 0; jj < cnt; jj++) {
                    flag = hit_data->flag;
                    src_vert = (sceVu0FVECTOR*)((char*)hit_data + 0x10);
                    for (kk = 0; kk < hit_data->nvertex; kk++) {
                        sceVu0ApplyMatrix(dst_vert[kk], vtmcrsObjectData.local[ii].local_world, src_vert[kk]);
                    }
                    for (kk = 0; kk < hit_data->nvertex - 2; kk++) {
                        if (tmcrsCheckCollisionBound(src, dst, dst_vert[kk], dst_vert[kk + 1], dst_vert[kk + 2]) == 1) {
                            if (flag) {
                                tmcrsMakeCollisionMatrix(matrix, dst_vert[kk], dst_vert[kk + 2], dst_vert[kk + 1]);
                            } else {
                                tmcrsMakeCollisionMatrix(matrix, dst_vert[kk], dst_vert[kk + 1], dst_vert[kk + 2]);
                            }
                            if (tmcrsGetCollisionSub(collision[ret].point, collision[ret].normal, matrix, src, dst) == 1) {
                                sceVu0SubVector(tmp, collision[ret].point, src);
                                sceVu0MulVector(tmp, tmp, tmp);
                                collision[ret].obj_type = vtmcrsObjectData.data[ii].type;
                                collision[ret].obj_no = ii;
                                collision[ret].obj_attr = vtmcrsObjectData.local[ii].obj_attr;
                                collision[ret].attr = hit_data->type;
                                collision[ret].no = hit_data->no;
                                collision[ret].len = tmp[0] + tmp[1] + tmp[2];
                                collision[ret].normal[3] = 1.0f;
                                collision[ret].point[3] = 1.0f;
                                ret++;
                                continue;
                            }
                        }
                        flag ^= 1;
                    }
                    hit_data = (Collision*)((char*)src_vert + hit_data->nvertex * 16);
                }
            }
        }
    }
    return ret;
}
