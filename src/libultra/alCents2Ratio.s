# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel alCents2Ratio
/* 0143C0 700137C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0143C4 700137C4 44811000 */  mtc1  $at, $f2
/* 0143C8 700137C8 04800004 */  bltz  $a0, .L700137DC
/* 0143CC 700137CC 3C018003 */   lui   $at, %hi(F32_800296E4)
/* 0143D0 700137D0 3C018003 */  lui   $at, %hi(F32_800296E0)
/* 0143D4 700137D4 10000003 */  b     .L700137E4
/* 0143D8 700137D8 C42096E0 */   lwc1  $f0, %lo(F32_800296E0)($at)
.L700137DC:
/* 0143DC 700137DC C42096E4 */  lwc1  $f0, %lo(F32_800296E4)($at)
/* 0143E0 700137E0 00042023 */  negu  $a0, $a0
.L700137E4:
/* 0143E4 700137E4 10800008 */  beqz  $a0, .L70013808
.L700137E8:
/* 0143E8 700137E8 308E0001 */   andi  $t6, $a0, 1
/* 0143EC 700137EC 11C00003 */  beqz  $t6, .L700137FC
/* 0143F0 700137F0 00047843 */   sra   $t7, $a0, 1
/* 0143F4 700137F4 46001082 */  mul.s $f2, $f2, $f0
/* 0143F8 700137F8 00000000 */  nop   
.L700137FC:
/* 0143FC 700137FC 46000002 */  mul.s $f0, $f0, $f0
/* 014400 70013800 15E0FFF9 */  bnez  $t7, .L700137E8
/* 014404 70013804 01E02025 */   move  $a0, $t7
.L70013808:
/* 014408 70013808 03E00008 */  jr    $ra
/* 01440C 7001380C 46001006 */   mov.s $f0, $f2

.section .rodata
glabel F32_800296E0
.float 1.0005778
glabel F32_800296E4
.float 0.99942255

