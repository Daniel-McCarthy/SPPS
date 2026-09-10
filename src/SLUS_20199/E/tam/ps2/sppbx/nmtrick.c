// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// Static data ///////////////////////////////////////////////////////////////////////

//////// vspRider (from ktact.c)/////////////////////////////////////////

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
typedef struct Stats
{
    signed int ollie; // Offset: 0x0, DWARF: 0x7C61D
    signed int spin; // Offset: 0x4, DWARF: 0x7C63F
    signed int speed; // Offset: 0x8, DWARF: 0x7C660
    signed int landing; // Offset: 0xC, DWARF: 0x7C682
    signed int balance; // Offset: 0x10, DWARF: 0x7C6A6
    signed int stability; // Offset: 0x14, DWARF: 0x7C6CA
    signed int stance; // Offset: 0x18, DWARF: 0x7C6F0
} Stats;

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

// Size: 0x190, DWARF: 0x7F127
typedef struct Cam
{
    float pre_speed[4]; // Offset: 0x0, DWARF: 0x7F143
    float now_speed[4]; // Offset: 0x10, DWARF: 0x7F16B
    float normal_speed[4]; // Offset: 0x20, DWARF: 0x7F193
    float rot[4]; // Offset: 0x30, DWARF: 0x7F1BE
    float pos_waist[4]; // Offset: 0x40, DWARF: 0x7F1E0
    float pos_disp[4]; // Offset: 0x50, DWARF: 0x7F208
    // Size: 0x60, DWARF: 0x79DD3
    Pos pos; // Offset: 0x60, DWARF: 0x7F22F
    // Size: 0x60, DWARF: 0x79DD3
    Pos prepos; // Offset: 0xC0, DWARF: 0x7F251
    // DWARF: 0x7EA91
    Ripside ripside; // Offset: 0x120, DWARF: 0x7F276
    // DWARF: 0x7C53F
    Sliding_State sliding_state; // Offset: 0x124, DWARF: 0x7F29C
    // DWARF: 0x7C53F
    Sliding_State pre_state; // Offset: 0x128, DWARF: 0x7F2C8
    // DWARF: 0x7C53F
    Sliding_State pre_tumble_state; // Offset: 0x12C, DWARF: 0x7F2F0
    float max_height; // Offset: 0x130, DWARF: 0x7F31F
    signed int cnt_onair; // Offset: 0x134, DWARF: 0x7F346
    signed int cnt_turn; // Offset: 0x138, DWARF: 0x7F36C
    float max_speed; // Offset: 0x13C, DWARF: 0x7F391
    signed int hp_air; // Offset: 0x140, DWARF: 0x7F3B7
    float splen_prejump; // Offset: 0x144, DWARF: 0x7F3DA
    // DWARF: 0x7E931
    Tumble_Type tumble_type; // Offset: 0x148, DWARF: 0x7F404
    // DWARF: 0x7FF3C
    Tumble_Way tumble_way; // Offset: 0x14C, DWARF: 0x7F42E
    // DWARF: 0x7E931
    Tumble_Type trg_tumble_type; // Offset: 0x150, DWARF: 0x7F457
    signed int trg_tumble_standup; // Offset: 0x154, DWARF: 0x7F485
    float grind_enter_ang; // Offset: 0x158, DWARF: 0x7F4B4
    signed int trick_link; // Offset: 0x15C, DWARF: 0x7F4E0
    signed int trg_start_endmot; // Offset: 0x160, DWARF: 0x7F507
    signed int trg_recovered; // Offset: 0x164, DWARF: 0x7F534
    signed int trg_hopup; // Offset: 0x168, DWARF: 0x7F55E
    signed int trg_jumpup; // Offset: 0x16C, DWARF: 0x7F584
    signed int trg_touch; // Offset: 0x170, DWARF: 0x7F5AB
    signed int trg_boost; // Offset: 0x174, DWARF: 0x7F5D1
    signed int bonk_goto; // Offset: 0x178, DWARF: 0x7F5F7
    signed int trg_plant; // Offset: 0x17C, DWARF: 0x7F61D
    signed int grind_goto; // Offset: 0x180, DWARF: 0x7F643
} Cam;

// Size: 0x48, DWARF: 0x7C763
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

