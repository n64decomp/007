#include "ultra64.h"
//#include ""

// bss
//CODE.bss:8008C600
s32 dword_CODE_bss_8008C600;
//CODE.bss:8008C604
s32 dword_CODE_bss_8008C604;
//CODE.bss:8008C608
s32 dword_CODE_bss_8008C608;
//CODE.bss:8008C60C
s32 dword_CODE_bss_8008C60C;
//CODE.bss:8008C610
s32 dword_CODE_bss_8008C610;
//CODE.bss:8008C614
s32 dword_CODE_bss_8008C614;
//CODE.bss:8008C618
s32 dword_CODE_bss_8008C618;
//CODE.bss:8008C61C
s32 dword_CODE_bss_8008C61C;
//CODE.bss:8008C620
s32 dword_CODE_bss_8008C620;
//CODE.bss:8008C624
s32 dword_CODE_bss_8008C624;
//CODE.bss:8008C628
s32 dword_CODE_bss_8008C628;
//CODE.bss:8008C62C
s32 dword_CODE_bss_8008C62C;
//CODE.bss:8008C630
s32 dword_CODE_bss_8008C630;
//CODE.bss:8008C634
s32 dword_CODE_bss_8008C634;


// data
//D:800484C0
s32 mission_state = 0;





void sub_GAME_7F0C0C10(void) {
  sub_GAME_7F0A9180();
}

s32 get_mission_state(void) {
  return mission_state;
}






