#include <ultra64.h>
#include <memp.h>
#include "title.h"
#include "initintromatrices.h"

void alloc_intro_matrices(void)
{
    D_8002A7D0 = 0;
    matrix_buffer_rarelogo_0 = mempAllocBytesInBank(0x80, 4);
    matrix_buffer_gunbarrel_0 = mempAllocBytesInBank(0x40, 4);
    matrix_buffer_rarelogo_1 = mempAllocBytesInBank(0x80, 4);
    matrix_buffer_rarelogo_2 = mempAllocBytesInBank(0x80, 4);
    matrix_buffer_gunbarrel_1 = mempAllocBytesInBank(0x80, 4);
    matrix_buffer_intro_backdrop = mempAllocBytesInBank(0x80, 4);
    matrix_buffer_intro_bond = mempAllocBytesInBank(0x80, 4);
}