// Size: 0x8, DWARF: 0x168106
typedef struct Pad
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x168121
    signed char lh; // Offset: 0x2, DWARF: 0x168141
    signed char lv; // Offset: 0x3, DWARF: 0x168160
    signed int analog; // Offset: 0x4, DWARF: 0x16817F
} Pad;

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
    Stats chr_param_x10; // Offset: 0x4B4, DWARF: 0x77B5B
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
    struct // : E:\tam\ps2\sppbx\main.c
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
    } nowreq; // Offset: 0x298, DWARF: 0x16AE17
    // Size: 0x48, DWARF: 0x16EEA4
    struct // : E:\tam\ps2\sppbx\main.c
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
    } prereq; // Offset: 0x2E0, DWARF: 0x16AE3C
    // Size: 0x2580, DWARF: 0x168520
    Act act; // Offset: 0x330, DWARF: 0x16AE61
    // Size: 0x190, DWARF: 0x1677E9
    struct // Offset 28B0
    {
        // Size: 0x2C, DWARF: 0x16DF3B
        struct // Offset 0x28B0
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
        } now; // Offset: 0x0, DWARF: 0x167804
        // Size: 0x2C, DWARF: 0x16DF3B
        struct // Offset 2C + 28B0 = 28DC
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
        } next; // Offset: 0x2C, DWARF: 0x167826
        // Size: 0x2C, DWARF: 0x16DF3B
        struct
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
        } pre; // Offset: 0x58, DWARF: 0x167849
        // Size: 0x2C, DWARF: 0x16DF3B
        struct
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
        } pre2; // Offset: 0x84, DWARF: 0x16786B
        // Size: 0x2C, DWARF: 0x16DF3B
        struct // Offset B0 + 28B0 = 2960
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
        } now2; // Offset: 0xB0, DWARF: 0x16788E
        // Size: 0x2C, DWARF: 0x16DF3B
        struct // Offset 28B0 + DC = 298C
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
        } next2; // Offset: 0xDC, DWARF: 0x1678B1
        // Size: 0x50, DWARF: 0x16F172
        struct // Offset 28B0 + 110 = 29C0
        {
            // Size: 0x20, DWARF: 0x16E73E
            struct
            {
                float rot[4]; // Offset: 0x0, DWARF: 0x16E75A
                signed int frame; // Offset: 0x10, DWARF: 0x16E77C
                signed int pad; // Offset: 0x14, DWARF: 0x16E79E
            }* key_list; // Offset: 0x0, DWARF: 0x16F18E
            // Size: 0x20, DWARF: 0x16E73E
            struct // Offset 29C0 + 10 = 29D0
            {
                float rot[4] __attribute__((aligned (16))); // Offset: 0x0, DWARF: 0x16E75A
                signed int frame; // Offset: 0x10, DWARF: 0x16E77C
                signed int pad; // Offset: 0x14, DWARF: 0x16E79E
            } now; // Offset: 0x10, DWARF: 0x16F1B8
            signed int num_key; // Offset: 0x30, DWARF: 0x16F1DA
            signed int num_frame; // Offset: 0x34, DWARF: 0x16F1FE
            // DWARF: 0x16ECC4
            enum
            {
                eflReady,
                eflFlipping,
                eflEnd
            } flipmode; // Offset: 0x38, DWARF: 0x16F224
            signed int mot_id; // Offset: 0x3C, DWARF: 0x16F24B
            signed int play_mot; // Offset: 0x40, DWARF: 0x16F26E
        } flip __attribute__((aligned (16))); // Offset: 0x110, DWARF: 0x1678D5
        signed int cnt_ik_foot; // Offset: 0x160, DWARF: 0x1678F8
        signed int freemotion; // Offset: 0x164, DWARF: 0x167920
        signed int ik; // Offset: 0x168, DWARF: 0x167947
        signed int reserve_schange; // Offset: 0x16C, DWARF: 0x167966
        signed int reserve_brending_schange; // Offset: 0x170, DWARF: 0x167992
        signed int motion_speed; // Offset: 0x174, DWARF: 0x1679C7
        signed int mot_sp_flip; // Offset: 0x178, DWARF: 0x1679F0
        signed int trg_to_calc_flip; // Offset: 0x17C, DWARF: 0x167A18
        signed int to_calc_flip; // Offset: 0x180, DWARF: 0x167A45
    } mot; // Offset: 0x28B0, DWARF: 0x16AE83
    // Size: 0x190, DWARF: 0x16B9B7
    struct // : E:\tam\ps2\sppbx\main.c // Offset 2A40
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
    } cam; // Offset: 0x2A40, DWARF: 0x16AEA5
    // Size: 0x14, DWARF: 0x16D54F
    struct
    {
        float splen; // Offset: 0x0, DWARF: 0x16D56B
        float rot_pole; // Offset: 0x4, DWARF: 0x16D58D
        float anggap_sp_brd; // Offset: 0x8, DWARF: 0x16D5B2
        float anggap_board_rot; // Offset: 0xC, DWARF: 0x16D5DC
        signed int side_slide; // Offset: 0x10, DWARF: 0x16D609
    } se __attribute__((aligned(16))); // Offset: 0x2BD0, DWARF: 0x16AEC7
    // Size: 0x3C, DWARF: 0x167640
    struct
    {
        signed int no; // Offset: 0x0, DWARF: 0x16765B
        signed int player; // Offset: 0x4, DWARF: 0x16767A
        signed int wear; // Offset: 0x8, DWARF: 0x16769D
        signed int board; // Offset: 0xC, DWARF: 0x1676BE
        // Size: 0x1C, DWARF: 0x16D2B9
        Stats chr_param; // Offset: 0x10, DWARF: 0x1676E0
        // Size: 0x10, DWARF: 0x16DA24
        Board_Param brd_param; // Offset: 0x2C, DWARF: 0x167708
    }* param; // Offset: 0x2BE4, DWARF: 0x16AEE8
    // Size: 0x24, DWARF: 0x167A72
    struct
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
    }* key; // Offset: 0x2BE8, DWARF: 0x16AF0F
    // Size: 0x30, DWARF: 0x167BEE
    Cheats* cheats; // Offset: 0x2BEC, DWARF: 0x16AF34
    // Size: 0x340, DWARF: 0x167DF5
    struct
    {
        // Size: 0x30, DWARF: 0x16C801
        struct // : E:\tam\ps2\sppbx\main.c
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
        } scr_info; // Offset: 0x0, DWARF: 0x167E10
        // Size: 0x20, DWARF: 0x16D961
        struct // : E:\tam\ps2\sppbx\main.c
        {
            float min; // Offset: 0x0, DWARF: 0x16D97D
            float max; // Offset: 0x4, DWARF: 0x16D99D
            float far; // Offset: 0x8, DWARF: 0x16D9BD
            float near; // Offset: 0xC, DWARF: 0x16D9DD
            signed int col[4]; // Offset: 0x10, DWARF: 0x16D9FE
        } fog; // Offset: 0x30, DWARF: 0x167E37
        // Size: 0x140, DWARF: 0x16DBF7
        struct
        {
            sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x16DC13
            sceVu0FMATRIX local_light; // Offset: 0x40, DWARF: 0x16DC3E
            sceVu0FMATRIX light_color; // Offset: 0x80, DWARF: 0x16DC68
            sceVu0FMATRIX local_clip; // Offset: 0xC0, DWARF: 0x16DC92
            sceVu0FMATRIX clip_screen; // Offset: 0x100, DWARF: 0x16DCBB
        } matrix; // Offset: 0x50, DWARF: 0x167E59
        sceVu0FMATRIX world_screen; // Offset: 0x190, DWARF: 0x167E7E
        sceVu0FMATRIX world_view; // Offset: 0x1D0, DWARF: 0x167EA9
        sceVu0FMATRIX view_screen; // Offset: 0x210, DWARF: 0x167ED2
        sceVu0FMATRIX light_color; // Offset: 0x250, DWARF: 0x167EFC
        sceVu0FMATRIX normal_light; // Offset: 0x290, DWARF: 0x167F26
        sceVu0FMATRIX view_clip; // Offset: 0x2D0, DWARF: 0x167F51
        sceVu0FVECTOR cam_rot; // Offset: 0x310, DWARF: 0x167F79
        sceVu0FVECTOR cam_trans; // Offset: 0x320, DWARF: 0x167F9F
        float view_angle; // Offset: 0x330, DWARF: 0x167FC7
    }* sys_mat ; // Offset: 0x2BF0, DWARF: 0x16AF5C
} Ctrl;

// Size: 0x2A30, DWARF: 0x7F8F0
typedef struct Disp
{
    void* umd; // Offset: 0x0, DWARF: 0x7F90C
    void* utd; // Offset: 0x4, DWARF: 0x7F92F
    // Size: 0xF0, DWARF: 0x80315
    struct
    {
        unsigned int model_id; // Offset: 0x0, DWARF: 0x80331
        signed int loop; // Offset: 0x4, DWARF: 0x80356
        signed int mode; // Offset: 0x8, DWARF: 0x80377
        signed int write_flg; // Offset: 0xC, DWARF: 0x80398
        signed int now_local_id; // Offset: 0x10, DWARF: 0x803BE
        signed int now_top_id; // Offset: 0x14, DWARF: 0x803E7
        signed int next_local_id; // Offset: 0x18, DWARF: 0x8040E
        signed int next_top_id; // Offset: 0x1C, DWARF: 0x80438
        // Size: 0x20, DWARF: 0x7EE12
        struct
        {
            float pos[4]; // Offset: 0x0, DWARF: 0x7EE2E
            float rot[4]; // Offset: 0x10, DWARF: 0x7EE50
        }* mdl_data; // Offset: 0x20, DWARF: 0x80460
        float now_frame; // Offset: 0x24, DWARF: 0x8048A
        float next_frame; // Offset: 0x28, DWARF: 0x804B0
        float ratio; // Offset: 0x2C, DWARF: 0x804D7
        // Size: 0x10, DWARF: 0x813DF
        struct
        {
            unsigned int type; // Offset: 0x0, DWARF: 0x813FB
            float frame; // Offset: 0x4, DWARF: 0x8141C
            signed short flg; // Offset: 0x8, DWARF: 0x8143E
            signed short non; // Offset: 0xA, DWARF: 0x8145E
            float* data[4]; // Offset: 0xC, DWARF: 0x8147E
        }* now_pos_address; // Offset: 0x30, DWARF: 0x804F9
        // Size: 0x10, DWARF: 0x813DF
        struct
        {
            unsigned int type; // Offset: 0x0, DWARF: 0x813FB
            float frame; // Offset: 0x4, DWARF: 0x8141C
            signed short flg; // Offset: 0x8, DWARF: 0x8143E
            signed short non; // Offset: 0xA, DWARF: 0x8145E
            float* data[4]; // Offset: 0xC, DWARF: 0x8147E
        }* now_rot_address; // Offset: 0x34, DWARF: 0x8052A
        // Size: 0x10, DWARF: 0x813DF
        struct
        {
            unsigned int type; // Offset: 0x0, DWARF: 0x813FB
            float frame; // Offset: 0x4, DWARF: 0x8141C
            signed short flg; // Offset: 0x8, DWARF: 0x8143E
            signed short non; // Offset: 0xA, DWARF: 0x8145E
            float* data[4]; // Offset: 0xC, DWARF: 0x8147E
        }* next_pos_address; // Offset: 0x38, DWARF: 0x8055B
        // Size: 0x10, DWARF: 0x813DF
        struct
        {
            unsigned int type; // Offset: 0x0, DWARF: 0x813FB
            float frame; // Offset: 0x4, DWARF: 0x8141C
            signed short flg; // Offset: 0x8, DWARF: 0x8143E
            signed short non; // Offset: 0xA, DWARF: 0x8145E
            float* data[4]; // Offset: 0xC, DWARF: 0x8147E
        }* next_rot_address; // Offset: 0x3C, DWARF: 0x8058D
        float nowDir[4]; // Offset: 0x40, DWARF: 0x805BF
        float nowTrans[4]; // Offset: 0x50, DWARF: 0x805E4
        float now_matrix[4][4]; // Offset: 0x60, DWARF: 0x8060B
        float pos[4]; // Offset: 0xA0, DWARF: 0x80634
        float quat[4]; // Offset: 0xB0, DWARF: 0x80656
        float pre_pos[4]; // Offset: 0xC0, DWARF: 0x80679
        float pre_rot[4]; // Offset: 0xD0, DWARF: 0x8069F
        signed int startVertexIdx; // Offset: 0xE0, DWARF: 0x806C5
        signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0x806F0
        signed int pad[2]; // Offset: 0xE8, DWARF: 0x8071A
    }* seq; // Offset: 0x8, DWARF: 0x7F952
    // Size: 0x24, DWARF: 0x80BCF
    struct
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
    } uad_list; // Offset: 0xC, DWARF: 0x7F977
    // Size: 0x160, DWARF: 0x7D512
    struct // : E:\tam\ps2\sppbx\main.c
    {
        unsigned int enable; // Offset: 0x0, DWARF: 0x7D52E
        // Size: 0x140, DWARF: 0x7DA36
        struct // : E:\tam\ps2\sppbx\main.c
        {
            signed int count[8][3] __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x7DA52
            signed int speed[8][3]; // Offset: 0x60, DWARF: 0x7DA76
            float wave[8][4]; // Offset: 0xC0, DWARF: 0x7DA9A
        } wind; // Offset: 0x10, DWARF: 0x7D551
        // Size: 0x8, DWARF: 0x7E8D5
        struct
        {
            float a; // Offset: 0x0, DWARF: 0x7E8F1
            float b; // Offset: 0x4, DWARF: 0x7E90F
        } fog; // Offset: 0x150, DWARF: 0x7D574
        // Size: 0x8, DWARF: 0x7EB45
        struct // : E:\tam\ps2\sppbx\main.c
        {
            unsigned long tex0; // Offset: 0x0, DWARF: 0x7EB61
        } envmap; // Offset: 0x158, DWARF: 0x7D596
    } vmenv; // Offset: 0x30, DWARF: 0x7F99E
    // Size: 0x2E0, DWARF: 0x7CF19
    struct
    {
        float rot[4]; // Offset: 0x0, DWARF: 0x7CF35
        float trans[4]; // Offset: 0x10, DWARF: 0x7CF57
        float scale[4]; // Offset: 0x20, DWARF: 0x7CF7B
        float matrix[4][4]; // Offset: 0x30, DWARF: 0x7CF9F
        float revision[4][4]; // Offset: 0x70, DWARF: 0x7CFC4
        // Size: 0x230, DWARF: 0x81827
        struct
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
        } ikparam; // Offset: 0xB0, DWARF: 0x7CFEB
    }* umd_ctrl; // Offset: 0x190, DWARF: 0x7F9C2
    // Size: 0x1A0, DWARF: 0x7C011
    struct
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
    }* smd_ctrl; // Offset: 0x194, DWARF: 0x7F9EC
    // Size: 0x90, DWARF: 0x7BE99
    struct
    {
        float original[4][4]; // Offset: 0x0, DWARF: 0x7BEB5
        float original2[4][4]; // Offset: 0x40, DWARF: 0x7BEDC
        float* address[4][4]; // Offset: 0x80, DWARF: 0x7BF04
        float* address2[4][4]; // Offset: 0x84, DWARF: 0x7BF2D
        signed int pad[2]; // Offset: 0x88, DWARF: 0x7BF57
    }* model_change; // Offset: 0x198, DWARF: 0x7FA16
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
    struct
    {
        float rot[4]; // Offset: 0x0, DWARF: 0x7CF35
        float trans[4]; // Offset: 0x10, DWARF: 0x7CF57
        float scale[4]; // Offset: 0x20, DWARF: 0x7CF7B
        float matrix[4][4]; // Offset: 0x30, DWARF: 0x7CF9F
        float revision[4][4]; // Offset: 0x70, DWARF: 0x7CFC4
        // Size: 0x230, DWARF: 0x81827
        struct
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
        } ikparam; // Offset: 0xB0, DWARF: 0x7CFEB
    }* sub_umd_ctrl; // Offset: 0x285C, DWARF: 0x7FCC1
    // Size: 0x1A0, DWARF: 0x7C011
    struct
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
    }* sub_smd_ctrl; // Offset: 0x2860, DWARF: 0x7FCEF
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

// nmtrick.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x4, DWARF: 0x225C4E
typedef struct Course
{
    signed int no; // Offset: 0x0, DWARF: 0x225C6A
} Course;

// Size: 0x1C, DWARF: 0x227336
typedef struct CharacterParam
{
    signed int ollie; // Offset: 0x0, DWARF: 0x227352
    signed int spin; // Offset: 0x4, DWARF: 0x227374
    signed int speed; // Offset: 0x8, DWARF: 0x227395
    signed int landing; // Offset: 0xC, DWARF: 0x2273B7
    signed int balance; // Offset: 0x10, DWARF: 0x2273DB
    signed int stability; // Offset: 0x14, DWARF: 0x2273FF
    signed int stance; // Offset: 0x18, DWARF: 0x227425
} CharacterParam;

// Size: 0x10, DWARF: 0x227A42
typedef struct BoardParam
{
    signed int speed; // Offset: 0x0, DWARF: 0x227A5E
    signed int stability; // Offset: 0x4, DWARF: 0x227A80
    signed int balance; // Offset: 0x8, DWARF: 0x227AA6
    signed int turning; // Offset: 0xC, DWARF: 0x227ACA
} BoardParam;

// Size: 0x3C, DWARF: 0x225FB8
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x225FD4
    signed int player; // Offset: 0x4, DWARF: 0x225FF3
    signed int wear; // Offset: 0x8, DWARF: 0x226016
    signed int board; // Offset: 0xC, DWARF: 0x226037
    // Size: 0x1C, DWARF: 0x227336
    CharacterParam chr_param; // Offset: 0x10, DWARF: 0x226059
    // Size: 0x10, DWARF: 0x227A42
    BoardParam brd_param; // Offset: 0x2C, DWARF: 0x226081
} Character;

// Size: 0x18, DWARF: 0x22694A
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x226966
    signed int game_mode; // Offset: 0x4, DWARF: 0x22698D
    signed int match_rule; // Offset: 0x8, DWARF: 0x2269B3
    signed int divide; // Offset: 0xC, DWARF: 0x2269DA
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x2269FD
} Mode;

// Size: 0xA0, DWARF: 0x2275F5
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x225C4E
    Course course; // Offset: 0x0, DWARF: 0x227611
    // Size: 0x3C, DWARF: 0x225FB8
    Character character[2]; // Offset: 0x4, DWARF: 0x227636
    // Size: 0x18, DWARF: 0x22694A
    Mode mode; // Offset: 0x7C, DWARF: 0x22765E
    signed int language; // Offset: 0x94, DWARF: 0x227681
    signed int ending; // Offset: 0x98, DWARF: 0x2276A6
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x2276C9
} VspenvGame;

// Size: 0x10, DWARF: 0x221233
typedef struct Spin
{
    signed int rewind; // Offset: 0x0, DWARF: 0x22124E
    signed int cab; // Offset: 0x4, DWARF: 0x221271
    signed int value; // Offset: 0x8, DWARF: 0x221291
    signed int first; // Offset: 0xC, DWARF: 0x2212B3
} Spin;

// Size: 0x10, DWARF: 0x223D31
typedef struct TrickCol
{
    signed int state; // Offset: 0x0, DWARF: 0x223D4C
    signed int cnt; // Offset: 0x4, DWARF: 0x223D6E
    signed int land; // Offset: 0x8, DWARF: 0x223D8E
    signed int flight; // Offset: 0xC, DWARF: 0x223DAF
} TrickCol;

// Size: 0x40, DWARF: 0x22479E
typedef struct TrickQue
{
    signed int type; // Offset: 0x0, DWARF: 0x2247BA
    signed int sp_type; // Offset: 0x4, DWARF: 0x2247DB
    signed int num; // Offset: 0x8, DWARF: 0x2247FF
    signed int link; // Offset: 0xC, DWARF: 0x22481F
    signed int jump; // Offset: 0x10, DWARF: 0x224840
    signed int fakie; // Offset: 0x14, DWARF: 0x224861
    signed int late; // Offset: 0x18, DWARF: 0x224883
    signed int disaster; // Offset: 0x1C, DWARF: 0x2248A4
    // Size: 0x10, DWARF: 0x221233
    Spin spin; // Offset: 0x20, DWARF: 0x2248C9
    // Size: 0x10, DWARF: 0x223D31
    TrickCol col; // Offset: 0x30, DWARF: 0x2248EC
} TrickQue;

// Size: 0x810, DWARF: 0x223E39
typedef struct VnmtrickInfo
{
    // Size: 0x40, DWARF: 0x22479E
    TrickQue que[32]; // Offset: 0x0, DWARF: 0x223E54
    signed int land; // Offset: 0x800, DWARF: 0x223E76
    signed int flight; // Offset: 0x804, DWARF: 0x223E97
    signed int fakie; // Offset: 0x808, DWARF: 0x223EBA
    char entry_id; // Offset: 0x80C, DWARF: 0x223EDC
    char spin_id; // Offset: 0x80D, DWARF: 0x223F01
    char omit_id; // Offset: 0x80E, DWARF: 0x223F25
    char link_id; // Offset: 0x80F, DWARF: 0x223F49
} VnmtrickInfo;

// Size: 0x4, DWARF: 0x2258FC
typedef struct Word
{
    char id; // Offset: 0x0, DWARF: 0x225918
    char value; // Offset: 0x1, DWARF: 0x225937
    char res[2]; // Offset: 0x2, DWARF: 0x225959
} Word;

// Size: 0x4C, DWARF: 0x225E76
typedef struct List
{
    // Size: 0x4, DWARF: 0x2258FC
    Word word[16]; // Offset: 0x0, DWARF: 0x225E92
    float length; // Offset: 0x40, DWARF: 0x225EB5
    signed int res[2]; // Offset: 0x44, DWARF: 0x225ED8
} List;

// Size: 0x10, DWARF: 0x22516A
typedef struct Info
{
    float width; // Offset: 0x0, DWARF: 0x225186
    float font; // Offset: 0x4, DWARF: 0x2251A8
    signed int line; // Offset: 0x8, DWARF: 0x2251C9
    signed int res; // Offset: 0xC, DWARF: 0x2251EA
} Info;

//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0xA0, DWARF: 0x2275F5
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x5640, DWARF: 0x22501D
extern Rider* vspRider[8]; // Address: 0x3BD480
extern char* vsptblTrickName[160]; // Address: 0x2B6C60
extern char* vsptblGapList[8][64]; // Address: 0x2B5A60
extern char* vnmtblTrickAcce[3][7]; // Address: 0x2CE400

// nmtrick bss and sbss, declared highest address first.
// Size: 0x810, DWARF: 0x223E39
VnmtrickInfo vnmtrickInfo[2]; // Address: 0x3C8840
// Size: 0x4, DWARF: 0x225C4E
Course* vnmtrickCrsEnv; // Address: 0x2E80D8
// Size: 0x3C, DWARF: 0x225FB8
Character* vnmtrickCharEnv; // Address: 0x2E80D4
// Size: 0x18, DWARF: 0x22694A
Mode* vnmtrickModeEnv; // Address: 0x2E80D0
signed int* vnmtrickLang; // Address: 0x2E80CC

//// Function Declarations ///////////////////////////////////////////////////////////

void nmtrickInit();
void nmtrickInitInfo(// Size: 0x810, DWARF: 0x223E39
VnmtrickInfo* info);
void nmtrickInitInfo2(signed int id);
void nmtrickInitList(// Size: 0x4C, DWARF: 0x225E76
List* list);
static void nmtrickInitFig();
void nmtrickSetLand(signed int id, signed int type);
void nmtrickSetFlight(signed int id, signed int flag);
void nmtrickSetFakie(signed int id, signed int flag);
void nmtrickSetJump(signed int id, signed int num);
void nmtrickSetTrick(signed int id, signed int type, signed int num, signed int unused1);
void nmtrickSetSpin(signed int id, signed int pipe, signed int rewind, signed int spin);
void nmtrickSetInfo(signed int id, // Size: 0x810, DWARF: 0x223E39
VnmtrickInfo* info);
void nmtrickGetInfo(signed int id, // Size: 0x810, DWARF: 0x223E39
VnmtrickInfo* info);
signed int nmtrickMakeList(signed int id, // Size: 0x10, DWARF: 0x22516A
Info* info, // Size: 0x4C, DWARF: 0x225E76
List* list);
void nmtrickMakeStr(signed int id, // Size: 0x10, DWARF: 0x22516A
Info* info, // Size: 0x4C, DWARF: 0x225E76
List* list);
signed int nmtrickSetSpType(signed int num);
static void nmtrickDelInfo(signed int id);

void* memcpy(void* destination, void* source, int size);

float nmfontGetPackStrFLen(char* str, float font, signed int flag);
void ulstdSprintf(char* buf, char* fmt, ...);
char* strcat(char* dst, char* src);
void nmdispSetTrickFall(signed int id, char* str, signed int line);

//// Function Definitions ////////////////////////////////////////////////////////////

void nmtrickInit() {
    nmtrickInitFig();
    vnmtrickCrsEnv = &vspenvGame->course;
    vnmtrickCharEnv = &vspenvGame->character[0];
    vnmtrickModeEnv = &vspenvGame->mode;
    vnmtrickLang = &vspenvGame->language;
}

