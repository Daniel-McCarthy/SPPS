#include "common.h"
#include "types.h"

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// ayselect.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x4, DWARF: 0xE9CF9
typedef struct Course
{
    signed int no; // Offset: 0x0, DWARF: 0xE9D15
} Course;

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
} CharacterState; // Offset: 0x0, DWARF: 0xE9A1F

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

// Size: 0x4, DWARF: 0xE8731
typedef struct BestTime
{
    unsigned int time; // Offset: 0x0, DWARF: 0xE874C
} BestTime;

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

// Size: 0x8, DWARF: 0xE8AB2
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0xE8ACD
    signed int bgm; // Offset: 0x4, DWARF: 0xE8AEC
} Volume;

// Size: 0x48, DWARF: 0xE9155
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0, DWARF: 0xE9171
    signed int disable; // Offset: 0x40, DWARF: 0xE9195
    signed int random; // Offset: 0x44, DWARF: 0xE91B9
} Bgm;

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

// Size: 0x8, DWARF: 0xE9FFC
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0, DWARF: 0xEA018
} CourseGap;

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

// Size: 0x1690, DWARF: 0xE8489
typedef struct VaySelData
{
    signed int count; // Offset: 0x0, DWARF: 0xE84A4
    signed int bocount; // Offset: 0x4, DWARF: 0xE84C6
    signed int step; // Offset: 0x8, DWARF: 0xE84EA
    signed int nextMode; // Offset: 0xC, DWARF: 0xE850B
    signed int mode; // Offset: 0x10, DWARF: 0xE8530
    // Size: 0x1668, DWARF: 0xE8771
    MemCard mc; // Offset: 0x18, DWARF: 0xE8551
    signed int bgmdiff; // Offset: 0x1680, DWARF: 0xE8572
    signed int bgm; // Offset: 0x1684, DWARF: 0xE8596
    signed int vcID; // Offset: 0x1688, DWARF: 0xE85B6
    signed int vcTO; // Offset: 0x168C, DWARF: 0xE85D7
} VaySelData;

// Size: 0x10, DWARF: 0xE9204
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0, DWARF: 0xE9220
    __int128* pBase; // Offset: 0x4, DWARF: 0xE9248
    __int128* pDmaTag; // Offset: 0x8, DWARF: 0xE926D
    unsigned long* pGifTag; // Offset: 0xC, DWARF: 0xE9294
} VgmsysGifPkt;

// Size: 0x50, DWARF: 0xE900E
typedef struct CharacterScale
{
    signed int head; // Offset: 0x0, DWARF: 0xE902A
    signed int kid; // Offset: 0x4, DWARF: 0xE904B
    signed int cancel; // Offset: 0x8, DWARF: 0xE906B
    signed int pad; // Offset: 0xC, DWARF: 0xE908E
    float head_scale[4]; // Offset: 0x10, DWARF: 0xE90AE
    float hand_scale[4]; // Offset: 0x20, DWARF: 0xE90D7
    float kid_scale[4]; // Offset: 0x30, DWARF: 0xE9100
    float body_scale[4]; // Offset: 0x40, DWARF: 0xE9128
} CharacterScale;

//// Function Declarations ///////////////////////////////////////////////////////////

void aySelectModInit(signed int modnum);
static signed int aySelectModFrame(signed int modnum);
static void aySelectModEnd(int arg1, int arg2);
// Size: 0x50, DWARF: 0xE900E
static void aySetCharScale(CharacterScale* cheat);

// Included functions ////////////////////////////////////////////////////////////////
void* memcpy(void* dst, const void* src, unsigned int len);
void* ulMalloc(unsigned int size, signed int a, signed int b);
void ulFree(void* ptr);

//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0xA0, DWARF: 0xE9586
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x5D0E0, DWARF: 0xE8F5F
extern VspenvEnv vspenvEnv; // Address: 0x3474D0
extern void(*vgmsysEndFunc)(signed int, signed int); // Address: 0x2E79AC
extern signed int(*vgmsysFrameFunc)(signed int); // Address: 0x2E79B0
// Size: 0x114, DWARF: 0xE92BF
extern VspenvOption* vspenvOption; // Address: 0x2E7B10
// Size: 0x10, DWARF: 0xE9204
extern VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
// Size: 0x2DCEC, DWARF: 0xE8B10
extern VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
extern signed int vayNewCareer; // Address: 0x2E7BD0
// Size: 0xEF8, DWARF: 0xE9D38
extern VspenvSecret* vspenvSecret; // Address: 0x2E7B04

// sbss is emitted in reverse declaration order, so these descend.

signed int vayStateFlg; // Address: 0x2E7BB8
// Size: 0x1690, DWARF: 0xE8489
VaySelData* vaySelData; // Address: 0x2E7BB4

//// Function Definitions ////////////////////////////////////////////////////////////

