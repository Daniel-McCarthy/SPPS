#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi

//// Function Declarations ///////////////////////////////////////////////////////////

void nmeventInit();
signed int nmeventPlay(signed int id, signed int num);
signed int nmeventPlay2(signed int unused1, signed int num);
signed int nmeventPlayLoop(signed int id, signed int num);
signed int nmeventStop(signed int res);
signed int nmeventPlayWarp(signed int id, signed int num);
static signed int nmeventSearchRes();
signed int nmactGetVoiceVol(signed int id);
void nmvcSetOptLoop(signed int loop);
void nmvcSetOptVol(signed int vol, signed int pan);
signed int nmvcPlay(signed int res, signed int group, signed int num);
signed int nmvcStop(signed int res);
signed int nmvcGetState(signed int res);
void scePrintf(const char* fmt, ...);

//// Variables ///////////////////////////////////////////////////////////////////////

static signed int vnmeventSearchRes; // Address: 0x2E80C8

//// Function Definitions ////////////////////////////////////////////////////////////

void nmeventInit() {
    vnmeventSearchRes = 0x12;
}

signed int nmeventPlay(signed int id, signed int num) {
    signed int res; // r16
    signed int tmp; // r17

    res = nmeventSearchRes();
    nmvcSetOptVol(nmactGetVoiceVol(id), 0);
    tmp = nmvcPlay(res, 4, num);
    if (tmp == -1) {
        scePrintf("nmvcPlay Error\n");
        return -1;
    }
    return res;
}

signed int nmeventPlay2(signed int unused1, signed int num) {
    signed int res; // r16
    signed int tmp; // r17

    res = nmeventSearchRes();
    tmp = nmvcPlay(res, 4, num);
    if (tmp == -1) {
        scePrintf("nmvcPlay Error\n");
        return -1;
    }
    return res;
}

signed int nmeventPlayLoop(signed int id, signed int num) {
    signed int res; // r16
    signed int tmp; // r17

    nmvcSetOptLoop(1);
    res = id + 0x17;
    tmp = nmvcPlay(res, 4, num);
    if (tmp == -1) {
        scePrintf("nmvcPlay Error\n");
        return -1;
    }
    return res;
}

signed int nmeventStop(signed int res) {
    signed int tmp; // r16

    tmp = nmvcStop(res);
    if (tmp == -1) {
        scePrintf("nmvcStop Error\n");
        return -1;
    }
    return 0;
}

signed int nmeventPlayWarp(signed int id, signed int num) {
    signed int tmp; // r16
    signed int res; // r17

    nmvcSetOptVol(nmactGetVoiceVol(id), 0);
    res = nmeventSearchRes();
    tmp = nmvcPlay(res, 4, num);
    if (tmp == -1) {
        scePrintf("nmvcPlay Error\n");
        return -1;
    }
    return 0;
}

static signed int nmeventSearchRes() {
    signed int state; // r17
    signed int res; // r18
    signed int i; // r16

    for (i = 0; i < 5; i++) {
        state = nmvcGetState(vnmeventSearchRes);
        if (state == 1) {
            break;
        }
        if (vnmeventSearchRes < 0x16) {
            vnmeventSearchRes++;
        } else {
            vnmeventSearchRes = 0x12;
        }
    }
    res = vnmeventSearchRes;
    if (vnmeventSearchRes < 0x16) {
        vnmeventSearchRes++;
    } else {
        vnmeventSearchRes = 0x12;
    }
    return res;
}
