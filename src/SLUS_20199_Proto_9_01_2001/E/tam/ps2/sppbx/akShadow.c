#include "common.h"
#include "types.h"

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop)<<15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim)<<47) | ((unsigned long)(flg)<<58) | ((unsigned long)(nreg)<<60))

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.
#pragma fast_fptosi on // Trunc will be used instead of fptosi
#pragma dont_inline on

// SCE types ///////////////////////////////////////////////////////////////////////////
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// akShadow.c structs //////////////////////////////////////////////////////////////////

// Size: 0x90
typedef struct tag_ulcodCOORDINATE
{
    struct tag_ulcodCOORDINATE* super; // Offset: 0x0
    unsigned int flag; // Offset: 0x4
    unsigned int id; // Offset: 0x8
    signed int parent; // Offset: 0xC
    sceVu0FMATRIX mat; // Offset: 0x10
    sceVu0FMATRIX tmp; // Offset: 0x50
} tag_ulcodCOORDINATE;

// Size: 0x20
typedef struct ModelHeader
{
    char id[3]; // Offset: 0x0
    char version; // Offset: 0x3
    signed int nobj; // Offset: 0x4
    void* obj; // Offset: 0x8
    signed int ncoord; // Offset: 0xC
    tag_ulcodCOORDINATE* coord; // Offset: 0x10
    signed int _pad[3]; // Offset: 0x14
} ModelHeader;

typedef struct TexData
{
    signed short tofs; // Offset: 0x0
    signed short cofs; // Offset: 0x2
    signed short width; // Offset: 0x4
    signed short height; // Offset: 0x6
    signed short tw; // Offset: 0x8
    signed short th; // Offset: 0xA
    signed short image_bit; // Offset: 0xC
    signed short clut_bit; // Offset: 0xE
} TexData;

// Size: 0x18
typedef struct Shadow
{
    signed int pos0; // Offset: 0x0
    signed int pos1; // Offset: 0x4
    float len0; // Offset: 0x8
    float len1; // Offset: 0xC
    float wid; // Offset: 0x10
    signed int br; // Offset: 0x14
} Shadow;

// SCE includes /////////////////////////////////////////////////////////////////////
void sceVu0Normalize(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0SubVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void sceVu0AddVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void sceVu0ScaleVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float t);
void sceVu0FTOI4Vector(sceVu0IVECTOR v0, sceVu0FVECTOR v1);
void sceVu0MulMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FMATRIX m2);
void sceVu0ApplyMatrix(sceVu0FVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1);

//// External function prototypes ////////////////////////////////////////////////////
signed int ulcodGetLwMatrix(sceVu0FMATRIX mat, tag_ulcodCOORDINATE* coord);
void ulcodGetWsMatrix(sceVu0FMATRIX mat);
TexData* spfxGetTexData();
unsigned long ultexGetTEX0(TexData* data);
__int128* ulgraphAlphaOpenPacket(void* abuf);
signed int ulgraphAlphaClosePacket(void* abuf, signed int qwc, unsigned int z);

//// Function Declarations ///////////////////////////////////////////////////////////

void aksdwDrawShadowVuMdl(void* abuf, tag_ulcodCOORDINATE* coord, float* _lvec, float* _nor, float* ppos, float height, unsigned char* model, float thickness, signed int depth);
static void _DrawShadow(void* abuf, float (*pos)[4], float* nor, float thickness, signed int depth);
void aksdwMakeShadowMatrix(float (*smat)[4], float* lv, float* nv, float* pos, float height);

//// Variables ///////////////////////////////////////////////////////////////////////

Shadow shadow[] = {
    {6, 5, 3.8f, 1.2f, 2.6f, 0x80}, {5, 2, 1.7f, 2.3f, 3.5f, 0x80}, {8, 9, 0.8f, 0.8f, 1.4f, 0x40}, {9, 0xA, 0.8f, 1.2f, 1.4f, 0x40},
    {0xE, 0xF, 0.8f, 0.8f, 1.4f, 0x40}, {0xF, 0x10, 0.8f, 1.2f, 1.4f, 0x40}, {0x13, 0x14, 0.2f, 2.2f, 1.4f, 0x60}, {0x14, 0x15, 2.0f, 0.8f, 1.4f, 0x60},
    {0x17, 0x18, 0.2f, 2.2f, 1.4f, 0x60}, {0x18, 0x19, 2.0f, 0.8f, 1.4f, 0x60}, {0x15, 0x19, 5.0f, 5.0f, 3.0f, 0x80}, {-1, -1, 0.0f, 0.0f, 0.0f, 0},
};

//// Function Definitions ////////////////////////////////////////////////////////////

void aksdwDrawShadowVuMdl(void* abuf, tag_ulcodCOORDINATE* coord, float* _lvec, float* _nor, float* ppos, float height, unsigned char* model, float thickness, signed int depth) {
    float mat[4][4]; // 0x50(r29)
    float smat[4][4]; // 0x90(r29)
    float lw[4][4]; // 0xD0(r29)
    float pos[27][4]; // 0x110(r29)
    float fv[4]; // 0x2C0(r29)
    float lvec[4]; // 0x2D0(r29)
    float nor[4]; // 0x2E0(r29)
    tag_ulcodCOORDINATE* c; // r17
    ModelHeader* mhead; // r18
    signed int i; // r16
    float a; // 0x2FC(r29)

    sceVu0Normalize(lvec, _lvec);
    sceVu0Normalize(nor, _nor);
    a = 0.173648f + (lvec[0] * nor[0] + lvec[1] * nor[1] + lvec[2] * nor[2]);
    if (a <= 0.0f) {
        a = -a / 0.168372f;
        depth = (a > 1.0f) ? depth : (signed int)((float)depth * a);
        aksdwMakeShadowMatrix(smat, lvec, nor, ppos, height);
        ulcodGetLwMatrix(lw, coord);
        sceVu0MulMatrix(smat, smat, lw);
        for (i = 0; i < 0x1B; i++) {
            pos[i][3] = -1.0f;
        }
        mhead = (ModelHeader*)model;
        for (i = 0; i < mhead->ncoord; i++) {
            c = &mhead->coord[i];
            if (c->id < 0x1B) {
                ulcodGetLwMatrix(mat, c);
                fv[0] = mat[3][0];
                fv[1] = mat[3][1];
                fv[2] = mat[3][2];
                fv[3] = 1.0f;
                sceVu0ApplyMatrix(pos[c->id], smat, fv);
                sceVu0ApplyMatrix(fv, lw, fv);
                pos[c->id][3] = 0.5f + (pos[c->id][1] - fv[1]);
            }
        }
        _DrawShadow(abuf, pos, nor, thickness, depth);
    }
}

static void _DrawShadow(void* abuf, float (*pos)[4], float* nor, float thickness, signed int depth) {
    float v[4][4]; // 0xA0(r29)
    float vl0[4]; // 0xE0(r29)
    float vl1[4]; // 0xF0(r29)
    float vw[4]; // 0x100(r29)
    float fv[4][4]; // 0x110(r29)
    float st[4]; // 0x150(r29)
    signed int iv[4]; // 0x160(r29)
    float ws[4][4]; // 0x170(r29)
    float dz[4]; // 0x1B0(r29)
    signed int col[4] = {0x80, 0x80, 0x80, 0x18}; // 0x1C0(r29)
    float _stq[4][4] = {{0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 1.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 0.0f}, {1.0f, 0.0f, 1.0f, 0.0f}}; // 0x1D0(r29)
    float v1[4]; // 0x210(r29)
    float v2[4]; // 0x220(r29)
    float qq; // 0x230(r29)
    Shadow* s; // r19
    unsigned long tex0; // r30
    signed int f; // r18
    unsigned long* q; // r17
    float* p0; // r20
    float* p1; // r21
    signed int j; // r16
    signed int i; // r23

    tex0 = ultexGetTEX0(&spfxGetTexData()[8]);
    ulcodGetWsMatrix(ws);
    for (i = 0, s = shadow; s->pos0 >= 0; i++, s++) {
        p0 = pos[s->pos0];
        p1 = pos[s->pos1];
        if ((p0[3] < 0.0f) || (p1[3] < 0.0f)) {
            continue;
        }
        qq = p0[3] / 3.0f;
        dz[0] = dz[1] = (qq > 5.0f) ? 5.0f : ((qq < 0.0f) ? 0.0f : qq);
        qq = p1[3] / 3.0f;
        dz[2] = dz[3] = (qq > 5.0f) ? 5.0f : ((qq < 0.0f) ? 0.0f : qq);
        sceVu0SubVector(vl1, p0, p1);
        sceVu0Normalize(vl1, vl1);
        vw[0] = vl1[1] * nor[2] - vl1[2] * nor[1];
        vw[1] = vl1[2] * nor[0] - vl1[0] * nor[2];
        vw[2] = vl1[0] * nor[1] - vl1[1] * nor[0];
        vw[3] = 0.0f;
        sceVu0Normalize(vw, vw);
        sceVu0ScaleVector(vl0, vl1, s->len0 * thickness);
        sceVu0ScaleVector(vl1, vl1, s->len1 * thickness);
        sceVu0ScaleVector(vw, vw, s->wid * thickness);
        p0[3] = p1[3] = 1.0f;
        sceVu0AddVector(v[0], p0, vl0);
        sceVu0AddVector(v[1], v[0], vw);
        sceVu0SubVector(v[0], v[0], vw);
        sceVu0SubVector(v[2], p1, vl1);
        sceVu0SubVector(v[3], v[2], vw);
        sceVu0AddVector(v[2], v[2], vw);
        q = (unsigned long*)ulgraphAlphaOpenPacket(abuf);
        *q++ = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 3);
        *q++ = 0x7EE;
        *q++ = 0x42;
        *q++ = 0x43;
        *q++ = 0x51001;
        *q++ = 0x48;
        *q++ = tex0;
        *q++ = 0;
        *q++ = SCE_GIF_SET_TAG(1, 1, 1, 0x255, 0, 13);
        *q++ = 0xE412412412412;
        col[3] = (depth * s->br) >> 7;
        f = 0;
        for (j = 0; j < 4; j++) {
            sceVu0ApplyMatrix(fv[j], ws, v[j]);
            qq = 1.0f / fv[j][3];
            fv[j][0] *= qq;
            fv[j][1] *= qq;
            fv[j][2] /= (fv[j][3] - dz[j]);
            fv[j][3] = 0.0f;
            if ((fv[j][2] < 1.0f) || (fv[j][2] > 16777215.0f) || (fv[j][0] < 1024.0f) || (fv[j][0] > 3192.0f) || (fv[j][1] < 1024.0f) || (fv[j][1] > 3192.0f)) {
                f++;
                break;
            } else {
                sceVu0FTOI4Vector(iv, fv[j]);
                sceVu0ScaleVector(st, _stq[j], qq);
                *((__int128*)q)++ = *(__int128*)st;
                *((__int128*)q)++ = *(__int128*)col;
                *((__int128*)q)++ = *(__int128*)iv;
            }
        }
        if (f == 0) {
            sceVu0SubVector(v1, fv[1], fv[0]);
            sceVu0SubVector(v2, fv[2], fv[0]);
            if (v1[0] * v2[1] - v1[1] * v2[0] < 0.0f) {
                f = 1;
            } else {
                *q++ = 0x50000;
                *q++ = 0x48;
                ulgraphAlphaClosePacket(abuf, 0x12, iv[2]);
            }
        }
    }
}

void aksdwMakeShadowMatrix(float (*smat)[4], float* lv, float* nv, float* pos, float height) {
    float a; // 0x8(r29)
    float d; // 0xC(r29)

    d = 1.0f / (lv[0] * nv[0] + lv[1] * nv[1] + lv[2] * nv[2]);
    a = d * (nv[0] * pos[0] + nv[1] * height + nv[2] * pos[2]);
    smat[0][0] = 1.0f - d * (lv[0] * nv[0]);
    smat[1][0] = d * (-lv[0] * nv[1]);
    smat[2][0] = d * (-lv[0] * nv[2]);
    smat[3][0] = lv[0] * a;
    smat[0][1] = d * (-lv[1] * nv[0]);
    smat[1][1] = 1.0f - d * (lv[1] * nv[1]);
    smat[2][1] = d * (-lv[1] * nv[2]);
    smat[3][1] = lv[1] * a - 0.1f;
    smat[0][2] = d * (-lv[2] * nv[0]);
    smat[1][2] = d * (-lv[2] * nv[1]);
    smat[2][2] = 1.0f - d * (lv[2] * nv[2]);
    smat[3][2] = lv[2] * a;
    smat[0][3] = 0.0f;
    smat[1][3] = 0.0f;
    smat[2][3] = 0.0f;
    smat[3][3] = 1.0f;
}