void aySelectModInit(signed int modnum) {
    vaySelData = (VaySelData*)ulMalloc(0x1690, 0, 0);
    vaySelData->count = 0;
    if (vayStateFlg == -1) {
        vaySelData->bocount = -1;
        vaySelData->step = 0;
        vaySelData->nextMode = 0;
    } else {
        vaySelData->bocount = 0x20;
        vaySelData->step = 3;
        vaySelData->nextMode = 0x11;
    }
    vaySelData->bgmdiff = 0;
    vaySelData->bgm = vspenvEnv.mc.option.volume.bgm;
    nmbgmSetExterVol(vaySelData->bgm);
    vaySelData->vcID = -1;
    vaySelData->vcTO = 0;
    memcpy(&vaySelData->mc, &vspenvEnv.mc, 0x1668);
    vgmsysFrameFunc = &aySelectModFrame;
    vgmsysEndFunc = &aySelectModEnd;
    ayModeSelInit();
    ayCharSelInit();
    ayOptionInit();
    ayCreateInit();
    ulpadSetRepFrame(0xA);
    ulpadSetAnaRef(1);
    if (vayStateFlg != -1) {
        vayStateFlg = -1;
    }
    nmbgmSetOptNext(0);
    nmbgmChangeOption();
    nmvcSetExterVol(vspenvEnv.mc.option.volume.se);
    nmbgmSetExterVol(vspenvEnv.mc.option.volume.bgm);
    nmsqSetExterMVol(vspenvEnv.mc.option.volume.bgm);
    vspenvGame->bgm_no = -1;
}

static signed int aySelectModFrame(signed int modnum) {
    signed int temp_v0_2;
    signed int var_s5;

    // Size: 0x50, DWARF: 0xE900E
    signed int ii; // r16
    signed int chara; // r17
    signed int ret; // r18
    signed int mode; // r19
    signed int count; // r20
    signed int col; // r21
    CharacterScale cheat; // 0x70(r29)

    ret = modnum;
    ayFrameReset();
    switch (vaySelData->step) {
    case 0:
        mode = ayModeSelFrame();
        switch (mode) {
        case 11:
            cheat.head = vspenvOption->enable.big_head & vspenvOption->cheats.big_head;
            cheat.kid = vspenvOption->enable.kids & vspenvOption->cheats.kids;
            aySetCharScale(&cheat);
            vaySelData->bocount = 0;
            vaySelData->nextMode = 1;
            break;
        case 13:
            vaySelData->bocount = 0;
            vaySelData->nextMode = 3;
            break;
        case 14:
            cheat.head = 0;
            cheat.kid = 0;
            aySetCharScale(&cheat);
            vaySelData->bocount = 0;
            vaySelData->nextMode = 2;
            break;
        }
        break;
    case 1:
        mode = ayCharSelFrame();
        if (mode == 0xB) {
            vaySelData->bocount = 0;
            vaySelData->nextMode = mode;
            nmsndExitSel(0x20);
        } else if (mode == 0xC) {
            vaySelData->bocount = 0;
            vaySelData->nextMode = 0;
        }
        break;
    case 2:
        mode = ayCreateFrame();
        if (mode== 0xB) {
            vaySelData->bocount = 0;
            vaySelData->nextMode = 0;
        }
        break;
    case 3:
        // temp_v0_3 = ayOptionFrame(3);
        mode = ayOptionFrame();
        switch (mode) {
        case 11:
            vaySelData->bocount = 0;
            vaySelData->nextMode = 0;
            break;
        case 15:
        case 16:
        case 18:
            nmsndExitSel(0x20);
            vaySelData->bocount = 0;
            vaySelData->nextMode = mode;
            break;
        }
        break;
    }
    vaySelData->count = (vaySelData->count + 1) & 0xFFFFFF;
    if (vaySelData->bocount >= 0) {
        count = vaySelData->bocount;
        // if (count < 0x20) {
        //     var_s5 = count * 4;
        // } else {
        //     var_s5 = 0x80 - ((count - 0x20) * 4);
        // }
        if (count < 0x20) {
            col = count * 4;
        } else {
            col = 0x80 - ((count - 0x20) * 4);
        }
        // count = count < 0x20 ? count * 4 : 0x80 - ((count - 0x20) * 4);
        if ((vaySelData->bocount < 0x40) && ((vaySelData->bocount != 0x1F) || (vaySelData->nextMode != 0xF) || (nmsndCheckExit() != -1))) {
            vaySelData->bocount++;
        }
        ayBlackOutDraw(col);
        if (vaySelData->bocount == 0x20) {
            switch (vaySelData->nextMode) {
            case 0xB:
                switch (vspenvGame->mode.game_mode) {
                case 0:
                    ret = 2;
                    break;
                case 1:
                    ret = 3;
                    break;
                case 2:
                    ret = 4;
                    break;
                }
                memcpy((void*)&vspenvReplay[0]->key, (void*)&vspenvOption->key_config[0], 0x24);
                memcpy((void*)&vspenvReplay[1]->key, (void*)&vspenvOption->key_config[1], 0x24);
                aySetRepData(2);
                for (ii = 0; ii < 2; ii++) {
                    chara = vspenvGame->character[ii].no;
                    if (chara < 0xC) {
                        memcpy((void*)&vspenvReplay[ii]->character, &vspenvSecret->character[chara], 0x74);
                    } else {
                        chara -= 0xC;
                        memcpy((void*)&vspenvReplay[ii]->character, &vspenvSecret->create_character[chara], 0xEC);
                    }
                }
                vayNewCareer = 1;
                break;
            case 0xF:
                ret = 0x17;
                break;
            case 0x10:
                ret = 8;
                break;
            case 0x12:
                cheat.head = vspenvReplay[0]->cheats.big_head;
                cheat.kid = vspenvReplay[0]->cheats.kids;
                aySetCharScale(&cheat);
                ret = 5;
                break;
            case 0x13:
                cheat.head = vspenvReplay[0]->cheats.big_head;
                cheat.kid = vspenvReplay[0]->cheats.kids;
                aySetCharScale(&cheat);
                ret = 6;
                break;
            case 0x11:
                break;
            case 0xD:
                ret = 0xD;
                break;
            case 0: 
                if ((vaySelData->step == 1) && (vaySelData->mode == 1)) {
                    memcpy((void*)(&vspenvEnv.mc), (void*)&vaySelData->mc, 0x1668);
                }
                // break;
            default:
                vaySelData->step = (signed int) vaySelData->nextMode;
                vaySelData->count = 0;
                ayOptionClear();
                ayCharSelClear();
                ayCreateClear();
                break;
            }
        } else if (vaySelData->bocount == 0x40) {
            vaySelData->bocount = -1;
        }
    }
    if (vaySelData->bgmdiff < 0) {
        vaySelData->bgm += 3;
        if (0xFF < vaySelData->bgm) {
            vaySelData->bgm = 0xFF;
        }
        vaySelData->bgmdiff += 3;
        if (vaySelData->bgmdiff > 0) {
            vaySelData->bgmdiff = 0;
        }
        nmsqSetExterMVol(vaySelData->bgm);
    } else if (vaySelData->bgmdiff > 0) {
        vaySelData->bgm -= 3;
        if (vaySelData->bgm < 0) {
            vaySelData->bgm = 0;
        }
        vaySelData->bgmdiff -= 3;
        if (vaySelData->bgmdiff < 0) {
            vaySelData->bgmdiff = 0;
        }
        nmsqSetExterMVol(vaySelData->bgm);
    }
    ulgifTermPacket(vgmsysGifPkt);
    ulgifDmaSend(vgmsysGifPkt);
    sceGsSyncPath(0, 0);
    if (ret != modnum) {
        nmbgmSetSelectTbl(vspenvOption->bgm, vspenvOption->bgm.disable);
        nmbgmSetOptRand(vspenvOption->bgm.random);
        nmbgmChangeOption();
    }
    return ret;
}

