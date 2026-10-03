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
#pragma fast_fptosi on

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// Static data ///////////////////////////////////////////////////////////////////////

// kncamera.c structs ////////////////////////////////////////////////////////////////////

// DWARF: 0x116136
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

// DWARF: 0x1175D4
typedef enum Restart
{
    ersNone,
    ersNormal,
    ersReplay
} Restart;

// Size: 0x5C, DWARF: 0x112744
typedef struct VspModeData
{
    // DWARF: 0x116136
    FlowMode flow_mode; // Offset: 0x0, DWARF: 0x11275F
    unsigned int game_time_limit; // Offset: 0x4, DWARF: 0x112787
    unsigned int game_time; // Offset: 0x8, DWARF: 0x1127B3
    unsigned int game_count; // Offset: 0xC, DWARF: 0x1127D9
    unsigned int realtime_count; // Offset: 0x10, DWARF: 0x112800
    unsigned int flow_count; // Offset: 0x14, DWARF: 0x11282B
    signed int can_pause; // Offset: 0x18, DWARF: 0x112852
    signed int modnum; // Offset: 0x1C, DWARF: 0x112878
    signed int bgm_no; // Offset: 0x20, DWARF: 0x11289B
    signed int replay_speed; // Offset: 0x24, DWARF: 0x1128BE
    signed int num_window; // Offset: 0x28, DWARF: 0x1128E7
    signed int horse_pid; // Offset: 0x2C, DWARF: 0x11290E
    signed int end_sliding; // Offset: 0x30, DWARF: 0x112934
    signed int pause; // Offset: 0x34, DWARF: 0x11295C
    signed int pre_pause; // Offset: 0x38, DWARF: 0x11297E
    // DWARF: 0x116136
    FlowMode next_flow_mode; // Offset: 0x3C, DWARF: 0x1129A4
    // DWARF: 0x1175D4
    Restart restart; // Offset: 0x40, DWARF: 0x1129D1
    signed int next_modnum; // Offset: 0x44, DWARF: 0x1129F7
    signed int next_bgm_no; // Offset: 0x48, DWARF: 0x112A1F
    signed int fade; // Offset: 0x4C, DWARF: 0x112A47
    signed int to_end_sliding; // Offset: 0x50, DWARF: 0x112A68
    signed int next_replay_speed; // Offset: 0x54, DWARF: 0x112A93
    signed int next_pause; // Offset: 0x58, DWARF: 0x112AC1
} VspModeData;

// Size: 0x4, DWARF: 0x115E6C
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0x115E88
} CourseNo;

// Size: 0x1C, DWARF: 0x114D31
typedef struct CharacterParameters
{
    signed int ollie; // Offset: 0x0, DWARF: 0x114D4D
    signed int spin; // Offset: 0x4, DWARF: 0x114D6F
    signed int speed; // Offset: 0x8, DWARF: 0x114D90
    signed int landing; // Offset: 0xC, DWARF: 0x114DB2
    signed int balance; // Offset: 0x10, DWARF: 0x114DD6
    signed int stability; // Offset: 0x14, DWARF: 0x114DFA
    signed int stance; // Offset: 0x18, DWARF: 0x114E20
} CharacterParameters;

// Size: 0x10, DWARF: 0x11558A
typedef struct BoardParameters
{
    signed int speed; // Offset: 0x0, DWARF: 0x1155A6
    signed int stability; // Offset: 0x4, DWARF: 0x1155C8
    signed int balance; // Offset: 0x8, DWARF: 0x1155EE
    signed int turning; // Offset: 0xC, DWARF: 0x115612
} BoardParameters;

// Size: 0x3C, DWARF: 0x115811
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x11582D
    signed int player; // Offset: 0x4, DWARF: 0x11584C
    signed int wear; // Offset: 0x8, DWARF: 0x11586F
    signed int board; // Offset: 0xC, DWARF: 0x115890
    // Size: 0x1C, DWARF: 0x114D31
    CharacterParameters chr_param; // Offset: 0x10, DWARF: 0x1158B2
    // Size: 0x10, DWARF: 0x11558A
    BoardParameters brd_param; // Offset: 0x2C, DWARF: 0x1158DA
} Character;

// Size: 0x18, DWARF: 0x11400B
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x114027
    signed int game_mode; // Offset: 0x4, DWARF: 0x11404E
    signed int match_rule; // Offset: 0x8, DWARF: 0x114074
    signed int divide; // Offset: 0xC, DWARF: 0x11409B
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x1140BE
} Mode;

// Size: 0xA0, DWARF: 0x114FCC
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x115E6C
    CourseNo course; // Offset: 0x0, DWARF: 0x114FE8
    // Size: 0x3C, DWARF: 0x115811
    Character character[2]; // Offset: 0x4, DWARF: 0x11500D
    // Size: 0x18, DWARF: 0x11400B
    Mode mode; // Offset: 0x7C, DWARF: 0x115035
    signed int language; // Offset: 0x94, DWARF: 0x115058
    signed int ending; // Offset: 0x98, DWARF: 0x11507D
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x1150A0
} VspenvGame;

// Size: 0x50, DWARF: 0x113C6A
typedef struct Camera
{
    float rot[4]; // Offset: 0x0, DWARF: 0x113C86
    float trans[4]; // Offset: 0x10, DWARF: 0x113CA8
    float obj[4]; // Offset: 0x20, DWARF: 0x113CCC
    float aim[4]; // Offset: 0x30, DWARF: 0x113CEE
    float up[4]; // Offset: 0x40, DWARF: 0x113D10
} Camera;

// Size: 0x20, DWARF: 0x1100C9
typedef struct Event
{
    float ope[4]; // Offset: 0x0, DWARF: 0x1100E4
    float rateX; // Offset: 0x10, DWARF: 0x110106
    float dis; // Offset: 0x14, DWARF: 0x110128
    unsigned int dis_cnt; // Offset: 0x18, DWARF: 0x110148
    signed int event; // Offset: 0x1C, DWARF: 0x11016C
} Event;

// Size: 0x130, DWARF: 0x10FC5F
typedef struct VknCamera
{
    // Size: 0x50, DWARF: 0x113C6A
    Camera cam; // Offset: 0x0, DWARF: 0x10FC7A
    float old_rot[4]; // Offset: 0x50, DWARF: 0x10FC9C
    float old_pos[4]; // Offset: 0x60, DWARF: 0x10FCC2
    float old_chr[4]; // Offset: 0x70, DWARF: 0x10FCE8
    float cv[4]; // Offset: 0x80, DWARF: 0x10FD0E
    float ov[4]; // Offset: 0x90, DWARF: 0x10FD2F
    float add_rip[4]; // Offset: 0xA0, DWARF: 0x10FD50
    float tumble_pos[4]; // Offset: 0xB0, DWARF: 0x10FD76
    float ip_rate[4]; // Offset: 0xC0, DWARF: 0x10FD9F
    float def_dis; // Offset: 0xD0, DWARF: 0x10FDC5
    float def_rot; // Offset: 0xD4, DWARF: 0x10FDE9
    float base_dis; // Offset: 0xD8, DWARF: 0x10FE0D
    float up_rot; // Offset: 0xDC, DWARF: 0x10FE32
    float old_h; // Offset: 0xE0, DWARF: 0x10FE55
    float old_tilt; // Offset: 0xE4, DWARF: 0x10FE77
    float eff_cnt; // Offset: 0xE8, DWARF: 0x10FE9C
    float shake_pow; // Offset: 0xEC, DWARF: 0x10FEC0
    float hopup_height; // Offset: 0xF0, DWARF: 0x10FEE6
    float boost_dis; // Offset: 0xF4, DWARF: 0x10FF0F
    signed short boost_cnt; // Offset: 0xF8, DWARF: 0x10FF35
    signed short tumble_cnt; // Offset: 0xFA, DWARF: 0x10FF5B
    signed short effect; // Offset: 0xFC, DWARF: 0x10FF82
    signed short vc_cnt; // Offset: 0xFE, DWARF: 0x10FFA5
    signed short vc_cnt2; // Offset: 0x100, DWARF: 0x10FFC8
    signed short finish_flg; // Offset: 0x102, DWARF: 0x10FFEC
    signed short old_hpair; // Offset: 0x104, DWARF: 0x110013
    signed short pad[5]; // Offset: 0x106, DWARF: 0x110039
    // Size: 0x20, DWARF: 0x1100C9
    Event event; // Offset: 0x110, DWARF: 0x11005B
} VknCamera;

// Size: 0x30, DWARF: 0x11474A
typedef struct ScreenInfo
{
    float aspect_x; // Offset: 0x0, DWARF: 0x114766
    float aspect_y; // Offset: 0x4, DWARF: 0x11478B
    float center_x; // Offset: 0x8, DWARF: 0x1147B0
    float center_y; // Offset: 0xC, DWARF: 0x1147D5
    float clip_vol_x; // Offset: 0x10, DWARF: 0x1147FA
    float clip_vol_y; // Offset: 0x14, DWARF: 0x114821
    float min_z; // Offset: 0x18, DWARF: 0x114848
    float max_z; // Offset: 0x1C, DWARF: 0x11486A
    float near_z; // Offset: 0x20, DWARF: 0x11488C
    float far_z; // Offset: 0x24, DWARF: 0x1148AF
    float screen_z; // Offset: 0x28, DWARF: 0x1148D1
    float res; // Offset: 0x2C, DWARF: 0x1148F6
} ScreenInfo;

// Size: 0x20, DWARF: 0x114C6E
typedef struct Fog
{
    float min; // Offset: 0x0, DWARF: 0x114C8A
    float max; // Offset: 0x4, DWARF: 0x114CAA
    float far; // Offset: 0x8, DWARF: 0x114CCA
    float near; // Offset: 0xC, DWARF: 0x114CEA
    signed int col[4]; // Offset: 0x10, DWARF: 0x114D0B
} Fog;

