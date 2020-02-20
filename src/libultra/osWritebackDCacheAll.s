# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"
glabel osWritebackDCacheAll
/* 00DF20 7000D320 3C088000 */  lui   $t0, 0x8000
/* 00DF24 7000D324 240A2000 */  li    $t2, 8192
/* 00DF28 7000D328 010A4821 */  addu  $t1, $t0, $t2
/* 00DF2C 7000D32C 2529FFF0 */  addiu $t1, $t1, -0x10
.L7000D330:
/* 00DF30 7000D330 BD010000 */  cache 1, ($t0)
/* 00DF34 7000D334 0109082B */  sltu  $at, $t0, $t1
/* 00DF38 7000D338 1420FFFD */  bnez  $at, .L7000D330
/* 00DF3C 7000D33C 25080010 */   addiu $t0, $t0, 0x10
/* 00DF40 7000D340 03E00008 */  jr    $ra
/* 00DF44 7000D344 00000000 */   nop   
