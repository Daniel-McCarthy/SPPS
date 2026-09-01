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

// nmvc.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0x126312
typedef struct VnmvcOption
{
    signed int atk_rate; // Offset: 0x0, DWARF: 0x12632D
    signed int rel_rate; // Offset: 0x4, DWARF: 0x126352
    signed int loop; // Offset: 0x8, DWARF: 0x126377
    signed int priority; // Offset: 0xC, DWARF: 0x126398
    signed int vol; // Offset: 0x10, DWARF: 0x1263BD
    signed int pan; // Offset: 0x14, DWARF: 0x1263DD
    signed int pitch; // Offset: 0x18, DWARF: 0x1263FD
    signed int res; // Offset: 0x1C, DWARF: 0x12641F
} VnmvcOption;

// Size: 0x30, DWARF: 0x1261D4
typedef struct VnmvcResult
{
    char state[32]; // Offset: 0x0, DWARF: 0x1261EF
    signed int batch; // Offset: 0x20, DWARF: 0x126213
    signed int data_state; // Offset: 0x24, DWARF: 0x126235
    signed int res[2]; // Offset: 0x28, DWARF: 0x12625C
} VnmvcResult;

// Size: 0x10, DWARF: 0x1264C9
typedef struct Voice
{
    signed int max_vol; // Offset: 0x0, DWARF: 0x1264E4
    signed int mix; // Offset: 0x4, DWARF: 0x126508
    signed int chan_num; // Offset: 0x8, DWARF: 0x126528
    signed int res; // Offset: 0xC, DWARF: 0x12654D
} Voice;

// Size: 0x10, DWARF: 0x126443
typedef struct Batch
{
    signed int com; // Offset: 0x0, DWARF: 0x12645E
    signed int data[3]; // Offset: 0x4, DWARF: 0x12647E
} Batch;

// Size: 0x8, DWARF: 0x126571
typedef struct Adsr
{
    char atk_mode; // Offset: 0x0, DWARF: 0x12658C
    char atk_rate; // Offset: 0x1, DWARF: 0x1265B1
    char dec_rate; // Offset: 0x2, DWARF: 0x1265D6
    char sus_rate; // Offset: 0x3, DWARF: 0x1265FB
    char sus_mode; // Offset: 0x4, DWARF: 0x126620
    char sus_level; // Offset: 0x5, DWARF: 0x126645
    char rel_mode; // Offset: 0x6, DWARF: 0x12666B
    char rel_rate; // Offset: 0x7, DWARF: 0x126690
} Adsr;

// Size: 0x710, DWARF: 0x12A083
typedef struct VnmsndFrame
{
    // Size: 0x10, DWARF: 0x129A55
    Batch bgm[16]; // Offset: 0x0, DWARF: 0x12A09F
    // Size: 0x10, DWARF: 0x129A55
    Batch voice[64]; // Offset: 0x100, DWARF: 0x12A0C1
    // Size: 0x10, DWARF: 0x129A55
    Batch synth[32]; // Offset: 0x500, DWARF: 0x12A0E5
    signed int bgm_num; // Offset: 0x700, DWARF: 0x12A109
    signed int voice_num; // Offset: 0x704, DWARF: 0x12A12D
    signed int synth_num; // Offset: 0x708, DWARF: 0x12A153
    signed int res; // Offset: 0x70C, DWARF: 0x12A179
} VnmsndFrame;

//// Function Declarations ///////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x1264C9
signed int nmvcInit(Voice* init);
void nmvcInitOption();
// Size: 0x710, DWARF: 0x12A083
// Size: 0x30, DWARF: 0x1261D4
signed int nmvcFrame(VnmsndFrame* frame, VnmvcResult* result, signed int pause);
signed int nmvcSetData(signed int group, signed int addr);
signed int nmvcResetData();
signed int nmvcSetExterVol(signed int vol);
signed int nmvcSetInterVol(signed int res, signed int vol, signed int pan);
signed int nmvcSetPitch(signed int res, signed int pitch);
// Size: 0x20, DWARF: 0x126312
void nmvcSetOption(VnmvcOption* vcoption);
void nmvcSetOptLoop(signed int loop);
void nmvcSetOptVol(signed int vol, signed int pan);
void nmvcSetOptPitch(signed int pitch);
signed int nmvcPlay(signed int res, signed int group, signed int num);
signed int nmvcStop(signed int res);
signed int nmvcStopVoice();
signed int nmvcStopAct();
signed int nmvcStopEvent();
signed int nmvcStopEffect();
signed int nmvcPause(signed int res);
signed int nmvcResume(signed int res);
signed int nmvcPlayButton(signed int num);
signed int nmvcPlayCursor(signed int num);
signed int nmvcGetState(signed int res);
signed int nmvcGetDataState(signed int group);
signed int nmvcCheckAllStop();
signed int nmvcChangeSin(signed int value);
static void nmvcInitFig();
static void nmvcCheckState();

//// Variables ///////////////////////////////////////////////////////////////////////

// bss and sbss are emitted in reverse declaration order, so these descend.

// Size: 0x30, DWARF: 0x1261D4
VnmvcResult vnmvcResult; // Address: 0x3C1020
// Size: 0x20, DWARF: 0x126312
VnmvcOption vnmvcOption; // Address: 0x3C1000
signed int vnmvcOperate[32]; // Address: 0x3C0F80
signed int vnmvcState[32]; // Address: 0x3C0F00

signed int vnmvcPause; // Address: 0x2E7BFC

//// Function Definitions ////////////////////////////////////////////////////////////

s32 nmvcInit(// Size: 0x10, DWARF: 0x1264C9
Voice* init) {
    nmvcInitFig();
    init->max_vol = 0x3FFF;
    init->mix = 1;
    init->chan_num = 0x30;
    return 0;
}

void nmvcInitOption(void) {
    vnmvcOption.atk_rate = 0x1E;
    vnmvcOption.rel_rate = 0xD;
    vnmvcOption.loop = 0;
    vnmvcOption.priority = 0;
    vnmvcOption.vol = 0xFF;
    vnmvcOption.pan = 0;
    vnmvcOption.pitch = 0;
}

s32 nmvcFrame(// Size: 0x710, DWARF: 0x12A083
VnmsndFrame* frame, // Size: 0x30, DWARF: 0x1261D4
VnmvcResult* result, signed int pause) {
    signed int i; // r16
    memcpy(&vnmvcResult, result, 0x30);
    nmvcCheckState();
    if (pause == 1) {
        if (vnmvcPause == 0) {
            for (i = 0; i < 32; i++) {
                if (vnmvcState[i] != 1 || (vnmvcOperate[i])) {
                    if (i) {
                        nmvcPause(i);
                    }
                }
            }
            vnmvcPause = pause;
        }
    } else if (pause == 0 && vnmvcPause == 1) {
        for (i = 0; i < 32; i++) {
            if (vnmvcResult.state[i] == 3) {
                nmvcResume(i);
            }
        }
        vnmvcPause = pause;
    }
    return 0;
}

s32 nmvcSetData(signed int group, signed int addr) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    batch.com = 0x8230;
    batch.data[0] = group;
    batch.data[1] = addr;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    return 0;
}

s32 nmvcResetData(void) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    batch.com = 0x8231;
    tmp = nmsndEntryBatch(0x200, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    return 0;
}

s32 nmvcSetExterVol(signed int vol) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    batch.com = 0x8240;
    batch.data[0] = vol;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    return 0;
}

s32 nmvcSetInterVol(signed int res, signed int vol, signed int pan) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    batch.com = 0x8241;
    batch.data[0] = res;
    batch.data[1] = vol;
    batch.data[2] = pan + 0x20;
    tmp = nmsndEntryBatch(0x200, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    return 0;
}

s32 nmvcSetPitch(signed int res, signed int pitch) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    if (pitch > 0) {
        tmp = pitch;
    } else {
        tmp = abs(pitch) | 0x1000;
    }
    batch.com = 0x8242;
    batch.data[0] = res;
    batch.data[1] = tmp;
    tmp = nmsndEntryBatch(0x200, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    return 0;
}

void nmvcSetOption(VnmvcOption* vcoption) {
    // Size: 0x20, DWARF: 0x126312
    VnmvcOption option; // 0x10(r29)
    option = *vcoption;
    memcpy(&vnmvcOption, &option, 0x20);
    if (option.pitch < 0) {
        vnmvcOption.pitch = abs(option.pitch) | 0x1000;
    }
}

void nmvcSetOptLoop(signed int loop) {
    vnmvcOption.loop = loop;
}

void nmvcSetOptVol(signed int vol, signed int pan) {
    vnmvcOption.vol = vol;
    vnmvcOption.pan = pan;
}

void nmvcSetOptPitch(signed int pitch) {
    if (pitch > 0) {
        vnmvcOption.pitch = pitch;
        return;
    }
    vnmvcOption.pitch = abs(pitch) | 0x1000;
}

s32 nmvcPlay(signed int res, signed int group, signed int num) {
    signed int tmp; // r16
    signed int ret; // r17
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x30(r29)
    // Size: 0x8, DWARF: 0x126571
    Adsr adsr; // 0x48(r29)

    ret = 0;
    adsr.atk_mode = 0;
    adsr.atk_rate = vnmvcOption.atk_rate;
    adsr.dec_rate = 0xE;
    adsr.sus_rate = 0xE;
    adsr.sus_mode = 0;
    adsr.sus_level = 0x34;
    adsr.rel_mode = 0x20;
    adsr.rel_rate = vnmvcOption.rel_rate;
    batch.com = 0x8250;
    batch.data[0] = res;
    batch.data[1] = group;
    batch.data[2] = num;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        ret = -1;
    }
    batch.com = 0x8270;
    batch.data[0] = ((adsr.sus_rate) << 0x18) | (((adsr.dec_rate) << 0x10) | ((adsr.atk_mode) | ((adsr.atk_rate) << 8)));
    batch.data[1] = ((adsr.rel_rate) << 0x18) | (((adsr.rel_mode) << 0x10) | ((adsr.sus_mode) | ((adsr.sus_level) << 8)));
    batch.data[2] = vnmvcOption.loop;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        ret = -1;
    }
    batch.com = 0x8270;
    batch.data[0] = vnmvcOption.priority;
    batch.data[1] = vnmvcOption.vol;
    batch.data[2] = vnmvcOption.pan + 0x20;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        ret = -1;
    }
    batch.com = 0x8270;
    batch.data[0] = vnmvcOption.pitch;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        ret = -1;
    }
    nmvcInitOption();
    vnmvcOperate[res] = 1;
    vnmvcState[res] = 2;
    return ret;
}

s32 nmvcStop(signed int res) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    batch.com = 0x8251;
    batch.data[0] = res;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    vnmvcOperate[res] = 2;
    return 0;
}

s32 nmvcStopVoice(void) {
    signed int i; // r16
    signed int tmp; // r17
    signed int state; // r18

    for (i = 0; i < 2; i++) {
        state = nmvcGetState(i + 2);
        if (state != 1) {
            tmp = nmvcStop(i + 2);
            if (tmp == -1) {
                scePrintf("nmvcStop Error\n" /*@157*/);
                return -1;
            }
        }
    }
    return 0;
}

s32 nmvcStopAct(void) {
    signed int i; // r16
    signed int tmp; // r17
    signed int state; // r18

    for (i = 0; 0xE > i; i++) {
        state = nmvcGetState(i + 4);
        tmp = nmvcStop(i + 4);
        if (tmp == -1) {
            scePrintf("nmvcStop Error\n" /*@157*/);
            return -1;
        }
    }
    return 0;
}

s32 nmvcStopEvent(void) {
    signed int i; // r16
    signed int tmp; // r17
    signed int state; // r18
    for (i = 0; 8 > i; i++) {
        state = nmvcGetState(i + 0x12);
        tmp = nmvcStop(i + 0x12);
        if (tmp == -1) {
            scePrintf("nmvcStop Error\n" /*@157*/);
            return -1;
        }
    }
    return 0;
}

