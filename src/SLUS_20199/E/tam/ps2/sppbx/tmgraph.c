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
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// tmgraph.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0x3F9D6
typedef struct Fog
{
    float min; // Offset: 0x0, DWARF: 0x3F9F1
    float max; // Offset: 0x4, DWARF: 0x3FA11
    float far; // Offset: 0x8, DWARF: 0x3FA31
    float near; // Offset: 0xC, DWARF: 0x3FA51
    signed int col[4]; // Offset: 0x10, DWARF: 0x3FA72
} Fog;

// Size: 0x30, DWARF: 0x4015C
typedef struct Prim
{
    unsigned long prim; // Offset: 0x0, DWARF: 0x40177
    unsigned long tex; // Offset: 0x8, DWARF: 0x40198
    unsigned long tex1; // Offset: 0x10, DWARF: 0x401B8
    unsigned long alpha; // Offset: 0x18, DWARF: 0x401D9
    unsigned long test; // Offset: 0x20, DWARF: 0x401FB
    unsigned int scissor; // Offset: 0x28, DWARF: 0x4021C
    // Size: 0x20, DWARF: 0x3F9D6
    Fog* fog; // Offset: 0x2C, DWARF: 0x40240
} Prim;

// Size: 0x10, DWARF: 0x3FE9C
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0, DWARF: 0x3FEB7
    unsigned int addr; // Offset: 0x4, DWARF: 0x3FEDA
    unsigned int z; // Offset: 0x8, DWARF: 0x3FEFB
    unsigned int _pad; // Offset: 0xC, DWARF: 0x3FF19
} ATag;

// Size: 0x20, DWARF: 0x3FB40
typedef struct Alpha
{
    unsigned int maxatag; // Offset: 0x0, DWARF: 0x3FB5B
    unsigned int natag; // Offset: 0x4, DWARF: 0x3FB7F
    unsigned int maxpkt; // Offset: 0x8, DWARF: 0x3FBA1
    unsigned int npkt; // Offset: 0xC, DWARF: 0x3FBC4
    // Size: 0x10, DWARF: 0x3FE9C
    ATag* atag; // Offset: 0x10, DWARF: 0x3FBE5
    // Size: 0x10, DWARF: 0x3FE9C
    ATag* curatag; // Offset: 0x14, DWARF: 0x3FC0B
    __int128* pkt; // Offset: 0x18, DWARF: 0x3FC34
    __int128* curpkt; // Offset: 0x1C, DWARF: 0x3FC57
} Alpha;

// Size: 0x30, DWARF: 0x3FC81
typedef struct Screen
{
    float aspect_x; // Offset: 0x0, DWARF: 0x3FC9C
    float aspect_y; // Offset: 0x4, DWARF: 0x3FCC1
    float center_x; // Offset: 0x8, DWARF: 0x3FCE6
    float center_y; // Offset: 0xC, DWARF: 0x3FD0B
    float clip_vol_x; // Offset: 0x10, DWARF: 0x3FD30
    float clip_vol_y; // Offset: 0x14, DWARF: 0x3FD57
    float min_z; // Offset: 0x18, DWARF: 0x3FD7E
    float max_z; // Offset: 0x1C, DWARF: 0x3FDA0
    float near_z; // Offset: 0x20, DWARF: 0x3FDC2
    float far_z; // Offset: 0x24, DWARF: 0x3FDE5
    float screen_z; // Offset: 0x28, DWARF: 0x3FE07
    float res; // Offset: 0x2C, DWARF: 0x3FE2C
} Screen;

// Size: 0x20, DWARF: 0x3F7B1
typedef struct Data
{
    float (*vertex)[4]; // Offset: 0x0, DWARF: 0x3F7CC
    float (*normal)[4]; // Offset: 0x4, DWARF: 0x3F7F4
    signed int (*rgba)[4]; // Offset: 0x8, DWARF: 0x3F81C
    float (*stq)[4]; // Offset: 0xC, DWARF: 0x3F842
    float width; // Offset: 0x10, DWARF: 0x3F867
    float height; // Offset: 0x14, DWARF: 0x3F889
    signed int res[2]; // Offset: 0x18, DWARF: 0x3F8AC
} Data;

