#include "common.h"
#include "types.h"

// Pragma //////////////////////////////////////////////////////////////////////////////
#pragma mpwc_relax on // Allows conversion from matrix to float** and vector to float* types.
#pragma fast_fptosi on // Prevent calling fptosi on float to int conversions.

// C function includes
int strlen(const char* s);

// DWARF: 0x3F5B8
// Address: 0x141B70
signed int ulstrAsciitoSjis(char* sjis /* 0x90(r29) */, char* ascii /* 0xA0(r29) */) {
    char tmp; // s0
    signed int no; // s1
    signed int ii; // s2
    signed int len; // s3
    char codelist[33] = { // 0x60(r29)
        '@', 'I', 'h', 0x94, 0x90, 0x93, 0x95, 'f', 'i', 'j', 0x96,
        '{', 'C', '|', 'D', '^', 'F', 'G', 0x83, 0x81, 0x84, 'H',
        0x97, 'm', 0x8F, 0x8E, 'O', 'Q', 'e', 'o', 'b', 'p', '`'
    };
    s32* codelist_ptr = &codelist; // s4

    len = strlen(ascii);
    for (ii = 0; ii < len; ii++) {
        tmp = ascii[ii];
        no = ii << 1;
        if ((tmp >= 0x30) && (tmp < 0x3A)) {
            sjis[no] = 0x82;
            sjis[no + 1] = (tmp + 0x1F);
        } else if ((tmp >= 0x41) && (tmp < 0x5B)) {
            sjis[no] = 0x82;
            sjis[no + 1] = (tmp + 0x1F);
        } else if ((tmp >= 0x61) && (tmp < 0x7B)) {
            sjis[no] = 0x82;
            sjis[no + 1] = (tmp + 0x20);
        } else {
            sjis[no] = 0x81;
            no++;
            if ((tmp >= 0x20) && (tmp < 0x30)) {
                sjis[no] = codelist[tmp - 0x20];
            } else if ((tmp >= 0x3A) && (tmp < 0x41)) {
                sjis[no] = codelist[tmp - 0x2A];
            } else if ((tmp >= 0x5B) && (tmp < 0x61)) {
                sjis[no] = codelist[tmp - 0x44];
            } else if ((tmp >= 0x7B) && (tmp < 0x7F)) {
                sjis[no] = codelist[tmp - 0x5E];
            } else {
                sjis[no] = 0x40;
            }
        }
    }
    sjis[len * 2] = 0;
    return len;
}
