// spinit.c context
// Last updated 4/18/2025
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

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
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

// Spinit.c structs

// Size: 0x8, DWARF: 0xA9B29
typedef struct Clock
{
    unsigned char stat; // Offset: 0x0, DWARF: 0xA9B45
    unsigned char second; // Offset: 0x1, DWARF: 0xA9B66
    unsigned char minute; // Offset: 0x2, DWARF: 0xA9B89
    unsigned char hour; // Offset: 0x3, DWARF: 0xA9BAC
    unsigned char pad; // Offset: 0x4, DWARF: 0xA9BCD
    unsigned char day; // Offset: 0x5, DWARF: 0xA9BED
    unsigned char month; // Offset: 0x6, DWARF: 0xA9C0D
    unsigned char year; // Offset: 0x7, DWARF: 0xA9C2F
} Clock; // 0x28(r29)

// Size: 0x8, DWARF: 0xA8502
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0xA851D
    signed int bgm; // Offset: 0x4, DWARF: 0xA853C
} Volume;

// Size: 0x48, DWARF: 0xA8EA0
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0xA8EBC
    signed int disable; // Offset: 0x40, DWARF: 0xA8EE0
    signed int random; // Offset: 0x44, DWARF: 0xA8F04
} Bgm;

// Size: 0x18, DWARF: 0xA9DE9
typedef struct Clock2
{
    signed int year; // Offset: 0x0, DWARF: 0xA9E05
    signed int month; // Offset: 0x4, DWARF: 0xA9E26
    signed int day; // Offset: 0x8, DWARF: 0xA9E48
    signed int hour; // Offset: 0xC, DWARF: 0xA9E68
    signed int minute; // Offset: 0x10, DWARF: 0xA9E89
    signed int second; // Offset: 0x14, DWARF: 0xA9EAC
} Clock2;

// Size: 0x24, DWARF: 0xA80F3
typedef struct KeyConfig
{
    signed int vibration; // Offset: 0x0, DWARF: 0xA810E
    signed int spin_l; // Offset: 0x4, DWARF: 0xA8134
    signed int spin_r; // Offset: 0x8, DWARF: 0xA8157
    signed int stance; // Offset: 0xC, DWARF: 0xA817A
    signed int revert; // Offset: 0x10, DWARF: 0xA819D
    signed int grind; // Offset: 0x14, DWARF: 0xA81C0
    signed int grab; // Offset: 0x18, DWARF: 0xA81E2
    signed int jump; // Offset: 0x1C, DWARF: 0xA8203
    signed int flip; // Offset: 0x20, DWARF: 0xA8224
} KeyConfig;

// Size: 0x8, DWARF: 0xA83F1
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0xA840C
    signed char lh; // Offset: 0x2, DWARF: 0xA842C
    signed char lv; // Offset: 0x3, DWARF: 0xA844B
    signed int analog; // Offset: 0x4, DWARF: 0xA846A
} PadData;

// Size: 0x8, DWARF: 0xA9D5C
typedef struct Course
{
    unsigned long gap; // Offset: 0x0, DWARF: 0xA9D78
} Course;

// Size: 0x4, DWARF: 0xA9998
typedef struct Course2
{
    signed int no; // Offset: 0x0, DWARF: 0xA99B4
} Course2;

// Size: 0x38, DWARF: 0xAA04E
typedef struct File
{
    // Size: 0x18, DWARF: 0xA9DE9
    Clock2 clock; // Offset: 0x0, DWARF: 0xAA06A
    char name[32]; // Offset: 0x18, DWARF: 0xAA08E
} File; 

// Size: 0x1C, DWARF: 0xA933E
typedef struct CharacterParameters
{
    signed int ollie; // Offset: 0x0, DWARF: 0xA935A
    signed int spin; // Offset: 0x4, DWARF: 0xA937C
    signed int speed; // Offset: 0x8, DWARF: 0xA939D
    signed int landing; // Offset: 0xC, DWARF: 0xA93BF
    signed int balance; // Offset: 0x10, DWARF: 0xA93E3
    signed int stability; // Offset: 0x14, DWARF: 0xA9407
    signed int stance; // Offset: 0x18, DWARF: 0xA942D
} CharacterParameters;

