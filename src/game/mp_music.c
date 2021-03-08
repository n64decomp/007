#include "ultra64.h"
#include "music.h"
#include "music_0D2720.h"

// bss
//CODE.bss:8008C600
s32 dword_CODE_bss_8008C600;
//CODE.bss:8008C604
s32 dword_CODE_bss_8008C604;
//CODE.bss:8008C608
s32 music_slot_active_0;
//CODE.bss:8008C60C
s32 music_slot_active_1;
//CODE.bss:8008C610
s32 music_slot_active_2;
//CODE.bss:8008C614
s32 music_slot_active_3;
//CODE.bss:8008C618
s32 music_slot_minutes_0;
//CODE.bss:8008C61C
s32 music_slot_minutes_1;
//CODE.bss:8008C620
s32 music_slot_minutes_2;
//CODE.bss:8008C624
s32 music_slot_minutes_3;
//CODE.bss:8008C628
s32 music_slot_seconds_0;
//CODE.bss:8008C62C
s32 music_slot_seconds_1;
//CODE.bss:8008C630
s32 music_slot_seconds_2;
//CODE.bss:8008C634
s32 music_slot_seconds_3;


// data
//D:800484C0
s32 mission_state = 0;





void sub_GAME_7F0C0C10(void) {
  call_sfx_c_700091C8();
}

s32 get_mission_state(void) {
  return mission_state;
}






#ifdef NONMATCHING
void set_missionstate(void) {

}
#else
#ifdef VERSION_US
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
/* 0F576C set_missionstate 3C038005 */  lui   $v1, %hi(mission_state)
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
/* 0F57CC 7F0C0C9C 0C001C0F */  jal   musicTrack1ApplySeqpVol
/* 0F57D0 7F0C0CA0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F57D4 7F0C0CA4 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade)
/* 0F57D8 7F0C0CA8 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F57DC 7F0C0CAC AC20434C */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 0F57E0 7F0C0CB0 0FC349C8 */  jal   getmusictrack_or_randomtrack
/* 0F57E4 7F0C0CB4 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F57E8 7F0C0CB8 0C001B9F */  jal   musicTrack1Play
/* 0F57EC 7F0C0CBC 00402025 */   move  $a0, $v0
/* 0F57F0 7F0C0CC0 1000014B */  b     .L7F0C11F0
/* 0F57F4 7F0C0CC4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0CC8:
/* 0F57F8 7F0C0CC8 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F57FC 7F0C0CCC 00000000 */   nop   
/* 0F5800 7F0C0CD0 0C001C0F */  jal   musicTrack1ApplySeqpVol
/* 0F5804 7F0C0CD4 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5808 7F0C0CD8 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade)
/* 0F580C 7F0C0CDC 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5810 7F0C0CE0 AC20434C */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 0F5814 7F0C0CE4 0FC349C8 */  jal   getmusictrack_or_randomtrack
/* 0F5818 7F0C0CE8 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F581C 7F0C0CEC 0C001B9F */  jal   musicTrack1Play
/* 0F5820 7F0C0CF0 00402025 */   move  $a0, $v0
/* 0F5824 7F0C0CF4 0FC30304 */  jal   sub_GAME_7F0C0C10
/* 0F5828 7F0C0CF8 00000000 */   nop   
/* 0F582C 7F0C0CFC 0C001DD3 */  jal   musicTrack3ApplySeqpVol
/* 0F5830 7F0C0D00 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5834 7F0C0D04 3C018002 */  lui   $at, %hi(g_musicXTrack3Fade)
/* 0F5838 7F0C0D08 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F583C 7F0C0D0C AC204354 */  sw    $zero, %lo(g_musicXTrack3Fade)($at)
/* 0F5840 7F0C0D10 0FC34A12 */  jal   musicGetBgTrackForStage
/* 0F5844 7F0C0D14 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F5848 7F0C0D18 0C001D63 */  jal   musicTrack3Play
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
/* 0F58A0 7F0C0D70 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F58A4 7F0C0D74 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F58A8 7F0C0D78 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F58AC 7F0C0D7C 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F58B0 7F0C0D80 AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F58B4 7F0C0D84 0FC34A24 */  jal   musicGetXTrackForStage
/* 0F58B8 7F0C0D88 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F58BC 7F0C0D8C 0C001C81 */  jal   musicTrack2Play
/* 0F58C0 7F0C0D90 00402025 */   move  $a0, $v0
/* 0F58C4 7F0C0D94 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F58C8 7F0C0D98 44816000 */  mtc1  $at, $f12
/* 0F58CC 7F0C0D9C 0C001C3E */  jal   musicTrack1FadeOut
/* 0F58D0 7F0C0DA0 00000000 */   nop   
/* 0F58D4 7F0C0DA4 10000112 */  b     .L7F0C11F0
/* 0F58D8 7F0C0DA8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0DAC:
/* 0F58DC 7F0C0DAC 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F58E0 7F0C0DB0 00000000 */   nop   
/* 0F58E4 7F0C0DB4 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F58E8 7F0C0DB8 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F58EC 7F0C0DBC 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F58F0 7F0C0DC0 AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F58F4 7F0C0DC4 0C001C81 */  jal   musicTrack2Play
/* 0F58F8 7F0C0DC8 24040018 */   li    $a0, 24
/* 0F58FC 7F0C0DCC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5900 7F0C0DD0 44816000 */  mtc1  $at, $f12
/* 0F5904 7F0C0DD4 0C001C3E */  jal   musicTrack1FadeOut
/* 0F5908 7F0C0DD8 00000000 */   nop   
/* 0F590C 7F0C0DDC 10000104 */  b     .L7F0C11F0
/* 0F5910 7F0C0DE0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0DE4:
/* 0F5914 7F0C0DE4 3C018006 */  lui   $at, %hi(music_rate_8005B7E4)
/* 0F5918 7F0C0DE8 0C001C3E */  jal   musicTrack1FadeOut
/* 0F591C 7F0C0DEC C42CB7E4 */   lwc1  $f12, %lo(music_rate_8005B7E4)($at)
/* 0F5920 7F0C0DF0 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5924 7F0C0DF4 00000000 */   nop   
/* 0F5928 7F0C0DF8 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F592C 7F0C0DFC 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5930 7F0C0E00 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F5934 7F0C0E04 AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
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
/* 0F5998 7F0C0E68 0C001C5A */  jal   musicTrack1FadeIn
/* 0F599C 7F0C0E6C 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F59A0 7F0C0E70 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F59A4 7F0C0E74 44816000 */  mtc1  $at, $f12
/* 0F59A8 7F0C0E78 0C001D20 */  jal   musicTrack2FadeOut
/* 0F59AC 7F0C0E7C 00000000 */   nop   
/* 0F59B0 7F0C0E80 100000DB */  b     .L7F0C11F0
/* 0F59B4 7F0C0E84 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0E88:
/* 0F59B8 7F0C0E88 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F59BC 7F0C0E8C 00000000 */   nop   
/* 0F59C0 7F0C0E90 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F59C4 7F0C0E94 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F59C8 7F0C0E98 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F59CC 7F0C0E9C AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
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
/* 0F5A30 7F0C0F00 0C001C5A */  jal   musicTrack1FadeIn
/* 0F5A34 7F0C0F04 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5A38 7F0C0F08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5A3C 7F0C0F0C 44816000 */  mtc1  $at, $f12
/* 0F5A40 7F0C0F10 0C001D20 */  jal   musicTrack2FadeOut
/* 0F5A44 7F0C0F14 00000000 */   nop   
/* 0F5A48 7F0C0F18 100000B5 */  b     .L7F0C11F0
/* 0F5A4C 7F0C0F1C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0F20:
/* 0F5A50 7F0C0F20 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5A54 7F0C0F24 00000000 */   nop   
/* 0F5A58 7F0C0F28 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F5A5C 7F0C0F2C 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5A60 7F0C0F30 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F5A64 7F0C0F34 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5A68 7F0C0F38 AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F5A6C 7F0C0F3C 0FC34A24 */  jal   musicGetXTrackForStage
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
/* 0F5A94 7F0C0F64 0C001C5A */  jal   musicTrack1FadeIn
/* 0F5A98 7F0C0F68 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5A9C 7F0C0F6C 0FC30304 */  jal   sub_GAME_7F0C0C10
/* 0F5AA0 7F0C0F70 00000000 */   nop   
/* 0F5AA4 7F0C0F74 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5AA8 7F0C0F78 44816000 */  mtc1  $at, $f12
/* 0F5AAC 7F0C0F7C 0C001E1E */  jal   musicTrack3FadeIn
/* 0F5AB0 7F0C0F80 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5AB4 7F0C0F84 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5AB8 7F0C0F88 44816000 */  mtc1  $at, $f12
/* 0F5ABC 7F0C0F8C 0C001D20 */  jal   musicTrack2FadeOut
/* 0F5AC0 7F0C0F90 00000000 */   nop   
/* 0F5AC4 7F0C0F94 10000096 */  b     .L7F0C11F0
/* 0F5AC8 7F0C0F98 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0F9C:
/* 0F5ACC 7F0C0F9C 0FC30304 */  jal   sub_GAME_7F0C0C10
/* 0F5AD0 7F0C0FA0 00000000 */   nop   
/* 0F5AD4 7F0C0FA4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F5AD8 7F0C0FA8 44816000 */  mtc1  $at, $f12
/* 0F5ADC 7F0C0FAC 0C001E1E */  jal   musicTrack3FadeIn
/* 0F5AE0 7F0C0FB0 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5AE4 7F0C0FB4 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5AE8 7F0C0FB8 00000000 */   nop   
/* 0F5AEC 7F0C0FBC 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F5AF0 7F0C0FC0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5AF4 7F0C0FC4 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F5AF8 7F0C0FC8 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5AFC 7F0C0FCC AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F5B00 7F0C0FD0 0FC34A24 */  jal   musicGetXTrackForStage
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
/* 0F5B60 7F0C1030 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F5B64 7F0C1034 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5B68 7F0C1038 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F5B6C 7F0C103C AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F5B70 7F0C1040 0C001C81 */  jal   musicTrack2Play
/* 0F5B74 7F0C1044 24040018 */   li    $a0, 24
/* 0F5B78 7F0C1048 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5B7C 7F0C104C 44816000 */  mtc1  $at, $f12
/* 0F5B80 7F0C1050 0C001C3E */  jal   musicTrack1FadeOut
/* 0F5B84 7F0C1054 00000000 */   nop   
/* 0F5B88 7F0C1058 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5B8C 7F0C105C 44816000 */  mtc1  $at, $f12
/* 0F5B90 7F0C1060 0C001E02 */  jal   musicTrack3FadeOut
/* 0F5B94 7F0C1064 00000000 */   nop   
/* 0F5B98 7F0C1068 10000061 */  b     .L7F0C11F0
/* 0F5B9C 7F0C106C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C1070:
/* 0F5BA0 7F0C1070 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5BA4 7F0C1074 00000000 */   nop   
/* 0F5BA8 7F0C1078 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F5BAC 7F0C107C 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5BB0 7F0C1080 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F5BB4 7F0C1084 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5BB8 7F0C1088 AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F5BBC 7F0C108C 0FC34A24 */  jal   musicGetXTrackForStage
/* 0F5BC0 7F0C1090 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F5BC4 7F0C1094 0C001C81 */  jal   musicTrack2Play
/* 0F5BC8 7F0C1098 00402025 */   move  $a0, $v0
/* 0F5BCC 7F0C109C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5BD0 7F0C10A0 44816000 */  mtc1  $at, $f12
/* 0F5BD4 7F0C10A4 0C001C3E */  jal   musicTrack1FadeOut
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
/* 0F5C2C 7F0C10FC 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F5C30 7F0C1100 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5C34 7F0C1104 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F5C38 7F0C1108 AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F5C3C 7F0C110C 0C001C81 */  jal   musicTrack2Play
/* 0F5C40 7F0C1110 24040018 */   li    $a0, 24
/* 0F5C44 7F0C1114 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5C48 7F0C1118 44816000 */  mtc1  $at, $f12
/* 0F5C4C 7F0C111C 0C001E02 */  jal   musicTrack3FadeOut
/* 0F5C50 7F0C1120 00000000 */   nop   
/* 0F5C54 7F0C1124 10000032 */  b     .L7F0C11F0
/* 0F5C58 7F0C1128 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C112C:
/* 0F5C5C 7F0C112C 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5C60 7F0C1130 00000000 */   nop   
/* 0F5C64 7F0C1134 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5C68 7F0C1138 44816000 */  mtc1  $at, $f12
/* 0F5C6C 7F0C113C 0C001C5A */  jal   musicTrack1FadeIn
/* 0F5C70 7F0C1140 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5C74 7F0C1144 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F5C78 7F0C1148 44816000 */  mtc1  $at, $f12
/* 0F5C7C 7F0C114C 0C001D20 */  jal   musicTrack2FadeOut
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
/* 0F5CDC 7F0C11AC 0C001C5A */  jal   musicTrack1FadeIn
/* 0F5CE0 7F0C11B0 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F5CE4 7F0C11B4 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0F5CE8 7F0C11B8 44816000 */  mtc1  $at, $f12
/* 0F5CEC 7F0C11BC 0C001D20 */  jal   musicTrack2FadeOut
/* 0F5CF0 7F0C11C0 00000000 */   nop   
/* 0F5CF4 7F0C11C4 1000000A */  b     .L7F0C11F0
/* 0F5CF8 7F0C11C8 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C11CC:
/* 0F5CFC 7F0C11CC 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade)
/* 0F5D00 7F0C11D0 AC204350 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
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

#ifdef VERSION_JP
GLOBAL_ASM(
    .late_rodata
/*D:8005B790*/
glabel jpt_8005B790
.word .Ljp7F0C1904
.word .Ljp7F0C19D8
.word .Ljp7F0C1AC8
.word .Ljp7F0C1B60
.word .Ljp7F0C1C98
.word .Ljp7F0C1D64
.word .Ljp7F0C1E0C

/*D:8005B7AC*/
glabel jpt_8005B7AC
.word .Ljp7F0C1924
.word .Ljp7F0C1944
.word .Ljp7F0C19D8
.word .Ljp7F0C19D8
.word .Ljp7F0C1978
.word .Ljp7F0C19D8
.word .Ljp7F0C19D8


/*D:8005B7C8*/
glabel jpt_8005B7C8
.word .Ljp7F0C19F8
.word .Ljp7F0C1AC8
.word .Ljp7F0C1A18
.word .Ljp7F0C1A5C
.word .Ljp7F0C1AC8
.word .Ljp7F0C1AC8
.word .Ljp7F0C1A94

