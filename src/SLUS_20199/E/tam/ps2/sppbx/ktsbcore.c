#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// ktsbcore.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x30, DWARF: 0x1737CD
typedef struct Plane
{
    float cross[4] __attribute__((aligned (16))); // Offset: 0x0, DWARF: 0x1737E8
    float normal[4]; // Offset: 0x10, DWARF: 0x17380C
    unsigned short material; // Offset: 0x20, DWARF: 0x173831
    unsigned short attribute; // Offset: 0x22, DWARF: 0x173856
    signed short almighty1; // Offset: 0x24, DWARF: 0x17387C
    signed short almighty2; // Offset: 0x26, DWARF: 0x1738A2
    signed short almighty3; // Offset: 0x28, DWARF: 0x1738C8
    signed short slidable; // Offset: 0x2A, DWARF: 0x1738EE
    signed int available; // Offset: 0x2C, DWARF: 0x173913
} Plane;

// Size: 0x1F0, DWARF: 0x173961
typedef struct Sbcore
{
    float nextpos[4]; // Offset: 0x0, DWARF: 0x17397C
    float speed[4]; // Offset: 0x10, DWARF: 0x1739A2
    float rot_pole; // Offset: 0x20, DWARF: 0x1739C6
    float max_relief_gap; // Offset: 0x24, DWARF: 0x1739EB
    signed int freefoot; // Offset: 0x28, DWARF: 0x173A16
    float limit_ang_down; // Offset: 0x2C, DWARF: 0x173A3B
    float limit_ang_up; // Offset: 0x30, DWARF: 0x173A66
    signed int set_sp_normal; // Offset: 0x34, DWARF: 0x173A8F
    float pos_head[4] __attribute__((aligned (16))); // Offset: 0x40, DWARF: 0x173AB9
    float pos_hip[4] __attribute__((aligned (16))); // Offset: 0x50, DWARF: 0x173AE0
    signed int move_head; // Offset: 0x60, DWARF: 0x173B06
    float ang_slidable_limit; // Offset: 0x64, DWARF: 0x173B2C
    float pos[4] __attribute__((aligned (16))); // Offset: 0x70, DWARF: 0x173B5B
    float pole[4]; // Offset: 0x80, DWARF: 0x173B7D
    float sp_normal[4]; // Offset: 0x90, DWARF: 0x173BA0
    signed int sliding; // Offset: 0xA0, DWARF: 0x173BC8
    float relief_gap; // Offset: 0xA4, DWARF: 0x173BEC
    float touch_posy; // Offset: 0xA8, DWARF: 0x173C13
    float const_max_relief_gap; // Offset: 0xAC, DWARF: 0x173C3A
    float const_under_foot; // Offset: 0xB0, DWARF: 0x173C6B
    signed int const_keep_normal; // Offset: 0xB4, DWARF: 0x173C98
    float height; // Offset: 0xB8, DWARF: 0x173CC6
    signed int cnt_keep_normal; // Offset: 0xBC, DWARF: 0x173CE9
    signed int move; // Offset: 0xC0, DWARF: 0x173D15
    // Size: 0x30, DWARF: 0x1737CD
    Plane plane_hit __attribute__((aligned (16))); // Offset: 0xD0, DWARF: 0x173D36
    // Size: 0x30, DWARF: 0x1737CD
    Plane plane_sliding; // Offset: 0x100, DWARF: 0x173D5E
    // Size: 0x30, DWARF: 0x1737CD
    Plane plane_beneath; // Offset: 0x130, DWARF: 0x173D8A
    // Size: 0x30, DWARF: 0x1737CD
    Plane plane_body; // Offset: 0x160, DWARF: 0x173DB6
    // Size: 0x30, DWARF: 0x1737CD
    Plane plane_hit_buff; // Offset: 0x190, DWARF: 0x173DDF
    // Size: 0x30, DWARF: 0x1737CD
    Plane plane_pre_hit; // Offset: 0x1C0, DWARF: 0x173E0C
} Sbcore;

// Size: 0x300, DWARF: 0x173E60
typedef struct Ps
{
    // Size: 0x30, DWARF: 0x1737CD
    Plane plane[8]; // Offset: 0x0, DWARF: 0x173E7B
    float from[8][4]; // Offset: 0x180, DWARF: 0x173E9F
    float to[8][4]; // Offset: 0x200, DWARF: 0x173EC2
    signed int move[8]; // Offset: 0x280, DWARF: 0x173EE3
    float height[8]; // Offset: 0x2A0, DWARF: 0x173F06
    signed int ret[8]; // Offset: 0x2C0, DWARF: 0x173F2B
    signed int touch; // Offset: 0x2E0, DWARF: 0x173F4D
    signed int num; // Offset: 0x2E4, DWARF: 0x173F6F
    signed int ofs; // Offset: 0x2E8, DWARF: 0x173F8F
    signed int id_touch; // Offset: 0x2EC, DWARF: 0x173FAF
    signed int id_head; // Offset: 0x2F0, DWARF: 0x173FD4
    signed int id_body; // Offset: 0x2F4, DWARF: 0x173FF8
} Ps;

// DWARF: 0x173757
typedef enum ESCM_Grind_Type
{
    escmtNormal,
    escmtGrind,
    escmtToGrind
} ESCM_Grind_Type;

//// Function Declarations ///////////////////////////////////////////////////////////

// SCE includes /////////////////////////////////////////////////////////////////////
void sceVu0AddVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0SubVector(sceVu0FVECTOR a, sceVu0FVECTOR b, sceVu0FVECTOR c);
void sceVu0ScaleVector(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0Normalize(sceVu0FVECTOR a, sceVu0FVECTOR b);
float sceVu0InnerProduct(float* a, float* b);
void sceVu0OuterProduct(float* a, float* b, float* c);
void sceVu0InterVector(float a[4], float b[4], float c[4], float d);
void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);
void sceVu0RotMatrix(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, sceVu0FVECTOR rot);
void sceVu0TransposeMatrix(sceVu0FMATRIX mat, sceVu0FMATRIX mat2);
void sceVu0ApplyMatrix(sceVu0FVECTOR vec, sceVu0FMATRIX mat, sceVu0FVECTOR vec2);
void sceVu0MulVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2, sceVu0FVECTOR vec3);
void sceVu0CopyVector(sceVu0FVECTOR vec, sceVu0FVECTOR vec2);
void sceVu0UnitMatrix(sceVu0FMATRIX a);
void sceVu0InversMatrix(sceVu0FMATRIX a, sceVu0FMATRIX b);
float sqrtf(float a);
float tanf(float a);
float atan2f(float y, float x);
float sinf(float a);
float cosf(float a);
float acosf(float a);

