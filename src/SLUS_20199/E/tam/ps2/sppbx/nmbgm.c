#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);
float sinf(float a);

// nmbgm.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x12BE87
typedef struct Init
{
    signed int read_type; // Offset: 0x0, DWARF: 0x12BEA2
    signed int max_vol; // Offset: 0x4, DWARF: 0x12BEC8
    signed int res[2]; // Offset: 0x8, DWARF: 0x12BEEC
} Init;

// Size: 0x20, DWARF: 0x12C435
typedef struct VnmbgmResult
{
    signed int state; // Offset: 0x0, DWARF: 0x12C451
    signed short select_num; // Offset: 0x4, DWARF: 0x12C473
    signed short select_tbl; // Offset: 0x6, DWARF: 0x12C49A
    signed int fade; // Offset: 0x8, DWARF: 0x12C4C1
    signed short retry; // Offset: 0xC, DWARF: 0x12C4E2
    signed short tray; // Offset: 0xE, DWARF: 0x12C504
    signed int batch; // Offset: 0x10, DWARF: 0x12C525
    signed int vol; // Offset: 0x14, DWARF: 0x12C547
    signed int level[2]; // Offset: 0x18, DWARF: 0x12C567
} VnmbgmResult;

// Size: 0x10, DWARF: 0x12C0D2
typedef struct VnmbgmOption
{
    signed int vol; // Offset: 0x0, DWARF: 0x12C0ED
    signed int loop; // Offset: 0x4, DWARF: 0x12C10D
    signed int next; // Offset: 0x8, DWARF: 0x12C12E
    signed int rand; // Offset: 0xC, DWARF: 0x12C14F
} VnmbgmOption;

// Size: 0x20, DWARF: 0x12BF12
typedef struct VnmbgmQue
{
    signed int type; // Offset: 0x0, DWARF: 0x12BF2D
    signed int process; // Offset: 0x4, DWARF: 0x12BF4E
    signed int data[6]; // Offset: 0x8, DWARF: 0x12BF72
} VnmbgmQue;

// Size: 0x4, DWARF: 0x12C58F
typedef struct Course
{
    signed int no; // Offset: 0x0, DWARF: 0x12C5AB
} Course;

// Size: 0x1C, DWARF: 0x12BFBD
typedef struct Chr_Param
{
    signed int ollie; // Offset: 0x0, DWARF: 0x12BFD8
    signed int spin; // Offset: 0x4, DWARF: 0x12BFFA
    signed int speed; // Offset: 0x8, DWARF: 0x12C01B
    signed int landing; // Offset: 0xC, DWARF: 0x12C03D
    signed int balance; // Offset: 0x10, DWARF: 0x12C061
    signed int stability; // Offset: 0x14, DWARF: 0x12C085
    signed int stance; // Offset: 0x18, DWARF: 0x12C0AB
} Chr_Param;

// Size: 0x10, DWARF: 0x12C26E
typedef struct Brd_Param
{
    signed int speed; // Offset: 0x0, DWARF: 0x12C289
    signed int stability; // Offset: 0x4, DWARF: 0x12C2AB
    signed int balance; // Offset: 0x8, DWARF: 0x12C2D1
    signed int turning; // Offset: 0xC, DWARF: 0x12C2F5
} Brd_Param;

// Size: 0x3C, DWARF: 0x12C31D
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x12C338
    signed int player; // Offset: 0x4, DWARF: 0x12C357
    signed int wear; // Offset: 0x8, DWARF: 0x12C37A
    signed int board; // Offset: 0xC, DWARF: 0x12C39B
    // Size: 0x1C, DWARF: 0x12BFBD
    Chr_Param chr_param; // Offset: 0x10, DWARF: 0x12C3BD
    // Size: 0x10, DWARF: 0x12C26E
    Brd_Param brd_param; // Offset: 0x2C, DWARF: 0x12C3E5
} Character;

// Size: 0x18, DWARF: 0x12C631
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x12C64D
    signed int game_mode; // Offset: 0x4, DWARF: 0x12C674
    signed int match_rule; // Offset: 0x8, DWARF: 0x12C69A
    signed int divide; // Offset: 0xC, DWARF: 0x12C6C1
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x12C6E4
} Mode;

