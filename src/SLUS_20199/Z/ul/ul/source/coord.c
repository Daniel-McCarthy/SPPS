#include "common.h"
#include "types.h"

typedef float sceVu0FVECTOR[4] __attribute__((aligned(16)));
typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

// coord.c structs //////////////////////////////////////////////////////////////////

// Size: 0x90
typedef struct tag_ulcodCOORDINATE
{
    struct tag_ulcodCOORDINATE* super; // Offset: 0x0
    unsigned int flag; // Offset: 0x4
    unsigned int id; // Offset: 0x8
    signed int parent; // Offset: 0xC
    sceVu0FMATRIX mat; // Offset: 0x10
    sceVu0FMATRIX tmp; // Offset: 0x50
} ulcodCOORDINATE;

//// Globals ////////////////////////////////////////////////////////////////////////

sceVu0FMATRIX vulcodVSmat; // Address: 0x2F2390
sceVu0FMATRIX vulcodWVmat; // Address: 0x2F2350
ulcodCOORDINATE* vulcodCamera; // Address: 0x2E79D8

//// Function Declarations //////////////////////////////////////////////////////////

void sceVu0UnitMatrix(sceVu0FMATRIX m0);
void sceVu0CopyMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1);
void sceVu0MulMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1, sceVu0FMATRIX m2);
void sceVu0InversMatrix(sceVu0FMATRIX m0, sceVu0FMATRIX m1);

void ulcodInitCoordinate(ulcodCOORDINATE* coord, ulcodCOORDINATE* super);
void ulcodLinkCoordinate(ulcodCOORDINATE* coord, ulcodCOORDINATE* super);
void ulcodSetVsMatrix(sceVu0FMATRIX vs);
void ulcodGetWvMatrix(sceVu0FMATRIX mat);
void ulcodSetWvMatrix(sceVu0FMATRIX wv);
signed int ulcodGetLwMatrix(sceVu0FMATRIX mat, ulcodCOORDINATE* coord);
void ulcodGetWsMatrix(sceVu0FMATRIX mat);

//// Functions //////////////////////////////////////////////////////////////////////

void ulcodInitCoordinate(ulcodCOORDINATE* coord, ulcodCOORDINATE* super)
{
    sceVu0UnitMatrix(coord->mat);
    coord->id = 0;
    coord->parent = 0;

    ulcodLinkCoordinate(coord, super);
}

void ulcodLinkCoordinate(ulcodCOORDINATE* coord, ulcodCOORDINATE* super)
{
    sceVu0UnitMatrix(coord->tmp);
    coord->super = super;
    coord->flag = 0;
}

void ulcodSetVsMatrix(sceVu0FMATRIX vs)
{
    sceVu0CopyMatrix(vulcodVSmat, vs);
}

void ulcodGetWvMatrix(sceVu0FMATRIX mat)
{
    sceVu0FMATRIX vw;

    if (vulcodCamera && ulcodGetLwMatrix(vw, vulcodCamera)) {
        sceVu0InversMatrix(vulcodWVmat, vw);
    }
    sceVu0CopyMatrix(mat, vulcodWVmat);
}

void ulcodSetWvMatrix(sceVu0FMATRIX wv)
{
    vulcodCamera = 0;
    sceVu0CopyMatrix(vulcodWVmat, wv);
}

signed int ulcodGetLwMatrix(sceVu0FMATRIX mat, ulcodCOORDINATE* coord)
{
    signed int ret = 0;

    if (coord->super == 0) {
        if (coord->flag == 0) {
            sceVu0CopyMatrix(coord->tmp, coord->mat);
            coord->flag = 0;
            ret = 1;
        }
    } else {
        if (ulcodGetLwMatrix(0, coord->super) || coord->flag == 0) {
            sceVu0MulMatrix(coord->tmp, coord->super->tmp, coord->mat);
            coord->flag = 0;
            ret = 1;
        }
    }

    if (mat) {
        sceVu0CopyMatrix(mat, coord->tmp);
    }
    return ret;
}

void ulcodGetWsMatrix(sceVu0FMATRIX mat)
{
    sceVu0FMATRIX wv;

    ulcodGetWvMatrix(wv);
    sceVu0MulMatrix(mat, vulcodVSmat, wv);
}
