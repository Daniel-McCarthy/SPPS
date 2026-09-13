#include "common.h"

typedef struct DataHead {
	char magic[4];
	signed int ver;
	signed int num;
	signed int res;
} DataHead;

typedef struct DataBlock {
	signed int addr;
	signed int size;
	signed int res[2];
} DataBlock;

typedef struct Data {
	DataHead* head;
	DataBlock* block;
} Data;

void tmlinkMappingData(unsigned int addr, Data* data) {
	signed int ii;

	data->head = (DataHead*)addr;
	data->block = (DataBlock*)(addr + 0x10);
	for (ii = 0; ii < data->head->num; ii++) {
		data->block[ii].addr += addr;
	}
}