// Size: 0x74, DWARF: 0xA94E9
typedef struct Character
{
    signed int secret; // Offset: 0x0, DWARF: 0xA9505
    unsigned int board; // Offset: 0x4, DWARF: 0xA9528
    unsigned int course; // Offset: 0x8, DWARF: 0xA954A
    signed int rem_point; // Offset: 0xC, DWARF: 0xA956D
    signed int old_brd_no; // Offset: 0x10, DWARF: 0xA9593
    signed int old_wear_no; // Offset: 0x14, DWARF: 0xA95BA
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0xA95E2
    signed int soft[8]; // Offset: 0x38, DWARF: 0xA960B
    // Size: 0x1C, DWARF: 0xA933E
    CharacterParameters parameter; // Offset: 0x58, DWARF: 0xA962E
} Character;

// Size: 0xEC, DWARF: 0xA8F4F
typedef struct CreateCharacter //: E:\tam\ps2\sppbx\main.c
{
    // Size: 0x74, DWARF: 0xA94E9
    Character character; // Offset: 0x0, DWARF: 0xA8F6B
    // Size: 0x1C, DWARF: 0xA933E
    CharacterParameters init_param; // Offset: 0x74, DWARF: 0xA8F93
    // Size: 0x18, DWARF: 0xA9DE9
    Clock2 clock; // Offset: 0x90, DWARF: 0xA8FBC
    char name[16]; // Offset: 0xA8, DWARF: 0xA8FE0
    signed int age; // Offset: 0xB8, DWARF: 0xA9003
    signed int sex; // Offset: 0xBC, DWARF: 0xA9023
    signed int face; // Offset: 0xC0, DWARF: 0xA9043
    signed int hair; // Offset: 0xC4, DWARF: 0xA9064
    signed int hair_color; // Offset: 0xC8, DWARF: 0xA9085
    signed int body; // Offset: 0xCC, DWARF: 0xA90AC
    signed int body_color; // Offset: 0xD0, DWARF: 0xA90CD
    signed int pants; // Offset: 0xD4, DWARF: 0xA90F4
    signed int pants_color; // Offset: 0xD8, DWARF: 0xA9116
    signed int glove; // Offset: 0xDC, DWARF: 0xA913E
    signed int boots; // Offset: 0xE0, DWARF: 0xA9160
    signed int board_type; // Offset: 0xE4, DWARF: 0xA9182
    signed int trick_type; // Offset: 0xE8, DWARF: 0xA91A9
} CreateCharacter;

// Size: 0x10, DWARF: 0xA96A5
typedef struct VsptblBoardParam
{
    signed int speed; // Offset: 0x0, DWARF: 0xA96C1
    signed int stability; // Offset: 0x4, DWARF: 0xA96E3
    signed int balance; // Offset: 0x8, DWARF: 0xA9709
    signed int turning; // Offset: 0xC, DWARF: 0xA972D
} VsptblBoardParam;

// Size: 0xEF8, DWARF: 0xA8295
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0xA94E9
    Character character[12]; // Offset: 0x0, DWARF: 0xA82B0
    // Size: 0xEC, DWARF: 0xA8F4F
    CreateCharacter create_character[10]; // Offset: 0x570, DWARF: 0xA82D8
    // Size: 0x8, DWARF: 0xA9D5C
    Course course[8]; // Offset: 0xEA8, DWARF: 0xA8307
    signed int tour_round; // Offset: 0xEE8, DWARF: 0xA832C
    signed int old_char; // Offset: 0xEEC, DWARF: 0xA8353
    signed int first_clear; // Offset: 0xEF0, DWARF: 0xA8378
} VspenvSecret;

// Size: 0x30, DWARF: 0xA87A8
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0xA87C3
    signed int always_sp; // Offset: 0x4, DWARF: 0xA87E4
    signed int perfect_b; // Offset: 0x8, DWARF: 0xA880A
    signed int super_spin; // Offset: 0xC, DWARF: 0xA8830
    signed int half_g; // Offset: 0x10, DWARF: 0xA8857
    signed int fast_motion; // Offset: 0x14, DWARF: 0xA887A
    signed int super_speed; // Offset: 0x18, DWARF: 0xA88A2
    signed int big_head; // Offset: 0x1C, DWARF: 0xA88CA
    signed int metallic; // Offset: 0x20, DWARF: 0xA88EF
    signed int mirror; // Offset: 0x24, DWARF: 0xA8914
    signed int replay_view; // Offset: 0x28, DWARF: 0xA8937
    signed int partition; // Offset: 0x2C, DWARF: 0xA895F
} Cheats;

