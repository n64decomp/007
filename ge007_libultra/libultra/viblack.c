#include "ultra64.h"

#ifdef NONMATCHING
void osViBlack(s32 arg0, s32 argA) {
    // Node 0
    if (argA != 0)
    {
        // Node 1
        *__osViNext = (s16) (*__osViNext | 0x20);
    }
    else
    {
        // Node 2
        *__osViNext = (s16) (*__osViNext & -0x21);
    }
    // Node 3
    __osRestoreInt(__osDisableInt());
    return;
    // (possible return value: __osRestoreInt(__osDisableInt()))
}

#else
GLOBAL_ASM(
.text
glabel osViBlack
/* 00EED0 7000E2D0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00EED4 7000E2D4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00EED8 7000E2D8 AFA40028 */  sw    $a0, 0x28($sp)
/* 00EEDC 7000E2DC 0C00617C */  jal   __osDisableInt
/* 00EEE0 7000E2E0 AFB00018 */   sw    $s0, 0x18($sp)
/* 00EEE4 7000E2E4 93AE002B */  lbu   $t6, 0x2b($sp)
/* 00EEE8 7000E2E8 00408025 */  move  $s0, $v0
/* 00EEEC 7000E2EC 11C00007 */  beqz  $t6, .L7000E30C
/* 00EEF0 7000E2F0 00000000 */   nop   
/* 00EEF4 7000E2F4 3C0F8003 */  lui   $t7, %hi(__osViNext) 
/* 00EEF8 7000E2F8 8DEF8044 */  lw    $t7, %lo(__osViNext)($t7)
/* 00EEFC 7000E2FC 95F80000 */  lhu   $t8, ($t7)
/* 00EF00 7000E300 37190020 */  ori   $t9, $t8, 0x20
/* 00EF04 7000E304 10000007 */  b     .L7000E324
/* 00EF08 7000E308 A5F90000 */   sh    $t9, ($t7)
.L7000E30C:
/* 00EF0C 7000E30C 3C088003 */  lui   $t0, %hi(__osViNext) 
/* 00EF10 7000E310 8D088044 */  lw    $t0, %lo(__osViNext)($t0)
/* 00EF14 7000E314 2401FFDF */  li    $at, -33
/* 00EF18 7000E318 95090000 */  lhu   $t1, ($t0)
/* 00EF1C 7000E31C 01215024 */  and   $t2, $t1, $at
/* 00EF20 7000E320 A50A0000 */  sh    $t2, ($t0)
.L7000E324:
/* 00EF24 7000E324 0C006184 */  jal   __osRestoreInt
/* 00EF28 7000E328 02002025 */   move  $a0, $s0
/* 00EF2C 7000E32C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00EF30 7000E330 8FB00018 */  lw    $s0, 0x18($sp)
/* 00EF34 7000E334 27BD0028 */  addiu $sp, $sp, 0x28
/* 00EF38 7000E338 03E00008 */  jr    $ra
/* 00EF3C 7000E33C 00000000 */   nop   
)
#endif