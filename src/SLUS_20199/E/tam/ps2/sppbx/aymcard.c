#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi
#pragma dont_inline on

// SCE types ///////////////////////////////////////////////////////////////////////////
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// aymcard.c structs ///////////////////////////////////////////////////////////////////

// Size: 0x8
typedef struct Date
{
    unsigned char Resv2; // Offset: 0x0
    unsigned char Sec; // Offset: 0x1
    unsigned char Min; // Offset: 0x2
    unsigned char Hour; // Offset: 0x3
    unsigned char Day; // Offset: 0x4
    unsigned char Month; // Offset: 0x5
    unsigned short Year; // Offset: 0x6
} Date;

// Size: 0x40
typedef struct Table
{
    Date _Create; // Offset: 0x0
    Date _Modify; // Offset: 0x8
    unsigned int FileSizeByte; // Offset: 0x10
    unsigned short AttrFile; // Offset: 0x14
    unsigned short Reserve1; // Offset: 0x16
    unsigned int Reserve2; // Offset: 0x18
    unsigned int PdaAplNo; // Offset: 0x1C
    unsigned char EntryName[32]; // Offset: 0x20
} Table;

// Size: 0x3C4
typedef struct Is
{
    unsigned char Head[4]; // Offset: 0x0
    unsigned short Reserv1; // Offset: 0x4
    unsigned short OffsLF; // Offset: 0x6
    unsigned int Reserv2; // Offset: 0x8
    unsigned int TransRate; // Offset: 0xC
    signed int BgColor[4][4]; // Offset: 0x10
    float LightDir[3][4]; // Offset: 0x50
    float LightColor[3][4]; // Offset: 0x80
    float Ambient[4]; // Offset: 0xB0
    unsigned char TitleName[68]; // Offset: 0xC0
    unsigned char FnameView[64]; // Offset: 0x104
    unsigned char FnameCopy[64]; // Offset: 0x144
    unsigned char FnameDel[64]; // Offset: 0x184
    unsigned char Reserve3[512]; // Offset: 0x1C4
} Is;

// Size: 0x300
typedef struct VayMcFile
{
    signed int flg; // Offset: 0x0
    Table table[10] __attribute__((aligned(64))); // Offset: 0x40
    char* data; // Offset: 0x2C0
} VayMcFile;

// Size: 0x980
typedef struct VayMcSys
{
    Table table[10]; // Offset: 0x0
    signed int fileFlg[10]; // Offset: 0x280
    signed int fileID; // Offset: 0x2A8
    signed int fnum; // Offset: 0x2AC
    signed int newFile; // Offset: 0x2B0
    signed int year; // Offset: 0x2B4
    signed int month; // Offset: 0x2B8
    signed int day; // Offset: 0x2BC
    signed int hour; // Offset: 0x2C0
    signed int min; // Offset: 0x2C4
    signed int sec; // Offset: 0x2C8
    signed int step; // Offset: 0x2CC
    signed int process; // Offset: 0x2D0
    signed int count; // Offset: 0x2D4
    signed int retry; // Offset: 0x2D8
    signed int rewrite; // Offset: 0x2DC
    signed int memFlg; // Offset: 0x2E0
    signed int mes[3]; // Offset: 0x2E4
    signed int confFlg; // Offset: 0x2F0
    signed int confirm; // Offset: 0x2F4
    signed int select; // Offset: 0x2F8
    signed int nameCH; // Offset: 0x2FC
    signed int nameID; // Offset: 0x300
    Is icon; // Offset: 0x304
    VayMcFile* fdata; // Offset: 0x6C8
    char date[10][32]; // Offset: 0x6CC
    char name[10][32]; // Offset: 0x80C
    signed int capa; // Offset: 0x94C
    char* data; // Offset: 0x950
} VayMcSys;

// Size: 0x4
typedef struct Course
{
    signed int no; // Offset: 0x0
} Course;

// Size: 0x1C
typedef struct CharacterParams
{
    signed int ollie; // Offset: 0x0
    signed int spin; // Offset: 0x4
    signed int speed; // Offset: 0x8
    signed int landing; // Offset: 0xC
    signed int balance; // Offset: 0x10
    signed int stability; // Offset: 0x14
    signed int stance; // Offset: 0x18
} CharacterParams;

// Size: 0x10
typedef struct BoardParams
{
    signed int speed; // Offset: 0x0
    signed int stability; // Offset: 0x4
    signed int balance; // Offset: 0x8
    signed int turning; // Offset: 0xC
} BoardParams;

// Size: 0x3C
typedef struct CharacterConfiguration
{
    signed int no; // Offset: 0x0
    signed int player; // Offset: 0x4
    signed int wear; // Offset: 0x8
    signed int board; // Offset: 0xC
    CharacterParams chr_param; // Offset: 0x10
    BoardParams brd_param; // Offset: 0x2C
} CharacterConfiguration;

// Size: 0x18
typedef struct GameMode
{
    signed int num_player; // Offset: 0x0
    signed int game_mode; // Offset: 0x4
    signed int match_rule; // Offset: 0x8
    signed int divide; // Offset: 0xC
    signed int handicap[2]; // Offset: 0x10
} GameMode;

// Size: 0xA0
typedef struct VspenvGame
{
    Course course; // Offset: 0x0
    CharacterConfiguration character[2]; // Offset: 0x4
    GameMode mode; // Offset: 0x7C
    signed int language; // Offset: 0x94
    signed int ending; // Offset: 0x98
    signed int bgm_no; // Offset: 0x9C
} VspenvGame;

// Size: 0x18
typedef struct Clock
{
    signed int year; // Offset: 0x0
    signed int month; // Offset: 0x4
    signed int day; // Offset: 0x8
    signed int hour; // Offset: 0xC
    signed int minute; // Offset: 0x10
    signed int second; // Offset: 0x14
} Clock;

// Size: 0x38
typedef struct File
{
    Clock clock; // Offset: 0x0
    char name[32]; // Offset: 0x18
} File;

// Size: 0x20
typedef struct Record
{
    signed int chr_no; // Offset: 0x0
    unsigned long score; // Offset: 0x8
    char name[16]; // Offset: 0x10
} Record;

// Size: 0x4
typedef struct BestTime
{
    unsigned int time; // Offset: 0x0
} BestTime;

// Size: 0x24
typedef struct KeyConfig
{
    signed int vibration; // Offset: 0x0
    signed int spin_l; // Offset: 0x4
    signed int spin_r; // Offset: 0x8
    signed int stance; // Offset: 0xC
    signed int revert; // Offset: 0x10
    signed int grind; // Offset: 0x14
    signed int grab; // Offset: 0x18
    signed int jump; // Offset: 0x1C
    signed int flip; // Offset: 0x20
} KeyConfig;

// Size: 0x30
typedef struct Cheats
{
    signed int kids; // Offset: 0x0
    signed int always_sp; // Offset: 0x4
    signed int perfect_b; // Offset: 0x8
    signed int super_spin; // Offset: 0xC
    signed int half_g; // Offset: 0x10
    signed int fast_motion; // Offset: 0x14
    signed int super_speed; // Offset: 0x18
    signed int big_head; // Offset: 0x1C
    signed int metallic; // Offset: 0x20
    signed int mirror; // Offset: 0x24
    signed int replay_view; // Offset: 0x28
    signed int partition; // Offset: 0x2C
} Cheats;

// Size: 0x8
typedef struct Volume
{
    signed int se; // Offset: 0x0
    signed int bgm; // Offset: 0x4
} Volume;

// Size: 0x48
typedef struct Bgm
{
    signed int table[16]; // Offset: 0x0
    signed int disable; // Offset: 0x40
    signed int random; // Offset: 0x44
} Bgm;

// Size: 0x114
typedef struct VspenvOption
{
    KeyConfig key_config[2]; // Offset: 0x0
    Cheats enable; // Offset: 0x48
    Cheats cheats; // Offset: 0x78
    Volume volume; // Offset: 0xA8
    char name[16]; // Offset: 0xB0
    signed int divide; // Offset: 0xC0
    signed int tutorial; // Offset: 0xC4
    Bgm bgm; // Offset: 0xC8
    unsigned int movie; // Offset: 0x110
} VspenvOption;

// Size: 0x74
typedef struct CharacterState
{
    signed int secret; // Offset: 0x0
    unsigned int board; // Offset: 0x4
    unsigned int course; // Offset: 0x8
    signed int rem_point; // Offset: 0xC
    signed int old_brd_no; // Offset: 0x10
    signed int old_wear_no; // Offset: 0x14
    unsigned int level_goal[8]; // Offset: 0x18
    signed int soft[8]; // Offset: 0x38
    CharacterParams parameter; // Offset: 0x58
} CharacterState;

// Size: 0xEC
typedef struct CreateCharacter
{
    CharacterState character; // Offset: 0x0
    CharacterParams init_param; // Offset: 0x74
    Clock clock; // Offset: 0x90
    char name[16]; // Offset: 0xA8
    signed int age; // Offset: 0xB8
    signed int sex; // Offset: 0xBC
    signed int face; // Offset: 0xC0
    signed int hair; // Offset: 0xC4
    signed int hair_color; // Offset: 0xC8
    signed int body; // Offset: 0xCC
    signed int body_color; // Offset: 0xD0
    signed int pants; // Offset: 0xD4
    signed int pants_color; // Offset: 0xD8
    signed int glove; // Offset: 0xDC
    signed int boots; // Offset: 0xE0
    signed int board_type; // Offset: 0xE4
    signed int trick_type; // Offset: 0xE8
} CreateCharacter;

// Size: 0x8
typedef struct CourseGap
{
    unsigned long gap; // Offset: 0x0
} CourseGap;

// Size: 0xEF8
typedef struct VspenvSecret
{
    CharacterState character[12]; // Offset: 0x0
    CreateCharacter create_character[10]; // Offset: 0x570
    CourseGap course[8]; // Offset: 0xEA8
    signed int tour_round; // Offset: 0xEE8
    signed int old_char; // Offset: 0xEEC
    signed int first_clear; // Offset: 0xEF0
} VspenvSecret;

// Size: 0x1668
typedef struct MemCard
{
    File file; // Offset: 0x0
    Record record[8][6]; // Offset: 0x38
    BestTime best_time[8]; // Offset: 0x638
    VspenvOption option; // Offset: 0x658
    VspenvSecret secret; // Offset: 0x770
} MemCard;

// Size: 0x8
typedef struct Pad
{
    unsigned short cnt; // Offset: 0x0
    signed char lh; // Offset: 0x2
    signed char lv; // Offset: 0x3
    signed int analog; // Offset: 0x4
} Pad;

// Size: 0x2DCEC
typedef struct VspenvReplay
{
    File file; // Offset: 0x0
    signed int pid; // Offset: 0x38
    signed int num_frame; // Offset: 0x3C
    unsigned int game_time; // Offset: 0x40
    signed int endrun_frame; // Offset: 0x44
    Pad pad_data[23400]; // Offset: 0x48
    KeyConfig key; // Offset: 0x2DB88
    CreateCharacter character; // Offset: 0x2DBAC
    Cheats cheats; // Offset: 0x2DC98
    signed int crs_no; // Offset: 0x2DCC8
    signed int chr_no; // Offset: 0x2DCCC
    signed int wear_no; // Offset: 0x2DCD0
    signed int brd_no; // Offset: 0x2DCD4
    signed int game_mode; // Offset: 0x2DCD8
    BoardParams brd_param; // Offset: 0x2DCDC
} VspenvReplay;

// Size: 0x5D0E0
typedef struct VspenvEnv
{
    VspenvGame game; // Offset: 0x0
    MemCard mc; // Offset: 0xA0
    VspenvReplay replay[2]; // Offset: 0x1708
} VspenvEnv;

// Size: 0x20
typedef struct PadState
{
    signed int id; // Offset: 0x0
    unsigned int now; // Offset: 0x4
    unsigned int status; // Offset: 0x8
    unsigned int press; // Offset: 0xC
    signed char right_h; // Offset: 0x10
    signed char right_v; // Offset: 0x11
    signed char left_h; // Offset: 0x12
    signed char left_v; // Offset: 0x13
    unsigned char l_right; // Offset: 0x14
    unsigned char l_left; // Offset: 0x15
    unsigned char l_up; // Offset: 0x16
    unsigned char l_down; // Offset: 0x17
    unsigned char r_up; // Offset: 0x18
    unsigned char r_right; // Offset: 0x19
    unsigned char r_down; // Offset: 0x1A
    unsigned char r_left; // Offset: 0x1B
    unsigned char r_1; // Offset: 0x1C
    unsigned char l_1; // Offset: 0x1D
    unsigned char r_2; // Offset: 0x1E
    unsigned char l_2; // Offset: 0x1F
} PadState;

// Size: 0x60
typedef struct VgmsysPadInfo
{
    PadState now; // Offset: 0x0
    PadState old; // Offset: 0x20
    unsigned int port; // Offset: 0x40
    unsigned int slot; // Offset: 0x44
    unsigned int mode; // Offset: 0x48
    unsigned int trg; // Offset: 0x4C
    unsigned int rev; // Offset: 0x50
    unsigned int cnt; // Offset: 0x54
    unsigned int rep; // Offset: 0x58
    signed int state; // Offset: 0x5C
} VgmsysPadInfo;

// Size: 0x10
typedef struct VgmsysGifPkt
{
    unsigned int* pCurrent; // Offset: 0x0
    int128* pBase; // Offset: 0x4
    int128* pDmaTag; // Offset: 0x8
    unsigned long* pGifTag; // Offset: 0xC
} VgmsysGifPkt;

// Size: 0x20
typedef struct Info
{
    signed int type; // Offset: 0x0
    signed int format; // Offset: 0x4
    signed int capa; // Offset: 0x8
    signed int result; // Offset: 0xC
    signed int fnum; // Offset: 0x10
    signed int res[3]; // Offset: 0x14
} Info;

// Size: 0x1C
typedef struct VsploadIcon
{
    unsigned int* link; // Offset: 0x0
    unsigned int* system[3]; // Offset: 0x4
    unsigned int* replay[3]; // Offset: 0x10
} VsploadIcon;

// Size: 0x104
typedef struct McMessage
{
    char mes[4][64]; // Offset: 0x0
    signed int line; // Offset: 0x100
} McMessage;

