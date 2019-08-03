#include "ultra64.h"







#ifdef NONMATCHING
void something_with_ejected_cartridges(void) {

}
#else
GLOBAL_ASM(
.text
glabel something_with_ejected_cartridges
/* 039B70 7F005040 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 039B74 7F005044 3C018007 */  lui   $at, %hi(dword_CODE_bss_80075DB0) # $at, 0x8007
/* 039B78 7F005048 3C028007 */  lui   $v0, %hi(dword_CODE_bss_80075DB8) # $v0, 0x8007
/* 039B7C 7F00504C 3C038007 */  lui   $v1, %hi(dword_CODE_bss_80075DC8) # $v1, 0x8007
/* 039B80 7F005050 AFBF001C */  sw    $ra, 0x1c($sp)
/* 039B84 7F005054 AFB10018 */  sw    $s1, 0x18($sp)
/* 039B88 7F005058 AFB00014 */  sw    $s0, 0x14($sp)
/* 039B8C 7F00505C AC205DB0 */  sw    $zero, %lo(dword_CODE_bss_80075DB0)($at)
/* 039B90 7F005060 24635DC8 */  addiu $v1, %lo(dword_CODE_bss_80075DC8) # addiu $v1, $v1, 0x5dc8
/* 039B94 7F005064 24425DB8 */  addiu $v0, %lo(dword_CODE_bss_80075DB8) # addiu $v0, $v0, 0x5db8
.L7F005068:
/* 039B98 7F005068 24420004 */  addiu $v0, $v0, 4
/* 039B9C 7F00506C 0043082B */  sltu  $at, $v0, $v1
/* 039BA0 7F005070 1420FFFD */  bnez  $at, .L7F005068
/* 039BA4 7F005074 AC40FFFC */   sw    $zero, -4($v0)
/* 039BA8 7F005078 3C0E8003 */  lui   $t6, %hi(ejected_cartridge) # $t6, 0x8003
/* 039BAC 7F00507C 8DCE246C */  lw    $t6, %lo(ejected_cartridge)($t6)
/* 039BB0 7F005080 3C018003 */  lui   $at, %hi(cartridges_eject) # $at, 0x8003
/* 039BB4 7F005084 AC204C9C */  sw    $zero, %lo(cartridges_eject)($at)
/* 039BB8 7F005088 3C018003 */  lui   $at, %hi(D_80034CA0) # $at, 0x8003
/* 039BBC 7F00508C 11C0000B */  beqz  $t6, .L7F0050BC
/* 039BC0 7F005090 AC204CA0 */   sw    $zero, %lo(D_80034CA0)($at)
/* 039BC4 7F005094 3C0F8003 */  lui   $t7, %hi(ejected_cartridge)
/* 039BC8 7F005098 25F0246C */  addiu $s0, $t7, %lo(ejected_cartridge)
/* 039BCC 7F00509C 8E110000 */  lw    $s1, ($s0)
/* 039BD0 7F0050A0 02202025 */  move  $a0, $s1
.L7F0050A4:
/* 039BD4 7F0050A4 0FC1D953 */  jal   load_object_into_memory
/* 039BD8 7F0050A8 8E050004 */   lw    $a1, 4($s0)
/* 039BDC 7F0050AC 8E110008 */  lw    $s1, 8($s0)
/* 039BE0 7F0050B0 26100008 */  addiu $s0, $s0, 8
/* 039BE4 7F0050B4 5620FFFB */  bnezl $s1, .L7F0050A4
/* 039BE8 7F0050B8 02202025 */   move  $a0, $s1
.L7F0050BC:
/* 039BEC 7F0050BC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 039BF0 7F0050C0 8FB00014 */  lw    $s0, 0x14($sp)
/* 039BF4 7F0050C4 8FB10018 */  lw    $s1, 0x18($sp)
/* 039BF8 7F0050C8 03E00008 */  jr    $ra
/* 039BFC 7F0050CC 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif

