#pragma alignlabel off
#include "common.h"
#include "types.h"

// mdlprTon.c structs ////////////////////////////////////////////////////////////////////

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

#define SCE_GS_SET_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((unsigned long)(wms) | ((unsigned long)(wmt) << 2) | ((unsigned long)(minu) << 4) | \
    ((unsigned long)(maxu) << 14) | ((unsigned long)(minv) << 24) | ((unsigned long)(maxv) << 34))

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((unsigned long)(nloop) | ((unsigned long)(eop) << 15) | ((unsigned long)(pre) << 46) | \
    ((unsigned long)(prim) << 47) | ((unsigned long)(flg) << 58) | ((unsigned long)(nreg) << 60))

#define SCE_GIF_PACKED_RGBAQ 0x1
#define SCE_GIF_PACKED_ST 0x2
#define SCE_GIF_PACKED_XYZF2 0x4
#define SCE_GIF_PACKED_TEX0_2 0x7
#define SCE_GIF_PACKED_A_D 0xe

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

// Only the field this file reads is known; the rest of the struct is unmapped.
typedef struct DrawInfo
{
    unsigned char pad[0x168]; // Offset: 0x0
    unsigned long tex0; // Offset: 0x168
} DrawInfo;

// Address: 0x2D9B50
static const signed int rgba[4] = { 0x80, 0x80, 0x80, 0x80 };

// Address: 0x13F2E0
signed int ulmdlPrimPhysiqueStripGT_Toon(__int128* _q, PrimList** _prim, DrawInfo* dinfo) {
    signed int len; // t1
    signed int i; // t1
    unsigned long* q2; // a2
    unsigned long* q = (unsigned long*)_q; // a0
    unsigned char* p; // v1
    signed int qwc; // a3
    unsigned long* q1; // t0
    unsigned int verNum; // t2
    PrimList* prim; // t0
    signed int clip;

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    qwc = 0;
    verNum = prim->verNum;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 4);
    q[1] = (SCE_GIF_PACKED_TEX0_2 << 12) | (SCE_GIF_PACKED_A_D << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(1, 5, 0x80, 1, 0, 0, 1, 2);
    q[5] = 0x48;
    q[6] = SCE_GS_SET_CLAMP(0, 0, 0, 0, 0, 0);
    q[7] = 0x9;
    q[8] = prim->tex0;
    q[9] = 0;
    q[10] = SCE_GIF_SET_TAG(verNum, 1, 1, SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 0, 1, 0), 0, 3);
    q[11] = (SCE_GIF_PACKED_XYZF2 << 8) | (SCE_GIF_PACKED_RGBAQ << 4) | SCE_GIF_PACKED_ST;
    q1 = q + 12;
    len = verNum * 3 + 6;
    q += len * 2;
    qwc += len;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 4);
    q[1] = (SCE_GIF_PACKED_TEX0_2 << 12) | (SCE_GIF_PACKED_A_D << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(2, 0, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[5] = 0x48;
    q[6] = SCE_GS_SET_CLAMP(1, 1, 0, 0, 0, 0);
    q[7] = 0x9;
    q[8] = dinfo->tex0;
    q[9] = 0;
    q[10] = SCE_GIF_SET_TAG(verNum, 1, 1, SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 0, 1, 0), 0, 3);
    q[11] = (SCE_GIF_PACKED_XYZF2 << 8) | (SCE_GIF_PACKED_RGBAQ << 4) | SCE_GIF_PACKED_ST;
    q2 = q + 12;
    len = verNum * 3 + 6;
    q += len * 2;
    qwc += len;

    q[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 3);
    q[1] = (SCE_GIF_PACKED_A_D << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[5] = 0x48;
    q[6] = SCE_GS_SET_CLAMP(0, 0, 0, 0, 0, 0);
    q[7] = 0x9;
    qwc += 4;

    {
        const signed int* col = rgba;
        asm {
            move i, $zero
        }
        asm {
            lqc2 $vf6, 0x0(col)
        }
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
        }
        {
            __int128* uv = ((PhysiqueVert*)p)->uv;
            asm {
                lqc2 $vf3, 0x0(uv)
                vwaitq
                vmulq.xyzw $vf1, $vf1, $Q
                vmulq.xyz $vf3, $vf3, $Q
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
                sqc2 $vf2, 0x20(q1)
                sqc2 $vf2, 0x20(q2)
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
                    sqc2 $vf3, 0x0(q1)
                    sqc2 $vf2, 0x20(q1)
                    sqc2 $vf2, 0x20(q2)
                    vmulax.xyz $ACC, $vf20, $vf4x
                    vmadday.xyz $ACC, $vf21, $vf4y
                    vmaddz.xyz $vf4, $vf22, $vf4z
                    vmaxx.xyz $vf4, $vf4, $vf0x
                    vmove.w $vf4, $vf0
                    vmulax.xyzw $ACC, $vf24, $vf4x
                    vmadday.xyzw $ACC, $vf25, $vf4y
                    vmaddaz.xyzw $ACC, $vf26, $vf4z
                    vmaddw.xyzw $vf4, $vf27, $vf4w
                    vmr32.xyzw $vf3, $vf0
                    vmove.x $vf3, $vf4
                    vminiw.x $vf3, $vf3, $vf0w
                    vmaxx.x $vf3, $vf3, $vf0x
                    vmulq.xyz $vf3, $vf3, $Q
                    sqc2 $vf3, 0x0(q2)
                    sqc2 $vf6, 0x10(q1)
                    sqc2 $vf6, 0x10(q2)
                }
            }
        }
        verNum--;
        p += sizeof(PhysiqueVert);
        q1 = (unsigned long*)((unsigned char*)q1 + 0x30);
        q2 = (unsigned long*)((unsigned char*)q2 + 0x30);
    } while ((signed int)verNum > 0);

    *_prim = (PrimList*)p;
    clip = qwc;
    return clip;
}