// Size: 0xA0, DWARF: 0x12C174
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x12C58F
    Course course; // Offset: 0x0, DWARF: 0x12C18F
    // Size: 0x3C, DWARF: 0x12C31D
    Character character[2]; // Offset: 0x4, DWARF: 0x12C1B4
    // Size: 0x18, DWARF: 0x12C631
    Mode mode; // Offset: 0x7C, DWARF: 0x12C1DC
    signed int language; // Offset: 0x94, DWARF: 0x12C1FF
    signed int ending; // Offset: 0x98, DWARF: 0x12C224
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x12C247
} VspenvGame;

// Size: 0x10, DWARF: 0x12BC40
typedef struct Send
{
    unsigned int com; // Offset: 0x0, DWARF: 0x12BC5B
    signed int wait; // Offset: 0x4, DWARF: 0x12BC7B
    signed int data; // Offset: 0x8, DWARF: 0x12BC9C
    signed int size; // Offset: 0xC, DWARF: 0x12BCBD
} Send;

// Size: 0x10, DWARF: 0x12BCE2
typedef struct Rec
{
    void* addr; // Offset: 0x0, DWARF: 0x12BCFD
    signed int size; // Offset: 0x4, DWARF: 0x12BD21
    signed int res[2]; // Offset: 0x8, DWARF: 0x12BD42
} Rec;

// Size: 0x30, DWARF: 0x12BD8C
typedef struct Pub
{
    // Size: 0x10, DWARF: 0x12BC40
    Send send; // Offset: 0x0, DWARF: 0x12BDA7
    // Size: 0x10, DWARF: 0x12BCE2
    Rec rec; // Offset: 0x10, DWARF: 0x12BDCA
    void* end_func; // Offset: 0x20, DWARF: 0x12BDEC
    void* end_param; // Offset: 0x24, DWARF: 0x12BE14
    signed int res[2]; // Offset: 0x28, DWARF: 0x12BE3D
} Pub;

// Size: 0x10, DWARF: 0x12C5CE
typedef struct Batch
{
    signed int com; // Offset: 0x0, DWARF: 0x12C5EA
    signed int data[3]; // Offset: 0x4, DWARF: 0x12C60A
} Batch;

// Size: 0x10, DWARF: 0x129A55
typedef struct Snd_Data
{
    signed int com; // Offset: 0x0, DWARF: 0x129A71
    signed int data[3]; // Offset: 0x4, DWARF: 0x129A91
} Snd_Data;

// Size: 0x710, DWARF: 0x12A083
typedef struct VnmsndFrame
{
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data bgm[16]; // Offset: 0x0, DWARF: 0x12A09F
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data voice[64]; // Offset: 0x100, DWARF: 0x12A0C1
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data synth[32]; // Offset: 0x500, DWARF: 0x12A0E5
    signed int bgm_num; // Offset: 0x700, DWARF: 0x12A109
    signed int voice_num; // Offset: 0x704, DWARF: 0x12A12D
    signed int synth_num; // Offset: 0x708, DWARF: 0x12A153
    signed int res; // Offset: 0x70C, DWARF: 0x12A179
} VnmsndFrame;

//// Function Declarations ///////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x12BE87
signed int nmbgmInit(Init* init);
// Size: 0x710, DWARF: 0x12A083
// Size: 0x20, DWARF: 0x12C435
signed int nmbgmFrame(VnmsndFrame* vnmsndFrame, VnmbgmResult* result, signed int pause);
signed int nmbgmSetTbl();
signed int nmbgmSelect(signed int num, signed int tbl);
signed int nmbgmSetSelectTbl(volatile signed int* tbl, signed int skip);
signed int nmbgmReset();
signed int nmbgmSetExterVol(signed int vol);
void nmbgmSetOptNext(signed int next);
void nmbgmSetOptRand(signed int rand);
signed int nmbgmChangeOption();
signed int nmbgmPlay();
signed int nmbgmStop(signed int fade);
signed int nmbgmPause();
signed int nmbgmResume();
signed int nmbgmChange(signed int fade, signed int num, signed int tbl);
signed int nmbgmChange2(signed int fade, signed int num, signed int tbl);
signed int nmbgmExit(signed int fade);
signed int nmbgmGetState();
signed int nmbgmGetLevel(signed int dir);
signed int nmbgmGetSelect();
signed int nmbgmGetSelectTbl();
signed int nmbgmCheckQue();
static void nmbgmInitFig();
static void nmbgmInitOption();
static void nmbgmInitQue();
static signed int nmbgmProcessQue();
static signed int nmbgmCheckRandom();

//// Variables ///////////////////////////////////////////////////////////////////////

