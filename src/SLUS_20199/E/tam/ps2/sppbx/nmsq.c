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

// nmsq.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0x12E779
typedef struct VnmsqResult
{
    signed int batch; // Offset: 0x0, DWARF: 0x12E794
    signed int midi_state[2]; // Offset: 0x4, DWARF: 0x12E7B6
    signed int sesq_state[2]; // Offset: 0xC, DWARF: 0x12E7DF
    signed int wave_state; // Offset: 0x14, DWARF: 0x12E808
    signed int res[2]; // Offset: 0x18, DWARF: 0x12E82F
} VnmsqResult;

// Size: 0x20, DWARF: 0x12E96C
typedef struct VnmsqOption
{
    signed int vol; // Offset: 0x0, DWARF: 0x12E987
    signed int loop; // Offset: 0x4, DWARF: 0x12E9A7
    signed int wave; // Offset: 0x8, DWARF: 0x12E9C8
    signed int bank; // Offset: 0xC, DWARF: 0x12E9E9
    signed int sq; // Offset: 0x10, DWARF: 0x12EA0A
    signed int res[3]; // Offset: 0x14, DWARF: 0x12EA29
} VnmsqOption;

// Size: 0x20, DWARF: 0x12E89D
typedef struct VnmsqQue
{
    signed int type; // Offset: 0x0, DWARF: 0x12E8B8
    signed int process; // Offset: 0x4, DWARF: 0x12E8D9
    signed int data[6]; // Offset: 0x8, DWARF: 0x12E8FD
} VnmsqQue;

// Size: 0x10, DWARF: 0x12E6C8
typedef struct Synth
{
    unsigned int voice_res[2]; // Offset: 0x0, DWARF: 0x129155
    signed int res[2]; // Offset: 0x8, DWARF: 0x12917D
} Synth;

// Size: 0x10, DWARF: 0x12EA73
typedef struct Batch
{
    signed int com; // Offset: 0x0, DWARF: 0x12EA8E
    signed int data[3]; // Offset: 0x4, DWARF: 0x12EAAE
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

// Size: 0x10, DWARF: 0x12E6C8
signed int nmsqInit(Synth* init);
// Size: 0x710, DWARF: 0x12A083
// Size: 0x20, DWARF: 0x12E779
signed int nmsqFrame(VnmsndFrame* vnmsndFrame, VnmsqResult* result, signed int pause);
signed int nmsqSetWave(signed int num, signed int hd_addr, signed int bd_addr);
signed int nmsqSetSq(signed int num, signed int addr);
signed int nmsqResetData();
signed int nmsqSetExterMVol(signed int vol);
signed int nmsqSetInterMVol(signed int port, signed int vol);
void nmsqSetOptVol(signed int vol);
void nmsqSetOptLoop(signed int loop);
void nmsqSetOptWave(signed int num);
void nmsqSetOptBank(signed int num);
void nmsqSetOptSq(signed int num);
signed int nmsqPlayMidi(signed int port, signed int block);
signed int nmsqStopMidi(signed int port);
signed int nmsqExit();
signed int nmsqExitSelect(signed int fade);
signed int nmsqGetWaveState(signed int num);
signed int nmsqCheckQue();
signed int nmsqPlaySelect();
signed int nmsqStopSelect(signed int fade);
static void nmsqInitFig();
static void nmsqInitOption();
static void nmsqInitQue();
static signed int nmsqProcessQue();
static void nmsqCheckState();

//// Variables ///////////////////////////////////////////////////////////////////////

// bss and sbss are emitted in reverse declaration order, so these descend.

// Size: 0x20, DWARF: 0x12E779
VnmsqResult vnmsqResult; // Address: 0x3C2A90
signed int vnmsqHdAddr[4]; // Address: 0x3C2A80
// Size: 0x20, DWARF: 0x12E96C
VnmsqOption vnmsqOption; // Address: 0x3C2A60
signed int vnmsqSesqOperate[2][32]; // Address: 0x3C2960
signed int vnmsqSesqState[2][32]; // Address: 0x3C2860
// Size: 0x20, DWARF: 0x12E89D
VnmsqQue vnmsqQue; // Address: 0x3C2840

signed int vnmsqPause; // Address: 0x2E7C30
signed int vnmsqSqAddr[2]; // Address: 0x2E7C28
signed int vnmsqMidiOperate[2]; // Address: 0x2E7C20
signed int vnmsqMidiState[2]; // Address: 0x2E7C18
signed int vnmsqInterMVol; // Address: 0x2E7C14
signed int vnmsqFadeCnt; // Address: 0x2E7C10
signed int vnmsqExit; // Address: 0x2E7C0C

//// Function Definitions ////////////////////////////////////////////////////////////

s32 nmsqInit(// Size: 0x10, DWARF: 0x12E6C8
Synth* init) {
    nmsqInitFig();
    init->voice_res[0] = 0xFFFFFF;
    init->voice_res[1] = 0xFFFFFF;
    return 0;
}

s32 nmsqFrame(// Size: 0x710, DWARF: 0x12A083
VnmsndFrame* vnmsndFrame, // Size: 0x20, DWARF: 0x12E779
VnmsqResult* result, signed int pause) {
    signed int tmp; // r16
    memcpy(&vnmsqResult, result, 0x20);
    nmsqCheckState();
    if (pause == 1) {
        if (vnmsqPause == 0) {
            vnmsqPause = pause;
        }
    } else if ((pause == 0) && (vnmsqPause == 1)) {
        vnmsqPause = pause;
    }
    tmp = nmsqProcessQue();
    if (tmp == -1) {
        scePrintf("nmsqProcessQue Error\n" /*@34*/);
        return -1;
    }
    return 0;
}

s32 nmsqSetWave(signed int num, signed int hd_addr, signed int bd_addr) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12EA73
    Batch batch; // 0x20(r29)
    
    if (num >= 0 && num < 4) {
        batch.com = 0x8330;
        batch.data[0] = num;
        batch.data[1] = hd_addr;
        batch.data[2] = bd_addr;
        tmp = nmsndEntryBatch(0x300, &batch);
        if (tmp == -1) {
            scePrintf("nmsndEntryBatch Error\n" /*@45*/);
            return -1;
        }
        vnmsqHdAddr[num] = hd_addr;
    } else {
        scePrintf("Entry Error\n" /*@46*/);
        return -1;
    }
    return 0;
}

s32 nmsqSetSq(signed int num, signed int addr) {
    if (num >= 0 && num < 2) {
        vnmsqSqAddr[num] = addr;
    } else {
        scePrintf("Entry Error\n" /*@46*/);
        return -1;
    }
    return 0;
}

s32 nmsqResetData(void) {
    signed int i; // r16
    signed int tmp; // r17
    // Size: 0x10, DWARF: 0x12EA73
    Batch batch; // 0x30(r29)

    for (i = 0; i < 4; i++) {
        if (vnmsqHdAddr[i]) {
            tmp = sceSifFreeIopHeap(vnmsqHdAddr[i]);
            if (tmp < 0) {
                scePrintf("sceSifFreeIopHeap Error\n" /*@79*/);
                return -1;
            }
            vnmsqHdAddr[i] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (vnmsqSqAddr[i]) {
            tmp = sceSifFreeIopHeap(vnmsqSqAddr[i]);
            if (tmp < 0) {
                scePrintf("sceSifFreeIopHeap Error\n" /*@79*/);
                return -1;
            }
            vnmsqSqAddr[i] = 0;
        }
    }
    batch.com = 0x8332;
    tmp = nmsndEntryBatch(0x300, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@45*/);
        return -1;
    }
    return 0;
}

s32 nmsqSetExterMVol(signed int vol) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12EA73
    Batch batch; // 0x20(r29)

    batch.com = 0x8440;
    batch.data[0] = vol;
    tmp = nmsndEntryBatch(0x300, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@45*/);
        return -1;
    }
    return 0;
}

s32 nmsqSetInterMVol(signed int port, signed int vol) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12EA73
    Batch batch; // 0x20(r29)

    batch.com = 0x8441;
    batch.data[0] = port;
    batch.data[1] = vol;
    tmp = nmsndEntryBatch(0x300, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@45*/);
        return -1;
    }
    vnmsqInterMVol = vol;
    return 0;
}

