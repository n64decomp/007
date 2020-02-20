# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osDpSetNextBuffer
/* 00F3B0 7000E7B0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00F3B4 7000E7B4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00F3B8 7000E7B8 AFA40028 */  sw    $a0, 0x28($sp)
/* 00F3BC 7000E7BC AFA60030 */  sw    $a2, 0x30($sp)
/* 00F3C0 7000E7C0 AFA70034 */  sw    $a3, 0x34($sp)
/* 00F3C4 7000E7C4 0C0063FC */  jal   __osDpDeviceBusy
/* 00F3C8 7000E7C8 AFB00018 */   sw    $s0, 0x18($sp)
/* 00F3CC 7000E7CC 10400003 */  beqz  $v0, .L7000E7DC
/* 00F3D0 7000E7D0 00000000 */   nop   
/* 00F3D4 7000E7D4 1000001B */  b     .L7000E844
/* 00F3D8 7000E7D8 2402FFFF */   li    $v0, -1
.L7000E7DC:
/* 00F3DC 7000E7DC 240E0001 */  li    $t6, 1
/* 00F3E0 7000E7E0 3C0FA410 */  lui   $t7, %hi(DPC_STATUS_REG) # $t7, 0xa410
/* 00F3E4 7000E7E4 ADEE000C */  sw    $t6, %lo(DPC_STATUS_REG)($t7)
.L7000E7E8:
/* 00F3E8 7000E7E8 3C18A410 */  lui   $t8, %hi(DPC_STATUS_REG) # $t8, 0xa410
/* 00F3EC 7000E7EC 8F10000C */  lw    $s0, %lo(DPC_STATUS_REG)($t8)
/* 00F3F0 7000E7F0 32190001 */  andi  $t9, $s0, 1
/* 00F3F4 7000E7F4 1720FFFC */  bnez  $t9, .L7000E7E8
/* 00F3F8 7000E7F8 00000000 */   nop   
/* 00F3FC 7000E7FC 0C003A2C */  jal   osVirtualToPhysical
/* 00F400 7000E800 8FA40028 */   lw    $a0, 0x28($sp)
/* 00F404 7000E804 3C08A410 */  lui   $t0, 0xa410
/* 00F408 7000E808 AD020000 */  sw    $v0, ($t0)
/* 00F40C 7000E80C 0C003A2C */  jal   osVirtualToPhysical
/* 00F410 7000E810 8FA40028 */   lw    $a0, 0x28($sp)
/* 00F414 7000E814 8FAD0034 */  lw    $t5, 0x34($sp)
/* 00F418 7000E818 00405825 */  move  $t3, $v0
/* 00F41C 7000E81C 8FAC0030 */  lw    $t4, 0x30($sp)
/* 00F420 7000E820 016D7821 */  addu  $t7, $t3, $t5
/* 00F424 7000E824 240A0000 */  li    $t2, 0
/* 00F428 7000E828 01ED082B */  sltu  $at, $t7, $t5
/* 00F42C 7000E82C 002A7021 */  addu  $t6, $at, $t2
/* 00F430 7000E830 01E04825 */  move  $t1, $t7
/* 00F434 7000E834 3C18A410 */  lui   $t8, %hi(DPC_END_REG) # $t8, 0xa410
/* 00F438 7000E838 AF090004 */  sw    $t1, %lo(DPC_END_REG)($t8)
/* 00F43C 7000E83C 00001025 */  move  $v0, $zero
/* 00F440 7000E840 01CC7021 */  addu  $t6, $t6, $t4
.L7000E844:
/* 00F444 7000E844 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00F448 7000E848 8FB00018 */  lw    $s0, 0x18($sp)
/* 00F44C 7000E84C 27BD0028 */  addiu $sp, $sp, 0x28
/* 00F450 7000E850 03E00008 */  jr    $ra
/* 00F454 7000E854 00000000 */   nop   
