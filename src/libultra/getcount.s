# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osGetCount
/* 00E4E0 7000D8E0 40024800 */  mfc0  $v0, $9
/* 00E4E4 7000D8E4 03E00008 */  jr    $ra
/* 00E4E8 7000D8E8 00000000 */   nop   
