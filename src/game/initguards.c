#include "ultra64.h"
#include "game/chr.h"

void init_guards(void) {
    animation_rate = 1.0f;
    D_8002C904 = 0;
    D_8002C908 = 0;
    D_8002C90C = 0;
    D_8002C910 = 0;
    D_8002CC58 = 0;
    show_patrols_flag = 0;
    player1_guardID = 0x1388;
    ptr_guard_data = 0;
    num_guards = 0;
    init_obj_register_difficulty_vals();
}



#ifdef NONMATCHING
void alloc_init_GUARDdata_entries(void) {

}
#else
GLOBAL_ASM(
.text
glabel alloc_init_GUARDdata_entries
/* 0359E8 7F000EB8 248E000A */  addiu $t6, $a0, 0xa
/* 0359EC 7F000EBC 000E7900 */  sll   $t7, $t6, 4
/* 0359F0 7F000EC0 01EE7823 */  subu  $t7, $t7, $t6
/* 0359F4 7F000EC4 000F78C0 */  sll   $t7, $t7, 3
/* 0359F8 7F000EC8 01EE7823 */  subu  $t7, $t7, $t6
/* 0359FC 7F000ECC 000F7880 */  sll   $t7, $t7, 2
/* 035A00 7F000ED0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 035A04 7F000ED4 3C068003 */  lui   $a2, %hi(num_guards)
/* 035A08 7F000ED8 25E4000F */  addiu $a0, $t7, 0xf
/* 035A0C 7F000EDC 24C6CC68 */  addiu $a2, %lo(num_guards) # addiu $a2, $a2, -0x3398
/* 035A10 7F000EE0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 035A14 7F000EE4 3498000F */  ori   $t8, $a0, 0xf
/* 035A18 7F000EE8 ACCE0000 */  sw    $t6, ($a2)
/* 035A1C 7F000EEC 3B04000F */  xori  $a0, $t8, 0xf
/* 035A20 7F000EF0 0C0025C8 */  jal   allocate_bytes_in_bank
/* 035A24 7F000EF4 24050004 */   li    $a1, 4
/* 035A28 7F000EF8 3C068003 */  lui   $a2, %hi(num_guards)
/* 035A2C 7F000EFC 24C6CC68 */  addiu $a2, %lo(num_guards) # addiu $a2, $a2, -0x3398
/* 035A30 7F000F00 8CC80000 */  lw    $t0, ($a2)
/* 035A34 7F000F04 3C048003 */  lui   $a0, %hi(ptr_guard_data)
/* 035A38 7F000F08 2484CC64 */  addiu $a0, %lo(ptr_guard_data) # addiu $a0, $a0, -0x339c
/* 035A3C 7F000F0C AC820000 */  sw    $v0, ($a0)
/* 035A40 7F000F10 1900000B */  blez  $t0, .L7F000F40
/* 035A44 7F000F14 00001825 */   move  $v1, $zero
/* 035A48 7F000F18 00001025 */  move  $v0, $zero
/* 035A4C 7F000F1C 8C890000 */  lw    $t1, ($a0)
.L7F000F20:
/* 035A50 7F000F20 24630001 */  addiu $v1, $v1, 1
/* 035A54 7F000F24 01225021 */  addu  $t2, $t1, $v0
/* 035A58 7F000F28 AD40001C */  sw    $zero, 0x1c($t2)
/* 035A5C 7F000F2C 8CCB0000 */  lw    $t3, ($a2)
/* 035A60 7F000F30 244201DC */  addiu $v0, $v0, 0x1dc
/* 035A64 7F000F34 006B082A */  slt   $at, $v1, $t3
/* 035A68 7F000F38 5420FFF9 */  bnezl $at, .L7F000F20
/* 035A6C 7F000F3C 8C890000 */   lw    $t1, ($a0)
.L7F000F40:
/* 035A70 7F000F40 8FBF0014 */  lw    $ra, 0x14($sp)
/* 035A74 7F000F44 27BD0018 */  addiu $sp, $sp, 0x18
/* 035A78 7F000F48 03E00008 */  jr    $ra
/* 035A7C 7F000F4C 00000000 */   nop   
)
#endif


