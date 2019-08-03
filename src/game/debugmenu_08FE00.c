#include "ultra64.h"


// data
//D:80036B70
s32 highlighted_debug_option = 0;
//D:80036B74
s32 ptr_last_debuggrp_cutoff = 0;
//D:80036B78
s32 ptr_textptrs = 0;
//D:80036B7C
s32 ptr_positions = 0;
//D:80036B80
s32 number_groups = 0;
//D:80036B84
s32 ptr_groupings = 0;
//D:80036B88
s32 num_mcm_something = 2;
//D:80036B8C
u32 mcm_xoffset_multiplier = 0x4040400;
//D:80036B90
u32 mcm_yoffset_multiplier = 0x7070700;
/*
D:80036B94                     .word 0
D:80036B98                     .word 0
D:80036B9C                     .word 0
*/

// rodata
//D:80055340
const char aMenu_cErrorTriedToCallFont_makegt[] = "menu.c: ERROR! Tried to call font_makegt\n";




void nullsub_32(void) {
    return;
}

void sub_GAME_7F08FE08(s32 param_1) {
  num_mcm_something = param_1;
}





#ifdef NONMATCHING
void init_debug_menu_values(void) {

}
#else
GLOBAL_ASM(
.text
glabel init_debug_menu_values
/* 0C4944 7F08FE14 3C018003 */  lui   $at, %hi(ptr_textptrs) # $at, 0x8003
/* 0C4948 7F08FE18 AC246B78 */  sw    $a0, %lo(ptr_textptrs)($at)
/* 0C494C 7F08FE1C 3C018003 */  lui   $at, %hi(ptr_positions) # $at, 0x8003
/* 0C4950 7F08FE20 AC256B7C */  sw    $a1, %lo(ptr_positions)($at)
/* 0C4954 7F08FE24 3C018003 */  lui   $at, %hi(ptr_groupings) # $at, 0x8003
/* 0C4958 7F08FE28 AC266B84 */  sw    $a2, %lo(ptr_groupings)($at)
/* 0C495C 7F08FE2C 8CCE0000 */  lw    $t6, ($a2)
/* 0C4960 7F08FE30 00001025 */  move  $v0, $zero
/* 0C4964 7F08FE34 00C01825 */  move  $v1, $a2
/* 0C4968 7F08FE38 05C20007 */  bltzl $t6, .L7F08FE58
/* 0C496C 7F08FE3C 0002C080 */   sll   $t8, $v0, 2
/* 0C4970 7F08FE40 8C6F0004 */  lw    $t7, 4($v1)
.L7F08FE44:
/* 0C4974 7F08FE44 24420001 */  addiu $v0, $v0, 1
/* 0C4978 7F08FE48 24630004 */  addiu $v1, $v1, 4
/* 0C497C 7F08FE4C 05E3FFFD */  bgezl $t7, .L7F08FE44
/* 0C4980 7F08FE50 8C6F0004 */   lw    $t7, 4($v1)
/* 0C4984 7F08FE54 0002C080 */  sll   $t8, $v0, 2
.L7F08FE58:
/* 0C4988 7F08FE58 00D8C821 */  addu  $t9, $a2, $t8
/* 0C498C 7F08FE5C 8F28FFFC */  lw    $t0, -4($t9)
/* 0C4990 7F08FE60 3C018003 */  lui   $at, %hi(ptr_last_debuggrp_cutoff) # $at, 0x8003
/* 0C4994 7F08FE64 AC286B74 */  sw    $t0, %lo(ptr_last_debuggrp_cutoff)($at)
/* 0C4998 7F08FE68 3C018003 */  lui   $at, %hi(number_groups)
/* 0C499C 7F08FE6C 03E00008 */  jr    $ra
/* 0C49A0 7F08FE70 AC226B80 */   sw    $v0, %lo(number_groups)($at)
)
#endif





#ifdef NONMATCHING
void print_debug_mcm_to_stdout(void) {

}
#else
GLOBAL_ASM(
.text
glabel print_debug_mcm_to_stdout
/* 0C49A4 7F08FE74 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0C49A8 7F08FE78 3C028003 */  lui   $v0, %hi(num_mcm_something) # $v0, 0x8003
/* 0C49AC 7F08FE7C 8C426B88 */  lw    $v0, %lo(num_mcm_something)($v0)
/* 0C49B0 7F08FE80 3C0E8003 */  lui   $t6, %hi(ptr_last_debuggrp_cutoff) # $t6, 0x8003
/* 0C49B4 7F08FE84 8DCE6B74 */  lw    $t6, %lo(ptr_last_debuggrp_cutoff)($t6)
/* 0C49B8 7F08FE88 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0C49BC 7F08FE8C AFB70034 */  sw    $s7, 0x34($sp)
/* 0C49C0 7F08FE90 3C178003 */  lui   $s7, %hi(mcm_xoffset_multiplier)
/* 0C49C4 7F08FE94 3C1E8003 */  lui   $fp, %hi(mcm_yoffset_multiplier)
/* 0C49C8 7F08FE98 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C49CC 7F08FE9C 02E2B821 */  addu  $s7, $s7, $v0
/* 0C49D0 7F08FEA0 03C2F021 */  addu  $fp, $fp, $v0
/* 0C49D4 7F08FEA4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0C49D8 7F08FEA8 AFB60030 */  sw    $s6, 0x30($sp)
/* 0C49DC 7F08FEAC AFB5002C */  sw    $s5, 0x2c($sp)
/* 0C49E0 7F08FEB0 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C49E4 7F08FEB4 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C49E8 7F08FEB8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C49EC 7F08FEBC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C49F0 7F08FEC0 AFA40040 */  sw    $a0, 0x40($sp)
/* 0C49F4 7F08FEC4 92F76B8C */  lbu   $s7, %lo(mcm_xoffset_multiplier)($s7)
/* 0C49F8 7F08FEC8 93DE6B90 */  lbu   $fp, %lo(mcm_yoffset_multiplier)($fp)
/* 0C49FC 7F08FECC 19C00042 */  blez  $t6, .L7F08FFD8
/* 0C4A00 7F08FED0 00008025 */   move  $s0, $zero
/* 0C4A04 7F08FED4 3C168003 */  lui   $s6, %hi(ptr_textptrs) # $s6, 0x8003
/* 0C4A08 7F08FED8 3C148003 */  lui   $s4, %hi(ptr_positions) # $s4, 0x8003
/* 0C4A0C 7F08FEDC 3C138003 */  lui   $s3, %hi(highlighted_debug_option) # $s3, 0x8003
/* 0C4A10 7F08FEE0 26736B70 */  addiu $s3, %lo(highlighted_debug_option) # addiu $s3, $s3, 0x6b70
/* 0C4A14 7F08FEE4 26946B7C */  addiu $s4, %lo(ptr_positions) # addiu $s4, $s4, 0x6b7c
/* 0C4A18 7F08FEE8 26D66B78 */  addiu $s6, %lo(ptr_textptrs) # addiu $s6, $s6, 0x6b78
/* 0C4A1C 7F08FEEC 00008825 */  move  $s1, $zero
/* 0C4A20 7F08FEF0 00009025 */  move  $s2, $zero
/* 0C4A24 7F08FEF4 24150007 */  li    $s5, 7
.L7F08FEF8:
/* 0C4A28 7F08FEF8 0FC23F80 */  jal   nullsub_32
/* 0C4A2C 7F08FEFC 00000000 */   nop   
/* 0C4A30 7F08FF00 8E6F0000 */  lw    $t7, ($s3)
/* 0C4A34 7F08FF04 240400C0 */  li    $a0, 192
/* 0C4A38 7F08FF08 240500C0 */  li    $a1, 192
/* 0C4A3C 7F08FF0C 160F0008 */  bne   $s0, $t7, .L7F08FF30
/* 0C4A40 7F08FF10 240600C0 */   li    $a2, 192
/* 0C4A44 7F08FF14 240400C0 */  li    $a0, 192
/* 0C4A48 7F08FF18 00002825 */  move  $a1, $zero
/* 0C4A4C 7F08FF1C 00003025 */  move  $a2, $zero
/* 0C4A50 7F08FF20 0C002C1B */  jal   set_debug_text_color
/* 0C4A54 7F08FF24 240700C0 */   li    $a3, 192
/* 0C4A58 7F08FF28 10000004 */  b     .L7F08FF3C
/* 0C4A5C 7F08FF2C 8E980000 */   lw    $t8, ($s4)
.L7F08FF30:
/* 0C4A60 7F08FF30 0C002C1B */  jal   set_debug_text_color
/* 0C4A64 7F08FF34 240700C0 */   li    $a3, 192
/* 0C4A68 7F08FF38 8E980000 */  lw    $t8, ($s4)
.L7F08FF3C:
/* 0C4A6C 7F08FF3C 03111021 */  addu  $v0, $t8, $s1
/* 0C4A70 7F08FF40 8C590000 */  lw    $t9, ($v0)
/* 0C4A74 7F08FF44 8C490004 */  lw    $t1, 4($v0)
/* 0C4A78 7F08FF48 03370019 */  multu $t9, $s7
/* 0C4A7C 7F08FF4C 00002012 */  mflo  $a0
/* 0C4A80 7F08FF50 2484FFEC */  addiu $a0, $a0, -0x14
/* 0C4A84 7F08FF54 04810003 */  bgez  $a0, .L7F08FF64
/* 0C4A88 7F08FF58 00044083 */   sra   $t0, $a0, 2
/* 0C4A8C 7F08FF5C 24810003 */  addiu $at, $a0, 3
/* 0C4A90 7F08FF60 00014083 */  sra   $t0, $at, 2
.L7F08FF64:
/* 0C4A94 7F08FF64 013E0019 */  multu $t1, $fp
/* 0C4A98 7F08FF68 01002025 */  move  $a0, $t0
/* 0C4A9C 7F08FF6C 00005012 */  mflo  $t2
/* 0C4AA0 7F08FF70 254BFFF8 */  addiu $t3, $t2, -8
/* 0C4AA4 7F08FF74 00000000 */  nop   
/* 0C4AA8 7F08FF78 0175001A */  div   $zero, $t3, $s5
/* 0C4AAC 7F08FF7C 00002812 */  mflo  $a1
/* 0C4AB0 7F08FF80 16A00002 */  bnez  $s5, .L7F08FF8C
/* 0C4AB4 7F08FF84 00000000 */   nop   
/* 0C4AB8 7F08FF88 0007000D */  break 7
.L7F08FF8C:
/* 0C4ABC 7F08FF8C 2401FFFF */  li    $at, -1
/* 0C4AC0 7F08FF90 16A10004 */  bne   $s5, $at, .L7F08FFA4
/* 0C4AC4 7F08FF94 3C018000 */   lui   $at, 0x8000
/* 0C4AC8 7F08FF98 15610002 */  bne   $t3, $at, .L7F08FFA4
/* 0C4ACC 7F08FF9C 00000000 */   nop   
/* 0C4AD0 7F08FFA0 0006000D */  break 6
.L7F08FFA4:
/* 0C4AD4 7F08FFA4 0C002C10 */  jal   set_final_debug_text_positions
/* 0C4AD8 7F08FFA8 00000000 */   nop   
/* 0C4ADC 7F08FFAC 8ECC0000 */  lw    $t4, ($s6)
/* 0C4AE0 7F08FFB0 01926821 */  addu  $t5, $t4, $s2
/* 0C4AE4 7F08FFB4 0C002C7A */  jal   write_string_stdout
/* 0C4AE8 7F08FFB8 8DA40000 */   lw    $a0, ($t5)
/* 0C4AEC 7F08FFBC 3C0E8003 */  lui   $t6, %hi(ptr_last_debuggrp_cutoff) # $t6, 0x8003
/* 0C4AF0 7F08FFC0 8DCE6B74 */  lw    $t6, %lo(ptr_last_debuggrp_cutoff)($t6)
/* 0C4AF4 7F08FFC4 26100001 */  addiu $s0, $s0, 1
/* 0C4AF8 7F08FFC8 26310008 */  addiu $s1, $s1, 8
/* 0C4AFC 7F08FFCC 020E082A */  slt   $at, $s0, $t6
/* 0C4B00 7F08FFD0 1420FFC9 */  bnez  $at, .L7F08FEF8
/* 0C4B04 7F08FFD4 26520004 */   addiu $s2, $s2, 4
.L7F08FFD8:
/* 0C4B08 7F08FFD8 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0C4B0C 7F08FFDC 8FA20040 */  lw    $v0, 0x40($sp)
/* 0C4B10 7F08FFE0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C4B14 7F08FFE4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C4B18 7F08FFE8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C4B1C 7F08FFEC 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C4B20 7F08FFF0 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C4B24 7F08FFF4 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0C4B28 7F08FFF8 8FB60030 */  lw    $s6, 0x30($sp)
/* 0C4B2C 7F08FFFC 8FB70034 */  lw    $s7, 0x34($sp)
/* 0C4B30 7F090000 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0C4B34 7F090004 03E00008 */  jr    $ra
/* 0C4B38 7F090008 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09000C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09000C
/* 0C4B3C 7F09000C 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0C4B40 7F090010 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0C4B44 7F090014 3C028003 */  lui   $v0, %hi(num_mcm_something) # $v0, 0x8003
/* 0C4B48 7F090018 8C426B88 */  lw    $v0, %lo(num_mcm_something)($v0)
/* 0C4B4C 7F09001C 3C158003 */  lui   $s5, %hi(ptr_last_debuggrp_cutoff) # $s5, 0x8003
/* 0C4B50 7F090020 26B56B74 */  addiu $s5, %lo(ptr_last_debuggrp_cutoff) # addiu $s5, $s5, 0x6b74
/* 0C4B54 7F090024 8EAE0000 */  lw    $t6, ($s5)
/* 0C4B58 7F090028 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C4B5C 7F09002C AFB30024 */  sw    $s3, 0x24($sp)
/* 0C4B60 7F090030 3C138003 */  lui   $s3, %hi(mcm_xoffset_multiplier)
/* 0C4B64 7F090034 3C148003 */  lui   $s4, %hi(mcm_yoffset_multiplier)
/* 0C4B68 7F090038 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C4B6C 7F09003C 02629821 */  addu  $s3, $s3, $v0
/* 0C4B70 7F090040 0282A021 */  addu  $s4, $s4, $v0
/* 0C4B74 7F090044 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0C4B78 7F090048 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0C4B7C 7F09004C AFB70034 */  sw    $s7, 0x34($sp)
/* 0C4B80 7F090050 AFB60030 */  sw    $s6, 0x30($sp)
/* 0C4B84 7F090054 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C4B88 7F090058 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C4B8C 7F09005C AFA40040 */  sw    $a0, 0x40($sp)
/* 0C4B90 7F090060 AFA50044 */  sw    $a1, 0x44($sp)
/* 0C4B94 7F090064 AFA60048 */  sw    $a2, 0x48($sp)
/* 0C4B98 7F090068 92736B8C */  lbu   $s3, %lo(mcm_xoffset_multiplier)($s3)
/* 0C4B9C 7F09006C 92946B90 */  lbu   $s4, %lo(mcm_yoffset_multiplier)($s4)
/* 0C4BA0 7F090070 19C00043 */  blez  $t6, .L7F090180
/* 0C4BA4 7F090074 00008025 */   move  $s0, $zero
/* 0C4BA8 7F090078 3C178003 */  lui   $s7, %hi(ptr_positions) # $s7, 0x8003
/* 0C4BAC 7F09007C 3C168003 */  lui   $s6, %hi(highlighted_debug_option) # $s6, 0x8003
/* 0C4BB0 7F090080 26D66B70 */  addiu $s6, %lo(highlighted_debug_option) # addiu $s6, $s6, 0x6b70
/* 0C4BB4 7F090084 26F76B7C */  addiu $s7, %lo(ptr_positions) # addiu $s7, $s7, 0x6b7c
/* 0C4BB8 7F090088 00008825 */  move  $s1, $zero
/* 0C4BBC 7F09008C 00009025 */  move  $s2, $zero
/* 0C4BC0 7F090090 241E0007 */  li    $fp, 7
.L7F090094:
/* 0C4BC4 7F090094 0FC23F80 */  jal   nullsub_32
/* 0C4BC8 7F090098 00000000 */   nop   
/* 0C4BCC 7F09009C 8ECF0000 */  lw    $t7, ($s6)
/* 0C4BD0 7F0900A0 240400C0 */  li    $a0, 192
/* 0C4BD4 7F0900A4 240500C0 */  li    $a1, 192
/* 0C4BD8 7F0900A8 160F0008 */  bne   $s0, $t7, .L7F0900CC
/* 0C4BDC 7F0900AC 240600C0 */   li    $a2, 192
/* 0C4BE0 7F0900B0 240400C0 */  li    $a0, 192
/* 0C4BE4 7F0900B4 00002825 */  move  $a1, $zero
/* 0C4BE8 7F0900B8 00003025 */  move  $a2, $zero
/* 0C4BEC 7F0900BC 0C002C1B */  jal   set_debug_text_color
/* 0C4BF0 7F0900C0 240700C0 */   li    $a3, 192
/* 0C4BF4 7F0900C4 10000004 */  b     .L7F0900D8
/* 0C4BF8 7F0900C8 8EF80000 */   lw    $t8, ($s7)
.L7F0900CC:
/* 0C4BFC 7F0900CC 0C002C1B */  jal   set_debug_text_color
/* 0C4C00 7F0900D0 240700C0 */   li    $a3, 192
/* 0C4C04 7F0900D4 8EF80000 */  lw    $t8, ($s7)
.L7F0900D8:
/* 0C4C08 7F0900D8 03111021 */  addu  $v0, $t8, $s1
/* 0C4C0C 7F0900DC 8C590000 */  lw    $t9, ($v0)
/* 0C4C10 7F0900E0 8C490004 */  lw    $t1, 4($v0)
/* 0C4C14 7F0900E4 03330019 */  multu $t9, $s3
/* 0C4C18 7F0900E8 00002012 */  mflo  $a0
/* 0C4C1C 7F0900EC 2484FFEC */  addiu $a0, $a0, -0x14
/* 0C4C20 7F0900F0 04810003 */  bgez  $a0, .L7F090100
/* 0C4C24 7F0900F4 00044083 */   sra   $t0, $a0, 2
/* 0C4C28 7F0900F8 24810003 */  addiu $at, $a0, 3
/* 0C4C2C 7F0900FC 00014083 */  sra   $t0, $at, 2
.L7F090100:
/* 0C4C30 7F090100 01340019 */  multu $t1, $s4
/* 0C4C34 7F090104 01002025 */  move  $a0, $t0
/* 0C4C38 7F090108 00005012 */  mflo  $t2
/* 0C4C3C 7F09010C 254BFFF8 */  addiu $t3, $t2, -8
/* 0C4C40 7F090110 00000000 */  nop   
/* 0C4C44 7F090114 017E001A */  div   $zero, $t3, $fp
/* 0C4C48 7F090118 00002812 */  mflo  $a1
/* 0C4C4C 7F09011C 17C00002 */  bnez  $fp, .L7F090128
/* 0C4C50 7F090120 00000000 */   nop   
/* 0C4C54 7F090124 0007000D */  break 7
.L7F090128:
/* 0C4C58 7F090128 2401FFFF */  li    $at, -1
/* 0C4C5C 7F09012C 17C10004 */  bne   $fp, $at, .L7F090140
/* 0C4C60 7F090130 3C018000 */   lui   $at, 0x8000
/* 0C4C64 7F090134 15610002 */  bne   $t3, $at, .L7F090140
/* 0C4C68 7F090138 00000000 */   nop   
/* 0C4C6C 7F09013C 0006000D */  break 6
.L7F090140:
/* 0C4C70 7F090140 0C002C10 */  jal   set_final_debug_text_positions
/* 0C4C74 7F090144 00000000 */   nop   
/* 0C4C78 7F090148 3C0C8003 */  lui   $t4, %hi(ptr_textptrs) # $t4, 0x8003
/* 0C4C7C 7F09014C 8D8C6B78 */  lw    $t4, %lo(ptr_textptrs)($t4)
/* 0C4C80 7F090150 01926821 */  addu  $t5, $t4, $s2
/* 0C4C84 7F090154 0C002C7A */  jal   write_string_stdout
/* 0C4C88 7F090158 8DA40000 */   lw    $a0, ($t5)
/* 0C4C8C 7F09015C 3C048005 */  lui   $a0, %hi(aMenu_cErrorTriedToCallFont_makegt) # $a0, 0x8005
/* 0C4C90 7F090160 0C0033D1 */  jal   osSyncPrintf
/* 0C4C94 7F090164 24845340 */   addiu $a0, %lo(aMenu_cErrorTriedToCallFont_makegt) # addiu $a0, $a0, 0x5340
/* 0C4C98 7F090168 8EAE0000 */  lw    $t6, ($s5)
/* 0C4C9C 7F09016C 26100001 */  addiu $s0, $s0, 1
/* 0C4CA0 7F090170 26310008 */  addiu $s1, $s1, 8
/* 0C4CA4 7F090174 020E082A */  slt   $at, $s0, $t6
/* 0C4CA8 7F090178 1420FFC6 */  bnez  $at, .L7F090094
/* 0C4CAC 7F09017C 26520004 */   addiu $s2, $s2, 4
.L7F090180:
/* 0C4CB0 7F090180 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0C4CB4 7F090184 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C4CB8 7F090188 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C4CBC 7F09018C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C4CC0 7F090190 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C4CC4 7F090194 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C4CC8 7F090198 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0C4CCC 7F09019C 8FB60030 */  lw    $s6, 0x30($sp)
/* 0C4CD0 7F0901A0 8FB70034 */  lw    $s7, 0x34($sp)
/* 0C4CD4 7F0901A4 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0C4CD8 7F0901A8 03E00008 */  jr    $ra
/* 0C4CDC 7F0901AC 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif




s32 get_highlighted_debug_option(void) {
    return highlighted_debug_option;
}

void sub_GAME_7F0901BC(s32 value) {
    highlighted_debug_option = value;
}






#ifdef NONMATCHING
void sub_GAME_7F0901C8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0901C8
/* 0C4CF8 7F0901C8 3C068003 */  lui   $a2, %hi(highlighted_debug_option) # $a2, 0x8003
/* 0C4CFC 7F0901CC 24C66B70 */  addiu $a2, %lo(highlighted_debug_option) # addiu $a2, $a2, 0x6b70
/* 0C4D00 7F0901D0 8CCE0000 */  lw    $t6, ($a2)
/* 0C4D04 7F0901D4 3C188003 */  lui   $t8, %hi(ptr_groupings) # $t8, 0x8003
/* 0C4D08 7F0901D8 3C048003 */  lui   $a0, %hi(number_groups)
/* 0C4D0C 7F0901DC 25C2FFFF */  addiu $v0, $t6, -1
/* 0C4D10 7F0901E0 04410006 */  bgez  $v0, .L7F0901FC
/* 0C4D14 7F0901E4 ACC20000 */   sw    $v0, ($a2)
/* 0C4D18 7F0901E8 8F186B84 */  lw    $t8, %lo(ptr_groupings)($t8)
/* 0C4D1C 7F0901EC 8F190000 */  lw    $t9, ($t8)
/* 0C4D20 7F0901F0 2728FFFF */  addiu $t0, $t9, -1
/* 0C4D24 7F0901F4 03E00008 */  jr    $ra
/* 0C4D28 7F0901F8 ACC80000 */   sw    $t0, ($a2)

.L7F0901FC:
/* 0C4D2C 7F0901FC 8C846B80 */  lw    $a0, %lo(number_groups)($a0)
/* 0C4D30 7F090200 00001825 */  move  $v1, $zero
/* 0C4D34 7F090204 3C058003 */  lui   $a1, %hi(ptr_groupings) # $a1, 0x8003
/* 0C4D38 7F090208 1880000D */  blez  $a0, .L7F090240
/* 0C4D3C 7F09020C 00000000 */   nop   
/* 0C4D40 7F090210 8CA56B84 */  lw    $a1, %lo(ptr_groupings)($a1)
.L7F090214:
/* 0C4D44 7F090214 8CAA0000 */  lw    $t2, ($a1)
/* 0C4D48 7F090218 24630001 */  addiu $v1, $v1, 1
/* 0C4D4C 7F09021C 24490001 */  addiu $t1, $v0, 1
/* 0C4D50 7F090220 152A0005 */  bne   $t1, $t2, .L7F090238
/* 0C4D54 7F090224 0064082A */   slt   $at, $v1, $a0
/* 0C4D58 7F090228 8CAB0004 */  lw    $t3, 4($a1)
/* 0C4D5C 7F09022C 256CFFFF */  addiu $t4, $t3, -1
/* 0C4D60 7F090230 03E00008 */  jr    $ra
/* 0C4D64 7F090234 ACCC0000 */   sw    $t4, ($a2)

.L7F090238:
/* 0C4D68 7F090238 1420FFF6 */  bnez  $at, .L7F090214
/* 0C4D6C 7F09023C 24A50004 */   addiu $a1, $a1, 4
.L7F090240:
/* 0C4D70 7F090240 03E00008 */  jr    $ra
/* 0C4D74 7F090244 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F090248(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F090248
/* 0C4D78 7F090248 3C078003 */  lui   $a3, %hi(highlighted_debug_option) # $a3, 0x8003
/* 0C4D7C 7F09024C 24E76B70 */  addiu $a3, %lo(highlighted_debug_option) # addiu $a3, $a3, 0x6b70
/* 0C4D80 7F090250 8CEE0000 */  lw    $t6, ($a3)
/* 0C4D84 7F090254 3C038003 */  lui   $v1, %hi(ptr_groupings) # $v1, 0x8003
/* 0C4D88 7F090258 3C058003 */  lui   $a1, %hi(number_groups)
/* 0C4D8C 7F09025C 25C20001 */  addiu $v0, $t6, 1
/* 0C4D90 7F090260 ACE20000 */  sw    $v0, ($a3)
/* 0C4D94 7F090264 8C636B84 */  lw    $v1, %lo(ptr_groupings)($v1)
/* 0C4D98 7F090268 8C780000 */  lw    $t8, ($v1)
/* 0C4D9C 7F09026C 14580003 */  bne   $v0, $t8, .L7F09027C
/* 0C4DA0 7F090270 00000000 */   nop   
/* 0C4DA4 7F090274 03E00008 */  jr    $ra
/* 0C4DA8 7F090278 ACE00000 */   sw    $zero, ($a3)

.L7F09027C:
/* 0C4DAC 7F09027C 8CA56B80 */  lw    $a1, %lo(number_groups)($a1)
/* 0C4DB0 7F090280 00002025 */  move  $a0, $zero
/* 0C4DB4 7F090284 00603025 */  move  $a2, $v1
/* 0C4DB8 7F090288 18A0000B */  blez  $a1, .L7F0902B8
/* 0C4DBC 7F09028C 00000000 */   nop   
.L7F090290:
/* 0C4DC0 7F090290 8CD90000 */  lw    $t9, ($a2)
/* 0C4DC4 7F090294 24840001 */  addiu $a0, $a0, 1
/* 0C4DC8 7F090298 0085082A */  slt   $at, $a0, $a1
/* 0C4DCC 7F09029C 14590004 */  bne   $v0, $t9, .L7F0902B0
/* 0C4DD0 7F0902A0 00000000 */   nop   
/* 0C4DD4 7F0902A4 8CC8FFFC */  lw    $t0, -4($a2)
/* 0C4DD8 7F0902A8 03E00008 */  jr    $ra
/* 0C4DDC 7F0902AC ACE80000 */   sw    $t0, ($a3)

.L7F0902B0:
/* 0C4DE0 7F0902B0 1420FFF7 */  bnez  $at, .L7F090290
/* 0C4DE4 7F0902B4 24C60004 */   addiu $a2, $a2, 4
.L7F0902B8:
/* 0C4DE8 7F0902B8 03E00008 */  jr    $ra
/* 0C4DEC 7F0902BC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0902C0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0902C0
/* 0C4DF0 7F0902C0 3C038003 */  lui   $v1, %hi(ptr_groupings) # $v1, 0x8003
/* 0C4DF4 7F0902C4 8C636B84 */  lw    $v1, %lo(ptr_groupings)($v1)
/* 0C4DF8 7F0902C8 3C088003 */  lui   $t0, %hi(highlighted_debug_option) # $t0, 0x8003
/* 0C4DFC 7F0902CC 25086B70 */  addiu $t0, %lo(highlighted_debug_option) # addiu $t0, $t0, 0x6b70
/* 0C4E00 7F0902D0 8D020000 */  lw    $v0, ($t0)
/* 0C4E04 7F0902D4 8C640000 */  lw    $a0, ($v1)
/* 0C4E08 7F0902D8 3C058003 */  lui   $a1, %hi(number_groups)
/* 0C4E0C 7F0902DC 0044082A */  slt   $at, $v0, $a0
/* 0C4E10 7F0902E0 10200008 */  beqz  $at, .L7F090304
/* 0C4E14 7F0902E4 00447021 */   addu  $t6, $v0, $a0
/* 0C4E18 7F0902E8 AD0E0000 */  sw    $t6, ($t0)
/* 0C4E1C 7F0902EC 8C650004 */  lw    $a1, 4($v1)
/* 0C4E20 7F0902F0 01C5082A */  slt   $at, $t6, $a1
/* 0C4E24 7F0902F4 14200027 */  bnez  $at, .L7F090394
/* 0C4E28 7F0902F8 24B8FFFF */   addiu $t8, $a1, -1
/* 0C4E2C 7F0902FC 03E00008 */  jr    $ra
/* 0C4E30 7F090300 AD180000 */   sw    $t8, ($t0)

.L7F090304:
/* 0C4E34 7F090304 8CA56B80 */  lw    $a1, %lo(number_groups)($a1)
/* 0C4E38 7F090308 00002025 */  move  $a0, $zero
/* 0C4E3C 7F09030C 00603025 */  move  $a2, $v1
/* 0C4E40 7F090310 18A00020 */  blez  $a1, .L7F090394
/* 0C4E44 7F090314 00000000 */   nop   
.L7F090318:
/* 0C4E48 7F090318 8CC70000 */  lw    $a3, ($a2)
/* 0C4E4C 7F09031C 24840001 */  addiu $a0, $a0, 1
/* 0C4E50 7F090320 0047082A */  slt   $at, $v0, $a3
/* 0C4E54 7F090324 50200019 */  beql  $at, $zero, .L7F09038C
/* 0C4E58 7F090328 0085082A */   slt   $at, $a0, $a1
/* 0C4E5C 7F09032C 8CC9FFFC */  lw    $t1, -4($a2)
/* 0C4E60 7F090330 0047C821 */  addu  $t9, $v0, $a3
/* 0C4E64 7F090334 03295023 */  subu  $t2, $t9, $t1
/* 0C4E68 7F090338 AD0A0000 */  sw    $t2, ($t0)
/* 0C4E6C 7F09033C 8CC40004 */  lw    $a0, 4($a2)
/* 0C4E70 7F090340 0483000B */  bgezl $a0, .L7F090370
/* 0C4E74 7F090344 8D180000 */   lw    $t8, ($t0)
/* 0C4E78 7F090348 8CCC0000 */  lw    $t4, ($a2)
/* 0C4E7C 7F09034C 014C6823 */  subu  $t5, $t2, $t4
/* 0C4E80 7F090350 AD0D0000 */  sw    $t5, ($t0)
/* 0C4E84 7F090354 8C640000 */  lw    $a0, ($v1)
/* 0C4E88 7F090358 01A4082A */  slt   $at, $t5, $a0
/* 0C4E8C 7F09035C 1420000D */  bnez  $at, .L7F090394
/* 0C4E90 7F090360 248FFFFF */   addiu $t7, $a0, -1
/* 0C4E94 7F090364 03E00008 */  jr    $ra
/* 0C4E98 7F090368 AD0F0000 */   sw    $t7, ($t0)

/* 0C4E9C 7F09036C 8D180000 */  lw    $t8, ($t0)
.L7F090370:
/* 0C4EA0 7F090370 2499FFFF */  addiu $t9, $a0, -1
/* 0C4EA4 7F090374 0304082A */  slt   $at, $t8, $a0
/* 0C4EA8 7F090378 14200006 */  bnez  $at, .L7F090394
/* 0C4EAC 7F09037C 00000000 */   nop   
/* 0C4EB0 7F090380 03E00008 */  jr    $ra
/* 0C4EB4 7F090384 AD190000 */   sw    $t9, ($t0)

/* 0C4EB8 7F090388 0085082A */  slt   $at, $a0, $a1
.L7F09038C:
/* 0C4EBC 7F09038C 1420FFE2 */  bnez  $at, .L7F090318
/* 0C4EC0 7F090390 24C60004 */   addiu $a2, $a2, 4
.L7F090394:
/* 0C4EC4 7F090394 03E00008 */  jr    $ra
/* 0C4EC8 7F090398 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09039C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09039C
/* 0C4ECC 7F09039C 3C038003 */  lui   $v1, %hi(ptr_groupings) # $v1, 0x8003
/* 0C4ED0 7F0903A0 8C636B84 */  lw    $v1, %lo(ptr_groupings)($v1)
/* 0C4ED4 7F0903A4 3C078003 */  lui   $a3, %hi(highlighted_debug_option) # $a3, 0x8003
/* 0C4ED8 7F0903A8 24E76B70 */  addiu $a3, %lo(highlighted_debug_option) # addiu $a3, $a3, 0x6b70
/* 0C4EDC 7F0903AC 8CE20000 */  lw    $v0, ($a3)
/* 0C4EE0 7F0903B0 8C640000 */  lw    $a0, ($v1)
/* 0C4EE4 7F0903B4 3C058003 */  lui   $a1, %hi(number_groups) # $a1, 0x8003
/* 0C4EE8 7F0903B8 0044082A */  slt   $at, $v0, $a0
/* 0C4EEC 7F0903BC 50200016 */  beql  $at, $zero, .L7F090418
/* 0C4EF0 7F0903C0 0044082A */   slt   $at, $v0, $a0
/* 0C4EF4 7F0903C4 8CA56B80 */  lw    $a1, %lo(number_groups)($a1)
/* 0C4EF8 7F0903C8 00002025 */  move  $a0, $zero
/* 0C4EFC 7F0903CC 24A5FFFF */  addiu $a1, $a1, -1
/* 0C4F00 7F0903D0 58A00006 */  blezl $a1, .L7F0903EC
/* 0C4F04 7F0903D4 00047080 */   sll   $t6, $a0, 2
/* 0C4F08 7F0903D8 24840001 */  addiu $a0, $a0, 1
.L7F0903DC:
/* 0C4F0C 7F0903DC 0085082A */  slt   $at, $a0, $a1
/* 0C4F10 7F0903E0 5420FFFE */  bnezl $at, .L7F0903DC
/* 0C4F14 7F0903E4 24840001 */   addiu $a0, $a0, 1
/* 0C4F18 7F0903E8 00047080 */  sll   $t6, $a0, 2
.L7F0903EC:
/* 0C4F1C 7F0903EC 006E2821 */  addu  $a1, $v1, $t6
/* 0C4F20 7F0903F0 8CAFFFFC */  lw    $t7, -4($a1)
/* 0C4F24 7F0903F4 004FC021 */  addu  $t8, $v0, $t7
/* 0C4F28 7F0903F8 ACF80000 */  sw    $t8, ($a3)
/* 0C4F2C 7F0903FC 8CA60000 */  lw    $a2, ($a1)
/* 0C4F30 7F090400 0306082A */  slt   $at, $t8, $a2
/* 0C4F34 7F090404 1420001E */  bnez  $at, .L7F090480
/* 0C4F38 7F090408 24C8FFFF */   addiu $t0, $a2, -1
/* 0C4F3C 7F09040C 03E00008 */  jr    $ra
/* 0C4F40 7F090410 ACE80000 */   sw    $t0, ($a3)

/* 0C4F44 7F090414 0044082A */  slt   $at, $v0, $a0
.L7F090418:
/* 0C4F48 7F090418 14200008 */  bnez  $at, .L7F09043C
/* 0C4F4C 7F09041C 00002825 */   move  $a1, $zero
/* 0C4F50 7F090420 00602025 */  move  $a0, $v1
/* 0C4F54 7F090424 8C890004 */  lw    $t1, 4($a0)
.L7F090428:
/* 0C4F58 7F090428 24A50001 */  addiu $a1, $a1, 1
/* 0C4F5C 7F09042C 24840004 */  addiu $a0, $a0, 4
/* 0C4F60 7F090430 0049082A */  slt   $at, $v0, $t1
/* 0C4F64 7F090434 5020FFFC */  beql  $at, $zero, .L7F090428
/* 0C4F68 7F090438 8C890004 */   lw    $t1, 4($a0)
.L7F09043C:
/* 0C4F6C 7F09043C 00055080 */  sll   $t2, $a1, 2
/* 0C4F70 7F090440 006A2021 */  addu  $a0, $v1, $t2
/* 0C4F74 7F090444 8C8BFFFC */  lw    $t3, -4($a0)
/* 0C4F78 7F090448 24ADFFFE */  addiu $t5, $a1, -2
/* 0C4F7C 7F09044C 004B6023 */  subu  $t4, $v0, $t3
/* 0C4F80 7F090450 05A00004 */  bltz  $t5, .L7F090464
/* 0C4F84 7F090454 ACEC0000 */   sw    $t4, ($a3)
/* 0C4F88 7F090458 8C8FFFF8 */  lw    $t7, -8($a0)
/* 0C4F8C 7F09045C 018FC021 */  addu  $t8, $t4, $t7
/* 0C4F90 7F090460 ACF80000 */  sw    $t8, ($a3)
.L7F090464:
/* 0C4F94 7F090464 8C82FFFC */  lw    $v0, -4($a0)
/* 0C4F98 7F090468 8CF90000 */  lw    $t9, ($a3)
/* 0C4F9C 7F09046C 2448FFFF */  addiu $t0, $v0, -1
/* 0C4FA0 7F090470 0322082A */  slt   $at, $t9, $v0
/* 0C4FA4 7F090474 14200002 */  bnez  $at, .L7F090480
/* 0C4FA8 7F090478 00000000 */   nop   
/* 0C4FAC 7F09047C ACE80000 */  sw    $t0, ($a3)
.L7F090480:
/* 0C4FB0 7F090480 03E00008 */  jr    $ra
/* 0C4FB4 7F090484 00000000 */   nop   
)
#endif