void nmtrickInitInfo(VnmtrickInfo* info) {
    signed int i; // r16

    for (i = 0; i < 32; i++) {
        info->que[i].type = 0;
        info->que[i].sp_type = 0;
        info->que[i].num = -1;
        info->que[i].link = -1;
        info->que[i].jump = -1;
        info->que[i].fakie = 0;
        info->que[i].late = 0;
        info->que[i].disaster = 0;
        info->que[i].spin.cab = 0;
        info->que[i].spin.rewind = 0;
        info->que[i].spin.value = 0;
        info->que[i].spin.first = 0;
        info->que[i].col.state = 0;
        info->que[i].col.cnt = 0;
        info->que[i].col.land = 0;
        info->que[i].col.flight = 0;
    }
    info->land = 0;
    info->flight = 0;
    info->fakie = 0;
    info->entry_id = 0;
    info->spin_id = 0;
    info->omit_id = 0;
    info->link_id = 0;
}

void nmtrickInitInfo2(signed int id) {
    signed int i; // r16

    for (i = 0; i < 32; i++) {
        vnmtrickInfo[id].que[i].type = 0;
        vnmtrickInfo[id].que[i].sp_type = 0;
        vnmtrickInfo[id].que[i].num = -1;
        vnmtrickInfo[id].que[i].link = -1;
        vnmtrickInfo[id].que[i].jump = -1;
        vnmtrickInfo[id].que[i].fakie = 0;
        vnmtrickInfo[id].que[i].late = 0;
        vnmtrickInfo[id].que[i].disaster = 0;
        vnmtrickInfo[id].que[i].spin.cab = 0;
        vnmtrickInfo[id].que[i].spin.rewind = 0;
        vnmtrickInfo[id].que[i].spin.value = 0;
        vnmtrickInfo[id].que[i].spin.first = 0;
        vnmtrickInfo[id].que[i].col.state = 0;
        vnmtrickInfo[id].que[i].col.cnt = 0;
        vnmtrickInfo[id].que[i].col.land = 0;
        vnmtrickInfo[id].que[i].col.flight = 0;
    }
    vnmtrickInfo[id].land = 0;
    vnmtrickInfo[id].flight = 0;
    vnmtrickInfo[id].fakie = 0;
    vnmtrickInfo[id].entry_id = 0;
    vnmtrickInfo[id].spin_id = 0;
    vnmtrickInfo[id].omit_id = 0;
    vnmtrickInfo[id].link_id = 0;
}

void nmtrickInitList(List* list) {
    signed int i; // r16
    for (i = 0; i < 16; i++) {
        list->word[i].id = 0;
        list->word[i].value = 0xFF;
    }
    list->length = 0.0f;
}

void nmtrickInitFig() {
    signed int i; // r16
    vnmtrickCrsEnv = 0;
    vnmtrickCharEnv = 0;
    vnmtrickModeEnv = 0;
    vnmtrickLang = 0;
    for (i = 0; i < 2; i++) {
        nmtrickInitInfo(&vnmtrickInfo[i]);
    }
}

void nmtrickSetLand(signed int id, signed int type) {
    signed int i; // r16

    if ((type != vnmtrickInfo[id].land) && type != 0) {
        vnmtrickInfo[id].land = type;
        for (i = 0; i < (vnmtrickInfo[id].entry_id); i++) {
            if ((vnmtrickInfo[id].link_id) == vnmtrickInfo[id].que[i].link) {
                vnmtrickInfo[id].que[i].col.state = 1;
                vnmtrickInfo[id].que[i].col.cnt = 0;
                vnmtrickInfo[id].que[i].col.land = vnmtrickInfo[id].land;
            }
        }
        if (((vnmtrickInfo[id].que[i].jump >= 0) || (vnmtrickInfo[id].que[i].spin.value > 0)) && (vnmtrickInfo[id].que[i].type == 0) && ((vnmtrickInfo[id].link_id) == vnmtrickInfo[id].que[i].link)) {
            vnmtrickInfo[id].que[i].col.state = 1;
            vnmtrickInfo[id].que[i].col.cnt = 0;
            vnmtrickInfo[id].que[i].col.land = vnmtrickInfo[id].land;
        }
        nmdispRenewTrick(id);
    }
}

void nmtrickSetFlight(signed int id /* 0x20(r29) */, signed int flag /* 0x30(r29) */) {
    signed int i; // r16

    vnmtrickInfo[id].flight = flag;
    if (flag == 1) {
        for (i = 0; i < vnmtrickInfo[id].entry_id; i++) {
            if ((vnmtrickInfo[id].link_id) == vnmtrickInfo[id].que[i].link) {
                vnmtrickInfo[id].que[i].col.state = 1;
                vnmtrickInfo[id].que[i].col.cnt = 0;
                vnmtrickInfo[id].que[i].col.flight = 1;
            }
        }
        if ((vnmtrickInfo[id].que[i].jump >= 0 || vnmtrickInfo[id].que[i].spin.value > 0)
            && vnmtrickInfo[id].que[i].type == 0
            && vnmtrickInfo[id].link_id == vnmtrickInfo[id].que[i].link
        ) {
            vnmtrickInfo[id].que[i].col.state = 1;
            vnmtrickInfo[id].que[i].col.cnt = 0;
            vnmtrickInfo[id].que[i].col.flight = 1;
        }
        nmdispRenewTrick(id);
    }
}

void nmtrickSetFakie(signed int id, signed int flag) {
    vnmtrickInfo[id].fakie = flag;
}

void nmtrickSetJump(signed int id, signed int num) {
    if (vnmtrickInfo[id].entry_id == 0x20) {
        nmtrickDelInfo(id);
    }
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].jump = num;
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].fakie = vnmtrickInfo[id].fakie;
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].link = vnmtrickInfo[id].link_id;
    nmdispRenewTrick(id);
}

