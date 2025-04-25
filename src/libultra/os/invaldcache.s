# asm file.

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osInvalDCache
/* 011720 70010B20 18A0001F */  blez  $a1, .L70010BA0
/* 011724 70010B24 00000000 */   nop   
/* 011728 70010B28 240B2000 */  li    $t3, 8192
/* 01172C 70010B2C 00AB082B */  sltu  $at, $a1, $t3
/* 011730 70010B30 1020001D */  beqz  $at, .L70010BA8
/* 011734 70010B34 00000000 */   nop   
/* 011738 70010B38 00804025 */  move  $t0, $a0
/* 01173C 70010B3C 00854821 */  addu  $t1, $a0, $a1
/* 011740 70010B40 0109082B */  sltu  $at, $t0, $t1
/* 011744 70010B44 10200016 */  beqz  $at, .L70010BA0
/* 011748 70010B48 00000000 */   nop   
/* 01174C 70010B4C 310A000F */  andi  $t2, $t0, 0xf
/* 011750 70010B50 11400007 */  beqz  $t2, .L70010B70
/* 011754 70010B54 2529FFF0 */   addiu $t1, $t1, -0x10
/* 011758 70010B58 010A4023 */  subu  $t0, $t0, $t2
/* 01175C 70010B5C BD150000 */  cache 0x15, ($t0)
/* 011760 70010B60 0109082B */  sltu  $at, $t0, $t1
/* 011764 70010B64 1020000E */  beqz  $at, .L70010BA0
/* 011768 70010B68 00000000 */   nop   
/* 01176C 70010B6C 25080010 */  addiu $t0, $t0, 0x10
.L70010B70:
/* 011770 70010B70 312A000F */  andi  $t2, $t1, 0xf
/* 011774 70010B74 11400006 */  beqz  $t2, .L70010B90
/* 011778 70010B78 00000000 */   nop   
/* 01177C 70010B7C 012A4823 */  subu  $t1, $t1, $t2
/* 011780 70010B80 BD350010 */  cache 0x15, 0x10($t1)
/* 011784 70010B84 0128082B */  sltu  $at, $t1, $t0
/* 011788 70010B88 14200005 */  bnez  $at, .L70010BA0
/* 01178C 70010B8C 00000000 */   nop   
.L70010B90:
/* 011790 70010B90 BD110000 */  cache 0x11, ($t0)
/* 011794 70010B94 0109082B */  sltu  $at, $t0, $t1
/* 011798 70010B98 1420FFFD */  bnez  $at, .L70010B90
/* 01179C 70010B9C 25080010 */   addiu $t0, $t0, 0x10
.L70010BA0:
/* 0117A0 70010BA0 03E00008 */  jr    $ra
/* 0117A4 70010BA4 00000000 */   nop   

.L70010BA8:
/* 0117A8 70010BA8 3C088000 */  lui   $t0, 0x8000
/* 0117AC 70010BAC 010B4821 */  addu  $t1, $t0, $t3
/* 0117B0 70010BB0 2529FFF0 */  addiu $t1, $t1, -0x10
.L70010BB4:
/* 0117B4 70010BB4 BD010000 */  cache 1, ($t0)
/* 0117B8 70010BB8 0109082B */  sltu  $at, $t0, $t1
/* 0117BC 70010BBC 1420FFFD */  bnez  $at, .L70010BB4
/* 0117C0 70010BC0 25080010 */   addiu $t0, $t0, 0x10
/* 0117C4 70010BC4 03E00008 */  jr    $ra
/* 0117C8 70010BC8 00000000 */   nop   
.size osInvalDCache, . - osInvalDCache
