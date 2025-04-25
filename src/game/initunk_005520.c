#include <ultra64.h>
#include <memp.h>
#include "initunk_005520.h"
#include "objecthandler.h"
#include "memp.h"

extern s32 D_80036070;
extern s32 D_80036074;
extern s32 D_80036078;



void zero_contents_of_80036070_74(void) {
    D_80036070 = 0;
    D_80036074 = 0;
}

void set_contents_of_80036078(s32 arg0) {
    D_80036078 = arg0;
}

//this may be a file split

/**
 * NTSC address 0x7F005540.
*/
void sub_GAME_7F005540(s32 arg0)
{
    s32 temp_t6;
    s32 var_s1;

    D_80036074 = arg0 + 30;
    
    ptr_allocation_1 = mempAllocBytesInBank(D_80036074 * sizeof(struct ptr_1_s), MEMPOOL_STAGE);

    for (var_s1 = 0; var_s1 < D_80036074; var_s1++)
    {
        ptr_allocation_1[var_s1].unk08 = 0;

        if (var_s1 < arg0)
        {
            ptr_allocation_1[var_s1].unk10 = NULL;
        }
        else
        {
            ptr_allocation_1[var_s1].unk10 = mempAllocBytesInBank(0x50, MEMPOOL_STAGE);
            ptr_allocation_1[var_s1].unk02 = 0x14;
        }
    }
}


/**
 * NTSC address 0x7F005540.
*/
void sub_GAME_7F005624(s32 arg0)
{
    s32 temp_t6;
    s32 var_s1;

    D_80036070 = arg0 + 10;

    // mips2c says: ptr_allocation_0 = mempAllocBytesInBank(temp_t6 * 0xC0, 4);
    // however, the pointer is incremented by 0xbc in the loop below.
    ptr_allocation_0 = mempAllocBytesInBank(D_80036070 * (4 + sizeof(struct ptr_0_s)), MEMPOOL_STAGE);

    for (var_s1 = 0; var_s1 < D_80036070; var_s1++)
    {
        ptr_allocation_0[var_s1].unk08 = 0;

        if (var_s1 < arg0)
        {
            ptr_allocation_0[var_s1].unk10 = NULL;
        }
        else
        {
            ptr_allocation_0[var_s1].unk10 = mempAllocBytesInBank(0x230, MEMPOOL_STAGE);
            ptr_allocation_0[var_s1].unk02 = 0x8c;
        }
    }
}
