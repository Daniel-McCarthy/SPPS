#include "common.h"
#include "types.h"

// aymovie.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x4, DWARF: 0xE8731
typedef struct BestTime
{
    unsigned int time; // Offset: 0x0, DWARF: 0xE874C
} BestTime;

// Size: 0x18, DWARF: 0xEA03C
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0xEA058
    signed int month; // Offset: 0x4, DWARF: 0xEA079
    signed int day; // Offset: 0x8, DWARF: 0xEA09B
    signed int hour; // Offset: 0xC, DWARF: 0xEA0BB
    signed int minute; // Offset: 0x10, DWARF: 0xEA0DC
    signed int second; // Offset: 0x14, DWARF: 0xEA0FF
} Clock;

// Size: 0x38, DWARF: 0xE86A7
typedef struct File
{
    // Size: 0x18, DWARF: 0xEA03C
    Clock clock; // Offset: 0x0, DWARF: 0xE86C2
    char name[32]; // Offset: 0x18, DWARF: 0xE86E6
} File;

// Size: 0x20, DWARF: 0xE85FC
typedef struct Record
{
    signed int chr_no; // Offset: 0x0, DWARF: 0xE8617
    unsigned long score; // Offset: 0x8, DWARF: 0xE863A
    char name[16]; // Offset: 0x10, DWARF: 0xE865C
} Record;

// Size: 0x48, DWARF: 0xE9155
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0xE9171
    signed int disable; // Offset: 0x40, DWARF: 0xE9195
    signed int random; // Offset: 0x44, DWARF: 0xE91B9
} Bgm;

// Size: 0x30, DWARF: 0xE8D58
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0xE8D73
    signed int always_sp; // Offset: 0x4, DWARF: 0xE8D94
    signed int perfect_b; // Offset: 0x8, DWARF: 0xE8DBA
    signed int super_spin; // Offset: 0xC, DWARF: 0xE8DE0
    signed int half_g; // Offset: 0x10, DWARF: 0xE8E07
    signed int fast_motion; // Offset: 0x14, DWARF: 0xE8E2A
    signed int super_speed; // Offset: 0x18, DWARF: 0xE8E52
    signed int big_head; // Offset: 0x1C, DWARF: 0xE8E7A
    signed int metallic; // Offset: 0x20, DWARF: 0xE8E9F
    signed int mirror; // Offset: 0x24, DWARF: 0xE8EC4
    signed int replay_view; // Offset: 0x28, DWARF: 0xE8EE7
    signed int partition; // Offset: 0x2C, DWARF: 0xE8F0F
} Cheats;

// Size: 0x24, DWARF: 0xE884A
typedef struct KeyConfig
{
    signed int vibration; // Offset: 0x0, DWARF: 0xE8865
    signed int spin_l; // Offset: 0x4, DWARF: 0xE888B
    signed int spin_r; // Offset: 0x8, DWARF: 0xE88AE
    signed int stance; // Offset: 0xC, DWARF: 0xE88D1
    signed int revert; // Offset: 0x10, DWARF: 0xE88F4
    signed int grind; // Offset: 0x14, DWARF: 0xE8917
    signed int grab; // Offset: 0x18, DWARF: 0xE8939
    signed int jump; // Offset: 0x1C, DWARF: 0xE895A
    signed int flip; // Offset: 0x20, DWARF: 0xE897B
} KeyConfig;

// Size: 0x8, DWARF: 0xE8AB2
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0xE8ACD
    signed int bgm; // Offset: 0x4, DWARF: 0xE8AEC
} Volume;

// Size: 0x114, DWARF: 0xE92BF
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0xE884A
    KeyConfig key_config[2]; // Offset: 0x0, DWARF: 0xE92DB
    // Size: 0x30, DWARF: 0xE8D58
    Cheats enable; // Offset: 0x48, DWARF: 0xE9304
    // Size: 0x30, DWARF: 0xE8D58
    Cheats cheats; // Offset: 0x78, DWARF: 0xE9329
    // Size: 0x8, DWARF: 0xE8AB2
    Volume volume; // Offset: 0xA8, DWARF: 0xE934E
    char name[16]; // Offset: 0xB0, DWARF: 0xE9373
    signed int divide; // Offset: 0xC0, DWARF: 0xE9396
    signed int tutorial; // Offset: 0xC4, DWARF: 0xE93B9
    // Size: 0x48, DWARF: 0xE9155
    Bgm bgm; // Offset: 0xC8, DWARF: 0xE93DE
    unsigned int movie; // Offset: 0x110, DWARF: 0xE9400
} VspenvOption;

// Size: 0x1C, DWARF: 0xE944C
typedef struct CharacterParam
{
    signed int ollie; // Offset: 0x0, DWARF: 0xE9468
    signed int spin; // Offset: 0x4, DWARF: 0xE948A
    signed int speed; // Offset: 0x8, DWARF: 0xE94AB
    signed int landing; // Offset: 0xC, DWARF: 0xE94CD
    signed int balance; // Offset: 0x10, DWARF: 0xE94F1
    signed int stability; // Offset: 0x14, DWARF: 0xE9515
    signed int stance; // Offset: 0x18, DWARF: 0xE953B
} CharacterParam;

// Size: 0x74, DWARF: 0xE9681
typedef struct CharacterState
{
    signed int secret; // Offset: 0x0, DWARF: 0xE969D
    unsigned int board; // Offset: 0x4, DWARF: 0xE96C0
    unsigned int course; // Offset: 0x8, DWARF: 0xE96E2
    signed int rem_point; // Offset: 0xC, DWARF: 0xE9705
    signed int old_brd_no; // Offset: 0x10, DWARF: 0xE972B
    signed int old_wear_no; // Offset: 0x14, DWARF: 0xE9752
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0xE977A
    signed int soft[8]; // Offset: 0x38, DWARF: 0xE97A3
    // Size: 0x1C, DWARF: 0xE944C
    CharacterParam parameter; // Offset: 0x58, DWARF: 0xE97C6
} CharacterState;

// Size: 0x8, DWARF: 0xE9FFC
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0, DWARF: 0xEA018
} CourseGap;

// Size: 0xEC, DWARF: 0xE9A03
typedef struct CreateCharacter
{
    // Size: 0x74, DWARF: 0xE9681
    CharacterState character; // Offset: 0x0, DWARF: 0xE9A1F
    // Size: 0x1C, DWARF: 0xE944C
    CharacterParam init_param; // Offset: 0x74, DWARF: 0xE9A47
    // Size: 0x18, DWARF: 0xEA03C
    Clock clock; // Offset: 0x90, DWARF: 0xE9A70
    char name[16]; // Offset: 0xA8, DWARF: 0xE9A94
    signed int age; // Offset: 0xB8, DWARF: 0xE9AB7
    signed int sex; // Offset: 0xBC, DWARF: 0xE9AD7
    signed int face; // Offset: 0xC0, DWARF: 0xE9AF7
    signed int hair; // Offset: 0xC4, DWARF: 0xE9B18
    signed int hair_color; // Offset: 0xC8, DWARF: 0xE9B39
    signed int body; // Offset: 0xCC, DWARF: 0xE9B60
    signed int body_color; // Offset: 0xD0, DWARF: 0xE9B81
    signed int pants; // Offset: 0xD4, DWARF: 0xE9BA8
    signed int pants_color; // Offset: 0xD8, DWARF: 0xE9BCA
    signed int glove; // Offset: 0xDC, DWARF: 0xE9BF2
    signed int boots; // Offset: 0xE0, DWARF: 0xE9C14
    signed int board_type; // Offset: 0xE4, DWARF: 0xE9C36
    signed int trick_type; // Offset: 0xE8, DWARF: 0xE9C5D
} CreateCharacter;

// Size: 0xEF8, DWARF: 0xE9D38
typedef struct VspenvSecret
{
    // Size: 0x74, DWARF: 0xE9681
    CharacterState character[12]; // Offset: 0x0, DWARF: 0xE9D54
    // Size: 0xEC, DWARF: 0xE9A03
    CreateCharacter create_character[10]; // Offset: 0x570, DWARF: 0xE9D7C
    // Size: 0x8, DWARF: 0xE9FFC
    CourseGap course[8]; // Offset: 0xEA8, DWARF: 0xE9DAB
    signed int tour_round; // Offset: 0xEE8, DWARF: 0xE9DD0
    signed int old_char; // Offset: 0xEEC, DWARF: 0xE9DF7
    signed int first_clear; // Offset: 0xEF0, DWARF: 0xE9E1C
} VspenvSecret;

// Size: 0x1668, DWARF: 0xE8771
typedef struct MemCard
{
    // Size: 0x38, DWARF: 0xE86A7
    File file; // Offset: 0x0, DWARF: 0xE878C
    // Size: 0x20, DWARF: 0xE85FC
    Record record[8][6]; // Offset: 0x38, DWARF: 0xE87AF
    // Size: 0x4, DWARF: 0xE8731
    BestTime best_time[8]; // Offset: 0x638, DWARF: 0xE87D4
    // Size: 0x114, DWARF: 0xE92BF
    VspenvOption option; // Offset: 0x658, DWARF: 0xE87FC
    // Size: 0xEF8, DWARF: 0xE9D38
    VspenvSecret secret; // Offset: 0x770, DWARF: 0xE8821
} MemCard;

// Size: 0x10, DWARF: 0xE9816
typedef struct BoardParam
{
    signed int speed; // Offset: 0x0, DWARF: 0xE9832
    signed int stability; // Offset: 0x4, DWARF: 0xE9854
    signed int balance; // Offset: 0x8, DWARF: 0xE987A
    signed int turning; // Offset: 0xC, DWARF: 0xE989E
} BoardParam;

// Size: 0x3C, DWARF: 0xE98EA
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0xE9906
    signed int player; // Offset: 0x4, DWARF: 0xE9925
    signed int wear; // Offset: 0x8, DWARF: 0xE9948
    signed int board; // Offset: 0xC, DWARF: 0xE9969
    // Size: 0x1C, DWARF: 0xE944C
    CharacterParam chr_param; // Offset: 0x10, DWARF: 0xE998B
    // Size: 0x10, DWARF: 0xE9816
    BoardParam brd_param; // Offset: 0x2C, DWARF: 0xE99B3
} Character;

// Size: 0x4, DWARF: 0xE9CF9
typedef struct Course
{
    signed int no; // Offset: 0x0, DWARF: 0xE9D15
} Course;

// Size: 0x18, DWARF: 0xE9E7C
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0xE9E98
    signed int game_mode; // Offset: 0x4, DWARF: 0xE9EBF
    signed int match_rule; // Offset: 0x8, DWARF: 0xE9EE5
    signed int divide; // Offset: 0xC, DWARF: 0xE9F0C
    signed int handicap[2]; // Offset: 0x10, DWARF: 0xE9F2F
} Mode;

// Size: 0xA0, DWARF: 0xE9586
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0xE9CF9
    Course course; // Offset: 0x0, DWARF: 0xE95A2
    // Size: 0x3C, DWARF: 0xE98EA
    Character character[2]; // Offset: 0x4, DWARF: 0xE95C7
    // Size: 0x18, DWARF: 0xE9E7C
    Mode mode; // Offset: 0x7C, DWARF: 0xE95EF
    signed int language; // Offset: 0x94, DWARF: 0xE9612
    signed int ending; // Offset: 0x98, DWARF: 0xE9637
    signed int bgm_no; // Offset: 0x9C, DWARF: 0xE965A
} VspenvGame;

// Size: 0x8, DWARF: 0xE8A12
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0xE8A2D
    signed char lh; // Offset: 0x2, DWARF: 0xE8A4D
    signed char lv; // Offset: 0x3, DWARF: 0xE8A6C
    signed int analog; // Offset: 0x4, DWARF: 0xE8A8B
} PadData;

// Size: 0x2DCEC, DWARF: 0xE8B10
typedef struct VspenvReplay
{
    // Size: 0x38, DWARF: 0xE86A7
    File file; // Offset: 0x0, DWARF: 0xE8B2B
    signed int pid; // Offset: 0x38, DWARF: 0xE8B4E
    signed int num_frame; // Offset: 0x3C, DWARF: 0xE8B6E
    unsigned int game_time; // Offset: 0x40, DWARF: 0xE8B94
    signed int endrun_frame; // Offset: 0x44, DWARF: 0xE8BBA
    // Size: 0x8, DWARF: 0xE8A12
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0xE8BE3
    // Size: 0x24, DWARF: 0xE884A
    KeyConfig key; // Offset: 0x2DB88, DWARF: 0xE8C0A
    // Size: 0xEC, DWARF: 0xE9A03
    CreateCharacter character; // Offset: 0x2DBAC, DWARF: 0xE8C2C
    // Size: 0x30, DWARF: 0xE8D58
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0xE8C54
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0xE8C79
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0xE8C9C
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0xE8CBF
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0xE8CE3
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0xE8D06
    // Size: 0x10, DWARF: 0xE9816
    BoardParam brd_param; // Offset: 0x2DCDC, DWARF: 0xE8D2C
} VspenvReplay;

// Size: 0x5D0E0, DWARF: 0xE8F5F
typedef struct VspenvEnv
{
    // Size: 0xA0, DWARF: 0xE9586
    VspenvGame game; // Offset: 0x0, DWARF: 0xE8F7B
    // Size: 0x1668, DWARF: 0xE8771
    MemCard mc; // Offset: 0xA0, DWARF: 0xE8F9E
    // Size: 0x2DCEC, DWARF: 0xE8B10
    VspenvReplay replay[2]; // Offset: 0x1708, DWARF: 0xE8FBF
} VspenvEnv;

// Size: 0x10
typedef struct AyTexData
{
    signed short x; // Offset: 0x0
    signed short y; // Offset: 0x2
    unsigned char pad[0xC]; // Offset: 0x4
} AyTexData;

// Size: 0x8
typedef struct AyMovieData
{
    unsigned int* addr; // Offset: 0x0
    signed int offset; // Offset: 0x4
} AyMovieData;

// Size: 0x20
typedef struct AyAlphaPkt
{
    __int128 q[2]; // Offset: 0x0
} AyAlphaPkt;

// Size: 0x20
typedef struct AyPolyPkt
{
    __int128 q[2]; // Offset: 0x0
} AyPolyPkt;

// Size: 0xE0, field offsets confirmed from aySetPolyComFT4's prologue
typedef struct AyPolyData
{
    signed int rgba[4]; // Offset: 0x0
    unsigned char pad0[0x30]; // Offset: 0x10
    signed int vert[16]; // Offset: 0x40
    signed int uv[4]; // Offset: 0x80
    signed int stq[16]; // Offset: 0x90
    AyTexData* texData; // Offset: 0xD0
    unsigned char pad1[0x4]; // Offset: 0xD4
    unsigned long flag; // Offset: 0xD8
} AyPolyData;

// Size: 0x10
typedef struct VgmsysPadInfo
{
    unsigned char pad[0x10]; // Offset: 0x0
} VgmsysPadInfo;

// Size: 0x10
typedef struct VspLocalGifPkt
{
    unsigned char pad[0x10]; // Offset: 0x0
} VspLocalGifPkt;

//// Function Declarations ///////////////////////////////////////////////////////////

void ayMovieModInit(signed int modnum);
static signed int ayMovieModFrame(signed int modnum);
static void ayMovieModEnd(signed int modnum, signed int unused1);

