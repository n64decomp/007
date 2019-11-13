#include "ultra64.h"

#ifdef NONMATCHING
void osViSetEvent(s32 arg0, s32 arg1, ? arg2, ?32 argA, ?32 argB, s16 argC) {
    // Node 0
    __osViNext->unk10 = argA;
    __osViNext->unk14 = argB;
    __osViNext->unk2 = argC;
    __osRestoreInt(__osDisableInt());
    return;
    // (possible return value: __osRestoreInt(__osDisableInt()))
}
#else
GLOBAL_ASM(
.text
glabel osViSetEvent
/* 00E8C0 7000DCC0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00E8C4 7000DCC4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E8C8 7000DCC8 AFA40028 */  sw    $a0, 0x28($sp)
/* 00E8CC 7000DCCC AFA5002C */  sw    $a1, 0x2c($sp)
/* 00E8D0 7000DCD0 AFA60030 */  sw    $a2, 0x30($sp)
/* 00E8D4 7000DCD4 0C00617C */  jal   __osDisableInt
/* 00E8D8 7000DCD8 AFB00018 */   sw    $s0, 0x18($sp)
/* 00E8DC 7000DCDC 3C0F8003 */  lui   $t7, %hi(__osViNext) 
/* 00E8E0 7000DCE0 8DEF8044 */  lw    $t7, %lo(__osViNext)($t7)
/* 00E8E4 7000DCE4 8FAE0028 */  lw    $t6, 0x28($sp)
/* 00E8E8 7000DCE8 3C198003 */  lui   $t9, %hi(__osViNext) 
/* 00E8EC 7000DCEC 3C098003 */  lui   $t1, %hi(__osViNext) 
/* 00E8F0 7000DCF0 ADEE0010 */  sw    $t6, 0x10($t7)
/* 00E8F4 7000DCF4 8F398044 */  lw    $t9, %lo(__osViNext)($t9)
/* 00E8F8 7000DCF8 8FB8002C */  lw    $t8, 0x2c($sp)
/* 00E8FC 7000DCFC 00408025 */  move  $s0, $v0
/* 00E900 7000DD00 02002025 */  move  $a0, $s0
/* 00E904 7000DD04 AF380014 */  sw    $t8, 0x14($t9)
/* 00E908 7000DD08 8D298044 */  lw    $t1, %lo(__osViNext)($t1)
/* 00E90C 7000DD0C 8FA80030 */  lw    $t0, 0x30($sp)
/* 00E910 7000DD10 0C006184 */  jal   __osRestoreInt
/* 00E914 7000DD14 A5280002 */   sh    $t0, 2($t1)
/* 00E918 7000DD18 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00E91C 7000DD1C 8FB00018 */  lw    $s0, 0x18($sp)
/* 00E920 7000DD20 27BD0028 */  addiu $sp, $sp, 0x28
/* 00E924 7000DD24 03E00008 */  jr    $ra
/* 00E928 7000DD28 00000000 */   nop 
)
#endif