#include "libultra_internal.h"

s32 __osAtomicDec(u32 *a0)
{
    s32 sp1c;
    s32 sp18;
    //  addiu $sp, $sp, -0x20
    //  sw    $ra, 0x14($sp)
    //  jal   __osDisableInt
    //   sw    $a0, 0x20($sp)
    sp1c = __osDisableInt();
    //  lw    $t6, 0x20($sp)
    //  sw    $v0, 0x1c($sp)
    //  lw    $t7, ($t6)
    //  beqz  $t7, .L8032A2F8
    //   nop
    if(*a0 != 0){
    //  addiu $t8, $t7, -1
    //  sw    $t8, ($t6)
    //  li    $t9, 1
    //  b     .L8032A2FC
    //   sw    $t9, 0x18($sp)
    (*a0)--;
    sp18 = 1;
    }else{
    //.L8032A2F8:
    //  sw    $zero, 0x18($sp)
    sp18 = 0;
    }
    //.L8032A2FC:
    //  jal   __osRestoreInt
    //   lw    $a0, 0x1c($sp)
    __osRestoreInt(sp1c);
    //  lw    $ra, 0x14($sp)
    //  lw    $v0, 0x18($sp)
    //  addiu $sp, $sp, 0x20
    //  jr    $ra
    //   nop
    return sp18;

    //  nop
    //  nop
}
