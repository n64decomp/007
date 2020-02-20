# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"   

glabel __osGetTLBHi
/* 00F480 7000E880 40840000 */  mtc0  $a0, $0
/* 00F484 7000E884 00000000 */  nop   
/* 00F488 7000E888 42000001 */  tlbr  
/* 00F48C 7000E88C 00000000 */  nop   
/* 00F490 7000E890 00000000 */  nop   
/* 00F494 7000E894 00000000 */  nop   
/* 00F498 7000E898 40025000 */  mfc0  $v0, $10
/* 00F49C 7000E89C 03E00008 */  jr    $ra
/* 00F4A0 7000E8A0 00000000 */   nop   

