// gmpad.c context
// Last updated 9/16/2024
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

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));


// Static data ///////////////////////////////////////////////////////////////////////

// gmpad.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0xB65A4
typedef struct PadState
{
    signed int id; // Offset: 0x0, DWARF: 0xB65BF
    unsigned int now; // Offset: 0x4, DWARF: 0xB65DE
    unsigned int status; // Offset: 0x8, DWARF: 0xB65FE
    unsigned int press; // Offset: 0xC, DWARF: 0xB6621
    signed char right_h; // Offset: 0x10, DWARF: 0xB6643
    signed char right_v; // Offset: 0x11, DWARF: 0xB6667
    signed char left_h; // Offset: 0x12, DWARF: 0xB668B
    signed char left_v; // Offset: 0x13, DWARF: 0xB66AE
    unsigned char l_right; // Offset: 0x14, DWARF: 0xB66D1
    unsigned char l_left; // Offset: 0x15, DWARF: 0xB66F5
    unsigned char l_up; // Offset: 0x16, DWARF: 0xB6718
    unsigned char l_down; // Offset: 0x17, DWARF: 0xB6739
    unsigned char r_up; // Offset: 0x18, DWARF: 0xB675C
    unsigned char r_right; // Offset: 0x19, DWARF: 0xB677D
    unsigned char r_down; // Offset: 0x1A, DWARF: 0xB67A1
    unsigned char r_left; // Offset: 0x1B, DWARF: 0xB67C4
    unsigned char r_1; // Offset: 0x1C, DWARF: 0xB67E7
    unsigned char l_1; // Offset: 0x1D, DWARF: 0xB6807
    unsigned char r_2; // Offset: 0x1E, DWARF: 0xB6827
    unsigned char l_2; // Offset: 0x1F, DWARF: 0xB6847
} PadState;

// Size: 0x60, DWARF: 0xB63ED
typedef struct VgmsysPadInfo
{
    // Size: 0x20, DWARF: 0xB65A4
    PadState now; // Offset: 0x0, DWARF: 0xB6408
    // Size: 0x20, DWARF: 0xB65A4
    PadState old; // Offset: 0x20, DWARF: 0xB642A
    unsigned int port; // Offset: 0x40, DWARF: 0xB644C
    unsigned int slot; // Offset: 0x44, DWARF: 0xB646D
    unsigned int mode; // Offset: 0x48, DWARF: 0xB648E
    unsigned int trg; // Offset: 0x4C, DWARF: 0xB64AF
    unsigned int rev; // Offset: 0x50, DWARF: 0xB64CF
    unsigned int cnt; // Offset: 0x54, DWARF: 0xB64EF
    unsigned int rep; // Offset: 0x58, DWARF: 0xB650F
    signed int state; // Offset: 0x5C, DWARF: 0xB652F
} VgmsysPadInfo;

//// Variables ///////////////////////////////////////////////////////////////////////

signed int vgmsysPadPausePid; // Address: 0x2E7B2C
signed int vgmsysPadResume; // Address: 0x2E7B20
// Size: 0x60, DWARF: 0xB63ED
VgmsysPadInfo vgmsysPadNull; // Address: 0x3BD360
// Size: 0x60, DWARF: 0xB63ED
VgmsysPadInfo* vgmsysPad[2]; // Address: 0x2E7B30
unsigned int vgmsysPadAllowPause; // Address: 0x2E7B24
signed int vgmsysPadSoftReset; // Address: 0x2E7B38
signed int vgmsysPadAllowSoftReset; // Address: 0x2E7B3C
signed int vgmsysPadPrePausePid; // Address: 0x2E7B28
// Size: 0x60, DWARF: 0xB63ED
VgmsysPadInfo vgmsysPadInfo[2]; // Address: 0x3BD3C0

//// Function Declarations ///////////////////////////////////////////////////////////

void gmsysPadInit();
void gmsysPadMain();
void gmsysPadReset();
void gmsysPadResume();
static void gmsysPadInitPadBuff();
static void gmsysPadInitPadOpe(// Size: 0x60, DWARF: 0xB63ED
VgmsysPadInfo* ope);
static void gmsysPadInitPadData(// Size: 0x20, DWARF: 0xB65A4
PadState* pad);
static void gmsysPadSetPadInfoLink();

//// Function Definitions ///////////////////////////////////////////////////////////

// DWARF: 0xB68C3
// Address: 0x1974D0
// Size: 0x50
void gmsysPadInit(void) {
    while (sceGsSyncV(0) == 0) {}
    ulpadInit(1, 1);
    gmsysPadReset();
}

