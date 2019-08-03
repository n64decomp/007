#include "ultra64.h"

#ifdef NONMATCHING
void osViSetMode(s32 arg0, ?32 argA) {
    // Node 0
    __osViNext->unk8 = argA;
    *__osViNext = (u16)1;
    __osViNext->unkC = (?32) __osViNext->unk8->unk4;
    __osRestoreInt(__osDisableInt());
    return;
    // (possible return value: __osRestoreInt(__osDisableInt()))
}
#else
GLOBAL_ASM(
.text
glabel osViSetMode
/* 00EC60 7000E060 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00EC64 7000E064 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00EC68 7000E068 AFA40028 */  sw    $a0, 0x28($sp)
/* 00EC6C 7000E06C 0C00617C */  jal   __osDisableInt
/* 00EC70 7000E070 AFB00018 */   sw    $s0, 0x18($sp)
/* 00EC74 7000E074 3C0F8003 */  lui   $t7, %hi(__osViNext) # $t7, 0x8003
/* 00EC78 7000E078 8DEF8044 */  lw    $t7, %lo(__osViNext)($t7)
/* 00EC7C 7000E07C 8FAE0028 */  lw    $t6, 0x28($sp)
/* 00EC80 7000E080 3C198003 */  lui   $t9, %hi(__osViNext) # $t9, 0x8003
/* 00EC84 7000E084 24180001 */  li    $t8, 1
/* 00EC88 7000E088 ADEE0008 */  sw    $t6, 8($t7)
/* 00EC8C 7000E08C 8F398044 */  lw    $t9, %lo(__osViNext)($t9)
/* 00EC90 7000E090 3C088003 */  lui   $t0, %hi(__osViNext) # $t0, 0x8003
/* 00EC94 7000E094 00408025 */  move  $s0, $v0
/* 00EC98 7000E098 A7380000 */  sh    $t8, ($t9)
/* 00EC9C 7000E09C 8D088044 */  lw    $t0, %lo(__osViNext)($t0)
/* 00ECA0 7000E0A0 02002025 */  move  $a0, $s0
/* 00ECA4 7000E0A4 8D090008 */  lw    $t1, 8($t0)
/* 00ECA8 7000E0A8 8D2A0004 */  lw    $t2, 4($t1)
/* 00ECAC 7000E0AC 0C006184 */  jal   __osRestoreInt
/* 00ECB0 7000E0B0 AD0A000C */   sw    $t2, 0xc($t0)
/* 00ECB4 7000E0B4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00ECB8 7000E0B8 8FB00018 */  lw    $s0, 0x18($sp)
/* 00ECBC 7000E0BC 27BD0028 */  addiu $sp, $sp, 0x28
/* 00ECC0 7000E0C0 03E00008 */  jr    $ra
/* 00ECC4 7000E0C4 00000000 */   nop   
)
#endif