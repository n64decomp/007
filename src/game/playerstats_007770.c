#include "ultra64.h"



#ifdef NONMATCHING
void sub_GAME_7F007770(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F007770
/* 03C2A0 7F007770 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 03C2A4 7F007774 AFBF0024 */  sw    $ra, 0x24($sp)
/* 03C2A8 7F007778 AFB30020 */  sw    $s3, 0x20($sp)
/* 03C2AC 7F00777C AFB2001C */  sw    $s2, 0x1c($sp)
/* 03C2B0 7F007780 AFB10018 */  sw    $s1, 0x18($sp)
/* 03C2B4 7F007784 0FC26919 */  jal   get_num_players
/* 03C2B8 7F007788 AFB00014 */   sw    $s0, 0x14($sp)
/* 03C2BC 7F00778C 0FC26C54 */  jal   get_cur_playernum
/* 03C2C0 7F007790 00409825 */   move  $s3, $v0
/* 03C2C4 7F007794 AFA20030 */  sw    $v0, 0x30($sp)
/* 03C2C8 7F007798 1A60000E */  blez  $s3, .L7F0077D4
/* 03C2CC 7F00779C 00008025 */   move  $s0, $zero
/* 03C2D0 7F0077A0 27B20038 */  addiu $s2, $sp, 0x38
/* 03C2D4 7F0077A4 27B1003C */  addiu $s1, $sp, 0x3c
.L7F0077A8:
/* 03C2D8 7F0077A8 0FC26C43 */  jal   set_cur_player
/* 03C2DC 7F0077AC 02002025 */   move  $a0, $s0
/* 03C2E0 7F0077B0 02202025 */  move  $a0, $s1
/* 03C2E4 7F0077B4 0FC236C2 */  jal   sub_GAME_7F08DB08
/* 03C2E8 7F0077B8 02402825 */   move  $a1, $s2
/* 03C2EC 7F0077BC 8FA4003C */  lw    $a0, 0x3c($sp)
/* 03C2F0 7F0077C0 0FC075A0 */  jal   store_favorite_weapon_current_player
/* 03C2F4 7F0077C4 8FA50038 */   lw    $a1, 0x38($sp)
/* 03C2F8 7F0077C8 26100001 */  addiu $s0, $s0, 1
/* 03C2FC 7F0077CC 1613FFF6 */  bne   $s0, $s3, .L7F0077A8
/* 03C300 7F0077D0 00000000 */   nop   
.L7F0077D4:
/* 03C304 7F0077D4 0FC26C43 */  jal   set_cur_player
/* 03C308 7F0077D8 8FA40030 */   lw    $a0, 0x30($sp)
/* 03C30C 7F0077DC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 03C310 7F0077E0 8FB00014 */  lw    $s0, 0x14($sp)
/* 03C314 7F0077E4 8FB10018 */  lw    $s1, 0x18($sp)
/* 03C318 7F0077E8 8FB2001C */  lw    $s2, 0x1c($sp)
/* 03C31C 7F0077EC 8FB30020 */  lw    $s3, 0x20($sp)
/* 03C320 7F0077F0 03E00008 */  jr    $ra
/* 03C324 7F0077F4 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

