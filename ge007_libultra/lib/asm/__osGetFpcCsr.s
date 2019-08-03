.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"

#s32 __osGetFpcCsr(void)

.section .text, "ax" 

glabel __osGetFpcCsr
/* 00E010 7000D410 4442F800 */  cfc1  $v0, $31
/* 00E014 7000D414 03E00008 */  jr    $ra
/* 00E018 7000D418 00000000 */   nop

