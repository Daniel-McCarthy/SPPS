#pragma alignlabel off
#include "common.h"
#include "types.h"

// mdlprEnv.c structs ////////////////////////////////////////////////////////////////////

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
#define SCE_GIF_PACKED_TEX0_2 0x7

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
    __int128 color; // Offset: 0x0
    __int128* normal; // Offset: 0x10
    __int128* uv; // Offset: 0x14
    unsigned char pad[0x4]; // Offset: 0x18
    __int128* pos; // Offset: 0x1C
} PhysiqueVert;

// Size: 0x10
typedef struct MeshVert
{
    __int128* pos; // Offset: 0x0
    __int128* normal; // Offset: 0x4
    unsigned int color; // Offset: 0x8
    __int128* uv; // Offset: 0xC
} MeshVert;

// Address: 0x130D90
signed int ulmdlPrimPhysiqueStripGT_Envmap(__int128* _q, PrimList** _prim) {
    signed int qwc; // a2
    signed int i; // t1
    unsigned int verNum; // t0
    unsigned long tex0; // a2
    PrimList* prim; // a2
    unsigned long* q = (unsigned long*)_q; // a0
    unsigned char* p; // v1
    signed int clip;

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    verNum = prim->verNum;
    tex0 = prim->tex0;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 3);
    q[1] = (SCE_GIF_PACKED_TEX0_2 << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(1, 5, 0x80, 1, 0, 0, 1, 2);
    q[5] = 0x48;
    ((__int128*)q)[3] = (__int128)tex0;
    q[8] = SCE_GIF_SET_TAG(verNum, 1, 1, SCE_GS_SET_PRIM(4, 1, 1, 1, 1, 0, 0, 1, 0), 0, 3);
    q[9] = 0x412;
    q += 10;
    qwc = verNum * 3 + 5;

    asm {
        move i, $zero
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
        i <<= 1;
        i &= 6;
        asm {
            cfc2.ni clip, $vi16
        }
        clip &= 0xC0;
        if (clip) {
            i |= 1;
            asm {
                vmfir.w $vf2, $vi1
                sqc2 $vf2, 0x20(q)
            }
        } else {
            if (i != 0) {
                asm {
                    vmtir $vi2, $vf2w
                    vior $vi2, $vi2, $vi1
                    vmfir.w $vf2, $vi2
                }
            }
            {
                __int128* normal = ((PhysiqueVert*)p)->normal;
                asm {
                    lqc2 $vf4, 0x0(normal)
                    sqc2 $vf2, 0x20(q)
                    vmulax.xy $ACC, $vf16, $vf4x
                    vmadday.xy $ACC, $vf17, $vf4y
                    vmaddz.xy $vf3, $vf18, $vf4z
                    vaddw.z $vf3, $vf0, $vf0w
                    vaddw.xy $vf3, $vf3, $vf0w
                    vmuly.xy $vf3, $vf3, $vf11y
                    vmulq.xyz $vf3, $vf3, $Q
                    sqc2 $vf3, 0x0(q)
                    vmulax.xyz $ACC, $vf20, $vf4x
                    vmadday.xyz $ACC, $vf21, $vf4y
                    vmaddz.xyz $vf4, $vf22, $vf4z
                    vmaxx.xyz $vf4, $vf4, $vf0x
                    vmove.w $vf4, $vf0
                    vmulax.xyzw $ACC, $vf24, $vf4x
                    vmadday.xyzw $ACC, $vf25, $vf4y
                    vmaddaz.xyzw $ACC, $vf26, $vf4z
                    vmaddw.xyzw $vf4, $vf27, $vf4w
                    lqc2 $vf5, 0x0(p)
                    vmul.xyz $vf5, $vf5, $vf4
                    vminix.xyz $vf5, $vf5, $vf11x
                    vftoi0.xyzw $vf5, $vf5
                    sqc2 $vf5, 0x10(q)
                }
            }
        }
        verNum--;
        p += sizeof(PhysiqueVert);
        q = (unsigned long*)((unsigned char*)q + 0x30);
    } while ((signed int)verNum > 0);

    q[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
    q[1] = 0xE;
    q[2] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[3] = 0x48;
    *_prim = (PrimList*)p;
    clip = qwc + 2;
    return clip;
}

// Address: 0x130F80
signed int ulmdlPrimMeshStripGT_Envmap(__int128* _q, PrimList** _prim) {
    unsigned char* p; // v1
    signed int clip;
    unsigned long tex0; // a2
    signed int qwc; // a2
    signed int i; // t1
    unsigned int verNum; // t0
    unsigned long* q = (unsigned long*)_q; // a0
    PrimList* prim; // a2

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    verNum = prim->verNum;
    tex0 = prim->tex0;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 3);
    q[1] = (SCE_GIF_PACKED_TEX0_2 << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(1, 5, 0x80, 1, 0, 0, 1, 2);
    q[5] = 0x48;
    ((__int128*)q)[3] = (__int128)tex0;
    q[8] = SCE_GIF_SET_TAG(verNum, 0, 1, SCE_GS_SET_PRIM(4, 1, 1, 1, 1, 0, 0, 1, 0), 0, 3);
    q[9] = 0x412;
    q += 10;
    qwc = verNum * 3 + 5;

    asm {
        move i, $zero
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
        i <<= 1;
        i &= 6;
        asm {
            cfc2.ni clip, $vi16
        }
        clip &= 0xC0;
        if (clip) {
            i |= 1;
            asm {
                vmfir.w $vf2, $vi1
                sqc2 $vf2, 0x20(q)
            }
        } else {
            if (i != 0) {
                asm {
                    vmtir $vi2, $vf2w
                    vior $vi2, $vi2, $vi1
                    vmfir.w $vf2, $vi2
                }
            }
            {
                __int128* normal = ((MeshVert*)p)->normal;
                asm {
                    lqc2 $vf4, 0x0(normal)
                    sqc2 $vf2, 0x20(q)
                    vmulax.xy $ACC, $vf16, $vf4x
                    vmadday.xy $ACC, $vf17, $vf4y
                    vmaddz.xy $vf3, $vf18, $vf4z
                    vaddw.z $vf3, $vf0, $vf0w
                    vaddw.xy $vf3, $vf3, $vf0w
                    vmuly.xy $vf3, $vf3, $vf11y
                    vmulq.xyz $vf3, $vf3, $Q
                    sqc2 $vf3, 0x0(q)
                    vmulax.xyz $ACC, $vf20, $vf4x
                    vmadday.xyz $ACC, $vf21, $vf4y
                    vmaddz.xyz $vf4, $vf22, $vf4z
                    vmaxx.xyz $vf4, $vf4, $vf0x
                    vmove.w $vf4, $vf0
                    vmulax.xyzw $ACC, $vf24, $vf4x
                    vmadday.xyzw $ACC, $vf25, $vf4y
                    vmaddaz.xyzw $ACC, $vf26, $vf4z
                    vmaddw.xyzw $vf4, $vf27, $vf4w
                }
            }
            {
                unsigned int color = ((MeshVert*)p)->color;
                asm {
                    pextlb color, $zero, color
                    pextlb color, $zero, color
                    qmtc2.ni color, $vf5
                    vitof0.xyzw $vf5, $vf5
                    vmul.xyz $vf5, $vf5, $vf4
                    vminix.xyz $vf5, $vf5, $vf11x
                    vftoi0.xyzw $vf5, $vf5
                    sqc2 $vf5, 0x10(q)
                }
            }
        }
        verNum--;
        p += sizeof(MeshVert);
        q = (unsigned long*)((unsigned char*)q + 0x30);
    } while ((signed int)verNum > 0);

    q[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 1);
    q[1] = 0xE;
    q[2] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[3] = 0x48;
    *_prim = (PrimList*)p;
    clip = qwc + 2;
    return clip;
}
