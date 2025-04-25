// cdvd.c context
// Last updated 7/1/2024
// SPPS NTSC-U 201.99 Final

// SCE types
typedef int qword[4] __attribute__ ((aligned(16)));
typedef int sceVu0IVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FVECTOR[4] __attribute__((aligned (16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned (16)));

// Common structs //////////////////////////////////////////////////////////////

// Size: 0x30, DWARF: 0x6238
typedef struct VuldvdSystem
{
    unsigned long total_sec; // Offset: 0x0, DWARF: 0x6253
    unsigned long read_sec; // Offset: 0x8, DWARF: 0x6279
    signed int que_pos; // Offset: 0x10, DWARF: 0x629E
    signed int read_num; // Offset: 0x14, DWARF: 0x62C2
    unsigned int old_read_sec; // Offset: 0x18, DWARF: 0x62E7
    unsigned int read_time; // Offset: 0x1C, DWARF: 0x6310
    float read_per; // Offset: 0x20, DWARF: 0x6336
    float old_read_per; // Offset: 0x24, DWARF: 0x635B
    signed int mem_check; // Offset: 0x28, DWARF: 0x6384
    signed int res; // Offset: 0x2C, DWARF: 0x63AA
} VuldvdSystem;

// Size: 0x10, DWARF: 0x6520
typedef struct VuldvdStreamData
{
    signed int ring_num; // Offset: 0x0, DWARF: 0x653B
    signed int ring_sec; // Offset: 0x4, DWARF: 0x6560
    void* iop_addr; // Offset: 0x8, DWARF: 0x6585
    signed int res; // Offset: 0xC, DWARF: 0x65AD
} VuldvdStreamData;

// Size: 0x4, DWARF: 0x6086
typedef struct VuldvdReadMode
{
    unsigned char trycount; // Offset: 0x0, DWARF: 0x60A1
    unsigned char spindlctrl; // Offset: 0x1, DWARF: 0x60C6
    unsigned char datapattern; // Offset: 0x2, DWARF: 0x60ED
    unsigned char pad; // Offset: 0x3, DWARF: 0x6115
} VuldvdReadMode;

// Size: 0x10, DWARF: 0x6139
typedef struct VuldvdHead
{
    unsigned int ver; // Offset: 0x0, DWARF: 0x6154
    unsigned int num; // Offset: 0x4, DWARF: 0x6174
    unsigned int ofs; // Offset: 0x8, DWARF: 0x6194
    unsigned int res; // Offset: 0xC, DWARF: 0x61B4
} VuldvdHead;

// Size: 0x24, DWARF: 0x65D1
typedef struct VuldvdFD
{
    unsigned int lsn; // Offset: 0x0, DWARF: 0x65EC
    unsigned int size; // Offset: 0x4, DWARF: 0x660C
    char name[16]; // Offset: 0x8, DWARF: 0x662D
    unsigned char date[8]; // Offset: 0x18, DWARF: 0x6650
    unsigned int flag; // Offset: 0x20, DWARF: 0x6673
} VuldvdFD;

// Size: 0x8, DWARF: 0x61D8
typedef struct VuldvdData
{
    unsigned int ofs; // Offset: 0x0, DWARF: 0x61F3
    unsigned int size; // Offset: 0x4, DWARF: 0x6213
} VuldvdData;

// Size: 0x20, DWARF: 0x63CE
typedef struct VuldvdQue
{
    signed int* addr; // Offset: 0x0, DWARF: 0x63E9
    signed short que_no; // Offset: 0x4, DWARF: 0x640D
    signed short no; // Offset: 0x6, DWARF: 0x6430
    signed short tail; // Offset: 0x8, DWARF: 0x644F
    signed short id; // Offset: 0xA, DWARF: 0x6470
    signed short align; // Offset: 0xC, DWARF: 0x648F
    signed short ee_iop; // Offset: 0xE, DWARF: 0x64B1
    void(*func)(void*, signed int, signed int, signed int, signed int); // Offset: 0x10, DWARF: 0x64D4
    signed int src[3]; // Offset: 0x14, DWARF: 0x64FA
} VuldvdQue;

// Size: 0x24, DWARF: 0x65D1
typedef struct VuldvdStreamFD
{
    unsigned int lsn; // Offset: 0x0, DWARF: 0x65EC
    unsigned int size; // Offset: 0x4, DWARF: 0x660C
    char name[16]; // Offset: 0x8, DWARF: 0x662D
    unsigned char date[8]; // Offset: 0x18, DWARF: 0x6650
    unsigned int flag; // Offset: 0x20, DWARF: 0x6673
} VuldvdStreamFD;

// Static data ////////////////////////////////////////////////////////////////////////

char d104[] = "%s;1";

//// Variables ////////////////////////////////////////////////////////////////////////

// Size: 0x30, DWARF: 0x6238
VuldvdSystem vuldvdSystem; // Address: 0x2F2320
char** vuldvdFileList; // Address: 0x0
unsigned char* vuldvdReadAddr; // Address: 0x2E79D4
signed int vuldvdStreamSize; // Address: 0x0
// Size: 0x10, DWARF: 0x6520
VuldvdStreamData vuldvdStreamData; // Address: 0x0
signed int vuldvdFileID; // Address: 0x0
signed int vuldvdStreamCnt; // Address: 0x0
// Size: 0x4, DWARF: 0x6086
VuldvdReadMode vuldvdReadMode; // Address: 0x2E79D0
// Size: 0x10, DWARF: 0x6139
VuldvdHead vuldvdHead; // Address: 0x2F2310
// Size: 0x24, DWARF: 0x65D1
VuldvdFD vuldvdFD; // Address: 0x2EF2E0
// Size: 0x8, DWARF: 0x61D8
VuldvdData vuldvdData[1024]; // Address: 0x2F0310
// Size: 0x20, DWARF: 0x63CE
VuldvdQue vuldvdQue[128]; // Address: 0x2EF310
// Size: 0x24, DWARF: 0x65D1
VuldvdStreamFD vuldvdStreamFD; // Address: 0x0

// Function includes //////////////////////////////////////////////////////
int sceCdRead(unsigned int a, unsigned int sectors, void* buffer , VuldvdReadMode* mode);
int sceCdReadIOPm(unsigned int a, unsigned int sectors, void* buffer , VuldvdReadMode* mode);

//// Function Declarations ////////////////////////////////////////////////

void uldvdInitCdvd_DRIVE(signed int type);
void uldvdSetReadFile_DRIVE(char* fn);
unsigned long uldvdReadData_DRIVE();
signed int uldvdStartReadData_DRIVE();
signed int uldvdCheckFinish_DRIVE();
float uldvdCheckReadPer_DRIVE();

// Function Definitions //////////////////////////////////////////////////

void uldvdInitCdvd_DRIVE(signed int type) {
    signed int disk_type; // r16

    sceCdInit(0);
    if (type == 0) {
        sceCdMmode(1);
    } else {
        sceCdMmode(2);
    }
    disk_type = sceCdGetDiskType();
    if (disk_type == 0x14) {
        sceCdMmode(2);
    } else {
        sceCdMmode(1);
    }
    vuldvdReadMode.trycount = 0;
    vuldvdReadMode.spindlctrl = 1;
    vuldvdReadMode.datapattern = 0;
    vuldvdSystem.total_sec = 0;
    vuldvdSystem.read_sec = 0;
    vuldvdSystem.que_pos = 0;
    vuldvdSystem.read_num = 0;
    vuldvdSystem.old_read_sec = 0;
    vuldvdSystem.mem_check = 0;
}

void uldvdSetReadFile_DRIVE(char* fn) {
    signed int ptr;
    signed int ii; // r16
    signed int sec; // r17
    char tmp[16384]; // 0x30(r29)
    char str_tmp[256]; // 0x4030(r29)

    ulstdSprintf(str_tmp, "%s;1", fn);
    sceCdDiskReady(0);
    sceCdSearchFile(&vuldvdFD, &str_tmp);
    sceCdDiskReady(0);
    sceCdRead(vuldvdFD.lsn, 1U, &tmp, &vuldvdReadMode);
    sceCdSync(0);
    memcpy(&vuldvdHead, &tmp, 0x10);
    ptr = ((vuldvdHead.num * 8) + 0x7FF) / 0x800;
    sceCdDiskReady(0);
    sceCdRead(vuldvdFD.lsn, ptr, &tmp, &vuldvdReadMode);
    sceCdSync(0);
    memcpy(vuldvdData, &tmp[0x10], vuldvdHead.num * 8);
    for (ii = 0; ii < vuldvdHead.num; ii++) {
        vuldvdData[ii].ofs += vuldvdFD.lsn;
    }
}

unsigned long uldvdReadData_DRIVE(VuldvdQue* read_data) {
    // Adds another read request to the que.
    VuldvdQue data; // 0x10(r29)
    data = *read_data;
    memcpy(&vuldvdQue[vuldvdSystem.que_pos], &data, 0x20);
    vuldvdSystem.que_pos = (vuldvdSystem.que_pos + 1);
    vuldvdSystem.total_sec += vuldvdData[vuldvdQue[vuldvdSystem.que_pos - 1].no].size / 0x800;
    vuldvdSystem.read_sec = 0;
    return vuldvdData[vuldvdQue[vuldvdSystem.que_pos - 1].no].size;
}

signed int uldvdStartReadData_DRIVE() {
    signed int ret = 0; // r16

    if (vuldvdSystem.que_pos != 0) {
        sceCdDiskReady(0);
        if (vuldvdQue[vuldvdSystem.read_num].ee_iop == 1) {
            if (vuldvdQue[vuldvdSystem.read_num].addr != 0) {
                vuldvdReadAddr = (unsigned char*)vuldvdQue[vuldvdSystem.read_num].addr;
            } else {
                vuldvdReadAddr = (unsigned char*)sceSifAllocIopHeap(vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].size);
                if (vuldvdReadAddr == 0) {
                    ret = -2;
                }
            }
            if (ret == 0) {
                sceCdReadIOPm(vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].ofs, vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].size / 0x800, vuldvdReadAddr, &vuldvdReadMode);
            }
        } else {
            if (vuldvdQue[vuldvdSystem.read_num].addr != 0) {
                vuldvdReadAddr = (unsigned char*)vuldvdQue[vuldvdSystem.read_num].addr;
            } else {
                vuldvdReadAddr = (unsigned char*)ulMalloc(vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].size, vuldvdQue[vuldvdSystem.read_num].tail, vuldvdQue[vuldvdSystem.read_num].id);
                if (vuldvdReadAddr == 0) {
                    ret = -1;
                }
            }
            if (ret == 0) {
                sceCdRead(vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].ofs, vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].size / 0x800, vuldvdReadAddr, &vuldvdReadMode);
            }
        }
        vuldvdSystem.read_time = 0;
        vuldvdSystem.read_per = 0.0f;
        vuldvdSystem.old_read_per = 0.0f;
    }
    return ret;
}

signed int uldvdCheckFinish_DRIVE() {
    signed int ret; // r16
    unsigned int sec; // r17
    signed int error; // r18

    ret = 0;
    sec = sceCdGetReadPos();
    if ((sec != 0) && (vuldvdSystem.read_num != 0)) {
        vuldvdSystem.read_sec -= ((vuldvdSystem.old_read_sec));
        vuldvdSystem.read_sec += (sec) / 0x800;
        vuldvdSystem.old_read_sec = (sec / 0x800);
    }
    if (vuldvdSystem.mem_check == 1) {
        ret = uldvdStartReadData_DRIVE();
        vuldvdSystem.mem_check = 0;
    } else if (sceCdSync(1) == 0) {
        error = sceCdGetError();
        switch (error) {
        case 1:
        case 48:
        case 49:
            vuldvdSystem.read_sec = vuldvdSystem.read_sec - vuldvdSystem.old_read_sec;
            vuldvdSystem.old_read_sec = 0;
            if (vuldvdQue[vuldvdSystem.read_num].addr == 0 && vuldvdReadAddr != 0) {
                if (vuldvdQue[vuldvdSystem.read_num].ee_iop == 1) {
                    sceSifFreeIopHeap(vuldvdReadAddr);
                } else {
                    ulFree(vuldvdReadAddr);
                }
                vuldvdReadAddr = 0;
            }
            ret = uldvdStartReadData_DRIVE();
            break;
        case 0x14:
        case 0x32:
        case 0x13:
        case -1:
            break;
        case 0:
            vuldvdSystem.read_sec -= ((vuldvdSystem.old_read_sec));
            vuldvdSystem.read_sec += (vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].size / 0x800);
            vuldvdSystem.old_read_sec = 0;
            if (vuldvdQue[vuldvdSystem.read_num].func != 0) {
                vuldvdQue[vuldvdSystem.read_num].func(vuldvdReadAddr, vuldvdData[vuldvdQue[vuldvdSystem.read_num].no].size, vuldvdQue[vuldvdSystem.read_num].src[0], vuldvdQue[vuldvdSystem.read_num].src[1], vuldvdQue[vuldvdSystem.read_num].src[2]);
            }
            vuldvdSystem.read_num = vuldvdSystem.read_num + 1;
            if (vuldvdSystem.read_num == vuldvdSystem.que_pos) {
                vuldvdSystem.que_pos = 0;
                vuldvdSystem.read_num = 0;
                vuldvdSystem.total_sec = 0;
                vuldvdSystem.read_sec = 0;
                vuldvdSystem.old_read_sec = 0;
            } else {
                ret = uldvdStartReadData_DRIVE();
            }
            break;
        }
    }

    vuldvdSystem.read_per = (100.0f * vuldvdSystem.read_sec) /  vuldvdSystem.total_sec;
    if (vuldvdSystem.read_per != vuldvdSystem.old_read_per) {
        vuldvdSystem.old_read_per = vuldvdSystem.read_per;
        vuldvdSystem.read_time = 0;
    } else {
        vuldvdSystem.read_time += 1;
        if (vuldvdSystem.read_time >= 0x78U) {
            do {

            } while (sceCdBreak() == 0);
        }
    }
    if (ret == 0) {
        ret = vuldvdSystem.que_pos - vuldvdSystem.read_num;
    } else {
        vuldvdSystem.mem_check = 1;
    }
    return ret;
}

float uldvdCheckReadPer_DRIVE() {
    return vuldvdSystem.read_per;
}
