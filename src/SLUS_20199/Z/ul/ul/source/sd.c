#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi

// SCE includes /////////////////////////////////////////////////////////////////////
void sceSdRemoteInit();
int sceSdRemote(int arg, ...);
void* sceSifAllocIopHeap(int size);

// sd.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x8, DWARF: 0x1F314
typedef struct VulsdBatchIop
{
    unsigned short func; // Offset: 0x0
    unsigned short entry; // Offset: 0x2
    unsigned int value; // Offset: 0x4
} VulsdBatchIop;

// Size: 0x8, DWARF: 0x1F59B
typedef struct Vol
{
    signed int left; // Offset: 0x0
    signed int right; // Offset: 0x4
} Vol;

// Size: 0x14, DWARF: 0x1F398
typedef struct Attr
{
    signed int core; // Offset: 0x0
    signed int mode; // Offset: 0x4
    signed short depth_L; // Offset: 0x8
    signed short depth_R; // Offset: 0xA
    signed int delay; // Offset: 0xC
    signed int feedback; // Offset: 0x10
} Attr;

//// Variables ///////////////////////////////////////////////////////////////////////

static VulsdBatchIop vulsdBatch[64]; // Address: 0x2F3850
static VulsdBatchIop* vulsdBatchIop; // Address: 0x2E79FC
static unsigned int* vulsdBatchRet; // Address: 0x2E79F8
static signed int vulsdBatchCnt; // Address: 0x2E79F4

//// Function Declarations ///////////////////////////////////////////////////////////

void ulsdInit();
void ulsdSetMasterVol(signed int core, signed int mode, Vol vol);
void ulsdSetEffectReturnVol(signed int core, signed int mode, Vol vol);
void ulsdSetOutSideVol(signed int core, signed int mode, Vol vol);
void ulsdSetSoundDataVol(signed int core, signed int mode, Vol vol);
void ulsdSetEffectAttr(signed int core, Attr* snd_attr);
void ulsdSetMixAft(signed int core, signed int mode, signed int flag);
void ulsdSetEffectEndAddr(signed int core, signed int mode, signed int addr);
void ulsdSetEffectEnable(signed int core, signed int mode, signed int flag);
static signed int ulsdEntryBatch(unsigned short func, unsigned short entry, unsigned short value);

//// Function Definitions ////////////////////////////////////////////////////////////

// Address: 0x135F90
void ulsdInit(void) {
    sceSdRemoteInit();
    sceSdRemote(1, 0x8000, 0);
    vulsdBatchCnt = 0;
    vulsdBatchIop = (void*)sceSifAllocIopHeap(0x200);
    vulsdBatchRet = (void*)sceSifAllocIopHeap(0x100);
}

// Address: 0x135FF0
void ulsdSetMasterVol(signed int core /* 0x10(r29) */, signed int mode /* 0x20(r29) */, Vol vol /* 0x30(r29) */) {
    if (mode == 1) {
        sceSdRemote(1, 0x8010, core | 0x980, vol.left);
        sceSdRemote(1, 0x8010, core | 0xA80, vol.right);
        return;
    }
    ulsdEntryBatch(1, (core | 0x980), vol.left);
    ulsdEntryBatch(1, (core | 0xA80), vol.right);
}

// Address: 0x1360B0
void ulsdSetEffectReturnVol(signed int core /* 0x10(r29) */, signed int mode /* 0x20(r29) */, Vol vol /* 0x30(r29) */) {
    if (mode == 1) {
        sceSdRemote(1, 0x8010, core | 0xB80, vol.left);
        sceSdRemote(1, 0x8010, core | 0xC80, vol.right);
        return;
    }
    ulsdEntryBatch(1, (core | 0xB80), vol.left);
    ulsdEntryBatch(1, (core | 0xC80), vol.right);
}

// Address: 0x136170
void ulsdSetOutSideVol(signed int core /* 0x10(r29) */, signed int mode /* 0x20(r29) */, Vol vol /* 0x30(r29) */) {
    if (mode == 1) {
        sceSdRemote(1, 0x8010, core | 0xD80, vol.left);
        sceSdRemote(1, 0x8010, core | 0xE80, vol.right);
        return;
    }
    ulsdEntryBatch(1, (core | 0xD80), vol.left);
    ulsdEntryBatch(1, (core | 0xE80), vol.right);
}

// Address: 0x136230
void ulsdSetSoundDataVol(signed int core /* 0x10(r29) */, signed int mode /* 0x20(r29) */, Vol vol /* 0x30(r29) */) {
    if (mode == 1) {
        sceSdRemote(1, 0x8010, core | 0xF80, vol.left);
        sceSdRemote(1, 0x8010, core | 0x1080, vol.right);
        return;
    }
    ulsdEntryBatch(1, (core | 0xF80), vol.left);
    ulsdEntryBatch(1, (core | 0x1080), vol.right);
}

// Address: 0x1362F0
void ulsdSetEffectAttr(signed int core /* 0x30(r29) */, Attr* snd_attr /* 0x40(r29) */) {
    Attr attr; // 0x10(r29)

    attr = *snd_attr;
    sceSdRemote(1, 0x8130, core, &attr);
}

// Address: 0x136360
void ulsdSetMixAft(signed int core /* 0x10(r29) */, signed int mode /* 0x20(r29) */, signed int flag /* 0x30(r29) */) {
    if (mode == 1) {
        sceSdRemote(1, 0x8010, core | 0x800, flag);
        return;
    }
    ulsdEntryBatch(1, (core | 0x800), flag);
}

// Address: 0x1363E0
void ulsdSetEffectEndAddr(signed int core /* 0x10(r29) */, signed int mode /* 0x20(r29) */, signed int addr /* 0x30(r29) */) {
    if (mode == 1) {
        sceSdRemote(1, 0x8050, core | 0x1D00, addr);
        return;
    }
    ulsdEntryBatch(3, (core | 0x1D00), addr);
}

// Address: 0x136460
void ulsdSetEffectEnable(signed int core /* 0x10(r29) */, signed int mode /* 0x20(r29) */, signed int flag /* 0x30(r29) */) {
    if (mode == 1) {
        sceSdRemote(1, 0x8070, core | 2, flag);
        return;
    }
    ulsdEntryBatch(4, (core | 2), flag);
}

// Address: 0x1364E0
static signed int ulsdEntryBatch(unsigned short func /* 0x10(r29) */, unsigned short entry /* 0x20(r29) */, unsigned short value /* 0x30(r29) */) {
    signed int ret; // r16

    vulsdBatch[vulsdBatchCnt].func = func;
    vulsdBatch[vulsdBatchCnt].entry = entry;
    vulsdBatch[vulsdBatchCnt].value = value;
    ret = vulsdBatchCnt;
    vulsdBatchCnt += 1;
    return ret;
}
