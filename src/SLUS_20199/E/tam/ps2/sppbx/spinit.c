#include "common.h"
#include "types.h"

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

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

//// Function Declarations ///////////////////////////////////////////////////////////

void spinitInit();
void spinitInitRecord();
// Size: 0x114, DWARF: 0xA8BCC
void spinitInitOption(VspenvOption* option);
// Size: 0x24, DWARF: 0xA80F3
static void spinitInitKeyConfig(KeyConfig* config);
// Size: 0x8, DWARF: 0xA8502
static void spinitInitVolume(Volume* volume);
// Size: 0x30, DWARF: 0xA87A8
static void spinitInitCheats(Cheats* cheats);
// Size: 0xEF8, DWARF: 0xA8295
void spinitInitSecret(VspenvSecret* secret);
// Size: 0x74, DWARF: 0xA94E9
// Size: 0x1C, DWARF: 0xA933E
void spinitInitCharacter(Character* character, signed int sw, CharacterParameters* param);
// Size: 0xEC, DWARF: 0xA8F4F
void spinitInitCreateCharacter(CreateCharacter* character);
void spinitGetClock();
void spinitGetCreateClock(signed int no);
// Size: 0x18, DWARF: 0xA9DE9
static void spinitGetClockSub(Clock2* clk);
static void spinitModule();

// Included functions ////////////////////////////////////////////////////////////////
void* memcpy(void* dst, const void* src, unsigned int len);
void nmbgmSetSelectTbl(Bgm bgm, signed int disable);
void uldvdSetReadFile_DRIVE(char* fn);
void gmsysSetModule(signed int no, void(*func)(signed int));
// Size: 0x8, DWARF: 0xA9B29
void sceCdReadClock(Clock* clock);
void sceScfGetLocalTimefromRTC(Clock* clock);
void spFreeRideInit(signed int); // Address: 0x198FA0
void aySelectModInit(signed int); // Address: 0x1A4290
void ayMovieModInit(signed int); // Address: 0x1B42F0
void sploadInit(signed int); // Address: 0x18A600

//// Variables ///////////////////////////////////////////////////////////////////////

// Initialised data is emitted in declaration order, so these ascend by address.

char* vsptblCharacterName[12] = {
    "SHAUN PALMER", "TOMMY CZESCHIN", "JIMMY HALOPOFF",
    "SHAUN WHITE", "LESLEE OLSON", "DREW NEILSON",
    "ROSS POWERS", "TARA DAKIDES", "INGEMAR BACKMAN",
    "MARKUS HURME", "ROOFTOP", "CORY NASTAZIO",
};

char* vsptblBoardName[12][7] = {
    {
        "CARBON CIRCLE", "CHANNEL TITANIUM", "HONEYCOMB", "HONEYCIRCLE",
        "LIBERTY", "GAP", "GLASS",
    },
    {
        "PROJECT FS 157", "SMOKE 153", "MEGALIGHT 162", "NBX 163",
        "PEAK 166", "TOMMY 155", "GLASS",
    },
    {
        "MOVEMENT 60", "MOVEMENT 58", "ADVANCE 56", "ADVANCE 54",
        "FORWARD 52", "FORWARD 48", "GLASS",
    },
    {
        "PUNCH 43", "CUSTOM 46", "CUSTOM 51", "DRAGON 47",
        "BALANCE 44", "BALANCE 48", "GLASS",
    },
    {
        "142 STRENGTH", "146 RESPECT", "150 DETERMINATION", "153 CONFIDENCE",
        "157 GRACE", "FAITH", "GLASS",
    },
    {
        "FRONTIER 64X", "FRONTIER 66", "CUSTOM 56", "CUSTOM 60",
        "BMC62", "BMC66", "GLASS",
    },
    {
        "POWERS 58", "BALANCE 57.5", "BALANCE 61", "CUSTOM 60",
        "CUSTOM 64", "CUSTOM 68", "GLASS",
    },
    {
        "FR 750 158", "FS 750 144", "FS 750 155", "FS 750W 152",
        "FSR 750 151", "FSR 750 157", "GLASS",
    },
    {
        "160 DIRECTIONAL", "147 DIRECTIONAL", "GRENADE 152", "156 DIRECTIONAL",
        "155 DIRECTIONAL", "166 DIRECTIONAL", "GLASS",
    },
    {
        "BIG SHOT 590", "ELEMENT 630", "EPIC 620", "MISSION 70",
        "NOTORIOUS 570", "SUPREME 6100", "GLASS",
    },
    {
        "ELECTRIC", "HIVE", "MIST", "NAPALM",
        "REFLEX", "ROSEWOOD", "GLASS",
    },
    {
        "COLONY", "FRESH", "FURY", "LASARIUM",
        "SHOCKWAVE", "VIBE", "GLASS",
    },
};

char* vsptblCourseName[24] = {
    "DONNER SKI RANCH", "ASPEN", "KIRKWOOD",
    "HEAVENLY", "SNOWBIRD", "SQUAW VALLEY",
    "MT. HOOD MEADOWS", "GOTCHA GLACIER", "DONNER SKI RANCH",
    "ASPEN SKI RESORT", "KIRKWOOD MOUNTAIN RESORT", "HEAVENLY SKI RESORT",
    "SNOWBIRD", "SQUAW VALLEY SKI RESORT", "MOUNT HOOD MEADOWS SKI RESORT",
    "GOTCHA GLACIER", "DONNER", "ASPEN",
    "KIRKWOOD", "HEAVENLY", "SNOWBIRD",
    "SQUAW", "MT. HOOD", "GOTCHA",
};

char* vsptblGapList[8][64] = {
    {
        "TOWERING AIR", "SNOW CAT AIR", "BUST THE ANTENNA",
        "OLD LIFT AIR", "OUTTA' HERE!", "AIR BUSTO",
        "OVER THE POND", "P'S FRONT YARD TRANSFER", "LODGE 2 WIRE",
        "BUSTO RETURNS", "PIPE WHEELIE", "CRATE WHEELIE",
        "PRO SURFER?", "DRUM CAN BONK", "LIFT SLIDE",
        "WATER TANK PIPE", "MAN ON THE ROOF", "RAIL 2 RAIL 2 RAIL",
        "CABIN 2 CABIN", "SORRY DUDE...", "DONNER DELINQUENCY",
        "PALMER CADDY GRIND", "HELLO, OPERATOR?", "WIRE SLIDE",
        "TENT 2 TENT", "CHAIR BONK", "R U SCARED OF HEIGHTS?",
        "WRECKAGE SLIDE", "PLANK 2 ROOF", "OVER THE TOP",
        "PEEPING TOM", "AIR OVITZ", "LIGHT IT UP",
        "PIPE HOPPIN'", "ROUND THE TANK", "LOVE'DEM HIPS",
        "GRIND'N HIPS", "HOW YA LIKE ME NOW!", "NO WAY!!!",
        "NEEDLE IN THE HAYSTACK", "HAYES' STACK", "CASA DE PALM AIR",
        "PORCH SLIDE", "TANK PLANT", "DUMPSTER PLANT",
        "SIGN PLANT", "CONDO PLANT", "LUNCH 2 GO",
        "PHOTO OP", 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
    {
        "BIG BURN AIR", "SPIDER SABICH AIR", "SHADOW MOUNTAIN AIR",
        "HANGING VALLEY AIR", "I CAN SEE MY HOUSE", "DUDE... THERE'S MY CAR",
        "ASPEN AIR", "BONNIE'S TRANSFER", "YERT AIR",
        "LOGS 2 CABLE!", "TANK AIR!", "STICK IT!!!",
        "THAT'LL LEAVE A MARK", "TURKEY DINNER", "TREE 2 FENCE 2 TREE",
        "FIRE WOOD", "TREE 2 ROOF 2 ROOF", "1 800 GRIND",
        "WOOD PECKER", "GET ON UP", "JAVA THE WARMING HUTT",
        "747 RAIL", "LIFT BONK", "SCAFFOLDING GRIND",
        "POWER SLIDE", "LIGHTS OUT", "RAISE THE ROOF",
        "ULLRHOF SLIDE", "MOSHI MOSHI", "BRICK HILL",
        "GONDOLA BONK", "NELL BONK", "SIGN 2 SIGN 2 SIGN",
        "CHAIR BONK", "WORLD'S HARDEST GAP", "AIR TEGULAPALLE",
        "HOLY #$%!", "BLIND MAN'S COMBO", "SNOWBALL PLANT",
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
    {
        "LIVING DANGEROUSLY", "FLETCH AIR", "HAYES' HOP",
        "OVER THE BRIDGE", "BIG KIRK AIR", "INCOMING!!!",
        "CREVASSE AIR", "OVER THE LOG", "HIP HOP",
        "SHED SHREDDIN'", "OUT THE CRACK", "TRAIL MAP WHEELIE",
        "THRU THE HOLE", "EXPERTS ONLY", "WOOD 2 STEEL",
        "HAWK SLIDE", "HARE SLIDE", "TREE 2 TREE 2 TREE",
        "GOLD MINE", "HIGH WIRE", "BRIDGE BUSTIN'",
        "BRIDGE SLIDE", "LOG ROLLIN'", "BARREL BONK",
        "LINK IT UP", "LUMBER JACK", "RAIL MADNESS",
        "GARBAGE BONKIN'", "MACHINE STOMPIN'", "DON'T LOOK DOWN",
        "BIG RED RIDING HOOD", "MAKE YOUR OWN BRIDGE", "LUCKY 13",
        "LONG DISTANCE CALL", "CHAIR BONK", "TREE CLIMBIN'",
        "CORNICE BEND PLANT", 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
    {
        "GUNBARREL EXPRESS", "TRAMWAY AIR", "MED DECK AIR",
        "OVER THE PIPE", "HEAVENLY HOLLOW", "OVER THE VALLEY",
        "HEAVENLY HIPS", "PARKING LOT AIR", "OVER THE SCAFFOLD",
        "GALAXY AIR", "DEVILICIOUS", "SPACE BUS",
        "LODGE TRANSFER", "BANNER HOP", "LOOK AT THE PRETTY COLORS",
        "OFF WITH YOUR HEAD", "CRANE DROP", "HEAVENLY HIGH",
        "TAHOE BABY, TAHOE", "BUSTA CAR", "AUTO TRANSFER",
        "TRANSPORTATION GAP", "TRAFFIC JAMMIN'", "MEDICAL MANUAL",
        "TIGHT SQUEEZE", "GUNBARREL BONK", "DARE DEVIL",
        "BLIND WIRE", "POWER LINE", "SELL OUT",
        "LIGHTS OUT", "ROJO VERDE", "FENCE 2 CHUTE",
        "BUMPY RIDE", "ELECTRIC SLIDE", "UNDER CONSTRUCTION",
        "LOG JAMMIN'", "MEN AT WORK", "UP IN THE HEAVENS",
        "ROLLING WHAT?", "SOUTH LAKE SLIDE", "STRIKE IT RICH",
        "GIANT LUCKY 7", "GONDOLA BONK", "CHAIR BONK",
        "ANTE UP!", "SPLISH SPLASH", "GUTTER BALL",
        "...TO THE OTHER SIDE", "PARTY CRASHER", 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
    {
        "MID GAD AIR", "PERUVIAN ACCESS", "NICE ARCH",
        "OVER THE RAINBOW", "BIG STICK AIR", "LIP 2 LIP",
        "MID GAD TEST CENTER AIR", "ROCK WALL", "PIPE LAND",
        "PALMER EXPRESS", "OVER DAVE FIELD'S OFFICE", "NICE LANDING!",
        "HIDDEN PEAK WHEELIE", "ARC D' WHEELIE", "TAKIN' OUT THE TRASH",
        "BARKIN' UP A TREE", "BEAR CLAW", "HIDDEN PEAK SLIDE",
        "CHUTE HOP", "BIRDY HOP", "PERUVIAN SLIDE",
        "EVERGREEN TRANSFER", "PRIMROSE SLIDE", "CHAIR BONK",
        "ROCK ISLAND", "TRIPLE RED", "DROPPIN' THE PLOW",
        "SNOWMOBILE STOMP", "SNOWPLOW 2 CABLE", "BELT SLIDE",
        "TEST CENTER SLIDE", "TRAM RIDE", "BIG STICK SLIDE",
        "HARD WOOD PLANT", "GREY RAIL PLANT", "PLOW PLANT",
        "BLUE RAIL PLANT", 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
    {
        "SIBERIAN AIR", "GOLD COAST AIR", "RAIL TOP TRANSFER",
        "SUN ROOF", "ROLLER COASTER AIR", "BUNGEE JUMP!",
        "RAISE THE FLAG", "SKATE PARK AIR", "PRO SKATER?",
        "WAREHOUSE AIR", "LUNCHLINE", "UNDER THE ROLLER COASTER",
        "THAT'S HOT!", "FOLLOW THE YELLOW BRICK ROAD", "HIGH ALPINE",
        "TIMBER LINE", "SQUAW LIGHTS OUT", "NIGHT LINE",
        "INCOMING", "CHALET SLIDE", "ZIP LINE",
        "CAT BONK", "EXPRESS WAY", "SNOW BLOWIN'",
        "BEAM 2 BEAM", "SUN ROOF SLIDE", "DOUBLE TREE TRIPLE RAIL",
        "WATCHIN' PALMER X", "CONTRACTOR SLIDE", "HIGH TOWER",
        "HOPE IT DOESN'T RAIN", "GET WET", "HIGH CAMP TRIPLE-SLIDE",
        "SMOKE STACKS", "WAREHOUSE PLANT", "FOUNTAIN PLANT",
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
    {
        "LAUNCH PAD", "GIANT HIPS AIR", "WALL 2 WALL",
        "GET ON THE BUS", "DOUBLE UP", "DOUBLE DOWN",
        "ALMOST INVERTED!", "WALL BANGER", "BS STAIRWAY TRANSFER",
        "MT. HOOD AIR", "OVER THE PIPE", "TRAIL MAP AIR",
        "UP AND OVER!", "NOW THAT'S A TASTY GAP", "HUGE GAP",
        "OUCH!", "HELI-GRIND", "MAP GAP",
        "STOHL GRIND", "SLIDER", "TIMBER!!!",
        "SIDEWINDER", "OFF THE H2O TOWER", "READY... AIM... FIRE!",
        "HOWITZER", "BONKIN' MACHINERY", "LANDING STRIP",
        "CHAIR BONK", "POWER LINE", "SEWAGE SLIDE",
        "FENCE 2 FENCE", "AUTO BONK", "HEY, MY NEW SKIS!!!",
        "NICE STICK!", "ARCH 2 CABLE", "COLD STEEL",
        "RED RAIL!", "RED RAIL!!", "RED RAIL!!!",
        "7-WOOD", "SHOW-OFF", "ROOF PLANT",
        "BUS PLANT", "NICE ENTRANCE!", "COMIN' THRU",
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
    {
        "BREAKIN' THE LAWS... OF PHYSICS", "FOREST HILLS", "JACKSON HEIGHTS",
        "QUEEN'S PLAZA", "CHERMERHORN", "KEW GARDEN",
        "LAST ONE'S A DOOZY!", "AGAIN!", "BIG OL' DROP",
        "GETTING WARMER...", "PALM R AIR", "LAKE DELORES",
        "LEVEL UP...", "OVER THE GIRDER", "2 THE CATWALK",
        "MMM... RAILS", "STRAW BRIDGE", "NO STROLLERS",
        "MMM... MORE RAILS", "THE BIGGER THEY ARE...", "STUPID SLIDE",
        "UH-OH", "SPOTLIGHT BONK", "PIPE PLANT",
        "A FEW, THE PROUD", "ICE PLANT", "RANDOM RAIL PLANT",
        "THREADIN' THE NEEDLE", "YEAH RIGHT", "HOW MANY IDIOTS...",
        "COUNTING DOWN...", "4...", "3...",
        "2...", "1!!!", 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
        0,
    },
};

signed int vsptblGapPoint[8][64] = {
    {
        500, 500, 650, 500, 500, 700, 3000, 1000, 500, 1000, 500, 500, 650, 500, 500, 600,
        600, 600, 700, 500, 700, 500, 600, 700, 700, 700, 1500, 700, 700, 800, 800, 1500,
        800, 800, 800, 800, 500, 1500, 1500, 350, 800, 500, 500, 500, 500, 500, 500, 350,
        350, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        500, 500, 800, 1000, 500, 600, 800, 700, 1000, 1200, 500, 1500, 700, 700, 600, 1200,
        500, 700, 800, 300, 800, 300, 600, 800, 400, 900, 1200, 500, 800, 500, 1000, 1000,
        800, 700, 700, 800, 800, 800, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        600, 550, 650, 750, 700, 700, 500, 500, 500, 600, 550, 500, 600, 1500, 600, 500,
        500, 600, 650, 600, 600, 600, 550, 550, 650, 650, 600, 500, 300, 700, 500, 600,
        600, 600, 500, 600, 600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        500, 500, 500, 800, 800, 800, 500, 800, 1000, 800, 1000, 500, 600, 500, 1000, 500,
        1000, 800, 1000, 800, 800, 800, 800, 500, 400, 300, 1000, 700, 500, 600, 700, 600,
        500, 700, 1000, 500, 500, 600, 1200, 500, 700, 600, 700, 800, 600, 500, 500, 4000,
        1500, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        500, 650, 700, 1000, 600, 500, 800, 500, 500, 650, 600, 650, 500, 600, 650, 600,
        600, 5000, 600, 600, 600, 650, 650, 600, 600, 650, 500, 500, 800, 500, 500, 700,
        600, 550, 600, 600, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        850, 700, 500, 700, 500, 500, 600, 650, 600, 700, 600, 500, 600, 500, 800, 800,
        600, 500, 500, 650, 500, 600, 600, 700, 600, 500, 500, 750, 650, 800, 600, 600,
        600, 600, 500, 600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        300, 500, 800, 1000, 850, 700, 1200, 700, 800, 800, 500, 600, 900, 800, 1000, 400,
        1500, 400, 500, 500, 700, 700, 700, 700, 700, 700, 500, 1000, 1000, 700, 850, 500,
        300, 500, 300, 400, 200, 400, 600, 1000, 500, 500, 500, 1000, 1000, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        500, 200, 200, 300, 400, 400, 400, 500, 500, 800, 600, 500, 300, 1000, 200, 500,
        600, 600, 900, 1000, 800, 800, 200, 300, 300, 500, 400, 800, 800, 400, 800, 1000,
        1200, 1600, 2400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
};

signed int vsptblLevelGoalValue[8][7] = {
    { 20000, 50000, 120000, 80, 15000, 0, 0 },
    { 40000, 100000, 200000, 85, 30000, 0, 0 },
    { 80000, 160000, 320000, 120, 40000, 0, 0 },
    { 100000, 200000, 400000, 125, 50000, 0, 0 },
    { 150000, 300000, 500000, 140, 75000, 0, 0 },
    { 200000, 400000, 600000, 140, 100000, 0, 0 },
    { 275000, 550000, 800000, 205, 125000, 0, 0 },
    { 300000, 600000, 1000000, 220, 150000, 0, 0 },
};

static char* vsptblLevelGoalStrE[8][3] = {
    { "BUST THE SLOW SIGNS", "NOSEPRESS THE WATER TANK PIPE", "SAY CHEESE!" },
    { "DEMOLISH THE COFFEE STANDS", "BONK THE GONDOLA", "SHOW THE YUPPIES THE BOTTOM OF YOUR BOARD" },
    { "BONK THE WILDLIFE", "BUST THE CAUTION SIGNS", "FRONT FLIP OVER HAYES' HOP" },
    { "MOVE THE CRANES", "SMASH THE BIG SLOT", "ESCAPE WITH THE IDOL" },
    { "ABOLISH THE SNOWMEN", "RIDE THE TRAMS", "STOP THE RUNAWAY SNOWMOBILE" },
    { "RIDE THE CRANES", "BEST 20 SECS THROUGH THE PALMER X RUN", "EXTINGUISH THE SQUAW LIGHTS" },
    { "CUT THE POWER", "BONK THE WATER TOWERS", "CLEAR THE ROAD" },
    { "BRING DOWN THE MAN", "COLLAPSE THE BRIDGE", "TRANSFER ON THE G TRAIN" },
};

static char* vsptblLevelGoalStrG[8][3] = {
    { "FAHR DIE SLOW-SCHILDER UM!", "NOSEPRESS AN DER WASSERR\222HRE!", "SAG 'CHEESE'!" },
    { "FAHR DIE KAFFEETHEKEN UM!", "BONKE DIE GONDEL!", "ZEIG DEN YUPPIES DIE UNTERSEITE DEINES BOARDS!" },
    { "BONKE DAS TIERREICH!", "ZERST\222R DIE CAUTION-SCHILDER!", "FRONT FLIP \224BER HAYES-HOP-GAP" },
    { "BEWEGE DIE KR\220NE!", "BONKE DEN GROSSEN SPIELAUTOMAT!", "FAHR UM DEIN LEBEN" },
    { "FAHR DIE SCHNEEM\220NNER UM!", "FAHR AUF DEN GONDELSEILEN!", "HALTE DAS FAHRERLOSE SCHNEEMOBIL AUF!" },
    { "FAHRE AN DEN KR\220NEN!", "BEENDE DAS PALMER-X-RENNEN IN 20 SEK!", "L\222SCH DIE SQUAW-LICHTER!" },
    { "DREH DEN STROM AB!", "BONKE DIE WASSERT\224URME!", "R\220UME DIE STRASSE!" },
    { "BRING DEN CHAMPION ZU FALL!", "BRING DIE BR\224CKE ZUM EINSTURZ!", "TRANSFER AUF DEM G-ZUG!" },
};

static char* vsptblLevelGoalStrF[8][3] = {
    { "EXPLOSE LES PANNEAUX \"RALENTIR\"", "FAIS UN NOSEPRESS SUR LE TUYAU DU RESERVOIR", "FAIS UN JOLI SOURIRE !" },
    { "EXPLOSE LES MACHINES A CAFE", "BONKE LA CABINE", "MONTRE AUX YUPPIES LE DESSOUS DE TA PLANCHE" },
    { "BONKE LES ANIMAUX", "EXPLOSE LES PANNEAUX \"DANGER\"", "FAIS UN FRONT FLIP SUR LE HAYES' HOP" },
    { "DEPLACE LES GRUES", "PULVERISE LA GRANDE MACHINE A SOUS", "ENFUIS-TOI AVEC L'IDOLE" },
    { "EXPLOSE LES BONHOMMES DE NEIGE", "RIDE SUR LES TRAMS", "ARRETE LA MOTONEIGE EN FOLIE" },
    { "SAUTE ENTRE LES TOURS", "FAIS MOINS DE 20 S AVEC PALMER X", "ETEINS LES LAMPES" },
    { "COUPE LE COURANT", "BONKE LES CITERNES", "FAIS LE MENAGE SUR LA ROUTE" },
    { "FAIS TOMBER LE MEC", "DEMOLIS LE PONT", "PASSE PAR LES G" },
};

char* vsptblTrickName[160] = {
    "SHIFTY", "NOSEGRAB", "MUTE",
    "INDY", "STALEFISH AIR", "TAILGRAB",
    "MELONCHOLY", "METHOD", "GRASSER",
    "ROCKET AIR", "LIEN AIR", "ROASTBEEF",
    "LIEN METHOD", "DOUBLE HANDED INDY", "INDY NOSEBONE",
    "TINDY GRAB", "CRAIL", "SAD AIR",
    "SEATBELT", "TAIL NOSEBONE", "NUCLEAR",
    "JAPAN AIR", "CROSSROCKET", "TAIPAN AIR",
    "METHOD DONKEY KICK STYLE", "FRONT FLIP", "BS CORK 5",
    "MISTY 5", "BS RODEO 5", "BACK FLIP",
    "FS RODEO 5", "UNDER FLIP", "FS CORK 5",
    "DOUBLE FLIP", "BS CORK 7", "FRONT FLIP 180",
    "FS CORK 7", "BS CORK 9", "MISTY 7",
    "BS RODEO 9", "BACK FLIP 180", "SUPERMAN FLIP",
    "BS RODEO 7", "DOUBLE BACK FLIP", "FS RODEO 7",
    "FS CORK 9", "MISTY 9", "FS RODEO 9",
    "BACK FLIP 540", "50-50", "NOSEPRESS",
    "BS NOSE SLIDE", "BS BOARD SLIDE", "BS TAIL SLIDE",
    "TAILPRESS", "FS TAIL SLIDE", "FS BOARD SLIDE",
    "FS NOSE SLIDE", "FS 180 50-50", "BS 270 BOARD SLIDE REVERT OUT",
    "FS 270 BOARD SLIDE REVERT OUT", "BS 180 50-50", "NOSE BONK",
    "BS JIB BONK", "TAIL BONK", "FS JIB BONK",
    "HANDPLANT", "HANDPLANT TO FAKIE", "EGGPLANT INDY",
    "EGGPLANT", "EGGPLANT STALEFISH", "LAYBACK",
    "MILLER FLIP", "J-TEAR", "DOUBLE HANDPLANT",
    "MANUAL", "NOSE MANUAL", "TAIL BUTTER",
    "NOSE BUTTER", "BS REVERT", "FS REVERT",
    "BIG OLLIE", "SUPER OLLIE", "NOLLIE",
    "PALM AIR", "ONE-FOOTED TAIL BUTTER", "BS 360 TO BS RODEO 7 MELON",
    "ONE-FOOTED STIFFY", "ONE-FOOTED BOARDSLIDE", "STALLED UNDERFLIP INDY POKE",
    "BS RODEO 9 ONE-FOOTED METHOD", "DRAGON BONING", "LONG BOARDER",
    "FS RODEO 1080 INDY", "SPIN SLIDE", "1080 JAPAN",
    "METHOD LATE Mc 7 MELON", "McTWIST 1080 MELON", "FS RODEO 1080 STALEFISH",
    "STATUE OF LIBERTY AIR", "CYCLONE", "OVERTWEAKED BS AIR",
    "SPREAD EAGLE TOE GRAB", "ONE-FOOTED BOOTSLIDE", "HAND MANUAL",
    "ONE-FOOTED HANDPLANT", "BS 1080 ONE-FOOTED TAILGRAB", "LIMBO SLIDE",
    "PALM AIR", "ONE-FOOTED TAIL BUTTER", "BS 360 TO BS RODEO 7 MELON",
    "ONE-FOOTED STIFFY", "ONE-FOOTED BOARDSLIDE", "STALLED UNDERFLIP INDY POKE",
    "BS RODEO 9 ONE-FOOTED METHOD", "DRAGON BONING", "LONG BOARDER",
    "FS RODEO 1080 INDY", "SPIN SLIDE", "CAB 1080 JAPAN",
    "METHOD LATE Mc 7 MELON", "McTWIST 1080 MELON", "FS RODEO 1080 STALEFISH",
    "STATUE OF LIBERTY AIR", "CYCLONE", "OVERTWEAKED BS AIR",
    "SPREAD EAGLE TOE GRAB", "ONE-FOOTED BOOTSLIDE", "HAND MANUAL",
    "ONE-FOOTED HANDPLANT", "BS CAB 1080 ONE-FOOTED TAILGRAB", "LIMBO SLIDE",
    "RAIL TAP", "DISASTER", "FRONT FLIP 180",
    "FRONT FLIP", "INVERTED 5", "INVERTED 7",
    "INVERTED 9", "INVERTED 5", "INVERTED 7",
    "INVERTED 9", 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0, 0, 0,
    0,
};

signed int vsptblTrickPoint[160] = {
    50, 100, 150, 100, 150, 100, 150, 100, 150, 200, 250, 250, 250, 300, 200, 300,
    300, 300, 250, 200, 250, 300, 300, 300, 200, 300, 400, 350, 400, 300, 400, 350,
    400, 1250, 1500, 1750, 1500, 2500, 1500, 2500, 1750, 2200, 1500, 1250, 1500, 2500, 2500, 2500,
    1500, 100, 150, 200, 150, 200, 150, 200, 150, 200, 500, 650, 650, 500, 250, 350,
    250, 350, 400, 500, 650, 550, 650, 1800, 2500, 2000, 650, 100, 110, 120, 120, 350,
    350, 100, 200, 150, 1250, 600, 5000, 1200, 1200, 5000, 5000, 1200, 1200, 5000, 1300, 4500,
    5000, 4500, 5000, 1100, 5000, 1100, 1100, 1200, 1000, 4500, 5000, 1200, 1250, 600, 5000, 1200,
    1200, 5000, 5000, 1200, 1200, 5000, 1300, 4500, 5000, 4500, 5000, 1100, 5000, 1100, 1100, 1200,
    1000, 4500, 5000, 1200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

CharacterParameters vsptblCharacterParam[12] = {
    { 4, 2, 5, 3, 2, 10, 0 },
    { 3, 5, 2, 3, 3, 10, 0 },
    { 3, 4, 3, 3, 3, 10, 0 },
    { 3, 4, 2, 2, 5, 6, 0 },
    { 3, 2, 4, 4, 3, 8, 0 },
    { 3, 2, 4, 5, 2, 10, 0 },
    { 4, 4, 3, 2, 3, 10, 0 },
    { 2, 4, 3, 5, 2, 8, 1 },
    { 5, 3, 3, 3, 2, 10, 0 },
    { 3, 3, 3, 5, 2, 10, 0 },
    { 4, 4, 3, 2, 3, 10, 1 },
    { 3, 3, 4, 4, 2, 10, 1 },
};

VsptblBoardParam vsptblBoardParam[12][7] = {
    {
        { 4, 4, 3, 3 },
        { 5, 5, 3, 4 },
        { 6, 6, 4, 5 },
        { 8, 7, 4, 6 },
        { 9, 8, 5, 7 },
        { 10, 9, 7, 8 },
        { 10, 10, 10, 10 },
    },
    {
        { 3, 4, 3, 4 },
        { 3, 5, 4, 5 },
        { 4, 6, 5, 6 },
        { 5, 7, 6, 7 },
        { 6, 7, 8, 8 },
        { 7, 9, 9, 9 },
        { 10, 10, 10, 10 },
    },
    {
        { 4, 4, 3, 3 },
        { 4, 5, 4, 4 },
        { 5, 6, 5, 5 },
        { 6, 7, 6, 6 },
        { 7, 8, 7, 7 },
        { 9, 9, 8, 8 },
        { 10, 10, 10, 10 },
    },
    {
        { 3, 4, 4, 3 },
        { 4, 4, 5, 4 },
        { 5, 5, 6, 5 },
        { 5, 6, 8, 6 },
        { 6, 6, 9, 8 },
        { 7, 8, 10, 9 },
        { 10, 10, 10, 10 },
    },
    {
        { 4, 4, 3, 3 },
        { 5, 4, 4, 4 },
        { 6, 5, 5, 5 },
        { 7, 6, 6, 6 },
        { 9, 7, 7, 6 },
        { 10, 9, 8, 7 },
        { 10, 10, 10, 10 },
    },
    {
        { 4, 4, 3, 3 },
        { 5, 5, 4, 3 },
        { 6, 6, 5, 4 },
        { 7, 8, 5, 5 },
        { 8, 9, 6, 6 },
        { 9, 10, 8, 7 },
        { 0, 0, 0, 0 },
    },
    {
        { 3, 4, 3, 4 },
        { 4, 4, 4, 5 },
        { 5, 5, 5, 6 },
        { 6, 6, 6, 7 },
        { 7, 7, 8, 7 },
        { 7, 9, 9, 9 },
        { 10, 10, 10, 10 },
    },
    {
        { 3, 4, 3, 4 },
        { 4, 4, 4, 5 },
        { 5, 5, 5, 6 },
        { 6, 6, 6, 7 },
        { 7, 7, 7, 8 },
        { 7, 9, 8, 10 },
        { 10, 10, 10, 10 },
    },
    {
        { 3, 4, 3, 4 },
        { 4, 5, 4, 4 },
        { 5, 6, 5, 5 },
        { 6, 7, 6, 6 },
        { 7, 8, 7, 7 },
        { 9, 9, 8, 8 },
        { 10, 10, 10, 10 },
    },
    {
        { 3, 4, 3, 4 },
        { 4, 5, 3, 5 },
        { 5, 5, 5, 6 },
        { 6, 6, 6, 7 },
        { 7, 7, 7, 8 },
        { 8, 10, 7, 9 },
        { 10, 10, 10, 10 },
    },
    {
        { 3, 4, 3, 4 },
        { 4, 5, 4, 4 },
        { 5, 6, 5, 5 },
        { 6, 7, 6, 6 },
        { 7, 8, 7, 7 },
        { 8, 9, 8, 9 },
        { 10, 10, 10, 10 },
    },
    {
        { 3, 4, 3, 4 },
        { 4, 4, 4, 5 },
        { 5, 5, 5, 6 },
        { 6, 6, 6, 7 },
        { 7, 7, 7, 8 },
        { 8, 9, 8, 9 },
        { 10, 10, 10, 10 },
    },
};

signed int vsptblCourseParam[8][5] = {
    { 62, 5, 25, 5561, 49 },
    { 62, 5, 25, 5561, 39 },
    { 58, 10, 32, 4712, 37 },
    { 62, 5, 25, 5561, 50 },
    { 62, 5, 25, 5561, 37 },
    { 62, 5, 25, 5561, 36 },
    { 62, 5, 25, 5561, 45 },
    { 62, 5, 25, 5561, 35 },
};

static char* vsptblCheatsE[10] = {
    "KID MODE", "ALWAYS SPECIAL",
    "PERFECT BALANCE", "SUPER SPIN",
    "HALF GRAVITY", "QUICKIE TRICKS",
    "DOUBLE SPEED", "BIG HEAD MODE",
    "METALLIC BOARDER", "THE FLIPSIDE",
};

static char* vsptblCheatsG[10] = {
    "KID-MODUS", "IMMER SPEZIAL",
    "PERFEKTE BALANCE", "SUPER-SPIN",
    "HALBE SCHWERKRAFT", "QUICKIE-TRICKS",
    "DOPPELTES TEMPO", "K\224RBISKOPF",
    "METALLBOARDER", "SPIEGELLEVEL",
};

static char* vsptblCheatsF[10] = {
    "MODE KID", "TOUJOURS SPECIAL",
    "EQUILIBRE PARFAIT", "SUPER ROTATION",
    "APESANTEUR", "TRICKS RAPIDES",
    "DOUBLE VITESSE", "MODE GROSSE TETE",
    "SNOWBOARDER METALLIQUE", "NIVEAUX MIROIR",
};

static VsptblFreeStyleRanking vsptblFreeStyleRanking[8][6] = {
    {
        { 0, 80000, "ACT" },
        { 1, 75000, "ACT" },
        { 2, 70000, "ACT" },
        { 3, 65000, "ACT" },
        { 4, 60000, "ACT" },
        { 5, 55000, "ACT" },
    },
    {
        { 0, 95000, "ACT" },
        { 1, 90000, "ACT" },
        { 2, 85000, "ACT" },
        { 3, 80000, "ACT" },
        { 4, 75000, "ACT" },
        { 5, 70000, "ACT" },
    },
    {
        { 2, 120000, "ACT" },
        { 3, 115000, "ACT" },
        { 4, 110000, "ACT" },
        { 5, 105000, "ACT" },
        { 6, 100000, "ACT" },
        { 7, 95000, "ACT" },
    },
    {
        { 0, 195000, "ACT" },
        { 1, 190000, "ACT" },
        { 2, 185000, "ACT" },
        { 3, 180000, "ACT" },
        { 4, 175000, "ACT" },
        { 5, 170000, "ACT" },
    },
    {
        { 4, 100000, "ACT" },
        { 5, 95000, "ACT" },
        { 6, 90000, "ACT" },
        { 7, 85000, "ACT" },
        { 8, 80000, "ACT" },
        { 9, 75000, "ACT" },
    },
    {
        { 2, 120000, "ACT" },
        { 3, 115000, "ACT" },
        { 4, 110000, "ACT" },
        { 5, 105000, "ACT" },
        { 6, 100000, "ACT" },
        { 7, 95000, "ACT" },
    },
    {
        { 6, 100000, "ACT" },
        { 7, 95000, "ACT" },
        { 8, 90000, "ACT" },
        { 9, 85000, "ACT" },
        { 0, 80000, "ACT" },
        { 1, 75000, "ACT" },
    },
    {
        { 8, 180000, "ACT" },
        { 9, 175000, "ACT" },
        { 0, 170000, "ACT" },
        { 1, 165000, "ACT" },
        { 2, 160000, "ACT" },
        { 3, 155000, "ACT" },
    },
};

static VsptblBestTime vsptblBestTime[8] = {
    { 87000 }, { 85000 }, { 90000 }, { 78000 },
    { 102000 }, { 98000 }, { 115000 }, { 100000 },
};

char* vsptblMovieName[15] = {
    "SHAUN PALMER", "TOMMY CZESCHIN", "JIMMY HALOPOFF",
    "SHAUN WHITE", "LESLEE OLSON", "DREW NEILSON",
    "ROSS POWERS", "TARA DAKIDES", "INGEMAR BACKMAN",
    "MARKUS HURME", "ROOFTOP", "CORY NASTAZIO",
    "MINI SHRED", "BAILS 1", "BAILS 2",
};

// bss and sbss are emitted in reverse declaration order, so these descend.

char* vsptblLevelGoalStr[8][3]; // Address: 0x3A45E0
char* vsptblCheats[10]; // Address: 0x3A45B0
// Size: 0x5D0E0, DWARF: 0xA8DCB
VspenvEnv vspenvEnv; // Address: 0x3474D0
// Size: 0x20, DWARF: 0xA8A83
VsptblFreeStyleRanking* vspenvRecord[8][6]; // Address: 0x347410
// Size: 0x4, DWARF: 0xA7FDA
VsptblBestTime* vspenvBestTime[8]; // Address: 0x3473F0
// Size: 0x20, DWARF: 0xA91D4
VspenvDemo vspenvDemo; // Address: 0x3473D0

// Size: 0xA0, DWARF: 0xA8989
VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x114, DWARF: 0xA8BCC
VspenvOption* vspenvOption; // Address: 0x2E7B10
// Size: 0x2DCEC, DWARF: 0xA8560
VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
// Size: 0xEF8, DWARF: 0xA8295
VspenvSecret* vspenvSecret; // Address: 0x2E7B04

//// Function Definitions ////////////////////////////////////////////////////////////

// DWARF: 0xAA132
// Address: 0x1897E0
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
static void spinitInitVolume(Volume* volume) {
    volume->se = 0xFF;
    volume->bgm = 0xFF;
}

// DWARF: 0xAA5A3
// Address: 0x189DB0
static void spinitInitCheats(Cheats* cheats) {
    cheats->kids = 0;
    cheats->always_sp = 0;
    cheats->perfect_b = 0;
    cheats->super_spin = 0;
    cheats->half_g = 0;
    cheats->fast_motion = 0;
    cheats->super_speed = 0;
    cheats->big_head = 0;
    cheats->mirror = 0;
    cheats->metallic = 0;
    cheats->replay_view = 0;
    cheats->partition = 0;
}

// DWARF: 0xAA67D
// Address: 0x189E30
void spinitInitSecret(VspenvSecret* secret) {
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

// DWARF: 0xAA8B5
// Address: 0x189F80
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
void spinitGetClock() {
    signed int ii; // r16
    spinitGetClockSub(&vspenvEnv.mc.file.clock);
    for (ii = 0; ii < 2; ii++) {
        spinitGetClockSub(&vspenvReplay[ii]->file.clock);
    }
}

// DWARF: 0xAAC71
// Address: 0x18A1E0
void spinitGetCreateClock(signed int no) {
    spinitGetClockSub(&vspenvSecret->create_character[no].clock);
}

// DWARF: 0xAAD5E
// Address: 0x18A230
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