// Size: 0x114, DWARF: 0xA8BCC
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0xA80F3
    KeyConfig key_config[2]; // Offset: 0x0, DWARF: 0xA8BE8
    // Size: 0x30, DWARF: 0xA87A8
    Cheats enable; // Offset: 0x48, DWARF: 0xA8C11
    // Size: 0x30, DWARF: 0xA87A8
    Cheats cheats; // Offset: 0x78, DWARF: 0xA8C36
    // Size: 0x8, DWARF: 0xA8502
    Volume volume; // Offset: 0xA8, DWARF: 0xA8C5B
    char name[16]; // Offset: 0xB0, DWARF: 0xA8C80
    signed int divide; // Offset: 0xC0, DWARF: 0xA8CA3
    signed int tutorial; // Offset: 0xC4, DWARF: 0xA8CC6
    // Size: 0x48, DWARF: 0xA8EA0
    Bgm bgm; // Offset: 0xC8, DWARF: 0xA8CEB
    unsigned int movie; // Offset: 0x110, DWARF: 0xA8D0D
} VspenvOption;

// Size: 0x2DCEC, DWARF: 0xA8560
typedef struct VspenvReplay
{
    // Size: 0x38, DWARF: 0xAA04E
    File file; // Offset: 0x0, DWARF: 0xA857B
    signed int pid; // Offset: 0x38, DWARF: 0xA859E
    signed int num_frame; // Offset: 0x3C, DWARF: 0xA85BE
    unsigned int game_time; // Offset: 0x40, DWARF: 0xA85E4
    signed int endrun_frame; // Offset: 0x44, DWARF: 0xA860A
    // Size: 0x8, DWARF: 0xA83F1
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0xA8633
    // Size: 0x24, DWARF: 0xA80F3
    KeyConfig key; // Offset: 0x2DB88, DWARF: 0xA865A
    // Size: 0xEC, DWARF: 0xA8F4F
    CreateCharacter character; // Offset: 0x2DBAC, DWARF: 0xA867C
    // Size: 0x30, DWARF: 0xA87A8
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0xA86A4
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0xA86C9
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0xA86EC
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0xA870F
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0xA8733
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0xA8756
    // Size: 0x10, DWARF: 0xA96A5
    VsptblBoardParam brd_param; // Offset: 0x2DCDC, DWARF: 0xA877C
} VspenvReplay;

// Size: 0x20, DWARF: 0xA8A83
typedef struct VsptblFreeStyleRanking
{
    signed int chr_no; // Offset: 0x0, DWARF: 0xA8A9E
    unsigned long score; // Offset: 0x8, DWARF: 0xA8AC1
    char name[16]; // Offset: 0x10, DWARF: 0xA8AE3
} VsptblFreeStyleRanking;

// Size: 0x4, DWARF: 0xA7FDA
typedef struct VsptblBestTime
{
    unsigned int time; // Offset: 0x0, DWARF: 0xA7FF5
} VsptblBestTime;

// Size: 0xA0, DWARF: 0xA8989
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0xA9998
    Course2 course; // Offset: 0x0, DWARF: 0xA89A4
    // Size: 0x3C, DWARF: 0xA97C3
    struct
    {
        signed int no; // Offset: 0x0, DWARF: 0xA97DF
        signed int player; // Offset: 0x4, DWARF: 0xA97FE
        signed int wear; // Offset: 0x8, DWARF: 0xA9821
        signed int board; // Offset: 0xC, DWARF: 0xA9842
        // Size: 0x1C, DWARF: 0xA933E
        CharacterParameters chr_param; // Offset: 0x10, DWARF: 0xA9864
        // Size: 0x10, DWARF: 0xA96A5
        VsptblBoardParam brd_param; // Offset: 0x2C, DWARF: 0xA988C
    } character[2]; // Offset: 0x4, DWARF: 0xA89C9
    // Size: 0x18, DWARF: 0xA9A4B
    struct //: E:\tam\ps2\sppbx\main.c
    {
        signed int num_player; // Offset: 0x0, DWARF: 0xA9A67
        signed int game_mode; // Offset: 0x4, DWARF: 0xA9A8E
        signed int match_rule; // Offset: 0x8, DWARF: 0xA9AB4
        signed int divide; // Offset: 0xC, DWARF: 0xA9ADB
        signed int handicap[2]; // Offset: 0x10, DWARF: 0xA9AFE
    } mode; // Offset: 0x7C, DWARF: 0xA89F1
    signed int language; // Offset: 0x94, DWARF: 0xA8A14
    signed int ending; // Offset: 0x98, DWARF: 0xA8A39
    signed int bgm_no; // Offset: 0x9C, DWARF: 0xA8A5C
} VspenvGame;