float isbcoreSqrtf(float var);
void isbcoreGetNextPos(float* next, float* now, float* speed);
float isbcoreGetLen(float* v);
float isbcoreGetLenXZ(float* v);
// Size: 0x1F0, DWARF: 0x173961
void sbcoreInit(Sbcore* cd);
// Size: 0x30, DWARF: 0x1737CD
void sbcoreInitPLANE(Plane* pl);
// Size: 0x300, DWARF: 0x173E60
static void sbcoreInitPLANESET(Ps* ps);
void sbcoreSetNextPos(Sbcore* cd);
signed int sbcoreSetNextPosOnVertexList(Sbcore* cd, signed int current_id, sceVu0FVECTOR* vertex_list, signed int num_vertex);
signed int sbcoreSetNextPosOnVertexListHP(Sbcore* cd, signed int current_id, sceVu0FVECTOR* vertex_list, signed int num_vertex);
// DWARF: 0x173757
signed int sbcoreMove(Sbcore* cd, ESCM_Grind_Type type);
static signed int sbcoreCheckSliding(Ps* ps, Sbcore* cd);
static signed int sbcoreCheckGrind(Ps* ps, Sbcore* cd, signed int kill_far);
static signed int sbcoreAdjTouch(Plane* pl, Sbcore* cd, signed int hit);
static void sbcoreGetCheckTouchArea(float* from, float* to, Sbcore* cd, float* pos);
static void sbcoreGetCheckHeightArea(float* from, float* to, float* pos, signed int ofs);
static void sbcoreGetCheckHeightArea_onair(float* from1, float* to1, float* from2, float* to2, float* pos, float* pole, float rot_pole);
static signed int sbcoreUpdateReliefGap(Sbcore* cd, Plane* pl);
static void sbcoreAdjOnSliding(float* new_next, Sbcore* cd, Plane* pl, signed int use_pole);
static void sbcoreUpdateOnSliding(Sbcore* cd, Plane* pl, float* next);
static void sbcoreUpdateOnAir(Sbcore* cd, Plane* pl, float* next);
void sbcoreGetRotMatrix(sceVu0FMATRIX mat, float* pole, float rot_pole);
void sbcoreGetShadowVector(float* out, float* nor, float* vec);
void sbcoreGetShadowRotVector(float* out, float* nor, float* vec);
void sbcoreGetShadowVectorXZ(float* out, float* nor, float* vec);
void sbcoreGetShadowVector2(float* out, float* snor, float* wnor, float* vec);
void sbcoreGetShadowVector3(float* out, float* snor, float* wnor1, float* wnor2, float* vec);
void sbcoreGetMirrorVector(float* out, float* nor, float* vec);
void sbcoreGetMirrorVector_angle(float* out, float* nor, float* vec, float ang);
float sbcoreGetInnerAngle90(float* vec0, float* vec1);
float sbcoreGetInnerAngle180(float* vec0, float* vec1);

// Additional C includes
// Size: 0x30, DWARF: 0x79C3C
signed int sbcoreGetHit(Plane* pl, float* from, float* to, signed int move, float height, signed int kill_far); // From Ktact.c
// Size: 0x300, DWARF: 0x7AA0C
void sbcoreGetHit2(Ps* ps);

//// Function Definitions ////////////////////////////////////////////////

void sbcoreInit(// Size: 0x1F0, DWARF: 0x173961
    Sbcore* cd) {
    cd->nextpos[0] = 0.0f;
    cd->nextpos[1] = 0.0f;
    cd->nextpos[2] = 0.0f;
    cd->nextpos[3] = 0.0f;
    cd->speed[0] = 0.0f;
    cd->speed[1] = 0.0f;
    cd->speed[2] = 0.0f;
    cd->speed[3] = 0.0f;
    cd->rot_pole = 0.0f;
    cd->max_relief_gap = 5.1f;
    cd->freefoot = 0;
    cd->limit_ang_down = 0.95993096f;
    cd->limit_ang_up = 1.0471973f;
    cd->set_sp_normal = 0;
    cd->pos_head[0] = 0.0f;
    cd->pos_head[1] = 0.0f;
    cd->pos_head[2] = 0.0f;
    cd->pos_head[3] = 0.0f;
    cd->pos_hip[0] = 0.0f;
    cd->pos_hip[1] = 0.0f;
    cd->pos_hip[2] = 0.0f;
    cd->pos_hip[3] = 0.0f;
    cd->move_head = 1;
    cd->ang_slidable_limit = 1.570796f;
    cd->pos[0] = 0.0f;
    cd->pos[1] = 0.0f;
    cd->pos[2] = 0.0f;
    cd->pos[3] = 0.0f;
    cd->pole[0] = 0.0f;
    cd->pole[1] = -1.0f;
    cd->pole[2] = 0.0f;
    cd->pole[3] = 0.0f;
    cd->sp_normal[0] = 0.0f;
    cd->sp_normal[1] = -1.0f;
    cd->sp_normal[2] = 0.0f;
    cd->sp_normal[3] = 0.0f;
    cd->sliding = 1;
    cd->relief_gap = 0.0f;
    cd->touch_posy = 0.0f;
    cd->const_max_relief_gap = 5.1f;
    cd->const_under_foot = 1.02f;
    cd->const_keep_normal = 0;
    cd->height = 0.0f;
    cd->cnt_keep_normal = 0;
    cd->move = 0;
    sbcoreInitPLANE(&cd->plane_hit);
    sbcoreInitPLANE(&cd->plane_sliding);
    sbcoreInitPLANE(&cd->plane_beneath);
    sbcoreInitPLANE(&cd->plane_body);
    sbcoreInitPLANE(&cd->plane_hit_buff);
    sbcoreInitPLANE(&cd->plane_pre_hit);
}

void sbcoreInitPLANE(// Size: 0x30, DWARF: 0x1737CD
    Plane* pl) {
    pl->cross[0] = 0.0f;
    pl->cross[1] = 0.0f;
    pl->cross[2] = 0.0f;
    pl->cross[3] = 0.0f;
    pl->normal[0] = 0.0f;
    pl->normal[1] = 0.0f;
    pl->normal[2] = 0.0f;
    pl->normal[3] = 0.0f;
    pl->material = 0;
    pl->attribute = 0;
    pl->almighty1 = 0;
    pl->almighty2 = 0;
    pl->almighty3 = 0;
    pl->slidable = 0;
    pl->available = 0;
}

static void sbcoreInitPLANESET(// Size: 0x300, DWARF: 0x173E60
    Ps* ps) {
    signed int i; // r16

    for (i = 0; i < 8; i++) {
        sbcoreInitPLANE(&ps->plane[i]);
        ps->from[i][0] = 0.0f;
        ps->from[i][1] = 0.0f;
        ps->from[i][2] = 0.0f;
        ps->from[i][3] = 0.0f;
        ps->to[i][0] = 0.0f;
        ps->to[i][1] = 0.0f;
        ps->to[i][2] = 0.0f;
        ps->to[i][3] = 0.0f;
        ps->move[i] = 0;
        ps->height[i] = 0.0f;
        ps->ret[i] = 0;
    }
    ps->touch = 0;
    ps->num = 0;
    ps->ofs = 0;
    ps->id_touch = -1;
    ps->id_head = -1;
    ps->id_body = -1;
}

void sbcoreSetNextPos(// Size: 0x1F0, DWARF: 0x173961
    Sbcore* cd) {
    isbcoreGetNextPos(cd->nextpos, cd->pos, cd->speed);
}

void isbcoreGetNextPos(float* next, float* now, float* speed) {
    sceVu0ScaleVectorXYZ(next, speed, 0.16666667);
    sceVu0AddVector(next, next, now);
    next[3] = 0.0f;
}

