// tmevent.c context
// Last updated 3/27/2025
// SPPS NTSC-U 201.99 Final

typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;
typedef unsigned int u_int;
typedef __int128 int128;
typedef __int128 s128;
typedef unsigned __int128 u_int128;

#define ABORT() asm(".word 0x0000000d")

// Pragma
// //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to
                      // float* types.
#pragma divbyzerocheck on

// SCE types
// /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned(16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned(16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

// Static data
// ///////////////////////////////////////////////////////////////////////

//////// vspRider Struct ///////////////////////////////////////////////
// Last updated: 08/14/2024

// Size: 0x30, DWARF: 0x7DAC1, 0x1C06F9
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
typedef struct Character_Param {
  signed int ollie;     // Offset: 0x0, DWARF: 0x7C61D
  signed int spin;      // Offset: 0x4, DWARF: 0x7C63F
  signed int speed;     // Offset: 0x8, DWARF: 0x7C660
  signed int landing;   // Offset: 0xC, DWARF: 0x7C682
  signed int balance;   // Offset: 0x10, DWARF: 0x7C6A6
  signed int stability; // Offset: 0x14, DWARF: 0x7C6CA
  signed int stance;    // Offset: 0x18, DWARF: 0x7C6F0
} Character_Param;

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

// Size: 0x48, DWARF: 0x7C763, 0x16EEA4
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

// Size: 0x8, DWARF: 0x168106
typedef struct Pad {
  unsigned short cnt; // Offset: 0x0, DWARF: 0x168121
  signed char lh;     // Offset: 0x2, DWARF: 0x168141
  signed char lv;     // Offset: 0x3, DWARF: 0x168160
  signed int analog;  // Offset: 0x4, DWARF: 0x16817F
} Pad;

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
  float rail_pos[4]
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
  float hp_normal[4];            // Offset: 0x3A0, DWARF: 0x77641
  float hp_cross[4];             // Offset: 0x3B0, DWARF: 0x77669
  signed int manual_ready;       // Offset: 0x3C0, DWARF: 0x77690
  signed int manual_ready_no;    // Offset: 0x3C4, DWARF: 0x776B9
  signed int manual_cnt_to_play; // Offset: 0x3C8, DWARF: 0x776E5
  // Size: 0x14, DWARF: 0x7C447
  Balance manu_balance;        // Offset: 0x3CC, DWARF: 0x77714
  signed int manu_reset_lean;  // Offset: 0x3E0, DWARF: 0x7773F
  signed int bonk_ready;       // Offset: 0x3E4, DWARF: 0x7776B
  signed int bonk_ready_no;    // Offset: 0x3E8, DWARF: 0x77792
  signed int bonk_goto;        // Offset: 0x3EC, DWARF: 0x777BC
  float bonk_point[4];         // Offset: 0x3F0, DWARF: 0x777E2
  float bonk_presp[4];         // Offset: 0x400, DWARF: 0x7780B
  signed int revert_cnt_ready; // Offset: 0x410, DWARF: 0x77834
  signed int revert_ready_no;  // Offset: 0x414, DWARF: 0x77861
  signed int plant_air;        // Offset: 0x418, DWARF: 0x7788D
  float plant_normal[4]
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
  float pos_waist[4]
      __attribute__((aligned(16))); // Offset: 0x460, DWARF: 0x77A46
  float pos_disp[4];                // Offset: 0x470, DWARF: 0x77A6E
  float shadow_posy;                // Offset: 0x480, DWARF: 0x77A95
  float max_speed;                  // Offset: 0x484, DWARF: 0x77ABD
  float cmn_max_speed;              // Offset: 0x488, DWARF: 0x77AE3
  float now_max_speed;              // Offset: 0x48C, DWARF: 0x77B0D
  // Size: 0x24, DWARF: 0x7C294
  Param2 param; // Offset: 0x490, DWARF: 0x77B37
  // Size: 0x1C, DWARF: 0x7C601
  Character_Param chr_param_x10; // Offset: 0x4B4, DWARF: 0x77B5B
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
  float mot_flip_rot[4]
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
  float balance_pole[4]
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
  float mat_head[4][4];                      // Offset: 0x1C30, DWARF: 0x7863B
  float mat_hip[4][4];                       // Offset: 0x1C70, DWARF: 0x78662
  // Size: 0x60, DWARF: 0x75E44
  Col col_rail; // Offset: 0x1CB0, DWARF: 0x78688
  // Size: 0x60, DWARF: 0x75E44
  Col col_plant; // Offset: 0x1D10, DWARF: 0x786AF
  // Size: 0x60, DWARF: 0x75E44
  Col col_hp; // Offset: 0x1D70, DWARF: 0x786D7
  // Size: 0x60, DWARF: 0x75E44
  Col col_zhp;                           // Offset: 0x1DD0, DWARF: 0x786FC
  float recover_pos[4];                  // Offset: 0x1E30, DWARF: 0x78722
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

// Size: 0x140, DWARF: 0x16DBF7
typedef struct Matrix {
  float local_screen[4][4]; // Offset: 0x0, DWARF: 0x16DC13
  float local_light[4][4];  // Offset: 0x40, DWARF: 0x16DC3E
  float light_color[4][4];  // Offset: 0x80, DWARF: 0x16DC68
  float local_clip[4][4];   // Offset: 0xC0, DWARF: 0x16DC92
  float clip_screen[4][4];  // Offset: 0x100, DWARF: 0x16DCBB
} Matrix;

// Size: 0x20, DWARF: 0x16D961
typedef struct Fog {
  float min;         // Offset: 0x0, DWARF: 0x16D97D
  float max;         // Offset: 0x4, DWARF: 0x16D99D
  float far;         // Offset: 0x8, DWARF: 0x16D9BD
  float near;        // Offset: 0xC, DWARF: 0x16D9DD
  signed int col[4]; // Offset: 0x10, DWARF: 0x16D9FE
} Fog;

// Size: 0x30, DWARF: 0x16C801
typedef struct ScreenInfo {
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
} ScreenInfo;

// Size: 0x340, DWARF: 0x167DF5
typedef struct SysMat {
  // Size: 0x30, DWARF: 0x16C801
  ScreenInfo scr_info; // Offset: 0x0, DWARF: 0x167E10
  // Size: 0x20, DWARF: 0x16D961
  Fog fog; // Offset: 0x30, DWARF: 0x167E37
  // Size: 0x140, DWARF: 0x16DBF7
  Matrix matrix;            // Offset: 0x50, DWARF: 0x167E59
  float world_screen[4][4]; // Offset: 0x190, DWARF: 0x167E7E
  float world_view[4][4];   // Offset: 0x1D0, DWARF: 0x167EA9
  float view_screen[4][4];  // Offset: 0x210, DWARF: 0x167ED2
  float light_color[4][4];  // Offset: 0x250, DWARF: 0x167EFC
  float normal_light[4][4]; // Offset: 0x290, DWARF: 0x167F26
  float view_clip[4][4];    // Offset: 0x2D0, DWARF: 0x167F51
  float cam_rot[4];         // Offset: 0x310, DWARF: 0x167F79
  float cam_trans[4];       // Offset: 0x320, DWARF: 0x167F9F
  float view_angle;         // Offset: 0x330, DWARF: 0x167FC7
} SysMat;

// Size: 0x24, DWARF: 0x167A72
typedef struct Key {
  signed int vibration; // Offset: 0x0, DWARF: 0x167A8D
  signed int spin_l;    // Offset: 0x4, DWARF: 0x167AB3
  signed int spin_r;    // Offset: 0x8, DWARF: 0x167AD6
  signed int stance;    // Offset: 0xC, DWARF: 0x167AF9
  signed int revert;    // Offset: 0x10, DWARF: 0x167B1C
  signed int grind;     // Offset: 0x14, DWARF: 0x167B3F
  signed int grab;      // Offset: 0x18, DWARF: 0x167B61
  signed int jump;      // Offset: 0x1C, DWARF: 0x167B82
  signed int flip;      // Offset: 0x20, DWARF: 0x167BA3
} Key;

// Size: 0x3C, DWARF: 0x167640
typedef struct Rider_State {
  signed int no;     // Offset: 0x0, DWARF: 0x16765B
  signed int player; // Offset: 0x4, DWARF: 0x16767A
  signed int wear;   // Offset: 0x8, DWARF: 0x16769D
  signed int board;  // Offset: 0xC, DWARF: 0x1676BE
  // Size: 0x1C, DWARF: 0x16D2B9
  Character_Param chr_param; // Offset: 0x10, DWARF: 0x1676E0
  // Size: 0x10, DWARF: 0x16DA24
  Board_Param brd_param; // Offset: 0x2C, DWARF: 0x167708
} Rider_State;

// Size: 0x14, DWARF: 0x16D54F
typedef struct Se {
  float splen;            // Offset: 0x0, DWARF: 0x16D56B
  float rot_pole;         // Offset: 0x4, DWARF: 0x16D58D
  float anggap_sp_brd;    // Offset: 0x8, DWARF: 0x16D5B2
  float anggap_board_rot; // Offset: 0xC, DWARF: 0x16D5DC
  signed int side_slide;  // Offset: 0x10, DWARF: 0x16D609
} Se __attribute__((aligned(16)));

// Size: 0x190, DWARF: 0x16B9B7
typedef struct Cam // Offset 2A40
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
} Cam;

// DWARF: 0x16ECC4
typedef enum FlipMode { eflReady, eflFlipping, eflEnd } FlipMode;

// Size: 0x20, DWARF: 0x16E73E
typedef struct KeyList {
  float rot[4];     // Offset: 0x0, DWARF: 0x16E75A
  signed int frame; // Offset: 0x10, DWARF: 0x16E77C
  signed int pad;   // Offset: 0x14, DWARF: 0x16E79E
  char padding[4];  // Not originally in struct
} KeyList;

// Size: 0x50, DWARF: 0x16F172
typedef struct Flip // Offset 28B0 + 110 = 29C0
{
  // Size: 0x20, DWARF: 0x16E73E
  KeyList *key_list; // Offset: 0x0, DWARF: 0x16F18E
  // Size: 0x20, DWARF: 0x16E73E
  KeyList now;          // Offset: 0x10, DWARF: 0x16F1B8
  signed int num_key;   // Offset: 0x30, DWARF: 0x16F1DA
  signed int num_frame; // Offset: 0x34, DWARF: 0x16F1FE
  // DWARF: 0x16ECC4
  FlipMode flipmode;   // Offset: 0x38, DWARF: 0x16F224
  signed int mot_id;   // Offset: 0x3C, DWARF: 0x16F24B
  signed int play_mot; // Offset: 0x40, DWARF: 0x16F26E
  int padding[7];      // Not originally in struct
} Flip __attribute__((aligned(16)));

// Size: 0x2C, DWARF: 0x16DF3B
typedef struct MotFrames // Offset 0x28B0
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
  Flip flip;                           // Offset: 0x110, DWARF: 0x1678D5
  signed int cnt_ik_foot;              // Offset: 0x160, DWARF: 0x1678F8
  signed int freemotion;               // Offset: 0x164, DWARF: 0x167920
  signed int ik;                       // Offset: 0x168, DWARF: 0x167947
  signed int reserve_schange;          // Offset: 0x16C, DWARF: 0x167966
  signed int reserve_brending_schange; // Offset: 0x170, DWARF: 0x167992
  signed int motion_speed;             // Offset: 0x174, DWARF: 0x1679C7
  signed int mot_sp_flip;              // Offset: 0x178, DWARF: 0x1679F0
  signed int trg_to_calc_flip;         // Offset: 0x17C, DWARF: 0x167A18
  signed int to_calc_flip;             // Offset: 0x180, DWARF: 0x167A45
} Mot;

// Size: 0x2C00, DWARF: 0x16AA87, 0xBAAA7, 0xDB58D
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
  Req nowreq; // Offset: 0x298, DWARF: 0x16AE17
  // Size: 0x48, DWARF: 0x16EEA4
  Req prereq; // Offset: 0x2E0, DWARF: 0x16AE3C
  // Size: 0x2580, DWARF: 0x168520
  Act act; // Offset: 0x330, DWARF: 0x76810
  // Size: 0x190, DWARF: 0x1677E9
  Mot mot; // Offset: 0x28B0, DWARF: 0x16AE83
  // Size: 0x190, DWARF: 0x16B9B7
  Cam cam; // Offset: 0x2A40, DWARF: 0x16AEA5
  // Size: 0x14, DWARF: 0x16D54F
  Se se __attribute__((aligned(16))); // Offset: 0x2BD0, DWARF: 0x16AEC7
  // Size: 0x3C, DWARF: 0x167640
  Rider_State *param; // Offset: 0x2BE4, DWARF: 0x16AEE8
  // Size: 0x24, DWARF: 0x167A72
  Key *key; // Offset: 0x2BE8, DWARF: 0x16AF0F
  // Size: 0x30, DWARF: 0x167BEE
  Cheats *cheats; // Offset: 0x2BEC, DWARF: 0x16AF34
  // Size: 0x340, DWARF: 0x167DF5
  SysMat *sys_mat; // Offset: 0x2BF0, DWARF: 0x16AF5C
} Ctrl;

// Size: 0x20, DWARF: 0x7EE12, 0xBA133
typedef struct ModelData {
  float pos[4]; // Offset: 0x0, DWARF: 0xBA14E
  float rot[4]; // Offset: 0x10, DWARF: 0xBA170
} ModelData;

// Size: 0x10, DWARF: 0x813DF, 0xBCA3C
typedef struct PosAddress //: const volatile float[4]
{
  unsigned int type; // Offset: 0x0, DWARF: 0xBCA58
  float frame;       // Offset: 0x4, DWARF: 0xBCA79
  signed short flg;  // Offset: 0x8, DWARF: 0xBCA9B
  signed short non;  // Offset: 0xA, DWARF: 0xBCABB
  float *data[4];    // Offset: 0xC, DWARF: 0xBCADB
} PosAddress;

// Size: 0x140, DWARF: 0x7DA36
typedef struct Wind {
  signed int count[8][3]
      __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x7DA52
  signed int speed[8][3];           // Offset: 0x60, DWARF: 0x7DA76
  float wave[8][4];                 // Offset: 0xC0, DWARF: 0x7DA9A
} Wind;

// Size: 0x8, DWARF: 0x7E8D5
typedef struct EnvFog {
  float a; // Offset: 0x0, DWARF: 0x7E8F1
  float b; // Offset: 0x4, DWARF: 0x7E90F
} EnvFog;

// Size: 0xF0, DWARF: 0x80315, 0xBB2C0
typedef struct Seq {
  unsigned int model_id;    // Offset: 0x0, DWARF: 0xBB2DC
  signed int loop;          // Offset: 0x4, DWARF: 0xBB301
  signed int mode;          // Offset: 0x8, DWARF: 0xBB322
  signed int write_flg;     // Offset: 0xC, DWARF: 0xBB343
  signed int now_local_id;  // Offset: 0x10, DWARF: 0xBB369
  signed int now_top_id;    // Offset: 0x14, DWARF: 0xBB392
  signed int next_local_id; // Offset: 0x18, DWARF: 0xBB3B9
  signed int next_top_id;   // Offset: 0x1C, DWARF: 0xBB3E3
  // Size: 0x20, DWARF: 0xBA133
  ModelData *mdl_data; // Offset: 0x20, DWARF: 0xBB40B
  float now_frame;     // Offset: 0x24, DWARF: 0xBB435
  float next_frame;    // Offset: 0x28, DWARF: 0xBB45B
  float ratio;         // Offset: 0x2C, DWARF: 0xBB482
  // Size: 0x10, DWARF: 0xBCA3C
  PosAddress *now_pos_address; // Offset: 0x30, DWARF: 0xBB4A4
  // Size: 0x10, DWARF: 0xBCA3C
  PosAddress *now_rot_address; // Offset: 0x34, DWARF: 0xBB4D5
  // Size: 0x10, DWARF: 0xBCA3C
  PosAddress *next_pos_address; // Offset: 0x38, DWARF: 0xBB506
  // Size: 0x10, DWARF: 0xBCA3C
  PosAddress *next_rot_address; // Offset: 0x3C, DWARF: 0xBB538
  float nowDir[4];              // Offset: 0x40, DWARF: 0xBB56A
  float nowTrans[4];            // Offset: 0x50, DWARF: 0xBB58F
  float now_matrix[4][4];       // Offset: 0x60, DWARF: 0xBB5B6
  float pos[4];                 // Offset: 0xA0, DWARF: 0xBB5DF
  float quat[4];                // Offset: 0xB0, DWARF: 0xBB601
  float pre_pos[4];             // Offset: 0xC0, DWARF: 0xBB624
  float pre_rot[4];             // Offset: 0xD0, DWARF: 0xBB64A
  signed int startVertexIdx;    // Offset: 0xE0, DWARF: 0xBB670
  signed int vertexLoopFlg;     // Offset: 0xE4, DWARF: 0xBB69B
  signed int pad[2];            // Offset: 0xE8, DWARF: 0xBB6C5
} Seq;

// Size: 0x8, DWARF: 0x7EB45
typedef struct EnvMap {
  unsigned long tex0; // Offset: 0x0, DWARF: 0x7EB61
} EnvMap;

// Size: 0x160, DWARF: 0x7D512
typedef struct Vmenv {
  unsigned int enable; // Offset: 0x0, DWARF: 0x7D52E
  // Size: 0x140, DWARF: 0x7DA36
  Wind wind; // Offset: 0x10, DWARF: 0x7D551
  // Size: 0x8, DWARF: 0x7E8D5
  EnvFog fog; // Offset: 0x150, DWARF: 0x7D574
  // Size: 0x8, DWARF: 0x7EB45
  EnvMap envmap; // Offset: 0x158, DWARF: 0x7D596
} Vmenv;

// Size: 0x230, DWARF: 0xFB1A1, 0x81827
typedef struct IkParam {
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
} IkParam;

// Size: 0x2E0, DWARF: 0x7CF19
typedef struct UmdCtrl {
  float rot[4];         // Offset: 0x0, DWARF: 0x7CF35
  float trans[4];       // Offset: 0x10, DWARF: 0x7CF57
  float scale[4];       // Offset: 0x20, DWARF: 0x7CF7B
  float matrix[4][4];   // Offset: 0x30, DWARF: 0x7CF9F
  float revision[4][4]; // Offset: 0x70, DWARF: 0x7CFC4
  // Size: 0x230, DWARF: 0x81827
  IkParam ikparam; // Offset: 0xB0, DWARF: 0x7CFEB
} UmdCtrl;

// Size: 0x24, DWARF: 0x80BCF
typedef struct UadList {
  __int128 *regular;  // Offset: 0x0, DWARF: 0x80BEB
  __int128 *fakie;    // Offset: 0x4, DWARF: 0x80C12
  __int128 *trick;    // Offset: 0x8, DWARF: 0x80C37
  __int128 *special;  // Offset: 0xC, DWARF: 0x80C5C
  __int128 *special2; // Offset: 0x10, DWARF: 0x80C83
  __int128 *special3; // Offset: 0x14, DWARF: 0x80CAB
  __int128 *special4; // Offset: 0x18, DWARF: 0x80CD3
  __int128 *special5; // Offset: 0x1C, DWARF: 0x80CFB
  __int128 *special6; // Offset: 0x20, DWARF: 0x80D23
} UadList;

// Size: 0x1A0, DWARF: 0x7C011
typedef struct SmdCtrl {
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
} SmdCtrl;

// Size: 0x90, DWARF: 0x7BE99
typedef struct ModelChange {
  float original[4][4];  // Offset: 0x0, DWARF: 0x7BEB5
  float original2[4][4]; // Offset: 0x40, DWARF: 0x7BEDC
  float *address[4][4];  // Offset: 0x80, DWARF: 0x7BF04
  float *address2[4][4]; // Offset: 0x84, DWARF: 0x7BF2D
  signed int pad[2];     // Offset: 0x88, DWARF: 0x7BF57
} ModelChange;

// Size: 0x2A30, DWARF: 0x7F8F0
typedef struct Disp {
  void *umd; // Offset: 0x0, DWARF: 0x7F90C
  void *utd; // Offset: 0x4, DWARF: 0x7F92F
  // Size: 0xF0, DWARF: 0x80315
  Seq *seq; // Offset: 0x8, DWARF: 0x7F952
  // Size: 0x24, DWARF: 0x80BCF
  UadList uad_list; // Offset: 0xC, DWARF: 0x7F977
  // Size: 0x160, DWARF: 0x7D512
  Vmenv vmenv; // Offset: 0x30, DWARF: 0x7F99E
  // Size: 0x2E0, DWARF: 0x7CF19
  UmdCtrl *umd_ctrl; // Offset: 0x190, DWARF: 0x7F9C2
  // Size: 0x1A0, DWARF: 0x7C011
  SmdCtrl *smd_ctrl; // Offset: 0x194, DWARF: 0x7F9EC
  // Size: 0x90, DWARF: 0x7BE99
  ModelChange *model_change; // Offset: 0x198, DWARF: 0x7FA16
  float scale;               // Offset: 0x19C, DWARF: 0x7FA44
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
  UmdCtrl *sub_umd_ctrl; // Offset: 0x285C, DWARF: 0x7FCC1
  // Size: 0x1A0, DWARF: 0x7C011
  SmdCtrl *sub_smd_ctrl; // Offset: 0x2860, DWARF: 0x7FCEF
  float normal_light0[4]
      __attribute__((aligned(16))); // Offset: 0x2870, DWARF: 0x7FD1D
  float normal_light1[4];           // Offset: 0x2880, DWARF: 0x7FD49
  float normal_light2[4];           // Offset: 0x2890, DWARF: 0x7FD75
  float light_color0[4];            // Offset: 0x28A0, DWARF: 0x7FDA1
  float light_color1[4];            // Offset: 0x28B0, DWARF: 0x7FDCC
  float light_color2[4];            // Offset: 0x28C0, DWARF: 0x7FDF7
  float ambient[4];                 // Offset: 0x28D0, DWARF: 0x7FE22
  float shadow[4];                  // Offset: 0x28E0, DWARF: 0x7FE48
  float mat_base_lw[4][4];          // Offset: 0x28F0, DWARF: 0x7FE6D
  float mat_board[4][4];            // Offset: 0x2930, DWARF: 0x7FE97
  float mat_hand_l[4][4];           // Offset: 0x2970, DWARF: 0x7FEBF
  float mat_hand_r[4][4];           // Offset: 0x29B0, DWARF: 0x7FEE8
  float mat_head[4][4];             // Offset: 0x29F0, DWARF: 0x7FF11
} Disp;

// Size: 0x5640, DWARF: 0x78FAB, 0x1BFCC8 // vspRider from  ktact.c
typedef struct Rider {
  // Size: 0x2A30, DWARF: 0x7F8F0, 0xBB1F1
  Disp disp; // Offset: 0x0, DWARF: 0x78FC6
  // Size: 0x2C00, DWARF: 0x7627B, 0xDB58D
  Ctrl ctrl; // Offset: 0x2A30, DWARF: 0x78FE9
  // char padding[48]; // This does not exist in the original struct, this is
  // added to match the expected offsets. Ctrl is supposed to be size 0x2C00.
  signed int pid;      // Offset: 0x5630, DWARF: 0x7900C
  signed int secondly; // Offset: 0x5634, DWARF: 0x7902C
} Rider;

// tmevent.c structs
// ////////////////////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0xDFB4F
// typedef struct Fog
// {
//     float min; // Offset: 0x0, DWARF: 0xDFB6B
//     float max; // Offset: 0x4, DWARF: 0xDFB8B
//     float far; // Offset: 0x8, DWARF: 0xDFBAB
//     float near; // Offset: 0xC, DWARF: 0xDFBCB
//     signed int col[4]; // Offset: 0x10, DWARF: 0xDFBEC
// } Fog;

// Size: 0x10, DWARF: 0xE2A01
typedef struct Course {
  // Size: 0x20, DWARF: 0xDFB4F
  Fog *fog;          // Offset: 0x0, DWARF: 0xE2A1D
  signed int no;     // Offset: 0x4, DWARF: 0xE2A42
  signed int res[2]; // Offset: 0x8, DWARF: 0xE2A61
} Course;

// Size: 0x60, DWARF: 0xD845C
typedef struct Object {
  float normal[4];       // Offset: 0x0, DWARF: 0xD8477
  float point[4];        // Offset: 0x10, DWARF: 0xD849C
  sceVu0FVECTOR *vertex; // Offset: 0x20, DWARF: 0xD84C0
  unsigned int attr;     // Offset: 0x24, DWARF: 0xD84E8
  signed int nvertex;    // Offset: 0x28, DWARF: 0xD8509
  signed int no;         // Offset: 0x2C, DWARF: 0xD852D
  float len;             // Offset: 0x30, DWARF: 0xD854C
  signed int rail_no;    // Offset: 0x34, DWARF: 0xD856C
  signed int obj_no;     // Offset: 0x38, DWARF: 0xD8590
  signed int obj_attr;   // Offset: 0x3C, DWARF: 0xD85B3
  signed int obj_type;   // Offset: 0x40, DWARF: 0xD85D8
  signed int res[4];     // Offset: 0x44, DWARF: 0xD85FD
  signed int padding[3];
} Object;

// Size: 0x34, DWARF: 0xD7BEE
typedef struct Character {
  signed int no;        // Offset: 0x0, DWARF: 0xD7C09
  signed int player;    // Offset: 0x4, DWARF: 0xD7C28
  signed int base_attr; // Offset: 0x8, DWARF: 0xD7C4B
  signed int nvector;   // Offset: 0xC, DWARF: 0xD7C71
  signed int nhit;      // Offset: 0x10, DWARF: 0xD7C95
  signed int nobj;      // Offset: 0x14, DWARF: 0xD7CB6
  signed int rail;      // Offset: 0x18, DWARF: 0xD7CD7
  signed int old_rail;  // Offset: 0x1C, DWARF: 0xD7CF8
  signed int res;       // Offset: 0x20, DWARF: 0xD7D1D
  // Size: 0x60, DWARF: 0xD845C
  Object *vector; // Offset: 0x24, DWARF: 0xD7D3D
  // Size: 0x60, DWARF: 0xD845C
  Object *hit; // Offset: 0x28, DWARF: 0xD7D65
  // Size: 0x60, DWARF: 0xD845C
  Object *object; // Offset: 0x2C, DWARF: 0xD7D8A
  // Size: 0x2C00, DWARF: 0xDB58D
  Ctrl *ctrl; // Offset: 0x30, DWARF: 0xD7DB2
} Character;