// Size: 0x1668, DWARF: 0xA801A
typedef struct MemCard
{
    // Size: 0x38, DWARF: 0xAA04E
    File file; // Offset: 0x0, DWARF: 0xA8035
    // Size: 0x20, DWARF: 0xA8A83
    VsptblFreeStyleRanking record[8][6]; // Offset: 0x38, DWARF: 0xA8058
    // Size: 0x4, DWARF: 0xA7FDA
    VsptblBestTime best_time[8]; // Offset: 0x638, DWARF: 0xA807D
    // Size: 0x114, DWARF: 0xA8BCC
    VspenvOption option; // Offset: 0x658, DWARF: 0xA80A5
    // Size: 0xEF8, DWARF: 0xA8295
    VspenvSecret secret; // Offset: 0x770, DWARF: 0xA80CA
} MemCard;

// Size: 0x5D0E0, DWARF: 0xA8DCB
typedef struct VspenvEnv
{
    // Size: 0xA0, DWARF: 0xA8989
    VspenvGame game; // Offset: 0x0, DWARF: 0xA8DE7
    // Size: 0x1668, DWARF: 0xA801A
    MemCard mc; // Offset: 0xA0, DWARF: 0xA8E0A
    // Size: 0x2DCEC, DWARF: 0xA8560
    VspenvReplay replay[2]; // Offset: 0x1708, DWARF: 0xA8E2B
} VspenvEnv;

// Size: 0x20, DWARF: 0xA91D4
typedef struct VspenvDemo
{
    unsigned long time_out; // Offset: 0x0, DWARF: 0xA91F0
    unsigned long play_time_out; // Offset: 0x8, DWARF: 0xA9215
    signed int usr_end; // Offset: 0x10, DWARF: 0xA923F
    signed int to; // Offset: 0x14, DWARF: 0xA9263
    signed int play_to; // Offset: 0x18, DWARF: 0xA9282
    signed int demo; // Offset: 0x1C, DWARF: 0xA92A6
} VspenvDemo;

