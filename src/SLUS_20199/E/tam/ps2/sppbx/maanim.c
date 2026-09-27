#include "common.h"
#include "types.h"

// Pragma
// //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to
                      // float* types.
#pragma divbyzerocheck on // Allows generation of break instructions on division
                          // by variables that risk div by 0.

// SCE types
// /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned(16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned(16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

// maanim.c structs
// ////////////////////////////////////////////////////////////////////

// Size: 0x90, DWARF: 0x609D4
typedef struct tag_ulcodCOORDINATE {
  struct tag_ulcodCOORDINATE *super; // Offset: 0x0, DWARF: 0x609FC
  unsigned int flag;                 // Offset: 0x4, DWARF: 0x60A23
  unsigned int id;                   // Offset: 0x8, DWARF: 0x60A44
  signed int parent;                 // Offset: 0xC, DWARF: 0x60A63
  float mat[4][4];                   // Offset: 0x10, DWARF: 0x60A86
  float tmp[4][4];                   // Offset: 0x50, DWARF: 0x60AA8
} tag_ulcodCOORDINATE;

// Size: 0x90, DWARF: 0x60E91
typedef struct Ctrl {
  float original[4][4];    // Offset: 0x0, DWARF: 0x60EAD
  float original2[4][4];   // Offset: 0x40, DWARF: 0x60ED4
  float (*address)[4][4];  // Offset: 0x80, DWARF: 0x60EFC
  float (*address2)[4][4]; // Offset: 0x84, DWARF: 0x60F25
  signed int pad[2];       // Offset: 0x88, DWARF: 0x60F4F
} Ctrl;

// Size: 0x50, DWARF: 0x61157
typedef struct ModelMode {
  signed int head;     // Offset: 0x0, DWARF: 0x61173
  signed int kid;      // Offset: 0x4, DWARF: 0x61194
  signed int cancel;   // Offset: 0x8, DWARF: 0x611B4
  signed int pad;      // Offset: 0xC, DWARF: 0x611D7
  float head_scale[4]; // Offset: 0x10, DWARF: 0x611F7
  float hand_scale[4]; // Offset: 0x20, DWARF: 0x61220
  float kid_scale[4];  // Offset: 0x30, DWARF: 0x61249
  float body_scale[4]; // Offset: 0x40, DWARF: 0x61271
} ModelMode;

// Size: 0x10, DWARF: 0x60F75
typedef struct DebugPacket {
  unsigned int *pCurrent; // Offset: 0x0, DWARF: 0x60F91
  __int128 *pBase;        // Offset: 0x4, DWARF: 0x60FB9
  __int128 *pDmaTag;      // Offset: 0x8, DWARF: 0x60FDE
  unsigned long *pGifTag; // Offset: 0xC, DWARF: 0x61005
} DebugPacket;

// Size: 0x230, DWARF: 0x6134E
typedef struct IkParam {
  float rot[4];               // Offset: 0x0, DWARF: 0xCE04C
  float trans[4];             // Offset: 0x10, DWARF: 0xCE06E
  float off_trans[2][4];      // Offset: 0x20, DWARF: 0xCE092
  sceVu0FMATRIX *boardMat;    // Offset: 0x40, DWARF: 0xCE0BA
  sceVu0FMATRIX *board_local; // Offset: 0x44, DWARF: 0xCE0E4
  sceVu0FMATRIX *thighMatL;   // Offset: 0x48, DWARF: 0xCE111
  sceVu0FMATRIX *thighMatR;   // Offset: 0x4C, DWARF: 0xCE13C
  sceVu0FMATRIX *calfMatL;    // Offset: 0x50, DWARF: 0xCE167
  sceVu0FMATRIX *calfMatR;    // Offset: 0x54, DWARF: 0xCE191
  sceVu0FMATRIX *footMatL;    // Offset: 0x58, DWARF: 0xCE1BB
  sceVu0FMATRIX *footMatR;    // Offset: 0x5C, DWARF: 0xCE1E5
  sceVu0FMATRIX *toeMatL;     // Offset: 0x60, DWARF: 0xCE20F
  sceVu0FMATRIX *toeMatR;     // Offset: 0x64, DWARF: 0xCE238
  float thighLength[2];       // Offset: 0x68, DWARF: 0xCE261
  float shinLength[2];        // Offset: 0x70, DWARF: 0xCE28B
  signed int flg;             // Offset: 0x78, DWARF: 0xCE2B4
  signed int pad;             // Offset: 0x7C, DWARF: 0xCE2D4
  sceVu0FMATRIX footL;        // Offset: 0x80, DWARF: 0xCE2F4
  sceVu0FMATRIX footR;        // Offset: 0xC0, DWARF: 0xCE318
  sceVu0FMATRIX toeL;         // Offset: 0x100, DWARF: 0xCE33C
  sceVu0FMATRIX toeR;         // Offset: 0x140, DWARF: 0xCE35F
  float off_trans_toe[2][4];  // Offset: 0x180, DWARF: 0xCE382
  float thighLength_toe[2];   // Offset: 0x1A0, DWARF: 0xCE3AE
  float shinLength_toe[2];    // Offset: 0x1A8, DWARF: 0xCE3DC
  sceVu0FMATRIX board;        // Offset: 0x1B0, DWARF: 0xCE409
  sceVu0FMATRIX board_world;  // Offset: 0x1F0, DWARF: 0xCE42D
} IkParam;

// Size: 0x20, DWARF: 0x60CFF
typedef struct MdlData {
  float pos[4]; // Offset: 0x0, DWARF: 0x60D1B
  float rot[4]; // Offset: 0x10, DWARF: 0x60D3D
} MdlData;

// Size: 0x10, DWARF: 0x6057E
typedef struct PosAddress {
  unsigned int type; // Offset: 0x0, DWARF: 0x60599
  float frame;       // Offset: 0x4, DWARF: 0x605BA
  signed short flg;  // Offset: 0x8, DWARF: 0x605DC
  signed short non;  // Offset: 0xA, DWARF: 0x605FC
  float (*data)[4];  // Offset: 0xC, DWARF: 0x6061C
} PosAddress;

// Size: 0xF0, DWARF: 0x5FC9E
typedef struct Seq {
  unsigned int model_id;    // Offset: 0x0, DWARF: 0x5FCB9
  signed int loop;          // Offset: 0x4, DWARF: 0x5FCDE
  signed int mode;          // Offset: 0x8, DWARF: 0x5FCFF
  signed int write_flg;     // Offset: 0xC, DWARF: 0x5FD20
  signed int now_local_id;  // Offset: 0x10, DWARF: 0x5FD46
  signed int now_top_id;    // Offset: 0x14, DWARF: 0x5FD6F
  signed int next_local_id; // Offset: 0x18, DWARF: 0x5FD96
  signed int next_top_id;   // Offset: 0x1C, DWARF: 0x5FDC0
  // Size: 0x20, DWARF: 0x60CFF
  MdlData *mdl_data; // Offset: 0x20, DWARF: 0x5FDE8
  float now_frame;   // Offset: 0x24, DWARF: 0x5FE12
  float next_frame;  // Offset: 0x28, DWARF: 0x5FE38
  float ratio;       // Offset: 0x2C, DWARF: 0x5FE5F
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now_pos_address; // Offset: 0x30, DWARF: 0x5FE81
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now_rot_address; // Offset: 0x34, DWARF: 0x5FEB2
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next_pos_address; // Offset: 0x38, DWARF: 0x5FEE3
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next_rot_address; // Offset: 0x3C, DWARF: 0x5FF15
  float nowDir[4];              // Offset: 0x40, DWARF: 0x5FF47
  float nowTrans[4];            // Offset: 0x50, DWARF: 0x5FF6C
  float now_matrix[4][4];       // Offset: 0x60, DWARF: 0x5FF93
  float pos[4];                 // Offset: 0xA0, DWARF: 0x5FFBC
  float quat[4];                // Offset: 0xB0, DWARF: 0x5FFDE
  float pre_pos[4];             // Offset: 0xC0, DWARF: 0x60001
  float pre_rot[4];             // Offset: 0xD0, DWARF: 0x60027
  signed int startVertexIdx;    // Offset: 0xE0, DWARF: 0x6004D
  signed int vertexLoopFlg;     // Offset: 0xE4, DWARF: 0x60078
  signed int pad[2];            // Offset: 0xE8, DWARF: 0x600A2
} Seq;

// Size: 0x2E0, DWARF: 0x61779
typedef struct CtrlWithIKParam {
  float rot[4];         // Offset: 0x0, DWARF: 0x61795
  float trans[4];       // Offset: 0x10, DWARF: 0x617B7
  float scale[4];       // Offset: 0x20, DWARF: 0x617DB
  float matrix[4][4];   // Offset: 0x30, DWARF: 0x617FF
  float revision[4][4]; // Offset: 0x70, DWARF: 0x61824
  // Size: 0x230, DWARF: 0x6134E
  IkParam ikparam; // Offset: 0xB0, DWARF: 0x6184B
} CtrlWithIKParam;

// Size: 0x20, DWARF: 0x61030
typedef struct ObjData {
  signed int size;   // Offset: 0x0, DWARF: 0x6104C
  unsigned int mode; // Offset: 0x4, DWARF: 0x6106D
  signed int nprim;  // Offset: 0x8, DWARF: 0x6108E
  signed int blend;  // Offset: 0xC, DWARF: 0x610B0
  signed int ver;    // Offset: 0x10, DWARF: 0x610D2
  signed int nor;    // Offset: 0x14, DWARF: 0x610F2
  signed int rgba;   // Offset: 0x18, DWARF: 0x61112
  signed int stq;    // Offset: 0x1C, DWARF: 0x61133
} ObjData;

// Size: 0x10, DWARF: 0x612C2
typedef struct Obj {
  signed int nblock; // Offset: 0x0, DWARF: 0x612DE
  // Size: 0x20, DWARF: 0x61030
  ObjData *data;      // Offset: 0x4, DWARF: 0x61301
  signed int _pad[2]; // Offset: 0x8, DWARF: 0x61327
} Obj;

// Size: 0x20, DWARF: 0x60873
typedef struct ModelHeader {
  char id[3];      // Offset: 0x0, DWARF: 0x6088E
  char version;    // Offset: 0x3, DWARF: 0x608AF
  signed int nobj; // Offset: 0x4, DWARF: 0x608D3
  // Size: 0x10, DWARF: 0x612C2
  Obj *obj;                   // Offset: 0x8, DWARF: 0x608F4
  signed int ncoord;          // Offset: 0xC, DWARF: 0x60919
  tag_ulcodCOORDINATE *coord; // Offset: 0x10, DWARF: 0x6093C
  signed int _pad[3];         // Offset: 0x14, DWARF: 0x60963
} ModelHeader;

// Size: 0x1A0, DWARF: 0x5FB16
typedef struct MotionCtrl {
  signed int type;              // Offset: 0x0, DWARF: 0x5FB31
  float power;                  // Offset: 0x4, DWARF: 0x5FB52
  float dir;                    // Offset: 0x8, DWARF: 0x5FB74
  float cnt;                    // Offset: 0xC, DWARF: 0x5FB94
  float head[4];                // Offset: 0x10, DWARF: 0x5FBB4
  float preHead[4];             // Offset: 0x20, DWARF: 0x5FBD7
  float tail_matrix[5][4][4];   // Offset: 0x30, DWARF: 0x5FBFD
  float g_vector[4];            // Offset: 0x170, DWARF: 0x5FC27
  unsigned int *tailAddress[5]; // Offset: 0x180, DWARF: 0x5FC4E
  signed int pad[3];            // Offset: 0x194, DWARF: 0x5FC78
} MotionCtrl;

// Size: 0x10, DWARF: 0x604AC
typedef struct Primitive {
  unsigned int id; // Offset: 0x0, DWARF: 0x604C7
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *pos; // Offset: 0x4, DWARF: 0x604E6
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *rot; // Offset: 0x8, DWARF: 0x6050B
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *vert; // Offset: 0xC, DWARF: 0x60530
} Primitive;

// Size: 0x20, DWARF: 0x60646
typedef struct LocalHeader {
  float version;       // Offset: 0x0, DWARF: 0x60661
  float frame;         // Offset: 0x4, DWARF: 0x60685
  signed int anim_num; // Offset: 0x8, DWARF: 0x606A7
  signed int obj_num;  // Offset: 0xC, DWARF: 0x606CC
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive_address; // Offset: 0x10, DWARF: 0x606F0
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *sequence_address; // Offset: 0x14, DWARF: 0x60723
  sceVu0FVECTOR *data_address;  // Offset: 0x18, DWARF: 0x60755
  signed int pad;               // Offset: 0x1C, DWARF: 0x60783
} LocalHeader;

// Size: 0x20, DWARF: 0x600C8
typedef struct MainHeader {
  char name[4];   // Offset: 0x0, DWARF: 0x600E3
  float ver;      // Offset: 0x4, DWARF: 0x60106
  signed int num; // Offset: 0x8, DWARF: 0x60126
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive_top_address; // Offset: 0xC, DWARF: 0x60146
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *sequence_top_address; // Offset: 0x10, DWARF: 0x6017D
  sceVu0FVECTOR *data_top_address;  // Offset: 0x14, DWARF: 0x601B3
  signed int maping_flg;            // Offset: 0x18, DWARF: 0x601E5
  signed int pad;                   // Offset: 0x1C, DWARF: 0x6020C
} MainHeader;

// Size: 0x20, DWARF: 0x607A7
typedef struct PrimData {
  unsigned long tex0;   // Offset: 0x0, DWARF: 0x607C2
  signed int nver;      // Offset: 0x8, DWARF: 0x607E3
  signed int coordidx4; // Offset: 0xC, DWARF: 0x60804
  unsigned long alpha;  // Offset: 0x10, DWARF: 0x6082A
  signed int _pad[2];   // Offset: 0x18, DWARF: 0x6084C
} PrimData;

//// Variables
//////////////////////////////////////////////////////////////////////////

static // Size: 0x50, DWARF: 0x61157
    ModelMode model_mode = {0,
                            0,
                            0,
                            0,
                            {1.0f, 1.0f, 1.0f, 1.0f},
                            {1.0f, 1.0f, 1.0f, 1.0f},
                            {1.0f, 1.0f, 1.0f, 1.0f},
                            {1.0f, 1.0f, 1.0f, 1.0f}}; // Address: 0x2B2FD0

//// Function Declarations
//////////////////////////////////////////////////////////////
float acosf(float a);
float sinf(float a);
float cosf(float a);
void *memcpy(void *dst, const void *src, unsigned int n);
float sqrtf(float a);
float atan2f(float y, float x);
double atan2(double y, double x);
void sceVu0InterVectorXYZ(sceVu0FVECTOR v0, sceVu0FVECTOR v1, sceVu0FVECTOR v2,
                          float t);
void sceVu0ScaleVector(sceVu0FVECTOR v0, sceVu0FVECTOR v1, float s);
float sceVu0InnerProduct(sceVu0FVECTOR v0, sceVu0FVECTOR v1);
void sceVu0RotMatrixX(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rx);
void sceVu0RotMatrixY(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float ry);
void sceVu0RotMatrixZ(sceVu0FMATRIX m0, sceVu0FMATRIX m1, float rz);

static void maQuatSlerp(float *quat, float *from, float *to, float time);
static void bezierVector(float *bez, float *x0, float *x1, float *x2, float *x3,
                         float time);
static void euler2Quat(float *quat, float *rot);
static void matrix2Euler(float *rot, float (*matrix)[4]);
static void quat2Matrix(float (*matrix)[4], float *quat);
void maIKSet( // Size: 0x230, DWARF: 0x6134E
    IkParam *ctrl, signed int flag);
void maMdlMotionMap(__int128 *motion_data);
// Size: 0xF0, DWARF: 0x5FC9E
Seq *maMdlMotionInit(__int128 *motion_data, signed int id);
void maMdlMotionInitEnd( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq);
void maMdlMotionDirect(unsigned int *total_data, // Size: 0xF0, DWARF: 0x5FC9E
                       Seq *seq, signed int id, float frame);
void maMdlMotionRealBrendDirect(
    unsigned int *total_data, // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, signed int flg, signed int next_id, float next_frame,
    float ratio);
float maGetMdlMotionFrame(unsigned int *total_data, signed int id);
void maMdlMotionRealDirBrendDirect(
    unsigned int *total_data, // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, signed int flg, float *now_dir, float *now_pos,
    signed int next_id, float next_frame, float ratio);
void maMdlMotionRealDirBrendDirect2(
    unsigned int *total_data, // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, signed int flg, float (*matrix)[4], float *now_pos,
    signed int next_id, float next_frame, float ratio);
signed int
maVuMdlMotionCtrl(__int128 *mdl_data,
                  __int128 *motion_data, // Size: 0xF0, DWARF: 0x5FC9E
                  Seq *seq, __int128 **total_data);
static void aVuMdlMotionPosDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *pos);
static void aVuMdlMotionRotDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *rot);
static void aVuMdlMotionBrendPosDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *pos);
static void aVuMdlMotionBrendRotDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *rot);
static void aVuMdlMotionRealBrendPosDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *pos);
static void aVuMdlMotionRealBrendRotDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *rot);
static void aVuMdlMotionRealDirBrendPosDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *pos, signed int type);
static void aVuMdlMotionRealDirBrendRotDirect( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *rot, signed int type);
static void aVuMdlMotionRealDirBrendPosDirect2( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *pos, signed int type);
static void aVuMdlMotionRealDirBrendRotDirect2( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq, float *rot, signed int type);
void maVuMdlIKInit(__int128 *mdl_data, // Size: 0x2E0, DWARF: 0x61779
                   CtrlWithIKParam *ctrl);
static void aVuMdlCoord(tag_ulcodCOORDINATE *coord);
void maVuMdlIKCtrl(__int128 *mdl_data, // Size: 0x2E0, DWARF: 0x61779
                   CtrlWithIKParam *ctrl);
static void
aVuMdlIKCoord(tag_ulcodCOORDINATE *coord, // Size: 0x2E0, DWARF: 0x61779
              CtrlWithIKParam *ctrl,      // Size: 0x20, DWARF: 0x60873
              ModelHeader *header);
static void aVuMdlIKComp(float *rot,
                         ModelHeader *unused1, // Size: 0x2E0, DWARF: 0x61779
                         CtrlWithIKParam *ctrl, unsigned int id);
void maSecMotionInit(__int128 *mdl_data, // Size: 0x1A0, DWARF: 0x5FB16
                     MotionCtrl *ctrl);
void maSecMotionCtrl(__int128 *mdl_data, // Size: 0x1A0, DWARF: 0x5FB16
                     MotionCtrl *ctrl, float (*root_matrix)[4]);
unsigned char *maCreateModelLink(unsigned char **mdl_data,
                                 signed int *file_size, signed int *text_num,
                                 signed int *alpha_num, signed int num);
void maCreateModelFree(unsigned char *mdl_data);
void maSetModelMode( // Size: 0x50, DWARF: 0x61157
    ModelMode *mode);
void maGetModelScale(float *ret, signed int id);
void maSetModelScaleCancel(signed int flg);
// Size: 0x90, DWARF: 0x60E91
Ctrl *maModelChangeInit(__int128 *mdl_data);
void maSecMotionMode( // Size: 0x1A0, DWARF: 0x5FB16
    MotionCtrl *ctrl, signed int mode);
void maModelChangeSet( // Size: 0x90, DWARF: 0x60E91
    Ctrl *ctrl, signed int mode);
void maModelChangeInitEnd( // Size: 0x90, DWARF: 0x60E91
    Ctrl *ctrl);

//// Function Definitions
///////////////////////////////////////////////////////////////

static void maQuatSlerp(float *quat, float *from, float *to, float time) {
  float omega;
  float cosom;
  float sinom;
  float scale0;
  float scale1;
  float next[4];  // 0x50(r29)
  float scale[4]; // 0x60(r29)
  float tmp[4];   // 0x70(r29)

  sceVu0MulVector(tmp, from, to);
  cosom = tmp[0] + tmp[1] + tmp[2] + tmp[3];

  if (cosom < 0.0f) {
    cosom = -cosom;
    sceVu0ScaleVector(next, to, -1.0f);
  } else {
    sceVu0CopyVector(next, to);
  }

  if ((1.0f - cosom) > 0.001f) {
    omega = acosf(cosom);
    sinom = 1.0f / sinf(omega);
    scale0 = sinom * sinf((1.0f - time) * omega);
    scale1 = sinom * sinf(time * omega);
  } else {
    scale0 = 1.0f - time;
    scale1 = time;
  }

  scale[0] = scale0;
  scale[1] = scale1;
  asm(la v1, next; la a0, scale; lqc2 $vf1, 0(from); lqc2 $vf2, 0(v1);
      lqc2 $vf3, 0(a0);

      vmulx.xyzw $vf5, $vf1, $vf3x; vmuly.xyzw $vf6, $vf2, $vf3y;

      vadd.xyzw $vf7, $vf5, $vf6;

      sqc2 $vf7, 0(quat););
}

static void bezierVector(float *bez, float *x0, float *x1, float *x2, float *x3,
                         float time) {
  float tmp[4];

  tmp[0] = time;
  tmp[1] = 1.0f - time;
  tmp[2] = 3.0f;

  asm(la v1, tmp; lqc2 $vf1, 0(x0); lqc2 $vf2, 0(x1); lqc2 $vf3, 0(x2);
      lqc2 $vf4, 0(x3); lqc2 $vf5, 0(v1);

      vmuly.xyz $vf6, $vf1, $vf5y; vmuly.xyz $vf6, $vf6, $vf5y;
      vmuly.xyz $vf6, $vf6, $vf5y;

      vmulz.xyz $vf7, $vf2, $vf5z; vmulx.xyz $vf7, $vf7, $vf5x;
      vmuly.xyz $vf7, $vf7, $vf5y; vmuly.xyz $vf7, $vf7, $vf5y;

      vmulz.xyz $vf8, $vf3, $vf5z; vmulx.xyz $vf8, $vf8, $vf5x;
      vmulx.xyz $vf8, $vf8, $vf5x; vmuly.xyz $vf8, $vf8, $vf5y;

      vmulx.xyz $vf9, $vf4, $vf5x; vmulx.xyz $vf9, $vf9, $vf5x;
      vmulx.xyz $vf9, $vf9, $vf5x;

      vadd.xyz $vf10, $vf6, $vf7; vadd.xyz $vf10, $vf10, $vf8;
      vadd.xyz $vf10, $vf10, $vf9;

      vmuly.xyz $vf6, $vf1, $vf5y; vmulz.xyz $vf7, $vf2, $vf5z;
      vmulz.xyz $vf8, $vf3, $vf5z; vmulx.xyz $vf9, $vf4, $vf5x;
      vmuly.xyz $vf6, $vf6, $vf5y; vmulx.xyz $vf7, $vf7, $vf5x;
      vmulx.xyz $vf8, $vf8, $vf5x; vmulx.xyz $vf9, $vf9, $vf5x;
      vmuly.xyz $vf6, $vf6, $vf5y; vmuly.xyz $vf7, $vf7, $vf5y;
      vmulx.xyz $vf8, $vf8, $vf5x; vmulx.xyz $vf9, $vf9, $vf5x;
      vmuly.xyz $vf7, $vf7, $vf5y; vmuly.xyz $vf8, $vf8, $vf5y;

      vadd.xyz $vf10, $vf6, $vf7; vadd.xyz $vf10, $vf10, $vf8;
      vadd.xyz $vf10, $vf10, $vf9; sqc2 $vf10, 0(bez););
}

static void euler2Quat(float *quat, float *rot) {
  float rx; // 0x10(r29)
  float ry; // 0x14(r29)
  float rz; // 0x18(r29)
  float tx; // 0x1C(r29)
  float ty; // 0x20(r29)
  float tz; // 0x24(r29)
  float cx; // 0x28(r29)
  float cy; // 0x2C(r29)
  float cz; // 0x30(r29)
  float sx; // 0x34(r29)
  float sy; // 0x38(r29)
  float sz; // 0x3C(r29)
  float cc; // 0x40(r29)
  float cs; // 0x44(r29)
  float sc; // 0x48(r29)
  float ss; // 0x4C(r29)

  rx = (3.141592f * rot[0]) / 180.0f;
  ry = (3.141592f * rot[1]) / 180.0f;
  rz = (3.141592f * rot[2]) / 180.0f;

  tx = 0.5f * rx;
  ty = 0.5f * ry;
  tz = 0.5f * rz;
  cx = cosf(tx);
  cy = cosf(ty);
  cz = cosf(tz);
  sx = sinf(tx);
  sy = sinf(ty);
  sz = sinf(tz);
  cc = cx * cz;
  cs = cx * sz;
  sc = sx * cz;
  ss = sx * sz;

  quat[0] = (cy * sc) - (sy * cs);
  quat[1] = (cy * ss) + (sy * cc);
  quat[2] = (cy * cs) - (sy * sc);
  quat[3] = (cy * cc) + (sy * ss);
}

static void matrix2Euler(float *rot, float (*matrix)[4]) {
  float cx; // 0x24(r29)
  float sx; // 0x28(r29)
  float cy; // 0x2C(r29)
  float sy; // 0x30(r29)
  float yr; // 0x34(r29)
  float cz; // 0x38(r29)
  float sz; // 0x3C(r29)

  sy = -matrix[2][0];
  cy = sqrtf(1.0f - (sy * sy));
  yr = atan2(sy, cy);

  rot[1] = (180.0f * yr) / 3.141592f;

  if ((sy != 1.0f) && (sy != -1.0f)) {
    cx = matrix[2][2] / cy;
    sx = matrix[2][1] / cy;
    rot[0] = (180.0f * atan2f(sx, cx)) / 3.141592f;
    cz = matrix[0][0] / cy;
    sz = matrix[1][0] / cy;

    rot[2] = (180.0f * atan2f(sz, cz)) / 3.141592f;
  } else {
    cx = matrix[1][1];
    sx = -matrix[1][2];
    rot[0] = (180.0f * atan2f(sx, cx)) / 3.141592f;
    cz = 1.0f;
    sz = 0.0f;

    rot[2] = (180.0f * atan2f(sz, cz)) / 3.141592f;
  }
}

static void quat2Matrix(float (*matrix)[4], float *quat) {
  float x;  // 0x1C(r29)
  float y;  // 0x20(r29)
  float z;  // 0x24(r29)
  float w;  // 0x28(r29)
  float xx; // 0x2C(r29)
  float yy; // 0x30(r29)
  float zz; // 0x34(r29)
  float xy; // 0x38(r29)
  float wz; // 0x3C(r29)
  float xz; // 0x40(r29)
  float wy; // 0x44(r29)
  float yz; // 0x48(r29)
  float wx; // 0x4C(r29)

  sceVu0UnitMatrix(matrix);
  x = quat[0];
  y = quat[1];
  z = quat[2];
  w = quat[3];
  xx = 2.0f * x * x;
  yy = 2.0f * y * y;
  zz = 2.0f * z * z;
  xy = 2.0f * x * y;
  wz = 2.0f * w * z;
  xz = 2.0f * x * z;
  wy = 2.0f * w * y;
  yz = 2.0f * y * z;
  wx = 2.0f * w * x;

  matrix[0][0] = 1.0f - yy - zz;
  matrix[0][1] = xy - wz;
  matrix[0][2] = xz + wy;
  matrix[1][0] = xy + wz;
  matrix[1][1] = 1.0f - xx - zz;
  matrix[1][2] = yz - wx;
  matrix[2][0] = xz - wy;
  matrix[2][1] = yz + wx;
  matrix[2][2] = 1.0f - xx - yy;
}

void maIKSet( // Size: 0x230, DWARF: 0x6134E
    IkParam *ctrl, signed int flag) {
  ctrl->flg = flag;
}

void maMdlMotionMap(__int128 *motion_data) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *sequence;     // r16
  unsigned int tmp_address; // r17
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header; // r18
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive;         // r19
  signed int p_cnt;             // r20
  signed int motion_object_num; // r21
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header;          // r22
  signed int h_cnt;                   // r23
  signed int motion_num;              // r30
  unsigned int primitive_top_address; // 0x94(r29)
  unsigned int sequence_top_address;  // 0x98(r29)
  unsigned int data_top_address;      // 0x9C(r29)

  main_header = (MainHeader *)motion_data;

  if (main_header->ver == 2.0f) {
    motion_num = main_header->num;

    primitive_top_address = (unsigned int)main_header->primitive_top_address;
    sequence_top_address = (unsigned int)main_header->sequence_top_address;
    data_top_address = (unsigned int)main_header->data_top_address;

    local_header = (LocalHeader *)(motion_data + 2);

    if (main_header->maping_flg == 0) {
      for (h_cnt = 0; h_cnt < motion_num; h_cnt++) {
        motion_object_num = local_header->anim_num;

        tmp_address = (unsigned int)local_header->primitive_address;
        local_header->primitive_address =
            (Primitive *)(motion_data + tmp_address);

        primitive = local_header->primitive_address;
        for (p_cnt = 0; p_cnt < motion_object_num; p_cnt++) {
          if ((signed int)primitive->pos != -1) {
            tmp_address = (unsigned int)main_header->sequence_top_address;
            tmp_address += (unsigned int)primitive->pos;
            primitive->pos = (PosAddress *)(motion_data + tmp_address);
          } else {
            primitive->pos = 0;
          }

          if ((signed int)primitive->rot != -1) {
            tmp_address = (unsigned int)main_header->sequence_top_address;
            tmp_address += (unsigned int)primitive->rot;
            primitive->rot = (PosAddress *)(motion_data + tmp_address);
          } else {
            primitive->rot = 0;
          }

          if ((signed int)primitive->vert != -1) {
            tmp_address = (unsigned int)main_header->sequence_top_address;
            tmp_address += (unsigned int)primitive->vert;
            primitive->vert = (PosAddress *)(motion_data + tmp_address);
          } else {
            primitive->vert = 0;
          }

          if (primitive->pos != 0) {
            sequence = primitive->pos;
            while (1) {
              tmp_address = (unsigned int)main_header->data_top_address;
              tmp_address += (unsigned int)sequence->data;
              sequence->data = (float(*)[4])(motion_data + tmp_address);
              if (sequence->flg < 0) {
                break;
              }
              sequence++;
            }
          }

          if (primitive->rot != 0) {
            sequence = primitive->rot;
            while (1) {
              tmp_address = (unsigned int)main_header->data_top_address;
              tmp_address += (unsigned int)sequence->data;
              sequence->data = (float(*)[4])(motion_data + tmp_address);
              if (sequence->flg < 0) {
                break;
              }
              sequence++;
            }
          }

          if (primitive->vert != 0) {
            sequence = primitive->vert;
            while (1) {
              tmp_address = (unsigned int)main_header->data_top_address;
              tmp_address += (unsigned int)sequence->data;
              sequence->data = (float(*)[4])(motion_data + tmp_address);
              if (sequence->flg < 0) {
                break;
              }
              sequence++;
            }
          }

          primitive++;
        }
        local_header++;
      }
      main_header->maping_flg = 1;
    }
  }
}

Seq *maMdlMotionInit(__int128 *motion_data, signed int id) {
  signed int i; // r16
  // Size: 0xF0, DWARF: 0x5FC9E
  Seq *seq;                     // r17
  signed int motion_object_num; // r18
  // Size: 0x20, DWARF: 0x60CFF
  MdlData *tmp; // r19
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header; // r20
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header; // r21

  main_header = (MainHeader *)motion_data;
  seq = 0;

  if (main_header->ver == 2.0f) {
    local_header = (LocalHeader *)(motion_data + 2);

    if ((main_header->num <= id) || (id < 0)) {
      return seq;
    }
    motion_object_num = local_header[id].obj_num;
    seq = (Seq *)ulMalloc(motion_object_num * sizeof(Seq), 0, 0);
    tmp = (MdlData *)ulMalloc(motion_object_num * sizeof(MdlData), 0, 0);

    for (i = 0; i < motion_object_num; i++) {
      seq[i].model_id = -1;
      seq[i].now_local_id = 0;
      seq[i].now_top_id = -1;
      seq[i].next_local_id = 0;
      seq[i].next_top_id = -1;
      seq[i].mode = 0;
      seq[i].now_frame = 0.0f;
      seq[i].next_frame = 0.0f;
      seq[i].mdl_data = tmp;
    }
  }
  return seq;
}

void maMdlMotionInitEnd( // Size: 0xF0, DWARF: 0x5FC9E
    Seq *seq) {
  ulFree(seq->mdl_data);
  ulFree(seq);
}

void maMdlMotionDirect(unsigned int *total_data, Seq *seq, signed int id,
                       float frame) {
  signed int i; // r16
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive; // r17
  signed int anim_num;  // r18
  signed int local_id;  // r19
  signed int top_id;    // r20
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header; // r21
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header; // r22

  top_id = (id & 0xFFFF0000) >> 16;
  local_id = id & 0xFFFF;
  main_header = (MainHeader *)total_data[top_id];

  if (main_header->ver == 2.0f) {
    local_header = (LocalHeader *)(main_header + 1);

    anim_num = local_header[local_id].anim_num;
    primitive = local_header[local_id].primitive_address;
    if ((seq->mode != 1) || (seq->now_top_id != top_id) ||
        (seq->now_local_id != local_id)) {
      for (i = 0; i < anim_num; i++) {
        seq[i].mode = 1;
        seq[i].model_id = primitive[i].id;
        seq[i].now_local_id = local_id;
        seq[i].now_top_id = top_id;
        seq[i].now_frame = frame;

        seq[i].now_pos_address = primitive[i].pos;
        seq[i].now_rot_address = primitive[i].rot;
        seq[i].startVertexIdx = (signed int)primitive[i].vert;
        seq[i].vertexLoopFlg = 0;
      }
    } else {
      for (i = 0; i < anim_num; i++) {
        seq[i].now_frame = frame;
      }
    }
  }
}

void maMdlMotionRealBrendDirect(unsigned int *total_data, Seq *seq,
                                signed int flg, signed int next_id,
                                float next_frame, float ratio) {
  signed int i; // r16
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive; // r17
  signed int anim_num;  // r18
  signed int local_id;  // r19
  signed int top_id;    // r20
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header; // r21
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header; // r22

  top_id = (next_id & 0xFFFF0000) >> 16;
  local_id = next_id & 0xFFFF;
  main_header = (MainHeader *)total_data[top_id];

  if (main_header->ver == 2.0f) {
    local_header = (LocalHeader *)(main_header + 1);

    anim_num = local_header[local_id].anim_num;
    primitive = local_header[local_id].primitive_address;
    if ((seq->mode != 3) || (seq->now_top_id != top_id) ||
        (seq->now_local_id != local_id)) {
      for (i = 0; i < anim_num; i++) {
        seq[i].mode = 3;
        seq[i].model_id = primitive[i].id;
        seq[i].now_local_id = local_id;
        seq[i].now_top_id = top_id;

        seq[i].next_pos_address = primitive[i].pos;
        seq[i].next_rot_address = primitive[i].rot;
        seq[i].startVertexIdx = (signed int)primitive[i].vert;
        seq[i].vertexLoopFlg = 0;

        seq[i].next_frame = next_frame;
        seq[i].ratio = ratio;
        seq[i].write_flg = flg;
      }
    } else {
      for (i = 0; i < anim_num; i++) {
        seq[i].next_frame = next_frame;
        seq[i].ratio = ratio;
        seq[i].write_flg = 0;
      }
    }
  }
}

f32 maGetMdlMotionFrame(unsigned int *total_data, signed int id) {
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header; // r16
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header; // r17
  signed int top_id;         // r18
  signed int local_id;       // r19

  top_id = ((u32)(id & 0xFFFF0000) >> 0x10);
  local_id = id & 0xFFFF;
  main_header = (MainHeader *)*(total_data + top_id);
  if (main_header->ver == 2.0f) {
    local_header = (LocalHeader *)(main_header + 1);
    return (local_header + local_id)->frame;
  }
  return 0.0f;
}

void maMdlMotionRealDirBrendDirect(unsigned int *total_data, Seq *seq,
                                   signed int flg, float *now_dir,
                                   float *now_pos, signed int next_id,
                                   float next_frame, float ratio) {
  signed int i; // r16
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive; // r17
  signed int anim_num;  // r18
  signed int local_id;  // r19
  signed int top_id;    // r20
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header; // r21
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header; // r22

  top_id = (next_id & 0xFFFF0000) >> 16;
  local_id = next_id & 0xFFFF;
  main_header = (MainHeader *)total_data[top_id];

  if (main_header->ver == 2.0f) {
    local_header = (LocalHeader *)(main_header + 1);

    anim_num = local_header[local_id].anim_num;
    primitive = local_header[local_id].primitive_address;
    if ((seq->mode != 4) || (seq->now_top_id != top_id) ||
        (seq->now_local_id != local_id)) {
      for (i = 0; i < anim_num; i++) {
        seq[i].mode = 4;
        seq[i].model_id = primitive[i].id;
        seq[i].now_local_id = local_id;
        seq[i].now_top_id = top_id;

        seq[i].next_pos_address = primitive[i].pos;
        seq[i].next_rot_address = primitive[i].rot;
        seq[i].startVertexIdx = (signed int)primitive[i].vert;
        seq[i].vertexLoopFlg = 0;

        seq[i].next_frame = next_frame;
        seq[i].ratio = ratio;
        seq[i].write_flg = flg;

        sceVu0CopyVector(seq[i].nowDir, now_dir);
        sceVu0CopyVector(seq[i].nowTrans, now_pos);
      }
    } else {
      for (i = 0; i < anim_num; i++) {
        seq[i].next_frame = next_frame;
        seq[i].ratio = ratio;
      }
    }
  }
}

void maMdlMotionRealDirBrendDirect2(unsigned int *total_data, Seq *seq,
                                    signed int flg, float (*matrix)[4],
                                    float *now_pos, signed int next_id,
                                    float next_frame, float ratio) {
  signed int i; // r16
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive; // r17
  signed int anim_num;  // r18
  signed int local_id;  // r19
  signed int top_id;    // r20
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header; // r21
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header; // r22

  top_id = (next_id & 0xFFFF0000) >> 16;
  local_id = next_id & 0xFFFF;
  main_header = (MainHeader *)total_data[top_id];

  if (main_header->ver == 2.0f) {
    local_header = (LocalHeader *)(main_header + 1);

    anim_num = local_header[local_id].anim_num;
    primitive = local_header[local_id].primitive_address;
    if ((seq->mode != 5) || (seq->now_top_id != top_id) ||
        (seq->now_local_id != local_id)) {
      for (i = 0; i < anim_num; i++) {
        seq[i].mode = 5;
        seq[i].model_id = primitive[i].id;
        seq[i].now_local_id = local_id;
        seq[i].now_top_id = top_id;

        seq[i].next_pos_address = primitive[i].pos;
        seq[i].next_rot_address = primitive[i].rot;
        seq[i].startVertexIdx = (signed int)primitive[i].vert;
        seq[i].vertexLoopFlg = 0;

        seq[i].next_frame = next_frame;
        seq[i].ratio = ratio;
        seq[i].write_flg = flg;

        sceVu0CopyVector(seq[i].nowTrans, now_pos);
        sceVu0CopyMatrix(seq[i].now_matrix, matrix);
      }
    } else {
      for (i = 0; i < anim_num; i++) {
        seq[i].next_frame = next_frame;
        seq[i].ratio = ratio;
        seq[i].write_flg = 0;
      }
    }
  }
}

