#include "ultra64.h"
#include "game/gamefile.h"
#include "bondconstants.h"

s32 sub_GAME_7F01D6C0(void) {
  return joyGamePakProbe();
}




#ifdef NONMATCHING
void sub_GAME_7F01D6E0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01D6E0
/* 052210 7F01D6E0 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 052214 7F01D6E4 3C0E8003 */  lui   $t6, %hi(D_8002C520) 
/* 052218 7F01D6E8 27A20000 */  addiu $v0, $sp, 0
/* 05221C 7F01D6EC 25CEC520 */  addiu $t6, %lo(D_8002C520) # addiu $t6, $t6, -0x3ae0
/* 052220 7F01D6F0 25D90060 */  addiu $t9, $t6, 0x60
/* 052224 7F01D6F4 00404025 */  move  $t0, $v0
.L7F01D6F8:
/* 052228 7F01D6F8 8DC10000 */  lw    $at, ($t6)
/* 05222C 7F01D6FC 25CE000C */  addiu $t6, $t6, 0xc
/* 052230 7F01D700 2508000C */  addiu $t0, $t0, 0xc
/* 052234 7F01D704 AD01FFF4 */  sw    $at, -0xc($t0)
/* 052238 7F01D708 8DC1FFF8 */  lw    $at, -8($t6)
/* 05223C 7F01D70C AD01FFF8 */  sw    $at, -8($t0)
/* 052240 7F01D710 8DC1FFFC */  lw    $at, -4($t6)
/* 052244 7F01D714 15D9FFF8 */  bne   $t6, $t9, .L7F01D6F8
/* 052248 7F01D718 AD01FFFC */   sw    $at, -4($t0)
/* 05224C 7F01D71C 3C098007 */  lui   $t1, %hi(save6) 
/* 052250 7F01D720 25299B00 */  addiu $t1, %lo(save6) # addiu $t1, $t1, -0x6500
/* 052254 7F01D724 00406825 */  move  $t5, $v0
/* 052258 7F01D728 244C0060 */  addiu $t4, $v0, 0x60
.L7F01D72C:
/* 05225C 7F01D72C 8DA10000 */  lw    $at, ($t5)
/* 052260 7F01D730 25AD000C */  addiu $t5, $t5, 0xc
/* 052264 7F01D734 2529000C */  addiu $t1, $t1, 0xc
/* 052268 7F01D738 AD21FFF4 */  sw    $at, -0xc($t1)
/* 05226C 7F01D73C 8DA1FFF8 */  lw    $at, -8($t5)
/* 052270 7F01D740 AD21FFF8 */  sw    $at, -8($t1)
/* 052274 7F01D744 8DA1FFFC */  lw    $at, -4($t5)
/* 052278 7F01D748 15ACFFF8 */  bne   $t5, $t4, .L7F01D72C
/* 05227C 7F01D74C AD21FFFC */   sw    $at, -4($t1)
/* 052280 7F01D750 03E00008 */  jr    $ra
/* 052284 7F01D754 27BD0060 */   addiu $sp, $sp, 0x60
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01D758(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01D758
/* 052288 7F01D758 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 05228C 7F01D75C AFBF0014 */  sw    $ra, 0x14($sp)
/* 052290 7F01D760 0FC075B0 */  jal   sub_GAME_7F01D6C0
/* 052294 7F01D764 AFA40018 */   sw    $a0, 0x18($sp)
/* 052298 7F01D768 10400009 */  beqz  $v0, .L7F01D790
/* 05229C 7F01D76C 8FA70018 */   lw    $a3, 0x18($sp)
/* 0522A0 7F01D770 24E40008 */  addiu $a0, $a3, 8
/* 0522A4 7F01D774 24E50020 */  addiu $a1, $a3, 0x20
/* 0522A8 7F01D778 0FC26D80 */  jal   sub_GAME_7F09B600
/* 0522AC 7F01D77C 00E03025 */   move  $a2, $a3
/* 0522B0 7F01D780 8FA50018 */  lw    $a1, 0x18($sp)
/* 0522B4 7F01D784 00002025 */  move  $a0, $zero
/* 0522B8 7F01D788 0C003202 */  jal   joyGamePakLongWrite
/* 0522BC 7F01D78C 24060020 */   li    $a2, 32
.L7F01D790:
/* 0522C0 7F01D790 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0522C4 7F01D794 27BD0018 */  addiu $sp, $sp, 0x18
/* 0522C8 7F01D798 03E00008 */  jr    $ra
/* 0522CC 7F01D79C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01D7A0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01D7A0
/* 0522D0 7F01D7A0 3C0E8007 */  lui   $t6, %hi(save1) 
/* 0522D4 7F01D7A4 25CE9920 */  addiu $t6, %lo(save1) # addiu $t6, $t6, -0x66e0
/* 0522D8 7F01D7A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0522DC 7F01D7AC 008E082B */  sltu  $at, $a0, $t6
/* 0522E0 7F01D7B0 1420001F */  bnez  $at, .L7F01D830
/* 0522E4 7F01D7B4 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0522E8 7F01D7B8 3C0F8007 */  lui   $t7, %hi(save6) 
/* 0522EC 7F01D7BC 25EF9B00 */  addiu $t7, %lo(save6) # addiu $t7, $t7, -0x6500
/* 0522F0 7F01D7C0 008F082B */  sltu  $at, $a0, $t7
/* 0522F4 7F01D7C4 5020001B */  beql  $at, $zero, .L7F01D834
/* 0522F8 7F01D7C8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0522FC 7F01D7CC 0FC075B0 */  jal   sub_GAME_7F01D6C0
/* 052300 7F01D7D0 AFA40018 */   sw    $a0, 0x18($sp)
/* 052304 7F01D7D4 10400016 */  beqz  $v0, .L7F01D830
/* 052308 7F01D7D8 8FA70018 */   lw    $a3, 0x18($sp)
/* 05230C 7F01D7DC 24E40008 */  addiu $a0, $a3, 8
/* 052310 7F01D7E0 24E50060 */  addiu $a1, $a3, 0x60
/* 052314 7F01D7E4 00E03025 */  move  $a2, $a3
/* 052318 7F01D7E8 0FC26D80 */  jal   sub_GAME_7F09B600
/* 05231C 7F01D7EC AFA70018 */   sw    $a3, 0x18($sp)
/* 052320 7F01D7F0 8FA50018 */  lw    $a1, 0x18($sp)
/* 052324 7F01D7F4 3C188007 */  lui   $t8, %hi(save1) 
/* 052328 7F01D7F8 27189920 */  addiu $t8, %lo(save1) # addiu $t8, $t8, -0x66e0
/* 05232C 7F01D7FC 24010060 */  li    $at, 96
/* 052330 7F01D800 00B82023 */  subu  $a0, $a1, $t8
/* 052334 7F01D804 0081001A */  div   $zero, $a0, $at
/* 052338 7F01D808 0000C812 */  mflo  $t9
/* 05233C 7F01D80C 00194080 */  sll   $t0, $t9, 2
/* 052340 7F01D810 01194023 */  subu  $t0, $t0, $t9
/* 052344 7F01D814 00084140 */  sll   $t0, $t0, 5
/* 052348 7F01D818 000848C2 */  srl   $t1, $t0, 3
/* 05234C 7F01D81C 25240004 */  addiu $a0, $t1, 4
/* 052350 7F01D820 308A00FF */  andi  $t2, $a0, 0xff
/* 052354 7F01D824 01402025 */  move  $a0, $t2
/* 052358 7F01D828 0C003202 */  jal   joyGamePakLongWrite
/* 05235C 7F01D82C 24060060 */   li    $a2, 96
.L7F01D830:
/* 052360 7F01D830 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01D834:
/* 052364 7F01D834 27BD0018 */  addiu $sp, $sp, 0x18
/* 052368 7F01D838 03E00008 */  jr    $ra
/* 05236C 7F01D83C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01D840(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01D840
/* 052370 7F01D840 27BDFF88 */  addiu $sp, $sp, -0x78
/* 052374 7F01D844 3C0E8003 */  lui   $t6, %hi(D_8002C580) 
/* 052378 7F01D848 27A20018 */  addiu $v0, $sp, 0x18
/* 05237C 7F01D84C 25CEC580 */  addiu $t6, %lo(D_8002C580) # addiu $t6, $t6, -0x3a80
/* 052380 7F01D850 AFBF0014 */  sw    $ra, 0x14($sp)
/* 052384 7F01D854 25D90060 */  addiu $t9, $t6, 0x60
/* 052388 7F01D858 00404025 */  move  $t0, $v0
.L7F01D85C:
/* 05238C 7F01D85C 8DC10000 */  lw    $at, ($t6)
/* 052390 7F01D860 25CE000C */  addiu $t6, $t6, 0xc
/* 052394 7F01D864 2508000C */  addiu $t0, $t0, 0xc
/* 052398 7F01D868 AD01FFF4 */  sw    $at, -0xc($t0)
/* 05239C 7F01D86C 8DC1FFF8 */  lw    $at, -8($t6)
/* 0523A0 7F01D870 AD01FFF8 */  sw    $at, -8($t0)
/* 0523A4 7F01D874 8DC1FFFC */  lw    $at, -4($t6)
/* 0523A8 7F01D878 15D9FFF8 */  bne   $t6, $t9, .L7F01D85C
/* 0523AC 7F01D87C AD01FFFC */   sw    $at, -4($t0)
/* 0523B0 7F01D880 00406025 */  move  $t4, $v0
/* 0523B4 7F01D884 00806825 */  move  $t5, $a0
/* 0523B8 7F01D888 244B0060 */  addiu $t3, $v0, 0x60
.L7F01D88C:
/* 0523BC 7F01D88C 8D810000 */  lw    $at, ($t4)
/* 0523C0 7F01D890 258C000C */  addiu $t4, $t4, 0xc
/* 0523C4 7F01D894 25AD000C */  addiu $t5, $t5, 0xc
/* 0523C8 7F01D898 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 0523CC 7F01D89C 8D81FFF8 */  lw    $at, -8($t4)
/* 0523D0 7F01D8A0 ADA1FFF8 */  sw    $at, -8($t5)
/* 0523D4 7F01D8A4 8D81FFFC */  lw    $at, -4($t4)
/* 0523D8 7F01D8A8 158BFFF8 */  bne   $t4, $t3, .L7F01D88C
/* 0523DC 7F01D8AC ADA1FFFC */   sw    $at, -4($t5)
/* 0523E0 7F01D8B0 0FC075E8 */  jal   sub_GAME_7F01D7A0
/* 0523E4 7F01D8B4 00000000 */   nop   
/* 0523E8 7F01D8B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0523EC 7F01D8BC 27BD0078 */  addiu $sp, $sp, 0x78
/* 0523F0 7F01D8C0 03E00008 */  jr    $ra
/* 0523F4 7F01D8C4 00000000 */   nop   
)
#endif


u32 get_foldernum_of_eeprom(struct save_data *eeprom)
{
  return eeprom->completion_bitflags & 7;
}

void set_eeprom_to_folder_num(struct save_data *eeprom, u32 folder) {
    eeprom->completion_bitflags = eeprom->completion_bitflags & 0xFFF8;
  
    eeprom->completion_bitflags = eeprom->completion_bitflags | folder & 7;
}


u32 set_eeprom_flag_0x18(struct save_data *folder)
{
  return (folder->completion_bitflags & 0x18) >> 3;
}

void reset_eeprom_flag_0x18(struct save_data *folder, s32 arg1) {
    folder->completion_bitflags = folder->completion_bitflags & 0xFFE7;

    folder->completion_bitflags = (folder->completion_bitflags | ((arg1 * 8) & 0x18));
}


u32 get_selected_bond(struct save_data *folder)
{
  return (folder->completion_bitflags & 0x60) >> 5;
}




void set_selected_bond(struct save_data *folder, s32 arg1) {
    folder->completion_bitflags = folder->completion_bitflags & 0xFF9F;

    folder->completion_bitflags = (folder->completion_bitflags | ((arg1 << 5) & 0x60));
}





u32 check_if_eeprom_flag_set_0x80(struct save_data *folder)
{
  return ((folder->completion_bitflags & 0x80) != 0);
}


void toggle_eeprom_flag_set_0x80(struct save_data *folder,u32 mode)
{
  if (mode != 0) {
    folder->completion_bitflags = folder->completion_bitflags | 0x80;
    return;
  }
  folder->completion_bitflags = folder->completion_bitflags & 0xff7f;
  return;
}