void nmsqSetOptVol(signed int vol) {
    vnmsqOption.vol = vol;
}

void nmsqSetOptLoop(signed int loop) {
    vnmsqOption.loop = loop;
}

void nmsqSetOptWave(signed int num) {
    vnmsqOption.wave = num;
}

void nmsqSetOptBank(signed int num) {
    vnmsqOption.bank = num;
}

void nmsqSetOptSq(signed int num) {
    vnmsqOption.sq = num;
}

s32 nmsqPlayMidi(signed int port, signed int block) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12EA73
    Batch batch; // 0x20(r29)

    batch.com = 0x8450;
    batch.data[0] = port;
    batch.data[1] = vnmsqOption.vol;
    batch.data[2] = vnmsqOption.loop;
    tmp = nmsndEntryBatch(0x300, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@45*/);
        return -1;
    }
    batch.com = 0x8460;
    batch.data[0] = vnmsqOption.wave | (vnmsqOption.bank << 0x10);
    batch.data[1] = vnmsqSqAddr[vnmsqOption.sq];
    batch.data[2] = block;
    tmp = nmsndEntryBatch(0x300, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@45*/);
        return -1;
    }
    vnmsqInterMVol = vnmsqOption.vol;
    nmsqInitOption();
    vnmsqMidiOperate[port] = 1;
    vnmsqMidiState[port] = 2;
    return 0;
}

s32 nmsqStopMidi(signed int port) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x12EA73
    Batch batch; // 0x20(r29)

    batch.com = 0x8451;
    batch.data[0] = port;
    tmp = nmsndEntryBatch(0x300, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@45*/);
        return -1;
    }
    vnmsqMidiOperate[port] = 2;
    return 0;
}

s32 nmsqExit(void) {
    signed int i; // r16
    signed int tmp; // r17
    // Size: 0x10, DWARF: 0x12EA73
    Batch batch; // 0x30(r29)

    for (i = 0; i < 2; i++) {
        if (vnmsqMidiState[i] != 1) {
            batch.com = 0x8451;
            batch.data[0] = i;
            tmp = nmsndEntryBatch(0x300, &batch);
            if (tmp == -1) {
                scePrintf("nmsndEntryBatch Error\n" /*@45*/);
                return -1;
            }
            vnmsqMidiOperate[i] = 2;
        }
    }
    vnmsqQue.type = 1;
    vnmsqQue.process = 1;
    return 0;
}

s32 nmsqExitSelect(signed int fade) {
    signed int tmp; // r16
    tmp = nmsqStopSelect(fade);
    if (tmp == -1) {
        scePrintf("nmsqStopSelect Error\n" /*@171*/);
        return -1;
    }
    vnmsqExit = 1;
    return 0;
}

s32 nmsqGetWaveState(signed int num) {
    signed int ret = vnmsqResult.wave_state & (1 << num); // r16
    return ret;
}

s32 nmsqCheckQue(void) {
    return vnmsqQue.type;
}

s32 nmsqPlaySelect(void) {
    signed int tmp; // r16
    nmsndAssignChan(0x18);
    nmsqSetOptVol(0xFF);
    nmsqSetOptLoop(1);
    nmsqSetOptWave(0);
    nmsqSetOptBank(0);
    nmsqSetOptSq(0);
    tmp = nmsqPlayMidi(0, 0);
    if (tmp == -1) {
        scePrintf("nmsqPlayMidi Error\n" /*@190*/);
        return -1;
    }
    return 0;
}

s32 nmsqStopSelect(signed int fade) {
    vnmsqFadeCnt = 0;
    vnmsqQue.type = 2;
    vnmsqQue.process = 1;
    vnmsqQue.data[0] = 0;
    vnmsqQue.data[1] = fade;
    vnmsqQue.data[2] = vnmsqInterMVol;
    return 0;
}

static void nmsqInitFig() {
    signed int j; // r16
    signed int i; // r17

    for (i = 0; i < 2; i++) {
        vnmsqMidiOperate[i] = 0;
        vnmsqMidiState[i] = 1;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 0x20; j++) {
            vnmsqSesqOperate[i][j] = 0;
            vnmsqSesqState[i][j] = 1;
        }
    }
    vnmsqInterMVol = 0xFF;
    vnmsqFadeCnt = 0;
    nmsqInitOption();
    vnmsqExit = 0;
}

static void nmsqInitOption(void) {
    vnmsqOption.vol = 0xFF;
    vnmsqOption.loop = 0;
    vnmsqOption.wave = 0;
    vnmsqOption.bank = 0;
    vnmsqOption.sq = 0;
}

static void nmsqInitQue(void) {
    vnmsqQue.type = 0;
    vnmsqQue.process = 0;
    vnmsqQue.data[0] = 0;
    vnmsqQue.data[1] = 0;
    vnmsqQue.data[2] = 0;
    vnmsqQue.data[3] = 0;
    vnmsqQue.data[4] = 0;
    vnmsqQue.data[5] = 0;
}

static s32 nmsqProcessQue(void) {
    signed int i; // r16
    signed int tmp; // r17

    switch (vnmsqQue.type) {    
    case 0:
    default:
        break;
    case 1:
        if (vnmsqQue.process != 1) {
            break;
        }
        for (i = 0; i < 2; i++) {
            if (vnmsqMidiState[i] != 1) {
                return 0;
            }
        }
        tmp = nmsqResetData();
        if (tmp == -1) {
            scePrintf("nmsqResetData Error\n" /*@263*/);
            return -1;
        }
        nmsqInitQue();
        vnmsqExit = 0;
        break;
    case 2:
        if (vnmsqQue.process == 1) {
            vnmsqFadeCnt += 1;
            tmp = vnmsqQue.data[2] - ((vnmsqQue.data[2] * vnmsqFadeCnt) / vnmsqQue.data[1]);
            if (tmp < 0) {
                tmp = 0;
            }
            tmp = nmsqSetInterMVol(vnmsqQue.data[0], tmp);
            if (tmp == -1) {
                scePrintf("nmsqSetInterMVol Error\n" /*@264*/);
                return -1;
            }
            if (vnmsqFadeCnt >= vnmsqQue.data[1]) {
                vnmsqFadeCnt = 0;
                vnmsqQue.process = 2;
            }
            break;
        }
        if (vnmsqQue.process == 2) {
            tmp = nmsqStopMidi(vnmsqQue.data[0]);
            if (tmp == -1) {
                scePrintf("nmsqStopMidi Error\n" /*@265*/);
                return -1;
            }
            tmp = nmsndAssignChan(0x30);
            if (tmp == -1) {
                scePrintf("nmsndAssignChan Error\n" /*@266*/);
                return -1;
            }
            vnmsqQue.process = 3;
            break;
        }
        if (vnmsqQue.process == 3) {
            if (vnmsqMidiState[vnmsqQue.data[0]] == 1) {
                nmsqInitQue();
            }
            if (vnmsqExit == 1) {
                nmsqExit();
            }
        }
        break;
    }
    return 0;
}

static void nmsqCheckState(void) {
    signed int i; // r16

    for (i = 0; i < 2; i++) {
        switch (vnmsqMidiOperate[i]) {
        case 0:
            if ((vnmsqResult.midi_state[i] == 1) && (vnmsqMidiState[i] != 1)) {
                vnmsqMidiState[i] = 1;
            }
            break;
        case 1:
            if (vnmsqResult.midi_state[i] == 2) {
                vnmsqMidiOperate[i] = 0;
            }
            break;
        case 2:
            if ((vnmsqResult.midi_state[i] == 1) || (vnmsqResult.midi_state[i] == 0)) {
                vnmsqMidiState[i] = 1;
                vnmsqMidiOperate[i] = 0;
            }
            break;
        case 3:
            if (vnmsqResult.midi_state[i] == 3) {
                vnmsqMidiState[i] = 3;
                vnmsqMidiOperate[i] = 0;
            }
            break;
        case 4:
            if (vnmsqResult.midi_state[i] == 2) {
                vnmsqMidiState[i] = 2;
                vnmsqMidiOperate[i] = 0;
            }
            break;
        }
    }
}