// Address: 0x13F5D0
signed int ulmdlPrimMeshStripGT_Toon(__int128* _q, PrimList** _prim, DrawInfo* dinfo) {
    signed int len; // t1
    signed int i; // t1
    unsigned long* q2; // a2
    unsigned long* q = (unsigned long*)_q; // a0
    unsigned char* p; // v1
    signed int qwc; // a3
    unsigned long* q1; // t0
    unsigned int verNum; // t2
    PrimList* prim; // t0
    signed int clip;

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    qwc = 0;
    verNum = prim->verNum;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 4);
    q[1] = (SCE_GIF_PACKED_TEX0_2 << 12) | (SCE_GIF_PACKED_A_D << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(1, 5, 0x80, 1, 0, 0, 1, 2);
    q[5] = 0x48;
    q[6] = SCE_GS_SET_CLAMP(0, 0, 0, 0, 0, 0);
    q[7] = 0x9;
    q[8] = prim->tex0;
    q[9] = 0;
    q[10] = SCE_GIF_SET_TAG(verNum, 1, 1, SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 0, 1, 0), 0, 3);
    q[11] = (SCE_GIF_PACKED_XYZF2 << 8) | (SCE_GIF_PACKED_RGBAQ << 4) | SCE_GIF_PACKED_ST;
    q1 = q + 12;
    len = verNum * 3 + 6;
    q += len * 2;
    qwc += len;

    q[0] = SCE_GIF_SET_TAG(1, 0, 0, 0, 0, 4);
    q[1] = (SCE_GIF_PACKED_TEX0_2 << 12) | (SCE_GIF_PACKED_A_D << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(2, 0, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[5] = 0x48;
    q[6] = SCE_GS_SET_CLAMP(1, 1, 0, 0, 0, 0);
    q[7] = 0x9;
    q[8] = dinfo->tex0;
    q[9] = 0;
    q[10] = SCE_GIF_SET_TAG(verNum, 1, 1, SCE_GS_SET_PRIM(4, 0, 1, 0, 1, 0, 0, 1, 0), 0, 3);
    q[11] = (SCE_GIF_PACKED_XYZF2 << 8) | (SCE_GIF_PACKED_RGBAQ << 4) | SCE_GIF_PACKED_ST;
    q2 = q + 12;
    len = verNum * 3 + 6;
    q += len * 2;
    qwc += len;

    q[0] = SCE_GIF_SET_TAG(1, 1, 0, 0, 0, 3);
    q[1] = (SCE_GIF_PACKED_A_D << 8) | (SCE_GIF_PACKED_A_D << 4) | SCE_GIF_PACKED_A_D;
    q[2] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    q[3] = 0x43;
    q[4] = SCE_GS_SET_TEST(0, 0, 0, 0, 0, 0, 1, 2);
    q[5] = 0x48;
    q[6] = SCE_GS_SET_CLAMP(0, 0, 0, 0, 0, 0);
    q[7] = 0x9;
    qwc += 4;

    {
        const signed int* col = rgba;
        asm {
            move i, $zero
        }
        asm {
            lqc2 $vf6, 0x0(col)
        }
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
        }
        {
            __int128* uv = ((MeshVert*)p)->uv;
            asm {
                lqc2 $vf3, 0x0(uv)
                vwaitq
                vmulq.xyzw $vf1, $vf1, $Q
                vmulq.xyz $vf3, $vf3, $Q
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
                sqc2 $vf2, 0x20(q1)
                sqc2 $vf2, 0x20(q2)
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
                    sqc2 $vf3, 0x0(q1)
                    sqc2 $vf2, 0x20(q1)
                    sqc2 $vf2, 0x20(q2)
                    vmulax.xyz $ACC, $vf20, $vf4x
                    vmadday.xyz $ACC, $vf21, $vf4y
                    vmaddz.xyz $vf4, $vf22, $vf4z
                    vmaxx.xyz $vf4, $vf4, $vf0x
                    vmove.w $vf4, $vf0
                    vmulax.xyzw $ACC, $vf24, $vf4x
                    vmadday.xyzw $ACC, $vf25, $vf4y
                    vmaddaz.xyzw $ACC, $vf26, $vf4z
                    vmaddw.xyzw $vf4, $vf27, $vf4w
                    vmr32.xyzw $vf3, $vf0
                    vmove.x $vf3, $vf4
                    vminiw.x $vf3, $vf3, $vf0w
                    vmaxx.x $vf3, $vf3, $vf0x
                    vmulq.xyz $vf3, $vf3, $Q
                    sqc2 $vf3, 0x0(q2)
                    sqc2 $vf6, 0x10(q1)
                    sqc2 $vf6, 0x10(q2)
                }
            }
        }
        verNum--;
        p += sizeof(MeshVert);
        q1 = (unsigned long*)((unsigned char*)q1 + 0x30);
        q2 = (unsigned long*)((unsigned char*)q2 + 0x30);
    } while ((signed int)verNum > 0);

    *_prim = (PrimList*)p;
    clip = qwc;
    return clip;
}