#ifdef NONMATCHING
void set_new_rand_head_bodies(void) {

}
#else
GLOBAL_ASM(
.text
glabel set_new_rand_head_bodies
/* 035A80 7F000F50 3C0E8004 */  lui   $t6, %hi(c_item_entries) 
/* 035A84 7F000F54 8DCEDE10 */  lw    $t6, %lo(c_item_entries)($t6)
/* 035A88 7F000F58 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 035A8C 7F000F5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 035A90 7F000F60 11C00009 */  beqz  $t6, .L7F000F88
/* 035A94 7F000F64 AFA40018 */   sw    $a0, 0x18($sp)
/* 035A98 7F000F68 3C0F8004 */  lui   $t7, %hi(c_item_entries)
/* 035A9C 7F000F6C 25E2DE10 */  addiu $v0, $t7, %lo(c_item_entries)
/* 035AA0 7F000F70 8C430000 */  lw    $v1, ($v0)
/* 035AA4 7F000F74 AC600000 */  sw    $zero, ($v1)
.L7F000F78:
/* 035AA8 7F000F78 8C430014 */  lw    $v1, 0x14($v0)
/* 035AAC 7F000F7C 24420014 */  addiu $v0, $v0, 0x14
/* 035AB0 7F000F80 5460FFFD */  bnezl $v1, .L7F000F78
/* 035AB4 7F000F84 AC600000 */   sw    $zero, ($v1)
.L7F000F88:
/* 035AB8 7F000F88 0C002914 */  jal   get_random_value
/* 035ABC 7F000F8C 00000000 */   nop   
/* 035AC0 7F000F90 3C188003 */  lui   $t8, %hi(num_male_heads) 
/* 035AC4 7F000F94 8F18CD04 */  lw    $t8, %lo(num_male_heads)($t8)
/* 035AC8 7F000F98 3C018003 */  lui   $at, %hi(current_random_male_head)
/* 035ACC 7F000F9C 0058001B */  divu  $zero, $v0, $t8
/* 035AD0 7F000FA0 0000C810 */  mfhi  $t9
/* 035AD4 7F000FA4 AC39CE38 */  sw    $t9, %lo(current_random_male_head)($at)
/* 035AD8 7F000FA8 17000002 */  bnez  $t8, .L7F000FB4
/* 035ADC 7F000FAC 00000000 */   nop   
/* 035AE0 7F000FB0 0007000D */  break 7
.L7F000FB4:
/* 035AE4 7F000FB4 0C002914 */  jal   get_random_value
/* 035AE8 7F000FB8 00000000 */   nop   
/* 035AEC 7F000FBC 3C088003 */  lui   $t0, %hi(num_female_heads) 
/* 035AF0 7F000FC0 8D08CD08 */  lw    $t0, %lo(num_female_heads)($t0)
/* 035AF4 7F000FC4 3C018003 */  lui   $at, %hi(current_random_female_head)
/* 035AF8 7F000FC8 0048001B */  divu  $zero, $v0, $t0
/* 035AFC 7F000FCC 00004810 */  mfhi  $t1
/* 035B00 7F000FD0 AC29CE3C */  sw    $t1, %lo(current_random_female_head)($at)
/* 035B04 7F000FD4 15000002 */  bnez  $t0, .L7F000FE0
/* 035B08 7F000FD8 00000000 */   nop   
/* 035B0C 7F000FDC 0007000D */  break 7
.L7F000FE0:
/* 035B10 7F000FE0 0C002914 */  jal   get_random_value
/* 035B14 7F000FE4 00000000 */   nop   
/* 035B18 7F000FE8 3C0A8003 */  lui   $t2, %hi(num_bodies) 
/* 035B1C 7F000FEC 8D4ACD00 */  lw    $t2, %lo(num_bodies)($t2)
/* 035B20 7F000FF0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 035B24 7F000FF4 3C018003 */  lui   $at, %hi(current_random_body)
/* 035B28 7F000FF8 004A001B */  divu  $zero, $v0, $t2
/* 035B2C 7F000FFC 00005810 */  mfhi  $t3
/* 035B30 7F001000 AC2BCE34 */  sw    $t3, %lo(current_random_body)($at)
/* 035B34 7F001004 15400002 */  bnez  $t2, .L7F001010
/* 035B38 7F001008 00000000 */   nop   
/* 035B3C 7F00100C 0007000D */  break 7
.L7F001010:
/* 035B40 7F001010 27BD0018 */  addiu $sp, $sp, 0x18
/* 035B44 7F001014 03E00008 */  jr    $ra
/* 035B48 7F001018 00000000 */   nop
)
#endif