s32 sbcoreSetNextPosOnVertexList(// Size: 0x1F0, DWARF: 0x173961
    Sbcore* cd, signed int current_id, sceVu0FVECTOR* vertex_list, signed int num_vertex) {
    sceVu0FVECTOR* from; // r16
    sceVu0FVECTOR* to; // r17
    signed int vec_goback; // r18
    signed int loop; // r19
    signed int next_id; // r20
    float rail[4]; // 0x60(r29)
    float sp[4]; // 0x70(r29)
    float now[4]; // 0x80(r29)
    float next[4]; // 0x90(r29)
    float nor[4]; // 0xA0(r29)
    float rsp[4]; // 0xB0(r29)
    float v0[4]; // 0xC0(r29)
    float v1[4]; // 0xD0(r29)
    float inner0; // 0xEC(r29)
    float inner1; // 0xF0(r29)
    float splen; // 0xF4(r29)
    float splen0; // 0xF8(r29)
    float d; // 0xFC(r29)
    float a; // 0x100(r29)
    float b; // 0x104(r29)
    float len0; // 0x108(r29)
    float len1; // 0x10C(r29)

    *(__int128*)sp = *(__int128*)cd->speed;
    sp[3] = 0.0f;
    splen0 = isbcoreGetLen(&sp);
    splen = splen0;
    next_id = current_id + 1;
    if (next_id >= num_vertex) {
        current_id = num_vertex - 2;
        next_id = current_id + 1;
    }
    from = vertex_list[current_id];
    to = vertex_list[next_id];
    sceVu0SubVector(&rail, to, from);
    sceVu0Normalize(&rail, &rail);
    *(__int128*)now = *(__int128*)cd->pos;
    now[3] = 0.0f;
    *(__int128*)nor = *(__int128*)rail;
    d = -sceVu0InnerProduct(&nor, &now);
    a = d + sceVu0InnerProduct(&nor, from);
    b = d + sceVu0InnerProduct(&nor, to);
    if ((a * b) < 0.0f) {
        if (a < 0.0f) {
            a = -a;
        }
        if (b < 0.0f) {
            b = -b;
        }
        sceVu0InterVector(&now, from, to, b / (a + b));
    }
    inner0 = sceVu0InnerProduct(&rail, &sp[0]);
    if ((inner0 > 0.0f)) {
        loop = 0;
    } else {
        loop = 1;
    }
    vec_goback = 1;
    do {
        if (loop != 0) {
            sceVu0ScaleVectorXYZ(&rail, &rail, -1.0f);
        }
        sceVu0ScaleVector( &rsp, &rail, splen);
        isbcoreGetNextPos(&next, &now, &rsp);
        sceVu0SubVector(&v0, to, from);
        sceVu0SubVector(&v1, &next, from);
        inner0 = sceVu0InnerProduct(&v0, &v1);
        sceVu0SubVector(&v0, from, to);
        sceVu0SubVector(&v1, &next, to);
        inner1 = sceVu0InnerProduct(&v0, &v1);
        if ((loop == 0) && (inner0 < 0.0f) && !(inner1 < 0.0f)) {
            *(__int128*)next = *(__int128*)from;
            next[3] = 0.0f;
            inner0 = 0.0f;
        } else if ((loop != 0) && !(inner0 < 0.0f) && (inner1 < 0.0f)) {
            *(__int128*)next = *(__int128*)to;
            next[3] = 0.0f;
            inner1 = 0.0f;
        }
        if (!(inner0 < 0.0f) && !(inner1 < 0.0f)) {
            vec_goback = 0;
        } else {
            sceVu0SubVector(&v0, &next, &now[0]);
            len0 = isbcoreGetLen(&v0);
            if (loop != 0) {
                sceVu0SubVector(&v0, &next, from);
                *(__int128*)now = *(__int128*)from;
            } else {
                sceVu0SubVector(&v0, &next, to);
                *(__int128*)now = *(__int128*)to;
            }
            len1 = isbcoreGetLen(&v0);
            splen = (splen * len1) / len0;
            now[3] = 0.0f;
        }
        if (vec_goback != 0) {
            if (loop != 0) {
                current_id -= 1;
            } else {
                current_id += 1;
                if (current_id >= (num_vertex - 1)) {
                    current_id = -1;
                }
            }
            next_id = current_id + 1;
            if (current_id >= 0) {
                from = vertex_list[current_id];
                to = vertex_list[next_id];
                sceVu0SubVector(&v0, to, from);
                if (loop != 0) {
                    sceVu0ScaleVectorXYZ(&v0, &v0, -1.0f);
                }
                inner0 = sbcoreGetInnerAngle180(&rail, &v0);
                if (inner0 < 1.3962631f) {
                    sceVu0SubVector(&rail, to, from);
                    sceVu0Normalize(&rail, &rail);
                } else {
                    current_id = -1;
                    vec_goback = 0;
                }
            } else {
                vec_goback = 0;
            }
        }
    } while (vec_goback != 0);
    *(__int128*)cd->nextpos = *(__int128*)next;
    sceVu0ScaleVector(cd->speed, &rail, splen0);
    return current_id;
}

float isbcoreGetLen(float* v) {
    float sum = sceVu0InnerProduct(v, v); // 0x1C(r29)
    isbcoreSqrtf(sum);
}

signed int sbcoreSetNextPosOnVertexListHP(Sbcore* cd /* 0x130(r29) */, signed int current_id /* 0x140(r29) */, sceVu0FVECTOR* vertex_list /* 0x150(r29) */, signed int num_vertex /* 0x160(r29) */)
{
    signed int next_id; // r20
    float rail[4]; // 0x80(r29)
    float sp[4]; // 0x90(r29)
    float now[4]; // 0xA0(r29)
    float next[4]; // 0xB0(r29)
    sceVu0FVECTOR* from; // r16
    sceVu0FVECTOR* to; // r17
    signed int vec_goback; // r21
    signed int loop; // r19
    float inner0; // 0x114(r29)
    float inner1; // 0x118(r29)
    float splenxz; // 0x11C(r29)
    float splenxz0; // 0x120(r29)
    float adj[4]; // 0xC0(r29)
    signed int start_id; // r22
    float outer[4]; // 0xD0(r29)
    float v0[4]; // 0xE0(r29)
    float v1[4]; // 0xF0(r29)
    float rsp[4]; // 0x100(r29)
    float len0; // 0x124(r29)
    float len1; // 0x128(r29)
    float nowy; // 0x12C(r29)
    signed int loop2; // r18

    *(__int128*)sp = *(__int128*)cd->speed;
    sp[3] = 0.0f;
    splenxz0 = isbcoreGetLenXZ(sp);
    splenxz = splenxz0;
    next_id = current_id + 1;
    if (next_id >= num_vertex) {
        current_id = num_vertex - 2;
        next_id = current_id + 1;
    }
    start_id = current_id;
    from = vertex_list[current_id];
    to = vertex_list[next_id];
    sceVu0SubVector(rail, to, from);
    rail[1] = 0.0f;
    sceVu0Normalize(rail, rail);
    inner0 = sceVu0InnerProduct(rail, sp);
    if (inner0 > 0.0f) {
        vec_goback = 0;
    } else {
        vec_goback = 1;
    }
    *(__int128*)v0 = *(__int128*)cd->pole;
    v0[1] = 0.0f;
    sceVu0Normalize(v0, v0);
    if (vec_goback != 0) {
        sceVu0ScaleVector(v1, rail, -1.0f);
    } else {
        *(__int128*)v1 = *(__int128*)rail;
    }
    sceVu0OuterProduct(outer, v0, v1);
    *(__int128*)adj = *(__int128*)cd->pole;
    sceVu0Normalize(adj, adj);
    sceVu0ScaleVectorXYZ(adj, adj, cd->const_max_relief_gap);
    *(__int128*)now = *(__int128*)cd->pos;
    sceVu0SubVector(now, now, adj);
    now[3] = 0.0f;
    loop = 1;
    do {
        if (vec_goback != 0) {
            sceVu0ScaleVectorXYZ(rail, rail, -1.0f);
        }
        sceVu0ScaleVector(rsp, rail, splenxz);
        rsp[1] = sp[1];
        isbcoreGetNextPos(next, now, rsp);
        sceVu0SubVector(v0, to, from);
        sceVu0SubVector(v1, next, from);
        v0[1] = 0.0f;
        v1[1] = 0.0f;
        inner0 = sceVu0InnerProduct(v0, v1);
        sceVu0SubVector(v0, from, to);
        sceVu0SubVector(v1, next, to);
        v0[1] = 0.0f;
        v1[1] = 0.0f;
        inner1 = sceVu0InnerProduct(v0, v1);
        if ((vec_goback == 0) && (inner0 < 0.0f) && !(inner1 < 0.0f)) {
            next[0] = from[0][0];
            next[2] = from[0][2];
            next[3] = 0.0f;
            inner0 = 0.0f;
        } else if ((vec_goback != 0) && !(inner0 < 0.0f) && (inner1 < 0.0f)) {
            next[0] = to[0][0];
            next[2] = to[0][2];
            next[3] = 0.0f;
            inner1 = 0.0f;
        }
        if (!(inner0 < 0.0f) && !(inner1 < 0.0f)) {
            loop = 0;
            v0[0] = rail[2];
            v0[1] = 0.0f;
            v0[2] = -rail[0];
            sceVu0Normalize(v0, v0);
            sceVu0OuterProduct(v1, v0, rail);
            if ((v1[1] * outer[1]) < 0.0f) {
                sceVu0ScaleVectorXYZ(v0, v0, -1.0f);
            }
            *(__int128*)cd->pole = *(__int128*)v0;
        } else {
            nowy = now[1];
            sceVu0SubVector(v0, next, now);
            len0 = isbcoreGetLenXZ(v0);
            if (len0 == 0.0f) {
                loop = 0;
                current_id = -1;
            } else {
                if (vec_goback != 0) {
                    sceVu0SubVector(v0, next, from);
                    *(__int128*)now = *(__int128*)from;
                } else {
                    sceVu0SubVector(v0, next, to);
                    *(__int128*)now = *(__int128*)to;
                }
                now[1] = nowy;
                len1 = isbcoreGetLenXZ(v0);
                splenxz = (splenxz * len1) / len0;
                now[3] = 0.0f;
            }
        }
        if (loop != 0) {
            do {
                loop2 = 0;
            if (vec_goback != 0) {
                current_id -= 1;
            } else {
                current_id += 1;
                if (current_id >= (num_vertex - 1)) {
                    current_id = -1;
                }
            }
            next_id = current_id + 1;
            if (current_id >= 0) {
                from = vertex_list[current_id];
                to = vertex_list[next_id];
                sceVu0SubVector(rail, to, from);
                rail[1] = 0.0f;
                sceVu0Normalize(rail, rail);
                if ((rail[0] == 0.0f) && (rail[2] == 0.0f)) {
                    loop2 = 1;
                }
            } else {
                loop = 0;
            }
            } while ((loop != 0) && (loop2 != 0));
        }
    } while (loop != 0);
    *(__int128*)adj = *(__int128*)cd->pole;
    sceVu0Normalize(adj, adj);
    sceVu0ScaleVectorXYZ(adj, adj, cd->const_max_relief_gap);
    sceVu0AddVector(next, next, adj);
    *(__int128*)cd->nextpos = *(__int128*)next;
    sceVu0ScaleVector(cd->speed, rail, splenxz0);
    cd->speed[1] = sp[1];
    return current_id;
}