glabel music_rate_8005B7E4
.word 0x3ca3d70a /*0.02*/

/*D:8005B7E8*/
glabel jpt_8005B7E8
.word .Ljp7F0C1AE8
.word .Ljp7F0C1B08
.word .Ljp7F0C1E9C
.word .Ljp7F0C1B38
.word .Ljp7F0C1B60
.word .Ljp7F0C1B60
.word .Ljp7F0C1B60

/*D:8005B804*/
glabel jpt_8005B804
.word .Ljp7F0C1B80
.word .Ljp7F0C1BA0
.word .Ljp7F0C1BD0
.word .Ljp7F0C1C98
.word .Ljp7F0C1C04
.word .Ljp7F0C1C4C
.word .Ljp7F0C1C98

/*D:8005B820*/
glabel jpt_8005B820
.word .Ljp7F0C1CB8
.word .Ljp7F0C1D64
.word .Ljp7F0C1D64
.word .Ljp7F0C1CD8
.word .Ljp7F0C1D64
.word .Ljp7F0C1D20
.word .Ljp7F0C1D64

/*D:8005B83C*/
glabel jpt_8005B83C
.word .Ljp7F0C1D84
.word .Ljp7F0C1E0C
.word .Ljp7F0C1E0C
.word .Ljp7F0C1DA4
.word .Ljp7F0C1DDC
.word .Ljp7F0C1E0C
.word .Ljp7F0C1E0C

/*D:8005B858*/
glabel jpt_8005B858
.word .Ljp7F0C1E2C
.word .Ljp7F0C1E4C
.word .Ljp7F0C1E94
.word .Ljp7F0C1E94
.word .Ljp7F0C1E94
.word .Ljp7F0C1E94
.word .Ljp7F0C1E7C

.text
glabel set_missionstate
/* 0F643C 7F0C18CC 3C038005 */  lui   $v1, %hi(mission_state) # $v1, 0x8005
/* 0F6440 7F0C18D0 246384F0 */  addiu $v1, %lo(mission_state) # addiu $v1, $v1, -0x7b10
/* 0F6444 7F0C18D4 8C620000 */  lw    $v0, ($v1)
/* 0F6448 7F0C18D8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F644C 7F0C18DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F6450 7F0C18E0 2C410007 */  sltiu $at, $v0, 7
/* 0F6454 7F0C18E4 1020016B */  beqz  $at, .Ljp7F0C1E94
/* 0F6458 7F0C18E8 AC640000 */   sw    $a0, ($v1)
/* 0F645C 7F0C18EC 00027080 */  sll   $t6, $v0, 2
/* 0F6460 7F0C18F0 3C018006 */  lui   $at, %hi(jpt_8005B790)
/* 0F6464 7F0C18F4 002E0821 */  addu  $at, $at, $t6
/* 0F6468 7F0C18F8 8C2EB7D0 */  lw    $t6, %lo(jpt_8005B790)($at)
/* 0F646C 7F0C18FC 01C00008 */  jr    $t6
/* 0F6470 7F0C1900 00000000 */   nop   
.Ljp7F0C1904:
/* 0F6474 7F0C1904 2C810007 */  sltiu $at, $a0, 7
/* 0F6478 7F0C1908 10200033 */  beqz  $at, .Ljp7F0C19D8
/* 0F647C 7F0C190C 00047880 */   sll   $t7, $a0, 2
/* 0F6480 7F0C1910 3C018006 */  lui   $at, %hi(jpt_8005B7AC)
/* 0F6484 7F0C1914 002F0821 */  addu  $at, $at, $t7
/* 0F6488 7F0C1918 8C2FB7EC */  lw    $t7, %lo(jpt_8005B7AC)($at)
/* 0F648C 7F0C191C 01E00008 */  jr    $t7
/* 0F6490 7F0C1920 00000000 */   nop   
.Ljp7F0C1924:
/* 0F6494 7F0C1924 0C001BF8 */  jal   musicTrack1Stop
/* 0F6498 7F0C1928 00000000 */   nop   
/* 0F649C 7F0C192C 0C001CDA */  jal   musicTrack2Stop
/* 0F64A0 7F0C1930 00000000 */   nop   
/* 0F64A4 7F0C1934 0C001DBC */  jal   musicTrack3Stop
/* 0F64A8 7F0C1938 00000000 */   nop   
/* 0F64AC 7F0C193C 10000158 */  b     .Ljp7F0C1EA0
/* 0F64B0 7F0C1940 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1944:
/* 0F64B4 7F0C1944 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F64B8 7F0C1948 00000000 */   nop   
/* 0F64BC 7F0C194C 0C001C13 */  jal   musicTrack1ApplySeqpVol
/* 0F64C0 7F0C1950 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F64C4 7F0C1954 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade) # $at, 0x8002
/* 0F64C8 7F0C1958 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F64CC 7F0C195C AC20438C */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 0F64D0 7F0C1960 0FC34D00 */  jal   getmusictrack_or_randomtrack
/* 0F64D4 7F0C1964 8C84C670 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F64D8 7F0C1968 0C001BA3 */  jal   musicTrack1Play
/* 0F64DC 7F0C196C 00402025 */   move  $a0, $v0
/* 0F64E0 7F0C1970 1000014B */  b     .Ljp7F0C1EA0
/* 0F64E4 7F0C1974 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1978:
/* 0F64E8 7F0C1978 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F64EC 7F0C197C 00000000 */   nop   
/* 0F64F0 7F0C1980 0C001C13 */  jal   musicTrack1ApplySeqpVol
/* 0F64F4 7F0C1984 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F64F8 7F0C1988 3C018002 */  lui   $at, %hi(g_musicXTrack1Fade) # $at, 0x8002
/* 0F64FC 7F0C198C 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F6500 7F0C1990 AC20438C */  sw    $zero, %lo(g_musicXTrack1Fade)($at)
/* 0F6504 7F0C1994 0FC34D00 */  jal   getmusictrack_or_randomtrack
/* 0F6508 7F0C1998 8C84C670 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F650C 7F0C199C 0C001BA3 */  jal   musicTrack1Play
/* 0F6510 7F0C19A0 00402025 */   move  $a0, $v0
/* 0F6514 7F0C19A4 0FC30628 */  jal   sub_GAME_7F0C0C10
/* 0F6518 7F0C19A8 00000000 */   nop   
/* 0F651C 7F0C19AC 0C001DD7 */  jal   musicTrack3ApplySeqpVol
/* 0F6520 7F0C19B0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F6524 7F0C19B4 3C018002 */  lui   $at, %hi(g_musicXTrack3Fade) # $at, 0x8002
/* 0F6528 7F0C19B8 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F652C 7F0C19BC AC204394 */  sw    $zero, %lo(g_musicXTrack3Fade)($at)
/* 0F6530 7F0C19C0 0FC34D4A */  jal   musicGetBgTrackForStage
/* 0F6534 7F0C19C4 8C84C670 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F6538 7F0C19C8 0C001D67 */  jal   musicTrack3Play
/* 0F653C 7F0C19CC 00402025 */   move  $a0, $v0
/* 0F6540 7F0C19D0 10000133 */  b     .Ljp7F0C1EA0
/* 0F6544 7F0C19D4 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C19D8:
/* 0F6548 7F0C19D8 2C810007 */  sltiu $at, $a0, 7
/* 0F654C 7F0C19DC 1020003A */  beqz  $at, .Ljp7F0C1AC8
/* 0F6550 7F0C19E0 0004C080 */   sll   $t8, $a0, 2
/* 0F6554 7F0C19E4 3C018006 */  lui   $at, %hi(jpt_8005B7C8)
/* 0F6558 7F0C19E8 00380821 */  addu  $at, $at, $t8
/* 0F655C 7F0C19EC 8C38B808 */  lw    $t8, %lo(jpt_8005B7C8)($at)
/* 0F6560 7F0C19F0 03000008 */  jr    $t8
/* 0F6564 7F0C19F4 00000000 */   nop   
.Ljp7F0C19F8:
/* 0F6568 7F0C19F8 0C001BF8 */  jal   musicTrack1Stop
/* 0F656C 7F0C19FC 00000000 */   nop   
/* 0F6570 7F0C1A00 0C001CDA */  jal   musicTrack2Stop
/* 0F6574 7F0C1A04 00000000 */   nop   
/* 0F6578 7F0C1A08 0C001DBC */  jal   musicTrack3Stop
/* 0F657C 7F0C1A0C 00000000 */   nop   
/* 0F6580 7F0C1A10 10000123 */  b     .Ljp7F0C1EA0
/* 0F6584 7F0C1A14 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1A18:
/* 0F6588 7F0C1A18 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F658C 7F0C1A1C 00000000 */   nop   
/* 0F6590 7F0C1A20 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F6594 7F0C1A24 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F6598 7F0C1A28 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F659C 7F0C1A2C 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F65A0 7F0C1A30 AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F65A4 7F0C1A34 0FC34D5C */  jal   musicGetXTrackForStage
/* 0F65A8 7F0C1A38 8C84C670 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F65AC 7F0C1A3C 0C001C85 */  jal   musicTrack2Play
/* 0F65B0 7F0C1A40 00402025 */   move  $a0, $v0
/* 0F65B4 7F0C1A44 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F65B8 7F0C1A48 44816000 */  mtc1  $at, $f12
/* 0F65BC 7F0C1A4C 0C001C42 */  jal   musicTrack1FadeOut
/* 0F65C0 7F0C1A50 00000000 */   nop   
/* 0F65C4 7F0C1A54 10000112 */  b     .Ljp7F0C1EA0
/* 0F65C8 7F0C1A58 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1A5C:
/* 0F65CC 7F0C1A5C 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F65D0 7F0C1A60 00000000 */   nop   
/* 0F65D4 7F0C1A64 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F65D8 7F0C1A68 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F65DC 7F0C1A6C 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F65E0 7F0C1A70 AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F65E4 7F0C1A74 0C001C85 */  jal   musicTrack2Play
/* 0F65E8 7F0C1A78 24040018 */   li    $a0, 24
/* 0F65EC 7F0C1A7C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F65F0 7F0C1A80 44816000 */  mtc1  $at, $f12
/* 0F65F4 7F0C1A84 0C001C42 */  jal   musicTrack1FadeOut
/* 0F65F8 7F0C1A88 00000000 */   nop   
/* 0F65FC 7F0C1A8C 10000104 */  b     .Ljp7F0C1EA0
/* 0F6600 7F0C1A90 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1A94:
/* 0F6604 7F0C1A94 3C018006 */  lui   $at, %hi(music_rate_8005B7E4) # $at, 0x8006
/* 0F6608 7F0C1A98 0C001C42 */  jal   musicTrack1FadeOut
/* 0F660C 7F0C1A9C C42CB824 */   lwc1  $f12, %lo(music_rate_8005B7E4)($at)
/* 0F6610 7F0C1AA0 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F6614 7F0C1AA4 00000000 */   nop   
/* 0F6618 7F0C1AA8 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F661C 7F0C1AAC 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F6620 7F0C1AB0 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F6624 7F0C1AB4 AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F6628 7F0C1AB8 0C001C85 */  jal   musicTrack2Play
/* 0F662C 7F0C1ABC 2404003A */   li    $a0, 58
/* 0F6630 7F0C1AC0 100000F7 */  b     .Ljp7F0C1EA0
/* 0F6634 7F0C1AC4 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1AC8:
/* 0F6638 7F0C1AC8 2C810007 */  sltiu $at, $a0, 7
/* 0F663C 7F0C1ACC 10200024 */  beqz  $at, .Ljp7F0C1B60
/* 0F6640 7F0C1AD0 0004C880 */   sll   $t9, $a0, 2
/* 0F6644 7F0C1AD4 3C018006 */  lui   $at, 0x8006
/* 0F6648 7F0C1AD8 00390821 */  addu  $at, $at, $t9
/* 0F664C 7F0C1ADC 8C39B828 */  lw    $t9, -0x47d8($at)
/* 0F6650 7F0C1AE0 03200008 */  jr    $t9
/* 0F6654 7F0C1AE4 00000000 */   nop   
.Ljp7F0C1AE8:
/* 0F6658 7F0C1AE8 0C001BF8 */  jal   musicTrack1Stop
/* 0F665C 7F0C1AEC 00000000 */   nop   
/* 0F6660 7F0C1AF0 0C001CDA */  jal   musicTrack2Stop
/* 0F6664 7F0C1AF4 00000000 */   nop   
/* 0F6668 7F0C1AF8 0C001DBC */  jal   musicTrack3Stop
/* 0F666C 7F0C1AFC 00000000 */   nop   
/* 0F6670 7F0C1B00 100000E7 */  b     .Ljp7F0C1EA0
/* 0F6674 7F0C1B04 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1B08:
/* 0F6678 7F0C1B08 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F667C 7F0C1B0C 00000000 */   nop   
/* 0F6680 7F0C1B10 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F6684 7F0C1B14 44816000 */  mtc1  $at, $f12
/* 0F6688 7F0C1B18 0C001C5E */  jal   musicTrack1FadeIn
/* 0F668C 7F0C1B1C 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F6690 7F0C1B20 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F6694 7F0C1B24 44816000 */  mtc1  $at, $f12
/* 0F6698 7F0C1B28 0C001D24 */  jal   musicTrack2FadeOut
/* 0F669C 7F0C1B2C 00000000 */   nop   
/* 0F66A0 7F0C1B30 100000DB */  b     .Ljp7F0C1EA0
/* 0F66A4 7F0C1B34 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1B38:
/* 0F66A8 7F0C1B38 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F66AC 7F0C1B3C 00000000 */   nop   
/* 0F66B0 7F0C1B40 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F66B4 7F0C1B44 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F66B8 7F0C1B48 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F66BC 7F0C1B4C AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F66C0 7F0C1B50 0C001C85 */  jal   musicTrack2Play
/* 0F66C4 7F0C1B54 24040018 */   li    $a0, 24
/* 0F66C8 7F0C1B58 100000D1 */  b     .Ljp7F0C1EA0
/* 0F66CC 7F0C1B5C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1B60:
/* 0F66D0 7F0C1B60 2C810007 */  sltiu $at, $a0, 7
/* 0F66D4 7F0C1B64 1020004C */  beqz  $at, .Ljp7F0C1C98
/* 0F66D8 7F0C1B68 00044080 */   sll   $t0, $a0, 2
/* 0F66DC 7F0C1B6C 3C018006 */  lui   $at, %hi(jpt_8005B804)
/* 0F66E0 7F0C1B70 00280821 */  addu  $at, $at, $t0
/* 0F66E4 7F0C1B74 8C28B844 */  lw    $t0, %lo(jpt_8005B804)($at)
/* 0F66E8 7F0C1B78 01000008 */  jr    $t0
/* 0F66EC 7F0C1B7C 00000000 */   nop   
.Ljp7F0C1B80:
/* 0F66F0 7F0C1B80 0C001BF8 */  jal   musicTrack1Stop
/* 0F66F4 7F0C1B84 00000000 */   nop   
/* 0F66F8 7F0C1B88 0C001CDA */  jal   musicTrack2Stop
/* 0F66FC 7F0C1B8C 00000000 */   nop   
/* 0F6700 7F0C1B90 0C001DBC */  jal   musicTrack3Stop
/* 0F6704 7F0C1B94 00000000 */   nop   
/* 0F6708 7F0C1B98 100000C1 */  b     .Ljp7F0C1EA0
/* 0F670C 7F0C1B9C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1BA0:
/* 0F6710 7F0C1BA0 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F6714 7F0C1BA4 00000000 */   nop   
/* 0F6718 7F0C1BA8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F671C 7F0C1BAC 44816000 */  mtc1  $at, $f12
/* 0F6720 7F0C1BB0 0C001C5E */  jal   musicTrack1FadeIn
/* 0F6724 7F0C1BB4 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F6728 7F0C1BB8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F672C 7F0C1BBC 44816000 */  mtc1  $at, $f12
/* 0F6730 7F0C1BC0 0C001D24 */  jal   musicTrack2FadeOut
/* 0F6734 7F0C1BC4 00000000 */   nop   
/* 0F6738 7F0C1BC8 100000B5 */  b     .Ljp7F0C1EA0
/* 0F673C 7F0C1BCC 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1BD0:
/* 0F6740 7F0C1BD0 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F6744 7F0C1BD4 00000000 */   nop   
/* 0F6748 7F0C1BD8 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F674C 7F0C1BDC 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F6750 7F0C1BE0 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F6754 7F0C1BE4 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F6758 7F0C1BE8 AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F675C 7F0C1BEC 0FC34D5C */  jal   musicGetXTrackForStage
/* 0F6760 7F0C1BF0 8C84C670 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F6764 7F0C1BF4 0C001C85 */  jal   musicTrack2Play
/* 0F6768 7F0C1BF8 00402025 */   move  $a0, $v0
/* 0F676C 7F0C1BFC 100000A8 */  b     .Ljp7F0C1EA0
/* 0F6770 7F0C1C00 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1C04:
/* 0F6774 7F0C1C04 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F6778 7F0C1C08 00000000 */   nop   
/* 0F677C 7F0C1C0C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F6780 7F0C1C10 44816000 */  mtc1  $at, $f12
/* 0F6784 7F0C1C14 0C001C5E */  jal   musicTrack1FadeIn
/* 0F6788 7F0C1C18 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F678C 7F0C1C1C 0FC30628 */  jal   sub_GAME_7F0C0C10
/* 0F6790 7F0C1C20 00000000 */   nop   
/* 0F6794 7F0C1C24 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F6798 7F0C1C28 44816000 */  mtc1  $at, $f12
/* 0F679C 7F0C1C2C 0C001E22 */  jal   musicTrack3FadeIn
/* 0F67A0 7F0C1C30 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F67A4 7F0C1C34 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F67A8 7F0C1C38 44816000 */  mtc1  $at, $f12
/* 0F67AC 7F0C1C3C 0C001D24 */  jal   musicTrack2FadeOut
/* 0F67B0 7F0C1C40 00000000 */   nop   
/* 0F67B4 7F0C1C44 10000096 */  b     .Ljp7F0C1EA0
/* 0F67B8 7F0C1C48 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1C4C:
/* 0F67BC 7F0C1C4C 0FC30628 */  jal   sub_GAME_7F0C0C10
/* 0F67C0 7F0C1C50 00000000 */   nop   
/* 0F67C4 7F0C1C54 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F67C8 7F0C1C58 44816000 */  mtc1  $at, $f12
/* 0F67CC 7F0C1C5C 0C001E22 */  jal   musicTrack3FadeIn
/* 0F67D0 7F0C1C60 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F67D4 7F0C1C64 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F67D8 7F0C1C68 00000000 */   nop   
/* 0F67DC 7F0C1C6C 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F67E0 7F0C1C70 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F67E4 7F0C1C74 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F67E8 7F0C1C78 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F67EC 7F0C1C7C AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F67F0 7F0C1C80 0FC34D5C */  jal   musicGetXTrackForStage
/* 0F67F4 7F0C1C84 8C84C670 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F67F8 7F0C1C88 0C001C85 */  jal   musicTrack2Play
/* 0F67FC 7F0C1C8C 00402025 */   move  $a0, $v0
/* 0F6800 7F0C1C90 10000083 */  b     .Ljp7F0C1EA0
/* 0F6804 7F0C1C94 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1C98:
/* 0F6808 7F0C1C98 2C810007 */  sltiu $at, $a0, 7
/* 0F680C 7F0C1C9C 10200031 */  beqz  $at, .Ljp7F0C1D64
/* 0F6810 7F0C1CA0 00044880 */   sll   $t1, $a0, 2
/* 0F6814 7F0C1CA4 3C018006 */  lui   $at, 0x8006
/* 0F6818 7F0C1CA8 00290821 */  addu  $at, $at, $t1
/* 0F681C 7F0C1CAC 8C29B860 */  lw    $t1, -0x47a0($at)
/* 0F6820 7F0C1CB0 01200008 */  jr    $t1
/* 0F6824 7F0C1CB4 00000000 */   nop   
.Ljp7F0C1CB8:
/* 0F6828 7F0C1CB8 0C001BF8 */  jal   musicTrack1Stop
/* 0F682C 7F0C1CBC 00000000 */   nop   
/* 0F6830 7F0C1CC0 0C001CDA */  jal   musicTrack2Stop
/* 0F6834 7F0C1CC4 00000000 */   nop   
/* 0F6838 7F0C1CC8 0C001DBC */  jal   musicTrack3Stop
/* 0F683C 7F0C1CCC 00000000 */   nop   
/* 0F6840 7F0C1CD0 10000073 */  b     .Ljp7F0C1EA0
/* 0F6844 7F0C1CD4 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1CD8:
/* 0F6848 7F0C1CD8 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F684C 7F0C1CDC 00000000 */   nop   
/* 0F6850 7F0C1CE0 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F6854 7F0C1CE4 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F6858 7F0C1CE8 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F685C 7F0C1CEC AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F6860 7F0C1CF0 0C001C85 */  jal   musicTrack2Play
/* 0F6864 7F0C1CF4 24040018 */   li    $a0, 24
/* 0F6868 7F0C1CF8 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F686C 7F0C1CFC 44816000 */  mtc1  $at, $f12
/* 0F6870 7F0C1D00 0C001C42 */  jal   musicTrack1FadeOut
/* 0F6874 7F0C1D04 00000000 */   nop   
/* 0F6878 7F0C1D08 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F687C 7F0C1D0C 44816000 */  mtc1  $at, $f12
/* 0F6880 7F0C1D10 0C001E06 */  jal   musicTrack3FadeOut
/* 0F6884 7F0C1D14 00000000 */   nop   
/* 0F6888 7F0C1D18 10000061 */  b     .Ljp7F0C1EA0
/* 0F688C 7F0C1D1C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1D20:
/* 0F6890 7F0C1D20 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F6894 7F0C1D24 00000000 */   nop   
/* 0F6898 7F0C1D28 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F689C 7F0C1D2C 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F68A0 7F0C1D30 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F68A4 7F0C1D34 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
/* 0F68A8 7F0C1D38 AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F68AC 7F0C1D3C 0FC34D5C */  jal   musicGetXTrackForStage
/* 0F68B0 7F0C1D40 8C84C670 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F68B4 7F0C1D44 0C001C85 */  jal   musicTrack2Play
/* 0F68B8 7F0C1D48 00402025 */   move  $a0, $v0
/* 0F68BC 7F0C1D4C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F68C0 7F0C1D50 44816000 */  mtc1  $at, $f12
/* 0F68C4 7F0C1D54 0C001C42 */  jal   musicTrack1FadeOut
/* 0F68C8 7F0C1D58 00000000 */   nop   
/* 0F68CC 7F0C1D5C 10000050 */  b     .Ljp7F0C1EA0
/* 0F68D0 7F0C1D60 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1D64:
/* 0F68D4 7F0C1D64 2C810007 */  sltiu $at, $a0, 7
/* 0F68D8 7F0C1D68 10200028 */  beqz  $at, .Ljp7F0C1E0C
/* 0F68DC 7F0C1D6C 00045080 */   sll   $t2, $a0, 2
/* 0F68E0 7F0C1D70 3C018006 */  lui   $at, %hi(jpt_8005B83C)
/* 0F68E4 7F0C1D74 002A0821 */  addu  $at, $at, $t2
/* 0F68E8 7F0C1D78 8C2AB87C */  lw    $t2, %lo(jpt_8005B83C)($at)
/* 0F68EC 7F0C1D7C 01400008 */  jr    $t2
/* 0F68F0 7F0C1D80 00000000 */   nop   
.Ljp7F0C1D84:
/* 0F68F4 7F0C1D84 0C001BF8 */  jal   musicTrack1Stop
/* 0F68F8 7F0C1D88 00000000 */   nop   
/* 0F68FC 7F0C1D8C 0C001CDA */  jal   musicTrack2Stop
/* 0F6900 7F0C1D90 00000000 */   nop   
/* 0F6904 7F0C1D94 0C001DBC */  jal   musicTrack3Stop
/* 0F6908 7F0C1D98 00000000 */   nop   
/* 0F690C 7F0C1D9C 10000040 */  b     .Ljp7F0C1EA0
/* 0F6910 7F0C1DA0 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1DA4:
/* 0F6914 7F0C1DA4 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F6918 7F0C1DA8 00000000 */   nop   
/* 0F691C 7F0C1DAC 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F6920 7F0C1DB0 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F6924 7F0C1DB4 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F6928 7F0C1DB8 AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F692C 7F0C1DBC 0C001C85 */  jal   musicTrack2Play
/* 0F6930 7F0C1DC0 24040018 */   li    $a0, 24
/* 0F6934 7F0C1DC4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F6938 7F0C1DC8 44816000 */  mtc1  $at, $f12
/* 0F693C 7F0C1DCC 0C001E06 */  jal   musicTrack3FadeOut
/* 0F6940 7F0C1DD0 00000000 */   nop   
/* 0F6944 7F0C1DD4 10000032 */  b     .Ljp7F0C1EA0
/* 0F6948 7F0C1DD8 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1DDC:
/* 0F694C 7F0C1DDC 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F6950 7F0C1DE0 00000000 */   nop   
/* 0F6954 7F0C1DE4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F6958 7F0C1DE8 44816000 */  mtc1  $at, $f12
/* 0F695C 7F0C1DEC 0C001C5E */  jal   musicTrack1FadeIn
/* 0F6960 7F0C1DF0 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F6964 7F0C1DF4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F6968 7F0C1DF8 44816000 */  mtc1  $at, $f12
/* 0F696C 7F0C1DFC 0C001D24 */  jal   musicTrack2FadeOut
/* 0F6970 7F0C1E00 00000000 */   nop   
/* 0F6974 7F0C1E04 10000026 */  b     .Ljp7F0C1EA0
/* 0F6978 7F0C1E08 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1E0C:
/* 0F697C 7F0C1E0C 2C810007 */  sltiu $at, $a0, 7
/* 0F6980 7F0C1E10 10200020 */  beqz  $at, .Ljp7F0C1E94
/* 0F6984 7F0C1E14 00045880 */   sll   $t3, $a0, 2
/* 0F6988 7F0C1E18 3C018006 */  lui   $at, %hi(jpt_8005B858)
/* 0F698C 7F0C1E1C 002B0821 */  addu  $at, $at, $t3
/* 0F6990 7F0C1E20 8C2BB898 */  lw    $t3, %lo(jpt_8005B858)($at)
/* 0F6994 7F0C1E24 01600008 */  jr    $t3
/* 0F6998 7F0C1E28 00000000 */   nop   
.Ljp7F0C1E2C:
/* 0F699C 7F0C1E2C 0C001BF8 */  jal   musicTrack1Stop
/* 0F69A0 7F0C1E30 00000000 */   nop   
/* 0F69A4 7F0C1E34 0C001CDA */  jal   musicTrack2Stop
/* 0F69A8 7F0C1E38 00000000 */   nop   
/* 0F69AC 7F0C1E3C 0C001DBC */  jal   musicTrack3Stop
/* 0F69B0 7F0C1E40 00000000 */   nop   
/* 0F69B4 7F0C1E44 10000016 */  b     .Ljp7F0C1EA0
/* 0F69B8 7F0C1E48 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1E4C:
/* 0F69BC 7F0C1E4C 0FC30620 */  jal   sub_GAME_7F0C0BF0
/* 0F69C0 7F0C1E50 00000000 */   nop   
/* 0F69C4 7F0C1E54 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0F69C8 7F0C1E58 44816000 */  mtc1  $at, $f12
/* 0F69CC 7F0C1E5C 0C001C5E */  jal   musicTrack1FadeIn
/* 0F69D0 7F0C1E60 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0F69D4 7F0C1E64 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0F69D8 7F0C1E68 44816000 */  mtc1  $at, $f12
/* 0F69DC 7F0C1E6C 0C001D24 */  jal   musicTrack2FadeOut
/* 0F69E0 7F0C1E70 00000000 */   nop   
/* 0F69E4 7F0C1E74 1000000A */  b     .Ljp7F0C1EA0
/* 0F69E8 7F0C1E78 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1E7C:
/* 0F69EC 7F0C1E7C 3C018002 */  lui   $at, %hi(g_musicXTrack2Fade) # $at, 0x8002
/* 0F69F0 7F0C1E80 AC204390 */  sw    $zero, %lo(g_musicXTrack2Fade)($at)
/* 0F69F4 7F0C1E84 0C001C85 */  jal   musicTrack2Play
/* 0F69F8 7F0C1E88 2404003A */   li    $a0, 58
/* 0F69FC 7F0C1E8C 10000004 */  b     .Ljp7F0C1EA0
/* 0F6A00 7F0C1E90 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C1E94:
/* 0F6A04 7F0C1E94 1000FFFF */  b     .Ljp7F0C1E94
/* 0F6A08 7F0C1E98 00000000 */   nop   
.Ljp7F0C1E9C:
/* 0F6A0C 7F0C1E9C 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F0C1EA0:
/* 0F6A10 7F0C1EA0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F6A14 7F0C1EA4 03E00008 */  jr    $ra
/* 0F6A18 7F0C1EA8 00000000 */   nop   
)
#endif

#ifdef VERSION_EU
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
/* 0F576C set_missionstate 3C038005 */  lui   $v1, %hi(mission_state)
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
/* 0F57D4 7F0C0CA4 3C018002 */  lui   $at, %hi(music1_playing)
/* 0F57D8 7F0C0CA8 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F57DC 7F0C0CAC AC20434C */  sw    $zero, %lo(music1_playing)($at)
/* 0F57E0 7F0C0CB0 0FC349C8 */  jal   getmusictrack_or_randomtrack
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
/* 0F5808 7F0C0CD8 3C018002 */  lui   $at, %hi(music1_playing)
/* 0F580C 7F0C0CDC 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5810 7F0C0CE0 AC20434C */  sw    $zero, %lo(music1_playing)($at)
/* 0F5814 7F0C0CE4 0FC349C8 */  jal   getmusictrack_or_randomtrack
/* 0F5818 7F0C0CE8 8C84C600 */   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
/* 0F581C 7F0C0CEC 0C001B9F */  jal   musicTrack1Play
/* 0F5820 7F0C0CF0 00402025 */   move  $a0, $v0
/* 0F5824 7F0C0CF4 0FC30304 */  jal   sub_GAME_7F0C0C10
/* 0F5828 7F0C0CF8 00000000 */   nop   
/* 0F582C 7F0C0CFC 0C001DD3 */  jal   musicTrack3Vol
/* 0F5830 7F0C0D00 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5834 7F0C0D04 3C018002 */  lui   $at, %hi(music3_playing)
/* 0F5838 7F0C0D08 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F583C 7F0C0D0C AC204354 */  sw    $zero, %lo(music3_playing)($at)
/* 0F5840 7F0C0D10 0FC34A12 */  jal   musicGetBgTrackForStage
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
/* 0F58A8 7F0C0D78 3C018002 */  lui   $at, %hi(music2_playing)
/* 0F58AC 7F0C0D7C 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F58B0 7F0C0D80 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F58B4 7F0C0D84 0FC34A24 */  jal   musicGetXTrackForStage
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
/* 0F58EC 7F0C0DBC 3C018002 */  lui   $at, %hi(music2_playing)
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
/* 0F5914 7F0C0DE4 3C018006 */  lui   $at, %hi(music_rate_8005B7E4)
/* 0F5918 7F0C0DE8 0C001C3E */  jal   music_related_1
/* 0F591C 7F0C0DEC C42CB7E4 */   lwc1  $f12, %lo(music_rate_8005B7E4)($at)
/* 0F5920 7F0C0DF0 0FC302FC */  jal   sub_GAME_7F0C0BF0
/* 0F5924 7F0C0DF4 00000000 */   nop   
/* 0F5928 7F0C0DF8 0C001CF1 */  jal   musicTrack2Vol
/* 0F592C 7F0C0DFC 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0F5930 7F0C0E00 3C018002 */  lui   $at, %hi(music2_playing)
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
/* 0F59C8 7F0C0E98 3C018002 */  lui   $at, %hi(music2_playing)
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
/* 0F5A60 7F0C0F30 3C018002 */  lui   $at, %hi(music2_playing)
/* 0F5A64 7F0C0F34 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5A68 7F0C0F38 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5A6C 7F0C0F3C 0FC34A24 */  jal   musicGetXTrackForStage
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
/* 0F5AF4 7F0C0FC4 3C018002 */  lui   $at, %hi(music2_playing)
/* 0F5AF8 7F0C0FC8 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5AFC 7F0C0FCC AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5B00 7F0C0FD0 0FC34A24 */  jal   musicGetXTrackForStage
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
/* 0F5B68 7F0C1038 3C018002 */  lui   $at, %hi(music2_playing)
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
/* 0F5BB0 7F0C1080 3C018002 */  lui   $at, %hi(music2_playing)
/* 0F5BB4 7F0C1084 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008C600)
/* 0F5BB8 7F0C1088 AC204350 */  sw    $zero, %lo(music2_playing)($at)
/* 0F5BBC 7F0C108C 0FC34A24 */  jal   musicGetXTrackForStage
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
/* 0F5C34 7F0C1104 3C018002 */  lui   $at, %hi(music2_playing)
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
/* 0F5CFC 7F0C11CC 3C018002 */  lui   $at, %hi(music2_playing)
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

#endif



#ifdef NONMATCHING//
void sub_GAME_7F0C11FC(s16 param_1)
{
    musicTrack1Stop();
    musicTrack2Stop();
    musicTrack3Stop();
    mission_state = 0;
    dword_CODE_bss_8008C600 = (int)param_1;

    if (musicGetBgTrackForStage(param_1) < 0)
    {
        set_missionstate(1);
    }
    else
    {
        set_missionstate(4);
    }
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
/* 0F5D50 7F0C1220 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008C600)
/* 0F5D54 7F0C1224 3C018005 */  lui   $at, %hi(mission_state)
/* 0F5D58 7F0C1228 2442C600 */  addiu $v0, %lo(dword_CODE_bss_8008C600) # addiu $v0, $v0, -0x3a00
/* 0F5D5C 7F0C122C AC2084C0 */  sw    $zero, %lo(mission_state)($at)
/* 0F5D60 7F0C1230 0FC34A12 */  jal   musicGetBgTrackForStage
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





void sub_GAME_7F0C1268(void)
{
  set_missionstate(0);
}

void sub_GAME_7F0C1288(void)
{
  if (musicGetBgTrackForStage(dword_CODE_bss_8008C600) < 0)
  {
    set_missionstate(2);
  }
  else
  {
    set_missionstate(5);
  }
}

void sub_GAME_7F0C12CC(void)
{
  if (musicGetBgTrackForStage(dword_CODE_bss_8008C600) < 0)
  {
    set_missionstate(1);
  }
  else
  {
    set_missionstate(4);
  }
}

void sub_GAME_7F0C1310(void)
{
  dword_CODE_bss_8008C604 = mission_state;
  set_missionstate(3);
}

void sub_GAME_7F0C1340(void)
{
  set_missionstate(dword_CODE_bss_8008C604);
}

void sub_GAME_7F0C1364(void)
{
  music_slot_active_0 = 0;
  music_slot_minutes_0 = 0;
  music_slot_seconds_0 = 0;
  music_slot_active_1 = 0;
  music_slot_minutes_1 = 0;
  music_slot_seconds_1 = 0;
  music_slot_active_2 = 0;
  music_slot_minutes_2 = 0;
  music_slot_seconds_2 = 0;
  music_slot_active_3 = 0;
  music_slot_minutes_3 = 0;
  music_slot_seconds_3 = 0;
}






#ifdef NONMATCHING
void reset_all_music_slots(void) {

}
#else
GLOBAL_ASM(
.text
glabel reset_all_music_slots
/* 0F5EF8 7F0C13C8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F5EFC 7F0C13CC 3C078009 */  lui   $a3, %hi(music_slot_active_0)
/* 0F5F00 7F0C13D0 3C048009 */  lui   $a0, %hi(music_slot_minutes_0)
/* 0F5F04 7F0C13D4 3C068005 */  lui   $a2, %hi(clock_timer)
/* 0F5F08 7F0C13D8 3C098009 */  lui   $t1, %hi(music_slot_seconds_0) 
/* 0F5F0C 7F0C13DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F5F10 7F0C13E0 00005025 */  move  $t2, $zero
/* 0F5F14 7F0C13E4 2529C628 */  addiu $t1, %lo(music_slot_seconds_0) # addiu $t1, $t1, -0x39d8
/* 0F5F18 7F0C13E8 8CC68374 */  lw    $a2, %lo(clock_timer)($a2)
/* 0F5F1C 7F0C13EC 2484C618 */  addiu $a0, %lo(music_slot_minutes_0) # addiu $a0, $a0, -0x39e8
/* 0F5F20 7F0C13F0 24E7C608 */  addiu $a3, %lo(music_slot_active_0) # addiu $a3, $a3, -0x39f8
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
/* 0F5F44 7F0C1414 3C0F8009 */  lui   $t7, %hi(music_slot_seconds_0) 
/* 0F5F48 7F0C1418 25EFC628 */  addiu $t7, %lo(music_slot_seconds_0) # addiu $t7, $t7, -0x39d8
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
void set_musicslot_time(int slot,int min,int sec)
{
    if (music_slot_active[slot] == 0) {
        music_slot_active[slot] = 1;
        music_slot_minutes[slot] = min * 0x3c;
        music_slot_seconds[slot] = sec * 0x3c;
    }
}
#else
GLOBAL_ASM(
.text
glabel set_musicslot_time
/* 0F602C 7F0C14FC 3C0E8009 */  lui   $t6, %hi(music_slot_active_0) 
/* 0F6030 7F0C1500 25CEC608 */  addiu $t6, %lo(music_slot_active_0) # addiu $t6, $t6, -0x39f8
/* 0F6034 7F0C1504 00041080 */  sll   $v0, $a0, 2
/* 0F6038 7F0C1508 004E1821 */  addu  $v1, $v0, $t6
/* 0F603C 7F0C150C 8C6F0000 */  lw    $t7, ($v1)
/* 0F6040 7F0C1510 2404003C */  li    $a0, 60
/* 0F6044 7F0C1514 15E0000E */  bnez  $t7, .L7F0C1550
/* 0F6048 7F0C1518 00000000 */   nop   
/* 0F604C 7F0C151C 00A40019 */  multu $a1, $a0
/* 0F6050 7F0C1520 24180001 */  li    $t8, 1
/* 0F6054 7F0C1524 3C018009 */  lui   $at, %hi(music_slot_minutes_0)
/* 0F6058 7F0C1528 AC780000 */  sw    $t8, ($v1)
/* 0F605C 7F0C152C 00220821 */  addu  $at, $at, $v0
/* 0F6060 7F0C1530 0000C812 */  mflo  $t9
/* 0F6064 7F0C1534 AC39C618 */  sw    $t9, %lo(music_slot_minutes_0)($at)
/* 0F6068 7F0C1538 3C018009 */  lui   $at, %hi(music_slot_seconds_0)
/* 0F606C 7F0C153C 00C40019 */  multu $a2, $a0
/* 0F6070 7F0C1540 00220821 */  addu  $at, $at, $v0
/* 0F6074 7F0C1544 00004012 */  mflo  $t0
/* 0F6078 7F0C1548 AC28C628 */  sw    $t0, %lo(music_slot_seconds_0)($at)
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
    (&music_slot_active_0)[(int)lParm1] = 0;
    return;
  }
  music_slot_active_0 = 0;
  music_slot_active_1 = 0;
  music_slot_active_2 = 0;
  music_slot_active_3 = 0;
  music_slot_minutes_0 = 0;
  music_slot_minutes_1 = 0;
  music_slot_minutes_2 = 0;
  music_slot_minutes_3 = 0;
  music_slot_seconds_0 = 0;
  music_slot_seconds_1 = 0;
  music_slot_seconds_2 = 0;
  music_slot_seconds_3 = 0;
  return;
}
#else
GLOBAL_ASM(
.text
glabel reset_music_in_slot
/* 0F6088 7F0C1558 04800006 */  bltz  $a0, .L7F0C1574
/* 0F608C 7F0C155C 3C018009 */   lui   $at, %hi(music_slot_active_0)
/* 0F6090 7F0C1560 00047080 */  sll   $t6, $a0, 2
/* 0F6094 7F0C1564 3C018009 */  lui   $at, %hi(music_slot_active_0)
/* 0F6098 7F0C1568 002E0821 */  addu  $at, $at, $t6
/* 0F609C 7F0C156C 03E00008 */  jr    $ra
/* 0F60A0 7F0C1570 AC20C608 */   sw    $zero, %lo(music_slot_active_0)($at)

.L7F0C1574:
/* 0F60A4 7F0C1574 AC20C608 */  sw    $zero, %lo(music_slot_active_0)($at)
/* 0F60A8 7F0C1578 3C018009 */  lui   $at, %hi(music_slot_minutes_0)
/* 0F60AC 7F0C157C AC20C618 */  sw    $zero, %lo(music_slot_minutes_0)($at)
/* 0F60B0 7F0C1580 3C018009 */  lui   $at, %hi(music_slot_seconds_0)
/* 0F60B4 7F0C1584 AC20C628 */  sw    $zero, %lo(music_slot_seconds_0)($at)
/* 0F60B8 7F0C1588 3C018009 */  lui   $at, %hi(music_slot_active_1)
/* 0F60BC 7F0C158C AC20C60C */  sw    $zero, %lo(music_slot_active_1)($at)
/* 0F60C0 7F0C1590 3C018009 */  lui   $at, %hi(music_slot_minutes_1)
/* 0F60C4 7F0C1594 AC20C61C */  sw    $zero, %lo(music_slot_minutes_1)($at)
/* 0F60C8 7F0C1598 3C018009 */  lui   $at, %hi(music_slot_seconds_1)
/* 0F60CC 7F0C159C AC20C62C */  sw    $zero, %lo(music_slot_seconds_1)($at)
/* 0F60D0 7F0C15A0 3C018009 */  lui   $at, %hi(music_slot_active_2)
/* 0F60D4 7F0C15A4 AC20C610 */  sw    $zero, %lo(music_slot_active_2)($at)
/* 0F60D8 7F0C15A8 3C018009 */  lui   $at, %hi(music_slot_minutes_2)
/* 0F60DC 7F0C15AC AC20C620 */  sw    $zero, %lo(music_slot_minutes_2)($at)
/* 0F60E0 7F0C15B0 3C018009 */  lui   $at, %hi(music_slot_seconds_2)
/* 0F60E4 7F0C15B4 AC20C630 */  sw    $zero, %lo(music_slot_seconds_2)($at)
/* 0F60E8 7F0C15B8 3C018009 */  lui   $at, %hi(music_slot_active_3)
/* 0F60EC 7F0C15BC AC20C614 */  sw    $zero, %lo(music_slot_active_3)($at)
/* 0F60F0 7F0C15C0 3C018009 */  lui   $at, %hi(music_slot_minutes_3)
/* 0F60F4 7F0C15C4 AC20C624 */  sw    $zero, %lo(music_slot_minutes_3)($at)
/* 0F60F8 7F0C15C8 3C018009 */  lui   $at, %hi(music_slot_seconds_3)
/* 0F60FC 7F0C15CC AC20C634 */  sw    $zero, %lo(music_slot_seconds_3)($at)
/* 0F6100 7F0C15D0 03E00008 */  jr    $ra
/* 0F6104 7F0C15D4 00000000 */   nop   
)
#endif