// Size: 0x140, DWARF: 0x3FF8A
typedef struct Mat
{
    sceVu0FMATRIX local_screen; // Offset: 0x0, DWARF: 0x3FFA5
    sceVu0FMATRIX local_light; // Offset: 0x40, DWARF: 0x3FFD0
    sceVu0FMATRIX light_color; // Offset: 0x80, DWARF: 0x3FFFA
    sceVu0FMATRIX local_clip; // Offset: 0xC0, DWARF: 0x40024
    sceVu0FMATRIX clip_screen; // Offset: 0x100, DWARF: 0x4004D
} Mat;

// Size: 0x40, DWARF: 0x3FA98
typedef struct Scissor
{
    float clip[4] __attribute__((aligned(16))); // Offset: 0x0, DWARF: 0x3FAB3
    float stq[4]; // Offset: 0x10, DWARF: 0x3FAD6
    float rgba[4]; // Offset: 0x20, DWARF: 0x3FAF8
    unsigned int flag; // Offset: 0x30, DWARF: 0x3FB1B
} Scissor;

// Size: 0x340, DWARF: 0xC7FB6
typedef struct VspSystemMatrix
{
    // Size: 0x30, DWARF: 0xC6530
    Screen scr_info; // Offset: 0x0, DWARF: 0xC7FD2
    // Size: 0x20, DWARF: 0xC6972
    Fog fog; // Offset: 0x30, DWARF: 0xC7FF9
    // Size: 0x140, DWARF: 0xC6770
    Mat matrix; // Offset: 0x50, DWARF: 0xC801B
    sceVu0FMATRIX world_screen; // Offset: 0x190, DWARF: 0xC8040
    sceVu0FMATRIX world_view; // Offset: 0x1D0, DWARF: 0xC806B
    sceVu0FMATRIX view_screen; // Offset: 0x210, DWARF: 0xC8094
    sceVu0FMATRIX light_color; // Offset: 0x250, DWARF: 0xC80BE
    sceVu0FMATRIX normal_light; // Offset: 0x290, DWARF: 0xC80E8
    sceVu0FMATRIX view_clip; // Offset: 0x2D0, DWARF: 0xC8113
    sceVu0FVECTOR cam_rot; // Offset: 0x310, DWARF: 0xC813B
    sceVu0FVECTOR cam_trans; // Offset: 0x320, DWARF: 0xC8161
    float view_angle; // Offset: 0x330, DWARF: 0xC8189
    char padding[0xC]; // Not normally in struct but added to pad struct to size.
} VspSystemMatrix;

//// Variables ///////////////////////////////////////////////////////////////////////

//// Function Declarations ///////////////////////////////////////////////////////////

void tmgraphSetMatrix(sceVu0FMATRIX view_screen, sceVu0FMATRIX view_clip, sceVu0FMATRIX clip_screen, VspSystemMatrix* mtx);
void tmgraphGetFogCoef(float* coef_a, float* coef_b, // Size: 0x20, DWARF: 0x3F9D6
Fog* fog);
signed int tmgraphCheckClip(float* clip, float local_clip[4][4], float* vertex);
static signed int tmgraphCheckClipFlag(unsigned int flag);
static signed int tmgraphScissorAlphaPolyT(// Size: 0x20, DWARF: 0x3FB40
Alpha* alpha, // Size: 0x40, DWARF: 0x3FA98
Scissor* data, // Size: 0x140, DWARF: 0x3FF8A
Mat mat, // Size: 0x30, DWARF: 0x4015C
Prim prim);
static signed int tmgraphDivideMain(// Size: 0x40, DWARF: 0x3FA98
Scissor* data);
static void tmgraphDivideSub(// Size: 0x40, DWARF: 0x3FA98
Scissor* dst, // Size: 0x40, DWARF: 0x3FA98
Scissor* src1, // Size: 0x40, DWARF: 0x3FA98
Scissor* src2, float sign, unsigned int field);
void tmgraphRTPSpriteAddAlphaBufT__(// Size: 0x20, DWARF: 0x3FB40
Alpha* alpha, float screen_z, // Size: 0x20, DWARF: 0x3F7B1
Data* data, // Size: 0x140, DWARF: 0x3FF8A
Mat mat, // Size: 0x30, DWARF: 0x4015C
Prim prim);
void tmgraphRTPAddAlphaBufG_T__(// Size: 0x20, DWARF: 0x3FB40
Alpha* alpha, signed int num, // Size: 0x20, DWARF: 0x3F7B1
Data* data, // Size: 0x140, DWARF: 0x3FF8A
Mat mat, // Size: 0x30, DWARF: 0x4015C
Prim prim);