#ifdef NONMATCHING
void set_missionstate(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005B790*/
glabel jpt_8005B790
.word .L7F0C0C74
.word .L7F0C0D28
.word .L7F0C0E18
.word .L7F0C0EB0
.word .L7F0C0FE8
.word .L7F0C10B4
.word .L7F0C115C

/*D:8005B7AC*/
glabel jpt_8005B7AC
.word .L7F0C11EC
.word .L7F0C0C94
.word .L7F0C0D28
.word .L7F0C0D28
.word .L7F0C0CC8
.word .L7F0C0D28
.word .L7F0C0D28

/*D:8005B7C8*/
glabel jpt_8005B7C8
.word .L7F0C0D48
.word .L7F0C0E18
.word .L7F0C0D68
.word .L7F0C0DAC
.word .L7F0C0E18
.word .L7F0C0E18
.word .L7F0C0DE4

glabel music_rate_8005B7E4
.word 0x3ca3d70a /*0.02*/

/*D:8005B7E8*/
glabel jpt_8005B7E8
.word .L7F0C0E38
.word .L7F0C0E58
.word .L7F0C11EC
.word .L7F0C0E88
.word .L7F0C0EB0
.word .L7F0C0EB0
.word .L7F0C0EB0

/*D:8005B804*/
glabel jpt_8005B804
.word .L7F0C0ED0
.word .L7F0C0EF0
.word .L7F0C0F20
.word .L7F0C0FE8
.word .L7F0C0F54
.word .L7F0C0F9C
.word .L7F0C0FE8

/*D:8005B820*/
glabel jpt_8005B820
.word .L7F0C1008
.word .L7F0C10B4
.word .L7F0C10B4
.word .L7F0C1028
.word .L7F0C10B4
.word .L7F0C1070
.word .L7F0C10B4

/*D:8005B83C*/
glabel jpt_8005B83C
.word .L7F0C10D4
.word .L7F0C115C
.word .L7F0C115C
.word .L7F0C10F4
.word .L7F0C112C
.word .L7F0C115C
.word .L7F0C115C

/*D:8005B858*/
glabel jpt_8005B858
.word .L7F0C117C
.word .L7F0C119C
.word .L7F0C11E4
.word .L7F0C11E4
.word .L7F0C11E4
.word .L7F0C11E4
.word .L7F0C11CC


.text
glabel set_missionstate
/* 0F576C set_missionstate 3C038005 */  lui   $v1, %hi(mission_state) # $v1, 0x8005
/* 0F5770 7F0C0C40 246384C0 */  addiu $v1, %lo(mission_state) # addiu $v1, $v1, -0x7b40
/* 0F5774 7F0C0C44 8C620000 */  lw    $v0, ($v1)
/* 0F5778 7F0C0C48 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F577C 7F0C0C4C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F5780 7F0C0C50 2C410007 */  sltiu $at, $v0, 7
/* 0F5784 7F0C0C54 10200163 */  beqz  $at, .L7F0C11E4
/* 0F5788 7F0C0C58 AC640000 */   sw    $a0, ($v1)
/* 0F578C 7F0C0C5C 00027080 */  sll   $t6, $v0, 2
/* 0F5790 7F0C0C60 3C018006 */  lui   $at, %hi(jpt_8005B790)
/* 0F5794 7F0C0C64 002E0821 */  addu  $at, $at, $t6
/* 0F5798 7F0C0C68 8C2EB790 */  lw    $t6, %lo(jpt_8005B790)($at)
/* 0F579C 7F0C0C6C 01C00008 */  jr    $t6
/* 0F57A0 7F0C0C70 00000000 */   nop   
.L7F0C0C74:
/* 0F57A4 7F0C0C74 2C810007 */  sltiu $at, $a0, 7
/* 0F57A8 7F0C0C78 1020002B */  beqz  $at, .L7F0C0D28
/* 0F57AC 7F0C0C7C 00047880 */   sll   $t7, $a0, 2
/* 0F57B0 7F0C0C80 3C018006 */  lui   $at, %hi(jpt_8005B7AC)
/* 0F57B4 7F0C0C84 002F0821 */  addu  $at, $at, $t7
/* 0F57B8 7F0C0C88 8C2FB7AC */  lw    $t7, %lo(jpt_8005B7AC)($at)
/* 0F57BC 7F0C0C8C 01E00008 */  jr    $t7
/* 0F57C0 7F0C0C90 00000000 */   nop   
.L7F0C0C94:
/* 0F57C4 7F0C0C94 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F57C8 7F0C0C98 00000000 */   nop   
/* 0F57CC 7F0C0C9C 0C001C0F */  jal   musicTrack1Vol
/* 0F57D0 7F0C0CA0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F57D4 7F0C0CA4 3C018002 */  lui   $at, %hi(music1_playing) # $at, 0x8002
/* 0F57D8 7F0C0CA8 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F57DC 7F0C0CAC AC20434C */  sw    $zero, %lo(music1_playing)($at)
/* 0F57E0 7F0C0CB0 0FC349C8 */  jal   sub_GAME_7F0D2720
/* 0F57E4 7F0C0CB4 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F57E8 7F0C0CB8 0C001B9F */  jal   musicTrack1Play
/* 0F57EC 7F0C0CBC 00402025 */   move  $a0, $v0
/* 0F57F0 7F0C0CC0 1000014B */  b     .L7F0C11F0
/* 0F57F4 7F0C0CC4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0CC8:
/* 0F57F8 7F0C0CC8 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F57FC 7F0C0CCC 00000000 */   nop   
/* 0F5800 7F0C0CD0 0C001C0F */  jal   musicTrack1Vol
/* 0F5804 7F0C0CD4 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5808 7F0C0CD8 3C018002 */  lui   $at, %hi(music1_playing) # $at, 0x8002
/* 0F580C 7F0C0CDC 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F5810 7F0C0CE0 AC20434C */  sw    $zero, %lo(music1_playing)($at)
/* 0F5814 7F0C0CE4 0FC349C8 */  jal   sub_GAME_7F0D2720
/* 0F5818 7F0C0CE8 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F581C 7F0C0CEC 0C001B9F */  jal   musicTrack1Play
/* 0F5820 7F0C0CF0 00402025 */   move  $a0, $v0
/* 0F5824 7F0C0CF4 0FC30304 */  jal   sub_GAME_7F0C0C10
/* 0F5828 7F0C0CF8 00000000 */   nop   
/* 0F582C 7F0C0CFC 0C001DD3 */  jal   musicTrack3Vol
/* 0F5830 7F0C0D00 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5834 7F0C0D04 3C018002 */  lui   $at, %hi(music3_playing) # $at, 0x8002
/* 0F5838 7F0C0D08 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F583C 7F0C0D0C AC204354 */  sw    $zero, %lo(music3_playing)($at)
/* 0F5840 7F0C0D10 0FC34A12 */  jal   sub_GAME_7F0D2848
/* 0F5844 7F0C0D14 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F5848 7F0C0D18 0C001D63 */  jal   music_related_3rd_block
/* 0F584C 7F0C0D1C 00402025 */   move  $a0, $v0
/* 0F5850 7F0C0D20 10000133 */  b     .L7F0C11F0
/* 0F5854 7F0C0D24 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0D28:
/* 0F5858 7F0C0D28 2C810007 */  sltiu $at, $a0, 7
/* 0F585C 7F0C0D2C 1020003A */  beqz  $at, .L7F0C0E18
/* 0F5860 7F0C0D30 0004C080 */   sll   $t8, $a0, 2
/* 0F5864 7F0C0D34 3C018006 */  lui   $at, %hi(jpt_8005B7C8)
/* 0F5868 7F0C0D38 00380821 */  addu  $at, $at, $t8
/* 0F586C 7F0C0D3C 8C38B7C8 */  lw    $t8, %lo(jpt_8005B7C8)($at)
/* 0F5870 7F0C0D40 03000008 */  jr    $t8
/* 0F5874 7F0C0D44 00000000 */   nop   
.L7F0C0D48:
/* 0F5878 7F0C0D48 0C001BF4 */  jal   musicTrack1Stop
/* 0F587C 7F0C0D4C 00000000 */   nop   
/* 0F5880 7F0C0D50 0C001CD6 */  jal   musicTrack2Stop
/* 0F5884 7F0C0D54 00000000 */   nop   
/* 0F5888 7F0C0D58 0C001DB8 */  jal   musicTrack3Stop
/* 0F588C 7F0C0D5C 00000000 */   nop   
/* 0F5890 7F0C0D60 10000123 */  b     .L7F0C11F0
/* 0F5894 7F0C0D64 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0D68:
/* 0F5898 7F0C0D68 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F589C 7F0C0D6C 00000000 */   nop   
/* 0F58A0 7F0C0D70 0C001CF1 */  jal   musicTrack2Vol
/* 0F58A4 7F0C0D74 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F58A8 7F0C0D78 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F58AC 7F0C0D7C 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F58B0 7F0C0D80 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F58B4 7F0C0D84 0FC34A24 */  jal   sub_GAME_7F0D2890
/* 0F58B8 7F0C0D88 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F58BC 7F0C0D8C 0C001C81 */  jal   musicTrack2Play
/* 0F58C0 7F0C0D90 00402025 */   move  $a0, $v0
/* 0F58C4 7F0C0D94 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F58C8 7F0C0D98 44816000 */  mtc1  $at, $f12
/* 0F58CC 7F0C0D9C 0C001C3E */  jal   music_related_1
/* 0F58D0 7F0C0DA0 00000000 */   nop   
/* 0F58D4 7F0C0DA4 10000112 */  b     .L7F0C11F0
/* 0F58D8 7F0C0DA8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0DAC:
/* 0F58DC 7F0C0DAC 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F58E0 7F0C0DB0 00000000 */   nop   
/* 0F58E4 7F0C0DB4 0C001CF1 */  jal   musicTrack2Vol
/* 0F58E8 7F0C0DB8 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F58EC 7F0C0DBC 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F58F0 7F0C0DC0 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F58F4 7F0C0DC4 0C001C81 */  jal   musicTrack2Play
/* 0F58F8 7F0C0DC8 24040018 */   li    $a0, 24
/* 0F58FC 7F0C0DCC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5900 7F0C0DD0 44816000 */  mtc1  $at, $f12
/* 0F5904 7F0C0DD4 0C001C3E */  jal   music_related_1
/* 0F5908 7F0C0DD8 00000000 */   nop   
/* 0F590C 7F0C0DDC 10000104 */  b     .L7F0C11F0
/* 0F5910 7F0C0DE0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0DE4:
/* 0F5914 7F0C0DE4 3C018006 */  lui   $at, %hi(music_rate_8005B7E4) # $at, 0x8006
/* 0F5918 7F0C0DE8 0C001C3E */  jal   music_related_1
/* 0F591C 7F0C0DEC C42CB7E4 */   lwc1  $f12, %lo(music_rate_8005B7E4)($at)
/* 0F5920 7F0C0DF0 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5924 7F0C0DF4 00000000 */   nop   
/* 0F5928 7F0C0DF8 0C001CF1 */  jal   musicTrack2Vol
/* 0F592C 7F0C0DFC 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5930 7F0C0E00 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F5934 7F0C0E04 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5938 7F0C0E08 0C001C81 */  jal   musicTrack2Play
/* 0F593C 7F0C0E0C 2404003A */   li    $a0, 58
/* 0F5940 7F0C0E10 100000F7 */  b     .L7F0C11F0
/* 0F5944 7F0C0E14 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0E18:
/* 0F5948 7F0C0E18 2C810007 */  sltiu $at, $a0, 7
/* 0F594C 7F0C0E1C 10200024 */  beqz  $at, .L7F0C0EB0
/* 0F5950 7F0C0E20 0004C880 */   sll   $t9, $a0, 2
/* 0F5954 7F0C0E24 3C018006 */  lui   $at, %hi(jpt_8005B7E8)
/* 0F5958 7F0C0E28 00390821 */  addu  $at, $at, $t9
/* 0F595C 7F0C0E2C 8C39B7E8 */  lw    $t9, %lo(jpt_8005B7E8)($at)
/* 0F5960 7F0C0E30 03200008 */  jr    $t9
/* 0F5964 7F0C0E34 00000000 */   nop   
.L7F0C0E38:
/* 0F5968 7F0C0E38 0C001BF4 */  jal   musicTrack1Stop
/* 0F596C 7F0C0E3C 00000000 */   nop   
/* 0F5970 7F0C0E40 0C001CD6 */  jal   musicTrack2Stop
/* 0F5974 7F0C0E44 00000000 */   nop   
/* 0F5978 7F0C0E48 0C001DB8 */  jal   musicTrack3Stop
/* 0F597C 7F0C0E4C 00000000 */   nop   
/* 0F5980 7F0C0E50 100000E7 */  b     .L7F0C11F0
/* 0F5984 7F0C0E54 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0E58:
/* 0F5988 7F0C0E58 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F598C 7F0C0E5C 00000000 */   nop   
/* 0F5990 7F0C0E60 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5994 7F0C0E64 44816000 */  mtc1  $at, $f12
/* 0F5998 7F0C0E68 0C001C5A */  jal   music_related_3
/* 0F599C 7F0C0E6C 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F59A0 7F0C0E70 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F59A4 7F0C0E74 44816000 */  mtc1  $at, $f12
/* 0F59A8 7F0C0E78 0C001D20 */  jal   music_related_6
/* 0F59AC 7F0C0E7C 00000000 */   nop   
/* 0F59B0 7F0C0E80 100000DB */  b     .L7F0C11F0
/* 0F59B4 7F0C0E84 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0E88:
/* 0F59B8 7F0C0E88 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F59BC 7F0C0E8C 00000000 */   nop   
/* 0F59C0 7F0C0E90 0C001CF1 */  jal   musicTrack2Vol
/* 0F59C4 7F0C0E94 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F59C8 7F0C0E98 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F59CC 7F0C0E9C AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F59D0 7F0C0EA0 0C001C81 */  jal   musicTrack2Play
/* 0F59D4 7F0C0EA4 24040018 */   li    $a0, 24
/* 0F59D8 7F0C0EA8 100000D1 */  b     .L7F0C11F0
/* 0F59DC 7F0C0EAC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0EB0:
/* 0F59E0 7F0C0EB0 2C810007 */  sltiu $at, $a0, 7
/* 0F59E4 7F0C0EB4 1020004C */  beqz  $at, .L7F0C0FE8
/* 0F59E8 7F0C0EB8 00044080 */   sll   $t0, $a0, 2
/* 0F59EC 7F0C0EBC 3C018006 */  lui   $at, %hi(jpt_8005B804)
/* 0F59F0 7F0C0EC0 00280821 */  addu  $at, $at, $t0
/* 0F59F4 7F0C0EC4 8C28B804 */  lw    $t0, %lo(jpt_8005B804)($at)
/* 0F59F8 7F0C0EC8 01000008 */  jr    $t0
/* 0F59FC 7F0C0ECC 00000000 */   nop   
.L7F0C0ED0:
/* 0F5A00 7F0C0ED0 0C001BF4 */  jal   musicTrack1Stop
/* 0F5A04 7F0C0ED4 00000000 */   nop   
/* 0F5A08 7F0C0ED8 0C001CD6 */  jal   musicTrack2Stop
/* 0F5A0C 7F0C0EDC 00000000 */   nop   
/* 0F5A10 7F0C0EE0 0C001DB8 */  jal   musicTrack3Stop
/* 0F5A14 7F0C0EE4 00000000 */   nop   
/* 0F5A18 7F0C0EE8 100000C1 */  b     .L7F0C11F0
/* 0F5A1C 7F0C0EEC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0EF0:
/* 0F5A20 7F0C0EF0 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5A24 7F0C0EF4 00000000 */   nop   
/* 0F5A28 7F0C0EF8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5A2C 7F0C0EFC 44816000 */  mtc1  $at, $f12
/* 0F5A30 7F0C0F00 0C001C5A */  jal   music_related_3
/* 0F5A34 7F0C0F04 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5A38 7F0C0F08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5A3C 7F0C0F0C 44816000 */  mtc1  $at, $f12
/* 0F5A40 7F0C0F10 0C001D20 */  jal   music_related_6
/* 0F5A44 7F0C0F14 00000000 */   nop   
/* 0F5A48 7F0C0F18 100000B5 */  b     .L7F0C11F0
/* 0F5A4C 7F0C0F1C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0F20:
/* 0F5A50 7F0C0F20 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5A54 7F0C0F24 00000000 */   nop   
/* 0F5A58 7F0C0F28 0C001CF1 */  jal   musicTrack2Vol
/* 0F5A5C 7F0C0F2C 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5A60 7F0C0F30 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F5A64 7F0C0F34 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F5A68 7F0C0F38 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5A6C 7F0C0F3C 0FC34A24 */  jal   sub_GAME_7F0D2890
/* 0F5A70 7F0C0F40 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F5A74 7F0C0F44 0C001C81 */  jal   musicTrack2Play
/* 0F5A78 7F0C0F48 00402025 */   move  $a0, $v0
/* 0F5A7C 7F0C0F4C 100000A8 */  b     .L7F0C11F0
/* 0F5A80 7F0C0F50 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0F54:
/* 0F5A84 7F0C0F54 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5A88 7F0C0F58 00000000 */   nop   
/* 0F5A8C 7F0C0F5C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5A90 7F0C0F60 44816000 */  mtc1  $at, $f12
/* 0F5A94 7F0C0F64 0C001C5A */  jal   music_related_3
/* 0F5A98 7F0C0F68 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5A9C 7F0C0F6C 0FC30304 */  jal   sub_GAME_7F0C0C10
/* 0F5AA0 7F0C0F70 00000000 */   nop   
/* 0F5AA4 7F0C0F74 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5AA8 7F0C0F78 44816000 */  mtc1  $at, $f12
/* 0F5AAC 7F0C0F7C 0C001E1E */  jal   music_related_13
/* 0F5AB0 7F0C0F80 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5AB4 7F0C0F84 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5AB8 7F0C0F88 44816000 */  mtc1  $at, $f12
/* 0F5ABC 7F0C0F8C 0C001D20 */  jal   music_related_6
/* 0F5AC0 7F0C0F90 00000000 */   nop   
/* 0F5AC4 7F0C0F94 10000096 */  b     .L7F0C11F0
/* 0F5AC8 7F0C0F98 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0F9C:
/* 0F5ACC 7F0C0F9C 0FC30304 */  jal   sub_GAME_7F0C0C10
/* 0F5AD0 7F0C0FA0 00000000 */   nop   
/* 0F5AD4 7F0C0FA4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5AD8 7F0C0FA8 44816000 */  mtc1  $at, $f12
/* 0F5ADC 7F0C0FAC 0C001E1E */  jal   music_related_13
/* 0F5AE0 7F0C0FB0 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5AE4 7F0C0FB4 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5AE8 7F0C0FB8 00000000 */   nop   
/* 0F5AEC 7F0C0FBC 0C001CF1 */  jal   musicTrack2Vol
/* 0F5AF0 7F0C0FC0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5AF4 7F0C0FC4 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F5AF8 7F0C0FC8 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F5AFC 7F0C0FCC AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5B00 7F0C0FD0 0FC34A24 */  jal   sub_GAME_7F0D2890
/* 0F5B04 7F0C0FD4 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F5B08 7F0C0FD8 0C001C81 */  jal   musicTrack2Play
/* 0F5B0C 7F0C0FDC 00402025 */   move  $a0, $v0
/* 0F5B10 7F0C0FE0 10000083 */  b     .L7F0C11F0
/* 0F5B14 7F0C0FE4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0FE8:
/* 0F5B18 7F0C0FE8 2C810007 */  sltiu $at, $a0, 7
/* 0F5B1C 7F0C0FEC 10200031 */  beqz  $at, .L7F0C10B4
/* 0F5B20 7F0C0FF0 00044880 */   sll   $t1, $a0, 2
/* 0F5B24 7F0C0FF4 3C018006 */  lui   $at, %hi(jpt_8005B820)
/* 0F5B28 7F0C0FF8 00290821 */  addu  $at, $at, $t1
/* 0F5B2C 7F0C0FFC 8C29B820 */  lw    $t1, %lo(jpt_8005B820)($at)
/* 0F5B30 7F0C1000 01200008 */  jr    $t1
/* 0F5B34 7F0C1004 00000000 */   nop   
.L7F0C1008:
/* 0F5B38 7F0C1008 0C001BF4 */  jal   musicTrack1Stop
/* 0F5B3C 7F0C100C 00000000 */   nop   
/* 0F5B40 7F0C1010 0C001CD6 */  jal   musicTrack2Stop
/* 0F5B44 7F0C1014 00000000 */   nop   
/* 0F5B48 7F0C1018 0C001DB8 */  jal   musicTrack3Stop
/* 0F5B4C 7F0C101C 00000000 */   nop   
/* 0F5B50 7F0C1020 10000073 */  b     .L7F0C11F0
/* 0F5B54 7F0C1024 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C1028:
/* 0F5B58 7F0C1028 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5B5C 7F0C102C 00000000 */   nop   
/* 0F5B60 7F0C1030 0C001CF1 */  jal   musicTrack2Vol
/* 0F5B64 7F0C1034 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5B68 7F0C1038 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F5B6C 7F0C103C AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5B70 7F0C1040 0C001C81 */  jal   musicTrack2Play
/* 0F5B74 7F0C1044 24040018 */   li    $a0, 24
/* 0F5B78 7F0C1048 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5B7C 7F0C104C 44816000 */  mtc1  $at, $f12
/* 0F5B80 7F0C1050 0C001C3E */  jal   music_related_1
/* 0F5B84 7F0C1054 00000000 */   nop   
/* 0F5B88 7F0C1058 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5B8C 7F0C105C 44816000 */  mtc1  $at, $f12
/* 0F5B90 7F0C1060 0C001E02 */  jal   music_related_11
/* 0F5B94 7F0C1064 00000000 */   nop   
/* 0F5B98 7F0C1068 10000061 */  b     .L7F0C11F0
/* 0F5B9C 7F0C106C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C1070:
/* 0F5BA0 7F0C1070 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5BA4 7F0C1074 00000000 */   nop   
/* 0F5BA8 7F0C1078 0C001CF1 */  jal   musicTrack2Vol
/* 0F5BAC 7F0C107C 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5BB0 7F0C1080 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F5BB4 7F0C1084 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F5BB8 7F0C1088 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5BBC 7F0C108C 0FC34A24 */  jal   sub_GAME_7F0D2890
/* 0F5BC0 7F0C1090 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F5BC4 7F0C1094 0C001C81 */  jal   musicTrack2Play
/* 0F5BC8 7F0C1098 00402025 */   move  $a0, $v0
/* 0F5BCC 7F0C109C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5BD0 7F0C10A0 44816000 */  mtc1  $at, $f12
/* 0F5BD4 7F0C10A4 0C001C3E */  jal   music_related_1
/* 0F5BD8 7F0C10A8 00000000 */   nop   
/* 0F5BDC 7F0C10AC 10000050 */  b     .L7F0C11F0
/* 0F5BE0 7F0C10B0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C10B4:
/* 0F5BE4 7F0C10B4 2C810007 */  sltiu $at, $a0, 7
/* 0F5BE8 7F0C10B8 10200028 */  beqz  $at, .L7F0C115C
/* 0F5BEC 7F0C10BC 00045080 */   sll   $t2, $a0, 2
/* 0F5BF0 7F0C10C0 3C018006 */  lui   $at, %hi(jpt_8005B83C)
/* 0F5BF4 7F0C10C4 002A0821 */  addu  $at, $at, $t2
/* 0F5BF8 7F0C10C8 8C2AB83C */  lw    $t2, %lo(jpt_8005B83C)($at)
/* 0F5BFC 7F0C10CC 01400008 */  jr    $t2
/* 0F5C00 7F0C10D0 00000000 */   nop   
.L7F0C10D4:
/* 0F5C04 7F0C10D4 0C001BF4 */  jal   musicTrack1Stop
/* 0F5C08 7F0C10D8 00000000 */   nop   
/* 0F5C0C 7F0C10DC 0C001CD6 */  jal   musicTrack2Stop
/* 0F5C10 7F0C10E0 00000000 */   nop   
/* 0F5C14 7F0C10E4 0C001DB8 */  jal   musicTrack3Stop
/* 0F5C18 7F0C10E8 00000000 */   nop   
/* 0F5C1C 7F0C10EC 10000040 */  b     .L7F0C11F0
/* 0F5C20 7F0C10F0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C10F4:
/* 0F5C24 7F0C10F4 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5C28 7F0C10F8 00000000 */   nop   
/* 0F5C2C 7F0C10FC 0C001CF1 */  jal   musicTrack2Vol
/* 0F5C30 7F0C1100 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5C34 7F0C1104 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F5C38 7F0C1108 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5C3C 7F0C110C 0C001C81 */  jal   musicTrack2Play
/* 0F5C40 7F0C1110 24040018 */   li    $a0, 24
/* 0F5C44 7F0C1114 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5C48 7F0C1118 44816000 */  mtc1  $at, $f12
/* 0F5C4C 7F0C111C 0C001E02 */  jal   music_related_11
/* 0F5C50 7F0C1120 00000000 */   nop   
/* 0F5C54 7F0C1124 10000032 */  b     .L7F0C11F0
/* 0F5C58 7F0C1128 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C112C:
/* 0F5C5C 7F0C112C 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5C60 7F0C1130 00000000 */   nop   
/* 0F5C64 7F0C1134 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5C68 7F0C1138 44816000 */  mtc1  $at, $f12
/* 0F5C6C 7F0C113C 0C001C5A */  jal   music_related_3
/* 0F5C70 7F0C1140 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5C74 7F0C1144 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5C78 7F0C1148 44816000 */  mtc1  $at, $f12
/* 0F5C7C 7F0C114C 0C001D20 */  jal   music_related_6
/* 0F5C80 7F0C1150 00000000 */   nop   
/* 0F5C84 7F0C1154 10000026 */  b     .L7F0C11F0
/* 0F5C88 7F0C1158 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C115C:
/* 0F5C8C 7F0C115C 2C810007 */  sltiu $at, $a0, 7
/* 0F5C90 7F0C1160 10200020 */  beqz  $at, .L7F0C11E4
/* 0F5C94 7F0C1164 00045880 */   sll   $t3, $a0, 2
/* 0F5C98 7F0C1168 3C018006 */  lui   $at, %hi(jpt_8005B858)
/* 0F5C9C 7F0C116C 002B0821 */  addu  $at, $at, $t3
/* 0F5CA0 7F0C1170 8C2BB858 */  lw    $t3, %lo(jpt_8005B858)($at)
/* 0F5CA4 7F0C1174 01600008 */  jr    $t3
/* 0F5CA8 7F0C1178 00000000 */   nop   
.L7F0C117C:
/* 0F5CAC 7F0C117C 0C001BF4 */  jal   musicTrack1Stop
/* 0F5CB0 7F0C1180 00000000 */   nop   
/* 0F5CB4 7F0C1184 0C001CD6 */  jal   musicTrack2Stop
/* 0F5CB8 7F0C1188 00000000 */   nop   
/* 0F5CBC 7F0C118C 0C001DB8 */  jal   musicTrack3Stop
/* 0F5CC0 7F0C1190 00000000 */   nop   
/* 0F5CC4 7F0C1194 10000016 */  b     .L7F0C11F0
/* 0F5CC8 7F0C1198 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C119C:
/* 0F5CCC 7F0C119C 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5CD0 7F0C11A0 00000000 */   nop   
/* 0F5CD4 7F0C11A4 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0F5CD8 7F0C11A8 44816000 */  mtc1  $at, $f12
/* 0F5CDC 7F0C11AC 0C001C5A */  jal   music_related_3
/* 0F5CE0 7F0C11B0 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5CE4 7F0C11B4 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0F5CE8 7F0C11B8 44816000 */  mtc1  $at, $f12
/* 0F5CEC 7F0C11BC 0C001D20 */  jal   music_related_6
/* 0F5CF0 7F0C11C0 00000000 */   nop   
/* 0F5CF4 7F0C11C4 1000000A */  b     .L7F0C11F0
/* 0F5CF8 7F0C11C8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C11CC:
/* 0F5CFC 7F0C11CC 3C018002 */  lui   $at, %hi(music2_playing) # $at, 0x8002
/* 0F5D00 7F0C11D0 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5D04 7F0C11D4 0C001C81 */  jal   musicTrack2Play
/* 0F5D08 7F0C11D8 2404003A */   li    $a0, 58
/* 0F5D0C 7F0C11DC 10000004 */  b     .L7F0C11F0
/* 0F5D10 7F0C11E0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C11E4:
/* 0F5D14 7F0C11E4 1000FFFF */  b     .L7F0C11E4
/* 0F5D18 7F0C11E8 00000000 */   nop   
.L7F0C11EC:
/* 0F5D1C 7F0C11EC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C11F0:
/* 0F5D20 7F0C11F0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F5D24 7F0C11F4 03E00008 */  jr    $ra
/* 0F5D28 7F0C11F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0C11FC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0C11FC
/* 0F5D2C 7F0C11FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5D30 7F0C1200 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F5D34 7F0C1204 0C001BF4 */  jal   musicTrack1Stop
/* 0F5D38 7F0C1208 AFA40018 */   sw    $a0, 0x18($sp)
/* 0F5D3C 7F0C120C 0C001CD6 */  jal   musicTrack2Stop
/* 0F5D40 7F0C1210 00000000 */   nop   
/* 0F5D44 7F0C1214 0C001DB8 */  jal   musicTrack3Stop
/* 0F5D48 7F0C1218 00000000 */   nop   
/* 0F5D4C 7F0C121C 8FA40018 */  lw    $a0, 0x18($sp)
/* 0F5D50 7F0C1220 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008C600) # $v0, 0x8009
/* 0F5D54 7F0C1224 3C018005 */  lui   $at, %hi(mission_state) # $at, 0x8005
/* 0F5D58 7F0C1228 2442C600 */  addiu $v0, %lo(dword_CODE_bss_8008C600) # addiu $v0, $v0, -0x3a00
/* 0F5D5C 7F0C122C AC2084C0 */  sw    $zero, %lo(mission_state)($at)
/* 0F5D60 7F0C1230 0FC34A12 */  jal   sub_GAME_7F0D2848
/* 0F5D64 7F0C1234 AC440000 */   sw    $a0, ($v0)
/* 0F5D68 7F0C1238 04410005 */  bgez  $v0, .L7F0C1250
/* 0F5D6C 7F0C123C 00000000 */   nop   
/* 0F5D70 7F0C1240 0FC3030F */  jal   set_missionstate
/* 0F5D74 7F0C1244 24040001 */   li    $a0, 1
/* 0F5D78 7F0C1248 10000004 */  b     .L7F0C125C
/* 0F5D7C 7F0C124C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C1250:
/* 0F5D80 7F0C1250 0FC3030F */  jal   set_missionstate
/* 0F5D84 7F0C1254 24040004 */   li    $a0, 4
/* 0F5D88 7F0C1258 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C125C:
/* 0F5D8C 7F0C125C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F5D90 7F0C1260 03E00008 */  jr    $ra
/* 0F5D94 7F0C1264 00000000 */   nop   
)
#endif





