#include "ultra64.h"

#ifdef NONMATCHING
?32 osViGetCurrentFramebuffer(void) {
    ?32 sp20;

    // Node 0
    sp20 = (?32) __osViCurr->unk4;
    __osRestoreInt(__osDisableInt());
    return;
    // (possible return value: sp20)
}
#else
GLOBAL_ASM(
.text
glabel osViGetCurrentFramebuffer
/* 00F010 7000E410 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00F014 7000E414 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00F018 7000E418 0C00617C */  jal   __osDisableInt
/* 00F01C 7000E41C AFB00018 */   sw    $s0, 0x18($sp)
/* 00F020 7000E420 3C0E8003 */  lui   $t6, %hi(__osViCurr) # $t6, 0x8003
/* 00F024 7000E424 8DCE8040 */  lw    $t6, %lo(__osViCurr)($t6)
/* 00F028 7000E428 00408025 */  move  $s0, $v0
/* 00F02C 7000E42C 02002025 */  move  $a0, $s0
/* 00F030 7000E430 8DCF0004 */  lw    $t7, 4($t6)
/* 00F034 7000E434 0C006184 */  jal   __osRestoreInt
/* 00F038 7000E438 AFAF0020 */   sw    $t7, 0x20($sp)
/* 00F03C 7000E43C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00F040 7000E440 8FA20020 */  lw    $v0, 0x20($sp)
/* 00F044 7000E444 8FB00018 */  lw    $s0, 0x18($sp)
/* 00F048 7000E448 03E00008 */  jr    $ra
/* 00F04C 7000E44C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif