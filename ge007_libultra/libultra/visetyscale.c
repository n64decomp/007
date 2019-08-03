#include "ultra64.h"

#ifdef NONMATCHING
void osViSetYScale(f32 arg0, f32 argA) {
    // Node 0
    __osViNext->unk24 = argA;
    *__osViNext = (s16) (*__osViNext | 4);
    __osRestoreInt(__osDisableInt());
    return;
    // (possible return value: __osRestoreInt(__osDisableInt()))
}

#else
GLOBAL_ASM(
.text
glabel osViSetYScale
/* 00EE00 7000E200 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00EE04 7000E204 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00EE08 7000E208 E7AC0028 */  swc1  $f12, 0x28($sp)
/* 00EE0C 7000E20C 0C00617C */  jal   __osDisableInt
/* 00EE10 7000E210 AFB00018 */   sw    $s0, 0x18($sp)
/* 00EE14 7000E214 3C0E8003 */  lui   $t6, %hi(__osViNext) # $t6, 0x8003
/* 00EE18 7000E218 8DCE8044 */  lw    $t6, %lo(__osViNext)($t6)
/* 00EE1C 7000E21C C7A40028 */  lwc1  $f4, 0x28($sp)
/* 00EE20 7000E220 3C0F8003 */  lui   $t7, %hi(__osViNext) # $t7, 0x8003
/* 00EE24 7000E224 00408025 */  move  $s0, $v0
/* 00EE28 7000E228 E5C40024 */  swc1  $f4, 0x24($t6)
/* 00EE2C 7000E22C 8DEF8044 */  lw    $t7, %lo(__osViNext)($t7)
/* 00EE30 7000E230 02002025 */  move  $a0, $s0
/* 00EE34 7000E234 95F80000 */  lhu   $t8, ($t7)
/* 00EE38 7000E238 37190004 */  ori   $t9, $t8, 4
/* 00EE3C 7000E23C 0C006184 */  jal   __osRestoreInt
/* 00EE40 7000E240 A5F90000 */   sh    $t9, ($t7)
/* 00EE44 7000E244 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00EE48 7000E248 8FB00018 */  lw    $s0, 0x18($sp)
/* 00EE4C 7000E24C 27BD0028 */  addiu $sp, $sp, 0x28
/* 00EE50 7000E250 03E00008 */  jr    $ra
/* 00EE54 7000E254 00000000 */   nop  
)
#endif