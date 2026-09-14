#include "common.h"
#include "types.h"

#define MEMBLK_BODY(m) ((char*)((char*)(m) + 0x40))
#define ABORT() asm { breakc 0x0 }

// xmem.c structs ///////////////////////////////////////////////////////////////////

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
typedef struct HEAPINFO_tag
{
    void* top; // Offset: 0x0
    void* end; // Offset: 0x4
    MEMBLKHEAD* lastmbh; // Offset: 0x8
    unsigned int num_all_memblk; // Offset: 0xC
    unsigned int num_use_memblk; // Offset: 0x10
} HEAPINFO;

//// Function Declarations //////////////////////////////////////////////////////////

void xmemInitHeap(HEAPINFO* heapinfo, void* top, void* end);
signed int xmemCheckExistMemory(HEAPINFO* heapinfo, void* memp);
void* xmemMalloc(HEAPINFO* heapinfo, unsigned int size);
void* xmemMalloc2(HEAPINFO* heapinfo, unsigned int size);
signed int xmemFree(void* memp);
signed int xmemMallocStat(HEAPINFO* heapinfo, unsigned int* mfree, unsigned int* msize);

//// Functions //////////////////////////////////////////////////////////////////////

void xmemInitHeap(HEAPINFO* heapinfo, void* top, void* end)
{
    void* retaddr; // DWARF: ra (renamed; MWCC resolves `ra` in asm to $ra)
    MEMBLKHEAD* mbh;

    heapinfo->top = (void*)(((unsigned int)top + 0x40) & -0x40);
    heapinfo->end = (void*)((unsigned int)end & -0x40);
    heapinfo->num_all_memblk = 1;
    heapinfo->num_use_memblk = 0;
    mbh = heapinfo->top;
    mbh->prev = 0;
    mbh->next = 0;
    mbh->size = (unsigned int)heapinfo->end - (unsigned int)heapinfo->top - 0x40;
    mbh->flag = 0;
    retaddr = 0;
    asm {
        addu retaddr, $ra, $zero
    }
    mbh->_retaddr = retaddr;
    mbh->_heapinfo = heapinfo;
    mbh->_pad[1] = 0;
    mbh->_pad[0] = 0;
    heapinfo->lastmbh = mbh;
}

void* xmemMalloc(HEAPINFO* heapinfo, unsigned int size)
{
    MEMBLKHEAD* mbh;
    MEMBLKHEAD* nmbh;

    mbh = heapinfo->top;
    size = (size + 0x40) & -0x40;
    while ((mbh->flag & 1) || (mbh->size < size)) {
        mbh = mbh->next;
        if (mbh == 0) {
            ABORT();
            return 0;
        }
    }
    if (mbh->size > size + 0x80) {
        void* retaddr;

        nmbh = (MEMBLKHEAD*)(MEMBLK_BODY(mbh) + size);
        nmbh->prev = mbh;
        nmbh->next = mbh->next;
        nmbh->size = mbh->size - size - 0x40;
        nmbh->flag = 0;
        retaddr = 0;
        asm {
            addu retaddr, $ra, $zero
        }
        nmbh->_retaddr = retaddr;
        nmbh->_heapinfo = heapinfo;
        nmbh->_pad[1] = 0;
        nmbh->_pad[0] = 0;
        if (nmbh->next) {
            nmbh->next->prev = nmbh;
        }
        mbh->next = nmbh;
        mbh->size = size;
        if (nmbh->next == 0) {
            heapinfo->lastmbh = nmbh;
        }
        heapinfo->num_all_memblk += 1;
    }
    {
        void* retaddr;

        mbh->flag = 1;
        retaddr = 0;
        asm {
            addu retaddr, $ra, $zero
        }
        mbh->_retaddr = retaddr;
        mbh->_heapinfo = heapinfo;
        mbh->_pad[1] = 0;
        mbh->_pad[0] = 0;
    }
    heapinfo->num_use_memblk += 1;
    return MEMBLK_BODY(mbh);
}

void* xmemMalloc2(HEAPINFO* heapinfo, unsigned int size)
{
    MEMBLKHEAD* mbh;
    MEMBLKHEAD* pmbh;

    mbh = heapinfo->lastmbh;
    size = (size + 0x40) & -0x40;
    while ((mbh->flag & 1) || (mbh->size < size)) {
        mbh = mbh->prev;
        if (mbh == 0) {
            ABORT();
            return 0;
        }
    }
    if (mbh->size > size + 0x80) {
        pmbh = mbh;
        mbh = (MEMBLKHEAD*)(MEMBLK_BODY(mbh) + mbh->size - (size + 0x40));
        mbh->prev = pmbh;
        mbh->next = pmbh->next;
        mbh->size = size;
        if (mbh->next) {
            mbh->next->prev = mbh;
        }
        pmbh->next = mbh;
        pmbh->size = pmbh->size - size - 0x40;
        if (mbh->next == 0) {
            heapinfo->lastmbh = mbh;
        }
        heapinfo->num_all_memblk += 1;
    }
    {
        void* retaddr;

        mbh->flag = 1;
        retaddr = 0;
        asm {
            addu retaddr, $ra, $zero
        }
        mbh->_retaddr = retaddr;
        mbh->_heapinfo = heapinfo;
        mbh->_pad[1] = 0;
        mbh->_pad[0] = 0;
    }
    heapinfo->num_use_memblk += 1;
    return MEMBLK_BODY(mbh);
}

signed int xmemFree(void* memp)
{
    MEMBLKHEAD* mbh;
    MEMBLKHEAD* pmbh;
    MEMBLKHEAD* nmbh;
    HEAPINFO* heapinfo;
    signed int ret;

    if (memp == 0) {
        return -2;
    }
    mbh = (MEMBLKHEAD*)((char*)memp - 0x40);
    heapinfo = mbh->_heapinfo;
    ret = xmemCheckExistMemory(heapinfo, memp);
    if (ret < 0) {
        return ret;
    }
    if (ret == 0) {
        return -4;
    }
    xmemMallocStat(heapinfo, 0, 0);
    mbh->flag = 0;
    {
        void* retaddr;

        retaddr = 0;
        asm {
            addu retaddr, $ra, $zero
        }
        mbh->_retaddr = retaddr;
    }
    mbh->_heapinfo = heapinfo;
    mbh->_pad[1] = 0;
    mbh->_pad[0] = 0;
    nmbh = mbh->next;
    if (nmbh && !(nmbh->flag & 1)) {
        mbh->next = nmbh->next;
        mbh->size = mbh->size + nmbh->size + 0x40;
        nmbh->flag = -1;
        if (mbh->next) {
            mbh->next->prev = mbh;
        } else {
            heapinfo->lastmbh = mbh;
        }
        heapinfo->num_all_memblk -= 1;
    }
    pmbh = mbh->prev;
    if (pmbh && !(pmbh->flag & 1)) {
        pmbh->next = mbh->next;
        pmbh->size = pmbh->size + mbh->size + 0x40;
        mbh->flag = 0xEEEEEEEE;
        if (pmbh->next) {
            pmbh->next->prev = pmbh;
        } else {
            heapinfo->lastmbh = pmbh;
        }
        heapinfo->num_all_memblk -= 1;
        {
            void* retaddr;

            retaddr = 0;
            asm {
                addu retaddr, $ra, $zero
            }
            pmbh->_retaddr = retaddr;
        }
        pmbh->_heapinfo = heapinfo;
        pmbh->_pad[1] = 0;
        pmbh->_pad[0] = 0;
    }
    heapinfo->num_use_memblk -= 1;
    xmemMallocStat(heapinfo, 0, 0);
    return 0;
}

signed int xmemMallocStat(HEAPINFO* heapinfo, unsigned int* mfree, unsigned int* msize)
{
    MEMBLKHEAD* m;
    unsigned int now;
    unsigned int next;
    unsigned int _mfree;
    unsigned int _msize;

    if (mfree == 0) {
        mfree = &_mfree;
    }
    if (msize == 0) {
        msize = &_msize;
    }
    if (heapinfo->lastmbh < heapinfo->top) {
        ABORT();
        return -1;
    }
    if (heapinfo->lastmbh > heapinfo->end) {
        ABORT();
        return -1;
    }
    *mfree = 0;
    *msize = 0;
    m = heapinfo->top;
    while (m) {
        now = (unsigned int)MEMBLK_BODY(m);
        next = m->next ? (unsigned int)m->next : (unsigned int)heapinfo->end;
        if (m->size != next - now) {
            ABORT();
            return -1;
        }
        if (m->next == 0 && m != heapinfo->lastmbh) {
            ABORT();
            return -1;
        }
        if (!(m->flag & 1)) {
            *mfree += m->size;
            if (m->size > *msize) {
                *msize = m->size;
            }
        }
        m = m->next;
    }
    return 0;
}

signed int xmemCheckExistMemory(HEAPINFO* heapinfo, void* memp)
{
    MEMBLKHEAD* m;

    if (memp < heapinfo->top) {
        return -5;
    }
    if (memp > heapinfo->end) {
        return -6;
    }
    m = heapinfo->top;
    while (m) {
        if ((void*)MEMBLK_BODY(m) == memp) {
            return (m->flag & 1) ? 1 : 0;
        }
        m = m->next;
    }
    return -3;
}
