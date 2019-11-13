#include "ultra64.h"

#ifdef NONMATCHING
?32 osViGetNextFramebuffer(void) {
    ?32 sp20;

    // Node 0
    sp20 = (?32) __osViNext->unk4;
    __osRestoreInt(__osDisableInt());
    return;
    // (possible return value: sp20)
}

#else
GLOBAL_ASM(
.text
glabel osViGetNextFramebuffer
/* 00F050 7000E450 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00F054 7000E454 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00F058 7000E458 0C00617C */  jal   __osDisableInt
/* 00F05C 7000E45C AFB00018 */   sw    $s0, 0x18($sp)
/* 00F060 7000E460 3C0E8003 */  lui   $t6, %hi(__osViNext) 
/* 00F064 7000E464 8DCE8044 */  lw    $t6, %lo(__osViNext)($t6)
/* 00F068 7000E468 00408025 */  move  $s0, $v0
/* 00F06C 7000E46C 02002025 */  move  $a0, $s0
/* 00F070 7000E470 8DCF0004 */  lw    $t7, 4($t6)
/* 00F074 7000E474 0C006184 */  jal   __osRestoreInt
/* 00F078 7000E478 AFAF0020 */   sw    $t7, 0x20($sp)
/* 00F07C 7000E47C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00F080 7000E480 8FA20020 */  lw    $v0, 0x20($sp)
/* 00F084 7000E484 8FB00018 */  lw    $s0, 0x18($sp)
/* 00F088 7000E488 03E00008 */  jr    $ra
/* 00F08C 7000E48C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif