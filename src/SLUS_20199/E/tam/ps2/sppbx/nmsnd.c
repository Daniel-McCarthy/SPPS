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

// C function includes
float sqrtf(float a);
float atan2f(float y, float x);
float sinf(float a);

// nmsnd.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10, DWARF: 0x12A38D
typedef struct _sif_rpc_data
{
    void* paddr; // Offset: 0x0, DWARF: 0x12A3AF
    unsigned int pid; // Offset: 0x4, DWARF: 0x12A3D4
    signed int tid; // Offset: 0x8, DWARF: 0x12A3F4
    unsigned int mode; // Offset: 0xC, DWARF: 0x12A414
} _sif_rpc_data;

// Size: 0x28, DWARF: 0x1291A3
typedef struct _sif_client_data
{
    _sif_rpc_data rpcd; // Offset: 0x0, DWARF: 0x1291C8
    unsigned int command; // Offset: 0x10, DWARF: 0x1291EB
    void* buff; // Offset: 0x14, DWARF: 0x12920F
    void* cbuff; // Offset: 0x18, DWARF: 0x129233
    void(*func)(void*); // Offset: 0x1C, DWARF: 0x129258
    void* para; // Offset: 0x20, DWARF: 0x12927E
    struct _sif_serve_data* serve; // Offset: 0x24, DWARF: 0x1292A2
} _sif_client_data;

// Size: 0x18, DWARF: 0x129667
typedef struct _sif_queue_data
{
    signed int key; // Offset: 0x0, DWARF: 0x12968B
    signed int active; // Offset: 0x4, DWARF: 0x1296AB
    struct _sif_serve_data* link; // Offset: 0x8, DWARF: 0x1296CE
    struct _sif_serve_data* start; // Offset: 0xC, DWARF: 0x1296F4
    struct _sif_serve_data* end; // Offset: 0x10, DWARF: 0x12971B
    struct _sif_queue_data* next; // Offset: 0x14, DWARF: 0x129740
} _sif_queue_data;

// Size: 0x44, DWARF: 0x12885D
typedef struct _sif_serve_data
{
    unsigned int command; // Offset: 0x0, DWARF: 0x128881
    void*(*func)(unsigned int, void*, signed int); // Offset: 0x4, DWARF: 0x1288A5
    void* buff; // Offset: 0x8, DWARF: 0x1288CB
    signed int size; // Offset: 0xC, DWARF: 0x1288EF
    void*(*cfunc)(unsigned int, void*, signed int); // Offset: 0x10, DWARF: 0x128910
    void* cbuff; // Offset: 0x14, DWARF: 0x128937
    signed int csize; // Offset: 0x18, DWARF: 0x12895C
    _sif_client_data* client; // Offset: 0x1C, DWARF: 0x12897E
    void* paddr; // Offset: 0x20, DWARF: 0x1289A6
    unsigned int fno; // Offset: 0x24, DWARF: 0x1289CB
    void* receive; // Offset: 0x28, DWARF: 0x1289EB
    signed int rsize; // Offset: 0x2C, DWARF: 0x128A12
    signed int rmode; // Offset: 0x30, DWARF: 0x128A34
    unsigned int rid; // Offset: 0x34, DWARF: 0x128A56
    struct _sif_serve_data* link; // Offset: 0x38, DWARF: 0x128A76
    struct _sif_serve_data* next; // Offset: 0x3C, DWARF: 0x128A9C
    _sif_queue_data* base; // Offset: 0x40, DWARF: 0x128AC2
} _sif_serve_data;

// Size: 0x10, DWARF: 0x129DA0
typedef struct Bgm
{
    signed int read_type; // Offset: 0x0, DWARF: 0x129DBC
    signed int max_vol; // Offset: 0x4, DWARF: 0x129DE2
    signed int res[2]; // Offset: 0x8, DWARF: 0x129E06
} Bgm;

// Size: 0x10, DWARF: 0x12A60A
typedef struct Voice
{
    signed int max_vol; // Offset: 0x0, DWARF: 0x12A626
    signed int mix; // Offset: 0x4, DWARF: 0x12A64A
    signed int chan_num; // Offset: 0x8, DWARF: 0x12A66A
    signed int res; // Offset: 0xC, DWARF: 0x12A68F
} Voice;

// Size: 0x10, DWARF: 0x12913A
typedef struct Synth
{
    unsigned int voice_res[2]; // Offset: 0x0, DWARF: 0x129155
    signed int res[2]; // Offset: 0x8, DWARF: 0x12917D
} Synth;

