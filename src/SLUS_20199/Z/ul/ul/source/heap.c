#include "common.h"
#include "types.h"

#define MEMBLK_HEAD(p) ((MEMBLKHEAD*)((char*)(p) - 0x40))
#define ABORT() asm { breakc 0x0 }

// heap.c structs ///////////////////////////////////////////////////////////////////

// Size: 0x20
typedef struct MEMBLKHEAD_tag
{
    struct MEMBLKHEAD_tag* prev; // Offset: 0x0
    struct MEMBLKHEAD_tag* next; // Offset: 0x4
    unsigned int size; // Offset: 0x8
    unsigned int flag; // Offset: 0xC
    void* _retaddr; // Offset: 0x10
    void* _heapinfo; // Offset: 0x14
    unsigned int _pad[2]; // Offset: 0x18
} MEMBLKHEAD;

// Size: 0x14
typedef struct
{
    void* top; // Offset: 0x0
    void* end; // Offset: 0x4
    MEMBLKHEAD* lastmbh; // Offset: 0x8
    unsigned int num_all_memblk; // Offset: 0xC
    unsigned int num_use_memblk; // Offset: 0x10
} HEAPINFO;

//// Globals ////////////////////////////////////////////////////////////////////////

static HEAPINFO heapinfo[2]; // Address: 0x2F23D0

//// Function Declarations //////////////////////////////////////////////////////////

signed int sceOpen(char* filename, signed int flag);
signed int sceWrite(signed int fd, void* buf, signed int nbyte);
signed int sceClose(signed int fd);

void ulstdPrintf(char* fmt, ...);
signed int ulstdSprintf(char* buf, char* fmt, ...);

void xmemInitHeap(HEAPINFO* heapinfo, void* top, void* end);
void* xmemMalloc(HEAPINFO* heapinfo, unsigned int size);
void* xmemMalloc2(HEAPINFO* heapinfo, unsigned int size);
signed int xmemFree(void* memp);
signed int xmemMallocStat(HEAPINFO* heapinfo, unsigned int* mfree, unsigned int* msize);

void ulInitHeap(void* heapstart, void* heapend, unsigned int heap1size);
void* ulMalloc(unsigned int size, signed int malloc2, signed int id);
void ulFree(void* p);
void ulDumpHeapInfo(char* filename, signed int heapno);

//// Functions //////////////////////////////////////////////////////////////////////

void ulInitHeap(void* heapstart, void* heapend, unsigned int heap1size)
{
    void* heap1;

    if (heap1size) {
        heap1 = (void*)((char*)heapend - heap1size);
        xmemInitHeap(&heapinfo[0], heapstart, heap1);
        xmemInitHeap(&heapinfo[1], heap1, heapend);
    } else {
        xmemInitHeap(&heapinfo[0], heapstart, heapend);
        heapinfo[1].top = 0;
        heapinfo[1].end = 0;
        heapinfo[1].lastmbh = 0;
        heapinfo[1].num_all_memblk = 0;
        heapinfo[1].num_use_memblk = 0;
    }
}

void* ulMalloc(unsigned int size, signed int malloc2, signed int id)
{
    void* ra;
    void* p;
    void* retaddr;

    retaddr = 0;
    asm {
        addu retaddr, $ra, $zero
    }
    ra = retaddr;

    xmemMallocStat(&heapinfo[id & 1], 0, 0);

    if (malloc2 == 0) {
        p = xmemMalloc(&heapinfo[id & 1], size);
    } else {
        p = xmemMalloc2(&heapinfo[id & 1], size);
    }
    MEMBLK_HEAD(p)->_retaddr = ra;

    xmemMallocStat(&heapinfo[id & 1], 0, 0);

    return p;
}

void ulFree(void* p)
{
    void* ra;
    void* retaddr;
    signed int ret;

    retaddr = 0;
    asm {
        addu retaddr, $ra, $zero
    }
    ra = retaddr;

    if (p) {
        if ((ret = xmemFree(p)) < 0) {
            ulstdPrintf("Error 'ulFree(0x%08x)' : %d\n", p, ret);
            ulDumpHeapInfo("host0:tmp/heap0.txt", 0);
            ulDumpHeapInfo("host0:tmp/heap1.txt", 1);
            ABORT();
        }
        MEMBLK_HEAD(p)->_retaddr = ra;
    }
}

void ulDumpHeapInfo(char* filename, signed int heapno)
{
    MEMBLKHEAD* nmbh;
    HEAPINFO* hi;
    char buf[256];
    signed int fd;
    signed int i;
    MEMBLKHEAD* mbh;

    fd = sceOpen(filename, 0x602);
    if (fd < 0)
        return;

    ulstdPrintf("Write heapinfo %d \"%s\"\n", heapno, filename);

    hi = &heapinfo[heapno];

    sceWrite(fd, buf, ulstdSprintf(buf, "[heapinfo]\n"));
    sceWrite(fd, buf, ulstdSprintf(buf, " TOP : %08x\n", hi->top));
    sceWrite(fd, buf, ulstdSprintf(buf, " END : %08x\n", hi->end));
    sceWrite(fd, buf, ulstdSprintf(buf, " BLK : %3d/%3d\n\n", hi->num_use_memblk, hi->num_all_memblk));

    sceWrite(fd, buf, ulstdSprintf(buf, "[memoryblock]\n"));
    sceWrite(fd, buf, ulstdSprintf(buf, "use    addr     size    size       from\n"));

    mbh = hi->top;
    i = 0;
    while (mbh) {
        sceWrite(fd, buf, ulstdSprintf(buf, " %c %08x %08x(%7d)  %08x\n", (mbh->flag & 1) ? '*' : ' ', mbh, mbh->size, mbh->size, (unsigned int)mbh->_retaddr));

        (void)nmbh;

        i++, nmbh = mbh = mbh->next;
    }

    sceClose(fd);
}