// DWARF: 0xB697B
// Address: 0x197520
// Size: 0x1CC
void gmsysPadMain() {
    signed int i; // r16
    signed int num_player = 2; // r17
    signed int pid; // r18

    vgmsysPadPrePausePid = vgmsysPadPausePid;
    gmsysPadSetPadInfoLink();
    if (((vgmsysPad[0]->cnt & 0x90F) == 0x90F) && (vgmsysPadAllowSoftReset != 0)) {
        vgmsysPadSoftReset = 1;
    }
    if (((vgmsysPad[1]->cnt & 0x90F) == 0x90F) && (vgmsysPadAllowSoftReset != 0)) {
        vgmsysPadSoftReset = 1;
    }
    if (vgmsysPadPausePid < 0) {
        pid = -1;
        for (i = 0; i < num_player; i++) {
            if (vgmsysPadAllowPause & (1 << i)) {
                if ((vgmsysPad[i]->trg & 0x800) || (&vgmsysPad[i]->now == &vgmsysPadNull)) {
                    pid = i;
                }
            }
        }
        if (pid >= 0) {
            vgmsysPadPausePid = pid;
            vgmsysPadResume = 0;
            for (i = 0; i < num_player; i++) {
                ulpadSetDualPause(i, 0, -1, 1);
            }
        }
    } else if (vgmsysPadResume != 0) {
        vgmsysPadPausePid = -1;
        for (i = 0; i < num_player; i++) {
            ulpadSetDualPause(i, 0, -1, 0);
        }
    }
}

// DWARF: 0xB6AED
// Address: 0x1976F0
// Size: 0x90
void gmsysPadReset() {
    signed int i; // r16

    gmsysPadInitPadBuff();
    vgmsysPadAllowSoftReset = 0;
    vgmsysPadSoftReset = 0;
    vgmsysPadPausePid = -1;
    vgmsysPadPrePausePid = -1;
    vgmsysPadAllowPause = 0;
    vgmsysPadResume = 0;
    for (i = 0; i < 2; i++) {
        ulpadSetDualPause(i, 0, -1, 0);
        ulpadStopDual(i, 0, -1);
    }
}

// DWARF: 0xB6BF3
// Address: 0x197780
// Size: 0x10
void gmsysPadResume() {
    vgmsysPadResume = 1;
}

// DWARF: 0xB6C9C
// Address: 0x197790
// Size: 0x70
static void gmsysPadInitPadBuff() {
    signed int i; // r16

    for (i = 0; i < 2; i++) {
        gmsysPadInitPadOpe(&vgmsysPadInfo[i]);
    }
    gmsysPadInitPadOpe(&vgmsysPadNull);
}

// DWARF: 0xB6D98
// Address: 0x197800
// Size: 0x68
static void gmsysPadInitPadOpe(VgmsysPadInfo* ope) {
    gmsysPadInitPadData(&ope->now);
    gmsysPadInitPadData(&ope->old);
    ope->mode = 0;
    ope->trg = 0;
    ope->rev = 0;
    ope->cnt = 0;
    ope->rep = 0;
    ope->state = 0;
}

// DWARF: 0xB6E80
// Address: 0x197870
// Size: 0xAC
static void gmsysPadInitPadData(PadState* pad) {
    pad->now = 0;
    pad->status = 0;
    pad->press = 0;
    pad->right_h = 0;
    pad->right_v = 0;
    pad->left_h = 0;
    pad->left_v = 0;
    pad->l_right = 0;
    pad->l_left = 0;
    pad->l_up = 0;
    pad->l_down = 0;
    pad->r_right = 0;
    pad->r_left = 0;
    pad->r_up = 0;
    pad->r_down = 0;
    pad->l_1 = 0;
    pad->l_2 = 0;
    pad->r_1 = 0;
    pad->r_2 = 0;
}

// DWARF: 0xB6F59
// Address: 0x197920
// Size: 0x128
static void gmsysPadSetPadInfoLink() {
    signed int port; // r16
    signed int slot; // r17
    signed int con; // r18

    for (slot = 0; slot < 2; slot++) {
        vgmsysPad[slot] = 0;
    }
    port = 0;
    slot = 0;
    for (port = 0; port < 2; port++) {
        ulpadSetAna(port, slot, 1, 0);
        con = ulpadGet(&vgmsysPadInfo[port], port, slot);
        if (con) {
            vgmsysPad[port] = &vgmsysPadInfo[port];
        } else {
            vgmsysPad[port] = &vgmsysPadNull;
        }
    }
    ulpadUpdateDual();
}