// SCE includes /////////////////////////////////////////////////////////////////////
signed int strcmp(const char* s1, const char* s2);
signed int strlen(const char* s);
void* memcpy(void* dest, const void* src, unsigned int count);
signed int rand(void);
void spinitGetClock();
signed int ulstrAsciitoSjis(char* sjis, char* ascii);
VsploadIcon* sploadGetIconData();
signed int sceScfGetTimeNotation(void);
signed int sceScfGetDateNotation(void);

//// External function prototypes ////////////////////////////////////////////////////
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void ulFree(void* p);
signed int ulstdSprintf(char* buf, char* fmt, ...);
void ulmcSetUseSlot(signed int slot);
signed int ulmcGetFstat();
Info* ulmcGetCardInfo(signed int slot);
signed int ulmcGetInfo(signed int slot);
signed int ulmcChDir(signed int slot, char* path, char* pwd);
signed int ulmcGetDir(signed int slot, Table* table, char* filename, signed int mode, signed int max);
signed int ulmcLoad(signed int slot, char* filename, void* loadbuf, signed int size);
signed int ulmcSave(signed int slot, char* filename, void* savebuf, signed int size);
signed int ulmcIsExist(signed int slot, char* filename);
signed int ulmcDelete(signed int slot, char* filename);
signed int ulmcMkDir(signed int slot, char* dirname);
signed int ulmcFormat(signed int slot);
signed int ulmcDeleteAll(signed int slot);
void ulmcClearIconSys(Is* is, char* tname, char* fnview, char* fncopy, char* fndel);
void ayFontInitmin();
float ayCalcTotalMove(signed int frame, signed int count, float totalmove, signed int type);
void nmfontSetSize(signed int width, signed int height);
void nmfontSetPack(signed int pack);
void nmfontSetCol(signed int* col);
void nmfontFPrint(VgmsysGifPkt* packet, char* str, signed int x, signed int y);
signed int nmvcPlayButton(signed int num);
signed int nmvcPlayCursor(signed int num);
signed int nmsndFrame(signed int pause);
signed int sceGsSyncV(signed int mode);
signed int nmfontGetPackStrLen(char* str, signed int width, signed int type);
void nmfontFPrintF(VgmsysGifPkt* packet, char* str, float* pos);

//// Function Declarations ///////////////////////////////////////////////////////////

void ayMcSysInit(void);
static void ayMcSysClear(void);
static void ayMcUpdateFile(File* data);
signed int ayMcStartLoad(VgmsysGifPkt* packet);
void ayMcSetSaveFileID(void);
void ayMcSysEnd(void);
signed int ayMcGetStep(void);
signed int ayMcCareerLoad(VgmsysGifPkt* packet);
signed int ayMcReplayLoad(VgmsysGifPkt* packet, signed int unused);
signed int ayMcCareerSave(VgmsysGifPkt* packet);
signed int ayMcReplaySave(VgmsysGifPkt* packet);
void aySetRepData(signed int pnum);
void aySetGameData(signed int randFlg, signed int pnum);
static signed int ayMcMesDraw(VgmsysGifPkt* packet, signed int id, signed int line);
static void ayMcFileDraw(VgmsysGifPkt* packet, signed int count, signed int kind, signed int scr);
static signed int ayMcDrawEnterName(VgmsysGifPkt* packet, char* name);
void aySetTimeStr(char* str, File* data);

//// Variables ///////////////////////////////////////////////////////////////////////

extern VspenvEnv vspenvEnv; // Address: 0x3474D0
extern VgmsysGifPkt* vgmsysGifPkt; // Address: 0x2E79CC
extern VgmsysPadInfo* vgmsysPad[2]; // Address: 0x2E7B30
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
extern VspenvOption* vspenvOption; // Address: 0x2E7B10
extern VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
extern signed int vayStateFlg; // Address: 0x2E7BB8
extern signed int vayNewCareer; // Address: 0x2E7BD0
extern signed int vayDemoSwitch; // Address: 0x2E7BD4
char* vayCode[1] = {"BASLUS-20199"}; // Address: 0x2E77F4
VayMcSys* vayMcSys; // Address: 0x2E7BC4
signed int vayLoadFile; // Address: 0x2E7BC0
signed int vayTmpFile; // Address: 0x2E7BBC

//// Function Definitions ////////////////////////////////////////////////////////////

void ayMcSysInit(void) {
    vayMcSys = ulMalloc(0x980, 0, 0);
    vayMcSys->memFlg = 0;
    ayMcSysClear();
    ulmcSetUseSlot(0);
}

static void ayMcSysClear(void) {
    signed int ii; // r16

    vayMcSys->fileID = 0;
    vayMcSys->step = 0;
    vayMcSys->process = 0;
    vayMcSys->count = 0;
    vayMcSys->retry = 0;
    vayMcSys->newFile = -1;
    vayMcSys->mes[0] = vayMcSys->mes[1] = vayMcSys->mes[2] = -1;
    vayMcSys->confFlg = 0;
    vayMcSys->select = 0;
    for (ii = 0; ii < 10; ii++) {
        vayMcSys->fileFlg[ii] = 0;
    }
}