void nmtrickSetTrick(signed int id, signed int type, signed int num, signed int unused1) {
    signed int i; // r16
    signed int sp_type; // r17

    if (type == 8) {
        sp_type = nmtrickSetSpType(num);
    } else {
        sp_type = 0;
    }
    switch (type) {
    case 3:
    case 4:
    case 5:
    case 9:
        if ((vnmtrickInfo[id].entry_id < 0x20) && (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].spin.value > 0) && (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].type == 0)) {
            vnmtrickInfo[id].entry_id++;
            vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
        }
        break;
    case 7:
        switch (vspRider[id]->ctrl.act.sliding_state) {
        case essGrind:
        case essManual:
        case essPlant:
            if ((vnmtrickInfo[id].entry_id < 0x20) && (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].spin.value > 0) && (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].type == 0)) {
                vnmtrickInfo[id].entry_id++;
                vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
            }
            break;
        }
        break;
    case 8:
        switch (sp_type) {
        case 3:
        case 4:
        case 5:
            if ((vnmtrickInfo[id].entry_id < 0x20) && (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].spin.value > 0) && (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].type == 0)) {
                vnmtrickInfo[id].entry_id++;
                vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
            }
            break;
        }
        break;
    }
    switch (type) {
    case 3:
    case 4:
    case 5:
    case 9:
        if (vnmtrickInfo[id].entry_id > 0) {
            vnmtrickInfo[id].link_id++;
            if (vnmtrickInfo[id].link_id > 0x40) {
                vnmtrickInfo[id].link_id = 1;
            }
        }
        break;
    case 7:
        switch (vspRider[id]->ctrl.act.sliding_state) {
        case essGrind:
        case essManual:
        case essPlant:
            if (vnmtrickInfo[id].entry_id > 0) {
                vnmtrickInfo[id].link_id++;
                if (vnmtrickInfo[id].link_id > 0x40) {
                    vnmtrickInfo[id].link_id = 1;
                }
            }
            break;
        }
        break;
    case 8:
        switch (sp_type) {
        case 3:
        case 4:
        case 5:
            if (vnmtrickInfo[id].entry_id > 0) {
                vnmtrickInfo[id].link_id++;
                if (vnmtrickInfo[id].link_id > 0x40) {
                    vnmtrickInfo[id].link_id = 1;
                }
            }
            break;
        }
        break;
    }
    if (vnmtrickInfo[id].entry_id == 0x20) {
        nmtrickDelInfo(id);
    }
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].type = type;
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].sp_type = sp_type;
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].num = num;
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].fakie = vnmtrickInfo[id].fakie;
    vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].link = vnmtrickInfo[id].link_id;
    switch (type) {
    case 3:
        vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].disaster = 0;
        break;
    case 8:
        switch (sp_type) {
        case 3:
            vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].disaster = 0;
            break;
        }
        break;
    }
    if ((vnmtrickInfo[id].entry_id > 0) && (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].link == vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id - 1].link)) {
        vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].col.state = 1;
        vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].col.cnt = 0;
        vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].col.flight = vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id - 1].col.flight;
        vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id].col.land = vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id - 1].col.land;
        for (i = 0; i < vnmtrickInfo[id].entry_id; i++) {
            if (vnmtrickInfo[id].link_id == vnmtrickInfo[id].que[i].link) {
                vnmtrickInfo[id].que[i].col.state = 1;
                vnmtrickInfo[id].que[i].col.cnt = 0;
            }
        }
    }
    vnmtrickInfo[id].entry_id++;
    nmdispRenewTrick(id);
    switch (type) {
    case 3:
    case 4:
    case 5:
    case 9:
        vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
        if (vnmtrickInfo[id].entry_id > 0) {
            vnmtrickInfo[id].link_id++;
            if (vnmtrickInfo[id].link_id > 0x40) {
                vnmtrickInfo[id].link_id = 1;
            }
        }
        break;
    case 7:
        switch (vspRider[id]->ctrl.act.sliding_state) {
        case essGrind:
        case essManual:
        case essPlant:
            vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
            if (vnmtrickInfo[id].entry_id > 0) {
                vnmtrickInfo[id].link_id++;
                if (vnmtrickInfo[id].link_id > 0x40) {
                    vnmtrickInfo[id].link_id = 1;
                }
            }
            break;
        }
        break;
    case 8:
        switch (sp_type) {
        case 3:
        case 4:
        case 5:
            vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
            if (vnmtrickInfo[id].entry_id > 0) {
                vnmtrickInfo[id].link_id++;
                if (vnmtrickInfo[id].link_id > 0x40) {
                    vnmtrickInfo[id].link_id = 1;
                }
            }
            break;
        }
        break;
    }
    switch (type) {
    case 7:
        nmvcPlay(id + 0x1B, 5, 4);
        break;
    case 8:
        nmvcPlay(id + 0x1B, 5, 6);
        break;
    }
}

void nmtrickSetSpin(signed int id, signed int pipe, signed int rewind, signed int spin) {
    signed int i; // r16

    if (vnmtrickInfo[id].spin_id >= 0x20) {
        nmtrickDelInfo(id);
    } else {
        switch (vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].type) {
        case 3:
        case 4:
        case 5:
        case 9:
            if (vnmtrickInfo[id].entry_id == 0x20) {
                nmtrickDelInfo(id);
            }
            vnmtrickInfo[id].spin_id = 0x20;
            i = 0;
            while (1) {
                if (vnmtrickInfo[id].entry_id < i) {
                    vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
                }
                if (vnmtrickInfo[id].spin_id < 0x20) {
                    break;
                }
                switch (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id - i].type) {
                case 3:
                case 4:
                case 5:
                case 9:
                    vnmtrickInfo[id].spin_id = ((signed char)vnmtrickInfo[id].entry_id - i) + 1;
                    break;
                default:
                    i++;
                    break;
                }
            }
            break;
        case 8:
            switch (vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].sp_type) {
            case 3:
            case 4:
            case 5:
                if (vnmtrickInfo[id].entry_id == 0x20) {
                    nmtrickDelInfo(id);
                }
                vnmtrickInfo[id].spin_id = 0x20;
                i = 0;
                while (1) {
                    if (vnmtrickInfo[id].entry_id < i) {
                        vnmtrickInfo[id].spin_id = vnmtrickInfo[id].entry_id;
                    }
                    if (vnmtrickInfo[id].spin_id < 0x20) {
                        break;
                    }
                    switch (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id - i].type) {
                    case 3:
                    case 4:
                    case 5:
                    case 9:
                        vnmtrickInfo[id].spin_id = ((signed char)vnmtrickInfo[id].entry_id - i) + 1;
                        break;
                    case 8:
                        switch (vnmtrickInfo[id].que[vnmtrickInfo[id].entry_id - i].sp_type) {
                        case 3:
                        case 4:
                        case 5:
                            vnmtrickInfo[id].spin_id = ((signed char)vnmtrickInfo[id].entry_id - i) + 1;
                            break;
                        }
                    default:
                        i++;
                        break;
                    }
                }
                break;
            }
            break;
        }
    }
    if (vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.first == 0) {
        vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.value = spin;
        if ((pipe == 1) && (vnmtrickInfo[id].fakie == 1)) {
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.cab = 1;
        } else {
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.cab = 0;
        }
        vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.first = 1;
        vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].fakie = vnmtrickInfo[id].fakie;
        vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].link = vnmtrickInfo[id].link_id;
        if (vnmtrickInfo[id].entry_id > 0) {
            for (i = 0; i < vnmtrickInfo[id].entry_id; i++) {
                if (vnmtrickInfo[id].link_id == vnmtrickInfo[id].que[i].link) {
                    vnmtrickInfo[id].que[i].col.state = 1;
                    vnmtrickInfo[id].que[i].col.cnt = 0;
                }
            }
        }
        nmdispRenewTrick(id);
    } else if (rewind == 1) {
        if (vnmtrickInfo[id].entry_id == vnmtrickInfo[id].spin_id) {
            vnmtrickInfo[id].entry_id++;
            vnmtrickInfo[id].spin_id++;
            if (vnmtrickInfo[id].entry_id == 0x20) {
                nmtrickDelInfo(id);
            }
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.rewind = 1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.cab = 0;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.value = 1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.first = 1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].fakie = vnmtrickInfo[id].fakie;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].jump = -1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].link = vnmtrickInfo[id].link_id;
        } else {
            if (vnmtrickInfo[id].entry_id == 0x20) {
                nmtrickDelInfo(id);
            }
            for (i = vnmtrickInfo[id].entry_id; i > vnmtrickInfo[id].spin_id; i--) {
                memcpy(&vnmtrickInfo[id].que[i], &vnmtrickInfo[id].que[i - 1], 0x40);
            }
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].type = 0;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].sp_type = 0;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].num = 0;
            vnmtrickInfo[id].spin_id++;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.rewind = 1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.cab = 0;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.value = 1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.first = 1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].jump = -1;
            vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].link = vnmtrickInfo[id].link_id;
            vnmtrickInfo[id].entry_id++;
        }
        nmdispRenewTrick(id);
    } else {
        vnmtrickInfo[id].que[vnmtrickInfo[id].spin_id].spin.value = spin;
    }
}

void nmtrickSetInfo(signed int id, VnmtrickInfo* info) {
    nmtrickInitInfo2(id);
    memcpy(&vnmtrickInfo[id], info, 0x810);
}


void nmtrickGetInfo(signed int id, VnmtrickInfo* info) {
    memcpy(info, &vnmtrickInfo[id], 0x810);
}

signed int nmtrickMakeList(signed int id, Info* info, List* list) {
    signed int j; // r16
    signed int line_no; // r17
    signed int word_no; // r18
    signed int i; // r19
    signed int search; // r20
    char str_tmp[128]; // 0x60(r29)
    float tmp; // 0xE8(r29)
    float str_len; // 0xEC(r29)

    line_no = 0;
    i = vnmtrickInfo[id].omit_id;
    while (1) {
        if (line_no != 0) {
            break;
        }
        tmp = 0.0f;
        str_tmp[0] = 0;
        str_len = 0.0f;
        line_no = 0;
        word_no = 0;
        search = 0;
        for (j = 0; j < info->line; j++) {
            nmtrickInitList(&list[j]);
        }
        if (vnmtrickInfo[id].land != 0) {
            ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmtrickLang][vnmtrickInfo[id].land - 1]);
            str_len = nmfontGetPackStrFLen(str_tmp, info->font, 0);
            list[line_no].word[word_no].id = 1;
            list[line_no].word[word_no].value = vnmtrickInfo[id].land;
            list[line_no].length = str_len;
            word_no++;
        }
        if (vnmtrickInfo[id].flight == 1) {
            if (str_len > 0.0f) {
                ulstdSprintf(str_tmp, " %s", vnmtblTrickAcce[*vnmtrickLang][2]);
            } else {
                ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmtrickLang][2]);
            }
            str_len += nmfontGetPackStrFLen(str_tmp, info->font, 0);
            if (str_len > info->width) {
                line_no++;
                word_no = 0;
                str_len = nmfontGetPackStrFLen(str_tmp, info->font, 0);
            }
            list[line_no].word[word_no].id = 2;
            list[line_no].length = str_len;
            word_no++;
        }
        if (i > 0) {
            if (str_len > 0.0f) {
                ulstdSprintf(str_tmp, " ...");
            } else {
                ulstdSprintf(str_tmp, "...");
            }
            str_len += nmfontGetPackStrFLen(str_tmp, info->font, 0);
            if (str_len > info->width) {
                list[line_no].word[word_no].id = 6;
                line_no++;
                word_no = 0;
                ulstdSprintf(str_tmp, "...");
                str_len = nmfontGetPackStrFLen(str_tmp, info->font, 0);
            }
            list[line_no].word[word_no].id = 5;
            list[line_no].length = str_len;
            word_no++;
        }
        j = 0;
        tmp = 0.0f;
        while (1) {
            if ((j == 0x20) || ((vnmtrickInfo[id].que[j].type == 0) && (vnmtrickInfo[id].que[j].spin.value == 0) && (vnmtrickInfo[id].que[j].jump < 0))) {
                vnmtrickInfo[id].omit_id = i;
                break;
            }
            search++;
            if (search > i) {
                if (str_len > 0.0f) {
                    ulstdSprintf(str_tmp, " ");
                    tmp = nmfontGetPackStrFLen(str_tmp, info->font, 0);
                }
                if (vnmtrickInfo[id].que[j].jump >= 0) {
                    if (vnmtrickInfo[id].que[j].spin.value > 0) {
                        ulstdSprintf(str_tmp, "%s + ", vsptblTrickName[vnmtrickInfo[id].que[j].jump]);
                    } else if (vnmtrickInfo[id].que[j].type == 0) {
                        ulstdSprintf(str_tmp, "%s", vsptblTrickName[vnmtrickInfo[id].que[j].jump]);
                    } else {
                        ulstdSprintf(str_tmp, "%s + ", vsptblTrickName[vnmtrickInfo[id].que[j].jump]);
                    }
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                }
                if (vnmtrickInfo[id].que[j].spin.value > 0) {
                    if ((vnmtrickInfo[id].que[j].spin.cab == 1) && (vnmtrickInfo[id].que[j].spin.rewind == 0) && (vnmtrickInfo[id].que[j].spin.value > 1)) {
                        ulstdSprintf(str_tmp, "%s ", vnmtblTrickAcce[*vnmtrickLang][6]);
                        tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    }
                    ulstdSprintf(str_tmp, "%d", vnmtrickInfo[id].que[j].spin.value * 180);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    if (vnmtrickInfo[id].que[j].spin.rewind == 1) {
                        ulstdSprintf(str_tmp, " %s", vnmtblTrickAcce[*vnmtrickLang][4]);
                        tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    }
                    if (vnmtrickInfo[id].que[j].type != 0) {
                        ulstdSprintf(str_tmp, " ");
                        tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    }
                }
                if (vnmtrickInfo[id].que[j].late == 1) {
                    ulstdSprintf(str_tmp, "%s ", vnmtblTrickAcce[*vnmtrickLang][5]);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                }
                switch (vnmtrickInfo[id].que[j].type) {
                case 0:
                    break;
                case 7:
                    ulstdSprintf(str_tmp, "%s", vsptblGapList[vnmtrickCrsEnv->no][vnmtrickInfo[id].que[j].num]);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    break;
                default:
                    if (vnmtrickInfo[id].que[j].disaster == 1) {
                        ulstdSprintf(str_tmp, "%s ", vsptblTrickName[0x85]);
                        tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    }
                    ulstdSprintf(str_tmp, "%s", vsptblTrickName[vnmtrickInfo[id].que[j].num]);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    break;
                }
                if ((j < 0x1F) && ((vnmtrickInfo[id].que[j + 1].type != 0) || (vnmtrickInfo[id].que[j + 1].spin.value != 0) || (vnmtrickInfo[id].que[j + 1].jump >= 0))) {
                    if (vnmtrickInfo[id].que[j + 1].spin.rewind == 1) {
                        ulstdSprintf(str_tmp, " -");
                    } else {
                        ulstdSprintf(str_tmp, " +");
                    }
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                }
                if ((str_len + tmp) <= info->width) {
                    str_len += tmp;
                } else if (line_no == (info->line - 1)) {
                    line_no = -1;
                    break;
                } else {
                    list[line_no].word[word_no].id = 6;
                    line_no++;
                    word_no = 0;
                    if (str_len > 0.0f) {
                        ulstdSprintf(str_tmp, " ");
                        str_len = tmp - nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    } else {
                        str_len = tmp;
                    }
                }
                list[line_no].word[word_no].id = 4;
                list[line_no].word[word_no].value = j;
                list[line_no].length = str_len;
                word_no++;
            }
            j++;
        }
        if (line_no < 0) {
            line_no = 0;
            i++;
        } else {
            line_no = line_no + 1;
        }
    }
    return line_no;
}

