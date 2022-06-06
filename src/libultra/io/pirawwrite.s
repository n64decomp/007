# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"
glabel osPiRawWriteIo
/* 0D5390 800D4790 3C0EA460 */  lui   $t6, %hi(0xA4600010) # $t6, 0xa460
/* 0D5394 800D4794 8DC60010 */  lw    $a2, %lo(0xA4600010)($t6)
/* 0D5398 800D4798 27BDFFF8 */  addiu $sp, $sp, -8
/* 0D539C 800D479C 30CF0003 */  andi  $t7, $a2, 3
/* 0D53A0 800D47A0 11E00006 */  beqz  $t7, .L800D47BC
/* 0D53A4 800D47A4 00000000 */   nop   
.L800D47A8:
/* 0D53A8 800D47A8 3C18A460 */  lui   $t8, %hi(0xA4600010) # $t8, 0xa460
/* 0D53AC 800D47AC 8F060010 */  lw    $a2, %lo(0xA4600010)($t8)
/* 0D53B0 800D47B0 30D90003 */  andi  $t9, $a2, 3
/* 0D53B4 800D47B4 1720FFFC */  bnez  $t9, .L800D47A8
/* 0D53B8 800D47B8 00000000 */   nop   
.L800D47BC:
/* 0D53BC 800D47BC 3C088000 */  lui   $t0, %hi(osRomBase) # $t0, 0x8000
/* 0D53C0 800D47C0 8D080308 */  lw    $t0, %lo(osRomBase)($t0)
/* 0D53C4 800D47C4 3C01A000 */  lui   $at, 0xa000
/* 0D53C8 800D47C8 00001025 */  move  $v0, $zero
/* 0D53CC 800D47CC 01044825 */  or    $t1, $t0, $a0
/* 0D53D0 800D47D0 01215025 */  or    $t2, $t1, $at
/* 0D53D4 800D47D4 8D4B0000 */  lw    $t3, ($t2)
/* 0D53D8 800D47D8 27BD0008 */  addiu $sp, $sp, 8
/* 0D53DC 800D47DC 03E00008 */  jr    $ra
/* 0D53E0 800D47E0 ACAB0000 */   sw    $t3, ($a1)