signed int maVuMdlMotionCtrl(__int128 *mdl_data, __int128 *motion_data,
                             Seq *seq, __int128 **total_data) {
  // Size: 0x20, DWARF: 0x600C8
  MainHeader *main_header;
  signed int ret;
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *mdl_header;        // 0x204(r29)
  tag_ulcodCOORDINATE *mdl_coord; // r21
  signed int coord_num;           // r23
  // Size: 0x20, DWARF: 0x60646
  LocalHeader *local_header; // 0x208(r29)
  signed int anim_num;       // r22
  // Size: 0x10, DWARF: 0x604AC
  Primitive *primitive;    // r17
  signed int o_cnt;        // r19
  signed int p_cnt;        // r16
  signed int primitive_id; // r18
  signed int mdl_id;       // r20
  float pos[4];            // 0xA0(r29)
  float rot[4];            // 0xB0(r29)
  float matrix[4][4];      // 0xC0(r29)
  float x;                 // 0x20C(r29)
  float y;                 // 0x210(r29)
  float z;                 // 0x214(r29)
  float w;                 // 0x218(r29)
  float xx;                // 0x21C(r29)
  float xy;                // 0x220(r29)
  float xz;                // 0x224(r29)
  float wx;                // 0x228(r29)
  float yy;                // 0x22C(r29)
  float yz;                // 0x230(r29)
  float wy;                // 0x234(r29)
  float zz;                // 0x238(r29)
  float wz;                // 0x23C(r29)

  main_header = (MainHeader *)motion_data;
  ret = 0;
  if (seq->now_top_id >= 0) {
    main_header = (MainHeader *)total_data[seq->now_top_id];
  }

  if (main_header->ver == 2.0f) {
    mdl_header = (ModelHeader *)mdl_data;
    mdl_coord = mdl_header->coord;
    coord_num = mdl_header->ncoord;
    local_header = (LocalHeader *)(main_header + 1);
    anim_num = local_header[seq->now_local_id].anim_num;
    primitive = local_header[seq->now_local_id].primitive_address;

    for (o_cnt = 0; o_cnt < coord_num; o_cnt++) {
      for (p_cnt = 0; p_cnt < anim_num; p_cnt++) {
        primitive_id = primitive[p_cnt].id & 0x7FFFFFFF;
        mdl_id = mdl_coord[o_cnt].id;

        if (primitive_id == mdl_id) {
          if ((seq[p_cnt].mode > 0) && (seq[p_cnt].mode < 6)) {
            sceVu0CopyVector(seq[p_cnt].pre_pos,
                             seq[p_cnt].mdl_data[o_cnt].pos);
            sceVu0CopyVector(seq[p_cnt].pre_rot,
                             seq[p_cnt].mdl_data[o_cnt].rot);
          }

          switch (seq[p_cnt].mode) {
          case 0:
            break;
          case 1:
            if (primitive[p_cnt].pos) {
              aVuMdlMotionPosDirect(&seq[p_cnt], pos);
            }
            if (primitive[p_cnt].rot) {
              aVuMdlMotionRotDirect(&seq[p_cnt], rot);
            }
            break;
          case 2:
            if (primitive[p_cnt].pos) {
              aVuMdlMotionBrendPosDirect(&seq[p_cnt], pos);
            }
            if (primitive[p_cnt].rot) {
              aVuMdlMotionBrendRotDirect(&seq[p_cnt], rot);
            }
            break;
          case 3:
            if (primitive[p_cnt].pos) {
              aVuMdlMotionRealBrendPosDirect(&seq[p_cnt], pos);
            }
            if (primitive[p_cnt].rot) {
              aVuMdlMotionRealBrendRotDirect(&seq[p_cnt], rot);
            }
            break;
          case 4:
            if (primitive[p_cnt].pos) {
              aVuMdlMotionRealDirBrendPosDirect(&seq[p_cnt], pos, mdl_id);
            }
            if (primitive[p_cnt].rot) {
              aVuMdlMotionRealDirBrendRotDirect(&seq[p_cnt], rot, mdl_id);
            }
            break;
          case 5:
            if (primitive[p_cnt].pos) {
              aVuMdlMotionRealDirBrendPosDirect2(&seq[p_cnt], pos, mdl_id);
            }
            if (primitive[p_cnt].rot) {
              aVuMdlMotionRealDirBrendRotDirect2(&seq[p_cnt], rot, mdl_id);
            }
            break;
          }

          if ((seq[p_cnt].mode > 0) && (seq[p_cnt].mode < 6)) {
            sceVu0UnitMatrix(matrix);
            x = rot[0];
            y = rot[1];
            z = rot[2];
            w = rot[3];
            xx = 2.0f * x * x;
            yy = 2.0f * y * y;
            zz = 2.0f * z * z;
            xy = 2.0f * x * y;
            wz = 2.0f * w * z;
            xz = 2.0f * x * z;
            wy = 2.0f * w * y;
            yz = 2.0f * y * z;
            wx = 2.0f * w * x;

            matrix[0][0] = 1.0f - yy - zz;
            matrix[0][1] = xy - wz;
            matrix[0][2] = xz + wy;
            matrix[1][0] = xy + wz;
            matrix[1][1] = 1.0f - xx - zz;
            matrix[1][2] = yz - wx;
            matrix[2][0] = xz - wy;
            matrix[2][1] = yz + wx;
            matrix[2][2] = 1.0f - xx - yy;

            sceVu0TransMatrix(matrix, matrix, pos);

            if (model_mode.cancel == 0) {
              if (model_mode.head && (primitive_id == 6)) {
                float scale_matrix[4][4]; // 0x100(r29)

                sceVu0UnitMatrix(scale_matrix);
                scale_matrix[0][0] = model_mode.head_scale[0];
                scale_matrix[1][1] = model_mode.head_scale[1];
                scale_matrix[2][2] = model_mode.head_scale[2];
                sceVu0MulMatrix(matrix, matrix, scale_matrix);
              }

              if ((model_mode.kid || model_mode.head) &&
                  ((primitive_id == 10) || (primitive_id == 16))) {
                float scale_matrix[4][4]; // 0x140(r29)

                sceVu0UnitMatrix(scale_matrix);
                scale_matrix[0][0] = model_mode.hand_scale[0];
                scale_matrix[1][1] = model_mode.hand_scale[1];
                scale_matrix[2][2] = model_mode.hand_scale[2];
                sceVu0MulMatrix(matrix, matrix, scale_matrix);
              }

              if (model_mode.kid) {
                if (primitive_id == 6) {
                  float scale_matrix[4][4]; // 0x180(r29)

                  sceVu0UnitMatrix(scale_matrix);
                  scale_matrix[0][0] = model_mode.kid_scale[0];
                  scale_matrix[1][1] = model_mode.kid_scale[1];
                  scale_matrix[2][2] = model_mode.kid_scale[2];
                  sceVu0MulMatrix(matrix, matrix, scale_matrix);
                }

                if (primitive_id == 0) {
                  float scale_matrix[4][4]; // 0x1C0(r29)

                  sceVu0UnitMatrix(scale_matrix);
                  scale_matrix[0][0] = model_mode.body_scale[0];
                  scale_matrix[1][1] = model_mode.body_scale[1];
                  scale_matrix[2][2] = model_mode.body_scale[2];
                  sceVu0MulMatrix(matrix, scale_matrix, matrix);
                }
              }
            }

            sceVu0CopyMatrix(mdl_coord[o_cnt].mat, matrix);
            sceVu0CopyVector(seq[p_cnt].pre_pos, pos);
            sceVu0CopyVector(seq[p_cnt].pre_rot, rot);
            sceVu0CopyVector(seq[p_cnt].mdl_data[o_cnt].pos, pos);
            sceVu0CopyVector(seq[p_cnt].mdl_data[o_cnt].rot, rot);
          }
        }
      }
    }
  }

  return ret;
}

static void aVuMdlMotionPosDirect(Seq *seq, float *pos) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now;  // r17
  float time;       // 0x30(r29)
  float now_frame;  // 0x34(r29)
  float next_frame; // 0x38(r29)
  float seq_frame;  // 0x3C(r29)

  next = seq->now_pos_address;
  if (next->non == 0) {
    if (next->frame <= seq->now_frame) {
      do {
        next++;
      } while ((next->frame <= seq->now_frame) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seq->now_frame) && (next->flg <= 0));
      now = next;
      next++;
    }
    seq->now_pos_address = now;
    seq_frame = seq->now_frame;
    now_frame = now->frame;
    next_frame = next->frame;

    if (now_frame == seq_frame) {
      sceVu0CopyVector(pos, *now->data);
    } else if (next_frame == seq_frame) {
      sceVu0CopyVector(pos, *next->data);
    } else {
      time = (seq_frame - now_frame) / (next_frame - now_frame);
      if (now->type == 0x20) {
        bezierVector(pos, now->data[0], now->data[2], next->data[1],
                     next->data[0], time);
      } else {
        sceVu0InterVectorXYZ(pos, *next->data, *now->data, time);
      }
    }
  } else {
    sceVu0CopyVector(pos, *next->data);
  }
}

static void aVuMdlMotionRotDirect(Seq *seq, float *rot) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now;  // r17
  float time;       // 0x30(r29)
  float now_frame;  // 0x34(r29)
  float next_frame; // 0x38(r29)
  float seq_frame;  // 0x3C(r29)

  next = seq->now_rot_address;
  if (next->non == 0) {
    if (next->frame <= seq->now_frame) {
      do {
        next++;
      } while ((next->frame <= seq->now_frame) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seq->now_frame) && (next->flg <= 0));
      now = next;
      next++;
    }
    seq->now_rot_address = now;
    seq_frame = seq->now_frame;
    now_frame = now->frame;
    next_frame = next->frame;
    if (now_frame == seq_frame) {
      sceVu0CopyVector(rot, *now->data);
    } else if (next_frame == seq_frame) {
      sceVu0CopyVector(rot, *next->data);
    } else {
      time = (seq_frame - now_frame) / (next_frame - now_frame);
      maQuatSlerp(rot, *now->data, *next->data, time);
    }
  } else {
    sceVu0CopyVector(rot, *next->data);
  }
}

static void aVuMdlMotionBrendPosDirect(Seq *seq, float *pos) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now; // r17
  float tmp[4];    // 0x30(r29)
  float tmp2[4];   // 0x40(r29)
  float time;      // 0x50(r29)
  float seqframe;  // 0x54(r29)
  float nowframe;  // 0x58(r29)
  float nextframe; // 0x5C(r29)

  next = seq->now_pos_address;
  if (next->non == 0) {
    seqframe = seq->now_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(tmp, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(tmp, *next->data);
    } else if (now->type == 0x20) {
      bezierVector(tmp, now->data[0], now->data[2], next->data[1],
                   next->data[0], time);
    } else {
      sceVu0InterVectorXYZ(tmp, *next->data, *now->data, time);
    }
    seq->now_pos_address = now;
  } else {
    sceVu0CopyVector(tmp, *next->data);
  }

  next = seq->next_pos_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(tmp2, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(tmp2, *next->data);
    } else if (now->type == 0x20) {
      bezierVector(tmp2, now->data[0], now->data[2], next->data[1],
                   next->data[0], time);
    } else {
      sceVu0InterVectorXYZ(tmp2, *next->data, *now->data, time);
    }
    seq->next_pos_address = now;
  } else {
    sceVu0CopyVector(tmp2, *next->data);
  }
  sceVu0InterVectorXYZ(pos, tmp2, tmp, seq->ratio);
}

static void aVuMdlMotionBrendRotDirect(Seq *seq, float *rot) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now; // r17
  float tmp[4];    // 0x30(r29)
  float tmp2[4];   // 0x40(r29)
  float time;      // 0x50(r29)
  float seqframe;  // 0x54(r29)
  float nowframe;  // 0x58(r29)
  float nextframe; // 0x5C(r29)

  next = seq->now_rot_address;
  if (next->non == 0) {
    seqframe = seq->now_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(tmp, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(tmp, *next->data);
    } else {
      maQuatSlerp(tmp, *now->data, *next->data, time);
    }
    seq->now_rot_address = now;
  } else {
    sceVu0CopyVector(tmp, *next->data);
  }

  next = seq->next_rot_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(tmp2, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(tmp2, *next->data);
    } else {
      maQuatSlerp(tmp2, *now->data, *next->data, time);
    }
    seq->next_rot_address = now;
  } else {
    sceVu0CopyVector(tmp2, *next->data);
  }
  maQuatSlerp(rot, tmp, tmp2, seq->ratio);
}

static void aVuMdlMotionRealBrendPosDirect(Seq *seq, float *pos) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now; // r17
  float tmp[4];    // 0x30(r29)
  float time;      // 0x40(r29)
  float seqframe;  // 0x44(r29)
  float nowframe;  // 0x48(r29)
  float nextframe; // 0x4C(r29)

  if (seq->write_flg != 0) {
    sceVu0CopyVector(seq->pos, seq->pre_pos);
  }

  next = seq->next_pos_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(tmp, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(tmp, *next->data);
    } else if (now->type == 0x20) {
      bezierVector(tmp, now->data[0], now->data[2], next->data[1],
                   next->data[0], time);
    } else {
      sceVu0InterVectorXYZ(tmp, *next->data, *now->data, time);
    }
    seq->next_pos_address = now;
  } else {
    sceVu0CopyVector(tmp, *next->data);
  }
  sceVu0InterVectorXYZ(pos, tmp, seq->pos, seq->ratio);
}

static void aVuMdlMotionRealBrendRotDirect(Seq *seq, float *rot) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now; // r17
  float tmp[4];    // 0x30(r29)
  float time;      // 0x40(r29)
  float seqframe;  // 0x44(r29)
  float nowframe;  // 0x48(r29)
  float nextframe; // 0x4C(r29)

  if (seq->write_flg != 0) {
    sceVu0CopyVector(seq->quat, seq->pre_rot);
  }

  next = seq->next_rot_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;
    seq->next_rot_address = now;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(tmp, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(tmp, *next->data);
    } else {
      maQuatSlerp(tmp, *now->data, *next->data, time);
    }
  } else {
    sceVu0CopyVector(tmp, *next->data);
  }
  maQuatSlerp(rot, seq->quat, tmp, seq->ratio);
}