float isbcoreGetLenXZ(float* v) {
    float vv[4]; // 0x10(r29)
    sceVu0MulVector(&vv, v, v);
    isbcoreSqrtf(vv[0] + vv[2]);
}

signed int sbcoreMove(Sbcore* cd /* 0x380(r29) */, ESCM_Grind_Type type /* 0x390(r29) */)
{
    Ps ps; // 0x80(r29)
    Plane* plane_hit; // r19
    Plane* plane_sliding; // r21
    Plane* plane_base; // r16
    Plane* plane_body; // r20
    signed int hit; // r18
    signed int ok; // r17
    signed int pre_sliding; // r22

    plane_hit = &ps.plane[4];
    plane_sliding = &ps.plane[0];
    plane_base = &ps.plane[3];
    plane_body = &ps.plane[2];
    ok = 0;
    pre_sliding = cd->sliding;
    cd->speed[3] = 0.0f;
    cd->pos[3] = 0.0f;
    cd->pole[3] = 0.0f;
    sbcoreInitPLANESET(&ps);
    cd->plane_pre_hit = cd->plane_hit;
    switch (type) {
    case 2:
        hit = sbcoreCheckGrind(&ps, cd, 0);
        break;
    case 1:
        hit = sbcoreCheckGrind(&ps, cd, 1);
        break;
    default:
    case 0:
        hit = sbcoreCheckSliding(&ps, cd);
        break;
    }
    if (hit != 0) {
        cd->plane_hit_buff = *plane_hit;
    } else {
        cd->plane_hit_buff.available = 0;
    }
    if ((hit != 0) && (type != 2)) {
        cd->plane_hit = *plane_hit;
        cd->sliding = 1;
    } else if (type != 0) {
        *(__int128*)cd->pos = *(__int128*)cd->nextpos;
        cd->plane_sliding = *plane_base;
        cd->plane_body = *plane_body;
        cd->sliding = 1;
        ok = 1;
    } else {
        cd->plane_hit.available = 0;
        if (ps.touch != 0) {
            sbcoreUpdateOnSliding(cd, plane_sliding, cd->nextpos);
            ok = 1;
        } else if (plane_base->available != 0) {
            sbcoreUpdateOnAir(cd, plane_base, cd->nextpos);
            ok = 1;
        } else {
            cd->plane_sliding.available = 0;
        }
        cd->plane_beneath = *plane_base;
        cd->plane_body = *plane_body;
    }
    cd->move = ok;
    cd->plane_hit.cross[3] = 0.0f;
    cd->plane_hit.normal[3] = 0.0f;
    cd->plane_sliding.cross[3] = 0.0f;
    cd->plane_sliding.normal[3] = 0.0f;
    return ok;
}

