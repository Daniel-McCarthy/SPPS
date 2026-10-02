#pragma alignlabel off
#include "common.h"
#include "types.h"

// mdlprSdw.c structs ////////////////////////////////////////////////////////////////////

#define SCE_GS_SET_ALPHA(a, b, c, d, fix) \
    ((unsigned long)(a) | ((unsigned long)(b) << 2) | ((unsigned long)(c) << 4) | \
    ((unsigned long)(d) << 6) | ((unsigned long)(fix) << 32))

#define SCE_GS_SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix) \
    ((unsigned long)(prim) | ((unsigned long)(iip) << 3) | ((unsigned long)(tme) << 4) | \
    ((unsigned long)(fge) << 5) | ((unsigned long)(abe) << 6) | ((unsigned long)(aa1) << 7) | \
    ((unsigned long)(fst) << 8) | ((unsigned long)(ctxt) << 9) | ((unsigned long)(fix) << 10))

#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((unsigned long)(ate) | ((unsigned long)(atst) << 1) | ((unsigned long)(aref) << 4) | \
    ((unsigned long)(afail) << 12) | ((unsigned long)(date) << 14) | ((unsigned long)(datm) << 15) | \
    ((unsigned long)(zte) << 16) | ((unsigned long)(ztst) << 17))

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop) << 15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim) << 47) | ((unsigned long)(flg) << 58) | ((unsigned long)(nreg) << 60))

#define SCE_GIF_PACKED_A_D 0xe
#define SCE_GIF_PACKED_RGBAQ 0x1

// Size: 0x10, DWARF: 0x79C3C
typedef struct PrimList
{
    unsigned long tex0; // Offset: 0x0
    unsigned short pad; // Offset: 0x8
    unsigned short reserved[2]; // Offset: 0xA
    unsigned short verNum; // Offset: 0xE
} PrimList;

// Size: 0x20
typedef struct PhysiqueVert
{
    unsigned char pad[0x1C]; // Offset: 0x0
    __int128* pos; // Offset: 0x1C
} PhysiqueVert;

// Size: 0x10
typedef struct MeshVert
{
    __int128* pos; // Offset: 0x0
    unsigned char pad[0xC]; // Offset: 0x4
} MeshVert;