static void aVuMdlMotionRealDirBrendPosDirect(Seq *seq, float *pos,
                                              signed int type) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now;     // r17
  float matrix[4][4];  // 0x30(r29)
  float tmp[4][4];     // 0x70(r29)
  float last[4][4];    // 0xB0(r29)
  float matrix2[4][4]; // 0xF0(r29)
  float tmp2[4][4];    // 0x130(r29)
  float last2[4][4];   // 0x170(r29)
  float trans[4];      // 0x1B0(r29)
  float time;          // 0x1C0(r29)
  float seqframe;      // 0x1C4(r29)
  float nowframe;      // 0x1C8(r29)
  float nextframe;     // 0x1CC(r29)

  if (seq->write_flg != 0) {
    sceVu0CopyVector(seq->pos, seq->pre_pos);
    if (type == 0) {
      if (seq->nowTrans[0] != 0.0f) {
        quat2Matrix(matrix, seq->quat);
        sceVu0TransMatrix(matrix, matrix, seq->pre_pos);

        sceVu0UnitMatrix(tmp);
        sceVu0RotMatrixX(tmp, tmp, seq->nowDir[0]);
        sceVu0RotMatrixY(tmp, tmp, seq->nowDir[1]);
        sceVu0RotMatrixZ(tmp, tmp, seq->nowDir[2]);
        sceVu0MulMatrix(last, tmp, matrix);

        seq->pos[0] = last[3][0];
        seq->pos[1] = last[3][1];
        seq->pos[2] = last[3][2];
      } else {
        quat2Matrix(matrix2, seq->quat);
        trans[0] = seq->pre_pos[0];
        trans[1] = seq->pre_pos[1] + seq->nowTrans[1];
        trans[2] = seq->pre_pos[2];
        trans[3] = 1.0f;
        sceVu0TransMatrix(matrix2, matrix2, trans);

        sceVu0UnitMatrix(tmp2);
        sceVu0RotMatrixX(tmp2, tmp2, seq->nowDir[0]);
        sceVu0RotMatrixY(tmp2, tmp2, seq->nowDir[1]);
        sceVu0RotMatrixZ(tmp2, tmp2, seq->nowDir[2]);
        sceVu0MulMatrix(last2, tmp2, matrix2);

        seq->pos[0] = last2[3][0];
        seq->pos[1] = last2[3][1] - seq->nowTrans[1];
        seq->pos[2] = last2[3][2];
      }
    }
  }

  next = seq->next_pos_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(pos, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(pos, *next->data);
    } else if (now->type == 0x20) {
      bezierVector(pos, now->data[0], now->data[2], next->data[1],
                   next->data[0], time);
    } else {
      sceVu0InterVectorXYZ(pos, *next->data, *now->data, time);
    }
    seq->next_pos_address = now;
  } else {
    sceVu0CopyVector(pos, *next->data);
  }
  sceVu0InterVectorXYZ(pos, pos, seq->pos, seq->ratio);
}

static void aVuMdlMotionRealDirBrendRotDirect(Seq *seq, float *rot,
                                              signed int type) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now;    // r17
  float tmp2[4];      // 0x30(r29)
  float tmp_rot[4];   // 0x40(r29)
  float matrix[4][4]; // 0x50(r29)
  float tmp[4][4];    // 0x90(r29)
  float time;         // 0xD0(r29)
  float seqframe;     // 0xD4(r29)
  float nowframe;     // 0xD8(r29)
  float nextframe;    // 0xDC(r29)

  if (seq->write_flg != 0) {
    sceVu0CopyVector(seq->quat, seq->pre_rot);
    if (type == 0) {
      quat2Matrix(matrix, seq->quat);

      sceVu0UnitMatrix(tmp);
      sceVu0RotMatrixX(tmp, tmp, seq->nowDir[0]);
      sceVu0RotMatrixY(tmp, tmp, seq->nowDir[1]);
      sceVu0RotMatrixZ(tmp, tmp, seq->nowDir[2]);

      sceVu0MulMatrix(matrix, tmp, matrix);

      matrix2Euler(tmp_rot, matrix);

      euler2Quat(seq->quat, tmp_rot);
    }
  }

  next = seq->next_rot_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (nowframe == seqframe) {
      sceVu0CopyVector(tmp2, *now->data);
    } else if (nextframe == seqframe) {
      sceVu0CopyVector(tmp2, *next->data);
    } else {
      maQuatSlerp(tmp2, *now->data, *next->data, time);
    }
    seq->next_rot_address = now;
  } else {
    sceVu0CopyVector(tmp2, *next->data);
  }
  maQuatSlerp(rot, seq->quat, tmp2, seq->ratio);
}

static void aVuMdlMotionRealDirBrendPosDirect2(Seq *seq, float *pos,
                                               signed int type) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now;    // r17
  float matrix[4][4]; // 0x30(r29)
  float tmp[4][4];    // 0x70(r29)
  float last[4][4];   // 0xB0(r29)
  float trans[4];     // 0xF0(r29)
  float time;         // 0x100(r29)
  float seqframe;     // 0x104(r29)
  float nowframe;     // 0x108(r29)
  float nextframe;    // 0x10C(r29)

  if (seq->write_flg != 0) {
    sceVu0CopyVector(seq->pos, seq->pre_pos);
    if (type == 0) {
      quat2Matrix(matrix, seq->quat);
      trans[0] = seq->pre_pos[0];
      trans[1] = seq->pre_pos[1] + seq->nowTrans[1];
      trans[2] = seq->pre_pos[2];
      trans[3] = 1.0f;
      sceVu0TransMatrix(matrix, matrix, trans);

      sceVu0InversMatrix(tmp, seq->now_matrix);

      sceVu0MulMatrix(last, tmp, matrix);

      seq->pos[0] = last[3][0];
      seq->pos[1] = last[3][1] - seq->nowTrans[1];
      seq->pos[2] = last[3][2];
    }
  }

  next = seq->next_pos_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (seqframe == nowframe) {
      sceVu0CopyVector(pos, *now->data);
    } else if (seqframe == nextframe) {
      sceVu0CopyVector(pos, *next->data);
    } else if (now->type == 0x20) {
      bezierVector(pos, now->data[0], now->data[2], next->data[1],
                   next->data[0], time);
    } else {
      sceVu0InterVectorXYZ(pos, *next->data, *now->data, time);
    }
    seq->next_pos_address = now;
  } else {
    sceVu0CopyVector(pos, *next->data);
  }
  sceVu0InterVectorXYZ(pos, pos, seq->pos, seq->ratio);
}

static void aVuMdlMotionRealDirBrendRotDirect2(Seq *seq, float *rot,
                                               signed int type) {
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *next; // r16
  // Size: 0x10, DWARF: 0x6057E
  PosAddress *now;    // r17
  float tmp2[4];      // 0x30(r29)
  float tmp_rot[4];   // 0x40(r29)
  float matrix[4][4]; // 0x50(r29)
  float tmp[4][4];    // 0x90(r29)
  float time;         // 0xD0(r29)
  float seqframe;     // 0xD4(r29)
  float nowframe;     // 0xD8(r29)
  float nextframe;    // 0xDC(r29)

  if (seq->write_flg != 0) {
    sceVu0CopyVector(seq->quat, seq->pre_rot);
    if (type == 0) {
      quat2Matrix(matrix, seq->quat);

      sceVu0InversMatrix(tmp, seq->now_matrix);

      sceVu0MulMatrix(matrix, tmp, matrix);

      matrix2Euler(tmp_rot, matrix);

      euler2Quat(seq->quat, tmp_rot);
    }
  }

  next = seq->next_rot_address;
  if (next->non == 0) {
    seqframe = seq->next_frame;
    if (next->frame <= seqframe) {
      do {
        next++;
      } while ((next->frame <= seqframe) && (next->flg >= 0));
      now = next;
      now--;
    } else {
      do {
        next--;
      } while ((next->frame > seqframe) && (next->flg <= 0));
      now = next;
      next++;
    }
    nowframe = now->frame;
    nextframe = next->frame;

    time = (seqframe - nowframe) / (nextframe - nowframe);
    if (nowframe == seqframe) {
      sceVu0CopyVector(tmp2, *now->data);
    } else if (nextframe == seqframe) {
      sceVu0CopyVector(tmp2, *next->data);
    } else {
      maQuatSlerp(tmp2, *now->data, *next->data, time);
    }
    seq->next_rot_address = now;
  } else {
    sceVu0CopyVector(tmp2, *next->data);
  }
  maQuatSlerp(rot, seq->quat, tmp2, seq->ratio);
}

void maVuMdlIKInit(__int128 *mdl_data, CtrlWithIKParam *ctrl) {
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *header;           // 0x184(r29)
  tag_ulcodCOORDINATE *coord;    // r18
  signed int coord_num;          // r22
  sceVu0FMATRIX *board_matrix;   // r19
  sceVu0FMATRIX *board_matrix2;  // 0xA0(r29)
  sceVu0FMATRIX *foot_l_matrix;  // r20
  sceVu0FMATRIX *thigh_l_matrix; // r23
  sceVu0FMATRIX *calf_l_matrix;  // r30
  sceVu0FMATRIX *toe_l_matrix;   // 0xB0(r29)
  sceVu0FMATRIX *foot_r_matrix;  // r21
  sceVu0FMATRIX *thigh_r_matrix; // 0xC0(r29)
  sceVu0FMATRIX *calf_r_matrix;  // 0xD0(r29)
  sceVu0FMATRIX *toe_r_matrix;   // 0xE0(r29)
  float matrix[4][4];            // 0xF0(r29)
  signed int i;                  // r16
  float foot[4];                 // 0x130(r29)
  float thigh[4];                // 0x140(r29)
  float calf[4];                 // 0x150(r29)
  float toe[4];                  // 0x160(r29)
  float upper_leg;               // 0x188(r29)
  float down_leg;                // 0x18C(r29)
  float calc[4];                 // 0x170(r29)
  // Size: 0x230, DWARF: 0x6134E
  IkParam *ikparam; // r17

  header = (ModelHeader *)mdl_data;
  coord = header->coord;
  coord_num = header->ncoord;
  ikparam = &ctrl->ikparam;

  for (i = 0; i < coord_num; i++) {
    coord[i].flag = 0;
  }

  for (i = 0; i < coord_num; i++) {
    aVuMdlCoord(&coord[i]);
    if (coord[i].id == 0x3E8) {
      board_matrix = &coord[i].tmp;
      ikparam->boardMat = board_matrix;
      board_matrix2 = &coord[i].mat;
      ikparam->board_local = board_matrix2;
      sceVu0CopyMatrix(ikparam->board, coord[i].mat);
    }
    if (coord[i].id == 0x15) {
      foot_l_matrix = &coord[i].tmp;
      ikparam->footMatL = foot_l_matrix;
    }
    if (coord[i].id == 0x19) {
      foot_r_matrix = &coord[i].tmp;
      ikparam->footMatR = foot_r_matrix;
    }
    if (coord[i].id == 0x13) {
      thigh_l_matrix = &coord[i].tmp;
      ikparam->thighMatL = thigh_l_matrix;
    }
    if (coord[i].id == 0x17) {
      thigh_r_matrix = &coord[i].tmp;
      ikparam->thighMatR = thigh_r_matrix;
    }
    if (coord[i].id == 0x14) {
      calf_l_matrix = &coord[i].tmp;
      ikparam->calfMatL = calf_l_matrix;
    }
    if (coord[i].id == 0x18) {
      calf_r_matrix = &coord[i].tmp;
      ikparam->calfMatR = calf_r_matrix;
    }
    if (coord[i].id == 0x16) {
      toe_l_matrix = &coord[i].tmp;
      ikparam->toeMatL = toe_l_matrix;
    }
    if (coord[i].id == 0x1A) {
      toe_r_matrix = &coord[i].tmp;
      ikparam->toeMatR = toe_r_matrix;
    }
  }

  for (i = 0; i < 3; i++) {
    ikparam->rot[i] = 0.0f;
    ikparam->trans[i] = 0.0f;
  }

  ikparam->rot[3] = 1.0f;
  ikparam->trans[3] = 1.0f;

  ikparam->off_trans[0][0] = 2.78f;
  ikparam->off_trans[0][1] = 1.051f;
  ikparam->off_trans[0][2] = 1.589f;
  ikparam->off_trans[0][3] = 1.0f;
  ikparam->off_trans[1][0] = -3.002f;
  ikparam->off_trans[1][1] = 1.05f;
  ikparam->off_trans[1][2] = 1.578f;
  ikparam->off_trans[1][3] = 1.0f;

  ikparam->off_trans_toe[0][0] = 3.026f;
  ikparam->off_trans_toe[0][1] = -0.951f;
  ikparam->off_trans_toe[0][2] = 0.223f;
  ikparam->off_trans_toe[0][3] = 1.0f;
  ikparam->off_trans_toe[1][0] = -3.265f;
  ikparam->off_trans_toe[1][1] = -0.949f;
  ikparam->off_trans_toe[1][2] = 0.212f;
  ikparam->off_trans_toe[1][3] = 1.0f;

  sceVu0UnitMatrix(matrix);
  sceVu0RotMatrix(matrix, matrix, ikparam->rot);
  sceVu0TransMatrix(matrix, matrix, ikparam->trans);
  sceVu0MulMatrix(*board_matrix, *board_matrix, matrix);

  sceVu0UnitMatrix(matrix);
  sceVu0TransMatrix(matrix, matrix, ikparam->off_trans[0]);
  sceVu0MulMatrix(matrix, *board_matrix, matrix);
  sceVu0CopyVector((*foot_l_matrix)[3], matrix[3]);

  sceVu0UnitMatrix(matrix);
  sceVu0TransMatrix(matrix, matrix, ikparam->off_trans[1]);
  sceVu0MulMatrix(matrix, *board_matrix, matrix);
  sceVu0CopyVector((*foot_r_matrix)[3], matrix[3]);

  sceVu0CopyVector(foot, (*foot_l_matrix)[3]);
  foot[3] = 1.0f;
  sceVu0CopyVector(thigh, (*thigh_l_matrix)[3]);
  thigh[3] = 1.0f;
  sceVu0CopyVector(calf, (*calf_l_matrix)[3]);
  calf[3] = 1.0f;
  sceVu0CopyVector(toe, (*toe_l_matrix)[3]);
  toe[3] = 1.0f;

  sceVu0SubVector(calc, calf, thigh);
  upper_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  upper_leg = sqrtf(upper_leg);
  sceVu0SubVector(calc, foot, calf);
  down_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  down_leg = sqrtf(down_leg);

  ikparam->thighLength[0] = upper_leg;
  ikparam->shinLength[0] = down_leg;

  sceVu0SubVector(calc, foot, calf);
  upper_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  upper_leg = sqrtf(upper_leg);
  sceVu0SubVector(calc, toe, foot);
  down_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  down_leg = sqrtf(down_leg);

  ikparam->thighLength_toe[0] = upper_leg;
  ikparam->shinLength_toe[0] = down_leg;

  sceVu0CopyVector(foot, (*foot_r_matrix)[3]);
  foot[3] = 1.0f;
  sceVu0CopyVector(thigh, (*thigh_r_matrix)[3]);
  thigh[3] = 1.0f;
  sceVu0CopyVector(calf, (*calf_r_matrix)[3]);
  calf[3] = 1.0f;
  sceVu0CopyVector(toe, (*toe_r_matrix)[3]);
  toe[3] = 1.0f;

  sceVu0SubVector(calc, calf, thigh);
  upper_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  upper_leg = sqrtf(upper_leg);
  sceVu0SubVector(calc, foot, calf);
  down_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  down_leg = sqrtf(down_leg);

  ikparam->thighLength[1] = upper_leg;
  ikparam->shinLength[1] = down_leg;

  sceVu0SubVector(calc, foot, calf);
  upper_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  upper_leg = sqrtf(upper_leg);
  sceVu0SubVector(calc, toe, foot);
  down_leg = calc[0] * calc[0] + calc[1] * calc[1] + calc[2] * calc[2];
  down_leg = sqrtf(down_leg);

  ikparam->thighLength_toe[1] = upper_leg;
  ikparam->shinLength_toe[1] = down_leg;

  ikparam->flg = 1;
}

void aVuMdlCoord(tag_ulcodCOORDINATE *coord) {
  float matrix[4][4]; // 0x10(r29)
  if (coord->flag == 0) {
    if (coord->super != 0) {
      aVuMdlCoord(coord->super);
      sceVu0MulMatrix(coord->tmp, coord->super->tmp, coord->mat);
    } else {
      sceVu0UnitMatrix(&matrix);
      sceVu0MulMatrix(coord->tmp, &matrix, coord->mat);
    }
    coord->flag = 1;
  }
}

void maVuMdlIKCtrl(__int128 *mdl_data, CtrlWithIKParam *ctrl) {
  signed int i;               // r16
  tag_ulcodCOORDINATE *coord; // r17
  signed int coord_num;       // r18
  unsigned int id;            // r19
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *header;          // r20
  float(*board_matrix)[4][4];   // r21
  float board_tmp_matrix[4][4]; // 0x70(r29)
  float matrix[4][4];           // 0xB0(r29)
  float max_trans[4];           // 0xF0(r29)
  float scale_matrix[4][4];     // 0x100(r29)

  header = (ModelHeader *)mdl_data;
  coord = header->coord;
  coord_num = header->ncoord;

  for (i = 0; i < coord_num; i++) {
    id = coord[i].id;
    switch (id) {
    case 0x3E8:
    case 0:
    case 2:
    case 3:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1A:
      coord[i].flag = 0;
      break;
    default:
      coord[i].flag = 1;
      break;
    }
  }

  if (ctrl->ikparam.flg != 0) {
    for (i = 0; i < coord_num; i++) {
      if (coord[i].id == 0x3E8) {
        sceVu0CopyMatrix(coord[i].mat, ctrl->ikparam.board);
      }
      aVuMdlCoord(&coord[i]);
      if (coord[i].id == 0x15) {
        sceVu0CopyMatrix(ctrl->ikparam.footL, coord[i].tmp);
      }
      if (coord[i].id == 0x19) {
        sceVu0CopyMatrix(ctrl->ikparam.footR, coord[i].tmp);
      }
    }

    board_matrix = ctrl->ikparam.boardMat;

    sceVu0UnitMatrix(matrix);
    sceVu0RotMatrix(matrix, matrix, ctrl->ikparam.rot);
    sceVu0CopyVector(max_trans, ctrl->ikparam.trans);
    sceVu0TransMatrix(matrix, matrix, max_trans);
    sceVu0MulMatrix(*board_matrix, *board_matrix, matrix);
    sceVu0CopyMatrix(board_tmp_matrix, *board_matrix);
    sceVu0CopyMatrix(ctrl->ikparam.board_world, *board_matrix);
    sceVu0MulMatrix(*ctrl->ikparam.board_local, *ctrl->ikparam.board_local,
                    matrix);

    for (i = 0; i < coord_num; i++) {
      if (coord[i].id != 0x3E8) {
        coord[i].flag = 0;
      }
    }

    for (i = 0; i < coord_num; i++) {
      aVuMdlIKCoord(&coord[i], ctrl, header);
    }
    board_matrix = ctrl->ikparam.board_local;

    sceVu0CopyMatrix(*board_matrix, ctrl->ikparam.board);

    sceVu0UnitMatrix(scale_matrix);
    scale_matrix[0][0] = 1.0f / model_mode.body_scale[0];
    scale_matrix[1][1] = 1.0f / model_mode.body_scale[1];
    scale_matrix[2][2] = 1.0f / model_mode.body_scale[2];
  }
}

static void aVuMdlIKCoord(tag_ulcodCOORDINATE *coord, CtrlWithIKParam *ctrl,
                          ModelHeader *header) {
  unsigned int type;        // r16
  float matrix[4][4];       // 0x20(r29)
  float m[4][4];            // 0x60(r29)
  float tmp[4][4];          // 0xA0(r29)
  float rot[4];             // 0xE0(r29)
  float rot2[4][4];         // 0xF0(r29)
  float tmpx[4][4];         // 0x130(r29)
  float trans[4];           // 0x170(r29)
  float scale_matrix[4][4]; // 0x180(r29)

  type = coord->id;

  if (coord->flag == 0) {
    if (coord->super != 0) {
      aVuMdlIKCoord(coord->super, ctrl, header);

      sceVu0CopyMatrix(matrix, coord->super->tmp);

      sceVu0MulMatrix(coord->tmp, matrix, coord->mat);

      if ((type != 0x13) && (type != 0x14) && (type != 0x15) &&
          (type != 0x17) && (type != 0x18) && (type != 0x19) &&
          (type != 0x3E8)) {
        coord->flag = 1;
        return;
      }

      if (type == 0x3E8) {
        coord->flag = 1;
        return;
      }

      rot[0] = 0.0f;
      rot[1] = 0.0f;
      rot[2] = 0.0f;

      if ((type == 0x13) || (type == 0x17)) {
        aVuMdlIKComp(rot, header, ctrl, type);
      }

      if (type == 0x14) {
        aVuMdlIKComp(rot, header, ctrl, type);
      }

      if (type == 0x18) {
        aVuMdlIKComp(rot, header, ctrl, type);
      }

      if ((type == 0x15) || (type == 0x19)) {
        rot[1] = -ctrl->ikparam.rot[1];
        rot[2] = -ctrl->ikparam.rot[0];
      }

      sceVu0CopyMatrix(matrix, coord->super->tmp);
      sceVu0CopyMatrix(tmp, coord->mat);
      tmp[3][0] = 0.0f;
      tmp[3][1] = 0.0f;
      tmp[3][2] = 0.0f;
      tmp[3][3] = 1.0f;
      sceVu0UnitMatrix(rot2);
      sceVu0RotMatrixZ(rot2, rot2, rot[2]);
      sceVu0RotMatrixY(rot2, rot2, rot[1]);
      sceVu0MulMatrix(m, tmp, rot2);

      sceVu0TransMatrix(m, m, coord->mat[3]);

      sceVu0MulMatrix(matrix, matrix, m);

      if ((type == 0x15) || (type == 0x19)) {
        sceVu0UnitMatrix(scale_matrix);
        scale_matrix[0][0] = 1.0f / model_mode.body_scale[0];
        scale_matrix[1][1] = 1.0f / model_mode.body_scale[1];
        scale_matrix[2][2] = 1.0f / model_mode.body_scale[2];

        sceVu0CopyMatrix(tmpx, matrix);
        if (type == 0x15) {
          sceVu0CopyMatrix(matrix, ctrl->ikparam.footL);
        }
        if (type == 0x19) {
          sceVu0CopyMatrix(matrix, ctrl->ikparam.footR);
        }
        sceVu0CopyVector(trans, coord->mat[3]);
        sceVu0MulMatrix(m, tmp, rot2);

        sceVu0InversMatrix(m, coord->super->tmp);

        sceVu0MulMatrix(m, m, scale_matrix);
        sceVu0MulMatrix(matrix, matrix, scale_matrix);

        sceVu0MulMatrix(matrix, m, matrix);
        sceVu0MulMatrix(matrix, matrix, rot2);
        sceVu0CopyMatrix(coord->mat, matrix);
        sceVu0CopyVector(coord->mat[3], trans);
        sceVu0TransMatrix(m, m, coord->tmp[3]);

        sceVu0MulMatrix(matrix, matrix, m);
        sceVu0CopyMatrix(coord->tmp, matrix);
        sceVu0CopyVector(coord->tmp[3], tmpx[3]);
      } else {
        sceVu0CopyMatrix(coord->tmp, matrix);
        sceVu0CopyMatrix(coord->mat, m);
      }
    }
    coord->flag = 1;
  }
}

static void aVuMdlIKComp(float *rot, ModelHeader *unused1,
                         CtrlWithIKParam *ctrl, unsigned int id) {
  // Size: 0x230, DWARF: 0x6134E
  IkParam *ikparam;            // r16
  sceVu0FMATRIX *board_matrix; // r21
  sceVu0FMATRIX *base_matrix;  // r17
  sceVu0FMATRIX *targ_matrix;  // r20
  sceVu0FMATRIX *uvec_matrix;  // r19
  float now_target[4];         // 0x70(r29)
  float base[4];               // 0x80(r29)
  float targ[4];               // 0x90(r29)
  float uvec[4];               // 0xA0(r29)
  float matrix[4][4];          // 0xB0(r29)
  float omega;                 // 0x284(r29)
  float nowOmega;              // 0x288(r29)
  float omega2;                // 0x28C(r29)
  float nowOmega2;             // 0x290(r29)
  float ue;                    // 0x294(r29)
  float sita;                  // 0x298(r29)
  float ue2;                   // 0x29C(r29)
  float sita2;                 // 0x2A0(r29)
  unsigned int lr_flg;         // r18
  float direct;                // 0x2A4(r29)
  float upper;                 // 0x2A8(r29)
  float down;                  // 0x2AC(r29)
  float tmp1;                  // 0x2B0(r29)
  float tmp2;                  // 0x2B4(r29)
  float tmp3;                  // 0x2B8(r29)
  float tmp4;                  // 0x2BC(r29)

  ikparam = &ctrl->ikparam;
  board_matrix = ikparam->boardMat;

  switch (id) {
  case 0x13:
  case 0x14:
    lr_flg = 0;
    base_matrix = ikparam->thighMatL;
    uvec_matrix = ikparam->calfMatL;
    targ_matrix = ikparam->footMatL;
    break;
  case 0x17:
  case 0x18:
    lr_flg = 1;
    base_matrix = ikparam->thighMatR;
    uvec_matrix = ikparam->calfMatR;
    targ_matrix = ikparam->footMatR;
    break;
  }

  sceVu0UnitMatrix(matrix);
  sceVu0TransMatrix(matrix, matrix, ikparam->off_trans[lr_flg]);
  sceVu0MulMatrix(matrix, *board_matrix, matrix);

  sceVu0CopyVector(now_target, (*targ_matrix)[3]);
  sceVu0CopyVector(targ, matrix[3]);
  sceVu0CopyVector(base, (*base_matrix)[3]);
  sceVu0CopyVector(uvec, (*uvec_matrix)[3]);

  direct = (targ[0] - base[0]) * (targ[0] - base[0]) +
           (targ[1] - base[1]) * (targ[1] - base[1]) +
           (targ[2] - base[2]) * (targ[2] - base[2]);
  direct = sqrtf(direct);

  upper = ikparam->thighLength[lr_flg];
  down = ikparam->shinLength[lr_flg];

  tmp1 = upper * upper;
  tmp2 = down * down;
  tmp3 = direct * direct;
  tmp4 = 2.0f * direct;
  ue = tmp3 + (tmp1 - tmp2);
  sita = upper * tmp4;
  omega = acosf(ue / sita);

  ue2 = tmp3 + (tmp2 - tmp1);
  sita2 = down * tmp4;
  omega2 = acosf(ue2 / sita2);

  direct = (now_target[0] - base[0]) * (now_target[0] - base[0]) +
           (now_target[1] - base[1]) * (now_target[1] - base[1]) +
           (now_target[2] - base[2]) * (now_target[2] - base[2]);
  direct = sqrtf(direct);
  tmp3 = direct * direct;
  tmp4 = 2.0f * direct;
  ue = tmp3 + (tmp1 - tmp2);
  sita = upper * tmp4;
  nowOmega = acosf(ue / sita);

  ue2 = tmp3 + (tmp2 - tmp1);
  sita2 = down * tmp4;
  nowOmega2 = acosf(ue2 / sita2);

  if (id == 0x13) {
    float tmp[4];     // 0xF0(r29)
    float mtmp[4];    // 0x100(r29)
    float nowTmp[4];  // 0x110(r29)
    float mnowTmp[4]; // 0x120(r29)
    float out[4];     // 0x130(r29)
    float in;         // 0x2C0(r29)
    float inv[4][4];  // 0x140(r29)

    sceVu0InversMatrix(inv, *base_matrix);
    inv[3][0] = 0.0f;
    inv[3][1] = 0.0f;
    inv[3][2] = 0.0f;

    sceVu0SubVector(tmp, targ, base);
    sceVu0ApplyMatrix(tmp, inv, tmp);
    sceVu0Normalize(tmp, tmp);
    sceVu0CopyVector(mtmp, tmp);
    sceVu0SubVector(nowTmp, now_target, base);
    sceVu0ApplyMatrix(nowTmp, inv, nowTmp);
    sceVu0Normalize(nowTmp, nowTmp);
    sceVu0CopyVector(mnowTmp, nowTmp);
    sceVu0OuterProduct(out, tmp, nowTmp);

    tmp[2] = 0.0f;
    nowTmp[2] = 0.0f;
    sceVu0Normalize(tmp, tmp);
    sceVu0Normalize(nowTmp, nowTmp);
    in = sceVu0InnerProduct(tmp, nowTmp);
    in = acosf(in);
    if (out[2] > 0.0f) {
      in = -in;
    }
    rot[2] = in + omega - nowOmega;

    mtmp[1] = 0.0f;
    mnowTmp[1] = 0.0f;
    sceVu0Normalize(tmp, mtmp);
    sceVu0Normalize(nowTmp, mnowTmp);

    in = sceVu0InnerProduct(tmp, nowTmp);
    in = acosf(in);
    if (out[1] < 0.0f) {
      in = -in;
    }
    rot[1] = -in;
  } else if (id == 0x17) {
    float tmp[4];     // 0x180(r29)
    float mtmp[4];    // 0x190(r29)
    float nowTmp[4];  // 0x1A0(r29)
    float mnowTmp[4]; // 0x1B0(r29)
    float out[4];     // 0x1C0(r29)
    float in;         // 0x2C4(r29)
    float inv[4][4];  // 0x1D0(r29)

    sceVu0InversMatrix(inv, *base_matrix);
    sceVu0SubVector(tmp, targ, base);
    tmp[3] = 1.0f;

    inv[3][0] = 0.0f;
    inv[3][1] = 0.0f;
    inv[3][2] = 0.0f;
    sceVu0ApplyMatrix(tmp, inv, tmp);
    sceVu0Normalize(tmp, tmp);
    sceVu0CopyVector(mtmp, tmp);
    sceVu0SubVector(nowTmp, now_target, base);
    nowTmp[3] = 1.0f;

    sceVu0ApplyMatrix(nowTmp, inv, nowTmp);
    sceVu0Normalize(nowTmp, nowTmp);
    sceVu0CopyVector(mnowTmp, nowTmp);
    sceVu0OuterProduct(out, tmp, nowTmp);

    tmp[2] = 0.0f;
    nowTmp[2] = 0.0f;
    sceVu0Normalize(tmp, tmp);
    sceVu0Normalize(nowTmp, nowTmp);

    in = sceVu0InnerProduct(tmp, nowTmp);
    in = acosf(in);
    if (out[2] > 0.0f) {
      in = -in;
    }
    rot[2] = in + omega - nowOmega;

    mtmp[1] = 0.0f;
    mnowTmp[1] = 0.0f;
    sceVu0Normalize(tmp, mtmp);
    sceVu0Normalize(nowTmp, mnowTmp);

    in = sceVu0InnerProduct(tmp, nowTmp);
    in = acosf(in);
    if (out[1] < 0.0f) {
      in = -in;
    }
    rot[1] = -in;
  } else if (id == 0x14) {
    float inv[4][4]; // 0x210(r29)
    float c2b[4];    // 0x250(r29)
    float c2f[4];    // 0x260(r29)
    float outer[4];  // 0x270(r29)
    float inner;     // 0x2C8(r29)
    float inomega;   // 0x2CC(r29)

    sceVu0InversMatrix(inv, *uvec_matrix);
    inv[3][0] = 0.0f;
    inv[3][1] = 0.0f;
    inv[3][2] = 0.0f;

    sceVu0SubVector(c2b, targ, uvec);
    c2b[3] = 1.0f;
    sceVu0SubVector(c2f, now_target, uvec);
    c2f[3] = 1.0f;

    sceVu0ApplyMatrix(c2b, inv, c2b);
    sceVu0ApplyMatrix(c2f, inv, c2f);

    sceVu0Normalize(c2b, c2b);
    sceVu0Normalize(c2f, c2f);
    sceVu0OuterProduct(outer, c2b, c2f);
    inner = sceVu0InnerProduct(c2b, c2f);
    inomega = acosf(inner);
    rot[1] = 0.0f;
    rot[2] = (3.141592f - omega - omega2) - (3.141592f - nowOmega - nowOmega2);
  } else if (id == 0x18) {
    rot[1] = 0.0f;
    rot[2] = (3.141592f - omega - omega2) - (3.141592f - nowOmega - nowOmega2);
  }
}

void maSecMotionInit(__int128 *mdl_data, MotionCtrl *ctrl) {
  float initVec[4] = {0.0f, 0.0f, 0.0f, 1.0f}; // 0x80(r29)
  float *unused1 = initVec;
  signed int o_cnt;               // r16
  tag_ulcodCOORDINATE *mdl_coord; // r17
  signed int i;                   // r18
  signed int coord_num;           // r19
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *mdl_header; // r20

  mdl_header = (ModelHeader *)mdl_data;
  mdl_coord = mdl_header->coord;
  coord_num = mdl_header->ncoord;

  if (ctrl != 0) {
    ctrl->type = 0;
    ctrl->cnt = 0.0f;
    ctrl->power = 0.4f;
    ctrl->dir = 0.0f;
    sceVu0CopyVector(ctrl->g_vector, initVec);
    sceVu0CopyVector(ctrl->head, initVec);
    for (i = 0; i < 5; i++) {
      ctrl->tailAddress[i] = 0;
    }
    if (mdl_header->version == 2) {
      for (o_cnt = 0; o_cnt < coord_num; o_cnt++) {
        if (mdl_coord[o_cnt].id == 0x6) {
          ctrl->tailAddress[4] = (unsigned int *)mdl_coord[o_cnt].tmp;
          sceVu0CopyMatrix(ctrl->tail_matrix[4], mdl_coord[o_cnt].mat);
        }

        if (mdl_coord[o_cnt].id == 0x20) {
          ctrl->tailAddress[0] = (unsigned int *)mdl_coord[o_cnt].tmp;
          sceVu0CopyMatrix(ctrl->tail_matrix[0], mdl_coord[o_cnt].mat);
        }

        if (mdl_coord[o_cnt].id == 0x21) {
          ctrl->tailAddress[1] = (unsigned int *)mdl_coord[o_cnt].tmp;
          sceVu0CopyMatrix(ctrl->tail_matrix[1], mdl_coord[o_cnt].mat);
        }

        if (mdl_coord[o_cnt].id == 0x22) {
          ctrl->tailAddress[2] = (unsigned int *)mdl_coord[o_cnt].tmp;
          sceVu0CopyMatrix(ctrl->tail_matrix[2], mdl_coord[o_cnt].mat);
        }

        if (mdl_coord[o_cnt].id == 0x23) {
          ctrl->tailAddress[3] = (unsigned int *)mdl_coord[o_cnt].tmp;
          sceVu0CopyMatrix(ctrl->tail_matrix[3], mdl_coord[o_cnt].mat);
        }
      }
    }
  } else {
    if (mdl_header->version == 2) {
      float rot[4] = {0.0f, 0.0f, -0.4f, 0.0f}; // 0x90(r29)
      float *unused2 = rot;
      float matrix[4][4]; // 0xA0(r29)

      for (o_cnt = 0; o_cnt < coord_num; o_cnt++) {
        if (mdl_coord[o_cnt].id == 0x20) {
          sceVu0UnitMatrix(matrix);
          sceVu0RotMatrix(matrix, matrix, rot);
          sceVu0MulMatrix(mdl_coord[o_cnt].mat, mdl_coord[o_cnt].mat, matrix);
        }

        if (mdl_coord[o_cnt].id == 0x21) {
          sceVu0UnitMatrix(matrix);
          sceVu0RotMatrix(matrix, matrix, rot);
          sceVu0MulMatrix(mdl_coord[o_cnt].mat, mdl_coord[o_cnt].mat, matrix);
        }

        if (mdl_coord[o_cnt].id == 0x22) {
          sceVu0UnitMatrix(matrix);
          sceVu0RotMatrix(matrix, matrix, rot);
          sceVu0MulMatrix(mdl_coord[o_cnt].mat, mdl_coord[o_cnt].mat, matrix);
        }

        if (mdl_coord[o_cnt].id == 0x23) {
          sceVu0UnitMatrix(matrix);
          sceVu0RotMatrix(matrix, matrix, rot);
          sceVu0MulMatrix(mdl_coord[o_cnt].mat, mdl_coord[o_cnt].mat, matrix);
        }
      }
    }
  }
}

void maSecMotionCtrl(__int128 *mdl_data, MotionCtrl *ctrl,
                     float (*root_matrix)[4]) {
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *mdl_header = (ModelHeader *)mdl_data;  // r19
  tag_ulcodCOORDINATE *mdl_coord = mdl_header->coord; // r17
  signed int coord_num = mdl_header->ncoord;          // r20
  signed int o_cnt;                                   // r16
  float rot[4];                                       // 0xA0(r29)
  float matrix[4][4];                                 // 0xB0(r29)
  float up[4] = {10.0f, 0.0f, 0.0f, 1.0f};            // 0xF0(r29)
  float *unused1 = up;
  float front[4] = {0.0f, 10.0f, 0.0f, 1.0f}; // 0x100(r29)
  float *unused2 = front;
  float side[4] = {0.0f, 0.0f, 10.0f, 1.0f}; // 0x110(r29)
  float *unused3 = side;
  float tmp_matrix[4][4];                          // 0x120(r29)
  float scale_matrix[4][4];                        // 0x160(r29)
  float scale_matrix2[4][4];                       // 0x1A0(r29)
  float gravity[4] = {0.0f, 0.0f, 1.57085f, 0.0f}; // 0x1E0(r29)
  float *unused4 = gravity;
  float g_vector[4];  // 0x1F0(r29)
  float move[4];      // 0x200(r29)
  float speed = 0.4f; // 0x214(r29)
  float calc;         // 0x218(r29)
  float param;        // 0x21C(r29)
  signed int flg;     // r18

  sceVu0UnitMatrix(tmp_matrix);
  sceVu0RotMatrix(tmp_matrix, tmp_matrix, gravity);
  sceVu0CopyVector(g_vector, ctrl->g_vector);

  sceVu0UnitMatrix(scale_matrix2);

  if (model_mode.head) {
    sceVu0UnitMatrix(scale_matrix);
    scale_matrix[0][0] = 1.0f / model_mode.head_scale[0];
    scale_matrix[1][1] = 1.0f / model_mode.head_scale[1];
    scale_matrix[2][2] = 1.0f / model_mode.head_scale[2];
    sceVu0MulMatrix(scale_matrix2, scale_matrix2, scale_matrix);
  }

  if (model_mode.kid) {
    sceVu0UnitMatrix(scale_matrix);
    scale_matrix[0][0] = 1.0f / model_mode.kid_scale[0];
    scale_matrix[1][1] = 1.0f / model_mode.kid_scale[1];
    scale_matrix[2][2] = 1.0f / model_mode.kid_scale[2];
    sceVu0MulMatrix(scale_matrix2, scale_matrix2, scale_matrix);
    sceVu0UnitMatrix(scale_matrix);
    scale_matrix[0][0] = 1.0f / model_mode.body_scale[0];
    scale_matrix[1][1] = 1.0f / model_mode.body_scale[1];
    scale_matrix[2][2] = 1.0f / model_mode.body_scale[2];
    sceVu0MulMatrix(scale_matrix2, scale_matrix2, scale_matrix);
  }

  if (mdl_header->version == 2) {
    for (o_cnt = 0; o_cnt < coord_num; o_cnt++) {
      if (mdl_coord[o_cnt].id == 6) {
        sceVu0CopyMatrix(tmp_matrix, mdl_coord[o_cnt].tmp);
        sceVu0MulMatrix(tmp_matrix, root_matrix, tmp_matrix);

        sceVu0SubVector(move, ctrl->head, tmp_matrix[3]);
        calc = (move[0] * move[0]) + (move[1] * move[1]) + (move[2] * move[2]);
        sceVu0CopyVector(ctrl->head, tmp_matrix[3]);
        calc = 15.0f - calc;
        if (calc < 0.0f) {
          calc = 0.0f;
        }
        speed = (speed * calc) / 10.0f;

        calc = speed - ctrl->power;
        ctrl->power = ctrl->power + (0.1f * calc);
        if (ctrl->power > 0.4f) {
          ctrl->power = 0.4f;
        }

        tmp_matrix[3][0] = 0.0f;
        tmp_matrix[3][1] = 0.0f;
        tmp_matrix[3][2] = 0.0f;
        tmp_matrix[3][3] = 1.0f;

        sceVu0MulMatrix(tmp_matrix, tmp_matrix, scale_matrix2);

        if (ctrl->type != 0) {
          tmp_matrix[0][0] = 0.0f;
          tmp_matrix[0][1] = -1.0f;
          tmp_matrix[0][2] = 0.0f;
          tmp_matrix[1][0] = 0.0f;
          tmp_matrix[1][1] = 0.0f;
          tmp_matrix[1][2] = -1.0f;
          tmp_matrix[2][0] = 1.0f;
          tmp_matrix[2][1] = 0.0f;
          tmp_matrix[2][2] = 0.0f;
        }

        sceVu0ApplyMatrix(up, tmp_matrix, up);
        sceVu0ApplyMatrix(front, tmp_matrix, front);
        sceVu0ApplyMatrix(side, tmp_matrix, side);
      }

      if (mdl_coord[o_cnt].id == 0x20) {
        flg = 0;

        sceVu0UnitMatrix(matrix);

        if (front[1] < 0.0f) {
          front[1] = 0.0f;
        }

        param = 0.0f;
        rot[1] = -0.4f * (0.1f * side[1]);

        speed = ctrl->power;
        rot[2] = speed * (0.1f * (param + (up[1] + front[1])));
        rot[2] = rot[2] + g_vector[2];
        if (rot[2] >= speed) {
          rot[2] = speed;
          flg = 1;
        }

        if (rot[2] <= -speed) {
          rot[2] = -speed;
          flg = 1;
        }

        if (0.0f == front[1]) {
          flg = 1;
        }

        if (flg == 0) {
          if (up[1] >= 0.0f) {
            ctrl->g_vector[2] += 0.01f;
          } else {
            ctrl->g_vector[2] += -0.01f;
          }
        }

        rot[2] *= 1.3f;
        rot[1] *= 1.5f;
        rot[0] = 0.0f;

        sceVu0RotMatrix(matrix, matrix, rot);
        sceVu0MulMatrix(mdl_coord[o_cnt].mat, ctrl->tail_matrix[0], matrix);
      }

      if (mdl_coord[o_cnt].id == 0x21) {
        sceVu0UnitMatrix(matrix);
        sceVu0RotMatrix(matrix, matrix, rot);
        sceVu0MulMatrix(mdl_coord[o_cnt].mat, ctrl->tail_matrix[1], matrix);
      }

      if (mdl_coord[o_cnt].id == 0x22) {
        sceVu0UnitMatrix(matrix);
        sceVu0RotMatrix(matrix, matrix, rot);
        sceVu0MulMatrix(mdl_coord[o_cnt].mat, ctrl->tail_matrix[2], matrix);
      }

      if (mdl_coord[o_cnt].id == 0x23) {
        sceVu0UnitMatrix(matrix);
        sceVu0RotMatrix(matrix, matrix, rot);
        sceVu0MulMatrix(mdl_coord[o_cnt].mat, ctrl->tail_matrix[3], matrix);
      }
    }
  }
}

