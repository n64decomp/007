# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osPiStartDma
/* 0102A0 7000F6A0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0102A4 7000F6A4 3C0E8002 */  lui   $t6, %hi(__osPiDevMgr) 
/* 0102A8 7000F6A8 8DCE7790 */  lw    $t6, %lo(__osPiDevMgr)($t6)
/* 0102AC 7000F6AC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0102B0 7000F6B0 AFA40028 */  sw    $a0, 0x28($sp)
/* 0102B4 7000F6B4 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0102B8 7000F6B8 AFA60030 */  sw    $a2, 0x30($sp)
/* 0102BC 7000F6BC AFA70034 */  sw    $a3, 0x34($sp)
/* 0102C0 7000F6C0 AFB10018 */  sw    $s1, 0x18($sp)
/* 0102C4 7000F6C4 15C00003 */  bnez  $t6, .L7000F6D4
/* 0102C8 7000F6C8 AFB00014 */   sw    $s0, 0x14($sp)
/* 0102CC 7000F6CC 10000032 */  b     .L7000F798
/* 0102D0 7000F6D0 2402FFFF */   li    $v0, -1
.L7000F6D4:
/* 0102D4 7000F6D4 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0102D8 7000F6D8 15E00005 */  bnez  $t7, .L7000F6F0
/* 0102DC 7000F6DC 00000000 */   nop   
/* 0102E0 7000F6E0 8FB90028 */  lw    $t9, 0x28($sp)
/* 0102E4 7000F6E4 2418000B */  li    $t8, 11
/* 0102E8 7000F6E8 10000004 */  b     .L7000F6FC
/* 0102EC 7000F6EC A7380000 */   sh    $t8, ($t9)
.L7000F6F0:
/* 0102F0 7000F6F0 8FA90028 */  lw    $t1, 0x28($sp)
/* 0102F4 7000F6F4 2408000C */  li    $t0, 12
/* 0102F8 7000F6F8 A5280000 */  sh    $t0, ($t1)
.L7000F6FC:
/* 0102FC 7000F6FC 8FAA002C */  lw    $t2, 0x2c($sp)
/* 010300 7000F700 8FAB0028 */  lw    $t3, 0x28($sp)
/* 010304 7000F704 24010001 */  li    $at, 1
/* 010308 7000F708 A16A0002 */  sb    $t2, 2($t3)
/* 01030C 7000F70C 8FAD0028 */  lw    $t5, 0x28($sp)
/* 010310 7000F710 8FAC0040 */  lw    $t4, 0x40($sp)
/* 010314 7000F714 ADAC0004 */  sw    $t4, 4($t5)
/* 010318 7000F718 8FAF0028 */  lw    $t7, 0x28($sp)
/* 01031C 7000F71C 8FAE0038 */  lw    $t6, 0x38($sp)
/* 010320 7000F720 ADEE0008 */  sw    $t6, 8($t7)
/* 010324 7000F724 8FB90028 */  lw    $t9, 0x28($sp)
/* 010328 7000F728 8FB80034 */  lw    $t8, 0x34($sp)
/* 01032C 7000F72C AF38000C */  sw    $t8, 0xc($t9)
/* 010330 7000F730 8FA90028 */  lw    $t1, 0x28($sp)
/* 010334 7000F734 8FA8003C */  lw    $t0, 0x3c($sp)
/* 010338 7000F738 AD280010 */  sw    $t0, 0x10($t1)
/* 01033C 7000F73C 8FAA0028 */  lw    $t2, 0x28($sp)
/* 010340 7000F740 AD400014 */  sw    $zero, 0x14($t2)
/* 010344 7000F744 8FAB002C */  lw    $t3, 0x2c($sp)
/* 010348 7000F748 1561000A */  bne   $t3, $at, .L7000F774
/* 01034C 7000F74C 00000000 */   nop   
/* 010350 7000F750 0C006E00 */  jal   osPiGetCmdQueue
/* 010354 7000F754 00000000 */   nop   
/* 010358 7000F758 00408825 */  move  $s1, $v0
/* 01035C 7000F75C 02202025 */  move  $a0, $s1
/* 010360 7000F760 8FA50028 */  lw    $a1, 0x28($sp)
/* 010364 7000F764 0C006DAC */  jal   osJamMesg
/* 010368 7000F768 00003025 */   move  $a2, $zero
/* 01036C 7000F76C 10000009 */  b     .L7000F794
/* 010370 7000F770 00408025 */   move  $s0, $v0
.L7000F774:
/* 010374 7000F774 0C006E00 */  jal   osPiGetCmdQueue
/* 010378 7000F778 00000000 */   nop   
/* 01037C 7000F77C 00408825 */  move  $s1, $v0
/* 010380 7000F780 02202025 */  move  $a0, $s1
/* 010384 7000F784 8FA50028 */  lw    $a1, 0x28($sp)
/* 010388 7000F788 0C0037C4 */  jal   osSendMesg
/* 01038C 7000F78C 00003025 */   move  $a2, $zero
/* 010390 7000F790 00408025 */  move  $s0, $v0
.L7000F794:
/* 010394 7000F794 02001025 */  move  $v0, $s0
.L7000F798:
/* 010398 7000F798 8FBF001C */  lw    $ra, 0x1c($sp)
/* 01039C 7000F79C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0103A0 7000F7A0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0103A4 7000F7A4 03E00008 */  jr    $ra
/* 0103A8 7000F7A8 27BD0028 */   addiu $sp, $sp, 0x28