// Address: 0x1315D0
signed int ulmdlPrimPhysiqueStripGT_Shadow(__int128* _q, PrimList** _prim) {
    unsigned int verNum; // t0
    signed int qwc; // a2
    unsigned long tex0; // v0
    signed int i; // t1
    unsigned long* q = (unsigned long*)_q; // a0
    unsigned char* p; // v1
    PrimList* prim; // a2
    signed int clip;
    static unsigned long black[2] = {0, 0x80000000}; // 0x2B2E00

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    verNum = prim->verNum;
    tex0 = prim->tex0;
    (void)tex0;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 3);
    q[1] = (SCE_GIF_PACKED_RGBAQ << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(1, 5, 0x80, 3, 0, 0, 1, 2);
    q[5] = 0x48;
    ((__int128*)q)[3] = *(__int128*)black;
    q[8] = SCE_GIF_SET_TAG(verNum, 1, 1, SCE_GS_SET_PRIM(4, 0, 0, 1, 0, 0, 0, 0, 0), 0, 1);
    q[9] = 4;
    q += 10;
    qwc = verNum + 5;

    asm {
        move $t1, $zero
    }
    do {
        __int128* pos = ((PhysiqueVert*)p)->pos;
        asm {
            lqc2 $vf1, 0x0(pos)
            vmulax.xyzw $ACC, $vf28, $vf1x
            vmadday.xyzw $ACC, $vf29, $vf1y
            vmaddaz.xyzw $ACC, $vf30, $vf1z
            vmaddw.xyzw $vf1, $vf31, $vf1w
            vdiv $Q, $vf0w, $vf1w
            vmuly.w $vf1, $vf0, $vf12y
            vwaitq
            vmulq.xyzw $vf1, $vf1, $Q
            vaddx.w $vf1, $vf1, $vf12x
            vminix.w $vf1, $vf1, $vf11x
            vmaxx.w $vf1, $vf1, $vf0x
            vftoi4.xyzw $vf2, $vf1
            vnop
            vnop
            ctc2.ni $zero, $vi16
            vsub.xyz $vf0, $vf1, $vf0
            vsub.xyz $vf0, $vf10, $vf1
            vnop
            vnop
            vnop
            vnop
        }
        asm {
            sll $t1, $t1, 1
            andi $t1, $t1, 0x6
            cfc2.ni $v0, $vi16
            andi $v0, $v0, 0xC0
            beqz $v0, noclip
            ori $t1, $t1, 0x1
            vmfir.w $vf2, $vi1
            sqc2 $vf2, 0x0(q)
            b stored
        noclip:
            beqz $t1, store
            vmtir $vi2, $vf2w
            vior $vi2, $vi2, $vi1
            vmfir.w $vf2, $vi2
        store:
            sqc2 $vf2, 0x0(q)
        stored:
        }
        verNum--;
        p += sizeof(PhysiqueVert);
        q = (unsigned long*)((unsigned char*)q + 0x10);
    } while ((signed int)verNum > 0);

    q[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
    q[1] = 0xE;
    q[2] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[3] = 0x48;
    *_prim = (PrimList*)p;
    clip = qwc + 2;
    return clip;
}

// Address: 0x131770
signed int ulmdlPrimMeshStripGT_Shadow(__int128* _q, PrimList** _prim) {
    signed int qwc; // a2
    signed int i; // t1
    unsigned int verNum; // t0
    unsigned long tex0; // v0
    PrimList* prim; // a2
    unsigned long* q = (unsigned long*)_q; // a0
    unsigned char* p; // v1
    signed int clip;
    static unsigned long black[2] = {0, 0x80000000}; // 0x2B2E10

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    verNum = prim->verNum;
    tex0 = prim->tex0;
    (void)tex0;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 3);
    q[1] = (SCE_GIF_PACKED_RGBAQ << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(1, 5, 0x80, 3, 0, 0, 1, 2);
    q[5] = 0x48;
    ((__int128*)q)[3] = *(__int128*)black;
    q[8] = SCE_GIF_SET_TAG(verNum, 0, 1, SCE_GS_SET_PRIM(4, 0, 0, 1, 0, 0, 0, 1, 0), 0, 1);
    q[9] = 4;
    q += 10;
    qwc = verNum + 5;

    asm {
        move $t1, $zero
    }
    do {
        __int128* pos = ((MeshVert*)p)->pos;
        asm {
            lqc2 $vf1, 0x0(pos)
            vmulax.xyzw $ACC, $vf28, $vf1x
            vmadday.xyzw $ACC, $vf29, $vf1y
            vmaddaz.xyzw $ACC, $vf30, $vf1z
            vmaddw.xyzw $vf1, $vf31, $vf1w
            vdiv $Q, $vf0w, $vf1w
            vmuly.w $vf1, $vf0, $vf12y
            vwaitq
            vmulq.xyzw $vf1, $vf1, $Q
            vaddx.w $vf1, $vf1, $vf12x
            vminix.w $vf1, $vf1, $vf11x
            vmaxx.w $vf1, $vf1, $vf0x
            vftoi4.xyzw $vf2, $vf1
            vnop
            vnop
            ctc2.ni $zero, $vi16
            vsub.xyz $vf0, $vf1, $vf0
            vsub.xyz $vf0, $vf10, $vf1
            vnop
            vnop
            vnop
            vnop
        }
        asm {
            sll $t1, $t1, 1
            andi $t1, $t1, 0x6
            cfc2.ni $v0, $vi16
            andi $v0, $v0, 0xC0
            beqz $v0, noclip
            ori $t1, $t1, 0x1
            vmfir.w $vf2, $vi1
            sqc2 $vf2, 0x0(q)
            b stored
        noclip:
            beqz $t1, store
            vmtir $vi2, $vf2w
            vior $vi2, $vi2, $vi1
            vmfir.w $vf2, $vi2
        store:
            sqc2 $vf2, 0x0(q)
        stored:
        }
        verNum--;
        p += sizeof(MeshVert);
        q = (unsigned long*)((unsigned char*)q + 0x10);
    } while ((signed int)verNum > 0);

    q[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
    q[1] = 0xE;
    q[2] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[3] = 0x48;
    *_prim = (PrimList*)p;
    clip = qwc + 2;
    return clip;
}
