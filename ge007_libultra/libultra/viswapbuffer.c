#include "ultra64.h"

#ifdef NONMATCHING
void osViSwapBuffer(s32 arg0, ?32 arg8) {
    s32 sp1C;

    // Node 0
    sp1C = __osDisableInt();
    __osViNext->unk4 = arg8;
    *__osViNext = (s16) (*__osViNext | 0x10);
    __osRestoreInt(sp1C);
    return;
    // (possible return value: __osRestoreInt(sp1C))
}

#else
GLOBAL_ASM(
.text
glabel osViSwapBuffer
/* 00F090 7000E490 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00F094 7000E494 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00F098 7000E498 0C00617C */  jal   __osDisableInt
/* 00F09C 7000E49C AFA40020 */   sw    $a0, 0x20($sp)
/* 00F0A0 7000E4A0 3C0F8003 */  lui   $t7, %hi(__osViNext) # $t7, 0x8003
/* 00F0A4 7000E4A4 8DEF8044 */  lw    $t7, %lo(__osViNext)($t7)
/* 00F0A8 7000E4A8 8FAE0020 */  lw    $t6, 0x20($sp)
/* 00F0AC 7000E4AC AFA2001C */  sw    $v0, 0x1c($sp)
/* 00F0B0 7000E4B0 3C188003 */  lui   $t8, %hi(__osViNext) # $t8, 0x8003
/* 00F0B4 7000E4B4 ADEE0004 */  sw    $t6, 4($t7)
/* 00F0B8 7000E4B8 8F188044 */  lw    $t8, %lo(__osViNext)($t8)
/* 00F0BC 7000E4BC 97190000 */  lhu   $t9, ($t8)
/* 00F0C0 7000E4C0 37280010 */  ori   $t0, $t9, 0x10
/* 00F0C4 7000E4C4 A7080000 */  sh    $t0, ($t8)
/* 00F0C8 7000E4C8 0C006184 */  jal   __osRestoreInt
/* 00F0CC 7000E4CC 8FA4001C */   lw    $a0, 0x1c($sp)
/* 00F0D0 7000E4D0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00F0D4 7000E4D4 27BD0020 */  addiu $sp, $sp, 0x20
/* 00F0D8 7000E4D8 03E00008 */  jr    $ra
/* 00F0DC 7000E4DC 00000000 */   nop   
)
#endif