#ifdef NONMATCHING
void get_eeprom_stage_complete_time_for_difficulty(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_eeprom_stage_complete_time_for_difficulty
/* 0524C0 7F01D990 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0524C4 7F01D994 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0524C8 7F01D998 04A0004D */  bltz  $a1, .L7F01DAD0
/* 0524CC 7F01D99C 00803825 */   move  $a3, $a0
/* 0524D0 7F01D9A0 28A10014 */  slti  $at, $a1, 0x14
/* 0524D4 7F01D9A4 5020004B */  beql  $at, $zero, .L7F01DAD4
/* 0524D8 7F01D9A8 00001025 */   move  $v0, $zero
/* 0524DC 7F01D9AC 04C00048 */  bltz  $a2, .L7F01DAD0
/* 0524E0 7F01D9B0 28C10004 */   slti  $at, $a2, 4
/* 0524E4 7F01D9B4 10200046 */  beqz  $at, .L7F01DAD0
/* 0524E8 7F01D9B8 24030003 */   li    $v1, 3
/* 0524EC 7F01D9BC 14C3000B */  bne   $a2, $v1, .L7F01D9EC
/* 0524F0 7F01D9C0 24080007 */   li    $t0, 7
/* 0524F4 7F01D9C4 0FC07632 */  jal   get_foldernum_of_eeprom
/* 0524F8 7F01D9C8 00000000 */   nop   
/* 0524FC 7F01D9CC 0FC07D28 */  jal   check_for_007_mode_unlocked
/* 052500 7F01D9D0 00402025 */   move  $a0, $v0
/* 052504 7F01D9D4 10400003 */  beqz  $v0, .L7F01D9E4
/* 052508 7F01D9D8 00000000 */   nop   
/* 05250C 7F01D9DC 1000003D */  b     .L7F01DAD4
/* 052510 7F01D9E0 240203FF */   li    $v0, 1023
.L7F01D9E4:
/* 052514 7F01D9E4 1000003B */  b     .L7F01DAD4
/* 052518 7F01D9E8 00001025 */   move  $v0, $zero
.L7F01D9EC:
/* 05251C 7F01D9EC 00067080 */  sll   $t6, $a2, 2
/* 052520 7F01D9F0 01C67021 */  addu  $t6, $t6, $a2
/* 052524 7F01D9F4 000E7080 */  sll   $t6, $t6, 2
/* 052528 7F01D9F8 01C52021 */  addu  $a0, $t6, $a1
/* 05252C 7F01D9FC 00047880 */  sll   $t7, $a0, 2
/* 052530 7F01DA00 01E47821 */  addu  $t7, $t7, $a0
/* 052534 7F01DA04 000F7840 */  sll   $t7, $t7, 1
/* 052538 7F01DA08 31F80007 */  andi  $t8, $t7, 7
/* 05253C 7F01DA0C 01181023 */  subu  $v0, $t0, $t8
/* 052540 7F01DA10 24010001 */  li    $at, 1
/* 052544 7F01DA14 10410024 */  beq   $v0, $at, .L7F01DAA8
/* 052548 7F01DA18 01E02025 */   move  $a0, $t7
/* 05254C 7F01DA1C 10430019 */  beq   $v0, $v1, .L7F01DA84
/* 052550 7F01DA20 000458C3 */   sra   $t3, $a0, 3
/* 052554 7F01DA24 24010005 */  li    $at, 5
/* 052558 7F01DA28 5041000D */  beql  $v0, $at, .L7F01DA60
/* 05255C 7F01DA2C 000478C3 */   sra   $t7, $a0, 3
/* 052560 7F01DA30 14480025 */  bne   $v0, $t0, .L7F01DAC8
/* 052564 7F01DA34 00001825 */   move  $v1, $zero
/* 052568 7F01DA38 000FC8C3 */  sra   $t9, $t7, 3
/* 05256C 7F01DA3C 00F91021 */  addu  $v0, $a3, $t9
/* 052570 7F01DA40 90490013 */  lbu   $t1, 0x13($v0)
/* 052574 7F01DA44 904D0012 */  lbu   $t5, 0x12($v0)
/* 052578 7F01DA48 312A00C0 */  andi  $t2, $t1, 0xc0
/* 05257C 7F01DA4C 000A5983 */  sra   $t3, $t2, 6
/* 052580 7F01DA50 000D7080 */  sll   $t6, $t5, 2
/* 052584 7F01DA54 1000001F */  b     .L7F01DAD4
/* 052588 7F01DA58 016E1025 */   or    $v0, $t3, $t6
/* 05258C 7F01DA5C 000478C3 */  sra   $t7, $a0, 3
.L7F01DA60:
/* 052590 7F01DA60 00EF1021 */  addu  $v0, $a3, $t7
/* 052594 7F01DA64 90580013 */  lbu   $t8, 0x13($v0)
/* 052598 7F01DA68 904A0012 */  lbu   $t2, 0x12($v0)
/* 05259C 7F01DA6C 331900F0 */  andi  $t9, $t8, 0xf0
/* 0525A0 7F01DA70 314C003F */  andi  $t4, $t2, 0x3f
/* 0525A4 7F01DA74 000C6900 */  sll   $t5, $t4, 4
/* 0525A8 7F01DA78 00194903 */  sra   $t1, $t9, 4
/* 0525AC 7F01DA7C 10000015 */  b     .L7F01DAD4
/* 0525B0 7F01DA80 012D1025 */   or    $v0, $t1, $t5
.L7F01DA84:
/* 0525B4 7F01DA84 00EB1021 */  addu  $v0, $a3, $t3
/* 0525B8 7F01DA88 904E0013 */  lbu   $t6, 0x13($v0)
/* 0525BC 7F01DA8C 90590012 */  lbu   $t9, 0x12($v0)
/* 0525C0 7F01DA90 31CF00FC */  andi  $t7, $t6, 0xfc
/* 0525C4 7F01DA94 332A000F */  andi  $t2, $t9, 0xf
/* 0525C8 7F01DA98 000A6180 */  sll   $t4, $t2, 6
/* 0525CC 7F01DA9C 000FC083 */  sra   $t8, $t7, 2
/* 0525D0 7F01DAA0 1000000C */  b     .L7F01DAD4
/* 0525D4 7F01DAA4 030C1025 */   or    $v0, $t8, $t4
.L7F01DAA8:
/* 0525D8 7F01DAA8 000448C3 */  sra   $t1, $a0, 3
/* 0525DC 7F01DAAC 00E91021 */  addu  $v0, $a3, $t1
/* 0525E0 7F01DAB0 904E0012 */  lbu   $t6, 0x12($v0)
/* 0525E4 7F01DAB4 904B0013 */  lbu   $t3, 0x13($v0)
/* 0525E8 7F01DAB8 31CF0003 */  andi  $t7, $t6, 3
/* 0525EC 7F01DABC 000FCA00 */  sll   $t9, $t7, 8
/* 0525F0 7F01DAC0 10000004 */  b     .L7F01DAD4
/* 0525F4 7F01DAC4 01791025 */   or    $v0, $t3, $t9
.L7F01DAC8:
/* 0525F8 7F01DAC8 10000002 */  b     .L7F01DAD4
/* 0525FC 7F01DACC 00601025 */   move  $v0, $v1
.L7F01DAD0:
/* 052600 7F01DAD0 00001025 */  move  $v0, $zero
.L7F01DAD4:
/* 052604 7F01DAD4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 052608 7F01DAD8 27BD0018 */  addiu $sp, $sp, 0x18
/* 05260C 7F01DADC 03E00008 */  jr    $ra
/* 052610 7F01DAE0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01DAE4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DAE4
/* 052614 7F01DAE4 04A0005C */  bltz  $a1, .L7F01DC58
/* 052618 7F01DAE8 28A10014 */   slti  $at, $a1, 0x14
/* 05261C 7F01DAEC 1020005A */  beqz  $at, .L7F01DC58
/* 052620 7F01DAF0 00000000 */   nop   
/* 052624 7F01DAF4 04C00058 */  bltz  $a2, .L7F01DC58
/* 052628 7F01DAF8 28C10003 */   slti  $at, $a2, 3
/* 05262C 7F01DAFC 10200056 */  beqz  $at, .L7F01DC58
/* 052630 7F01DB00 24080007 */   li    $t0, 7
/* 052634 7F01DB04 14E00003 */  bnez  $a3, .L7F01DB14
/* 052638 7F01DB08 00067080 */   sll   $t6, $a2, 2
/* 05263C 7F01DB0C 10000005 */  b     .L7F01DB24
/* 052640 7F01DB10 2407004F */   li    $a3, 79
.L7F01DB14:
/* 052644 7F01DB14 28E10400 */  slti  $at, $a3, 0x400
/* 052648 7F01DB18 54200003 */  bnezl $at, .L7F01DB28
/* 05264C 7F01DB1C 01C67021 */   addu  $t6, $t6, $a2
/* 052650 7F01DB20 240703FF */  li    $a3, 1023
.L7F01DB24:
/* 052654 7F01DB24 01C67021 */  addu  $t6, $t6, $a2
.L7F01DB28:
/* 052658 7F01DB28 000E7080 */  sll   $t6, $t6, 2
/* 05265C 7F01DB2C 01C51021 */  addu  $v0, $t6, $a1
/* 052660 7F01DB30 00027880 */  sll   $t7, $v0, 2
/* 052664 7F01DB34 01E27821 */  addu  $t7, $t7, $v0
/* 052668 7F01DB38 000F7840 */  sll   $t7, $t7, 1
/* 05266C 7F01DB3C 31F80007 */  andi  $t8, $t7, 7
/* 052670 7F01DB40 01181823 */  subu  $v1, $t0, $t8
/* 052674 7F01DB44 24010001 */  li    $at, 1
/* 052678 7F01DB48 10610035 */  beq   $v1, $at, .L7F01DC20
/* 05267C 7F01DB4C 01E01025 */   move  $v0, $t7
/* 052680 7F01DB50 24010003 */  li    $at, 3
/* 052684 7F01DB54 10610023 */  beq   $v1, $at, .L7F01DBE4
/* 052688 7F01DB58 0002C0C3 */   sra   $t8, $v0, 3
/* 05268C 7F01DB5C 24010005 */  li    $at, 5
/* 052690 7F01DB60 10610011 */  beq   $v1, $at, .L7F01DBA8
/* 052694 7F01DB64 000260C3 */   sra   $t4, $v0, 3
/* 052698 7F01DB68 1468003B */  bne   $v1, $t0, .L7F01DC58
/* 05269C 7F01DB6C 000FC8C3 */   sra   $t9, $t7, 3
/* 0526A0 7F01DB70 00991821 */  addu  $v1, $a0, $t9
/* 0526A4 7F01DB74 90690012 */  lbu   $t1, 0x12($v1)
/* 0526A8 7F01DB78 906B0013 */  lbu   $t3, 0x13($v1)
/* 0526AC 7F01DB7C 00077883 */  sra   $t7, $a3, 2
/* 0526B0 7F01DB80 312DFF00 */  andi  $t5, $t1, 0xff00
/* 0526B4 7F01DB84 3179FF3F */  andi  $t9, $t3, 0xff3f
/* 0526B8 7F01DB88 00075180 */  sll   $t2, $a3, 6
/* 0526BC 7F01DB8C A06D0012 */  sb    $t5, 0x12($v1)
/* 0526C0 7F01DB90 A0790013 */  sb    $t9, 0x13($v1)
/* 0526C4 7F01DB94 01AFC025 */  or    $t8, $t5, $t7
/* 0526C8 7F01DB98 032A5825 */  or    $t3, $t9, $t2
/* 0526CC 7F01DB9C A0780012 */  sb    $t8, 0x12($v1)
/* 0526D0 7F01DBA0 03E00008 */  jr    $ra
/* 0526D4 7F01DBA4 A06B0013 */   sb    $t3, 0x13($v1)

.L7F01DBA8:
/* 0526D8 7F01DBA8 008C1821 */  addu  $v1, $a0, $t4
/* 0526DC 7F01DBAC 906E0012 */  lbu   $t6, 0x12($v1)
/* 0526E0 7F01DBB0 906F0013 */  lbu   $t7, 0x13($v1)
/* 0526E4 7F01DBB4 0007C903 */  sra   $t9, $a3, 4
/* 0526E8 7F01DBB8 31C9FFC0 */  andi  $t1, $t6, 0xffc0
/* 0526EC 7F01DBBC 31ECFF0F */  andi  $t4, $t7, 0xff0f
/* 0526F0 7F01DBC0 332A003F */  andi  $t2, $t9, 0x3f
/* 0526F4 7F01DBC4 00076900 */  sll   $t5, $a3, 4
/* 0526F8 7F01DBC8 A0690012 */  sb    $t1, 0x12($v1)
/* 0526FC 7F01DBCC A06C0013 */  sb    $t4, 0x13($v1)
/* 052700 7F01DBD0 012A5825 */  or    $t3, $t1, $t2
/* 052704 7F01DBD4 018D7825 */  or    $t7, $t4, $t5
/* 052708 7F01DBD8 A06B0012 */  sb    $t3, 0x12($v1)
/* 05270C 7F01DBDC 03E00008 */  jr    $ra
/* 052710 7F01DBE0 A06F0013 */   sb    $t7, 0x13($v1)

.L7F01DBE4:
/* 052714 7F01DBE4 00981821 */  addu  $v1, $a0, $t8
/* 052718 7F01DBE8 90790012 */  lbu   $t9, 0x12($v1)
/* 05271C 7F01DBEC 906A0013 */  lbu   $t2, 0x13($v1)
/* 052720 7F01DBF0 00076183 */  sra   $t4, $a3, 6
/* 052724 7F01DBF4 332EFFF0 */  andi  $t6, $t9, 0xfff0
/* 052728 7F01DBF8 3158FF03 */  andi  $t8, $t2, 0xff03
/* 05272C 7F01DBFC 318D000F */  andi  $t5, $t4, 0xf
/* 052730 7F01DC00 00074880 */  sll   $t1, $a3, 2
/* 052734 7F01DC04 A06E0012 */  sb    $t6, 0x12($v1)
/* 052738 7F01DC08 A0780013 */  sb    $t8, 0x13($v1)
/* 05273C 7F01DC0C 01CD7825 */  or    $t7, $t6, $t5
/* 052740 7F01DC10 03095025 */  or    $t2, $t8, $t1
/* 052744 7F01DC14 A06F0012 */  sb    $t7, 0x12($v1)
/* 052748 7F01DC18 03E00008 */  jr    $ra
/* 05274C 7F01DC1C A06A0013 */   sb    $t2, 0x13($v1)

.L7F01DC20:
/* 052750 7F01DC20 000258C3 */  sra   $t3, $v0, 3
/* 052754 7F01DC24 008B1821 */  addu  $v1, $a0, $t3
/* 052758 7F01DC28 906C0012 */  lbu   $t4, 0x12($v1)
/* 05275C 7F01DC2C 906D0013 */  lbu   $t5, 0x13($v1)
/* 052760 7F01DC30 0007C203 */  sra   $t8, $a3, 8
/* 052764 7F01DC34 3199FFFC */  andi  $t9, $t4, 0xfffc
/* 052768 7F01DC38 31ABFF00 */  andi  $t3, $t5, 0xff00
/* 05276C 7F01DC3C 33090003 */  andi  $t1, $t8, 3
/* 052770 7F01DC40 A0790012 */  sb    $t9, 0x12($v1)
/* 052774 7F01DC44 A06B0013 */  sb    $t3, 0x13($v1)
/* 052778 7F01DC48 03295025 */  or    $t2, $t9, $t1
/* 05277C 7F01DC4C 01677025 */  or    $t6, $t3, $a3
/* 052780 7F01DC50 A06A0012 */  sb    $t2, 0x12($v1)
/* 052784 7F01DC54 A06E0013 */  sb    $t6, 0x13($v1)
.L7F01DC58:
/* 052788 7F01DC58 03E00008 */  jr    $ra
/* 05278C 7F01DC5C 00000000 */   nop   
)
#endif



s32 get_eeprom_stage_completed_for_difficulty(struct save_data *folder, s32 levelid, DIFFICULTY difficulty) {
    
    if ((levelid >= 0) && (levelid < 0x14) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007)) {
        return get_eeprom_stage_complete_time_for_difficulty(folder, levelid, difficulty) != 0;
    }

    return 0;
}



void sub_GAME_7F01DCB0(struct save_data *folder, s32 levelid, DIFFICULTY difficulty, s32 arg4) {
    s32 temp_v0;

    if ((levelid >= 0) && (levelid < 0x14) && (difficulty >= DIFFICULTY_AGENT) && (difficulty <= DIFFICULTY_007)) {
        
        temp_v0 = get_eeprom_stage_complete_time_for_difficulty(folder, levelid, difficulty);
        
        if ((temp_v0 == 0) || (arg4 < temp_v0)) {
            sub_GAME_7F01DAE4(folder, levelid, difficulty, arg4);
        }
    }
}



#ifdef NONMATCHING
s32 check_if_cheat_unlocked(struct save_data *arg0, s32 arg1) {

    if ((arg1 >= 0) && (arg1 < 0x14)) {
        
        return ((1 << arg1) & (arg0->unlocked_cheats_1 | (arg0->unlocked_cheats_3 << 0x18) | (arg0->unlocked_cheats_3 << 0x10) | (arg0->unlocked_cheats_2 << 8))) != 0;
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel check_if_cheat_unlocked
/* 052850 7F01DD20 04A00011 */  bltz  $a1, .L7F01DD68
/* 052854 7F01DD24 28A10014 */   slti  $at, $a1, 0x14
/* 052858 7F01DD28 1020000F */  beqz  $at, .L7F01DD68
/* 05285C 7F01DD2C 240B0001 */   li    $t3, 1
/* 052860 7F01DD30 90860010 */  lbu   $a2, 0x10($a0)
/* 052864 7F01DD34 908E000E */  lbu   $t6, 0xe($a0)
/* 052868 7F01DD38 9089000F */  lbu   $t1, 0xf($a0)
/* 05286C 7F01DD3C 00067E00 */  sll   $t7, $a2, 0x18
/* 052870 7F01DD40 0006CC00 */  sll   $t9, $a2, 0x10
/* 052874 7F01DD44 01CFC025 */  or    $t8, $t6, $t7
/* 052878 7F01DD48 03194025 */  or    $t0, $t8, $t9
/* 05287C 7F01DD4C 00095200 */  sll   $t2, $t1, 8
/* 052880 7F01DD50 010A1825 */  or    $v1, $t0, $t2
/* 052884 7F01DD54 00AB6004 */  sllv  $t4, $t3, $a1
/* 052888 7F01DD58 01831024 */  and   $v0, $t4, $v1
/* 05288C 7F01DD5C 0002682B */  sltu  $t5, $zero, $v0
/* 052890 7F01DD60 03E00008 */  jr    $ra
/* 052894 7F01DD64 01A01025 */   move  $v0, $t5

.L7F01DD68:
/* 052898 7F01DD68 00001025 */  move  $v0, $zero
/* 05289C 7F01DD6C 03E00008 */  jr    $ra
/* 0528A0 7F01DD70 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01DD74(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DD74
/* 0528A4 7F01DD74 04A00011 */  bltz  $a1, .L7F01DDBC
/* 0528A8 7F01DD78 00803025 */   move  $a2, $a0
/* 0528AC 7F01DD7C 28A10014 */  slti  $at, $a1, 0x14
/* 0528B0 7F01DD80 1020000E */  beqz  $at, .L7F01DDBC
/* 0528B4 7F01DD84 240E0001 */   li    $t6, 1
/* 0528B8 7F01DD88 00AE1004 */  sllv  $v0, $t6, $a1
/* 0528BC 7F01DD8C 2C410100 */  sltiu $at, $v0, 0x100
/* 0528C0 7F01DD90 14200006 */  bnez  $at, .L7F01DDAC
/* 0528C4 7F01DD94 00002025 */   move  $a0, $zero
.L7F01DD98:
/* 0528C8 7F01DD98 00027A02 */  srl   $t7, $v0, 8
/* 0528CC 7F01DD9C 2DE10100 */  sltiu $at, $t7, 0x100
/* 0528D0 7F01DDA0 24840001 */  addiu $a0, $a0, 1
/* 0528D4 7F01DDA4 1020FFFC */  beqz  $at, .L7F01DD98
/* 0528D8 7F01DDA8 01E01025 */   move  $v0, $t7
.L7F01DDAC:
/* 0528DC 7F01DDAC 00C41821 */  addu  $v1, $a2, $a0
/* 0528E0 7F01DDB0 9078000E */  lbu   $t8, 0xe($v1)
/* 0528E4 7F01DDB4 03024025 */  or    $t0, $t8, $v0
/* 0528E8 7F01DDB8 A068000E */  sb    $t0, 0xe($v1)
.L7F01DDBC:
/* 0528EC 7F01DDBC 03E00008 */  jr    $ra
/* 0528F0 7F01DDC0 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void get_save_folder_ptr(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_save_folder_ptr
/* 0528F4 7F01DDC4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0528F8 7F01DDC8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0528FC 7F01DDCC AFB00018 */  sw    $s0, 0x18($sp)
/* 052900 7F01DDD0 AFB20020 */  sw    $s2, 0x20($sp)
/* 052904 7F01DDD4 3C108007 */  lui   $s0, %hi(save1)
/* 052908 7F01DDD8 3C118007 */  lui   $s1, %hi(save6)
/* 05290C 7F01DDDC 00809025 */  move  $s2, $a0
/* 052910 7F01DDE0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 052914 7F01DDE4 26319B00 */  addiu $s1, %lo(save6) # addiu $s1, $s1, -0x6500
/* 052918 7F01DDE8 26109920 */  addiu $s0, %lo(save1) # addiu $s0, $s0, -0x66e0
.L7F01DDEC:
/* 05291C 7F01DDEC 0FC07655 */  jal   check_if_eeprom_flag_set_0x80
/* 052920 7F01DDF0 02002025 */   move  $a0, $s0
/* 052924 7F01DDF4 54400008 */  bnezl $v0, .L7F01DE18
/* 052928 7F01DDF8 26100060 */   addiu $s0, $s0, 0x60
/* 05292C 7F01DDFC 0FC07632 */  jal   get_foldernum_of_eeprom
/* 052930 7F01DE00 02002025 */   move  $a0, $s0
/* 052934 7F01DE04 54520004 */  bnel  $v0, $s2, .L7F01DE18
/* 052938 7F01DE08 26100060 */   addiu $s0, $s0, 0x60
/* 05293C 7F01DE0C 1000000A */  b     .L7F01DE38
/* 052940 7F01DE10 02001025 */   move  $v0, $s0
/* 052944 7F01DE14 26100060 */  addiu $s0, $s0, 0x60
.L7F01DE18:
/* 052948 7F01DE18 1611FFF4 */  bne   $s0, $s1, .L7F01DDEC
/* 05294C 7F01DE1C 00000000 */   nop   
/* 052950 7F01DE20 24010064 */  li    $at, 100
/* 052954 7F01DE24 16410004 */  bne   $s2, $at, .L7F01DE38
/* 052958 7F01DE28 00001025 */   move  $v0, $zero
/* 05295C 7F01DE2C 3C028007 */  lui   $v0, %hi(save6)
/* 052960 7F01DE30 10000001 */  b     .L7F01DE38
/* 052964 7F01DE34 24429B00 */   addiu $v0, %lo(save6) # addiu $v0, $v0, -0x6500
.L7F01DE38:
/* 052968 7F01DE38 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05296C 7F01DE3C 8FB00018 */  lw    $s0, 0x18($sp)
/* 052970 7F01DE40 8FB1001C */  lw    $s1, 0x1c($sp)
/* 052974 7F01DE44 8FB20020 */  lw    $s2, 0x20($sp)
/* 052978 7F01DE48 03E00008 */  jr    $ra
/* 05297C 7F01DE4C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01DE50(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DE50
/* 052980 7F01DE50 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 052984 7F01DE54 AFB1001C */  sw    $s1, 0x1c($sp)
/* 052988 7F01DE58 AFB20020 */  sw    $s2, 0x20($sp)
/* 05298C 7F01DE5C AFB00018 */  sw    $s0, 0x18($sp)
/* 052990 7F01DE60 3C118007 */  lui   $s1, %hi(save1)
/* 052994 7F01DE64 AFBF0024 */  sw    $ra, 0x24($sp)
/* 052998 7F01DE68 26319920 */  addiu $s1, %lo(save1) # addiu $s1, $s1, -0x66e0
/* 05299C 7F01DE6C 00008025 */  move  $s0, $zero
/* 0529A0 7F01DE70 24120005 */  li    $s2, 5
.L7F01DE74:
/* 0529A4 7F01DE74 0FC07655 */  jal   check_if_eeprom_flag_set_0x80
/* 0529A8 7F01DE78 02202025 */   move  $a0, $s1
/* 0529AC 7F01DE7C 50400004 */  beql  $v0, $zero, .L7F01DE90
/* 0529B0 7F01DE80 26100001 */   addiu $s0, $s0, 1
/* 0529B4 7F01DE84 10000005 */  b     .L7F01DE9C
/* 0529B8 7F01DE88 02001025 */   move  $v0, $s0
/* 0529BC 7F01DE8C 26100001 */  addiu $s0, $s0, 1
.L7F01DE90:
/* 0529C0 7F01DE90 1612FFF8 */  bne   $s0, $s2, .L7F01DE74
/* 0529C4 7F01DE94 26310060 */   addiu $s1, $s1, 0x60
/* 0529C8 7F01DE98 2402FFFF */  li    $v0, -1
.L7F01DE9C:
/* 0529CC 7F01DE9C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0529D0 7F01DEA0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0529D4 7F01DEA4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0529D8 7F01DEA8 8FB20020 */  lw    $s2, 0x20($sp)
/* 0529DC 7F01DEAC 03E00008 */  jr    $ra
/* 0529E0 7F01DEB0 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01DEB4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DEB4
/* 0529E4 7F01DEB4 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0529E8 7F01DEB8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0529EC 7F01DEBC AFB00018 */  sw    $s0, 0x18($sp)
/* 0529F0 7F01DEC0 0FC07794 */  jal   sub_GAME_7F01DE50
/* 0529F4 7F01DEC4 AFA40088 */   sw    $a0, 0x88($sp)
/* 0529F8 7F01DEC8 0440002C */  bltz  $v0, .L7F01DF7C
/* 0529FC 7F01DECC 00401825 */   move  $v1, $v0
/* 052A00 7F01DED0 3C0E8003 */  lui   $t6, %hi(D_8002C5E0) 
/* 052A04 7F01DED4 27A20024 */  addiu $v0, $sp, 0x24
/* 052A08 7F01DED8 25CEC5E0 */  addiu $t6, %lo(D_8002C5E0) # addiu $t6, $t6, -0x3a20
/* 052A0C 7F01DEDC 25D80060 */  addiu $t8, $t6, 0x60
/* 052A10 7F01DEE0 0040C825 */  move  $t9, $v0
.L7F01DEE4:
/* 052A14 7F01DEE4 8DC10000 */  lw    $at, ($t6)
/* 052A18 7F01DEE8 25CE000C */  addiu $t6, $t6, 0xc
/* 052A1C 7F01DEEC 2739000C */  addiu $t9, $t9, 0xc
/* 052A20 7F01DEF0 AF21FFF4 */  sw    $at, -0xc($t9)
/* 052A24 7F01DEF4 8DC1FFF8 */  lw    $at, -8($t6)
/* 052A28 7F01DEF8 AF21FFF8 */  sw    $at, -8($t9)
/* 052A2C 7F01DEFC 8DC1FFFC */  lw    $at, -4($t6)
/* 052A30 7F01DF00 15D8FFF8 */  bne   $t6, $t8, .L7F01DEE4
/* 052A34 7F01DF04 AF21FFFC */   sw    $at, -4($t9)
/* 052A38 7F01DF08 00034080 */  sll   $t0, $v1, 2
/* 052A3C 7F01DF0C 01034023 */  subu  $t0, $t0, $v1
/* 052A40 7F01DF10 3C098007 */  lui   $t1, %hi(save1) 
/* 052A44 7F01DF14 25299920 */  addiu $t1, %lo(save1) # addiu $t1, $t1, -0x66e0
/* 052A48 7F01DF18 00084140 */  sll   $t0, $t0, 5
/* 052A4C 7F01DF1C 01098021 */  addu  $s0, $t0, $t1
/* 052A50 7F01DF20 02006825 */  move  $t5, $s0
/* 052A54 7F01DF24 00406025 */  move  $t4, $v0
/* 052A58 7F01DF28 244B0060 */  addiu $t3, $v0, 0x60
.L7F01DF2C:
/* 052A5C 7F01DF2C 8D810000 */  lw    $at, ($t4)
/* 052A60 7F01DF30 258C000C */  addiu $t4, $t4, 0xc
/* 052A64 7F01DF34 25AD000C */  addiu $t5, $t5, 0xc
/* 052A68 7F01DF38 ADA1FFF4 */  sw    $at, -0xc($t5)
/* 052A6C 7F01DF3C 8D81FFF8 */  lw    $at, -8($t4)
/* 052A70 7F01DF40 ADA1FFF8 */  sw    $at, -8($t5)
/* 052A74 7F01DF44 8D81FFFC */  lw    $at, -4($t4)
/* 052A78 7F01DF48 158BFFF8 */  bne   $t4, $t3, .L7F01DF2C
/* 052A7C 7F01DF4C ADA1FFFC */   sw    $at, -4($t5)
/* 052A80 7F01DF50 02002025 */  move  $a0, $s0
/* 052A84 7F01DF54 0FC07636 */  jal   set_eeprom_to_folder_num
/* 052A88 7F01DF58 8FA50088 */   lw    $a1, 0x88($sp)
/* 052A8C 7F01DF5C 02002025 */  move  $a0, $s0
/* 052A90 7F01DF60 0FC07659 */  jal   toggle_eeprom_flag_set_0x80
/* 052A94 7F01DF64 00002825 */   move  $a1, $zero
/* 052A98 7F01DF68 02002025 */  move  $a0, $s0
/* 052A9C 7F01DF6C 0FC0764D */  jal   set_selected_bond
/* 052AA0 7F01DF70 8FA50088 */   lw    $a1, 0x88($sp)
/* 052AA4 7F01DF74 0FC075E8 */  jal   sub_GAME_7F01D7A0
/* 052AA8 7F01DF78 02002025 */   move  $a0, $s0
.L7F01DF7C:
/* 052AAC 7F01DF7C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 052AB0 7F01DF80 8FB00018 */  lw    $s0, 0x18($sp)
/* 052AB4 7F01DF84 27BD0088 */  addiu $sp, $sp, 0x88
/* 052AB8 7F01DF88 03E00008 */  jr    $ra
/* 052ABC 7F01DF8C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01DF90(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01DF90
/* 052AC0 7F01DF90 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 052AC4 7F01DF94 AFBF003C */  sw    $ra, 0x3c($sp)
/* 052AC8 7F01DF98 AFBE0038 */  sw    $fp, 0x38($sp)
/* 052ACC 7F01DF9C AFB70034 */  sw    $s7, 0x34($sp)
/* 052AD0 7F01DFA0 AFB60030 */  sw    $s6, 0x30($sp)
/* 052AD4 7F01DFA4 AFB5002C */  sw    $s5, 0x2c($sp)
/* 052AD8 7F01DFA8 AFB40028 */  sw    $s4, 0x28($sp)
/* 052ADC 7F01DFAC AFB30024 */  sw    $s3, 0x24($sp)
/* 052AE0 7F01DFB0 AFB20020 */  sw    $s2, 0x20($sp)
/* 052AE4 7F01DFB4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 052AE8 7F01DFB8 0FC075B0 */  jal   sub_GAME_7F01D6C0
/* 052AEC 7F01DFBC AFB00018 */   sw    $s0, 0x18($sp)
/* 052AF0 7F01DFC0 104000A6 */  beqz  $v0, .L7F01E25C
/* 052AF4 7F01DFC4 27B10094 */   addiu $s1, $sp, 0x94
/* 052AF8 7F01DFC8 24100001 */  li    $s0, 1
/* 052AFC 7F01DFCC 00002025 */  move  $a0, $zero
/* 052B00 7F01DFD0 02202825 */  move  $a1, $s1
/* 052B04 7F01DFD4 0C0031EF */  jal   joyGamePakLongRead
/* 052B08 7F01DFD8 24060020 */   li    $a2, 32
/* 052B0C 7F01DFDC 93AE009C */  lbu   $t6, 0x9c($sp)
/* 052B10 7F01DFE0 24010042 */  li    $at, 66
/* 052B14 7F01DFE4 27B5008C */  addiu $s5, $sp, 0x8c
/* 052B18 7F01DFE8 11C10002 */  beq   $t6, $at, .L7F01DFF4
/* 052B1C 7F01DFEC 27A4009C */   addiu $a0, $sp, 0x9c
/* 052B20 7F01DFF0 00008025 */  move  $s0, $zero
.L7F01DFF4:
/* 052B24 7F01DFF4 27A500B4 */  addiu $a1, $sp, 0xb4
/* 052B28 7F01DFF8 0FC26D80 */  jal   sub_GAME_7F09B600
/* 052B2C 7F01DFFC 02A03025 */   move  $a2, $s5
/* 052B30 7F01E000 8FAF008C */  lw    $t7, 0x8c($sp)
/* 052B34 7F01E004 8FB80094 */  lw    $t8, 0x94($sp)
/* 052B38 7F01E008 8FB90090 */  lw    $t9, 0x90($sp)
/* 052B3C 7F01E00C 8FA80098 */  lw    $t0, 0x98($sp)
/* 052B40 7F01E010 15F80003 */  bne   $t7, $t8, .L7F01E020
/* 052B44 7F01E014 3C098003 */   lui   $t1, %hi(D_8002C640) 
/* 052B48 7F01E018 13280002 */  beq   $t9, $t0, .L7F01E024
/* 052B4C 7F01E01C 00000000 */   nop   
.L7F01E020:
/* 052B50 7F01E020 00008025 */  move  $s0, $zero
.L7F01E024:
/* 052B54 7F01E024 16000023 */  bnez  $s0, .L7F01E0B4
/* 052B58 7F01E028 2529C640 */   addiu $t1, %lo(D_8002C640) # addiu $t1, $t1, -0x39c0
/* 052B5C 7F01E02C 8D210000 */  lw    $at, ($t1)
/* 052B60 7F01E030 27A20064 */  addiu $v0, $sp, 0x64
/* 052B64 7F01E034 02202025 */  move  $a0, $s1
/* 052B68 7F01E038 AC410000 */  sw    $at, ($v0)
/* 052B6C 7F01E03C 8D2B0004 */  lw    $t3, 4($t1)
/* 052B70 7F01E040 AC4B0004 */  sw    $t3, 4($v0)
/* 052B74 7F01E044 8D210008 */  lw    $at, 8($t1)
/* 052B78 7F01E048 8C4D0004 */  lw    $t5, 4($v0)
/* 052B7C 7F01E04C AC410008 */  sw    $at, 8($v0)
/* 052B80 7F01E050 8D2B000C */  lw    $t3, 0xc($t1)
/* 052B84 7F01E054 AC4B000C */  sw    $t3, 0xc($v0)
/* 052B88 7F01E058 8D210010 */  lw    $at, 0x10($t1)
/* 052B8C 7F01E05C AC410010 */  sw    $at, 0x10($v0)
/* 052B90 7F01E060 8D2B0014 */  lw    $t3, 0x14($t1)
/* 052B94 7F01E064 AC4B0014 */  sw    $t3, 0x14($v0)
/* 052B98 7F01E068 8D210018 */  lw    $at, 0x18($t1)
/* 052B9C 7F01E06C AC410018 */  sw    $at, 0x18($v0)
/* 052BA0 7F01E070 8C410000 */  lw    $at, ($v0)
/* 052BA4 7F01E074 8D2B001C */  lw    $t3, 0x1c($t1)
/* 052BA8 7F01E078 AE2D0004 */  sw    $t5, 4($s1)
/* 052BAC 7F01E07C AE210000 */  sw    $at, ($s1)
/* 052BB0 7F01E080 8C410008 */  lw    $at, 8($v0)
/* 052BB4 7F01E084 8C4D000C */  lw    $t5, 0xc($v0)
/* 052BB8 7F01E088 AC4B001C */  sw    $t3, 0x1c($v0)
/* 052BBC 7F01E08C AE210008 */  sw    $at, 8($s1)
/* 052BC0 7F01E090 8C410010 */  lw    $at, 0x10($v0)
/* 052BC4 7F01E094 AE2D000C */  sw    $t5, 0xc($s1)
/* 052BC8 7F01E098 8C4D0014 */  lw    $t5, 0x14($v0)
/* 052BCC 7F01E09C AE210010 */  sw    $at, 0x10($s1)
/* 052BD0 7F01E0A0 8C410018 */  lw    $at, 0x18($v0)
/* 052BD4 7F01E0A4 AE2B001C */  sw    $t3, 0x1c($s1)
/* 052BD8 7F01E0A8 AE2D0014 */  sw    $t5, 0x14($s1)
/* 052BDC 7F01E0AC 0FC075D6 */  jal   sub_GAME_7F01D758
/* 052BE0 7F01E0B0 AE210018 */   sw    $at, 0x18($s1)
.L7F01E0B4:
/* 052BE4 7F01E0B4 3C058007 */  lui   $a1, %hi(save1)
/* 052BE8 7F01E0B8 24A59920 */  addiu $a1, %lo(save1) # addiu $a1, $a1, -0x66e0
/* 052BEC 7F01E0BC 24040004 */  li    $a0, 4
/* 052BF0 7F01E0C0 0C0031EF */  jal   joyGamePakLongRead
/* 052BF4 7F01E0C4 240601E0 */   li    $a2, 480
/* 052BF8 7F01E0C8 3C108007 */  lui   $s0, %hi(save1)
/* 052BFC 7F01E0CC 3C138007 */  lui   $s3, %hi(save1+8)
/* 052C00 7F01E0D0 3C128007 */  lui   $s2, %hi(save2)
/* 052C04 7F01E0D4 3C148007 */  lui   $s4, %hi(dword_CODE_bss_80069B60)
/* 052C08 7F01E0D8 26949B60 */  addiu $s4, %lo(dword_CODE_bss_80069B60) # addiu $s4, $s4, -0x64a0
/* 052C0C 7F01E0DC 26529980 */  addiu $s2, %lo(save2) # addiu $s2, $s2, -0x6680
/* 052C10 7F01E0E0 26739928 */  addiu $s3, %lo(save1+8) # addiu $s3, $s3, -0x66d8
/* 052C14 7F01E0E4 26109920 */  addiu $s0, %lo(save1) # addiu $s0, $s0, -0x66e0
.L7F01E0E8:
/* 052C18 7F01E0E8 24110001 */  li    $s1, 1
/* 052C1C 7F01E0EC 02602025 */  move  $a0, $s3
/* 052C20 7F01E0F0 02402825 */  move  $a1, $s2
/* 052C24 7F01E0F4 0FC26D80 */  jal   sub_GAME_7F09B600
/* 052C28 7F01E0F8 02A03025 */   move  $a2, $s5
/* 052C2C 7F01E0FC 8FAE008C */  lw    $t6, 0x8c($sp)
/* 052C30 7F01E100 8E0F0000 */  lw    $t7, ($s0)
/* 052C34 7F01E104 8FB80090 */  lw    $t8, 0x90($sp)
/* 052C38 7F01E108 55CF0005 */  bnel  $t6, $t7, .L7F01E120
/* 052C3C 7F01E10C 00008825 */   move  $s1, $zero
/* 052C40 7F01E110 8E190004 */  lw    $t9, 4($s0)
/* 052C44 7F01E114 13190002 */  beq   $t8, $t9, .L7F01E120
/* 052C48 7F01E118 00000000 */   nop   
/* 052C4C 7F01E11C 00008825 */  move  $s1, $zero
.L7F01E120:
/* 052C50 7F01E120 56200004 */  bnezl $s1, .L7F01E134
/* 052C54 7F01E124 26520060 */   addiu $s2, $s2, 0x60
/* 052C58 7F01E128 0FC07610 */  jal   sub_GAME_7F01D840
/* 052C5C 7F01E12C 02002025 */   move  $a0, $s0
/* 052C60 7F01E130 26520060 */  addiu $s2, $s2, 0x60
.L7F01E134:
/* 052C64 7F01E134 26100060 */  addiu $s0, $s0, 0x60
/* 052C68 7F01E138 1654FFEB */  bne   $s2, $s4, .L7F01E0E8
/* 052C6C 7F01E13C 26730060 */   addiu $s3, $s3, 0x60
/* 052C70 7F01E140 0000B025 */  move  $s6, $zero
/* 052C74 7F01E144 241E0060 */  li    $fp, 96
/* 052C78 7F01E148 24170005 */  li    $s7, 5
.L7F01E14C:
/* 052C7C 7F01E14C 3C108007 */  lui   $s0, %hi(save1)
/* 052C80 7F01E150 2414FFFF */  li    $s4, -1
/* 052C84 7F01E154 2415FFFF */  li    $s5, -1
/* 052C88 7F01E158 26109920 */  addiu $s0, %lo(save1) # addiu $s0, $s0, -0x66e0
/* 052C8C 7F01E15C 00008825 */  move  $s1, $zero
.L7F01E160:
/* 052C90 7F01E160 0FC07655 */  jal   check_if_eeprom_flag_set_0x80
/* 052C94 7F01E164 02002025 */   move  $a0, $s0
/* 052C98 7F01E168 54400023 */  bnezl $v0, .L7F01E1F8
/* 052C9C 7F01E16C 26310001 */   addiu $s1, $s1, 1
/* 052CA0 7F01E170 0FC07632 */  jal   get_foldernum_of_eeprom
/* 052CA4 7F01E174 02002025 */   move  $a0, $s0
/* 052CA8 7F01E178 5456001F */  bnel  $v0, $s6, .L7F01E1F8
/* 052CAC 7F01E17C 26310001 */   addiu $s1, $s1, 1
/* 052CB0 7F01E180 06810006 */  bgez  $s4, .L7F01E19C
/* 052CB4 7F01E184 02002025 */   move  $a0, $s0
/* 052CB8 7F01E188 0220A025 */  move  $s4, $s1
/* 052CBC 7F01E18C 0FC0763D */  jal   set_eeprom_flag_0x18
/* 052CC0 7F01E190 02002025 */   move  $a0, $s0
/* 052CC4 7F01E194 10000017 */  b     .L7F01E1F4
/* 052CC8 7F01E198 0040A825 */   move  $s5, $v0
.L7F01E19C:
/* 052CCC 7F01E19C 26B30001 */  addiu $s3, $s5, 1
/* 052CD0 7F01E1A0 06610004 */  bgez  $s3, .L7F01E1B4
/* 052CD4 7F01E1A4 32680003 */   andi  $t0, $s3, 3
/* 052CD8 7F01E1A8 11000002 */  beqz  $t0, .L7F01E1B4
/* 052CDC 7F01E1AC 00000000 */   nop   
/* 052CE0 7F01E1B0 2508FFFC */  addiu $t0, $t0, -4
.L7F01E1B4:
/* 052CE4 7F01E1B4 0FC0763D */  jal   set_eeprom_flag_0x18
/* 052CE8 7F01E1B8 01009825 */   move  $s3, $t0
/* 052CEC 7F01E1BC 1453000B */  bne   $v0, $s3, .L7F01E1EC
/* 052CF0 7F01E1C0 00409025 */   move  $s2, $v0
/* 052CF4 7F01E1C4 029E0019 */  multu $s4, $fp
/* 052CF8 7F01E1C8 3C098007 */  lui   $t1, %hi(save1) 
/* 052CFC 7F01E1CC 25299920 */  addiu $t1, %lo(save1) # addiu $t1, $t1, -0x66e0
/* 052D00 7F01E1D0 00005012 */  mflo  $t2
/* 052D04 7F01E1D4 01492021 */  addu  $a0, $t2, $t1
/* 052D08 7F01E1D8 0FC07610 */  jal   sub_GAME_7F01D840
/* 052D0C 7F01E1DC 00000000 */   nop   
/* 052D10 7F01E1E0 0220A025 */  move  $s4, $s1
/* 052D14 7F01E1E4 10000003 */  b     .L7F01E1F4
/* 052D18 7F01E1E8 0240A825 */   move  $s5, $s2
.L7F01E1EC:
/* 052D1C 7F01E1EC 0FC07610 */  jal   sub_GAME_7F01D840
/* 052D20 7F01E1F0 02002025 */   move  $a0, $s0
.L7F01E1F4:
/* 052D24 7F01E1F4 26310001 */  addiu $s1, $s1, 1
.L7F01E1F8:
/* 052D28 7F01E1F8 1637FFD9 */  bne   $s1, $s7, .L7F01E160
/* 052D2C 7F01E1FC 26100060 */   addiu $s0, $s0, 0x60
/* 052D30 7F01E200 06830004 */  bgezl $s4, .L7F01E214
/* 052D34 7F01E204 26D60001 */   addiu $s6, $s6, 1
/* 052D38 7F01E208 0FC077AD */  jal   sub_GAME_7F01DEB4
/* 052D3C 7F01E20C 02C02025 */   move  $a0, $s6
/* 052D40 7F01E210 26D60001 */  addiu $s6, $s6, 1
.L7F01E214:
/* 052D44 7F01E214 2AC10004 */  slti  $at, $s6, 4
/* 052D48 7F01E218 1420FFCC */  bnez  $at, .L7F01E14C
/* 052D4C 7F01E21C 00000000 */   nop   
/* 052D50 7F01E220 0000B025 */  move  $s6, $zero
/* 052D54 7F01E224 24110004 */  li    $s1, 4
.L7F01E228:
/* 052D58 7F01E228 0FC07771 */  jal   get_save_folder_ptr
/* 052D5C 7F01E22C 02C02025 */   move  $a0, $s6
/* 052D60 7F01E230 10400007 */  beqz  $v0, .L7F01E250
/* 052D64 7F01E234 00402025 */   move  $a0, $v0
/* 052D68 7F01E238 3C0C8003 */  lui   $t4, %hi(save_selected_bond) 
/* 052D6C 7F01E23C 258CC510 */  addiu $t4, %lo(save_selected_bond) # addiu $t4, $t4, -0x3af0
/* 052D70 7F01E240 00165880 */  sll   $t3, $s6, 2
/* 052D74 7F01E244 0FC07649 */  jal   get_selected_bond
/* 052D78 7F01E248 016C8021 */   addu  $s0, $t3, $t4
/* 052D7C 7F01E24C AE020000 */  sw    $v0, ($s0)
.L7F01E250:
/* 052D80 7F01E250 26D60001 */  addiu $s6, $s6, 1
/* 052D84 7F01E254 16D1FFF4 */  bne   $s6, $s1, .L7F01E228
/* 052D88 7F01E258 00000000 */   nop   
.L7F01E25C:
/* 052D8C 7F01E25C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 052D90 7F01E260 8FB00018 */  lw    $s0, 0x18($sp)
/* 052D94 7F01E264 8FB1001C */  lw    $s1, 0x1c($sp)
/* 052D98 7F01E268 8FB20020 */  lw    $s2, 0x20($sp)
/* 052D9C 7F01E26C 8FB30024 */  lw    $s3, 0x24($sp)
/* 052DA0 7F01E270 8FB40028 */  lw    $s4, 0x28($sp)
/* 052DA4 7F01E274 8FB5002C */  lw    $s5, 0x2c($sp)
/* 052DA8 7F01E278 8FB60030 */  lw    $s6, 0x30($sp)
/* 052DAC 7F01E27C 8FB70034 */  lw    $s7, 0x34($sp)
/* 052DB0 7F01E280 8FBE0038 */  lw    $fp, 0x38($sp)
/* 052DB4 7F01E284 03E00008 */  jr    $ra
/* 052DB8 7F01E288 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif



s32 check_if_valid_folder_num(s32 folder)
{
    if ((folder >= 0) && (folder < 4))
    {
        return 1;
    }
    if (folder == 100)
    {
        return 1;
    }
    return 0;
}



#ifdef NONMATCHING
s32 isStageUnlockedAtDifficulty(int foldernum,STAGENUM stageid,DIFFICULTY difficulty) {

}
#else
GLOBAL_ASM(
.text
glabel isStageUnlockedAtDifficulty
/* 052DF0 7F01E2C0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 052DF4 7F01E2C4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 052DF8 7F01E2C8 AFB50028 */  sw    $s5, 0x28($sp)
/* 052DFC 7F01E2CC AFB30020 */  sw    $s3, 0x20($sp)
/* 052E00 7F01E2D0 AFB00014 */  sw    $s0, 0x14($sp)
/* 052E04 7F01E2D4 00808025 */  move  $s0, $a0
/* 052E08 7F01E2D8 00A09825 */  move  $s3, $a1
/* 052E0C 7F01E2DC 00C0A825 */  move  $s5, $a2
/* 052E10 7F01E2E0 AFB40024 */  sw    $s4, 0x24($sp)
/* 052E14 7F01E2E4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 052E18 7F01E2E8 0FC078A3 */  jal   check_if_valid_folder_num
/* 052E1C 7F01E2EC AFB10018 */   sw    $s1, 0x18($sp)
/* 052E20 7F01E2F0 5040007B */  beql  $v0, $zero, .L7F01E4E0
/* 052E24 7F01E2F4 00001025 */   move  $v0, $zero
/* 052E28 7F01E2F8 06600078 */  bltz  $s3, .L7F01E4DC
/* 052E2C 7F01E2FC 2A610014 */   slti  $at, $s3, 0x14
/* 052E30 7F01E300 50200077 */  beql  $at, $zero, .L7F01E4E0
/* 052E34 7F01E304 00001025 */   move  $v0, $zero
/* 052E38 7F01E308 06A00074 */  bltz  $s5, .L7F01E4DC
/* 052E3C 7F01E30C 2AA10004 */   slti  $at, $s5, 4
/* 052E40 7F01E310 50200073 */  beql  $at, $zero, .L7F01E4E0
/* 052E44 7F01E314 00001025 */   move  $v0, $zero
/* 052E48 7F01E318 0FC07771 */  jal   get_save_folder_ptr
/* 052E4C 7F01E31C 02002025 */   move  $a0, $s0
/* 052E50 7F01E320 1040005C */  beqz  $v0, .L7F01E494
/* 052E54 7F01E324 00409025 */   move  $s2, $v0
/* 052E58 7F01E328 00402025 */  move  $a0, $v0
/* 052E5C 7F01E32C 02602825 */  move  $a1, $s3
/* 052E60 7F01E330 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052E64 7F01E334 02A03025 */   move  $a2, $s5
/* 052E68 7F01E338 10400003 */  beqz  $v0, .L7F01E348
/* 052E6C 7F01E33C 24010012 */   li    $at, 18
/* 052E70 7F01E340 10000067 */  b     .L7F01E4E0
/* 052E74 7F01E344 24020003 */   li    $v0, 3
.L7F01E348:
/* 052E78 7F01E348 56610003 */  bnel  $s3, $at, .L7F01E358
/* 052E7C 7F01E34C 24010013 */   li    $at, 19
/* 052E80 7F01E350 1AA00005 */  blez  $s5, .L7F01E368
/* 052E84 7F01E354 24010013 */   li    $at, 19
.L7F01E358:
/* 052E88 7F01E358 16610005 */  bne   $s3, $at, .L7F01E370
/* 052E8C 7F01E35C 2AA10002 */   slti  $at, $s5, 2
/* 052E90 7F01E360 50200004 */  beql  $at, $zero, .L7F01E374
/* 052E94 7F01E364 2AA10004 */   slti  $at, $s5, 4
.L7F01E368:
/* 052E98 7F01E368 1000005D */  b     .L7F01E4E0
/* 052E9C 7F01E36C 00001025 */   move  $v0, $zero
.L7F01E370:
/* 052EA0 7F01E370 2AA10004 */  slti  $at, $s5, 4
.L7F01E374:
/* 052EA4 7F01E374 10200014 */  beqz  $at, .L7F01E3C8
/* 052EA8 7F01E378 02A08825 */   move  $s1, $s5
/* 052EAC 7F01E37C 24140004 */  li    $s4, 4
.L7F01E380:
/* 052EB0 7F01E380 1A60000A */  blez  $s3, .L7F01E3AC
/* 052EB4 7F01E384 00008025 */   move  $s0, $zero
/* 052EB8 7F01E388 02402025 */  move  $a0, $s2
.L7F01E38C:
/* 052EBC 7F01E38C 02002825 */  move  $a1, $s0
/* 052EC0 7F01E390 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052EC4 7F01E394 02203025 */   move  $a2, $s1
/* 052EC8 7F01E398 50400005 */  beql  $v0, $zero, .L7F01E3B0
/* 052ECC 7F01E39C 0213082A */   slt   $at, $s0, $s3
/* 052ED0 7F01E3A0 26100001 */  addiu $s0, $s0, 1
/* 052ED4 7F01E3A4 5613FFF9 */  bnel  $s0, $s3, .L7F01E38C
/* 052ED8 7F01E3A8 02402025 */   move  $a0, $s2
.L7F01E3AC:
/* 052EDC 7F01E3AC 0213082A */  slt   $at, $s0, $s3
.L7F01E3B0:
/* 052EE0 7F01E3B0 14200003 */  bnez  $at, .L7F01E3C0
/* 052EE4 7F01E3B4 26310001 */   addiu $s1, $s1, 1
/* 052EE8 7F01E3B8 10000049 */  b     .L7F01E4E0
/* 052EEC 7F01E3BC 24020001 */   li    $v0, 1
.L7F01E3C0:
/* 052EF0 7F01E3C0 1634FFEF */  bne   $s1, $s4, .L7F01E380
/* 052EF4 7F01E3C4 00000000 */   nop   
.L7F01E3C8:
/* 052EF8 7F01E3C8 2AA10003 */  slti  $at, $s5, 3
/* 052EFC 7F01E3CC 10200011 */  beqz  $at, .L7F01E414
/* 052F00 7F01E3D0 24140004 */   li    $s4, 4
/* 052F04 7F01E3D4 2A610012 */  slti  $at, $s3, 0x12
/* 052F08 7F01E3D8 1020000E */  beqz  $at, .L7F01E414
/* 052F0C 7F01E3DC 2AA10004 */   slti  $at, $s5, 4
/* 052F10 7F01E3E0 1020000C */  beqz  $at, .L7F01E414
/* 052F14 7F01E3E4 02A08825 */   move  $s1, $s5
/* 052F18 7F01E3E8 2670FFFF */  addiu $s0, $s3, -1
/* 052F1C 7F01E3EC 02402025 */  move  $a0, $s2
.L7F01E3F0:
/* 052F20 7F01E3F0 02002825 */  move  $a1, $s0
/* 052F24 7F01E3F4 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052F28 7F01E3F8 02203025 */   move  $a2, $s1
/* 052F2C 7F01E3FC 10400003 */  beqz  $v0, .L7F01E40C
/* 052F30 7F01E400 26310001 */   addiu $s1, $s1, 1
/* 052F34 7F01E404 10000036 */  b     .L7F01E4E0
/* 052F38 7F01E408 24020001 */   li    $v0, 1
.L7F01E40C:
/* 052F3C 7F01E40C 5634FFF8 */  bnel  $s1, $s4, .L7F01E3F0
/* 052F40 7F01E410 02402025 */   move  $a0, $s2
.L7F01E414:
/* 052F44 7F01E414 2AA10003 */  slti  $at, $s5, 3
/* 052F48 7F01E418 1020001E */  beqz  $at, .L7F01E494
/* 052F4C 7F01E41C 00008825 */   move  $s1, $zero
/* 052F50 7F01E420 02402025 */  move  $a0, $s2
.L7F01E424:
/* 052F54 7F01E424 02202825 */  move  $a1, $s1
/* 052F58 7F01E428 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052F5C 7F01E42C 00003025 */   move  $a2, $zero
/* 052F60 7F01E430 50400006 */  beql  $v0, $zero, .L7F01E44C
/* 052F64 7F01E434 2A210012 */   slti  $at, $s1, 0x12
/* 052F68 7F01E438 26310001 */  addiu $s1, $s1, 1
/* 052F6C 7F01E43C 2A210012 */  slti  $at, $s1, 0x12
/* 052F70 7F01E440 5420FFF8 */  bnezl $at, .L7F01E424
/* 052F74 7F01E444 02402025 */   move  $a0, $s2
/* 052F78 7F01E448 2A210012 */  slti  $at, $s1, 0x12
.L7F01E44C:
/* 052F7C 7F01E44C 14200011 */  bnez  $at, .L7F01E494
/* 052F80 7F01E450 00000000 */   nop   
/* 052F84 7F01E454 1AA0000A */  blez  $s5, .L7F01E480
/* 052F88 7F01E458 00008825 */   move  $s1, $zero
/* 052F8C 7F01E45C 02402025 */  move  $a0, $s2
.L7F01E460:
/* 052F90 7F01E460 02602825 */  move  $a1, $s3
/* 052F94 7F01E464 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 052F98 7F01E468 02203025 */   move  $a2, $s1
/* 052F9C 7F01E46C 50400005 */  beql  $v0, $zero, .L7F01E484
/* 052FA0 7F01E470 0235082A */   slt   $at, $s1, $s5
/* 052FA4 7F01E474 26310001 */  addiu $s1, $s1, 1
/* 052FA8 7F01E478 5635FFF9 */  bnel  $s1, $s5, .L7F01E460
/* 052FAC 7F01E47C 02402025 */   move  $a0, $s2
.L7F01E480:
/* 052FB0 7F01E480 0235082A */  slt   $at, $s1, $s5
.L7F01E484:
/* 052FB4 7F01E484 14200003 */  bnez  $at, .L7F01E494
/* 052FB8 7F01E488 00000000 */   nop   
/* 052FBC 7F01E48C 10000014 */  b     .L7F01E4E0
/* 052FC0 7F01E490 24020001 */   li    $v0, 1
.L7F01E494:
/* 052FC4 7F01E494 16600003 */  bnez  $s3, .L7F01E4A4
/* 052FC8 7F01E498 00000000 */   nop   
/* 052FCC 7F01E49C 10000010 */  b     .L7F01E4E0
/* 052FD0 7F01E4A0 24020001 */   li    $v0, 1
.L7F01E4A4:
/* 052FD4 7F01E4A4 0FC24400 */  jal   get_debug_enable_agent_levels_flag
/* 052FD8 7F01E4A8 00000000 */   nop   
/* 052FDC 7F01E4AC 10400005 */  beqz  $v0, .L7F01E4C4
/* 052FE0 7F01E4B0 00000000 */   nop   
/* 052FE4 7F01E4B4 16A00003 */  bnez  $s5, .L7F01E4C4
/* 052FE8 7F01E4B8 00000000 */   nop   
/* 052FEC 7F01E4BC 10000008 */  b     .L7F01E4E0
/* 052FF0 7F01E4C0 24020001 */   li    $v0, 1
.L7F01E4C4:
/* 052FF4 7F01E4C4 0FC24403 */  jal   get_debug_enable_all_levels_flag
/* 052FF8 7F01E4C8 00000000 */   nop   
/* 052FFC 7F01E4CC 50400004 */  beql  $v0, $zero, .L7F01E4E0
/* 053000 7F01E4D0 00001025 */   move  $v0, $zero
/* 053004 7F01E4D4 10000002 */  b     .L7F01E4E0
/* 053008 7F01E4D8 24020001 */   li    $v0, 1
.L7F01E4DC:
/* 05300C 7F01E4DC 00001025 */  move  $v0, $zero
.L7F01E4E0:
/* 053010 7F01E4E0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 053014 7F01E4E4 8FB00014 */  lw    $s0, 0x14($sp)
/* 053018 7F01E4E8 8FB10018 */  lw    $s1, 0x18($sp)
/* 05301C 7F01E4EC 8FB2001C */  lw    $s2, 0x1c($sp)
/* 053020 7F01E4F0 8FB30020 */  lw    $s3, 0x20($sp)
/* 053024 7F01E4F4 8FB40024 */  lw    $s4, 0x24($sp)
/* 053028 7F01E4F8 8FB50028 */  lw    $s5, 0x28($sp)
/* 05302C 7F01E4FC 03E00008 */  jr    $ra
/* 053030 7F01E500 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01E504(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01E504
/* 053034 7F01E504 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 053038 7F01E508 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05303C 7F01E50C AFA40028 */  sw    $a0, 0x28($sp)
/* 053040 7F01E510 AFA5002C */  sw    $a1, 0x2c($sp)
/* 053044 7F01E514 0FC07794 */  jal   sub_GAME_7F01DE50
/* 053048 7F01E518 AFA00020 */   sw    $zero, 0x20($sp)
/* 05304C 7F01E51C 04400032 */  bltz  $v0, .L7F01E5E8
/* 053050 7F01E520 00401825 */   move  $v1, $v0
/* 053054 7F01E524 8FB9002C */  lw    $t9, 0x2c($sp)
/* 053058 7F01E528 00027080 */  sll   $t6, $v0, 2
/* 05305C 7F01E52C 01C27023 */  subu  $t6, $t6, $v0
/* 053060 7F01E530 3C0F8007 */  lui   $t7, %hi(save1) 
/* 053064 7F01E534 25EF9920 */  addiu $t7, %lo(save1) # addiu $t7, $t7, -0x66e0
/* 053068 7F01E538 000E7140 */  sll   $t6, $t6, 5
/* 05306C 7F01E53C 01CFC021 */  addu  $t8, $t6, $t7
/* 053070 7F01E540 27290060 */  addiu $t1, $t9, 0x60
.L7F01E544:
/* 053074 7F01E544 8F210000 */  lw    $at, ($t9)
/* 053078 7F01E548 2739000C */  addiu $t9, $t9, 0xc
/* 05307C 7F01E54C 2718000C */  addiu $t8, $t8, 0xc
/* 053080 7F01E550 AF01FFF4 */  sw    $at, -0xc($t8)
/* 053084 7F01E554 8F21FFF8 */  lw    $at, -8($t9)
/* 053088 7F01E558 AF01FFF8 */  sw    $at, -8($t8)
/* 05308C 7F01E55C 8F21FFFC */  lw    $at, -4($t9)
/* 053090 7F01E560 1729FFF8 */  bne   $t9, $t1, .L7F01E544
/* 053094 7F01E564 AF01FFFC */   sw    $at, -4($t8)
/* 053098 7F01E568 8FAA0028 */  lw    $t2, 0x28($sp)
/* 05309C 7F01E56C 1140000B */  beqz  $t2, .L7F01E59C
/* 0530A0 7F01E570 01402025 */   move  $a0, $t2
/* 0530A4 7F01E574 0FC0763D */  jal   set_eeprom_flag_0x18
/* 0530A8 7F01E578 AFA30024 */   sw    $v1, 0x24($sp)
/* 0530AC 7F01E57C 244B0001 */  addiu $t3, $v0, 1
/* 0530B0 7F01E580 8FA30024 */  lw    $v1, 0x24($sp)
/* 0530B4 7F01E584 05610004 */  bgez  $t3, .L7F01E598
/* 0530B8 7F01E588 316C0003 */   andi  $t4, $t3, 3
/* 0530BC 7F01E58C 11800002 */  beqz  $t4, .L7F01E598
/* 0530C0 7F01E590 00000000 */   nop   
/* 0530C4 7F01E594 258CFFFC */  addiu $t4, $t4, -4
.L7F01E598:
/* 0530C8 7F01E598 AFAC0020 */  sw    $t4, 0x20($sp)
.L7F01E59C:
/* 0530CC 7F01E59C 00036880 */  sll   $t5, $v1, 2
/* 0530D0 7F01E5A0 01A36823 */  subu  $t5, $t5, $v1
/* 0530D4 7F01E5A4 3C0E8007 */  lui   $t6, %hi(save1) 
/* 0530D8 7F01E5A8 25CE9920 */  addiu $t6, %lo(save1) # addiu $t6, $t6, -0x66e0
/* 0530DC 7F01E5AC 000D6940 */  sll   $t5, $t5, 5
/* 0530E0 7F01E5B0 01AE2021 */  addu  $a0, $t5, $t6
/* 0530E4 7F01E5B4 AFA4001C */  sw    $a0, 0x1c($sp)
/* 0530E8 7F01E5B8 0FC07659 */  jal   toggle_eeprom_flag_set_0x80
/* 0530EC 7F01E5BC 00002825 */   move  $a1, $zero
/* 0530F0 7F01E5C0 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0530F4 7F01E5C4 0FC07641 */  jal   reset_eeprom_flag_0x18
/* 0530F8 7F01E5C8 8FA50020 */   lw    $a1, 0x20($sp)
/* 0530FC 7F01E5CC 0FC075E8 */  jal   sub_GAME_7F01D7A0
/* 053100 7F01E5D0 8FA4001C */   lw    $a0, 0x1c($sp)
/* 053104 7F01E5D4 8FAF0028 */  lw    $t7, 0x28($sp)
/* 053108 7F01E5D8 51E00004 */  beql  $t7, $zero, .L7F01E5EC
/* 05310C 7F01E5DC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 053110 7F01E5E0 0FC07610 */  jal   sub_GAME_7F01D840
/* 053114 7F01E5E4 01E02025 */   move  $a0, $t7
.L7F01E5E8:
/* 053118 7F01E5E8 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01E5EC:
/* 05311C 7F01E5EC 27BD0028 */  addiu $sp, $sp, 0x28
/* 053120 7F01E5F0 03E00008 */  jr    $ra
/* 053124 7F01E5F4 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void unlock_stage_in_folder_on_difficulty(void) {

}
#else
GLOBAL_ASM(
.text
glabel unlock_stage_in_folder_on_difficulty
/* 053128 7F01E5F8 27BDFF68 */  addiu $sp, $sp, -0x98
/* 05312C 7F01E5FC AFB50028 */  sw    $s5, 0x28($sp)
/* 053130 7F01E600 AFB40024 */  sw    $s4, 0x24($sp)
/* 053134 7F01E604 AFB2001C */  sw    $s2, 0x1c($sp)
/* 053138 7F01E608 AFB00014 */  sw    $s0, 0x14($sp)
/* 05313C 7F01E60C 00808025 */  move  $s0, $a0
/* 053140 7F01E610 00A09025 */  move  $s2, $a1
/* 053144 7F01E614 00C0A025 */  move  $s4, $a2
/* 053148 7F01E618 00E0A825 */  move  $s5, $a3
/* 05314C 7F01E61C AFBF002C */  sw    $ra, 0x2c($sp)
/* 053150 7F01E620 AFB30020 */  sw    $s3, 0x20($sp)
/* 053154 7F01E624 04800045 */  bltz  $a0, .L7F01E73C
/* 053158 7F01E628 AFB10018 */   sw    $s1, 0x18($sp)
/* 05315C 7F01E62C 28810004 */  slti  $at, $a0, 4
/* 053160 7F01E630 50200043 */  beql  $at, $zero, .L7F01E740
/* 053164 7F01E634 8FBF002C */   lw    $ra, 0x2c($sp)
/* 053168 7F01E638 04A00040 */  bltz  $a1, .L7F01E73C
/* 05316C 7F01E63C 28A10014 */   slti  $at, $a1, 0x14
/* 053170 7F01E640 5020003F */  beql  $at, $zero, .L7F01E740
/* 053174 7F01E644 8FBF002C */   lw    $ra, 0x2c($sp)
/* 053178 7F01E648 04C0003C */  bltz  $a2, .L7F01E73C
/* 05317C 7F01E64C 28C10004 */   slti  $at, $a2, 4
/* 053180 7F01E650 1020003A */  beqz  $at, .L7F01E73C
/* 053184 7F01E654 27B10038 */   addiu $s1, $sp, 0x38
/* 053188 7F01E658 3C0E8003 */  lui   $t6, %hi(D_8002C640+0x20) 
/* 05318C 7F01E65C 25CEC660 */  addiu $t6, %lo(D_8002C640+0x20) # addiu $t6, $t6, -0x39a0
/* 053190 7F01E660 25D80060 */  addiu $t8, $t6, 0x60
/* 053194 7F01E664 0220C825 */  move  $t9, $s1
.L7F01E668:
/* 053198 7F01E668 8DC10000 */  lw    $at, ($t6)
/* 05319C 7F01E66C 25CE000C */  addiu $t6, $t6, 0xc
/* 0531A0 7F01E670 2739000C */  addiu $t9, $t9, 0xc
/* 0531A4 7F01E674 AF21FFF4 */  sw    $at, -0xc($t9)
/* 0531A8 7F01E678 8DC1FFF8 */  lw    $at, -8($t6)
/* 0531AC 7F01E67C AF21FFF8 */  sw    $at, -8($t9)
/* 0531B0 7F01E680 8DC1FFFC */  lw    $at, -4($t6)
/* 0531B4 7F01E684 15D8FFF8 */  bne   $t6, $t8, .L7F01E668
/* 0531B8 7F01E688 AF21FFFC */   sw    $at, -4($t9)
/* 0531BC 7F01E68C 0FC07771 */  jal   get_save_folder_ptr
/* 0531C0 7F01E690 02002025 */   move  $a0, $s0
/* 0531C4 7F01E694 1040000F */  beqz  $v0, .L7F01E6D4
/* 0531C8 7F01E698 AFA20034 */   sw    $v0, 0x34($sp)
/* 0531CC 7F01E69C 00405025 */  move  $t2, $v0
/* 0531D0 7F01E6A0 02205825 */  move  $t3, $s1
/* 0531D4 7F01E6A4 24490060 */  addiu $t1, $v0, 0x60
.L7F01E6A8:
/* 0531D8 7F01E6A8 8D410000 */  lw    $at, ($t2)
/* 0531DC 7F01E6AC 254A000C */  addiu $t2, $t2, 0xc
/* 0531E0 7F01E6B0 256B000C */  addiu $t3, $t3, 0xc
/* 0531E4 7F01E6B4 AD61FFF4 */  sw    $at, -0xc($t3)
/* 0531E8 7F01E6B8 8D41FFF8 */  lw    $at, -8($t2)
/* 0531EC 7F01E6BC AD61FFF8 */  sw    $at, -8($t3)
/* 0531F0 7F01E6C0 8D41FFFC */  lw    $at, -4($t2)
/* 0531F4 7F01E6C4 1549FFF8 */  bne   $t2, $t1, .L7F01E6A8
/* 0531F8 7F01E6C8 AD61FFFC */   sw    $at, -4($t3)
/* 0531FC 7F01E6CC 10000004 */  b     .L7F01E6E0
/* 053200 7F01E6D0 00000000 */   nop   
.L7F01E6D4:
/* 053204 7F01E6D4 02202025 */  move  $a0, $s1
/* 053208 7F01E6D8 0FC07636 */  jal   set_eeprom_to_folder_num
/* 05320C 7F01E6DC 02002825 */   move  $a1, $s0
.L7F01E6E0:
/* 053210 7F01E6E0 06800013 */  bltz  $s4, .L7F01E730
/* 053214 7F01E6E4 02808025 */   move  $s0, $s4
/* 053218 7F01E6E8 3C1305F5 */  lui   $s3, (0x05F5E0FF >> 16) # lui $s3, 0x5f5
/* 05321C 7F01E6EC 3673E0FF */  ori   $s3, (0x05F5E0FF & 0xFFFF) # ori $s3, $s3, 0xe0ff
.L7F01E6F0:
/* 053220 7F01E6F0 16140008 */  bne   $s0, $s4, .L7F01E714
/* 053224 7F01E6F4 02202025 */   move  $a0, $s1
/* 053228 7F01E6F8 02202025 */  move  $a0, $s1
/* 05322C 7F01E6FC 02402825 */  move  $a1, $s2
/* 053230 7F01E700 02003025 */  move  $a2, $s0
/* 053234 7F01E704 0FC0772C */  jal   sub_GAME_7F01DCB0
/* 053238 7F01E708 02A03825 */   move  $a3, $s5
/* 05323C 7F01E70C 10000006 */  b     .L7F01E728
/* 053240 7F01E710 2610FFFF */   addiu $s0, $s0, -1
.L7F01E714:
/* 053244 7F01E714 02402825 */  move  $a1, $s2
/* 053248 7F01E718 02003025 */  move  $a2, $s0
/* 05324C 7F01E71C 0FC0772C */  jal   sub_GAME_7F01DCB0
/* 053250 7F01E720 02603825 */   move  $a3, $s3
/* 053254 7F01E724 2610FFFF */  addiu $s0, $s0, -1
.L7F01E728:
/* 053258 7F01E728 0601FFF1 */  bgez  $s0, .L7F01E6F0
/* 05325C 7F01E72C 00000000 */   nop   
.L7F01E730:
/* 053260 7F01E730 8FA40034 */  lw    $a0, 0x34($sp)
/* 053264 7F01E734 0FC07941 */  jal   sub_GAME_7F01E504
/* 053268 7F01E738 02202825 */   move  $a1, $s1
.L7F01E73C:
/* 05326C 7F01E73C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F01E740:
/* 053270 7F01E740 8FB00014 */  lw    $s0, 0x14($sp)
/* 053274 7F01E744 8FB10018 */  lw    $s1, 0x18($sp)
/* 053278 7F01E748 8FB2001C */  lw    $s2, 0x1c($sp)
/* 05327C 7F01E74C 8FB30020 */  lw    $s3, 0x20($sp)
/* 053280 7F01E750 8FB40024 */  lw    $s4, 0x24($sp)
/* 053284 7F01E754 8FB50028 */  lw    $s5, 0x28($sp)
/* 053288 7F01E758 03E00008 */  jr    $ra
/* 05328C 7F01E75C 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01E760(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01E760
/* 053290 7F01E760 27BDFF80 */  addiu $sp, $sp, -0x80
/* 053294 7F01E764 AFBF0014 */  sw    $ra, 0x14($sp)
/* 053298 7F01E768 0480003E */  bltz  $a0, .L7F01E864
/* 05329C 7F01E76C 00803825 */   move  $a3, $a0
/* 0532A0 7F01E770 28810004 */  slti  $at, $a0, 4
/* 0532A4 7F01E774 5020003C */  beql  $at, $zero, .L7F01E868
/* 0532A8 7F01E778 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0532AC 7F01E77C 04A00039 */  bltz  $a1, .L7F01E864
/* 0532B0 7F01E780 28A10014 */   slti  $at, $a1, 0x14
/* 0532B4 7F01E784 50200038 */  beql  $at, $zero, .L7F01E868
/* 0532B8 7F01E788 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0532BC 7F01E78C AFA50084 */  sw    $a1, 0x84($sp)
/* 0532C0 7F01E790 0FC07771 */  jal   get_save_folder_ptr
/* 0532C4 7F01E794 AFA70080 */   sw    $a3, 0x80($sp)
/* 0532C8 7F01E798 8FA70080 */  lw    $a3, 0x80($sp)
/* 0532CC 7F01E79C 10400009 */  beqz  $v0, .L7F01E7C4
/* 0532D0 7F01E7A0 00403025 */   move  $a2, $v0
/* 0532D4 7F01E7A4 00402025 */  move  $a0, $v0
/* 0532D8 7F01E7A8 8FA50084 */  lw    $a1, 0x84($sp)
/* 0532DC 7F01E7AC AFA2007C */  sw    $v0, 0x7c($sp)
/* 0532E0 7F01E7B0 0FC07748 */  jal   check_if_cheat_unlocked
/* 0532E4 7F01E7B4 AFA70080 */   sw    $a3, 0x80($sp)
/* 0532E8 7F01E7B8 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0532EC 7F01E7BC 14400029 */  bnez  $v0, .L7F01E864
/* 0532F0 7F01E7C0 8FA70080 */   lw    $a3, 0x80($sp)
.L7F01E7C4:
/* 0532F4 7F01E7C4 3C0E8003 */  lui   $t6, %hi(D_8002C6C0) 
/* 0532F8 7F01E7C8 27A4001C */  addiu $a0, $sp, 0x1c
/* 0532FC 7F01E7CC 25CEC6C0 */  addiu $t6, %lo(D_8002C6C0) # addiu $t6, $t6, -0x3940
/* 053300 7F01E7D0 25D80060 */  addiu $t8, $t6, 0x60
/* 053304 7F01E7D4 0080C825 */  move  $t9, $a0
.L7F01E7D8:
/* 053308 7F01E7D8 8DC10000 */  lw    $at, ($t6)
/* 05330C 7F01E7DC 25CE000C */  addiu $t6, $t6, 0xc
/* 053310 7F01E7E0 2739000C */  addiu $t9, $t9, 0xc
/* 053314 7F01E7E4 AF21FFF4 */  sw    $at, -0xc($t9)
/* 053318 7F01E7E8 8DC1FFF8 */  lw    $at, -8($t6)
/* 05331C 7F01E7EC AF21FFF8 */  sw    $at, -8($t9)
/* 053320 7F01E7F0 8DC1FFFC */  lw    $at, -4($t6)
/* 053324 7F01E7F4 15D8FFF8 */  bne   $t6, $t8, .L7F01E7D8
/* 053328 7F01E7F8 AF21FFFC */   sw    $at, -4($t9)
/* 05332C 7F01E7FC 10C0000F */  beqz  $a2, .L7F01E83C
/* 053330 7F01E800 00E02825 */   move  $a1, $a3
/* 053334 7F01E804 00C05025 */  move  $t2, $a2
/* 053338 7F01E808 00805825 */  move  $t3, $a0
/* 05333C 7F01E80C 24C90060 */  addiu $t1, $a2, 0x60
.L7F01E810:
/* 053340 7F01E810 8D410000 */  lw    $at, ($t2)
/* 053344 7F01E814 254A000C */  addiu $t2, $t2, 0xc
/* 053348 7F01E818 256B000C */  addiu $t3, $t3, 0xc
/* 05334C 7F01E81C AD61FFF4 */  sw    $at, -0xc($t3)
/* 053350 7F01E820 8D41FFF8 */  lw    $at, -8($t2)
/* 053354 7F01E824 AD61FFF8 */  sw    $at, -8($t3)
/* 053358 7F01E828 8D41FFFC */  lw    $at, -4($t2)
/* 05335C 7F01E82C 1549FFF8 */  bne   $t2, $t1, .L7F01E810
/* 053360 7F01E830 AD61FFFC */   sw    $at, -4($t3)
/* 053364 7F01E834 10000006 */  b     .L7F01E850
/* 053368 7F01E838 8FA50084 */   lw    $a1, 0x84($sp)
.L7F01E83C:
/* 05336C 7F01E83C 0FC07636 */  jal   set_eeprom_to_folder_num
/* 053370 7F01E840 AFA6007C */   sw    $a2, 0x7c($sp)
/* 053374 7F01E844 8FA6007C */  lw    $a2, 0x7c($sp)
/* 053378 7F01E848 27A4001C */  addiu $a0, $sp, 0x1c
/* 05337C 7F01E84C 8FA50084 */  lw    $a1, 0x84($sp)
.L7F01E850:
/* 053380 7F01E850 0FC0775D */  jal   sub_GAME_7F01DD74
/* 053384 7F01E854 AFA6007C */   sw    $a2, 0x7c($sp)
/* 053388 7F01E858 8FA4007C */  lw    $a0, 0x7c($sp)
/* 05338C 7F01E85C 0FC07941 */  jal   sub_GAME_7F01E504
/* 053390 7F01E860 27A5001C */   addiu $a1, $sp, 0x1c
.L7F01E864:
/* 053394 7F01E864 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01E868:
/* 053398 7F01E868 27BD0080 */  addiu $sp, $sp, 0x80
/* 05339C 7F01E86C 03E00008 */  jr    $ra
/* 0533A0 7F01E870 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void get_highest_stage_difficulty_completed_in_folder(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_highest_stage_difficulty_completed_in_folder
/* 0533A4 7F01E874 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0533A8 7F01E878 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0533AC 7F01E87C AFB20020 */  sw    $s2, 0x20($sp)
/* 0533B0 7F01E880 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0533B4 7F01E884 AFB00018 */  sw    $s0, 0x18($sp)
/* 0533B8 7F01E888 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0533BC 7F01E88C 0FC07771 */  jal   get_save_folder_ptr
/* 0533C0 7F01E890 AFA60030 */   sw    $a2, 0x30($sp)
/* 0533C4 7F01E894 10400014 */  beqz  $v0, .L7F01E8E8
/* 0533C8 7F01E898 00409025 */   move  $s2, $v0
/* 0533CC 7F01E89C 24110003 */  li    $s1, 3
/* 0533D0 7F01E8A0 24100013 */  li    $s0, 19
.L7F01E8A4:
/* 0533D4 7F01E8A4 02402025 */  move  $a0, $s2
.L7F01E8A8:
/* 0533D8 7F01E8A8 02002825 */  move  $a1, $s0
/* 0533DC 7F01E8AC 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 0533E0 7F01E8B0 02203025 */   move  $a2, $s1
/* 0533E4 7F01E8B4 50400007 */  beql  $v0, $zero, .L7F01E8D4
/* 0533E8 7F01E8B8 2610FFFF */   addiu $s0, $s0, -1
/* 0533EC 7F01E8BC 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0533F0 7F01E8C0 ADD00000 */  sw    $s0, ($t6)
/* 0533F4 7F01E8C4 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0533F8 7F01E8C8 1000000C */  b     .L7F01E8FC
/* 0533FC 7F01E8CC ADF10000 */   sw    $s1, ($t7)
/* 053400 7F01E8D0 2610FFFF */  addiu $s0, $s0, -1
.L7F01E8D4:
/* 053404 7F01E8D4 0603FFF4 */  bgezl $s0, .L7F01E8A8
/* 053408 7F01E8D8 02402025 */   move  $a0, $s2
/* 05340C 7F01E8DC 2631FFFF */  addiu $s1, $s1, -1
/* 053410 7F01E8E0 0623FFF0 */  bgezl $s1, .L7F01E8A4
/* 053414 7F01E8E4 24100013 */   li    $s0, 19
.L7F01E8E8:
/* 053418 7F01E8E8 8FB8002C */  lw    $t8, 0x2c($sp)
/* 05341C 7F01E8EC 2402FFFF */  li    $v0, -1
/* 053420 7F01E8F0 AF020000 */  sw    $v0, ($t8)
/* 053424 7F01E8F4 8FB90030 */  lw    $t9, 0x30($sp)
/* 053428 7F01E8F8 AF220000 */  sw    $v0, ($t9)
.L7F01E8FC:
/* 05342C 7F01E8FC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 053430 7F01E900 8FB00018 */  lw    $s0, 0x18($sp)
/* 053434 7F01E904 8FB1001C */  lw    $s1, 0x1c($sp)
/* 053438 7F01E908 8FB20020 */  lw    $s2, 0x20($sp)
/* 05343C 7F01E90C 03E00008 */  jr    $ra
/* 053440 7F01E910 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif



#ifdef NONMATCHING
void check_egypt_completed_in_folder(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_egypt_completed_in_folder
/* 053444 7F01E914 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 053448 7F01E918 AFBF0024 */  sw    $ra, 0x24($sp)
/* 05344C 7F01E91C AFB2001C */  sw    $s2, 0x1c($sp)
/* 053450 7F01E920 00809025 */  move  $s2, $a0
/* 053454 7F01E924 AFB30020 */  sw    $s3, 0x20($sp)
/* 053458 7F01E928 AFB10018 */  sw    $s1, 0x18($sp)
/* 05345C 7F01E92C 0FC07771 */  jal   get_save_folder_ptr
/* 053460 7F01E930 AFB00014 */   sw    $s0, 0x14($sp)
/* 053464 7F01E934 10400010 */  beqz  $v0, .L7F01E978
/* 053468 7F01E938 24110013 */   li    $s1, 19
/* 05346C 7F01E93C 24130004 */  li    $s3, 4
/* 053470 7F01E940 00008025 */  move  $s0, $zero
.L7F01E944:
/* 053474 7F01E944 02402025 */  move  $a0, $s2
.L7F01E948:
/* 053478 7F01E948 02202825 */  move  $a1, $s1
/* 05347C 7F01E94C 0FC078B0 */  jal   isStageUnlockedAtDifficulty
/* 053480 7F01E950 02003025 */   move  $a2, $s0
/* 053484 7F01E954 10400003 */  beqz  $v0, .L7F01E964
/* 053488 7F01E958 26100001 */   addiu $s0, $s0, 1
/* 05348C 7F01E95C 10000007 */  b     .L7F01E97C
/* 053490 7F01E960 02201025 */   move  $v0, $s1
.L7F01E964:
/* 053494 7F01E964 5613FFF8 */  bnel  $s0, $s3, .L7F01E948
/* 053498 7F01E968 02402025 */   move  $a0, $s2
/* 05349C 7F01E96C 2631FFFF */  addiu $s1, $s1, -1
/* 0534A0 7F01E970 0623FFF4 */  bgezl $s1, .L7F01E944
/* 0534A4 7F01E974 00008025 */   move  $s0, $zero
.L7F01E978:
/* 0534A8 7F01E978 00001025 */  move  $v0, $zero
.L7F01E97C:
/* 0534AC 7F01E97C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0534B0 7F01E980 8FB00014 */  lw    $s0, 0x14($sp)
/* 0534B4 7F01E984 8FB10018 */  lw    $s1, 0x18($sp)
/* 0534B8 7F01E988 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0534BC 7F01E98C 8FB30020 */  lw    $s3, 0x20($sp)
/* 0534C0 7F01E990 03E00008 */  jr    $ra
/* 0534C4 7F01E994 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif



u32 check_egypt_completed_any_folder(void) {
    u32 isfound;
    int folder;
    u32 isunlocked;
    
    isunlocked = 0;
    folder = 0;
    while (folder != 4) {
        isfound = check_egypt_completed_in_folder(folder);
        folder += 1;
        if ((int)isunlocked < (int)isfound) {
            isunlocked = isfound;
        }
    };
    return isunlocked;
}




#ifdef NONMATCHING
void check_cradle_completed_in_folder(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_cradle_completed_in_folder
/* 053524 7F01E9F4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 053528 7F01E9F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 05352C 7F01E9FC AFA40018 */  sw    $a0, 0x18($sp)
/* 053530 7F01EA00 24050011 */  li    $a1, 17
/* 053534 7F01EA04 0FC078B0 */  jal   isStageUnlockedAtDifficulty
/* 053538 7F01EA08 00003025 */   move  $a2, $zero
/* 05353C 7F01EA0C 384E0003 */  xori  $t6, $v0, 3
/* 053540 7F01EA10 2DC20001 */  sltiu $v0, $t6, 1
/* 053544 7F01EA14 1440000D */  bnez  $v0, .L7F01EA4C
/* 053548 7F01EA18 8FA40018 */   lw    $a0, 0x18($sp)
/* 05354C 7F01EA1C 24050011 */  li    $a1, 17
/* 053550 7F01EA20 0FC078B0 */  jal   isStageUnlockedAtDifficulty
/* 053554 7F01EA24 24060001 */   li    $a2, 1
/* 053558 7F01EA28 384F0003 */  xori  $t7, $v0, 3
/* 05355C 7F01EA2C 2DE20001 */  sltiu $v0, $t7, 1
/* 053560 7F01EA30 14400006 */  bnez  $v0, .L7F01EA4C
/* 053564 7F01EA34 8FA40018 */   lw    $a0, 0x18($sp)
/* 053568 7F01EA38 24050011 */  li    $a1, 17
/* 05356C 7F01EA3C 0FC078B0 */  jal   isStageUnlockedAtDifficulty
/* 053570 7F01EA40 24060002 */   li    $a2, 2
/* 053574 7F01EA44 38580003 */  xori  $t8, $v0, 3
/* 053578 7F01EA48 2F020001 */  sltiu $v0, $t8, 1
.L7F01EA4C:
/* 05357C 7F01EA4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 053580 7F01EA50 27BD0018 */  addiu $sp, $sp, 0x18
/* 053584 7F01EA54 03E00008 */  jr    $ra
/* 053588 7F01EA58 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void check_aztec_completed_in_folder_secret_00(void) {

}
#else
GLOBAL_ASM(
.text
glabel check_aztec_completed_in_folder_secret_00
/* 05358C 7F01EA5C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 053590 7F01EA60 AFBF0014 */  sw    $ra, 0x14($sp)
/* 053594 7F01EA64 AFA40018 */  sw    $a0, 0x18($sp)
/* 053598 7F01EA68 24050012 */  li    $a1, 18
/* 05359C 7F01EA6C 0FC078B0 */  jal   isStageUnlockedAtDifficulty
/* 0535A0 7F01EA70 24060001 */   li    $a2, 1
/* 0535A4 7F01EA74 384E0003 */  xori  $t6, $v0, 3
/* 0535A8 7F01EA78 2DC20001 */  sltiu $v0, $t6, 1
/* 0535AC 7F01EA7C 14400006 */  bnez  $v0, .L7F01EA98
/* 0535B0 7F01EA80 8FA40018 */   lw    $a0, 0x18($sp)
/* 0535B4 7F01EA84 24050012 */  li    $a1, 18
/* 0535B8 7F01EA88 0FC078B0 */  jal   isStageUnlockedAtDifficulty
/* 0535BC 7F01EA8C 24060002 */   li    $a2, 2
/* 0535C0 7F01EA90 384F0003 */  xori  $t7, $v0, 3
/* 0535C4 7F01EA94 2DE20001 */  sltiu $v0, $t7, 1
.L7F01EA98:
/* 0535C8 7F01EA98 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0535CC 7F01EA9C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0535D0 7F01EAA0 03E00008 */  jr    $ra
/* 0535D4 7F01EAA4 00000000 */   nop   
)
#endif

s32 check_egypt_completed_in_folder_00(int foldernum)
{
    return isStageUnlockedAtDifficulty(foldernum, SP_LEVEL_AZTEC, DIFFICULTY_00) == 3;
}

u32 check_cradle_completed_any_folder(void) {
    u32 completed;
    int folder;
    
    folder = 0;
    while (folder != 4) {
        completed = check_cradle_completed_in_folder(folder);
        folder += 1;
        if (completed != FALSE) {
            return TRUE;
        }
    };
    return FALSE;
}


u32 check_aztec_completed_any_folder_secret_00(void) {
    u32 completed;
    int folder;
    
    folder = 0;
    while (folder != 4) {
        completed = check_aztec_completed_in_folder_secret_00(folder);
        folder += 1;
        if (completed != FALSE) {
            return TRUE;
        }
    };
    return FALSE;
}


u32 check_egypt_completed_any_folder_00(void) {
    u32 completed;
    int folder;
    
    folder = 0;
    while (folder != 4) {
        completed = check_egypt_completed_in_folder_00(folder);
        folder += 1;
        if (completed != FALSE) {
            return TRUE;
        }
    };
    return FALSE;
}


u8 removed_would_have_returned_bond_for_folder_num(u32 folder)
{
    #ifdef ALL_BONDS
    //likely code based on behavior
    if ((folder >= 0) && (folder < 4))
    {
        return save_selected_bond[folder];
    }
    #endif

    #ifndef ALL_BONDS
    return 0;
    #endif
}



#ifdef NONMATCHING
void set_selected_bond_to_folder(u32 folder,u32 bond) {
    if ((folder >= 0) && (folder < 4))
    {
        save_selected_bond[folder] = 0;
    }
}
#else
GLOBAL_ASM(
.text
glabel set_selected_bond_to_folder
/* 0536FC 7F01EBCC 04800007 */  bltz  $a0, .L7F01EBEC
/* 053700 7F01EBD0 AFA50004 */   sw    $a1, 4($sp)
/* 053704 7F01EBD4 28810004 */  slti  $at, $a0, 4
/* 053708 7F01EBD8 10200004 */  beqz  $at, .L7F01EBEC
/* 05370C 7F01EBDC 00047080 */   sll   $t6, $a0, 2
/* 053710 7F01EBE0 3C018003 */  lui   $at, %hi(save_selected_bond)
/* 053714 7F01EBE4 002E0821 */  addu  $at, $at, $t6
/* 053718 7F01EBE8 AC20C510 */  sw    $zero, %lo(save_selected_bond)($at)
.L7F01EBEC:
/* 05371C 7F01EBEC 03E00008 */  jr    $ra
/* 053720 7F01EBF0 00000000 */   nop   
)
#endif



void sub_GAME_7F01EBF4(u32 unused) {
    return;
}

void sub_GAME_7F01EBFC(u32 unused) {
    return;
}




#ifdef NONMATCHING
void delete_eeprom_folder(void) {

}
#else
GLOBAL_ASM(
.text
glabel delete_eeprom_folder
/* 053734 7F01EC04 27BDFF70 */  addiu $sp, $sp, -0x90
/* 053738 7F01EC08 AFB00014 */  sw    $s0, 0x14($sp)
/* 05373C 7F01EC0C 00808025 */  move  $s0, $a0
/* 053740 7F01EC10 AFBF001C */  sw    $ra, 0x1c($sp)
/* 053744 7F01EC14 04800039 */  bltz  $a0, .L7F01ECFC
/* 053748 7F01EC18 AFB10018 */   sw    $s1, 0x18($sp)
/* 05374C 7F01EC1C 28810004 */  slti  $at, $a0, 4
/* 053750 7F01EC20 50200037 */  beql  $at, $zero, .L7F01ED00
/* 053754 7F01EC24 8FBF001C */   lw    $ra, 0x1c($sp)
/* 053758 7F01EC28 0FC07771 */  jal   get_save_folder_ptr
/* 05375C 7F01EC2C 00000000 */   nop   
/* 053760 7F01EC30 10400032 */  beqz  $v0, .L7F01ECFC
/* 053764 7F01EC34 00408825 */   move  $s1, $v0
/* 053768 7F01EC38 02002025 */  move  $a0, $s0
/* 05376C 7F01EC3C 27A50088 */  addiu $a1, $sp, 0x88
/* 053770 7F01EC40 0FC07A1D */  jal   get_highest_stage_difficulty_completed_in_folder
/* 053774 7F01EC44 27A60084 */   addiu $a2, $sp, 0x84
/* 053778 7F01EC48 8FAE0088 */  lw    $t6, 0x88($sp)
/* 05377C 7F01EC4C 8FAF0084 */  lw    $t7, 0x84($sp)
/* 053780 7F01EC50 05C2002B */  bltzl $t6, .L7F01ED00
/* 053784 7F01EC54 8FBF001C */   lw    $ra, 0x1c($sp)
/* 053788 7F01EC58 05E00028 */  bltz  $t7, .L7F01ECFC
/* 05378C 7F01EC5C 27A20024 */   addiu $v0, $sp, 0x24
/* 053790 7F01EC60 3C188003 */  lui   $t8, %hi(D_8002C720) 
/* 053794 7F01EC64 2718C720 */  addiu $t8, %lo(D_8002C720) # addiu $t8, $t8, -0x38e0
/* 053798 7F01EC68 27080060 */  addiu $t0, $t8, 0x60
/* 05379C 7F01EC6C 00404825 */  move  $t1, $v0
.L7F01EC70:
/* 0537A0 7F01EC70 8F010000 */  lw    $at, ($t8)
/* 0537A4 7F01EC74 2718000C */  addiu $t8, $t8, 0xc
/* 0537A8 7F01EC78 2529000C */  addiu $t1, $t1, 0xc
/* 0537AC 7F01EC7C AD21FFF4 */  sw    $at, -0xc($t1)
/* 0537B0 7F01EC80 8F01FFF8 */  lw    $at, -8($t8)
/* 0537B4 7F01EC84 AD21FFF8 */  sw    $at, -8($t1)
/* 0537B8 7F01EC88 8F01FFFC */  lw    $at, -4($t8)
/* 0537BC 7F01EC8C 1708FFF8 */  bne   $t8, $t0, .L7F01EC70
/* 0537C0 7F01EC90 AD21FFFC */   sw    $at, -4($t1)
/* 0537C4 7F01EC94 00406025 */  move  $t4, $v0
/* 0537C8 7F01EC98 02206825 */  move  $t5, $s1
/* 0537CC 7F01EC9C 244B0060 */  addiu $t3, $v0, 0x60
.L7F01ECA0:
/* 0537D0 7F01ECA0 8D810000 */  lw    $at, ($t4)
/* 0537D4 7F01ECA4 258C000C */  addiu $t4, $t4, 0xc
/* 0537D8 7F01ECA8 25AD000C */  addiu $t5, $t5, 0xc
/* 0537DC 7F01ECAC ADA1FFF4 */  sw    $at, -0xc($t5)
/* 0537E0 7F01ECB0 8D81FFF8 */  lw    $at, -8($t4)
/* 0537E4 7F01ECB4 ADA1FFF8 */  sw    $at, -8($t5)
/* 0537E8 7F01ECB8 8D81FFFC */  lw    $at, -4($t4)
/* 0537EC 7F01ECBC 158BFFF8 */  bne   $t4, $t3, .L7F01ECA0
/* 0537F0 7F01ECC0 ADA1FFFC */   sw    $at, -4($t5)
/* 0537F4 7F01ECC4 02202025 */  move  $a0, $s1
/* 0537F8 7F01ECC8 0FC07636 */  jal   set_eeprom_to_folder_num
/* 0537FC 7F01ECCC 02002825 */   move  $a1, $s0
/* 053800 7F01ECD0 02202025 */  move  $a0, $s1
/* 053804 7F01ECD4 0FC07659 */  jal   toggle_eeprom_flag_set_0x80
/* 053808 7F01ECD8 00002825 */   move  $a1, $zero
/* 05380C 7F01ECDC 02202025 */  move  $a0, $s1
/* 053810 7F01ECE0 0FC0764D */  jal   set_selected_bond
/* 053814 7F01ECE4 02002825 */   move  $a1, $s0
/* 053818 7F01ECE8 02002025 */  move  $a0, $s0
/* 05381C 7F01ECEC 0FC07AF3 */  jal   set_selected_bond_to_folder
/* 053820 7F01ECF0 02002825 */   move  $a1, $s0
/* 053824 7F01ECF4 0FC075E8 */  jal   sub_GAME_7F01D7A0
/* 053828 7F01ECF8 02202025 */   move  $a0, $s1
.L7F01ECFC:
/* 05382C 7F01ECFC 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F01ED00:
/* 053830 7F01ED00 8FB00014 */  lw    $s0, 0x14($sp)
/* 053834 7F01ED04 8FB10018 */  lw    $s1, 0x18($sp)
/* 053838 7F01ED08 03E00008 */  jr    $ra
/* 05383C 7F01ED0C 27BD0090 */   addiu $sp, $sp, 0x90
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01ED10(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01ED10
/* 053840 7F01ED10 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 053844 7F01ED14 AFBF002C */  sw    $ra, 0x2c($sp)
/* 053848 7F01ED18 AFB50028 */  sw    $s5, 0x28($sp)
/* 05384C 7F01ED1C AFB40024 */  sw    $s4, 0x24($sp)
/* 053850 7F01ED20 AFB30020 */  sw    $s3, 0x20($sp)
/* 053854 7F01ED24 AFB2001C */  sw    $s2, 0x1c($sp)
/* 053858 7F01ED28 AFB10018 */  sw    $s1, 0x18($sp)
/* 05385C 7F01ED2C 0FC07771 */  jal   get_save_folder_ptr
/* 053860 7F01ED30 AFB00014 */   sw    $s0, 0x14($sp)
/* 053864 7F01ED34 3C1105F5 */  lui   $s1, (0x05F5E0FF >> 16) # lui $s1, 0x5f5
/* 053868 7F01ED38 0040A025 */  move  $s4, $v0
/* 05386C 7F01ED3C 3631E0FF */  ori   $s1, (0x05F5E0FF & 0xFFFF) # ori $s1, $s1, 0xe0ff
/* 053870 7F01ED40 00009825 */  move  $s3, $zero
/* 053874 7F01ED44 24150014 */  li    $s5, 20
/* 053878 7F01ED48 24120003 */  li    $s2, 3
/* 05387C 7F01ED4C 00008025 */  move  $s0, $zero
.L7F01ED50:
/* 053880 7F01ED50 02802025 */  move  $a0, $s4
.L7F01ED54:
/* 053884 7F01ED54 02602825 */  move  $a1, $s3
/* 053888 7F01ED58 02003025 */  move  $a2, $s0
/* 05388C 7F01ED5C 0FC0772C */  jal   sub_GAME_7F01DCB0
/* 053890 7F01ED60 02203825 */   move  $a3, $s1
/* 053894 7F01ED64 26100001 */  addiu $s0, $s0, 1
/* 053898 7F01ED68 5612FFFA */  bnel  $s0, $s2, .L7F01ED54
/* 05389C 7F01ED6C 02802025 */   move  $a0, $s4
/* 0538A0 7F01ED70 26730001 */  addiu $s3, $s3, 1
/* 0538A4 7F01ED74 5675FFF6 */  bnel  $s3, $s5, .L7F01ED50
/* 0538A8 7F01ED78 00008025 */   move  $s0, $zero
/* 0538AC 7F01ED7C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0538B0 7F01ED80 8FB00014 */  lw    $s0, 0x14($sp)
/* 0538B4 7F01ED84 8FB10018 */  lw    $s1, 0x18($sp)
/* 0538B8 7F01ED88 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0538BC 7F01ED8C 8FB30020 */  lw    $s3, 0x20($sp)
/* 0538C0 7F01ED90 8FB40024 */  lw    $s4, 0x24($sp)
/* 0538C4 7F01ED94 8FB50028 */  lw    $s5, 0x28($sp)
/* 0538C8 7F01ED98 03E00008 */  jr    $ra
/* 0538CC 7F01ED9C 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



#ifdef NONMATCHING
void sub_GAME_7F01EDA0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F01EDA0
/* 0538D0 7F01EDA0 27BDFF60 */  addiu $sp, $sp, -0xa0
/* 0538D4 7F01EDA4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0538D8 7F01EDA8 AFB30020 */  sw    $s3, 0x20($sp)
/* 0538DC 7F01EDAC AFB2001C */  sw    $s2, 0x1c($sp)
/* 0538E0 7F01EDB0 AFB10018 */  sw    $s1, 0x18($sp)
/* 0538E4 7F01EDB4 0480004F */  bltz  $a0, .L7F01EEF4
/* 0538E8 7F01EDB8 AFB00014 */   sw    $s0, 0x14($sp)
/* 0538EC 7F01EDBC 28810004 */  slti  $at, $a0, 4
/* 0538F0 7F01EDC0 5020004D */  beql  $at, $zero, .L7F01EEF8
/* 0538F4 7F01EDC4 8FBF0024 */   lw    $ra, 0x24($sp)
/* 0538F8 7F01EDC8 0FC07771 */  jal   get_save_folder_ptr
/* 0538FC 7F01EDCC AFA400A0 */   sw    $a0, 0xa0($sp)
/* 053900 7F01EDD0 10400048 */  beqz  $v0, .L7F01EEF4
/* 053904 7F01EDD4 AFA2009C */   sw    $v0, 0x9c($sp)
/* 053908 7F01EDD8 27B20098 */  addiu $s2, $sp, 0x98
/* 05390C 7F01EDDC 27B30094 */  addiu $s3, $sp, 0x94
/* 053910 7F01EDE0 02603025 */  move  $a2, $s3
/* 053914 7F01EDE4 02402825 */  move  $a1, $s2
/* 053918 7F01EDE8 0FC07A1D */  jal   get_highest_stage_difficulty_completed_in_folder
/* 05391C 7F01EDEC 8FA400A0 */   lw    $a0, 0xa0($sp)
/* 053920 7F01EDF0 8FAE0098 */  lw    $t6, 0x98($sp)
/* 053924 7F01EDF4 8FAF0094 */  lw    $t7, 0x94($sp)
/* 053928 7F01EDF8 05C2003F */  bltzl $t6, .L7F01EEF8
/* 05392C 7F01EDFC 8FBF0024 */   lw    $ra, 0x24($sp)
/* 053930 7F01EE00 05E0003C */  bltz  $t7, .L7F01EEF4
/* 053934 7F01EE04 00008025 */   move  $s0, $zero
/* 053938 7F01EE08 24110004 */  li    $s1, 4
.L7F01EE0C:
/* 05393C 7F01EE0C 0FC07771 */  jal   get_save_folder_ptr
/* 053940 7F01EE10 02002025 */   move  $a0, $s0
/* 053944 7F01EE14 1040000D */  beqz  $v0, .L7F01EE4C
/* 053948 7F01EE18 02002025 */   move  $a0, $s0
/* 05394C 7F01EE1C 02402825 */  move  $a1, $s2
/* 053950 7F01EE20 0FC07A1D */  jal   get_highest_stage_difficulty_completed_in_folder
/* 053954 7F01EE24 02603025 */   move  $a2, $s3
/* 053958 7F01EE28 8FB80098 */  lw    $t8, 0x98($sp)
/* 05395C 7F01EE2C 8FB90094 */  lw    $t9, 0x94($sp)
/* 053960 7F01EE30 07030004 */  bgezl $t8, .L7F01EE44
/* 053964 7F01EE34 26100001 */   addiu $s0, $s0, 1
/* 053968 7F01EE38 07220005 */  bltzl $t9, .L7F01EE50
/* 05396C 7F01EE3C 2A010004 */   slti  $at, $s0, 4
/* 053970 7F01EE40 26100001 */  addiu $s0, $s0, 1
.L7F01EE44:
/* 053974 7F01EE44 1611FFF1 */  bne   $s0, $s1, .L7F01EE0C
/* 053978 7F01EE48 00000000 */   nop   
.L7F01EE4C:
/* 05397C 7F01EE4C 2A010004 */  slti  $at, $s0, 4
.L7F01EE50:
/* 053980 7F01EE50 10200028 */  beqz  $at, .L7F01EEF4
/* 053984 7F01EE54 27B10030 */   addiu $s1, $sp, 0x30
/* 053988 7F01EE58 3C088003 */  lui   $t0, %hi(D_8002C780) 
/* 05398C 7F01EE5C 2508C780 */  addiu $t0, %lo(D_8002C780) # addiu $t0, $t0, -0x3880
/* 053990 7F01EE60 250A0060 */  addiu $t2, $t0, 0x60
/* 053994 7F01EE64 02205825 */  move  $t3, $s1
.L7F01EE68:
/* 053998 7F01EE68 8D010000 */  lw    $at, ($t0)
/* 05399C 7F01EE6C 2508000C */  addiu $t0, $t0, 0xc
/* 0539A0 7F01EE70 256B000C */  addiu $t3, $t3, 0xc
/* 0539A4 7F01EE74 AD61FFF4 */  sw    $at, -0xc($t3)
/* 0539A8 7F01EE78 8D01FFF8 */  lw    $at, -8($t0)
/* 0539AC 7F01EE7C AD61FFF8 */  sw    $at, -8($t3)
/* 0539B0 7F01EE80 8D01FFFC */  lw    $at, -4($t0)
/* 0539B4 7F01EE84 150AFFF8 */  bne   $t0, $t2, .L7F01EE68
/* 0539B8 7F01EE88 AD61FFFC */   sw    $at, -4($t3)
/* 0539BC 7F01EE8C 0FC07771 */  jal   get_save_folder_ptr
/* 0539C0 7F01EE90 02002025 */   move  $a0, $s0
/* 0539C4 7F01EE94 8FAC009C */  lw    $t4, 0x9c($sp)
/* 0539C8 7F01EE98 00409025 */  move  $s2, $v0
/* 0539CC 7F01EE9C 02207825 */  move  $t7, $s1
/* 0539D0 7F01EEA0 258E0060 */  addiu $t6, $t4, 0x60
.L7F01EEA4:
/* 0539D4 7F01EEA4 8D810000 */  lw    $at, ($t4)
/* 0539D8 7F01EEA8 258C000C */  addiu $t4, $t4, 0xc
/* 0539DC 7F01EEAC 25EF000C */  addiu $t7, $t7, 0xc
/* 0539E0 7F01EEB0 ADE1FFF4 */  sw    $at, -0xc($t7)
/* 0539E4 7F01EEB4 8D81FFF8 */  lw    $at, -8($t4)
/* 0539E8 7F01EEB8 ADE1FFF8 */  sw    $at, -8($t7)
/* 0539EC 7F01EEBC 8D81FFFC */  lw    $at, -4($t4)
/* 0539F0 7F01EEC0 158EFFF8 */  bne   $t4, $t6, .L7F01EEA4
/* 0539F4 7F01EEC4 ADE1FFFC */   sw    $at, -4($t7)
/* 0539F8 7F01EEC8 02202025 */  move  $a0, $s1
/* 0539FC 7F01EECC 0FC07636 */  jal   set_eeprom_to_folder_num
/* 053A00 7F01EED0 02002825 */   move  $a1, $s0
/* 053A04 7F01EED4 0FC07AF0 */  jal   removed_would_have_returned_bond_for_folder_num
/* 053A08 7F01EED8 8FA400A0 */   lw    $a0, 0xa0($sp)
/* 053A0C 7F01EEDC 02002025 */  move  $a0, $s0
/* 053A10 7F01EEE0 0FC07AF3 */  jal   set_selected_bond_to_folder
/* 053A14 7F01EEE4 00402825 */   move  $a1, $v0
/* 053A18 7F01EEE8 02402025 */  move  $a0, $s2
/* 053A1C 7F01EEEC 0FC07941 */  jal   sub_GAME_7F01E504
/* 053A20 7F01EEF0 02202825 */   move  $a1, $s1
.L7F01EEF4:
/* 053A24 7F01EEF4 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F01EEF8:
/* 053A28 7F01EEF8 8FB00014 */  lw    $s0, 0x14($sp)
/* 053A2C 7F01EEFC 8FB10018 */  lw    $s1, 0x18($sp)
/* 053A30 7F01EF00 8FB2001C */  lw    $s2, 0x1c($sp)
/* 053A34 7F01EF04 8FB30020 */  lw    $s3, 0x20($sp)
/* 053A38 7F01EF08 03E00008 */  jr    $ra
/* 053A3C 7F01EF0C 27BD00A0 */   addiu $sp, $sp, 0xa0
)
#endif



#ifdef NONMATCHING
void update_eeprom_to_current_solo_watch_settings(void) {

}
#else
GLOBAL_ASM(
.text
glabel update_eeprom_to_current_solo_watch_settings
/* 053A40 7F01EF10 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 053A44 7F01EF14 AFBF001C */  sw    $ra, 0x1c($sp)
/* 053A48 7F01EF18 AFB00018 */  sw    $s0, 0x18($sp)
/* 053A4C 7F01EF1C AFA40020 */  sw    $a0, 0x20($sp)
/* 053A50 7F01EF20 0FC2A4D6 */  jal   get_mTrack2Vol
/* 053A54 7F01EF24 00008025 */   move  $s0, $zero
/* 053A58 7F01EF28 8FAF0020 */  lw    $t7, 0x20($sp)
/* 053A5C 7F01EF2C 000271C3 */  sra   $t6, $v0, 7
/* 053A60 7F01EF30 0FC2A460 */  jal   call_sfx_c_700091C8
/* 053A64 7F01EF34 A1EE000A */   sb    $t6, 0xa($t7)
/* 053A68 7F01EF38 8FB90020 */  lw    $t9, 0x20($sp)
/* 053A6C 7F01EF3C 0002C1C3 */  sra   $t8, $v0, 7
/* 053A70 7F01EF40 0FC2938E */  jal   get_cur_player_look_vertical_inverted
/* 053A74 7F01EF44 A338000B */   sb    $t8, 0xb($t9)
/* 053A78 7F01EF48 10400002 */  beqz  $v0, .L7F01EF54
/* 053A7C 7F01EF4C 00000000 */   nop   
/* 053A80 7F01EF50 24100001 */  li    $s0, 1
.L7F01EF54:
/* 053A84 7F01EF54 0FC29394 */  jal   cur_player_get_autoaim
/* 053A88 7F01EF58 00000000 */   nop   
/* 053A8C 7F01EF5C 10400002 */  beqz  $v0, .L7F01EF68
/* 053A90 7F01EF60 36080002 */   ori   $t0, $s0, 2
/* 053A94 7F01EF64 3110FFFF */  andi  $s0, $t0, 0xffff
.L7F01EF68:
/* 053A98 7F01EF68 0FC293A0 */  jal   cur_player_get_aim_control
/* 053A9C 7F01EF6C 00000000 */   nop   
/* 053AA0 7F01EF70 10400002 */  beqz  $v0, .L7F01EF7C
/* 053AA4 7F01EF74 360A0004 */   ori   $t2, $s0, 4
/* 053AA8 7F01EF78 3150FFFF */  andi  $s0, $t2, 0xffff
.L7F01EF7C:
/* 053AAC 7F01EF7C 0FC293A6 */  jal   cur_player_get_sight_onscreen_control
/* 053AB0 7F01EF80 00000000 */   nop   
/* 053AB4 7F01EF84 10400002 */  beqz  $v0, .L7F01EF90
/* 053AB8 7F01EF88 360C0008 */   ori   $t4, $s0, 8
/* 053ABC 7F01EF8C 3190FFFF */  andi  $s0, $t4, 0xffff
.L7F01EF90:
/* 053AC0 7F01EF90 0FC2939A */  jal   cur_player_get_lookahead
/* 053AC4 7F01EF94 00000000 */   nop   
/* 053AC8 7F01EF98 10400002 */  beqz  $v0, .L7F01EFA4
/* 053ACC 7F01EF9C 360E0010 */   ori   $t6, $s0, 0x10
/* 053AD0 7F01EFA0 31D0FFFF */  andi  $s0, $t6, 0xffff
.L7F01EFA4:
/* 053AD4 7F01EFA4 0FC293AC */  jal   cur_player_get_ammo_onscreen_setting
/* 053AD8 7F01EFA8 00000000 */   nop   
/* 053ADC 7F01EFAC 10400002 */  beqz  $v0, .L7F01EFB8
/* 053AE0 7F01EFB0 36180020 */   ori   $t8, $s0, 0x20
/* 053AE4 7F01EFB4 3310FFFF */  andi  $s0, $t8, 0xffff
.L7F01EFB8:
/* 053AE8 7F01EFB8 0FC293B2 */  jal   cur_player_get_screen_setting
/* 053AEC 7F01EFBC 00000000 */   nop   
/* 053AF0 7F01EFC0 24010001 */  li    $at, 1
/* 053AF4 7F01EFC4 14410003 */  bne   $v0, $at, .L7F01EFD4
/* 053AF8 7F01EFC8 36080040 */   ori   $t0, $s0, 0x40
/* 053AFC 7F01EFCC 10000007 */  b     .L7F01EFEC
/* 053B00 7F01EFD0 3110FFFF */   andi  $s0, $t0, 0xffff
.L7F01EFD4:
/* 053B04 7F01EFD4 0FC293B2 */  jal   cur_player_get_screen_setting
/* 053B08 7F01EFD8 00000000 */   nop   
/* 053B0C 7F01EFDC 24010002 */  li    $at, 2
/* 053B10 7F01EFE0 14410002 */  bne   $v0, $at, .L7F01EFEC
/* 053B14 7F01EFE4 360A0800 */   ori   $t2, $s0, 0x800
/* 053B18 7F01EFE8 3150FFFF */  andi  $s0, $t2, 0xffff
.L7F01EFEC:
/* 053B1C 7F01EFEC 0FC293B8 */  jal   get_screen_ratio
/* 053B20 7F01EFF0 00000000 */   nop   
/* 053B24 7F01EFF4 10400002 */  beqz  $v0, .L7F01F000
/* 053B28 7F01EFF8 360C0080 */   ori   $t4, $s0, 0x80
/* 053B2C 7F01EFFC 3190FFFF */  andi  $s0, $t4, 0xffff
.L7F01F000:
/* 053B30 7F01F000 0FC29370 */  jal   cur_player_get_control_type
/* 053B34 7F01F004 00000000 */   nop   
/* 053B38 7F01F008 8FA80020 */  lw    $t0, 0x20($sp)
/* 053B3C 7F01F00C 00027A00 */  sll   $t7, $v0, 8
/* 053B40 7F01F010 31F80700 */  andi  $t8, $t7, 0x700
/* 053B44 7F01F014 0218C825 */  or    $t9, $s0, $t8
/* 053B48 7F01F018 A519000C */  sh    $t9, 0xc($t0)
/* 053B4C 7F01F01C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 053B50 7F01F020 8FB00018 */  lw    $s0, 0x18($sp)
/* 053B54 7F01F024 27BD0020 */  addiu $sp, $sp, 0x20
/* 053B58 7F01F028 03E00008 */  jr    $ra
/* 053B5C 7F01F02C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void get_screen_ratio_settings_for_mpgame_from_folder(void) {

}
#else
GLOBAL_ASM(
.text
glabel get_screen_ratio_settings_for_mpgame_from_folder
/* 053B60 7F01F030 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 053B64 7F01F034 AFBF001C */  sw    $ra, 0x1c($sp)
/* 053B68 7F01F038 0FC07771 */  jal   get_save_folder_ptr
/* 053B6C 7F01F03C AFB00018 */   sw    $s0, 0x18($sp)
/* 053B70 7F01F040 1040004B */  beqz  $v0, .L7F01F170
/* 053B74 7F01F044 00401825 */   move  $v1, $v0
/* 053B78 7F01F048 9042000A */  lbu   $v0, 0xa($v0)
/* 053B7C 7F01F04C AFA30024 */  sw    $v1, 0x24($sp)
/* 053B80 7F01F050 000271C0 */  sll   $t6, $v0, 7
/* 053B84 7F01F054 00027843 */  sra   $t7, $v0, 1
/* 053B88 7F01F058 01CF2025 */  or    $a0, $t6, $t7
/* 053B8C 7F01F05C 3098FFFF */  andi  $t8, $a0, 0xffff
/* 053B90 7F01F060 0FC2A4D9 */  jal   set_mTrack2Vol
/* 053B94 7F01F064 03002025 */   move  $a0, $t8
/* 053B98 7F01F068 8FB00024 */  lw    $s0, 0x24($sp)
/* 053B9C 7F01F06C 9202000B */  lbu   $v0, 0xb($s0)
/* 053BA0 7F01F070 0002C9C0 */  sll   $t9, $v0, 7
/* 053BA4 7F01F074 00024043 */  sra   $t0, $v0, 1
/* 053BA8 7F01F078 03282025 */  or    $a0, $t9, $t0
/* 053BAC 7F01F07C 3089FFFF */  andi  $t1, $a0, 0xffff
/* 053BB0 7F01F080 0FC2A468 */  jal   sub_GAME_7F0A91A0
/* 053BB4 7F01F084 01202025 */   move  $a0, $t1
/* 053BB8 7F01F088 960A000C */  lhu   $t2, 0xc($s0)
/* 053BBC 7F01F08C 0FC26919 */  jal   getPlayerCount
/* 053BC0 7F01F090 A7AA0020 */   sh    $t2, 0x20($sp)
/* 053BC4 7F01F094 24010001 */  li    $at, 1
/* 053BC8 7F01F098 14410007 */  bne   $v0, $at, .L7F01F0B8
/* 053BCC 7F01F09C 97B00020 */   lhu   $s0, 0x20($sp)
/* 053BD0 7F01F0A0 32040700 */  andi  $a0, $s0, 0x700
/* 053BD4 7F01F0A4 00045A03 */  sra   $t3, $a0, 8
/* 053BD8 7F01F0A8 0FC29374 */  jal   cur_player_set_control_type
/* 053BDC 7F01F0AC 3164FFFF */   andi  $a0, $t3, 0xffff
/* 053BE0 7F01F0B0 10000005 */  b     .L7F01F0C8
/* 053BE4 7F01F0B4 32040001 */   andi  $a0, $s0, 1
.L7F01F0B8:
/* 053BE8 7F01F0B8 0FC29374 */  jal   cur_player_set_control_type
/* 053BEC 7F01F0BC 00002025 */   move  $a0, $zero
/* 053BF0 7F01F0C0 97B00020 */  lhu   $s0, 0x20($sp)
/* 053BF4 7F01F0C4 32040001 */  andi  $a0, $s0, 1
.L7F01F0C8:
/* 053BF8 7F01F0C8 0004682B */  sltu  $t5, $zero, $a0
/* 053BFC 7F01F0CC 0FC29391 */  jal   set_cur_player_look_vertical_inverted
/* 053C00 7F01F0D0 01A02025 */   move  $a0, $t5
/* 053C04 7F01F0D4 32040002 */  andi  $a0, $s0, 2
/* 053C08 7F01F0D8 0004702B */  sltu  $t6, $zero, $a0
/* 053C0C 7F01F0DC 0FC29397 */  jal   cur_player_set_autoaim
/* 053C10 7F01F0E0 01C02025 */   move  $a0, $t6
/* 053C14 7F01F0E4 32040004 */  andi  $a0, $s0, 4
/* 053C18 7F01F0E8 0004782B */  sltu  $t7, $zero, $a0
/* 053C1C 7F01F0EC 0FC293A3 */  jal   cur_player_set_aim_control
/* 053C20 7F01F0F0 01E02025 */   move  $a0, $t7
/* 053C24 7F01F0F4 32040008 */  andi  $a0, $s0, 8
/* 053C28 7F01F0F8 0004C02B */  sltu  $t8, $zero, $a0
/* 053C2C 7F01F0FC 0FC293A9 */  jal   cur_player_set_sight_onscreen_control
/* 053C30 7F01F100 03002025 */   move  $a0, $t8
/* 053C34 7F01F104 32040010 */  andi  $a0, $s0, 0x10
/* 053C38 7F01F108 0004C82B */  sltu  $t9, $zero, $a0
/* 053C3C 7F01F10C 0FC2939D */  jal   cur_player_set_lookahead
/* 053C40 7F01F110 03202025 */   move  $a0, $t9
/* 053C44 7F01F114 32040020 */  andi  $a0, $s0, 0x20
/* 053C48 7F01F118 0004402B */  sltu  $t0, $zero, $a0
/* 053C4C 7F01F11C 0FC293AF */  jal   cur_player_set_ammo_onscreen_setting
/* 053C50 7F01F120 01002025 */   move  $a0, $t0
/* 053C54 7F01F124 32090800 */  andi  $t1, $s0, 0x800
/* 053C58 7F01F128 11200005 */  beqz  $t1, .L7F01F140
/* 053C5C 7F01F12C 320A0040 */   andi  $t2, $s0, 0x40
/* 053C60 7F01F130 0FC293B5 */  jal   cur_player_set_screen_setting
/* 053C64 7F01F134 24040002 */   li    $a0, 2
/* 053C68 7F01F138 1000000A */  b     .L7F01F164
/* 053C6C 7F01F13C 32040080 */   andi  $a0, $s0, 0x80
.L7F01F140:
/* 053C70 7F01F140 11400005 */  beqz  $t2, .L7F01F158
/* 053C74 7F01F144 00000000 */   nop   
/* 053C78 7F01F148 0FC293B5 */  jal   cur_player_set_screen_setting
/* 053C7C 7F01F14C 24040001 */   li    $a0, 1
/* 053C80 7F01F150 10000004 */  b     .L7F01F164
/* 053C84 7F01F154 32040080 */   andi  $a0, $s0, 0x80
.L7F01F158:
/* 053C88 7F01F158 0FC293B5 */  jal   cur_player_set_screen_setting
/* 053C8C 7F01F15C 00002025 */   move  $a0, $zero
/* 053C90 7F01F160 32040080 */  andi  $a0, $s0, 0x80
.L7F01F164:
/* 053C94 7F01F164 0004582B */  sltu  $t3, $zero, $a0
/* 053C98 7F01F168 0FC293BB */  jal   set_screen_ratio
/* 053C9C 7F01F16C 01602025 */   move  $a0, $t3
.L7F01F170:
/* 053CA0 7F01F170 8FBF001C */  lw    $ra, 0x1c($sp)
/* 053CA4 7F01F174 8FB00018 */  lw    $s0, 0x18($sp)
/* 053CA8 7F01F178 27BD0028 */  addiu $sp, $sp, 0x28
/* 053CAC 7F01F17C 03E00008 */  jr    $ra
/* 053CB0 7F01F180 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void delete_update_eeprom_file(void) {

}
#else
GLOBAL_ASM(
.text
glabel delete_update_eeprom_file
/* 053CB4 7F01F184 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 053CB8 7F01F188 AFBF0014 */  sw    $ra, 0x14($sp)
/* 053CBC 7F01F18C 0480003F */  bltz  $a0, .L7F01F28C
/* 053CC0 7F01F190 00802825 */   move  $a1, $a0
/* 053CC4 7F01F194 28810004 */  slti  $at, $a0, 4
/* 053CC8 7F01F198 5020003D */  beql  $at, $zero, .L7F01F290
/* 053CCC 7F01F19C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 053CD0 7F01F1A0 0FC07771 */  jal   get_save_folder_ptr
/* 053CD4 7F01F1A4 AFA500E0 */   sw    $a1, 0xe0($sp)
/* 053CD8 7F01F1A8 3C0E8003 */  lui   $t6, %hi(D_8002C7E0) 
/* 053CDC 7F01F1AC 27A6007C */  addiu $a2, $sp, 0x7c
/* 053CE0 7F01F1B0 25CEC7E0 */  addiu $t6, %lo(D_8002C7E0) # addiu $t6, $t6, -0x3820
/* 053CE4 7F01F1B4 8FA500E0 */  lw    $a1, 0xe0($sp)
/* 053CE8 7F01F1B8 AFA200DC */  sw    $v0, 0xdc($sp)
/* 053CEC 7F01F1BC 25D90060 */  addiu $t9, $t6, 0x60
/* 053CF0 7F01F1C0 00C04025 */  move  $t0, $a2
.L7F01F1C4:
/* 053CF4 7F01F1C4 8DC10000 */  lw    $at, ($t6)
/* 053CF8 7F01F1C8 25CE000C */  addiu $t6, $t6, 0xc
/* 053CFC 7F01F1CC 2508000C */  addiu $t0, $t0, 0xc
/* 053D00 7F01F1D0 AD01FFF4 */  sw    $at, -0xc($t0)
/* 053D04 7F01F1D4 8DC1FFF8 */  lw    $at, -8($t6)
/* 053D08 7F01F1D8 AD01FFF8 */  sw    $at, -8($t0)
/* 053D0C 7F01F1DC 8DC1FFFC */  lw    $at, -4($t6)
/* 053D10 7F01F1E0 15D9FFF8 */  bne   $t6, $t9, .L7F01F1C4
/* 053D14 7F01F1E4 AD01FFFC */   sw    $at, -4($t0)
/* 053D18 7F01F1E8 1040000E */  beqz  $v0, .L7F01F224
/* 053D1C 7F01F1EC 00405825 */   move  $t3, $v0
/* 053D20 7F01F1F0 00C06025 */  move  $t4, $a2
/* 053D24 7F01F1F4 244A0060 */  addiu $t2, $v0, 0x60
.L7F01F1F8:
/* 053D28 7F01F1F8 8D610000 */  lw    $at, ($t3)
/* 053D2C 7F01F1FC 256B000C */  addiu $t3, $t3, 0xc
/* 053D30 7F01F200 258C000C */  addiu $t4, $t4, 0xc
/* 053D34 7F01F204 AD81FFF4 */  sw    $at, -0xc($t4)
/* 053D38 7F01F208 8D61FFF8 */  lw    $at, -8($t3)
/* 053D3C 7F01F20C AD81FFF8 */  sw    $at, -8($t4)
/* 053D40 7F01F210 8D61FFFC */  lw    $at, -4($t3)
/* 053D44 7F01F214 156AFFF8 */  bne   $t3, $t2, .L7F01F1F8
/* 053D48 7F01F218 AD81FFFC */   sw    $at, -4($t4)
/* 053D4C 7F01F21C 10000005 */  b     .L7F01F234
/* 053D50 7F01F220 27A4001C */   addiu $a0, $sp, 0x1c
.L7F01F224:
/* 053D54 7F01F224 0FC07636 */  jal   set_eeprom_to_folder_num
/* 053D58 7F01F228 00C02025 */   move  $a0, $a2
/* 053D5C 7F01F22C 27A6007C */  addiu $a2, $sp, 0x7c
/* 053D60 7F01F230 27A4001C */  addiu $a0, $sp, 0x1c
.L7F01F234:
/* 053D64 7F01F234 0080C825 */  move  $t9, $a0
/* 053D68 7F01F238 00C07825 */  move  $t7, $a2
/* 053D6C 7F01F23C 24D80060 */  addiu $t8, $a2, 0x60
.L7F01F240:
/* 053D70 7F01F240 8DE10000 */  lw    $at, ($t7)
/* 053D74 7F01F244 25EF000C */  addiu $t7, $t7, 0xc
/* 053D78 7F01F248 2739000C */  addiu $t9, $t9, 0xc
/* 053D7C 7F01F24C AF21FFF4 */  sw    $at, -0xc($t9)
/* 053D80 7F01F250 8DE1FFF8 */  lw    $at, -8($t7)
/* 053D84 7F01F254 AF21FFF8 */  sw    $at, -8($t9)
/* 053D88 7F01F258 8DE1FFFC */  lw    $at, -4($t7)
/* 053D8C 7F01F25C 15F8FFF8 */  bne   $t7, $t8, .L7F01F240
/* 053D90 7F01F260 AF21FFFC */   sw    $at, -4($t9)
/* 053D94 7F01F264 0FC07BC4 */  jal   update_eeprom_to_current_solo_watch_settings
/* 053D98 7F01F268 00000000 */   nop   
/* 053D9C 7F01F26C 27A4001C */  addiu $a0, $sp, 0x1c
/* 053DA0 7F01F270 27A5007C */  addiu $a1, $sp, 0x7c
/* 053DA4 7F01F274 0C005B5C */  jal   _bcmp
/* 053DA8 7F01F278 24060060 */   li    $a2, 96
/* 053DAC 7F01F27C 10400003 */  beqz  $v0, .L7F01F28C
/* 053DB0 7F01F280 8FA400DC */   lw    $a0, 0xdc($sp)
/* 053DB4 7F01F284 0FC07941 */  jal   sub_GAME_7F01E504
/* 053DB8 7F01F288 27A5001C */   addiu $a1, $sp, 0x1c
.L7F01F28C:
/* 053DBC 7F01F28C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01F290:
/* 053DC0 7F01F290 27BD00E0 */  addiu $sp, $sp, 0xe0
/* 053DC4 7F01F294 03E00008 */  jr    $ra
/* 053DC8 7F01F298 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void copy_eeprom_to_stack_set_folder_num(void) {

}
#else
GLOBAL_ASM(
.text
glabel copy_eeprom_to_stack_set_folder_num
/* 053DCC 7F01F29C 27BDFF78 */  addiu $sp, $sp, -0x88
/* 053DD0 7F01F2A0 AFB00014 */  sw    $s0, 0x14($sp)
/* 053DD4 7F01F2A4 00808025 */  move  $s0, $a0
/* 053DD8 7F01F2A8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 053DDC 7F01F2AC 04800034 */  bltz  $a0, .L7F01F380
/* 053DE0 7F01F2B0 AFB10018 */   sw    $s1, 0x18($sp)
/* 053DE4 7F01F2B4 28810004 */  slti  $at, $a0, 4
/* 053DE8 7F01F2B8 50200032 */  beql  $at, $zero, .L7F01F384
/* 053DEC 7F01F2BC 8FBF001C */   lw    $ra, 0x1c($sp)
/* 053DF0 7F01F2C0 0FC07771 */  jal   get_save_folder_ptr
/* 053DF4 7F01F2C4 00000000 */   nop   
/* 053DF8 7F01F2C8 3C0E8003 */  lui   $t6, %hi(D_8002C840) 
/* 053DFC 7F01F2CC 27B10024 */  addiu $s1, $sp, 0x24
/* 053E00 7F01F2D0 25CEC840 */  addiu $t6, %lo(D_8002C840) # addiu $t6, $t6, -0x37c0
/* 053E04 7F01F2D4 AFA20084 */  sw    $v0, 0x84($sp)
/* 053E08 7F01F2D8 25D90060 */  addiu $t9, $t6, 0x60
/* 053E0C 7F01F2DC 02204025 */  move  $t0, $s1
.L7F01F2E0:
/* 053E10 7F01F2E0 8DC10000 */  lw    $at, ($t6)
/* 053E14 7F01F2E4 25CE000C */  addiu $t6, $t6, 0xc
/* 053E18 7F01F2E8 2508000C */  addiu $t0, $t0, 0xc
/* 053E1C 7F01F2EC AD01FFF4 */  sw    $at, -0xc($t0)
/* 053E20 7F01F2F0 8DC1FFF8 */  lw    $at, -8($t6)
/* 053E24 7F01F2F4 AD01FFF8 */  sw    $at, -8($t0)
/* 053E28 7F01F2F8 8DC1FFFC */  lw    $at, -4($t6)
/* 053E2C 7F01F2FC 15D9FFF8 */  bne   $t6, $t9, .L7F01F2E0
/* 053E30 7F01F300 AD01FFFC */   sw    $at, -4($t0)
/* 053E34 7F01F304 1040000F */  beqz  $v0, .L7F01F344
/* 053E38 7F01F308 02202025 */   move  $a0, $s1
/* 053E3C 7F01F30C 00405825 */  move  $t3, $v0
/* 053E40 7F01F310 02206025 */  move  $t4, $s1
/* 053E44 7F01F314 244A0060 */  addiu $t2, $v0, 0x60
.L7F01F318:
/* 053E48 7F01F318 8D610000 */  lw    $at, ($t3)
/* 053E4C 7F01F31C 256B000C */  addiu $t3, $t3, 0xc
/* 053E50 7F01F320 258C000C */  addiu $t4, $t4, 0xc
/* 053E54 7F01F324 AD81FFF4 */  sw    $at, -0xc($t4)
/* 053E58 7F01F328 8D61FFF8 */  lw    $at, -8($t3)
/* 053E5C 7F01F32C AD81FFF8 */  sw    $at, -8($t4)
/* 053E60 7F01F330 8D61FFFC */  lw    $at, -4($t3)
/* 053E64 7F01F334 156AFFF8 */  bne   $t3, $t2, .L7F01F318
/* 053E68 7F01F338 AD81FFFC */   sw    $at, -4($t4)
/* 053E6C 7F01F33C 10000003 */  b     .L7F01F34C
/* 053E70 7F01F340 00000000 */   nop   
.L7F01F344:
/* 053E74 7F01F344 0FC07636 */  jal   set_eeprom_to_folder_num
/* 053E78 7F01F348 02002825 */   move  $a1, $s0
.L7F01F34C:
/* 053E7C 7F01F34C 0FC07649 */  jal   get_selected_bond
/* 053E80 7F01F350 02202025 */   move  $a0, $s1
/* 053E84 7F01F354 00106880 */  sll   $t5, $s0, 2
/* 053E88 7F01F358 3C058003 */  lui   $a1, %hi(save_selected_bond)
/* 053E8C 7F01F35C 00AD2821 */  addu  $a1, $a1, $t5
/* 053E90 7F01F360 8CA5C510 */  lw    $a1, %lo(save_selected_bond)($a1)
/* 053E94 7F01F364 50450007 */  beql  $v0, $a1, .L7F01F384
/* 053E98 7F01F368 8FBF001C */   lw    $ra, 0x1c($sp)
/* 053E9C 7F01F36C 0FC0764D */  jal   set_selected_bond
/* 053EA0 7F01F370 02202025 */   move  $a0, $s1
/* 053EA4 7F01F374 8FA40084 */  lw    $a0, 0x84($sp)
/* 053EA8 7F01F378 0FC07941 */  jal   sub_GAME_7F01E504
/* 053EAC 7F01F37C 02202825 */   move  $a1, $s1
.L7F01F380:
/* 053EB0 7F01F380 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F01F384:
/* 053EB4 7F01F384 8FB00014 */  lw    $s0, 0x14($sp)
/* 053EB8 7F01F388 8FB10018 */  lw    $s1, 0x18($sp)
/* 053EBC 7F01F38C 03E00008 */  jr    $ra
/* 053EC0 7F01F390 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif



#ifdef NONMATCHING
void copy_eeprom_from_to(void) {

}
#else
GLOBAL_ASM(
.text
glabel copy_eeprom_from_to
/* 053EC4 7F01F394 27BDFF80 */  addiu $sp, $sp, -0x80
/* 053EC8 7F01F398 AFBF0014 */  sw    $ra, 0x14($sp)
/* 053ECC 7F01F39C 0FC07771 */  jal   get_save_folder_ptr
/* 053ED0 7F01F3A0 AFA50084 */   sw    $a1, 0x84($sp)
/* 053ED4 7F01F3A4 1040000F */  beqz  $v0, .L7F01F3E4
/* 053ED8 7F01F3A8 8FA30084 */   lw    $v1, 0x84($sp)
/* 053EDC 7F01F3AC 0040C025 */  move  $t8, $v0
/* 053EE0 7F01F3B0 0060C825 */  move  $t9, $v1
/* 053EE4 7F01F3B4 244F0060 */  addiu $t7, $v0, 0x60
.L7F01F3B8:
/* 053EE8 7F01F3B8 8F010000 */  lw    $at, ($t8)
/* 053EEC 7F01F3BC 2718000C */  addiu $t8, $t8, 0xc
/* 053EF0 7F01F3C0 2739000C */  addiu $t9, $t9, 0xc
/* 053EF4 7F01F3C4 AF21FFF4 */  sw    $at, -0xc($t9)
/* 053EF8 7F01F3C8 8F01FFF8 */  lw    $at, -8($t8)
/* 053EFC 7F01F3CC AF21FFF8 */  sw    $at, -8($t9)
/* 053F00 7F01F3D0 8F01FFFC */  lw    $at, -4($t8)
/* 053F04 7F01F3D4 170FFFF8 */  bne   $t8, $t7, .L7F01F3B8
/* 053F08 7F01F3D8 AF21FFFC */   sw    $at, -4($t9)
/* 053F0C 7F01F3DC 1000001C */  b     .L7F01F450
/* 053F10 7F01F3E0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F01F3E4:
/* 053F14 7F01F3E4 3C088003 */  lui   $t0, %hi(blank_eeprom) 
/* 053F18 7F01F3E8 27A2001C */  addiu $v0, $sp, 0x1c
/* 053F1C 7F01F3EC 2508C8A0 */  addiu $t0, %lo(blank_eeprom) # addiu $t0, $t0, -0x3760
/* 053F20 7F01F3F0 250A0060 */  addiu $t2, $t0, 0x60
/* 053F24 7F01F3F4 00405825 */  move  $t3, $v0
.L7F01F3F8:
/* 053F28 7F01F3F8 8D010000 */  lw    $at, ($t0)
/* 053F2C 7F01F3FC 2508000C */  addiu $t0, $t0, 0xc
/* 053F30 7F01F400 256B000C */  addiu $t3, $t3, 0xc
/* 053F34 7F01F404 AD61FFF4 */  sw    $at, -0xc($t3)
/* 053F38 7F01F408 8D01FFF8 */  lw    $at, -8($t0)
/* 053F3C 7F01F40C AD61FFF8 */  sw    $at, -8($t3)
/* 053F40 7F01F410 8D01FFFC */  lw    $at, -4($t0)
/* 053F44 7F01F414 150AFFF8 */  bne   $t0, $t2, .L7F01F3F8
/* 053F48 7F01F418 AD61FFFC */   sw    $at, -4($t3)
/* 053F4C 7F01F41C 00407025 */  move  $t6, $v0
/* 053F50 7F01F420 00607825 */  move  $t7, $v1
/* 053F54 7F01F424 244D0060 */  addiu $t5, $v0, 0x60
.L7F01F428:
/* 053F58 7F01F428 8DC10000 */  lw    $at, ($t6)
/* 053F5C 7F01F42C 25CE000C */  addiu $t6, $t6, 0xc
/* 053F60 7F01F430 25EF000C */  addiu $t7, $t7, 0xc
/* 053F64 7F01F434 ADE1FFF4 */  sw    $at, -0xc($t7)
/* 053F68 7F01F438 8DC1FFF8 */  lw    $at, -8($t6)
/* 053F6C 7F01F43C ADE1FFF8 */  sw    $at, -8($t7)
/* 053F70 7F01F440 8DC1FFFC */  lw    $at, -4($t6)
/* 053F74 7F01F444 15CDFFF8 */  bne   $t6, $t5, .L7F01F428
/* 053F78 7F01F448 ADE1FFFC */   sw    $at, -4($t7)
/* 053F7C 7F01F44C 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F01F450:
/* 053F80 7F01F450 27BD0080 */  addiu $sp, $sp, 0x80
/* 053F84 7F01F454 03E00008 */  jr    $ra
/* 053F88 7F01F458 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void copy_eepromfile_a0_from_a1_to_buffer(void) {

}
#else
GLOBAL_ASM(
.text
glabel copy_eepromfile_a0_from_a1_to_buffer
/* 053F8C 7F01F45C 24010064 */  li    $at, 100
/* 053F90 7F01F460 1481000D */  bne   $a0, $at, .L7F01F498
/* 053F94 7F01F464 3C0E8007 */   lui   $t6, %hi(save6) 
/* 053F98 7F01F468 25CE9B00 */  addiu $t6, %lo(save6) # addiu $t6, $t6, -0x6500
/* 053F9C 7F01F46C 00A0C825 */  move  $t9, $a1
/* 053FA0 7F01F470 24B80060 */  addiu $t8, $a1, 0x60
.L7F01F474:
/* 053FA4 7F01F474 8F210000 */  lw    $at, ($t9)
/* 053FA8 7F01F478 2739000C */  addiu $t9, $t9, 0xc
/* 053FAC 7F01F47C 25CE000C */  addiu $t6, $t6, 0xc
/* 053FB0 7F01F480 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 053FB4 7F01F484 8F21FFF8 */  lw    $at, -8($t9)
/* 053FB8 7F01F488 ADC1FFF8 */  sw    $at, -8($t6)
/* 053FBC 7F01F48C 8F21FFFC */  lw    $at, -4($t9)
/* 053FC0 7F01F490 1738FFF8 */  bne   $t9, $t8, .L7F01F474
/* 053FC4 7F01F494 ADC1FFFC */   sw    $at, -4($t6)
.L7F01F498:
/* 053FC8 7F01F498 03E00008 */  jr    $ra
/* 053FCC 7F01F49C 00000000 */   nop   
)
#endif



#ifdef NONMATCHING

BOOL is007ModeUnlockedinFolder(u32 foldernum)

{
    save_file *folder;
    BOOL BVar1;
    BOOL found;
    int stagenum;
    
    folder = getEEPROMforFoldernum(foldernum);
    if (folder == NULL) {
        BVar1 = FALSE;
    }
    else {
        stagenum = SP_STAGE_DAM;
        if ((folder->bitflags & 1) == 0) {
            do {
                found = doesSaveHaveStageCompletedOnDifficulty(folder,stagenum,DIFFICULTY_00);
                if (found == FALSE) break;
                stagenum += SP_STAGE_FACILITY;
            } while (stagenum != 0x14);
            if (stagenum == SP_STAGE_MAX) {
                BVar1 = TRUE;
            }
            else {
                BVar1 = FALSE;
            }
        }
        else {
            BVar1 = TRUE;
        }
    }
    return BVar1;
}
#else
GLOBAL_ASM(
.text
glabel check_for_007_mode_unlocked
/* 053FD0 7F01F4A0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 053FD4 7F01F4A4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 053FD8 7F01F4A8 AFB20020 */  sw    $s2, 0x20($sp)
/* 053FDC 7F01F4AC AFB1001C */  sw    $s1, 0x1c($sp)
/* 053FE0 7F01F4B0 0FC07771 */  jal   get_save_folder_ptr
/* 053FE4 7F01F4B4 AFB00018 */   sw    $s0, 0x18($sp)
/* 053FE8 7F01F4B8 10400016 */  beqz  $v0, .L7F01F514
/* 053FEC 7F01F4BC 00408825 */   move  $s1, $v0
/* 053FF0 7F01F4C0 904E0009 */  lbu   $t6, 9($v0)
/* 053FF4 7F01F4C4 00008025 */  move  $s0, $zero
/* 053FF8 7F01F4C8 24120014 */  li    $s2, 20
/* 053FFC 7F01F4CC 31CF0001 */  andi  $t7, $t6, 1
/* 054000 7F01F4D0 11E00003 */  beqz  $t7, .L7F01F4E0
/* 054004 7F01F4D4 00000000 */   nop   
/* 054008 7F01F4D8 1000000F */  b     .L7F01F518
/* 05400C 7F01F4DC 24020001 */   li    $v0, 1
.L7F01F4E0:
/* 054010 7F01F4E0 02202025 */  move  $a0, $s1
.L7F01F4E4:
/* 054014 7F01F4E4 02002825 */  move  $a1, $s0
/* 054018 7F01F4E8 0FC07718 */  jal   get_eeprom_stage_completed_for_difficulty
/* 05401C 7F01F4EC 24060002 */   li    $a2, 2
/* 054020 7F01F4F0 10400004 */  beqz  $v0, .L7F01F504
/* 054024 7F01F4F4 00000000 */   nop   
/* 054028 7F01F4F8 26100001 */  addiu $s0, $s0, 1
/* 05402C 7F01F4FC 5612FFF9 */  bnel  $s0, $s2, .L7F01F4E4
/* 054030 7F01F500 02202025 */   move  $a0, $s1
.L7F01F504:
/* 054034 7F01F504 56120004 */  bnel  $s0, $s2, .L7F01F518
/* 054038 7F01F508 00001025 */   move  $v0, $zero
/* 05403C 7F01F50C 10000002 */  b     .L7F01F518
/* 054040 7F01F510 24020001 */   li    $v0, 1
.L7F01F514:
/* 054044 7F01F514 00001025 */  move  $v0, $zero
.L7F01F518:
/* 054048 7F01F518 8FBF0024 */  lw    $ra, 0x24($sp)
/* 05404C 7F01F51C 8FB00018 */  lw    $s0, 0x18($sp)
/* 054050 7F01F520 8FB1001C */  lw    $s1, 0x1c($sp)
/* 054054 7F01F524 8FB20020 */  lw    $s2, 0x20($sp)
/* 054058 7F01F528 03E00008 */  jr    $ra
/* 05405C 7F01F52C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