// Size: 0x40, DWARF: 0x129E2C
typedef struct VnmsndInit
{
    // Size: 0x10, DWARF: 0x129DA0
    Bgm bgm; // Offset: 0x0, DWARF: 0x129E48
    // Size: 0x10, DWARF: 0x12A60A
    Voice voice; // Offset: 0x10, DWARF: 0x129E6A
    // Size: 0x10, DWARF: 0x12913A
    Synth synth; // Offset: 0x20, DWARF: 0x129E8E
    signed int debug; // Offset: 0x30, DWARF: 0x129EB2
    signed int res[3]; // Offset: 0x34, DWARF: 0x129ED4
} VnmsndInit;

// Size: 0x20, DWARF: 0x12A233
typedef struct VnmbgmResult
{
    signed int state; // Offset: 0x0, DWARF: 0x12A24F
    signed short select_num; // Offset: 0x4, DWARF: 0x12A271
    signed short select_tbl; // Offset: 0x6, DWARF: 0x12A298
    signed int fade; // Offset: 0x8, DWARF: 0x12A2BF
    signed short retry; // Offset: 0xC, DWARF: 0x12A2E0
    signed short tray; // Offset: 0xE, DWARF: 0x12A302
    signed int batch; // Offset: 0x10, DWARF: 0x12A323
    signed int vol; // Offset: 0x14, DWARF: 0x12A345
    signed int level[2]; // Offset: 0x18, DWARF: 0x12A365
} VnmbgmResult;

// Size: 0x30, DWARF: 0x128D77
typedef struct Voice_Result
{
    char state[32]; // Offset: 0x0, DWARF: 0x128D92
    signed int batch; // Offset: 0x20, DWARF: 0x128DB6
    signed int data_state; // Offset: 0x24, DWARF: 0x128DD8
    signed int res[2]; // Offset: 0x28, DWARF: 0x128DFF
} Voice_Result;

// Size: 0x20, DWARF: 0x12939B
typedef struct Synth_Result
{
    signed int batch; // Offset: 0x0, DWARF: 0x1293B6
    signed int midi_state[2]; // Offset: 0x4, DWARF: 0x1293D8
    signed int sesq_state[2]; // Offset: 0xC, DWARF: 0x129401
    signed int wave_state; // Offset: 0x14, DWARF: 0x12942A
    signed int res[2]; // Offset: 0x18, DWARF: 0x129451
} Synth_Result;

// Size: 0x78, DWARF: 0x129591
typedef struct VnmsndResult
{
    // Size: 0x20, DWARF: 0x12A233
    VnmbgmResult bgm; // Offset: 0x0, DWARF: 0x1295AD
    // Size: 0x30, DWARF: 0x128D77
    Voice_Result voice; // Offset: 0x20, DWARF: 0x1295CF
    // Size: 0x20, DWARF: 0x12939B
    Synth_Result synth; // Offset: 0x50, DWARF: 0x1295F3
    unsigned int end_point[2]; // Offset: 0x70, DWARF: 0x129617
} VnmsndResult;

// Size: 0x10, DWARF: 0x129A55
typedef struct Snd_Data
{
    signed int com; // Offset: 0x0, DWARF: 0x129A71
    signed int data[3]; // Offset: 0x4, DWARF: 0x129A91
} Snd_Data;

// Size: 0x710, DWARF: 0x12A083
typedef struct VnmsndFrame
{
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data bgm[16]; // Offset: 0x0, DWARF: 0x12A09F
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data voice[64]; // Offset: 0x100, DWARF: 0x12A0C1
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data synth[32]; // Offset: 0x500, DWARF: 0x12A0E5
    signed int bgm_num; // Offset: 0x700, DWARF: 0x12A109
    signed int voice_num; // Offset: 0x704, DWARF: 0x12A12D
    signed int synth_num; // Offset: 0x708, DWARF: 0x12A153
    signed int res; // Offset: 0x70C, DWARF: 0x12A179
} VnmsndFrame;

// Size: 0x4, DWARF: 0x129F42
typedef struct CourseNo
{
    signed int no; // Offset: 0x0, DWARF: 0x129F5E
} CourseNo;

// Size: 0x1C, DWARF: 0x12993F
typedef struct Chr_Param
{
    signed int ollie; // Offset: 0x0, DWARF: 0x12995B
    signed int spin; // Offset: 0x4, DWARF: 0x12997D
    signed int speed; // Offset: 0x8, DWARF: 0x12999E
    signed int landing; // Offset: 0xC, DWARF: 0x1299C0
    signed int balance; // Offset: 0x10, DWARF: 0x1299E4
    signed int stability; // Offset: 0x14, DWARF: 0x129A08
    signed int stance; // Offset: 0x18, DWARF: 0x129A2E
} Chr_Param;

// Size: 0x10, DWARF: 0x129BFB
typedef struct Brd_Param
{
    signed int speed; // Offset: 0x0, DWARF: 0x129C17
    signed int stability; // Offset: 0x4, DWARF: 0x129C39
    signed int balance; // Offset: 0x8, DWARF: 0x129C5F
    signed int turning; // Offset: 0xC, DWARF: 0x129C83
} Brd_Param;

// Size: 0x3C, DWARF: 0x129CAB
typedef struct Character
{
    signed int no; // Offset: 0x0, DWARF: 0x129CC7
    signed int player; // Offset: 0x4, DWARF: 0x129CE6
    signed int wear; // Offset: 0x8, DWARF: 0x129D09
    signed int board; // Offset: 0xC, DWARF: 0x129D2A
    // Size: 0x1C, DWARF: 0x12993F
    Chr_Param chr_param; // Offset: 0x10, DWARF: 0x129D4C
    // Size: 0x10, DWARF: 0x129BFB
    Brd_Param brd_param; // Offset: 0x2C, DWARF: 0x129D74
} Character;

// Size: 0x18, DWARF: 0x129F81
typedef struct Mode
{
    signed int num_player; // Offset: 0x0, DWARF: 0x129F9D
    signed int game_mode; // Offset: 0x4, DWARF: 0x129FC4
    signed int match_rule; // Offset: 0x8, DWARF: 0x129FEA
    signed int divide; // Offset: 0xC, DWARF: 0x12A011
    signed int handicap[2]; // Offset: 0x10, DWARF: 0x12A034
} Mode;

// Size: 0xA0, DWARF: 0x129B00
typedef struct VspenvGame
{
    // Size: 0x4, DWARF: 0x129F42
    CourseNo course; // Offset: 0x0, DWARF: 0x129B1C
    // Size: 0x3C, DWARF: 0x129CAB
    Character character[2]; // Offset: 0x4, DWARF: 0x129B41
    // Size: 0x18, DWARF: 0x129F81
    Mode mode; // Offset: 0x7C, DWARF: 0x129B69
    signed int language; // Offset: 0x94, DWARF: 0x129B8C
    signed int ending; // Offset: 0x98, DWARF: 0x129BB1
    signed int bgm_no; // Offset: 0x9C, DWARF: 0x129BD4
} VspenvGame;

// Size: 0x24, DWARF: 0x128AEC
typedef struct Key_Config
{
    signed int vibration; // Offset: 0x0, DWARF: 0x128B07
    signed int spin_l; // Offset: 0x4, DWARF: 0x128B2D
    signed int spin_r; // Offset: 0x8, DWARF: 0x128B50
    signed int stance; // Offset: 0xC, DWARF: 0x128B73
    signed int revert; // Offset: 0x10, DWARF: 0x128B96
    signed int grind; // Offset: 0x14, DWARF: 0x128BB9
    signed int grab; // Offset: 0x18, DWARF: 0x128BDB
    signed int jump; // Offset: 0x1C, DWARF: 0x128BFC
    signed int flip; // Offset: 0x20, DWARF: 0x128C1D
} Key_Config;

// Size: 0x30, DWARF: 0x128E93
typedef struct Cheats
{
    signed int kids; // Offset: 0x0, DWARF: 0x128EAE
    signed int always_sp; // Offset: 0x4, DWARF: 0x128ECF
    signed int perfect_b; // Offset: 0x8, DWARF: 0x128EF5
    signed int super_spin; // Offset: 0xC, DWARF: 0x128F1B
    signed int half_g; // Offset: 0x10, DWARF: 0x128F42
    signed int fast_motion; // Offset: 0x14, DWARF: 0x128F65
    signed int super_speed; // Offset: 0x18, DWARF: 0x128F8D
    signed int big_head; // Offset: 0x1C, DWARF: 0x128FB5
    signed int metallic; // Offset: 0x20, DWARF: 0x128FDA
    signed int mirror; // Offset: 0x24, DWARF: 0x128FFF
    signed int replay_view; // Offset: 0x28, DWARF: 0x129022
    signed int partition; // Offset: 0x2C, DWARF: 0x12904A
} Cheats;

// Size: 0x8, DWARF: 0x128D19
typedef struct Volume
{
    signed int se; // Offset: 0x0, DWARF: 0x128D34
    signed int bgm; // Offset: 0x4, DWARF: 0x128D53
} Volume;

// Size: 0x48, DWARF: 0x1294E3
typedef struct Bgm_Option
{
    signed int table[16]; // Offset: 0x0, DWARF: 0x1294FE
    signed int disable; // Offset: 0x40, DWARF: 0x129522
    signed int random; // Offset: 0x44, DWARF: 0x129546
} Bgm_Option;

// Size: 0x114, DWARF: 0x12978E
typedef struct VspenvOption
{
    // Size: 0x24, DWARF: 0x128AEC
    Key_Config key_config[2]; // Offset: 0x0, DWARF: 0x1297AA
    // Size: 0x30, DWARF: 0x128E93
    Cheats enable; // Offset: 0x48, DWARF: 0x1297D3
    // Size: 0x30, DWARF: 0x128E93
    Cheats cheats; // Offset: 0x78, DWARF: 0x1297F8
    // Size: 0x8, DWARF: 0x128D19
    Volume volume; // Offset: 0xA8, DWARF: 0x12981D
    char name[16]; // Offset: 0xB0, DWARF: 0x129842
    signed int divide; // Offset: 0xC0, DWARF: 0x129865
    signed int tutorial; // Offset: 0xC4, DWARF: 0x129888
    // Size: 0x48, DWARF: 0x1294E3
    Bgm_Option bgm; // Offset: 0xC8, DWARF: 0x1298AD
    unsigned int movie; // Offset: 0x110, DWARF: 0x1298CF
} VspenvOption;

// Size: 0x10, DWARF: 0x129098
typedef struct Send
{
    unsigned int com; // Offset: 0x0, DWARF: 0x1290B3
    signed int wait; // Offset: 0x4, DWARF: 0x1290D3
    signed int data; // Offset: 0x8, DWARF: 0x1290F4
    signed int size; // Offset: 0xC, DWARF: 0x129115
} Send;

// Size: 0x10, DWARF: 0x129315
typedef struct Rec
{
    void* addr; // Offset: 0x0, DWARF: 0x129330
    signed int size; // Offset: 0x4, DWARF: 0x129354
    signed int res[2]; // Offset: 0x8, DWARF: 0x129375
} Rec;

// Size: 0x30, DWARF: 0x128C42
typedef struct Pub
{
    // Size: 0x10, DWARF: 0x129098
    Send send; // Offset: 0x0, DWARF: 0x128C5D
    // Size: 0x10, DWARF: 0x129315
    Rec rec; // Offset: 0x10, DWARF: 0x128C80
    void* end_func; // Offset: 0x20, DWARF: 0x128CA2
    void* end_param; // Offset: 0x24, DWARF: 0x128CCA
    signed int res[2]; // Offset: 0x28, DWARF: 0x128CF3
} Pub;

// Size: 0x14, DWARF: 0x12A4CE
typedef struct Attr
{
    signed int core; // Offset: 0x0, DWARF: 0x12A4EA
    signed int mode; // Offset: 0x4, DWARF: 0x12A50B
    signed short depth_L; // Offset: 0x8, DWARF: 0x12A52C
    signed short depth_R; // Offset: 0xA, DWARF: 0x12A550
    signed int delay; // Offset: 0xC, DWARF: 0x12A574
    signed int feedback; // Offset: 0x10, DWARF: 0x12A596
} Attr;

// Size: 0x8, DWARF: 0x12A6B3
typedef struct Vol
{
    signed int left; // Offset: 0x0, DWARF: 0x12A6CF
    signed int right; // Offset: 0x4, DWARF: 0x12A6F0
} Vol;

//// Function Declarations ///////////////////////////////////////////////////////////

int sceSifCheckStatRpc(_sif_client_data* cd);
int sceSifCallRpc(_sif_client_data* bd, unsigned int fno, unsigned int mode, void* send, int ssize,
                  void* receive, int rsize, void(*end_func)(void*), void* end_para);
void* memcpy(void* dst, const void* src, unsigned int len);
void scePrintf(const char* fmt, ...);

signed int nmsndInit();
signed int nmsndFrame(signed int pause);
signed int nmsndRestart(signed int fade);
signed int nmsndStartGame();
signed int nmsndStartDemo();
signed int nmsndEndGame();
signed int nmsndExit(signed int fade);
signed int nmsndExitSel(signed int fade);
signed int nmsndCheckExit();
signed int nmsndResetWave();
signed int nmsndAssignChan(signed int num);
// Size: 0x10, DWARF: 0x129A55
signed int nmsndEntryBatch(signed int type, Snd_Data* batch);
// Size: 0x30, DWARF: 0x128C42
signed int nmsndPubCom(Pub* pub);
signed int nmsndGetChanState(signed int core);
static signed int nmsndInitMod();
static void nmsndEndPub(void* data);

// Other C Includes
// Size: 0x8, DWARF: 0x1F59B
void ulsdSetOutSideVol(signed int core, signed int mode, Vol vol);
void ulsdSetEffectReturnVol(signed int core, signed int mode, Vol vol);
void ulsdSetMasterVol(signed int core, signed int mode, Vol vol);
void ulsdSetMixAft(signed int core, signed int mode, signed int flag);

// Size: 0x10, DWARF: 0x12BE87
signed int nmbgmInit(Bgm* init);
// Size: 0x710 / 0x20
signed int nmbgmFrame(VnmsndFrame* vnmsndFrame, VnmbgmResult* result, signed int pause);
signed int nmbgmSetTbl();
signed int nmbgmSelect(signed int num, signed int tbl);
signed int nmbgmSetSelectTbl(volatile signed int* tbl, signed int skip);
signed int nmbgmReset();
signed int nmbgmSetExterVol(signed int vol);
void nmbgmSetOptNext(signed int next);
void nmbgmSetOptRand(signed int rand);
signed int nmbgmChangeOption();
signed int nmbgmPlay();
signed int nmbgmStop(signed int fade);
signed int nmbgmPause();
signed int nmbgmResume();
signed int nmbgmChange(signed int fade, signed int num, signed int tbl);
signed int nmbgmChange2(signed int fade, signed int num, signed int tbl);
signed int nmbgmExit(signed int fade);
signed int nmbgmGetState();
signed int nmbgmGetLevel(signed int dir);
signed int nmbgmGetSelect();
signed int nmbgmGetSelectTbl();
signed int nmbgmCheckQue();

//// Variables ///////////////////////////////////////////////////////////////////////

// bss is emitted in reverse declaration order, so these descend.

_sif_client_data vnmsndCd; // Address: 0x3C27C0
unsigned int vnmsndRpcBuf[512]; // Address: 0x3C1FC0
// Size: 0x40, DWARF: 0x129E2C
VnmsndInit vnmsndInit; // Address: 0x3C1F80
// Size: 0x710, DWARF: 0x12A083
VnmsndFrame vnmsndFrame; // Address: 0x3C1840
// Size: 0x710, DWARF: 0x12A083
VnmsndFrame vnmsndFrameSend; // Address: 0x3C1100
// Size: 0x78, DWARF: 0x129591
VnmsndResult vnmsndResult; // Address: 0x3C1080

// Size: 0xA0, DWARF: 0x129B00
extern VspenvGame* vspenvGame; // Address: 0x2E7B14
// Size: 0x114, DWARF: 0x12978E
extern VspenvOption* vspenvOption; // Address: 0x2E7B10

//// Function Definitions ////////////////////////////////////////////////

s32 nmsndInit(void) {
    signed int i; // r16 // s0
    signed int tmp; // r17 // s1
    // Size: 0x14, DWARF: 0x12A4CE
    Attr attr; // 0x40(r29)
    // Size: 0x8, DWARF: 0x12A6B3
    Vol vol; // 0x58(r29)

    vol.left = 0x7FFF;
    vol.right = 0x7FFF;
    ulsdSetOutSideVol(1, 1, vol);
    for (i = 0; i < 2; i++) {
        ulsdSetEffectEndAddr(i, 1, 0x1FFFFF - (i * 0xADE0));
        attr.mode = 0x100;
        attr.depth_L = 0;
        attr.depth_R = 0;
        attr.delay = 0;
        attr.feedback = 0;
        ulsdSetEffectAttr(i, &attr);
        ulsdSetEffectEnable(i, 1, 1);
        vol.left = 0x2FFF;
        vol.right = 0x2FFF;
        ulsdSetEffectReturnVol(i, 1, vol);
        vol.left = 0x3FFF;
        vol.right = 0x3FFF;
        ulsdSetMasterVol(i, 1, vol);
    }
    tmp = 0xFF0;
    ulsdSetMixAft(0, 1, tmp);
    tmp = 0xFFF;
    ulsdSetMixAft(1, 1, tmp);
    tmp = nmbgmInit(&vnmsndInit);
    if (tmp == -1) {
        scePrintf("nmbgmInit Error\n" /*@30*/);
        return -1;
    }
    tmp = nmvcInit(&vnmsndInit.voice);
    if (tmp == -1) {
        scePrintf("nmvcInit Error\n" /*@31*/);
        return -1;
    }
    tmp = nmsqInit(&vnmsndInit.synth);
    if (tmp == -1) {
        scePrintf("nmvcInit Error\n" /*@31*/);
        return -1;
    }
    vnmsndInit.debug = 0;
    tmp = nmsndInitMod();
    if (tmp == -1) {
        scePrintf("nmsndInitMod Error\n" /*@32*/);
        return -1;
    }
    tmp = nmbgmSetTbl();
    if (tmp == -1) {
        scePrintf("nmbgmSetTbl Error\n" /*@33*/);
        return -1;
    }
    return 0;
}

s32 nmsndFrame(signed int pause /*sp50*/) {
    signed int tmp; // r16
    // Size: 0x30, DWARF: 0x128C42
    Pub pub; // 0x20(r29)

    if (sceSifCheckStatRpc(&vnmsndCd) == 0) {
        pub.send.com = 0xD020;
        pub.send.wait = 0;
        pub.send.data = (s32)&vnmsndFrameSend.bgm;
        pub.send.size = 0x710;
        pub.rec.addr = &vnmsndResult;
        pub.rec.size = 0x78;
        pub.end_func = &nmsndEndPub;
        pub.end_param = &vnmsndResult;
        tmp = nmsndPubCom(&pub);
        if (tmp == -1) {
            scePrintf("nmsndPubCom Error(%x)\n" /*@49*/, 0xD020);
            return -1;
        }
    }
    tmp = nmbgmFrame(&vnmsndFrame, &vnmsndResult.bgm, pause);
    if (tmp == -1) {
        scePrintf("nmbgmFrame Error\n" /*@64*/);
        return -1;
    }
    tmp = nmvcFrame(&vnmsndFrame, &vnmsndResult.voice, pause);
    if (tmp == -1) {
        scePrintf("nmvcFrame Error\n" /*@65*/);
        return -1;
    }
    tmp = nmsqFrame(&vnmsndFrame, &vnmsndResult.synth, pause);
    if (tmp == -1) {
        scePrintf("nmsqFrame Error\n" /*@66*/);
        return -1;
    }
    return 0;
}

s32 nmsndRestart(signed int fade) {
    signed int tmp; // r16

    if (nmbgmGetSelect() >= 0) {
        tmp = nmbgmGetState();
        if (tmp == 3) {
            tmp = nmbgmStop(0);
        } else {
            tmp = nmbgmStop(fade);
        }
        if (tmp == -1) {
            scePrintf("nmbgmStop Error\n" /*@86*/);
            return -1;
        }
    }
    tmp = nmvcStopVoice();
    if (tmp == -1) {
        scePrintf("nmvcStopVoice Error\n" /*@87*/);
        return -1;
    }
    tmp = nmvcStopAct();
    if (tmp == -1) {
        scePrintf("nmvcStopAct Error\n" /*@88*/);
        return -1;
    }
    tmp = nmvcStopEvent();
    if (tmp == -1) {
        scePrintf("nmvcStopEvent Error\n" /*@89*/);
        return -1;
    }
    tmp = nmvcStopEffect();
    if (tmp == -1) {
        scePrintf("nmvcStopEffect Error\n" /*@90*/);
        return -1;
    }
    return 0;
}

s32 nmsndStartGame(void) {
    signed int select; // r16
    signed int tmp; // r17

    if (vspenvOption->bgm.disable != -1) {
        nmbgmSetOptNext(1);
        tmp = nmbgmChangeOption();
        select = nmbgmGetSelect();
        if (select < 0) {
            if (vspenvGame->bgm_no < 0) {
                if (vspenvOption->bgm.random == 1) {
                    while (1) {
                        select = rand() % 12;
                        if ((vspenvOption->bgm.disable & (1 << select)) == 0) {
                            break;
                        }
                    }
                } else {
                    select = 0;
                    while (1) {
                        if ((vspenvOption->bgm.disable & (1 << select)) == 0) {
                            break;
                        }
                        select += 1;
                    }
                }
                tmp = nmbgmSelect(select, 1);
                tmp = nmbgmPlay();
            } else {
                tmp = nmbgmChange2(0, vspenvGame->bgm_no, 1);
            }
        } else if (select >= 0xC) {
            tmp = nmbgmChange2(0, vspenvGame->bgm_no, 1);
        } else {
            tmp = nmbgmPlay();
        }
    }
    return 0;
}

s32 nmsndStartDemo(void) {
    signed int i; // r16
    signed int tmp; // r17
    signed int skip; // r18
    signed int table[16]; // 0x40(r29)

    for (i = 0; i < 0x10; i++) {
        table[i] = i;
    }
    skip = -1;
    for (i = 0; i < 0xC; i++) {
        skip ^= 1 << i;
    }
    nmbgmSetSelectTbl(table, skip);
    nmbgmSetOptNext(1);
    nmbgmSetOptRand(1);
    tmp = nmbgmChangeOption();
    tmp = nmbgmGetSelect();
    if (tmp < 0) {
        tmp = rand() % 12;
        tmp = nmbgmSelect(tmp, 1);
        tmp = nmbgmPlay();
    } else {
        tmp = nmbgmChange2(0, -1, 1);
    }
    return 0;
}

s32 nmsndEndGame(void) {
    signed int tmp; // r16
    tmp = nmvcStopVoice();
    if (tmp == -1) {
        scePrintf("nmbgmStop Error\n" /*@86*/);
        return -1;
    }
    tmp = nmvcStopAct();
    if (tmp == -1) {
        scePrintf("nmbgmStop Error\n" /*@86*/);
        return -1;
    }
    tmp = nmvcStopEvent();
    if (tmp == -1) {
        scePrintf("nmbgmStop Error\n" /*@86*/);
        return -1;
    }
    tmp = nmvcStopEffect();
    if (tmp == -1) {
        scePrintf("nmbgmStop Error\n" /*@86*/);
        return -1;
    }
    return 0;
}

s32 nmsndExit(signed int fade) {
    signed int tmp; // r16
    tmp = nmbgmExit(fade);
    if (tmp == -1) {
        scePrintf("nmbgmExit Error\n" /*@156*/);
        return -1;
    }
    return 0;
}

s32 nmsndExitSel(signed int fade) {
    signed int tmp; // r16
    tmp = nmsqExitSelect(fade);
    if (tmp == -1) {
        scePrintf("nmsqExitSelect Error\n" /*@165*/);
        return -1;
    }
    tmp = nmsndResetWave();
    if (tmp == -1) {
        scePrintf("nmsndResetWave Error\n" /*@166*/);
        return -1;
    }
    return 0;
}

s32 nmsndCheckExit(void) {
    signed int tmp; // r16
    tmp = nmbgmCheckQue();
    if (tmp) {
        return -1;
    }
    tmp = nmsqCheckQue();
    if (tmp) {
        return -1;
    }
    tmp = nmvcCheckAllStop();
    if (tmp) {
        return -1;
    }
    tmp = nmvcResetData();
    if (tmp == -1) {
        scePrintf("nmvcResetData Error\n" /*@181*/);
        return -1;
    }
    tmp = nmsndResetWave();
    if (tmp == -1) {
        scePrintf("nmsndResetWave Error\n" /*@166*/);
        return -1;
    }
    return 0;
}

s32 nmsndResetWave(void) {
    signed int tmp; // r16
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data batch; // 0x20(r29)

    batch.com = 0x8232;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@188*/);
        return -1;
    }
    return 0;
}

s32 nmsndAssignChan(signed int num /*sp70*/) {
    signed int i; // r16
    signed int core; // r17
    signed int chan; // r18
    signed int tmp; // r19
    // Size: 0x10, DWARF: 0x129A55
    Snd_Data batch; // 0x50(r29)
    signed int res[2]; // 0x68(r29)

    batch.com = 0x243;
    batch.data[0] = num;
    tmp = nmsndEntryBatch(0x200, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@188*/);
        return -1;
    }
    res[0] = 0;
    res[1] = 0;
    for (i = 0; i < num; i++) {
        core = (i / 24);
        chan = (i % 24);
        res[core] = (s32) ((1 << chan) | res[core]);
    }
    batch.com = 0x8333;
    batch.data[0] = res[0];
    batch.data[1] = res[1];
    tmp = nmsndEntryBatch(0x300, &batch);
    if (tmp == -1) {
        scePrintf("nmsndEntryBatch Error\n" /*@188*/);
        return -1;
    }
    return 0;
}

s32 nmsndEntryBatch(signed int type, // Size: 0x10, DWARF: 0x129A55
Snd_Data* batch) {
    switch (type) {
    case 0x100:
        if (vnmsndFrame.bgm_num < 0x10) {
            memcpy(&vnmsndFrame.bgm[vnmsndFrame.bgm_num], batch, 0x10);
            vnmsndFrame.bgm_num++;
            break;
        }
        scePrintf("Bgm batch over\n" /*@225*/);
        return -1;
    case 0x200:
        if (vnmsndFrame.voice_num < 0x40) {
            memcpy(&vnmsndFrame.voice[vnmsndFrame.voice_num], batch, 0x10);
            vnmsndFrame.voice_num++;
            break;
        }
        scePrintf("Voice batch over\n" /*@226*/);
        return -1;
    case 0x300:
        if (vnmsndFrame.synth_num < 0x20) {
            memcpy(&vnmsndFrame.synth[vnmsndFrame.synth_num], batch, 0x10);
            vnmsndFrame.synth_num++;
            break;
        }
        scePrintf("Synth batch over\n" /*@227*/);
        return -1;
    }
    return 0;
}

signed int nmsndPubCom(Pub* pub /* 0x40(r29) */) {
    signed int tmp; // r16
    signed int mode; // r17

    if (sceSifCheckStatRpc(&vnmsndCd)) {
        return 1;
    }
    if (pub->send.wait == 1) {
        mode = 0;
    } else {
        mode = 1;
    }
    if (pub->send.com & 0x1000) {
        tmp = sceSifCallRpc(&vnmsndCd, pub->send.com, mode, (void*)pub->send.data, pub->send.size, vnmsndRpcBuf, pub->rec.size, pub->end_func, pub->end_param);
    } else {
        vnmsndRpcBuf[0] = pub->send.data;
        tmp = sceSifCallRpc(&vnmsndCd, pub->send.com, mode, vnmsndRpcBuf, 0x10, vnmsndRpcBuf, pub->rec.size, pub->end_func, pub->end_param);
    }
    if (tmp < 0) {
        scePrintf("sceSifCallRpc Error(%x)\n" /*@247*/, pub->send.com);
        return -1;
    }
    if (pub->send.com & 0x4000) {
        memcpy(pub->rec.addr, vnmsndRpcBuf, pub->rec.size);
    }
    if (tmp == 1) {
        return -1;
    }
    return 0;
}

s32 nmsndGetChanState(signed int core) {
    return vnmsndResult.end_point[core];
}

static s32 nmsndInitMod(void) {
    signed int i; // r16
    signed int tmp; // r17
    // Size: 0x30, DWARF: 0x128C42
    Pub pub; // 0x30(r29)

    sceSifInitRpc(0);
    do {
        tmp = sceSifBindRpc(&vnmsndCd, 0x12345, 0);
        if (tmp < 0) {
            scePrintf("sceSifBindRpc Error\n" /*@272*/);
        }
        i = 0;
        do {
            i++;
        } while (0x2710 >= i);
    } while (vnmsndCd.serve == 0);
    pub.send.com = 0x9000;
    pub.send.wait = 1;
    pub.send.data = (int)&vnmsndInit;
    pub.send.size = 0x40;
    pub.rec.addr = 0;
    pub.rec.size = 4;
    pub.end_func = 0;
    pub.end_param = 0;
    tmp = nmsndPubCom(&pub.send.com);
    if (tmp == -1) {
        scePrintf("nmsndPubCom Error(%x)\n" /*@49*/, 0x9000);
        return -1;
    }
    return 0;
}

static void nmsndEndPub(void* data /* 0x30(r29) */) {
    signed int i; // r16
    // Size: 0x78, DWARF: 0x129591
    VnmsndResult* result = data; // r17

    if (result->bgm.batch == 0) {
        for (i = 0; i < vnmsndFrame.bgm_num; i++) {
            memcpy(&vnmsndFrameSend.bgm[i], &vnmsndFrame.bgm[i], 0x10);
        }
        vnmsndFrameSend.bgm_num = vnmsndFrame.bgm_num;
        vnmsndFrame.bgm_num = 0;
    }
    if (result->voice.batch == 0) {
        for (i = 0; i < vnmsndFrame.voice_num; i++) {
            memcpy(&vnmsndFrameSend.voice[i], &vnmsndFrame.voice[i], 0x10);
        }
        vnmsndFrameSend.voice_num = vnmsndFrame.voice_num;
        vnmsndFrame.voice_num = 0;
    }
    if (result->synth.batch == 0) {
        for (i = 0; i < vnmsndFrame.synth_num; i++) {
            memcpy(&vnmsndFrameSend.synth[i], &vnmsndFrame.synth[i], 0x10);
        }
        vnmsndFrameSend.synth_num = vnmsndFrame.synth_num;
        vnmsndFrame.synth_num = 0;
    }
}