// Included functions ////////////////////////////////////////////////////////////////
void ulmov2InitMovie(void);
void ulmov2SetMovie_DRIVE(char* fname, unsigned char volume, void* addr, signed int tid);
signed int ulmov2IsPlaying(void);
void ulmov2SyncPlay(void);
void sploadFreeMovie(void);
void* sploadGetCommonOffset(void);
void ayMcSysInit(void);
void ayMcSysEnd(void);
void ulpadSetRepFrame(signed int frames);
signed int GetThreadId(void);
void FlushCache(signed int mode);
void ayFrameReset(void);
void ayFontInit(signed int x, signed int y, signed int* fcol);
signed int ayMcStartLoad(VspLocalGifPkt* packet);
void aySetVert(signed int* vert, float* xy, signed int z);
void aySetPolyComFT4(AyPolyPkt* poly, AyPolyData* data, signed int flg);
AyMovieData* sploadGetMovieData(void);
void ultexResetTex(signed int offset);
void ultexTransTexTag(VspLocalGifPkt* packet, unsigned int* addr, AyTexData* data, signed int no);
AyAlphaPkt* ulgifAddCNTReserve(VspLocalGifPkt* pkt, signed int qwc);
void ulpktInitALPHA(AyAlphaPkt* pkt, signed int ctext);
void ulgifTermPacket(VspLocalGifPkt* pkt);
void ulgifDmaSend(VspLocalGifPkt* pkt);
signed int ulpadGet(VgmsysPadInfo* info, signed int port, signed int slot);
void nmfontSetSize(signed int width, signed int height);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);
void nmfontFPrintF(VspLocalGifPkt* packet, char* str, float* pos);
void ulmov2PlayMovie(void);
signed int ulmov2GetState(void);
void ulmov2FlushMovie(void);
void ulmov2DeleteMovie(void);
void ulmov2CancelMovie(void);
signed int ulmov2GetMpegFrame(void);
signed int scePadRead(signed int port, signed int slot, unsigned char* data);
void sceGsSyncPath(signed int mode, unsigned short timeout);

//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0x5D0E0, DWARF: 0xE8F5F
extern VspenvEnv vspenvEnv; // Address: 0x3474D0
extern void(*vgmsysEndFunc)(signed int, signed int); // Address: 0x2E79AC
extern signed int(*vgmsysFrameFunc)(signed int); // Address: 0x2E79B0
extern VgmsysPadInfo* vgmsysPad[2]; // Address: 0x2E7B30
extern VspLocalGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
extern signed int vayNewCareer; // Address: 0x2E7BD0

// sbss is emitted in reverse declaration order, so these descend.

signed int vayMovKind; // Address: 0x2E7BE0
static signed int vayMovStep; // Address: 0x2E7BDC
static signed int vayMovCount; // Address: 0x2E7BD8

//// Function Definitions ////////////////////////////////////////////////////////////

// Address: 0x1B42F0
void ayMovieModInit(signed int modnum) {
    char** name;
    char* fname[18] = {
        "\\MOVIE\\O2.PSS",
        "\\MOVIE\\OPENING.PSS",
        "\\MOVIE\\CHR01.PSS",
        "\\MOVIE\\CHR02.PSS",
        "\\MOVIE\\CHR03.PSS",
        "\\MOVIE\\CHR04.PSS",
        "\\MOVIE\\CHR05.PSS",
        "\\MOVIE\\CHR06.PSS",
        "\\MOVIE\\CHR07.PSS",
        "\\MOVIE\\CHR08.PSS",
        "\\MOVIE\\CHR09.PSS",
        "\\MOVIE\\CHR10.PSS",
        "\\MOVIE\\CHR11.PSS",
        "\\MOVIE\\CHR12.PSS",
        "\\MOVIE\\CHR13.PSS",
        "\\MOVIE\\BAILS01.PSS",
        "\\MOVIE\\BAILS02.PSS",
        "\\MOVIE\\DEMO.PSS"
    }; // 0x30(sp)

    name = fname;
    ulmov2InitMovie();
    if (modnum == 0x16) {
        vayNewCareer = 0;
        vayMovStep = 0;
        vayMovCount = 0;
        ayMcSysInit();
        ulpadSetRepFrame(0xA);
    } else {
        signed int tid;

        ulmov2SetMovie_DRIVE(fname[vayMovKind],
                             (vspenvEnv.mc.option.volume.bgm * 200) / 255,
                             sploadGetCommonOffset(), GetThreadId());
        FlushCache(0);
        vayMovStep = 0;
        while (ulmov2IsPlaying() == 0) {
            ulmov2SyncPlay();
        }
    }
    vgmsysFrameFunc = &ayMovieModFrame;
    vgmsysEndFunc = &ayMovieModEnd;
}

