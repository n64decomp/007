# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osSetEventMesg
/* 00E850 7000DC50 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00E854 7000DC54 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E858 7000DC58 AFA40028 */  sw    $a0, 0x28($sp)
/* 00E85C 7000DC5C AFA5002C */  sw    $a1, 0x2c($sp)
/* 00E860 7000DC60 AFA60030 */  sw    $a2, 0x30($sp)
/* 00E864 7000DC64 0C00617C */  jal   __osDisableInt
/* 00E868 7000DC68 AFB00018 */   sw    $s0, 0x18($sp)
/* 00E86C 7000DC6C 8FAE0028 */  lw    $t6, 0x28($sp)
/* 00E870 7000DC70 3C188006 */  lui   $t8, %hi(__osEventStateTab) 
/* 00E874 7000DC74 8FA8002C */  lw    $t0, 0x2c($sp)
/* 00E878 7000DC78 27186A10 */  addiu $t8, %lo(__osEventStateTab) # addiu $t8, $t8, 0x6a10
/* 00E87C 7000DC7C 000E78C0 */  sll   $t7, $t6, 3
/* 00E880 7000DC80 01F8C821 */  addu  $t9, $t7, $t8
/* 00E884 7000DC84 AFB90020 */  sw    $t9, 0x20($sp)
/* 00E888 7000DC88 AF280000 */  sw    $t0, ($t9)
/* 00E88C 7000DC8C 8FAA0020 */  lw    $t2, 0x20($sp)
/* 00E890 7000DC90 8FA90030 */  lw    $t1, 0x30($sp)
/* 00E894 7000DC94 00408025 */  move  $s0, $v0
/* 00E898 7000DC98 02002025 */  move  $a0, $s0
/* 00E89C 7000DC9C 0C006184 */  jal   __osRestoreInt
/* 00E8A0 7000DCA0 AD490004 */   sw    $t1, 4($t2)
/* 00E8A4 7000DCA4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00E8A8 7000DCA8 8FB00018 */  lw    $s0, 0x18($sp)
/* 00E8AC 7000DCAC 27BD0028 */  addiu $sp, $sp, 0x28
/* 00E8B0 7000DCB0 03E00008 */  jr    $ra
/* 00E8B4 7000DCB4 00000000 */   nop   

.section .bss
glabel __osEventStateTab
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0
.byte 0