// Data is emitted in declaration order; bss and sbss in reverse, so those descend.

static char vnmbgmFileTbl[14][128] = {
    "\\BGM\\BGM01.INT",
    "\\BGM\\BGM02.INT",
    "\\BGM\\BGM03.INT",
    "\\BGM\\BGM04.INT",
    "\\BGM\\BGM05.INT",
    "\\BGM\\BGM06.INT",
    "\\BGM\\BGM07.INT",
    "\\BGM\\BGM08.INT",
    "\\BGM\\BGM09.INT",
    "\\BGM\\BGM10.INT",
    "\\BGM\\BGM11.INT",
    "\\BGM\\BGM13.INT",
    "\\BGM\\BGM14.INT",
    "\\BGM\\BGM06.INT",
}; // Address: 0x2CD280
signed int vnmbgmPause; // Address: 0x2E7C08
// Size: 0x20, DWARF: 0x12C435
VnmbgmResult vnmbgmResult; // Address: 0x3C2820
signed int vnmbgmSelect; // Address: 0x2E7C04
// Size: 0x10, DWARF: 0x12C0D2
VnmbgmOption vnmbgmOption; // Address: 0x3C2810
// Size: 0x20, DWARF: 0x12BF12
VnmbgmQue vnmbgmQue; // Address: 0x3C27F0
// Size: 0xA0, DWARF: 0x12C174
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
signed int vnmbgmRandom; // Address: 0x2E7C00

//// Function Definitions ////////////////////////////////////////////////////////////

s32 nmbgmInit(// Size: 0x10, DWARF: 0x12BE87
Init* init) {
    nmbgmInitFig();
    init->read_type = 0;
    init->max_vol = 0x5998;
    return 0;
}

s32 nmbgmFrame(// Size: 0x710, DWARF: 0x12A083
VnmsndFrame* vnmsndFrame, // Size: 0x20, DWARF: 0x12C435
VnmbgmResult* result, signed int pause) {
    signed int tmp; // r16 // s0
    memcpy(&vnmbgmResult, result, 0x20);
    if (pause == 1) {
        if (vnmbgmPause == 0) {
            tmp = nmbgmPause();
            if (tmp == -1) {
                scePrintf("nmbgmPause Error\n" /*@38*/);
                return -1;
            }
            vnmbgmPause = pause;
        }
    } else if (pause == 0 && vnmbgmPause == 1) {
        tmp = nmbgmResume();
        if (tmp == -1) {
            scePrintf("nmbgmResume Error\n" /*@39*/);
            return -1;
        }
        vnmbgmPause = pause;
    }
    tmp = nmbgmProcessQue();
    if (tmp == -1) {
        scePrintf("nmbgmProcessQue Error\n" /*@40*/);
        return -1;
    }
    nmbgmCheckRandom();
    return 0;
}

s32 nmbgmSetTbl(void) {
    signed int i; // r16
    signed int tmp; // r17
    // Size: 0x30, DWARF: 0x12BD8C
    Pub pub; // 0x30(r29)

    pub.send.com = 0x9030;
    pub.send.wait = 1;
    pub.send.size = 0x80;
    pub.rec.addr = 0;
    pub.rec.size = 0;
    pub.end_func = 0;
    pub.end_param = 0;

    for (i = 0; i < 0xE; i++) {
        pub.send.data = (int)&vnmbgmFileTbl[i];
        tmp = nmsndPubCom(&pub.send.com);
        if (tmp == -1) {
            scePrintf("nmsndPubCom Error(%d)\n" /*@52*/, 0x9030);
            return -1;
        }
    }
    return 0;
}

s32 nmbgmSelect(signed int num, signed int tbl) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)
    
    batch.com = 0x8130;
    batch.data[0] = num;
    batch.data[1] = tbl;
    tmp = nmsndEntryBatch(0x100, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    vnmbgmSelect = num;
    return 0;
}

s32 nmbgmSetSelectTbl(volatile signed int* tbl /* 0x40(r29) */, signed int skip /* 0x50(r29) */) {
    signed int i; // r16
    signed int tmp; // r17
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x30(r29)

    batch.com = 0x133;
    batch.data[0] = 0;
    batch.data[1] = 0;
    for (i = 0; i < 8; i++) {
        batch.data[0] |= tbl[i] << (i * 4);
        batch.data[1] |= tbl[i + 8] << ((i + 8) * 4);
    }
    batch.data[2] = skip;
    tmp = nmsndEntryBatch(0x100, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    return 0;
}

s32 nmbgmReset(void) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)

    batch.com = 0x8131;
    tmp = nmsndEntryBatch(0x100, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    vnmbgmSelect = -1;
    return 0;
}

s32 nmbgmSetExterVol(signed int vol) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)

    (void)"nmbgmSelect Error\n" /*@134*/;

    batch.com = 0x140;
    batch.data[0] = vol;
    tmp = nmsndEntryBatch(0x100, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    return 0;
}

void nmbgmSetOptNext(signed int next) {
    vnmbgmOption.next = next;
}

void nmbgmSetOptRand(signed int rand) {
    vnmbgmOption.rand = rand;
}

s32 nmbgmChangeOption(void) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)
    
    batch.com = 0x160;
    batch.data[0] = vnmbgmOption.loop;
    batch.data[1] = vnmbgmOption.next;
    batch.data[2] = vnmbgmOption.rand;
    tmp = nmsndEntryBatch(0x100, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    return 0;
}

s32 nmbgmPlay(void) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)

    batch.com = 0x8150;
    batch.data[0] = vnmbgmOption.vol;
    batch.data[1] = 0;
    batch.data[2] = (vnmbgmOption.rand << 0x10) | (vnmbgmOption.loop | (vnmbgmOption.next << 8));
    tmp = nmsndEntryBatch(0x100, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    return 0;
}

s32 nmbgmStop(signed int fade) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)

    batch.com = 0x8151;
    batch.data[0] = fade;
    tmp = nmsndEntryBatch(0x100, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    return 0;
}

s32 nmbgmPause(void) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)

    batch.com = 0x152;
    tmp = nmsndEntryBatch(0x100, batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    return 0;
}

s32 nmbgmResume(void) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)
    
    batch.com = 0x153;
    tmp = nmsndEntryBatch(0x100, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    return 0;
}

s32 nmbgmChange(signed int fade, signed int num, signed int tbl) {
    signed int tmp; // r16

    switch (vnmbgmResult.state) {
    case 0:
        vnmbgmQue.process = 2;
        /* fallthrough */
    case 1:
        vnmbgmQue.process = 1;
        break;
    default:
        tmp = nmbgmStop(fade);
        if (tmp == -1) {
            scePrintf("nmbgmStop Error\n" /*@163*/);
            return -1;
        }
        vnmbgmQue.process = 1;
    }
    vnmbgmQue.type = 1;
    vnmbgmQue.data[0] = num;
    vnmbgmQue.data[1] = tbl;
    return 0;
}

s32 nmbgmChange2(signed int fade, signed int num, signed int tbl) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12C5CE
    Batch batch; // 0x20(r29)
    if (nmbgmGetSelect() < 0) {
        batch.com = 0x8130;
        batch.data[0] = num;
        batch.data[1] = tbl;
        tmp = nmsndEntryBatch(0x100, &batch.com);
    } else {
        if (nmbgmGetSelect() < 0xC) {
            vspenvGame->bgm_no = vnmbgmResult.select_tbl;
        }
        batch.com = 0x8134;
        batch.data[0] = fade;
        batch.data[1] = num;
        batch.data[2] = tbl;
        tmp = nmsndEntryBatch(0x100, &batch);
    }
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@59*/);
        return -1;
    }
    vnmbgmQue.type = 1;
    vnmbgmQue.process = 3;
    return 0;
}

s32 nmbgmExit(signed int fade) {
    signed int tmp; // r16
    if ((vnmbgmResult.select_num >= 0) && (vnmbgmQue.type == 0)) {
        tmp = nmbgmStop(fade);
        if (tmp == -1) {
            scePrintf("nmbgmStop Error\n" /*@163*/);
            return -1;
        }
        vnmbgmQue.type = 2;
        vnmbgmQue.process = 1;
    }
    vnmbgmRandom = 0;
    return 0;
}

s32 nmbgmGetState(void) {
    return vnmbgmResult.state;
}

s32 nmbgmGetLevel(signed int dir) {
    return vnmbgmResult.level[dir];
}

s32 nmbgmGetSelect(void) {
    return vnmbgmResult.select_num;
}

s32 nmbgmGetSelectTbl(void) {
    return vnmbgmResult.select_tbl;
}

s32 nmbgmCheckQue(void) {
    return vnmbgmQue.type;
}