s32 nmvcStopEffect(void) {
    signed int i; // r16
    signed int tmp; // r17
    signed int state; // r18

    for (i = 0; 5 > i; i++) {
        state = nmvcGetState(i + 0x1A);
        if (state != 1) {
            tmp = nmvcStop(i + 0x1A);
            if (tmp == -1) {
                scePrintf("nmvcStop Error\n" /*@157*/);
                return -1;
            }
        }
    }
    return 0;
}

s32 nmvcPause(signed int res) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    // res = res;
    batch.com = 0x8252;
    batch.data[0] = res;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    vnmvcOperate[res] = 3;
    vnmvcState[res] = 3;
    return 0;
}

s32 nmvcResume(signed int res) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x126443
    Batch batch; // 0x20(r29)

    batch.com = 0x8253;
    batch.data[0] = res;
    tmp = nmsndEntryBatch(0x200, &batch.com);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@64*/);
        return -1;
    }
    vnmvcOperate[res] = 4;
    return 0;
}

s32 nmvcPlayButton(signed int num) {
    signed int tmp; // r16
    vnmvcOption.atk_rate = 0x1E;
    vnmvcOption.rel_rate = 1;
    vnmvcOption.loop = 0;
    vnmvcOption.priority = 0;
    vnmvcOption.vol = 0xFF;
    vnmvcOption.pan = 0;
    vnmvcOption.pitch = 0;
    tmp = nmvcPlay(0, 0, num);
    if (tmp == -1) {
        scePrintf("nmvcPlay Error\n" /*@224*/);
    }
    return 0;
}

s32 nmvcPlayCursor(signed int num) {
    signed int tmp; // r16
    vnmvcOption.atk_rate = 0x1E;
    vnmvcOption.rel_rate = 1;
    vnmvcOption.loop = 0;
    vnmvcOption.priority = 0;
    vnmvcOption.vol = 0xFF;
    vnmvcOption.pan = 0;
    vnmvcOption.pitch = 0;
    tmp = nmvcPlay(1, 0, num);
    if (tmp == -1) {
        scePrintf("nmvcPlay Error\n" /*@224*/);
    }
    return 0;
}

s32 nmvcGetState(signed int res) {
    return vnmvcState[res];
}

s32 nmvcGetDataState(signed int group) {
    signed int ret = vnmvcResult.data_state & (1 << group); // r16
    return ret;
}

s32 nmvcCheckAllStop(void) {
    signed int i; // r16

    for (i = 0; 32 > i; i++) {
        if (vnmvcState[i] != 1) {
            return -1;
        }
    }
    return 0;
}

s32 nmvcChangeSin(signed int value) {
    signed int ret; // r16
    float tmp; // 0x2C(r29)

    tmp = value / 255.0f;
    tmp = sinf((3.141592f * tmp) / 2.0f);
    ret = 255.0f * tmp;
    return ret;
}

static void nmvcInitFig(void) {
    signed int i; // r16

    for (i = 0; i < 32; i++) {
        vnmvcOperate[i] = 0;
        vnmvcState[i] = 1;
    }
    vnmvcResult.batch = 0;
    vnmvcPause = 0;
    nmvcInitOption();
}

static void nmvcCheckState(void) {
    signed int i; // r16

    for (i = 0; i < 32; i++) {
        switch (vnmvcOperate[i]) {
        case 0:
            if (((vnmvcResult.state[i]) == 1) && (vnmvcState[i] != 1)) {
                vnmvcState[i] = 1;
            }
            break;
        case 1:
            if ((vnmvcResult.state[i]) == 2) {
                vnmvcOperate[i] = 0;
            }
            break;
        case 2:
            if ((vnmvcResult.state[i]) == 1) {
                vnmvcState[i] = 1;
                vnmvcOperate[i] = 0;
            }
            break;
        case 3:
            if ((vnmvcResult.state[i]) == 3) {
                vnmvcState[i] = 3;
                vnmvcOperate[i] = 0;
            }
            break;
        case 4:
            if ((vnmvcResult.state[i]) == 2) {
                vnmvcState[i] = 2;
                vnmvcOperate[i] = 0;
            }
            break;
        }
    }
}