double fabs(double x);
void sceVu0ApplyMatrix(float* v0, sceVu0FMATRIX m, float* v1);
void sceVu0DivVector(float* v0, float* v1, float q);
void sceVu0FTOI4Vector(float* v0, float* v1);
void* memcpy(void* dst, const void* src, unsigned int n);
void ulgraphAlphaClosePacket(Alpha* alpha, signed int qwc, unsigned int ave_z);

//// Function Definitions ////////////////////////////////////////////////////////////

void tmgraphSetMatrix(sceVu0FMATRIX view_screen, sceVu0FMATRIX view_clip, sceVu0FMATRIX clip_screen, VspSystemMatrix* mtx) {
    // Size: 0x30, DWARF: 0x3FC81
    Screen screen = mtx->scr_info; // 0x10(r29)
    sceVu0FMATRIX mat; // 0x40(r29)
    float tmp; // 0x8C(r29)
    float az; // 0x90(r29)
    float cz; // 0x94(r29)
    float gsx; // 0x98(r29)
    float gsy; // 0x9C(r29)

    tmp = screen.far_z - screen.near_z;
    gsx = (screen.near_z * screen.clip_vol_x) / screen.screen_z;
    gsy = (screen.near_z * screen.clip_vol_y) / screen.screen_z;
    cz = (-screen.max_z * screen.near_z) + (screen.min_z * screen.far_z);
    cz = cz / tmp;
    az = ((screen.far_z * screen.near_z) * (-screen.min_z + screen.max_z)) / tmp;
    sceVu0UnitMatrix(view_screen);
    view_screen[0][0] = screen.screen_z;
    view_screen[1][1] = screen.screen_z;
    view_screen[2][2] = 0.0f;
    view_screen[3][3] = 0.0f;
    view_screen[3][2] = 1.0f;
    view_screen[2][3] = 1.0f;
    sceVu0UnitMatrix(&mat);
    mat[0][0] = screen.aspect_x;
    mat[1][1] = screen.aspect_y;
    mat[2][2] = az;
    mat[3][0] = screen.center_x;
    mat[3][1] = screen.center_y;
    mat[3][2] = cz;
    sceVu0MulMatrix(view_screen, &mat, view_screen);
    sceVu0UnitMatrix(view_clip);
    view_clip[0][0] = (2.0f * screen.near_z) / (gsx - -gsx);
    view_clip[1][1] = ((2.0f * screen.near_z) / (gsy - -gsy));
    view_clip[2][2] = (screen.far_z + screen.near_z);
    view_clip[2][2] /= tmp;
    view_clip[3][2] = (-2.0f * (screen.far_z * screen.near_z));
    view_clip[3][2] /= tmp;
    view_clip[2][3] = 1.0f;
    view_clip[3][3] = 0.0f;
    sceVu0UnitMatrix(clip_screen);
    clip_screen[0][0] = (gsx * (screen.screen_z * screen.aspect_x)) / screen.near_z;
    clip_screen[1][1] = ((gsy * (screen.screen_z * screen.aspect_y)) / screen.near_z);
    clip_screen[2][2] = ((-screen.max_z + screen.min_z) / 2.0f);
    clip_screen[3][2] = ((screen.max_z + screen.min_z) / 2.0f);
    clip_screen[3][0] = screen.center_x;
    clip_screen[3][1] = screen.center_y;
}

void tmgraphGetFogCoef(float* coef_a, float* coef_b, Fog* fog) {
    *coef_a = (fog->min + fog->max + (((fog->min - fog->max) * (fog->far + fog->near)) / (fog->far - fog->near))) / 2.0f;
    *coef_b = (fog->far * fog->near * (fog->max - fog->min)) / (fog->far - fog->near);
}

static signed int tmgraphCheckClipFlag(unsigned int flag) {
    if ((flag & 0x1041) == 0x1041) {
        return 1;
    }
    if ((flag & 0x2082) == 0x2082) {
        return 1;
    }
    if ((flag & 0x4104) == 0x4104) {
        return 1;
    }
    if ((flag & 0x8208) == 0x8208) {
        return 1;
    }
    if ((flag & 0x10410) == 0x10410) {
        return 1;
    }
    if ((flag & 0x20820) == 0x20820) {
        return 1;
    }
    return 0;
}

static signed int tmgraphScissorAlphaPolyT(Alpha* alpha, Scissor* data, Mat mat, Prim prim) {
    Scissor* work; // r5
    unsigned long* top; // r6
    unsigned long fprim; // r4
    unsigned int ave_z; // 0x1A8(r29)
    unsigned long* buf; // 0x1AC(r29)
    signed int qwc; // r5
    signed int num;

    num = tmgraphDivideMain(data);
    if (num == 0) {
        return 0;
    }
    work = (Scissor*)0x70001000;
    top = alpha->curpkt;
    buf = top;
    *buf++ = 0x1000000000000004;
    *buf++ = 0xE;
    *buf++ = prim.test;
    *buf++ = 0x48;
    *buf++ = prim.alpha;
    *buf++ = 0x43;
    *buf++ = prim.tex1;
    *buf++ = 0x15;
    *buf++ = prim.tex;
    *buf++ = 0x7;
    fprim = (prim.prim & 0x3F8) | 5;
    *buf++ = num | (1UL << 46) | (fprim << 47) | (3UL << 60);
    *buf++ = 0x412;
    ave_z = 0;
    asm (
        la v0, mat.clip_screen;
        lqc2 $vf1, 0x0(v0);
        lqc2 $vf2, 0x10(v0);
        lqc2 $vf3, 0x20(v0);
        lqc2 $vf4, 0x30(v0);
        la a3, buf;
        la t1, ave_z;
        lw a0, 0x0(a3);
        addu t0, num, zero;
        lw v0, 0x0(t1);
        nop;
    loop:
        lqc2 $vf5, 0x0(work);
        lqc2 $vf6, 0x10(work);
        lqc2 $vf7, 0x20(work);
        vmulax.xyzw $ACC, $vf1, $vf5x;
        vmadday.xyzw $ACC, $vf2, $vf5y;
        vmaddaz.xyzw $ACC, $vf3, $vf5z;
        vmaddw.xyzw $vf5, $vf4, $vf5w;
        vftoi0.xyzw $vf7, $vf7;
        vnop;
        vnop;
        vdiv $Q, $vf0w, $vf5w;
        vwaitq;
        vmulq.xyz $vf5, $vf5, $Q;
        vmulq.xyz $vf6, $vf6, $Q;
        vnop;
        vnop;
        vftoi4.xyzw $vf5, $vf5;
        sqc2 $vf6, 0x0(a0);
        sqc2 $vf7, 0x10(a0);
        sqc2 $vf5, 0x20(a0);
        addiu a0, a0, 0x28;
        addiu work, work, 0x40;
        lw v1, 0x0(a0);
        addu v0, v0, v1;
        addiu a0, a0, 0x8;
        addi t0, t0, -0x1;
        bne zero, t0, loop;
        sw v0, 0x0(t1);
        sw a0, 0x0(a3);
    );
    *buf++ = 0x1000000000008001;
    *buf++ = 0xE;
    *buf++ = 0x220;
    *buf++ = 0x15;
    ave_z = ave_z / num;
    if (ave_z > 0xFFFFFFF) {
        ave_z = 0xFFFFFFF;
    }
    qwc = ((unsigned int)buf - (unsigned int)top) / 16;
    ulgraphAlphaClosePacket(alpha, qwc, ave_z);
    return num;
}

static signed int tmgraphDivideMain(Scissor* data) {
    signed int id; // r16
    signed int jj; // r17
    signed int tmp; // r18
    signed int ii; // r19
    signed int cnt; // r20
    unsigned int flag; // r21
    Scissor* work[2]; // 0x70(r29)
    float sign; // 0x7C(r29)

    flag = (data[2].flag << 12) | (data[0].flag | (data[1].flag << 6));
    if (tmgraphCheckClipFlag(flag) != 0) {
        return 0;
    }
    id = 0;
    cnt = 0;
    work[0] = (Scissor*)0x70001000;
    work[1] = (Scissor*)0x70002800;
    for (ii = 0; ii < 3; ii++) {
        work[id][ii] = data[ii];
        cnt++;
    }
    for (ii = 5; ii >= 0; ii--) {
        work[id][cnt] = work[id][0];
        if (ii % 2) {
            sign = -1.0f;
        } else {
            sign = 1.0f;
        }
        tmp = 0;
        for (jj = 0; jj < cnt; jj++) {
            if ((1 << ii) & work[id][jj].flag) {
                if (((1 << ii) & work[id][jj + 1].flag) == 0) {
                    tmgraphDivideSub(&work[id ^ 1][tmp], &work[id][jj], &work[id][jj + 1], sign, ii / 2);
                    tmp++;
                }
            } else {
                work[id ^ 1][tmp] = work[id][jj];
                tmp++;
                if ((1 << ii) & work[id][jj + 1].flag) {
                    tmgraphDivideSub(&work[id ^ 1][tmp], &work[id][jj], &work[id][jj + 1], sign, ii / 2);
                    tmp++;
                }
            }
        }
        cnt = tmp;
        id ^= 1;
    }
    return cnt;
}

static void tmgraphDivideSub(Scissor* dst, Scissor* src1, Scissor* src2, float sign, unsigned int field) {
    unsigned int flag; // r3
    float tmp1;
    float tmp2;
    float tmp;

    flag = 0;
    tmp1 = src1->clip[3] * sign;
    tmp2 = src2->clip[3] * sign;
    tmp1 = src1->clip[field] - tmp1;
    tmp2 = src2->clip[field] - tmp2;
    sign = tmp2 - tmp1;
    sign = fabs(tmp1 / sign);
    asm (
        lqc2 $vf1, 0(src1);
        lqc2 $vf2, 0x10(src1);
        lqc2 $vf3, 0x20(src1);
        lqc2 $vf4, 0(src2);
        lqc2 $vf5, 0x10(src2);
        lqc2 $vf6, 0x20(src2);
        mfc1 a2, sign;
        nop;
        qmtc2 $a2, $vf10;
        vsub.xyzw $vf7, $vf4, $vf1;
        vsub.xyzw $vf8, $vf5, $vf2;
        vsub.xyzw $vf9, $vf6, $vf3;
        vmulx.xyzw $vf7, $vf7, $vf10x;
        vmulx.xyzw $vf8, $vf8, $vf10x;
        vmulx.xyzw $vf9, $vf9, $vf10x;
        vadd.xyzw $vf7, $vf1, $vf7;
        vadd.xyzw $vf8, $vf2, $vf8;
        vadd.xyzw $vf9, $vf3, $vf9;
        vclipw.xyz $vf7xyz, $vf7w;
        sqc2 $vf7, 0(dst);
        sqc2 $vf8, 0x10(dst);
        sqc2 $vf9, 0x20(dst);
        vnop;
        cfc2 flag,$vi18;
    );
    dst->flag = flag & 0x3F;
}

s32 tmgraphCheckClip(float* clip, float local_clip[4][4], float* vertex) {
    signed int ret = 0; // r2
    asm (
        lqc2 $vf5, 0($vertex);
        lqc2 $vf1, 0($local_clip);
        lqc2 $vf2, 0x10($local_clip);
        lqc2 $vf3, 0x20($local_clip);
        lqc2 $vf4, 0x30($local_clip);
        vmulax.xyzw $ACC, $vf1, $vf5x;
        vmadday.xyzw $ACC, $vf2, $vf5y;
        vmaddaz.xyzw $ACC, $vf3, $vf5z;
        vmaddw.xyzw $vf6, $vf4, $vf5w;
        vclipw.xyz $vf6xyz,$vf6w;
        vnop;
        vnop;
        vnop;
        sqc2    $vf6,0(clip);
        cfc2    v0,$vi18;
        andi    v0,v0,0x3f;
    );
}