signed int ayMcStartLoad(VgmsysGifPkt* packet) {
    signed int ret = 0; // 0x124(r29)
    char name[64]; // 0xA0(r29)
    signed int fcol[2][4]; // 0xE0(r29)
    char* strList[3][2] = {{"YES", "NO"}, {"JA", "NEIN"}, {"OUI", "NON"}}; // 0x100(r29)
    char** str = strList[vspenvGame->language]; // 0x128(r29)
    char* loadname; // 0x12C(r29)
    signed int loadID; // 0x130(r29)
    signed int fstat = ulmcGetFstat(); // r22
    Info* info = ulmcGetCardInfo(0); // r21
    signed int* mes = &vayMcSys->mes[0]; // r17
    signed int ii; // r16
    Table* table; // r18
    signed int flg; // r19
    File* data; // r20
    signed int line; // r23

    switch (vayMcSys->step) {
    case 0:
        mes[0] = 0;
        mes[1] = 1;
        mes[2] = -1;
        if (fstat == -1) {
            ulmcGetInfo(0);
            vayMcSys->capa = 0x189;
            vayLoadFile = 0;
        } else if (fstat == 1) {
            if (info->fnum == 1) {
                if (info->type == 2) {
                    if (info->format == 1) {
                        vayMcSys->step = 1;
                    } else {
                        if (vayMcSys->retry == 2) {
                            vayMcSys->retry = 0;
                            vayMcSys->step = 5;
                            vayMcSys->confirm = 1;
                            mes[0] = 3;
                            mes[1] = 4;
                            mes[2] = -1;
                        } else {
                            vayMcSys->retry++;
                        }
                    }
                } else {
                    if (vayMcSys->retry == 2) {
                        vayMcSys->retry = 0;
                        vayMcSys->confirm = 1;
                        vayMcSys->step = 5;
                        mes[0] = 2;
                        mes[1] = 7;
                        mes[2] = 4;
                    } else {
                        vayMcSys->retry++;
                    }
                }
            }
        }
        break;
    case 1:
        if (fstat == -1) {
            ulstdSprintf(name, "%s%s*", vayCode[vspenvGame->language], "SPCR-");
            ulmcGetDir(0, vayMcSys->table, name, 0, 10);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < 0) {
                    vayMcSys->step = 5;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 7;
                    mes[2] = 4;
                } else if (info->result == 0) {
                    if (info->capa < vayMcSys->capa) {
                        vayMcSys->step = 5;
                        vayMcSys->confirm = 1;
                        mes[0] = 8;
                        mes[1] = 7;
                        mes[2] = 4;
                    } else {
                        ret = 1;
                    }
                } else {
                    vayMcSys->step = 2;
                    if (vayMcSys->memFlg == 1) {
                        for (ii = 0; ii < vayMcSys->fnum; ii++) {
                            ulFree(vayMcSys->fdata[ii].data);
                        }
                        ulFree(vayMcSys->fdata);
                        vayMcSys->memFlg = 0;
                    }
                    vayMcSys->fnum = info->result;
                    vayMcSys->fdata = ulMalloc(vayMcSys->fnum * 0x300, 0, 0);
                    for (ii = 0; ii < vayMcSys->fnum; ii++) {
                        vayMcSys->fdata[ii].data = ulMalloc(0x38, 0, 0);
                    }
                    vayMcSys->memFlg = 1;
                    vayMcSys->fileID = 0;
                    vayMcSys->newFile = -1;
                }
            }
        }
        break;
    case 2:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s/*", vayMcSys->table[vayMcSys->fileID].EntryName);
            ulmcGetDir(0, vayMcSys->fdata[vayMcSys->fileID].table, name, 0, 10);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < 0) {
                    vayMcSys->step = 5;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 7;
                    mes[2] = 4;
                } else {
                    vayMcSys->step = 3;
                }
            }
        }
        break;
    case 3:
        flg = 0;
        for (ii = 0; ii < 7; ii++) {
            table = &vayMcSys->fdata[vayMcSys->fileID].table[ii];
            if ((strcmp(table->EntryName, vayMcSys->table[vayMcSys->fileID].EntryName) == 0) && (table->FileSizeByte == 0x1668)) {
                flg++;
            } else if ((strcmp("icon.sys", table->EntryName) == 0) && (table->FileSizeByte == 0x3C4)) {
                flg++;
            } else if ((strcmp("alien1.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                flg++;
            } else if ((strcmp("alien2.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                flg++;
            } else if ((strcmp("alien3.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                flg++;
            }
        }
        if (flg == 5) {
            vayMcSys->step = 4;
        } else {
            vayMcSys->fileID++;
            if (vayMcSys->fileID == vayMcSys->fnum) {
                if (vayMcSys->newFile == -1) {
                    vayMcSys->step = 5;
                    vayMcSys->confirm = 1;
                    mes[0] = 5;
                    mes[1] = 4;
                    mes[2] = -1;
                } else {
                    vayMcSys->step = 6;
                }
            } else {
                vayMcSys->step = 2;
            }
        }
        break;
    case 4:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s/%s", (char*)vayMcSys->table[vayMcSys->fileID].EntryName, (char*)vayMcSys->table[vayMcSys->fileID].EntryName);
            ulmcLoad(0, name, vayMcSys->fdata[vayMcSys->fileID].data, 0x38);
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 5;
                vayMcSys->confirm = 1;
                mes[0] = 2;
                mes[1] = 7;
                mes[2] = 4;
            } else {
                data = (File*)vayMcSys->fdata[vayMcSys->fileID].data;
                if (vayMcSys->newFile == -1) {
                    ayMcUpdateFile(data);
                } else if (vayMcSys->year < data->clock.year) {
                    ayMcUpdateFile(data);
                } else if (vayMcSys->year == data->clock.year) {
                    if (vayMcSys->month < data->clock.month) {
                        ayMcUpdateFile(data);
                    } else if (vayMcSys->month == data->clock.month) {
                        if (vayMcSys->day < data->clock.day) {
                            ayMcUpdateFile(data);
                        } else if (vayMcSys->day == data->clock.day) {
                            if (vayMcSys->hour < data->clock.hour) {
                                ayMcUpdateFile(data);
                            } else if (vayMcSys->hour == data->clock.hour) {
                                if (vayMcSys->min < data->clock.minute) {
                                    ayMcUpdateFile(data);
                                } else if (vayMcSys->min == data->clock.minute) {
                                    if (vayMcSys->sec < data->clock.second) {
                                        ayMcUpdateFile(data);
                                    }
                                }
                            }
                        }
                    }
                }
                vayMcSys->fileID++;
                if (vayMcSys->fileID == vayMcSys->fnum) {
                    vayMcSys->step = 6;
                } else {
                    vayMcSys->step = 2;
                }
            }
        }
        break;
    case 5:
        if ((vgmsysPad[0]->rep & 0x8000) || (vgmsysPad[0]->rep & 0x2000)) {
            nmvcPlayCursor(1);
            vayMcSys->confirm ^= 1;
        } else if (vgmsysPad[0]->trg & 0x40) {
            if (vayMcSys->confirm == 0) {
                nmvcPlayButton(0);
                nmsndFrame(0);
                sceGsSyncV(0);
                ret = 1;
            } else {
                nmvcPlayButton(2);
                ayMcSysClear();
            }
        }
        ayFontInitmin();
        for (ii = 0; ii < 2; ii++) {
            if (ii == vayMcSys->confirm) {
                fcol[ii][0] = 0x80, fcol[ii][1] = 0x60, fcol[ii][2] = 0x40, fcol[ii][3] = 0x80;
            } else {
                fcol[ii][0] = 0x80, fcol[ii][1] = 0x80, fcol[ii][2] = 0x80, fcol[ii][3] = 0x80;
            }
        }
        nmfontSetCol(fcol[0]);
        nmfontFPrint(packet, str[0], 0x118, 0x130);
        nmfontSetCol(fcol[1]);
        nmfontFPrint(packet, str[1], 0x154, 0x130);
        break;
    case 6:
        loadname = vayMcSys->table[vayMcSys->newFile].EntryName;
        if (fstat == -1) {
            vayMcSys->data = ulMalloc(0x1668, 0, 0);
            ulstdSprintf(name, "/%s/%s", loadname, loadname);
            ulmcLoad(0, name, vayMcSys->data, 0x1668);
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 5;
                vayMcSys->confirm = 1;
                mes[0] = 2;
                mes[1] = 7;
                mes[2] = 4;
            } else {
                memcpy(&vspenvEnv.mc, vayMcSys->data, 0x1668);
                mes[0] = -1;
                ret = 1;
                vayNewCareer = 1;
                loadID = loadname[0x11] - 0x41;
                vayTmpFile = vayLoadFile = loadID;
            }
            ulFree(vayMcSys->data);
        }
        break;
    }
    for (ii = 0, line = 0; ii < 3; ii++) {
        if (mes[ii] == -1) {
            break;
        }
        line = ayMcMesDraw(packet, mes[ii], line);
    }
    if (ret == 1) {
        if (vayMcSys->memFlg == 1) {
            for (ii = 0; ii < vayMcSys->fnum; ii++) {
                ulFree(vayMcSys->fdata[ii].data);
            }
            ulFree(vayMcSys->fdata);
            vayMcSys->memFlg = 0;
        }
        vayStateFlg = -1;
        vayDemoSwitch = 0;
        ayMcSysClear();
    }
    return ret;
}

static void ayMcUpdateFile(File* data) {
    vayMcSys->newFile = vayMcSys->fileID;
    vayMcSys->year = data->clock.year;
    vayMcSys->month = data->clock.month;
    vayMcSys->day = data->clock.day;
    vayMcSys->hour = data->clock.hour;
    vayMcSys->min = data->clock.minute;
    vayMcSys->sec = data->clock.second;
}

signed int ayMcCareerLoad(VgmsysGifPkt* packet) {
    signed int ret = 0; // 0x138(r29)
    char name[64]; // 0xA0(r29)
    char* strList[3][3] = {{"CAREER A", "YES", "NO"}, {"KARRIERE A", "JA", "NEIN"}, {"CARRIERE A", "OUI", "NON"}}; // 0xE0(r29)
    char** str = strList[vspenvGame->language]; // r22
    signed int fcol[4]; // 0x110(r29)
    signed int len[3] = {7, 9, 9}; // 0x128(r29)
    File* data; // 0x13C(r29)
    signed int fstat = ulmcGetFstat(); // r21
    Info* info = ulmcGetCardInfo(0); // r19
    signed int* mes = &vayMcSys->mes[0]; // r17
    signed int ii; // r16
    Table* table; // r18
    signed int flg; // r20
    signed int line; // r23

    switch (vayMcSys->step) {
    case 0:
        mes[0] = 0;
        mes[1] = 1;
        mes[2] = -1;
        if (fstat == -1) {
            ulmcGetInfo(0);
        } else if (fstat == 1) {
            if (info->fnum == 1) {
                if (info->type == 2) {
                    if (info->format == 1) {
                        vayMcSys->step = 1;
                    } else {
                        if (vayMcSys->retry == 2) {
                            vayMcSys->retry = 0;
                            vayMcSys->step = 8;
                            vayMcSys->confirm = 1;
                            mes[0] = 3;
                            mes[1] = 0x17;
                            mes[2] = -1;
                        } else {
                            vayMcSys->retry++;
                        }
                    }
                } else {
                    if (vayMcSys->retry == 2) {
                        vayMcSys->retry = 0;
                        vayMcSys->step = 8;
                        vayMcSys->confirm = 1;
                        mes[0] = 2;
                        mes[1] = 0x17;
                        mes[2] = -1;
                    } else {
                        vayMcSys->retry++;
                    }
                }
            }
        }
        break;
    case 1:
        if (fstat == -1) {
            ulstdSprintf(name, "%s%s*", vayCode[vspenvGame->language], "SPCR-");
            ulmcGetDir(0, vayMcSys->table, name, 0, 10);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < -10) {
                    vayMcSys->step = 8;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result < 0) {
                    vayMcSys->step = 8;
                    vayMcSys->confirm = 1;
                    mes[0] = 9;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result == 0) {
                    vayMcSys->step = 8;
                    vayMcSys->confirm = 1;
                    mes[0] = 6;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else {
                    vayMcSys->step = 2;
                    vayMcSys->fnum = info->result;
                    if (vayMcSys->memFlg == 1) {
                        for (ii = 0; ii < 10; ii++) {
                            ulFree(vayMcSys->fdata[ii].data);
                        }
                        ulFree(vayMcSys->fdata);
                        vayMcSys->memFlg = 0;
                    }
                    vayMcSys->fdata = ulMalloc(0x1E00, 0, 1);
                    for (ii = 0; ii < 10; ii++) {
                        vayMcSys->fdata[ii].data = ulMalloc(0x38, 0, 1);
                    }
                    vayMcSys->memFlg = 1;
                    vayMcSys->fileID = 0;
                }
            }
        }
        break;
    case 2:
        if (fstat == -1) {
            ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
            ulmcIsExist(0, name);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < -10) {
                    vayMcSys->step = 8;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result < 0) {
                    vayMcSys->step = 8;
                    vayMcSys->confirm = 1;
                    mes[0] = 9;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result == 0) {
                    vayMcSys->fileFlg[vayMcSys->fileID] = 0;
                    str[0][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                    ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[0]);
                    vayMcSys->fileID++;
                    if (vayMcSys->fileID == 10) {
                        vayMcSys->step = 6;
                        ulmcSetUseSlot(1);
                    }
                } else {
                    vayMcSys->step = 3;
                }
            }
        }
        break;
    case 3:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/*", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
            ulmcGetDir(0, vayMcSys->fdata[vayMcSys->fileID].table, name, 0, 10);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < -10) {
                    vayMcSys->step = 8;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result < 0) {
                    vayMcSys->step = 8;
                    vayMcSys->confirm = 1;
                    mes[0] = 9;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else {
                    flg = 0;
                    ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
                    for (ii = 0; ii < 7; ii++) {
                        table = &vayMcSys->fdata[vayMcSys->fileID].table[ii];
                        if ((strcmp(name, table->EntryName) == 0) && (table->FileSizeByte == 0x1668)) {
                            flg++;
                        } else if ((strcmp("icon.sys", table->EntryName) == 0) && (table->FileSizeByte == 0x3C4)) {
                            flg++;
                        } else if ((strcmp("alien1.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("alien2.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("alien3.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        }
                    }
                    if (flg == 5) {
                        vayMcSys->step = 4;
                    } else {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 1;
                        str[0][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                        ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[0]);
                        vayMcSys->fileID++;
                        if (vayMcSys->fileID == 10) {
                            vayMcSys->step = 6;
                            ulmcSetUseSlot(1);
                        } else {
                            vayMcSys->step = 2;
                        }
                    }
                }
            }
        }
        break;
    case 4:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41, vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
            ulmcLoad(0, name, vayMcSys->fdata[vayMcSys->fileID].data, 0x38);
        } else if (fstat == 1) {
            if (info->result < -10) {
                vayMcSys->step = 8;
                vayMcSys->confirm = 1;
                mes[0] = 2;
                mes[1] = 0x17;
            } else if (info->result < 0) {
                vayMcSys->step = 8;
                vayMcSys->confirm = 1;
                mes[0] = 9;
                mes[1] = 0x17;
            } else {
                vayMcSys->fileFlg[vayMcSys->fileID] = 3;
                data = (File*)vayMcSys->fdata[vayMcSys->fileID].data;
                aySetTimeStr(vayMcSys->date[vayMcSys->fileID], data);
                ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", ((File*)vayMcSys->fdata[vayMcSys->fileID].data)->name);
                vayMcSys->fileID++;
                if (vayMcSys->fileID == 10) {
                    vayMcSys->step = 6;
                    ulmcSetUseSlot(1);
                } else {
                    vayMcSys->step = 2;
                }
            }
            mes[2] = -1;
        }
        break;
    case 5:
        vayMcSys->count++;
        if (vayMcSys->count == 0xB4) {
            ret = 2;
        }
        break;
    case 6:
        if (info->type != 2) {
            ulmcSetUseSlot(0);
            vayMcSys->step = 8;
            vayMcSys->confirm = 1;
            mes[0] = 2;
            mes[1] = 0x17;
            mes[2] = -1;
        } else {
            if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 9) {
                    vayMcSys->select = 0;
                } else {
                    vayMcSys->select++;
                }
            } else if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 0) {
                    vayMcSys->select = 9;
                } else {
                    vayMcSys->select--;
                }
            } else if (vgmsysPad[0]->trg & 0x40) {
                if (vayMcSys->fileFlg[vayMcSys->select] == 3) {
                    nmvcPlayButton(0);
                    vayMcSys->step = 7;
                    ulmcSetUseSlot(0);
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                ret = 2;
            }
            ayMcFileDraw(packet, 0, 0, 0);
        }
        break;
    case 7:
        if (fstat == -1) {
            vayMcSys->data = ulMalloc(0x1668, 0, 1);
            ulstdSprintf(name, "/%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41, vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41);
            ulmcLoad(0, name, vayMcSys->data, 0x1668);
            mes[0] = 0x16;
            mes[1] = 1;
            mes[2] = -1;
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 8;
                mes[0] = 9;
                mes[1] = 0x17;
                mes[2] = -1;
                vayMcSys->confirm = 1;
            } else {
                memcpy(&vspenvEnv.mc, vayMcSys->data, 0x1668);
                mes[0] = -1;
                ret = 1;
                vayNewCareer = 1;
                vayLoadFile = vayMcSys->select;
            }
            ulFree(vayMcSys->data);
        }
        break;
    case 8:
        if ((vgmsysPad[0]->rep & 0x8000) || (vgmsysPad[0]->rep & 0x2000)) {
            nmvcPlayCursor(1);
            vayMcSys->confirm ^= 1;
        } else if (vgmsysPad[0]->trg & 0x40) {
            if (vayMcSys->confirm == 0) {
                nmvcPlayButton(0);
                ret = 2;
            } else {
                nmvcPlayButton(2);
                ayMcSysClear();
            }
        }
        ayFontInitmin();
        for (ii = 0; ii < 2; ii++) {
            if (ii == vayMcSys->confirm) {
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            nmfontFPrint(packet, (char*)str[ii + 1], ii * 0x3C + 0x118, 0x158);
        }
        break;
    }
    if (vayMcSys->step != 6) {
        for (ii = 0, line = 0; ii < 3; ii++) {
            if (mes[ii] == -1) {
                break;
            }
            line = ayMcMesDraw(packet, mes[ii], line);
        }
    }
    if (ret > 0) {
        if (vayMcSys->memFlg == 1) {
            for (ii = 0; ii < 10; ii++) {
                ulFree(vayMcSys->fdata[ii].data);
            }
            ulFree(vayMcSys->fdata);
            vayMcSys->memFlg = 0;
        }
        ayMcSysClear();
    }
    return ret;
}

signed int ayMcCareerSave(VgmsysGifPkt* packet) {
    signed int ret = 0; // 0x164(r29)
    signed int fstat; // r21
    char name[64]; // 0xA0(r29)
    char uname[64]; // 0xE0(r29)
    signed int fcol[4]; // 0x120(r29)
    char* strList[3][3] = {{"CAREER A", "YES", "NO"}, {"KARRIERE A", "JA", "NEIN"}, {"CARRIERE A", "OUI", "NON"}}; // 0x130(r29)
    char** str = strList[vspenvGame->language]; // r22
    signed int len[3] = {7, 9, 9}; // 0x158(r29)
    char pwd = 0; // 0x1BF(r29)
    Info* info; // r19
    signed int* mes; // r16
    signed int nret; // 0x168(r29)
    char* fname; // 0x16C(r29)
    File* data; // 0x170(r29)
    MemCard* mc; // 0x174(r29)
    VsploadIcon* icondata; // 0x178(r29)
    signed int ii; // r17
    Table* table; // r18
    signed int flg; // r20
    signed int line; // r23
    fstat = ulmcGetFstat();
    info = ulmcGetCardInfo(0);
    mes = &vayMcSys->mes[0];

    switch (vayMcSys->step) {
    case 0:
        mes[0] = 0;
        mes[1] = 1;
        mes[2] = -1;
        if (fstat == -1) {
            ulmcGetInfo(0);
            vayMcSys->capa = 0x189;
            vayMcSys->fnum = 0;
        } else if (fstat == 1) {
            if (info->fnum == 1) {
                if (info->type == 2) {
                    if (info->format == 1) {
                        vayMcSys->step = 1;
                        if (vayMcSys->memFlg == 0) {
                            vayMcSys->fdata = ulMalloc(0x300, 0, 1);
                            vayMcSys->fdata->data = ulMalloc(0x38, 0, 1);
                            vayMcSys->memFlg = 1;
                        }
                        vayMcSys->fileID = 0;
                    } else {
                        if (vayMcSys->retry == 2) {
                            vayMcSys->retry = 0;
                            vayMcSys->step = 4;
                            vayMcSys->confirm = 1;
                            vayMcSys->confFlg = 1;
                            mes[0] = 3;
                            mes[1] = 0xB;
                            mes[2] = -1;
                        } else {
                            vayMcSys->retry++;
                        }
                    }
                } else {
                    if (vayMcSys->retry == 2) {
                        vayMcSys->retry = 0;
                        vayMcSys->step = 4;
                        vayMcSys->confirm = 1;
                        vayMcSys->confFlg = 0;
                        mes[0] = 2;
                        mes[1] = 7;
                        mes[2] = 0xC;
                    } else {
                        vayMcSys->retry++;
                    }
                }
            }
        }
        break;
    case 1:
        if (fstat == -1) {
            ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
            ulmcIsExist(0, name);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < 0) {
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 0;
                    mes[0] = 2;
                    mes[1] = 7;
                    mes[2] = 0xC;
                } else if (info->result == 0) {
                    if (info->capa < vayMcSys->capa) {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 2;
                    } else {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 0;
                    }
                    str[0][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                    ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[0]);
                    vayMcSys->fileID++;
                    if (vayMcSys->fileID == 10) {
                        if ((info->capa < vayMcSys->capa) && (vayMcSys->fnum == 0)) {
                            vayMcSys->step = 4;
                            vayMcSys->confFlg = 0;
                            vayMcSys->confirm = 1;
                            mes[0] = 8;
                            mes[1] = 7;
                            mes[2] = 0xC;
                        } else {
                            vayMcSys->step = 5;
                            ulmcSetUseSlot(1);
                            vayMcSys->select = vayLoadFile;
                        }
                    }
                } else {
                    vayMcSys->step = 2;
                    vayMcSys->fnum++;
                }
            }
        }
        break;
    case 2:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/*", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
            ulmcGetDir(0, vayMcSys->fdata->table, name, 0, 10);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < 0) {
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 0;
                    mes[0] = 2;
                    mes[1] = 7;
                    mes[2] = 0xC;
                } else if (info->result == 0) {
                    vayMcSys->fileFlg[vayMcSys->fileID] = 4;
                    str[0][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                    ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[0]);
                    vayMcSys->fileID++;
                    if (vayMcSys->fileID == 10) {
                        vayMcSys->step = 5;
                        ulmcSetUseSlot(1);
                        vayMcSys->select = vayLoadFile;
                    } else {
                        vayMcSys->step = 1;
                    }
                } else {
                    flg = 0;
                    ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
                    for (ii = 0; ii < 7; ii++) {
                        table = &vayMcSys->fdata->table[ii];
                        if ((strcmp(name, table->EntryName) == 0) && (table->FileSizeByte == 0x1668)) {
                            flg++;
                        } else if ((strcmp("icon.sys", table->EntryName) == 0) && (table->FileSizeByte == 0x3C4)) {
                            flg++;
                        } else if ((strcmp("alien1.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("alien2.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("alien3.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        }
                    }
                    if (flg == 5) {
                        vayMcSys->step = 3;
                    } else {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 1;
                        str[0][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                        ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[0]);
                        vayMcSys->fileID++;
                        if (vayMcSys->fileID == 10) {
                            vayMcSys->step = 5;
                            ulmcSetUseSlot(1);
                            vayMcSys->select = vayLoadFile;
                        } else {
                            vayMcSys->step = 1;
                        }
                    }
                }
            }
        }
        break;
    case 3:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41, vayCode[vspenvGame->language], "SPCR-", vayMcSys->fileID + 0x41);
            ulmcLoad(0, name, vayMcSys->fdata->data, 0x38);
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 4;
                vayMcSys->confirm = 1;
                vayMcSys->confFlg = 0;
                mes[0] = 2;
                mes[1] = 7;
                mes[2] = 0xC;
            } else {
                vayMcSys->fileFlg[vayMcSys->fileID] = 3;
                data = (File*)vayMcSys->fdata->data;
                aySetTimeStr(vayMcSys->date[vayMcSys->fileID], data);
                mc = (MemCard*)vayMcSys->fdata->data;
                ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", mc->file.name);
                vayMcSys->fileID++;
                if (vayMcSys->fileID == 10) {
                    vayMcSys->step = 5;
                    ulmcSetUseSlot(1);
                    vayMcSys->select = vayLoadFile;
                } else {
                    vayMcSys->step = 1;
                }
            }
            mes[2] = -1;
        }
        break;
    case 4:
        if ((vgmsysPad[0]->rep & 0x8000) || (vgmsysPad[0]->rep & 0x2000)) {
            nmvcPlayCursor(1);
            vayMcSys->confirm ^= 1;
        } else {
            switch (vayMcSys->confFlg) {
            case 0:
                if (vgmsysPad[0]->trg & 0x40) {
                    if (vayMcSys->confirm == 0) {
                        nmvcPlayButton(0);
                        ret = 1;
                    } else {
                        nmvcPlayButton(2);
                        ayMcSysClear();
                    }
                }
                break;
            case 1:
                if (info->type != 2) {
                    ulmcSetUseSlot(0);
                    mes[0] = 2;
                    mes[1] = 7;
                    mes[2] = 0xC;
                    vayMcSys->confFlg = 0;
                    vayMcSys->confirm = 1;
                } else if (vgmsysPad[0]->trg & 0x40) {
                    if (vayMcSys->confirm == 0) {
                        nmvcPlayButton(0);
                        vayMcSys->step = 6;
                        mes[0] = 0x13;
                        mes[1] = 1;
                    } else {
                        nmvcPlayButton(2);
                        mes[0] = 7;
                        mes[1] = 0xC;
                        vayMcSys->confFlg = 0;
                        vayMcSys->confirm = 1;
                    }
                }
                break;
            case 2:
            case 3:
                if (info->type != 2) {
                    ulmcSetUseSlot(0);
                    mes[0] = 2;
                    mes[1] = 7;
                    mes[2] = 0xC;
                    vayMcSys->confFlg = 0;
                    vayMcSys->confirm = 1;
                } else if (vgmsysPad[0]->trg & 0x40) {
                    if (vayMcSys->confirm == 0) {
                        nmvcPlayButton(0);
                        if (vayMcSys->confFlg == 2) {
                            vayMcSys->step = 0xA;
                            vayMcSys->rewrite = 1;
                            ulstdSprintf(vspenvEnv.mc.file.name, "%s", vayMcSys->name[vayMcSys->select]);
                            vayMcSys->nameID = strlen(vayMcSys->name[vayMcSys->select]);
                            for (ii = vayMcSys->nameID; ii < 0x11; ii++) {
                                vspenvEnv.mc.file.name[ii] = 0;
                            }
                            vayMcSys->nameCH = 0x26;
                            vayMcSys->count = 0;
                        } else {
                            mes[0] = 0x10;
                            mes[1] = 1;
                            mes[2] = -1;
                            vayMcSys->step = 8;
                            ulmcSetUseSlot(0);
                        }
                    } else {
                        nmvcPlayButton(2);
                        vayMcSys->step = 5;
                    }
                }
                break;
            }
        }
        ayFontInitmin();
        for (ii = 0; ii < 2; ii++) {
            if (ii == vayMcSys->confirm) {
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            nmfontFPrint(packet, (char*)str[ii + 1], ii * 0x3C + 0x118, 0x158);
        }
        break;
    case 5:
        if (info->type != 2) {
            ulmcSetUseSlot(0);
            vayMcSys->confFlg = 0;
            vayMcSys->confirm = 1;
            vayMcSys->step = 4;
            mes[0] = 2;
            mes[1] = 7;
            mes[2] = 0xC;
        } else {
            ayMcFileDraw(packet, 0, 0, 1);
            if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 9) {
                    vayMcSys->select = 0;
                } else {
                    vayMcSys->select++;
                }
            } else if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 0) {
                    vayMcSys->select = 9;
                } else {
                    vayMcSys->select--;
                }
            } else if (vgmsysPad[0]->trg & 0x40) {
                if (vayMcSys->fileFlg[vayMcSys->select] == 3) {
                    nmvcPlayButton(0);
                    mes[0] = 0x11;
                    mes[1] = -1;
                    mes[2] = -1;
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 2;
                } else if (vayMcSys->fileFlg[vayMcSys->select] == 0) {
                    nmvcPlayButton(0);
                    vayMcSys->step = 0xA;
                    vayMcSys->rewrite = 0;
                    ulstdSprintf(vspenvEnv.mc.file.name, "%s", vayMcSys->name[vayMcSys->select]);
                    vayMcSys->nameID = strlen(vayMcSys->name[vayMcSys->select]);
                    for (ii = vayMcSys->nameID; ii < 0x11; ii++) {
                        vspenvEnv.mc.file.name[ii] = 0;
                    }
                    vayMcSys->nameCH = 0x26;
                    vayMcSys->count = 0;
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[0]->trg & 0x20) {
                if ((vayMcSys->fileFlg[vayMcSys->select] == 3) || (vayMcSys->fileFlg[vayMcSys->select] == 1) || (vayMcSys->fileFlg[vayMcSys->select] == 4)) {
                    nmvcPlayButton(0);
                    mes[0] = 0x12;
                    mes[1] = -1;
                    mes[2] = -1;
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 3;
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                ret = 2;
            }
        }
        break;
    case 6:
        if (fstat == -1) {
            ulmcFormat(0);
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 4;
                vayMcSys->confirm = 1;
                vayMcSys->confFlg = 0;
                mes[0] = 0xD;
                mes[1] = 7;
                mes[2] = 0xC;
            } else {
                vayMcSys->step = 1;
                mes[0] = 0;
                mes[1] = 1;
                mes[2] = -1;
                vayLoadFile = vayTmpFile = 0;
            }
        }
        break;
    case 7:
        if (fstat == -1) {
            mes[0] = 0xF;
            mes[1] = 1;
            mes[2] = -1;
            ulstrAsciitoSjis(uname, vspenvEnv.mc.file.name);
            ulstdSprintf(name, "%s%s", "\202r\202o\202o\202r\201@\202b\202`\202q\202d\202d\202q\201@\201|\201@", uname);
            ulmcClearIconSys(&vayMcSys->icon, name, "alien1.ico", "alien2.ico", "alien3.ico");
            vayMcSys->icon.OffsLF = 0x1C;
            vayMcSys->icon.TransRate = 0x80;
            vayMcSys->icon.BgColor[0][0] = 0x20, vayMcSys->icon.BgColor[0][1] = 0x20, vayMcSys->icon.BgColor[0][2] = 0x20, vayMcSys->icon.BgColor[0][3] = 0x80;
            vayMcSys->icon.BgColor[1][0] = 0x20, vayMcSys->icon.BgColor[1][1] = 0x20, vayMcSys->icon.BgColor[1][2] = 0x20, vayMcSys->icon.BgColor[1][3] = 0x80;
            vayMcSys->icon.BgColor[2][0] = 0x60, vayMcSys->icon.BgColor[2][1] = 0x60, vayMcSys->icon.BgColor[2][2] = 0x60, vayMcSys->icon.BgColor[2][3] = 0x80;
            vayMcSys->icon.BgColor[3][0] = 0x60, vayMcSys->icon.BgColor[3][1] = 0x60, vayMcSys->icon.BgColor[3][2] = 0x60, vayMcSys->icon.BgColor[3][3] = 0x80;
            vayMcSys->icon.LightColor[0][0] = 0.0f, vayMcSys->icon.LightColor[0][1] = 0.0f, vayMcSys->icon.LightColor[0][2] = 0.0f, vayMcSys->icon.LightColor[0][3] = 0.0f;
            vayMcSys->icon.LightColor[1][0] = 0.0f, vayMcSys->icon.LightColor[1][1] = 0.0f, vayMcSys->icon.LightColor[1][2] = 0.0f, vayMcSys->icon.LightColor[1][3] = 0.0f;
            vayMcSys->icon.LightColor[2][0] = 0.0f, vayMcSys->icon.LightColor[2][1] = 0.0f, vayMcSys->icon.LightColor[2][2] = 0.0f, vayMcSys->icon.LightColor[2][3] = 0.0f;
            vayMcSys->icon.Ambient[0] = 0.0f, vayMcSys->icon.Ambient[1] = 0.0f, vayMcSys->icon.Ambient[2] = 0.0f, vayMcSys->icon.Ambient[3] = 0.0f;
            vayMcSys->icon.Ambient[0] = 0.5f, vayMcSys->icon.Ambient[1] = 0.5f, vayMcSys->icon.Ambient[2] = 0.5f, vayMcSys->icon.Ambient[3] = 0.5f;
            vayMcSys->icon.LightDir[0][0] = 0.0f, vayMcSys->icon.LightDir[0][1] = 0.0f, vayMcSys->icon.LightDir[0][2] = 1.0f, vayMcSys->icon.LightDir[0][3] = 1.0f;
            vayMcSys->icon.LightDir[1][0] = 0.0f, vayMcSys->icon.LightDir[1][1] = 0.0f, vayMcSys->icon.LightDir[1][2] = -1.0f, vayMcSys->icon.LightDir[1][3] = 1.0f;
            vayMcSys->icon.LightDir[2][0] = 0.0f, vayMcSys->icon.LightDir[2][1] = 1.0f, vayMcSys->icon.LightDir[2][2] = 0.0f, vayMcSys->icon.LightDir[2][3] = 1.0f;
            if (vayMcSys->rewrite != 0) {
                ulstdSprintf(name, "%s%s%c/icon.sys", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41);
                ulmcSave(0, name, &vayMcSys->icon, 0x3C4);
                vayMcSys->process = 4;
            } else {
                ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41);
                ulmcMkDir(0, name);
                vayMcSys->process = 0;
            }
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 4;
                vayMcSys->confirm = 1;
                vayMcSys->confFlg = 0;
                mes[0] = 0xA;
                mes[1] = 7;
                mes[2] = 0xC;
            } else {
                switch (vayMcSys->process) {
                case 0:
                    ulstdSprintf(name, "%s%s%c/icon.sys", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41);
                    ulmcSave(0, name, &vayMcSys->icon, 0x3C4);
                    vayMcSys->process++;
                    break;
                case 1:
                    icondata = sploadGetIconData();
                    ulstdSprintf(name, "%s%s%c/%s", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41, "alien1.ico");
                    ulmcSave(0, name, icondata->system[0], 0x1F818);
                    vayMcSys->process++;
                    break;
                case 2:
                    icondata = sploadGetIconData();
                    ulstdSprintf(name, "%s%s%c/%s", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41, "alien2.ico");
                    ulmcSave(0, name, icondata->system[1], 0x1F818);
                    vayMcSys->process++;
                    break;
                case 3:
                    icondata = sploadGetIconData();
                    ulstdSprintf(name, "%s%s%c/%s", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41, "alien3.ico");
                    ulmcSave(0, name, icondata->system[2], 0x1F818);
                    vayMcSys->process++;
                    break;
                case 4:
                    spinitGetClock();
                    ulstdSprintf(name, "%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41, vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41);
                    ulmcSave(0, name, &vspenvEnv.mc, 0x1668);
                    vayMcSys->process++;
                    break;
                case 5:
                    ret = 1;
                    vayTmpFile = vayLoadFile = vayMcSys->select;
                    break;
                }
            }
        }
        break;
    case 8:
        if (fstat == -1) {
            mes[0] = 0x10;
            mes[1] = 1;
            mes[2] = -1;
            ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41);
            if (vayMcSys->fileFlg[vayMcSys->select] == 4) {
                ulmcDelete(0, name);
                vayMcSys->process = 3;
            } else {
                ulmcChDir(0, name, &pwd);
                vayMcSys->process = 0;
            }
        } else if (fstat == 1) {
            if (info->result < -10) {
                vayMcSys->step = 9;
                mes[0] = 0xE;
                mes[1] = -1;
                mes[2] = -1;
            } else if (info->result < 0) {
                ulmcChDir(0, "/", &pwd);
                vayMcSys->process = 4;
            } else {
                switch (vayMcSys->process) {
                case 0:
                    ulmcDeleteAll(0);
                    vayMcSys->process++;
                    break;
                case 1:
                    ulmcChDir(0, "/", &pwd);
                    vayMcSys->process++;
                    break;
                case 2:
                    ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPCR-", vayMcSys->select + 0x41);
                    ulmcDelete(0, name);
                    vayMcSys->process++;
                    break;
                case 3:
                    vayLoadFile = vayMcSys->select;
                    ayMcSysClear();
                    break;
                case 4:
                    vayMcSys->step = 9;
                    mes[0] = 0xE;
                    mes[1] = -1;
                    mes[2] = -1;
                    break;
                }
            }
        }
        break;
    case 9:
        vayMcSys->count++;
        if (vayMcSys->count == 0xB4) {
            ayMcSysClear();
        }
        break;
    case 10:
        if (info->type != 2) {
            ulmcSetUseSlot(0);
            mes[0] = 2;
            mes[1] = 7;
            mes[2] = 0xC;
            vayMcSys->confFlg = 0;
            vayMcSys->confirm = 1;
            vayMcSys->step = 4;
        } else {
            fname = vspenvEnv.mc.file.name;
            nret = ayMcDrawEnterName(packet, fname);
            if (nret == 1) {
                ulmcSetUseSlot(0);
                vayMcSys->step = 7;
            } else if (nret == -1) {
                vayMcSys->step = 5;
            }
        }
        break;
    }
    if ((vayMcSys->step != 5) && (vayMcSys->step != 0xA)) {
        for (ii = 0, line = 0; ii < 3; ii++) {
            if (mes[ii] == -1) {
                break;
            }
            line = ayMcMesDraw(packet, mes[ii], line);
        }
    }
    if (ret > 0) {
        vayLoadFile = vayTmpFile;
        if (vayMcSys->memFlg == 1) {
            ulFree(vayMcSys->fdata->data);
            ulFree(vayMcSys->fdata);
            vayMcSys->memFlg = 0;
        }
        ayMcSysClear();
    }
    return ret;
}

void ayMcSetSaveFileID(void) {
    vayTmpFile = vayLoadFile;
}

signed int ayMcReplayLoad(VgmsysGifPkt* packet, signed int unused) {
    signed int ret = 0; // 0x134(r29)
    char name[64]; // 0xA0(r29)
    char* strList[3][3] = {{"YES", "NO", "REPLAY A"}, {"JA", "NEIN", "WIEDERHOLUNG A"}, {"OUI", "NON", "LIRE LA VIDEO A"}}; // 0xE0(r29)
    char** str = strList[vspenvGame->language]; // r22
    signed int fcol[4]; // 0x110(r29)
    signed int len[3] = {7, 13, 14}; // 0x128(r29)
    File* data; // 0x138(r29)
    signed int fstat = ulmcGetFstat(); // r21
    Info* info = ulmcGetCardInfo(0); // r19
    signed int* mes = &vayMcSys->mes[0]; // r17
    signed int ii; // r16
    Table* table; // r18
    signed int flg; // r20
    signed int line; // r23
    signed int size; // r30

    switch (vayMcSys->step) {
    case 0:
        mes[0] = 0;
        mes[1] = 1;
        mes[2] = -1;
        if (fstat == -1) {
            ulmcGetInfo(0);
        } else if (fstat == 1) {
            if (info->fnum == 1) {
                if (info->type == 2) {
                    if (info->format == 1) {
                        vayMcSys->step = 1;
                    } else {
                        if (vayMcSys->retry == 2) {
                            vayMcSys->retry = 0;
                            vayMcSys->step = 9;
                            vayMcSys->confirm = 1;
                            mes[0] = 3;
                            mes[1] = 0x17;
                            mes[2] = -1;
                        } else {
                            vayMcSys->retry++;
                        }
                    }
                } else {
                    if (vayMcSys->retry == 2) {
                        vayMcSys->retry = 0;
                        vayMcSys->step = 9;
                        vayMcSys->confirm = 1;
                        mes[0] = 2;
                        mes[1] = 0x17;
                        mes[2] = -1;
                    } else {
                        vayMcSys->retry++;
                    }
                }
            }
        }
        break;
    case 1:
        if (fstat == -1) {
            ulstdSprintf(name, "%s%s*", vayCode[vspenvGame->language], "SPREP-");
            ulmcGetDir(0, vayMcSys->table, name, 0, 5);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < -10) {
                    vayMcSys->step = 9;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result < 0) {
                    vayMcSys->step = 9;
                    vayMcSys->confirm = 1;
                    mes[0] = 9;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result == 0) {
                    vayMcSys->step = 9;
                    vayMcSys->confirm = 1;
                    mes[0] = 0x14;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else {
                    vayMcSys->step = 2;
                    vayMcSys->fnum = info->result;
                    if (vayMcSys->memFlg == 1) {
                        for (ii = 0; ii < 5; ii++) {
                            ulFree(vayMcSys->fdata[ii].data);
                        }
                        ulFree(vayMcSys->fdata);
                        vayMcSys->memFlg = 0;
                    }
                    vayMcSys->fdata = ulMalloc(0xF00, 0, 1);
                    for (ii = 0; ii < 5; ii++) {
                        vayMcSys->fdata[ii].data = ulMalloc(0x2DCEC, 0, 1);
                    }
                    vayMcSys->memFlg = 1;
                    vayMcSys->fileID = 0;
                }
            }
        }
        break;
    case 2:
        if (fstat == -1) {
            ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
            ulmcIsExist(0, name);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < -10) {
                    vayMcSys->step = 9;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result < 0) {
                    vayMcSys->step = 9;
                    vayMcSys->confirm = 1;
                    mes[0] = 9;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result == 0) {
                    vayMcSys->fileFlg[vayMcSys->fileID] = 0;
                    str[2][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                    ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[2]);
                    vayMcSys->fileID++;
                    if (vayMcSys->fileID == 5) {
                        vayMcSys->step = 6;
                        ulmcSetUseSlot(1);
                    }
                } else {
                    vayMcSys->step = 3;
                }
            }
        }
        break;
    case 3:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/*", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
            ulmcGetDir(0, vayMcSys->fdata[vayMcSys->fileID].table, name, 0, 10);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < -10) {
                    vayMcSys->step = 9;
                    vayMcSys->confirm = 1;
                    mes[0] = 2;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else if (info->result < 0) {
                    vayMcSys->step = 9;
                    vayMcSys->confirm = 1;
                    mes[0] = 9;
                    mes[1] = 0x17;
                    mes[2] = -1;
                } else {
                    flg = 0;
                    ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
                    for (ii = 0; ii < 7; ii++) {
                        table = &vayMcSys->fdata[vayMcSys->fileID].table[ii];
                        if (strcmp(name, table->EntryName) == 0) {
                            size = 0x2DCEC;
                            if ((strcmp(name, table->EntryName) == 0) && (table->FileSizeByte == size)) {
                                flg++;
                            }
                        } else if ((strcmp("icon.sys", table->EntryName) == 0) && (table->FileSizeByte == 0x3C4)) {
                            flg++;
                        } else if ((strcmp("sman1.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("sman2.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("sman3.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        }
                    }
                    if (flg == 5) {
                        vayMcSys->step = 4;
                    } else {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 1;
                        str[2][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                        ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[2]);
                        vayMcSys->fileID++;
                        if (vayMcSys->fileID == 5) {
                            vayMcSys->step = 6;
                            ulmcSetUseSlot(1);
                        } else {
                            vayMcSys->step = 2;
                        }
                    }
                }
            }
        }
        break;
    case 4:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41, vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
            ulmcLoad(0, name, vayMcSys->fdata[vayMcSys->fileID].data, 0x38);
        } else if (fstat == 1) {
            if (info->result < -10) {
                vayMcSys->step = 9;
                vayMcSys->confirm = 1;
                mes[0] = 2;
                mes[1] = 0x17;
            } else if (info->result < 0) {
                vayMcSys->step = 9;
                vayMcSys->confirm = 1;
                mes[0] = 9;
                mes[1] = 0x17;
            } else {
                vayMcSys->fileFlg[vayMcSys->fileID] = 3;
                data = (File*)vayMcSys->fdata[vayMcSys->fileID].data;
                aySetTimeStr(vayMcSys->date[vayMcSys->fileID], data);
                ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", ((File*)vayMcSys->fdata[vayMcSys->fileID].data)->name);
                vayMcSys->fileID++;
                if (vayMcSys->fileID == 5) {
                    vayMcSys->step = 6;
                    ulmcSetUseSlot(1);
                } else {
                    vayMcSys->step = 2;
                }
            }
            mes[2] = -1;
        }
        break;
    case 5:
        vayMcSys->count++;
        if (vayMcSys->count == 0xB4) {
            ret = 1;
        }
        break;
    case 6:
        if (info->type != 2) {
            ulmcSetUseSlot(0);
            vayMcSys->step = 9;
            vayMcSys->confirm = 1;
            mes[0] = 2;
            mes[1] = 0x17;
            mes[2] = -1;
        } else {
            if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 4) {
                    vayMcSys->select = 0;
                } else {
                    vayMcSys->select++;
                }
            } else if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 0) {
                    vayMcSys->select = 4;
                } else {
                    vayMcSys->select--;
                }
            } else if (vgmsysPad[0]->trg & 0x40) {
                if (vayMcSys->fileFlg[vayMcSys->select] == 3) {
                    nmvcPlayButton(0);
                    vayMcSys->step = 8;
                    ulmcSetUseSlot(0);
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                ret = 1;
            }
            ayMcFileDraw(packet, 0, 1, 0);
        }
        break;
    case 8:
        if (fstat == -1) {
            vayMcSys->data = ulMalloc(0x2DCEC, 0, 0);
            ulstdSprintf(name, "/%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41, vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41);
            ulmcLoad(0, name, vayMcSys->data, 0x2DCEC);
            mes[0] = 0x16;
            mes[1] = 1;
            mes[2] = -1;
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 9;
                mes[0] = 9;
                mes[1] = 0x17;
                mes[2] = -1;
                vayMcSys->confirm = 1;
            } else {
                aySetGameData(0, 1);
                ret = 2;
                mes[0] = -1;
            }
            ulFree(vayMcSys->data);
        }
        break;
    case 9:
        if ((vgmsysPad[0]->rep & 0x8000) || (vgmsysPad[0]->rep & 0x2000)) {
            nmvcPlayCursor(1);
            vayMcSys->confirm ^= 1;
        } else if (vgmsysPad[0]->trg & 0x40) {
            if (vayMcSys->confirm == 0) {
                nmvcPlayButton(0);
                ret = 1;
            } else {
                nmvcPlayButton(2);
                ayMcSysClear();
            }
        }
        ayFontInitmin();
        for (ii = 0; ii < 2; ii++) {
            if (ii == vayMcSys->confirm) {
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            nmfontFPrint(packet, (char*)str[ii], ii * 0x3C + 0x118, 0x158);
        }
        break;
    }
    if (vayMcSys->step != 6) {
        for (ii = 0, line = 0; ii < 3; ii++) {
            if (mes[ii] == -1) {
                break;
            }
            line = ayMcMesDraw(packet, mes[ii], line);
        }
    }
    if (ret > 0) {
        if (vayMcSys->memFlg) {
            for (ii = 0; ii < 5; ii++) {
                ulFree(vayMcSys->fdata[ii].data);
            }
            ulFree(vayMcSys->fdata);
            vayMcSys->memFlg = 0;
        }
        ayMcSysClear();
    }
    return ret;
}

signed int ayMcReplaySave(VgmsysGifPkt* packet) {
    signed int fstat; // r21
    signed int flg; // r20
    signed int ret = 0; // 0x168(r29)
    signed int nret; // 0x16C(r29)
    signed int* mes; // r16
    Info* info; // r19
    char name[64]; // 0xA0(r29)
    char uname[64]; // 0xE0(r29)
    char* fname; // 0x170(r29)
    Table* table; // r18
    File* data; // 0x174(r29)
    signed int ii; // r17
    signed int line; // r23
    signed int fcol[4]; // 0x120(r29)
    VsploadIcon* icondata; // 0x178(r29)
    char pwd = 0; // 0x1BF(r29)
    char* strList[3][3] = {{"YES", "NO", "REPLAY A"}, {"JA", "NEIN", "WIEDERHOLUNG A"}, {"OUI", "NON", "LIRE LA VIDEO A"}}; // 0x130(r29)
    char** str = strList[vspenvGame->language]; // r22
    signed int len[3] = {7, 13, 14}; // 0x158(r29)
    fstat = ulmcGetFstat();
    info = ulmcGetCardInfo(0);
    mes = &vayMcSys->mes[0];

    switch (vayMcSys->step) {
    case 0:
        mes[0] = 0;
        mes[1] = 1;
        mes[2] = -1;
        if (fstat == -1) {
            ulmcGetInfo(0);
            vayMcSys->capa = 0x23B;
            vayMcSys->fnum = 0;
        } else if (fstat == 1) {
            if (info->fnum == 1) {
                if (info->type == 2) {
                    if (info->format == 1) {
                        vayMcSys->step = 1;
                        if (vayMcSys->memFlg == 0) {
                            vayMcSys->fdata = ulMalloc(0x300, 0, 0);
                            vayMcSys->fdata->data = ulMalloc(0x2DCEC, 0, 0);
                            vayMcSys->memFlg = 1;
                        }
                        vayMcSys->fileID = 0;
                    } else {
                        if (vayMcSys->retry == 2) {
                            vayMcSys->retry = 0;
                            vayMcSys->step = 4;
                            vayMcSys->confirm = 1;
                            vayMcSys->confFlg = 1;
                            mes[0] = 3;
                            mes[1] = 0xB;
                            mes[2] = -1;
                        } else {
                            vayMcSys->retry++;
                        }
                    }
                } else {
                    if (vayMcSys->retry == 2) {
                        vayMcSys->retry = 0;
                        vayMcSys->step = 4;
                        vayMcSys->confirm = 1;
                        vayMcSys->confFlg = 0;
                        mes[0] = 2;
                        mes[1] = 0x15;
                        mes[2] = 0xC;
                    } else {
                        vayMcSys->retry++;
                    }
                }
            }
        }
        break;
    case 1:
        if (fstat == -1) {
            ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
            ulmcIsExist(0, name);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < 0) {
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 0;
                    mes[0] = 2;
                    mes[1] = 0x15;
                    mes[2] = 0xC;
                } else if (info->result == 0) {
                    if (info->capa < vayMcSys->capa) {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 2;
                    } else {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 0;
                    }
                    str[2][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                    ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[2]);
                    vayMcSys->fileID++;
                    if (vayMcSys->fileID == 5) {
                        if ((info->capa < vayMcSys->capa) && (vayMcSys->fnum == 0)) {
                            vayMcSys->step = 4;
                            vayMcSys->confFlg = 0;
                            vayMcSys->confirm = 1;
                            mes[0] = 8;
                            mes[1] = 0x15;
                            mes[2] = 0xC;
                        } else {
                            vayMcSys->step = 5;
                            ulmcSetUseSlot(1);
                                                    }
                    }
                } else {
                    vayMcSys->step = 2;
                    vayMcSys->fnum++;
                }
            }
        }
        break;
    case 2:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/*", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
            ulmcGetDir(0, vayMcSys->fdata->table, name, 0, 10);
        } else if (fstat == 1) {
            if (info->fnum == 0xD) {
                if (info->result < 0) {
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 0;
                    mes[0] = 2;
                    mes[1] = 0x15;
                    mes[2] = 0xC;
                } else if (info->result == 0) {
                    vayMcSys->fileFlg[vayMcSys->fileID] = 4;
                    str[0][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                    ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[2]);
                    vayMcSys->fileID++;
                    if (vayMcSys->fileID == 5) {
                        vayMcSys->step = 5;
                        ulmcSetUseSlot(1);
                                            } else {
                        vayMcSys->step = 1;
                    }
                } else {
                    flg = 0;
                    ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
                    for (ii = 0; ii < 7; ii++) {
                        table = &vayMcSys->fdata->table[ii];
                        if ((strcmp(name, table->EntryName) == 0) && (table->FileSizeByte == 0x2DCEC)) {
                            flg++;
                        } else if ((strcmp("icon.sys", table->EntryName) == 0) && (table->FileSizeByte == 0x3C4)) {
                            flg++;
                        } else if ((strcmp("sman1.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("sman2.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        } else if ((strcmp("sman3.ico", table->EntryName) == 0) && (table->FileSizeByte == 0x1F818)) {
                            flg++;
                        }
                    }
                    if (flg == 5) {
                        vayMcSys->step = 3;
                    } else {
                        vayMcSys->fileFlg[vayMcSys->fileID] = 1;
                        str[2][len[vspenvGame->language]] = (char)(vayMcSys->fileID + 0x41);
                        ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", str[2]);
                        vayMcSys->fileID++;
                        if (vayMcSys->fileID == 5) {
                            vayMcSys->step = 5;
                            ulmcSetUseSlot(1);
                                                    } else {
                            vayMcSys->step = 1;
                        }
                    }
                }
            }
        }
        break;
    case 3:
        if (fstat == -1) {
            ulstdSprintf(name, "/%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41, vayCode[vspenvGame->language], "SPREP-", vayMcSys->fileID + 0x41);
            ulmcLoad(0, name, vayMcSys->fdata->data, 0x38);
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 4;
                vayMcSys->confirm = 1;
                vayMcSys->confFlg = 0;
                mes[0] = 2;
                mes[1] = 0x15;
                mes[2] = 0xC;
            } else {
                vayMcSys->fileFlg[vayMcSys->fileID] = 3;
                data = (File*)vayMcSys->fdata->data;
                aySetTimeStr(vayMcSys->date[vayMcSys->fileID], data);
                ulstdSprintf(vayMcSys->name[vayMcSys->fileID], "%s", ((File*)vayMcSys->fdata->data)->name);
                vayMcSys->fileID++;
                if (vayMcSys->fileID == 5) {
                    vayMcSys->step = 5;
                    ulmcSetUseSlot(1);
                                    } else {
                    vayMcSys->step = 1;
                }
            }
            mes[2] = -1;
        }
        break;
    case 4:
        if ((vgmsysPad[0]->rep & 0x8000) || (vgmsysPad[0]->rep & 0x2000)) {
            nmvcPlayCursor(1);
            vayMcSys->confirm ^= 1;
        } else {
            switch (vayMcSys->confFlg) {
            case 0:
                if (vgmsysPad[0]->trg & 0x40) {
                    if (vayMcSys->confirm == 0) {
                        nmvcPlayButton(0);
                        ret = 1;
                    } else {
                        nmvcPlayButton(2);
                        ayMcSysClear();
                    }
                }
                break;
            case 1:
                if (info->type != 2) {
                    ulmcSetUseSlot(0);
                    mes[0] = 2;
                    mes[1] = 0x15;
                    mes[2] = 0xC;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 0;
                } else if (vgmsysPad[0]->trg & 0x40) {
                    if (vayMcSys->confirm == 0) {
                        nmvcPlayButton(0);
                        vayMcSys->step = 6;
                        mes[0] = 0x13;
                        mes[1] = 1;
                    } else {
                        nmvcPlayButton(2);
                        mes[0] = 0x15;
                        mes[1] = 0xC;
                        vayMcSys->confirm = 1;
                        vayMcSys->confFlg = 0;
                    }
                }
                break;
            case 2:
            case 3:
                if (info->type != 2) {
                    ulmcSetUseSlot(0);
                    mes[0] = 2;
                    mes[1] = 0x15;
                    mes[2] = 0xC;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 0;
                } else if (vgmsysPad[0]->trg & 0x40) {
                    if (vayMcSys->confirm == 0) {
                        nmvcPlayButton(0);
                        if (vayMcSys->confFlg == 2) {
                            vayMcSys->step = 0xA;
                            vayMcSys->rewrite = 1;
                            ulstdSprintf(vspenvReplay[0]->file.name, "%s", vayMcSys->name[vayMcSys->select]);
                            vayMcSys->nameID = strlen(vayMcSys->name[vayMcSys->select]);
                            for (ii = vayMcSys->nameID; ii < 0x11; ii++) {
                                vspenvReplay[0]->file.name[ii] = 0;
                            }
                            vayMcSys->nameCH = 0x26;
                            vayMcSys->count = 0;
                            aySetRepData(1);
                        } else {
                            mes[0] = 0x10;
                            mes[1] = 1;
                            mes[2] = -1;
                            vayMcSys->step = 8;
                        }
                        ulmcSetUseSlot(0);
                    } else {
                        nmvcPlayButton(2);
                        vayMcSys->step = 5;
                    }
                }
                break;
            }
        }
        ayFontInitmin();
        for (ii = 0; ii < 2; ii++) {
            if (ii == vayMcSys->confirm) {
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            }
            nmfontSetCol(fcol);
            nmfontFPrint(packet, (char*)str[ii], ii * 0x3C + 0x118, 0x158);
        }
        break;
    case 5:
        if (info->type != 2) {
            ulmcSetUseSlot(0);
            vayMcSys->confFlg = 0;
            vayMcSys->step = 4;
            vayMcSys->confirm = 1;
            mes[0] = 2;
            mes[1] = 0x15;
            mes[2] = 0xC;
        } else {
            if (vgmsysPad[0]->rep & 0x4000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 4) {
                    vayMcSys->select = 0;
                } else {
                    vayMcSys->select++;
                }
            } else if (vgmsysPad[0]->rep & 0x1000) {
                nmvcPlayCursor(1);
                if (vayMcSys->select == 0) {
                    vayMcSys->select = 4;
                } else {
                    vayMcSys->select--;
                }
            } else if (vgmsysPad[0]->trg & 0x40) {
                if (vayMcSys->fileFlg[vayMcSys->select] == 3) {
                    nmvcPlayButton(0);
                    mes[0] = 0x11;
                    mes[1] = -1;
                    mes[2] = -1;
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 2;
                } else if (vayMcSys->fileFlg[vayMcSys->select] == 0) {
                    nmvcPlayButton(0);
                    vayMcSys->step = 0xA;
                    aySetRepData(1);
                    vayMcSys->rewrite = 0;
                    ulstdSprintf(vspenvReplay[0]->file.name, "%s", vayMcSys->name[vayMcSys->select]);
                    vayMcSys->nameID = strlen(vayMcSys->name[vayMcSys->select]);
                    for (ii = vayMcSys->nameID; ii < 0x11; ii++) {
                        vspenvReplay[0]->file.name[ii] = 0;
                    }
                    vayMcSys->nameCH = 0x26;
                    vayMcSys->count = 0;
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[0]->trg & 0x20) {
                if ((vayMcSys->fileFlg[vayMcSys->select] == 3) || (vayMcSys->fileFlg[vayMcSys->select] == 1) || (vayMcSys->fileFlg[vayMcSys->select] == 4)) {
                    nmvcPlayButton(0);
                    mes[0] = 0x12;
                    mes[1] = -1;
                    mes[2] = -1;
                    vayMcSys->step = 4;
                    vayMcSys->confirm = 1;
                    vayMcSys->confFlg = 3;
                } else {
                    nmvcPlayButton(3);
                }
            } else if (vgmsysPad[0]->trg & 0x10) {
                nmvcPlayButton(2);
                ret = 1;
            }
            ayMcFileDraw(packet, 0, 1, 1);
        }
        break;
    case 6:
        if (fstat == -1) {
            ulmcFormat(0);
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 4;
                vayMcSys->confirm = 1;
                vayMcSys->confFlg = 0;
                mes[0] = 0xD;
                mes[1] = 0x15;
                mes[2] = 0xC;
            } else {
                vayMcSys->step = 1;
                mes[0] = 0;
                mes[1] = 1;
                mes[2] = -1;
                            }
        }
        break;
    case 7:
        if (fstat == -1) {
            mes[0] = 0xF;
            mes[1] = 1;
            mes[2] = -1;
            ulstrAsciitoSjis(uname, vspenvReplay[0]->file.name);
            ulstdSprintf(name, "%s%s", "\202r\202o\202o\202r\201@\202q\202d\202o\202k\202`\202x\201@\201|\201@", uname);
            ulmcClearIconSys(&vayMcSys->icon, name, "sman1.ico", "sman2.ico", "sman3.ico");
            vayMcSys->icon.OffsLF = 0x1C;
            vayMcSys->icon.TransRate = 0x80;
            vayMcSys->icon.BgColor[0][0] = 0x20, vayMcSys->icon.BgColor[0][1] = 0x20, vayMcSys->icon.BgColor[0][2] = 0x20, vayMcSys->icon.BgColor[0][3] = 0x80;
            vayMcSys->icon.BgColor[1][0] = 0x20, vayMcSys->icon.BgColor[1][1] = 0x20, vayMcSys->icon.BgColor[1][2] = 0x20, vayMcSys->icon.BgColor[1][3] = 0x80;
            vayMcSys->icon.BgColor[2][0] = 0x60, vayMcSys->icon.BgColor[2][1] = 0x60, vayMcSys->icon.BgColor[2][2] = 0x60, vayMcSys->icon.BgColor[2][3] = 0x80;
            vayMcSys->icon.BgColor[3][0] = 0x60, vayMcSys->icon.BgColor[3][1] = 0x60, vayMcSys->icon.BgColor[3][2] = 0x60, vayMcSys->icon.BgColor[3][3] = 0x80;
            vayMcSys->icon.LightColor[0][0] = 0.0f, vayMcSys->icon.LightColor[0][1] = 0.0f, vayMcSys->icon.LightColor[0][2] = 0.0f, vayMcSys->icon.LightColor[0][3] = 0.0f;
            vayMcSys->icon.LightColor[1][0] = 0.0f, vayMcSys->icon.LightColor[1][1] = 0.0f, vayMcSys->icon.LightColor[1][2] = 0.0f, vayMcSys->icon.LightColor[1][3] = 0.0f;
            vayMcSys->icon.LightColor[2][0] = 0.0f, vayMcSys->icon.LightColor[2][1] = 0.0f, vayMcSys->icon.LightColor[2][2] = 0.0f, vayMcSys->icon.LightColor[2][3] = 0.0f;
            vayMcSys->icon.Ambient[0] = 0.0f, vayMcSys->icon.Ambient[1] = 0.0f, vayMcSys->icon.Ambient[2] = 0.0f, vayMcSys->icon.Ambient[3] = 0.0f;
            vayMcSys->icon.Ambient[0] = 0.5f, vayMcSys->icon.Ambient[1] = 0.5f, vayMcSys->icon.Ambient[2] = 0.5f, vayMcSys->icon.Ambient[3] = 0.5f;
            vayMcSys->icon.LightDir[0][0] = 0.0f, vayMcSys->icon.LightDir[0][1] = 0.0f, vayMcSys->icon.LightDir[0][2] = 1.0f, vayMcSys->icon.LightDir[0][3] = 1.0f;
            vayMcSys->icon.LightDir[1][0] = 0.0f, vayMcSys->icon.LightDir[1][1] = 0.0f, vayMcSys->icon.LightDir[1][2] = -1.0f, vayMcSys->icon.LightDir[1][3] = 1.0f;
            vayMcSys->icon.LightDir[2][0] = 0.0f, vayMcSys->icon.LightDir[2][1] = 1.0f, vayMcSys->icon.LightDir[2][2] = 0.0f, vayMcSys->icon.LightDir[2][3] = 1.0f;
            if (vayMcSys->rewrite != 0) {
                ulstdSprintf(name, "%s%s%c/icon.sys", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41);
                ulmcSave(0, name, &vayMcSys->icon, 0x3C4);
                vayMcSys->process = 4;
            } else {
                ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41);
                ulmcMkDir(0, name);
                vayMcSys->process = 0;
            }
        } else if (fstat == 1) {
            if (info->result < 0) {
                vayMcSys->step = 4;
                vayMcSys->confirm = 1;
                vayMcSys->confFlg = 0;
                mes[0] = 0xA;
                mes[1] = 0x15;
                mes[2] = 0xC;
            } else {
                switch (vayMcSys->process) {
                case 0:
                    ulstdSprintf(name, "%s%s%c/icon.sys", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41);
                    ulmcSave(0, name, &vayMcSys->icon, 0x3C4);
                    vayMcSys->process++;
                    break;
                case 1:
                    icondata = sploadGetIconData();
                    ulstdSprintf(name, "%s%s%c/%s", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41, "sman1.ico");
                    ulmcSave(0, name, icondata->replay[0], 0x1F818);
                    vayMcSys->process++;
                    break;
                case 2:
                    icondata = sploadGetIconData();
                    ulstdSprintf(name, "%s%s%c/%s", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41, "sman2.ico");
                    ulmcSave(0, name, icondata->replay[1], 0x1F818);
                    vayMcSys->process++;
                    break;
                case 3:
                    icondata = sploadGetIconData();
                    ulstdSprintf(name, "%s%s%c/%s", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41, "sman3.ico");
                    ulmcSave(0, name, icondata->replay[2], 0x1F818);
                    vayMcSys->process++;
                    break;
                case 4:
                    spinitGetClock();
                    ulstdSprintf(name, "%s%s%c/%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41, vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41);
                    ulmcSave(0, name, vspenvReplay[0], 0x2DCEC);
                    vayMcSys->process++;
                    break;
                case 5:
                    ret = 1;
                                        break;
                }
            }
        }
        break;
    case 8:
        if (fstat == -1) {
            mes[0] = 0x10;
            mes[1] = 1;
            mes[2] = -1;
            ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41);
            if (vayMcSys->fileFlg[vayMcSys->select] == 4) {
                ulmcDelete(0, name);
                vayMcSys->process = 3;
            } else {
                ulmcChDir(0, name, &pwd);
                vayMcSys->process = 0;
            }
        } else if (fstat == 1) {
            if (info->result < 0) {
                if (info->result < -10) {
                    vayMcSys->step = 9;
                    mes[0] = 0xE;
                    mes[1] = -1;
                    mes[2] = -1;
                } else {
                    ulmcChDir(0, "/", &pwd);
                    vayMcSys->process = 4;
                }
            } else {
                switch (vayMcSys->process) {
                case 0:
                    ulmcDeleteAll(0);
                    vayMcSys->process++;
                    break;
                case 1:
                    ulmcChDir(0, "/", &pwd);
                    vayMcSys->process++;
                    break;
                case 2:
                    ulstdSprintf(name, "%s%s%c", vayCode[vspenvGame->language], "SPREP-", vayMcSys->select + 0x41);
                    ulmcDelete(0, name);
                    vayMcSys->process++;
                    break;
                case 3:
                                        ayMcSysClear();
                    break;
                case 4:
                    vayMcSys->step = 9;
                    mes[0] = 0xE;
                    mes[1] = -1;
                    mes[2] = -1;
                    break;
                }
            }
        }
        break;
    case 9:
        vayMcSys->count++;
        if (vayMcSys->count == 0xB4) {
            ayMcSysClear();
        }
        break;
    case 10:
        if (info->type != 2) {
            ulmcSetUseSlot(0);
            mes[0] = 2;
            mes[1] = 0x15;
            mes[2] = 0xC;
            vayMcSys->confFlg = 0;
            vayMcSys->confirm = 1;
            vayMcSys->step = 4;
        } else {
            fname = vspenvReplay[0]->file.name;
            nret = ayMcDrawEnterName(packet, fname);
            if (nret == 1) {
                ulmcSetUseSlot(0);
                vayMcSys->step = 7;
            } else if (nret == -1) {
                vayMcSys->step = 5;
            }
        }
        break;
    }
    if ((vayMcSys->step != 5) && (vayMcSys->step != 0xA)) {
        for (ii = 0, line = 0; ii < 3; ii++) {
            if (mes[ii] == -1) {
                break;
            }
            line = ayMcMesDraw(packet, mes[ii], line);
        }
    }
    if (ret) {
        if (vayMcSys->memFlg == 1) {
            ulFree(vayMcSys->fdata->data);
            ulFree(vayMcSys->fdata);
            vayMcSys->memFlg = 0;
        }
        ayMcSysClear();
    }
    return ret;
}

static void ayMcFileDraw(VgmsysGifPkt* packet, signed int count, signed int kind, signed int scr) {
    signed int dx[12]; // 0xA0(r29)
    signed int fcol[4]; // 0xD0(r29)
    char* strList[3][6] = {{"SELECT A FILE", "FILE", "DATE", "NO DATA", "CORRUPTED DATA", "NOT ENOUGH FREE MEMORY"}, {"DATEI W\x90HLEN", "DATEI", "DATUM", "KEINE DATEN", "UNG\x94LTIGE DATEN", "NICHT GEN\x94GEND SPEICHER"}, {"SELECTIONNER UN FICHIER", "FICHIER", "DATE", "AUCUNE DONNEE", "DONNEES CORROMPUES", "MEM. LIBRE INSUFFISANTE"}}; // 0xE0(r29)
    char** str = strList[vspenvGame->language]; // r17
    signed int dy; // r19
    signed int limit; // r20
    signed int exist; // r18
    signed int ii; // r16

    if (kind == 0) {
        limit = 10;
        dy = 0x14;
    } else {
        limit = 5;
        dy = 0x24;
    }
    for (ii = 0; ii < limit + 2; ii++) {
        if (count <= ii * 4) {
            dx[ii] = 0;
        } else if (count < ii * 4 + 0x10) {
            dx[ii] = ayCalcTotalMove(0x11, count - ii * 4, 640.0f, 3);
        } else {
            dx[ii] = 0x280;
        }
    }
    ayFontInitmin();
    fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
    nmfontSetSize(0x1C, 0x1C);
    nmfontSetCol(fcol);
    nmfontFPrint(packet, (char*)str[0], dx[0] + 0x140 - nmfontGetPackStrLen(str[0], 0x1C, 0) / 2, 0x54);
    fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
    nmfontSetCol(fcol);
    nmfontSetSize(0x14, 0x12);
    nmfontFPrint(packet, (char*)str[1], dx[1] + 0x96 - nmfontGetPackStrLen(str[1], 0x14, 0) / 2, 0x74);
    nmfontFPrint(packet, (char*)str[2], dx[1] + 0x1C2 - nmfontGetPackStrLen(str[2], 0x14, 0) / 2, 0x74);
    nmfontSetSize(0x10, 0x10);
    for (ii = 0; ii < limit; ii++) {
        if (scr == 0) {
            if (vayMcSys->fileFlg[ii] == 3) {
                exist = 1;
            } else {
                exist = 0;
            }
        } else {
            if (vayMcSys->fileFlg[ii] == 3 || vayMcSys->fileFlg[ii] == 0) {
                exist = 1;
            } else {
                exist = 0;
            }
        }
        if (vayMcSys->select == ii) {
            if (exist) {
                fcol[0] = 0x80, fcol[1] = 0x60, fcol[2] = 0x40, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x40, fcol[1] = 0x30, fcol[2] = 0x20, fcol[3] = 0x80;
            }
        } else {
            if (exist) {
                fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
            } else {
                fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x40, fcol[3] = 0x80;
            }
        }
        nmfontSetCol(fcol);
        nmfontFPrint(packet, vayMcSys->name[ii], dx[ii + 2] + 0x96 - nmfontGetPackStrLen(vayMcSys->name[ii], 0x10, 0) / 2, ii * dy + 0x9E);
        switch (vayMcSys->fileFlg[ii]) {
        case 0:
            nmfontFPrint(packet, (char*)str[3], dx[ii + 2] + 0x1C2 - nmfontGetPackStrLen(str[3], 0x10, 0) / 2, ii * dy + 0x9E);
            break;
        case 1:
        case 4:
            nmfontFPrint(packet, (char*)str[4], dx[ii + 2] + 0x1C2 - nmfontGetPackStrLen(str[4], 0x10, 0) / 2, ii * dy + 0x9E);
            break;
        case 2:
            nmfontFPrint(packet, (char*)str[5], dx[ii + 2] + 0x1C2 - nmfontGetPackStrLen(str[5], 0x10, 0) / 2, ii * dy + 0x9E);
            break;
        case 3:
            nmfontFPrint(packet, vayMcSys->date[ii], dx[ii + 2] + 0x1C2 - nmfontGetPackStrLen(vayMcSys->date[ii], 0x10, 0) / 2, ii * dy + 0x9E);
            break;
        }
    }
}

static signed int ayMcDrawEnterName(VgmsysGifPkt* packet, char* name) {
    signed int ret = 0; // 0xE8(r29)
    char* letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "; // r19
    char* strList[3][4] = {{"ENTER NAME", "SPC", "DEL", "END"}, {"NAME EINGEBEN", "SPC", "DEL", "END"}, {"ENTRER NOM", "SPC", "DEL", "END"}}; // 0xA0(r29)
    char** str; // r20
    signed int alpha; // r18
    signed int ii; // r16
    signed int size; // r17
    char ch[2]; // 0xEC(r29)
    signed int fcol[4]; // 0xD0(r29)

    str = strList[vspenvGame->language];
    if (vgmsysPad[0]->rep & 0x4000) {
        if (vayMcSys->nameID < 0x10) {
            nmvcPlayCursor(1);
            if (vayMcSys->nameCH == 0x1F) {
                vayMcSys->nameCH = 7;
            } else if (vayMcSys->nameCH >= 0x20) {
                vayMcSys->nameCH -= 0x20;
            } else {
                vayMcSys->nameCH += 8;
            }
        }
    } else if (vgmsysPad[0]->rep & 0x1000) {
        if (vayMcSys->nameID < 0x10) {
            nmvcPlayCursor(1);
            if (vayMcSys->nameCH == 7) {
                vayMcSys->nameCH = 0x1F;
            } else if (vayMcSys->nameCH < 7) {
                vayMcSys->nameCH += 0x20;
            } else {
                vayMcSys->nameCH -= 8;
            }
        }
    } else if (vgmsysPad[0]->rep & 0x8000) {
        if (vayMcSys->nameID < 0x10) {
            nmvcPlayCursor(1);
            if (vayMcSys->nameCH == 0x20) {
                vayMcSys->nameCH = 0x26;
            } else if (vayMcSys->nameCH % 8 == 0) {
                vayMcSys->nameCH += 7;
            } else {
                vayMcSys->nameCH--;
            }
        } else {
            if (vayMcSys->nameCH == 0x26) {
                nmvcPlayCursor(1);
                vayMcSys->nameCH = 0x25;
            } else if (vayMcSys->nameCH == 0x25) {
                nmvcPlayCursor(1);
                vayMcSys->nameCH = 0x26;
            }
        }
    } else if (vgmsysPad[0]->rep & 0x2000) {
        if (vayMcSys->nameID < 0x10) {
            nmvcPlayCursor(1);
            if (vayMcSys->nameCH == 0x26) {
                vayMcSys->nameCH = 0x20;
            } else if (vayMcSys->nameCH % 8 == 7) {
                vayMcSys->nameCH -= 7;
            } else {
                vayMcSys->nameCH++;
            }
        } else {
            if (vayMcSys->nameCH == 0x26) {
                nmvcPlayCursor(1);
                vayMcSys->nameCH = 0x25;
            } else if (vayMcSys->nameCH == 0x25) {
                nmvcPlayCursor(1);
                vayMcSys->nameCH = 0x26;
            }
        }
    } else if (vgmsysPad[0]->trg & 0x40) {
        if (vayMcSys->nameCH == 0x26) {
            if (vayMcSys->nameID == 0) {
                nmvcPlayButton(3);
            } else {
                nmvcPlayButton(0);
                for (ii = vayMcSys->nameID; ii < 0x11; ii++) {
                    name[ii] = 0;
                }
                ret = 1;
            }
        } else if (vayMcSys->nameCH == 0x25) {
            if (vayMcSys->nameID > 0) {
                nmvcPlayButton(2);
                vayMcSys->nameID--;
                name[vayMcSys->nameID] = 0;
            }
        } else if (vayMcSys->nameCH == 0x24) {
            if (vayMcSys->nameID > 0) {
                nmvcPlayButton(0);
                name[vayMcSys->nameID] = letter[0x24];
                vayMcSys->nameID++;
                name[vayMcSys->nameID] = 0;
                if (vayMcSys->nameID == 0x10) {
                    vayMcSys->nameCH = 0x26;
                }
            } else {
                nmvcPlayButton(3);
            }
        } else {
            nmvcPlayButton(0);
            name[vayMcSys->nameID] = letter[vayMcSys->nameCH];
            vayMcSys->nameID++;
            name[vayMcSys->nameID] = 0;
            if (vayMcSys->nameID == 0x10) {
                vayMcSys->nameCH = 0x26;
            }
        }
    } else if (vgmsysPad[0]->trg & 0x10) {
        nmvcPlayButton(2);
        ret = -1;
    }
    alpha = vayMcSys->count % 0x40;
    if (alpha < 0x20) {
        alpha *= 4;
    } else {
        alpha = 0x80 - (alpha - 0x20) * 4;
    }
    ayFontInitmin();
    fcol[0] = 0x40, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = 0x80;
    nmfontSetSize(0x1C, 0x1C);
    nmfontSetCol(fcol);
    nmfontFPrint(packet, (char*)str[0], 0x140 - nmfontGetPackStrLen(str[0], 0x1C, 0) / 2, 0x54);
    nmfontSetPack(0);
    nmfontSetSize(0x14, 0x14);
    for (ii = 0; ii < 0x10; ii++) {
        if (vayMcSys->nameID == ii) {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = alpha;
        } else {
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }
        nmfontSetCol(fcol);
        if (name[ii] == 0) {
            ch[0] = 0x5F;
        } else {
            ch[0] = name[ii];
        }
        ch[1] = 0;
        nmfontFPrint(vgmsysGifPkt, ch, ii * 20 + 0xA0, 0x74);
    }
    for (ii = 0; ii < 0x24; ii++) {
        if (vayMcSys->nameCH == ii) {
            size = 0x18;
            fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = alpha;
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }
        ch[0] = letter[ii];
        nmfontSetSize(size, size);
        nmfontSetCol(fcol);
        nmfontFPrint(vgmsysGifPkt, ch, ii % 8 * 60 + 0x64, ii / 8 * 40 + 0x9C - (size - 0x14) / 2);
    }
    nmfontSetPack(1);
    for (ii = 0; ii < 3; ii++) {
        if (vayMcSys->nameCH == ii + 0x24) {
            size = 0x18;
            fcol[0] = 0x80, fcol[1] = 0x40, fcol[2] = 0x80, fcol[3] = alpha;
        } else {
            size = 0x14;
            fcol[0] = 0x80, fcol[1] = 0x80, fcol[2] = 0x80, fcol[3] = 0x80;
        }
        nmfontSetSize(size, size);
        nmfontSetCol(fcol);
        nmfontFPrint(vgmsysGifPkt, (char*)str[ii + 1], (ii + 0x24) % 8 * 60 + 0x50, (ii + 0x24) / 8 * 40 + 0x9C - (size - 0x14) / 2);
    }
    vayMcSys->count = (vayMcSys->count + 1) & 0xFFFFFF;
    return ret;
}

void aySetRepData(signed int pnum) {
    signed int ii; // r16
    signed int chara; // r17

    for (ii = 0; ii < pnum; ii++) {
        chara = vspenvGame->character[ii].no;
        vspenvReplay[ii]->chr_no = chara;
        vspenvReplay[ii]->wear_no = vspenvGame->character[ii].wear;
        vspenvReplay[ii]->brd_no = vspenvGame->character[ii].board;
        memcpy(&vspenvReplay[ii]->character.character.parameter, &vspenvGame->character[ii].chr_param, 0x1C);
        memcpy(&vspenvReplay[ii]->brd_param, &vspenvGame->character[ii].brd_param, 0x10);
        memcpy(&vspenvReplay[ii]->cheats, &vspenvOption->cheats, 0x30);
        vspenvReplay[ii]->crs_no = vspenvGame->course.no;
        vspenvReplay[ii]->game_mode = vspenvGame->mode.game_mode;
    }
}

void aySetGameData(signed int randFlg, signed int pnum) {
    signed int ii; // r16

    for (ii = 0; ii < pnum; ii++) {
        if (randFlg) {
            if (vspenvReplay[ii]->chr_no < 0xC) {
                vspenvGame->character[ii].wear = rand() % 3;
            } else {
                vspenvGame->character[ii].wear = 0;
            }
            vspenvGame->character[ii].board = rand() % 6;
        } else {
            memcpy(&vspenvEnv.replay[0], vayMcSys->data, 0x2DCEC);
            vspenvGame->character[0].wear = vspenvReplay[0]->wear_no;
            vspenvGame->character[0].board = vspenvReplay[0]->brd_no;
        }
        vspenvGame->character[ii].no = vspenvReplay[ii]->chr_no;
        vspenvGame->character[ii].player = ii;
        memcpy(&vspenvGame->character[ii].chr_param, &vspenvReplay[ii]->character.character.parameter, 0x1C);
        memcpy(&vspenvGame->character[ii].brd_param, &vspenvReplay[ii]->brd_param, 0x10);
    }
    vspenvEnv.game.mode.num_player = pnum;
    if (pnum == 1) {
        vspenvEnv.game.mode.game_mode = vspenvReplay[0]->game_mode;
    } else {
        vspenvEnv.game.mode.game_mode = 1;
    }
    vspenvGame->course.no = vspenvReplay[0]->crs_no;
}

static signed int ayMcMesDraw(VgmsysGifPkt* packet, signed int id, signed int line) {
    char str[64]; // 0x50(r29)
    float pos[4]; // 0x90(r29)
    McMessage mesList[3][24] = {{
            {{"SCANNING MEMORY CARD (8MB) (FOR PLAYSTATION 2)", "IN MEMORY CARD SLOT 1.", "", ""}, 2},
            {{"DO NOT REMOVE MEMORY CARD (8MB)", "(FOR PLAYSTATION 2) FROM MEMORY CARD SLOT 1.", "", ""}, 2},
            {{"THERE IS NO MEMORY CARD (8MB)", "(FOR PLAYSTATION 2) IN MEMORY CARD SLOT 1.", "", ""}, 2},
            {{"MEMORY CARD (8MB) (FOR PLAYSTATION 2)", "IS NOT FORMATTED.", "", ""}, 2},
            {{"DO YOU WANT TO START?", "", "", ""}, 1},
            {{"AUTO LOAD FAILED.", "", "", ""}, 1},
            {{"MEMORY CARD (8MB) (FOR PLAYSTATION 2) IN", "MEMORY CARD SLOT 1 HAS NO CAREER DATA.", "", ""}, 2},
            {{"A MEMORY CARD (8MB) (FOR PLAYSTATION 2) WITH", "AT LEAST %dKB OF FREE SPACE IS NEEDED", "TO SAVE GAME DATA.", ""}, 3},
            {{"THERE IS INSUFFICIENT SPACE", "ON THE MEMORY CARD (8MB) (FOR PLAYSTATION 2).", "IN MEMORY CARD SLOT 1.", ""}, 3},
            {{"LOAD FAILED.", "", "", ""}, 1},
            {{"SAVE FAILED.", "", "", ""}, 1},
            {{"DO YOU WANT TO FORMAT?", "", "", ""}, 1},
            {{"CONTINUE WITHOUT SAVING?", "", "", ""}, 1},
            {{"FORMAT FAILED.", "", "", ""}, 1},
            {{"DELETE FAILED.", "", "", ""}, 1},
            {{"SAVING DATA TO MEMORY CARD (8MB)", "(FOR PLAYSTATION 2) IN MEMORY CARD SLOT 1.", "", ""}, 2},
            {{"DELETING DATA FROM MEMORY CARD (8MB)", "(FOR PLAYSTATION 2) IN MEMORY CARD SLOT 1.", "", ""}, 2},
            {{"DO YOU WANT TO OVERWRITE", "THE EXISTING DATA?", "", ""}, 2},
            {{"DO YOU WANT TO DELETE", "THIS DATA?", "", ""}, 2},
            {{"FORMATTING MEMORY CARD (8MB)", "(FOR PLAYSTATION 2) IN MEMORY CARD SLOT 1.", "", ""}, 2},
            {{"MEMORY CARD (8MB) (FOR PLAYSTATION 2) IN", "MEMORY CARD SLOT 1 HAS NO REPLAY DATA.", "", ""}, 2},
            {{"A MEMORY CARD (8MB) (FOR PLAYSTATION 2) WITH", "AT LEAST %dKB OF FREE SPACE IS NEEDED", "TO SAVE GAME DATA.", ""}, 3},
            {{"LOADING DATA FROM MEMORY CARD (8MB)", "(FOR PLAYSTATION 2) IN MEMORY CARD SLOT 1.", "", ""}, 2},
            {{"CONTINUE WITHOUT LOADING?", "", "", ""}, 1}
        }, {
            {{"LESE MEMORY CARD (8MB) (F\224R PLAYSTATION 2)", "IN MEMORY CARD-STECKPLATZ 1.", "", ""}, 2},
            {{"MEMORY CARD (8MB) (F\224R PLAYSTATION 2) NICHT", "AUS MEMORY CARD-STECKPLATZ 1 ENTFERNEN.", "", ""}, 2},
            {{"KEINE MEMORY CARD (8MB) (F\224R PLAYSTATION 2)", "IN MEMORY CARD-STECKPLATZ 1 EINGESTECKT.", "", ""}, 2},
            {{"DIE MEMORY CARD (8MB) (F\224R PLAYSTATION 2)", "IST NICHT FORMATIERT.", "", ""}, 2},
            {{"JETZT STARTEN?", "", "", ""}, 1},
            {{"AUTO-LADEN FEHLGESCHLAGEN.", "", "", ""}, 1},
            {{"DIE MEMORY CARD (8MB) (F\224R PLAYSTATION 2)", "IN MEMORY CARD-STECKPLATZ 1", "ENTH\220LT KEINE KARRIEREDATEN.", ""}, 3},
            {{"EINE MEMORY CARD (8MB) (F\224R PLAYSTATION 2) MIT", "MINDESTENS %dKB FREIEM SPEICHERPLATZ WIRD", "BEN\222TIGT, UM DIE SPIELDATEN ZU SPEICHERN.", ""}, 3},
            {{"NICHT GEN\224GEND SPEICHERPLATZ AUF DER", "MEMORY CARD (8MB) (F\224R PLAYSTATION 2)", "IN MEMORY CARD-STECKPLATZ 1.", ""}, 3},
            {{"LADEN FEHLGESCHLAGEN.", "", "", ""}, 1},
            {{"SPEICHERN FEHLGESCHLAGEN.", "", "", ""}, 1},
            {{"JETZT FORMATIEREN?", "", "", ""}, 1},
            {{"WEITER OHNE ZU SPEICHERN?", "", "", ""}, 1},
            {{"FORMATIERUNG FEHLGESCHLAGEN.", "", "", ""}, 1},
            {{"L\222SCHEN FEHLGESCHLAGEN.", "", "", ""}, 1},
            {{"SPEICHERE DATEN AUF MEMORY CARD", "(8MB) (F\224R PLAYSTATION 2) IN", "MEMORY CARD-STECKPLATZ 1.", ""}, 3},
            {{"L\222SCHE DATEN VON MEMORY CARD", "(8MB) (F\224R PLAYSTATION 2) IN", "MEMORY CARD-STECKPLATZ 1.", ""}, 3},
            {{"BESTEHENDE DATEN \224BERSCHREIBEN?", "", "", ""}, 1},
            {{"DIESE DATEN L\222SCHEN?", "", "", ""}, 1},
            {{"FORMATIERE MEMORY CARD (8MB)", "(F\224R PLAYSTATION 2) IN MEMORY", "CARD-STECKPLATZ 1.", ""}, 3},
            {{"DIE MEMORY CARD (8MB) (F\224R PLAYSTATION 2) IN", "MEMORY CARD-STECKPLATZ 1 ENTH\220LT", "KEINE WIEDERHOLUNGSDATEN.", ""}, 3},
            {{"EINE MEMORY CARD (8MB) (F\224R PLAYSTATION 2) MIT", "MINDESTENS %dKB FREIEM SPEICHERPLATZ WIRD", "BEN\222TIGT, UM DIE WIEDERHOLUNGSDATEN ZU SPEICHERN.", ""}, 3},
            {{"LADE MEMORY CARD (8MB) (F\224R PLAYSTATION 2)", "IN MEMORY CARD-STECKPLATZ 1.", "", ""}, 2},
            {{"WEITER OHNE ZU LADEN?", "", "", ""}, 1}
        }, {
            {{"VERIFICATION DE LA MEMORY CARD (CARTE MEMOIRE)", "(8MB) (POUR PLAYSTATION 2) DANS LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1.", ""}, 3},
            {{"NE PAS RETIRER LA MEMORY CARD (CARTE MEMOIRE)", "(8MB) (POUR PLAYSTATION 2) DE LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1.", ""}, 3},
            {{"PAS DE MEMORY CARD (CARTE MEMOIRE) (8MB)", "(POUR PLAYSTATION 2) DANS LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1.", ""}, 3},
            {{"LA MEMORY CARD (CARTE MEMOIRE) (8MB)", "(POUR PLAYSTATION 2) DANS LA FENTE POUR", "MEMORY CARD 1 N'EST PAS FORMATEE.", ""}, 3},
            {{"VEUX-TU COMMENCER ?", "", "", ""}, 1},
            {{"ECHEC DU CHARGEMENT AUTOMATIQUE.", "", "", ""}, 1},
            {{"AUCUNE DONNEE DE CARRIERE SUR LA", "MEMORY CARD (CARTE MEMOIRE) (8MB)", "(POUR PLAYSTATION 2) INSEREE DANS LA FENTE", "POUR MEMORY CARD (CARTE MEMOIRE) N^1."}, 4},
            {{"INSERER UNE MEMORY CARD (CARTE MEMOIRE) (8MB)", "(POUR PLAYSTATION 2) AVEC AU MOINS %dKB", "D'ESPACE LIBRE POUR SAUVEGARDER", "DES DONNEES DE JEU."}, 4},
            {{"ESPACE INSUFFISANT SUR LA MEMORY CARD", "(CARTE MEMOIRE) (8MB) (POUR PLAYSTATION 2)", "INSEREE DANS LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1."}, 4},
            {{"ECHEC DU CHARGEMENT.", "", "", ""}, 1},
            {{"ECHEC DE LA SAUVEGARDE.", "", "", ""}, 1},
            {{"FORMATER LA MEMORY CARD?", "", "", ""}, 1},
            {{"CONTINUER SANS SAUVEGARDER?", "", "", ""}, 1},
            {{"ECHEC DU FORMATAGE.", "", "", ""}, 1},
            {{"ECHEC DE LA SUPPRESSION.", "", "", ""}, 1},
            {{"SAUVEGARDE EN COURS SUR LA MEMORY CARD", "(CARTE MEMOIRE) (8MB) (POUR PLAYSTATION 2)", "INSEREE DANS LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1."}, 4},
            {{"SUPPRESSION EN COURS SUR LA MEMORY CARD", "(CARTE MEMOIRE) (8MB) (POUR PLAYSTATION 2)", "INSEREE DANS LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1."}, 4},
            {{"ECRASER LES DONNEES PRECEDENTES ?", "", "", ""}, 1},
            {{"EFFACER CES DONNEES ?", "", "", ""}, 1},
            {{"FORMATAGE DE LA MEMORY CARD (CARTE MEMOIRE)", "(8MB) (POUR PLAYSTATION 2) INSEREE DANS", "LA FENTE POUR MEMORY CARD 1 EN COURS.", ""}, 3},
            {{"AUCUNE DONNEE DE VIDEO SUR LA MEMORY CARD", "(CARTE MEMOIRE) (8MB) (POUR PLAYSTATION 2)", "INSEREE DANS LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1."}, 4},
            {{"INSERER UNE MEMORY CARD (CARTE MEMOIRE) (8MB)", "(POUR PLAYSTATION 2) AVEC AU MOINS %dKB", "D'ESPACE LIBRE POUR SAUVEGARDER", "DES DONNEES VIDEO."}, 4},
            {{"CHARGEMENT EN COURS DEPUIS LA MEMORY CARD", "(CARTE MEMOIRE) (8MB) (POUR PLAYSTATION 2)", "INSEREE DANS LA FENTE POUR", "MEMORY CARD (CARTE MEMOIRE) N^1."}, 4},
            {{"CONTINUER SANS CHARGER ?", "", "", ""}, 1}
        }}; // 0xA0(r29)
    McMessage* mes = mesList[vspenvGame->language]; // r17
    signed int ii; // r16
    signed int nextL; // r19

    ayFontInitmin();
    for (ii = 0; ii < mes[id].line; ii++) {
        if ((id == 7) && (ii == 1)) {
            ulstdSprintf(str, mes[7].mes[1], 0x189);
            pos[0] = 320.0f - (float)nmfontGetPackStrLen(str, 0x10, 0) / 2.0f;
            pos[1] = 112.0f + 20.0f * (float)(line + ii) - 16.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
            nmfontFPrintF(packet, str, pos);
        } else if ((id == 0x15) && (ii == 1)) {
            ulstdSprintf(str, mes[0x15].mes[1], 0x23B);
            pos[0] = 320.0f - (float)nmfontGetPackStrLen(str, 0x10, 0) / 2.0f;
            pos[1] = 112.0f + 20.0f * (float)(line + ii) - 16.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
            nmfontFPrintF(packet, str, pos);
        } else {
            pos[0] = 320.0f - (float)nmfontGetPackStrLen(mes[id].mes[ii], 0x10, 0) / 2.0f;
            pos[1] = 112.0f + 20.0f * (float)(line + ii) - 16.0f, pos[2] = 16777215.0f, pos[3] = 1.0f;
            nmfontFPrintF(packet, mes[id].mes[ii], pos);
        }
    }
    nextL = line + mes[id].line + 1;
    return nextL;
}

void ayMcSysEnd(void) {
    ulFree(vayMcSys);
}

signed int ayMcGetStep(void) {
    return vayMcSys->step;
}

void aySetTimeStr(char* str, File* data) {
    signed int datetype; // r16
    char date[16]; // 0x20(r29)
    char time[16]; // 0x30(r29)

    if (sceScfGetTimeNotation() == 1) {
        if (data->clock.hour < 12) {
            ulstdSprintf(time, "%2d:%02d:%02dAM", data->clock.hour % 12, data->clock.minute, data->clock.second);
        } else {
            ulstdSprintf(time, "%2d:%02d:%02dPM", data->clock.hour % 12, data->clock.minute, data->clock.second);
        }
    } else {
        ulstdSprintf(time, "%2d:%02d:%02d", data->clock.hour, data->clock.minute, data->clock.second);
    }
    datetype = sceScfGetDateNotation();
    switch (datetype) {
    case 0:
        ulstdSprintf(date, "%4d/%2d/%2d", data->clock.year + 2000, data->clock.month, data->clock.day);
        break;
    case 1:
        ulstdSprintf(date, "%2d/%2d/%4d", data->clock.month, data->clock.day, data->clock.year + 2000);
        break;
    case 2:
        ulstdSprintf(date, "%2d/%2d/%4d", data->clock.day, data->clock.month, data->clock.year + 2000);
        break;
    }
    ulstdSprintf(str, "%s %s", date, time);
}