void nmtrickMakeStr(signed int id, Info* info, List* list) {
    signed int que_no; // r16
    signed int i; // r17
    signed int j; // r18
    char str_tmp[128]; // 0x40(r29)
    char str[128]; // 0xC0(r29)
    float tmp; // 0x14C(r29)

    for (i = 0; ; i++) {
        if (i == info->line) {
            break;
        }
        if (list[i].word[0].id == 0) {
            break;
        }
        j = 0;
        tmp = 0.0f;
        str[0] = 0;
        for (; ; j++) {
            if ((j == 0x10) || (list[i].word[j].id == 0) || (list[i].word[j].id == 6)) {
                if (str != 0) {
                    nmdispSetTrickFall(id, str, i);
                }
                break;
            }
            if (j > 0) {
                ulstdSprintf(str_tmp, " ");
                strcat(str, str_tmp);
            }
            switch (list[i].word[j].id) {
            case 1:
                ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmtrickLang][list[i].word[j].value - 1]);
                strcat(str, str_tmp);
                break;
            case 2:
                ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmtrickLang][2]);
                strcat(str, str_tmp);
                break;
            case 3:
                ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmtrickLang][3]);
                strcat(str, str_tmp);
                break;
            case 4:
                que_no = list[i].word[j].value;
                if (vnmtrickInfo[id].que[que_no].jump >= 0) {
                    if (vnmtrickInfo[id].que[que_no].spin.value > 0) {
                        ulstdSprintf(str_tmp, "%s + ", vsptblTrickName[vnmtrickInfo[id].que[que_no].jump]);
                    } else if (vnmtrickInfo[id].que[que_no].type == 0) {
                        ulstdSprintf(str_tmp, "%s", vsptblTrickName[vnmtrickInfo[id].que[que_no].jump]);
                    } else {
                        ulstdSprintf(str_tmp, "%s + ", vsptblTrickName[vnmtrickInfo[id].que[que_no].jump]);
                    }
                    strcat(str, str_tmp);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                }
                if (vnmtrickInfo[id].que[que_no].spin.value > 0) {
                    if (vnmtrickInfo[id].que[que_no].spin.rewind == 1) {
                        ulstdSprintf(str_tmp, "%d %s", vnmtrickInfo[id].que[que_no].spin.value * 180, vnmtblTrickAcce[*vnmtrickLang][4]);
                    } else if ((vnmtrickInfo[id].que[que_no].spin.cab == 1) && (vnmtrickInfo[id].que[que_no].spin.value > 1)) {
                        ulstdSprintf(str_tmp, "%s %d", vnmtblTrickAcce[*vnmtrickLang][6], vnmtrickInfo[id].que[que_no].spin.value * 180);
                    } else {
                        ulstdSprintf(str_tmp, "%d", vnmtrickInfo[id].que[que_no].spin.value * 180);
                    }
                    strcat(str, str_tmp);
                    if (vnmtrickInfo[id].que[que_no].type != 0) {
                        ulstdSprintf(str_tmp, " ");
                        strcat(str, str_tmp);
                    }
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                }
                if (vnmtrickInfo[id].que[que_no].late == 1) {
                    ulstdSprintf(str_tmp, "%s ", vnmtblTrickAcce[*vnmtrickLang][5]);
                    strcat(str, str_tmp);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                }
                switch (vnmtrickInfo[id].que[que_no].type) {
                case 0:
                    break;
                case 7:
                    ulstdSprintf(str_tmp, "%s", vsptblGapList[vnmtrickCrsEnv->no][vnmtrickInfo[id].que[que_no].num]);
                    strcat(str, str_tmp);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    break;
                default:
                    if (vnmtrickInfo[id].que[que_no].disaster == 1) {
                        ulstdSprintf(str_tmp, "%s ", vsptblTrickName[0x85]);
                        strcat(str, str_tmp);
                        tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    }
                    ulstdSprintf(str_tmp, "%s", vsptblTrickName[vnmtrickInfo[id].que[que_no].num]);
                    strcat(str, str_tmp);
                    tmp += nmfontGetPackStrFLen(str_tmp, info->font, 0);
                    break;
                }
                if (j < 0xF) {
                    if ((list[i].word[j + 1].id != 0) && (tmp > 0.0f)) {
                        if (list[i].word[j + 1].id == 6) {
                            que_no = list[i + 1].word[0].value;
                        } else {
                            que_no = list[i].word[j + 1].value;
                        }
                        if (vnmtrickInfo[id].que[que_no].spin.rewind == 1) {
                            ulstdSprintf(str_tmp, " -");
                        } else {
                            ulstdSprintf(str_tmp, " +");
                        }
                        strcat(str, str_tmp);
                    }
                } else if ((i + 1) != info->line) {
                    if ((list[i + 1].word[0].id != 0) && (tmp > 0.0f)) {
                        que_no = list[i + 1].word[0].value;
                        if (vnmtrickInfo[id].que[que_no].spin.rewind == 1) {
                            ulstdSprintf(str_tmp, " -");
                        } else {
                            ulstdSprintf(str_tmp, " +");
                        }
                        strcat(str, str_tmp);
                    }
                }
                break;
            case 5:
                ulstdSprintf(str_tmp, "...");
                strcat(str, str_tmp);
                break;
            }
        }
    }
}

signed int nmtrickSetSpType(signed int num) {
    signed int type; // r16

    switch (num) {
    case 0x54:
    case 0x57:
    case 0x5B:
    case 0x63:
    case 0x65:
    case 0x66:
        type = 1;
        break;
    case 0x56:
    case 0x59:
    case 0x5A:
    case 0x5D:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x64:
    case 0x6A:
        type = 2;
        break;
    case 0x58:
    case 0x5C:
    case 0x5E:
    case 0x67:
    case 0x6B:
        type = 3;
        break;
    case 0x55:
    case 0x68:
        type = 4;
        break;
    case 0x69:
        type = 5;
        break;
    default:
        type = 1;
    }
    return type;
}


void nmtrickDelInfo(signed int id) {
    // Size: 0x10, DWARF: 0x221233
    signed int i; // r16
    Spin spin; // 0x20(r29)

    if (vnmtrickInfo[id].que[0].link == vnmtrickInfo[id].que[1].link) {
        memcpy(&spin, &vnmtrickInfo[id].que[0].spin, 0x10);
        for (i = 0; i < 31; i++) {
            memcpy(&vnmtrickInfo[id].que[i], &vnmtrickInfo[id].que[i+1], 0x40);
            if ((i + 1) == (vnmtrickInfo[id].spin_id)) {
                vnmtrickInfo[id].spin_id = i;
            }
        }
        memcpy(&vnmtrickInfo[id].que[0].spin, &spin, 0x10);
    } else {
        for (i = 0; i < 31; i++) {
            memcpy(&vnmtrickInfo[id].que[i], &vnmtrickInfo[id].que[i+1], 0x40);
            if ((i + 1) == (vnmtrickInfo[id].spin_id)) {
                vnmtrickInfo[id].spin_id = i;
            }
        }
    }
    vnmtrickInfo[id].que[i].type = 0;
    vnmtrickInfo[id].que[i].sp_type = 0;
    vnmtrickInfo[id].que[i].num = -1;
    vnmtrickInfo[id].que[i].link = -1;
    vnmtrickInfo[id].que[i].jump = -1;
    vnmtrickInfo[id].que[i].fakie = 0;
    vnmtrickInfo[id].que[i].late = 0;
    vnmtrickInfo[id].que[i].disaster = 0;
    vnmtrickInfo[id].que[i].spin.cab = 0;
    vnmtrickInfo[id].que[i].spin.rewind = 0;
    vnmtrickInfo[id].que[i].spin.value = 0;
    vnmtrickInfo[id].que[i].spin.first = 0;
    vnmtrickInfo[id].entry_id = i;
    if (0x1F < vnmtrickInfo[id].spin_id) {
        vnmtrickInfo[id].spin_id = i;
    }
    if ((vnmtrickInfo[id].omit_id) > 0) {
        vnmtrickInfo[id].omit_id -= 1;
    }
}
