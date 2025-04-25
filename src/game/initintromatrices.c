#include <ultra64.h>
#include <memp.h>
#include "title.h"
#include "initintromatrices.h"

void alloc_intro_matrices(void)
{
    D_8002A7D0 = 0;
    matrixBufferRareLogo0     = mempAllocBytesInBank(0x80, MEMPOOL_STAGE);
    matrixBufferGunbarrel0    = mempAllocBytesInBank(0x40, MEMPOOL_STAGE);
    matrixBufferRareLogo1     = mempAllocBytesInBank(0x80, MEMPOOL_STAGE);
    matrixBufferRareLogo2     = mempAllocBytesInBank(0x80, MEMPOOL_STAGE);
    matrixBufferGunbarrel1    = mempAllocBytesInBank(0x80, MEMPOOL_STAGE);
    matrixBufferIntroBackdrop = mempAllocBytesInBank(0x80, MEMPOOL_STAGE);
    matrixBufferIntroBond     = mempAllocBytesInBank(0x80, MEMPOOL_STAGE);
}