static signed int sbcoreCheckSliding(Ps* ps /* 0x100(r29) */, Sbcore* cd /* 0x110(r29) */)
{
    signed int adj = 0; // r20
    signed int touch = 0; // r16
    signed int ret_move = 0; // r17
    Plane plane_move; // 0xA0(r29)
    float wnor[4] = { 0.0f, -1.0f, 0.0f, 0.0f }; // 0xD0(r29) // @180
    s32* wnor_ptr = &wnor;
    float ang; // 0xF0(r29)
    float vtmp[4]; // 0xE0(r29)
    float ftmp; // 0xF4(r29)
    signed int double_touch; // r21
    signed int flying_board; // r23
    signed int use_sub; // r18
    signed int under_height; // r19
    float landing_height; // 0xF8(r29)
    float hi; // 0xFC(r29)
    signed int slidable; // r30

    sbcoreGetCheckTouchArea(ps->from[0], ps->to[0], cd, cd->nextpos);
    ps->move[0] = 0;
    ps->height[0] = 0.0f;
    sceVu0AddVector(ps->from[1], cd->pos, cd->pos_head);
    sceVu0AddVector(ps->to[1], cd->nextpos, cd->pos_head);
    ps->move[1] = 0;
    ps->height[1] = 0.0f;
    *(__int128*)ps->from[2] = *(__int128*)cd->pos;
    *(__int128*)ps->to[2] = *(__int128*)ps->from[0];
    ps->move[2] = 0;
    ps->height[2] = 0.0f;
    if (cd->sliding) {
        sbcoreGetCheckHeightArea(ps->from[3], ps->to[3], cd->nextpos, 1);
    } else {
        sbcoreGetCheckHeightArea_onair(ps->from[3], ps->to[3], ps->from[4], ps->to[4], cd->nextpos, cd->pole, cd->rot_pole);
    }
    ps->move[3] = 0;
    ps->move[4] = 0;
    ps->height[3] = 0.0f;
    ps->height[4] = 0.0f;
    if (cd->sliding) {
        ps->num = 3;
        ps->ofs = 0;
        ps->id_touch = 0;
        ps->id_head = 1;
        ps->id_body = 2;
        sbcoreGetHit2(ps);
    } else {
        if (cd->move_head) {
            ps->num = 4;
            ps->ofs = 1;
            ps->id_head = 1;
            ps->id_body = 2;
        } else {
            ps->num = 3;
            ps->ofs = 2;
            ps->id_head = -1;
            ps->id_body = 2;
        }
        ps->id_touch = -1;
        sbcoreGetHit2(ps);
    }
    if (cd->sliding) {
        if ((ps->ret[0]) && (ps->ret[2])) {
            *(__int128*)ps->from[0] = *(__int128*)cd->nextpos;
            ps->num = 1;
            ps->ofs = 0;
            ps->id_touch = 0;
            ps->id_head = -1;
            ps->id_body = -1;
            sbcoreGetHit2(ps);
        }
        if (ps->ret[0]) {
            if (cd->ang_slidable_limit == 1.570796f) {
                if (ps->plane[0].normal[1] > 0.0f) {
                    ps->ret[0] = 0;
                    ps->plane[0].available = 0;
                }
            } else {
                ang = sbcoreGetInnerAngle180(wnor, ps->plane[0].normal);
                if (ang > cd->ang_slidable_limit) {
                    ps->ret[0] = 0;
                    ps->plane[0].available = 0;
                }
            }
        }
        ps->ret[0] = sbcoreAdjTouch(&ps->plane[0], cd, ps->ret[0]);
        touch = ps->ret[0];
        if ((ps->ret[1]) && (cd->move_head)) {
            ret_move = 1;
            plane_move = ps->plane[1];
        } else if (ps->ret[0]) {
            if ((ps->ret[1]) && (ps->ret[2] == 0)) {
                ps->ret[2] = ps->ret[1];
                ps->plane[2] = ps->plane[1];
            }
            if (sbcoreUpdateReliefGap(cd, &ps->plane[0])) {
                ps->ret[0] = 0;
                touch = 0;
            } else {
                sbcoreAdjOnSliding(cd->nextpos, cd, &ps->plane[0], 1);
                adj = 1;
            }
        }
        if (ps->ret[0] == 0) {
            sbcoreGetCheckHeightArea_onair(ps->from[3], ps->to[3], ps->from[4], ps->to[4], cd->nextpos, cd->pole, cd->rot_pole);
            ps->num = 2;
            ps->ofs = 3;
            ps->id_touch = -1;
            ps->id_head = -1;
            ps->id_body = -1;
            sbcoreGetHit2(ps);
            sbcoreUpdateReliefGap(cd, 0);
            if ((ps->ret[3] == 0) && (ps->ret[4])) {
                ps->ret[3] = ps->ret[4];
                ps->plane[3] = ps->plane[4];
                ps->plane[3].cross[0] = cd->nextpos[0];
                ps->plane[3].cross[2] = cd->nextpos[2];
            }
        }
    } else {
        flying_board = 0;
        use_sub = 0;
        if ((ps->ret[3] == 0) && (ps->ret[4])) {
            use_sub = 1;
        } else if ((ps->ret[3]) && (ps->ret[4])) {
            ftmp = ps->plane[3].cross[1] - ps->plane[4].cross[1];
            if ((ftmp > 10.0f) && (ps->plane[4].cross[1] >= cd->pos[1])) {
                use_sub = 1;
            }
        }
        if (use_sub) {
            sceVu0SubVector(vtmp, ps->plane[4].cross, cd->nextpos);
            vtmp[1] = 0.0f;
            vtmp[3] = 0.0f;
            sceVu0AddVector(cd->nextpos, cd->nextpos, vtmp);
            ps->ret[3] = ps->ret[4];
            ps->plane[3] = ps->plane[4];
            ps->plane[3].cross[0] = cd->nextpos[0];
            ps->plane[3].cross[2] = cd->nextpos[2];
            sbcoreGetCheckTouchArea(ps->from[0], ps->to[0], cd, cd->nextpos);
        }
        if ((ps->ret[3]) && (ps->ret[1]) && (cd->move_head)) {
            if (ps->plane[1].normal[1] > 0.0f) {
                ret_move = 1;
                plane_move = ps->plane[1];
            } else if (ps->ret[2] == 0) {
                ps->ret[2] = ps->ret[1];
                ps->plane[2] = ps->plane[1];
            }
        }
        if (ps->ret[3]) {
            under_height = 0;
            if (ps->ret[2]) {
                under_height = 1;
            } else if ((ps->plane[3].cross[1] < cd->nextpos[1]) && ((cd->nextpos[1] - cd->pos[1]) <= cd->height)) {
                under_height = 1;
            }
            if (under_height) {
                sbcoreGetCheckHeightArea(ps->from[4], ps->to[4], cd->nextpos, 0);
                ps->num = 1;
                ps->ofs = 4;
                ps->id_touch = -1;
                ps->id_head = -1;
                ps->id_body = -1;
                sbcoreGetHit2(ps);
                if (ps->ret[4]) {
                    ps->ret[3] = ps->ret[4];
                    ps->plane[3] = ps->plane[4];
                }
            }
        }
        if (ps->ret[3]) {
            landing_height = 0.75f * cd->const_max_relief_gap;
            hi = ps->plane[3].cross[1] - cd->nextpos[1];
            slidable = ps->plane[3].slidable;
            if (flying_board) {
                sbcoreUpdateReliefGap(cd, 0);
            } else if ((hi < landing_height) && slidable) {
                ps->num = 2;
                ps->ofs = 0;
                ps->id_touch = 0;
                ps->id_head = -1;
                ps->id_body = -1;
                sbcoreGetHit2(ps);
                if (ps->ret[0]) {
                    if (cd->ang_slidable_limit == 1.570796f) {
                        if (ps->plane[0].normal[1] > 0.0f) {
                            ps->ret[0] = 0;
                            ps->plane[0].available = 0;
                        }
                    } else {
                        ang = sbcoreGetInnerAngle180(wnor, ps->plane[0].normal);
                        if (ang > cd->ang_slidable_limit) {
                            ps->ret[0] = 0;
                            ps->plane[0].available = 0;
                        }
                    }
                }
                ps->ret[0] = sbcoreAdjTouch(&ps->plane[0], cd, ps->ret[0]);
                touch = ps->ret[0];
                if (ps->ret[0]) {
                    sbcoreUpdateReliefGap(cd, &ps->plane[0]);
                    sbcoreAdjOnSliding(cd->nextpos, cd, &ps->plane[0], 1);
                    adj = 1;
                } else {
                    sbcoreUpdateReliefGap(cd, 0);
                }
            } else {
                sbcoreUpdateReliefGap(cd, 0);
            }
        }
    }
    ps->touch = touch;
    *(__int128*)ps->from[4] = *(__int128*)cd->pos;
    *(__int128*)ps->to[4] = *(__int128*)cd->nextpos;
    ps->move[4] = 1;
    ps->height[4] = cd->height;
    sceVu0SubVector(vtmp, cd->nextpos, cd->pos);
    ftmp = isbcoreGetLen(vtmp);
    ftmp += 0.01f;
    sceVu0Normalize(vtmp, vtmp);
    sceVu0ScaleVector(vtmp, vtmp, ftmp);
    sceVu0AddVector(ps->to[4], ps->from[4], vtmp);
    ps->ret[4] = sbcoreGetHit(&ps->plane[4], ps->from[4], ps->to[4], ps->move[4], ps->height[4], 1);
    double_touch = 0;
    if ((ps->ret[4]) && (ps->plane[4].slidable) && (touch == 0) && (cd->sliding == 0)) {
        double_touch = 1;
    }
    if (double_touch) {
        ps->plane[0] = ps->plane[4];
        sbcoreUpdateReliefGap(cd, &ps->plane[0]);
        sbcoreAdjOnSliding(cd->nextpos, cd, &ps->plane[0], 0);
        *(__int128*)ps->from[5] = *(__int128*)cd->pos;
        *(__int128*)ps->to[5] = *(__int128*)cd->nextpos;
        ps->move[5] = 0;
        ps->height[5] = cd->height;
        ps->ret[5] = sbcoreGetHit(&ps->plane[5], ps->from[5], ps->to[5], ps->move[5], ps->height[5], 1);
        if (ps->ret[5] == 0) {
            ps->touch = 1;
            ps->ret[4] = ps->ret[5];
            ps->plane[4] = ps->plane[5];
            *(__int128*)ps->from[4] = *(__int128*)ps->from[5];
            *(__int128*)ps->to[4] = *(__int128*)ps->to[5];
            ps->move[4] = ps->move[5];
            ps->height[4] = ps->height[5];
        }
    }
    if ((ps->ret[4] == 0) && (ret_move)) {
        ps->ret[4] = ret_move;
        ps->plane[4] = plane_move;
    }
    (void)wnor_ptr;
    return ps->ret[4];
}