static void nmbgmInitFig(void) {
    vnmbgmResult.state = 0;
    vnmbgmResult.vol = 0;
    vnmbgmResult.fade = 0;
    vnmbgmResult.retry = 0;
    vnmbgmResult.tray = 0;
    vnmbgmResult.batch = 0;
    vnmbgmResult.level[0] = 0;
    vnmbgmResult.level[1] = 0;
    vnmbgmPause = 0;
    vnmbgmSelect = -1;
    nmbgmInitQue();
    nmbgmInitOption();
    vnmbgmRandom = 0;
}

static void nmbgmInitOption(void) {
    vnmbgmOption.vol = 255;
    vnmbgmOption.loop = 1;
    vnmbgmOption.next = 0;
    vnmbgmOption.rand = 0;
}

static void nmbgmInitQue(void) {
    vnmbgmQue.type = 0;
    vnmbgmQue.process = 0;
    vnmbgmQue.data[0] = 0;
    vnmbgmQue.data[1] = 0;
}

static s32 nmbgmProcessQue(void) {
    signed int tmp; // r16
    switch (vnmbgmQue.type) {
    case 0:
        break;
    case 1:
        if (vnmbgmQue.process == 1) {
            if (vnmbgmResult.state == 1) {
                tmp = nmbgmReset();
                if (tmp == -1) {
                    scePrintf("nmbgmReset Error\n" /*@284*/);
                    return -1;
                }
                vnmbgmQue.process = 2;
            }
            break;
        }
        if (vnmbgmQue.process == 2) {
            if (vnmbgmResult.state == 0) {
                tmp = nmbgmSelect(vnmbgmQue.data[0], vnmbgmQue.data[1]);
                if (tmp == -1) {
                    scePrintf("nmbgmSelect Error\n" /*@134*/);
                    return -1;
                }
                vnmbgmQue.process = 3;
            }
            break;
        }
        if (vnmbgmQue.process == 3) {
            if ((vnmbgmResult.state == 1) && (vnmbgmResult.select_num >= 0)) {
                tmp = nmbgmPlay();
                if (tmp == -1) {
                    scePrintf("nmbgmPlay Error\n" /*@285*/);
                    return -1;
                }
                vnmbgmQue.process = 4;
            }
            break;
        }
        if ((vnmbgmQue.process == 4) && (vnmbgmResult.state == 2)) {
            nmbgmInitQue();
        }
        break;
    case 2:
        if (vnmbgmQue.process == 1) {
            if (vnmbgmResult.state == 1) {
                tmp = nmbgmReset();
                if (tmp == -1) {
                    scePrintf("nmbgmReset Error\n" /*@284*/);
                    return -1;
                }
                vnmbgmQue.process = 2;
            }
            break;
        }
        if ((vnmbgmQue.process == 2) && (vnmbgmResult.state == 0)) {
            nmbgmInitQue();
        }
        break;
    case 3:
        if (vnmbgmQue.process == 1) {
            if (vnmbgmResult.state == 0) {
                tmp = nmbgmSelect(vnmbgmQue.data[0], 1);
                if (tmp == -1) {
                    scePrintf("nmbgmSelect Error\n" /*@134*/);
                    return -1;
                }
                vnmbgmQue.process = 2;
            }
            break;
        }
        if (vnmbgmQue.process == 2) {
            if (vnmbgmResult.state == 1) {
                vnmbgmOption.loop = 0;
                tmp = nmbgmPlay();
                if (tmp == -1) {
                    scePrintf("nmbgmPlay Error\n" /*@285*/);
                    return -1;
                }
                vnmbgmQue.process = 3;
            }
            break;
        }
        if ((vnmbgmQue.process == 3) && (vnmbgmResult.state == 2)) {
            vnmbgmRandom = 1;
            nmbgmInitQue();
        }
        break;
    }
    return 0;
}

static s32 nmbgmCheckRandom(void) {
    signed int num; // r16
    signed int tmp; // r17

    if (vnmbgmRandom == 1 && vnmbgmQue.type == 0 && vnmbgmResult.state == 1) {
        do {
            num = rand() % 14;
        } while (num == vnmbgmSelect);
        tmp = nmbgmReset();
        if (tmp == -1) {
            scePrintf("nmbgmReset Error\n" /*@284*/);
            return -1;
        }
        vnmbgmQue.data[0] = num;
        vnmbgmQue.type = 3;
        vnmbgmQue.process = 1;
    }
    return 0;
}
