# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"    

glabel osSpTaskYielded
/* 00EF40 7000E340 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00EF44 7000E344 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00EF48 7000E348 0C0063B4 */  jal   __osSpGetStatus
/* 00EF4C 7000E34C AFA40020 */   sw    $a0, 0x20($sp)
/* 00EF50 7000E350 AFA2001C */  sw    $v0, 0x1c($sp)
/* 00EF54 7000E354 8FAE001C */  lw    $t6, 0x1c($sp)
/* 00EF58 7000E358 31CF0100 */  andi  $t7, $t6, 0x100
/* 00EF5C 7000E35C 11E00004 */  beqz  $t7, .L7000E370
/* 00EF60 7000E360 00000000 */   nop   
/* 00EF64 7000E364 24180001 */  li    $t8, 1
/* 00EF68 7000E368 10000002 */  b     .L7000E374
/* 00EF6C 7000E36C AFB80018 */   sw    $t8, 0x18($sp)
.L7000E370:
/* 00EF70 7000E370 AFA00018 */  sw    $zero, 0x18($sp)
.L7000E374:
/* 00EF74 7000E374 8FB9001C */  lw    $t9, 0x1c($sp)
/* 00EF78 7000E378 33280080 */  andi  $t0, $t9, 0x80
/* 00EF7C 7000E37C 1100000B */  beqz  $t0, .L7000E3AC
/* 00EF80 7000E380 00000000 */   nop   
/* 00EF84 7000E384 8FA90020 */  lw    $t1, 0x20($sp)
/* 00EF88 7000E388 8FAB0018 */  lw    $t3, 0x18($sp)
/* 00EF8C 7000E38C 2401FFFD */  li    $at, -3
/* 00EF90 7000E390 8D2A0004 */  lw    $t2, 4($t1)
/* 00EF94 7000E394 014B6025 */  or    $t4, $t2, $t3
/* 00EF98 7000E398 AD2C0004 */  sw    $t4, 4($t1)
/* 00EF9C 7000E39C 8FAD0020 */  lw    $t5, 0x20($sp)
/* 00EFA0 7000E3A0 8DAE0004 */  lw    $t6, 4($t5)
/* 00EFA4 7000E3A4 01C17824 */  and   $t7, $t6, $at
/* 00EFA8 7000E3A8 ADAF0004 */  sw    $t7, 4($t5)
.L7000E3AC:
/* 00EFAC 7000E3AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00EFB0 7000E3B0 8FA20018 */  lw    $v0, 0x18($sp)
/* 00EFB4 7000E3B4 27BD0020 */  addiu $sp, $sp, 0x20
/* 00EFB8 7000E3B8 03E00008 */  jr    $ra
/* 00EFBC 7000E3BC 00000000 */   nop   
