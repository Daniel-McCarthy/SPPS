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

#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to
                      // float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division
                          // by variables that risk div by 0.
#pragma fast_fptosi on    // Trunc will be used instead of fptosi

typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned(16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned(16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));


typedef struct Cheats {
  signed int kids;        // Offset: 0x0, DWARF: 0x7DADD
  signed int always_sp;   // Offset: 0x4, DWARF: 0x7DAFE
  signed int perfect_b;   // Offset: 0x8, DWARF: 0x7DB24
  signed int super_spin;  // Offset: 0xC, DWARF: 0x7DB4A
  signed int half_g;      // Offset: 0x10, DWARF: 0x7DB71
  signed int fast_motion; // Offset: 0x14, DWARF: 0x7DB94
  signed int super_speed; // Offset: 0x18, DWARF: 0x7DBBC
  signed int big_head;    // Offset: 0x1C, DWARF: 0x7DBE4
  signed int metallic;    // Offset: 0x20, DWARF: 0x7DC09
  signed int mirror;      // Offset: 0x24, DWARF: 0x7DC2E
  signed int replay_view; // Offset: 0x28, DWARF: 0x7DC51
  signed int partition;   // Offset: 0x2C, DWARF: 0x7DC79
} Cheats;

// Size: 0x28, DWARF: 0x7DEB2
typedef struct Param {
  signed int quickness;     // Offset: 0x0, DWARF: 0x7DECE
  signed int jump_power;    // Offset: 0x4, DWARF: 0x7DEF4
  signed int turning;       // Offset: 0x8, DWARF: 0x7DF1B
  signed int sit_turning;   // Offset: 0xC, DWARF: 0x7DF3F
  signed int quick_turning; // Offset: 0x10, DWARF: 0x7DF67
  signed int max_speed;     // Offset: 0x14, DWARF: 0x7DF91
  signed int cmn_max_speed; // Offset: 0x18, DWARF: 0x7DFB7
  signed int spin;          // Offset: 0x1C, DWARF: 0x7DFE1
  signed int grind;         // Offset: 0x20, DWARF: 0x7E002
  signed int landing;       // Offset: 0x24, DWARF: 0x7E024
} Param;

// Size: 0x24, DWARF: 0x7C294
typedef struct Param2 // (Includes additional stats not able to be set by
                      // player, like power/quickness)
{
  signed int ollie;          // Offset: 0x0, DWARF: 0x7C2B0
  signed int spin;           // Offset: 0x4, DWARF: 0x7C2D2
  signed int speed;          // Offset: 0x8, DWARF: 0x7C2F3
  signed int landing;        // Offset: 0xC, DWARF: 0x7C315
  signed int landing_switch; // Offset: 0x10, DWARF: 0x7C339
  signed int balance;        // Offset: 0x14, DWARF: 0x7C364
  signed int quickness;      // Offset: 0x18, DWARF: 0x7C388
  signed int power;          // Offset: 0x1C, DWARF: 0x7C3AE
  signed int turning;        // Offset: 0x20, DWARF: 0x7C3D0
} Param2;

// Size: 0x10, DWARF: 0x7A1DB, 0x16DA24
typedef struct Board_Param {
  signed int speed;     // Offset: 0x0, DWARF: 0x7A1F7
  signed int stability; // Offset: 0x4, DWARF: 0x7A219
  signed int balance;   // Offset: 0x8, DWARF: 0x7A23F
  signed int turning;   // Offset: 0xC, DWARF: 0x7A263
} Board_Param;

// Size: 0x1C, DWARF: 0x7C601, 0x16D2B9
typedef struct Stats {
  signed int ollie;     // Offset: 0x0, DWARF: 0x7C61D
  signed int spin;      // Offset: 0x4, DWARF: 0x7C63F
  signed int speed;     // Offset: 0x8, DWARF: 0x7C660
  signed int landing;   // Offset: 0xC, DWARF: 0x7C682
  signed int balance;   // Offset: 0x10, DWARF: 0x7C6A6
  signed int stability; // Offset: 0x14, DWARF: 0x7C6CA
  signed int stance;    // Offset: 0x18, DWARF: 0x7C6F0
} Stats;

// Size: 0x14, DWARF: 0x7C447
typedef struct Balance {
  float balance;       // Offset: 0x0, DWARF: 0x7C463
  float lean;          // Offset: 0x4, DWARF: 0x7C487
  float lean_dir;      // Offset: 0x8, DWARF: 0x7C4A8
  signed int released; // Offset: 0xC, DWARF: 0x7C4CD
  signed int cnt_free; // Offset: 0x10, DWARF: 0x7C4F2
} Balance;

// Size: 0x30, DWARF: 0x79C3C, 0x1737CD
typedef struct Plane {
  float cross[4];           // Offset: 0x0, DWARF: 0x79C58
  float normal[4];          // Offset: 0x10, DWARF: 0x79C7C
  unsigned short material;  // Offset: 0x20, DWARF: 0x79CA1
  unsigned short attribute; // Offset: 0x22, DWARF: 0x79CC6
  signed short almighty1;   // Offset: 0x24, DWARF: 0x79CEC
  signed short almighty2;   // Offset: 0x26, DWARF: 0x79D12
  signed short almighty3;   // Offset: 0x28, DWARF: 0x79D38
  signed short slidable;    // Offset: 0x2A, DWARF: 0x79D5E
  signed int available;     // Offset: 0x2C, DWARF: 0x79D83
} Plane;

// Size: 0x60, DWARF: 0x75E44
typedef struct Col {
  float normal[4];       // Offset: 0x0, DWARF: 0x75E5F
  float point[4];        // Offset: 0x10, DWARF: 0x75E84
  sceVu0FVECTOR *vertex; // Offset: 0x20, DWARF: 0x75EA8 // float*[4]
  unsigned int attr;     // Offset: 0x24, DWARF: 0x75ED0
  signed int nvertex;    // Offset: 0x28, DWARF: 0x75EF1
  signed int no;         // Offset: 0x2C, DWARF: 0x75F15
  float len;             // Offset: 0x30, DWARF: 0x75F34
  signed int rail_no;    // Offset: 0x34, DWARF: 0x75F54
  signed int obj_no;     // Offset: 0x38, DWARF: 0x75F78
  signed int obj_attr;   // Offset: 0x3C, DWARF: 0x75F9B
  signed int obj_type;   // Offset: 0x40, DWARF: 0x75FC0
  signed int res[4];     // Offset: 0x44, DWARF: 0x75FE5
  char padding[12];      // Not normally in the struct, but pads to make it the
                         // expected size.
} Col;

// Size: 0x60, DWARF: 0x79DD3, 0x16E55B
typedef struct Pos {
  float pos[4];        // Offset: 0x0, DWARF: 0x79DEF
  float cross[4];      // Offset: 0x10, DWARF: 0x79E11
  float normal[4];     // Offset: 0x20, DWARF: 0x79E35
  signed int hit;      // Offset: 0x30, DWARF: 0x79E5A
  signed int material; // Offset: 0x34, DWARF: 0x79E7A
  signed int halfpipe; // Offset: 0x38, DWARF: 0x79E9F
  signed int ripping;  // Offset: 0x3C, DWARF: 0x79EC4
  signed int bonk;     // Offset: 0x40, DWARF: 0x79EE8
  signed int low_g;    // Offset: 0x44, DWARF: 0x79F09
  signed int no;       // Offset: 0x48, DWARF: 0x79F2B
  float len2;          // Offset: 0x4C, DWARF: 0x79F4A
  signed int type;     // Offset: 0x50, DWARF: 0x79F6B
  char padding[12];    // Not normally part of the struct, but pads a missing 8
                       // bytes.
} Pos;

typedef enum Sliding_State {
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

typedef enum Tumble_Type {
  ettNormal,
  ettTotter,
  ettTumbleS,
  ettTumbleL,
  ettTumbleF,
  ettTumbleN
} Tumble_Type; // Offset: 0x2A0, DWARF: 0x168A79

typedef enum Tumble_Way {
  etwLeft,
  etwRight,
  etwFoward,
  etwBack
} Tumble_Way; // Offset: 0x2A4, DWARF: 0x168AA3

typedef enum ESP_Spin_Way {
  espNoSpin,
  espTurnLeft,
  espTurnRight,
  espTurnLeftFast,
  espTurnRightFast
} ESP_Spin_Way; // Offset: 0x18, DWARF: 0x16B1F5

typedef enum Acceleration_State {
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

typedef enum Jump_State {
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
typedef enum Stance_Change {
  escNoAction,
  escTurnLeft,
  escTurnRight
} Stance_Change; // Offset: 0x14, DWARF: 0x16B1C9

// DWARF: 0x16C19D
typedef enum Trick_Command {
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
typedef enum Key_Way {
  ekwNone,
  ekwLeft,
  ekwRight
} Key_Way; // Offset: 0x2C, DWARF: 0x16B2BC

// DWARF: 0x16C5FB
typedef enum Acceleration_Brake {
  eraNone,
  eraAccel,
  eraBrake,
  eraAccelLeft,
  eraAccelRight
} Acceleration_Brake; // Offset: 0x0, DWARF: 0x16EEC0

// DWARF: 0x16E4C8
typedef enum Jump_Strength {
  erjNone,
  erjWeak,
  erjMiddle,
  erjStrong,
  erjNollie,
  erjStart
} Jump_Strength; // Offset: 0x8, DWARF: 0x16EF0E

// DWARF: 0x16D3F3
typedef enum ERSC_Stance_Change {
  erscNone,
  erscTurnLeft,
  erscTurnRight
} ERSC_Stance_Change; // Offset: 0xC, DWARF: 0x16EF31

// DWARF: 0x16DAF8
typedef enum ERC_Command {
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
typedef enum Landing_Bonus {
  elbNormal,
  elbPerfect,
  elbSloppy
} Landing_Bonus; // Offset: 0x24, DWARF: 0x16CB5A

// DWARF: 0x16C76D
typedef enum ETS_Trick_State {
  etsNormal,
  etsFlip,
  etsManual,
  etsGrind,
  etsPlant,
  etsRevert
} ETS_Trick_State; // Offset: 0x5D4, DWARF: 0x169BF9

// DWARF: 0x16D779
typedef enum Trick_Link_State {
  elsNone,
  elsLinking,
  elsSuccess,
  elsFailure
} Trick_Link_State; // Offset: 0x5E0, DWARF: 0x169C72

// DWARF: 0x1C3C55
typedef enum FlowMode {
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
typedef enum Ripside { ersNoRip, ersLeft, ersRight } Ripside;

typedef enum Restart { ersNone, ersNormal, ersReplay } Restart;

// Size: 0x10, DWARF: 0x7A4D2
typedef struct Cmd {
  signed short type;         // Offset: 0x0, DWARF: 0x7A4EE
  char way1;                 // Offset: 0x2, DWARF: 0x7A50F
  char way2;                 // Offset: 0x3, DWARF: 0x7A530
  char way3;                 // Offset: 0x4, DWARF: 0x7A551
  char way4;                 // Offset: 0x5, DWARF: 0x7A572
  unsigned short fin_button; // Offset: 0x6, DWARF: 0x7A593
  char rev_button;           // Offset: 0x8, DWARF: 0x7A5BA
  char inp_fin_button;       // Offset: 0x9, DWARF: 0x7A5E1
  char left_count;           // Offset: 0xA, DWARF: 0x7A60C
  char fin_left_count;       // Offset: 0xB, DWARF: 0x7A633
  char step;                 // Offset: 0xC, DWARF: 0x7A65E
  char ok;                   // Offset: 0xD, DWARF: 0x7A67F
  char passtime;             // Offset: 0xE, DWARF: 0x7A69E
  char tmp;                  // Offset: 0xF, DWARF: 0x7A6C3
} Cmd;

// Size: 0x190, DWARF: 0x7F127
typedef struct Cam {
  float pre_speed[4];    // Offset: 0x0, DWARF: 0x7F143
  float now_speed[4];    // Offset: 0x10, DWARF: 0x7F16B
  float normal_speed[4]; // Offset: 0x20, DWARF: 0x7F193
  float rot[4];          // Offset: 0x30, DWARF: 0x7F1BE
  float pos_waist[4];    // Offset: 0x40, DWARF: 0x7F1E0
  float pos_disp[4];     // Offset: 0x50, DWARF: 0x7F208
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
  float max_height;               // Offset: 0x130, DWARF: 0x7F31F
  signed int cnt_onair;           // Offset: 0x134, DWARF: 0x7F346
  signed int cnt_turn;            // Offset: 0x138, DWARF: 0x7F36C
  float max_speed;                // Offset: 0x13C, DWARF: 0x7F391
  signed int hp_air;              // Offset: 0x140, DWARF: 0x7F3B7
  float splen_prejump;            // Offset: 0x144, DWARF: 0x7F3DA
  // DWARF: 0x7E931
  Tumble_Type tumble_type; // Offset: 0x148, DWARF: 0x7F404
  // DWARF: 0x7FF3C
  Tumble_Way tumble_way; // Offset: 0x14C, DWARF: 0x7F42E
  // DWARF: 0x7E931
  Tumble_Type trg_tumble_type;   // Offset: 0x150, DWARF: 0x7F457
  signed int trg_tumble_standup; // Offset: 0x154, DWARF: 0x7F485
  float grind_enter_ang;         // Offset: 0x158, DWARF: 0x7F4B4
  signed int trick_link;         // Offset: 0x15C, DWARF: 0x7F4E0
  signed int trg_start_endmot;   // Offset: 0x160, DWARF: 0x7F507
  signed int trg_recovered;      // Offset: 0x164, DWARF: 0x7F534
  signed int trg_hopup;          // Offset: 0x168, DWARF: 0x7F55E
  signed int trg_jumpup;         // Offset: 0x16C, DWARF: 0x7F584
  signed int trg_touch;          // Offset: 0x170, DWARF: 0x7F5AB
  signed int trg_boost;          // Offset: 0x174, DWARF: 0x7F5D1
  signed int bonk_goto;          // Offset: 0x178, DWARF: 0x7F5F7
  signed int trg_plant;          // Offset: 0x17C, DWARF: 0x7F61D
  signed int grind_goto;         // Offset: 0x180, DWARF: 0x7F643
} Cam;

// Size: 0x48, DWARF: 0x7C763
typedef struct Req {
  // DWARF: 0x80E2D
  Acceleration_Brake accel_brake; // Offset: 0x0, DWARF: 0x7C77F
  signed int sitting;             // Offset: 0x4, DWARF: 0x7C7A9
  // DWARF: 0x7BAC5
  Jump_Strength jump; // Offset: 0x8, DWARF: 0x7C7CD
  // DWARF: 0x81681
  ERSC_Stance_Change stance_change; // Offset: 0xC, DWARF: 0x7C7F0
  // DWARF: 0x821D6
  ERC_Command command;      // Offset: 0x10, DWARF: 0x7C81C
  signed int cmd_mot_id;    // Offset: 0x14, DWARF: 0x7C842
  signed int cmd_mot_nloop; // Offset: 0x18, DWARF: 0x7C869
  signed int cmd_trick_no;  // Offset: 0x1C, DWARF: 0x7C893
  signed int end_fall;      // Offset: 0x20, DWARF: 0x7C8BC
  signed int trick_no;      // Offset: 0x24, DWARF: 0x7C8E1
  signed int flip_no;       // Offset: 0x28, DWARF: 0x7C906
  signed int grind_no;      // Offset: 0x2C, DWARF: 0x7C92A
  signed int plant_no;      // Offset: 0x30, DWARF: 0x7C94F
  signed int bonk_no;       // Offset: 0x34, DWARF: 0x7C974
  signed int manual_no;     // Offset: 0x38, DWARF: 0x7C998
  signed int revert_no;     // Offset: 0x3C, DWARF: 0x7C9BE
  signed int jump_no;       // Offset: 0x40, DWARF: 0x7C9E4
  signed int sptrk_id;      // Offset: 0x44, DWARF: 0x7CA08
} Req;

// Size: 0x3C, DWARF: 0x7600B, 0x16B0EF
typedef struct Inp {
  signed int turn;       // Offset: 0x0, DWARF: 0x76026
  signed int turn_x;     // Offset: 0x4, DWARF: 0x76047
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
  Trick_Command command;    // Offset: 0x1C, DWARF: 0x76137
  signed int cmd_mot_id;    // Offset: 0x20, DWARF: 0x7615D
  signed int cmd_mot_nloop; // Offset: 0x24, DWARF: 0x76184
  signed int cmd_trick_no;  // Offset: 0x28, DWARF: 0x761AE
  // DWARF: 0x79055
  Key_Way keyway;             // Offset: 0x2C, DWARF: 0x761D7
  signed int tumble_speed_up; // Offset: 0x30, DWARF: 0x761FC
  signed int accel_speed;     // Offset: 0x34, DWARF: 0x76228
  signed int stop_speed;      // Offset: 0x38, DWARF: 0x76250
} Inp;

// Size: 0x98, DWARF: 0x791A9
typedef struct TrickLink {
  signed int trick_link;         // Offset: 0x0, DWARF: 0x791C4
  signed int trg_start_link;     // Offset: 0x4, DWARF: 0x791EB
  signed int trg_end_link;       // Offset: 0x8, DWARF: 0x79216
  signed int trg_get_pts;        // Offset: 0xC, DWARF: 0x7923F
  signed int spenv_get_trick_no; // Offset: 0x10, DWARF: 0x79267
  signed int pre_cnt_link;       // Offset: 0x14, DWARF: 0x79296
  signed int cnt_link;           // Offset: 0x18, DWARF: 0x792BF
  signed int cnt_trick;          // Offset: 0x1C, DWARF: 0x792E4
  unsigned int last_point;       // Offset: 0x20, DWARF: 0x7930A
  // DWARF: 0x807AE
  Landing_Bonus is_bonus_landing;     // Offset: 0x24, DWARF: 0x79331
  signed int is_bonus_switch;         // Offset: 0x28, DWARF: 0x79360
  signed int is_bonus_spin;           // Offset: 0x2C, DWARF: 0x7938C
  signed int is_bonus_airtime;        // Offset: 0x30, DWARF: 0x793B6
  signed int set_top_cnt_link;        // Offset: 0x34, DWARF: 0x793E3
  signed int added_nollie;            // Offset: 0x38, DWARF: 0x79410
  signed int added_airtime;           // Offset: 0x3C, DWARF: 0x79439
  signed int trg_trick;               // Offset: 0x40, DWARF: 0x79463
  unsigned int pts_current_trick;     // Offset: 0x44, DWARF: 0x79489
  unsigned int pts_current_hold;      // Offset: 0x48, DWARF: 0x794B7
  unsigned int pts_current_spin;      // Offset: 0x4C, DWARF: 0x794E4
  unsigned int pts_trick;             // Offset: 0x50, DWARF: 0x79511
  unsigned int pts_gap;               // Offset: 0x54, DWARF: 0x79537
  signed int cnt_total_hold;          // Offset: 0x58, DWARF: 0x7955B
  signed int spin_ang;                // Offset: 0x5C, DWARF: 0x79586
  signed int last_spin_ang;           // Offset: 0x60, DWARF: 0x795AB
  signed int airtime_frame;           // Offset: 0x64, DWARF: 0x795D5
  unsigned int current_set_tp;        // Offset: 0x68, DWARF: 0x795FF
  unsigned int current_set_tp_rate;   // Offset: 0x6C, DWARF: 0x7962A
  signed int link_rate;               // Offset: 0x70, DWARF: 0x7965A
  unsigned int link_trick_point;      // Offset: 0x74, DWARF: 0x79680
  unsigned int total_trick_point;     // Offset: 0x78, DWARF: 0x796AD
  unsigned int last_link_trick_point; // Offset: 0x7C, DWARF: 0x796DB
  unsigned int get_point;             // Offset: 0x80, DWARF: 0x7970D
  signed int total_trick_num;         // Offset: 0x84, DWARF: 0x79733
  signed int best_link_num;           // Offset: 0x88, DWARF: 0x7975F
  unsigned int best_link_pts;         // Offset: 0x8C, DWARF: 0x79789
  signed int get_the_best;            // Offset: 0x90, DWARF: 0x797B3
  signed int pre_spin_ang;            // Offset: 0x94, DWARF: 0x797DC
} TrickLink;

// Size: 0x1F0, DWARF: 0x7B067
typedef struct Sbcore {
  float nextpos[4];         // Offset: 0x0, DWARF: 0x7B083
  float speed[4];           // Offset: 0x10, DWARF: 0x7B0A9
  float rot_pole;           // Offset: 0x20, DWARF: 0x7B0CD
  float max_relief_gap;     // Offset: 0x24, DWARF: 0x7B0F2
  signed int freefoot;      // Offset: 0x28, DWARF: 0x7B11D
  float limit_ang_down;     // Offset: 0x2C, DWARF: 0x7B142
  float limit_ang_up;       // Offset: 0x30, DWARF: 0x7B16D
  signed int set_sp_normal; // Offset: 0x34, DWARF: 0x7B196
  float pos_head[4]
      __attribute__((aligned(16)));          // Offset: 0x40, DWARF: 0x7B1C0
  float pos_hip[4];                          // Offset: 0x50, DWARF: 0x7B1E7
  signed int move_head;                      // Offset: 0x60, DWARF: 0x7B20D
  float ang_slidable_limit;                  // Offset: 0x64, DWARF: 0x7B233
  float pos[4] __attribute__((aligned(16))); // Offset: 0x70, DWARF: 0x7B262
  float pole[4];                             // Offset: 0x80, DWARF: 0x7B284
  float sp_normal[4];                        // Offset: 0x90, DWARF: 0x7B2A7
  signed int sliding;                        // Offset: 0xA0, DWARF: 0x7B2CF
  float relief_gap;                          // Offset: 0xA4, DWARF: 0x7B2F3
  float touch_posy;                          // Offset: 0xA8, DWARF: 0x7B31A
  float const_max_relief_gap;                // Offset: 0xAC, DWARF: 0x7B341
  float const_under_foot;                    // Offset: 0xB0, DWARF: 0x7B372
  signed int const_keep_normal;              // Offset: 0xB4, DWARF: 0x7B39F
  float height;                              // Offset: 0xB8, DWARF: 0x7B3CD
  signed int cnt_keep_normal;                // Offset: 0xBC, DWARF: 0x7B3F0
  signed int move;                           // Offset: 0xC0, DWARF: 0x7B41C
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
typedef struct Pad {
  unsigned short cnt; // Offset: 0x0, DWARF: 0x168121
  signed char lh;     // Offset: 0x2, DWARF: 0x168141
  signed char lv;     // Offset: 0x3, DWARF: 0x168160
  signed int analog;  // Offset: 0x4, DWARF: 0x16817F
} Pad;

// Size: 0x2580, DWARF: 0x76810
typedef struct Act {
  // Size: 0x1F0, DWARF: 0x7B067
  Sbcore sbcore; // Offset: 0x0, DWARF: 0x7682B
  // Size: 0x30, DWARF: 0x79C3C
  Plane wall;                  // Offset: 0x1F0, DWARF: 0x76850
  signed int cnt_freefoot;     // Offset: 0x220, DWARF: 0x76873
  signed int cnt_turn;         // Offset: 0x224, DWARF: 0x7689C
  signed int cnt_sitting;      // Offset: 0x228, DWARF: 0x768C1
  signed int cnt_spinkey;      // Offset: 0x22C, DWARF: 0x768E9
  signed int cnt_d2c;          // Offset: 0x230, DWARF: 0x76911
  signed int cnt_to_rail;      // Offset: 0x234, DWARF: 0x76935
  signed int cnt_grind;        // Offset: 0x238, DWARF: 0x7695D
  signed int cnt_real_grind;   // Offset: 0x23C, DWARF: 0x76983
  signed int cnt_manual;       // Offset: 0x240, DWARF: 0x769AE
  signed int cnt_total_grind;  // Offset: 0x244, DWARF: 0x769D5
  signed int cnt_total_manual; // Offset: 0x248, DWARF: 0x76A01
  signed int cnt_plant;        // Offset: 0x24C, DWARF: 0x76A2E
  signed int cnt_holding;      // Offset: 0x250, DWARF: 0x76A54
  signed int cnt_planttumble;  // Offset: 0x254, DWARF: 0x76A7C
  signed int cnt_plant2grind;  // Offset: 0x258, DWARF: 0x76AA8
  signed int cnt_tumble;       // Offset: 0x25C, DWARF: 0x76AD4
  signed int cnt_nospin;       // Offset: 0x260, DWARF: 0x76AFB
  signed int cnt_brake;        // Offset: 0x264, DWARF: 0x76B22
  signed int cnt_backward;     // Offset: 0x268, DWARF: 0x76B48
  signed int cnt_no_bodyhit;   // Offset: 0x26C, DWARF: 0x76B71
  signed int cnt_hokan;        // Offset: 0x270, DWARF: 0x76B9C
  signed int jump_air;         // Offset: 0x274, DWARF: 0x76BC2
  signed int def_goofy;        // Offset: 0x278, DWARF: 0x76BE7
  signed int goofy;            // Offset: 0x27C, DWARF: 0x76C0D
  signed int fakie;            // Offset: 0x280, DWARF: 0x76C2F
  // DWARF: 0x7C53F
  Sliding_State sliding_state; // Offset: 0x284, DWARF: 0x76C51
  // DWARF: 0x7C53F
  Sliding_State pre_state;   // Offset: 0x288, DWARF: 0x76C7D
  signed int nollie;         // Offset: 0x28C, DWARF: 0x76CA5
  signed int big_ollie;      // Offset: 0x290, DWARF: 0x76CC8
  signed int super_ollie;    // Offset: 0x294, DWARF: 0x76CEE
  signed int plant_to_fakie; // Offset: 0x298, DWARF: 0x76D16
  signed int trick_keep;     // Offset: 0x29C, DWARF: 0x76D41
  // DWARF: 0x7E931
  Tumble_Type tumble_type; // Offset: 0x2A0, DWARF: 0x76D68
  // DWARF: 0x7FF3C
  Tumble_Way tumble_way;             // Offset: 0x2A4, DWARF: 0x76D92
  signed int trg_hopup;              // Offset: 0x2A8, DWARF: 0x76DBB
  signed int trg_jumpup;             // Offset: 0x2AC, DWARF: 0x76DE1
  signed int trg_touch;              // Offset: 0x2B0, DWARF: 0x76E08
  signed int trg_bonk;               // Offset: 0x2B4, DWARF: 0x76E2E
  signed int trg_boost;              // Offset: 0x2B8, DWARF: 0x76E53
  signed int trg_rewind;             // Offset: 0x2BC, DWARF: 0x76E79
  signed int trg_hit_wall;           // Offset: 0x2C0, DWARF: 0x76EA0
  signed int no_approach_speed;      // Offset: 0x2C4, DWARF: 0x76EC9
  signed int hop_vertical_plane;     // Offset: 0x2C8, DWARF: 0x76EF7
  signed int touch_perfect;          // Offset: 0x2CC, DWARF: 0x76F26
  signed int grind_jump;             // Offset: 0x2D0, DWARF: 0x76F50
  signed int grind_tumble;           // Offset: 0x2D4, DWARF: 0x76F77
  signed int hips;                   // Offset: 0x2D8, DWARF: 0x76FA0
  signed int trg_onair_with_over_hp; // Offset: 0x2DC, DWARF: 0x76FC1
  // DWARF: 0x7E931
  Tumble_Type trg_tumble_type; // Offset: 0x2E0, DWARF: 0x76FF4
  // DWARF: 0x7FF3C
  Tumble_Way trg_tumble_way;    // Offset: 0x2E4, DWARF: 0x77022
  signed int trg_tumble_body;   // Offset: 0x2E8, DWARF: 0x7704F
  signed int end_grind;         // Offset: 0x2EC, DWARF: 0x7707B
  signed int end_manual;        // Offset: 0x2F0, DWARF: 0x770A1
  signed int end_sliding;       // Offset: 0x2F4, DWARF: 0x770C8
  float max_relief_gap;         // Offset: 0x2F8, DWARF: 0x770F0
  float relief_gap;             // Offset: 0x2FC, DWARF: 0x7711B
  float slant;                  // Offset: 0x300, DWARF: 0x77142
  float side_slant;             // Offset: 0x304, DWARF: 0x77164
  float sp_slant;               // Offset: 0x308, DWARF: 0x7718B
  float sp_side_slant;          // Offset: 0x30C, DWARF: 0x771B0
  float ofs_updown;             // Offset: 0x310, DWARF: 0x771DA
  float target_way;             // Offset: 0x314, DWARF: 0x77201
  sceVu0FVECTOR *pre_rail_list; // Offset: 0x318, DWARF: 0x77228 // float*[4]
  sceVu0FVECTOR *rail_list;     // Offset: 0x31C, DWARF: 0x77257 // float*[4]
  signed int num_rail_vertex;   // Offset: 0x320, DWARF: 0x77282
  signed int rail_id;           // Offset: 0x324, DWARF: 0x772AE
  signed int rail_no;           // Offset: 0x328, DWARF: 0x772D2
  sceVu0FVECTOR rail_pos
      __attribute__((aligned(16))); // Offset: 0x330, DWARF: 0x772F6
  // Size: 0x14, DWARF: 0x7C447
  Balance gr_balance;            // Offset: 0x340, DWARF: 0x7731D
  float gr_enter_ang;            // Offset: 0x354, DWARF: 0x77346
  signed int gr_reset_lean;      // Offset: 0x358, DWARF: 0x7736F
  signed int trg_grind_name;     // Offset: 0x35C, DWARF: 0x77399
  signed int gr_grind_no;        // Offset: 0x360, DWARF: 0x773C4
  signed int gr_cnt_kissed;      // Offset: 0x364, DWARF: 0x773EC
  signed int gr_is_reverse;      // Offset: 0x368, DWARF: 0x77416
  signed int gr_back_accel;      // Offset: 0x36C, DWARF: 0x77440
  signed int trg_change_grind;   // Offset: 0x370, DWARF: 0x7746A
  signed int changed_grind;      // Offset: 0x374, DWARF: 0x77497
  signed int disaster;           // Offset: 0x378, DWARF: 0x774C1
  signed int first_grind;        // Offset: 0x37C, DWARF: 0x774E6
  signed int gr_no_jump;         // Offset: 0x380, DWARF: 0x7750E
  signed int hp_air;             // Offset: 0x384, DWARF: 0x77535
  signed int pre_hp_air;         // Offset: 0x388, DWARF: 0x77558
  signed int halfpiping;         // Offset: 0x38C, DWARF: 0x7757F
  signed int pre_halfpiping;     // Offset: 0x390, DWARF: 0x775A6
  signed int over_hp;            // Offset: 0x394, DWARF: 0x775D1
  signed int hp_jump;            // Offset: 0x398, DWARF: 0x775F5
  signed int hp_adj_roty;        // Offset: 0x39C, DWARF: 0x77619
  sceVu0FVECTOR hp_normal;       // Offset: 0x3A0, DWARF: 0x77641
  sceVu0FVECTOR hp_cross;        // Offset: 0x3B0, DWARF: 0x77669
  signed int manual_ready;       // Offset: 0x3C0, DWARF: 0x77690
  signed int manual_ready_no;    // Offset: 0x3C4, DWARF: 0x776B9
  signed int manual_cnt_to_play; // Offset: 0x3C8, DWARF: 0x776E5
  // Size: 0x14, DWARF: 0x7C447
  Balance manu_balance;        // Offset: 0x3CC, DWARF: 0x77714
  signed int manu_reset_lean;  // Offset: 0x3E0, DWARF: 0x7773F
  signed int bonk_ready;       // Offset: 0x3E4, DWARF: 0x7776B
  signed int bonk_ready_no;    // Offset: 0x3E8, DWARF: 0x77792
  signed int bonk_goto;        // Offset: 0x3EC, DWARF: 0x777BC
  sceVu0FVECTOR bonk_point;    // Offset: 0x3F0, DWARF: 0x777E2
  sceVu0FVECTOR bonk_presp;    // Offset: 0x400, DWARF: 0x7780B
  signed int revert_cnt_ready; // Offset: 0x410, DWARF: 0x77834
  signed int revert_ready_no;  // Offset: 0x414, DWARF: 0x77861
  signed int plant_air;        // Offset: 0x418, DWARF: 0x7788D
  sceVu0FVECTOR plant_normal
      __attribute__((aligned(16))); // Offset: 0x420, DWARF: 0x778B3
  float max_height;                 // Offset: 0x430, DWARF: 0x778DE
  signed int big_air;               // Offset: 0x434, DWARF: 0x77905
  signed int cnt_onair;             // Offset: 0x438, DWARF: 0x77929
  signed int cnt_onair2;            // Offset: 0x43C, DWARF: 0x7794F
  signed int cnt_nothit;            // Offset: 0x440, DWARF: 0x77976
  signed int tumble_se_id;          // Offset: 0x444, DWARF: 0x7799D
  float jump_rot_pole;              // Offset: 0x448, DWARF: 0x779C6
  float last_rot_pole;              // Offset: 0x44C, DWARF: 0x779F0
  // DWARF: 0x8178B
  ESP_Spin_Way last_spin_way; // Offset: 0x450, DWARF: 0x77A1A
  sceVu0FVECTOR pos_waist
      __attribute__((aligned(16))); // Offset: 0x460, DWARF: 0x77A46
  float pos_disp[4];                // Offset: 0x470, DWARF: 0x77A6E
  float shadow_posy;                // Offset: 0x480, DWARF: 0x77A95
  float max_speed;                  // Offset: 0x484, DWARF: 0x77ABD
  float cmn_max_speed;              // Offset: 0x488, DWARF: 0x77AE3
  float now_max_speed;              // Offset: 0x48C, DWARF: 0x77B0D
  // Size: 0x24, DWARF: 0x7C294
  Param2 param; // Offset: 0x490, DWARF: 0x77B37
  // Size: 0x1C, DWARF: 0x7C601
  Stats chr_param_x10; // Offset: 0x4B4, DWARF: 0x77B5B
  // Size: 0x10, DWARF: 0x7A1DB
  Board_Param brd_param_x10;             // Offset: 0x4D0, DWARF: 0x77B87
  signed int mot_finish;                 // Offset: 0x4E0, DWARF: 0x77BB3
  signed int mot_grabing;                // Offset: 0x4E4, DWARF: 0x77BDA
  signed int mot_flipping;               // Offset: 0x4E8, DWARF: 0x77C02
  signed int mot_spflipping;             // Offset: 0x4EC, DWARF: 0x77C2B
  signed int mot_grinding;               // Offset: 0x4F0, DWARF: 0x77C56
  signed int mot_planting;               // Offset: 0x4F4, DWARF: 0x77C7F
  signed int mot_manualing;              // Offset: 0x4F8, DWARF: 0x77CA8
  signed int mot_reverting;              // Offset: 0x4FC, DWARF: 0x77CD2
  signed int mot_bonking;                // Offset: 0x500, DWARF: 0x77CFC
  signed int mot_tumbling;               // Offset: 0x504, DWARF: 0x77D24
  signed int mot_reserve_tumble_standup; // Offset: 0x508, DWARF: 0x77D4D
  signed int mot_tumble_standup;         // Offset: 0x50C, DWARF: 0x77D84
  signed int mot_tumble_standup_already; // Offset: 0x510, DWARF: 0x77DB3
  signed int mot_end_tumble;             // Offset: 0x514, DWARF: 0x77DEA
  sceVu0FVECTOR mot_flip_rot
      __attribute__((aligned(16))); // Offset: 0x520, DWARF: 0x77E15
  float mot_flip_roty_base;         // Offset: 0x530, DWARF: 0x77E40
  signed int mot_flip_mode;         // Offset: 0x534, DWARF: 0x77E6F
  // Size: 0x98, DWARF: 0x791A9
  TrickLink trick_link; // Offset: 0x538, DWARF: 0x77E99
  signed int trk_doing; // Offset: 0x5D0, DWARF: 0x77EC2
  // DWARF: 0x80EBF
  ETS_Trick_State trk_state; // Offset: 0x5D4, DWARF: 0x77EE8
  signed int trk_grab_no;    // Offset: 0x5D8, DWARF: 0x77F10
  signed int trk_trick_no;   // Offset: 0x5DC, DWARF: 0x77F38
  // DWARF: 0x81DE1
  Trick_Link_State trk_link_state;  // Offset: 0x5E0, DWARF: 0x77F61
  signed int num_set_gap;           // Offset: 0x5E4, DWARF: 0x77F8E
  signed short set_gap[64];         // Offset: 0x5E8, DWARF: 0x77FB6
  signed int special_num;           // Offset: 0x668, DWARF: 0x77FDC
  signed int special_charge;        // Offset: 0x66C, DWARF: 0x78004
  signed int special_charge_cnt;    // Offset: 0x670, DWARF: 0x7802F
  signed int special_charge_maxcnt; // Offset: 0x674, DWARF: 0x7805E
  signed int special_left_time;     // Offset: 0x678, DWARF: 0x78090
  signed int special_total_time;    // Offset: 0x67C, DWARF: 0x780BE
  signed int special_remainder_tp;  // Offset: 0x680, DWARF: 0x780ED
  signed int boost;                 // Offset: 0x684, DWARF: 0x7811E
  signed int boost_num;             // Offset: 0x688, DWARF: 0x78140
  signed int boost_charge;          // Offset: 0x68C, DWARF: 0x78166
  signed int boost_left_time;       // Offset: 0x690, DWARF: 0x7818F
  signed int boost_total_time;      // Offset: 0x694, DWARF: 0x781BB
  signed int balance_cnt_adj;       // Offset: 0x698, DWARF: 0x781E8
  float balance_ang_adj;            // Offset: 0x69C, DWARF: 0x78214
  float balance_roty_adj;           // Offset: 0x6A0, DWARF: 0x78240
  signed int balance_bigair;        // Offset: 0x6A4, DWARF: 0x7826D
  sceVu0FVECTOR balance_pole
      __attribute__((aligned(16))); // Offset: 0x6B0, DWARF: 0x78298
  float hang_rate;                  // Offset: 0x6C0, DWARF: 0x782C3
  signed int num_hit;               // Offset: 0x6C4, DWARF: 0x782E9
  signed int num_vec;               // Offset: 0x6C8, DWARF: 0x7830D
  signed int num_obj;               // Offset: 0x6CC, DWARF: 0x78331
  // Size: 0x60, DWARF: 0x75E44
  Col col_hit[0x10]; // Offset: 0x6D0, DWARF: 0x78355
  // Size: 0x60, DWARF: 0x75E44
  Col col_vec[0x10]; // Offset: 0xCD0, DWARF: 0x7837B
  // Size: 0x60, DWARF: 0x75E44
  Col col_obj[0x10];          // Offset: 0x12D0, DWARF: 0x783A1
  signed int reserve_tumble;  // Offset: 0x18D0, DWARF: 0x783C7
  float reserve_tumble_ang;   // Offset: 0x18D4, DWARF: 0x783F2
  float reserve_tumble_speed; // Offset: 0x18D8, DWARF: 0x78421
  // DWARF: 0x7E931
  Tumble_Type reserve_tumble_type;         // Offset: 0x18DC, DWARF: 0x78452
  signed int reserve_trick_no[16];         // Offset: 0x18E0, DWARF: 0x78484
  signed int reserve_trick_is_flip[16];    // Offset: 0x1920, DWARF: 0x784B3
  signed int reserve_trick_is_special[16]; // Offset: 0x1960, DWARF: 0x784E7
  signed int num_reserve_trick;            // Offset: 0x19A0, DWARF: 0x7851E
  signed int top_reserve_trick;            // Offset: 0x19A4, DWARF: 0x7854C
  signed int reserve_stance_change;        // Offset: 0x19A8, DWARF: 0x7857A
  signed int num_reserve_grab;             // Offset: 0x19AC, DWARF: 0x785AC
  unsigned char num_play_trick[2][160];    // Offset: 0x19B0, DWARF: 0x785D9
  unsigned char num_play_trick_in_link[2]
                                      [160]; // Offset: 0x1AF0, DWARF: 0x78606
  sceVu0FMATRIX mat_head;                    // Offset: 0x1C30, DWARF: 0x7863B
  float mat_hip[4][4];                       // Offset: 0x1C70, DWARF: 0x78662
  // Size: 0x60, DWARF: 0x75E44
  Col col_rail; // Offset: 0x1CB0, DWARF: 0x78688
  // Size: 0x60, DWARF: 0x75E44
  Col col_plant; // Offset: 0x1D10, DWARF: 0x786AF
  // Size: 0x60, DWARF: 0x75E44
  Col col_hp; // Offset: 0x1D70, DWARF: 0x786D7
  // Size: 0x60, DWARF: 0x75E44
  Col col_zhp;                           // Offset: 0x1DD0, DWARF: 0x786FC
  sceVu0FVECTOR recover_pos;             // Offset: 0x1E30, DWARF: 0x78722
  float recover_roty;                    // Offset: 0x1E40, DWARF: 0x7874C
  float recover_speed;                   // Offset: 0x1E44, DWARF: 0x78775
  signed int recover;                    // Offset: 0x1E48, DWARF: 0x7879F
  signed int trg_recovered;              // Offset: 0x1E4C, DWARF: 0x787C3
  signed int reserve_fall;               // Offset: 0x1E50, DWARF: 0x787ED
  signed int cnt_fall;                   // Offset: 0x1E54, DWARF: 0x78816
  signed int cnt_warp;                   // Offset: 0x1E58, DWARF: 0x7883B
  signed int water_manual;               // Offset: 0x1E5C, DWARF: 0x78860
  signed int sptrk[2];                   // Offset: 0x1E60, DWARF: 0x78889
  signed int num_total_gap;              // Offset: 0x1E68, DWARF: 0x788AD
  signed int num_total_break;            // Offset: 0x1E6C, DWARF: 0x788D7
  signed int reserve_quit;               // Offset: 0x1E70, DWARF: 0x78903
  signed int allow_tlink;                // Offset: 0x1E74, DWARF: 0x7892C
  signed int no_trick;                   // Offset: 0x1E78, DWARF: 0x78954
  signed int trg_quit;                   // Offset: 0x1E7C, DWARF: 0x78979
  signed int cnt_quit;                   // Offset: 0x1E80, DWARF: 0x7899E
  signed int cnt_reserve_quit;           // Offset: 0x1E84, DWARF: 0x789C3
  signed int pass_finish_line;           // Offset: 0x1E88, DWARF: 0x789F0
  signed int pass_finish_line2;          // Offset: 0x1E8C, DWARF: 0x78A1D
  signed int wait_motion;                // Offset: 0x1E90, DWARF: 0x78A4B
  signed int wait_vs;                    // Offset: 0x1E94, DWARF: 0x78A73
  signed int noheight_reflect;           // Offset: 0x1E98, DWARF: 0x78A97
  signed int cnt_noheight_reflect;       // Offset: 0x1E9C, DWARF: 0x78AC4
  signed int cnt_brank_noheight_reflect; // Offset: 0x1EA0, DWARF: 0x78AF5
  signed int forced_bailout;             // Offset: 0x1EA4, DWARF: 0x78B2C
  signed int cnt_hit_wall;               // Offset: 0x1EA8, DWARF: 0x78B57
  signed int cnt_brank_hit_wall;         // Offset: 0x1EAC, DWARF: 0x78B80
  signed int cnt_forced_bailout;         // Offset: 0x1EB0, DWARF: 0x78BAF
  float last_hit_plane[10][4]
      __attribute__((aligned(16))); // Offset: 0x1EC0, DWARF: 0x78BDE
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
typedef struct Ctrl {
  float rot[4];                  // Offset: 0x0, DWARF: 0x16AAA3
  float speed[4];                // Offset: 0x10, DWARF: 0x16AAC5
  float pole[4];                 // Offset: 0x20, DWARF: 0x16AAE9
  float nor_pole[4];             // Offset: 0x30, DWARF: 0x16AB0C
  float disp_pole[4];            // Offset: 0x40, DWARF: 0x16AB33
  float rot_pole;                // Offset: 0x50, DWARF: 0x16AB5B
  float disp_rot_pole;           // Offset: 0x54, DWARF: 0x16AB80
  float disp_rot_foot;           // Offset: 0x58, DWARF: 0x16ABAA
  signed int disp_rot_foot_is_x; // Offset: 0x5C, DWARF: 0x16ABD4
  float disp_pos[4];             // Offset: 0x60, DWARF: 0x16AC03
  float disp_pos_ofs[4];         // Offset: 0x70, DWARF: 0x16AC2A
  float disp_rot_z_ofs;          // Offset: 0x80, DWARF: 0x16AC55
  float slant_pole;              // Offset: 0x84, DWARF: 0x16AC80
  float splen;                   // Offset: 0x88, DWARF: 0x16ACA7
  float splenxz;                 // Offset: 0x8C, DWARF: 0x16ACC9
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
  struct {
    // DWARF: 0x16C5FB
    Acceleration_Brake accel_brake; // Offset: 0x0, DWARF: 0x16EEC0
    signed int sitting;             // Offset: 0x4, DWARF: 0x16EEEA
    // DWARF: 0x16E4C8
    Jump_Strength jump; // Offset: 0x8, DWARF: 0x16EF0E
    // DWARF: 0x16D3F3
    ERSC_Stance_Change stance_change; // Offset: 0xC, DWARF: 0x16EF31
    // DWARF: 0x16DAF8
    ERC_Command command;      // Offset: 0x10, DWARF: 0x16EF5D
    signed int cmd_mot_id;    // Offset: 0x14, DWARF: 0x16EF83
    signed int cmd_mot_nloop; // Offset: 0x18, DWARF: 0x16EFAA
    signed int cmd_trick_no;  // Offset: 0x1C, DWARF: 0x16EFD4
    signed int end_fall;      // Offset: 0x20, DWARF: 0x16EFFD
    signed int trick_no;      // Offset: 0x24, DWARF: 0x16F022
    signed int flip_no;       // Offset: 0x28, DWARF: 0x16F047
    signed int grind_no;      // Offset: 0x2C, DWARF: 0x16F06B
    signed int plant_no;      // Offset: 0x30, DWARF: 0x16F090
    signed int bonk_no;       // Offset: 0x34, DWARF: 0x16F0B5
    signed int manual_no;     // Offset: 0x38, DWARF: 0x16F0D9
    signed int revert_no;     // Offset: 0x3C, DWARF: 0x16F0FF
    signed int jump_no;       // Offset: 0x40, DWARF: 0x16F125
    signed int sptrk_id;      // Offset: 0x44, DWARF: 0x16F149
  } nowreq;                   // Offset: 0x298, DWARF: 0x16AE17
  // Size: 0x48, DWARF: 0x16EEA4
  struct {
    // DWARF: 0x16C5FB
    Acceleration_Brake accel_brake; // Offset: 0x0, DWARF: 0x16EEC0
    signed int sitting;             // Offset: 0x4, DWARF: 0x16EEEA
    // DWARF: 0x16E4C8
    Jump_Strength jump; // Offset: 0x8, DWARF: 0x16EF0E
    // DWARF: 0x16D3F3
    ERSC_Stance_Change stance_change; // Offset: 0xC, DWARF: 0x16EF31
    // DWARF: 0x16DAF8
    ERC_Command command;      // Offset: 0x10, DWARF: 0x16EF5D
    signed int cmd_mot_id;    // Offset: 0x14, DWARF: 0x16EF83
    signed int cmd_mot_nloop; // Offset: 0x18, DWARF: 0x16EFAA
    signed int cmd_trick_no;  // Offset: 0x1C, DWARF: 0x16EFD4
    signed int end_fall;      // Offset: 0x20, DWARF: 0x16EFFD
    signed int trick_no;      // Offset: 0x24, DWARF: 0x16F022
    signed int flip_no;       // Offset: 0x28, DWARF: 0x16F047
    signed int grind_no;      // Offset: 0x2C, DWARF: 0x16F06B
    signed int plant_no;      // Offset: 0x30, DWARF: 0x16F090
    signed int bonk_no;       // Offset: 0x34, DWARF: 0x16F0B5
    signed int manual_no;     // Offset: 0x38, DWARF: 0x16F0D9
    signed int revert_no;     // Offset: 0x3C, DWARF: 0x16F0FF
    signed int jump_no;       // Offset: 0x40, DWARF: 0x16F125
    signed int sptrk_id;      // Offset: 0x44, DWARF: 0x16F149
  } prereq;                   // Offset: 0x2E0, DWARF: 0x16AE3C
  // Size: 0x2580, DWARF: 0x168520
  Act act; // Offset: 0x330, DWARF: 0x16AE61
  // Size: 0x190, DWARF: 0x1677E9
  struct // Offset 28B0
  {
    // Size: 0x2C, DWARF: 0x16DF3B
    struct // Offset 0x28B0
    {
      signed int id;             // Offset: 0x0, DWARF: 0x16DF57
      signed int uad;            // Offset: 0x4, DWARF: 0x16DF76
      signed int num_frame;      // Offset: 0x8, DWARF: 0x16DF96
      signed int frame;          // Offset: 0xC, DWARF: 0x16DFBC
      signed int target_frame;   // Offset: 0x10, DWARF: 0x16DFDE
      signed int nloop;          // Offset: 0x14, DWARF: 0x16E007
      signed int inter_frame;    // Offset: 0x18, DWARF: 0x16E029
      signed int inter_count;    // Offset: 0x1C, DWARF: 0x16E051
      signed int brend;          // Offset: 0x20, DWARF: 0x16E079
      float adj_rot;             // Offset: 0x24, DWARF: 0x16E09B
      signed int cannot_control; // Offset: 0x28, DWARF: 0x16E0BF
    } now;                       // Offset: 0x0, DWARF: 0x167804
    // Size: 0x2C, DWARF: 0x16DF3B
    struct // Offset 2C + 28B0 = 28DC
    {
      signed int id;             // Offset: 0x0, DWARF: 0x16DF57
      signed int uad;            // Offset: 0x4, DWARF: 0x16DF76
      signed int num_frame;      // Offset: 0x8, DWARF: 0x16DF96
      signed int frame;          // Offset: 0xC, DWARF: 0x16DFBC
      signed int target_frame;   // Offset: 0x10, DWARF: 0x16DFDE
      signed int nloop;          // Offset: 0x14, DWARF: 0x16E007
      signed int inter_frame;    // Offset: 0x18, DWARF: 0x16E029
      signed int inter_count;    // Offset: 0x1C, DWARF: 0x16E051
      signed int brend;          // Offset: 0x20, DWARF: 0x16E079
      float adj_rot;             // Offset: 0x24, DWARF: 0x16E09B
      signed int cannot_control; // Offset: 0x28, DWARF: 0x16E0BF
    } next;                      // Offset: 0x2C, DWARF: 0x167826
    // Size: 0x2C, DWARF: 0x16DF3B
    struct {
      signed int id;             // Offset: 0x0, DWARF: 0x16DF57
      signed int uad;            // Offset: 0x4, DWARF: 0x16DF76
      signed int num_frame;      // Offset: 0x8, DWARF: 0x16DF96
      signed int frame;          // Offset: 0xC, DWARF: 0x16DFBC
      signed int target_frame;   // Offset: 0x10, DWARF: 0x16DFDE
      signed int nloop;          // Offset: 0x14, DWARF: 0x16E007
      signed int inter_frame;    // Offset: 0x18, DWARF: 0x16E029
      signed int inter_count;    // Offset: 0x1C, DWARF: 0x16E051
      signed int brend;          // Offset: 0x20, DWARF: 0x16E079
      float adj_rot;             // Offset: 0x24, DWARF: 0x16E09B
      signed int cannot_control; // Offset: 0x28, DWARF: 0x16E0BF
    } pre;                       // Offset: 0x58, DWARF: 0x167849
    // Size: 0x2C, DWARF: 0x16DF3B
    struct {
      signed int id;             // Offset: 0x0, DWARF: 0x16DF57
      signed int uad;            // Offset: 0x4, DWARF: 0x16DF76
      signed int num_frame;      // Offset: 0x8, DWARF: 0x16DF96
      signed int frame;          // Offset: 0xC, DWARF: 0x16DFBC
      signed int target_frame;   // Offset: 0x10, DWARF: 0x16DFDE
      signed int nloop;          // Offset: 0x14, DWARF: 0x16E007
      signed int inter_frame;    // Offset: 0x18, DWARF: 0x16E029
      signed int inter_count;    // Offset: 0x1C, DWARF: 0x16E051
      signed int brend;          // Offset: 0x20, DWARF: 0x16E079
      float adj_rot;             // Offset: 0x24, DWARF: 0x16E09B
      signed int cannot_control; // Offset: 0x28, DWARF: 0x16E0BF
    } pre2;                      // Offset: 0x84, DWARF: 0x16786B
    // Size: 0x2C, DWARF: 0x16DF3B
    struct // Offset B0 + 28B0 = 2960
    {
      signed int id;             // Offset: 0x0, DWARF: 0x16DF57
      signed int uad;            // Offset: 0x4, DWARF: 0x16DF76
      signed int num_frame;      // Offset: 0x8, DWARF: 0x16DF96
      signed int frame;          // Offset: 0xC, DWARF: 0x16DFBC
      signed int target_frame;   // Offset: 0x10, DWARF: 0x16DFDE
      signed int nloop;          // Offset: 0x14, DWARF: 0x16E007
      signed int inter_frame;    // Offset: 0x18, DWARF: 0x16E029
      signed int inter_count;    // Offset: 0x1C, DWARF: 0x16E051
      signed int brend;          // Offset: 0x20, DWARF: 0x16E079
      float adj_rot;             // Offset: 0x24, DWARF: 0x16E09B
      signed int cannot_control; // Offset: 0x28, DWARF: 0x16E0BF
    } now2;                      // Offset: 0xB0, DWARF: 0x16788E
    // Size: 0x2C, DWARF: 0x16DF3B
    struct // Offset 28B0 + DC = 298C
    {
      signed int id;             // Offset: 0x0, DWARF: 0x16DF57
      signed int uad;            // Offset: 0x4, DWARF: 0x16DF76
      signed int num_frame;      // Offset: 0x8, DWARF: 0x16DF96
      signed int frame;          // Offset: 0xC, DWARF: 0x16DFBC
      signed int target_frame;   // Offset: 0x10, DWARF: 0x16DFDE
      signed int nloop;          // Offset: 0x14, DWARF: 0x16E007
      signed int inter_frame;    // Offset: 0x18, DWARF: 0x16E029
      signed int inter_count;    // Offset: 0x1C, DWARF: 0x16E051
      signed int brend;          // Offset: 0x20, DWARF: 0x16E079
      float adj_rot;             // Offset: 0x24, DWARF: 0x16E09B
      signed int cannot_control; // Offset: 0x28, DWARF: 0x16E0BF
    } next2;                     // Offset: 0xDC, DWARF: 0x1678B1
    // Size: 0x50, DWARF: 0x16F172
    struct // Offset 28B0 + 110 = 29C0
    {
      // Size: 0x20, DWARF: 0x16E73E
      struct {
        float rot[4];     // Offset: 0x0, DWARF: 0x16E75A
        signed int frame; // Offset: 0x10, DWARF: 0x16E77C
        signed int pad;   // Offset: 0x14, DWARF: 0x16E79E
      } *key_list;        // Offset: 0x0, DWARF: 0x16F18E
      // Size: 0x20, DWARF: 0x16E73E
      struct // Offset 29C0 + 10 = 29D0
      {
        float rot[4]
            __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x16E75A
        signed int frame;                 // Offset: 0x10, DWARF: 0x16E77C
        signed int pad;                   // Offset: 0x14, DWARF: 0x16E79E
      } now;                              // Offset: 0x10, DWARF: 0x16F1B8
      signed int num_key;                 // Offset: 0x30, DWARF: 0x16F1DA
      signed int num_frame;               // Offset: 0x34, DWARF: 0x16F1FE
      // DWARF: 0x16ECC4
      enum {
        eflReady,
        eflFlipping,
        eflEnd
      } flipmode;                        // Offset: 0x38, DWARF: 0x16F224
      signed int mot_id;                 // Offset: 0x3C, DWARF: 0x16F24B
      signed int play_mot;               // Offset: 0x40, DWARF: 0x16F26E
    } flip __attribute__((aligned(16))); // Offset: 0x110, DWARF: 0x1678D5
    signed int cnt_ik_foot;              // Offset: 0x160, DWARF: 0x1678F8
    signed int freemotion;               // Offset: 0x164, DWARF: 0x167920
    signed int ik;                       // Offset: 0x168, DWARF: 0x167947
    signed int reserve_schange;          // Offset: 0x16C, DWARF: 0x167966
    signed int reserve_brending_schange; // Offset: 0x170, DWARF: 0x167992
    signed int motion_speed;             // Offset: 0x174, DWARF: 0x1679C7
    signed int mot_sp_flip;              // Offset: 0x178, DWARF: 0x1679F0
    signed int trg_to_calc_flip;         // Offset: 0x17C, DWARF: 0x167A18
    signed int to_calc_flip;             // Offset: 0x180, DWARF: 0x167A45
  } mot;                                 // Offset: 0x28B0, DWARF: 0x16AE83
  // Size: 0x190, DWARF: 0x16B9B7
  struct // Offset 2A40
  {
    float pre_speed[4];    // Offset: 0x0, DWARF: 0x16B9D3
    float now_speed[4];    // Offset: 0x10, DWARF: 0x16B9FB
    float normal_speed[4]; // Offset: 0x20, DWARF: 0x16BA23
    float rot[4];          // Offset: 0x30, DWARF: 0x16BA4E
    float pos_waist[4];    // Offset: 0x40, DWARF: 0x16BA70
    float pos_disp[4];     // Offset: 0x50, DWARF: 0x16BA98
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
    float max_height;               // Offset: 0x130, DWARF: 0x16BBAF
    signed int cnt_onair;           // Offset: 0x134, DWARF: 0x16BBD6
    signed int cnt_turn;            // Offset: 0x138, DWARF: 0x16BBFC
    float max_speed;                // Offset: 0x13C, DWARF: 0x16BC21
    signed int hp_air;              // Offset: 0x140, DWARF: 0x16BC47
    float splen_prejump;            // Offset: 0x144, DWARF: 0x16BC6A
    // DWARF: 0x1681CA
    Tumble_Type tumble_type; // Offset: 0x148, DWARF: 0x16BC94
    // DWARF: 0x16C25C
    Tumble_Way tumble_way; // Offset: 0x14C, DWARF: 0x16BCBE
    // DWARF: 0x1681CA
    Tumble_Type trg_tumble_type;   // Offset: 0x150, DWARF: 0x16BCE7
    signed int trg_tumble_standup; // Offset: 0x154, DWARF: 0x16BD15
    float grind_enter_ang;         // Offset: 0x158, DWARF: 0x16BD44
    signed int trick_link;         // Offset: 0x15C, DWARF: 0x16BD70
    signed int trg_start_endmot;   // Offset: 0x160, DWARF: 0x16BD97
    signed int trg_recovered;      // Offset: 0x164, DWARF: 0x16BDC4
    signed int trg_hopup;          // Offset: 0x168, DWARF: 0x16BDEE
    signed int trg_jumpup;         // Offset: 0x16C, DWARF: 0x16BE14
    signed int trg_touch;          // Offset: 0x170, DWARF: 0x16BE3B
    signed int trg_boost;          // Offset: 0x174, DWARF: 0x16BE61
    signed int bonk_goto;          // Offset: 0x178, DWARF: 0x16BE87
    signed int trg_plant;          // Offset: 0x17C, DWARF: 0x16BEAD
    signed int grind_goto;         // Offset: 0x180, DWARF: 0x16BED3
  } cam;                           // Offset: 0x2A40, DWARF: 0x16AEA5
  // Size: 0x14, DWARF: 0x16D54F
  struct {
    float splen;                     // Offset: 0x0, DWARF: 0x16D56B
    float rot_pole;                  // Offset: 0x4, DWARF: 0x16D58D
    float anggap_sp_brd;             // Offset: 0x8, DWARF: 0x16D5B2
    float anggap_board_rot;          // Offset: 0xC, DWARF: 0x16D5DC
    signed int side_slide;           // Offset: 0x10, DWARF: 0x16D609
  } se __attribute__((aligned(16))); // Offset: 0x2BD0, DWARF: 0x16AEC7
  // Size: 0x3C, DWARF: 0x167640
  struct {
    signed int no;     // Offset: 0x0, DWARF: 0x16765B
    signed int player; // Offset: 0x4, DWARF: 0x16767A
    signed int wear;   // Offset: 0x8, DWARF: 0x16769D
    signed int board;  // Offset: 0xC, DWARF: 0x1676BE
    // Size: 0x1C, DWARF: 0x16D2B9
    Stats chr_param; // Offset: 0x10, DWARF: 0x1676E0
    // Size: 0x10, DWARF: 0x16DA24
    Board_Param brd_param; // Offset: 0x2C, DWARF: 0x167708
  } *param;                // Offset: 0x2BE4, DWARF: 0x16AEE8
  // Size: 0x24, DWARF: 0x167A72
  struct {
    signed int vibration; // Offset: 0x0, DWARF: 0x167A8D
    signed int spin_l;    // Offset: 0x4, DWARF: 0x167AB3
    signed int spin_r;    // Offset: 0x8, DWARF: 0x167AD6
    signed int stance;    // Offset: 0xC, DWARF: 0x167AF9
    signed int revert;    // Offset: 0x10, DWARF: 0x167B1C
    signed int grind;     // Offset: 0x14, DWARF: 0x167B3F
    signed int grab;      // Offset: 0x18, DWARF: 0x167B61
    signed int jump;      // Offset: 0x1C, DWARF: 0x167B82
    signed int flip;      // Offset: 0x20, DWARF: 0x167BA3
  } *key;                 // Offset: 0x2BE8, DWARF: 0x16AF0F
  // Size: 0x30, DWARF: 0x167BEE
  Cheats *cheats; // Offset: 0x2BEC, DWARF: 0x16AF34
  // Size: 0x340, DWARF: 0x167DF5
  struct {
    // Size: 0x30, DWARF: 0x16C801
    struct {
      float aspect_x;   // Offset: 0x0, DWARF: 0x16C81D
      float aspect_y;   // Offset: 0x4, DWARF: 0x16C842
      float center_x;   // Offset: 0x8, DWARF: 0x16C867
      float center_y;   // Offset: 0xC, DWARF: 0x16C88C
      float clip_vol_x; // Offset: 0x10, DWARF: 0x16C8B1
      float clip_vol_y; // Offset: 0x14, DWARF: 0x16C8D8
      float min_z;      // Offset: 0x18, DWARF: 0x16C8FF
      float max_z;      // Offset: 0x1C, DWARF: 0x16C921
      float near_z;     // Offset: 0x20, DWARF: 0x16C943
      float far_z;      // Offset: 0x24, DWARF: 0x16C966
      float screen_z;   // Offset: 0x28, DWARF: 0x16C988
      float res;        // Offset: 0x2C, DWARF: 0x16C9AD
    } scr_info;         // Offset: 0x0, DWARF: 0x167E10
    // Size: 0x20, DWARF: 0x16D961
    struct {
      float min;         // Offset: 0x0, DWARF: 0x16D97D
      float max;         // Offset: 0x4, DWARF: 0x16D99D
      float far;         // Offset: 0x8, DWARF: 0x16D9BD
      float near;        // Offset: 0xC, DWARF: 0x16D9DD
      signed int col[4]; // Offset: 0x10, DWARF: 0x16D9FE
    } fog;               // Offset: 0x30, DWARF: 0x167E37
    // Size: 0x140, DWARF: 0x16DBF7
    struct {
      sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x16DC13
      sceVu0FMATRIX local_light;  // Offset: 0x40, DWARF: 0x16DC3E
      sceVu0FMATRIX light_color;  // Offset: 0x80, DWARF: 0x16DC68
      sceVu0FMATRIX local_clip;   // Offset: 0xC0, DWARF: 0x16DC92
      sceVu0FMATRIX clip_screen;  // Offset: 0x100, DWARF: 0x16DCBB
    } matrix;                     // Offset: 0x50, DWARF: 0x167E59
    sceVu0FMATRIX world_screen;   // Offset: 0x190, DWARF: 0x167E7E
    sceVu0FMATRIX world_view;     // Offset: 0x1D0, DWARF: 0x167EA9
    sceVu0FMATRIX view_screen;    // Offset: 0x210, DWARF: 0x167ED2
    sceVu0FMATRIX light_color;    // Offset: 0x250, DWARF: 0x167EFC
    sceVu0FMATRIX normal_light;   // Offset: 0x290, DWARF: 0x167F26
    sceVu0FMATRIX view_clip;      // Offset: 0x2D0, DWARF: 0x167F51
    sceVu0FVECTOR cam_rot;        // Offset: 0x310, DWARF: 0x167F79
    sceVu0FVECTOR cam_trans;      // Offset: 0x320, DWARF: 0x167F9F
    float view_angle;             // Offset: 0x330, DWARF: 0x167FC7
  } *sys_mat;                     // Offset: 0x2BF0, DWARF: 0x16AF5C
} Ctrl;

// Size: 0x2A30, DWARF: 0x7F8F0
typedef struct Disp {
  void *umd; // Offset: 0x0, DWARF: 0x7F90C
  void *utd; // Offset: 0x4, DWARF: 0x7F92F
  // Size: 0xF0, DWARF: 0x80315
  struct {
    unsigned int model_id;    // Offset: 0x0, DWARF: 0x80331
    signed int loop;          // Offset: 0x4, DWARF: 0x80356
    signed int mode;          // Offset: 0x8, DWARF: 0x80377
    signed int write_flg;     // Offset: 0xC, DWARF: 0x80398
    signed int now_local_id;  // Offset: 0x10, DWARF: 0x803BE
    signed int now_top_id;    // Offset: 0x14, DWARF: 0x803E7
    signed int next_local_id; // Offset: 0x18, DWARF: 0x8040E
    signed int next_top_id;   // Offset: 0x1C, DWARF: 0x80438
    // Size: 0x20, DWARF: 0x7EE12
    struct {
      float pos[4];   // Offset: 0x0, DWARF: 0x7EE2E
      float rot[4];   // Offset: 0x10, DWARF: 0x7EE50
    } *mdl_data;      // Offset: 0x20, DWARF: 0x80460
    float now_frame;  // Offset: 0x24, DWARF: 0x8048A
    float next_frame; // Offset: 0x28, DWARF: 0x804B0
    float ratio;      // Offset: 0x2C, DWARF: 0x804D7
    // Size: 0x10, DWARF: 0x813DF
    struct {
      unsigned int type; // Offset: 0x0, DWARF: 0x813FB
      float frame;       // Offset: 0x4, DWARF: 0x8141C
      signed short flg;  // Offset: 0x8, DWARF: 0x8143E
      signed short non;  // Offset: 0xA, DWARF: 0x8145E
      float *data[4];    // Offset: 0xC, DWARF: 0x8147E
    } *now_pos_address;  // Offset: 0x30, DWARF: 0x804F9
    // Size: 0x10, DWARF: 0x813DF
    struct {
      unsigned int type; // Offset: 0x0, DWARF: 0x813FB
      float frame;       // Offset: 0x4, DWARF: 0x8141C
      signed short flg;  // Offset: 0x8, DWARF: 0x8143E
      signed short non;  // Offset: 0xA, DWARF: 0x8145E
      float *data[4];    // Offset: 0xC, DWARF: 0x8147E
    } *now_rot_address;  // Offset: 0x34, DWARF: 0x8052A
    // Size: 0x10, DWARF: 0x813DF
    struct {
      unsigned int type; // Offset: 0x0, DWARF: 0x813FB
      float frame;       // Offset: 0x4, DWARF: 0x8141C
      signed short flg;  // Offset: 0x8, DWARF: 0x8143E
      signed short non;  // Offset: 0xA, DWARF: 0x8145E
      float *data[4];    // Offset: 0xC, DWARF: 0x8147E
    } *next_pos_address; // Offset: 0x38, DWARF: 0x8055B
    // Size: 0x10, DWARF: 0x813DF
    struct {
      unsigned int type;       // Offset: 0x0, DWARF: 0x813FB
      float frame;             // Offset: 0x4, DWARF: 0x8141C
      signed short flg;        // Offset: 0x8, DWARF: 0x8143E
      signed short non;        // Offset: 0xA, DWARF: 0x8145E
      float *data[4];          // Offset: 0xC, DWARF: 0x8147E
    } *next_rot_address;       // Offset: 0x3C, DWARF: 0x8058D
    float nowDir[4];           // Offset: 0x40, DWARF: 0x805BF
    float nowTrans[4];         // Offset: 0x50, DWARF: 0x805E4
    float now_matrix[4][4];    // Offset: 0x60, DWARF: 0x8060B
    float pos[4];              // Offset: 0xA0, DWARF: 0x80634
    float quat[4];             // Offset: 0xB0, DWARF: 0x80656
    float pre_pos[4];          // Offset: 0xC0, DWARF: 0x80679
    float pre_rot[4];          // Offset: 0xD0, DWARF: 0x8069F
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0x806C5
    signed int vertexLoopFlg;  // Offset: 0xE4, DWARF: 0x806F0
    signed int pad[2];         // Offset: 0xE8, DWARF: 0x8071A
  } *seq;                      // Offset: 0x8, DWARF: 0x7F952
  // Size: 0x24, DWARF: 0x80BCF
  struct {
    __int128 *regular;  // Offset: 0x0, DWARF: 0x80BEB
    __int128 *fakie;    // Offset: 0x4, DWARF: 0x80C12
    __int128 *trick;    // Offset: 0x8, DWARF: 0x80C37
    __int128 *special;  // Offset: 0xC, DWARF: 0x80C5C
    __int128 *special2; // Offset: 0x10, DWARF: 0x80C83
    __int128 *special3; // Offset: 0x14, DWARF: 0x80CAB
    __int128 *special4; // Offset: 0x18, DWARF: 0x80CD3
    __int128 *special5; // Offset: 0x1C, DWARF: 0x80CFB
    __int128 *special6; // Offset: 0x20, DWARF: 0x80D23
  } uad_list;           // Offset: 0xC, DWARF: 0x7F977
  // Size: 0x160, DWARF: 0x7D512
  struct {
    unsigned int enable; // Offset: 0x0, DWARF: 0x7D52E
    // Size: 0x140, DWARF: 0x7DA36
    struct {
      signed int count[8][3]
          __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x7DA52
      signed int speed[8][3];           // Offset: 0x60, DWARF: 0x7DA76
      float wave[8][4];                 // Offset: 0xC0, DWARF: 0x7DA9A
    } wind;                             // Offset: 0x10, DWARF: 0x7D551
    // Size: 0x8, DWARF: 0x7E8D5
    struct {
      float a; // Offset: 0x0, DWARF: 0x7E8F1
      float b; // Offset: 0x4, DWARF: 0x7E90F
    } fog;     // Offset: 0x150, DWARF: 0x7D574
    // Size: 0x8, DWARF: 0x7EB45
    struct {
      unsigned long tex0; // Offset: 0x0, DWARF: 0x7EB61
    } envmap;             // Offset: 0x158, DWARF: 0x7D596
  } vmenv;                // Offset: 0x30, DWARF: 0x7F99E
  // Size: 0x2E0, DWARF: 0x7CF19
  struct {
    float rot[4];         // Offset: 0x0, DWARF: 0x7CF35
    float trans[4];       // Offset: 0x10, DWARF: 0x7CF57
    float scale[4];       // Offset: 0x20, DWARF: 0x7CF7B
    float matrix[4][4];   // Offset: 0x30, DWARF: 0x7CF9F
    float revision[4][4]; // Offset: 0x70, DWARF: 0x7CFC4
    // Size: 0x230, DWARF: 0x81827
    struct {
      float rot[4];               // Offset: 0x0, DWARF: 0xCE04C
      float trans[4];             // Offset: 0x10, DWARF: 0xCE06E
      float off_trans[2][4];      // Offset: 0x20, DWARF: 0xCE092
      sceVu0FMATRIX *boardMat;    // Offset: 0x40, DWARF: 0xCE0BA
      sceVu0FMATRIX *board_local; // Offset: 0x44, DWARF: 0xCE0E4
      sceVu0FMATRIX *thighMatL;   // Offset: 0x48, DWARF: 0xCE111
      sceVu0FMATRIX *thighMatR;   // Offset: 0x4C, DWARF: 0xCE13C
      sceVu0FMATRIX *calfMatL;    // Offset: 0x50, DWARF: 0xCE167
      sceVu0FMATRIX *calfMatR;    // Offset: 0x54, DWARF: 0xCE191
      sceVu0FMATRIX *footMatL;    // Offset: 0x58, DWARF: 0xCE1BB
      sceVu0FMATRIX *footMatR;    // Offset: 0x5C, DWARF: 0xCE1E5
      sceVu0FMATRIX *toeMatL;     // Offset: 0x60, DWARF: 0xCE20F
      sceVu0FMATRIX *toeMatR;     // Offset: 0x64, DWARF: 0xCE238
      float thighLength[2];       // Offset: 0x68, DWARF: 0xCE261
      float shinLength[2];        // Offset: 0x70, DWARF: 0xCE28B
      signed int flg;             // Offset: 0x78, DWARF: 0xCE2B4
      signed int pad;             // Offset: 0x7C, DWARF: 0xCE2D4
      sceVu0FMATRIX footL;        // Offset: 0x80, DWARF: 0xCE2F4
      sceVu0FMATRIX footR;        // Offset: 0xC0, DWARF: 0xCE318
      sceVu0FMATRIX toeL;         // Offset: 0x100, DWARF: 0xCE33C
      sceVu0FMATRIX toeR;         // Offset: 0x140, DWARF: 0xCE35F
      float off_trans_toe[2][4];  // Offset: 0x180, DWARF: 0xCE382
      float thighLength_toe[2];   // Offset: 0x1A0, DWARF: 0xCE3AE
      float shinLength_toe[2];    // Offset: 0x1A8, DWARF: 0xCE3DC
      sceVu0FMATRIX board;        // Offset: 0x1B0, DWARF: 0xCE409
      sceVu0FMATRIX board_world;  // Offset: 0x1F0, DWARF: 0xCE42D
    } ikparam;                    // Offset: 0xB0, DWARF: 0x7CFEB
  } *umd_ctrl;                    // Offset: 0x190, DWARF: 0x7F9C2
  // Size: 0x1A0, DWARF: 0x7C011
  struct {
    signed int type;              // Offset: 0x0, DWARF: 0x7C02D
    float power;                  // Offset: 0x4, DWARF: 0x7C04E
    float dir;                    // Offset: 0x8, DWARF: 0x7C070
    float cnt;                    // Offset: 0xC, DWARF: 0x7C090
    float head[4];                // Offset: 0x10, DWARF: 0x7C0B0
    float preHead[4];             // Offset: 0x20, DWARF: 0x7C0D3
    float tail_matrix[5][4][4];   // Offset: 0x30, DWARF: 0x7C0F9
    float g_vector[4];            // Offset: 0x170, DWARF: 0x7C123
    unsigned int *tailAddress[5]; // Offset: 0x180, DWARF: 0x7C14A
    signed int pad[3];            // Offset: 0x194, DWARF: 0x7C174
  } *smd_ctrl;                    // Offset: 0x194, DWARF: 0x7F9EC
  // Size: 0x90, DWARF: 0x7BE99
  struct {
    float original[4][4];  // Offset: 0x0, DWARF: 0x7BEB5
    float original2[4][4]; // Offset: 0x40, DWARF: 0x7BEDC
    float *address[4][4];  // Offset: 0x80, DWARF: 0x7BF04
    float *address2[4][4]; // Offset: 0x84, DWARF: 0x7BF2D
    signed int pad[2];     // Offset: 0x88, DWARF: 0x7BF57
  } *model_change;         // Offset: 0x198, DWARF: 0x7FA16
  float scale;             // Offset: 0x19C, DWARF: 0x7FA44
  // Size: 0x2580, DWARF: 0x76810
  Act act; // Offset: 0x1A0, DWARF: 0x7FA66
  // Size: 0x60, DWARF: 0x79DD3
  Pos nowpos; // Offset: 0x2720, DWARF: 0x7FA88
  // Size: 0x60, DWARF: 0x79DD3
  Pos prepos __attribute__((aligned(16))); // Offset: 0x2780, DWARF: 0x7FAAD
  // Size: 0x3C, DWARF: 0x7600B
  Inp nowinp __attribute__((aligned(16)));     // Offset: 0x27E0, DWARF: 0x7FAD2
  float speed[4] __attribute__((aligned(16))); // Offset: 0x2820, DWARF: 0x7FAF7
  float splen;                                 // Offset: 0x2830, DWARF: 0x7FB1B
  float splenxz;                               // Offset: 0x2834, DWARF: 0x7FB3D
  float shadow_posy;                           // Offset: 0x2838, DWARF: 0x7FB61
  signed int disp_char;                        // Offset: 0x283C, DWARF: 0x7FB89
  signed int disp_shadow;                      // Offset: 0x2840, DWARF: 0x7FBAF
  signed int in_screen;                        // Offset: 0x2844, DWARF: 0x7FBD7
  signed int reset_effect2;                    // Offset: 0x2848, DWARF: 0x7FBFD
  signed int detail;                           // Offset: 0x284C, DWARF: 0x7FC27
  signed int set_sub_data;                     // Offset: 0x2850, DWARF: 0x7FC4A
  signed int sub_detail;                       // Offset: 0x2854, DWARF: 0x7FC73
  void *sub_umd;                               // Offset: 0x2858, DWARF: 0x7FC9A
  // Size: 0x2E0, DWARF: 0x7CF19
  struct {
    float rot[4];         // Offset: 0x0, DWARF: 0x7CF35
    float trans[4];       // Offset: 0x10, DWARF: 0x7CF57
    float scale[4];       // Offset: 0x20, DWARF: 0x7CF7B
    float matrix[4][4];   // Offset: 0x30, DWARF: 0x7CF9F
    float revision[4][4]; // Offset: 0x70, DWARF: 0x7CFC4
    // Size: 0x230, DWARF: 0x81827
    struct {
      float rot[4];               // Offset: 0x0, DWARF: 0xCE04C
      float trans[4];             // Offset: 0x10, DWARF: 0xCE06E
      float off_trans[2][4];      // Offset: 0x20, DWARF: 0xCE092
      sceVu0FMATRIX *boardMat;    // Offset: 0x40, DWARF: 0xCE0BA
      sceVu0FMATRIX *board_local; // Offset: 0x44, DWARF: 0xCE0E4
      sceVu0FMATRIX *thighMatL;   // Offset: 0x48, DWARF: 0xCE111
      sceVu0FMATRIX *thighMatR;   // Offset: 0x4C, DWARF: 0xCE13C
      sceVu0FMATRIX *calfMatL;    // Offset: 0x50, DWARF: 0xCE167
      sceVu0FMATRIX *calfMatR;    // Offset: 0x54, DWARF: 0xCE191
      sceVu0FMATRIX *footMatL;    // Offset: 0x58, DWARF: 0xCE1BB
      sceVu0FMATRIX *footMatR;    // Offset: 0x5C, DWARF: 0xCE1E5
      sceVu0FMATRIX *toeMatL;     // Offset: 0x60, DWARF: 0xCE20F
      sceVu0FMATRIX *toeMatR;     // Offset: 0x64, DWARF: 0xCE238
      float thighLength[2];       // Offset: 0x68, DWARF: 0xCE261
      float shinLength[2];        // Offset: 0x70, DWARF: 0xCE28B
      signed int flg;             // Offset: 0x78, DWARF: 0xCE2B4
      signed int pad;             // Offset: 0x7C, DWARF: 0xCE2D4
      sceVu0FMATRIX footL;        // Offset: 0x80, DWARF: 0xCE2F4
      sceVu0FMATRIX footR;        // Offset: 0xC0, DWARF: 0xCE318
      sceVu0FMATRIX toeL;         // Offset: 0x100, DWARF: 0xCE33C
      sceVu0FMATRIX toeR;         // Offset: 0x140, DWARF: 0xCE35F
      float off_trans_toe[2][4];  // Offset: 0x180, DWARF: 0xCE382
      float thighLength_toe[2];   // Offset: 0x1A0, DWARF: 0xCE3AE
      float shinLength_toe[2];    // Offset: 0x1A8, DWARF: 0xCE3DC
      sceVu0FMATRIX board;        // Offset: 0x1B0, DWARF: 0xCE409
      sceVu0FMATRIX board_world;  // Offset: 0x1F0, DWARF: 0xCE42D
    } ikparam;                    // Offset: 0xB0, DWARF: 0x7CFEB
  } *sub_umd_ctrl;                // Offset: 0x285C, DWARF: 0x7FCC1
  // Size: 0x1A0, DWARF: 0x7C011
  struct {
    signed int type;              // Offset: 0x0, DWARF: 0x7C02D
    float power;                  // Offset: 0x4, DWARF: 0x7C04E
    float dir;                    // Offset: 0x8, DWARF: 0x7C070
    float cnt;                    // Offset: 0xC, DWARF: 0x7C090
    float head[4];                // Offset: 0x10, DWARF: 0x7C0B0
    float preHead[4];             // Offset: 0x20, DWARF: 0x7C0D3
    float tail_matrix[5][4][4];   // Offset: 0x30, DWARF: 0x7C0F9
    float g_vector[4];            // Offset: 0x170, DWARF: 0x7C123
    unsigned int *tailAddress[5]; // Offset: 0x180, DWARF: 0x7C14A
    signed int pad[3];            // Offset: 0x194, DWARF: 0x7C174
  } *sub_smd_ctrl;                // Offset: 0x2860, DWARF: 0x7FCEF
  float normal_light0[4]
      __attribute__((aligned(16))); // Offset: 0x2870, DWARF: 0x7FD1D
  float normal_light1[4];           // Offset: 0x2880, DWARF: 0x7FD49
  float normal_light2[4];           // Offset: 0x2890, DWARF: 0x7FD75
  float light_color0[4];            // Offset: 0x28A0, DWARF: 0x7FDA1
  float light_color1[4];            // Offset: 0x28B0, DWARF: 0x7FDCC
  float light_color2[4];            // Offset: 0x28C0, DWARF: 0x7FDF7
  float ambient[4];                 // Offset: 0x28D0, DWARF: 0x7FE22
  float shadow[4];                  // Offset: 0x28E0, DWARF: 0x7FE48
  sceVu0FMATRIX mat_base_lw;        // Offset: 0x28F0, DWARF: 0x7FE6D
  sceVu0FMATRIX mat_board;          // Offset: 0x2930, DWARF: 0x7FE97
  sceVu0FMATRIX mat_hand_l;         // Offset: 0x2970, DWARF: 0x7FEBF
  sceVu0FMATRIX mat_hand_r;         // Offset: 0x29B0, DWARF: 0x7FEE8
  sceVu0FMATRIX mat_head;           // Offset: 0x29F0, DWARF: 0x7FF11
} Disp;

// Size: 0x5640, DWARF: 0x78FAB, 0x1BFCC8
typedef struct Rider {
  // Size: 0x2A30, DWARF: 0x7F8F0, 0xBB1F1
  Disp disp; // Offset: 0x0, DWARF: 0x78FC6
  // Size: 0x2C00, DWARF: 0x7627B
  Ctrl ctrl; // Offset: 0x2A30, DWARF: 0x78FE9
  // char padding[48]; // This does not exist in the original struct, this is
  // added to match the expected offsets. Ctrl is supposed to be size 0x2C00.
  signed int pid;      // Offset: 0x5630, DWARF: 0x7900C
  signed int secondly; // Offset: 0x5634, DWARF: 0x7902C
} Rider;

// Size: 0x24, DWARF: 0x1336DF
typedef struct KeyConfig {
  signed int vibration; // Offset: 0x0, DWARF: 0x1336FA
  signed int spin_l;    // Offset: 0x4, DWARF: 0x133720
  signed int spin_r;    // Offset: 0x8, DWARF: 0x133743
  signed int stance;    // Offset: 0xC, DWARF: 0x133766
  signed int revert;    // Offset: 0x10, DWARF: 0x133789
  signed int grind;     // Offset: 0x14, DWARF: 0x1337AC
  signed int grab;      // Offset: 0x18, DWARF: 0x1337CE
  signed int jump;      // Offset: 0x1C, DWARF: 0x1337EF
  signed int flip;      // Offset: 0x20, DWARF: 0x133810
} KeyConfig;

// Size: 0x8, DWARF: 0x1338A8
typedef struct Volume {
  signed int se;  // Offset: 0x0, DWARF: 0x1338C4
  signed int bgm; // Offset: 0x4, DWARF: 0x1338E3
} Volume;

// Size: 0x48, DWARF: 0x136C73
typedef struct Bgm {
  signed int table[16]; // Offset: 0x0, DWARF: 0x136C8F
  signed int disable;   // Offset: 0x40, DWARF: 0x136CB3
  signed int random;    // Offset: 0x44, DWARF: 0x136CD7
} Bgm;

// Size: 0x114, DWARF: 0x13759C
typedef struct VnmdispOption {
  // Size: 0x24, DWARF: 0x1336DF
  KeyConfig key_config[2]; // Offset: 0x0, DWARF: 0x1375B8
  // Size: 0x30, DWARF: 0x1354B5
  Cheats enable; // Offset: 0x48, DWARF: 0x1375E1
  // Size: 0x30, DWARF: 0x1354B5
  Cheats cheats; // Offset: 0x78, DWARF: 0x137606
  // Size: 0x8, DWARF: 0x1338A8
  Volume volume;       // Offset: 0xA8, DWARF: 0x13762B
  char name[16];       // Offset: 0xB0, DWARF: 0x137650
  signed int divide;   // Offset: 0xC0, DWARF: 0x137673
  signed int tutorial; // Offset: 0xC4, DWARF: 0x137696
  // Size: 0x48, DWARF: 0x136C73
  Bgm bgm;            // Offset: 0xC8, DWARF: 0x1376BB
  unsigned int movie; // Offset: 0x110, DWARF: 0x1376DD
} VnmdispOption;

// Size: 0x8, DWARF: 0x135342
typedef struct DisplayState {
  unsigned int cnt; // Offset: 0x0, DWARF: 0x13535E
  char state;       // Offset: 0x4, DWARF: 0x13537E
} DisplayState;

// Size: 0x18, DWARF: 0x13B40E
typedef struct VnmdispModeEnv {
  signed int num_player;  // Offset: 0x0, DWARF: 0x13B42A
  signed int game_mode;   // Offset: 0x4, DWARF: 0x13B451
  signed int match_rule;  // Offset: 0x8, DWARF: 0x13B477
  signed int divide;      // Offset: 0xC, DWARF: 0x13B49E
  signed int handicap[2]; // Offset: 0x10, DWARF: 0x13B4C1
} VnmdispModeEnv;

// Size: 0x1C, DWARF: 0x133AA2
typedef struct CharacterParam {
  signed int ollie;     // Offset: 0x0, DWARF: 0x133ABE
  signed int spin;      // Offset: 0x4, DWARF: 0x133AE0
  signed int speed;     // Offset: 0x8, DWARF: 0x133B01
  signed int landing;   // Offset: 0xC, DWARF: 0x133B23
  signed int balance;   // Offset: 0x10, DWARF: 0x133B47
  signed int stability; // Offset: 0x14, DWARF: 0x133B6B
  signed int stance;    // Offset: 0x18, DWARF: 0x133B91
} CharacterParam;

// Size: 0x10, DWARF: 0x1395A3
typedef struct BoardParam {
  signed int speed;     // Offset: 0x0, DWARF: 0x1395BF
  signed int stability; // Offset: 0x4, DWARF: 0x1395E1
  signed int balance;   // Offset: 0x8, DWARF: 0x139607
  signed int turning;   // Offset: 0xC, DWARF: 0x13962B
} BoardParam;

// Size: 0x3C, DWARF: 0x13A391
typedef struct Character {
  signed int no;     // Offset: 0x0, DWARF: 0x13A3AD
  signed int player; // Offset: 0x4, DWARF: 0x13A3CC
  signed int wear;   // Offset: 0x8, DWARF: 0x13A3EF
  signed int board;  // Offset: 0xC, DWARF: 0x13A410
  // Size: 0x1C, DWARF: 0x133AA2
  CharacterParam chr_param; // Offset: 0x10, DWARF: 0x13A432
  // Size: 0x10, DWARF: 0x1395A3
  BoardParam brd_param; // Offset: 0x2C, DWARF: 0x13A45A
} Character;

// Size: 0x4, DWARF: 0x13B213
typedef struct VnmdispCrsEnv {
  signed int no; // Offset: 0x0, DWARF: 0x13B22F
} VnmdispCrsEnv;

// Size: 0xA0, DWARF: 0x138983
typedef struct VspenvGame {
  // Size: 0x4, DWARF: 0x13B213
  VnmdispCrsEnv course; // Offset: 0x0, DWARF: 0x13899F
  // Size: 0x3C, DWARF: 0x13A391
  Character character[2]; // Offset: 0x4, DWARF: 0x1389C4
  // Size: 0x18, DWARF: 0x13B40E
  VnmdispModeEnv mode; // Offset: 0x7C, DWARF: 0x1389EC
  signed int language; // Offset: 0x94, DWARF: 0x138A0F
  signed int ending;   // Offset: 0x98, DWARF: 0x138A34
  signed int bgm_no;   // Offset: 0x9C, DWARF: 0x138A57
} VspenvGame;

// Size: 0x74, DWARF: 0x139033
typedef struct CharacterState {
  signed int secret;          // Offset: 0x0, DWARF: 0x13904F
  unsigned int board;         // Offset: 0x4, DWARF: 0x139072
  unsigned int course;        // Offset: 0x8, DWARF: 0x139094
  signed int rem_point;       // Offset: 0xC, DWARF: 0x1390B7
  signed int old_brd_no;      // Offset: 0x10, DWARF: 0x1390DD
  signed int old_wear_no;     // Offset: 0x14, DWARF: 0x139104
  unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x13912C
  signed int soft[8];         // Offset: 0x38, DWARF: 0x139155
  // Size: 0x1C, DWARF: 0x133AA2
  CharacterParam parameter; // Offset: 0x58, DWARF: 0x139178
} CharacterState;

// Size: 0x18, DWARF: 0x13F575
typedef struct Clock {
  signed int year;   // Offset: 0x0, DWARF: 0x13F591
  signed int month;  // Offset: 0x4, DWARF: 0x13F5B2
  signed int day;    // Offset: 0x8, DWARF: 0x13F5D4
  signed int hour;   // Offset: 0xC, DWARF: 0x13F5F4
  signed int minute; // Offset: 0x10, DWARF: 0x13F615
  signed int second; // Offset: 0x14, DWARF: 0x13F638
} Clock;

// Size: 0xEC, DWARF: 0x13AB26
typedef struct CreateCharacter {
  // Size: 0x74, DWARF: 0x139033
  CharacterState character; // Offset: 0x0, DWARF: 0x13AB42
  // Size: 0x1C, DWARF: 0x133AA2
  CharacterParam init_param; // Offset: 0x74, DWARF: 0x13AB6A
  // Size: 0x18, DWARF: 0x13F575
  Clock clock;            // Offset: 0x90, DWARF: 0x13AB93
  char name[16];          // Offset: 0xA8, DWARF: 0x13ABB7
  signed int age;         // Offset: 0xB8, DWARF: 0x13ABDA
  signed int sex;         // Offset: 0xBC, DWARF: 0x13ABFA
  signed int face;        // Offset: 0xC0, DWARF: 0x13AC1A
  signed int hair;        // Offset: 0xC4, DWARF: 0x13AC3B
  signed int hair_color;  // Offset: 0xC8, DWARF: 0x13AC5C
  signed int body;        // Offset: 0xCC, DWARF: 0x13AC83
  signed int body_color;  // Offset: 0xD0, DWARF: 0x13ACA4
  signed int pants;       // Offset: 0xD4, DWARF: 0x13ACCB
  signed int pants_color; // Offset: 0xD8, DWARF: 0x13ACED
  signed int glove;       // Offset: 0xDC, DWARF: 0x13AD15
  signed int boots;       // Offset: 0xE0, DWARF: 0x13AD37
  signed int board_type;  // Offset: 0xE4, DWARF: 0x13AD59
  signed int trick_type;  // Offset: 0xE8, DWARF: 0x13AD80
} CreateCharacter;

// Size: 0x8, DWARF: 0x13F1DE
typedef struct CourseGap {
  unsigned long gap; // Offset: 0x0, DWARF: 0x13F1FA
} CourseGap;

// Size: 0xEF8, DWARF: 0x132F36
typedef struct VnmdispSecret {
  // Size: 0x74, DWARF: 0x139033
  CharacterState character[12]; // Offset: 0x0, DWARF: 0x132F51
  // Size: 0xEC, DWARF: 0x13AB26
  CreateCharacter create_character[10]; // Offset: 0x570, DWARF: 0x132F79
  // Size: 0x8, DWARF: 0x13F1DE
  CourseGap course[8];    // Offset: 0xEA8, DWARF: 0x132FA8
  signed int tour_round;  // Offset: 0xEE8, DWARF: 0x132FCD
  signed int old_char;    // Offset: 0xEEC, DWARF: 0x132FF4
  signed int first_clear; // Offset: 0xEF0, DWARF: 0x133019
} VnmdispSecret;

// Size: 0x4, DWARF: 0x132A37
typedef struct VnmdispBestTime {
  unsigned int time; // Offset: 0x0, DWARF: 0x132A52
} VnmdispBestTime;

// Size: 0x20, DWARF: 0x1393EA
typedef struct VspenvRecord {
  signed int chr_no;   // Offset: 0x0, DWARF: 0x139406
  unsigned long score; // Offset: 0x8, DWARF: 0x139429
  char name[16];       // Offset: 0x10, DWARF: 0x13944B
} VspenvRecord;

// Size: 0x10, DWARF: 0x133E14
typedef struct Tex {
  signed short tofs;      // Offset: 0x0, DWARF: 0x133E30
  signed short cofs;      // Offset: 0x2, DWARF: 0x133E51
  signed short width;     // Offset: 0x4, DWARF: 0x133E72
  signed short height;    // Offset: 0x6, DWARF: 0x133E94
  signed short tw;        // Offset: 0x8, DWARF: 0x133EB7
  signed short th;        // Offset: 0xA, DWARF: 0x133ED6
  signed short image_bit; // Offset: 0xC, DWARF: 0x133EF5
  signed short clut_bit;  // Offset: 0xE, DWARF: 0x133F1B
} Tex;

// Size: 0x20, DWARF: 0x134D25
typedef struct MdlData {
  float pos[4]; // Offset: 0x0, DWARF: 0x134D41
  float rot[4]; // Offset: 0x10, DWARF: 0x134D63
} MdlData;

// Size: 0x10, DWARF: 0x1350D5
typedef struct PosAddress {
  unsigned int type; // Offset: 0x0, DWARF: 0x1350F1
  float frame;       // Offset: 0x4, DWARF: 0x135112
  signed short flg;  // Offset: 0x8, DWARF: 0x135134
  signed short non;  // Offset: 0xA, DWARF: 0x135154
  float *data[4];    // Offset: 0xC, DWARF: 0x135174
} PosAddress;

// Size: 0xF0, DWARF: 0x133093
typedef struct Seq {
  unsigned int model_id;    // Offset: 0x0, DWARF: 0x1330AE
  signed int loop;          // Offset: 0x4, DWARF: 0x1330D3
  signed int mode;          // Offset: 0x8, DWARF: 0x1330F4
  signed int write_flg;     // Offset: 0xC, DWARF: 0x133115
  signed int now_local_id;  // Offset: 0x10, DWARF: 0x13313B
  signed int now_top_id;    // Offset: 0x14, DWARF: 0x133164
  signed int next_local_id; // Offset: 0x18, DWARF: 0x13318B
  signed int next_top_id;   // Offset: 0x1C, DWARF: 0x1331B5
  // Size: 0x20, DWARF: 0x134D25
  MdlData *mdl_data; // Offset: 0x20, DWARF: 0x1331DD
  float now_frame;   // Offset: 0x24, DWARF: 0x133207
  float next_frame;  // Offset: 0x28, DWARF: 0x13322D
  float ratio;       // Offset: 0x2C, DWARF: 0x133254
  // Size: 0x10, DWARF: 0x1350D5
  PosAddress *now_pos_address; // Offset: 0x30, DWARF: 0x133276
  // Size: 0x10, DWARF: 0x1350D5
  PosAddress *now_rot_address; // Offset: 0x34, DWARF: 0x1332A7
  // Size: 0x10, DWARF: 0x1350D5
  PosAddress *next_pos_address; // Offset: 0x38, DWARF: 0x1332D8
  // Size: 0x10, DWARF: 0x1350D5
  PosAddress *next_rot_address; // Offset: 0x3C, DWARF: 0x13330A
  float nowDir[4];              // Offset: 0x40, DWARF: 0x13333C
  float nowTrans[4];            // Offset: 0x50, DWARF: 0x133361
  float now_matrix[4][4];       // Offset: 0x60, DWARF: 0x133388
  float pos[4];                 // Offset: 0xA0, DWARF: 0x1333B1
  float quat[4];                // Offset: 0xB0, DWARF: 0x1333D3
  float pre_pos[4];             // Offset: 0xC0, DWARF: 0x1333F6
  float pre_rot[4];             // Offset: 0xD0, DWARF: 0x13341C
  signed int startVertexIdx;    // Offset: 0xE0, DWARF: 0x133442
  signed int vertexLoopFlg;     // Offset: 0xE4, DWARF: 0x13346D
  signed int pad[2];            // Offset: 0xE8, DWARF: 0x133497
} Seq;

// Size: 0x230, DWARF: 0x135B6A
typedef struct IkParam {
  float rot[4];              // Offset: 0x0, DWARF: 0x135B86
  float trans[4];            // Offset: 0x10, DWARF: 0x135BA8
  float off_trans[2][4];     // Offset: 0x20, DWARF: 0x135BCC
  float *boardMat[4][4];     // Offset: 0x40, DWARF: 0x135BF4
  float *board_local[4][4];  // Offset: 0x44, DWARF: 0x135C1E
  float *thighMatL[4][4];    // Offset: 0x48, DWARF: 0x135C4B
  float *thighMatR[4][4];    // Offset: 0x4C, DWARF: 0x135C76
  float *calfMatL[4][4];     // Offset: 0x50, DWARF: 0x135CA1
  float *calfMatR[4][4];     // Offset: 0x54, DWARF: 0x135CCB
  float *footMatL[4][4];     // Offset: 0x58, DWARF: 0x135CF5
  float *footMatR[4][4];     // Offset: 0x5C, DWARF: 0x135D1F
  float *toeMatL[4][4];      // Offset: 0x60, DWARF: 0x135D49
  float *toeMatR[4][4];      // Offset: 0x64, DWARF: 0x135D72
  float thighLength[2];      // Offset: 0x68, DWARF: 0x135D9B
  float shinLength[2];       // Offset: 0x70, DWARF: 0x135DC5
  signed int flg;            // Offset: 0x78, DWARF: 0x135DEE
  signed int pad;            // Offset: 0x7C, DWARF: 0x135E0E
  float footL[4][4];         // Offset: 0x80, DWARF: 0x135E2E
  float footR[4][4];         // Offset: 0xC0, DWARF: 0x135E52
  float toeL[4][4];          // Offset: 0x100, DWARF: 0x135E76
  float toeR[4][4];          // Offset: 0x140, DWARF: 0x135E99
  float off_trans_toe[2][4]; // Offset: 0x180, DWARF: 0x135EBC
  float thighLength_toe[2];  // Offset: 0x1A0, DWARF: 0x135EE8
  float shinLength_toe[2];   // Offset: 0x1A8, DWARF: 0x135F16
  float board[4][4];         // Offset: 0x1B0, DWARF: 0x135F43
  float board_world[4][4];   // Offset: 0x1F0, DWARF: 0x135F67
} IkParam;

// Size: 0x2E0, DWARF: 0x132B0C
typedef struct ModelCtrl {
  float rot[4];         // Offset: 0x0, DWARF: 0x132B27
  float trans[4];       // Offset: 0x10, DWARF: 0x132B49
  float scale[4];       // Offset: 0x20, DWARF: 0x132B6D
  float matrix[4][4];   // Offset: 0x30, DWARF: 0x132B91
  float revision[4][4]; // Offset: 0x70, DWARF: 0x132BB6
  // Size: 0x230, DWARF: 0x135B6A
  IkParam ikparam; // Offset: 0xB0, DWARF: 0x132BDD
} ModelCtrl;

// Size: 0x1A0, DWARF: 0x13350A
typedef struct SCtrl {
  signed int type;              // Offset: 0x0, DWARF: 0x133525
  float power;                  // Offset: 0x4, DWARF: 0x133546
  float dir;                    // Offset: 0x8, DWARF: 0x133568
  float cnt;                    // Offset: 0xC, DWARF: 0x133588
  float head[4];                // Offset: 0x10, DWARF: 0x1335A8
  float preHead[4];             // Offset: 0x20, DWARF: 0x1335CB
  float tail_matrix[5][4][4];   // Offset: 0x30, DWARF: 0x1335F1
  float g_vector[4];            // Offset: 0x170, DWARF: 0x13361B
  unsigned int *tailAddress[5]; // Offset: 0x180, DWARF: 0x133642
  signed int pad[3];            // Offset: 0x194, DWARF: 0x13366C
} SCtrl;

// Size: 0x4B0, DWARF: 0x138E8E
typedef struct VnmdispSoftData {
  unsigned int *link; // Offset: 0x0, DWARF: 0x138EAA
  __int128 *umd;      // Offset: 0x4, DWARF: 0x138ECE
  __int128 *smd;      // Offset: 0x8, DWARF: 0x138EF1
  unsigned int *utd;  // Offset: 0xC, DWARF: 0x138F14
  // Size: 0x10, DWARF: 0x133E14
  Tex *tex; // Offset: 0x10, DWARF: 0x138F37
  // Size: 0xF0, DWARF: 0x133093
  Seq *seq;            // Offset: 0x14, DWARF: 0x138F5C
  signed int block;    // Offset: 0x18, DWARF: 0x138F81
  unsigned int *frame; // Offset: 0x1C, DWARF: 0x138FA3
  signed int res;      // Offset: 0x20, DWARF: 0x138FC8
  // Size: 0x2E0, DWARF: 0x132B0C
  ModelCtrl ctrl; // Offset: 0x30, DWARF: 0x138FE8
  // Size: 0x1A0, DWARF: 0x13350A
  SCtrl sctrl; // Offset: 0x310, DWARF: 0x13900B
} VnmdispSoftData;

// Size: 0x20, DWARF: 0x1379B9
typedef struct VnmdispTexData {
  unsigned int *utd; // Offset: 0x0, DWARF: 0x1379D5
  // Size: 0x10, DWARF: 0x133E14
  Tex *tex;            // Offset: 0x4, DWARF: 0x1379F8
  signed int ntex;     // Offset: 0x8, DWARF: 0x137A1D
  signed int offset;   // Offset: 0xC, DWARF: 0x137A3E
  signed int block;    // Offset: 0x10, DWARF: 0x137A61
  unsigned int *frame; // Offset: 0x14, DWARF: 0x137A83
  signed int res[2];   // Offset: 0x18, DWARF: 0x137AA8
} VnmdispTexData;

// Size: 0x500, DWARF: 0x132D63
typedef struct VnmLoadGame2d {
  // Size: 0x20, DWARF: 0x1379B9
  VnmdispTexData game; // Offset: 0x0, DWARF: 0x132D7E
  // Size: 0x20, DWARF: 0x1379B9
  VnmdispTexData result; // Offset: 0x20, DWARF: 0x132DA1
  // Size: 0x4B0, DWARF: 0x138E8E
  VnmdispSoftData soft;      // Offset: 0x40, DWARF: 0x132DC6
  __int128 *board_umd;       // Offset: 0x4F0, DWARF: 0x132DE9
  unsigned int *board_utd;   // Offset: 0x4F4, DWARF: 0x132E12
  unsigned int *ayboard_utd; // Offset: 0x4F8, DWARF: 0x132E3B
  // Size: 0x10, DWARF: 0x133E14
  Tex *board_tex; // Offset: 0x4FC, DWARF: 0x132E66
} VnmLoadGame2d;

// Size: 0x5C, DWARF: 0x13C2A3
typedef struct VspModeData {
  // DWARF: 0x138DCB
  FlowMode flow_mode;           // Offset: 0x0, DWARF: 0x13C2BF
  unsigned int game_time_limit; // Offset: 0x4, DWARF: 0x13C2E7
  unsigned int game_time;       // Offset: 0x8, DWARF: 0x13C313
  unsigned int game_count;      // Offset: 0xC, DWARF: 0x13C339
  unsigned int realtime_count;  // Offset: 0x10, DWARF: 0x13C360
  unsigned int flow_count;      // Offset: 0x14, DWARF: 0x13C38B
  signed int can_pause;         // Offset: 0x18, DWARF: 0x13C3B2
  signed int modnum;            // Offset: 0x1C, DWARF: 0x13C3D8
  signed int bgm_no;            // Offset: 0x20, DWARF: 0x13C3FB
  signed int replay_speed;      // Offset: 0x24, DWARF: 0x13C41E
  signed int num_window;        // Offset: 0x28, DWARF: 0x13C447
  signed int horse_pid;         // Offset: 0x2C, DWARF: 0x13C46E
  signed int end_sliding;       // Offset: 0x30, DWARF: 0x13C494
  signed int pause;             // Offset: 0x34, DWARF: 0x13C4BC
  signed int pre_pause;         // Offset: 0x38, DWARF: 0x13C4DE
  // DWARF: 0x138DCB
  FlowMode next_flow_mode; // Offset: 0x3C, DWARF: 0x13C504
  // DWARF: 0x13B8DD
  Restart restart;              // Offset: 0x40, DWARF: 0x13C531
  signed int next_modnum;       // Offset: 0x44, DWARF: 0x13C557
  signed int next_bgm_no;       // Offset: 0x48, DWARF: 0x13C57F
  signed int fade;              // Offset: 0x4C, DWARF: 0x13C5A7
  signed int to_end_sliding;    // Offset: 0x50, DWARF: 0x13C5C8
  signed int next_replay_speed; // Offset: 0x54, DWARF: 0x13C5F3
  signed int next_pause;        // Offset: 0x58, DWARF: 0x13C621
} VspModeData;

// Size: 0x48, DWARF: 0x138326
typedef struct VnmDispList {
  unsigned int cnt; // Offset: 0x0, DWARF: 0x138342
  char state;       // Offset: 0x4, DWARF: 0x138362
  char top;         // Offset: 0x5, DWARF: 0x138384
  char res[2];      // Offset: 0x6, DWARF: 0x1383A4
  float pos[16];    // Offset: 0x8, DWARF: 0x1383C6
} VnmDispList;

// Size: 0x10, DWARF: 0x13A486
typedef struct VnmdispTrickPtsDraw {
  signed int single;    // Offset: 0x0, DWARF: 0x13A4A2
  signed int total;     // Offset: 0x4, DWARF: 0x13A4C5
  signed int freeride;  // Offset: 0x8, DWARF: 0x13A4E7
  signed int link_rate; // Offset: 0xC, DWARF: 0x13A50C
} VnmdispTrickPtsDraw;

// Size: 0x10, DWARF: 0x13B859
typedef struct VnmdispBalanceInfo {
  signed int state;  // Offset: 0x0, DWARF: 0x13B875
  float per;         // Offset: 0x4, DWARF: 0x13B897
  signed int res[2]; // Offset: 0x8, DWARF: 0x13B8B7
} VnmdispBalanceInfo;

// Size: 0x4, DWARF: 0x13B06C
typedef struct Bar {
  char num;    // Offset: 0x0, DWARF: 0x13B088
  char charge; // Offset: 0x1, DWARF: 0x13B0A8
  char left;   // Offset: 0x2, DWARF: 0x13B0CB
  char res;    // Offset: 0x3, DWARF: 0x13B0EC
} Bar;

// Size: 0x4, DWARF: 0x13BEDC
typedef struct Boost {
  char num;    // Offset: 0x0, DWARF: 0x13BEF8
  char charge; // Offset: 0x1, DWARF: 0x13BF18
  char res[2]; // Offset: 0x2, DWARF: 0x13BF3B
} Boost;

// Size: 0x10, DWARF: 0x13C73E
typedef struct Match {
  // Size: 0x4, DWARF: 0x13BEDC
  Boost boost;       // Offset: 0x0, DWARF: 0x13C75A
  signed int push;   // Offset: 0x4, DWARF: 0x13C77E
  signed int res[2]; // Offset: 0x8, DWARF: 0x13C79F
} Match;

// Size: 0x38, DWARF: 0x134E8C
typedef struct VspDispEnvChar {
  // Size: 0x10, DWARF: 0x13A486
  VnmdispTrickPtsDraw points; // Offset: 0x0, DWARF: 0x134EA8
  // Size: 0x4, DWARF: 0x13B06C
  Bar bar; // Offset: 0x10, DWARF: 0x134ECD
  // Size: 0x10, DWARF: 0x13B859
  VnmdispBalanceInfo balance; // Offset: 0x14, DWARF: 0x134EEF
  // Size: 0x10, DWARF: 0x13C73E
  Match match;     // Offset: 0x24, DWARF: 0x134F15
  signed int rank; // Offset: 0x34, DWARF: 0x134F39
} VspDispEnvChar;

// Size: 0x4, DWARF: 0x139F66
typedef struct Word {
  char id;     // Offset: 0x0, DWARF: 0x139F82
  char value;  // Offset: 0x1, DWARF: 0x139FA1
  char res[2]; // Offset: 0x2, DWARF: 0x139FC3
} Word;

// Size: 0x4C, DWARF: 0x137703
typedef struct List {
  // Size: 0x4, DWARF: 0x139F66
  Word word[16];     // Offset: 0x0, DWARF: 0x13771F
  float length;      // Offset: 0x40, DWARF: 0x137742
  signed int res[2]; // Offset: 0x44, DWARF: 0x137765
} List;

// Size: 0x20, DWARF: 0x13647D
typedef struct TrickWord {
  unsigned int cnt;  // Offset: 0x0, DWARF: 0x136499
  char state;        // Offset: 0x4, DWARF: 0x1364B9
  char str;          // Offset: 0x5, DWARF: 0x1364DB
  char res[2];       // Offset: 0x6, DWARF: 0x1364FB
  float pos[2];      // Offset: 0x8, DWARF: 0x13651D
  sceVu0FVECTOR add; // Offset: 0x10, DWARF: 0x13653F
} TrickWord;

// Size: 0x210, DWARF: 0x13743C
typedef struct VnmdispTrickPtsInfo {
  unsigned int cnt; // Offset: 0x0, DWARF: 0x137458
  char state;       // Offset: 0x4, DWARF: 0x137478
  char num;         // Offset: 0x5, DWARF: 0x13749A
  // Size: 0x20, DWARF: 0x13647D
  TrickWord word[16]; // Offset: 0x10, DWARF: 0x1374BA
} VnmdispTrickPtsInfo;

// Size: 0x4, DWARF: 0x138B98
typedef struct VnmdispLevelMesInfo {
  char type;     // Offset: 0x0, DWARF: 0x138BB4
  char num;      // Offset: 0x1, DWARF: 0x138BD5
  char value[2]; // Offset: 0x2, DWARF: 0x138BF5
} VnmdispLevelMesInfo;

// Size: 0x10, DWARF: 0x1398B6
typedef struct VnmdispCareerItem {
  signed int type;     // Offset: 0x0, DWARF: 0x1398D2
  signed int num;      // Offset: 0x4, DWARF: 0x1398F3
  signed int value[2]; // Offset: 0x8, DWARF: 0x139913
} VnmdispCareerItem;

// Size: 0x810, DWARF: 0x136BAA
typedef struct VnmdispTrickNameInfo {
  unsigned int cnt; // Offset: 0x0, DWARF: 0x136BC6
  char state;       // Offset: 0x4, DWARF: 0x136BE6
  char num;         // Offset: 0x5, DWARF: 0x136C08
  // Size: 0x20, DWARF: 0x13647D
  TrickWord word[64]; // Offset: 0x10, DWARF: 0x136C28
} VnmdispTrickNameInfo;

// Size: 0x20, DWARF: 0x140E3C
typedef struct PadState {
  signed int id;         // Offset: 0x0, DWARF: 0x140E59
  unsigned int now;      // Offset: 0x4, DWARF: 0x140E78
  unsigned int status;   // Offset: 0x8, DWARF: 0x140E98
  unsigned int press;    // Offset: 0xC, DWARF: 0x140EBB
  signed char right_h;   // Offset: 0x10, DWARF: 0x140EDD
  signed char right_v;   // Offset: 0x11, DWARF: 0x140F01
  signed char left_h;    // Offset: 0x12, DWARF: 0x140F25
  signed char left_v;    // Offset: 0x13, DWARF: 0x140F48
  unsigned char l_right; // Offset: 0x14, DWARF: 0x140F6B
  unsigned char l_left;  // Offset: 0x15, DWARF: 0x140F8F
  unsigned char l_up;    // Offset: 0x16, DWARF: 0x140FB2
  unsigned char l_down;  // Offset: 0x17, DWARF: 0x140FD3
  unsigned char r_up;    // Offset: 0x18, DWARF: 0x140FF6
  unsigned char r_right; // Offset: 0x19, DWARF: 0x141017
  unsigned char r_down;  // Offset: 0x1A, DWARF: 0x14103B
  unsigned char r_left;  // Offset: 0x1B, DWARF: 0x14105E
  unsigned char r_1;     // Offset: 0x1C, DWARF: 0x141081
  unsigned char l_1;     // Offset: 0x1D, DWARF: 0x1410A1
  unsigned char r_2;     // Offset: 0x1E, DWARF: 0x1410C1
  unsigned char l_2;     // Offset: 0x1F, DWARF: 0x1410E1
} PadState;

// Size: 0x60, DWARF: 0x1358D9
typedef struct VgmsysPad {
  // Size: 0x20, DWARF: 0x140E3C
  PadState now; // Offset: 0x0, DWARF: 0x1358F5
  // Size: 0x20, DWARF: 0x140E3C
  PadState old;      // Offset: 0x20, DWARF: 0x135917
  unsigned int port; // Offset: 0x40, DWARF: 0x135939
  unsigned int slot; // Offset: 0x44, DWARF: 0x13595A
  unsigned int mode; // Offset: 0x48, DWARF: 0x13597B
  unsigned int trg;  // Offset: 0x4C, DWARF: 0x13599C
  unsigned int rev;  // Offset: 0x50, DWARF: 0x1359BC
  unsigned int cnt;  // Offset: 0x54, DWARF: 0x1359DC
  unsigned int rep;  // Offset: 0x58, DWARF: 0x1359FC
  signed int state;  // Offset: 0x5C, DWARF: 0x135A1C
} VgmsysPad;

// Size: 0x30, DWARF: 0x13ED2C
typedef struct Dual {
  float pos[4]; // Offset: 0x0, DWARF: 0x13ED48
  // Size: 0x10, DWARF: 0x133E14
  Tex *data; // Offset: 0x10, DWARF: 0x13ED6A
  // Size: 0x60, DWARF: 0x1358D9
  VgmsysPad *ope;    // Offset: 0x14, DWARF: 0x13ED90
  signed int abe;    // Offset: 0x18, DWARF: 0x13EDB5
  float ratio;       // Offset: 0x1C, DWARF: 0x13EDD5
  signed int res[2]; // Offset: 0x20, DWARF: 0x13EDF7
} Dual;

// Size: 0x10, DWARF: 0x132956
typedef struct VgmsysGifPkt {
  unsigned int *pCurrent; // Offset: 0x0, DWARF: 0x132971
  __int128 *pBase;        // Offset: 0x4, DWARF: 0x132999
  __int128 *pDmaTag;      // Offset: 0x8, DWARF: 0x1329BE
  unsigned long *pGifTag; // Offset: 0xC, DWARF: 0x1329E5
} VgmsysGifPkt;

// Size: 0x8, DWARF: 0x134CA2
typedef struct Comb {
  float ofs;   // Offset: 0x0, DWARF: 0x134CBE
  char line;   // Offset: 0x4, DWARF: 0x134CDE
  char res[3]; // Offset: 0x5, DWARF: 0x134CFF
} Comb;

// Size: 0x20, DWARF: 0x138C1D
typedef struct VspDispEnv {
  signed int mode;      // Offset: 0x0, DWARF: 0x138C39
  signed int time_left; // Offset: 0x4, DWARF: 0x138C5A
  signed int pass_time; // Offset: 0x8, DWARF: 0x138C80
  signed int div;       // Offset: 0xC, DWARF: 0x138CA6
  signed int div_exp;   // Offset: 0x10, DWARF: 0x138CC6
  signed int res[3];    // Offset: 0x14, DWARF: 0x138CEA
} VspDispEnv;

// Size: 0x10, DWARF: 0x13C151
typedef struct Spin {
  signed int rewind; // Offset: 0x0, DWARF: 0x13C16D
  signed int cab;    // Offset: 0x4, DWARF: 0x13C190
  signed int value;  // Offset: 0x8, DWARF: 0x13C1B0
  signed int first;  // Offset: 0xC, DWARF: 0x13C1D2
} Spin;

// Size: 0x10, DWARF: 0x13F244
typedef struct QueCol {
  signed int state;  // Offset: 0x0, DWARF: 0x13F260
  signed int cnt;    // Offset: 0x4, DWARF: 0x13F282
  signed int land;   // Offset: 0x8, DWARF: 0x13F2A2
  signed int flight; // Offset: 0xC, DWARF: 0x13F2C3
} QueCol;

// Size: 0x40, DWARF: 0x140042
typedef struct TrickQue {
  signed int type;     // Offset: 0x0, DWARF: 0x14005F
  signed int sp_type;  // Offset: 0x4, DWARF: 0x140080
  signed int num;      // Offset: 0x8, DWARF: 0x1400A4
  signed int link;     // Offset: 0xC, DWARF: 0x1400C4
  signed int jump;     // Offset: 0x10, DWARF: 0x1400E5
  signed int fakie;    // Offset: 0x14, DWARF: 0x140106
  signed int late;     // Offset: 0x18, DWARF: 0x140128
  signed int disaster; // Offset: 0x1C, DWARF: 0x140149
  // Size: 0x10, DWARF: 0x13C151
  Spin spin; // Offset: 0x20, DWARF: 0x14016E
  // Size: 0x10, DWARF: 0x13F244
  QueCol col; // Offset: 0x30, DWARF: 0x140191
} TrickQue;

// Size: 0x810, DWARF: 0x132C07
typedef struct CombInfo // Same as VnmtrickInfo (0x223E39)
{
  // Size: 0x40, DWARF: 0x140042
  TrickQue que[32];  // Offset: 0x0, DWARF: 0x132C22
  signed int land;   // Offset: 0x800, DWARF: 0x132C44
  signed int flight; // Offset: 0x804, DWARF: 0x132C65
  signed int fakie;  // Offset: 0x808, DWARF: 0x132C88
  char entry_id;     // Offset: 0x80C, DWARF: 0x132CAA
  char spin_id;      // Offset: 0x80D, DWARF: 0x132CCF
  char omit_id;      // Offset: 0x80E, DWARF: 0x132CF3
  char link_id;      // Offset: 0x80F, DWARF: 0x132D17
} CombInfo;

// Size: 0x824, DWARF: 0x13471A
typedef struct VspDispResult {
  signed int rank;          // Offset: 0x0, DWARF: 0x134736
  signed int trick_landing; // Offset: 0x4, DWARF: 0x134757
  signed int comb_num;      // Offset: 0x8, DWARF: 0x134781
  signed int comb_points;   // Offset: 0xC, DWARF: 0x1347A6
  unsigned int comp_time;   // Offset: 0x10, DWARF: 0x1347CE
  // Size: 0x810, DWARF: 0x132C07
  CombInfo comb_info; // Offset: 0x14, DWARF: 0x1347F4
} VspDispResult;

// Size: 0x10, DWARF: 0x132E95
typedef struct VspDispVsScore {
  signed int win;  // Offset: 0x0, DWARF: 0x132EB0
  signed int lose; // Offset: 0x4, DWARF: 0x132ED0
  signed int draw; // Offset: 0x8, DWARF: 0x132EF1
  signed int res;  // Offset: 0xC, DWARF: 0x132F12
} VspDispVsScore;

// Size: 0x10, DWARF: 0x135A42
typedef struct Info {
  float start;        // Offset: 0x0, DWARF: 0x135A5E
  float length;       // Offset: 0x4, DWARF: 0x135A80
  signed short frame; // Offset: 0x8, DWARF: 0x135AA3
  char dir;           // Offset: 0xA, DWARF: 0x135AC5
  char vel;           // Offset: 0xB, DWARF: 0x135AE5
  char lag;           // Offset: 0xC, DWARF: 0x135B05
  char num;           // Offset: 0xD, DWARF: 0x135B25
  signed short skip;  // Offset: 0xE, DWARF: 0x135B45
} Info;

// Size: 0x10, DWARF: 0x1391C8
typedef struct DispInfo {
  float width;     // Offset: 0x0, DWARF: 0x1391E4
  float font;      // Offset: 0x4, DWARF: 0x139206
  signed int line; // Offset: 0x8, DWARF: 0x139227
  signed int res;  // Offset: 0xC, DWARF: 0x139248
} DispInfo;

// Size: 0x60, DWARF: 0x13661E
typedef struct FontOption {
  signed int col[4][4]; // Offset: 0x0, DWARF: 0x13663A
  signed short type;    // Offset: 0x40, DWARF: 0x13665C
  float width;          // Offset: 0x44, DWARF: 0x13667D
  float height;         // Offset: 0x48, DWARF: 0x13669F
  signed short pack;    // Offset: 0x4C, DWARF: 0x1366C2
  signed short shadow;  // Offset: 0x4E, DWARF: 0x1366E3
  signed short bil;     // Offset: 0x50, DWARF: 0x136706
} FontOption;

// Size: 0x20, DWARF: 0x134B98
typedef struct Fade {
  signed int cnt;    // Offset: 0x0, DWARF: 0x134BB4
  signed int flag;   // Offset: 0x4, DWARF: 0x134BD4
  signed int type;   // Offset: 0x8, DWARF: 0x134BF5
  signed int col;    // Offset: 0xC, DWARF: 0x134C16
  signed int max;    // Offset: 0x10, DWARF: 0x134C36
  signed int res[3]; // Offset: 0x14, DWARF: 0x134C56
} Fade;

// Size: 0x40, DWARF: 0x13519E
typedef struct Key {
  sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x1351BA
  // Size: 0x10, DWARF: 0x133E14
  Tex *data;           // Offset: 0x10, DWARF: 0x1351DC
  signed int button;   // Offset: 0x14, DWARF: 0x135202
  signed int message;  // Offset: 0x18, DWARF: 0x135225
  signed int cnt;      // Offset: 0x1C, DWARF: 0x135249
  signed int center;   // Offset: 0x20, DWARF: 0x135269
  signed int language; // Offset: 0x24, DWARF: 0x13528C
  signed int mode;     // Offset: 0x28, DWARF: 0x1352B1
  signed int res[2];   // Offset: 0x2C, DWARF: 0x1352D2
} Key;

// Size: 0x10, DWARF: 0x13C672
typedef struct TexOption {
  signed int sprite; // Offset: 0x0, DWARF: 0x13C68E
  signed int bil;    // Offset: 0x4, DWARF: 0x13C6B1
  float width;       // Offset: 0x8, DWARF: 0x13C6D1
  float height;      // Offset: 0xC, DWARF: 0x13C6F3
} TexOption;

// Size: 0xB0, DWARF: 0x13F356
typedef struct DispTex {
  // Size: 0x10, DWARF: 0x133E14
  Tex *data;              // Offset: 0x0, DWARF: 0x13F372
  signed int tex_size[2]; // Offset: 0x4, DWARF: 0x13F398
  signed int tex_uv[2];   // Offset: 0xC, DWARF: 0x13F3BF
  sceVu0FMATRIX vertex;   // Offset: 0x20, DWARF: 0x13F3E4
  signed int col[4][4];   // Offset: 0x60, DWARF: 0x13F409
  // Size: 0x10, DWARF: 0x13C672
  TexOption option; // Offset: 0xA0, DWARF: 0x13F42B
} DispTex;

// Size: 0x50, DWARF: 0x13ADF6
typedef struct Meter {
  float pos[4];         // Offset: 0x0, DWARF: 0x13AE12
  signed int col[2][4]; // Offset: 0x10, DWARF: 0x13AE34
  float ratio;          // Offset: 0x30, DWARF: 0x13AE56
  float per;            // Offset: 0x34, DWARF: 0x13AE78
  signed int type;      // Offset: 0x38, DWARF: 0x13AE98
  signed int frame;     // Offset: 0x3C, DWARF: 0x13AEB9
  signed int shadow;    // Offset: 0x40, DWARF: 0x13AEDB
  signed int div;       // Offset: 0x44, DWARF: 0x13AEFE
  float div_per;        // Offset: 0x48, DWARF: 0x13AF1E
  signed int res;       // Offset: 0x4C, DWARF: 0x13AF42
} Meter;

// Size: 0x90, DWARF: 0x140CBB
typedef struct Poly {
  float vertex[4][4];   // Offset: 0x0, DWARF: 0x140CD8
  signed int col[4][4]; // Offset: 0x40, DWARF: 0x140CFD
  // Size: 0x10, DWARF: 0x13C672
  TexOption option; // Offset: 0x80, DWARF: 0x140D1F
} Poly;

// Size: 0x70, DWARF: 0x137FF4
typedef struct Point {
  float pos[4];         // Offset: 0x0, DWARF: 0x138010
  signed int col[4][4]; // Offset: 0x10, DWARF: 0x138032
  signed int point;     // Offset: 0x50, DWARF: 0x138054
  signed int type;      // Offset: 0x54, DWARF: 0x138076
  signed int size[2];   // Offset: 0x58, DWARF: 0x138097
  signed int flat;      // Offset: 0x60, DWARF: 0x1380BA
  signed int base;      // Offset: 0x64, DWARF: 0x1380DB
  signed int language;  // Offset: 0x68, DWARF: 0x1380FC
  signed int res;       // Offset: 0x6C, DWARF: 0x138121
} Point;

// Size: 0x30, DWARF: 0x139290
typedef struct Allow {
  float pos[4]; // Offset: 0x0, DWARF: 0x1392AC
  // Size: 0x10, DWARF: 0x133E14
  Tex *data;       // Offset: 0x10, DWARF: 0x1392CE
  signed int abe;  // Offset: 0x14, DWARF: 0x1392F4
  signed int type; // Offset: 0x18, DWARF: 0x139314
  float width;     // Offset: 0x1C, DWARF: 0x139335
  float height;    // Offset: 0x20, DWARF: 0x139357
} Allow;

// Size: 0x70, DWARF: 0x136340
typedef struct DispBar {
  sceVu0FVECTOR pos;    // Offset: 0x0, DWARF: 0x13635C
  signed int col[4][4]; // Offset: 0x10, DWARF: 0x13637E
  // Size: 0x10, DWARF: 0x13C672
  TexOption option;  // Offset: 0x50, DWARF: 0x1363A0
  signed int type;   // Offset: 0x60, DWARF: 0x1363C5
  signed int res[3]; // Offset: 0x64, DWARF: 0x1363E6
} DispBar;

// Size: 0x40, DWARF: 0x13A082
typedef struct DispBalance {
  sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x13A09E
  // Size: 0x10, DWARF: 0x133E14
  Tex *data;           // Offset: 0x10, DWARF: 0x13A0C0
  sceVu0FVECTOR ratio; // Offset: 0x20, DWARF: 0x13A0E6
  signed int abe;      // Offset: 0x30, DWARF: 0x13A10A
  signed int type;     // Offset: 0x34, DWARF: 0x13A12A
  float per;           // Offset: 0x38, DWARF: 0x13A14B
  signed int res;      // Offset: 0x3C, DWARF: 0x13A16B
} DispBalance;

// Size: 0x70, DWARF: 0x13BC8D
typedef struct Ice {
  sceVu0FVECTOR pos; // Offset: 0x0, DWARF: 0x13BCA9
  // Size: 0x10, DWARF: 0x133E14
  Tex *data; // Offset: 0x10, DWARF: 0x13BCCB
  signed int col[4][4]
      __attribute__((aligned(16))); // Offset: 0x20, DWARF: 0x13BCF1
  float width;                      // Offset: 0x60, DWARF: 0x13BD13
  float height;                     // Offset: 0x64, DWARF: 0x13BD35
  signed int pack;                  // Offset: 0x68, DWARF: 0x13BD58
  signed int res;                   // Offset: 0x6C, DWARF: 0x13BD79
} Ice;

// Size: 0x30, DWARF: 0x136A94
typedef struct Check {
  float pos[4]; // Offset: 0x0, DWARF: 0x136AB0
  // Size: 0x10, DWARF: 0x133E14
  Tex *data;         // Offset: 0x10, DWARF: 0x136AD2
  signed int cnt;    // Offset: 0x14, DWARF: 0x136AF8
  signed int res[3]; // Offset: 0x18, DWARF: 0x136B18
} Check;

// Size: 0x60, DWARF: 0x1370BD
typedef struct Time {
  float pos[4];         // Offset: 0x0, DWARF: 0x1370D9
  signed int col[4][4]; // Offset: 0x10, DWARF: 0x1370FB
  signed int frame;     // Offset: 0x50, DWARF: 0x13711D
  signed int type;      // Offset: 0x54, DWARF: 0x13713F
  signed int size[2];   // Offset: 0x58, DWARF: 0x137160
} Time;

static char *ul_performance_name[3];        // Address: 0x0
static char *vnmtblPauseMenu[3][10];        // Address: 0x2CD980
static char *vnmtblPauseFlag[3][2];         // Address: 0x2CDA00
static char vnmtblPauseCareerItem[7];       // Address: 0x2E7848
static char vnmtblPauseMatchItem[6];        // Address: 0x2E7850
static char vnmtblPauseFreeItem[7];         // Address: 0x2E7858
static char *vnmtblPauseDebug[22];          // Address: 0x0
static char *vnmtblTlistCate[3][9];         // Address: 0x2CDA20
static char vnmtblTlistNum[9];              // Address: 0x2CDA90
static char *vnmtblTlistCom[86][2];         // Address: 0x2CDAA0
static char *vnmtblTutoItem[3][8];          // Address: 0x2CDD50
static char vnmtblTutoEnd[8];               // Address: 0x2E7860
static char *vnmtblTutoMes[3][25][5];       // Address: 0x2CDDB0
static float vnmtblCourseLogo[8][2];        // Address: 0x2CE390
static char *vnmtblMatchRule[3][4];         // Address: 0x2CE3D0
char *vnmtblTrickAcce[3][7];                // Address: 0x2CE400
static char *vnmtblLevelCompMes[3][7];      // Address: 0x2CE460
static char *vnmtblLevelIncompMes[3][8][4]; // Address: 0x2CE4C0
static char *vnmtblResultItem[3][3];        // Address: 0x2CE640
static char vnmtblGetSoft[9];               // Address: 0x2CE668
static signed int vnmtblCareerItem[34][3];  // Address: 0x2CE680
static char *vnmtblCareerMessage[3][7];     // Address: 0x2CE820
static char *vnmtblRank[3][6];              // Address: 0x2CE880
static char *vnmtblRank2[3][6];             // Address: 0x2CE8D0
static char *vnmtblCommon[3][5];            // Address: 0x2CE920
static char *vbgmtblMusic[12];              // Address: 0x2CE960
static char *vbgmtblArtist[12];             // Address: 0x2CE990
signed int vnmdispSelectIntTbl;             // Address: 0x2E7DF0
// Size: 0x114, DWARF: 0x13759C
VnmdispOption *vnmdispOption;  // Address: 0x2E7E94
signed int vnmdispTutoMesFlag; // Address: 0x2E7DCC
signed int vnmdispTutoMesNum;  // Address: 0x2E7DC8
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispTutoMes; // Address: 0x2E7DD0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPauseTutorial; // Address: 0x2E7DD8
signed int vnmdispHorseNum;        // Address: 0x2E7CE8
signed int *vnmdispLang;           // Address: 0x2E7E8C
char vnmdispHorseWord[16];         // Address: 0x3C2DA0
float vnmdispScrBottom[2];         // Address: 0x2E7D18
float vnmdispScrDiv;               // Address: 0x2E7D2C
signed int vnmdispDivSide;         // Address: 0x2E7E78
float vnmdispScrCenter[2];         // Address: 0x2E7D20
// Size: 0x18, DWARF: 0x13B40E
VnmdispModeEnv *vnmdispModeEnv; // Address: 0x2E7E98
signed int vnmdispDivMode;      // Address: 0x2E7E7C
// Size: 0xA0, DWARF: 0x138983
VspenvGame *vspenvGame; // Address: 0x2E7B14
// Size: 0xEF8, DWARF: 0x132F36
VnmdispSecret *vnmdispSecret; // Address: 0x2E7E90
// Size: 0xEF8, DWARF: 0x132F36
VnmdispSecret *vspenvSecret; // Address: 0x2E7B04
// Size: 0x114, DWARF: 0x13759C
VnmdispOption *vspenvOption; // Address: 0x2E7B10
// Size: 0x4, DWARF: 0x132A37
VnmdispBestTime *vnmdispBestTime[8]; // Address: 0x3C6950
// Size: 0x4, DWARF: 0x132A37
VnmdispBestTime *vspenvBestTime[8]; // Address: 0x3473F0
// Size: 0x20, DWARF: 0x1393EA
VspenvRecord *vnmdispRecord[8][6]; // Address: 0x3C6970
// Size: 0x20, DWARF: 0x1393EA
VspenvRecord *vspenvRecord[8][6]; // Address: 0x347410
// Size: 0x3C, DWARF: 0x13A391
Character *vnmdispCharEnv; // Address: 0x2E7E9C
// Size: 0x4, DWARF: 0x13B213
VnmdispCrsEnv *vnmdispCrsEnv; // Address: 0x2E7EA0
// Size: 0x4B0, DWARF: 0x138E8E
VnmdispSoftData *vnmdispSoftData; // Address: 0x2E7EA4
// Size: 0x500, DWARF: 0x132D63
VnmLoadGame2d *vnmdispGame2d; // Address: 0x2E7EAC
// Size: 0x20, DWARF: 0x1379B9
VnmdispTexData *vnmdispTexData; // Address: 0x2E7EA8
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispReplay; // Address: 0x2E7C38
char vnmdispResultFlow;     // Address: 0x2E7CB8
char vnmdispMode;           // Address: 0x2E7E88
signed int vsppScrWidth;    // Address: 0x2E7704
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispBackGround; // Address: 0x2E7E60
signed int vnmdispHorseAccept;  // Address: 0x2E7CF4
// Size: 0x5C, DWARF: 0x13C2A3
VspModeData vspModeData;       // Address: 0x3BF620
float vnmdispHorseMesPos[4];   // Address: 0x3C2D90
char vnmdispHorseMesType;      // Address: 0x2E7CBC
signed int vnmdispHorseSet;    // Address: 0x2E7CF0
signed int vnmdispHorsePts[2]; // Address: 0x2E7CE0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispHorseMes;  // Address: 0x2E7CC0
char vnmdispHorseFlow;         // Address: 0x2E7CF8
float vnmdispHorseEnterPos[2]; // Address: 0x2E7CC8
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispHorseEnter; // Address: 0x2E7CD0
signed int vnmdispHorseGet[2];  // Address: 0x2E7CD8
signed int vnmdispHorseWordNum; // Address: 0x2E7CEC
signed int vnmdispInvalid;      // Address: 0x2E7CFC
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispDraw; // Address: 0x2E7D00
float vnmdispLosePos[4];  // Address: 0x3C2DB0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispLose; // Address: 0x2E7D08
float vnmdispWinPos[4];   // Address: 0x3C2DC0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispWin;      // Address: 0x2E7D10
float vnmdispLineImagePos[5]; // Address: 0x3C2DD0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispLineImage[5]; // Address: 0x3C2DF0
float vnmdispScrDivExp;           // Address: 0x2E7D28
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispAllow; // Address: 0x2E7D98
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispTimeLeft; // Address: 0x2E7D78
signed int vnmdispOtherMode;  // Address: 0x2E7E80
signed int vnmdispDebug;      // Address: 0x2E7E84
signed int vnmdispCameraUp;   // Address: 0x2E7DA0
signed int vnmdispSyncDetail; // Address: 0x2E7DA4
signed int vnmdispSndDebug;   // Address: 0x2E7DA8
// Size: 0x48, DWARF: 0x138326
VnmDispList vnmdispGapList;     // Address: 0x3C65A0
signed int vnmdispPauseDebug2d; // Address: 0x2E7DAC
char vnmdispPauseDebugTop;      // Address: 0x2E7DB0
char vnmdispPauseDebugItem;     // Address: 0x2E7DB4
float vnmdispPauseDebugPos[5];  // Address: 0x3C65F0
char vnmdispPauseDebugFlow;     // Address: 0x2E7DB8
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPauseDebug; // Address: 0x2E7DC0
// Size: 0x48, DWARF: 0x138326
VnmDispList vnmdispLevelGoalList; // Address: 0x3C6610
// Size: 0x48, DWARF: 0x138326
VnmDispList vnmdispTrickList[9];  // Address: 0x3C6660
signed int vnmdispPauseTrickCate; // Address: 0x2E7DE0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPauseTrick; // Address: 0x2E7DE8
signed int vnmdispSelectInt;    // Address: 0x2E7DF4
signed int vnmdispSelectCnt;    // Address: 0x2E7DF8
char vnmdispSelectFlow;         // Address: 0x2E7DFC
// Size: 0x8, DWARF: 0x1338A8
Volume vnmdispVolume;          // Address: 0x2E7E00
char vnmdispPauseSoundItem;    // Address: 0x2E7E08
float vnmdispPauseSoundPos[6]; // Address: 0x3C68F0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPauseSound; // Address: 0x2E7E10
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPauseRetry; // Address: 0x2E7E18
float vnmdispPauseSelectPos[4]; // Address: 0x3C6910
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPauseSelect; // Address: 0x2E7E20
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispMenuItem; // Address: 0x2E7E28
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPauseMenu; // Address: 0x2E7E30
float vnmdispPausePos[10];     // Address: 0x3C6920
signed int vnmdispPauseCancel; // Address: 0x2E7E38
char vnmdispPauseItem;         // Address: 0x2E7E3C
char vnmdispPauseFlow;         // Address: 0x2E7E40
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispPause;    // Address: 0x2E7E48
signed int vnmdispOpeAccept;  // Address: 0x2E7E68
signed int vnmdispOpeConnect; // Address: 0x2E7E6C
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispOpe;      // Address: 0x2E7E70
signed int vnmdispIntrCancel; // Address: 0x2E7E50
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispIntr;   // Address: 0x2E7E58
float vnmdispParamPosDown;  // Address: 0x2E7D80
float vnmdispParamPosUp;    // Address: 0x2E7D84
float vnmdispParamPosRight; // Address: 0x2E7D88
float vnmdispParamPosLeft;  // Address: 0x2E7D8C
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispParam; // Address: 0x2E7D90
float vnmdispOutMesPos[2]; // Address: 0x2E7D30
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispOutMes[2]; // Address: 0x3C2E20
char vnmdispBoostMeterLen[2];  // Address: 0x2E7D38
char vnmdispSpMeterLen[2];     // Address: 0x2E7D3C
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispSpMeter[2];     // Address: 0x3C2EB0
unsigned long vnmdispTotalScore[2]; // Address: 0x3C2EC0
// Size: 0x10, DWARF: 0x13A486
VnmdispTrickPtsDraw vnmdispTrickPtsDraw[2]; // Address: 0x3C32F0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispBalance[2]; // Address: 0x3C6560
// Size: 0x10, DWARF: 0x13B859
VnmdispBalanceInfo vnmdispBalanceInfo[2]; // Address: 0x3C6570
float vnmdispStancePos[2];                // Address: 0x2E7D68
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispStance[2]; // Address: 0x3C6590
signed int vnmdispFakie[2];    // Address: 0x2E7D70
char vnmdispTrickNameLine[2];  // Address: 0x2E7D40
// Size: 0x4C, DWARF: 0x137703
List vnmdispTrickNameList[2][3]; // Address: 0x3C6380
// Size: 0x810, DWARF: 0x136BAA
VnmdispTrickNameInfo vnmdispTrickNameInfo[2][3]; // Address: 0x3C3320
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispTrickName[2];     // Address: 0x3C6550
signed int vnmdispTrickEffectType[2]; // Address: 0x2E7D48
signed int vnmdispTrickSuccess[2];    // Address: 0x2E7D50
signed int vnmdispTrickEnd[2];        // Address: 0x2E7D58
signed int vnmdispTrickStart[2];      // Address: 0x2E7D60
// Size: 0x210, DWARF: 0x13743C
VnmdispTrickPtsInfo vnmdispTrickPtsInfo[2]; // Address: 0x3C2ED0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispTrickPts[2]; // Address: 0x3C3310
// Size: 0x4, DWARF: 0x138B98
VnmdispLevelMesInfo vnmdispLevelMesInfo[8]; // Address: 0x3C2E30
float vnmdispLevelMesPos[8];                // Address: 0x3C2E50
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispLevelMes[8]; // Address: 0x3C2E70
signed int vnmdispCareerSearch;  // Address: 0x2E7C6C
// Size: 0x10, DWARF: 0x1398B6
VnmdispCareerItem vnmdispCareerItem; // Address: 0x3C2CE0
float vnmdispLevelCareerPos[5];      // Address: 0x3C2CF0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispLevelCareer; // Address: 0x2E7C70
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispSoftCount; // Address: 0x2E7C78
char vnmdispSoftAdd;           // Address: 0x2E7C80
char vnmdispSoftNum;           // Address: 0x2E7C84
float vnmdispSoftPos;          // Address: 0x2E7C88
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispSoft; // Address: 0x2E7C90
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispLevelMark[9]; // Address: 0x3C2D10
char vnmdispLevelSearch;          // Address: 0x2E7C98
float vnmdispLevelGoalsPos[11];   // Address: 0x3C2D60
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispLevelGoals; // Address: 0x2E7CA0
char vnmdispLevelFlow;          // Address: 0x2E7CA8
char vnmdispCombLine;           // Address: 0x2E7C50
// Size: 0x4C, DWARF: 0x137703
List vnmdispCombList[6];        // Address: 0x3C2AD0
signed int vnmdispTimeRenew;    // Address: 0x2E7C54
signed int vnmdispStatisSearch; // Address: 0x2E7C58
float vnmdispStatisticsPos[16]; // Address: 0x3C2CA0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispStatistics; // Address: 0x2E7C60
char vnmdispStatisFlow;         // Address: 0x2E7C68
char vnmdispEntryNum;           // Address: 0x2E7C40
char vnmdispScoreRank;          // Address: 0x2E7C44
float vnmdispHighScorePos[7];   // Address: 0x3C2AB0
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispHighScore;         // Address: 0x2E7C48
char *vsptblCharacterName[12];         // Address: 0x2B5880
char *vsptblLevelGoalStr[8][3];        // Address: 0x3A45E0
char *vsptblCourseName[24];            // Address: 0x2B5A00
signed int vsptblLevelGoalValue[8][7]; // Address: 0x2B6A60
signed int vsptblTrickPoint[160];      // Address: 0x2B6EE0
char *vsptblTrickName[160];            // Address: 0x2B6C60
signed int vgmsysPadPausePid;          // Address: 0x2E7B2C
// Size: 0x5640, DWARF: 0x1384F3
Rider *vspRider[8]; // Address: 0x3BD480
// Size: 0x60, DWARF: 0x1358D9
VgmsysPad *vgmsysPad[2];            // Address: 0x2E7B30
signed int vsptblCourseParam[8][5]; // Address: 0x2B77F0
signed int vsptblGapPoint[8][64];   // Address: 0x2B6260
char *vsptblGapList[8][64];         // Address: 0x2B5A60
// Size: 0x20, DWARF: 0x138C1D
VspDispEnv vspDispEnv; // Address: 0x3BE570
// Size: 0x38, DWARF: 0x134E8C
VspDispEnvChar vspDispEnvChar[2]; // Address: 0x3BE500
// Size: 0x824, DWARF: 0x13471A
VspDispResult vspDispResult[2]; // Address: 0x3BD4B0
// Size: 0x10, DWARF: 0x132E95
VspDispVsScore vspDispVsScore; // Address: 0x3BD4A0
char *vsptblMovieName[15];     // Address: 0x2B7F40
char *vsptblCheats[10];        // Address: 0x3A45B0
char *vsptblBoardName[12][7];  // Address: 0x2B58B0
signed int vsppScrHeight;      // Address: 0x2E7708
// Size: 0x8, DWARF: 0x135342
DisplayState vnmdispResultFade;     // Address: 0x2E7CB0
unsigned int vgmsysPadAllowPause;   // Address: 0x2E7B24
static unsigned int vnmdispSoftCnt; // Address: 0x0
static char vnmdispHorseEnterNum;   // Address: 0x0
static signed int vnmdispCrsStrip;  // Address: 0x0

void nmdispInit();
void nmdispInitReplay();
void nmdispInitEnv(VspDispEnv *env);
void nmdispInitEnvChar(VspDispEnvChar *env);
void nmdispInitResult(VspDispResult *result);
void nmdispInitMatchScore(VspDispVsScore *score);
void nmdispInitHorse();
static void nmdispInitFig();
static void nmdispInitFont();
static void nmdispInitPause();
static void nmdispInitList(VnmDispList *info);
static void nmdispInitOperate();
static void nmdispInitIntr();
static void nmdispInitParam();
static void nmdispInitChar(signed int id);
static void nmdispInitStance(signed int id);
static void nmdispInitTrick(signed int id);
static void nmdispInitTrickPts(signed int id);
static void nmdispInitLevelMes(signed int num);
static void nmdispInitLevelGoals();
static void nmdispInitStatistics();
static void nmdispInitHighScore();
static void nmdispInitSound();
void nmdispTotal(VgmsysGifPkt *packet);
void nmdispTotalChar(VgmsysGifPkt *packet, signed int id);
void nmdispModel();
static void nmdispCareer(VgmsysGifPkt *packet);
static void nmdispCareerChar(VgmsysGifPkt *packet, signed int id);
static void nmdispFreeride(VgmsysGifPkt *packet);
static void nmdispFreerideChar(VgmsysGifPkt *packet, signed int id);
static void nmdispMatchAttack(VgmsysGifPkt *packet);
static void nmdispMatchAttackChar(VgmsysGifPkt *packet, signed int id);
static void nmdispMatchBoost(VgmsysGifPkt *packet);
static void nmdispMatchBoostChar(VgmsysGifPkt *packet, signed int id);
static void nmdispMatchPush(VgmsysGifPkt *packet);
static void nmdispMatchPushChar(VgmsysGifPkt *packet, signed int id);
static void nmdispMatchHorse(VgmsysGifPkt *packet);
static void nmdispMatchHorseChar(VgmsysGifPkt *packet, signed int id);
static void nmdispIntr(VgmsysGifPkt *packet);
static void nmdispIntrCareer(VgmsysGifPkt *packet);
static void nmdispIntrMatch(VgmsysGifPkt *packet);
static void nmdispIntrLevel(VgmsysGifPkt *packet);
static void nmdispBackGround(VgmsysGifPkt *packet);
static void nmdispPauseCareer(VgmsysGifPkt *packet);
static void nmdispPauseMenuCareer(VgmsysGifPkt *packet);
static void nmdispPauseFreeride(VgmsysGifPkt *packet);
static void nmdispPauseMenuFreeride(VgmsysGifPkt *packet);
static void nmdispPauseMatch(VgmsysGifPkt *packet);
static void nmdispPauseMenuMatch(VgmsysGifPkt *packet);
static void nmdispPauseHorse(VgmsysGifPkt *packet);
static void nmdispPauseSelect(VgmsysGifPkt *packet, signed int id);
static void nmdispSoundLevels(VgmsysGifPkt *packet);
static void nmdispTrickList(VgmsysGifPkt *packet);
static void nmdispLevelGoalList(VgmsysGifPkt *packet);
static void nmdispTutorial(VgmsysGifPkt *packet);
static void nmdispPadInfo(VgmsysGifPkt *packet);
static void nmdispTutoMes(struct VgmsysGifPkt *packet);
static void nmdispDebugMenu();
static void nmdispTimeLeft(VgmsysGifPkt *packet);
static void nmdispTotalTrkPts(VgmsysGifPkt *packet, signed int id);
static void nmdispTrkMeter(VgmsysGifPkt *packet, signed int id);
static void nmdispSwitch(VgmsysGifPkt *packet, signed int id);
static void nmdispBalance(VgmsysGifPkt *packet, signed int id);
static void nmdispTrickName(VgmsysGifPkt *packet, signed int id);
static void nmdispTrickNameTrans(VgmsysGifPkt *packet, signed int id,
                                 signed int mode);
static void nmdispTrickNameFreeze(VgmsysGifPkt *packet, signed int id);
static void nmdispTrickNameFaild(VgmsysGifPkt *packet, signed int id);
static void nmdispTrickPts(VgmsysGifPkt *packet, signed int id);
static void nmdispTrickPtsTrans(VgmsysGifPkt *packet, signed int id,
                                signed int mode);
static void nmdispTrickPtsFreeze(VgmsysGifPkt *packet, signed int id);
static void nmdispTrickPtsFaild(VgmsysGifPkt *packet, signed int id);
static void nmdispRankVer(VgmsysGifPkt *packet);
static void nmdispRankHor(VgmsysGifPkt *packet, signed int id);
static void nmdispLevelMes(VgmsysGifPkt *packet);
static void nmdispOutMes(VgmsysGifPkt *packet, signed int id);
static void nmdispWinLoseDraw(VgmsysGifPkt *packet);
static void nmdispDivLine(VgmsysGifPkt *packet);
static void nmdispDivExpLine(VgmsysGifPkt *packet);
static void nmdispDivLineImage(VgmsysGifPkt *packet);
static void nmdispFireSil(VgmsysGifPkt *packet, signed int id);
static void nmdispBoostMeter(VgmsysGifPkt *packet, signed int id);
static void nmdispBoostLap(VgmsysGifPkt *packet, signed int id);
static void nmdispHorsePts(VgmsysGifPkt *packet);
static void nmdispHorseEnter(VgmsysGifPkt *packet);
static void nmdispHorseMes(VgmsysGifPkt *packet);
static void nmdispResultCareer(VgmsysGifPkt *packet);
static void nmdispResultFreeride(VgmsysGifPkt *packet);
static void nmdispResultMatch(VgmsysGifPkt *packet);
static void nmdispLevelGoals(VgmsysGifPkt *packet);
static void nmdispStatisCareer(VgmsysGifPkt *packet);
static void nmdispStatisFreeride(VgmsysGifPkt *packet);
static void nmdispStatisMatch(VgmsysGifPkt *packet);
static void nmdispHighScore(VgmsysGifPkt *packet);
static void nmdispBackLogo(VgmsysGifPkt *packet);
static void nmdispCareerUp(VgmsysGifPkt *packet);
static void nmdispTrickComb(VgmsysGifPkt *packet, // Size: 0x8, DWARF: 0x134CA2
                            Comb *comb);
static void nmdispReplay(VgmsysGifPkt *packet);
static void nmdispReplayMatch(VgmsysGifPkt *packet);
static void nmdispDemo(VgmsysGifPkt *packet);
void nmdispCalcTotal();
void nmdispCalcTotalChar(signed int id);
static void nmdispCalcCareer();
static void nmdispCalcCareerChar(signed int id);
static void nmdispCalcFreeride();
static void nmdispCalcFreerideChar(signed int id);
static void nmdispCalcMatchAttack();
static void nmdispCalcMatchAttackChar(signed int id);
static void nmdispCalcMatchBoostChar(signed int id);
static void nmdispCalcMatchPush();
static void nmdispCalcMatchPushChar(signed int id);
static void nmdispCalcMatchHorse();
static void nmdispCalcMatchHorseChar(signed int id);
static void nmdispCalcIntr();
static void nmdispCalcParam();
static signed int nmdispCalcSlide(Info *info, float *vertex, signed int frame);
static void nmdispCalcOperate();
static void nmdispCalcBackGround();
static void nmdispCalcPauseCareer();
static void nmdispCalcPauseMenuCareer();
static void nmdispCalcPauseFreeride();
static void nmdispCalcPauseMenuFreeride();
static void nmdispCalcPauseMatch();
static void nmdispCalcPauseMenuMatch();
static void nmdispCalcPauseHorse();
static void nmdispCalcSoundLevels();
static void nmdispCalcRetry();
static void nmdispCalcTrickList();
static void nmdispCalcTrickListCate(signed int num);
static void nmdispCalcLevelGoalList();
static void nmdispCalcTutorial();
static void nmdispCalcTutoMes();
static void nmdispCalcDebugMenu();
static void nmdispCalcGapList();
static void nmdispCalcPauseSelect();
static void nmdispCalcMenuItem();
static void nmdispCalcMenuItem2();
static void nmdispCalcAllow();
static void nmdispCalcTimeLeft();
static void nmdispCalcTrkMeter(signed int id);
static void nmdispCalcBoostMeter(signed int id);
static void nmdispCalcSwitch(signed int id);
static void nmdispCalcBalance(signed int id);
static void nmdispCalcTrickName(signed int id);
static void nmdispCalcTrickNameCol(signed int id);
static char nmdispCalcTrickNameFaild(signed int id);
static void nmdispCalcTrickPts(signed int id);
static char nmdispCalcTrickPtsFaild(signed int id);
static void nmdispCalcLevelMes();
static void nmdispCalcOutMes();
static void nmdispCalcDiv();
static void nmdispCalcDivExp();
static void nmdispCalcDivImage();
static void nmdispCalcWinLoseDraw();
static void nmdispCalcHorseEnter();
static void nmdispCalcHorseMes();
static void nmdispCalcResultCareer();
static void nmdispCalcResultFreeride();
static void nmdispCalcResultMatch();
static void nmdispCalcResultFade();
static void nmdispCalcLevelGoals();
static void nmdispCalcStatisCareer();
static void nmdispCalcStatisFreeride();
static void nmdispCalcStatisMatch();
static void nmdispCalcHighScore();
static void nmdispCalcGameSoft();
static void nmdispCalcCheckMark();
static void nmdispCalcCareerUp();
static void nmdispCalcReplay();
void nmdispFlowTotal();
static void nmdispFlowCareer();
static void nmdispFlowFreeride();
static void nmdispFlowMatch();
static void nmdispFlowSelectBgm();
static void nmdispFlowResultCareer();
static void nmdispFlowResultFreeride();
static void nmdispFlowResultMatch();
static void nmdispFlowLevelGoals();
static void nmdispFlowStatistics();
static void nmdispFlowSoftCount();
static void nmdispOpeIntr();
static void nmdispOpeIntrMatch();
static void nmdispOpePauseCareer();
static void nmdispOpePauseFreeride();
static void nmdispOpePauseMatch();
static signed int nmdispOpeSoundLevels();
static signed int nmdispOpeTrickList();
static signed int nmdispOpeLevelGoalList();
static void nmdispOpeDebug();
static void nmdispOpeHorse();
static void nmdispOpeEnterWord();
static void nmdispOpeResultCareer();
static void nmdispOpeResultFreeride();
static void nmdispOpeResultMatch();
static void nmdispOpeNameEntry();
static void nmdispOpeReplay();
static void nmdispOpeReplayMatch();
static void nmdispOpeDemo();
void nmdispInputParam();
void nmdispInputTrick(signed int id);
void nmdispInputLevel(signed int num);
void nmdispInputLevelCount(signed int now, signed int total, signed int num);
void nmdispInputOutMes(signed int id);
void nmdispInputResult();
void nmdispInputHorseResult(signed int next);
void nmdispEndTrick(signed int id, signed int result);
void nmdispEndReplay();
void nmdispEndHorse();
static void nmdispEndSound();
signed int nmdispGetMode();
signed int nmdispCheckIntr();
signed int nmdispCheckHorse();
signed int nmdispGetHorseNum();
signed int nmdispSearchRank(signed int id);
void nmdispTransTex(VgmsysGifPkt *packet);
void nmdispRenewTrick(signed int id);
void nmdispSetTrickFall(signed int id, char *str, signed int line);
static void nmdispChanState(VgmsysGifPkt *packet);

// Included functions
unsigned int tmevGetLevelGoal(signed int player);

void nmtrickInitInfo(CombInfo *info);
void nmtrickMakeStr(signed int id, DispInfo *info, List *list);
void ultexSetTexPath3(VgmsysGifPkt *packet, unsigned int *addr,
                      signed int offset, signed int block);
void nmbgmSetOptNext(signed int next);
signed int nmbgmChangeOption();
signed int nmbgmResume();
signed int nmvcPlayButton(signed int no);
signed int nmvcPlayCursor(signed int num);
signed int nmsndRestart(signed int fade);
void spSetFade(signed int per, signed int col);
VnmLoadGame2d *sploadGetGame2D();
void nmfontSetFSize(float width, float height);
void nmfontSetPack(signed int flag);
void nmfontSetFCol(signed int r, signed int g, signed int b, signed int a);
float nmfontGetStrFLen(char *str, float width);
float nmfontGetPackStrFLen(char *str, float width, signed int type);
void scePrintf(char *format, ...);
float cosf(float x);
float sinf(float x);
signed int rand();
signed int strlen(char *str);
void gmsysPadResume();
signed int ktmfMenuFunc_finish();
signed int ktmfMenuFunc_restart();
signed int nmactPlayPush();
signed int nmbgmChange2(signed int fade, signed int num, signed int tbl);
signed int nmbgmCheckQue();
signed int nmbgmGetSelect();
signed int nmbgmGetSelectTbl();
signed int nmbgmPause();
signed int nmbgmSetExterVol(signed int vol);
void nmbgmSetOptRand(signed int rand);
void nmdrawBalance2(VgmsysGifPkt *packet, DispBalance *info);
void nmdrawDual(VgmsysGifPkt *packet, Dual *info);
void nmdrawFPoly(VgmsysGifPkt *packet, Poly *info);
void nmdrawMeter(VgmsysGifPkt *packet, Meter *info);
void nmdrawFade(VgmsysGifPkt *packet, Fade *info);
void nmdrawIceFont(VgmsysGifPkt *packet, char *str, Ice *info);
void nmdrawInit();
void nmdrawSwitchTest(VgmsysGifPkt *packet, signed int flag);
void nmfontInitOption();
void nmfontSetBil(signed int flag);
void nmfontSetOption();
void nmfontSetScrRate(signed int type);
void nmfontSetShadow();
signed int nmsndEndGame();
signed int nmsndGetChanState(signed int core);
signed int nmtrickSetSpType(signed int num);
void nmtrickInit();
void nmtrickInitInfo2(signed int id);
void nmtrickInitList(List *list);
signed int nmtrickMakeList(signed int id, DispInfo *info, List *list);
void nmtrickSetInfo(signed int id, CombInfo *info);
void nmtrickGetInfo(signed int id, CombInfo *info);
signed int nmvcPlay(signed int res, signed int group, signed int num);
signed int nmvcSetExterVol(signed int vol);
signed int tmevGetLap(signed int player);
signed int tmevGetLevelGoalFlag(signed int no);
void ulpadInitData(VgmsysPad *ope);
void ulpadSetAnaRef(signed int flag);
float nmdrawGetPointLen(Point *info);
void nmdrawBar(VgmsysGifPkt *packet, DispBar *info);
void nmdrawCheck(VgmsysGifPkt *packet, Check *info);
void nmdrawFTex(VgmsysGifPkt *packet, DispTex *info);
void nmdrawKeyOperate(VgmsysGifPkt *packet, Key *info);
void nmdrawPoint(VgmsysGifPkt *packet, Point *info);
void nmfontFPrintF(VgmsysGifPkt *packet, char *str, float *pos);
void nmfontGPrintF(VgmsysGifPkt *packet, char *str, float *pos);
void nmfontSetCol(sceVu0IMATRIX col);
void nmfontSetType(signed int type);
signed int ulstdSprintf(char *buf, char *fmt, ...);

void nmdispInit() {
  signed int i; // r16
  char *word_tbl[3] = {
      // 0x30(r29) @554
      "HORSE     ", // @551
      "LOSER     ", // @552
      "PENDU     "  // @553
  };
  s32 *word_tbl_ptr = &word_tbl;

  nmdispInitFig();
  vnmdispGame2d = sploadGetGame2D();
  vnmdispTexData = &vnmdispGame2d->game;
  vnmdispSoftData = &vnmdispGame2d->soft;
  vnmdispCrsEnv = &vspenvGame->course;
  vnmdispCharEnv = &vspenvGame->character[0];
  vnmdispModeEnv = &vspenvGame->mode;

  vnmdispRecord = vspenvRecord;
  vnmdispBestTime = vspenvBestTime;
  vnmdispOption = vspenvOption;
  vnmdispSecret = vspenvSecret;
  vnmdispLang = &vspenvGame->language;
  switch (vnmdispModeEnv->game_mode) {
  case 0:
    break;
  case 1:
    switch (vnmdispModeEnv->match_rule) {
    case 0:
    case 1:
    case 2:
      vnmdispDivMode = 1;
      if (vnmdispModeEnv->divide == 0) {
        vnmdispScrCenter[0] = 160.0f;
        vnmdispScrCenter[1] = 480.0f;
      } else {
        vnmdispDivSide = 1;
        vnmdispScrDiv = 224.0f;
        vnmdispScrBottom[0] = 224.0f;
      }
      break;
    case 3:
      ulstdSprintf(&vnmdispHorseWord, "%s", word_tbl[*vnmdispLang]);
      vnmdispHorseNum = 5;
      break;
    }
    break;
  case 2:
    if (vnmdispOption->tutorial == 1) {
      vnmdispPauseTutorial.state = 1;
      vnmdispTutoMes.state = 1;
      vnmdispTutoMesNum = rand() % 25;
      vnmdispTutoMesFlag |= 1 << vnmdispTutoMesNum;
    }
    break;
  }
  for (i = 0; i < 0xC; i++) {
    if ((vnmdispOption->bgm.disable & (1 << i)) == 0) {
      vnmdispSelectIntTbl += 1;
    }
  }
  nmdrawInit();
  nmtrickInit();
}

void nmdispInitReplay() {
  vnmdispMode = 0;
  vnmdispResultFlow = 0;
  vnmdispReplay.state = 0;
  vnmdispReplay.cnt = 0;
}

void nmdispInitEnv(VspDispEnv *env) {
  env->mode = 0;
  env->time_left = 0;
  env->pass_time = 0;
  env->div = vsppScrWidth / 2;
  env->div_exp = vsppScrWidth / 2;
}

void nmdispInitEnvChar(VspDispEnvChar *env) {
  env->points.single = 0;
  env->points.total = 0;
  env->points.freeride = 0;
  env->points.link_rate = 0x64;
  env->bar.num = 0;
  env->bar.charge = 0;
  env->bar.left = 0;
  env->balance.state = 0;
  env->balance.per = 0.0f;
  env->match.boost.num = 0;
  env->match.boost.charge = 0;
  env->match.push = 0;
  env->match.res[2] = 0;
}

void nmdispInitResult(VspDispResult *result) {
  result->rank = 0;
  result->trick_landing = 0;
  result->comb_num = 0;
  result->comp_time = 0;
  result->comb_points = 0;
  nmtrickInitInfo(&result->comb_info);
}

void nmdispInitMatchScore(VspDispVsScore *score) {
  score->win = 0;
  score->lose = 0;
  score->draw = 0;
}

void nmdispInitHorse() {
  signed int i; // r16

  vnmdispHorseFlow = 2;
  vnmdispHorseMes.state = 1;
  vnmdispHorseMes.cnt = 0;
  if (vnmdispHorseSet == 0 && vnmdispHorsePts[vspModeData.horse_pid ^ 1] > 0) {
    vnmdispHorseSet = 1;
  }
  if (vnmdispHorseSet == 1) {
    vnmdispHorseMesType = 1;
  } else {
    vnmdispHorseMesType = 0;
  }
  for (i = 0; i < 4; i++) {
    vnmdispHorseMesPos[i] = -640.0f;
  }
  nmdispInitChar(vspModeData.horse_pid);
  nmdispInitPause();
  nmdispInitOperate();
  vnmdispHorseAccept = 0;
  vnmdispBackGround.state = 1;
  vnmdispBackGround.cnt = 0;
}

static void nmdispInitFig() {
  signed int i; // r16
  signed int j; // r17

  vnmdispGame2d = 0;
  vnmdispTexData = 0;
  vnmdispSoftData = 0;
  vnmdispCrsEnv = 0;
  vnmdispCharEnv = 0;
  vnmdispModeEnv = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 6; j++) {
      vnmdispRecord[i][j] = 0;
    }
    vnmdispBestTime[i] = 0;
  }
  vnmdispOption = 0;
  vnmdispSecret = 0;
  vnmdispLang = 0;
  vnmdispMode = 0;
  vnmdispDebug = 1;
  vnmdispOtherMode = 0;
  vnmdispDivMode = 0;
  vnmdispDivSide = 0;
  vnmdispTimeLeft.state = 0;
  vnmdispTimeLeft.cnt = 0;
  nmdispInitPause();
  vnmdispAllow.state = 0;
  vnmdispAllow.cnt = 0;
  nmdispInitOperate();
  nmdispInitIntr();
  nmdispInitParam();
  for (i = 0; i < 2; i++) {
    nmdispInitChar(i);
  }
  for (i = 0; i < 8; i++) {
    nmdispInitLevelMes(i);
  }
  vnmdispScrDiv = 320.0f;
  vnmdispScrDivExp = 320.0f;
  for (i = 0; i < 5; i++) {
    vnmdispLineImage[i].state = 0;
    vnmdispLineImage[i].cnt = 0;
    vnmdispLineImagePos[i] = 0.0f;
  }
  vnmdispWin.state = 0;
  vnmdispWin.cnt = 0;
  vnmdispWinPos[0] = -640.0f;
  vnmdispWinPos[1] = 149.33333f;
  vnmdispLose.state = 0;
  vnmdispLose.cnt = 0;
  vnmdispLosePos[0] = -640.0f;
  vnmdispLosePos[1] = 149.33333f;
  vnmdispDraw.state = 0;
  vnmdispDraw.cnt = 0;
  vnmdispInvalid = 0;
  vnmdispHorseFlow = 0;
  vnmdispHorseAccept = 0;
  vnmdispHorseSet = 0;
  vnmdispHorseWord[0] = 0;
  vnmdispHorseNum = 0;
  vnmdispHorseWordNum = 0;
  for (i = 0; i < 2; i++) {
    vnmdispHorsePts[i] = 0;
    vnmdispHorseGet[i] = 0;
  }
  vnmdispHorseEnter.state = 0;
  vnmdispHorseEnter.cnt = 0;
  vnmdispHorseEnterPos[0] = -640.0f;
  vnmdispHorseEnterPos[1] = -640.0f;
  vnmdispHorseMes.state = 0;
  vnmdispHorseMes.cnt = 0;
  for (i = 0; i < 4; i++) {
    vnmdispHorseMesPos[i] = -640.0f;
  }
  vnmdispHorseMesType = 0;
  vnmdispResultFlow = 0;
  nmdispInitLevelGoals();
  nmdispInitStatistics();
  nmdispInitHighScore();
}

static void nmdispInitFont() {
  signed int i; // r16
  // Size: 0x60, DWARF: 0x13661E
  FontOption option; // 0x20(r29)

  for (i = 0; i < 4; i++) {
    option.col[i][0] = 0x80;
    option.col[i][1] = 0x80;
    option.col[i][2] = 0x80;
    option.col[i][3] = 0x80;
  }
  option.type = 0;
  option.width = 16.0f;
  option.height = 16.0f;
  option.pack = 1;
  option.shadow = 1;
  option.bil = 1;
  nmfontSetOption(&option);
  nmfontSetScrRate(1);
}

static void nmdispInitPause() {
  signed int i; // r16

  vnmdispPause.state = 0;
  vnmdispPause.cnt = 0;
  vnmdispPauseFlow = 0;
  vnmdispPauseItem = 0;
  vnmdispPauseCancel = 0;
  for (i = 0; i < 0xA; i++) {
    vnmdispPausePos[i] = -640.0f;
  }
  vnmdispBackGround.state = 0;
  vnmdispBackGround.cnt = 0;
  vnmdispPauseMenu.state = 0;
  vnmdispPauseMenu.cnt = 0;
  vnmdispMenuItem.state = 0;
  vnmdispMenuItem.cnt = 0;
  vnmdispPauseSelect.state = 0;
  vnmdispPauseSelect.cnt = 0;
  vnmdispPauseSelectPos[0] = -640.0f;
  vnmdispPauseSelectPos[1] = -224.0f;
  vnmdispPauseRetry.state = 0;
  vnmdispPauseRetry.cnt = 0;
  vnmdispPauseSound.state = 0;
  vnmdispPauseSound.cnt = 0;
  for (i = 0; i < 6; i++) {
    vnmdispPauseSoundPos[i] = -640.0f;
  }
  vnmdispPauseSoundItem = 0;
  vnmdispVolume.se = 0;
  vnmdispVolume.bgm = 0;
  vnmdispSelectFlow = 0;
  vnmdispSelectCnt = 0;
  vnmdispSelectInt = -1;
  vnmdispSelectIntTbl = 0;
  vnmdispPauseTrick.state = 0;
  vnmdispPauseTrick.cnt = 0;
  vnmdispPauseTrickCate = 0;
  for (i = 0; i < 9; i++) {
    nmdispInitList(&vnmdispTrickList[i]);
  }
  nmdispInitList(&vnmdispLevelGoalList);
  vnmdispPauseTutorial.state = 0;
  vnmdispPauseTutorial.cnt = 0;
  vnmdispTutoMes.state = 0;
  vnmdispTutoMes.cnt = 0;
  vnmdispTutoMesFlag = 0;
  vnmdispTutoMesNum = 0;
  vnmdispPauseDebug.state = 0;
  vnmdispPauseDebug.cnt = 0;
  vnmdispPauseDebugFlow = 0;
  for (i = 0; i < 5; i++) {
    vnmdispPauseDebugPos[i] = -640.0f;
  }
  vnmdispPauseDebugItem = 0;
  vnmdispPauseDebugTop = 0;
  vnmdispPauseDebug2d = 0;
  nmdispInitList(&vnmdispGapList);
  vnmdispSndDebug = 0;
  vnmdispSyncDetail = 0;
  vnmdispCameraUp = 0;
}

static void nmdispInitList(VnmDispList *info) {
  signed int i; // r16

  info->state = 0;
  info->cnt = 0;
  info->top = 0;
  for (i = 0; i < 0x10; i++) {
    info->pos[i] = -640.0f;
  }
}

static void nmdispInitOperate() {
  vnmdispOpe.state = 0;
  vnmdispOpe.cnt = 0;
  vnmdispOpeConnect = 0;
  vnmdispOpeAccept = 1;
}

static void nmdispInitIntr() {
  vnmdispIntr.state = 0;
  vnmdispIntr.cnt = 0;
  vnmdispIntrCancel = 0;
}

static void nmdispInitParam() {
  vnmdispParam.state = 0;
  vnmdispParam.cnt = 0;
  vnmdispParamPosLeft = -320.0f;
  vnmdispParamPosRight = 960.0f;
  vnmdispParamPosUp = -112.0f;
  vnmdispParamPosDown = 224.0f;
}

static void nmdispInitChar(signed int id) {
  nmdispInitStance(id);
  vnmdispBalanceInfo[id].state = 0;
  vnmdispBalanceInfo[id].per = 0.0f;
  vnmdispBalance[id].state = 0;
  vnmdispBalance[id].cnt = 0;
  nmdispInitTrick(id);
  nmdispInitTrickPts(id);
  vnmdispTrickPtsDraw[id].freeride = 0;
  vnmdispTotalScore[id] = 0;
  vnmdispSpMeter[id].state = 0;
  vnmdispSpMeter[id].cnt = 0;
  vnmdispSpMeterLen[id] = 0;
  vnmdispBoostMeterLen[id] = 0;
  vnmdispOutMes[id].state = 0;
  vnmdispOutMes[id].cnt = 0;
  vnmdispOutMesPos[id] = -640.0f;
  vnmdispScrCenter[id] = 320.0f;
  vnmdispScrBottom[id] = 448.0f;
}

static void nmdispInitStance(signed int id) {
  vnmdispFakie[id] = 0;
  vnmdispStance[id].state = 0;
  vnmdispStance[id].cnt = 0;
  vnmdispStancePos[id] = 800.0f;
}

static void nmdispInitTrick(signed int id) {
  signed int j; // r16
  signed int i; // r17

  vnmdispTrickStart[id] = 0;
  vnmdispTrickEnd[id] = 0;
  vnmdispTrickSuccess[id] = 0;
  vnmdispTrickEffectType[id] = 0;
  vnmdispTrickName[id].state = 0;
  vnmdispTrickName[id].cnt = 0;
  // Loop through the y column of 2D vnmdispTrickNameInfo array
  for (i = 0; i < 3; i++) {
    vnmdispTrickNameInfo[id][i].cnt = 0;
    vnmdispTrickNameInfo[id][i].state = 0;
    vnmdispTrickNameInfo[id][i].num = 0xFF;
    // Loop through all word values
    for (j = 0; j < 64; j++) {
      vnmdispTrickNameInfo[id][i].word[j].cnt = 0;
      vnmdispTrickNameInfo[id][i].word[j].state = 0;
      vnmdispTrickNameInfo[id][i].word[j].str = 0xFF;
      vnmdispTrickNameInfo[id][i].word[j].pos[0] = 0.0f;
      vnmdispTrickNameInfo[id][i].word[j].pos[1] = 0.0f;
      vnmdispTrickNameInfo[id][i].word[j].add[0] = 0.0f;
      vnmdispTrickNameInfo[id][i].word[j].add[1] = 0.0f;
      vnmdispTrickNameInfo[id][i].word[j].add[2] = 0.0f;
      vnmdispTrickNameInfo[id][i].word[j].add[3] = 0.0f;
    }
  }
  nmtrickInitInfo2(id);
  for (i = 0; i < 3; i++) {
    nmtrickInitList(&vnmdispTrickNameList[id][i]);
  }
  vnmdispTrickNameLine[id] = 0;
}

static void nmdispInitTrickPts(signed int id) {
  signed int i; // r16

  vnmdispTrickPts[id].state = 0;
  vnmdispTrickPts[id].cnt = 0;
  vnmdispTrickPtsDraw[id].single = 0;
  vnmdispTrickPtsDraw[id].total = 0;
  vnmdispTrickPtsDraw[id].link_rate = 0x64;
  vnmdispTrickPtsInfo[id].cnt = 0;
  vnmdispTrickPtsInfo[id].state = 0;
  vnmdispTrickPtsInfo[id].num = 0;
  for (i = 0; i < 16; i++) {
    vnmdispTrickPtsInfo[id].word[i].cnt = 0;
    vnmdispTrickPtsInfo[id].word[i].state = 0;
    vnmdispTrickPtsInfo[id].word[i].str = 255;
    vnmdispTrickPtsInfo[id].word[i].pos[0] = 0.0f;
    vnmdispTrickPtsInfo[id].word[i].pos[1] = 0.0f;
  }
}

static void nmdispInitLevelMes(signed int num) {
  vnmdispLevelMes[num].state = 0;
  vnmdispLevelMes[num].cnt = 0;
  vnmdispLevelMesPos[num] = -640.0f;
  vnmdispLevelMesInfo[num].type = 0xFF;
  vnmdispLevelMesInfo[num].num = 0xFF;
  vnmdispLevelMesInfo[num].value[0] = 0xFF;
  vnmdispLevelMesInfo[num].value[1] = 0xFF;
}

static void nmdispInitLevelGoals() {
  signed int i; // r16

  vnmdispLevelFlow = 0;
  vnmdispLevelGoals.state = 0;
  vnmdispLevelGoals.cnt = 0;
  for (i = 0; i < 0xB; i++) {
    vnmdispLevelGoalsPos[i] = -640.0f;
  }
  vnmdispLevelSearch = 0;
  for (i = 0; i < 9; i++) {
    vnmdispLevelMark[i].state = 0;
    vnmdispLevelMark[i].cnt = 0;
  }
  vnmdispSoft.state = 0;
  vnmdispSoft.cnt = 0;
  vnmdispSoftPos = -2048.0f;
  vnmdispSoftNum = 0;
  vnmdispSoftAdd = 0;
  vnmdispSoftCount.state = 0;
  vnmdispSoftCount.cnt = 0;
  vnmdispLevelCareer.state = 0;
  vnmdispLevelCareer.cnt = 0;
  for (i = 0; i < 5; i++) {
    vnmdispLevelCareerPos[i] = -640.0f;
  }
  vnmdispCareerItem.type = 0xFF;
  vnmdispCareerItem.num = 0xFF;
  vnmdispCareerItem.value[0] = 0xFF;
  vnmdispCareerItem.value[1] = 0xFF;
  vnmdispCareerSearch = 0;
}

static void nmdispInitStatistics() {
  signed int i; // r16

  vnmdispStatisFlow = 0;
  vnmdispStatistics.state = 0;
  vnmdispStatistics.cnt = 0;
  for (i = 0; i < 16; i++) {
    vnmdispStatisticsPos[i] = -640.0f;
  }
  vnmdispStatisSearch = 0;
  vnmdispTimeRenew = 0;
  for (i = 0; i < 6; i++) {
    nmtrickInitList(&vnmdispCombList[i]);
  }
  vnmdispCombLine = 0;
}

static void nmdispInitHighScore() {
  signed int i; // r16

  vnmdispHighScore.state = 0;
  vnmdispHighScore.cnt = 0;
  for (i = 0; i < 7; i++) {
    vnmdispHighScorePos[i] = -640.0f;
  }
  vnmdispScoreRank = 0xFF;
  vnmdispEntryNum = 0;
}

static void nmdispInitSound() {
  signed int tmp; // r16

  nmbgmSetOptNext(0);
  nmbgmChangeOption();
  tmp = nmbgmResume();
  if (tmp == -1) {
    scePrintf("nmbgmResume Error\n");
  }
}

void nmdispTotal(VgmsysGifPkt *packet) {
  if (vnmdispSndDebug == 1) {
    nmdispChanState(packet);
  }
  if (vnmdispPauseDebug2d == 0) {
    switch (vnmdispModeEnv->game_mode) {
    case 0:
      nmdispCareer(packet);
      break;
    case 1:
      switch (vnmdispModeEnv->match_rule) {
      case 0:
        nmdispMatchAttack(packet);
        break;
      case 1:
        nmdispMatchBoost(packet);
        break;
      case 2:
        nmdispMatchPush(packet);
        break;
      case 3:
        nmdispMatchHorse(packet);
        break;
      }
      break;
    case 2:
      nmdispFreeride(packet);
      break;
    }
  }
  nmfontInitOption();
}

void nmdispTotalChar(VgmsysGifPkt *packet, signed int id) {
  if (vnmdispPauseDebug2d == 0) {
    switch (vnmdispModeEnv->game_mode) {
    case 0:
      nmdispCareerChar(packet, id);
      break;
    case 1:
      switch (vnmdispModeEnv->match_rule) {
      case 0:
        nmdispMatchAttackChar(packet, id);
        break;
      case 1:
        nmdispMatchBoostChar(packet, id);
        break;
      case 2:
        nmdispMatchPushChar(packet, id);
        break;
      case 3:
        nmdispMatchHorseChar(packet, id);
        break;
      }
      break;
    case 2:
      nmdispFreerideChar(packet, id);
      break;
    }
  }
  nmfontInitOption();
}

void nmdispModel(VgmsysGifPkt *packet) {}

static void nmdispCareer(VgmsysGifPkt *packet) {
  switch (vnmdispMode) {
  case 0:
    break;
  case 1:
    if (vnmdispDebug == 1) {
      nmdispIntrCareer(packet);
    }
    break;
  case 2:
    if (vnmdispDebug == 1) {
      nmdispTimeLeft(packet);
    }
    nmdispPauseCareer(packet);
    break;
  case 3:
    if (vnmdispDebug == 1) {
      nmdispResultCareer(packet);
    }
    break;
  case 4:
    if (vnmdispDebug == 1) {
      nmdispReplay(packet);
    }
    break;
  case 5:
    nmdispDemo(packet);
    break;
  }
}

static void nmdispCareerChar(VgmsysGifPkt *packet, signed int id) {
  if (vnmdispDebug == 1) {
    switch (vnmdispMode) {
    case 0:
    case 1:
      break;
    case 2:
      nmdispLevelMes(packet);
      nmdispTotalTrkPts(packet, id);
      nmdispTrkMeter(packet, id);
      nmdispSwitch(packet, id);
      nmdispBalance(packet, id);
      nmdispTrickName(packet, id);
      nmdispTrickPts(packet, id);
      nmdispOutMes(packet, id);
      break;
    case 3:
    case 4:
      break;
    }
  }
}

static void nmdispFreeride(VgmsysGifPkt *packet) {
  switch (vnmdispMode) {
  case 0:
    break;
  case 1:
    if (vnmdispDebug == 1) {
      nmdispIntr(packet);
    }
    break;
  case 2:
    if (vnmdispDebug == 1) {
      nmdispTimeLeft(packet);
    }
    nmdispPauseFreeride(packet);
    break;
  case 3:
    if (vnmdispDebug == 1) {
      nmdispResultFreeride(packet);
    }
    break;
  case 4:
    if (vnmdispDebug == 1) {
      nmdispReplay(packet);
    }
    break;
  case 5:
    nmdispDemo(packet);
    break;
  }
  return;
}

static void nmdispFreerideChar(VgmsysGifPkt *packet, signed int id) {
  if (vnmdispDebug == 1) {
    switch (vnmdispMode) {
    case 0:
    case 1:
      break;
    case 2:
      nmdispTutorial(packet);
      nmdispTotalTrkPts(packet, id);
      nmdispTrkMeter(packet, id);
      nmdispSwitch(packet, id);
      nmdispBalance(packet, id);
      nmdispTrickName(packet, id);
      nmdispTrickPts(packet, id);
      nmdispOutMes(packet, id);
      break;
    case 3:
    case 4:
      break;
    }
  }
}

static void nmdispMatchAttack(VgmsysGifPkt *packet) {
  switch (vnmdispMode) {
  case 0:
    break;
  case 1:
    if (vnmdispDebug == 1) {
      nmdispIntrMatch(packet);
    }
    break;
  case 2:
    if (vnmdispDebug == 1) {
      nmdispDivLine(packet);
      nmdispTimeLeft(packet);
      nmdispWinLoseDraw(packet);
    }
    nmdispPauseMatch(packet);
    break;
  case 3:
    if (vnmdispDebug == 1) {
      nmdispResultMatch(packet);
    }
    break;
  case 4:
    if (vnmdispDebug == 1) {
      nmdispReplayMatch(packet);
    }
    break;
  case 5:
    nmdispDemo(packet);
    break;
  }
}

static void nmdispMatchAttackChar(VgmsysGifPkt *packet, signed int id) {
  if (vnmdispDebug == 1) {
    switch (vnmdispMode) {
    case 0:
    case 1:
      break;
    case 2:
      nmdispFireSil(packet, id);
      nmdispTrkMeter(packet, id);
      nmdispTotalTrkPts(packet, id);
      nmdispSwitch(packet, id);
      nmdispBalance(packet, id);
      nmdispTrickName(packet, id);
      nmdispTrickPts(packet, id);
      nmdispOutMes(packet, id);
      break;
    }
  }
}

static void nmdispMatchBoost(VgmsysGifPkt *packet) {
  switch (vnmdispMode) {
  case 0:
    break;
  case 1:
    if (vnmdispDebug == 1) {
      nmdispIntrMatch(packet);
    }
    break;
  case 2:
    if (vnmdispDebug == 1) {
      nmdispDivLine(packet);
      nmdispTimeLeft(packet);
      nmdispRankVer(packet);
      nmdispWinLoseDraw(packet);
    }
    nmdispPauseMatch(packet);
    break;
  case 3:
    if (vnmdispDebug == 1) {
      nmdispResultMatch(packet);
    }
    break;
  case 4:
    if (vnmdispDebug == 1) {
      nmdispReplayMatch(packet);
    }
    break;
  case 5:
    nmdispDemo(packet);
    break;
  }
}

static void nmdispMatchBoostChar(VgmsysGifPkt *packet, signed int id) {
  if (vnmdispDebug == 1) {
    switch (vnmdispMode) {
    case 0:
    case 1:
      break;
    case 2:
      nmdispFireSil(packet, id);
      nmdispTrkMeter(packet, id);
      nmdispBoostMeter(packet, id);
      nmdispBoostLap(packet, id);
      nmdispSwitch(packet, id);
      nmdispRankHor(packet, id);
      nmdispBalance(packet, id);
      nmdispTrickName(packet, id);
      nmdispTrickPts(packet, id);
      nmdispOutMes(packet, id);
      break;
    }
  }
}

static void nmdispMatchPush(VgmsysGifPkt *packet) {
  switch (vnmdispMode) {
  case 0:
    break;
  case 1:
    if (vnmdispDebug == 1) {
      nmdispIntrMatch(packet);
    }
    break;
  case 2:
    if (vnmdispDebug == 1) {
      nmdispDivExpLine(packet);
      nmdispDivLine(packet);
      nmdispDivLineImage(packet);
      nmdispTimeLeft(packet);
      nmdispWinLoseDraw(packet);
    }
    nmdispPauseMatch(packet);
    break;
  case 3:
    if (vnmdispDebug == 1) {
      nmdispResultMatch(packet);
    }
    break;
  case 4:
    if (vnmdispDebug == 1) {
      nmdispReplayMatch(packet);
    }
    break;
  case 5:
    nmdispDemo(packet);
  }
  return;
}

static void nmdispMatchPushChar(VgmsysGifPkt *packet, signed int id) {
  if (vnmdispDebug == 1) {
    switch (vnmdispMode) {
    case 0:
    case 1:
      break;
    case 2:
      nmdispFireSil(packet, id);
      nmdispTrkMeter(packet, id);
      nmdispSwitch(packet, id);
      nmdispBalance(packet, id);
      nmdispTrickName(packet, id);
      nmdispTrickPts(packet, id);
      nmdispOutMes(packet, id);
      break;
    }
  }
}

static void nmdispMatchHorse(VgmsysGifPkt *packet) {
  switch (vnmdispMode) {
  case 0:
    break;
  case 1:
    if (vnmdispDebug == 1) {
      nmdispIntrMatch(packet);
    }
    break;
  case 2:
    if (vnmdispDebug == 1) {
      nmdispHorsePts(packet);
      nmdispTimeLeft(packet);
    }
    nmdispBackGround(packet);
    nmdispHorseEnter(packet);
    nmdispHorseMes(packet);
    nmdispPauseHorse(packet);
    break;
  case 3:
    if (vnmdispDebug == 1) {
      nmdispResultMatch(packet);
    }
    break;
  case 4:
    if (vnmdispDebug == 1) {
      nmdispReplayMatch(packet);
    }
    break;
  case 5:
    nmdispDemo(packet);
  }
  return;
}

static void nmdispMatchHorseChar(VgmsysGifPkt *packet, signed int id) {
  if (vnmdispDebug == 1) {
    switch (vnmdispMode) {
    case 0:
    case 1:
      break;
    case 2:
      nmdispTrkMeter(packet, id);
      nmdispSwitch(packet, id);
      nmdispBalance(packet, id);
      nmdispTrickName(packet, id);
      nmdispTrickPts(packet, id);
      nmdispOutMes(packet, id);
      break;
    }
  }
}

static void nmdispIntr(VgmsysGifPkt *packet) {
  float pos_tmp[4]; // 0x10(r29)
  // Size: 0xB0, DWARF: 0x13F356
  DispTex tex; // 0x20(r29)
  // Size: 0x40, DWARF: 0x13519E
  Key key; // 0xD0(r29)
  // Size: 0x20, DWARF: 0x134B98
  Fade fade; // 0x110(r29)

  pos_tmp[0] = 32.0f;
  pos_tmp[1] = 96.0f;
  nmdispInitFont();
  tex.data = vnmdispTexData->tex + 0x8;
  tex.tex_size[0] = 0x100;
  tex.tex_size[1] = 0x80;
  tex.tex_uv[0] = 0;
  tex.tex_uv[1] = 0;
  tex.vertex[0][0] = pos_tmp[0] - 8.0f;
  tex.vertex[0][1] = pos_tmp[1] - vnmtblCourseLogo[vnmdispCrsEnv->no][1];
  tex.col[0][0] = 0x80;
  tex.col[0][1] = 0x80;
  tex.col[0][2] = 0x80;
  tex.col[0][3] = 0x80;
  tex.option.sprite = (signed int)1;
  tex.option.bil = 1;
  tex.option.width = tex.tex_size[0];
  tex.option.height = tex.tex_size[1]; // 0x80;
  nmdrawFTex(packet, &tex);
  if ((vnmdispIntr.state) == 1) {
    fade.cnt = vnmdispIntr.cnt;
    fade.flag = 0;
    fade.type = 0;
    fade.col = 0;
    fade.max = 0x3C;
    nmdrawFade(packet, &fade);
  }
  key.pos[0] = 320.0f;
  key.pos[1] = 430.0f;
  key.data = vnmdispTexData->tex;
  key.button = 0;
  key.message = 8;
  key.language = *vnmdispLang;
  if ((vnmdispIntr.state) == 1) {
    if (vnmdispIntr.cnt < 5U) {
      key.cnt = vnmdispIntr.cnt;
    } else {
      key.cnt = 5;
    }
  } else {
    key.cnt = 5;
  }
  key.center = 1;
  key.mode = 0;
  nmdrawKeyOperate(packet, &key);
  if (vnmdispIntr.state == 0 || (vnmdispIntr.state == 3)) {
    fade.cnt = vnmdispIntr.cnt;
    fade.flag = 1;
    fade.type = 0;
    fade.col = 0;
    fade.max = 0x3C;
    nmdrawFade(packet, &fade);
  }
}

static void nmdispIntrCareer(VgmsysGifPkt *packet) {
  float pos_tmp[4]; // 0x10(r29)
  // Size: 0xB0, DWARF: 0x13F356
  DispTex tex; // 0x20(r29)
  // Size: 0x40, DWARF: 0x13519E
  Key key; // 0xD0(r29)
  // Size: 0x20, DWARF: 0x134B98
  Fade fade; // 0x110(r29)

  // packet = packet; // sp130 sp 0x130
  pos_tmp[0] = 32.0f;
  pos_tmp[1] = 96.0f;
  nmdispInitFont();
  tex.data = vnmdispTexData->tex + 0x8;
  tex.tex_size[0] = 0x100;
  tex.tex_size[1] = 0x80;
  tex.tex_uv[0] = 0;
  tex.tex_uv[1] = 0;
  tex.vertex[0][0] = pos_tmp[0] - 8.0f;
  tex.vertex[0][1] = pos_tmp[1] - vnmtblCourseLogo[vnmdispCrsEnv->no][1];
  tex.col[0][0] = 0x80;
  tex.col[0][1] = 0x80;
  tex.col[0][2] = 0x80;
  tex.col[0][3] = 0x80;
  tex.option.sprite = 1;
  tex.option.bil = 1;
  tex.option.width = tex.tex_size[0];
  tex.option.height = tex.tex_size[1];
  nmdrawFTex(packet, &tex);
  nmdispIntrLevel(packet);
  if (vnmdispIntr.state == 1) {
    fade.cnt = vnmdispIntr.cnt;
    fade.flag = 0;
    fade.type = 0;
    fade.col = 0;
    fade.max = 0x3C;
    nmdrawFade(packet, &fade);
  }
  key.pos[0] = 320.0f;
  key.pos[1] = 430.0f;
  key.data = vnmdispTexData->tex;
  key.button = 0;
  key.message = 8;
  key.language = *vnmdispLang;
  if ((vnmdispIntr.state) == 1) {
    if (vnmdispIntr.cnt < 5U) {
      key.cnt = vnmdispIntr.cnt;
    } else {
      key.cnt = 5;
    }
  } else {
    key.cnt = 5;
  }
  key.center = 1;
  key.mode = 0;
  nmdrawKeyOperate(packet, &key);
  if (vnmdispIntr.state == 0 || (vnmdispIntr.state == 3)) {
    fade.cnt = vnmdispIntr.cnt;
    fade.flag = 1;
    fade.type = 0;
    fade.col = 0;
    fade.max = 0x3C;
    nmdrawFade(packet, &fade);
  }
}

static void nmdispBackGround(VgmsysGifPkt *packet) {
  Poly poly; // 0x10(r29)

  if (vnmdispBackGround.state != 0) {
    poly.vertex[0][0] = 0.0f;
    poly.vertex[0][1] = 0.0f;
    poly.vertex[0][2] = 1.0f;
    poly.col[0][0] = 0;
    poly.col[0][1] = 0;
    poly.col[0][2] = 0;
    switch (vnmdispBackGround.state) {
    case 1:
      poly.col[0][3] = (vnmdispBackGround.cnt * 0x60) / 10;
      break;
    case 3:
      poly.col[0][3] = 0x60 - ((vnmdispBackGround.cnt * 0x60) / 10);
      break;
    default:
      poly.col[0][3] = 0x60;
      break;
    }
    poly.option.sprite = 1;
    poly.option.width = 640.0f;
    poly.option.height = 448.0f;
    nmdrawFPoly(packet, &poly);
  }
}

static void nmdispPauseCareer(VgmsysGifPkt *packet) {
  nmdispBackGround(packet);
  nmdispPauseMenuCareer(packet);
  nmdispSoundLevels(packet);
  nmdispTrickList(packet);
  nmdispLevelGoalList(packet);
  nmdispDebugMenu(packet);
  nmdispPauseSelect(packet, vnmtblPauseCareerItem[vnmdispPauseItem]);
}

static void nmdispPauseMenuCareer(VgmsysGifPkt *packet) {
  signed int i;              // r16
  char str_tmp[128];         // 0x20(r29)
  float font_pos[4];         // 0xA0(r29)
  signed int font_col[4][4]; // 0xB0(r29)
  float font_size[4];        // 0xF0(r29)
  // Size: 0x40, DWARF: 0x13519E
  Key key;       // 0x100(r29)
  float tmp;     // 0x148(r29)
  float pos_tmp; // 0x14C(r29)

  // packet = packet; // 0x150
  pos_tmp = 64.0f;
  nmdispInitFont();
  if (vnmdispPauseMenu.state != 0) {
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(28.0f, 28.0f); //(5.46040909e-315);
    ulstdSprintf(&str_tmp, "%s", vnmtblPauseMenu[*vnmdispLang][8]); // @580
    tmp = nmfontGetPackStrFLen(str_tmp, 28.0f, 0);
    font_pos[0] = vnmdispPausePos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    for (i = 0; i < 6; i++) {
      if (i != (vnmdispPauseItem)) {
        ulstdSprintf(
            &str_tmp, "%s",
            vnmtblPauseMenu[*vnmdispLang][vnmtblPauseCareerItem[i]]); // @580
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        font_size[0] = 20.0f;
        font_size[1] = 20.0f;
        nmfontSetFSize(font_size[0], font_size[1]);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
        font_pos[0] = ((640.0f - tmp) / 2.0f) + vnmdispPausePos[i + 1];
        font_pos[1] =
            (80.0f + pos_tmp + (30.0f * i)) - ((font_size[1] - 20.0f) / 2.0f);
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      }
    }
    if ((vnmdispPauseMenu.state != 3 && vnmdispOpe.state != 0) ||
        ((vnmdispPauseMenu.state == 3 && ((vnmdispOpe.state) == 3)))) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.pos[0] = 248.0f;
      key.button = 0;
      key.message = 0;
      nmdrawKeyOperate(packet, &key);
      key.pos[0] = 392.0f;
      key.button = 2;
      key.message = 4;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispPauseFreeride(VgmsysGifPkt *packet) {
  nmdispBackGround(packet);
  nmdispPauseMenuFreeride(packet);
  nmdispSoundLevels(packet);
  nmdispTrickList(packet);
  nmdispLevelGoalList(packet);
  nmdispDebugMenu(packet);
  nmdispPauseSelect(packet, vnmtblPauseFreeItem[vnmdispPauseItem]);
}

static void nmdispPauseMenuFreeride(VgmsysGifPkt *packet) {
  signed int i;              // r16
  char str_tmp[128];         // 0x20(r29)
  float font_pos[4];         // 0xA0(r29)
  signed int font_col[4][4]; // 0xB0(r29)
  // Size: 0x40, DWARF: 0x13519E
  Key key;       // 0xF0(r29)
  float tmp;     // 0x138(r29)
  float pos_tmp; // 0x13C(r29)

  pos_tmp = 64.0f;
  nmdispInitFont();
  if (vnmdispPauseMenu.state != 0) {
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(28.0f, 28.0f);
    ulstdSprintf(&str_tmp, "%s", vnmtblPauseMenu[*vnmdispLang][8]);
    // temp_f0 = nmfontGetPackStrFLen(0x41E00000, &str_tmp, 0);
    tmp = nmfontGetPackStrFLen(str_tmp, 28.0f, 0);
    font_pos[0] = vnmdispPausePos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    for (i = 0; i < 6; i++) {
      if (i != (vnmdispPauseItem)) {
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblPauseMenu[*vnmdispLang][vnmtblPauseFreeItem[i]]);
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        nmfontSetFSize(20.0f, 20.0f);
        tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
        font_pos[0] = ((640.0f - tmp) / 2.0f) + vnmdispPausePos[i + 1];
        font_pos[1] = 80.0f + pos_tmp + (30.0f * (float)i);
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
        if (i == 4) {
          ulstdSprintf(&str_tmp, "%s",
                       vnmtblPauseFlag[*vnmdispLang][vnmdispOption->tutorial]);
          tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
          font_pos[0] = (512.0f + vnmdispPausePos[i + 1]) - (tmp / 2.0f);
          nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
        }
      }
    }
    if (((vnmdispPauseMenu.state != 3) && vnmdispOpe.state != 0) ||
        (((vnmdispPauseMenu.state) == 3) && vnmdispOpe.state == 3)) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.pos[0] = 248.0f;
      key.button = 0;
      key.message = 0;
      nmdrawKeyOperate(packet, &key);
      key.pos[0] = 392.0f;
      key.button = 2;
      key.message = 4;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispPauseMatch(VgmsysGifPkt *packet) {
  nmdispBackGround(packet);
  nmdispPauseMenuMatch(packet);
  nmdispSoundLevels(packet);
  nmdispTrickList(packet);
  nmdispDebugMenu(packet);
  nmdispPauseSelect(packet, vnmtblPauseMatchItem[vnmdispPauseItem]);
}

static void nmdispPauseMenuMatch(VgmsysGifPkt *packet) {
  signed int i;              // r16
  char str_tmp[128];         // 0x20(r29)
  float font_pos[4];         // 0xA0(r29)
  signed int font_col[4][4]; // 0xB0(r29)
  float font_size[4];        // 0xF0(r29)
  // Size: 0x40, DWARF: 0x13519E
  Key key;       // 0x100(r29)
  float tmp;     // 0x148(r29)
  float pos_tmp; // 0x14C(r29)

  pos_tmp = 64.0f;
  nmdispInitFont();
  if (vnmdispPauseMenu.state != 0) {
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(28.0f, 28.0f);
    ulstdSprintf(&str_tmp, "%s", vnmtblPauseMenu[*vnmdispLang][8]);
    tmp = nmfontGetPackStrFLen(str_tmp, 28.0f, 0);
    font_pos[0] = vnmdispPausePos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    for (i = 0; i < 5; i++) {
      if (i != (vnmdispPauseItem)) {
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblPauseMenu[*vnmdispLang][vnmtblPauseMatchItem[i]]);
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        font_size[0] = 20.0f;
        font_size[1] = 20.0f;
        nmfontSetFSize(font_size[0], font_size[1]);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
        font_pos[0] = ((640.0f - tmp) / 2.0f) + vnmdispPausePos[i + 1];
        font_pos[1] = (80.0f + pos_tmp + (30.0f * (float)i)) -
                      ((font_size[1] - 20.0f) / 2.0f);
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      }
    }
    if ((((vnmdispPauseMenu.state) != 3) && vnmdispOpe.state != 0) ||
        (((vnmdispPauseMenu.state) == 3) && ((vnmdispOpe.state) == 3))) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.pos[0] = 248.0f;
      key.button = 0;
      key.message = 0;
      nmdrawKeyOperate(packet, &key);
      key.pos[0] = 392.0f;
      key.button = 2;
      key.message = 4;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispPauseHorse(VgmsysGifPkt *packet) {
  nmdispPauseMenuMatch(packet);
  nmdispSoundLevels(packet);
  nmdispTrickList(packet);
  nmdispDebugMenu(packet);
  nmdispPauseSelect(packet, vnmtblPauseMatchItem[vnmdispPauseItem]);
}

static void nmdispLevelGoalList(VgmsysGifPkt *packet) {
  signed int i;              // r16
  float tmp;                 // 0x1CC(r29)
  char str_tmp[128];         // 0x60(r29)
  float pos_tmp[4];          // 0xE0(r29)
  float font_pos[4];         // 0xF0(r29)
  signed int font_col[1][4]; // 0x100(r29)
  Key key;                   // 0x110(r29)
  unsigned int *level_goal;  // r19
  unsigned int new_level;    // r20
  signed int min;            // r17
  signed int sec;            // r18
  Point point;               // 0x150(r29)

  pos_tmp[0] = 48.0f;
  pos_tmp[1] = 64.0f;
  nmdispInitFont();
  if (vnmdispCharEnv->no < 12) {
    level_goal = &vnmdispSecret->character[vnmdispCharEnv->no]
                      .level_goal[vnmdispCrsEnv->no];
  } else {
    level_goal = &vnmdispSecret->create_character[vnmdispCharEnv->no - 12]
                      .character.level_goal[vnmdispCrsEnv->no];
  }
  new_level = tmevGetLevelGoal(vnmdispCharEnv->player);
  if (vnmdispLevelGoalList.state != 0) {
    nmfontSetFSize(16.0f, 16.0f);
    for (i = 0; i < 9; i += 1) {
      if (*level_goal & (1 << i)) {
        font_col[0][0] = 0x40;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
      } else if (new_level & (1 << i)) {
        font_col[0][0] = 0x40;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      } else {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      }
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      font_pos[1] = 80.0f + pos_tmp[1] + (22.5f * (f32)i);
      switch (i) {
      case 0:
      case 1:
      case 2:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblLevelCompMes[*vnmdispLang][i]);
        font_pos[0] = vnmdispLevelGoalList.pos[i] + pos_tmp[0];
        nmfontFPrintF(packet, str_tmp, font_pos);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] =
            (640.0f + vnmdispLevelGoalList.pos[i]) - (pos_tmp[0] + tmp);
        nmfontFPrintF(packet, str_tmp, font_pos);
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no][i];
        point.type = 0;
        point.size[0] = 0x10;
        point.size[1] = 0x10;
        point.flat = 1;
        point.base = 1;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        break;
      case 3:
        min = vsptblLevelGoalValue[vnmdispCrsEnv->no][i] / 60;
        sec = vsptblLevelGoalValue[vnmdispCrsEnv->no][i] % 60;
        font_pos[0] = vnmdispLevelGoalList.pos[i] + pos_tmp[0];
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s ", vnmtblLevelCompMes[*vnmdispLang][i]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] = font_pos[0] + tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%d", min);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetStrFLen(str_tmp, 16.0f);
        font_pos[0] = font_pos[0] + tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblCommon[*vnmdispLang][2]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] = font_pos[0] + tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%02d", sec);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetStrFLen(str_tmp, 16.0f);
        font_pos[0] = font_pos[0] + tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s ", vnmtblLevelCompMes[*vnmdispLang][6]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] = font_pos[0] + tmp;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no][i + 1];
        point.type = 0;
        point.size[0] = 0x10;
        point.size[1] = 0x10;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        tmp = nmdrawGetPointLen(&point);
        font_pos[0] = font_pos[0] + tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][1]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 4:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, vnmtblLevelCompMes[*vnmdispLang][i],
                     vsptblCourseName[vnmdispCrsEnv->no + 0x10]);
        font_pos[0] = vnmdispLevelGoalList.pos[i] + pos_tmp[0];
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 5:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblLevelCompMes[*vnmdispLang][i]);
        font_pos[0] = vnmdispLevelGoalList.pos[i] + pos_tmp[0];
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 6:
      case 7:
      case 8:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s",
                     vsptblLevelGoalStr[vnmdispCrsEnv->no][i - 6]);
        font_pos[0] = vnmdispLevelGoalList.pos[i] + pos_tmp[0];
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      }
    }
    if ((vnmdispLevelGoalList.state != 3 && vnmdispOpe.state != 0) ||
        (vnmdispLevelGoalList.state == 3 && vnmdispOpe.state == 3)) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.pos[0] = 320.0f;
      key.button = 2;
      key.message = 4;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispTrickList(VgmsysGifPkt *packet) {
  signed int i;              // r18
  signed int j;              // r16
  float tmp;                 // 0x2FC(r29)
  float pos_tmp[4];          // 0x60(r29)
  char str_tmp[256];         // 0x70(r29)
  float font_pos[4];         // 0x170(r29)
  signed int font_col[1][4]; // 0x180(r29)
  // Size: 0x30, DWARF: 0x139290
  Allow allow; // 0x190(r29)
  // Size: 0x30, DWARF: 0x13519E
  Key key; // 0x1C0(r29)
  // Size: 0x70, DWARF: 0x137FF4
  Point point;                 // 0x200(r29)
  char list_num;               // r20
  char top_ofs;                // r17
  char button_key[16][4];      // 0x270(r29)
  signed int button_col[4][4]; // 0x2B0(r29)
  signed int type;             // r19

  pos_tmp[0] = 48.0f;
  pos_tmp[1] = 64.0f;
  nmdispInitFont();
  if (vnmdispPauseTrick.state != 0) {
    if (vnmdispCharEnv[vgmsysPadPausePid].chr_param.stance == 0) {
      type = 0;
    } else {
      type = 1;
    }
    if (vspRider[vgmsysPadPausePid]->ctrl.act.fakie == 1) {
      type ^= 1;
    }
    if (vspenvOption->cheats.mirror == 1) {
      type ^= 1;
    }
    for (i = 0; i < 9; i++) {
      if (vnmdispTrickList[i].state != 0) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        nmfontSetFSize(20.0f, 20.0f);
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblTlistCate[*vnmdispLang][i]);
        tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
        font_pos[0] = ((640.0f - tmp) / 2.0f) + vnmdispTrickList[i].pos[0];
        font_pos[1] = 35.0f + pos_tmp[1];
        nmfontFPrintF(packet, str_tmp, font_pos);
        switch (i) {
        case 0:
          top_ofs = 0x1;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].grab) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 1:
          top_ofs = 0x19;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].flip) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 2:
          top_ofs = 0x31;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].grind) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 3:
          top_ofs = 0x42;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].grind) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 4:
          top_ofs = 0x51;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].jump) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 5:
          top_ofs = 0x3E;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].jump) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 6:
          top_ofs = 0x4B;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].grind) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 7:
          top_ofs = 0x4F;
          switch (vnmdispOption->key_config[vgmsysPadPausePid].revert) {
          case 4:
            ulstdSprintf(button_key[0], "L1");
            break;
          case 1:
            ulstdSprintf(button_key[0], "L2");
            break;
          case 8:
            ulstdSprintf(button_key[0], "R1");
            break;
          case 2:
            ulstdSprintf(button_key[0], "R2");
            break;
          default:
            ulstdSprintf(button_key[0], "  ");
            break;
          }
          switch (vnmdispOption->key_config[vgmsysPadPausePid].stance) {
          case 4:
            ulstdSprintf(button_key[1], "L1");
            break;
          case 1:
            ulstdSprintf(button_key[1], "L2");
            break;
          case 8:
            ulstdSprintf(button_key[1], "R1");
            break;
          case 2:
            ulstdSprintf(button_key[1], "R2");
            break;
          default:
            ulstdSprintf(button_key[1], "  ");
            break;
          }
          button_col[0][0] = 0x80;
          button_col[0][1] = 0x80;
          button_col[0][2] = 0x80;
          button_col[0][3] = 0x80;
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          break;
        case 8:
          if (vnmdispCharEnv[vgmsysPadPausePid].no < 0xC) {
            top_ofs = (vnmdispCharEnv[vgmsysPadPausePid].no * 2) + 0x54;
          } else {
            top_ofs =
                (vnmdispSecret
                     ->create_character[vnmdispCharEnv[vgmsysPadPausePid].no -
                                        0xC]
                     .trick_type *
                 2) +
                0x54;
          }
          switch (vnmdispOption->key_config[vgmsysPadPausePid].flip) {
          case 0x10:
            ulstdSprintf(button_key[0], "\202");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[0], "\200");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x40;
            button_col[0][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[0], "\201");
            button_col[0][0] = 0x40;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[0], "\203");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x40;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[0], "\204");
            button_col[0][0] = 0x80;
            button_col[0][1] = 0x80;
            button_col[0][2] = 0x80;
            button_col[0][3] = 0x80;
            break;
          }
          switch (vnmdispOption->key_config[vgmsysPadPausePid].grab) {
          case 0x10:
            ulstdSprintf(button_key[1], "\202");
            button_col[1][0] = 0x40;
            button_col[1][1] = 0x80;
            button_col[1][2] = 0x40;
            button_col[1][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[1], "\200");
            button_col[1][0] = 0x80;
            button_col[1][1] = 0x40;
            button_col[1][2] = 0x40;
            button_col[1][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[1], "\201");
            button_col[1][0] = 0x40;
            button_col[1][1] = 0x40;
            button_col[1][2] = 0x80;
            button_col[1][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[1], "\203");
            button_col[1][0] = 0x80;
            button_col[1][1] = 0x40;
            button_col[1][2] = 0x80;
            button_col[1][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[1], "\204");
            button_col[1][0] = 0x80;
            button_col[1][1] = 0x80;
            button_col[1][2] = 0x80;
            button_col[1][3] = 0x80;
            break;
          }
          switch (vnmdispOption->key_config[vgmsysPadPausePid].grind) {
          case 0x10:
            ulstdSprintf(button_key[2], "\202");
            button_col[2][0] = 0x40;
            button_col[2][1] = 0x80;
            button_col[2][2] = 0x40;
            button_col[2][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[2], "\200");
            button_col[2][0] = 0x80;
            button_col[2][1] = 0x40;
            button_col[2][2] = 0x40;
            button_col[2][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[2], "\201");
            button_col[2][0] = 0x40;
            button_col[2][1] = 0x40;
            button_col[2][2] = 0x80;
            button_col[2][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[2], "\203");
            button_col[2][0] = 0x80;
            button_col[2][1] = 0x40;
            button_col[2][2] = 0x80;
            button_col[2][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[2], "\204");
            button_col[2][0] = 0x80;
            button_col[2][1] = 0x80;
            button_col[2][2] = 0x80;
            button_col[2][3] = 0x80;
            break;
          }
          switch (vnmdispOption->key_config[vgmsysPadPausePid].jump) {
          case 0x10:
            ulstdSprintf(button_key[3], "\202");
            button_col[3][0] = 0x40;
            button_col[3][1] = 0x80;
            button_col[3][2] = 0x40;
            button_col[3][3] = 0x80;
            break;
          case 0x20:
            ulstdSprintf(button_key[3], "\200");
            button_col[3][0] = 0x80;
            button_col[3][1] = 0x40;
            button_col[3][2] = 0x40;
            button_col[3][3] = 0x80;
            break;
          case 0x40:
            ulstdSprintf(button_key[3], "\201");
            button_col[3][0] = 0x40;
            button_col[3][1] = 0x40;
            button_col[3][2] = 0x80;
            button_col[3][3] = 0x80;
            break;
          case 0x80:
            ulstdSprintf(button_key[3], "\203");
            button_col[3][0] = 0x80;
            button_col[3][1] = 0x40;
            button_col[3][2] = 0x80;
            button_col[3][3] = 0x80;
            break;
          default:
            ulstdSprintf(button_key[3], "\204");
            button_col[3][0] = 0x80;
            button_col[3][1] = 0x80;
            button_col[3][2] = 0x80;
            button_col[3][3] = 0x80;
            break;
          }
          break;
        default:
          ulstdSprintf(button_key[0], " ");
          ulstdSprintf(button_key[1], " ");
          ulstdSprintf(button_key[2], " ");
          ulstdSprintf(button_key[3], " ");
          button_col[0][0] = 0x80;
          button_col[0][1] = 0x80;
          button_col[0][2] = 0x80;
          button_col[0][3] = 0x80;
          button_col[1][0] = 0x80;
          button_col[1][1] = 0x80;
          button_col[1][2] = 0x80;
          button_col[1][3] = 0x80;
          button_col[2][0] = 0x80;
          button_col[2][1] = 0x80;
          button_col[2][2] = 0x80;
          button_col[2][3] = 0x80;
          button_col[3][0] = 0x80;
          button_col[3][1] = 0x80;
          button_col[3][2] = 0x80;
          button_col[3][3] = 0x80;
          break;
        }
        list_num = vnmtblTlistNum[i];
        if (list_num >= 0xB) {
          list_num = 0xA;
        }
        top_ofs += vnmdispTrickList[i].top;
        for (j = 0; j < list_num; j++) {
          nmfontSetFSize(18.0f, 18.0f);
          switch (i) {
          case 6:
            nmfontSetPack(0);
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x40;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
            ulstdSprintf(str_tmp, "%s", vnmtblTlistCom[top_ofs + j][type]);
            tmp = nmfontGetStrFLen(str_tmp, 18.0f);
            font_pos[0] = pos_tmp[0] + vnmdispTrickList[i].pos[j + 1];
            font_pos[1] = (80.0f + pos_tmp[1]) + (22.5f * (f32)j);
            nmfontFPrintF(packet, str_tmp, font_pos);
            break;
          case 7:
            nmfontSetPack(1);
            nmfontSetFCol(button_col[0][0], button_col[0][1], button_col[0][2],
                          button_col[0][3]);
            if (vnmtblTlistCom[top_ofs + j][type][0] == 0x32) {
              ulstdSprintf(str_tmp, "%s", button_key[1]);
            } else {
              ulstdSprintf(str_tmp, "%s", button_key[0]);
            }
            font_pos[0] = pos_tmp[0] + vnmdispTrickList[i].pos[j + 1];
            font_pos[1] = (80.0f + pos_tmp[1]) + (22.5f * (f32)j);
            nmfontFPrintF(packet, str_tmp, font_pos);
            break;
          case 8:
            nmfontSetPack(0);
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x40;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
            ulstdSprintf(str_tmp, "%s", vnmtblTlistCom[j + 0x54][type]);
            tmp = nmfontGetStrFLen(str_tmp, 18.0f);
            font_pos[0] = pos_tmp[0] + vnmdispTrickList[i].pos[j + 1];
            font_pos[1] = (80.0f + pos_tmp[1]) + (22.5f * (f32)j);
            nmfontFPrintF(packet, str_tmp, font_pos);
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
            font_pos[0] += tmp;
            ulstdSprintf(str_tmp, "+");
            tmp = nmfontGetStrFLen(str_tmp, 18.0f);
            nmfontFPrintF(packet, str_tmp, font_pos);
            font_pos[0] += tmp;
            switch (nmtrickSetSpType(top_ofs + j)) {
            case 1:
              nmfontSetFCol(button_col[1][0], button_col[1][1],
                            button_col[1][2], button_col[1][3]);
              ulstdSprintf(str_tmp, "%s", button_key[1]);
              break;
            case 2:
              nmfontSetFCol(button_col[0][0], button_col[0][1],
                            button_col[0][2], button_col[0][3]);
              ulstdSprintf(str_tmp, "%s", button_key[0]);
              break;
            case 3:
            case 4:
            case 5:
              nmfontSetFCol(button_col[2][0], button_col[2][1],
                            button_col[2][2], button_col[2][3]);
              ulstdSprintf(str_tmp, "%s", button_key[2]);
              break;
            default:
              nmfontSetFCol(button_col[1][0], button_col[1][1],
                            button_col[1][2], button_col[1][3]);
              ulstdSprintf(str_tmp, "%s", button_key[1]);
              break;
            }
            nmfontFPrintF(packet, str_tmp, font_pos);
            break;
          default:
            nmfontSetPack(0);
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x40;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
            ulstdSprintf(str_tmp, "%s", vnmtblTlistCom[top_ofs + j][type]);
            tmp = nmfontGetStrFLen(str_tmp, 18.0f);
            font_pos[0] = pos_tmp[0] + vnmdispTrickList[i].pos[j + 1];
            font_pos[1] = (80.0f + pos_tmp[1]) + (22.5f * (f32)j);
            nmfontFPrintF(packet, str_tmp, font_pos);
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
            font_pos[0] += tmp;
            ulstdSprintf(str_tmp, "+");
            tmp = nmfontGetStrFLen(str_tmp, 18.0f);
            if (vnmtblTlistCom[top_ofs + j][type][0] != 0x20) {
              nmfontFPrintF(packet, str_tmp, font_pos);
              nmfontSetFCol(button_col[0][0], button_col[0][1],
                            button_col[0][2], button_col[0][3]);
              font_pos[0] += tmp;
              ulstdSprintf(str_tmp, "%s", button_key[0]);
            }
            nmfontFPrintF(packet, str_tmp, font_pos);
            break;
          }
          nmfontSetPack(1);
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          font_col[0][3] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          ulstdSprintf(str_tmp, "%s", vsptblTrickName[top_ofs + j]);
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          if (tmp > 360.0f) {
            nmfontSetFSize(12.0f, 18.0f);
          } else if (tmp > 288.0f) {
            nmfontSetFSize(14.0f, 18.0f);
          } else {
            nmfontSetFSize(18.0f, 18.0f);
          }
          font_pos[0] = (144.0f + pos_tmp[0]) + vnmdispTrickList[i].pos[j + 1];
          nmfontFPrintF(packet, str_tmp, font_pos);
          point.pos[0] = (640.0f + vnmdispTrickList[i].pos[j + 1]) - pos_tmp[0];
          point.pos[1] = font_pos[1];
          point.col[0][0] = font_col[0][0];
          point.col[0][1] = font_col[0][1];
          point.col[0][2] = font_col[0][2];
          point.col[0][3] = font_col[0][3];
          point.point = vsptblTrickPoint[top_ofs + j];
          point.type = 0;
          point.size[0] = 0x12;
          point.size[1] = 0x12;
          point.flat = 1;
          point.base = 1;
          point.language = *vnmdispLang;
          nmdrawPoint(packet, &point);
        }
      }
    }
    if (vnmdispTrickList[vnmdispPauseTrickCate].state == 2) {
      if (vnmdispAllow.state != 0) {
        allow.data = vnmdispTexData->tex + 1;
        if (vnmdispAllow.state == 1) {
          allow.abe = (vnmdispAllow.cnt * 128) / 40;
        } else {
          allow.abe = 0x80 - ((vnmdispAllow.cnt * 128) / 40);
        }
        allow.type = 2;
        allow.width = 16.0f;
        allow.height = 64.0f;
        allow.pos[0] = (pos_tmp[0] - 16.0f) - allow.width;
        allow.pos[1] = 224.0f - (allow.height / 2.0f);
        nmdrawAllow(packet, &allow);
        allow.type = 3;
        allow.pos[0] = 640.0f - (pos_tmp[0] - 16.0f);
        nmdrawAllow(packet, &allow);
      }
    }
    if (vnmdispTrickList[vnmdispPauseTrickCate].top > 0) {
      allow.type = 0;
      allow.width = 64.0f;
      allow.height = 16.0f;
      allow.pos[0] = (640.0f - allow.width) / 2.0f;
      allow.pos[1] = (80.0f + pos_tmp[1]) - (9.0f + allow.height);
      nmdrawAllow(packet, &allow);
    }
    list_num = vnmtblTlistNum[vnmdispPauseTrickCate];
    if ((vnmdispTrickList[vnmdispPauseTrickCate].top + 0xA) < list_num) {
      allow.type = 1;
      allow.width = 64.0f;
      allow.height = 16.0f;
      allow.pos[0] = (640.0f - allow.width) / 2.0f;
      allow.pos[1] = 27.0f + (202.5f + (80.0f + pos_tmp[1]));
      nmdrawAllow(packet, &allow);
    }
    if ((vnmdispPauseTrick.state != 3 && vnmdispOpe.state != 0) ||
        (vnmdispPauseTrick.state == 3 && vnmdispOpe.state == 3)) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.pos[0] = 320.0f;
      key.button = 2;
      key.message = 4;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispTutorial(VgmsysGifPkt *packet) {
  nmdispPadInfo(packet);
  nmdispTutoMes(packet);
}

static void nmdispPadInfo(VgmsysGifPkt *packet) {
  // // Size: 0x30, DWARF: 0x13ED2C
  Dual dual; // 0x10(r29)
  // Size: 0x60, DWARF: 0x1358D9
  VgmsysPad ope; // 0x40(r29)

  if (vnmdispPauseTutorial.state != 0) {
    dual.pos[0] = 426.66666f;
    dual.pos[1] = 224.0f;
    dual.data = vnmdispTexData->tex + 0x6;
    if (vnmdispPauseFlow == 0) {
      dual.ope = vgmsysPad[0];
    } else {
      ulpadInitData(&ope);
      dual.ope = &ope;
    }
    switch (vnmdispPauseTutorial.state) {
    case 1:
      dual.abe = (vnmdispPauseTutorial.cnt << 7) / 20;
      break;
    case 3:
      dual.abe = 0x80 - ((vnmdispPauseTutorial.cnt << 7) / 20);
      break;
    default:
      dual.abe = 0x80;
      break;
    }
    dual.ratio = 0.8f;
    nmdrawDual(packet, &dual);
  }
}

static void nmdispPauseSelect(VgmsysGifPkt *packet, signed int id) {
  float tmp;                 // 0xF8(r29)
  char str_tmp[128];         // 0x10(r29)
  float pos_tmp;             // 0xFC(r29)
  float font_pos[4];         // 0x90(r29)
  signed int font_col[4][4]; // 0xA0(r29)
  float font_size[4];        // 0xE0(r29)

  pos_tmp = 64.0f;
  nmdispInitFont();
  if (vnmdispPauseSelect.state != 0) {
    ulstdSprintf(&str_tmp, "%s", vnmtblPauseMenu[*vnmdispLang][id]);
    switch (vnmdispPauseSelect.state) {
    case 1:
    case 2:
      font_size[0] = 28.0f;
      font_size[1] = 28.0f;
      nmfontSetFSize(font_size[0], font_size[1]);
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x60;
      font_col[0][2] = 0x40;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
      font_pos[0] =
          ((640.0f - tmp) / 2.0f) + vnmdispPausePos[vnmdispPauseItem + 1];
      font_pos[1] = ((pos_tmp + 80.0f) + (vnmdispPauseItem * 30.0f)) -
                    ((font_size[1] - 20.0f) / 2.0f);
      nmfontFPrintF(packet, &str_tmp, &font_pos);
      if (vnmdispModeEnv->game_mode == 2) {
        if (vnmdispPauseItem == 4) {
          ulstdSprintf(&str_tmp, "%s",
                       vnmtblPauseFlag[*vnmdispLang][vnmdispOption->tutorial]);
          tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
          font_pos[0] =
              (vnmdispPausePos[vnmdispPauseItem + 1] + 512.0f) - (tmp / 2.0f);
          nmfontFPrintF(packet, &str_tmp, &font_pos);
        }
      }
      break;
    case 3:
      switch (vnmdispMenuItem.state) {
      case 1:
        font_size[0] = ((vnmdispMenuItem.cnt * 0.2f) + 1.0f) * 20.0f;
        font_size[1] = ((vnmdispMenuItem.cnt * 0.2f) + 1.0f) * 20.0f;
        break;
      case 2:
        font_size[0] = (1.6f - (vnmdispMenuItem.cnt * 0.1f)) * 20.0f;
        font_size[1] = (1.6f - (vnmdispMenuItem.cnt * 0.1f)) * 20.0f;
        break;
      default:
        font_size[0] = 28.0f;
        font_size[1] = 28.0f;
        break;
      }
      nmfontSetFSize(font_size[0], font_size[1]);
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x60;
      font_col[0][2] = 0x40;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
      font_pos[0] = (640.0f - tmp) / 2.0f;
      font_pos[1] = ((pos_tmp + 80.0f) + (vnmdispPauseItem * 30.0f)) -
                    ((font_size[1] - 20.0f) / 2.0f);
      nmfontFPrintF(packet, &str_tmp, &font_pos);
      if (vnmdispModeEnv->game_mode == 2) {
        if (vnmdispPauseItem == 4) {
          ulstdSprintf(&str_tmp, "%s",
                       vnmtblPauseFlag[*vnmdispLang][vnmdispOption->tutorial]);
          tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
          font_pos[0] =
              (vnmdispPausePos[vnmdispPauseItem + 1] + 512.0f) - (tmp / 2.0f);
          nmfontFPrintF(packet, &str_tmp, &font_pos);
        }
      }
      break;
    case 4:
      font_size[0] = 28.0f;
      font_size[1] = 28.0f;
      nmfontSetFSize(font_size[0], font_size[1]);
      font_col[0][0] = 0x40;
      font_col[0][1] = 0x40;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      font_col[1][0] = 0x40;
      font_col[1][1] = 0x40;
      font_col[1][2] = 0x80;
      font_col[1][3] = 0x80;
      font_col[2][0] = 0x80;
      font_col[2][1] = 0x80;
      font_col[2][2] = 0x80;
      font_col[2][3] = 0x80;
      font_col[3][0] = 0x80;
      font_col[3][1] = 0x80;
      font_col[3][2] = 0x80;
      font_col[3][3] = 0x80;
      nmfontSetCol(&font_col);
      tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
      font_pos[0] = (640.0f - tmp) / 2.0f;
      font_pos[1] = pos_tmp;
      nmfontGPrintF(packet, &str_tmp, &font_pos);
      break;
    case 5:
      switch (vnmdispModeEnv->game_mode) {
      case 1:
        if ((vnmdispPauseItem == 0) || (vnmdispPauseItem == 1) ||
            (vnmdispPauseItem == 4)) {
          font_size[0] = ((vnmdispPauseSelect.cnt * 0.05f) + 1.0f) * 28.0f;
          font_size[1] = ((vnmdispPauseSelect.cnt * 0.05f) + 1.0f) * 28.0f;
          font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] =
              0x80 - ((vnmdispPauseSelect.cnt << 7) / 10);
        } else {
          font_size[0] = 28.0f;
          font_size[1] = 28.0f;
          font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] =
              0x80;
        }
        break;
      default:
        if ((vnmdispPauseItem == 0) || (vnmdispPauseItem == 1) ||
            (vnmdispPauseItem == 5)) {
          font_size[0] = ((vnmdispPauseSelect.cnt * 0.05f) + 1.0f) * 28.0f;
          font_size[1] = ((vnmdispPauseSelect.cnt * 0.05f) + 1.0f) * 28.0f;
          font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] =
              0x80 - ((vnmdispPauseSelect.cnt << 7) / 10);
        } else {
          font_size[0] = 28.0f;
          font_size[1] = 28.0f;
          font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] =
              0x80;
        }
        break;
      }
      nmfontSetFSize(font_size[0], font_size[1]);
      font_col[0][0] = font_col[1][0] =
          0x80 - ((vnmdispPauseSelect.cnt << 6) / 10);
      font_col[0][1] = font_col[1][1] =
          0x60 - ((vnmdispPauseSelect.cnt << 5) / 10);
      font_col[0][2] = font_col[1][2] =
          ((vnmdispPauseSelect.cnt << 7) / 10) + 0x40;
      font_col[2][0] = font_col[3][0] = 0x80;
      font_col[2][1] = font_col[3][1] =
          ((vnmdispPauseSelect.cnt << 5) / 10) + 0x60;
      font_col[2][2] = font_col[3][2] =
          ((vnmdispPauseSelect.cnt << 6) / 10) + 0x40;
      nmfontSetCol(&font_col);
      tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
      font_pos[0] = (640.0f - tmp) / 2.0f;
      font_pos[1] = vnmdispPauseSelectPos[1];
      nmfontGPrintF(packet, &str_tmp, &font_pos);
      break;
    case 6:
      font_size[0] = 28.0f;
      font_size[1] = 28.0f;
      nmfontSetFSize(font_size[0], font_size[1]);
      font_col[0][0] = font_col[1][0] =
          ((vnmdispPauseSelect.cnt << 6) / 10) + 0x40;
      font_col[0][1] = font_col[1][1] =
          ((vnmdispPauseSelect.cnt << 5) / 10) + 0x40;
      font_col[0][2] = font_col[1][2] =
          0x80 - ((vnmdispPauseSelect.cnt << 6) / 10);
      font_col[2][0] = font_col[3][0] = 0x80;
      font_col[2][1] = font_col[3][1] =
          0x80 - ((vnmdispPauseSelect.cnt << 5) / 10);
      font_col[2][2] = font_col[3][2] =
          0x80 - ((vnmdispPauseSelect.cnt << 6) / 10);
      font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] = 0x80;
      nmfontSetCol(&font_col);
      tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
      font_pos[0] = (640.0f - tmp) / 2.0f;
      font_pos[1] = vnmdispPauseSelectPos[1];
      nmfontGPrintF(packet, &str_tmp, &font_pos);
      break;
    case 7:
      font_size[0] = 28.0f;
      font_size[1] = 28.0f;
      nmfontSetFSize(font_size[0], font_size[1]);
      font_col[0][0] = 0x40;
      font_col[0][1] = 0x40;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      font_col[1][0] = 0x40;
      font_col[1][1] = 0x40;
      font_col[1][2] = 0x80;
      font_col[1][3] = 0x80;
      font_col[2][0] = 0x80;
      font_col[2][1] = 0x80;
      font_col[2][2] = 0x80;
      font_col[2][3] = 0x80;
      font_col[3][0] = 0x80;
      font_col[3][1] = 0x80;
      font_col[3][2] = 0x80;
      font_col[3][3] = 0x80;
      nmfontSetCol(&font_col);
      tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
      font_pos[0] = vnmdispPauseSelectPos[0] + ((640.0f - tmp) / 2.0f);
      font_pos[1] = vnmdispPauseSelectPos[1];
      nmfontGPrintF(packet, &str_tmp, &font_pos);
      break;
    }
  }
}

static void nmdispTutoMes(VgmsysGifPkt *packet) {
  signed int i;           // r16
  char jump;              // r17
  char grind;             // r18
  char str_tmp[128];      // 0x40(r29)
  float pos_tmp[4];       // 0xC0(r29)
  float font_pos[4];      // 0xD0(r29)
  signed int font_col[4]; // 0xE0(r29)
  char spin_l[4];         // 0xF0(r29)
  char spin_r[4];         // 0xF4(r29)
  char revert[4];         // 0xF8(r29)
  char stance[4];         // 0xFC(r29)

  pos_tmp[0] = vnmdispParamPosLeft + 16.0f;
  pos_tmp[1] = 149.33333f;
  nmdispInitFont();
  if (vnmdispTutoMes.state != 0) {
    if (vnmdispTutoMes.state != 4) {
      font_pos[0] = pos_tmp[0];
      font_col[0] = 0x80;
      font_col[1] = 0x70;
      font_col[2] = 0x40;
      switch (vnmdispTutoMes.state) {
      case 1:
        font_col[3] = (vnmdispTutoMes.cnt << 7) / 20;
        break;
      case 3:
        font_col[3] = 0x80 - ((vnmdispTutoMes.cnt << 7) / 20);
        break;
      default:
        font_col[3] = 0x80;
        break;
      }
      nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
      nmfontSetFSize(20.0f, 20.0f);
      for (i = 0; i < 8; i++) {
        if (vnmdispTutoMesNum < vnmtblTutoEnd[i]) {
          break;
        }
      }
      ulstdSprintf(&str_tmp[0], "%s", vnmtblTutoItem[*vnmdispLang][i]);
      font_pos[1] = pos_tmp[1] - 28.0f;
      nmfontFPrintF(packet, &str_tmp, &font_pos);
      switch (vnmdispOption->key_config[0].grind) {
      case 0x10:
        grind = 0x82;
        break;
      case 0x20:
        grind = 0x80;
        break;
      case 0x40:
        grind = 0x81;
        break;
      case 0x80:
        grind = 0x83;
        break;
      }
      switch (vnmdispOption->key_config[0].jump) {
      case 0x10:
        jump = 0x82;
        break;
      case 0x20:
        jump = 0x80;
        break;
      case 0x40:
        jump = 0x81;
        break;
      case 0x80:
        jump = 0x83;
        break;
      }
      switch (vnmdispOption->key_config[0].spin_l) {
      case 4:
        ulstdSprintf(&spin_l, "L1");
        break;
      case 1:
        ulstdSprintf(&spin_l, "L2");
        break;
      case 8:
        ulstdSprintf(&spin_l, "R1");
        break;
      case 2:
        ulstdSprintf(&spin_l, "R2");
        break;
      default:
        ulstdSprintf(&spin_l, "  ");
        break;
      }
      switch (vnmdispOption->key_config[0].spin_r) {
      case 4:
        ulstdSprintf(&spin_r, "L1");
        break;
      case 1:
        ulstdSprintf(&spin_r, "L2");
        break;
      case 8:
        ulstdSprintf(&spin_r, "R1");
        break;
      case 2:
        ulstdSprintf(&spin_r, "R2");
        break;
      default:
        ulstdSprintf(&spin_r, "  ");
        break;
      }
      switch (vnmdispOption->key_config[0].revert) {
      case 4:
        ulstdSprintf(&revert, "L1");
        break;
      case 1:
        ulstdSprintf(&revert, "L2");
        break;
      case 8:
        ulstdSprintf(&revert, "R1");
        break;
      case 2:
        ulstdSprintf(&revert, "R2");
        break;
      default:
        ulstdSprintf(&revert, "  ");
        break;
      }
      switch (vnmdispOption->key_config[0].stance) {
      case 4:
        ulstdSprintf(&stance, "L1");
        break;
      case 1:
        ulstdSprintf(&stance, "L2");
        break;
      case 8:
        ulstdSprintf(&stance, "R1");
        break;
      case 2:
        ulstdSprintf(&stance, "R2");
        break;
      default:
        ulstdSprintf(&stance, "  ");
        break;
      }
      nmfontSetFSize(16.0f, 16.0f);
      switch (vnmdispTutoMesNum) {
      case 4:
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][0]);
        font_pos[1] = pos_tmp[1];
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][1]);
        font_pos[1] = font_pos[1] + 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][2], jump);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][3]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][4]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        break;
      case 11:
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][0]);
        font_pos[1] = pos_tmp[1];
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][1],
                     &spin_l);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][2],
                     &spin_r);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][3]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][4]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        break;
      case 16:
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][0], grind);
        font_pos[1] = pos_tmp[1];
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][1]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][2]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][3]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][4]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        break;
      case 17:
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][0]);
        font_pos[1] = pos_tmp[1];
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][1], jump);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][2]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][3]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][4]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        break;
      case 20:
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][0]);
        font_pos[1] = pos_tmp[1];
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][1],
                     &revert);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp,
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][2],
                     &stance);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][3]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        ulstdSprintf(&str_tmp, "%s",
                     vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][4]);
        font_pos[1] += 24.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos);
        break;
      default:
        for (i = 0; i < 5; i++) {
          ulstdSprintf(&str_tmp, "%s",
                       vnmtblTutoMes[*vnmdispLang][vnmdispTutoMesNum][i]);
          font_pos[1] = pos_tmp[1] + (24.0f * i);
          nmfontFPrintF(packet, &str_tmp, &font_pos);
        }
        break;
      }
    }
  }
}

static void nmdispDebugMenu(VgmsysGifPkt *packet) {}

static void nmdispSwitch( // Size: 0x10, DWARF: 0x132956
    VgmsysGifPkt *packet, signed int id) {
  float pos_tmp[4];       // r29+0x20
  char str_tmp[256];      // r29+0x30
  float font_pos[4];      // r29+0x130
  signed int font_col[4]; // r29+0x140
  // Size: 0x70, DWARF: 0x136340
  DispBar bar; // r29+0x150
  char *word_tbl[3] = {
      // r29+0x1C0
      "SWITCH", // @390
      "SWITCH", // @390
      "SWITCH"  // @390
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // r29+0x1CC

  if (vnmdispDivMode == 0) {
    pos_tmp[0] = vnmdispStancePos[id] - 16.0f;
    pos_tmp[1] = vnmdispScrBottom[id] - 26.0f;
  } else {
    if (vnmdispDivSide == 0) {
      if (id == 0) {
        pos_tmp[0] = 16.0f + vnmdispStancePos[id];
      } else {
        pos_tmp[0] = vnmdispStancePos[id] - 16.0f;
      }
    } else {
      pos_tmp[0] = vnmdispStancePos[id] - 16.0f;
    }
    pos_tmp[1] = vnmdispScrBottom[id] - 26.0f;
    if (vnmdispModeEnv->match_rule == 1) {
      pos_tmp[1] -= 20.0f;
    }
  }
  nmdispInitFont();
  ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
  tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
  if (vnmdispDivMode == 0) {
    bar.pos[0] = pos_tmp[0] - (16.0f + tmp);
  } else if (vnmdispDivSide == 0) {
    if (id == 0) {
      bar.pos[0] = pos_tmp[0];
    } else {
      bar.pos[0] = pos_tmp[0] - (16.0f + tmp);
    }
  } else {
    bar.pos[0] = pos_tmp[0] - (16.0f + tmp);
  }
  bar.pos[1] = pos_tmp[1];
  bar.col[0][0] = 0;
  bar.col[0][1] = 0;
  bar.col[0][2] = 0;
  bar.col[0][3] = 0x40;
  bar.col[1][0] = 0;
  bar.col[1][1] = 0;
  bar.col[1][2] = 0;
  bar.col[1][3] = 0x40;
  bar.col[2][0] = 0;
  bar.col[2][1] = 0;
  bar.col[2][2] = 0;
  bar.col[2][3] = 0x40;
  bar.col[3][0] = 0;
  bar.col[3][1] = 0;
  bar.col[3][2] = 0;
  bar.col[3][3] = 0x40;
  bar.option.width = 24.0f + tmp;
  bar.option.height = 12.0f;
  bar.type = 1;
  nmdrawBar(packet, &bar);
  if (vnmdispDivMode == 0) {
    font_pos[0] = pos_tmp[0] - (8.0f + tmp);
  } else if (vnmdispDivSide == 0) {
    if (id == 0) {
      font_pos[0] = 8.0f + pos_tmp[0];
    } else {
      font_pos[0] = pos_tmp[0] - (8.0f + tmp);
    }
  } else {
    font_pos[0] = pos_tmp[0] - (8.0f + tmp);
  }
  font_pos[1] = pos_tmp[1] - 6.0f;
  font_col[0] = 0x80;
  font_col[1] = 0x60;
  font_col[2] = 0x40;
  font_col[3] = 0x80;
  nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
}

static void nmdispBalance(VgmsysGifPkt *packet, signed int id) {
  sceVu0FVECTOR ofs; // 0x10(r29)
  // Size: 0x40, DWARF: 0x13A082
  DispBalance balance; // 0x20(r29)
  float ratio;         // 0x6C(r29)
  // packet: sp70
  // id: sp80
  if (vnmdispDivMode == 0) {
    ofs[0] = 112.0f;
    ofs[1] = 96.0f;
    ratio = 1.0f;
  } else {
    ofs[0] = 48.0f;
    ofs[1] = 48.0f;
    ratio = 0.8f;
  }
  if (vnmdispBalance[id].state != 0) {
    balance.data = vnmdispTexData->tex + 0x3;
    switch (vnmdispBalance[id].state) {
    case 1:
      balance.abe = (vnmdispBalance[id].cnt << 7) / 5;
      break;
    case 3:
      balance.abe = 0x80 - ((vnmdispBalance[id].cnt << 7) / 5);
      break;
    default:
      balance.abe = 0x80;
      break;
    }
    if (vnmdispBalanceInfo[id].state == 1) {
      balance.pos[0] = vnmdispScrCenter[id] - ofs[0];
      if (vnmdispDivMode == 0) {
        balance.pos[1] = vnmdispScrBottom[id] / 2.0f;
      } else if (vnmdispDivSide == 0) {
        balance.pos[1] = vnmdispScrBottom[id] / 2.0f;
      } else if (id == 0) {
        balance.pos[1] = vnmdispScrDiv / 2.0f;
      } else {
        balance.pos[1] =
            vnmdispScrDiv + ((vnmdispScrBottom[id] - vnmdispScrDiv) / 2.0f);
      }
      balance.ratio[0] = 0.8f * ratio;
      balance.ratio[1] = 1.0f;
      balance.type = 0;
      balance.per = -vnmdispBalanceInfo[id].per;
    } else {
      balance.pos[0] = vnmdispScrCenter[id];
      if (vnmdispDivMode == 0) {
        balance.pos[1] = vnmdispScrBottom[id] / 2.0f;
      } else if (vnmdispDivSide == 0) {
        balance.pos[1] = vnmdispScrBottom[id] / 2.0f;
      } else if (id == 0) {
        balance.pos[1] = vnmdispScrDiv / 2.0f;
      } else {
        balance.pos[1] =
            vnmdispScrDiv + ((vnmdispScrBottom[id] - vnmdispScrDiv) / 2.0f);
      }
      balance.pos[1] = balance.pos[1] - ofs[1];
      balance.ratio[0] = ratio;
      balance.ratio[1] = ratio;
      balance.type = 1;
      if (vspenvOption->cheats.mirror == 1) {
        balance.per = -vnmdispBalanceInfo[id].per;
      } else {
        balance.per = vnmdispBalanceInfo[id].per;
      }
    }
    nmdrawBalance2(packet, &balance);
  }
}

static void nmdispTrickName(VgmsysGifPkt *packet, signed int id) {
  switch (vnmdispTrickName[id].state) {
  case 1:
    nmdispTrickNameTrans(packet, id, 1);
    return;
  case 2:
    nmdispTrickNameTrans(packet, id, 0);
    return;
  case 3:
    nmdispTrickNameTrans(packet, id, 0);
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      break;
    case 0:
      nmdispTrickNameFreeze(packet, id);
      return;
    }
    break;
  case 4:
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      nmdispTrickNameTrans(packet, id, 2);
      return;
    case 0:
      nmdispTrickNameFaild(packet, id);
      break;
    }
    break;
  }
}

static void nmdispTrickPts(VgmsysGifPkt *packet, signed int id) {
  switch (vnmdispTrickPts[id].state) {
  case 1:
    nmdispTrickPtsTrans(packet, id, 1);
    return;
  case 2:
    nmdispTrickPtsTrans(packet, id, 0);
    return;
  case 3:
    nmdispTrickPtsTrans(packet, id, 0);
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      break;
    case 0:
      nmdispTrickPtsFreeze(packet, id);
      return;
    }
    break;
  case 4:
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      nmdispTrickPtsTrans(packet, id, 4);
      return;
    case 0:
      nmdispTrickPtsFaild(packet, id);
      break;
    }
    break;
  }
}

static void nmdispTrickPtsFreeze(VgmsysGifPkt *packet, signed int id) {
  signed int i;            // r16
  char str_tmp[128];       // 0x20(r29)
  sceVu0FVECTOR font_size; // 0xA0(r29)
  // Size: 0x70, DWARF: 0x13BC8D
  Ice ice;        // 0xB0(r29)
  float tmp;      // 0x128(r29)
  float base_pos; // 0x12C(r29)

  if (vnmdispDivMode == 0) {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  } else {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  }
  base_pos = 16.0f + (vnmdispScrBottom[id] - 48.0f);
  ulstdSprintf(&str_tmp[0], "%d", vnmdispTrickPtsDraw[id].single);
  tmp = nmfontGetStrFLen(str_tmp, font_size[0]);
  ice.pos[0] = vnmdispScrCenter[id] - (tmp / 2.0f);
  ice.pos[1] = base_pos;
  for (i = 0; i < vnmdispTrickPtsInfo[id].num; i++) {
    str_tmp[0] = vnmdispTrickPtsInfo[id].word[i].str;
    str_tmp[1] = 0;
    ice.col[0][0] = ice.col[1][0] = ice.col[2][0] = ice.col[3][0] = 0x80;
    ice.col[0][1] = ice.col[1][1] = ice.col[2][1] = ice.col[3][1] = 0x80;
    ice.col[0][2] = ice.col[1][2] = ice.col[2][2] = ice.col[3][2] = 0x80;
    ice.col[0][3] = ice.col[1][3] = (vnmdispTrickName[id].cnt << 7) / 60;
    ice.col[2][3] = ice.col[3][3] = 0x80;
    ice.data = vnmdispTexData->tex + 0x5;
    ice.width = font_size[0];
    ice.height = font_size[1];
    ice.pack = 0;
    nmdrawIceFont(packet, &str_tmp[0], &ice);
    tmp = nmfontGetStrFLen(str_tmp, font_size[0]);
    ice.pos[0] += tmp;
  }
}

static void nmdispRankVer(VgmsysGifPkt *packet) {
  float pos_tmp[4];       // 0x10(r29)
  char str_tmp[256];      // 0x20(r29)
  float font_pos[4];      // 0x120(r29)
  signed int font_col[4]; // 0x130(r29)
  // Size: 0x70, DWARF: 0x136340
  DispBar bar; // 0x140(r29)
  float tmp;   // 0x1BC(r29)

  if (vnmdispDivSide == 0) {
    pos_tmp[0] = 320.0f;
    pos_tmp[1] = (2.0f * vnmdispParamPosDown) - 26.0f;
    nmdispInitFont();
    bar.option.width = 144.0f;
    bar.option.height = 12.0f;
    bar.pos[0] =
        pos_tmp[0] - ((bar.option.width - bar.option.height / 2.0f) / 2.0f);
    bar.pos[1] = pos_tmp[1];
    bar.col[0][0] = 0;
    bar.col[0][1] = 0;
    bar.col[0][2] = 0;
    bar.col[0][3] = 0x40;
    bar.col[1][0] = 0;
    bar.col[1][1] = 0;
    bar.col[1][2] = 0;
    bar.col[1][3] = 0x40;
    bar.col[2][0] = 0;
    bar.col[2][1] = 0;
    bar.col[2][2] = 0;
    bar.col[2][3] = 0x40;
    bar.col[3][0] = 0;
    bar.col[3][1] = 0;
    bar.col[3][2] = 0;
    bar.col[3][3] = 0x40;
    bar.type = 1;
    nmdrawBar(packet, &bar);
    if (vspDispEnvChar[0].rank == 0) {
      font_col[0] = 0x80;
      font_col[1] = 0x40;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_col[0] = 0x40;
      font_col[1] = 0x40;
      font_col[2] = 0x80;
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetPack(1);
    nmfontSetFSize(16.0f, 16.0f);
    ulstdSprintf(&str_tmp, "%s",
                 *((vspDispEnvChar[0].rank) + (&vnmtblRank2[*vnmdispLang][0])));
    tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
    font_pos[0] = pos_tmp[0] - (8.0f + tmp);
    font_pos[1] = pos_tmp[1] - 6.0f;
    nmfontFPrintF(packet, &str_tmp, font_pos);
    nmfontSetPack(0);
    nmfontSetFSize(28.0f, 28.0f);
    ulstdSprintf(&str_tmp, "%d", vspDispEnvChar[0].rank + 1);
    tmp = nmfontGetStrFLen(str_tmp, 28.0f);
    font_pos[0] = font_pos[0] - tmp;
    font_pos[1] = pos_tmp[1] - 18.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    if (vspDispEnvChar[1].rank == 0) {
      font_col[0] = 0x80;
      font_col[1] = 0x40;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_col[0] = 0x40;
      font_col[1] = 0x40;
      font_col[2] = 0x80;
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetPack(0);
    nmfontSetFSize(28.0f, 28.0f);
    ulstdSprintf(&str_tmp, "%d", vspDispEnvChar[1].rank + 1);
    tmp = nmfontGetStrFLen(str_tmp, 28.0f);
    font_pos[0] = 8.0f + pos_tmp[0];
    font_pos[1] = pos_tmp[1] - 18.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(1);
    nmfontSetFSize(16.0f, 16.0f);
    ulstdSprintf(&str_tmp, "%s",
                 *((vspDispEnvChar[1].rank) + (&vnmtblRank2[*vnmdispLang][0])));
    font_pos[0] = font_pos[0] + tmp;
    font_pos[1] = pos_tmp[1] - 6.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  }
}

static void nmdispOutMes(VgmsysGifPkt *packet, signed int id) {
  float pos_tmp[4];       // 0x20(r29)
  char str_tmp[128];      // 0x30(r29)
  float font_pos[4];      // 0xB0(r29)
  signed int font_col[4]; // 0xC0(r29)
  float font_size[4];     // 0xD0(r29)
  char *word_tbl[3] = {
      // 0xE0(r29)
      "OUT OF BOUNDS",       // @2580
      "AUSSERHALB VOM KURS", // @2581
      "HORS-PISTE"           // @2582
  };
  void *word_tbl_ptr = (void *)&word_tbl;
  float tmp; // 0xEC(r29)

  nmdispInitFont();
  nmfontSetPack(1);
  pos_tmp[0] = vnmdispScrCenter[id];
  if (vnmdispDivMode == 0) {
    pos_tmp[1] = vnmdispScrBottom[id] - 336.0f;
  } else if (vnmdispDivSide == 0) {
    pos_tmp[1] = vnmdispScrBottom[id] - 336.0f;
  } else {
    pos_tmp[1] = vnmdispScrBottom[id] - 168.0f;
  }
  // temp_a0 = id * 8;
  if (vnmdispOutMes[id].state != 0) {
    if (vnmdispDivMode == 0) {
      font_size[0] = 32.0f;
      font_size[1] = 32.0f;
    } else if (vnmdispDivSide == 0) {
      font_size[0] = 24.0f;
      font_size[1] = 32.0f;
    } else {
      font_size[0] = 32.0f;
      font_size[1] = 32.0f;
    }
    nmfontSetFSize(font_size[0], font_size[1]);
    font_col[0] = 0x80;
    font_col[1] = 0x40;
    font_col[2] = 0x40;
    switch (vnmdispOutMes[id].state) {
    case 1:
      font_col[3] = (vnmdispOutMes[id].cnt << 7) / 30;
      break;
    case 2:
      font_col[3] = 0x80;
      break;
    case 3:
      font_col[3] = 0x80 - ((vnmdispOutMes[id].cnt << 7) / 15);
      break;
    default:
      font_col[3] = 0x80;
      break;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
    font_pos[0] = pos_tmp[0] - (tmp / 2.0f);
    font_pos[1] = pos_tmp[1];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  }
}

static void nmdispDivLine(VgmsysGifPkt *packet) {
  Poly poly; // 0x10(r29)

  if (vnmdispDivSide == 0) {
    poly.vertex[0][0] = vnmdispScrDiv - 2.0f;
    poly.vertex[0][1] = 0.0f;
    poly.vertex[0][2] = 1.0f;
    poly.col[0][0] = 0x40;
    poly.col[0][1] = 0x40;
    poly.col[0][2] = 0x40;
    poly.col[0][3] = 0x40;
    poly.option.sprite = 1;
    poly.option.width = 4.0f;
    poly.option.height = 448.0f;
    nmdrawFPoly(packet, &poly);
    return;
  }
  poly.vertex[0][0] = 0.0f;
  poly.vertex[0][1] = vnmdispScrDiv - 2.0f;
  poly.vertex[0][2] = 1.0f;
  poly.col[0][0] = 0x40;
  poly.col[0][1] = 0x40;
  poly.col[0][2] = 0x40;
  poly.col[0][3] = 0x40;
  poly.option.sprite = 1;
  poly.option.width = 640.0f;
  poly.option.height = 4.0f;
  nmdrawFPoly(packet, &poly);
}

static void nmdispDivExpLine(VgmsysGifPkt *packet) {
  // Size: 0x90, DWARF: 0x140CBB
  Poly poly; // 0x10(r29)

  if (vnmdispScrDivExp != vnmdispScrDiv) {
    if (vnmdispDivSide == 0) {
      poly.vertex[0][0] = vnmdispScrDivExp - 2.0f;
      poly.vertex[0][1] = 0.0f;
      poly.vertex[0][2] = 1.0f;
      poly.col[0][0] = 0x80;
      poly.col[0][1] = 0x40;
      poly.col[0][2] = 0x40;
      poly.col[0][3] = 0x40;
      poly.option.sprite = 1;
      poly.option.width = 4.0f;
      poly.option.height = 448.0f;
      nmdrawFPoly(packet, &poly);
      return;
    }
    poly.vertex[0][0] = 0.0f;
    poly.vertex[0][1] = vnmdispScrDivExp - 2.0f;
    poly.vertex[0][2] = 1.0f;
    poly.col[0][0] = 0x80;
    poly.col[0][1] = 0x40;
    poly.col[0][2] = 0x40;
    poly.col[0][3] = 0x80;
    poly.option.sprite = 1;
    poly.option.width = 640.0f;
    poly.option.height = 4.0f;
    nmdrawFPoly(packet, &poly);
  }
}

static void nmdispFireSil(VgmsysGifPkt *packet, signed int id) {
  // Offset: 0xA0, DWARF: 0x13F42B
  DispTex tex;      // 0x10(r29)
  float pos_tmp[4]; // 0xC0(r29)

  if (vnmdispDivSide == 0) {
    if (id == 0) {
      pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    } else {
      pos_tmp[0] = vnmdispParamPosRight - 16.0f;
    }
    pos_tmp[1] = 56.0f;
    tex.data = vnmdispTexData->tex + 0x2;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 128.0f;
    tex.option.height = 80.0f;
    if (id == 0) {
      tex.tex_size[0] = 0x80;
      tex.tex_size[1] = 0x40;
      tex.tex_uv[0] = 0;
      tex.tex_uv[1] = 0x40;
      tex.vertex[0][0] = pos_tmp[0];
    } else {
      tex.tex_size[0] = -0x80;
      tex.tex_size[1] = 0x40;
      tex.tex_uv[0] = 0x80;
      tex.tex_uv[1] = 0x40;
      tex.vertex[0][0] = pos_tmp[0] - tex.option.width;
    }
    tex.vertex[0][1] = pos_tmp[1] - (tex.tex_size[1] / 2.0f);
    nmdrawFTex(packet, &tex);
  }
}

static void nmdispHorseMes(VgmsysGifPkt *packet) {
  signed int i;              // r16
  float tmp;                 // 0x208(r29)
  float pos_tmp;             // 0x20C(r29)
  char str_tmp[128];         // 0x30(r29)
  float font_pos[4];         // 0xB0(r29)
  signed int font_col[1][4]; // 0xC0(r29)
  float font_size[4];        // 0xD0(r29)
  // Size: 0x30, DWARF: 0x13519E
  Key key; // 0xE0(r29)
  // Size: 0x70, DWARF: 0x137FF4
  Point point; // 0x120(r29)
  char *mes_tbl[3][9] = {
      // 0x190(r29)
      {"SET SCORE", "MATCH", "SET SCORE AT", "NO SCORE", "GOING FOR",
       "YOU SCORED", "YOU GET A LETTER", "YOU ARE A", "SWITCH"},
      {"LEGT PUNKTZAHL VOR.", "MUSS AUSGLEICHEN:", "LEGT PUNKTESTAND VOR:",
       "KEINE PUNKTE", "ZIEL:", "ERREICHT: ", "DU ERH\220LTST DEN BUCHSTABEN",
       "DU BIST EIN LOSER!", "WECHSEL"},
      {"FIXE LE SCORE", "EGALISE A", "FIXE LE SCORE A", "N'A PAS MARQUE",
       "JOUANT POUR", "TU AS MARQUE", "TU OBTIENS LA LETTRE", "TU AS PERDU!",
       "CHANGEMENT DE JOUEUR"}};
  s32 *mes_tbl_ptr = &mes_tbl;

  nmdispInitFont();
  if (vnmdispHorseMes.state != 0) {
    if (vnmdispHorseMesType < 4) {
      pos_tmp = 168.0f;
      nmfontSetFSize(24.0f, 28.0f);
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x80;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      nmfontSetPack(1);
      ulstdSprintf(str_tmp, "%s %d", vnmtblCommon[*vnmdispLang][3],
                   vspModeData.horse_pid + 1);
      tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
      font_pos[0] = ((640.0f + vnmdispHorseMesPos[0]) - tmp) / 2.0f;
      font_pos[1] = pos_tmp;
      nmfontFPrintF(packet, str_tmp, font_pos);
      switch (vnmdispHorseMesType) {
      case 0:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][0]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[1]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 1:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][1]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[1]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        point.point = vnmdispHorsePts[vspModeData.horse_pid ^ 1];
        point.type = 0;
        point.size[0] = 0x18;
        point.size[1] = 0x1C;
        point.language = *vnmdispLang;
        tmp = nmdrawGetPointLen(&point);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        tmp += nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[2]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vnmdispHorsePts[vspModeData.horse_pid ^ 1];
        point.type = 0;
        point.size[0] = 0x18;
        point.size[1] = 0x1C;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        tmp = nmdrawGetPointLen(&point);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 2:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][2]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[1]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        point.point = vnmdispHorsePts[vspModeData.horse_pid];
        point.type = 0;
        point.size[0] = 0x18;
        point.size[1] = 0x1C;
        point.language = *vnmdispLang;
        tmp = nmdrawGetPointLen(&point);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        tmp += nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[2]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vnmdispHorsePts[vspModeData.horse_pid];
        point.type = 0;
        point.size[0] = 0x18;
        point.size[1] = 0x1C;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        tmp = nmdrawGetPointLen(&point);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 3:
        ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][3]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[1]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][8]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[2]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      }
    } else {
      pos_tmp = 126.0f;
      nmfontSetFSize(24.0f, 28.0f);
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x80;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      point.point = vnmdispHorsePts[vspModeData.horse_pid ^ 1];
      point.type = 0;
      point.size[0] = 0x18;
      point.size[1] = 0x1C;
      point.language = *vnmdispLang;
      tmp = nmdrawGetPointLen(&point);
      ulstdSprintf(str_tmp, "%s  %s", mes_tbl[*vnmdispLang][4],
                   vnmtblCommon[*vnmdispLang][0]);
      tmp += nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
      nmfontSetPack(1);
      ulstdSprintf(str_tmp, "%s ", mes_tbl[*vnmdispLang][4]);
      font_pos[0] = ((640.0f + vnmdispHorseMesPos[0]) - tmp) / 2.0f;
      font_pos[1] = pos_tmp;
      nmfontFPrintF(packet, str_tmp, font_pos);
      tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
      font_pos[0] += tmp;
      point.pos[0] = font_pos[0];
      point.pos[1] = font_pos[1];
      point.col[0][0] = font_col[0][0];
      point.col[0][1] = font_col[0][1];
      point.col[0][2] = font_col[0][2];
      point.col[0][3] = font_col[0][3];
      point.point = vnmdispHorsePts[vspModeData.horse_pid ^ 1];
      point.type = 0;
      point.size[0] = 0x18;
      point.size[1] = 0x1C;
      point.flat = 1;
      point.base = 0;
      point.language = *vnmdispLang;
      nmdrawPoint(packet, &point);
      tmp = nmdrawGetPointLen(&point);
      font_pos[0] += tmp;
      nmfontSetPack(1);
      ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
      nmfontFPrintF(packet, str_tmp, font_pos);
      point.point = vnmdispHorsePts[vspModeData.horse_pid];
      point.type = 0;
      point.size[0] = 0x18;
      point.size[1] = 0x1C;
      point.language = *vnmdispLang;
      tmp = nmdrawGetPointLen(&point);
      ulstdSprintf(str_tmp, "%s  %s", mes_tbl[*vnmdispLang][5],
                   vnmtblCommon[*vnmdispLang][0]);
      tmp += nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
      nmfontSetPack(1);
      ulstdSprintf(str_tmp, "%s ", mes_tbl[*vnmdispLang][5]);
      font_pos[0] = ((640.0f + vnmdispHorseMesPos[1]) - tmp) / 2.0f;
      font_pos[1] += 42.0f;
      nmfontFPrintF(packet, str_tmp, font_pos);
      tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
      font_pos[0] += tmp;
      point.pos[0] = font_pos[0];
      point.pos[1] = font_pos[1];
      point.col[0][0] = font_col[0][0];
      point.col[0][1] = font_col[0][1];
      point.col[0][2] = font_col[0][2];
      point.col[0][3] = font_col[0][3];
      point.point = vnmdispHorsePts[vspModeData.horse_pid];
      point.type = 0;
      point.size[0] = 0x18;
      point.size[1] = 0x1C;
      point.flat = 1;
      point.base = 0;
      point.language = *vnmdispLang;
      nmdrawPoint(packet, &point);
      tmp = nmdrawGetPointLen(&point);
      font_pos[0] += tmp;
      nmfontSetPack(1);
      ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
      nmfontFPrintF(packet, str_tmp, font_pos);
      switch (vnmdispHorseMesType) {
      case 4:
        ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][8]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[2]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 5:
        if (vnmdispHorseGet[vspModeData.horse_pid] < vnmdispHorseNum) {
          ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][6]);
        } else {
          ulstdSprintf(str_tmp, "%s", mes_tbl[*vnmdispLang][7]);
        }
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[2]) - tmp) / 2.0f;
        font_pos[1] += 42.0f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        nmfontSetPack(0);
        nmfontSetFSize(48.0f, 48.0f);
        ulstdSprintf(str_tmp, "%s", vnmdispHorseWord);
        str_tmp[vnmdispHorseGet[vspModeData.horse_pid]] = 0;
        tmp = nmfontGetStrFLen(str_tmp, 48.0f);
        font_pos[0] = ((640.0f + vnmdispHorseMesPos[3]) - tmp) / 2.0f;
        font_pos[1] += 56.0f;
        for (i = 0; i < (vnmdispHorseGet[vspModeData.horse_pid] - 1); i++) {
          str_tmp[0] = vnmdispHorseWord[i];
          str_tmp[1] = 0;
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] += 48.0f;
        }
        str_tmp[0] =
            vnmdispHorseWord[vnmdispHorseGet[vspModeData.horse_pid] - 1];
        str_tmp[1] = 0;
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x60;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        switch (vnmdispHorseMes.state) {
        case 1:
          break;
        case 2:
          font_pos[0] += 24.0f;
          font_pos[1] += 24.0f;
          if (vnmdispHorseMes.cnt < 0x3C) {
            font_size[0] = (72.0f * (f32)vnmdispHorseMes.cnt) / 60.0f;
            font_size[1] = (72.0f * (f32)vnmdispHorseMes.cnt) / 60.0f;
          } else if (vnmdispHorseMes.cnt < 0x50) {
            font_size[0] =
                72.0f - ((24.0f * (f32)(vnmdispHorseMes.cnt - 0x3C)) / 20.0f);
            font_size[1] =
                72.0f - ((24.0f * (f32)(vnmdispHorseMes.cnt - 0x3C)) / 20.0f);
          } else {
            font_size[0] = 48.0f;
            font_size[1] = 48.0f;
          }
          font_pos[0] -= font_size[0] / 2.0f;
          font_pos[1] -= font_size[1] / 2.0f;
          nmfontSetFSize(font_size[0], font_size[1]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          break;
        default:
          nmfontSetFSize(48.0f, 48.0f);
          nmfontFPrintF(packet, str_tmp, font_pos);
          break;
        }
        break;
      }
    }
    if (vnmdispOpe.state != 0) {
      key.pos[0] = 320.0f;
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.button = 0;
      key.message = 1;
      key.language = *vnmdispLang;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.center = 1;
      key.language = *vnmdispLang;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispResultCareer(VgmsysGifPkt *packet) {
  nmdispBackLogo(packet);
  nmdispLevelGoals(packet);
  nmdispStatisCareer(packet);
  nmdispHighScore(packet);
}

static void nmdispResultFreeride(VgmsysGifPkt *packet) {
  nmdispBackLogo(packet);
  nmdispStatisFreeride(packet);
}

static void nmdispResultMatch(VgmsysGifPkt *packet) {
  nmdispBackLogo(packet);
  nmdispStatisMatch(packet);
}

static void nmdispBackLogo(VgmsysGifPkt *packet) {
  // Size: 0x90, DWARF: 0x140CBB
  Poly poly; // 0x10(r29)
  // Size: 0xB0, DWARF: 0x13F356
  DispTex tex; // 0xA0(r29)

  nmdrawSwitchTest(packet, 1);
  poly.vertex[0][0] = 0.0f;
  poly.vertex[0][1] = 0.0f;
  poly.vertex[0][2] = 0.0f;
  poly.col[0][0] = 0;
  poly.col[0][1] = 0;
  poly.col[0][2] = 0;
  poly.col[0][3] = 0x40;
  poly.option.sprite = 1;
  poly.option.width = 640.0f;
  poly.option.height = 448.0f;
  nmdrawFPoly(packet, &poly);
  nmdrawSwitchTest(packet, 0);
  tex.data = vnmdispTexData->tex + 0x8;
  tex.tex_size[0] = 0x100;
  tex.tex_size[1] = 0x80;
  tex.tex_uv[0] = 0;
  tex.tex_uv[1] = 0;
  tex.vertex[0][0] = 320.0f - vnmtblCourseLogo[vnmdispCrsEnv->no][0];
  tex.vertex[0][1] = 224.0f - vnmtblCourseLogo[vnmdispCrsEnv->no][1];
  tex.col[0][0] = 0x80;
  tex.col[0][1] = 0x80;
  tex.col[0][2] = 0x80;
  tex.col[0][3] = 0x20;
  tex.option.sprite = 1;
  tex.option.bil = 1;
  tex.option.width = 2.0f * tex.tex_size[0] * 1.0f;
  tex.option.height = 2.0f * tex.tex_size[1] * 1.0f;
  nmdrawFTex(packet, &tex);
}

void nmdispCalcTotal() {
  nmdispFlowTotal();
  switch (vnmdispModeEnv->game_mode) {
  case 0:
    nmdispCalcCareer();
    return;
  case 1:
    switch (vnmdispModeEnv->match_rule) {
    case 0:
      nmdispCalcMatchAttack();
      return;
    case 1:
      nmdispCalcMatchAttack();
      return;
    case 2:
      nmdispCalcMatchPush();
      return;
    case 3:
      nmdispCalcMatchHorse();
      return;
    }
    break;
  case 2:
    nmdispCalcFreeride();
    return;
  }
}

void nmdispCalcTotalChar(signed int id) {
  switch (vnmdispModeEnv->game_mode) {
  case 0:
    nmdispCalcCareerChar(id);
    return;
  case 1:
    switch (vnmdispModeEnv->match_rule) {
    case 0:
      nmdispCalcMatchAttackChar(id);
      return;
    case 1:
      nmdispCalcMatchBoostChar(id);
      return;
    case 2:
      nmdispCalcMatchPushChar(id);
      return;
    case 3:
      nmdispCalcMatchHorseChar(id);
      return;
    }
    break;
  case 2:
    nmdispCalcFreerideChar(id);
    return;
  }
}

static void nmdispCalcCareerChar(signed int id) {
  switch (vnmdispMode) {
  case 0:
  case 1:
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcTrkMeter(id);
      nmdispCalcSwitch(id);
      nmdispCalcBalance(id);
      nmdispCalcTrickName(id);
      nmdispCalcTrickPts(id);
      nmdispCalcLevelMes();
    }
  case 3:
  case 4:
    break;
  }
}

static void nmdispCalcFreerideChar(signed int id) {
  switch (vnmdispMode) {
  case 0:
  case 1:
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcTrkMeter(id);
      nmdispCalcSwitch(id);
      nmdispCalcBalance(id);
      nmdispCalcTrickName(id);
      nmdispCalcTrickPts(id);
    }
  case 3:
  case 4:
    return;
  }
}

static void nmdispCalcMatchAttackChar(signed int id) {
  switch (vnmdispMode) {
  case 0:
  case 1:
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcTrkMeter(id);
      nmdispCalcSwitch(id);
      nmdispCalcBalance(id);
      nmdispCalcTrickName(id);
      nmdispCalcTrickPts(id);
    }
  case 3:
  case 4:
    return;
  }
}

static void nmdispCalcMatchBoostChar(signed int id) {
  switch (vnmdispMode) {
  case 0:
  case 1:
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcTrkMeter(id);
      nmdispCalcBoostMeter(id);
      nmdispCalcSwitch(id);
      nmdispCalcBalance(id);
      nmdispCalcTrickName(id);
      nmdispCalcTrickPts(id);
    }
  case 3:
  case 4:
    return;
  }
}

static void nmdispCalcMatchPushChar(signed int id) {
  switch (vnmdispMode) {
  case 0:
  case 1:
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcTrkMeter(id);
      nmdispCalcSwitch(id);
      nmdispCalcBalance(id);
      nmdispCalcTrickName(id);
      nmdispCalcTrickPts(id);
    }
  case 3:
  case 4:
    return;
  }
}

static void nmdispCalcMatchHorseChar(signed int id) {
  switch (vnmdispMode) {
  case 0:
  case 1:
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcTrkMeter(id);
      nmdispCalcSwitch(id);
      nmdispCalcBalance(id);
      nmdispCalcTrickName(id);
      nmdispCalcTrickPts(id);
    }
  case 3:
  case 4:
    return;
  }
}

static void nmdispCalcIntr() {
  switch (vnmdispIntr.state) {
  case 1:
    if (vnmdispIntr.cnt >= 0x3C) {
      vnmdispIntr.state = 2;
      vnmdispIntr.cnt = 0;
      return;
    }
    vnmdispIntr.cnt += 1;
    return;
  case 3:
    if (0x3C < vnmdispIntr.cnt) {
      vnmdispIntr.state = 0;
      vnmdispIntr.cnt = 0x3C;
      return;
    }
    vnmdispIntr.cnt += 1;
    return;
  default:
    vnmdispIntr.cnt = 0x3C;
    return;
  }
}

static void nmdispCalcOperate() {
  switch (vnmdispOpe.state) {
  case 1:
    if (vnmdispOpe.cnt == 5) {
      vnmdispOpe.state = 2;
      vnmdispOpe.cnt = 0;
      if (vnmdispOpeConnect != 1) {
        return;
      }
      vnmdispOpeAccept = 1;
      vnmdispOpeConnect = 0;
      return;
    }
    vnmdispOpe.cnt += 1;
    return;
  case 3:
    if (vnmdispOpe.cnt == 5) {
      vnmdispOpe.state = 0;
      vnmdispOpe.cnt = 0;
      return;
    }
    vnmdispOpe.cnt += 1;
    break;
  }
}

static void nmdispCalcBackGround() {
  switch (vnmdispBackGround.state) {
  case 1:
    if (vnmdispBackGround.cnt == 0xA) {
      vnmdispBackGround.state = 2;
      vnmdispBackGround.cnt = 0;
      return;
    }
    vnmdispBackGround.cnt += 1;
    return;
  case 3:
    if (vnmdispBackGround.cnt == 0xA) {
      vnmdispBackGround.state = 0;
      vnmdispBackGround.cnt = 0;
      return;
    }
    vnmdispBackGround.cnt += 1;
    return;
  }
}

static void nmdispCalcPauseCareer() {
  switch (vnmdispPause.state) {
  case 1:
    if (vnmdispBackGround.state == 2 && vnmdispPauseMenu.state == 2) {
      vnmdispPause.state = 2;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  case 3:
    if (vnmdispBackGround.state == 0 && vnmdispPauseMenu.state == 0) {
      vnmdispPause.state = 0U;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  }
  nmdispCalcBackGround();
  nmdispCalcPauseMenuCareer();
  nmdispCalcPauseSelect();
  nmdispCalcRetry();
  nmdispCalcSoundLevels();
  nmdispCalcTrickList();
  nmdispCalcLevelGoalList();
  nmdispCalcDebugMenu();
}

static void nmdispCalcPauseFreeride() {
  switch (vnmdispPause.state) {
  case 1:
    if ((vnmdispBackGround.state == 2) && vnmdispPauseMenu.state == 2) {
      vnmdispPause.state = 2;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  case 3:
    if (vnmdispBackGround.state == 0 && vnmdispPauseMenu.state == 0) {
      vnmdispPause.state = 0;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  }
  nmdispCalcBackGround();
  nmdispCalcPauseMenuFreeride();
  nmdispCalcPauseSelect();
  nmdispCalcRetry();
  nmdispCalcSoundLevels();
  nmdispCalcTrickList();
  nmdispCalcLevelGoalList();
  nmdispCalcTutorial();
  nmdispCalcDebugMenu();
}

static void nmdispCalcPauseMatch() {
  switch (vnmdispPause.state) {
  case 1:
    if ((vnmdispBackGround.state == 2) && (vnmdispPauseMenu.state == 2)) {
      vnmdispPause.state = 2;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  case 3:
    if (vnmdispBackGround.state == 0 && vnmdispPauseMenu.state == 0) {
      vnmdispPause.state = 0;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  }
  nmdispCalcBackGround();
  nmdispCalcPauseMenuMatch();
  nmdispCalcPauseSelect();
  nmdispCalcRetry();
  nmdispCalcSoundLevels();
  nmdispCalcTrickList();
  nmdispCalcDebugMenu();
}

static void nmdispCalcPauseHorse() {
  switch (vnmdispPause.state) {
  case 1:
    if (((vnmdispBackGround.state) == 2) && ((vnmdispPauseMenu.state) == 2)) {
      vnmdispPause.state = 2;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  case 3:
    if (vnmdispBackGround.state == 0 && vnmdispPauseMenu.state == 0) {
      vnmdispPause.state = 0;
      vnmdispPause.cnt = 0;
    } else {
      vnmdispPause.cnt += 1;
    }
    break;
  }
  nmdispCalcPauseMenuMatch();
  nmdispCalcPauseSelect();
  nmdispCalcRetry();
  nmdispCalcSoundLevels();
  nmdispCalcTrickList();
  nmdispCalcDebugMenu();
}

static void nmdispCalcSoundLevels() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispPauseSound.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 6;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispPauseSoundPos[0], vnmdispPauseSound.cnt);
    if (tmp == 1) {
      vnmdispPauseSound.state = 2U;
      vnmdispPauseSound.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispPauseSound.cnt += 1;
    if (vnmdispPauseSound.cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
    break;
  case 2:
    nmdispCalcMenuItem2();
    nmdispCalcAllow();
    return;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 6;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispPauseSoundPos[0], vnmdispPauseSound.cnt);
    if (tmp == 1) {
      vnmdispPauseSound.state = 0U;
      vnmdispPauseSound.cnt = 0;
      return;
    }
    vnmdispPauseSound.cnt += 1;
    if (vnmdispPauseSound.cnt == 0xA) {
      vnmdispPauseMenu.state = 1;
      vnmdispPauseMenu.cnt = 0;
    }
    break;
  }
}

static void nmdispCalcRetry(void) {
  signed int tmp; // r16

  switch (vnmdispPauseRetry.state) {
  case 1:
    if (vnmdispPauseRetry.cnt == 0x14) {
      vnmdispPauseRetry.state = 2;
      vnmdispPauseRetry.cnt = 0;
      return;
    }
    vnmdispPauseRetry.cnt += 1;
    tmp = (vnmdispPauseRetry.cnt << 7) / 20;
    spSetFade(tmp, 0xFF);
    return;
  case 2:
    if (vnmdispPauseMenu.state == 0) {
      vnmdispPauseRetry.state = 0;
      vnmdispPauseRetry.cnt = 0;
    }
    spSetFade(0x80, 0xFF);
    return;
  }
}

static void nmdispCalcTrickList(void) {
  signed int i; // r16

  for (i = 0; i < 9; i++) {
    nmdispCalcTrickListCate(i);
  }

  if (vnmdispTrickList[vnmdispPauseTrickCate].state == 2) {
    nmdispCalcAllow();
  }
}

static void nmdispCalcLevelGoalList(void) {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispLevelGoalList.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 9;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispLevelGoalList.pos[0],
                          vnmdispLevelGoalList.cnt);
    if (tmp == 1) {
      vnmdispLevelGoalList.state = 2;
      vnmdispLevelGoalList.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispLevelGoalList.cnt += 1;
    if (vnmdispLevelGoalList.cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
  case 2:
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 9;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispLevelGoalList.pos[0],
                          vnmdispLevelGoalList.cnt);
    if (tmp == 1) {
      vnmdispLevelGoalList.state = 0;
      vnmdispLevelGoalList.cnt = 0;
      return;
    }
    vnmdispLevelGoalList.cnt += 1;
    if (vnmdispLevelGoalList.cnt == 0xA) {
      vnmdispPauseMenu.state = 1;
      vnmdispPauseMenu.cnt = 0;
    }
    break;
  }
}

static void nmdispCalcTutorial() {
  switch (vnmdispPauseTutorial.state) {
  case 1:
    if (vnmdispPauseTutorial.cnt == 0x14) {
      vnmdispPauseTutorial.state = 2;
      vnmdispPauseTutorial.cnt = 0;
    } else {
      vnmdispPauseTutorial.cnt += 1;
    }
    break;
  case 3:
    if (vnmdispPauseTutorial.cnt == 0x14) {
      vnmdispPauseTutorial.state = 0;
      vnmdispPauseTutorial.cnt = 0;
    } else {
      vnmdispPauseTutorial.cnt += 1;
    }
    break;
  }
  nmdispCalcTutoMes();
}

static void nmdispCalcDebugMenu() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispPauseDebug.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 5;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispPauseDebugPos[0], vnmdispPauseDebug.cnt);
    if (tmp == 1) {
      vnmdispPauseDebug.state = 2;
      vnmdispPauseDebug.cnt = 0;
      vnmdispAllow.state = 1;
      vnmdispAllow.cnt = 0;
      vnmdispOpeAccept = 1;
    } else {
      vnmdispPauseDebug.cnt += 1;
      if (vnmdispPauseDebug.cnt == 0xA) {
        vnmdispOpe.state = 1;
        vnmdispOpe.cnt = 0;
        vnmdispOpeConnect = 0;
      }
    }
    break;
  case 2:
    nmdispCalcMenuItem();
    nmdispCalcAllow();
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 5;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispPauseDebugPos[0], vnmdispPauseDebug.cnt);
    if (tmp == 1) {
      vnmdispPauseDebug.state = 0;
      vnmdispPauseDebug.cnt = 0;
    } else {
      vnmdispPauseDebug.cnt += 1;
      if (vnmdispPauseDebug.cnt == 0xA) {
        switch (vnmdispPauseDebugFlow) {
        case 0:
          vnmdispPauseMenu.state = 1;
          vnmdispPauseMenu.cnt = 0;
          break;
        case 2:
          nmdispInitList(&vnmdispGapList);
          vnmdispGapList.state = 1;
          vnmdispGapList.cnt = 0;
          break;
        }
      }
    }
    break;
  }
  nmdispCalcGapList();
}

static void nmdispCalcGapList() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispGapList.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 0xB;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispGapList.pos[0], vnmdispGapList.cnt);
    if (tmp == 1) {
      vnmdispGapList.state = 2;
      vnmdispGapList.cnt = 0;
      vnmdispAllow.state = 1;
      vnmdispAllow.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispGapList.cnt += 1;
    if (vnmdispGapList.cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
    break;
  case 2:
    nmdispCalcAllow();
    return;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 0xB;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispGapList.pos[0], vnmdispGapList.cnt);
    if (tmp == 1) {
      vnmdispGapList.state = 0;
      vnmdispGapList.cnt = 0;
      return;
    }
    vnmdispGapList.cnt += 1;
    if (vnmdispGapList.cnt == 0xA) {
      vnmdispPauseDebug.state = 1;
      vnmdispPauseDebug.cnt = 0;
    }
    break;
  }
}

static void nmdispCalcMenuItem() {
  switch (vnmdispMenuItem.state) {
  case 1:
    if (vnmdispMenuItem.cnt == 3) {
      vnmdispMenuItem.state = 2;
      vnmdispMenuItem.cnt = 0;
      return;
    }
    vnmdispMenuItem.cnt += 1;
    return;
  case 2:
    if (vnmdispMenuItem.cnt == 2) {
      vnmdispMenuItem.state = 0;
      vnmdispMenuItem.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispMenuItem.cnt += 1;
    return;
  }
}

static void nmdispCalcMenuItem2() {
  switch (vnmdispMenuItem.state) {
  case 1:
    if (vnmdispMenuItem.cnt == 2) {
      vnmdispMenuItem.state = 2;
      vnmdispMenuItem.cnt = 0;
      return;
    }
    vnmdispMenuItem.cnt += 1;
    return;
  case 2:
    if (vnmdispMenuItem.cnt == 2) {
      vnmdispMenuItem.state = 0;
      vnmdispMenuItem.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispMenuItem.cnt += 1;
    return;
  }
}

static void nmdispCalcAllow() {
  switch (vnmdispAllow.state) {
  case 1:
    if (vnmdispAllow.cnt == 0x28) {
      vnmdispAllow.state = 3;
      vnmdispAllow.cnt = 0;
      return;
    }
    vnmdispAllow.cnt += 1;
    return;
  case 3:
    if (vnmdispAllow.cnt == 0x28) {
      vnmdispAllow.state = 1;
      vnmdispAllow.cnt = 0;
      return;
    }
    vnmdispAllow.cnt += 1;
    return;
  }
}

static void nmdispCalcTimeLeft() {
  switch (vnmdispTimeLeft.state) {
  case 0:
    if (vspDispEnv.time_left == 5) {
      vnmdispTimeLeft.state = 3U;
      vnmdispTimeLeft.cnt = 0;
    }
  case 1:
    if (vnmdispTimeLeft.cnt == 0x14) {
      if (vspDispEnv.time_left == 0) {
        vnmdispTimeLeft.state = 0U;
      } else {
        vnmdispTimeLeft.state = 3;
      }
      vnmdispTimeLeft.cnt = 0;
      return;
    }
    vnmdispTimeLeft.cnt += 1;
    return;
  case 3:
    if (vnmdispTimeLeft.cnt == 0x14) {
      vnmdispTimeLeft.state = 1;
      vnmdispTimeLeft.cnt = 0;
      return;
    }
    vnmdispTimeLeft.cnt += 1;
    return;
  }
}

static void nmdispCalcTrkMeter(signed int id) {
  // s32 id;
  // s32 temp_a0;
  // s32* temp_a0_2;
  // s32* temp_a0_3;
  // u8* temp_a0_4;

  // id = id;
  // temp_a0 = vnmdispSpMeter[id].state & 0xFF;
  switch (vnmdispSpMeter[id].state) {
  case 0:
    if (vspDispEnvChar[id].bar.left != 0) {
      vnmdispSpMeter[id].state = 1;
      vnmdispSpMeter[id].cnt = 0;
      vnmdispSpMeterLen[id] = vspDispEnvChar[id].bar.charge;
    }
    break;
  case 1:
    if (vnmdispSpMeter[id].cnt == 0x1E) {
      vnmdispSpMeter[id].state = 2;
      vnmdispSpMeter[id].cnt = 0;
    } else {
      vnmdispSpMeter[id].cnt += 1;
    }
    break;
  case 2:
    if (vnmdispSpMeter[id].cnt == 0x1E) {
      vnmdispSpMeter[id].state = 1;
      vnmdispSpMeter[id].cnt = 0;
    } else {
      vnmdispSpMeter[id].cnt += 1;
    }
    break;
  }
  if (vspDispEnvChar[id].bar.left == 0) {
    vnmdispSpMeter[id].state = 0;
    vnmdispSpMeter[id].cnt = 0;
  }
  if ((vnmdispSpMeterLen[id]) < (vspDispEnvChar[id].bar.charge)) {
    vnmdispSpMeterLen[id] += 1;
  } else if (vnmdispSpMeterLen[id] > vspDispEnvChar[id].bar.charge) {
    vnmdispSpMeterLen[id] = vspDispEnvChar[id].bar.charge;
  }
  if (0x64 < vnmdispSpMeterLen[id]) {
    vnmdispSpMeterLen[id] = 0x64;
    return;
  }
  if (vnmdispSpMeterLen[id] < 0) {
    vnmdispSpMeterLen[id] = 0;
  }
}

static void nmdispCalcBoostMeter(signed int id) {
  if (vnmdispBoostMeterLen[id] < vspDispEnvChar[id].match.boost.charge) {
    vnmdispBoostMeterLen[id] += 1;
  } else if (vnmdispBoostMeterLen[id] > vspDispEnvChar[id].match.boost.charge) {
    vnmdispBoostMeterLen[id] = vspDispEnvChar[id].match.boost.charge;
  }
  if (0x64 < vnmdispBoostMeterLen[id]) {
    vnmdispBoostMeterLen[id] = 0x64;
    return;
  }
  if (vnmdispBoostMeterLen[id] < 0) {
    vnmdispBoostMeterLen[id] = 0;
  }
}

static void nmdispCalcSwitch(signed int id) {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  if (vspRider[id]->ctrl.act.fakie != vnmdispFakie[id]) {
    switch (vnmdispStance[id].state) {
    case 0:
      vnmdispStance[id].state = 1;
      vnmdispStance[id].cnt = 0;
      if (vnmdispDivMode == 0) {
        vnmdispStancePos[id] = 800.0f;
      } else if (vnmdispDivSide == 0) {
        if (id == 0) {
          vnmdispStancePos[id] = -160.0f;
        } else {
          vnmdispStancePos[id] = 800.0f;
        }
      } else {
        vnmdispStancePos[id] = 800.0f;
      }
      break;
    case 1:
      vnmdispStance[id].state = 3;
      vnmdispStance[id].cnt = 0xA - vnmdispStance[id].cnt;
      if (vnmdispDivMode == 0) {
        vnmdispStancePos[id] = 640.0f;
      } else if (vnmdispDivSide == 0) {
        if (id == 0) {
          vnmdispStancePos[id] = 0.0f;
        } else {
          vnmdispStancePos[id] = 640.0f;
        }
      } else {
        vnmdispStancePos[id] = 640.0f;
      }
      break;
    case 2:
      vnmdispStance[id].state = 3;
      vnmdispStance[id].cnt = 0;
      vnmdispStancePos[id] = 640.0f;
      break;
    case 3:
      vnmdispStance[id].state = 1;
      vnmdispStance[id].cnt = 0xA - vnmdispStance[id].cnt;
      if (vnmdispDivMode == 0) {
        vnmdispStancePos[id] = 800.0f;
      } else if (vnmdispDivSide == 0) {
        if (id == 0) {
          vnmdispStancePos[id] = 0.0f;
        } else {
          vnmdispStancePos[id] = 800.0f;
        }
      } else {
        vnmdispStancePos[id] = 800.0f;
      }
      break;
    }
    vnmdispFakie[id] = vspRider[id]->ctrl.act.fakie;
  }
  switch (vnmdispStance[id].state) {
  case 1:
    if (vnmdispDivMode == 0) {
      info.start = 800.0f;
      info.dir = 1;
    } else if (vnmdispDivSide == 0) {
      if (id == 0) {
        info.start = -160.0f;
        info.dir = 0;
      } else {
        info.start = 800.0f;
        info.dir = 1;
      }
    } else {
      info.start = 800.0f;
      info.dir = 1;
    }
    info.length = 160.0f;
    info.frame = 0xA;
    info.vel = 1;
    info.lag = 0;
    info.num = 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispStancePos[id], vnmdispStance[id].cnt);
    if (tmp == 1) {
      vnmdispStance[id].state = 2;
      vnmdispStance[id].cnt = 0;
      return;
    }
    vnmdispStance[id].cnt += 1;
    return;
  case 3:
    if (vnmdispDivMode == 0) {
      info.start = 640.0f;
      info.dir = 0;
    } else if (vnmdispDivSide == 0) {
      if (id == 0) {
        info.start = 0.0f;
        info.dir = 1;
      } else {
        info.start = 640.0f;
        info.dir = 0;
      }
    } else {
      info.start = 640.0f;
      info.dir = 0;
    }
    info.length = 160.0f;
    info.frame = 0xA;
    info.vel = 0;
    info.lag = 0;
    info.num = 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispStancePos[id], vnmdispStance[id].cnt);
    if (tmp == 1) {
      vnmdispStance[id].state = 0;
      vnmdispStance[id].cnt = 0;
      return;
    }
    vnmdispStance[id].cnt += 1;
    return;
  }
}

static void nmdispCalcBalance(signed int id) {
  switch (vnmdispBalance[id].state) {
  case 0:
    if (vspDispEnvChar[id].balance.state != 0) {
      vnmdispBalance[id].state = 1;
      vnmdispBalance[id].cnt = 0;
      vnmdispBalanceInfo[id].state = vspDispEnvChar[id].balance.state;
      vnmdispBalanceInfo[id].per = vspDispEnvChar[id].balance.per;
      if (vnmdispBalanceInfo[id].per > 1.0f) {
        vnmdispBalanceInfo[id].per = 1.0f;
        return;
      }
      if (vnmdispBalanceInfo[id].per < -1.0f) {
        vnmdispBalanceInfo[id].per = -1.0f;
        return;
      }
    }
    break;
  case 1:
    if (vnmdispBalance[id].cnt == 5) {
      vnmdispBalance[id].state = 2;
      vnmdispBalance[id].cnt = 0;
    } else {
      vnmdispBalance[id].cnt += 1;
    }
    if (vspDispEnvChar[id].balance.state == 0) {
      vnmdispBalance[id].state = 3;
      vnmdispBalance[id].cnt = 0;
      return;
    }
    vnmdispBalanceInfo[id].state = vspDispEnvChar[id].balance.state;
    vnmdispBalanceInfo[id].per = vspDispEnvChar[id].balance.per;
    if (vnmdispBalanceInfo[id].per > 1.0f) {
      vnmdispBalanceInfo[id].per = 1.0f;
      return;
    }
    if (vnmdispBalanceInfo[id].per < -1.0f) {
      vnmdispBalanceInfo[id].per = -1.0f;
      return;
    }
    break;
  case 2:
    if (vspDispEnvChar[id].balance.state == 0) {
      vnmdispBalance[id].state = 3;
      vnmdispBalance[id].cnt = 0;
      return;
    }
    vnmdispBalanceInfo[id].state = vspDispEnvChar[id].balance.state;
    vnmdispBalanceInfo[id].per = vspDispEnvChar[id].balance.per;
    if (vnmdispBalanceInfo[id].per > 1.0f) {
      vnmdispBalanceInfo[id].per = 1.0f;
      return;
    }
    if (vnmdispBalanceInfo[id].per < -1.0f) {
      vnmdispBalanceInfo[id].per = -1.0f;
      return;
    }
    break;
  case 3:
    if (vnmdispBalance[id].cnt == 5) {
      vnmdispBalance[id].state = 0;
      vnmdispBalance[id].cnt = 0;
      vnmdispBalanceInfo[id].state = 0;
      vnmdispBalanceInfo[id].per = 0.0f;
      return;
    }
    vnmdispBalance[id].cnt += 1;
    break;
  }
}

static void nmdispCalcTrickName(signed int id) {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x1391C8
  DispInfo info; // 0x20(r29)

  switch (vnmdispTrickName[id].state) {
  case 1:
    if (vnmdispTrickName[id].cnt == 0xA) {
      if (vnmdispTrickEnd[id] == 1) {
        if (vnmdispTrickSuccess[id] == 0) {
          if (vnmdispDivMode == 0) {
            info.font = 16.0f;
            info.line = 3;
          } else {
            if (vnmdispDivSide == 0) {
              info.line = 3;
            } else {
              info.line = 2;
            }
            info.font = 16.0f;
          }
          nmtrickMakeStr(id, &info, &vnmdispTrickNameList[id]);
        }
        vnmdispTrickName[id].state = 3;
        vnmdispTrickName[id].cnt = 0;
      } else {
        vnmdispTrickName[id].state = 2;
        vnmdispTrickName[id].cnt = 0;
      }
    } else {
      vnmdispTrickName[id].cnt += 1;
    }
    nmdispCalcTrickNameCol(id);
    return;
  case 2:
    if (vnmdispTrickEnd[id] == 1) {
      if (vnmdispTrickSuccess[id] == 0) {
        if (vnmdispDivMode == 0) {
          info.font = 16.0f;
          info.line = 3;
        } else {
          if (vnmdispDivSide == 0) {
            info.line = 3;
          } else {
            info.line = 2;
          }
          info.font = 16.0f;
        }
        nmtrickMakeStr(id, &info, &vnmdispTrickNameList[id]);
      }
      vnmdispTrickName[id].state = 3;
      vnmdispTrickName[id].cnt = 0;
    }
    nmdispCalcTrickNameCol(id);
    return;
  case 3:
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      if (vnmdispTrickName[id].cnt == 0x78) {
        vnmdispTrickName[id].state = 4;
        vnmdispTrickName[id].cnt = 0;
      } else {
        vnmdispTrickName[id].cnt += 1;
      }
      break;
    case 0:
      if (vnmdispTrickName[id].cnt == 0x3C) {
        vnmdispTrickName[id].state = 4;
        vnmdispTrickName[id].cnt = 0;
        vnmdispTrickEffectType[id] = rand() % 4;
      } else {
        vnmdispTrickName[id].cnt += 1;
      }
      break;
    }
    nmdispCalcTrickNameCol(id);
    return;
  case 4:
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      if (vnmdispTrickName[id].cnt == 0x14) {
        vnmdispTrickName[id].state = 0;
        vnmdispTrickName[id].cnt = 0;
        return;
      }
      vnmdispTrickName[id].cnt += 1;
      return;
    case 0:
      tmp = nmdispCalcTrickNameFaild(id);
      if (tmp == 0) {
        vnmdispTrickName[id].state = 0;
        vnmdispTrickName[id].cnt = 0;
      }
      return;
    }
    break;
  }
}

static void nmdispCalcLevelMes() {
  signed int i;   // r16
  signed int tmp; // r17
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x30(r29)

  for (i = 0; i < 8; i++) {
    switch (vnmdispLevelMes[i].state) {
    case 1:
      info.start = -640.0f;
      info.length = 640.0f;
      info.frame = 0xF;
      info.dir = 0;
      info.vel = 1;
      info.lag = 0;
      info.num = 1;
      info.skip = 0;
      tmp = nmdispCalcSlide(&info, &vnmdispLevelMesPos[i],
                            vnmdispLevelMes[i].cnt);
      if (tmp == 1) {
        if (i < 4) {
          tmp = 4;
        } else {
          tmp = -4;
        }
        switch (vnmdispLevelMes[i + tmp].state) {
        case 1:
          vnmdispLevelMes[i].state = 3;
          break;
        default:
          vnmdispLevelMes[i].state = 2;
          break;
        }
        vnmdispLevelMes[i].cnt = 0;
      } else {
        vnmdispLevelMes[i].cnt += 1;
      }
      break;
    case 2:
      if (vnmdispLevelMes[i].cnt == 0x3C) {
        vnmdispLevelMes[i].state = 3;
        vnmdispLevelMes[i].cnt = 0;
      } else {
        vnmdispLevelMes[i].cnt += 1;
      }
      break;
    case 3:
      info.start = 0.0f;
      info.length = 640.0f;
      info.frame = 0xF;
      info.dir = 0;
      info.vel = 0;
      info.lag = 0;
      info.num = 1;
      info.skip = 0;
      tmp = nmdispCalcSlide(&info, &vnmdispLevelMesPos[i],
                            vnmdispLevelMes[i].cnt);
      if (tmp == 1) {
        vnmdispLevelMes[i].state = 0;
        vnmdispLevelMes[i].cnt = 0;
      } else {
        vnmdispLevelMes[i].cnt += 1;
      }
      break;
    }
  }
}

static void nmdispCalcOutMes() {
  signed int i; // r16

  for (i = 0; i < 2; i++) {
    switch (vnmdispOutMes[i].state) {
    case 1:
      if (vnmdispOutMes[i].cnt == 0x1E) {
        vnmdispOutMes[i].state = 2;
        vnmdispOutMes[i].cnt = 0;
      } else {
        vnmdispOutMes[i].cnt++;
      }
      break;
    case 2:
      if (vnmdispOutMes[i].cnt == 0x2D) {
        vnmdispOutMes[i].state = 3;
        vnmdispOutMes[i].cnt = 0;
      } else {
        vnmdispOutMes[i].cnt++;
      }
      break;
    case 3:
      if (vnmdispOutMes[i].cnt == 0xF) {
        vnmdispOutMes[i].state = 0;
        vnmdispOutMes[i].cnt = 0;
      } else {
        vnmdispOutMes[i].cnt++;
      }
      break;
    }
  }
}

static void nmdispCalcDivExp() {
  if (vnmdispDivSide == 0) {
    vnmdispScrDivExp =
        ((vspDispEnv.div_exp / 1.0f) / (vsppScrWidth / 2) * 320.0f);
    return;
  }
  vnmdispScrDivExp =
      ((vspDispEnv.div_exp / 1.0f) / (vsppScrHeight / 2) * 224.0f);
}

static void nmdispCalcDivImage(void) {
  signed int i; // r16

  for (i = 0; i < 5; i++) {
    switch (vnmdispLineImage[i].state) {
    case 3:
      if (vnmdispLineImage[i].cnt == 0x14) {
        vnmdispLineImage[i].state = 0;
        vnmdispLineImage[i].cnt = 0;
      } else {
        vnmdispLineImage[i].cnt++;
      }
      break;
    }
  }
}

static void nmdispCalcWinLoseDraw() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispWin.state) {
  case 1:
    if (vspDispEnvChar->rank == 0) {
      info.start = 640.0f;
      info.dir = 1;
    } else {
      if (vnmdispDivSide == 0) {
        if (vnmdispModeEnv->match_rule == 2) {
          info.start = -640.0f;
        } else {
          info.start = -320.0f;
        }
      } else {
        info.start = -640.0f;
      }
      info.dir = 0;
    }
    info.length = 640.0f;
    info.frame = 0x28;
    info.vel = 1;
    info.lag = 0;
    info.num = 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispWinPos[0], vnmdispWin.cnt);
    if (tmp == 1) {
      vnmdispWin.state = 2;
      vnmdispWin.cnt = 0;
    } else {
      vnmdispWin.cnt++;
    }
    break;
  case 2:
    break;
  }
  switch (vnmdispLose.state) {
  case 1:
    if (vnmdispLose.cnt == 0x78) {
      vnmdispLose.state = 2;
      vnmdispLose.cnt = 0;
    } else {
      vnmdispLose.cnt++;
    }
    break;
  case 2:
    break;
  }
  switch (vnmdispDraw.state) {
  case 1:
    if (vnmdispDraw.cnt == 0x1E) {
      vnmdispDraw.state = 2;
      vnmdispDraw.cnt = 0;
      return;
    }
    vnmdispDraw.cnt++;
    return;
  case 2:
    if (vnmdispDraw.cnt == 0xA) {
      vnmdispDraw.state = 3;
      vnmdispDraw.cnt = 0;
      return;
    }
    vnmdispDraw.cnt++;
  case 3:
    return;
  }
}

static void nmdispCalcHorseEnter() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispHorseEnter.state) {
  case 1:
    info.start = -640.0f;
    info.dir = 0;
    info.length = 640.0f;
    info.frame = 0xA;
    info.vel = 1;
    info.lag = 2;
    info.num = 2;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispHorseEnterPos[0], vnmdispHorseEnter.cnt);
    if (tmp == 1) {
      vnmdispHorseEnter.state = 2;
      vnmdispHorseEnter.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispHorseEnter.cnt++;
    if (vnmdispHorseEnter.cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
    break;
  case 2:
    if (vnmdispHorseEnter.cnt == 0x78) {
      vnmdispHorseEnter.cnt = 0;
      return;
    }
    vnmdispHorseEnter.cnt++;
    return;
  case 3:
    info.start = 0.0f;
    info.dir = 0;
    info.length = 640.0f;
    info.frame = 0xA;
    info.vel = 0;
    info.lag = 2;
    info.num = 2;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispHorseEnterPos[0], vnmdispHorseEnter.cnt);
    if (tmp == 1) {
      vnmdispHorseEnter.state = 0;
      vnmdispHorseEnter.cnt = 0;
      return;
    }
    vnmdispHorseEnter.cnt++;
    if (vnmdispHorseEnter.cnt == 0xA) {
      vnmdispHorseMes.state = 1;
      vnmdispHorseMes.cnt = 0;
    }
    break;
  }
}

static void nmdispCalcHorseMes() {
  // Size: 0x10, DWARF: 0x135A42
  Info info;      // 0x20(r29)
  signed int tmp; // r16

  switch (vnmdispHorseMes.state) {
  case 1:
    info.start = -640.0f;
    info.dir = 0;
    info.length = 640.0f;
    info.frame = 0xA;
    info.vel = 1;
    info.lag = 2;
    switch (vnmdispHorseMesType) {
    case 1:
    case 2:
    case 3:
    case 4:
      info.num = 3;
      break;
    case 5:
      info.num = 4;
      break;
    default:
      info.num = 2;
      break;
    }
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispHorseMesPos[0], vnmdispHorseMes.cnt);
    if (tmp == 1) {
      if ((vnmdispHorseMesType) == 5) {
        vnmdispHorseMes.state = 2;
        vnmdispHorseMes.cnt = 0;
        return;
      }
      vnmdispHorseMes.state = 3;
      vnmdispHorseMes.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispHorseMes.cnt++;
    if (((vnmdispHorseMesType) != 5) && (vnmdispHorseMes.cnt == 0xA)) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
    break;
  case 2:
    if (vnmdispHorseMes.cnt == 0x50) {
      vnmdispHorseMes.state = 3;
      vnmdispHorseMes.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispHorseMes.cnt++;
    if (vnmdispHorseMes.cnt == 0x3C) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
    break;
  case 4:
    info.start = 0.0f;
    info.dir = 0;
    info.length = 640.0f;
    info.frame = 0xA;
    info.vel = 0;
    info.lag = 2;
    switch (vnmdispHorseMesType) {
    case 1:
    case 2:
    case 3:
    case 4:
      info.num = 3;
      break;
    case 5:
      info.num = 4;
      break;
    default:
      info.num = 2;
      break;
    }
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispHorseMesPos[0], vnmdispHorseMes.cnt);
    if (tmp == 1) {
      vnmdispHorseMes.state = 0;
      vnmdispHorseMes.cnt = 0;
      vnmdispOpeAccept = 1;
      vnmdispHorseAccept = 1;
      return;
    }
    vnmdispHorseMes.cnt++;
    if (vnmdispHorseMes.cnt == 0xA) {
      vnmdispBackGround.state = 3;
      vnmdispBackGround.cnt = 0;
    }
    break;
  }
}

static void nmdispCalcResultCareer() {
  nmdispCalcResultFade();
  nmdispCalcLevelGoals();
  nmdispCalcStatisCareer();
  nmdispCalcHighScore();
}

static void nmdispCalcResultFreeride() {
  nmdispCalcResultFade();
  nmdispCalcStatisFreeride();
}

static void nmdispCalcResultMatch() {
  nmdispCalcResultFade();
  nmdispCalcStatisMatch();
}

static void nmdispCalcResultFade() {
  signed int tmp; // r16

  switch (vnmdispResultFade.state) {
  case 1:
    tmp = (vnmdispResultFade.cnt << 7) / 20;
    spSetFade(tmp, 0xFF);
    if (vnmdispResultFade.cnt == 0x14) {
      vnmdispResultFade.state = 0;
      vnmdispResultFade.cnt = 0;
      return;
    }
    vnmdispResultFade.cnt++;
    return;
  case 3:
    tmp = 0x80 - ((vnmdispResultFade.cnt << 7) / 20);
    spSetFade(tmp, 0xFF);
    if (vnmdispResultFade.cnt == 0x14) {
      vnmdispResultFade.state = 0;
      vnmdispResultFade.cnt = 0;
      return;
    }
    vnmdispResultFade.cnt++;
    return;
  }
}

static void nmdispCalcLevelGoals() {
  // Size: 0x10, DWARF: 0x135A42
  Info info;      // 0x20(r29)
  signed int tmp; // r16

  switch (vnmdispLevelGoals.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0x14;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 0xB;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispLevelGoalsPos[0], vnmdispLevelGoals.cnt);
    if (tmp == 1) {
      if (vnmdispResultFade.state == 0) {
        vnmdispLevelGoals.state = 2;
        vnmdispLevelGoals.cnt = 0;
      }
    } else {
      vnmdispLevelGoals.cnt++;
    }
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 0xB;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispLevelGoalsPos[0], vnmdispLevelGoals.cnt);
    if (tmp == 1) {
      vnmdispLevelGoals.state = 0;
      vnmdispLevelGoals.cnt = 0;
      vnmdispSoft.state = 0;
      vnmdispSoft.cnt = 0;
    } else {
      vnmdispLevelGoals.cnt++;
      if (vnmdispLevelGoals.cnt == 0xA) {
        vnmdispStatistics.state = 1;
        vnmdispStatistics.cnt = 0;
        nmvcPlay(0x1A, 5, 2);
        vnmdispResultFlow = 2;
      }
    }
    break;
  }
  nmdispCalcGameSoft();
  nmdispCalcCheckMark();
  nmdispCalcCareerUp();
}

static void nmdispCalcStatisCareer() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispStatistics.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = vnmdispCombLine + 9;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispStatisticsPos[0], vnmdispStatistics.cnt);
    if (tmp == 1) {
      if (vnmdispResultFade.state == 0) {
        vnmdispStatistics.state = 2;
        vnmdispStatistics.cnt = 0;
      }
    } else {
      vnmdispStatistics.cnt++;
    }
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = vnmdispCombLine + 9;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispStatisticsPos[0], vnmdispStatistics.cnt);
    if (tmp == 1) {
      vnmdispStatistics.state = 0;
      vnmdispStatistics.cnt = 0;
    } else {
      vnmdispStatistics.cnt++;
      if (vnmdispStatistics.cnt == 0xA) {
        vnmdispHighScore.state = 1;
        vnmdispHighScore.cnt = 0;
        nmvcPlay(0x1A, 5, 2);
        vnmdispResultFlow = 3;
      }
    }
    break;
  }
  nmdispCalcCareerUp();
}

static void nmdispCalcStatisFreeride() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispStatistics.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = vnmdispCombLine + 4;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispStatisticsPos[0], vnmdispStatistics.cnt);
    if (tmp == 1) {
      if (vnmdispResultFade.state == 0) {
        vnmdispStatistics.state = 2;
        vnmdispStatistics.cnt = 0;
      }
    } else {
      vnmdispStatistics.cnt++;
    }
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = vnmdispCombLine + 4;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispStatisticsPos[0], vnmdispStatistics.cnt);
    if (tmp == 1) {
      if (vnmdispResultFade.state == 0) {
        vnmdispStatistics.state = 0;
        vnmdispStatistics.cnt = 0;
        vnmdispResultFlow = 5;
      }
    } else {
      vnmdispStatistics.cnt++;
    }
    break;
  }
  nmdispCalcCareerUp();
}

static void nmdispCalcStatisMatch() {
  // Size: 0x10, DWARF: 0x135A42
  Info info;      // 0x20(r29)
  signed int tmp; // r16

  switch (vnmdispStatistics.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 0x10;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispStatisticsPos[0], vnmdispStatistics.cnt);
    if (tmp == 1) {
      if (vnmdispResultFade.state == 0) {
        vnmdispStatistics.state = 2;
        vnmdispStatistics.cnt = 0;
        vnmdispOpe.state = 1;
        vnmdispOpe.cnt = 0;
        vnmdispOpeConnect = 1;
      }
    } else {
      vnmdispStatistics.cnt++;
    }
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 0x10;
    info.skip = 0;
    tmp =
        nmdispCalcSlide(&info, &vnmdispStatisticsPos[0], vnmdispStatistics.cnt);
    if (tmp == 1) {
      if (vnmdispResultFade.state == 0) {
        vnmdispStatistics.state = 0;
        vnmdispStatistics.cnt = 0;
        vnmdispResultFlow = 5;
      }
    } else {
      vnmdispStatistics.cnt++;
    }
    break;
  }
  nmdispCalcCareerUp();
}

static void nmdispCalcHighScore() {
  // Size: 0x10, DWARF: 0x135A42
  Info info;      // 0x20(r29)
  signed int tmp; // r16

  switch (vnmdispHighScore.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 7;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispHighScorePos[0], vnmdispHighScore.cnt);
    if (tmp == 1) {
      vnmdispHighScore.state = 2U;
      vnmdispHighScore.cnt = 0;
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 1;
      return;
    }
    vnmdispHighScore.cnt++;
    return;
  case 2:
    if (vnmdispHighScore.cnt == 0x78) {
      vnmdispHighScore.cnt = 0;
      return;
    }
    vnmdispHighScore.cnt++;
    return;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0x14;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 7;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispHighScorePos[0], vnmdispHighScore.cnt);
    if (tmp == 1) {
      if (vnmdispResultFade.state == 0) {
        vnmdispHighScore.state = 0U;
        vnmdispHighScore.cnt = 0;
        vnmdispResultFlow = 5;
        return;
      }
    } else {
      vnmdispHighScore.cnt++;
      return;
    }
    break;
  }
}

static void nmdispCalcGameSoft() {
  signed int cnt; // r16
  signed int tmp; // r17
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x30(r29)

  switch (vnmdispLevelGoals.state) {
  case 1:
    info.start = -2048.0f;
    info.length = 2048.0f;
    info.frame = 0x14;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 1;
    info.skip = 0;
    cnt = vnmdispLevelGoals.cnt - 0x14;
    if (cnt >= 0) {
      tmp = nmdispCalcSlide(&info, &vnmdispSoftPos, cnt);
    } else {
      vnmdispSoftPos = -2048.0f;
    }
    break;
  case 2:
    vnmdispSoftPos = 0.0f;
    break;
  case 3:
    info.start = 0.0f;
    info.length = 2048.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 1;
    info.skip = 0;
    cnt = vnmdispLevelGoals.cnt - 0x14;
    if (cnt >= 0) {
      tmp = nmdispCalcSlide(&info, &vnmdispSoftPos, cnt);
    } else {
      vnmdispSoftPos = 0.0f;
    }
    break;
  }
  if (vnmdispSoft.state != 0) {
    if (vnmdispSoft.cnt < 0x12C) {
      vnmdispSoft.cnt++;
      return;
    }
    vnmdispSoft.cnt = 0;
  }
}

static void nmdispCalcCheckMark() {
  signed int i; // r16

  for (i = 0; i < 9; i++) {
    switch (vnmdispLevelMark[i].state) {
    case 1:
      if (vnmdispLevelMark[i].cnt == 5) {
        vnmdispLevelMark[i].state = 2;
      } else {
        vnmdispLevelMark[i].cnt++;
      }
      break;
    case 2:
      if (vnmdispLevelMark[i].cnt == 0xA) {
        vnmdispLevelMark[i].state = 3;
        vnmdispLevelMark[i].cnt = 0;
      } else {
        vnmdispLevelMark[i].cnt++;
      }
      break;
    }
  }
}

static void nmdispCalcCareerUp() {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispLevelCareer.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xF;
    info.dir = 0;
    info.vel = 1;
    info.lag = 5;
    info.num = vnmdispCareerItem.num + 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispLevelCareerPos[0],
                          vnmdispLevelCareer.cnt);
    if (tmp == 1) {
      vnmdispLevelCareer.state = 2;
      vnmdispLevelCareer.cnt = 0;
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 1;
      return;
    }
    vnmdispLevelCareer.cnt++;
    return;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xF;
    info.dir = 0;
    info.vel = 0;
    info.lag = 5;
    info.num = vnmdispCareerItem.num + 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispLevelCareerPos[0],
                          vnmdispLevelCareer.cnt);
    if (tmp == 1) {
      vnmdispLevelCareer.state = 0;
      vnmdispLevelCareer.cnt = 0;
      if (vnmdispResultFlow == 1) {
        vnmdispLevelFlow = 3;
        vnmdispSoftCount.state = 3;
        vnmdispSoftCount.cnt = 0;
        vnmdispCareerSearch += 1;
        return;
      }
      vnmdispStatisFlow = 1;
      vnmdispStatisSearch += 1;
      return;
    }
    vnmdispLevelCareer.cnt++;
    return;
  }
}

static void nmdispCalcReplay() {
  signed int tmp; // r16

  switch (vnmdispReplay.state) {
  case 1:
    if (vnmdispReplay.cnt == 0x1E) {
      vnmdispReplay.state = 2;
      vnmdispReplay.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispReplay.cnt++;
    tmp = 0x80 - ((vnmdispReplay.cnt << 7) / 30);
    spSetFade(tmp, 0xFF);
    return;
  case 3:
    if (vnmdispReplay.cnt == 0x1E) {
      vnmdispReplay.state = 0;
      vnmdispResultFlow = 5;
      nmsndEndGame();
      return;
    }
    vnmdispReplay.cnt++;
    tmp = (vnmdispReplay.cnt << 7) / 30;
    spSetFade(tmp, 0xFF);
    return;
  }
}

void nmdispFlowTotal() {
  switch (vnmdispModeEnv->game_mode) {
  case 0:
    nmdispFlowCareer();
    return;
  case 1:
    nmdispFlowMatch();
    return;
  case 2:
    nmdispFlowFreeride();
    return;
  }
}

static void nmdispFlowCareer(void) {
  switch (vnmdispMode) {
  case 0:
    switch (vspDispEnv.mode) {
    case 1:
      vnmdispMode = 1;
      vnmdispIntr.state = 1;
      vnmdispIntr.cnt = 0;
      return;
    case 2:
      vnmdispMode = 2;
      return;
    case 4:
      vnmdispMode = 4;
      vnmdispResultFlow = 4;
      vnmdispReplay.state = 1;
      vnmdispReplay.cnt = 0;
      return;
    case 5:
      vnmdispMode = 5;
      vnmdispResultFlow = 4;
      vnmdispReplay.state = 1;
      vnmdispReplay.cnt = 0;
      return;
    }
    break;
  case 1:
    if (vspDispEnv.mode == 2) {
      vnmdispMode = 2;
    }
    nmdispOpeIntr();
    return;
  case 2:
    if (vspDispEnv.mode == 3) {
      vnmdispMode = 3;
    }
    nmdispFlowSelectBgm();
    nmdispOpePauseCareer();
    return;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispFlowResultCareer();
      return;
    }
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      if (vnmdispResultFlow == 5) {
        vnmdispMode = 6;
      }
      nmdispOpeReplay();
      return;
    }
    break;
  case 5:
    if (vgmsysPadPausePid < 0) {
      if (vnmdispResultFlow == 5) {
        vnmdispMode = 6;
      }
      nmdispOpeDemo();
    }
    break;
  }
}

static void nmdispFlowFreeride(void) {
  switch (vnmdispMode) {
  case 0:
    switch (vspDispEnv.mode) {
    case 1:
      vnmdispMode = 1;
      vnmdispIntr.state = 1;
      vnmdispIntr.cnt = 0;
      return;
    case 2:
      vnmdispMode = 2;
      return;
    case 4:
      vnmdispMode = 4;
      vnmdispResultFlow = 4;
      vnmdispReplay.state = 1;
      vnmdispReplay.cnt = 0;
      return;
    case 5:
      vnmdispMode = 5;
      vnmdispResultFlow = 4;
      vnmdispReplay.state = 1;
      vnmdispReplay.cnt = 0;
      return;
    }
    break;
  case 1:
    if (vspDispEnv.mode == 2) {
      vnmdispMode = 2;
    }
    nmdispOpeIntr();
    return;
  case 2:
    if (vspDispEnv.mode == 3) {
      vnmdispMode = 3;
    }
    nmdispFlowSelectBgm();
    nmdispOpePauseFreeride();
    return;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispFlowResultFreeride();
      return;
    }
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      if (vnmdispResultFlow == 5) {
        vnmdispMode = 6;
      }
      nmdispOpeReplay();
      return;
    }
    break;
  case 5:
    if (vgmsysPadPausePid < 0) {
      if (vnmdispResultFlow == 5) {
        vnmdispMode = 6;
      }
      nmdispOpeDemo();
    }
    break;
  }
}

static void nmdispFlowSelectBgm() {
  signed int tmp; // r16

  switch (vnmdispSelectFlow) {
  case 1:
    if (vnmdispSelectCnt == 0x1E) {
      tmp = nmbgmGetSelect();
      if (vnmdispOption->bgm.table[vnmdispSelectInt] != tmp) {
        nmbgmChange2(0xF, vnmdispSelectInt, 1);
        vnmdispSelectFlow = 2;
        vnmdispOpeAccept = 0;
        return;
      }
      vnmdispSelectFlow = 0;
      return;
    }
    vnmdispSelectCnt += 1;
    return;
  case 2:
    if (nmbgmCheckQue() == 0) {
      vnmdispSelectFlow = 0;
      vnmdispOpeAccept = 1;
    }
    return;
  }
}

static void nmdispFlowResultCareer() {
  // Size: 0x10, DWARF: 0x1391C8
  DispInfo info;  // 0x30(r29)
  signed int tmp; // r17
  signed int i;   // r16

  switch (vnmdispResultFlow) {
  case 0:
    if (vnmdispMode == 3) {
      vnmdispResultFlow = 1;
      vnmdispLevelGoals.state = 1;
      vnmdispLevelGoals.cnt = 0;
      vnmdispResultFade.state = 3;
      vnmdispResultFade.cnt = 0;
      nmvcPlay(0x1A, 5, 2);
      vnmdispSoft.state = 1;
      vnmdispSoft.cnt = 0;
      nmdispInitOperate();
      vnmdispOpeAccept = 0;
      tmp = nmdispSearchRank(0);
      if (tmp >= 0) {
        vnmdispScoreRank = tmp;
        for (i = 0; i < (5 - tmp); i++) {
          memcpy((VspenvRecord *)vnmdispRecord[vnmdispCrsEnv->no][5 - i],
                 (VspenvRecord *)vnmdispRecord[vnmdispCrsEnv->no][4 - i], 0x20);
        }
        vnmdispRecord[vnmdispCrsEnv->no][tmp]->chr_no = vnmdispCharEnv->no;
        vnmdispRecord[vnmdispCrsEnv->no][tmp]->score = vnmdispTotalScore[0];
        ulstdSprintf(vnmdispRecord[vnmdispCrsEnv->no][tmp]->name, "%s",
                     vnmdispOption->name);
      } else {
        vnmdispScoreRank = 0xFF;
      }
      if ((vspDispResult[0].comp_time != 0) &&
          vspDispResult[0].comp_time <
              vnmdispBestTime[vnmdispCrsEnv->no]->time) {
        vnmdispBestTime[vnmdispCrsEnv->no]->time = vspDispResult[0].comp_time;
        vnmdispTimeRenew = 1;
      }
      if (vspDispResult[0].comb_num > 0) {
        vspDispResult->comb_info.omit_id = 0;
        nmtrickSetInfo(0, &vspDispResult[0].comb_info);
        info.width = 480.0f;
        info.font = 18.0f;
        info.line = 6;
        vnmdispCombLine = nmtrickMakeList(0, &info, &vnmdispCombList);
        return;
      }
      vspDispResult[0].comb_points = 0;
      return;
    }
    break;
  case 1:
    nmdispFlowLevelGoals();
    nmdispOpeResultCareer();
    return;
  case 2:
    nmdispFlowStatistics();
    nmdispOpeResultCareer();
    return;
  case 3:
    nmdispOpeResultCareer();
    return;
  default:
    vnmdispMode = 6;
    break;
  }
}

static void nmdispFlowResultFreeride() {
  // Size: 0x10, DWARF: 0x1391C8
  DispInfo info; // 0x10(r29)

  switch (vnmdispResultFlow) {
  case 0:
    if (vnmdispMode == 3) {
      vnmdispResultFlow = 2;
      vnmdispStatistics.state = 1;
      vnmdispStatistics.cnt = 0;
      vnmdispResultFade.state = 3;
      vnmdispResultFade.cnt = 0;
      nmvcPlay(0x1A, 5, 2);
      nmdispInitOperate();
      vnmdispOpeAccept = 0;
      if (vspDispResult[0].comb_num > 0) {
        vspDispResult[0].comb_info.omit_id = 0;
        nmtrickSetInfo(0, &vspDispResult->comb_info);
        info.width = 480.0f;
        info.font = 18.0f;
        info.line = 6;
        vnmdispCombLine = nmtrickMakeList(0, &info, &vnmdispCombList);
        return;
      }
      vspDispResult[0].comb_points = 0;
      return;
    }
    break;
  case 2:
    nmdispFlowStatistics();
    nmdispOpeResultFreeride();
    return;
  default:
    vnmdispMode = 6;
    break;
  }
}

static void nmdispFlowResultMatch(void) {
  switch (vnmdispResultFlow) { /* irregular */
  case 0:
    if (vnmdispMode == 3) {
      vnmdispResultFlow = 2;
      vnmdispStatistics.state = 1;
      vnmdispStatistics.cnt = 0;
      vnmdispResultFade.state = 3;
      vnmdispResultFade.cnt = 0;
      nmvcPlay(0x1A, 5, 2);
      nmdispInitOperate();
      vnmdispOpeAccept = 0;
      return;
    }
    break;
  case 2:
    nmdispOpeResultMatch();
    return;
  default:
    vnmdispMode = 6;
    break;
  }
}

static void nmdispFlowLevelGoals(void) {
  unsigned int level_goal; // r16 // s0
  signed int *game_soft;   // r17 // s1

  if (vnmdispCharEnv->no < 0xC) {
    game_soft = vnmdispSecret->character[vnmdispCharEnv->no].soft;
  } else {
    game_soft = vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                    .character.soft;
  }
  switch (vnmdispLevelFlow) {
  case 0:
    if (vnmdispLevelGoals.state == 2) {
      vnmdispLevelFlow = 1;
      return;
    }
    break;
  case 1:
    while (1) {
      if (vnmdispLevelSearch > 9) {
        vnmdispLevelFlow = 5;
        vnmdispOpe.state = 1;
        vnmdispOpe.cnt = 0;
        vnmdispOpeConnect = 1;
        return;
      }
      level_goal = tmevGetLevelGoal(vnmdispCharEnv->player);
      if (level_goal & (1 << (vnmdispLevelSearch))) {
        vnmdispLevelFlow = 2;
        vnmdispLevelMark[vnmdispLevelSearch].state = 1;
        vnmdispLevelMark[vnmdispLevelSearch].cnt = 0;
        nmvcPlay(0x1C, 5, 5);
        return;
      }
      vnmdispLevelSearch++;
    }
    break;
  case 2:
    if (vnmdispLevelMark[vnmdispLevelSearch].state == 3) {
      vnmdispLevelFlow = 3;
      vnmdispSoftCount.state = 1;
      vnmdispSoftCount.cnt = 0;
      vnmdispSoftAdd = vnmtblGetSoft[vnmdispLevelSearch];
      vnmdispSoftNum = game_soft[vnmdispCrsEnv->no];
      return;
    }
    break;
  case 3:
    nmdispFlowSoftCount();
    break;
  case 4:
    break;
  case 5:
    break;
  }
}

static void nmdispFlowStatistics() {
  signed int j;          // r16
  signed int i;          // r17
  signed int total_gaps; // r18
  signed int all_gaps;   // r19
  unsigned int *movie;   // r20
  signed int tmp;        // r21

  switch (vnmdispStatisFlow) {
  case 0:
    if (vnmdispStatistics.state != 2) {
      break;
    }
    vnmdispStatisFlow = 1;
    break;
  case 1:
    all_gaps = 0;
    total_gaps = 0;
    for (i = 0; i < 8; i++) {
      all_gaps += vsptblCourseParam[i][4];
      for (j = 0; j < vsptblCourseParam[i][4]; j++) {
        if ((vnmdispSecret->course[i].gap & ((u64)1 << (u64)j))) {
          total_gaps += 1;
        }
      }
    }
    tmp = (total_gaps * 100) / all_gaps;
    if (total_gaps == all_gaps) {
      movie = &vnmdispOption->movie;
      if (!(movie[0] & 0x4000)) {
        vnmdispCareerItem.type = 4;
        vnmdispCareerItem.num = 2;
        vnmdispCareerItem.value[0] = 0xE;
        vnmdispCareerItem.value[1] = 0xFF;
        movie[0] |= 0x4000;
        vnmdispStatisFlow = 2;
        vnmdispLevelCareer.state = 1;
        vnmdispLevelCareer.cnt = 0;
        return;
      }
      vnmdispStatisFlow = 3;
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 1;
      return;
    }
    vnmdispStatisFlow = 3;
    vnmdispOpe.state = 1;
    vnmdispOpe.cnt = 0;
    vnmdispOpeConnect = 1;
  case 2:
    break;
  case 3:
    switch (vnmdispOpe.state) {
    case 1:
      break;
    case 2:
      vnmdispStatisFlow = 4;
      vnmdispOpeAccept = 1;
      return;
    default:
      vnmdispOpeAccept = 0;
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 1;
      break;
    }
  case 4:
    return;
  }
}

static void nmdispOpeIntr() {
  if ((vnmdispIntrCancel == 0) && (vgmsysPad[0]->trg & 0x40)) {
    vnmdispIntrCancel = 1;
    switch (vnmdispIntr.state) {
    case 1:
      vnmdispIntr.cnt = 0x3C - vnmdispIntr.cnt;
      break;
    default:
      vnmdispIntr.cnt = 0;
      break;
    }
    vnmdispIntr.state = 3;
    nmvcPlayButton(0);
  }
}

static void nmdispOpeIntrMatch() {
  if ((vnmdispIntrCancel == 0) &&
      ((vgmsysPad[0]->trg & 0x40) || (vgmsysPad[1]->trg & 0x40))) {
    vnmdispIntrCancel = 1;
    switch (vnmdispIntr.state) {
    case 1:
      vnmdispIntr.cnt = 0x3C - vnmdispIntr.cnt;
      break;
    default:
      vnmdispIntr.cnt = 0;
      break;
    }
    vnmdispIntr.state = 3;
    nmvcPlayButton(0);
  }
}

static signed int nmdispOpeSoundLevels() {
  Volume *volume; // r17
  signed int tmp; // r16

  volume = &vnmdispOption->volume;
  if ((vgmsysPad[vgmsysPadPausePid]->trg & 0x10) ||
      ((vgmsysPad[vgmsysPadPausePid]->trg & 0x40) &&
       vnmdispPauseSoundItem == 4)) {
    vnmdispPauseFlow = 1;
    vnmdispMenuItem.state = 0;
    vnmdispMenuItem.cnt = 0;
    vnmdispPauseSound.state = 3;
    vnmdispPauseSound.cnt = 0;
    vnmdispSelectFlow = 0;
    vnmdispSelectCnt = 0;
    vnmdispPauseSelect.state = 6;
    vnmdispPauseSelect.cnt = 0;
    if (vnmdispOption->tutorial == 1) {
      if (vnmdispPauseTutorial.state == 3) {
        vnmdispPauseTutorial.cnt = (0x14 - vnmdispPauseTutorial.cnt);
      } else {
        vnmdispPauseTutorial.cnt = 0;
      }
      vnmdispPauseTutorial.state = 1;
      if ((vnmdispTutoMes.state) == 3) {
        vnmdispTutoMes.cnt = (0x14 - vnmdispTutoMes.cnt);
      } else {
        vnmdispTutoMes.cnt = 0;
      }
      vnmdispTutoMes.state = 1U;
    }
    volume->se = vnmdispVolume.se;
    nmvcSetExterVol(volume->se);
    vnmdispOpe.state = 3;
    vnmdispOpe.cnt = 0;
    vnmdispOpeAccept = 0;
    nmdispEndSound();
    if (vgmsysPad[vgmsysPadPausePid]->trg & 0x10) {
      nmvcPlayButton(2);
    } else {
      nmvcPlayButton(0);
    }
  } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x1000) {
    if ((vnmdispPauseSoundItem) > 0) {
      vnmdispPauseSoundItem -= 1;
    } else {
      vnmdispPauseSoundItem = 4;
    }
    if (((vnmdispPauseSoundItem) == 2) && (vnmdispSelectIntTbl < 2)) {
      vnmdispPauseSoundItem -= 1;
    }
    volume->se = vnmdispVolume.se;
    nmvcSetExterVol(volume->se);
    vnmdispMenuItem.state = 1;
    vnmdispMenuItem.cnt = 0;
    if ((vnmdispPauseSoundItem) == 2) {
      vnmdispAllow.state = 1;
    } else {
      vnmdispAllow.state = 0;
    }
    vnmdispAllow.cnt = 0;
    nmvcPlayCursor(1);
  } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x4000) {
    if ((vnmdispPauseSoundItem) < 4) {
      vnmdispPauseSoundItem += 1;
    } else {
      vnmdispPauseSoundItem = 0;
    }
    if (((vnmdispPauseSoundItem) == 2) && (vnmdispSelectIntTbl < 2)) {
      vnmdispPauseSoundItem += 1;
    }
    volume->se = vnmdispVolume.se;
    nmvcSetExterVol(volume->se);
    vnmdispMenuItem.state = 1;
    vnmdispMenuItem.cnt = 0;
    if ((vnmdispPauseSoundItem) == 2) {
      vnmdispAllow.state = 1;
    } else {
      vnmdispAllow.state = 0;
    }
    vnmdispAllow.cnt = 0;
    nmvcPlayCursor(1);
  } else {
    switch (vnmdispPauseSoundItem) { /* irregular */
    case 0:
      if (vgmsysPad[vgmsysPadPausePid]->cnt & 0x8000) {
        if (vnmdispVolume.se > 0) {
          vnmdispVolume.se--;
        }
      } else if ((vgmsysPad[vgmsysPadPausePid]->cnt & 0x2000) &&
                 (vnmdispVolume.se < 0xFF)) {
        vnmdispVolume.se++;
      }
      if (((vgmsysPad[vgmsysPadPausePid]->rev & 0x8000) ||
           (vgmsysPad[vgmsysPadPausePid]->rev & 0x2000)) &&
          (vnmdispVolume.se != volume->se)) {
        volume->se = vnmdispVolume.se;
        nmvcSetExterVol(volume->se);
        nmvcPlayButton(4);
      }
      break;
    case 1:
      if (vgmsysPad[vgmsysPadPausePid]->cnt & 0x8000) {
        if (vnmdispVolume.bgm > 0) {
          vnmdispVolume.bgm--;
        }
      } else if ((vgmsysPad[vgmsysPadPausePid]->cnt & 0x2000) &&
                 (vnmdispVolume.bgm < 0xFF)) {
        vnmdispVolume.bgm++;
      }
      if (vnmdispVolume.bgm != volume->bgm) {
        volume->bgm = vnmdispVolume.bgm;
        nmbgmSetExterVol(volume->bgm);
      }
      break;
    case 2:
      if (vgmsysPad[vgmsysPadPausePid]->rep & 0x8000) {
        tmp = vnmdispSelectInt;
        do {
          if (tmp > 0) {
            tmp -= 1;
          } else {
            tmp = 0xB;
          }
        } while (vnmdispOption->bgm.disable & (1 << tmp));
        vnmdispSelectInt = tmp;
        vnmdispSelectFlow = 0;
        nmvcPlayCursor(1);
      } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x2000) {
        tmp = vnmdispSelectInt;
        do {
          if (tmp < 0xC) {
            tmp += 1;
          } else {
            tmp = 0;
          }
        } while (vnmdispOption->bgm.disable & (1 << tmp));
        vnmdispSelectInt = tmp;
        vnmdispSelectFlow = 0;
        nmvcPlayCursor(1);
      }
      if ((vgmsysPad[vgmsysPadPausePid]->cnt & 0x8000) ||
          (vgmsysPad[vgmsysPadPausePid]->cnt & 0x2000)) {
        vnmdispSelectCnt = 0;
      }
      if ((vgmsysPad[vgmsysPadPausePid]->rev & 0x8000) ||
          (vgmsysPad[vgmsysPadPausePid]->rev & 0x2000)) {
        vnmdispSelectFlow = 1;
        vnmdispSelectCnt = 0;
      }
      break;
    case 3:
      if (((vgmsysPad[vgmsysPadPausePid]->trg & 0x8000) |
           (vgmsysPad[vgmsysPadPausePid]->trg & 0x2000)) != 0) {
        vnmdispOption->bgm.random ^= 1;
        nmvcPlayCursor(1);
      }
      break;
    }
  }
  return 0;
}

static signed int nmdispOpeTrickList() {
  signed int list_num; // r16
  signed int tmp;      // r17

  if (vnmdispTrickList[vnmdispPauseTrickCate].state == 2) {
    if (vgmsysPad[vgmsysPadPausePid]->trg & 0x10) {
      vnmdispPauseFlow = 1;
      vnmdispPauseTrick.state = 3;
      vnmdispPauseTrick.cnt = 0;
      vnmdispAllow.state = 0;
      vnmdispAllow.cnt = 0;
      vnmdispTrickList[vnmdispPauseTrickCate].state = 3;
      vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
      vnmdispPauseSelect.state = 6;
      vnmdispPauseSelect.cnt = 0;
      if (vnmdispOption->tutorial == 1) {
        if (vnmdispPauseTutorial.state == 3) {
          vnmdispPauseTutorial.cnt = 0x14 - vnmdispPauseTutorial.cnt;
        } else {
          vnmdispPauseTutorial.cnt = 0;
        }
        vnmdispPauseTutorial.state = 1;
        if (vnmdispTutoMes.state == 3) {
          vnmdispTutoMes.cnt = (0x14 - vnmdispTutoMes.cnt);
        } else {
          vnmdispTutoMes.cnt = 0;
        }
        vnmdispTutoMes.state = 1;
      }
      vnmdispOpe.state = 3;
      vnmdispOpe.cnt = 0;
      vnmdispOpeAccept = 0;
      nmvcPlayButton(2);
    } else if (vgmsysPad[vgmsysPadPausePid]->trg & 0x2000) {
      vnmdispTrickList[vnmdispPauseTrickCate].state = 5;
      vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
      vnmdispPauseTrickCate = (vnmdispPauseTrickCate + 1) % 9;
      vnmdispAllow.state = 0;
      vnmdispAllow.cnt = 0;
      vnmdispOpeAccept = 0;
      nmvcPlayCursor(1);
    } else if (vgmsysPad[vgmsysPadPausePid]->trg & 0x8000) {
      vnmdispTrickList[vnmdispPauseTrickCate].state = 3;
      vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
      vnmdispPauseTrickCate--;
      if (vnmdispPauseTrickCate < 0) {
        vnmdispPauseTrickCate += 9;
      }
      vnmdispAllow.state = 0;
      vnmdispAllow.cnt = 0;
      vnmdispOpeAccept = 0;
      nmvcPlayCursor(1);
    } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x1000) {
      list_num = vnmtblTlistNum[vnmdispPauseTrickCate];
      if ((0xA < list_num) &&
          (vnmdispTrickList[vnmdispPauseTrickCate].top) > 0) {
        vnmdispTrickList[vnmdispPauseTrickCate].top--;
        nmvcPlayCursor(1);
      }
    } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x4000) {
      list_num = vnmtblTlistNum[vnmdispPauseTrickCate];
      if (list_num > 0xA) {
        tmp = vnmdispTrickList[vnmdispPauseTrickCate].top + 0xA;
        if ((tmp < list_num)) {
          vnmdispTrickList[vnmdispPauseTrickCate].top++;
          nmvcPlayCursor(1);
        }
      }
    }
  }
  return 0;
}

static signed int nmdispOpeLevelGoalList() {
  if ((vnmdispLevelGoalList.state == 2) &&
      (vgmsysPad[vgmsysPadPausePid]->trg & 0x10)) {
    vnmdispPauseFlow = 1;
    vnmdispLevelGoalList.state = 3;
    vnmdispLevelGoalList.cnt = 0;
    vnmdispAllow.state = 0;
    vnmdispAllow.cnt = 0;
    vnmdispPauseSelect.state = 6;
    vnmdispPauseSelect.cnt = 0;
    if (vnmdispOption->tutorial == 1) {
      if (vnmdispPauseTutorial.state == 3) {
        vnmdispPauseTutorial.cnt = 0x14 - vnmdispPauseTutorial.cnt;
      } else {
        vnmdispPauseTutorial.cnt = 0;
      }
      vnmdispPauseTutorial.state = 1;
      if (vnmdispTutoMes.state == 3) {
        vnmdispTutoMes.cnt = 0x14 - vnmdispTutoMes.cnt;
      } else {
        vnmdispTutoMes.cnt = 0;
      }
      vnmdispTutoMes.state = 1;
    }
    vnmdispOpe.state = 3;
    vnmdispOpe.cnt = 0;
    vnmdispOpeAccept = 0;
    nmvcPlayButton(2);
  }
  return 0;
}

static void nmdispOpeDebug() {}

static void nmdispOpeHorse() {
  if (vnmdispOpeAccept == 1) {
    switch (vnmdispHorseFlow) {
    case 1:
      nmdispOpeEnterWord();
      if ((vgmsysPad[0]->trg & 0x40) || (vgmsysPad[1]->trg & 0x40)) {
        vnmdispHorseFlow = 2;
        vnmdispHorseEnter.state = 3;
        vnmdispHorseEnter.cnt = 0;
        vnmdispOpe.state = 3;
        vnmdispOpe.cnt = 0;
        vnmdispOpeAccept = 0;
        nmvcPlayButton(0);
        return;
      }
      break;
    case 2:
      if (vgmsysPad[vspModeData.horse_pid]->trg & 0x40) {
        vnmdispHorseFlow = 0;
        vnmdispHorseMes.state = 4;
        vnmdispHorseMes.cnt = 0;
        vnmdispOpe.state = 3;
        vnmdispOpe.cnt = 0;
        vnmdispOpeAccept = 0;
        nmvcPlayButton(0);
        return;
      }
      break;
    case 3:
      if ((vgmsysPad[0]->trg & 0x40) || (vgmsysPad[1]->trg & 0x40)) {
        vnmdispHorseFlow = 0;
        vnmdispHorseMes.state = 4;
        vnmdispHorseMes.cnt = 0;
        vnmdispOpe.state = 3;
        vnmdispOpe.cnt = 0;
        vnmdispOpeAccept = 0;
        nmvcPlayButton(0);
      }
      break;
    }
  }
}

static void nmdispOpeEnterWord() {
  char str_tmp; // r16

  if ((vgmsysPad[0]->trg & 0x8000) || (vgmsysPad[1]->trg & 0x8000)) {
    if (vnmdispHorseWordNum > 0) {
      vnmdispHorseWordNum -= 1;
    } else if (vnmdispHorseNum == 0xA) {
      vnmdispHorseWordNum = vnmdispHorseNum - 1;
    } else {
      vnmdispHorseWordNum = vnmdispHorseNum;
    }
    nmvcPlayCursor(1);
  } else if ((vgmsysPad[0]->trg & 0x2000) || (vgmsysPad[1]->trg & 0x2000)) {
    if (vnmdispHorseWordNum < vnmdispHorseNum) {
      vnmdispHorseWordNum = (vnmdispHorseWordNum + 1) % 10;
    } else {
      vnmdispHorseWordNum = 0;
    }
    nmvcPlayCursor(1);
  }
  if ((vgmsysPad[0]->rep & 0x1000) || (vgmsysPad[1]->rep & 0x1000)) {
    str_tmp = vnmdispHorseWord[vnmdispHorseWordNum];
    switch (str_tmp) {
    case 0x20:
      str_tmp = 0x5A & 0xFF;
      vnmdispHorseNum += 1;
      break;
    case 0x41:
      if (3 < vnmdispHorseNum) {
        if (vnmdispHorseWordNum == (vnmdispHorseNum - 1)) {
          str_tmp = 0x20 & 0xFF;
          vnmdispHorseNum -= 1;
        } else if (vnmdispHorseWord[vnmdispHorseWordNum + 1] == 0x20) {
          str_tmp = 0x20 & 0xFF;
          vnmdispHorseNum -= 1;
        } else {
          str_tmp = 0x5A & 0xFF;
        }
      } else {
        str_tmp = 0x5A & 0xFF;
      }
      break;
    default:
      str_tmp--;
      break;
    }
    vnmdispHorseWord[vnmdispHorseWordNum] = str_tmp;
    nmvcPlayCursor(1);
    return;
  }
  if ((vgmsysPad[0]->rep & 0x4000) || (vgmsysPad[1]->rep & 0x4000)) {
    str_tmp = vnmdispHorseWord[vnmdispHorseWordNum];
    switch (str_tmp) {
    case 0x20:
      str_tmp = 0x41 & 0xFF;
      vnmdispHorseNum += 1;
      break;
    case 0x5A:
      if (3 < vnmdispHorseNum) {
        if (vnmdispHorseWordNum == (vnmdispHorseNum - 1)) {
          str_tmp = 0x20 & 0xFF;
          vnmdispHorseNum -= 1;
        } else if (vnmdispHorseWord[vnmdispHorseWordNum + 1] == 0x20) {
          str_tmp = 0x20 & 0xFF;
          vnmdispHorseNum -= 1;
        } else {
          str_tmp = 0x41 & 0xFF;
        }
      } else {
        str_tmp = 0x41 & 0xFF;
      }
      break;
    default:
      str_tmp++;
      break;
    }
    vnmdispHorseWord[vnmdispHorseWordNum] = str_tmp;
    nmvcPlayCursor(1);
  }
}

static void nmdispOpeResultCareer() {
  unsigned int *level_goal; // r16

  if (vnmdispOpeAccept == 1) {
    switch (vnmdispResultFlow) {
    case 1:
      switch (vnmdispLevelGoals.state) {
      case 2:
        switch (vnmdispLevelFlow) {
        case 4:
          switch (vnmdispLevelCareer.state) {
          case 2:
            if (vgmsysPad[0]->trg & 0x40) {
              vnmdispLevelCareer.state = 3;
              vnmdispLevelCareer.cnt = 0;
              vnmdispOpe.state = 3;
              vnmdispOpe.cnt = 0;
              vnmdispOpeAccept = 0;
              nmvcPlayButton(0);
              return;
            }
            break;
          }
          break;
        case 5:
          if (vgmsysPad[0]->trg & 0x40) {
            vnmdispLevelGoals.state = 3;
            vnmdispLevelGoals.cnt = 0;
            nmvcPlay(0x1B, 5, 3);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            nmvcPlayButton(0);
            return;
          }
          break;
        }
        break;
      }
      break;

    case 2:
      switch (vnmdispStatistics.state) {
      case 2:
        switch (vnmdispStatisFlow) {
        case 2:
          switch (vnmdispLevelCareer.state) {
          case 2:
            if (vgmsysPad[0]->trg & 0x40) {
              vnmdispLevelCareer.state = 3;
              vnmdispLevelCareer.cnt = 0;
              vnmdispOpe.state = 3;
              vnmdispOpe.cnt = 0;
              vnmdispOpeAccept = 0;
              nmvcPlayButton(0);
              return;
            }
            break;
          }
          break;
        case 4:
          if (vgmsysPad[0]->trg & 0x40) {
            vnmdispStatistics.state = 3;
            vnmdispStatistics.cnt = 0;
            nmvcPlay(0x1B, 5, 3);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            nmvcPlayButton(0);
            return;
          }
          break;
        }
        break;
      }
      break;
    case 3:
      if (vgmsysPad[0]->trg & 0x40) {
        vnmdispHighScore.state = 3;
        vnmdispHighScore.cnt = 0;
        vnmdispResultFade.state = 1;
        vnmdispResultFade.cnt = 0;
        nmsndRestart(0xA);
        nmvcPlay(0x1B, 5, 3);
        vnmdispOpe.state = 3;
        vnmdispOpe.cnt = 0;
        vnmdispOpeAccept = 0;
        nmvcPlayButton(0);
        if (vnmdispCharEnv->no < 0xC) {
          level_goal = &vnmdispSecret->character[vnmdispCharEnv->no]
                            .level_goal[vnmdispCrsEnv->no];
        } else {
          level_goal =
              &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                   .character.level_goal[vnmdispCrsEnv->no];
        }
        *level_goal |= tmevGetLevelGoal(vnmdispCharEnv->player);
      }
      nmdispOpeNameEntry();
      break;
    }
  }
}

static void nmdispOpeResultFreeride() {
  if (vnmdispOpeAccept == 1) {
    switch (vnmdispResultFlow) {
    case 2:
      switch (vnmdispStatistics.state) {
      case 2:
        switch (vnmdispStatisFlow) {
        case 2:
          switch (vnmdispLevelCareer.state) {
          case 2:
            if (vgmsysPad[0]->trg & 0x40) {
              vnmdispLevelCareer.state = 3;
              vnmdispLevelCareer.cnt = 0;
              vnmdispOpe.state = 3;
              vnmdispOpe.cnt = 0;
              vnmdispOpeAccept = 0;
              nmvcPlayButton(0);
              return;
            }
            break;
          }
          break;
        case 4:
          if (vgmsysPad[0]->trg & 0x40) {
            vnmdispStatistics.state = 3;
            vnmdispStatistics.cnt = 0;
            vnmdispResultFade.state = 1;
            vnmdispResultFade.cnt = 0;
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            nmsndRestart(0xA);
            nmvcPlayButton(0);
          }
          break;
        }
      }
    }
  }
}

static void nmdispOpeResultMatch() {
  if (vnmdispOpeAccept == 1) {
    switch (vnmdispResultFlow) {
    case 2:
      switch (vnmdispStatistics.state) {
      case 2:
        if ((vgmsysPad[0]->trg & 0x40) || (vgmsysPad[1]->trg & 0x40)) {
          vnmdispStatistics.state = 3;
          vnmdispStatistics.cnt = 0;
          vnmdispResultFade.state = 1;
          vnmdispResultFade.cnt = 0;
          vnmdispOpe.state = 3;
          vnmdispOpe.cnt = 0;
          vnmdispOpeAccept = 0;
          nmsndRestart(0xA);
          nmvcPlayButton(0);
        }
      }
    }
  }
}

static void nmdispOpeNameEntry() {
  char str_tmp; // r16

  if (vnmdispScoreRank < 0xFF) {
    if (vgmsysPad[0]->trg & 0x8000) {
      if ((vnmdispEntryNum) > 0) {
        vnmdispEntryNum -= 1;
      } else {
        vnmdispEntryNum = 2;
      }
      nmvcPlayCursor(1);
    } else if (vgmsysPad[0]->trg & 0x2000) {
      if ((vnmdispEntryNum) < 2) {
        vnmdispEntryNum += 1;
      } else {
        vnmdispEntryNum = 0;
      }
      nmvcPlayCursor(1);
    }
    if (vgmsysPad[0]->rep & 0x1000) {
      str_tmp = vnmdispRecord[vnmdispCrsEnv->no][vnmdispScoreRank]
                    ->name[vnmdispEntryNum];
      switch (str_tmp) {
      case 0x41:
        str_tmp = 0x39;
        break;
      case 0x61:
        str_tmp = 0x5A;
        break;
      case 0x30:
        str_tmp = 0x7A;
        break;
      default:
        str_tmp--;
        break;
      }
      vnmdispRecord[vnmdispCrsEnv->no][vnmdispScoreRank]
          ->name[vnmdispEntryNum] = str_tmp;
      nmvcPlayCursor(1);
      return;
    }
    if (vgmsysPad[0]->rep & 0x4000) {
      str_tmp = vnmdispRecord[vnmdispCrsEnv->no][vnmdispScoreRank]
                    ->name[vnmdispEntryNum];
      switch (str_tmp) {
      case 0x5A:
        str_tmp = 0x61;
        break;
      case 0x7A:
        str_tmp = 0x30;
        break;
      case 0x39:
        str_tmp = 0x41;
        break;
      default:
        str_tmp++;
        break;
      }
      vnmdispRecord[vnmdispCrsEnv->no][vnmdispScoreRank]
          ->name[vnmdispEntryNum] = str_tmp;
      nmvcPlayCursor(1);
    }
  }
}

static void nmdispOpeReplay() {
  if ((vnmdispOpeAccept == 1) && (vgmsysPad[0]->trg & 0x10)) {
    vnmdispReplay.state = 3;
    vnmdispReplay.cnt = 0;
    vnmdispOpe.state = 3;
    vnmdispOpe.cnt = 0;
    vnmdispOpeAccept = 0;
    nmvcPlayButton(2);
    nmsndRestart(0xF);
  }
}

static void nmdispOpeReplayMatch(void) {
  if ((vnmdispOpeAccept == 1) &&
      ((vgmsysPad[0]->trg & 0x10) || (vgmsysPad[1]->trg & 0x10))) {
    vnmdispReplay.state = 3;
    vnmdispReplay.cnt = 0;
    vnmdispOpe.state = 3;
    vnmdispOpe.cnt = 0;
    vnmdispOpeAccept = 0;
    nmvcPlayButton(2);
    nmsndRestart(0xF);
  }
}

static void nmdispOpeDemo(void) {
  if (vnmdispOpeAccept == 1 &&
      (vgmsysPad[0]->state == 2 || vgmsysPad[0]->state == 6) &&
      vgmsysPad[0]->cnt != 0xFFFF0000) {
    vnmdispReplay.state = 3;
    vnmdispReplay.cnt = 0;
    vnmdispOpe.state = 3;
    vnmdispOpe.cnt = 0;
    vnmdispOpeAccept = 0;
    nmsndRestart(0xF);
  }
}

void nmdispInputParam() {
  vnmdispParam.state = 1;
  vnmdispParam.cnt = 0;
  vnmdispParamPosLeft = -320.0f;
  vnmdispParamPosRight = 960.0f;
  vnmdispParamPosUp = -112.0f;
  vnmdispParamPosDown = 224.0f;
}

void nmdispInputTrick(signed int id) {
  nmdispInitTrick(id);
  nmdispInitTrickPts(id);
  vnmdispTrickStart[id] = 1;
  vnmdispTrickSuccess[id] = 0;
  if (vnmdispModeEnv->game_mode != 2) {
    vnmdispTrickPtsDraw[id].total = (signed int)vspDispEnvChar[id].points.total;
    return;
  }
  vnmdispTrickPtsDraw[id].total = (signed int)vnmdispTrickPtsDraw[id].freeride;
}

void nmdispInputLevel(signed int num) {
  signed int i; // r16

  if (vnmdispModeEnv->game_mode == 0 && vspModeData.flow_mode != efmReplay &&
      vspModeData.flow_mode != efmRepReady &&
      vspModeData.flow_mode != efmRepEnd && tmevGetLevelGoalFlag(num) == 0) {
    for (i = 0; i < 8; i++) {
      if (vnmdispLevelMes[i].state == 0) {
        break;
      }
    }
    vnmdispLevelMes[i].state = 1;
    vnmdispLevelMes[i].cnt = 0;
    vnmdispLevelMesInfo[i].type = 0;
    vnmdispLevelMesInfo[i].num = num;
    vnmdispLevelMesInfo[i].value[0] = 0xFF;
    vnmdispLevelMesInfo[i].value[1] = 0xFF;
    nmvcPlay(0x1A, 5, 1);
  }
}

void nmdispInputLevelCount(signed int now, signed int total, signed int num) {
  signed int i; // r16

  if (vnmdispModeEnv->game_mode == 0 && vspModeData.flow_mode != efmReplay &&
      vspModeData.flow_mode != efmRepReady &&
      vspModeData.flow_mode != efmRepEnd && tmevGetLevelGoalFlag(num) == 0) {
    for (i = 0; i < 8; i++) {
      if (vnmdispLevelMes[i].state == 0) {
        break;
      }
    }
    vnmdispLevelMes[i].state = 1;
    vnmdispLevelMes[i].cnt = 0;
    vnmdispLevelMesInfo[i].type = 1;
    vnmdispLevelMesInfo[i].num = num;
    vnmdispLevelMesInfo[i].value[0] = now;
    vnmdispLevelMesInfo[i].value[1] = total;
    nmvcPlay(0x1A, 5, 0);
  }
}

void nmdispInputOutMes(signed int id) {
  if (vspModeData.flow_mode != 6 && vspModeData.flow_mode != 5 &&
      vspModeData.flow_mode != 7) {
    vnmdispOutMes[id].state = 1;
    vnmdispOutMes[id].cnt = 0;
  }
}

void nmdispInputResult() {
  switch (vnmdispModeEnv->match_rule) {
  case 0:
  case 1:
    if (vspDispEnvChar[0].rank == vspDispEnvChar[1].rank) {
      vnmdispDraw.state = 1;
      vnmdispDraw.cnt = 0;
      return;
    }
    vnmdispWin.state = 1;
    vnmdispWin.cnt = 0;
    vnmdispLose.state = 1;
    vnmdispLose.cnt = 0;
    if (vspDispEnvChar[0].rank == 0) {
      vnmdispWinPos[0] = 640.0f;
      if (vnmdispDivSide == 0) {
        vnmdispWinPos[1] = 149.33333f;
        vnmdispLosePos[0] = 320.0f;
        vnmdispLosePos[1] = 149.33333f;
        return;
      }
      vnmdispWinPos[1] = 74.666664f;
      vnmdispLosePos[0] = 160.0f;
      vnmdispLosePos[1] = 298.66666f;
      return;
    }
    if (vnmdispDivSide == 0) {
      vnmdispWinPos[0] = -320.0f;
      vnmdispWinPos[1] = 149.33333f;
      vnmdispLosePos[0] = 0.0f;
      vnmdispLosePos[1] = 149.33333f;
      return;
    }
    vnmdispWinPos[0] = -640.0f;
    vnmdispWinPos[1] = 298.66666f;
    vnmdispLosePos[0] = 160.0f;
    vnmdispLosePos[1] = 74.666664f;
    return;
  case 2:
    if (vspDispEnvChar[0].rank == vspDispEnvChar[1].rank) {
      vnmdispDraw.state = 1;
      vnmdispDraw.cnt = 0;
      return;
    }
    vnmdispWin.state = 1;
    vnmdispWin.cnt = 0;
    if (vspDispEnvChar[0].rank == 0) {
      vnmdispWinPos[0] = 640.0f;
    } else {
      vnmdispWinPos[0] = -640.0f;
    }
    vnmdispWinPos[1] = 149.33333f;
    return;
  }
}

void nmdispEndTrick(signed int id, signed int result) {
  // // Size: 0x10, DWARF: 0x1391C8
  DispInfo info; // 0x10(r29)

  if (vnmdispTrickStart[id] == 1) {
    vnmdispTrickStart[id] = 0;
    vnmdispTrickEnd[id] = 1;
    vnmdispTrickSuccess[id] = result;
    if (vnmdispTotalScore[id] < vspDispEnvChar[id].points.total) {
      vnmdispTotalScore[id] = vspDispEnvChar[id].points.total;
    }
    switch (result) {
    case 1:
      if (vnmdispTrickPtsDraw[id].single != vspDispEnvChar[id].points.single) {
        vnmdispTrickPtsDraw[id].single = vspDispEnvChar[id].points.single;
        vnmdispTrickPtsDraw[id].link_rate = 0x64;
        vnmdispTrickPts[id].state = 1;
        vnmdispTrickPts[id].cnt = 0;
      } else {
        vnmdispTrickPts[id].state = 2;
        vnmdispTrickPts[id].cnt = 0;
      }
      if (vnmdispModeEnv->game_mode == 2) {
        vnmdispTrickPtsDraw[id].freeride = vspDispEnvChar[id].points.single;
        vnmdispTrickPtsDraw[id].total = 0;
        return;
      }
      break;
    case 0:
      vnmdispTrickPtsDraw[id].single = vspDispEnvChar[id].points.single;
      vnmdispTrickPtsDraw[id].link_rate = 0x64;
      if (vnmdispDivMode == 0) {
        info.font = 16.0f;
        info.line = 3;
      } else {
        if (vnmdispDivSide == 0) {
          info.line = 3;
        } else {
          info.line = 2;
        }
        info.font = 16.0f;
      }
      nmtrickMakeStr(id, &info, &vnmdispTrickNameList[id][0]);
      break;
    }
  }
}

void nmdispEndReplay() {
  if (vnmdispReplay.state != 3) {
    vnmdispReplay.state = 3;
    vnmdispReplay.cnt = 0;
    vnmdispOpe.state = 3;
    vnmdispOpe.cnt = 0;
    vnmdispOpeAccept = 0;
    nmsndRestart(0xF);
  }
}

void nmdispEndHorse() {
  signed int i; // r16

  vnmdispHorseFlow = 0;
  vnmdispHorseAccept = 0;
  vnmdispHorseSet = 0;
  for (i = 0; i < 2; i++) {
    vnmdispHorsePts[i] = 0;
  }
  vnmdispHorseEnter.state = 0;
  vnmdispHorseEnter.cnt = 0;
  vnmdispHorseEnterPos[0] = -640.0f;
  vnmdispHorseEnterPos[1] = -640.0f;
  vnmdispHorseMes.state = 0;
  vnmdispHorseMes.cnt = 0;
  for (i = 0; i < 4; i++) {
    vnmdispHorseMesPos[i] = -640.0f;
  }
  vnmdispHorseMesType = 0;
}

static void nmdispEndSound() {

  // Size: 0x8, DWARF: 0x1338A8
  Volume *volume; // r17
  signed int tmp; // r16
  volume = &vnmdispOption->volume;
  nmbgmSetOptNext(1);
  nmbgmSetOptRand(vnmdispOption->bgm.random);
  nmbgmChangeOption();
  tmp = nmbgmPause();
  if (tmp == -1) {
    scePrintf("nmbgmPause Error\n");
  }
}

signed int nmdispGetMode() { return vnmdispMode; }

signed int nmdispCheckIntr() {
  if (vnmdispIntr.state == 0) {
    return 1;
  }
  return 0;
}

signed int nmdispCheckHorse() { return vnmdispHorseAccept; }

signed int nmdispGetHorseNum() { return vnmdispHorseNum; }

signed int nmdispSearchRank(signed int id) {
  signed int rank; // r18
  signed int tmp;  // r17
  signed int i;    // r16

  for (i = 0; i < 6; i++) {
    tmp = i;
    if (vnmdispTotalScore[id] <=
        vnmdispRecord[vnmdispCrsEnv->no][5 - i]->score) {
      tmp -= 1;
      break;
    }
  }
  if (tmp >= 0) {
    rank = 5 - tmp;
  } else {
    rank = tmp;
  }
  return rank;
}

void nmdispTransTex(VgmsysGifPkt *packet) {
  ultexSetTexPath3(packet, vnmdispTexData->frame, vnmdispTexData->offset,
                   vnmdispTexData->block);
}

void nmdispRenewTrick(signed int id) {
  // Size: 0x10, DWARF: 0x1391C8
  DispInfo info; // 0x10(r29)

  vnmdispTrickName[id].state = 1;
  vnmdispTrickName[id].cnt = 0;
  if (vnmdispDivMode == 0) {
    info.width = 512.0f;
    info.font = 16.0f;
    info.line = 3;
  } else {
    if (vnmdispDivSide == 0) {
      info.width = 240.0f;
      info.line = 3;
    } else {
      info.width = 512.0f;
      info.line = 2;
    }
    info.font = 16.0f;
  }
  vnmdispTrickNameLine[id] =
      nmtrickMakeList(id, &info, vnmdispTrickNameList[id]);
  if (vnmdispTrickPtsDraw[id].single != vspDispEnvChar[id].points.single ||
      vnmdispTrickPtsDraw[id].link_rate < vspDispEnvChar[id].points.link_rate) {
    vnmdispTrickPts[id].state = 1;
    vnmdispTrickPts[id].cnt = 0;
    vnmdispTrickPtsDraw[id].single = vspDispEnvChar[id].points.single;
    vnmdispTrickPtsDraw[id].link_rate = vspDispEnvChar[id].points.link_rate;
  }
}

void nmdispSetTrickFall(signed int id, char *str, signed int line) {
  signed int i; // r16

  vnmdispTrickNameInfo[id][line].state = 2;
  vnmdispTrickNameInfo[id][line].num = strlen(str);
  for (i = 0; i < (vnmdispTrickNameInfo[id][line].num); i++) {
    vnmdispTrickNameInfo[id][line].word[i].state = 2;
    vnmdispTrickNameInfo[id][line].word[i].cnt = 0;
    vnmdispTrickNameInfo[id][line].word[i].str = *(str + i);
  }
}

static void nmdispChanState(VgmsysGifPkt *packet) {
  signed int j;           // r16
  signed int tmp;         // r17
  signed int i;           // r18
  char str_tmp[128];      // 0xD0(r29)
  float pos_tmp[4];       // 0x150(r29)
  signed int chan[2][24]; // 0x160(r29)
  signed int state[2];    // 0x228(r29)

  nmfontInitOption();
  nmfontSetShadow(1);
  nmfontSetBil(1);
  nmfontSetScrRate(1);
  for (i = 0; i < 2; i++) {
    state[i] = nmsndGetChanState(i);
    for (j = 0; j < 0x18; j++) {
      tmp = (1 << j);
      tmp &= state[i];
      chan[i][j] = ((tmp) >> j);
    }
  }
  pos_tmp[0] = 16.0f;
  pos_tmp[1] = 368.0f;
  ulstdSprintf(&str_tmp,
               "CORE0:%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
               chan[0][0], chan[0][1], chan[0][2], chan[0][3], chan[0][4],
               chan[0][5], chan[0][6], chan[0][7], chan[0][8], chan[0][9],
               chan[0][10], chan[0][11], chan[0][12], chan[0][13], chan[0][14],
               chan[0][15], chan[0][16], chan[0][17], chan[0][18], chan[0][19],
               chan[0][20], chan[0][21], chan[0][22], chan[0][23]);
  nmfontFPrintF(packet, &str_tmp, &pos_tmp[0]);
  ulstdSprintf(&str_tmp,
               "CORE1:%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
               chan[1][0], chan[1][1], chan[1][2], chan[1][3], chan[1][4],
               chan[1][5], chan[1][6], chan[1][7], chan[1][8], chan[1][9],
               chan[1][10], chan[1][11], chan[1][12], chan[1][13], chan[1][14],
               chan[1][15], chan[1][16], chan[1][17], chan[1][18], chan[1][19],
               chan[1][20], chan[1][21], chan[1][22], chan[1][23]);
  pos_tmp[1] += 16.0f;
  nmfontFPrintF(packet, &str_tmp, &pos_tmp[0]);
}

static void nmdispIntrLevel(VgmsysGifPkt *packet) {
  float tmp;                 // 0x1A8(r29)
  char str_tmp[128];         // 0x60(r29)
  float font_pos[4];         // 0xE0(r29)
  float font_size;           // 0x1AC(r29)
  signed int font_col[1][4]; // 0xF0(r29)
  signed int mes_tbl[9] = {  // 0x100(r29)
                           6, 0, 7, 1, 8, 2, 4, 3, 5};
  s32 *mes_tbl_ptr = &mes_tbl;
  unsigned int *level_goal; // r19
  signed int min;           // r17
  signed int sec;           // r18
  signed int cut_num;       // r16
  // Size: 0x70, DWARF: 0x137FF4
  Point point; // 0x130(r29)

  nmdispInitFont();
  cut_num = tmevGetIntroCut();
  if (cut_num < 9) {
    if (vnmdispCharEnv->no < 0xC) {
      level_goal = &vnmdispSecret->character[vnmdispCharEnv->no]
                        .level_goal[vnmdispCrsEnv->no];
    } else {
      level_goal = &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                        .character.level_goal[vnmdispCrsEnv->no];
    }
    if ((*level_goal & (1 << mes_tbl[cut_num])) == 0) {
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x60;
      font_col[0][2] = 0x40;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      switch (cut_num) {
      case 1:
      case 3:
      case 5:
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no][mes_tbl[cut_num]];
        point.type = 0;
        point.size[0] = 0x18;
        point.size[1] = 0x18;
        point.language = *vnmdispLang;
        tmp = nmdrawGetPointLen(&point);
        ulstdSprintf(str_tmp, "%s  %s",
                     vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]],
                     vnmtblCommon[*vnmdispLang][0]);
        tmp += nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          point.size[0] = font_size;
          tmp = nmdrawGetPointLen(&point);
          ulstdSprintf(str_tmp, "%s  %s",
                       vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]],
                       vnmtblCommon[*vnmdispLang][0]);
          tmp += nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 24.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = (640.0f - tmp) / 2.0f;
        font_pos[1] = 149.333328f;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s ",
                     vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]]);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        nmfontFPrintF(packet, str_tmp, font_pos);
        font_pos[0] += tmp;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no][mes_tbl[cut_num]];
        point.type = 0;
        point.size[0] = font_size;
        point.size[1] = 0x18;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        tmp = nmdrawGetPointLen(&point);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 7:
        min = vsptblLevelGoalValue[vnmdispCrsEnv->no][mes_tbl[cut_num]] / 60;
        sec = vsptblLevelGoalValue[vnmdispCrsEnv->no][mes_tbl[cut_num]] % 60;
        ulstdSprintf(str_tmp, "%d%02d", min, sec);
        tmp = nmfontGetStrFLen(str_tmp, 24.0f);
        point.point =
            vsptblLevelGoalValue[vnmdispCrsEnv->no][mes_tbl[cut_num] + 1];
        point.type = 0;
        point.size[0] = 0x18;
        point.size[1] = 0x18;
        point.language = *vnmdispLang;
        tmp += nmdrawGetPointLen(&point);
        ulstdSprintf(str_tmp, "%s %s %s  %s",
                     vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]],
                     vnmtblCommon[*vnmdispLang][2],
                     vnmtblLevelCompMes[*vnmdispLang][6],
                     vnmtblCommon[*vnmdispLang][1]);
        tmp += nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          ulstdSprintf(str_tmp, "%d%02d", min, sec);
          tmp = nmfontGetStrFLen(str_tmp, font_size);
          point.size[0] = font_size;
          tmp += nmdrawGetPointLen(&point);
          ulstdSprintf(str_tmp, "%s %s %s  %s",
                       vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]],
                       vnmtblCommon[*vnmdispLang][2],
                       vnmtblLevelCompMes[*vnmdispLang][6],
                       vnmtblCommon[*vnmdispLang][1]);
          tmp += nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 24.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = (640.0f - tmp) / 2.0f;
        font_pos[1] = 149.333328f;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s ",
                     vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        font_pos[0] += tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%d", min);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetStrFLen(str_tmp, font_size);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblCommon[*vnmdispLang][2]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        font_pos[0] += tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%02d", sec);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetStrFLen(str_tmp, font_size);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s ", vnmtblLevelCompMes[*vnmdispLang][6]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        font_pos[0] += tmp;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point =
            vsptblLevelGoalValue[vnmdispCrsEnv->no][mes_tbl[cut_num] + 1];
        point.type = 0;
        point.size[0] = font_size;
        point.size[1] = 0x18;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        tmp = nmdrawGetPointLen(&point);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][1]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 6:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp,
                     vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]],
                     vsptblCourseName[vnmdispCrsEnv->no + 0x10]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 24.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = (640.0f - tmp) / 2.0f;
        font_pos[1] = 149.333328f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 8:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s",
                     vnmtblLevelCompMes[*vnmdispLang][mes_tbl[cut_num]]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 24.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = (640.0f - tmp) / 2.0f;
        font_pos[1] = 149.333328f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 0:
      case 2:
      case 4:
        nmfontSetPack(1);
        ulstdSprintf(
            str_tmp, "%s",
            vsptblLevelGoalStr[vnmdispCrsEnv->no][mes_tbl[cut_num] - 6]);
        tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 24.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = (640.0f - tmp) / 2.0f;
        font_pos[1] = 149.333328f;
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      }
    }
  }
}

static void nmdispTimeLeft(VgmsysGifPkt *packet) {
  signed int min; // r16
  signed int sec; // r17
  // float var_a1;
  float pos_tmp[4];          // 0x40(r29)
  char str_tmp[128];         // 0x50(r29)
  float font_pos[4];         // 0xD0(r29)
  signed int font_col[4][4]; // 0xE0(r29)
  // Size: 0xB0, DWARF: 0x13F356
  DispTex tex; // 0x120(r29)
  char *word_tbl[3] = {
      "TIME LEFT", // @1769
      "\x94"
      "BRIGE ZEIT",   // @1770
      "TEMPS RESTANT" // @1771
  }; // 0x1D0(r29) // @1772
  float tmp; // 0x1DC(r29)
  s32 *word_tbl_ptr = &word_tbl;

  // packet = packet; // 0x1E0

  pos_tmp[0] = 320.0f;

  if (vnmdispDivSide == 0) {
    pos_tmp[1] = 16.0f + vnmdispParamPosUp;
  } else {
    pos_tmp[1] = vnmdispParamPosUp + vnmdispScrBottom[0];
  }
  nmdispInitFont();
  tex.data = &vnmdispTexData->tex[2];
  tex.tex_size[0] = 0x80;
  tex.tex_size[1] = 0x40;
  tex.tex_uv[0] = 0;
  tex.tex_uv[1] = 0;
  tex.col[0][0] = 0;
  tex.col[0][1] = 0;
  tex.col[0][2] = 0;
  tex.col[0][3] = 0x40;
  tex.option.sprite = 1;
  tex.option.bil = 1;
  if (vnmdispDivSide == 0) {
    tex.option.width = tex.tex_size[0];
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0] - (tex.option.width / 2.0f);
    tex.vertex[0][1] = pos_tmp[1];
  } else {
    tex.option.width = tex.tex_size[0];
    tex.option.height = (tex.tex_size[1] / 2.0f);
    tex.vertex[0][0] = pos_tmp[0] - (tex.option.width / 2.0f);
    tex.vertex[0][1] = pos_tmp[1] - (tex.option.height / 2.0f);
  }
  nmdrawFTex(packet, &tex);
  if (vnmdispDivSide == 0) {
    ulstdSprintf(str_tmp, "%s", word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
    font_pos[0] = pos_tmp[0] - (tmp / 2.0f);
    font_pos[1] = pos_tmp[1];
    nmfontFPrintF(packet, str_tmp, font_pos);
  }
  // var_a1 = -1;
  if (vspDispEnv.time_left == -1) {
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    // var_a1 = 0x40;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x80;
    font_col[1][2] = 0x40;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x40;
    font_col[2][2] = 0x40;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x40;
    font_col[3][2] = 0x40;
    font_col[3][3] = 0x80;
  } else if (vspDispEnv.time_left == 0) {
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x40;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x40;
    font_col[2][2] = 0x40;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x40;
    font_col[3][2] = 0x40;
    font_col[3][3] = 0x80;
  } else if (vspDispEnv.time_left < 6) {
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x40;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x40;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x40;
    font_col[2][2] = 0x40;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x40;
    font_col[3][2] = 0x40;
    switch (vnmdispTimeLeft.state) {
    case 1:
      font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] =
          (vnmdispTimeLeft.cnt << 7) / 20;
      break;
    case 3:
      font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] =
          0x80 - ((vnmdispTimeLeft.cnt << 7) / 20);
      break;
    default:
      font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] = 0x80;
      break;
    }
  } else if (vspDispEnv.time_left < 11) {
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x40;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x40;
    font_col[2][2] = 0x40;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x40;
    font_col[3][2] = 0x40;
    font_col[3][3] = 0x80;
  } else {
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x80;
    font_col[1][2] = 0x40;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x40;
    font_col[2][2] = 0x40;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x40;
    font_col[3][2] = 0x40;
    font_col[3][3] = 0x80;
  }
  nmfontSetCol(&font_col[0][0]);
  if (vspDispEnv.time_left == -1) {
    nmfontSetPack(0);
    nmfontSetFSize(48.0f, 40.0f);
    ulstdSprintf(str_tmp, "\x84"); // @1598
    tmp = nmfontGetStrFLen(str_tmp, 48.0f);
    font_pos[1] = 16.0f + pos_tmp[1];
    if (vnmdispDivSide == 0) {
      font_pos[0] = pos_tmp[0] - (tmp / 2.0f);
    } else {
      font_pos[1] = pos_tmp[1] - 20.0f;
    }
    nmfontGPrintF(packet, str_tmp, &font_pos[0]);
    return;
  }

  min = (vspDispEnv.time_left / 60);
  sec = (signed int)vspDispEnv.time_left % 60;
  if (vnmdispDivSide == 0) {
    nmfontSetFSize(32.0f, 32.0f);
    ulstdSprintf(str_tmp, "%d%02d", min, sec); // @1168
    tmp = nmfontGetStrFLen(str_tmp, 32.0f);
    ulstdSprintf(str_tmp, ":"); // @514
    tmp = tmp + nmfontGetPackStrFLen(str_tmp, 32.0f, 0);
    nmfontSetPack(0);
    font_pos[0] = pos_tmp[0] - (tmp / 2.0f);
    font_pos[1] = 20.0f + pos_tmp[1];
    ulstdSprintf(str_tmp, "%d", min); // @1170
    tmp = nmfontGetStrFLen(str_tmp, 32.0f);
    nmfontGPrintF(packet, str_tmp, &font_pos[0]);
    font_pos[0] += tmp;
    nmfontSetPack(1);
    ulstdSprintf(str_tmp, ":"); // @514
    tmp = nmfontGetPackStrFLen(str_tmp, 32.0f, 0);
    nmfontGPrintF(packet, str_tmp, &font_pos[0]);
    font_pos[0] += tmp;
    nmfontSetPack(0);
    ulstdSprintf(str_tmp, "%02d", sec); // @1171
    nmfontGPrintF(packet, str_tmp, &font_pos[0]);
    return;
  }

  nmfontSetFSize(24.0f, 24.0f);
  ulstdSprintf(str_tmp, "%d%02d", min, sec); // @1168
  tmp = nmfontGetStrFLen(str_tmp, 24.0f);
  ulstdSprintf(str_tmp, ":"); // @514
  tmp += nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
  nmfontSetPack(0);
  font_pos[0] = pos_tmp[0] - (tmp / 2.0f);
  font_pos[1] = pos_tmp[1] - 12.0f;
  ulstdSprintf(str_tmp, "%d", min); // @1170
  tmp = nmfontGetStrFLen(str_tmp, 24.0f);
  nmfontGPrintF(packet, str_tmp, &font_pos[0]);
  font_pos[0] += tmp;
  nmfontSetPack(1);
  ulstdSprintf(str_tmp, ":");
  tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0); // @514
  nmfontGPrintF(packet, str_tmp, &font_pos[0]);
  font_pos[0] += tmp;
  nmfontSetPack(0);
  ulstdSprintf(str_tmp, "%02d", sec); // @1171
  nmfontGPrintF(packet, str_tmp, &font_pos[0]);
}

static void nmdispTrickPtsFaild(VgmsysGifPkt *packet, signed int id) {
  // s32 id; // 160
  // s32 packet; // 150
  // f32 tmp; // 14c
  // s32 ice.pack; // 138
  // f32 ice.height; // 134
  // f32 ice.width; // 130
  // f32 ice.col[3][3]; // 12c
  // s32 ice.col[3][2]; // 128
  // s32 ice.col[3][1]; // 124
  // s32 ice.col[3][0]; // 120
  // f32 ice.col[2][3]; // 11c
  // s32 ice.col[2][2]; // 118
  // s32 ice.col[2][1]; // 114
  // s32 ice.col[2][0]; // 110
  // f32 ice.col[1][3]; // 10c
  // s32 ice.col[1][2]; // 108
  // s32 ice.col[1][1]; // 104
  // s32 ice.col[1][0]; // 100
  // f32 ice.col[0][3]; // fc
  // s32 ice.col[0][2]; // f8
  // s32 ice.col[0][1]; // f4
  // s32 ice.col[0][0]; // f0
  // s32 ice.data; // e0
  // f32 ice.pos[1]; // d4
  // f32 ice.pos[0]; // d0
  // f32 font_size[1]; // c4
  // f32 font_size[0]; // c0
  // f32 font_pos[1]; // b4
  // f32 font_pos[0]; // b0
  // s8 str_tmp[1]; // 31
  // u8 str_tmp[0]; // 30
  // f32 temp_f0;
  // f32 temp_f0_2;
  // s32 i;

  signed int i;       // r16
  signed int cnt;     // r17
  char str_tmp[128];  // 0x30(r29)
  float font_pos[4];  // 0xB0(r29)
  float font_size[4]; // 0xC0(r29)
  // Size: 0x70, DWARF: 0x13BC8D
  // struct
  // {
  //     float pos[4]; // Offset: 0x0, DWARF: 0x13BCA9
  //     // Size: 0x10, DWARF: 0x133E14
  // struct
  // {
  //     signed short tofs; // Offset: 0x0, DWARF: 0x133E30
  //     signed short cofs; // Offset: 0x2, DWARF: 0x133E51
  //     signed short width; // Offset: 0x4, DWARF: 0x133E72
  //     signed short height; // Offset: 0x6, DWARF: 0x133E94
  //     signed short tw; // Offset: 0x8, DWARF: 0x133EB7
  //     signed short th; // Offset: 0xA, DWARF: 0x133ED6
  //     signed short image_bit; // Offset: 0xC, DWARF: 0x133EF5
  //     signed short clut_bit; // Offset: 0xE, DWARF: 0x133F1B
  // }* data; // Offset: 0x10, DWARF: 0x13BCCB
  // signed int col[4][4]; // Offset: 0x20, DWARF: 0x13BCF1
  // float width; // Offset: 0x60, DWARF: 0x13BD13
  // float height; // Offset: 0x64, DWARF: 0x13BD35
  // signed int pack; // Offset: 0x68, DWARF: 0x13BD58
  // signed int res; // Offset: 0x6C, DWARF: 0x13BD79
  Ice ice;   // 0xD0(r29)
  float tmp; // 0x14C(r29)

  // packet = packet; // 150
  // id = id; // 160
  if (vnmdispDivMode == 0) {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  } else {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  }
  font_pos[1] = 16.0f + (vnmdispScrBottom[id] - 48.0f);
  ulstdSprintf(&str_tmp[0], "%d", vnmdispTrickPtsDraw[id].single);
  // temp_f0 = nmfontGetStrFLen(font_size[0], &str_tmp[0]);
  tmp = nmfontGetStrFLen(str_tmp, font_size[0]);
  font_pos[0] = vnmdispScrCenter[id] - (tmp / 2.0f);
  for (i = 0; i < vnmdispTrickPtsInfo[id].num; i++) {
    str_tmp[0] = vnmdispTrickPtsInfo[id].word[i].str;
    str_tmp[1] = 0;
    if (vnmdispTrickPtsInfo[id].word[i].state == 2) {
      ice.pos[0] = font_pos[0];
      ice.pos[1] = font_pos[1];
      ice.col[0][0] = ice.col[1][0] = ice.col[2][0] = ice.col[3][0] = 0x80;
      ice.col[0][1] = ice.col[1][1] = ice.col[2][1] = ice.col[3][1] = 0x80;
      ice.col[0][2] = ice.col[1][2] = ice.col[2][2] = ice.col[3][2] = 0x80;
      ice.col[0][3] = ice.col[1][3] = ice.col[2][3] = ice.col[3][3] = 0x80;
      ice.data = vnmdispTexData->tex + 0x5;
      ice.width = font_size[0];
      ice.height = font_size[1];
      ice.pack = 0;
      nmdrawIceFont(packet, &str_tmp[0], &ice);
    } else if (vnmdispTrickPtsInfo[id].word[i].state == 3) {
      cnt = vnmdispTrickPtsInfo[id].word[i].cnt;
      ice.pos[0] = font_pos[0] + vnmdispTrickPtsInfo[id].word[i].pos[0];
      ice.pos[1] = font_pos[1] + vnmdispTrickPtsInfo[id].word[i].pos[1];
      ice.col[0][0] = ice.col[1][0] = ice.col[2][0] = ice.col[3][0] = 0x80;
      ice.col[0][1] = ice.col[1][1] = ice.col[2][1] = ice.col[3][1] = 0x80;
      ice.col[0][2] = ice.col[1][2] = ice.col[2][2] = ice.col[3][2] = 0x80;
      ice.col[3][3] = 128.0f - ((128.0f * cnt) / 20.0f);
      if (ice.col[3][3] < 0) {
        ice.col[3][3] = 0;
      }
      ice.col[0][3] = ice.col[1][3] = ice.col[2][3] = ice.col[3][3];
      ice.data = vnmdispTexData->tex + 0x5;
      ice.width = font_size[0];
      ice.height = font_size[1];
      ice.pack = 0;
      nmdrawIceFont(packet, &str_tmp[0], &ice);
      if (font_pos[1] > 448.0f) {
        vnmdispTrickPtsInfo[id].word[i].state = 0;
      }
    }
    tmp = nmfontGetStrFLen(str_tmp, font_size[0]);
    font_pos[0] = font_pos[0] + tmp;
  }
}

static void nmdispDivLineImage(VgmsysGifPkt *packet) {
  signed int i; // r16
  // Size: 0x90, DWARF: 0x140CBB
  Poly poly; // 0x20(r29)

  // packet = packet;
  if (vnmdispDivSide == 0) {
    for (i = 0; i < 5; i++) {
      if (vnmdispLineImage[i].state != 0) {
        poly.vertex[0][0] = vnmdispLineImagePos[i] - 2.0f;
        poly.vertex[0][1] = 0.0f;
        poly.vertex[0][2] = 1.0f;
        poly.col[0][0] = 0x60;
        poly.col[0][1] = 0x60;
        poly.col[0][2] = 0x60;
        poly.col[0][3] = 0x80 - ((vnmdispLineImage[i].cnt << 7) / 20);
        poly.option.sprite = 1;
        poly.option.width = 4.0f;
        poly.option.height = 448.0f;
        nmdrawFPoly(packet, &poly);
      }
    }
  } else {
    for (i = 0; i < 5; i++) {
      if (vnmdispLineImage[i].state != 0) {
        poly.vertex[0][0] = 0.0f;
        poly.vertex[0][1] = vnmdispLineImagePos[i] - 2.0f;
        poly.vertex[0][2] = 1.0f;
        poly.col[0][0] = 0x60;
        poly.col[0][1] = 0x60;
        poly.col[0][2] = 0x60;
        poly.col[0][3] = 0x80 - ((vnmdispLineImage[i].cnt << 7) / 20);
        poly.option.sprite = 1;
        poly.option.width = 640.0f;
        poly.option.height = 4.0f;
        nmdrawFPoly(packet, &poly);
      }
    }
  }
}

static void nmdispBoostLap(VgmsysGifPkt *packet, signed int id) {
  float pos_tmp[4];       // 0x30(r29)
  char str_tmp[256];      // 0x40(r29)
  float font_pos[4];      // 0x140(r29)
  signed int font_col[4]; // 0x150(r29)

  // Size: 0x70, DWARF: 0x136340
  DispBar bar; // 0x160(r29)
  char *word_tbl[3] = {
      // 0x1D8(r29) @2778
      "LAPS",   // English Laps text @2775
      "RUNDEN", // German Laps text @2776
      "TOURS"   // French Laps text @2777
  };
  s32 *word_tbl_ptr = &word_tbl;
  signed int lap; // r17
  float tmp;      // 0x1E8(r29)
  float len;      // 0x1EC(r29)

  // (void)lap;

  if (vnmdispDivSide == 0) {
    if (id == 0) {
      pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    } else {
      pos_tmp[0] = vnmdispParamPosRight - 16.0f;
    }
  } else {
    pos_tmp[0] = vnmdispParamPosRight - 16.0f;
  }
  pos_tmp[1] = vnmdispScrBottom[id] - 26.0f;
  len = 128.0f;
  nmdispInitFont();
  if (vnmdispDivSide == 0) {
    if (id == 0) {
      bar.pos[0] = pos_tmp[0];
    } else {
      bar.pos[0] = pos_tmp[0] - (16.0f + len);
    }
  } else {
    bar.pos[0] = pos_tmp[0] - (16.0f + len);
  }
  bar.pos[1] = pos_tmp[1];
  bar.col[0][0] = 0;
  bar.col[0][1] = 0;
  bar.col[0][2] = 0;
  bar.col[0][3] = 0x40;
  bar.col[1][0] = 0;
  bar.col[1][1] = 0;
  bar.col[1][2] = 0;
  bar.col[1][3] = 0x40;
  bar.col[2][0] = 0;
  bar.col[2][1] = 0;
  bar.col[2][2] = 0;
  bar.col[2][3] = 0x40;
  bar.col[3][0] = 0;
  bar.col[3][1] = 0;
  bar.col[3][2] = 0;
  bar.col[3][3] = 0x40;
  bar.option.width = 24.0f + len;
  bar.option.height = 12.0f;
  bar.type = 1;
  nmdrawBar(packet, &bar);
  lap = tmevGetLap(id);
  ulstdSprintf(&str_tmp[0], "%d/%d %s", lap, 3, word_tbl[*vnmdispLang]);
  tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
  if (vnmdispDivSide == 0) {
    if (id == 0) {
      font_pos[0] = 8.0f + pos_tmp[0] + ((len - tmp) / 2.0f);
    } else {
      font_pos[0] = (pos_tmp[0] - (8.0f + len)) + ((len - tmp) / 2.0f);
    }
  } else {
    font_pos[0] = (pos_tmp[0] - (8.0f + len)) + ((len - tmp) / 2.0f);
  }
  font_pos[1] = pos_tmp[1] - 6.0f;
  font_col[0] = 0x80;
  font_col[1] = 0x60;
  font_col[2] = 0x40;
  font_col[3] = 0x80;
  nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
}

static void nmdispLevelGoals(VgmsysGifPkt *packet) {
  signed int i;             // r16 // s0
  signed int min;           // r17 // s1
  signed int sec;           // r18 // s2
  signed int total_soft;    // r19 // s3
  unsigned int *level_goal; // r20 // s4
  signed int *game_soft;    // r21 // s5
  char str_tmp[128];        // r29+0x80
  float pos_tmp[4];         // r29+0x100
  float font_pos[4];        // r29+0x110
  sceVu0IMATRIX font_col;   // r29+0x120
  // Size: 0x30, DWARF: 0x136A94
  Check check; // r29+0x160
  Key key;     // r29+0x190
  Point point; // r29+0x1D0
  char *word_tbl[3] = {"TOTAL SPONSORS", "SPONSOREN GESAMT",
                       "NB DE SPONSORS"}; // r29+0x240 // @2982
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // r29+0x24C

  // packet = packet; // sp 250
  if (vnmdispCharEnv->no < 0xC) {
    level_goal = &vnmdispSecret->character[vnmdispCharEnv->no]
                      .level_goal[vnmdispCrsEnv->no];
    game_soft = vnmdispSecret->character[vnmdispCharEnv->no].soft;
  } else {
    level_goal = &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                      .character.level_goal[vnmdispCrsEnv->no];
    game_soft = vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                    .character
                    .soft; // index soft by how much? // + (var_a0 * 4) + 0x5A8;
  }
  pos_tmp[0] = 48.0f;
  pos_tmp[1] = 16.0f;
  nmdispInitFont();
  if (vnmdispLevelGoals.state != 0) {
    nmfontSetType(1);
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(font_col[0]);
    nmfontSetFSize(32.0f, 32.0f);
    ulstdSprintf(str_tmp, "%s", vnmtblResultItem[*vnmdispLang][0]);
    // temp_f0 = nmfontGetPackStrFLen(str_tmp, 1, 32.0f);
    // tmp = nmfontGetPackStrFLen(str_tmp, 1, 32.0f);
    tmp = nmfontGetPackStrFLen(str_tmp, 32.0f, 1);
    font_pos[0] = vnmdispLevelGoalsPos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp[1];
    nmfontGPrintF(packet, str_tmp, font_pos);
    nmfontSetType(0);
    nmfontSetFSize(16.0f, 16.0f);
    for (i = 0; i < 9; i++) {
      if (level_goal[0] & (1 << i)) {
        font_col[0][0] = 0x40;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
      } else {
        // temp_v0 = vnmdispLevelMark[i].state;
        switch (vnmdispLevelMark[i].state) {
        case 1:
        case 2:
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80 - ((vnmdispLevelMark[i].cnt << 5) / 10);
          font_col[0][2] = 0x80 - ((vnmdispLevelMark[i].cnt << 6) / 10);
          font_col[0][3] = 0x80;
          break;
        case 3:
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x60;
          font_col[0][2] = 0x40;
          font_col[0][3] = 0x80;
          break;
        default:
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          font_col[0][3] = 0x80;
          break;
        }
      }
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      font_pos[1] = 64.0f + pos_tmp[1] + (24.0f * (f32)i);
      switch (i) {
      case 0:
      case 1:
      case 2:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblLevelCompMes[*vnmdispLang][i]);
        font_pos[0] = pos_tmp[0] + vnmdispLevelGoalsPos[i + 1];
        nmfontFPrintF(packet, str_tmp, font_pos);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] =
            (640.0f + vnmdispLevelGoalsPos[i + 1]) - (pos_tmp[0] + tmp);
        nmfontFPrintF(packet, str_tmp, font_pos);
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no][i];
        point.type = 0;
        point.size[0] = 0x10;
        point.size[1] = 0x10;
        point.flat = 1;
        point.base = 1;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        break;
      case 3:
        min = vsptblLevelGoalValue[vnmdispCrsEnv->no][i] / 60;
        sec = vsptblLevelGoalValue[vnmdispCrsEnv->no][i] % 60;
        font_pos[0] = pos_tmp[0] + vnmdispLevelGoalsPos[i + 1];
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s ", vnmtblLevelCompMes[*vnmdispLang][i]);
        nmfontFPrintF(packet, str_tmp, font_pos);

        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] += tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%d", min);
        nmfontFPrintF(packet, str_tmp, font_pos);

        tmp = nmfontGetStrFLen(str_tmp, 16.0f);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblCommon[*vnmdispLang][2]);
        nmfontFPrintF(packet, str_tmp, font_pos);

        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] += tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%02d", sec);
        nmfontFPrintF(packet, str_tmp, font_pos);

        tmp = nmfontGetStrFLen(str_tmp, 16.0f);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s ", vnmtblLevelCompMes[*vnmdispLang][6]);
        nmfontFPrintF(packet, str_tmp, font_pos);

        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] += tmp;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no][i + 1];
        point.type = 0;
        point.size[0] = 0x10;
        point.size[1] = 0x10;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);

        tmp = nmdrawGetPointLen(&point);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][1]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 4:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, vnmtblLevelCompMes[*vnmdispLang][i],
                     vsptblCourseName[vnmdispCrsEnv->no + 0x10]);
        font_pos[0] = pos_tmp[0] + vnmdispLevelGoalsPos[i + 1];
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 5:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblLevelCompMes[*vnmdispLang][i]);
        font_pos[0] = pos_tmp[0] + vnmdispLevelGoalsPos[i + 1];
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 6:
      case 7:
      case 8:
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s",
                     vsptblLevelGoalStr[vnmdispCrsEnv->no][i - 6]);
        font_pos[0] = pos_tmp[0] + vnmdispLevelGoalsPos[i + 1];
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      }
      check.pos[0] = pos_tmp[0] + vnmdispLevelGoalsPos[i + 1];
      check.pos[1] = 8.0f + font_pos[1];
      check.pos[2] = font_pos[2];
      check.data = vnmdispTexData->tex;
      switch (vnmdispLevelMark[i].state) {
      case 1:
        check.cnt = vnmdispLevelMark[i].cnt;
        nmdrawCheck(packet, &check);
        break;
      case 2:
      case 3:
        check.cnt = 5;
        nmdrawCheck(packet, &check);
        break;
      }
    }
    total_soft = 0;
    for (i = 0; i < 8; i++) {
      total_soft += game_soft[i];
    }
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x80;
    font_col[1][2] = 0x40;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(20.0f, 28.0f);
    ulstdSprintf(str_tmp, "%s", word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    ulstdSprintf(str_tmp, " %2d/%2d", total_soft, 0x48);
    tmp += nmfontGetStrFLen(str_tmp, 20.0f);
    nmfontSetPack(1);
    ulstdSprintf(str_tmp, "%s", word_tbl[*vnmdispLang]);
    font_pos[0] = vnmdispLevelGoalsPos[10] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = 352.0f;
    nmfontGPrintF(packet, str_tmp, font_pos);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    nmfontSetPack(0);
    ulstdSprintf(str_tmp, " %2d/%2d", total_soft, 0x48);
    font_pos[0] += tmp;
    nmfontGPrintF(packet, str_tmp, font_pos);
    nmdispCareerUp(packet);
    if (vnmdispOpe.state != 0) {
      key.pos[0] = 320.0f;
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.button = 0;
      key.message = 1;
      key.language = *vnmdispLang;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.center = 1;
      key.language = *vnmdispLang;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispCareerUp(VgmsysGifPkt *packet) {
  signed int tmp;            // r16
  char str_tmp[128];         // 0x40(r29)
  float font_pos[4];         // 0xC0(r29)
  signed int font_col[4][4]; // 0xD0(r29)
  // Size: 0x90, DWARF: 0x140CBC
  Poly poly;             // 0x110(r29)
  signed int board_type; // r17
  char *word_tbl[3] = {  // 0x1A0(r29)
                       "ADD", "PLUS", "AJOUTER"};
  s32 *word_tbl_ptr = &word_tbl;

  nmdispInitFont();
  if (vnmdispLevelCareer.state != 0) {
    if (vnmdispLevelCareer.state == 3) {
      poly.vertex[0][0] = vnmdispLevelCareerPos[vnmdispCareerItem.num];
    } else {
      poly.vertex[0][0] = vnmdispLevelCareerPos[0];
    }
    poly.vertex[0][1] = 149.333328f;
    poly.vertex[0][2] = 1.0f;
    poly.col[0][0] = 0x40;
    poly.col[0][1] = 0x40;
    poly.col[0][2] = 0x80;
    poly.col[0][3] = 0x60;
    poly.option.sprite = 1;
    poly.option.width = 640.0f;
    poly.option.height = 149.333328f;
    nmdrawFPoly(packet, &poly);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x80;
    font_col[1][2] = 0x40;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(24.0f, 24.0f);
    ulstdSprintf(str_tmp, "%s",
                 vnmtblCareerMessage[*vnmdispLang][vnmdispCareerItem.type]);
    tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
    if (vnmdispLevelCareer.state == 3) {
      font_pos[0] = vnmdispLevelCareerPos[0] + ((640.0f - (f32)tmp) / 2.0f);
    } else {
      font_pos[0] = vnmdispLevelCareerPos[1] + ((640.0f - (f32)tmp) / 2.0f);
    }
    if (vnmdispCareerItem.num == 3) {
      font_pos[1] = 33.0f + poly.vertex[0][1];
    } else {
      font_pos[1] = 42.0f + poly.vertex[0][1];
    }
    nmfontGPrintF(packet, str_tmp, font_pos);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    nmfontSetFSize(18.0f, 18.0f);
    font_pos[1] += 42.0f;
    switch (vnmdispCareerItem.type) {
    case 0:
      ulstdSprintf(str_tmp, "%s", vsptblCourseName[vnmdispCareerItem.value[0]]);
      break;
    case 1:
      if (vnmdispCharEnv->no < 0xC) {
        ulstdSprintf(
            str_tmp, "%s",
            vsptblBoardName[vnmdispCharEnv->no][vnmdispCareerItem.value[0]]);
      } else {
        board_type = vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                         .board_type;
        ulstdSprintf(str_tmp, "%s",
                     vsptblBoardName[board_type][vnmdispCareerItem.value[0]]);
      }
      break;
    case 2:
      ulstdSprintf(str_tmp, "%s %d %s", word_tbl[*vnmdispLang], 2,
                   vnmtblCommon[*vnmdispLang][0]);
      break;
    case 3:
      if (vnmdispCharEnv->no < 0xC) {
        ulstdSprintf(
            str_tmp, "%s",
            vsptblBoardName[vnmdispCharEnv->no][vnmdispCareerItem.value[0]]);
      } else {
        board_type = vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                         .board_type;
        ulstdSprintf(str_tmp, "%s",
                     vsptblBoardName[board_type][vnmdispCareerItem.value[0]]);
      }
      break;
    case 4:
      ulstdSprintf(str_tmp, "%s", vsptblMovieName[vnmdispCareerItem.value[0]]);
      break;
    case 5:
      ulstdSprintf(str_tmp, "%s",
                   vsptblCharacterName[vnmdispCareerItem.value[0]]);
      break;
    case 6:
      ulstdSprintf(str_tmp, "%s", vsptblCheats[vnmdispCareerItem.value[0]]);
      break;
    }
    tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
    if (vnmdispLevelCareer.state == 3) {
      font_pos[0] = vnmdispLevelCareerPos[1] + ((640.0f - (f32)tmp) / 2.0f);
    } else {
      font_pos[0] = vnmdispLevelCareerPos[2] + ((640.0f - (f32)tmp) / 2.0f);
    }
    nmfontFPrintF(packet, str_tmp, font_pos);
    if (vnmdispCareerItem.num == 3) {
      font_pos[1] += 22.5f;
      switch (vnmdispCareerItem.type) {
      case 4:
        ulstdSprintf(str_tmp, "%s",
                     vsptblMovieName[vnmdispCareerItem.value[1]]);
        break;
      default:
        str_tmp[0] = 0;
        break;
      }
      if (str_tmp != 0) {
        tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
        if (vnmdispLevelCareer.state == 3) {
          font_pos[0] = vnmdispLevelCareerPos[2] + ((640.0f - (f32)tmp) / 2.0f);
        } else {
          font_pos[0] = vnmdispLevelCareerPos[3] + ((640.0f - (f32)tmp) / 2.0f);
        }
        nmfontFPrintF(packet, str_tmp, font_pos);
      }
    }
  }
}

static void nmdispCalcCareer() {
  switch (vnmdispMode) {
  case 1:
    nmdispCalcIntr();
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcParam();
      nmdispCalcTimeLeft();
      nmdispCalcOutMes();
    }
    nmdispCalcPauseCareer();
    nmdispCalcOperate();
    break;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcResultCareer();
    }
    nmdispCalcOperate();
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcReplay();
    }
    break;
  case 5:
    nmdispCalcReplay();
    break;
  case 0:
    break;
  }
}

static void nmdispCalcFreeride() {
  switch (vnmdispMode) {
  case 1:
    nmdispCalcIntr();
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcParam();
      nmdispCalcTimeLeft();
      nmdispCalcOutMes();
    }
    nmdispCalcPauseFreeride();
    nmdispCalcOperate();
    break;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcResultFreeride();
    }
    nmdispCalcOperate();
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcReplay();
    }
    break;
  case 5:
    nmdispCalcReplay();
    break;
  case 0:
    break;
  }
}

static void nmdispCalcMatchAttack() {
  switch (vnmdispMode) {
  case 1:
    nmdispCalcIntr();
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcParam();
      nmdispCalcTimeLeft();
      nmdispCalcWinLoseDraw();
      nmdispCalcOutMes();
    }
    nmdispCalcPauseMatch();
    nmdispCalcOperate();
    break;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcResultMatch();
    }
    nmdispCalcOperate();
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcReplay();
    }
    break;
  case 5:
    nmdispCalcReplay();
    break;
  case 0:
    break;
  }
}

static void nmdispCalcMatchPush() {
  switch (vnmdispMode) {
  case 1:
    nmdispCalcIntr();
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcParam();
      nmdispCalcTimeLeft();
      nmdispCalcDiv();
      nmdispCalcDivExp();
      nmdispCalcDivImage();
      nmdispCalcWinLoseDraw();
      nmdispCalcOutMes();
    }
    nmdispCalcPauseMatch();
    nmdispCalcOperate();
    break;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcResultMatch();
    }
    nmdispCalcOperate();
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcReplay();
    }
    break;
  case 5:
    nmdispCalcReplay();
    break;
  case 0:
    break;
  }
}

static void nmdispCalcMatchHorse() {
  switch (vnmdispMode) {
  case 1:
    nmdispCalcIntr();
    break;
  case 2:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcParam();
      nmdispCalcTimeLeft();
      nmdispCalcHorseEnter();
      nmdispCalcHorseMes();
      nmdispCalcOutMes();
    }
    nmdispCalcBackGround();
    nmdispCalcPauseHorse();
    nmdispCalcOperate();
    break;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcResultMatch();
    }
    nmdispCalcOperate();
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      nmdispCalcReplay();
    }
    break;
  case 5:
    nmdispCalcReplay();
    break;
  case 0:
    break;
  }
}

static void nmdispCalcParam() {
  float acc;  // 0x4(r29)
  float vel;  // 0x8(r29)
  float move; // 0xC(r29)

  if (vnmdispParam.cnt < 0x3CU) {
    acc = -0.17777778f;
    vel = 10.666667f;
    move = (vel * vnmdispParam.cnt) +
           ((acc * (vnmdispParam.cnt * vnmdispParam.cnt)) / 2.0f);
    vnmdispParamPosLeft = -320.0f + move;
    vnmdispParamPosRight = 960.0f - move;
    acc = -0.12444445f;
    vel = 7.4666667f;
    move = (vel * vnmdispParam.cnt) +
           ((acc * (vnmdispParam.cnt * vnmdispParam.cnt)) / 2.0f);
    vnmdispParamPosUp = -224.0f + move;
    vnmdispParamPosDown = 448.0f - move;
    vnmdispParam.cnt += 1;
    return;
  }
  vnmdispParamPosLeft = 0.0f;
  vnmdispParamPosRight = 640.0f;
  vnmdispParamPosUp = 0.0f;
  vnmdispParamPosDown = 224.0f;
}

static signed int nmdispCalcSlide(Info *info, float *vertex, signed int frame) {
  signed int cnt;      // r16
  signed int i;        // r17
  signed int j;        // r18
  signed int loop_num; // r19
  signed int ret;      // r20
  float acc;           // 0x54(r29)
  float vel;           // 0x58(r29)
  float move;          // 0x5C(r29)

  ret = 1;
  loop_num = 0;
  cnt = 0;
  if (frame < (info->lag * (info->num - 1))) {
    loop_num = (frame / info->lag) + 1;
  } else {
    loop_num = info->num;
  }
  j = 0;
  for (i = 0; i < loop_num; i++) {
    if (!(info->skip & (1 << i))) {
      cnt = frame - (info->lag * j);
      if (cnt < info->frame) {
        switch (info->vel) {
        case 0:
          acc = (2.0f * info->length) / (info->frame * info->frame);
          vel = 0.0f;
          move = (vel * cnt) + ((acc * (cnt * cnt)) / 2.0f);
          break;
        case 1:
          acc = (2.0f * info->length) / (info->frame * info->frame);
          acc = -acc;
          vel = (2.0f * info->length) / info->frame;
          move = (vel * cnt) + ((acc * (cnt * cnt)) / 2.0f);
          break;
        }
        if (info->dir == 0) {
          vertex[i] = info->start + move;
        } else {
          vertex[i] = info->start - move;
        }
        ret = 0;
      } else if (info->dir == 0) {
        vertex[i] = info->start + info->length;
      } else {
        vertex[i] = info->start - info->length;
      }
      j += 1;
    }
  }
  return ret;
}

static void nmdispCalcPauseMenuCareer() {
  signed int i;   // r16
  signed int tmp; // r17
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x30(r29)

  switch (vnmdispPauseMenu.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 7;
    switch (vnmdispPauseItem) {
    case 2:
    case 3:
    case 4:
      info.skip = 1 << ((vnmdispPauseItem) + 1);
      break;
    default:
      info.skip = 0;
      break;
    }
    tmp = nmdispCalcSlide(&info, &vnmdispPausePos[0], vnmdispPauseMenu.cnt);
    if (tmp == 1) {
      vnmdispPauseMenu.state = 2;
      vnmdispPauseMenu.cnt = 0;
      vnmdispPausePos[vnmdispPauseItem + 1] = 0.0f;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispPauseMenu.cnt += 1;
    if (vnmdispPauseMenu.cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
  case 2:
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 7;
    if (vnmdispPauseCancel == 1) {
      info.skip = 0;
    } else {
      info.skip = 1 << (vnmdispPauseItem + 1);
    }
    tmp = nmdispCalcSlide(&info, &vnmdispPausePos[0], vnmdispPauseMenu.cnt);
    if (tmp == 1) {
      vnmdispPauseMenu.state = 0;
      vnmdispPauseMenu.cnt = 0;
      vnmdispPauseCancel = 0;
      vnmdispPausePos[vnmdispPauseItem + 1] = -640.0f;
      switch (vnmdispPauseFlow) {
      case 0:
        vnmdispPauseItem = 0;
        vnmdispOpeAccept = 1;
        gmsysPadResume();
        return;
      case 2:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_restart(0);
        return;
      case 7:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_finish(0);
        gmsysPadResume();
        return;
      case 9:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_finish(0);
        gmsysPadResume();
        return;
      }
    } else {
      vnmdispPauseMenu.cnt += 1;
      if (vnmdispPause.state == 3 &&
          vnmdispPauseMenu.cnt == (info.lag * (info.num - 1))) {
        vnmdispBackGround.state = 3;
        vnmdispBackGround.cnt = 0;
      }
      if (vnmdispPauseMenu.cnt == 0xA) {
        switch (vnmdispPauseFlow) {
        case 3:
          vnmdispPauseSound.state = 1;
          vnmdispPauseSound.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          vnmdispSelectInt = nmbgmGetSelectTbl();
          return;
        case 4:
          vnmdispPauseTrick.state = 1;
          vnmdispPauseTrick.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          vnmdispPauseTrickCate = 0;
          for (i = 0; i < 9; i++) {
            nmdispInitList(&vnmdispTrickList[i]);
          }
          vnmdispTrickList[vnmdispPauseTrickCate].state = 1;
          vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
          return;
        case 5:
          vnmdispLevelGoalList.state = 1;
          vnmdispLevelGoalList.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          return;
        case 8:
          vnmdispPauseDebugFlow = 1;
          for (i = 0; i < 5; i++) {
            vnmdispPauseDebugPos[i] = -640.0f;
          }
          vnmdispPauseDebug.state = 1;
          vnmdispPauseDebug.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          break;
        }
      }
    }
    break;
  }
}

static void nmdispCalcPauseMenuFreeride() {
  signed int i;   // r16
  signed int tmp; // r17
  Info info;      // 0x30(r29)

  switch (vnmdispPauseMenu.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 7;
    switch (vnmdispPauseItem) {
    case 2:
    case 3:
    case 4:
      info.skip = 1 << (vnmdispPauseItem + 1);
      break;
    default:
      info.skip = 0;
      break;
    }
    tmp = nmdispCalcSlide(&info, &vnmdispPausePos[0], vnmdispPauseMenu.cnt);
    if (tmp == 1) {
      vnmdispPauseMenu.state = 2;
      vnmdispPauseMenu.cnt = 0;
      vnmdispPausePos[vnmdispPauseItem + 1] = 0.0f;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispPauseMenu.cnt += 1;
    if (vnmdispPauseMenu.cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
  case 2:
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 7;
    if (vnmdispPauseCancel == 1) {
      info.skip = 0;
    } else {
      info.skip = 1 << (vnmdispPauseItem + 1);
    }
    tmp = nmdispCalcSlide(&info, &vnmdispPausePos[0], vnmdispPauseMenu.cnt);
    if (tmp == 1) {
      vnmdispPauseMenu.state = 0U;
      vnmdispPauseMenu.cnt = 0;
      vnmdispPauseCancel = 0;
      vnmdispPausePos[vnmdispPauseItem + 1] = -640.0f;
      switch (vnmdispPauseFlow) {
      case 0:
        vnmdispPauseItem = 0;
        vnmdispOpeAccept = 1;
        gmsysPadResume();
        return;
      case 2:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_restart(0);
        return;
      case 7:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_finish(0);
        gmsysPadResume();
        return;
      case 9:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_finish(0);
        gmsysPadResume();
        return;
      }
    } else {
      vnmdispPauseMenu.cnt += 1;
      if (((vnmdispPause.state) == 3) &&
          (vnmdispPauseMenu.cnt == ((info.lag) * ((info.num) - 1)))) {
        vnmdispBackGround.state = 3;
        vnmdispBackGround.cnt = 0;
      }
      if (vnmdispPauseMenu.cnt == 0xA) {
        switch (vnmdispPauseFlow) {
        case 3:
          vnmdispPauseSound.state = 1;
          vnmdispPauseSound.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          vnmdispSelectInt = nmbgmGetSelectTbl();
          return;
        case 4:
          vnmdispPauseTrick.state = 1;
          vnmdispPauseTrick.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          vnmdispPauseTrickCate = 0;
          for (i = 0; i < 9; i++) {
            nmdispInitList(&vnmdispTrickList[i]);
          }
          vnmdispTrickList[vnmdispPauseTrickCate].state = 1;
          vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
          return;
        case 8:
          vnmdispPauseDebugFlow = 1;
          vnmdispPauseDebug.state = 1;
          vnmdispPauseDebug.cnt = 0;
          vnmdispPauseDebugItem = 0;
          vnmdispPauseDebugTop = 0;
          break;
        }
      }
    }
    break;
  }
}

static void nmdispCalcPauseMenuMatch() {
  // s16 info.skip;
  // u8 info.num;
  // u8 info.lag;
  // s8 info.vel;
  // s8 info.dir;
  // s16 info.frame;
  // f32 info.length;
  // f32 info.start;
  // s32 temp_a0;
  // s32 temp_a0_2;
  // s32 temp_a0_3;
  // s32 temp_v1;
  // s32 i;
  // s32 i;

  signed int i;   // r16
  signed int tmp; // r17
  // Size: 0x10, DWARF: 0x135A42
  // struct : <unknown type 0x140005>
  // {
  //     float start; // Offset: 0x0, DWARF: 0x135A5E
  //     float length; // Offset: 0x4, DWARF: 0x135A80
  //     signed short frame; // Offset: 0x8, DWARF: 0x135AA3
  //     char dir; // Offset: 0xA, DWARF: 0x135AC5
  //     char vel; // Offset: 0xB, DWARF: 0x135AE5
  //     char lag; // Offset: 0xC, DWARF: 0x135B05
  //     char num; // Offset: 0xD, DWARF: 0x135B25
  //     signed short skip; // Offset: 0xE, DWARF: 0x135B45
  Info info; // 0x30(r29)

  switch (vnmdispPauseMenu.state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.num = 6;
    switch (vnmdispPauseItem) {
    case 2:
    case 3:
      info.skip = 1 << ((vnmdispPauseItem) + 1);
      break;
    default:
      info.skip = 0;
      break;
    }
    tmp = nmdispCalcSlide(&info, &vnmdispPausePos[0], vnmdispPauseMenu.cnt);
    if (tmp == 1) {
      vnmdispPauseMenu.state = 2U;
      vnmdispPauseMenu.cnt = 0;
      vnmdispPausePos[vnmdispPauseItem + 1] = 0.0f;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispPauseMenu.cnt += 1;
    if (vnmdispPauseMenu.cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
  case 2:
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 7;
    if (vnmdispPauseCancel == 1) {
      info.skip = 0;
    } else {
      info.skip = 1 << (vnmdispPauseItem + 1);
    }
    tmp = nmdispCalcSlide(&info, &vnmdispPausePos[0], vnmdispPauseMenu.cnt);
    if (tmp == 1) {
      vnmdispPauseMenu.state = 0U;
      vnmdispPauseMenu.cnt = 0;
      vnmdispPauseCancel = 0;
      vnmdispPausePos[vnmdispPauseItem + 1] = -640.0f;
      switch (vnmdispPauseFlow) {
      case 0:
        vnmdispPauseItem = 0;
        vnmdispOpeAccept = 1;
        gmsysPadResume();
        return;
      case 2:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_restart(0);
        return;
      case 7:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_finish(0);
        gmsysPadResume();
        return;
      case 9:
        vnmdispPauseFlow = 0;
        ktmfMenuFunc_finish(0);
        gmsysPadResume();
        return;
      }
    } else {
      vnmdispPauseMenu.cnt += 1;
      if (((vnmdispPause.state) == 3) &&
          (vnmdispPauseMenu.cnt == ((info.lag) * ((info.num) - 1)))) {
        vnmdispBackGround.state = 3;
        vnmdispBackGround.cnt = 0;
      }
      if (vnmdispPauseMenu.cnt == 0xA) {
        switch (vnmdispPauseFlow) {
        case 3:
          vnmdispPauseSound.state = 1;
          vnmdispPauseSound.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          vnmdispSelectInt = nmbgmGetSelectTbl();
          return;
        case 4:
          vnmdispPauseTrick.state = 1;
          vnmdispPauseTrick.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          vnmdispPauseTrickCate = 0;
          for (i = 0; i < 9; i++) {
            nmdispInitList(&vnmdispTrickList[i]);
          }
          vnmdispTrickList[vnmdispPauseTrickCate].state = 1;
          vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
          return;
        case 8:
          vnmdispPauseDebugFlow = 1;
          for (i = 0; i < 5; i++) {
            vnmdispPauseDebugPos[i] = -640.0f;
          }
          vnmdispPauseDebug.state = 1;
          vnmdispPauseDebug.cnt = 0;
          vnmdispAllow.state = 0;
          vnmdispAllow.cnt = 0;
          break;
        }
      }
    }
    break;
  }
}

static void nmdispCalcPauseSelect(void) {
  signed int tmp; // r16
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x20(r29)

  switch (vnmdispPauseSelect.state) {
  case 0:
    break;
  case 1:
    if (vnmdispPauseMenu.state == 2) {
      vnmdispPauseSelect.state = 3;
      vnmdispPauseSelect.cnt = 0;
    }
    break;
  case 2:
    if (vnmdispPauseMenu.state == 0) {
      vnmdispPauseSelect.state = 0;
      vnmdispPauseSelect.cnt = 0;
    }
    break;
  case 3:
    nmdispCalcMenuItem();
    vnmdispPauseSelectPos[0] = 0.0f;
    vnmdispPauseSelectPos[1] = 144.0f + (30.0f * (f32)vnmdispPauseItem);
    break;
  case 4:
    vnmdispPauseSelectPos[0] = 0.0f;
    vnmdispPauseSelectPos[1] = 64.0f;
    break;
  case 5:
    info.start = 144.0f + (30.0f * (f32)vnmdispPauseItem);
    info.length = 80.0f + (30.0f * (f32)vnmdispPauseItem);
    info.frame = 0xA;
    info.dir = 1;
    info.vel = 1;
    info.lag = 0;
    info.num = 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispPauseSelectPos[1],
                          vnmdispPauseSelect.cnt);
    if (tmp == 1) {
      switch (vnmdispModeEnv->game_mode) {
      case 1:
        if ((vnmdispPauseItem == 0) || (vnmdispPauseItem == 1) ||
            (vnmdispPauseItem == 4)) {
          vnmdispPauseSelect.state = 0;
        } else {
          vnmdispPauseSelect.state = 4;
        }
        break;
      default:
        if ((vnmdispPauseItem == 0) || (vnmdispPauseItem == 1) ||
            (vnmdispPauseItem == 5)) {
          vnmdispPauseSelect.state = 0;
        } else {
          vnmdispPauseSelect.state = 4;
        }
        break;
      }
      vnmdispPauseSelect.cnt = 0;
    } else {
      vnmdispPauseSelect.cnt += 1;
    }
    break;
  case 6:
    info.start = 64.0f;
    info.length = 80.0f + (30.0f * (f32)vnmdispPauseItem);
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 0;
    info.num = 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispPauseSelectPos[1],
                          vnmdispPauseSelect.cnt);
    if (tmp == 1) {
      vnmdispPauseSelect.state = 3;
      vnmdispPauseSelect.cnt = 0;
    } else {
      vnmdispPauseSelect.cnt += 1;
    }
    break;
  case 7:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.num = 1;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, &vnmdispPauseSelectPos[0],
                          vnmdispPauseSelect.cnt);
    if (tmp == 1) {
      vnmdispPauseSelect.state = 0;
      vnmdispPauseSelect.cnt = 0;
      vnmdispBackGround.state = 3;
      vnmdispBackGround.cnt = 0;
    } else {
      vnmdispPauseSelect.cnt += 1;
    }
    break;
  }
}

static void nmdispCalcDiv() {
  // f32 tmp;
  // s16 info.skip;
  // s8 info.num;
  // s8 info.lag;
  // s8 info.vel;
  // s8 info.dir;
  // s16 info.frame;
  // f32 info.length;
  // f32 info.start;

  signed int i; // r16
  // Size: 0x10, DWARF: 0x135A42

  // {
  //     float start; // Offset: 0x0, DWARF: 0x135A5E
  //     float length; // Offset: 0x4, DWARF: 0x135A80
  //     signed short frame; // Offset: 0x8, DWARF: 0x135AA3
  //     char dir; // Offset: 0xA, DWARF: 0x135AC5
  //     char vel; // Offset: 0xB, DWARF: 0x135AE5
  //     char lag; // Offset: 0xC, DWARF: 0x135B05
  //     char num; // Offset: 0xD, DWARF: 0x135B25
  //     signed short skip; // Offset: 0xE, DWARF: 0x135B45
  Info info; // 0x20(r29)
  float tmp; // 0x3C(r29)

  if (vnmdispDivSide == 0) {
    // if (vsppScrWidth < 0) {
    //     var_v1 = (vsppScrWidth + 1) >> 1;
    // }
    tmp = 320.0f * (vspDispEnv.div / (float)(vsppScrWidth / 2));
    if (tmp != vnmdispScrDiv) {
      info.start = vnmdispScrDiv;
      info.length = 32.0f;
      info.frame = 5;
      if (tmp > vnmdispScrDiv) {
        info.dir = 0;
      } else {
        info.dir = 1;
      }
      info.vel = 1;
      info.lag = 0;
      info.num = 1;
      info.skip = 0;
      for (i = 0; i < 5; i++) {
        vnmdispLineImage[i].state = 3;
        vnmdispLineImage[i].cnt = 5 - i;
        nmdispCalcSlide(&info, &vnmdispLineImagePos[i], i);
      }
      vnmdispScrDiv = tmp;
      nmactPlayPush();
    }
    vnmdispScrCenter[0] = (vnmdispScrDiv / 2.0f);
    vnmdispScrCenter[1] = (vnmdispScrDiv + ((640.0f - vnmdispScrDiv) / 2.0f));
    return;
  }
  tmp = 224.0f * (vspDispEnv.div / (float)(vsppScrHeight / 2));
  if (tmp != vnmdispScrDiv) {
    info.start = vnmdispScrDiv;
    info.length = 22.0f;
    info.frame = 5;
    if (tmp > vnmdispScrDiv) {
      info.dir = 0;
    } else {
      info.dir = 1;
    }
    info.vel = 1;
    info.lag = 0;
    info.num = 1;
    info.skip = 0;
    for (i = 0; i < 5; i++) {
      vnmdispLineImage[i].state = 3;
      vnmdispLineImage[i].cnt = 5 - i;
      nmdispCalcSlide(&info, &vnmdispLineImagePos[i], i);
    }
    vnmdispScrDiv = tmp;
    nmactPlayPush();
  }
  vnmdispScrBottom[0] = vnmdispScrDiv;
}

static void nmdispFlowMatch(void) {
  switch (vnmdispMode) {
  case 0:
    switch (vspDispEnv.mode) {
    case 1:
      vnmdispMode = 1;
      vnmdispIntr.state = 1;
      vnmdispIntr.cnt = 0;
      return;
    case 2:
      vnmdispMode = 2;
      switch (vnmdispModeEnv->match_rule) {
      case 3:
        vnmdispHorseAccept = 0;
        vnmdispHorseFlow = 1;
        vnmdispHorseEnter.state = 1;
        vnmdispHorseEnter.cnt = 0;
        vnmdispBackGround.state = 1;
        vnmdispBackGround.cnt = 0;
        nmdispInitOperate();
        vnmdispOpeAccept = 0;
        break;
      }
      break;
    case 4:
      vnmdispMode = 4;
      vnmdispResultFlow = 4;
      vnmdispReplay.state = 1;
      vnmdispReplay.cnt = 0;
      return;
    case 5:
      vnmdispMode = 5;
      vnmdispResultFlow = 4;
      vnmdispReplay.state = 1;
      vnmdispReplay.cnt = 0;
      return;
    }
    break;
  case 1:
    if (vspDispEnv.mode == 2) {
      vnmdispMode = 2;
      switch (vnmdispModeEnv->match_rule) {
      case 3:
        vnmdispHorseAccept = 0;
        vnmdispHorseFlow = 1;
        vnmdispHorseEnter.state = 1;
        vnmdispHorseEnter.cnt = 0;
        vnmdispBackGround.state = 1;
        vnmdispBackGround.cnt = 0;
        nmdispInitOperate();
        vnmdispOpeAccept = 0;
        break;
      }
    }
    nmdispOpeIntrMatch();
    return;
  case 2:
    if (vspDispEnv.mode == 3) {
      vnmdispMode = 3;
    }
    nmdispFlowSelectBgm();
    switch (vnmdispModeEnv->match_rule) {
    case 3:
      nmdispOpeHorse();
      break;
    }
    nmdispOpePauseMatch();
    return;
  case 3:
    if (vgmsysPadPausePid < 0) {
      nmdispFlowResultMatch();
      return;
    }
    break;
  case 4:
    if (vgmsysPadPausePid < 0) {
      if (vnmdispResultFlow == 5) {
        vnmdispMode = 6;
      }
      nmdispOpeReplayMatch();
      return;
    }
    break;
  case 5:
    if (vgmsysPadPausePid < 0) {
      if (vnmdispResultFlow == 5) {
        vnmdispMode = 6;
      }
      nmdispOpeDemo();
    }
    break;
  }
}

static void nmdispFlowSoftCount(void) {
  signed int i;          // r16
  signed int *round;     // 0x94(r29)
  signed int *game_soft; // r30
  unsigned int *course;  // r22
  unsigned int *board;   // r18
  signed int *rem_point; // r19
  unsigned int *movie;   // r17
  signed int *ending;    // 0x98(r29)
  // Size: 0x1C, DWARF: 0x133AA2
  CharacterParam *param;  // r23
  signed int char_no;     // 0x9C(r29)
  signed int total_soft;  // r20
  signed int total_param; // r21

  round = &vnmdispSecret->tour_round;
  movie = &vnmdispOption->movie;
  ending = &vspenvGame->ending;
  if (vnmdispCharEnv->no < 0xC) {
    game_soft = &vnmdispSecret->character[vnmdispCharEnv->no].soft[0];
    course = &vnmdispSecret->character[vnmdispCharEnv->no].course;
    board = &vnmdispSecret->character[vnmdispCharEnv->no].board;
    rem_point = &vnmdispSecret->character[vnmdispCharEnv->no].rem_point;
    param = &vnmdispSecret->character[vnmdispCharEnv->no].parameter;
    char_no = vnmdispCharEnv->no;
  } else {
    game_soft = &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                     .character.soft[0];
    course = &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                  .character.course;
    board = &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                 .character.board;
    rem_point = &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                     .character.rem_point;
    param = &vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC]
                 .character.parameter;
    char_no =
        vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC].trick_type;
  }
  total_param = param->ollie + param->spin + param->speed + param->landing +
                param->balance + param->stance;
  switch (vnmdispSoftCount.state) {
  case 1:
    if (game_soft[vnmdispCrsEnv->no] < (vnmdispSoftNum + vnmdispSoftAdd)) {
      game_soft[vnmdispCrsEnv->no] += 1;
      vnmdispSoftCount.state = 2;
      vnmdispSoftCount.cnt = 0;
    } else {
      vnmdispSoftCount.state = 0;
      vnmdispSoftCount.cnt = 0;
      vnmdispSoftNum = 0;
      vnmdispSoftAdd = 0;
      vnmdispLevelFlow = 1;
      vnmdispLevelSearch += 1;
    }
    break;
  case 2:
    if (vnmdispSoftCount.cnt == 0x14) {
      vnmdispSoftCount.state = 3;
      vnmdispSoftCount.cnt = 0;
    } else {
      vnmdispSoftCount.cnt += 1;
    }
    break;
  case 3:
    total_soft = 0;
    for (i = 0; i < 8; i++) {
      total_soft += game_soft[i];
    }
    i = vnmdispCareerSearch;
    for (; i < 0x22; i++) {
      if (total_soft == vnmtblCareerItem[i][0]) {
        vnmdispCareerItem.type = vnmtblCareerItem[i][1];
        switch (vnmdispCareerItem.type) {
        case 0:
          if ((*course & (1 << vnmtblCareerItem[i][2])) == 0) {
            vnmdispCareerItem.num = 2;
            vnmdispCareerItem.value[0] = vnmtblCareerItem[i][2];
            vnmdispCareerItem.value[1] = 0xFF;
            *round |= 1 << vnmdispCareerItem.value[0];
            *course |= 1 << vnmdispCareerItem.value[0];
          } else {
            vnmdispCareerItem.num = -1;
          }
          break;
        case 1:
          if ((*board & (1 << vnmtblCareerItem[i][2])) == 0) {
            vnmdispCareerItem.num = 2;
            vnmdispCareerItem.value[0] = vnmtblCareerItem[i][2];
            vnmdispCareerItem.value[1] = 0xFF;
            *board |= 1 << vnmdispCareerItem.value[0];
          } else {
            vnmdispCareerItem.num = -1;
          }
          break;
        case 2:
          if (vnmtblCareerItem[i][2] >= 0xF) {
            if (vnmdispCharEnv->no < 0xA) {
              vnmdispCareerItem.num = -1;
            } else if (total_param < 0x32) {
              vnmdispCareerItem.num = 2;
              vnmdispCareerItem.value[0] = vnmtblCareerItem[i][2];
              vnmdispCareerItem.value[1] = 0xFF;
              *rem_point += 2;
            } else {
              vnmdispCareerItem.num = -1;
            }
          } else if (vnmdispCharEnv->no < 0xA) {
            if (total_param < 0x2C) {
              vnmdispCareerItem.num = 2;
              vnmdispCareerItem.value[0] = vnmtblCareerItem[i][2];
              vnmdispCareerItem.value[1] = 0xFF;
              *rem_point += 2;
            } else {
              vnmdispCareerItem.num = -1;
            }
          } else if (total_param < 0x32) {
            vnmdispCareerItem.num = 2;
            vnmdispCareerItem.value[0] = vnmtblCareerItem[i][2];
            vnmdispCareerItem.value[1] = 0xFF;
            *rem_point += 2;
          } else {
            vnmdispCareerItem.num = -1;
          }
          break;
        case 3:
          if ((*board & (1 << vnmtblCareerItem[i][2])) == 0) {
            vnmdispCareerItem.num = 2;
            vnmdispCareerItem.value[0] = vnmtblCareerItem[i][2];
            vnmdispCareerItem.value[1] = 0xFF;
            *board |= 1 << vnmdispCareerItem.value[0];
          } else {
            vnmdispCareerItem.num = -1;
          }
          break;
        case 4:
          if (vnmtblCareerItem[i][2] == 0) {
            if (vnmdispCharEnv->no < 0xA) {
              if ((*movie & (1 << vnmdispCharEnv->no)) == 0) {
                vnmdispCareerItem.num = 2;
                vnmdispCareerItem.value[0] = vnmdispCharEnv->no;
                vnmdispCareerItem.value[1] = 0xFF;
                *movie |= 1 << vnmdispCharEnv->no;
              } else {
                vnmdispCareerItem.num = -1;
              }
            } else if (vnmdispCharEnv->no < 0xC) {
              if ((*movie & (1 << vnmdispCharEnv->no)) == 0) {
                vnmdispCareerItem.num = 2;
                vnmdispCareerItem.value[0] = vnmdispCharEnv->no;
                vnmdispCareerItem.value[1] = 0xFF;
                *movie |= 1 << vnmdispCharEnv->no;
              } else {
                vnmdispCareerItem.num = -1;
              }
            } else if ((*movie & 0x1000) == 0) {
              vnmdispCareerItem.num = 2;
              vnmdispCareerItem.value[0] = 0xC;
              vnmdispCareerItem.value[1] = 0xFF;
              *movie |= 0x1000;
            } else {
              vnmdispCareerItem.num = -1;
            }
          } else if (vnmdispCharEnv->no < 0xA) {
            if ((*movie & 0x2000) == 0) {
              vnmdispCareerItem.num = 2;
              vnmdispCareerItem.value[0] = 0xD;
              *movie |= 0x2000;
            } else {
              vnmdispCareerItem.num = -1;
            }
          } else {
            vnmdispCareerItem.num = -1;
          }
          break;
        case 5:
          if (vnmdispCharEnv->no < 0xA) {
            if (vnmdispSecret->character[10].secret == 0) {
              vnmdispCareerItem.value[0] = 0xA;
              vnmdispSecret->character[10].secret = 1;
              vnmdispCareerItem.num = 2;
              vnmdispCareerItem.value[1] = 0xFF;
            } else {
              vnmdispCareerItem.num = -1;
            }
          } else if (vnmdispCharEnv->no < 0xC) {
            vnmdispCareerItem.num = -1;
          } else if (vnmdispSecret->character[11].secret == 0) {
            vnmdispCareerItem.value[0] = 0xB;
            vnmdispSecret->character[11].secret = 1;
            vnmdispCareerItem.num = 2;
            vnmdispCareerItem.value[1] = 0xFF;
          } else {
            vnmdispCareerItem.num = -1;
          }
          break;
        case 6:
          if (vnmdispSecret->first_clear == 0) {
            vnmdispSecret->first_clear = 1;
            vnmdispCareerItem.num = 0;
          } else {
            vnmdispCareerItem.num = 2;
            vnmdispCareerItem.value[1] = 0xFF;
            if (vnmdispOption->enable.kids == 0) {
              vnmdispOption->enable.kids = 1;
              vnmdispCareerItem.value[0] = 0;
            } else if (vnmdispOption->enable.always_sp == 0) {
              vnmdispOption->enable.always_sp = 1;
              vnmdispCareerItem.value[0] = 1;
            } else if (vnmdispOption->enable.perfect_b == 0) {
              vnmdispOption->enable.perfect_b = 1;
              vnmdispCareerItem.value[0] = 2;
            } else if (vnmdispOption->enable.super_spin == 0) {
              vnmdispOption->enable.super_spin = 1;
              vnmdispCareerItem.value[0] = 3;
            } else if (vnmdispOption->enable.half_g == 0) {
              vnmdispOption->enable.half_g = 1;
              vnmdispCareerItem.value[0] = 4;
            } else if (vnmdispOption->enable.fast_motion == 0) {
              vnmdispOption->enable.fast_motion = 1;
              vnmdispCareerItem.value[0] = 5;
            } else if (vnmdispOption->enable.super_speed == 0) {
              vnmdispCareerItem.value[0] = 6;
              vnmdispOption->enable.super_speed = 1;
            } else if (vnmdispOption->enable.big_head == 0) {
              vnmdispOption->enable.big_head = 1;
              vnmdispCareerItem.value[0] = 7;
            } else if (vnmdispOption->enable.metallic == 0) {
              vnmdispOption->enable.metallic = 1;
              vnmdispCareerItem.value[0] = 8;
            } else if (vnmdispOption->enable.mirror == 0) {
              vnmdispOption->enable.mirror = 1;
              vnmdispCareerItem.value[0] = 9;
            } else {
              vnmdispCareerItem.num = 0;
              vnmdispCareerItem.value[0] = 0;
            }
          }
          *ending = 1;
          break;
        default:
          vnmdispCareerItem.num = 0;
          break;
        }
        if (vnmdispCareerItem.num >= 0) {
          if (vnmdispCareerItem.num == 0) {
            vnmdispSoftCount.state = 1;
            vnmdispSoftCount.cnt = 0;
            break;
          } else if (vnmdispCareerItem.num > 0) {
            vnmdispLevelFlow = 4;
            vnmdispLevelCareer.state = 1;
            vnmdispLevelCareer.cnt = 0;
            break;
          }
        }
      } else if (total_soft < vnmtblCareerItem[i][0]) {
        vnmdispSoftCount.state = 1;
        vnmdispSoftCount.cnt = 0;
        break;
      }
      vnmdispCareerSearch += 1;
    }
    if (vnmdispCareerSearch == 0x22) {
      vnmdispSoftCount.state = 1;
      vnmdispSoftCount.cnt = 0;
    }
    break;
  }
}

static void nmdispOpePauseCareer() {
  Volume *volume; // r16

  volume = &vnmdispOption->volume;
  if (vnmdispOpeAccept == 1) {
    switch (vnmdispPauseFlow) {
    case 0:
      if (vgmsysPadAllowPause != 0) {
        if (vgmsysPadPausePid >= 0) {
          vnmdispPauseFlow = 1;
          vnmdispPause.state = 1;
          vnmdispPause.cnt = 0;
          vnmdispBackGround.state = 1;
          vnmdispBackGround.cnt = 0;
          vnmdispPauseMenu.state = 1;
          vnmdispPauseMenu.cnt = 0;
          vnmdispMenuItem.state = 0;
          vnmdispMenuItem.cnt = 0;
          vnmdispPauseSelect.state = 1;
          vnmdispPauseSelect.cnt = 0;
          ulpadSetAnaRef(1);
          vnmdispOpeAccept = 0;
          nmvcPlayButton(4);
        }
      }
      break;
    case 1:
      if (vgmsysPadPausePid >= 0) {
        if ((vgmsysPad[vgmsysPadPausePid]->trg & 0x10) ||
            (vgmsysPad[vgmsysPadPausePid]->trg & 0x800)) {
          vnmdispPauseFlow = 0;
          vnmdispPause.state = 3;
          vnmdispPause.cnt = 0;
          vnmdispPauseMenu.state = 3;
          vnmdispPauseMenu.cnt = 0;
          vnmdispMenuItem.state = 0;
          vnmdispMenuItem.cnt = 0;
          vnmdispPauseSelect.state = 2;
          vnmdispPauseSelect.cnt = 0;
          ulpadSetAnaRef(0);
          vnmdispOpe.state = 3;
          vnmdispOpe.cnt = 0;
          vnmdispOpeAccept = 0;
          vnmdispPauseCancel = 1;
          nmvcPlayButton(2);
        } else if (vgmsysPad[vgmsysPadPausePid]->trg & 0x40) {
          switch (vnmdispPauseItem) {
          case 0:
            vnmdispPauseFlow = 0;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 1:
            vnmdispPauseFlow = 2;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispPauseRetry.state = 1;
            vnmdispPauseRetry.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            nmsndRestart(0xA);
            break;
          case 2:
            vnmdispPauseFlow = 3;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispPauseSoundItem = 0;
            vnmdispVolume.se = volume->se;
            vnmdispVolume.bgm = volume->bgm;
            nmdispInitSound();
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 3:
            vnmdispPauseFlow = 4;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 4:
            vnmdispPauseFlow = 5;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 5:
            vnmdispPauseFlow = 7;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            vnmdispInvalid = 1;
            break;
          case 6:
            vnmdispPauseFlow = 8;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          }
          nmvcPlayButton(0);
        } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x1000) {
          if (vnmdispPauseItem > 0) {
            vnmdispPauseItem -= 1;
          } else {
            vnmdispPauseItem = 5;
          }
          vnmdispMenuItem.state = 1;
          vnmdispMenuItem.cnt = 0;
          nmvcPlayCursor(1);
        } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x4000) {
          if (vnmdispPauseItem < 5) {
            vnmdispPauseItem += 1;
          } else {
            vnmdispPauseItem = 0;
          }
          vnmdispMenuItem.state = 1;
          vnmdispMenuItem.cnt = 0;
          nmvcPlayCursor(1);
        }
      }
      break;
    case 3:
      nmdispOpeSoundLevels();
      break;
    case 4:
      nmdispOpeTrickList();
      break;
    case 5:
      nmdispOpeLevelGoalList();
      break;
    case 8:
      nmdispOpeDebug();
      break;
    }
  }
}

static void nmdispOpePauseFreeride() {
  Volume *volume; // r16

  volume = &vnmdispOption->volume;
  if (vnmdispOpeAccept == 1) {
    switch (vnmdispPauseFlow) {
    case 0:
      if (vgmsysPadAllowPause != 0) {
        if (vgmsysPadPausePid >= 0) {
          vnmdispPauseFlow = 1;
          vnmdispPause.state = 1;
          vnmdispPause.cnt = 0;
          vnmdispBackGround.state = 1;
          vnmdispBackGround.cnt = 0;
          vnmdispPauseMenu.state = 1;
          vnmdispPauseMenu.cnt = 0;
          vnmdispMenuItem.state = 0;
          vnmdispMenuItem.cnt = 0;
          vnmdispPauseSelect.state = 1;
          vnmdispPauseSelect.cnt = 0;
          ulpadSetAnaRef(1);
          vnmdispOpeAccept = 0;
          nmvcPlayButton(0);
        }
      }
      break;
    case 1:
      if (vgmsysPadPausePid >= 0) {
        if ((vgmsysPad[vgmsysPadPausePid]->trg & 0x10) ||
            (vgmsysPad[vgmsysPadPausePid]->trg & 0x800)) {
          vnmdispPauseFlow = 0;
          vnmdispPause.state = 3;
          vnmdispPause.cnt = 0;
          vnmdispPauseMenu.state = 3;
          vnmdispPauseMenu.cnt = 0;
          vnmdispMenuItem.state = 0;
          vnmdispMenuItem.cnt = 0;
          vnmdispPauseSelect.state = 2;
          vnmdispPauseSelect.cnt = 0;
          ulpadSetAnaRef(0);
          vnmdispOpe.state = 3;
          vnmdispOpe.cnt = 0;
          vnmdispOpeAccept = 0;
          vnmdispPauseCancel = 1;
          nmvcPlayButton(2);
        } else if (vgmsysPad[vgmsysPadPausePid]->trg & 0x40) {
          switch (vnmdispPauseItem) {
          case 0:
            vnmdispPauseFlow = 0;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 1:
            vnmdispPauseFlow = 2;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispPauseRetry.state = 1;
            vnmdispPauseRetry.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            nmsndRestart(0xA);
            break;
          case 2:
            vnmdispPauseFlow = 3;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispPauseSoundItem = 0;
            vnmdispVolume.se = volume->se;
            vnmdispVolume.bgm = volume->bgm;
            nmdispInitSound();
            if (vnmdispOption->tutorial == 1) {
              if (vnmdispPauseTutorial.state == 1) {
                vnmdispPauseTutorial.cnt = 0x14 - vnmdispPauseTutorial.cnt;
              } else {
                vnmdispPauseTutorial.cnt = 0;
              }
              vnmdispPauseTutorial.state = 3;
              if (vnmdispTutoMes.state == 1) {
                vnmdispTutoMes.cnt = 0x14 - vnmdispTutoMes.cnt;
              } else {
                vnmdispTutoMes.cnt = 0;
              }
              vnmdispTutoMes.state = 3;
            }
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 3:
            vnmdispPauseFlow = 4;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            if (vnmdispOption->tutorial == 1) {
              if (vnmdispPauseTutorial.state == 1) {
                vnmdispPauseTutorial.cnt = 0x14 - vnmdispPauseTutorial.cnt;
              } else {
                vnmdispPauseTutorial.cnt = 0;
              }
              vnmdispPauseTutorial.state = 3;
              if (vnmdispTutoMes.state == 1) {
                vnmdispTutoMes.cnt = 0x14 - vnmdispTutoMes.cnt;
              } else {
                vnmdispTutoMes.cnt = 0;
              }
              vnmdispTutoMes.state = 3;
            }
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 4:
            break;
          case 5:
            vnmdispPauseFlow = 7;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 6:
            vnmdispPauseFlow = 8;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          }
          if (vnmdispPauseItem != 4) {
            nmvcPlayButton(0);
          }
        } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x1000) {
          if (vnmdispPauseItem > 0) {
            vnmdispPauseItem -= 1;
          } else {
            vnmdispPauseItem = 5;
          }
          vnmdispMenuItem.state = 1;
          vnmdispMenuItem.cnt = 0;
          nmvcPlayCursor(1);
        } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x4000) {
          if (vnmdispPauseItem < 5) {
            vnmdispPauseItem += 1;
          } else {
            vnmdispPauseItem = 0;
          }
          vnmdispMenuItem.state = 1;
          vnmdispMenuItem.cnt = 0;
          nmvcPlayCursor(1);
        } else if ((vgmsysPad[vgmsysPadPausePid]->trg & 0x8000) ||
                   (vgmsysPad[vgmsysPadPausePid]->trg & 0x2000)) {
          if (vnmdispPauseItem == 4) {
            vnmdispOption->tutorial ^= 1;
            if (vnmdispOption->tutorial == 1) {
              if (vnmdispPauseTutorial.state == 3) {
                vnmdispPauseTutorial.cnt = 0x14 - vnmdispPauseTutorial.cnt;
              } else {
                vnmdispPauseTutorial.cnt = 0;
              }
              vnmdispPauseTutorial.state = 1;
              if (vnmdispTutoMes.state == 3) {
                vnmdispTutoMes.cnt = 0x14 - vnmdispTutoMes.cnt;
              } else {
                vnmdispTutoMes.cnt = 0;
              }
              vnmdispTutoMes.state = 1;
            } else {
              if (vnmdispPauseTutorial.state == 1) {
                vnmdispPauseTutorial.cnt = 0x14 - vnmdispPauseTutorial.cnt;
              } else {
                vnmdispPauseTutorial.cnt = 0;
              }
              vnmdispPauseTutorial.state = 3;
              if (vnmdispTutoMes.state == 1) {
                vnmdispTutoMes.cnt = 0x14 - vnmdispTutoMes.cnt;
              } else {
                vnmdispTutoMes.cnt = 0;
              }
              vnmdispTutoMes.state = 3;
            }
            nmvcPlayCursor(1);
          }
        } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x4) {
          if (vnmdispPauseItem == 4) {
            vnmdispTutoMesNum = (vnmdispTutoMesNum + 1) % 25;
          }
        }
      }
      break;
    case 3:
      nmdispOpeSoundLevels();
      break;
    case 4:
      nmdispOpeTrickList();
      break;
    case 8:
      nmdispOpeDebug();
      break;
    }
  }
}

static void nmdispOpePauseMatch() {
  Volume *volume; // r16

  volume = &vnmdispOption->volume;
  if (vnmdispOpeAccept == 1) {
    switch (vnmdispPauseFlow) {
    case 0:
      if (vgmsysPadAllowPause != 0) {
        if (vgmsysPadPausePid >= 0) {
          vnmdispPauseFlow = 1;
          vnmdispPause.state = 1;
          vnmdispPause.cnt = 0;
          vnmdispBackGround.state = 1;
          vnmdispBackGround.cnt = 0;
          vnmdispPauseMenu.state = 1;
          vnmdispPauseMenu.cnt = 0;
          vnmdispMenuItem.state = 0;
          vnmdispMenuItem.cnt = 0;
          vnmdispPauseSelect.state = 1;
          vnmdispPauseSelect.cnt = 0;
          ulpadSetAnaRef(1);
          vnmdispOpeAccept = 0;
          nmvcPlayButton(4);
        }
      }
      break;
    case 1:
      if (vgmsysPadPausePid >= 0) {
        if ((vgmsysPad[vgmsysPadPausePid]->trg & 0x10) ||
            (vgmsysPad[vgmsysPadPausePid]->trg & 0x800)) {
          vnmdispPauseFlow = 0;
          vnmdispPause.state = 3;
          vnmdispPause.cnt = 0;
          vnmdispPauseMenu.state = 3;
          vnmdispPauseMenu.cnt = 0;
          vnmdispMenuItem.state = 0;
          vnmdispMenuItem.cnt = 0;
          vnmdispPauseSelect.state = 2;
          vnmdispPauseSelect.cnt = 0;
          ulpadSetAnaRef(0);
          vnmdispOpe.state = 3;
          vnmdispOpe.cnt = 0;
          vnmdispOpeAccept = 0;
          vnmdispPauseCancel = 1;
          nmvcPlayButton(2);
        } else if (vgmsysPad[vgmsysPadPausePid]->trg & 0x40) {
          switch (vnmdispPauseItem) {
          case 0:
            vnmdispPauseFlow = 0;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 1:
            vnmdispPauseFlow = 2;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispPauseRetry.state = 1;
            vnmdispPauseRetry.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            nmsndRestart(0xA);
            break;
          case 2:
            vnmdispPauseFlow = 3;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispPauseSoundItem = 0;
            vnmdispVolume.se = volume->se;
            vnmdispVolume.bgm = volume->bgm;
            nmdispInitSound();
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 3:
            vnmdispPauseFlow = 4;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          case 4:
            vnmdispPauseFlow = 7;
            vnmdispPause.state = 3;
            vnmdispPause.cnt = 0;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            ulpadSetAnaRef(0);
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            vnmdispInvalid = 1;
            break;
          case 5:
            vnmdispPauseFlow = 8;
            vnmdispPauseMenu.state = 3;
            vnmdispPauseMenu.cnt = 0;
            vnmdispMenuItem.state = 0;
            vnmdispMenuItem.cnt = 0;
            vnmdispPauseSelect.state = 5;
            vnmdispPauseSelect.cnt = 0;
            vnmdispOpe.state = 3;
            vnmdispOpe.cnt = 0;
            vnmdispOpeAccept = 0;
            break;
          }
          nmvcPlayButton(0);
        } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x1000) {
          if (vnmdispPauseItem > 0) {
            vnmdispPauseItem -= 1;
          } else {
            vnmdispPauseItem = 4;
          }
          vnmdispMenuItem.state = 1;
          vnmdispMenuItem.cnt = 0;
          nmvcPlayCursor(1);
        } else if (vgmsysPad[vgmsysPadPausePid]->rep & 0x4000) {
          if (vnmdispPauseItem < 4) {
            vnmdispPauseItem += 1;
          } else {
            vnmdispPauseItem = 0;
          }
          vnmdispMenuItem.state = 1;
          vnmdispMenuItem.cnt = 0;
          nmvcPlayCursor(1);
        }
      }
      break;
    case 3:
      nmdispOpeSoundLevels();
      break;
    case 4:
      nmdispOpeTrickList();
      break;
    case 8:
      nmdispOpeDebug();
      break;
    }
  }
}

void nmdispInputHorseResult(signed int next) {
  signed int i; // r16

  vnmdispHorseFlow = 3;
  vnmdispHorseMes.state = 1;
  vnmdispHorseMes.cnt = 0;
  if (vnmdispHorseSet == 1) {
    if (next == 1) {
      vnmdispHorseMesType = 4;
    } else {
      vnmdispHorseMesType = 5;
      vnmdispHorseGet[vspModeData.horse_pid]++;
    }
  } else if (next == 1) {
    vnmdispHorseMesType = 2;
  } else {
    vnmdispHorseMesType = 3;
  }
  vnmdispHorsePts[vspModeData.horse_pid] =
      vspDispEnvChar[vspModeData.horse_pid].points.total;
  for (i = 0; i < 4; i++) {
    vnmdispHorseMesPos[i] = -640.0f;
  }
  vnmdispBackGround.state = 1;
  vnmdispBackGround.cnt = 0;
  nmdispInitOperate();
  vnmdispOpeAccept = 0;
  vnmdispHorseAccept = 0;
}

static void nmdispTrickNameTrans(VgmsysGifPkt *packet, signed int id,
                                 signed int mode) {
  signed int i;              // r17
  signed int j;              // r18
  float tmp;                 // 0x954(r29)
  char str_tmp[128];         // 0x60(r29)
  float str_len;             // 0x958(r29)
  float font_pos[4];         // 0xE0(r29)
  signed int font_col[4][4]; // 0xF0(r29)
  float font_size[4];        // 0x130(r29)
  // Size: 0x810, DWARF: 0x132C06
  CombInfo info;     // 0x140(r29)
  List *list;        // r19
  float rate;        // 0x95C(r29)
  signed int que_no; // r16
  signed int cnt;    // r20

  list = vnmdispTrickNameList[id];
  nmtrickGetInfo(id, &info);
  nmdispInitFont();
  cnt = vnmdispTrickName[id].cnt;
  switch (mode) {
  case 1:
    if (cnt < 5) {
      rate = (1.5f * (f32)vnmdispTrickName[id].cnt) / 5.0f;
    } else {
      rate = 1.5 - ((0.5f * (f32)(cnt - 5)) / 5.0f);
    }
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f;
    } else {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f;
    }
    font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] = 0x80;
    break;
  case 2:
    rate = 1.0f + ((0.5f * (f32)cnt) / 20.0f);
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    } else {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    }
    font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] =
        0x80 - ((cnt * 128) / 20);
    break;
  case 3:
    rate = 1.0f - ((f32)cnt / 20.0f);
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    } else {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    }
    font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] = 0x80;
    break;
  default:
    rate = 1.0f;
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f;
      font_size[1] = 16.0f;
    } else {
      font_size[0] = 16.0f;
      font_size[1] = 16.0f;
    }
    font_col[0][3] = font_col[1][3] = font_col[2][3] = font_col[3][3] = 0x80;
    break;
  }
  nmfontSetFSize(font_size[0], font_size[1]);
  font_pos[1] = (vnmdispScrBottom[id] - 48.0f) -
                (((f32)vnmdispTrickNameLine[id] * font_size[1]) +
                 ((f32)(vnmdispTrickNameLine[id] - 1) * (font_size[1] / 4.0f)));
  i = 0;
  while (1) {
    if (i == 3) {
      break;
    }
    if (list[i].word[0].id == 0) {
      break;
    }
    font_pos[0] = vnmdispScrCenter[id] - ((rate * list[i].length) / 2.0f);
    str_len = 0.0f;
    tmp = 0.0f;
    j = 0;
    while (1) {
      if (j == 0x10) {
        break;
      }
      if (list[i].word[j].id == 0) {
        break;
      }
      if (list[i].word[j].id == 6) {
        break;
      }
      if (j > 0) {
        ulstdSprintf(str_tmp, " ");
        tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
        font_pos[0] = font_pos[0] + tmp;
      }
      switch (list[i].word[j].id) {
      case 1:
        ulstdSprintf(str_tmp, "%s",
                     vnmtblTrickAcce[*vnmdispLang][list[i].word[j].value - 1]);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
        switch (list[i].word[j].value) {
        case 1:
          font_col[0][0] = 0x40;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x40;
          font_col[1][0] = 0x40;
          font_col[1][1] = 0x80;
          font_col[1][2] = 0x40;
          break;
        case 2:
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x40;
          font_col[0][2] = 0x40;
          font_col[1][0] = 0x80;
          font_col[1][1] = 0x40;
          font_col[1][2] = 0x40;
          break;
        default:
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          font_col[1][0] = 0x80;
          font_col[1][1] = 0x80;
          font_col[1][2] = 0x80;
          break;
        }
        font_col[2][0] = 0x80;
        font_col[2][1] = 0x80;
        font_col[2][2] = 0x80;
        font_col[3][0] = 0x80;
        font_col[3][1] = 0x80;
        font_col[3][2] = 0x80;
        nmfontSetCol(&font_col[0][0]);
        nmfontGPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      case 2:
        ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmdispLang][2]);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
        font_col[0][0] = 0x60;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x80;
        font_col[1][0] = 0x60;
        font_col[1][1] = 0x40;
        font_col[1][2] = 0x80;
        font_col[2][0] = 0x80;
        font_col[2][1] = 0x80;
        font_col[2][2] = 0x80;
        font_col[3][0] = 0x80;
        font_col[3][1] = 0x80;
        font_col[3][2] = 0x80;
        nmfontSetCol(&font_col[0][0]);
        nmfontGPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      case 3:
        ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmdispLang][3]);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      case 4:
        que_no = list[i].word[j].value;
        if (info.que[que_no].jump >= 0) {
          ulstdSprintf(str_tmp, "%s", vsptblTrickName[info.que[que_no].jump]);
          tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
          if (info.que[que_no].fakie == 1) {
            if (info.que[que_no].col.land == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              case 2:
                font_col[0][0] = 0x40;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x40;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][1] = font_col[1][1] =
                    (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x60;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x60;
                font_col[1][2] = 0x40;
                break;
              }
            } else if (info.que[que_no].col.land == 2) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              case 2:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x60;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x60;
                font_col[1][2] = 0x40;
                break;
              }
            } else if (info.que[que_no].col.flight == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][1] = font_col[1][1] =
                    (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][2] = font_col[1][2] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                break;
              case 2:
                font_col[0][0] = 0x60;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x60;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x80;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x60;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x60;
                font_col[1][2] = 0x40;
                break;
              }
            } else {
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x60;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x60;
              font_col[1][2] = 0x40;
            }
          } else {
            if (info.que[que_no].col.land == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][1] = font_col[1][1] = 0x80;
                font_col[0][2] = font_col[1][2] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                break;
              case 2:
                font_col[0][0] = 0x40;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x40;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][1] = font_col[1][1] = 0x80;
                font_col[0][2] = font_col[1][2] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x80;
                break;
              }
            } else if (info.que[que_no].col.land == 2) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][2] = font_col[1][2] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                break;
              case 2:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x80;
                break;
              }
            } else if (info.que[que_no].col.flight == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][1] = font_col[1][1] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][2] = font_col[1][2] = 0x80;
                break;
              case 2:
                font_col[0][0] = 0x60;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x60;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x80;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] = 0x80;
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x80;
                break;
              }
            } else {
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x80;
            }
          }
          font_col[2][0] = 0x80;
          font_col[2][1] = 0x80;
          font_col[2][2] = 0x80;
          font_col[3][0] = 0x80;
          font_col[3][1] = 0x80;
          font_col[3][2] = 0x80;
          nmfontSetCol(&font_col[0][0]);
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          if ((info.que[que_no].spin.value > 0) ||
              (info.que[que_no].type != 0)) {
            ulstdSprintf(str_tmp, " + ");
            tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
            nmfontFPrintF(packet, str_tmp, font_pos);
            font_pos[0] = font_pos[0] + tmp;
            if (info.que[que_no].spin.value > 0) {
              if (info.que[que_no].spin.rewind == 1) {
                ulstdSprintf(str_tmp, "%d %s",
                             info.que[que_no].spin.value * 180,
                             vnmtblTrickAcce[*vnmdispLang][4]);
              } else if ((info.que[que_no].spin.cab == 1) &&
                         (info.que[que_no].spin.value > 1)) {
                ulstdSprintf(str_tmp, "%s %d", vnmtblTrickAcce[*vnmdispLang][6],
                             info.que[que_no].spin.value * 180);
              } else {
                ulstdSprintf(str_tmp, "%d", info.que[que_no].spin.value * 180);
              }
              tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
              if (info.que[que_no].fakie == 1) {
                if (info.que[que_no].col.land == 1) {
                  switch (info.que[que_no].col.state) {
                  case 1:
                    font_col[0][0] = font_col[1][0] =
                        (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                    font_col[0][1] = font_col[1][1] =
                        (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                    font_col[0][2] = font_col[1][2] = 0x40;
                    break;
                  case 2:
                    font_col[0][0] = 0x40;
                    font_col[0][1] = 0x80;
                    font_col[0][2] = 0x40;
                    font_col[1][0] = 0x40;
                    font_col[1][1] = 0x80;
                    font_col[1][2] = 0x40;
                    break;
                  case 3:
                    font_col[0][0] = font_col[1][0] =
                        (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                    font_col[0][1] = font_col[1][1] =
                        (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                    font_col[0][2] = font_col[1][2] = 0x40;
                    break;
                  default:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x60;
                    font_col[0][2] = 0x40;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x60;
                    font_col[1][2] = 0x40;
                    break;
                  }
                } else if (info.que[que_no].col.land == 2) {
                  switch (info.que[que_no].col.state) {
                  case 1:
                    font_col[0][0] = font_col[1][0] = 0x80;
                    font_col[0][1] = font_col[1][1] =
                        (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
                    font_col[0][2] = font_col[1][2] = 0x40;
                    break;
                  case 2:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x40;
                    font_col[0][2] = 0x40;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x40;
                    font_col[1][2] = 0x40;
                    break;
                  case 3:
                    font_col[0][0] = font_col[1][0] = 0x80;
                    font_col[0][1] = font_col[1][1] =
                        (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
                    font_col[0][2] = font_col[1][2] = 0x40;
                    break;
                  default:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x60;
                    font_col[0][2] = 0x40;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x60;
                    font_col[1][2] = 0x40;
                    break;
                  }
                } else if (info.que[que_no].col.flight == 1) {
                  switch (info.que[que_no].col.state) {
                  case 1:
                    font_col[0][0] = font_col[1][0] =
                        (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                    font_col[0][1] = font_col[1][1] =
                        (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
                    font_col[0][2] = font_col[1][2] =
                        (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                    break;
                  case 2:
                    font_col[0][0] = 0x60;
                    font_col[0][1] = 0x40;
                    font_col[0][2] = 0x80;
                    font_col[1][0] = 0x60;
                    font_col[1][1] = 0x40;
                    font_col[1][2] = 0x80;
                    break;
                  case 3:
                    font_col[0][0] = font_col[1][0] =
                        (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                    font_col[0][1] = font_col[1][1] =
                        (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
                    font_col[0][2] = font_col[1][2] =
                        (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                    break;
                  default:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x60;
                    font_col[0][2] = 0x40;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x60;
                    font_col[1][2] = 0x40;
                    break;
                  }
                } else {
                  font_col[0][0] = 0x80;
                  font_col[0][1] = 0x60;
                  font_col[0][2] = 0x40;
                  font_col[1][0] = 0x80;
                  font_col[1][1] = 0x60;
                  font_col[1][2] = 0x40;
                }
              } else {
                if (info.que[que_no].col.land == 1) {
                  switch (info.que[que_no].col.state) {
                  case 1:
                    font_col[0][0] = font_col[1][0] =
                        (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                    font_col[0][1] = font_col[1][1] = 0x80;
                    font_col[0][2] = font_col[1][2] =
                        (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                    break;
                  case 2:
                    font_col[0][0] = 0x40;
                    font_col[0][1] = 0x80;
                    font_col[0][2] = 0x40;
                    font_col[1][0] = 0x40;
                    font_col[1][1] = 0x80;
                    font_col[1][2] = 0x40;
                    break;
                  case 3:
                    font_col[0][0] = font_col[1][0] =
                        (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                    font_col[0][1] = font_col[1][1] = 0x80;
                    font_col[0][2] = font_col[1][2] =
                        (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                    break;
                  default:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x80;
                    font_col[0][2] = 0x80;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x80;
                    font_col[1][2] = 0x80;
                    break;
                  }
                } else if (info.que[que_no].col.land == 2) {
                  switch (info.que[que_no].col.state) {
                  case 1:
                    font_col[0][0] = font_col[1][0] = 0x80;
                    font_col[0][1] = font_col[1][1] =
                        (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                    font_col[0][2] = font_col[1][2] =
                        (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                    break;
                  case 2:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x40;
                    font_col[0][2] = 0x40;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x40;
                    font_col[1][2] = 0x40;
                    break;
                  case 3:
                    font_col[0][0] = font_col[1][0] = 0x80;
                    font_col[0][1] = font_col[1][1] =
                        (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                    font_col[0][2] = font_col[1][2] =
                        (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                    break;
                  default:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x80;
                    font_col[0][2] = 0x80;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x80;
                    font_col[1][2] = 0x80;
                    break;
                  }
                } else if (info.que[que_no].col.flight == 1) {
                  switch (info.que[que_no].col.state) {
                  case 1:
                    font_col[0][0] = font_col[1][0] =
                        (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                    font_col[0][1] = font_col[1][1] =
                        (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                    font_col[0][2] = font_col[1][2] = 0x80;
                    break;
                  case 2:
                    font_col[0][0] = 0x60;
                    font_col[0][1] = 0x40;
                    font_col[0][2] = 0x80;
                    font_col[1][0] = 0x60;
                    font_col[1][1] = 0x40;
                    font_col[1][2] = 0x80;
                    break;
                  case 3:
                    font_col[0][0] = font_col[1][0] =
                        (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                    font_col[0][1] = font_col[1][1] =
                        (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                    font_col[0][2] = font_col[1][2] = 0x80;
                    break;
                  default:
                    font_col[0][0] = 0x80;
                    font_col[0][1] = 0x80;
                    font_col[0][2] = 0x80;
                    font_col[1][0] = 0x80;
                    font_col[1][1] = 0x80;
                    font_col[1][2] = 0x80;
                    break;
                  }
                } else {
                  font_col[0][0] = 0x80;
                  font_col[0][1] = 0x80;
                  font_col[0][2] = 0x80;
                  font_col[1][0] = 0x80;
                  font_col[1][1] = 0x80;
                  font_col[1][2] = 0x80;
                }
              }
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              nmfontSetCol(&font_col[0][0]);
              nmfontGPrintF(packet, str_tmp, font_pos);
              font_pos[0] = font_pos[0] + tmp;
              if (info.que[que_no].type != 0) {
                ulstdSprintf(str_tmp, " ");
                tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
                font_pos[0] = font_pos[0] + tmp;
              }
            }
          }
        }
        if (info.que[que_no].late == 1) {
          ulstdSprintf(str_tmp, "%s ", vnmtblTrickAcce[*vnmdispLang][5]);
          tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
          if (info.que[que_no].col.land == 1) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[0][1] = font_col[1][1] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
              font_col[2][2] = font_col[3][2] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
              break;
            case 2:
              font_col[0][0] = 0x40;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x40;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[0][1] = font_col[1][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[2][2] = font_col[3][2] =
                  (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
              break;
            default:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x60;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x60;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            }
          } else if (info.que[que_no].col.land == 2) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] = 0x80;
              font_col[0][1] = font_col[1][1] =
                  (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
              font_col[2][2] = font_col[3][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              break;
            case 2:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] = 0x80;
              font_col[0][1] = font_col[1][1] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[2][2] = font_col[3][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              break;
            default:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x60;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x60;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            }
          } else if (info.que[que_no].col.flight == 1) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[0][1] = font_col[1][1] =
                  (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[0][2] = font_col[1][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
              font_col[2][2] = font_col[3][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              break;
            case 2:
              font_col[0][0] = 0x60;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x60;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x80;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
              font_col[0][1] = font_col[1][1] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
              font_col[0][2] = font_col[1][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[2][2] = font_col[3][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              break;
            default:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x60;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x60;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x60;
              font_col[2][2] = 0x40;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x60;
              font_col[3][2] = 0x40;
              break;
            }
          } else {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x60;
            font_col[0][2] = 0x40;
            font_col[1][0] = 0x80;
            font_col[1][1] = 0x60;
            font_col[1][2] = 0x40;
            font_col[2][0] = 0x80;
            font_col[2][1] = 0x60;
            font_col[2][2] = 0x40;
            font_col[3][0] = 0x80;
            font_col[3][1] = 0x60;
            font_col[3][2] = 0x40;
          }
          nmfontSetCol(&font_col[0][0]);
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
        }
        switch (info.que[que_no].type) {
        case 0:
          break;
        case 7:
          ulstdSprintf(str_tmp, "%s",
                       vsptblGapList[vnmdispCrsEnv->no][info.que[que_no].num]);
          tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
          if (info.que[que_no].col.land == 1) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] = 0x40;
              font_col[0][1] = font_col[1][1] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[0][2] = font_col[1][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][0] = font_col[3][0] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][1] = font_col[3][1] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][2] = font_col[3][2] = 0x80;
              break;
            case 2:
              font_col[0][0] = 0x40;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x40;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] = 0x40;
              font_col[0][1] = font_col[1][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[0][2] = font_col[1][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][0] = font_col[3][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][1] = font_col[3][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][2] = font_col[3][2] = 0x80;
              break;
            default:
              font_col[0][0] = 0x40;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x40;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x80;
              font_col[2][0] = 0x40;
              font_col[2][1] = 0x40;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x40;
              font_col[3][1] = 0x40;
              font_col[3][2] = 0x80;
              break;
            }
          } else if (info.que[que_no].col.land == 2) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[0][1] = font_col[1][1] = 0x40;
              font_col[0][2] = font_col[1][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][0] = font_col[3][0] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][1] = font_col[3][1] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][2] = font_col[3][2] = 0x80;
              break;
            case 2:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[0][1] = font_col[1][1] = 0x40;
              font_col[0][2] = font_col[1][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][0] = font_col[3][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][1] = font_col[3][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][2] = font_col[3][2] = 0x80;
              break;
            default:
              font_col[0][0] = 0x40;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x40;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x80;
              font_col[2][0] = 0x40;
              font_col[2][1] = 0x40;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x40;
              font_col[3][1] = 0x40;
              font_col[3][2] = 0x80;
              break;
            }
          } else if (info.que[que_no].col.flight == 1) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
              font_col[0][1] = font_col[1][1] = 0x40;
              font_col[0][2] = font_col[1][2] = 0x80;
              font_col[2][0] = font_col[3][0] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][1] = font_col[3][1] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][2] = font_col[3][2] = 0x80;
              break;
            case 2:
              font_col[0][0] = 0x60;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x60;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x80;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] =
                  (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[0][1] = font_col[1][1] = 0x40;
              font_col[0][2] = font_col[1][2] = 0x80;
              font_col[2][0] = font_col[3][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][1] = font_col[3][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[2][2] = font_col[3][2] = 0x80;
              break;
            default:
              font_col[0][0] = 0x40;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x40;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x80;
              font_col[2][0] = 0x40;
              font_col[2][1] = 0x40;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x40;
              font_col[3][1] = 0x40;
              font_col[3][2] = 0x80;
              break;
            }
          } else {
            font_col[0][0] = 0x40;
            font_col[0][1] = 0x40;
            font_col[0][2] = 0x80;
            font_col[1][0] = 0x40;
            font_col[1][1] = 0x40;
            font_col[1][2] = 0x80;
            font_col[2][0] = 0x40;
            font_col[2][1] = 0x40;
            font_col[2][2] = 0x80;
            font_col[3][0] = 0x40;
            font_col[3][1] = 0x40;
            font_col[3][2] = 0x80;
          }
          nmfontSetCol(&font_col[0][0]);
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          break;
        case 8:
          if (info.que[que_no].disaster == 1) {
            ulstdSprintf(str_tmp, "%s %s", vsptblTrickName[133],
                         vsptblTrickName[info.que[que_no].num]);
          } else {
            ulstdSprintf(str_tmp, "%s", vsptblTrickName[info.que[que_no].num]);
          }
          tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
          if (info.que[que_no].col.land == 1) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[0][1] = font_col[1][1] = 0x80;
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] = 0x80;
              font_col[2][2] = font_col[3][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              break;
            case 2:
              font_col[0][0] = 0x40;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x40;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[0][1] = font_col[1][1] = 0x80;
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] = 0x80;
              font_col[2][2] = font_col[3][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              break;
            default:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x40;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x40;
              break;
            }
          } else if (info.que[que_no].col.land == 2) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] = 0x80;
              font_col[0][1] = font_col[1][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] = 0x80;
              font_col[2][2] = font_col[3][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              break;
            case 2:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] = 0x80;
              font_col[0][1] = font_col[1][1] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[0][2] = font_col[1][2] = 0x40;
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] = 0x80;
              font_col[2][2] = font_col[3][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              break;
            default:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x40;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x40;
              break;
            }
          } else if (info.que[que_no].col.flight == 1) {
            switch (info.que[que_no].col.state) {
            case 1:
              font_col[0][0] = font_col[1][0] =
                  (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
              font_col[0][1] = font_col[1][1] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              font_col[0][2] = font_col[1][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] = 0x80;
              font_col[2][2] = font_col[3][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              break;
            case 2:
              font_col[0][0] = 0x60;
              font_col[0][1] = 0x40;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x60;
              font_col[1][1] = 0x40;
              font_col[1][2] = 0x80;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x80;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x80;
              break;
            case 3:
              font_col[0][0] = font_col[1][0] =
                  (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
              font_col[0][1] = font_col[1][1] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
              font_col[0][2] = font_col[1][2] =
                  (((info.que[que_no].col.cnt * 64) / 20) + 0x80);
              font_col[2][0] = font_col[3][0] = 0x80;
              font_col[2][1] = font_col[3][1] = 0x80;
              font_col[2][2] = font_col[3][2] =
                  (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
              break;
            default:
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x40;
              font_col[2][0] = 0x80;
              font_col[2][1] = 0x80;
              font_col[2][2] = 0x40;
              font_col[3][0] = 0x80;
              font_col[3][1] = 0x80;
              font_col[3][2] = 0x40;
              break;
            }
          } else {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x40;
            font_col[1][0] = 0x80;
            font_col[1][1] = 0x80;
            font_col[1][2] = 0x40;
            font_col[2][0] = 0x80;
            font_col[2][1] = 0x80;
            font_col[2][2] = 0x40;
            font_col[3][0] = 0x80;
            font_col[3][1] = 0x80;
            font_col[3][2] = 0x40;
          }
          nmfontSetCol(&font_col[0][0]);
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          break;
        default:
          if (info.que[que_no].disaster == 1) {
            ulstdSprintf(str_tmp, "%s %s", vsptblTrickName[133],
                         vsptblTrickName[info.que[que_no].num]);
          } else {
            ulstdSprintf(str_tmp, "%s", vsptblTrickName[info.que[que_no].num]);
          }
          tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
          if (info.que[que_no].fakie == 1) {
            if (info.que[que_no].col.land == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              case 2:
                font_col[0][0] = 0x40;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x40;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][1] = font_col[1][1] =
                    (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x60;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x60;
                font_col[1][2] = 0x40;
                break;
              }
            } else if (info.que[que_no].col.land == 2) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              case 2:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] = 0x40;
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x60;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x60;
                font_col[1][2] = 0x40;
                break;
              }
            } else if (info.que[que_no].col.flight == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][1] = font_col[1][1] =
                    (0x60 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][2] = font_col[1][2] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                break;
              case 2:
                font_col[0][0] = 0x60;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x60;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x80;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x60;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x60;
                font_col[1][2] = 0x40;
                break;
              }
            } else {
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x60;
              font_col[0][2] = 0x40;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x60;
              font_col[1][2] = 0x40;
            }
          } else {
            if (info.que[que_no].col.land == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][1] = font_col[1][1] = 0x80;
                font_col[0][2] = font_col[1][2] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                break;
              case 2:
                font_col[0][0] = 0x40;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x40;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][1] = font_col[1][1] = 0x80;
                font_col[0][2] = font_col[1][2] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x80;
                break;
              }
            } else if (info.que[que_no].col.land == 2) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][2] = font_col[1][2] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                break;
              case 2:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x40;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x40;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] = 0x80;
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x80;
                break;
              }
            } else if (info.que[que_no].col.flight == 1) {
              switch (info.que[que_no].col.state) {
              case 1:
                font_col[0][0] = font_col[1][0] =
                    (0x80 - ((info.que[que_no].col.cnt * 32) / 20));
                font_col[0][1] = font_col[1][1] =
                    (0x80 - ((info.que[que_no].col.cnt * 64) / 20));
                font_col[0][2] = font_col[1][2] = 0x80;
                break;
              case 2:
                font_col[0][0] = 0x60;
                font_col[0][1] = 0x40;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x60;
                font_col[1][1] = 0x40;
                font_col[1][2] = 0x80;
                break;
              case 3:
                font_col[0][0] = font_col[1][0] =
                    (((info.que[que_no].col.cnt * 32) / 20) + 0x60);
                font_col[0][1] = font_col[1][1] =
                    (((info.que[que_no].col.cnt * 64) / 20) + 0x40);
                font_col[0][2] = font_col[1][2] = 0x80;
                break;
              default:
                font_col[0][0] = 0x80;
                font_col[0][1] = 0x80;
                font_col[0][2] = 0x80;
                font_col[1][0] = 0x80;
                font_col[1][1] = 0x80;
                font_col[1][2] = 0x80;
                break;
              }
            } else {
              font_col[0][0] = 0x80;
              font_col[0][1] = 0x80;
              font_col[0][2] = 0x80;
              font_col[1][0] = 0x80;
              font_col[1][1] = 0x80;
              font_col[1][2] = 0x80;
            }
          }
          font_col[2][0] = 0x80;
          font_col[2][1] = 0x80;
          font_col[2][2] = 0x80;
          font_col[3][0] = 0x80;
          font_col[3][1] = 0x80;
          font_col[3][2] = 0x80;
          nmfontSetCol(&font_col[0][0]);
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          break;
        }
        if (j < 15) {
          if (list[i].word[j + 1].id == 0) {
            break;
          }
          if (list[i].word[j + 1].id == 6) {
            que_no = list[i + 1].word[0].value;
          } else {
            que_no = list[i].word[j + 1].value;
          }
          if (info.que[que_no].spin.rewind == 1) {
            ulstdSprintf(str_tmp, " -");
          } else {
            ulstdSprintf(str_tmp, " +");
          }
          tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
        } else {
          if (i + 1 == 3) {
            break;
          }
          if (list[i + 1].word[0].id == 0) {
            break;
          }
          que_no = list[i + 1].word[0].value;
          if (info.que[que_no].spin.rewind == 1) {
            ulstdSprintf(str_tmp, " -");
          } else {
            ulstdSprintf(str_tmp, " +");
          }
          tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
        }
        break;
      case 5:
        ulstdSprintf(str_tmp, "...");
        tmp = nmfontGetPackStrFLen(str_tmp, font_size[0], 0);
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      }
      j = j + 1;
    }
    i += 1;
    font_pos[1] = font_pos[1] + (1.25f * font_size[1]);
  }
}

static void nmdispTrickComb(VgmsysGifPkt *packet, Comb *comb) {
  signed int i;              // r17
  signed int j;              // r18
  float tmp;                 // 0x938(r29)
  char str_tmp[128];         // 0x50(r29)
  float str_len;             // 0x93C(r29)
  float font_pos[4];         // 0xD0(r29)
  signed int font_col[4][4]; // 0xE0(r29)
  List *list;                // r19
  CombInfo info;             // 0x120(r29)
  signed int que_no;         // r16

  list = vnmdispCombList;
  info = vspDispResult[0].comb_info;
  nmdispInitFont();
  nmfontSetFSize(18.0f, 18.0f);
  i = 0;
  while (1) {
    if (i == 6) {
      break;
    }
    if (list[i].word[0].id == 0) {
      break;
    }
    font_pos[0] = ((640.0f - list[i].length) / 2.0f) +
                  vnmdispStatisticsPos[comb->line + i];
    font_pos[1] = comb->ofs + (22.5f * (f32)i);
    str_len = 0.0f;
    tmp = 0.0f;
    j = 0;
    while (1) {
      if (j == 0x10) {
        break;
      }
      if (list[i].word[j].id == 0) {
        break;
      }
      if (list[i].word[j].id == 6) {
        break;
      }
      if (j > 0) {
        ulstdSprintf(str_tmp, " ");
        tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
        font_pos[0] = font_pos[0] + tmp;
      }
      switch (list[i].word[j].id) {
      case 1:
        ulstdSprintf(str_tmp, "%s",
                     vnmtblTrickAcce[*vnmdispLang][list[i].word[j].value - 1]);
        tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
        switch (list[i].word[j].value) {
        case 1:
          font_col[0][0] = 0x40;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x40;
          font_col[0][3] = 0x80;
          font_col[1][0] = 0x40;
          font_col[1][1] = 0x80;
          font_col[1][2] = 0x40;
          font_col[1][3] = 0x80;
          break;
        case 2:
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x40;
          font_col[0][2] = 0x40;
          font_col[0][3] = 0x80;
          font_col[1][0] = 0x80;
          font_col[1][1] = 0x40;
          font_col[1][2] = 0x40;
          font_col[1][3] = 0x80;
          break;
        default:
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          font_col[0][3] = 0x80;
          font_col[1][0] = 0x80;
          font_col[1][1] = 0x80;
          font_col[1][2] = 0x80;
          font_col[1][3] = 0x80;
          break;
        }
        font_col[2][0] = 0x80;
        font_col[2][1] = 0x80;
        font_col[2][2] = 0x80;
        font_col[2][3] = 0x80;
        font_col[3][0] = 0x80;
        font_col[3][1] = 0x80;
        font_col[3][2] = 0x80;
        font_col[3][3] = 0x80;
        nmfontSetCol(&font_col[0][0]);
        nmfontGPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      case 2:
        ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmdispLang][2]);
        tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
        font_col[0][0] = 0x60;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
        font_col[1][0] = 0x60;
        font_col[1][1] = 0x40;
        font_col[1][2] = 0x80;
        font_col[1][3] = 0x80;
        font_col[2][0] = 0x80;
        font_col[2][1] = 0x80;
        font_col[2][2] = 0x80;
        font_col[2][3] = 0x80;
        font_col[3][0] = 0x80;
        font_col[3][1] = 0x80;
        font_col[3][2] = 0x80;
        font_col[3][3] = 0x80;
        nmfontSetCol(&font_col[0][0]);
        nmfontGPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      case 3:
        ulstdSprintf(str_tmp, "%s", vnmtblTrickAcce[*vnmdispLang][3]);
        tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      case 4:
        que_no = list[i].word[j].value;
        if (info.que[que_no].jump >= 0) {
          ulstdSprintf(str_tmp, "%s", vsptblTrickName[info.que[que_no].jump]);
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          if (info.que[que_no].fakie == 1) {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x60;
            font_col[0][2] = 0x40;
            font_col[0][3] = 0x80;
            font_col[1][0] = 0x80;
            font_col[1][1] = 0x60;
            font_col[1][2] = 0x40;
            font_col[1][3] = 0x80;
            font_col[2][0] = 0x80;
            font_col[2][1] = 0x80;
            font_col[2][2] = 0x80;
            font_col[2][3] = 0x80;
            font_col[3][0] = 0x80;
            font_col[3][1] = 0x80;
            font_col[3][2] = 0x80;
            font_col[3][3] = 0x80;
            nmfontSetCol(&font_col[0][0]);
          } else {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
          }
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          if ((info.que[que_no].spin.value > 0) ||
              (info.que[que_no].type != 0)) {
            ulstdSprintf(str_tmp, " + ");
            tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
            nmfontFPrintF(packet, str_tmp, font_pos);
            font_pos[0] = font_pos[0] + tmp;
          }
        }
        if (info.que[que_no].spin.value > 0) {
          if (info.que[que_no].spin.rewind == 1) {
            ulstdSprintf(str_tmp, "%d %s", info.que[que_no].spin.value * 180,
                         vnmtblTrickAcce[*vnmdispLang][4]);
          } else if ((info.que[que_no].spin.cab == 1) &&
                     (info.que[que_no].spin.value > 1)) {
            ulstdSprintf(str_tmp, "%s %d", vnmtblTrickAcce[*vnmdispLang][6],
                         info.que[que_no].spin.value * 180);
          } else {
            ulstdSprintf(str_tmp, "%d", info.que[que_no].spin.value * 180);
          }
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          if (info.que[que_no].fakie == 1) {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x60;
            font_col[0][2] = 0x40;
            font_col[0][3] = 0x80;
            font_col[1][0] = 0x80;
            font_col[1][1] = 0x60;
            font_col[1][2] = 0x40;
            font_col[1][3] = 0x80;
            font_col[2][0] = 0x80;
            font_col[2][1] = 0x80;
            font_col[2][2] = 0x80;
            font_col[2][3] = 0x80;
            font_col[3][0] = 0x80;
            font_col[3][1] = 0x80;
            font_col[3][2] = 0x80;
            font_col[3][3] = 0x80;
            nmfontSetCol(&font_col[0][0]);
          } else {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
          }
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          if (info.que[que_no].type != 0) {
            ulstdSprintf(str_tmp, " ");
            tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
            font_pos[0] = font_pos[0] + tmp;
          }
        }
        if (info.que[que_no].late == 1) {
          ulstdSprintf(str_tmp, "%s ", vnmtblTrickAcce[*vnmdispLang][5]);
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x60;
          font_col[0][2] = 0x40;
          font_col[0][3] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
        }
        switch (info.que[que_no].type) {
        case 0:
          break;
        case 7:
          ulstdSprintf(str_tmp, "%s",
                       vsptblGapList[vnmdispCrsEnv->no][info.que[que_no].num]);
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          font_col[0][0] = 0x40;
          font_col[0][1] = 0x40;
          font_col[0][2] = 0x80;
          font_col[0][3] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          break;
        case 8:
          ulstdSprintf(str_tmp, "%s", vsptblTrickName[info.que[que_no].num]);
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x40;
          font_col[0][3] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          break;
        default:
          if (info.que[que_no].disaster == 1) {
            ulstdSprintf(str_tmp, "%s %s", vsptblTrickName[133],
                         vsptblTrickName[info.que[que_no].num]);
          } else {
            ulstdSprintf(str_tmp, "%s", vsptblTrickName[info.que[que_no].num]);
          }
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          if (info.que[que_no].fakie == 1) {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x60;
            font_col[0][2] = 0x40;
            font_col[0][3] = 0x80;
            font_col[1][0] = 0x80;
            font_col[1][1] = 0x60;
            font_col[1][2] = 0x40;
            font_col[1][3] = 0x80;
            font_col[2][0] = 0x80;
            font_col[2][1] = 0x80;
            font_col[2][2] = 0x80;
            font_col[2][3] = 0x80;
            font_col[3][0] = 0x80;
            font_col[3][1] = 0x80;
            font_col[3][2] = 0x80;
            font_col[3][3] = 0x80;
            nmfontSetCol(&font_col[0][0]);
          } else {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            font_col[0][3] = 0x80;
            nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                          font_col[0][3]);
          }
          nmfontGPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
          break;
        }
        if (j < 15) {
          if (list[i].word[j + 1].id == 0) {
            break;
          }
          if (list[i].word[j + 1].id == 6) {
            que_no = list[i + 1].word[0].value;
          } else {
            que_no = list[i].word[j + 1].value;
          }
          if (info.que[que_no].spin.rewind == 1) {
            ulstdSprintf(str_tmp, " -");
          } else {
            ulstdSprintf(str_tmp, " +");
          }
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          font_col[0][3] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
        } else {
          if (i + 1 == 6) {
            break;
          }
          if (list[i + 1].word[0].id == 0) {
            break;
          }
          que_no = list[i + 1].word[0].value;
          if (info.que[que_no].spin.rewind == 1) {
            ulstdSprintf(str_tmp, " -");
          } else {
            ulstdSprintf(str_tmp, " +");
          }
          tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x80;
          font_col[0][2] = 0x80;
          font_col[0][3] = 0x80;
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] = font_pos[0] + tmp;
        }
        break;
      case 5:
        ulstdSprintf(str_tmp, "...");
        tmp = nmfontGetPackStrFLen(str_tmp, 18.0f, 0);
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        font_pos[0] = font_pos[0] + tmp;
        break;
      }
      j += 1;
    }
    i += 1;
  }
}

void nmdispReplay(VgmsysGifPkt *packet) {

  float pos_tmp[4];  // 0x20(r29)
  char str_tmp[256]; // 0x30(r29)
  DispTex tex;       // 0x130(r29)

  Key key;                   // 0x1E0(r29)
  float font_pos[4];         // 0x220(r29)
  signed int font_col[4][4]; // 0x230(r29)
  char *word_tbl[3] = {
      "REPLAY",       // @3414
      "WIEDERHOLUNG", // @3415
      "VIDEO"         // @3416
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x27C(r29)
  pos_tmp[0] = 16.0f;
  pos_tmp[1] = 28.0f;
  nmdispInitFont();
  if (vnmdispReplay.state != 0) {
    tex.data = vnmdispTexData->tex + 0x2;
    tex.tex_size[0] = 0x80;
    tex.tex_size[1] = 0x40;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0x40;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 152.0f;
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0];
    tex.vertex[0][1] = pos_tmp[1];
    nmdrawFTex(packet, &tex);
    nmfontSetFSize(20.0f, 20.0f);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x60;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    font_pos[0] = pos_tmp[0];
    font_pos[1] = 4.0f + pos_tmp[1];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    key.pos[1] = 430.0f;
    key.data = vnmdispTexData->tex;
    key.language = *vnmdispLang;
    key.center = 1;
    key.cnt = 5;
    key.mode = 0;
    key.pos[0] = 320.0f;
    key.pos[1] = 430.0f;
    key.button = 2;
    key.message = 4;
    nmdrawKeyOperate(packet, &key);
  }
}

void nmdispReplayMatch(VgmsysGifPkt *packet) {
  float pos_tmp[4];          // 0x20(r29)
  char str_tmp[256];         // 0x30(r29)
  DispTex tex;               // 0x130(r29)
  Key key;                   // 0x1E0(r29)
  float font_pos[4];         // 0x220(r29)
  signed int font_col[4][4]; // 0x230(r29)
  char *word_tbl[3] = {
      "REPLAY",       // @3414
      "WIEDERHOLUNG", // @3415
      "VIDEO"         // @3416
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x27C(r29)
  pos_tmp[0] = 16.0f;
  pos_tmp[1] = 28.0f;
  nmdispInitFont();
  if (vnmdispReplay.state != 0) {
    tex.data = vnmdispTexData->tex + 0x2;
    tex.tex_size[0] = 0x80;
    tex.tex_size[1] = 0x40;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0x40;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 152.0f;
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0];
    tex.vertex[0][1] = pos_tmp[1];
    nmdrawFTex(packet, &tex);
    nmfontSetFSize(20.0f, 20.0f);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x60;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    font_pos[0] = pos_tmp[0];
    font_pos[1] = 4.0f + pos_tmp[1];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    key.data = vnmdispTexData->tex;
    key.language = *vnmdispLang;
    key.center = 1;
    key.cnt = 5;
    key.mode = 0;
    key.pos[0] = 320.0f;
    key.pos[1] = 430.0f;
    key.button = 2;
    key.message = 4;
    nmdrawKeyOperate(packet, &key);
  }
}

void nmdispDemo(VgmsysGifPkt *packet) {

  float pos_tmp[4];          // 0x20(r29)
  char str_tmp[256];         // 0x30(r29)
  DispTex tex;               // 0x130(r29)
  float font_pos[4];         // 0x1E0(r29)
  signed int font_col[4][4]; // 0x1F0(r29)
  char *word_tbl[3] = {
      "DEMO MODE",  // @3433
      "DEMO-MODUS", // @3434
      "MODE DEMO"   // @3435
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x23C(r29)
  pos_tmp[0] = 16.0f;
  pos_tmp[1] = 28.0f;
  nmdispInitFont();
  if (vnmdispReplay.state != 0) {
    tex.data = vnmdispTexData->tex + 0x2;
    tex.tex_size[0] = 0x80;
    tex.tex_size[1] = 0x40;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0x40;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 152.0f;
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0];
    tex.vertex[0][1] = pos_tmp[1];
    nmdrawFTex(packet, &tex);
    nmfontSetFSize(20.0f, 20.0f);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x60;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    font_pos[0] = pos_tmp[0];
    font_pos[1] = 4.0f + pos_tmp[1];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    tex.data = vnmdispTexData->tex + 0x7;
    tex.tex_size[0] = 0x100;
    tex.tex_size[1] = 0x80;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0;
    tex.col[0][0] = 0x80;
    tex.col[0][1] = 0x80;
    tex.col[0][2] = 0x80;
    tex.col[0][3] = 0x80;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 256.0f;
    tex.option.height = 128.0f;
    tex.vertex[0][0] = 640.0f - (tex.option.width + 16.0f);
    tex.vertex[0][1] = 448.0f - (tex.option.height + 8.0f);
    nmdrawFTex(packet, &tex);
  }
}

static void nmdispHorsePts(VgmsysGifPkt *packet) {
  sceVu0FVECTOR pos_tmp;  // 0x20(r29)
  char str_tmp[128];      // 0x30(r29)
  sceVu0FVECTOR font_pos; // 0xB0(r29)
  signed int font_col[4]; // 0xC0(r29)
  DispTex tex;            // 0xD0(r29)
  char *word_tbl[3] = {   // 0x180(r29)
                       "SCORE", "", ""};
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x18C(r29)

  pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
  pos_tmp[1] = 28.0f;
  nmdispInitFont();
  if (vnmdispHorseSet == 1) {
    tex.data = vnmdispTexData->tex + 0x2;
    tex.tex_size[0] = 0x80;
    tex.tex_size[1] = 0x40;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0x40;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 152.0f;
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0];
    tex.vertex[0][1] = pos_tmp[1];
    nmdrawFTex(packet, &tex);
    ulstdSprintf(&str_tmp, "%s %d %s", vnmtblCommon[*vnmdispLang][3],
                 (vspModeData.horse_pid ^ 1) + 1, word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
    font_pos[0] = pos_tmp[0];
    font_pos[1] = 4.0f + pos_tmp[1];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    ulstdSprintf(&str_tmp, "%s", *vnmtblCommon[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
    font_pos[0] = (pos_tmp[0] + tex.option.width) - ((2.0f * tmp) / 3.0f);
    font_pos[1] = 32.0f + pos_tmp[1];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(0);
    font_col[0] = 0x40;
    font_col[1] = 0x60;
    font_col[2] = 0x40;
    font_col[3] = 0x80;
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    ulstdSprintf(&str_tmp, "%d", vnmdispHorsePts[vspModeData.horse_pid ^ 1]);
    tmp = nmfontGetStrFLen(str_tmp, 22.0f);
    if (tmp > 132.0f) {
      nmfontSetFSize(18.0f, 24.0f);
      tmp = nmfontGetStrFLen(str_tmp, 18.0f);
    } else {
      nmfontSetFSize(22.0f, 24.0f);
    }
    font_pos[0] =
        /*(second half of f64) - (bitwise f32) (bitwise f64)*/ font_pos[0] -
        tmp;
    font_pos[1] -= 8.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  }
}

static void nmdispHorseEnter(VgmsysGifPkt *packet) {

  signed int i;              // r16
  char str_tmp[128];         // 0x30(r29)
  float font_pos[4];         // 0xB0(r29)
  signed int font_col[4][4]; // 0xC0(r29)
  Key key;                   // 0x100(r29)
  char *word_tbl[3] = {
      // 0x140(r29)
      "ENTER WORD",    // @2815
      "WORT EINGEBEN", // @2816
      "ENTRE UN MOT"   // @2817
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x14C(r29)

  nmdispInitFont();
  nmfontSetFSize(28.0f, 28.0f);
  if (vnmdispHorseEnter.state != 0) {
    nmfontSetPack(1);
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    ulstdSprintf(&str_tmp[0], "%s", word_tbl[*vnmdispLang]);
    tmp = nmfontGetPackStrFLen(str_tmp, 28.0f, 0);
    font_pos[0] = ((640.0f + vnmdispHorseEnterPos[0]) - tmp) / 2.0f;
    font_pos[1] = 96.0f;
    nmfontGPrintF(packet, &str_tmp[0], &font_pos[0]);
    nmfontSetPack(0);
    font_pos[0] = ((640.0f + vnmdispHorseEnterPos[1]) / 2.0f) - 140.0f;
    font_pos[1] = 210.0f;
    for (i = 0; i < 0xA; i++) {
      if (i == vnmdispHorseWordNum) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x60;
        font_col[0][2] = 0x40;
        switch (vnmdispHorseEnter.state) {
        case 2:
          if (vnmdispHorseEnter.cnt < 0x3CU) {
            font_col[0][3] = 0x80 - ((vnmdispHorseEnter.cnt << 7) / 60);
          } else {
            font_col[0][3] = ((vnmdispHorseEnter.cnt - 0x3C) << 7) / 60;
          }
          break;
        default:
          font_col[0][3] = 0x80;
          break;
        }
      } else {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      }
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      str_tmp[0] = vnmdispHorseWord[i];
      if (str_tmp[0] == 0x20) {
        str_tmp[0] = 0x5F;
      }
      str_tmp[1] = 0;
      nmfontFPrintF(packet, &str_tmp[0], &font_pos[0]);
      font_pos[0] += 28.0f;
    }
    if (vnmdispOpe.state != 0) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      switch (vnmdispOpe.state) { /* irregular */
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.pos[0] = 320.0f;
      key.button = 0;
      key.message = 0;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispStatisFreeride(VgmsysGifPkt *packet) {

  char str_tmp[128];         // 0x20(r29)
  float font_pos[4];         // 0xA0(r29)
  signed int font_col[4][4]; // 0xB0(r29)
  Key key;                   // 0xF0(r29)
  Point point;               // 0x130(r29)
  char *word_tbl[3][3] = {   // 0x1A0(r29)
                          {"TRICKS LANDED", "BEST COMBO", "TRICKS"},
                          {"GELANDETE TRICKS", "BESTE KOMBO", "TRICKS"},
                          {"TRICKS EFFECTUES", "MEILLEUR COMBO", "TRICKS"}};
  s32 *word_tbl_ptr = &word_tbl;
  Comb comb_info; // 0x1D0(r29)
  float tmp;      // 0x1D8(r29)
  float pos_tmp;  // 0x1DC(r29)

  pos_tmp = 104.0f;
  nmdispInitFont();
  if (vnmdispStatistics.state != 0) {
    nmfontSetType(1);
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(32.0f, 32.0f);
    ulstdSprintf(&str_tmp, "%s", vnmtblResultItem[*vnmdispLang][1]);
    tmp = nmfontGetPackStrFLen(str_tmp, 32.0f, 1);
    font_pos[0] = vnmdispStatisticsPos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = 16.0f;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetType(0);
    nmfontSetFSize(16.0f, 16.0f);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][0]);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[1];
    font_pos[1] = pos_tmp;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(0);
    ulstdSprintf(&str_tmp, "%d", vspDispResult[0].trick_landing);
    tmp = nmfontGetStrFLen(str_tmp, 16.0f);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[1]) - (80.0f + tmp);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][1]);
    tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[2];
    font_pos[1] += 24.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][2]);
    tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[2]) - (80.0f + tmp);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(0);
    ulstdSprintf(&str_tmp, "%d", vspDispResult[0].comb_num);
    tmp = nmfontGetStrFLen(str_tmp, 16.0f);
    font_pos[0] = font_pos[0] - tmp;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
    tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[3]) - (80.0f + tmp);
    font_pos[1] += 24.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    point.pos[0] = font_pos[0];
    point.pos[1] = font_pos[1];
    point.col[0][0] = font_col[0][0];
    point.col[0][1] = font_col[0][1];
    point.col[0][2] = font_col[0][2];
    point.col[0][3] = font_col[0][3];
    point.point = vspDispResult[0].comb_points;
    point.type = 0;
    point.size[0] = 0x10;
    point.size[1] = 0x10;
    point.flat = 1;
    point.base = 1;
    point.language = *vnmdispLang;
    nmdrawPoint(packet, &point);
    tmp = 130.5f;
    font_pos[1] += tmp / 2.0f + (128.0f / 2.0f);
    if (vnmdispCombLine > 0) {
      tmp = (22.5f * vnmdispCombLine) - 4.5f;
      comb_info.ofs = font_pos[1] - (tmp / 2.0f);
      comb_info.line = 4;
      nmdispTrickComb(packet, &comb_info);
    }
    nmdispCareerUp(packet);
    if (vnmdispOpe.state != 0) {
      key.pos[0] = 320.0f;
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.button = 0;
      key.message = 1;
      switch (vnmdispOpe.state) { /* irregular */
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.center = 1;
      key.language = *vnmdispLang;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispSoundLevels(VgmsysGifPkt *packet) {

  char str_tmp[256];      // 0x20(r29)
  float font_pos[4];      // 0x120(r29)
  signed int font_col[4]; // 0x130(r29)
  float font_size[4];     // 0x140(r29)
  DispBar bar;            // 0x150(r29)
  Allow allow;            // 0x1C0(r29)
  Key key;                // 0x1F0(r29)
  char *item_tbl[3][5] = {
      // 0x230(r29)
      {"SFX LEVEL", "MUSIC LEVEL", "SELECT TRACK", "SHUFFLE", "BACK"},
      {"SOUNDEFFEKTE", "MUSIK", "SONG W\x90HLEN", "SHUFFLE", "BACK"},
      {"EFFETS SONORES", "MUSIQUE", "CHOISIR LA PISTE", "SHUFFLE", "RETOUR"}};
  s32 *item_tbl_ptr = &item_tbl;
  float tmp;     // 0x278(r29)
  float pos_tmp; // 0x27C(r29)

  pos_tmp = 64.0f;
  nmdispInitFont();
  if (vnmdispPauseSound.state != 0) {
    if (vnmdispPauseSoundItem == 0) {
      font_size[0] = 20.0f;
      switch (vnmdispMenuItem.state) { /* irregular */
      case 1:
        font_size[1] = 20.0 * (1.0f + (0.2f * vnmdispMenuItem.cnt));
        break;
      case 2:
        font_size[1] = 20.0f * (1.4f - (0.2f * vnmdispMenuItem.cnt));
        break;
      default:
        font_size[1] = 20.0f;
        break;
      }
      font_col[0] = 0x80;
      font_col[1] = 0x60;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_size[0] = 20.0f;
      font_size[1] = 20.0f;
      font_col[0] = 0x80;
      font_col[1] = 0x80;
      font_col[2] = 0x80;
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetFSize(font_size[0], font_size[1]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", item_tbl[*vnmdispLang][0]);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    font_pos[0] = 96.0f + vnmdispPauseSoundPos[0];
    font_pos[1] = (80.0f + pos_tmp) - ((font_size[1] - 20.0f) / 2.0f);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    bar.pos[0] = 32.0f + (320.0f + vnmdispPauseSoundPos[0]);
    bar.pos[1] = 2.0f + (80.0f + pos_tmp);
    bar.col[0][0] = 0;
    bar.col[0][1] = 0;
    bar.col[0][2] = 0;
    bar.col[0][3] = 0x40;
    bar.col[1][0] = 0;
    bar.col[1][1] = 0;
    bar.col[1][2] = 0;
    bar.col[1][3] = 0x40;
    bar.col[2][0] = 0;
    bar.col[2][1] = 0;
    bar.col[2][2] = 0;
    bar.col[2][3] = 0x40;
    bar.col[3][0] = 0;
    bar.col[3][1] = 0;
    bar.col[3][2] = 0;
    bar.col[3][3] = 0x40;
    bar.option.width = 192.0f;
    bar.option.height = 16.0f;
    bar.type = 0;
    nmdrawBar(packet, &bar); //, &allow.pos[0]);
    bar.col[0][0] = 0xFF;
    bar.col[0][1] = 0xC0;
    bar.col[0][2] = 0;
    bar.col[0][3] = 0x80;
    bar.col[1][0] = 0xFF;
    bar.col[1][1] = 0xC0;
    bar.col[1][2] = 0;
    bar.col[1][3] = 0x80;
    bar.col[2][0] = 0xFF;
    bar.col[2][1] = 0xC0;
    bar.col[2][2] = 0;
    bar.col[2][3] = 0x80;
    bar.col[3][0] = 0xFF;
    bar.col[3][1] = 0xC0;
    bar.col[3][2] = 0;
    bar.col[3][3] = 0x80;
    bar.option.width = (192.0f * vnmdispVolume.se) / 255.0f;
    bar.type = 0;
    nmdrawBar(packet, &bar); // &allow.pos[0], (f32* )0xC0);
    if (vnmdispPauseSoundItem == 1) {
      font_size[0] = 20.0f;
      switch (vnmdispMenuItem.state) { /* switch 1; irregular */
      case 1:                          /* switch 1 */
        font_size[1] = 20.0f * (1.0f + (0.2f * vnmdispMenuItem.cnt));
        break;
      case 2: /* switch 1 */
        font_size[1] = 20.0f * (1.4f - (0.2f * vnmdispMenuItem.cnt));
        break;
      default: /* switch 1 */
        font_size[1] = 20.0f;
        break;
      }
      font_col[0] = 0x80;
      font_col[1] = 0x60;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_size[0] = 20.0f;
      font_size[1] = 20.0f;
      font_col[0] = 0x80;
      font_col[1] = 0x80;
      font_col[2] = 0x80;
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetFSize(font_size[0], font_size[1]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", item_tbl[*vnmdispLang][1]);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    font_pos[0] = 96.0f + vnmdispPauseSoundPos[1];
    font_pos[1] = (30.0f + (80.0f + pos_tmp)) - ((font_size[1] - 20.0f) / 2.0f);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    bar.pos[0] = 32.0f + (320.0f + vnmdispPauseSoundPos[1]);
    bar.pos[1] = 2.0f + (30.0f + (80.0f + pos_tmp));
    bar.col[0][0] = 0;
    bar.col[0][1] = 0;
    bar.col[0][2] = 0;
    bar.col[0][3] = 0x40;
    bar.col[1][0] = 0;
    bar.col[1][1] = 0;
    bar.col[1][2] = 0;
    bar.col[1][3] = 0x40;
    bar.col[2][0] = 0;
    bar.col[2][1] = 0;
    bar.col[2][2] = 0;
    bar.col[2][3] = 0x40;
    bar.col[3][0] = 0;
    bar.col[3][1] = 0;
    bar.col[3][2] = 0;
    bar.col[3][3] = 0x40;
    bar.option.width = 192.0f;
    bar.option.height = 16.0f;
    bar.type = 0;
    nmdrawBar(packet, &bar); //&allow.pos[0]);
    bar.col[0][0] = 0xFF;
    bar.col[0][1] = 0xC0;
    bar.col[0][2] = 0;
    bar.col[0][3] = 0x80;
    bar.col[1][0] = 0xFF;
    bar.col[1][1] = 0xC0;
    bar.col[1][2] = 0;
    bar.col[1][3] = 0x80;
    bar.col[2][0] = 0xFF;
    bar.col[2][1] = 0xC0;
    bar.col[2][2] = 0;
    bar.col[2][3] = 0x80;
    bar.col[3][0] = 0xFF;
    bar.col[3][1] = 0xC0;
    bar.col[3][2] = 0;
    bar.col[3][3] = 0x80;
    bar.option.width = (192.0f * vnmdispVolume.bgm) / 255.0f;
    nmdrawBar(packet, &bar); //&allow);
    if (vnmdispPauseSoundItem == 2) {
      font_size[0] = 20.0f;
      switch (vnmdispMenuItem.state) { /* switch 2; irregular */
      case 1:                          /* switch 2 */
        font_size[1] = 20.0f * (1.0f + (0.2f * vnmdispMenuItem.cnt));
        break;
      case 2: /* switch 2 */
        font_size[1] = 20.0f * (1.4f - (0.2f * vnmdispMenuItem.cnt));
        break;
      default: /* switch 2 */
        font_size[1] = 20.0f;
        break;
      }
      font_col[0] = 0x80;
      font_col[1] = 0x60;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_size[0] = 20.0f;
      font_size[1] = 20.0f;
      if (vnmdispSelectIntTbl >= 2) {
        font_col[0] = 0x80;
        font_col[1] = 0x80;
        font_col[2] = 0x80;
        font_col[3] = 0x80;
      } else {
        font_col[0] = 0x40;
        font_col[1] = 0x40;
        font_col[2] = 0x40;
        font_col[3] = 0x80;
      }
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetFSize(font_size[0], font_size[1]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", item_tbl[*vnmdispLang][2]);
    tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
    font_pos[0] = 96.0f + vnmdispPauseSoundPos[2];
    font_pos[1] = (90.0f + (80.0f + pos_tmp)) - ((font_size[1] - 20.0f) / 2.0f);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    if (vnmdispOption->bgm.disable != -1) {
      if (vnmdispSelectIntTbl >= 2) {
        font_col[0] = 0x80;
        font_col[1] = 0x80;
        font_col[2] = 0x80;
        font_col[3] = 0x80;
      } else {
        font_col[0] = 0x40;
        font_col[1] = 0x40;
        font_col[2] = 0x40;
        font_col[3] = 0x80;
      }
      nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
      nmfontSetPack(1);
      ulstdSprintf(&str_tmp, "%s",
                   vbgmtblMusic[vnmdispOption->bgm.table[vnmdispSelectInt]]);
      tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
      if (tmp > 480.0f) {
        nmfontSetFSize(14.0f, 20.0f);
      } else {
        nmfontSetFSize(20.0f, 20.0f);
      }
      font_pos[0] = 40.0f + (96.0f + vnmdispPauseSoundPos[3]);
      font_pos[1] = 20.0f + (90.0f + (80.0f + pos_tmp));
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      nmfontSetFSize(16.0f, 16.0f);
      ulstdSprintf(&str_tmp, "- %s -",
                   vbgmtblArtist[vnmdispOption->bgm.table[vnmdispSelectInt]]);
      tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
      font_pos[0] = (640.0f + vnmdispPauseSoundPos[3]) - (136.0f + tmp);
      font_pos[1] += 20.0f;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    }
    if (vnmdispAllow.state != 0) {
      allow.data = vnmdispTexData->tex + 1;
      if (vnmdispAllow.state == 1) {
        allow.abe = (vnmdispAllow.cnt << 7) / 40;
      } else {
        allow.abe = 0x80 - ((vnmdispAllow.cnt << 7) / 40);
      }
      allow.type = 2;
      allow.width = 20.0f;
      allow.height = 36.0f;
      allow.pos[0] = 96.0f + vnmdispPauseSoundPos[3];
      font_pos[1] = 8.0f + (20.0f + (90.0f + (80.0f + pos_tmp)));
      allow.pos[1] = (10.0f + font_pos[1]) - (allow.height / 2.0f);
      nmdrawAllow(packet, &allow);
      allow.type = 3;
      allow.pos[0] = (640.0f + vnmdispPauseSoundPos[3]) - (96.0f + allow.width);
      nmdrawAllow(packet, &allow);
    }
    if (vnmdispPauseSoundItem == 3) {
      font_size[0] = 20.0f;
      switch (vnmdispMenuItem.state) {
      case 1:
        font_size[1] = 20.0f * (1.0f + (0.2f * vnmdispMenuItem.cnt));
        break;
      case 2:
        font_size[1] = 20.0f * (1.4f - (0.2f * vnmdispMenuItem.cnt));
        break;
      default:
        font_size[1] = 20.0f;
        break;
      }
      font_col[0] = 0x80;
      font_col[1] = 0x60;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_size[0] = 20.0f;
      font_size[1] = 20.0f;
      font_col[0] = 0x80;
      font_col[1] = 0x80;
      font_col[2] = 0x80;
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetFSize(font_size[0], font_size[1]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", item_tbl[*vnmdispLang][3]);
    font_pos[0] = 96.0f + vnmdispPauseSoundPos[4];
    tmp = 20.0f + (150.0f + (80.0f + pos_tmp));
    font_pos[1] = tmp - ((font_size[1] - 20.0f) / 2.0f);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    ulstdSprintf(&str_tmp, "%s",
                 vnmtblPauseFlag[*vnmdispLang][vnmdispOption->bgm.random]);
    font_pos[0] = 192.0f + (96.0f + vnmdispPauseSoundPos[4]);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    if (vnmdispPauseSoundItem == 4) {
      font_size[0] = 20.0f;
      switch (vnmdispMenuItem.state) { /* switch 4; irregular */
      case 1:                          /* switch 4 */
        font_size[1] = 20.0f * (1.0f + (0.2f * vnmdispMenuItem.cnt));
        break;
      case 2: /* switch 4 */
        font_size[1] = 20.0f * (1.4f - (0.2f * vnmdispMenuItem.cnt));
        break;
      default: /* switch 4 */
        font_size[1] = 20.0f;
        break;
      }
      font_col[0] = 0x80;
      font_col[1] = 0x60;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_size[0] = 20.0f;
      font_size[1] = 20.0f;
      font_col[0] = 0x80;
      font_col[1] = 0x80;
      font_col[2] = 0x80;
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetFSize(font_size[0], font_size[1]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", item_tbl[*vnmdispLang][4]);
    font_pos[0] = 96.0f + vnmdispPauseSoundPos[5];
    font_pos[1] = (20.0f + (180.0f + (80.0f + pos_tmp))) -
                  ((font_size[1] - 20.0f) / 2.0f);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    if ((((vnmdispPauseSound.state) != 3) && (vnmdispOpe.state != 0)) ||
        ((vnmdispPauseSound.state == 3) && (vnmdispOpe.state == 3))) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      switch (vnmdispOpe.state) { /* switch 5; irregular */
      case 1:                     /* switch 5 */
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3: /* switch 5 */
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default: /* switch 5 */
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      if (vnmdispPauseSoundItem == 4) {
        key.pos[0] = 248.0f;
        key.button = 0;
        key.message = 0;
        nmdrawKeyOperate(packet, &key);
        key.pos[0] = 392.0f;
        key.button = 2;
        key.message = 4;
        nmdrawKeyOperate(packet, &key);
        return;
      }
      key.pos[0] = 320.0f;
      key.button = 2;
      key.message = 4;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispTrickNameFreeze(VgmsysGifPkt *packet, signed int id) {

  signed int j;       // r16
  signed int i;       // r17
  float font_size[4]; // 0x30(r29)
  Ice ice;            // 0x40(r29)
  float tmp;          // 0xB4(r29)
  char str_tmp[2];    // 0xB8(r29)
  float base_pos;     // 0xBC(r29)

  if (vnmdispDivMode == 0) {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  } else {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  }

  base_pos = (vnmdispScrBottom[id] - 48.0f) -
             ((vnmdispTrickNameLine[id] * font_size[1]) +
              ((vnmdispTrickNameLine[id] - 1) * (font_size[1] / 4.0f)));
  ice.data = vnmdispTexData->tex + 0x5;
  ice.width = font_size[0];
  ice.height = font_size[1];
  ice.col[0][0] = ice.col[1][0] = ice.col[2][0] = ice.col[3][0] = 0x80;
  ice.col[0][1] = ice.col[1][1] = ice.col[2][1] = ice.col[3][1] = 0x80;
  ice.col[0][2] = ice.col[1][2] = ice.col[2][2] = ice.col[3][2] = 0x80;
  ice.col[0][3] = ice.col[1][3] = (vnmdispTrickName[id].cnt << 7) / 60;
  ice.col[2][3] = ice.col[3][3] = 0x80;
  for (i = 0; i < (vnmdispTrickNameLine[id]); i++) {
    tmp = vnmdispTrickNameList[id][i].length;
    ice.pos[0] = vnmdispScrCenter[id] - (tmp / 2.0f);
    ice.pos[1] = base_pos;
    for (j = 0; j < vnmdispTrickNameInfo[id][i].num; j++) {
      str_tmp[0] = /*((j << 5) + ((i * 0x810) + */ vnmdispTrickNameInfo[id][i]
                       .word[j]
                       .str; //->unk15;
      str_tmp[1] = 0;
      nmdrawIceFont(packet, &str_tmp[0], &ice);
      tmp = nmfontGetPackStrFLen(&str_tmp[0], font_size[0], 0);
      ice.pos[0] = ice.pos[0] + tmp;
    }
    base_pos += 1.25f * font_size[1];
  }
}

static void nmdispWinLoseDraw(VgmsysGifPkt *packet) {

  signed int i;           // r16
  char str_tmp[128];      // 0x30(r29)
  float font_pos[4];      // 0xB0(r29)
  signed int font_col[4]; // 0xC0(r29)
  float font_size[4];     // 0xD0(r29)
  char *word_tbl[3][3] = {// 0xE0(r29)
                          {"YOU WIN!", "YOU LOSE", "DRAW"},
                          {"SIEGER!", "VERLIERER!", "UNENTSCH."},
                          {"TU AS GAGNE!", "TU AS PERDU", "EGALITE"}};
  s32 *word_tbl_ptr = &word_tbl;
  float tmp;  // 0x108(r29)
  float rate; // 0x10C(r29)

  nmdispInitFont();
  nmfontSetPack(1);
  if (vnmdispWin.state != 0) {
    font_col[0] = 0x80;
    font_col[1] = 0x80;
    font_col[2] = 0x80;
    font_col[3] = 0x80;
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    nmfontSetFSize(32.0f, 32.0f);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][0]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 32.0f, 0);
    if (vnmdispDivSide == 0) {
      if (vnmdispModeEnv->match_rule == 2) {
        font_pos[0] = (320.0f + vnmdispWinPos[0]) - (tmp / 2.0f);
        font_pos[1] = vnmdispWinPos[1];
      } else {
        font_pos[0] = (160.0f + vnmdispWinPos[0]) - (tmp / 2.0f);
        font_pos[1] = vnmdispWinPos[1];
      }
    } else {
      font_pos[0] = (320.0f + vnmdispWinPos[0]) - (tmp / 2.0f);
      font_pos[1] = vnmdispWinPos[1];
    }
    nmfontFPrintF(packet, &str_tmp, font_pos);
  }
  if (vnmdispLose.state != 0) {
    font_col[0] = 0x80;
    font_col[1] = 0x80;
    font_col[2] = 0x80;
    if (vnmdispLose.state == 1) {
      font_col[3] = (vnmdispLose.cnt << 7) / 120;
    } else {
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    font_size[0] = 32.0f;
    font_size[1] = 32.0f;
    nmfontSetFSize(font_size[0], font_size[1]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][1]);
    tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
    font_pos[0] = (160.0f + vnmdispLosePos[0]) - (tmp / 2.0f);
    font_pos[1] = vnmdispLosePos[1];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  }
  if (vnmdispDraw.state != 0) {
    font_col[0] = 0x80;
    font_col[1] = 0x80;
    font_col[2] = 0x80;
    font_col[3] = 0x80;
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    switch (vnmdispDraw.state) { /* irregular */
    case 1:
      rate = (2.0f * vnmdispDraw.cnt) / 30.0f;
      break;
    case 2:
      rate = 2.0f - (vnmdispDraw.cnt / 10.0f);
      break;
    default:
      rate = 1.0f;
      break;
    }
    font_size[0] = 32.0f * rate;
    font_size[1] = 32.0f;
    nmfontSetFSize(font_size[0], font_size[1]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][2]);
    tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
    for (i = 0; i < 2; i++) {
      if (vnmdispDivSide == 0) {
        font_pos[0] = (160.0f + (320.0f * i)) - (tmp / 2.0f);
        font_pos[1] = 149.33333f;
      } else {
        font_pos[0] = 320.0f - (tmp / 2.0f);
        font_pos[1] = 74.666664f + (224.0f * i);
      }
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    }
  }
}

static void nmdispRankHor(VgmsysGifPkt *packet, signed int id) {

  float pos_tmp[4];       // 0x10(r29)
  char str_tmp[256];      // 0x20(r29)
  float font_pos[4];      // 0x120(r29)
  signed int font_col[4]; // 0x130(r29)
  DispBar bar;            // 0x140(r29)
  float tmp;              // 0x1BC(r29)

  if (vnmdispDivSide == 1) {
    pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    pos_tmp[1] = vnmdispScrBottom[id] - 26.0f;
    nmdispInitFont();
    bar.option.width = 80.0f;
    bar.option.height = 12.0f;
    bar.pos[0] = pos_tmp[0];
    bar.pos[1] = pos_tmp[1];
    bar.col[0][0] = 0;
    bar.col[0][1] = 0;
    bar.col[0][2] = 0;
    bar.col[0][3] = 0x40;
    bar.col[1][0] = 0;
    bar.col[1][1] = 0;
    bar.col[1][2] = 0;
    bar.col[1][3] = 0x40;
    bar.col[2][0] = 0;
    bar.col[2][1] = 0;
    bar.col[2][2] = 0;
    bar.col[2][3] = 0x40;
    bar.col[3][0] = 0;
    bar.col[3][1] = 0;
    bar.col[3][2] = 0;
    bar.col[3][3] = 0x40;
    bar.type = 1;
    nmdrawBar(packet, &bar);
    if (vspDispEnvChar[id].rank == 0) {
      font_col[0] = 0x80;
      font_col[1] = 0x40;
      font_col[2] = 0x40;
      font_col[3] = 0x80;
    } else {
      font_col[0] = 0x40;
      font_col[1] = 0x40;
      font_col[2] = 0x80;
      font_col[3] = 0x80;
    }
    nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
    ulstdSprintf(&str_tmp, "%s",
                 vnmtblRank2[*vnmdispLang][vspDispEnvChar[id].rank]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
    ulstdSprintf(&str_tmp, "%d", vspDispEnvChar[0].rank + 1);
    tmp += nmfontGetStrFLen(&str_tmp, 28.0f);
    nmfontSetPack(0);
    nmfontSetFSize(28.0f, 28.0f);
    ulstdSprintf(&str_tmp, "%d", vspDispEnvChar[id].rank + 1);
    font_pos[0] = pos_tmp[0] + ((80.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp[1] - 18.0f;
    tmp = nmfontGetStrFLen(&str_tmp, 28.0f);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(1);
    nmfontSetFSize(16.0f, 16.0f);
    ulstdSprintf(&str_tmp, "%s",
                 vnmtblRank2[*vnmdispLang][vspDispEnvChar[id].rank]);
    font_pos[0] = font_pos[0] + tmp;
    font_pos[1] = pos_tmp[1] - 6.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  }
}

static void nmdispLevelMes(VgmsysGifPkt *packet) {
  signed int i;              // r16
  float tmp;                 // 0x158(r29)
  char str_tmp[128];         // 0x40(r29)
  float font_pos[4];         // 0xC0(r29)
  signed int font_col[1][4]; // 0xD0(r29)
  float font_size;           // 0x15C(r29)
  signed int min;            // r17
  signed int sec;            // r18
  // Size: 0x70, DWARF: 0x137FF4
  Point point; // 0xE0(r29)

  nmdispInitFont();
  for (i = 0; i < 8; i++) {
    if (vnmdispLevelMes[i].state != 0) {
      if (vnmdispLevelMesInfo[i].type == 0) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x60;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
      } else {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
      }
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      switch (vnmdispLevelMesInfo[i].num) {
      case 0:
      case 1:
      case 2:
        point.point =
            vsptblLevelGoalValue[vnmdispCrsEnv->no][vnmdispLevelMesInfo[i].num];
        point.type = 0;
        point.size[0] = 0x14;
        point.size[1] = 0x14;
        point.language = *vnmdispLang;
        tmp = nmdrawGetPointLen(&point);
        ulstdSprintf(
            str_tmp, "%s  %s",
            vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num],
            vnmtblCommon[*vnmdispLang][0]);
        tmp += nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          point.size[0] = font_size;
          tmp = nmdrawGetPointLen(&point);
          ulstdSprintf(
              str_tmp, "%s  %s",
              vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num],
              vnmtblCommon[*vnmdispLang][0]);
          tmp += nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 20.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = ((640.0f - tmp) / 2.0f) + vnmdispLevelMesPos[i];
        font_pos[1] = 88.0f + (32.0f * (f32)(i % 4));
        nmfontSetPack(1);
        ulstdSprintf(
            str_tmp, "%s ",
            vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num]);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        nmfontFPrintF(packet, str_tmp, font_pos);
        font_pos[0] += tmp;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point =
            vsptblLevelGoalValue[vnmdispCrsEnv->no][vnmdispLevelMesInfo[i].num];
        point.type = 0;
        point.size[0] = font_size;
        point.size[1] = 0x18;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        tmp = nmdrawGetPointLen(&point);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 3:
        min = vsptblLevelGoalValue[vnmdispCrsEnv->no]
                                  [vnmdispLevelMesInfo[i].num] /
              60;
        sec = vsptblLevelGoalValue[vnmdispCrsEnv->no]
                                  [vnmdispLevelMesInfo[i].num] %
              60;
        ulstdSprintf(str_tmp, "%d%02d", min, sec);
        tmp = nmfontGetStrFLen(str_tmp, 20.0f);
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no]
                                          [vnmdispLevelMesInfo[i].num + 1];
        point.type = 0;
        point.size[0] = 0x14;
        point.size[1] = 0x18;
        point.language = *vnmdispLang;
        tmp += nmdrawGetPointLen(&point);
        ulstdSprintf(
            str_tmp, "%s %s %s  %s",
            vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num],
            vnmtblCommon[*vnmdispLang][2], vnmtblLevelCompMes[*vnmdispLang][6],
            vnmtblCommon[*vnmdispLang][1]);
        tmp += nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          ulstdSprintf(str_tmp, "%d%02d", min, sec);
          tmp = nmfontGetStrFLen(str_tmp, font_size);
          point.size[0] = font_size;
          tmp += nmdrawGetPointLen(&point);
          ulstdSprintf(
              str_tmp, "%s %s %s  %s",
              vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num],
              vnmtblCommon[*vnmdispLang][2],
              vnmtblLevelCompMes[*vnmdispLang][6],
              vnmtblCommon[*vnmdispLang][1]);
          tmp += nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 20.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = ((640.0f - tmp) / 2.0f) + vnmdispLevelMesPos[i];
        font_pos[1] = 88.0f + (32.0f * (f32)(i % 4));
        nmfontSetPack(1);
        ulstdSprintf(
            str_tmp, "%s ",
            vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        font_pos[0] += tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%d", min);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetStrFLen(str_tmp, font_size);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, "%s", vnmtblCommon[*vnmdispLang][2]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        font_pos[0] += tmp;
        nmfontSetPack(0);
        ulstdSprintf(str_tmp, "%02d", sec);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetStrFLen(str_tmp, font_size);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s ", vnmtblLevelCompMes[*vnmdispLang][6]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        font_pos[0] += tmp;
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vsptblLevelGoalValue[vnmdispCrsEnv->no]
                                          [vnmdispLevelMesInfo[i].num + 1];
        point.type = 0;
        point.size[0] = font_size;
        point.size[1] = 0x18;
        point.flat = 1;
        point.base = 0;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        tmp = nmdrawGetPointLen(&point);
        font_pos[0] += tmp;
        nmfontSetPack(1);
        ulstdSprintf(str_tmp, " %s", vnmtblCommon[*vnmdispLang][1]);
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      case 4:
        nmfontSetPack(1);
        if (vnmdispLevelMesInfo[i].type == 0) {
          ulstdSprintf(
              str_tmp,
              vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num],
              vsptblCourseName[vnmdispCrsEnv->no + 0x10]);
          tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
          if (tmp > 576.0f) {
            font_size = 16.0f;
            tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
          } else {
            font_size = 20.0f;
          }
          nmfontSetFSize(font_size, 24.0f);
          font_pos[0] = (320.0f + vnmdispLevelMesPos[i]) - (tmp / 2.0f);
          font_pos[1] = 88.0f + (32.0f * (f32)(i % 4));
          nmfontFPrintF(packet, str_tmp, font_pos);
        } else {
          ulstdSprintf(str_tmp, "%d %s %d ", vnmdispLevelMesInfo[i].value[0],
                       vnmtblCommon[*vnmdispLang][4],
                       vnmdispLevelMesInfo[i].value[1]);
          tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
          ulstdSprintf(str_tmp,
                       vnmtblLevelIncompMes[*vnmdispLang][vnmdispCrsEnv->no][3],
                       vsptblCourseName[vnmdispCrsEnv->no + 0x10]);
          tmp += nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
          if (tmp > 576.0f) {
            font_size = 16.0f;
            ulstdSprintf(str_tmp, "%d %s %d ", vnmdispLevelMesInfo[i].value[0],
                         vnmtblCommon[*vnmdispLang][4],
                         vnmdispLevelMesInfo[i].value[1]);
            tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
            ulstdSprintf(
                str_tmp,
                vnmtblLevelIncompMes[*vnmdispLang][vnmdispCrsEnv->no][3],
                vsptblCourseName[vnmdispCrsEnv->no + 0x10]);
            tmp += nmfontGetPackStrFLen(str_tmp, font_size, 0);
          } else {
            font_size = 20.0f;
          }
          nmfontSetFSize(font_size, 24.0f);
          font_pos[0] = (320.0f + vnmdispLevelMesPos[i]) - (tmp / 2.0f);
          font_pos[1] = 88.0f + (32.0f * (f32)(i % 4));
          ulstdSprintf(str_tmp, "%d %s %d ", vnmdispLevelMesInfo[i].value[0],
                       vnmtblCommon[*vnmdispLang][4],
                       vnmdispLevelMesInfo[i].value[1]);
          tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
          nmfontFPrintF(packet, str_tmp, font_pos);
          font_pos[0] += tmp;
          ulstdSprintf(str_tmp,
                       vnmtblLevelIncompMes[*vnmdispLang][vnmdispCrsEnv->no][3],
                       vsptblCourseName[vnmdispCrsEnv->no + 0x10]);
          nmfontFPrintF(packet, str_tmp, font_pos);
        }
        break;
      case 5:
        nmfontSetPack(1);
        ulstdSprintf(
            str_tmp, "%s",
            vnmtblLevelCompMes[*vnmdispLang][vnmdispLevelMesInfo[i].num]);
        tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 20.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = (320.0f + vnmdispLevelMesPos[i]) - (tmp / 2.0f);
        font_pos[1] = 88.0f + (32.0f * (f32)(i % 4));
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      default:
        nmfontSetPack(1);
        if (vnmdispLevelMesInfo[i].type == 0) {
          ulstdSprintf(str_tmp, "%s",
                       vsptblLevelGoalStr[vnmdispCrsEnv->no]
                                         [vnmdispLevelMesInfo[i].num - 6]);
        } else {
          ulstdSprintf(str_tmp, "%d %s %d %s", vnmdispLevelMesInfo[i].value[0],
                       vnmtblCommon[*vnmdispLang][4],
                       vnmdispLevelMesInfo[i].value[1],
                       vnmtblLevelIncompMes[*vnmdispLang][vnmdispCrsEnv->no]
                                           [vnmdispLevelMesInfo[i].num - 6]);
        }
        tmp = nmfontGetPackStrFLen(str_tmp, 20.0f, 0);
        if (tmp > 576.0f) {
          font_size = 16.0f;
          tmp = nmfontGetPackStrFLen(str_tmp, font_size, 0);
        } else {
          font_size = 20.0f;
        }
        nmfontSetFSize(font_size, 24.0f);
        font_pos[0] = (320.0f + vnmdispLevelMesPos[i]) - (tmp / 2.0f);
        font_pos[1] = 88.0f + (32.0f * (f32)(i % 4));
        nmfontFPrintF(packet, str_tmp, font_pos);
        break;
      }
    }
  }
}

static void nmdispStatisCareer(VgmsysGifPkt *packet) {

  char str_tmp[128];         // 0x20(r29)
  float font_pos[4];         // 0xA0(r29)
  signed int font_col[4][4]; // 0xB0(r29)
  Time time;                 // 0xF0(r29)
  Key key;                   // 0x150(r29)
  Point point;               // 0x190(r29)
  char *word_tbl[3][8] = {
      {"HIGH SCORE", "BEST TIME", "TOTAL SCORE", "TRICKS LANDED",
       "TIME TO COMPLETE COURSE", "BEST COMBO", "TRICKS", "DNF"},
      {"HIGHSCORE", "BESTE ZEIT", "PUNKTE GESAMT", "GELANDETE TRICKS",
       "ZEIT F\x94R ABSCHLUSS", "BESTE KOMBO", "TRICKS", "ABBRUCH"},
      {"MEILLEUR SCORE", "MEILLEUR TEMPS", "SCORE TOTAL", "TRICKS EFFECTUES",
       "TEMPS POUR FINIR COURSE", "MEILLEUR COMBO", "TRICKS", "ABANDON"}};
  s32 *word_tbl_ptr = &word_tbl;
  Comb comb_info; // 0x260(r29)
  float tmp;      // 0x268(r29)
  float pos_tmp;  // 0x26C(r29)
  pos_tmp = 16.0f;
  nmdispInitFont();
  if (vnmdispStatistics.state != 0) {
    nmfontSetType(1);
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(font_col[0]);
    nmfontSetFSize(32.0f, 32.0f);
    ulstdSprintf(&str_tmp, "%s", vnmtblResultItem[*vnmdispLang][1]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 32.0f, 1);
    font_pos[0] = vnmdispStatisticsPos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetType(0);
    nmfontSetFSize(16.0f, 16.0f);
    if (vnmdispScoreRank == 0) {
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x40;
      font_col[0][2] = 0x40;
      font_col[0][3] = 0x80;
      font_col[1][0] = 0x80;
      font_col[1][1] = 0x40;
      font_col[1][2] = 0x40;
      font_col[1][3] = 0x80;
    } else {
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x80;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      font_col[1][0] = 0x80;
      font_col[1][1] = 0x80;
      font_col[1][2] = 0x80;
      font_col[1][3] = 0x80;
    }
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][0]);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[1];
    font_pos[1] = 64.0f + pos_tmp;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    ulstdSprintf(&str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[1]) - (80.0f + tmp);
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    point.pos[0] = font_pos[0];
    point.pos[1] = font_pos[1];
    point.col[0][0] = font_col[0][0];
    point.col[0][1] = font_col[0][1];
    point.col[0][2] = font_col[0][2];
    point.col[0][3] = font_col[0][3];
    point.col[1][0] = font_col[1][0];
    point.col[1][1] = font_col[1][1];
    point.col[1][2] = font_col[1][2];
    point.col[1][3] = font_col[1][3];
    point.col[2][0] = font_col[2][0];
    point.col[2][1] = font_col[2][1];
    point.col[2][2] = font_col[2][2];
    point.col[2][3] = font_col[2][3];
    point.col[3][0] = font_col[3][0];
    point.col[3][1] = font_col[3][1];
    point.col[3][2] = font_col[3][2];
    point.col[3][3] = font_col[3][3];
    point.point = vnmdispRecord[vnmdispCrsEnv->no][0]->score;
    point.type = 0;
    point.size[0] = 0x10;
    point.size[1] = 0x10;
    point.flat = 0;
    point.base = 1;
    point.language = *vnmdispLang;
    nmdrawPoint(packet, &point);
    nmfontSetPack(1);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x80;
    font_col[1][1] = 0x80;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][1]);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[2];
    font_pos[1] += 24.0f;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    time.frame = vnmdispBestTime[vnmdispCrsEnv->no]->time;
    time.type = 0;
    time.size[0] = 0x10;
    time.size[1] = 0x10;
    time.pos[0] = (640.0f + vnmdispStatisticsPos[2]) -
                  (80.0f + (9.0f * (float)time.size[0]));
    time.pos[1] = font_pos[1];
    if (vnmdispTimeRenew == 1) {
      time.col[0][0] = 0x80;
      time.col[0][1] = 0x40;
      time.col[0][2] = 0x40;
      time.col[0][3] = 0x80;
      time.col[1][0] = 0x80;
      time.col[1][1] = 0x40;
      time.col[1][2] = 0x40;
      time.col[1][3] = 0x80;
      time.col[2][0] = 0x80;
      time.col[2][1] = 0x40;
      time.col[2][2] = 0x40;
      time.col[2][3] = 0x80;
      time.col[3][0] = 0x80;
      time.col[3][1] = 0x40;
      time.col[3][2] = 0x40;
      time.col[3][3] = 0x80;
    } else {
      time.col[0][0] = 0x80;
      time.col[0][1] = 0x80;
      time.col[0][2] = 0x80;
      time.col[0][3] = 0x80;
      time.col[1][0] = 0x80;
      time.col[1][1] = 0x80;
      time.col[1][2] = 0x80;
      time.col[1][3] = 0x80;
      time.col[2][0] = 0x80;
      time.col[2][1] = 0x80;
      time.col[2][2] = 0x80;
      time.col[2][3] = 0x80;
      time.col[3][0] = 0x80;
      time.col[3][1] = 0x80;
      time.col[3][2] = 0x80;
      time.col[3][3] = 0x80;
    }
    nmdrawTime(packet, &time);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][2]);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[4];
    font_pos[1] += 32.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    ulstdSprintf(&str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[4]) - (80.0f + tmp);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    point.pos[0] = font_pos[0];
    point.pos[1] = font_pos[1];
    point.col[0][0] = font_col[0][0];
    point.col[0][1] = font_col[0][1];
    point.col[0][2] = font_col[0][2];
    point.col[0][3] = font_col[0][3];
    point.point = vnmdispTotalScore[0];
    point.type = 0;
    point.size[0] = 0x10;
    point.size[1] = 0x10;
    point.flat = 1;
    point.base = 1;
    point.language = *vnmdispLang;
    nmdrawPoint(packet, &point);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][3]);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[5];
    font_pos[1] += 24.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(0);
    ulstdSprintf(&str_tmp, "%d", vspDispResult[0].trick_landing);
    tmp = nmfontGetStrFLen(&str_tmp, 16.0f);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[5]) - (80.0f + tmp);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][4]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[6];
    font_pos[1] += 24.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    if (vspDispResult[0].comp_time != 0) {
      time.frame = vspDispResult[0].comp_time;
      time.pos[0] = (640.0f + vnmdispStatisticsPos[6]) -
                    (80.0f + (9.0f * (float)time.size[0]));
      time.pos[1] = font_pos[1];
      time.col[0][0] = 0x80;
      time.col[0][1] = 0x80;
      time.col[0][2] = 0x80;
      time.col[0][3] = 0x80;
      time.col[1][0] = 0x80;
      time.col[1][1] = 0x80;
      time.col[1][2] = 0x80;
      time.col[1][3] = 0x80;
      time.col[2][0] = 0x80;
      time.col[2][1] = 0x80;
      time.col[2][2] = 0x80;
      time.col[2][3] = 0x80;
      time.col[3][0] = 0x80;
      time.col[3][1] = 0x80;
      time.col[3][2] = 0x80;
      time.col[3][3] = 0x80;
      nmdrawTime(packet, &time);
    } else {
      ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][7]);
      tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
      font_pos[0] = (640.0f + vnmdispStatisticsPos[6]) - (80.0f + tmp);
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    }
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][5]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
    font_pos[0] = 80.0f + vnmdispStatisticsPos[7];
    font_pos[1] += 24.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    ulstdSprintf(&str_tmp, " %s", word_tbl[*vnmdispLang][6]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[7]) - (80.0f + tmp);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(0);
    ulstdSprintf(&str_tmp, "%d", vspDispResult[0].comb_num);
    tmp = nmfontGetStrFLen(&str_tmp, 16.0f);
    font_pos[0] = font_pos[0] - tmp;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
    font_pos[0] = (640.0f + vnmdispStatisticsPos[8]) - (80.0f + tmp);
    font_pos[1] += 24.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    point.pos[0] = font_pos[0];
    point.pos[1] = font_pos[1];
    point.col[0][0] = font_col[0][0];
    point.col[0][1] = font_col[0][1];
    point.col[0][2] = font_col[0][2];
    point.col[0][3] = font_col[0][3];
    point.point = vspDispResult[0].comb_points;
    point.type = 0;
    point.size[0] = 0x10;
    point.size[1] = 0x10;
    point.flat = 1;
    point.base = 1;
    point.language = *vnmdispLang;
    nmdrawPoint(packet, &point);
    tmp = 130.5f;
    font_pos[1] += 24.0f + (tmp / 2.0f);
    if (vnmdispCombLine > 0) {
      tmp = (22.5f * vnmdispCombLine) - 4.5f;
      comb_info.ofs = font_pos[1] - (tmp / 2.0f);
      comb_info.line = 9;
      nmdispTrickComb(packet, &comb_info);
    }
    nmdispCareerUp(packet);
    if ((vnmdispOpe.state != 0) && (vnmdispHighScore.state == 0)) {
      key.pos[0] = 320.0f;
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.button = 0;
      key.message = 1;
      switch (vnmdispOpe.state) { /* irregular */
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.center = 1;
      key.language = *vnmdispLang;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispBoostMeter(VgmsysGifPkt *packet, signed int id) {

  float pos_tmp[4];       // 0x20(r29)
  char str_tmp[256];      // 0x30(r29)
  float font_pos[4];      // 0x130(r29)
  signed int font_col[4]; // 0x140(r29)
  DispTex tex;            // 0x150(r29)
  Meter meter;            // 0x200(r29)
  char *word_tbl[3] = {
      // 0x250(r29)
      "TRICK BOOST",  // @2735
      "TRICK-RENNEN", // @2736
      "BOOSTER"       // @2737
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x25C(r29)
  if (vnmdispDivSide == 0) {
    if (id == 0) {
      pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    } else {
      pos_tmp[0] = vnmdispParamPosRight - 16.0f;
    }
    pos_tmp[1] = 64.0f;
  } else {
    pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    if (id == 0) {
      pos_tmp[1] = 16.0f;
    } else {
      pos_tmp[1] = 240.0f;
    }
  }
  nmdispInitFont();
  if (vnmdispDivSide == 1) {
    tex.data = vnmdispTexData->tex + 0x2;
    tex.tex_size[0] = 0x80;
    tex.tex_size[1] = 0x40;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0x40;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 152.0f;
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0];
    tex.vertex[0][1] = pos_tmp[1];
    nmdrawFTex(packet, &tex);
  }
  ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
  tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
  if (vnmdispDivSide == 0) {
    if (id == 0) {
      font_pos[0] = pos_tmp[0];
    } else {
      font_pos[0] = pos_tmp[0] - tmp;
    }
  } else {
    font_pos[0] = pos_tmp[0];
  }
  font_pos[1] = 4.0f + pos_tmp[1];
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  nmfontSetPack(0);
  font_col[0] = 0x80;
  font_col[1] = 0x40;
  font_col[2] = 0x40;
  font_col[3] = 0x80;
  nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
  ulstdSprintf(&str_tmp, "%d", vspDispEnvChar[id].match.boost.num);
  if (vnmdispDivSide == 0) {
    nmfontSetFSize(20.0f, 20.0f);
    if (id == 0) {
      font_pos[0] = pos_tmp[0];
    } else {
      font_pos[0] = pos_tmp[0] - 20.0f;
    }
    font_pos[1] = (44.0f + pos_tmp[1]) - 20.0f;
  } else {
    nmfontSetFSize(24.0f, 24.0f);
    font_pos[0] = pos_tmp[0];
    font_pos[1] = (48.0f + pos_tmp[1]) - 24.0f;
  }
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  if (vnmdispDivSide == 0) {
    meter.ratio = 0.8f;
    meter.type = 2;
    if (id == 0) {
      meter.pos[0] = 24.0f + pos_tmp[0];
    } else {
      meter.pos[0] =
          pos_tmp[0] - (8.0f + (20.0f + (16.0f + (96.0f * meter.ratio))));
    }
    meter.pos[1] = 44.0f + pos_tmp[1];
  } else {
    meter.ratio = 1.0f;
    meter.type = 2;
    meter.pos[0] = 28.0f + pos_tmp[0];
    meter.pos[1] = 48.0f + pos_tmp[1];
  }
  meter.col[0][0] = 0;
  meter.col[0][1] = 0;
  meter.col[0][2] = 0xFF;
  meter.col[0][3] = 0x80;
  meter.col[1][0] = 0xC0;
  meter.col[1][1] = 0xC0;
  meter.col[1][2] = 0xFF;
  meter.col[1][3] = 0x80;
  meter.per = vnmdispBoostMeterLen[id];
  meter.frame = 1;
  meter.shadow = 1;
  meter.div = 0;
  meter.div_per = 0.0f;
  nmdrawMeter(packet, &meter);
}

static void nmdispCalcTutoMes() {
  switch (vnmdispTutoMes.state) {
  case 1:
    if (vnmdispTutoMes.cnt == 0x14) {
      vnmdispTutoMes.state = 2;
      vnmdispTutoMes.cnt = 0;
      return;
    }
    vnmdispTutoMes.cnt += 1;
    return;
  case 2:
    if (vnmdispTutoMes.cnt == 0x12C) {
      vnmdispTutoMes.state = 3;
      vnmdispTutoMes.cnt = 0;
      return;
    }
    if (vnmdispPause.state != 0) {
      return;
    }
    vnmdispTutoMes.cnt += 1;
    return;
  case 3:
    if (vnmdispTutoMes.cnt == 0x14) {
      vnmdispTutoMes.state = 4;
      vnmdispTutoMes.cnt = 0;
      return;
    }
    vnmdispTutoMes.cnt += 1;
    return;
  case 4:
    if (vnmdispTutoMes.cnt == 0x14) {
      if (vnmdispOption->tutorial == 1) {
        if (vnmdispPauseFlow != 3 && vnmdispPauseFlow != 4) {
          vnmdispTutoMesNum = rand() % 25;
          while (1) {
            if (!(vnmdispTutoMesFlag & (1 << vnmdispTutoMesNum))) {
              break;
            }
            if (vnmdispTutoMesFlag == 0x01FFFFFF) {
              vnmdispTutoMesFlag = 0;
              break;
            }
            vnmdispTutoMesNum = (vnmdispTutoMesNum + 1) % 25;
          }
          vnmdispTutoMesFlag |= 1 << vnmdispTutoMesNum;
          vnmdispTutoMes.state = 1;
        } else {
          vnmdispTutoMes.state = 0;
        }
      } else {
        vnmdispTutoMes.state = 0;
      }
      vnmdispTutoMes.cnt = 0;
      return;
    }
    vnmdispTutoMes.cnt += 1;
    break;
  }
}

static void nmdispCalcTrickNameCol(signed int id) {
  signed int que_no; // r16
  signed int j;      // r17
  signed int i;      // r18
  // Size: 0x4C, DWARF: 0x137703
  List *list; // r19
  // Size: 0x810, DWARF: 0x132C07
  CombInfo info; // 0x50(r29)

  list = vnmdispTrickNameList[id];
  nmtrickGetInfo(id, &info);
  i = 0;
  while (1) {
    if (i == 3) {
      break;
    }
    if (list[i].word[0].id == 0) {
      break;
    }
    j = 0;
    while (1) {
      if (j == 0x10) {
        break;
      }
      if (list[i].word[j].id == 0) {
        break;
      }
      if (list[i].word[j].id == 6) {
        break;
      }
      if (list[i].word[j].id == 4) {
        que_no = list[i].word[j].value;
        switch (info.que[que_no].col.state) {
        case 1:
          if (info.que[que_no].col.cnt == 0x14) {
            info.que[que_no].col.state = 2;
            info.que[que_no].col.cnt = 0;
          } else {
            info.que[que_no].col.cnt += 1;
          }
          nmtrickSetInfo(id, &info);
          break;
        case 2:
          if (info.que[que_no].col.cnt == 0x14) {
            info.que[que_no].col.state = 3;
            info.que[que_no].col.cnt = 0;
          } else {
            info.que[que_no].col.cnt += 1;
          }
          nmtrickSetInfo(id, &info);
          break;
        case 3:
          if (info.que[que_no].col.cnt == 0x14) {
            info.que[que_no].col.state = 0;
            info.que[que_no].col.cnt = 0;
          } else {
            info.que[que_no].col.cnt += 1;
          }
          nmtrickSetInfo(id, &info);
          break;
        }
      }
      j++;
    }
    i++;
  }
}

static void nmdispCalcTrickListCate(signed int num) {
  signed int i;   // r16
  signed int tmp; // r17
  // Size: 0x10, DWARF: 0x135A42
  Info info; // 0x30(r29)

  info.num = vnmtblTlistNum[num];
  if (info.num > 0xA) {
    info.num = 0xA;
  }
  info.num += 1;
  switch (vnmdispTrickList[num].state) {
  case 1:
    info.start = -640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 1;
    info.lag = 2;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, vnmdispTrickList[num].pos,
                          vnmdispTrickList[num].cnt);
    if (tmp == 1) {
      vnmdispTrickList[num].state = 2;
      vnmdispTrickList[num].cnt = 0;
      if (vnmdispPauseTrick.state == 1) {
        vnmdispPauseTrick.state = 2;
        vnmdispPauseTrick.cnt = 0;
      }
      vnmdispAllow.state = 1;
      vnmdispAllow.cnt = 0;
      vnmdispOpeAccept = 1;
      return;
    }
    vnmdispTrickList[num].cnt += 1;
    if (vnmdispPauseTrick.state == 1 && vnmdispTrickList[num].cnt == 0xA) {
      vnmdispOpe.state = 1;
      vnmdispOpe.cnt = 0;
      vnmdispOpeConnect = 0;
      return;
    }
  case 2:
    break;
  case 3:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 0;
    info.vel = 0;
    info.lag = 2;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, vnmdispTrickList[num].pos,
                          vnmdispTrickList[num].cnt);
    if (tmp == 1) {
      vnmdispTrickList[num].state = 0;
      vnmdispTrickList[num].cnt = 0;
      if (vnmdispPauseTrick.state == 3) {
        vnmdispPauseTrick.state = 0;
        vnmdispPauseTrick.cnt = 0;
        return;
      }
    } else {
      vnmdispTrickList[num].cnt += 1;
      if (vnmdispTrickList[num].cnt == 0xA) {
        if (vnmdispPauseTrick.state == 3) {
          vnmdispPauseMenu.state = 1;
          vnmdispPauseMenu.cnt = 0;
          return;
        }
        vnmdispTrickList[vnmdispPauseTrickCate].state = 1;
        vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
        for (i = 0; i < 0xB; i++) {
          vnmdispTrickList[vnmdispPauseTrickCate].pos[i] = -640.0f;
        }
        return;
      }
    }
    break;
  case 4:
    info.start = 640.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 1;
    info.vel = 1;
    info.lag = 2;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, vnmdispTrickList[num].pos,
                          vnmdispTrickList[num].cnt);
    if (tmp == 1) {
      vnmdispTrickList[num].state = 2;
      vnmdispTrickList[num].cnt = 0;
      vnmdispOpeAccept = 1;
      vnmdispAllow.state = 1;
      vnmdispAllow.cnt = 0;
      return;
    }
    vnmdispTrickList[num].cnt += 1;
    return;
  case 5:
    info.start = 0.0f;
    info.length = 640.0f;
    info.frame = 0xA;
    info.dir = 1;
    info.vel = 0;
    info.lag = 2;
    info.skip = 0;
    tmp = nmdispCalcSlide(&info, vnmdispTrickList[num].pos,
                          vnmdispTrickList[num].cnt);
    if (tmp == 1) {
      vnmdispTrickList[num].state = 0;
      vnmdispTrickList[num].cnt = 0;
      return;
    }
    vnmdispTrickList[num].cnt += 1;
    if (vnmdispTrickList[num].cnt == 0xA) {
      vnmdispTrickList[vnmdispPauseTrickCate].state = 4;
      vnmdispTrickList[vnmdispPauseTrickCate].cnt = 0;
      for (i = 0; i < 0xB; i++) {
        vnmdispTrickList[vnmdispPauseTrickCate].pos[i] = 640.0f;
      }
    }
    break;
  }
}

static void nmdispTrickNameFaild(VgmsysGifPkt *packet, signed int id) {
  signed int j;           // r16
  signed int i;           // r17
  signed int cnt;         // r18
  float font_pos[4];      // 0x40(r29)
  signed int font_col[4]; // 0x50(r29)
  float font_size[4];     // 0x60(r29)
  // Size: 0x70, DWARF: 0x13BC8D
  Ice ice;         // 0x70(r29)
  float tmp;       // 0xE8(r29)
  char str_tmp[2]; // 0xEC(r29)

  nmdispInitFont();
  if (vnmdispDivMode == 0) {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  } else {
    font_size[0] = 16.0f;
    font_size[1] = 16.0f;
  }
  nmfontSetFSize(font_size[0], font_size[1]);
  font_col[0] = 0x80;
  font_col[1] = 0x40;
  font_col[2] = 0x40;
  font_col[3] = 0x80;
  nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
  font_pos[1] = (vnmdispScrBottom[id] - 48.0f) -
                ((vnmdispTrickNameLine[id] * font_size[1]) +
                 ((vnmdispTrickNameLine[id] - 1) * (font_size[1] / 4.0f)));
  for (i = 0; i < vnmdispTrickNameLine[id]; i++) {
    tmp = vnmdispTrickNameList[id][i].length;
    font_pos[0] = vnmdispScrCenter[id] - (tmp / 2.0f);
    for (j = 0; j < vnmdispTrickNameInfo[id][i].num; j++) {
      str_tmp[0] = vnmdispTrickNameInfo[id][i].word[j].str;
      str_tmp[1] = 0;
      if (vnmdispTrickNameInfo[id][i].word[j].state == 2) {
        ice.pos[0] = font_pos[0];
        ice.pos[1] = font_pos[1];
        ice.col[0][0] = ice.col[1][0] = ice.col[2][0] = ice.col[3][0] = 0x80;
        ice.col[0][1] = ice.col[1][1] = ice.col[2][1] = ice.col[3][1] = 0x80;
        ice.col[0][2] = ice.col[1][2] = ice.col[2][2] = ice.col[3][2] = 0x80;
        ice.col[0][3] = ice.col[1][3] = ice.col[2][3] = ice.col[3][3] = 0x80;
        ice.data = vnmdispTexData->tex + 0x5;
        ice.width = font_size[0];
        ice.height = font_size[1];
        ice.pack = 1;
        nmdrawIceFont(packet, str_tmp, &ice);
      } else if (vnmdispTrickNameInfo[id][i].word[j].state == 3) {
        cnt = vnmdispTrickNameInfo[id][i].word[j].cnt;
        ice.pos[0] = font_pos[0] + vnmdispTrickNameInfo[id][i].word[j].pos[0];
        ice.pos[1] = font_pos[1] + vnmdispTrickNameInfo[id][i].word[j].pos[1];
        ice.col[0][0] = ice.col[1][0] = ice.col[2][0] = ice.col[3][0] = 0x80;
        ice.col[0][1] = ice.col[1][1] = ice.col[2][1] = ice.col[3][1] = 0x80;
        ice.col[0][2] = ice.col[1][2] = ice.col[2][2] = ice.col[3][2] = 0x80;
        ice.col[3][3] = 128.0f - ((128.0f * cnt) / 20.0f);
        if (ice.col[3][3] < 0) {
          ice.col[3][3] = 0;
        }
        ice.col[0][3] = ice.col[1][3] = ice.col[2][3] = ice.col[3][3];
        ice.data = vnmdispTexData->tex + 0x5;
        ice.width = font_size[0];
        ice.height = font_size[1];
        ice.pack = 1;
        nmdrawIceFont(packet, &str_tmp[0], &ice);
      }
      tmp = nmfontGetPackStrFLen(&str_tmp[0], font_size[0], 0);
      font_pos[0] = font_pos[0] + tmp;
    }
    font_pos[1] += 1.25f * font_size[1];
  }
}

static void nmdispTrkMeter(VgmsysGifPkt *packet, signed int id) {
  float pos_tmp[4];  // 0x20(r29)
  char str_tmp[256]; // 0x30(r29)
  // Size: 0xB0, DWARF: 0x13F356
  DispTex tex; // 0x130(r29)
  // Size: 0x50, DWARF: 0x13ADF6
  Meter meter;       // 0x1E0(r29)
  float font_pos[4]; // 0x230(r29)
  char *word_tbl[3] = {
      // 0x240(r29)
      "SPECIAL", // @1888
      "SPEZIAL", // @1889
      "SPECIAL"  // @1888
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x24C(r29)

  if (vnmdispDivMode == 0) {
    pos_tmp[0] = vnmdispParamPosRight - 16.0f;
    pos_tmp[1] = 28.0f;
  } else if (vnmdispDivSide == 0) {
    if (id == 0) {
      pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    } else {
      pos_tmp[0] = vnmdispParamPosRight - 16.0f;
    }
    pos_tmp[1] = 16.0f;
  } else {
    pos_tmp[0] = vnmdispParamPosRight - 16.0f;
    if (id == 0) {
      pos_tmp[1] = 16.0f;
    } else {
      pos_tmp[1] = 16.0f + vnmdispScrBottom[0];
    }
  }
  nmdispInitFont();
  if (vnmdispDivMode == 0 || vnmdispDivSide == 1) {
    tex.data = vnmdispTexData->tex + 0x2;
    tex.tex_size[0] = -0x80;
    tex.tex_size[1] = 0x40;
    tex.tex_uv[0] = 0x80;
    tex.tex_uv[1] = 0x40;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 152.0f;
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0] - tex.option.width;
    tex.vertex[0][1] = pos_tmp[1];
    nmdrawFTex(packet, &tex);
  }
  ulstdSprintf(&str_tmp[0], "%s", word_tbl[*vnmdispLang]);
  tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
  if (vnmdispDivMode == 0) {
    font_pos[0] = pos_tmp[0] - tmp;
    font_pos[1] = 4.0f + pos_tmp[1];
  } else {
    if (vnmdispDivSide == 0) {
      if (id == 0) {
        font_pos[0] = pos_tmp[0];
      } else {
        font_pos[0] = pos_tmp[0] - tmp;
      }
    } else {
      font_pos[0] = pos_tmp[0] - tmp;
    }
    font_pos[1] = 4.0f + pos_tmp[1];
  }
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  if (vnmdispDivMode == 0) {
    meter.ratio = 1.0f;
    meter.type = 2;
    meter.pos[0] = pos_tmp[0] - 144.0f;
    meter.pos[1] = 48.0f + pos_tmp[1];
  } else if (vnmdispDivSide == 0) {
    meter.ratio = 0.8f;
    meter.type = 2;
    if (id == 0) {
      meter.pos[0] = 24.0f + pos_tmp[0];
    } else {
      meter.pos[0] =
          pos_tmp[0] - (8.0f + (20.0f + (16.0f + (96.0f * meter.ratio))));
    }
    meter.pos[1] = 44.0f + pos_tmp[1];
  } else {
    meter.ratio = 1.0f;
    meter.type = 2;
    meter.pos[0] = pos_tmp[0] - 144.0f;
    meter.pos[1] = 48.0f + pos_tmp[1];
  }
  if (vspDispEnvChar[id].bar.left > 0) {
    meter.col[0][0] = 0xFF;
    meter.col[0][1] = 0xFF;
    meter.col[0][2] = 0;
    meter.col[0][3] = 0x80;
    meter.col[1][0] = 0xFF;
    meter.col[1][1] = 0;
    meter.col[1][2] = 0;
    meter.col[1][3] = 0x80;
    meter.per = vnmdispSpMeterLen[id];
    meter.frame = 1;
    meter.shadow = 1;
    meter.div = 1;
    switch (vnmdispSpMeter[id].state) {
    case 1:
      meter.div_per = 0.2f + ((0.6f * vnmdispSpMeter[id].cnt) / 30.0f);
      break;
    case 2:
      meter.div_per = 0.8f - ((0.6f * vnmdispSpMeter[id].cnt) / 30.0f);
      break;
    default:
      meter.div_per = 0.0f;
      break;
    }
    nmdrawMeter(packet, &meter);
    return;
  }
  meter.col[0][0] = 0;
  meter.col[0][1] = 0xFF;
  meter.col[0][2] = 0;
  meter.col[0][3] = 0x80;
  meter.col[1][0] = 0xC0;
  meter.col[1][1] = 0xFF;
  meter.col[1][2] = 0xC0;
  meter.col[1][3] = 0x80;
  meter.per = vnmdispSpMeterLen[id];
  meter.frame = 1;
  meter.shadow = 1;
  meter.div = 0;
  meter.div_per = 0.0f;
  nmdrawMeter(packet, &meter);
}

static void nmdispTrickPtsTrans(VgmsysGifPkt *packet, signed int id,
                                signed int mode) {
  signed int cnt;            // r16
  signed int dec;            // r17
  signed int integer;        // r18
  char str_tmp[128];         // 0x40(r29)
  float font_pos[4];         // 0xC0(r29)
  signed int font_col[4][4]; // 0xD0(r29)
  float font_size[4];        // 0x110(r29)
  float tmp;                 // 0x128(r29)
  float rate;                // 0x12C(r29)

  nmdispInitFont();
  cnt = vnmdispTrickPts[id].cnt;
  switch (mode) {
  case 1:
    if (cnt < 5) {
      rate = (1.5f * cnt) / 5.0f;
    } else {
      rate = 1.5f - ((0.5f * (cnt - 5)) / 5.0f);
    }
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f;
    } else {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f;
    }
    font_col[0][3] = 0x80;
    break;
  case 2:
    rate = 1.0f + ((0.5f * cnt) / 20.0f);
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    } else {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    }
    font_col[0][3] = 0x80 - ((cnt << 7) / 20);
    break;
  case 3:
    rate = 1.0f - (cnt / 20.0f);
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    } else {
      font_size[0] = 16.0f * rate;
      font_size[1] = 16.0f * rate;
    }
    font_col[0][3] = 0x80;
    break;
  case 4:
    rate = 1.0f;
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f;
      font_size[1] = 16.0f;
    } else {
      font_size[0] = 16.0f;
      font_size[1] = 16.0f;
    }
    font_col[0][3] = 0x80 - ((cnt << 7) / 2);
    break;
  default:
    rate = 1.0f;
    if (vnmdispDivMode == 0) {
      font_size[0] = 16.0f;
      font_size[1] = 16.0f;
    } else {
      font_size[0] = 16.0f;
      font_size[1] = 16.0f;
    }
    font_col[0][3] = 0x80;
    break;
  }
  nmfontSetFSize(font_size[0], font_size[1]);
  if (vnmdispTrickPtsDraw[id].link_rate != 0x64) {
    nmfontSetPack(0);
    ulstdSprintf(&str_tmp, "%d", vnmdispTrickPtsDraw[id].single);
    tmp = nmfontGetStrFLen(&str_tmp, font_size[0]);
    font_pos[0] = vnmdispScrCenter[id] - tmp;
    font_pos[1] = 16.0f + (vnmdispScrBottom[id] - 48.0f);
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    integer = vnmdispTrickPtsDraw[id].link_rate / 100;
    dec = vnmdispTrickPtsDraw[id].link_rate % 100;
    if ((dec % 10) == 0) {
      dec = dec / 10;
    }
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, " * ");
    font_pos[0] = vnmdispScrCenter[id];
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
    font_pos[1] -= 0.25f * font_size[1];
    font_size[0] *= 1.25f;
    font_size[1] *= 1.25f;
    nmfontSetFSize(font_size[0], font_size[1]);
    if (vnmdispTrickPtsDraw[id].link_rate < 0x3E8) {
      font_col[0][0] = ((vnmdispTrickPtsDraw[id].link_rate << 6) / 1000) + 0x40;
      font_col[0][1] = 0x80;
      font_col[0][2] = 0x40;
    } else if (vnmdispTrickPtsDraw[id].link_rate < 0x7D0) {
      font_col[0][0] = 0x80;
      font_col[0][1] =
          0x80 - (((vnmdispTrickPtsDraw[id].link_rate - 0x3E8) << 5) / 1000);
      font_col[0][2] = 0x40;
    } else if (vnmdispTrickPtsDraw[id].link_rate < 0xBB8) {
      font_col[0][0] = 0x80;
      font_col[0][1] =
          0x60 - (((vnmdispTrickPtsDraw[id].link_rate - 0x7D0) << 5) / 1000);
      font_col[0][2] = 0x40;
    } else {
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x40;
      font_col[0][2] = 0x40;
    }
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    nmfontSetPack(0);
    ulstdSprintf(&str_tmp, "%d", integer);
    font_pos[0] = font_pos[0] + tmp;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    tmp = nmfontGetStrFLen(&str_tmp, font_size[0]);
    nmfontSetPack(1);
    ulstdSprintf(&str_tmp, ".");
    font_pos[0] = font_pos[0] + tmp;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    tmp = nmfontGetPackStrFLen(&str_tmp, font_size[0], 0);
    nmfontSetPack(0);
    ulstdSprintf(&str_tmp, "%d", dec);
    font_pos[0] = font_pos[0] + tmp;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    return;
  }
  font_pos[1] = 16.0f + (vnmdispScrBottom[id] - 48.0f);
  font_col[0][0] = 0x80;
  font_col[0][1] = 0x80;
  font_col[0][2] = 0x80;
  nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2], font_col[0][3]);
  nmfontSetPack(0);
  ulstdSprintf(&str_tmp, "%d", vnmdispTrickPtsDraw[id].single);
  tmp = nmfontGetStrFLen(&str_tmp, font_size[0]);
  font_pos[0] = vnmdispScrCenter[id] - (tmp / 2.0f);
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
}

static void nmdispStatisMatch(VgmsysGifPkt *packet) {
  signed int i;              // r16
  signed int j;              // r17
  char str_tmp[128];         // 0x70(r29)
  signed int result[2][3];   // 0xF0(r29)
  float font_pos[4];         // 0x110(r29)
  signed int font_col[4][4]; // 0x120(r29)
  Key key;                   // 0x160(r29)
  Point point;               // 0x1A0(r29)
  char *word_tbl[3][5] = {
      // 0x210(r29)
      {"TOTAL SCORES", "TOTAL SCORE", "TRICKS LANDED", "BEST COMBO",
       "ENTERED WORD"},
      {"GESAMTERGEBNIS", "PUNKTE GESAMT", "GELANDETE TRICKS", "BESTE KOMBO",
       "EINGEGEBENES WORT"},
      {"RESULTATS", "SCORE TOTAL", "TRICKS EFFECTUES", "MEILLEUR COMBO",
       "MOT ENTRE"}};
  s32 *word_tbl_ptr = &word_tbl;
  char *result_tbl[3][4] = {
      // 0x250(r29)
      {"WINNER", "LOSER", "DRAW", "NO CONTEST"},
      {"SIEGER", "VERLIERER", "UNENTSCH.", "VAINQUEUR"},
      {"VAINQUEUR", "PERDANT", "EGALITE", "AUCUN TOURNOI"}};
  s32 *result_tbl_ptr = &result_tbl;
  char *score_tbl[3][3] = {// 0x280(r29)
                           {"WINS", "LOSSES", "DRAWS"},
                           {"SIEG", "NIEDERL", "UNENTSCH."},
                           {"GAGNE", "PERDU", "EGALITE"}};
  s32 *score_tbl_ptr = &score_tbl;
  float tmp;     // 0x2A8(r29)
  float pos_tmp; // 0x2AC(r29)

  pos_tmp = 16.0f;
  nmdispInitFont();
  if (vnmdispStatistics.state != 0) {
    nmfontSetType(1);
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(32.0f, 32.0f);
    ulstdSprintf(&str_tmp, "%s", vnmtblResultItem[*vnmdispLang][1]);
    tmp = nmfontGetPackStrFLen(str_tmp, 32.0f, 1);
    font_pos[0] = vnmdispStatisticsPos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetType(0);
    result[0][0] = result[1][1] = vspDispVsScore.win;
    result[0][1] = result[1][0] = vspDispVsScore.lose;
    result[0][2] = result[1][2] = vspDispVsScore.draw;
    nmfontSetFSize(24.0f, 24.0f);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    ulstdSprintf(&str_tmp, "%s",
                 vnmtblMatchRule[*vnmdispLang][vnmdispModeEnv->match_rule]);
    tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
    font_pos[0] = vnmdispStatisticsPos[1] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp + 48.0f;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    pos_tmp += 72.0f;
    for (i = 0; i < 2; i++) {
      if (vnmdispInvalid == 1) {
        font_col[0][0] = 0x40;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
        ulstdSprintf(&str_tmp, "%s", result_tbl[*vnmdispLang][3]);
      } else if (vspDispEnvChar[0].rank == vspDispEnvChar[1].rank) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x60;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
        ulstdSprintf(&str_tmp, "%s", result_tbl[*vnmdispLang][2]);
      } else {
        if (vspDispEnvChar[i].rank == 0) {
          font_col[0][0] = 0x80;
          font_col[0][1] = 0x40;
          font_col[0][2] = 0x40;
          font_col[0][3] = 0x80;
        } else {
          font_col[0][0] = 0x40;
          font_col[0][1] = 0x40;
          font_col[0][2] = 0x80;
          font_col[0][3] = 0x80;
        }
        ulstdSprintf(&str_tmp, "%s",
                     result_tbl[*vnmdispLang][vspDispEnvChar[i].rank]);
      }
      nmfontSetPack(1);
      nmfontSetFSize(24.0f, 24.0f);
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      font_pos[0] = vnmdispStatisticsPos[(i * 5) + 2] + 64.0f;
      font_pos[1] = pos_tmp + (104.0f * i);
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      nmfontSetFSize(16.0f, 16.0f);
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x80;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      ulstdSprintf(&str_tmp, "%s %d", vnmtblCommon[*vnmdispLang][3], i + 1);
      font_pos[0] = vnmdispStatisticsPos[(i * 5) + 3] + 80.0f;
      font_pos[1] += 24.0f;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      if (vnmdispCharEnv[i].no < 0xC) {
        ulstdSprintf(&str_tmp, "%s", vsptblCharacterName[vnmdispCharEnv[i].no]);
      } else {
        ulstdSprintf(
            &str_tmp, "%s",
            &vnmdispSecret->create_character[vnmdispCharEnv[i].no - 0xC].name);
      }
      tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
      font_pos[0] += 128.0f;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      font_pos[1] += 20.0f;
      switch (vnmdispModeEnv->match_rule) {
      case 3:
        nmfontSetPack(1);
        ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][4]);
        font_pos[0] = vnmdispStatisticsPos[(i * 5) + 4] + 128.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
        nmfontSetPack(0);
        for (j = 0; j < 0xA; j += 1) {
          if (j < vnmdispHorseGet[i]) {
            str_tmp[j] = vnmdispHorseWord[j];
          } else {
            str_tmp[j] = 0x5F;
          }
        }
        str_tmp[j] = 0;
        font_pos[0] = (640.0f + vnmdispStatisticsPos[(i * 5) + 4]) - 240.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
        break;
      default:
        nmfontSetPack(1);
        ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][1]);
        font_pos[0] = vnmdispStatisticsPos[(i * 5) + 4] + 128.0f;
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
        nmfontSetPack(1);
        ulstdSprintf(&str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
        tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
        font_pos[0] =
            (640.0f + vnmdispStatisticsPos[(i * 5) + 4]) - (80.0f + tmp);
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
        point.pos[0] = font_pos[0];
        point.pos[1] = font_pos[1];
        point.col[0][0] = font_col[0][0];
        point.col[0][1] = font_col[0][1];
        point.col[0][2] = font_col[0][2];
        point.col[0][3] = font_col[0][3];
        point.point = vnmdispTotalScore[i];
        point.type = 0;
        point.size[0] = 0x10;
        point.size[1] = 0x10;
        point.flat = 1;
        point.base = 1;
        point.language = *vnmdispLang;
        nmdrawPoint(packet, &point);
        break;
      }
      font_pos[1] += 20.0f;
      nmfontSetPack(1);
      ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][2]);
      font_pos[0] = vnmdispStatisticsPos[(i * 5) + 5] + 128.0f;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      nmfontSetPack(0);
      ulstdSprintf(&str_tmp, "%d", vspDispResult[i].trick_landing);
      tmp = nmfontGetStrFLen(str_tmp, 16.0f);
      font_pos[0] =
          (640.0f + vnmdispStatisticsPos[(i * 5) + 5]) - (80.0f + tmp);
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      font_pos[1] += 20.0f;
      nmfontSetPack(1);
      ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][3]);
      font_pos[0] = vnmdispStatisticsPos[(i * 5) + 6] + 128.0f;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      nmfontSetPack(1);
      ulstdSprintf(&str_tmp, " %s", vnmtblCommon[*vnmdispLang][0]);
      tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
      font_pos[0] =
          (640.0f + vnmdispStatisticsPos[(i * 5) + 6]) - (80.0f + tmp);
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      point.pos[0] = font_pos[0];
      point.pos[1] = font_pos[1];
      point.col[0][0] = font_col[0][0];
      point.col[0][1] = font_col[0][1];
      point.col[0][2] = font_col[0][2];
      point.col[0][3] = font_col[0][3];
      point.point = vspDispResult[i].comb_points;
      point.type = 0;
      point.size[0] = 0x10;
      point.size[1] = 0x10;
      point.flat = 1;
      point.base = 1;
      point.language = *vnmdispLang;
      nmdrawPoint(packet, &point);
    }
    pos_tmp = 304.0f;
    nmfontSetPack(1);
    nmfontSetFSize(24.0f, 24.0f);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x40;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang][0]);
    tmp = nmfontGetPackStrFLen(str_tmp, 24.0f, 0);
    font_pos[0] = vnmdispStatisticsPos[12] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp;
    nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetFSize(16.0f, 16.0f);
    font_col[0][0] = 0x80;
    font_col[0][1] = 0x80;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                  font_col[0][3]);
    font_pos[1] = pos_tmp + 30.0;
    for (i = 0; i < 3; i++) {
      ulstdSprintf(&str_tmp, "%s", score_tbl[*vnmdispLang][i]);
      tmp = nmfontGetPackStrFLen(str_tmp, 16.0f, 0);
      font_pos[0] = ((288.0f + vnmdispStatisticsPos[13]) + (128.0f * i)) - tmp;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    }
    pos_tmp += 50.0f;
    for (i = 0; i < 2; i++) {
      nmfontSetPack(1);
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x80;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      ulstdSprintf(&str_tmp, "%s %d", vnmtblCommon[*vnmdispLang][3], i + 1);
      font_pos[0] = vnmdispStatisticsPos[i + 0xE] + 80.0f;
      font_pos[1] = pos_tmp + (20.0f * i);
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      nmfontSetPack(0);
      if (vnmdispInvalid == 1) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      } else if ((vspDispEnvChar[0].rank != vspDispEnvChar[1].rank) &&
                 (vspDispEnvChar[i].rank == 0)) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
      } else {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      }
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      ulstdSprintf(&str_tmp, "%d", result[i][0]);
      tmp = nmfontGetStrFLen(str_tmp, 16.0f);
      font_pos[0] = (288.0f + vnmdispStatisticsPos[i + 0xE]) - tmp;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      if (vnmdispInvalid == 1) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      } else if ((vspDispEnvChar[0].rank != vspDispEnvChar[1].rank) &&
                 (vspDispEnvChar[i].rank == 1)) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
      } else {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      }
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      ulstdSprintf(&str_tmp, "%d", result[i][1]);
      tmp = nmfontGetStrFLen(str_tmp, 16.0f);
      font_pos[0] = (128.0f + (288.0f + vnmdispStatisticsPos[i + 0xE])) - tmp;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      if (vnmdispInvalid == 1) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      } else if (vspDispEnvChar[0].rank == vspDispEnvChar[1].rank) {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x40;
        font_col[0][2] = 0x40;
        font_col[0][3] = 0x80;
      } else {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
      }
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      ulstdSprintf(&str_tmp, "%d", result[i][2]);
      tmp = nmfontGetStrFLen(str_tmp, 16.0f);
      font_pos[0] = (256.0f + (288.0f + vnmdispStatisticsPos[i + 0xE])) - tmp;
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
    }
    if (vnmdispOpe.state != 0) {
      key.pos[0] = 320.0f;
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.button = 0;
      key.message = 1;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      key.center = 1;
      key.language = *vnmdispLang;
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispHighScore(VgmsysGifPkt *packet) {
  signed int i;              // r16
  signed int j;              // r17
  signed int char_no;        // r18
  char str_tmp[128];         // 0x40(r29)
  float font_pos[4];         // 0xC0(r29)
  signed int font_col[4][4]; // 0xD0(r29)
  // Size: 0x40, DWARF: 0x13519E
  Key key; // 0x110(r29)
  // Size: 0x70, DWARF: 0x137FF4
  Point point;        // 0x150(r29)
  float tmp;          // 0x1C4(r29)
  float pos_tmp;      // 0x1C8(r29)
  char entry_name[2]; // 0x1CC(r29)

  pos_tmp = 16.0f;
  nmdispInitFont();
  if (vnmdispHighScore.state != 0) {
    nmfontSetType(1);
    font_col[0][0] = 0x40;
    font_col[0][1] = 0x40;
    font_col[0][2] = 0x80;
    font_col[0][3] = 0x80;
    font_col[1][0] = 0x40;
    font_col[1][1] = 0x40;
    font_col[1][2] = 0x80;
    font_col[1][3] = 0x80;
    font_col[2][0] = 0x80;
    font_col[2][1] = 0x80;
    font_col[2][2] = 0x80;
    font_col[2][3] = 0x80;
    font_col[3][0] = 0x80;
    font_col[3][1] = 0x80;
    font_col[3][2] = 0x80;
    font_col[3][3] = 0x80;
    nmfontSetCol(&font_col[0][0]);
    nmfontSetFSize(32.0f, 32.0f);
    ulstdSprintf(&str_tmp, "%s", vnmtblResultItem[*vnmdispLang][2]);
    tmp = nmfontGetPackStrFLen(&str_tmp, 32.0f, 1);
    font_pos[0] = vnmdispHighScorePos[0] + ((640.0f - tmp) / 2.0f);
    font_pos[1] = pos_tmp;
    nmfontGPrintF(packet, &str_tmp, &font_pos[0]);
    nmfontSetType(0);
    for (i = 0; i < 6; i++) {
      nmfontSetPack(0);
      nmfontSetFSize(18.0f, 24.0f);
      font_col[0][0] = 0x80;
      font_col[0][1] = ((i << 6) / 5) + 0x40;
      font_col[0][2] = 0x40;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      ulstdSprintf(&str_tmp, "%s", vnmtblRank[*vnmdispLang][i]);
      font_pos[0] = 32.0f + vnmdispHighScorePos[i + 1];
      font_pos[1] = 64.0f + pos_tmp + (42.0f * i);
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      ulstdSprintf(&str_tmp, "%s", vnmdispRecord[vnmdispCrsEnv->no][i]->name);
      if (i == vnmdispScoreRank) {
        for (j = 0; j < 3; j++) {
          if (j == vnmdispEntryNum) {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x60;
            font_col[0][2] = 0x40;
            switch (vnmdispHighScore.state) {
            case 2:
              if (vnmdispHighScore.cnt < 0x3CU) {
                font_col[0][3] = 0x80 - ((vnmdispHighScore.cnt * 128) / 60);
              } else {
                font_col[0][3] = ((vnmdispHighScore.cnt - 0x3C) * 128) / 60;
              }
              break;
            default:
              font_col[0][3] = 0x80;
              break;
            }
            nmfontSetFSize(22.5f, 30.0f);
            font_pos[0] =
                (22.5f * j) +
                ((72.0f + (32.0f + vnmdispHighScorePos[i + 1])) - 6.75f);
            font_pos[1] = (64.0f + pos_tmp + (42.0f * i)) - 3.0f;
          } else {
            font_col[0][0] = 0x80;
            font_col[0][1] = 0x80;
            font_col[0][2] = 0x80;
            font_col[0][3] = 0x80;
            nmfontSetFSize(18.0f, 24.0f);
            font_pos[0] =
                (22.5f * j) +
                ((72.0f + (32.0f + vnmdispHighScorePos[i + 1])) - 4.5f);
            font_pos[1] = 64.0f + pos_tmp + (42.0f * i);
          }
          nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                        font_col[0][3]);
          memcpy(entry_name, &str_tmp[j], 1);
          entry_name[1] = 0;
          nmfontFPrintF(packet, &entry_name[0], &font_pos[0]);
        }
      } else {
        font_col[0][0] = 0x80;
        font_col[0][1] = 0x80;
        font_col[0][2] = 0x80;
        font_col[0][3] = 0x80;
        nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                      font_col[0][3]);
        font_pos[0] = 72.0f + (32.0f + vnmdispHighScorePos[i + 1]);
        font_pos[1] = 64.0f + pos_tmp + (42.0f * i);
        nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      }
      font_col[0][0] = 0x80;
      font_col[0][1] = 0x80;
      font_col[0][2] = 0x80;
      font_col[0][3] = 0x80;
      nmfontSetFCol(font_col[0][0], font_col[0][1], font_col[0][2],
                    font_col[0][3]);
      nmfontSetPack(1);
      nmfontSetFSize(18.0f, 24.0f);
      char_no = vnmdispRecord[vnmdispCrsEnv->no][i]->chr_no;
      if (char_no < 0xC) {
        ulstdSprintf(&str_tmp, "%s", vsptblCharacterName[char_no]);
      } else {
        ulstdSprintf(&str_tmp, "%s",
                     vnmdispSecret->create_character[char_no - 0xC].name);
      }
      font_pos[0] = 144.0f + (32.0f + vnmdispHighScorePos[i + 1]);
      font_pos[1] = 64.0f + pos_tmp + (42.0f * i);
      nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
      point.pos[0] = (640.0f + vnmdispHighScorePos[i + 1]) - 32.0f;
      point.pos[1] = font_pos[1];
      if (i == vnmdispScoreRank) {
        point.col[0][0] = 0x80;
        point.col[0][1] = ((i << 6) / 5) + 0x40;
        point.col[0][2] = 0x40;
      } else {
        point.col[0][0] = 0x80;
        point.col[0][1] = 0x80;
        point.col[0][2] = 0x80;
      }
      point.col[0][3] = 0x80;
      point.point = vnmdispRecord[vnmdispCrsEnv->no][i]->score;
      point.type = 0;
      point.size[0] = 0x12;
      point.size[1] = 0x18;
      point.flat = 1;
      point.base = 1;
      point.language = *vnmdispLang;
      nmdrawPoint(packet, &point);
    }
    if (vnmdispOpe.state != 0) {
      key.pos[1] = 430.0f;
      key.data = vnmdispTexData->tex;
      key.language = *vnmdispLang;
      key.center = 1;
      if (vnmdispScoreRank < 0xFF) {
        switch (vnmdispOpe.state) {
        case 1:
          key.mode = 0;
          key.cnt = vnmdispOpe.cnt;
          break;
        case 3:
          key.mode = 1;
          key.cnt = vnmdispOpe.cnt;
          break;
        default:
          key.mode = 0;
          key.cnt = 5;
          break;
        }
        key.pos[0] = 320.0f;
        key.button = 0;
        key.message = 0;
        nmdrawKeyOperate(packet, &key);
        return;
      }
      key.pos[0] = 320.0f;
      key.button = 0;
      key.message = 1;
      switch (vnmdispOpe.state) {
      case 1:
        key.mode = 0;
        key.cnt = vnmdispOpe.cnt;
        break;
      case 3:
        key.mode = 1;
        key.cnt = vnmdispOpe.cnt;
        break;
      default:
        key.mode = 0;
        key.cnt = 5;
        break;
      }
      nmdrawKeyOperate(packet, &key);
    }
  }
}

static void nmdispTotalTrkPts(VgmsysGifPkt *packet, signed int id) {
  float pos_tmp[4];       // 0x20(r29)
  char str_tmp[128];      // 0x30(r29)
  float font_pos[4];      // 0xB0(r29)
  signed int font_col[4]; // 0xC0(r29)
  // Size: 0xB0, DWARF: 0x13F356
  DispTex tex; // 0xD0(r29)
  char *word_tbl[3] = {
      // 0x180(r29)
      "SCORE",       // @1826
      "PUNKTESTAND", // @1827
      "SCORE"        // @1826
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x18C(r29)

  if (vnmdispDivMode == 0) {
    pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    pos_tmp[1] = 28.0f;
  } else if (vnmdispDivSide == 0) {
    if (id == 0) {
      pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    } else {
      pos_tmp[0] = vnmdispParamPosRight - 16.0f;
    }
    pos_tmp[1] = 64.0f;
  } else {
    pos_tmp[0] = 16.0f + vnmdispParamPosLeft;
    if (id == 0) {
      pos_tmp[1] = 16.0f;
    } else {
      pos_tmp[1] = 240.0f;
    }
  }
  nmdispInitFont();
  if (vnmdispDivMode == 0 || vnmdispDivSide == 1) {
    tex.data = vnmdispTexData->tex + 0x2;
    tex.tex_size[0] = 0x80;
    tex.tex_size[1] = 0x40;
    tex.tex_uv[0] = 0;
    tex.tex_uv[1] = 0x40;
    tex.col[0][0] = 0;
    tex.col[0][1] = 0;
    tex.col[0][2] = 0;
    tex.col[0][3] = 0x40;
    tex.option.sprite = 1;
    tex.option.bil = 1;
    tex.option.width = 152.0f;
    tex.option.height = tex.tex_size[1];
    tex.vertex[0][0] = pos_tmp[0];
    tex.vertex[0][1] = pos_tmp[1];
    nmdrawFTex(packet, &tex);
  }
  ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
  tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
  if (vnmdispDivMode == 0) {
    font_pos[0] = pos_tmp[0];
    font_pos[1] = 4.0f + pos_tmp[1];
  } else {
    if (vnmdispDivSide == 0) {
      if (id == 0) {
        font_pos[0] = pos_tmp[0];
      } else {
        font_pos[0] = pos_tmp[0] - tmp;
      }
    } else {
      font_pos[0] = pos_tmp[0];
    }
    font_pos[1] = 4.0f + pos_tmp[1];
  }
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  ulstdSprintf(&str_tmp, "%s", vnmtblCommon[*vnmdispLang][0]);
  tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
  if (vnmdispDivMode == 0) {
    font_pos[0] = (pos_tmp[0] + tex.option.width) - 24.0f;
    font_pos[1] = 32.0f + pos_tmp[1];
  } else {
    if (vnmdispDivSide == 0) {
      if (id == 0) {
        font_pos[0] = 112.0f + pos_tmp[0];
      } else {
        font_pos[0] = pos_tmp[0] - tmp;
      }
      font_pos[1] = 28.0f + pos_tmp[1];
    } else {
      font_pos[0] = (pos_tmp[0] + tex.option.width) - 24.0f;
      font_pos[1] = 32.0f + pos_tmp[1];
    }
  }
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  nmfontSetPack(0);
  font_col[0] = 0x40;
  font_col[1] = 0x60;
  font_col[2] = 0x40;
  font_col[3] = 0x80;
  nmfontSetFCol(font_col[0], font_col[1], font_col[2], font_col[3]);
  ulstdSprintf(&str_tmp, "%d", vnmdispTrickPtsDraw[id].total);
  if (vnmdispDivMode == 0) {
    tmp = nmfontGetStrFLen(&str_tmp, 22.0f);
    if (!(tmp <= 154.0f)) {
      nmfontSetFSize(16.0f, 24.0f);
      tmp = nmfontGetStrFLen(&str_tmp, 16.0f);
    } else if (!(tmp <= 132.0f)) {
      nmfontSetFSize(18.0f, 24.0f);
      tmp = nmfontGetStrFLen(&str_tmp, 18.0f);
    } else {
      nmfontSetFSize(22.0f, 24.0f);
    }
    font_pos[0] = font_pos[0] - tmp;
    font_pos[1] = font_pos[1] - 8.0f;
  } else if (vnmdispDivSide == 0) {
    tmp = nmfontGetStrFLen(&str_tmp, 18.0f);
    if (!(tmp <= 108.0f)) {
      nmfontSetFSize(16.0f, 20.0f);
      tmp = nmfontGetStrFLen(&str_tmp[0], 16.0f);
    } else {
      nmfontSetFSize(18.0f, 20.0f);
    }
    font_pos[0] = font_pos[0] - tmp;
    font_pos[1] = font_pos[1] - 4.0f;
  } else {
    tmp = nmfontGetStrFLen(&str_tmp, 22.0f);
    if (!(tmp <= 154.0f)) {
      nmfontSetFSize(16.0f, 24.0f);
      tmp = nmfontGetStrFLen(&str_tmp, 16.0f);
    } else if (!(tmp <= 132.0f)) {
      nmfontSetFSize(18.0f, 24.0f);
      tmp = nmfontGetStrFLen(&str_tmp, 18.0f);
    } else {
      nmfontSetFSize(22.0f, 24.0f);
    }
    font_pos[0] = font_pos[0] - tmp;
    font_pos[1] = font_pos[1] - 8.0f;
  }
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
}

static void nmdispIntrMatch(VgmsysGifPkt *packet) {
  char str_tmp[128]; // 0x20(r29)
  float pos_tmp[4];  // 0xA0(r29)
  float font_pos[4]; // 0xB0(r29)
  // Size: 0xB0, DWARF: 0x13F356
  DispTex tex; // 0xC0(r29)
  // Size: 0x40, DWARF: 0x13519E
  Key key; // 0x170(r29)
  // Size: 0x20, DWARF: 0x134B98
  Fade fade; // 0x1B0(r29)
  char *word_tbl[3] = {
      // 0x1D0(r29)
      "VS",    // @1101
      "GEGEN", // @1102
      "CONTRE" // @1103
  };
  s32 *word_tbl_ptr = &word_tbl;
  float tmp; // 0x1DC(r29)

  pos_tmp[0] = 32.0f;
  pos_tmp[1] = 96.0f;
  nmdispInitFont();
  tex.data = vnmdispTexData->tex + 0x8;
  tex.tex_size[0] = 0x100;
  tex.tex_size[1] = 0x80;
  tex.tex_uv[0] = 0;
  tex.tex_uv[1] = 0;
  tex.vertex[0][0] = pos_tmp[0] - 8.0f;
  tex.vertex[0][1] = pos_tmp[1] - vnmtblCourseLogo[vnmdispCrsEnv->no][1];
  tex.col[0][0] = 0x80;
  tex.col[0][1] = 0x80;
  tex.col[0][2] = 0x80;
  tex.col[0][3] = 0x80;
  tex.option.sprite = 1;
  tex.option.bil = 1;
  tex.option.width = tex.tex_size[0];
  tex.option.height = tex.tex_size[1];
  nmdrawFTex(packet, &tex);
  nmfontSetPack(1);
  nmfontSetFSize(24.0f, 24.0f);
  ulstdSprintf(&str_tmp, "%s",
               vnmtblMatchRule[*vnmdispLang][vnmdispModeEnv->match_rule]);
  tmp = nmfontGetPackStrFLen(&str_tmp, 24.0f, 0);
  font_pos[0] = (640.0f - tmp) / 2.0f;
  font_pos[1] = 32.0f + pos_tmp[1];
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  nmfontSetFSize(24.0f, 24.0f);
  ulstdSprintf(&str_tmp, "%s", word_tbl[*vnmdispLang]);
  tmp = nmfontGetPackStrFLen(&str_tmp, 24.0f, 0);
  font_pos[0] = (640.0f - tmp) / 2.0f;
  font_pos[1] = 212.0f;
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  nmfontSetFSize(16.0f, 16.0f);
  ulstdSprintf(&str_tmp, "%s 1", vnmtblCommon[*vnmdispLang][3]);
  font_pos[0] = 64.0f;
  font_pos[1] = 168.0f;
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  nmfontSetFSize(20.0f, 20.0f);
  if (vnmdispCharEnv->no < 0xC) {
    ulstdSprintf(&str_tmp, "%s", vsptblCharacterName[vnmdispCharEnv->no]);
  } else {
    ulstdSprintf(
        &str_tmp, "%s",
        vnmdispSecret->create_character[vnmdispCharEnv->no - 0xC].name);
  }
  font_pos[1] += 16.0f;
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  nmfontSetFSize(20.0f, 20.0f);
  if (vnmdispCharEnv[1].no < 0xC) {
    ulstdSprintf(&str_tmp, "%s", vsptblCharacterName[vnmdispCharEnv[1].no]);
  } else {
    ulstdSprintf(
        &str_tmp, "%s",
        vnmdispSecret->create_character[vnmdispCharEnv[1].no - 0xC].name);
  }
  tmp = nmfontGetPackStrFLen(&str_tmp, 20.0f, 0);
  font_pos[0] = 640.0f - (64.0f + tmp);
  font_pos[1] = 260.0f;
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  nmfontSetFSize(16.0f, 16.0f);
  ulstdSprintf(&str_tmp, "%s 2", vnmtblCommon[*vnmdispLang][3]);
  tmp = nmfontGetPackStrFLen(&str_tmp, 16.0f, 0);
  font_pos[0] = 640.0f - (64.0f + tmp);
  font_pos[1] -= 16.0f;
  nmfontFPrintF(packet, &str_tmp, &font_pos[0]);
  if (vnmdispIntr.state == 1) {
    fade.cnt = vnmdispIntr.cnt;
    fade.flag = 0;
    fade.type = 0;
    fade.col = 0;
    fade.max = 0x3C;
    nmdrawFade(packet, &fade);
  }
  key.pos[0] = 320.0f;
  key.pos[1] = 430.0f;
  key.data = vnmdispTexData->tex;
  key.button = 0;
  key.message = 8;
  key.language = *vnmdispLang;
  if (vnmdispIntr.state == 1) {
    if (vnmdispIntr.cnt < 5U) {
      key.cnt = vnmdispIntr.cnt;
    } else {
      key.cnt = 5;
    }
  } else {
    key.cnt = 5;
  }
  key.center = 1;
  key.mode = 0;
  nmdrawKeyOperate(packet, &key);
  if (vnmdispIntr.state == 0 || vnmdispIntr.state == 3) {
    fade.cnt = vnmdispIntr.cnt;
    fade.flag = 1;
    fade.type = 0;
    fade.col = 0;
    fade.max = 0x3C;
    nmdrawFade(packet, &fade);
  }
}

static char nmdispCalcTrickNameFaild(signed int id) {
  signed int i;          // r16
  signed int j;          // r17
  signed int cnt;        // r18
  signed int search_num; // r19
  signed int tmp;        // r20
  char end_flag;         // r21
  float dir;             // 0x78(r29)
  float len;             // 0x7C(r29)

  end_flag = 0;
  for (i = 0; i < vnmdispTrickNameLine[id]; i++) {
    for (j = 0; j < vnmdispTrickNameInfo[id][i].num; j++) {
      if (vnmdispTrickNameInfo[id][i].word[j].state == 3) {
        if (vnmdispTrickNameInfo[id][i].word[j].cnt == 0x14) {
          vnmdispTrickNameInfo[id][i].word[j].state = 0;
          vnmdispTrickNameInfo[id][i].word[j].cnt = 0;
          vnmdispTrickNameInfo[id][i].word[j].pos[0] = 0.0f;
          vnmdispTrickNameInfo[id][i].word[j].pos[1] = 0.0f;
        } else {
          vnmdispTrickNameInfo[id][i].word[j].cnt += 1;
          cnt = vnmdispTrickNameInfo[id][i].word[j].cnt;
          switch (vnmdispTrickEffectType[id]) {
          case 0:
            vnmdispTrickNameInfo[id][i].word[j].pos[0] = 0.0f;
            vnmdispTrickNameInfo[id][i].word[j].pos[1] =
                (cnt * cnt) * vnmdispTrickNameInfo[id][i].word[j].add[1];
            break;
          case 1:
          case 2:
            vnmdispTrickNameInfo[id][i].word[j].pos[0] =
                (cnt * cnt) * vnmdispTrickNameInfo[id][i].word[j].add[0];
            vnmdispTrickNameInfo[id][i].word[j].pos[1] =
                (cnt * cnt) * vnmdispTrickNameInfo[id][i].word[j].add[1];
            break;
          case 3:
            vnmdispTrickNameInfo[id][i].word[j].pos[0] =
                (cnt * cnt) * vnmdispTrickNameInfo[id][i].word[j].add[0];
            vnmdispTrickNameInfo[id][i].word[j].pos[1] =
                -(f32)(cnt * cnt) * vnmdispTrickNameInfo[id][i].word[j].add[1];
            break;
          default:
            vnmdispTrickNameInfo[id][i].word[j].pos[0] = 0.0f;
            vnmdispTrickNameInfo[id][i].word[j].pos[1] = 0.0f;
            break;
          }
        }
      }
    }
    switch (vnmdispTrickNameInfo[id][i].state) {
    case 2:
      if (vnmdispTrickNameInfo[id][i].num == 0) {
        vnmdispTrickNameInfo[id][i].state = 3;
      } else {
        search_num = rand() % vnmdispTrickNameInfo[id][i].num;
        if (vnmdispTrickNameInfo[id][i].word[search_num].state != 2) {
          tmp = 0;
          while (1) {
            search_num += 1;
            if (search_num == vnmdispTrickNameInfo[id][i].num) {
              search_num = 0;
            }
            if (vnmdispTrickNameInfo[id][i].word[search_num].state == 2) {
              break;
            }
            tmp += 1;
            if (tmp == vnmdispTrickNameInfo[id][i].num) {
              vnmdispTrickNameInfo[id][i].state = 3;
              break;
            }
          }
        }
        if (vnmdispTrickNameInfo[id][i].state != 3) {
          vnmdispTrickNameInfo[id][i].word[search_num].state = 3;
          vnmdispTrickNameInfo[id][i].word[search_num].cnt = 0;
          switch (vnmdispTrickEffectType[id]) {
          case 0:
            vnmdispTrickNameInfo[id][i].word[search_num].add[0] = 0.0f;
            vnmdispTrickNameInfo[id][i].word[search_num].add[1] = 0.15f;
            break;
          case 1:
            vnmdispTrickNameInfo[id][i].word[search_num].add[0] = 0.45000002f;
            vnmdispTrickNameInfo[id][i].word[search_num].add[1] =
                (0xA - (rand() % 20)) / 100.0f;
            break;
          case 2:
            vnmdispTrickNameInfo[id][i].word[search_num].add[0] = -0.45000002f;
            vnmdispTrickNameInfo[id][i].word[search_num].add[1] =
                (0xA - (rand() % 20)) / 100.0f;
            break;
          case 3:
            dir = 3.14926f / (vnmdispTrickNameInfo[id][i].num - 1);
            dir = 3.14926f - (dir * search_num);
            len = 0.2f * (1.0f + ((rand() % 30) / 100.0f));
            vnmdispTrickNameInfo[id][i].word[search_num].add[0] =
                len * cosf(dir);
            vnmdispTrickNameInfo[id][i].word[search_num].add[1] =
                len * sinf(dir);
            break;
          default:
            vnmdispTrickNameInfo[id][i].word[search_num].add[0] = 0.0f;
            vnmdispTrickNameInfo[id][i].word[search_num].add[1] = 0.0f;
            break;
          }
        }
      }
      break;
    case 3:
      tmp = 0;
      for (j = 0; j < vnmdispTrickNameInfo[id][i].num; j++) {
        tmp |= vnmdispTrickNameInfo[id][i].word[j].state;
      }
      if (tmp == 0) {
        vnmdispTrickNameInfo[id][i].state = 0;
      }
      break;
    }
    end_flag |= vnmdispTrickNameInfo[id][i].state;
  }
  return end_flag;
}

static void nmdispCalcTrickPts(signed int id) {
  signed int i;      // r16
  signed int tmp;    // r17
  char str_tmp[128]; // 0x30(r29)

  switch (vnmdispTrickPts[id].state) {
  case 1:
    if (vnmdispTrickPts[id].cnt == 0xA) {
      if (vnmdispTrickEnd[id] == 1) {
        if (vnmdispTrickSuccess[id] == 0) {
          ulstdSprintf(&str_tmp, "%d", vnmdispTrickPtsDraw[id].single);
          vnmdispTrickPtsInfo[id].state = 2;
          vnmdispTrickPtsInfo[id].num = strlen(&str_tmp);
          for (i = 0; i < vnmdispTrickPtsInfo[id].num; i++) {
            vnmdispTrickPtsInfo[id].word[i].state = 2;
            vnmdispTrickPtsInfo[id].word[i].cnt = 0;
            vnmdispTrickPtsInfo[id].word[i].str = str_tmp[i];
          }
        }
        vnmdispTrickPts[id].state = 3;
        vnmdispTrickPts[id].cnt = 0;
        return;
      }
      vnmdispTrickPts[id].state = 2;
      vnmdispTrickPts[id].cnt = 0;
      return;
    }
    vnmdispTrickPts[id].cnt += 1;
    return;
  case 2:
    switch (vnmdispTrickName[id].state) {
    case 1:
      break;
    case 2:
      if (vnmdispTrickPtsDraw[id].single < vspDispEnvChar[id].points.single) {
        tmp = (vspDispEnvChar[id].points.single -
               vnmdispTrickPtsDraw[id].single) /
              10;
        if (tmp < 0x11) {
          tmp = 0x11;
        }
        vnmdispTrickPtsDraw[id].single += tmp;
        if (vnmdispTrickPtsDraw[id].single > vspDispEnvChar[id].points.single) {
          vnmdispTrickPtsDraw[id].single = vspDispEnvChar[id].points.single;
          return;
        }
      } else {
        if (vnmdispTrickPtsDraw[id].single > vspDispEnvChar[id].points.single) {
          vnmdispTrickPtsDraw[id].single = vspDispEnvChar[id].points.single;
          return;
        }
      }
      break;
    default:
      if (vnmdispTrickSuccess[id] == 0) {
        ulstdSprintf(&str_tmp, "%d", vnmdispTrickPtsDraw[id].single);
        vnmdispTrickPtsInfo[id].state = 2;
        vnmdispTrickPtsInfo[id].num = strlen(&str_tmp);
        for (i = 0; vnmdispTrickPtsInfo[id].num > i; i++) {
          vnmdispTrickPtsInfo[id].word[i].state = 2;
          vnmdispTrickPtsInfo[id].word[i].cnt = 0;
          vnmdispTrickPtsInfo[id].word[i].str = str_tmp[i];
        }
      }
      vnmdispTrickPts[id].state = 3;
      vnmdispTrickPts[id].cnt = 0;
      return;
    }
    break;
  case 3:
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      if (vnmdispTrickPts[id].cnt == 0x78) {
        if (vnmdispTrickPtsDraw[id].single > 0) {
          tmp = vnmdispTrickPtsDraw[id].single / 10;
          if (tmp < 0x11) {
            tmp = 0x11;
          } else if (tmp >= 0x2711) {
            tmp = tmp / 2;
          }
          vnmdispTrickPtsDraw[id].single -= tmp;
          vnmdispTrickPtsDraw[id].total += tmp;
          if (vnmdispTrickPtsDraw[id].single < 0) {
            vnmdispTrickPtsDraw[id].single = 0;
          }
          if (vnmdispModeEnv->game_mode != 2) {
            if (vnmdispTrickPtsDraw[id].total >
                vspDispEnvChar[id].points.total) {
              vnmdispTrickPtsDraw[id].total = vspDispEnvChar[id].points.total;
            }
          } else if (vnmdispTrickPtsDraw[id].total >
                     vnmdispTrickPtsDraw[id].freeride) {
            vnmdispTrickPtsDraw[id].total = vnmdispTrickPtsDraw[id].freeride;
          }
          if (vnmdispTrickPtsDraw[id].single == 0) {
            vnmdispTrickPts[id].state = 4;
            vnmdispTrickPts[id].cnt = 0;
            return;
          }
        } else {
          vnmdispTrickPts[id].state = 4;
          vnmdispTrickPts[id].cnt = 0;
          return;
        }
      } else {
        vnmdispTrickPts[id].cnt += 1;
        return;
      }
      break;
    case 0:
      if (vnmdispTrickPts[id].cnt == 0x3C) {
        vnmdispTrickPts[id].state = 4;
        vnmdispTrickPts[id].cnt = 0;
        return;
      }
      vnmdispTrickPts[id].cnt += 1;
      return;
    }
    break;
  case 4:
    switch (vnmdispTrickSuccess[id]) {
    case 1:
      if (vnmdispTrickPts[id].cnt == 2) {
        vnmdispTrickPts[id].state = 0;
        vnmdispTrickPts[id].cnt = 0;
        return;
      }
      vnmdispTrickPts[id].cnt += 1;
      return;
    case 0:
      if (nmdispCalcTrickPtsFaild(id) == 0) {
        vnmdispTrickPts[id].state = 0;
        vnmdispTrickPts[id].cnt = 0;
      }
      break;
    }
    break;
  }
}

static char nmdispCalcTrickPtsFaild(signed int id) {
  signed int i;          // r16
  signed int cnt;        // r17
  signed int search_num; // r18
  signed int tmp;        // r19
  char end_flag;         // r20
  float dir;             // 0x68(r29)
  float len;             // 0x6C(r29)

  end_flag = 0;
  for (i = 0; i < vnmdispTrickPtsInfo[id].num; i++) {
    if (vnmdispTrickPtsInfo[id].word[i].state == 3) {
      if (vnmdispTrickPtsInfo[id].word[i].cnt == 0x14) {
        vnmdispTrickPtsInfo[id].word[i].state = 0;
        vnmdispTrickPtsInfo[id].word[i].cnt = 0;
        vnmdispTrickPtsInfo[id].word[i].pos[0] = 0.0f;
        vnmdispTrickPtsInfo[id].word[i].pos[1] = 0.0f;
      } else {
        vnmdispTrickPtsInfo[id].word[i].cnt += 1;
        cnt = vnmdispTrickPtsInfo[id].word[i].cnt;
        switch (vnmdispTrickEffectType[id]) {
        case 0:
          vnmdispTrickPtsInfo[id].word[i].pos[0] = 0.0f;
          vnmdispTrickPtsInfo[id].word[i].pos[1] =
              (cnt * cnt) * vnmdispTrickPtsInfo[id].word[i].add[1];
          break;
        case 1:
        case 2:
          vnmdispTrickPtsInfo[id].word[i].pos[0] =
              (cnt * cnt) * vnmdispTrickPtsInfo[id].word[i].add[0];
          vnmdispTrickPtsInfo[id].word[i].pos[1] =
              (cnt * cnt) * vnmdispTrickPtsInfo[id].word[i].add[1];
          break;
        case 3:
          vnmdispTrickPtsInfo[id].word[i].pos[0] =
              (cnt * cnt) * vnmdispTrickPtsInfo[id].word[i].add[0];
          vnmdispTrickPtsInfo[id].word[i].pos[1] =
              -(f32)(cnt * cnt) * vnmdispTrickPtsInfo[id].word[i].add[1];
          break;
        default:
          vnmdispTrickPtsInfo[id].word[i].pos[0] = 0.0f;
          vnmdispTrickPtsInfo[id].word[i].pos[1] = 0.0f;
          break;
        }
      }
    }
  }
  switch (vnmdispTrickPtsInfo[id].state) {
  case 2:
    if (vnmdispTrickPtsInfo[id].num == 0) {
      vnmdispTrickPtsInfo[id].state = 3;
    } else {
      search_num = rand() % vnmdispTrickPtsInfo[id].num;
      if (vnmdispTrickPtsInfo[id].word[search_num].state != 2) {
        tmp = 0;
        while (1) {
          search_num += 1;
          if (search_num == vnmdispTrickPtsInfo[id].num) {
            search_num = 0;
          }
          if (vnmdispTrickPtsInfo[id].word[search_num].state == 2) {
            break;
          }
          tmp += 1;
          if (tmp == vnmdispTrickPtsInfo[id].num) {
            vnmdispTrickPtsInfo[id].state = 3;
            break;
          }
        }
      }
      if (vnmdispTrickPtsInfo[id].state != 3) {
        vnmdispTrickPtsInfo[id].word[search_num].state = 3;
        vnmdispTrickPtsInfo[id].word[search_num].cnt = 0;
        switch (vnmdispTrickEffectType[id]) {
        case 0:
          vnmdispTrickPtsInfo[id].word[search_num].add[0] = 0.0f;
          vnmdispTrickPtsInfo[id].word[search_num].add[1] = 0.15f;
          break;
        case 1:
          vnmdispTrickPtsInfo[id].word[search_num].add[0] = 0.45000002f;
          vnmdispTrickPtsInfo[id].word[search_num].add[1] =
              (0xA - (rand() % 20)) / 100.0f;
          break;
        case 2:
          vnmdispTrickPtsInfo[id].word[search_num].add[0] = -0.45000002f;
          vnmdispTrickPtsInfo[id].word[search_num].add[1] =
              (0xA - (rand() % 20)) / 100.0f;
          break;
        case 3:
          dir = 3.14926f / (vnmdispTrickNameInfo[id][i].num - 1);
          dir = 3.14926f - (dir * search_num);
          len = 0.2f * (1.0f + ((rand() % 30) / 100.0f));
          vnmdispTrickPtsInfo[id].word[search_num].add[0] = len * cosf(dir);
          vnmdispTrickPtsInfo[id].word[search_num].add[1] = len * sinf(dir);
          break;
        default:
          vnmdispTrickPtsInfo[id].word[search_num].add[0] = 0.0f;
          vnmdispTrickPtsInfo[id].word[search_num].add[1] = 0.0f;
          break;
        }
      }
    }
    break;
  case 3:
    tmp = 0;
    for (i = 0; i < vnmdispTrickPtsInfo[id].num; i++) {
      tmp |= vnmdispTrickPtsInfo[id].word[i].state;
    }
    if (tmp == 0) {
      vnmdispTrickPtsInfo[id].state = 0;
    }
    break;
  }
  end_flag |= vnmdispTrickPtsInfo[id].state;
  return end_flag;
}
