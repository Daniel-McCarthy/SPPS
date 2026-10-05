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

// SCE includes /////////////////////////////////////////////////////////////////////
void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0ScaleVector(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0SubVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0MulVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0UnitMatrix(sceVu0FMATRIX a);
void sceVu0CopyVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2);
void sceVu0AddVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
float sceVu0InnerProduct(float* a, float* b);

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);

// tmetc.c structs //////////////////////////////////////////

// Size: 0x10, DWARF: 0x22FCDB
typedef struct Head
{
    signed int narea; // Offset: 0x0, DWARF: 0x22FCF6
    signed int res[3]; // Offset: 0x4, DWARF: 0x22FD18
} Head;

// Size: 0x30, DWARF: 0x22FBBE
typedef struct Data
{
    float vertex[2][4]; // Offset: 0x0, DWARF: 0x22FBD9
    signed short nblock; // Offset: 0x20, DWARF: 0x22FBFE
    signed short block[4]; // Offset: 0x22, DWARF: 0x22FC21
} Data;

// Size: 0xC, DWARF: 0x22FDD0
typedef struct Acc
{
    unsigned int top_addr; // Offset: 0x0, DWARF: 0x22FDEB
    // Size: 0x10, DWARF: 0x22FCDB
    Head* head; // Offset: 0x4, DWARF: 0x22FE10
    // Size: 0x30, DWARF: 0x22FBBE
    Data** data; // Offset: 0x8, DWARF: 0x22FE36
} Acc;

// Size: 0x8, DWARF: 0x22FE61
typedef struct Player
{
    signed int old_block; // Offset: 0x0, DWARF: 0x22FE7C
    signed int now_area; // Offset: 0x4, DWARF: 0x22FEA2
} Player;

// Size: 0x28, DWARF: 0x22FECB
typedef struct VtmetcSystem
{
    // Size: 0xC, DWARF: 0x22FDD0
    Acc acc; // Offset: 0x0, DWARF: 0x22FEE6
    // Size: 0xC, DWARF: 0x22FDD0
    Acc grp; // Offset: 0xC, DWARF: 0x22FF08
    // Size: 0x8, DWARF: 0x22FE61
    Player player[2]; // Offset: 0x18, DWARF: 0x22FF2A
} VtmetcSystem;

//// Function Declarations ////////////////////////////////////

void tmetcInit(unsigned char* acc, unsigned char* grp);
void tmetcEnd();
void tmetcReset();
signed int tmetcGetRank(float* p1, float* p2);
static void tmetcGetVerticalPoint(float* src, float* dst, float* pos, float* point);
void tmetcGetAcc(float* acc, float* pos);

// Included functions
signed int tmcrsChangeNo(signed int x, signed int y);
void tmcrsGetArea(signed int* x, signed int* y, float* pos);

//// Variables ////////////////////////////////////////////////

// Size: 0x28, DWARF: 0x22FECB
static VtmetcSystem vtmetcSystem; // Address: 0x3C9860

//// Function Definitions ////////////////////////////////////////////////

void tmetcInit(unsigned char* acc /* 0x50(r29) */, unsigned char* grp /* 0x60(r29) */) {
    signed int jj; // r16
    signed int ii; // r17
    signed char* xy; // r18
    unsigned int* data; // r19

    vtmetcSystem.acc.data = 0;
    vtmetcSystem.grp.data = 0;
    vtmetcSystem.acc.top_addr = (int)acc;
    vtmetcSystem.grp.top_addr = (int)grp;
    vtmetcSystem.acc.head = (Head*)vtmetcSystem.acc.top_addr;
    vtmetcSystem.grp.head = (Head*)vtmetcSystem.grp.top_addr;
    vtmetcSystem.acc.data = (Data**)vtmetcSystem.acc.top_addr + 4;
    vtmetcSystem.grp.data = (Data**)vtmetcSystem.grp.top_addr + 4;
    data = (unsigned int*)vtmetcSystem.acc.data;
    for (ii = 0; ii < vtmetcSystem.acc.head->narea; ii++) {
        *data += vtmetcSystem.acc.top_addr;
        for (jj = 0; jj < vtmetcSystem.acc.data[ii][0].nblock; jj++) {
            xy = (signed char*)&vtmetcSystem.acc.data[ii][0].block[jj];
            vtmetcSystem.acc.data[ii][0].block[jj] = tmcrsChangeNo(xy[1], xy[0]);
        }
        data += 1;
    }
    data = (unsigned int*)vtmetcSystem.grp.data;
    for (ii = 0; ii < vtmetcSystem.grp.head->narea; ii++) {
        *data += vtmetcSystem.grp.top_addr;
        for (jj = 0; jj < vtmetcSystem.grp.data[ii][0].nblock; jj++) {
            xy = (signed char*)&vtmetcSystem.grp.data[ii][0].block[jj];
            vtmetcSystem.grp.data[ii][0].block[jj] = tmcrsChangeNo(xy[1], xy[0]);
        }
        data += 1;
    }
    tmetcReset();
}

