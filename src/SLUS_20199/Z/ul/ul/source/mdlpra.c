#include "common.h"
#include "types.h"

// mdlpra.c structs ////////////////////////////////////////////////////////////////////

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

// Size: 0x30
typedef struct AlphaVert
{
    __int128 uv; // Offset: 0x0
    __int128 color; // Offset: 0x10
    __int128 pos; // Offset: 0x20
} AlphaVert;

// Size: 0x60
typedef struct AlphaVertPair
{
    AlphaVert v[2]; // Offset: 0x0
} AlphaVertPair;

// Size: 0x10, DWARF: 0x3FE9C
typedef struct ATag
{
    unsigned int dmatag; // Offset: 0x0
    unsigned int addr; // Offset: 0x4
    unsigned int z; // Offset: 0x8
    unsigned int _pad; // Offset: 0xC
} ATag;

// Size: 0x20, DWARF: 0x3FB40
typedef struct Alpha
{
    unsigned int maxatag; // Offset: 0x0
    unsigned int natag; // Offset: 0x4
    unsigned int maxpkt; // Offset: 0x8
    unsigned int npkt; // Offset: 0xC
    ATag* atag; // Offset: 0x10
    ATag* curatag; // Offset: 0x14
    __int128* pkt; // Offset: 0x18
    __int128* curpkt; // Offset: 0x1C
} Alpha;

// Only the field this file reads is known; the rest of the struct is unmapped.
typedef struct DrawInfo
{
    unsigned char pad[0x160]; // Offset: 0x0
    unsigned short alphaMode; // Offset: 0x160
} DrawInfo;

void ulgraphAlphaClosePacket(Alpha* alpha, signed int qwc, unsigned int ave_z);

// Address: 0x130430
void ulmdlPrimPhysiqueStripGTalpha(Alpha* abuf, PrimList** _prim, DrawInfo* dinfo) {
    unsigned int z; // a2
    unsigned long test; // reg65535
    unsigned long alpha; // s2
    AlphaVert qdata[3]; // sp+0xa0
    signed int i; // s1
    unsigned int flag; // s0
    unsigned int nver; // s7
    unsigned long tex0; // s3
    unsigned long* q; // a0
    unsigned char* p; // reg65535
    PrimList* prim; // a1

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    flag = 0;
    nver = prim->verNum;
    alpha = (((unsigned long)dinfo->alphaMode & 0xFF00) << 24) | (unsigned long)(dinfo->alphaMode & 0xFF);
    test = ((alpha & 0xCF) == 0x48) ? 0x51001UL : 0x50000UL;
    tex0 = prim->tex0;

    for (i = 0; i < nver; i++) {
        AlphaVert* qbase = qdata;
        __int128* pos = ((PhysiqueVert*)p)->pos;
        asm {
            lqc2 $vf1, 0x0(pos)
            vmulax.xyzw $ACC, $vf28, $vf1x
            vmadday.xyzw $ACC, $vf29, $vf1y
            vmaddaz.xyzw $ACC, $vf30, $vf1z
            vmaddw.xyzw $vf1, $vf31, $vf1w
            vdiv $Q, $vf0w, $vf1w
            vwaitq
            vmulq.xyzw $vf1, $vf1, $Q
            vftoi4.xyzw $vf2, $vf1
            sqc2 $vf2, 0x80(qbase)
        }
        {
            __int128* uv = ((PhysiqueVert*)p)->uv;
            asm {
                lqc2 $vf3, 0x0(uv)
                vmulq.xyz $vf3, $vf3, $Q
                sqc2 $vf3, 0x60(qbase)
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
        flag <<= 1;
        flag &= 6;
        {
            signed int clip;
            asm {
                cfc2.ni clip, $vi16
            }
            clip &= 0xC0;
            if (clip) {
                flag |= 1;
            }
        }
        {
            __int128* normal = ((PhysiqueVert*)p)->normal;
            asm {
                lqc2 $vf4, 0x0(normal)
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
                vminix.xyzw $vf5, $vf5, $vf11x
                vftoi0.xyzw $vf5, $vf5
                sqc2 $vf5, 0x70(qbase)
            }
        }
        if (i >= 2 && flag == 0) {
            q = (unsigned long*)abuf->curpkt;
            q[0] = 0xD12E400000008001;
            q[1] = 0xE4124124127EE;
            q[2] = test;
            q[3] = 0x48;
            q[4] = alpha;
            q[5] = 0x43;
            q[6] = tex0;
            q[7] = 0;
            {
                AlphaVert* dst = (AlphaVert*)&q[8];
                AlphaVert* src = qdata;
                asm {
                    lq $v1, 0x20(src)
                    sq $v1, 0x20(dst)
                    lq $v0, 0x50(src)
                    sq $v0, 0x50(dst)
                    padduw $v1, $v1, $v0
                    lq $v0, 0x80(src)
                    sq $v0, 0x80(dst)
                    padduw $v1, $v1, $v0
                    pexew $v1, $v1
                    lui $at, 0x5555
                    ori $v0, $at, 0x5555
                    mult $zero, $v0, $v1
                    lq $v0, 0x0(src)
                    sq $v0, 0x0(dst)
                    lq $v0, 0x10(src)
                    sq $v0, 0x10(dst)
                    lq $v0, 0x30(src)
                    sq $v0, 0x30(dst)
                    lq $v0, 0x40(src)
                    sq $v0, 0x40(dst)
                    lq $v0, 0x60(src)
                    sq $v0, 0x60(dst)
                    lq $v0, 0x70(src)
                    sq $v0, 0x70(dst)
                    mfhi z
                }
            }
            q[26] = 0x50000;
            q[27] = 0x48;
            ulgraphAlphaClosePacket(abuf, 0xE, z);
        }
        qdata[0].uv = qdata[1].uv;
        qdata[0].color = qdata[1].color;
        qdata[0].pos = qdata[1].pos;
        qdata[1].uv = qdata[2].uv;
        qdata[1].color = qdata[2].color;
        qdata[1].pos = qdata[2].pos;
        p += 0x20;
    }
    *_prim = (PrimList*)p;
}

// Address: 0x130710
void ulmdlPrimMeshStripGTalpha(Alpha* abuf, PrimList** _prim, DrawInfo* dinfo) {
    unsigned int z; // a2
    unsigned long test; // reg65535
    unsigned long alpha; // s2
    AlphaVert qdata[3]; // sp+0xa0
    signed int i; // s1
    unsigned int flag; // s0
    unsigned int nver; // s7
    unsigned long tex0; // s3
    unsigned long* q; // a0
    unsigned char* p; // reg65535
    PrimList* prim; // a1

    prim = *_prim;
    p = (unsigned char*)prim + 0x10;
    flag = 0;
    nver = prim->verNum;
    alpha = (((unsigned long)dinfo->alphaMode & 0xFF00) << 24) | (unsigned long)(dinfo->alphaMode & 0xFF);
    test = ((alpha & 0xCF) == 0x48) ? 0x51001UL : 0x50000UL;
    tex0 = prim->tex0;

    for (i = 0; i < nver; i++) {
        AlphaVert* qbase = qdata;
        __int128* pos = ((MeshVert*)p)->pos;
        asm {
            lqc2 $vf1, 0x0(pos)
            vmulax.xyzw $ACC, $vf28, $vf1x
            vmadday.xyzw $ACC, $vf29, $vf1y
            vmaddaz.xyzw $ACC, $vf30, $vf1z
            vmaddw.xyzw $vf1, $vf31, $vf1w
            vdiv $Q, $vf0w, $vf1w
            vwaitq
            vmulq.xyzw $vf1, $vf1, $Q
            vftoi4.xyzw $vf2, $vf1
            sqc2 $vf2, 0x80(qbase)
        }
        {
            __int128* uv = ((MeshVert*)p)->uv;
            asm {
                lqc2 $vf3, 0x0(uv)
                vmulq.xyz $vf3, $vf3, $Q
                sqc2 $vf3, 0x60(qbase)
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
        flag <<= 1;
        flag &= 6;
        {
            signed int clip;
            asm {
                cfc2.ni clip, $vi16
            }
            clip &= 0xC0;
            if (clip) {
                flag |= 1;
            }
        }
        {
            __int128* normal = ((MeshVert*)p)->normal;
            asm {
                lqc2 $vf4, 0x0(normal)
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
                vminix.xyzw $vf5, $vf5, $vf11x
                vftoi0.xyzw $vf5, $vf5
                sqc2 $vf5, 0x70(qbase)
            }
        }
        if (i >= 2 && flag == 0) {
            q = (unsigned long*)abuf->curpkt;
            q[0] = 0xD12E400000008001;
            q[1] = 0xE4124124127EE;
            q[2] = test;
            q[3] = 0x48;
            q[4] = alpha;
            q[5] = 0x43;
            q[6] = tex0;
            q[7] = 0;
            {
                AlphaVert* dst = (AlphaVert*)&q[8];
                AlphaVert* src = qdata;
                asm {
                    lq $v1, 0x20(src)
                    sq $v1, 0x20(dst)
                    lq $v0, 0x50(src)
                    sq $v0, 0x50(dst)
                    padduw $v1, $v1, $v0
                    lq $v0, 0x80(src)
                    sq $v0, 0x80(dst)
                    padduw $v1, $v1, $v0
                    pexew $v1, $v1
                    lui $at, 0x5555
                    ori $v0, $at, 0x5555
                    mult $zero, $v0, $v1
                    lq $v0, 0x0(src)
                    sq $v0, 0x0(dst)
                    lq $v0, 0x10(src)
                    sq $v0, 0x10(dst)
                    lq $v0, 0x30(src)
                    sq $v0, 0x30(dst)
                    lq $v0, 0x40(src)
                    sq $v0, 0x40(dst)
                    lq $v0, 0x60(src)
                    sq $v0, 0x60(dst)
                    lq $v0, 0x70(src)
                    sq $v0, 0x70(dst)
                    mfhi z
                }
            }
            q[26] = 0x50000;
            q[27] = 0x48;
            ulgraphAlphaClosePacket(abuf, 0xE, z);
        }
        qdata[0].uv = qdata[1].uv;
        qdata[0].color = qdata[1].color;
        qdata[0].pos = qdata[1].pos;
        qdata[1].uv = qdata[2].uv;
        qdata[1].color = qdata[2].color;
        qdata[1].pos = qdata[2].pos;
        p += 0x10;
    }
    *_prim = (PrimList*)p;
}
