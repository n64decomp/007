# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel __osSetFpcCsr
/* 00E020 7000D420 4442F800 */  cfc1  $v0, $31
/* 00E024 7000D424 44C4F800 */  ctc1  $a0, $31
/* 00E028 7000D428 03E00008 */  jr    $ra
/* 00E02C 7000D42C 00000000 */   nop   
