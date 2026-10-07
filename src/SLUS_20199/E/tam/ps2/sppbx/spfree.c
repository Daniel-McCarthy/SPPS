typedef signed int s32;
typedef signed long s64;
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

typedef struct sceDmaTag {
	unsigned short qwc;
	unsigned char mark;
	unsigned char id;
	struct sceDmaTag* next;
	unsigned int p[2];
} sceDmaTag __attribute__((aligned(16)));

// Static data /////////////////////////////////////////////////////////

float d1250[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

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

// Size: 0x60, DWARF: 0x75E44, 0xCEEDE
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

// Size: 0x10, DWARF: 0x7A4D2, 0xC73CB
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

// Size: 0x190, DWARF: 0x7F127, 0x16B9B7
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

// Size: 0x98, DWARF: 0x791A9, 0xCB0BC
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

// Size: 0x24, DWARF: 0xC7B3F
typedef struct Spenv_KeyConfig
{
    signed int vibration; // Offset: 0x0, DWARF: 0xC7B5B
    signed int spin_l; // Offset: 0x4, DWARF: 0xC7B81
    signed int spin_r; // Offset: 0x8, DWARF: 0xC7BA4
    signed int stance; // Offset: 0xC, DWARF: 0xC7BC7
    signed int revert; // Offset: 0x10, DWARF: 0xC7BEA
    signed int grind; // Offset: 0x14, DWARF: 0xC7C0D
    signed int grab; // Offset: 0x18, DWARF: 0xC7C2F
    signed int jump; // Offset: 0x1C, DWARF: 0xC7C50
    signed int flip; // Offset: 0x20, DWARF: 0xC7C71
} Spenv_KeyConfig;

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

// Size: 0x8, DWARF: 0x168106, 0xC9763
typedef struct Pad
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x168121
    signed char lh; // Offset: 0x2, DWARF: 0x168141
    signed char lv; // Offset: 0x3, DWARF: 0x168160
    signed int analog; // Offset: 0x4, DWARF: 0x16817F
} Pad;

// Size: 0x2580, DWARF: 0x76810, 0x168520, 0x16AE61
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
    sceVu0FMATRIX mat_hip; // Offset: 0x1C70, DWARF: 0x78662
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
    sceVu0IVECTOR col; // Offset: 0x10, DWARF: 0x16D9FE
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
    signed int cnt_ik_foot __attribute__((aligned(16))); // Offset: 0x160, DWARF: 0x1678F8
    signed int freemotion; // Offset: 0x164, DWARF: 0x167920
    signed int ik; // Offset: 0x168, DWARF: 0x167947
    signed int reserve_schange; // Offset: 0x16C, DWARF: 0x167966
    signed int reserve_brending_schange; // Offset: 0x170, DWARF: 0x167992
    signed int motion_speed; // Offset: 0x174, DWARF: 0x1679C7
    signed int mot_sp_flip; // Offset: 0x178, DWARF: 0x1679F0
    signed int trg_to_calc_flip; // Offset: 0x17C, DWARF: 0x167A18
    signed int to_calc_flip; // Offset: 0x180, DWARF: 0x167A45
} Mot;

// Size: 0x2C00, DWARF: 0x16AA87, 0xBCB90
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
    Spenv_KeyConfig* key; // Offset: 0x2BE8, DWARF: 0x16AF0F
    // Size: 0x30, DWARF: 0x167BEE
    Cheats* cheats; // Offset: 0x2BEC, DWARF: 0x16AF34
    // Size: 0x340, DWARF: 0x167DF5
    SysMat* sys_mat ; // Offset: 0x2BF0, DWARF: 0x16AF5C
} Ctrl;

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

// Size: 0x230, DWARF: 0xCE030
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

// Size: 0x90, DWARF: 0xC6A35, 0x7BE99
typedef struct ModelChange //: signed int[2]
{
    sceVu0FMATRIX original; // Offset: 0x0, DWARF: 0xC6A51
    sceVu0FMATRIX original2; // Offset: 0x40, DWARF: 0xC6A78
    sceVu0FMATRIX* address; // Offset: 0x80, DWARF: 0xC6AA0
    sceVu0FMATRIX* address2; // Offset: 0x84, DWARF: 0xC6AC9
    signed int pad[2]; // Offset: 0x88, DWARF: 0xC6AF3
} ModelChange;

// Size: 0x10, DWARF: 0xCDB7F
typedef struct PosAddress
{
    unsigned int type; // Offset: 0x0, DWARF: 0xCDB9B
    float frame; // Offset: 0x4, DWARF: 0xCDBBC
    signed short flg; // Offset: 0x8, DWARF: 0xCDBDE
    signed short non; // Offset: 0xA, DWARF: 0xCDBFE
    float* data[4]; // Offset: 0xC, DWARF: 0xCDC1E
} PosAddress;

// Size: 0x20, DWARF: 0xC9141
typedef struct ModelData
{
    float pos[4]; // Offset: 0x0, DWARF: 0xC915D
    float rot[4]; // Offset: 0x10, DWARF: 0xC917F
} ModelData;

// Size: 0xF0, DWARF: 0xC5DDA
typedef struct Seq
{
    unsigned int model_id; // Offset: 0x0, DWARF: 0xC5DF6
    signed int loop; // Offset: 0x4, DWARF: 0xC5E1B
    signed int mode; // Offset: 0x8, DWARF: 0xC5E3C
    signed int write_flg; // Offset: 0xC, DWARF: 0xC5E5D
    signed int now_local_id; // Offset: 0x10, DWARF: 0xC5E83
    signed int now_top_id; // Offset: 0x14, DWARF: 0xC5EAC
    signed int next_local_id; // Offset: 0x18, DWARF: 0xC5ED3
    signed int next_top_id; // Offset: 0x1C, DWARF: 0xC5EFD
    // Size: 0x20, DWARF: 0xC9141
    ModelData* mdl_data; // Offset: 0x20, DWARF: 0xC5F25
    float now_frame; // Offset: 0x24, DWARF: 0xC5F4F
    float next_frame; // Offset: 0x28, DWARF: 0xC5F75
    float ratio; // Offset: 0x2C, DWARF: 0xC5F9C
    // Size: 0x10, DWARF: 0xCDB7F
    PosAddress* now_pos_address; // Offset: 0x30, DWARF: 0xC5FBE
    // Size: 0x10, DWARF: 0xCDB7F
    PosAddress* now_rot_address; // Offset: 0x34, DWARF: 0xC5FEF
    // Size: 0x10, DWARF: 0xCDB7F
    PosAddress* next_pos_address; // Offset: 0x38, DWARF: 0xC6020
    // Size: 0x10, DWARF: 0xCDB7F
    PosAddress* next_rot_address; // Offset: 0x3C, DWARF: 0xC6052
    float nowDir[4]; // Offset: 0x40, DWARF: 0xC6084
    float nowTrans[4]; // Offset: 0x50, DWARF: 0xC60A9
    float now_matrix[4][4]; // Offset: 0x60, DWARF: 0xC60D0
    float pos[4]; // Offset: 0xA0, DWARF: 0xC60F9
    float quat[4]; // Offset: 0xB0, DWARF: 0xC611B
    float pre_pos[4]; // Offset: 0xC0, DWARF: 0xC613E
    float pre_rot[4]; // Offset: 0xD0, DWARF: 0xC6164
    signed int startVertexIdx; // Offset: 0xE0, DWARF: 0xC618A
    signed int vertexLoopFlg; // Offset: 0xE4, DWARF: 0xC61B5
    signed int pad[2]; // Offset: 0xE8, DWARF: 0xC61DF
} Seq;

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

// Size: 0x2A30, DWARF: 0x7F8F0, 0xCA227, 0xBAAA7
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

// Size: 0x5640, DWARF: 0x78FAB, 0x1BFCC8, 0xC81B4, 0xBB1F1 // vspRider from  ktact.c
typedef struct Rider
{
    // Size: 0x2A30, DWARF: 0x7F8F0, 0xBAAA7
    Disp disp; // Offset: 0x0, DWARF: 0x78FC6
    // Size: 0x2C00, DWARF: 0x7627B
    Ctrl ctrl; // Offset: 0x2A30, DWARF: 0x78FE9
    // char padding[48]; // This does not exist in the original struct, this is added to match the expected offsets. Ctrl is supposed to be size 0x2C00.
    signed int pid; // Offset: 0x5630, DWARF: 0x7900C
    signed int secondly; // Offset: 0x5634, DWARF: 0x7902C
} Rider;

// spfree.c structs //////////////////////////////////////////

// Size: 0x10, DWARF: 0xC91C9
typedef struct QueCol
{
    signed int state; // Offset: 0x0, DWARF: 0xC91E5
    signed int cnt; // Offset: 0x4, DWARF: 0xC9207
    signed int land; // Offset: 0x8, DWARF: 0xC9227
    signed int flight; // Offset: 0xC, DWARF: 0xC9248
} QueCol;

// Size: 0x10, DWARF: 0xC8BF0
typedef struct Spin
{
    signed int rewind; // Offset: 0x0, DWARF: 0xC8C0C
    signed int cab; // Offset: 0x4, DWARF: 0xC8C2F
    signed int value; // Offset: 0x8, DWARF: 0xC8C4F
    signed int first; // Offset: 0xC, DWARF: 0xC8C71
} Spin;

// Size: 0x40, DWARF: 0xCA0B3
typedef struct Que
{
    signed int type; // Offset: 0x0, DWARF: 0xCA0CF
    signed int sp_type; // Offset: 0x4, DWARF: 0xCA0F0
    signed int num; // Offset: 0x8, DWARF: 0xCA114
    signed int link; // Offset: 0xC, DWARF: 0xCA134
    signed int jump; // Offset: 0x10, DWARF: 0xCA155
    signed int fakie; // Offset: 0x14, DWARF: 0xCA176
    signed int late; // Offset: 0x18, DWARF: 0xCA198
    signed int disaster; // Offset: 0x1C, DWARF: 0xCA1B9
    // Size: 0x10, DWARF: 0xC8BF0
    Spin spin; // Offset: 0x20, DWARF: 0xCA1DE
    // Size: 0x10, DWARF: 0xC91C9
    QueCol col; // Offset: 0x30, DWARF: 0xCA201
} Que;

// Size: 0x810, DWARF: 0xCBDBC
typedef struct CombInfo
{
    // Size: 0x40, DWARF: 0xCA0B3 // 0x40 * 32 = 0x800
    Que que[32]; // Offset: 0x0, DWARF: 0xCBDD8
    signed int land; // Offset: 0x800, DWARF: 0xCBDFA
    signed int flight; // Offset: 0x804, DWARF: 0xCBE1B
    signed int fakie; // Offset: 0x808, DWARF: 0xCBE3E
    char entry_id; // Offset: 0x80C, DWARF: 0xCBE60
    char spin_id; // Offset: 0x80D, DWARF: 0xCBE85
    char omit_id; // Offset: 0x80E, DWARF: 0xCBEA9
    char link_id; // Offset: 0x80F, DWARF: 0xCBECD
} CombInfo;

// Size: 0x824, DWARF: 0xCD7C4
typedef struct HorseBestCombo {
    signed int rank; // Offset: 0x0, DWARF: 0xCD7E0
    signed int trick_landing; // Offset: 0x4, DWARF: 0xCD801
    signed int comb_num; // Offset: 0x8, DWARF: 0xCD82B
    signed int comb_points; // Offset: 0xC, DWARF: 0xCD850
    unsigned int comp_time; // Offset: 0x10, DWARF: 0xCD878
    // Size: 0x810, DWARF: 0xCBDBC
    CombInfo comb_info; // Offset: 0x14, DWARF: 0xCD89E
} HorseBestCombo;

// Size: 0x838, DWARF: 0xCD9AA
typedef struct Result {
    signed int goal; // offset 0x0, size 0x4
    unsigned int time; // offset 0x4, size 0x4
    unsigned int count; // offset 0x8, size 0x4
    unsigned int point; // offset 0xC, size 0x4
    signed int cnt_horse; // offset 0x10, size 0x4
    // Size: 0x824, DWARF: 0xCD7C4
    HorseBestCombo horse_best_combo; // offset 0x14, size 0x824
} Result;

// Size: 0x108C, DWARF: 0xCA873
typedef struct VspVsData
{
    signed int div_side; // Offset: 0x0, DWARF: 0xCA88F
    signed int center; // Offset: 0x4, DWARF: 0xCA8B4
    signed int center_pos_id; // Offset: 0x8, DWARF: 0xCA8D7
    signed int center_to_pos_id; // Offset: 0xC, DWARF: 0xCA901
    signed int cnt_center_move; // Offset: 0x10, DWARF: 0xCA92E
    signed int horse_num_round; // Offset: 0x14, DWARF: 0xCA95A
    signed int horse_end_one_round; // Offset: 0x18, DWARF: 0xCA986
    // Size: 0x838, DWARF: 0xCD9AA
    Result result[2]; // offset 0x1C, size 0x1070
} VspVsData;

// Size: 0x10, DWARF: 0xC8D27
typedef union Giftag
{
    // Size: 0x10, DWARF: 0xF7F23
    sceGifTag sce; // Offset: 0x0, DWARF: 0xF8657
    unsigned long ul[2]; // Offset: 0x0, DWARF: 0xF8679
} Giftag;

// Size: 0x8, DWARF: 0xCF49F
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

// Size: 0x8, DWARF: 0xC9402
typedef union Prim
{
    // Size: 0x8, DWARF: 0xF9D57
    sceGsPrim sce; // Offset: 0x0, DWARF: 0xF8FD6
    unsigned long ul; // Offset: 0x0, DWARF: 0xF8FF8
} Prim;

// Size: 0x8, DWARF: 0xC22B3
typedef struct Color //: E:\tam\ps2\sppbx\main.c
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0xFB92B, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0xFB953, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0xFB97B, Bit Offset: 16, Bit Size: 8
    unsigned int A : 8; // Offset: 0x0, DWARF: 0xFB9A3, Bit Offset: 24, Bit Size: 8
    float Q; // Offset: 0x4, DWARF: 0xFB9CB
} Color;

// Size: 0x8, DWARF: 0xCD8CA
typedef struct XYZ
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0xCD8E6, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0xCD90E, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 32; // Offset: 0x0, DWARF: 0xCD936, Bit Offset: 32, Bit Size: 32
} XYZ;

// Size: 0x8, DWARF: 0xCE47F
typedef struct XYZF //: unsigned long
{
    unsigned long X : 16; // Offset: 0x0, DWARF: 0xCE49B, Bit Offset: 0, Bit Size: 16
    unsigned long Y : 16; // Offset: 0x0, DWARF: 0xCE4C3, Bit Offset: 16, Bit Size: 16
    unsigned long Z : 24; // Offset: 0x0, DWARF: 0xCE4EB, Bit Offset: 32, Bit Size: 24
    unsigned long F : 8; // Offset: 0x0, DWARF: 0xCE513, Bit Offset: 56, Bit Size: 8
} XYZF;

// Size: 0x8, DWARF: 0xCAAE8
typedef union XYZF_Type //: <unknown type 0xC000C>
{
    // Size: 0x8, DWARF: 0xCE47F
    XYZF sce; // Offset: 0x0, DWARF: 0xCAB04
    unsigned long ul; // Offset: 0x0, DWARF: 0xCAB26
} XYZF_Type;

// Size: 0x8, DWARF: 0xC9F10
typedef struct Test //: <unknown type 0xC000C>
{
    unsigned long ATE : 1; // Offset: 0x0, DWARF: 0xC9F2C, Bit Offset: 0, Bit Size: 1
    unsigned long ATST : 3; // Offset: 0x0, DWARF: 0xC9F56, Bit Offset: 1, Bit Size: 3
    unsigned long AREF : 8; // Offset: 0x0, DWARF: 0xC9F81, Bit Offset: 4, Bit Size: 8
    unsigned long AFAIL : 2; // Offset: 0x0, DWARF: 0xC9FAC, Bit Offset: 12, Bit Size: 2
    unsigned long DATE : 1; // Offset: 0x0, DWARF: 0xC9FD8, Bit Offset: 14, Bit Size: 1
    unsigned long DATM : 1; // Offset: 0x0, DWARF: 0xCA003, Bit Offset: 15, Bit Size: 1
    unsigned long ZTE : 1; // Offset: 0x0, DWARF: 0xCA02E, Bit Offset: 16, Bit Size: 1
    unsigned long ZTST : 2; // Offset: 0x0, DWARF: 0xCA058, Bit Offset: 17, Bit Size: 2
    unsigned long pad19 : 45; // Offset: 0x0, DWARF: 0xCA083, Bit Offset: 19, Bit Size: 45
} Test;

// Size: 0x60, DWARF: 0xC2CE5
typedef struct Clear
{
    // Size: 0x8, DWARF: 0xC9F10
    Test testa; // Offset: 0x0, DWARF: 0xC2D00
    signed long testaaddr; // Offset: 0x8, DWARF: 0xC2D24
    // Size: 0x8, DWARF: 0xCF49F
    sceGsPrim prim; // Offset: 0x10, DWARF: 0xC2D4A
    signed long primaddr; // Offset: 0x18, DWARF: 0xC2D6D
    // Size: 0x8, DWARF: 0xC22B3
    Color rgbaq; // Offset: 0x20, DWARF: 0xC2D92
    signed long rgbaqaddr; // Offset: 0x28, DWARF: 0xC2DB6
    // Size: 0x8, DWARF: 0xCD8CA
    XYZ xyz2a; // Offset: 0x30, DWARF: 0xC2DDC
    signed long xyz2aaddr; // Offset: 0x38, DWARF: 0xC2E00
    // Size: 0x8, DWARF: 0xCD8CA
    XYZ xyz2b; // Offset: 0x40, DWARF: 0xC2E26
    signed long xyz2baddr; // Offset: 0x48, DWARF: 0xC2E4A
    // Size: 0x8, DWARF: 0xC9F10
    Test testb; // Offset: 0x50, DWARF: 0xC2E70
    signed long testbaddr; // Offset: 0x58, DWARF: 0xC2E94
} Clear;

// Size: 0x8, DWARF: 0xC2850
typedef struct Fba2
{
    unsigned long FBA : 1; // Offset: 0x0, DWARF: 0xC286B, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0xC2895, Bit Offset: 1, Bit Size: 63
} Fba2;

// Size: 0x8, DWARF: 0xD1028
typedef struct Texa
{
    unsigned long TA0 : 8; // Offset: 0x0, DWARF: 0xD1045, Bit Offset: 0, Bit Size: 8
    unsigned long pad08 : 7; // Offset: 0x0, DWARF: 0xD106F, Bit Offset: 8, Bit Size: 7
    unsigned long AEM : 1; // Offset: 0x0, DWARF: 0xD109B, Bit Offset: 15, Bit Size: 1
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0xD10C5, Bit Offset: 16, Bit Size: 16
    unsigned long TA1 : 8; // Offset: 0x0, DWARF: 0xD10F1, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0xD111B, Bit Offset: 40, Bit Size: 24
} Texa;

// Size: 0x8, DWARF: 0xCEAD0
typedef struct Pabe
{
    unsigned long PABE : 1; // Offset: 0x0, DWARF: 0xCEAED, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0xCEB18, Bit Offset: 1, Bit Size: 63
} Pabe;

// Size: 0x8, DWARF: 0xD173B
typedef struct Alpha2
{
    unsigned long A : 2; // Offset: 0x0, DWARF: 0xD1758, Bit Offset: 0, Bit Size: 2
    unsigned long B : 2; // Offset: 0x0, DWARF: 0xD1780, Bit Offset: 2, Bit Size: 2
    unsigned long C : 2; // Offset: 0x0, DWARF: 0xD17A8, Bit Offset: 4, Bit Size: 2
    unsigned long D : 2; // Offset: 0x0, DWARF: 0xD17D0, Bit Offset: 6, Bit Size: 2
    unsigned long pad8 : 24; // Offset: 0x0, DWARF: 0xD17F8, Bit Offset: 8, Bit Size: 24
    unsigned long FIX : 8; // Offset: 0x0, DWARF: 0xD1823, Bit Offset: 32, Bit Size: 8
    unsigned long pad40 : 24; // Offset: 0x0, DWARF: 0xD184D, Bit Offset: 40, Bit Size: 24
} Alpha2;

// Size: 0x60, DWARF: 0xD0AD2
typedef struct Alpha
{
    // Size: 0x8, DWARF: 0xD173B
    Alpha2 alpha1; // Offset: 0x0, DWARF: 0xD0AEF
    signed long alpha1addr; // Offset: 0x8, DWARF: 0xD0B14
    // Size: 0x8, DWARF: 0xD173B
    Alpha2 alpha2; // Offset: 0x10, DWARF: 0xD0B3B
    signed long alpha2addr; // Offset: 0x18, DWARF: 0xD0B60
    // Size: 0x8, DWARF: 0xCEAD0
    Pabe pabe; // Offset: 0x20, DWARF: 0xD0B87
    signed long pabeaddr; // Offset: 0x28, DWARF: 0xD0BAA
    // Size: 0x8, DWARF: 0xD1028
    Texa texa; // Offset: 0x30, DWARF: 0xD0BCF
    signed long texaaddr; // Offset: 0x38, DWARF: 0xD0BF2
    // Size: 0x8, DWARF: 0xC2850
    Fba2 fba1; // Offset: 0x40, DWARF: 0xD0C17
    signed long fba1addr; // Offset: 0x48, DWARF: 0xD0C3A
    // Size: 0x8, DWARF: 0xC2850
    Fba2 fba2; // Offset: 0x50, DWARF: 0xD0C5F
    signed long fba2addr; // Offset: 0x58, DWARF: 0xD0C82
} Alpha;

// Size: 0x8, DWARF: 0xCD2CC
typedef union Alpha_Type
{
    // Size: 0x8, DWARF: 0xD173B
    Alpha2 sce; // Offset: 0x0, DWARF: 0xCD2E8
    unsigned long ul; // Offset: 0x0, DWARF: 0xCD30A
} Alpha_Type;

// Size: 0x20, DWARF: 0xCDEE6
typedef struct Alpha_Tag
{
    // Size: 0x10, DWARF: 0xC8D27
    Giftag giftag; // Offset: 0x0, DWARF: 0xCDF02
    // Size: 0x8, DWARF: 0xCD2CC
    Alpha_Type alpha; // Offset: 0x10, DWARF: 0xCDF27
    signed long reg_addr; // Offset: 0x18, DWARF: 0xCDF4B
} Alpha_Tag;

// Size: 0x8, DWARF: 0xCCB53
typedef struct Dimx //: unsigned long
{
    unsigned long DIMX00 : 3; // Offset: 0x0, DWARF: 0xCCB6F, Bit Offset: 0, Bit Size: 3
    unsigned long pad00 : 1; // Offset: 0x0, DWARF: 0xCCB9C, Bit Offset: 3, Bit Size: 1
    unsigned long DIMX01 : 3; // Offset: 0x0, DWARF: 0xCCBC8, Bit Offset: 4, Bit Size: 3
    unsigned long pad01 : 1; // Offset: 0x0, DWARF: 0xCCBF5, Bit Offset: 7, Bit Size: 1
    unsigned long DIMX02 : 3; // Offset: 0x0, DWARF: 0xCCC21, Bit Offset: 8, Bit Size: 3
    unsigned long pad02 : 1; // Offset: 0x0, DWARF: 0xCCC4E, Bit Offset: 11, Bit Size: 1
    unsigned long DIMX03 : 3; // Offset: 0x0, DWARF: 0xCCC7A, Bit Offset: 12, Bit Size: 3
    unsigned long pad03 : 1; // Offset: 0x0, DWARF: 0xCCCA7, Bit Offset: 15, Bit Size: 1
    unsigned long DIMX10 : 3; // Offset: 0x0, DWARF: 0xCCCD3, Bit Offset: 16, Bit Size: 3
    unsigned long pad10 : 1; // Offset: 0x0, DWARF: 0xCCD00, Bit Offset: 19, Bit Size: 1
    unsigned long DIMX11 : 3; // Offset: 0x0, DWARF: 0xCCD2C, Bit Offset: 20, Bit Size: 3
    unsigned long pad11 : 1; // Offset: 0x0, DWARF: 0xCCD59, Bit Offset: 23, Bit Size: 1
    unsigned long DIMX12 : 3; // Offset: 0x0, DWARF: 0xCCD85, Bit Offset: 24, Bit Size: 3
    unsigned long pad12 : 1; // Offset: 0x0, DWARF: 0xCCDB2, Bit Offset: 27, Bit Size: 1
    unsigned long DIMX13 : 3; // Offset: 0x0, DWARF: 0xCCDDE, Bit Offset: 28, Bit Size: 3
    unsigned long pad13 : 1; // Offset: 0x0, DWARF: 0xCCE0B, Bit Offset: 31, Bit Size: 1
    unsigned long DIMX20 : 3; // Offset: 0x0, DWARF: 0xCCE37, Bit Offset: 32, Bit Size: 3
    unsigned long pad20 : 1; // Offset: 0x0, DWARF: 0xCCE64, Bit Offset: 35, Bit Size: 1
    unsigned long DIMX21 : 3; // Offset: 0x0, DWARF: 0xCCE90, Bit Offset: 36, Bit Size: 3
    unsigned long pad21 : 1; // Offset: 0x0, DWARF: 0xCCEBD, Bit Offset: 39, Bit Size: 1
    unsigned long DIMX22 : 3; // Offset: 0x0, DWARF: 0xCCEE9, Bit Offset: 40, Bit Size: 3
    unsigned long pad22 : 1; // Offset: 0x0, DWARF: 0xCCF16, Bit Offset: 43, Bit Size: 1
    unsigned long DIMX23 : 3; // Offset: 0x0, DWARF: 0xCCF42, Bit Offset: 44, Bit Size: 3
    unsigned long pad23 : 1; // Offset: 0x0, DWARF: 0xCCF6F, Bit Offset: 47, Bit Size: 1
    unsigned long DIMX30 : 3; // Offset: 0x0, DWARF: 0xCCF9B, Bit Offset: 48, Bit Size: 3
    unsigned long pad30 : 1; // Offset: 0x0, DWARF: 0xCCFC8, Bit Offset: 51, Bit Size: 1
    unsigned long DIMX31 : 3; // Offset: 0x0, DWARF: 0xCCFF4, Bit Offset: 52, Bit Size: 3
    unsigned long pad31 : 1; // Offset: 0x0, DWARF: 0xCD021, Bit Offset: 55, Bit Size: 1
    unsigned long DIMX32 : 3; // Offset: 0x0, DWARF: 0xCD04D, Bit Offset: 56, Bit Size: 3
    unsigned long pad32 : 1; // Offset: 0x0, DWARF: 0xCD07A, Bit Offset: 59, Bit Size: 1
    unsigned long DIMX33 : 3; // Offset: 0x0, DWARF: 0xCD0A6, Bit Offset: 60, Bit Size: 3
    unsigned long pad33 : 1; // Offset: 0x0, DWARF: 0xCD0D3, Bit Offset: 63, Bit Size: 1
} Dimx;

// Size: 0x8, DWARF: 0xC9EAF
typedef union Rgbaq // : <unknown type 0xC000C>
{
    // Size: 0x8, DWARF: 0xC22B3
    Color sce; // Offset: 0x0, DWARF: 0xC9ECB
    unsigned long ul; // Offset: 0x0, DWARF: 0xC9EED
} Rgbaq;

// Size: 0x8, DWARF: 0xD187D
typedef struct Dthe
{
    unsigned long DTHE : 1; // Offset: 0x0, DWARF: 0xD189A, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0xD18C5, Bit Offset: 1, Bit Size: 63
} Dthe;

// Size: 0x10, DWARF: 0xC5D1F
typedef struct VspLocalGifPkt //: const volatile <unknown type 0xC000C>
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0xC5D3B
    __int128* pBase; // Offset: 0x4, DWARF: 0xC5D63
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0xC5D88
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0xC5DAF
} VspLocalGifPkt;

// Size: 0x8, DWARF: 0xCEDFD
typedef struct BgColor
{
    unsigned int R : 8; // Offset: 0x0, DWARF: 0xCEE1A, Bit Offset: 0, Bit Size: 8
    unsigned int G : 8; // Offset: 0x0, DWARF: 0xCEE42, Bit Offset: 8, Bit Size: 8
    unsigned int B : 8; // Offset: 0x0, DWARF: 0xCEE6A, Bit Offset: 16, Bit Size: 8
    unsigned int p0 : 8; // Offset: 0x0, DWARF: 0xCEE92, Bit Offset: 24, Bit Size: 8
    unsigned int p1; // Offset: 0x4, DWARF: 0xCEEBB
} BgColor;

// Size: 0x8, DWARF: 0xCE53F, 0xC29BF
typedef struct Display
{
    unsigned int DX : 12; // Offset: 0x0, DWARF: 0xCE55B, Bit Offset: 0, Bit Size: 12
    unsigned int DY : 11; // Offset: 0x0, DWARF: 0xCE584, Bit Offset: 12, Bit Size: 11
    unsigned int MAGH : 4; // Offset: 0x0, DWARF: 0xCE5AD, Bit Offset: 23, Bit Size: 4
    unsigned int MAGV : 2; // Offset: 0x0, DWARF: 0xCE5D8, Bit Offset: 27, Bit Size: 2
    unsigned int p0 : 3; // Offset: 0x0, DWARF: 0xCE603, Bit Offset: 29, Bit Size: 3
    unsigned int DW : 12; // Offset: 0x4, DWARF: 0xCE62C, Bit Offset: 0, Bit Size: 12
    unsigned int DH : 11; // Offset: 0x4, DWARF: 0xCE655, Bit Offset: 12, Bit Size: 11
    unsigned int p1 : 9; // Offset: 0x4, DWARF: 0xCE67E, Bit Offset: 23, Bit Size: 9
} Display;

// Size: 0x8, DWARF: 0xC961F, 0xCF6FB
typedef struct DispFb //: <unknown type 0xC0009>
{
    unsigned int FBP : 9; // Offset: 0x0, DWARF: 0xC963B, Bit Offset: 0, Bit Size: 9
    unsigned int FBW : 6; // Offset: 0x0, DWARF: 0xC9665, Bit Offset: 9, Bit Size: 6
    unsigned int PSM : 5; // Offset: 0x0, DWARF: 0xC968F, Bit Offset: 15, Bit Size: 5
    unsigned int p0 : 12; // Offset: 0x0, DWARF: 0xC96B9, Bit Offset: 20, Bit Size: 12
    unsigned int DBX : 11; // Offset: 0x4, DWARF: 0xC96E2, Bit Offset: 0, Bit Size: 11
    unsigned int DBY : 11; // Offset: 0x4, DWARF: 0xC970C, Bit Offset: 11, Bit Size: 11
    unsigned int p1 : 10; // Offset: 0x4, DWARF: 0xC9736, Bit Offset: 22, Bit Size: 10
} DispFb;

// Size: 0x8, DWARF: 0xCAFD3
typedef struct ColClamp
{
    unsigned long CLAMP : 1; // Offset: 0x0, DWARF: 0xCAFEF, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0xCB01B, Bit Offset: 1, Bit Size: 63
} ColClamp;

// Size: 0x8, DWARF: 0xD11E8
typedef struct PrModeCont
{
    unsigned long AC : 1; // Offset: 0x0, DWARF: 0xD1205, Bit Offset: 0, Bit Size: 1
    unsigned long pad01 : 63; // Offset: 0x0, DWARF: 0xD122E, Bit Offset: 1, Bit Size: 63
} PrModeCont;

// Size: 0x8, DWARF: 0xC6CB9
typedef struct Scissor2 //: unsigned long
{
    unsigned long SCAX0 : 11; // Offset: 0x0, DWARF: 0xC6CD5, Bit Offset: 0, Bit Size: 11
    unsigned long pad11 : 5; // Offset: 0x0, DWARF: 0xC6D01, Bit Offset: 11, Bit Size: 5
    unsigned long SCAX1 : 11; // Offset: 0x0, DWARF: 0xC6D2D, Bit Offset: 16, Bit Size: 11
    unsigned long pad27 : 5; // Offset: 0x0, DWARF: 0xC6D59, Bit Offset: 27, Bit Size: 5
    unsigned long SCAY0 : 11; // Offset: 0x0, DWARF: 0xC6D85, Bit Offset: 32, Bit Size: 11
    unsigned long pad43 : 5; // Offset: 0x0, DWARF: 0xC6DB1, Bit Offset: 43, Bit Size: 5
    unsigned long SCAY1 : 11; // Offset: 0x0, DWARF: 0xC6DDD, Bit Offset: 48, Bit Size: 11
    unsigned long pad59 : 5; // Offset: 0x0, DWARF: 0xC6E09, Bit Offset: 59, Bit Size: 5
} Scissor2;

// Size: 0x8, DWARF: 0xCD103
typedef struct XYOffset
{
    unsigned long OFX : 16; // Offset: 0x0, DWARF: 0xCD11F, Bit Offset: 0, Bit Size: 16
    unsigned long pad16 : 16; // Offset: 0x0, DWARF: 0xCD149, Bit Offset: 16, Bit Size: 16
    unsigned long OFY : 16; // Offset: 0x0, DWARF: 0xCD175, Bit Offset: 32, Bit Size: 16
    unsigned long pad48 : 16; // Offset: 0x0, DWARF: 0xCD19F, Bit Offset: 48, Bit Size: 16
} XYOffset;

// Size: 0x8, DWARF: 0xCF0A7
typedef struct Zbuf
{
    unsigned long ZBP : 9; // Offset: 0x0, DWARF: 0xCF0C4, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 15; // Offset: 0x0, DWARF: 0xCF0EE, Bit Offset: 9, Bit Size: 15
    unsigned long PSM : 4; // Offset: 0x0, DWARF: 0xCF11A, Bit Offset: 24, Bit Size: 4
    unsigned long pad28 : 4; // Offset: 0x0, DWARF: 0xCF144, Bit Offset: 28, Bit Size: 4
    unsigned long ZMSK : 1; // Offset: 0x0, DWARF: 0xCF170, Bit Offset: 32, Bit Size: 1
    unsigned long pad33 : 31; // Offset: 0x0, DWARF: 0xCF19B, Bit Offset: 33, Bit Size: 31
} Zbuf;

// Size: 0x8, DWARF: 0xC84D2
typedef struct Frame
{
    unsigned long FBP : 9; // Offset: 0x0, DWARF: 0xC84EE, Bit Offset: 0, Bit Size: 9
    unsigned long pad09 : 7; // Offset: 0x0, DWARF: 0xC8518, Bit Offset: 9, Bit Size: 7
    unsigned long FBW : 6; // Offset: 0x0, DWARF: 0xC8544, Bit Offset: 16, Bit Size: 6
    unsigned long pad22 : 2; // Offset: 0x0, DWARF: 0xC856E, Bit Offset: 22, Bit Size: 2
    unsigned long PSM : 6; // Offset: 0x0, DWARF: 0xC859A, Bit Offset: 24, Bit Size: 6
    unsigned long pad30 : 2; // Offset: 0x0, DWARF: 0xC85C4, Bit Offset: 30, Bit Size: 2
    unsigned long FBMSK : 32; // Offset: 0x0, DWARF: 0xC85F0, Bit Offset: 32, Bit Size: 32
} Frame;

// Size: 0x80, DWARF: 0xCEB48
typedef struct Draw1
{
    // Size: 0x8, DWARF: 0xC84D2
    Frame frame1; // Offset: 0x0, DWARF: 0xCEB65
    unsigned long frame1addr; // Offset: 0x8, DWARF: 0xCEB8A
    // Size: 0x8, DWARF: 0xCF0A7
    Zbuf zbuf1; // Offset: 0x10, DWARF: 0xCEBB1
    signed long zbuf1addr; // Offset: 0x18, DWARF: 0xCEBD5
    // Size: 0x8, DWARF: 0xCD103
    XYOffset xyoffset1; // Offset: 0x20, DWARF: 0xCEBFB
    signed long xyoffset1addr; // Offset: 0x28, DWARF: 0xCEC23
    // Size: 0x8, DWARF: 0xC6CB9
    Scissor2 scissor1; // Offset: 0x30, DWARF: 0xCEC4D
    signed long scissor1addr; // Offset: 0x38, DWARF: 0xCEC74
    // Size: 0x8, DWARF: 0xD11E8
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0xCEC9D
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0xCECC6
    // Size: 0x8, DWARF: 0xCAFD3
    ColClamp colclamp; // Offset: 0x50, DWARF: 0xCECF1
    signed long colclampaddr; // Offset: 0x58, DWARF: 0xCED18
    // Size: 0x8, DWARF: 0xD187D
    Dthe dthe; // Offset: 0x60, DWARF: 0xCED41
    signed long dtheaddr; // Offset: 0x68, DWARF: 0xCED64
    // Size: 0x8, DWARF: 0xC9F10
    Test test1; // Offset: 0x70, DWARF: 0xCED89
    signed long test1addr; // Offset: 0x78, DWARF: 0xCEDAD
} Draw1;

// Size: 0x80, DWARF: 0xD046F
typedef struct Draw2
{
    // Size: 0x8, DWARF: 0xC84D2
    Frame frame2; // Offset: 0x0, DWARF: 0xD048C
    unsigned long frame2addr; // Offset: 0x8, DWARF: 0xD04B1
    // Size: 0x8, DWARF: 0xCF0A7
    Zbuf zbuf2; // Offset: 0x10, DWARF: 0xD04D8
    signed long zbuf2addr; // Offset: 0x18, DWARF: 0xD04FC
    // Size: 0x8, DWARF: 0xCD103
    XYOffset xyoffset2; // Offset: 0x20, DWARF: 0xD0522
    signed long xyoffset2addr; // Offset: 0x28, DWARF: 0xD054A
    // Size: 0x8, DWARF: 0xC6CB9
    Scissor2 scissor2; // Offset: 0x30, DWARF: 0xD0574
    signed long scissor2addr; // Offset: 0x38, DWARF: 0xD059B
    // Size: 0x8, DWARF: 0xD11E8
    PrModeCont prmodecont; // Offset: 0x40, DWARF: 0xD05C4
    signed long prmodecontaddr; // Offset: 0x48, DWARF: 0xD05ED
    // Size: 0x8, DWARF: 0xCAFD3
    ColClamp colclamp; // Offset: 0x50, DWARF: 0xD0618
    signed long colclampaddr; // Offset: 0x58, DWARF: 0xD063F
    // Size: 0x8, DWARF: 0xD187D
    Dthe dthe; // Offset: 0x60, DWARF: 0xD0668
    signed long dtheaddr; // Offset: 0x68, DWARF: 0xD068B
    // Size: 0x8, DWARF: 0xC9F10
    Test test2; // Offset: 0x70, DWARF: 0xD06B0
    signed long test2addr; // Offset: 0x78, DWARF: 0xD06D4
} Draw2;

// Size: 0x8, DWARF: 0xCC19A
typedef struct Smode //: unsigned int
{
    unsigned int INT : 1; // Offset: 0x0, DWARF: 0xCC1B6, Bit Offset: 0, Bit Size: 1
    unsigned int FFMD : 1; // Offset: 0x0, DWARF: 0xCC1E0, Bit Offset: 1, Bit Size: 1
    unsigned int DPMS : 2; // Offset: 0x0, DWARF: 0xCC20B, Bit Offset: 2, Bit Size: 2
    unsigned int p0 : 28; // Offset: 0x0, DWARF: 0xCC236, Bit Offset: 4, Bit Size: 28
    unsigned int p1; // Offset: 0x4, DWARF: 0xCC25F
} Smode;

// Size: 0x8, DWARF: 0xC8644
typedef struct Pmode
{
    unsigned int EN1 : 1; // Offset: 0x0, DWARF: 0xC8660, Bit Offset: 0, Bit Size: 1
    unsigned int EN2 : 1; // Offset: 0x0, DWARF: 0xC868A, Bit Offset: 1, Bit Size: 1
    unsigned int CRTMD : 3; // Offset: 0x0, DWARF: 0xC86B4, Bit Offset: 2, Bit Size: 3
    unsigned int MMOD : 1; // Offset: 0x0, DWARF: 0xC86E0, Bit Offset: 5, Bit Size: 1
    unsigned int AMOD : 1; // Offset: 0x0, DWARF: 0xC870B, Bit Offset: 6, Bit Size: 1
    unsigned int SLBG : 1; // Offset: 0x0, DWARF: 0xC8736, Bit Offset: 7, Bit Size: 1
    unsigned int ALP : 8; // Offset: 0x0, DWARF: 0xC8761, Bit Offset: 8, Bit Size: 8
    unsigned int p0 : 16; // Offset: 0x0, DWARF: 0xC878B, Bit Offset: 16, Bit Size: 16
    unsigned int p1; // Offset: 0x4, DWARF: 0xC87B4
} Pmode;

// Size: 0x28, DWARF: 0xCDAA5
typedef struct DisplayType // Size: 0x8, DWARF: 0xCEDFD 
{
    // Size: 0x8, DWARF: 0xC8644
    Pmode pmode; // Offset: 0x0, DWARF: 0xCDAC1
    // Size: 0x8, DWARF: 0xCC19A
    Smode smode2; // Offset: 0x8, DWARF: 0xCDAE5
    // Size: 0x8, DWARF: 0xC961F
    DispFb dispfb; // Offset: 0x10, DWARF: 0xCDB0A
    // Size: 0x8, DWARF: 0xCE53F
    Display display; // Offset: 0x18, DWARF: 0xCDB2F
    // Size: 0x8, DWARF: 0xCEDFD
    BgColor bgcolor; // Offset: 0x20, DWARF: 0xCDB55
} DisplayType;

// Size: 0x40, DWARF: 0xD0024
typedef struct Cmn
{
    // Size: 0x8, DWARF: 0xD11E8
    PrModeCont prmodecont; // Offset: 0x0, DWARF: 0xD0041
    signed long prmodecontaddr; // Offset: 0x8, DWARF: 0xD006A
    // Size: 0x8, DWARF: 0xCAFD3
    ColClamp colclamp; // Offset: 0x10, DWARF: 0xD0095
    signed long colclampaddr; // Offset: 0x18, DWARF: 0xD00BC
    // Size: 0x8, DWARF: 0xD187D
    Dthe dthe; // Offset: 0x20, DWARF: 0xD00E5
    signed long dtheaddr; // Offset: 0x28, DWARF: 0xD0108
    // Size: 0x8, DWARF: 0xCCB53
    Dimx dimx; // Offset: 0x30, DWARF: 0xD012D
    signed long dimxaddr; // Offset: 0x38, DWARF: 0xD0150
} Cmn;

// Size: 0x50, DWARF: 0xCF306
typedef struct Fbuf
{
    // Size: 0x8, DWARF: 0xC84D2
    Frame frame; // Offset: 0x0, DWARF: 0xCF323
    unsigned long frameaddr; // Offset: 0x8, DWARF: 0xCF347
    // Size: 0x8, DWARF: 0xCF0A7
    Zbuf zbuf; // Offset: 0x10, DWARF: 0xCF36D
    signed long zbufaddr; // Offset: 0x18, DWARF: 0xCF390
    // Size: 0x8, DWARF: 0xCD103
    XYOffset xyoffset; // Offset: 0x20, DWARF: 0xCF3B5
    signed long xyoffsetaddr; // Offset: 0x28, DWARF: 0xCF3DC
    // Size: 0x8, DWARF: 0xC6CB9
    Scissor2 scissor; // Offset: 0x30, DWARF: 0xCF405
    signed long scissoraddr; // Offset: 0x38, DWARF: 0xCF42B
    // Size: 0x8, DWARF: 0xC9F10
    Test test; // Offset: 0x40, DWARF: 0xCF453
    signed long testaddr; // Offset: 0x48, DWARF: 0xCF476
} Fbuf;

// Size: 0x1B0, DWARF: 0xC5BC9
typedef struct Draw // Size: 0x60, DWARF: 0xC2CE5
{
    // Size: 0x10, DWARF: 0xCB71D
    sceGifTag giftag; // Offset: 0x0, DWARF: 0xC5BE5
    // Size: 0x50, DWARF: 0xCF306
    Fbuf fbuf[2]; // Offset: 0x10, DWARF: 0xC5C0A
    // Size: 0x40, DWARF: 0xD0024
    Cmn cmn; // Offset: 0xB0, DWARF: 0xC5C2D
    // Size: 0x60, DWARF: 0xD0AD2
    Alpha alpha; // Offset: 0xF0, DWARF: 0xC5C4F
    // Size: 0x60, DWARF: 0xC2CE5
    Clear clear; // Offset: 0x150, DWARF: 0xC5C73
} Draw;

// Size: 0x1, DWARF: 0xC8B48
typedef struct Flag //: unsigned int
{
    unsigned int filter : 1; // Offset: 0x0, DWARF: 0xC8B64, Bit Offset: 0, Bit Size: 1
    unsigned int dither : 1; // Offset: 0x0, DWARF: 0xC8B91, Bit Offset: 1, Bit Size: 1
    unsigned int oddeven : 1; // Offset: 0x0, DWARF: 0xC8BBE, Bit Offset: 2, Bit Size: 1
} Flag;

// Size: 0x38, DWARF: 0xC218B
typedef struct DisplayModes
{
    // Size: 0x8, DWARF: 0xC8644
    Pmode pmode; // Offset: 0x0, DWARF: 0xC21A6
    // Size: 0x8, DWARF: 0xCC19A
    Smode smode2; // Offset: 0x8, DWARF: 0xC21CA
    // Size: 0x8, DWARF: 0xCF6FB
    DispFb dispfb1; // Offset: 0x10, DWARF: 0xC21EF
    // Size: 0x8, DWARF: 0xC29BF
    Display display1; // Offset: 0x18, DWARF: 0xC2215
    // Size: 0x8, DWARF: 0xC961F
    DispFb dispfb2; // Offset: 0x20, DWARF: 0xC223C
    // Size: 0x8, DWARF: 0xCE53F
    Display display2; // Offset: 0x28, DWARF: 0xC2262
    // Size: 0x8, DWARF: 0xCEDFD
    BgColor bgcolor; // Offset: 0x30, DWARF: 0xC2289
} DisplayModes;

// Size: 0x790, DWARF: 0xC702B
typedef struct VgmsysFrameBuffer
{
    // Size: 0x38, DWARF: 0xC218B
    DisplayModes disp[3]; // Offset: 0x0, DWARF: 0xC7047
    // Size: 0x1B0, DWARF: 0xC5BC9
    Draw draw[4]; // Offset: 0xB0, DWARF: 0xC706A
    unsigned short nbuf; // Offset: 0x770, DWARF: 0xC708D
    unsigned short idx; // Offset: 0x772, DWARF: 0xC70AE
    unsigned short count; // Offset: 0x774, DWARF: 0xC70CE
    unsigned short psm; // Offset: 0x776, DWARF: 0xC70F0
    unsigned short zpsm; // Offset: 0x778, DWARF: 0xC7110
    signed short w; // Offset: 0x77A, DWARF: 0xC7131
    signed short h; // Offset: 0x77C, DWARF: 0xC714F
    signed short cx; // Offset: 0x77E, DWARF: 0xC716D
    signed short cy; // Offset: 0x780, DWARF: 0xC718C
    unsigned short ztest; // Offset: 0x782, DWARF: 0xC71AB
    unsigned short mode; // Offset: 0x784, DWARF: 0xC71CD
    // Size: 0x1, DWARF: 0xC8B48
    Flag flag; // Offset: 0x786, DWARF: 0xC71EE
} VgmsysFrameBuffer;

// Size: 0x330, DWARF: 0xC9295
typedef struct DBuffType // Size: 0x60, DWARF: 0xC2CE5
{
    // Size: 0x28, DWARF: 0xCDAA5
    DisplayType disp[2]; // Offset: 0x0, DWARF: 0xC92B1
    // Size: 0x10, DWARF: 0xCB71D
    sceGifTag giftag0; // Offset: 0x50, DWARF: 0xC92D4
    // Size: 0x80, DWARF: 0xCEB48
    Draw1 draw01; // Offset: 0x60, DWARF: 0xC92FA
    // Size: 0x80, DWARF: 0xD046F
    Draw2 draw02; // Offset: 0xE0, DWARF: 0xC931F
    // Size: 0x60, DWARF: 0xC2CE5
    Clear clear0; // Offset: 0x160, DWARF: 0xC9344
    // Size: 0x10, DWARF: 0xCB71D
    sceGifTag giftag1; // Offset: 0x1C0, DWARF: 0xC9369
    // Size: 0x80, DWARF: 0xCEB48
    Draw1 draw11; // Offset: 0x1D0, DWARF: 0xC938F
    // Size: 0x80, DWARF: 0xD046F
    Draw2 draw12; // Offset: 0x250, DWARF: 0xC93B4
    // Size: 0x60, DWARF: 0xC2CE5
    Clear clear1; // Offset: 0x2D0, DWARF: 0xC93D9
} DBuffType;

// Size: 0x4, DWARF: 0xC57C8
typedef struct Chcr
{
    unsigned int DIR : 1; // Offset: 0x0, DWARF: 0xC57E4, Bit Offset: 0, Bit Size: 1
    unsigned int p0 : 1; // Offset: 0x0, DWARF: 0xC580E, Bit Offset: 1, Bit Size: 1
    unsigned int MOD : 2; // Offset: 0x0, DWARF: 0xC5837, Bit Offset: 2, Bit Size: 2
    unsigned int ASP : 2; // Offset: 0x0, DWARF: 0xC5861, Bit Offset: 4, Bit Size: 2
    unsigned int TTE : 1; // Offset: 0x0, DWARF: 0xC588B, Bit Offset: 6, Bit Size: 1
    unsigned int TIE : 1; // Offset: 0x0, DWARF: 0xC58B5, Bit Offset: 7, Bit Size: 1
    unsigned int STR : 1; // Offset: 0x0, DWARF: 0xC58DF, Bit Offset: 8, Bit Size: 1
    unsigned int p1 : 7; // Offset: 0x0, DWARF: 0xC5909, Bit Offset: 9, Bit Size: 7
    unsigned int TAG : 16; // Offset: 0x0, DWARF: 0xC5932, Bit Offset: 16, Bit Size: 16
} Chcr;

// Size: 0x90, DWARF: 0xCBB7C
typedef struct DmaVif //: unsigned int[3]
{
    // Size: 0x4, DWARF: 0xC57C8
    Chcr chcr; // Offset: 0x0, DWARF: 0xCBB98
    unsigned int p0[3]; // Offset: 0x4, DWARF: 0xCBBBB
    void* madr; // Offset: 0x10, DWARF: 0xCBBDC
    unsigned int p1[3]; // Offset: 0x14, DWARF: 0xCBC00
    unsigned int qwc; // Offset: 0x20, DWARF: 0xCBC21
    unsigned int p2[3]; // Offset: 0x24, DWARF: 0xCBC41
    sceDmaTag* tadr; // Offset: 0x30, DWARF: 0xCBC62
    unsigned int p3[3]; // Offset: 0x34, DWARF: 0xCBC88
    void* as0; // Offset: 0x40, DWARF: 0xCBCA9
    unsigned int p4[3]; // Offset: 0x44, DWARF: 0xCBCCC
    void* as1; // Offset: 0x50, DWARF: 0xCBCED
    unsigned int p5[3]; // Offset: 0x54, DWARF: 0xCBD10
    unsigned int p6[4]; // Offset: 0x60, DWARF: 0xCBD31
    unsigned int p7[4]; // Offset: 0x70, DWARF: 0xCBD52
    void* sadr; // Offset: 0x80, DWARF: 0xCBD73
    unsigned int p8[3]; // Offset: 0x84, DWARF: 0xCBD97
} DmaVif;

// Size: 0x360, DWARF: 0xCBF1B
typedef struct VulsysSystem
{
    unsigned int KeepMemSize; // Offset: 0x0, DWARF: 0xCBF37
    signed int Pal; // Offset: 0x4, DWARF: 0xCBF5F
    signed int Interlace; // Offset: 0x8, DWARF: 0xCBF7F
    signed short ScreenMode; // Offset: 0xC, DWARF: 0xCBFA5
    signed short ScreenWidth; // Offset: 0xE, DWARF: 0xCBFCC
    signed short ScreenHeight; // Offset: 0x10, DWARF: 0xCBFF4
    signed short ScreenYofs; // Offset: 0x12, DWARF: 0xCC01D
    signed int EvenOdd; // Offset: 0x14, DWARF: 0xCC044
    unsigned long Frame; // Offset: 0x18, DWARF: 0xCC068
    signed int PadInit; // Offset: 0x20, DWARF: 0xCC08A
    // Size: 0x90, DWARF: 0xCBB7C
    DmaVif* DmaGif; // Offset: 0x24, DWARF: 0xCC0AE
    // Size: 0x90, DWARF: 0xCBB7C
    DmaVif* DmaVif0; // Offset: 0x28, DWARF: 0xCC0D6
    // Size: 0x90, DWARF: 0xCBB7C
    DmaVif* DmaVif1; // Offset: 0x2C, DWARF: 0xCC0FF
    // Size: 0x330, DWARF: 0xC9295
    DBuffType DBuff; // Offset: 0x30, DWARF: 0xCC128
} VulsysSystem;

// Size: 0x10, DWARF: 0xC9463
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0xC947F
    unsigned int addr; // Offset: 0x4, DWARF: 0xC94A2
    unsigned int z; // Offset: 0x8, DWARF: 0xC94C3
    unsigned int _pad; // Offset: 0xC, DWARF: 0xC94E1
} ATag;

// Size: 0x20, DWARF: 0xC8303
typedef struct VgmsysAbuf //ABuf
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0xC831F
    unsigned int natag; // Offset: 0x4, DWARF: 0xC8343
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0xC8365
    unsigned int npkt; // Offset: 0xC, DWARF: 0xC8388
    // Size: 0x10, DWARF: 0xC9463
    ATag* atag; // Offset: 0x10, DWARF: 0xC83A9
    // Size: 0x10, DWARF: 0xC9463
    ATag* curatag; // Offset: 0x14, DWARF: 0xC83CF
    __int128* pkt; // Offset: 0x18, DWARF: 0xC83F8
    __int128* curpkt; // Offset: 0x1C, DWARF: 0xC841B
} VgmsysAbuf;

// Size: 0x20, DWARF: 0xC7745
typedef struct VifPacket //: unsigned int
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0xC7761
    __int128* pBase; // Offset: 0x4, DWARF: 0xC7789
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0xC77AE
    unsigned int* pVifCode; // Offset: 0xC, DWARF: 0xC77D5
    unsigned int numlen; // Offset: 0x10, DWARF: 0xC77FD
    unsigned long* pGifTag; // Offset: 0x14, DWARF: 0xC7820
    unsigned int pad12; // Offset: 0x18, DWARF: 0xC7847
    unsigned int pad13; // Offset: 0x1C, DWARF: 0xC7869
} VifPacket;

// Size: 0x340, DWARF: 0xC7FB6
typedef struct VspSystemMatrix // : <unknown type 0xC000E>
{
    // Size: 0x30, DWARF: 0xC6530
    ScreenInfo scr_info; // Offset: 0x0, DWARF: 0xC7FD2
    // Size: 0x20, DWARF: 0xC6972
    Fog fog; // Offset: 0x30, DWARF: 0xC7FF9
    // Size: 0x140, DWARF: 0xC6770
    Matrix matrix; // Offset: 0x50, DWARF: 0xC801B
    sceVu0FMATRIX world_screen; // Offset: 0x190, DWARF: 0xC8040
    sceVu0FMATRIX world_view; // Offset: 0x1D0, DWARF: 0xC806B
    sceVu0FMATRIX view_screen; // Offset: 0x210, DWARF: 0xC8094
    sceVu0FMATRIX light_color; // Offset: 0x250, DWARF: 0xC80BE
    sceVu0FMATRIX normal_light; // Offset: 0x290, DWARF: 0xC80E8
    sceVu0FMATRIX view_clip; // Offset: 0x2D0, DWARF: 0xC8113
    sceVu0FVECTOR cam_rot; // Offset: 0x310, DWARF: 0xC813B
    sceVu0FVECTOR cam_trans; // Offset: 0x320, DWARF: 0xC8161
    float view_angle; // Offset: 0x330, DWARF: 0xC8189
    char padding[0xC]; // Not normally in struct but added to pad struct to size.
} VspSystemMatrix;

// Size: 0x34, DWARF: 0x1671F4
typedef struct SpfreeCharacter
{
    signed int no; // Offset: 0x0, DWARF: 0xCDD13
    signed int player; // Offset: 0x4, DWARF: 0xCDD32
    signed int base_attr; // Offset: 0x8, DWARF: 0xCDD55
    signed int nvector; // Offset: 0xC, DWARF: 0xCDD7B
    signed int nhit; // Offset: 0x10, DWARF: 0xCDD9F
    signed int nobj; // Offset: 0x14, DWARF: 0xCDDC0
    signed int rail; // Offset: 0x18, DWARF: 0xCDDE1
    signed int old_rail; // Offset: 0x1C, DWARF: 0xCDE02
    signed int res; // Offset: 0x20, DWARF: 0xCDE27
    // Size: 0x60, DWARF: 0xCEEDE
    Col* vector; // Offset: 0x24, DWARF: 0xCDE47
    // Size: 0x60, DWARF: 0xCEEDE
    Col* hit; // Offset: 0x28, DWARF: 0xCDE6F
    // Size: 0x60, DWARF: 0xCEEDE
    Col* object; // Offset: 0x2C, DWARF: 0xCDE94
    // Size: 0x2C00, DWARF: 0xCC651
    Ctrl* ctrl; // Offset: 0x30, DWARF: 0xCDEBC
} SpfreeCharacter;

// Size: 0x30, DWARF: 0xC6251
typedef struct CharacterRenderParams //: signed int[2]
{
    // Size: 0x30, DWARF: 0xC6530
    ScreenInfo* screen; // Offset: 0x0, DWARF: 0xC626D
    // Size: 0x140, DWARF: 0xC6770
    Matrix* matrix; // Offset: 0x4, DWARF: 0xC6295
    // Size: 0x20, DWARF: 0xC6972
    Fog* fog; // Offset: 0x8, DWARF: 0xC62BD
    sceVu0FVECTOR* camera_position; // Offset: 0xC, DWARF: 0xC62E2
    sceVu0FVECTOR* camera_rotation; // Offset: 0x10, DWARF: 0xC6313
    // Size: 0x10, DWARF: 0xC5D1F
    VspLocalGifPkt* gif_packet; // Offset: 0x14, DWARF: 0xC6344
    // Size: 0x20, DWARF: 0xC7745
    VifPacket* vif1_packet; // Offset: 0x18, DWARF: 0xC6370
    // Size: 0x20, DWARF: 0xC8303
    VgmsysAbuf* alpha; // Offset: 0x1C, DWARF: 0xC639D
    float view_angle; // Offset: 0x20, DWARF: 0xC63C4
    signed int player; // Offset: 0x24, DWARF: 0xC63EB
    signed int res[2]; // Offset: 0x28, DWARF: 0xC640E
} CharacterRenderParams;

// Size: 0x20, DWARF: 0xC952C
typedef struct VspDispEnv //: signed int[3]
{
    signed int mode; // Offset: 0x0, DWARF: 0xC9548
    signed int time_left; // Offset: 0x4, DWARF: 0xC9569
    signed int pass_time; // Offset: 0x8, DWARF: 0xC958F
    signed int div; // Offset: 0xC, DWARF: 0xC95B5
    signed int div_exp; // Offset: 0x10, DWARF: 0xC95D5
    signed int res[3]; // Offset: 0x14, DWARF: 0xC95F9
} VspDispEnv;

// Size: 0x4, DWARF: 0xC8862
typedef struct Boost
{
    char num; // Offset: 0x0, DWARF: 0xC887E
    char charge; // Offset: 0x1, DWARF: 0xC889E
    char res[2]; // Offset: 0x2, DWARF: 0xC88C1
} Boost;

// Size: 0x10, DWARF: 0xC8D8A
typedef struct Match //: signed int[2]
{
    // Size: 0x4, DWARF: 0xC8862
    Boost boost; // Offset: 0x0, DWARF: 0xC8DA6
    signed int push; // Offset: 0x4, DWARF: 0xC8DCA
    signed int res[2]; // Offset: 0x8, DWARF: 0xC8DEB
} Match;

// Size: 0x10, DWARF: 0xC7F0C
typedef struct BalanceState
{
    signed int state; // Offset: 0x0, DWARF: 0xC7F28
    float per; // Offset: 0x4, DWARF: 0xC7F4A
    signed int res[2]; // Offset: 0x8, DWARF: 0xC7F6A
} BalanceState;

// Size: 0x4, DWARF: 0xC6B19
typedef struct Bar // : <unknown type 0xC0001>
{
    char num; // Offset: 0x0, DWARF: 0xC6B35
    char charge; // Offset: 0x1, DWARF: 0xC6B55
    char left; // Offset: 0x2, DWARF: 0xC6B78
    char res; // Offset: 0x3, DWARF: 0xC6B99
} Bar;

// Size: 0x10, DWARF: 0xC5718
typedef struct Points //: signed int
{
    signed int single; // Offset: 0x0, DWARF: 0xC5734
    signed int total; // Offset: 0x4, DWARF: 0xC5757
    signed int freeride; // Offset: 0x8, DWARF: 0xC5779
    signed int link_rate; // Offset: 0xC, DWARF: 0xC579E
} Points;

// Size: 0x38, DWARF: 0xCAEB7
typedef struct VspDispEnvChar
{
    // Size: 0x10, DWARF: 0xC5718
    Points points; // Offset: 0x0, DWARF: 0xCAED3
    // Size: 0x4, DWARF: 0xC6B19
    Bar bar; // Offset: 0x10, DWARF: 0xCAEF8
    // Size: 0x10, DWARF: 0xC7F0C
    BalanceState balance; // Offset: 0x14, DWARF: 0xCAF1A
    // Size: 0x10, DWARF: 0xC8D8A
    Match match; // Offset: 0x24, DWARF: 0xCAF40
    signed int rank; // Offset: 0x34, DWARF: 0xCAF64
} VspDispEnvChar;

// Size: 0x10, DWARF: 0xCD73E
typedef struct Course // : signed int[2]
{
    // Size: 0x20, DWARF: 0xC6972
    Fog* fog; // Offset: 0x0, DWARF: 0xCD75A
    signed int no; // Offset: 0x4, DWARF: 0xCD77F
    signed int res[2]; // Offset: 0x8, DWARF: 0xCD79E
} Course;

// Size: 0x14, DWARF: 0xCF840
typedef struct Game
{
    signed int player; // Offset: 0x0, DWARF: 0xCF85D
    signed int nplayer; // Offset: 0x4, DWARF: 0xCF880
    signed int pause; // Offset: 0x8, DWARF: 0xCF8A4
    signed int mode; // Offset: 0xC, DWARF: 0xCF8C6
    signed int wid; // Offset: 0x10, DWARF: 0xCF8E7
} Game;

// Size: 0x8C, DWARF: 0xCFCA6, 0xD7795
typedef struct VspEvent
{
    // Size: 0x10, DWARF: 0xCD73E
    Course course; // Offset: 0x0, DWARF: 0xCFCC3
    // Size: 0x34, DWARF: 0xCDCF7
    SpfreeCharacter character[2]; // Offset: 0x10, DWARF: 0xCFCE8
    // Size: 0x14, DWARF: 0xCF840
    Game game; // Offset: 0x78, DWARF: 0xCFD10
} VspEvent;

// Size: 0x4, DWARF: 0xD0CCF
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0xD0CEC
} CourseNo;

// Size: 0x3C, DWARF: 0xC75E0
typedef struct SpenvCharacter
{
    signed int no; // Offset: 0x0, DWARF: 0xC75FC
    signed int player; // Offset: 0x4, DWARF: 0xC761B
    signed int wear; // Offset: 0x8, DWARF: 0xC763E
    signed int board; // Offset: 0xC, DWARF: 0xC765F
    // Size: 0x1C, DWARF: 0xCF1CB
    Character_Param chr_param; // Offset: 0x10, DWARF: 0xC7681
    // Size: 0x10, DWARF: 0xCFBF5
    Board_Param brd_param; // Offset: 0x2C, DWARF: 0xC76A9
} SpenvCharacter;

// Size: 0x18, DWARF: 0xD0F25
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0xD0F42
    signed int game_mode; // Offset: 0x4, DWARF: 0xD0F69
    signed int match_rule; // Offset: 0x8, DWARF: 0xD0F8F
    signed int divide; // Offset: 0xC, DWARF: 0xD0FB6
    signed int handicap[2]; // Offset: 0x10, DWARF: 0xD0FD9
} Mode;

// Size: 0xA0, DWARF: 0xC28C5
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0xD0CCF
    CourseNo course; // Offset: 0x0, DWARF: 0xC28E0
    // Size: 0x3C, DWARF: 0xC75E0
    SpenvCharacter character[2]; // Offset: 0x4, DWARF: 0xC2905
    // Size: 0x18, DWARF: 0xD0F25
    Mode mode; // Offset: 0x7C, DWARF: 0xC292D
    signed int language; // Offset: 0x94, DWARF: 0xC2950
    signed int ending; // Offset: 0x98, DWARF: 0xC2975
    signed int bgm_no; // Offset: 0x9C, DWARF: 0xC2998
} VspenvGame;

// Size: 0x2DBFC, DWARF: 0xCD375
typedef struct VspReplay
{
    // Size: 0x4, DWARF: 0xD0CCF
    CourseNo spenv_course; // Offset: 0x0, DWARF: 0xCD391
    // Size: 0x3C, DWARF: 0xC75E0
    SpenvCharacter spenv_character; // Offset: 0x4, DWARF: 0xCD3BC
    // Size: 0x18, DWARF: 0xD0F25
    Mode spenv_gamemode; // Offset: 0x40, DWARF: 0xCD3EA
    // Size: 0x24, DWARF: 0xC7B3F
    Spenv_KeyConfig spenv_keyconfig; // Offset: 0x58, DWARF: 0xCD417
    // Size: 0x30, DWARF: 0xC7D2A
    Cheats spenv_cheats; // Offset: 0x7C, DWARF: 0xCD445
    signed short pid; // Offset: 0xAC, DWARF: 0xCD470
    unsigned short rand_num; // Offset: 0xAE, DWARF: 0xCD490
    signed int num_frame; // Offset: 0xB0, DWARF: 0xCD4B5
    signed int endrun_frame; // Offset: 0xB4, DWARF: 0xCD4DB
    unsigned int game_time; // Offset: 0xB8, DWARF: 0xCD504
    // Size: 0x8, DWARF: 0xC9763
    Pad pad_data[23400]; // Offset: 0xBC, DWARF: 0xCD52A
} VspReplay;

// Size: 0x5C, DWARF: 0xC2390
typedef struct VspModeData
{
    // DWARF: 0xD114B
    FlowMode flow_mode; // Offset: 0x0, DWARF: 0xC23AB
    unsigned int game_time_limit; // Offset: 0x4, DWARF: 0xC23D3
    unsigned int game_time; // Offset: 0x8, DWARF: 0xC23FF
    unsigned int game_count; // Offset: 0xC, DWARF: 0xC2425
    unsigned int realtime_count; // Offset: 0x10, DWARF: 0xC244C
    unsigned int flow_count; // Offset: 0x14, DWARF: 0xC2477
    signed int can_pause; // Offset: 0x18, DWARF: 0xC249E
    signed int modnum; // Offset: 0x1C, DWARF: 0xC24C4
    signed int bgm_no; // Offset: 0x20, DWARF: 0xC24E7
    signed int replay_speed; // Offset: 0x24, DWARF: 0xC250A
    signed int num_window; // Offset: 0x28, DWARF: 0xC2533
    signed int horse_pid; // Offset: 0x2C, DWARF: 0xC255A
    signed int end_sliding; // Offset: 0x30, DWARF: 0xC2580
    signed int pause; // Offset: 0x34, DWARF: 0xC25A8
    signed int pre_pause; // Offset: 0x38, DWARF: 0xC25CA
    // DWARF: 0xD114B
    FlowMode next_flow_mode; // Offset: 0x3C, DWARF: 0xC25F0
    // DWARF: 0xC7C96
    Restart restart; // Offset: 0x40, DWARF: 0xC261D
    signed int next_modnum; // Offset: 0x44, DWARF: 0xC2643
    signed int next_bgm_no; // Offset: 0x48, DWARF: 0xC266B
    signed int fade; // Offset: 0x4C, DWARF: 0xC2693
    signed int to_end_sliding; // Offset: 0x50, DWARF: 0xC26B4
    signed int next_replay_speed; // Offset: 0x54, DWARF: 0xC26DF
    signed int next_pause; // Offset: 0x58, DWARF: 0xC270D
} VspModeData;

// Size: 0x8, DWARF: 0xCAB49
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0xCAB65
    signed int bgm; // Offset: 0x4, DWARF: 0xCAB84
} Volume;

// Size: 0x48, DWARF: 0xCDC6C
typedef struct Bgm //: <unknown type 0xC0008>
{
    signed int table[16]; // Offset: 0x0, DWARF: 0xCDC88
    signed int disable; // Offset: 0x40, DWARF: 0xCDCAC
    signed int random; // Offset: 0x44, DWARF: 0xCDCD0
} Bgm;

// Size: 0x114, DWARF: 0xCE89D
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0xC7B3F
    Spenv_KeyConfig key_config[2]; // Offset: 0x0, DWARF: 0xCE8BA
    // Size: 0x30, DWARF: 0xC7D2A
    Cheats enable; // Offset: 0x48, DWARF: 0xCE8E3
    // Size: 0x30, DWARF: 0xC7D2A
    Cheats cheats; // Offset: 0x78, DWARF: 0xCE908
    // Size: 0x8, DWARF: 0xCAB49
    Volume volume; // Offset: 0xA8, DWARF: 0xCE92D
    char name[16]; // Offset: 0xB0, DWARF: 0xCE952
    signed int divide; // Offset: 0xC0, DWARF: 0xCE975
    signed int tutorial; // Offset: 0xC4, DWARF: 0xCE998
    // Size: 0x48, DWARF: 0xCDC6C
    Bgm bgm; // Offset: 0xC8, DWARF: 0xCE9BD
    unsigned int movie; // Offset: 0x110, DWARF: 0xCE9DF
} VspenvOption;

// Size: 0x18, DWARF: 0xC6888
typedef struct Clock //: signed int
{
    signed int year; // Offset: 0x0, DWARF: 0xC68A4
    signed int month; // Offset: 0x4, DWARF: 0xC68C5
    signed int day; // Offset: 0x8, DWARF: 0xC68E7
    signed int hour; // Offset: 0xC, DWARF: 0xC6907
    signed int minute; // Offset: 0x10, DWARF: 0xC6928
    signed int second; // Offset: 0x14, DWARF: 0xC694B
} Clock;

// Size: 0x38, DWARF: 0xC846B
typedef struct File //: char[32]
{
    // Size: 0x18, DWARF: 0xC6888
    Clock clock; // Offset: 0x0, DWARF: 0xC8487
    char name[32]; // Offset: 0x18, DWARF: 0xC84AB
} File;

// Size: 0x10, DWARF: 0xCFD5D
typedef struct TestReg
{
    signed int atest; // Offset: 0x0, DWARF: 0xCFD7A
    signed int aref; // Offset: 0x4, DWARF: 0xCFD9C
    signed int afail; // Offset: 0x8, DWARF: 0xCFDBD
    signed int send; // Offset: 0xC, DWARF: 0xCFDDF
} TestReg;

// Size: 0x74, DWARF: 0xCF92F
typedef struct SpenvNormalCharacter
{
    signed int secret; // Offset: 0x0, DWARF: 0xCF94C
    unsigned int board; // Offset: 0x4, DWARF: 0xCF96F
    unsigned int course; // Offset: 0x8, DWARF: 0xCF991
    signed int rem_point; // Offset: 0xC, DWARF: 0xCF9B4
    signed int old_brd_no; // Offset: 0x10, DWARF: 0xCF9DA
    signed int old_wear_no; // Offset: 0x14, DWARF: 0xCFA01
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0xCFA29
    signed int soft[8]; // Offset: 0x38, DWARF: 0xCFA52
    // Size: 0x1C, DWARF: 0xCF1CB
    Character_Param parameter; // Offset: 0x58, DWARF: 0xCFA75
} SpenvNormalCharacter;

// Size: 0xEC, DWARF: 0xD06FE
typedef struct SpenvCreatedCharacter
{
    // Size: 0x74, DWARF: 0xCF92F
    SpenvNormalCharacter character; // Offset: 0x0, DWARF: 0xD071B
    // Size: 0x1C, DWARF: 0xCF1CB
    Character_Param init_param; // Offset: 0x74, DWARF: 0xD0743
    // Size: 0x18, DWARF: 0xC6888
    Clock clock; // Offset: 0x90, DWARF: 0xD076C
    char name[16]; // Offset: 0xA8, DWARF: 0xD0790
    signed int age; // Offset: 0xB8, DWARF: 0xD07B3
    signed int sex; // Offset: 0xBC, DWARF: 0xD07D3
    signed int face; // Offset: 0xC0, DWARF: 0xD07F3
    signed int hair; // Offset: 0xC4, DWARF: 0xD0814
    signed int hair_color; // Offset: 0xC8, DWARF: 0xD0835
    signed int body; // Offset: 0xCC, DWARF: 0xD085C
    signed int body_color; // Offset: 0xD0, DWARF: 0xD087D
    signed int pants; // Offset: 0xD4, DWARF: 0xD08A4
    signed int pants_color; // Offset: 0xD8, DWARF: 0xD08C6
    signed int glove; // Offset: 0xDC, DWARF: 0xD08EE
    signed int boots; // Offset: 0xE0, DWARF: 0xD0910
    signed int board_type; // Offset: 0xE4, DWARF: 0xD0932
    signed int trick_type; // Offset: 0xE8, DWARF: 0xD0959
} SpenvCreatedCharacter; // Offset: 0x2DBAC, DWARF: 0xCAD41

// Size: 0x2DCEC, DWARF: 0xCAC24
typedef struct VspenvReplay
{
    // Size: 0x38, DWARF: 0xC846B
    File file; // Offset: 0x0, DWARF: 0xCAC40
    signed int pid; // Offset: 0x38, DWARF: 0xCAC63
    signed int num_frame; // Offset: 0x3C, DWARF: 0xCAC83
    unsigned int game_time; // Offset: 0x40, DWARF: 0xCACA9
    signed int endrun_frame; // Offset: 0x44, DWARF: 0xCACCF
    // Size: 0x8, DWARF: 0xC9763
    Pad pad_data[23400]; // Offset: 0x48, DWARF: 0xCACF8
    // Size: 0x24, DWARF: 0xC7B3F
    Spenv_KeyConfig key; // Offset: 0x2DB88, DWARF: 0xCAD1F
    // Size: 0xEC, DWARF: 0xD06FE
    SpenvCreatedCharacter character; // Offset: 0x2DBAC, DWARF: 0xCAD41
    // Size: 0x30, DWARF: 0xC7D2A
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0xCAD69
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0xCAD8E
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0xCADB1
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0xCADD4
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0xCADF8
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0xCAE1B
    // Size: 0x10, DWARF: 0xCFBF5
    Board_Param brd_param; // Offset: 0x2DCDC, DWARF: 0xCAE41
} VspenvReplay;