char* vsptblCharacterName[12]; // Address: 0x2B5880
char* vsptblBoardName[12][7]; // Address: 0x2B58B0
char* vsptblCourseName[24]; // Address: 0x2B5A00
char* vsptblGapList[8][64]; // Address: 0x2B5A60
signed int vsptblGapPoint[8][64]; // Address: 0x2B6260
signed int vsptblLevelGoalValue[8][7]; // Address: 0x2B6A60
static char* vsptblLevelGoalStrE[8][3]; // Address: 0x2B6B40
static char* vsptblLevelGoalStrG[8][3]; // Address: 0x2B6BA0
static char* vsptblLevelGoalStrF[8][3]; // Address: 0x2B6C00
char* vsptblTrickName[160]; // Address: 0x2B6C60
signed int vsptblTrickPoint[160]; // Address: 0x2B6EE0
// Size: 0x1C, DWARF: 0xA933E
CharacterParameters vsptblCharacterParam[12]; // Address: 0x2B7160
// Size: 0x10, DWARF: 0xA96A5
VsptblBoardParam vsptblBoardParam[12][7]; // Address: 0x2B72B0
signed int vsptblCourseParam[8][5]; // Address: 0x2B77F0
static char* vsptblCheatsE[10]; // Address: 0x2B7890
static char* vsptblCheatsG[10]; // Address: 0x2B78C0
static char* vsptblCheatsF[10]; // Address: 0x2B78F0
static // Size: 0x20, DWARF: 0xA8A83
VsptblFreeStyleRanking vsptblFreeStyleRanking[8][6]; // Address: 0x2B7920
static // Size: 0x4, DWARF: 0xA7FDA
VsptblBestTime vsptblBestTime[8]; // Address: 0x2B7F20
char* vsptblMovieName[15]; // Address: 0x2B7F40
// Size: 0x114, DWARF: 0xA8BCC
VspenvOption* vspenvOption; // Address: 0x2E7B10
// Size: 0xEF8, DWARF: 0xA8295
VspenvSecret* vspenvSecret; // Address: 0x2E7B04
// Size: 0xA0, DWARF: 0xA8989
VspenvGame* vspenvGame; // Address: 0x2E7B14
char* vsptblLevelGoalStr[8][3]; // Address: 0x3A45E0
char* vsptblCheats[10]; // Address: 0x3A45B0
VspenvEnv vspenvEnv; // Address: 0x3474D0
// Size: 0x2DCEC, DWARF: 0xA8560
VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
// Size: 0x4, DWARF: 0xA7FDA
VsptblBestTime* vspenvBestTime[8]; // Address: 0x3473F0
// Size: 0x20, DWARF: 0xA8A83
VsptblFreeStyleRanking* vspenvRecord[8][6]; // Address: 0x347410
void(spFreeRideInit)(signed int); // Address: 0x198FA0
void(aySelectModInit)(signed int); // Address: 0x1A4290
void(ayMovieModInit)(signed int); // Address: 0x1B42F0
void(sploadInit)(signed int); // Address: 0x18A600
// Size: 0x20, DWARF: 0xA91D4
VspenvDemo vspenvDemo; // Address: 0x3473D0

//// Function Declarations ///////////////////////////////////////////////////////////

void spinitInit();
void spinitInitRecord();
void spinitInitOption(// Size: 0x114, DWARF: 0xA8BCC
VspenvOption* option);
static void spinitInitKeyConfig(// Size: 0x24, DWARF: 0xA80F3
KeyConfig* config);
static void spinitInitVolume(// Size: 0x8, DWARF: 0xA8502
Volume* volume);
static void spinitInitCheats(// Size: 0x30, DWARF: 0xA87A8
Cheats* cheats);
void spinitInitSecret(// Size: 0xEF8, DWARF: 0xA8295
VspenvSecret* secret);
void spinitInitCharacter(// Size: 0x74, DWARF: 0xA94E9
Character* character, signed int sw, // Size: 0x1C, DWARF: 0xA933E
CharacterParameters* param);
void spinitInitCreateCharacter(// Size: 0xEC, DWARF: 0xA8F4F
CreateCharacter* character);
void spinitGetClock();
void spinitGetCreateClock(signed int no);
static void spinitGetClockSub(// Size: 0x18, DWARF: 0xA9DE9
Clock2* clk);
static void spinitModule();

//// Function Definitions ////////////////////////////////////////////////////////////

// DWARF: 0xAA132
// Address: 0x1897E0
// Size: 0x2AC
void spinitInit() {
    signed int jj; // r16
    signed int ii; // r17

    vspenvGame = &vspenvEnv.game;
    vspenvOption = &vspenvEnv.mc.option;
    for (ii = 0; ii < 8; ii++) {
        for (jj = 0; jj < 6; jj++) {
             // Load records from memory card data.
            vspenvRecord[ii][jj] = &vspenvEnv.mc.record[ii][jj];
        }
        // Load best times form memory card.
        vspenvBestTime[ii] = &vspenvEnv.mc.best_time[ii];
    }
    for (ii = 0; ii < 2; ii++) {
        vspenvReplay[ii] = &vspenvEnv.replay[ii];
    }
    vspenvSecret = &vspenvEnv.mc.secret;
    vspenvGame->mode.divide = 0;
    vspenvGame->language = 0;
    if (vspenvGame->language == 0) {
        // English Language
        memcpy(&vsptblCheats, &vsptblCheatsE, 0x28);
        memcpy(&vsptblLevelGoalStr, &vsptblLevelGoalStrE, 0x60);
    } else if (vspenvGame->language == 1) {
        // German Language
        memcpy(&vsptblCheats, &vsptblCheatsG, 0x28);
        memcpy(&vsptblLevelGoalStr, &vsptblLevelGoalStrG, 0x60);
    } else if (vspenvGame->language == 2) {
        // French Language
        memcpy(&vsptblCheats, &vsptblCheatsF, 0x28);
        memcpy(&vsptblLevelGoalStr, &vsptblLevelGoalStrF, 0x60);
    }
    vspenvGame->ending = 0;
    vspenvGame->bgm_no = -1;
    spinitInitRecord();
    spinitInitOption(vspenvOption);
    spinitInitSecret(vspenvSecret);
    spinitGetClock();
    nmbgmSetSelectTbl(vspenvOption->bgm, vspenvOption->bgm.disable);
    spinitModule();
    uldvdSetReadFile_DRIVE("\\DATA.DAT");
}

// DWARF: 0xAA289
// Address: 0x189A90
// Size: 0xF0
void spinitInitRecord() {
    signed int ii;
    signed int jj;

    for (ii = 0; ii < 8; ii++) {
        for (jj = 0; jj < 6; jj++) {
            *vspenvRecord[ii][jj] = vsptblFreeStyleRanking[ii][jj];
        }
        *vspenvBestTime[ii] = vsptblBestTime[ii];
    }
}

// DWARF: 0xAA3AA
// Address: 0x189B80
// Size: 0x174
void spinitInitOption(VspenvOption* option) {
    signed int ii; // r16

    for (ii = 0; ii < 2; ii++) {
        spinitInitKeyConfig(&option[0].key_config[ii]);
    }
    spinitInitVolume(&option->volume);
    spinitInitCheats(&option->cheats);
    spinitInitCheats(&option->enable);
    for (ii = 0; ii < 0x10; ii++) {
        option[0].bgm.table[ii] = ii;
    }
    option->bgm.disable = -1;
    for (ii = 0; ii < 0xC; ii++) {
        option->bgm.disable ^= (1 << ii);
    }
    option->bgm.random = 0;
    option->tutorial = 1;
    for (ii = 0; ii < 0x10; ii++) {
        option[0].name[ii] = 0;
    }
    option->name[0] = 'A';
    option->name[1] = 'C';
    option->name[2] = 'T';
    option->movie = 0;
    option->divide = 0;
}

// DWARF: 0xAA4C6
// Address: 0x189D00
// Size: 0x80
static void spinitInitKeyConfig(KeyConfig* config) {
    config->vibration = 1;
    config->spin_l = 4;
    config->spin_r = 8;
    config->stance = 2;
    config->grind = 0x10;
    config->grab = 0x20;
    config->jump = 0x40;
    config->flip = 0x80;
    config->revert = 1;
}

// DWARF: 0xAA5A3
// Address: 0x189D80
// Size: 0x2C
static void spinitInitVolume(Volume* volume) {
    volume->se = 0xFF;
    volume->bgm = 0xFF;
}

// DWARF: 0xAA67D
// Address: 0x189DB0
// Size: 0x74
static void spinitInitSecret(VspenvSecret* secret) {
    int* ptr;
    signed int ii; // r16
    signed int sw[12] = { // 0x30(r29)
        1, 1, 1, 1,
        1, 1, 1, 1,
        1, 1, 0, 0
    };

    ptr = sw;
    for (ii = 0; ii < 0xC; ii++) {
        spinitInitCharacter(&vspenvSecret->character[ii], sw[ii], &vsptblCharacterParam[ii]);
    }
    for (ii = 0; ii < 0xA; ii++) {
        spinitInitCreateCharacter(&vspenvSecret->create_character[ii]);
    }
    for (ii = 0; ii < 8; ii++) {
        vspenvSecret->course[ii].gap = 0;
    }
    secret->old_char = 0;
    secret->first_clear = 0;
    secret->tour_round = 1;
}

// DWARF: 0xAA757
// Address: 0x189E30
// Size: 0x150
void spinitInitSecret(// Size: 0xEF8, DWARF: 0xA8295
VspenvSecret* secret /* 0x60(r29) */);

