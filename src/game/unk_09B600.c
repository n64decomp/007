#include "ultra64.h"






#ifdef NONMATCHING
void sub_GAME_7F09B600(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B600
/* 0D0130 7F09B600 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0D0134 7F09B604 3C0E8F80 */  lui   $t6, (0x8F809F47 >> 16) # lui $t6, 0x8f80 # seed for save profile checksum confirmation
/* 0D0138 7F09B608 3C0F3108 */  lui   $t7, (0x3108B3C1 >> 16) # lui $t7, 0x3108
/* 0D013C 7F09B60C AFB50028 */  sw    $s5, 0x28($sp)
/* 0D0140 7F09B610 AFB40024 */  sw    $s4, 0x24($sp)
/* 0D0144 7F09B614 AFB30020 */  sw    $s3, 0x20($sp)
/* 0D0148 7F09B618 AFB10018 */  sw    $s1, 0x18($sp)
/* 0D014C 7F09B61C AFB00014 */  sw    $s0, 0x14($sp)
/* 0D0150 7F09B620 35EFB3C1 */  ori   $t7, (0x3108B3C1 & 0xFFFF) # ori $t7, $t7, 0xb3c1
/* 0D0154 7F09B624 35CE9F47 */  ori   $t6, (0x8F809F47 & 0xFFFF) # ori $t6, $t6, 0x9f47
/* 0D0158 7F09B628 0085082B */  sltu  $at, $a0, $a1 #
/* 0D015C 7F09B62C 00A0A825 */  move  $s5, $a1
/* 0D0160 7F09B630 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0D0164 7F09B634 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0D0168 7F09B638 AFA60060 */  sw    $a2, 0x60($sp)
/* 0D016C 7F09B63C 00803825 */  move  $a3, $a0
/* 0D0170 7F09B640 00008825 */  move  $s1, $zero
/* 0D0174 7F09B644 AFAE0048 */  sw    $t6, 0x48($sp)
/* 0D0178 7F09B648 AFAF004C */  sw    $t7, 0x4c($sp)
/* 0D017C 7F09B64C 00009825 */  move  $s3, $zero
/* 0D0180 7F09B650 0000A025 */  move  $s4, $zero
/* 0D0184 7F09B654 10200016 */  beqz  $at, .L7F09B6B0
/* 0D0188 7F09B658 00808025 */   move  $s0, $a0
/* 0D018C 7F09B65C AFA40058 */  sw    $a0, 0x58($sp)
/* 0D0190 7F09B660 27B20048 */  addiu $s2, $sp, 0x48
.L7F09B664:
/* 0D0194 7F09B664 92180000 */  lbu   $t8, ($s0)
/* 0D0198 7F09B668 8FAD004C */  lw    $t5, 0x4c($sp)
/* 0D019C 7F09B66C 3239000F */  andi  $t9, $s1, 0xf
/* 0D01A0 7F09B670 03384004 */  sllv  $t0, $t8, $t9
/* 0D01A4 7F09B674 8FAC0048 */  lw    $t4, 0x48($sp)
/* 0D01A8 7F09B678 010D7821 */  addu  $t7, $t0, $t5
/* 0D01AC 7F09B67C 000857C3 */  sra   $t2, $t0, 0x1f
/* 0D01B0 7F09B680 01ED082B */  sltu  $at, $t7, $t5
/* 0D01B4 7F09B684 002A7021 */  addu  $t6, $at, $t2
/* 0D01B8 7F09B688 01CC7021 */  addu  $t6, $t6, $t4
/* 0D01BC 7F09B68C AFAE0048 */  sw    $t6, 0x48($sp)
/* 0D01C0 7F09B690 AFAF004C */  sw    $t7, 0x4c($sp)
/* 0D01C4 7F09B694 0C00292B */  jal   lotsa_shifting_randomizer_related
/* 0D01C8 7F09B698 02402025 */   move  $a0, $s2
/* 0D01CC 7F09B69C 26100001 */  addiu $s0, $s0, 1
/* 0D01D0 7F09B6A0 26310007 */  addiu $s1, $s1, 7
/* 0D01D4 7F09B6A4 1615FFEF */  bne   $s0, $s5, .L7F09B664
/* 0D01D8 7F09B6A8 02629826 */   xor   $s3, $s3, $v0
/* 0D01DC 7F09B6AC 8FA70058 */  lw    $a3, 0x58($sp)
.L7F09B6B0:
/* 0D01E0 7F09B6B0 26B0FFFF */  addiu $s0, $s5, -1
/* 0D01E4 7F09B6B4 0207082B */  sltu  $at, $s0, $a3
/* 0D01E8 7F09B6B8 14200014 */  bnez  $at, .L7F09B70C
/* 0D01EC 7F09B6BC 27B20048 */   addiu $s2, $sp, 0x48
/* 0D01F0 7F09B6C0 24F5FFFF */  addiu $s5, $a3, -1
.L7F09B6C4:
/* 0D01F4 7F09B6C4 92090000 */  lbu   $t1, ($s0)
/* 0D01F8 7F09B6C8 8FAB004C */  lw    $t3, 0x4c($sp)
/* 0D01FC 7F09B6CC 3238000F */  andi  $t8, $s1, 0xf
/* 0D0200 7F09B6D0 0309C804 */  sllv  $t9, $t1, $t8
/* 0D0204 7F09B6D4 8FAA0048 */  lw    $t2, 0x48($sp)
/* 0D0208 7F09B6D8 032B6821 */  addu  $t5, $t9, $t3
/* 0D020C 7F09B6DC 001947C3 */  sra   $t0, $t9, 0x1f
/* 0D0210 7F09B6E0 01AB082B */  sltu  $at, $t5, $t3
/* 0D0214 7F09B6E4 00286021 */  addu  $t4, $at, $t0
/* 0D0218 7F09B6E8 018A6021 */  addu  $t4, $t4, $t2
/* 0D021C 7F09B6EC AFAC0048 */  sw    $t4, 0x48($sp)
/* 0D0220 7F09B6F0 AFAD004C */  sw    $t5, 0x4c($sp)
/* 0D0224 7F09B6F4 0C00292B */  jal   lotsa_shifting_randomizer_related
/* 0D0228 7F09B6F8 02402025 */   move  $a0, $s2
/* 0D022C 7F09B6FC 2610FFFF */  addiu $s0, $s0, -1
/* 0D0230 7F09B700 26310003 */  addiu $s1, $s1, 3
/* 0D0234 7F09B704 1615FFEF */  bne   $s0, $s5, .L7F09B6C4
/* 0D0238 7F09B708 0282A026 */   xor   $s4, $s4, $v0
.L7F09B70C:
/* 0D023C 7F09B70C 8FAE0060 */  lw    $t6, 0x60($sp)
/* 0D0240 7F09B710 ADD30000 */  sw    $s3, ($t6)
/* 0D0244 7F09B714 ADD40004 */  sw    $s4, 4($t6)
/* 0D0248 7F09B718 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0D024C 7F09B71C 8FB50028 */  lw    $s5, 0x28($sp)
/* 0D0250 7F09B720 8FB40024 */  lw    $s4, 0x24($sp)
/* 0D0254 7F09B724 8FB30020 */  lw    $s3, 0x20($sp)
/* 0D0258 7F09B728 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0D025C 7F09B72C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0D0260 7F09B730 8FB00014 */  lw    $s0, 0x14($sp)
/* 0D0264 7F09B734 03E00008 */  jr    $ra
/* 0D0268 7F09B738 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif

