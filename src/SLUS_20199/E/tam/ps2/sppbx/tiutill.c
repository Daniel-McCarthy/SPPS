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
void sceVu0InterVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c, float d);

// C function includes
float sinf(float a);
float cosf(float a);
int rand(void);

static float _randtbl[100] = { // Address: 0x2D6D40
    0.606f, 0.707f, 0.808f, 0.939f, 0.7f,
    0.197f, 0.208f, 0.359f, 0.48f, 0.521f,
    0.635f, 0.724f, 0.873f, 0.962f, 0.201f,
    0.682f, 0.743f, 0.844f, 0.905f, 1.006f,
    0.243f, 0.464f, 0.684f, 0.896f, 0.925f,
    0.754f, 1.0f, 0.333f, 0.265f, 0.618f,
    0.101f, 0.262f, 0.303f, 0.404f, 0.535f,
    0.13f, 0.219f, 0.378f, 0.447f, 0.506f,
    0.143f, 0.264f, 0.384f, 0.496f, 0.525f,
    0.154f, 0.265f, 0.233f, 0.465f, 0.518f,
    0.606f, 0.783f, 0.808f, 0.399f, 0.07f,
    0.197f, 0.028f, 0.359f, 0.44f, 0.251f,
    1.0f, 0.983f, 0.808f, 1.0f, 0.07f,
    1.0f, 0.028f, 0.959f, 0.44f, 0.251f,
    0.243f, 0.464f, 0.684f, 0.896f, 0.925f,
    0.754f, 1.0f, 0.333f, 0.265f, 0.618f,
    0.943f, 0.754f, 0.954f, 0.646f, 0.765f,
    0.944f, 1.0f, 0.0f, 0.945f, 0.018f,
    0.502f, 0.264f, 0.844f, 0.946f, 0.255f,
    0.514f, 0.625f, 0.323f, 0.645f, 0.158f,
};

static short _randcnt = 0x64; // Address: 0x2E7934

float tiutRand(void) {
    if (_randcnt) {
        return _randtbl[(_randcnt-- - 1)];
    }
    _randcnt = 0x64;
    return _randtbl[(rand() % 100)];
}

float tiutVu0DistanceP2P(sceVu0FVECTOR v0 /* $a0 */, sceVu0FVECTOR v1 /* $a1 */) {
    float ret = 0.0f; // $f0

    asm {
        lqc2 $vf4, 0x0($a0)
        lqc2 $vf5, 0x0($a1)
        vsub.xyzw $vf6, $vf5, $vf4
        vmul.xyzw $vf6, $vf6, $vf6
        vaddy.x $vf6, $vf6, $vf6
        vaddz.x $vf6, $vf6, $vf6
        vsqrt $Q, $vf6x
        vwaitq
        vaddq.x $vf6, $vf0, $Q
        qmfc2.ni $v0, $vf6
        mtc1 $v0, ret
    }

    return ret;
}

signed int tiutVu0CrossL2L(sceVu0FVECTOR v0 /* 0x30(r29) */, sceVu0FVECTOR v1 /* 0x40(r29) */, sceVu0FVECTOR v2 /* 0x50(r29) */, sceVu0FVECTOR v3 /* 0x60(r29) */, sceVu0FVECTOR v4 /* 0x70(r29) */) {
    float a; // 0x1C(r29)
    float b; // 0x20(r29)
    float l0; // 0x24(r29)
    float l1; // 0x28(r29)
    float t; // 0x2C(r29)

    if ((v3[0] - v4[0]) != 0.0f) {
        a = (v3[2] - v4[2]) / (v3[0] - v4[0]);
        b = v3[2] - (a * v3[0]);
        l0 = b + ((a * v1[0]) - v1[2]);
        l1 = b + ((a * v2[0]) - v2[2]);
    } else {
        l0 = v1[0] - v3[0];
        l1 = v2[0] - v3[0];
    }
    if ((l0 * l1) < 0.0f) {
        if (l0 < 0.0f) {
            l0 = -l0;
        }
        if (l1 < 0.0f) {
            l1 = -l1;
        }
        t = l1 / (l0 + l1);
        sceVu0InterVector(v0, v1, v2, t);
        v0[3] = 1.0f;
        return 1;
    }
    return 0;
}

void tiutVu0AxisRotate(sceVu0FMATRIX m0 /* 0x20(r29) */, sceVu0FVECTOR v0 /* 0x30(r29) */, float r /* 0x40(r29) */) {
    float cs; // 0x14(r29)
    float si; // 0x18(r29)
    float l; // 0x1C(r29)

    cs = cosf(r);
    si = sinf(r);
    l = 1.0f - cs;

    m0[0][0] = cs + (l * (v0[0] * v0[0]));
    m0[0][1] = (l * (v0[0] * v0[1])) - (v0[2] * si);
    m0[0][2] = (l * (v0[0] * v0[2])) + (v0[1] * si);
    m0[1][0] = (l * (v0[1] * v0[0])) + (v0[2] * si);
    m0[1][1] = cs + (l * (v0[1] * v0[1]));
    m0[1][2] = (l * (v0[1] * v0[2])) - (v0[0] * si);
    m0[2][0] = (l * (v0[2] * v0[0])) - (v0[1] * si);
    m0[2][1] = (l * (v0[2] * v0[1])) + (v0[0] * si);
    m0[2][2] = cs + (l * (v0[2] * v0[2]));
}
