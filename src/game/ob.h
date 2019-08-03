#ifndef _OB_H_
#define _OB_H_
#include "ultra64.h"

struct fileentry {
    s32 index;
    char *filename;
    void *size;
};

void something_mem_bank_a0(int);
void sub_GAME_7F0BD234(void);

#endif