// Size: 0x10, DWARF: 0xCC5AF
typedef struct VspDispVsScore //: signed int
{
    signed int win; // Offset: 0x0, DWARF: 0xCC5CB
    signed int lose; // Offset: 0x4, DWARF: 0xCC5EB
    signed int draw; // Offset: 0x8, DWARF: 0xCC60C
    signed int res; // Offset: 0xC, DWARF: 0xCC62D
} VspDispVsScore;

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

// Size: 0x10, DWARF: 0xCD5EA
typedef struct Tex
{
    signed short tofs; // Offset: 0x0, DWARF: 0xCD606
    signed short cofs; // Offset: 0x2, DWARF: 0xCD627
    signed short width; // Offset: 0x4, DWARF: 0xCD648
    signed short height; // Offset: 0x6, DWARF: 0xCD66A
    signed short tw; // Offset: 0x8, DWARF: 0xCD68D
    signed short th; // Offset: 0xA, DWARF: 0xCD6AC
    signed short image_bit; // Offset: 0xC, DWARF: 0xCD6CB
    signed short clut_bit; // Offset: 0xE, DWARF: 0xCD6F1
} Tex;

// Size: 0x20, DWARF: 0xD019D
typedef struct Utd
{
    unsigned int* utd; // Offset: 0x0, DWARF: 0xD01BA
    // Size: 0x10, DWARF: 0xCD5EA
    Tex* tex; // Offset: 0x4, DWARF: 0xD01DD
    signed int ntex; // Offset: 0x8, DWARF: 0xD0202
    signed int offset; // Offset: 0xC, DWARF: 0xD0223
    signed int block; // Offset: 0x10, DWARF: 0xD0246
    unsigned int* frame; // Offset: 0x14, DWARF: 0xD0268
    signed int res[2]; // Offset: 0x18, DWARF: 0xD028D
} Utd;

// Size: 0x960, DWARF: 0xC2738
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
    ModelChange* change[2]; // Offset: 0x950, DWARF: 0xC2827
    char padding[8]; // Not in struct, but pads for alignment/size/
} Model;

// Size: 0x12F0, DWARF: 0xC7295
typedef struct Cd //: unsigned long[2]
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

// Size: 0x90, DWARF: 0xC89B0
typedef struct tag_ulcodCOORDINATE
{
    struct tag_ulcodCOORDINATE* super; // Offset: 0x0, DWARF: 0xC89D8
    unsigned int flag; // Offset: 0x4, DWARF: 0xC89FF
    unsigned int id; // Offset: 0x8, DWARF: 0xC8A20
    signed int parent; // Offset: 0xC, DWARF: 0xC8A3F
    float mat[4][4]; // Offset: 0x10, DWARF: 0xC8A62
    float tmp[4][4]; // Offset: 0x50, DWARF: 0xC8A84
} tag_ulcodCOORDINATE;

// Size: 0x40, DWARF: 0xC6E39
typedef struct Poly // Size: 0x8, DWARF: 0xCAAE8
{
    // Size: 0x10, DWARF: 0xC8D27
    Giftag giftag; // Offset: 0x0, DWARF: 0xC6E55
    // Size: 0x8, DWARF: 0xC9402
    Prim prim; // Offset: 0x10, DWARF: 0xC6E7A
    // Size: 0x8, DWARF: 0xC9EAF
    Rgbaq rgbaq0; // Offset: 0x18, DWARF: 0xC6E9D
    // Size: 0x8, DWARF: 0xCAAE8
    XYZF_Type xyzf0; // Offset: 0x20, DWARF: 0xC6EC2
    // Size: 0x8, DWARF: 0xCAAE8
    XYZF_Type xyzf1; // Offset: 0x28, DWARF: 0xC6EE6
    // Size: 0x8, DWARF: 0xCAAE8
    XYZF_Type xyzf2; // Offset: 0x30, DWARF: 0xC6F0A
    // Size: 0x8, DWARF: 0xCAAE8
    XYZF_Type xyzf3; // Offset: 0x38, DWARF: 0xC6F2E
} Poly;

//// Variables ////////////////////////////////////////////////

signed int vspDisp2D; // Address: 0x2E77F0
static signed int vspChangeScreen; // Address: 0x2E7B40
static signed int vspBgmTable[8]; // Address: 0x0
signed int vspIntroCutNum; // Address: 0x2E7B44
// Size: 0x108C, DWARF: 0xCA873
VspVsData vspVsData; // Address: 0x3BE590
// Size: 0x8C, DWARF: 0xCFCA6
VspEvent* vspEvent; // Address: 0x2E7Bf68
// Size: 0xA0, DWARF: 0xC28C5
VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix vspSystemMatrix[2]; // Address: 0x3BF6B0
// Size: 0x20, DWARF: 0xC7745
VifPacket vspLocalVif1Pkt; // Address: 0x3BF680
__int128* vspLocalVif1PktBuff; // Address: 0x2E7B6C
// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt vspLocalGifPkt; // Address: 0x3BF6A0
__int128* vspLocalGifPktBuff; // Address: 0x2E7B70
signed int vspEndRunReplay; // Address: 0x2E7B80
signed int vspEndRun; // Address: 0x2E7B84
signed int vspPlayIntro; // Address: 0x2E7B78
signed int vspInitHorse; // Address: 0x2E7B7C
// Size: 0x5C, DWARF: 0xC2390
VspModeData vspModeData; // Address: 0x3BF620
void(*vgmsysEndFunc)(signed int, signed int); // Address: 0x2E79AC
void(spFreeRideEnd)(signed int, signed int); // Address: 0x199160
signed int(*vgmsysFrameFunc)(signed int); // Address: 0x2E79B0
signed int(spFreeRideFrame)(signed int); // Address: 0x1991F0
signed int vgmsysPadPausePid; // Address: 0x2E7B2C
signed int vspEventCamera; // Address: 0x2E7B74
signed int vspFadeCol; // Address: 0x2E7B64
signed int vspFadePercent; // Address: 0x2E7B60
// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
// Size: 0x790, DWARF: 0xC702B
VgmsysFrameBuffer vgmsysFrameBuffer; // Address: 0x2EEB10
// Size: 0x360, DWARF: 0xCBF1B
VulsysSystem vulsysSystem; // Address: 0x2F3A50
// Size: 0x20, DWARF: 0xC8303
VgmsysAbuf* vgmsysAbuf; // Address: 0x2E79C0
// Size: 0x5640, DWARF: 0xC81B4
Rider* vspRider[8]; // Address: 0x3BD480
signed int vspWndFadePercent[2]; // Address: 0x2E7B58
// Size: 0x20, DWARF: 0xC7745
VifPacket* vgmsysVif1Pkt; // Address: 0x2E79C8
signed int vspVsWid; // Address: 0x2E7B50
// Size: 0x20, DWARF: 0xC952C
VspDispEnv vspDispEnv; // Address: 0x3BE570
// Size: 0x824, DWARF: 0xCD7C4
HorseBestCombo vspDispResult[2]; // Address: 0x3BD4B0
// Size: 0x38, DWARF: 0xCAEB7
VspDispEnvChar vspDispEnvChar[2]; // Address: 0x3BE500
// Size: 0x2DBFC, DWARF: 0xCD375
VspReplay* vspReplay[2]; // Address: 0x2E7B48
signed int vsppScrHeight; // Address: 0x2E7708
signed int vsppScrWidth; // Address: 0x2E7704
// Size: 0x114, DWARF: 0xCE89D
VspenvOption* vspenvOption; // Address: 0x2E7B10
// Size: 0x2DCEC, DWARF: 0xCAC24
VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
unsigned int vgmsysPadAllowPause; // Address: 0x2E7B24
// Size: 0x10, DWARF: 0xCC5AF
VspDispVsScore vspDispVsScore; // Address: 0x3BD4A0

//// Function Declarations ////////////////////////////////////////////////