void tmgraphRTPSpriteAddAlphaBufT__(Alpha* alpha, float screen_z, Data* data, Mat mat, Prim prim) {
    float tmp[4]; // 0x1F0(r29)
    float center[4]; // 0x200(r29)
    float fpos[4][4]; // 0x210(r29)
    float stq[4][4] = {
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 1.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 1.0f, 1.0f, 0.0f },
        { 1.0f, 1.0f, 1.0f, 0.0f }
    }; // 0x250(r29)
    float scr; // 0x29C(r29)
    unsigned long* work; // r16
    signed int ii; // r17
    signed int end; // r18
    unsigned int ave_z; // r19
    signed int qwc; // r20
    float* unused1;
    unsigned long* buf; // r22

    unused1 = &stq[0][0];
    (void)unused1;
    work = (unsigned long*)0x70000000;
    if (tmgraphCheckClip(tmp, mat.local_clip, data->vertex[0]) != 0) {
        return;
    }
    scr = screen_z / tmp[2];
    *work++ = 0x1000000000000004;
    *work++ = 0xE;
    *work++ = prim.test;
    *work++ = 0x48;
    *work++ = prim.alpha;
    *work++ = 0x43;
    *work++ = prim.tex1;
    *work++ = 0x15;
    *work++ = prim.tex;
    *work++ = 0x7;
    *work++ = (prim.prim << 47) | ((1UL << 46) | 4) | (3UL << 60);
    *work++ = 0x412;
    sceVu0ApplyMatrix(tmp, mat.clip_screen, tmp);
    sceVu0DivVector(center, tmp, tmp[3]);
    fpos[0][0] = center[0] - ((data->width / 2.0f) * scr);
    fpos[0][1] = center[1] + ((data->height / 2.0f) * scr);
    fpos[1][0] = center[0] + ((data->width / 2.0f) * scr);
    fpos[1][1] = center[1] + ((data->height / 2.0f) * scr);
    fpos[2][0] = center[0] - ((data->width / 2.0f) * scr);
    fpos[2][1] = center[1] - ((data->height / 2.0f) * scr);
    fpos[3][0] = center[0] + ((data->width / 2.0f) * scr);
    fpos[3][1] = center[1] - ((data->height / 2.0f) * scr);
    end = 0;
    for (ii = 0; ii < 4; ii++) {
        if ((fpos[ii][0] < 0.0f) || (fpos[ii][1] < 0.0f)) {
            end = 1;
            break;
        }
        if ((fpos[ii][0] > 4096.0f) || (fpos[ii][1] > 4096.0f)) {
            end = 1;
            break;
        }
        fpos[ii][2] = 2048.0f + center[2];
        fpos[ii][3] = 0.0f;
        sceVu0DivVector(work, stq[ii], tmp[3]);
        work += 2;
        memcpy(work, data[ii].rgba[0], 0x10);
        work += 2;
        sceVu0FTOI4Vector(work, fpos[ii]);
        ave_z = work[1];
        work += 2;
    }
    *work++ = 0x1000000000008001;
    *work++ = 0xE;
    *work++ = 0x220;
    *work++ = 0x15;
    if (end != 0) {
        return;
    }
    qwc = ((unsigned int)work - 0x70000000) >> 4;
    if (ave_z > 0xFFFFFFF) {
        ave_z = 0xFFFFFFF;
    }
    buf = alpha->curpkt;
    memcpy(buf, (unsigned long*)0x70000000, qwc * 16);
    ulgraphAlphaClosePacket(alpha, qwc, ave_z);
}