// Address: 0x1B4460
static signed int ayMovieModFrame(signed int modnum) {
    signed int ret = modnum; // s5
    VgmsysPadInfo* pad = vgmsysPad[0]; // 0x2CC(sp)
    signed int col; // s6
    AyPolyPkt* poly; // 0x2D0(sp)
    AyAlphaPkt* alpha; // 0x2D4(sp)
    void* addr; // fp
    AyTexData texData; // 0xC0(sp)
    AyPolyData data; // 0xD0(sp)
    float xy[4]; // 0x1B0(sp)
    AyMovieData* loaddata; // s7
    unsigned char padData[32]; // 0x1C0(sp)
    unsigned int padVal; // s0
    unsigned int padFlg = 0xF7FF; // s3
    signed int step = 0; // s4
    {
        char* strList[3][16] = {
            {
                "{ 2001 ACTIVISION, INC. AND ITS AFFILIATES.",
                "PUBLISHED AND DISTRIBUTED BY ACTIVISION",
                "PUBLISHING, INC. DEVELOPED BY DEARSOFT CO., LTD.",
                "ACTIVISION IS A REGISTERED TRADEMARK AND",
                "ACTIVISION O2, SHAUN PALMER'S PRO SNOWBOARDER",
                "AND PRO SNOWBOARDER ARE TRADEMARKS OF",
                "ACTIVISION, INC. AND ITS AFFILIATES.",
                "ALL RIGHTS RESERVED.",
                "SHAUN PALMER IS A TRADEMARK OF SHAUN PALMER.",
                "ALL OTHER TRADEMARKS AND TRADE NAMES",
                "ARE THE PROPERTY OF THEIR RESPECTIVE OWNERS.",
            0,
            0,
            0,
            0,
            0
            },
            {
                "{ 2001 ACTIVISION, INC. UND DIE ZUGEH\222RIGEN",
                "UNTERNEHMEN. VER\222FFENTLICHUNG UND",
                "VERTRIEB DURCH ACTIVISION PUBLISHING, INC.",
                "ENTWICKELT VON DEARSOFT CO., LTD. ACTIVISION",
                "IST EIN EINGETRAGENES WARENZEICHEN UND",
                "ACTIVISION O2, SHAUN PALMER'S PRO SNOWBOARDER",
                "UND PRO SNOWBOARDER SIND WARENZEICHEN VON",
                "ACTIVISION, INC. UND DEN ZUGEH\222RIGEN",
                "UNTERNEHMEN. ALLE RECHTE VORBEHALTEN.",
                "SHAUN PALMER IST EIN WARENZEICHEN VON",
                "SHAUN PALMER. ALLE WEITEREN WARENZEICHEN UND",
                "HANDELSNAMEN SIND EIGENTUM DER",
                "JEWEILIGEN INHABER.",
            0,
            0,
            0
            },
            {
                "{ 2001 ACTIVISION, INC. ET SES FILIALES.",
                "PUBLIE ET DISTRIBUE PAR ACTIVISION",
                "PUBLISHING, INC. DEVELOPPE PAR DEARSOFT CO., LTD.",
                "ACTIVISION EST UNE MARQUE DEPOSEE ET",
                "ACTIVISION O2, SHAUN PALMER'S PRO SNOWBOARDER",
                "ET PRO SNOWBOARDER SONT DES MARQUES",
                "COMMERCIALES DE ACTIVISION, INC. ET SES FILIALES.",
                "TOUS DROITS RESERVES. SHAUN PALMER EST",
                "UNE MARQUE COMMERCIALE DE SHAUN PALMER.",
                "TOUTES LES AUTRES MARQUES ET TOUS LES",
                "NOMS DE MARQUES APPARTIENNENT A LEURS",
                "PROPRIETAIRES RESPECTIFS.",
            0,
            0,
            0,
            0
            }
        }; // 0x1E0(sp)
        s32* volatile ptr1 = (s32*)&strList;
        (void)ptr1;
        {
            char** str = strList[vspenvGame->language]; // s2
            signed int lnum[3] = { 11, 13, 12 }; // 0x2C0(sp)
            s32* volatile ptr2 = (s32*)&lnum;
            (void)ptr2;
            {
                float pos[4]; // 0x2A0(sp)
                signed int fcol[4] = { 0x80, 0x80, 0x80, 0x80 }; // 0x2B0(sp)
                s32* volatile ptr3 = (s32*)&fcol;
                (void)ptr3;
                {
                    signed int ii; // s1
                    signed int unused1;
                    signed int unused2;
                    float unused3;



                    if (modnum == 0x16) {
                        ayFrameReset();
                        switch (vayMovStep) {
                        case 0:
                            if (ayMcStartLoad(vgmsysGifPkt) == 1) {
                                vayMovStep = 10;
                            }
                            ulgifTermPacket(vgmsysGifPkt);
                            ulgifDmaSend(vgmsysGifPkt);
                            sceGsSyncPath(0, 0);
                            break;
                        case 10:
                            vayMovStep = 1;
                            ulgifTermPacket(vgmsysGifPkt);
                            ulgifDmaSend(vgmsysGifPkt);
                            sceGsSyncPath(0, 0);
                            break;
                        case 1:
                            addr = sploadGetCommonOffset();
                            ulmov2SetMovie_DRIVE("\\MOVIE\\O2.PSS",
                                                 (vspenvEnv.mc.option.volume.bgm * 200) / 255,
                                                 addr, GetThreadId());
                            FlushCache(0);
                            while (ulmov2IsPlaying() == 0) {
                                ulmov2SyncPlay();
                            }
                            vayMovStep = 2;
                            break;
                        case 2:
                            while (ulmov2GetState() >= 0) {
                                ulmov2PlayMovie();
                            }
                            ulmov2FlushMovie();
                            ulmov2DeleteMovie();
                            sceGsSyncPath(0, 0);
                            vayMovStep = 3;
                            ulpadGet(pad, 0, 0);
                            break;
                        case 6:
                            while (ulmov2GetState() >= 0) {
                                if (0xA < ulmov2GetMpegFrame()) {
                                    if (scePadRead(0, 0, padData) > 0) {
                                        padVal = (((unsigned int)padData[2] << 8) | padData[3]) ^ 0xFFFF;
                                    } else {
                                        padVal = 0;
                                    }
                                    if ((padVal & 0x800) || (padVal & padFlg)) {
                                        ulmov2CancelMovie();
                                        step = 1;
                                        break;
                                    }
                                }
                                ulmov2PlayMovie();
                            }
                            ulmov2FlushMovie();
                            ulmov2DeleteMovie();
                            sceGsSyncPath(0, 0);
                            ret = 1;
                            ulpadGet(pad, 0, 0);
                            break;
                        case 3:
                            if (vayMovCount < 0x20) {
                                col = vayMovCount * 4;
                            } else if (vayMovCount < 0x14C) {
                                col = 0x80;
                            } else {
                                col = (0x16C - vayMovCount) * 4;
                            }
                            loaddata = sploadGetMovieData();
                            ultexResetTex(loaddata->offset);
                            texData.x = -1;
                            texData.y = -1;
                            ultexTransTexTag(vgmsysGifPkt, loaddata->addr, &texData, 0);
                            addr = ulgifAddCNTReserve(vgmsysGifPkt, 9);
                            alpha = (AyAlphaPkt*)addr;
                            poly = (AyPolyPkt*)((char*)addr + 32);
                            ulpktInitALPHA(alpha, 1);
                            data.texData = &texData;
                            data.rgba[0] = 0x80;
                            data.rgba[1] = 0x80;
                            data.rgba[2] = 0x80;
                            unused1 = data.rgba[3] = col;
                            data.uv[0] = 0;
                            data.uv[1] = 0;
                            data.uv[2] = 0x200;
                            unused2 = data.uv[3] = 0x200;
                            xy[0] = 0.0f;
                            xy[1] = 0.0f;
                            xy[2] = 640.0f;
                            unused3 = xy[3] = 224.0f;
                            aySetVert(data.vert, xy, 1);
                            data.flag = 0x14;
                            aySetPolyComFT4(poly, &data, 1);
                            vayMovCount++;
                            if (vayMovCount == 0x16C) {
                                vayMovStep = 5;
                                vayMovCount = 0;
                            }
                            ulgifTermPacket(vgmsysGifPkt);
                            ulgifDmaSend(vgmsysGifPkt);
                            sceGsSyncPath(0, 0);
                            break;
                        case 5:
                            if (vayMovCount < 0x20) {
                                fcol[3] = vayMovCount * 4;
                            } else if (vayMovCount < 0x14C) {
                                fcol[3] = 0x80;
                            } else {
                                fcol[3] = (0x16C - vayMovCount) * 4;
                            }
                            ayFontInit(0x10, 0x10, fcol);
                            nmfontSetSize(0x10, 0x10);
                            pos[0] = 20.0f;
                            pos[2] = 16777215.0f;
                            pos[3] = 1.0f;
                            for (ii = 0; ii < lnum[vspenvGame->language]; ii++) {
                                pos[0] = 320.0f - nmfontGetPackStrLen(str[ii], 0x10, 0) / 2.0f;
                                pos[1] = 224.0f - lnum[vspenvGame->language] * 10.0f + ii * 20.0f;
                                nmfontFPrintF(vgmsysGifPkt, str[ii], pos);
                            }
                            vayMovCount++;
                            if (vayMovCount >= 0x16C) {
                                addr = sploadGetCommonOffset();
                                ulmov2SetMovie_DRIVE("\\MOVIE\\OPENING.PSS",
                                                     (vspenvEnv.mc.option.volume.bgm * 200) / 255,
                                                     addr, GetThreadId());
                                FlushCache(0);
                                while (ulmov2IsPlaying() == 0) {
                                    ulmov2SyncPlay();
                                }
                                vayMovStep = 6;
                                vayMovCount = 0;
                            }
                            ulgifTermPacket(vgmsysGifPkt);
                            ulgifDmaSend(vgmsysGifPkt);
                            sceGsSyncPath(0, 0);
                            break;
                        }
                    } else {
                        while (ulmov2GetState() >= 0) {
                            ulmov2PlayMovie();
                            if (0xA < ulmov2GetMpegFrame()) {
                                if (scePadRead(0, 0, padData) > 0) {
                                    padVal = (((unsigned int)padData[2] << 8) | padData[3]) ^ 0xFFFF;
                                } else {
                                    padVal = 0;
                                }
                                if ((padVal & 0x800) || (padVal & padFlg)) {
                                    ulmov2CancelMovie();
                                    break;
                                }
                            }
                        }
                        ulmov2FlushMovie();
                        ulmov2DeleteMovie();
                        sceGsSyncPath(0, 0);
                        ret = 1;
                    }
                    return ret;
                }
            }
        }
    }
}

// Address: 0x1B4DB0
static void ayMovieModEnd(signed int modnum, signed int unused1) {
    sploadFreeMovie();
    if (modnum == 0x16) {
        ayMcSysEnd();
    }
}