// Size: 0x14, DWARF: 0xDC00E
typedef struct Game {
  signed int player;  // Offset: 0x0, DWARF: 0xDC02A
  signed int nplayer; // Offset: 0x4, DWARF: 0xDC04D
  signed int pause;   // Offset: 0x8, DWARF: 0xDC071
  signed int mode;    // Offset: 0xC, DWARF: 0xDC093
  signed int wid;     // Offset: 0x10, DWARF: 0xDC0B4
} Game;

// Size: 0x8C, DWARF: 0xD7795
typedef struct Event {
  // Size: 0x10, DWARF: 0xE2A01
  Course course; // Offset: 0x0, DWARF: 0xD77B0
  // Size: 0x34, DWARF: 0xD7BEE
  Character character[2]; // Offset: 0x10, DWARF: 0xD77D5
  // Size: 0x14, DWARF: 0xDC00E
  Game game; // Offset: 0x78, DWARF: 0xD77FD
} Event;

// Size: 0x50, DWARF: 0xE1190
typedef struct VtmevSystem {
  signed int crs_no;               // Offset: 0x0, DWARF: 0xE11AC
  unsigned int level_goals[2];     // Offset: 0x4, DWARF: 0xE11CF
  unsigned int level_goals_tmp[2]; // Offset: 0xC, DWARF: 0xE11F9
  unsigned int old_level_goals[2]; // Offset: 0x14, DWARF: 0xE1227
  signed int res;                  // Offset: 0x1C, DWARF: 0xE1255
  unsigned long gaps[2];           // Offset: 0x20, DWARF: 0xE1275
  unsigned long gaps_tmp[2];       // Offset: 0x30, DWARF: 0xE1298
  signed int gap;                  // Offset: 0x40, DWARF: 0xE12BF
  signed int vs;                   // Offset: 0x44, DWARF: 0xE12DF
  signed int finish[2];            // Offset: 0x48, DWARF: 0xE12FE
} VtmevSystem;

// Size: 0x8, DWARF: 0xD8898
typedef struct VtmevVibData {
  char **common; // Offset: 0x0, DWARF: 0xD88B3
  char **event;  // Offset: 0x4, DWARF: 0xD88DA
} VtmevVibData;

// Size: 0x84, DWARF: 0xDEA19
typedef struct ObjectList {
  signed int nobj;       // Offset: 0x0, DWARF: 0xDEA35
  signed int obj_no[32]; // Offset: 0x4, DWARF: 0xDEA56
} ObjectList;

// Size: 0x320, DWARF: 0xDEB94
typedef struct VtmevObject {
  signed int get_logo; // Offset: 0x0, DWARF: 0xDEBB0
  signed int get_soft; // Offset: 0x4, DWARF: 0xDEBD5
  // Size: 0x84, DWARF: 0xDEA19
  ObjectList logo; // Offset: 0x8, DWARF: 0xDEBFA
  // Size: 0x84, DWARF: 0xDEA19
  ObjectList sponsor; // Offset: 0x8C, DWARF: 0xDEC1D
  // Size: 0x84, DWARF: 0xDEA19
  ObjectList arrow; // Offset: 0x110, DWARF: 0xDEC43
  // Size: 0x84, DWARF: 0xDEA19
  ObjectList vs; // Offset: 0x194, DWARF: 0xDEC67
  // Size: 0x84, DWARF: 0xDEA19
  ObjectList non_vs; // Offset: 0x218, DWARF: 0xDEC88
  // Size: 0x84, DWARF: 0xDEA19
  ObjectList warp; // Offset: 0x29C, DWARF: 0xDECAD
} VtmevObject;

// Size: 0x30, DWARF: 0xDF534
typedef struct Warp {
  signed int no;     // Offset: 0x0, DWARF: 0xDF550
  signed int se;     // Offset: 0x4, DWARF: 0xDF56F
  signed int hit_no; // Offset: 0x8, DWARF: 0xDF58E
  signed int se_no;  // Offset: 0xC, DWARF: 0xDF5B1
  float speed;       // Offset: 0x10, DWARF: 0xDF5D3
  float angle;       // Offset: 0x14, DWARF: 0xDF5F5
  char padding[8];   // pads rec_pos to 0x20, not originally here.
  float rec_pos[4];  // Offset: 0x20, DWARF: 0xDF617
} Warp;

// Size: 0x2A0, DWARF: 0xE0525
typedef struct VtmevVs {
  signed int lap[2];      // Offset: 0x0, DWARF: 0xE0541
  signed int now_warp[2]; // Offset: 0x8, DWARF: 0xE0563
  // Size: 0x30, DWARF: 0xDF534
  Warp warp[8];            // Offset: 0x10, DWARF: 0xE058A
  signed int nwarp;        // Offset: 0x190, DWARF: 0xE05AD
  signed int now_pos;      // Offset: 0x194, DWARF: 0xE05CF
  signed int nhorse;       // Offset: 0x198, DWARF: 0xE05F3
  signed int horse_enable; // Offset: 0x19C, DWARF: 0xE0616
  float boost_pos[2][4];   // Offset: 0x1A0, DWARF: 0xE063F
  float warp_pos[2][4];    // Offset: 0x1C0, DWARF: 0xE0667
  float horse_pos[12][4];  // Offset: 0x1E0, DWARF: 0xE068E
} VtmevVs;

// Size: 0x30, DWARF: 0xE264F
typedef struct VtmevCourse {
  signed int mipmdl_block; // Offset: 0x0, DWARF: 0xE266B
  float view_angle;        // Offset: 0x4, DWARF: 0xE2694
  float draw_length;       // Offset: 0x8, DWARF: 0xE26BB
  float obj_draw_length;   // Offset: 0xC, DWARF: 0xE26E3
  signed int fog;          // Offset: 0x10, DWARF: 0xE270F
  signed int bg_fog;       // Offset: 0x14, DWARF: 0xE272F
  signed int bg_draw;      // Offset: 0x18, DWARF: 0xE2752
  signed int bg_no;        // Offset: 0x1C, DWARF: 0xE2776
  signed int bg_col[4];    // Offset: 0x20, DWARF: 0xE2798
} VtmevCourse;

// Size: 0x5C, DWARF: 0xDB198
typedef struct VspModeData {
  // DWARF: 0xE1376
  FlowMode flow_mode;           // Offset: 0x0, DWARF: 0xDB1B4
  unsigned int game_time_limit; // Offset: 0x4, DWARF: 0xDB1DC
  unsigned int game_time;       // Offset: 0x8, DWARF: 0xDB208
  unsigned int game_count;      // Offset: 0xC, DWARF: 0xDB22E
  unsigned int realtime_count;  // Offset: 0x10, DWARF: 0xDB255
  unsigned int flow_count;      // Offset: 0x14, DWARF: 0xDB280
  signed int can_pause;         // Offset: 0x18, DWARF: 0xDB2A7
  signed int modnum;            // Offset: 0x1C, DWARF: 0xDB2CD
  signed int bgm_no;            // Offset: 0x20, DWARF: 0xDB2F0
  signed int replay_speed;      // Offset: 0x24, DWARF: 0xDB313
  signed int num_window;        // Offset: 0x28, DWARF: 0xDB33C
  signed int horse_pid;         // Offset: 0x2C, DWARF: 0xDB363
  signed int end_sliding;       // Offset: 0x30, DWARF: 0xDB389
  signed int pause;             // Offset: 0x34, DWARF: 0xDB3B1
  signed int pre_pause;         // Offset: 0x38, DWARF: 0xDB3D3
  // DWARF: 0xE1376
  FlowMode next_flow_mode; // Offset: 0x3C, DWARF: 0xDB3F9
  // DWARF: 0xD81E4
  Restart restart;              // Offset: 0x40, DWARF: 0xDB426
  signed int next_modnum;       // Offset: 0x44, DWARF: 0xDB44C
  signed int next_bgm_no;       // Offset: 0x48, DWARF: 0xDB474
  signed int fade;              // Offset: 0x4C, DWARF: 0xDB49C
  signed int to_end_sliding;    // Offset: 0x50, DWARF: 0xDB4BD
  signed int next_replay_speed; // Offset: 0x54, DWARF: 0xDB4E8
  signed int next_pause;        // Offset: 0x58, DWARF: 0xDB516
} VspModeData;

// Size: 0x4, DWARF: 0xE08FD
typedef struct CourseNo {
  signed int no; // Offset: 0x0, DWARF: 0xE0919
} CourseNo;

// Size: 0x1C, DWARF: 0xDEDC6
// typedef struct Character_Param
// {
//     signed int ollie; // Offset: 0x0, DWARF: 0xDEDE2
//     signed int spin; // Offset: 0x4, DWARF: 0xDEE04
//     signed int speed; // Offset: 0x8, DWARF: 0xDEE25
//     signed int landing; // Offset: 0xC, DWARF: 0xDEE47
//     signed int balance; // Offset: 0x10, DWARF: 0xDEE6B
//     signed int stability; // Offset: 0x14, DWARF: 0xDEE8F
//     signed int stance; // Offset: 0x18, DWARF: 0xDEEB5
// } Character_Param;

// Size: 0x10, DWARF: 0xDFC64
// typedef struct Board_Param
// {
//     signed int speed; // Offset: 0x0, DWARF: 0xDFC80
//     signed int stability; // Offset: 0x4, DWARF: 0xDFCA2
//     signed int balance; // Offset: 0x8, DWARF: 0xDFCC8
//     signed int turning; // Offset: 0xC, DWARF: 0xDFCEC
// } Board_Param;

// Size: 0x3C, DWARF: 0xD7AD4
typedef struct RiderState {
  signed int no;     // Offset: 0x0, DWARF: 0xD7AEF
  signed int player; // Offset: 0x4, DWARF: 0xD7B0E
  signed int wear;   // Offset: 0x8, DWARF: 0xD7B31
  signed int board;  // Offset: 0xC, DWARF: 0xD7B52
  // Size: 0x1C, DWARF: 0xDEDC6
  Character_Param chr_param; // Offset: 0x10, DWARF: 0xD7B74
  // Size: 0x10, DWARF: 0xDFC64
  Board_Param brd_param; // Offset: 0x2C, DWARF: 0xD7B9C
} RiderState;

// Size: 0x18, DWARF: 0xE0C5F
typedef struct Mode {
  signed int num_player;  // Offset: 0x0, DWARF: 0xE0C7B
  signed int game_mode;   // Offset: 0x4, DWARF: 0xE0CA2
  signed int match_rule;  // Offset: 0x8, DWARF: 0xE0CC8
  signed int divide;      // Offset: 0xC, DWARF: 0xE0CEF
  signed int handicap[2]; // Offset: 0x10, DWARF: 0xE0D12
} Mode;

// Size: 0xA0, DWARF: 0xDF7C0
typedef struct VspenvGame {
  // Size: 0x4, DWARF: 0xE08FD
  CourseNo course; // Offset: 0x0, DWARF: 0xDF7DC
  // Size: 0x3C, DWARF: 0xD7AD4
  RiderState character[2]; // Offset: 0x4, DWARF: 0xDF801
  // Size: 0x18, DWARF: 0xE0C5F
  Mode mode;           // Offset: 0x7C, DWARF: 0xDF829
  signed int language; // Offset: 0x94, DWARF: 0xDF84C
  signed int ending;   // Offset: 0x98, DWARF: 0xDF871
  signed int bgm_no;   // Offset: 0x9C, DWARF: 0xDF894
} VspenvGame;

// Size: 0x50, DWARF: 0xD8B96
typedef struct VtmevLight {
  float light_color[2][4];  // Offset: 0x0, DWARF: 0xD8BB2
  float normal_light[2][4]; // Offset: 0x20, DWARF: 0xD8BDC
  float ambient[4];         // Offset: 0x40, DWARF: 0xD8C07
} VtmevLight;

// Size: 0x74, DWARF: 0xDF98C
typedef struct CharacterCareer {
  signed int secret;          // Offset: 0x0, DWARF: 0xDF9A8
  unsigned int board;         // Offset: 0x4, DWARF: 0xDF9CB
  unsigned int course;        // Offset: 0x8, DWARF: 0xDF9ED
  signed int rem_point;       // Offset: 0xC, DWARF: 0xDFA10
  signed int old_brd_no;      // Offset: 0x10, DWARF: 0xDFA36
  signed int old_wear_no;     // Offset: 0x14, DWARF: 0xDFA5D
  unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0xDFA85
  signed int soft[8];         // Offset: 0x38, DWARF: 0xDFAAE
  // Size: 0x1C, DWARF: 0xDEDC6
  Character_Param parameter; // Offset: 0x58, DWARF: 0xDFAD1
} CharacterCareer;

// Size: 0x18, DWARF: 0xE1BF4
typedef struct Clock {
  signed int year;   // Offset: 0x0, DWARF: 0xE1C10
  signed int month;  // Offset: 0x4, DWARF: 0xE1C31
  signed int day;    // Offset: 0x8, DWARF: 0xE1C53
  signed int hour;   // Offset: 0xC, DWARF: 0xE1C73
  signed int minute; // Offset: 0x10, DWARF: 0xE1C94
  signed int second; // Offset: 0x14, DWARF: 0xE1CB7
} Clock;

// Size: 0xEC, DWARF: 0xE021A
typedef struct Create_Character {
  // Size: 0x74, DWARF: 0xDF98C
  CharacterCareer character; // Offset: 0x0, DWARF: 0xE0236
  // Size: 0x1C, DWARF: 0xDEDC6
  Character_Param init_param; // Offset: 0x74, DWARF: 0xE025E
  // Size: 0x18, DWARF: 0xE1BF4
  Clock clock;            // Offset: 0x90, DWARF: 0xE0287
  char name[16];          // Offset: 0xA8, DWARF: 0xE02AB
  signed int age;         // Offset: 0xB8, DWARF: 0xE02CE
  signed int sex;         // Offset: 0xBC, DWARF: 0xE02EE
  signed int face;        // Offset: 0xC0, DWARF: 0xE030E
  signed int hair;        // Offset: 0xC4, DWARF: 0xE032F
  signed int hair_color;  // Offset: 0xC8, DWARF: 0xE0350
  signed int body;        // Offset: 0xCC, DWARF: 0xE0377
  signed int body_color;  // Offset: 0xD0, DWARF: 0xE0398
  signed int pants;       // Offset: 0xD4, DWARF: 0xE03BF
  signed int pants_color; // Offset: 0xD8, DWARF: 0xE03E1
  signed int glove;       // Offset: 0xDC, DWARF: 0xE0409
  signed int boots;       // Offset: 0xE0, DWARF: 0xE042B
  signed int board_type;  // Offset: 0xE4, DWARF: 0xE044D
  signed int trick_type;  // Offset: 0xE8, DWARF: 0xE0474
} Create_Character;

// Size: 0x8, DWARF: 0xE19D1
typedef struct CourseGap {
  unsigned long gap; // Offset: 0x0, DWARF: 0xE19ED
} CourseGap;

// Size: 0xEF8, DWARF: 0xE0970
typedef struct VspenvSecret {
  // Size: 0x74, DWARF: 0xDF98C
  CharacterCareer character[12]; // Offset: 0x0, DWARF: 0xE098C
  // Size: 0xEC, DWARF: 0xE021A
  Create_Character create_character[10]; // Offset: 0x570, DWARF: 0xE09B4
  // Size: 0x8, DWARF: 0xE19D1
  CourseGap course[8];    // Offset: 0xEA8, DWARF: 0xE09E3
  signed int tour_round;  // Offset: 0xEE8, DWARF: 0xE0A08
  signed int old_char;    // Offset: 0xEEC, DWARF: 0xE0A2F
  signed int first_clear; // Offset: 0xEF0, DWARF: 0xE0A54
} VspenvSecret;

// Size: 0x20, DWARF: 0xDC12A
typedef struct VspDispEnv {
  signed int mode;      // Offset: 0x0, DWARF: 0xDC146
  signed int time_left; // Offset: 0x4, DWARF: 0xDC167
  signed int pass_time; // Offset: 0x8, DWARF: 0xDC18D
  signed int div;       // Offset: 0xC, DWARF: 0xDC1B3
  signed int div_exp;   // Offset: 0x10, DWARF: 0xDC1D3
  signed int res[3];    // Offset: 0x14, DWARF: 0xDC1F7
} VspDispEnv;

// Size: 0x38, DWARF: 0xE299A
typedef struct File {
  // Size: 0x18, DWARF: 0xE1BF4
  Clock clock;   // Offset: 0x0, DWARF: 0xE29B6
  char name[32]; // Offset: 0x18, DWARF: 0xE29DA
} File;

// Size: 0x8, DWARF: 0xD89AF
typedef struct Pad_Data {
  unsigned short cnt; // Offset: 0x0, DWARF: 0xD89CB
  signed char lh;     // Offset: 0x2, DWARF: 0xD89EB
  signed char lv;     // Offset: 0x3, DWARF: 0xD8A0A
  signed int analog;  // Offset: 0x4, DWARF: 0xD8A29
} Pad_Data;

// Size: 0x24, DWARF: 0xD808E
typedef struct KeyInputs {
  signed int vibration; // Offset: 0x0, DWARF: 0xD80A9
  signed int spin_l;    // Offset: 0x4, DWARF: 0xD80CF
  signed int spin_r;    // Offset: 0x8, DWARF: 0xD80F2
  signed int stance;    // Offset: 0xC, DWARF: 0xD8115
  signed int revert;    // Offset: 0x10, DWARF: 0xD8138
  signed int grind;     // Offset: 0x14, DWARF: 0xD815B
  signed int grab;      // Offset: 0x18, DWARF: 0xD817D
  signed int jump;      // Offset: 0x1C, DWARF: 0xD819E
  signed int flip;      // Offset: 0x20, DWARF: 0xD81BF
} KeyInputs;

// Size: 0x30, DWARF: 0xD827B
// typedef struct Cheats
// {
//     signed int kids; // Offset: 0x0, DWARF: 0xD8296
//     signed int always_sp; // Offset: 0x4, DWARF: 0xD82B7
//     signed int perfect_b; // Offset: 0x8, DWARF: 0xD82DD
//     signed int super_spin; // Offset: 0xC, DWARF: 0xD8303
//     signed int half_g; // Offset: 0x10, DWARF: 0xD832A
//     signed int fast_motion; // Offset: 0x14, DWARF: 0xD834D
//     signed int super_speed; // Offset: 0x18, DWARF: 0xD8375
//     signed int big_head; // Offset: 0x1C, DWARF: 0xD839D
//     signed int metallic; // Offset: 0x20, DWARF: 0xD83C2
//     signed int mirror; // Offset: 0x24, DWARF: 0xD83E7
//     signed int replay_view; // Offset: 0x28, DWARF: 0xD840A
//     signed int partition; // Offset: 0x2C, DWARF: 0xD8432
// } Cheats;

// Size: 0x2DCEC, DWARF: 0xDBDC5
typedef struct VspenvReplay {
  // Size: 0x38, DWARF: 0xE299A
  File file;               // Offset: 0x0, DWARF: 0xDBDE1
  signed int pid;          // Offset: 0x38, DWARF: 0xDBE04
  signed int num_frame;    // Offset: 0x3C, DWARF: 0xDBE24
  unsigned int game_time;  // Offset: 0x40, DWARF: 0xDBE4A
  signed int endrun_frame; // Offset: 0x44, DWARF: 0xDBE70
  // Size: 0x8, DWARF: 0xD89AF
  Pad_Data pad_data[23400]; // Offset: 0x48, DWARF: 0xDBE99
  // Size: 0x24, DWARF: 0xD808E
  KeyInputs key; // Offset: 0x2DB88, DWARF: 0xDBEC0
  // Size: 0xEC, DWARF: 0xE021A
  Create_Character character; // Offset: 0x2DBAC, DWARF: 0xDBEE2
  // Size: 0x30, DWARF: 0xD827B
  Cheats cheats;        // Offset: 0x2DC98, DWARF: 0xDBF0A
  signed int crs_no;    // Offset: 0x2DCC8, DWARF: 0xDBF2F
  signed int chr_no;    // Offset: 0x2DCCC, DWARF: 0xDBF52
  signed int wear_no;   // Offset: 0x2DCD0, DWARF: 0xDBF75
  signed int brd_no;    // Offset: 0x2DCD4, DWARF: 0xDBF99
  signed int game_mode; // Offset: 0x2DCD8, DWARF: 0xDBFBC
  // Size: 0x10, DWARF: 0xDFC64
  Board_Param brd_param; // Offset: 0x2DCDC, DWARF: 0xDBFE2
} VspenvReplay;

// Size: 0x210, DWARF: 0xDDA21
typedef struct VtmevCounter {
  signed int i_cnt[64]; // Offset: 0x0, DWARF: 0xDDA3D
  float f_cnt[64];      // Offset: 0x100, DWARF: 0xDDA61
  unsigned long i_flag; // Offset: 0x200, DWARF: 0xDDA85
  unsigned long f_flag; // Offset: 0x208, DWARF: 0xDDAA8
} VtmevCounter;

// Size: 0x190, DWARF: 0xE0156
typedef struct VtmevWarpSystem {
  signed int nwarp; // Offset: 0x0, DWARF: 0xE0172
  char padding[12]; // pads warp to 0x10, not originally in DWARF data.
  // Size: 0x30, DWARF: 0xDF534
  Warp warp[8]; // Offset: 0x10, DWARF: 0xE0194
} VtmevWarpSystem;

// Size: 0x9C, DWARF: 0xDDFEA
typedef struct EvData {
  unsigned int *link;           // Offset: 0x0, DWARF: 0xDE006
  unsigned char *replay_camera; // Offset: 0x4, DWARF: 0xDE02A
  unsigned char *intro_camera;  // Offset: 0x8, DWARF: 0xDE057
  unsigned char *accelerate;    // Offset: 0xC, DWARF: 0xDE083
  unsigned char *group;         // Offset: 0x10, DWARF: 0xDE0AD
  unsigned int *vib_link[2];    // Offset: 0x14, DWARF: 0xDE0D2
  char *vib_com[16];            // Offset: 0x1C, DWARF: 0xDE0F9
  char *vib_evt[16];            // Offset: 0x5C, DWARF: 0xDE11F
} EvData;

//// Variables
//////////////////////////////////////////////////////////////////////////

void(tmevDefEnd)();                   // Address: 0x1A4280
signed int(tmevDefFinishPlayerEvent)( // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x1A4260
signed int(tmevDefDrawPlayerEvent)(   // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x1A4240
signed int(tmevDefDrawEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x1A4220
signed int(tmevDefPlayerEvent)(       // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x1A4200
signed int(tmevDefMainEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x1A41E0
signed int(tmevDefResetEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x1A41C0
signed int(tmevDefInit)(              // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x1A41A0
void(spev08End)();                    // Address: 0x261B00
signed int(spev08FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x261AE0
signed int(spev08DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x261AC0
signed int(spev08DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x261A40
signed int(spev08PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x261810
signed int(spev08MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x260EC0
signed int(spev08ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x260B90
signed int(spev08Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x2605B0
void(spev07End)();                    // Address: 0x28AB60
signed int(spev07FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28AB40
signed int(spev07DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28AB20
signed int(spev07DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28A9E0
signed int(spev07PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28A4D0
signed int(spev07MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28A320
signed int(spev07ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x289E10
signed int(spev07Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x289B90
void(spev06End)();                    // Address: 0x27D510
signed int(spev06FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x27D4E0
signed int(spev06DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x27D4C0
signed int(spev06DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x27D400
signed int(spev06PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x27CF40
signed int(spev06MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x27C100
signed int(spev06ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x27BC70
signed int(spev06Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x27B4E0
void(spev05End)();                    // Address: 0x28D950
signed int(spev05FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28D8E0
signed int(spev05DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28D8C0
signed int(spev05DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28D730
signed int(spev05PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28C740
signed int(spev05MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28C150
signed int(spev05ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28B4B0
signed int(spev05Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x28ABF0
void(spev04End)();                    // Address: 0x249DC0
signed int(spev04FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x249D70
signed int(spev04DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x249D50
signed int(spev04DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x249C60
signed int(spev04PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x249B80
signed int(spev04MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x249500
signed int(spev04ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x2493B0
signed int(spev04Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x2491B0
void(spev03End)();                    // Address: 0x278080
signed int(spev03FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x278060
signed int(spev03DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x278040
signed int(spev03DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x277FC0
signed int(spev03PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x2755D0
signed int(spev03MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x274E10
signed int(spev03ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x2741E0
signed int(spev03Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x273CE0
void(spev02End)();                    // Address: 0x2690F0
signed int(spev02FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x2690B0
signed int(spev02DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x269090
signed int(spev02DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x269010
signed int(spev02PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x268F70
signed int(spev02MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x268E00
signed int(spev02ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x268CD0
signed int(spev02Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x268A90
void(spev01End)();                    // Address: 0x21D5B0
signed int(spev01FinishPlayerEvent)(  // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x21D570
signed int(spev01DrawPlayerEvent)(    // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x21D550
signed int(spev01DrawEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x21D480
signed int(spev01PlayerEvent)(        // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x21C660
signed int(spev01MainEvent)(          // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x21C060
signed int(spev01ResetEvent)(         // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x21BCA0
signed int(spev01Init)(               // Size: 0x8C, DWARF: 0xD7795
    Event *);                         // Address: 0x21B560
// Size: 0x5640, DWARF: 0xDCB87
extern Rider *vspRider[8]; // Address: 0x3BD480
// Size: 0x5C, DWARF: 0xDB198
extern VspModeData vspModeData; // Address: 0x3BF620
// Size: 0xA0, DWARF: 0xDF7C0
extern VspenvGame *vspenvGame; // Address: 0x2E7B14
// Size: 0xEF8, DWARF: 0xE0970
extern VspenvSecret *vspenvSecret;            // Address: 0x2E7B04
extern signed int vsptblLevelGoalValue[8][7]; // Address: 0x2B6A60
// Size: 0x20, DWARF: 0xDC12A
extern VspDispEnv vspDispEnv; // Address: 0x3BE570
// Size: 0x2DCEC, DWARF: 0xDBDC5
extern VspenvReplay *vspenvReplay[2]; // Address: 0x2E7B08

//// Function Declarations
//////////////////////////////////////////////////////////////

signed int tmevInit( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
signed int tmevReset( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
signed int tmevMainEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
signed int tmevPlayerEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
signed int tmevDrawEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
signed int tmevDrawPlayerEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
signed int tmevFinishPlayerEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
void tmevEnd();
static void tmevInitSystem( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
static void tmevResetSystem( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
void tmevSetLevelGoal(signed int player, signed int no);
void tmevSetGap(signed int player, signed int no);
static void tmevCheckLevelGoal( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
static void tmevCheckGap( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
unsigned int tmevGetLevelGoal(signed int player);
signed int tmevGetLevelGoalFlag(signed int no);
static void tmevInitCounter();
static void tmevCountCounter();
void tmevResetICounter(signed int no);
signed int tmevGetICounter(signed int no);
void tmevSetICounter(signed int no, signed int value);
void tmevStartICounter(signed int no);
void tmevStopICounter(signed int no);
void tmevResetFlag();
void tmevSetFlag(signed int no, signed int value);
signed int tmevGetFlag(signed int no);
void tmevSetFog(signed int fog, signed int player);
void tmevSetBGFog(signed int fog, signed int player);
void tmevSetBGNo(signed int no, signed int player);
void tmevSetViewAngle(float view_angle, signed int player);
void tmevSetDrawLength(float length, signed int player);
float tmevGetDrawLength(signed int player);
void tmevSetObjectDrawLength(float length, signed int player);
void tmevSetMiPModelLevel(signed int block, signed int player);
static void tmevResetObject();
static void tmevMoveObject( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
void tmevSetCourseLogo(signed int no);
static void tmevRollCourseLogo();
void tmevSetSponsor(signed int sp_no, signed int obj_no);
static void tmevResetSponsor();
static void tmevRollSponsor();
void tmevSetWarpArrow(signed int no);
static void tmevMoveWarpArrow();
void tmevSetVsObject(signed int no);
void tmevSet1PlayObject(signed int no);
void tmevSetVsWarpObject(signed int no);
signed int tmevGetEventMdlHit( // Size: 0x2C00, DWARF: 0xDB58D
    Ctrl *rider, signed int no, float len, signed int unused);
static void tmevInitWarp();
void tmevSetWarp(float *rec_pos, float angle, signed int hit, signed int se,
                 float speed);
static void tmevCheck1PWarp( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
static void tmevCheckReset( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
static void tmevInitVs();
static void tmevResetVs();
void tmevSetWarpNo(signed int no, signed int se);
void tmevSetStartPosition(float x, float y, float z, float angle,
                          signed int player);
void tmevSetWarpPosition(float x, float y, float z, float angle,
                         signed int player);
void tmevSetHorsePosition(float x, float y, float z, float angle);
signed int tmevGetNowHorsePos();
signed int tmevGetLap(signed int player);
void tmevResetHorsePosition(signed int first);
static void tmevCheckVsWarp( // Size: 0x8C, DWARF: 0xD7795
    Event *event);
signed int tmevGetFinish(signed int player);
void tmevSetVib( // Size: 0x8C, DWARF: 0xD7795
    Event *event, signed int type, signed int no, signed int id);
void tmevSetVibPlayer( // Size: 0x8C, DWARF: 0xD7795
    Event *event, signed int type, signed int no, signed int id,
    signed int player);
signed int tmevGetIntroCut();
void tmevSetLightVector(float *light_color, float *normal_light, signed int id,
                        signed int player);
void tmevSetAmbient(float *ambient, signed int player);
void tmevGetLightVector(sceVu0FMATRIX light_color, sceVu0FMATRIX normal_light,
                        float *ambient, signed int player);
static signed int tmevDefInit();
static signed int tmevDefResetEvent();
static signed int tmevDefMainEvent();
static signed int tmevDefPlayerEvent();
static signed int tmevDefDrawEvent();
static signed int tmevDefDrawPlayerEvent();
static signed int tmevDefFinishPlayerEvent();
static void tmevDefEnd();

// Included functions //////////////////////////
void tmcrsSetViewAngle(float angle);
void tmcrsSetDrawLength(float length);
void tmcrsSetObjectDrawLength(float length);

void spRiderSetPos2(Rider *rider, float *pos, float roty);
void ktactSetRecover(signed int pid, float *pos, float roty, float speed,
                     signed int warp);
void nmeventPlayWarp(signed int player, signed int se);

//// tmevent bss and sbss, declared highest address first
///////////////////////////////

// Size: 0x50, DWARF: 0xE1190
VtmevSystem vtmevSystem; // Address: 0x3C0B90
// Size: 0x190, DWARF: 0xE0156
VtmevWarpSystem vtmevWarpSystem; // Address: 0x3C0A00
// Size: 0x2A0, DWARF: 0xE0525
VtmevVs vtmevVs; // Address: 0x3C0760
// Size: 0x210, DWARF: 0xDDA21
VtmevCounter vtmevCounter; // Address: 0x3C0550
signed int vtmevFlag[256]; // Address: 0x3C0150
// Size: 0x320, DWARF: 0xDEB94
VtmevObject vtmevObject; // Address: 0x3BFE30
// Size: 0x30, DWARF: 0xE264F
VtmevCourse vtmevCourse[2]; // Address: 0x3BFDD0
// Size: 0x50, DWARF: 0xD8B96
VtmevLight vtmevLight[2]; // Address: 0x3BFD30

signed int (*vtmevInit)(Event *);         // Address: 0x2E7BB0
signed int (*vtmevReset)(Event *);        // Address: 0x2E7BAC
signed int (*vtmevMain)(Event *);         // Address: 0x2E7BA8
signed int (*vtmevPlayer)(Event *);       // Address: 0x2E7BA4
signed int (*vtmevDraw)(Event *);         // Address: 0x2E7BA0
signed int (*vtmevDrawPlayer)(Event *);   // Address: 0x2E7B9C
signed int (*vtmevFinishPlayer)(Event *); // Address: 0x2E7B98
void (*vtmevEnd)();                       // Address: 0x2E7B94
void (*vtmevWarp)(Event *);               // Address: 0x2E7B90
// Size: 0x8, DWARF: 0xD8898
VtmevVibData vtmevVibData; // Address: 0x2E7B88

//// Function Definitions ///////////////////////////////////////////

EvData *sploadGetGameEtc();

int tmevInit(Event *event) {
  // Size: 0x9C, DWARF: 0xDDFEA
  EvData *data; // r16

  vtmevWarp = 0;
  data = sploadGetGameEtc();
  vtmevVibData.common = (data)[0].vib_com;
  vtmevVibData.event = data->vib_evt;

  vtmevSystem.crs_no = event->course.no;
  if (1 < event->game.nplayer) {
    vtmevSystem.vs = 1;
  } else {
    vtmevSystem.vs = 0;
  }
  tmevInitVs(event);
  tmevInitWarp();
  switch (vtmevSystem.crs_no) {
  case 0:
    vtmevInit = spev01Init;
    vtmevReset = spev01ResetEvent;
    vtmevMain = spev01MainEvent;
    vtmevPlayer = spev01PlayerEvent;
    vtmevDraw = spev01DrawEvent;
    vtmevDrawPlayer = spev01DrawPlayerEvent;
    vtmevFinishPlayer = spev01FinishPlayerEvent;
    vtmevEnd = spev01End;
    break;
  case 1:
    vtmevInit = spev02Init;
    vtmevReset = spev02ResetEvent;
    vtmevMain = spev02MainEvent;
    vtmevPlayer = spev02PlayerEvent;
    vtmevDraw = spev02DrawEvent;
    vtmevDrawPlayer = spev02DrawPlayerEvent;
    vtmevFinishPlayer = spev02FinishPlayerEvent;
    vtmevEnd = spev02End;
    break;
  case 2:
    vtmevInit = spev03Init;
    vtmevReset = spev03ResetEvent;
    vtmevMain = spev03MainEvent;
    vtmevPlayer = spev03PlayerEvent;
    vtmevDraw = spev03DrawEvent;
    vtmevDrawPlayer = spev03DrawPlayerEvent;
    vtmevFinishPlayer = spev03FinishPlayerEvent;
    vtmevEnd = spev03End;
    break;
  case 3:
    vtmevInit = spev04Init;
    vtmevReset = spev04ResetEvent;
    vtmevMain = spev04MainEvent;
    vtmevPlayer = spev04PlayerEvent;
    vtmevDraw = spev04DrawEvent;
    vtmevDrawPlayer = spev04DrawPlayerEvent;
    vtmevFinishPlayer = spev04FinishPlayerEvent;
    vtmevEnd = spev04End;
    break;
  case 4:
    vtmevInit = spev05Init;
    vtmevReset = spev05ResetEvent;
    vtmevMain = spev05MainEvent;
    vtmevPlayer = spev05PlayerEvent;
    vtmevDraw = spev05DrawEvent;
    vtmevDrawPlayer = spev05DrawPlayerEvent;
    vtmevFinishPlayer = spev05FinishPlayerEvent;
    vtmevEnd = spev05End;
    break;
  case 5:
    vtmevInit = spev06Init;
    vtmevReset = spev06ResetEvent;
    vtmevMain = spev06MainEvent;
    vtmevPlayer = spev06PlayerEvent;
    vtmevDraw = spev06DrawEvent;
    vtmevDrawPlayer = spev06DrawPlayerEvent;
    vtmevFinishPlayer = spev06FinishPlayerEvent;
    vtmevEnd = spev06End;
    break;
  case 6:
    vtmevInit = spev07Init;
    vtmevReset = spev07ResetEvent;
    vtmevMain = spev07MainEvent;
    vtmevPlayer = spev07PlayerEvent;
    vtmevDraw = spev07DrawEvent;
    vtmevDrawPlayer = spev07DrawPlayerEvent;
    vtmevFinishPlayer = spev07FinishPlayerEvent;
    vtmevEnd = spev07End;
    break;
  case 7:
    vtmevInit = spev08Init;
    vtmevReset = spev08ResetEvent;
    vtmevMain = spev08MainEvent;
    vtmevPlayer = spev08PlayerEvent;
    vtmevDraw = spev08DrawEvent;
    vtmevDrawPlayer = spev08DrawPlayerEvent;
    vtmevFinishPlayer = spev08FinishPlayerEvent;
    vtmevEnd = spev08End;
    break;
  default:
    vtmevInit = tmevDefInit;
    vtmevReset = tmevDefResetEvent;
    vtmevMain = tmevDefMainEvent;
    vtmevPlayer = tmevDefPlayerEvent;
    vtmevDraw = tmevDefDrawEvent;
    vtmevDrawPlayer = tmevDefDrawPlayerEvent;
    vtmevFinishPlayer = tmevDefFinishPlayerEvent;
    vtmevEnd = tmevDefEnd;
    break;
  }
  nmeventInit();
  tmevInitSystem(event);
  vtmevInit(event);
  return 0;
}

s32 tmevReset(Event *event) {
  signed int ii; // r16
  unsigned int time_tbl[8] = {0x2BF20, 0x2BF20, 0x33450, 0x33450,
                              0x3A980, 0x3A980, 0x493E0, 0x493E0}; // 0x50(r29)
  unsigned int *timetbl_ptr = time_tbl;
  unsigned int vs_time[8] = {0x50910, 0x493E0, 0x493E0, 0x4E200,
                             0x51C98, 0x53020, 0x57E40, 0x4E200}; // 0x70(r29)
  unsigned int *vstimetbl_ptr = vs_time;
  signed int ret; // r19
  float tmp[4];   // 0x90(r29)

  (void)timetbl_ptr;
  (void)vstimetbl_ptr;
  ret = 0;
  for (ii = 0; ii < 2; ii++) {
    event->character[ii].old_rail = -1;
    vtmevSystem.finish[ii] = 0;
  }
  tmevResetSystem(event);
  for (ii = 0; ii < 2; ii++) {
    vtmevLight[ii].normal_light[0][0] = 1.0f;
    vtmevLight[ii].normal_light[0][1] = 1.0f;
    vtmevLight[ii].normal_light[0][2] = -1.0f;
    vtmevLight[ii].normal_light[0][3] = 1.0f;
    vtmevLight[ii].light_color[0][0] = 0.2f;
    vtmevLight[ii].light_color[0][1] = 0.2f;
    vtmevLight[ii].light_color[0][2] = 0.2f;
    vtmevLight[ii].light_color[0][3] = 1.0f;
    vtmevLight[ii].normal_light[1][0] = 0.0f;
    vtmevLight[ii].normal_light[1][1] = 0.0f;
    vtmevLight[ii].normal_light[1][2] = 0.0f;
    vtmevLight[ii].normal_light[1][3] = 1.0f;
    vtmevLight[ii].light_color[1][0] = 0.0f;
    vtmevLight[ii].light_color[1][1] = 0.0f;
    vtmevLight[ii].light_color[1][2] = 0.0f;
    vtmevLight[ii].light_color[1][3] = 1.0f;
    vtmevLight[ii].ambient[0] = 0.4f;
    vtmevLight[ii].ambient[1] = 0.4f;
    vtmevLight[ii].ambient[2] = 0.4f;
    vtmevLight[ii].ambient[3] = 0.0f;
  }
  tmcrsSetDrawMipMapNo(1);
  if (vtmevSystem.vs == 1) {
    if (vspenvGame->mode.match_rule == 1) {
      vspModeData.game_time_limit = vs_time[event->course.no];
    } else if (vspenvGame->mode.match_rule == 3) {
      vspModeData.game_time_limit = 0x2710;
    } else {
      vspModeData.game_time_limit = time_tbl[event->course.no];
    }
  } else {
    vspModeData.game_time_limit = time_tbl[event->course.no];
  }
  tmevInitCounter();
  tmevResetFlag();
  tmevResetObject();
  tmcrsResetRailCollision();
  tmcrsReset();
  for (ii = 0; ii < 2; ii++) {
    vtmevCourse[ii].bg_fog = 0;
    vtmevCourse[ii].bg_draw = 1;
    vtmevCourse[ii].bg_no = 0;
    vtmevCourse[ii].bg_col[0] = 0x80;
    vtmevCourse[ii].bg_col[1] = 0x80;
    vtmevCourse[ii].bg_col[2] = 0x80;
    vtmevCourse[ii].bg_col[3] = 0x80;
    vtmevCourse[ii].view_angle = -1.0f;
    vtmevCourse[ii].draw_length = 3600.0f;
    vtmevCourse[ii].obj_draw_length = 3600.0f;
    vtmevCourse[ii].fog = 1;
    vtmevCourse[ii].mipmdl_block = 4;
  }
  vtmevVs.nwarp = 0;
  vtmevReset(event);
  if (vtmevSystem.vs == 1) {
    tmevResetVs(event);
  } else {
    tmp[0] = vtmevVs.boost_pos[0][0];
    tmp[1] = vtmevVs.boost_pos[0][1];
    tmp[2] = vtmevVs.boost_pos[0][2];
    tmp[3] = 1.0f;
    spRiderSetPos2(vspRider[0], tmp, vtmevVs.boost_pos[0][3]);
  }
  if (vtmevSystem.vs == 1) {
    for (ii = 0; ii < vtmevObject.non_vs.nobj; ii++) {
      tmcrsSetObjectDrawFlag(vtmevObject.non_vs.obj_no[ii], 0);
    }
  } else {
    for (ii = 0; ii < vtmevObject.vs.nobj; ii++) {
      tmcrsSetObjectDrawFlag(vtmevObject.vs.obj_no[ii], 0);
    }
  }
  tmevResetSponsor();
  if (event->game.mode != 2) {
    vtmevSystem.gap = 1;
  } else {
    vtmevSystem.gap = 1;
  }
  return ret;
}

s32 tmevMainEvent(Event *event) {
  signed int ii;      // r16
  signed int id;      // r17
  signed int draw;    // r18
  signed int ret = 0; // r19

  tmcrsResetScrollAnimTex();
  if (event->game.pause == 0) {
    tmevMoveObject(event);
    tmcrsResetHitCollision();
  }
  vtmevMain(event);
  if (event->game.pause == 0) {
    tmevCountCounter();
  }
  if (vtmevSystem.vs == 1) {
    if (vspenvGame->mode.match_rule == 3) {
      id = event->game.player;
    } else {
      // Modulo optimization
      // temp_v1 = event->game.wid + 1;
      // id = temp_v1 & 1;
      // if ((temp_v1 < 0) && (id != 0)) {
      //     id -= 2;
      // }
      id = (event->game.wid + 1) % 2;
    }
    if (tmevGetLap(id) == 3) {
      draw = 0;
    } else {
      draw = 1;
    }
    if (vspenvGame->mode.match_rule == 3) {
      draw = 0;
    }
    for (ii = 0; ii < vtmevObject.warp.nobj; ii++) {
      tmcrsSetObjectDrawFlag(vtmevObject.warp.obj_no[ii], draw);
    }
  } else {
    id = 0;
  }

  tmcrsSetBGFog(vtmevCourse[id].bg_fog);
  tmcrsSetBGDrawFlag(vtmevCourse[id].bg_draw);
  tmcrsSetBGColor(vtmevCourse[id].bg_col[0], vtmevCourse[id].bg_col[1],
                  vtmevCourse[id].bg_col[2]);
  tmcrsSetBGNo(vtmevCourse[id].bg_no);
  tmcrsSetFog(vtmevCourse[id].fog);
  tmcrsSetViewAngle(vtmevCourse[id].view_angle);
  tmcrsSetDrawLength(vtmevCourse[id].draw_length);
  tmcrsSetObjectDrawLength(vtmevCourse[id].draw_length);
  tmcrsSetMipModelLevel(vtmevCourse[id].mipmdl_block);
  return ret;
}

s32 tmevPlayerEvent(Event *event) {
  signed int player;  // r16
  signed int ret = 0; // r17

  // event = event;
  player = event->game.player;
  if ((event->character[player].old_rail != -1) &&
      (event->character[player].ctrl->act.sliding_state != essPlant) &&
      (event->character[player].ctrl->act.sliding_state != essGrind) &&
      (event->character[player].ctrl->act.sliding_state != essStandUp) &&
      (event->character[player].ctrl->act.sliding_state != 3)) {
    event->character[player].old_rail = -1;
  }
  if (event->character[player].ctrl->act.trg_bonk != 0) {
    event->character[player].rail = -1;
    event->character[player].old_rail = -1;
  }
  vtmevPlayer(event);
  if ((event->character[player].ctrl->act.sliding_state == essPlant) &&
      (event->character[player].old_rail == -1)) {
    event->character[player].old_rail = event->character[player].rail;
  }
  if ((event->character[player].ctrl->act.sliding_state == essGrind) &&
      (event->character[player].old_rail == -1)) {
    event->character[player].old_rail = event->character[player].rail;
  }
  if ((event->character[player].ctrl->act.sliding_state == essGrind) &&
      (event->character[player].old_rail != event->character[player].rail)) {
    event->character[player].old_rail = event->character[player].rail;
  }
  if ((event->game.mode != 2) && (event->game.nplayer == 1)) {
    tmevCheckLevelGoal(event);
  }
  if (event->game.mode != 2) {
    tmevCheckGap(event);
  }
  tmevCheckReset(event);
  if (vtmevSystem.vs == 1) {
    tmevCheckVsWarp(event);
  } else {
    tmevCheck1PWarp(event);
  }
  return ret;
}

s32 tmevDrawEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *event) {
  signed int ret = 0; // r16
  ret = vtmevDraw(event);
  return ret;
}

s32 tmevDrawPlayerEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *event) {
  signed int ret = 0; // r16
  ret = vtmevDrawPlayer(event);
  return ret;
}

s32 tmevFinishPlayerEvent(Event *event) {
  signed int player;       // r16
  signed int time;         // r17
  signed int tmp;          // r18
  signed int ret;          // r19
  unsigned int level_goal; // r20
  signed int score;        // r21

  ret = 0;
  player = event->game.player;
  vtmevSystem.finish[player] = 1;
  ret = vtmevFinishPlayer(event);
  if (event->game.mode != 2) {
    tmp = event->character[player].no;
    if (event->game.nplayer == 1) {
      score = event->character[player].ctrl->act.trick_link.total_trick_point;
      time = vspDispEnv.time_left;
      if (time == -1) {
        time = 0x12C;
      }
      if ((time >= vsptblLevelGoalValue[event->course.no][3]) &&
          (score >= vsptblLevelGoalValue[event->course.no][4]) &&
          (event->character[player].ctrl->act.pass_finish_line == 1)) {
        tmevSetLevelGoal(player, 3);
      }
      if (tmp < 12) {
        level_goal = vspenvSecret->character[tmp].level_goal[event->course.no] |
                     tmevGetLevelGoal(player);
      } else {
        level_goal = vspenvSecret->create_character[tmp - 12]
                         .character.level_goal[event->course.no] |
                     tmevGetLevelGoal(player);
      }
      (void)(level_goal == 0x1FF);
    }
    vspenvSecret->course[event->course.no].gap |= vtmevSystem.gaps[player];
  }
  return ret;
}

void tmevEnd() { vtmevEnd(); }

static void tmevInitSystem(Event *event) {
  signed int ii;  // r16
  signed int tmp; // r17

  for (ii = 0; ii < 2; ii++) {
    vtmevSystem.level_goals[ii] = 0;
    vtmevSystem.level_goals_tmp[ii] = 0;
    vtmevSystem.gaps[ii] = 0;
    vtmevSystem.gaps_tmp[ii] = 0;
  }
  for (ii = 0; ii < event->game.nplayer; ii++) {
    tmp = event->character[ii].no;
    vtmevSystem.level_goals_tmp[ii] =
        vspenvReplay[ii]->character.character.level_goal[vtmevSystem.crs_no];
    vtmevSystem.old_level_goals[ii] = vtmevSystem.level_goals_tmp[ii];
  }
}

static void tmevResetSystem(Event *event) {
  signed int ii; // r16

  if (event->game.mode == 0) {
    for (ii = 0; ii < 2; ii++) {
      vtmevSystem.level_goals_tmp[ii] |= vtmevSystem.level_goals[ii];
      vtmevSystem.level_goals[ii] = 0;
    }
  }
  if (event->game.mode == 2) {
    for (ii = 0; ii < 2; ii++) {
      vtmevSystem.level_goals_tmp[ii] = vtmevSystem.old_level_goals[ii];
    }
  } else {
    for (ii = 0; ii < 2; ii++) {
      vtmevSystem.old_level_goals[ii] = vtmevSystem.level_goals_tmp[ii];
      vspenvReplay[ii]->character.character.level_goal[vtmevSystem.crs_no] =
          vtmevSystem.level_goals_tmp[ii];
    }
  }
}

void tmevSetLevelGoal(s32 player, s32 no) {
  if (vspenvGame->mode.game_mode == 0) {
    if ((vtmevSystem.level_goals_tmp[player] & (1 << no)) == 0) {
      nmdispInputLevel(no);
      vtmevSystem.level_goals[player] |= (1 << no);
      vtmevSystem.level_goals_tmp[player] |= (1 << no);
    }
  }
}

void ktactSetGap(signed int pid, signed short gap_no);

void tmevSetGap(s32 player, s32 no) {
  if (vtmevSystem.gap == 1) {
    vtmevSystem.gaps_tmp[player] |= ((unsigned long)1 << (unsigned long)no);
    if (tmevGetFinish(player) == 0) {
      ktactSetGap(player, no);
    }
  }
}

static void tmevCheckLevelGoal(Event *event /* sp70 */) {
  signed int ii;           // r16 // s0
  signed int player;       // r17 // s1
  signed int score;        // r18 // s2
  signed int tmp;          // r19 // s3
  unsigned int level_goal; // r20 // s4

  // Size: 0xEF8, DWARF: 0xE0970
  VspenvSecret *secret; // Not in the dwarf info // s5

  player = event->game.player;
  tmp = event->character[player].no;
  score = event->character[player].ctrl->act.trick_link.total_trick_point;
  for (ii = 0; ii < 3; ii++) {
    if (score >= vsptblLevelGoalValue[event->course.no][ii] &&
        ((1 << ii) & tmevGetLevelGoal(player)) == 0) {
      tmevSetLevelGoal(player, ii);
    }
  }
  if (tmp < 0xC) {

    secret = &vspenvSecret->character[tmp].secret + event->course.no;
    level_goal = tmevGetLevelGoal(player) | secret->character[0].level_goal[0];
  } else {
    secret = &((Create_Character *)vspenvSecret)[tmp - 12].character.secret +
             event->course.no;
    level_goal =
        (tmevGetLevelGoal(player) | secret->character[12].level_goal[0]);
  }

  if (level_goal == 0x1FF) {
  }

  (void)level_goal;
  (void)level_goal;
  (void)tmp;
}

void tmevCheckGap(Event *event) {
  signed int player = event->game.player; // r16

  if (vtmevSystem.gaps_tmp[player] != 0) {
    if (event->character[player].ctrl->act.trk_link_state == elsSuccess) {
      vtmevSystem.gaps[player] |= vtmevSystem.gaps_tmp[player];
      vtmevSystem.gaps_tmp[player] = 0;
      return;
    }
    if (event->character[player].ctrl->act.trk_link_state == elsFailure) {
      vtmevSystem.gaps_tmp[player] = 0;
    }
  }
}

unsigned int tmevGetLevelGoal(s32 player) {
  return vtmevSystem.level_goals[player];
}

s32 tmevGetLevelGoalFlag(s32 no) {
  signed int ret; // r16

  ret = 0;
  if (((vspenvGame->mode.game_mode == 0) ||
       (vspenvGame->mode.game_mode == 2)) &&
      (vtmevSystem.level_goals_tmp[0] & (1 << no))) {
    ret = 1;
  }
  return ret;
}

void tmevInitCounter() {
  signed int ii; // r16

  for (ii = 0; ii < 0x40; ii++) {
    vtmevCounter.i_cnt[ii] = 0;
    vtmevCounter.f_cnt[ii] = 0.0f;
  }
  vtmevCounter.i_flag = 1;
  vtmevCounter.f_flag = 1;
}

void tmevCountCounter() {
  signed int ii; // r16

  for (ii = 0; ii < 0x40; ii++) {
    if ((vtmevCounter.i_flag >> ii) & 1) {
      vtmevCounter.i_cnt[ii] += 1;
    }
    if ((vtmevCounter.f_flag >> ii) & 1) {
      vtmevCounter.f_cnt[ii] += 1.0f;
    }
  }
}

void tmevResetICounter(s32 no) {
  if (no != 0) {
    tmevSetICounter(no, 0);
  }
}

s32 tmevGetICounter(s32 no) { return vtmevCounter.i_cnt[no]; }

void tmevSetICounter(s32 no, s32 value) {
  if (no != 0) {
    vtmevCounter.i_cnt[no] = value;
  }
}

void tmevStartICounter(s32 no) {
  if (no != 0) {
    vtmevCounter.i_flag |= ((unsigned long)1 << (unsigned long)no);
  }
}

void tmevStopICounter(s32 no) {
  if (no != 0) {
    vtmevCounter.i_flag &= ~((unsigned long)1 << ((unsigned long)no));
  }
}

void tmevResetFlag() {
  signed int ii; // r16

  for (ii = 0; ii < 256; ii++) {
    vtmevFlag[ii] = 0;
  }
}

void tmevSetFlag(s32 no, s32 value) { vtmevFlag[no] = value; }

s32 tmevGetFlag(s32 no) { return vtmevFlag[no]; }

void tmevSetFog(s32 fog, s32 player) { vtmevCourse[player].fog = fog; }

void tmevSetBGFog(s32 fog, s32 player) { vtmevCourse[player].bg_fog = fog; }

void tmevSetBGNo(s32 no, s32 player) { vtmevCourse[player].bg_no = no; }

void tmevSetViewAngle(f32 view_angle, s32 player) {
  vtmevCourse[player].view_angle = view_angle;
}

void tmevSetDrawLength(f32 length, s32 player) {
  vtmevCourse[player].draw_length = length;
  vtmevCourse[player].obj_draw_length = length;
}

f32 tmevGetDrawLength(s32 player) { return vtmevCourse[player].draw_length; }

void tmevSetObjectDrawLength(f32 length, s32 player) {
  vtmevCourse[player].obj_draw_length = length;
}

void tmevSetMiPModelLevel(s32 block, s32 player) {
  vtmevCourse[player].mipmdl_block = block;
}

void tmevResetObject() {
  signed int ii; // r16

  vtmevObject.logo.nobj = 0;
  vtmevObject.get_logo = 0;
  for (ii = 0; ii < 0x20; ii++) {
    vtmevObject.logo.obj_no[ii] = -1;
  }
  vtmevObject.sponsor.nobj = 0;
  vtmevObject.get_soft = 0;
  for (ii = 0; ii < 0x20; ii++) {
    vtmevObject.sponsor.obj_no[ii] = -1;
  }
  vtmevObject.arrow.nobj = 0;
  for (ii = 0; ii < 0x20; ii++) {
    vtmevObject.arrow.obj_no[ii] = -1;
  }
  vtmevObject.vs.nobj = 0;
  vtmevObject.non_vs.nobj = 0;
  vtmevObject.warp.nobj = 0;
  for (ii = 0; ii < 0x20; ii++) {
    vtmevObject.vs.obj_no[ii] = -1;
    vtmevObject.non_vs.obj_no[ii] = -1;
    vtmevObject.warp.obj_no[ii] = -1;
  }
}

void nmdispInputLevelCount(signed int now, signed int total, signed int num);
signed int tmcrsGetObjectDrawFlag(signed int no);

void tmevMoveObject(Event *event) {
  signed int jj; // r16
  signed int ii; // r17
  float tmp[4];  // 0x30(r29)
  float pos[4];  // 0x40(r29)

  // event = event; // sp50
  for (ii = 0; ii < event->character[0].nobj; ii++) {
    for (jj = 0; jj < vtmevObject.logo.nobj; jj++) {
      if ((vtmevObject.logo.obj_no[jj] ==
           event->character[0].object[ii].obj_no) &&
          (tmcrsGetObjectDrawFlag(vtmevObject.logo.obj_no[jj]) != 0)) {
        tmcrsSetObjectDrawFlag(vtmevObject.logo.obj_no[jj], 0);
        vtmevObject.get_logo += 1;
        if (vtmevObject.get_logo == vtmevObject.logo.nobj) {
          if (event->game.mode != 2) {
            tmevSetLevelGoal(0, 4);
          }
        } else {
          nmdispInputLevelCount(vtmevObject.get_logo, vtmevObject.logo.nobj, 4);
        }
      }
    }
    for (jj = 0; jj < 0x20; jj++) {
      if ((vtmevObject.sponsor.obj_no[ii] != -1) &&
          (vtmevObject.sponsor.obj_no[jj] ==
           event->character[0].object[ii].obj_no)) {
        tmcrsSetObjectDrawFlag(vtmevObject.sponsor.obj_no[jj], 0);
        vtmevObject.get_soft = vtmevObject.get_soft + 1;
        if (event->game.mode != 2) {
          tmevSetLevelGoal(0, 5);
        }
      }
    }
  }
  sceVu0CopyVector(&pos[0], event->character[0].ctrl->nowpos);
  pos[1] -= 10.0f;
  for (ii = 0; ii < vtmevObject.logo.nobj; ii++) {
    if (tmcrsGetObjectDrawFlag(vtmevObject.logo.obj_no[ii]) != 0) {
      tmcrsGetObjectPosition(&tmp[0], vtmevObject.logo.obj_no[ii]);
      sceVu0SubVector(&tmp[0], &tmp[0], &pos[0]);
      sceVu0MulVector(&tmp[0], &tmp[0], &tmp[0]);
      if (tmp[0] + tmp[1] + tmp[2] < 400.0f) {
        tmcrsSetObjectDrawFlag(vtmevObject.logo.obj_no[ii], 0);
        vtmevObject.get_logo += 1;
        if (vtmevObject.get_logo == vtmevObject.logo.nobj) {
          if (event->game.mode != 2) {
            tmevSetLevelGoal(0, 4);
          }
        } else {
          nmdispInputLevelCount(vtmevObject.get_logo, vtmevObject.logo.nobj, 4);
        }
      }
    }
  }
  for (ii = 0; ii < 0x20; ii++) {
    if ((vtmevObject.sponsor.obj_no[ii] != -1) &&
        (tmcrsGetObjectDrawFlag(vtmevObject.sponsor.obj_no[ii]) != 0)) {
      tmcrsGetObjectPosition(&tmp[0], vtmevObject.sponsor.obj_no[ii]);
      sceVu0SubVector(&tmp[0], &tmp[0], &pos[0]);
      sceVu0MulVector(&tmp[0], &tmp[0], &tmp[0]);
      if (tmp[0] + tmp[1] + tmp[2] < 400.0f) {
        tmcrsSetObjectDrawFlag(vtmevObject.sponsor.obj_no[ii], 0);
        vtmevObject.get_soft = vtmevObject.get_soft + 1;
        if (event->game.mode != 2) {
          tmevSetLevelGoal(0, 5);
        }
      }
    }
  }
  tmevRollCourseLogo();
  tmevRollSponsor();
  tmevMoveWarpArrow();
}

void tmevSetCourseLogo(signed int no) {
  vtmevObject.logo.obj_no[vtmevObject.logo.nobj] = no;
  if ((vtmevSystem.level_goals_tmp[0] & 0x10) || (vspenvGame->mode.game_mode)) {
    tmcrsSetObjectDrawFlag(no, 0);
  }
  tmcrsSetObjectAttr(no, 0);
  vtmevObject.logo.nobj++;
}

static void tmevRollCourseLogo(void) {
  signed int ii;  // r16
  float rot[4];   // 0x20(r29)
  float trans[4]; // 0x30(r29)

  rot[0] = 0.0f;
  rot[1] = 0.01f;
  rot[2] = 0.0f;
  rot[3] = 1.0f;
  trans[0] = 0.0f;
  trans[1] = 0.0f;
  trans[2] = 0.0f;
  trans[3] = 1.0f;
  for (ii = 0; ii < vtmevObject.logo.nobj; ii++) {
    tmcrsMoveObject(vtmevObject.logo.obj_no[ii], &rot[0], &trans[0], 0);
  }
}

void tmevSetSponsor(signed int sp_no, signed int obj_no) {
  vtmevObject.sponsor.obj_no[sp_no] = obj_no;
  tmcrsSetObjectDrawFlag(obj_no, 0);
  tmcrsSetObjectAttr(obj_no, 0);
}

static void tmevResetSponsor() {
  signed int chr_no; // r16
  signed int sp_tbl[8][13] = {
      {1, 3, 5, 2, 9, 7, 7, 13, 16, 18, 19, 21, 21},
      {2, 4, 6, 7, 10, 11, 12, 14, 17, 22, 20, 22, 22},
      {1, 3, 5, 8, 9, 7, 7, 0xF, 16, 18, 22, 21, 21},
      {2, 4, 6, 2, 10, 11, 12, 13, 17, 22, 19, 22, 22},
      {1, 3, 5, 7, 9, 7, 7, 14, 16, 18, 20, 21, 21},
      {2, 4, 6, 8, 10, 11, 12, 0xF, 17, 22, 22, 22, 22},
      {1, 3, 5, 2, 9, 7, 7, 13, 16, 18, 19, 21, 21},
      {2, 4, 6, 7, 10, 11, 12, 14, 17, 22, 20, 22, 22}}; // 0x40(r29)
  signed int *sp_tbl_ptr = &sp_tbl[0][0];
  signed int sp_no; // r18

  (void)sp_tbl_ptr;

  if ((vtmevSystem.level_goals_tmp[0] & 0x20) == 0 &&
      (vspenvGame->mode.game_mode == 0)) {
    if (vspenvGame->character[0].no < 12) {
      chr_no = vspenvGame->character[0].no;
    } else {
      chr_no = 12;
    }

    sp_no = sp_tbl[vtmevSystem.crs_no][chr_no] - 1;
    tmcrsSetObjectDrawFlag(vtmevObject.sponsor.obj_no[sp_no], 1);
  }
}

static void tmevRollSponsor() {
  signed int ii;  // r16
  float rot[4];   // 0x20(r29)
  float trans[4]; // 0x30(r29)

  rot[0] = 0.0f;
  rot[1] = 0.01f;
  rot[2] = 0.0f;
  rot[3] = 1.0f;
  trans[0] = 0.0f;
  trans[1] = 0.0f;
  trans[2] = 0.0f;
  trans[3] = 1.0f;
  for (ii = 0; ii < 0x20; ii++) {
    if ((vtmevObject.sponsor.obj_no[ii] != -1) &&
        (tmcrsGetObjectDrawFlag(vtmevObject.sponsor.obj_no[ii]) == 1)) {
      tmcrsMoveObject(vtmevObject.sponsor.obj_no[ii], &rot[0], &trans[0], 0);
    }
  }
}

void tmevSetWarpArrow(signed int no) {
  vtmevObject.arrow.obj_no[vtmevObject.arrow.nobj] = no;
  vtmevObject.arrow.nobj = vtmevObject.arrow.nobj + 1;
  tmcrsSetObjectAttr(no, 0);
}

static void tmevMoveWarpArrow() {
  signed int ii;  // r16
  float rot[4];   // 0x20(r29)
  float trans[4]; // 0x30(r29)
  float mov;      // 0x4C(r29)

  if (tmevGetICounter(0) % 0x20 < 0x10) {
    mov = -0.9375f;
  } else {
    mov = 0.9375f;
  }
  rot[0] = 0.0f;
  rot[1] = 0.02f;
  rot[2] = 0.0f;
  rot[3] = 1.0f;
  trans[0] = 0.0f;
  trans[1] = mov;
  trans[2] = 0.0f;
  trans[3] = 1.0f;
  for (ii = 0; ii < vtmevObject.arrow.nobj; ii++) {
    tmcrsMoveObject(vtmevObject.arrow.obj_no[ii], &rot[0], &trans[0], 0);
  }
}

void tmevSetVsObject(signed int no) {
  vtmevObject.vs.obj_no[vtmevObject.vs.nobj] = no;
  vtmevObject.vs.nobj++;
}

// tmevent.c
void tmevSet1PlayObject(signed int no) {
  vtmevObject.non_vs.obj_no[vtmevObject.non_vs.nobj] = no;
  vtmevObject.non_vs.nobj++;
}

// tmevent.c
void tmevSetVsWarpObject(signed int no) {
  vtmevObject.warp.obj_no[vtmevObject.warp.nobj] = no;
  vtmevObject.warp.nobj++;
}

signed int tmcrsGetEventModelHit(float *pos, signed int no, float len);

s32 tmevGetEventMdlHit( // Size: 0x2C00, DWARF: 0xDB58D
    Ctrl *rider, signed int no, float len, signed int unused) {
  signed int ret; // r16
  ret = tmcrsGetEventModelHit(rider->nowpos.pos, no, len);
  return ret;
}

void tmevInitWarp() {
  signed int ii; // r16

  vtmevWarpSystem.nwarp = 0;
  for (ii = 0; ii < 8; ii++) {
    vtmevWarpSystem.warp[ii].hit_no = 0;
    vtmevWarpSystem.warp[ii].se_no = 0;
    vtmevWarpSystem.warp[ii].speed = 0.0f;
    vtmevWarpSystem.warp[ii].angle = 0.0f;
    vtmevWarpSystem.warp[ii].rec_pos[0] = 0.0f;
    vtmevWarpSystem.warp[ii].rec_pos[1] = 0.0f;
    vtmevWarpSystem.warp[ii].rec_pos[2] = 0.0f;
    vtmevWarpSystem.warp[ii].rec_pos[3] = 0.0f;
  }
}

void tmevSetWarp(float *rec_pos, f32 angle, s32 hit, s32 se, f32 speed) {
  // Size: 0x30, DWARF: 0xDF534
  Warp *warp = &vtmevWarpSystem.warp[vtmevWarpSystem.nwarp]; // r16

  sceVu0CopyVector(warp->rec_pos, rec_pos);
  warp->angle = angle;
  warp->hit_no = hit;
  warp->se_no = se;
  warp->speed = speed;
  vtmevWarpSystem.nwarp += 1;
}

static void tmevCheck1PWarp(Event *event) {
  signed int jj; // r16
  signed int ii; // r17

  for (ii = 0; ii < event->character[0].nhit; ii++) {
    for (jj = 0; jj < vtmevWarpSystem.nwarp; jj++) {
      if (vtmevWarpSystem.warp[jj].hit_no == event->character[0].hit[ii].no) {
        ktactSetRecover(0, &vtmevWarpSystem.warp[jj].rec_pos[0],
                        vtmevWarpSystem.warp[jj].angle,
                        vtmevWarpSystem.warp[jj].speed, 1);
        nmeventPlayWarp(0, vtmevWarpSystem.warp[jj].se_no);
      }
    }
  }
}

void ktactSetRecover(signed int pid, float *pos, float roty, float speed,
                     signed int warp);

static void tmevCheckReset( // Size: 0x8C, DWARF: 0xD7795
    Event *event) {
  signed int player; // r16
  signed int ii;     // r17
  // Size: 0x60, DWARF: 0xD845C
  Object *vector; // r18
  float tmp[4];   // 0x40(r29)

  // event = event; // 50
  player = event->game.player;
  vector = event->character[player].vector;
  for (ii = 0; ii < event->character[player].nvector; ii++) {
    if (vector[ii].attr == 0x1D) {
      tmp[0] = vtmevVs.boost_pos[player][0];
      tmp[1] = vtmevVs.boost_pos[player][1];
      tmp[2] = vtmevVs.boost_pos[player][2];
      tmp[3] = 1.0f;
      ktactSetRecover(player, tmp, vtmevVs.boost_pos[player][3], 0.0f, 1);
      if (event->character[player].ctrl->act.pass_finish_line2 == 0) {
        nmdispInputOutMes(player);
      }
      break;
    }
  }
}

static void tmevInitVs(int unused) {
  signed int ii; // r16

  for (ii = 0; ii < 2; ii++) {
    vtmevVs.lap[ii] = 1;
  }
  for (ii = 0; ii < 8; ii++) {
    vtmevVs.warp[ii].no = -1;
    vtmevVs.warp[ii].se = -1;
  }
  vtmevVs.now_pos = -1;
  vtmevVs.nwarp = 0;
  vtmevVs.nhorse = 0;
  vtmevVs.horse_enable = 0;
  for (ii = 0; ii < 2; ii++) {
    vtmevVs.boost_pos[ii][0] = 0.0f;
    vtmevVs.boost_pos[ii][1] = 0.0f;
    vtmevVs.boost_pos[ii][2] = 0.0f;
    vtmevVs.boost_pos[ii][3] = 0.0f;
  }
  for (ii = 0; ii < 0xC; ii++) {
    vtmevVs.horse_pos[ii][0] = 0.0f;
    vtmevVs.horse_pos[ii][1] = 0.0f;
    vtmevVs.horse_pos[ii][2] = 0.0f;
    vtmevVs.horse_pos[ii][3] = 0.0f;
  }
}

void spRiderSetPos2(Rider *rider, float *pos, float roty);
static void tmevResetVs(int unused) {
  signed int ii; // r16
  float pos[4];  // 0x20(r29)

  switch (vspenvGame->mode.match_rule) {
  case 1:
    for (ii = 0; ii < 2; ii++) {
      vtmevVs.lap[ii] = 1;
      vtmevVs.now_warp[ii] = 0;
      pos[0] = vtmevVs.boost_pos[ii][0];
      pos[1] = vtmevVs.boost_pos[ii][1];
      pos[2] = vtmevVs.boost_pos[ii][2];
      pos[3] = 1.0f;
      spRiderSetPos2(vspRider[ii], pos, vtmevVs.boost_pos[ii][3]);
    }
    break;
  case 3:
    for (ii = 0; ii < 2; ii++) {
      if (vtmevVs.now_pos == -1) {
        pos[0] = 0.0f;
        pos[1] = 0.0f;
        pos[2] = 0.0f;
        pos[3] = 1.0f;
      } else {
        pos[0] = vtmevVs.horse_pos[vtmevVs.now_pos][0];
        pos[1] = vtmevVs.horse_pos[vtmevVs.now_pos][1];
        pos[2] = vtmevVs.horse_pos[vtmevVs.now_pos][2];
        pos[3] = 1.0f;
      }
      spRiderSetPos2(vspRider[ii], pos, vtmevVs.horse_pos[vtmevVs.now_pos][3]);
    }
    break;
  default:
    for (ii = 0; ii < 2; ii++) {
      vtmevVs.now_warp[ii] = 0;
      pos[0] = vtmevVs.boost_pos[ii][0];
      pos[1] = vtmevVs.boost_pos[ii][1];
      pos[2] = vtmevVs.boost_pos[ii][2];
      pos[3] = 1.0f;
      spRiderSetPos2(vspRider[ii], pos, vtmevVs.boost_pos[ii][3]);
    }
    break;
  }
}

void tmevSetWarpNo(s32 no, s32 se) {
  vtmevVs.warp[vtmevVs.nwarp].no = no;
  vtmevVs.warp[vtmevVs.nwarp].se = se;
  vtmevVs.nwarp += 1;
}

void tmevSetStartPosition(float x, float y, float z, float angle,
                          signed int player) {
  vtmevVs.boost_pos[player][0] = x;
  vtmevVs.boost_pos[player][1] = y;
  vtmevVs.boost_pos[player][2] = z;
  vtmevVs.boost_pos[player][3] = angle;
  vtmevVs.warp_pos[player][0] = x;
  vtmevVs.warp_pos[player][1] = y;
  vtmevVs.warp_pos[player][2] = z;
  vtmevVs.warp_pos[player][3] = angle;
}

void tmevSetWarpPosition(float x, float y, float z, float angle,
                         signed int player) {
  vtmevVs.warp_pos[player][0] = x;
  vtmevVs.warp_pos[player][1] = y;
  vtmevVs.warp_pos[player][2] = z;
  vtmevVs.warp_pos[player][3] = angle;
}

void tmevSetHorsePosition(float x, float y, float z, float angle) {
  vtmevVs.horse_pos[vtmevVs.nhorse][0] = x;
  vtmevVs.horse_pos[vtmevVs.nhorse][1] = y;
  vtmevVs.horse_pos[vtmevVs.nhorse][2] = z;
  vtmevVs.horse_pos[vtmevVs.nhorse][3] = angle;
  vtmevVs.nhorse++;
}

s32 tmevGetNowHorsePos() { return vtmevVs.now_pos; }

s32 tmevGetLap(signed int player /* r29 */) { return vtmevVs.lap[player]; }

void tmevResetHorsePosition(s32 first) {
  signed int tmp;  // r16
  signed int ii;   // r17
  signed int flag; // r18

  flag = 0;
  for (ii = 0; ii < 0xC; ii++) {
    flag |= 1 << ii;
  }
  if (first == 1) {
    vtmevVs.horse_enable = 0;
  }
  if (vtmevVs.horse_enable == flag) {
    vtmevVs.horse_enable = 0;
  }
  if (vtmevVs.nhorse == 0) {
    vtmevVs.now_pos = -1;
    return;
  }
  while (1) {
    tmp = rand() % vtmevVs.nhorse;
    if (tmp == vtmevVs.now_pos) {
      continue;
    }
    if ((1 << tmp) & vtmevVs.horse_enable) {
      continue;
    }
    vtmevVs.now_pos = tmp;
    vtmevVs.horse_enable |= (1 << tmp);
    break;
  }
}

static void tmevCheckVsWarp(Event *event) {
  signed int jj;     // r16
  signed int player; // r17
  signed int ii;     // r18
  signed int warp;   // r19
  float tmp[4];      // 0x50(r29)

  warp = 0;
  player = event->game.player;
  tmp[0] = vtmevVs.warp_pos[player][0];
  tmp[1] = vtmevVs.warp_pos[player][1];
  tmp[2] = vtmevVs.warp_pos[player][2];
  tmp[3] = 1.0f;
  if ((vtmevVs.now_warp[player] == 1) &&
      event->character[player].ctrl->act.trg_recovered == 1) {
    if (vspenvGame->mode.match_rule == 1) {
      vtmevVs.lap[player]++;
    }
    vtmevVs.now_warp[player] = 0;
    if (vtmevWarp != 0) {
      vtmevWarp(event);
    }
  }
  if (vtmevVs.now_warp[player] == 0) {
    for (ii = 0; ii < event->character[player].nhit; ii++) {
      for (jj = 0; jj < vtmevVs.nwarp; jj++) {
        if (vtmevVs.warp[jj].no == event->character[player].hit[ii].no) {
          warp = 1;
          break;
        }
      }
      if (warp == 1) {
        break;
      }
    }
  }
  if (warp == 1) {
    switch (vspenvGame->mode.match_rule) {
    case 1:
      if (tmevGetLap(player) != 3) {
        ktactSetRecover(player, tmp, vtmevVs.warp_pos[player][3], 0.0f, 1);
        nmeventPlayWarp(player, vtmevVs.warp[jj].se);
        vtmevVs.now_warp[player] = 1;
      }
      break;
    case 3:
      break;
    default:
      ktactSetRecover(player, tmp, vtmevVs.warp_pos[player][3], 0.0f, 1);
      vtmevVs.now_warp[player] = 1;
      nmeventPlayWarp(player, vtmevVs.warp[jj].se);
      break;
    }
  }
}

s32 tmevGetFinish(signed int player) { return vtmevSystem.finish[player]; }

void tmevSetVib( // Size: 0x8C, DWARF: 0xD7795
    Event *event, signed int type, signed int no, signed int id) {
  if ((event->game.pause == 0) && (event->game.mode == 1)) {
    if (type == 0) {
      ulpadInitDual(vtmevVibData.common[no], event->game.player, 0, id);
      return;
    }
    ulpadInitDual(vtmevVibData.event[no], event->game.player, 0, id);
  }
}

void tmevSetVibPlayer( // Size: 0x8C, DWARF: 0xD7795
    Event *event, signed int type, signed int no, signed int id,
    signed int player) {
  if ((event->game.pause == 0) && (event->game.mode == 1)) {
    if (type == 0) {
      ulpadInitDual(vtmevVibData.common[no], player, 0, id);
      return;
    }
    ulpadInitDual(vtmevVibData.event[no], player, 0, id);
  }
}

s32 tmevGetIntroCut() {
  signed int frame; // r16
  signed int ret;   // r17

  ret = 0;
  if (vtmevSystem.vs == 1) {
    frame = tmevGetICounter(0) % 720;
  } else {
    frame = tmevGetICounter(0) % 1200;
  }
loop_3:
  if (frame >= 0xF0) {
    ret += 2;
    frame -= 0xF0;
    goto loop_3;
  }
  if (0x78 < frame) {
    ret += 1;
  }
  return ret;
}

void tmevSetLightVector(float *light_color, float *normal_light, signed int id,
                        signed int player) {
  sceVu0CopyVector(vtmevLight[player].light_color[id], light_color);
  sceVu0CopyVector(vtmevLight[player].normal_light[id], normal_light);
}

void tmevSetAmbient(float *ambient, signed int player) {
  sceVu0CopyVector(vtmevLight[player].ambient, ambient);
}

void tmevGetLightVector(sceVu0FMATRIX light_color, sceVu0FMATRIX normal_light,
                        float *ambient, signed int player) {
  signed int ii; // r16

  for (ii = 0; ii < 2; ii++) {
    sceVu0CopyVector(light_color[ii], vtmevLight[player].light_color[ii]);
    sceVu0CopyVector(normal_light[ii], vtmevLight[player].normal_light[ii]);
  }
  sceVu0CopyVector(ambient, vtmevLight[player].ambient);
}

s32 tmevDefInit( // Size: 0x8C, DWARF: 0xD7795
    Event *) {
  return 0;
}

s32 tmevDefResetEvent(Event *event) { return 0; }

s32 tmevDefMainEvent(Event *event) { return 0; }

s32 tmevDefPlayerEvent(Event *event) { return 0; }

s32 tmevDefDrawEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *) {
  return 0;
}

s32 tmevDefDrawPlayerEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *) {
  return 0;
}

s32 tmevDefFinishPlayerEvent( // Size: 0x8C, DWARF: 0xD7795
    Event *) {
  return 0;
}

static void tmevDefEnd() {}