// DWARF: 0xAA8B5
// Address: 0x189F80
// Size: 0xE0
void spinitInitCharacter(Character* character, signed int sw, CharacterParameters* param) {
    signed int ii; // r16
    
    character->secret = sw;
    character->board = 1;
    character->course = 1;
    for (ii = 0; ii < 8; ii++) {
        character->soft[ii] = 0;
    }
    for (ii = 0; ii < 8; ii++) {
        character->level_goal[ii] = 0;
    }
    character->rem_point = 0;
    character->old_brd_no = 0;
    character->old_wear_no = 0;
    memcpy(&character->parameter, param, 0x1C);
}

// DWARF: 0xAAA27
// Address: 0x18A060
// Size: 0x10C
void spinitInitCreateCharacter(CreateCharacter* character) {
    CharacterParameters param; // 0x20(r29)
    signed int ii; // r16

    param.ollie = 1;
    param.spin = 1;
    param.speed = 1;
    param.landing = 1;
    param.balance = 1;
    param.stability = 10;
    param.stance = 0;
    spinitInitCharacter(&character->character, 0, &param);
    character->character.rem_point = 11;
    for (ii = 0; ii < 16; ii++) {
        character->name[ii] = 0;
    }
    character->age = 20;
    character->sex = 0;
    character->face = 0;
    character->hair = 0;
    character->hair_color = 0;
    character->body = 0;
    character->body_color = 0;
    character->pants = 0;
    character->pants_color = 0;
    character->glove = 0;
    character->boots = 0;
    character->board_type = 0;
    character->trick_type = 0;
}

// DWARF: 0xAAB78
// Address: 0x18A170
// Size: 0x68
void spinitGetClock() {
    signed int ii; // r16
    spinitGetClockSub(&vspenvEnv.mc.file.clock);
    for (ii = 0; ii < 2; ii++) {
        spinitGetClockSub(&vspenvReplay[ii]->file.clock);
    }
}

// DWARF: 0xAAC71
// Address: 0x18A1E0
// Size: 0x48
void spinitGetCreateClock(signed int no) {
    spinitGetClockSub(&vspenvSecret->create_character[no].clock);
}

// DWARF: 0xAAD5E
// Address: 0x18A230
// Size: 0x264
static void spinitGetClockSub(Clock2* clk) {
    signed int tmp; // r16
    // Size: 0x8, DWARF: 0xA9B29
    Clock clock; // 0x28(r29)

    sceCdReadClock(&clock);
    sceScfGetLocalTimefromRTC(&clock);

    tmp = (clock.year % 16);
    clk->year = tmp = (signed int) tmp + ((clock.year / 16) * 0xA);
    tmp = (clock.month % 16);
    clk->month = tmp = (signed int) (tmp + ((clock.month / 16) * 0xA));
    tmp = (clock.day % 16);
    clk->day = tmp = (signed int) (tmp + ((clock.day / 16) * 0xA));
    tmp = (clock.hour % 16);
    clk->hour = tmp = (signed int) (tmp + (clock.hour / 16) * 0xA);
    tmp = (clock.minute % 16);
    clk->minute = tmp = (signed int) (tmp + ((clock.minute / 16) * 0xA));
    tmp = (clock.second % 16);
    clk->second = tmp = (signed int) (tmp + (((clock.second) / 16) * 0xA));
}

// DWARF: 0xAAEA2
// Address: 0x18A4A0
// Size: 0x158
static void spinitModule() {
    gmsysSetModule(0, &sploadInit);
    gmsysSetModule(7, &sploadInit);
    gmsysSetModule(1, &sploadInit);
    gmsysSetModule(2, &sploadInit);
    gmsysSetModule(3, &sploadInit);
    gmsysSetModule(4, &sploadInit);
    gmsysSetModule(5, &sploadInit);
    gmsysSetModule(6, &sploadInit);
    gmsysSetModule(0x16, &ayMovieModInit);
    gmsysSetModule(0x17, &ayMovieModInit);
    gmsysSetModule(0x10, &aySelectModInit);
    gmsysSetModule(0x11, &spFreeRideInit);
    gmsysSetModule(0x12, &spFreeRideInit);
    gmsysSetModule(0x13, &spFreeRideInit);
    gmsysSetModule(0x14, &spFreeRideInit);
    gmsysSetModule(0x15, &spFreeRideInit);
}