void sub_GAME_7F0C1268(void) {
  set_missionstate(0);
}

void sub_GAME_7F0C1288(void) {
  if (sub_GAME_7F0D2848(dword_CODE_bss_8008C600) < 0) {
    set_missionstate(2);
  }
  else {
    set_missionstate(5);
  }
  return;
}

void sub_GAME_7F0C12CC(void) {
  if (sub_GAME_7F0D2848(dword_CODE_bss_8008C600) < 0) {
    set_missionstate(1);
  }
  else {
    set_missionstate(4);
  }
  return;
}

void sub_GAME_7F0C1310(void) {
  dword_CODE_bss_8008C604 = mission_state;
  set_missionstate(3);
}

void sub_GAME_7F0C1340(void) {
  set_missionstate(dword_CODE_bss_8008C604);
}

void sub_GAME_7F0C1364(void) {
  dword_CODE_bss_8008C608 = 0;
  dword_CODE_bss_8008C618 = 0;
  dword_CODE_bss_8008C628 = 0;
  dword_CODE_bss_8008C60C = 0;
  dword_CODE_bss_8008C61C = 0;
  dword_CODE_bss_8008C62C = 0;
  dword_CODE_bss_8008C610 = 0;
  dword_CODE_bss_8008C620 = 0;
  dword_CODE_bss_8008C630 = 0;
  dword_CODE_bss_8008C614 = 0;
  dword_CODE_bss_8008C624 = 0;
  dword_CODE_bss_8008C634 = 0;
}






#ifdef NONMATCHING
void reset_all_music_slots(void) {

}
#else
GLOBAL_ASM(
.text
glabel reset_all_music_slots
/* 0F5EF8 7F0C13C8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F5EFC 7F0C13CC 3C078009 */  lui   $a3, %hi(dword_CODE_bss_8008C608) # $a3, 0x8009
/* 0F5F00 7F0C13D0 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C618) # $a0, 0x8009
/* 0F5F04 7F0C13D4 3C068005 */  lui   $a2, %hi(clock_timer) # $a2, 0x8005
/* 0F5F08 7F0C13D8 3C098009 */  lui   $t1, %hi(dword_CODE_bss_8008C628) # $t1, 0x8009
/* 0F5F0C 7F0C13DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F5F10 7F0C13E0 00005025 */  move  $t2, $zero
/* 0F5F14 7F0C13E4 2529C628 */  addiu $t1, %lo(dword_CODE_bss_8008C628) # addiu $t1, $t1, -0x39d8
/* 0F5F18 7F0C13E8 8CC68374 */  lw    $a2, %lo(clock_timer)($a2)
/* 0F5F1C 7F0C13EC 2484C618 */  addiu $a0, %lo(dword_CODE_bss_8008C618) # addiu $a0, $a0, -0x39e8
/* 0F5F20 7F0C13F0 24E7C608 */  addiu $a3, %lo(dword_CODE_bss_8008C608) # addiu $a3, $a3, -0x39f8
/* 0F5F24 7F0C13F4 00004025 */  move  $t0, $zero
.L7F0C13F8:
/* 0F5F28 7F0C13F8 8CE50000 */  lw    $a1, ($a3)
/* 0F5F2C 7F0C13FC 54A00005 */  bnezl $a1, .L7F0C1414
/* 0F5F30 7F0C1400 8C820000 */   lw    $v0, ($a0)
/* 0F5F34 7F0C1404 8C8E0000 */  lw    $t6, ($a0)
/* 0F5F38 7F0C1408 59C0001F */  blezl $t6, .L7F0C1488
/* 0F5F3C 7F0C140C 24840004 */   addiu $a0, $a0, 4
/* 0F5F40 7F0C1410 8C820000 */  lw    $v0, ($a0)
.L7F0C1414:
/* 0F5F44 7F0C1414 3C0F8009 */  lui   $t7, %hi(dword_CODE_bss_8008C628) # $t7, 0x8009
/* 0F5F48 7F0C1418 25EFC628 */  addiu $t7, %lo(dword_CODE_bss_8008C628) # addiu $t7, $t7, -0x39d8
/* 0F5F4C 7F0C141C 0046082A */  slt   $at, $v0, $a2
/* 0F5F50 7F0C1420 14200004 */  bnez  $at, .L7F0C1434
/* 0F5F54 7F0C1424 010F1821 */   addu  $v1, $t0, $t7
/* 0F5F58 7F0C1428 0046C023 */  subu  $t8, $v0, $a2
/* 0F5F5C 7F0C142C 10000002 */  b     .L7F0C1438
/* 0F5F60 7F0C1430 AC980000 */   sw    $t8, ($a0)
.L7F0C1434:
/* 0F5F64 7F0C1434 AC800000 */  sw    $zero, ($a0)
.L7F0C1438:
/* 0F5F68 7F0C1438 8C620000 */  lw    $v0, ($v1)
/* 0F5F6C 7F0C143C 10400011 */  beqz  $v0, .L7F0C1484
/* 0F5F70 7F0C1440 0046082A */   slt   $at, $v0, $a2
/* 0F5F74 7F0C1444 14200003 */  bnez  $at, .L7F0C1454
/* 0F5F78 7F0C1448 0046C823 */   subu  $t9, $v0, $a2
/* 0F5F7C 7F0C144C 10000002 */  b     .L7F0C1458
/* 0F5F80 7F0C1450 AC790000 */   sw    $t9, ($v1)
.L7F0C1454:
/* 0F5F84 7F0C1454 AC600000 */  sw    $zero, ($v1)
.L7F0C1458:
/* 0F5F88 7F0C1458 8C6B0000 */  lw    $t3, ($v1)
/* 0F5F8C 7F0C145C 51600009 */  beql  $t3, $zero, .L7F0C1484
/* 0F5F90 7F0C1460 ACE00000 */   sw    $zero, ($a3)
/* 0F5F94 7F0C1464 14A00004 */  bnez  $a1, .L7F0C1478
/* 0F5F98 7F0C1468 00000000 */   nop   
/* 0F5F9C 7F0C146C 8C8C0000 */  lw    $t4, ($a0)
/* 0F5FA0 7F0C1470 51800005 */  beql  $t4, $zero, .L7F0C1488
/* 0F5FA4 7F0C1474 24840004 */   addiu $a0, $a0, 4
.L7F0C1478:
/* 0F5FA8 7F0C1478 10000002 */  b     .L7F0C1484
/* 0F5FAC 7F0C147C 240A0001 */   li    $t2, 1
/* 0F5FB0 7F0C1480 ACE00000 */  sw    $zero, ($a3)
.L7F0C1484:
/* 0F5FB4 7F0C1484 24840004 */  addiu $a0, $a0, 4
.L7F0C1488:
/* 0F5FB8 7F0C1488 25080004 */  addiu $t0, $t0, 4
/* 0F5FBC 7F0C148C 1489FFDA */  bne   $a0, $t1, .L7F0C13F8
/* 0F5FC0 7F0C1490 24E70004 */   addiu $a3, $a3, 4
/* 0F5FC4 7F0C1494 50C00016 */  beql  $a2, $zero, .L7F0C14F0
/* 0F5FC8 7F0C1498 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F5FCC 7F0C149C 0FC3030C */  jal   get_mission_state
/* 0F5FD0 7F0C14A0 AFAA0018 */   sw    $t2, 0x18($sp)
/* 0F5FD4 7F0C14A4 24010002 */  li    $at, 2
/* 0F5FD8 7F0C14A8 10410006 */  beq   $v0, $at, .L7F0C14C4
/* 0F5FDC 7F0C14AC 8FAA0018 */   lw    $t2, 0x18($sp)
/* 0F5FE0 7F0C14B0 0FC3030C */  jal   get_mission_state
/* 0F5FE4 7F0C14B4 AFAA0018 */   sw    $t2, 0x18($sp)
/* 0F5FE8 7F0C14B8 24010005 */  li    $at, 5
/* 0F5FEC 7F0C14BC 14410007 */  bne   $v0, $at, .L7F0C14DC
/* 0F5FF0 7F0C14C0 8FAA0018 */   lw    $t2, 0x18($sp)
.L7F0C14C4:
/* 0F5FF4 7F0C14C4 5540000A */  bnezl $t2, .L7F0C14F0
/* 0F5FF8 7F0C14C8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F5FFC 7F0C14CC 0FC304B3 */  jal   sub_GAME_7F0C12CC
/* 0F6000 7F0C14D0 00000000 */   nop   
/* 0F6004 7F0C14D4 10000006 */  b     .L7F0C14F0
/* 0F6008 7F0C14D8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C14DC:
/* 0F600C 7F0C14DC 51400004 */  beql  $t2, $zero, .L7F0C14F0
/* 0F6010 7F0C14E0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F6014 7F0C14E4 0FC304A2 */  jal   sub_GAME_7F0C1288
/* 0F6018 7F0C14E8 00000000 */   nop   
/* 0F601C 7F0C14EC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C14F0:
/* 0F6020 7F0C14F0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F6024 7F0C14F4 03E00008 */  jr    $ra
/* 0F6028 7F0C14F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void set_musicslot_time(void) {

}
#else
GLOBAL_ASM(
.text
glabel set_musicslot_time
/* 0F602C 7F0C14FC 3C0E8009 */  lui   $t6, %hi(dword_CODE_bss_8008C608) # $t6, 0x8009
/* 0F6030 7F0C1500 25CEC608 */  addiu $t6, %lo(dword_CODE_bss_8008C608) # addiu $t6, $t6, -0x39f8
/* 0F6034 7F0C1504 00041080 */  sll   $v0, $a0, 2
/* 0F6038 7F0C1508 004E1821 */  addu  $v1, $v0, $t6
/* 0F603C 7F0C150C 8C6F0000 */  lw    $t7, ($v1)
/* 0F6040 7F0C1510 2404003C */  li    $a0, 60
/* 0F6044 7F0C1514 15E0000E */  bnez  $t7, .L7F0C1550
/* 0F6048 7F0C1518 00000000 */   nop   
/* 0F604C 7F0C151C 00A40019 */  multu $a1, $a0
/* 0F6050 7F0C1520 24180001 */  li    $t8, 1
/* 0F6054 7F0C1524 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C618)
/* 0F6058 7F0C1528 AC780000 */  sw    $t8, ($v1)
/* 0F605C 7F0C152C 00220821 */  addu  $at, $at, $v0
/* 0F6060 7F0C1530 0000C812 */  mflo  $t9
/* 0F6064 7F0C1534 AC39C618 */  sw    $t9, %lo(dword_CODE_bss_8008C618)($at)
/* 0F6068 7F0C1538 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C628)
/* 0F606C 7F0C153C 00C40019 */  multu $a2, $a0
/* 0F6070 7F0C1540 00220821 */  addu  $at, $at, $v0
/* 0F6074 7F0C1544 00004012 */  mflo  $t0
/* 0F6078 7F0C1548 AC28C628 */  sw    $t0, %lo(dword_CODE_bss_8008C628)($at)
/* 0F607C 7F0C154C 00000000 */  nop   
.L7F0C1550:
/* 0F6080 7F0C1550 03E00008 */  jr    $ra
/* 0F6084 7F0C1554 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void reset_music_in_slot(int lParm1) 
{
  if (-1 < lParm1) {
    (&dword_CODE_bss_8008C608)[(int)lParm1] = 0;
    return;
  }
  dword_CODE_bss_8008C608 = 0;
  dword_CODE_bss_8008C60C = 0;
  dword_CODE_bss_8008C610 = 0;
  dword_CODE_bss_8008C614 = 0;
  dword_CODE_bss_8008C618 = 0;
  dword_CODE_bss_8008C61C = 0;
  dword_CODE_bss_8008C620 = 0;
  dword_CODE_bss_8008C624 = 0;
  dword_CODE_bss_8008C628 = 0;
  dword_CODE_bss_8008C62C = 0;
  dword_CODE_bss_8008C630 = 0;
  dword_CODE_bss_8008C634 = 0;
  return;
}
#else
GLOBAL_ASM(
.text
glabel reset_music_in_slot
/* 0F6088 7F0C1558 04800006 */  bltz  $a0, .L7F0C1574
/* 0F608C 7F0C155C 3C018009 */   lui   $at, %hi(dword_CODE_bss_8008C608)
/* 0F6090 7F0C1560 00047080 */  sll   $t6, $a0, 2
/* 0F6094 7F0C1564 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C608)
/* 0F6098 7F0C1568 002E0821 */  addu  $at, $at, $t6
/* 0F609C 7F0C156C 03E00008 */  jr    $ra
/* 0F60A0 7F0C1570 AC20C608 */   sw    $zero, %lo(dword_CODE_bss_8008C608)($at)

.L7F0C1574:
/* 0F60A4 7F0C1574 AC20C608 */  sw    $zero, %lo(dword_CODE_bss_8008C608)($at)
/* 0F60A8 7F0C1578 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C618) # $at, 0x8009
/* 0F60AC 7F0C157C AC20C618 */  sw    $zero, %lo(dword_CODE_bss_8008C618)($at)
/* 0F60B0 7F0C1580 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C628) # $at, 0x8009
/* 0F60B4 7F0C1584 AC20C628 */  sw    $zero, %lo(dword_CODE_bss_8008C628)($at)
/* 0F60B8 7F0C1588 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C60C) # $at, 0x8009
/* 0F60BC 7F0C158C AC20C60C */  sw    $zero, %lo(dword_CODE_bss_8008C60C)($at)
/* 0F60C0 7F0C1590 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C61C) # $at, 0x8009
/* 0F60C4 7F0C1594 AC20C61C */  sw    $zero, %lo(dword_CODE_bss_8008C61C)($at)
/* 0F60C8 7F0C1598 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C62C) # $at, 0x8009
/* 0F60CC 7F0C159C AC20C62C */  sw    $zero, %lo(dword_CODE_bss_8008C62C)($at)
/* 0F60D0 7F0C15A0 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C610) # $at, 0x8009
/* 0F60D4 7F0C15A4 AC20C610 */  sw    $zero, %lo(dword_CODE_bss_8008C610)($at)
/* 0F60D8 7F0C15A8 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C620) # $at, 0x8009
/* 0F60DC 7F0C15AC AC20C620 */  sw    $zero, %lo(dword_CODE_bss_8008C620)($at)
/* 0F60E0 7F0C15B0 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C630) # $at, 0x8009
/* 0F60E4 7F0C15B4 AC20C630 */  sw    $zero, %lo(dword_CODE_bss_8008C630)($at)
/* 0F60E8 7F0C15B8 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C614) # $at, 0x8009
/* 0F60EC 7F0C15BC AC20C614 */  sw    $zero, %lo(dword_CODE_bss_8008C614)($at)
/* 0F60F0 7F0C15C0 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C624) # $at, 0x8009
/* 0F60F4 7F0C15C4 AC20C624 */  sw    $zero, %lo(dword_CODE_bss_8008C624)($at)
/* 0F60F8 7F0C15C8 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C634) # $at, 0x8009
/* 0F60FC 7F0C15CC AC20C634 */  sw    $zero, %lo(dword_CODE_bss_8008C634)($at)
/* 0F6100 7F0C15D0 03E00008 */  jr    $ra
/* 0F6104 7F0C15D4 00000000 */   nop   
)
#endif



