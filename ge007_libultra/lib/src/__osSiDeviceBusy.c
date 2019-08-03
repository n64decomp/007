#include "libultra_internal.h"
#include "hardware.h"
s32 __osSiDeviceBusy()
{
    register u32 status;
    //  lui   $t6, %hi(D_A4800018) # $t6, 0xa480
    //  lw    $a0, %lo(D_A4800018)($t6)
    //  addiu $sp, $sp, -8
    //  andi  $t7, $a0, 3
    //  beqz  $t7, .L8032A110
    //   nop
    status = HW_REG(SI_STATUS_REG, u32);
    if (status & (SI_STATUS_DMA_BUSY | SI_STATUS_IO_READ_BUSY))
    {
        return 1;
    }
    else
    {

        return 0;
    }
    //  b     .L8032A114
    //   li    $v0, 1
    //.L8032A110:
    //  move  $v0, $zero
    //.L8032A114:
    //  jr    $ra
    //   addiu $sp, $sp, 8

    //  nop
}