static void aySelectModEnd(int arg1, int arg2) {
    ulpadSetAnaRef(0);
    sploadFreeSelect();
    ulFree(vaySelData);
    ayModeSelEnd();
    ayCharSelEnd();
    ayOptionEnd();
    ayCreateEnd();
}

static void aySetCharScale(CharacterScale* cheat) {
    float sp10;
    float sp14;
    float sp18;
    float sp1C;
    float sp20;
    float sp24;
    float sp28;
    float sp2C;

    if (cheat->head != 0) {
        cheat->head_scale[0] = 3.0f;
        cheat->head_scale[1] = 3.0f;
        cheat->head_scale[2] = 3.0f;
        sp10 = cheat->head_scale[3] = 1.0f;
    } else {
        cheat->head_scale[0] = 1.0f;
        cheat->head_scale[1] = 1.0f;
        cheat->head_scale[2] = 1.0f;
        sp14 = cheat->head_scale[3] = 1.0f;
    }
    if (cheat->kid != 0) {
        // Apply Kid cheat character scaling.
        cheat->hand_scale[0] = 2.0f;
        cheat->hand_scale[1] = 2.0f;
        cheat->hand_scale[2] = 2.0f;
        sp18 = cheat->hand_scale[3] = 1.0f;
        cheat->kid_scale[0] = 2.0f;
        cheat->kid_scale[1] = 2.0f;
        cheat->kid_scale[2] = 2.0f;
        sp1C = cheat->kid_scale[3] = 1.0f;
        cheat->body_scale[0] = 0.5f;
        cheat->body_scale[1] = 0.5f;
        cheat->body_scale[2] = 0.5f;
        sp20 = cheat->body_scale[3] = 1.0f;
    } else {
        cheat->hand_scale[0] = 1.0f;
        cheat->hand_scale[1] = 1.0f;
        cheat->hand_scale[2] = 1.0f;
        sp24 = cheat->hand_scale[3] = 1.0f;
        cheat->kid_scale[0] = 1.0f;
        cheat->kid_scale[1] = 1.0f;
        cheat->kid_scale[2] = 1.0f;
        sp28 = cheat->kid_scale[3] = 1.0f;
        cheat->body_scale[0] = 1.0f;
        cheat->body_scale[1] = 1.0f;
        cheat->body_scale[2] = 1.0f;
        sp2C = cheat->body_scale[3] = 1.0f;
    }
    maSetModelMode(cheat);
}
