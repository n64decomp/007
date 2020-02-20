# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osSetTimer
/* 011850 70010C50 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 011854 70010C54 AFA40020 */  sw    $a0, 0x20($sp)
/* 011858 70010C58 8FAE0020 */  lw    $t6, 0x20($sp)
/* 01185C 70010C5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 011860 70010C60 AFA60028 */  sw    $a2, 0x28($sp)
/* 011864 70010C64 AFA7002C */  sw    $a3, 0x2c($sp)
/* 011868 70010C68 ADC00000 */  sw    $zero, ($t6)
/* 01186C 70010C6C 8FAF0020 */  lw    $t7, 0x20($sp)
/* 011870 70010C70 ADE00004 */  sw    $zero, 4($t7)
/* 011874 70010C74 8FA80020 */  lw    $t0, 0x20($sp)
/* 011878 70010C78 8FB90034 */  lw    $t9, 0x34($sp)
/* 01187C 70010C7C 8FB80030 */  lw    $t8, 0x30($sp)
/* 011880 70010C80 AD19000C */  sw    $t9, 0xc($t0)
/* 011884 70010C84 AD180008 */  sw    $t8, 8($t0)
/* 011888 70010C88 8FAA0028 */  lw    $t2, 0x28($sp)
/* 01188C 70010C8C 8FAB002C */  lw    $t3, 0x2c($sp)
/* 011890 70010C90 15400003 */  bnez  $t2, .L70010CA0
/* 011894 70010C94 00000000 */   nop   
/* 011898 70010C98 11600005 */  beqz  $t3, .L70010CB0
/* 01189C 70010C9C 00000000 */   nop   
.L70010CA0:
/* 0118A0 70010CA0 8FA90020 */  lw    $t1, 0x20($sp)
/* 0118A4 70010CA4 AD2A0010 */  sw    $t2, 0x10($t1)
/* 0118A8 70010CA8 10000006 */  b     .L70010CC4
/* 0118AC 70010CAC AD2B0014 */   sw    $t3, 0x14($t1)
.L70010CB0:
/* 0118B0 70010CB0 8FAE0020 */  lw    $t6, 0x20($sp)
/* 0118B4 70010CB4 8FAC0030 */  lw    $t4, 0x30($sp)
/* 0118B8 70010CB8 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0118BC 70010CBC ADCC0010 */  sw    $t4, 0x10($t6)
/* 0118C0 70010CC0 ADCD0014 */  sw    $t5, 0x14($t6)
.L70010CC4:
/* 0118C4 70010CC4 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0118C8 70010CC8 8FB80020 */  lw    $t8, 0x20($sp)
/* 0118CC 70010CCC AF0F0018 */  sw    $t7, 0x18($t8)
/* 0118D0 70010CD0 8FA80020 */  lw    $t0, 0x20($sp)
/* 0118D4 70010CD4 8FB9003C */  lw    $t9, 0x3c($sp)
/* 0118D8 70010CD8 AD19001C */  sw    $t9, 0x1c($t0)
/* 0118DC 70010CDC 0C00622A */  jal   __osInsertTimer
/* 0118E0 70010CE0 8FA40020 */   lw    $a0, 0x20($sp)
/* 0118E4 70010CE4 3C0A8002 */  lui   $t2, %hi(__osTimerList) 
/* 0118E8 70010CE8 8D4A7FD0 */  lw    $t2, %lo(__osTimerList)($t2)
/* 0118EC 70010CEC AFA20018 */  sw    $v0, 0x18($sp)
/* 0118F0 70010CF0 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0118F4 70010CF4 8FA90020 */  lw    $t1, 0x20($sp)
/* 0118F8 70010CF8 8D4B0000 */  lw    $t3, ($t2)
/* 0118FC 70010CFC 15690004 */  bne   $t3, $t1, .L70010D10
/* 011900 70010D00 00000000 */   nop   
/* 011904 70010D04 8FA40018 */  lw    $a0, 0x18($sp)
/* 011908 70010D08 0C00620D */  jal   __osSetTimerIntr
/* 01190C 70010D0C 8FA5001C */   lw    $a1, 0x1c($sp)
.L70010D10:
/* 011910 70010D10 8FBF0014 */  lw    $ra, 0x14($sp)
/* 011914 70010D14 27BD0020 */  addiu $sp, $sp, 0x20
/* 011918 70010D18 00001025 */  move  $v0, $zero
/* 01191C 70010D1C 03E00008 */  jr    $ra
/* 011920 70010D20 00000000 */   nop   