unsigned char *maCreateModelLink(unsigned char **mdl_data,
                                 signed int *file_size, signed int *text_num,
                                 signed int *alpha_num, signed int num) {
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *mdl_header;        // 0xA0(r29)
  tag_ulcodCOORDINATE *mdl_coord; // 0xA4(r29)
  signed int coord_num;           // 0xA8(r29)
  signed int object_num;          // 0xAC(r29)
  unsigned char *ret_data;        // 0xB0(r29)
  unsigned char *data;            // 0xB4(r29)
  unsigned char *mdl_cur_data;    // 0xB8(r29)
  signed int add_object;          // 0xBC(r29)
  signed int size;                // 0xC0(r29)
  signed int i;                   // 0xC4(r29)
  signed int j;                   // 0xC8(r29)
  signed int cur_address;         // 0xCC(r29)
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *ret_header; // 0xD0(r29)
  signed int tmp;          // 0xD4(r29)
  signed int *tmp_int;     // 0xD8(r29)
  signed int data_size;    // 0xDC(r29)
  signed int *tmp_data;    // 0xE0(r29)
  signed int obj_cnt;      // 0xE4(r29)
  signed int block_cnt;    // 0xE8(r29)
  signed int obj_max;      // 0xEC(r29)
  signed int block_max;    // 0xF0(r29)
  signed int coord;        // 0xF4(r29)
  signed int size2;        // 0xF8(r29)
  signed int mode;         // 0xFC(r29)
  signed int now_tmp_text; // r16
  // Size: 0x20, DWARF: 0x607A7
  PrimData *prim_data;       // r17
  signed int prim_cnt;       // r18
  signed int *tmp_prim_data; // r19
  signed int alpha;          // r20
  signed int prim_max;       // r21
  signed int *tmp_cur_data;  // r22
  signed int now_text;       // r23
  signed int now_alpha_text; // r30

  ret_data = 0;

  add_object = 0;
  size = 0;

  cur_address = 0;

  now_text = 0;
  now_alpha_text = 0;

  for (i = 0; i < num; i++) {
    size += file_size[i];
    if (i > 0) {
      mdl_header = (ModelHeader *)mdl_data[i];
      mdl_coord = mdl_header->coord;
      coord_num = mdl_header->ncoord;
      object_num = mdl_header->nobj;
      add_object += object_num;
    }
  }
  size += add_object * 16;

  if (add_object > 0) {
    data = ret_data = (unsigned char *)ulMalloc(size, 0, 1);
    ret_header = (ModelHeader *)ret_data;
    memcpy(ret_data, mdl_data[0], 0x20);
    data += 0x20;
    ret_header->nobj += add_object;
    tmp = (signed int)ret_header->coord;
    tmp += add_object;
    ret_header->coord = (tag_ulcodCOORDINATE *)tmp;

    cur_address += add_object;
    for (i = 0; i < num; i++) {
      mdl_header = (ModelHeader *)mdl_data[i];
      object_num = mdl_header->nobj;
      mdl_cur_data = mdl_data[i];
      mdl_cur_data += 0x20;
      for (j = 0; j < object_num; j++) {
        memcpy(data, mdl_cur_data, 0x10);
        tmp = data[1];
        tmp += cur_address;
        tmp_int = (signed int *)data;
        tmp = tmp_int[1];
        tmp += cur_address;
        tmp_int[1] = tmp;
        data += 0x10;
        mdl_cur_data += 0x10;
      }
      cur_address += file_size[i] / 16;
    }
    for (i = 0; i < num; i++) {
      data_size = file_size[i];
      tmp_data = (signed int *)mdl_data[i];
      mdl_cur_data = mdl_data[i];
      if (i == 0) {
        mdl_header = (ModelHeader *)mdl_data[i];
        coord = (signed int)mdl_header->coord;
        mdl_cur_data += coord * sizeof(sceVu0FVECTOR);
        data_size -= coord * sizeof(sceVu0FVECTOR);
      }
      mdl_header = (ModelHeader *)mdl_data[i];
      obj_max = mdl_header->nobj;
      for (obj_cnt = 0; obj_cnt < obj_max; obj_cnt++) {
        tmp_cur_data = tmp_data;
        tmp_cur_data += ((signed int)mdl_header->obj + obj_cnt) * 4;
        block_max = *tmp_cur_data;
        tmp_cur_data++;
        tmp_cur_data = tmp_data + (*tmp_cur_data * 4);
        for (block_cnt = 0; block_cnt < block_max; block_cnt++) {
          mode = 0;
          alpha = 0;
          size2 = tmp_cur_data[0];
          if (tmp_cur_data[1] & 0x20000) {
            mode = 1;
          }
          if (tmp_cur_data[1] & 0x10000) {
            alpha = 1;
          }
          prim_max = tmp_cur_data[2];
          if (mode == 0) {
            prim_data = (PrimData *)(tmp_cur_data + 9);
          } else {
            prim_data = (PrimData *)(tmp_cur_data + 8);
          }
          for (prim_cnt = 0; prim_cnt < prim_max; prim_cnt++) {
            tmp_prim_data = (signed int *)prim_data;
            if (alpha == 0) {
              now_tmp_text = now_text;
            } else {
              now_tmp_text = now_alpha_text;
            }
            tmp_prim_data[0] += now_tmp_text;
            prim_data++;
          }
          tmp_cur_data += 8;
          tmp_cur_data += size2 * 4;
        }
      }
      memcpy(data, mdl_cur_data, data_size);
      data += data_size;
      now_text += text_num[i];
      now_alpha_text += alpha_num[i];
    }
  }
  return ret_data;
}

void maCreateModelFree(unsigned char *mdl_data) { ulFree(mdl_data); }

// DWARF: 0x6864D
// Address: 0x15D4B0
// Size: 0x9C
void maSetModelMode( // Size: 0x50, DWARF: 0x61157
    ModelMode *mode) {
  model_mode.head = mode->head;
  model_mode.kid = mode->kid;
  sceVu0CopyVector(&model_mode.head_scale, mode->head_scale);
  sceVu0CopyVector(&model_mode.kid_scale, mode->kid_scale);
  sceVu0CopyVector(&model_mode.hand_scale, mode->hand_scale);
  sceVu0CopyVector(&model_mode.body_scale, mode->body_scale);
}

// DWARF: 0x6873B
// Address: 0x15D550
// Size: 0x160

void maGetModelScale(float *ret, signed int id) {
  ret[0] = ret[1] = ret[2] = 0.0f;
  ret[3] = 1.0f;
  switch (id) {
  case 0: // Body scale
    if ((model_mode.head) || (model_mode.kid)) {
      sceVu0CopyVector(ret, &model_mode.body_scale);
      return;
    }
    break;
  case 1: // Head Scale
    if (model_mode.kid) {
      sceVu0CopyVector(ret, &model_mode.kid_scale);
    }
    if (model_mode.head) {
      ret[0] += model_mode.head_scale[0];
      ret[1] += model_mode.head_scale[1];
      ret[2] += model_mode.head_scale[2];
      return;
    }
    break;
  case 2: // Hand Scale
    if (model_mode.kid) {
      sceVu0CopyVector(ret, &model_mode.hand_scale);
    }
    break;
  }
}

// DWARF: 0x6884B
// Address: 0x15D6B0
// Size: 0x20
void maSetModelScaleCancel(signed int flg) { model_mode.cancel = flg; }

// DWARF: 0x6892A
// Address: 0x15D6D0
// Size: 0x2A0
// Size: 0x90, DWARF: 0x60E91
Ctrl *maModelChangeInit(__int128 *mdl_data) {
  // Size: 0x20, DWARF: 0x60873
  ModelHeader *mhead; // r16
  signed int i;       // r17
  // Size: 0x90, DWARF: 0x60E91
  Ctrl *ret_data = 0; // r18

  ret_data = (Ctrl *)ulMalloc(0x90, 0, 0);
  ret_data->address = 0;
  ret_data->address2 = 0;
  mhead = (ModelHeader *)mdl_data;
  for (i = 0; i < mhead->ncoord; i++) {
    if (mhead->coord[i].id == 0x3E9) {
      ret_data->address = &mhead->coord[i].mat;
      sceVu0CopyMatrix(ret_data, mhead->coord[i].mat);
    }
    if (mhead->coord[i].id == 0x3EA) {
      ret_data->address2 = &mhead->coord[i].mat;
      sceVu0CopyMatrix(ret_data->original2, mhead->coord[i].mat);
      mhead->coord[i].mat[0][0] = 0.0f;
      mhead->coord[i].mat[0][1] = 0.0f;
      mhead->coord[i].mat[0][2] = 0.0f;
      mhead->coord[i].mat[0][3] = 0.0f;
      mhead->coord[i].mat[1][0] = 0.0f;
      mhead->coord[i].mat[1][1] = 0.0f;
      mhead->coord[i].mat[1][2] = 0.0f;
      mhead->coord[i].mat[1][3] = 0.0f;
      mhead->coord[i].mat[2][0] = 0.0f;
      mhead->coord[i].mat[2][1] = 0.0f;
      mhead->coord[i].mat[2][2] = 0.0f;
      mhead->coord[i].mat[2][3] = 0.0f;
    }
  }
  return ret_data;
}

// DWARF: 0x68ABA
// Address: 0x15D970
// Size: 0x24
void maSecMotionMode( // Size: 0x1A0, DWARF: 0x5FB16
    MotionCtrl *ctrl, signed int mode) {
  ctrl->type = mode;
}

// DWARF: 0x68BB7
// Address: 0x15D9A0
// Size: 0x3A4
void maModelChangeSet( // Size: 0x90, DWARF: 0x60E91
    Ctrl *ctrl, signed int mode) {
  if ((ctrl->address == 0) || (ctrl->address2 == 0)) {
    return;
  }
  switch (mode) {
  case 0:
    sceVu0CopyMatrix(ctrl->address, ctrl->original);
    (*ctrl->address2)[0][0] = 0.0f;
    (*ctrl->address2)[0][1] = 0.0f;
    (*ctrl->address2)[0][2] = 0.0f;
    (*ctrl->address2)[0][3] = 0.0f;
    (*ctrl->address2)[1][0] = 0.0f;
    (*ctrl->address2)[1][1] = 0.0f;
    (*ctrl->address2)[1][2] = 0.0f;
    (*ctrl->address2)[1][3] = 0.0f;
    (*ctrl->address2)[2][0] = 0.0f;
    (*ctrl->address2)[2][1] = 0.0f;
    (*ctrl->address2)[2][2] = 0.0f;
    (*ctrl->address2)[2][3] = 0.0f;
    return;
  case 1:
    sceVu0CopyMatrix(ctrl->address2, ctrl->original2);
    (*ctrl->address)[0][0] = 0.0f;
    (*ctrl->address)[0][1] = 0.0f;
    (*ctrl->address)[0][2] = 0.0f;
    (*ctrl->address)[0][3] = 0.0f;
    (*ctrl->address)[1][0] = 0.0f;
    (*ctrl->address)[1][1] = 0.0f;
    (*ctrl->address)[1][2] = 0.0f;
    (*ctrl->address)[1][3] = 0.0f;
    (*ctrl->address)[2][0] = 0.0f;
    (*ctrl->address)[2][1] = 0.0f;
    (*ctrl->address)[2][2] = 0.0f;
    (*ctrl->address)[2][3] = 0.0f;
    return;
  default:
    (*ctrl->address2)[0][0] = 0.0f;
    (*ctrl->address2)[0][1] = 0.0f;
    (*ctrl->address2)[0][2] = 0.0f;
    (*ctrl->address2)[0][3] = 0.0f;
    (*ctrl->address2)[1][0] = 0.0f;
    (*ctrl->address2)[1][1] = 0.0f;
    (*ctrl->address2)[1][2] = 0.0f;
    (*ctrl->address2)[1][3] = 0.0f;
    (*ctrl->address2)[2][0] = 0.0f;
    (*ctrl->address2)[2][1] = 0.0f;
    (*ctrl->address2)[2][2] = 0.0f;
    (*ctrl->address2)[2][3] = 0.0f;
    (*ctrl->address)[0][0] = 0.0f;
    (*ctrl->address)[0][1] = 0.0f;
    (*ctrl->address)[0][2] = 0.0f;
    (*ctrl->address)[0][3] = 0.0f;
    (*ctrl->address)[1][0] = 0.0f;
    (*ctrl->address)[1][1] = 0.0f;
    (*ctrl->address)[1][2] = 0.0f;
    (*ctrl->address)[1][3] = 0.0f;
    (*ctrl->address)[2][0] = 0.0f;
    (*ctrl->address)[2][1] = 0.0f;
    (*ctrl->address)[2][2] = 0.0f;
    (*ctrl->address)[2][3] = 0.0f;
    return;
  }
}

void maModelChangeInitEnd( // Size: 0x90, DWARF: 0x60E91
    Ctrl *ctrl /* 0x10(r29) */) {
  ulFree(ctrl);
}