static signed int sbcoreCheckGrind(Ps* ps /* 0x20(r29) */, Sbcore* cd /* 0x30(r29) */, signed int kill_far /* 0x40(r29) */)
{
    signed int use_sub = 0; // r16

    sbcoreGetCheckHeightArea_onair(ps->from[3], ps->to[3], ps->from[2], ps->to[2], cd->nextpos, cd->pole, cd->rot_pole);
    ps->move[3] = 0;
    ps->move[2] = 0;
    ps->height[3] = 0.0f;
    ps->height[2] = 0.0f;
    sbcoreGetCheckTouchArea(ps->from[4], ps->to[4], cd, cd->nextpos);
    ps->move[4] = 0;
    ps->height[4] = 0.0f;
    ps->ofs = 2;
    ps->num = 3;
    ps->id_touch = 4;
    ps->id_head = -1;
    ps->id_body = -1;
    sbcoreGetHit2(ps);
    ps->plane[0] = ps->plane[4];
    if ((ps->ret[3] == 0) && (ps->ret[2] != 0)) {
        use_sub = 1;
    } else if ((ps->ret[3] != 0) && (ps->ret[2] != 0) && !(ps->plane[3].cross[1] <= ps->plane[2].cross[1])) {
        use_sub = 1;
    }
    if (use_sub != 0) {
        ps->ret[3] = ps->ret[2];
        ps->plane[3] = ps->plane[2];
        ps->plane[3].cross[0] = cd->nextpos[0];
        ps->plane[3].cross[2] = cd->nextpos[2];
        ps->plane[2].available = 0;
    }
    *(__int128*)ps->from[4] = *(__int128*)cd->pos;
    *(__int128*)ps->to[4] = *(__int128*)cd->nextpos;
    ps->move[4] = 1;
    ps->height[4] = cd->height;
    ps->ret[4] = sbcoreGetHit(&ps->plane[4], ps->from[4], ps->to[4], ps->move[4], ps->height[4], kill_far);
    sbcoreUpdateReliefGap(cd, 0);
    ps->touch = 1;
    return ps->ret[4];
}

static s32 sbcoreAdjTouch(// Size: 0x30, DWARF: 0x1737CD
    Plane* pl, // Size: 0x1F0, DWARF: 0x173961
Sbcore* cd, signed int hit) {
    signed int use_pole = 1; // r16
    float pos0[4]; // 0x20(r29)
    float wlm[4][4]; // 0x30(r29)
    float pre[4]; // 0x70(r29)
    float now[4]; // 0x80(r29)

    *(__int128*)pre = *(__int128*)cd->plane_sliding.normal;
    *(__int128*)now = *(__int128*)pl->normal;
    if (hit != 0) {
        if (use_pole != 0) {
            sbcoreGetRotMatrix(wlm, cd->pole, cd->rot_pole);
        } else {
            sbcoreGetRotMatrix(wlm, now, cd->rot_pole);
        }
        sceVu0InversMatrix(wlm, wlm);
        sceVu0SubVector(pos0, pl->cross, cd->nextpos);
        pos0[3] = 0.0f;
        sceVu0ApplyMatrix(pos0, wlm, pos0);
        cd->touch_posy = pos0[1];
    } else {
        cd->touch_posy = cd->const_max_relief_gap;
    }
    if (cd->freefoot && hit && (cd->touch_posy > 0.0f)) {
        hit = 0;
    }
    if (cd->sliding == 0 && !pl->slidable) {
        hit = 0;
    }
    return hit;
}

static void sbcoreGetCheckTouchArea(float* from, float* to, // Size: 0x1F0, DWARF: 0x173961
    Sbcore* cd, float* pos) {
    f32 temp_f0;
    float area0[4]; // 0x10(r29)
    float area1[4]; // 0x20(r29)
    float lwm[4][4]; // 0x30(r29)
    float bottom; // 0x7C(r29)

    bottom = cd->const_max_relief_gap + cd->const_under_foot;
    area0[0] = 0.0f;
    area0[1] = -10.0f;
    area0[2] = 0.0f;
    area0[3] = 0.0f;
    area1[0] = 0.0f;
    area1[1] = bottom;
    area1[2] = 0.0f;
    area1[3] = 0.0f;
    sbcoreGetRotMatrix(&lwm, cd->pole, cd->rot_pole);
    sceVu0ApplyMatrix(from, &lwm, &area0[0]);
    sceVu0ApplyMatrix(to, &lwm, &area1[0]);
    sceVu0AddVector(from, from, pos);
    sceVu0AddVector(to, to, pos);
}

static void sbcoreGetCheckHeightArea(float* from, float* to, float* pos, signed int ofs) {
    *(__int128*)from = *(__int128*)pos;
    if (ofs) {
        from[1] += -10.0f;
    }
    *(__int128*)to = *(__int128*)from;
    to[1] += 10000.0f;
}

static void sbcoreGetCheckHeightArea_onair(float* from1, float* to1, float* from2, float* to2, float* pos, float* pole, float rot_pole) {
    signed int i; // r16

    float ofs0[2][4] = {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.099999994f, -0.099999994f, 0.0f, 0.0f }
    }; // 0x40(r29) // @362
    s32* ptr1 = &ofs0;
    float ofs1[2][4] = {
        { 0.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.099999994f, 0.0f }
    }; // 0x60(r29) // @363
    s32* ptr2 = &ofs1;
    float point0[4]; // 0x80(r29)
    float point1[4]; // 0x90(r29)
    float m[4][4]; // 0xA0(r29)

    sbcoreGetRotMatrix(&m, pole, rot_pole);
    for (i = 0; i < 2; i++) {
        sceVu0ApplyMatrix(&point0, &m, ofs0[i]);
        sceVu0AddVector(&point0, &point0, pos);
        point0[1] = pos[1];
        sceVu0ApplyMatrix(&point1, &m, ofs1[i]);
        sceVu0AddVector(&point1, &point1, pos);
        point1[1] = pos[1];
        if (i == 0) {
            *(__int128*)from1 = *(__int128*)point0;
            from1[1] += -10.0f;
            *(__int128*)to1 = *(__int128*)from1;
            to1[1] += 10000.0f;
        } else {
            *(__int128*)from2 = *(__int128*)point0;
            from2[1] += -10.0f;
            *(__int128*)to2 = *(__int128*)point1;
            to2[1] += 9990.0f;
        }
    }
}

