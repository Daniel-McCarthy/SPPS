// mcard.c context
// Last updated 11/4/2024
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
#pragma divbyzerocheck on // Allows generation of break instructions on division by variables that risk div by 0.

// SCE types /////////////////////////////////////////////////////////////////////////
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef int sceVu0IMATRIX[4][4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));


// Static data ////////////////////////////////////////////////////////////////////////

char d132[] = "%s";
char d282[] = "*";

// mcard.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x20, DWARF: 0x1419E
typedef struct Info
{
    signed int type; // Offset: 0x0, DWARF: 0x141B9
    signed int format; // Offset: 0x4, DWARF: 0x141DA
    signed int capa; // Offset: 0x8, DWARF: 0x141FD
    signed int result; // Offset: 0xC, DWARF: 0x1421E
    signed int fnum; // Offset: 0x10, DWARF: 0x14241
    signed int res[3]; // Offset: 0x14, DWARF: 0x14262
} Info;

// Size: 0x8, DWARF: 0x14CDC, 0x14DE1
typedef struct Date
{
    unsigned char Resv2; // Offset: 0x0, DWARF: 0x14CF7
    unsigned char Sec; // Offset: 0x1, DWARF: 0x14D19
    unsigned char Min; // Offset: 0x2, DWARF: 0x14D39
    unsigned char Hour; // Offset: 0x3, DWARF: 0x14D59
    unsigned char Day; // Offset: 0x4, DWARF: 0x14D7A
    unsigned char Month; // Offset: 0x5, DWARF: 0x14D9A
    unsigned short Year; // Offset: 0x6, DWARF: 0x14DBC
} Date;

// Size: 0x40, DWARF: 0x144E0
typedef struct Table
{
    // Size: 0x8, DWARF: 0x14CDC
    Date _Create; // Offset: 0x0, DWARF: 0x144FB
    // Size: 0x8, DWARF: 0x14DE1
    Date _Modify; // Offset: 0x8, DWARF: 0x14521
    unsigned int FileSizeByte; // Offset: 0x10, DWARF: 0x14547
    unsigned short AttrFile; // Offset: 0x14, DWARF: 0x14570
    unsigned short Reserve1; // Offset: 0x16, DWARF: 0x14595
    unsigned int Reserve2; // Offset: 0x18, DWARF: 0x145BA
    unsigned int PdaAplNo; // Offset: 0x1C, DWARF: 0x145DF
    unsigned char EntryName[32]; // Offset: 0x20, DWARF: 0x14604
} Table;

// Size: 0x140, DWARF: 0x14941
typedef struct VulmcCardData
{
    // Size: 0x20, DWARF: 0x1419E
    Info info; // Offset: 0x0, DWARF: 0x1495C
    char name[64]; // Offset: 0x20, DWARF: 0x1497F
    char rename[64]; // Offset: 0x60, DWARF: 0x149A2
    signed int mode; // Offset: 0xA0, DWARF: 0x149C7
    signed int* openfd; // Offset: 0xA4, DWARF: 0x149E8
    signed int fd; // Offset: 0xA8, DWARF: 0x14A0E
    signed int size; // Offset: 0xAC, DWARF: 0x14A2D
    // Size: 0x40, DWARF: 0x144E0
    Table* table; // Offset: 0xB0, DWARF: 0x14A4E
    // Size: 0x40, DWARF: 0x144E0
    char padding[0xC]; // Not originally in the struct, but aligns the Tables.
    Table newinfo; // Offset: 0xC0, DWARF: 0x14A75
    void* workbuf; // Offset: 0x100, DWARF: 0x14A9B
    char* pwd; // Offset: 0x104, DWARF: 0x14AC2
    char res[7]; // Offset: 0x108, DWARF: 0x14AE5
    signed int valid; // Offset: 0x110, DWARF: 0x14B07
    signed int count; // Offset: 0x114, DWARF: 0x14B29
    signed int fnum[10]; // Offset: 0x118, DWARF: 0x14B4B
} VulmcCardData;

// Size: 0x44, DWARF: 0x142AE
typedef struct VulmcSysInfo
{
    signed int slot; // Offset: 0x0, DWARF: 0x142C9
    signed int actSlot; // Offset: 0x4, DWARF: 0x142EA
    signed int checkSlot; // Offset: 0x8, DWARF: 0x1430E
    signed int connect; // Offset: 0xC, DWARF: 0x14334
    signed int result; // Offset: 0x10, DWARF: 0x14358
    // Size: 0x140, DWARF: 0x14941
    VulmcCardData* reqdata; // Offset: 0x14, DWARF: 0x1437B
    signed int fstat; // Offset: 0x18, DWARF: 0x143A4
    signed int retstat; // Offset: 0x1C, DWARF: 0x143C6
    signed int seqID; // Offset: 0x20, DWARF: 0x143EA
    signed int count; // Offset: 0x24, DWARF: 0x1440C
    signed int block; // Offset: 0x28, DWARF: 0x1442E
    signed int fd[3]; // Offset: 0x2C, DWARF: 0x14450
    signed int fp_num; // Offset: 0x38, DWARF: 0x14471
    signed int res[2]; // Offset: 0x3C, DWARF: 0x14494
} VulmcSysInfo;

// Size: 0x3C4, DWARF: 0x14630
typedef struct Is
{
    unsigned char Head[4]; // Offset: 0x0, DWARF: 0x1464B
    unsigned short Reserv1; // Offset: 0x4, DWARF: 0x1466E
    unsigned short OffsLF; // Offset: 0x6, DWARF: 0x14692
    unsigned int Reserv2; // Offset: 0x8, DWARF: 0x146B5
    unsigned int TransRate; // Offset: 0xC, DWARF: 0x146D9
    signed int BgColor[4][4]; // Offset: 0x10, DWARF: 0x146FF
    float LightDir[3][4]; // Offset: 0x50, DWARF: 0x14725
    float LightColor[3][4]; // Offset: 0x80, DWARF: 0x1474C
    float Ambient[4]; // Offset: 0xB0, DWARF: 0x14775
    unsigned char TitleName[68]; // Offset: 0xC0, DWARF: 0x1479B
    unsigned char FnameView[64]; // Offset: 0x104, DWARF: 0x147C3
    unsigned char FnameCopy[64]; // Offset: 0x144, DWARF: 0x147EB
    unsigned char FnameDel[64]; // Offset: 0x184, DWARF: 0x14813
    unsigned char Reserve3[512]; // Offset: 0x1C4, DWARF: 0x1483A
} Is;

// Included functions /////////////////////////////////////////////////////////////////
int sceMcInit(void);
int sceMcGetInfo(int, int, int*, int*, int*);
int sceMcSetFileInfo(int, int, char*, char*, unsigned int);
int sceMcGetDir(int, int, const char *, unsigned, int, Table *);

//// Variables ////////////////////////////////////////////////////////////////////////

// Size: 0x140, DWARF: 0x14941
VulmcCardData vulmcCardData[8]; // Address: 0x2F2400
// Size: 0x44, DWARF: 0x142AE
VulmcSysInfo vulmcSysInfo; // Address: 0x2F3300
// Size: 0x40, DWARF: 0x144E0
Table vulmcDir[20]; // Address: 0x2F2E00

// Function Declarations /////////////////////////////////////////////////////////////

void ulmcSysInit(signed int with_reset);
void ulmcSysReset();
void ulmcSetUseSlot(signed int slot);
signed int ulmcGetFstat();
// Size: 0x20, DWARF: 0x1419E
Info* ulmcGetCardInfo(signed int slot);
signed int ulmcServer();
signed int ulmcSync(signed int block);
static void ulmcCallBack(// Size: 0x44, DWARF: 0x142AE
VulmcSysInfo* sinfo);
signed int ulmcGetInfo(signed int slot);
signed int ulmcChDir(signed int slot, char* path, char* pwd);
signed int ulmcMkDir(signed int slot, char* dirname);
signed int ulmcGetDir(signed int slot, // Size: 0x40, DWARF: 0x144E0
Table* table, char* filename, signed int mode, signed int max);
signed int ulmcIsExist(signed int slot, char* filename);
signed int ulmcLoad(signed int slot, char* filename, void* loadbuf, signed int size);
signed int ulmcSave(signed int slot, char* filename, void* savebuf, signed int size);
signed int ulmcFormat(signed int slot);
signed int ulmcDelete(signed int slot, char* filename);
signed int ulmcDeleteAll(signed int slot);
void ulmcClearIconSys(// Size: 0x3C4, DWARF: 0x14630
Is* is, char* tname, char* fnview, char* fncopy, char* fndel);
static signed int ulmcCheckSlotNo(signed int slot);

// Function Definitions /////////////////////////////////////////////////////////////

void ulmcSysInit(signed int with_reset)
{
    signed int ret;
    ret = sceMcInit();
    if (with_reset == 1) {
        ulmcSysReset();
    }
    return;
}

void ulmcSysReset()
{
    int j;
    int i;
    vulmcSysInfo.slot = -1;
    vulmcSysInfo.actSlot = -1;
    vulmcSysInfo.checkSlot = 0;
    vulmcSysInfo.connect = 0;
    vulmcSysInfo.result = 0;
    vulmcSysInfo.reqdata = &(vulmcCardData[0]);
    vulmcSysInfo.fstat = 0;
    vulmcSysInfo.retstat = 0;
    vulmcSysInfo.seqID = 0;
    vulmcSysInfo.count = 0;
    vulmcSysInfo.block = 1;
    for (i = 0; i < 3; i++) {
        vulmcSysInfo.fd[i] = 0;
    }
    vulmcSysInfo.fp_num = 0; //0x38
    for (i = 0; i < 8; i++) {
        vulmcCardData[i].info.type = -1;
        vulmcCardData[i].info.format = 0;
        vulmcCardData[i].info.capa = 0;
        vulmcCardData[i].info.result = 0;
        vulmcCardData[i].info.fnum = 0;
        for (j = 0; j < 4; j++) {
            vulmcCardData[i].fnum[j] = -1; // struct in ctx is off?
        }
    }
    return;
}

void ulmcSetUseSlot(signed int slot)
{
  vulmcSysInfo.connect = slot;
  return;
}

signed int ulmcGetFstat(void) {
    return vulmcSysInfo.retstat;
}

Info* ulmcGetCardInfo(signed int slot) {
    return &vulmcCardData[slot].info;
}