// Size: 0x140, DWARF: 0x114EDA
typedef struct Matrix
{
    float local_screen[4][4]; // Offset: 0x0, DWARF: 0x114EF6
    float local_light[4][4]; // Offset: 0x40, DWARF: 0x114F21
    float light_color[4][4]; // Offset: 0x80, DWARF: 0x114F4B
    float local_clip[4][4]; // Offset: 0xC0, DWARF: 0x114F75
    float clip_screen[4][4]; // Offset: 0x100, DWARF: 0x114F9E
} Matrix;

// Size: 0x340, DWARF: 0x11538C
typedef struct VspSystemMatrix
{
    // Size: 0x30, DWARF: 0x11474A
    ScreenInfo scr_info; // Offset: 0x0, DWARF: 0x1153A8
    // Size: 0x20, DWARF: 0x114C6E
    Fog fog; // Offset: 0x30, DWARF: 0x1153CF
    // Size: 0x140, DWARF: 0x114EDA
    Matrix matrix; // Offset: 0x50, DWARF: 0x1153F1
    float world_screen[4][4]; // Offset: 0x190, DWARF: 0x115416
    float world_view[4][4]; // Offset: 0x1D0, DWARF: 0x115441
    float view_screen[4][4]; // Offset: 0x210, DWARF: 0x11546A
    float light_color[4][4]; // Offset: 0x250, DWARF: 0x115494
    float normal_light[4][4]; // Offset: 0x290, DWARF: 0x1154BE
    float view_clip[4][4]; // Offset: 0x2D0, DWARF: 0x1154E9
    float cam_rot[4]; // Offset: 0x310, DWARF: 0x115511
    float cam_trans[4]; // Offset: 0x320, DWARF: 0x115537
    float view_angle; // Offset: 0x330, DWARF: 0x11555F
    char padding[0xC]; // Not normally in struct but added to pad struct to size.
} VspSystemMatrix;

// Size: 0x18, DWARF: 0x116FB3
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0x116FCF
    signed int month; // Offset: 0x4, DWARF: 0x116FF0
    signed int day; // Offset: 0x8, DWARF: 0x117012
    signed int hour; // Offset: 0xC, DWARF: 0x117032
    signed int minute; // Offset: 0x10, DWARF: 0x117053
    signed int second; // Offset: 0x14, DWARF: 0x117076
} Clock;

// Size: 0x38, DWARF: 0x117930
typedef struct File
{
    // Size: 0x18, DWARF: 0x116FB3
    Clock clock; // Offset: 0x0, DWARF: 0x11794C
    char name[32]; // Offset: 0x18, DWARF: 0x117970
} File;

// Size: 0x8, DWARF: 0x11308A
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x1130A5
    signed char lh; // Offset: 0x2, DWARF: 0x1130C5
    signed char lv; // Offset: 0x3, DWARF: 0x1130E4
    signed int analog; // Offset: 0x4, DWARF: 0x113103
} PadData;

// Size: 0x24, DWARF: 0x112AEC
typedef struct KeyCommands
{
    signed int vibration; // Offset: 0x0, DWARF: 0x112B07
    signed int spin_l; // Offset: 0x4, DWARF: 0x112B2D
    signed int spin_r; // Offset: 0x8, DWARF: 0x112B50
    signed int stance; // Offset: 0xC, DWARF: 0x112B73
    signed int revert; // Offset: 0x10, DWARF: 0x112B96
    signed int grind; // Offset: 0x14, DWARF: 0x112BB9
    signed int grab; // Offset: 0x18, DWARF: 0x112BDB
    signed int jump; // Offset: 0x1C, DWARF: 0x112BFC
    signed int flip; // Offset: 0x20, DWARF: 0x112C1D
} KeyCommands;

// Size: 0x74, DWARF: 0x11521B
typedef struct CharacterState
{
    signed int secret; // Offset: 0x0, DWARF: 0x115237
    unsigned int board; // Offset: 0x4, DWARF: 0x11525A
    unsigned int course; // Offset: 0x8, DWARF: 0x11527C
    signed int rem_point; // Offset: 0xC, DWARF: 0x11529F
    signed int old_brd_no; // Offset: 0x10, DWARF: 0x1152C5
    signed int old_wear_no; // Offset: 0x14, DWARF: 0x1152EC
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x115314
    signed int soft[8]; // Offset: 0x38, DWARF: 0x11533D
    // Size: 0x1C, DWARF: 0x114D31
    CharacterParameters parameter; // Offset: 0x58, DWARF: 0x115360
} CharacterState;

// Size: 0xEC, DWARF: 0x115B07
typedef struct CreatedCharacter
{
    // Size: 0x74, DWARF: 0x11521B
    CharacterState character; // Offset: 0x0, DWARF: 0x115B23
    // Size: 0x1C, DWARF: 0x114D31
    CharacterParameters init_param; // Offset: 0x74, DWARF: 0x115B4B
    // Size: 0x18, DWARF: 0x116FB3
    Clock clock; // Offset: 0x90, DWARF: 0x115B74
    char name[16]; // Offset: 0xA8, DWARF: 0x115B98
    signed int age; // Offset: 0xB8, DWARF: 0x115BBB
    signed int sex; // Offset: 0xBC, DWARF: 0x115BDB
    signed int face; // Offset: 0xC0, DWARF: 0x115BFB
    signed int hair; // Offset: 0xC4, DWARF: 0x115C1C
    signed int hair_color; // Offset: 0xC8, DWARF: 0x115C3D
    signed int body; // Offset: 0xCC, DWARF: 0x115C64
    signed int body_color; // Offset: 0xD0, DWARF: 0x115C85
    signed int pants; // Offset: 0xD4, DWARF: 0x115CAC
    signed int pants_color; // Offset: 0xD8, DWARF: 0x115CCE
    signed int glove; // Offset: 0xDC, DWARF: 0x115CF6
    signed int boots; // Offset: 0xE0, DWARF: 0x115D18
    signed int board_type; // Offset: 0xE4, DWARF: 0x115D3A
    signed int trick_type; // Offset: 0xE8, DWARF: 0x115D61
} CreatedCharacter;

// Size: 0x30, DWARF: 0x113670
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x11368C
    signed int always_sp; // Offset: 0x4, DWARF: 0x1136AD
    signed int perfect_b; // Offset: 0x8, DWARF: 0x1136D3
    signed int super_spin; // Offset: 0xC, DWARF: 0x1136F9
    signed int half_g; // Offset: 0x10, DWARF: 0x113720
    signed int fast_motion; // Offset: 0x14, DWARF: 0x113743
    signed int super_speed; // Offset: 0x18, DWARF: 0x11376B
    signed int big_head; // Offset: 0x1C, DWARF: 0x113793
    signed int metallic; // Offset: 0x20, DWARF: 0x1137B8
    signed int mirror; // Offset: 0x24, DWARF: 0x1137DD
    signed int replay_view; // Offset: 0x28, DWARF: 0x113800
    signed int partition; // Offset: 0x2C, DWARF: 0x113828
} Cheats;

// Size: 0x2DCEC, DWARF: 0x113964
typedef struct VspenvReplay
{
    // Size: 0x38, DWARF: 0x117930
    File file; // Offset: 0x0, DWARF: 0x113980
    signed int pid; // Offset: 0x38, DWARF: 0x1139A3
    signed int num_frame; // Offset: 0x3C, DWARF: 0x1139C3
    unsigned int game_time; // Offset: 0x40, DWARF: 0x1139E9
    signed int endrun_frame; // Offset: 0x44, DWARF: 0x113A0F
    // Size: 0x8, DWARF: 0x11308A
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0x113A38
    // Size: 0x24, DWARF: 0x112AEC
    KeyCommands key; // Offset: 0x2DB88, DWARF: 0x113A5F
    // Size: 0xEC, DWARF: 0x115B07
    CreatedCharacter character; // Offset: 0x2DBAC, DWARF: 0x113A81
    // Size: 0x30, DWARF: 0x113670
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0x113AA9
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0x113ACE
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0x113AF1
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0x113B14
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0x113B38
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0x113B5B
    // Size: 0x10, DWARF: 0x11558A
    BoardParameters brd_param; // Offset: 0x2DCDC, DWARF: 0x113B81
} VspenvReplay;

// Size: 0x20, DWARF: 0x117668
typedef struct PadState
{
    signed int id; // Offset: 0x0, DWARF: 0x117684
    unsigned int now; // Offset: 0x4, DWARF: 0x1176A3
    unsigned int status; // Offset: 0x8, DWARF: 0x1176C3
    unsigned int press; // Offset: 0xC, DWARF: 0x1176E6
    signed char right_h; // Offset: 0x10, DWARF: 0x117708
    signed char right_v; // Offset: 0x11, DWARF: 0x11772C
    signed char left_h; // Offset: 0x12, DWARF: 0x117750
    signed char left_v; // Offset: 0x13, DWARF: 0x117773
    unsigned char l_right; // Offset: 0x14, DWARF: 0x117796
    unsigned char l_left; // Offset: 0x15, DWARF: 0x1177BA
    unsigned char l_up; // Offset: 0x16, DWARF: 0x1177DD
    unsigned char l_down; // Offset: 0x17, DWARF: 0x1177FE
    unsigned char r_up; // Offset: 0x18, DWARF: 0x117821
    unsigned char r_right; // Offset: 0x19, DWARF: 0x117842
    unsigned char r_down; // Offset: 0x1A, DWARF: 0x117866
    unsigned char r_left; // Offset: 0x1B, DWARF: 0x117889
    unsigned char r_1; // Offset: 0x1C, DWARF: 0x1178AC
    unsigned char l_1; // Offset: 0x1D, DWARF: 0x1178CC
    unsigned char r_2; // Offset: 0x1E, DWARF: 0x1178EC
    unsigned char l_2; // Offset: 0x1F, DWARF: 0x11790C
} PadState;