static s32 sbcoreUpdateReliefGap(// Size: 0x1F0, DWARF: 0x173961
    Sbcore* cd, // Size: 0x30, DWARF: 0x1737CD
    Plane* pl) {
    signed int change_plane; // r16
    signed int hop; // r17
    float pre[4]; // 0x30(r29)
    float now[4]; // 0x40(r29)
    float move[4]; // 0x50(r29)
    float pre_relief_gap; // 0x60(r29)
    float len; // 0x64(r29)
    float inner; // 0x68(r29)
    float ang; // 0x6C(r29)

    pre_relief_gap = cd->relief_gap;
    hop = 0;
    change_plane = 0;
    if (pl == 0) {
        cd->relief_gap = 0.0f;
        return 0;
    }
    *(__int128*)pre = *(__int128*)cd->plane_sliding.normal;
    *(__int128*)now = *(__int128*)pl->normal;
    if (cd->plane_sliding.available && pl->available && ((pre[0] != now[0]) || pre[1] != now[1] || pre[2] != now[2])) {
        hop = 1;
    }
    if (hop) {
        sceVu0SubVector(move, cd->nextpos, cd->pos);
        inner = sceVu0InnerProduct(move, now);
        if ((inner > 0.0f)) {
            ang = sbcoreGetInnerAngle180(now, pre);
            if (ang > cd->limit_ang_down) {
                change_plane = 1;
            }
        }
    }
    if (change_plane == 0) {
        cd->relief_gap = (cd->const_max_relief_gap - cd->touch_posy);
        if (cd->relief_gap < 0.0f) {
            cd->relief_gap = 0.0f;
        } else if (cd->relief_gap > cd->const_max_relief_gap) {
            cd->relief_gap = cd->const_max_relief_gap;
        }
        if (hop == 0 && cd->sliding) {
            if (cd->relief_gap > pre_relief_gap) {
                cd->relief_gap = pre_relief_gap;
            }
            len = cd->const_max_relief_gap / 15.0f;
            cd->relief_gap -= len;
            if (cd->relief_gap < 0.0f) {
                cd->relief_gap = 0.0f;
            }
        } else if (cd->sliding == 0) {
            cd->relief_gap = 0.0f;
        } else if (cd->relief_gap > cd->max_relief_gap) {
            cd->relief_gap = cd->max_relief_gap;
        } else if (cd->relief_gap < 0.0f) {
            cd->relief_gap = 0.0f;
        }
        if (hop) {
            cd->cnt_keep_normal = cd->const_keep_normal;
        }
    }
    return change_plane;
}

static void sbcoreAdjOnSliding(float* new_next /* 0x40(r29) */, Sbcore* cd /* 0x50(r29) */, Plane* pl /* 0x60(r29) */, signed int use_pole /* 0x70(r29) */)
{
    float next_pos[4]; // 0x10(r29)
    float vec[4]; // 0x20(r29)
    float len; // 0x3C(r29)

    if (use_pole) {
        sceVu0Normalize(vec, cd->pole);
    } else {
        sceVu0Normalize(vec, pl->normal);
    }
    len = cd->const_max_relief_gap - cd->relief_gap;
    len += 0.099999994f;
    sceVu0ScaleVectorXYZ(vec, vec, len);
    sceVu0AddVector(next_pos, pl->cross, vec);
    next_pos[3] = 0.0f;
    *(__int128*)new_next = *(__int128*)next_pos;
}

static void sbcoreUpdateOnSliding(Sbcore* cd /* 0x10(r29) */, Plane* pl /* 0x20(r29) */, float* next /* 0x30(r29) */)
{
    signed int pre_sliding = cd->sliding; // r16

    cd->sliding = 1;
    cd->height = 0.0f;
    *(__int128*)cd->pos = *(__int128*)next;
    cd->plane_sliding = *pl;
    if ((cd->cnt_keep_normal > 0) && (cd->set_sp_normal == 0) && pre_sliding
        && (cd->max_relief_gap > 0.0f) && (cd->touch_posy > 0.0f)) {
        cd->cnt_keep_normal--;
        return;
    }
    cd->cnt_keep_normal = 0;
    *(__int128*)cd->sp_normal = *(__int128*)pl->normal;
    *(__int128*)cd->pole = *(__int128*)pl->normal;
}

static void sbcoreUpdateOnAir(// Size: 0x1F0, DWARF: 0x173961
    Sbcore* cd, // Size: 0x30, DWARF: 0x1737CD
    Plane* pl, float* next) {
    cd->relief_gap = 0.0f;
    cd->sliding = 0;
    cd->height = (pl->cross[1] - next[1]);
    *(__int128*)cd->pos = *(__int128*)next;
    cd->plane_sliding = *pl;
    cd->cnt_keep_normal = 0;
    *(__int128*)cd->sp_normal = *(__int128*)pl->normal;
}

void sbcoreGetRotMatrix(sceVu0FMATRIX mat, float* pole, float rot_pole) {
    float m0[4][4]; // 0x10(r29)
    float m1[4][4]; // 0x50(r29)
    float lenxz; // 0x9C(r29)
    float rotx; // 0xA0(r29)
    float roty; // 0xA4(r29)

    lenxz = isbcoreGetLenXZ(pole);
    rotx = atan2f(lenxz, -pole[1]);
    roty = atan2f(-pole[0], -pole[2]);
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixX(&m0, mat, rotx);
    sceVu0RotMatrixY(&m0, &m0, roty);
    rot_pole -= roty;

    rot_pole = rot_pole < -3.141592f 
        ? 6.283184f + rot_pole
        : rot_pole > 3.141592f
            ? rot_pole - 6.283184f
            : rot_pole;
    sceVu0RotMatrixY(&m1, mat, rot_pole);
    sceVu0MulMatrix(mat, &m0, &m1);
}

void sbcoreGetShadowVector(float* out, float* nor, float* vec) {
    f32 temp_f0;

    float v0[4]; // 0x10(r29)
    float v1[4]; // 0x20(r29)
    float n[4]; // 0x30(r29)
    float inner; // 0x4C(r29)

    *(__int128*)v0 = *(__int128*)vec;
    v0[3] = 0.0f;
    sceVu0Normalize(&n, nor);
    inner = sceVu0InnerProduct(&n, &v0);
    sceVu0ScaleVector(&v1, &n, -inner);
    sceVu0AddVector(out, &v0, &v1);
}

void sbcoreGetShadowRotVector(float* out, float* nor, float* vec) {
    float sv[4]; // 0x10(r29)
    float vlen0; // 0x24(r29)
    float vlen1; // 0x28(r29)
    float rate; // 0x2C(r29)
    
    sbcoreGetShadowVector(&sv, nor, vec);
    vlen0 = isbcoreGetLen(vec);
    vlen1 = isbcoreGetLen(&sv);
    rate = vlen0 / vlen1;
    sceVu0ScaleVectorXYZ(out, &sv, rate);
    out[3] = sv[3];
}

void sbcoreGetShadowVectorXZ(float* out, float* nor, float* vec) {
    float n[4]; // 0x10(r29)
    float vv[4]; // 0x20(r29)
    float m[4][4]; // 0x30(r29)
    float ang; // 0x70(r29)
    float adj_y; // 0x74(r29)
    float len; // 0x78(r29)
    float lenxz; // 0x7C(r29)

    sceVu0Normalize(&n, nor);
    ang = atan2f(vec[0], vec[2]);
    sceVu0UnitMatrix(&m);
    sceVu0RotMatrixY(&m, &m, -ang);
    sceVu0ApplyMatrix(&n, &m, &n);
    if (n[1] <= 0.0f) {
        ang = atan2f(n[2], -n[1]);
    } else {
        ang = atan2f(n[2], -n[1]);
    }
    sceVu0MulVector(&vv, vec, vec);
    len = isbcoreSqrtf(vv[0] + vv[1] + vv[2]);
    lenxz = isbcoreSqrtf(vv[0] + vv[2]);
    // temp_f0 = lenxz * tanf(ang);
    adj_y = lenxz * tanf(ang);
    vv[0] = vec[0];
    vv[1] = adj_y;
    vv[2] = vec[2];
    vv[3] = 0.0f;
    sceVu0Normalize(&vv, &vv);
    sceVu0ScaleVector(&vv, &vv, len);
    *(__int128*)out = *(__int128*)vv;
}

