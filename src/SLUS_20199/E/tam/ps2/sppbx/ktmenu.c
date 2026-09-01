#include "common.h"
#include "types.h"

// Size: 0x3C, DWARF: 0x9DA78
typedef struct VktMenuList
{
    char text[32]; // Offset: 0x0, DWARF: 0x9DA93
    signed int x; // Offset: 0x20, DWARF: 0x9DAB6
    signed int use_num; // Offset: 0x24, DWARF: 0x9DAD4
    signed int num; // Offset: 0x28, DWARF: 0x9DAF8
    signed int num_min; // Offset: 0x2C, DWARF: 0x9DB18
    signed int num_max; // Offset: 0x30, DWARF: 0x9DB3C
    char** num_text; // Offset: 0x34, DWARF: 0x9DB60
    signed int(*menu_func)(signed int); // Offset: 0x38, DWARF: 0x9DB89
} VktMenuList;

//// Variables ///////////////////////////////////////////////////////////////////////

// Size: 0x3C, DWARF: 0x9DA78
VktMenuList vktmenuList[16]; // Address: 0x347010
signed int vktmenuNumItem; // Address: 0x2E7B00
signed int vktmenuCurrentItem; // Address: 0x2E7AFC
signed int vktmenuDispCount; // Address: 0x2E7AF8
signed int vktmenuResumable; // Address: 0x2E7AF4

//// Function Declarations ///////////////////////////////////////////////////////////

void ulpadSetRepFrame(signed int frames);

void ktmenuInit();
void ktmenuAdd(char* text, signed int x, signed int use_num, signed int num_min, signed int num_max, char** num_text, signed int(*menu_func)(signed int));

//// Function Definitions ////////////////////////////////////////////////////////////

// DWARF: 0x9E092
// Address: 0x189300
// Size: 0xA0
void ktmenuInit() {
    // Size: 0x3C, DWARF: 0x9DA78
    VktMenuList* menu; // r16
    signed int i; // r17

    vktmenuNumItem = 0;
    vktmenuCurrentItem = 0;
    vktmenuDispCount = 0;
    vktmenuResumable = 0;
    for (i = 0; i < 0x10; i++) {
        menu = &vktmenuList[i];
        menu->text[0] = 0;
        menu->x = -1;
        menu->use_num = 0;
        menu->num = 0;
        menu->num_min = 0;
        menu->num_max = 0;
        menu->num_text = 0;
        menu->menu_func = 0;
    }
    ulpadSetRepFrame(0xA);
}

// DWARF: 0x9E1C7
// Address: 0x1893A0
// Size: 0x110
void ktmenuAdd(char* text, signed int x, signed int use_num, signed int num_min, signed int num_max, char** num_text, signed int(*menu_func)(signed int)) {
    s32 tmp;
    signed int i; // r16
    // Size: 0x3C, DWARF: 0x9DA78
    VktMenuList* menu; // r17

    menu = &vktmenuList[vktmenuNumItem];
    vktmenuNumItem += 1;
    for (i = 0; i < 0x1F; i++) {

        menu->text[i] = text[i];
        if (text[i] == 0) {
            break;
        }
    }
    menu->text[i] = 0;
    menu->x = x;
    menu->use_num = use_num;
    if (use_num) {
        tmp = num_min;
    } else {
        tmp = 0;
    }
    menu->num = tmp;
    menu->num_min = num_min;
    menu->num_max = num_max;
    menu->num_text = num_text;
    menu->menu_func = menu_func;
}
