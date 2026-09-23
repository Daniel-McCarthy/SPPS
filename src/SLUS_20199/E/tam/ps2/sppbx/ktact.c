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
typedef int sceVu0IVECTOR[4] __attribute__((aligned(16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned(16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

// Helper Structs/Enums
typedef enum GameMode
{
    Career = 0,
    Multiplayer = 1,
    FreeRide = 2
} GameMode;

typedef enum MatchRule
{
    MatchAttack = 0,
    MatchBoost = 1,
    MatchPush = 2,
    MatchHorse = 3
} MatchRule;

// Common structs ///////////

// Size: 0x24, DWARF: 0x7D86F
typedef struct Key_Config
{
    signed int vibration; // Offset: 0x0, DWARF: 0x7D88B
    signed int spin_l; // Offset: 0x4, DWARF: 0x7D8B1
    signed int spin_r; // Offset: 0x8, DWARF: 0x7D8D4
    signed int stance; // Offset: 0xC, DWARF: 0x7D8F7
    signed int revert; // Offset: 0x10, DWARF: 0x7D91A
    signed int grind; // Offset: 0x14, DWARF: 0x7D93D
    signed int grab; // Offset: 0x18, DWARF: 0x7D95F
    signed int jump; // Offset: 0x1C, DWARF: 0x7D980
    signed int flip; // Offset: 0x20, DWARF: 0x7D9A1
} Key_Config;
/////////////////////////////

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
typedef struct Param
{
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
    sceVu0FVECTOR cross; // Offset: 0x0, DWARF: 0x79C58
    sceVu0FVECTOR normal; // Offset: 0x10, DWARF: 0x79C7C
    unsigned short material; // Offset: 0x20, DWARF: 0x79CA1
    unsigned short attribute; // Offset: 0x22, DWARF: 0x79CC6
    signed short almighty1; // Offset: 0x24, DWARF: 0x79CEC
    signed short almighty2; // Offset: 0x26, DWARF: 0x79D12
    signed short almighty3; // Offset: 0x28, DWARF: 0x79D38
    signed short slidable; // Offset: 0x2A, DWARF: 0x79D5E
    signed int available; // Offset: 0x2C, DWARF: 0x79D83
} Plane;

// Size: 0x2F8, DWARF: 0x7AA0C
typedef struct _anon18
{
    // Size: 0x30, DWARF: 0x79C3C
    Plane plane[8]; // Offset: 0x0, DWARF: 0x7AA28
    float from[8][4]; // Offset: 0x180, DWARF: 0x7AA4C
    float to[8][4]; // Offset: 0x200, DWARF: 0x7AA6F
    signed int move[8]; // Offset: 0x280, DWARF: 0x7AA90
    float height[8]; // Offset: 0x2A0, DWARF: 0x7AAB3
    signed int ret[8]; // Offset: 0x2C0, DWARF: 0x7AAD8
    signed int touch; // Offset: 0x2E0, DWARF: 0x7AAFA
    signed int num; // Offset: 0x2E4, DWARF: 0x7AB1C
    signed int ofs; // Offset: 0x2E8, DWARF: 0x7AB3C
    signed int id_touch; // Offset: 0x2EC, DWARF: 0x7AB5C
    signed int id_head; // Offset: 0x2F0, DWARF: 0x7AB81
    signed int id_body; // Offset: 0x2F4, DWARF: 0x7ABA5
} _anon18;

// Size: 0x10, DWARF: 0x797EF
typedef union _anon8
{
    __int128 ul128; // Offset: 0x0, DWARF: 0x79824
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0x79846
    unsigned int ui[4]; // Offset: 0x0, DWARF: 0x79867
    unsigned short us[8]; // Offset: 0x0, DWARF: 0x79888
    unsigned char uc[16]; // Offset: 0x0, DWARF: 0x798A9
    __int128 sl128; // Offset: 0x0, DWARF: 0x798CA
    signed long sl[2]; // Offset: 0x0, DWARF: 0x798EC
    signed int si[4]; // Offset: 0x0, DWARF: 0x7990D
    signed short ss[8]; // Offset: 0x0, DWARF: 0x7992E
    signed char sc[16]; // Offset: 0x0, DWARF: 0x7994F
    float fvec[4]; // Offset: 0x0, DWARF: 0x79970
} _anon8;

// Size: 0x60, DWARF: 0x75E44
typedef struct Col
{
    sceVu0FVECTOR normal; // Offset: 0x0, DWARF: 0x75E5F
    sceVu0FVECTOR point; // Offset: 0x10, DWARF: 0x75E84
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
} Col;

// Size: 0x60, DWARF: 0x79DD3, 0x16E55B
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
    sceVu0FVECTOR nextpos; // Offset: 0x0, DWARF: 0x7B083
    sceVu0FVECTOR speed; // Offset: 0x10, DWARF: 0x7B0A9
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
} Flip __attribute__((aligned(16)));

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
    Pos prepos2 __attribute__((aligned(16))); // Offset: 0x90, DWARF: 0x16ACED
    // Size: 0x60, DWARF: 0x16E55B
    Pos prepos __attribute__((aligned(16))); // Offset: 0xF0, DWARF: 0x16AD13
    // Size: 0x60, DWARF: 0x16E55B
    Pos nowpos __attribute__((aligned(16))); // Offset: 0x150, DWARF: 0x16AD38
    // Size: 0x60, DWARF: 0x16E55B
    Pos nextpos __attribute__((aligned(16))); // Offset: 0x1B0, DWARF: 0x16AD5D
    // Size: 0x8, DWARF: 0x168106
    Pad nowpad __attribute__((aligned(16))); // Offset: 0x210, DWARF: 0x16AD83
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
} ModelData;

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
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0xBB5B6
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

// Size: 0x3C, DWARF: 0x7ACCF
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x7ACEB
    signed int player; // Offset: 0x4, DWARF: 0x7AD0A
    signed int wear; // Offset: 0x8, DWARF: 0x7AD2D
    signed int board; // Offset: 0xC, DWARF: 0x7AD4E
    // Size: 0x1C, DWARF: 0x7C601
    Character_Param chr_param; // Offset: 0x10, DWARF: 0x7AD70
    // Size: 0x10, DWARF: 0x7A1DB
    Board_Param brd_param; // Offset: 0x2C, DWARF: 0x7AD98
} Character;

// Size: 0x4, DWARF: 0x7BBEA
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0x7BC06
} CourseNo;

// Size: 0x18, DWARF: 0x7BDBB
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x7BDD7
    signed int game_mode; // Offset: 0x4, DWARF: 0x7BDFE
    signed int match_rule; // Offset: 0x8, DWARF: 0x7BE24
    signed int divide; // Offset: 0xC, DWARF: 0x7BE4B
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x7BE6E
} Mode;

// Size: 0xA0, DWARF: 0x78E67
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x7BBEA
    CourseNo course; // Offset: 0x0, DWARF: 0x78E82
    // Size: 0x3C, DWARF: 0x7ACCF
    Character character[2]; // Offset: 0x4, DWARF: 0x78EA7
    // Size: 0x18, DWARF: 0x7BDBB
    Mode mode; // Offset: 0x7C, DWARF: 0x78ECF
    signed int language; // Offset: 0x94, DWARF: 0x78EF2
    signed int ending; // Offset: 0x98, DWARF: 0x78F17
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x78F3A
} VspenvGame;

// Size: 0x18, DWARF: 0x7D14B
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0x7D167
    signed int month; // Offset: 0x4, DWARF: 0x7D188
    signed int day; // Offset: 0x8, DWARF: 0x7D1AA
    signed int hour; // Offset: 0xC, DWARF: 0x7D1CA
    signed int minute; // Offset: 0x10, DWARF: 0x7D1EB
    signed int second; // Offset: 0x14, DWARF: 0x7D20E
} Clock;

// Size: 0x38, DWARF: 0x7E106
typedef struct File
{
    // Size: 0x18, DWARF: 0x7D14B
    Clock clock; // Offset: 0x0, DWARF: 0x7E122
    char name[32]; // Offset: 0x18, DWARF: 0x7E146
} File;

// Size: 0x20, DWARF: 0x7DD98
typedef struct Record
{
    signed int chr_no; // Offset: 0x0, DWARF: 0x7DDB4
    unsigned long score; // Offset: 0x8, DWARF: 0x7DDD7
    char name[16]; // Offset: 0x10, DWARF: 0x7DDF9
} Record;

// Size: 0x4, DWARF: 0x7EA50
typedef struct Best_Time
{
    unsigned int time; // Offset: 0x0, DWARF: 0x7EA6C
} Best_Time;

// Size: 0x8, DWARF: 0x7FFFF
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0x8001B
    signed int bgm; // Offset: 0x4, DWARF: 0x8003A
} Volume;

// Size: 0x48, DWARF: 0x815AC
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0x815C8
    signed int disable; // Offset: 0x40, DWARF: 0x815EC
    signed int random; // Offset: 0x44, DWARF: 0x81610
} Bgm;

// Size: 0x114, DWARF: 0x81EAA
typedef struct Option
{
    // Size: 0x24, DWARF: 0x7D86F
    Key_Config key_config[2]; // Offset: 0x0, DWARF: 0x81EC6
    // Size: 0x30, DWARF: 0x7DAC1
    Cheats enable; // Offset: 0x48, DWARF: 0x81EEF
    // Size: 0x30, DWARF: 0x7DAC1
    Cheats cheats; // Offset: 0x78, DWARF: 0x81F14
    // Size: 0x8, DWARF: 0x7FFFF
    Volume volume; // Offset: 0xA8, DWARF: 0x81F39
    char name[16]; // Offset: 0xB0, DWARF: 0x81F5E
    signed int divide; // Offset: 0xC0, DWARF: 0x81F81
    signed int tutorial; // Offset: 0xC4, DWARF: 0x81FA4
    // Size: 0x48, DWARF: 0x815AC
    Bgm bgm; // Offset: 0xC8, DWARF: 0x81FC9
    unsigned int movie; // Offset: 0x110, DWARF: 0x81FEB
} Option;

// Size: 0x74, DWARF: 0x79A37
typedef struct CharacterState
{
    signed int secret; // Offset: 0x0, DWARF: 0x79A53
    unsigned int board; // Offset: 0x4, DWARF: 0x79A76
    unsigned int course; // Offset: 0x8, DWARF: 0x79A98
    signed int rem_point; // Offset: 0xC, DWARF: 0x79ABB
    signed int old_brd_no; // Offset: 0x10, DWARF: 0x79AE1
    signed int old_wear_no; // Offset: 0x14, DWARF: 0x79B08
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x79B30
    signed int soft[8]; // Offset: 0x38, DWARF: 0x79B59
    // Size: 0x1C, DWARF: 0x7C601
    Character_Param parameter; // Offset: 0x58, DWARF: 0x79B7C
} CharacterState;

// Size: 0xEC, DWARF: 0x7B740
typedef struct Create_Character
{
    // Size: 0x74, DWARF: 0x79A37
    CharacterState character; // Offset: 0x0, DWARF: 0x7B75C
    // Size: 0x1C, DWARF: 0x7C601
    Character_Param init_param; // Offset: 0x74, DWARF: 0x7B784
    // Size: 0x18, DWARF: 0x7D14B
    Clock clock; // Offset: 0x90, DWARF: 0x7B7AD
    char name[16]; // Offset: 0xA8, DWARF: 0x7B7D1
    signed int age; // Offset: 0xB8, DWARF: 0x7B7F4
    signed int sex; // Offset: 0xBC, DWARF: 0x7B814
    signed int face; // Offset: 0xC0, DWARF: 0x7B834
    signed int hair; // Offset: 0xC4, DWARF: 0x7B855
    signed int hair_color; // Offset: 0xC8, DWARF: 0x7B876
    signed int body; // Offset: 0xCC, DWARF: 0x7B89D
    signed int body_color; // Offset: 0xD0, DWARF: 0x7B8BE
    signed int pants; // Offset: 0xD4, DWARF: 0x7B8E5
    signed int pants_color; // Offset: 0xD8, DWARF: 0x7B907
    signed int glove; // Offset: 0xDC, DWARF: 0x7B92F
    signed int boots; // Offset: 0xE0, DWARF: 0x7B951
    signed int board_type; // Offset: 0xE4, DWARF: 0x7B973
    signed int trick_type; // Offset: 0xE8, DWARF: 0x7B99A
} Create_Character;

// Size: 0x8, DWARF: 0x7CE8F
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0, DWARF: 0x7CEAB
} CourseGap;

// Size: 0xEF8, DWARF: 0x7D03B
typedef struct Secret
{
    // Size: 0x74, DWARF: 0x79A37
    CharacterState character[12]; // Offset: 0x0, DWARF: 0x7D057
    // Size: 0xEC, DWARF: 0x7B740
    Create_Character create_character[10]; // Offset: 0x570, DWARF: 0x7D07F
    // Size: 0x8, DWARF: 0x7CE8F
    CourseGap course[8]; // Offset: 0xEA8, DWARF: 0x7D0AE
    signed int tour_round; // Offset: 0xEE8, DWARF: 0x7D0D3
    signed int old_char; // Offset: 0xEEC, DWARF: 0x7D0FA
    signed int first_clear; // Offset: 0xEF0, DWARF: 0x7D11F
} Secret;

// Size: 0x1668, DWARF: 0x7EB86
typedef struct Memcard
{
    // Size: 0x38, DWARF: 0x7E106
    File file; // Offset: 0x0, DWARF: 0x7EBA2
    // Size: 0x20, DWARF: 0x7DD98
    Record record[8][6]; // Offset: 0x38, DWARF: 0x7EBC5
    // Size: 0x4, DWARF: 0x7EA50
    Best_Time best_time[8]; // Offset: 0x638, DWARF: 0x7EBEA
    // Size: 0x114, DWARF: 0x81EAA
    Option option; // Offset: 0x658, DWARF: 0x7EC12
    // Size: 0xEF8, DWARF: 0x7D03B
    Secret secret; // Offset: 0x770, DWARF: 0x7EC37
} Memcard;

// Size: 0x2DCEC, DWARF: 0x800A8
typedef struct Replay
{
    // Size: 0x38, DWARF: 0x7E106
    File file; // Offset: 0x0, DWARF: 0x800C4
    signed int pid; // Offset: 0x38, DWARF: 0x800E7
    signed int num_frame; // Offset: 0x3C, DWARF: 0x80107
    unsigned int game_time; // Offset: 0x40, DWARF: 0x8012D
    signed int endrun_frame; // Offset: 0x44, DWARF: 0x80153
    // Size: 0x8, DWARF: 0x79997
    Pad pad_data[23400]; // Offset: 0x48, DWARF: 0x8017C
    // Size: 0x24, DWARF: 0x7D86F
    Key_Config key; // Offset: 0x2DB88, DWARF: 0x801A3
    // Size: 0xEC, DWARF: 0x7B740
    Create_Character character; // Offset: 0x2DBAC, DWARF: 0x801C5
    // Size: 0x30, DWARF: 0x7DAC1
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0x801ED
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0x80212
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0x80235
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0x80258
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0x8027C
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0x8029F
    // Size: 0x10, DWARF: 0x7A1DB
    Board_Param brd_param; // Offset: 0x2DCDC, DWARF: 0x802C5
} Replay;

// Size: 0x5D0E0, DWARF: 0x81356
typedef struct VspenvEnv
{
    // Size: 0xA0, DWARF: 0x78E67
    VspenvGame game; // Offset: 0x0, DWARF: 0x81372
    // Size: 0x1668, DWARF: 0x7EB86
    Memcard mc; // Offset: 0xA0, DWARF: 0x81395
    // Size: 0x2DCEC, DWARF: 0x800A8
    Replay replay[2]; // Offset: 0x1708, DWARF: 0x813B6
} VspenvEnv;

// Size: 0x10, DWARF: 0x7E9A9
typedef struct Spin
{
    signed int rewind; // Offset: 0x0, DWARF: 0x7E9C5
    signed int cab; // Offset: 0x4, DWARF: 0x7E9E8
    signed int value; // Offset: 0x8, DWARF: 0x7EA08
    signed int first; // Offset: 0xC, DWARF: 0x7EA2A
} Spin;

// Size: 0x10, DWARF: 0x7EEE9
typedef struct QueCol
{
    signed int state; // Offset: 0x0, DWARF: 0x7EF05
    signed int cnt; // Offset: 0x4, DWARF: 0x7EF27
    signed int land; // Offset: 0x8, DWARF: 0x7EF47
    signed int flight; // Offset: 0xC, DWARF: 0x7EF68
} QueCol;

// Size: 0x40, DWARF: 0x7F697
typedef struct Que
{
    signed int type; // Offset: 0x0, DWARF: 0x7F6B3
    signed int sp_type; // Offset: 0x4, DWARF: 0x7F6D4
    signed int num; // Offset: 0x8, DWARF: 0x7F6F8
    signed int link; // Offset: 0xC, DWARF: 0x7F718
    signed int jump; // Offset: 0x10, DWARF: 0x7F739
    signed int fakie; // Offset: 0x14, DWARF: 0x7F75A
    signed int late; // Offset: 0x18, DWARF: 0x7F77C
    signed int disaster; // Offset: 0x1C, DWARF: 0x7F79D
    // Size: 0x10, DWARF: 0x7E9A9
    Spin spin; // Offset: 0x20, DWARF: 0x7F7C2
    // Size: 0x10, DWARF: 0x7EEE9
    QueCol col; // Offset: 0x30, DWARF: 0x7F7E5
} Que;

// Size: 0x810, DWARF: 0x80A47
typedef struct Comb_Info
{
    // Size: 0x40, DWARF: 0x7F697
    Que que[32]; // Offset: 0x0, DWARF: 0x80A63
    signed int land; // Offset: 0x800, DWARF: 0x80A85
    signed int flight; // Offset: 0x804, DWARF: 0x80AA6
    signed int fakie; // Offset: 0x808, DWARF: 0x80AC9
    char entry_id; // Offset: 0x80C, DWARF: 0x80AEB
    char spin_id; // Offset: 0x80D, DWARF: 0x80B10
    char omit_id; // Offset: 0x80E, DWARF: 0x80B34
    char link_id; // Offset: 0x80F, DWARF: 0x80B58
} Comb_Info;

// Size: 0x824, DWARF: 0x7AF3D
typedef struct VspDispResult
{
    signed int rank; // Offset: 0x0, DWARF: 0x7AF59
    signed int trick_landing; // Offset: 0x4, DWARF: 0x7AF7A
    signed int comb_num; // Offset: 0x8, DWARF: 0x7AFA4
    signed int comb_points; // Offset: 0xC, DWARF: 0x7AFC9
    unsigned int comp_time; // Offset: 0x10, DWARF: 0x7AFF1
    // Size: 0x810, DWARF: 0x80A47
    Comb_Info comb_info; // Offset: 0x14, DWARF: 0x7B017
} VspDispResult;

// Size: 0x5C, DWARF: 0x7E16D
typedef struct VspModeData
{
    // DWARF: 0x7BC29
    FlowMode flow_mode; // Offset: 0x0, DWARF: 0x7E189
    unsigned int game_time_limit; // Offset: 0x4, DWARF: 0x7E1B1
    unsigned int game_time; // Offset: 0x8, DWARF: 0x7E1DD
    unsigned int game_count; // Offset: 0xC, DWARF: 0x7E203
    unsigned int realtime_count; // Offset: 0x10, DWARF: 0x7E22A
    unsigned int flow_count; // Offset: 0x14, DWARF: 0x7E255
    signed int can_pause; // Offset: 0x18, DWARF: 0x7E27C
    signed int modnum; // Offset: 0x1C, DWARF: 0x7E2A2
    signed int bgm_no; // Offset: 0x20, DWARF: 0x7E2C5
    signed int replay_speed; // Offset: 0x24, DWARF: 0x7E2E8
    signed int num_window; // Offset: 0x28, DWARF: 0x7E311
    signed int horse_pid; // Offset: 0x2C, DWARF: 0x7E338
    signed int end_sliding; // Offset: 0x30, DWARF: 0x7E35E
    signed int pause; // Offset: 0x34, DWARF: 0x7E386
    signed int pre_pause; // Offset: 0x38, DWARF: 0x7E3A8
    // DWARF: 0x7BC29
    FlowMode next_flow_mode; // Offset: 0x3C, DWARF: 0x7E3CE
    // DWARF: 0x7D3EA
    Restart restart; // Offset: 0x40, DWARF: 0x7E3FB
    signed int next_modnum; // Offset: 0x44, DWARF: 0x7E421
    signed int next_bgm_no; // Offset: 0x48, DWARF: 0x7E449
    signed int fade; // Offset: 0x4C, DWARF: 0x7E471
    signed int to_end_sliding; // Offset: 0x50, DWARF: 0x7E492
    signed int next_replay_speed; // Offset: 0x54, DWARF: 0x7E4BD
    signed int next_pause; // Offset: 0x58, DWARF: 0x7E4EB
} VspModeData;

// Size: 0x2DBFC, DWARF: 0x80867
typedef struct VspReplay
{
    // Size: 0x4, DWARF: 0x7BBEA
    CourseNo spenv_course; // Offset: 0x0, DWARF: 0x80883
    // Size: 0x3C, DWARF: 0x7ACCF
    Character spenv_character; // Offset: 0x4, DWARF: 0x808AE
    // Size: 0x18, DWARF: 0x7BDBB
    Mode spenv_gamemode; // Offset: 0x40, DWARF: 0x808DC
    // Size: 0x24, DWARF: 0x7D86F
    Key_Config spenv_keyconfig; // Offset: 0x58, DWARF: 0x80909
    // Size: 0x30, DWARF: 0x7DAC1
    Cheats spenv_cheats; // Offset: 0x7C, DWARF: 0x80937
    signed short pid; // Offset: 0xAC, DWARF: 0x80962
    unsigned short rand_num; // Offset: 0xAE, DWARF: 0x80982
    signed int num_frame; // Offset: 0xB0, DWARF: 0x809A7
    signed int endrun_frame; // Offset: 0xB4, DWARF: 0x809CD
    unsigned int game_time; // Offset: 0xB8, DWARF: 0x809F6
    // Size: 0x8, DWARF: 0x79997
    Pad pad_data[23400]; // Offset: 0xBC, DWARF: 0x80A1C
} VspReplay;

// Size: 0x20, DWARF: 0x7ECF9
typedef struct VspDispEnv
{
    signed int mode; // Offset: 0x0, DWARF: 0x7ED15
    signed int time_left; // Offset: 0x4, DWARF: 0x7ED36
    signed int pass_time; // Offset: 0x8, DWARF: 0x7ED5C
    signed int div; // Offset: 0xC, DWARF: 0x7ED82
    signed int div_exp; // Offset: 0x10, DWARF: 0x7EDA2
    signed int res[3]; // Offset: 0x14, DWARF: 0x7EDC6
} VspDispEnv;

// Size: 0x10, DWARF: 0x7C1BE
typedef struct Points
{
    signed int single; // Offset: 0x0, DWARF: 0x7C1DA
    signed int total; // Offset: 0x4, DWARF: 0x7C1FD
    signed int freeride; // Offset: 0x8, DWARF: 0x7C21F
    signed int link_rate; // Offset: 0xC, DWARF: 0x7C244
} Points;

// Size: 0x4, DWARF: 0x7CDA1
typedef struct Bar
{
    char num; // Offset: 0x0, DWARF: 0x7CDBD
    char charge; // Offset: 0x1, DWARF: 0x7CDDD
    char left; // Offset: 0x2, DWARF: 0x7CE00
    char res; // Offset: 0x3, DWARF: 0x7CE21
} Bar;

// Size: 0x10, DWARF: 0x7D366
typedef struct EnvBalance
{
    signed int state; // Offset: 0x0, DWARF: 0x7D382
    float per; // Offset: 0x4, DWARF: 0x7D3A4
    signed int res[2]; // Offset: 0x8, DWARF: 0x7D3C4
} EnvBalance;

// Size: 0x4, DWARF: 0x7DCED
typedef struct Boost
{
    char num; // Offset: 0x0, DWARF: 0x7DD09
    char charge; // Offset: 0x1, DWARF: 0x7DD29
    char res[2]; // Offset: 0x2, DWARF: 0x7DD4C
} Boost;

// Size: 0x10, DWARF: 0x7E53C
typedef struct Match
{
    // Size: 0x4, DWARF: 0x7DCED
    Boost boost; // Offset: 0x0, DWARF: 0x7E558
    signed int push; // Offset: 0x4, DWARF: 0x7E57C
    signed int res[2]; // Offset: 0x8, DWARF: 0x7E59D
} Match;

// Size: 0x38, DWARF: 0x7B648
typedef struct VspDispEnvChar
{
    // Size: 0x10, DWARF: 0x7C1BE
    Points points; // Offset: 0x0, DWARF: 0x7B664
    // Size: 0x4, DWARF: 0x7CDA1
    Bar bar; // Offset: 0x10, DWARF: 0x7B689
    // Size: 0x10, DWARF: 0x7D366
    EnvBalance balance; // Offset: 0x14, DWARF: 0x7B6AB
    // Size: 0x10, DWARF: 0x7E53C
    Match match; // Offset: 0x24, DWARF: 0x7B6D1
    signed int rank; // Offset: 0x34, DWARF: 0x7B6F5
} VspDispEnvChar;

// Size: 0x838, DWARF: 0x81CC0
typedef struct VsResult
{
    signed int goal; // Offset: 0x0, DWARF: 0x81CDC
    unsigned int time; // Offset: 0x4, DWARF: 0x81CFD
    unsigned int count; // Offset: 0x8, DWARF: 0x81D1E
    unsigned int point; // Offset: 0xC, DWARF: 0x81D40
    signed int cnt_horse; // Offset: 0x10, DWARF: 0x81D62
    // Size: 0x824, DWARF: 0x7AF3D
    VspDispResult horse_best_combo; // Offset: 0x14, DWARF: 0x81D88
} VsResult;

// Size: 0x108C, DWARF: 0x822D5
typedef struct VspVsData
{
    signed int div_side; // Offset: 0x0, DWARF: 0x822F1
    signed int center; // Offset: 0x4, DWARF: 0x82316
    signed int center_pos_id; // Offset: 0x8, DWARF: 0x82339
    signed int center_to_pos_id; // Offset: 0xC, DWARF: 0x82363
    signed int cnt_center_move; // Offset: 0x10, DWARF: 0x82390
    signed int horse_num_round; // Offset: 0x14, DWARF: 0x823BC
    signed int horse_end_one_round; // Offset: 0x18, DWARF: 0x823E8
    // Size: 0x838, DWARF: 0x81CC0
    VsResult result[2]; // Offset: 0x1C, DWARF: 0x82418
} VspVsData;

// Size: 0x20, DWARF: 0x7E60D
typedef struct KeyState // : E:\tam\ps2\sppbx\main.c
{
    signed int id; // Offset: 0x0, DWARF: 0x7E629
    unsigned int now; // Offset: 0x4, DWARF: 0x7E648
    unsigned int status; // Offset: 0x8, DWARF: 0x7E668
    unsigned int press; // Offset: 0xC, DWARF: 0x7E68B
    signed char right_h; // Offset: 0x10, DWARF: 0x7E6AD
    signed char right_v; // Offset: 0x11, DWARF: 0x7E6D1
    signed char left_h; // Offset: 0x12, DWARF: 0x7E6F5
    signed char left_v; // Offset: 0x13, DWARF: 0x7E718
    unsigned char l_right; // Offset: 0x14, DWARF: 0x7E73B
    unsigned char l_left; // Offset: 0x15, DWARF: 0x7E75F
    unsigned char l_up; // Offset: 0x16, DWARF: 0x7E782
    unsigned char l_down; // Offset: 0x17, DWARF: 0x7E7A3
    unsigned char r_up; // Offset: 0x18, DWARF: 0x7E7C6
    unsigned char r_right; // Offset: 0x19, DWARF: 0x7E7E7
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x7E80B
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x7E82E
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x7E851
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x7E871
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x7E891
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x7E8B1
} KeyState;

// Size: 0x60, DWARF: 0x7A31D
typedef struct Ope
{
    // Size: 0x20, DWARF: 0x7E60D
    KeyState now; // Offset: 0x0, DWARF: 0x7A339
    // Size: 0x20, DWARF: 0x7E60D
    KeyState old; // Offset: 0x20, DWARF: 0x7A35B
    unsigned int port; // Offset: 0x40, DWARF: 0x7A37D
    unsigned int slot; // Offset: 0x44, DWARF: 0x7A39E
    unsigned int mode; // Offset: 0x48, DWARF: 0x7A3BF
    unsigned int trg; // Offset: 0x4C, DWARF: 0x7A3E0
    unsigned int rev; // Offset: 0x50, DWARF: 0x7A400
    unsigned int cnt; // Offset: 0x54, DWARF: 0x7A420
    unsigned int rep; // Offset: 0x58, DWARF: 0x7A440
    signed int state; // Offset: 0x5C, DWARF: 0x7A460
} Ope;

static signed int vktactParamG_jump_up; // Address: 0x2E771C
static signed int vktactParamG_jump_down; // Address: 0x2E7720
static signed int vktactParamG_air; // Address: 0x2E7724
static signed int vktactParamG_hpair; // Address: 0x2E7728
static signed int vktactParamHangRate; // Address: 0x2E772C
static signed int vktactParamSpt_time; // Address: 0x2E7730
static signed int vktactParamSpt_charge_time; // Address: 0x2E7734
static signed int vktactParamSpt_one_stock_tp; // Address: 0x2E7738
static signed int vktactParamBal_lean_gravity_min; // Address: 0x2E773C
static signed int vktactParamBal_lean_gravity_max; // Address: 0x2E7740
static signed int vktactParamBal_lean_limit; // Address: 0x2E7744
static signed int vktactParamBal_lean_start_dir; // Address: 0x2E7748
static signed int vktactParamBal_lean_acc_inp; // Address: 0x2E774C
static signed int vktactParamBal_lean_acc_fr_base; // Address: 0x2E7750
static signed int vktactParamBal_lean_acc_fr_rate; // Address: 0x2E7754
static signed int vktactParamBal_start_input; // Address: 0x2E7758
static signed int vktactParamPts_hold_pts_rate_grab; // Address: 0x2E775C
static signed int vktactParamPts_hold_pts_rate_plant; // Address: 0x2E7760
static signed int vktactParamPts_hold_pts_rate_grind; // Address: 0x2E7764
static signed int vktactParamPts_switch_bonus; // Address: 0x2E7768
static signed int vktactParamPts_perfect_bonus; // Address: 0x2E776C
static signed int vktactParamPts_sloppy_bonus; // Address: 0x2E7770
static signed int vktactParamPts_sicktime_bonus; // Address: 0x2E7774
static signed int vktactParamPts_sicktime_start; // Address: 0x2E7778
static signed int vktactParamHpOver_accel; // Address: 0x2E777C
static signed int vktactParamHpOver_jump_rate; // Address: 0x2E7780
static // Size: 0x28, DWARF: 0x7DEB2
Param vktactMinParam; // Address: 0x2B50B0
static // Size: 0x28, DWARF: 0x7DEB2
Param vktactCmnParam; // Address: 0x2B50E0
static // Size: 0x28, DWARF: 0x7DEB2
Param vktactMaxParam; // Address: 0x2B5110
static signed int vktactPlantTumbleFrame[12]; // Address: 0x2B5140
static float vktactMatMaxSpRate[12]; // Address: 0x2B5170
static float vktactMatAccelRate[12]; // Address: 0x2B51A0
static float vktactMatEdgeAdj[12]; // Address: 0x2B51D0
static signed int vktactMatSideSlip[12]; // Address: 0x2B5200
static float vktactMatCrashSpDown[12]; // Address: 0x2B5230
static float vktactTTCrashSpDown_normal[5]; // Address: 0x2B5260
static float vktactTTCrashSpDown_touch[5]; // Address: 0x2B5280
static float vktactMatTumbleSpeed_normal[3]; // Address: 0x2B5298
static float vktactMatTumbleAng_normal[3]; // Address: 0x2B52A8
static float vktactMatTumbleAng_touch[2]; // Address: 0x2E7788
static float vktactMatTumbleSpeed_touch[3]; // Address: 0x2B52B8
static float vktactMatRate_touch[12]; // Address: 0x2B52D0
static signed short vktactTrkToMot[108]; // Address: 0x2B5300
static signed short vktactCmdToGrab[25]; // Address: 0x2B53E0
static signed short vktactCmdToFlip[25]; // Address: 0x2B5420
static signed short vktactCmdToGrind[13]; // Address: 0x2B5460
static signed short vktactCmdToBonk[9]; // Address: 0x2B5480
static signed short vktactCmdToPlant[9]; // Address: 0x2B54A0
static signed short vktactCmdToManual[9]; // Address: 0x2B54C0
static signed short vktactCmdToRevert[2]; // Address: 0x2E7790
static signed short vktactCmdToJump[4]; // Address: 0x2E7798
static signed short vktactSpTrk[12][2]; // Address: 0x2B54E0
// Size: 0x5D0E0, DWARF: 0x81356
VspenvEnv vspenvEnv; // Address: 0x3474D0
// Size: 0xA0, DWARF: 0x78E67
VspenvGame* vspenvGame; // Address: 0x2E7B14
float vktactParamMaxCmnSpeed; // Address: 0x2E7A6C
float vktactParamMinCmnSpeed; // Address: 0x2E7A70
float vktactParamCmnCmnSpeed; // Address: 0x2E7A74
float vktactParamMaxMaxSpeed; // Address: 0x2E7A78
float vktactParamMinMaxSpeed; // Address: 0x2E7A7C
float vktactParamCmnMaxSpeed; // Address: 0x2E7A80
float vktactParamMaxLanding; // Address: 0x2E7A48
float vktactParamMinLanding; // Address: 0x2E7A4C
float vktactParamCmnLanding; // Address: 0x2E7A50
float vktactParamMaxGrind; // Address: 0x2E7A54
float vktactParamMinGrind; // Address: 0x2E7A58
float vktactParamCmnGrind; // Address: 0x2E7A5C
float vktactParamMaxSpin; // Address: 0x2E7A60
float vktactParamMinSpin; // Address: 0x2E7A64
float vktactParamCmnSpin; // Address: 0x2E7A68
float vktactParamMaxQuickTurn; // Address: 0x2E7A84
float vktactParamMinQuickTurn; // Address: 0x2E7A88
float vktactParamCmnQuickTurn; // Address: 0x2E7A8C
float vktactParamMaxSitTurn; // Address: 0x2E7A90
float vktactParamMinSitTurn; // Address: 0x2E7A94
float vktactParamCmnSitTurn; // Address: 0x2E7A98
float vktactParamMaxTurn; // Address: 0x2E7A9C
float vktactParamMinTurn; // Address: 0x2E7AA0
float vktactParamCmnTurn; // Address: 0x2E7AA4
float vktactParamMaxJumpPower; // Address: 0x2E7AA8
float vktactParamMinJumpPower; // Address: 0x2E7AAC
float vktactParamCmnJumpPower; // Address: 0x2E7AB0
signed int vktactParamMaxRetRate; // Address: 0x2E7AB4
signed int vktactParamMinRetRate; // Address: 0x2E7AB8
signed int vktactParamCmnRetRate; // Address: 0x2E7ABC
// Size: 0x824, DWARF: 0x7AF3D
VspDispResult vspDispResult[2]; // Address: 0x3BD4B0
// Size: 0x5C, DWARF: 0x7E16D
VspModeData vspModeData; // Address: 0x3BF620
// Size: 0x2DBFC, DWARF: 0x80867
VspReplay* vspReplay[2]; // Address: 0x2E7B48
// Size: 0x60, DWARF: 0x7A31D
Ope* vgmsysPad[2]; // Address: 0x2E7B30
// Size: 0x20, DWARF: 0x7ECF9
VspDispEnv vspDispEnv; // Address: 0x3BE570
// Size: 0x38, DWARF: 0x7B648
VspDispEnvChar vspDispEnvChar[2]; // Address: 0x3BE500
signed int vktactNumObj; // Address: 0x2E7AE4
signed int vktactNumVec; // Address: 0x2E7AE8
signed int vktactNumHit; // Address: 0x2E7AEC
signed int vktactNumObj_head; // Address: 0x2E7AC0
// Size: 0x60, DWARF: 0x75E44
Col vktactColObj_head[16]; // Address: 0x345710
signed int vktactNumHit_head; // Address: 0x2E7AC4
// Size: 0x60, DWARF: 0x75E44
Col vktactColHit_head[16]; // Address: 0x345D10
// Size: 0x5640, DWARF: 0x78FAB
Rider* vspRider[8]; // Address: 0x3BD480
signed int vktactSlideWater; // Address: 0x2E7AD0
signed int vktactNumObj_body; // Address: 0x2E7AC8
signed int vktactNumHit_body; // Address: 0x2E7ACC
// Size: 0x60, DWARF: 0x75E44
Col* vktactColObj; // Address: 0x2E7AD4
// Size: 0x60, DWARF: 0x75E44
Col* vktactColVec; // Address: 0x2E7AD8
// Size: 0x60, DWARF: 0x75E44
Col* vktactColHit; // Address: 0x2E7ADC
signed int vktactIsSliding; // Address: 0x2E7AE0
// Size: 0x60, DWARF: 0x75E44
Col vktactColObj_body[16]; // Address: 0x346310
// Size: 0x60, DWARF: 0x75E44
Col vktactColHit_body[16]; // Address: 0x346910
// Size: 0x60, DWARF: 0x75E44
Col vktactColSliding; // Address: 0x346F10
signed int vsptblTrickPoint[160]; // Address: 0x2B6EE0
signed int vsptblGapPoint[8][64]; // Address: 0x2B6260
// Size: 0x108C, DWARF: 0x822D5
VspVsData vspVsData; // Address: 0x3BE590
signed int vspEndRunReplay; // Address: 0x2E7B80
signed int vspEndRun; // Address: 0x2E7B84

float iktactGetLen(float* v);
float iktactGetLenXZ(float* v);
signed int iktactMakeParam_return(signed int src);
float iktactMakeParam_jumppower(signed int src);
float iktactMakeParam_turn(signed int src);
float iktactMakeParam_sitting_turn(signed int src);
float iktactMakeParam_quick_turn(signed int src);
float iktactMakeParam_max_speed(signed int src);
float iktactMakeParam_cmn_max_speed(signed int src);
float iktactMakeParam_spin(signed int src);
float iktactMakeParam_landing(signed int src);
void ktactInitCtrl(Act* act, // Size: 0x3C, DWARF: 0x7ACCF
                   Character* param, // Size: 0x24, DWARF: 0x7D86F
                   Key_Config* key, // Size: 0x30, DWARF: 0x7DAC1
                   Cheats* cheats);
static void ktactGetChrParamX10(Character_Param* cp10, // Size: 0x1C, DWARF: 0x7C601
                                Character_Param* cp);
static void ktactGetBrdParamX10(Board_Param* bp10, // Size: 0x10, DWARF: 0x7A1DB
                                Board_Param* bp);
static void ktactInitParam2(Param2* param, // Size: 0x1C, DWARF: 0x7C601
                            Character_Param* cp10, // Size: 0x10, DWARF: 0x7A1DB
                            Board_Param* bp10);
static void ktactSetParam();
void ktactInitPos(Pos* pos);
void ktactInitRequest(Req* req);
void ktactInitInput(Inp* inp);
static void ktactInitBalance(Balance* bal);
static void ktactResetBalance(Balance* bal, signed int reset_lean, signed int free_frame);
static void ktactInitTLinkAll(TrickLink* tl);
static void ktactInitTLink(TrickLink* tl);
static void ktactResetTrickPointOneSet(TrickLink* tl);
static void ktactCommandInit(Cmd* cmd, signed short cmdtype, signed int way1, signed int way2, signed int way3, signed int way4, unsigned short fin_button, signed int rev);
static void ktactCommandReset(Cmd* cmd);
// static void ktactCommandResetAll(static void ktactCommandResetAllForGrind(// Act* act, signed int grind_no);
static void ktactCommandResetAllForRevert(Act* act);
static void ktactCommandResetAllForJump(Act* act);
static void ktactCommandResetAllForTrick(Act* act);
// static void ktactCommandSet(Key_Config* key); // Note: There may be a third unused Key_Config* parameter.
static void ktactResetNumPlayTrickInLink(Act* act);
static void ktactRecoverNumPlayTrick(Act* act);
void ktactSetCaminfo(Cam* cam, // Size: 0x2C00, DWARF: 0x7627B
                     Ctrl* rc);
void ktactSetSeinfo(Se* se, // Size: 0x2C00, DWARF: 0x7627B
                    Ctrl* rc);
void ktactGetRotVector(float* rot, float* pole, float rot_pole, // DWARF: 0x7C53F
                       Sliding_State ss);
static void ktactPlaySE(Rider* rider);
void ktactCtrl(Rider* rider, signed int end_brake);
static signed int ktactSetPadCnt(Pad* pad, // Size: 0x60, DWARF: 0x7A31D
                                 Ope* ope, signed int mirror);
static signed int ktactCheckCommand(Req* req, // Size: 0x2C00, DWARF: 0x7627B
                                    Ctrl* rc);
static signed int ktactCheckCmd(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int late, signed int mirror, signed int jump);
static void ktactCheckCmd_1(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int num_maxstep);
static void ktactCheckCmd_2(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int num_maxstep);
static void ktactCheckCmd_3(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int num_maxstep);
static void ktactSetRequest(Ctrl* rc);
static void ktactSetSlidingState(Ctrl* rc);
static void ktactSetSS_grind(Ctrl* rc, signed int grind_no);
static void ktactSetInput0(Ctrl* rc);
static signed int ktactSetInput1(Ctrl* rc);
static void ktactUpdateBalance(Balance* bal, // Size: 0x2580, DWARF: 0x76810
                               Act* act, signed int a, signed int b, signed int cnt);
static void ktactReflectInput(Ctrl* rc);
static void ktactAdj(Ctrl* rc);
static void ktactAdjRot(Ctrl* rc);
static void ktactAdjSpeed(Ctrl* rc);
static void ktactAdjSpeed_grind(Ctrl* rc);
static void ktactAdjSpeed_halfpipe(Ctrl* rc);
static void ktactAdjSpeed_bonk(Ctrl* rc);
static void ktactAdjSpeedG(Ctrl* rc);
static float ktactGetAdjSpeedOnAir(float spy, signed int hp_air, signed int jump_air);
static void ktactAdjSpeedJump(Ctrl* rc);
static void ktactAdjSpeedAccel(Ctrl* rc);
static void ktactAdjSpeedBoard(Ctrl* rc);
static void ktactAdjSpeedLimit(Ctrl* rc);
static void ktactAdjSpeedEtc(Ctrl* rc);
static void ktactMove(Ctrl* rc);
static void ktactSetNextPos(Sbcore* cd, // Size: 0x2C00, DWARF: 0x7627B
                            Ctrl* rc);
static signed int ktactMoveAdjPos_halfpipe(float* next, // Size: 0x60, DWARF: 0x75E44
                                           Col* col, // Size: 0x2C00, DWARF: 0x7627B
                                           Ctrl* rc, float* from, float* to, signed int unused1);
static void ktactMoveCrash(Ctrl* rc, // Size: 0x1F0, DWARF: 0x7B067
                           Sbcore* cd);
static void ktactGetNoheightReflection(float* out, Ctrl* unused1, float* nor, float* in);
static signed int ktactCheckWall(Plane* plane, // Size: 0x1F0, DWARF: 0x7B067
                                 Sbcore* cd, // Size: 0x60, DWARF: 0x79DD3
                                 Pos* now);
static void ktactGetWallPlane(Plane* plane, float* now, // Size: 0x30, DWARF: 0x79C3C
                              Plane* next, float* move);
static signed int ktactCheckShadow(Act* act, signed int shadow);
static void ktactProcHitBody(Ctrl* rc, // Size: 0x30, DWARF: 0x79C3C
                             Plane* plane, // Size: 0x60, DWARF: 0x79DD3
                             Pos* pos);
static void ktactProcVerticalPlane(Sbcore* cd, // Size: 0x2C00, DWARF: 0x7627B
                                   Ctrl* rc, // Size: 0x30, DWARF: 0x79C3C
                                   Plane* plane);
static void ktactCheckManual(Ctrl* rc, // Size: 0x60, DWARF: 0x79DD3
                             Pos* next);
static void ktactMergeHitList(Ctrl* rc, // Size: 0x1F0, DWARF: 0x7B067
                              Sbcore* cd, signed int body, float* prepos, float* nowpos);
static signed int ktactMergeHitList_0(Col* list, signed int num_list, float* prepos, float* nowpos, signed int move);
static signed int ktactMergeHitList_1(Col* list, signed int num_list, // Size: 0x60, DWARF: 0x75E44
                                      Col* add, signed int num_add, signed int event);
static void ktactForcedBailout(Ctrl* rc);
static void ktactUpdateState(Ctrl* rc);
static void ktactUpdateStateByMot(Ctrl* rc);
static void ktactUpdateTrickLink(TrickLink* tl, // Size: 0x2C00, DWARF: 0x7627B
                                 Ctrl* rc);
static void ktactUpdateGap(Act* act);
static void ktactUpdateSpecialTrick(Ctrl* rc);
static void ktactUpdateBoost(Ctrl* rc);
static void ktactUpdateParam(Ctrl* rc);
static void ktactUpdateFlipPole(Ctrl* rc);
static float ktactGetCmnMaxSpeed(Ctrl* rc);
static void ktactSetCrashPow_normal(Ctrl* rc, // Size: 0x30, DWARF: 0x79C3C
                                    Plane* plane);
static void ktactSetCrashPow_touch(Ctrl* rc, // Size: 0x30, DWARF: 0x79C3C
                                   Plane* plane, signed int hp);
static void ktactSetSlant_speed(Ctrl* rc);
void ktactSetSlant_char_rot(Ctrl* rc);
void ktactSetNormalPole(Ctrl* rc);
signed int ktactGetHeight(Pos* base, float* pos);
void ktactGetInnerRotMatrix(sceVu0FMATRIX mat, float* rot);
void ktactGetDispRotMatrix(sceVu0FMATRIX mat, // Size: 0x2C00, DWARF: 0x7627B
                           Ctrl* rc, float scale);
void maGetModelScale(float* ret, signed int id);
void ktactGetWaistPos(Ctrl* rc);
static void ktactSetHorizonParam(Ctrl* rc, signed int hp);
static void ktactSetVerticalityParam(Ctrl* rc);
static void ktactUpdateBalanceAdj(Ctrl* rc);
static void ktactEdgeSpeed(float* out, float* lsp, s32 unused, s32 unused2, signed int mat, signed int d2c);
static void ktactSpeedAdj(float* speed, signed int d2c, signed int mat);
static signed int ktactSideSlantToD2C(float side_slant);
static signed int ktactGetHit_base(Pos* cross, float* from, float* to, // Size: 0x60, DWARF: 0x75E44
                                   Col* cross_buff, // Size: 0x60, DWARF: 0x75E44
                                   Col* hit_buff, signed int hit_nbuff, signed int* num_hit, // Size: 0x60, DWARF: 0x75E44
                                   Col* obj_buff, signed int obj_nbuff, signed int* num_obj, signed int water, signed int kill_far);
static signed int ktactGetHit_hit(Col* cross, float* from, float* to, // Size: 0x60, DWARF: 0x75E44
                                  Col* hit_buff, signed int hit_nbuff, signed int* num_hit, signed int water, signed int kill_far);
static unsigned int ktactGetHit_base2(Col* cross, float* from, float* to, signed int water, signed int* ret, signed int num);
static void ktactTmcrsCol2KtactPos(Pos* pos, // Size: 0x60, DWARF: 0x75E44
                                   Col* col);
static void ktactSbcorePlane2TmcrsCol(Col* col, // Size: 0x30, DWARF: 0x79C3C
                                      Plane* pl);
static void ktactRail2SbcorePlane(Plane* pl, // Size: 0x60, DWARF: 0x75E44
                                  Col* vec, float* mv);
static signed int ktactGetHit_vector(float* from, float* to, // Size: 0x60, DWARF: 0x75E44
                                     Col* vec_buff, signed int vec_nbuff);
static void ktactGetHit_rail_hp(float* rfrom, float* rto, float* hpfrom, float* hpto, // Size: 0x60, DWARF: 0x75E44
                                Col* rail, // Size: 0x60, DWARF: 0x75E44
                                Col* plant, // Size: 0x60, DWARF: 0x75E44
                                Col* hp);
static void ktactGetHit_hp(float* hpfrom, float* hpto, // Size: 0x60, DWARF: 0x75E44
                           Col* hp);
static signed int ktactGetHit_out(Col* out, float* from, float* to);
static signed int ktactGetHit_bonk(float* pos, float* speed, float* bonk_point);
static void ktactGetBlockArea(_anon8* area, float* from, float* to);
static void ktactSetHeadHipMatrix(Rider* rider);
static void ktactSetHeadHipOffset(float* head, float* hip, // Size: 0x5640, DWARF: 0x78FAB
                                  Rider* rider);
signed int sbcoreGetHit(Plane* pl, float* from, float* to, signed int move, float height, signed int kill_far);
void sbcoreGetHit2(_anon18* ps);
static signed int ktactUpdateTrickPoint(Act* act, Ctrl* unused1);
static unsigned int ktactGetTrickPointOneSet(Act* act);
static unsigned int ktactGetTrickLinkRate(Act* act);
static void ktactAddSpecialTrickCharge(Act* act);
static void ktactAddBoostCharge(Act* act);
void ktactSetGap(signed int pid, signed short gap_no);
void ktactSetRecover(signed int pid, float* pos, float roty, float speed, signed int warp);
void ktactSetGrindToHp(signed int pid, signed int hp);
void ktactSetAccelOnGrind(signed int pid, signed int acc);
static void ktactSetAccelWay(Ctrl* rc);
void ktactCtrlIntro(Rider* rider, signed int count);
void ktactCtrlReady(Rider* rider, signed int count);
void ktactCtrlFinish(Rider* rider, signed int count);
void ktactCtrlHorseReady(Rider* rider, signed int count);
static signed int ktactGetIntroMotion(Rider* rider);
static signed int ktactGetEndMotion(Rider* rider);
static signed int ktactGetCharHitPlane(Plane* pl, signed int pid, float* nextpos);
static signed int ktactCheckHitChar_1(Plane* pl, // Size: 0x5640, DWARF: 0x78FAB
                                      Rider* rider0, float* nextpos, // Size: 0x5640, DWARF: 0x78FAB
                                      Rider* rider1);
static signed int ktactCheckBoxLineCol(sceVu0FVECTOR (*box)[4], float* from, float* to);
static signed int ktactCheckTriLineCol(sceVu0FVECTOR* tri, float* from, float* to);
void ktactReserveTumble(signed int pid, float ang, // DWARF: 0x7E931
                        Tumble_Type tt);
void ktactReserveTumble2(signed int unused1, float* unused2, float unused3, signed int unused4);
static void ktactProcReserveTumble(Plane* pl, // Size: 0x2C00, DWARF: 0x7627B
                                   Ctrl* rc);
static signed int ktactGetChangedTrickNo(Ctrl* rc, signed int tno);
static float ktactGetLimitAng_down(float* nor);
static unsigned int David_ktactGetHit_hit2(Col* col, float* from, float* to, signed int water, signed int* ret, signed int num);
signed int David_GetHitCollision2(Col** collision, signed int* ret, signed int x, signed int y, float* src, float* dst, signed int num);
void David_PutRaysInVU0(float* from, float* to, signed int num);
signed int David_GetBaseCollision2(Col* collision, signed int* ret, signed int x, signed int y, signed int num);
signed int tmcrsGetRailCollision(Col* rail, Col* hp, signed int bx, signed int by, float* p0, float* p1, float* p2);
signed int tmcrsGetHitCollision(Col* collision, signed int x, signed int y, float* src, float* dst);
void sbcoreGetMirrorVector_angle(float* out, float* nor, float* vec, float ang);
static unsigned int David_ktactGetHit_obs2(Col* col, float* from, float* to, signed int* ret, signed int num);
signed int David_tmcrsGetObjectCollision2(Col** collision, signed int* ret, float* src, float* dst, signed int num);
signed int tmcrsGetObjectCollision(Col* collision, float* src, float* dst);
static signed int David_ktactGetHit_obs(Col* cross, float* from, float* to, // Size: 0x60, DWARF: 0x75E44
                                        Col* obj_buff, signed int unused1, signed int* num_obj, signed int kill_far);

// Included Functions /////////////////////////////////////////////
float acosf(float x);
float atan2f(float y, float x);
int rand(void);
void akevResetEffect2(signed int pn);
void gmsysSetBlurPow(signed int pow);
void nmactDualSwitch(signed int id);
signed int nmactPlay(signed int id, signed int type, signed int attr);
signed int nmactPlayBoost(signed int id);
signed int nmactPlayLand(signed int id, signed int attr, signed int unused1);
signed int nmactPlaySlip(signed int id, signed int type);
signed int nmactPlayVoice(signed int id, signed int num);
signed int nmactStop(signed int id, signed int type);
void sbcoreInit(Sbcore* cd);
void sbcoreSetNextPos(Sbcore* cd);
float sbcoreGetInnerAngle90(float* vec0, float* vec1);
void sbcoreGetShadowVector(float* out, float* nor, float* vec);
void sbcoreGetShadowRotVector(float* out, float* nor, float* vec);
void sbcoreGetShadowVector2(float* out, float* snor, float* wnor, float* vec);
void tmcrsGetArea(signed int* x, signed int* y, float* pos);
signed int tmcrsGetBonkCollision(Col* collision, signed int x, signed int y, float* position);
signed int tmcrsGetObjectBonkCollision(Col* collision, float* pos);
signed int tmcrsGetVectorCollision(Col* collision, signed int x, signed int y, float* src, float* dst);
void maModelChangeSet(ModelChange* ctrl, signed int mode);
static void ktactCommandSet(Act* act, Key_Config* key);
void tmetcGetAcc(float* acc, float* pos);
void sceVu0AddVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0MulVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0InversMatrix(sceVu0FMATRIX a, sceVu0FMATRIX b);
void sceVu0TransMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FVECTOR v);
float iktactGetLen(float* v);
float iktactGetLenXZ(float* v);
float sinf(float i);
float cosf(float i);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float scale);
void sceVu0SubVector(sceVu0FVECTOR vec1, sceVu0FVECTOR vec2, sceVu0FVECTOR vec3);
void sceVu0ScaleVector(sceVu0FVECTOR vec1, sceVu0FVECTOR vec2, float scale);
float sceVu0InnerProduct(sceVu0FVECTOR vec1, sceVu0FVECTOR vec2);
void ktmotSetNewAnim2(Rider* rider, signed int id, signed int uad, signed int nloop, signed int inter, signed int brend);
void ktmotEndFreeMotion(Rider* rider);
float sbcoreGetInnerAngle180(float* vec0, float* vec1);
void sbcoreGetRotMatrix(sceVu0FMATRIX mat, float* pole, float rot_pole);
void spSetWndFade(signed int wid, signed int per);
void spRiderSetPos2(Rider* rider, float* pos, float roty);
void nmdispInputTrick(signed int id);
void nmdispEndTrick(signed int id, signed int result);
void nmtrickSetLand(signed int id, signed int type);
void nmtrickSetFakie(signed int id, signed int flag);
void nmtrickSetTrick(signed int id, signed int type, signed int num, signed int unused1);
void nmtrickSetJump(signed int id, signed int num);
void nmtrickSetSpin(signed int id, signed int pipe, signed int rewind, signed int spin);
void nmtrickSetFlight(signed int id, signed int flag);
void nmtrickGetInfo(signed int id, Comb_Info* info);

float isbcoreSqrtf(float var);
void sbcoreGetShadowVector3(float* out, float* snor, float* wnor1, float* wnor2, float* vec);
void sbcoreInitPLANE(Plane* pl);
signed int sbcoreSetNextPosOnVertexList(Sbcore* cd, signed int current_id, sceVu0FVECTOR* vertex_list, signed int num_vertex);
signed int tmcrsCheckObjectCollision(float* src, float* dst, signed int unused1);
void sceVu0ApplyMatrix(sceVu0FVECTOR a, sceVu0FMATRIX b, sceVu0FVECTOR c);
void sceVu0InterVector(float a[4], float b[4], float c[4], float d);
void sceVu0MulMatrix(sceVu0FMATRIX a, sceVu0FMATRIX b, sceVu0FMATRIX c);
void sceVu0Normalize(sceVu0FVECTOR a, sceVu0FVECTOR b);
void sceVu0OuterProduct(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0RotMatrixX(float a[4][4], float b[4][4], float c);
void sceVu0RotMatrixY(float a[4][4], float b[4][4], float c);
void sceVu0RotMatrixZ(float a[4][4], float b[4][4], float c);
void sceVu0UnitMatrix(float a[4][4]);

signed int sbcoreSetNextPosOnVertexListHP(Sbcore* cd, signed int current_id, sceVu0FVECTOR* vertex_list, signed int num_vertex);
static signed int ktactGetHit_out(Col* out, float* from, float* to);
static signed int ktactMergeHitList_0(Col* list, signed int num_list, float* prepos, float* nowpos, signed int move);
static signed int ktactMergeHitList_1(Col* list, signed int num_list, Col* add, signed int num_add, signed int event);
signed int ulvumdlGetMatrix(sceVu0FMATRIX mat, unsigned char* vmd, unsigned int id);

void ktactInitCtrl(Act* act /* 0x60(r29) */, Character* param /* 0x70(r29) */, Key_Config* key /* 0x80(r29) */, Cheats* cheats /* 0x90(r29) */) {
    signed int i; // r16
    signed int cid; // r17
    signed int stance; // r18
    float max_speed; // 0x58(r29)
    float cmn_max_speed; // 0x5C(r29)

    sbcoreInit(act);
    act->cnt_freefoot = 0;
    act->cnt_turn = 0;
    act->cnt_sitting = 0;
    act->cnt_spinkey = 0;
    act->cnt_d2c = 0;
    act->cnt_to_rail = 0;
    act->cnt_grind = 0;
    act->cnt_real_grind = 0;
    act->cnt_manual = 0;
    act->cnt_total_grind = 0;
    act->cnt_total_manual = 0;
    act->cnt_plant = 0;
    act->cnt_holding = 0;
    act->cnt_planttumble = 0;
    act->cnt_plant2grind = 0;
    act->cnt_tumble = 0;
    act->cnt_nospin = 0;
    act->cnt_brake = 0;
    act->cnt_backward = 0;
    act->cnt_no_bodyhit = 0;
    act->cnt_hokan = 0;
    stance = param->chr_param.stance == 0 ? 0 : 1;
    act->jump_air = 0;
    act->def_goofy = stance;
    act->goofy = stance;
    act->fakie = 0;
    act->sliding_state = 0;
    act->pre_state = 0;
    act->nollie = 0;
    act->big_ollie = 0;
    act->super_ollie = 0;
    act->plant_to_fakie = 0;
    act->trick_keep = 0;
    act->tumble_type = 0;
    act->tumble_way = 0;
    act->trg_hopup = 0;
    act->trg_jumpup = 0;
    act->trg_touch = 0;
    act->trg_bonk = 0;
    act->trg_boost = 0;
    act->trg_rewind = 0;
    act->trg_hit_wall = 0;
    act->no_approach_speed = 0;
    act->hop_vertical_plane = 0;
    act->touch_perfect = 0;
    act->grind_jump = 0;
    act->grind_tumble = 0;
    act->hips = 1;
    act->trg_onair_with_over_hp = 0;
    act->trg_tumble_type = 0;
    act->trg_tumble_way = 0;
    act->trg_tumble_body = 0;
    act->end_grind = 0;
    act->end_manual = 0;
    act->end_sliding = 0;
    act->max_relief_gap = (float)act->sbcore.const_max_relief_gap;
    act->relief_gap = 0.0f;
    act->slant = 0.0f;
    act->side_slant = 0.0f;
    act->sp_slant = 0.0f;
    act->sp_side_slant = 0.0f;
    act->ofs_updown = 0.0f;
    act->target_way = 0.0f;
    act->pre_rail_list = 0;
    act->rail_list = 0;
    act->num_rail_vertex = 0;
    act->rail_id = -1;
    act->rail_no = 0;
    act->rail_pos[0] = 0.0f;
    act->rail_pos[1] = 0.0f;
    act->rail_pos[2] = 0.0f;
    act->rail_pos[3] = 1.0f;
    ktactInitBalance(&act->gr_balance);
    act->gr_enter_ang = 0.0f;
    act->gr_reset_lean = 1;
    act->trg_grind_name = 0;
    act->gr_grind_no = -1;
    act->gr_cnt_kissed = 0;
    act->gr_is_reverse = 0;
    act->gr_back_accel = 1;
    act->trg_change_grind = 0;
    act->changed_grind = 0;
    act->disaster = 0;
    act->first_grind = 1;
    act->gr_no_jump = 0;
    act->hp_air = 0;
    act->pre_hp_air = 0;
    act->halfpiping = 0;
    act->pre_halfpiping = 0;
    act->over_hp = 0;
    act->hp_jump = 0;
    act->hp_adj_roty = 0;
    act->hp_normal[0] = 0.0f;
    act->hp_normal[1] = 0.0f;
    act->hp_normal[2] = 0.0f;
    act->hp_normal[3] = 1.0f;
    act->hp_cross[0] = 0.0f;
    act->hp_cross[1] = 0.0f;
    act->hp_cross[2] = 0.0f;
    act->hp_cross[3] = 1.0f;
    act->manual_ready = 0;
    act->manual_ready_no = -1;
    act->manual_cnt_to_play = 0;
    ktactInitBalance(&act->manu_balance);
    // 3E0 was skipped, potential bug.
    act->bonk_ready;
    act->bonk_ready = 0;
    act->bonk_ready_no = -1;
    act->bonk_goto = 0;
    act->bonk_point[0] = 0.0f;
    act->bonk_point[1] = 0.0f;
    act->bonk_point[2] = 0.0f;
    act->bonk_point[3] = 1.0f;
    act->bonk_presp[0] = 0.0f;
    act->bonk_presp[1] = 0.0f;
    act->bonk_presp[2] = 0.0f;
    act->bonk_presp[3] = 1.0f;
    act->revert_cnt_ready = 0;
    act->revert_ready_no = -1;
    act->plant_air = 0;
    act->plant_normal[0] = 0.0f;
    act->plant_normal[1] = 0.0f;
    act->plant_normal[2] = 0.0f;
    act->plant_normal[3] = 0.0f;
    act->max_height = 0.0f;
    act->big_air = 0;
    act->cnt_onair = 0;
    act->cnt_onair2 = 0;
    act->cnt_nothit = 0;
    act->tumble_se_id = -1;
    act->jump_rot_pole = 0.0f;
    act->last_rot_pole = 0.0f;
    act->last_spin_way = 0;
    act->pos_waist[0] = 0.0f;
    act->pos_waist[1] = 0.0f;
    act->pos_waist[2] = 0.0f;
    act->pos_waist[3] = 0.0f;
    act->pos_disp[0] = 0.0f;
    act->pos_disp[1] = 0.0f;
    act->pos_disp[2] = 0.0f;
    act->pos_disp[3] = 0.0f;
    act->shadow_posy = 0.0f;
    ktactSetParam();
    ktactGetChrParamX10(&act->chr_param_x10, &param->chr_param);
    ktactGetBrdParamX10(&act->brd_param_x10, &param->brd_param);
    ktactInitParam2(&act->param, &act->chr_param_x10, &act->brd_param_x10);
    max_speed = iktactMakeParam_max_speed(act->param.speed);
    cmn_max_speed = iktactMakeParam_cmn_max_speed(act->param.speed);
    if (cheats->super_speed != 0) {
        max_speed *= 1.5f;
        cmn_max_speed *= 1.5f;
    }
    act->max_speed = max_speed;
    act->cmn_max_speed = cmn_max_speed;
    act->now_max_speed = cmn_max_speed;
    act->mot_finish = -1;
    act->mot_grabing = 0;
    act->mot_flipping = 0;
    act->mot_spflipping = 0;
    act->mot_grinding = 0;
    act->mot_planting = 0;
    act->mot_manualing = 0;
    act->mot_reverting = 0;
    act->mot_bonking = 0;
    act->mot_tumbling = 0;
    act->mot_reserve_tumble_standup = 0;
    act->mot_tumble_standup = 0;
    act->mot_tumble_standup_already = 0;
    act->mot_end_tumble = 0;
    act->mot_flip_rot[0] = 0.0f;
    act->mot_flip_rot[1] = 0.0f;
    act->mot_flip_rot[2] = 0.0f;
    act->mot_flip_rot[3] = 0.0f;
    act->mot_flip_roty_base = 0.0f;
    act->mot_flip_mode = 0;
    ktactInitTLinkAll(&act->trick_link);
    act->trk_doing = 0;
    act->trk_state = 0;
    act->trk_grab_no = -1;
    act->trk_trick_no = -1;
    act->trk_link_state = 0;
    act->num_set_gap = 0;
    for (i = 0; i < 64; i++) {
        act->set_gap[i] = -1;
    }
    act->special_num = 0;
    act->special_charge = 0;
    act->special_left_time = 0;
    act->special_total_time = (signed int)((vktactParamSpt_time * 0x3C) / 10);
    act->special_charge_cnt = 0;
    act->special_charge_maxcnt = (signed int)((((vktactParamSpt_charge_time * 0x3C) / 10) / 100));
    act->special_remainder_tp = 0;
    act->boost = 0;
    act->boost_num = 0;
    act->boost_charge = 0;
    act->boost_left_time = 0;
    act->boost_total_time = 0xD2;
    if ((vspenvGame->mode.game_mode == 1) && (vspenvGame->mode.match_rule == 1)) {
        act->boost = 1;
    }
    act->num_hit = 0;
    act->num_vec = 0;
    act->num_obj = 0;
    act->reserve_tumble = 0;
    act->reserve_tumble_ang = 0.0f;
    act->reserve_tumble_speed = -1.0f;
    act->reserve_tumble_type = 0;
    for (i = 0; i < 16; i++) {
        act->reserve_trick_no[i] = -1;
        act->reserve_trick_is_flip[i] = 0;
        act->reserve_trick_is_special[i] = 0;
    }
    act->num_reserve_trick = 0;
    act->top_reserve_trick = 0;
    act->reserve_stance_change = 0;
    act->num_reserve_grab = 0;
    act->balance_cnt_adj = 0;
    act->balance_ang_adj = 0.0f;
    act->balance_roty_adj = 0.0f;
    act->balance_bigair = 0;
    act->balance_pole[0] = 0.0f;
    act->balance_pole[1] = 0.0f;
    act->balance_pole[2] = 0.0f;
    act->balance_pole[3] = 0.0f;
    act->hang_rate = (float)(0.001f * (float)vktactParamHangRate);
    for (i = 0; i < 160; i++) {
        act->num_play_trick[0][i] = 0;
        act->num_play_trick[1][i] = 0;
    }
    ktactResetNumPlayTrickInLink(act);
    sceVu0UnitMatrix(act->mat_head);
    sceVu0UnitMatrix(act->mat_hip);
    act->recover_pos[0] = 0.0f;
    act->recover_pos[1] = 0.0f;
    act->recover_pos[2] = 0.0f;
    act->recover_pos[3] = 0.0f;
    act->recover_roty = 0.0f;
    act->recover_speed = 0.0f;
    act->recover = 0;
    act->trg_recovered = 0;
    act->reserve_fall = 0;
    act->cnt_fall = 0;
    act->cnt_warp = 0;
    act->water_manual = 0;
    for (i = 0; i < 2; i++) {
        cid = param->no;
        if (cid >= 12) {
            cid = vspenvEnv.mc.secret.create_character[cid - 12].trick_type; //(&vspenvEnv + ((cid - 0xC) * 0xEC))->unkE68;
        }
        act->sptrk[i] = vktactSpTrk[cid][i]; //(signed int) ((s64) ((s64) *((i * 2) + (&vktactSpTrk + (i * 4)))));
    }
    act->num_total_gap = 0;
    act->num_total_break = 0;
    act->reserve_quit = 0;
    act->allow_tlink = 1;
    act->no_trick = 0;
    act->trg_quit = 0;
    act->cnt_quit = -1;
    act->cnt_reserve_quit = 0;
    act->pass_finish_line = 0;
    act->pass_finish_line2 = 0;
    act->wait_motion = 0;
    act->wait_vs = 0;
    act->noheight_reflect = 0;
    act->cnt_noheight_reflect = 0;
    act->cnt_brank_noheight_reflect = 0;
    act->forced_bailout = 0;
    act->cnt_hit_wall = 0;
    act->cnt_brank_hit_wall = 0;
    act->cnt_forced_bailout = 0;
    for (i = 0; i < 10; i++) {
        act->last_hit_plane[i][0] = 0.0f;
        act->last_hit_plane[i][1] = 0.0f;
        act->last_hit_plane[i][2] = 0.0f;
        act->last_hit_plane[i][3] = 0.0f;
    }
    ktactCommandSet(act, key);
}

float iktactMakeParam_cmn_max_speed(signed int src) {
    float cmn_cmnsp; // r29
    float min_cmnsp; // 0x4(r29)
    float max_cmnsp; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_cmnsp = vktactParamCmnCmnSpeed;
    min_cmnsp = vktactParamMinCmnSpeed;
    max_cmnsp = vktactParamMaxCmnSpeed;
    param = cmn_cmnsp;
    if (src >= 0x32) {
        param += ((src - 0x32) * (max_cmnsp - cmn_cmnsp)) / 50.0f;
    } else {
        param += ((float)(0x32 - src) * (min_cmnsp - cmn_cmnsp)) / 40.0f;
    }
    return param;
}

float iktactMakeParam_max_speed(signed int src) {
    float cmn_maxsp; // r29
    float min_maxsp; // 0x4(r29)
    float max_maxsp; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_maxsp = vktactParamCmnMaxSpeed;
    min_maxsp = vktactParamMinMaxSpeed;
    max_maxsp = vktactParamMaxMaxSpeed;
    param = cmn_maxsp;
    if (src >= 0x32) {
        param += ((float)(src - 0x32) * (max_maxsp - cmn_maxsp)) / 50.0f; //((float) (src - 0x32) * ((second half of f64) - (bitwise float) (f64) max_maxsp)) / 50.0f;
    } else {
        param += ((float)(0x32 - src) * (min_maxsp - cmn_maxsp)) / 40.0f; // param += ((float) (0x32 - src) * ((second half of f64) - (bitwise float) (f64) min_maxsp)) / 40.0f;
    }
    return param;
}

static void ktactGetChrParamX10(Character_Param* cp10, Character_Param* cp) {
    cp10->ollie = cp->ollie * 10;
    cp10->spin = cp->spin * 10;
    cp10->speed = cp->speed * 10;
    cp10->landing = cp->landing * 10;
    cp10->balance = cp->balance * 10;
    cp10->stability = cp->stability * 10;
    cp10->stance = cp->stance;
}

static void ktactGetBrdParamX10(Board_Param* bp10, Board_Param* bp) {
    bp10->speed = bp->speed * 10;
    bp10->stability = bp->stability * 10;
    bp10->balance = bp->balance * 10;
    bp10->turning = bp->turning * 10;
}

static void ktactInitParam2(Param2* param /* 90 */, Character_Param* cp10 /* A0 */, Board_Param* bp10 /* B0 */) {
    signed int ollie = cp10->ollie; // r17
    signed int spin = cp10->spin; // r18
    signed int speed = ((cp10->speed * 0x4b) + (bp10->speed * 0x19)) / 100; // r19
    signed int landing = ((cp10->landing * 0x4B) + (bp10->stability * 0x19)) / 100; // r16
    signed int landing_switch = (((landing << 2) + landing) * 16) / 100; // r20
    signed int balance = ((cp10->balance * 7) + (bp10->balance * 3)) / 10; // r21
    signed int quickness = bp10->turning; // r22
    signed int power = cp10->stability; // r23
    signed int turning = bp10->turning; // r30

    param->ollie = ollie;
    param->spin = spin;
    param->speed = speed;
    param->landing = landing;
    param->landing_switch = landing_switch;
    param->balance = balance;
    param->quickness = quickness;
    param->power = power;
    param->turning = turning;
}

static void ktactSetParam() {
    vktactParamCmnRetRate = vktactCmnParam.quickness;
    vktactParamMinRetRate = vktactMinParam.quickness;
    vktactParamMaxRetRate = vktactMaxParam.quickness;
    vktactParamCmnJumpPower = 0.01f * (-9.8f * (float)vktactCmnParam.jump_power);
    vktactParamMinJumpPower = 0.01f * (-9.8f * (float)vktactMinParam.jump_power);
    vktactParamMaxJumpPower = 0.01f * (-9.8f * (float)vktactMaxParam.jump_power);
    vktactParamCmnTurn = (3.141592f * (float)vktactCmnParam.turning) / 180.0f;
    vktactParamMinTurn = (3.141592f * (float)vktactMinParam.turning) / 180.0f;
    vktactParamMaxTurn = (3.141592f * (float)vktactMaxParam.turning) / 180.0f;
    vktactParamCmnSitTurn = (3.141592f * (float)vktactCmnParam.sit_turning) / 180.0f;
    vktactParamMinSitTurn = (3.141592f * (float)vktactCmnParam.sit_turning) / 180.0f;
    vktactParamMaxSitTurn = (3.141592f * (float)vktactCmnParam.sit_turning) / 180.0f;
    vktactParamCmnQuickTurn = (3.141592f * (float)vktactCmnParam.quick_turning) / 180.0f;
    vktactParamMinQuickTurn = (3.141592f * (float)vktactCmnParam.quick_turning) / 180.0f;
    vktactParamMaxQuickTurn = (3.141592f * (float)vktactCmnParam.quick_turning) / 180.0f;
    vktactParamCmnMaxSpeed = (1000.0f * (float)vktactCmnParam.max_speed) / 3600.0f;
    vktactParamMinMaxSpeed = (1000.0f * (float)vktactMinParam.max_speed) / 3600.0f;
    vktactParamMaxMaxSpeed = (1000.0f * (float)vktactMaxParam.max_speed) / 3600.0f;
    vktactParamCmnCmnSpeed = (1000.0f * (float)vktactCmnParam.cmn_max_speed) / 3600.0f;
    vktactParamMinCmnSpeed = (1000.0f * (float)vktactMinParam.cmn_max_speed) / 3600.0f;
    vktactParamMaxCmnSpeed = (1000.0f * (float)vktactMaxParam.cmn_max_speed) / 3600.0f;
    vktactParamCmnSpin = (3.141592f * (float)vktactCmnParam.spin) / 180.0f;
    vktactParamMinSpin = (3.141592f * (float)vktactMinParam.spin) / 180.0f;
    vktactParamMaxSpin = (3.141592f * (float)vktactMaxParam.spin) / 180.0f;
    vktactParamCmnGrind = (3.141592f * (float)vktactCmnParam.grind) / 180.0f;
    vktactParamMinGrind = (3.141592f * (float)vktactMinParam.grind) / 180.0f;
    vktactParamMaxGrind = (3.141592f * (float)vktactMaxParam.grind) / 180.0f;
    vktactParamCmnLanding = 0.01f * (float)vktactCmnParam.landing;
    vktactParamMinLanding = 0.01f * (float)vktactMinParam.landing;
    vktactParamMaxLanding = 0.01f * (float)vktactMaxParam.landing;
}

void ktactInitPos(Pos* pos) {
    pos->pos[0] = 0.0f;
    pos->pos[1] = 0.0f;
    pos->pos[2] = 0.0f;
    pos->pos[3] = 1.0f;
    pos->cross[0] = 0.0f;
    pos->cross[1] = 0.0f;
    pos->cross[2] = 0.0f;
    pos->cross[3] = 1.0f;
    pos->normal[0] = 0.0f;
    pos->normal[1] = 0.0f;
    pos->normal[2] = 0.0f;
    pos->normal[3] = 1.0f;
    pos->material = 0;
    pos->hit = 0;
    pos->halfpipe = 0;
    pos->ripping = 0;
    pos->bonk = 0;
    pos->low_g = 0;
    pos->no = -1;
    pos->len2 = 0.0f;
    pos->type = 0;
}

void ktactInitRequest(Req* req) {
    req->accel_brake = 0;
    req->sitting = 0;
    req->jump = 0;
    req->stance_change = 0;
    req->command = 0;
    req->cmd_mot_id = -1;
    req->cmd_mot_nloop = 0;
    req->cmd_trick_no = -1;
    req->end_fall = 0;
    req->trick_no = -1;
    req->flip_no = -1;
    req->grind_no = -1;
    req->plant_no = -1;
    req->bonk_no = -1;
    req->manual_no = -1;
    req->revert_no = -1;
    req->jump_no = -1;
    req->sptrk_id = -1;
}

void ktactInitInput(Inp* inp) {
    inp->turn = 0;
    inp->turn_x = 0;
    inp->quick_turn = 0;
    inp->accel_state = 0;
    inp->jump_state = 0;
    inp->stance_change = 0;
    inp->spin_way = 0;
    inp->command = 0;
    inp->cmd_mot_id = -1;
    inp->cmd_mot_nloop = 0;
    inp->cmd_trick_no = -1;
    inp->keyway = 0;
    inp->tumble_speed_up = 0;
    inp->accel_speed = 0;
    inp->stop_speed = 0;
}

static void ktactInitBalance(Balance* bal) {
    bal->balance = 0.0f;
    bal->lean = 0.0f;
    bal->lean_dir = 0.0f;
    bal->released = 0;
    bal->cnt_free = 0;
}

static void ktactResetBalance(Balance* bal, s32 reset_lean, s32 free_frame) {
    bal->balance = 0.0f;
    if (reset_lean != 0) {
        bal->lean = 0.0f;
    } else if (bal->lean > 0.0f) {
        if (bal->lean < (vktactParamBal_lean_limit * 2) / 3) {
            bal->lean += ((vktactParamBal_lean_limit * 2) / 15);
            if ((bal->lean > (vktactParamBal_lean_limit * 2) / 3)) {
                bal->lean = ((vktactParamBal_lean_limit * 2) / 3);
            }
        }
    } else if (bal->lean > -((vktactParamBal_lean_limit * 2) / 3)) {
        bal->lean -= (vktactParamBal_lean_limit * 2) / 15;
        if (bal->lean < -((vktactParamBal_lean_limit * 2) / 3)) {
            bal->lean = -((vktactParamBal_lean_limit * 2) / 3);
        }
    }
    bal->lean_dir = (0.1f * vktactParamBal_lean_start_dir);
    bal->released = 0;
    bal->cnt_free = free_frame;
}

static void ktactInitTLinkAll(TrickLink* tl) {
    ktactInitTLink(tl);
    tl->link_rate = 0;
    tl->link_trick_point = 0;
    tl->total_trick_point = 0;
    tl->last_link_trick_point = 0;
    tl->get_point = 0;
    tl->total_trick_num = 0;
    tl->best_link_num = 0;
    tl->best_link_pts = 0;
    tl->get_the_best = 0;
    tl->pre_spin_ang = 0;
}

static void ktactInitTLink(TrickLink* tl) {
    ktactResetTrickPointOneSet(tl);
    tl->trick_link = 0;
    tl->trg_start_link = 0;
    tl->trg_end_link = 0;
    tl->trg_get_pts = 0;
    tl->spenv_get_trick_no = -1;
    tl->pre_cnt_link = 0;
    tl->cnt_link = 0;
    tl->cnt_trick = 0;
    tl->last_point = 0;
    tl->is_bonus_landing = 0;
}

static void ktactResetTrickPointOneSet(TrickLink* tl) {
    tl->is_bonus_switch = 0;
    tl->is_bonus_spin = 0;
    tl->is_bonus_airtime = 0;
    tl->set_top_cnt_link = 0;
    tl->added_nollie = 0;
    tl->added_airtime = 0;
    tl->trg_trick = -1;
    tl->pts_current_trick = 0;
    tl->pts_current_hold = 0;
    tl->pts_current_spin = 0;
    tl->pts_trick = 0;
    tl->pts_gap = 0;
    tl->cnt_total_hold = 0;
    tl->spin_ang = 0;
    tl->last_spin_ang = 0;
    tl->airtime_frame = 0;
    tl->current_set_tp = 0;
    tl->current_set_tp_rate = 0;
}

static void ktactCommandInit(Cmd* cmd, short cmdtype, int way1, int way2, signed int way3, signed int way4, unsigned short fin_button, signed int rev) {
    if (cmdtype == 1) {
        way2 = way1;
        way1 = 8 - way1;
    } else if (cmdtype == 2) {
        way2 = way1;
    }

    cmd->type = cmdtype;
    cmd->way1 = (way1);
    cmd->way2 = (way2);
    cmd->way3 = (way3);
    cmd->way4 = (way4);
    cmd->fin_button = fin_button;
    cmd->rev_button = (rev);
    cmd->inp_fin_button = 0;
    cmd->left_count = 0;
    cmd->fin_left_count = 0;
    cmd->step = 0;
    cmd->ok = 0;
}

static void ktactCommandReset(Cmd* cmd) {
    cmd->inp_fin_button = 0;
    cmd->left_count = 0;
    cmd->fin_left_count = 0;
    cmd->step = 0;
    cmd->ok = 0;
    cmd->passtime = 0;
}

static void ktactCommandResetAll(Act* act) {
    signed int i; // r16

    for (i = 0; i < 9; i++) {
        ktactCommandReset(&act->cmd_trick[i]);
        ktactCommandReset(&act->cmd_flip[i]);
        ktactCommandReset(&act->cmd_grind[i]);
        ktactCommandReset(&act->cmd_plant[i]);
        ktactCommandReset(&act->cmd_bonk[i]);
        ktactCommandReset(&act->cmd_manual[i]);
    }
    for (i = 9; i < 25; i++) {
        ktactCommandReset(&act->cmd_trick[i]);
        ktactCommandReset(&act->cmd_flip[i]);
        if (i < 13) {
            ktactCommandReset(&act->cmd_grind[i]);
        }
    }
    for (i = 0; i < 2; i++) {
        ktactCommandReset(&act->cmd_sptrk[i]);
    }
}

static void ktactCommandResetAllForGrind(Act* act, signed int grind_no) {
    signed int i; // r16
    signed int reset_hi_grind; // r17

    reset_hi_grind = 1;
    for (i = 0; i < 9; i++) {
        ktactCommandReset(&act->cmd_trick[i]);
        ktactCommandReset(&act->cmd_flip[i]);
        ktactCommandReset(&act->cmd_plant[i]);
        ktactCommandReset(&act->cmd_bonk[i]);
        ktactCommandReset(&act->cmd_manual[i]);
        if (grind_no == vktactCmdToGrind[i]) {
            reset_hi_grind = 0;
        }
        ktactCommandReset(&act->cmd_grind[i]);
    }
    for (i = 9; i < 0x19; i++) {
        ktactCommandReset(&act->cmd_trick[i]);
        ktactCommandReset(&act->cmd_flip[i]);
        if ((reset_hi_grind != 0) && (i < 0xD)) {
            ktactCommandReset(&act->cmd_grind[i]);
        }
    }
}

static void ktactCommandResetAllForRevert(Act* act) {
    signed int i; // r16

    for (i = 0; i < 9; i++) {
        ktactCommandReset(&act->cmd_trick[i]);
        ktactCommandReset(&act->cmd_flip[i]);
        ktactCommandReset(&act->cmd_grind[i]);
        ktactCommandReset(&act->cmd_plant[i]);
        ktactCommandReset(&act->cmd_bonk[i]);
    }
    for (i = 9; i < 0x19; i++) {
        ktactCommandReset(&act->cmd_trick[i]);
        ktactCommandReset(&act->cmd_flip[i]);
        if (i < 0xD) {
            ktactCommandReset(&act->cmd_grind[i]);
        }
    }
}

static void ktactCommandResetAllForJump(Act* act) {
    signed int i; // r16
    Cmd* cmd; // r17

    for (i = 0; i < 9; i++) {
        cmd = &act->cmd_trick[i];
        if ((cmd->passtime) >= 5) {
            ktactCommandReset(cmd);
        }
        cmd = &act->cmd_flip[i];
        if ((cmd->passtime) >= 5) {
            ktactCommandReset(cmd);
        }
        ktactCommandReset(&act->cmd_grind[i]);
        ktactCommandReset(&act->cmd_plant[i]);
        ktactCommandReset(&act->cmd_bonk[i]);
        ktactCommandReset(&act->cmd_manual[i]);
    }
    for (i = 9; i < 0x19; i++) {
        cmd = &act->cmd_trick[i];
        if ((cmd->passtime) >= 5) {
            ktactCommandReset(cmd);
        }
        cmd = &act->cmd_flip[i];
        if ((cmd->passtime) >= 5) {
            ktactCommandReset(cmd);
        }
        if (i < 0xD) {
            ktactCommandReset(&act->cmd_grind[i]);
        }
    }
    for (i = 0; i < 2; i++) {
        ktactCommandReset(&act->cmd_sptrk[i]);
    }
}

static void ktactCommandResetAllForTrick(Act* act) {
    signed int i; // r16

    for (i = 0; i < 9; i++) {
        if (act->cmd_trick[i].fin_left_count == 0) {
            ktactCommandReset(&act->cmd_trick[i]);
        }
        if (act->cmd_flip[i].fin_left_count == 0) {
            ktactCommandReset(&act->cmd_flip[i]);
        }
        ktactCommandReset(&act->cmd_grind[i]);
        ktactCommandReset(&act->cmd_plant[i]);
        ktactCommandReset(&act->cmd_bonk[i]);
        ktactCommandReset(&act->cmd_manual[i]);
    }
    for (i = 9; i < 0x19; i++) {
        if (act->cmd_trick[i].fin_left_count == 0) {
            ktactCommandReset(&act->cmd_trick[i]);
        }
        if (act->cmd_flip[i].fin_left_count == 0) {
            ktactCommandReset(&act->cmd_flip[i]);
        }
        if (i < 0xD) {
            ktactCommandReset(&act->cmd_grind[i]);
        }
    }
    for (i = 0; i < 2; i++) {
        if ((act->cmd_sptrk[i].fin_button == 0x20) || (act->cmd_sptrk[i].fin_button == 0x80)) {
            if (act->cmd_sptrk[i].fin_left_count == 0) {
                ktactCommandReset(&act->cmd_sptrk[i]);
            }
        } else {
            ktactCommandReset(&act->cmd_sptrk[i]);
        }
    }
}

// ktact.c
static void ktactCommandSet(Act* act, Key_Config* key) {
    signed int i; // r16
    signed int nop; // r17
    signed int way1; // r18
    signed int way2; // r20

    nop = 4;
    for (i = 0; i < 9; i++) {
        ktactCommandInit(&act->cmd_trick[i], 5, i, nop, nop, nop, 0x20, 0);
        ktactCommandInit(&act->cmd_flip[i], 5, i, nop, nop, nop, 0x80, 0);
        ktactCommandInit(&act->cmd_grind[i], 4, i, nop, nop, nop, 0x10, 0);
        ktactCommandInit(&act->cmd_plant[i], 4, i, nop, nop, nop, 0x10, 0);
        ktactCommandInit(&act->cmd_bonk[i], 0, i, nop, nop, nop, 0x40, 1);
        if ((i == 3) || (i == 5)) {
            ktactCommandInit(&act->cmd_manual[i], 6, 7, i, 1, nop, 0, 0);
        } else {
            ktactCommandInit(&act->cmd_manual[i], 1, i, i, i, i, 0, 0);
        }
    }
    for (i = 9; i < 25; i++) {
        way1 = i - 9;
        way2 = way1 % 4;
        way1 = way1 / 4;
        way1 = (way1 * 2) + 1;
        way2 = (way2 * 2) + 1;
        ktactCommandInit(&act->cmd_trick[i], 3, way1, way2, nop, nop, 0x20, 0);
        ktactCommandInit(&act->cmd_flip[i], 3, way1, way2, nop, nop, 0x80, 0);
    }
    for (i = 9; i < 13; i++) {
        way1 = i - 9;
        way1 = way1 % 4;
        way1 = (way1 * 2) + 1;
        ktactCommandInit(&act->cmd_grind[i], 1, way1, way1, nop, nop, 0x10, 0);
    }
    way1 = 7;
    way2 = 1;
    ktactCommandInit(&act->cmd_jump[0], 5, nop, nop, nop, nop, 0x40, 1);
    ktactCommandInit(&act->cmd_jump[1], 5, way1, nop, nop, nop, 0x40, 1);
    ktactCommandInit(&act->cmd_jump[2], 3, way1, way1, nop, nop, 0x40, 1);
    ktactCommandInit(&act->cmd_jump[3], 5, way2, nop, nop, nop, 0x40, 1);
    for (i = 0; i < 2; i++) {
        signed int sptrk_way[2][3] = {{3, 1, 5}, {5, 1, 3}}; // 0xA0(r29)
        s32* sptrk_wayPtr = &sptrk_way; // r22
        unsigned short btn; // r19

        (void)sptrk_wayPtr;
        switch (act->sptrk[i]) {
            case 84:
            case 87:
            case 91:
            case 99:
            case 101:
            case 102:
                btn = 0x20;
                break;
            case 88:
            case 92:
            case 94:
            case 103:
            case 107:
                btn = 0x10;
                break;
            case 85:
            case 104:
                btn = 0x10;
                break;
            case 105:
                btn = 0x10;
                break;
            case 86:
            case 89:
            case 90:
            case 93:
            case 95:
            case 96:
            case 97:
            case 98:
            case 100:
            case 106:
            default:
                btn = 0x80;
                break;
        }
        ktactCommandInit(&act->cmd_sptrk[i], 6, sptrk_way[i][0], sptrk_way[i][1], sptrk_way[i][2], nop, btn, 0);
    }
    for (i = 0; i < 2; i++) {
        signed int revert_way[1] = {4}; // 0xBC(r29)
        s32* revert_wayPtr = &revert_way; // r23
        unsigned short btn; // r30

        (void)revert_wayPtr;
        btn = (i & 1) ? key->stance : key->revert;
        way1 = revert_way[i / 2];
        ktactCommandInit(&act->cmd_revert[i], 5, way1, nop, nop, nop, btn, 0);
    }
}

static void ktactResetNumPlayTrickInLink(Act* act) {
    signed int j; // r16
    signed int i; // r17

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 160; j++) {
            act->num_play_trick_in_link[i][j] = 0;
        }
    }
}

static void ktactRecoverNumPlayTrick(Act* act) {
    signed int j; // r16
    signed int i; // r17

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 0xA0; j++) {
            act->num_play_trick[i][j] -= act->num_play_trick_in_link[i][j];
            act->num_play_trick_in_link[i][j] = 0;
        }
    }
}

void ktactSetCaminfo(Cam* cam, Ctrl* rc) {
    Act* act; // r16
    signed int from; // r17
    sceVu0FVECTOR* ver;
    signed int to; // r20

    float hp[4];
    float nor[4];
    float outer[4];
    float inner;

    act = &rc->act;
    *(__int128*)cam->pre_speed = *(__int128*)cam->now_speed;
    *(__int128*)cam->now_speed = *(__int128*)rc->speed;
    if (act->sliding_state != essPlant) {
        *(__int128*)cam->normal_speed = *(__int128*)rc->speed;
    }
    *(__int128*)cam->rot = *(__int128*)rc->rot;
    *(__int128*)cam->pos_waist = *(__int128*)act->pos_waist;
    *(__int128*)cam->pos_disp = *(__int128*)act->pos_disp;
    // temp_t0 = rc->nowpos;
    // temp_a3 = cam->pos;
    cam->pos = rc->nowpos;
    // temp_t0_2 = rc->prepos;
    // temp_a3_2 = cam->prepos;
    cam->prepos = rc->prepos;
    cam->sliding_state = (signed int)act->sliding_state;
    cam->pre_state = (signed int)act->pre_state;
    if (act->sliding_state != essTumble) {
        cam->pre_tumble_state = (signed int)act->sliding_state;
    }
    cam->max_height = (float)act->max_height;
    cam->cnt_onair = (signed int)act->cnt_onair2;
    cam->cnt_turn = (signed int)act->cnt_turn;
    cam->max_speed = (float)act->max_speed;
    cam->hp_air = (signed int)act->hp_air;
    cam->tumble_type = (signed int)act->tumble_type;
    cam->tumble_way = (signed int)act->tumble_way;
    cam->trg_tumble_type = (signed int)act->trg_tumble_type;
    if ((rc->nowpos.hit != 0) && (rc->nowinp.jump_state < 4)) {
        cam->splen_prejump = (float)rc->splen;
    }
    cam->trg_tumble_standup = (signed int)act->mot_tumble_standup;
    cam->grind_enter_ang = (float)act->gr_enter_ang;
    cam->trick_link = act->trick_link.trick_link;
    cam->trg_start_endmot = 0;
    cam->trg_recovered = (signed int)act->trg_recovered;
    cam->trg_hopup = (signed int)act->trg_hopup;
    cam->trg_jumpup = (signed int)act->trg_jumpup;
    cam->trg_touch = (signed int)act->trg_touch;
    cam->trg_boost = (signed int)act->trg_boost;
    cam->bonk_goto = (signed int)act->bonk_goto;
    if ((act->sliding_state == essPlant) && (act->cnt_plant == 2)) {
        cam->trg_plant = 1;
    } else {
        cam->trg_plant = 0;
    }
    cam->grind_goto = act->cnt_to_rail > 0 ? 1 : 0;
    if (rc->nowpos.hit != 0) {
        cam->ripside = 0;
        return;
    }
    if ((cam->ripside == 0) && (act->hp_air != 0) && (act->col_hp.vertex[0] != 0)) {
        ver = act->col_hp.vertex;
        from = act->col_hp.no;
        if (from >= act->col_hp.nvertex - 1) {
            from = act->col_hp.nvertex - 1;
        }
        to = from + 1;
        sceVu0SubVector(hp, ver[to], ver[from]);
        hp[1] = 0.0f;
        sceVu0Normalize(hp, hp);
        inner = sceVu0InnerProduct(rc->speed, hp);
        sceVu0Normalize(nor, act->hp_normal);
        sceVu0OuterProduct(outer, hp, nor);
        if (!(inner <= 0.0f)) {
            if (!(outer[1] <= 0.0f)) {
                cam->ripside = 1;
                return;
            }
            cam->ripside = 2;
            return;
        }
        if (!(outer[1] <= 0.0f)) {
            cam->ripside = 2;
            return;
        }
        cam->ripside = 1;
    }
}

// ktact.c
void ktactSetSeinfo(Se* se, Ctrl* rc) {
    float m[4][4]; // 0x20(r29)
    float lsp[4]; // 0x60(r29)
    float ftmp; // 0x74(r29)

    sbcoreGetRotMatrix(m, rc->pole, rc->rot_pole);
    sceVu0InversMatrix(&m, &m);
    sceVu0ApplyMatrix(&lsp[0], &m, &rc->speed);
    se->splen = rc->splen;
    se->anggap_sp_brd = atan2f(-lsp[0], -lsp[2]);
    ftmp = rc->rot_pole - se->rot_pole;
    se->anggap_board_rot = ftmp < -3.141592f  ? 6.283184f + ftmp
                           : ftmp > 3.141592f ? ftmp - 6.283184f
                                              : ftmp;
    se->rot_pole = rc->rot_pole;
    se->side_slide = rc->act.cnt_d2c > 0 ? 1 : 0;
    if (rc->act.cnt_fall > 0) {
        se->splen = 0.0f;
    }
}

void ktactGetRotVector(float* rot /* 0xC0(r29) */, float* pole /* 0xD0(r29) */, float rot_pole /* 0xE0(r29) */, Sliding_State ss /* 0xF0(r29) */) {
    float lv0[4] = {1.0f, 0.0f, 0.0f, 1.0f}; // r29+0x30 // @461
    s32* lv0Ptr = &lv0;
    float lv2[4] = {0.0f, 0.0f, 1.0f, 1.0f}; // r29+0x40 @462
    s32* lv2Ptr = &lv2;
    float wv0[4]; // r29+0x50
    float wv2[4]; // r29+0x60
    float m[4][4]; // r29+0x70
    float lenxz0; // r29+0xB8
    float lenxz2; // r29+0xBC

    sbcoreGetRotMatrix(&m, pole, rot_pole);
    sceVu0ApplyMatrix(&wv0, &m, &lv0);
    sceVu0ApplyMatrix(&wv2, &m, &lv2);
    lenxz0 = iktactGetLenXZ(&wv0);
    lenxz2 = iktactGetLenXZ(&wv2);
    if (ss == essOnAir) {
        rot[1] = rot_pole;
        rot[3] = 1.0f;
        return;
    }
    rot[0] = atan2f(wv2[1], lenxz2);
    rot[1] = rot_pole;
    rot[2] = atan2f(wv0[1], lenxz0);
    rot[3] = 1.0f;
}

// ktact.c
float iktactGetLenXZ(float* v) {
    float vv[4]; // 0x10(r29)

    sceVu0MulVector(&vv, v, v);
    return isbcoreSqrtf(vv[0] + vv[2]);
}

float isbcoreSqrtf(float var) {
    float ret = 0.0f;
    asm("sqrt.s ret, var");
    return ret;
}

static void ktactPlaySE(Rider* rider) {
    Act* act; // r16
    signed int i; // r17
    signed int pid; // r18
    Ctrl* rc; // r19
    signed int mat_nowpos; // r20
    signed int mat_plane_hit; // r21

    rc = &rider->ctrl;
    act = &rc->act;
    pid = rider->pid;
    mat_nowpos = rc->nowpos.material & 0x7FF;
    mat_plane_hit = act->sbcore.plane_hit.material & 0x7FF;
    if (act->pre_state == essGrind && act->sliding_state != essGrind) {
        nmactStop(pid, 2);
    } else if (act->pre_state != essGrind && act->sliding_state == essGrind) {
        nmactPlay(pid, 2, mat_nowpos);
    }
    if (act->cnt_fall == 0) {
        if (act->trg_touch) {
            nmactPlayLand(pid, mat_nowpos, act->big_air);
        } else if (act->trg_jumpup) {
            nmactPlay(pid, 0, mat_nowpos);
        }
        if (act->sbcore.move == 0) {
            nmactPlay(pid, 3, mat_plane_hit);
        }
        if (act->tumble_se_id >= 0) {
            nmactPlaySlip(pid, act->tumble_se_id);
        }
        for (i = 0; i < act->num_hit; i++) {
            switch (act->col_hit[i].no) {
                case 0xE:
                case 0xF:
                case 0x10:
                case 0x11:
                    nmactPlay(pid, 4, act->col_hit[i].no);
                    break;
            }
        }
    }
    if (act->trg_boost) {
        nmactPlayBoost(pid);
    }
    if (rc->nowinp.stance_change || rc->nowinp.command == ecmdRevert) {
        nmactDualSwitch(pid);
    }
}

void ktactCtrl(Rider* rider, signed int end_brake) {
    Ctrl* rc; // r17
    Act* act; // r16
    Ope* ope; // 0xFC(r29)
    signed int prehit; // 0x100(r29)
    TrickLink* tl; // r18
    VspDispEnvChar* disp; // r20
    signed int cnt; // 0x104(r29)
    signed int per; // r30
    unsigned int frame; // 0x108(r29)
    signed int arg0; // r19
    signed int arg1; // r21
    signed int fakie; // r23
    signed int jump; // 0x10C(r29)
    signed int grind; // 0x110(r29)
    signed int disaster; // 0x114(r29)
    signed int i; // r22
    signed int success; // 0x118(r29)

    rc = &rider->ctrl;
    act = &rc->act;
    prehit = rc->nowpos.hit;
    tl = &act->trick_link;
    disp = &vspDispEnvChar[rider->pid];
    if (act->no_trick) {
        act->num_set_gap = 0;
    }
    ktactUpdateParam(rc);
    ktactSetAccelWay(rc);
    if (vspModeData.flow_mode == 6) {
        if (act->reserve_quit && (act->cnt_quit < 0) && (vspDispEnv.mode == 4) && (vspReplay[rider->pid]->num_frame == 0x5B68) &&
            (vspModeData.game_count >= vspReplay[rider->pid]->num_frame)) {
            act->trg_quit = 1;
        }
        if ((vspModeData.game_count >= vspReplay[rider->pid]->num_frame) || (vspModeData.game_count == vspReplay[rider->pid]->endrun_frame)) {
            if (act->cnt_quit < 0) {
                act->reserve_quit = 1;
            }
            act->allow_tlink = 0;
        }
    }
    act->trg_recovered = 0;
    if (act->recover) {
        sceVu0FVECTOR sp = {0.0f, 0.0f, -act->recover_speed, 0.0f}; // 0xA0(r29)
        sceVu0FMATRIX mat; // 0xB0(r29)
        s32* volatile spPtr = &sp;
        (void)spPtr;

        spRiderSetPos2(rider, act->recover_pos, act->recover_roty);
        act->recover = 0;
        act->trg_recovered = 1;
        sbcoreGetRotMatrix(mat, rc->pole, rc->rot_pole);
        sceVu0ApplyMatrix(sp, mat, sp);
        sbcoreGetShadowRotVector(rc->speed, rc->nowpos.normal, sp);
        rider->disp.reset_effect2 = 1;
        act->manual_ready = 0;
        act->bonk_ready = 0;
        act->revert_cnt_ready = 0;
        act->num_reserve_trick = 0;
        act->num_reserve_grab = 0;
        rider->disp.disp_shadow = 1;
        act->cnt_onair = 0;
        act->cnt_onair = 0;
        act->cnt_onair2 = 0;
        act->cnt_nospin = 0;
        tl->is_bonus_spin = 0;
        tl->is_bonus_airtime = 0;
    }
    if ((act->cnt_fall > 0) || (act->cnt_warp > 0)) {
        cnt = 0;
        if (act->cnt_fall > 0) {
            if (act->cnt_fall < 0x5A) {
                cnt = 0x5A - act->cnt_fall;
            }
        } else if (act->cnt_warp < 0x50) {
            cnt = 0x50 - act->cnt_warp;
        }
        per = cnt * 6;
        if (per > 0xFF) {
            per = 0xFF;
        }
        spSetWndFade(rider->pid, per);
        if (per == 0xFF) {
            if (act->cnt_fall > 0) {
                act->cnt_fall = 1;
            } else {
                act->cnt_warp = 1;
                spSetWndFade(rider->pid, 0xB4);
            }
        }
    }
    rc->rot[3] = 1.0f;
    rc->nowpos.pos[3] = 1.0f;
    rc->speed[3] = 1.0f;
    rc->pole[3] = 1.0f;
    rc->splen = iktactGetLen(rc->speed);
    rc->splenxz = iktactGetLenXZ(rc->speed);
    if (((vspModeData.flow_mode == 3) || (vspModeData.flow_mode == 6)) && !vspModeData.flow_count) {
        act->pre_state = essSitting;
        act->sliding_state = essSitting;
    }
    ktactSetHeadHipMatrix(rider);
    ktactSetHeadHipOffset(act->sbcore.pos_head, act->sbcore.pos_hip, rider);
    ktactUpdateStateByMot(rc);
    ktactMove(rc);
    rc->splen = iktactGetLen(rc->speed);
    rc->splenxz = iktactGetLenXZ(rc->speed);
    if (rider->pid < vspenvGame->mode.num_player) {
        ope = vgmsysPad[rider->pid];
    } else {
        ope = 0;
    }
    rc->prepad = rc->nowpad;
    rc->preinp = rc->nowinp;
    rc->prereq = rc->nowreq;
    ktactInitInput(&rc->nowinp);
    ktactInitRequest(&rc->nowreq);
    if (act->cnt_quit >= 0) {
        ktactSetPadCnt(&rc->nowpad, 0, 0);
        if (end_brake) {
            rc->nowreq.accel_brake = 2;
        }
        if (!act->sliding_state && (rc->splen < 1.3888888f) && (rc->mot.now.frame == rc->mot.now.num_frame) && !act->cnt_fall && !act->cnt_warp) {
            act->end_sliding = 1;
        }
    } else if (vspModeData.flow_mode == 6) {
        frame = vspModeData.game_count;
        if (frame < vspReplay[rider->pid]->num_frame) {
            rc->nowpad = vspReplay[rider->pid]->pad_data[frame];
        } else {
            ktactSetPadCnt(&rc->nowpad, 0, 0);
            rc->nowreq.accel_brake = 2;
        }
    } else {
        ktactSetPadCnt(&rc->nowpad, ope, rc->cheats->mirror);
    }
    if (act->cnt_warp > 0) {
        rc->nowinp.stop_speed = 1;
        ktactSetPadCnt(&rc->nowpad, 0, 0);
    }
    ktactSetRequest(rc);
    if (((vspModeData.flow_mode == 3) || (vspModeData.flow_mode == 6)) && !vspModeData.flow_count) {
        rc->nowreq.jump = 5;
        rc->nowreq.sitting = 0;
        rc->nowinp.accel_state = 12;
        rc->nowreq.stance_change = 0;
    }
    ktactSetSlidingState(rc);
    ktactSetInput0(rc);
    ktactUpdateState(rc);
    ktactSetInput1(rc);
    ktactReflectInput(rc);
    ktactAdj(rc);
    ktactUpdateTrickLink(&act->trick_link, rc);
    ktactUpdateSpecialTrick(rc);
    ktactUpdateBoost(rc);
    rc->splen = iktactGetLen(rc->speed);
    rc->splenxz = iktactGetLenXZ(rc->speed);
    ktactGetRotVector(rc->rot, rc->disp_pole, rc->rot_pole, act->sliding_state);
    ktactSetCaminfo(&rc->cam, rc);
    ktactSetSeinfo(&rc->se, rc);
    ktactPlaySE(rider);
    if (tl->trg_start_link && !tl->trick_link) {
        nmdispInputTrick(rider->pid);
        tl->trick_link = 1;
    }
    if (((vspModeData.flow_mode == 3) || (vspModeData.flow_mode == 6)) && (act->cnt_quit < 0) && tl->trick_link) {
        if (tl->trg_end_link) {
            disp->points.single = tl->last_link_trick_point;
            disp->points.total = tl->total_trick_point;
            disp->points.link_rate = 100;
        } else {
            disp->points.single = tl->link_trick_point + (unsigned long)((unsigned long)tl->current_set_tp * (unsigned long)tl->current_set_tp_rate) / 100;
            disp->points.total = tl->total_trick_point;
            disp->points.link_rate = tl->link_rate;
        }
        if (disp->points.single > 99999999) {
            disp->points.single = 99999999;
        }
        if (disp->points.total > 99999999) {
            disp->points.total = 99999999;
        }
    }
    fakie = act->fakie;
    if (tl->trick_link && act->trg_touch) {
        switch (tl->is_bonus_landing) {
            case elbPerfect:
                arg0 = 1;
                break;
            case elbSloppy:
                arg0 = 2;
                break;
            default:
                arg0 = 0;
                break;
        }
        nmtrickSetLand(rider->pid, arg0);
    }
    if (act->gr_grind_no >= 0) {
        if (act->trg_grind_name || tl->trg_end_link) {
            arg0 = act->gr_grind_no;
            if ((arg0 >= 0x54) && (arg0 < 0x84)) {
                arg1 = 8;
            } else {
                arg1 = 3;
            }
            nmtrickSetFakie(rider->pid, fakie);
            nmtrickSetTrick(rider->pid, arg1, arg0, act->disaster);
            act->gr_grind_no = -1;
            act->gr_cnt_kissed = 0;
        }
    }
    arg0 = tl->spenv_get_trick_no;
    arg0 = ktactGetChangedTrickNo(rc, arg0);
    if (arg0 >= 0) {
        jump = 0;
        grind = 0;
        disaster = 0;
        if (arg0 < 0x19) {
            arg1 = 1;
        } else if (arg0 < 0x31) {
            arg1 = 2;
        } else if (arg0 < 0x3E) {
            arg1 = 3;
            grind = 1;
        } else if (arg0 < 0x42) {
            arg1 = 1;
        } else if (arg0 < 0x4B) {
            arg1 = 5;
        } else if (arg0 < 0x4F) {
            arg1 = 4;
        } else if (arg0 < 0x51) {
            arg1 = 9;
        } else if (arg0 < 0x54) {
            arg1 = 9;
            jump = 1;
        } else if (arg0 < 0x84) {
            arg1 = 8;
            switch (arg0) {
                case 0x58:
                case 0x5C:
                case 0x5E:
                case 0x67:
                case 0x6B:
                    grind = 1;
                    break;
            }
        } else if (arg0 >= 0x86) {
            arg1 = 2;
        } else {
            arg1 = 3;
        }
        if (arg0 == 0x84) {
            disaster = act->disaster;
        }
        if (!grind) {
            if (jump) {
                nmtrickSetFakie(rider->pid, fakie);
                nmtrickSetJump(rider->pid, arg0);
            } else {
                nmtrickSetFakie(rider->pid, fakie);
                nmtrickSetTrick(rider->pid, arg1, arg0, disaster);
            }
        }
    }
    if (tl->trick_link && (act->num_set_gap > 0)) {
        for (i = 0; i < act->num_set_gap; i++) {
            arg0 = act->set_gap[i];
            nmtrickSetFakie(rider->pid, fakie);
            nmtrickSetTrick(rider->pid, 7, arg0, 0);
        }
    }
    if (tl->spin_ang) {
        arg0 = tl->pre_spin_ang;
        if (arg0 < 0) {
            arg0 = -arg0;
        }
        nmtrickSetFakie(rider->pid, fakie);
        nmtrickSetSpin(rider->pid, act->hp_air, act->trg_rewind, arg0);
    }
    if (tl->trick_link && !tl->added_airtime && tl->is_bonus_airtime) {
        nmtrickSetFlight(rider->pid, 1);
        tl->added_airtime = 1;
    }
    act->trk_link_state = elsNone;
    if (tl->trick_link) {
        success = 0;
        if (tl->trg_get_pts) {
            ktactAddSpecialTrickCharge(act);
        }
        act->trk_link_state = elsLinking;
        if (tl->trg_end_link) {
            if ((act->tumble_type != 2) && (act->tumble_type != 3) && (act->tumble_type != 4) && (act->tumble_type != 5)) {
                success = 1;
                act->trk_link_state = elsSuccess;
            } else {
                act->trk_link_state = elsFailure;
            }
            nmdispEndTrick(rider->pid, success);
            ktactInitTLink(tl);
        }
        if (success) {
            if ((vspModeData.flow_mode == 3) && (act->cnt_quit < 0) && tl->get_the_best) {
                nmtrickGetInfo(rider->pid, &vspDispResult[rider->pid].comb_info);
            }
            ktactAddBoostCharge(act);
        }
    }
    disp->bar.num = act->special_num;
    disp->bar.charge = act->special_charge;
    disp->bar.left = (act->special_left_time * 100) / act->special_total_time;
    if (act->boost) {
        disp->match.boost.num = act->boost_num;
        disp->match.boost.charge = act->boost_charge;
    }
    switch (act->sliding_state) {
        case essGrind:
            disp->balance.state = 2;
            disp->balance.per = act->gr_balance.balance / 0.34906578f;
            break;
        case essManual:
            disp->balance.state = 1;
            disp->balance.per = act->manu_balance.balance / 0.34906578f;
            break;
        default:
            disp->balance.state = 0;
            disp->balance.per = 0.0f;
            break;
    }
    ktactUpdateGap(act);
    rider->disp.disp_shadow = ktactCheckShadow(act, rider->disp.disp_shadow);
    if (act->trg_quit) {
        act->cnt_quit = 0;
    }
}

// ktact.c
float iktactGetLen(float* v) {
    float sum; // 0x1C(r29)
    sum = sceVu0InnerProduct(v, v);
    return isbcoreSqrtf(sum);
}

static signed int ktactSetPadCnt(Pad* pad, Ope* ope, signed int mirror) {
    signed int ana_lx0; // r16 $s0
    signed int ana_ly0; // r17 $s1
    unsigned short ana_pad; // r18 $s2
    unsigned short pad_left; // r20 $s4
    unsigned short pad_right; // r21 $s5

    pad->lh = 0;
    pad->lv = 0;
    pad->analog = 0;
    if (ope == 0) {
        pad->cnt = 0;
        return 0;
    }

    pad->cnt = ope->now.now;
    pad->lh = ope->now.left_h;
    pad->lv = ope->now.left_v;

    pad->analog = (ope->now.id == 4) ? 0 : 1;

    if (pad->analog) {
        ana_lx0 = pad->lh;
        ana_ly0 = pad->lv;

        if (ana_lx0 == -0x80) {
            ana_lx0++;
        }

        ana_lx0 = -ana_lx0;
        if ((ana_lx0 > -0x40) && (0x40 > ana_lx0)) {
            ana_lx0 = 0;
        } else if (ana_lx0 > 0) {
            ana_lx0 = ((ana_lx0 - 0x40) * 0x7f) / 0x3f;
        } else {
            ana_lx0 = ((-ana_lx0 - 0x40) * -0x7f) / 0x3f;
        }

        pad->lh = ana_lx0;
        if (ana_ly0 == -0x80) {
            ana_ly0++;
        }

        if ((ana_ly0 > -0x40) && (0x40 > ana_ly0)) {
            ana_ly0 = 0;
        } else if (ana_ly0 > 0) {
            ana_ly0 = ((ana_ly0 - 0x40) * 0x7f) / 0x3f;
        } else {
            ana_ly0 = ((-ana_ly0 - 0x40) * -0x7f) / 0x3f;
        }

        pad->lv = ana_ly0;
        ana_pad = 0;
        if (ana_lx0 > 0) {
            ana_pad |= 0x2000;
        }
        if (ana_lx0 < 0) {
            ana_pad |= 0x8000;
        }
        if (ana_ly0 > 0) {
            ana_pad |= 0x1000;
        }
        if (ana_ly0 < 0) {
            ana_pad |= 0x4000;
        }
        if (ana_pad != 0) {
            pad->cnt &= 0xfff;
            pad->cnt |= ana_pad;
        }
    }

    if (mirror != 0) {
        pad_left = pad->cnt & 0x8000;
        pad_right = pad->cnt & 0x2000;
        pad->lh = -pad->lh;
        pad->cnt &= 0x5fff;
        if (pad_left) {
            pad->cnt |= 0x2000;
        }
        if (pad_right) {
            pad->cnt |= 0x8000;
        }
    }

    return pad->analog;
}

static signed int ktactCheckCommand(Req* req /* 0x100(r29) */, Ctrl* rc /* 0x110(r29) */) {
    Act* act = &rc->act; // r18 // s2
    unsigned short pad = rc->nowpad.cnt; // r19 // s3
    unsigned short prepad = rc->prepad.cnt; // r20 // s4
    signed int mirror; // r21 // s5
    signed int no_mirror; // r30 // s8
    signed int onair = act->sliding_state == essOnAir ? 1 : 0; // 0xA8(r29)
    signed int ok; // r17 // s1
    signed int trick_way; // r22 // s6
    signed int flip_way; // r23 // s7
    signed int grind_way; // 0xAC(r29)
    signed int plant_way; // 0xB0(r29)
    signed int bonk_way; // 0xB4(r29)
    signed int manual_way; // 0xB8(r29)
    signed int revert_way; // 0xBC(r29)
    signed int trick; // 0xC0(r29)
    signed int flip; // 0xC4(r29)
    signed int grind; // 0xC8(r29)
    signed int plant; // 0xCC(r29)
    signed int bonk; // 0xD0(r29)
    signed int manual; // 0xD4(r29)
    signed int revert; // 0xD8(r29)
    signed int sptrk_id; // 0xDC(r29)
    signed int jump; // 0xE0(r29)
    signed int jump_pow; // 0xE4(r29)
    signed int i; // r16 // s0
    unsigned short btn; // 0xFE(r29)
    signed int late; // 0xE8(r29)

    ok = 0;
    // onair = act->sliding_state == essOnAir;
    // signed int onair = act->sliding_state == essOnAir ? 1 : 0; // 0xA8(r29)

    trick_way = -1;
    flip_way = -1;
    grind_way = -1; // should be AC but showing as s8 register?
    plant_way = -1;
    bonk_way = -1;
    manual_way = -1;
    revert_way = -1;
    trick = -1;
    flip = -1;
    grind = -1;
    plant = -1;
    bonk = -1;
    manual = -1;
    revert = -1;
    sptrk_id = -1;
    jump = -1;
    jump_pow = -1;

    mirror = act->goofy ? 1 : 0;
    no_mirror = rc->cheats->mirror ? 1 : 0;
    i = 4;
    ok = ktactCheckCmd(&act->cmd_grind[i], pad, prepad, 0, mirror, 0);
    if (ok) {
        grind_way = i;
    }
    ok = ktactCheckCmd(&act->cmd_plant[i], pad, prepad, 0, mirror, 0);
    if (ok) {
        plant_way = i;
    }
    ok = ktactCheckCmd(&act->cmd_bonk[i], pad, prepad, 0, mirror, 0);
    if (ok) {
        bonk_way = i;
    }
    for (i = 1; i < 9; i += 2) {
        ok = ktactCheckCmd(&act->cmd_trick[i], pad, prepad, 1, no_mirror, 0);
        if (ok) {
            trick_way = i;
        }
        ok = ktactCheckCmd(&act->cmd_flip[i], pad, prepad, 1, mirror, 0);
        if (ok) {
            flip_way = i;
        }
        ok = ktactCheckCmd(&act->cmd_grind[i], pad, prepad, 1, mirror, 0);
        if (ok) {
            grind_way = i;
        }
        ok = ktactCheckCmd(&act->cmd_plant[i], pad, prepad, 0, mirror, 0);
        if (ok) {
            plant_way = i;
        }
        ok = ktactCheckCmd(&act->cmd_bonk[i], pad, prepad, 0, mirror, 0);
        if (ok) {
            bonk_way = i;
        }
        ok = ktactCheckCmd(&act->cmd_manual[i], pad, prepad, 0, mirror, 0);
        if (ok) {
            manual_way = i;
        }
    }
    for (i = 0; i < 9; i += 2) {
        if (i != 4) {
            ok = ktactCheckCmd(&act->cmd_trick[i], pad, prepad, 1, no_mirror, 0);
            if (ok) {
                trick_way = i;
            }
            ok = ktactCheckCmd(&act->cmd_flip[i], pad, prepad, 1, mirror, 0);
            if (ok) {
                flip_way = i;
            }
            ok = ktactCheckCmd(&act->cmd_grind[i], pad, prepad, 1, mirror, 0);
            if (ok) {
                grind_way = i;
            }
            ok = ktactCheckCmd(&act->cmd_plant[i], pad, prepad, 0, mirror, 0);
            if (ok) {
                plant_way = i;
            }
        }
    }
    for (i = 9; i < 0x19; i++) {
        ok = ktactCheckCmd(&act->cmd_trick[i], pad, prepad, 1, no_mirror, 0);
        if (onair == 0 && (act->cmd_trick[i].passtime >= 5)) {
            ktactCommandReset(&act->cmd_trick[i]);
            ok = 0;
        }
        if (ok) {
            trick_way = i;
        }
        ok = ktactCheckCmd(&act->cmd_flip[i], pad, prepad, 1, mirror, 0);
        if (onair == 0 && (act->cmd_flip[i].passtime >= 5)) {
            ktactCommandReset(&act->cmd_flip[i]);
            ok = 0;
        }
        if (ok) {
            flip_way = i;
        }
        if (i < 0xD) {
            ok = ktactCheckCmd(&act->cmd_grind[i], pad, prepad, 1, mirror, 0);
            if (ok) {
                grind_way = i;
            }
        }
    }
    for (i = 0; i < 4; i++) {
        ok = ktactCheckCmd(&act->cmd_jump[i], pad, prepad, 0, mirror, 1);
        if (ok) {
            jump_pow = i;
        }
    }
    for (i = 0; i < 2; i++) {
        if (mirror) {
            btn = act->cmd_revert[i].fin_button;
            act->cmd_revert[i].fin_button = (btn & rc->key->stance) ? rc->key->revert : rc->key->stance; //(spF8 & 0xFFFF);
            ok = ktactCheckCmd(&act->cmd_revert[i], pad, prepad, 0, mirror, 0);
            act->cmd_revert[i].fin_button = btn;
        } else {
            ok = ktactCheckCmd(&act->cmd_revert[i], pad, prepad, 0, mirror, 0);
        }
        if (ok) {
            revert_way = i;
        }
    }
    if ((act->special_num > 0) || (act->special_left_time > 0)) {
        for (i = 0; i < 2; i++) {
            if (act->sptrk[i] == 0x69) {
                late = 0;
            } else {
                late = 1;
            }
            ok = ktactCheckCmd(&act->cmd_sptrk[i], pad, prepad, late, no_mirror, 0);
            if (ok) {
                sptrk_id = i;
                trick = -1;
                trick_way = -1;
                flip = -1;
                flip_way = -1;
            }
        }
    }

    if (trick_way >= 0) {
        trick = vktactCmdToGrab[trick_way];
        if (trick == 0xFF || trick == 0xFE) {
            trick = -1;
            trick_way = -1;
        }
    }
    if (flip_way >= 0) {
        flip = vktactCmdToFlip[flip_way];
        if (flip == 0xFF || flip == 0xFE) {
            flip = -1;
            flip_way = -1;
        }
    }
    if (grind_way >= 0) {
        grind = vktactCmdToGrind[grind_way];
        if (grind == 0xFF || grind == 0xFE) {
            grind = -1;
            grind_way = -1;
        }
    }
    if (plant_way >= 0) {
        plant = vktactCmdToPlant[plant_way];
        if (plant == 0xFF || plant == 0xFE) {
            plant = -1;
            plant_way = -1;
        }
        // switch (plant) {
        //     case 0xFE:
        //     case 0xFF:
        //         plant = -1;
        //         plant_way = -1;
        // }
    }
    if (bonk_way >= 0) {
        bonk = vktactCmdToBonk[bonk_way];
        if (bonk == 0xFF || bonk == 0xFE) {
            bonk = -1;
            bonk_way = -1;
        }
    }
    if (manual_way >= 0) {
        manual = vktactCmdToManual[manual_way];
        if (manual == 0xFF || manual == 0xFE) {
            manual = -1;
            manual_way = -1;
        }
    }
    if (revert_way >= 0) {
        revert = vktactCmdToRevert[revert_way];
        if (revert == 0xFF || revert == 0xFE) {
            revert = -1;
            revert_way = -1;
        }
    }
    if (jump_pow >= 0) {
        jump = vktactCmdToJump[jump_pow];
        if (jump == 0xFF || jump == 0xFE) {
            jump = -1;
            jump_pow = -1;
        }
    }
    req->trick_no = trick;
    req->flip_no = flip;
    req->grind_no = grind;
    req->plant_no = plant;
    req->bonk_no = bonk;
    req->manual_no = manual;
    req->jump = jump_pow + 1;
    req->sptrk_id = sptrk_id;
    req->revert_no = revert;
    req->jump_no = jump;
    return trick;
}

// ktact.c
static signed int ktactCheckCmd(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int late, signed int mirror, signed int jump) {
    signed int way[5]; // 0xA0(r29)
    signed int num_way; // 0xB4(r29)
    signed int way2; // 0xB8(r29)
    signed int way3; // 0xBC(r29)
    signed int i; // r16
    signed int num_maxstep; // r17
    signed int tmp; // r18
    signed int nowway; // r19
    signed int preway; // r20
    signed int way0; // r21
    signed int s; // r22
    signed int notcount; // r23
    signed int way1; // r30

    num_maxstep = 0;
    num_way = 0;
    notcount = 0;
    for (i = 0; i < 5; i++) {
        way[i] = -1;
    }
    if (cmd->way1 == 4) {
        num_maxstep = 1;
    } else {
        way0 = cmd->way1;
        way1 = cmd->way2;
        way2 = cmd->way3;
        way3 = cmd->way4;
        switch (cmd->type) {
            case 0:
                way[0] = way0;
                num_maxstep = 1;
                break;
            case 1:
            case 3:
                way[0] = way0;
                way[1] = way1;
                num_maxstep = 2;
                break;
            case 2:
                way[0] = way0;
                way[1] = 4;
                way[2] = way0;
                num_maxstep = 3;
                break;
            case 4:
            case 5:
                way[0] = way0;
                num_maxstep = 1;
                break;
            case 6:
                way[0] = way0;
                way[1] = way1;
                way[2] = way2;
                num_maxstep = 3;
                break;
        }
        num_way = num_maxstep;
        if (cmd->fin_button) {
            num_maxstep++;
        }
    }
    if (pad & 0x4000) {
        nowway = 1;
    } else if (pad & 0x1000) {
        nowway = 7;
    } else {
        nowway = 4;
    }
    if (pad & 0x8000) {
        nowway--;
    } else if (pad & 0x2000) {
        nowway++;
    }
    if (prepad & 0x4000) {
        preway = 1;
    } else if (prepad & 0x1000) {
        preway = 7;
    } else {
        preway = 4;
    }
    if (prepad & 0x8000) {
        preway--;
    } else if (prepad & 0x2000) {
        preway++;
    }
    if (mirror) {
        for (i = 0; i < num_maxstep; i++) {
            tmp = way[i] % 3;
            if (tmp == 0) {
                way[i] += 2;
            } else if (tmp == 2) {
                way[i] -= 2;
            }
        }
    }
    if (cmd->passtime < 0xFF) {
        cmd->passtime++;
    }
    if (cmd->ok) {
        ktactCommandReset(cmd);
    }
    if ((nowway != preway) || (cmd->type == 4) || (cmd->type == 5)) {
        if (nowway == way[cmd->step]) {
            if (cmd->step == 0) {
                cmd->left_count = 30;
            }
            cmd->step++;
            cmd->passtime = 0;
        }
    }
    if (cmd->type == 5) {
        s = cmd->step;
        if (cmd->fin_button && (s > 0) && (s == num_maxstep - 1)) {
            s--;
        }
        if (nowway == way[s]) {
            if (jump) {
                if (cmd->passtime > 5) {
                    cmd->passtime = 5;
                }
            } else {
                cmd->passtime = 0;
            }
            notcount = 1;
        }
    }
    if (jump) {
        ktactCheckCmd_3(cmd, pad, prepad, num_maxstep);
    } else if (late) {
        ktactCheckCmd_2(cmd, pad, prepad, num_maxstep);
    } else {
        ktactCheckCmd_1(cmd, pad, prepad, num_maxstep);
    }
    if (!cmd->ok) {
        if ((cmd->left_count > 0) && (notcount == 0)) {
            cmd->left_count--;
        }
        if (cmd->left_count == 0) {
            ktactCommandReset(cmd);
        }
    }
    return cmd->ok;
}

static void ktactCheckCmd_1(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int num_maxstep) {
    unsigned short padtrg;

    if (cmd->step == num_maxstep) {
        cmd->ok = 1;
        return;
    }
    if (cmd->fin_button && cmd->step == num_maxstep - 1) {
        if (cmd->rev_button) {
            padtrg = prepad & (pad ^ prepad);
        } else {
            padtrg = pad & (pad ^ prepad);
        }
        if (cmd->type == 4) {
            if (pad & cmd->fin_button) {
                cmd->step++;
                cmd->ok = 1;
            }
        } else if (padtrg & cmd->fin_button) {
            cmd->step++;
            cmd->ok = 1;
        }
    }
}

static void ktactCheckCmd_2(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int num_maxstep) {
    unsigned short padtrg;

    if (cmd->step == num_maxstep) {
        cmd->ok = 1;
        return;
    }
    if (cmd->fin_button) {
        if (cmd->step >= num_maxstep - 2 && !cmd->inp_fin_button) {
            if (cmd->rev_button) {
                padtrg = prepad & (pad ^ prepad);
            } else {
                padtrg = pad & (pad ^ prepad);
            }
            if (cmd->type == 4) {
                if (pad & cmd->fin_button) {
                    cmd->inp_fin_button = 1;
                    cmd->fin_left_count = 8;
                    cmd->left_count = cmd->fin_left_count;
                }
            } else if (padtrg & cmd->fin_button) {
                cmd->inp_fin_button = 1;
                cmd->fin_left_count = 8;
                cmd->left_count = cmd->fin_left_count;
            }
        }
        if (cmd->inp_fin_button && cmd->fin_left_count > 0) {
            cmd->fin_left_count--;
            if (cmd->fin_left_count == 0 && cmd->step >= num_maxstep - 1) {
                cmd->step = num_maxstep;
                cmd->ok = 1;
            }
        }
    }
}

static void ktactCheckCmd_3(Cmd* cmd, unsigned short pad, unsigned short prepad, signed int num_maxstep) {
    unsigned short padtrg;

    if (cmd->step == num_maxstep) {
        cmd->ok = 1;
        return;
    }
    if (cmd->fin_button && cmd->step == num_maxstep - 1) {
        if (cmd->rev_button) {
            padtrg = prepad & (pad ^ prepad);
        } else {
            padtrg = pad & (pad ^ prepad);
        }
        if ((padtrg & cmd->fin_button) && (cmd->passtime >= 5 || num_maxstep == 1)) {
            cmd->step++;
            cmd->ok = 1;
        }
    }
}

static void ktactSetRequest(Ctrl* rc) {
    Act* act; // r16
    Pos* nowpos; // r20
    Pos* prepos; // 0xC8(r29)
    Req* nowreq; // r17
    Pad* nowpad; // r21
    Pad* prepad; // r23
    unsigned short padinfo; // 0x11A(r29)
    unsigned short padpush; // 0x11C(r29)
    unsigned short padpop; // 0x11E(r29)
    signed int rfrom; // r18
    signed int rto; // 0xCC(r29)
    float ang; // 0xD0(r29)
    sceVu0FVECTOR v; // 0xA0(r29)
    sceVu0FVECTOR vv; // 0xB0(r29)
    signed int sptrk_no; // 0xD4(r29)
    signed int b; // r19
    signed int grab_no; // 0xD8(r29)
    signed int sp_grab; // 0xDC(r29)
    signed int flip_no; // 0xE0(r29)
    signed int sp_flip; // 0xE4(r29)
    signed int gid; // r30
    signed int fid; // 0xE8(r29)
    signed int spgrind; // 0xEC(r29)
    signed int spmanual; // 0xF0(r29)
    signed int spplant; // 0xF4(r29)
    signed int gr_lvl0; // 0xF8(r29)
    signed int gr_lvl1; // 0xFC(r29)
    signed int grindable; // r22
    float ang0; // 0x100(r29)
    float ang1; // 0x104(r29)

    act = &rc->act;
    nowpos = &rc->nowpos;
    prepos = &rc->prepos;
    nowreq = &rc->nowreq;
    nowpad = &rc->nowpad;
    prepad = &rc->prepad;
    padinfo = nowpad->cnt;
    padpush = (nowpad->cnt ^ prepad->cnt) & nowpad->cnt;
    padpop = (nowpad->cnt ^ prepad->cnt) & prepad->cnt;
    if (padpush & 0x1000) {
        nowreq->accel_brake = eraAccel;
    }
    if ((padinfo & 0x4000) && !(padinfo & 0x8000) && !(padinfo & 0x2000) && (act->side_slant > -0.785398f) && (act->side_slant < 0.785398f) &&
        (act->slant > -1.0471973f) && (act->slant < 1.0471973f)) {
        if (padpush & 0x4000) {
            act->cnt_brake = 0x78;
        } else if ((padpop & 0x8000) || (padpop & 0x2000)) {
            act->cnt_brake = 0x78;
        } else if (act->cnt_brake < 0x6C) {
            nowreq->accel_brake = eraBrake;
        }
    }
    if ((padinfo & 0x40) && (act->sliding_state != essRevert)) {
        nowreq->sitting = 1;
    }
    if (padpush & (rc->key->stance | rc->key->revert)) {
        if (act->goofy) {
            nowreq->stance_change = erscTurnRight;
        } else {
            nowreq->stance_change = erscTurnLeft;
        }
    }
    ktactCheckCommand(nowreq, rc);
    if (act->no_trick || (rc->mot.now.uad == 4)) {
        nowreq->trick_no = -1;
        nowreq->flip_no = -1;
        nowreq->grind_no = -1;
        nowreq->plant_no = -1;
        nowreq->bonk_no = -1;
        nowreq->manual_no = -1;
        nowreq->revert_no = -1;
        nowreq->sptrk_id = -1;
        if (act->no_trick) {
            nowreq->jump_no = -1;
            act->num_reserve_trick = 0;
        }
    }
    if (nowpos->hit) {
        if (0 <= nowreq->jump_no) {
            b = 0;
            if ((act->sliding_state == essSitting) || (act->sliding_state == essGrind) || (act->sliding_state == essManual) || (act->sliding_state == essRevert)) {
                b = 1;
            }
            if (b) {
                nowreq->command = ercJump;
                nowreq->cmd_mot_id = vktactTrkToMot[nowreq->jump_no];
                nowreq->cmd_mot_nloop = 0;
                nowreq->cmd_trick_no = nowreq->jump_no;
                nowreq->stance_change = erscNone;
            } else {
                nowreq->jump_no = -1;
            }
        }
        act->num_reserve_trick = 0;
        act->num_reserve_grab = 0;
    } else if (!act->mot_bonking) {
        grab_no = -1;
        sp_grab = 0;
        flip_no = -1;
        sp_flip = 0;
        if ((nowreq->trick_no >= 0) && (vktactTrkToMot[nowreq->trick_no] >= 0)) {
            grab_no = nowreq->trick_no;
        }
        if ((nowreq->sptrk_id >= 0) && (act->cmd_sptrk[nowreq->sptrk_id].fin_button & 0x20)) {
            grab_no = act->sptrk[nowreq->sptrk_id];
            sp_grab = 1;
        }
        if ((grab_no >= 0) && (act->num_reserve_trick < 16)) {
            gid = act->top_reserve_trick + act->num_reserve_trick;
            gid = gid % 16;
            act->reserve_trick_no[gid] = grab_no;
            act->reserve_trick_is_flip[gid] = 0;
            act->reserve_trick_is_special[gid] = sp_grab;
            act->num_reserve_trick++;
            act->num_reserve_grab++;
            ktactCommandResetAllForTrick(act);
        }
        if ((nowreq->flip_no >= 0) && (vktactTrkToMot[nowreq->flip_no] >= 0)) {
            flip_no = nowreq->flip_no;
        }
        if ((nowreq->sptrk_id >= 0) && (act->cmd_sptrk[nowreq->sptrk_id].fin_button & 0x80)) {
            flip_no = act->sptrk[nowreq->sptrk_id];
            sp_flip = 1;
        }
        if ((flip_no >= 0) && (act->num_reserve_trick < 16)) {
            fid = act->top_reserve_trick + act->num_reserve_trick;
            fid = fid % 16;
            act->reserve_trick_no[fid] = flip_no;
            act->reserve_trick_is_flip[fid] = 1;
            act->reserve_trick_is_special[fid] = sp_flip;
            act->num_reserve_trick++;
            ktactCommandResetAllForTrick(act);
        }
        if (act->no_trick) {
            act->num_reserve_trick = 0;
        }
        if (act->num_reserve_trick > 0) {
            if (!act->mot_grabing && !act->mot_spflipping && !act->reserve_trick_is_flip[act->top_reserve_trick]) {
                nowreq->trick_no = act->reserve_trick_no[act->top_reserve_trick];
                act->top_reserve_trick = (act->top_reserve_trick + 1) % 16;
                act->num_reserve_trick--;
                act->num_reserve_grab--;
                if (vktactTrkToMot[nowreq->trick_no] >= 0) {
                    nowreq->command = ercTrick;
                    nowreq->cmd_mot_id = vktactTrkToMot[nowreq->trick_no];
                    nowreq->cmd_mot_nloop = 0;
                    nowreq->cmd_trick_no = nowreq->trick_no;
                }
            }
            if (!act->mot_flipping && !act->mot_spflipping && act->reserve_trick_is_flip[act->top_reserve_trick]) {
                b = 0;
                if (!nowreq->command) {
                    if (!act->reserve_trick_is_special[act->top_reserve_trick]) {
                        b = 1;
                    } else if (!act->mot_grabing) {
                        b = 1;
                    }
                }
                if (b) {
                    nowreq->flip_no = act->reserve_trick_no[act->top_reserve_trick];
                    act->top_reserve_trick = (act->top_reserve_trick + 1) % 16;
                    act->num_reserve_trick--;
                    if (vktactTrkToMot[nowreq->flip_no] >= 0) {
                        nowreq->command = ercFlip;
                        nowreq->cmd_mot_id = vktactTrkToMot[nowreq->flip_no];
                        nowreq->cmd_trick_no = nowreq->flip_no;
                        nowreq->cmd_mot_nloop = 0;
                    }
                }
            }
        }
    }
    if (nowreq->sptrk_id >= 0) {
        spgrind = 0;
        spmanual = 0;
        spplant = 0;
        sptrk_no = act->sptrk[nowreq->sptrk_id];
        if ((act->cmd_sptrk[nowreq->sptrk_id].fin_button & 0x10) && !act->mot_grabing && !act->mot_spflipping) {
            switch (sptrk_no) {
                case 0x55:
                case 0x68:
                    spmanual = 1;
                    break;
                case 0x69:
                    spplant = 1;
                    break;
                default:
                    spgrind = 1;
                    break;
            }
        }
        if (spgrind) {
            nowreq->grind_no = sptrk_no;
        } else if (spmanual) {
            nowreq->manual_no = sptrk_no;
        } else if (spplant) {
            nowreq->plant_no = sptrk_no;
        }
    }
    if (0 <= nowreq->manual_no) {
        act->manual_ready = 1;
        act->manual_ready_no = nowreq->manual_no;
        if ((act->sliding_state == essOnAir) || (act->sliding_state == essRevert)) {
            act->manual_cnt_to_play = 0;
        } else {
            act->manual_cnt_to_play = 15;
        }
        if ((act->manual_ready_no == 0x4E) || (act->manual_ready_no == 0x4D)) {
            act->cnt_nospin = 15;
        }
    }
    if ((act->reserve_quit || (act->cnt_quit >= 0)) && !act->allow_tlink) {
        act->manual_ready = 0;
    }
    if (((act->cnt_quit >= 0) || (act->reserve_quit && ((act->sliding_state == essSliding) || (act->sliding_state == essSitting)))) && !act->trick_link.trick_link &&
        act->manual_ready) {
        act->manual_ready = 0;
    }
    if (act->manual_ready && nowpos->hit && !act->mot_reverting && !act->pre_hp_air && !act->manual_cnt_to_play) {
        nowreq->command = ercManual;
        nowreq->cmd_mot_id = vktactTrkToMot[act->manual_ready_no];
        nowreq->cmd_mot_nloop = -1;
        act->manual_ready = 0;
    }
    if ((act->sliding_state == essOnAir) && (nowreq->bonk_no >= 0)) {
        act->bonk_ready = 1;
        act->bonk_ready_no = nowreq->bonk_no;
        act->bonk_goto = 0;
    }
    if (act->bonk_ready && !act->bonk_goto) {
        act->bonk_goto = ktactGetHit_bonk(nowpos->pos, rc->speed, act->bonk_point);
        *(__int128*)act->bonk_presp = *(__int128*)rc->speed;
    }
    if (act->trg_bonk) {
        nowreq->command = ercBonk;
        nowreq->cmd_mot_id = vktactTrkToMot[act->bonk_ready_no];
        nowreq->cmd_mot_nloop = 0;
    }
    if ((act->sliding_state == essGrind) && !act->changed_grind && (act->cnt_real_grind < 10)) {
        b = 0;
        if ((nowreq->grind_no >= 0) && (vktactTrkToMot[nowreq->grind_no] >= 0) && (nowreq->grind_no != act->trk_trick_no)) {
            if (nowreq->grind_no < 0x3A) {
                gr_lvl0 = 0;
            } else if (nowreq->grind_no < 0x3E) {
                gr_lvl0 = 1;
            } else {
                gr_lvl0 = 2;
            }
            if (act->trk_trick_no < 0x3A) {
                gr_lvl1 = 0;
            } else if (act->trk_trick_no < 0x3E) {
                gr_lvl1 = 1;
            } else {
                gr_lvl1 = 2;
            }
            if (gr_lvl0 >= gr_lvl1) {
                b = 1;
            }
        }
        if (b) {
            nowreq->command = ercGrind;
            nowreq->cmd_mot_id = vktactTrkToMot[nowreq->grind_no];
            nowreq->cmd_mot_nloop = -1;
            act->trg_change_grind = 1;
            act->changed_grind = 1;
        }
    } else if (!act->mot_grabing && !act->mot_flipping && !act->mot_spflipping && act->allow_tlink && act->col_rail.vertex && (act->col_rail.attr & 0x2000)) {
        grindable = 0;
        if ((nowreq->grind_no >= 0) && (vktactTrkToMot[nowreq->grind_no] >= 0)) {
            switch (act->sliding_state) {
                case essSliding:
                case essSitting:
                    if (!act->cnt_plant2grind) {
                        grindable = 1;
                    }
                    break;
                case essManual:
                    grindable = 1;
                    break;
                case essOnAir:
                    if (!act->cnt_plant2grind) {
                        if ((act->pre_rail_list != act->col_rail.vertex) || (act->cnt_onair >= 0x1F)) {
                            grindable = 1;
                        }
                    }
                    if (act->trg_bonk) {
                        grindable = 0;
                    }
                    break;
            }
        }
        if (grindable) {
            rfrom = act->col_rail.no;
            rto = (rfrom < act->col_rail.nvertex - 1) ? rfrom + 1 : rfrom - 1;
            sceVu0SubVector(v, act->col_rail.vertex[rto], act->col_rail.vertex[rfrom]);
            sceVu0SubVector(vv, nowpos->pos, prepos->pos);
            ang0 = atan2f(v[0], v[2]);
            ang1 = atan2f(vv[0], vv[2]);
            ang = ang0 - ang1;
            ang = (ang < -3.141592f) ? (6.283184f + ang) : ((ang > 3.141592f) ? (ang - 6.283184f) : ang);
            if (ang < -1.570796f) {
                ang = ang + 3.141592f;
            } else if (ang > 1.570796f) {
                ang = ang - 3.141592f;
            }
            if ((ang > -1.2217302f) && (ang < 1.2217302f)) {
                nowreq->command = ercGrind;
                nowreq->cmd_mot_id = vktactTrkToMot[nowreq->grind_no];
                nowreq->cmd_mot_nloop = -1;
                act->gr_enter_ang = ang;
            }
        }
    }
    if (!act->mot_grabing && !act->mot_flipping && !act->mot_spflipping && prepos->halfpipe && act->col_plant.vertex && (rc->speed[1] < 0.0f) && act->allow_tlink) {
        rfrom = act->col_plant.no;
        rto = (rfrom < act->col_plant.nvertex - 1) ? rfrom + 1 : rfrom - 1;
        sceVu0SubVector(v, act->col_plant.vertex[rto], act->col_plant.vertex[rfrom]);
        sceVu0SubVector(vv, nowpos->pos, prepos->pos);
        v[1] = 0.0f;
        ang = sbcoreGetInnerAngle90(v, vv);
        if (ang > 1.2217302f) {
            if (!act->sliding_state || (act->sliding_state == essManual) || ((act->sliding_state == essOnAir) && act->hp_jump)) {
                if ((nowreq->plant_no >= 0) && (vktactTrkToMot[nowreq->plant_no] >= 0)) {
                    nowreq->command = ercPlant;
                    nowreq->cmd_mot_id = vktactTrkToMot[nowreq->plant_no];
                    nowreq->cmd_mot_nloop = 0;
                    switch (nowreq->plant_no) {
                        case 0x43:
                            act->plant_to_fakie = 1;
                            break;
                        default:
                            act->plant_to_fakie = 0;
                            break;
                    }
                }
            }
        }
    }
    if (act->sliding_state == essPlant) {
        if (nowreq->revert_no >= 0) {
            act->revert_cnt_ready = 60;
            act->revert_ready_no = nowreq->revert_no;
        }
    } else if (act->halfpiping && (act->sliding_state == essOnAir) && (nowreq->revert_no >= 0)) {
        act->revert_cnt_ready = 30;
        act->revert_ready_no = nowreq->revert_no;
        act->manual_ready = 0;
    }
    if ((act->revert_cnt_ready > 0) && nowpos->hit && !act->mot_planting && act->allow_tlink) {
        nowreq->command = ercRevert;
        nowreq->cmd_mot_id = vktactTrkToMot[act->revert_ready_no];
        nowreq->cmd_mot_nloop = 0;
        act->revert_cnt_ready = 0;
    }
    if (rc->mot.now.cannot_control) {
        ktactInitRequest(nowreq);
    }
}

static void ktactSetSlidingState( // Size: 0x2C00, DWARF: 0x7627B
    Ctrl* rc) {
    Act* act; // r16 // s0
    Req* req; // r17 // s1
    Sliding_State pre_state; // r19 // s3
    signed int command; // r20 // s4
    Jump_Strength j; // r21 // s5
    Pos* pre; // r22 // s6
    Pos* now; // r18 // s2
    signed int grind_no; // r23 // s7
    Sbcore* cd; // r30 // s8 // showing as a4
    Sliding_State pre_pre_state; // r29+0xA0
    Acceleration_Brake tumble_accel; // r29+0xA4
    signed int trick_no; // r29+0xA8
    signed int flip_no; // r29+0xAC
    signed int plant_no; // r29+0xB0
    signed int manual_no; // r29+0xB4
    signed int bonk_no; // r29+0xB8
    signed int revert_no; // r29+0xBC
    signed int jump_no; // r29+0xC0
    signed int kkk; // r29+0xC4
    act = &rc->act;
    cd = &act->sbcore;
    pre = &rc->prepos;
    now = &rc->nowpos;
    req = &rc->nowreq;
    pre_state = act->sliding_state;
    pre_pre_state = act->pre_state;
    tumble_accel = eraNone;
    trick_no = req->trick_no;
    flip_no = req->flip_no;
    grind_no = req->grind_no;
    plant_no = req->plant_no;
    manual_no = req->manual_no;
    bonk_no = req->bonk_no;
    revert_no = req->revert_no;
    jump_no = req->jump_no;
    command = req->command;
    act->pre_state = pre_state;
    if ((act->mot_tumbling) || (act->trg_tumble_type)) {
        if (pre_state == essGrind) {
            if (act->trg_tumble_way == etwLeft) {
                tumble_accel = eraAccelLeft;
            } else {
                tumble_accel = eraAccelRight;
            }
        }
        if (pre_state != essTumble) {
            act->mot_tumble_standup_already = 0;
        }
        act->sliding_state = essTumble;
        pre_state = act->sliding_state;
    }
    if (pre_state == essRevert && act->mot_reverting == 0) {
        pre_state = essSliding;
    }
    switch (pre_state) {
        case essTumble:
            ktactInitRequest(req);
            req->accel_brake = tumble_accel;
            if (act->cnt_fall > 0) {
                act->cnt_fall--;
                if (act->cnt_fall == 0) {
                    act->recover = 1;
                    act->sliding_state = essSliding;
                    act->tumble_type = ettNormal;
                    act->tumble_way = etwLeft;
                    act->trg_tumble_type = ettNormal;
                    act->trg_tumble_way = etwLeft;
                    act->mot_reserve_tumble_standup = 0;
                    act->mot_tumble_standup_already = 0;
                    req->end_fall = 1;
                }
            }
            if (act->mot_end_tumble) {
                act->sliding_state = essSliding;
                act->tumble_type = ettNormal;
                act->tumble_way = etwLeft;
                act->mot_reserve_tumble_standup = 0;
                act->mot_tumble_standup_already = 0;
            }
            break;
        case essManual:
            if (command == 3) {
                if (act->cnt_total_grind) {
                    if (act->gr_balance.lean_dir > 0.0f) {
                        if (act->gr_balance.lean_dir < (0.1f * vktactParamBal_lean_start_dir)) {
                            act->gr_balance.lean_dir = (0.1f * vktactParamBal_lean_start_dir);
                        }
                    } else if (act->gr_balance.lean_dir > -(0.1f * vktactParamBal_lean_start_dir)) {
                        act->gr_balance.lean_dir = -(0.1f * vktactParamBal_lean_start_dir);
                    }
                } else if (act->gr_enter_ang < 0.0f) {
                    act->gr_balance.lean_dir = (0.1f * vktactParamBal_lean_start_dir);
                } else {
                    act->gr_balance.lean_dir = -(0.1f * vktactParamBal_lean_start_dir);
                }
                req->trick_no = -1;
                req->flip_no = -1;
                req->grind_no = -1;
                req->plant_no = -1;
                req->revert_no = -1;
                req->jump_no = -1;
                ktactSetSS_grind(rc, grind_no);
            } else {
                j = req->jump;
                ktactInitRequest(req);
                req->jump = j;
                if (command == 8) {
                    req->command = command;
                    req->jump_no = jump_no;
                    req->cmd_mot_id = vktactTrkToMot[req->jump_no];
                    req->cmd_mot_nloop = 0;
                    req->cmd_trick_no = req->jump_no;
                }
                if (act->end_manual) {
                    if ((now->material & 0x7FF) == 8) {
                        act->sliding_state = essOnAir;
                    } else {
                        act->sliding_state = essSliding;
                    }
                } else if (now->hit == 0) {
                    act->sliding_state = essOnAir;
                } else if (req->jump) {
                    act->sliding_state = essStandUp;
                }
            }
            break;
        case essGrind:
            j = req->jump;
            ktactInitRequest(req);
            req->jump = j;
            if (command == 8) {
                req->command = command;
                req->jump_no = jump_no;
                req->cmd_mot_id = vktactTrkToMot[req->jump_no];
                req->cmd_mot_nloop = 0;
                req->cmd_trick_no = req->jump_no;
            }
            if (command == 3) {
                req->command = command;
                req->grind_no = grind_no;
                req->cmd_mot_id = vktactTrkToMot[grind_no];
                req->cmd_mot_nloop = -1;
            }
            if (act->col_rail.vertex[0] == 0 || act->end_grind) {
                act->rail_list = 0;
                act->num_rail_vertex = 0;
                act->rail_id = -1;
                act->sliding_state = essOnAir;
                act->trg_hopup = 1;
                now->hit = 0;
            } else if (req->jump) {
                act->sliding_state = essStandUp;
            }
            break;
        case essPlant:
            act->cnt_plant2grind = 30;
            if (act->mot_planting == 0) {
                act->rail_list = 0;
                act->num_rail_vertex = 0;
                act->rail_id = -1;
                act->sliding_state = essSliding;
                if (act->plant_air) {
                    act->sliding_state = essOnAir;
                }
            }
            // if (req->command != ercRevert) {
            //     ktactInitRequest(req);
            // } else {
            //     act->sliding_state = essRevert;
            // }
            switch (req->command) {
                case ercRevert:
                    act->sliding_state = essRevert;
                    break;
                default:
                    ktactInitRequest(req);
                    break;
            }
            break;
        case essRevert:
            j = req->jump;
            ktactInitRequest(req);
            req->jump = j;
            if (command == 8) {
                req->command = command;
                req->jump_no = jump_no;
                req->cmd_mot_id = vktactTrkToMot[req->jump_no];
                req->cmd_mot_nloop = 0;
                req->cmd_trick_no = req->jump_no;
            }
            if (req->jump) {
                act->sliding_state = essStandUp;
            }
            break;
        case essSitting:
        case essStandUp:
            if (req->accel_brake != eraBrake) {
                req->accel_brake = eraNone;
            }
            if (req->command != ercJump && req->command != ercGrind) {
                req->command = ercNone;
            }
            if (req->accel_brake == eraBrake || req->stance_change) {
                act->sliding_state = essSliding;
                // goto block_70;
                break;
            }
            if (req->command == ercGrind || now->hit != 0) {
                break;
            }
            // 🤔
            // if (req->command == ercGrind || now->hit == 0) {
            //     break;
            // }
        case essOnAir:
            // block_70:
            if (act->sliding_state != essSliding) {
                req->accel_brake = eraNone;
                req->stance_change = erscNone;
            }
            req->sitting = 0;
            req->jump = erjNone;
        default:
            if (act->cnt_total_grind) {
                if (act->gr_balance.lean_dir > 0.0f) {
                    if (act->gr_balance.lean_dir < (0.1f * vktactParamBal_lean_start_dir)) {
                        act->gr_balance.lean_dir = (0.1f * vktactParamBal_lean_start_dir);
                    }
                } else if ((act->gr_balance.lean_dir > -(0.1f * vktactParamBal_lean_start_dir))) {
                    act->gr_balance.lean_dir = -(0.1f * vktactParamBal_lean_start_dir);
                }
            } else if (act->gr_enter_ang < 0.0f) {
                act->gr_balance.lean_dir = (0.1f * vktactParamBal_lean_start_dir);
            } else {
                act->gr_balance.lean_dir = -(0.1f * vktactParamBal_lean_start_dir);
            }
            req->trick_no = -1;
            req->flip_no = -1;
            req->grind_no = -1;
            req->plant_no = -1;
            req->revert_no = -1;
            req->jump_no = -1;
            if (req->accel_brake == eraBrake) {
                if (req->command == ercJump) {
                    req->command = ercNone;
                }
                req->jump = erjNone;
                req->sitting = 0;
            }

            switch (req->command) {
                case ercGrind:
                    ktactSetSS_grind(rc, grind_no);
                    break;
                case ercPlant:
                    act->sliding_state = essPlant;
                    act->rail_id = act->col_plant.rail_no;
                    act->cnt_plant = 0;
                    req->plant_no = plant_no;
                    act->plant_air = act->pre_state == essOnAir ? essSitting : essSliding;
                    if ((act->cnt_onair < 10) && (now->pos[1] < act->col_plant.point[1])) {
                        act->halfpiping = 0;
                        act->plant_air = 0;
                    } else if (now->pos[1] < act->col_plant.point[1]) {
                        kkk = 0;
                    }
                    break;
                case ercManual:
                    act->sliding_state = essManual;
                    act->cnt_manual = 0;
                    ktactResetBalance(&act->manu_balance, act->manu_reset_lean, 0x14);
                    act->manu_reset_lean = 0;
                    act->gr_reset_lean = 1;
                    rc->disp_rot_foot = 0.0f;
                    rc->disp_rot_foot_is_x = 1;
                    req->manual_no = manual_no;
                    req->sitting = 0;
                    break;
                case ercRevert:
                    act->sliding_state = essRevert;
                    req->revert_no = revert_no;
                    break;
                case ercFlip:
                    act->sliding_state = now->hit ? 0 : 3;
                    req->flip_no = flip_no;
                    break;
                case ercTrick:
                    act->sliding_state = now->hit ? 0 : 3;
                    req->trick_no = trick_no;
                    break;
                case ercBonk:
                    act->sliding_state = now->hit ? 0 : 3;
                    req->bonk_no = bonk_no;
                    break;
                default:
                    if (cd->plane_hit.available && cd->plane_hit.attribute == 0) {
                        act->sliding_state = essSliding;
                    } else {
                        act->sliding_state = now->hit ? 0 : 3;
                    }
                    break;
            }
    }

    if (req->sitting) {
        if (pre_state == essSliding || pre_state == essSitting) {
            act->sliding_state = essSitting;
        }
    } else if (pre_state == essSitting && act->sliding_state == essSitting) {
        grind_no = essStandUp;
        act->sliding_state = grind_no;
    }
    if (act->pre_state == essOnAir && act->sliding_state != essOnAir) {
        if (act->trg_tumble_body) {
            if (pre->hit == 0 && now->hit) {
                act->trg_touch = 1;
            }
        } else {
            act->trg_touch = 1;
        }
    } else if (act->pre_state != essOnAir && act->sliding_state == essOnAir && act->plant_air == 0) {
        if (act->jump_air) {
            act->trg_jumpup = 1;
            act->grind_jump = pre_pre_state == essGrind ? essSitting : essSliding;
        } else {
            act->trg_hopup = 1;
            act->grind_jump = 0;
        }
        act->jump_rot_pole = rc->rot_pole;
        act->last_rot_pole = rc->rot_pole;
        act->last_spin_way = 0;
        if (act->grind_jump || act->pre_state == essGrind) {
            if (act->trg_jumpup || act->hips) {
                act->hp_jump = 0;
            } else {
                act->hp_jump = now->halfpipe;
            }
        } else {
            act->hp_jump = pre->halfpipe;
        }
        act->hp_adj_roty = act->hp_jump;
        if (act->hp_adj_roty == 0) {
            act->hp_adj_roty = act->halfpiping;
        }
    } else if (act->pre_state == essTumble && act->sliding_state == essTumble && pre->hit == 0 && now->hit) {
        act->trg_touch = 1;
    }
}

static void ktactSetSS_grind(Ctrl* rc, signed int grind_no) {
    Act* act = &rc->act;
    Pos* now = &rc->nowpos;
    Req* req = &rc->nowreq;
    float lean_dir;

    act->sliding_state = essGrind;
    act->rail_list = act->col_rail.vertex;
    act->num_rail_vertex = act->col_rail.nvertex;
    act->rail_id = act->col_rail.rail_no;
    act->rail_no = act->col_rail.no;
    *(__int128*)act->rail_pos = *(__int128*)act->col_rail.point;
    act->cnt_to_rail = 6;
    act->cnt_grind = 0;
    act->gr_is_reverse = 0;
    lean_dir = act->gr_balance.lean_dir;
    ktactResetBalance(&act->gr_balance, act->gr_reset_lean, 0x14);
    lean_dir *= 0.25f;
    if (!(lean_dir <= 0.0f)) {
        if (lean_dir < 0.1f * (float)vktactParamBal_lean_start_dir) {
            lean_dir = 0.1f * (float)vktactParamBal_lean_start_dir;
        }
    } else if (!(lean_dir <= -(0.1f * (float)vktactParamBal_lean_start_dir))) {
        lean_dir = -(0.1f * (float)vktactParamBal_lean_start_dir);
    }
    if (!((act->gr_balance.lean * lean_dir) < 0.0f)) {
    }
    act->gr_balance.lean_dir = lean_dir;
    act->gr_reset_lean = 0;
    act->manu_reset_lean = 1;
    act->trg_touch = 1;
    rc->disp_rot_foot = 0.0f;
    rc->disp_rot_foot_is_x = 0;
    req->grind_no = grind_no;
    now->material = act->col_rail.attr & 0x7FF;
    if (rc->splen < 11.111111f) {
        rc->splen = 11.111111f;
        sceVu0Normalize(rc->speed, rc->speed);
        sceVu0ScaleVector(rc->speed, rc->speed, rc->splen);
        rc->speed[3] = 1.0f;
    }
}

static void ktactSetInput0(Ctrl* rc) {
    Act* act = &rc->act;
    Inp* nowinp = &rc->nowinp;
    Inp* preinp = &rc->preinp;
    Pad* nowpad = &rc->nowpad;
    signed int analog = nowpad->analog;
    signed int cnt_turn = rc->act.cnt_turn;
    signed int val_return;
    signed int turn = 0;
    signed int turn_x = 0;
    Key_Way keyway = 0;
    signed int quick_turn = 0;

    val_return = iktactMakeParam_return(act->param.quickness);
    if (nowpad->lh == 0 && nowpad->lv == 0) {
        analog = 0;
    }
    if (nowpad->cnt & 0x8000) {
        keyway = 1;
        if (nowpad->cnt & 0x4000) {
            quick_turn = 1;
        }
    } else if (nowpad->cnt & 0x2000) {
        keyway = 2;
        if (nowpad->cnt & 0x4000) {
            quick_turn = 1;
        }
    }
    if (analog != 0) {
        turn = nowpad->lh;
    } else {
        cnt_turn = (cnt_turn * 60) / 10;
        if (cnt_turn < 0) {
            cnt_turn = -cnt_turn;
        }
        cnt_turn = cnt_turn + 1;
        if (cnt_turn > 0x7F) {
            cnt_turn = 0x7F;
        }
        if (nowpad->cnt & 0x2000) {
            turn = cnt_turn;
        } else if (nowpad->cnt & 0x8000) {
            turn = -cnt_turn;
        }
    }
    turn = turn * 10;
    if (analog != 0) {
        turn_x = nowpad->lv;
    } else if (nowpad->cnt & 0x1000) {
        turn_x = 0x60;
    } else if (nowpad->cnt & 0x4000) {
        turn_x = -0x60;
    }
    turn_x = turn_x * 10;
    if (rc->mot.now.cannot_control != 0) {
        turn = 0;
        turn_x = 0;
    } else {
        if (act->sliding_state != essSliding && act->sliding_state != essSitting && act->sliding_state != essManual) {
            turn = 0;
        }
        if (act->sliding_state != essOnAir) {
            turn_x = 0;
        } else if (act->mot_grabing != 0 || act->mot_flipping != 0 || act->mot_spflipping != 0) {
            turn_x = 0;
        }
    }
    nowinp->turn = turn;
    nowinp->turn_x = turn_x;
    nowinp->quick_turn = quick_turn;
    nowinp->keyway = keyway;
}

signed int iktactMakeParam_return(signed int src) {
    signed int param; // r16 $s0
    signed int min_ret_rate; // r18 $s2
    signed int max_ret_rate; // r19 $s3
    signed int cmn_ret_rate; // r17 $s1

    cmn_ret_rate = vktactParamCmnRetRate;
    min_ret_rate = vktactParamMinRetRate;
    max_ret_rate = vktactParamMaxRetRate;
    param = cmn_ret_rate;

    if (src >= 0x32) {
        param += ((src - 0x32) * (max_ret_rate - cmn_ret_rate)) / 50;
    } else {
        param += ((0x32 - src) * (min_ret_rate - cmn_ret_rate)) / 40;
    }
    return param;
}

static signed int ktactSetInput1(Ctrl* rc) {
    Act* act; // r16
    Mot* mot; // 0x110(r29)
    Req* req; // r17
    Pos* nowpos; // 0x114(r29)
    Inp* nowinp; // r20
    Pad* nowpad; // r18
    Pad* prepad; // 0x118(r29)
    unsigned short padpush; // 0x1BE(r29)
    signed int analog; // 0x11C(r29)
    Acceleration_State accel_state; // r21
    Jump_State jump_state; // 0x120(r29)
    Stance_Change stance_change; // 0x124(r29)
    ESP_Spin_Way spin_way; // r30
    Trick_Command command; // r22
    signed int cmd_mot_id; // r19
    signed int cmd_mot_nloop; // 0x128(r29)
    signed int cmd_trick_no; // 0x12C(r29)

    act = &rc->act;
    mot = &rc->mot;
    req = &rc->nowreq;
    nowpos = &rc->nowpos;
    nowinp = &rc->nowinp;
    nowpad = &rc->nowpad;
    prepad = &rc->prepad;
    padpush = (nowpad->cnt ^ prepad->cnt) & nowpad->cnt;
    analog = nowpad->analog;
    accel_state = nowinp->accel_state;
    jump_state = nowpos->hit ? ejsSliding : ejsOnAir;
    stance_change = escNoAction;
    spin_way = espNoSpin;
    command = ecmdNone;
    cmd_mot_id = -1;
    cmd_mot_nloop = 0;
    cmd_trick_no = -1;
    switch (act->sliding_state) {
        case essTumble:
            if (padpush) {
                nowinp->tumble_speed_up = 1;
            }
            break;
        case essRevert:
            if (req->command == ercRevert) {
                command = ecmdRevert;
                cmd_mot_id = req->cmd_mot_id;
                cmd_mot_nloop = req->cmd_mot_nloop;
            }
            break;
        case essManual: {
            signed int a; // 0x130(r29)
            signed int b; // 0x134(r29)

            if (req->command == ercManual) {
                command = ecmdManual;
                cmd_mot_id = req->cmd_mot_id;
                cmd_mot_nloop = req->cmd_mot_nloop;
            }
            a = (nowpad->cnt & 0x1000) ? 1 : 0;
            b = (nowpad->cnt & 0x4000) ? 1 : 0;
            if (!(nowpad->cnt & 0x5000)) {
                act->manu_balance.released = 1;
            }
            if (act->cnt_warp) {
                break;
            }
            ktactUpdateBalance(&act->manu_balance, act, a, b, act->cnt_total_manual);
            if (rc->cheats->perfect_b) {
                act->manu_balance.balance = 0.0f;
            }
            break;
        }
        case essPlant:
            if (req->command == ercPlant) {
                command = ecmdPlant;
                cmd_mot_id = req->cmd_mot_id;
                cmd_mot_nloop = req->cmd_mot_nloop;
            }
            nowinp->stop_speed = 1;
            if (nowpad->cnt & 0x10) {
                act->trick_keep = 1;
            } else {
                act->trick_keep = 0;
            }
            break;
        case essGrind: {
            signed int a; // 0x138(r29)
            signed int b; // 0x13C(r29)

            if (req->command == ercGrind) {
                command = ecmdGrind;
                cmd_mot_id = req->cmd_mot_id;
                cmd_mot_nloop = req->cmd_mot_nloop;
            }
            a = (nowpad->cnt & 0x8000) ? 1 : 0;
            b = (nowpad->cnt & 0x2000) ? 1 : 0;
            if (!act->first_grind || (act->cnt_total_grind >= vktactParamBal_start_input)) {
                act->gr_balance.released = 1;
            }
            if (!(nowpad->cnt & 0xA000) && !act->gr_cnt_kissed && (act->cnt_total_grind > 0)) {
                act->gr_balance.released = 1;
            }
            ktactUpdateBalance(&act->gr_balance, act, a, b, act->cnt_total_grind);
            if (rc->cheats->perfect_b) {
                act->gr_balance.balance = 0.0f;
            }
            break;
        }
        case essSitting:
            jump_state = ejsSitting;
            break;
        case essStandUp:
            if (req->jump) {
                act->nollie = 0;
                act->big_ollie = (req->jump == 2) ? 1 : 0;
                act->super_ollie = (req->jump == 3) ? 1 : 0;
                jump_state = req->jump + 3;
                act->rail_list = 0;
                act->num_rail_vertex = 0;
                act->rail_id = -1;
            }
            break;
        case essOnAir: {
            signed int spin_l; // 0x140(r29)
            signed int spin_r; // 0x144(r29)
            signed int nospin; // 0x148(r29)

            if (act->mot_flipping || act->mot_spflipping || act->mot_bonking) {
                act->cnt_spinkey = 0;
            } else if ((mot->now.id == 0x3B) || (mot->now.id == 0x53)) {
                act->cnt_spinkey = 0;
            } else if (act->no_trick) {
                act->cnt_spinkey = 0;
            } else {
                spin_l = rc->key->spin_l;
                spin_r = rc->key->spin_r;
                nospin = 0;
                if (rc->cheats->mirror) {
                    spin_l = rc->key->spin_r;
                    spin_r = rc->key->spin_l;
                }
                if ((nowpad->cnt & spin_l) && (nowpad->cnt & spin_r)) {
                    nospin = 1;
                } else if ((nowpad->cnt & 0x8000) && (nowpad->cnt & spin_l)) {
                    spin_way = espTurnLeftFast;
                } else if ((nowpad->cnt & 0x2000) && (nowpad->cnt & spin_r)) {
                    spin_way = espTurnRightFast;
                } else if (nowpad->cnt & spin_l) {
                    spin_way = espTurnLeft;
                    spin_way = espTurnLeftFast;
                } else if (nowpad->cnt & spin_r) {
                    spin_way = espTurnRight;
                    spin_way = espTurnRightFast;
                } else if (nowpad->cnt & 0x8000) {
                    spin_way = espTurnLeft;
                    spin_way = espTurnLeftFast;
                } else if (nowpad->cnt & 0x2000) {
                    spin_way = espTurnRight;
                    spin_way = espTurnRightFast;
                }
                switch (spin_way) {
                    case espTurnLeftFast:
                    case espTurnLeft:
                        if (act->cnt_spinkey > 0) {
                            act->cnt_spinkey = 0;
                        }
                        act->cnt_spinkey--;
                        break;
                    case espTurnRightFast:
                    case espTurnRight:
                        if (act->cnt_spinkey < 0) {
                            act->cnt_spinkey = 0;
                        }
                        act->cnt_spinkey++;
                        break;
                    default:
                        act->cnt_spinkey = 0;
                        break;
                }
                if (!nospin && (nowpad->cnt & (spin_l | spin_r))) {
                    if (!act->cnt_nospin) {
                        act->cnt_spinkey = (act->cnt_spinkey > 0) ? 100 : -100;
                    } else {
                        act->cnt_spinkey = 0;
                    }
                }
            }
            if ((nowpad->cnt & 0x20) && !act->num_reserve_grab) {
                act->trick_keep = 1;
            } else {
                act->trick_keep = 0;
            }
            if (req->command == ercTrick) {
                command = ecmdTrick;
                cmd_mot_id = req->cmd_mot_id;
                cmd_mot_nloop = req->cmd_mot_nloop;
                cmd_trick_no = req->cmd_trick_no;
            } else if (req->command == ercFlip) {
                command = ecmdFlip;
                cmd_mot_id = req->cmd_mot_id;
                cmd_mot_nloop = req->cmd_mot_nloop;
                cmd_trick_no = req->cmd_trick_no;
            }
            break;
        }
        default: {
            signed int sc; // 0x14C(r29)

            switch (mot->now.id) {
                case 0x43:
                    sc = 0;
                    break;
                case 0x31:
                case 0x33:
                    if (mot->now.frame > (mot->now.num_frame / 3)) {
                        sc = 1;
                    } else {
                        sc = 0;
                    }
                    break;
                default:
                    sc = 1;
                    break;
            }
            if (sc) {
                if (req->stance_change == erscTurnLeft) {
                    stance_change = escTurnLeft;
                } else if (req->stance_change == erscTurnRight) {
                    stance_change = escTurnRight;
                }
            }
            if (req->end_fall) {
                command = ecmdEndFall;
                cmd_mot_id = 0x4D;
            }
            break;
        }
    }
    act->trg_onair_with_over_hp = 0;
    if (!act->hp_air && (nowpad->cnt & 0x1000) && !(nowpad->cnt & 0xA000)) {
        act->over_hp = 1;
        if ((act->trg_hopup || act->trg_jumpup) && rc->prepos.halfpipe && rc->act.col_hp.vertex) {
            act->trg_onair_with_over_hp = 1;
            req->accel_brake = eraAccel;
        }
    }
    if ((req->accel_brake == eraAccel) && act->trg_onair_with_over_hp) {
        accel_state = easAccel;
    } else if (!stance_change && (mot->now.id != 0x43)) {
        if (req->accel_brake == eraAccel) {
            if (rc->splen < 8.0f) {
                accel_state = easAccel;
            }
        } else if (req->accel_brake == eraBrake) {
            accel_state = easBrake;
        } else if ((act->sliding_state == essSliding) || (act->sliding_state == essSitting) || (act->sliding_state == essManual) ||
                   ((act->sliding_state == essGrind) && (act->pre_state == essGrind))) {
            float ang; // 0x150(r29)

            ang = act->target_way - rc->rot_pole;
            ang = (ang < -3.141592f) ? (6.283184f + ang) : ((ang > 3.141592f) ? (ang - 6.283184f) : ang);
            if ((ang > -0.785398f) && (ang < 0.785398f) && (act->sliding_state != essGrind) && (rc->splen < 11.0f)) {
                accel_state = easLowSpAccel;
            } else if ((ang < -2.0943947f) || (ang > 2.0943947f)) {
                accel_state = easBackAccel;
            }
        }
    }
    if (nowpos->hit && (act->tumble_type > 0) && !act->cnt_planttumble) {
        if (act->tumble_type == 1) {
            accel_state = easBrakeTotter;
        } else if (act->tumble_type == 2) {
            accel_state = easBrakeTumbleS;
        } else if ((act->tumble_type == 3) || (act->tumble_type == 4)) {
            accel_state = easBrakeTumbleL;
        } else if (act->tumble_type == 5) {
            accel_state = easBrakeTotter;
        }
    }
    if (req->accel_brake == eraAccelLeft) {
        accel_state = easAccelLeft;
    } else if (req->accel_brake == eraAccelRight) {
        accel_state = easAccelRight;
    }
    if ((jump_state == ejsSitting) && (accel_state != easLowSpAccel) && (accel_state != easBackAccel)) {
        accel_state = easSitAccel;
    }
    if (act->boost && (act->boost_left_time > 0) && (!act->sliding_state || (act->sliding_state == essSitting))) {
        accel_state = easBoostAccel;
    }
    if ((act->pre_state == essPlant) && !act->mot_planting) {
        accel_state = easPlantAccel;
    }
    switch (command) {
        case ecmdNone:
            if (req->command != ercJump) {
                break;
            }
        case ecmdTrick:
        case ecmdFlip:
            if (command != ecmdNone) {
                if (!act->mot_grabing && !act->mot_flipping && !act->mot_spflipping && !act->num_reserve_trick) {
                    ktactCommandResetAllForTrick(act);
                }
                act->manual_ready = 0;
                act->bonk_ready = 0;
                act->revert_cnt_ready = 0;
                break;
            }
        case ecmdGrind:
        case ecmdPlant:
        case ecmdRevert:
        case ecmdTumble:
        case ecmdEndFall:
            if (command == ecmdGrind) {
                ktactCommandResetAllForGrind(act, req->grind_no);
            } else if (command == ecmdRevert) {
                ktactCommandResetAllForRevert(act);
            } else if (!command && (req->command == ercJump)) {
                ktactCommandResetAllForJump(act);
            } else {
                ktactCommandResetAll(act);
            }
            if (command != ecmdRevert) {
                act->manual_ready = 0;
            }
            act->bonk_ready = 0;
            act->num_reserve_trick = 0;
            act->num_reserve_grab = 0;
            act->revert_cnt_ready = 0;
            break;
    }
    if (req->command == ercBonk) {
        command = ecmdBonk;
        cmd_mot_id = req->cmd_mot_id;
        cmd_mot_nloop = req->cmd_mot_nloop;
        ktactSetHorizonParam(rc, 1);
        act->revert_cnt_ready = 0;
    }
    if (act->hp_air) {
        signed int hp_cancel; // 0x154(r29)

        hp_cancel = 0;
        if (act->cnt_warp > 0) {
            hp_cancel = 1;
        } else if (!act->col_hp.vertex || !(act->col_hp.attr & 0x1800)) {
            if ((nowpad->cnt & rc->key->revert) && (nowpad->cnt & rc->key->stance)) {
                hp_cancel = 1;
            }
        }
        if (hp_cancel) {
            act->over_hp = 1;
            act->hp_air = 0;
            ktactSetHorizonParam(rc, 1);
            command = ecmdHpCancel;
            cmd_mot_id = 0x42;
            cmd_mot_nloop = 0;
            act->revert_cnt_ready = 0;
        }
    }
    nowinp->accel_state = accel_state;
    nowinp->jump_state = jump_state;
    nowinp->stance_change = stance_change;
    nowinp->spin_way = spin_way;
    nowinp->command = command;
    nowinp->cmd_mot_id = cmd_mot_id;
    nowinp->cmd_mot_nloop = cmd_mot_nloop;
    nowinp->cmd_trick_no = cmd_trick_no;
    if (act->trg_tumble_type) {
        signed int mot_totter[4] = {0x3A, 0x52, 0x18, 0x0B}; // 0xA0(r29)
        s32* volatile mot_totterPtr = &mot_totter;
        (void)mot_totterPtr;
        {
            signed int mot_tumble_s[4] = {0x3C, 0x54, 0x17, 0x0A}; // 0xB0(r29)
            s32* volatile mot_tumble_sPtr = &mot_tumble_s;
            (void)mot_tumble_sPtr;
            {
                signed int mot_tumble_s_touch[4] = {0x39, 0x51, 0x17, 0x0A}; // 0xC0(r29)
                s32* volatile mot_tumble_s_touchPtr = &mot_tumble_s_touch;
                (void)mot_tumble_s_touchPtr;
                {
                    signed int mot_tumble_l_touch[4] = {0x38, 0x50, 0x13, 0x06}; // 0xD0(r29)
                    s32* volatile mot_tumble_l_touchPtr = &mot_tumble_l_touch;
                    (void)mot_tumble_l_touchPtr;
                    {
                        signed int mot_tumble_l_normal[4] = {0x56, 0x56, 0x20, 0x48}; // 0xE0(r29)
                        s32* volatile mot_tumble_l_normalPtr = &mot_tumble_l_normal;
                        (void)mot_tumble_l_normalPtr;
                        {
                            signed int mot_tumble_l_gr_fs[2] = {0x35, 0x4C}; // 0xF0(r29)
                            s32* volatile mot_tumble_l_gr_fsPtr = &mot_tumble_l_gr_fs;
                            (void)mot_tumble_l_gr_fsPtr;
                            {
                                signed int mot_tumble_l_gr_bs[2] = {0x34, 0x4B}; // 0xF8(r29)
                                s32* volatile mot_tumble_l_gr_bsPtr = &mot_tumble_l_gr_bs;
                                (void)mot_tumble_l_gr_bsPtr;
                                {
                                    signed int mot_tumble_l_gr_50[2] = {0x2F, 0x47}; // 0x100(r29)
                                    s32* volatile mot_tumble_l_gr_50Ptr = &mot_tumble_l_gr_50;
                                    (void)mot_tumble_l_gr_50Ptr;
                                    {
                                        signed int mot_tumble_l_manual[2] = {0x13, 0x06}; // 0x108(r29)
                                        s32* volatile mot_tumble_l_manualPtr = &mot_tumble_l_manual;
                                        (void)mot_tumble_l_manualPtr;
                                        {
                                            signed int mot_tumble_l_plant = 0x13; // 0x158(r29)
                                            signed int mot_tumble_f = 0x56; // 0x15C(r29)
                                            signed int mot_tumble_n = 0x13; // 0x160(r29)
                                            signed int mot_tumble_s_grab = 0x1F; // 0x164(r29)
                                            signed int tw; // r23

                                            tw = act->trg_tumble_way;
                                            switch (act->trg_tumble_type) {
                                            case 1:
                                            cmd_mot_id = mot_totter[tw];
                                            break;
                                            case 2:
                                            if (act->trg_touch) {
                                            if (act->mot_grabing) {
                                            cmd_mot_id = mot_tumble_s_grab;
                                            } else {
                                            cmd_mot_id = mot_tumble_s_touch[tw];
                                            }
                                            } else {
                                            cmd_mot_id = mot_tumble_s[tw];
                                            }
                                            break;
                                            case 4:
                                            cmd_mot_id = mot_tumble_f;
                                            break;
                                            case 5:
                                            cmd_mot_id = mot_tumble_n;
                                            break;
                                            case 3:
                                            default:
                                            if (act->trg_touch) {
                                            cmd_mot_id = mot_tumble_l_touch[tw];
                                            } else {
                                            switch (act->pre_state) {
                                            case essGrind:
                                            tw = (tw == 0) ? 0 : 1;
                                            switch (rc->mot.now.id) {
                                            case 0x91:
                                            case 0x92:
                                            case 0x8E:
                                            case 0x8F:
                                            case 0x93:
                                            case 0x94:
                                            case 0x97:
                                            case 0x98:
                                            case 0x9E:
                                            case 0x9F:
                                            case 0x8C:
                                            case 0x82:
                                            cmd_mot_id = mot_tumble_l_gr_fs[tw];
                                            break;
                                            case 0x87:
                                            case 0x88:
                                            case 0x84:
                                            case 0x85:
                                            case 0x89:
                                            case 0x8A:
                                            cmd_mot_id = mot_tumble_l_gr_bs[tw];
                                            break;
                                            case 0xA1:
                                            case 0xA2:
                                            case 0x9A:
                                            case 0x9B:
                                            case 0x7F:
                                            case 0x80:
                                            case 0x95:
                                            case 0x9C:
                                            case 0x96:
                                            case 0x9D:
                                            case 0x8B:
                                            case 0x81:
                                            case 0x60:
                                            case 0x66:
                                            case 0x74:
                                            case 0x62:
                                            case 0x6B:
                                            case 0x61:
                                            case 0x67:
                                            case 0x75:
                                            case 0x63:
                                            case 0x6C:
                                            cmd_mot_id = mot_tumble_l_gr_50[tw];
                                            break;
                                            }
                                            break;
                                            case essManual:
                                            tw = (tw == 2) ? 0 : 1;
                                            cmd_mot_id = mot_tumble_l_manual[tw];
                                            break;
                                            case essPlant:
                                            cmd_mot_id = mot_tumble_l_plant;
                                            break;
                                            default:
                                            cmd_mot_id = mot_tumble_l_normal[tw];
                                            break;
                                            }
                                            }
                                            break;
                                            }
                                            nowinp->command = ecmdTumble;
                                            nowinp->cmd_mot_id = cmd_mot_id;
                                            nowinp->cmd_mot_nloop = 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

static void ktactUpdateBalance(Balance* bal, Act* act, signed int a, signed int b, signed int cnt) {
    float lean_limit;
    float lean_gravity_min;
    float lean_gravity_max;
    float lean;
    float lean_dir;
    float manual_time;
    float rate;
    float lean_gravity;
    float lean_acc;
    float lean_acc_fr;

    lean_limit = (float)vktactParamBal_lean_limit;
    lean_gravity_min = 0.1f * (float)vktactParamBal_lean_gravity_min;
    lean_gravity_max = 0.1f * (float)vktactParamBal_lean_gravity_max;
    lean = bal->lean;
    lean_dir = bal->lean_dir;
    manual_time = 0.016666668f * (float)cnt;
    rate = (float)act->param.balance / 90.0f;
    lean_gravity = lean_gravity_min + rate * (lean_gravity_max - lean_gravity_min);
    lean_acc = 0.1f * (float)vktactParamBal_lean_acc_inp;
    lean_acc_fr = (0.0001f * (float)vktactParamBal_lean_acc_fr_base) + ((float)cnt * (0.0001f * (float)vktactParamBal_lean_acc_fr_rate));
    if (bal->cnt_free == 0) {
        lean = lean + ((30.0f + (0.5f * manual_time)) * (lean / lean_gravity)) / lean_gravity;
        lean = lean + (lean_dir * (30.0f + (0.5f * manual_time))) / lean_gravity;
        if (a != 0 && bal->released != 0) {
            lean_dir = lean_dir - lean_acc;
        } else if (b != 0 && bal->released != 0) {
            lean_dir = lean_dir + lean_acc;
        } else if (!(lean_dir <= 0.0f)) {
            lean_dir = lean_dir + lean_acc_fr;
        } else {
            lean_dir = lean_dir - lean_acc_fr;
        }
    }
    bal->lean = lean;
    bal->lean_dir = lean_dir;
    bal->balance = (0.34906578f * lean) / lean_limit;
    if (bal->balance <= 0.34906578f && !(bal->balance < -0.34906578f)) {
    }
}

static void ktactReflectInput(Ctrl* rc) {
    Act* act; // r16
    Inp* inp; // r17
    float delta_limit_move; // 0x38(r29)
    float max_relief_gap; // 0x3C(r29)

    act = &rc->act;
    inp = &rc->nowinp;
    if (inp->jump_state >= 4) {
        act->cnt_freefoot = 0xA;
    }
    if ((inp->turn > 0) && (act->cnt_turn >= 0)) {
        act->cnt_turn = (signed int)(act->cnt_turn + 1);
    } else if ((inp->turn < 0) && (act->cnt_turn <= 0)) {
        act->cnt_turn = (signed int)(act->cnt_turn - 1);
    } else {
        act->cnt_turn = 0;
    }
    if ((inp->jump_state == 1) || (inp->jump_state == 2) || (inp->jump_state >= 4)) {
        act->cnt_sitting = (signed int)(act->cnt_sitting + 1);
    } else {
        act->cnt_sitting = 0;
    }
    if (act->sliding_state != 3) {
        act->jump_air = inp->jump_state >= 4 ? 1 : 0;
    }
    if (inp->jump_state == 1) {
        act->now_max_speed *= 1.1f;
    }
    delta_limit_move = act->sbcore.const_max_relief_gap / 30.0f;
    max_relief_gap = act->max_relief_gap;
    if ((act->sliding_state == 1) || (act->boost_left_time > 0) || (rc->nowpos.halfpipe != 0)) {
        max_relief_gap = max_relief_gap - delta_limit_move;
        if (max_relief_gap < 0.0f) {
            max_relief_gap = 0.0f;
        }
    } else {
        max_relief_gap = max_relief_gap + delta_limit_move;
        if (!(max_relief_gap <= act->sbcore.const_max_relief_gap)) {
            max_relief_gap = act->sbcore.const_max_relief_gap;
        }
    }
    act->max_relief_gap = max_relief_gap;
    act->sbcore.max_relief_gap = max_relief_gap;
}

static void ktactAdj(Ctrl* rc) {
    Act* act; // r16

    act = &rc->act;
    if (act->sliding_state == 5) {
        ktactAdjSpeed_grind(rc);
    } else if (act->sliding_state == 6) {
        rc->speed[0] = 0.0f;
        rc->speed[1] = 0.0f;
        rc->speed[2] = 0.0f;
        rc->speed[3] = 0.0f;
        ktactAdjSpeedG(rc);
    } else if (act->hp_air != 0) {
        ktactAdjRot(rc);
        ktactAdjSpeed_halfpipe(rc);
        ktactAdjSpeedG(rc);
    } else {
        ktactAdjRot(rc);
        ktactAdjSpeed(rc);
    }
    ktactAdjSpeedLimit(rc);
}

static void ktactAdjRot(Ctrl* rc) {
    // float sp1DC;
    // float sp1D8;
    // float sp1D4;
    // float sp1D0;
    // float sp1CC;
    // float sp1C8;
    // float sp1C4;
    // float sp1C0;
    // float sp1BC;
    // float sp1B8;
    // float sp1B4;
    // float sp1B0;
    // float sp1AC;
    // float sp1A8;
    // float sp1A4;
    // float sp1A0;
    // float sp19C;
    // float sp198;
    // float sp194;
    // float sp190;
    // float sp18C;
    // float sp188;
    // float sp184;
    // float sp180;
    // float sp17C;
    // float sp178;
    // float sp174;
    // float rx;
    // float lsp;
    // ? wlm;
    // signed int temp_a1;
    // signed int temp_a2;
    // signed int var_a0;
    // signed int var_s4;

    float ang_spin_count; // 0x15C(r29)
    float max_turn_ang; // 0x160(r29)
    float sp_spin_ang; // 0x164(r29)
    float pre_rot_pole; // 0x168(r29)
    float ang; // 0x16C(r29)
    TrickLink* tl; // r17
    Param2* param; // r19
    Act* act; // r16
    Inp* inp; // r18

    ang_spin_count = vktactMatTumbleAng_touch[0];
    inp = &rc->nowinp;
    act = &rc->act;
    param = &act->param;
    tl = &act->trick_link;
    sp_spin_ang = 0.0f;
    pre_rot_pole = rc->rot_pole;
    if (act->sliding_state == 4) {
        // temp_a2 = param->turning;
        max_turn_ang = iktactMakeParam_sitting_turn(param->turning);
    } else if (inp->quick_turn) {
        max_turn_ang = iktactMakeParam_quick_turn(param->turning);
    } else if (inp->jump_state == 1) {
        // temp_a1 = param->turning;
        max_turn_ang = iktactMakeParam_sitting_turn(param->turning);
    } else {
        max_turn_ang = iktactMakeParam_turn(param->turning);
    }
    if ((act->hp_adj_roty) && ((act->cnt_spinkey < -0x1E) || (act->cnt_spinkey > 0x1E))) {
        act->hp_adj_roty = 0;
        act->cnt_spinkey = act->cnt_spinkey > 0 ? 1 : -1;
    }
    if (inp->spin_way) {
        sp_spin_ang = iktactMakeParam_spin(param->spin);
    }
    if ((act->cnt_spinkey > -0x1E) && (act->cnt_spinkey < 0x1E)) {
        if (act->cnt_spinkey >= 0) {
            sp_spin_ang *= (float)act->cnt_spinkey / 30.0f;
        } else {
            sp_spin_ang *= -(float)act->cnt_spinkey / 30.0f;
        }
    }
    if (rc->cheats->super_spin) {
        sp_spin_ang *= 1.5f;
    }
    if (((inp->turn > 0) && (inp->keyway == 2)) || ((inp->turn < 0) && (inp->keyway == 1))) {
        rc->rot_pole += (max_turn_ang * (float)inp->turn) / 1270.0f;
        rc->rot_pole = rc->rot_pole < -3.141592f
                           ? 6.283184f + rc->rot_pole
                       : rc->rot_pole > 3.141592f
                           ? rc->rot_pole - 6.283184f
                           : rc->rot_pole;
    }
    switch (inp->spin_way) {
        case 3:
            sp_spin_ang *= 1.5f;
            /* fallthrough */
        case 1:
            rc->rot_pole -= sp_spin_ang;

            rc->rot_pole = rc->rot_pole < -3.141592f
                               ? 6.283184f + rc->rot_pole
                           : rc->rot_pole > 3.141592f
                               ? rc->rot_pole - 6.283184f
                               : rc->rot_pole;
            if (act->last_spin_way != 1) {
                act->last_rot_pole = pre_rot_pole;
                act->last_spin_way = 1;
            }
            ang = rc->rot_pole - act->last_rot_pole;
            ang = ang < -3.141592f
                      ? 6.283184f + ang
                  : ang > 3.141592f
                      ? ang - 6.283184f
                      : ang;
            pre_rot_pole -= act->last_rot_pole;
            pre_rot_pole = pre_rot_pole < -3.141592f
                               ? 6.283184f + pre_rot_pole
                           : pre_rot_pole > 3.141592f
                               ? pre_rot_pole - 6.283184f
                               : pre_rot_pole;
            if (!(pre_rot_pole <= ang_spin_count) && (ang <= ang_spin_count)) {
                tl->spin_ang = (signed int)(tl->spin_ang + 1);
                if (tl->last_spin_ang > 0) {
                    act->trg_rewind = 1;
                    tl->last_spin_ang = 0;
                }
                tl->last_spin_ang = (signed int)(tl->last_spin_ang - 1);
            } else {
                pre_rot_pole += 3.141592f;
                pre_rot_pole = pre_rot_pole < -3.141592f
                                   ? 6.283184f + pre_rot_pole
                               : pre_rot_pole > 3.141592f
                                   ? pre_rot_pole - 6.283184f
                                   : pre_rot_pole;
                ang += 3.141592f;
                ang = ang < -3.141592f
                          ? 6.283184f + ang
                      : ang > 3.141592f
                          ? ang - 6.283184f
                          : ang;
                if (!(pre_rot_pole <= ang_spin_count) && (ang <= ang_spin_count)) {
                    tl->spin_ang = (signed int)(tl->spin_ang + 1);
                    if (tl->last_spin_ang > 0) {
                        act->trg_rewind = 1;
                        tl->last_spin_ang = 0;
                    }
                    tl->last_spin_ang = (signed int)(tl->last_spin_ang - 1);
                }
            }
            break;
        case 4:
            sp_spin_ang *= 1.5f;
            /* fallthrough */
        case 2:
            rc->rot_pole += sp_spin_ang;
            rc->rot_pole = rc->rot_pole < -3.141592f
                               ? 6.283184f + rc->rot_pole
                           : rc->rot_pole > 3.141592f
                               ? rc->rot_pole - 6.283184f
                               : rc->rot_pole;
            // var_a0 = act->last_spin_way;
            if (act->last_spin_way != 2) {
                act->last_rot_pole = pre_rot_pole;
                act->last_spin_way = 2;
            }
            ang = rc->rot_pole - act->last_rot_pole;
            ang = ang < -3.141592f
                      ? 6.283184f + ang
                  : ang > 3.141592f
                      ? ang - 6.283184f
                      : ang;
            pre_rot_pole -= act->last_rot_pole;
            pre_rot_pole = pre_rot_pole < -3.141592f
                               ? 6.283184f + pre_rot_pole
                           : pre_rot_pole > 3.141592f
                               ? pre_rot_pole - 6.283184f
                               : pre_rot_pole;
            if ((pre_rot_pole < -ang_spin_count) && !(ang < -ang_spin_count)) {
                tl->spin_ang++;
                if (tl->last_spin_ang < 0) {
                    act->trg_rewind = 1;
                    tl->last_spin_ang = 0;
                }
                tl->last_spin_ang++;
            } else {
                pre_rot_pole += 3.141592f;
                pre_rot_pole = pre_rot_pole < -3.141592f
                                   ? 6.283184f + pre_rot_pole
                               : pre_rot_pole > 3.141592f
                                   ? pre_rot_pole - 6.283184f
                                   : pre_rot_pole;
                ang += 3.141592f;

                ang = ang < -3.141592f
                          ? 6.283184f + ang
                      : ang > 3.141592f
                          ? ang - 6.283184f
                          : ang;
                if ((pre_rot_pole < -ang_spin_count) && !(ang < -ang_spin_count)) {
                    tl->spin_ang = (signed int)(tl->spin_ang + 1);
                    if (tl->last_spin_ang < 0) {
                        act->trg_rewind = 1;
                        tl->last_spin_ang = 0;
                    }
                    tl->last_spin_ang = (signed int)(tl->last_spin_ang + 1);
                }
            }
            break;
    }
    if ((inp->turn_x) && (act->hp_air == 0)) {
        sceVu0FMATRIX m; // 0x70(r29)
        sceVu0FMATRIX mtx; // 0xB0(r29)
        float rx = inp->turn_x > 0 ? 0.026179934f : -0.026179934f; // 0x170(r29)
        sceVu0FVECTOR v = {0.0f, -1.0f, 0.0f, 1.0f}; // 0xF0(r29)
        s32* vPtr = &v;

        ang = atan2f(-rc->speed[0], -rc->speed[2]);
        ang = rc->rot_pole - ang;
        ang = ang < -3.141592f
                  ? 6.283184f + ang
              : ang > 3.141592f
                  ? ang - 6.283184f
                  : ang;
        if (ang > 1.570796f || ang < -1.570796f) {
            rx = -rx;
        }
        sceVu0UnitMatrix(m);
        sceVu0RotMatrixX(&m, &m, rx);
        sceVu0ApplyMatrix(v, m, v);
        sbcoreGetRotMatrix(mtx, rc->pole, rc->rot_pole);
        sceVu0ApplyMatrix(v, mtx, v);
        if (v[1] > 0.0f) {
            if (v[1] < rc->pole[1]) {
                *(__int128*)rc->pole = *(__int128*)v;
            }
        } else {
            *(__int128*)rc->pole = *(__int128*)v;
        }
    }
    if (act->hp_air && act->hp_adj_roty) {
        sceVu0FMATRIX wlm; // 0x100(r29)
        sceVu0FVECTOR lsp; // 0x140(r29)

        sbcoreGetRotMatrix(wlm, rc->pole, rc->rot_pole);
        sceVu0InversMatrix(wlm, wlm);
        sceVu0ApplyMatrix(lsp, wlm, rc->speed);
        ang = atan2f(-lsp[0], -lsp[2]);
        rc->rot_pole += ang;
        rc->rot_pole = rc->rot_pole < -3.141592f
                           ? 6.283184f + rc->rot_pole
                       : rc->rot_pole > 3.141592f
                           ? rc->rot_pole - 6.283184f
                           : rc->rot_pole;
        act->last_rot_pole = rc->rot_pole;
    }
}

float iktactMakeParam_spin(signed int src) {

    float cmn_spin; // r29
    float min_spin; // 0x4(r29)
    float max_spin; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_spin = vktactParamCmnSpin;
    min_spin = vktactParamMinSpin;
    max_spin = vktactParamMaxSpin;
    param = cmn_spin;
    if (src >= 0x32) {
        param += ((src - 0x32) * (max_spin - cmn_spin)) / 50.0f;
    } else {
        param += ((0x32 - src) * (min_spin - cmn_spin)) / 40.0f;
    }

    param *= 0.016666668f;
    return param;
}

float iktactMakeParam_turn(signed int src) {
    float cmn_turn; // r29
    float min_turn; // 0x4(r29)
    float max_turn; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_turn = vktactParamCmnTurn;
    min_turn = vktactParamMinTurn;
    max_turn = vktactParamMaxTurn;
    param = cmn_turn;
    if (src >= 0x32) {
        param += ((src - 0x32) * (max_turn - cmn_turn)) / 50.0f;
    } else {
        param += ((0x32 - src) * (min_turn - cmn_turn)) / 40.0f;
    }
    param *= 0.016666668f;
    return param;
}

float iktactMakeParam_quick_turn(signed int src) {
    float cmn_sturn; // r29
    float min_sturn; // 0x4(r29)
    float max_sturn; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_sturn = vktactParamCmnQuickTurn;
    min_sturn = vktactParamMinQuickTurn;
    max_sturn = vktactParamMaxQuickTurn;
    param = cmn_sturn;
    if (src >= 0x32) {
        param += ((src - 0x32) * (max_sturn - cmn_sturn)) / 50.0f;
    } else {
        param += ((0x32 - src) * (min_sturn - cmn_sturn)) / 40.0f;
    }
    param *= 0.016666668f;
    return param;
}

float iktactMakeParam_sitting_turn(signed int src) {
    float cmn_sturn; // r29
    float min_sturn; // 0x4(r29)
    float max_sturn; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_sturn = vktactParamCmnSitTurn;
    min_sturn = vktactParamMinSitTurn;
    max_sturn = vktactParamMaxSitTurn;
    param = cmn_sturn;
    if (src >= 0x32) {
        param += ((src - 0x32) * (max_sturn - cmn_sturn)) / 50.0f;
    } else {
        param += ((0x32 - src) * (min_sturn - cmn_sturn)) / 40.0f;
    }

    param *= 0.016666668f;
    return param;
}

static void ktactAdjSpeed(Ctrl* ctrl) {
    if (ctrl->nowinp.jump_state >= 4) {
        // Is at the very start of a jump
        ktactAdjSpeedJump(ctrl);
    }
    if ((ctrl->nowpos.hit) && (ctrl->nowinp.jump_state < 4)) {
        // Is on ground (not in air)
        ktactAdjSpeedBoard(ctrl);
        ktactAdjSpeedG(ctrl);
        ktactAdjSpeedAccel(ctrl);
        ktactAdjSpeedEtc(ctrl);
    } else {
        // Is midair
        ktactAdjSpeedG(ctrl);
        ktactAdjSpeedAccel(ctrl);
        ktactAdjSpeedEtc(ctrl);
        if ((ctrl->act.bonk_ready != 0) && (ctrl->act.bonk_goto != 0)) {
            ktactAdjSpeed_bonk(ctrl);
        }
    }
}

static void ktactAdjSpeed_grind(Ctrl* rc) {
    Act* act; // r16 // s0
    signed int no; // r17 // s1
    signed int back_accel; // r18 // s2
    signed int reverse_speed; // r19 // s3
    signed int acc; // r20 // s4

    float vec[4]; // 0x70(r29)
    float sp[4]; // 0x80(r29)
    float splen; // 0x98(r29)
    float inner; // 0x9C(r29)
    float len; // 0xA0(r29)
    float ang; // 0xA4(r29)

    act = &rc->act;
    no = act->rail_no;
    back_accel = 0;
    reverse_speed = 0;
    acc = 0;
    if (no >= (act->num_rail_vertex - 1)) {
        no = act->num_rail_vertex - 2;
    }
    sceVu0SubVector(&vec, act->rail_list[no + 1], act->rail_list[no]);
    *(__int128*)sp = *(__int128*)rc->speed;
    splen = iktactGetLen(sp);
    len = iktactGetLen(vec);
    inner = (sp[0] * vec[0]) + (sp[2] * vec[2]); //((second half of double) * (bitwise float) sp) + ((second half of double) * (bitwise float) sp88);
    if (inner > 0.0f) {
        sceVu0ScaleVector(&sp, &vec, splen / len); //(second half of double) / (bitwise float) (bitwise double) splen, &sp, &vec);
    } else {
        sceVu0ScaleVector(&sp, &vec, -splen / len);
    }
    if (act->gr_back_accel && (rc->nowinp.accel_state == easBackAccel)) {
        acc = 1;
    }
    if (acc) {
        ktactAdjSpeedAccel(rc);
        inner = sceVu0InnerProduct(&sp, rc->speed);
        splen = iktactGetLen(rc->speed);
        if (inner < 0.0f) {
            splen = -splen;
        }
    }
    ang = atan2f(-(float)sp[0], -(float)sp[2]);
    ang = ang - act->target_way;
    ang = ang < -3.141592f  ? 6.283184f + ang
          : ang > 3.141592f ? ang - 6.283184f
                            : ang;

    if (ang < 0.0f) {
        ang = -ang;
    }
    if ((ang > 2.0943947f)) {
        back_accel = 1;
    }
    len = iktactGetLenXZ(&sp);
    ang = atan2f(sp[1], len);
    if (ang < 0.0f) {
        ang = -ang;
    }
    if (ang > 1.570796f) {
        ang = 3.141592f - ang;
    }
    if (sp[1] > 0.0f) {
        len = 0.16333334f * sinf(ang);
        splen = splen + len;
        if ((splen > act->cmn_max_speed)) {
            splen = act->cmn_max_speed;
        }
    } else {
        len = 0.32666668f * sinf(ang);
        splen = splen - len;
        if (back_accel != 0) {
            splen += -0.083333336f;
        }
    }
    if (act->trg_touch != 0) {
        if (splen > act->now_max_speed) {
            splen = act->now_max_speed;
        } else if (splen < -act->now_max_speed) {
            splen = -act->now_max_speed;
        }
    }
    sceVu0Normalize(&sp, &sp);
    sceVu0ScaleVectorXYZ(sp, sp, splen);
    if (splen < 0.0f) {
        reverse_speed = 1;
        splen = -splen;
        if ((act->trg_touch == 0) && (splen < 11.111111f)) {
            sceVu0ScaleVectorXYZ(sp, sp, 11.111111f / splen);
            splen = 11.111111f;
        }
    }
    sp[3] = 1.0f;
    *(__int128*)rc->speed = *(__int128*)sp;
    rc->splen = splen;
    if ((act->trg_touch == 0) && reverse_speed) {
        act->gr_is_reverse = act->gr_is_reverse ? 0 : 1;
    }
}

static void ktactAdjSpeed_halfpipe(Ctrl* rc) {
    Act* act; // r16
    act = &rc->act;
    if (act->hp_normal[1] == 0.0f) {
        sbcoreGetShadowRotVector(rc->speed, &act->hp_normal, rc->speed);
        rc->speed[3] = 1.0f;
    }
}

// ktact.c
static void ktactAdjSpeed_bonk(Ctrl* rc) {
    float v[4]; // 0x30(r29)
    float splen; // 0x4C(r29)
    Act* act; // r16
    Pos* now; // r17

    act = &rc->act;
    now = &rc->nowpos;
    if (now->pos[1] < act->bonk_point[1]) {
        splen = iktactGetLen(rc->speed);
        sceVu0SubVector(v, act->bonk_point, now);
        sceVu0Normalize(v, v);
        sceVu0ScaleVector(rc->speed, v, splen);
    }
}

static void ktactAdjSpeedG(Ctrl* rc /* sp C0 */) {
    sceVu0FVECTOR nor; // 0x80(r29)
    float adj_sp_slide = 0.16333334f; // 0x90(r29)
    float adj_sp_rise = 0.32666668f; // 0x94(r29)
    float adj_sp_rise_rip = 0.016333334f; // 0x98(r29)
    float limit_sp_material_rate = 0.5f * rc->act.cmn_max_speed; // 0x9C(r29)
    float rate; // 0xA0(r29)
    float material_rate; // 0xA4(r29)
    float ftmp; // 0xA8(r29)
    float splen; // 0xAC(r29)
    float splimit0; // 0xB0(r29)
    float ang; // 0xB4(r29)
    float slant_rate; // 0xB8(r29)
    float spy_adj; // 0xBC(r29)
    // Size: 0x2580, DWARF: 0x76810
    Act* act = &rc->act; // r16
    float* speed = rc->speed; // r17
    signed int boost; // r18
    signed int material; // r19
    sceVu0FVECTOR sp = {
        0.0f, adj_sp_slide, 0.0f, 1.0f}; // 0x70(r29)
    s32* spPtr = &sp;

    boost = 0;
    if (act->sbcore.move) {
        if (vspenvGame->mode.game_mode == Multiplayer && vspenvGame->mode.match_rule == MatchBoost) {
            boost = 1;
        }
        if (rc->cheats->half_g && boost == 0) {
            adj_sp_slide *= 0.8f;
            adj_sp_rise *= 0.8f;
            adj_sp_rise_rip *= 0.8f;
        }
        if (rc->nowpos.hit && rc->nowpos.normal[1] < 0.0f) {
            material = rc->nowpos.material & 0x7FF;
            if (material >= 0xC) {
                material = 0xB;
            }
            material_rate = vktactMatAccelRate[material];
            if (rc->splen < limit_sp_material_rate) {
                material_rate = 1.0f;
            }
            if (speed[1] < 0.0f && (rc->nowpos.halfpipe || rc->nowpos.low_g) && act->tumble_type < 2 && act->cnt_d2c == 0) {
                sp[1] = adj_sp_rise_rip;
                rate = 1.0f;
            } else if (act->slant < 0.0f) {
                ftmp = -act->slant;
                ftmp = ftmp / 0.785398f;
                if ((ftmp > 1.0f)) {
                    ftmp = 1.0f;
                }
                sp[1] = adj_sp_slide + (ftmp * (adj_sp_rise - adj_sp_slide));
                rate = 1.0f;
            } else {
                splen = rc->splen;
                splimit0 = act->now_max_speed;
                if (splen < splimit0) {
                    rate = 1.0f - ((splen * splen * splen) / (splimit0 * splimit0 * splimit0));
                } else {
                    rate = 0.0f;
                }
            }
            if (rc->nowpos.halfpipe == 0) {
                sceVu0FVECTOR nor = {0.0f, -1.0f, 0.0f, 0.0f}; // @2347
                s32* norPtr = &nor;
                ang = sbcoreGetInnerAngle90(&nor, rc->nowpos.normal);
                slant_rate = ang / 1.570796f;
                if ((slant_rate > 1.0f)) {
                    slant_rate = 1.0f;
                }
                rate *= 1.0f + slant_rate;
            }
            rate = rate * material_rate;
            sbcoreGetShadowVector(&sp[0], rc->nowpos.normal, &sp[0]);
            sceVu0ScaleVectorXYZ(&sp[0], &sp[0], rate);
            sceVu0AddVector(speed, speed, &sp[0]);
            speed[3] = 1.0f;
            return;
        }
        spy_adj = ktactGetAdjSpeedOnAir(speed[1], act->hp_air, act->jump_air);
        if ((rc->cheats->half_g) && (boost == 0)) {
            spy_adj *= 0.8f;
        }
        speed[1] += (spy_adj * act->hang_rate);
    }
}

static float ktactGetAdjSpeedOnAir(float spy, signed int hp_air, signed int jump_air) {
    float sp; // 0xC(r29)

    if (hp_air != 0) {
        sp = 0.01f * (0.16333334f * (float)vktactParamG_hpair);
    } else if (jump_air != 0) {
        if (spy < 0.0f) {
            sp = 0.01f * (0.16333334f * (float)vktactParamG_jump_up);
        } else {
            sp = 0.01f * (0.16333334f * (float)vktactParamG_jump_down);
        }
    } else {
        sp = 0.01f * (0.16333334f * (float)vktactParamG_air);
    }
    return sp;
}

static void ktactAdjSpeedJump(Ctrl* rc) {
    // Size: 0x3C, DWARF: 0x7600B
    Inp* inp; // r16
    float* speed; // r17
    sceVu0FMATRIX m; // 0x50(r29)
    float power_adj; // 0x114(r29)
    float power; // 0x118(r29)
    float spover; // 0x11C(r29)
    float spover2; // 0x120(r29)
    float roty; // 0x124(r29)

    inp = &rc->nowinp;
    speed = rc->speed;
    power_adj = 0.002f * rc->act.cnt_sitting;
    if (inp->jump_state >= ejsJumpUpW) {
        if (inp->jump_state == ejsJumpUpStart) {
            power = iktactMakeParam_jumppower(0);
            power *= 0.8f;
        } else {
            power = iktactMakeParam_jumppower(rc->act.param.ollie);
        }
        if (inp->jump_state == ejsJumpUpM) {
            power *= 1.15f;
        } else if (inp->jump_state == ejsJumpUpS) {
            power *= 1.3f;
        }
        if (rc->act.over_hp && rc->nowpos.halfpipe && rc->act.col_hp.vertex) {
            power *= 0.01f * vktactParamHpOver_jump_rate;
        }
        if (power_adj > 1.0f) {
            power_adj = 1.0f;
        }
        power += power_adj;
        if (speed[1] < 0.0f) {
            if (rc->nowpos.halfpipe) {
                spover = rc->act.max_speed - rc->act.cmn_max_speed;
                spover2 = rc->splen - rc->act.cmn_max_speed;
                if (spover2 > spover) {
                    power = 0.0f;
                } else if (spover2 > 0.0f) {
                    power *= (spover - spover2) / spover;
                }
            }
            speed[1] += power;
        } else {
            sceVu0FVECTOR lsp = {0.0f, power, 0.0f, 1.0f}; // 0x90(r29)
            s32* lspPtr = &lsp;
            sceVu0FVECTOR wsp; // 0xA0(r29)

            sbcoreGetRotMatrix(m, rc->nor_pole, rc->rot_pole);
            sceVu0ApplyMatrix(wsp, m, lsp);
            sceVu0AddVector(speed, speed, wsp);
        }
        if (rc->act.pre_rail_list && inp->keyway != ekwNone) {
            sceVu0FVECTOR lsp = {2.7777777f, 0.0f, 0.0f, 1.0f}; // 0xB0(r29)
            s32* lspPtr = &lsp;
            sceVu0FVECTOR sp; // 0xC0(r29)
            sceVu0FMATRIX rm; // 0xD0(r29)

            roty = rc->rot_pole;
            if (inp->keyway == ekwRight) {
                roty += 3.141592f;
                roty = roty < -3.141592f
                           ? 6.283184f + roty
                       : (roty > 3.141592f)
                           ? roty - 6.283184f
                           : roty;
            }
            sceVu0UnitMatrix(rm);
            sceVu0RotMatrixY(rm, rm, roty);
            sceVu0ApplyMatrix(&sp, &rm, &lsp);
            sceVu0AddVector(speed, speed, sp);
            speed[3] = 1.0f;
        }
    }
}

float iktactMakeParam_jumppower(signed int src) {
    float cmn_jump_power; // r29
    float min_jump_power; // 0x4(r29)
    float max_jump_power; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_jump_power = vktactParamCmnJumpPower;
    min_jump_power = vktactParamMinJumpPower;
    max_jump_power = vktactParamMaxJumpPower;
    param = cmn_jump_power;
    if (src >= 0x32) {
        param += ((float)(src - 0x32) * (max_jump_power - cmn_jump_power)) / 50.0f;
    } else {
        param += ((float)(0x32 - src) * (min_jump_power - cmn_jump_power)) / 40.0f;
    }
    return param;
}

static void ktactAdjSpeedAccel(Ctrl* rc) {
    float adj_sp_accel_over_hp; // 0x154(r29)
    // Size: 0x3C, DWARF: 0x7600B
    Inp* inp; // r17
    float* speed; // r16
    float rate; // 0x158(r29)

    adj_sp_accel_over_hp = (1000.0f * (0.1f * vktactParamHpOver_accel)) / 3600.0f;
    inp = &rc->nowinp;
    speed = rc->speed;
    switch (inp->accel_state) {
        case easAccel:
        case easSitAccel:
        case easPlantAccel:
        case easLowSpAccel:
        case easBackAccel:
        case easStartAccel:
        case easBoostAccel: {
            sceVu0FVECTOR nor = {0.0f, -1.0f, 0.0f, 0.0f}; // 0x70(r29)
            s32* norPtr = &nor;
            sceVu0FVECTOR pole; // 0x80(r29)
            float adj_sp_accel = 0.0f; // 0x15C(r29)
            signed int a = 0; // r21
            sceVu0FVECTOR fv = {0.0f, 0.0f, -adj_sp_accel, 1.0f}; // 0x90(r29)
            s32* fvPtr = &fv;
            sceVu0FVECTOR vec; // 0xA0(r29)
            sceVu0FMATRIX m; // 0xB0(r29)
            float ang; // 0x160(r29)

            (void)norPtr;
            (void)fvPtr;
            *(__int128*)pole = *(__int128*)rc->pole;
            if (inp->accel_state == easAccel) {
                if (rc->act.trg_onair_with_over_hp) {
                    sbcoreGetRotMatrix(m, nor, rc->rot_pole);
                    fv[2] = -adj_sp_accel_over_hp;
                    sceVu0ApplyMatrix(vec, m, fv);
                    sbcoreGetShadowRotVector(vec, nor, vec);
                    sceVu0AddVector(speed, speed, vec);
                    speed[3] = 1.0f;
                    ktactSetHorizonParam(rc, 1);
                } else {
                    ang = sbcoreGetInnerAngle180(nor, rc->nowpos.normal);
                    if (!(speed[1] < 0.0f) || (ang < 0.5235987f)) {
                        adj_sp_accel = 4.1666665f;
                    }
                }
            } else if (inp->accel_state == easSitAccel) {
                if (!(speed[1] < 0.0f)) {
                    if (rc->splen < rc->act.cmn_max_speed) {
                        adj_sp_accel = 0.083333336f;
                    }
                }
            } else if (inp->accel_state == easLowSpAccel) {
                if (rc->splen < rc->act.cmn_max_speed) {
                    adj_sp_accel = 0.19444445f;
                }
            } else if (inp->accel_state == easBackAccel) {
                adj_sp_accel = -0.083333336f;
            } else if (inp->accel_state == easStartAccel) {
                adj_sp_accel = 2.7777777f;
            } else if (inp->accel_state == easBoostAccel) {
                adj_sp_accel = 0.27777779f;
            } else {
                adj_sp_accel = 13.888889f;
                *(__int128*)pole = *(__int128*)rc->act.plant_normal;
            }
            if (adj_sp_accel != 0.0f) {
                sbcoreGetRotMatrix(m, pole, rc->rot_pole);
                fv[2] = -adj_sp_accel;
                sceVu0ApplyMatrix(vec, m, fv);
                sbcoreGetShadowRotVector(vec, pole, vec);
                sceVu0AddVector(speed, speed, vec);
                speed[3] = 1.0f;
            }
            break;
        }
        case easBrake:
            rate = (0.965f * rc->splen) / iktactGetLen(speed);
            sceVu0ScaleVectorXYZ(speed, speed, rate);
            break;
        case easBrakeTotter:
            rate = (0.995f * rc->splen) / iktactGetLen(speed);
            sceVu0ScaleVectorXYZ(speed, speed, rate);
            break;
        case easBrakeTumbleS:
            rate = (0.995f * rc->splen) / iktactGetLen(speed);
            sceVu0ScaleVectorXYZ(speed, speed, rate);
            break;
        case easBrakeTumbleL:
            rate = (0.992f * rc->splen) / iktactGetLen(speed);
            sceVu0ScaleVectorXYZ(speed, speed, rate);
            break;
        case easAccelLeft:
        case easAccelRight: {
            sceVu0FVECTOR lsp = {6.6666665f, 0.0f, 0.0f, 0.0f}; // 0xF0(r29)
            s32* lspPtr = &lsp;
            sceVu0FVECTOR sp; // 0x100(r29)
            sceVu0FMATRIX rm; // 0x110(r29)
            float roty; // 0x164(r29)

            (void)lspPtr;
            roty = rc->rot_pole;
            if (inp->accel_state == easAccelRight) {
                roty += 3.141592f;
                roty = roty < -3.141592f ? 6.283184f + roty : roty > 3.141592f ? roty - 6.283184f
                                                                               : roty;
            }
            sceVu0UnitMatrix(rm);
            sceVu0RotMatrixY(rm, rm, roty);
            sceVu0ApplyMatrix(sp, rm, lsp);
            sceVu0AddVector(speed, speed, sp);
            speed[3] = 1.0f;
            break;
        }
    }
}

// ktact.c
static void ktactAdjSpeedBoard(Ctrl* rc) {
    signed int material; // r16
    signed int d2c; // r17
    float wlm[4][4]; // 0x30(r29)
    float lwm[4][4]; // 0x70(r29)
    float lsp[4]; // 0xB0(r29)
    float wsp[4]; // 0xC0(r29)

    material = rc->nowpos.material & 0x7ff;
    d2c = rc->act.cnt_d2c;

    if (material >= 0xC) {
        material = 0xB;
    }

    *(__int128*)wsp = *(__int128*)rc->speed;
    wsp[3] = 1.0f;
    sbcoreGetRotMatrix(lwm, rc->nowpos.normal, rc->rot_pole);
    sceVu0InversMatrix(&wlm, &lwm);
    sceVu0ApplyMatrix(&lsp, &wlm, &wsp);
    if (!(rc->act.slant <= 0.0f)) {
        d2c += -1;
    }
    ktactEdgeSpeed(lsp, lsp, 0, 0, material, d2c);
    sceVu0ApplyMatrix(&wsp, &lwm, &lsp);
    *(__int128*)rc->speed = *(__int128*)wsp;
}

// ktact.c
static void ktactAdjSpeedLimit(Ctrl* rc /* A0 */) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act; // r16 // s0
    // Size: 0x60, DWARF: 0x79DD3
    Pos* now; // r17 // s1
    signed int b; // r18 // s2
    signed int slidable; // r19 // s3
    signed int material; // r20 // s4
    // Size: 0x30, DWARF: 0x79C3C
    Plane* plane; // r21 // s5
    // Size: 0x30, DWARF: 0x79C3C
    Plane* pre_plane; // r22 // s6
    float max_splen; // 0x80(r29)
    float now_max_splen; // 0x84(r29)
    float splen; // 0x88(r29)
    float splen2; // 0x8C(r29)
    float material_rate; // 0x90(r29)
    float splenxz; // 0x94(r29)
    float spy; // 0x98(r29)
    float inner; // 0x9C(r29)

    max_splen = rc->act.max_speed;
    act = &rc->act;
    now = &rc->nowpos;
    now_max_splen = act->max_speed;
    b = 1;
    if (act->forced_bailout == 0) {
        if (act->boost && (act->boost_left_time > 0)) {
            now_max_splen *= 2.0f;
        }
        material = now->material & 0x7FF;
        if (material >= 0xC) {
            material = 0xB;
        }
        material_rate = vktactMatMaxSpRate[material];
        if (rc->nowinp.jump_state >= ejsJumpUpW) {
            b = 0;
        } else if (act->no_approach_speed != 0) {
            b = 0;
        } else if ((now->hit == 0) && ((act->trg_touch == 0) || (act->trg_bonk != 0)) && (act->hop_vertical_plane == 0)) {
            b = 0;
        }
        if (b != 0) {
            slidable = 0;
            if (now->type == 0) {
                slidable = 1;
            } else if (now->material & 0xA000) {
                slidable = 1;
            }
            if ((act->sliding_state == essTumble) || ((act->trg_touch != 0) && slidable && (act->sliding_state != essGrind))) {
                sbcoreGetShadowVector(rc->speed, now->normal, rc->speed);
                now_max_splen = act->now_max_speed;
            } else if (act->sliding_state == essSitting) {
                now_max_splen *= 1.1f;
            }

            // Adjust the max allowed speed for the material the player is riding on
            now_max_splen = now_max_splen * material_rate;
            if (act->sliding_state == essPlant) {
                sbcoreGetShadowRotVector(rc->speed, act->plant_normal, rc->speed);
            } else if (slidable && (act->sliding_state != essGrind)) {
                sbcoreGetShadowRotVector(rc->speed, act->sbcore.sp_normal, rc->speed);
            }
            splen = iktactGetLen(rc->speed);
            if (splen > now_max_splen) {
                sceVu0ScaleVector(rc->speed, rc->speed, now_max_splen / splen);
                splen = now_max_splen;
            }
            splen2 = iktactGetLen(rc->speed);
            sceVu0ScaleVector(rc->speed, rc->speed, splen / splen2);
            rc->speed[3] = 1.0f;
        } else if (act->pass_finish_line) {
            splenxz = iktactGetLenXZ(rc->speed);
            spy = rc->speed[1];
            if (splenxz > 16.666666f) {
                rc->speed[1] = 0.0f;
                sceVu0Normalize(rc->speed, rc->speed);
                sceVu0ScaleVector(rc->speed, rc->speed, 16.666666f);
                rc->speed[1] = spy;
            }
        }
        if (act->trg_hit_wall) {
            plane = &act->sbcore.plane_hit;
            pre_plane = &act->sbcore.plane_pre_hit;
            if (pre_plane->available) {
                sbcoreGetShadowVector3(rc->speed, now->normal, plane->normal, pre_plane->normal, rc->speed); // Preplane isn't correct for all last 3
                return;
            }
            inner = sceVu0InnerProduct(plane->normal, rc->speed);
            if (inner < 0.0f) {
                sbcoreGetShadowVector2(rc->speed, now->normal, plane->normal, rc->speed);
            }
        }
    }
}

static void ktactAdjSpeedEtc(Ctrl* rc) {
    float* speed; // r16
    Inp* inp; // r17

    inp = &rc->nowinp;
    speed = rc->speed;
    if (inp->stop_speed != 0) {
        speed[0] = 0.0f;
        speed[1] = 0.0f;
        speed[2] = 0.0f;
        speed[3] = 1.0f;
    }
}

// ktact.c
static void ktactMove(Ctrl* rc) {
    Act* act = &rc->act; // r16
    Pos* now = &rc->nowpos; // r19
    Pos* next = &rc->nextpos; // r18
    Pos* pre = &rc->prepos; // 0x2AC(r29)
    Sbcore* cd = &act->sbcore; // r17
    sceVu0FVECTOR v; // 0xA0(r29)
    float ftmp; // 0x2B0(r29)
    signed int tmp; // r23
    signed int b; // r22
    Plane plane_reserve; // 0xB0(r29)
    sceVu0FVECTOR wnor = {0.0f, -1.0f, 0.0f, 0.0f}; // 0xE0(r29)
    signed int next_no; // r30
    signed int now_no; // 0x2B4(r29)
    sceVu0FVECTOR gr_nor; // 0xF0(r29)
    sceVu0FMATRIX m; // 0x100(r29)
    sceVu0FMATRIX m2; // 0x140(r29)
    sceVu0FVECTOR lv; // 0x180(r29)
    float roty; // 0x2B8(r29)
    float rate; // 0x2BC(r29)
    signed int pid; // 0x2C0(r29)
    Rider* rider0; // 0x2C4(r29)
    Rider* rider1; // 0x2C8(r29)
    sceVu0FVECTOR sp0; // 0x190(r29)
    sceVu0FVECTOR sp1; // 0x1A0(r29)
    float splen0; // 0x2CC(r29)
    float splen1; // 0x2D0(r29)
    signed int pre_hp; // 0x2D4(r29)
    signed int on_slidable; // 0x2D8(r29)
    signed int bonk; // r21
    signed int out; // 0x2DC(r29)
    Col col_tmp; // 0x1B0(r29)
    sceVu0FVECTOR n; // 0x210(r29)
    sceVu0FVECTOR v1; // 0x220(r29)
    float len_hp; // 0x2E0(r29)
    float len_plane; // 0x2E4(r29)
    Col col; // 0x230(r29)
    sceVu0FVECTOR bonk_normal; // 0x290(r29)
    float len; // 0x2E8(r29)
    signed int i; // r20
    s32* volatile wnorPtr = &wnor; // 0x2EC(r29)

    (void)wnorPtr;
    ktactInitPos(next);
    act->trg_tumble_type = 0;
    act->trg_tumble_way = 0;
    act->trg_tumble_body = 0;
    act->end_grind = 0;
    act->end_manual = 0;
    act->trg_hopup = 0;
    act->trg_jumpup = 0;
    act->trg_touch = 0;
    act->trg_bonk = 0;
    act->trg_boost = 0;
    act->trg_rewind = 0;
    act->trg_hit_wall = 0;
    act->num_hit = 0;
    act->num_vec = 0;
    act->num_obj = 0;
    act->tumble_se_id = -1;
    act->no_approach_speed = 0;
    act->hop_vertical_plane = 0;
    act->trg_grind_name = 0;
    act->trg_change_grind = 0;
    act->pre_halfpiping = act->halfpiping;
    vktactNumHit = 0;
    vktactNumVec = 0;
    vktactNumObj = 0;
    vktactIsSliding = 0;
    vktactColHit = act->col_hit;
    vktactColVec = act->col_vec;
    vktactColObj = act->col_obj;
    vktactSlideWater = 0;
    vktactNumHit_body = 0;
    vktactNumObj_body = 0;
    vktactNumHit_head = 0;
    vktactNumObj_head = 0;
    if (!(rc->splenxz < 8.333333f)) {
        if ((act->sliding_state == essManual) && ((rc->mot.now.id == 0xA3) || (rc->mot.now.id == 0xA4))) {
            vktactSlideWater = 1;
        } else if ((act->sliding_state == essOnAir) && act->manual_ready && !act->water_manual && (act->manual_ready_no == 0x4B)) {
            vktactSlideWater = 1;
        }
    }
    if (act->rail_list) {
        act->pre_rail_list = act->rail_list;
    }
    *(__int128*)cd->speed = *(__int128*)rc->speed;
    cd->rot_pole = rc->rot_pole;
    cd->freefoot = act->cnt_freefoot > 0 ? 1 : 0;
    cd->limit_ang_down = ktactGetLimitAng_down(now->normal);
    cd->set_sp_normal = now->halfpipe ? 1 : 0;
    *(__int128*)cd->pos = *(__int128*)now->pos;
    *(__int128*)cd->pole = *(__int128*)rc->pole;
    cd->sliding = now->hit;
    cd->relief_gap = act->relief_gap;
    cd->height = now->hit ? 0.0f : (now->cross[1] - now->pos[1]);
    *(__int128*)cd->plane_sliding.normal = *(__int128*)now->normal;
    *(__int128*)cd->plane_sliding.cross = *(__int128*)now->cross;
    cd->plane_sliding.material = now->material;
    cd->plane_sliding.almighty1 = now->type;
    cd->plane_sliding.almighty2 = now->no;
    cd->move_head = vspModeData.num_window == 1 ? 1 : 0;
    if (act->tumble_type >= 2) {
        cd->move_head = 0;
    } else if (act->cnt_no_bodyhit > 0) {
        cd->move_head = 0;
    } else if (act->mot_flipping || act->mot_spflipping) {
        cd->move_head = 0;
    }
    if (act->forced_bailout) {
        cd->freefoot = 1;
    }
    act->noheight_reflect = 0;
    act->forced_bailout = 0;
    sbcoreInitPLANE(&plane_reserve);
    ktactProcReserveTumble(&plane_reserve, rc);
    if ((act->sliding_state == essPlant) && act->mot_planting) {
        ktactMoveAdjPos_halfpipe(next->pos, &act->col_plant, rc, now->pos, now->pos, 1);
        *(__int128*)rc->pole = *(__int128*)act->hp_normal;
        *(__int128*)act->plant_normal = *(__int128*)act->hp_normal;
        *(__int128*)next->normal = *(__int128*)act->hp_normal;
        *(__int128*)next->cross = *(__int128*)act->hp_cross;
        if (act->mot_planting) {
            rc->rot_pole = atan2f(next->normal[0], next->normal[2]);
        }
        next->hit = 1;
        cd->sliding = 1;
        cd->move = 1;
        act->shadow_posy = next->cross[1];
        tmp = rc->param->no;
        if (tmp >= 12) {
            tmp = vspenvEnv.mc.secret.create_character[tmp - 12].trick_type;
        }
        if (act->cnt_holding > vktactPlantTumbleFrame[tmp]) {
            act->trg_tumble_type = 3;
            act->trg_tumble_way = 2;
            act->tumble_se_id = 1;
            act->cnt_planttumble = 60;
            act->goofy = act->goofy ? 0 : 1;
            rc->rot_pole += 3.141592f;
            rc->rot_pole = rc->rot_pole < -3.141592f
                               ? 6.283184f + rc->rot_pole
                           : rc->rot_pole > 3.141592f
                               ? rc->rot_pole - 6.283184f
                               : rc->rot_pole;
        }
    } else if (act->sliding_state == essGrind) {
        now_no = act->rail_no;
        if (act->cnt_to_rail > 0) {
            *(__int128*)cd->pos = *(__int128*)act->rail_pos;
            cd->pos[1] -= cd->const_max_relief_gap;
        }
        if (act->cnt_to_rail > 0) {
            cd->pos[1] += cd->const_max_relief_gap;
            next_no = sbcoreSetNextPosOnVertexList(cd, act->rail_no, act->rail_list, act->num_rail_vertex);
            cd->pos[1] -= cd->const_max_relief_gap;
            if (act->cnt_to_rail > 1) {
                cd->nextpos[1] -= cd->const_max_relief_gap;
            } else {
                sceVu0Normalize(v, cd->pole);
                sceVu0ScaleVectorXYZ(&v[0], &v[0], cd->const_max_relief_gap);
                sceVu0AddVector(cd->nextpos, cd->nextpos, v);
            }
        } else {
            sceVu0Normalize(v, cd->pole);
            sceVu0ScaleVectorXYZ(v, v, cd->const_max_relief_gap);
            sceVu0SubVector(cd->pos, cd->pos, v);
            next_no = sbcoreSetNextPosOnVertexList(cd, act->rail_no, act->rail_list, act->num_rail_vertex);
            sceVu0AddVector(cd->pos, cd->pos, v);
        }
        if (next_no >= 0) {
            sceVu0SubVector(v, act->rail_list[next_no + 1], act->rail_list[next_no]);
        } else {
            sceVu0SubVector(v, act->rail_list[now_no + 1], act->rail_list[now_no]);
        }
        sceVu0UnitMatrix(m);
        roty = atan2f(-v[0], -v[2]);
        sceVu0RotMatrixY(m2, m, -roty);
        sceVu0ApplyMatrix(lv, m2, v);
        sceVu0RotMatrixX(m, m, 1.570796f);
        sceVu0ApplyMatrix(lv, m, lv);
        sceVu0InversMatrix(m2, m2);
        sceVu0ApplyMatrix(v, m2, lv);
        if (!(v[1] <= 0.0f)) {
            sceVu0ScaleVectorXYZ(v, v, -1.0f);
        }
        sceVu0Normalize(gr_nor, v);
        if (!act->cnt_to_rail) {
            sceVu0ScaleVector(v, gr_nor, cd->const_max_relief_gap);
            sceVu0AddVector(cd->nextpos, cd->nextpos, v);
        }
        if (act->cnt_to_rail > 0) {
            *(__int128*)act->rail_pos = *(__int128*)cd->nextpos;
            act->rail_pos[1] += cd->const_max_relief_gap;
            rate = 1.0f / (float)act->cnt_to_rail;
            *(__int128*)cd->pos = *(__int128*)now->pos;
            sceVu0InterVector(v, cd->nextpos, cd->pos, rate);
            *(__int128*)cd->nextpos = *(__int128*)v;
        }
        if (next_no < 0) {
            sbcoreMove(cd, 0);
        } else {
            sbcoreMove(cd, act->cnt_to_rail > 0 ? 2 : 1);
        }
        if (plane_reserve.available) {
            cd->move = 0;
            cd->plane_hit = plane_reserve;
        }
        if (cd->move && (vspModeData.num_window == 2)) {
            pid = rc->param->player;
            rider0 = vspRider[pid];
            rider1 = vspRider[(pid + 1) % 2];
            if (rider1->ctrl.act.sliding_state == essGrind) {
                b = ktactGetCharHitPlane(0, pid, cd->pos);
                if (b) {
                    *(__int128*)sp0 = *(__int128*)rider0->ctrl.speed;
                    *(__int128*)sp1 = *(__int128*)rider1->ctrl.speed;
                    splen0 = rider0->ctrl.splen;
                    splen1 = rider1->ctrl.splen;
                    sceVu0Normalize(sp0, sp0);
                    sceVu0Normalize(sp1, sp1);
                    tmp = 0;
                    ftmp = sceVu0InnerProduct(sp0, sp1);
                    if (ftmp > 0.0f) {
                        if (splen0 > splen1) {
                            splen1 *= 0.5f;
                        } else {
                            splen0 *= 0.5f;
                        }
                    } else {
                        ftmp = splen0 + splen1;
                        splen0 = -splen0;
                        splen1 = -splen1;
                        if (!(ftmp <= 13.888889f)) {
                            act->trg_tumble_type = 4;
                            act->trg_tumble_way = 0;
                            ktactReserveTumble2(rider1->pid, sp0, splen0, 4);
                            b = 0;
                            tmp = 2;
                        }
                    }
                    sceVu0ScaleVectorXYZ(sp0, sp0, splen1);
                    *(__int128*)rider0->ctrl.speed = *(__int128*)sp0;
                    *(__int128*)cd->speed = *(__int128*)sp0;
                    act->tumble_se_id = tmp;
                    if (b) {
                        sceVu0ScaleVectorXYZ(sp1, sp1, splen0);
                        *(__int128*)rider1->ctrl.speed = *(__int128*)sp1;
                    }
                }
            }
        }
        if (cd->move) {
            next->hit = cd->sliding;
            rc->rot_pole = cd->rot_pole;
            *(__int128*)next->pos = *(__int128*)cd->pos;
            *(__int128*)rc->pole = *(__int128*)cd->pole;
            *(__int128*)rc->speed = *(__int128*)cd->speed;
            act->relief_gap = cd->relief_gap;
            if (cd->plane_sliding.available) {
                act->shadow_posy = cd->plane_sliding.cross[1];
            }
            *(__int128*)next->normal = *(__int128*)cd->plane_sliding.normal;
            *(__int128*)next->cross = *(__int128*)cd->plane_sliding.cross;
            if (next_no < 0) {
                next->material = cd->plane_sliding.material;
            } else {
                next->material = act->col_rail.attr & 0x7FF;
            }
            next->type = cd->plane_sliding.almighty1;
            next->no = cd->plane_sliding.almighty2;
            if (!next->type) {
                next->halfpipe = (next->material & 0x2000) ? 1 : 0;
                next->bonk = (next->material & 0x4000) ? 1 : 0;
            } else if (next->type == 3) {
                next->halfpipe = (next->material & 0x2000) ? 1 : 0;
                next->bonk = (next->material & 0x4000) ? 1 : 0;
            } else if (next->type == 7) {
                next->halfpipe = (next->material & 0x2000) ? 1 : 0;
                next->bonk = (next->material & 0x4000) ? 1 : 0;
            }
            next->low_g = 0;
            *(__int128*)rc->pole = *(__int128*)next->normal;
            rc->rot_pole = atan2f(-rc->speed[0], -rc->speed[2]);
            if (act->gr_is_reverse) {
                rc->rot_pole += 3.141592f;
                rc->rot_pole = rc->rot_pole < -3.141592f
                                   ? 6.283184f + rc->rot_pole
                               : rc->rot_pole > 3.141592f
                                   ? rc->rot_pole - 6.283184f
                                   : rc->rot_pole;
            }
            if (next_no >= 0) {
                *(__int128*)next->normal = *(__int128*)gr_nor;
                *(__int128*)rc->pole = *(__int128*)next->normal;
            }
        } else {
            ktactMoveCrash(rc, cd);
            next_no = -1;
        }
        if (next_no < 0) {
            act->rail_list = 0;
            act->col_rail.vertex = 0;
            act->col_plant.vertex = 0;
            act->rail_id = -1;
        } else {
            act->rail_no = next_no;
            if (!act->cnt_to_rail) {
                *(__int128*)act->rail_pos = *(__int128*)next->pos;
                act->rail_pos[1] += cd->const_max_relief_gap;
            }
            *(__int128*)next->cross = *(__int128*)act->rail_pos;
        }
        act->halfpiping = 0;
        b = 0;
        if (!(act->gr_balance.balance < 0.34906578f)) {
            act->trg_tumble_way = 1;
            b = 1;
        } else if (act->gr_balance.balance <= -0.34906578f) {
            act->trg_tumble_way = 0;
            b = 1;
        }
        if (b) {
            act->trg_tumble_type = 3;
            act->rail_list = 0;
            act->num_rail_vertex = 0;
            act->rail_id = -1;
        }
    } else {
        pre_hp = act->halfpiping;
        on_slidable = 1;
        bonk = 0;
        if ((act->sliding_state == essPlant) && act->halfpiping) {
            cd->sliding = 0;
        } else if (cd->plane_sliding.available) {
            on_slidable = cd->plane_sliding.slidable;
        }
        ktactSetNextPos(cd, rc);
        if (act->col_hp.vertex && (!now->hit || !on_slidable) && ((act->col_hp.attr & 0x1800) || !act->over_hp)) {
            if (!act->halfpiping) {
                if (pre->halfpipe || (act->pre_state == essGrind) || (act->col_hp.attr & 0x800)) {
                    ktactMoveAdjPos_halfpipe(cd->nextpos, &act->col_hp, rc, cd->pos, cd->nextpos, 0);
                }
            }
            act->halfpiping = 1;
        } else {
            act->halfpiping = 0;
        }
        sbcoreMove(cd, 0);
        if (cd->plane_sliding.available) {
            on_slidable = cd->plane_sliding.slidable;
        } else {
            on_slidable = 1;
        }
        if (cd->move) {
            ktactGetCharHitPlane(&plane_reserve, rc->param->player, cd->pos);
        }
        if (plane_reserve.available) {
            cd->move = 0;
            cd->plane_hit = plane_reserve;
        }
        if (!act->halfpiping) {
            ktactGetHit_hp(now->pos, cd->pos, &act->col_zhp);
            if (!act->col_zhp.vertex || !(act->col_zhp.attr & 0x800)) {
                act->col_zhp.vertex = 0;
                act->col_zhp.len = -1.0f;
            }
        }
        b = 0;
        out = 0;
        if (act->col_zhp.vertex) {
            act->col_hp = act->col_zhp;
        } else {
            b = ktactGetHit_out(&col_tmp, now->pos, cd->pos);
            if (b) {
                act->col_hp = col_tmp;
                act->col_zhp = col_tmp;
                out = 1;
            }
        }
        if (cd->move && (!act->halfpiping || out) && act->col_hp.vertex) {
            if (out) {
                b = 1;
                if (now->hit) {
                    sceVu0SubVector(v, act->col_hp.vertex[act->col_hp.no + 1], act->col_hp.vertex[act->col_hp.no]);
                    sceVu0SubVector(v1, now->pos, act->col_hp.vertex[act->col_hp.no]);
                    v[1] = 0.0f;
                    v1[1] = 0.0f;
                    sceVu0OuterProduct(n, v1, v);
                    sceVu0OuterProduct(n, v, n);
                    ftmp = sceVu0InnerProduct(n, now->normal);
                    if (ftmp < 0.0f) {
                        b = 0;
                    }
                }
            } else if (act->col_hp.attr & 0x800) {
                b = 1;
                if (act->col_zhp.vertex && !now->hit) {
                    b = 0;
                }
            } else if ((act->col_hp.attr & 0x1000) || !act->over_hp) {
                if (now->halfpipe && cd->sliding) {
                    b = 1;
                }
            }
        }
        if (b) {
            sceVu0SubVector(v, act->col_hp.point, cd->pos);
            len_hp = sceVu0InnerProduct(v, v);
            sceVu0SubVector(v, cd->plane_sliding.cross, cd->pos);
            len_plane = sceVu0InnerProduct(v, v);
            if (len_hp <= len_plane) {
                if (act->col_hp.attr & 0x800) {
                    ktactMoveAdjPos_halfpipe(cd->pos, &act->col_hp, rc, now->pos, cd->pos, 0);
                } else {
                    ktactMoveAdjPos_halfpipe(v, &act->col_hp, rc, now->pos, cd->pos, 0);
                }
                act->halfpiping = 1;
                cd->sliding = 0;
            }
        }
        if (cd->plane_sliding.available && cd->move && cd->sliding) {
            ktactProcVerticalPlane(cd, rc, &cd->plane_sliding);
            if (!cd->move) {
                cd->sliding = 1;
                ktactMergeHitList(rc, cd, 0, now->pos, cd->pos);
                cd->sliding = 0;
            }
        }
        if (cd->move && !act->halfpiping && act->col_zhp.vertex) {
            if (!now->halfpipe && now->hit) {
                b = 1;
            } else if (!now->hit) {
                b = 1;
            } else {
                b = 0;
            }
            if (b) {
                sceVu0SubVector(v, cd->pos, now->pos);
                ktactRail2SbcorePlane(&cd->plane_hit, &act->col_zhp, v);
                cd->move = 0;
            }
        }
        if (cd->move && !act->halfpiping) {
            if (!now->halfpipe || (now->halfpipe && on_slidable)) {
                cd->move = ktactCheckWall(&cd->plane_hit, cd, now);
                if (!cd->move && (vktactNumHit < 16) && (cd->plane_sliding.almighty1 == 3)) {
                    ktactSbcorePlane2TmcrsCol(&col, &cd->plane_sliding);
                    act->col_hit[vktactNumHit++] = col;
                }
            }
        }
        if (cd->move) {
            ktactMergeHitList(rc, cd, 1, now->pos, cd->pos);
        } else if (cd->move_head) {
            if (vktactNumHit_head > 0) {
                vktactNumHit = ktactMergeHitList_1(act->col_hit, vktactNumHit, vktactColHit_head, vktactNumHit_head, 2);
            }
            if (vktactNumObj_head > 0) {
                vktactNumObj = ktactMergeHitList_1(act->col_obj, vktactNumObj, vktactColObj_head, vktactNumObj_head, 2);
            }
        }
        bonk = 0;
        if (cd->move) {
            next->hit = cd->sliding;
            rc->rot_pole = cd->rot_pole;
            if (!on_slidable) {
                next->hit = 0;
            }
            *(__int128*)next->pos = *(__int128*)cd->pos;
            *(__int128*)next->normal = *(__int128*)cd->plane_sliding.normal;
            *(__int128*)next->cross = *(__int128*)cd->plane_sliding.cross;
            next->material = cd->plane_sliding.material;
            next->type = cd->plane_sliding.almighty1;
            next->no = cd->plane_sliding.almighty2;
            if (!next->type) {
                next->halfpipe = (next->material & 0x2000) ? 1 : 0;
                next->bonk = (next->material & 0x4000) ? 1 : 0;
                next->low_g = (next->material & 0x1000) ? 1 : 0;
            } else if (next->type == 3) {
                next->halfpipe = (next->material & 0x2000) ? 1 : 0;
                next->bonk = (next->material & 0x4000) ? 1 : 0;
                next->low_g = (next->material & 0x1000) ? 1 : 0;
            } else if (next->type == 7) {
                next->halfpipe = (next->material & 0x2000) ? 1 : 0;
                next->bonk = (next->material & 0x4000) ? 1 : 0;
                next->low_g = 0;
            }
            if (act->bonk_ready && !act->mot_grabing && !act->mot_flipping && !act->mot_spflipping) {
                if (next->hit && next->bonk) {
                    bonk = 1;
                    *(__int128*)bonk_normal = *(__int128*)cd->plane_sliding.normal;
                    *(__int128*)v = *(__int128*)cd->plane_sliding.cross;
                } else {
                    len = 16777000.0f;
                    for (i = 0; i < vktactNumObj; i++) {
                        if ((act->col_obj[i].attr & 0x4000) && (act->col_obj[i].len < len)) {
                            bonk = 1;
                            *(__int128*)bonk_normal = *(__int128*)act->col_obj[i].normal;
                            *(__int128*)v = *(__int128*)act->col_obj[i].point;
                        }
                    }
                }
                if (bonk) {
                    ftmp = sbcoreGetInnerAngle180(wnor, rc->pole);
                    if (!(ftmp <= vktactMatTumbleAng_touch[1])) {
                        bonk = 0;
                    }
                    if (rc->speed[1] < 0.0f) {
                        bonk = 0;
                    }
                    if (act->trg_tumble_type >= 2) {
                        bonk = 0;
                    }
                    if (v[1] <= now->pos[1]) {
                        bonk = 0;
                    }
                }
            }
            *(__int128*)rc->speed = *(__int128*)cd->speed;
            act->relief_gap = cd->relief_gap;
            if (!now->hit && next->hit && !bonk) {
                ktactUpdateFlipPole(rc);
                ktactSetCrashPow_touch(rc, &cd->plane_sliding, next->halfpipe);
                *(__int128*)rc->pole = *(__int128*)next->normal;
            } else if (!bonk) {
                *(__int128*)rc->pole = *(__int128*)cd->pole;
            }
            if (act->halfpiping) {
                if (pre_hp) {
                    sceVu0ScaleVector(v, cd->pole, cd->const_max_relief_gap);
                    sceVu0SubVector(act->hp_cross, next->pos, v);
                    *(__int128*)act->hp_normal = *(__int128*)cd->pole;
                } else {
                    *(__int128*)next->normal = *(__int128*)act->hp_normal;
                    *(__int128*)next->cross = *(__int128*)act->hp_cross;
                    *(__int128*)rc->pole = *(__int128*)next->normal;
                }
            } else if (!next->hit && !next->halfpipe && !act->hp_air && act->hp_jump) {
                act->hp_jump = 0;
            }
            if (bonk) {
                *(__int128*)rc->speed = *(__int128*)act->bonk_presp;
                ftmp = iktactGetLenXZ(rc->speed);
                if (ftmp < 8.333333f) {
                    rc->speed[1] = 0.0f;
                    sceVu0Normalize(rc->speed, rc->speed);
                    sceVu0ScaleVector(rc->speed, rc->speed, 8.333333f);
                }
                rc->speed[1] = -11.111111f;
                next->hit = 0;
                act->trg_bonk = 1;
                act->trg_touch = 1;
                act->bonk_ready = 0;
                act->manual_ready = 0;
                act->bonk_goto = 0;
                act->revert_cnt_ready = 0;
            }
            if (!bonk && (act->cnt_quit < 0) && !act->mot_flipping && !act->mot_spflipping && (act->sliding_state != essSitting) && !act->cnt_no_bodyhit) {
                ktactProcHitBody(rc, &cd->plane_body, next);
            }
        } else {
            if (act->bonk_ready && !act->mot_grabing && !act->mot_flipping && !act->mot_spflipping) {
                if (cd->plane_hit.almighty1 == 0) {
                    if (cd->plane_hit.material & 0x4000) {
                        bonk = 1;
                    }
                } else if ((cd->plane_hit.almighty1 == 3) || (cd->plane_hit.almighty1 == 7)) {
                    if (cd->plane_hit.material & 0x4000) {
                        bonk = 1;
                    }
                }
                if (bonk) {
                    ftmp = sbcoreGetInnerAngle180(wnor, rc->pole);
                    if (!(ftmp <= vktactMatTumbleAng_touch[1])) {
                        bonk = 0;
                    }
                    if (rc->speed[1] < 0.0f) {
                        bonk = 0;
                    }
                }
            }
            if (bonk) {
                *(__int128*)rc->speed = *(__int128*)act->bonk_presp;
                ftmp = iktactGetLenXZ(rc->speed);
                if (ftmp < 8.333333f) {
                    rc->speed[1] = 0.0f;
                    sceVu0Normalize(rc->speed, rc->speed);
                    sceVu0ScaleVector(rc->speed, rc->speed, 8.333333f);
                }
                rc->speed[1] = -11.111111f;
                *next = *now;
                act->trg_bonk = 1;
                act->trg_touch = 1;
                act->bonk_ready = 0;
                act->manual_ready = 0;
                act->bonk_goto = 0;
                act->revert_cnt_ready = 0;
            } else {
                ktactMoveCrash(rc, cd);
                act->bonk_ready = 0;
                act->bonk_goto = 0;
                act->manual_ready = 0;
                act->revert_cnt_ready = 0;
            }
            act->col_hp.vertex = 0;
            act->col_zhp.vertex = 0;
            act->col_rail.vertex = 0;
            act->col_plant.vertex = 0;
            act->rail_list = 0;
            act->rail_id = -1;
            act->hp_air = 0;
            act->halfpiping = 0;
        }
        act->shadow_posy = next->cross[1];
        ktactCheckManual(rc, next);
        ktactForcedBailout(rc);
    }
    if (act->reserve_tumble && (act->reserve_tumble_speed > 0.0f)) {
    }
    tmp = tmcrsCheckObjectCollision(now->pos, next->pos, act->trg_bonk);
    if (tmp > 0) {
        act->num_total_break += tmp;
    }
    rc->prepos2 = rc->prepos;
    rc->prepos = *now;
    *now = *next;
    act->num_hit = vktactNumHit;
    act->num_vec = vktactNumVec;
    act->num_obj = vktactNumObj;
    if (act->reserve_fall) {
        act->reserve_fall = 0;
        act->cnt_fall = 120;
        act->trg_tumble_type = 5;
        act->trg_tumble_way = 2;
    }
}

static void ktactSetNextPos(Sbcore* cd, Ctrl* rc) {
    Act* act; // r16
    Pos* now; // r17
    signed int next_no; // r18
    signed int b; // r19
    float area0[4]; // 0x50(r29)
    float area1[4]; // 0x60(r29)
    float hpfrom[4]; // 0x70(r29)
    float hpto[4]; // 0x80(r29)
    float pole[4]; // 0x90(r29)
    float lwm[4][4]; // 0xA0(r29)
    float sp[4]; // 0xE0(r29)
    float hang_sp[4]; // 0xF0(r29)
    float bottom; // 0x108(r29)
    float top; // 0x10C(r29)

    act = &rc->act;
    now = &rc->nowpos;
    bottom = act->sbcore.const_max_relief_gap;
    top = -20.0f;
    act->col_rail.vertex = 0;
    act->col_plant.vertex = 0;
    if ((act->col_hp.vertex != 0) && (act->halfpiping != 0) && (now->hit == 0)) {
        next_no = sbcoreSetNextPosOnVertexListHP(cd, act->col_hp.no, act->col_hp.vertex, act->col_hp.nvertex);
        if (next_no < 0) {
            act->col_hp.vertex = 0;
            act->col_hp.len = -1.0f;
            act->col_hp.no = -1;
            act->halfpiping = 0;
            act->col_zhp.vertex = 0;
            act->col_zhp.len = -1.0f;
            act->col_zhp.no = -1;
        } else {
            act->col_hp.no = next_no;
        }
        *(__int128*)hpfrom = *(__int128*)cd->nextpos;
        *(__int128*)hpto = *(__int128*)cd->nextpos;
        ktactGetHit_rail_hp(cd->pos, cd->nextpos, &hpfrom, &hpto, &act->col_rail, &act->col_plant, 0);
        if (next_no < 0) {
            *(__int128*)pole = *(__int128*)rc->pole;
            pole[1] = 0.0f;
            sceVu0Normalize(&pole, &pole);
            area0[0] = 0.0f;
            area0[1] = top;
            area0[2] = 0.0f;
            area0[3] = 1.0f;
            area1[0] = 0.0f;
            area1[1] = bottom;
            area1[2] = 0.0f;
            area1[3] = 1.0f;
            sbcoreGetRotMatrix(lwm, pole, rc->rot_pole);
            sceVu0TransMatrix(lwm, lwm, cd->nextpos);
            sceVu0ApplyMatrix(&hpfrom, &lwm, &area0[0]);
            sceVu0ApplyMatrix(&hpto, &lwm, &area1[0]);
            b = ktactGetHit_out(&act->col_hp, &hpfrom, &hpto);
            if (b) {
                act->col_zhp = act->col_hp;
            }
        }
    } else {
        if (act->sliding_state == 3) {
            hang_sp[0] = rc->speed[0] * act->hang_rate;
            hang_sp[2] = rc->speed[2] * act->hang_rate;
            hang_sp[1] = rc->speed[1] * act->hang_rate;
            *(__int128*)sp = *(__int128*)cd->speed;
            *(__int128*)cd->speed = *(__int128*)hang_sp;
            sbcoreSetNextPos(cd);
            *(__int128*)cd->speed = *(__int128*)sp;
        } else {
            sbcoreSetNextPos(cd);
        }
        bottom += 5.0f;
        if ((act->hp_jump != 0) || ((now->hit != 0) && (act->pre_state != 5))) {
            *(__int128*)pole = *(__int128*)rc->pole;
            pole[1] = 0.0f;
            sceVu0Normalize(&pole, &pole);
            area0[0] = 0.0f;
            area0[1] = top;
            area0[2] = 0.0f;
            area0[3] = 1.0f;
            area1[0] = 0.0f;
            area1[1] = bottom;
            area1[2] = 0.0f;
            area1[3] = 1.0f;
            sbcoreGetRotMatrix(&lwm, &pole, rc->rot_pole);
            sceVu0TransMatrix(lwm, lwm, cd->nextpos);
            sceVu0ApplyMatrix(&hpfrom, &lwm, &area0[0]);
            sceVu0ApplyMatrix(&hpto, &lwm, &area1[0]);
        } else {
            *(__int128*)hpfrom = *(__int128*)cd->nextpos;
            *(__int128*)hpto = *(__int128*)cd->nextpos;
        }
        ktactGetHit_rail_hp(cd->pos, cd->nextpos, &hpfrom, &hpto, &act->col_rail, &act->col_plant, &act->col_hp);
    }
}

static signed int ktactMoveAdjPos_halfpipe(sceVu0FVECTOR next, Col* col, Ctrl* rc, sceVu0FVECTOR from, sceVu0FVECTOR to, signed int unused1) {
    /* next: sp50, col: sp60, rc: sp70, from: sp80, to: sp90 */
    signed int no; // r16
    sceVu0FVECTOR v; // 0x20(r29)
    sceVu0FVECTOR vv; // 0x30(r29)
    sceVu0FVECTOR nor; // 0x40(r29)

    if (col->vertex[0] == 0) {
        *(__int128*)next = *(__int128*)to;
        return 0;
    }
    no = col->no;
    if (no >= (col->nvertex - 1)) {
        no = col->nvertex - 2;
    }
    sceVu0SubVector(vv, col->vertex[no], col->vertex[no + 1]);
    sceVu0SubVector(v, from, col->vertex[no + 1]);
    v[1] = 0.0f;
    vv[1] = 0.0f;
    sceVu0Normalize(&v, &v);
    sceVu0Normalize(&vv, &vv);
    sceVu0OuterProduct(&nor, &v, &vv);
    sceVu0OuterProduct(&nor, &vv, &nor);
    sceVu0Normalize(&nor, &nor);
    sceVu0ScaleVector(v, nor, rc->act.sbcore.const_max_relief_gap);
    sceVu0AddVector(next, col->point, v);
    next[3] = 1.0f;
    *(__int128*)&rc->act.hp_normal = *(__int128*)&nor;
    *(__int128*)&rc->act.hp_cross = *(__int128*)&col->point;
    return 1;
}

static void ktactMoveCrash(Ctrl* rc, Sbcore* cd) {
    Act* act = &rc->act;
    Plane* plane_hit = &cd->plane_hit;
    Plane* plane_sliding = &cd->plane_sliding;
    signed int hp = rc->nowpos.halfpipe;

    if (plane_hit->available != 0) {
        switch (act->sliding_state) {
            case essOnAir:
            case essTumble:
                if (plane_hit->attribute == 0 && plane_hit->slidable) {
                    ktactUpdateFlipPole(rc);
                    ktactSetCrashPow_touch(rc, plane_hit, hp);
                    *(__int128*)rc->pole = *(__int128*)plane_hit->normal;
                    break;
                }
            default:
                ktactSetCrashPow_normal(rc, plane_hit);
                break;
        }
    } else if (plane_sliding->available != 0 && plane_sliding->attribute) {
        ktactSetCrashPow_normal(rc, plane_sliding);
    } else if (act->cnt_fall == 0) {
        ktactGetNoheightReflection(rc->speed, rc, rc->nowpos.normal, rc->speed);
        act->noheight_reflect = 1;
    } else {
        rc->speed[0] = 0.0f;
        rc->speed[2] = 0.0f;
    }
    rc->nextpos = rc->nowpos;
}

static void ktactGetNoheightReflection(float* out, Ctrl* unused1, float* nor, float* in) {
    float sp[4];
    float splen;
    float ftmp;

    *(__int128*)sp = *(__int128*)in;
    {
        float wnor[4] = {0.0f, -1.0f, 0.0f, 0.0f};
        float* unused2 = wnor;

        splen = iktactGetLen(sp);
        if (splen < 16.666666f) {
            splen = 16.666666f;
        }
        sceVu0ScaleVector(sp, sp, -1.0f);
        ftmp = sceVu0InnerProduct(nor, sp);
        if (ftmp < 0.0f) {
            sbcoreGetShadowVector(sp, nor, sp);
        }
        sceVu0Normalize(sp, sp);
        sceVu0AddVector(sp, sp, wnor);
        sceVu0Normalize(sp, sp);
        sceVu0ScaleVectorXYZ(sp, sp, splen);
        sp[3] = 1.0f;
        *(__int128*)out = *(__int128*)sp;
    }
}

static signed int ktactCheckWall(Plane* plane, Sbcore* cd, Pos* now) {
    float wnor[4] = {0.0f, -1.0f, 0.0f, 0.0f};
    float* unused1 = wnor;
    signed int ok = 1;
    signed int hp = 0;
    Plane* pl = &cd->plane_sliding;
    Plane p;
    float nownor[4];
    float nextnor[4];
    float move[4];
    float ftmp;
    float ang;

    if (cd->sliding == 0) {
        return 1;
    }
    sceVu0Normalize(nownor, now->normal);
    sceVu0Normalize(nextnor, pl->normal);
    sceVu0SubVector(move, cd->nextpos, now->pos);
    ang = sceVu0InnerProduct(move, nextnor);
    if (!(ang < 0.0f)) {
        return 1;
    }
    if (pl->almighty1 == 0) {
        if (pl->material & 0x2000) {
            hp = 1;
        }
    } else if ((pl->almighty1 == 3 || pl->almighty1 == 7) && (pl->material & 0x2000)) {
        hp = 1;
    }
    if (now->hit != 0) {
        if (nownor[0] != nextnor[0] || nownor[1] != nextnor[1] || nownor[2] != nextnor[2]) {
            if (pl->attribute == 2 && hp == 0) {
                ok = 0;
            } else {
                ftmp = sceVu0InnerProduct(move, nextnor);
                if (!(ftmp < 0.0f)) {
                }
            }
        }
    } else if (pl->attribute && hp == 0) {
        ok = 0;
    }
    if (!pl->slidable) {
        ok = 0;
    }
    if (ok == 0) {
        if (pl->attribute == 2) {
            *plane = *pl;
            plane->slidable = 0;
        } else {
            ktactGetWallPlane(&p, nownor, pl, move);
            ang = sceVu0InnerProduct(p.normal, nextnor);
            if (!(ang <= 0.0f)) {
                *plane = p;
            } else {
                ok = 1;
            }
        }
    }
    return ok;
}

static void ktactGetWallPlane(Plane* plane, float* now, Plane* next, float* move) {
    Plane p; // 0x10(r29)
    float nownor[4]; // 0x40(r29)
    float nextnor[4]; // 0x50(r29)
    float nor[4]; // 0x60(r29)
    float ang; // 0x78(r29)
    float ftmp; // 0x7C(r29)

    sceVu0Normalize(nownor, now);
    sceVu0Normalize(nextnor, next->normal);
    sceVu0OuterProduct(nor, nownor, nextnor);
    ftmp = nor[0];
    nor[0] = -nor[2];
    nor[1] = 0.0f;
    nor[2] = ftmp;
    ang = sceVu0InnerProduct(move, nor);
    if (ang > 0.0f) {
        sceVu0ScaleVector(nor, nor, -1.0f);
    }
    sceVu0Normalize(p.normal, nor);
    *(__int128*)&p.cross = *(__int128*)&next->cross;
    p.material = next->material;
    p.attribute = next->attribute;
    p.almighty1 = next->almighty1;
    p.almighty2 = next->almighty2;
    p.almighty3 = next->almighty3;
    p.slidable = 0;
    p.available = 1;
    *plane = p;
}

static signed int ktactCheckShadow(Act* act, signed int shadow) {
    signed int var_s1;

    signed int i; // r16

    if (act->sbcore.move != 0) {
        for (i = 0; i < act->num_hit; i++) {
            if (act->col_hit[i].no == 8) {
                shadow = 1;
            } else if (act->col_hit[i].no == 9) {
                shadow = 0;
            }
        }
        for (i = 0; i < act->num_vec; i++) {
            if ((act->col_vec[i].attr & 0x7FF) == 0x19) {
                if (shadow != 0) {
                    var_s1 = 0;
                } else {
                    var_s1 = 1;
                }
                shadow = var_s1;
            }
        }
    }
    return shadow;
}

static void ktactProcHitBody(Ctrl* rc, Plane* plane, Pos* pos) {
    Act* act = &rc->act;
    float splen_totter;
    float splen;
    float tsumazuki_height;
    float len;
    signed int raliat;
    signed int tumble;
    float v[4];

    splen_totter = pos->hit ? 13.888889f : 6.9444447f;
    splen = pos->hit ? rc->splen : rc->splenxz;
    tsumazuki_height = 5.0f;
    raliat = 1;
    tumble = 0;
    if (plane->available != 0) {
        if (act->trg_tumble_type >= 2 || act->tumble_type >= 2) {
            return;
        }
        if (pos->hit != 0) {
            sceVu0SubVector(v, plane->cross, pos->pos);
            len = iktactGetLen(v);
            if (len < tsumazuki_height) {
                raliat = 0;
            }
        }
        if (!(splen <= splen_totter)) {
            tumble = 1;
        } else if (plane->almighty1 == 7 && (plane->almighty3 & 0x8000)) {
            tumble = 1;
        }
        if (tumble != 0) {
            act->trg_tumble_type = 3;
            act->trg_tumble_way = raliat ? 3 : 2;
            act->tumble_se_id = 3;
            act->trg_tumble_body = 1;
            sceVu0ScaleVectorXYZ(rc->speed, rc->speed, vktactTTCrashSpDown_touch[act->trg_tumble_type]);
            return;
        }
        if (act->tumble_type == 0) {
            act->trg_tumble_type = 1;
            act->trg_tumble_way = raliat ? 3 : 2;
            act->trg_tumble_body = 1;
            act->tumble_se_id = 4;
            sceVu0ScaleVectorXYZ(rc->speed, rc->speed, vktactTTCrashSpDown_touch[act->trg_tumble_type]);
        }
    }
}

static void ktactProcVerticalPlane(Sbcore* cd, Ctrl* rc, Plane* plane) {
    Act* act = &rc->act; // r18
    float wnor[4] = {0.0f, -1.0f, 0.0f, 0.0f}; // 0xA0(r29)
    s32* wnorPtr = &wnor;
    signed int material = plane->material; // r16
    signed int type = plane->almighty1; // r19
    signed int hp = 0; // r17
    float ang; // 0xB8(r29)
    Sliding_State state = act->sliding_state; // r30
    volatile signed int unable_material; // 0xBC(r29)

    (void)wnorPtr;
    if (cd->sliding == 0 || cd->move == 0) {
        return;
    }
    if (type == 0) {
        hp = (material & 0x2000) ? 1 : 0;
    } else if (type == 3) {
        hp = (material & 0x2000) ? 1 : 0;
    } else if (type == 7) {
        hp = (material & 0x2000) ? 1 : 0;
    }
    ang = sbcoreGetInnerAngle180(wnor, plane->normal);
    if (!(ang <= 1.2217302f)) {
        if (state == essOnAir) {
            ang = sbcoreGetInnerAngle180(plane->normal, rc->speed);
            if (!(ang < 1.570796f) && act->hp_air == 0 && hp == 0) {
                cd->plane_hit = *plane;
                cd->sliding = 0;
                cd->move = 0;
            }
        } else {
            unable_material = 1;
            if (!(material & 0x7FF)) {
                unable_material = 0;
            }
        }
    }
}

// ktact.c
static void ktactCheckManual(Ctrl* rc, Pos* next) {
    Act* act; // r16
    signed int reverse_speed; // r17
    sceVu0FMATRIX mat; // 0x30(r29)
    sceVu0FVECTOR lsp; // 0x70(r29)
    float ang; // 0x88(r29)
    float balance; // 0x8C(r29)

    act = &rc->act;
    reverse_speed = 0;
    if (act->sliding_state == 4) {
        sbcoreGetRotMatrix(mat, rc->pole, rc->rot_pole);
        sceVu0InversMatrix(&mat, &mat);
        sceVu0ApplyMatrix(lsp, mat, rc->speed);
        ang = atan2f(-lsp[0], -lsp[2]);
        if (!(ang <= 1.570796f) || (ang < -1.570796f)) {
            reverse_speed = 1;
        }
        if (reverse_speed != 0) {
            act->end_manual = 1;
            return;
        }
        if (act->cnt_warp <= 0) {
            if (((act->reserve_quit != 0) || (act->cnt_quit >= 0)) && (act->allow_tlink == 0)) {
                act->end_manual = 1;
                return;
            }
            balance = act->manu_balance.balance;
            switch (rc->mot.now.id) { /* irregular */
                case 0xA3:
                case 0xA4:
                    if ((next->material & 0x7FF) == 8) {
                        act->water_manual = 1;
                    }
                    if (!(balance < 0.34906578f)) {
                        act->trg_tumble_type = 2;
                        act->trg_tumble_way = 3;
                        act->tumble_se_id = 0;
                        return;
                    }
                    if (balance <= -0.34906578f) {
                        act->end_manual = 1;
                        return;
                    }
                    break;
                case 0xA7:
                case 0xA8:
                    if (!(balance < 0.34906578f)) {
                        act->end_manual = 1;
                        return;
                    }
                    if (balance <= -0.34906578f) {
                        act->trg_tumble_type = 2;
                        act->trg_tumble_way = 2;
                        act->tumble_se_id = 0;
                        return;
                    }
                    break;
                case 0x7D:
                case 0x7E:
                    balance = -balance;
                    // break;
                case 0xA5:
                case 0xA6:
                case 0xA9:
                case 0xAA:
                case 0x7A:
                case 0x7B:
                default:
                    if (!(balance < 0.34906578f)) {
                        act->trg_tumble_type = 2;
                        act->trg_tumble_way = 3;
                        act->tumble_se_id = 0;
                        return;
                    }
                    if (balance <= -0.34906578f) {
                        act->trg_tumble_type = 2;
                        act->trg_tumble_way = 2;
                        act->tumble_se_id = 0;
                    }
                    break;
            }
        }
    }
}

// ktact.c
static void ktactMergeHitList(Ctrl* rc, Sbcore* cd, signed int body, float* prepos, float* nowpos) {
    Act* act = &rc->act; // r16

    if (vktactNumHit > 0) {
        vktactNumHit = ktactMergeHitList_0(act->col_hit, vktactNumHit, prepos, nowpos, cd->move);
    }
    if (vktactNumObj > 0) {
        vktactNumObj = ktactMergeHitList_0(act->col_obj, vktactNumObj, prepos, nowpos, cd->move);
    }
    if ((cd->sliding != 0) && (vktactIsSliding != 0)) {
        switch (vktactColSliding.res[0]) {
            case 3:
                vktactNumHit = ktactMergeHitList_1(act->col_hit, vktactNumHit, &vktactColSliding, 1, 1);
                break;
            case 7:
                vktactNumObj = ktactMergeHitList_1(act->col_obj, vktactNumObj, &vktactColSliding, 1, 0);
                break;
        }
    }
    if ((body != 0) && (act->tumble_type < 2)) {
        if (vktactNumHit_body > 0) {
            vktactNumHit = ktactMergeHitList_1(act->col_hit, vktactNumHit, vktactColHit_body, vktactNumHit_body, 2);
        }
        if (vktactNumHit_head > 0) {
            vktactNumHit = ktactMergeHitList_1(act->col_hit, vktactNumHit, vktactColHit_head, vktactNumHit_head, 2);
        }
        if (vktactNumObj_body > 0) {
            vktactNumObj = ktactMergeHitList_1(act->col_obj, vktactNumObj, vktactColObj_body, vktactNumObj_body, 2);
        }
        if (vktactNumObj_head > 0) {
            vktactNumObj = ktactMergeHitList_1(act->col_obj, vktactNumObj, vktactColObj_head, vktactNumObj_head, 2);
        }
    }
}

// ktact.c
static signed int ktactMergeHitList_0(Col* list, signed int num_list, float* prepos, float* nowpos, signed int move) {
    // Size: 0x60, DWARF: 0x75E44
    Col* col0; // r16
    // Size: 0x60, DWARF: 0x75E44
    Col* col1; // r17
    signed int j; // r18
    signed int num_buff; // r19
    signed int i; // r20
    // Size: 0x60, DWARF: 0x75E44
    Col buff[16]; // 0x60(r29)
    float v0[4]; // 0x660(r29)
    float v1[4]; // 0x670(r29)
    float inner; // 0x68C(r29)

    sceVu0SubVector(&v0[0], prepos, nowpos);
    v0[3] = 0.0f;
    num_buff = 0;
    for (i = 0; i < num_list; i++) {
        col0 = &list[i];
        if (move != 0) {
            sceVu0SubVector(&v1[0], col0->point, nowpos);
            v1[3] = 0.0f;
            inner = sceVu0InnerProduct(&v0[0], &v1[0]);
            if (inner < 0.0f) {
                continue;
            }
        }
        for (j = 0; j < num_buff; j++) {
            col1 = &buff[j];
            if (col0->res[0] == 7) {
                if (col0->obj_no == col1->obj_no) {
                    break;
                }
            } else if ((col0->normal[0] == col1->normal[0]) && (col0->normal[1] == col1->normal[1]) && (col0->normal[2] == col1->normal[2]) && (col0->attr == col1->attr) && (col0->no == col1->no)) {
                break;
            }
        }
        if (j == num_buff) {
            buff[num_buff++] = *col0;
        }
    }
    for (i = 0; i < num_buff; i++) {
        list[i] = buff[i];
    }
    return num_buff;
}

static signed int ktactMergeHitList_1(Col* list, signed int num_list, Col* add, signed int num_add, signed int event) {
    Col* col0;
    Col* col1;
    signed int i;
    signed int j;
    signed int event_only;
    signed int no_event;

    event_only = (event == 1) ? 1 : 0;
    no_event = (event == 2) ? 1 : 0;
    for (i = 0; i < num_add; i++) {
        col0 = &add[i];
        if ((no_event == 0 || col0->no < 0x1F) && (event_only == 0 || col0->no >= 0x1F)) {
            for (j = 0; j < num_list; j++) {
                col1 = &list[j];
                if (col0->res[0] == 7) {
                    if (col0->obj_no == col1->obj_no) {
                        break;
                    }
                } else if (col0->normal[0] == col1->normal[0] && col0->normal[1] == col1->normal[1] && col0->normal[2] == col1->normal[2] && col0->attr == col1->attr && col0->no == col1->no) {
                    break;
                }
            }
            if (j == num_list) {
                if (num_list >= 0x10) {
                    break;
                }
                list[num_list++] = *col0;
            }
        }
    }
    return num_list;
}

// ktact.c
static void ktactForcedBailout(Ctrl* rc) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act; // r16
    sceVu0FVECTOR nor; // 0x80(r29)
    sceVu0FVECTOR snor; // 0x90(r29)
    sceVu0FVECTOR wnor1; // 0xA0(r29)
    sceVu0FVECTOR wnor2; // 0xB0(r29)
    signed int i; // r17
    signed int num; // r18
    // Size: 0x1F0, DWARF: 0x7B067
    Sbcore* cd; // r19
    signed int cnt_bailout; // r20
    signed int bailout; // r21
    float ftmp; // 0xCC(r29)

    act = &rc->act;
    cd = &act->sbcore;
    bailout = 0;
    cnt_bailout = (act->cnt_quit >= 0) ? 60 : 60;
    if (act->noheight_reflect) {
        act->cnt_hit_wall = 0;
        act->cnt_brank_hit_wall = 0;
        act->forced_bailout = 1;
    } else if (cd->move == 0) {
        act->cnt_brank_hit_wall = 0;
        act->cnt_hit_wall++;
        if (cd->plane_hit.available) {
            for (i = 9; i > 0; i--) {
                *(__int128*)act->last_hit_plane[i] = *(__int128*)act->last_hit_plane[i - 1];
            }
            *(__int128*)act->last_hit_plane[i] = *(__int128*)cd->plane_hit.normal;
        }
        if (!(act->cnt_hit_wall < cnt_bailout)) {
            bailout = 1;
        }
    } else if ((act->sliding_state != 8) || (act->tumble_type < 2)) {
        act->cnt_brank_hit_wall++;
        if (!(act->cnt_brank_hit_wall < 10)) {
            act->cnt_hit_wall = 0;
            act->cnt_brank_hit_wall = 0;
            act->cnt_forced_bailout = 0;
        }
    }
    if (act->noheight_reflect) {
        act->cnt_noheight_reflect++;
        act->cnt_brank_noheight_reflect = 0;
        if (!(act->cnt_noheight_reflect < 20) && !act->cnt_warp && !act->cnt_fall) {
            act->col_vec[vktactNumVec].attr = 0x1D;
            act->col_vec[vktactNumVec].len = 0.0f;
            vktactNumVec++;
            act->cnt_noheight_reflect = 0;
            act->cnt_brank_noheight_reflect = 0;
            act->cnt_forced_bailout = 0;
        }
    } else {
        act->cnt_brank_noheight_reflect++;
        if (!(act->cnt_brank_noheight_reflect < 10)) {
            act->cnt_noheight_reflect = 0;
            act->cnt_brank_noheight_reflect = 0;
        }
    }
    if (bailout) {
        for (i = 9; i > 0; i--) {
            sceVu0Normalize(act->last_hit_plane[i], act->last_hit_plane[i]);
        }
        if (cnt_bailout > 10) {
            num = 10;
        } else {
            num = cnt_bailout;
        }
        sceVu0Normalize(snor, rc->nowpos.normal);
        *(__int128*)wnor1 = *(__int128*)act->last_hit_plane[0];
        for (i = 1; i < num; i++) {
            *(__int128*)wnor2 = *(__int128*)act->last_hit_plane[i];
            sceVu0SubVector(nor, wnor1, wnor2);
            ftmp = iktactGetLen(nor);
            if (!(ftmp <= 0.0001f)) {
                break;
            }
            sceVu0SubVector(nor, snor, wnor2);
            ftmp = iktactGetLen(nor);
            if (!(ftmp <= 0.0001f)) {
                break;
            }
        }
        if (i == num) {
            wnor2[0] = 0.0f;
            wnor2[1] = 0.0f;
            wnor2[2] = 0.0f;
            wnor2[3] = 0.0f;
            num = 2;
        } else {
            num = 3;
        }
        sceVu0SubVector(nor, snor, wnor1);
        ftmp = iktactGetLen(nor);
        if (ftmp <= 0.0001f) {
            wnor1[0] = 0.0f;
            wnor1[1] = 0.0f;
            wnor1[2] = 0.0f;
            wnor1[3] = 0.0f;
            num--;
        }
        sceVu0AddVector(nor, snor, wnor1);
        sceVu0AddVector(nor, nor, wnor2);
        sceVu0Normalize(nor, nor);
        if (act->cnt_quit < 0) {
            sceVu0ScaleVectorXYZ(nor, nor, 16.666666f);
        } else {
            sceVu0ScaleVectorXYZ(nor, nor, 16.666666f);
        }
        *(__int128*)rc->speed = *(__int128*)nor;
        act->forced_bailout = 1;
        act->cnt_hit_wall /= 2;
        act->cnt_forced_bailout++;
        if (!(act->cnt_forced_bailout < 10)) {
            act->col_vec[vktactNumVec].attr = 0x1D;
            act->col_vec[vktactNumVec].len = 0.0f;
            vktactNumVec++;
            act->cnt_forced_bailout = 0;
        }
    }
}

static void ktactUpdateState(Ctrl* rc) {
    Act* act; // r16
    Sbcore* cd; // r20
    Pos* now; // r17
    Pos* pre; // r21
    float hi; // 0x128(r29)
    float ang; // 0x12C(r29)
    float ftmp; // 0x130(r29)
    signed int b; // r18
    signed int gr_cnt_free; // r22
    signed int manu_cnt_free; // r23
    sceVu0FVECTOR v0; // 0xA0(r29)
    sceVu0FVECTOR v1; // 0xB0(r29)
    sceVu0FVECTOR v; // 0xC0(r29)
    signed int tmp; // r19

    act = &rc->act;
    cd = &act->sbcore;
    now = &rc->nowpos;
    pre = &rc->prepos;
    if (act->cnt_warp > 0) {
        act->cnt_warp--;
        if (!act->cnt_warp) {
            act->recover = 1;
            if (act->sliding_state == essTumble) {
                act->tumble_type = 0;
                act->tumble_way = 0;
                act->mot_reserve_tumble_standup = 0;
                act->mot_tumble_standup_already = 0;
                rc->nowreq.end_fall = 1;
            }
            act->sliding_state = essSliding;
        }
    }
    switch (act->sliding_state) {
        case essOnAir:
            if (act->trg_jumpup) {
                act->cnt_freefoot = 10;
            } else if (act->trg_hopup && (act->pre_state != essGrind)) {
                act->cnt_freefoot = 10;
            } else if (act->trg_bonk) {
                act->cnt_freefoot = 10;
            }
            if ((act->trg_hopup || act->trg_jumpup) && !act->halfpiping && !rc->nowinp.turn) {
                *(__int128*)rc->pole = *(__int128*)rc->disp_pole;
            }
            if (act->trg_hopup || act->trg_jumpup) {
                act->touch_perfect = 0;
                act->water_manual = 0;
                act->balance_cnt_adj = 0;
                act->big_air = 0;
            }
            hi = now->cross[1] - now->pos[1];
            if (act->max_height < hi) {
                act->max_height = hi;
                if (hi > 200.0f) {
                    act->big_air = 1;
                }
            }
            act->cnt_onair++;
            act->cnt_onair2++;
            break;
        case essSliding:
            gr_cnt_free = act->gr_balance.cnt_free;
            manu_cnt_free = act->manu_balance.cnt_free;
            ktactInitBalance(&act->gr_balance);
            ktactInitBalance(&act->manu_balance);
            act->gr_balance.cnt_free = gr_cnt_free;
            act->manu_balance.cnt_free = manu_cnt_free;
            act->gr_reset_lean = 1;
            act->manu_reset_lean = 1;
            act->cnt_total_grind = 0;
            act->cnt_total_manual = 0;
            act->cnt_freefoot = 0;
            break;
        case essGrind:
            if (!act->gr_balance.cnt_free) {
                act->cnt_grind++;
                act->cnt_total_grind++;
            }
            act->cnt_real_grind++;
            if (act->gr_cnt_kissed > 0) {
                act->gr_cnt_kissed--;
            }
            if ((act->pre_state == essOnAir) && act->pre_hp_air) {
                act->disaster = 1;
            } else if (act->pre_state != essGrind) {
                act->disaster = 0;
            }
            break;
        case essManual:
            if (!act->manu_balance.cnt_free) {
                act->cnt_manual++;
                act->cnt_total_manual++;
            }
            break;
        case essPlant:
            act->cnt_plant++;
            break;
        case essTumble:
            act->cnt_tumble++;
            if (act->cnt_planttumble > 0) {
                act->cnt_planttumble--;
            }
            gr_cnt_free = act->gr_balance.cnt_free;
            manu_cnt_free = act->manu_balance.cnt_free;
            ktactInitBalance(&act->gr_balance);
            ktactInitBalance(&act->manu_balance);
            act->gr_balance.cnt_free = gr_cnt_free;
            act->manu_balance.cnt_free = manu_cnt_free;
            act->gr_reset_lean = 1;
            act->manu_reset_lean = 1;
            act->gr_grind_no = -1;
            act->gr_cnt_kissed = 0;
            act->cnt_total_grind = 0;
            act->cnt_total_manual = 0;
            if (act->tumble_type >= 2) {
                act->cnt_d2c = 60;
            }
            if (act->tumble_type) {
                act->cnt_no_bodyhit = 30;
            }
            if (act->pre_state == essGrind) {
                act->grind_tumble = 1;
            }
            if ((act->tumble_se_id < 0) && act->grind_tumble && (act->cnt_tumble >= 4)) {
                if (!pre->hit && now->hit) {
                    act->tumble_se_id = 0;
                    act->grind_tumble = 0;
                } else if (act->grind_tumble && now->hit && (act->cnt_tumble == 4)) {
                    act->tumble_se_id = 0;
                    act->grind_tumble = 0;
                }
            }
            break;
    }
    if (now->hit) {
        act->cnt_nothit = 0;
    } else {
        act->cnt_nothit++;
    }
    if (act->trg_touch) {
        act->cnt_onair = 0;
        if (act->sliding_state != essOnAir) {
            act->cnt_onair2 = 0;
        }
        act->cnt_d2c = 60;
        act->cnt_nospin = 0;
    }
    if (!cd->move) {
        act->cnt_d2c = 60;
    }
    if (act->trick_link.trick_link) {
        if ((act->sliding_state != essGrind) && (act->pre_state == essGrind)) {
            act->first_grind = 0;
        }
    } else {
        act->first_grind = 1;
    }
    if (act->reserve_quit) {
        if (!act->sliding_state || (act->sliding_state == essSitting)) {
            act->trg_quit = 1;
            act->reserve_quit = 0;
        } else if (act->cnt_reserve_quit == 900) {
            act->trg_quit = 1;
            act->reserve_quit = 0;
        }
        if (!act->trick_link.trick_link || (!act->allow_tlink && (act->sliding_state != essGrind))) {
            act->cnt_reserve_quit++;
        }
    }
    if (act->sliding_state != essOnAir) {
        act->bonk_ready = 0;
        act->bonk_goto = 0;
        if (!act->trg_touch) {
            act->max_height = 0.0f;
        }
    }
    if (act->sliding_state && (act->sliding_state != essOnAir) && (act->sliding_state != essRevert)) {
        act->manual_ready = 0;
    } else if (!act->sliding_state && act->trg_touch && act->hp_air) {
        act->manual_ready = 0;
    }
    if ((act->sliding_state != essOnAir) && (act->sliding_state != essPlant)) {
        act->revert_cnt_ready = 0;
    }
    if ((act->sliding_state != essOnAir) && (act->sliding_state != essPlant)) {
        act->plant_air = 0;
    }
    if (act->sliding_state != essOnAir) {
        act->cnt_spinkey = 0;
    }
    if (act->sliding_state != essGrind) {
        act->cnt_grind = 0;
        act->cnt_real_grind = 0;
        act->changed_grind = 0;
        act->rail_list = 0;
        if (!act->trick_link.trick_link) {
            act->pre_rail_list = 0;
        }
    }
    if (act->sliding_state != essManual) {
        act->cnt_manual = 0;
    }
    if (act->sliding_state != essPlant) {
        act->cnt_plant = 0;
    }
    if (act->sliding_state != essTumble) {
        act->cnt_planttumble = 0;
        act->cnt_tumble = 0;
        act->grind_tumble = 0;
        act->mot_reserve_tumble_standup = 0;
    }
    if ((act->sliding_state != essManual) && (act->sliding_state != essOnAir) && ((now->material & 0x7FF) != 8)) {
        act->water_manual = 0;
    }
    if ((act->sliding_state != essOnAir) && (act->sliding_state != essGrind)) {
        act->disaster = 0;
    }
    if (!now->halfpipe) {
        if (!act->sliding_state || (act->sliding_state == essSitting) || (act->sliding_state == essManual) || (act->sliding_state == essTumble)) {
            tmp = ktactSideSlantToD2C(act->side_slant);
            if (act->cnt_d2c < tmp) {
                act->cnt_d2c = tmp;
            }
            tmp = ktactSideSlantToD2C(act->sp_side_slant);
            if (act->cnt_d2c < tmp) {
                act->cnt_d2c = tmp;
            }
        }
    }
    if (pre->hit && now->hit) {
        signed int nowmat; // r30
        signed int premat; // 0x134(r29)

        nowmat = now->material & 0x7FF;
        premat = pre->material & 0x7FF;
        if (nowmat >= 12) {
            nowmat = 11;
        }
        if (premat >= 12) {
            premat = 11;
        }
        if (!vktactMatSideSlip[nowmat] && vktactMatSideSlip[premat]) {
            act->cnt_d2c = 60;
        }
    }
    {
        signed int nowmat; // 0x138(r29)
        float sink_len; // 0x13C(r29)
        float len; // 0x140(r29)

        nowmat = now->material & 0x7FF;
        switch (nowmat) {
            case 1:
            case 3:
                if (now->hit) {
                    sink_len = 2.0f;
                    len = sink_len / 30.0f;
                    break;
                }
            case 2:
                if (now->hit) {
                    sink_len = 3.5f;
                    len = sink_len / 30.0f;
                    break;
                }
            default:
                sink_len = 0.0f;
                len = 0.11666667f;
                break;
        }
        if (act->ofs_updown < sink_len) {
            act->ofs_updown += len;
            if (act->ofs_updown > sink_len) {
                act->ofs_updown = sink_len;
            }
        } else {
            act->ofs_updown -= len;
            if (act->ofs_updown < sink_len) {
                act->ofs_updown = sink_len;
            }
        }
    }
    if (act->trg_jumpup || act->trg_hopup) {
        ktactSetHorizonParam(rc, 0);
    }
    if (act->trg_jumpup || act->trg_hopup) {
        ktactSetVerticalityParam(rc);
    }
    if (act->sliding_state == essOnAir) {
        ktactUpdateBalanceAdj(rc);
    }
    ktactSetSlant_speed(rc);
    ktactSetSlant_char_rot(rc);
    ktactSetNormalPole(rc);
    if (now->hit) {
        signed int turning; // 0x144(r29)

        turning = 0;
        if ((rc->nowinp.turn > 960) || (rc->nowinp.turn < -960)) {
            turning = 1;
        }
        if (turning || (act->sliding_state == essTumble)) {
            sceVu0Normalize(v0, rc->pole);
        } else {
            sceVu0Normalize(v0, rc->nor_pole);
        }
    } else {
        sceVu0Normalize(v0, rc->pole);
    }
    ftmp = sbcoreGetInnerAngle90(rc->disp_pole, v0);
    if (ftmp < 0.017453289f) {
        *(__int128*)rc->disp_pole = *(__int128*)v0;
    } else if (act->hp_air) {
        sceVu0InterVector(v1, &rc->disp_pole[0], &v0[0], 0.95f);
        *(__int128*)rc->disp_pole = *(__int128*)v1;
    } else {
        sceVu0InterVector(v1, rc->disp_pole, v0, 0.9f);
        *(__int128*)rc->disp_pole = *(__int128*)v1;
    }
    *(__int128*)rc->disp_pos = *(__int128*)now->pos;
    if ((act->sliding_state == essGrind) || (act->hp_air && act->hp_adj_roty)) {
        ftmp = rc->rot_pole - rc->disp_rot_pole;
        ftmp = 0.1f * (ftmp < -3.141592f ? 6.283184f + ftmp : ftmp > 3.141592f ? ftmp - 6.283184f
                                                                               : ftmp);
        ftmp = ftmp + rc->disp_rot_pole;
        rc->disp_rot_pole = ftmp < -3.141592f ? 6.283184f + ftmp : ftmp > 3.141592f ? ftmp - 6.283184f
                                                                                    : ftmp;
    } else {
        rc->disp_rot_pole = rc->rot_pole;
    }
    if (act->sliding_state == essGrind) {
        rc->disp_rot_foot = act->gr_balance.balance;
    } else if (act->sliding_state == essManual) {
        rc->disp_rot_foot = act->manu_balance.balance;
    } else {
        rc->disp_rot_foot *= 0.9f;
    }
    if (act->cnt_freefoot > 0) {
        act->cnt_freefoot--;
    }
    if (act->cnt_d2c > 0) {
        act->cnt_d2c--;
    }
    if (act->cnt_to_rail > 0) {
        act->cnt_to_rail--;
    }
    if (act->cnt_nospin > 0) {
        act->cnt_nospin--;
    }
    if (act->cnt_brake > 0) {
        act->cnt_brake--;
    }
    if (act->cnt_no_bodyhit > 0) {
        act->cnt_no_bodyhit--;
    }
    if (act->manual_cnt_to_play > 0) {
        act->manual_cnt_to_play--;
    }
    if (act->revert_cnt_ready > 0) {
        act->revert_cnt_ready--;
    }
    if (act->gr_balance.cnt_free > 0) {
        act->gr_balance.cnt_free--;
    }
    if (act->manu_balance.cnt_free > 0) {
        act->manu_balance.cnt_free--;
    }
    if (act->cnt_plant2grind > 0) {
        act->cnt_plant2grind--;
    }
    if ((rc->speed[0] == 0.0f) && (rc->speed[2] == 0.0f)) {
        ang = 0.0f;
    } else {
        ang = atan2f(-rc->speed[0], -rc->speed[2]);
        ang = ang - rc->rot_pole;
        ang = ang < -3.141592f ? 6.283184f + ang : ang > 3.141592f ? ang - 6.283184f
                                                                   : ang;
    }
    if ((ang < -1.570796f) || (ang > 1.570796f)) {
        act->cnt_backward++;
    } else {
        act->cnt_backward = 0;
    }
    if ((act->sliding_state == essOnAir) || (act->sliding_state == essPlant)) {
        act->cnt_backward = 0;
    }
    act->pre_hp_air = act->hp_air;
    if (act->sliding_state == essOnAir) {
        if (!act->hp_air) {
            act->hp_air = act->halfpiping;
            if (act->halfpiping) {
                float len; // 0x148(r29)

                sbcoreGetShadowVector(v, act->hp_normal, rc->speed);
                len = iktactGetLenXZ(v);
                ftmp = v[1];
                if (ftmp < 0.0f) {
                    ftmp = -ftmp;
                }
                ang = atan2f(len, ftmp);
                if (ang < 0.34906578f) {
                    act->hp_adj_roty = 0;
                }
            }
        }
    } else {
        act->hp_air = 0;
        act->over_hp = 0;
        if (act->sliding_state != essPlant) {
            act->hp_jump = 0;
        }
    }
    if (act->trg_tumble_type == 5) {
        act->tumble_type = act->trg_tumble_type;
        act->tumble_way = act->trg_tumble_way;
    } else if (act->trg_tumble_type && !act->tumble_type) {
        act->tumble_type = act->trg_tumble_type;
        act->tumble_way = act->trg_tumble_way;
    } else {
        act->trg_tumble_type = 0;
        act->trg_tumble_way = 0;
    }
    if ((cd->plane_hit.available && !now->halfpipe && (cd->plane_hit.attribute != 0)) || act->trg_tumble_type) {
        act->no_approach_speed = 1;
    } else {
        act->sliding_state == essGrind;
    }
    if (!act->trg_touch && ((act->sliding_state == essGrind) || (act->sliding_state == essManual) || (act->sliding_state == essPlant))) {
        b = 0;
    } else if (act->plant_air || (act->sliding_state == essRevert)) {
        b = 1;
    } else if (((rc->splen > 2.7777777f) || act->trg_touch) && (now->hit || (act->sliding_state == essGrind)) && act->sbcore.move) {
        b = 1;
    } else if ((act->sliding_state != essOnAir) && (act->cnt_backward > 60)) {
        b = 1;
    } else {
        b = 0;
    }
    if ((act->sliding_state == essTumble) &&
        ((act->tumble_type == 2) || (act->tumble_type == 3) || (act->tumble_type == 4) || (act->tumble_type == 5))) {
        b = 0;
    }
    if (b) {
        sceVu0FMATRIX mat; // 0xD0(r29)
        sceVu0FVECTOR lsp; // 0x110(r29)

        sbcoreGetRotMatrix(mat, rc->pole, rc->rot_pole);
        sceVu0InversMatrix(mat, mat);
        sceVu0ApplyMatrix(lsp, mat, rc->speed);
        ang = atan2f(-lsp[0], -lsp[2]);
        if ((ang > 1.570796f) || (ang < -1.570796f)) {
            act->goofy = act->goofy ? 0 : 1;
            rc->rot_pole = (rc->rot_pole + 3.141592f) < -3.141592f
                               ? 6.283184f + (rc->rot_pole + 3.141592f)
                           : (rc->rot_pole + 3.141592f) > 3.141592f
                               ? (rc->rot_pole + 3.141592f) - 6.283184f
                               : (rc->rot_pole + 3.141592f);
            rc->disp_rot_pole = rc->rot_pole;
            if (act->tumble_type == 1) {
                if (act->trg_tumble_way == 2) {
                    act->trg_tumble_way = 3;
                } else if (act->trg_tumble_way == 3) {
                    act->trg_tumble_way = 2;
                }
            }
        }
    }
    if (act->sliding_state != essOnAir) {
        if (act->goofy == act->def_goofy) {
            act->fakie = 0;
        } else {
            act->fakie = 1;
        }
    }
    act->now_max_speed = ktactGetCmnMaxSpeed(rc);
    ktactGetWaistPos(rc);
    act->reserve_tumble = 0;
    act->reserve_tumble_ang = 0.0f;
    act->reserve_tumble_speed = -1.0f;
    act->reserve_tumble_type = 0;
}

static void ktactUpdateStateByMot(Ctrl* rc) {
    Act* act = &rc->act; // r16
    Mot* nowmot = &rc->mot; // r23

    if (rc->mot.now.uad < 2) {
        switch (act->mot_finish) {
            case 0x3B:
            case 0x53:
            case 0x90:
            case 0x86:
                act->goofy = act->goofy ? 0 : 1;
                break;
            case 0x12:
            case 0x2:
            case 0x3D:
            case 0x3F:
            case 0x14:
            case 0x16:
            case 0x7:
            case 0x9:
            case 0xD:
            case 0xF:
            case 0x3:
            case 0x5:
            case 0x57:
            case 0x40:
                act->goofy = act->goofy ? 0 : 1;
                break;
            case 0x8B:
            case 0x81:
                act->goofy = act->goofy ? 0 : 1;
                break;
            case 0xC0:
            case 0xB0:
            case 0xB8:
            case 0xB5:
            case 0xBB:
            case 0xCB:
            case 0xCC:
            case 0x72:
                rc->rot_pole += 3.141592f;
                rc->rot_pole = rc->rot_pole < -3.141592f
                                   ? 6.283184f + rc->rot_pole
                               : rc->rot_pole > 3.141592f
                                   ? rc->rot_pole - 6.283184f
                                   : rc->rot_pole;
                act->mot_planting = 0;
                break;
            case 0xC1:
            case 0xD7:
                act->goofy = act->goofy ? 0 : 1;
                rc->rot_pole += 3.141592f;
                rc->rot_pole = rc->rot_pole < -3.141592f
                                   ? 6.283184f + rc->rot_pole
                               : rc->rot_pole > 3.141592f
                                   ? rc->rot_pole - 6.283184f
                                   : rc->rot_pole;
                act->mot_planting = 0;
                break;
            case 0x8D:
            case 0x83:
                act->goofy = act->goofy ? 0 : 1;
                break;
            case 0x7C:
            case 0x5F:
                act->goofy = act->goofy ? 0 : 1;
                break;
        }
        switch (act->mot_finish) {
            case 0xBF:
            case 0xAF:
            case 0xB4:
            case 0xB7:
            case 0xBA:
            case 0x71:
                act->cnt_holding++;
                break;
            case 0xAB:
            case 0xAD:
            case 0xBD:
            case 0xC3:
            case 0xB2:
            case 0xC5:
            case 0xC7:
            case 0xC9:
            case 0xCD:
            case 0xCF:
            case 0xD1:
            case 0xD3:
            case 0xD5:
            case 0xD8:
            case 0xDA:
            case 0xDC:
            case 0xDE:
            case 0xE0:
            case 0xE2:
            case 0xE4:
            case 0xE6:
            case 0xE8:
            case 0xEA:
            case 0xEC:
            case 0xEE:
            case 0xF0:
                act->cnt_holding++;
                break;
            case 0x6F:
            case 0x78:
            case 0x64:
            case 0x69:
            case 0x6D:
            case 0x76:
                act->cnt_holding++;
                break;
            default:
                switch (rc->mot.now.id) {
                    case 0xC2:
                    case 0xB1:
                    case 0xB9:
                    case 0xBC:
                    case 0xB6:
                    case 0x73:
                    case 0xAC:
                    case 0xAE:
                    case 0xBE:
                    case 0xC4:
                    case 0xB3:
                    case 0xC6:
                    case 0xC8:
                    case 0xCA:
                    case 0xCE:
                    case 0xD0:
                    case 0xD2:
                    case 0xD4:
                    case 0xD6:
                    case 0xD9:
                    case 0xDB:
                    case 0xDD:
                    case 0xDF:
                    case 0xE1:
                    case 0xE3:
                    case 0xE5:
                    case 0xE7:
                    case 0xE9:
                    case 0xEB:
                    case 0xED:
                    case 0xEF:
                    case 0xF1:
                    case 0x70:
                    case 0x79:
                    case 0x65:
                    case 0x6A:
                    case 0x6E:
                    case 0x77:
                        act->cnt_holding++;
                        break;
                    default:
                        act->cnt_holding = 0;
                        break;
                }
                break;
        }
        if (
            act->mot_grabing == 0 && act->mot_flipping == 0 && act->mot_spflipping == 0 && act->mot_grinding == 0 && act->mot_planting == 0 && act->mot_manualing == 0) {
            act->trk_doing = 0;
            act->trk_state = 0;
            act->trk_grab_no = -1;
            act->trk_trick_no = -1;
        }
    } else {
        act->trk_doing = 0;
        act->trk_state = 0;
        act->trk_grab_no = -1;
        act->trk_trick_no = -1;
    }
}

// ktact.c
static void ktactUpdateTrickLink(TrickLink* tl, Ctrl* rc) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act; // r16
    // Size: 0x44, DWARF: 0x7F8B4
    Req* req; // r17
    signed int link_up; // r18
    signed int end_link; // r19

    act = &rc->act;
    req = &rc->nowreq;
    end_link = 0;
    link_up = 0;
    if (act->tumble_type < 2) {
        if (req->command || ((tl->spin_ang > 0) && (tl->trick_link == 0)) || (act->num_set_gap > 0)) {
            link_up = 1;
        }
    }
    if (link_up) {
        if (act->trg_change_grind) {
            link_up = 0;
        }
    }
    if (link_up) {
        if (tl->trick_link == 0) {
            tl->trg_start_link = 1;
        }
        if (req->command) {
            tl->cnt_link++;
            tl->cnt_trick++;
        }
        if (act->num_set_gap > 0) {
            tl->cnt_link++;
        }
    } else {
        switch (act->sliding_state) {
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                tl->trg_start_link = 0;
                tl->trg_end_link = 0;
                break;
            case 0:
            case 1:
            case 8:
                if (tl->trick_link) {
                    if ((act->tumble_type == 1) && (rc->nowpos.hit == 0)) {
                        tl->trg_end_link = 0;
                    } else {
                        tl->trg_end_link = 1;
                    }
                } else {
                    tl->trg_end_link = 0;
                }
                break;
        }
        if (tl->trick_link) {
            if (act->cnt_warp > 0) {
                tl->trg_end_link = 1;
            }
        }
    }
    tl->spenv_get_trick_no = -1;
    switch (req->command) {
        case 1:
            tl->spenv_get_trick_no = req->trick_no;
            act->trk_doing = 1;
            act->trk_grab_no = tl->spenv_get_trick_no;
            break;
        case 2:
            tl->spenv_get_trick_no = req->flip_no;
            act->trk_doing = 1;
            act->trk_state = 1;
            act->trk_trick_no = tl->spenv_get_trick_no;
            break;
        case 3:
            tl->spenv_get_trick_no = req->grind_no;
            act->trk_doing = 1;
            act->trk_state = 3;
            act->trk_trick_no = tl->spenv_get_trick_no;
            act->gr_grind_no = req->grind_no;
            if (act->trg_change_grind == 0) {
                act->gr_cnt_kissed = 10;
            }
            break;
        case 4:
            tl->spenv_get_trick_no = req->plant_no;
            act->trk_doing = 1;
            act->trk_state = 4;
            act->trk_trick_no = tl->spenv_get_trick_no;
            break;
        case 5:
            tl->spenv_get_trick_no = act->bonk_ready_no;
            act->trk_trick_no = tl->spenv_get_trick_no;
            break;
        case 6:
            tl->spenv_get_trick_no = act->manual_ready_no;
            act->trk_doing = 1;
            act->trk_state = 2;
            act->trk_trick_no = tl->spenv_get_trick_no;
            break;
        case 7:
            tl->spenv_get_trick_no = act->revert_ready_no;
            act->trk_doing = 1;
            act->trk_state = 5;
            act->trk_trick_no = tl->spenv_get_trick_no;
            break;
        case 8:
            tl->spenv_get_trick_no = req->jump_no;
            act->trk_trick_no = tl->spenv_get_trick_no;
            break;
        case 0:
        default:
            if (act->gr_cnt_kissed == 0) {
                if (act->gr_grind_no >= 0) {
                    if (act->sliding_state == 5) {
                        act->trg_grind_name = 1;
                    }
                }
            }
            break;
    }
    if (act->gr_cnt_kissed > 0) {
        if (req->jump) {
            act->gr_grind_no = 0x84;
            act->trg_grind_name = 1;
        }
        if (act->sliding_state != 5) {
            act->gr_grind_no = 0x84;
            act->trg_grind_name = 1;
        }
    }
    if (tl->spenv_get_trick_no >= 0) {
        if (act->num_play_trick[act->fakie][tl->spenv_get_trick_no] < 0xFF) {
            act->num_play_trick[act->fakie][tl->spenv_get_trick_no]++;
            act->num_play_trick_in_link[act->fakie][tl->spenv_get_trick_no]++;
        }
    }
    ktactUpdateTrickPoint(act, rc);
}

static void ktactUpdateGap(Act* act) {
    signed int i; // r16

    act->num_total_gap += act->num_set_gap;
    for (i = 0; i < act->num_set_gap; i++) {
        act->set_gap[i] = -1;
    }
    act->num_set_gap = 0;
}

static void ktactUpdateSpecialTrick(Ctrl* rc) {
    Act* act; // r16
    TrickLink* tl; // r17

    act = &rc->act;
    tl = &act->trick_link;
    if (act->special_num > 0) {
        act->special_left_time = act->special_total_time;
        act->special_charge_cnt = act->special_charge_maxcnt;
        act->special_num = 0;
    }
    if (act->trg_tumble_type >= 2) {
        act->special_charge = 0;
        act->special_left_time = 0;
        act->special_charge_cnt = 0;
    }
    if (act->special_left_time > 0) {
        act->special_left_time = (signed int)(act->special_left_time - 1);
        act->special_charge = (signed int)((signed int)(act->special_left_time * 0x64) / (signed int)act->special_total_time);
        // break;
    } else {
        act->special_left_time = 0;
        if (act->special_charge > 0) {
            act->special_charge_cnt = (signed int)(act->special_charge_cnt - 1);
            if (act->special_charge_cnt <= 0) {
                act->special_charge_cnt = (signed int)act->special_charge_maxcnt;
                act->special_charge = (signed int)(act->special_charge - 1);
            }
        }
    }
    if (rc->cheats->always_sp != 0) {
        act->special_num = 0;
        act->special_charge = 0x64;
        act->special_charge_cnt = (signed int)act->special_charge_maxcnt;
        act->special_left_time = (signed int)act->special_total_time;
    }
}

static void ktactUpdateBoost(Ctrl* rc) {
    Act* act = &rc->act; // r16 // s0
    signed int bp; // r17 // s1
    unsigned short padpush; // r18 // s2
    TrickLink* tl = &act->trick_link; // r19 // s3
    padpush = (rc->nowpad.cnt ^ rc->prepad.cnt) & rc->nowpad.cnt;

    if (act->boost && act->boost_num > 0 && act->boost_left_time == 0) {
        switch (act->sliding_state) {
            case essSliding:
            case essSitting:
                if ((padpush & 0x20) == 0)
                    break;
                act->boost_left_time = (signed int)act->boost_total_time;
                act->boost_num--;
                act->trg_boost = 1;
                break;
        }
    }
    if (act->boost) {
        if (act->tumble_type == 8) {
            act->boost_left_time = 0;
        }
        if (act->cnt_quit >= 0) {
            act->boost_left_time = 0;
        }
        if (act->boost_left_time > 0) {
            act->boost_left_time--;
            bp = act->boost_left_time * 5;
            if (255 < bp) {
                bp = 255;
            }
        } else {
            gmsysSetBlurPow(0);
        }
    }
}

// ktact.c
static void ktactUpdateParam(Ctrl* rc) {
    Act* act; // r16
    signed int rate; // r17
    signed int tmp_rate;

    act = &rc->act;
    if (act->special_left_time > 0) {
        tmp_rate = 0x14;
    } else {
        tmp_rate = 0;
    }
    rate = tmp_rate;
    if (act->fakie != 0) {
        rate -= 0xA;
    }
    ktactGetChrParamX10(&act->chr_param_x10, &rc->param->chr_param);
    act->chr_param_x10.ollie = (signed int)(act->chr_param_x10.ollie + rate);
    act->chr_param_x10.spin = (signed int)(act->chr_param_x10.spin + rate);
    act->chr_param_x10.speed = (signed int)(act->chr_param_x10.speed + rate);
    act->chr_param_x10.landing = (signed int)(act->chr_param_x10.landing + rate);
    act->chr_param_x10.balance = (signed int)(act->chr_param_x10.balance + rate);
    act->chr_param_x10.stability = (signed int)(act->chr_param_x10.stability + rate);
    ktactInitParam2(&act->param, &act->chr_param_x10, &act->brd_param_x10);
    act->max_speed = iktactMakeParam_max_speed(act->param.speed);
    act->cmn_max_speed = iktactMakeParam_cmn_max_speed(act->param.speed);
    if (rc->cheats->super_speed != 0) {
        act->max_speed *= 1.5f;
        act->cmn_max_speed *= 1.5f;
    }
}

static void ktactUpdateFlipPole(Ctrl* rc) {
    Act* act = &rc->act; // r16
    float mat[4][4]; // 0x30(r29)
    float pole[4]; // 0x70(r29)

    if (act->mot_flipping) {
        float v[4] = {
            0.0f,
            -1.0f,
            0.0f,
            0.0f}; // 0x80(r29) // @4091
        s32* vPtr = &v;
        float rot_pole; // 0x94(r29)

        ktactGetInnerRotMatrix(mat, act->mot_flip_rot);
        sceVu0ApplyMatrix(&pole, &mat, &v);
        sbcoreGetRotMatrix(mat, rc->pole, rc->rot_pole);
        sceVu0ApplyMatrix(&pole, &mat, &pole);
        rot_pole = rc->rot_pole - act->mot_flip_rot[1];
        sceVu0Normalize(rc->pole, &pole);
        rc->rot_pole = rot_pole < -3.141592f
                           ? 6.283184f + rot_pole
                       : rot_pole > 3.141592f
                           ? rot_pole - 6.283184f
                           : rot_pole;
    }
}

static float ktactGetCmnMaxSpeed(Ctrl* rc) {
    sceVu0FVECTOR nor = {
        0.0f,
        -1.0f,
        0.0f,
        0.0f}; // 0x20(r29) // @4106
    float limit_ang_hi; // 0x30(r29)
    float max_speed; // 0x34(r29)
    float cmn_max_speed; // 0x38(r29)
    float splimit; // 0x3C(r29)
    float inner; // 0x40(r29)
    float ang; // 0x44(r29)
    float ftmp; // 0x48(r29)
    sceVu0FVECTOR* unused = &nor;

    max_speed = rc->act.max_speed;
    cmn_max_speed = rc->act.cmn_max_speed;
    limit_ang_hi = (rc->nowpos.halfpipe) ? 3.141592f : 1.3962631f;

    inner = sceVu0InnerProduct(nor, rc->nowpos.normal);
    ang = acosf(inner);
    if (ang > limit_ang_hi) {
        ftmp = max_speed - cmn_max_speed;
    } else if (ang > 0.0f) {
        ftmp = (max_speed - cmn_max_speed) * (ang / limit_ang_hi); //((second half of f64) - (bitwise float) (f64) max_speed) * ((second half of f64) / (bitwise float) (bitwise f64) ang);
    } else {
        ftmp = 0.0f;
    }
    splimit = cmn_max_speed + ftmp; //(second half of f64) + (bitwise float) (f64) cmn_max_speed;
    if (rc->act.boost && rc->act.boost_left_time > 0) {
        splimit *= 2.0f;
    }
    return splimit;
}

// ktact.c
static void ktactSetCrashPow_normal(Ctrl* rc, Plane* plane) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act; // r16
    Tumble_Type tt; // r17
    Tumble_Way tw; // r18
    sceVu0FVECTOR next_sp; // 0xA0(r29)
    sceVu0FVECTOR next_sp2; // 0xB0(r29)
    sceVu0FVECTOR next_pole; // 0xC0(r29)
    sceVu0FVECTOR dd; // 0xD0(r29)
    sceVu0FVECTOR n0; // 0xE0(r29)
    sceVu0FVECTOR n1; // 0xF0(r29)
    sceVu0FVECTOR n; // 0x100(r29)
    sceVu0FVECTOR v0; // 0x110(r29)
    sceVu0FVECTOR v1; // 0x120(r29)
    signed int ttse; // r19
    signed int sliding; // r20
    signed int material; // r21
    signed int turn_left; // r22
    signed int samenormal; // r23
    signed int adj_pole; // r30
    float nextang; // 0x134(r29)
    float nextang2; // 0x138(r29)
    float preang; // 0x13C(r29)
    float ang; // 0x140(r29)
    float tt_spdown_rate; // 0x144(r29)
    signed int sliding0; // 0x148(r29)
    float len; // 0x14C(r29)
    float hi; // 0x150(r29)
    float area; // 0x154(r29)
    float inner; // 0x158(r29)

    act = &rc->act;
    tt = 0;
    tw = 0;
    turn_left = 0;
    ttse = -1;
    adj_pole = 0;
    *(__int128*)next_pole = *(__int128*)rc->pole;
    material = plane->material & 0x7FF;
    if (!(material < 12)) {
        material = 11;
    }
    sbcoreGetMirrorVector_angle(next_sp, plane->normal, rc->speed, 1.3089967f);
    sceVu0ScaleVectorXYZ(next_sp, next_sp, vktactMatCrashSpDown[material]);
    nextang = atan2f(-next_sp[0], -next_sp[2]);
    sbcoreGetMirrorVector(next_sp2, plane->normal, rc->speed);
    nextang2 = sbcoreGetInnerAngle180(plane->normal, next_sp2);
    if (nextang2 > 1.3089967f) {
        *(__int128*)next_sp2 = *(__int128*)next_sp;
        nextang2 = nextang;
    } else {
        sceVu0ScaleVectorXYZ(next_sp2, next_sp2, vktactMatCrashSpDown[material]);
        nextang2 = atan2f(-next_sp2[0], -next_sp2[2]);
    }
    if (act->sliding_state == 8) {
        sliding = rc->nowpos.hit;
    } else {
        sliding = (act->sliding_state == 3) ? 0 : 1;
    }
    sliding0 = sliding;
    if (!sliding) {
        samenormal = 0;
        sceVu0SubVector(dd, plane->normal, rc->nowpos.normal);
        len = iktactGetLen(dd);
        if (len < 1e-05f) {
            samenormal = 1;
        }
        if (!(act->tumble_type < 2) && plane->slidable) {
            samenormal = 0;
        }
        if (!samenormal) {
            hi = rc->nowpos.cross[1] - rc->nowpos.pos[1];
            area = 1.5f * act->sbcore.const_max_relief_gap;
            if (hi < area) {
                sliding = 1;
            }
        }
    }
    if (sliding) {
        sceVu0Normalize(n0, rc->nowpos.normal);
        sceVu0Normalize(n1, plane->normal);
        sceVu0OuterProduct(n, n0, n1);
        sceVu0OuterProduct(n, n, n0);
        if (n[1] < 0.0f) {
            sbcoreGetShadowVectorXZ(next_sp, rc->nowpos.normal, next_sp);
            sbcoreGetShadowVectorXZ(next_sp2, rc->nowpos.normal, next_sp2);
        } else {
            sbcoreGetShadowVector2(next_sp, rc->nowpos.normal, plane->normal, next_sp);
            sbcoreGetShadowVector2(next_sp2, rc->nowpos.normal, plane->normal, next_sp2);
        }
        act->trg_hit_wall = 1;
    }
    if (!sliding0 && !plane->slidable && (plane->almighty1 != 0)) {
        *(__int128*)next_sp = *(__int128*)next_sp2;
        nextang = nextang2;
        adj_pole = 1;
    }
    if (act->reserve_tumble && (act->reserve_tumble_speed > 0.0f)) {
        len = iktactGetLen(next_sp2);
        if (len < act->reserve_tumble_speed) {
            len = act->reserve_tumble_speed;
        }
        ang = act->reserve_tumble_ang;
        next_sp2[0] = -sinf(ang);
        next_sp2[1] = 0.0f;
        next_sp2[2] = -cosf(ang);
        sceVu0Normalize(next_sp2, next_sp2);
        sceVu0ScaleVector(next_sp2, next_sp2, len);
        *(__int128*)next_sp = *(__int128*)next_sp2;
        nextang = nextang2;
        act->trg_hit_wall = 0;
    }
    preang = atan2f(-rc->speed[0], -rc->speed[2]);
    ang = atan2f(-plane->normal[0], -plane->normal[2]);
    ang = ang - preang;
    ang = ang < -3.141592f
              ? 6.283184f + ang
          : (ang > 3.141592f)
              ? ang - 6.283184f
              : ang;
    if (ang < 0.0f) {
        turn_left = 1;
        ang = -ang;
    }
    if (ang > 1.570796f) {
        ang = 3.141592f - ang;
    }
    ang = 1.570796f - ang;
    if ((rc->splen > vktactMatTumbleSpeed_normal[2]) && (ang > vktactMatTumbleAng_normal[2])) {
        *(__int128*)next_sp = *(__int128*)next_sp2;
        nextang = nextang2;
        *(__int128*)v0 = *(__int128*)rc->speed;
        *(__int128*)v1 = *(__int128*)next_sp;
        v0[1] = 0.0f;
        v1[1] = 0.0f;
        inner = sceVu0InnerProduct(v0, v1);
        if (inner < 0.0f) {
            tt = 4;
            tw = 0;
            ttse = 2;
            nextang += 3.141592f;
            nextang = nextang < -3.141592f
                          ? 6.283184f + nextang
                      : (nextang > 3.141592f)
                          ? nextang - 6.283184f
                          : nextang;
        } else {
            tt = 3;
            tw = 3;
            ttse = 3;
        }
    } else if ((rc->splen > vktactMatTumbleSpeed_normal[1]) && (ang > vktactMatTumbleAng_normal[1])) {
        tt = 2;
        tw = turn_left ? 0 : 1;
        ttse = 0;
        if (act->tumble_type == 4) {
            nextang += 3.141592f;
            nextang = nextang < -3.141592f
                          ? 6.283184f + nextang
                      : (nextang > 3.141592f)
                          ? nextang - 6.283184f
                          : nextang;
        }
    } else if ((rc->splen < vktactMatTumbleSpeed_normal[0]) || (ang < vktactMatTumbleAng_normal[0]) || (act->sliding_state == 3)) {
        if (act->tumble_type == 4) {
            nextang += 3.141592f;
            nextang = nextang < -3.141592f
                          ? 6.283184f + nextang
                      : (nextang > 3.141592f)
                          ? nextang - 6.283184f
                          : nextang;
        }
    } else {
        tt = 1;
        tw = turn_left ? 0 : 1;
        ttse = 4;
        if (act->tumble_type == 4) {
            nextang += 3.141592f;
            nextang = nextang < -3.141592f
                          ? 6.283184f + nextang
                      : (nextang > 3.141592f)
                          ? nextang - 6.283184f
                          : nextang;
        }
    }
    if (adj_pole && !(tt < 2)) {
        next_pole[0] = 0.0f;
        next_pole[1] = -1.0f;
        next_pole[2] = 0.0f;
        next_pole[3] = 0.0f;
    }
    tt_spdown_rate = vktactTTCrashSpDown_normal[tt];
    if (tt < act->trg_tumble_type) {
        tt = act->trg_tumble_type;
        tw = act->trg_tumble_way;
    }
    act->trg_tumble_type = tt;
    act->trg_tumble_way = tw;
    act->tumble_se_id = ttse;
    sceVu0ScaleVectorXYZ(next_sp, next_sp, tt_spdown_rate);
    if ((act->cnt_quit < 0) && ((rc->splen * tt_spdown_rate) < 4.1666665f)) {
        tt_spdown_rate = 4.1666665f / (rc->splen * tt_spdown_rate);
        sceVu0ScaleVectorXYZ(next_sp, next_sp, tt_spdown_rate);
    }
    next_sp[3] = 1.0f;
    rc->rot_pole = nextang;
    *(__int128*)rc->speed = *(__int128*)next_sp;
    *(__int128*)rc->pole = *(__int128*)next_pole;
}

// ktact.c
static void ktactSetCrashPow_touch(Ctrl* rc, Plane* plane, signed int hp) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act; // r16
    sceVu0FVECTOR next_sp; // 0xA0(r29)
    sceVu0FVECTOR v0; // 0xB0(r29)
    sceVu0FVECTOR v1; // 0xC0(r29)
    sceVu0FMATRIX wlm; // 0xD0(r29)
    sceVu0FVECTOR lsp; // 0x110(r29)
    Tumble_Type tt; // r17
    signed int material; // r18
    Tumble_Way tw; // r19
    signed int is_left; // r20
    signed int ttse; // r21
    signed int is_foward; // r22
    float perfect_rate; // 0x124(r29)
    float ang_totter; // 0x128(r29)
    float ang_tumble; // 0x12C(r29)
    float spang_totter; // 0x130(r29)
    float spang_tumble; // 0x134(r29)
    float splen_totter; // 0x138(r29)
    float splen_tumble_s; // 0x13C(r29)
    float splen_tumble_l; // 0x140(r29)
    float rot_pole; // 0x144(r29)
    float rot_pole0; // 0x148(r29)
    float splen; // 0x14C(r29)
    float param_adj; // 0x150(r29)
    float ang; // 0x154(r29)
    float spang; // 0x158(r29)
    float spang0; // 0x15C(r29)
    signed int end_frame; // 0x160(r29)

    perfect_rate = 0.25f;
    ang_totter = vktactMatTumbleAng_touch[0];
    ang_tumble = vktactMatTumbleAng_touch[1];
    splen_totter = vktactMatTumbleSpeed_touch[0];
    splen_tumble_s = vktactMatTumbleSpeed_touch[1];
    splen_tumble_l = vktactMatTumbleSpeed_touch[2];
    act = &rc->act;
    tt = 0;
    tw = 0;
    is_left = 0;
    is_foward = 0;
    rot_pole0 = rc->rot_pole;
    ttse = -1;
    splen = act->hp_air ? rc->splen : rc->splenxz;
    material = plane->material & 0x7FF;
    if (!(material < 12)) {
        material = 11;
    }
    ang_totter *= vktactMatRate_touch[material];
    ang_tumble *= vktactMatRate_touch[material];
    splen_totter *= vktactMatRate_touch[material];
    splen_tumble_s *= vktactMatRate_touch[material];
    splen_tumble_l *= vktactMatRate_touch[material];
    if (act->fakie) {
        param_adj = iktactMakeParam_landing(act->param.landing_switch);
    } else {
        param_adj = iktactMakeParam_landing(act->param.landing);
    }
    ang_totter *= param_adj;
    ang_tumble *= param_adj;
    spang_totter = ang_totter;
    spang_tumble = ang_tumble;
    if (hp) {
        ang_totter *= 1.5f;
        ang_tumble *= 1.5f;
    }
    if (plane->slidable) {
        sbcoreGetShadowVector(next_sp, plane->normal, rc->speed);
    } else {
        sbcoreGetMirrorVector(next_sp, plane->normal, rc->speed);
    }
    sceVu0ScaleVectorXYZ(next_sp, next_sp, vktactMatCrashSpDown[material]);
    rot_pole = rc->rot_pole;
    if (!(act->cnt_onair < 30)) {
        sbcoreGetRotMatrix(wlm, rc->pole, rc->rot_pole);
        sceVu0InversMatrix(wlm, wlm);
        if (act->hp_air) {
            sceVu0ApplyMatrix(lsp, wlm, rc->speed);
            spang = atan2f(-lsp[0], -lsp[2]);
        } else {
            *(__int128*)lsp = *(__int128*)rc->speed;
            spang = atan2f(-lsp[0], -lsp[2]);
            spang = rc->rot_pole - spang;
            spang = spang < -3.141592f
                        ? 6.283184f + spang
                    : (spang > 3.141592f)
                        ? spang - 6.283184f
                        : spang;
        }
        spang0 = spang;
        if (spang > 1.570796f) {
            spang -= 3.141592f;
        } else if (spang < -1.570796f) {
            spang += 3.141592f;
        }
        if (spang < 0.0f) {
            is_left = 1;
            spang = -spang;
        }
        sceVu0OuterProduct(v0, plane->normal, rc->pole);
        sceVu0OuterProduct(v1, plane->normal, rc->speed);
        ang = sceVu0InnerProduct(v0, v1);
        if (!(ang < 0.0f)) {
            is_foward = 1;
        }
        if (act->hp_air && hp) {
            *(__int128*)v0 = *(__int128*)rc->pole;
            *(__int128*)v1 = *(__int128*)plane->normal;
            v0[1] = 0.0f;
            v1[1] = 0.0f;
            ang = sbcoreGetInnerAngle180(v0, v1);
        } else {
            ang = sbcoreGetInnerAngle180(rc->pole, plane->normal);
        }
        if ((ang < ang_totter) && (spang < spang_totter)) {
            if ((ang < (ang_totter * perfect_rate)) && (spang < (spang_totter * perfect_rate))) {
                act->touch_perfect = 1;
            } else {
                act->touch_perfect = 0;
            }
        } else if ((spang > spang_tumble) && (rc->splen > splen_tumble_s)) {
            if (rc->splen < splen_tumble_l) {
                tt = 2;
            } else {
                tt = 3;
            }
            is_left = (spang0 < 0.0f) ? 1 : 0;
            tw = is_left ? 1 : 0;
        } else if ((ang > ang_tumble) && (rc->splen > splen_tumble_s)) {
            if (rc->splen < splen_tumble_l) {
                tt = 2;
            } else {
                tt = 3;
            }
            tw = is_foward ? 2 : 3;
        } else if (ang > spang) {
            tt = 1;
            tw = is_foward ? 2 : 3;
        } else {
            tt = 1;
            tw = is_left ? 1 : 0;
        }
        if ((tt == 2) || (tt == 3)) {
            rot_pole = atan2f(-next_sp[0], -next_sp[2]);
            ttse = (tt == 2) ? 0 : 1;
        } else if (tt == 1) {
        }
    }
    if ((tt == 0) || (tt == 1)) {
        if (act->mot_grabing || (act->mot_bonking && (plane->almighty1 != 7) && !(plane->material & 0x4000))) {
            tt = 2;
            tw = 2;
            ttse = 1;
            rot_pole = atan2f(-next_sp[0], -next_sp[2]);
        } else if (act->mot_flipping || act->mot_spflipping) {
            end_frame = (signed int)((float)rc->mot.now.num_frame - 1600.0f);
            if (rc->mot.now.frame < end_frame) {
                tt = 2;
                tw = 2;
                ttse = 1;
                rot_pole = atan2f(-next_sp[0], -next_sp[2]);
            }
        }
    }
    if (tt) {
        act->trg_tumble_type = tt;
        act->trg_tumble_way = tw;
        act->tumble_se_id = ttse;
        sceVu0ScaleVectorXYZ(next_sp, next_sp, vktactTTCrashSpDown_touch[tt]);
    }
    next_sp[3] = 1.0f;
    rc->rot_pole = rot_pole;
    *(__int128*)rc->speed = *(__int128*)next_sp;
}

float iktactMakeParam_landing(signed int src) {
    float cmn_grind; // r29
    float min_grind; // 0x4(r29)
    float max_grind; // 0x8(r29)
    float param; // 0xC(r29)

    cmn_grind = vktactParamCmnLanding;
    min_grind = vktactParamMinLanding;
    max_grind = vktactParamMaxLanding;
    param = cmn_grind;
    if (src >= 0x32) {
        param += ((src - 0x32) * (max_grind - cmn_grind)) / 50.0f;
    } else {
        param += ((0x32 - src) * (min_grind - cmn_grind)) / 40.0f;
    }
    return param;
}

// ktact.c
static void ktactSetSlant_speed(Ctrl* rc) {
    Act* act; // r16
    float nor[4]; // 0x20(r29)
    float m[4][4]; // 0x30(r29)
    float angx; // 0x74(r29)
    float angz; // 0x78(r29)
    float ang; // 0x7C(r29)

    act = &rc->act;
    *(__int128*)nor = *(__int128*)rc->nowpos.normal;
    ang = atan2f(-rc->speed[0], -rc->speed[2]);
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixY(m, m, -ang);
    sceVu0ApplyMatrix(nor, m, nor);
    if (nor[1] <= 0.0f) {
        angx = atan2f(nor[0], -nor[1]);
        angz = atan2f(nor[2], -nor[1]);
    } else {
        angx = atan2f(nor[0], -nor[1]);
        angz = atan2f(nor[2], -nor[1]);
    }
    act->sp_slant = angz;
    act->sp_side_slant = angx;
}

void ktactSetSlant_char_rot(Ctrl* rc) {
    Act* act = &rc->act;
    float lvx[4] = {1.0f, 0.0f, 0.0f, 0.0f};
    float* unused1 = lvx;
    float lvz[4] = {0.0f, 0.0f, -1.0f, 0.0f};
    float* unused2 = lvz;
    float wv[4];
    sceVu0FMATRIX lwm;
    float len;
    float angx;
    float angz;

    sbcoreGetRotMatrix(lwm, rc->nowpos.normal, rc->rot_pole);
    sceVu0ApplyMatrix(wv, lwm, lvx);
    len = iktactGetLenXZ(wv);
    angx = atan2f(wv[1], len);
    sceVu0ApplyMatrix(wv, lwm, lvz);
    len = iktactGetLenXZ(wv);
    angz = atan2f(wv[1], len);
    act->slant = angz;
    act->side_slant = angx;
}

// ktact.c
void ktactSetNormalPole(Ctrl* rc) {
    Act* act; // r16
    float v0[4]; // 0x20(r29)
    float m0[4][4]; // 0x30(r29)
    float m[4][4]; // 0x70(r29)
    float roty; // 0xBC(r29)

    act = &rc->act;
    roty = rc->rot_pole;
    v0[0] = 0.0f;
    v0[1] = -1.0f;
    v0[2] = 0.0f;
    v0[3] = 0.0f;
    sceVu0UnitMatrix(m0);
    sceVu0RotMatrixX(m, m0, act->slant);
    sceVu0ApplyMatrix(v0, m, v0);
    sceVu0RotMatrixY(m, m0, roty);
    sceVu0ApplyMatrix(&rc->nor_pole[0], m, v0);
}

s32 ktactGetHeight(Pos* base /* sp60 */, float* pos /* sp70 */) {
    signed int hit; // r16
    float pos0[4]; // 0x40(r29)
    float pos1[4]; // 0x50(r29)

    *(__int128*)pos0 = *(__int128*)pos;
    pos0[1] += -10.0f;
    *(__int128*)pos1 = *(__int128*)pos0;
    pos1[1] += 10000.0f;

    hit = ktactGetHit_base(base, &pos0[0], &pos1[0], 0, 0, 0, 0, 0, 0, 0, 1, 1);
    if (hit == 0) {
        pos0[0] += 1.0f;
        pos0[2] += 1.0f;
        pos1[0] += 1.0f;
        pos1[2] += 1.0f;
        hit = ktactGetHit_base(base, &pos0[0], &pos1[0], 0, 0, 0, 0, 0, 0, 0, 1, 1);
    }
    if (hit) {
        *(__int128*)base = *(__int128*)pos;
    }
    return hit;
}

// ktact.c
void ktactGetInnerRotMatrix(sceVu0FMATRIX mat, float* rot) {
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixY(mat, mat, rot[1]);
    sceVu0RotMatrixZ(mat, mat, rot[2]);
    sceVu0RotMatrixX(mat, mat, rot[0]);
}

// ktact.c
void ktactGetDispRotMatrix(sceVu0FMATRIX mat, Ctrl* rc, float scale) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act = &rc->act; // r16
    float flip_center = -10.0f * scale; // 0x2DC(r29)
    sceVu0FVECTOR t0 = {0.0f, act->sbcore.const_max_relief_gap, 0.0f, 0.0f}; // 0x70(r29)
    s32* t0Ptr = &t0; // r17
    sceVu0FVECTOR t3 = {0.0f, flip_center, 0.0f, 0.0f}; // 0x80(r29)
    s32* t3Ptr = &t3; // r18
    sceVu0FVECTOR t5 = {0.0f, -flip_center, 0.0f, 0.0f}; // 0x90(r29)
    s32* t5Ptr = &t5; // r19
    sceVu0FVECTOR tpow = {0.0f, act->ofs_updown, 0.0f, 0.0f}; // 0xA0(r29)
    s32* tpowPtr = &tpow; // r20
    sceVu0FVECTOR trans; // 0xB0(r29)
    sceVu0FMATRIX um; // 0xC0(r29)
    sceVu0FMATRIX m0; // 0x100(r29)
    sceVu0FMATRIX m3; // 0x140(r29)
    sceVu0FMATRIX m4; // 0x180(r29)
    sceVu0FMATRIX m5; // 0x1C0(r29)
    sceVu0FMATRIX mpow; // 0x200(r29)
    sceVu0FMATRIX mrz; // 0x240(r29)
    sceVu0FMATRIX mer; // 0x280(r29)
    sceVu0FVECTOR kids; // 0x2C0(r29)
    signed int rotx = rc->disp_rot_foot_is_x; // r21

    (void)t0Ptr;
    (void)t3Ptr;
    (void)t5Ptr;
    (void)tpowPtr;
    if (rc->cheats->kids) {
        maGetModelScale(kids, 0);
        t3[1] *= kids[1];
        t5[1] *= kids[1];
    }
    sceVu0UnitMatrix(um);
    sbcoreGetRotMatrix(mat, rc->disp_pole, rc->disp_rot_pole);
    sceVu0TransMatrix(m0, um, t0);
    sceVu0MulMatrix(mat, mat, m0);
    if (rotx) {
        sceVu0RotMatrixX(mrz, um, -rc->disp_rot_foot);
    } else {
        sceVu0RotMatrixZ(mrz, um, -rc->disp_rot_foot);
    }
    sceVu0RotMatrixZ(mer, um, rc->disp_rot_z_ofs);
    sceVu0TransMatrix(mer, mer, rc->disp_pos_ofs);
    sceVu0TransMatrix(mpow, um, tpow);
    sceVu0MulMatrix(mat, mat, mrz);
    sceVu0MulMatrix(mat, mat, mer);
    sceVu0MulMatrix(mat, mat, mpow);
    if (act->mot_flip_mode) {
        ktactGetInnerRotMatrix(m4, act->mot_flip_rot);
        sceVu0TransMatrix(m3, um, t3);
        sceVu0TransMatrix(m5, um, t5);
        sceVu0MulMatrix(mat, mat, m3);
        sceVu0MulMatrix(mat, mat, m4);
        sceVu0MulMatrix(mat, mat, m5);
    }
    *(__int128*)trans = *(__int128*)rc->nowpos.pos;
    trans[3] = 1.0f;
    sceVu0TransMatrix(mat, mat, trans);
}

// ktact.c
void ktactGetWaistPos(Ctrl* rc) {
    Act* act; // r16
    signed int flip_mode; // r17
    sceVu0FMATRIX mat; // 0x30(r29)
    float v[4]; // 0x70(r29)
    float len_waist; // 0x88(r29)
    float len_knee; // 0x8C(r29)

    act = &rc->act;
    len_waist = 10.0f;
    len_knee = act->sbcore.const_max_relief_gap;
    flip_mode = act->mot_flip_mode;
    act->mot_flip_mode = 0;
    ktactGetDispRotMatrix(mat, rc, 1.0f);
    v[0] = 0.0f;
    v[1] = -len_knee;
    v[2] = 0.0f;
    v[3] = 1.0f;
    sceVu0ApplyMatrix(act->pos_disp, mat, &v[0]);
    v[0] = 0.0f;
    v[1] = -len_waist;
    v[2] = 0.0f;
    v[3] = 1.0f;
    sceVu0ApplyMatrix(act->pos_waist, mat, &v[0]);
    act->mot_flip_mode = flip_mode;
}

static void ktactSetHorizonParam( // Size: 0x2C00, DWARF: 0x7627B
    Ctrl* rc, signed int hp) {
    Act* act = &rc->act; // r16 // s0
    signed int frame_to_top_point; // r17 // s1
    signed int boost; // r18 // s2
    float n[4] = {0.0f, -1.0f, 0.0f, 0.0f}; // r29+0x50 // @4407
    s32* nPtr = &n;
    float vec[4]; // r29+0x60
    float ang_per_frame; // r29+0x74
    float roty_per_frame; // r29+0x78
    float spy_adj; // r29+0x7C
    float spy; // r29+0x80
    float inner; // r29+0x84

    boost = 0;
    if (vspenvGame->mode.game_mode == 1 && vspenvGame->mode.match_rule == 1) {
        boost = 1;
    }

    if (hp) {
        *(__int128*)vec = *(__int128*)rc->speed;
        vec[1] = 0.0f;
        frame_to_top_point = 30;
    } else {
        spy = rc->speed[1];
        if (spy >= 0.0f) {
            return;
        }

        *(__int128*)vec = *(__int128*)rc->speed;
        vec[1] = 0.0f;
        inner = sceVu0InnerProduct(vec, rc->pole);
        if (inner >= 0.0f) {
            return;
        }

        spy_adj = ktactGetAdjSpeedOnAir(spy, act->hp_air, act->jump_air);
        if (rc->cheats->half_g && boost == 0) {
            spy_adj *= 0.8f;
        }

        spy = -spy;
        frame_to_top_point = spy / spy_adj;
        if (30 < frame_to_top_point) {
            frame_to_top_point = 30;
        }
    }

    ang_per_frame = sbcoreGetInnerAngle180(&n, rc->pole);
    ang_per_frame /= frame_to_top_point;

    roty_per_frame = atan2f(-vec[0], -vec[2]) - rc->rot_pole;
    roty_per_frame = ((roty_per_frame < -3.141592f)
                          ? 6.283184f + roty_per_frame
                      : (roty_per_frame > 3.141592f)
                          ? roty_per_frame - 6.283184f
                          : roty_per_frame);
    roty_per_frame /= frame_to_top_point;

    act->balance_cnt_adj = frame_to_top_point;
    act->balance_ang_adj = ang_per_frame;
    act->balance_roty_adj = roty_per_frame;
    act->balance_bigair = 1;
    *(__int128*)act->balance_pole = *(__int128*)n;
}

static void ktactSetVerticalityParam(Ctrl* rc) {
    Act* act = &rc->act; // r16 // s0
    signed int set = 1; // r17 // s1
    float vec[4]; // 0x40(r29)
    float n[4] = {
        0.0f,
        -1.0f,
        0.0f,
        0.0f}; // 0x50(r29)
    s32* ptr = &n;
    float nor_pole[4]; // 0x60(r29)
    float outer0[4]; // 0x70(r29)
    float outer1[4]; // 0x80(r29)
    float ang_per_frame; // 0x9C(r29)
    float roty_per_frame; // 0xA0(r29)
    float inner; // 0xA4(r29)
    // A8 = ternary temp val
    // AC = ternary temp val

    *(__int128*)nor_pole = *(__int128*)rc->nor_pole;
    *(__int128*)vec = *(__int128*)rc->speed;
    vec[1] = 0.0f;
    ang_per_frame = sbcoreGetInnerAngle180(nor_pole, rc->pole);
    ang_per_frame /= 30.0f;
    roty_per_frame = atan2f(-vec[0], -vec[2]) - rc->rot_pole;
    roty_per_frame = roty_per_frame < -3.141592f
                         ? 6.283184f + roty_per_frame
                     : roty_per_frame > 3.141592f
                         ? roty_per_frame - 6.283184f
                         : roty_per_frame;
    roty_per_frame /= 30.0f;
    if (act->balance_cnt_adj > 0) {
        sceVu0OuterProduct(&outer0, &nor_pole, act->balance_pole);
        sceVu0OuterProduct(&outer1, &nor_pole, &vec);
        inner = sceVu0InnerProduct(&outer0, &outer1);
        if (inner >= 0.0f) {
            set = 0;
        }
    }
    if (set) {
        sceVu0OuterProduct(&outer0, &nor_pole, &n);
        sceVu0OuterProduct(&outer1, &nor_pole, &vec);
        inner = sceVu0InnerProduct(&outer0, &outer1);
        if (inner >= 0.0f) {
            *(__int128*)nor_pole = *(__int128*)n;
        }
        act->balance_cnt_adj = 0x1E;
        act->balance_ang_adj = ang_per_frame;
        act->balance_roty_adj = roty_per_frame;
        act->balance_bigair = 0;
        *(__int128*)act->balance_pole = *(__int128*)nor_pole;
    }
}

// ktact.c
static void ktactUpdateBalanceAdj(Ctrl* rc) {
    Act* act; // r16
    float inner; // 0x2C(r29)
    float rate; // 0x30(r29)
    float sp_roty; // 0x34(r29)

    act = &rc->act;
    sp_roty = atan2f(-rc->speed[0], -rc->speed[2]);
    if (act->halfpiping != 0) {
        act->balance_cnt_adj = 0;
        return;
    }
    if (act->balance_cnt_adj != 0) {
        act->balance_cnt_adj = (signed int)(act->balance_cnt_adj - 1);
        inner = sbcoreGetInnerAngle180(act->balance_pole, rc->pole);
        rate = act->balance_ang_adj / inner;
        if (!(rate < 1.0f)) {
            rate = 1.0f;
            act->balance_cnt_adj = 0;
        }
        sceVu0InterVector(rc->pole, act->balance_pole, rc->pole, rate);
        rc->rot_pole += act->balance_roty_adj;
        rc->rot_pole = (rc->rot_pole < -3.141592f) ? (6.283184f + rc->rot_pole) : ((rc->rot_pole > 3.141592f) ? (rc->rot_pole - 6.283184f) : rc->rot_pole);
    }
}

// ktact.c
static void ktactEdgeSpeed(float* out, float* lsp, s32 unused, s32 unused2, signed int mat, signed int d2c) {
    *(__int128*)out = *(__int128*)lsp;
    ktactSpeedAdj(out, d2c, mat);
}

// ktact.c
static void ktactSpeedAdj(float* speed, signed int d2c, signed int mat) {
    // signed int mat;
    // signed int d2c;

    signed int side_slip; // r16
    sceVu0FVECTOR lsp; // 0x20(r29)
    sceVu0FMATRIX m; // 0x30(r29)
    float ang; // 0x70(r29)
    float limit_sp_rot_ang; // 0x74(r29)
    float spdown_rate; // 0x78(r29)
    float sss; // 0x7C(r29)

    limit_sp_rot_ang = vktactMatEdgeAdj[mat];
    spdown_rate = 1.0f;
    sss = 0.1f;
    side_slip = vktactMatSideSlip[mat];
    *(__int128*)lsp = *(__int128*)speed;
    ang = atan2f(-lsp[0], -lsp[2]);
    if (!(ang <= 1.570796f)) {
        ang -= 3.141592f;
    } else if (ang < -1.570796f) {
        ang += 3.141592f;
    }
    if ((ang >= -1.3089967f) && (ang > 1.3089967f)) {
    }
    if (d2c > 0) {
        ang *= 1.0f / (float)d2c;
    }
    if (side_slip != 0) {
        if (!(ang <= limit_sp_rot_ang)) {
            ang = limit_sp_rot_ang;
            spdown_rate -= 0.016666668f * sss;
        } else if (ang < -limit_sp_rot_ang) {
            ang = -limit_sp_rot_ang;
            spdown_rate -= 0.016666668f * sss;
        }
    } else if (ang > limit_sp_rot_ang || ang < -limit_sp_rot_ang) {
        spdown_rate -= 0.016666668f * sss;
    }

    ang = -ang;
    if (d2c >= 0x3B) {
        ang = 0.0f;
    }
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixY(m, m, ang);
    sceVu0ApplyMatrix(lsp, m, lsp);
    sceVu0ScaleVectorXYZ(lsp, lsp, spdown_rate);
    *(__int128*)speed = *(__int128*)lsp;
    speed[3] = 1.0f;
}

// ktact.c
static signed int ktactSideSlantToD2C(float side_slant) {
    signed int d2c; // r16 $s0
    float ang; // 0x14(r29)
    float rate; // 0x18(r29)

    d2c = 0;

    ang = (side_slant >= 0.0f) ? side_slant : -side_slant;

    if (!(ang < 1.0471973f)) {
        d2c = 0x3C;
    } else if (!(ang <= 0.34906578f)) {
        if (!(ang <= 1.0471973f)) {
            rate = 1.0f;
        } else {
            ang -= 0.34906578f;
            rate = ang / 0.69813156f;
        }
        d2c = (60.0f * rate);
    }

    return d2c;
}

// ktact.c
static signed int ktactGetHit_base(Pos* cross, float* from, float* to, Col* cross_buff, Col* hit_buff, signed int hit_nbuff, signed int* num_hit, Col* obj_buff, signed int obj_nbuff, signed int* num_obj, signed int water, signed int kill_far) {
    // Size: 0x60, DWARF: 0x75E44
    Col col; // 0xA0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col col_base; // 0x100(r29)
    _anon8 area; // 0x160(r29)
    sceVu0FVECTOR davidFrom; // 0x170(r29)
    sceVu0FVECTOR davidTo; // 0x180(r29)
    sceVu0FVECTOR v; // 0x190(r29)
    signed int y; // r16
    signed int x; // r17
    signed int hit; // r18
    signed int by_to; // r19
    signed int hit_base; // r20
    signed int bx_to; // r21
    signed int by_from; // r22
    signed int bx_from; // r23
    signed int hit_hit; // r30
    signed int tmp; // 0x1A8(r29)
    signed int hit_obs; // 0x1AC(r29)

    hit = 0;
    ktactGetBlockArea(&area, from, to);
    bx_from = area.si[0];
    bx_to = area.si[1];
    by_from = area.si[2];
    by_to = area.si[3];
    *(__int128*)davidFrom = *(__int128*)from;
    *(__int128*)davidTo = *(__int128*)to;
    David_PutRaysInVU0(davidFrom, davidTo, 1);
    col.len = 1.6777e+07f;
    hit_base = 0;
    tmp = 0;
    for (x = bx_from; x <= bx_to; x++) {
        for (y = by_from; y <= by_to; y++) {
            tmp = David_GetBaseCollision2(&col_base, &tmp, x, y, 1);
            if (tmp > 0) {
                if (col_base.len < col.len) {
                    col_base.res[0] = 0;
                    col = col_base;
                    hit_base = 1;
                    hit = 1;
                }
            }
        }
    }
    hit_hit = ktactGetHit_hit(&col, from, to, hit_buff, hit_nbuff, num_hit, water, kill_far);
    if (hit_hit) {
        hit = 1;
    }
    hit_obs = David_ktactGetHit_obs(&col, from, to, obj_buff, obj_nbuff, num_obj, kill_far);
    if (hit_obs) {
        hit = 1;
    }
    if (hit) {
        ktactTmcrsCol2KtactPos(cross, &col);
        if (cross_buff) {
            *cross_buff = col;
        }
    } else {
        *(__int128*)v = *(__int128*)to;
        ktactInitPos(cross);
        *(__int128*)cross->pos = *(__int128*)v;
    }
    return hit;
}

// ktact.c
static signed int ktactGetHit_hit(Col* cross, float* from, float* to, Col* hit_buff, signed int hit_nbuff, signed int* num_hit, signed int water, signed int kill_far) {
    // Size: 0x60, DWARF: 0x75E44
    static Col col_hit[4][4][16];
    // Size: 0x60, DWARF: 0x75E44
    Col col; // 0xA0(r29)
    _anon8 area; // 0x100(r29)
    signed int j; // r16
    signed int i; // r17
    // Size: 0x60, DWARF: 0x75E44
    Col* c; // r18
    signed int current; // r19
    signed int hit; // r20
    signed int tmp; // r21
    signed int x; // r22
    signed int y; // r23
    signed int bx_from; // r30
    signed int bx_to; // 0x11C(r29)
    signed int by_from; // 0x120(r29)
    signed int by_to; // 0x124(r29)
    float hit_len; // 0x128(r29)
    float ci_len; // 0x12C(r29)

    hit = 0;
    ktactGetBlockArea(&area, from, to);
    bx_from = area.si[0];
    bx_to = area.si[1];
    by_from = area.si[2];
    by_to = area.si[3];
    tmp = 0;
    for (y = by_from; y <= by_to; y++) {
        for (x = bx_from; x <= bx_to; x++) {
            c = col_hit[y - by_from][x - bx_from];
            tmp = tmcrsGetHitCollision(c, x, y, from, to);
            c[0].res[0] = tmp;
        }
    }
    if (kill_far) {
        col = *cross;
    } else {
        col.len = 1.6777e+07f;
    }
    for (y = by_from; y <= by_to; y++) {
        for (x = bx_from; x <= bx_to; x++) {
            c = col_hit[y - by_from][x - bx_from];
            tmp = c[0].res[0];
            for (i = 0; i < tmp; i++) {
                if (c[i].len < col.len) {
                    if (c[i].attr & 0xA000) {
                        switch (c[i].attr & 0x7FF) {
                            case 8:
                                if (water == 0) {
                                    continue;
                                }
                                break;
                        }
                        col = c[i];
                        col.res[0] = 3;
                        hit = 1;
                    } else {
                        switch (c[i].no) {
                            case 6:
                                c[i].attr &= 0xF800;
                                c[i].attr |= 0xA;
                                col = c[i];
                                col.res[0] = 3;
                                hit = 1;
                                break;
                            case 7:
                                c[i].attr &= 0xF800;
                                c[i].attr |= 0x9;
                            case 0:
                            case 1:
                                col = c[i];
                                col.res[0] = 3;
                                hit = 1;
                                break;
                        }
                    }
                }
            }
        }
    }
    if (num_hit) {
        *num_hit = 0;
    }
    if (hit_buff) {
        hit_len = col.len;
        current = 0;
        for (y = by_from; y <= by_to; y++) {
            for (x = bx_from; x <= bx_to; x++) {
                c = col_hit[y - by_from][x - bx_from];
                tmp = c[0].res[0];
                for (i = 0; i < tmp; i++) {
                    ci_len = c[i].len;
                    if (kill_far) {
                        if (!(ci_len <= hit_len)) {
                            continue;
                        }
                    }
                    j = 0;
                    if (current < hit_nbuff) {
                        current++;
                        j = 1;
                    } else if (ci_len < hit_buff[current - 1].len) {
                        j = 1;
                    }
                    if (j != 0) {
                        j = current - 1;
                        while (j > 0) {
                            if (!(ci_len < hit_buff[j - 1].len)) {
                                break;
                            }
                            hit_buff[j] = hit_buff[j - 1];
                            j -= 1;
                        }
                        hit_buff[j] = c[i];
                        hit_buff[j].res[0] = 3;
                    }
                }
            }
        }
        if (num_hit) {
            *num_hit = current;
        }
    }
    if (kill_far || hit) {
        *cross = col;
    }
    return hit;
}

// ktact.c
static unsigned int ktactGetHit_base2(Col* cross, float* from, float* to, signed int water, signed int* ret, signed int num) {
    // Size: 0x60, DWARF: 0x75E44
    Col col[8]; // 0xA0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col col_base[8]; // 0x3A0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col col_hit[8]; // 0x6A0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col col_obs[8]; // 0x9A0(r29)
    signed int ret_base[8]; // 0xCA0(r29)
    signed int ret_hit[8]; // 0xCC0(r29)
    signed int ret_obs[8]; // 0xCE0(r29)
    _anon8 area; // 0xD00(r29)
    sceVu0FVECTOR v; // 0xD10(r29)
    signed int i; // r16
    unsigned int hit; // r17
    unsigned int hit_base; // r18
    signed int y; // r19
    signed int x; // r20
    signed int by_to; // r21
    signed int tmp; // r22
    signed int bx_to; // r30
    signed int bx_from; // 0xD20(r29)
    signed int by_from; // 0xD24(r29)
    unsigned int hit_hit; // 0xD28(r29)
    unsigned int hit_obs; // 0xD2C(r29)

    hit = 0;
    ktactGetBlockArea(&area, from, to);
    bx_from = area.si[0];
    bx_to = area.si[1];
    by_from = area.si[2];
    by_to = area.si[3];
    for (i = 0; i < num; i++) {
        col[i].len = 1.6777e+07f;
    }
    David_PutRaysInVU0(from, to, num);
    hit_base = 0;
    tmp = 0;
    for (x = bx_from; x <= bx_to; x++) {
        for (y = by_from; y <= by_to; y++) {
            tmp = David_GetBaseCollision2(col_base, ret_base, x, y, num);
            for (i = 0; i < num; i++) {
                if (ret_base[i] > 0) {
                    if (col_base[i].len < col[i].len) {
                        col_base[i].res[0] = 0;
                        col[i] = col_base[i];
                        hit_base |= 1 << i;
                        hit |= 1 << i;
                    }
                }
            }
        }
    }
    hit_hit = David_ktactGetHit_hit2(col_hit, from, to, water, ret_hit, num);
    if (hit_hit) {
        for (i = 0; i < num; i++) {
            if (col_hit[i].len < col[i].len) {
                col[i] = col_hit[i];
                hit |= 1 << i;
            }
        }
    }
    hit_obs = David_ktactGetHit_obs2(col_obs, from, to, ret_obs, num);
    if (hit_obs) {
        for (i = 0; i < num; i++) {
            if (col_obs[i].len < col[i].len) {
                col[i] = col_obs[i];
                hit |= 1 << i;
            }
        }
    }
    if (hit) {
        for (i = 0; i < num; i++) {
            cross[i] = col[i];
        }
    } else {
        *(__int128*)v = *(__int128*)to;
        for (i = 0; i < num; i++) {
        }
    }
    for (i = 0; i < num; i++) {
        ret[i] = (hit & (1 << i)) ? 1 : 0;
    }
    return hit;
}

static void ktactTmcrsCol2KtactPos(Pos* pos, Col* col) {
    *(__int128*)pos->pos = *(__int128*)col->point;
    *(__int128*)pos->cross = *(__int128*)col->point;
    *(__int128*)pos->normal = *(__int128*)col->normal;
    pos->pos[3] = 1.0f;
    pos->cross[3] = 1.0f;
    pos->normal[3] = 1.0f;
    pos->hit = 1;
    pos->material = col->attr;
    if (col->res[0] == 0) {
        pos->halfpipe = (col->attr & 0x2000) ? 1 : 0;
        pos->ripping = 0;
        pos->bonk = (col->attr & 0x4000) ? 1 : 0;
        pos->low_g = (col->attr & 0x1000) ? 1 : 0;
    } else if (col->res[0] == 3 || col->res[0] == 7) {
        pos->halfpipe = (col->attr & 0x2000) ? 1 : 0;
        pos->ripping = 0;
        pos->bonk = (col->attr & 0x4000) ? 1 : 0;
        pos->low_g = (col->attr & 0x1000) ? 1 : 0;
    } else {
        pos->halfpipe = 0;
        pos->ripping = 0;
        pos->bonk = (col->attr & 0x4000) ? 1 : 0;
        pos->low_g = 0;
    }
    pos->no = col->no;
    pos->len2 = col->len;
    pos->type = col->res[0];
}

static void ktactSbcorePlane2TmcrsCol(Col* col, Plane* pl) {
    *(__int128*)col->normal = *(__int128*)pl->normal;
    *(__int128*)col->point = *(__int128*)pl->cross;
    col->vertex = 0;
    col->attr = (pl->material);
    col->nvertex = 0;
    col->no = pl->almighty2;
    col->len = 0.0f;
    col->rail_no = 0;
    col->obj_no = 0;
    col->obj_attr = pl->almighty3;
    col->obj_type = 0;
    col->res[0] = pl->almighty1;
}

// ktact.c
static void ktactRail2SbcorePlane(Plane* pl, Col* vec, float* mv) {
    signed int no; // r16
    float v[4]; // 0x20(r29)
    float vv[4]; // 0x30(r29)
    float inner; // 0x4C(r29)

    no = vec->no;
    if (no == (vec->nvertex - 1)) {
        no -= 1;
    }
    sceVu0SubVector(vv, vec->vertex[no], vec->vertex[no + 1]);
    v[0] = -vv[2];
    v[2] = vv[0];
    v[1] = 0.0f;
    v[3] = 0.0f;
    *(__int128*)vv = *(__int128*)mv;
    vv[3] = 0.0f;
    inner = sceVu0InnerProduct(v, vv);
    if (!(inner <= 0.0f)) {
        sceVu0ScaleVectorXYZ(v, v, -1.0f);
    }
    sbcoreInitPLANE(pl);
    *(__int128*)pl->cross = *(__int128*)vec->point;
    sceVu0Normalize(pl->normal, v);
    pl->material = 0;
    pl->attribute = 0;
    pl->almighty1 = 3;
    pl->almighty2 = 0;
    pl->slidable = 0;
    pl->available = 1;
}

static signed int ktactGetHit_vector(float* from, float* to, Col* vec_buff, signed int vec_nbuff) {
    // Size: 0x60, DWARF: 0x75E44
    static Col col_vec[4][16];
    signed int bx_from; // 0xAC(r29)
    signed int bx_to; // 0xB0(r29)
    signed int by_from; // 0xB4(r29)
    signed int by_to; // 0xB8(r29)
    float ci_len; // 0xBC(r29)
    signed int j; // r16
    signed int i; // r17
    signed int current; // r18
    // Size: 0x60, DWARF: 0x75E44
    Col* c; // r19
    signed int tmp; // r20
    signed int nvec; // r21
    signed int hit; // r22
    signed int k; // r23
    signed int num_check; // r30

    hit = 0;
    current = 0;
    num_check = 0;
    tmcrsGetArea(&bx_from, &by_from, from);
    tmcrsGetArea(&bx_to, &by_to, to);
    c = col_vec[num_check++];
    tmp = tmcrsGetVectorCollision(c, bx_from, by_from, from, to);
    c[0].res[0] = tmp;
    if ((bx_from != bx_to) && (by_from != by_to)) {
        c = col_vec[num_check++];
        tmp = tmcrsGetVectorCollision(c, bx_to, by_from, from, to);
        c[0].res[0] = tmp;
        c = col_vec[num_check++];
        tmp = tmcrsGetVectorCollision(c, bx_from, by_to, from, to);
        c[0].res[0] = tmp;
        c = col_vec[num_check++];
        tmp = tmcrsGetVectorCollision(c, bx_to, by_to, from, to);
        c[0].res[0] = tmp;
    } else if ((bx_from != bx_to) || (by_from != by_to)) {
        c = col_vec[num_check++];
        tmp = tmcrsGetVectorCollision(c, bx_to, by_to, from, to);
        c[0].res[0] = tmp;
    }
    nvec = 0;
    for (k = 0; k < num_check; k++) {
        c = col_vec[k];
        tmp = c[0].res[0];
        for (i = 0; i < tmp; i++) {
            ci_len = c[i].len;
            j = 0;
            if (current < vec_nbuff) {
                current++;
                j = 1;
            } else if (ci_len < vec_buff[current - 1].len) {
                j = 1;
            }
            if (j != 0) {
                j = current - 1;
                while (j > 0) {
                    if (!(ci_len < vec_buff[j - 1].len)) {
                        break;
                    }
                    vec_buff[j] = vec_buff[j - 1];
                    j -= 1;
                }
                vec_buff[j] = c[i];
                vec_buff[j].res[0] = 4;
                vec_buff[j].attr &= 0xFFFF;
                nvec++;
                hit = 1;
            }
        }
    }
    return nvec;
}

// ktact.c
static void ktactGetHit_rail_hp(float* rfrom, float* rto, float* hpfrom, float* hpto, Col* rail, Col* plant, Col* hp) {
    // Size: 0x60, DWARF: 0x75E44
    static Col col_rail[2][16];
    // Size: 0x60, DWARF: 0x75E44
    static Col col_hp[2][16];
    sceVu0FVECTOR v; // 0xA0(r29)
    sceVu0FVECTOR vv; // 0xB0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col cbuf[2]; // 0xC0(r29)
    sceVu0FVECTOR mv; // 0x180(r29)
    sceVu0FVECTOR hpmove; // 0x190(r29)
    sceVu0FVECTOR v0; // 0x1A0(r29)
    sceVu0FVECTOR v1; // 0x1B0(r29)
    sceVu0FVECTOR cross; // 0x1C0(r29)
    signed int hit[2]; // 0x1D8(r29)
    float ang[2]; // 0x1E0(r29)
    signed int i; // r16
    signed int k; // r17
    // Size: 0x60, DWARF: 0x75E44
    Col* cr; // r18
    signed int no; // r19
    sceVu0FVECTOR* rail_list; // r20
    // Size: 0x60, DWARF: 0x75E44
    Col* chp; // r21
    float* from; // r22
    float* to; // r23
    signed int tmp; // r30
    signed int bx_from; // 0x1EC(r29)
    signed int bx_to; // 0x1F0(r29)
    signed int by_from; // 0x1F4(r29)
    signed int by_to; // 0x1F8(r29)
    signed int j; // 0x1FC(r29)
    signed int current; // 0x200(r29)
    float len; // 0x204(r29)
    float len2; // 0x208(r29)
    signed int num_check; // 0x20C(r29)
    float inner0; // 0x210(r29)
    float inner1; // 0x214(r29)
    float lenxz; // 0x218(r29)
    float anghp; // 0x21C(r29)

    current = 0;
    num_check = 0;
    tmcrsGetArea(&bx_from, &by_from, hpfrom);
    tmcrsGetArea(&bx_to, &by_to, hpto);
    cr = col_rail[num_check];
    chp = col_hp[num_check++];
    tmp = tmcrsGetRailCollision(cr, chp, bx_from, by_from, rto, hpfrom, hpto);
    cr[0].res[0] = tmp & 0xFFFF;
    chp[0].res[0] = (tmp >> 16) & 0xFFFF;
    if ((bx_from != bx_to) || (by_from != by_to)) {
        cr = col_rail[num_check];
        chp = col_hp[num_check++];
        tmp = tmcrsGetRailCollision(cr, chp, bx_to, by_to, rto, hpfrom, hpto);
        cr[0].res[0] = tmp & 0xFFFF;
        chp[0].res[0] = (tmp >> 16) & 0xFFFF;
    }
    if (rail) {
        rail_list = rail->vertex;
        sceVu0SubVector(mv, rto, rfrom);
        mv[1] = 0.0f;
        hit[0] = 0;
        hit[1] = 0;
        len = 1.6777e+07f;
        ang[0] = 1.570796f;
        ang[1] = 1.6777e+07f;
        for (j = 0; j < num_check; j++) {
            cr = col_rail[j];
            tmp = cr[0].res[0];
            for (i = 0; i < tmp; i++) {
                no = cr[i].no;
                if (no == cr[i].nvertex - 1) {
                    no--;
                }
                sceVu0SubVector(v, cr[i].vertex[no], rto);
                sceVu0SubVector(vv, cr[i].vertex[no + 1], rto);
                if (!(cr[i].attr & 0x8000)) {
                    v[1] = 0.0f;
                    vv[1] = 0.0f;
                }
                inner0 = sceVu0InnerProduct(v, mv);
                inner1 = sceVu0InnerProduct(vv, mv);
                if ((inner0 > 0.0f) || (inner1 > 0.0f)) {
                    for (k = 0; k < 2; k++) {
                        if (k == 0) {
                            if (!(cr[i].attr & 0x2000)) {
                                continue;
                            }
                            sceVu0SubVector(v, cr[i].vertex[no + 1], cr[i].vertex[no]);
                            v[1] = 0.0f;
                            len2 = sbcoreGetInnerAngle90(mv, v);
                        } else {
                            if (!(cr[i].attr & 0x8000)) {
                                continue;
                            }
                            sceVu0SubVector(v, cr[i].point, rfrom);
                            v[1] = 0.0f;
                            v[3] = 0.0f;
                            len2 = sceVu0InnerProduct(v, v);
                        }
                        if (!(len2 < ang[k]) && (cr[i].vertex != rail_list)) {
                            continue;
                        }
                        if (cr[i].vertex == rail_list) {
                            ang[k] = 0.0f;
                        } else {
                            ang[k] = len2;
                        }
                        cbuf[k] = cr[i];
                        cbuf[k].res[0] = 5;
                        hit[k] = 1;
                    }
                }
            }
        }
        if (hit[0]) {
            *rail = cbuf[0];
            rail->attr &= 0xFFFF;
        } else {
            rail->len = -1.0f;
            rail->vertex = 0;
        }
        if (hit[1]) {
            *plant = cbuf[1];
            plant->attr &= 0xFFFF;
        } else {
            plant->len = -1.0f;
            plant->vertex = 0;
        }
    }
    if (hp) {
        sceVu0SubVector(hpmove, hpto, hpfrom);
        lenxz = iktactGetLenXZ(hpmove);
        anghp = atan2f(hpmove[1], lenxz);
        if (anghp < 0.0f) {
            anghp = -anghp;
        }
        hit[0] = 0;
        if (anghp <= 0.5235987f) {
            len = 1.6777e+07f;
            for (j = 0; j < num_check; j++) {
                chp = col_hp[j];
                tmp = chp[0].res[0];
                for (i = 0; i < tmp; i++) {
                    no = chp[i].no;
                    if (!(no < chp[i].nvertex - 1)) {
                        no = chp[i].nvertex - 2;
                    }
                    from = chp[i].vertex[no];
                    to = chp[i].vertex[no + 1];
                    *(__int128*)cross = *(__int128*)chp[i].point;
                    sceVu0SubVector(v0, to, from);
                    sceVu0SubVector(v1, cross, from);
                    v0[1] = 0.0f;
                    v1[1] = 0.0f;
                    inner0 = sceVu0InnerProduct(v0, v1);
                    sceVu0SubVector(v0, from, to);
                    sceVu0SubVector(v1, cross, to);
                    v0[1] = 0.0f;
                    v1[1] = 0.0f;
                    inner1 = sceVu0InnerProduct(v0, v1);
                    if (inner0 < 0.0f) {
                        continue;
                    }
                    if (inner1 < 0.0f) {
                        continue;
                    }
                    sceVu0SubVector(v, chp[i].point, hpfrom);
                    sceVu0MulVector(vv, v, v);
                    len2 = vv[0] + vv[2];
                    if (len2 < len) {
                        len = len2;
                        cbuf[0] = chp[i];
                        cbuf[0].res[0] = 5;
                        hit[0] = 1;
                    }
                }
            }
        }
        if (hit[0]) {
            *hp = cbuf[0];
        } else {
            hp->len = -1.0f;
            hp->vertex = 0;
        }
    }
}

// ktact.c
static void ktactGetHit_hp(float* hpfrom, float* hpto, Col* hp) {
    // Size: 0x60, DWARF: 0x75E44
    static Col col_rail[16];
    // Size: 0x60, DWARF: 0x75E44
    static Col col_hp[2][16];
    sceVu0FVECTOR v; // 0xA0(r29)
    sceVu0FVECTOR vv; // 0xB0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col cbuf; // 0xC0(r29)
    sceVu0FVECTOR v0; // 0x120(r29)
    sceVu0FVECTOR v1; // 0x130(r29)
    sceVu0FVECTOR cross; // 0x140(r29)
    signed int i; // r16
    // Size: 0x60, DWARF: 0x75E44
    Col* chp; // r17
    signed int no; // r18
    float* from; // r19
    float* to; // r20
    signed int tmp; // r21
    signed int hit; // r22
    signed int j; // r23
    signed int num_check; // r30
    signed int bx_from; // 0x158(r29)
    signed int bx_to; // 0x15C(r29)
    signed int by_from; // 0x160(r29)
    signed int by_to; // 0x164(r29)
    signed int current; // 0x168(r29)
    float len; // 0x16C(r29)
    float len2; // 0x170(r29)
    signed int check; // 0x174(r29)
    float inner0; // 0x178(r29)
    float inner1; // 0x17C(r29)

    current = 0;
    num_check = 0;
    tmcrsGetArea(&bx_from, &by_from, hpfrom);
    tmcrsGetArea(&bx_to, &by_to, hpto);
    chp = col_hp[num_check++];
    tmp = tmcrsGetRailCollision(col_rail, chp, bx_from, by_from, hpto, hpfrom, hpto);
    chp[0].res[0] = (tmp >> 16) & 0xFFFF;
    if ((bx_from != bx_to) || (by_from != by_to)) {
        chp = col_hp[num_check++];
        tmp = tmcrsGetRailCollision(col_rail, chp, bx_to, by_to, hpto, hpfrom, hpto);
        chp[0].res[0] = (tmp >> 16) & 0xFFFF;
    }
    if (hp) {
        check = 1;
        hit = 0;
        if (check) {
            len = 1.6777e+07f;
            for (j = 0; j < num_check; j++) {
                chp = col_hp[j];
                tmp = chp[0].res[0];
                for (i = 0; i < tmp; i++) {
                    no = chp[i].no;
                    if (!(no < chp[i].nvertex - 1)) {
                        no = chp[i].nvertex - 2;
                    }
                    from = &chp[i].vertex[no];
                    to = &chp[i].vertex[no + 1];
                    *(__int128*)cross = *(__int128*)chp[i].point;
                    sceVu0SubVector(v0, to, from);
                    sceVu0SubVector(v1, cross, from);
                    v0[1] = 0.0f;
                    v1[1] = 0.0f;
                    inner0 = sceVu0InnerProduct(v0, v1);
                    sceVu0SubVector(v0, from, to);
                    sceVu0SubVector(v1, cross, to);
                    v0[1] = 0.0f;
                    v1[1] = 0.0f;
                    inner1 = sceVu0InnerProduct(v0, v1);
                    if (inner0 < 0.0f) {
                        continue;
                    }
                    if (inner1 < 0.0f) {
                        continue;
                    }
                    sceVu0SubVector(v, chp[i].point, hpfrom);
                    sceVu0MulVector(vv, v, v);
                    len2 = vv[0] + vv[2];
                    if (len2 < len) {
                        len = len2;
                        cbuf = chp[i];
                        cbuf.res[0] = 5;
                        hit = 1;
                    }
                }
            }
        }
        if (hit) {
            *hp = cbuf;
        } else {
            hp->len = -1.0f;
            hp->vertex = 0;
        }
    }
}

static signed int ktactGetHit_out(Col* out, float* from, float* to) {
    Col vec_buff[16];
    signed int attr;
    signed int num;
    signed int i;
    signed int ok;

    ok = 0;
    num = ktactGetHit_vector(from, to, vec_buff, 0x10);
    out->vertex = 0;
    out->len = -1.0f;
    for (i = 0; i < num; i++) {
        attr = vec_buff[i].attr & 0x7FF;
        if (attr == 0) {
            *out = vec_buff[i];
            out->nvertex = 2;
            out->no = 0;
            out->attr = 0x4800;
            out->res[0] = 5;
            ok = 1;
            break;
        }
    }
    return ok;
}

// ktact.c
static signed int ktactGetHit_bonk(float* pos, float* speed, float* bonk_point) {
    // Size: 0x60, DWARF: 0x75E44
    Col col_bonk[32]; // 0x40(r29)
    float sp[4]; // 0xC40(r29)
    float spxz[4]; // 0xC50(r29)
    float v[4]; // 0xC60(r29)
    float vxz[4]; // 0xC70(r29)
    signed int bx; // 0xC8C(r29)
    signed int by; // 0xC90(r29)
    float len; // 0xC94(r29)
    float ang; // 0xC98(r29)
    float angxz; // 0xC9C(r29)
    signed int i; // r16
    signed int res; // r17
    signed int bonk_goto; // r18

    bonk_goto = 0;
    tmcrsGetArea(&bx, &by, pos);
    res = tmcrsGetBonkCollision(col_bonk, bx, by, pos);
    res += tmcrsGetObjectBonkCollision(&col_bonk[res], pos);
    if (res > 0) {
        len = 1.6777e+07f;
        *(__int128*)sp = *(__int128*)speed;
        *(__int128*)spxz = *(__int128*)speed;
        spxz[1] = 0.0f;
        for (i = 0; i < res; i++) {
            if (col_bonk[i].point[1] > pos[1]) {
                sceVu0SubVector(v, col_bonk[i].point, pos);
                *(__int128*)vxz = *(__int128*)v;
                vxz[1] = 0.0f;
                ang = sbcoreGetInnerAngle180(sp, v);
                angxz = sbcoreGetInnerAngle180(spxz, vxz);
                if ((angxz < 1.570796f) && (ang < 1.0471973f) && (col_bonk[i].len < len)) {
                    *(__int128*)bonk_point = *(__int128*)col_bonk[i].point;
                    len = col_bonk[i].len;
                    bonk_goto = 1;
                }
            }
        }
    }
    return bonk_goto;
}

// ktact.c
static void ktactGetBlockArea(_anon8* area, float* from, float* to) {
    signed int bx[2]; // 0x88(r29)
    signed int by[2]; // 0x90(r29)
    float x[2]; // 0x98(r29)
    float y[2]; // 0xA0(r29)
    signed int bx_adj[2] = {0, 0}; // 0xA8(r29)
    s32* bx_adjPtr = &bx_adj; // r21
    signed int by_adj[2] = {0, 0}; // 0xB0(r29)
    s32* by_adjPtr = &by_adj; // r22
    float xx; // 0xB8(r29)
    float yy; // 0xBC(r29)
    signed int i; // r16
    signed int bx_from; // r17
    signed int bx_to; // r18
    signed int by_from; // r19
    signed int by_to; // r20

    xx = 300.0f + from[0];
    yy = 300.0f + from[2];
    i = (signed int)xx;
    x[0] = (float)(i % 600);
    x[0] += xx - (float)i;
    i = (signed int)yy;
    y[0] = (float)(i % 600);
    y[0] += yy - (float)i;
    if (x[0] < 0.0f) {
        x[0] = 600.0f + x[0];
    }
    if (y[0] < 0.0f) {
        y[0] = 600.0f + y[0];
    }
    xx = 300.0f + to[0];
    yy = 300.0f + to[2];
    i = (signed int)xx;
    x[1] = (float)(i % 600);
    x[1] += xx - (float)i;
    i = (signed int)yy;
    y[1] = (float)(i % 600);
    y[1] += yy - (float)i;
    if (x[1] < 0.0f) {
        x[1] = 600.0f + x[1];
    }
    if (y[1] < 0.0f) {
        y[1] = 600.0f + y[1];
    }
    for (i = 0; i < 2; i++) {
        if (x[i] < 212.13203f) {
            bx_adj[i] = -1;
        } else if (!(x[i] <= 387.86798f)) {
            bx_adj[i] = 1;
        }
        if (y[i] < 212.13203f) {
            by_adj[i] = -1;
        } else if (!(y[i] <= 387.86798f)) {
            by_adj[i] = 1;
        }
    }
    tmcrsGetArea(&bx[0], &by[0], from);
    tmcrsGetArea(&bx[1], &by[1], to);
    if (bx[0] == bx[1]) {
        bx_from = bx[0];
        bx_to = bx[0];
        if (bx_adj[0] > bx_adj[1]) {
            i = bx_adj[0];
            bx_adj[0] = bx_adj[1];
            bx_adj[1] = i;
        }
        if (bx_adj[0] == bx_adj[1]) {
            if (bx_adj[0] < 0) {
                bx_from += bx_adj[0];
            } else if (bx_adj[0] > 0) {
                bx_to += bx_adj[0];
            }
        } else {
            bx_from += bx_adj[0];
            bx_to += bx_adj[1];
        }
    } else if (bx[0] < bx[1]) {
        bx_from = bx[0];
        bx_to = bx[1];
        if (bx_adj[0] < 0) {
            bx_from += bx_adj[0];
        }
        if (bx_adj[1] > 0) {
            bx_to += bx_adj[1];
        }
    } else {
        bx_from = bx[1];
        bx_to = bx[0];
        if (bx_adj[1] < 0) {
            bx_from += bx_adj[1];
        }
        if (bx_adj[0] > 0) {
            bx_to += bx_adj[0];
        }
    }
    if (by[0] == by[1]) {
        by_from = by[0];
        by_to = by[0];
        if (by_adj[0] > by_adj[1]) {
            i = by_adj[0];
            by_adj[0] = by_adj[1];
            by_adj[1] = i;
        }
        if (by_adj[0] == by_adj[1]) {
            if (by_adj[0] < 0) {
                by_from += by_adj[0];
            } else if (by_adj[0] > 0) {
                by_to += by_adj[0];
            }
        } else {
            by_from += by_adj[0];
            by_to += by_adj[1];
        }
    } else if (by[0] < by[1]) {
        by_from = by[0];
        by_to = by[1];
        if (by_adj[0] < 0) {
            by_from += by_adj[0];
        }
        if (by_adj[1] > 0) {
            by_to += by_adj[1];
        }
    } else {
        by_from = by[1];
        by_to = by[0];
        if (by_adj[1] < 0) {
            by_from += by_adj[1];
        }
        if (by_adj[0] > 0) {
            by_to += by_adj[0];
        }
    }
    area->si[0] = bx_from;
    area->si[1] = bx_to;
    area->si[2] = by_from;
    area->si[3] = by_to;
}

// ktact.c
static void ktactSetHeadHipMatrix(Rider* rider) {
    sceVu0FMATRIX mat; // 0x30(r29)
    Disp* rdd; // r16
    Act* act; // r17

    act = &rider->ctrl.act;
    rdd = &rider->disp;
    ulvumdlGetMatrix(mat, (unsigned char*)(rdd->umd), 6);
    sceVu0MulMatrix(act->mat_head, rdd->mat_base_lw, mat);
    ulvumdlGetMatrix(mat, (unsigned char*)rider->disp.umd, 2);
    sceVu0MulMatrix(act->mat_hip, rdd->mat_base_lw, mat);
}

static void ktactSetHeadHipOffset(float* head, float* hip, Rider* rider) {
    sceVu0FVECTOR* t;
    signed int kids; // r21 $s5
    Ctrl* rc = &rider->ctrl; // r16 $s0
    Disp* rdd = &rider->disp; // r19 $s3
    Pos* nowpos = &rdd->nowpos; // r20 $s4
    Act* act = &rc->act; // r17 $s1
    Sbcore* cd = &act->sbcore; // r22 $s6
    sceVu0FVECTOR pos = {0.0f, 0.0f, 0.0f, 1.0f}; // 0x80(r29)
    sceVu0FMATRIX mat; // 0x90(r29)
    sceVu0FMATRIX rev; // 0xD0(r29)
    float ftmp; // 0x11C(r29)
    t = &pos;
    kids = rc->cheats->kids;

    sceVu0ApplyMatrix((sceVu0FVECTOR*)head, act->mat_head, pos);
    sceVu0SubVector(head, head, nowpos);
    head[3] = 0.0f;
    hip[0] = 0.0f;
    hip[1] = 0.0f;
    hip[2] = 0.0f;
    hip[3] = 0.0f;
    sbcoreGetRotMatrix(mat, rc->pole, rc->rot_pole);
    sceVu0InversMatrix(&rev, &mat);
    sceVu0ApplyMatrix(&pos, rev, head);
    pos[2] = 0.0f;
    if (kids != 0) {
        ftmp = pos[1];
        if (ftmp > 0.0f) {
            ftmp = 0.0f;
        }
        ftmp -= rc->act.sbcore.const_max_relief_gap;
        ftmp *= 1.5f;
        ftmp += rc->act.sbcore.const_max_relief_gap;
        pos[1] = ftmp;
    }
    sceVu0ApplyMatrix((sceVu0FVECTOR*)head, mat, pos);
}

// ktact.c
signed int sbcoreGetHit(Plane* pl, float* from, float* to, signed int move, float height, signed int kill_far) {
    // Size: 0x60, DWARF: 0x79DD3
    Pos cross; // 0xC0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col _cross_buff; // 0x120(r29)
    signed int hid; // r16
    // Size: 0x60, DWARF: 0x75E44
    Col* col; // r17
    signed int hitvec; // r18
    signed int material; // r19
    signed int no; // r20
    signed int i; // r21
    signed int hit; // r22
    // Size: 0x60, DWARF: 0x75E44
    Col* vec_buff; // r23
    signed int nvec; // r30
    signed int nhit; // 0x1DC(r29)
    signed int nobj; // 0x1E0(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col* cross_buff; // 0x1E4(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col* hit_buff; // 0x1E8(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col* obj_buff; // 0x1EC(r29)
    signed int hit_nbuff; // 0x1F0(r29)
    signed int vec_nbuff; // 0x1F4(r29)
    signed int obj_nbuff; // 0x1F8(r29)
    signed int water; // 0x1FC(r29)
    float inner; // 0x200(r29)
    float ang; // 0x204(r29)

    nvec = 0;
    nhit = 0;
    nobj = 0;
    cross_buff = 0;
    hit_buff = 0;
    vec_buff = 0;
    obj_buff = 0;
    hit_nbuff = 0;
    vec_nbuff = 0;
    obj_nbuff = 0;
    water = vktactSlideWater;
    if (move) {
        hit_buff = vktactColHit;
        hit_nbuff = 16;
        vec_buff = vktactColVec;
        vec_nbuff = 16;
        obj_buff = vktactColObj;
        obj_nbuff = 16;
        cross_buff = &_cross_buff;
    } else {
        cross_buff = &vktactColSliding;
    }
    from[3] = 1.0f;
    to[3] = 1.0f;
    hit = ktactGetHit_base(&cross, from, to, cross_buff, hit_buff, hit_nbuff, &nhit, obj_buff, obj_nbuff, &nobj, water, kill_far);
    if (!move && hit) {
        vktactIsSliding = 1;
    }
    if (move) {
        float vec_hi[6] = {15.0f, 20.0f, 25.0f, 30.0f, 40.0f, -1.0f}; // 0x180(r29)
        s32* volatile vec_hiPtr = &vec_hi; // 0x208(r29)
        sceVu0FVECTOR v; // 0x1A0(r29)
        sceVu0FVECTOR vv; // 0x1B0(r29)

        (void)vec_hiPtr;
        hitvec = 0;
        nvec = ktactGetHit_vector(from, to, vec_buff, vec_nbuff);
        for (i = 0; i < nvec; i++) {
            hid = 0;
            switch (vec_buff[i].attr & 0x7FF) {
                case 21:
                    material = 0;
                    hitvec = 1;
                    break;
                case 6:
                    hid++;
                case 5:
                    hid++;
                case 4:
                    hid++;
                case 3:
                    hid++;
                case 2:
                    hid++;
                case 1:
                    if ((vec_hi[hid] < 0.0f) || (height < vec_hi[hid])) {
                        material = 10;
                        hitvec = 1;
                    }
                    break;
                case 20:
                case 12:
                    hid++;
                case 11:
                    hid++;
                case 10:
                    hid++;
                case 9:
                    hid++;
                case 8:
                    hid++;
                case 7:
                    if ((vec_hi[hid] < 0.0f) || (height < vec_hi[hid])) {
                        material = 7;
                        hitvec = 1;
                    }
                    break;
                case 22:
                case 18:
                    hid++;
                case 17:
                    hid++;
                case 16:
                    hid++;
                case 15:
                    hid++;
                case 14:
                    hid++;
                case 13:
                    if ((vec_hi[hid] < 0.0f) || (height < vec_hi[hid])) {
                        material = 9;
                        hitvec = 1;
                    }
                    break;
                case 19:
                    material = 5;
                    hitvec = 1;
                    break;
                case 0:
                    break;
                case 23:
                case 24:
                case 25:
                case 26:
                    break;
            }
            if (hitvec) {
                col = &vec_buff[i];
                if (hit) {
                    if (!(col->len < cross.len2)) {
                        break;
                    }
                }
                no = col->no;
                if (no == col->nvertex - 1) {
                    no--;
                }
                sceVu0SubVector(vv, &col->vertex[no], &col->vertex[no + 1]);
                v[0] = -vv[2];
                v[2] = vv[0];
                v[1] = 0.0f;
                v[3] = 0.0f;
                sceVu0SubVector(vv, to, from);
                vv[3] = 0.0f;
                inner = sceVu0InnerProduct(v, vv);
                if (inner > 0.0f) {
                    sceVu0ScaleVectorXYZ(v, v, -1.0f);
                }
                sceVu0Normalize(cross.normal, v);
                *(__int128*)cross.pos = *(__int128*)col->point;
                *(__int128*)cross.cross = *(__int128*)col->point;
                cross.hit = 1;
                cross.material = material;
                cross.halfpipe = 0;
                cross.ripping = 0;
                cross.bonk = 0;
                cross.low_g = 0;
                cross.no = 0;
                cross.len2 = col->len;
                cross.type = 3;
                hit = 1;
                break;
            }
        }
        vktactNumHit = nhit;
        vktactNumVec = nvec;
        vktactNumObj = nobj;
    }
    from[3] = 0.0f;
    to[3] = 0.0f;
    if (hit) {
        *(__int128*)pl->cross = *(__int128*)cross.cross;
        *(__int128*)pl->normal = *(__int128*)cross.normal;
        pl->cross[3] = 0.0f;
        pl->normal[3] = 0.0f;
        pl->material = cross.material;
        pl->attribute = 0;
        pl->almighty1 = cross.type;
        pl->almighty2 = cross.no;
        pl->almighty3 = cross_buff->obj_attr;
        pl->available = 1;
        switch (cross.type) {
            case 0:
                pl->slidable = 1;
                break;
            case 3:
            case 7:
                if (cross.material & 0xA000) {
                    pl->slidable = 1;
                } else {
                    pl->slidable = 0;
                }
                break;
            case 4:
            default:
                pl->slidable = 0;
                break;
        }
        if (cross.type != 4) {
            sceVu0FVECTOR n = {0.0f, -1.0f, 0.0f, 0.0f}; // 0x1C0(r29)
            s32* volatile nPtr = &n; // 0x20C(r29)

            (void)nPtr;
            ang = sbcoreGetInnerAngle180(n, pl->normal);
            if (!(ang <= 1.570796f)) {
                pl->attribute = 2;
            } else if (!(ang <= 1.2217302f)) {
                pl->attribute = 1;
            }
        }
    } else {
        pl->available = 0;
    }
    return hit;
}

// ktact.c
void sbcoreGetHit2(_anon18* ps) {
    // Size: 0x60, DWARF: 0x79DD3
    Pos cross; // 0x70(r29)
    // Size: 0x60, DWARF: 0x75E44
    Col _cross[8]; // 0xD0(r29)
    // Size: 0x30, DWARF: 0x79C3C
    Plane* pl; // r16
    signed int n; // r17
    signed int ofs; // r18
    unsigned int hit; // r19
    signed int water; // r21
    float ang; // 0x3EC(r29)

    water = vktactSlideWater;
    ofs = ps->ofs;
    hit = ktactGetHit_base2(&_cross[ofs], ps->from[ofs], ps->to[ofs], water, &ps->ret[ofs], ps->num);
    hit <<= ofs;
    if (ps->id_touch >= 0) {
        if (hit & (1 << ps->id_touch)) {
            vktactIsSliding = 1;
            vktactColSliding = _cross[ps->id_touch];
        }
    }
    if (ps->id_head >= 0) {
        if (hit & (1 << ps->id_head)) {
            switch (_cross[ps->id_head].res[0]) {
                case 3:
                    vktactColHit_head[vktactNumHit_head] = _cross[ps->id_head];
                    vktactNumHit_head++;
                    break;
                case 7:
                    vktactColObj_head[vktactNumObj_head] = _cross[ps->id_head];
                    vktactNumObj_head++;
                    break;
            }
        }
    }
    if (ps->id_body >= 0) {
        if (hit & (1 << ps->id_body)) {
            switch (_cross[ps->id_body].res[0]) {
                case 3:
                    vktactColHit_body[vktactNumHit_body] = _cross[ps->id_body];
                    vktactNumHit_body++;
                    break;
                case 7:
                    vktactColObj_body[vktactNumObj_body] = _cross[ps->id_body];
                    vktactNumObj_body++;
                    break;
            }
        }
    }
    for (n = ofs; n < ofs + ps->num; n++) {
        pl = &ps->plane[n];
        if (hit & (1 << n)) {
            ktactTmcrsCol2KtactPos(&cross, &_cross[n]);
            *(__int128*)pl->cross = *(__int128*)cross.cross;
            *(__int128*)pl->normal = *(__int128*)cross.normal;
            pl->cross[3] = 0.0f;
            pl->normal[3] = 0.0f;
            pl->material = cross.material;
            pl->attribute = 0;
            pl->almighty1 = cross.type;
            pl->almighty2 = cross.no;
            pl->almighty3 = _cross[n].obj_attr;
            pl->available = 1;
            switch (cross.type) {
                case 0:
                    pl->slidable = 1;
                    break;
                case 3:
                case 7:
                    if (cross.material & 0xA000) {
                        pl->slidable = 1;
                    } else {
                        pl->slidable = 0;
                    }
                    break;
                case 4:
                default:
                    pl->slidable = 0;
                    break;
            }
            if (cross.type != 4) {
                sceVu0FVECTOR n = {0.0f, -1.0f, 0.0f, 0.0f}; // 0x3D0(r29)
                s32* nPtr = &n; // r20

                (void)nPtr;
                ang = sbcoreGetInnerAngle180(n, pl->normal);
                if (!(ang <= 1.570796f)) {
                    pl->attribute = 2;
                } else if (!(ang <= 1.2217302f)) {
                    pl->attribute = 1;
                }
            }
        } else {
            pl->available = 0;
        }
    }
}

// ktact.c
static signed int ktactUpdateTrickPoint(Act* act, Ctrl* unused1) {
    signed int hold_rate = vktactParamPts_hold_pts_rate_grind; // r19
    signed int grab_rate[10] = {100, 100, 90, 80, 70, 60, 50, 40, 30, 20}; // 0xA0(r29)
    // Size: 0x98, DWARF: 0x791A8
    TrickLink* tl; // r16
    unsigned int pts; // r17
    signed int i; // r18
    signed int end_one_set; // r20
    unsigned int spin_pts; // r21
    unsigned int next_pts; // r22
    signed int keep_pts; // r23
    signed int spin_only; // r30
    signed int end_link; // 0xD4(r29)
    signed int rate; // 0xD8(r29)
    s32* volatile grab_ratePtr = &grab_rate; // 0xDC(r29)

    (void)grab_ratePtr;
    tl = &act->trick_link;
    end_one_set = 0;
    end_link = 0;
    next_pts = 0;
    keep_pts = 0;
    spin_only = 0;
    if (act->trg_touch && !tl->trick_link) {
        ktactResetTrickPointOneSet(tl);
    }
    for (i = 0; i < act->num_set_gap; i++) {
        pts = vsptblGapPoint[vspenvGame->course.no][act->set_gap[i]];
        tl->pts_gap += pts;
    }
    if (act->fakie && (act->trg_jumpup || act->trg_hopup || tl->trg_start_link)) {
        tl->is_bonus_switch = 1;
    }
    if (act->sliding_state == 3) {
        tl->airtime_frame = act->cnt_onair;
        if ((tl->cnt_link > tl->set_top_cnt_link) || tl->is_bonus_spin) {
            if (act->cnt_onair > vktactParamPts_sicktime_start) {
                tl->is_bonus_airtime = 1;
            }
        }
        if (tl->spin_ang) {
            tl->is_bonus_spin = 1;
        }
    }
    if (tl->is_bonus_spin) {
        switch (act->sliding_state) {
            case 5:
            case 4:
            case 7:
                if (tl->cnt_link == tl->set_top_cnt_link + 1) {
                    spin_only = 1;
                }
                break;
            default:
                if (tl->cnt_link == tl->set_top_cnt_link) {
                    spin_only = 1;
                }
                break;
        }
    }
    tl->trg_trick = tl->spenv_get_trick_no;
    if (act->cnt_manual > 0) {
        tl->cnt_total_hold = act->cnt_manual;
    } else if (act->cnt_grind > 0) {
        tl->cnt_total_hold = act->cnt_grind;
    } else if (act->cnt_holding > 0) {
        tl->cnt_total_hold = act->cnt_holding;
    }
    switch (act->sliding_state) {
        case 4:
        case 5:
        case 7:
            hold_rate = vktactParamPts_hold_pts_rate_grind;
            break;
        case 6:
            hold_rate = vktactParamPts_hold_pts_rate_plant;
            break;
        case 2:
            if ((act->pre_state == 5) || (act->pre_state == 4) || (act->pre_state == 7)) {
                hold_rate = vktactParamPts_hold_pts_rate_grind;
                end_one_set = 1;
            }
            break;
        case 0:
        case 1:
        case 3:
        case 8:
        default:
            switch (act->pre_state) {
                case 6:
                    hold_rate = vktactParamPts_hold_pts_rate_plant;
                    end_one_set = 1;
                    break;
                case 5:
                case 4:
                case 7:
                    hold_rate = vktactParamPts_hold_pts_rate_grind;
                    end_one_set = 1;
                    break;
                default:
                    hold_rate = vktactParamPts_hold_pts_rate_grab;
                    break;
            }
            break;
    }
    if (tl->trg_end_link) {
        end_one_set = 1;
    }
    if (act->trg_touch && !act->trg_bonk && (act->pre_state == 3)) {
        if (!act->tumble_type) {
            if (act->touch_perfect && tl->is_bonus_spin) {
                tl->is_bonus_landing = 1;
            } else {
                tl->is_bonus_landing = 0;
            }
        }
        if (act->tumble_type == 1) {
            tl->is_bonus_landing = 2;
        }
        if (tl->trick_link) {
            end_one_set = 1;
            if ((act->sliding_state == 5) || (act->sliding_state == 6) || (act->sliding_state == 4) || (act->sliding_state == 7)) {
                keep_pts = 1;
            }
            if (!act->trg_bonk && spin_only) {
                tl->is_bonus_spin = 0;
                tl->is_bonus_airtime = 0;
            }
        }
    }
    next_pts = 0;
    if (tl->trg_trick >= 0) {
        pts = vsptblTrickPoint[tl->trg_trick];
        if (vspenvGame->mode.game_mode == 2) {
            i = 0;
        } else {
            i = act->num_play_trick[act->fakie][tl->trg_trick];
            if (!(i < 10)) {
                i = 9;
            }
        }
        pts = (pts * grab_rate[i]) / 100;
        if (act->trg_change_grind) {
            tl->pts_current_trick = pts;
        } else {
            tl->pts_trick += tl->pts_current_trick;
            tl->pts_trick += tl->pts_current_hold;
            if (keep_pts) {
                next_pts = pts;
                tl->pts_current_trick = 0;
            } else {
                tl->pts_current_trick = pts;
            }
            tl->pts_current_hold = 0;
            tl->cnt_total_hold = 0;
        }
    }
    tl->pre_spin_ang = tl->last_spin_ang;
    if (tl->pre_spin_ang < 0) {
        tl->pre_spin_ang = -tl->pre_spin_ang;
    }
    if (!tl->cnt_link) {
        tl->link_rate = 100;
    } else if (tl->cnt_link < 14) {
        tl->link_rate = tl->cnt_link * 100;
    } else {
        tl->link_rate = 1300;
        tl->link_rate += (tl->cnt_link - 13) * 50;
    }
    tl->pts_current_hold = 0;
    if (tl->cnt_total_hold > 1) {
        tl->pts_current_hold = (unsigned long)((long)tl->cnt_total_hold * (unsigned long)tl->pts_current_trick * (long)hold_rate) / 1000;
    }
    pts = ktactGetTrickPointOneSet(act);
    rate = ktactGetTrickLinkRate(act);
    tl->current_set_tp = pts;
    tl->current_set_tp_rate = rate;
    spin_pts = tl->pts_current_spin;
    if (tl->is_bonus_landing == 1) {
        spin_pts = (spin_pts * vktactParamPts_perfect_bonus) / 100;
    } else if (tl->is_bonus_landing == 2) {
        spin_pts = (spin_pts * vktactParamPts_sloppy_bonus) / 100;
    }
    tl->pts_current_spin = 0;
    if (spin_only) {
        tl->pts_current_spin = (unsigned long)((unsigned long)pts * (long)rate) / 100;
    }
    if (tl->pts_current_spin > 99999999) {
        tl->pts_current_spin = 99999999;
    }
    if (end_one_set) {
        tl->link_trick_point += (pts * tl->current_set_tp_rate) / 100;
        tl->link_trick_point += spin_pts;
        if (tl->link_trick_point > 99999999) {
            tl->link_trick_point = 99999999;
        }
        ktactResetTrickPointOneSet(tl);
        if (tl->trg_end_link) {
            end_link = 1;
        } else {
            tl->pts_current_trick = next_pts;
            tl->current_set_tp = next_pts;
            tl->current_set_tp_rate = rate;
            if (keep_pts) {
                tl->set_top_cnt_link = tl->pre_cnt_link;
            } else {
                tl->set_top_cnt_link = tl->cnt_link;
            }
            tl->added_airtime = 0;
        }
    }
    tl->trg_get_pts = 0;
    tl->get_point = 0;
    pts = tl->link_trick_point;
    pts += (unsigned long)((unsigned long)tl->current_set_tp * (unsigned long)tl->current_set_tp_rate) / 100;
    pts = (unsigned long)((unsigned long)pts * (long)tl->link_rate) / 100;
    if (tl->last_point < pts) {
        tl->get_point = pts - tl->last_point;
        tl->last_point = pts;
        tl->trg_get_pts = 1;
    }
    if ((act->tumble_type == 2) || (act->tumble_type == 3) || (act->tumble_type == 4) || (act->tumble_type == 5)) {
        pts = tl->link_trick_point;
        pts += (unsigned long)((unsigned long)tl->current_set_tp * (unsigned long)tl->current_set_tp_rate) / 100;
        pts = (unsigned long)((unsigned long)pts * (long)tl->link_rate) / 100;
        if (pts > 99999999) {
            pts = 99999999;
        }
        if (tl->trick_link) {
            tl->last_link_trick_point = pts;
            tl->link_trick_point = 0;
            tl->link_rate = 0;
            ktactResetTrickPointOneSet(tl);
            ktactRecoverNumPlayTrick(act);
        } else {
            ktactInitTLink(tl);
            tl->last_link_trick_point = pts;
            tl->link_trick_point = 0;
            tl->link_rate = 0;
        }
    } else if (end_link) {
        pts = tl->link_trick_point;
        pts += (unsigned long)((unsigned long)tl->current_set_tp * (unsigned long)tl->current_set_tp_rate) / 100;
        pts = (unsigned long)((unsigned long)pts * (long)tl->link_rate) / 100;
        if (pts > 99999999) {
            pts = 99999999;
        }
        tl->total_trick_point += pts;
        tl->last_link_trick_point = pts;
        tl->link_trick_point = 0;
        tl->link_rate = 0;
        if (tl->total_trick_point > 99999999) {
            tl->total_trick_point = 99999999;
        }
        tl->total_trick_num += tl->cnt_link;
        if ((tl->best_link_pts < pts) && !(tl->cnt_link < 2)) {
            tl->best_link_num = tl->cnt_link;
            tl->best_link_pts = pts;
            tl->get_the_best = 1;
        } else {
            tl->get_the_best = 0;
        }
        ktactResetTrickPointOneSet(tl);
        ktactResetNumPlayTrickInLink(act);
    } else if (!tl->trick_link && !tl->trg_start_link && act->trg_touch) {
        ktactInitTLink(tl);
    }
    tl->pre_cnt_link = tl->cnt_link;
    if (act->fakie && keep_pts) {
        tl->is_bonus_switch = 1;
    }
    return end_link;
}

static unsigned int ktactGetTrickPointOneSet(Act* act) {
    signed int i;
    TrickLink* tl = &act->trick_link;
    unsigned int pts = 0;
    unsigned int grab;
    signed int tmp;

    grab = tl->pts_trick + tl->pts_current_trick;
    grab += tl->pts_current_hold;
    pts = grab + tl->pts_gap;
    if (tl->is_bonus_spin != 0) {
        if (tl->cnt_link == tl->set_top_cnt_link) {
            tmp = tl->spin_ang;
            if (tmp < 0) {
                tmp = -tmp;
            }
            tmp = tmp - 1;
            if (tmp < 0) {
                tmp = 0;
            }
            for (i = 0; i <= tmp; i++) {
                pts += (i + 1) * 50;
            }
        }
    }
    return pts;
}

static unsigned int ktactGetTrickLinkRate(Act* act) {
    signed int spin_rate[12] = {150, 200, 300, 400, 500, 600, 700, 800, 900, 950, 1000, 1050};
    s32* spin_ratePtr = &spin_rate;
    TrickLink* tl = &act->trick_link;
    unsigned long bonus_switch = 100;
    unsigned long bonus_spin = 100;
    unsigned long bonus_airtime = 100;
    unsigned long bonus_landing = 100;
    unsigned long bonus_nollie = 100;
    unsigned long rate;
    signed int tmp;

    (void)spin_ratePtr;
    if (tl->is_bonus_switch) {
        bonus_switch = vktactParamPts_switch_bonus;
    }
    if (tl->is_bonus_spin && tl->cnt_link > tl->set_top_cnt_link) {
        tmp = tl->spin_ang;
        if (tmp < 0) {
            tmp = -tmp;
        }
        tmp = tmp - 1;
        if (tmp < 0) {
            tmp = 0;
        }
        if (tmp < 12) {
            rate = spin_rate[tmp];
        } else {
            rate = spin_rate[11];
            tmp = tmp - 12;
            rate = rate + (tmp + 1) * 50;
        }
        bonus_spin = rate;
    }
    bonus_airtime = 100;
    if (tl->is_bonus_airtime) {
        bonus_airtime = vktactParamPts_sicktime_bonus;
    }
    if (act->trg_touch && !act->trg_bonk && act->pre_state == essOnAir) {
        if (tl->is_bonus_landing == 1) {
            bonus_landing = vktactParamPts_perfect_bonus;
        } else if (tl->is_bonus_landing == 2) {
            bonus_landing = vktactParamPts_sloppy_bonus;
        }
    }
    rate = bonus_switch * bonus_spin * bonus_airtime * bonus_landing * bonus_nollie / 100000000;
    return rate;
}

static void ktactAddSpecialTrickCharge(Act* act) {
    unsigned int tp; // r16 // s0
    unsigned int charge; // r17 // s1
    signed int num; // r18 // s2
    unsigned int add_charge; // r19 // s3
    // Size: 0x98, DWARF: 0x791A9
    TrickLink* tl; // r20 // s4
    unsigned int utmp; // r21 //s5

    tl = &act->trick_link;
    tp = tl->get_point;
    tp += act->special_remainder_tp;
    act->special_remainder_tp = 0;
    if (vktactParamSpt_one_stock_tp < tp) {
        tp = vktactParamSpt_one_stock_tp;
    }
    if (act->trg_tumble_type >= 2) {
        tp = 0;
    }
    utmp = (vktactParamSpt_one_stock_tp / 100);
    act->special_remainder_tp = (tp % (utmp));
    num = act->special_num + (tp / vktactParamSpt_one_stock_tp);
    charge = act->special_charge;
    add_charge = ((tp % vktactParamSpt_one_stock_tp) * 100) / vktactParamSpt_one_stock_tp;
    charge += add_charge;
    if ((num > 0) || (charge >= 100)) {
        num = 1;
        charge = 100;
    }
    if (act->special_left_time > 0) {
        if ((add_charge) || (num > 0)) {
            act->special_left_time = (s32)((act->special_total_time * charge) / 100);
            act->special_charge = charge;
            act->special_num = 0;
        }
    } else {
        act->special_charge = charge;
        act->special_num = num;
    }
}

static void ktactAddBoostCharge(Act* act) {
    unsigned int charge; // r16 // s0
    signed int num; // r17 // s1
    unsigned int tp; // r18 // s2
    // Size: 0x98, DWARF: 0x791A9
    TrickLink* tl; // r19 // s3

    // (void*)tp;

    tl = &act->trick_link;
    if (act->boost_left_time == 0) {
        tp = tl->last_link_trick_point;
        num = act->boost_num + (tp / 5000);
        charge = act->boost_charge;
        charge += ((tp % 5000) * 100) / 5000;
        if (charge >= 0x64) {
            num += charge / 100;
            charge = charge % 100;
        }
        if (9 < num) {
            num = 9;
            charge = 0x63;
        }
        act->boost_charge = charge;
        act->boost_num = num;
    }
}

void ktactSetGap(signed int pid, signed short gap_no) {
    Act* act = &vspRider[pid]->ctrl.act;
    act->set_gap[act->num_set_gap++] = gap_no;
}

void ktactSetRecover(s32 pid, float* pos, float roty, float speed, s32 warp) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act; // r16

    act = &vspRider[pid]->ctrl.act;
    if ((act->pass_finish_line2 != 0) || (act->cnt_fall > 0) || (act->cnt_warp > 0)) {
        return;
    }
    act->recover_roty = roty;
    act->recover_speed = ((1000.0f * speed) / 3600.0f);
    *(__int128*)act->recover_pos = *(__int128*)pos;
    if (warp != 0) {
        act->reserve_fall = 0;
        act->cnt_warp = 0x78;
    } else {
        act->reserve_fall = 1;
        nmactPlayVoice(pid, (vspModeData.game_count % 3U) + 0x14);
    }
    act->num_reserve_trick = 0;
    act->num_reserve_grab = 0;
    ktactCommandResetAll(act);
}

void ktactSetGrindToHp(signed int pid, signed int hp) {
    Act* act = &vspRider[pid]->ctrl.act;
    act->hips = hp ? 0 : 1;
}

void ktactSetAccelOnGrind(signed int pid, signed int acc) {
    Act* act = &vspRider[pid]->ctrl.act;
    act->gr_back_accel = acc;
}

static void ktactSetAccelWay(Ctrl* rc) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act = &rc->act; // r16
    float way[4]; // 0x20(r29)

    tmetcGetAcc(&way[0], rc->nowpos.pos);
    way[1] = 0.0f;
    sceVu0Normalize(&way[0], &way[0]);
    act->target_way = atan2f(-way[0], -way[2]);
}

void ktactCtrlIntro(Rider* rider, s32 count) {
    // Size: 0x2C00, DWARF: 0x7627B
    Ctrl* rc = &rider->ctrl; // r17 // s1
    // Size: 0x2580, DWARF: 0x76810
    Act* act = &rc->act; // 0xA0(r29)
    signed int palmer; // r21 // s3
    signed int num_mot; // r22 // s4
    signed int id; // r16 // s0
    signed int uad; // r23 // s7
    signed int nloop; // r18 // s2
    signed int inter; // r30 // s8
    signed int unused1;
    signed int unused2;
    signed int brend; // 0xAC(r29)

    (void)unused1;
    (void)unused2;
    palmer = rc->param->no == 0 ? 1 : 0;
    num_mot = (palmer ? 0x12 : 0xD) + 1;
    id = -1;
    uad = 4;
    nloop = 0;
    inter = 0;
    brend = 0;
    count %= 1200;
    if ((count == 120) || (count == 360) || (count == 600) || (count == 840) || (count == 1080)) {
        id = rand() % num_mot;
        if (id == 0) {
            nloop = -1;
        }
        akevResetEffect2(rider->pid);
    }
    if (id >= 0) {
        ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
    }
}

void ktactCtrlReady(Rider* rider, s32 count) {
    signed int start_frame; // r16
    signed int id = -1; // r17
    // no 18 due to ternary.
    signed int uad = 4; // r19
    signed int nloop = 0; // r20
    signed int inter = 0; // r21
    signed int brend = 0; // r22

    if (vspenvGame->mode.game_mode == Multiplayer && vspenvGame->mode.match_rule == MatchHorse) {
        start_frame = 5;
    } else {
        start_frame = 0x78;
    }

    if (count < start_frame) {
        id = rider->ctrl.act.goofy ? 0x13 : 0x14;
    }
    if (count == (start_frame + 0x11)) {
        ktmotEndFreeMotion(rider);
    }
    if (id >= 0) {
        ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
    }
}

// ktact.c
void ktactCtrlFinish(Rider* rider, s32 count) {
    Ctrl* rc; // r18
    Act* act; // r16
    Mot* mot; // 0xA8(r29)
    MotFrames* motnow; // r19
    signed int multi; // 0xAC(r29)
    signed int id; // r17
    signed int uad; // r20
    signed int nloop; // r21
    signed int inter; // 0xB0(r29)
    signed int brend; // 0xB4(r29)
    VspDispResult* res; // r23
    signed int end_brake; // 0xB8(r29)
    VspDispResult* best; // r30
    signed int enemy_pid; // 0xBC(r29)
    Rider* rider1; // r22
    ModelChange* ch; // 0xC0(r29)
    signed int nowframe; // 0xC4(r29)
    signed int nextframe; // 0xC8(r29)
    rc = &rider->ctrl;
    act = &rc->act;
    mot = &rc->mot;
    motnow = &mot->now;
    multi = vspModeData.num_window == 2 ? 1 : 0;
    id = -1;
    uad = 3;
    nloop = 0;
    inter = 0x1E;
    brend = 1;
    res = &vspDispResult[rider->pid];
    end_brake = 1;
    (void)nloop;
    (void)res;
    if (act->end_sliding == 0) {
        if ((vspDispEnv.mode == 4) && (vspModeData.flow_mode == 7) && (vspReplay[rider->pid]->num_frame == 0x5B68)) {
            end_brake = 0;
            vspModeData.fade = 1;
            vspModeData.to_end_sliding = 1;
        }
        ktactCtrl(rider, end_brake);
        if ((act->cnt_reserve_quit >= 0x384) || (count > 0x384)) {
            act->end_sliding = 1;
        }
        if (act->end_sliding != 0) {
            id = ktactGetEndMotion(rider);
            if (multi == 0) {
                ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
            }
            ktactSetCaminfo(&rc->cam, rc);
            rc->cam.trg_start_endmot = 1;
            ktactSetSeinfo(&rc->se, rc);
            vspModeData.to_end_sliding = 1;
        }
        if ((act->cnt_quit == 0) && ((vspModeData.flow_mode == 3) || (vspModeData.flow_mode == 4))) {
            if (act->pass_finish_line != 0) {
                res->comp_time = vspVsData.result[rider->pid].time;
            }
            if (vspModeData.horse_pid < 0) {
                res->trick_landing = act->trick_link.total_trick_num;
                res->comb_num = act->trick_link.best_link_num;
                res->comb_points = act->trick_link.best_link_pts;
            } else {
                best = &vspVsData.result[rider->pid].horse_best_combo;
                enemy_pid = (rider->pid + 1) % 2;
                best->trick_landing = (best->trick_landing + act->trick_link.total_trick_num);
                if (best->comb_points < act->trick_link.best_link_pts) {
                    best->rank = res->rank;
                    best->comb_num = act->trick_link.best_link_num;
                    best->comb_points = act->trick_link.best_link_pts;
                    best->comp_time = res->comp_time;

                    best->comb_info = res->comb_info;
                    // var_a3 = res->comb_info;
                    // var_a2 = best->comb_info;
                    // var_a1 = 0x102;
                    // do {
                    //     // temp_a0_2 = var_a3->unk0;
                    //     // temp_v1 = var_a3->unk4;
                    //     var_a3 += 8;
                    //     var_a1 -= 1;
                    //     var_a2->unk0 = var_a3->unk0;
                    //     var_a2->unk4 = var_a3->unk4;
                    //     var_a2 += 8;
                    // } while (var_a1 > 0);
                }
                *res = *best;
                // var_a0 = 0x209;
                // do {
                //     temp_v1_2 = *best;
                //     best += 4;
                //     var_a0 -= 1;
                //     *res = temp_v1_2;
                //     res += 4;
                // } while (var_a0 > 0);
                vspDispResult[enemy_pid] = vspVsData.result[enemy_pid].horse_best_combo;
                // var_a0_2 = 0x209;
                // do {
                //     temp_v1_3 = *best;
                //     best += 4;
                //     var_a0_2 -= 1;
                //     *res = temp_v1_3;
                //     res += 4;
                // } while (var_a0_2 > 0);
            }
        }
    } else {
        rider1 = vspRider[(rider->pid + 1) % 2];
        if (vspModeData.flow_mode == 4) {
            if (multi == 0) {
                if ((vspModeData.horse_pid < 0) && (vgmsysPad[0]->trg & 0x840)) {
                    vspModeData.fade = 1;
                }
            } else {
                if (vgmsysPad[0]->trg & 0x840) {
                    vspModeData.fade = 1;
                }
                if (vgmsysPad[1]->trg & 0x840) {
                    vspModeData.fade = 1;
                }
            }
        }
        if ((motnow->frame >= motnow->num_frame) && (act->wait_motion == 0) && (act->wait_vs == 0)) {
            if (multi == 0) {
                if (vspModeData.horse_pid < 0) {
                    vspModeData.fade = 1;
                }
                if (rider->ctrl.mot.now.id != 3) {
                    id = 0;
                    uad = 4;
                    nloop = -1;
                    ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
                }
            } else if (act->cnt_quit <= rider1->ctrl.act.cnt_quit) {
                if (motnow->uad == uad) {
                    vspModeData.fade = 1;
                    if (rider->ctrl.mot.now.id != 3) {
                        id = 0;
                        uad = 4;
                        nloop = -1;
                        ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
                    }
                    if (rider1->ctrl.mot.now.id != 3) {
                        id = 0;
                        uad = 4;
                        nloop = -1;
                        ktmotSetNewAnim2(rider1, id, uad, nloop, inter, brend);
                    }
                } else if (rider1->ctrl.act.end_sliding != 0) {
                    id = ktactGetEndMotion(rider);
                    ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
                    id = ktactGetEndMotion(rider1);
                    ktmotSetNewAnim2(rider1, id, uad, nloop, inter, brend);
                }
            } else if (rider1->ctrl.act.end_sliding == 0) {
                id = ktactGetIntroMotion(rider);
                uad = 4;
                ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
                act->wait_motion = 1;
                act->wait_vs = 1;
            }
        } else if ((multi != 0) && (act->wait_vs != 0)) {
            if ((rider1->ctrl.act.end_sliding != 0) && (act->wait_motion != 0)) {
                id = ktactGetEndMotion(rider);
                ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
                id = ktactGetEndMotion(rider1);
                ktmotSetNewAnim2(rider1, id, uad, nloop, inter, brend);
                act->wait_motion = 0;
                act->wait_vs = 0;
            } else if ((motnow->frame >= motnow->num_frame) && (act->wait_motion != 0)) {
                do {
                    id = ktactGetIntroMotion(rider);
                } while (id == motnow->id);
                uad = 4;
                ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
            }
        }
        mot->freemotion = 1;
        rc->splen = 0.0f;
        rc->splenxz = 0.0f;
        rc->speed[0] = 0.0f;
        rc->speed[1] = 0.0f;
        rc->speed[2] = 0.0f;
        rc->speed[3] = 0.0f;
        ktactSetCaminfo(&rc->cam, rc);
        ktactSetSeinfo(&rc->se, rc);
        if (motnow->uad == 3) {
            ch = rider->disp.model_change;
            nowframe = motnow->frame;
            nextframe = nowframe + mot->motion_speed;
            switch (motnow->id) {
                case 8:
                    if ((nowframe < 0x1220) && (nextframe >= 0x1220)) {
                        maModelChangeSet(ch, 1);
                    } else if ((nowframe < 0x2C10) && (nextframe >= 0x2C10)) {
                        maModelChangeSet(ch, 2);
                    }
                    break;
                case 10:
                    if ((nowframe < 0xA00) && (nextframe >= 0xA00)) {
                        maModelChangeSet(ch, 1);
                    }
                    break;
            }
        }
    }
    act->cnt_quit++;

    (void)motnow;
}

void ktactCtrlHorseReady(Rider* rider, signed int count) {
    signed int id = -1;
    signed int uad = 4;
    signed int nloop = -1;
    signed int inter = 0;
    signed int brend = 0;

    if (count == 0) {
        id = 13;
    }
    if (id >= 0) {
        ktmotSetNewAnim2(rider, id, uad, nloop, inter, brend);
    }
}

static signed int ktactGetIntroMotion(Rider* rider) {
    Ctrl* rc = &rider->ctrl;
    Act* act = &rc->act;
    signed int palmer;
    signed int num_mot;
    signed int id;

    palmer = rc->param->no == 0 ? 1 : 0;
    num_mot = (palmer ? 0x12 : 0xD) + 1;
    id = -1;
    id = rand() % num_mot;
    return id;
}

// ktact.c
static signed int ktactGetEndMotion(Rider* rider) {
    signed int id; // r16
    signed int joy; // r17
    signed int rand_num; // r18
    signed int goggle; // r19
    signed int pid; // r20
    signed int rank0; // r21
    signed int rank1; // r22
    signed int palmer; // r23

    palmer = (rider->ctrl.param->no == 0) ? 1 : 0;
    pid = rider->pid;
    rand_num = vspReplay[pid]->rand_num;
    switch (vspenvGame->mode.game_mode) {
        case 0:
            if (nmdispSearchRank(pid) < 0) {
                joy = 1;
            } else {
                joy = 0;
            }
            break;
        case 1:
            rank0 = vspDispEnvChar[pid].rank;
            rank1 = vspDispEnvChar[(pid + 1) % 2].rank;
            if ((rank0 == rank1) || vspEndRun || vspEndRunReplay) {
                joy = 1;
            } else if (rank0 < rank1) {
                joy = 0;
            } else {
                joy = 2;
            }
            break;
        case 2:
        default:
            joy = 1;
            break;
    }
    if (joy == 0) {
        if (palmer) {
            id = rand_num % 1;
            id += 11;
        } else {
            id = rand_num % 3;
        }
    } else if (joy == 1) {
        id = rand_num % 2;
        id += 9;
    } else {
        if (palmer) {
            id = rand_num % 1;
            id += 12;
        } else {
            id = rand_num % 2;
            id += 3;
        }
    }
    goggle = 1;
    if (rider->ctrl.param->wear > 0) {
        goggle = 0;
    } else if (!(rider->ctrl.param->no < 10)) {
        goggle = 0;
    } else if (rider->ctrl.cheats->big_head) {
        goggle = 0;
    } else if (rider->ctrl.cheats->kids) {
        goggle = 0;
    }
    if (goggle == 0) {
        if (id == 8) {
            id--;
        } else if (id == 10) {
            id--;
        }
    }
    return id;
}

static signed int ktactGetCharHitPlane(Plane* pl, signed int pid, float* nextpos) {
    Rider* rider0;
    Rider* rider1;
    signed int hit = 0;

    if (vspModeData.num_window == 1) {
        return 0;
    }
    rider0 = vspRider[pid];
    rider1 = vspRider[(pid + 1) % 2];
    if (rider0->ctrl.act.cnt_warp > 0 || rider1->ctrl.act.cnt_warp > 0) {
        return 0;
    }
    if (rider0->ctrl.act.sliding_state == essTumble) {
        if (rider1->ctrl.act.sliding_state == essTumble) {
            return 0;
        }
        if (rider0->ctrl.nowpos.hit == 0) {
            return 0;
        }
    }
    if (rider0->ctrl.act.sliding_state == essOnAir && rider1->ctrl.act.sliding_state == essTumble) {
        return 0;
    }
    hit = ktactCheckHitChar_1(pl, rider0, nextpos, rider1);
    return hit;
}

// ktact.c
static signed int ktactCheckHitChar_1(Plane* pl, Rider* rider0, float* nextpos, Rider* rider1) {
    sceVu0FVECTOR area[2][4] = {// 0xA0(r29)
                                {{5.0f, 5.0f, 5.0f, 1.0f},
                                 {5.0f, 5.0f, -5.0f, 1.0f},
                                 {-5.0f, 5.0f, -5.0f, 1.0f},
                                 {-5.0f, 5.0f, 5.0f, 1.0f}},
                                {{5.0f, -10.0f, 5.0f, 1.0f},
                                 {5.0f, -10.0f, -5.0f, 1.0f},
                                 {-5.0f, -10.0f, -5.0f, 1.0f},
                                 {-5.0f, -10.0f, 5.0f, 1.0f}}};
    s32* areaPtr = &area; // r22
    sceVu0FMATRIX lwm0; // 0x120(r29)
    sceVu0FMATRIX lwm1; // 0x160(r29)
    sceVu0FMATRIX llm; // 0x1A0(r29)
    sceVu0FVECTOR area1[2][4]; // 0x1E0(r29)
    sceVu0FVECTOR v; // 0x260(r29)
    sceVu0FVECTOR dis; // 0x270(r29)
    signed int j; // r16
    signed int i; // r17
    signed int hit; // r18
    // Size: 0x2C00, DWARF: 0x7627B
    Ctrl* rc0; // r19
    // Size: 0x2C00, DWARF: 0x7627B
    Ctrl* rc1; // r20
    Tumble_Type tt; // r21
    // Size: 0x2580, DWARF: 0x76810
    Act* act0; // r23
    // Size: 0x2580, DWARF: 0x76810
    Act* act1; // r30
    float inner; // 0x280(r29)
    float ang; // 0x284(r29)
    float splen; // 0x288(r29)
    float dif_ang; // 0x28C(r29)
    float spx; // 0x290(r29)
    float spy; // 0x294(r29)

    rc0 = &rider0->ctrl;
    rc1 = &rider1->ctrl;
    act0 = &rc0->act;
    act1 = &rc1->act;
    hit = 0;
    sbcoreGetRotMatrix(lwm0, rc0->disp_pole, rc0->disp_rot_pole);
    sceVu0TransMatrix(lwm0, lwm0, nextpos);
    sbcoreGetRotMatrix(lwm1, rc1->disp_pole, rc1->disp_rot_pole);
    sceVu0TransMatrix(lwm1, lwm1, rc1->nowpos.pos);
    sceVu0InversMatrix(lwm0, lwm0);
    sceVu0MulMatrix(llm, lwm0, lwm1);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            sceVu0ApplyMatrix(area1[i][j], llm, area[i][j]);
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            hit = ktactCheckBoxLineCol(area, area1[i][j], area1[i][(j + 1) % 4]);
            if (hit) {
                break;
            }
        }
        if (hit) {
            break;
        }
    }
    if (!hit) {
        for (i = 0; i < 4; i++) {
            hit = ktactCheckBoxLineCol(area, area1[0][i], area1[1][i]);
            if (hit) {
                break;
            }
        }
    }
    if (hit) {
        sceVu0SubVector(v, nextpos, rc0->nowpos.pos);
        sceVu0SubVector(dis, rc1->nowpos.pos, rc0->nowpos.pos);
        inner = sceVu0InnerProduct(v, rc1->speed);
        if (inner > 0.0f) {
            inner = sceVu0InnerProduct(v, dis);
            if (inner < 0.0f) {
                hit = 0;
            }
        } else {
            inner = sceVu0InnerProduct(v, dis);
            if (inner < 0.0f) {
                hit = 0;
            }
        }
    }
    if (hit && pl) {
        ang = atan2f(-rc0->speed[0], -rc0->speed[2]);
        dif_ang = ang - atan2f(-rc1->speed[0], -rc1->speed[2]);
        dif_ang = dif_ang < -3.141592f
                      ? 6.283184f + dif_ang
                  : (dif_ang > 3.141592f)
                      ? dif_ang - 6.283184f
                      : dif_ang;
        if (dif_ang < 0.0f) {
            dif_ang = -dif_ang;
        }
        spx = rc0->splen * cosf(dif_ang);
        spy = rc0->splen * sinf(dif_ang);
        spx = rc1->splen - spx;
        splen = (spx * spx) + (spy * spy);
        splen = isbcoreSqrtf(splen);
        if (splen < vktactMatTumbleSpeed_normal[1]) {
            tt = 1;
        } else {
            tt = 2;
        }
        ktactReserveTumble(rider1->pid, ang, tt);
        sceVu0SubVector(pl->normal, rc0->nowpos.pos, rc1->nowpos.pos);
        pl->normal[1] = 0.0f;
        sceVu0Normalize(pl->normal, pl->normal);
        *(__int128*)pl->cross = *(__int128*)rc0->nowpos.pos;
        pl->available = 1;
    }
    return hit;
}

static signed int ktactCheckBoxLineCol(sceVu0FVECTOR (*box)[4], float* from, float* to) {
    signed int hit = 0;
    sceVu0FVECTOR tri[3];
    signed int i;

    for (i = 0; i < 2; i++) {
        *(__int128*)tri[0] = *(__int128*)box[i][0];
        *(__int128*)tri[1] = *(__int128*)box[i][1];
        *(__int128*)tri[2] = *(__int128*)box[i][2];
        hit = ktactCheckTriLineCol(tri, from, to);
        if (hit == 0) {
            *(__int128*)tri[0] = *(__int128*)box[i][2];
            *(__int128*)tri[1] = *(__int128*)box[i][3];
            *(__int128*)tri[2] = *(__int128*)box[i][0];
            hit = ktactCheckTriLineCol(tri, from, to);
        }
        if (hit != 0) {
            break;
        }
    }
    if (hit == 0) {
        for (i = 0; i < 4; i++) {
            *(__int128*)tri[0] = *(__int128*)box[0][i];
            *(__int128*)tri[1] = *(__int128*)box[0][(i + 1) % 4];
            *(__int128*)tri[2] = *(__int128*)box[1][(i + 1) % 4];
            hit = ktactCheckTriLineCol(tri, from, to);
            if (hit == 0) {
                *(__int128*)tri[0] = *(__int128*)box[1][(i + 1) % 4];
                *(__int128*)tri[1] = *(__int128*)box[1][i];
                *(__int128*)tri[2] = *(__int128*)box[0][i];
                hit = ktactCheckTriLineCol(tri, from, to);
            }
            if (hit != 0) {
                break;
            }
        }
    }
    return hit;
}

static signed int ktactCheckTriLineCol(sceVu0FVECTOR* tri, float* from, float* to) {
    signed int hit = 0;
    float nor[4];
    float cross[4];
    float v0[4];
    float v1[4];
    float v[4];
    float d;
    float a;
    float b;
    signed int i;

    sceVu0SubVector(v0, tri[1], tri[0]);
    sceVu0SubVector(v1, tri[2], tri[0]);
    sceVu0OuterProduct(nor, v0, v1);
    d = -sceVu0InnerProduct(nor, tri[0]);
    a = d + sceVu0InnerProduct(nor, from);
    b = d + sceVu0InnerProduct(nor, to);
    if (a * b < 0.0f) {
        if (a < 0.0f) {
            a = -a;
        }
        if (b < 0.0f) {
            b = -b;
        }
        sceVu0InterVector(cross, from, to, b / (a + b));
        for (i = 0; i < 3; i++) {
            sceVu0SubVector(v0, cross, tri[i]);
            sceVu0SubVector(v1, tri[(i + 1) % 3], tri[i]);
            sceVu0OuterProduct(v, v1, v0);
            a = sceVu0InnerProduct(nor, v);
            if (a < 0.0f) {
                break;
            }
        }
        if (i == 3) {
            hit = 1;
        }
    }
    return hit;
}

void ktactReserveTumble(signed int pid, float ang, Tumble_Type tt) {
    Act* act = &vspRider[pid]->ctrl.act;
    act->reserve_tumble = 1;
    act->reserve_tumble_ang = ang;
    act->reserve_tumble_speed = -1.0f;
    act->reserve_tumble_type = tt;
}

void ktactReserveTumble2(signed int unused1, float* unused2, float unused3, signed int unused4) {
}

// ktact.c
static void ktactProcReserveTumble(Plane* pl, Ctrl* rc) {
    // Size: 0x2580, DWARF: 0x76810
    Act* act; // r16
    Tumble_Way tw; // r17
    sceVu0FVECTOR nor; // 0x30(r29)
    sceVu0FVECTOR sp; // 0x40(r29)
    float spang; // 0x54(r29)
    float preang; // 0x58(r29)
    float refang; // 0x5C(r29)
    float ang; // 0x60(r29)
    float ang_foward; // 0x64(r29)
    float ang_backward; // 0x68(r29)

    act = &rc->act;
    if (act->reserve_tumble) {
        ang_foward = 1.570796f - vktactMatTumbleAng_normal[2];
        ang_backward = 3.141592f - ang_foward;
        *(__int128*)sp = *(__int128*)rc->speed;
        sp[1] = 0.0f;
        preang = atan2f(-sp[0], -sp[2]);
        refang = act->reserve_tumble_ang;
        ang = refang - preang;
        ang = ang < -3.141592f
                  ? 6.283184f + ang
              : (ang > 3.141592f)
                  ? ang - 6.283184f
                  : ang;
        spang = preang + (0.5f * ang);
        spang = spang < -3.141592f
                    ? 6.283184f + spang
                : (spang > 3.141592f)
                    ? spang - 6.283184f
                    : spang;
        ang = ang > 0.0f ? 1.570796f : -1.570796f;
        spang += ang;
        spang = spang < -3.141592f
                    ? 6.283184f + spang
                : (spang > 3.141592f)
                    ? spang - 6.283184f
                    : spang;
        nor[0] = -sinf(spang);
        nor[1] = 0.0f;
        nor[2] = -cosf(spang);
        sceVu0Normalize(nor, nor);
        *(__int128*)pl->normal = *(__int128*)nor;
        *(__int128*)pl->cross = *(__int128*)rc->nowpos.pos;
        pl->available = 1;
        ang = refang - preang;
        ang = ang < -3.141592f
                  ? 6.283184f + ang
              : (ang > 3.141592f)
                  ? ang - 6.283184f
                  : ang;
        if (ang < 0.0f) {
            tw = etwLeft;
            ang = -ang;
        } else {
            tw = etwRight;
        }
        if (ang < ang_foward) {
            tw = etwFoward;
        } else if (!(ang <= ang_backward)) {
            tw = etwBack;
        }
        act->trg_tumble_way = tw;
        act->trg_tumble_type = act->reserve_tumble_type;
    }
}

static signed int ktactGetChangedTrickNo(Ctrl* rc, signed int tno) {
    Act* act = &rc->act;
    signed int cnt;

    if (act->hp_air) {
        cnt = 0;
        switch (tno) {
            case 0x2E:
            case 0x2D:
            case 0x25:
                cnt++;
            case 0x26:
            case 0x24:
            case 0x22:
                cnt++;
            case 0x1B:
            case 0x20:
            case 0x1A:
                if (!act->fakie || cnt == 0) {
                    tno = cnt + 0x88;
                } else {
                    tno = cnt + 0x8B;
                }
                break;
            case 0x23:
                tno = 0x86;
                break;
            case 0x19:
                break;
        }
    } else if (act->pre_hp_air) {
        if (tno >= 0x31 && tno < 0x3E) {
        }
    }
    if (tno >= 0x54 && tno < 0x6C) {
        switch (tno) {
            case 0x5F:
                if (act->hp_air && act->fakie) {
                    tno = 0x77;
                }
                break;
            case 0x6A:
                if (act->hp_air && act->fakie) {
                    tno = 0x82;
                }
                break;
        }
    }
    return tno;
}

const char* padding[] = {
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100", "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111", "112", "113", "114", "115", "116", "117", "118", "119", "120", "121", "122", "123", "124", "125", "126", "127", "128", "129", "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "140", "141", "142", "143", "144", "145", "146", "147", "148", "149", "150", "151", "152", "153", "154", "155", "156", "157", "158", "159", "160", "161", "162", "163", "164", "165", "166", "167", "168", "169", "170", "171", "172", "173", "174", "175", "176", "177", "178", "179", "180", "181", "182", "183", "184", "185", "186", "187", "188", "189", "190", "191", "192", "193", "194", "195", "196", "197", "198", "199", "200", "201", "202", "203", "204", "205", "206", "207", "208", "209", "210", "211", "212", "213", "214", "215", "216", "217", "218", "219", "220", "221", "222", "223", "224", "225", "226", "227", "228", "229", "230", "231", "232", "233", "234", "235", "236", "237", "238", "239", "240", "241", "242", "243", "244", "245", "246", "247", "248", "249", "250", "251", "252", "253", "254", "255", "256", "257", "258", "259", "260", "261", "262", "263", "264", "265", "266", "267", "268", "269", "270", "271", "272", "273", "274", "275", "276", "277", "278", "279", "280", "281", "282", "283", "284", "285", "286", "287", "288", "289", "290", "291", "292", "293", "294", "295", "296", "297", "298", "299", "300", "301", "302", "303", "304", "305", "306", "307", "308", "309", "310", "311", "312", "313", "314", "315", "316", "317", "318", "319", "320", "321", "322", "323", "324", "325", "326", "327", "328", "329", "330", "331", "332", "333", "334", "335", "336", "337", "338", "339", "340", "341", "342", "343", "344", "345", "346", "347", "348", "349", "350", "351", "352", "353", "354", "355", "356", "357", "358", "359", "360", "361", "362", "363", "364", "365", "366", "367", "368", "369", "370", "371", "372", "373", "374", "375", "376", "377", "378", "379", "380", "381", "382", "383", "384", "385", "386", "387", "388", "389", "390", "391", "392", "393", "394", "395", "396", "397", "398", "399", "400", "401", "402", "403", "404", "405", "406", "407", "408", "409", "410", "411", "412", "413", "414", "415", "416", "417", "418", "419", "420", "421", "422", "423", "424", "425", "426", "427", "428", "429", "430", "431", "432", "433", "434", "435", "436", "437", "438", "439", "440", "441", "442", "443", "444", "445", "446", "447", "448", "449", "450", "451", "452", "453", "454", "455", "456", "457", "458", "459", "460", "461", "462", "463", "464", "465", "466", "467", "468", "469", "470", "471", "472", "473", "474", "475", "476", "477", "478", "479", "480", "481", "482", "483", "484", "485", "486", "487", "488", "489", "490", "491", "492", "493", "494", "495", "496", "497", "498", "499", "500", "501", "502", "503", "504", "505", "506", "507", "508", "509", "510", "511", "512", "513", "514", "515", "516", "517", "518", "519", "520", "521", "522", "523", "524", "525", "526", "527", "528", "529", "530", "531", "532", "533", "534", "535", "536", "537", "538", "539", "540", "541", "542", "543", "544", "545", "546", "547", "548", "549", "550", "551", "552", "553", "554", "555", "556", "557", "558", "559", "560", "561", "562", "563", "564", "565", "566", "567", "568", "569", "570", "571", "572", "573", "574", "575", "576", "577", "578", "579", "580", "581", "582", "583", "584", "585", "586", "587", "588", "589", "590", "591", "592", "593", "594", "595", "596", "597", "598", "599", "600", "601", "602", "603", "604", "605", "606", "607", "608", "609", "610", "611", "612", "613", "614", "615", "616", "617", "618", "619", "620", "621", "622", "623", "624", "625", "626", "627", "628", "629", "630", "631", "632", "633", "634", "635", "636", "637", "638", "639", "640", "641", "642", "643", "644", "645", "646", "647", "648", "649", "650", "651", "652", "653", "654", "655", "656", "657", "658", "659", "660", "661", "662", "663", "664", "665", "666", "667", "668", "669", "670", "671", "672", "673", "674", "675", "676", "677", "678", "679", "680", "681", "682", "683", "684", "685", "686", "687", "688", "689", "690", "691", "692", "693", "694", "695", "696", "697", "698", "699", "700", "701", "702", "703", "704", "705", "706", "707", "708", "709", "710", "711", "712", "713", "714", "715", "716", "717", "718", "719", "720", "721", "722", "723", "724", "725", "726", "727", "728", "729", "730", "731", "732", "733", "734", "735", "736", "737", "738", "739", "740", "741", "742", "743", "744", "745", "746", "747", "748", "749", "750", "751", "752", "753", "754", "755", "756", "757", "758", "759", "760", "761", "762", "763", "764", "765", "766", "767", "768", "769", "770", "771", "772", "773", "774", "775", "776", "777", "778", "779", "780", "781", "782", "783", "784", "785", "786", "787", "788", "789", "790", "791", "792", "793", "794", "795", "796", "797", "798", "799", "800", "801", "802", "803", "804", "805", "806", "807", "808", "809", "810", "811", "812", "813", "814", "815", "816", "817", "818", "819", "820", "821", "822", "823", "824", "825", "826", "827", "828", "829", "830", "831", "832", "833", "834", "835", "836", "837", "838", "839", "840", "841", "842", "843", "844", "845", "846", "847", "848", "849", "850", "851", "852", "853", "854", "855", "856", "857", "858", "859", "860", "861", "862", "863", "864", "865", "866", "867", "868", "869", "870", "871", "872", "873", "874", "875", "876", "877", "878", "879", "880", "881", "882", "883", "884", "885", "886", "887", "888", "889", "890", "891", "892", "893", "894", "895", "896", "897", "898", "899", "900", "901", "902", "903", "904", "905", "906", "907", "908", "909", "910", "911", "912", "913", "914", "915", "916", "917", "918", "919", "920", "921", "922", "923", "924", "925", "926", "927", "928", "929", "930", "931", "932", "933", "934", "935", "936", "937", "938", "939", "940", "941", "942", "943", "944", "945", "946", "947", "948", "949", "950", "951", "952", "953", "954", "955", "956", "957", "958", "959", "960", "961", "962", "963", "964", "965", "966", "967", "968", "969", "970", "971", "972", "973", "974", "975", "976", "977", "978", "979", "980", "981", "982", "983", "984", "985", "986", "987", "988", "989", "990", "991", "992", "993", "994", "995", "996", "997", "998", "999", "1000", "1001", "1002", "1003", "1004", "1005", "1006", "1007", "1008", "1009", "1010", "1011", "1012", "1013", "1014", "1015", "1016", "1017", "1018", "1019", "1020", "1021", "1022", "1023", "1024", "1025", "1026", "1027", "1028", "1029", "1030", "1031", "1032", "1033", "1034", "1035", "1036", "1037", "1038", "1039", "1040", "1041", "1042", "1043", "1044", "1045", "1046", "1047", "1048", "1049", "1050", "1051", "1052", "1053", "1054", "1055", "1056", "1057", "1058", "1059", "1060", "1061", "1062", "1063", "1064", "1065", "1066", "1067", "1068", "1069", "1070", "1071", "1072", "1073", "1074", "1075", "1076", "1077", "1078", "1079", "1080", "1081", "1082", "1083", "1084", "1085", "1086", "1087", "1088", "1089", "1090", "1091", "1092", "1093", "1094", "1095", "1096", "1097", "1098", "1099", "1100", "1101", "1102", "1103", "1104", "1105", "1106", "1107", "1108", "1109", "1110", "1111", "1112", "1113", "1114", "1115", "1116", "1117", "1118", "1119", "1120", "1121", "1122", "1123", "1124", "1125", "1126", "1127", "1128", "1129", "1130", "1131", "1132", "1133", "1134", "1135", "1136", "1137", "1138", "1139", "1140", "1141", "1142", "1143", "1144", "1145", "1146", "1147", "1148", "1149", "1150", "1151", "1152", "1153", "1154", "1155", "1156", "1157", "1158", "1159", "1160", "1161", "1162", "1163", "1164", "1165", "1166", "1167", "1168", "1169", "1170", "1171", "1172", "1173", "1174", "1175", "1176", "1177", "1178", "1179", "1180", "1181", "1182", "1183", "1184", "1185", "1186", "1187", "1188", "1189", "1190", "1191", "1192", "1193", "1194", "1195", "1196", "1197", "1198", "1199", "1200", "1201", "1202", "1203", "1204", "1205", "1206", "1207", "1208", "1209", "1210", "1211", "1212", "1213", "1214", "1215", "1216", "1217", "1218", "1219", "1220", "1221", "1222", "1223", "1224", "1225", "1226", "1227", "1228", "1229", "1230", "1231", "1232", "1233", "1234", "1235", "1236", "1237", "1238", "1239", "1240", "1241", "1242", "1243", "1244", "1245", "1246", "1247", "1248", "1249", "1250", "1251", "1252", "1253", "1254", "1255", "1256", "1257", "1258", "1259", "1260", "1261", "1262", "1263", "1264", "1265", "1266", "1267", "1268", "1269", "1270", "1271", "1272", "1273", "1274", "1275", "1276", "1277", "1278", "1279", "1280", "1281", "1282", "1283", "1284", "1285", "1286", "1287", "1288", "1289", "1290", "1291", "1292", "1293", "1294", "1295", "1296", "1297", "1298", "1299", "1300", "1301", "1302", "1303", "1304", "1305", "1306", "1307", "1308", "1309", "1310", "1311", "1312", "1313", "1314", "1315", "1316", "1317", "1318", "1319", "1320", "1321", "1322", "1323", "1324", "1325", "1326", "1327", "1328", "1329", "1330", "1331", "1332", "1333", "1334", "1335", "1336", "1337", "1338", "1339", "1340", "1341", "1342", "1343", "1344", "1345", "1346", "1347", "1348", "1349", "1350", "1351", "1352", "1353", "1354", "1355", "1356", "1357", "1358", "1359", "1360", "1361", "1362", "1363", "1364", "1365", "1366", "1367", "1368", "1369", "1370", "1371", "1372", "1373", "1374", "1375", "1376", "1377", "1378", "1379", "1380", "1381", "1382", "1383", "1384", "1385", "1386", "1387", "1388", "1389", "1390", "1391", "1392", "1393", "1394", "1395", "1396", "1397", "1398", "1399", "1400", "1401", "1402", "1403", "1404", "1405", "1406", "1407", "1408", "1409", "1410", "1411", "1412", "1413", "1414", "1415", "1416", "1417", "1418", "1419", "1420", "1421", "1422", "1423", "1424", "1425", "1426", "1427", "1428", "1429", "1430", "1431", "1432", "1433", "1434", "1435", "1436", "1437", "1438", "1439", "1440", "1441", "1442", "1443", "1444", "1445", "1446", "1447", "1448", "1449", "1450", "1451", "1452", "1453", "1454", "1455", "1456", "1457", "1458", "1459", "1460", "1461", "1462", "1463", "1464", "1465", "1466", "1467", "1468", "1469", "1470", "1471", "1472", "1473", "1474", "1475", "1476", "1477", "1478", "1479", "1480", "1481", "1482", "1483", "1484", "1485", "1486", "1487", "1488", "1489", "1490", "1491", "1492", "1493", "1494", "1495", "1496", "1497", "1498", "1499", "1500", "1501", "1502", "1503", "1504", "1505", "1506", "1507", "1508", "1509", "1510", "1511", "1512", "1513", "1514", "1515", "1516", "1517", "1518", "1519", "1520", "1521", "1522", "1523", "1524", "1525", "1526", "1527", "1528", "1529", "1530", "1531", "1532", "1533", "1534", "1535", "1536", "1537", "1538", "1539", "1540", "1541", "1542", "1543", "1544", "1545", "1546", "1547", "1548", "1549", "1550", "1551", "1552", "1553", "1554", "1555", "1556", "1557", "1558", "1559", "1560", "1561", "1562", "1563", "1564", "1565", "1566", "1567", "1568", "1569", "1570", "1571", "1572", "1573", "1574", "1575", "1576", "1577", "1578", "1579", "1580", "1581", "1582", "1583", "1584", "1585", "1586", "1587", "1588", "1589", "1590", "1591", "1592", "1593", "1594", "1595", "1596", "1597", "1598", "1599", "1600", "1601", "1602", "1603", "1604", "1605", "1606", "1607", "1608", "1609", "1610", "1611", "1612", "1613", "1614", "1615", "1616", "1617", "1618", "1619", "1620", "1621", "1622", "1623", "1624", "1625", "1626", "1627", "1628", "1629", "1630", "1631", "1632", "1633", "1634", "1635", "1636", "1637", "1638", "1639", "1640", "1641", "1642", "1643", "1644", "1645", "1646", "1647", "1648", "1649", "1650", "1651", "1652", "1653", "1654", "1655", "1656", "1657", "1658", "1659", "1660", "1661", "1662", "1663", "1664", "1665", "1666", "1667", "1668", "1669", "1670", "1671", "1672", "1673", "1674", "1675", "1676", "1677", "1678", "1679", "1680", "1681", "1682", "1683", "1684", "1685", "1686", "1687", "1688", "1689", "1690", "1691", "1692", "1693", "1694", "1695", "1696", "1697", "1698", "1699", "1700", "1701", "1702", "1703", "1704", "1705", "1706", "1707", "1708", "1709", "1710", "1711", "1712", "1713", "1714", "1715", "1716", "1717", "1718", "1719", "1720", "1721", "1722", "1723", "1724", "1725", "1726", "1727", "1728", "1729", "1730", "1731", "1732", "1733", "1734", "1735", "1736", "1737", "1738", "1739", "1740", "1741", "1742", "1743", "1744", "1745", "1746", "1747", "1748", "1749", "1750", "1751", "1752", "1753", "1754", "1755", "1756", "1757", "1758", "1759", "1760", "1761", "1762", "1763", "1764", "1765", "1766", "1767", "1768", "1769", "1770", "1771", "1772", "1773", "1774", "1775", "1776", "1777", "1778", "1779", "1780", "1781", "1782", "1783", "1784", "1785", "1786", "1787", "1788", "1789", "1790", "1791", "1792", "1793", "1794", "1795", "1796", "1797", "1798", "1799", "1800", "1801", "1802", "1803", "1804", "1805", "1806", "1807", "1808", "1809", "1810", "1811", "1812", "1813", "1814", "1815", "1816", "1817", "1818", "1819", "1820", "1821", "1822", "1823", "1824", "1825", "1826", "1827", "1828", "1829", "1830", "1831", "1832", "1833", "1834", "1835", "1836", "1837", "1838", "1839", "1840", "1841", "1842", "1843", "1844", "1845", "1846", "1847", "1848", "1849", "1850", "1851", "1852", "1853", "1854", "1855", "1856", "1857", "1858", "1859", "1860", "1861", "1862", "1863", "1864", "1865", "1866", "1867", "1868", "1869", "1870", "1871", "1872", "1873", "1874", "1875", "1876", "1877", "1878", "1879", "1880", "1881", "1882", "1883", "1884", "1885", "1886", "1887", "1888", "1889", "1890", "1891", "1892", "1893", "1894", "1895", "1896", "1897", "1898", "1899", "1900", "1901", "1902", "1903", "1904", "1905", "1906", "1907", "1908", "1909", "1910", "1911", "1912", "1913", "1914", "1915", "1916", "1917", "1918", "1919", "1920", "1921", "1922", "1923", "1924", "1925", "1926", "1927", "1928", "1929", "1930", "1931", "1932", "1933", "1934", "1935", "1936", "1937", "1938", "1939", "1940", "1941", "1942", "1943", "1944", "1945", "1946", "1947", "1948", "1949", "1950", "1951", "1952", "1953", "1954", "1955", "1956", "1957", "1958", "1959", "1960", "1961", "1962", "1963", "1964", "1965", "1966", "1967", "1968", "1969", "1970", "1971", "1972", "1973", "1974", "1975", "1976", "1977", "1978", "1979", "1980", "1981", "1982", "1983", "1984", "1985", "1986", "1987", "1988", "1989", "1990", "1991", "1992", "1993", "1994", "1995", "1996", "1997", "1998", "1999", "2000", "2001", "2002", "2003", "2004", "2005", "2006", "2007", "2008", "2009", "2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019", "2020", "2021", "2022", "2023", "2024", "2025", "2026", "2027", "2028", "2029", "2030", "2031", "2032", "2033", "2034", "2035", "2036", "2037", "2038", "2039", "2040", "2041", "2042", "2043", "2044", "2045", "2046", "2047", "2048", "2049", "2050", "2051", "2052", "2053", "2054", "2055", "2056", "2057", "2058", "2059", "2060", "2061", "2062", "2063", "2064", "2065", "2066", "2067", "2068", "2069", "2070", "2071", "2072", "2073", "2074", "2075", "2076", "2077", "2078", "2079", "2080", "2081", "2082", "2083", "2084", "2085", "2086", "2087", "2088", "2089", "2090", "2091", "2092", "2093", "2094", "2095", "2096", "2097", "2098", "2099", "2100", "2101", "2102", "2103", "2104", "2105", "2106", "2107", "2108", "2109", "2110", "2111", "2112", "2113", "2114", "2115", "2116", "2117", "2118", "2119", "2120", "2121", "2122", "2123", "2124", "2125", "2126", "2127", "2128", "2129", "2130", "2131", "2132", "2133", "2134", "2135", "2136", "2137", "2138", "2139", "2140", "2141", "2142", "2143", "2144", "2145", "2146", "2147", "2148", "2149", "2150", "2151", "2152", "2153", "2154", "2155", "2156", "2157", "2158", "2159", "2160", "2161", "2162", "2163", "2164", "2165", "2166", "2167", "2168", "2169", "2170", "2171", "2172", "2173", "2174", "2175", "2176", "2177", "2178", "2179", "2180", "2181", "2182", "2183", "2184", "2185", "2186", "2187", "2188", "2189", "2190", "2191", "2192", "2193", "2194", "2195", "2196", "2197", "2198", "2199", "2200", "2201", "2202", "2203", "2204", "2205", "2206", "2207", "2208", "2209", "2210", "2211", "2212", "2213", "2214", "2215", "2216", "2217", "2218", "2219", "2220", "2221", "2222", "2223", "2224", "2225", "2226", "2227", "2228", "2229", "2230", "2231", "2232", "2233", "2234", "2235", "2236", "2237", "2238", "2239", "2240", "2241", "2242", "2243", "2244", "2245", "2246", "2247", "2248", "2249", "2250", "2251", "2252", "2253", "2254", "2255", "2256", "2257", "2258", "2259", "2260", "2261", "2262", "2263", "2264", "2265", "2266", "2267", "2268", "2269", "2270", "2271", "2272", "2273", "2274", "2275", "2276", "2277", "2278", "2279", "2280", "2281", "2282", "2283", "2284", "2285", "2286", "2287", "2288", "2289", "2290", "2291", "2292", "2293", "2294", "2295", "2296", "2297", "2298", "2299", "2300", "2301", "2302", "2303", "2304", "2305", "2306", "2307", "2308", "2309", "2310", "2311", "2312", "2313", "2314", "2315", "2316", "2317", "2318", "2319", "2320", "2321", "2322", "2323", "2324", "2325", "2326", "2327", "2328", "2329", "2330", "2331", "2332", "2333", "2334", "2335", "2336", "2337", "2338", "2339", "2340", "2341", "2342", "2343", "2344", "2345", "2346", "2347", "2348", "2349", "2350", "2351", "2352", "2353", "2354", "2355", "2356", "2357", "2358", "2359", "2360", "2361", "2362", "2363", "2364", "2365", "2366", "2367", "2368", "2369", "2370", "2371", "2372", "2373", "2374", "2375", "2376", "2377", "2378", "2379", "2380", "2381", "2382", "2383", "2384", "2385", "2386", "2387", "2388", "2389", "2390", "2391", "2392", "2393", "2394", "2395", "2396", "2397", "2398", "2399", "2400", "2401", "2402", "2403", "2404", "2405", "2406", "2407", "2408", "2409", "2410", "2411", "2412", "2413", "2414", "2415", "2416", "2417", "2418", "2419", "2420", "2421", "2422", "2423", "2424", "2425", "2426", "2427", "2428", "2429", "2430", "2431", "2432", "2433", "2434", "2435", "2436", "2437", "2438", "2439", "2440", "2441", "2442", "2443", "2444", "2445", "2446", "2447", "2448", "2449", "2450", "2451", "2452", "2453", "2454", "2455", "2456", "2457", "2458", "2459", "2460", "2461", "2462", "2463", "2464", "2465", "2466", "2467", "2468", "2469", "2470", "2471", "2472", "2473", "2474", "2475", "2476", "2477", "2478", "2479", "2480", "2481", "2482", "2483", "2484", "2485", "2486", "2487", "2488", "2489", "2490", "2491", "2492", "2493", "2494", "2495", "2496", "2497", "2498", "2499", "2500", "2501", "2502", "2503", "2504", "2505", "2506", "2507", "2508", "2509", "2510", "2511", "2512", "2513", "2514", "2515", "2516", "2517", "2518", "2519", "2520", "2521", "2522", "2523", "2524", "2525", "2526", "2527", "2528", "2529", "2530", "2531", "2532", "2533", "2534", "2535", "2536", "2537", "2538", "2539", "2540", "2541", "2542", "2543", "2544", "2545", "2546", "2547", "2548", "2549", "2550", "2551", "2552", "2553", "2554", "2555", "2556", "2557", "2558", "2559", "2560", "2561", "2562", "2563", "2564", "2565", "2566", "2567", "2568", "2569", "2570", "2571", "2572", "2573", "2574", "2575", "2576", "2577", "2578", "2579", "2580", "2581", "2582", "2583", "2584", "2585", "2586", "2587", "2588", "2589", "2590", "2591", "2592", "2593", "2594", "2595", "2596", "2597", "2598", "2599", "2600", "2601", "2602", "2603", "2604", "2605", "2606", "2607", "2608", "2609", "2610", "2611", "2612", "2613", "2614", "2615", "2616", "2617", "2618", "2619", "2620", "2621", "2622", "2623", "2624", "2625", "2626", "2627", "2628", "2629", "2630", "2631", "2632", "2633", "2634", "2635", "2636", "2637", "2638", "2639", "2640", "2641", "2642", "2643", "2644", "2645", "2646", "2647", "2648", "2649", "2650", "2651", "2652", "2653", "2654", "2655", "2656", "2657", "2658", "2659", "2660", "2661", "2662", "2663", "2664", "2665", "2666", "2667", "2668", "2669", "2670", "2671", "2672", "2673", "2674", "2675", "2676", "2677", "2678", "2679", "2680", "2681", "2682", "2683", "2684", "2685", "2686", "2687", "2688", "2689", "2690", "2691", "2692", "2693", "2694", "2695", "2696", "2697", "2698", "2699", "2700", "2701", "2702", "2703", "2704", "2705", "2706", "2707", "2708", "2709", "2710", "2711", "2712", "2713", "2714", "2715", "2716", "2717", "2718", "2719", "2720", "2721", "2722", "2723", "2724", "2725", "2726", "2727", "2728", "2729", "2730", "2731", "2732", "2733", "2734", "2735", "2736", "2737", "2738", "2739", "2740", "2741", "2742", "2743", "2744", "2745", "2746", "2747", "2748", "2749", "2750", "2751", "2752", "2753", "2754", "2755", "2756", "2757", "2758", "2759", "2760", "2761", "2762", "2763", "2764", "2765", "2766", "2767", "2768", "2769", "2770", "2771", "2772", "2773", "2774", "2775", "2776", "2777", "2778", "2779", "2780", "2781", "2782", "2783", "2784", "2785", "2786", "2787", "2788", "2789", "2790", "2791", "2792", "2793", "2794", "2795", "2796", "2797", "2798", "2799", "2800", "2801", "2802", "2803", "2804", "2805", "2806", "2807", "2808", "2809", "2810", "2811", "2812", "2813", "2814", "2815", "2816", "2817", "2818", "2819", "2820", "2821", "2822", "2823", "2824", "2825", "2826", "2827", "2828", "2829", "2830", "2831", "2832", "2833", "2834", "2835", "2836", "2837", "2838", "2839", "2840", "2841", "2842", "2843", "2844", "2845", "2846", "2847", "2848", "2849", "2850", "2851", "2852", "2853", "2854", "2855", "2856", "2857", "2858", "2859", "2860", "2861", "2862", "2863", "2864", "2865", "2866", "2867", "2868", "2869", "2870", "2871", "2872", "2873", "2874", "2875", "2876", "2877", "2878", "2879", "2880", "2881", "2882", "2883", "2884", "2885", "2886", "2887", "2888", "2889", "2890", "2891", "2892", "2893", "2894", "2895", "2896", "2897", "2898", "2899", "2900", "2901", "2902", "2903", "2904", "2905", "2906", "2907", "2908", "2909", "2910", "2911", "2912", "2913", "2914", "2915", "2916", "2917", "2918", "2919", "2920", "2921", "2922", "2923", "2924", "2925", "2926", "2927", "2928", "2929", "2930", "2931", "2932", "2933", "2934", "2935", "2936", "2937", "2938", "2939", "2940", "2941", "2942", "2943", "2944", "2945", "2946", "2947", "2948", "2949", "2950", "2951", "2952", "2953", "2954", "2955", "2956", "2957", "2958", "2959", "2960", "2961", "2962", "2963", "2964", "2965", "2966", "2967", "2968", "2969", "2970", "2971", "2972", "2973", "2974", "2975", "2976", "2977", "2978", "2979", "2980", "2981", "2982", "2983", "2984", "2985", "2986", "2987", "2988", "2989", "2990", "2991", "2992", "2993", "2994", "2995", "2996", "2997", "2998", "2999", "3000", "3001", "3002", "3003", "3004", "3005", "3006", "3007", "3008", "3009", "3010", "3011", "3012", "3013", "3014", "3015", "3016", "3017", "3018", "3019", "3020", "3021", "3022", "3023", "3024", "3025", "3026", "3027", "3028", "3029", "3030", "3031", "3032", "3033", "3034", "3035", "3036", "3037", "3038", "3039", "3040", "3041", "3042", "3043", "3044", "3045", "3046", "3047", "3048", "3049", "3050", "3051", "3052", "3053", "3054", "3055", "3056", "3057", "3058", "3059", "3060", "3061", "3062", "3063", "3064", "3065", "3066", "3067", "3068", "3069", "3070", "3071", "3072", "3073", "3074", "3075", "3076", "3077", "3078", "3079", "3080", "3081", "3082", "3083", "3084", "3085", "3086", "3087", "3088", "3089", "3090", "3091", "3092", "3093", "3094", "3095", "3096", "3097", "3098", "3099", "3100", "3101", "3102", "3103", "3104", "3105", "3106", "3107", "3108", "3109", "3110", "3111", "3112", "3113", "3114", "3115", "3116", "3117", "3118", "3119", "3120", "3121", "3122", "3123", "3124", "3125", "3126", "3127", "3128", "3129", "3130", "3131", "3132", "3133", "3134", "3135", "3136", "3137", "3138", "3139", "3140", "3141", "3142", "3143", "3144", "3145", "3146", "3147", "3148", "3149", "3150", "3151", "3152", "3153", "3154", "3155", "3156", "3157", "3158", "3159", "3160", "3161", "3162", "3163", "3164", "3165", "3166", "3167", "3168", "3169", "3170", "3171", "3172", "3173", "3174", "3175", "3176", "3177", "3178", "3179", "3180", "3181", "3182", "3183", "3184", "3185", "3186", "3187", "3188", "3189", "3190", "3191", "3192", "3193", "3194", "3195", "3196", "3197", "3198", "3199", "3200", "3201", "3202", "3203", "3204", "3205", "3206", "3207", "3208", "3209", "3210", "3211", "3212", "3213", "3214", "3215", "3216", "3217", "3218", "3219", "3220", "3221", "3222", "3223", "3224", "3225", "3226", "3227", "3228", "3229", "3230", "3231", "3232", "3233", "3234", "3235", "3236", "3237", "3238", "3239", "3240", "3241", "3242", "3243", "3244", "3245", "3246", "3247", "3248", "3249", "3250", "3251", "3252", "3253", "3254", "3255", "3256", "3257", "3258", "3259", "3260", "3261", "3262", "3263", "3264", "3265", "3266", "3267", "3268", "3269", "3270", "3271", "3272", "3273", "3274", "3275", "3276", "3277", "3278", "3279", "3280", "3281", "3282", "3283", "3284", "3285", "3286", "3287", "3288", "3289", "3290", "3291", "3292", "3293", "3294", "3295", "3296", "3297", "3298", "3299", "3300", "3301", "3302", "3303", "3304", "3305", "3306", "3307", "3308", "3309", "3310", "3311", "3312", "3313", "3314", "3315", "3316", "3317", "3318", "3319", "3320", "3321", "3322", "3323", "3324", "3325", "3326", "3327", "3328", "3329", "3330", "3331", "3332", "3333", "3334", "3335", "3336", "3337", "3338", "3339", "3340", "3341", "3342", "3343", "3344", "3345", "3346", "3347", "3348", "3349", "3350", "3351", "3352", "3353", "3354", "3355", "3356", "3357", "3358", "3359", "3360", "3361", "3362", "3363", "3364", "3365", "3366", "3367", "3368", "3369", "3370", "3371", "3372", "3373", "3374", "3375", "3376", "3377", "3378", "3379", "3380", "3381", "3382", "3383", "3384", "3385", "3386", "3387", "3388", "3389", "3390", "3391", "3392", "3393", "3394", "3395", "3396", "3397", "3398", "3399", "3400", "3401", "3402", "3403", "3404", "3405", "3406", "3407", "3408", "3409", "3410", "3411", "3412", "3413", "3414", "3415", "3416", "3417", "3418", "3419", "3420", "3421", "3422", "3423", "3424", "3425", "3426", "3427", "3428", "3429", "3430", "3431", "3432", "3433", "3434", "3435", "3436", "3437", "3438", "3439", "3440", "3441", "3442", "3443", "3444", "3445", "3446", "3447", "3448", "3449", "3450", "3451", "3452", "3453", "3454", "3455", "3456", "3457", "3458", "3459", "3460", "3461", "3462", "3463", "3464", "3465", "3466", "3467", "3468", "3469", "3470", "3471", "3472", "3473", "3474", "3475", "3476", "3477", "3478", "3479", "3480", "3481", "3482", "3483", "3484", "3485", "3486", "3487", "3488", "3489", "3490", "3491", "3492", "3493", "3494", "3495", "3496", "3497", "3498", "3499", "3500", "3501", "3502", "3503", "3504", "3505", "3506", "3507", "3508", "3509", "3510", "3511", "3512", "3513", "3514", "3515", "3516", "3517", "3518", "3519", "3520", "3521", "3522", "3523", "3524", "3525", "3526", "3527", "3528", "3529", "3530", "3531", "3532", "3533", "3534", "3535", "3536", "3537", "3538", "3539", "3540", "3541", "3542", "3543", "3544", "3545", "3546", "3547", "3548", "3549", "3550", "3551", "3552", "3553", "3554", "3555", "3556", "3557", "3558", "3559", "3560", "3561", "3562", "3563", "3564", "3565", "3566", "3567", "3568", "3569", "3570", "3571", "3572", "3573", "3574", "3575", "3576", "3577", "3578", "3579", "3580", "3581", "3582", "3583", "3584", "3585", "3586", "3587", "3588", "3589", "3590", "3591", "3592", "3593", "3594", "3595", "3596", "3597", "3598", "3599", "3600", "3601", "3602", "3603", "3604", "3605", "3606", "3607", "3608", "3609", "3610", "3611", "3612", "3613", "3614", "3615", "3616", "3617", "3618", "3619", "3620", "3621", "3622", "3623", "3624", "3625", "3626", "3627", "3628", "3629", "3630", "3631", "3632", "3633", "3634", "3635", "3636", "3637", "3638", "3639", "3640", "3641", "3642", "3643", "3644", "3645", "3646", "3647", "3648", "3649", "3650", "3651", "3652", "3653", "3654", "3655", "3656", "3657", "3658", "3659", "3660", "3661", "3662", "3663", "3664", "3665", "3666", "3667", "3668", "3669", "3670", "3671", "3672", "3673", "3674", "3675", "3676", "3677", "3678", "3679", "3680", "3681", "3682", "3683", "3684", "3685", "3686", "3687", "3688", "3689", "3690", "3691", "3692", "3693", "3694", "3695", "3696", "3697", "3698", "3699", "3700", "3701", "3702", "3703", "3704", "3705", "3706", "3707", "3708", "3709", "3710", "3711", "3712", "3713", "3714", "3715", "3716", "3717", "3718", "3719", "3720", "3721", "3722", "3723", "3724", "3725", "3726", "3727", "3728", "3729", "3730", "3731", "3732", "3733", "3734", "3735", "3736", "3737", "3738", "3739", "3740", "3741", "3742", "3743", "3744", "3745", "3746", "3747", "3748", "3749", "3750", "3751", "3752", "3753", "3754", "3755", "3756", "3757", "3758", "3759", "3760", "3761", "3762", "3763", "3764", "3765", "3766", "3767", "3768", "3769", "3770", "3771", "3772", "3773", "3774", "3775", "3776", "3777", "3778", "3779", "3780", "3781", "3782", "3783", "3784", "3785", "3786", "3787", "3788", "3789", "3790", "3791", "3792", "3793", "3794", "3795", "3796", "3797", "3798", "3799", "3800", "3801", "3802", "3803", "3804", "3805", "3806", "3807", "3808", "3809", "3810", "3811", "3812", "3813", "3814", "3815", "3816", "3817", "3818", "3819", "3820", "3821", "3822", "3823", "3824", "3825", "3826", "3827", "3828", "3829", "3830", "3831", "3832", "3833", "3834", "3835", "3836", "3837", "3838", "3839", "3840", "3841", "3842", "3843", "3844", "3845", "3846", "3847", "3848", "3849", "3850", "3851", "3852", "3853", "3854", "3855", "3856", "3857", "3858", "3859", "3860", "3861", "3862", "3863", "3864", "3865", "3866", "3867", "3868", "3869", "3870", "3871", "3872", "3873", "3874", "3875", "3876", "3877", "3878", "3879", "3880", "3881", "3882", "3883", "3884", "3885", "3886", "3887", "3888", "3889", "3890", "3891", "3892", "3893", "3894", "3895", "3896", "3897", "3898", "3899", "3900", "3901", "3902", "3903", "3904", "3905", "3906", "3907", "3908", "3909", "3910", "3911", "3912", "3913", "3914", "3915", "3916", "3917", "3918", "3919", "3920", "3921", "3922", "3923", "3924", "3925", "3926", "3927", "3928", "3929", "3930", "3931", "3932", "3933", "3934", "3935", "3936", "3937", "3938", "3939", "3940", "3941", "3942", "3943", "3944", "3945", "3946", "3947", "3948", "3949", "3950", "3951", "3952", "3953", "3954", "3955", "3956", "3957", "3958", "3959", "3960", "3961", "3962", "3963", "3964", "3965", "3966", "3967", "3968", "3969", "3970", "3971", "3972", "3973", "3974", "3975", "3976", "3977", "3978", "3979", "3980", "3981", "3982", "3983", "3984", "3985", "3986", "3987", "3988", "3989", "3990", "3991", "3992", "3993", "3994", "3995", "3996", "3997", "3998", "3999", "4000", "4001", "4002", "4003", "4004", "4005", "4006", "4007", "4008", "4009", "4010", "4011", "4012", "4013", "4014", "4015", "4016", "4017", "4018", "4019", "4020", "4021", "4022", "4023", "4024", "4025", "4026", "4027", "4028", "4029", "4030", "4031", "4032", "4033", "4034", "4035", "4036", "4037", "4038", "4039", "4040", "4041", "4042", "4043", "4044", "4045", "4046", "4047", "4048", "4049", "4050", "4051", "4052", "4053", "4054", "4055", "4056", "4057", "4058", "4059", "4060", "4061", "4062", "4063", "4064", "4065", "4066", "4067", "4068", "4069", "4070", "4071", "4072", "4073", "4074", "4075", "4076", "4077", "4078", "4079", "4080", "4081", "4082", "4083", "4084", "4085", "4086", "4087", "4088", "4089", "4090", "4091", "4092", "4093", "4094", "4095", "4096", "4097", "4098", "4099", "4100", "4101", "4102", "4103", "4104", "4105", "4106", "4107", "4108", "4109", "4110", "4111", "4112", "4113", "4114", "4115", "4116", "4117", "4118", "4119", "4120", "4121", "4122", "4123", "4124", "4125", "4126", "4127", "4128", "4129", "4130", "4131", "4132", "4133", "4134", "4135", "4136", "4137", "4138", "4139", "4140", "4141", "4142", "4143", "4144", "4145", "4146", "4147", "4148", "4149", "4150", "4151", "4152", "4153", "4154", "4155", "4156", "4157", "4158", "4159", "4160", "4161", "4162", "4163", "4164", "4165", "4166", "4167", "4168", "4169", "4170", "4171", "4172", "4173", "4174", "4175", "4176", "4177", "4178", "4179", "4180", "4181", "4182", "4183", "4184", "4185", "4186", "4187", "4188", "4189", "4190", "4191", "4192", "4193", "4194", "4195", "4196", "4197", "4198", "4199", "4200", "4201", "4202", "4203", "4204", "4205", "4206", "4207", "4208", "4209", "4210", "4211", "4212", "4213", "4214", "4215", "4216", "4217", "4218", "4219", "4220", "4221", "4222", "4223", "4224", "4225", "4226", "4227", "4228", "4229", "4230", "4231", "4232", "4233", "4234", "4235", "4236", "4237", "4238", "4239", "4240", "4241", "4242", "4243", "4244", "4245", "4246", "4247", "4248", "4249", "4250", "4251", "4252", "4253", "4254", "4255", "4256", "4257", "4258", "4259", "4260", "4261", "4262", "4263", "4264", "4265", "4266", "4267", "4268", "4269", "4270", "4271", "4272", "4273", "4274", "4275", "4276", "4277", "4278", "4279", "4280", "4281", "4282", "4283", "4284", "4285", "4286", "4287", "4288", "4289", "4290", "4291", "4292", "4293", "4294", "4295", "4296", "4297", "4298", "4299", "4300", "4301", "4302", "4303", "4304", "4305", "4306", "4307", "4308", "4309", "4310", "4311", "4312", "4313", "4314", "4315", "4316", "4317", "4318", "4319", "4320", "4321", "4322", "4323", "4324", "4325", "4326", "4327", "4328", "4329", "4330", "4331", "4332", "4333", "4334", "4335", "4336", "4337", "4338", "4339", "4340", "4341", "4342", "4343", "4344", "4345", "4346", "4347", "4348", "4349", "4350", "4351", "4352", "4353", "4354", "4355", "4356", "4357", "4358", "4359", "4360", "4361", "4362", "4363", "4364", "4365", "4366", "4367", "4368", "4369", "4370", "4371", "4372", "4373", "4374", "4375", "4376", "4377", "4378", "4379", "4380", "4381", "4382", "4383", "4384", "4385", "4386", "4387", "4388", "4389", "4390", "4391", "4392", "4393", "4394", "4395", "4396", "4397", "4398", "4399", "4400", "4401", "4402", "4403", "4404", "4405", "4406", "4407", "4408", "4409", "4410", "4411", "4412", "4413", "4414", "4415", "4416", "4417", "4418", "4419", "4420", "4421", "4422", "4423", "4424", "4425", "4426", "4427", "4428", "4429", "4430", "4431", "4432", "4433", "4434", "4435", "4436", "4437", "4438", "4439", "4440", "4441", "4442", "4443", "4444", "4445", "4446", "4447", "4448", "4449", "4450", "4451", "4452", "4453", "4454", "4455", "4456", "4457", "4458", "4459", "4460", "4461", "4462", "4463", "4464", "4465", "4466", "4467", "4468", "4469", "4470", "4471", "4472", "4473", "4474", "4475", "4476", "4477", "4478", "4479", "4480", "4481", "4482", "4483", "4484", "4485", "4486", "4487", "4488", "4489", "4490", "4491", "4492", "4493", "4494", "4495", "4496", "4497", "4498", "4499", "4500", "4501", "4502", "4503", "4504", "4505", "4506", "4507", "4508", "4509", "4510", "4511", "4512", "4513", "4514", "4515", "4516", "4517", "4518", "4519", "4520", "4521", "4522", "4523", "4524", "4525", "4526", "4527", "4528", "4529", "4530", "4531", "4532", "4533", "4534", "4535", "4536", "4537", "4538", "4539", "4540", "4541", "4542", "4543", "4544", "4545", "4546", "4547", "4548", "4549", "4550", "4551", "4552", "4553", "4554", "4555", "4556", "4557", "4558", "4559", "4560", "4561", "4562", "4563", "4564", "4565", "4566", "4567", "4568", "4569", "4570", "4571", "4572", "4573", "4574", "4575", "4576", "4577", "4578", "4579", "4580", "4581", "4582", "4583", "4584", "4585", "4586", "4587", "4588", "4589", "4590", "4591", "4592", "4593", "4594", "4595", "4596", "4597", "4598", "4599", "4600", "4601", "4602", "4603", "4604", "4605", "4606", "4607", "4608", "4609", "4610", "4611", "4612", "4613", "4614", "4615", "4616", "4617", "4618", "4619", "4620", "4621", "4622", "4623", "4624", "4625", "4626", "4627", "4628", "4629", "4630", "4631", "4632", "4633", "4634", "4635", "4636", "4637", "4638", "4639", "4640", "4641", "4642", "4643", "4644", "4645", "4646", "4647", "4648", "4649", "4650", "4651", "4652", "4653", "4654", "4655", "4656", "4657", "4658", "4659", "4660", "4661", "4662", "4663", "4664", "4665", "4666", "4667", "4668", "4669", "4670", "4671", "4672", "4673", "4674", "4675", "4676", "4677", "4678", "4679", "4680", "4681", "4682", "4683", "4684", "4685", "4686", "4687", "4688", "4689", "4690", "4691", "4692", "4693", "4694", "4695", "4696", "4697", "4698", "4699", "4700", "4701", "4702", "4703", "4704", "4705", "4706", "4707", "4708", "4709", "4710", "4711", "4712", "4713", "4714", "4715", "4716", "4717", "4718", "4719", "4720", "4721", "4722", "4723", "4724", "4725", "4726", "4727", "4728", "4729", "4730", "4731", "4732", "4733", "4734", "4735", "4736", "4737", "4738", "4739", "4740", "4741", "4742", "4743", "4744", "4745", "4746", "4747", "4748", "4749", "4750", "4751", "4752", "4753", "4754", "4755", "4756", "4757", "4758", "4759", "4760", "4761", "4762", "4763", "4764", "4765", "4766", "4767", "4768", "4769", "4770", "4771", "4772", "4773", "4774", "4775", "4776", "4777", "4778", "4779", "4780", "4781", "4782", "4783", "4784", "4785", "4786", "4787", "4788", "4789", "4790", "4791", "4792", "4793", "4794", "4795", "4796", "4797", "4798", "4799", "4800", "4801", "4802", "4803", "4804", "4805", "4806", "4807", "4808", "4809", "4810", "4811", "4812", "4813", "4814", "4815", "4816", "4817", "4818", "4819", "4820", "4821", "4822", "4823", "4824", "4825", "4826", "4827", "4828", "4829", "4830", "4831", "4832", "4833", "4834", "4835", "4836", "4837", "4838", "4839", "4840", "4841", "4842", "4843", "4844", "4845", "4846", "4847", "4848", "4849", "4850", "4851", "4852", "4853", "4854", "4855", "4856", "4857", "4858", "4859", "4860", "4861", "4862", "4863", "4864", "4865", "4866", "4867", "4868", "4869", "4870", "4871", "4872", "4873", "4874", "4875", "4876", "4877", "4878", "4879", "4880", "4881", "4882", "4883", "4884", "4885", "4886", "4887", "4888", "4889", "4890", "4891", "4892", "4893", "4894", "4895", "4896", "4897", "4898", "4899", "4900", "4901", "4902", "4903", "4904", "4905", "4906", "4907", "4908", "4909", "4910", "4911", "4912", "4913", "4914", "4915", "4916", "4917", "4918", "4919", "4920", "4921", "4922", "4923", "4924", "4925", "4926", "4927", "4928", "4929", "4930", "4931", "4932", "4933", "4934", "4935", "4936", "4937", "4938", "4939", "4940", "4941", "4942", "4943", "4944", "4945", "4946", "4947", "4948", "4949", "4950", "4951", "4952", "4953", "4954", "4955", "4956", "4957", "4958", "4959", "4960", "4961", "4962", "4963", "4964", "4965", "4966", "4967", "4968", "4969", "4970", "4971", "4972", "4973", "4974", "4975", "4976", "4977", "4978", "4979", "4980", "4981", "4982", "4983", "4984", "4985", "4986", "4987", "4988", "4989", "4990", "4991", "4992", "4993", "4994", "4995", "4996", "4997", "4998", "4999", "5000", "5001", "5002", "5003", "5004", "5005", "5006", "5007", "5008", "5009", "5010", "5011", "5012", "5013", "5014", "5015", "5016", "5017", "5018", "5019", "5020", "5021", "5022", "5023", "5024", "5025", "5026", "5027", "5028", "5029", "5030", "5031", "5032", "5033", "5034", "5035", "5036", "5037", "5038", "5039", "5040", "5041", "5042", "5043", "5044", "5045", "5046", "5047", "5048", "5049", "5050", "5051", "5052", "5053", "5054", "5055", "5056", "5057", "5058", "5059", "5060", "5061", "5062", "5063", "5064", "5065", "5066", "5067", "5068", "5069", "5070", "5071", "5072", "5073", "5074", "5075", "5076", "5077", "5078", "5079", "5080", "5081", "5082", "5083", "5084", "5085", "5086", "5087", "5088", "5089", "5090", "5091", "5092", "5093", "5094", "5095", "5096", "5097", "5098", "5099", "5100", "5101", "5102", "5103", "5104", "5105", "5106", "5107", "5108", "5109", "5110", "5111", "5112", "5113", "5114", "5115", "5116", "5117", "5118", "5119", "5120", "5121", "5122", "5123", "5124", "5125", "5126", "5127", "5128", "5129", "5130", "5131", "5132", "5133", "5134", "5135", "5136", "5137", "5138", "5139", "5140", "5141", "5142", "5143", "5144", "5145", "5146", "5147", "5148", "5149", "5150", "5151", "5152", "5153", "5154", "5155", "5156", "5157", "5158", "5159", "5160", "5161", "5162", "5163", "5164", "5165", "5166", "5167", "5168", "5169", "5170", "5171", "5172", "5173", "5174", "5175", "5176", "5177", "5178", "5179", "5180", "5181", "5182", "5183", "5184", "5185", "5186", "5187", "5188", "5189", "5190", "5191", "5192", "5193", "5194", "5195", "5196", "5197", "5198", "5199", "5200", "5201", "5202", "5203", "5204", "5205", "5206", "5207", "5208", "5209", "5210", "5211", "5212", "5213", "5214", "5215", "5216", "5217", "5218", "5219", "5220", "5221", "5222", "5223", "5224", "5225", "5226", "5227", "5228", "5229", "5230", "5231", "5232", "5233", "5234", "5235", "5236", "5237", "5238", "5239", "5240", "5241", "5242", "5243", "5244", "5245", "5246", "5247", "5248", "5249", "5250", "5251", "5252", "5253", "5254", "5255", "5256", "5257", "5258", "5259", "5260", "5261", "5262", "5263", "5264", "5265", "5266", "5267", "5268", "5269", "5270", "5271", "5272", "5273", "5274", "5275", "5276", "5277", "5278", "5279", "5280", "5281", "5282", "5283", "5284", "5285", "5286", "5287", "5288", "5289", "5290", "5291", "5292", "5293", "5294", "5295", "5296", "5297", "5298", "5299", "5300", "5301", "5302", "5303", "5304", "5305", "5306", "5307", "5308", "5309", "5310", "5311", "5312", "5313", "5314", "5315", "5316", "5317", "5318", "5319", "5320", "5321", "5322", "5323", "5324", "5325", "5326", "5327", "5328", "5329", "5330", "5331", "5332", "5333", "5334", "5335", "5336", "5337", "5338", "5339", "5340", "5341", "5342", "5343", "5344", "5345", "5346", "5347", "5348", "5349", "5350", "5351", "5352", "5353", "5354", "5355", "5356", "5357", "5358", "5359", "5360", "5361", "5362", "5363", "5364", "5365", "5366", "5367", "5368", "5369", "5370", "5371", "5372", "5373", "5374", "5375", "5376", "5377", "5378", "5379", "5380", "5381", "5382", "5383", "5384", "5385", "5386", "5387", "5388", "5389", "5390", "5391", "5392", "5393", "5394", "5395", "5396", "5397", "5398", "5399", "5400", "5401", "5402", "5403", "5404", "5405", "5406", "5407", "5408", "5409", "5410", "5411", "5412", "5413", "5414", "5415", "5416", "5417", "5418", "5419", "5420", "5421", "5422", "5423", "5424", "5425", "5426", "5427", "5428", "5429", "5430", "5431", "5432", "5433", "5434", "5435", "5436", "5437", "5438", "5439", "5440", "5441", "5442", "5443", "5444", "5445", "5446", "5447", "5448", "5449", "5450", "5451", "5452", "5453", "5454", "5455", "5456", "5457", "5458", "5459", "5460", "5461", "5462", "5463", "5464", "5465", "5466", "5467", "5468", "5469", "5470", "5471", "5472", "5473", "5474", "5475", "5476", "5477", "5478", "5479", "5480", "5481", "5482", "5483", "5484", "5485", "5486", "5487", "5488", "5489", "5490", "5491", "5492", "5493", "5494", "5495", "5496", "5497", "5498", "5499", "5500", "5501", "5502", "5503", "5504", "5505", "5506", "5507", "5508", "5509", "5510", "5511", "5512", "5513", "5514", "5515", "5516", "5517", "5518", "5519", "5520", "5521", "5522", "5523", "5524", "5525", "5526", "5527", "5528", "5529", "5530", "5531", "5532", "5533", "5534", "5535", "5536", "5537", "5538", "5539", "5540", "5541", "5542", "5543", "5544", "5545", "5546", "5547", "5548", "5549", "5550", "5551", "5552", "5553", "5554", "5555", "5556", "5557", "5558", "5559", "5560", "5561", "5562", "5563", "5564", "5565", "5566", "5567", "5568", "5569", "5570", "5571", "5572", "5573", "5574", "5575", "5576", "5577", "5578", "5579", "5580", "5581", "5582", "5583", "5584", "5585", "5586", "5587", "5588", "5589", "5590", "5591", "5592", "5593", "5594", "5595", "5596", "5597", "5598", "5599", "5600", "5601", "5602", "5603", "5604", "5605", "5606", "5607", "5608", "5609", "5610", "5611", "5612", "5613", "5614", "5615", "5616", "5617", "5618", "5619", "5620", "5621", "5622", "5623", "5624", "5625", "5626", "5627", "5628", "5629", "5630", "5631", "5632", "5633", "5634", "5635", "5636", "5637", "5638", "5639", "5640", "5641", "5642", "5643", "5644", "5645", "5646", "5647", "5648", "5649", "5650", "5651", "5652", "5653", "5654", "5655", "5656", "5657", "5658", "5659", "5660", "5661", "5662", "5663", "5664", "5665", "5666", "5667", "5668", "5669", "5670", "5671", "5672", "5673", "5674", "5675", "5676", "5677", "5678", "5679", "5680", "5681", "5682", "5683", "5684", "5685", "5686", "5687", "5688", "5689", "5690", "5691", "5692", "5693", "5694", "5695", "5696", "5697", "5698", "5699", "5700", "5701", "5702", "5703", "5704", "5705", "5706", "5707", "5708", "5709", "5710", "5711", "5712", "5713", "5714", "5715", "5716", "5717", "5718", "5719", "5720", "5721", "5722", "5723", "5724", "5725", "5726", "5727", "5728", "5729", "5730", "5731", "5732", "5733", "5734", "5735", "5736", "5737", "5738", "5739", "5740", "5741", "5742", "5743", "5744", "5745", "5746", "5747", "5748", "5749", "5750", "5751", "5752", "5753", "5754", "5755", "5756", "5757", "5758", "5759", "5760", "5761", "5762", "5763", "5764", "5765", "5766", "5767", "5768", "5769", "5770", "5771", "5772", "5773", "5774", "5775", "5776", "5777", "5778", "5779", "5780", "5781", "5782", "5783", "5784", "5785", "5786", "5787", "5788", "5789", "5790", "5791", "5792", "5793", "5794", "5795", "5796", "5797", "5798", "5799", "5800", "5801", "5802", "5803", "5804", "5805", "5806", "5807", "5808", "5809", "5810", "5811", "5812", "5813", "5814", "5815", "5816", "5817", "5818", "5819", "5820", "5821", "5822", "5823", "5824", "5825", "5826", "5827", "5828", "5829", "5830", "5831", "5832", "5833", "5834", "5835", "5836", "5837", "5838", "5839", "5840", "5841", "5842", "5843", "5844", "5845", "5846", "5847", "5848", "5849", "5850", "5851", "5852", "5853", "5854", "5855", "5856", "5857", "5858", "5859", "5860", "5861", "5862", "5863", "5864", "5865", "5866", "5867", "5868", "5869", "5870", "5871", "5872", "5873", "5874", "5875", "5876", "5877", "5878", "5879", "5880", "5881", "5882", "5883", "5884", "5885", "5886", "5887", "5888", "5889", "5890", "5891", "5892", "5893", "5894", "5895", "5896", "5897", "5898", "5899", "5900", "5901", "5902", "5903", "5904", "5905", "5906", "5907", "5908", "5909", "5910", "5911", "5912", "5913", "5914", "5915", "5916", "5917", "5918", "5919", "5920", "5921", "5922", "5923", "5924", "5925", "5926", "5927", "5928", "5929", "5930", "5931", "5932", "5933", "5934", "5935", "5936", "5937", "5938", "5939", "5940", "5941", "5942", "5943", "5944", "5945", "5946", "5947", "5948", "5949", "5950", "5951", "5952", "5953", "5954", "5955", "5956", "5957", "5958", "5959", "5960", "5961", "5962", "5963", "5964", "5965", "5966", "5967", "5968", "5969", "5970", "5971", "5972", "5973", "5974", "5975", "5976", "5977", "5978", "5979", "5980", "5981", "5982", "5983", "5984", "5985", "5986", "5987", "5988", "5989", "5990", "5991", "5992", "5993", "5994", "5995", "5996", "5997", "5998", "5999", "6000", "6001", "6002", "6003", "6004", "6005", "6006", "6007", "6008", "6009", "6010", "6011", "6012", "6013", "6014", "6015", "6016", "6017", "6018", "6019", "6020", "6021", "6022", "6023", "6024", "6025", "6026", "6027", "6028", "6029", "6030", "6031", "6032", "6033", "6034", "6035", "6036", "6037", "6038", "6039", "6040", "6041", "6042", "6043", "6044", "6045", "6046", "6047", "6048", "6049", "6050", "6051", "6052", "6053", "6054", "6055", "6056", "6057", "6058", "6059", "6060", "6061", "6062", "6063", "6064", "6065", "6066", "6067", "6068", "6069", "6070", "6071", "6072", "6073", "6074", "6075", "6076", "6077", "6078", "6079", "6080", "6081", "6082", "6083", "6084", "6085", "6086", "6087", "6088", "6089", "6090", "6091", "6092", "6093", "6094", "6095", "6096", "6097", "6098", "6099", "6100", "6101", "6102", "6103", "6104", "6105", "6106", "6107", "6108", "6109", "6110", "6111", "6112", "6113", "6114", "6115", "6116", "6117", "6118", "6119", "6120", "6121", "6122", "6123", "6124", "6125", "6126", "6127", "6128", "6129", "6130", "6131", "6132", "6133", "6134", "6135", "6136", "6137", "6138", "6139", "6140", "6141", "6142", "6143", "6144", "6145", "6146", "6147", "6148", "6149", "6150", "6151", "6152", "6153", "6154", "6155", "6156", "6157", "6158", "6159", "6160", "6161", "6162", "6163", "6164", "6165", "6166", "6167", "6168", "6169", "6170", "6171", "6172", "6173", "6174", "6175", "6176", "6177", "6178", "6179", "6180", "6181", "6182", "6183", "6184", "6185", "6186", "6187", "6188", "6189", "6190", "6191", "6192", "6193", "6194", "6195", "6196", "6197", "6198", "6199", "6200", "6201", "6202", "6203", "6204", "6205", "6206", "6207", "6208", "6209", "6210", "6211", "6212", "6213", "6214", "6215", "6216", "6217", "6218", "6219", "6220", "6221", "6222", "6223", "6224", "6225", "6226", "6227", "6228", "6229", "6230", "6231", "6232", "6233", "6234", "6235", "6236", "6237", "6238", "6239", "6240", "6241", "6242", "6243", "6244", "6245", "6246", "6247", "6248", "6249", "6250", "6251", "6252", "6253", "6254", "6255", "6256", "6257", "6258", "6259", "6260", "6261", "6262", "6263", "6264", "6265", "6266", "6267", "6268", "6269", "6270", "6271", "6272", "6273", "6274", "6275", "6276", "6277", "6278", "6279", "6280", "6281", "6282", "6283", "6284", "6285", "6286", "6287", "6288", "6289", "6290", "6291", "6292", "6293"};

// ktact.c
static f32 ktactGetLimitAng_down(float* nor) {
    float wnor[4] = {0.0f, -1.0f, 0.0f, 0.0f}; // 0x20(r29)
    s32* ptr = &wnor;
    float limit_ang; // 0x38(r29)
    float ang = sbcoreGetInnerAngle180(&wnor, nor); // 0x3C(r29)

    if (ang < 0.0f) {
        limit_ang = 0.95993096f;
    } else if (ang < 1.0f) {
        limit_ang = 0.76794475f * (1.0f - ang);
        limit_ang += 0.19198619f;
    } else {
        limit_ang = 0.19198619f;
    }
    return limit_ang;
}

// ktact.c
static unsigned int David_ktactGetHit_hit2(Col* col, float* from, float* to, signed int water, signed int* ret, signed int num) {
    // Size: 0x60, DWARF: 0x75E44
    static Col col_hit[4][4][8][16];
    Col* cc[8]; // 0xA0(r29)
    _anon8 area; // 0xC0(r29)
    signed int i; // r16
    // Size: 0x60, DWARF: 0x75E44
    Col* c; // r17
    signed int n; // r18
    signed int h; // r19
    signed int tmp; // r20
    signed int x; // r21
    signed int y; // r22
    signed int bx_from; // r23
    signed int by_from; // r30
    signed int bx_to; // 0xD4(r29)
    signed int by_to; // 0xD8(r29)
    unsigned int hit; // 0xDC(r29)

    hit = 0;
    ktactGetBlockArea(&area, from, to);
    bx_from = area.si[0];
    bx_to = area.si[1];
    by_from = area.si[2];
    by_to = area.si[3];
    for (y = by_from; y <= by_to; y++) {
        for (x = bx_from; x <= bx_to; x++) {
            for (i = 0; i < num; i++) {
                cc[i] = col_hit[y - by_from][x - bx_from][i];
            }
            David_GetHitCollision2(cc, ret, x, y, from, to, num);
            for (i = 0; i < num; i++) {
                cc[i]->res[0] = ret[i];
            }
        }
    }
    for (n = 0; n < num; n++) {
        h = 0;
        col[n].len = 1.6777e+07f;
        for (y = by_from; y <= by_to; y++) {
            for (x = bx_from; x <= bx_to; x++) {
                c = col_hit[y - by_from][x - bx_from][n];
                tmp = c->res[0];
                for (i = 0; i < tmp; i++) {
                    if (c[i].len < col[n].len) {
                        if (c[i].attr & 0xA000) {
                            switch (c[i].attr & 0x7FF) {
                                case 8:
                                    if (water == 0) {
                                        continue;
                                    }
                                    break;
                            }
                            col[n] = c[i];
                            col[n].res[0] = 3;
                            h = 1;
                        } else {
                            switch (c[i].no) {
                                case 6:
                                    c[i].attr &= 0xF800;
                                    c[i].attr |= 0xA;
                                    col[n] = c[i];
                                    col[n].res[0] = 3;
                                    h = 1;
                                    break;
                                case 7:
                                    c[i].attr &= 0xF800;
                                    c[i].attr |= 0x9;
                                case 0:
                                case 1:
                                    col[n] = c[i];
                                    col[n].res[0] = 3;
                                    h = 1;
                                    break;
                            }
                        }
                    }
                }
            }
        }
        if (h) {
            hit |= 1 << n;
        }
    }
    return hit;
}

// ktact.c
static unsigned int David_ktactGetHit_obs2(Col* col, float* from, float* to, signed int* ret, signed int num) {
    // Size: 0x60, DWARF: 0x75E44
    static Col col_obs[8][16];
    Col* cc[8]; // 0xA0(r29)
    _anon8 area; // 0xC0(r29)
    signed int i; // r16
    signed int n; // r17
    // Size: 0x60, DWARF: 0x75E44
    Col* c; // r18
    signed int h; // r19
    unsigned int hit; // r20
    signed int bx_from; // r21
    signed int bx_to; // r22
    signed int by_from; // r23
    signed int by_to; // r30
    signed int tmp; // 0xDC(r29)

    hit = 0;
    ktactGetBlockArea(&area, from, to);
    bx_from = area.si[0];
    bx_to = area.si[1];
    by_from = area.si[2];
    by_to = area.si[3];
    for (i = 0; i < num; i++) {
        cc[i] = col_obs[i];
    }
    tmp = David_tmcrsGetObjectCollision2(cc, ret, from, to, num);
    for (n = 0; n < num; n++) {
        h = 0;
        c = cc[n];
        col[n].len = 1.6777e+07f;
        for (i = 0; i < ret[n]; i++) {
            if (c[i].len < col[n].len) {
                switch (c[i].obj_attr & 0xFFF) {
                    case 1:
                        col[n] = c[i];
                        col[n].res[0] = 7;
                        h = 1;
                        break;
                    case 2:
                        break;
                    case 0:
                        break;
                }
            }
        }
        if (h) {
            hit |= 1 << n;
        }
    }
    return hit;
}

// ktact.c
static signed int David_ktactGetHit_obs(Col* cross, float* from, float* to, Col* obj_buff, signed int unused1, signed int* num_obj, signed int kill_far) {
    // Size: 0x60, DWARF: 0x75E44
    static Col col_obs[16];
    // Size: 0x60, DWARF: 0x75E44
    Col col; // 0xA0(r29)
    _anon8 area; // 0x100(r29)
    signed int i; // r16
    // Size: 0x60, DWARF: 0x75E44
    Col* c; // r17
    signed int current; // r18
    signed int num; // r19
    signed int hit; // r20
    signed int bx_from; // r21
    signed int bx_to; // r22
    signed int by_from; // r23
    signed int by_to; // r30

    hit = 0;
    current = 0;
    ktactGetBlockArea(&area, from, to);
    bx_from = area.si[0];
    bx_to = area.si[1];
    by_from = area.si[2];
    by_to = area.si[3];
    if (kill_far) {
        num = tmcrsGetObjectCollision(col_obs, from, to);
        c = col_obs;
        col = *cross;
    } else {
        if (obj_buff) {
            num = tmcrsGetObjectCollision(obj_buff, from, to);
            *num_obj = num;
            c = obj_buff;
        } else {
            num = tmcrsGetObjectCollision(col_obs, from, to);
            c = col_obs;
        }
        col.len = 1.6777e+07f;
    }
    for (i = 0; i < num; i++) {
        if (c[i].len < col.len) {
            if (kill_far) {
                if (obj_buff) {
                    obj_buff[current] = c[i];
                    obj_buff[current].res[0] = 7;
                }
                current++;
                if (num_obj) {
                    *num_obj = current;
                }
            }
            switch (c[i].obj_attr & 0xFFF) {
                case 1:
                    col = c[i];
                    col.res[0] = 7;
                    hit = 1;
                    break;
                case 2:
                    break;
                case 0:
                    break;
            }
        }
    }
    if (kill_far || hit) {
        *cross = col;
    }
    return hit;
}
