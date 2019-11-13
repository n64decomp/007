#include "ultra64.h"
#include "game/bond.h"
#include "game/chr.h"
#include "game/unk_093880.h"
#include "game/textrelated.h"

#ifdef NONMATCHING
void reinit_BONDdata_inventory(void) {

}
#else
GLOBAL_ASM(
.text
glabel reinit_BONDdata_inventory
/* 0C0B20 7F08BFF0 3C058008 */  lui   $a1, %hi(pPlayer)
/* 0C0B24 7F08BFF4 24A5A0B0 */  addiu $a1, %lo(pPlayer) # addiu $a1, $a1, -0x5f50
/* 0C0B28 7F08BFF8 8CA30000 */  lw    $v1, ($a1)
/* 0C0B2C 7F08BFFC 00001025 */  move  $v0, $zero
/* 0C0B30 7F08C000 00002025 */  move  $a0, $zero
/* 0C0B34 7F08C004 8C6E11E8 */  lw    $t6, 0x11e8($v1)
/* 0C0B38 7F08C008 2406FFFF */  li    $a2, -1
/* 0C0B3C 7F08C00C 59C0000C */  blezl $t6, .L7F08C040
/* 0C0B40 7F08C010 AC6011E0 */   sw    $zero, 0x11e0($v1)
/* 0C0B44 7F08C014 8C6F11E4 */  lw    $t7, 0x11e4($v1)
.L7F08C018:
/* 0C0B48 7F08C018 24420001 */  addiu $v0, $v0, 1
/* 0C0B4C 7F08C01C 01E4C021 */  addu  $t8, $t7, $a0
/* 0C0B50 7F08C020 AF060000 */  sw    $a2, ($t8)
/* 0C0B54 7F08C024 8CA30000 */  lw    $v1, ($a1)
/* 0C0B58 7F08C028 24840014 */  addiu $a0, $a0, 0x14
/* 0C0B5C 7F08C02C 8C7911E8 */  lw    $t9, 0x11e8($v1)
/* 0C0B60 7F08C030 0059082A */  slt   $at, $v0, $t9
/* 0C0B64 7F08C034 5420FFF8 */  bnezl $at, .L7F08C018
/* 0C0B68 7F08C038 8C6F11E4 */   lw    $t7, 0x11e4($v1)
/* 0C0B6C 7F08C03C AC6011E0 */  sw    $zero, 0x11e0($v1)
.L7F08C040:
/* 0C0B70 7F08C040 8CA80000 */  lw    $t0, ($a1)
/* 0C0B74 7F08C044 AD0011F4 */  sw    $zero, 0x11f4($t0)
/* 0C0B78 7F08C048 8CA90000 */  lw    $t1, ($a1)
/* 0C0B7C 7F08C04C 03E00008 */  jr    $ra
/* 0C0B80 7F08C050 AD2011F0 */   sw    $zero, 0x11f0($t1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08C054(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08C054
/* 0C0B84 7F08C054 27BDFFF8 */  addiu $sp, $sp, -8
/* 0C0B88 7F08C058 AFB00004 */  sw    $s0, 4($sp)
/* 0C0B8C 7F08C05C 8C850000 */  lw    $a1, ($a0)
/* 0C0B90 7F08C060 240B0001 */  li    $t3, 1
/* 0C0B94 7F08C064 2402FFFF */  li    $v0, -1
/* 0C0B98 7F08C068 15650005 */  bne   $t3, $a1, .L7F08C080
/* 0C0B9C 7F08C06C 2403FFFF */   li    $v1, -1
/* 0C0BA0 7F08C070 8C820004 */  lw    $v0, 4($a0)
/* 0C0BA4 7F08C074 24100002 */  li    $s0, 2
/* 0C0BA8 7F08C078 1000000B */  b     .L7F08C0A8
/* 0C0BAC 7F08C07C 240D0003 */   li    $t5, 3
.L7F08C080:
/* 0C0BB0 7F08C080 240D0003 */  li    $t5, 3
/* 0C0BB4 7F08C084 15A50005 */  bne   $t5, $a1, .L7F08C09C
/* 0C0BB8 7F08C088 24100002 */   li    $s0, 2
/* 0C0BBC 7F08C08C 8C820004 */  lw    $v0, 4($a0)
/* 0C0BC0 7F08C090 8C830008 */  lw    $v1, 8($a0)
/* 0C0BC4 7F08C094 10000004 */  b     .L7F08C0A8
/* 0C0BC8 7F08C098 24100002 */   li    $s0, 2
.L7F08C09C:
/* 0C0BCC 7F08C09C 16050002 */  bne   $s0, $a1, .L7F08C0A8
/* 0C0BD0 7F08C0A0 00000000 */   nop   
/* 0C0BD4 7F08C0A4 240207D0 */  li    $v0, 2000
.L7F08C0A8:
/* 0C0BD8 7F08C0A8 3C0C8008 */  lui   $t4, %hi(pPlayer) 
/* 0C0BDC 7F08C0AC 258CA0B0 */  addiu $t4, %lo(pPlayer) # addiu $t4, $t4, -0x5f50
/* 0C0BE0 7F08C0B0 8D870000 */  lw    $a3, ($t4)
/* 0C0BE4 7F08C0B4 8C86000C */  lw    $a2, 0xc($a0)
/* 0C0BE8 7F08C0B8 8CEE11E0 */  lw    $t6, 0x11e0($a3)
/* 0C0BEC 7F08C0BC 00C02825 */  move  $a1, $a2
/* 0C0BF0 7F08C0C0 50CE0032 */  beql  $a2, $t6, .L7F08C18C
/* 0C0BF4 7F08C0C4 8FB00004 */   lw    $s0, 4($sp)
.L7F08C0C8:
/* 0C0BF8 7F08C0C8 8CCA0000 */  lw    $t2, ($a2)
/* 0C0BFC 7F08C0CC 2408FFFF */  li    $t0, -1
/* 0C0C00 7F08C0D0 2409FFFF */  li    $t1, -1
/* 0C0C04 7F08C0D4 156A0003 */  bne   $t3, $t2, .L7F08C0E4
/* 0C0C08 7F08C0D8 00000000 */   nop   
/* 0C0C0C 7F08C0DC 10000009 */  b     .L7F08C104
/* 0C0C10 7F08C0E0 8CC80004 */   lw    $t0, 4($a2)
.L7F08C0E4:
/* 0C0C14 7F08C0E4 15AA0004 */  bne   $t5, $t2, .L7F08C0F8
/* 0C0C18 7F08C0E8 00000000 */   nop   
/* 0C0C1C 7F08C0EC 8CC80004 */  lw    $t0, 4($a2)
/* 0C0C20 7F08C0F0 10000004 */  b     .L7F08C104
/* 0C0C24 7F08C0F4 8CC90008 */   lw    $t1, 8($a2)
.L7F08C0F8:
/* 0C0C28 7F08C0F8 560A0003 */  bnel  $s0, $t2, .L7F08C108
/* 0C0C2C 7F08C0FC 0102082A */   slt   $at, $t0, $v0
/* 0C0C30 7F08C100 240803E8 */  li    $t0, 1000
.L7F08C104:
/* 0C0C34 7F08C104 0102082A */  slt   $at, $t0, $v0
.L7F08C108:
/* 0C0C38 7F08C108 54200006 */  bnezl $at, .L7F08C124
/* 0C0C3C 7F08C10C 8CA6000C */   lw    $a2, 0xc($a1)
/* 0C0C40 7F08C110 1448001D */  bne   $v0, $t0, .L7F08C188
/* 0C0C44 7F08C114 0123082A */   slt   $at, $t1, $v1
/* 0C0C48 7F08C118 5020001C */  beql  $at, $zero, .L7F08C18C
/* 0C0C4C 7F08C11C 8FB00004 */   lw    $s0, 4($sp)
/* 0C0C50 7F08C120 8CA6000C */  lw    $a2, 0xc($a1)
.L7F08C124:
/* 0C0C54 7F08C124 54860006 */  bnel  $a0, $a2, .L7F08C140
/* 0C0C58 7F08C128 8C8F0010 */   lw    $t7, 0x10($a0)
/* 0C0C5C 7F08C12C ACE511E0 */  sw    $a1, 0x11e0($a3)
/* 0C0C60 7F08C130 8D870000 */  lw    $a3, ($t4)
/* 0C0C64 7F08C134 10000011 */  b     .L7F08C17C
/* 0C0C68 7F08C138 8CE811E0 */   lw    $t0, 0x11e0($a3)
/* 0C0C6C 7F08C13C 8C8F0010 */  lw    $t7, 0x10($a0)
.L7F08C140:
/* 0C0C70 7F08C140 AC86000C */  sw    $a2, 0xc($a0)
/* 0C0C74 7F08C144 ACAF0010 */  sw    $t7, 0x10($a1)
/* 0C0C78 7F08C148 AC850010 */  sw    $a1, 0x10($a0)
/* 0C0C7C 7F08C14C ACA4000C */  sw    $a0, 0xc($a1)
/* 0C0C80 7F08C150 8C98000C */  lw    $t8, 0xc($a0)
/* 0C0C84 7F08C154 AF040010 */  sw    $a0, 0x10($t8)
/* 0C0C88 7F08C158 8CB90010 */  lw    $t9, 0x10($a1)
/* 0C0C8C 7F08C15C AF25000C */  sw    $a1, 0xc($t9)
/* 0C0C90 7F08C160 8D870000 */  lw    $a3, ($t4)
/* 0C0C94 7F08C164 8CE811E0 */  lw    $t0, 0x11e0($a3)
/* 0C0C98 7F08C168 54880005 */  bnel  $a0, $t0, .L7F08C180
/* 0C0C9C 7F08C16C 8C86000C */   lw    $a2, 0xc($a0)
/* 0C0CA0 7F08C170 ACE511E0 */  sw    $a1, 0x11e0($a3)
/* 0C0CA4 7F08C174 8D870000 */  lw    $a3, ($t4)
/* 0C0CA8 7F08C178 8CE811E0 */  lw    $t0, 0x11e0($a3)
.L7F08C17C:
/* 0C0CAC 7F08C17C 8C86000C */  lw    $a2, 0xc($a0)
.L7F08C180:
/* 0C0CB0 7F08C180 14C8FFD1 */  bne   $a2, $t0, .L7F08C0C8
/* 0C0CB4 7F08C184 00C02825 */   move  $a1, $a2
.L7F08C188:
/* 0C0CB8 7F08C188 8FB00004 */  lw    $s0, 4($sp)
.L7F08C18C:
/* 0C0CBC 7F08C18C 03E00008 */  jr    $ra
/* 0C0CC0 7F08C190 27BD0008 */   addiu $sp, $sp, 8
)
#endif





#ifdef NONMATCHING
void add_additional_weapon_slot_to_player_inventory_guess(void) {

}
#else
GLOBAL_ASM(
.text
glabel add_additional_weapon_slot_to_player_inventory_guess
/* 0C0CC4 7F08C194 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C0CC8 7F08C198 2463A0B0 */  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
/* 0C0CCC 7F08C19C 8C6E0000 */  lw    $t6, ($v1)
/* 0C0CD0 7F08C1A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C0CD4 7F08C1A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C0CD8 7F08C1A8 8DC211E0 */  lw    $v0, 0x11e0($t6)
/* 0C0CDC 7F08C1AC 5040000B */  beql  $v0, $zero, .L7F08C1DC
/* 0C0CE0 7F08C1B0 AC84000C */   sw    $a0, 0xc($a0)
/* 0C0CE4 7F08C1B4 AC82000C */  sw    $v0, 0xc($a0)
/* 0C0CE8 7F08C1B8 8C6F0000 */  lw    $t7, ($v1)
/* 0C0CEC 7F08C1BC 8DF811E0 */  lw    $t8, 0x11e0($t7)
/* 0C0CF0 7F08C1C0 8F190010 */  lw    $t9, 0x10($t8)
/* 0C0CF4 7F08C1C4 AC990010 */  sw    $t9, 0x10($a0)
/* 0C0CF8 7F08C1C8 AC440010 */  sw    $a0, 0x10($v0)
/* 0C0CFC 7F08C1CC 8C890010 */  lw    $t1, 0x10($a0)
/* 0C0D00 7F08C1D0 10000003 */  b     .L7F08C1E0
/* 0C0D04 7F08C1D4 AD24000C */   sw    $a0, 0xc($t1)
/* 0C0D08 7F08C1D8 AC84000C */  sw    $a0, 0xc($a0)
.L7F08C1DC:
/* 0C0D0C 7F08C1DC AC840010 */  sw    $a0, 0x10($a0)
.L7F08C1E0:
/* 0C0D10 7F08C1E0 8C6A0000 */  lw    $t2, ($v1)
/* 0C0D14 7F08C1E4 0FC23015 */  jal   sub_GAME_7F08C054
/* 0C0D18 7F08C1E8 AD4411E0 */   sw    $a0, 0x11e0($t2)
/* 0C0D1C 7F08C1EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C0D20 7F08C1F0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C0D24 7F08C1F4 03E00008 */  jr    $ra
/* 0C0D28 7F08C1F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void reorder_inventory_ptrs_based_on_id_code(void) {

}
#else
GLOBAL_ASM(
.text
glabel reorder_inventory_ptrs_based_on_id_code
/* 0C0D2C 7F08C1FC 3C068008 */  lui   $a2, %hi(pPlayer)
/* 0C0D30 7F08C200 8CC6A0B0 */  lw    $a2, %lo(pPlayer)($a2)
/* 0C0D34 7F08C204 8C83000C */  lw    $v1, 0xc($a0)
/* 0C0D38 7F08C208 8C850010 */  lw    $a1, 0x10($a0)
/* 0C0D3C 7F08C20C 8CCE11E0 */  lw    $t6, 0x11e0($a2)
/* 0C0D40 7F08C210 240FFFFF */  li    $t7, -1
/* 0C0D44 7F08C214 00601025 */  move  $v0, $v1
/* 0C0D48 7F08C218 548E0007 */  bnel  $a0, $t6, .L7F08C238
/* 0C0D4C 7F08C21C AC450010 */   sw    $a1, 0x10($v0)
/* 0C0D50 7F08C220 54830004 */  bnel  $a0, $v1, .L7F08C234
/* 0C0D54 7F08C224 ACC311E0 */   sw    $v1, 0x11e0($a2)
/* 0C0D58 7F08C228 10000002 */  b     .L7F08C234
/* 0C0D5C 7F08C22C ACC011E0 */   sw    $zero, 0x11e0($a2)
/* 0C0D60 7F08C230 ACC311E0 */  sw    $v1, 0x11e0($a2)
.L7F08C234:
/* 0C0D64 7F08C234 AC450010 */  sw    $a1, 0x10($v0)
.L7F08C238:
/* 0C0D68 7F08C238 ACA2000C */  sw    $v0, 0xc($a1)
/* 0C0D6C 7F08C23C 03E00008 */  jr    $ra
/* 0C0D70 7F08C240 AC8F0000 */   sw    $t7, ($a0)
)
#endif





#ifdef NONMATCHING
void get_ptr_next_available_weapon(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_ptr_next_available_weapon
/* 0C0D74 7F08C244 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C0D78 7F08C248 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C0D7C 7F08C24C 00001025 */  move  $v0, $zero
/* 0C0D80 7F08C250 8C6411E8 */  lw    $a0, 0x11e8($v1)
/* 0C0D84 7F08C254 5880000F */  blezl $a0, .L7F08C294
/* 0C0D88 7F08C258 00001025 */   move  $v0, $zero
/* 0C0D8C 7F08C25C 8C6511E4 */  lw    $a1, 0x11e4($v1)
/* 0C0D90 7F08C260 2403FFFF */  li    $v1, -1
/* 0C0D94 7F08C264 00003025 */  move  $a2, $zero
/* 0C0D98 7F08C268 00A03825 */  move  $a3, $a1
.L7F08C26C:
/* 0C0D9C 7F08C26C 8CEE0000 */  lw    $t6, ($a3)
/* 0C0DA0 7F08C270 24420001 */  addiu $v0, $v0, 1
/* 0C0DA4 7F08C274 0044082A */  slt   $at, $v0, $a0
/* 0C0DA8 7F08C278 146E0003 */  bne   $v1, $t6, .L7F08C288
/* 0C0DAC 7F08C27C 24E70014 */   addiu $a3, $a3, 0x14
/* 0C0DB0 7F08C280 03E00008 */  jr    $ra
/* 0C0DB4 7F08C284 00A61021 */   addu  $v0, $a1, $a2

.L7F08C288:
/* 0C0DB8 7F08C288 1420FFF8 */  bnez  $at, .L7F08C26C
/* 0C0DBC 7F08C28C 24C60014 */   addiu $a2, $a2, 0x14
/* 0C0DC0 7F08C290 00001025 */  move  $v0, $zero
.L7F08C294:
/* 0C0DC4 7F08C294 03E00008 */  jr    $ra
/* 0C0DC8 7F08C298 00000000 */   nop   
)
#endif





void set_BONDdata_allguns_flag(s32 param_1) {
  pPlayer->equipallguns = param_1;
}

s32 get_BONDdata_allguns_flag(void) {
    return pPlayer->equipallguns;
}






#ifdef NONMATCHING
void get_ptr_inventory_item(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_ptr_inventory_item
/* 0C0DEC 7F08C2BC 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C0DF0 7F08C2C0 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C0DF4 7F08C2C4 24050001 */  li    $a1, 1
/* 0C0DF8 7F08C2C8 8DC211E0 */  lw    $v0, 0x11e0($t6)
/* 0C0DFC 7F08C2CC 1040000E */  beqz  $v0, .L7F08C308
/* 0C0E00 7F08C2D0 00401825 */   move  $v1, $v0
/* 0C0E04 7F08C2D4 8C6F0000 */  lw    $t7, ($v1)
.L7F08C2D8:
/* 0C0E08 7F08C2D8 54AF0007 */  bnel  $a1, $t7, .L7F08C2F8
/* 0C0E0C 7F08C2DC 8C63000C */   lw    $v1, 0xc($v1)
/* 0C0E10 7F08C2E0 8C780004 */  lw    $t8, 4($v1)
/* 0C0E14 7F08C2E4 54980004 */  bnel  $a0, $t8, .L7F08C2F8
/* 0C0E18 7F08C2E8 8C63000C */   lw    $v1, 0xc($v1)
/* 0C0E1C 7F08C2EC 03E00008 */  jr    $ra
/* 0C0E20 7F08C2F0 00601025 */   move  $v0, $v1

/* 0C0E24 7F08C2F4 8C63000C */  lw    $v1, 0xc($v1)
.L7F08C2F8:
/* 0C0E28 7F08C2F8 50620004 */  beql  $v1, $v0, .L7F08C30C
/* 0C0E2C 7F08C2FC 00001025 */   move  $v0, $zero
/* 0C0E30 7F08C300 5460FFF5 */  bnezl $v1, .L7F08C2D8
/* 0C0E34 7F08C304 8C6F0000 */   lw    $t7, ($v1)
.L7F08C308:
/* 0C0E38 7F08C308 00001025 */  move  $v0, $zero
.L7F08C30C:
/* 0C0E3C 7F08C30C 03E00008 */  jr    $ra
/* 0C0E40 7F08C310 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void is_weapon_in_inv(void) {

}
#else
GLOBAL_ASM(
.text
glabel is_weapon_in_inv
/* 0C0E44 7F08C314 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C0E48 7F08C318 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C0E4C 7F08C31C 0FC230AF */  jal   get_ptr_inventory_item
/* 0C0E50 7F08C320 00000000 */   nop   
/* 0C0E54 7F08C324 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C0E58 7F08C328 0002702B */  sltu  $t6, $zero, $v0
/* 0C0E5C 7F08C32C 01C01025 */  move  $v0, $t6
/* 0C0E60 7F08C330 03E00008 */  jr    $ra
/* 0C0E64 7F08C334 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void get_ptr_inventory_for_item_in_hand(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_ptr_inventory_for_item_in_hand
/* 0C0E68 7F08C338 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C0E6C 7F08C33C 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C0E70 7F08C340 24060003 */  li    $a2, 3
/* 0C0E74 7F08C344 8DC211E0 */  lw    $v0, 0x11e0($t6)
/* 0C0E78 7F08C348 10400011 */  beqz  $v0, .L7F08C390
/* 0C0E7C 7F08C34C 00401825 */   move  $v1, $v0
/* 0C0E80 7F08C350 8C6F0000 */  lw    $t7, ($v1)
.L7F08C354:
/* 0C0E84 7F08C354 54CF000A */  bnel  $a2, $t7, .L7F08C380
/* 0C0E88 7F08C358 8C63000C */   lw    $v1, 0xc($v1)
/* 0C0E8C 7F08C35C 8C780004 */  lw    $t8, 4($v1)
/* 0C0E90 7F08C360 54980007 */  bnel  $a0, $t8, .L7F08C380
/* 0C0E94 7F08C364 8C63000C */   lw    $v1, 0xc($v1)
/* 0C0E98 7F08C368 8C790008 */  lw    $t9, 8($v1)
/* 0C0E9C 7F08C36C 54B90004 */  bnel  $a1, $t9, .L7F08C380
/* 0C0EA0 7F08C370 8C63000C */   lw    $v1, 0xc($v1)
/* 0C0EA4 7F08C374 03E00008 */  jr    $ra
/* 0C0EA8 7F08C378 00601025 */   move  $v0, $v1

/* 0C0EAC 7F08C37C 8C63000C */  lw    $v1, 0xc($v1)
.L7F08C380:
/* 0C0EB0 7F08C380 50620004 */  beql  $v1, $v0, .L7F08C394
/* 0C0EB4 7F08C384 00001025 */   move  $v0, $zero
/* 0C0EB8 7F08C388 5460FFF2 */  bnezl $v1, .L7F08C354
/* 0C0EBC 7F08C38C 8C6F0000 */   lw    $t7, ($v1)
.L7F08C390:
/* 0C0EC0 7F08C390 00001025 */  move  $v0, $zero
.L7F08C394:
/* 0C0EC4 7F08C394 03E00008 */  jr    $ra
/* 0C0EC8 7F08C398 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void is_item_for_hand_in_inventory(void) {

}
#else
GLOBAL_ASM(
.text
glabel is_item_for_hand_in_inventory
/* 0C0ECC 7F08C39C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C0ED0 7F08C3A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C0ED4 7F08C3A4 0FC230CE */  jal   get_ptr_inventory_for_item_in_hand
/* 0C0ED8 7F08C3A8 00000000 */   nop   
/* 0C0EDC 7F08C3AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C0EE0 7F08C3B0 0002702B */  sltu  $t6, $zero, $v0
/* 0C0EE4 7F08C3B4 01C01025 */  move  $v0, $t6
/* 0C0EE8 7F08C3B8 03E00008 */  jr    $ra
/* 0C0EEC 7F08C3BC 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
void check_if_item_available(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel check_if_item_available
/* 0C0EF0 7F08C3C0 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C0EF4 7F08C3C4 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C0EF8 7F08C3C8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C0EFC 7F08C3CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C0F00 7F08C3D0 8DCF11EC */  lw    $t7, 0x11ec($t6)
/* 0C0F04 7F08C3D4 11E00007 */  beqz  $t7, .L7F08C3F4
/* 0C0F08 7F08C3D8 00000000 */   nop   
/* 0C0F0C 7F08C3DC 10800005 */  beqz  $a0, .L7F08C3F4
/* 0C0F10 7F08C3E0 28810021 */   slti  $at, $a0, 0x21
/* 0C0F14 7F08C3E4 10200003 */  beqz  $at, .L7F08C3F4
/* 0C0F18 7F08C3E8 00000000 */   nop   
/* 0C0F1C 7F08C3EC 10000003 */  b     .L7F08C3FC
/* 0C0F20 7F08C3F0 24020001 */   li    $v0, 1
.L7F08C3F4:
/* 0C0F24 7F08C3F4 0FC230C5 */  jal   is_weapon_in_inv
/* 0C0F28 7F08C3F8 00000000 */   nop   
.L7F08C3FC:
/* 0C0F2C 7F08C3FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C0F30 7F08C400 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C0F34 7F08C404 03E00008 */  jr    $ra
/* 0C0F38 7F08C408 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel check_if_item_available
/* 0C17C0 7F08CC50 3C0E8008 */  lui   $t6, %hi(pPlayer) # $t6, 0x8008
/* 0C17C4 7F08CC54 8DCEA120 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C17C8 7F08CC58 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C17CC 7F08CC5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C17D0 7F08CC60 8DCF11EC */  lw    $t7, 0x11ec($t6)
/* 0C17D4 7F08CC64 11E0000D */  beqz  $t7, .Ljp7F08CC9C
/* 0C17D8 7F08CC68 00000000 */   nop   
/* 0C17DC 7F08CC6C 1080000B */  beqz  $a0, .Ljp7F08CC9C
/* 0C17E0 7F08CC70 28810021 */   slti  $at, $a0, 0x21
/* 0C17E4 7F08CC74 10200009 */  beqz  $at, .Ljp7F08CC9C
/* 0C17E8 7F08CC78 3C188005 */   lui   $t8, %hi(j_text_trigger) # $t8, 0x8005
/* 0C17EC 7F08CC7C 8F188500 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0C17F0 7F08CC80 24010002 */  li    $at, 2
/* 0C17F4 7F08CC84 13000003 */  beqz  $t8, .Ljp7F08CC94
/* 0C17F8 7F08CC88 00000000 */   nop   
/* 0C17FC 7F08CC8C 10810003 */  beq   $a0, $at, .Ljp7F08CC9C
/* 0C1800 7F08CC90 00000000 */   nop   
.Ljp7F08CC94:
/* 0C1804 7F08CC94 10000003 */  b     .Ljp7F08CCA4
/* 0C1808 7F08CC98 24020001 */   li    $v0, 1
.Ljp7F08CC9C:
/* 0C180C 7F08CC9C 0FC232E9 */  jal   is_weapon_in_inv
/* 0C1810 7F08CCA0 00000000 */   nop   
.Ljp7F08CCA4:
/* 0C1814 7F08CCA4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C1818 7F08CCA8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C181C 7F08CCAC 03E00008 */  jr    $ra
/* 0C1820 7F08CCB0 00000000 */   nop   
)
#endif

#endif




#ifdef NONMATCHING
void check_if_item_for_hand_available(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel check_if_item_for_hand_available
/* 0C0F3C 7F08C40C 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C0F40 7F08C410 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C0F44 7F08C414 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C0F48 7F08C418 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C0F4C 7F08C41C AFA5001C */  sw    $a1, 0x1c($sp)
/* 0C0F50 7F08C420 8DCF11EC */  lw    $t7, 0x11ec($t6)
/* 0C0F54 7F08C424 28810021 */  slti  $at, $a0, 0x21
/* 0C0F58 7F08C428 11E00011 */  beqz  $t7, .L7F08C470
/* 0C0F5C 7F08C42C 00000000 */   nop   
/* 0C0F60 7F08C430 1020000F */  beqz  $at, .L7F08C470
/* 0C0F64 7F08C434 00000000 */   nop   
/* 0C0F68 7F08C438 1485000D */  bne   $a0, $a1, .L7F08C470
/* 0C0F6C 7F08C43C 00000000 */   nop   
/* 0C0F70 7F08C440 0FC26919 */  jal   get_num_players
/* 0C0F74 7F08C444 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C0F78 7F08C448 24010001 */  li    $at, 1
/* 0C0F7C 7F08C44C 14410008 */  bne   $v0, $at, .L7F08C470
/* 0C0F80 7F08C450 8FA40018 */   lw    $a0, 0x18($sp)
/* 0C0F84 7F08C454 3C050010 */  lui   $a1, 0x10
/* 0C0F88 7F08C458 0FC1782D */  jal   check_special_attributes
/* 0C0F8C 7F08C45C AFA40018 */   sw    $a0, 0x18($sp)
/* 0C0F90 7F08C460 10400003 */  beqz  $v0, .L7F08C470
/* 0C0F94 7F08C464 8FA40018 */   lw    $a0, 0x18($sp)
/* 0C0F98 7F08C468 10000003 */  b     .L7F08C478
/* 0C0F9C 7F08C46C 24020001 */   li    $v0, 1
.L7F08C470:
/* 0C0FA0 7F08C470 0FC230E7 */  jal   is_item_for_hand_in_inventory
/* 0C0FA4 7F08C474 8FA5001C */   lw    $a1, 0x1c($sp)
.L7F08C478:
/* 0C0FA8 7F08C478 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C0FAC 7F08C47C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C0FB0 7F08C480 03E00008 */  jr    $ra
/* 0C0FB4 7F08C484 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel check_if_item_for_hand_available
/* 0C1824 7F08CCB4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C1828 7F08CCB8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C182C 7F08CCBC 14A00003 */  bnez  $a1, .Ljp7F08CCCC
/* 0C1830 7F08CCC0 00A03025 */   move  $a2, $a1
/* 0C1834 7F08CCC4 10000024 */  b     .Ljp7F08CD58
/* 0C1838 7F08CCC8 24020001 */   li    $v0, 1
.Ljp7F08CCCC:
/* 0C183C 7F08CCCC 3C0E8008 */  lui   $t6, %hi(pPlayer) # $t6, 0x8008
/* 0C1840 7F08CCD0 8DCEA120 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1844 7F08CCD4 28810021 */  slti  $at, $a0, 0x21
/* 0C1848 7F08CCD8 8DCF11EC */  lw    $t7, 0x11ec($t6)
/* 0C184C 7F08CCDC 11E0001C */  beqz  $t7, .Ljp7F08CD50
/* 0C1850 7F08CCE0 00000000 */   nop   
/* 0C1854 7F08CCE4 1020001A */  beqz  $at, .Ljp7F08CD50
/* 0C1858 7F08CCE8 00000000 */   nop   
/* 0C185C 7F08CCEC 14860018 */  bne   $a0, $a2, .Ljp7F08CD50
/* 0C1860 7F08CCF0 00000000 */   nop   
/* 0C1864 7F08CCF4 AFA40018 */  sw    $a0, 0x18($sp)
/* 0C1868 7F08CCF8 0FC26C01 */  jal   get_num_players
/* 0C186C 7F08CCFC AFA6001C */   sw    $a2, 0x1c($sp)
/* 0C1870 7F08CD00 24010001 */  li    $at, 1
/* 0C1874 7F08CD04 8FA40018 */  lw    $a0, 0x18($sp)
/* 0C1878 7F08CD08 14410011 */  bne   $v0, $at, .Ljp7F08CD50
/* 0C187C 7F08CD0C 8FA6001C */   lw    $a2, 0x1c($sp)
/* 0C1880 7F08CD10 3C050010 */  lui   $a1, 0x10
/* 0C1884 7F08CD14 AFA40018 */  sw    $a0, 0x18($sp)
/* 0C1888 7F08CD18 0FC17975 */  jal   check_special_attributes
/* 0C188C 7F08CD1C AFA6001C */   sw    $a2, 0x1c($sp)
/* 0C1890 7F08CD20 8FA40018 */  lw    $a0, 0x18($sp)
/* 0C1894 7F08CD24 1040000A */  beqz  $v0, .Ljp7F08CD50
/* 0C1898 7F08CD28 8FA6001C */   lw    $a2, 0x1c($sp)
/* 0C189C 7F08CD2C 3C188005 */  lui   $t8, %hi(j_text_trigger) # $t8, 0x8005
/* 0C18A0 7F08CD30 8F188500 */  lw    $t8, %lo(j_text_trigger)($t8)
/* 0C18A4 7F08CD34 24010002 */  li    $at, 2
/* 0C18A8 7F08CD38 13000003 */  beqz  $t8, .Ljp7F08CD48
/* 0C18AC 7F08CD3C 00000000 */   nop   
/* 0C18B0 7F08CD40 10810003 */  beq   $a0, $at, .Ljp7F08CD50
/* 0C18B4 7F08CD44 00000000 */   nop   
.Ljp7F08CD48:
/* 0C18B8 7F08CD48 10000003 */  b     .Ljp7F08CD58
/* 0C18BC 7F08CD4C 24020001 */   li    $v0, 1
.Ljp7F08CD50:
/* 0C18C0 7F08CD50 0FC2330B */  jal   is_item_for_hand_in_inventory
/* 0C18C4 7F08CD54 00C02825 */   move  $a1, $a2
.Ljp7F08CD58:
/* 0C18C8 7F08CD58 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C18CC 7F08CD5C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C18D0 7F08CD60 03E00008 */  jr    $ra
/* 0C18D4 7F08CD64 00000000 */   nop    
)
#endif

#endif




#ifdef NONMATCHING
void add_item_to_inventory(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel add_item_to_inventory
/* 0C0FB8 7F08C488 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C0FBC 7F08C48C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C0FC0 7F08C490 0FC230C5 */  jal   is_weapon_in_inv
/* 0C0FC4 7F08C494 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C0FC8 7F08C498 54400018 */  bnezl $v0, .L7F08C4FC
/* 0C0FCC 7F08C49C 00001025 */   move  $v0, $zero
/* 0C0FD0 7F08C4A0 0FC23091 */  jal   get_ptr_next_available_weapon
/* 0C0FD4 7F08C4A4 00000000 */   nop   
/* 0C0FD8 7F08C4A8 10400006 */  beqz  $v0, .L7F08C4C4
/* 0C0FDC 7F08C4AC 00402025 */   move  $a0, $v0
/* 0C0FE0 7F08C4B0 240E0001 */  li    $t6, 1
/* 0C0FE4 7F08C4B4 AC4E0000 */  sw    $t6, ($v0)
/* 0C0FE8 7F08C4B8 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0C0FEC 7F08C4BC 0FC23065 */  jal   add_additional_weapon_slot_to_player_inventory_guess
/* 0C0FF0 7F08C4C0 AC4F0004 */   sw    $t7, 4($v0)
.L7F08C4C4:
/* 0C0FF4 7F08C4C4 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C0FF8 7F08C4C8 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C0FFC 7F08C4CC 8FA80018 */  lw    $t0, 0x18($sp)
/* 0C1000 7F08C4D0 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C1004 7F08C4D4 29010021 */  slti  $at, $t0, 0x21
/* 0C1008 7F08C4D8 13200005 */  beqz  $t9, .L7F08C4F0
/* 0C100C 7F08C4DC 00000000 */   nop   
/* 0C1010 7F08C4E0 10200003 */  beqz  $at, .L7F08C4F0
/* 0C1014 7F08C4E4 00000000 */   nop   
/* 0C1018 7F08C4E8 10000004 */  b     .L7F08C4FC
/* 0C101C 7F08C4EC 00001025 */   move  $v0, $zero
.L7F08C4F0:
/* 0C1020 7F08C4F0 10000002 */  b     .L7F08C4FC
/* 0C1024 7F08C4F4 24020001 */   li    $v0, 1
/* 0C1028 7F08C4F8 00001025 */  move  $v0, $zero
.L7F08C4FC:
/* 0C102C 7F08C4FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C1030 7F08C500 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C1034 7F08C504 03E00008 */  jr    $ra
/* 0C1038 7F08C508 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel add_item_to_inventory
/* 0C18D8 7F08CD68 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C18DC 7F08CD6C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C18E0 7F08CD70 0FC232E9 */  jal   is_weapon_in_inv
/* 0C18E4 7F08CD74 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C18E8 7F08CD78 5440001E */  bnezl $v0, .Ljp7F08CDF4
/* 0C18EC 7F08CD7C 00001025 */   move  $v0, $zero
/* 0C18F0 7F08CD80 0FC232B5 */  jal   get_ptr_next_available_weapon
/* 0C18F4 7F08CD84 00000000 */   nop   
/* 0C18F8 7F08CD88 10400006 */  beqz  $v0, .Ljp7F08CDA4
/* 0C18FC 7F08CD8C 00402025 */   move  $a0, $v0
/* 0C1900 7F08CD90 240E0001 */  li    $t6, 1
/* 0C1904 7F08CD94 AC4E0000 */  sw    $t6, ($v0)
/* 0C1908 7F08CD98 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0C190C 7F08CD9C 0FC23289 */  jal   add_additional_weapon_slot_to_player_inventory_guess
/* 0C1910 7F08CDA0 AC4F0004 */   sw    $t7, 4($v0)
.Ljp7F08CDA4:
/* 0C1914 7F08CDA4 3C188008 */  lui   $t8, %hi(pPlayer) # $t8, 0x8008
/* 0C1918 7F08CDA8 8F18A120 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C191C 7F08CDAC 8FA80018 */  lw    $t0, 0x18($sp)
/* 0C1920 7F08CDB0 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C1924 7F08CDB4 29010021 */  slti  $at, $t0, 0x21
/* 0C1928 7F08CDB8 1320000B */  beqz  $t9, .Ljp7F08CDE8
/* 0C192C 7F08CDBC 00000000 */   nop   
/* 0C1930 7F08CDC0 10200009 */  beqz  $at, .Ljp7F08CDE8
/* 0C1934 7F08CDC4 3C098005 */   lui   $t1, %hi(j_text_trigger) # $t1, 0x8005
/* 0C1938 7F08CDC8 8D298500 */  lw    $t1, %lo(j_text_trigger)($t1)
/* 0C193C 7F08CDCC 24010002 */  li    $at, 2
/* 0C1940 7F08CDD0 11200003 */  beqz  $t1, .Ljp7F08CDE0
/* 0C1944 7F08CDD4 00000000 */   nop   
/* 0C1948 7F08CDD8 11010003 */  beq   $t0, $at, .Ljp7F08CDE8
/* 0C194C 7F08CDDC 00000000 */   nop   
.Ljp7F08CDE0:
/* 0C1950 7F08CDE0 10000004 */  b     .Ljp7F08CDF4
/* 0C1954 7F08CDE4 00001025 */   move  $v0, $zero
.Ljp7F08CDE8:
/* 0C1958 7F08CDE8 10000002 */  b     .Ljp7F08CDF4
/* 0C195C 7F08CDEC 24020001 */   li    $v0, 1
/* 0C1960 7F08CDF0 00001025 */  move  $v0, $zero
.Ljp7F08CDF4:
/* 0C1964 7F08CDF4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C1968 7F08CDF8 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C196C 7F08CDFC 03E00008 */  jr    $ra
/* 0C1970 7F08CE00 00000000 */   nop    
)
#endif

#endif



#ifdef NONMATCHING
void add_doubles_item_to_inventory(void) {

}
#else
GLOBAL_ASM(
.text
glabel add_doubles_item_to_inventory
/* 0C103C 7F08C50C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C1040 7F08C510 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1044 7F08C514 AFA40018 */  sw    $a0, 0x18($sp)
/* 0C1048 7F08C518 0FC230E7 */  jal   is_item_for_hand_in_inventory
/* 0C104C 7F08C51C AFA5001C */   sw    $a1, 0x1c($sp)
/* 0C1050 7F08C520 5440000F */  bnezl $v0, .L7F08C560
/* 0C1054 7F08C524 00001025 */   move  $v0, $zero
/* 0C1058 7F08C528 0FC23091 */  jal   get_ptr_next_available_weapon
/* 0C105C 7F08C52C 00000000 */   nop   
/* 0C1060 7F08C530 10400008 */  beqz  $v0, .L7F08C554
/* 0C1064 7F08C534 00402025 */   move  $a0, $v0
/* 0C1068 7F08C538 240E0003 */  li    $t6, 3
/* 0C106C 7F08C53C AC4E0000 */  sw    $t6, ($v0)
/* 0C1070 7F08C540 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0C1074 7F08C544 AC4F0004 */  sw    $t7, 4($v0)
/* 0C1078 7F08C548 8FB8001C */  lw    $t8, 0x1c($sp)
/* 0C107C 7F08C54C 0FC23065 */  jal   add_additional_weapon_slot_to_player_inventory_guess
/* 0C1080 7F08C550 AC580008 */   sw    $t8, 8($v0)
.L7F08C554:
/* 0C1084 7F08C554 10000002 */  b     .L7F08C560
/* 0C1088 7F08C558 24020001 */   li    $v0, 1
/* 0C108C 7F08C55C 00001025 */  move  $v0, $zero
.L7F08C560:
/* 0C1090 7F08C560 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C1094 7F08C564 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C1098 7F08C568 03E00008 */  jr    $ra
/* 0C109C 7F08C56C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08C570(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08C570
/* 0C10A0 7F08C570 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C10A4 7F08C574 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C10A8 7F08C578 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C10AC 7F08C57C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C10B0 7F08C580 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C10B4 7F08C584 8DC611E0 */  lw    $a2, 0x11e0($t6)
/* 0C10B8 7F08C588 00808025 */  move  $s0, $a0
/* 0C10BC 7F08C58C 240A0008 */  li    $t2, 8
/* 0C10C0 7F08C590 10C0001C */  beqz  $a2, .L7F08C604
/* 0C10C4 7F08C594 24090004 */   li    $t1, 4
/* 0C10C8 7F08C598 8CC4000C */  lw    $a0, 0xc($a2)
/* 0C10CC 7F08C59C 24080002 */  li    $t0, 2
.L7F08C5A0:
/* 0C10D0 7F08C5A0 8C8F0000 */  lw    $t7, ($a0)
/* 0C10D4 7F08C5A4 8C87000C */  lw    $a3, 0xc($a0)
/* 0C10D8 7F08C5A8 150F0010 */  bne   $t0, $t7, .L7F08C5EC
/* 0C10DC 7F08C5AC 00000000 */   nop   
/* 0C10E0 7F08C5B0 8C830004 */  lw    $v1, 4($a0)
/* 0C10E4 7F08C5B4 90780000 */  lbu   $t8, ($v1)
/* 0C10E8 7F08C5B8 1538000C */  bne   $t1, $t8, .L7F08C5EC
/* 0C10EC 7F08C5BC 00000000 */   nop   
/* 0C10F0 7F08C5C0 8C650004 */  lw    $a1, 4($v1)
/* 0C10F4 7F08C5C4 90B90003 */  lbu   $t9, 3($a1)
/* 0C10F8 7F08C5C8 15590008 */  bne   $t2, $t9, .L7F08C5EC
/* 0C10FC 7F08C5CC 00000000 */   nop   
/* 0C1100 7F08C5D0 80AB0080 */  lb    $t3, 0x80($a1)
/* 0C1104 7F08C5D4 160B0005 */  bne   $s0, $t3, .L7F08C5EC
/* 0C1108 7F08C5D8 00000000 */   nop   
/* 0C110C 7F08C5DC 0FC2307F */  jal   reorder_inventory_ptrs_based_on_id_code
/* 0C1110 7F08C5E0 AFA50024 */   sw    $a1, 0x24($sp)
/* 0C1114 7F08C5E4 10000008 */  b     .L7F08C608
/* 0C1118 7F08C5E8 8FA20024 */   lw    $v0, 0x24($sp)
.L7F08C5EC:
/* 0C111C 7F08C5EC 50860006 */  beql  $a0, $a2, .L7F08C608
/* 0C1120 7F08C5F0 00001025 */   move  $v0, $zero
/* 0C1124 7F08C5F4 50C00004 */  beql  $a2, $zero, .L7F08C608
/* 0C1128 7F08C5F8 00001025 */   move  $v0, $zero
/* 0C112C 7F08C5FC 1000FFE8 */  b     .L7F08C5A0
/* 0C1130 7F08C600 00E02025 */   move  $a0, $a3
.L7F08C604:
/* 0C1134 7F08C604 00001025 */  move  $v0, $zero
.L7F08C608:
/* 0C1138 7F08C608 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C113C 7F08C60C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C1140 7F08C610 27BD0038 */  addiu $sp, $sp, 0x38
/* 0C1144 7F08C614 03E00008 */  jr    $ra
/* 0C1148 7F08C618 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08C61C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08C61C
/* 0C114C 7F08C61C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C1150 7F08C620 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C1154 7F08C624 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1158 7F08C628 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0C115C 7F08C62C AFB60030 */  sw    $s6, 0x30($sp)
/* 0C1160 7F08C630 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0C1164 7F08C634 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C1168 7F08C638 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C116C 7F08C63C AFB20020 */  sw    $s2, 0x20($sp)
/* 0C1170 7F08C640 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C1174 7F08C644 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C1178 7F08C648 8DC511E0 */  lw    $a1, 0x11e0($t6)
/* 0C117C 7F08C64C 00809025 */  move  $s2, $a0
/* 0C1180 7F08C650 24150008 */  li    $s5, 8
/* 0C1184 7F08C654 10A00029 */  beqz  $a1, .L7F08C6FC
/* 0C1188 7F08C658 24160001 */   li    $s6, 1
/* 0C118C 7F08C65C 8CB0000C */  lw    $s0, 0xc($a1)
/* 0C1190 7F08C660 24140004 */  li    $s4, 4
/* 0C1194 7F08C664 24130002 */  li    $s3, 2
.L7F08C668:
/* 0C1198 7F08C668 8E020000 */  lw    $v0, ($s0)
/* 0C119C 7F08C66C 8E11000C */  lw    $s1, 0xc($s0)
/* 0C11A0 7F08C670 16620012 */  bne   $s3, $v0, .L7F08C6BC
/* 0C11A4 7F08C674 00000000 */   nop   
/* 0C11A8 7F08C678 8E030004 */  lw    $v1, 4($s0)
/* 0C11AC 7F08C67C 906F0000 */  lbu   $t7, ($v1)
/* 0C11B0 7F08C680 168F0018 */  bne   $s4, $t7, .L7F08C6E4
/* 0C11B4 7F08C684 00000000 */   nop   
/* 0C11B8 7F08C688 8C640004 */  lw    $a0, 4($v1)
/* 0C11BC 7F08C68C 90980003 */  lbu   $t8, 3($a0)
/* 0C11C0 7F08C690 16B80014 */  bne   $s5, $t8, .L7F08C6E4
/* 0C11C4 7F08C694 00000000 */   nop   
/* 0C11C8 7F08C698 80990080 */  lb    $t9, 0x80($a0)
/* 0C11CC 7F08C69C 16590011 */  bne   $s2, $t9, .L7F08C6E4
/* 0C11D0 7F08C6A0 00000000 */   nop   
/* 0C11D4 7F08C6A4 0FC2307F */  jal   reorder_inventory_ptrs_based_on_id_code
/* 0C11D8 7F08C6A8 02002025 */   move  $a0, $s0
/* 0C11DC 7F08C6AC 3C088008 */  lui   $t0, %hi(pPlayer) 
/* 0C11E0 7F08C6B0 8D08A0B0 */  lw    $t0, %lo(pPlayer)($t0)
/* 0C11E4 7F08C6B4 1000000B */  b     .L7F08C6E4
/* 0C11E8 7F08C6B8 8D0511E0 */   lw    $a1, 0x11e0($t0)
.L7F08C6BC:
/* 0C11EC 7F08C6BC 16C20009 */  bne   $s6, $v0, .L7F08C6E4
/* 0C11F0 7F08C6C0 00000000 */   nop   
/* 0C11F4 7F08C6C4 8E090004 */  lw    $t1, 4($s0)
/* 0C11F8 7F08C6C8 16490006 */  bne   $s2, $t1, .L7F08C6E4
/* 0C11FC 7F08C6CC 00000000 */   nop   
/* 0C1200 7F08C6D0 0FC2307F */  jal   reorder_inventory_ptrs_based_on_id_code
/* 0C1204 7F08C6D4 02002025 */   move  $a0, $s0
/* 0C1208 7F08C6D8 3C0A8008 */  lui   $t2, %hi(pPlayer) 
/* 0C120C 7F08C6DC 8D4AA0B0 */  lw    $t2, %lo(pPlayer)($t2)
/* 0C1210 7F08C6E0 8D4511E0 */  lw    $a1, 0x11e0($t2)
.L7F08C6E4:
/* 0C1214 7F08C6E4 52050006 */  beql  $s0, $a1, .L7F08C700
/* 0C1218 7F08C6E8 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0C121C 7F08C6EC 50A00004 */  beql  $a1, $zero, .L7F08C700
/* 0C1220 7F08C6F0 8FBF0034 */   lw    $ra, 0x34($sp)
/* 0C1224 7F08C6F4 1000FFDC */  b     .L7F08C668
/* 0C1228 7F08C6F8 02208025 */   move  $s0, $s1
.L7F08C6FC:
/* 0C122C 7F08C6FC 8FBF0034 */  lw    $ra, 0x34($sp)
.L7F08C700:
/* 0C1230 7F08C700 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C1234 7F08C704 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C1238 7F08C708 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C123C 7F08C70C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C1240 7F08C710 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C1244 7F08C714 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0C1248 7F08C718 8FB60030 */  lw    $s6, 0x30($sp)
/* 0C124C 7F08C71C 03E00008 */  jr    $ra
/* 0C1250 7F08C720 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08C724(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08C724
/* 0C1254 7F08C724 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C1258 7F08C728 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C125C 7F08C72C 0FC23091 */  jal   get_ptr_next_available_weapon
/* 0C1260 7F08C730 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C1264 7F08C734 10400006 */  beqz  $v0, .L7F08C750
/* 0C1268 7F08C738 00402025 */   move  $a0, $v0
/* 0C126C 7F08C73C 240E0002 */  li    $t6, 2
/* 0C1270 7F08C740 AC4E0000 */  sw    $t6, ($v0)
/* 0C1274 7F08C744 8FAF0018 */  lw    $t7, 0x18($sp)
/* 0C1278 7F08C748 0FC23065 */  jal   add_additional_weapon_slot_to_player_inventory_guess
/* 0C127C 7F08C74C AC4F0004 */   sw    $t7, 4($v0)
.L7F08C750:
/* 0C1280 7F08C750 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C1284 7F08C754 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C1288 7F08C758 24020001 */  li    $v0, 1
/* 0C128C 7F08C75C 03E00008 */  jr    $ra
/* 0C1290 7F08C760 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08C764(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08C764
/* 0C1294 7F08C764 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C1298 7F08C768 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C129C 7F08C76C AFB00018 */  sw    $s0, 0x18($sp)
/* 0C12A0 7F08C770 908E0000 */  lbu   $t6, ($a0)
/* 0C12A4 7F08C774 24010004 */  li    $at, 4
/* 0C12A8 7F08C778 00002825 */  move  $a1, $zero
/* 0C12AC 7F08C77C 55C10037 */  bnel  $t6, $at, .L7F08C85C
/* 0C12B0 7F08C780 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0C12B4 7F08C784 8C860004 */  lw    $a2, 4($a0)
/* 0C12B8 7F08C788 24010008 */  li    $at, 8
/* 0C12BC 7F08C78C 90CF0003 */  lbu   $t7, 3($a2)
/* 0C12C0 7F08C790 55E10032 */  bnel  $t7, $at, .L7F08C85C
/* 0C12C4 7F08C794 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0C12C8 7F08C798 80D00080 */  lb    $s0, 0x80($a2)
/* 0C12CC 7F08C79C AFA60024 */  sw    $a2, 0x24($sp)
/* 0C12D0 7F08C7A0 0FC23122 */  jal   add_item_to_inventory
/* 0C12D4 7F08C7A4 02002025 */   move  $a0, $s0
/* 0C12D8 7F08C7A8 8FA30024 */  lw    $v1, 0x24($sp)
/* 0C12DC 7F08C7AC 00402825 */  move  $a1, $v0
/* 0C12E0 7F08C7B0 8C660084 */  lw    $a2, 0x84($v1)
/* 0C12E4 7F08C7B4 50C00019 */  beql  $a2, $zero, .L7F08C81C
/* 0C12E8 7F08C7B8 80660081 */   lb    $a2, 0x81($v1)
/* 0C12EC 7F08C7BC 8C780008 */  lw    $t8, 8($v1)
/* 0C12F0 7F08C7C0 02002825 */  move  $a1, $s0
/* 0C12F4 7F08C7C4 02002025 */  move  $a0, $s0
/* 0C12F8 7F08C7C8 0018C8C0 */  sll   $t9, $t8, 3
/* 0C12FC 7F08C7CC 07230008 */  bgezl $t9, .L7F08C7F0
/* 0C1300 7F08C7D0 80C50080 */   lb    $a1, 0x80($a2)
/* 0C1304 7F08C7D4 80C40080 */  lb    $a0, 0x80($a2)
/* 0C1308 7F08C7D8 0FC230E7 */  jal   is_item_for_hand_in_inventory
/* 0C130C 7F08C7DC AFA30024 */   sw    $v1, 0x24($sp)
/* 0C1310 7F08C7E0 8FA30024 */  lw    $v1, 0x24($sp)
/* 0C1314 7F08C7E4 10000006 */  b     .L7F08C800
/* 0C1318 7F08C7E8 2C450001 */   sltiu $a1, $v0, 1
/* 0C131C 7F08C7EC 80C50080 */  lb    $a1, 0x80($a2)
.L7F08C7F0:
/* 0C1320 7F08C7F0 0FC230E7 */  jal   is_item_for_hand_in_inventory
/* 0C1324 7F08C7F4 AFA30024 */   sw    $v1, 0x24($sp)
/* 0C1328 7F08C7F8 8FA30024 */  lw    $v1, 0x24($sp)
/* 0C132C 7F08C7FC 2C450001 */  sltiu $a1, $v0, 1
.L7F08C800:
/* 0C1330 7F08C800 8C680084 */  lw    $t0, 0x84($v1)
/* 0C1334 7F08C804 A1100081 */  sb    $s0, 0x81($t0)
/* 0C1338 7F08C808 8C690084 */  lw    $t1, 0x84($v1)
/* 0C133C 7F08C80C AD200084 */  sw    $zero, 0x84($t1)
/* 0C1340 7F08C810 10000011 */  b     .L7F08C858
/* 0C1344 7F08C814 AC600084 */   sw    $zero, 0x84($v1)
/* 0C1348 7F08C818 80660081 */  lb    $a2, 0x81($v1)
.L7F08C81C:
/* 0C134C 7F08C81C 04C2000F */  bltzl $a2, .L7F08C85C
/* 0C1350 7F08C820 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0C1354 7F08C824 8C6A0008 */  lw    $t2, 8($v1)
/* 0C1358 7F08C828 02002825 */  move  $a1, $s0
/* 0C135C 7F08C82C 02002025 */  move  $a0, $s0
/* 0C1360 7F08C830 000A58C0 */  sll   $t3, $t2, 3
/* 0C1364 7F08C834 05610005 */  bgez  $t3, .L7F08C84C
/* 0C1368 7F08C838 00000000 */   nop   
/* 0C136C 7F08C83C 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C1370 7F08C840 00C02025 */   move  $a0, $a2
/* 0C1374 7F08C844 10000004 */  b     .L7F08C858
/* 0C1378 7F08C848 00402825 */   move  $a1, $v0
.L7F08C84C:
/* 0C137C 7F08C84C 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C1380 7F08C850 00C02825 */   move  $a1, $a2
/* 0C1384 7F08C854 00402825 */  move  $a1, $v0
.L7F08C858:
/* 0C1388 7F08C858 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F08C85C:
/* 0C138C 7F08C85C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C1390 7F08C860 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C1394 7F08C864 03E00008 */  jr    $ra
/* 0C1398 7F08C868 00A01025 */   move  $v0, $a1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08C86C(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08C86C
/* 0C139C 7F08C86C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C13A0 7F08C870 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C13A4 7F08C874 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C13A8 7F08C878 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C13AC 7F08C87C AFB30020 */  sw    $s3, 0x20($sp)
/* 0C13B0 7F08C880 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C13B4 7F08C884 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C13B8 7F08C888 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C13BC 7F08C88C AFA40028 */  sw    $a0, 0x28($sp)
/* 0C13C0 7F08C890 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0C13C4 7F08C894 8C7011E0 */  lw    $s0, 0x11e0($v1)
/* 0C13C8 7F08C898 00C09025 */  move  $s2, $a2
/* 0C13CC 7F08C89C 8C910000 */  lw    $s1, ($a0)
/* 0C13D0 7F08C8A0 1200003D */  beqz  $s0, .L7F08C998
/* 0C13D4 7F08C8A4 8CB30000 */   lw    $s3, ($a1)
/* 0C13D8 7F08C8A8 8E020000 */  lw    $v0, ($s0)
.L7F08C8AC:
/* 0C13DC 7F08C8AC 24010001 */  li    $at, 1
/* 0C13E0 7F08C8B0 54410013 */  bnel  $v0, $at, .L7F08C900
/* 0C13E4 7F08C8B4 24010003 */   li    $at, 3
/* 0C13E8 7F08C8B8 8E040004 */  lw    $a0, 4($s0)
/* 0C13EC 7F08C8BC 28810021 */  slti  $at, $a0, 0x21
/* 0C13F0 7F08C8C0 10200029 */  beqz  $at, .L7F08C968
/* 0C13F4 7F08C8C4 0224082A */   slt   $at, $s1, $a0
/* 0C13F8 7F08C8C8 10200027 */  beqz  $at, .L7F08C968
/* 0C13FC 7F08C8CC 00000000 */   nop   
/* 0C1400 7F08C8D0 52400008 */  beql  $s2, $zero, .L7F08C8F4
/* 0C1404 7F08C8D4 00808825 */   move  $s1, $a0
/* 0C1408 7F08C8D8 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C140C 7F08C8DC 00000000 */   nop   
/* 0C1410 7F08C8E0 10400021 */  beqz  $v0, .L7F08C968
/* 0C1414 7F08C8E4 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C1418 7F08C8E8 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C141C 7F08C8EC 8E040004 */  lw    $a0, 4($s0)
/* 0C1420 7F08C8F0 00808825 */  move  $s1, $a0
.L7F08C8F4:
/* 0C1424 7F08C8F4 10000028 */  b     .L7F08C998
/* 0C1428 7F08C8F8 00009825 */   move  $s3, $zero
/* 0C142C 7F08C8FC 24010003 */  li    $at, 3
.L7F08C900:
/* 0C1430 7F08C900 14410019 */  bne   $v0, $at, .L7F08C968
/* 0C1434 7F08C904 00000000 */   nop   
/* 0C1438 7F08C908 8E040004 */  lw    $a0, 4($s0)
/* 0C143C 7F08C90C 0224082A */  slt   $at, $s1, $a0
/* 0C1440 7F08C910 14200007 */  bnez  $at, .L7F08C930
/* 0C1444 7F08C914 00000000 */   nop   
/* 0C1448 7F08C918 16240013 */  bne   $s1, $a0, .L7F08C968
/* 0C144C 7F08C91C 00000000 */   nop   
/* 0C1450 7F08C920 8E180008 */  lw    $t8, 8($s0)
/* 0C1454 7F08C924 0278082A */  slt   $at, $s3, $t8
/* 0C1458 7F08C928 1020000F */  beqz  $at, .L7F08C968
/* 0C145C 7F08C92C 00000000 */   nop   
.L7F08C930:
/* 0C1460 7F08C930 12400008 */  beqz  $s2, .L7F08C954
/* 0C1464 7F08C934 00000000 */   nop   
/* 0C1468 7F08C938 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C146C 7F08C93C 00000000 */   nop   
/* 0C1470 7F08C940 14400004 */  bnez  $v0, .L7F08C954
/* 0C1474 7F08C944 00000000 */   nop   
/* 0C1478 7F08C948 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C147C 7F08C94C 8E040008 */   lw    $a0, 8($s0)
/* 0C1480 7F08C950 10400005 */  beqz  $v0, .L7F08C968
.L7F08C954:
/* 0C1484 7F08C954 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C1488 7F08C958 8E110004 */  lw    $s1, 4($s0)
/* 0C148C 7F08C95C 8E130008 */  lw    $s3, 8($s0)
/* 0C1490 7F08C960 1000000D */  b     .L7F08C998
/* 0C1494 7F08C964 8C63A0B0 */   lw    $v1, %lo(pPlayer)($v1)
.L7F08C968:
/* 0C1498 7F08C968 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C149C 7F08C96C 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C14A0 7F08C970 8E10000C */  lw    $s0, 0xc($s0)
/* 0C14A4 7F08C974 8C7911E0 */  lw    $t9, 0x11e0($v1)
/* 0C14A8 7F08C978 16190005 */  bne   $s0, $t9, .L7F08C990
/* 0C14AC 7F08C97C 00000000 */   nop   
/* 0C14B0 7F08C980 56400006 */  bnezl $s2, .L7F08C99C
/* 0C14B4 7F08C984 8C6811EC */   lw    $t0, 0x11ec($v1)
/* 0C14B8 7F08C988 2411FFFF */  li    $s1, -1
/* 0C14BC 7F08C98C 2413FFFF */  li    $s3, -1
.L7F08C990:
/* 0C14C0 7F08C990 5600FFC6 */  bnezl $s0, .L7F08C8AC
/* 0C14C4 7F08C994 8E020000 */   lw    $v0, ($s0)
.L7F08C998:
/* 0C14C8 7F08C998 8C6811EC */  lw    $t0, 0x11ec($v1)
.L7F08C99C:
/* 0C14CC 7F08C99C 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C14D0 7F08C9A0 51000051 */  beql  $t0, $zero, .L7F08CAE8
/* 0C14D4 7F08C9A4 8FAB0028 */   lw    $t3, 0x28($sp)
/* 0C14D8 7F08C9A8 0FC26919 */  jal   get_num_players
/* 0C14DC 7F08C9AC 8D300000 */   lw    $s0, ($t1)
/* 0C14E0 7F08C9B0 24010001 */  li    $at, 1
/* 0C14E4 7F08C9B4 5441001E */  bnel  $v0, $at, .L7F08CA30
/* 0C14E8 7F08C9B8 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C14EC 7F08C9BC 8FAA0028 */  lw    $t2, 0x28($sp)
/* 0C14F0 7F08C9C0 3C050010 */  lui   $a1, 0x10
/* 0C14F4 7F08C9C4 0FC1782D */  jal   check_special_attributes
/* 0C14F8 7F08C9C8 8D440000 */   lw    $a0, ($t2)
/* 0C14FC 7F08C9CC 50400018 */  beql  $v0, $zero, .L7F08CA30
/* 0C1500 7F08C9D0 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C1504 7F08C9D4 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C1508 7F08C9D8 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0C150C 7F08C9DC 8D640000 */  lw    $a0, ($t3)
/* 0C1510 7F08C9E0 8D8D0000 */  lw    $t5, ($t4)
/* 0C1514 7F08C9E4 01A4082A */  slt   $at, $t5, $a0
/* 0C1518 7F08C9E8 50200011 */  beql  $at, $zero, .L7F08CA30
/* 0C151C 7F08C9EC 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C1520 7F08C9F0 12400007 */  beqz  $s2, .L7F08CA10
/* 0C1524 7F08C9F4 00000000 */   nop   
/* 0C1528 7F08C9F8 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C152C 7F08C9FC 00000000 */   nop   
/* 0C1530 7F08CA00 5040000B */  beql  $v0, $zero, .L7F08CA30
/* 0C1534 7F08CA04 8FAF0028 */   lw    $t7, 0x28($sp)
/* 0C1538 7F08CA08 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C153C 7F08CA0C 8DC40000 */  lw    $a0, ($t6)
.L7F08CA10:
/* 0C1540 7F08CA10 16240003 */  bne   $s1, $a0, .L7F08CA20
/* 0C1544 7F08CA14 0093082A */   slt   $at, $a0, $s3
/* 0C1548 7F08CA18 50200005 */  beql  $at, $zero, .L7F08CA30
/* 0C154C 7F08CA1C 8FAF0028 */   lw    $t7, 0x28($sp)
.L7F08CA20:
/* 0C1550 7F08CA20 00808825 */  move  $s1, $a0
/* 0C1554 7F08CA24 1000002F */  b     .L7F08CAE4
/* 0C1558 7F08CA28 00809825 */   move  $s3, $a0
/* 0C155C 7F08CA2C 8FAF0028 */  lw    $t7, 0x28($sp)
.L7F08CA30:
/* 0C1560 7F08CA30 24030021 */  li    $v1, 33
/* 0C1564 7F08CA34 8DF80000 */  lw    $t8, ($t7)
/* 0C1568 7F08CA38 16380005 */  bne   $s1, $t8, .L7F08CA50
/* 0C156C 7F08CA3C 00000000 */   nop   
/* 0C1570 7F08CA40 8FB9002C */  lw    $t9, 0x2c($sp)
/* 0C1574 7F08CA44 8F280000 */  lw    $t0, ($t9)
/* 0C1578 7F08CA48 56680027 */  bnel  $s3, $t0, .L7F08CAE8
/* 0C157C 7F08CA4C 8FAB0028 */   lw    $t3, 0x28($sp)
.L7F08CA50:
/* 0C1580 7F08CA50 26090001 */  addiu $t1, $s0, 1
.L7F08CA54:
/* 0C1584 7F08CA54 0123001A */  div   $zero, $t1, $v1
/* 0C1588 7F08CA58 00008010 */  mfhi  $s0
/* 0C158C 7F08CA5C 260A0001 */  addiu $t2, $s0, 1
/* 0C1590 7F08CA60 14600002 */  bnez  $v1, .L7F08CA6C
/* 0C1594 7F08CA64 00000000 */   nop   
/* 0C1598 7F08CA68 0007000D */  break 7
.L7F08CA6C:
/* 0C159C 7F08CA6C 2401FFFF */  li    $at, -1
/* 0C15A0 7F08CA70 14610004 */  bne   $v1, $at, .L7F08CA84
/* 0C15A4 7F08CA74 3C018000 */   lui   $at, 0x8000
/* 0C15A8 7F08CA78 15210002 */  bne   $t1, $at, .L7F08CA84
/* 0C15AC 7F08CA7C 00000000 */   nop   
/* 0C15B0 7F08CA80 0006000D */  break 6
.L7F08CA84:
/* 0C15B4 7F08CA84 1600000C */  bnez  $s0, .L7F08CAB8
/* 0C15B8 7F08CA88 00000000 */   nop   
/* 0C15BC 7F08CA8C 0143001A */  div   $zero, $t2, $v1
/* 0C15C0 7F08CA90 00008010 */  mfhi  $s0
/* 0C15C4 7F08CA94 14600002 */  bnez  $v1, .L7F08CAA0
/* 0C15C8 7F08CA98 00000000 */   nop   
/* 0C15CC 7F08CA9C 0007000D */  break 7
.L7F08CAA0:
/* 0C15D0 7F08CAA0 2401FFFF */  li    $at, -1
/* 0C15D4 7F08CAA4 14610004 */  bne   $v1, $at, .L7F08CAB8
/* 0C15D8 7F08CAA8 3C018000 */   lui   $at, 0x8000
/* 0C15DC 7F08CAAC 15410002 */  bne   $t2, $at, .L7F08CAB8
/* 0C15E0 7F08CAB0 00000000 */   nop   
/* 0C15E4 7F08CAB4 0006000D */  break 6
.L7F08CAB8:
/* 0C15E8 7F08CAB8 52400006 */  beql  $s2, $zero, .L7F08CAD4
/* 0C15EC 7F08CABC 02008825 */   move  $s1, $s0
/* 0C15F0 7F08CAC0 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C15F4 7F08CAC4 02002025 */   move  $a0, $s0
/* 0C15F8 7F08CAC8 10400004 */  beqz  $v0, .L7F08CADC
/* 0C15FC 7F08CACC 24030021 */   li    $v1, 33
/* 0C1600 7F08CAD0 02008825 */  move  $s1, $s0
.L7F08CAD4:
/* 0C1604 7F08CAD4 10000003 */  b     .L7F08CAE4
/* 0C1608 7F08CAD8 00009825 */   move  $s3, $zero
.L7F08CADC:
/* 0C160C 7F08CADC 5611FFDD */  bnel  $s0, $s1, .L7F08CA54
/* 0C1610 7F08CAE0 26090001 */   addiu $t1, $s0, 1
.L7F08CAE4:
/* 0C1614 7F08CAE4 8FAB0028 */  lw    $t3, 0x28($sp)
.L7F08CAE8:
/* 0C1618 7F08CAE8 AD710000 */  sw    $s1, ($t3)
/* 0C161C 7F08CAEC 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0C1620 7F08CAF0 AD930000 */  sw    $s3, ($t4)
/* 0C1624 7F08CAF4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C1628 7F08CAF8 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C162C 7F08CAFC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C1630 7F08CB00 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C1634 7F08CB04 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C1638 7F08CB08 03E00008 */  jr    $ra
/* 0C163C 7F08CB0C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08C86C
/* 0C1CD4 7F08D164 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C1CD8 7F08D168 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C1CDC 7F08D16C 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C1CE0 7F08D170 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C1CE4 7F08D174 AFB30020 */  sw    $s3, 0x20($sp)
/* 0C1CE8 7F08D178 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C1CEC 7F08D17C AFB10018 */  sw    $s1, 0x18($sp)
/* 0C1CF0 7F08D180 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C1CF4 7F08D184 AFA40028 */  sw    $a0, 0x28($sp)
/* 0C1CF8 7F08D188 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0C1CFC 7F08D18C 8C7011E0 */  lw    $s0, 0x11e0($v1)
/* 0C1D00 7F08D190 00C09025 */  move  $s2, $a2
/* 0C1D04 7F08D194 8C910000 */  lw    $s1, ($a0)
/* 0C1D08 7F08D198 1200003D */  beqz  $s0, .Ljp7F08D290
/* 0C1D0C 7F08D19C 8CB30000 */   lw    $s3, ($a1)
/* 0C1D10 7F08D1A0 8E020000 */  lw    $v0, ($s0)
.Ljp7F08D1A4:
/* 0C1D14 7F08D1A4 24010001 */  li    $at, 1
/* 0C1D18 7F08D1A8 54410013 */  bnel  $v0, $at, .Ljp7F08D1F8
/* 0C1D1C 7F08D1AC 24010003 */   li    $at, 3
/* 0C1D20 7F08D1B0 8E040004 */  lw    $a0, 4($s0)
/* 0C1D24 7F08D1B4 28810021 */  slti  $at, $a0, 0x21
/* 0C1D28 7F08D1B8 10200029 */  beqz  $at, .Ljp7F08D260
/* 0C1D2C 7F08D1BC 0224082A */   slt   $at, $s1, $a0
/* 0C1D30 7F08D1C0 10200027 */  beqz  $at, .Ljp7F08D260
/* 0C1D34 7F08D1C4 00000000 */   nop   
/* 0C1D38 7F08D1C8 52400008 */  beql  $s2, $zero, .Ljp7F08D1EC
/* 0C1D3C 7F08D1CC 00808825 */   move  $s1, $a0
/* 0C1D40 7F08D1D0 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C1D44 7F08D1D4 00000000 */   nop   
/* 0C1D48 7F08D1D8 10400021 */  beqz  $v0, .Ljp7F08D260
/* 0C1D4C 7F08D1DC 3C038008 */   lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C1D50 7F08D1E0 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C1D54 7F08D1E4 8E040004 */  lw    $a0, 4($s0)
/* 0C1D58 7F08D1E8 00808825 */  move  $s1, $a0
.Ljp7F08D1EC:
/* 0C1D5C 7F08D1EC 10000028 */  b     .Ljp7F08D290
/* 0C1D60 7F08D1F0 00009825 */   move  $s3, $zero
/* 0C1D64 7F08D1F4 24010003 */  li    $at, 3
.Ljp7F08D1F8:
/* 0C1D68 7F08D1F8 14410019 */  bne   $v0, $at, .Ljp7F08D260
/* 0C1D6C 7F08D1FC 00000000 */   nop   
/* 0C1D70 7F08D200 8E040004 */  lw    $a0, 4($s0)
/* 0C1D74 7F08D204 0224082A */  slt   $at, $s1, $a0
/* 0C1D78 7F08D208 14200007 */  bnez  $at, .Ljp7F08D228
/* 0C1D7C 7F08D20C 00000000 */   nop   
/* 0C1D80 7F08D210 16240013 */  bne   $s1, $a0, .Ljp7F08D260
/* 0C1D84 7F08D214 00000000 */   nop   
/* 0C1D88 7F08D218 8E180008 */  lw    $t8, 8($s0)
/* 0C1D8C 7F08D21C 0278082A */  slt   $at, $s3, $t8
/* 0C1D90 7F08D220 1020000F */  beqz  $at, .Ljp7F08D260
/* 0C1D94 7F08D224 00000000 */   nop   
.Ljp7F08D228:
/* 0C1D98 7F08D228 12400008 */  beqz  $s2, .Ljp7F08D24C
/* 0C1D9C 7F08D22C 00000000 */   nop   
/* 0C1DA0 7F08D230 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C1DA4 7F08D234 00000000 */   nop   
/* 0C1DA8 7F08D238 14400004 */  bnez  $v0, .Ljp7F08D24C
/* 0C1DAC 7F08D23C 00000000 */   nop   
/* 0C1DB0 7F08D240 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C1DB4 7F08D244 8E040008 */   lw    $a0, 8($s0)
/* 0C1DB8 7F08D248 10400005 */  beqz  $v0, .Ljp7F08D260
.Ljp7F08D24C:
/* 0C1DBC 7F08D24C 3C038008 */   lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C1DC0 7F08D250 8E110004 */  lw    $s1, 4($s0)
/* 0C1DC4 7F08D254 8E130008 */  lw    $s3, 8($s0)
/* 0C1DC8 7F08D258 1000000D */  b     .Ljp7F08D290
/* 0C1DCC 7F08D25C 8C63A120 */   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F08D260:
/* 0C1DD0 7F08D260 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C1DD4 7F08D264 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C1DD8 7F08D268 8E10000C */  lw    $s0, 0xc($s0)
/* 0C1DDC 7F08D26C 8C7911E0 */  lw    $t9, 0x11e0($v1)
/* 0C1DE0 7F08D270 16190005 */  bne   $s0, $t9, .Ljp7F08D288
/* 0C1DE4 7F08D274 00000000 */   nop   
/* 0C1DE8 7F08D278 56400006 */  bnezl $s2, .Ljp7F08D294
/* 0C1DEC 7F08D27C 8C6811EC */   lw    $t0, 0x11ec($v1)
/* 0C1DF0 7F08D280 2411FFFF */  li    $s1, -1
/* 0C1DF4 7F08D284 2413FFFF */  li    $s3, -1
.Ljp7F08D288:
/* 0C1DF8 7F08D288 5600FFC6 */  bnezl $s0, .Ljp7F08D1A4
/* 0C1DFC 7F08D28C 8E020000 */   lw    $v0, ($s0)
.Ljp7F08D290:
/* 0C1E00 7F08D290 8C6811EC */  lw    $t0, 0x11ec($v1)
.Ljp7F08D294:
/* 0C1E04 7F08D294 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C1E08 7F08D298 5100005E */  beql  $t0, $zero, .Ljp7F08D414
/* 0C1E0C 7F08D29C 8FAD0028 */   lw    $t5, 0x28($sp)
/* 0C1E10 7F08D2A0 0FC26C01 */  jal   get_num_players
/* 0C1E14 7F08D2A4 8D300000 */   lw    $s0, ($t1)
/* 0C1E18 7F08D2A8 24010001 */  li    $at, 1
/* 0C1E1C 7F08D2AC 14410023 */  bne   $v0, $at, .Ljp7F08D33C
/* 0C1E20 7F08D2B0 8FAA0028 */   lw    $t2, 0x28($sp)
/* 0C1E24 7F08D2B4 8D440000 */  lw    $a0, ($t2)
/* 0C1E28 7F08D2B8 0FC17975 */  jal   check_special_attributes
/* 0C1E2C 7F08D2BC 3C050010 */   lui   $a1, 0x10
/* 0C1E30 7F08D2C0 5040001F */  beql  $v0, $zero, .Ljp7F08D340
/* 0C1E34 7F08D2C4 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C1E38 7F08D2C8 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C1E3C 7F08D2CC 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0C1E40 7F08D2D0 8D640000 */  lw    $a0, ($t3)
/* 0C1E44 7F08D2D4 8D8D0000 */  lw    $t5, ($t4)
/* 0C1E48 7F08D2D8 01A4082A */  slt   $at, $t5, $a0
/* 0C1E4C 7F08D2DC 50200018 */  beql  $at, $zero, .Ljp7F08D340
/* 0C1E50 7F08D2E0 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C1E54 7F08D2E4 12400007 */  beqz  $s2, .Ljp7F08D304
/* 0C1E58 7F08D2E8 00000000 */   nop   
/* 0C1E5C 7F08D2EC 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C1E60 7F08D2F0 00000000 */   nop   
/* 0C1E64 7F08D2F4 50400012 */  beql  $v0, $zero, .Ljp7F08D340
/* 0C1E68 7F08D2F8 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C1E6C 7F08D2FC 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C1E70 7F08D300 8DC40000 */  lw    $a0, ($t6)
.Ljp7F08D304:
/* 0C1E74 7F08D304 16240003 */  bne   $s1, $a0, .Ljp7F08D314
/* 0C1E78 7F08D308 0093082A */   slt   $at, $a0, $s3
/* 0C1E7C 7F08D30C 5020000C */  beql  $at, $zero, .Ljp7F08D340
/* 0C1E80 7F08D310 8FB80028 */   lw    $t8, 0x28($sp)
.Ljp7F08D314:
/* 0C1E84 7F08D314 3C0F8005 */  lui   $t7, %hi(j_text_trigger) # $t7, 0x8005
/* 0C1E88 7F08D318 8DEF8500 */  lw    $t7, %lo(j_text_trigger)($t7)
/* 0C1E8C 7F08D31C 24010002 */  li    $at, 2
/* 0C1E90 7F08D320 51E00004 */  beql  $t7, $zero, .Ljp7F08D334
/* 0C1E94 7F08D324 00808825 */   move  $s1, $a0
/* 0C1E98 7F08D328 50810005 */  beql  $a0, $at, .Ljp7F08D340
/* 0C1E9C 7F08D32C 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C1EA0 7F08D330 00808825 */  move  $s1, $a0
.Ljp7F08D334:
/* 0C1EA4 7F08D334 10000036 */  b     .Ljp7F08D410
/* 0C1EA8 7F08D338 00809825 */   move  $s3, $a0
.Ljp7F08D33C:
/* 0C1EAC 7F08D33C 8FB80028 */  lw    $t8, 0x28($sp)
.Ljp7F08D340:
/* 0C1EB0 7F08D340 24030021 */  li    $v1, 33
/* 0C1EB4 7F08D344 8F190000 */  lw    $t9, ($t8)
/* 0C1EB8 7F08D348 16390005 */  bne   $s1, $t9, .Ljp7F08D360
/* 0C1EBC 7F08D34C 00000000 */   nop   
/* 0C1EC0 7F08D350 8FA8002C */  lw    $t0, 0x2c($sp)
/* 0C1EC4 7F08D354 8D090000 */  lw    $t1, ($t0)
/* 0C1EC8 7F08D358 5669002E */  bnel  $s3, $t1, .Ljp7F08D414
/* 0C1ECC 7F08D35C 8FAD0028 */   lw    $t5, 0x28($sp)
.Ljp7F08D360:
/* 0C1ED0 7F08D360 260A0001 */  addiu $t2, $s0, 1
.Ljp7F08D364:
/* 0C1ED4 7F08D364 0143001A */  div   $zero, $t2, $v1
/* 0C1ED8 7F08D368 00008010 */  mfhi  $s0
/* 0C1EDC 7F08D36C 14600002 */  bnez  $v1, .Ljp7F08D378
/* 0C1EE0 7F08D370 00000000 */   nop   
/* 0C1EE4 7F08D374 0007000D */  break 7
.Ljp7F08D378:
/* 0C1EE8 7F08D378 2401FFFF */  li    $at, -1
/* 0C1EEC 7F08D37C 14610004 */  bne   $v1, $at, .Ljp7F08D390
/* 0C1EF0 7F08D380 3C018000 */   lui   $at, 0x8000
/* 0C1EF4 7F08D384 15410002 */  bne   $t2, $at, .Ljp7F08D390
/* 0C1EF8 7F08D388 00000000 */   nop   
/* 0C1EFC 7F08D38C 0006000D */  break 6
.Ljp7F08D390:
/* 0C1F00 7F08D390 1600000D */  bnez  $s0, .Ljp7F08D3C8
/* 0C1F04 7F08D394 00000000 */   nop   
/* 0C1F08 7F08D398 260B0001 */  addiu $t3, $s0, 1
/* 0C1F0C 7F08D39C 0163001A */  div   $zero, $t3, $v1
/* 0C1F10 7F08D3A0 00008010 */  mfhi  $s0
/* 0C1F14 7F08D3A4 14600002 */  bnez  $v1, .Ljp7F08D3B0
/* 0C1F18 7F08D3A8 00000000 */   nop   
/* 0C1F1C 7F08D3AC 0007000D */  break 7
.Ljp7F08D3B0:
/* 0C1F20 7F08D3B0 2401FFFF */  li    $at, -1
/* 0C1F24 7F08D3B4 14610004 */  bne   $v1, $at, .Ljp7F08D3C8
/* 0C1F28 7F08D3B8 3C018000 */   lui   $at, 0x8000
/* 0C1F2C 7F08D3BC 15610002 */  bne   $t3, $at, .Ljp7F08D3C8
/* 0C1F30 7F08D3C0 00000000 */   nop   
/* 0C1F34 7F08D3C4 0006000D */  break 6
.Ljp7F08D3C8:
/* 0C1F38 7F08D3C8 12400005 */  beqz  $s2, .Ljp7F08D3E0
/* 0C1F3C 7F08D3CC 00000000 */   nop   
/* 0C1F40 7F08D3D0 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C1F44 7F08D3D4 02002025 */   move  $a0, $s0
/* 0C1F48 7F08D3D8 1040000B */  beqz  $v0, .Ljp7F08D408
/* 0C1F4C 7F08D3DC 24030021 */   li    $v1, 33
.Ljp7F08D3E0:
/* 0C1F50 7F08D3E0 3C0C8005 */  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
/* 0C1F54 7F08D3E4 8D8C8500 */  lw    $t4, %lo(j_text_trigger)($t4)
/* 0C1F58 7F08D3E8 24010002 */  li    $at, 2
/* 0C1F5C 7F08D3EC 51800004 */  beql  $t4, $zero, .Ljp7F08D400
/* 0C1F60 7F08D3F0 02008825 */   move  $s1, $s0
/* 0C1F64 7F08D3F4 12010004 */  beq   $s0, $at, .Ljp7F08D408
/* 0C1F68 7F08D3F8 00000000 */   nop   
/* 0C1F6C 7F08D3FC 02008825 */  move  $s1, $s0
.Ljp7F08D400:
/* 0C1F70 7F08D400 10000003 */  b     .Ljp7F08D410
/* 0C1F74 7F08D404 00009825 */   move  $s3, $zero
.Ljp7F08D408:
/* 0C1F78 7F08D408 5611FFD6 */  bnel  $s0, $s1, .Ljp7F08D364
/* 0C1F7C 7F08D40C 260A0001 */   addiu $t2, $s0, 1
.Ljp7F08D410:
/* 0C1F80 7F08D410 8FAD0028 */  lw    $t5, 0x28($sp)
.Ljp7F08D414:
/* 0C1F84 7F08D414 ADB10000 */  sw    $s1, ($t5)
/* 0C1F88 7F08D418 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0C1F8C 7F08D41C ADD30000 */  sw    $s3, ($t6)
/* 0C1F90 7F08D420 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C1F94 7F08D424 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C1F98 7F08D428 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C1F9C 7F08D42C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C1FA0 7F08D430 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C1FA4 7F08D434 03E00008 */  jr    $ra
/* 0C1FA8 7F08D438 27BD0028 */   addiu $sp, $sp, 0x28 
)
#endif

#endif




#ifdef NONMATCHING
void sub_GAME_7F08CB10(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08CB10
/* 0C1640 7F08CB10 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C1644 7F08CB14 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C1648 7F08CB18 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C164C 7F08CB1C AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C1650 7F08CB20 AFB30020 */  sw    $s3, 0x20($sp)
/* 0C1654 7F08CB24 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C1658 7F08CB28 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C165C 7F08CB2C AFB00014 */  sw    $s0, 0x14($sp)
/* 0C1660 7F08CB30 AFA40028 */  sw    $a0, 0x28($sp)
/* 0C1664 7F08CB34 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0C1668 7F08CB38 8C6211E0 */  lw    $v0, 0x11e0($v1)
/* 0C166C 7F08CB3C 00C09025 */  move  $s2, $a2
/* 0C1670 7F08CB40 8C910000 */  lw    $s1, ($a0)
/* 0C1674 7F08CB44 00807025 */  move  $t6, $a0
/* 0C1678 7F08CB48 8CB30000 */  lw    $s3, ($a1)
/* 0C167C 7F08CB4C 10400042 */  beqz  $v0, .L7F08CC58
/* 0C1680 7F08CB50 00A07825 */   move  $t7, $a1
/* 0C1684 7F08CB54 8C500010 */  lw    $s0, 0x10($v0)
.L7F08CB58:
/* 0C1688 7F08CB58 8E020000 */  lw    $v0, ($s0)
/* 0C168C 7F08CB5C 24010001 */  li    $at, 1
/* 0C1690 7F08CB60 54410018 */  bnel  $v0, $at, .L7F08CBC4
/* 0C1694 7F08CB64 24010003 */   li    $at, 3
/* 0C1698 7F08CB68 8E040004 */  lw    $a0, 4($s0)
/* 0C169C 7F08CB6C 28810021 */  slti  $at, $a0, 0x21
/* 0C16A0 7F08CB70 1020002E */  beqz  $at, .L7F08CC2C
/* 0C16A4 7F08CB74 00000000 */   nop   
/* 0C16A8 7F08CB78 0091082A */  slt   $at, $a0, $s1
/* 0C16AC 7F08CB7C 14200005 */  bnez  $at, .L7F08CB94
/* 0C16B0 7F08CB80 00000000 */   nop   
/* 0C16B4 7F08CB84 16240029 */  bne   $s1, $a0, .L7F08CC2C
/* 0C16B8 7F08CB88 00000000 */   nop   
/* 0C16BC 7F08CB8C 1A600027 */  blez  $s3, .L7F08CC2C
/* 0C16C0 7F08CB90 00000000 */   nop   
.L7F08CB94:
/* 0C16C4 7F08CB94 52400008 */  beql  $s2, $zero, .L7F08CBB8
/* 0C16C8 7F08CB98 00808825 */   move  $s1, $a0
/* 0C16CC 7F08CB9C 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C16D0 7F08CBA0 00000000 */   nop   
/* 0C16D4 7F08CBA4 10400021 */  beqz  $v0, .L7F08CC2C
/* 0C16D8 7F08CBA8 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C16DC 7F08CBAC 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C16E0 7F08CBB0 8E040004 */  lw    $a0, 4($s0)
/* 0C16E4 7F08CBB4 00808825 */  move  $s1, $a0
.L7F08CBB8:
/* 0C16E8 7F08CBB8 10000027 */  b     .L7F08CC58
/* 0C16EC 7F08CBBC 00009825 */   move  $s3, $zero
/* 0C16F0 7F08CBC0 24010003 */  li    $at, 3
.L7F08CBC4:
/* 0C16F4 7F08CBC4 14410019 */  bne   $v0, $at, .L7F08CC2C
/* 0C16F8 7F08CBC8 00000000 */   nop   
/* 0C16FC 7F08CBCC 8E040004 */  lw    $a0, 4($s0)
/* 0C1700 7F08CBD0 0091082A */  slt   $at, $a0, $s1
/* 0C1704 7F08CBD4 14200007 */  bnez  $at, .L7F08CBF4
/* 0C1708 7F08CBD8 00000000 */   nop   
/* 0C170C 7F08CBDC 16240013 */  bne   $s1, $a0, .L7F08CC2C
/* 0C1710 7F08CBE0 00000000 */   nop   
/* 0C1714 7F08CBE4 8E180008 */  lw    $t8, 8($s0)
/* 0C1718 7F08CBE8 0313082A */  slt   $at, $t8, $s3
/* 0C171C 7F08CBEC 1020000F */  beqz  $at, .L7F08CC2C
/* 0C1720 7F08CBF0 00000000 */   nop   
.L7F08CBF4:
/* 0C1724 7F08CBF4 12400008 */  beqz  $s2, .L7F08CC18
/* 0C1728 7F08CBF8 00000000 */   nop   
/* 0C172C 7F08CBFC 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C1730 7F08CC00 00000000 */   nop   
/* 0C1734 7F08CC04 14400004 */  bnez  $v0, .L7F08CC18
/* 0C1738 7F08CC08 00000000 */   nop   
/* 0C173C 7F08CC0C 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C1740 7F08CC10 8E040008 */   lw    $a0, 8($s0)
/* 0C1744 7F08CC14 10400005 */  beqz  $v0, .L7F08CC2C
.L7F08CC18:
/* 0C1748 7F08CC18 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C174C 7F08CC1C 8E110004 */  lw    $s1, 4($s0)
/* 0C1750 7F08CC20 8E130008 */  lw    $s3, 8($s0)
/* 0C1754 7F08CC24 1000000C */  b     .L7F08CC58
/* 0C1758 7F08CC28 8C63A0B0 */   lw    $v1, %lo(pPlayer)($v1)
.L7F08CC2C:
/* 0C175C 7F08CC2C 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C1760 7F08CC30 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C1764 7F08CC34 8C7911E0 */  lw    $t9, 0x11e0($v1)
/* 0C1768 7F08CC38 16190005 */  bne   $s0, $t9, .L7F08CC50
/* 0C176C 7F08CC3C 00000000 */   nop   
/* 0C1770 7F08CC40 56400006 */  bnezl $s2, .L7F08CC5C
/* 0C1774 7F08CC44 8C6811EC */   lw    $t0, 0x11ec($v1)
/* 0C1778 7F08CC48 241103E8 */  li    $s1, 1000
/* 0C177C 7F08CC4C 241303E8 */  li    $s3, 1000
.L7F08CC50:
/* 0C1780 7F08CC50 1000FFC1 */  b     .L7F08CB58
/* 0C1784 7F08CC54 8E100010 */   lw    $s0, 0x10($s0)
.L7F08CC58:
/* 0C1788 7F08CC58 8C6811EC */  lw    $t0, 0x11ec($v1)
.L7F08CC5C:
/* 0C178C 7F08CC5C 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0C1790 7F08CC60 51000079 */  beql  $t0, $zero, .L7F08CE48
/* 0C1794 7F08CC64 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1798 7F08CC68 8D4B0000 */  lw    $t3, ($t2)
/* 0C179C 7F08CC6C 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C17A0 7F08CC70 24030021 */  li    $v1, 33
/* 0C17A4 7F08CC74 1560001B */  bnez  $t3, .L7F08CCE4
/* 0C17A8 7F08CC78 8D300000 */   lw    $s0, ($t1)
/* 0C17AC 7F08CC7C 260C0020 */  addiu $t4, $s0, 0x20
/* 0C17B0 7F08CC80 0183001A */  div   $zero, $t4, $v1
/* 0C17B4 7F08CC84 00008010 */  mfhi  $s0
/* 0C17B8 7F08CC88 260D0020 */  addiu $t5, $s0, 0x20
/* 0C17BC 7F08CC8C 14600002 */  bnez  $v1, .L7F08CC98
/* 0C17C0 7F08CC90 00000000 */   nop   
/* 0C17C4 7F08CC94 0007000D */  break 7
.L7F08CC98:
/* 0C17C8 7F08CC98 2401FFFF */  li    $at, -1
/* 0C17CC 7F08CC9C 14610004 */  bne   $v1, $at, .L7F08CCB0
/* 0C17D0 7F08CCA0 3C018000 */   lui   $at, 0x8000
/* 0C17D4 7F08CCA4 15810002 */  bne   $t4, $at, .L7F08CCB0
/* 0C17D8 7F08CCA8 00000000 */   nop   
/* 0C17DC 7F08CCAC 0006000D */  break 6
.L7F08CCB0:
/* 0C17E0 7F08CCB0 1600000C */  bnez  $s0, .L7F08CCE4
/* 0C17E4 7F08CCB4 00000000 */   nop   
/* 0C17E8 7F08CCB8 01A3001A */  div   $zero, $t5, $v1
/* 0C17EC 7F08CCBC 00008010 */  mfhi  $s0
/* 0C17F0 7F08CCC0 14600002 */  bnez  $v1, .L7F08CCCC
/* 0C17F4 7F08CCC4 00000000 */   nop   
/* 0C17F8 7F08CCC8 0007000D */  break 7
.L7F08CCCC:
/* 0C17FC 7F08CCCC 2401FFFF */  li    $at, -1
/* 0C1800 7F08CCD0 14610004 */  bne   $v1, $at, .L7F08CCE4
/* 0C1804 7F08CCD4 3C018000 */   lui   $at, 0x8000
/* 0C1808 7F08CCD8 15A10002 */  bne   $t5, $at, .L7F08CCE4
/* 0C180C 7F08CCDC 00000000 */   nop   
/* 0C1810 7F08CCE0 0006000D */  break 6
.L7F08CCE4:
/* 0C1814 7F08CCE4 1611001E */  bne   $s0, $s1, .L7F08CD60
/* 0C1818 7F08CCE8 00000000 */   nop   
/* 0C181C 7F08CCEC 0FC26919 */  jal   get_num_players
/* 0C1820 7F08CCF0 00000000 */   nop   
/* 0C1824 7F08CCF4 24010001 */  li    $at, 1
/* 0C1828 7F08CCF8 14410052 */  bne   $v0, $at, .L7F08CE44
/* 0C182C 7F08CCFC 02002025 */   move  $a0, $s0
/* 0C1830 7F08CD00 0FC1782D */  jal   check_special_attributes
/* 0C1834 7F08CD04 3C050010 */   lui   $a1, 0x10
/* 0C1838 7F08CD08 5040004F */  beql  $v0, $zero, .L7F08CE48
/* 0C183C 7F08CD0C 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1840 7F08CD10 52400006 */  beql  $s2, $zero, .L7F08CD2C
/* 0C1844 7F08CD14 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1848 7F08CD18 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C184C 7F08CD1C 02002025 */   move  $a0, $s0
/* 0C1850 7F08CD20 50400049 */  beql  $v0, $zero, .L7F08CE48
/* 0C1854 7F08CD24 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1858 7F08CD28 8FAE0028 */  lw    $t6, 0x28($sp)
.L7F08CD2C:
/* 0C185C 7F08CD2C 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0C1860 7F08CD30 8DCF0000 */  lw    $t7, ($t6)
/* 0C1864 7F08CD34 560F0005 */  bnel  $s0, $t7, .L7F08CD4C
/* 0C1868 7F08CD38 0270082A */   slt   $at, $s3, $s0
/* 0C186C 7F08CD3C 8F190000 */  lw    $t9, ($t8)
/* 0C1870 7F08CD40 0219082A */  slt   $at, $s0, $t9
/* 0C1874 7F08CD44 1020003F */  beqz  $at, .L7F08CE44
/* 0C1878 7F08CD48 0270082A */   slt   $at, $s3, $s0
.L7F08CD4C:
/* 0C187C 7F08CD4C 5020003E */  beql  $at, $zero, .L7F08CE48
/* 0C1880 7F08CD50 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C1884 7F08CD54 02008825 */  move  $s1, $s0
/* 0C1888 7F08CD58 1000003A */  b     .L7F08CE44
/* 0C188C 7F08CD5C 02009825 */   move  $s3, $s0
.L7F08CD60:
/* 0C1890 7F08CD60 12400005 */  beqz  $s2, .L7F08CD78
/* 0C1894 7F08CD64 00000000 */   nop   
/* 0C1898 7F08CD68 0FC17817 */  jal   check_if_have_ammo_for_item
/* 0C189C 7F08CD6C 02002025 */   move  $a0, $s0
/* 0C18A0 7F08CD70 10400018 */  beqz  $v0, .L7F08CDD4
/* 0C18A4 7F08CD74 24030021 */   li    $v1, 33
.L7F08CD78:
/* 0C18A8 7F08CD78 0FC26919 */  jal   get_num_players
/* 0C18AC 7F08CD7C 00000000 */   nop   
/* 0C18B0 7F08CD80 24010001 */  li    $at, 1
/* 0C18B4 7F08CD84 14410010 */  bne   $v0, $at, .L7F08CDC8
/* 0C18B8 7F08CD88 02002025 */   move  $a0, $s0
/* 0C18BC 7F08CD8C 0FC1782D */  jal   check_special_attributes
/* 0C18C0 7F08CD90 3C050010 */   lui   $a1, 0x10
/* 0C18C4 7F08CD94 1040000C */  beqz  $v0, .L7F08CDC8
/* 0C18C8 7F08CD98 8FA80028 */   lw    $t0, 0x28($sp)
/* 0C18CC 7F08CD9C 8D090000 */  lw    $t1, ($t0)
/* 0C18D0 7F08CDA0 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0C18D4 7F08CDA4 02008825 */  move  $s1, $s0
/* 0C18D8 7F08CDA8 16090005 */  bne   $s0, $t1, .L7F08CDC0
/* 0C18DC 7F08CDAC 00000000 */   nop   
/* 0C18E0 7F08CDB0 8D4B0000 */  lw    $t3, ($t2)
/* 0C18E4 7F08CDB4 020B082A */  slt   $at, $s0, $t3
/* 0C18E8 7F08CDB8 50200004 */  beql  $at, $zero, .L7F08CDCC
/* 0C18EC 7F08CDBC 02008825 */   move  $s1, $s0
.L7F08CDC0:
/* 0C18F0 7F08CDC0 10000020 */  b     .L7F08CE44
/* 0C18F4 7F08CDC4 02009825 */   move  $s3, $s0
.L7F08CDC8:
/* 0C18F8 7F08CDC8 02008825 */  move  $s1, $s0
.L7F08CDCC:
/* 0C18FC 7F08CDCC 1000001D */  b     .L7F08CE44
/* 0C1900 7F08CDD0 00009825 */   move  $s3, $zero
.L7F08CDD4:
/* 0C1904 7F08CDD4 260C0020 */  addiu $t4, $s0, 0x20
/* 0C1908 7F08CDD8 0183001A */  div   $zero, $t4, $v1
/* 0C190C 7F08CDDC 00008010 */  mfhi  $s0
/* 0C1910 7F08CDE0 14600002 */  bnez  $v1, .L7F08CDEC
/* 0C1914 7F08CDE4 00000000 */   nop   
/* 0C1918 7F08CDE8 0007000D */  break 7
.L7F08CDEC:
/* 0C191C 7F08CDEC 2401FFFF */  li    $at, -1
/* 0C1920 7F08CDF0 14610004 */  bne   $v1, $at, .L7F08CE04
/* 0C1924 7F08CDF4 3C018000 */   lui   $at, 0x8000
/* 0C1928 7F08CDF8 15810002 */  bne   $t4, $at, .L7F08CE04
/* 0C192C 7F08CDFC 00000000 */   nop   
/* 0C1930 7F08CE00 0006000D */  break 6
.L7F08CE04:
/* 0C1934 7F08CE04 1600FFB7 */  bnez  $s0, .L7F08CCE4
/* 0C1938 7F08CE08 00000000 */   nop   
/* 0C193C 7F08CE0C 260D0020 */  addiu $t5, $s0, 0x20
/* 0C1940 7F08CE10 01A3001A */  div   $zero, $t5, $v1
/* 0C1944 7F08CE14 00008010 */  mfhi  $s0
/* 0C1948 7F08CE18 14600002 */  bnez  $v1, .L7F08CE24
/* 0C194C 7F08CE1C 00000000 */   nop   
/* 0C1950 7F08CE20 0007000D */  break 7
.L7F08CE24:
/* 0C1954 7F08CE24 2401FFFF */  li    $at, -1
/* 0C1958 7F08CE28 14610004 */  bne   $v1, $at, .L7F08CE3C
/* 0C195C 7F08CE2C 3C018000 */   lui   $at, 0x8000
/* 0C1960 7F08CE30 15A10002 */  bne   $t5, $at, .L7F08CE3C
/* 0C1964 7F08CE34 00000000 */   nop   
/* 0C1968 7F08CE38 0006000D */  break 6
.L7F08CE3C:
/* 0C196C 7F08CE3C 1000FFA9 */  b     .L7F08CCE4
/* 0C1970 7F08CE40 00000000 */   nop   
.L7F08CE44:
/* 0C1974 7F08CE44 8FAE0028 */  lw    $t6, 0x28($sp)
.L7F08CE48:
/* 0C1978 7F08CE48 ADD10000 */  sw    $s1, ($t6)
/* 0C197C 7F08CE4C 8FAF002C */  lw    $t7, 0x2c($sp)
/* 0C1980 7F08CE50 ADF30000 */  sw    $s3, ($t7)
/* 0C1984 7F08CE54 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C1988 7F08CE58 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C198C 7F08CE5C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C1990 7F08CE60 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C1994 7F08CE64 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C1998 7F08CE68 03E00008 */  jr    $ra
/* 0C199C 7F08CE6C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08CB10
/* 0C1FAC 7F08D43C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C1FB0 7F08D440 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C1FB4 7F08D444 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C1FB8 7F08D448 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C1FBC 7F08D44C AFB30020 */  sw    $s3, 0x20($sp)
/* 0C1FC0 7F08D450 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C1FC4 7F08D454 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C1FC8 7F08D458 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C1FCC 7F08D45C AFA40028 */  sw    $a0, 0x28($sp)
/* 0C1FD0 7F08D460 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0C1FD4 7F08D464 8C6211E0 */  lw    $v0, 0x11e0($v1)
/* 0C1FD8 7F08D468 00C09025 */  move  $s2, $a2
/* 0C1FDC 7F08D46C 8C910000 */  lw    $s1, ($a0)
/* 0C1FE0 7F08D470 00807025 */  move  $t6, $a0
/* 0C1FE4 7F08D474 8CB30000 */  lw    $s3, ($a1)
/* 0C1FE8 7F08D478 10400042 */  beqz  $v0, .Ljp7F08D584
/* 0C1FEC 7F08D47C 00A07825 */   move  $t7, $a1
/* 0C1FF0 7F08D480 8C500010 */  lw    $s0, 0x10($v0)
.Ljp7F08D484:
/* 0C1FF4 7F08D484 8E020000 */  lw    $v0, ($s0)
/* 0C1FF8 7F08D488 24010001 */  li    $at, 1
/* 0C1FFC 7F08D48C 54410018 */  bnel  $v0, $at, .Ljp7F08D4F0
/* 0C2000 7F08D490 24010003 */   li    $at, 3
/* 0C2004 7F08D494 8E040004 */  lw    $a0, 4($s0)
/* 0C2008 7F08D498 28810021 */  slti  $at, $a0, 0x21
/* 0C200C 7F08D49C 1020002E */  beqz  $at, .Ljp7F08D558
/* 0C2010 7F08D4A0 00000000 */   nop   
/* 0C2014 7F08D4A4 0091082A */  slt   $at, $a0, $s1
/* 0C2018 7F08D4A8 14200005 */  bnez  $at, .Ljp7F08D4C0
/* 0C201C 7F08D4AC 00000000 */   nop   
/* 0C2020 7F08D4B0 16240029 */  bne   $s1, $a0, .Ljp7F08D558
/* 0C2024 7F08D4B4 00000000 */   nop   
/* 0C2028 7F08D4B8 1A600027 */  blez  $s3, .Ljp7F08D558
/* 0C202C 7F08D4BC 00000000 */   nop   
.Ljp7F08D4C0:
/* 0C2030 7F08D4C0 52400008 */  beql  $s2, $zero, .Ljp7F08D4E4
/* 0C2034 7F08D4C4 00808825 */   move  $s1, $a0
/* 0C2038 7F08D4C8 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C203C 7F08D4CC 00000000 */   nop   
/* 0C2040 7F08D4D0 10400021 */  beqz  $v0, .Ljp7F08D558
/* 0C2044 7F08D4D4 3C038008 */   lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C2048 7F08D4D8 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C204C 7F08D4DC 8E040004 */  lw    $a0, 4($s0)
/* 0C2050 7F08D4E0 00808825 */  move  $s1, $a0
.Ljp7F08D4E4:
/* 0C2054 7F08D4E4 10000027 */  b     .Ljp7F08D584
/* 0C2058 7F08D4E8 00009825 */   move  $s3, $zero
/* 0C205C 7F08D4EC 24010003 */  li    $at, 3
.Ljp7F08D4F0:
/* 0C2060 7F08D4F0 14410019 */  bne   $v0, $at, .Ljp7F08D558
/* 0C2064 7F08D4F4 00000000 */   nop   
/* 0C2068 7F08D4F8 8E040004 */  lw    $a0, 4($s0)
/* 0C206C 7F08D4FC 0091082A */  slt   $at, $a0, $s1
/* 0C2070 7F08D500 14200007 */  bnez  $at, .Ljp7F08D520
/* 0C2074 7F08D504 00000000 */   nop   
/* 0C2078 7F08D508 16240013 */  bne   $s1, $a0, .Ljp7F08D558
/* 0C207C 7F08D50C 00000000 */   nop   
/* 0C2080 7F08D510 8E180008 */  lw    $t8, 8($s0)
/* 0C2084 7F08D514 0313082A */  slt   $at, $t8, $s3
/* 0C2088 7F08D518 1020000F */  beqz  $at, .Ljp7F08D558
/* 0C208C 7F08D51C 00000000 */   nop   
.Ljp7F08D520:
/* 0C2090 7F08D520 12400008 */  beqz  $s2, .Ljp7F08D544
/* 0C2094 7F08D524 00000000 */   nop   
/* 0C2098 7F08D528 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C209C 7F08D52C 00000000 */   nop   
/* 0C20A0 7F08D530 14400004 */  bnez  $v0, .Ljp7F08D544
/* 0C20A4 7F08D534 00000000 */   nop   
/* 0C20A8 7F08D538 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C20AC 7F08D53C 8E040008 */   lw    $a0, 8($s0)
/* 0C20B0 7F08D540 10400005 */  beqz  $v0, .Ljp7F08D558
.Ljp7F08D544:
/* 0C20B4 7F08D544 3C038008 */   lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C20B8 7F08D548 8E110004 */  lw    $s1, 4($s0)
/* 0C20BC 7F08D54C 8E130008 */  lw    $s3, 8($s0)
/* 0C20C0 7F08D550 1000000C */  b     .Ljp7F08D584
/* 0C20C4 7F08D554 8C63A120 */   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F08D558:
/* 0C20C8 7F08D558 3C038008 */  lui   $v1, %hi(pPlayer) # $v1, 0x8008
/* 0C20CC 7F08D55C 8C63A120 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C20D0 7F08D560 8C7911E0 */  lw    $t9, 0x11e0($v1)
/* 0C20D4 7F08D564 16190005 */  bne   $s0, $t9, .Ljp7F08D57C
/* 0C20D8 7F08D568 00000000 */   nop   
/* 0C20DC 7F08D56C 56400006 */  bnezl $s2, .Ljp7F08D588
/* 0C20E0 7F08D570 8C6811EC */   lw    $t0, 0x11ec($v1)
/* 0C20E4 7F08D574 241103E8 */  li    $s1, 1000
/* 0C20E8 7F08D578 241303E8 */  li    $s3, 1000
.Ljp7F08D57C:
/* 0C20EC 7F08D57C 1000FFC1 */  b     .Ljp7F08D484
/* 0C20F0 7F08D580 8E100010 */   lw    $s0, 0x10($s0)
.Ljp7F08D584:
/* 0C20F4 7F08D584 8C6811EC */  lw    $t0, 0x11ec($v1)
.Ljp7F08D588:
/* 0C20F8 7F08D588 8FAA002C */  lw    $t2, 0x2c($sp)
/* 0C20FC 7F08D58C 51000087 */  beql  $t0, $zero, .Ljp7F08D7AC
/* 0C2100 7F08D590 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C2104 7F08D594 8D4B0000 */  lw    $t3, ($t2)
/* 0C2108 7F08D598 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C210C 7F08D59C 24030021 */  li    $v1, 33
/* 0C2110 7F08D5A0 1560001B */  bnez  $t3, .Ljp7F08D610
/* 0C2114 7F08D5A4 8D300000 */   lw    $s0, ($t1)
/* 0C2118 7F08D5A8 260C0020 */  addiu $t4, $s0, 0x20
/* 0C211C 7F08D5AC 0183001A */  div   $zero, $t4, $v1
/* 0C2120 7F08D5B0 00008010 */  mfhi  $s0
/* 0C2124 7F08D5B4 14600002 */  bnez  $v1, .Ljp7F08D5C0
/* 0C2128 7F08D5B8 00000000 */   nop   
/* 0C212C 7F08D5BC 0007000D */  break 7
.Ljp7F08D5C0:
/* 0C2130 7F08D5C0 2401FFFF */  li    $at, -1
/* 0C2134 7F08D5C4 14610004 */  bne   $v1, $at, .Ljp7F08D5D8
/* 0C2138 7F08D5C8 3C018000 */   lui   $at, 0x8000
/* 0C213C 7F08D5CC 15810002 */  bne   $t4, $at, .Ljp7F08D5D8
/* 0C2140 7F08D5D0 00000000 */   nop   
/* 0C2144 7F08D5D4 0006000D */  break 6
.Ljp7F08D5D8:
/* 0C2148 7F08D5D8 5600000E */  bnezl $s0, .Ljp7F08D614
/* 0C214C 7F08D5DC 24030021 */   li    $v1, 33
/* 0C2150 7F08D5E0 260D0020 */  addiu $t5, $s0, 0x20
/* 0C2154 7F08D5E4 01A3001A */  div   $zero, $t5, $v1
/* 0C2158 7F08D5E8 00008010 */  mfhi  $s0
/* 0C215C 7F08D5EC 14600002 */  bnez  $v1, .Ljp7F08D5F8
/* 0C2160 7F08D5F0 00000000 */   nop   
/* 0C2164 7F08D5F4 0007000D */  break 7
.Ljp7F08D5F8:
/* 0C2168 7F08D5F8 2401FFFF */  li    $at, -1
/* 0C216C 7F08D5FC 14610004 */  bne   $v1, $at, .Ljp7F08D610
/* 0C2170 7F08D600 3C018000 */   lui   $at, 0x8000
/* 0C2174 7F08D604 15A10002 */  bne   $t5, $at, .Ljp7F08D610
/* 0C2178 7F08D608 00000000 */   nop   
/* 0C217C 7F08D60C 0006000D */  break 6
.Ljp7F08D610:
/* 0C2180 7F08D610 24030021 */  li    $v1, 33
.Ljp7F08D614:
/* 0C2184 7F08D614 16110024 */  bne   $s0, $s1, .Ljp7F08D6A8
/* 0C2188 7F08D618 00000000 */   nop   
/* 0C218C 7F08D61C 0FC26C01 */  jal   get_num_players
/* 0C2190 7F08D620 00000000 */   nop   
/* 0C2194 7F08D624 24010001 */  li    $at, 1
/* 0C2198 7F08D628 1441005F */  bne   $v0, $at, .Ljp7F08D7A8
/* 0C219C 7F08D62C 02002025 */   move  $a0, $s0
/* 0C21A0 7F08D630 0FC17975 */  jal   check_special_attributes
/* 0C21A4 7F08D634 3C050010 */   lui   $a1, 0x10
/* 0C21A8 7F08D638 5040005C */  beql  $v0, $zero, .Ljp7F08D7AC
/* 0C21AC 7F08D63C 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C21B0 7F08D640 52400006 */  beql  $s2, $zero, .Ljp7F08D65C
/* 0C21B4 7F08D644 8FAE0028 */   lw    $t6, 0x28($sp)
/* 0C21B8 7F08D648 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C21BC 7F08D64C 02002025 */   move  $a0, $s0
/* 0C21C0 7F08D650 50400056 */  beql  $v0, $zero, .Ljp7F08D7AC
/* 0C21C4 7F08D654 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C21C8 7F08D658 8FAE0028 */  lw    $t6, 0x28($sp)
.Ljp7F08D65C:
/* 0C21CC 7F08D65C 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0C21D0 7F08D660 8DCF0000 */  lw    $t7, ($t6)
/* 0C21D4 7F08D664 560F0005 */  bnel  $s0, $t7, .Ljp7F08D67C
/* 0C21D8 7F08D668 0270082A */   slt   $at, $s3, $s0
/* 0C21DC 7F08D66C 8F190000 */  lw    $t9, ($t8)
/* 0C21E0 7F08D670 0219082A */  slt   $at, $s0, $t9
/* 0C21E4 7F08D674 1020004C */  beqz  $at, .Ljp7F08D7A8
/* 0C21E8 7F08D678 0270082A */   slt   $at, $s3, $s0
.Ljp7F08D67C:
/* 0C21EC 7F08D67C 1020004A */  beqz  $at, .Ljp7F08D7A8
/* 0C21F0 7F08D680 3C088005 */   lui   $t0, %hi(j_text_trigger) # $t0, 0x8005
/* 0C21F4 7F08D684 8D088500 */  lw    $t0, %lo(j_text_trigger)($t0)
/* 0C21F8 7F08D688 24010002 */  li    $at, 2
/* 0C21FC 7F08D68C 51000004 */  beql  $t0, $zero, .Ljp7F08D6A0
/* 0C2200 7F08D690 02008825 */   move  $s1, $s0
/* 0C2204 7F08D694 52010045 */  beql  $s0, $at, .Ljp7F08D7AC
/* 0C2208 7F08D698 8FB80028 */   lw    $t8, 0x28($sp)
/* 0C220C 7F08D69C 02008825 */  move  $s1, $s0
.Ljp7F08D6A0:
/* 0C2210 7F08D6A0 10000041 */  b     .Ljp7F08D7A8
/* 0C2214 7F08D6A4 02009825 */   move  $s3, $s0
.Ljp7F08D6A8:
/* 0C2218 7F08D6A8 12400005 */  beqz  $s2, .Ljp7F08D6C0
/* 0C221C 7F08D6AC 00000000 */   nop   
/* 0C2220 7F08D6B0 0FC1795F */  jal   check_if_have_ammo_for_item
/* 0C2224 7F08D6B4 02002025 */   move  $a0, $s0
/* 0C2228 7F08D6B8 1040001F */  beqz  $v0, .Ljp7F08D738
/* 0C222C 7F08D6BC 24030021 */   li    $v1, 33
.Ljp7F08D6C0:
/* 0C2230 7F08D6C0 3C098005 */  lui   $t1, %hi(j_text_trigger) # $t1, 0x8005
/* 0C2234 7F08D6C4 8D298500 */  lw    $t1, %lo(j_text_trigger)($t1)
/* 0C2238 7F08D6C8 24010002 */  li    $at, 2
/* 0C223C 7F08D6CC 11200003 */  beqz  $t1, .Ljp7F08D6DC
/* 0C2240 7F08D6D0 00000000 */   nop   
/* 0C2244 7F08D6D4 52010019 */  beql  $s0, $at, .Ljp7F08D73C
/* 0C2248 7F08D6D8 260E0020 */   addiu $t6, $s0, 0x20
.Ljp7F08D6DC:
/* 0C224C 7F08D6DC 0FC26C01 */  jal   get_num_players
/* 0C2250 7F08D6E0 00000000 */   nop   
/* 0C2254 7F08D6E4 24010001 */  li    $at, 1
/* 0C2258 7F08D6E8 14410010 */  bne   $v0, $at, .Ljp7F08D72C
/* 0C225C 7F08D6EC 02002025 */   move  $a0, $s0
/* 0C2260 7F08D6F0 0FC17975 */  jal   check_special_attributes
/* 0C2264 7F08D6F4 3C050010 */   lui   $a1, 0x10
/* 0C2268 7F08D6F8 1040000C */  beqz  $v0, .Ljp7F08D72C
/* 0C226C 7F08D6FC 8FAA0028 */   lw    $t2, 0x28($sp)
/* 0C2270 7F08D700 8D4B0000 */  lw    $t3, ($t2)
/* 0C2274 7F08D704 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0C2278 7F08D708 02008825 */  move  $s1, $s0
/* 0C227C 7F08D70C 160B0005 */  bne   $s0, $t3, .Ljp7F08D724
/* 0C2280 7F08D710 00000000 */   nop   
/* 0C2284 7F08D714 8D8D0000 */  lw    $t5, ($t4)
/* 0C2288 7F08D718 020D082A */  slt   $at, $s0, $t5
/* 0C228C 7F08D71C 50200004 */  beql  $at, $zero, .Ljp7F08D730
/* 0C2290 7F08D720 02008825 */   move  $s1, $s0
.Ljp7F08D724:
/* 0C2294 7F08D724 10000020 */  b     .Ljp7F08D7A8
/* 0C2298 7F08D728 02009825 */   move  $s3, $s0
.Ljp7F08D72C:
/* 0C229C 7F08D72C 02008825 */  move  $s1, $s0
.Ljp7F08D730:
/* 0C22A0 7F08D730 1000001D */  b     .Ljp7F08D7A8
/* 0C22A4 7F08D734 00009825 */   move  $s3, $zero
.Ljp7F08D738:
/* 0C22A8 7F08D738 260E0020 */  addiu $t6, $s0, 0x20
.Ljp7F08D73C:
/* 0C22AC 7F08D73C 01C3001A */  div   $zero, $t6, $v1
/* 0C22B0 7F08D740 00008010 */  mfhi  $s0
/* 0C22B4 7F08D744 14600002 */  bnez  $v1, .Ljp7F08D750
/* 0C22B8 7F08D748 00000000 */   nop   
/* 0C22BC 7F08D74C 0007000D */  break 7
.Ljp7F08D750:
/* 0C22C0 7F08D750 2401FFFF */  li    $at, -1
/* 0C22C4 7F08D754 14610004 */  bne   $v1, $at, .Ljp7F08D768
/* 0C22C8 7F08D758 3C018000 */   lui   $at, 0x8000
/* 0C22CC 7F08D75C 15C10002 */  bne   $t6, $at, .Ljp7F08D768
/* 0C22D0 7F08D760 00000000 */   nop   
/* 0C22D4 7F08D764 0006000D */  break 6
.Ljp7F08D768:
/* 0C22D8 7F08D768 1600FFAA */  bnez  $s0, .Ljp7F08D614
/* 0C22DC 7F08D76C 00000000 */   nop   
/* 0C22E0 7F08D770 260F0020 */  addiu $t7, $s0, 0x20
/* 0C22E4 7F08D774 01E3001A */  div   $zero, $t7, $v1
/* 0C22E8 7F08D778 00008010 */  mfhi  $s0
/* 0C22EC 7F08D77C 14600002 */  bnez  $v1, .Ljp7F08D788
/* 0C22F0 7F08D780 00000000 */   nop   
/* 0C22F4 7F08D784 0007000D */  break 7
.Ljp7F08D788:
/* 0C22F8 7F08D788 2401FFFF */  li    $at, -1
/* 0C22FC 7F08D78C 14610004 */  bne   $v1, $at, .Ljp7F08D7A0
/* 0C2300 7F08D790 3C018000 */   lui   $at, 0x8000
/* 0C2304 7F08D794 15E10002 */  bne   $t7, $at, .Ljp7F08D7A0
/* 0C2308 7F08D798 00000000 */   nop   
/* 0C230C 7F08D79C 0006000D */  break 6
.Ljp7F08D7A0:
/* 0C2310 7F08D7A0 1000FF9C */  b     .Ljp7F08D614
/* 0C2314 7F08D7A4 00000000 */   nop   
.Ljp7F08D7A8:
/* 0C2318 7F08D7A8 8FB80028 */  lw    $t8, 0x28($sp)
.Ljp7F08D7AC:
/* 0C231C 7F08D7AC AF110000 */  sw    $s1, ($t8)
/* 0C2320 7F08D7B0 8FB9002C */  lw    $t9, 0x2c($sp)
/* 0C2324 7F08D7B4 AF330000 */  sw    $s3, ($t9)
/* 0C2328 7F08D7B8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C232C 7F08D7BC 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C2330 7F08D7C0 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C2334 7F08D7C4 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C2338 7F08D7C8 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C233C 7F08D7CC 03E00008 */  jr    $ra
/* 0C2340 7F08D7D0 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F08CE70(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08CE70
/* 0C19A0 7F08CE70 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C19A4 7F08CE74 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C19A8 7F08CE78 27BDFFF8 */  addiu $sp, $sp, -8
/* 0C19AC 7F08CE7C AFB00004 */  sw    $s0, 4($sp)
/* 0C19B0 7F08CE80 8DC511E0 */  lw    $a1, 0x11e0($t6)
/* 0C19B4 7F08CE84 00808025 */  move  $s0, $a0
/* 0C19B8 7F08CE88 00001025 */  move  $v0, $zero
/* 0C19BC 7F08CE8C 10A0001B */  beqz  $a1, .L7F08CEFC
/* 0C19C0 7F08CE90 00A01825 */   move  $v1, $a1
/* 0C19C4 7F08CE94 240A0004 */  li    $t2, 4
/* 0C19C8 7F08CE98 24090001 */  li    $t1, 1
/* 0C19CC 7F08CE9C 24080002 */  li    $t0, 2
/* 0C19D0 7F08CEA0 8C6F0000 */  lw    $t7, ($v1)
.L7F08CEA4:
/* 0C19D4 7F08CEA4 550F0011 */  bnel  $t0, $t7, .L7F08CEEC
/* 0C19D8 7F08CEA8 8C63000C */   lw    $v1, 0xc($v1)
/* 0C19DC 7F08CEAC 8C640004 */  lw    $a0, 4($v1)
/* 0C19E0 7F08CEB0 90980000 */  lbu   $t8, ($a0)
/* 0C19E4 7F08CEB4 5538000D */  bnel  $t1, $t8, .L7F08CEEC
/* 0C19E8 7F08CEB8 8C63000C */   lw    $v1, 0xc($v1)
/* 0C19EC 7F08CEBC 8C870004 */  lw    $a3, 4($a0)
/* 0C19F0 7F08CEC0 90F90003 */  lbu   $t9, 3($a3)
/* 0C19F4 7F08CEC4 55590009 */  bnel  $t2, $t9, .L7F08CEEC
/* 0C19F8 7F08CEC8 8C63000C */   lw    $v1, 0xc($v1)
/* 0C19FC 7F08CECC 8CEB0080 */  lw    $t3, 0x80($a3)
/* 0C1A00 7F08CED0 004B1025 */  or    $v0, $v0, $t3
/* 0C1A04 7F08CED4 02026024 */  and   $t4, $s0, $v0
/* 0C1A08 7F08CED8 560C0004 */  bnel  $s0, $t4, .L7F08CEEC
/* 0C1A0C 7F08CEDC 8C63000C */   lw    $v1, 0xc($v1)
/* 0C1A10 7F08CEE0 10000007 */  b     .L7F08CF00
/* 0C1A14 7F08CEE4 24020001 */   li    $v0, 1
/* 0C1A18 7F08CEE8 8C63000C */  lw    $v1, 0xc($v1)
.L7F08CEEC:
/* 0C1A1C 7F08CEEC 50650004 */  beql  $v1, $a1, .L7F08CF00
/* 0C1A20 7F08CEF0 00001025 */   move  $v0, $zero
/* 0C1A24 7F08CEF4 5460FFEB */  bnezl $v1, .L7F08CEA4
/* 0C1A28 7F08CEF8 8C6F0000 */   lw    $t7, ($v1)
.L7F08CEFC:
/* 0C1A2C 7F08CEFC 00001025 */  move  $v0, $zero
.L7F08CF00:
/* 0C1A30 7F08CF00 8FB00004 */  lw    $s0, 4($sp)
/* 0C1A34 7F08CF04 03E00008 */  jr    $ra
/* 0C1A38 7F08CF08 27BD0008 */   addiu $sp, $sp, 8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08CF0C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08CF0C
/* 0C1A3C 7F08CF0C 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C1A40 7F08CF10 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1A44 7F08CF14 240800F8 */  li    $t0, 248
/* 0C1A48 7F08CF18 24070004 */  li    $a3, 4
/* 0C1A4C 7F08CF1C 8DC311E0 */  lw    $v1, 0x11e0($t6)
/* 0C1A50 7F08CF20 24060002 */  li    $a2, 2
/* 0C1A54 7F08CF24 10600013 */  beqz  $v1, .L7F08CF74
/* 0C1A58 7F08CF28 00601025 */   move  $v0, $v1
/* 0C1A5C 7F08CF2C 8C4F0000 */  lw    $t7, ($v0)
.L7F08CF30:
/* 0C1A60 7F08CF30 54CF000C */  bnel  $a2, $t7, .L7F08CF64
/* 0C1A64 7F08CF34 8C42000C */   lw    $v0, 0xc($v0)
/* 0C1A68 7F08CF38 8C440004 */  lw    $a0, 4($v0)
/* 0C1A6C 7F08CF3C 90980000 */  lbu   $t8, ($a0)
/* 0C1A70 7F08CF40 54F80008 */  bnel  $a3, $t8, .L7F08CF64
/* 0C1A74 7F08CF44 8C42000C */   lw    $v0, 0xc($v0)
/* 0C1A78 7F08CF48 8C850004 */  lw    $a1, 4($a0)
/* 0C1A7C 7F08CF4C 84B90004 */  lh    $t9, 4($a1)
/* 0C1A80 7F08CF50 55190004 */  bnel  $t0, $t9, .L7F08CF64
/* 0C1A84 7F08CF54 8C42000C */   lw    $v0, 0xc($v0)
/* 0C1A88 7F08CF58 03E00008 */  jr    $ra
/* 0C1A8C 7F08CF5C 24020001 */   li    $v0, 1

/* 0C1A90 7F08CF60 8C42000C */  lw    $v0, 0xc($v0)
.L7F08CF64:
/* 0C1A94 7F08CF64 50430004 */  beql  $v0, $v1, .L7F08CF78
/* 0C1A98 7F08CF68 00001025 */   move  $v0, $zero
/* 0C1A9C 7F08CF6C 5440FFF0 */  bnezl $v0, .L7F08CF30
/* 0C1AA0 7F08CF70 8C4F0000 */   lw    $t7, ($v0)
.L7F08CF74:
/* 0C1AA4 7F08CF74 00001025 */  move  $v0, $zero
.L7F08CF78:
/* 0C1AA8 7F08CF78 03E00008 */  jr    $ra
/* 0C1AAC 7F08CF7C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08CF80(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08CF80
/* 0C1AB0 7F08CF80 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C1AB4 7F08CF84 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1AB8 7F08CF88 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C1ABC 7F08CF8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1AC0 7F08CF90 8DCF00D8 */  lw    $t7, 0xd8($t6)
/* 0C1AC4 7F08CF94 00001025 */  move  $v0, $zero
/* 0C1AC8 7F08CF98 15E00005 */  bnez  $t7, .L7F08CFB0
/* 0C1ACC 7F08CF9C 00000000 */   nop   
/* 0C1AD0 7F08CFA0 0FC230C5 */  jal   is_weapon_in_inv
/* 0C1AD4 7F08CFA4 24040058 */   li    $a0, 88
/* 0C1AD8 7F08CFA8 10000002 */  b     .L7F08CFB4
/* 0C1ADC 7F08CFAC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08CFB0:
/* 0C1AE0 7F08CFB0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08CFB4:
/* 0C1AE4 7F08CFB4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C1AE8 7F08CFB8 03E00008 */  jr    $ra
/* 0C1AEC 7F08CFBC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08CFC0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08CFC0
/* 0C1AF0 7F08CFC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C1AF4 7F08CFC4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1AF8 7F08CFC8 0FC230C5 */  jal   is_weapon_in_inv
/* 0C1AFC 7F08CFCC 24040013 */   li    $a0, 19
/* 0C1B00 7F08CFD0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C1B04 7F08CFD4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C1B08 7F08CFD8 03E00008 */  jr    $ra
/* 0C1B0C 7F08CFDC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08CFE0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08CFE0
/* 0C1B10 7F08CFE0 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C1B14 7F08CFE4 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1B18 7F08CFE8 24050002 */  li    $a1, 2
/* 0C1B1C 7F08CFEC 8DC311E0 */  lw    $v1, 0x11e0($t6)
/* 0C1B20 7F08CFF0 1060000E */  beqz  $v1, .L7F08D02C
/* 0C1B24 7F08CFF4 00601025 */   move  $v0, $v1
/* 0C1B28 7F08CFF8 8C4F0000 */  lw    $t7, ($v0)
.L7F08CFFC:
/* 0C1B2C 7F08CFFC 54AF0007 */  bnel  $a1, $t7, .L7F08D01C
/* 0C1B30 7F08D000 8C42000C */   lw    $v0, 0xc($v0)
/* 0C1B34 7F08D004 8C580004 */  lw    $t8, 4($v0)
/* 0C1B38 7F08D008 54980004 */  bnel  $a0, $t8, .L7F08D01C
/* 0C1B3C 7F08D00C 8C42000C */   lw    $v0, 0xc($v0)
/* 0C1B40 7F08D010 03E00008 */  jr    $ra
/* 0C1B44 7F08D014 24020001 */   li    $v0, 1

/* 0C1B48 7F08D018 8C42000C */  lw    $v0, 0xc($v0)
.L7F08D01C:
/* 0C1B4C 7F08D01C 50430004 */  beql  $v0, $v1, .L7F08D030
/* 0C1B50 7F08D020 00001025 */   move  $v0, $zero
/* 0C1B54 7F08D024 5440FFF5 */  bnezl $v0, .L7F08CFFC
/* 0C1B58 7F08D028 8C4F0000 */   lw    $t7, ($v0)
.L7F08D02C:
/* 0C1B5C 7F08D02C 00001025 */  move  $v0, $zero
.L7F08D030:
/* 0C1B60 7F08D030 03E00008 */  jr    $ra
/* 0C1B64 7F08D034 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D038(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D038
/* 0C1B68 7F08D038 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C1B6C 7F08D03C 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C1B70 7F08D040 00001825 */  move  $v1, $zero
/* 0C1B74 7F08D044 3C0B0004 */  lui   $t3, 4
/* 0C1B78 7F08D048 8C4411EC */  lw    $a0, 0x11ec($v0)
/* 0C1B7C 7F08D04C 240A0001 */  li    $t2, 1
/* 0C1B80 7F08D050 24090004 */  li    $t1, 4
/* 0C1B84 7F08D054 10800002 */  beqz  $a0, .L7F08D060
/* 0C1B88 7F08D058 24080002 */   li    $t0, 2
/* 0C1B8C 7F08D05C 24030020 */  li    $v1, 32
.L7F08D060:
/* 0C1B90 7F08D060 8C4611E0 */  lw    $a2, 0x11e0($v0)
/* 0C1B94 7F08D064 10C00026 */  beqz  $a2, .L7F08D100
/* 0C1B98 7F08D068 00C02825 */   move  $a1, $a2
/* 0C1B9C 7F08D06C 8CA20000 */  lw    $v0, ($a1)
.L7F08D070:
/* 0C1BA0 7F08D070 15020015 */  bne   $t0, $v0, .L7F08D0C8
/* 0C1BA4 7F08D074 00000000 */   nop   
/* 0C1BA8 7F08D078 8CA20004 */  lw    $v0, 4($a1)
/* 0C1BAC 7F08D07C 90470000 */  lbu   $a3, ($v0)
/* 0C1BB0 7F08D080 15270008 */  bne   $t1, $a3, .L7F08D0A4
/* 0C1BB4 7F08D084 00000000 */   nop   
/* 0C1BB8 7F08D088 8C470004 */  lw    $a3, 4($v0)
/* 0C1BBC 7F08D08C 8CEE0064 */  lw    $t6, 0x64($a3)
/* 0C1BC0 7F08D090 31CF0400 */  andi  $t7, $t6, 0x400
/* 0C1BC4 7F08D094 51E00016 */  beql  $t7, $zero, .L7F08D0F0
/* 0C1BC8 7F08D098 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1BCC 7F08D09C 10000013 */  b     .L7F08D0EC
/* 0C1BD0 7F08D0A0 24630001 */   addiu $v1, $v1, 1
.L7F08D0A4:
/* 0C1BD4 7F08D0A4 55470012 */  bnel  $t2, $a3, .L7F08D0F0
/* 0C1BD8 7F08D0A8 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1BDC 7F08D0AC 8C580004 */  lw    $t8, 4($v0)
/* 0C1BE0 7F08D0B0 8F19000C */  lw    $t9, 0xc($t8)
/* 0C1BE4 7F08D0B4 032B6024 */  and   $t4, $t9, $t3
/* 0C1BE8 7F08D0B8 5580000D */  bnezl $t4, .L7F08D0F0
/* 0C1BEC 7F08D0BC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1BF0 7F08D0C0 1000000A */  b     .L7F08D0EC
/* 0C1BF4 7F08D0C4 24630001 */   addiu $v1, $v1, 1
.L7F08D0C8:
/* 0C1BF8 7F08D0C8 55420009 */  bnel  $t2, $v0, .L7F08D0F0
/* 0C1BFC 7F08D0CC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1C00 7F08D0D0 50800006 */  beql  $a0, $zero, .L7F08D0EC
/* 0C1C04 7F08D0D4 24630001 */   addiu $v1, $v1, 1
/* 0C1C08 7F08D0D8 8CAD0004 */  lw    $t5, 4($a1)
/* 0C1C0C 7F08D0DC 29A10021 */  slti  $at, $t5, 0x21
/* 0C1C10 7F08D0E0 54200003 */  bnezl $at, .L7F08D0F0
/* 0C1C14 7F08D0E4 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1C18 7F08D0E8 24630001 */  addiu $v1, $v1, 1
.L7F08D0EC:
/* 0C1C1C 7F08D0EC 8CA5000C */  lw    $a1, 0xc($a1)
.L7F08D0F0:
/* 0C1C20 7F08D0F0 10A60003 */  beq   $a1, $a2, .L7F08D100
/* 0C1C24 7F08D0F4 00000000 */   nop   
/* 0C1C28 7F08D0F8 54A0FFDD */  bnezl $a1, .L7F08D070
/* 0C1C2C 7F08D0FC 8CA20000 */   lw    $v0, ($a1)
.L7F08D100:
/* 0C1C30 7F08D100 03E00008 */  jr    $ra
/* 0C1C34 7F08D104 00601025 */   move  $v0, $v1
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D038
/* 0C250C 7F08D99C 3C028008 */  lui   $v0, %hi(pPlayer) # $v0, 0x8008
/* 0C2510 7F08D9A0 8C42A120 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C2514 7F08D9A4 00001825 */  move  $v1, $zero
/* 0C2518 7F08D9A8 3C0E8005 */  lui   $t6, %hi(j_text_trigger) # $t6, 0x8005
/* 0C251C 7F08D9AC 8C4411EC */  lw    $a0, 0x11ec($v0)
/* 0C2520 7F08D9B0 3C0B0004 */  lui   $t3, 4
/* 0C2524 7F08D9B4 240A0001 */  li    $t2, 1
/* 0C2528 7F08D9B8 10800007 */  beqz  $a0, .Ljp7F08D9D8
/* 0C252C 7F08D9BC 24090004 */   li    $t1, 4
/* 0C2530 7F08D9C0 8DCE8500 */  lw    $t6, %lo(j_text_trigger)($t6)
/* 0C2534 7F08D9C4 24030020 */  li    $v1, 32
/* 0C2538 7F08D9C8 11C00003 */  beqz  $t6, .Ljp7F08D9D8
/* 0C253C 7F08D9CC 00000000 */   nop   
/* 0C2540 7F08D9D0 10000001 */  b     .Ljp7F08D9D8
/* 0C2544 7F08D9D4 2403001F */   li    $v1, 31
.Ljp7F08D9D8:
/* 0C2548 7F08D9D8 8C4611E0 */  lw    $a2, 0x11e0($v0)
/* 0C254C 7F08D9DC 24080002 */  li    $t0, 2
/* 0C2550 7F08D9E0 10C00026 */  beqz  $a2, .Ljp7F08DA7C
/* 0C2554 7F08D9E4 00C02825 */   move  $a1, $a2
/* 0C2558 7F08D9E8 8CA20000 */  lw    $v0, ($a1)
.Ljp7F08D9EC:
/* 0C255C 7F08D9EC 15020015 */  bne   $t0, $v0, .Ljp7F08DA44
/* 0C2560 7F08D9F0 00000000 */   nop   
/* 0C2564 7F08D9F4 8CA20004 */  lw    $v0, 4($a1)
/* 0C2568 7F08D9F8 90470000 */  lbu   $a3, ($v0)
/* 0C256C 7F08D9FC 15270008 */  bne   $t1, $a3, .Ljp7F08DA20
/* 0C2570 7F08DA00 00000000 */   nop   
/* 0C2574 7F08DA04 8C470004 */  lw    $a3, 4($v0)
/* 0C2578 7F08DA08 8CEF0064 */  lw    $t7, 0x64($a3)
/* 0C257C 7F08DA0C 31F80400 */  andi  $t8, $t7, 0x400
/* 0C2580 7F08DA10 53000016 */  beql  $t8, $zero, .Ljp7F08DA6C
/* 0C2584 7F08DA14 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C2588 7F08DA18 10000013 */  b     .Ljp7F08DA68
/* 0C258C 7F08DA1C 24630001 */   addiu $v1, $v1, 1
.Ljp7F08DA20:
/* 0C2590 7F08DA20 55470012 */  bnel  $t2, $a3, .Ljp7F08DA6C
/* 0C2594 7F08DA24 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C2598 7F08DA28 8C590004 */  lw    $t9, 4($v0)
/* 0C259C 7F08DA2C 8F2C000C */  lw    $t4, 0xc($t9)
/* 0C25A0 7F08DA30 018B6824 */  and   $t5, $t4, $t3
/* 0C25A4 7F08DA34 55A0000D */  bnezl $t5, .Ljp7F08DA6C
/* 0C25A8 7F08DA38 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C25AC 7F08DA3C 1000000A */  b     .Ljp7F08DA68
/* 0C25B0 7F08DA40 24630001 */   addiu $v1, $v1, 1
.Ljp7F08DA44:
/* 0C25B4 7F08DA44 55420009 */  bnel  $t2, $v0, .Ljp7F08DA6C
/* 0C25B8 7F08DA48 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C25BC 7F08DA4C 50800006 */  beql  $a0, $zero, .Ljp7F08DA68
/* 0C25C0 7F08DA50 24630001 */   addiu $v1, $v1, 1
/* 0C25C4 7F08DA54 8CAE0004 */  lw    $t6, 4($a1)
/* 0C25C8 7F08DA58 29C10021 */  slti  $at, $t6, 0x21
/* 0C25CC 7F08DA5C 54200003 */  bnezl $at, .Ljp7F08DA6C
/* 0C25D0 7F08DA60 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C25D4 7F08DA64 24630001 */  addiu $v1, $v1, 1
.Ljp7F08DA68:
/* 0C25D8 7F08DA68 8CA5000C */  lw    $a1, 0xc($a1)
.Ljp7F08DA6C:
/* 0C25DC 7F08DA6C 10A60003 */  beq   $a1, $a2, .Ljp7F08DA7C
/* 0C25E0 7F08DA70 00000000 */   nop   
/* 0C25E4 7F08DA74 54A0FFDD */  bnezl $a1, .Ljp7F08D9EC
/* 0C25E8 7F08DA78 8CA20000 */   lw    $v0, ($a1)
.Ljp7F08DA7C:
/* 0C25EC 7F08DA7C 03E00008 */  jr    $ra
/* 0C25F0 7F08DA80 00601025 */   move  $v0, $v1
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F08D108(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D108
/* 0C1C38 7F08D108 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C1C3C 7F08D10C 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C1C40 7F08D110 28810020 */  slti  $at, $a0, 0x20
/* 0C1C44 7F08D114 8C4311EC */  lw    $v1, 0x11ec($v0)
/* 0C1C48 7F08D118 50600006 */  beql  $v1, $zero, .L7F08D134
/* 0C1C4C 7F08D11C 8C4611E0 */   lw    $a2, 0x11e0($v0)
/* 0C1C50 7F08D120 10200003 */  beqz  $at, .L7F08D130
/* 0C1C54 7F08D124 2484FFE0 */   addiu $a0, $a0, -0x20
/* 0C1C58 7F08D128 03E00008 */  jr    $ra
/* 0C1C5C 7F08D12C 00001025 */   move  $v0, $zero

.L7F08D130:
/* 0C1C60 7F08D130 8C4611E0 */  lw    $a2, 0x11e0($v0)
.L7F08D134:
/* 0C1C64 7F08D134 3C0B0004 */  lui   $t3, 4
/* 0C1C68 7F08D138 240A0001 */  li    $t2, 1
/* 0C1C6C 7F08D13C 10C00034 */  beqz  $a2, .L7F08D210
/* 0C1C70 7F08D140 00C02825 */   move  $a1, $a2
/* 0C1C74 7F08D144 24090004 */  li    $t1, 4
/* 0C1C78 7F08D148 24080002 */  li    $t0, 2
/* 0C1C7C 7F08D14C 8CA20000 */  lw    $v0, ($a1)
.L7F08D150:
/* 0C1C80 7F08D150 1502001D */  bne   $t0, $v0, .L7F08D1C8
/* 0C1C84 7F08D154 00000000 */   nop   
/* 0C1C88 7F08D158 8CA20004 */  lw    $v0, 4($a1)
/* 0C1C8C 7F08D15C 90470000 */  lbu   $a3, ($v0)
/* 0C1C90 7F08D160 1527000C */  bne   $t1, $a3, .L7F08D194
/* 0C1C94 7F08D164 00000000 */   nop   
/* 0C1C98 7F08D168 8C470004 */  lw    $a3, 4($v0)
/* 0C1C9C 7F08D16C 8CEE0064 */  lw    $t6, 0x64($a3)
/* 0C1CA0 7F08D170 31CF0400 */  andi  $t7, $t6, 0x400
/* 0C1CA4 7F08D174 51E00022 */  beql  $t7, $zero, .L7F08D200
/* 0C1CA8 7F08D178 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1CAC 7F08D17C 14800003 */  bnez  $a0, .L7F08D18C
/* 0C1CB0 7F08D180 00000000 */   nop   
/* 0C1CB4 7F08D184 03E00008 */  jr    $ra
/* 0C1CB8 7F08D188 00A01025 */   move  $v0, $a1

.L7F08D18C:
/* 0C1CBC 7F08D18C 1000001B */  b     .L7F08D1FC
/* 0C1CC0 7F08D190 2484FFFF */   addiu $a0, $a0, -1
.L7F08D194:
/* 0C1CC4 7F08D194 5547001A */  bnel  $t2, $a3, .L7F08D200
/* 0C1CC8 7F08D198 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1CCC 7F08D19C 8C580004 */  lw    $t8, 4($v0)
/* 0C1CD0 7F08D1A0 8F19000C */  lw    $t9, 0xc($t8)
/* 0C1CD4 7F08D1A4 032B6024 */  and   $t4, $t9, $t3
/* 0C1CD8 7F08D1A8 55800015 */  bnezl $t4, .L7F08D200
/* 0C1CDC 7F08D1AC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1CE0 7F08D1B0 14800003 */  bnez  $a0, .L7F08D1C0
/* 0C1CE4 7F08D1B4 00000000 */   nop   
/* 0C1CE8 7F08D1B8 03E00008 */  jr    $ra
/* 0C1CEC 7F08D1BC 00A01025 */   move  $v0, $a1

.L7F08D1C0:
/* 0C1CF0 7F08D1C0 1000000E */  b     .L7F08D1FC
/* 0C1CF4 7F08D1C4 2484FFFF */   addiu $a0, $a0, -1
.L7F08D1C8:
/* 0C1CF8 7F08D1C8 5542000D */  bnel  $t2, $v0, .L7F08D200
/* 0C1CFC 7F08D1CC 8CA5000C */   lw    $a1, 0xc($a1)
/* 0C1D00 7F08D1D0 10600005 */  beqz  $v1, .L7F08D1E8
/* 0C1D04 7F08D1D4 00000000 */   nop   
/* 0C1D08 7F08D1D8 8CAD0004 */  lw    $t5, 4($a1)
/* 0C1D0C 7F08D1DC 29A10021 */  slti  $at, $t5, 0x21
/* 0C1D10 7F08D1E0 54200007 */  bnezl $at, .L7F08D200
/* 0C1D14 7F08D1E4 8CA5000C */   lw    $a1, 0xc($a1)
.L7F08D1E8:
/* 0C1D18 7F08D1E8 54800004 */  bnezl $a0, .L7F08D1FC
/* 0C1D1C 7F08D1EC 2484FFFF */   addiu $a0, $a0, -1
/* 0C1D20 7F08D1F0 03E00008 */  jr    $ra
/* 0C1D24 7F08D1F4 00A01025 */   move  $v0, $a1

/* 0C1D28 7F08D1F8 2484FFFF */  addiu $a0, $a0, -1
.L7F08D1FC:
/* 0C1D2C 7F08D1FC 8CA5000C */  lw    $a1, 0xc($a1)
.L7F08D200:
/* 0C1D30 7F08D200 50A60004 */  beql  $a1, $a2, .L7F08D214
/* 0C1D34 7F08D204 00001025 */   move  $v0, $zero
/* 0C1D38 7F08D208 54A0FFD1 */  bnezl $a1, .L7F08D150
/* 0C1D3C 7F08D20C 8CA20000 */   lw    $v0, ($a1)
.L7F08D210:
/* 0C1D40 7F08D210 00001025 */  move  $v0, $zero
.L7F08D214:
/* 0C1D44 7F08D214 03E00008 */  jr    $ra
/* 0C1D48 7F08D218 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D108
/* 0C25F4 7F08DA84 3C028008 */  lui   $v0, %hi(pPlayer) # $v0, 0x8008
/* 0C25F8 7F08DA88 8C42A120 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C25FC 7F08DA8C 00803025 */  move  $a2, $a0
/* 0C2600 7F08DA90 3C048005 */  lui   $a0, %hi(j_text_trigger) # $a0, 0x8005
/* 0C2604 7F08DA94 8C4311EC */  lw    $v1, 0x11ec($v0)
/* 0C2608 7F08DA98 50600012 */  beql  $v1, $zero, .Ljp7F08DAE4
/* 0C260C 7F08DA9C 8C4511E0 */   lw    $a1, 0x11e0($v0)
/* 0C2610 7F08DAA0 8C848500 */  lw    $a0, %lo(j_text_trigger)($a0)
/* 0C2614 7F08DAA4 24050020 */  li    $a1, 32
/* 0C2618 7F08DAA8 10800003 */  beqz  $a0, .Ljp7F08DAB8
/* 0C261C 7F08DAAC 00000000 */   nop   
/* 0C2620 7F08DAB0 10000001 */  b     .Ljp7F08DAB8
/* 0C2624 7F08DAB4 2405001F */   li    $a1, 31
.Ljp7F08DAB8:
/* 0C2628 7F08DAB8 00C5082A */  slt   $at, $a2, $a1
/* 0C262C 7F08DABC 10200003 */  beqz  $at, .Ljp7F08DACC
/* 0C2630 7F08DAC0 00000000 */   nop   
/* 0C2634 7F08DAC4 03E00008 */  jr    $ra
/* 0C2638 7F08DAC8 00001025 */   move  $v0, $zero

.Ljp7F08DACC:
/* 0C263C 7F08DACC 10800003 */  beqz  $a0, .Ljp7F08DADC
/* 0C2640 7F08DAD0 24050020 */   li    $a1, 32
/* 0C2644 7F08DAD4 10000001 */  b     .Ljp7F08DADC
/* 0C2648 7F08DAD8 2405001F */   li    $a1, 31
.Ljp7F08DADC:
/* 0C264C 7F08DADC 00C53023 */  subu  $a2, $a2, $a1
/* 0C2650 7F08DAE0 8C4511E0 */  lw    $a1, 0x11e0($v0)
.Ljp7F08DAE4:
/* 0C2654 7F08DAE4 3C0B0004 */  lui   $t3, 4
/* 0C2658 7F08DAE8 240A0001 */  li    $t2, 1
/* 0C265C 7F08DAEC 10A00034 */  beqz  $a1, .Ljp7F08DBC0
/* 0C2660 7F08DAF0 00A02025 */   move  $a0, $a1
/* 0C2664 7F08DAF4 24090004 */  li    $t1, 4
/* 0C2668 7F08DAF8 24080002 */  li    $t0, 2
/* 0C266C 7F08DAFC 8C820000 */  lw    $v0, ($a0)
.Ljp7F08DB00:
/* 0C2670 7F08DB00 1502001D */  bne   $t0, $v0, .Ljp7F08DB78
/* 0C2674 7F08DB04 00000000 */   nop   
/* 0C2678 7F08DB08 8C820004 */  lw    $v0, 4($a0)
/* 0C267C 7F08DB0C 90470000 */  lbu   $a3, ($v0)
/* 0C2680 7F08DB10 1527000C */  bne   $t1, $a3, .Ljp7F08DB44
/* 0C2684 7F08DB14 00000000 */   nop   
/* 0C2688 7F08DB18 8C470004 */  lw    $a3, 4($v0)
/* 0C268C 7F08DB1C 8CEE0064 */  lw    $t6, 0x64($a3)
/* 0C2690 7F08DB20 31CF0400 */  andi  $t7, $t6, 0x400
/* 0C2694 7F08DB24 51E00022 */  beql  $t7, $zero, .Ljp7F08DBB0
/* 0C2698 7F08DB28 8C84000C */   lw    $a0, 0xc($a0)
/* 0C269C 7F08DB2C 14C00003 */  bnez  $a2, .Ljp7F08DB3C
/* 0C26A0 7F08DB30 00000000 */   nop   
/* 0C26A4 7F08DB34 03E00008 */  jr    $ra
/* 0C26A8 7F08DB38 00801025 */   move  $v0, $a0

.Ljp7F08DB3C:
/* 0C26AC 7F08DB3C 1000001B */  b     .Ljp7F08DBAC
/* 0C26B0 7F08DB40 24C6FFFF */   addiu $a2, $a2, -1
.Ljp7F08DB44:
/* 0C26B4 7F08DB44 5547001A */  bnel  $t2, $a3, .Ljp7F08DBB0
/* 0C26B8 7F08DB48 8C84000C */   lw    $a0, 0xc($a0)
/* 0C26BC 7F08DB4C 8C580004 */  lw    $t8, 4($v0)
/* 0C26C0 7F08DB50 8F19000C */  lw    $t9, 0xc($t8)
/* 0C26C4 7F08DB54 032B6024 */  and   $t4, $t9, $t3
/* 0C26C8 7F08DB58 55800015 */  bnezl $t4, .Ljp7F08DBB0
/* 0C26CC 7F08DB5C 8C84000C */   lw    $a0, 0xc($a0)
/* 0C26D0 7F08DB60 14C00003 */  bnez  $a2, .Ljp7F08DB70
/* 0C26D4 7F08DB64 00000000 */   nop   
/* 0C26D8 7F08DB68 03E00008 */  jr    $ra
/* 0C26DC 7F08DB6C 00801025 */   move  $v0, $a0

.Ljp7F08DB70:
/* 0C26E0 7F08DB70 1000000E */  b     .Ljp7F08DBAC
/* 0C26E4 7F08DB74 24C6FFFF */   addiu $a2, $a2, -1
.Ljp7F08DB78:
/* 0C26E8 7F08DB78 5542000D */  bnel  $t2, $v0, .Ljp7F08DBB0
/* 0C26EC 7F08DB7C 8C84000C */   lw    $a0, 0xc($a0)
/* 0C26F0 7F08DB80 10600005 */  beqz  $v1, .Ljp7F08DB98
/* 0C26F4 7F08DB84 00000000 */   nop   
/* 0C26F8 7F08DB88 8C8D0004 */  lw    $t5, 4($a0)
/* 0C26FC 7F08DB8C 29A10021 */  slti  $at, $t5, 0x21
/* 0C2700 7F08DB90 54200007 */  bnezl $at, .Ljp7F08DBB0
/* 0C2704 7F08DB94 8C84000C */   lw    $a0, 0xc($a0)
.Ljp7F08DB98:
/* 0C2708 7F08DB98 54C00004 */  bnezl $a2, .Ljp7F08DBAC
/* 0C270C 7F08DB9C 24C6FFFF */   addiu $a2, $a2, -1
/* 0C2710 7F08DBA0 03E00008 */  jr    $ra
/* 0C2714 7F08DBA4 00801025 */   move  $v0, $a0

/* 0C2718 7F08DBA8 24C6FFFF */  addiu $a2, $a2, -1
.Ljp7F08DBAC:
/* 0C271C 7F08DBAC 8C84000C */  lw    $a0, 0xc($a0)
.Ljp7F08DBB0:
/* 0C2720 7F08DBB0 50850004 */  beql  $a0, $a1, .Ljp7F08DBC4
/* 0C2724 7F08DBB4 00001025 */   move  $v0, $zero
/* 0C2728 7F08DBB8 5480FFD1 */  bnezl $a0, .Ljp7F08DB00
/* 0C272C 7F08DBBC 8C820000 */   lw    $v0, ($a0)
.Ljp7F08DBC0:
/* 0C2730 7F08DBC0 00001025 */  move  $v0, $zero
.Ljp7F08DBC4:
/* 0C2734 7F08DBC4 03E00008 */  jr    $ra
/* 0C2738 7F08DBC8 00000000 */   nop   
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F08D21C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D21C
/* 0C1D4C 7F08D21C 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C1D50 7F08D220 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1D54 7F08D224 00001025 */  move  $v0, $zero
/* 0C1D58 7F08D228 8DC311F4 */  lw    $v1, 0x11f4($t6)
/* 0C1D5C 7F08D22C 10600009 */  beqz  $v1, .L7F08D254
/* 0C1D60 7F08D230 00000000 */   nop   
/* 0C1D64 7F08D234 8C6F0024 */  lw    $t7, 0x24($v1)
.L7F08D238:
/* 0C1D68 7F08D238 548F0004 */  bnel  $a0, $t7, .L7F08D24C
/* 0C1D6C 7F08D23C 8C630020 */   lw    $v1, 0x20($v1)
/* 0C1D70 7F08D240 03E00008 */  jr    $ra
/* 0C1D74 7F08D244 00601025 */   move  $v0, $v1

/* 0C1D78 7F08D248 8C630020 */  lw    $v1, 0x20($v1)
.L7F08D24C:
/* 0C1D7C 7F08D24C 5460FFFA */  bnezl $v1, .L7F08D238
/* 0C1D80 7F08D250 8C6F0024 */   lw    $t7, 0x24($v1)
.L7F08D254:
/* 0C1D84 7F08D254 03E00008 */  jr    $ra
/* 0C1D88 7F08D258 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D25C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D25C
/* 0C1D8C 7F08D25C 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C1D90 7F08D260 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1D94 7F08D264 00001025 */  move  $v0, $zero
/* 0C1D98 7F08D268 8DC311F4 */  lw    $v1, 0x11f4($t6)
/* 0C1D9C 7F08D26C 1060000C */  beqz  $v1, .L7F08D2A0
/* 0C1DA0 7F08D270 00000000 */   nop   
/* 0C1DA4 7F08D274 8C6F0004 */  lw    $t7, 4($v1)
.L7F08D278:
/* 0C1DA8 7F08D278 55E00007 */  bnezl $t7, .L7F08D298
/* 0C1DAC 7F08D27C 8C630020 */   lw    $v1, 0x20($v1)
/* 0C1DB0 7F08D280 8C780008 */  lw    $t8, 8($v1)
/* 0C1DB4 7F08D284 54980004 */  bnel  $a0, $t8, .L7F08D298
/* 0C1DB8 7F08D288 8C630020 */   lw    $v1, 0x20($v1)
/* 0C1DBC 7F08D28C 03E00008 */  jr    $ra
/* 0C1DC0 7F08D290 00601025 */   move  $v0, $v1

/* 0C1DC4 7F08D294 8C630020 */  lw    $v1, 0x20($v1)
.L7F08D298:
/* 0C1DC8 7F08D298 5460FFF7 */  bnezl $v1, .L7F08D278
/* 0C1DCC 7F08D29C 8C6F0004 */   lw    $t7, 4($v1)
.L7F08D2A0:
/* 0C1DD0 7F08D2A0 03E00008 */  jr    $ra
/* 0C1DD4 7F08D2A4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D2A8(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D2A8
/* 0C1DD8 7F08D2A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C1DDC 7F08D2AC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1DE0 7F08D2B0 0FC23442 */  jal   sub_GAME_7F08D108
/* 0C1DE4 7F08D2B4 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C1DE8 7F08D2B8 8FA40018 */  lw    $a0, 0x18($sp)
/* 0C1DEC 7F08D2BC 10400011 */  beqz  $v0, .L7F08D304
/* 0C1DF0 7F08D2C0 00401825 */   move  $v1, $v0
/* 0C1DF4 7F08D2C4 8C440000 */  lw    $a0, ($v0)
/* 0C1DF8 7F08D2C8 24010002 */  li    $at, 2
/* 0C1DFC 7F08D2CC 54810009 */  bnel  $a0, $at, .L7F08D2F4
/* 0C1E00 7F08D2D0 24010001 */   li    $at, 1
/* 0C1E04 7F08D2D4 8C420004 */  lw    $v0, 4($v0)
/* 0C1E08 7F08D2D8 0FC23487 */  jal   sub_GAME_7F08D21C
/* 0C1E0C 7F08D2DC 8C440004 */   lw    $a0, 4($v0)
/* 0C1E10 7F08D2E0 50400013 */  beql  $v0, $zero, .L7F08D330
/* 0C1E14 7F08D2E4 00001025 */   move  $v0, $zero
/* 0C1E18 7F08D2E8 10000011 */  b     .L7F08D330
/* 0C1E1C 7F08D2EC 8C420008 */   lw    $v0, 8($v0)
/* 0C1E20 7F08D2F0 24010001 */  li    $at, 1
.L7F08D2F4:
/* 0C1E24 7F08D2F4 5481000E */  bnel  $a0, $at, .L7F08D330
/* 0C1E28 7F08D2F8 00001025 */   move  $v0, $zero
/* 0C1E2C 7F08D2FC 1000000C */  b     .L7F08D330
/* 0C1E30 7F08D300 8C620004 */   lw    $v0, 4($v1)
.L7F08D304:
/* 0C1E34 7F08D304 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C1E38 7F08D308 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C1E3C 7F08D30C 28810020 */  slti  $at, $a0, 0x20
/* 0C1E40 7F08D310 8DCF11EC */  lw    $t7, 0x11ec($t6)
/* 0C1E44 7F08D314 51E00006 */  beql  $t7, $zero, .L7F08D330
/* 0C1E48 7F08D318 00001025 */   move  $v0, $zero
/* 0C1E4C 7F08D31C 50200004 */  beql  $at, $zero, .L7F08D330
/* 0C1E50 7F08D320 00001025 */   move  $v0, $zero
/* 0C1E54 7F08D324 10000002 */  b     .L7F08D330
/* 0C1E58 7F08D328 24820001 */   addiu $v0, $a0, 1
/* 0C1E5C 7F08D32C 00001025 */  move  $v0, $zero
.L7F08D330:
/* 0C1E60 7F08D330 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C1E64 7F08D334 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C1E68 7F08D338 03E00008 */  jr    $ra
/* 0C1E6C 7F08D33C 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D2A8
/* 0C27C8 7F08DC58 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C27CC 7F08DC5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C27D0 7F08DC60 0FC236A1 */  jal   sub_GAME_7F08D108
/* 0C27D4 7F08DC64 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C27D8 7F08DC68 8FA40018 */  lw    $a0, 0x18($sp)
/* 0C27DC 7F08DC6C 10400011 */  beqz  $v0, .Ljp7F08DCB4
/* 0C27E0 7F08DC70 00401825 */   move  $v1, $v0
/* 0C27E4 7F08DC74 8C440000 */  lw    $a0, ($v0)
/* 0C27E8 7F08DC78 24010002 */  li    $at, 2
/* 0C27EC 7F08DC7C 54810009 */  bnel  $a0, $at, .Ljp7F08DCA4
/* 0C27F0 7F08DC80 24010001 */   li    $at, 1
/* 0C27F4 7F08DC84 8C420004 */  lw    $v0, 4($v0)
/* 0C27F8 7F08DC88 0FC236F3 */  jal   sub_GAME_7F08D21C
/* 0C27FC 7F08DC8C 8C440004 */   lw    $a0, 4($v0)
/* 0C2800 7F08DC90 50400021 */  beql  $v0, $zero, .Ljp7F08DD18
/* 0C2804 7F08DC94 00001025 */   move  $v0, $zero
/* 0C2808 7F08DC98 1000001F */  b     .Ljp7F08DD18
/* 0C280C 7F08DC9C 8C420008 */   lw    $v0, 8($v0)
/* 0C2810 7F08DCA0 24010001 */  li    $at, 1
.Ljp7F08DCA4:
/* 0C2814 7F08DCA4 5481001C */  bnel  $a0, $at, .Ljp7F08DD18
/* 0C2818 7F08DCA8 00001025 */   move  $v0, $zero
/* 0C281C 7F08DCAC 1000001A */  b     .Ljp7F08DD18
/* 0C2820 7F08DCB0 8C620004 */   lw    $v0, 4($v1)
.Ljp7F08DCB4:
/* 0C2824 7F08DCB4 3C0E8008 */  lui   $t6, %hi(pPlayer) # $t6, 0x8008
/* 0C2828 7F08DCB8 8DCEA120 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C282C 7F08DCBC 3C028005 */  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
/* 0C2830 7F08DCC0 8DCF11EC */  lw    $t7, 0x11ec($t6)
/* 0C2834 7F08DCC4 51E00014 */  beql  $t7, $zero, .Ljp7F08DD18
/* 0C2838 7F08DCC8 00001025 */   move  $v0, $zero
/* 0C283C 7F08DCCC 8C428500 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0C2840 7F08DCD0 24030020 */  li    $v1, 32
/* 0C2844 7F08DCD4 10400003 */  beqz  $v0, .Ljp7F08DCE4
/* 0C2848 7F08DCD8 00000000 */   nop   
/* 0C284C 7F08DCDC 10000001 */  b     .Ljp7F08DCE4
/* 0C2850 7F08DCE0 2403001F */   li    $v1, 31
.Ljp7F08DCE4:
/* 0C2854 7F08DCE4 0083082A */  slt   $at, $a0, $v1
/* 0C2858 7F08DCE8 5020000B */  beql  $at, $zero, .Ljp7F08DD18
/* 0C285C 7F08DCEC 00001025 */   move  $v0, $zero
/* 0C2860 7F08DCF0 10400006 */  beqz  $v0, .Ljp7F08DD0C
/* 0C2864 7F08DCF4 24980001 */   addiu $t8, $a0, 1
/* 0C2868 7F08DCF8 2B010002 */  slti  $at, $t8, 2
/* 0C286C 7F08DCFC 14200003 */  bnez  $at, .Ljp7F08DD0C
/* 0C2870 7F08DD00 00000000 */   nop   
/* 0C2874 7F08DD04 10000004 */  b     .Ljp7F08DD18
/* 0C2878 7F08DD08 24820002 */   addiu $v0, $a0, 2
.Ljp7F08DD0C:
/* 0C287C 7F08DD0C 10000002 */  b     .Ljp7F08DD18
/* 0C2880 7F08DD10 24820001 */   addiu $v0, $a0, 1
/* 0C2884 7F08DD14 00001025 */  move  $v0, $zero
.Ljp7F08DD18:
/* 0C2888 7F08DD18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C288C 7F08DD1C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C2890 7F08DD20 03E00008 */  jr    $ra
/* 0C2894 7F08DD24 00000000 */   nop   
)
#endif

#endif




#ifdef NONMATCHING
void sub_GAME_7F08D340(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D340
/* 0C1E70 7F08D340 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C1E74 7F08D344 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1E78 7F08D348 0FC23442 */  jal   sub_GAME_7F08D108
/* 0C1E7C 7F08D34C AFA40020 */   sw    $a0, 0x20($sp)
/* 0C1E80 7F08D350 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C1E84 7F08D354 00401825 */  move  $v1, $v0
/* 0C1E88 7F08D358 10400024 */  beqz  $v0, .L7F08D3EC
/* 0C1E8C 7F08D35C 00003025 */   move  $a2, $zero
/* 0C1E90 7F08D360 8C440000 */  lw    $a0, ($v0)
/* 0C1E94 7F08D364 24010002 */  li    $at, 2
/* 0C1E98 7F08D368 54810012 */  bnel  $a0, $at, .L7F08D3B4
/* 0C1E9C 7F08D36C 24010001 */   li    $at, 1
/* 0C1EA0 7F08D370 8C420004 */  lw    $v0, 4($v0)
/* 0C1EA4 7F08D374 8C440004 */  lw    $a0, 4($v0)
/* 0C1EA8 7F08D378 0FC23487 */  jal   sub_GAME_7F08D21C
/* 0C1EAC 7F08D37C AFA00018 */   sw    $zero, 0x18($sp)
/* 0C1EB0 7F08D380 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C1EB4 7F08D384 10400025 */  beqz  $v0, .L7F08D41C
/* 0C1EB8 7F08D388 00401825 */   move  $v1, $v0
/* 0C1EBC 7F08D38C 8C4E0014 */  lw    $t6, 0x14($v0)
/* 0C1EC0 7F08D390 11C00005 */  beqz  $t6, .L7F08D3A8
/* 0C1EC4 7F08D394 00000000 */   nop   
/* 0C1EC8 7F08D398 0FC30776 */  jal   get_textptr_for_textID
/* 0C1ECC 7F08D39C 8C640014 */   lw    $a0, 0x14($v1)
/* 0C1ED0 7F08D3A0 10000021 */  b     .L7F08D428
/* 0C1ED4 7F08D3A4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D3A8:
/* 0C1ED8 7F08D3A8 1000001C */  b     .L7F08D41C
/* 0C1EDC 7F08D3AC 8C460008 */   lw    $a2, 8($v0)
/* 0C1EE0 7F08D3B0 24010001 */  li    $at, 1
.L7F08D3B4:
/* 0C1EE4 7F08D3B4 14810019 */  bne   $a0, $at, .L7F08D41C
/* 0C1EE8 7F08D3B8 00000000 */   nop   
/* 0C1EEC 7F08D3BC 8C640004 */  lw    $a0, 4($v1)
/* 0C1EF0 7F08D3C0 0FC23497 */  jal   sub_GAME_7F08D25C
/* 0C1EF4 7F08D3C4 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C1EF8 7F08D3C8 10400014 */  beqz  $v0, .L7F08D41C
/* 0C1EFC 7F08D3CC 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C1F00 7F08D3D0 8C4F0014 */  lw    $t7, 0x14($v0)
/* 0C1F04 7F08D3D4 11E00011 */  beqz  $t7, .L7F08D41C
/* 0C1F08 7F08D3D8 00000000 */   nop   
/* 0C1F0C 7F08D3DC 0FC30776 */  jal   get_textptr_for_textID
/* 0C1F10 7F08D3E0 8C440014 */   lw    $a0, 0x14($v0)
/* 0C1F14 7F08D3E4 10000010 */  b     .L7F08D428
/* 0C1F18 7F08D3E8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D3EC:
/* 0C1F1C 7F08D3EC 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C1F20 7F08D3F0 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C1F24 7F08D3F4 28A10020 */  slti  $at, $a1, 0x20
/* 0C1F28 7F08D3F8 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C1F2C 7F08D3FC 13200007 */  beqz  $t9, .L7F08D41C
/* 0C1F30 7F08D400 00000000 */   nop   
/* 0C1F34 7F08D404 10200005 */  beqz  $at, .L7F08D41C
/* 0C1F38 7F08D408 00000000 */   nop   
/* 0C1F3C 7F08D40C 0FC19C2A */  jal   get_ptr_short_watch_text_for_item
/* 0C1F40 7F08D410 24A40001 */   addiu $a0, $a1, 1
/* 0C1F44 7F08D414 10000004 */  b     .L7F08D428
/* 0C1F48 7F08D418 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D41C:
/* 0C1F4C 7F08D41C 0FC19C2A */  jal   get_ptr_short_watch_text_for_item
/* 0C1F50 7F08D420 00C02025 */   move  $a0, $a2
/* 0C1F54 7F08D424 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D428:
/* 0C1F58 7F08D428 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C1F5C 7F08D42C 03E00008 */  jr    $ra
/* 0C1F60 7F08D430 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D340
/* 0C2898 7F08DD28 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C289C 7F08DD2C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C28A0 7F08DD30 0FC236A1 */  jal   sub_GAME_7F08D108
/* 0C28A4 7F08DD34 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C28A8 7F08DD38 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C28AC 7F08DD3C 00401825 */  move  $v1, $v0
/* 0C28B0 7F08DD40 10400024 */  beqz  $v0, .Ljp7F08DDD4
/* 0C28B4 7F08DD44 00003025 */   move  $a2, $zero
/* 0C28B8 7F08DD48 8C440000 */  lw    $a0, ($v0)
/* 0C28BC 7F08DD4C 24010002 */  li    $at, 2
/* 0C28C0 7F08DD50 54810012 */  bnel  $a0, $at, .Ljp7F08DD9C
/* 0C28C4 7F08DD54 24010001 */   li    $at, 1
/* 0C28C8 7F08DD58 8C420004 */  lw    $v0, 4($v0)
/* 0C28CC 7F08DD5C 8C440004 */  lw    $a0, 4($v0)
/* 0C28D0 7F08DD60 0FC236F3 */  jal   sub_GAME_7F08D21C
/* 0C28D4 7F08DD64 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C28D8 7F08DD68 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C28DC 7F08DD6C 10400035 */  beqz  $v0, .Ljp7F08DE44
/* 0C28E0 7F08DD70 00401825 */   move  $v1, $v0
/* 0C28E4 7F08DD74 8C4E0014 */  lw    $t6, 0x14($v0)
/* 0C28E8 7F08DD78 11C00005 */  beqz  $t6, .Ljp7F08DD90
/* 0C28EC 7F08DD7C 00000000 */   nop   
/* 0C28F0 7F08DD80 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C28F4 7F08DD84 8C640014 */   lw    $a0, 0x14($v1)
/* 0C28F8 7F08DD88 10000031 */  b     .Ljp7F08DE50
/* 0C28FC 7F08DD8C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DD90:
/* 0C2900 7F08DD90 1000002C */  b     .Ljp7F08DE44
/* 0C2904 7F08DD94 8C460008 */   lw    $a2, 8($v0)
/* 0C2908 7F08DD98 24010001 */  li    $at, 1
.Ljp7F08DD9C:
/* 0C290C 7F08DD9C 14810029 */  bne   $a0, $at, .Ljp7F08DE44
/* 0C2910 7F08DDA0 00000000 */   nop   
/* 0C2914 7F08DDA4 8C640004 */  lw    $a0, 4($v1)
/* 0C2918 7F08DDA8 0FC23703 */  jal   sub_GAME_7F08D25C
/* 0C291C 7F08DDAC AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2920 7F08DDB0 10400024 */  beqz  $v0, .Ljp7F08DE44
/* 0C2924 7F08DDB4 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C2928 7F08DDB8 8C4F0014 */  lw    $t7, 0x14($v0)
/* 0C292C 7F08DDBC 11E00021 */  beqz  $t7, .Ljp7F08DE44
/* 0C2930 7F08DDC0 00000000 */   nop   
/* 0C2934 7F08DDC4 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C2938 7F08DDC8 8C440014 */   lw    $a0, 0x14($v0)
/* 0C293C 7F08DDCC 10000020 */  b     .Ljp7F08DE50
/* 0C2940 7F08DDD0 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DDD4:
/* 0C2944 7F08DDD4 3C188008 */  lui   $t8, %hi(pPlayer) # $t8, 0x8008
/* 0C2948 7F08DDD8 8F18A120 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C294C 7F08DDDC 3C028005 */  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
/* 0C2950 7F08DDE0 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C2954 7F08DDE4 13200017 */  beqz  $t9, .Ljp7F08DE44
/* 0C2958 7F08DDE8 00000000 */   nop   
/* 0C295C 7F08DDEC 8C428500 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0C2960 7F08DDF0 24030020 */  li    $v1, 32
/* 0C2964 7F08DDF4 10400003 */  beqz  $v0, .Ljp7F08DE04
/* 0C2968 7F08DDF8 00000000 */   nop   
/* 0C296C 7F08DDFC 10000001 */  b     .Ljp7F08DE04
/* 0C2970 7F08DE00 2403001F */   li    $v1, 31
.Ljp7F08DE04:
/* 0C2974 7F08DE04 00A3082A */  slt   $at, $a1, $v1
/* 0C2978 7F08DE08 1020000E */  beqz  $at, .Ljp7F08DE44
/* 0C297C 7F08DE0C 00000000 */   nop   
/* 0C2980 7F08DE10 10400008 */  beqz  $v0, .Ljp7F08DE34
/* 0C2984 7F08DE14 24A80001 */   addiu $t0, $a1, 1
/* 0C2988 7F08DE18 29010002 */  slti  $at, $t0, 2
/* 0C298C 7F08DE1C 14200005 */  bnez  $at, .Ljp7F08DE34
/* 0C2990 7F08DE20 00000000 */   nop   
/* 0C2994 7F08DE24 0FC19DA0 */  jal   get_ptr_short_watch_text_for_item
/* 0C2998 7F08DE28 24A40002 */   addiu $a0, $a1, 2
/* 0C299C 7F08DE2C 10000008 */  b     .Ljp7F08DE50
/* 0C29A0 7F08DE30 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DE34:
/* 0C29A4 7F08DE34 0FC19DA0 */  jal   get_ptr_short_watch_text_for_item
/* 0C29A8 7F08DE38 24A40001 */   addiu $a0, $a1, 1
/* 0C29AC 7F08DE3C 10000004 */  b     .Ljp7F08DE50
/* 0C29B0 7F08DE40 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DE44:
/* 0C29B4 7F08DE44 0FC19DA0 */  jal   get_ptr_short_watch_text_for_item
/* 0C29B8 7F08DE48 00C02025 */   move  $a0, $a2
/* 0C29BC 7F08DE4C 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F08DE50:
/* 0C29C0 7F08DE50 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C29C4 7F08DE54 03E00008 */  jr    $ra
/* 0C29C8 7F08DE58 00000000 */   nop     
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F08D434(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D434
/* 0C1F64 7F08D434 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C1F68 7F08D438 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C1F6C 7F08D43C 0FC23442 */  jal   sub_GAME_7F08D108
/* 0C1F70 7F08D440 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C1F74 7F08D444 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C1F78 7F08D448 00401825 */  move  $v1, $v0
/* 0C1F7C 7F08D44C 10400024 */  beqz  $v0, .L7F08D4E0
/* 0C1F80 7F08D450 00003025 */   move  $a2, $zero
/* 0C1F84 7F08D454 8C440000 */  lw    $a0, ($v0)
/* 0C1F88 7F08D458 24010002 */  li    $at, 2
/* 0C1F8C 7F08D45C 54810012 */  bnel  $a0, $at, .L7F08D4A8
/* 0C1F90 7F08D460 24010001 */   li    $at, 1
/* 0C1F94 7F08D464 8C420004 */  lw    $v0, 4($v0)
/* 0C1F98 7F08D468 8C440004 */  lw    $a0, 4($v0)
/* 0C1F9C 7F08D46C 0FC23487 */  jal   sub_GAME_7F08D21C
/* 0C1FA0 7F08D470 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C1FA4 7F08D474 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C1FA8 7F08D478 10400025 */  beqz  $v0, .L7F08D510
/* 0C1FAC 7F08D47C 00401825 */   move  $v1, $v0
/* 0C1FB0 7F08D480 8C4E0018 */  lw    $t6, 0x18($v0)
/* 0C1FB4 7F08D484 11C00005 */  beqz  $t6, .L7F08D49C
/* 0C1FB8 7F08D488 00000000 */   nop   
/* 0C1FBC 7F08D48C 0FC30776 */  jal   get_textptr_for_textID
/* 0C1FC0 7F08D490 8C640018 */   lw    $a0, 0x18($v1)
/* 0C1FC4 7F08D494 10000021 */  b     .L7F08D51C
/* 0C1FC8 7F08D498 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D49C:
/* 0C1FCC 7F08D49C 1000001C */  b     .L7F08D510
/* 0C1FD0 7F08D4A0 8C460008 */   lw    $a2, 8($v0)
/* 0C1FD4 7F08D4A4 24010001 */  li    $at, 1
.L7F08D4A8:
/* 0C1FD8 7F08D4A8 14810019 */  bne   $a0, $at, .L7F08D510
/* 0C1FDC 7F08D4AC 00000000 */   nop   
/* 0C1FE0 7F08D4B0 8C640004 */  lw    $a0, 4($v1)
/* 0C1FE4 7F08D4B4 0FC23497 */  jal   sub_GAME_7F08D25C
/* 0C1FE8 7F08D4B8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C1FEC 7F08D4BC 10400014 */  beqz  $v0, .L7F08D510
/* 0C1FF0 7F08D4C0 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C1FF4 7F08D4C4 8C4F0018 */  lw    $t7, 0x18($v0)
/* 0C1FF8 7F08D4C8 11E00011 */  beqz  $t7, .L7F08D510
/* 0C1FFC 7F08D4CC 00000000 */   nop   
/* 0C2000 7F08D4D0 0FC30776 */  jal   get_textptr_for_textID
/* 0C2004 7F08D4D4 8C440018 */   lw    $a0, 0x18($v0)
/* 0C2008 7F08D4D8 10000010 */  b     .L7F08D51C
/* 0C200C 7F08D4DC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D4E0:
/* 0C2010 7F08D4E0 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C2014 7F08D4E4 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C2018 7F08D4E8 28A10020 */  slti  $at, $a1, 0x20
/* 0C201C 7F08D4EC 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C2020 7F08D4F0 13200007 */  beqz  $t9, .L7F08D510
/* 0C2024 7F08D4F4 00000000 */   nop   
/* 0C2028 7F08D4F8 10200005 */  beqz  $at, .L7F08D510
/* 0C202C 7F08D4FC 00000000 */   nop   
/* 0C2030 7F08D500 0FC19C37 */  jal   get_ptr_long_watch_text_for_item
/* 0C2034 7F08D504 24A40001 */   addiu $a0, $a1, 1
/* 0C2038 7F08D508 10000004 */  b     .L7F08D51C
/* 0C203C 7F08D50C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D510:
/* 0C2040 7F08D510 0FC19C37 */  jal   get_ptr_long_watch_text_for_item
/* 0C2044 7F08D514 00C02025 */   move  $a0, $a2
/* 0C2048 7F08D518 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D51C:
/* 0C204C 7F08D51C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C2050 7F08D520 03E00008 */  jr    $ra
/* 0C2054 7F08D524 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D434
/* 0C29CC 7F08DE5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C29D0 7F08DE60 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C29D4 7F08DE64 0FC236A1 */  jal   sub_GAME_7F08D108
/* 0C29D8 7F08DE68 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C29DC 7F08DE6C 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C29E0 7F08DE70 00401825 */  move  $v1, $v0
/* 0C29E4 7F08DE74 10400024 */  beqz  $v0, .Ljp7F08DF08
/* 0C29E8 7F08DE78 00003025 */   move  $a2, $zero
/* 0C29EC 7F08DE7C 8C440000 */  lw    $a0, ($v0)
/* 0C29F0 7F08DE80 24010002 */  li    $at, 2
/* 0C29F4 7F08DE84 54810012 */  bnel  $a0, $at, .Ljp7F08DED0
/* 0C29F8 7F08DE88 24010001 */   li    $at, 1
/* 0C29FC 7F08DE8C 8C420004 */  lw    $v0, 4($v0)
/* 0C2A00 7F08DE90 8C440004 */  lw    $a0, 4($v0)
/* 0C2A04 7F08DE94 0FC236F3 */  jal   sub_GAME_7F08D21C
/* 0C2A08 7F08DE98 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C2A0C 7F08DE9C 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C2A10 7F08DEA0 10400035 */  beqz  $v0, .Ljp7F08DF78
/* 0C2A14 7F08DEA4 00401825 */   move  $v1, $v0
/* 0C2A18 7F08DEA8 8C4E0018 */  lw    $t6, 0x18($v0)
/* 0C2A1C 7F08DEAC 11C00005 */  beqz  $t6, .Ljp7F08DEC4
/* 0C2A20 7F08DEB0 00000000 */   nop   
/* 0C2A24 7F08DEB4 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C2A28 7F08DEB8 8C640018 */   lw    $a0, 0x18($v1)
/* 0C2A2C 7F08DEBC 10000031 */  b     .Ljp7F08DF84
/* 0C2A30 7F08DEC0 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DEC4:
/* 0C2A34 7F08DEC4 1000002C */  b     .Ljp7F08DF78
/* 0C2A38 7F08DEC8 8C460008 */   lw    $a2, 8($v0)
/* 0C2A3C 7F08DECC 24010001 */  li    $at, 1
.Ljp7F08DED0:
/* 0C2A40 7F08DED0 14810029 */  bne   $a0, $at, .Ljp7F08DF78
/* 0C2A44 7F08DED4 00000000 */   nop   
/* 0C2A48 7F08DED8 8C640004 */  lw    $a0, 4($v1)
/* 0C2A4C 7F08DEDC 0FC23703 */  jal   sub_GAME_7F08D25C
/* 0C2A50 7F08DEE0 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2A54 7F08DEE4 10400024 */  beqz  $v0, .Ljp7F08DF78
/* 0C2A58 7F08DEE8 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C2A5C 7F08DEEC 8C4F0018 */  lw    $t7, 0x18($v0)
/* 0C2A60 7F08DEF0 11E00021 */  beqz  $t7, .Ljp7F08DF78
/* 0C2A64 7F08DEF4 00000000 */   nop   
/* 0C2A68 7F08DEF8 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C2A6C 7F08DEFC 8C440018 */   lw    $a0, 0x18($v0)
/* 0C2A70 7F08DF00 10000020 */  b     .Ljp7F08DF84
/* 0C2A74 7F08DF04 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DF08:
/* 0C2A78 7F08DF08 3C188008 */  lui   $t8, %hi(pPlayer) # $t8, 0x8008
/* 0C2A7C 7F08DF0C 8F18A120 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C2A80 7F08DF10 3C028005 */  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
/* 0C2A84 7F08DF14 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C2A88 7F08DF18 13200017 */  beqz  $t9, .Ljp7F08DF78
/* 0C2A8C 7F08DF1C 00000000 */   nop   
/* 0C2A90 7F08DF20 8C428500 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0C2A94 7F08DF24 24030020 */  li    $v1, 32
/* 0C2A98 7F08DF28 10400003 */  beqz  $v0, .Ljp7F08DF38
/* 0C2A9C 7F08DF2C 00000000 */   nop   
/* 0C2AA0 7F08DF30 10000001 */  b     .Ljp7F08DF38
/* 0C2AA4 7F08DF34 2403001F */   li    $v1, 31
.Ljp7F08DF38:
/* 0C2AA8 7F08DF38 00A3082A */  slt   $at, $a1, $v1
/* 0C2AAC 7F08DF3C 1020000E */  beqz  $at, .Ljp7F08DF78
/* 0C2AB0 7F08DF40 00000000 */   nop   
/* 0C2AB4 7F08DF44 10400008 */  beqz  $v0, .Ljp7F08DF68
/* 0C2AB8 7F08DF48 24A80001 */   addiu $t0, $a1, 1
/* 0C2ABC 7F08DF4C 29010002 */  slti  $at, $t0, 2
/* 0C2AC0 7F08DF50 14200005 */  bnez  $at, .Ljp7F08DF68
/* 0C2AC4 7F08DF54 00000000 */   nop   
/* 0C2AC8 7F08DF58 0FC19DAD */  jal   get_ptr_long_watch_text_for_item
/* 0C2ACC 7F08DF5C 24A40002 */   addiu $a0, $a1, 2
/* 0C2AD0 7F08DF60 10000008 */  b     .Ljp7F08DF84
/* 0C2AD4 7F08DF64 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DF68:
/* 0C2AD8 7F08DF68 0FC19DAD */  jal   get_ptr_long_watch_text_for_item
/* 0C2ADC 7F08DF6C 24A40001 */   addiu $a0, $a1, 1
/* 0C2AE0 7F08DF70 10000004 */  b     .Ljp7F08DF84
/* 0C2AE4 7F08DF74 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08DF78:
/* 0C2AE8 7F08DF78 0FC19DAD */  jal   get_ptr_long_watch_text_for_item
/* 0C2AEC 7F08DF7C 00C02025 */   move  $a0, $a2
/* 0C2AF0 7F08DF80 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F08DF84:
/* 0C2AF4 7F08DF84 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C2AF8 7F08DF88 03E00008 */  jr    $ra
/* 0C2AFC 7F08DF8C 00000000 */   nop       
)
#endif

#endif



#ifdef NONMATCHING
void sub_GAME_7F08D528(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D528
/* 0C2058 7F08D528 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C205C 7F08D52C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2060 7F08D530 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C2064 7F08D534 00000000 */   nop   
/* 0C2068 7F08D538 0FC19C44 */  jal   get_45_degree_angle_0
/* 0C206C 7F08D53C 00402025 */   move  $a0, $v0
/* 0C2070 7F08D540 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C2074 7F08D544 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C2078 7F08D548 03E00008 */  jr    $ra
/* 0C207C 7F08D54C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D550(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D550
/* 0C2080 7F08D550 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C2084 7F08D554 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2088 7F08D558 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C208C 7F08D55C 00000000 */   nop   
/* 0C2090 7F08D560 0FC19C48 */  jal   get_horizontal_offset_on_solo_watch_menu_for_item
/* 0C2094 7F08D564 00402025 */   move  $a0, $v0
/* 0C2098 7F08D568 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C209C 7F08D56C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C20A0 7F08D570 03E00008 */  jr    $ra
/* 0C20A4 7F08D574 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D578(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D578
/* 0C20A8 7F08D578 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C20AC 7F08D57C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C20B0 7F08D580 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C20B4 7F08D584 00000000 */   nop   
/* 0C20B8 7F08D588 0FC19C4F */  jal   get_vertical_offset_on_solo_watch_menu_for_item
/* 0C20BC 7F08D58C 00402025 */   move  $a0, $v0
/* 0C20C0 7F08D590 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C20C4 7F08D594 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C20C8 7F08D598 03E00008 */  jr    $ra
/* 0C20CC 7F08D59C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D5A0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D5A0
/* 0C20D0 7F08D5A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C20D4 7F08D5A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C20D8 7F08D5A8 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C20DC 7F08D5AC 00000000 */   nop   
/* 0C20E0 7F08D5B0 0FC19C56 */  jal   get_depth_offset_solo_watch_menu_inventory_page_for_item
/* 0C20E4 7F08D5B4 00402025 */   move  $a0, $v0
/* 0C20E8 7F08D5B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C20EC 7F08D5BC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C20F0 7F08D5C0 03E00008 */  jr    $ra
/* 0C20F4 7F08D5C4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D5C8(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D5C8
/* 0C20F8 7F08D5C8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C20FC 7F08D5CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2100 7F08D5D0 0FC23442 */  jal   sub_GAME_7F08D108
/* 0C2104 7F08D5D4 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C2108 7F08D5D8 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C210C 7F08D5DC 00401825 */  move  $v1, $v0
/* 0C2110 7F08D5E0 10400024 */  beqz  $v0, .L7F08D674
/* 0C2114 7F08D5E4 00003025 */   move  $a2, $zero
/* 0C2118 7F08D5E8 8C440000 */  lw    $a0, ($v0)
/* 0C211C 7F08D5EC 24010002 */  li    $at, 2
/* 0C2120 7F08D5F0 54810012 */  bnel  $a0, $at, .L7F08D63C
/* 0C2124 7F08D5F4 24010001 */   li    $at, 1
/* 0C2128 7F08D5F8 8C420004 */  lw    $v0, 4($v0)
/* 0C212C 7F08D5FC 8C440004 */  lw    $a0, 4($v0)
/* 0C2130 7F08D600 0FC23487 */  jal   sub_GAME_7F08D21C
/* 0C2134 7F08D604 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C2138 7F08D608 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C213C 7F08D60C 10400025 */  beqz  $v0, .L7F08D6A4
/* 0C2140 7F08D610 00401825 */   move  $v1, $v0
/* 0C2144 7F08D614 8C4E000C */  lw    $t6, 0xc($v0)
/* 0C2148 7F08D618 11C00005 */  beqz  $t6, .L7F08D630
/* 0C214C 7F08D61C 00000000 */   nop   
/* 0C2150 7F08D620 0FC30776 */  jal   get_textptr_for_textID
/* 0C2154 7F08D624 8C64000C */   lw    $a0, 0xc($v1)
/* 0C2158 7F08D628 10000021 */  b     .L7F08D6B0
/* 0C215C 7F08D62C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D630:
/* 0C2160 7F08D630 1000001C */  b     .L7F08D6A4
/* 0C2164 7F08D634 8C460008 */   lw    $a2, 8($v0)
/* 0C2168 7F08D638 24010001 */  li    $at, 1
.L7F08D63C:
/* 0C216C 7F08D63C 14810019 */  bne   $a0, $at, .L7F08D6A4
/* 0C2170 7F08D640 00000000 */   nop   
/* 0C2174 7F08D644 8C640004 */  lw    $a0, 4($v1)
/* 0C2178 7F08D648 0FC23497 */  jal   sub_GAME_7F08D25C
/* 0C217C 7F08D64C AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2180 7F08D650 10400014 */  beqz  $v0, .L7F08D6A4
/* 0C2184 7F08D654 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C2188 7F08D658 8C4F000C */  lw    $t7, 0xc($v0)
/* 0C218C 7F08D65C 11E00011 */  beqz  $t7, .L7F08D6A4
/* 0C2190 7F08D660 00000000 */   nop   
/* 0C2194 7F08D664 0FC30776 */  jal   get_textptr_for_textID
/* 0C2198 7F08D668 8C44000C */   lw    $a0, 0xc($v0)
/* 0C219C 7F08D66C 10000010 */  b     .L7F08D6B0
/* 0C21A0 7F08D670 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D674:
/* 0C21A4 7F08D674 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C21A8 7F08D678 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C21AC 7F08D67C 28A10020 */  slti  $at, $a1, 0x20
/* 0C21B0 7F08D680 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C21B4 7F08D684 13200007 */  beqz  $t9, .L7F08D6A4
/* 0C21B8 7F08D688 00000000 */   nop   
/* 0C21BC 7F08D68C 10200005 */  beqz  $at, .L7F08D6A4
/* 0C21C0 7F08D690 00000000 */   nop   
/* 0C21C4 7F08D694 0FC19C10 */  jal   get_ptr_first_title_line_item
/* 0C21C8 7F08D698 24A40001 */   addiu $a0, $a1, 1
/* 0C21CC 7F08D69C 10000004 */  b     .L7F08D6B0
/* 0C21D0 7F08D6A0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D6A4:
/* 0C21D4 7F08D6A4 0FC19C10 */  jal   get_ptr_first_title_line_item
/* 0C21D8 7F08D6A8 00C02025 */   move  $a0, $a2
/* 0C21DC 7F08D6AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D6B0:
/* 0C21E0 7F08D6B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C21E4 7F08D6B4 03E00008 */  jr    $ra
/* 0C21E8 7F08D6B8 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D5C8
/* 0C2BA0 7F08E030 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C2BA4 7F08E034 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2BA8 7F08E038 0FC236A1 */  jal   sub_GAME_7F08D108
/* 0C2BAC 7F08E03C AFA40020 */   sw    $a0, 0x20($sp)
/* 0C2BB0 7F08E040 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C2BB4 7F08E044 00401825 */  move  $v1, $v0
/* 0C2BB8 7F08E048 10400024 */  beqz  $v0, .Ljp7F08E0DC
/* 0C2BBC 7F08E04C 00003025 */   move  $a2, $zero
/* 0C2BC0 7F08E050 8C440000 */  lw    $a0, ($v0)
/* 0C2BC4 7F08E054 24010002 */  li    $at, 2
/* 0C2BC8 7F08E058 54810012 */  bnel  $a0, $at, .Ljp7F08E0A4
/* 0C2BCC 7F08E05C 24010001 */   li    $at, 1
/* 0C2BD0 7F08E060 8C420004 */  lw    $v0, 4($v0)
/* 0C2BD4 7F08E064 8C440004 */  lw    $a0, 4($v0)
/* 0C2BD8 7F08E068 0FC236F3 */  jal   sub_GAME_7F08D21C
/* 0C2BDC 7F08E06C AFA00018 */   sw    $zero, 0x18($sp)
/* 0C2BE0 7F08E070 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C2BE4 7F08E074 10400035 */  beqz  $v0, .Ljp7F08E14C
/* 0C2BE8 7F08E078 00401825 */   move  $v1, $v0
/* 0C2BEC 7F08E07C 8C4E000C */  lw    $t6, 0xc($v0)
/* 0C2BF0 7F08E080 11C00005 */  beqz  $t6, .Ljp7F08E098
/* 0C2BF4 7F08E084 00000000 */   nop   
/* 0C2BF8 7F08E088 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C2BFC 7F08E08C 8C64000C */   lw    $a0, 0xc($v1)
/* 0C2C00 7F08E090 10000031 */  b     .Ljp7F08E158
/* 0C2C04 7F08E094 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E098:
/* 0C2C08 7F08E098 1000002C */  b     .Ljp7F08E14C
/* 0C2C0C 7F08E09C 8C460008 */   lw    $a2, 8($v0)
/* 0C2C10 7F08E0A0 24010001 */  li    $at, 1
.Ljp7F08E0A4:
/* 0C2C14 7F08E0A4 14810029 */  bne   $a0, $at, .Ljp7F08E14C
/* 0C2C18 7F08E0A8 00000000 */   nop   
/* 0C2C1C 7F08E0AC 8C640004 */  lw    $a0, 4($v1)
/* 0C2C20 7F08E0B0 0FC23703 */  jal   sub_GAME_7F08D25C
/* 0C2C24 7F08E0B4 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2C28 7F08E0B8 10400024 */  beqz  $v0, .Ljp7F08E14C
/* 0C2C2C 7F08E0BC 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C2C30 7F08E0C0 8C4F000C */  lw    $t7, 0xc($v0)
/* 0C2C34 7F08E0C4 11E00021 */  beqz  $t7, .Ljp7F08E14C
/* 0C2C38 7F08E0C8 00000000 */   nop   
/* 0C2C3C 7F08E0CC 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C2C40 7F08E0D0 8C44000C */   lw    $a0, 0xc($v0)
/* 0C2C44 7F08E0D4 10000020 */  b     .Ljp7F08E158
/* 0C2C48 7F08E0D8 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E0DC:
/* 0C2C4C 7F08E0DC 3C188008 */  lui   $t8, %hi(pPlayer) # $t8, 0x8008
/* 0C2C50 7F08E0E0 8F18A120 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C2C54 7F08E0E4 3C028005 */  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
/* 0C2C58 7F08E0E8 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C2C5C 7F08E0EC 13200017 */  beqz  $t9, .Ljp7F08E14C
/* 0C2C60 7F08E0F0 00000000 */   nop   
/* 0C2C64 7F08E0F4 8C428500 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0C2C68 7F08E0F8 24030020 */  li    $v1, 32
/* 0C2C6C 7F08E0FC 10400003 */  beqz  $v0, .Ljp7F08E10C
/* 0C2C70 7F08E100 00000000 */   nop   
/* 0C2C74 7F08E104 10000001 */  b     .Ljp7F08E10C
/* 0C2C78 7F08E108 2403001F */   li    $v1, 31
.Ljp7F08E10C:
/* 0C2C7C 7F08E10C 00A3082A */  slt   $at, $a1, $v1
/* 0C2C80 7F08E110 1020000E */  beqz  $at, .Ljp7F08E14C
/* 0C2C84 7F08E114 00000000 */   nop   
/* 0C2C88 7F08E118 10400008 */  beqz  $v0, .Ljp7F08E13C
/* 0C2C8C 7F08E11C 24A80001 */   addiu $t0, $a1, 1
/* 0C2C90 7F08E120 29010002 */  slti  $at, $t0, 2
/* 0C2C94 7F08E124 14200005 */  bnez  $at, .Ljp7F08E13C
/* 0C2C98 7F08E128 00000000 */   nop   
/* 0C2C9C 7F08E12C 0FC19D86 */  jal   get_ptr_first_title_line_item
/* 0C2CA0 7F08E130 24A40002 */   addiu $a0, $a1, 2
/* 0C2CA4 7F08E134 10000008 */  b     .Ljp7F08E158
/* 0C2CA8 7F08E138 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E13C:
/* 0C2CAC 7F08E13C 0FC19D86 */  jal   get_ptr_first_title_line_item
/* 0C2CB0 7F08E140 24A40001 */   addiu $a0, $a1, 1
/* 0C2CB4 7F08E144 10000004 */  b     .Ljp7F08E158
/* 0C2CB8 7F08E148 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E14C:
/* 0C2CBC 7F08E14C 0FC19D86 */  jal   get_ptr_first_title_line_item
/* 0C2CC0 7F08E150 00C02025 */   move  $a0, $a2
/* 0C2CC4 7F08E154 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F08E158:
/* 0C2CC8 7F08E158 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C2CCC 7F08E15C 03E00008 */  jr    $ra
/* 0C2CD0 7F08E160 00000000 */   nop       
)
#endif

#endif




#ifdef NONMATCHING
void sub_GAME_7F08D6BC(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D6BC
/* 0C21EC 7F08D6BC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C21F0 7F08D6C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C21F4 7F08D6C4 0FC23442 */  jal   sub_GAME_7F08D108
/* 0C21F8 7F08D6C8 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C21FC 7F08D6CC 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C2200 7F08D6D0 00401825 */  move  $v1, $v0
/* 0C2204 7F08D6D4 10400024 */  beqz  $v0, .L7F08D768
/* 0C2208 7F08D6D8 00003025 */   move  $a2, $zero
/* 0C220C 7F08D6DC 8C440000 */  lw    $a0, ($v0)
/* 0C2210 7F08D6E0 24010002 */  li    $at, 2
/* 0C2214 7F08D6E4 54810012 */  bnel  $a0, $at, .L7F08D730
/* 0C2218 7F08D6E8 24010001 */   li    $at, 1
/* 0C221C 7F08D6EC 8C420004 */  lw    $v0, 4($v0)
/* 0C2220 7F08D6F0 8C440004 */  lw    $a0, 4($v0)
/* 0C2224 7F08D6F4 0FC23487 */  jal   sub_GAME_7F08D21C
/* 0C2228 7F08D6F8 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C222C 7F08D6FC 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C2230 7F08D700 10400025 */  beqz  $v0, .L7F08D798
/* 0C2234 7F08D704 00401825 */   move  $v1, $v0
/* 0C2238 7F08D708 8C4E0010 */  lw    $t6, 0x10($v0)
/* 0C223C 7F08D70C 11C00005 */  beqz  $t6, .L7F08D724
/* 0C2240 7F08D710 00000000 */   nop   
/* 0C2244 7F08D714 0FC30776 */  jal   get_textptr_for_textID
/* 0C2248 7F08D718 8C640010 */   lw    $a0, 0x10($v1)
/* 0C224C 7F08D71C 10000021 */  b     .L7F08D7A4
/* 0C2250 7F08D720 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D724:
/* 0C2254 7F08D724 1000001C */  b     .L7F08D798
/* 0C2258 7F08D728 8C460008 */   lw    $a2, 8($v0)
/* 0C225C 7F08D72C 24010001 */  li    $at, 1
.L7F08D730:
/* 0C2260 7F08D730 14810019 */  bne   $a0, $at, .L7F08D798
/* 0C2264 7F08D734 00000000 */   nop   
/* 0C2268 7F08D738 8C640004 */  lw    $a0, 4($v1)
/* 0C226C 7F08D73C 0FC23497 */  jal   sub_GAME_7F08D25C
/* 0C2270 7F08D740 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2274 7F08D744 10400014 */  beqz  $v0, .L7F08D798
/* 0C2278 7F08D748 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C227C 7F08D74C 8C4F0010 */  lw    $t7, 0x10($v0)
/* 0C2280 7F08D750 11E00011 */  beqz  $t7, .L7F08D798
/* 0C2284 7F08D754 00000000 */   nop   
/* 0C2288 7F08D758 0FC30776 */  jal   get_textptr_for_textID
/* 0C228C 7F08D75C 8C440010 */   lw    $a0, 0x10($v0)
/* 0C2290 7F08D760 10000010 */  b     .L7F08D7A4
/* 0C2294 7F08D764 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D768:
/* 0C2298 7F08D768 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C229C 7F08D76C 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C22A0 7F08D770 28A10020 */  slti  $at, $a1, 0x20
/* 0C22A4 7F08D774 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C22A8 7F08D778 13200007 */  beqz  $t9, .L7F08D798
/* 0C22AC 7F08D77C 00000000 */   nop   
/* 0C22B0 7F08D780 10200005 */  beqz  $at, .L7F08D798
/* 0C22B4 7F08D784 00000000 */   nop   
/* 0C22B8 7F08D788 0FC19C1D */  jal   get_ptr_second_title_line_item
/* 0C22BC 7F08D78C 24A40001 */   addiu $a0, $a1, 1
/* 0C22C0 7F08D790 10000004 */  b     .L7F08D7A4
/* 0C22C4 7F08D794 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F08D798:
/* 0C22C8 7F08D798 0FC19C1D */  jal   get_ptr_second_title_line_item
/* 0C22CC 7F08D79C 00C02025 */   move  $a0, $a2
/* 0C22D0 7F08D7A0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D7A4:
/* 0C22D4 7F08D7A4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C22D8 7F08D7A8 03E00008 */  jr    $ra
/* 0C22DC 7F08D7AC 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D6BC
/* 0C2CD4 7F08E164 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C2CD8 7F08E168 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2CDC 7F08E16C 0FC236A1 */  jal   sub_GAME_7F08D108
/* 0C2CE0 7F08E170 AFA40020 */   sw    $a0, 0x20($sp)
/* 0C2CE4 7F08E174 8FA50020 */  lw    $a1, 0x20($sp)
/* 0C2CE8 7F08E178 00401825 */  move  $v1, $v0
/* 0C2CEC 7F08E17C 10400024 */  beqz  $v0, .Ljp7F08E210
/* 0C2CF0 7F08E180 00003025 */   move  $a2, $zero
/* 0C2CF4 7F08E184 8C440000 */  lw    $a0, ($v0)
/* 0C2CF8 7F08E188 24010002 */  li    $at, 2
/* 0C2CFC 7F08E18C 54810012 */  bnel  $a0, $at, .Ljp7F08E1D8
/* 0C2D00 7F08E190 24010001 */   li    $at, 1
/* 0C2D04 7F08E194 8C420004 */  lw    $v0, 4($v0)
/* 0C2D08 7F08E198 8C440004 */  lw    $a0, 4($v0)
/* 0C2D0C 7F08E19C 0FC236F3 */  jal   sub_GAME_7F08D21C
/* 0C2D10 7F08E1A0 AFA00018 */   sw    $zero, 0x18($sp)
/* 0C2D14 7F08E1A4 8FA60018 */  lw    $a2, 0x18($sp)
/* 0C2D18 7F08E1A8 10400035 */  beqz  $v0, .Ljp7F08E280
/* 0C2D1C 7F08E1AC 00401825 */   move  $v1, $v0
/* 0C2D20 7F08E1B0 8C4E0010 */  lw    $t6, 0x10($v0)
/* 0C2D24 7F08E1B4 11C00005 */  beqz  $t6, .Ljp7F08E1CC
/* 0C2D28 7F08E1B8 00000000 */   nop   
/* 0C2D2C 7F08E1BC 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C2D30 7F08E1C0 8C640010 */   lw    $a0, 0x10($v1)
/* 0C2D34 7F08E1C4 10000031 */  b     .Ljp7F08E28C
/* 0C2D38 7F08E1C8 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E1CC:
/* 0C2D3C 7F08E1CC 1000002C */  b     .Ljp7F08E280
/* 0C2D40 7F08E1D0 8C460008 */   lw    $a2, 8($v0)
/* 0C2D44 7F08E1D4 24010001 */  li    $at, 1
.Ljp7F08E1D8:
/* 0C2D48 7F08E1D8 14810029 */  bne   $a0, $at, .Ljp7F08E280
/* 0C2D4C 7F08E1DC 00000000 */   nop   
/* 0C2D50 7F08E1E0 8C640004 */  lw    $a0, 4($v1)
/* 0C2D54 7F08E1E4 0FC23703 */  jal   sub_GAME_7F08D25C
/* 0C2D58 7F08E1E8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C2D5C 7F08E1EC 10400024 */  beqz  $v0, .Ljp7F08E280
/* 0C2D60 7F08E1F0 8FA60018 */   lw    $a2, 0x18($sp)
/* 0C2D64 7F08E1F4 8C4F0010 */  lw    $t7, 0x10($v0)
/* 0C2D68 7F08E1F8 11E00021 */  beqz  $t7, .Ljp7F08E280
/* 0C2D6C 7F08E1FC 00000000 */   nop   
/* 0C2D70 7F08E200 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C2D74 7F08E204 8C440010 */   lw    $a0, 0x10($v0)
/* 0C2D78 7F08E208 10000020 */  b     .Ljp7F08E28C
/* 0C2D7C 7F08E20C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E210:
/* 0C2D80 7F08E210 3C188008 */  lui   $t8, %hi(pPlayer) # $t8, 0x8008
/* 0C2D84 7F08E214 8F18A120 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C2D88 7F08E218 3C028005 */  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
/* 0C2D8C 7F08E21C 8F1911EC */  lw    $t9, 0x11ec($t8)
/* 0C2D90 7F08E220 13200017 */  beqz  $t9, .Ljp7F08E280
/* 0C2D94 7F08E224 00000000 */   nop   
/* 0C2D98 7F08E228 8C428500 */  lw    $v0, %lo(j_text_trigger)($v0)
/* 0C2D9C 7F08E22C 24030020 */  li    $v1, 32
/* 0C2DA0 7F08E230 10400003 */  beqz  $v0, .Ljp7F08E240
/* 0C2DA4 7F08E234 00000000 */   nop   
/* 0C2DA8 7F08E238 10000001 */  b     .Ljp7F08E240
/* 0C2DAC 7F08E23C 2403001F */   li    $v1, 31
.Ljp7F08E240:
/* 0C2DB0 7F08E240 00A3082A */  slt   $at, $a1, $v1
/* 0C2DB4 7F08E244 1020000E */  beqz  $at, .Ljp7F08E280
/* 0C2DB8 7F08E248 00000000 */   nop   
/* 0C2DBC 7F08E24C 10400008 */  beqz  $v0, .Ljp7F08E270
/* 0C2DC0 7F08E250 24A80001 */   addiu $t0, $a1, 1
/* 0C2DC4 7F08E254 29010002 */  slti  $at, $t0, 2
/* 0C2DC8 7F08E258 14200005 */  bnez  $at, .Ljp7F08E270
/* 0C2DCC 7F08E25C 00000000 */   nop   
/* 0C2DD0 7F08E260 0FC19D93 */  jal   get_ptr_second_title_line_item
/* 0C2DD4 7F08E264 24A40002 */   addiu $a0, $a1, 2
/* 0C2DD8 7F08E268 10000008 */  b     .Ljp7F08E28C
/* 0C2DDC 7F08E26C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E270:
/* 0C2DE0 7F08E270 0FC19D93 */  jal   get_ptr_second_title_line_item
/* 0C2DE4 7F08E274 24A40001 */   addiu $a0, $a1, 1
/* 0C2DE8 7F08E278 10000004 */  b     .Ljp7F08E28C
/* 0C2DEC 7F08E27C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F08E280:
/* 0C2DF0 7F08E280 0FC19D93 */  jal   get_ptr_second_title_line_item
/* 0C2DF4 7F08E284 00C02025 */   move  $a0, $a2
/* 0C2DF8 7F08E288 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F08E28C:
/* 0C2DFC 7F08E28C 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C2E00 7F08E290 03E00008 */  jr    $ra
/* 0C2E04 7F08E294 00000000 */   nop      
)
#endif
#endif




#ifdef NONMATCHING
void sub_GAME_7F08D7B0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D7B0
/* 0C22E0 7F08D7B0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C22E4 7F08D7B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C22E8 7F08D7B8 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C22EC 7F08D7BC 00000000 */   nop   
/* 0C22F0 7F08D7C0 0FC19C0C */  jal   get_45_degree_angle
/* 0C22F4 7F08D7C4 00402025 */   move  $a0, $v0
/* 0C22F8 7F08D7C8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C22FC 7F08D7CC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C2300 7F08D7D0 03E00008 */  jr    $ra
/* 0C2304 7F08D7D4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D7D8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D7D8
/* 0C2308 7F08D7D8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C230C 7F08D7DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2310 7F08D7E0 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C2314 7F08D7E4 00000000 */   nop   
/* 0C2318 7F08D7E8 0FC19BE9 */  jal   get_vertical_position_solo_watch_menu_main_page_for_item
/* 0C231C 7F08D7EC 00402025 */   move  $a0, $v0
/* 0C2320 7F08D7F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C2324 7F08D7F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C2328 7F08D7F8 03E00008 */  jr    $ra
/* 0C232C 7F08D7FC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D800(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D800
/* 0C2330 7F08D800 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C2334 7F08D804 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2338 7F08D808 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C233C 7F08D80C 00000000 */   nop   
/* 0C2340 7F08D810 0FC19BF0 */  jal   get_lateral_position_solo_watch_menu_main_page_for_item
/* 0C2344 7F08D814 00402025 */   move  $a0, $v0
/* 0C2348 7F08D818 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C234C 7F08D81C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C2350 7F08D820 03E00008 */  jr    $ra
/* 0C2354 7F08D824 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D828(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D828
/* 0C2358 7F08D828 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C235C 7F08D82C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2360 7F08D830 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C2364 7F08D834 00000000 */   nop   
/* 0C2368 7F08D838 0FC19BF7 */  jal   get_depth_on_solo_watch_menu_page_for_item
/* 0C236C 7F08D83C 00402025 */   move  $a0, $v0
/* 0C2370 7F08D840 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C2374 7F08D844 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C2378 7F08D848 03E00008 */  jr    $ra
/* 0C237C 7F08D84C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D850(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D850
/* 0C2380 7F08D850 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C2384 7F08D854 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2388 7F08D858 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C238C 7F08D85C 00000000 */   nop   
/* 0C2390 7F08D860 0FC19BFE */  jal   get_zrotation_solo_watch_menu_for_item
/* 0C2394 7F08D864 00402025 */   move  $a0, $v0
/* 0C2398 7F08D868 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C239C 7F08D86C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C23A0 7F08D870 03E00008 */  jr    $ra
/* 0C23A4 7F08D874 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D878(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D878
/* 0C23A8 7F08D878 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C23AC 7F08D87C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C23B0 7F08D880 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C23B4 7F08D884 00000000 */   nop   
/* 0C23B8 7F08D888 0FC19C05 */  jal   get_xrotation_solo_watch_menu_for_item
/* 0C23BC 7F08D88C 00402025 */   move  $a0, $v0
/* 0C23C0 7F08D890 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C23C4 7F08D894 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C23C8 7F08D898 03E00008 */  jr    $ra
/* 0C23CC 7F08D89C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D8A0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D8A0
/* 0C23D0 7F08D8A0 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C23D4 7F08D8A4 2442A0B0 */  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
/* 0C23D8 7F08D8A8 8C4E0000 */  lw    $t6, ($v0)
/* 0C23DC 7F08D8AC 8DCF11F4 */  lw    $t7, 0x11f4($t6)
/* 0C23E0 7F08D8B0 AC8F0020 */  sw    $t7, 0x20($a0)
/* 0C23E4 7F08D8B4 8C580000 */  lw    $t8, ($v0)
/* 0C23E8 7F08D8B8 03E00008 */  jr    $ra
/* 0C23EC 7F08D8BC AF0411F4 */   sw    $a0, 0x11f4($t8)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D8C0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D8C0
/* 0C23F0 7F08D8C0 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C23F4 7F08D8C4 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C23F8 7F08D8C8 03E00008 */  jr    $ra
/* 0C23FC 7F08D8CC 8DC211F0 */   lw    $v0, 0x11f0($t6)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D8D0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D8D0
/* 0C2400 7F08D8D0 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C2404 7F08D8D4 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C2408 7F08D8D8 03E00008 */  jr    $ra
/* 0C240C 7F08D8DC ADC411F0 */   sw    $a0, 0x11f0($t6)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D8E0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D8E0
/* 0C2410 7F08D8E0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C2414 7F08D8E4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C2418 7F08D8E8 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C241C 7F08D8EC AFB00014 */  sw    $s0, 0x14($sp)
/* 0C2420 7F08D8F0 0FC17674 */  jal   get_item_in_hand
/* 0C2424 7F08D8F4 00002025 */   move  $a0, $zero
/* 0C2428 7F08D8F8 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C242C 7F08D8FC 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C2430 7F08D900 00408825 */  move  $s1, $v0
/* 0C2434 7F08D904 00008025 */  move  $s0, $zero
/* 0C2438 7F08D908 0FC2340E */  jal   sub_GAME_7F08D038
/* 0C243C 7F08D90C ADC011F0 */   sw    $zero, 0x11f0($t6)
/* 0C2440 7F08D910 5840000E */  blezl $v0, .L7F08D94C
/* 0C2444 7F08D914 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F08D918:
/* 0C2448 7F08D918 0FC234AA */  jal   sub_GAME_7F08D2A8
/* 0C244C 7F08D91C 02002025 */   move  $a0, $s0
/* 0C2450 7F08D920 14510004 */  bne   $v0, $s1, .L7F08D934
/* 0C2454 7F08D924 3C0F8008 */   lui   $t7, %hi(pPlayer) 
/* 0C2458 7F08D928 8DEFA0B0 */  lw    $t7, %lo(pPlayer)($t7)
/* 0C245C 7F08D92C 10000006 */  b     .L7F08D948
/* 0C2460 7F08D930 ADF011F0 */   sw    $s0, 0x11f0($t7)
.L7F08D934:
/* 0C2464 7F08D934 0FC2340E */  jal   sub_GAME_7F08D038
/* 0C2468 7F08D938 26100001 */   addiu $s0, $s0, 1
/* 0C246C 7F08D93C 0202082A */  slt   $at, $s0, $v0
/* 0C2470 7F08D940 1420FFF5 */  bnez  $at, .L7F08D918
/* 0C2474 7F08D944 00000000 */   nop   
.L7F08D948:
/* 0C2478 7F08D948 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F08D94C:
/* 0C247C 7F08D94C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C2480 7F08D950 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C2484 7F08D954 03E00008 */  jr    $ra
/* 0C2488 7F08D958 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D95C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D95C
/* 0C248C 7F08D95C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C2490 7F08D960 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C2494 7F08D964 0FC23487 */  jal   sub_GAME_7F08D21C
/* 0C2498 7F08D968 00000000 */   nop   
/* 0C249C 7F08D96C 50400009 */  beql  $v0, $zero, .L7F08D994
/* 0C24A0 7F08D970 00001025 */   move  $v0, $zero
/* 0C24A4 7F08D974 8C4E001C */  lw    $t6, 0x1c($v0)
/* 0C24A8 7F08D978 51C00006 */  beql  $t6, $zero, .L7F08D994
/* 0C24AC 7F08D97C 00001025 */   move  $v0, $zero
/* 0C24B0 7F08D980 0FC30776 */  jal   get_textptr_for_textID
/* 0C24B4 7F08D984 8C44001C */   lw    $a0, 0x1c($v0)
/* 0C24B8 7F08D988 10000003 */  b     .L7F08D998
/* 0C24BC 7F08D98C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C24C0 7F08D990 00001025 */  move  $v0, $zero
.L7F08D994:
/* 0C24C4 7F08D994 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D998:
/* 0C24C8 7F08D998 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C24CC 7F08D99C 03E00008 */  jr    $ra
/* 0C24D0 7F08D9A0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D9A4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D9A4
/* 0C24D4 7F08D9A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C24D8 7F08D9A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C24DC 7F08D9AC 0FC23497 */  jal   sub_GAME_7F08D25C
/* 0C24E0 7F08D9B0 00000000 */   nop   
/* 0C24E4 7F08D9B4 50400009 */  beql  $v0, $zero, .L7F08D9DC
/* 0C24E8 7F08D9B8 00001025 */   move  $v0, $zero
/* 0C24EC 7F08D9BC 8C4E001C */  lw    $t6, 0x1c($v0)
/* 0C24F0 7F08D9C0 51C00006 */  beql  $t6, $zero, .L7F08D9DC
/* 0C24F4 7F08D9C4 00001025 */   move  $v0, $zero
/* 0C24F8 7F08D9C8 0FC30776 */  jal   get_textptr_for_textID
/* 0C24FC 7F08D9CC 8C44001C */   lw    $a0, 0x1c($v0)
/* 0C2500 7F08D9D0 10000003 */  b     .L7F08D9E0
/* 0C2504 7F08D9D4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C2508 7F08D9D8 00001025 */  move  $v0, $zero
.L7F08D9DC:
/* 0C250C 7F08D9DC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08D9E0:
/* 0C2510 7F08D9E0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C2514 7F08D9E4 03E00008 */  jr    $ra
/* 0C2518 7F08D9E8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08D9EC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08D9EC
/* 0C251C 7F08D9EC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C2520 7F08D9F0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C2524 7F08D9F4 00A08025 */  move  $s0, $a1
/* 0C2528 7F08D9F8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C252C 7F08D9FC AFB10018 */  sw    $s1, 0x18($sp)
/* 0C2530 7F08DA00 00808825 */  move  $s1, $a0
/* 0C2534 7F08DA04 0FC1782D */  jal   check_special_attributes
/* 0C2538 7F08DA08 3C050002 */   lui   $a1, 2
/* 0C253C 7F08DA0C 10400039 */  beqz  $v0, .L7F08DAF4
/* 0C2540 7F08DA10 3C067FFF */   lui   $a2, (0x7FFFFFFF >> 16) # lui $a2, 0x7fff
/* 0C2544 7F08DA14 34C6FFFF */  ori   $a2, (0x7FFFFFFF & 0xFFFF) # ori $a2, $a2, 0xffff
/* 0C2548 7F08DA18 AFA60024 */  sw    $a2, 0x24($sp)
/* 0C254C 7F08DA1C 02002025 */  move  $a0, $s0
/* 0C2550 7F08DA20 3C050002 */  lui   $a1, 2
/* 0C2554 7F08DA24 0FC1782D */  jal   check_special_attributes
/* 0C2558 7F08DA28 AFA00020 */   sw    $zero, 0x20($sp)
/* 0C255C 7F08DA2C 8FA60024 */  lw    $a2, 0x24($sp)
/* 0C2560 7F08DA30 14400002 */  bnez  $v0, .L7F08DA3C
/* 0C2564 7F08DA34 8FA70020 */   lw    $a3, 0x20($sp)
/* 0C2568 7F08DA38 00008025 */  move  $s0, $zero
.L7F08DA3C:
/* 0C256C 7F08DA3C 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C2570 7F08DA40 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C2574 7F08DA44 00002025 */  move  $a0, $zero
.L7F08DA48:
/* 0C2578 7F08DA48 8C431200 */  lw    $v1, 0x1200($v0)
/* 0C257C 7F08DA4C 04600010 */  bltz  $v1, .L7F08DA90
/* 0C2580 7F08DA50 0066082A */   slt   $at, $v1, $a2
/* 0C2584 7F08DA54 8C4E11F8 */  lw    $t6, 0x11f8($v0)
/* 0C2588 7F08DA58 162E0008 */  bne   $s1, $t6, .L7F08DA7C
/* 0C258C 7F08DA5C 00000000 */   nop   
/* 0C2590 7F08DA60 8C4F11FC */  lw    $t7, 0x11fc($v0)
/* 0C2594 7F08DA64 160F0005 */  bne   $s0, $t7, .L7F08DA7C
/* 0C2598 7F08DA68 3C188005 */   lui   $t8, %hi(clock_timer) 
/* 0C259C 7F08DA6C 8F188374 */  lw    $t8, %lo(clock_timer)($t8)
/* 0C25A0 7F08DA70 0078C821 */  addu  $t9, $v1, $t8
/* 0C25A4 7F08DA74 1000000D */  b     .L7F08DAAC
/* 0C25A8 7F08DA78 AC591200 */   sw    $t9, 0x1200($v0)
.L7F08DA7C:
/* 0C25AC 7F08DA7C 50200008 */  beql  $at, $zero, .L7F08DAA0
/* 0C25B0 7F08DA80 24840001 */   addiu $a0, $a0, 1
/* 0C25B4 7F08DA84 00603025 */  move  $a2, $v1
/* 0C25B8 7F08DA88 10000004 */  b     .L7F08DA9C
/* 0C25BC 7F08DA8C 00803825 */   move  $a3, $a0
.L7F08DA90:
/* 0C25C0 7F08DA90 00803825 */  move  $a3, $a0
/* 0C25C4 7F08DA94 10000005 */  b     .L7F08DAAC
/* 0C25C8 7F08DA98 2404000A */   li    $a0, 10
.L7F08DA9C:
/* 0C25CC 7F08DA9C 24840001 */  addiu $a0, $a0, 1
.L7F08DAA0:
/* 0C25D0 7F08DAA0 2881000A */  slti  $at, $a0, 0xa
/* 0C25D4 7F08DAA4 1420FFE8 */  bnez  $at, .L7F08DA48
/* 0C25D8 7F08DAA8 2442000C */   addiu $v0, $v0, 0xc
.L7F08DAAC:
/* 0C25DC 7F08DAAC 2401000A */  li    $at, 10
/* 0C25E0 7F08DAB0 14810010 */  bne   $a0, $at, .L7F08DAF4
/* 0C25E4 7F08DAB4 3C038008 */   lui   $v1, %hi(pPlayer)
/* 0C25E8 7F08DAB8 2463A0B0 */  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
/* 0C25EC 7F08DABC 8C690000 */  lw    $t1, ($v1)
/* 0C25F0 7F08DAC0 00071080 */  sll   $v0, $a3, 2
/* 0C25F4 7F08DAC4 3C088005 */  lui   $t0, %hi(clock_timer) 
/* 0C25F8 7F08DAC8 8D088374 */  lw    $t0, %lo(clock_timer)($t0)
/* 0C25FC 7F08DACC 00471023 */  subu  $v0, $v0, $a3
/* 0C2600 7F08DAD0 00021080 */  sll   $v0, $v0, 2
/* 0C2604 7F08DAD4 01225021 */  addu  $t2, $t1, $v0
/* 0C2608 7F08DAD8 AD481200 */  sw    $t0, 0x1200($t2)
/* 0C260C 7F08DADC 8C6B0000 */  lw    $t3, ($v1)
/* 0C2610 7F08DAE0 01626021 */  addu  $t4, $t3, $v0
/* 0C2614 7F08DAE4 AD9111F8 */  sw    $s1, 0x11f8($t4)
/* 0C2618 7F08DAE8 8C6D0000 */  lw    $t5, ($v1)
/* 0C261C 7F08DAEC 01A27021 */  addu  $t6, $t5, $v0
/* 0C2620 7F08DAF0 ADD011FC */  sw    $s0, 0x11fc($t6)
.L7F08DAF4:
/* 0C2624 7F08DAF4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C2628 7F08DAF8 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C262C 7F08DAFC 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C2630 7F08DB00 03E00008 */  jr    $ra
/* 0C2634 7F08DB04 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08DB08(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08DB08
/* 0C2638 7F08DB08 AC800000 */  sw    $zero, ($a0)
/* 0C263C 7F08DB0C 3C088008 */  lui   $t0, %hi(pPlayer) 
/* 0C2640 7F08DB10 2402FFFF */  li    $v0, -1
/* 0C2644 7F08DB14 ACA00000 */  sw    $zero, ($a1)
/* 0C2648 7F08DB18 2508A0B0 */  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
/* 0C264C 7F08DB1C 00003025 */  move  $a2, $zero
/* 0C2650 7F08DB20 24090078 */  li    $t1, 120
/* 0C2654 7F08DB24 8D0E0000 */  lw    $t6, ($t0)
.L7F08DB28:
/* 0C2658 7F08DB28 01C61821 */  addu  $v1, $t6, $a2
/* 0C265C 7F08DB2C 8C671200 */  lw    $a3, 0x1200($v1)
/* 0C2660 7F08DB30 04E0000C */  bltz  $a3, .L7F08DB64
/* 0C2664 7F08DB34 0047082A */   slt   $at, $v0, $a3
/* 0C2668 7F08DB38 5020000B */  beql  $at, $zero, .L7F08DB68
/* 0C266C 7F08DB3C 8C67120C */   lw    $a3, 0x120c($v1)
/* 0C2670 7F08DB40 8C6F11F8 */  lw    $t7, 0x11f8($v1)
/* 0C2674 7F08DB44 00E01025 */  move  $v0, $a3
/* 0C2678 7F08DB48 AC8F0000 */  sw    $t7, ($a0)
/* 0C267C 7F08DB4C 8D180000 */  lw    $t8, ($t0)
/* 0C2680 7F08DB50 0306C821 */  addu  $t9, $t8, $a2
/* 0C2684 7F08DB54 8F2A11FC */  lw    $t2, 0x11fc($t9)
/* 0C2688 7F08DB58 ACAA0000 */  sw    $t2, ($a1)
/* 0C268C 7F08DB5C 8D0B0000 */  lw    $t3, ($t0)
/* 0C2690 7F08DB60 01661821 */  addu  $v1, $t3, $a2
.L7F08DB64:
/* 0C2694 7F08DB64 8C67120C */  lw    $a3, 0x120c($v1)
.L7F08DB68:
/* 0C2698 7F08DB68 04E0000A */  bltz  $a3, .L7F08DB94
/* 0C269C 7F08DB6C 0047082A */   slt   $at, $v0, $a3
/* 0C26A0 7F08DB70 50200009 */  beql  $at, $zero, .L7F08DB98
/* 0C26A4 7F08DB74 24C60018 */   addiu $a2, $a2, 0x18
/* 0C26A8 7F08DB78 8C6C1204 */  lw    $t4, 0x1204($v1)
/* 0C26AC 7F08DB7C 00E01025 */  move  $v0, $a3
/* 0C26B0 7F08DB80 AC8C0000 */  sw    $t4, ($a0)
/* 0C26B4 7F08DB84 8D0D0000 */  lw    $t5, ($t0)
/* 0C26B8 7F08DB88 01A67021 */  addu  $t6, $t5, $a2
/* 0C26BC 7F08DB8C 8DCF1208 */  lw    $t7, 0x1208($t6)
/* 0C26C0 7F08DB90 ACAF0000 */  sw    $t7, ($a1)
.L7F08DB94:
/* 0C26C4 7F08DB94 24C60018 */  addiu $a2, $a2, 0x18
.L7F08DB98:
/* 0C26C8 7F08DB98 54C9FFE3 */  bnel  $a2, $t1, .L7F08DB28
/* 0C26CC 7F08DB9C 8D0E0000 */   lw    $t6, ($t0)
/* 0C26D0 7F08DBA0 03E00008 */  jr    $ra
/* 0C26D4 7F08DBA4 00000000 */   nop   
)
#endif