// Size: 0x60, DWARF: 0x113D35
typedef struct VgmsysPad
{
    // Size: 0x20, DWARF: 0x117668
    PadState now; // Offset: 0x0, DWARF: 0x113D51
    // Size: 0x20, DWARF: 0x117668
    PadState old; // Offset: 0x20, DWARF: 0x113D73
    unsigned int port; // Offset: 0x40, DWARF: 0x113D95
    unsigned int slot; // Offset: 0x44, DWARF: 0x113DB6
    unsigned int mode; // Offset: 0x48, DWARF: 0x113DD7
    unsigned int trg; // Offset: 0x4C, DWARF: 0x113DF8
    unsigned int rev; // Offset: 0x50, DWARF: 0x113E18
    unsigned int cnt; // Offset: 0x54, DWARF: 0x113E38
    unsigned int rep; // Offset: 0x58, DWARF: 0x113E58
    signed int state; // Offset: 0x5C, DWARF: 0x113E78
} VgmsysPad;

// Size: 0x60, DWARF: 0x1161D3
typedef struct Cross
{
    float normal[4]; // Offset: 0x0, DWARF: 0x1161EF
    float point[4]; // Offset: 0x10, DWARF: 0x116214
    float* vertex[4]; // Offset: 0x20, DWARF: 0x116238
    unsigned int attr; // Offset: 0x24, DWARF: 0x116260
    signed int nvertex; // Offset: 0x28, DWARF: 0x116281
    signed int no; // Offset: 0x2C, DWARF: 0x1162A5
    float len; // Offset: 0x30, DWARF: 0x1162C4
    signed int rail_no; // Offset: 0x34, DWARF: 0x1162E4
    signed int obj_no; // Offset: 0x38, DWARF: 0x116308
    signed int obj_attr; // Offset: 0x3C, DWARF: 0x11632B
    signed int obj_type; // Offset: 0x40, DWARF: 0x116350
    signed int res[4]; // Offset: 0x44, DWARF: 0x116375
} Cross;

// SCE types ///////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

//////// vspRider Struct ///////////////////////////////////////////////
// Last updated: 08/14/2024

// Size: 0x30, DWARF: 0x7DAC1, 0x1C06F9
// typedef struct Cheats
// {
//     signed int kids; // Offset: 0x0, DWARF: 0x7DADD
//     signed int always_sp; // Offset: 0x4, DWARF: 0x7DAFE
//     signed int perfect_b; // Offset: 0x8, DWARF: 0x7DB24
//     signed int super_spin; // Offset: 0xC, DWARF: 0x7DB4A
//     signed int half_g; // Offset: 0x10, DWARF: 0x7DB71
//     signed int fast_motion; // Offset: 0x14, DWARF: 0x7DB94
//     signed int super_speed; // Offset: 0x18, DWARF: 0x7DBBC
//     signed int big_head; // Offset: 0x1C, DWARF: 0x7DBE4
//     signed int metallic; // Offset: 0x20, DWARF: 0x7DC09
//     signed int mirror; // Offset: 0x24, DWARF: 0x7DC2E
//     signed int replay_view; // Offset: 0x28, DWARF: 0x7DC51
//     signed int partition; // Offset: 0x2C, DWARF: 0x7DC79
// } Cheats;

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

// DWARF: 0x1169E0
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

// DWARF: 0x10FBE7
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

// DWARF: 0x7EA91, 0x1C52E1
// DWARF: 0x110083
typedef enum Ripside
{
    ersNoRip,
    ersLeft,
    ersRight
} Ripside;

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

// Size: 0x190, DWARF: 0x16B9B7, 0x11312A
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

// Size: 0x2C00, DWARF: 0x16AA87, 0xBAAA7, 0x10F6C0
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


//// Variables ///////////////////////////////////////////////////////////////////////

static signed int vknViewFlg_1P; // Address: 0x2E7BE8
static signed int vknViewFlg_2P[2] = { 0, 0 }; // Address: 0x2E7810
// Size: 0x5C, DWARF: 0x112744
extern VspModeData vspModeData; // Address: 0x3BF620
// Size: 0xA0, DWARF: 0x114FCC
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x130, DWARF: 0x10FC5F
static VknCamera vknCamera[2]; // Address: 0x3C0CA0
// Size: 0x340, DWARF: 0x11538C
extern VspSystemMatrix vspSystemMatrix[2]; // Address: 0x3BF6B0
// Size: 0x2DCEC, DWARF: 0x113964
extern VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
// Size: 0x60, DWARF: 0x113D35
extern VgmsysPad* vgmsysPad[2]; // Address: 0x2E7B30

//// Function Declarations ///////////////////////////////////////////////////////////

static void knCameraSetBoostAction(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x190, DWARF: 0x11312A
Cam* chr);
float acosf(float a);
float atan2f(float y, float x);
float cosf(float a);
float sinf(float a);
float fabsf(float a);
void* memset(void* dst, int c, unsigned int len);
void sceVu0AddVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0ApplyMatrix(sceVu0FVECTOR a, sceVu0FMATRIX b, sceVu0FVECTOR c);
void sceVu0DivVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float q);
float sceVu0InnerProduct(sceVu0FVECTOR vec1, sceVu0FVECTOR vec2);
void sceVu0InterVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2, float r);
void sceVu0MulVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2, sceVu0FVECTOR vec3);
void sceVu0Normalize(sceVu0FVECTOR a, sceVu0FVECTOR b);
void sceVu0OuterProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);
void sceVu0ScaleVector(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0SubVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0UnitMatrix(sceVu0FMATRIX a);
void knCoreAddVectorXYZ(float* out, float* v1, float* v2);
void knCoreGetAngle(float* rot, float* trans, float* obj);
signed int knCoreGetBaseHit(Cross* near_hit, float* pos1, float* pos2);
signed int knCoreGetCourseHit(Cross* near_hit, float* pos1, float* pos2);
signed int knCoreGetCourseHit2(signed int* ret, Cross* near_hit, float (*pos1)[4], float (*pos2)[4], float* src, signed int num);
float knCoreGetDifAngY(float* p1, float* p2, float* p3);
void knCoreRotMatrix(sceVu0FVECTOR* mat, float* rot);
void knCoreSetWState(Camera* data, signed int num);
void knEventEnd();
signed int knEventGet();
void knCameraInit(// Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, signed int num);
void knCameraSetScrZ(signed int num);
signed int knCameraCalc(// Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, signed int num);
static void knCameraDefaultView(float* rot, // Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, float* chr_pos, float* css, float* oss);
static void knCameraHalfPipeView(float* rot, // Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x190, DWARF: 0x11312A
Cam* chr);
static void knCameraRailSlideView(float* rot, // Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x190, DWARF: 0x11312A
Cam* chr);
static void knCameraSetLandShake(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, float power);
static void knCameraLandShake(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, sceVu0FMATRIX mat);
static signed int knCameraSpringCheck(// Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr);
static void knCameraChange(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x190, DWARF: 0x11312A
Cam* chr, signed int num_window, signed int p_id);
static void knCameraTumbleAction(float* chr_pos, // Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, float* css, float* oss, signed int* spring);
static float knCameraTiltAction(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x190, DWARF: 0x11312A
Cam* chr);
static void knCameraBoostAction(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, Cam* unused_cam, signed int num);
static void knCameraInterPol(float* rot, float* r1, float* r2, float* rate);
static void knCalcMain(float* new_dst, float* src, float* dst, float* v, float* ss, float* dd);
void knCameraSetFixRotation(float* rot, signed int id);
void knCameraSetDis(float dis, signed int id);
void knCameraEndDis(signed int id);
void knCameraEventAllReset(signed int id);
void knFinishCamera(// Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, unsigned int frame, signed int num);
static void knCameraKeepCourse(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, float* chr_pos, float* rot);
static signed int knCameraKeepCourse2b(// Size: 0x50, DWARF: 0x113C6A
Camera* base, // Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, signed int* spring);
static void knAngAxisToQuat(float* q, float* axis, float ang);
static float knQuatToAngAxis(float* axis, float* q);
static void knQuatSlerp(float* q, float* q1, float* q2, float t);


// Included Functions //////////////////////////////////
void gmsysSetWndBlurPow(signed int wid, signed int pow);

void knCameraInit(Ctrl* chr, s32 num) {
    // Size: 0x50, DWARF: 0x113C6A
    Camera* base; // r16
    // Size: 0x130, DWARF: 0x10FC5F
    VknCamera* cam; // r17
    // Size: 0x18, DWARF: 0x11400B
    Mode* mode; // r18
    float mat[4][4]; // 0x40(r29)
    float dis[4]; // 0x80(r29)
    float vec[4]; //0x90, not in DWARF data

    cam = &vknCamera[num];
    base = &cam->cam;
    mode = &vspenvGame->mode;
    memset(cam, 0, 0x130);
    if (vspModeData.num_window == 1) {
        cam->def_dis = -35.0f;
        cam->def_rot = -0.45f;
    } else {
        cam->def_dis = -50.0f;
        if (mode->divide == 0) {
            cam->def_rot = -0.45f;
        } else {
            cam->def_rot = -0.3f;
        }
    }
    dis[0] = 0.0f;
    dis[1] = 0.0f;
    dis[2] = cam->def_dis;
    dis[3] = 1.0f;
    base->aim[0] = 0.0f;
    base->aim[1] = -0.2f;
    base->aim[2] = 1.0f;
    base->aim[3] = 1.0f;
    base->up[0] = 0.0f;
    base->up[1] = 1.0f;
    base->up[2] = 0.0f;
    base->up[3] = 1.0f;
    sceVu0CopyVector(base->obj, chr->cam.pos_disp);
    sceVu0CopyVector(base->rot, chr->cam.rot);
    if (!((3.1415927f + base->rot[1]) <= 3.1415927f)) {
        vec[0] = (3.1415927f + base->rot[1]) - 6.2831855f;
    } else {
        if ((3.1415927f + base->rot[1]) < -3.1415927f) {
            vec[1] = 6.2831855f + (3.1415927f + base->rot[1]);
        } else {
            vec[1] = 3.1415927f + base->rot[1];
        }
        vec[0] = vec[1];
    }
    base->rot[1] = vec[0];
    if (!((base->rot[0] + cam->def_rot) <= 3.1415927f)) {
        vec[2] = (base->rot[0] + cam->def_rot) - 6.2831855f;
    } else {
        if ((base->rot[0] + cam->def_rot) < -3.1415927f) {
            vec[3] = 6.2831855f + (base->rot[0] + cam->def_rot);
        } else {
            vec[3] = base->rot[0] + cam->def_rot;
        }
        vec[2] = vec[3];
    }
    base->rot[0] = vec[2];
    knCoreRotMatrix(&mat, base);
    sceVu0ApplyMatrix(&dis, &mat, &dis);
    sceVu0AddVector(base->trans, base->obj, &dis);
    sceVu0CopyVector(cam->old_pos, base->trans);
    sceVu0CopyVector(cam->old_rot, base->rot);
    sceVu0CopyVector(cam->old_chr, chr->cam.pos_disp);
    cam->ip_rate[0] = 0.07f;
    cam->ip_rate[1] = 0.03f;
    cam->ip_rate[2] = 0.02f;
    vknViewFlg_2P[1] = 0;
    vknViewFlg_2P[0] = 0;
    knCoreSetWState(base, num);
    knEventEnd();
}

void knCameraSetScrZ(s32 num) {
    vspSystemMatrix[num].scr_info.screen_z = 300.0f;
}

s32 knCameraCalc(Ctrl* chr, s32 num) {
    sceVu0FVECTOR rot; // 0x60(r29)
    sceVu0FVECTOR chr_pos; // 0x70(r29)
    sceVu0FVECTOR old_pos; // 0x80(r29)
    sceVu0FVECTOR dis; // 0x90(r29)
    sceVu0FVECTOR tmp_dis; // 0xA0(r29)
    sceVu0FMATRIX mat; // 0xB0(r29)
    // Size: 0x130, DWARF: 0x10FC5F
    VknCamera* cam = &vknCamera[num]; // r16
    // Size: 0x50, DWARF: 0x113C6A
    Camera* base = cam; // r17
    sceVu0FVECTOR css = { 5.0f, 5.0f, 5.0f, 0.0f }; // 0xF0(r29)
    sceVu0FVECTOR* unused1 = &css;
    sceVu0FVECTOR oss = { 8.5f, 5.0f, 8.5f, 0.0f }; // 0x100(r29)
    sceVu0FVECTOR* unused2 = &oss;
    signed int check; // r20
    signed int spring; // 0x11C(r29)
    static sceVu0FVECTOR cdd = { 3.0f, 3.0f, 3.0f, 0.0f }; // 0x2CCE20
    static sceVu0FVECTOR odd = { 3.0f, 3.0f, 3.0f, 0.0f }; // 0x2CCE30

    (void)unused1;
    (void)unused2;
    
    if (knEventGet() != 0) {
        return 1;
    }
    spring = knCameraSpringCheck(chr);
    cam->up_rot = cam->def_rot;
    if (cam->event.event & 0x10) {
        cam->up_rot += cam->event.rateX;
    }
    knCameraChange(cam, &chr->cam, vspModeData.num_window, num);
    if (vspenvGame->mode.match_rule == 1) {
        knCameraSetBoostAction(cam, &chr->cam);
        if (((cam->boost_cnt)) & 0x8000) {
            knCameraBoostAction(cam, &chr->cam, num);
        }
    }
    dis[0] = 0.0f;
    dis[1] = 0.0f;
    dis[2] = cam->def_dis;
    dis[3] = 1.0f;
    knCameraTumbleAction(&chr_pos, cam, chr, css, oss, &spring);
    knCameraDefaultView(&rot[0], cam, chr, chr_pos, css, oss);
    knCameraHalfPipeView(&rot[0], cam, &chr->cam);
    knCameraRailSlideView(&rot[0], cam, &chr->cam);
    knCoreRotMatrix(&mat, &rot[0]);
    sceVu0ApplyMatrix(&tmp_dis, &mat, &dis[0]);
    knCoreAddVectorXYZ(base->trans, &chr_pos, &tmp_dis);
    if (chr->cam.trg_recovered == 0) {
        knCameraKeepCourse(cam, chr, &chr_pos, &rot[0]);
    }
    if (cam->event.event & 1) {
        rot[0] = cam->event.ope[0];
    }
    if (cam->event.event & 2) {
        rot[1] = cam->event.ope[1];
    }
    if (cam->event.event & 4) {
        rot[2] = cam->event.ope[2];
    }
    if (cam->event.event & 8) {
        sceVu0CopyVector(&rot[0], cam->event.ope);
    }
    if (chr->cam.trg_recovered == 0) {
        knCameraInterPol(&rot[0], cam->old_rot, &rot[0], cam->ip_rate);
    } else {
        sceVu0CopyVector(cam->old_rot, &rot[0]);
    }
    if (spring == 1) {
        knCalcMain(&chr_pos, cam->old_chr, &chr_pos, cam->ov, oss, odd);
    }
    knCoreRotMatrix(&mat, &rot[0]);
    sceVu0ApplyMatrix(&tmp_dis, &mat, &dis[0]);
    knCoreAddVectorXYZ(base->trans, &chr_pos, &tmp_dis);
    sceVu0CopyVector(&old_pos, base->trans);
    check = knCameraKeepCourse2b(base, chr, &spring);
    if (spring == 1) {
        knCalcMain(base->trans, cam->old_pos, base->trans, cam->cv, css, cdd);
    }
    sceVu0CopyVector(base, &rot[0]);
    sceVu0CopyVector(base->obj, chr->cam.pos_disp);
    if (((cam->effect)) & 4) {
        knCameraLandShake(cam, chr, mat);
    }
    if (((((cam->tumble_cnt)) != 0) && ((cam->event.event == 0) || (cam->event.event == 0x20))) || (((cam->effect)) & 2)) {
        knCoreGetAngle(base, base->trans, chr->cam.pos_disp);
    }
    sceVu0CopyVector(cam->old_rot, &rot[0]);
    sceVu0CopyVector(cam->old_chr, &chr_pos);
    if (check == 0) {
        sceVu0CopyVector(cam->old_pos, base->trans);
    } else {
        sceVu0CopyVector(cam->old_pos, &old_pos);
    }
    knCoreSetWState(base, num);
    return 1;
}

asm void knCoreAddVectorXYZ(float* out, float* v1, float* v2) {
        lqc2 $vf3, 0x0($a1);
        lqc2 $vf4, 0x0($a2);
        vadd.xyz $vf5, $vf3, $vf4;
        vmove.w $vf5, $vf0;
        sqc2 $vf5, 0x0($a0);
        jr $ra;
        nop;
}

void knCameraSetBoostAction(VknCamera* cam, Cam* chr) {
    if ((chr->trg_boost == 1) && !(cam->boost_cnt & 0x8000)) {
        cam->boost_cnt = -0x8000;
    }
}

static void knCameraDefaultView(float* rot, VknCamera* cam, Ctrl* chr, float* chr_pos, float* css, float* oss) {
    // DWARF: 0x1169E0
    Sliding_State slide; // r16
    signed int hp_air; // r17
    signed int turn; // r18
    signed int check; // r19
    // Size: 0x30, DWARF: 0x113670
    Cheats* cheats; // r20
    signed int air; // r21
    // DWARF: 0x10FBE7
    Tumble_Type trg_tumble; // r22
    // DWARF: 0x10FBE7
    Tumble_Type tumble_type; // r23

    sceVu0FVECTOR sp; // 0x90(r29)
    sceVu0FVECTOR dis; // 0xA0(r29)
    // f32 unused;// b0
    float rate; // 0xB4(r29)
    float tilt; // 0xB8(r29)
    float power; // 0xBC(r29)
    float sub_rot; // 0xC0(r29)
    float add_z; // 0xC4(r29)

    slide = chr->cam.sliding_state;
    hp_air = chr->cam.hp_air;
    turn = chr->cam.cnt_turn;
    air = chr->cam.cnt_onair;
    trg_tumble = chr->cam.trg_tumble_type;
    tumble_type = chr->cam.tumble_type;
    cheats = &vspenvReplay[0]->cheats;
    check = 0;
    if (slide == essPlant) {
        sceVu0CopyVector(sp, chr->cam.normal_speed);
    } else {
        sceVu0CopyVector(sp, chr->cam.now_speed);
    }
    if ((chr->act.trg_hopup == ettTotter) || (chr->act.trg_jumpup == ettTotter)) {
        cam->hopup_height = chr->cam.pos.pos[1];
    }
    if ((chr->act.pre_state == essOnAir) && (slide != essOnAir) && (trg_tumble != ettTumbleN) && (chr->cam.trg_recovered == ettNormal)) {
        rate = chr->cam.pos.pos[1] - cam->hopup_height;
        if (rate < 0.0f) {
            rate = 0.0f;
        }
        rate /= 250.0f;
        if ((rate > 1.0f)) {
            rate = 1.0f;
        }
        power = 4.0f * rate;
        knCameraSetLandShake(cam, power);
    }
    tilt = knCameraTiltAction(cam, &chr->cam);
    sceVu0CopyVector(rot, chr->cam.rot);

    // Adjusting rotation values to be within -Pi to Pi range.
    rot[0] = ((rot[0] + cam->up_rot) > 3.1415927f) 
        ? ((rot[0] + cam->up_rot) - 6.2831855f)
        : ((rot[0] + cam->up_rot) < -3.1415927f)
        ? 6.2831855f + (rot[0] + cam->up_rot)
        : rot[0] + cam->up_rot;

    // Clamps negative angle to -90
    if (rot[0] < -1.5707964f) {
        rot[0] = -1.5707964f;
    }

    // Adjusting rotation values to be within -Pi to Pi range.
    rot[1] = ((3.1415927f + rot[1]) > 3.1415927f)
        ? (3.1415927f + rot[1]) - 6.2831855f
        : (3.1415927f + rot[1]) < -3.1415927f
        ? 6.2831855f + (3.1415927f + rot[1])
        : 3.1415927f + rot[1];
        
    if (((cam->tumble_cnt == 0) || cam->event.event) && !(cam->effect & 2) && (chr->cam.pos.hit == 1) && (chr->cam.pos.halfpipe == 0)) {
        // Adjusting rotation values to be within -Pi to Pi range.
        rot[0] = ((rot[0] + tilt) > 3.1415927f)
            ? (rot[0] + tilt) - 6.2831855f
            : (rot[0] + tilt) < -3.1415927f
            ? 6.2831855f + (rot[0] + tilt)
            : rot[0] + tilt;
    }
    if (((chr->cam.pos.hit == 1) && (slide != essPlant) && (slide != essGrind) && (chr->cam.pre_tumble_state != essGrind)) || ((chr->cam.pos.hit == 0) && (chr->cam.pre_tumble_state == essPlant)) || tumble_type == essManual) {
        check = 1;
    }
    if (check == 1) {
        if (cheats->mirror == 0) {
            add_z = 0.4f;
        } else {
            add_z = -0.4f;
        }
        if (0x14 < turn) {
            rot[2] = add_z;
        } else if (turn < -0x14) {
            rot[2] = -add_z;
        } else {
            rot[2] = 0.0f;
        }
        cam->old_h = 0.0f;
    } else {
        rot[2] = 0.0f;
        if ((chr->cam.pos.hit == 1) || (chr->act.trg_bonk == 1)) {
            cam->old_h = 0.0f;
        }
        if ((hp_air != 1) && (slide != 5) && (rot[0] > -0.5f)) {
            rot[0] = -0.5f;
        }
        sp[1] = 0.0f;
        sceVu0Normalize(&sp[0], &sp[0]);
        rot[1] = atan2f(sp[0], sp[2]);
        if ((sp[0] == 0.0f) && (sp[2] == 0.0f)) {
            rot[1] = cam->old_rot[1];
        }
        if (slide == essGrind) {
            sub_rot = ((rot[1] - chr->cam.rot[1]) > 3.1415927f)
                ? (rot[1] - chr->cam.rot[1]) - 6.2831855f
                : (rot[1] - chr->cam.rot[1]) < -3.1415927f
                ? 6.2831855f + (rot[1] - chr->cam.rot[1])
                : rot[1] - chr->cam.rot[1];
            if (fabsf(sub_rot) < 0.2f) {
                rot[0] = -chr->cam.rot[0];
                rot[0] = ((rot[0] + cam->up_rot) > 3.1415927f)
                    ? (rot[0] + cam->up_rot) - 6.2831855f
                    : (rot[0] + cam->up_rot) < -3.1415927f
                    ? 6.2831855f + (rot[0] + cam->up_rot)
                    : rot[0] + cam->up_rot;
            }
        }
        if ((hp_air == 0) && (air >= 5)) {
            rate = chr->cam.max_height - cam->old_h;
            rate *= 0.03f;
            if (rate > 1.5f) {
                rate = 1.5f;
            }
            rate = cam->old_h + rate;
            cam->old_h = rate;
            rate = rate / 150.0f;
            if ((rate > 0.7f)) {
                rate = 0.7f;
            }
            rot[0] = rot[0] + (-1.0f * rate);
            if (rot[0] < -1.5707964f) {
                rot[0] = -1.5707964f;
            }
        }
    }
    if ((slide == essOnAir) && (hp_air == 0)) {
        sceVu0SubVector(&dis[0], cam->cam.trans, cam->old_chr);
        dis[3] = sceVu0InnerProduct(&dis[0], &dis[0]);
        if ((dis[3] > 1600.0f)) {
            rate = dis[3] / 1600.0f;
            css[1] = oss[1] = (3.0f + rate) - 1.0f;
            return;
        }
        css[1] = oss[1] = 3.0f;
    }
}

void knCameraHalfPipeView(float* rot, VknCamera* cam, Cam* chr) {
    signed int hp_air; // r16
    Sliding_State slide; // r17
    Ripside side; // r18
    signed int left; // r19
    signed int right; // r20
    Cheats* cheats; // r21
    float tmp; // 0x64(r29)
    static float max = 1.4137167f; // 0x2E7818

    hp_air = chr->hp_air;
    slide = chr->sliding_state;
    side = chr->ripside;
    cheats = &vspenvReplay[0]->cheats;
    if (!cheats->mirror) {
        left = 1;
        right = 2;
    } else {
        left = 2;
        right = 1;
    }
    if ((cam->old_hpair == 1) && (!hp_air) && (slide != essPlant)) {
        cam->add_rip[0] = cam->add_rip[1] = cam->add_rip[2] = 0.0f;
    }
    if ((hp_air == 1) || (slide == essPlant)) {
        tmp = -3.1415927f - cam->add_rip[0];
        tmp *= 0.025f;
        cam->add_rip[0] += tmp;
        if (cam->add_rip[0] < -2.3561945f) {
            cam->add_rip[0] = -2.3561945f;
        }
        if (side == right) {
            tmp = 1.5707964f + cam->add_rip[2];
            tmp *= 0.05f;
            cam->add_rip[2] -= tmp;
            if (cam->add_rip[2] < -1.5707964f) {
                cam->add_rip[2] = -1.5707964f;
            }
        } else if (side == left) {
            tmp = 1.5707964f - cam->add_rip[2];
            tmp *= 0.05f;
            cam->add_rip[2] += tmp;
            if ((cam->add_rip[2] > 1.5707964f)) {
                cam->add_rip[2] = 1.5707964f;
            }
        }
        if (slide != essPlant) {
            rot[0] = (rot[0] + cam->add_rip[0]);
            if (rot[0] < -max)
                rot[0] = -max;
            rot[2] = ((rot[2] + cam->add_rip[2]) > 3.1415927f)
                    ? rot[2] + cam->add_rip[2] - 6.2831855f
                    : (rot[2] + cam->add_rip[2]) < -3.1415927f
                        ? (rot[2] + cam->add_rip[2]) + 6.2831855f
                        : rot[2] + cam->add_rip[2];
        }
    }
    cam->old_hpair = (short) hp_air;
}

static void knCameraRailSlideView(float* rot, VknCamera* cam, Cam* chr) {
    Sliding_State slide; // r16
    float side; // 0x1C(r29)

    slide = chr->sliding_state;
    side = chr->grind_enter_ang;
    if (slide == essGrind) {
        if ((side > 0.0f)) {
            rot[1] = ((rot[1] - 0.25f) > 3.1415927f)
                ?(rot[1] - 0.25f) - 6.2831855f
                : ((rot[1] - 0.25f) < -3.1415927f)
                    ? 6.2831855f + (rot[1] - 0.25f)
                    :rot[1] - 0.25f;

            return;
        }
        rot[1] = ((0.25f + rot[1]) > 3.1415927f)
            ? (0.25f + rot[1]) - 6.2831855f
            : ((0.25f + rot[1]) < -3.1415927f)
                ? 6.2831855f + (0.25f + rot[1])
                : 0.25f + rot[1];
    }
}

static void knCameraSetLandShake(VknCamera* cam, float power) {
    if (!(cam->effect & 4)) {
        cam->effect ^= 4;
        cam->shake_pow = power;
        cam->eff_cnt = 0.0f;
    }
}

static void knCameraLandShake(VknCamera* cam, Ctrl* chr, sceVu0FMATRIX mat) {
    // Size: 0x50, DWARF: 0x113C6A
    Camera* base; // r16
    float power[4]; // 0x20(r29)
    float y; // 0x3C(r29)
    float s; // 0x40(r29)
    float cnt; // 0x44(r29)
    static float rate1 = 0.22439948f; // 0x2E781C // extern
    static float rate2 = 0.62831855f; // 0x2E7820 // extern
    static float rate3 = 0.062831856f; // 0x2E7824 // extern

    base = &cam->cam;
    if (cam->eff_cnt < 1.5707964f) {
        cam->eff_cnt += rate1; //rate1$295);
        cnt = cam->eff_cnt;
    } else if (cam->eff_cnt < 4.712389f) {
        cam->eff_cnt += rate2; //rate2$296);
        cnt = 1.5707964f;
    } else if (cam->eff_cnt < 6.2831855f) {
        cam->eff_cnt += rate3; //rate3$297);
        cnt = cam->eff_cnt;
    }
    if ((cam->eff_cnt > 6.2831855f)) {
        cnt = 0.0f;
        cam->effect ^= 4;
    }

    cnt = cnt > 3.1415927f
        ? cnt - 6.2831855f
        : (cnt < -3.1415927f
            ? 6.2831855f + cnt
            : cnt);
    cnt = fabsf(cnt);
    s = sinf(cnt);
    y = cam->shake_pow * s;
    power[0] = 0.0f;
    power[1] = y;
    power[2] = 0.0f;
    power[3] = 1.0f;
    sceVu0ApplyMatrix(&power[0], mat, &power[0]);
    knCoreAddVectorXYZ(base->trans, base->trans, &power[0]);
    knCoreAddVectorXYZ(base->obj, base->obj, power);
}

static signed int knCameraSpringCheck(Ctrl* chr) {
    if ((chr->cam.sliding_state == essGrind)
        || (chr->cam.bonk_goto == 1)
        || (chr->cam.trg_recovered == 1)
        || ((chr->cam.sliding_state == essPlant) && (chr->act.cnt_plant < 5))) {
        return 0;
    }
    return 1;
}

void knCameraChange(VknCamera* cam, Cam* chr, int num_window, int p_id) {
    signed int num_p; // r17
    unsigned int tmp; // r16
    float rate; // 0x20(r29)
    float dis; // 0x24(r29)
    float def_dis; // 0x28(r29)
    float def_dis2; // 0x2C(r29)

    num_p = vspenvGame->mode.num_player - 1;
    if (num_window == 1) {
        def_dis = -35.0f;
    } else {
        def_dis = -50.0f;
    }
    if ((vgmsysPad[p_id]->trg & 0x100) && (cam->vc_cnt == 0)) {
        if (num_p == 0) {
            vknViewFlg_1P ^= 1;
        } else {
            vknViewFlg_2P[p_id] ^= 1;
        }
        cam->vc_cnt = 0xF;
    }
    if (cam->vc_cnt != 0) {
        if (num_p == 0) {
            if (vknViewFlg_1P == 0) {
                cam->base_dis = (float) (def_dis - (float) cam->vc_cnt);
            } else {
                cam->base_dis = (float) ((def_dis - 15.0f) + (float) cam->vc_cnt);
            }
        } else if (vknViewFlg_2P[p_id] == 0) {
            cam->base_dis = (float) (def_dis - (float) cam->vc_cnt);
        } else {
            cam->base_dis = (float) ((def_dis - 15.0f) + (float) cam->vc_cnt);
        }
        --cam->vc_cnt;
        if (cam->vc_cnt < 0) {
            cam->vc_cnt;
        }
    } else if (num_p == 0) {
        if (vknViewFlg_1P == 0) {
            cam->base_dis = def_dis;
        } else {
            cam->base_dis = (float) (def_dis - 15.0f);
        }
    } else if (vknViewFlg_2P[p_id] == 0) {
        cam->base_dis = def_dis;
    } else {
        cam->base_dis = (float) (def_dis - 15.0f);
    }
    if (chr->hp_air == 1) {
        cam->vc_cnt2 += 1;
        if (0xF < cam->vc_cnt2) {
            cam->vc_cnt2 = 0xF;
        }
    } else {
        --cam->vc_cnt2;
        if (cam->vc_cnt2 < 0) {
            cam->vc_cnt2 = 0;
        }
    }
    rate = 0.75f;
    dis = (cam->base_dis)+ (cam->vc_cnt2 * rate);
    dis = dis - cam->def_dis;
    dis *= 0.5f;
    cam->def_dis = (float) (cam->def_dis + dis);
    if (cam->event.event & 0x20) {
        def_dis2 = cam->event.dis - cam->def_dis;
        rate = (cam->event.dis_cnt >= 0 ? cam->event.dis_cnt : ((cam->event.dis_cnt >> 1) | (cam->event.dis_cnt & 1)) ) * 0.06666f;
        if ((rate > 1.0f)) {
            rate = 1.0f;
        }
        def_dis2 *= rate;
        cam->def_dis += def_dis2;
        cam->event.dis_cnt++;
        if (15 < cam->event.dis_cnt) {
            cam->event.dis_cnt = 0xF;
        }
    } else if (cam->event.dis_cnt & 0x8000) {
        tmp = cam->event.dis_cnt;
        tmp &= 0x7FFF;
        def_dis2 = cam->event.dis - cam->def_dis;
        rate = 0.06666f * (tmp >= 0 ? tmp : (tmp >> 1) | (tmp & 1));
        if (rate > 1.0f) {
            rate = 1.0f;
        }
        def_dis2 *= rate;
        cam->def_dis += def_dis2;
        tmp--;
        cam->event.dis_cnt = tmp;
        cam->event.dis_cnt &= 0x8000;
    }
}

void knCameraTumbleAction(float* chr_pos, VknCamera* cam, Ctrl* chr, float* css, float* oss, signed int* spring) {
    Tumble_Type type; // r16
    Tumble_Type trg_type; // r17
    signed int standup; // r18
    // Size: 0x50
    Camera* base; // r19
    float rate; // 0x58(r29)
    float rate2; // 0x5C(r29)

    base = &cam->cam;
    type = chr->cam.tumble_type;
    trg_type = chr->cam.trg_tumble_type;
    standup = chr->cam.trg_tumble_standup;
    sceVu0CopyVector(chr_pos, chr->cam.pos_disp);
    if (type == ettTumbleN) {
        cam->effect = 2;
        cam->tumble_cnt = 0;
    } else {
        cam->effect &= ~2;
    }
    if ((trg_type != ettNormal) && (type == ettTumbleL) && ((cam->effect) & 1) == 0) {
        cam->effect ^= 1;
        cam->tumble_cnt = 0;
    }
    if (standup == 1) {
        if (((type == ettTumbleL) || (type == ettTumbleN)) && ((cam->effect) & 1) != 0) {
            cam->effect ^= 1;
            cam->tumble_cnt = 1;
            if (type == 5) {
                cam->tumble_cnt = 0;
            }
        }
    } else {
        if ((chr->cam.trg_recovered == 1) && ((cam->tumble_cnt) != 0)) {
            cam->effect = 0;
            cam->tumble_cnt = 0;
        }
    }
    rate = (float) cam->tumble_cnt;
    if (((cam->effect)) & 1) {
        rate2 = 1.0f + (-(rate * rate) / 225.0f);
        if (rate2 < 0.03f) {
            rate2 = 0.03f;
        }
        sceVu0InterVector(chr_pos, chr_pos, cam->old_chr, rate2);
        sceVu0CopyVector(cam->tumble_pos, chr_pos);
        ++cam->tumble_cnt;
        *spring = 0;
    } else if (cam->tumble_cnt != 0) {
        rate = 1.0f + -(((rate - 60.0f) * (rate - 60.0f)) / 3600.0f);
        ++cam->tumble_cnt;
        if ((fabsf(rate) >= 1.0f)) {
            rate = 1.0f;
            cam->tumble_cnt = 0;
            sceVu0CopyVector(chr_pos, chr->cam.pos_disp);
            sceVu0CopyVector(cam->old_chr, chr->cam.pos_disp);
        }
        sceVu0InterVector(chr_pos, chr_pos, cam->tumble_pos, rate);
        *spring = 0;
    }
    if ((cam->effect) & 2) {
        css[0] = css[1] = css[2] = 0.02f;
        oss[0] = oss[1] = oss[2] = 50.0f;
    }
}

static float knCameraTiltAction(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x190, DWARF: 0x11312A
Cam* chr) {
    float sq_tmp; // 0x40(r29)
    float xrot; // 0x40(r29)
    float xz;
    float nor[4]; // 0x20(r29)
    float tmp[4]; // 0x30(r29)

    xz = 0.0f;
    sceVu0CopyVector(nor, chr->pos.normal);
    sceVu0MulVector(tmp, nor, nor);
    sq_tmp = tmp[0] + tmp[2];
    asm("sqrt.s xz, sq_tmp");
    xrot = atan2f(nor[1], xz);
    xrot = -1.5707964f + fabsf(xrot);
    xrot = 0.2f * xrot;
    xrot = xrot - cam->old_tilt;
    xrot = 0.5f * xrot;
    cam->old_tilt = cam->old_tilt + xrot;
}

void knCameraBoostAction(VknCamera* cam, Cam* unused_cam, signed int num) {
    float tmp; // 0x14(r29)
    float cnt; // 0x18(r29)
    float cnt2; // 0x1C(r29)
    static float a = 25.0f; // 0x2E7828
    static float b = 3600.0f; // 0x2E782C

    cnt = (float) (((cam->boost_cnt)) & 0xFF);
    if (cnt < 60.0f) {
        gmsysSetWndBlurPow(num, 0x6E);
    } else if (cnt < 100.0f) {
        tmp = cnt - 60.0f;
        gmsysSetWndBlurPow(num, 110.0f - tmp);
    } else {
        gmsysSetWndBlurPow(num, 0.0f);
    }
    if (cnt <= 5.0f) {
        cam->boost_dis = -10.0f * ((cnt * cnt) / a);
    } else if (cnt <= 60.0f) {
        cam->boost_dis = -10.0f;
    } else {
        cnt2 = cnt - 60.0f;
        cam->boost_dis = -10.0f * (1.0f - ((cnt2 * cnt2) / b));
    }
    cam->boost_cnt++;
    cam->def_dis = (cam->def_dis + cam->boost_dis);
    if (cnt > 120.0f) {
        cam->boost_cnt &= 0x7FFF;
    }
}

static void knCameraInterPol(float* rot, float* r1, float* r2, float* rate) {
    float q[4]; // 0x10(r29)
    float q1[4]; // 0x20(r29)
    float q2[4]; // 0x30(r29)
    float axis[4]; // 0x40(r29)
    float from[4]; // 0x50(r29)
    float to[4]; // 0x60(r29)
    float mat[4][4]; // 0x70(r29)

    sceVu0CopyVector(from, r1);
    sceVu0CopyVector(to, r2);

    sceVu0UnitMatrix(mat);
    if (from[2] != to[2]) {
        if (from[2] < 0.0f) {
            from[2] += 6.2831855f;
        }

        if (to[2] < 0.0f) {
            to[2] += 6.2831855f;
        }

        axis[0] = 0.0f; axis[1] = 0.0f; axis[2] = 1.0f; axis[3] = 1.0f;
        knAngAxisToQuat(q1, axis, from[2]);
        knAngAxisToQuat(q2, axis, to[2]);
        knQuatSlerp(q, q1, q2, rate[2]);
        rot[2] = knQuatToAngAxis(axis, q);
    } else {
        rot[2] = to[2];
    }
    sceVu0RotMatrixZ(mat, mat, rot[2]);
    if (from[0] != to[0]) {
        if (from[0] < 0.0f) {
            from[0] += 6.2831855f;
        }

        if (to[0] < 0.0f) {
            to[0] += 6.2831855f;
        }

        axis[0] = 1.0f; axis[1] = 0.0f; axis[2] = 0.0f; axis[3] = 1.0f;
        sceVu0ApplyMatrix(axis, mat, axis);
        knAngAxisToQuat(q1, axis, from[0]);
        knAngAxisToQuat(q2, axis, to[0]);
        knQuatSlerp(q, q1, q2, rate[0]);
        rot[0] = knQuatToAngAxis(axis, q);
    } else {
        rot[0] = to[0];
    }
    sceVu0RotMatrixX(mat, mat, rot[0]);
    if (from[1] != to[1]) {
        if (from[1] < 0.0f) {
            from[1] += 6.2831855f;
        }

        if (to[1] < 0.0f) {
            to[1] += 6.2831855f;
        }

        axis[0] = 0.0f; axis[1] = 1.0f; axis[2] = 0.0f; axis[3] = 1.0f;
        sceVu0ApplyMatrix(axis, mat, axis);
        knAngAxisToQuat(q1, axis, from[1]);
        knAngAxisToQuat(q2, axis, to[1]);
        knQuatSlerp(q, q1, q2, rate[1]);
        rot[1] = knQuatToAngAxis(axis, q);
    } else {
        rot[1] = to[1];
    }
}

void knCalcMain(float* new_dst /* r16 */, register float* src /* r5 */, register float* dst /* r6 */, register float* v /* r7 */, register float* ss /* r8 */, register float* dd /* r9 */) {
    static float dt = 0.1f; // 0x2E7830
    register float temp_float = dt;

    asm (
        lqc2  $vf3, 0(src);
        lqc2  $vf4, 0(dst);
        lqc2  $vf5, 0(v);
        lqc2  $vf6, 0(ss);
        lqc2  $vf7, 0(dd);
        li    $v0,  10;
        mfc1  $v1,  temp_float;
        qmtc2 $v1,  $vf2;
        loop:
            vsub.xyz  $vf10, $vf4,  $vf3;
            vmul.xyz  $vf12, $vf10, $vf10;
            vaddy.x   $vf12, $vf12, $vf12y;
            vaddz.x   $vf12, $vf12, $vf12z;
            vdiv      $Q,    $vf0w, $vf12x;
            vmul.xyz  $vf11, $vf10, $vf6;
            vmul.xyz  $vf13, $vf5,  $vf10;
            vaddy.x   $vf13, $vf13, $vf13y;
            vaddz.x   $vf13, $vf13, $vf13z;
            vmulx.xyz $vf15, $vf10, $vf13x;
            vmul.xyz  $vf15, $vf15, $vf7;
            vwaitq;
            vmulq.xyz $vf15, $vf15, $Q;
            vsub.xyz  $vf20, $vf11, $vf15;
            vmulx.xyz $vf20, $vf20, $vf2x;
            vadd.xyz  $vf5,  $vf5,  $vf20;
            vmulx.xyz $vf5,  $vf5,  $vf2x;
            vadd.xyz  $vf3,  $vf3,  $vf5;
        addiu $v0, -1;
        bnez  $v0, loop;
        // nop
    
        sqc2 $vf3, 0(src);
        sqc2 $vf5, 0(v);
    );
    sceVu0CopyVector(new_dst);
    new_dst[3] = 1.0f;
}

void knCameraSetFixRotation(float* rot, s32 id) {
    // Size: 0x20, DWARF: 0x1100C9
    Event* ev; // r16

    ev = &vknCamera[id].event;
    if ((ev->event & 8) == 0) {
        sceVu0CopyVector(ev, rot);
        ev->event ^= 8;
    }
}

void knCameraSetDis(float dis, s32 id) {
    // Size: 0x20, DWARF: 0x1100C9
    Event* ev; // r16

    ev = &vknCamera[id].event;
    if ((ev->event & 0x20) == 0) {
        ev->dis_cnt = 0;
        ev->dis = dis;
        ev->event ^= 0x20;
    }
}

void knCameraEndDis(s32 id) {
    // Size: 0x20, DWARF: 0x1100C9
    Event* ev; // r16

    ev = &vknCamera[id].event;
    ev->event &= ~0x20;
    ev->dis_cnt |= 0x8000;
}

void knCameraEventAllReset(s32 id) {
    // Size: 0x20, DWARF: 0x1100C9
    Event* ev = &vknCamera[id].event; // r16
    ev->event = 0;
}

void knFinishCamera(Ctrl* chr, u32 frame, s32 num) {
    // Size: 0x50, DWARF: 0x113C6A
    Camera* base; // r16
    // Size: 0x30, DWARF: 0x113670
    Cheats* cheats; // r17
    signed int check; // r18
    // Size: 0x130, DWARF: 0x10FC5F
    VknCamera* cam; // r19
    // Size: 0x60, DWARF: 0x1161D3
    Cross cross; // 0x50(r29)
    float mat[4][4]; // 0xB0(r29)
    float dis[4]; // 0xF0(r29)
    float height; // 0x100(r29)
    float len; // 0x104(r29)
    float rate; // 0x108(r29)
    float len_rate; // 0x10C(r29)
    // float tmp[4]; // 0x110, not in DWARF
    static float angy = 0.3f; // 0x2E7834
    static float f = 60.0f; // 0x2E7838

    cam = &vknCamera[num];
    base = &vknCamera[num].cam;
    cheats = &vspenvReplay[0]->cheats; // + 0x2DC98;
    height = -10.0f;
    len_rate = -15.0f;
    (void)check;
    if (cheats->big_head == 1) {
        len_rate = -18.0f;
    }
    if (cheats->kids == 1) {
        height *= 0.4f;
    } else if (cheats->big_head == 1) {
        height *= 1.2f;
    }

    if ((frame >= 0 ? frame : (((u32) frame >> 1) | (frame & 1))) < 60.0f) {

        rate = (f - (frame >= 0 ? frame : (((u32) frame >> 1) | (frame & 1)))) / f;
        gmsysSetWndBlurPow(num, 128.0f * rate);
        len = -30.0f + ((30.0f + len_rate) * (1.0f - rate));
    } else {
        len = len_rate;
    }
    sceVu0CopyVector(base, chr->cam.rot);

    base->rot[1] = (base->rot[1] - angy/*$553*/) > 3.1415927f
        ? (base->rot[1] - angy/*$553*/) - 6.2831855f
        : (base->rot[1] - angy/*$553*/) < -3.1415927f
            ? 6.2831855f + (base->rot[1] - angy)
            : base->rot[1] - angy;
    base->rot[0] = (f32) -base->rot[0];

    base->rot[0] = (base->rot[0] - 0.3f) > 3.1415927f
        ? (base->rot[0] - 0.3f) - 6.2831855f
        : (base->rot[0] - 0.3f) < -3.1415927f
            ? 6.2831855f + (base->rot[0] - 0.3f)
            : base->rot[0] - 0.3f;
    if (chr->cam.sliding_state == essTumble) {
        base->rot[2] = 0.0f;
    }
    sceVu0UnitMatrix(&mat);
    sceVu0RotMatrixX(&mat, &mat, base->rot[0]);
    sceVu0RotMatrixY(&mat, &mat, base->rot[1]);
    dis[0] = 0.0f;
    dis[1] = height;
    dis[2] = len;
    dis[3] = 1.0f;
    sceVu0ApplyMatrix(&dis[0], &mat, &dis[0]);
    sceVu0CopyVector(base->obj, chr->cam.pos_disp);
    sceVu0AddVector(base->trans, base->obj, &dis[0]);
    base->trans[3] = base->obj[3] = 1.0f;
    sceVu0CopyVector(base->up, chr->disp_pole);
    sceVu0ScaleVector(base->up, base->up, -1.0f);
    base->up[3] = -1.0f;
    check = knCoreGetCourseHit(&cross, base->obj, base->trans);
    if (check) {
        sceVu0CopyVector(base->trans, &cross.point);
    }
    knCoreSetWState(base, num);
    vspSystemMatrix[num].scr_info.screen_z = 400.0f;
}

static void knCameraKeepCourse(// Size: 0x130, DWARF: 0x10FC5F
VknCamera* cam, // Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, float* chr_pos, float* rot) {
    // Size: 0x50, DWARF: 0x113C6A
    Camera* base = &cam->cam; // r16
    signed int check[2] = { 0, 0 }; // 0x208(r29)
    signed int* unused1 = check;
    float P1[2][4]; // 0x60(r29)
    float P2[2][4]; // 0x80(r29)
    // Size: 0x60, DWARF: 0x1161D3
    Cross cross[2]; // 0xA0(r29)
    float a1; // 0x214(r29)
    float a2; // 0x218(r29)
    float add_x; // 0x21C(r29)
    float add_y; // 0x220(r29)
    float p1[4]; // 0x160(r29)
    float p2[4]; // 0x170(r29)
    float v1[4]; // 0x180(r29)
    float v2[4]; // 0x190(r29)
    float dis[4]; // 0x1A0(r29)
    float tmp[4]; // 0x1B0(r29)
    float mat[4][4]; // 0x1C0(r29)
    // DWARF: 0x10FBE7
    Tumble_Type tumble_type; // r18
    // DWARF: 0x1169E0
    Sliding_State slide; // r19
    // DWARF: 0x1169E0
    Sliding_State tumble_slide; // r20
    float side; // 0x224(r29)

    (void)unused1;
    tumble_type = chr->cam.tumble_type;
    slide = chr->cam.sliding_state;
    tumble_slide = chr->cam.pre_tumble_state;
    side = chr->cam.grind_enter_ang;

    sceVu0CopyVector(p1, cam->old_pos);
    sceVu0CopyVector(p2, base->trans);

    sceVu0SubVector(v1, chr_pos, cam->old_pos);
    sceVu0SubVector(v2, chr_pos, base->trans);
    v1[1] = v2[1] = 0.0f;
    sceVu0Normalize(v1, v1);
    sceVu0Normalize(v2, v2);
    add_y = sceVu0InnerProduct(v1, v2);
    sceVu0OuterProduct(tmp, v1, v2);
    add_y = acosf(add_y);
    if (tmp[1] > 0.0f) {
        add_y = -add_y;
    }

    if ((slide == essGrind) || (tumble_slide == essGrind)) {
        a1 = 0.0f;
        knCoreRotMatrix(mat, rot);
        dis[0] = cam->def_dis; dis[1] = 0.0f; dis[2] = 0.0f; dis[3] = 1.0f;
        sceVu0ApplyMatrix(tmp, mat, dis);

        sceVu0AddVector(p1, base->trans, tmp);
        sceVu0SubVector(p2, base->trans, tmp);

        sceVu0CopyVector(P1[0], chr_pos);
        sceVu0CopyVector(P2[0], p1);
        sceVu0CopyVector(P1[1], chr_pos);
        sceVu0CopyVector(P2[1], p2);

        knCoreGetCourseHit2(check, cross, P1, P2, base->trans, 2);
        if (check[0] > 0) {
            a1 = knCoreGetDifAngY(base->trans, cross[0].point, p1);
        } else {

            if (check[1] > 0) {
                a1 = knCoreGetDifAngY(base->trans, cross[1].point, p2);
            }
        }

        if (a1 != 0.0f) {
            if (side > 0.0f) {
                if (a1 < 0.0f) {
                    a1 *= 0.5f;
                }
            } else {

                if (a1 > 0.0f) {
                    a1 *= 0.5f;
                }
            }

            rot[1] = ((rot[1] + a1) > 3.1415927f) ? ((rot[1] + a1) - 6.2831855f) : (((rot[1] + a1) < -3.1415927f) ? (6.2831855f + (rot[1] + a1)) : (rot[1] + a1));
        }
    } else {

        dis[0] = 0.0f; dis[1] = 0.0f; dis[2] = cam->def_dis - 10.0f; dis[3] = 1.0f;
        sceVu0CopyVector(tmp, rot);
        tmp[1] = ((tmp[1] + (0.97f * add_y)) > 3.1415927f) ? ((tmp[1] + (0.97f * add_y)) - 6.2831855f) : (((tmp[1] + (0.97f * add_y)) < -3.1415927f) ? (6.2831855f + (tmp[1] + (0.97f * add_y))) : (tmp[1] + (0.97f * add_y)));

        knCoreRotMatrix(mat, tmp);
        sceVu0ApplyMatrix(tmp, mat, dis);
        knCoreAddVectorXYZ(p2, chr_pos, tmp);

        if (chr->cam.pos.hit == 0) {
            sceVu0CopyVector(P1[0], chr_pos);
            sceVu0CopyVector(P2[0], base->trans);
        } else {
            sceVu0CopyVector(P1[0], cam->old_pos);
            sceVu0CopyVector(P2[0], base->trans);
        }

        sceVu0CopyVector(P1[1], p1);
        sceVu0CopyVector(P2[1], p2);

        knCoreGetCourseHit2(check, cross, P1, P2, base->trans, 2);

        if (check[0] > 0) {
            if (check[0] != 3) {
                a1 = sceVu0InnerProduct(base->up, cross[0].normal);
                a1 = acosf(a1);
            } else {

                a1 = 1.5707964f;
            }

            sceVu0CopyVector(v1, chr->cam.now_speed);
            sceVu0Normalize(v1, v1);
            if ((v1[0] == 0.0f) && (v1[1] == 0.0f) && (v1[2] == 0.0f)) {
                sceVu0OuterProduct(v1, base->up, chr->cam.pos.normal);
                a2 = sceVu0InnerProduct(base->up, v1);
                a2 = acosf(a2);
            } else {

                a2 = sceVu0InnerProduct(base->up, v1);
                a2 = acosf(a2);
            }

            a1 = a1 - a2;
            if (a1 < -0.785398f) {
                a1 = -0.785398f;
            }

            rot[0] = ((rot[0] - a1) > 3.1415927f) ? ((rot[0] - a1) - 6.2831855f) : (((rot[0] - a1) < -3.1415927f) ? (6.2831855f + (rot[0] - a1)) : (rot[0] - a1));

            if ((tumble_type == ettTumbleF) || (chr->act.cnt_backward != 0)) {
                sceVu0CopyVector(v1, cross[0].normal);
                sceVu0CopyVector(v2, chr->cam.now_speed);
                v1[1] = v2[1] = 0.0f;
                sceVu0Normalize(v1, v1);
                sceVu0Normalize(v2, v2);

                a1 = sceVu0InnerProduct(v1, v2);
                sceVu0OuterProduct(tmp, v1, v2);
                a1 = acosf(a1);
                if (tmp[1] > 0.0f) {
                    a1 = -a1;
                }

                rot[1] = ((rot[1] + a1) > 3.1415927f) ? ((rot[1] + a1) - 6.2831855f) : (((rot[1] + a1) < -3.1415927f) ? (6.2831855f + (rot[1] + a1)) : (rot[1] + a1));

                if (a1 != 0.0f) {
                    add_x = ((2.0f * chr->cam.rot[0]) * a1) / 3.1415927f;
                    add_x = fabsf(add_x);
                    rot[0] = ((rot[0] - add_x) > 3.1415927f) ? ((rot[0] - add_x) - 6.2831855f) : (((rot[0] - add_x) < -3.1415927f) ? (6.2831855f + (rot[0] - add_x)) : (rot[0] - add_x));
                }
            } else {

                rot[1] = ((rot[1] + add_y) > 3.1415927f) ? ((rot[1] + add_y) - 6.2831855f) : (((rot[1] + add_y) < -3.1415927f) ? (6.2831855f + (rot[1] + add_y)) : (rot[1] + add_y));
                if (add_y != 0.0f) {
                    add_x = ((2.0f * chr->cam.rot[0]) * add_y) / 3.1415927f;
                    add_x = fabsf(add_x);
                    rot[0] = ((rot[0] - add_x) > 3.1415927f) ? ((rot[0] - add_x) - 6.2831855f) : (((rot[0] - add_x) < -3.1415927f) ? (6.2831855f + (rot[0] - add_x)) : (rot[0] - add_x));
                }
            }
        } else {

            if (check[1] > 0) {
                rot[1] = ((rot[1] + add_y) > 3.1415927f) ? ((rot[1] + add_y) - 6.2831855f) : (((rot[1] + add_y) < -3.1415927f) ? (6.2831855f + (rot[1] + add_y)) : (rot[1] + add_y));
                if (add_y != 0.0f) {
                    add_x = ((2.0f * chr->cam.rot[0]) * add_y) / 3.1415927f;
                    add_x = fabsf(add_x);
                    rot[0] = ((rot[0] - add_x) > 3.1415927f) ? ((rot[0] - add_x) - 6.2831855f) : (((rot[0] - add_x) < -3.1415927f) ? (6.2831855f + (rot[0] - add_x)) : (rot[0] - add_x));
                }
            }
        }

        if (rot[0] < -1.5707964f) {
            rot[0] = -1.5707964f;
        }
    }
}

static signed int knCameraKeepCourse2b(// Size: 0x50, DWARF: 0x113C6A
Camera* base, // Size: 0x2C00, DWARF: 0x10F6C0
Ctrl* chr, signed int* spring) {
    // Size: 0x60, DWARF: 0x1161D3
    Cross cross; // 0x20(r29)
    signed int check; // r16

    if (chr->cam.tumble_type == ettTumbleN) {
        return 0;
    }
    check = knCoreGetBaseHit(&cross, chr->cam.pos_disp, base->trans);
    if (check == 1) {
        sceVu0CopyVector(base->trans, cross.point);
        sceVu0ScaleVector(cross.normal, cross.normal, 5.0f);
        knCoreAddVectorXYZ(base->trans, base->trans, cross.normal);
        *spring = 0;
        return 1;
    }
    return 0;
}

static void knAngAxisToQuat(float* q, float* axis, float ang) {
    float a; // 0x18(r29)
    float sa; // 0x1C(r29)

    a = 0.5f * ang;
    sa = sinf(a);

    sceVu0ScaleVectorXYZ(q, axis, sa);
    q[3] = cosf(a);
}

static float knQuatToAngAxis(float* axis, float* q) {
    float axis2[4]; // 0x10(r29)
    float ang; // 0x20(r29)
    float scale; // 0x24(r29)

    ang = 2.0f * acosf(q[3]);

    scale = sceVu0InnerProduct(q, q);
    sceVu0DivVectorXYZ(axis2, q, scale);
    axis2[3] = ang;

    if (((axis[0] > 0.0f) && (axis2[0] < 0.0f)) || ((axis[0] < 0.0f) && (axis2[0] > 0.0f))
        || ((axis[1] > 0.0f) && (axis2[1] < 0.0f)) || ((axis[1] < 0.0f) && (axis2[1] > 0.0f))
        || ((axis[2] > 0.0f) && (axis2[2] < 0.0f)) || ((axis[2] < 0.0f) && (axis2[2] > 0.0f))) {
        ang = -ang;
    }

    ang = (ang > 3.1415927f) ? (ang - 6.2831855f) : ((ang < -3.1415927f) ? (6.2831855f + ang) : ang);
    return ang;
}

static void knQuatSlerp(float* q, float* q1, float* q2, float t) {
    float theta;
    float s;
    float tmp[4]; // 0x50(r29)
    float qn[4]; // 0x60(r29)
    float scale[4] = { 1.0f - t, t, 0.0f, 1.0f }; // 0x70(r29)
    float* unused1 = scale;

    sceVu0MulVector(tmp, q1, q2);
    theta = tmp[0] + tmp[1] + tmp[2] + tmp[3];

    if (theta < 0.0f) {
        theta = -theta;
        sceVu0ScaleVector(qn, q2, -1.0f);
    } else {
        sceVu0CopyVector(qn, q2);
    }

    if ((1.0f - theta) > 1e-08f) {
        theta = acosf(theta);
        s = 1.0f / sinf(theta);
        scale[0] = s * sinf(theta * scale[0]);
        scale[1] = s * sinf(theta * scale[1]);
    }

    asm (
        la v1, qn; la a0, scale;
        lqc2 $vf3, 0(q1);
        lqc2 $vf4, 0(v1);
        lqc2 $vf5, 0(a0);
        vmulx.xyzw $vf10, $vf3, $vf5x;
        vmuly.xyzw $vf11, $vf4, $vf5y;
        vadd.xyzw $vf12, $vf10, $vf11;
        sqc2 $vf12, 0(q);
    );
}
