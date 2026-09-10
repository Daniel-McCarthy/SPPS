#include "common.h"
#include "types.h"

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop)<<15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim)<<47) | ((unsigned long)(flg)<<58) | ((unsigned long)(nreg)<<60))

#define SCE_GIF_PACKED_AD   0x0e

#define SCE_DMA_SET_TAG(qwc, pce, id, irq, addr, spr) \
    ((unsigned long)(qwc) | ((unsigned long)(pce)<<26) | ((unsigned long)(id)<<28) | \
    ((unsigned long)(irq)<<31) | ((unsigned long)(addr)<<32) | ((unsigned long)(spr)<<63))

#define SCE_DMA_CNT 1
#define SCE_DMA_END 7

#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((unsigned long)(ate) | ((unsigned long)(atst)<<1) | ((unsigned long)(aref)<<4) | \
    ((unsigned long)(afail)<<12) | ((unsigned long)(date)<<14) | ((unsigned long)(datm)<<15) | \
    ((unsigned long)(zte)<<16) | ((unsigned long)(ztst)<<17))

#define SCE_GS_TEST_1 0x47
#define SCE_GS_TEST_2 0x48

// tmalpha.c structs ////////////////////////////////////////////////////////////////////

// Size: 0x10
typedef struct _sceDmaTag
{
    unsigned short qwc; // Offset: 0x0
    unsigned char mark; // Offset: 0x2
    unsigned char id; // Offset: 0x3
    struct _sceDmaTag* next; // Offset: 0x4
    unsigned int p[2]; // Offset: 0x8
} _sceDmaTag;

// Size: 0x4
typedef struct Chcr
{
    unsigned int DIR : 1; // Offset: 0x0, Bit Offset: 0, Bit Size: 1
    unsigned int p0 : 1; // Offset: 0x0, Bit Offset: 1, Bit Size: 1
    unsigned int MOD : 2; // Offset: 0x0, Bit Offset: 2, Bit Size: 2
    unsigned int ASP : 2; // Offset: 0x0, Bit Offset: 4, Bit Size: 2
    unsigned int TTE : 1; // Offset: 0x0, Bit Offset: 6, Bit Size: 1
    unsigned int TIE : 1; // Offset: 0x0, Bit Offset: 7, Bit Size: 1
    unsigned int STR : 1; // Offset: 0x0, Bit Offset: 8, Bit Size: 1
    unsigned int p1 : 7; // Offset: 0x0, Bit Offset: 9, Bit Size: 7
    unsigned int TAG : 16; // Offset: 0x0, Bit Offset: 16, Bit Size: 16
} Chcr;

// Size: 0x90
typedef struct DmaVif
{
    // Size: 0x4
    Chcr chcr; // Offset: 0x0
    unsigned int p0[3]; // Offset: 0x4
    void* madr; // Offset: 0x10
    unsigned int p1[3]; // Offset: 0x14
    unsigned int qwc; // Offset: 0x20
    unsigned int p2[3]; // Offset: 0x24
    // Size: 0x10
    _sceDmaTag* tadr; // Offset: 0x30
    unsigned int p3[3]; // Offset: 0x34
    void* as0; // Offset: 0x40
    unsigned int p4[3]; // Offset: 0x44
    void* as1; // Offset: 0x50
    unsigned int p5[3]; // Offset: 0x54
    unsigned int p6[4]; // Offset: 0x60
    unsigned int p7[4]; // Offset: 0x70
    void* sadr; // Offset: 0x80
    unsigned int p8[3]; // Offset: 0x84
} DmaVif;

// Size: 0x360
typedef struct VulsysSystem
{
    unsigned int KeepMemSize; // Offset: 0x0
    signed int Pal; // Offset: 0x4
    signed int Interlace; // Offset: 0x8
    signed short ScreenMode; // Offset: 0xC
    signed short ScreenWidth; // Offset: 0xE
    signed short ScreenHeight; // Offset: 0x10
    signed short ScreenYofs; // Offset: 0x12
    signed int EvenOdd; // Offset: 0x14
    unsigned long Frame; // Offset: 0x18
    signed int PadInit; // Offset: 0x20
    // Size: 0x90
    DmaVif* DmaGif; // Offset: 0x24
    // Size: 0x90
    DmaVif* DmaVif0; // Offset: 0x28
    // Size: 0x90
    DmaVif* DmaVif1; // Offset: 0x2C
    unsigned char DBuff[0x330]; // Offset: 0x30
} VulsysSystem;

// Size: 0x10
typedef struct GifPkt
{
    unsigned int* pCurrent; // Offset: 0x0
    __int128* pBase; // Offset: 0x4
    __int128* pDmaTag; // Offset: 0x8
    unsigned long* pGifTag; // Offset: 0xC
} GifPkt;

// Size: 0x10
typedef struct Ctx
{
    signed int atest; // Offset: 0x0
    signed int aref; // Offset: 0x4
    signed int afail; // Offset: 0x8
    signed int send; // Offset: 0xC
} Ctx;

// SCE includes /////////////////////////////////////////////////////////////////////
void FlushCache(signed int mode);
signed int sceDmaSend(DmaVif* chan, void* data);
void sceGsSyncPath(signed int mode, unsigned short timeout);
void sceGifPkCnt(GifPkt* packet, unsigned int pce, unsigned int irq, unsigned int spr);
unsigned long* sceGifPkReserve(GifPkt* packet, unsigned int qwc);
void sceGifPkTerminate(GifPkt* packet);

//// Function Declarations ///////////////////////////////////////////////////////////

void tmalphaSetTestReg(GifPkt* packet, Ctx* ctx1, Ctx* ctx2);

//// Globals /////////////////////////////////////////////////////////////////////////

extern VulsysSystem vulsysSystem; // Address: 0x2F3A50

// Address: 0x155F20
// Size: 0x39C
void tmalphaSetTestReg(GifPkt* packet, Ctx* ctx1, Ctx* ctx2) {
    long tmp;
    unsigned long* addr; // r16
    __int128 giftag; // 0x40(r29)
    unsigned long local_packet[8]; // 0x50(r29)
    DmaVif* channel; // r17

    channel = vulsysSystem.DmaGif;
    ((unsigned long*)&giftag)[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
    ((unsigned long*)&giftag)[1] = tmp = SCE_GIF_PACKED_AD;

    if (ctx1 != 0) {
        if (ctx1->send != 0) {
            local_packet[0] = SCE_DMA_SET_TAG(2, 0, SCE_DMA_CNT, 0, 0, 0);
            local_packet[1] = 0;
            local_packet[2] = ((unsigned long*)&giftag)[0];
            local_packet[3] = ((unsigned long*)&giftag)[1];
            local_packet[4] = SCE_GS_SET_TEST(1, ctx1->atest, ctx1->aref, ctx1->afail, 0, 0, 1, 2);
            local_packet[5] = SCE_GS_TEST_1;
            local_packet[6] = SCE_DMA_SET_TAG(0, 0, SCE_DMA_END, 0, 0, 0);
            FlushCache(0);
            sceDmaSend(channel, local_packet);
            sceGsSyncPath(0, 0);
        } else {
            sceGifPkCnt(packet, 0, 0, 0);
            addr = sceGifPkReserve(packet, 8);
            *(__int128*)addr = giftag;
            addr += 2;
            *addr++ = SCE_GS_SET_TEST(1, ctx1->atest, ctx1->aref, ctx1->afail, 0, 0, 1, 2);
            *addr++ = SCE_GS_TEST_1;
            sceGifPkTerminate(packet);
        }
    }
    if (ctx2 != 0) {
        if (ctx2->send != 0) {
            local_packet[0] = SCE_DMA_SET_TAG(2, 0, SCE_DMA_CNT, 0, 0, 0);
            local_packet[1] = 0;
            local_packet[2] = ((unsigned long*)&giftag)[0];
            local_packet[3] = ((unsigned long*)&giftag)[1];
            local_packet[4] = SCE_GS_SET_TEST(1, ctx2->atest, ctx2->aref, ctx2->afail, 0, 0, 1, 2);
            local_packet[5] = SCE_GS_TEST_2;
            local_packet[6] = SCE_DMA_SET_TAG(0, 0, SCE_DMA_END, 0, 0, 0);
            FlushCache(0);
            sceDmaSend(channel, local_packet);
            sceGsSyncPath(0, 0);
        } else {
            sceGifPkCnt(packet, 0, 0, 0);
            addr = sceGifPkReserve(packet, 8);
            *(__int128*)addr = giftag;
            addr += 2;
            *addr++ = SCE_GS_SET_TEST(1, ctx2->atest, ctx2->aref, ctx2->afail, 0, 0, 1, 2);
            *addr++ = SCE_GS_TEST_2;
            sceGifPkTerminate(packet);
        }
    }
}