void spFreeRideInit();
static void spFreeRideEnd();
static signed int spFreeRideFrame(signed int modnum);
static void spfrMainLoop();
static void spfrReset(signed int modnum);
static void spfrMalloc();
static void spfrFree();
static void spInitModeData(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md, signed int modnum, // DWARF: 0xC7C96
Restart restart);
static void spInitVsData(// Size: 0x108C, DWARF: 0xCA873
VspVsData* vd);
static void spInitReplay(signed int load_replay);
static void spInitReplay_1(signed int pid);
static void spInitMatrix(// Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx);
static void spInitScreenInfo(// Size: 0x30, DWARF: 0xC6530
ScreenInfo* scr);
static void spInitFog(// Size: 0x20, DWARF: 0xC6972
Fog* fog);
static void spInitDisp(// Size: 0x20, DWARF: 0xC952C
VspDispEnv* disp, // Size: 0x38, DWARF: 0xCAEB7
VspDispEnvChar* dc, // Size: 0x824, DWARF: 0xCD7C4
HorseBestCombo* res);
static void spGetReplay(signed int pid);
static void spSetReplay(signed int pid);
static signed int spUpdateMode(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md);
static void spUpdateReplay(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md, signed int endrun);
static signed int spCheckFinish(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md, signed int replay);
static void spCheckPassFinishLine2(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md);
static void spFlowTrick(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md);
static void spFlowBoost(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md);
static void spFlowPush(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md);
static void spFlowHorse(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md);
static void spSetWndClip(// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt* gifpkt, signed int wid, signed int nwnd, signed int center, signed int send);
static void spMakeViewScreenMatrix(// Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx, signed int wid, signed int nwnd, signed int center);
static void spUpdateDispState(// Size: 0x5640, DWARF: 0xC81B4
Rider* rider, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx, signed int wid, signed int nwnd, signed int center);
static void spUpdateCamera_normal(signed int num_wnd, signed int horse_pid);
static void spUpdateCamera_pause(signed int wid);
static void spDivScreenSetting();
static void spSetCrsDrawParam(// Size: 0x30, DWARF: 0xC6251
CharacterRenderParams* param, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx, signed int pid);
static void spDrawCourse1(// Size: 0x30, DWARF: 0xC6251
CharacterRenderParams* param);
static void spDrawCourse2(// Size: 0x30, DWARF: 0xC6251
CharacterRenderParams* param);
static void spDrawRider(// Size: 0x20, DWARF: 0xC7745
VifPacket* vif1, // Size: 0x5640, DWARF: 0xC81B4
Rider* rider, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx);
static void spDrawRider2(// Size: 0x5640, DWARF: 0xC81B4
Rider* rider, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx);
static void spDrawRider2Tex(// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt* gifpkt, // Size: 0x5640, DWARF: 0xC81B4
Rider* rider);
void spSetFade(signed int per, signed int col);
void spSetWndFade(signed int wid, signed int per);
static void spFade(// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt* pkt, signed int per, signed int col);
void spEnterEventCameraMode();
void spExitEventCameraMode();
void spFreeRideInit();
static void spFreeRideEnd();
static signed int spFreeRideFrame(signed int modnum /* 0x10(r29) */);
static void spfrMainLoop();
// {
//     signed int flag; // 0x114(r29)
//     // Size: 0x2C00, DWARF: 0xCC651
//     Ctrl* rcc; // r18
//     // Size: 0x34, DWARF: 0xCDCF7
//     struct : const volatile // Size: 0x2C00, DWARF: 0xCC651
//     struct : volatile // Size: 0x340, DWARF: 0xC7FB6
//     VspSystemMatrix
//     Ctrl
//     SpfreeCharacter* chr; // r17
//     signed int p; // 0x110(r29)
//     signed int event_camera; // 0x10C(r29)
//     float cam_trans0[4]; // 0xE0(r29)
//     float cam_rot0[4]; // 0xD0(r29)
//     signed int pre_pause; // 0x108(r29)
//     signed int pause; // 0x104(r29)
//     // Size: 0x30, DWARF: 0xC6251
//     CharacterRenderParams param; // 0xA0(r29)
//     signed int i; // r16
//     // Size: 0x2C00, DWARF: 0xCC651
//     Ctrl* rc; // 0x100(r29)
//     // Size: 0x2A30, DWARF: 0xCA227
//     Disp* rdd; // 0xFC(r29)
//     // Size: 0x5640, DWARF: 0xC81B4
//     Rider* rider; // 0xF8(r29)
//     // Size: 0x340, DWARF: 0xC7FB6
//     VspSystemMatrix sys_mat; // r19
//     signed int wid; // 0xF4(r29)
//     signed int pid; // r23
//     signed int horse_pid; // r21
//     signed int num_wnd; // r30
//     signed int num_player; // r22
//     signed int num_rider; // r20 
//     // Line: 688, Address: 0x199300
// }

static void spfrReset(signed int modnum /* 0xB0(r29) */);
// {
//     // Size: 0x34, DWARF: 0xCDCF7
//     SpfreeCharacter* chr; // r18
//     signed int i; // r16
//     // Size: 0x2C00, DWARF: 0xCC651
//     Ctrl* rc; // r17
//     signed int horse_endrun; // 0xA0(r29)
//     signed int horse; // r22
//     signed int demo; // r30
//     signed int load_replay; // r21
//     signed int replay_start; // r20
//     signed int num_rider; // r23
//     signed int num_player; // r19
    
//     // Line: 1219, Address: 0x19A110
// }
static void spfrMalloc();
static void spfrFree();
static void spInitModeData(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0x30(r29) */, signed int modnum /* 0x40(r29) */, // DWARF: 0xC7C96
Restart restart /* 0x50(r29) */);
static void spInitVsData(// Size: 0x108C, DWARF: 0xCA873
VspVsData* vd /* 0x30(r29) */);
static void spInitReplay(signed int load_replay /* 0x30(r29) */);
static void spInitReplay_1(signed int pid /* 0x20(r29) */);
// {
//     // Size: 0x2DBFC, DWARF: 0xCD375
//     VspReplay* rep; // r16
// }

static void spInitMatrix(// Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx /* 0x10(r29) */);
static void spInitScreenInfo(// Size: 0x30, DWARF: 0xC6530
ScreenInfo* scr /* 0x10(r29) */);
static void spInitFog(// Size: 0x20, DWARF: 0xC6972
Fog* fog /* r29 */);
static void spInitDisp(// Size: 0x20, DWARF: 0xC952C
VspDispEnv* disp /* 0x20(r29) */, // Size: 0x38, DWARF: 0xCAEB7
VspDispEnvChar* dc /* 0x30(r29) */, // Size: 0x824, DWARF: 0xCD7C4
HorseBestCombo* res /* 0x40(r29) */);
static void spGetReplay(signed int pid /* 0x20(r29) */);
static void spSetReplay(signed int pid /* 0x20(r29) */);
static signed int spUpdateMode(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0xC0(r29) */);
// {
//     signed int update_count; // 0xB4(r29)
//     signed int num_pass_finish_line; // r23
//     signed int notime; // 0xB0(r29)
//     unsigned int game_time; // r21
//     signed int pause; // 0xAC(r29)
//     signed int i; // r16
//     signed int state; // r20
//     // Size: 0x2580, DWARF: 0xC2EBE
//     Act* act; // r18
//     // Size: 0x2C00, DWARF: 0xCC651
//     Ctrl* rc; // r30
//     signed int horse_pid; // r19
//     signed int num_player; // r17
//     signed int num_rider; // r22
    
//     // Line: 2077, Address: 0x19B910
//     // Line: 2078, Address: 0x19B940
// }

static void spUpdateReplay(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0x60(r29) */, signed int endrun /* 0x70(r29) */);
// {
//     signed int i; // r18
//     unsigned int frame; // r19
//     // Size: 0x2C00, DWARF: 0xCC651
//     struct : volatile // Size: 0x340, DWARF: 0xC7FB6
//     VspSystemMatrix
//     Ctrl* rc; // r17
//     // Size: 0x2DBFC, DWARF: 0xCD375
//     VspReplay* rep; // r16
//     signed int horse_pid; // r21
//     signed int num_player; // r20
    
//     // Line: 2857, Address: 0x19CC20
// }

static signed int spCheckFinish(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0x70(r29) */, signed int replay /* 0x80(r29) */);
// {
//     signed int go_end; // r21
//     signed int state; // r19
//     signed int j; // r17
//     signed int i; // r18
//     // Size: 0x2580, DWARF: 0xC2EBE
//     Act* act; // r16
//     signed int num_player; // r20
// }

static void spCheckPassFinishLine2(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0x40(r29) */);
// {
//     signed int j; // r17
//     signed int i; // r18
//     // Size: 0x2580, DWARF: 0xC2EBE
//     Act* act; // r16
//     signed int num_player; // r19
// }

static void spFlowTrick(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0x40(r29) */);
static void spFlowBoost(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0x80(r29) */);
static void spFlowPush(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0xE0(r29) */);
// {
//     signed int tmp; // r17
//     signed int set_result; // 0xD0(r29)
//     signed int push_cnt; // 0xCC(r29)
//     signed int cnt[2]; // 0xA0(r29)
//     unsigned int pts; // r21
//     // Size: 0x98, DWARF: 0xCB0BC
//     TrickLink* tl; // r30
//     signed int i; // r16
//     // Size: 0x2580, DWARF: 0xC2EBE
//     Act* act; // r18
//     signed int line_center_to; // 0xC8(r29)
//     signed int line_center; // r23
//     signed int cnt_move; // 0xC4(r29)
//     signed int center_to; // r19
//     signed int center; // r22
//     signed int dead_line1; // 0xC0(r29)
//     signed int dead_line0; // 0xBC(r29)
//     signed int move_length; // 0xB8(r29)
//     signed int scr_size0; // 0xB4(r29)
//     signed int scr_size; // 0xB0(r29)
//     signed int num_player; // r20
//     signed int div_side; // 0xAC(r29)
    
//     // Line: 3300, Address: 0x19D800
// }

static void spFlowHorse(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0x90(r29) */);
// {
//     unsigned int pts1; // r22
//     unsigned int pts0; // r20
//     signed int set_result; // r21
//     // Size: 0x2580, DWARF: 0xC2EBE
//     Act* act; // r16
//     signed int pid1; // r19
//     signed int pid0; // r17
//     signed int state; // r18
// }

static void spSetWndClip(// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt* gifpkt /* 0x90(r29) */, signed int wid /* 0xA0(r29) */, signed int nwnd /* 0xB0(r29) */, signed int center /* 0xC0(r29) */, signed int send /* 0xD0(r29) */);
// {
//     unsigned long scy1; // r19
//     unsigned long scx1; // r18
//     unsigned long scy0; // r17
//     unsigned long scx0; // r16
//     unsigned long scissor; // r20
//     // Size: 0x10, DWARF: 0xCFD5D
//     TestReg testreg[2]; // 0x70(r29)
//     signed int div_side; // r21
    
//     // Line: 3635, Address: 0x19E3A0
// }

static void spMakeViewScreenMatrix(// Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx /* 0xA0(r29) */, signed int wid /* 0xB0(r29) */, signed int nwnd /* 0xC0(r29) */, signed int center /* 0xD0(r29) */);
// {
//     // Size: 0x30, DWARF: 0xC6530
//     ScreenInfo* scr; // r16
//     unsigned long center_y; // r18
//     unsigned long center_x; // r17
//     unsigned long scy1; // r22
//     unsigned long scy0; // r21
//     unsigned long scx1; // r20
//     unsigned long scx0; // r19
//     signed int div_side; // r23
// }

static void spUpdateDispState(// Size: 0x5640, DWARF: 0xC81B4
Rider* rider /* 0x50(r29) */, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx /* 0x60(r29) */, signed int wid /* 0x70(r29) */, signed int nwnd /* 0x80(r29) */, signed int center /* 0x90(r29) */);
// {
//     signed int type; // r18
//     signed int in; // r17
//     // Size: 0x2A30, DWARF: 0xCA227
//     Disp* rdd; // r16
    
//     // Line: 3813, Address: 0x19E890
// }

static void spUpdateCamera_normal(signed int num_wnd /* 0x50(r29) */, signed int horse_pid /* 0x60(r29) */);
// {
//     signed int i; // r16
//     // DWARF: 0xD114B
//     FlowMode flow; // r18
//     signed int num_player; // r19
    
//     // Line: 3950, Address: 0x19E9C0
// }

static void spUpdateCamera_pause(signed int wid /* 0x70(r29) */);
static void spDivScreenSetting();
static void spSetCrsDrawParam(// Size: 0x30, DWARF: 0xC6251
CharacterRenderParams* param /* 0x80(r29) */, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx /* 0x90(r29) */, signed int pid /* 0xA0(r29) */);
static void spDrawCourse1(// Size: 0x30, DWARF: 0xC6251
CharacterRenderParams* param /* 0x10(r29) */);
static void spDrawCourse2(// Size: 0x30, DWARF: 0xC6251
CharacterRenderParams* param /* 0x10(r29) */);
static void spDrawRider(// Size: 0x20, DWARF: 0xC7745
VifPacket* vif1 /* 0x170(r29) */, // Size: 0x5640, DWARF: 0xC81B4
Rider* rider /* 0x180(r29) */, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx /* 0x190(r29) */);
// {
//     float light_color0[4]; // 0x160(r29)
//     // Size: 0x960, DWARF: 0xC2738
//     Model* md; // r17
//     // Size: 0x12F0, DWARF: 0xC7295
//     Cd* cd; // r18
//     float lc[4][4]; // 0x120(r29)
//     float nl[4][4]; // 0xE0(r29)
//     tag_ulcodCOORDINATE coord; // 0x50(r29)
//     // Size: 0x2A30, DWARF: 0xCA227
//     Disp* rdd; // r16
//     // Size: 0x2C00, DWARF: 0xCC651
//     Ctrl* rc; // r19
// }

static void spDrawRider2(// Size: 0x5640, DWARF: 0xC81B4
Rider* rider /* 0x160(r29) */, // Size: 0x340, DWARF: 0xC7FB6
VspSystemMatrix* mtx /* 0x170(r29) */);
// {
//     float light_color0[4]; // 0x150(r29)
//     // Size: 0x960, DWARF: 0xC2738
//     Model* md; // r18
//     // Size: 0x12F0, DWARF: 0xC7295
//     Cd* cd; // r17
//     float lc[4][4]; // 0x110(r29)
//     float nl[4][4]; // 0xD0(r29)
//     tag_ulcodCOORDINATE coord; // 0x40(r29)
//     // Size: 0x2A30, DWARF: 0xCA227
//     Disp* rdd; // r16 
// }

static void spDrawRider2Tex(// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt* gifpkt /* 0x50(r29) */, // Size: 0x5640, DWARF: 0xC81B4
Rider* rider /* 0x60(r29) */);
// {
//     signed int throw_goggle; // r19
//     signed int erase_goggle; // r18
//     // Size: 0x960, DWARF: 0xC2738
//     Model* md; // r16
//     // Size: 0x12F0, DWARF: 0xC7295
//     Cd* cd; // r17
// }

void spSetFade(signed int per /* r29 */, signed int col /* 0x10(r29) */);
void spSetWndFade(signed int wid /* r29 */, signed int per /* 0x10(r29) */);
static void spFade(// Size: 0x10, DWARF: 0xC5D1F
VspLocalGifPkt* pkt /* 0xB0(r29) */, signed int per /* 0xC0(r29) */, signed int col /* 0xD0(r29) */);
// {
//     // Size: 0x20, DWARF: 0xCDEE6
//     Alpha_Tag* a; // r22
//     // Size: 0x40, DWARF: 0xC6E39
//     Poly* poly; // r16
//     signed int qwc; // 0xAC(r29)
//     signed int alpha; // r30
//     signed int sy1; // r21
//     signed int sy0; // r20
//     signed int sx1; // r19
//     signed int sx0; // r17
//     signed int z; // r18
//     signed int wnd_width; // r23
// }
void spEnterEventCameraMode();
void spExitEventCameraMode();

// Other C function includes
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
__int128* ulgifAddCNTReserve(VspLocalGifPkt* pkt, signed int qwc);
void ulpktInitF4(Poly* pkt, signed int ctext);
void ktactSetCaminfo(// Size: 0x190, DWARF: 0x7F127
Cam* cam, // Size: 0x2C00, DWARF: 0x7627B
Ctrl* rc);

void spFreeRideInit(signed int modnum)
{
    int i;
    int numPlayers;
  
    numPlayers = vspenvGame->mode.num_player;
    vgmsysFrameFunc = spFreeRideFrame;
    vgmsysEndFunc  = spFreeRideEnd;
    vspModeData.restart = 1;
    vspInitHorse = 1;
    vspPlayIntro = 1;
    vspEndRun = 0;
    vspEndRunReplay = 0;
    vspChangeScreen = 0;
    spfrMalloc();
    spRiderInit();
    ayResultInit();
    nmdispInit();
    nmactInit();
    sceGifPkInit(vspLocalGifPkt,vspLocalGifPktBuff);
    sceGifPkReset(vspLocalGifPkt);
    sceVif1PkInit(vspLocalVif1Pkt,vspLocalVif1PktBuff);
    sceVif1PkReset(vspLocalVif1Pkt);
    akevInitEffect(numPlayers);
    vspEvent->course.fog = &vspSystemMatrix[0].fog;
    vspEvent->course.no = vspenvGame->course.no;
    vspEvent->character[0].no = 0;
    vspEvent->character[0].player = 1;
    vspEvent->game.player = 0;
    vspEvent->game.nplayer = numPlayers;
    vspEvent->game.pause = 0;
    vspEvent->game.mode = 0;
    vspEvent->game.wid = 0;
    tmevInit(vspEvent);
    for (i = 0; i < 2; i++) {
        vspVsData.result[i].cnt_horse = 0;
    }
    vspVsData.horse_num_round = 0;
    gmsysSetScrChangeColor(0xff,0xff,0xff);
    vspIntroCutNum = 0;
}

void spFreeRideEnd(signed int input1, signed int input2)
{
  akevFreeEffect();
  tmevEnd();
  ayResultEnd();
  spRiderEnd();
  spfrFree();
  sploadFreeGameCommon();
  nmsndEndGame();
  nmsndExit(0);
  gmsysSetScrChangeColor(0,0,0);
  gmsysSetScrFlipMode(0);
  gmsysSetScrDivType(0);
  gmsysPadReset();
}

signed int spFreeRideFrame(signed int modnum) {
  
  if (vspModeData.restart != 0) {
    spfrReset(modnum);
  }
  if (vspChangeScreen != 0) {
    gmsysSetScreenMode_normal();
    gmsysSetScrFlipMode(0);
    gmsysSetScrDivType(0);
    vspChangeScreen = 0;
  }
  vspModeData.next_pause = (unsigned int)vspEventCamera;
  vspModeData.pre_pause = vspModeData.pause;
  if (vgmsysPadPausePid >= 0) {
    vspModeData.pause = 1;
  }
  else {
    vspModeData.pause = vspModeData.next_pause;
  }
  if (vgmsysPadPausePid >= 0) {
    gmsysResetBlurPow();
  }
  if (vspModeData.flow_mode != 8) {
    spfrMainLoop();
  }
  modnum = spUpdateMode(&vspModeData.flow_mode);
  nmactFrame();
  return modnum;
}

void spfrMainLoop() {
    signed int i; // r16
    // Size: 0x34, DWARF: 0xCDCF7
    SpfreeCharacter* chr; // r17
    // Size: 0x2C00, DWARF: 0xCC651
    Ctrl* rcc; // r18
    // Size: 0x340, DWARF: 0xC7FB6
    VspSystemMatrix* sys_mat; // r19
    signed int num_rider; // r20
    signed int horse_pid; // r21
    signed int num_player; // r22
    signed int pid; // r23
    signed int num_wnd; // r30
    // Size: 0x30, DWARF: 0xC6251
    CharacterRenderParams param; // 0xA0(r29)
    sceVu0FVECTOR cam_rot0; // 0xD0(r29)
    sceVu0FVECTOR cam_trans0; // 0xE0(r29)
    signed int wid; // 0xF4(r29)
    // Size: 0x5640, DWARF: 0xC81B4
    Rider* rider; // 0xF8(r29)
    // Size: 0x2A30, DWARF: 0xCA227
    Disp* rdd; // 0xFC(r29)
    // Size: 0x2C00, DWARF: 0xCC651
    Ctrl* rc; // 0x100(r29)
    signed int pause; // 0x104(r29)
    signed int pre_pause; // 0x108(r29) 
    signed int event_camera; // 0x10C(r29)
    signed int p; // 0x110(r29)
    signed int flag; // 0x114(r29)
    
    num_rider = vspenvGame->mode.num_player;
    num_player = vspenvGame->mode.num_player;
    num_wnd = vspModeData.num_window;
    horse_pid = vspModeData.horse_pid;
    wid = 0;
    
    pause = vspModeData.pause;
    pre_pause = vspModeData.pre_pause;
    event_camera = vspEventCamera;
    vspVsWid = (vspVsWid + 1) % num_wnd;
    wid = vspVsWid;
    if (horse_pid >= 0) {
        pid = horse_pid;
    } else {
        pid = wid;
    }

    sys_mat = &vspSystemMatrix[pid];
    rider = vspRider[pid];
    rdd = &rider->disp;
    rc = &rider->ctrl;
    if (num_wnd == 1 || vspModeData.flow_mode == efmIntro) {
        spSetWndClip(vgmsysGifPkt, 0, 1, vspVsData.center, 1);
    } else {
        spSetWndClip(vgmsysGifPkt, wid, num_wnd, vspVsData.center, 1);
        spDivScreenSetting();
    }
    sceGifPkReset(vgmsysGifPkt);
    sceVif1PkReset(vgmsysVif1Pkt);
    ulgraphAlphaResetBuf(vgmsysAbuf);
    tmcrsTransTex(vgmsysGifPkt);
    ulgifTermPacket(vgmsysGifPkt);
    ulgifDmaSend(vgmsysGifPkt);
    if (vgmsysPadPausePid < 0) {
        if ((num_player == 1) || (horse_pid >= 0) || (vspModeData.flow_mode != efmIntro)) {
            knCoreGetWVMat(sys_mat->world_view, pid);
            knCoreGetWState(sys_mat->cam_trans, sys_mat->cam_rot, pid);
        } else {
            p = ((signed int) vspIntroCutNum >> 1) & 1;
            knCoreGetWVMat(sys_mat->world_view, p);
            knCoreGetWState(sys_mat->cam_trans, sys_mat->cam_rot, p);
        }
    } else {
        knCoreGetWVMat(sys_mat->world_view, pid);
        knCoreGetWState(sys_mat->cam_trans, sys_mat->cam_rot, pid);
    }
    if (num_wnd == 1 || (1 < num_player && vspModeData.flow_mode == efmIntro)) {
        spMakeViewScreenMatrix(sys_mat, 0, 1, vspVsData.center);
    } else {
        spMakeViewScreenMatrix(sys_mat, wid, num_wnd, vspVsData.center);
    }
    *(__int128*)cam_rot0 = *(__int128*)sys_mat->cam_rot;
    *(__int128*)cam_trans0 = *(__int128*)sys_mat->cam_trans;
    if (event_camera) {
        if (horse_pid >= 0) {
            vspRider[horse_pid]->ctrl.se.splen = 0.0f;
        } else {
            for (i = 0; i < num_player; i++) {
                vspRider[i]->ctrl.se.splen = 0.0f;
            }
        }
    }
    if (pause == 0) {
        for (i = 0; i < num_rider; i++) {
            tmevGetLightVector(vspRider[i]->disp.light_color0, &vspRider[i]->disp.normal_light0, vspRider[i]->disp.ambient, i);
            tmcrsGetObjectLight(vspRider[i]->disp.light_color2, vspRider[i]->disp.normal_light2, vspRider[i]->disp.nowpos.pos);
        }
    }
    for (i = 0; i < num_rider; i++) {
        spUpdateDispState(vspRider[i], sys_mat, wid, num_wnd, vspVsData.center);
    }
    spSetCrsDrawParam(&param, sys_mat, rider->pid);
    ulvif1DmaWait();
    sceVif1PkReset(&vspLocalVif1Pkt);
    param.vif1_packet = &vspLocalVif1Pkt;
    spDrawCourse1(&param);
    if (event_camera == 0) {
        if (horse_pid >= 0) {
            spDrawRider(param.vif1_packet, vspRider[horse_pid], sys_mat);
        } else {
            for (i = 0; i < num_rider; i++) {
                spDrawRider(param.vif1_packet, vspRider[i], sys_mat);
            }
        }
    }
    sceVif1PkEnd(param.vif1_packet, 0);
    sceVif1PkTerminate(param.vif1_packet);
    vulsysSystem.DmaVif1->chcr.TTE = 1;
    ulvif1DmaSend(param.vif1_packet->pBase);
    param.vif1_packet = vgmsysVif1Pkt;
    spDrawCourse2(&param);
    if (event_camera == 0) {
        if (horse_pid >= 0) {
            spDrawRider2(vspRider[horse_pid], sys_mat);
        } else {
            for (i = 0; i < num_rider; i++) {
                spDrawRider2(vspRider[i], sys_mat);
            }
        }
    }
    spRiderMain(horse_pid);
    if (vgmsysPadPausePid < 0) {
        spUpdateCamera_normal(num_wnd, horse_pid);
    } else {
        spUpdateCamera_pause(wid);
    }
    knCoreGetWState(sys_mat->cam_trans, sys_mat->cam_rot, pid);
    for (i = 0; i < num_rider; i++) {
        chr = &vspEvent->character[i];
        rcc = &vspRider[i]->ctrl;
        chr->base_attr = (signed int) rcc->nowpos.material;
        chr->nvector = (signed int) rcc->act.num_vec;
        chr->nhit = (signed int) rcc->act.num_hit;
        chr->nobj = (signed int) rcc->act.num_obj;
        chr->rail = (signed int) rcc->act.rail_id;
        chr->vector = rcc->act.col_vec;
        chr->hit = rcc->act.col_hit;
        chr->object = rcc->act.col_obj;
        chr->ctrl = rcc;
        chr->no = rcc->param->no;
    }
    vspEvent->game.player = pid;
    vspEvent->game.nplayer = num_player;
    vspEvent->game.pause = vgmsysPadPausePid < 0 ? 0 : 1;
    if (vspModeData.flow_mode == efmIntro) {
        vspEvent->game.mode = efmIntro;
    } else if (vspModeData.flow_mode == efmHorseReady) {
        vspEvent->game.mode = efmPlay;
    } else if (vspModeData.flow_mode == efmReplay || vspModeData.flow_mode == efmRepReady || vspModeData.flow_mode == efmRepEnd) {
        vspEvent->game.mode = efmReady;
    } else {
        vspEvent->game.mode = efmHorseReady;
    }
    
    vspEvent->game.wid = wid;
    vspEvent->course.fog = &vspSystemMatrix[pid].fog;
    tmevMainEvent(vspEvent);
    if (horse_pid >= 0) {
        vspEvent->game.player = horse_pid;
        vspEvent->course.fog = &vspSystemMatrix[horse_pid].fog;
        tmevPlayerEvent(vspEvent);
    } else {
        for (i = 0; i < num_player; i++) {
            vspEvent->game.player = i;
            vspEvent->course.fog = &vspSystemMatrix[i].fog;
            tmevPlayerEvent(vspEvent);
        }
    }
    *(__int128*)sys_mat->cam_rot = *(__int128*)cam_rot0;
    *(__int128*)sys_mat->cam_trans = *(__int128*)cam_trans0;
    if ((event_camera == 0) || (vspModeData.flow_mode == efmReplay)) {
        nmdispCalcTotalChar(pid);
    }
    sceGifPkReset(&vspLocalGifPkt);
    if (vspWndFadePercent[pid] > 0) {
        spFade(&vspLocalGifPkt, vspWndFadePercent[pid], 0xFF);
    }
    nmdispTransTex(&vspLocalGifPkt);
    if ((event_camera == 0) || (vspModeData.flow_mode == efmReplay)) {
        nmdispTotalChar(&vspLocalGifPkt, pid);
    }
    nmdispCalcTotal();
    if ((event_camera == 0) || (vgmsysPadPausePid >= 0) || (vspModeData.flow_mode == efmReplay)) {
        nmdispTotal(&vspLocalGifPkt);
    }
    ulgifTermPacket(&vspLocalGifPkt);
    vspEvent->game.player = pid;
    tmevDrawEvent(vspEvent);
    for (i = 0; i < num_player; i++) {
        vspEvent->game.player = i;
        tmevDrawPlayerEvent(vspEvent);
    }
    akevCalcEffect(&vspRider, sys_mat, pre_pause);
    akevDrawEffect1(vgmsysAbuf, sys_mat);
    if (nmdispGetMode() == 3) {
        nmdispModel(vgmsysGifPkt);
    }
    ulgraphAlphaSortPacket(vgmsysAbuf);
    ulgifDmaWait();
    ulvif1DmaWait();
    tmcrsFinish();
    if (horse_pid >= 0) {
        spDrawRider2Tex(vgmsysGifPkt, vspRider[horse_pid]);
    } else {
        for (i = 0; i < num_rider; i++) {
            spDrawRider2Tex(vgmsysGifPkt, vspRider[i]);
        }
    }
    tmcrsTransAlphaTex(vgmsysGifPkt);
    ulgifTermPacket(vgmsysGifPkt);
    ulgifDmaSend(vgmsysGifPkt);
    ulgifDmaWait();
    ulgraphAlphaDrawPacket(vulsysSystem.DmaGif, vgmsysAbuf);
    ulgifDmaWait();
    akevDrawEffect2(pid, vulsysSystem.DmaGif, sys_mat, &vgmsysFrameBuffer, pause);
    if (vspDisp2D) {
        ulgifDmaSend(&vspLocalGifPkt);
    }
    spRiderWriteData();
    
    ulgifDmaWait();
    ulvif1DmaWait();
    if (vspDisp2D == 0) {
        spSetWndClip(vgmsysGifPkt, 0, 1, vspVsData.center, 1);
    }
    if (vspFadePercent > 0) {
        sceGifPkReset(&vspLocalGifPkt);
        spFade(&vspLocalGifPkt, vspFadePercent, vspFadeCol);
        ulgifTermPacket(&vspLocalGifPkt);
        ulgifDmaSend(&vspLocalGifPkt);
        ulgifDmaWait();
    }
    if (event_camera != vspEventCamera) {
        flag = vspEventCamera ? 1 : 0;
        for (i = 0; i < num_player; i++) {
            if ((horse_pid < 0) || (i == horse_pid)) {
                ulpadSetDualPause(i, 0, 1, flag);
                if (flag) {
                    nmvcPause(i + 0xA);
                } else {
                    nmvcResume(i + 0xA);
                }
            }
        }
    }
}

void tmetcReset(void);

// spfree.c
void spfrReset(signed int modnum /* spB0 */) {
    signed int i; // r16
    // Size: 0x2C00, DWARF: 0xCC651
    Ctrl* rc; // r17
    // Size: 0x34, DWARF: 0xCDCF7
    SpfreeCharacter* chr; // r18
    signed int num_player; // r19
    signed int replay_start; // r20
    signed int load_replay; // r21
    signed int horse; // r22
    signed int num_rider; // r23
    signed int demo; // r30
    signed int horse_endrun; // 0xA0(r29)

    num_player = vspenvGame->mode.num_player;
    num_rider = vspenvGame->mode.num_player;
    replay_start = vspModeData.restart == 2 ? 1 : 0;
    load_replay = 0;
    demo = 0;
    horse = 0;
    horse_endrun = vspEndRun;
    if (vspenvGame->mode.game_mode == 1 && vspenvGame->mode.match_rule == 3) {
        horse = 1;
    }
    if (modnum == 0x14 || modnum == 0x15) {
        load_replay = 1;
    }
    if (modnum == 0x15) {
        demo = 1;
    }
    if (load_replay) {
        vspModeData.restart = 2;
        replay_start = 1;
        spInitReplay(load_replay);
    } else if (replay_start == 0 && horse == 0) {
        spInitReplay(load_replay);
    }
    gmsysSetScreenMode_on_play();
    if (replay_start == 0 || load_replay) {
        vspFadeCol = 0;
        vspFadePercent = 0;
    }
    for (i = 0; i < 2; i++) {
        vspWndFadePercent[i] = 0;
    }
    vspEndRunReplay = vspEndRun;
    vspEndRun = 0;
    vspEventCamera = 0;
    if (horse == 0) {
        vspInitHorse = 0;
    }
    if (vspInitHorse) {
        vspPlayIntro = 1;
        horse_endrun = 0;
    }
    vspVsWid = 0;
    vspDisp2D = 1;
    gmsysPadReset();
    gmsysResetBlurPow();
    if (horse) {
        if (vspInitHorse) {
            spInitReplay(0);
            spInitModeData(&vspModeData, modnum, vspModeData.restart);
            vspModeData.horse_pid = 0;
            spInitVsData(&vspVsData);
            tmevResetHorsePosition(1);
        } else {
            i = vspModeData.horse_pid;
            spInitModeData(&vspModeData, modnum, vspModeData.restart);
            if (replay_start == 0 || horse_endrun == 0) {
                i = (i + 1) % num_player;
            }
            vspModeData.horse_pid = i;
            if (replay_start == 0) {
                spInitReplay_1(i);
            }
            vspModeData.flow_mode = replay_start ? 5 : 1;
            vspModeData.next_flow_mode = vspModeData.flow_mode;
            if (vspVsData.horse_end_one_round) {
                vspVsData.result[0].point = 0;
                vspVsData.result[1].point = 0;
                vspVsData.horse_end_one_round = 0;
            }
            vspVsData.result[0].goal = 0;
            vspVsData.result[1].goal = 0;
        }
        vspModeData.num_window = 1;
    } else {
        spInitModeData(&vspModeData, modnum, vspModeData.restart);
        vspModeData.num_window = num_player;
        spInitVsData(&vspVsData);
    }
    if (vspModeData.num_window == 1) {
        gmsysSetScrFlipMode(0);
        gmsysSetScrDivType(0);
    } else {
        gmsysSetScrFlipMode(1);
        gmsysSetScrDivType(vspVsData.div_side ? 1 : 2);
    }
    spRiderReset();
    for (i = 0; i < num_player; i++) {
        spInitMatrix(&vspSystemMatrix[i]);
    }
    if (replay_start == 0 || load_replay) {
        spInitDisp(&vspDispEnv, &vspDispEnvChar, &vspDispResult);
        if (vspModeData.horse_pid >= 0) {
            if (vspInitHorse) {
                nmdispInit();
            } else {
                nmdispInitHorse();
            }
        } else {
            nmdispInit();
        }
        if (load_replay) {
            if (demo) {
                vspDispEnv.mode = 5;
            } else {
                vspDispEnv.mode = 4;
            }
        }
    }
    ktmfSetMenu();
    nmfontInitOption();
    akevResetEffect();
    if (load_replay) {
        if (demo) {
            nmsndStartDemo();
        } else {
            nmsndStartGame();
        }
    } else if (replay_start) {
        nmsndEndGame();
    }
    for (i = 0; i < num_rider; i++) {
        chr = &vspEvent->character[i];
        rc = &vspRider[i]->ctrl;
        chr->no = rc->param->no;
        chr->player = 1;
        chr->base_attr = rc->nowpos.material;
        chr->nvector = rc->act.num_vec;
        chr->nhit = rc->act.num_hit;
        chr->nobj = rc->act.num_obj;
        chr->rail = -1;
        chr->vector = rc->act.col_vec;
        chr->hit = rc->act.col_hit;
        chr->object = rc->act.col_obj;
        chr->ctrl = rc;

    }
    vspEvent->course.fog = &vspSystemMatrix[0].fog;
    vspEvent->course.no = (signed int) vspenvGame->course.no;
    vspEvent->game.player = 0;
    vspEvent->game.nplayer = num_player;
    vspEvent->game.pause = 0;
    if (replay_start) {
        vspEvent->game.mode = 2;
    } else if (vspPlayIntro == 0) {
        vspEvent->game.mode = 1;
    } else {
        vspEvent->game.mode = 0;
    }
    vspEvent->game.wid = 0;
    tmevReset(vspEvent);
    vspSystemMatrix[1].fog = vspSystemMatrix[0].fog;
    tmetcReset();
    if (vspModeData.horse_pid >= 0) {
        rc = &vspRider[vspModeData.horse_pid]->ctrl;
        ktactSetCaminfo(&rc->cam, rc);
        if (vspPlayIntro == 0) {
            knCameraSetScrZ(vspModeData.horse_pid);
        }
    } else {
        for (i = 0; i < num_player; i++) {
            rc = &vspRider[i]->ctrl;
            ktactSetCaminfo(&rc->cam, rc);
            if (vspPlayIntro == 0) {
                knCameraSetScrZ(i);
            }
        }
        rc = &vspRider[0]->ctrl;
    }
    if (replay_start && load_replay == 0) {
        knReplayInit(rc);
    } else {
        for (i = 0; i < num_player; i++) {
            knCameraInit(vspRider[i]->ctrl, i);
        }
        knReplayInit(rc);
        knIntroInit(rc);
    }
    if (horse) {
        if (vspInitHorse) {
            vspPlayIntro = 0;
            vspInitHorse = 0;
        }
    } else {
        if (vspPlayIntro == 0 && (vspDispEnv.mode != 3 || replay_start == 0 || load_replay)) {
            nmsndStartGame();
        }
        vspPlayIntro = 0;
    }
    if (vspModeData.flow_mode == 2 || vspModeData.flow_mode == 1) {
        spSetFade(255, 255);
    }
}

void spfrMalloc()
{
    void* replayMemAddress;
    void* gifPktBuffMemAddress;
    void* vifPktBuffMemAddress;
    void* eventMemAddress;

    replayMemAddress = (void*)0x2dbfc;
    vspReplay[0] = ulMalloc((unsigned int)replayMemAddress,0,1);
    vspReplay[1] = ulMalloc((unsigned int)replayMemAddress,0,1);
    gifPktBuffMemAddress = (void*)0x40000;
    vspLocalGifPktBuff = ulMalloc((unsigned int)gifPktBuffMemAddress,0, 0);
    vifPktBuffMemAddress = (void*)0x10000;
    vspLocalVif1PktBuff = ulMalloc((unsigned int)vifPktBuffMemAddress,0, 0);
    eventMemAddress = (void*)0x8C;
    vspEvent = ulMalloc((unsigned int)eventMemAddress,0, 0);
}

void spfrFree() {
    ulFree(vspReplay[0]);
    ulFree(vspReplay[1]);
    ulFree(vspLocalGifPktBuff);
    ulFree(vspLocalVif1PktBuff);
    ulFree(vspEvent);
}

// SPFREE.C
void spInitModeData(VspModeData* md, signed int modnum, Restart restart) {
    unsigned int time_limit = 0; // r18
    int tmp;
    int tmp2;

    if (vspPlayIntro != 0) {
        if (restart == 2) {
            tmp = 5;
        } else {
            tmp = 0;
        }
        md->flow_mode = tmp;
    } else {
        if (restart == 2) {
            tmp2 = 5;
        } else {
            tmp2 = 2;
        }
        md->flow_mode = tmp2;
    }
    md->game_time_limit = time_limit;
    md->game_time = 0;
    md->game_count = 0;
    md->realtime_count = 0;
    md->flow_count = 0;
    md->can_pause = 1;
    md->modnum = modnum;
    md->bgm_no = 0;
    md->replay_speed = 1;
    md->num_window = 1;
    md->horse_pid = -1;
    md->end_sliding = 0;
    md->pause = 0;
    md->pre_pause = 0;
    md->next_flow_mode = md->flow_mode;
    md->restart = 0;
    md->next_modnum = modnum;
    md->next_bgm_no = 0;
    md->fade = 0;
    md->to_end_sliding = 0;
    md->next_replay_speed = md->replay_speed;
    md->next_pause = 0;
}

void spInitVsData(VspVsData* vd) {
    signed int i; // r17
    // Size: 0x838, DWARF: 0xCD9AA
    Result* vdc; // r16

    // vd = vd; // 30
    if (vspenvGame->mode.divide == 0) {
        vd->div_side = 1;
    } else {
        vd->div_side = 0;
    }
    if (vd->div_side != 0) {
        vd->center = vsppScrWidth / 2;
    } else {
        vd->center = vsppScrHeight / 2;
    }
    vd->center_pos_id = 0;
    vd->center_to_pos_id = 0;
    vd->cnt_center_move = 0;
    vd->horse_num_round = 5;
    vd->horse_end_one_round = 0;
    for (i = 0; i < 2; i++) {
        vdc = &vd->result[i];
        vdc->goal = 0;
        vdc->time = 0;
        vdc->count = 0;
        vdc->point = 0;
        vdc->cnt_horse = 0;
        nmdispInitResult(vdc->horse_best_combo);
    }
}

void spInitReplay(signed int load_replay) {
    signed int i; // r16
    signed int num_player; // r17
    num_player = vspenvGame->mode.num_player;
    for (i = 0; i < num_player; i++) {
        spInitReplay_1(i);
        if (load_replay != 0) {
            spGetReplay(i);
        }
    }
}

void spInitReplay_1(signed int pid) {
    // Size: 0x2DBFC, DWARF: 0xCD375
    VspReplay* rep; // r16

    rep = vspReplay[pid];
    rep->spenv_course = vspenvGame->course;
    rep->spenv_character = vspenvGame->character[pid];
    rep->spenv_gamemode = vspenvGame->mode;
    rep->spenv_keyconfig = vspenvOption->key_config[pid];
    rep->spenv_cheats = vspenvOption->cheats;
    rep->pid = pid;
    rep->rand_num = rand();
    rep->game_time = 0;
    rep->num_frame = 0;
    rep->endrun_frame = 0;
}

void spInitMatrix(VspSystemMatrix* mtx) {
    spInitScreenInfo(&mtx->scr_info);
    spInitFog(&mtx->fog);
    sceVu0UnitMatrix(mtx->world_screen);
    sceVu0UnitMatrix(mtx->world_view);
    sceVu0UnitMatrix(mtx->view_screen);
    sceVu0UnitMatrix(mtx->light_color);
    sceVu0UnitMatrix(mtx->normal_light);
    sceVu0UnitMatrix(mtx->view_clip);
    mtx->normal_light[0][0] = 1.0f;
    mtx->normal_light[0][1] = 0.0f;
    mtx->normal_light[0][2] = 0.0f;
    mtx->normal_light[0][3] = 1.0f;
    mtx->normal_light[1][0] = 0.0f;
    mtx->normal_light[1][1] = 1.0f;
    mtx->normal_light[1][2] = 0.0f;
    mtx->normal_light[1][3] = 1.0f;
    mtx->normal_light[2][0] = 0.0f;
    mtx->normal_light[2][1] = 0.0f;
    mtx->normal_light[2][2] = 1.0f;
    mtx->normal_light[2][3] = 1.0f;
    mtx->light_color[0][0] = 0.1f;
    mtx->light_color[0][1] = 0.1f;
    mtx->light_color[0][2] = 0.1f;
    mtx->light_color[0][3] = 1.0f;
    mtx->light_color[1][0] = 0.1f;
    mtx->light_color[1][1] = 0.1f;
    mtx->light_color[1][2] = 0.1f;
    mtx->light_color[1][3] = 1.0f;
    mtx->light_color[2][0] = 0.1f;
    mtx->light_color[2][1] = 0.1f;
    mtx->light_color[2][2] = 0.1f;
    mtx->light_color[2][3] = 1.0f;
    mtx->light_color[3][0] = 0.3f;
    mtx->light_color[3][1] = 0.3f;
    mtx->light_color[3][2] = 0.3f;
    mtx->light_color[3][3] = 1.0f;
    tmgraphSetMatrix(mtx->view_screen, mtx->matrix.local_clip, mtx->matrix.clip_screen, mtx);
    mtx->cam_rot[0] = 0.0f;
    mtx->cam_rot[1] = 0.0f;
    mtx->cam_rot[2] = 0.0f;
    mtx->cam_rot[3] = 1.0f;
    mtx->cam_trans[0] = 0.0f;
    mtx->cam_trans[1] = 0.0f;
    mtx->cam_trans[2] = 0.0f;
    mtx->cam_trans[3] = 1.0f;
    mtx->view_angle = 0.785398f;
}

void spInitScreenInfo(ScreenInfo* scr) {
    float clip_vol_x; // 0x8(r29)
    float clip_vol_y; // 0xC(r29)

    clip_vol_x = 1024.0f;
    clip_vol_y = 1024.0f;
    scr->aspect_x = (vsppScrWidth / 640.0f);
    scr->aspect_y = ((0.94f * vsppScrHeight) / 448.0f);
    scr->center_x = 2048.0f;
    scr->center_y = 2048.0f;
    scr->clip_vol_x = clip_vol_x;
    scr->clip_vol_y = clip_vol_y;
    scr->min_z = 1.0f;
    scr->max_z = 1.677e7f;
    scr->near_z = 1.0f;
    scr->far_z = 65535.0f;
    scr->screen_z = 400.0f;
}

void spInitFog(Fog* fog) {
    fog->min = 255.0f;
    fog->max = 255.0f;
    fog->far = 5000.0f;
    fog->near = 800.0f;
    fog->col[0] = 0;
    fog->col[1] = 0;
    fog->col[2] = 0;
    fog->col[3] = 0;
}

void spInitDisp(VspDispEnv* disp, VspDispEnvChar* dc, HorseBestCombo* res) {
    signed int i; // r16

    nmdispInitEnv(disp);
    if (vspPlayIntro != 0) {
        disp->mode = 1;
    } else {
        disp->mode = 2;
    }
    for (i = 0; i < 2; i++) {
        nmdispInitEnvChar(dc[i]);
        nmdispInitResult(res[i]);
    }
}

void* memcpy(void* dest, void* src, int size);

// spfree.c
void spGetReplay(signed int pid) {
    signed int size; // r16
    
    vspReplay[pid]->pid             = vspenvReplay[pid]->pid;
    vspReplay[pid]->rand_num        = rand();
    vspReplay[pid]->num_frame       = vspenvReplay[pid]->num_frame;
    vspReplay[pid]->endrun_frame    = vspenvReplay[pid]->endrun_frame;
    vspReplay[pid]->game_time       = vspenvReplay[pid]->game_time;
    vspReplay[pid]->spenv_keyconfig = vspenvReplay[pid]->key;
    vspReplay[pid]->spenv_cheats    = vspenvReplay[pid]->cheats;
    size = 0x2DB40;
    memcpy(vspReplay[pid]->pad_data, vspenvReplay[pid]->pad_data, size);
}

void* memcpy(void* dest, void* src, int size);

// spfree.c
void spSetReplay(signed int pid) {
    signed int size; // r16
    vspenvReplay[pid]->pid = vspReplay[pid]->pid;
    vspenvReplay[pid]->num_frame = vspReplay[pid]->num_frame;
    vspenvReplay[pid]->endrun_frame = vspReplay[pid]->endrun_frame;
    vspenvReplay[pid]->game_time = vspReplay[pid]->game_time;
    size = 0x2DB40;
    memcpy(vspenvReplay[pid]->pad_data, vspReplay[pid]->pad_data, size);
}

signed int tmevReset(// Size: 0x8C, DWARF: 0xCFCA6
VspEvent* event);
signed int nmdispGetMode(void);
void nmdispEndReplay(void);
signed int tmevFinishPlayerEvent(// Size: 0x8C, DWARF: 0xD7795
VspEvent* event);

static s32 spUpdateMode(// Size: 0x5C, DWARF: 0xC2390
VspModeData* md /* 0xC0(r29) */) {

    signed int i; // r16 // s0
    signed int num_player; // r17 // s1
    // Size: 0x2580, DWARF: 0xC2EBE
    Act* act; // r18 // s2
    signed int horse_pid; // r19 // s3
    signed int state; // r20 // s4
    unsigned int game_time; // r21 // s5
    signed int num_rider; // r22 // s6
    signed int num_pass_finish_line; // r23 // s7
    // Size: 0x2C00, DWARF: 0xCC651
    Ctrl* rc; // r30
    signed int pause; // 0xAC(r29)
    signed int notime; // 0xB0(r29)
    signed int update_count; // 0xB4(r29)

    
    // md->flow_mode = md;
    num_rider = vspenvGame->mode.num_player; // s6
    num_player = vspenvGame->mode.num_player; // s1
    horse_pid = md->horse_pid;
    pause = md->pause;
    game_time = 0; // s5
    // if (vspenvGame->mode.game_mode == 2) {
    //     spB8 = 1;
    // } else {
    //     spB8 = 0;
    // }
    // notime = spB8;
    notime = vspenvGame->mode.game_mode == 2 ? 1 : 0;
    if (pause == 0) {
        num_pass_finish_line = 0;
        update_count = 1;
        if (md->flow_mode == 3) {
            spUpdateReplay(md, vspEndRun);
        }
        if (horse_pid >= 0) {
            if ((vspRider[horse_pid]->ctrl.act.pass_finish_line) && (vspRider[horse_pid]->ctrl.act.cnt_quit >= 0)) {
                num_pass_finish_line += 1;
            }
            if (num_pass_finish_line == 1) {
                update_count = 0;
            }
        } else {
            for (i = 0; i < num_player; i++) {
                if ((vspRider[i]->ctrl.act.pass_finish_line) && (vspRider[i]->ctrl.act.cnt_quit >= 0)) {
                    num_pass_finish_line += 1;
                }
            }
            if (num_pass_finish_line == num_player) {
                update_count = 0;
            }
        }
        if (((md->flow_mode == 3) || (md->flow_mode == 6)) && update_count) {
            md->game_count++;
            // temp_v1 = md->game_count;
            md->game_time = (u32) ((md->game_count * 0x3E8) / 60);
            // temp_v0 = rand();
            // var_v1 = temp_v0 & 0xF;
            // if ((temp_v0 < 0) && (var_v1)) {
            //     var_v1 -= 0x10;
            // }
            md->game_time += rand() % 16;
            if ((notime == 0) && ((u32) md->game_time_limit < (u32) md->game_time)) {
                md->game_time = (u32) md->game_time_limit;
            }
        }
        md->flow_count++;
    }
    // temp_v1_2 = md->flow_mode;
    // if ((temp_v1_2 != 7) && (temp_v1_2 != 6) && (temp_v1_2 != 4) && (temp_v1_2 != 3)) {

    // } else {
    //     md->realtime_count++;
    // }
    switch (md->flow_mode) {
        case efmPlay:
        case efmEnd:
        case efmReplay:
        case efmRepEnd:
            md->realtime_count++;
            break;
    }
    if (horse_pid >= 0) {
        game_time = vspReplay[horse_pid]->game_time;
        if (vspRider[horse_pid]->ctrl.act.pass_finish_line == 0) {
            vspVsData.result[horse_pid].time = game_time;
        }
    } else {
        for (i = 0; i < num_player; i++) {
            if (game_time < (u32) vspReplay[i]->game_time) {
                game_time = vspReplay[i]->game_time;
            }
            if (vspRider[i]->ctrl.act.pass_finish_line == 0) {
                vspVsData.result[i].time = game_time;
            }
        }
    }
    vspDispEnv.pass_time = game_time;
    if (notime) {
        vspDispEnv.time_left = -1;
    } else if (game_time < (u32) md->game_time_limit) {
        vspDispEnv.time_left = (md->game_time_limit - game_time) / 1000;
        if (((u32) (md->game_time_limit - game_time) % 1000U)) {
            vspDispEnv.time_left = vspDispEnv.time_left + 1;
        }
    } else {
        vspDispEnv.time_left = 0;
    }
    if ((vspenvGame->mode.game_mode == 1) && (pause == 0)) {
        // temp_a1 = vspenvGame;
        // temp_v0_2 = temp_a1->unk84;
        switch (vspenvGame->mode.match_rule) {
        case 0:
            spFlowTrick(md);
            break;
        case 1:
            spFlowBoost(md);
            break;
        case 2:
            spFlowPush(md);
            break;
        case 3:
            spFlowHorse(md);
            break;
        }
    }
    spCheckPassFinishLine2(md);
    // temp_v1_3 = md->flow_mode;
    switch (md->flow_mode) {                            /* switch 1 */
    case efmIntro:
        if (nmdispCheckIntr()) {
            if (horse_pid >= 0) {
                md->next_flow_mode = 1;
            } else {
                md->next_flow_mode = 2;
            }
            nmvcStopEvent();
            nmsndFrame(0);
            sceGsSyncV(0);
            spRiderReset();
            vspEvent->game.mode = 1;
            tmevReset(vspEvent);
            gmsysResetBlurPow();
            for (i = 0; i < num_rider; i++) {
                ktactSetCaminfo(&vspRider[i]->ctrl.cam, &vspRider[i]->ctrl);
                knCameraSetScrZ(i);
            }
            if (horse_pid >= 0) {
                akevResetEffect2(horse_pid);
            } else {
                for (i = 0; i < num_player; i++) {
                    akevResetEffect2(i);
                }
            }
            nmsndStartGame();
        }
        break;
    case efmHorseReady:
        if ((0xFF - (md->flow_count * 2)) < 0) {

        }
        spSetFade(0, 0xFF);
        if (md->flow_count == 1) {
            nmdispInputParam(md);
            vspDispEnv.mode = 2;
        }
        if (nmdispCheckHorse()) {
            md->next_flow_mode = 2;
            vspVsData.horse_num_round = nmdispGetHorseNum();
        }
        break;
    case efmReady:
        if (horse_pid < 0) {
            state = 0xFF - (md->flow_count * 2);
            if (state < 0) {
                state = 0;
            }
            spSetFade(state, 0xFF);
            if (md->flow_count == 1) {
                nmdispInputParam();
                vspDispEnv.mode = 2;
            }
        }
        if (horse_pid >= 0) {
            rc = &vspRider[horse_pid]->ctrl;
        } else {
            rc = &vspRider[0]->ctrl;
        }
        if (rc->mot.freemotion == 0) {
            md->next_flow_mode = 3;
            if (horse_pid < 0) {
                for (i = 0; i < num_player; i++) {
                    nmactPlaySlide(i);
                }
            } else {
                nmactPlaySlide(horse_pid);
            }
        }
        break;
    case efmPlay:
        if ((vspDispEnv.time_left == 0) && (vspEndRun == 0)) {
            for (i = 0; i < num_player; i++) {
                act = &vspRider[i]->ctrl.act;
                if ((act->cnt_quit < 0) && (act->reserve_quit == 0)) {
                    act->reserve_quit = 1;
                    if (act->pass_finish_line) {
                        act->allow_tlink = 0;
                    } else {
                        act->allow_tlink = 1;
                    }
                }
            }
        }
        if (md->next_flow_mode == 4) {
            for (i = 0; i < num_rider; i++) {
                vspEvent->game.player = i;
                tmevFinishPlayerEvent(vspEvent);
            }
        } else if (spCheckFinish(md, 0)) {
            md->next_flow_mode = 4;
        }
        vgmsysPadAllowPause = 0;
        if (vspEventCamera == 0) {
            if (horse_pid < 0) {
                for (i = 0; i < num_player; i++) {
                    vgmsysPadAllowPause = (s32) (vgmsysPadAllowPause | (1 << i));
                }
            } else {
                vgmsysPadAllowPause = (s32) (vgmsysPadAllowPause | (1 << horse_pid));
            }
        }
        break;
    case efmEnd:
        if (md->to_end_sliding) {
            md->end_sliding = 1;
        }
        if (md->end_sliding) {
            md->to_end_sliding = 0;
        }
        if (md->fade) {
            state = vspFadePercent + 4;
            if (state >= 0x100) {
                state = 0xFF;
            }
            spSetFade(state, 0xFF);
            if (state == 0xFF) {
                vspDispEnv.mode = 3;
                if (horse_pid < 0) {
                    for (i = 0; i < num_player; i++) {
                        nmactStopSlide(i);
                    }
                } else {
                    nmactStopSlide(horse_pid);
                    nmvcStopEvent();
                }
                nmactEndGame();
                // act_2 = md->modnum;
                switch (md->modnum) {
                case 19:
                case 17:
                    spSetReplay(0);
                    md->next_flow_mode = 5;
                    break;
                case 18:
                    if (horse_pid < 0) {
                        for (i = 0; i < num_player; i++) {
                            spSetReplay(i);
                        }
                        md->next_flow_mode = 5;
                    } else if (vspEndRun) {
                        nmdispEndHorse();
                        md->next_flow_mode = 5;
                    } else if (vspVsData.horse_end_one_round) {
                        nmdispEndHorse();
                        if (vspVsData.result[horse_pid].cnt_horse < vspVsData.horse_num_round) {
                            md->restart = 1;
                            tmevResetHorsePosition(0);
                        } else {
                            md->next_flow_mode = 5;
                        }
                    } else {
                        spSetReplay(horse_pid);
                        md->restart = 1;
                    }
                    break;
                }
            }
        }
        vgmsysPadAllowPause = 0;
        break;
    case efmRepReady:
        if (horse_pid >= 0) {
            rc = &vspRider[horse_pid]->ctrl;
        } else {
            rc = &vspRider[0]->ctrl;
        }
        if (rc->mot.freemotion == 0) {
            md->next_flow_mode = 6;
            if (horse_pid < 0) {
                for (i = 0; i < num_player; i++) {
                    nmactPlaySlide(i);
                }
            } else {
                nmactPlaySlide(horse_pid);
            }
        }
        // break; // intentional fallthrough?
    case efmReplay:
        if (md->flow_mode == 6) {
            if (md->next_flow_mode == 7) {
                for (i = 0; i < num_rider; i++) {
                    vspEvent->game.player = i;
                    tmevFinishPlayerEvent(vspEvent);
                }
            } else if (spCheckFinish(md, 1)) {
                md->next_flow_mode = 7;
            }
        }

    case efmRepEnd:
        if (vspDispEnv.mode == 4 || vspDispEnv.mode == 5) {
            // var_a0 = md->flow_mode;
            if (md->flow_mode == 7) {
                // var_a0 = (u32) md;
                if (md->fade) {
                    nmdispEndReplay();
                }
            }
        }
        if (nmdispGetMode() == 6) {
            md->next_flow_mode = 8;
            ayResultClear();
            vspChangeScreen = 1;
            nmsndEndGame();
            nmactEndGame();
            if (horse_pid < 0) {
                for (i = 0; i < num_player; i++) {
                    nmactStopSlide(i);
                }
            } else {
                nmactStopSlide(horse_pid);
            }
            gmsysResetBlurPow();
            if (md->modnum == 0x14 || md->modnum == 0x15) {
                md->next_modnum = 1;
            }
        }
        break;
    case efmResult:
        sceGifPkReset(vgmsysGifPkt);
        state = ayResultFrame(vgmsysGifPkt);
        if (vspFadePercent > 0) {
            spFade(vgmsysGifPkt, vspFadePercent, vspFadeCol);
        }
        ulgifTermPacket(vgmsysGifPkt);
        ulgifDmaSend(vgmsysGifPkt);
        ulgifDmaWait();
        switch (state) {
        case 1:
            gmsysSetScreenMode_on_play();
            if (md->num_window == 1) {
                gmsysSetScrFlipMode(0);
                gmsysSetScrDivType(0);
                if (horse_pid >= 0) {
                    vspInitHorse = 1;
                }
            } else {
                gmsysSetScrFlipMode(1);
                // if (vspVsData.div_side) {
                //     spBC = 1;
                // } else {
                //     spBC = 2;
                // }
                gmsysSetScrDivType(vspVsData.div_side ? 1 : 2);
            }
            md->restart = 1;
            vspPlayIntro = 1;
            if ((horse_pid < 0) && (vspenvGame->mode.game_mode == 1) && (vspenvGame->mode.match_rule == 3)) {
                vspInitHorse = 1;
            }
            break;
        case 2:
            switch (md->modnum) {                    /* switch 5; irregular */
            case 17:                                /* switch 5 */
                md->next_modnum = 2;
                break;
            case 18:                                /* switch 5 */
                md->next_modnum = 3;
                break;
            case 19:                                /* switch 5 */
                md->next_modnum = 4;
                break;
            default:                                /* switch 5 */
                md->next_modnum = 1;
                break;
            }
            break;
        case 5:
        case 6:
            md->next_modnum = 2;
            break;
        case 3:
            md->restart = 2;
            vspDispEnv.mode = 4;
            nmdispInitReplay();
            vspEndRun = (s32) vspEndRunReplay;
            break;
        case 4:
            md->next_modnum = 1;
            break;
        }
        break;
    }
    if (md->next_flow_mode != md->flow_mode) {
        if (md->next_flow_mode == 5) {
            md->restart = 2;
        }
        md->flow_mode = (u32) md->next_flow_mode;
        md->flow_count = 0;
        md->fade = 0;
    }
    md->modnum = (s32) md->next_modnum;
    md->bgm_no = (s32) md->next_bgm_no;
    if (horse_pid >= 0) {
        if ((*(vspWndFadePercent + (horse_pid * 4)) > 0) || (vspRider[horse_pid]->ctrl.act.cnt_warp > 0) || (vspRider[horse_pid]->ctrl.act.water_manual > 0)) {
            vgmsysPadAllowPause = (s32) (vgmsysPadAllowPause & ~(1 << horse_pid));
        }
    } else {
        i = 0;
loop_230:
        if (i >= num_player) {

        } else if ((*(vspWndFadePercent + (i * 4)) <= 0) && (vspRider[i]->ctrl.act.cnt_warp <= 0) && (vspRider[i]->ctrl.act.water_manual <= 0)) {
            i += 1;
            goto loop_230;
        }
        if (i < num_player) {
            vgmsysPadAllowPause = 0;
        }
    }
    state = 0;
    for (i = 0; i < num_player; i++) {
        act = &vspRider[i]->ctrl.act;
        act->trg_quit = 0;
        if (act->reserve_quit == 0) {
            if (act->cnt_quit >= 0) {
                goto block_238;
            }
        } else {
block_238:
            state += 1;
        }
    }
    if (state == num_player) {
        vgmsysPadAllowPause = 0;
    }
    return md->modnum;
}

// s32 spUpdateMode(void* arg0) {
//     void* spC0;
//     s32 spBC;
//     s32 spB8;
//     s32 spB4;
//     s32 spB0;
//     s32 spAC;
//     s32 temp_a1;
//     s32 temp_s1;
//     s32 temp_s2_2;
//     s32 temp_s3;
//     s32 state_2;
//     s32 temp_s6;
//     s32 temp_v0;
//     s32 temp_v0_2;
//     s32 temp_v1;
//     s32 var_s0;
//     s32 var_s0_10;
//     s32 var_s0_11;
//     s32 var_s0_12;
//     s32 var_s0_13;
//     s32 var_s0_14;
//     s32 var_s0_15;
//     s32 var_s0_2;
//     s32 var_s0_3;
//     s32 var_s0_4;
//     s32 var_s0_5;
//     s32 var_s0_6;
//     s32 var_s0_7;
//     s32 var_s0_8;
//     s32 var_s0_9;
//     s32 state;
//     s32 state;
//     s32 state;
//     s32 num_pass_finish_line;
//     s32 var_v1;
//     u32 state;
//     u32 temp_v1_2;
//     u32 temp_v1_3;
//     u32 var_a0;
//     u32 var_s5;
//     void* temp_s2;
//     void* temp_s2_3;
//     void* var_fp;
//     void* var_fp_2;

//     spC0 = arg0;
//     temp_s6 = vspenvGame->unk7C;
//     temp_s1 = vspenvGame->unk7C;
//     temp_s3 = spC0->unk2C;
//     spAC = spC0->unk34;
//     var_s5 = 0;
//     if (vspenvGame->unk80 == 2) {
//         spB8 = 1;
//     } else {
//         spB8 = 0;
//     }
//     spB0 = spB8;
//     if (spAC == 0) {
//         num_pass_finish_line = 0;
//         spB4 = 1;
//         if (spC0->unk0 == 3) {
//             spUpdateReplay(spC0, vspEndRun);
//         }
//         if (temp_s3 >= 0) {
//             if (((&vspRider)[temp_s3]->unk4BE8 != 0) && ((&vspRider)[temp_s3]->unk4BE0 >= 0)) {
//                 num_pass_finish_line = 1;
//             }
//             if (num_pass_finish_line == 1) {
//                 spB4 = 0;
//             }
//         } else {
//             var_s0 = 0;
// loop_17:
//             if (var_s0 < temp_s1) {
//                 if (((&vspRider)[var_s0]->unk4BE8 != 0) && ((&vspRider)[var_s0]->unk4BE0 >= 0)) {
//                     num_pass_finish_line += 1;
//                 }
//                 var_s0 += 1;
//                 goto loop_17;
//             }
//             if (num_pass_finish_line == temp_s1) {
//                 spB4 = 0;
//             }
//         }
//         if (((spC0->unk0 == 3) || (spC0->unk0 == 6)) && (spB4 != 0)) {
//             spC0->unkC = (s32) (spC0->unkC + 1);
//             temp_v1 = spC0->unkC;
//             spC0->unk8 = (u32) ((temp_v1 * 0x3E8) / 60);
//             temp_v0 = rand(spC0, temp_v1 * 0x3E8);
//             var_v1 = temp_v0 & 0xF;
//             if ((temp_v0 < 0) && (var_v1 != 0)) {
//                 var_v1 -= 0x10;
//             }
//             spC0->unk8 = (u32) (spC0->unk8 + var_v1);
//             if ((spB0 == 0) && ((u32) spC0->unk4 < (u32) spC0->unk8)) {
//                 spC0->unk8 = (u32) spC0->unk4;
//             }
//         }
//         spC0->unk14 = (s32) (spC0->unk14 + 1);
//     }
//     temp_v1_2 = spC0->unk0;
//     if ((temp_v1_2 != 7) && (temp_v1_2 != 6) && (temp_v1_2 != 4) && (temp_v1_2 != 3)) {

//     } else {
//         spC0->unk10 = (s32) (spC0->unk10 + 1);
//     }
//     if (temp_s3 >= 0) {
//         var_s5 = (*(&vspReplay + (temp_s3 * 4)))->unkB8;
//         if ((&vspRider)[temp_s3]->unk4BE8 == 0) {
//             (&vspVsData + (temp_s3 * 0x838))->unk20 = var_s5;
//         }
//     } else {
//         var_s0_2 = 0;
// loop_45:
//         if (var_s0_2 < temp_s1) {
//             if (var_s5 < (u32) (*(&vspReplay + (var_s0_2 * 4)))->unkB8) {
//                 var_s5 = (*(&vspReplay + (var_s0_2 * 4)))->unkB8;
//             }
//             if ((&vspRider)[var_s0_2]->unk4BE8 == 0) {
//                 (&vspVsData + (var_s0_2 * 0x838))->unk20 = var_s5;
//             }
//             var_s0_2 += 1;
//             goto loop_45;
//         }
//     }
//     *(&vspDispEnv + 8) = var_s5;
//     if (spB0 != 0) {
//         *(&vspDispEnv + 4) = -1U;
//     } else if (var_s5 < (u32) spC0->unk4) {
//         *(&vspDispEnv + 4) = (spC0->unk4 - var_s5) / 1000;
//         if (((u32) (spC0->unk4 - var_s5) % 1000U) != 0) {
//             *(&vspDispEnv + 4) = *(&vspDispEnv + 4) + 1;
//         }
//     } else {
//         *(&vspDispEnv + 4) = 0;
//     }
//     if ((vspenvGame->unk80 == 1) && (spAC == 0)) {
//         temp_v0_2 = vspenvGame->unk84;
//         switch (temp_v0_2) {                        /* switch 3; irregular */
//         case 0:                                     /* switch 3 */
//             spFlowTrick(spC0, vspenvGame);
//             break;
//         case 1:                                     /* switch 3 */
//             spFlowBoost(spC0, vspenvGame);
//             break;
//         case 2:                                     /* switch 3 */
//             spFlowPush(spC0, vspenvGame);
//             break;
//         case 3:                                     /* switch 3 */
//             spFlowHorse(spC0, vspenvGame);
//             break;
//         }
//     }
//     spCheckPassFinishLine2(spC0);
//     temp_v1_3 = spC0->unk0;
//     switch (temp_v1_3) {                            /* switch 1 */
//     case 0:                                         /* switch 1 */
//         if (nmdispCheckIntr() != 0) {
//             if (temp_s3 >= 0) {
//                 spC0->unk3C = 1U;
//             } else {
//                 spC0->unk3C = 2U;
//             }
//             nmvcStopEvent();
//             nmsndFrame(0);
//             sceGsSyncV(0);
//             spRiderReset();
//             vspEvent->unk84 = 1;
//             tmevReset(vspEvent);
//             gmsysResetBlurPow();
//             var_s0_3 = 0;
// loop_72:
//             if (var_s0_3 < temp_s6) {
//                 ktactSetCaminfo((&vspRider)[var_s0_3] + 0x5470, (&vspRider)[var_s0_3] + 0x2A30, &vspRider);
//                 knCameraSetScrZ(var_s0_3);
//                 var_s0_3 += 1;
//                 goto loop_72;
//             }
//             if (temp_s3 >= 0) {
//                 akevResetEffect2(temp_s3);
//             } else {
//                 var_s0_4 = 0;
// loop_77:
//                 if (var_s0_4 < temp_s1) {
//                     akevResetEffect2(var_s0_4);
//                     var_s0_4 += 1;
//                     goto loop_77;
//                 }
//             }
//             nmsndStartGame();
//         }
//         break;
//     case 1:                                         /* switch 1 */
//         if ((0xFF - (spC0->unk14 * 2)) < 0) {

//         }
//         spSetFade(0, 0xFF);
//         if (spC0->unk14 == 1) {
//             nmdispInputParam(spC0);
//             vspDispEnv = 2;
//         }
//         if (nmdispCheckHorse() != 0) {
//             spC0->unk3C = 2U;
//             *(&vspVsData + 0x14) = nmdispGetHorseNum();
//         }
//         break;
//     case 2:                                         /* switch 1 */
//         if (temp_s3 < 0) {
//             state = 0xFF - (spC0->unk14 * 2);
//             if (state < 0) {
//                 state = 0;
//             }
//             spSetFade(state, 0xFF);
//             if (spC0->unk14 == 1) {
//                 nmdispInputParam();
//                 vspDispEnv = 2;
//             }
//         }
//         if (temp_s3 >= 0) {
//             var_fp = (&vspRider)[temp_s3] + 0x2A30;
//         } else {
//             var_fp = &vspRider[0]->ctrl;
//         }
//         if (var_fp->unk2A14 == 0) {
//             spC0->unk3C = 3U;
//             if (temp_s3 < 0) {
//                 var_s0_5 = 0;
// loop_97:
//                 if (var_s0_5 < temp_s1) {
//                     nmactPlaySlide(var_s0_5);
//                     var_s0_5 += 1;
//                     goto loop_97;
//                 }
//             } else {
//                 nmactPlaySlide(temp_s3);
//             }
//         }
//         break;
//     case 3:                                         /* switch 1 */
//         if ((*(&vspDispEnv + 4) == 0) && (vspEndRun == 0)) {
//             var_s0_6 = 0;
// loop_109:
//             if (var_s0_6 < temp_s1) {
//                 temp_s2 = (&vspRider)[var_s0_6] + 0x2D60;
//                 if ((temp_s2->unk1E80 < 0) && (temp_s2->unk1E70 == 0)) {
//                     temp_s2->unk1E70 = 1;
//                     if (temp_s2->unk1E88 != 0) {
//                         temp_s2->unk1E74 = 0;
//                     } else {
//                         temp_s2->unk1E74 = 1;
//                     }
//                 }
//                 var_s0_6 += 1;
//                 goto loop_109;
//             }
//         }
//         if (spC0->unk3C == 4) {
//             var_s0_7 = 0;
// loop_114:
//             temp_a1 = var_s0_7 < temp_s6;
//             if (temp_a1 != 0) {
//                 vspEvent->unk78 = var_s0_7;
//                 tmevFinishPlayerEvent(vspEvent, temp_a1);
//                 var_s0_7 += 1;
//                 goto loop_114;
//             }
//         } else if (spCheckFinish(spC0, 0) != 0) {
//             spC0->unk3C = 4U;
//         }
//         vgmsysPadAllowPause = 0;
//         if (vspEventCamera == 0) {
//             if (temp_s3 < 0) {
//                 var_s0_8 = 0;
// loop_122:
//                 if (var_s0_8 < temp_s1) {
//                     vgmsysPadAllowPause |= 1 << var_s0_8;
//                     var_s0_8 += 1;
//                     goto loop_122;
//                 }
//             } else {
//                 vgmsysPadAllowPause |= 1 << temp_s3;
//             }
//         }
//         break;
//     case 4:                                         /* switch 1 */
//         if (spC0->unk50 != 0) {
//             spC0->unk30 = 1;
//         }
//         if (spC0->unk30 != 0) {
//             spC0->unk50 = 0;
//         }
//         if (spC0->unk4C != 0) {
//             state = vspFadePercent + 4;
//             if (state >= 0x100) {
//                 state = 0xFF;
//             }
//             spSetFade(state, 0xFF);
//             if (state == 0xFF) {
//                 vspDispEnv = 3;
//                 if (temp_s3 < 0) {
//                     var_s0_9 = 0;
// loop_136:
//                     if (var_s0_9 < temp_s1) {
//                         nmactStopSlide(var_s0_9);
//                         var_s0_9 += 1;
//                         goto loop_136;
//                     }
//                 } else {
//                     nmactStopSlide(temp_s3);
//                     nmvcStopEvent();
//                 }
//                 nmactEndGame();
//                 temp_s2_2 = spC0->unk1C;
//                 switch (temp_s2_2) {
//                 case 19:
//                 case 17:
//                     spSetReplay(0);
//                     spC0->unk3C = 5U;
//                     break;
//                 case 18:
//                     if (temp_s3 < 0) {
//                         var_s0_10 = 0;
// loop_147:
//                         if (var_s0_10 < temp_s1) {
//                             spSetReplay(var_s0_10);
//                             var_s0_10 += 1;
//                             goto loop_147;
//                         }
//                         spC0->unk3C = 5U;
//                     } else if (vspEndRun != 0) {
//                         nmdispEndHorse();
//                         spC0->unk3C = 5U;
//                     } else if (*(&vspVsData + 0x18) != 0) {
//                         nmdispEndHorse();
//                         if ((&vspVsData + (temp_s3 * 0x838))->unk2C < *(&vspVsData + 0x14)) {
//                             spC0->unk40 = 1;
//                             tmevResetHorsePosition(0);
//                         } else {
//                             spC0->unk3C = 5U;
//                         }
//                     } else {
//                         spSetReplay(temp_s3);
//                         spC0->unk40 = 1;
//                     }
//                     break;
//                 }
//             }
//         }
//         vgmsysPadAllowPause = 0;
//         break;
//     case 5:                                         /* switch 1 */
//         if (temp_s3 >= 0) {
//             var_fp_2 = (&vspRider)[temp_s3] + 0x2A30;
//         } else {
//             var_fp_2 = &vspRider[0]->ctrl;
//         }
//         if (var_fp_2->unk2A14 == 0) {
//             spC0->unk3C = 6U;
//             if (temp_s3 < 0) {
//                 var_s0_11 = 0;
// loop_164:
//                 if (var_s0_11 < temp_s1) {
//                     nmactPlaySlide(var_s0_11);
//                     var_s0_11 += 1;
//                     goto loop_164;
//                 }
//             } else {
//                 nmactPlaySlide(temp_s3);
//             }
//         }
// 
//     case 6:                                         /* switch 1 */
//         if (spC0->unk0 == 6) {
//             if (spC0->unk3C == 7) {
//                 var_s0_12 = 0;
// loop_171:
//                 if (var_s0_12 < temp_s6) {
//                     vspEvent->unk78 = var_s0_12;
//                     tmevFinishPlayerEvent(vspEvent);
//                     var_s0_12 += 1;
//                     goto loop_171;
//                 }
//             } else if (spCheckFinish(spC0, 1) != 0) {
//                 spC0->unk3C = 7U;
//             }
//         }
// 
//     case 7:                                         /* switch 1 */
//         if ((vspDispEnv == 4) || (var_a0 = 5, (vspDispEnv == 5))) {
//             var_a0 = spC0->unk0;
//             if (var_a0 == 7) {
//                 var_a0 = (u32) spC0;
//                 if (var_a0->unk4C != 0) {
//                     var_a0 = nmdispEndReplay((void* ) var_a0);
//                 }
//             }
//         }
//         if (nmdispGetMode((void* ) var_a0) == 6) {
//             spC0->unk3C = 8U;
//             ayResultClear();
//             vspChangeScreen = 1;
//             nmsndEndGame();
//             nmactEndGame();
//             if (temp_s3 < 0) {
//                 var_s0_13 = 0;
// loop_184:
//                 if (var_s0_13 < temp_s1) {
//                     nmactStopSlide(var_s0_13);
//                     var_s0_13 += 1;
//                     goto loop_184;
//                 }
//             } else {
//                 nmactStopSlide(temp_s3);
//             }
//             gmsysResetBlurPow();
//             if ((spC0->unk1C == 0x14) || (spC0->unk1C == 0x15)) {
//                 spC0->unk44 = 1;
//             }
//         }
//         break;
//     case 8:                                         /* switch 1 */
//         sceGifPkReset(vgmsysGifPkt);
//         state = ayResultFrame(vgmsysGifPkt);
//         if (vspFadePercent > 0) {
//             spFade(vgmsysGifPkt, vspFadePercent, vspFadeCol);
//         }
//         ulgifTermPacket(vgmsysGifPkt);
//         ulgifDmaSend(vgmsysGifPkt);
//         ulgifDmaWait();
//         switch (state) {
//         case 1:
//             gmsysSetScreenMode_on_play();
//             if (spC0->unk28 == 1) {
//                 gmsysSetScrFlipMode(0);
//                 gmsysSetScrDivType(0);
//                 if (temp_s3 >= 0) {
//                     vspInitHorse = 1;
//                 }
//             } else {
//                 gmsysSetScrFlipMode(1);
//                 if (vspVsData != 0) {
//                     spBC = 1;
//                 } else {
//                     spBC = 2;
//                 }
//                 gmsysSetScrDivType(spBC);
//             }
//             spC0->unk40 = 1;
//             vspPlayIntro = 1;
//             if ((temp_s3 < 0) && (vspenvGame->unk80 == 1) && (vspenvGame->unk84 == 3)) {
//                 vspInitHorse = 1;
//             }
//             break;
//         case 2:
//             state_2 = spC0->unk1C;
//             switch (state_2) {                    /* switch 5; irregular */
//             case 17:                                /* switch 5 */
//                 spC0->unk44 = 2;
//                 break;
//             case 18:                                /* switch 5 */
//                 spC0->unk44 = 3;
//                 break;
//             case 19:                                /* switch 5 */
//                 spC0->unk44 = 4;
//                 break;
//             default:                                /* switch 5 */
//                 spC0->unk44 = 1;
//                 break;
//             }
//             break;
//         case 5:
//         case 6:
//             spC0->unk44 = 2;
//             break;
//         case 3:
//             spC0->unk40 = 2;
//             vspDispEnv = 4;
//             nmdispInitReplay();
//             vspEndRun = vspEndRunReplay;
//             break;
//         case 4:
//             spC0->unk44 = 1;
//             break;
//         }
//         break;
//     }
//     if (spC0->unk3C != spC0->unk0) {
//         if (spC0->unk3C == 5) {
//             spC0->unk40 = 2;
//         }
//         spC0->unk0 = (u32) spC0->unk3C;
//         spC0->unk14 = 0;
//         spC0->unk4C = 0;
//     }
//     spC0->unk1C = (s32) spC0->unk44;
//     spC0->unk20 = (s32) spC0->unk48;
//     if (temp_s3 >= 0) {
//         if ((*(&vspWndFadePercent + (temp_s3 * 4)) > 0) || ((&vspRider)[temp_s3]->unk4BB4 > 0) || ((&vspRider)[temp_s3]->unk4BB8 > 0)) {
//             vgmsysPadAllowPause &= ~(1 << temp_s3);
//         }
//     } else {
//         var_s0_14 = 0;
// loop_230:
//         if (var_s0_14 >= temp_s1) {

//         } else if ((*(&vspWndFadePercent + (var_s0_14 * 4)) <= 0) && ((&vspRider)[var_s0_14]->unk4BB4 <= 0) && ((&vspRider)[var_s0_14]->unk4BB8 <= 0)) {
//             var_s0_14 += 1;
//             goto loop_230;
//         }
//         if (var_s0_14 < temp_s1) {
//             vgmsysPadAllowPause = 0;
//         }
//     }
//     state = 0;
//     var_s0_15 = 0;
// loop_240:
//     if (var_s0_15 < temp_s1) {
//         temp_s2_3 = (&vspRider)[var_s0_15] + 0x2D60;
//         temp_s2_3->unk1E7C = 0;
//         if (temp_s2_3->unk1E70 == 0) {
//             if (temp_s2_3->unk1E80 >= 0) {
//                 goto block_238;
//             }
//         } else {
// block_238:
//             state += 1;
//         }
//         var_s0_15 += 1;
//         goto loop_240;
//     }
//     if (state == temp_s1) {
//         vgmsysPadAllowPause = 0;
//     }
//     return spC0->unk1C;
// }

void spUpdateReplay(VspModeData* md, signed int endrun) {
    signed int i; // r18
    unsigned int frame; // r19
    // Size: 0x2C00, DWARF: 0xCC651
    Ctrl* rc; // r17
    // Size: 0x2DBFC, DWARF: 0xCD375
    VspReplay* rep; // r16
    signed int horse_pid; // r21
    signed int num_player; // r20

    num_player = vspenvGame->mode.num_player;
    horse_pid = md->horse_pid;
    frame = md->game_count;
    if (frame < 0x5B68) {
        if (horse_pid >= 0) {
            rep = vspReplay[horse_pid];
            rc = &vspRider[horse_pid]->ctrl;
            if (endrun == 0) {
                rep->endrun_frame = frame;
            }
            if (rc->act.cnt_quit < 0) {
                rep->pad_data[frame] = rc->nowpad;
                rep->num_frame = frame + 1;
                rep->game_time = md->game_time;
            }
        } else {
            for (i = 0; i < num_player; i++) {
                rep = vspReplay[i];
                rc = &vspRider[i]->ctrl;
                if (endrun == 0) {
                    rep->endrun_frame = frame;
                }
                if (rc->act.cnt_quit < 0) {
                    rep->pad_data[frame] = rc->nowpad;
                    rep->num_frame = frame + 1;
                    if (rc->act.pass_finish_line == 0) {
                        rep->game_time = md->game_time;
                    }
                }
            }
        }
    }
}

signed int spCheckFinish(VspModeData* md, signed int replay) {
    // Size: 0x2580, DWARF: 0xC2EBE
    Act* act; // r16
    signed int j; // r17
    signed int i; // r18
    signed int state; // r19
    signed int num_player; // r20
    signed int go_end; // r21

    num_player = vspenvGame->mode.num_player;
    go_end = 0;
    if (md->num_window == 1) {
        i = md->horse_pid;
        if (i < 0) {
            i = 0;
        }
        act = &vspRider[i]->ctrl.act;
        if (act->sbcore.move != 0) {
            for (j = 0; j < act->num_hit; j++) {
                if (act->col_hit[j].no == 0x14) {
                    if (act->cnt_quit < 0) {
                        act->reserve_quit = 1;
                    }
                    act->allow_tlink = 0;
                    act->pass_finish_line = 1;
                    if (replay == 0) {
                        vspVsData.result[i].goal = 1;
                    }
                }
            }
        }
        if (act->trg_quit != 0) {
            vspEvent->game.player = i;
            tmevFinishPlayerEvent(vspEvent);
            go_end = 1;
        } else if (act->cnt_quit >= 0) {
            go_end = 1;
        }
    } else {
        if ((vspenvGame->mode.match_rule == 1) && (vspRider[0]->ctrl.act.pass_finish_line == 0) && (vspRider[1]->ctrl.act.pass_finish_line == 0)) {
            state = 0;
            for (i = 0; i < num_player; i++) {
                act = &vspRider[i]->ctrl.act;
                if (act->sbcore.move != 0) {
                    for (j = 0; j < act->num_hit; j++) {
                        if (act->col_hit[j].no == 0x14) {
                            if (act->cnt_quit < 0) {
                                act->reserve_quit = 1;
                            }
                            act->allow_tlink = 0;
                            act->pass_finish_line = 1;
                            if (replay == 0) {
                                vspVsData.result[i].goal = 1;
                            }
                            state |= 1 << i;
                        }
                    }
                }
            }
            if (state != 0) {
                for (i = 0; i < num_player; i++) {
                    act = &vspRider[i]->ctrl.act;
                    if (!(state & (1 << i))) {
                        if (act->cnt_quit < 0) {
                            act->reserve_quit = 1;
                        }
                        act->allow_tlink = 0;
                    }
                }
            }
        }
        j = 0;
        for (i = 0; i < num_player; i++) {
            act = &vspRider[i]->ctrl.act;
            if (act->trg_quit != 0) {
                vspEvent->game.player = i;
                tmevFinishPlayerEvent(vspEvent);
                j += 1;
            } else if (act->cnt_quit >= 0) {
                j += 1;
            }
        }
        if (j == num_player) {
            go_end = 1;
        }
    }
    return go_end;
}

void spCheckPassFinishLine2(VspModeData* md) {
    // Size: 0x2580, DWARF: 0xC2EBE
    Act* act; // r16
    signed int j; // r17
    signed int i; // r18
    signed int num_player; // r19

    // md = md; // 40
    num_player = vspenvGame->mode.num_player;
    if (md->num_window == 1) {
        i = md->horse_pid;
        if (i < 0) {
            i = 0;
        }
        act = &vspRider[i]->ctrl.act;
        if ((act->sbcore.move != 0) || (act->end_sliding != 0)) {
            for (j = 0; j < act->num_hit; j++) {
                if (act->col_hit[j].no == 0x14) {
                    act->pass_finish_line2 = 1;
                }
            }
        }
    } else {
        for (i = 0; i < num_player; i++) {
            act = &vspRider[i]->ctrl.act;
            if ((act->sbcore.move != 0) && (act->end_sliding == 0)) {
                for (j = 0; j < act->num_hit; j++) {
                    if (act->col_hit[j].no == 0x14) {
                        act->pass_finish_line2 = 1;
                    }
                }
            }
        }
    }
}

void spFlowTrick(VspModeData* md) {
    unsigned int pts0; // r16
    unsigned int pts1; // r17
    signed int set_result; // r18

    pts0 = vspRider[0]->ctrl.act.trick_link.total_trick_point;
    pts1 = vspRider[1]->ctrl.act.trick_link.total_trick_point;
    if (md->flow_mode == 4) {
        set_result = 0;
        if ((md->flow_count == 1) && (vspEndRun == 0)) {
            set_result = 1;
        } else if (vspEndRun != 0) {
            md->fade = 1;
        }
        if (set_result != 0) {
            if (pts0 == pts1) {
                vspDispEnvChar[0].rank = 0;
                vspDispEnvChar[1].rank = 0;
                vspDispVsScore.draw += 1;
            } else if (pts1 < pts0) {
                vspDispEnvChar[0].rank = 0;
                vspDispEnvChar[1].rank = 1;
                vspDispVsScore.win += 1;
            } else {
                vspDispEnvChar[0].rank = 1;
                vspDispEnvChar[1].rank = 0;
                vspDispVsScore.lose += 1;
            }
            nmdispInputResult();
        }
    }
    if (vspVsData.div_side != 0) {
        vspVsData.center = vsppScrWidth / 2;
    } else {
        vspVsData.center = vsppScrHeight / 2;
    }
    vspDispEnv.div = vspVsData.center;
}

void spFlowBoost(VspModeData* md) {
    signed int r; // r16
    signed int goal0; // r17
    signed int goal1; // r18
    signed int lap0; // r19
    signed int lap1; // r20
    signed int set_result; // r21

    goal0 = vspVsData.result[0].goal;
    goal1 = vspVsData.result[1].goal;
    if (md->flow_mode == 3) {
        if ((goal0 != 0) && (goal1 != 0)) {
            if (vspVsData.result[0].time < vspVsData.result[1].time) {
                r = 0;
            } else {
                r = 1;
            }
        } else if (goal0 != 0) {
            r = 0;
        } else if (goal1 != 0) {
            r = 1;
        } else {
            lap0 = tmevGetLap(0);
            lap1 = tmevGetLap(1);
            if (lap0 == lap1) {
                r = tmetcGetRank(vspRider[0]->ctrl.nowpos.pos, vspRider[1]->ctrl.nowpos.pos);
            } else {
                r = (lap1 < lap0) ? 0 : 1;
            }
        }
        vspDispEnvChar[r].rank = 0;
        vspDispEnvChar[(r + 1) % 2].rank = 1;
    }
    if (md->flow_mode == 4) {
        set_result = 0;
        if ((md->flow_count == 1) && (vspEndRun == 0)) {
            set_result = 1;
        } else if (vspEndRun != 0) {
            // md->flow_count = 1;
            md->fade = 1;
        }
        if (set_result != 0) {
            if ((goal0 != 0) && (goal1 != 0)) {
                vspDispEnvChar[0].rank = 0;
                vspDispEnvChar[1].rank = 0;
                vspDispVsScore.draw = vspDispVsScore.draw + 1;
            } else if (vspDispEnvChar[0].rank < vspDispEnvChar[1].rank) {
                vspDispVsScore.win += 1;
            } else {
                vspDispVsScore.lose += 1;
            }
            nmdispInputResult();
        }
    }
    if (vspVsData.div_side != 0) {
        vspVsData.center = vsppScrWidth / 2;
    } else {
        vspVsData.center = vsppScrHeight / 2;
    }
    vspDispEnv.div = vspVsData.center;
}

static void spFlowPush(VspModeData* md) {
    signed int i; // r16
    signed int tmp; // r17
    Act* act; // r18
    signed int center_to; // r19
    signed int num_player; // r20
    unsigned int pts; // r21
    signed int center; // r22
    signed int line_center; // r23
    TrickLink* tl; // r30
    signed int div_side; // 0xAC(r29)
    signed int scr_size; // 0xB0(r29)
    signed int scr_size0; // 0xB4(r29)
    signed int move_length; // 0xB8(r29)
    signed int dead_line0; // 0xBC(r29)
    signed int dead_line1; // 0xC0(r29)
    signed int cnt_move; // 0xC4(r29)
    signed int line_center_to; // 0xC8(r29)
    signed int push_cnt; // 0xCC(r29)
    signed int set_result; // 0xD0(r29)
    signed int cnt[2]; // 0xA0(r29)

    div_side = vspVsData.div_side;
    num_player = vspenvGame->mode.num_player;
    scr_size = (div_side != 0) ? vsppScrWidth : vsppScrHeight;
    scr_size0 = 640;
    move_length = (scr_size * 32) / scr_size0;
    dead_line0 = (scr_size - move_length * 6 * 2) / 2;
    dead_line1 = scr_size - dead_line0;
    center = vspVsData.center_pos_id;
    center_to = vspVsData.center_to_pos_id;
    cnt_move = vspVsData.cnt_center_move;
    if ((md->flow_mode == 3) || (md->flow_mode == 6)) {
        for (i = 0; i < num_player; i++) {
            act = &vspRider[i]->ctrl.act;
            tl = &act->trick_link;
            cnt[i] = 0;
            if (act->trk_link_state == 2) {
                pts = tl->last_link_trick_point;
                pts = pts * vspDispEnvChar[i].match.push;
                pts = pts / 100;
                cnt[i] = pts / 2000;
            }
        }
        push_cnt = cnt[0] - cnt[1];
        if ((center_to == -6) && (push_cnt < 0)) {
            center_to--;
            md->next_flow_mode = (md->flow_mode == 3) ? 4 : 7;
            for (i = 0; i < num_player; i++) {
                vspRider[i]->ctrl.act.allow_tlink = 0;
            }
        } else if ((center_to == 6) && (push_cnt > 0)) {
            center_to++;
            md->next_flow_mode = (md->flow_mode == 3) ? 4 : 7;
            for (i = 0; i < num_player; i++) {
                vspRider[i]->ctrl.act.allow_tlink = 0;
            }
        } else {
            center_to += push_cnt;
            if (center_to < -6) {
                center_to = -6;
            } else if (center_to > 6) {
                center_to = 6;
            }
        }
    }
    if (md->flow_mode == 4) {
        set_result = 0;
        if ((md->flow_count == 1) && (vspEndRun == 0)) {
            set_result = 1;
        } else if (vspEndRun != 0) {
            md->fade = 1;
        }
        if (set_result != 0) {
            if (center_to == 0) {
                vspDispEnvChar[0].rank = 0;
                vspDispEnvChar[1].rank = 0;
                vspDispVsScore.draw += 1;
            } else if (center_to > 0) {
                vspDispEnvChar[0].rank = 0;
                vspDispEnvChar[1].rank = 1;
                vspDispVsScore.win += 1;
                center_to = 10;
            } else {
                vspDispEnvChar[0].rank = 1;
                vspDispEnvChar[1].rank = 0;
                vspDispVsScore.lose += 1;
                center_to = -10;
            }
            nmdispInputResult();
        }
    }
    if (cnt_move > 0) {
        cnt_move--;
    }
    if (cnt_move == 0) {
        if (center_to < center) {
            center--;
        } else if (center < center_to) {
            center++;
        }
        if (center != center_to) {
            cnt_move = 15;
        }
    }
    if (center < -6) {
        if (center == -10) {
            line_center = 0;
        } else {
            line_center = dead_line0 - (dead_line0 * (-center - 6)) / 4;
        }
    } else if (center > 6) {
        if (center == 10) {
            line_center = scr_size;
        } else {
            line_center = dead_line1 + (dead_line0 * (center - 6)) / 4;
        }
    } else {
        line_center = scr_size / 2 + (center * (dead_line1 - dead_line0)) / 12;
    }
    line_center_to = scr_size / 2 + (center_to * (dead_line1 - dead_line0)) / 12;
    if (center_to == -10) {
        line_center_to = 0;
    } else if (center_to == 10) {
        line_center_to = scr_size;
    }
    if ((md->flow_mode == 6) || (md->flow_mode == 7)) {
        line_center_to = line_center = scr_size / 2;
    }
    vspVsData.center = line_center;
    vspVsData.center_pos_id = center;
    vspVsData.center_to_pos_id = center_to;
    vspVsData.cnt_center_move = cnt_move;
    vspDispEnv.div = vspVsData.center;
    vspDispEnv.div_exp = line_center_to;
    for (i = 0; i < num_player; i++) {
        act = &vspRider[i]->ctrl.act;
        tmp = vspVsData.center_pos_id;
        if (i == 0) {
            if (tmp < 0) {
                tmp = -tmp * 50;
            } else {
                tmp = -tmp * 10;
            }
        } else {
            if (tmp > 0) {
                tmp = tmp * 50;
            } else {
                tmp = tmp * 10;
            }
        }
        tmp += 100;
        tmp += act->num_total_gap * 30;
        tmp += act->num_total_break * 10;
        if (tmp < 10) {
            tmp = 10;
        }
        vspDispEnvChar[i].match.push = tmp;
    }
}

static void spFlowHorse(VspModeData* md) {
    signed int set_result; // r21
    signed int pid0; // r17
    signed int pid1; // r19
    unsigned int pts0; // r20
    unsigned int pts1; // r22
    signed int state; // r18
    Act* act; // r16

    pid0 = md->horse_pid;
    pid1 = (pid0 + 1) % 2;
    if (md->flow_mode == 3) {
        act = &vspRider[pid0]->ctrl.act;
        if (act->trk_link_state == 2) {
            act->reserve_quit = 1;
            act->allow_tlink = 0;
            act->no_trick = 1;
        } else if (act->trk_link_state == 3) {
            act->reserve_quit = 1;
            act->allow_tlink = 0;
            act->no_trick = 1;
        }
    } else if (md->flow_mode == 4) {
        if ((md->to_end_sliding != 0) || (md->end_sliding != 0)) {
            set_result = 0;
            if ((md->to_end_sliding != 0) && (vspEndRun == 0)) {
                set_result = 1;
            } else if (vspEndRun != 0) {
                md->fade = 1;
            }
            if (set_result != 0) {
                pts0 = vspRider[pid0]->ctrl.act.trick_link.total_trick_point;
                pts1 = vspVsData.result[pid1].point;
                vspVsData.result[pid0].point = pts0;
                if (pts0 < pts1) {
                    state = 0;
                    vspDispEnvChar[pid0].rank = 1;
                    vspDispEnvChar[pid1].rank = 0;
                    if (pts1 != 0) {
                        vspVsData.horse_end_one_round = 1;
                        vspVsData.result[pid0].cnt_horse += 1;
                        if (vspVsData.result[pid0].cnt_horse >= vspVsData.horse_num_round) {
                            if (pid0 == 0) {
                                vspDispVsScore.lose += 1;
                            } else {
                                vspDispVsScore.win += 1;
                            }
                        }
                    }
                } else {
                    state = (pts0 != 0) ? 1 : 0;
                    vspDispEnvChar[pid0].rank = 0;
                    vspDispEnvChar[pid1].rank = 1;
                }
                nmdispInputHorseResult(state);
            }
            state = nmdispCheckHorse();
            if (state != 0) {
                md->fade = 1;
            }
        }
    }
}

void spSetWndClip(VspLocalGifPkt* gifpkt, signed int wid, signed int nwnd, signed int center, signed int send) {
    unsigned long scx0; // r16
    unsigned long scy0; // r17
    unsigned long scx1; // r18
    unsigned long scy1; // r19
    unsigned long scissor; // r20
    signed int div_side; // r21
    // Size: 0x10, DWARF: 0xCFD5D
    TestReg testreg[2]; // 0x70(r29)

    div_side = vspVsData.div_side;
    scx0 = 0;
    scy0 = 0;
    scx1 = (vsppScrWidth);
    scy1 = (vsppScrHeight);
    if (send != 0) {
        sceGifPkReset(gifpkt);
    }
    testreg[0].atest = 5;
    testreg[0].aref = 0x80;
    testreg[0].afail = 1;
    testreg[0].send = send;
    testreg[1].atest = 6;
    testreg[1].aref = 0;
    testreg[1].afail = 0;
    testreg[1].send = send;
    tmalphaSetTestReg(gifpkt, &testreg[0].atest, &testreg[1].atest);
    if (send != 0) {
        ulgifDmaWait();
        sceGifPkReset(gifpkt);
    }
    if (nwnd != 1) {
        if (div_side != 0) {
            if (wid == 0) {
                scx1 = (center);
            } else {
                scx0 = (center);
            }
        } else if (wid == 0) {
            scy1 = (center);
        } else {
            scy0 = (center);
        }
    }
    if (scx1 <= scx0) {
        scx1 = scx0 + 1;
    }
    if (scy1 <= scy0) {
        scy1 = scy0 + 1;
    }
    scissor = scx0 | ((scx1 - 1) << 16) | (scy0 << 32) | ((scy1 - 1) << 48);
    ulgifAddCNTSetGsRegister(gifpkt, 0x3F, 0);
    ulgifAddCNTSetGsRegister(gifpkt, 0x40, scissor);
    ulgifAddCNTSetGsRegister(gifpkt, 0x41, scissor);
    if (send != 0) {
        ulgifTermPacket(gifpkt);
        ulgifDmaSend(gifpkt);
        ulgifDmaWait();
    }
}

void spMakeViewScreenMatrix(VspSystemMatrix* mtx, signed int wid, signed int nwnd, signed int center) {
    ScreenInfo* scr; // r16 $s0
    unsigned long center_x; // r17 $s1
    unsigned long center_y; // r18 $s2
    unsigned long scx0; // r19 $s3
    unsigned long scx1; // r20 $s4
    unsigned long scy0; // r21 $s5
    unsigned long scy1; // r22 $s6
    signed int div_side; // r23 $s7
    
    div_side = vspVsData.div_side;
    scx0 = 0;
    scx1 = vsppScrWidth;
    scy0 = 0;
    scy1 = vsppScrHeight;
    scr = &mtx->scr_info;
    scr->aspect_x = (vsppScrWidth / 640.0f);
    scr->aspect_y = ((0.94f * vsppScrHeight) / 448.0f);
    if (nwnd != 1) {
        if (div_side != 0) {
            if (wid == 0) {
                scx1 = (center);
            } else {
                scx0 = (center);
            }
        } else if (wid == 0) {
            scy1 = (center);
        } else {
            scy0 = (center);
        }
    }
    
    center_x = (scx0 + scx1) / 2;
    center_x += (2048.0f - (vsppScrWidth / 2));
    scr->center_x = center_x;
    
    center_y = ((scy0 + scy1) / 2);
    center_y += (2048.0f - (vsppScrHeight / 2));
    scr->center_y = center_y;
    
    tmgraphSetMatrix(mtx->view_screen, mtx->view_clip, mtx->matrix.clip_screen, mtx);
    sceVu0MulMatrix(mtx->world_screen, mtx->view_screen, mtx->world_view);
}

signed int aksubClipScreen(float(* wsmat)[4], float(* mat)[4], float width, float height1, float height2, signed int wid, signed int divmode, float center);

#pragma fast_fptosi on

// spfree.c
void spUpdateDispState(Rider* rider, VspSystemMatrix* mtx, signed int wid, signed int nwnd, signed int center) {
    // Size: 0x2A30, DWARF: 0xCA227
    Disp* rdd; // r16
    signed int in; // r17
    signed int type; // r18
    float width;
    float height;
    signed int unused1;
    signed int unused2;
    signed int unused3;

    // rider = rider; // 50
    // mtx = mtx; // 60
    // wid = wid; // 70
    // nwnd = nwnd; // 80
    // center = M2C_ERROR(/* Read from unset register $t0 */); // 90
    rdd = &rider->disp;
    in = 0;
    type = 0;
    if (nwnd == 2 && vspModeData.flow_mode != 0) {
        type = (vspVsData.div_side != 0) ? 1 : 2;
    }
    
    in = aksubClipScreen(mtx->world_screen, rdd->mat_base_lw, 8.0f, -1.0f, -18.0f, wid, type, center);
    rdd->in_screen = in;
    rider->disp.disp_char = 1;
    if (vspModeData.horse_pid >= 0 && vspModeData.horse_pid != rider->pid) {
        rider->disp.disp_char = 0;
    }
}

signed int knReplayMain(Ctrl* chr, signed int num, signed int unused);
void knFinishCamera(Ctrl* chr /* 0x120(r29) */, unsigned int frame /* 0x130(r29) */, signed int num /* 0x140(r29) */);

// spfree.c
void spUpdateCamera_normal(signed int num_wnd, signed int horse_pid) {
    signed int var_s1;

    signed int i; // r16
    // DWARF: 0xD114B
    FlowMode flow; // r18
    signed int num_player; // r19
    
    num_player = vspenvGame->mode.num_player;
    flow = vspModeData.flow_mode;
    if ((vspenvOption->cheats.replay_view != 0) && (flow == efmHorseReady || flow == efmReady || flow == efmPlay)) {
        flow = efmReplay;
    }
    switch (flow) {
        case efmIntro:
        for (i = 0; i < num_wnd; i++) {
            vspIntroCutNum = knIntroMain(vspRider[i]->ctrl, vspModeData.flow_count, i);
        }
        return;
    
        case efmEnd:
        case efmRepEnd:
        if (horse_pid >= 0) {
            knFinishCamera(&vspRider[horse_pid]->ctrl, vspModeData.flow_count, horse_pid);
            return;
        }
        for (i = 0; i < num_wnd; i++) {
            knFinishCamera(&vspRider[i]->ctrl, vspRider[i]->ctrl.act.cnt_quit, i);
        }
        return;
        
        case efmRepReady:
        case efmReplay:
        if ((vspDispEnv.mode == 4) || (vspDispEnv.mode == 5)) {
            for (i = 0; i < num_wnd; i++) {
                if (vspRider[i]->ctrl.act.cnt_quit >= 0) {
                    knFinishCamera(&vspRider[i]->ctrl, vspRider[i]->ctrl.act.cnt_quit, i);
                } else {
                    if (num_player == 1) {
                        var_s1 = 1;
                    } else {
                        var_s1 = 0;
                    }
                    knReplayMain(&vspRider[i]->ctrl, i, var_s1);
                }
            }
            return;
        }
        if (horse_pid >= 0) {
            if (vspRider[horse_pid]->ctrl.act.cnt_quit >= 0) {
                knFinishCamera(&vspRider[horse_pid]->ctrl, vspRider[horse_pid]->ctrl.act.cnt_quit, horse_pid);
                return;
            }
            knReplayMain(&vspRider[horse_pid]->ctrl, horse_pid, 0);
            return;
        }
        for (i = 0; i < num_wnd; i++) {
            if (vspRider[i]->ctrl.act.cnt_quit >= 0) {
                knFinishCamera(&vspRider[i]->ctrl, vspRider[i]->ctrl.act.cnt_quit, i);
            } else {
                knReplayMain(&vspRider[i]->ctrl, i, 0);
            }
        }
        return;
    default:
        if (horse_pid >= 0) {
            knCameraCalc(vspRider[horse_pid]->ctrl, horse_pid);
            return;
        }
        for (i = 0; i < num_wnd; i++) {
            if (vspRider[i]->ctrl.act.cnt_quit >= 0) {
                knFinishCamera(&vspRider[i]->ctrl, vspRider[i]->ctrl.act.cnt_quit, i);
            } else {
                knCameraCalc(vspRider[i]->ctrl, i);
            }
        }
        return;
    }
}

static void spUpdateCamera_pause(signed int wid)
{
  float wv_mat [4][4];
  float cam_rot [4];
  float cam_trans [4];

  knCoreGetWVMat(wv_mat,wid);
  knCoreGetWState(cam_trans, cam_rot, wid);
}

void akevSetLensFlareScreen(signed int pn, signed int x, signed int y, signed int w, signed int h);

// spfree.c
void spDivScreenSetting() {
    signed int num_wnd; // r21
    signed int wid; // r16
    signed int x; // r17
    signed int y; // r18
    signed int w; // r19
    signed int h; // r20

    num_wnd = vspModeData.num_window;
    if (1 < num_wnd) {
        for (wid = 0; wid < num_wnd; wid++) {
            if (vspVsData.div_side != 0) {
                if (wid == 0) {
                    x = 0;
                    y = 0;
                    w = vspVsData.center;
                    h = vsppScrHeight;
                } else {
                    x = vspVsData.center;
                    y = 0;
                    w = vsppScrWidth - vspVsData.center;
                    h = vsppScrHeight;
                }
            } else if (wid == 0) {
                x = 0;
                y = 0;
                w = vsppScrWidth;
                h = vspVsData.center;
            } else {
                x = 0;
                y = vspVsData.center;
                w = vsppScrWidth;
                h = vsppScrHeight - vspVsData.center;
            }
            akevSetLensFlareScreen(wid, x, y, w, h);
        }
        gmsysSetScrDivLine(vspVsData.center);
        gmsysSetScrActiveWnd(vspVsWid);
    }
}

void spSetCrsDrawParam(CharacterRenderParams* param, VspSystemMatrix* mtx, signed int pid) {
    // Size: 0x140, DWARF: 0xC6770
    Matrix* g; // r16
    float lwm[4][4]; // 0x30(r29)
    g = &mtx->matrix;
    {
        float crs_trans[4] = { 0.0f, 0.0f, 0.0f, 1.0f }; // 0x70(r29)
        sceVu0FMATRIX* tmp;
        tmp = (sceVu0FMATRIX*)&crs_trans;

    sceVu0UnitMatrix(&lwm);
    sceVu0TransMatrix(&lwm, &lwm, &crs_trans);
    }
    sceVu0MulMatrix(g, mtx->world_screen, &lwm);
    sceVu0NormalLightMatrix(g->local_light, mtx->normal_light[0], mtx->normal_light[1], mtx->normal_light[2]);
    sceVu0LightColorMatrix(g->light_color, mtx->light_color[0], mtx->light_color[1], mtx->light_color[2], mtx->light_color[3]);
    sceVu0MulMatrix(g->local_clip, mtx->view_clip, mtx->world_view);
    sceVu0MulMatrix(g->local_clip, g->local_clip, &lwm);
    param->screen = &mtx->scr_info;
    param->matrix = g;
    param->fog = &mtx->fog;
    param->camera_position = (void* ) (mtx->cam_trans);
    param->camera_rotation = (void* ) (mtx->cam_rot);
    param->gif_packet = vgmsysGifPkt;
    param->vif1_packet = vgmsysVif1Pkt;
    param->alpha = vgmsysAbuf;
    param->view_angle = mtx->view_angle;
    param->player = pid;
}

void spDrawCourse1(CharacterRenderParams* param) {
    tmcrsDrawBG(param);
    tmcrsDrawEventModel(param);
}

void spDrawCourse2(CharacterRenderParams* param) {
    tmcrsDraw(param);
    ulgifDmaWait();
    sceGifPkReset(vgmsysGifPkt);
}

Cd* sploadGetCharacter(); // from spload.c
void ulvumdlDrawModel(VifPacket* vif1pkt, VgmsysAbuf* abuf, tag_ulcodCOORDINATE* coord, sceVu0FMATRIX* nl, sceVu0FMATRIX* _lcmat, unsigned char* model, Vmenv* env); // from vumodel.c

// spfree.c
void spDrawRider(VifPacket* vif1, Rider* rider, VspSystemMatrix* mtx) {
    // Size: 0x2A30, DWARF: 0xCA227
    Disp* rdd; // r16
    Model* md; // r17
    Cd* cd; // r18
    // Size: 0x2C00, DWARF: 0xCC651
    Ctrl* rc; // r19
    tag_ulcodCOORDINATE coord; // 0x50(r29)
    float nl[4][4]; // 0xE0(r29)
    float lc[4][4]; // 0x120(r29)
    float light_color0[4]; // 0x160(r29)

    rc = &rider->ctrl;
    rdd = &rider->disp;
    cd = sploadGetCharacter();
    md = &cd->model[rider->pid];
    *(__int128*)light_color0 = *(__int128*)rdd->light_color0;
    if (rdd->disp_shadow == 0) {
        light_color0[0] = 0.0f;
        light_color0[1] = 0.0f;
        light_color0[2] = 0.0f;
        light_color0[3] = 1.0f;
    }
    ulcodInitCoordinate(&coord, 0);
    sceVu0CopyMatrix(&coord.mat, rdd->umd_ctrl->matrix);
    coord.flag = 0;
    ulcodSetWvMatrix(mtx->world_view);
    ulcodSetVsMatrix(mtx->view_screen);
    if ((rdd->disp_char != 0) && (rdd->in_screen != 0)) {
        sceVu0NormalLightMatrix(&nl, rdd->normal_light0, rdd->normal_light1, rdd->normal_light2);
        sceVu0LightColorMatrix(&lc, &light_color0, rdd->light_color1, rdd->light_color2, &rdd->ambient);
        ultexSetTexPath2(vif1, md->utd[0].frame, md->utd[0].offset, md->utd[0].block);
        ulvumdlDrawModel(vif1, 0, &coord, &nl, &lc, rdd->umd, &rdd->vmenv);
    }
}

Cd* sploadGetCharacter(); // from spload.c
void ulvumdlDrawModelAlpha(VgmsysAbuf* abuf, tag_ulcodCOORDINATE* coord, sceVu0FMATRIX* nl, sceVu0FMATRIX* lcmat, unsigned char* model, Vmenv* env);
void aksdwDrawShadowVuMdl(VgmsysAbuf* abuf, tag_ulcodCOORDINATE* coord, float* _lvec, float* _nor, float* ppos, float height, float thickness,unsigned char* model,  signed int depth);

// spfree.c
void spDrawRider2(Rider* rider, VspSystemMatrix* mtx) {
    // Size: 0x2A30, DWARF: 0xCA227
    Disp* rdd; // r16
    // Size: 0x12F0, DWARF: 0xC7295
    Cd* cd; // r17
    // Size: 0x960, DWARF: 0xC2738
    Model* md; // r18
    tag_ulcodCOORDINATE coord; // 0x40(r29)
    float nl[4][4]; // 0xD0(r29)
    float lc[4][4]; // 0x110(r29)
    float light_color0[4]; // 0x150(r29)

    rdd = &rider->disp;
    cd = sploadGetCharacter();
    md = &cd->model[rider->pid];
    *(__int128*)light_color0 = *(__int128*)rdd->light_color0;
    if (rdd->disp_shadow == 0) {
        light_color0[0] = 0.0f;
        light_color0[1] = 0.0f;
        light_color0[2] = 0.0f;
        light_color0[3] = 1.0f;
    }
    ulcodInitCoordinate(&coord.super, 0);
    sceVu0CopyMatrix(&coord.mat, rdd->umd_ctrl->matrix);
    coord.flag = 0;
    ulcodSetWvMatrix(mtx->world_view);
    ulcodSetVsMatrix(mtx->view_screen);
    if (rdd->disp_char != 0 && rdd->in_screen != 0) {
        sceVu0NormalLightMatrix(&nl, rdd->normal_light0, rdd->normal_light1, rdd->normal_light2);
        sceVu0LightColorMatrix(&lc, &light_color0[0], rdd->light_color1, rdd->light_color2, &rdd->ambient);
        ulvumdlDrawModelAlpha(vgmsysAbuf, &coord, &nl, &lc, rdd->umd, &rdd->vmenv);
    }
    if (rdd->disp_shadow != 0 && (rdd->in_screen != 0 || (rdd->shadow_posy - rdd->nowpos.pos[1]) > 20.0f)) {
        aksdwDrawShadowVuMdl(vgmsysAbuf, &coord, rdd->shadow, rdd->nowpos.normal, rdd->nowpos.cross, rdd->shadow_posy, 1.0f, rdd->umd, 64);
    }
    // a0: vgmsysAbuf, a1: coord, a2: rdd->shadow, a3: rdd-nowpos.normal
    // t0: rdd->nowpos.cross
    // f12:rdd->shadow_posy
    // t1: rdd->umd
    // f13: 1.0f
    // t2: 64
}

Cd* sploadGetCharacter();

// spfree.c
void spDrawRider2Tex(VspLocalGifPkt* vgmsysGifPkt, Rider* rider)
{
    // Size: 0x960, DWARF: 0xC2738
    Model* md; // r16
    // Size: 0x12F0, DWARF: 0xC7295
    Cd* cd; // r17
    signed int erase_goggle; // r18
    signed int throw_goggle; // r19

    cd = sploadGetCharacter();
    md = &cd->model[rider->pid];
    throw_goggle = 0;
    erase_goggle = 0;
    ultexSetTexPath3(vgmsysGifPkt, md->utd[1].frame, md->utd[1].offset, md->utd[1].block);

    if ((rider->ctrl.cheats->metallic == 0) && (rider->ctrl.param->wear == 0)) {
        throw_goggle = 1;
    }
    return;
}

void spSetFade(signed int per, signed int col) {
    vspFadeCol = col;
    vspFadePercent = per;
}

void spSetWndFade(signed int wid, signed int per) {
    if (per < 0) {
        per = vspWndFadePercent[wid];
        per = per - 5;
        if (per < 0) {
            per = 0;
        }
    }
    vspWndFadePercent[wid] = per;
}

static void spFade(VspLocalGifPkt* pkt, signed int per, signed int col) {
    signed int wnd_width; // r23
    signed int z; // r18
    signed int sx0; // r17
    signed int sx1; // r19
    signed int sy0; // r20
    signed int sy1; // r21
    signed int alpha; // r30
    Poly* poly; // r16
    Alpha_Tag* a; // r22
    signed int qwc; // 0xAC(r29)

    wnd_width = vsppScrWidth;
    z = 0xFFFFFF;
    if (per > 100) {
        per = 100;
    }
    alpha = (per * 127) / 100;
    sx0 = 0x800 - vsppScrWidth / 2;
    sx1 = sx0 + wnd_width;
    sx0 = sx0 << 4;
    sx1 = sx1 << 4;
    sy0 = (0x800 - vsppScrHeight / 2) << 4;
    sy1 = (vsppScrHeight / 2 + 0x800) << 4;
    qwc = 6;
    a = (Alpha_Tag*)ulgifAddCNTReserve(pkt, qwc);
    poly = (Poly*)(a + 1);
    ulpktInitALPHA(a, 1);
    ulpktInitF4(poly, 1);
    poly->rgbaq0.ul = (s64)col | (s64)col << 8 | (s64)col << 16 | (s64)alpha << 24;
    poly->prim.sce.ABE = 1;
    poly->xyzf0.ul = ((s64)z << 0x20) | ((s64)sx0 | ((s64)sy0 << 0x10));
    poly->xyzf1.ul = ((s64)z << 0x20) | ((s64)sx1 | ((s64)sy0 << 0x10));
    poly->xyzf2.ul = ((s64)z << 0x20) | ((s64)sx0 | ((s64)sy1 << 0x10));
    poly->xyzf3.ul = ((s64)z << 0x20) | ((s64)sx1 | ((s64)sy1 << 0x10));
}

void spEnterEventCameraMode(void) {
    vspEventCamera = 1;
}

void spExitEventCameraMode() {
    vspEventCamera = 0;
}
