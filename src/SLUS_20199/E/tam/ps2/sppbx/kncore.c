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

// kncore.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x1C, DWARF: 0x114D31
typedef struct CharacterParameters
{
    signed int ollie; // Offset: 0x0, DWARF: 0x114D4D
    signed int spin; // Offset: 0x4, DWARF: 0x114D6F
    signed int speed; // Offset: 0x8, DWARF: 0x114D90
    signed int landing; // Offset: 0xC, DWARF: 0x114DB2
    signed int balance; // Offset: 0x10, DWARF: 0x114DD6
    signed int stability; // Offset: 0x14, DWARF: 0x114DFA
    signed int stance; // Offset: 0x18, DWARF: 0x114E20
} CharacterParameters;

// Size: 0x10, DWARF: 0x11558A
typedef struct BoardParameters
{
    signed int speed; // Offset: 0x0, DWARF: 0x1155A6
    signed int stability; // Offset: 0x4, DWARF: 0x1155C8
    signed int balance; // Offset: 0x8, DWARF: 0x1155EE
    signed int turning; // Offset: 0xC, DWARF: 0x115612
} BoardParameters;

// Size: 0x50, DWARF: 0x113C6A
typedef struct Camera
{
    float rot[4]; // Offset: 0x0, DWARF: 0x113C86
    float trans[4]; // Offset: 0x10, DWARF: 0x113CA8
    float obj[4]; // Offset: 0x20, DWARF: 0x113CCC
    float aim[4]; // Offset: 0x30, DWARF: 0x113CEE
    float up[4]; // Offset: 0x40, DWARF: 0x113D10
} Camera;

// Size: 0x30, DWARF: 0x11474A
typedef struct ScreenInfo
{
    float aspect_x; // Offset: 0x0, DWARF: 0x114766
    float aspect_y; // Offset: 0x4, DWARF: 0x11478B
    float center_x; // Offset: 0x8, DWARF: 0x1147B0
    float center_y; // Offset: 0xC, DWARF: 0x1147D5
    float clip_vol_x; // Offset: 0x10, DWARF: 0x1147FA
    float clip_vol_y; // Offset: 0x14, DWARF: 0x114821
    float min_z; // Offset: 0x18, DWARF: 0x114848
    float max_z; // Offset: 0x1C, DWARF: 0x11486A
    float near_z; // Offset: 0x20, DWARF: 0x11488C
    float far_z; // Offset: 0x24, DWARF: 0x1148AF
    float screen_z; // Offset: 0x28, DWARF: 0x1148D1
    float res; // Offset: 0x2C, DWARF: 0x1148F6
} ScreenInfo;

// Size: 0x20, DWARF: 0x114C6E
typedef struct Fog
{
    float min; // Offset: 0x0, DWARF: 0x114C8A
    float max; // Offset: 0x4, DWARF: 0x114CAA
    float far; // Offset: 0x8, DWARF: 0x114CCA
    float near; // Offset: 0xC, DWARF: 0x114CEA
    signed int col[4]; // Offset: 0x10, DWARF: 0x114D0B
} Fog;

// Size: 0x140, DWARF: 0x114EDA
typedef struct Matrix
{
    float local_screen[4][4]; // Offset: 0x0, DWARF: 0x114EF6
    float local_light[4][4]; // Offset: 0x40, DWARF: 0x114F21
    float light_color[4][4]; // Offset: 0x80, DWARF: 0x114F4B
    float local_clip[4][4]; // Offset: 0xC0, DWARF: 0x114F75
    float clip_screen[4][4]; // Offset: 0x100, DWARF: 0x114F9E
} Matrix;

// Size: 0x340, DWARF: 0x11538C
typedef struct VspSystemMatrix
{
    // Size: 0x30, DWARF: 0x11474A
    ScreenInfo scr_info; // Offset: 0x0, DWARF: 0x1153A8
    // Size: 0x20, DWARF: 0x114C6E
    Fog fog; // Offset: 0x30, DWARF: 0x1153CF
    // Size: 0x140, DWARF: 0x114EDA
    Matrix matrix; // Offset: 0x50, DWARF: 0x1153F1
    float world_screen[4][4]; // Offset: 0x190, DWARF: 0x115416
    float world_view[4][4]; // Offset: 0x1D0, DWARF: 0x115441
    float view_screen[4][4]; // Offset: 0x210, DWARF: 0x11546A
    float light_color[4][4]; // Offset: 0x250, DWARF: 0x115494
    float normal_light[4][4]; // Offset: 0x290, DWARF: 0x1154BE
    float view_clip[4][4]; // Offset: 0x2D0, DWARF: 0x1154E9
    float cam_rot[4]; // Offset: 0x310, DWARF: 0x115511
    float cam_trans[4]; // Offset: 0x320, DWARF: 0x115537
    float view_angle; // Offset: 0x330, DWARF: 0x11555F
    char padding[0xC]; // Not normally in struct but added to pad struct to size.
} VspSystemMatrix;

// Size: 0x18, DWARF: 0x116FB3
typedef struct Clock
{
    signed int year; // Offset: 0x0, DWARF: 0x116FCF
    signed int month; // Offset: 0x4, DWARF: 0x116FF0
    signed int day; // Offset: 0x8, DWARF: 0x117012
    signed int hour; // Offset: 0xC, DWARF: 0x117032
    signed int minute; // Offset: 0x10, DWARF: 0x117053
    signed int second; // Offset: 0x14, DWARF: 0x117076
} Clock;

// Size: 0x38, DWARF: 0x117930
typedef struct File
{
    // Size: 0x18, DWARF: 0x116FB3
    Clock clock; // Offset: 0x0, DWARF: 0x11794C
    char name[32]; // Offset: 0x18, DWARF: 0x117970
} File;

// Size: 0x8, DWARF: 0x11308A
typedef struct PadData
{
    unsigned short cnt; // Offset: 0x0, DWARF: 0x1130A5
    signed char lh; // Offset: 0x2, DWARF: 0x1130C5
    signed char lv; // Offset: 0x3, DWARF: 0x1130E4
    signed int analog; // Offset: 0x4, DWARF: 0x113103
} PadData;

// Size: 0x24, DWARF: 0x112AEC
typedef struct KeyCommands
{
    signed int vibration; // Offset: 0x0, DWARF: 0x112B07
    signed int spin_l; // Offset: 0x4, DWARF: 0x112B2D
    signed int spin_r; // Offset: 0x8, DWARF: 0x112B50
    signed int stance; // Offset: 0xC, DWARF: 0x112B73
    signed int revert; // Offset: 0x10, DWARF: 0x112B96
    signed int grind; // Offset: 0x14, DWARF: 0x112BB9
    signed int grab; // Offset: 0x18, DWARF: 0x112BDB
    signed int jump; // Offset: 0x1C, DWARF: 0x112BFC
    signed int flip; // Offset: 0x20, DWARF: 0x112C1D
} KeyCommands;

// Size: 0x74, DWARF: 0x11521B
typedef struct CharacterState
{
    signed int secret; // Offset: 0x0, DWARF: 0x115237
    unsigned int board; // Offset: 0x4, DWARF: 0x11525A
    unsigned int course; // Offset: 0x8, DWARF: 0x11527C
    signed int rem_point; // Offset: 0xC, DWARF: 0x11529F
    signed int old_brd_no; // Offset: 0x10, DWARF: 0x1152C5
    signed int old_wear_no; // Offset: 0x14, DWARF: 0x1152EC
    unsigned int level_goal[8]; // Offset: 0x18, DWARF: 0x115314
    signed int soft[8]; // Offset: 0x38, DWARF: 0x11533D
    // Size: 0x1C, DWARF: 0x114D31
    CharacterParameters parameter; // Offset: 0x58, DWARF: 0x115360
} CharacterState;

// Size: 0xEC, DWARF: 0x115B07
typedef struct CreatedCharacter
{
    // Size: 0x74, DWARF: 0x11521B
    CharacterState character; // Offset: 0x0, DWARF: 0x115B23
    // Size: 0x1C, DWARF: 0x114D31
    CharacterParameters init_param; // Offset: 0x74, DWARF: 0x115B4B
    // Size: 0x18, DWARF: 0x116FB3
    Clock clock; // Offset: 0x90, DWARF: 0x115B74
    char name[16]; // Offset: 0xA8, DWARF: 0x115B98
    signed int age; // Offset: 0xB8, DWARF: 0x115BBB
    signed int sex; // Offset: 0xBC, DWARF: 0x115BDB
    signed int face; // Offset: 0xC0, DWARF: 0x115BFB
    signed int hair; // Offset: 0xC4, DWARF: 0x115C1C
    signed int hair_color; // Offset: 0xC8, DWARF: 0x115C3D
    signed int body; // Offset: 0xCC, DWARF: 0x115C64
    signed int body_color; // Offset: 0xD0, DWARF: 0x115C85
    signed int pants; // Offset: 0xD4, DWARF: 0x115CAC
    signed int pants_color; // Offset: 0xD8, DWARF: 0x115CCE
    signed int glove; // Offset: 0xDC, DWARF: 0x115CF6
    signed int boots; // Offset: 0xE0, DWARF: 0x115D18
    signed int board_type; // Offset: 0xE4, DWARF: 0x115D3A
    signed int trick_type; // Offset: 0xE8, DWARF: 0x115D61
} CreatedCharacter;

// Size: 0x30, DWARF: 0x113670
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x11368C
    signed int always_sp; // Offset: 0x4, DWARF: 0x1136AD
    signed int perfect_b; // Offset: 0x8, DWARF: 0x1136D3
    signed int super_spin; // Offset: 0xC, DWARF: 0x1136F9
    signed int half_g; // Offset: 0x10, DWARF: 0x113720
    signed int fast_motion; // Offset: 0x14, DWARF: 0x113743
    signed int super_speed; // Offset: 0x18, DWARF: 0x11376B
    signed int big_head; // Offset: 0x1C, DWARF: 0x113793
    signed int metallic; // Offset: 0x20, DWARF: 0x1137B8
    signed int mirror; // Offset: 0x24, DWARF: 0x1137DD
    signed int replay_view; // Offset: 0x28, DWARF: 0x113800
    signed int partition; // Offset: 0x2C, DWARF: 0x113828
} Cheats;

// Size: 0x2DCEC, DWARF: 0x113964
typedef struct VspenvReplay
{
    // Size: 0x38, DWARF: 0x117930
    File file; // Offset: 0x0, DWARF: 0x113980
    signed int pid; // Offset: 0x38, DWARF: 0x1139A3
    signed int num_frame; // Offset: 0x3C, DWARF: 0x1139C3
    unsigned int game_time; // Offset: 0x40, DWARF: 0x1139E9
    signed int endrun_frame; // Offset: 0x44, DWARF: 0x113A0F
    // Size: 0x8, DWARF: 0x11308A
    PadData pad_data[23400]; // Offset: 0x48, DWARF: 0x113A38
    // Size: 0x24, DWARF: 0x112AEC
    KeyCommands key; // Offset: 0x2DB88, DWARF: 0x113A5F
    // Size: 0xEC, DWARF: 0x115B07
    CreatedCharacter character; // Offset: 0x2DBAC, DWARF: 0x113A81
    // Size: 0x30, DWARF: 0x113670
    Cheats cheats; // Offset: 0x2DC98, DWARF: 0x113AA9
    signed int crs_no; // Offset: 0x2DCC8, DWARF: 0x113ACE
    signed int chr_no; // Offset: 0x2DCCC, DWARF: 0x113AF1
    signed int wear_no; // Offset: 0x2DCD0, DWARF: 0x113B14
    signed int brd_no; // Offset: 0x2DCD4, DWARF: 0x113B38
    signed int game_mode; // Offset: 0x2DCD8, DWARF: 0x113B5B
    // Size: 0x10, DWARF: 0x11558A
    BoardParameters brd_param; // Offset: 0x2DCDC, DWARF: 0x113B81
} VspenvReplay;

// Size: 0x60, DWARF: 0x1161D3
typedef struct Cross
{
    sceVu0FVECTOR normal; // Offset: 0x0, DWARF: 0x1161EF
    sceVu0FVECTOR point; // Offset: 0x10, DWARF: 0x116214
    float (*vertex)[4]; // Offset: 0x20, DWARF: 0x116238
    unsigned int attr; // Offset: 0x24, DWARF: 0x116260
    signed int nvertex; // Offset: 0x28, DWARF: 0x116281
    signed int no; // Offset: 0x2C, DWARF: 0x1162A5
    float len; // Offset: 0x30, DWARF: 0x1162C4
    signed int rail_no; // Offset: 0x34, DWARF: 0x1162E4
    signed int obj_no; // Offset: 0x38, DWARF: 0x116308
    signed int obj_attr; // Offset: 0x3C, DWARF: 0x11632B
    signed int obj_type; // Offset: 0x40, DWARF: 0x116350
    signed int res[4]; // Offset: 0x44, DWARF: 0x116375
} Cross;

// Size: 0x40, DWARF: 0x2088C1
typedef struct VknGameEvent
{
    float pos[4]; // Offset: 0x0
    float obj[4]; // Offset: 0x10
    float rot[4]; // Offset: 0x20
    float s_cnt; // Offset: 0x30
    float power; // Offset: 0x34
    float rate; // Offset: 0x38
    signed short flg; // Offset: 0x3C
    signed short pad; // Offset: 0x3E
} VknGameEvent;

//// Function Declarations ///////////////////////////////////////////////////////////

void knCoreInitRand(signed int seed);
static float knCoreRandBase();
float knCoreRand();
signed int knEventGet();
void knEventStart();
void knEventEnd();
void knEventSetCameraPos(float* pos);
void knEventSetCameraObj(float* obj);
void knEventCameraMoveSpline1(float* p1, float* p2, float* p3, float* p4, float t);
void knEventSetShake(float power, float rate);
void knEventShake();
void knCoreGetWVMat(float (*wv_mat)[4], signed int num);
void knCoreGetWState(float* w_trans, float* w_rot, signed int num);
void knCoreSetWState(Camera* data, signed int num);
void knCoreRotMatrix(float (*mat)[4], float* rot);
void knCoreGetAngle(float* rot, float* trans, float* obj);
float cosf(float x);
signed int rand();
void* memcpy(void* dst, const void* src, unsigned int len);
void sceVu0CopyVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0ApplyMatrix(sceVu0FVECTOR v0, sceVu0FMATRIX m0, sceVu0FVECTOR v1);
void sceVu0CameraMatrix(sceVu0FMATRIX m, sceVu0FVECTOR p, sceVu0FVECTOR zd, sceVu0FVECTOR yd);
void sceVu0ScaleVectorXYZ(sceVu0FVECTOR a, sceVu0FVECTOR b, float c);
void sceVu0UnitMatrix(sceVu0FMATRIX m);
void sceVu0RotMatrixX(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotX);
void sceVu0RotMatrixY(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotY);
void sceVu0RotMatrixZ(sceVu0FMATRIX mat, sceVu0FMATRIX mat2, float rotZ);
signed int knCoreGetSearchBlock(signed int* sx, signed int* sy, float* pos1, float* pos2);
signed int knCoreGetSearchBlock2(signed int* sx, signed int* sy, float* pos);
float knCoreGetDifAngY(float* p1, float* p2, float* p3);
void knCoreBezier(float* V, float t, float* v0, float* v1, float* v2, float* v3);
void knCoreSpline1(float* V, float t, float* v0, float* v1, float* v2, float* v3);
void tmcrsGetArea(signed int* bx, signed int* by, float* pos);
void tmcrsGetCenterPos(signed int bx, signed int by, float* center);
void sceVu0SubVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void sceVu0MulVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
void sceVu0Normalize(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
float sceVu0InnerProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0OuterProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2);
signed int knCoreGetBaseHit(Cross* near_hit, float* pos1, float* pos2);
signed int knCoreGetHitHit(Cross* near_hit, float* pos1, float* pos2);
signed int knCoreGetCourseHit(Cross* near_hit, float* pos1, float* pos2);
signed int knCoreGetCourseHit2(signed int* ret, Cross* near_hit, float (*pos1)[4], float (*pos2)[4], float* src, signed int num);
void David_PutRaysInVU0();
signed int David_GetBaseCollision2(Cross* collision, signed int* ret, signed int x, signed int y, signed int num);
signed int David_GetHitCollision2(Cross** collision, signed int* ret, signed int x, signed int y, sceVu0FVECTOR* src, sceVu0FVECTOR* dst, signed int num);
signed int tmcrsGetVectorCollision(Cross* collision, signed int x, signed int y, float* src, float* dst);
float fabsf(float x);
float acosf(float x);
float atan2f(float y, float x);
float sqrtf(float x);

//// Variables ///////////////////////////////////////////////////////////////////////

extern VspenvReplay* vspenvReplay[2]; // Address: 0x2E7B08
extern VspSystemMatrix vspSystemMatrix[2]; // Address: 0x3BF6B0
extern signed int vgmsysPadPausePid; // Address: 0x2E7B2C
static VknGameEvent vknGameEvent; // Address: 0x3C80D0
static Camera vknCore[2]; // Address: 0x3C8030
static float vknPop_Pos[4]; // Address: 0x3C8020
static float vknPop_Rot[4]; // Address: 0x3C8010
static unsigned int vknRandSeed = 1; // Address: 0x2E7920

//// Function Definitions ////////////////////////////////////////////////////////////

void knCoreInitRand(signed int seed) {
    vknRandSeed = seed;
}

static float knCoreRandBase() {
    vknRandSeed = vknRandSeed * 0x5D588B65 + 1;
    return vknRandSeed;
}

float knCoreRand() {
    return 2.3283064e-10f * knCoreRandBase();
}

signed int knEventGet() {
    return vknGameEvent.flg;
}

void knEventStart() {
    vknGameEvent.flg = 1;
    vknGameEvent.power = 0.0f;
    vknGameEvent.rate = 0.0f;
    vknGameEvent.s_cnt = 0.0f;
    sceVu0CopyVector(vknPop_Rot, vknCore[0].rot);
    sceVu0CopyVector(vknPop_Pos, vknCore[0].trans);
}

void knEventEnd() {
    vknGameEvent.flg = 0;
    sceVu0CopyVector(vknCore[0].rot, vknPop_Rot);
    sceVu0CopyVector(vknCore[0].trans, vknPop_Pos);
}

void knEventSetCameraPos(float* pos) {
    sceVu0CopyVector(vknGameEvent.pos, pos);
}

void knEventSetCameraObj(float* obj) {
    sceVu0CopyVector(vknGameEvent.obj, obj);
    vknGameEvent.flg |= 2;
}

void knEventCameraMoveSpline1(float* p1, float* p2, float* p3, float* p4, float t) {
    knCoreSpline1(vknGameEvent.pos, t, p1, p2, p3, p4);
}

void knEventSetShake(float power, float rate) {
    vknGameEvent.power = power;
    vknGameEvent.rate = rate;
    vknGameEvent.s_cnt = 0.0f;
}

void knEventShake() {
    Camera* core; // r16
    float x; // 0x30(r29)
    float y; // 0x34(r29)
    float c; // 0x38(r29)
    float t; // 0x3C(r29)

    core = &vknCore[0];
    c = cosf(vknGameEvent.s_cnt);
    x = c * (vknGameEvent.power * c);
    y = vknGameEvent.power * c;
    t = 0.62831855f * (float)((rand(), 0) + 2);
    vknGameEvent.s_cnt += t;
    if (vknGameEvent.s_cnt > 3.1415927f) {
        vknGameEvent.s_cnt -= 6.2831855f;
        vknGameEvent.power *= vknGameEvent.rate;
        if (vknGameEvent.power < 0.001f) {
            vknGameEvent.power = 0.0f;
        }
    }
    core->obj[0] += x;
    core->obj[1] += y;
}

void knCoreGetWVMat(float (*wv_mat)[4], signed int num) {
    signed int unused1;
    signed int unused2;
    signed int event; // r18
    float mat[4][4]; // 0x50(r29)
    float aim[4]; // 0x90(r29)
    float up[4]; // 0xA0(r29)
    float pos[4]; // 0xB0(r29)
    float rot[4]; // 0xC0(r29)
    Camera* core; // r16
    VspSystemMatrix* sp; // r19
    Cheats* cheats; // r17

    core = &vknCore[num];
    sp = &vspSystemMatrix[num];
    cheats = &vspenvReplay[0]->cheats;
    if (vgmsysPadPausePid < 0) {
        event = knEventGet();
        if (event != 0) {
            sceVu0CopyVector(core->trans, vknGameEvent.pos);
            if (event & 2) {
                sceVu0CopyVector(core->obj, vknGameEvent.obj);
                if (vknGameEvent.power != 0.0f) {
                    knEventShake();
                }
            }
            if (event & 4) {
                sceVu0CopyVector(core->rot, vknGameEvent.rot);
            } else {
                knCoreGetAngle(core->rot, core->trans, core->obj);
                core->rot[2] = 0.0f;
            }
            sp->scr_info.screen_z = 300.0f;
        }
    }
    sceVu0CopyVector(rot, core->rot);
    sceVu0CopyVector(pos, core->trans);
    if (cheats->mirror == 1) {
        rot[1] = -rot[1];
        pos[0] = -pos[0];
    }
    knCoreRotMatrix(mat, rot);
    sceVu0ApplyMatrix(aim, mat, core->aim);
    if (core->up[3] != -1.0f) {
        sceVu0ApplyMatrix(up, mat, core->up);
    } else {
        sceVu0CopyVector(up, core->up);
        if (cheats->mirror == 1) {
            up[0] = -up[0];
        }
    }
    sceVu0CameraMatrix(wv_mat, pos, aim, up);
    if (cheats->mirror == 1) {
        sceVu0ScaleVectorXYZ(wv_mat, wv_mat, -1.0f);
    }
}

void knCoreGetWState(float* w_trans, float* w_rot, signed int num) {
    Camera* core; // r16

    core = &vknCore[num];
    sceVu0CopyVector(w_rot, core->rot);
    sceVu0CopyVector(w_trans, core->trans);
}

void knCoreSetWState(Camera* data, signed int num) {
    Camera* core; // r16

    core = &vknCore[num];
    memcpy(core, data, 0x50);
}

void knCoreRotMatrix(float (*mat)[4], float* rot) {
    sceVu0UnitMatrix(mat);
    sceVu0RotMatrixZ(mat, mat, rot[2]);
    sceVu0RotMatrixX(mat, mat, rot[0]);
    sceVu0RotMatrixY(mat, mat, rot[1]);
}

signed int knCoreGetSearchBlock(signed int* sx, signed int* sy, float* pos1, float* pos2) {
    static float max = 87.867966f; // Address: 0x2E7924
    signed int ret; // 0x7C(r29)
    signed int bx[2]; // 0x68(r29)
    signed int by[2]; // 0x70(r29)
    signed int loop_num; // r16
    float center[4]; // 0x50(r29)

    loop_num = 1;
    tmcrsGetArea(&bx[0], &by[0], pos1);
    tmcrsGetArea(&bx[1], &by[1], pos2);
    tmcrsGetCenterPos(bx[1], by[1], center);
    asm {
        la v1, ret;
        la v0, center;
        lqc2 $vf3, 0(pos2);
        lqc2 $vf4, 0(v0);
        vsub.xyz $vf5, $vf3, $vf4;
        vnop;
        vnop;
        vnop;
        vnop;
        cfc2.ni v0, $vi17;
        sw v0, 0(v1);
    }
    ret &= 0xFF;
    sx[0] = bx[1];
    sy[0] = by[1];
    switch (ret) {
    case 0xA0:
        if (center[0] - max > pos2[0]) {
            sx[1] = bx[1] - 1;
            sy[1] = by[1];
            loop_num++;
        }
        if (center[2] - max > pos2[2]) {
            if (loop_num == 1) {
                sx[1] = bx[1];
                sy[1] = by[1] - 1;
                loop_num++;
            } else {
                sx[2] = bx[1];
                sy[2] = by[1] - 1;
                sx[3] = bx[1] - 1;
                sy[3] = by[1] - 1;
                loop_num = 4;
            }
        }
        break;
    case 0x80:
        if (center[0] - max > pos2[0]) {
            sx[1] = bx[1] - 1;
            sy[1] = by[1];
            loop_num++;
        }
        if (center[2] + max < pos2[2]) {
            if (loop_num == 1) {
                sx[1] = bx[1];
                sy[1] = by[1] + 1;
                loop_num++;
            } else {
                sx[2] = bx[1];
                sy[2] = by[1] + 1;
                sx[3] = bx[1] - 1;
                sy[3] = by[1] + 1;
                loop_num = 4;
            }
        }
        break;
    case 0x20:
        if (center[0] + max < pos2[0]) {
            sx[1] = bx[1] + 1;
            sy[1] = by[1];
            loop_num++;
        }
        if (center[2] - max > pos2[2]) {
            if (loop_num == 1) {
                sx[1] = bx[1];
                sy[1] = by[1] - 1;
                loop_num++;
            } else {
                sx[2] = bx[1];
                sy[2] = by[1] - 1;
                sx[3] = bx[1] + 1;
                sy[3] = by[1] - 1;
                loop_num = 4;
            }
        }
        break;
    case 0:
        if (center[0] + max < pos2[0]) {
            sx[1] = bx[1] + 1;
            sy[1] = by[1];
            loop_num++;
        }
        if (center[2] + max < pos2[2]) {
            if (loop_num == 1) {
                sx[1] = bx[1];
                sy[1] = by[1] + 1;
                loop_num++;
            } else {
                sx[2] = bx[1];
                sy[2] = by[1] + 1;
                sx[3] = bx[1] + 1;
                sy[3] = by[1] + 1;
                loop_num = 4;
            }
        }
        break;
    }
    return loop_num;
}

signed int knCoreGetCourseHit(Cross* near_hit, float* pos1, float* pos2) {
    static unsigned int hit_on = 0xF000; // Address: 0x2E7928
    signed int i; // r16
    signed int j; // r17
    unsigned int attr; // r18
    signed int no; // r19
    signed int check; // r20
    signed int loop_num; // r21
    signed int sx[4]; // 0x70(r29)
    signed int sy[4]; // 0x80(r29)
    signed int h_check[4]; // 0x90(r29)
    signed int v_check[4]; // 0xA0(r29)
    Cross base; // 0xB0(r29)
    Cross hit[4][16]; // 0x110(r29)
    Cross* tmp[16]; // 0x1910(r29)
    Cross vect[2][16]; // 0x1950(r29)
    signed int num[2]; // 0x2550(r29)
    signed int b_check; // 0x2558(r29)
    float len; // 0x255C(r29)

    loop_num = 1;
    check = 0;
    near_hit->len = 16777000.0f;
    loop_num = knCoreGetSearchBlock(sx, sy, pos1, pos2);
    David_PutRaysInVU0(pos1, pos2, 1);
    for (i = 0; i < loop_num; i++) {
        David_GetBaseCollision2(&base, &b_check, sx[i], sy[i], 1);
        if (b_check > 0 && near_hit->len > base.len) {
            memcpy(near_hit, &base, 0x60);
            check = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        tmp[i] = hit[i];
    }
    for (i = 0; i < loop_num; i++) {
        David_GetHitCollision2(&tmp[i], &h_check[i], sx[i], sy[i], pos1, pos2, 1);
    }
    num[0] = -1;
    len = 16777000.0f;
    for (i = 0; i < loop_num; i++) {
        for (j = 0; j < h_check[i]; j++) {
            attr = hit[i][j].attr;
            no = hit[i][j].no;
            if (!(attr & 0x800)) {
                attr &= hit_on;
                if (attr || no < 8) {
                    if (hit[i][j].len < len) {
                        len = hit[i][j].len;
                        num[0] = i;
                        num[1] = j;
                        check = 2;
                    }
                }
            }
        }
    }
    if (num[0] != -1 && hit[num[0]][num[1]].len < near_hit->len) {
        memcpy(near_hit, &hit[num[0]][num[1]], 0x60);
        check = 2;
    }
    tmcrsGetArea(&sx[0], &sy[0], pos1);
    tmcrsGetArea(&sx[1], &sy[1], pos1);
    for (i = 0; i < 2; i++) {
        v_check[i] = tmcrsGetVectorCollision(vect[i], sx[i], sy[i], pos1, pos2);
    }
    num[0] = -1;
    len = 16777000.0f;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < v_check[i]; j++) {
            if (vect[i][j].attr < 0x16) {
                if (vect[i][j].len < len) {
                    len = vect[i][j].len;
                    num[0] = i;
                    num[1] = j;
                }
            }
        }
    }
    if (num[0] != -1 && vect[num[0]][num[1]].len < near_hit->len) {
        memcpy(near_hit, &vect[num[0]][num[1]], 0x60);
        check = 3;
    }
    return check;
}

signed int knCoreGetSearchBlock2(signed int* sx, signed int* sy, float* pos) {
    signed int bx; // 0x54(r29)
    signed int by; // 0x58(r29)
    signed int ret; // 0x5C(r29)
    float center[4]; // 0x40(r29)

    tmcrsGetArea(&bx, &by, pos);
    tmcrsGetCenterPos(bx, by, center);
    asm {
        la v1, ret;
        la v0, center;
        lqc2 $vf3, 0(pos);
        lqc2 $vf4, 0(v0);
        vsub.xyz $vf5, $vf3, $vf4;
        vnop;
        vnop;
        vnop;
        vnop;
        cfc2.ni v0, $vi17;
        sw v0, 0(v1);
    }
    ret &= 0xA0;
    sx[0] = bx;
    sy[0] = by;
    switch (ret) {
    case 0xA0:
        sx[1] = bx - 1;
        sy[1] = by;
        sx[2] = bx;
        sy[2] = by - 1;
        sx[3] = bx - 1;
        sy[3] = by - 1;
        break;
    case 0x80:
        sx[1] = bx - 1;
        sy[1] = by;
        sx[2] = bx;
        sy[2] = by + 1;
        sx[3] = bx - 1;
        sy[3] = by + 1;
        break;
    case 0x20:
        sx[1] = bx + 1;
        sy[1] = by;
        sx[2] = bx;
        sy[2] = by - 1;
        sx[3] = bx + 1;
        sy[3] = by - 1;
        break;
    case 0:
        sx[1] = bx + 1;
        sy[1] = by;
        sx[2] = bx;
        sy[2] = by + 1;
        sx[3] = bx + 1;
        sy[3] = by + 1;
        break;
    }
    return 4;
}

signed int knCoreGetCourseHit2(signed int* ret, Cross* near_hit, float (*pos1)[4], float (*pos2)[4], float* src, signed int num) {
    static unsigned int hit_on = 0xF000; // Address: 0x2E792C
    signed int k; // r16
    signed int j; // r17
    unsigned int attr; // r18
    signed int i; // r19
    signed int no; // r20
    signed int v; // r21
    signed int loop_num; // r22
    signed int sx[4]; // 0x80(r29)
    signed int sy[4]; // 0x90(r29)
    Cross base[3]; // 0xA0(r29)
    Cross hit[3][16]; // 0x1C0(r29)
    Cross vect[16]; // 0x13C0(r29)
    Cross* tmp[16]; // 0x19C0(r29)
    signed int b[4]; // 0x1A00(r29)
    signed int h[4]; // 0x1A10(r29)
    signed int x1; // 0x1A20(r29)
    signed int x2; // 0x1A24(r29)
    signed int y1; // 0x1A28(r29)
    signed int y2; // 0x1A2C(r29)

    loop_num = knCoreGetSearchBlock2(sx, sy, src);
    for (i = 0; i < num; i++) {
        near_hit[i].len = 16777000.0f;
    }
    David_PutRaysInVU0(pos1, pos2, num);
    for (i = 0; i < loop_num; i++) {
        David_GetBaseCollision2(base, b, sx[i], sy[i], num);
        for (j = 0; j < num; j++) {
            if (b[j] > 0 && near_hit[j].len > base[j].len) {
                memcpy(&near_hit[j], &base[j], 0x60);
                ret[j] = 1;
            }
        }
        for (j = 0; j < num; j++) {
            tmp[j] = hit[j];
        }
        David_GetHitCollision2(tmp, h, sx[i], sy[i], pos1, pos2, num);
        for (j = 0; j < num; j++) {
            for (k = 0; k < h[j]; k++) {
                attr = hit[j][k].attr;
                no = hit[j][k].no;
                if (!(attr & 0x800)) {
                    attr &= hit_on;
                    if (attr || no < 8) {
                        if (hit[j][k].len < near_hit[j].len) {
                            memcpy(&near_hit[j], &hit[j][k], 0x60);
                            ret[j] = 2;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < num; i++) {
        tmcrsGetArea(&x1, &y1, pos1[i]);
        tmcrsGetArea(&x2, &y2, pos2[i]);
        loop_num = 1;
        sx[0] = x1;
        sy[0] = y1;
        if (x1 != x2 && y1 != y2) {
            sx[1] = x2;
            sy[1] = y1;
            sx[2] = x1;
            sy[2] = y2;
            sx[3] = x2;
            sy[3] = y2;
            loop_num = 4;
        } else if (x1 != x2 || y1 != y2) {
            sx[1] = x2;
            sy[1] = y2;
            loop_num = 2;
        }
        for (j = 0; j < loop_num; j++) {
            v = tmcrsGetVectorCollision(vect, sx[j], sy[j], pos1[i], pos2[i]);
            for (k = 0; k < v; k++) {
                if (vect[k].attr < 0x16) {
                    if (vect[k].len < near_hit[i].len) {
                        memcpy(&near_hit[i], &vect[k], 0x60);
                        ret[i] = 3;
                    }
                }
            }
        }
    }
    return 1;
}

signed int knCoreGetBaseHit(Cross* near_hit, float* pos1, float* pos2) {
    signed int i; // r16
    signed int check; // r17
    signed int loop_num; // r18
    signed int sx[4]; // 0x40(r29)
    signed int sy[4]; // 0x50(r29)
    Cross base; // 0x60(r29)
    signed int b_check; // 0xCC(r29)

    check = 0;
    loop_num = 1;
    near_hit->len = 16777000.0f;
    loop_num = knCoreGetSearchBlock(sx, sy, pos1, pos2);
    David_PutRaysInVU0(pos1, pos2, 1);
    for (i = 0; i < loop_num; i++) {
        David_GetBaseCollision2(&base, &b_check, sx[i], sy[i], 1);
        if (b_check > 0 && near_hit->len > base.len) {
            memcpy(near_hit, &base, 0x60);
            check = 1;
        }
    }
    return check;
}

signed int knCoreGetHitHit(Cross* near_hit, float* pos1, float* pos2) {
    static unsigned int hit_on = 0xF000; // Address: 0x2E7930
    signed int i; // r16
    signed int j; // r17
    unsigned int attr; // r18
    signed int no; // r19
    signed int check; // r20
    signed int loop_num; // r21
    signed int h_check[4]; // 0x70(r29)
    signed int sx[4]; // 0x80(r29)
    signed int sy[4]; // 0x90(r29)
    Cross hit[4][16]; // 0xA0(r29)
    Cross* tmp[16]; // 0x18A0(r29)

    check = 0;
    loop_num = 1;
    near_hit->len = 16777000.0f;
    loop_num = knCoreGetSearchBlock(sx, sy, pos1, pos2);
    for (i = 0; i < 4; i++) {
        tmp[i] = hit[i];
    }
    for (i = 0; i < loop_num; i++) {
        David_GetHitCollision2(&tmp[i], &h_check[i], sx[i], sy[i], pos1, pos2, 1);
    }
    for (i = 0; i < loop_num; i++) {
        for (j = 0; j < h_check[i]; j++) {
            attr = hit[i][j].attr;
            no = hit[i][j].no;
            if (!(attr & 0x800)) {
                attr &= hit_on;
                if (attr || no < 8) {
                    if (hit[i][j].len < near_hit->len) {
                        memcpy(near_hit, &hit[i][j], 0x60);
                        check = 2;
                    }
                }
            }
        }
    }
    return check;
}

float knCoreGetDifAngY(float* p1, float* p2, float* p3) {
    float dis1[4]; // 0x10(r29)
    float dis2[4]; // 0x20(r29)
    float cross[4]; // 0x30(r29)
    float in; // 0x48(r29)
    float r; // 0x4C(r29)

    sceVu0SubVector(dis1, p1, p2);
    sceVu0SubVector(dis2, p1, p3);
    dis1[3] = dis2[3] = 1.0f;
    dis1[1] = dis2[1] = 0.0f;
    sceVu0Normalize(dis1, dis1);
    sceVu0Normalize(dis2, dis2);
    in = sceVu0InnerProduct(dis1, dis2);
    in = fabsf(in);
    if (dis1[0] == dis2[0] || dis1[2] == dis2[2]) {
        in = 1.0f;
    }
    sceVu0OuterProduct(cross, dis1, dis2);
    r = acosf(in);
    if (cross[1] < 0.0f) {
        r = -r;
    }
    return r;
}

void knCoreGetAngle(float* rot, float* trans, float* obj) {
    float v[4]; // 0x10(r29)
    float V[4]; // 0x20(r29)
    float xz; // 0x3C(r29)

    sceVu0SubVector(v, obj, trans);
    sceVu0MulVector(V, v, v);
    xz = sqrtf(V[0] + V[2]);
    rot[0] = -atan2f(v[1], xz);
    rot[1] = atan2f(v[0], v[2]);
    rot[3] = 1.0f;
}

void knCoreBezier(float* V, float t, float* v0, float* v1, float* v2, float* v3) {
    float tt[4] = { 0.0f, 0.0f, 3.0f, 1.0f };

    tt[0] = t;
    tt[1] = 1.0f - t;
    asm {
        la v1, tt;
        la v1, tt;
        lqc2 $vf3, 0($a1);
        lqc2 $vf4, 0($a2);
        lqc2 $vf5, 0($a3);
        lqc2 $vf6, 0($t0);
        lqc2 $vf7, 0(v1);
        vmuly.xyz $vf10, $vf3, $vf7y;
        vmuly.xyz $vf10, $vf10, $vf7y;
        vmuly.xyz $vf10, $vf10, $vf7y;
        vmulz.xyz $vf11, $vf4, $vf7z;
        vmulx.xyz $vf11, $vf11, $vf7x;
        vmuly.xyz $vf11, $vf11, $vf7y;
        vmuly.xyz $vf11, $vf11, $vf7y;
        vmulz.xyz $vf12, $vf5, $vf7z;
        vmulx.xyz $vf12, $vf12, $vf7x;
        vmulx.xyz $vf12, $vf12, $vf7x;
        vmuly.xyz $vf12, $vf12, $vf7y;
        vmulx.xyz $vf13, $vf6, $vf7x;
        vmulx.xyz $vf13, $vf13, $vf7x;
        vmulx.xyz $vf13, $vf13, $vf7x;
        vadd.xyzw $vf15, $vf10, $vf11;
        vadd.xyzw $vf15, $vf15, $vf12;
        vadd.xyzw $vf15, $vf15, $vf13;
        vmove.w $vf15, $vf0;
        sqc2 $vf15, 0($a0);
    }
}

void knCoreSpline1(float* V, float t, float* v0, float* v1, float* v2, float* v3) {
    static const float mat[4][4] = {
        { -9.0f, 18.0f, -11.0f, 2.0f },
        { 27.0f, -45.0f, 18.0f, 0.0f },
        { -27.0f, 36.0f, -9.0f, 0.0f },
        { 9.0f, -9.0f, 2.0f, 0.0f }
    };
    float t2 = t * t; // 0x40(r29)
    float t3 = t2 * t;
    float co[4] = { 0.0f, 0.0f, 0.0f, 0.5f };
    float vec1[4]; // 0x10(r29)
    float vec2[4]; // 0x20(r29)
    float vec3[4]; // 0x30(r29)

    co[0] = t3;
    co[1] = t2;
    co[2] = t;
    asm {
        la v1, co;
    }
    vec1[0] = v0[0];
    vec1[1] = v1[0];
    vec1[2] = v2[0];
    vec1[3] = v3[0];
    vec2[0] = v0[1];
    vec2[1] = v1[1];
    vec2[2] = v2[1];
    vec2[3] = v3[1];
    vec3[0] = v0[2];
    vec3[1] = v1[2];
    vec3[2] = v2[2];
    vec3[3] = v3[2];
    asm {
        la v1, mat;
        la a1, co;
        la a2, vec1;
        la a3, vec2;
        la t0, vec3;
        lqc2 $vf3, 0x0($v1);
        lqc2 $vf4, 0x10($v1);
        lqc2 $vf5, 0x20($v1);
        lqc2 $vf6, 0x30($v1);
        lqc2 $vf7, 0x0($a1);
        vmul.xyz $vf3, $vf3, $vf7;
        vmul.xyz $vf4, $vf4, $vf7;
        vmul.xyz $vf5, $vf5, $vf7;
        vmul.xyz $vf6, $vf6, $vf7;
        lqc2 $vf10, 0x0($a2);
        lqc2 $vf11, 0x0($a3);
        lqc2 $vf12, 0x0($t0);
        vmulax.xyzw $ACC, $vf3, $vf10x;
        vmadday.xyzw $ACC, $vf4, $vf10y;
        vmaddaz.xyzw $ACC, $vf5, $vf10z;
        vmaddw.xyzw $vf10, $vf6, $vf10w;
        vmulax.xyzw $ACC, $vf3, $vf11x;
        vmadday.xyzw $ACC, $vf4, $vf11y;
        vmaddaz.xyzw $ACC, $vf5, $vf11z;
        vmaddw.xyzw $vf11, $vf6, $vf11w;
        vmulax.xyzw $ACC, $vf3, $vf12x;
        vmadday.xyzw $ACC, $vf4, $vf12y;
        vmaddaz.xyzw $ACC, $vf5, $vf12z;
        vmaddw.xyzw $vf12, $vf6, $vf12w;
        vaddy.x $vf15, $vf10, $vf10y;
        vaddz.x $vf15, $vf15, $vf10z;
        vaddw.x $vf15, $vf15, $vf10w;
        vaddx.y $vf15, $vf11, $vf11x;
        vaddz.y $vf15, $vf15, $vf11z;
        vaddw.y $vf15, $vf15, $vf11w;
        vaddx.z $vf15, $vf12, $vf12x;
        vaddy.z $vf15, $vf15, $vf12y;
        vaddw.z $vf15, $vf15, $vf12w;
        vmulw.xyz $vf15, $vf15, $vf7w;
        vmove.w $vf15, $vf0;
        sqc2 $vf15, 0($a0);
    }
}