void sbcoreGetShadowVector2(float* out, float* snor, float* wnor, float* vec) {
    float sn[4]; // 0x10(r29)
    float wn[4]; // 0x20(r29)
    float n[4]; // 0x30(r29)
    float sv[4]; // 0x40(r29)
    float inner; // 0x5C(r29)

    sceVu0Normalize(&sn, snor);
    sceVu0Normalize(&wn, wnor);
    sceVu0OuterProduct(&n, &sn, &wn);
    sceVu0OuterProduct(&n, &n, &sn);
    inner = sceVu0InnerProduct(&wn, &n);
    if (inner < 0.0f) {
        sceVu0ScaleVectorXYZ(&n, &n, -1.0f);
    }
    sbcoreGetShadowRotVector(&sv, &sn, vec);
    inner = sceVu0InnerProduct(&n, &sv);
    if (inner < 0.0f) {
        sbcoreGetMirrorVector(&sv, &n, &sv);
    }
    *(__int128*)out = *(__int128*)sv;
}

void sbcoreGetShadowVector3(float* out, float* snor, float* wnor1, float* wnor2, float* vec) {
    float sn[4]; // 0x10(r29)
    float wn1[4]; // 0x20(r29)
    float wn2[4]; // 0x30(r29)
    float n1[4]; // 0x40(r29)
    float n2[4]; // 0x50(r29)
    float sv[4]; // 0x60(r29)
    float v0[4]; // 0x70(r29)
    float v1[4]; // 0x80(r29)
    float inner; // 0x98(r29)
    float len; // 0x9C(r29)

    len = isbcoreGetLen(vec);
    if ((wnor1[0] == wnor2[0]) && (wnor1[1] == wnor2[1]) && (wnor1[2] == wnor2[2])) {
        sbcoreGetShadowVector2(&sv, snor, wnor1, vec);
    } else {
        sceVu0Normalize(&sn, snor);
        sceVu0Normalize(&wn1, wnor1);
        sceVu0OuterProduct(&n1, &sn, &wn1);
        sceVu0OuterProduct(&n1, &n1, &sn);
        inner = sceVu0InnerProduct(&wn1, &n1);
        if (inner < 0.0f) {
            sceVu0ScaleVectorXYZ(&n1, &n1, -1.0f);
        }
        sceVu0Normalize(&wn2, wnor2);
        sceVu0OuterProduct(&n2, &sn, &wn2);
        sceVu0OuterProduct(&n2, &n2, &sn);
        inner = sceVu0InnerProduct(&wn2, &n2);
        if (inner < 0.0f) {
            sceVu0ScaleVectorXYZ(&n2, &n2, -1.0f);
        }
        sceVu0AddVector(&v0, &n1, &n2);
        sceVu0Normalize(&v0, &v0);
        sbcoreGetShadowVector(&v1, &n2, &v0);
        sceVu0Normalize(&v1, &v1);
        sceVu0AddVector(&sv, &v0, &v1);
        sceVu0Normalize(&sv, &sv);
        sceVu0ScaleVectorXYZ(&sv, &sv, len);
    }
    *(__int128*)out = *(__int128*)sv;
}

void sbcoreGetMirrorVector(float* out, float* nor, float* vec) {
    float v0[4]; // 0x10(r29)
    float v1[4]; // 0x20(r29)
    float v2[4]; // 0x30(r29)
    float v[4]; // 0x40(r29)
    float m[4][4]; // 0x50(r29)
    float m2[4][4]; // 0x90(r29)
    float len; // 0xD4(r29)
    float roty; // 0xD8(r29)
    float rotx; // 0xDC(r29)

    len = isbcoreGetLen(vec);
    sceVu0Normalize(&v0, vec);
    sceVu0Normalize(&v1, nor);
    roty = atan2f(v1[0], v1[2]);
    sceVu0UnitMatrix(&m);
    sceVu0RotMatrixY(&m2, &m, 3.141592f);
    sceVu0RotMatrixY(&m, &m, -roty);
    sceVu0ApplyMatrix(&v, &m, &v1);
    rotx = atan2f(v[2], v[1]);
    sceVu0RotMatrixX(&m, &m, -rotx);
    sceVu0ApplyMatrix(&v, &m, &v0);
    sceVu0ApplyMatrix(&v, &m2, &v);
    sceVu0InversMatrix(&m, &m);
    sceVu0ApplyMatrix(&v2, &m, &v);
    sceVu0ScaleVectorXYZ(&v2, &v2, -len);
    *(__int128*)out = *(__int128*)v2;
}

void sbcoreGetMirrorVector_angle(float* out, float* nor, float* vec, float ang) {
    float v0[4]; // 0x10(r29)
    float v1[4]; // 0x20(r29)
    float v2[4]; // 0x30(r29)
    float um[4][4]; // 0x40(r29)
    float m[4][4]; // 0x80(r29)
    float m2[4][4]; // 0xC0(r29)
    float m3[4][4]; // 0x100(r29)
    float inv[4][4]; // 0x140(r29)
    float pole[4]; // 0x180(r29)
    float len; // 0x198(r29)
    float roty; // 0x19C(r29)

    len = isbcoreGetLen(vec);
    if (ang < 0.0f) {
        ang = 0.0f;
    }
    if (ang > 1.570796f) {
        ang = 1.570796f;
    }
    sceVu0Normalize(&v0, vec);
    sceVu0Normalize(&v1, nor);
    roty = sbcoreGetInnerAngle180(&v1, &v0);
    if (roty > 1.570796f) {
        sceVu0ScaleVectorXYZ(&v1, &v1, -1.0f);
        roty = 3.141592f - roty;
    }
    roty = 3.141592f - (roty + ang);
    sceVu0OuterProduct(&pole, &v0, &v1);
    sbcoreGetRotMatrix(&m2, &pole, 0);
    sceVu0InversMatrix(&inv, &m2);
    sceVu0UnitMatrix(&um);
    sceVu0RotMatrixY(&m3, &um, roty);
    sceVu0MulMatrix(&m, &m2, &m3);
    sceVu0MulMatrix(&m, &m, &inv);
    sceVu0ApplyMatrix(&v2, &m, &v0);
    sceVu0ScaleVectorXYZ(&v2, &v2, len);
    *(__int128*)out = *(__int128*)v2;
}

f32 sbcoreGetInnerAngle90(float* vec0 /* 0x20(r29) */, float* vec1 /* 0x30(r29) */) {
    float ang; // 0x1C(r29)

    ang = sbcoreGetInnerAngle180(vec0, vec1);
    if (ang > 1.570796f) {
        ang = 3.141592f - ang;
    }
    return ang;
}

f32 sbcoreGetInnerAngle180(float* vec0, float* vec1) {
    f32 temp_f0;

    float v0[4]; // 0x10(r29)
    float v1[4]; // 0x20(r29)
    float inner; // 0x38(r29)
    float ang; // 0x3C(r29)

    sceVu0Normalize(&v0, vec0);
    sceVu0Normalize(&v1, vec1);
    inner = sceVu0InnerProduct(&v0, &v1);
    ang = acosf(inner);
    return ang;
}
