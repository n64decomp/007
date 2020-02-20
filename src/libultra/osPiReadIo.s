# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel osPiReadIo
/* 014410 70013810 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 014414 70013814 AFBF001C */  sw    $ra, 0x1c($sp)
/* 014418 70013818 AFA40028 */  sw    $a0, 0x28($sp)
/* 01441C 7001381C AFA5002C */  sw    $a1, 0x2c($sp)
/* 014420 70013820 0C0075D8 */  jal   __osPiGetAccess
/* 014424 70013824 AFB00018 */   sw    $s0, 0x18($sp)
/* 014428 70013828 8FA40028 */  lw    $a0, 0x28($sp)
/* 01442C 7001382C 0C005EF8 */  jal   osPiRawReadIo
/* 014430 70013830 8FA5002C */   lw    $a1, 0x2c($sp)
/* 014434 70013834 0C0075E9 */  jal   __osPiRelAccess
/* 014438 70013838 00408025 */   move  $s0, $v0
/* 01443C 7001383C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 014440 70013840 02001025 */  move  $v0, $s0
/* 014444 70013844 8FB00018 */  lw    $s0, 0x18($sp)
/* 014448 70013848 03E00008 */  jr    $ra
/* 01444C 7001384C 27BD0028 */   addiu $sp, $sp, 0x28
