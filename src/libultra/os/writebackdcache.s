# asm file.

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osWritebackDCache
/* 0117D0 70010BD0 18A00011 */  blez  $a1, .L70010C18
/* 0117D4 70010BD4 00000000 */   nop   
/* 0117D8 70010BD8 240B2000 */  li    $t3, 8192
/* 0117DC 70010BDC 00AB082B */  sltu  $at, $a1, $t3
/* 0117E0 70010BE0 1020000F */  beqz  $at, .L70010C20
/* 0117E4 70010BE4 00000000 */   nop   
/* 0117E8 70010BE8 00804025 */  move  $t0, $a0
/* 0117EC 70010BEC 00854821 */  addu  $t1, $a0, $a1
/* 0117F0 70010BF0 0109082B */  sltu  $at, $t0, $t1
/* 0117F4 70010BF4 10200008 */  beqz  $at, .L70010C18
/* 0117F8 70010BF8 00000000 */   nop   
/* 0117FC 70010BFC 310A000F */  andi  $t2, $t0, 0xf
/* 011800 70010C00 2529FFF0 */  addiu $t1, $t1, -0x10
/* 011804 70010C04 010A4023 */  subu  $t0, $t0, $t2
.L70010C08:
/* 011808 70010C08 BD190000 */  cache 0x19, ($t0)
/* 01180C 70010C0C 0109082B */  sltu  $at, $t0, $t1
/* 011810 70010C10 1420FFFD */  bnez  $at, .L70010C08
/* 011814 70010C14 25080010 */   addiu $t0, $t0, 0x10
.L70010C18:
/* 011818 70010C18 03E00008 */  jr    $ra
/* 01181C 70010C1C 00000000 */   nop   

.L70010C20:
/* 011820 70010C20 3C088000 */  lui   $t0, 0x8000
/* 011824 70010C24 010B4821 */  addu  $t1, $t0, $t3
/* 011828 70010C28 2529FFF0 */  addiu $t1, $t1, -0x10
.L70010C2C:
/* 01182C 70010C2C BD010000 */  cache 1, ($t0)
/* 011830 70010C30 0109082B */  sltu  $at, $t0, $t1
/* 011834 70010C34 1420FFFD */  bnez  $at, .L70010C2C
/* 011838 70010C38 25080010 */   addiu $t0, $t0, 0x10
/* 01183C 70010C3C 03E00008 */  jr    $ra
/* 011840 70010C40 00000000 */   nop   
