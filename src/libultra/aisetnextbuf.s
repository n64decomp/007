# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osAiSetNextBuffer
/* 00FB00 7000EF00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00FB04 7000EF04 3C0F8002 */  lui   $t7, %hi(B_800276F0) 
/* 00FB08 7000EF08 91EF76F0 */  lbu   $t7, %lo(B_800276F0)($t7)
/* 00FB0C 7000EF0C AFA40020 */  sw    $a0, 0x20($sp)
/* 00FB10 7000EF10 8FAE0020 */  lw    $t6, 0x20($sp)
/* 00FB14 7000EF14 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00FB18 7000EF18 AFA50024 */  sw    $a1, 0x24($sp)
/* 00FB1C 7000EF1C 11E00003 */  beqz  $t7, .L7000EF2C
/* 00FB20 7000EF20 AFAE001C */   sw    $t6, 0x1c($sp)
/* 00FB24 7000EF24 25D8E000 */  addiu $t8, $t6, -0x2000
/* 00FB28 7000EF28 AFB8001C */  sw    $t8, 0x1c($sp)
.L7000EF2C:
/* 00FB2C 7000EF2C 8FB90020 */  lw    $t9, 0x20($sp)
/* 00FB30 7000EF30 8FA80024 */  lw    $t0, 0x24($sp)
/* 00FB34 7000EF34 24012000 */  li    $at, 8192
/* 00FB38 7000EF38 03284821 */  addu  $t1, $t9, $t0
/* 00FB3C 7000EF3C 312A3FFF */  andi  $t2, $t1, 0x3fff
/* 00FB40 7000EF40 15410005 */  bne   $t2, $at, .L7000EF58
/* 00FB44 7000EF44 00000000 */   nop   
/* 00FB48 7000EF48 240B0001 */  li    $t3, 1
/* 00FB4C 7000EF4C 3C018002 */  lui   $at, %hi(B_800276F0)
/* 00FB50 7000EF50 10000003 */  b     .L7000EF60
/* 00FB54 7000EF54 A02B76F0 */   sb    $t3, %lo(B_800276F0)($at)
.L7000EF58:
/* 00FB58 7000EF58 3C018002 */  lui   $at, %hi(B_800276F0)
/* 00FB5C 7000EF5C A02076F0 */  sb    $zero, %lo(B_800276F0)($at)
.L7000EF60:
/* 00FB60 7000EF60 0C00643C */  jal   __osAiDeviceBusy
/* 00FB64 7000EF64 00000000 */   nop   
/* 00FB68 7000EF68 10400003 */  beqz  $v0, .L7000EF78
/* 00FB6C 7000EF6C 00000000 */   nop   
/* 00FB70 7000EF70 10000009 */  b     .L7000EF98
/* 00FB74 7000EF74 2402FFFF */   li    $v0, -1
.L7000EF78:
/* 00FB78 7000EF78 0C003A2C */  jal   osVirtualToPhysical
/* 00FB7C 7000EF7C 8FA4001C */   lw    $a0, 0x1c($sp)
/* 00FB80 7000EF80 3C0CA450 */  lui   $t4, 0xa450
/* 00FB84 7000EF84 AD820000 */  sw    $v0, ($t4)
/* 00FB88 7000EF88 8FAD0024 */  lw    $t5, 0x24($sp)
/* 00FB8C 7000EF8C 3C0FA450 */  lui   $t7, %hi(AI_LEN_REG) # $t7, 0xa450
/* 00FB90 7000EF90 00001025 */  move  $v0, $zero
/* 00FB94 7000EF94 ADED0004 */  sw    $t5, %lo(AI_LEN_REG)($t7)
.L7000EF98:
/* 00FB98 7000EF98 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00FB9C 7000EF9C 27BD0020 */  addiu $sp, $sp, 0x20
/* 00FBA0 7000EFA0 03E00008 */  jr    $ra
/* 00FBA4 7000EFA4 00000000 */   nop   

/* 00FBA8 7000EFA8 00000000 */  nop   
/* 00FBAC 7000EFAC 00000000 */  nop   
.section .data
glabel B_800276F0
.byte 0
