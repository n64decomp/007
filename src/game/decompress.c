#include "ultra64.h"
#include "zlib.h"

//this definately isn't proper way this data was represented, but works for now
// rodata
//D:8005BF80
const u32 rz_header_bytes[] = {
    0x11720000, 0x11720000, 0x11720000, 0x11720000, 0x11720000,
    0x11720000, 0x11720000, 0x11720000, 0x11720000, 0x11720000
};




#ifdef NONMATCHING
u32 *decompressdata(u32 arg0, u32 arg1, u32 arg2) {

}
#else
GLOBAL_ASM(
.text
glabel decompressdata
/* 103320 7F0CE7F0 3C078009 */  lui   $a3, %hi(dword_CODE_bss_8008D350)
/* 103324 7F0CE7F4 24E7D350 */  addiu $a3, %lo(dword_CODE_bss_8008D350) # addiu $a3, $a3, -0x2cb0
/* 103328 7F0CE7F8 ACE40000 */  sw    $a0, ($a3)
/* 10332C 7F0CE7FC 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D354)
/* 103330 7F0CE800 AC25D354 */  sw    $a1, %lo(dword_CODE_bss_8008D354)($at)
/* 103334 7F0CE804 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 103338 7F0CE808 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D360)
/* 10333C 7F0CE80C AFBF0014 */  sw    $ra, 0x14($sp)
/* 103340 7F0CE810 AC26D360 */  sw    $a2, %lo(dword_CODE_bss_8008D360)($at)
/* 103344 7F0CE814 3C0E8006 */  lui   $t6, %hi(rz_header_bytes) 
/* 103348 7F0CE818 91CEBF80 */  lbu   $t6, %lo(rz_header_bytes)($t6)
/* 10334C 7F0CE81C 90820000 */  lbu   $v0, ($a0)
/* 103350 7F0CE820 3C188006 */  lui   $t8, %hi(rz_header_bytes+0x5) 
/* 103354 7F0CE824 3C198006 */  lui   $t9, %hi(rz_header_bytes+0x8) 
/* 103358 7F0CE828 144E0005 */  bne   $v0, $t6, .L7F0CE840
/* 10335C 7F0CE82C 3C0A8006 */   lui   $t2, %hi(rz_header_bytes+0x18) 
/* 103360 7F0CE830 908F0001 */  lbu   $t7, 1($a0)
/* 103364 7F0CE834 9318BF85 */  lbu   $t8, %lo(rz_header_bytes+0x5)($t8)
/* 103368 7F0CE838 51F8000A */  beql  $t7, $t8, .L7F0CE864
/* 10336C 7F0CE83C 8CEC0000 */   lw    $t4, ($a3)
.L7F0CE840:
/* 103370 7F0CE840 9083FFFF */  lbu   $v1, -1($a0)
/* 103374 7F0CE844 9339BF88 */  lbu   $t9, %lo(rz_header_bytes+0x8)($t9)
/* 103378 7F0CE848 54790002 */  bnel  $v1, $t9, .L7F0CE854
/* 10337C 7F0CE84C 9089FFFE */   lbu   $t1, -2($a0)
/* 103380 7F0CE850 9089FFFE */  lbu   $t1, -2($a0)
.L7F0CE854:
/* 103384 7F0CE854 914ABF98 */  lbu   $t2, %lo(rz_header_bytes+0x18)($t2)
/* 103388 7F0CE858 552A0002 */  bnel  $t1, $t2, .L7F0CE864
/* 10338C 7F0CE85C 8CEC0000 */   lw    $t4, ($a3)
/* 103390 7F0CE860 8CEC0000 */  lw    $t4, ($a3)
.L7F0CE864:
/* 103394 7F0CE864 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D35C)
/* 103398 7F0CE868 258D0002 */  addiu $t5, $t4, 2
/* 10339C 7F0CE86C ACED0000 */  sw    $t5, ($a3)
/* 1033A0 7F0CE870 AC20D35C */  sw    $zero, %lo(dword_CODE_bss_8008D35C)($at)
/* 1033A4 7F0CE874 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D358)
/* 1033A8 7F0CE878 0FC33F35 */  jal   loop_to_decompress_entire_file
/* 1033AC 7F0CE87C AC20D358 */   sw    $zero, %lo(dword_CODE_bss_8008D358)($at)
/* 1033B0 7F0CE880 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1033B4 7F0CE884 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D35C)
/* 1033B8 7F0CE888 8C42D35C */  lw    $v0, %lo(dword_CODE_bss_8008D35C)($v0)
/* 1033BC 7F0CE88C 03E00008 */  jr    $ra
/* 1033C0 7F0CE890 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





#ifdef NONMATCHING
s32 sub_GAME_7F0CE894(void) {
    // Node 0
    return (dword_CODE_bss_8008D350 + dword_CODE_bss_8008D358);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CE894
/* 1033C4 7F0CE894 3C0E8009 */  lui   $t6, %hi(dword_CODE_bss_8008D350) 
/* 1033C8 7F0CE898 3C0F8009 */  lui   $t7, %hi(dword_CODE_bss_8008D358) 
/* 1033CC 7F0CE89C 8DEFD358 */  lw    $t7, %lo(dword_CODE_bss_8008D358)($t7)
/* 1033D0 7F0CE8A0 8DCED350 */  lw    $t6, %lo(dword_CODE_bss_8008D350)($t6)
/* 1033D4 7F0CE8A4 03E00008 */  jr    $ra
/* 1033D8 7F0CE8A8 01CF1021 */   addu  $v0, $t6, $t7
)
#endif