signed int ulmcServer() {
    // Size: 0x20, DWARF: 0x1419E
    signed int ii; // r16
    signed int req; // r17
    Info* info; // r18
    signed int ret; // r19
    ret = 0;

    vulmcSysInfo.count = (vulmcSysInfo.count + 1) & 0xFFFFFF;
    if (vulmcSysInfo.fstat) {
        if (vulmcSysInfo.actSlot == -1 && (vulmcSysInfo.slot != -1)) {
            vulmcSysInfo.actSlot = vulmcSysInfo.slot;
            vulmcSysInfo.slot = -1;
        }
        if (vulmcSysInfo.actSlot != -1) {
            vulmcSysInfo.reqdata = &vulmcCardData[vulmcSysInfo.actSlot].info.type;
            info = vulmcSysInfo.reqdata;
            switch (vulmcSysInfo.reqdata->fnum[0]) {
            case 1:
                req = sceMcGetInfo((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3, &info->type, &info->capa, &info->format);
                break;
            case 2:
                req = sceMcOpen((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3, vulmcSysInfo.reqdata->name, vulmcSysInfo.reqdata->mode);
                break;
            case 3:
                req = sceMcClose(vulmcSysInfo.reqdata->fd);
                break;
            case 4:
                req = sceMcSeek(vulmcSysInfo.reqdata->fd, vulmcSysInfo.reqdata->size, vulmcSysInfo.reqdata->mode);
                break;
            case 5:
                req = sceMcRead(vulmcSysInfo.reqdata->fd, vulmcSysInfo.reqdata->workbuf, vulmcSysInfo.reqdata->size);
                break;
            case 6:
                req = sceMcWrite(vulmcSysInfo.reqdata->fd, vulmcSysInfo.reqdata->workbuf, vulmcSysInfo.reqdata->size);
                break;
            case 11:
                req = sceMcMkdir((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3, vulmcSysInfo.reqdata->name);
                break;
            case 12:
                req = sceMcChdir((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3, vulmcSysInfo.reqdata->name, vulmcSysInfo.reqdata->pwd);
                break;
            case 13:
                req = sceMcGetDir((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3, vulmcSysInfo.reqdata->name, vulmcSysInfo.reqdata->mode, vulmcSysInfo.reqdata->size, vulmcSysInfo.reqdata->table);
                break;
            case 14:
                req = sceMcSetFileInfo((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.slot & 3, vulmcSysInfo.reqdata->name, &vulmcSysInfo.reqdata->newinfo, vulmcSysInfo.reqdata->valid);
                break;
            case 15:
            case 35:
                req = sceMcDelete((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3, vulmcSysInfo.reqdata->name);
                break;
            case 16:
                req = sceMcFormat((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3);
                break;
            case 17:
                req = sceMcUnformat((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3);
                break;
            case 19:
                req = sceMcRename((vulmcSysInfo.actSlot < 4) ^ 1, vulmcSysInfo.actSlot & 3, vulmcSysInfo.reqdata->name, vulmcSysInfo.reqdata->rename);
                break;
            }
        } else if (vulmcSysInfo.connect) {
            vulmcSysInfo.reqdata = &vulmcCardData[vulmcSysInfo.checkSlot];
            info = vulmcSysInfo.reqdata;
            req = sceMcGetInfo((vulmcSysInfo.checkSlot < 4) ^ 1, vulmcSysInfo.checkSlot & 3, &info->type, &info->capa, &info->format);
        }
    }
    ret = ulmcSync(vulmcSysInfo.block);
    if (vulmcSysInfo.fstat != 0) {
        if (vulmcSysInfo.actSlot != -1) {
            switch (vulmcSysInfo.seqID) {
            case 35:
                if (vulmcSysInfo.reqdata->fnum[0] == 0xD) {
                    vulmcSysInfo.reqdata->size = (signed int) vulmcSysInfo.result;
                    vulmcSysInfo.reqdata->count = 0;
                    vulmcSysInfo.reqdata->fnum[0] = 0x23;
                    vulmcSysInfo.reqdata->fnum[1] = -1;
                    while (((&vulmcDir[vulmcSysInfo.reqdata->count])->EntryName[0]) == 0x2E) {
                        vulmcSysInfo.reqdata->count++;
                    }
                } else {
                    vulmcSysInfo.reqdata->count += 1;
                }
                if (vulmcSysInfo.reqdata->count >= vulmcSysInfo.reqdata->size) {
                    vulmcSysInfo.reqdata->fnum[0] = -1;
                } else {
                    ulstdSprintf(vulmcSysInfo.reqdata->name, "%s", &vulmcDir[vulmcSysInfo.reqdata->count].EntryName);
                    vulmcSysInfo.retstat = 0;
                }
                if (vulmcSysInfo.result < 0) {
                    vulmcSysInfo.reqdata->fnum[0] = -1;
                    vulmcSysInfo.reqdata->fnum[1] = -1;
                    vulmcSysInfo.retstat = 1;
                }
                break;
            case 33:
            case 34:
                if (vulmcSysInfo.reqdata->fnum[0] == 2) {
                    vulmcSysInfo.reqdata->fd = (signed int) *vulmcSysInfo.reqdata->openfd;
                }
                for (ii = 0; ii < 2; ii++) {
                    vulmcSysInfo.reqdata->fnum[ii] = vulmcSysInfo.reqdata->fnum[ii+1];
                }
                vulmcSysInfo.reqdata->fnum[2] = -1;
                if (vulmcSysInfo.reqdata->fnum[0] != -1) {
                    vulmcSysInfo.retstat = 0;
                }
                if (vulmcSysInfo.result < 0) {
                    for (ii = 0; ii < 3; ii++) {
                        vulmcSysInfo.reqdata->fnum[ii] = -1;
                    }
                    vulmcSysInfo.retstat = 1;
                }
                break;
            default:
                vulmcSysInfo.reqdata->fnum[0] = -1;
                break;
            }
            if (vulmcSysInfo.reqdata->fnum[0] == -1) {
                vulmcSysInfo.seqID = 0;
                if (vulmcSysInfo.slot != -1) {
                    vulmcSysInfo.actSlot = vulmcSysInfo.slot;
                    vulmcSysInfo.slot = -1;
                } else {
                    vulmcSysInfo.actSlot = -1;
                }
            }
        } else if (vulmcSysInfo.connect != 0) {
            for (ii = vulmcSysInfo.checkSlot + 1; ii != vulmcSysInfo.checkSlot; ii++) {
                if (ii >= 8) {
                    ii = 0;
                }
                if (vulmcSysInfo.connect & (1 << ii)) {
                    vulmcSysInfo.checkSlot = ii;
                    break;
                }
            }
        }
    }
    return ret;
}

signed int ulmcSync(signed int block)
{
    signed int ret = 0;
    vulmcSysInfo.fstat = sceMcSync(block, &vulmcSysInfo.reqdata->info.fnum, &vulmcSysInfo.result);
    if (vulmcSysInfo.fstat == 0) {
        ret = 1;
    } else if (vulmcSysInfo.fstat == 1) {
        ulmcCallBack(&vulmcSysInfo);
    }
    if (vulmcSysInfo.actSlot != -1) {
        vulmcSysInfo.retstat = vulmcSysInfo.fstat;
    } else if (vulmcSysInfo.slot != -1) {
        vulmcSysInfo.retstat = 0;
    } else {
        vulmcSysInfo.retstat = -1;
    }
    
    vulmcSysInfo.reqdata->info.result = vulmcSysInfo.result;
    return ret;
}

static void ulmcCallBack(VulmcSysInfo* sinfo) {
    signed int func; // r16
    func = sinfo->reqdata->info.fnum;
    switch (func) { 
        case 1:
            if (sinfo->result >= -10) {
                return;
            }
            if (sinfo->reqdata->info.type != 0)
                return;

            sinfo->reqdata->info.type = -1;
            return;
        case 2:
            if (sinfo->result < 0)
                return;
            sinfo->fd[sinfo->fp_num] = *sinfo->reqdata->openfd = sinfo->result;
            sinfo->fp_num += 1;
            return;
        case 5:
            if (sinfo->result >= 0)
                return;
            if (sinfo->fp_num <= 0)
                return;
            sinfo->fp_num += -1;
            return;
        case 3:
            sinfo->fp_num += -1;
            return;
        case 0xC:
        case 0xB:
            goto end;
        case 6:
            if (sinfo->result >= 0)
                return;
            if (sinfo->fp_num <= 0)
                return;
            sinfo->fp_num += -1;
            return; 
        
        case 0xD:
            goto end;
        case 0x10:
            if (sinfo->result < 0) {
                sinfo->reqdata->info.capa = 0;
                return;
            }
            sinfo->reqdata->info.capa = 0x1f40;
            return;
        case 0xf:
        case 0x13:
        case 0x4:
        case 0xE:
            goto end;
    default:
        ulstdPrintf("Callback received unknown function. %d\n", func); // @181
        end:
        return;
    }
}

signed int ulmcGetInfo(signed int slot) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 1;
        vulmcSysInfo.slot = slot;
        return slot;
    }
    return -1;
}

signed int ulmcChDir(signed int slot, char* path, char* pwd) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 0xC;
        ulstdSprintf(vulmcCardData[slot].name, "%s", path);
        if (*pwd == 0) {
            (vulmcCardData[slot]).pwd = 0;
        } else {
            (vulmcCardData[slot]).pwd = pwd;
        }
        vulmcSysInfo.slot = slot;
        return slot;
    }
    return -1;
}

signed int ulmcMkDir(signed int slot, char* dirname) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 0xB;
        ulstdSprintf(vulmcCardData[slot].name, &d132, dirname);
        vulmcSysInfo.slot = slot;
        return slot;
    }
    return -1;
}

signed int ulmcGetDir(signed int slot, Table* table, char* filename, signed int mode, signed int max) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 0xD;
        vulmcCardData[slot].table = table;
        ulstdSprintf(vulmcCardData[slot].name, &d132, filename);
        vulmcCardData[slot].mode = mode;
        vulmcCardData[slot].size = max;
        vulmcSysInfo.slot = slot;
        return slot;
    }
    return -1;
}

signed int ulmcIsExist(signed int slot, char* filename) {
    int ret = ulmcGetDir(slot, vulmcDir, filename, 0, 1); // r16 
    return ret;
}

signed int ulmcLoad(signed int slot, char* filename, void* loadbuf, signed int size) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 2;
        vulmcCardData[slot].fnum[1] = 5;
        vulmcCardData[slot].fnum[2] = 3;
        vulmcCardData[slot].openfd = &vulmcSysInfo.fd[vulmcSysInfo.fp_num];
        ulstdSprintf(vulmcCardData[slot].name, &d132, filename);
        vulmcCardData[slot].mode = 1;
        vulmcCardData[slot].workbuf = loadbuf;
        vulmcCardData[slot].size = size;
        vulmcSysInfo.slot = slot;
        vulmcSysInfo.seqID = 0x21;
        return slot;
    }
    return -1;
}

signed int ulmcSave(signed int slot, char* filename, void* savebuf, signed int size) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 2;
        vulmcCardData[slot].fnum[1] = 6;
        vulmcCardData[slot].fnum[2] = 3;
        vulmcCardData[slot].openfd = &vulmcSysInfo.fd[vulmcSysInfo.fp_num];
        ulstdSprintf(vulmcCardData[slot].name, &d132, filename);
        vulmcCardData[slot].mode = 0x202;
        vulmcCardData[slot].workbuf = savebuf;
        vulmcCardData[slot].size = size;
        vulmcSysInfo.slot = slot;
        vulmcSysInfo.seqID = 0x22;
        return slot;
    }
    return -1;
}

signed int ulmcFormat(signed int slot) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 0x10;
        vulmcSysInfo.slot = slot;
        return slot;
    }
    return -1;
}

signed int ulmcDelete(signed int slot, char* filename) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        vulmcCardData[slot].fnum[0] = 0xF;
        ulstdSprintf(vulmcCardData[slot].name, &d132, filename);
        vulmcSysInfo.slot = slot;
        return slot;
    }
    return -1;
}

signed int ulmcDeleteAll(signed int slot) {
    if (vulmcSysInfo.slot == -1) {
        slot = ulmcCheckSlotNo(slot);
        ulmcGetDir(slot, &vulmcDir[0], d282, 0, 0x14);
        vulmcCardData[slot].fnum[0] = 0xD;
        vulmcCardData[slot].fnum[1] = 0x23;
        vulmcSysInfo.slot = slot;
        vulmcSysInfo.seqID = 0x23;
        return slot;
    }
    return -1;
}

void ulmcClearIconSys(Is* is /* 0x10(r29) */, char* tname /* 0x20(r29) */, char* fnview /* 0x30(r29) */, char* fncopy /* 0x40(r29) */, char* fndel /* 0x50(r29) */) {
    memset(is, 0, 0x3C4);
    is->Head[0] = 'P';
    is->Head[1] = 'S';
    is->Head[2] = '2';
    is->Head[3] = 'D';
    if (tname) {
        ulstdSprintf(is->TitleName, "%s", tname);
    }
    if (fnview) {
        ulstdSprintf(is->FnameView, "%s", fnview);
    }
    if (fncopy) {
        ulstdSprintf(is->FnameCopy, "%s", fncopy);
    }
    if (fndel) {
        ulstdSprintf(is->FnameDel, "%s", fndel);
    }
}

signed int ulmcCheckSlotNo(signed int slot) {
    if ((slot & 3) > 0) {
        slot = ((slot < 4) ^ 1) * 4;
    }
    return slot;
}