void tmgraphRTPAddAlphaBufG_T__(Alpha* alpha, signed int num, Data* data, Mat mat, Prim prim) {
    Scissor scissor[3]; // 0x200(r29)
    unsigned int flag; // r2
    signed int cnt; // r16
    signed int qwc; // r16
    signed int ii; // r17
    signed int* pos; // r18
    unsigned int ave_z; // r19
    unsigned long* work;
    unsigned long* buf; // r4

    work = (unsigned long*)0x70000000;
    ave_z = 0;
    cnt = 0;
    flag = 0;
    *work++ = 0x1000000000000004;
    *work++ = 0xE;
    *work++ = prim.test;
    *work++ = 0x48;
    *work++ = prim.alpha;
    *work++ = 0x43;
    *work++ = prim.tex1;
    *work++ = 0x15;
    *work++ = prim.tex;
    *work++ = 0x7;
    *work++ = num | (1UL << 46) | (prim.prim << 47) | (3UL << 60);
    *work++ = 0x412;
    for (ii = 0; ii < num; ii++) {
        asm (
            la v0, mat.local_clip;
            la v1, mat.clip_screen;
            lqc2 $vf1, 0x0(v0);
            lqc2 $vf2, 0x10(v0);
            lqc2 $vf3, 0x20(v0);
            lqc2 $vf4, 0x30(v0);
            lqc2 $vf5, 0x0(v1);
            lqc2 $vf6, 0x10(v1);
            lqc2 $vf7, 0x20(v1);
            lqc2 $vf8, 0x30(v1);
            la v0, scissor;
            lw v1, 0x0(data);
            lw a0, 0x8(data);
            lw a1, 0xC(data);
            lqc2 $vf17, 0x0(v1);
            lqc2 $vf19, 0x0(a0);
            lqc2 $vf20, 0x0(a1);
            vmulax.xyzw $ACC, $vf1, $vf17x;
            vmadday.xyzw $ACC, $vf2, $vf17y;
            vmaddaz.xyzw $ACC, $vf3, $vf17z;
            vmaddw.xyzw $vf17, $vf4, $vf17w;
            vitof0.xyzw $vf19, $vf19;
            sqc2 $vf20, 0x10(v0);
            sqc2 $vf17, 0x0(v0);
            vclipw.xyz $vf17xyz, $vf17w;
            sqc2 $vf19, 0x20(v0);
            vmulax.xyzw $ACC, $vf5, $vf17x;
            vmadday.xyzw $ACC, $vf6, $vf17y;
            vmaddaz.xyzw $ACC, $vf7, $vf17z;
            vmaddw.xyzw $vf17, $vf8, $vf17w;
            cfc2 flag, $vi18;
            vftoi0.xyzw $vf19, $vf19;
            vdiv $Q, $vf0w, $vf17w;
            vwaitq;
            vmulq.xyz $vf17, $vf17, $Q;
            vmulq.xyz $vf20, $vf20, $Q;
            vftoi4.xyzw $vf17, $vf17;
            sqc2 $vf20, 0x0(work);
            sqc2 $vf19, 0x10(work);
            sqc2 $vf17, 0x20(work);
            addiu work, work, 0x20;
            paddub pos, work, zero;
            addiu work, work, 0x10;
            andi flag, flag, 0x3f;
        );
        scissor[0].flag = flag;
        data++;
        if (scissor[0].flag != 0) {
            cnt = 3;
        }
        if (cnt != 0) {
            if ((prim.scissor != 0) && (ii >= 2)) {
                tmgraphScissorAlphaPolyT(alpha, scissor, mat, prim);
            }
            pos[3] = 0x8000;
            cnt--;
        } else {
            pos[3] = 0;
        }
        ave_z += pos[2];
        if (prim.scissor != 0) {
            scissor[2] = scissor[1];
            scissor[1] = scissor[0];
        }
    }
    *work++ = 0x1000000000008001;
    *work++ = 0xE;
    *work++ = 0x220;
    *work++ = 0x15;
    buf = alpha->curpkt;
    qwc = ((unsigned int)work - 0x70000000) >> 4;
    ave_z = ave_z / num;
    if (ave_z > 0xFFFFFFF) {
        ave_z = 0xFFFFFFF;
    }
    memcpy(buf, (unsigned long*)0x70000000, qwc * 16);
    ulgraphAlphaClosePacket(alpha, qwc, ave_z);
}