void tmetcEnd() {
}

void tmetcReset() {
    signed int ii; // r16
    for (ii = 0; ii < 2; ii++) {
        vtmetcSystem.player[ii].old_block = -1;
        vtmetcSystem.player[ii].now_area = 0;
    }
}

signed int tmetcGetRank(float* p1 /* 0xE0(r29) */, float* p2 /* 0xF0(r29) */) {
    signed int kk; // r16
    // Size: 0x30, DWARF: 0x22FBBE
    Data* data; // r17
    signed int jj; // r18
    signed int area; // r19
    signed int flg; // r20
    signed int ii; // r21
    signed int block; // r22
    signed int rank = 0; // r23
    float pos[2][4]; // 0x90(r29)
    float tmp[4]; // 0xB0(r29)
    signed int x[2]; // 0xC8(r29)
    signed int y[2]; // 0xD0(r29)
    float len[2]; // 0xD8(r29)

    tmcrsGetArea(&x[0], &y[0], p1);
    tmcrsGetArea(&x[1], &y[1], p2);
    for (ii = 0; ii < 2; ii++) {
        block = tmcrsChangeNo(x[ii], y[ii]);
        if (block != vtmetcSystem.player[ii].old_block) {
            vtmetcSystem.player[ii].old_block = block;
            area = vtmetcSystem.player[ii].now_area;
            flg = 0;
            for (jj = 0; jj < vtmetcSystem.grp.head->narea; jj++) {
                data = vtmetcSystem.grp.data[(jj + area) % vtmetcSystem.grp.head->narea];
                for (kk = 0; kk < data->nblock; kk++) {
                    if (block == data->block[kk]) {
                        flg = 1;
                        vtmetcSystem.player[ii].now_area = (jj + area) % vtmetcSystem.grp.head->narea;
                        break;
                    }
                }
                if (flg) {
                    break;
                }
            }
        }
    }
    if (vtmetcSystem.player[0].now_area > vtmetcSystem.player[1].now_area) {
        rank = 0;
        goto block_24;
    }
    if (vtmetcSystem.player[0].now_area < vtmetcSystem.player[1].now_area) {
        rank = 1;
        goto block_24;
    }
    data = vtmetcSystem.grp.data[vtmetcSystem.player[0].now_area];
    if (data == 0) {
        return 0;
    }
    tmetcGetVerticalPoint(data->vertex[0], data->vertex[1], p1, pos[0]);
    sceVu0SubVector(tmp, pos[0], data->vertex[0]);
    sceVu0MulVector(tmp, tmp, tmp);
    len[0] = tmp[0] + tmp[1] + tmp[2];
    data = vtmetcSystem.grp.data[vtmetcSystem.player[1].now_area];
    if (data == 0) {
        return 0;
    }
    tmetcGetVerticalPoint(data->vertex[0], data->vertex[1], p2, pos[1]);
    sceVu0SubVector(tmp, pos[1], data->vertex[0]);
    sceVu0MulVector(tmp, tmp, tmp);
    len[1] = tmp[0] + tmp[1] + tmp[2];
    if (len[0] < len[1]) {
        rank = 1;
    } else {
        rank = 0;
    }
block_24:
    return rank;
}

static void tmetcGetVerticalPoint(sceVu0FVECTOR src, sceVu0FVECTOR dst, sceVu0FVECTOR pos, sceVu0FVECTOR point) {
    sceVu0FVECTOR normal; // 0x10(r29)
    sceVu0FVECTOR tmp; // 0x20(r29)
    sceVu0SubVector(normal, dst, src);
    sceVu0Normalize(normal, normal);
    sceVu0SubVector(tmp, pos, src);
    sceVu0MulVector(tmp, normal, tmp);
    sceVu0ScaleVector(tmp, normal, tmp[0] + tmp[1] + tmp[2]);
    sceVu0AddVector(point, tmp, src);
}

void tmetcGetAcc(float* acc, float* pos) {
    // Size: 0x30, DWARF: 0x22FBBE
    Data* data; // r16
    signed int jj; // r17
    signed int flg; // r18
    signed int block; // r19
    signed int ii; // r20
    signed int x; // 0x68(r29)
    signed int y; // 0x6C(r29)

    acc[0] = 0.0f;
    acc[1] = 0.0f;
    acc[2] = -1.0f;
    acc[3] = 1.0f;
    flg = 0;
    tmcrsGetArea(&x, &y, pos);
    block = tmcrsChangeNo(x, y);
    for (ii = 0; ii < vtmetcSystem.acc.head->narea; ii++) {
        data = vtmetcSystem.acc.data[ii];
        for (jj = 0; jj < ((data->nblock)); jj++) {
            if (block == data->block[jj]) {
                flg = 1;
                sceVu0SubVector(acc, data->vertex[1], data->vertex[0]);
                break;
            }
        }
        if (flg)
            break;
    }
}
