#include <ultra64.h>
#include <limits.h>
#include "math_atan2f.h"
#include "unk_0A1DA0.h"
#include "random.h"

#ifndef VERSION_EU
#define SCALAR_1_7F0A2160 1.5f
#define SCALAR_2_7F0A2160 3.0f
#define SCALAR_3_7F0A2160 0.1f
#else
#define SCALAR_1_7F0A2160 1.8f
#define SCALAR_2_7F0A2160 3.6f
#define SCALAR_3_7F0A2160 0.12f
#endif

#define UNK_8007A170_MAX 20

// bss
//CODE.bss:8007A160
s32 SHATTERED_WINDOW_PIECES_BUFFER_LEN;
//CODE.bss:8007A164
s_shattered_window_piece* ptr_shattered_window_pieces;
//CODE.bss:8007A168
u32 dword_CODE_bss_8007A168;
//CODE.bss:8007A16C
u32 dword_CODE_bss_8007A16C;

// something explosion related
// size of each item is 0x2c (see sub_GAME_7F0A3E1C)
//CODE.bss:8007A170
bondstruct_unk_8007A170 dword_CODE_bss_8007A170[UNK_8007A170_MAX];

#ifndef VERSION_EU
//CODE.bss:8007A4E0
u8 dword_CODE_bss_8007A4E0[0xBB4];
//CODE.bss:8007B098
u8 dword_CODE_bss_8007B098[8];
#endif


// data
//D:80040940
s32 D_80040940 = 0;
u32 D_80040944 = 0;
u32 D_80040948 = 0;
u32 D_8004094C = 0;
u32 D_80040950 = 0;
u32 D_80040954 = 0;
u32 D_80040958 = 0;
u32 D_8004095C = 0;


//D:80040960
struct rgba_u8 D_80040960[8] = {
    { 0xFF, 0xFF, 0xFF, 0xFF }, 
    { 0xFF, 0xFF, 0xC8, 0xFF }, 
    { 0xFF, 0x00, 0x00, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF },
    { 0xFF, 0xFF, 0xFF, 0xFF },
    { 0 },
    { 0 }
};
u32 D_80040980 = 0;




// rodata



#ifdef NONMATCHING
void sub_GAME_7F0A1DA0(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80057710
.word 0x3dcccccd /*0.1*/
glabel D_80057714
.word 0x3f333333 /*0.69999999*/
.text
glabel sub_GAME_7F0A1DA0
/* 0D68D0 7F0A1DA0 27BDFF20 */  addiu $sp, $sp, -0xe0
/* 0D68D4 7F0A1DA4 AFBF005C */  sw    $ra, 0x5c($sp)
/* 0D68D8 7F0A1DA8 AFB50058 */  sw    $s5, 0x58($sp)
/* 0D68DC 7F0A1DAC AFB40054 */  sw    $s4, 0x54($sp)
/* 0D68E0 7F0A1DB0 AFB30050 */  sw    $s3, 0x50($sp)
/* 0D68E4 7F0A1DB4 AFB2004C */  sw    $s2, 0x4c($sp)
/* 0D68E8 7F0A1DB8 AFB10048 */  sw    $s1, 0x48($sp)
/* 0D68EC 7F0A1DBC AFB00044 */  sw    $s0, 0x44($sp)
/* 0D68F0 7F0A1DC0 F7BE0038 */  sdc1  $f30, 0x38($sp)
/* 0D68F4 7F0A1DC4 F7BC0030 */  sdc1  $f28, 0x30($sp)
/* 0D68F8 7F0A1DC8 F7BA0028 */  sdc1  $f26, 0x28($sp)
/* 0D68FC 7F0A1DCC F7B80020 */  sdc1  $f24, 0x20($sp)
/* 0D6900 7F0A1DD0 F7B60018 */  sdc1  $f22, 0x18($sp)
/* 0D6904 7F0A1DD4 F7B40010 */  sdc1  $f20, 0x10($sp)
/* 0D6908 7F0A1DD8 C4A40000 */  lwc1  $f4, ($a1)
/* 0D690C 7F0A1DDC 00C08025 */  move  $s0, $a2
/* 0D6910 7F0A1DE0 00808825 */  move  $s1, $a0
/* 0D6914 7F0A1DE4 E7A40090 */  swc1  $f4, 0x90($sp)
/* 0D6918 7F0A1DE8 C4A60004 */  lwc1  $f6, 4($a1)
/* 0D691C 7F0A1DEC C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 0D6920 7F0A1DF0 00E09025 */  move  $s2, $a3
/* 0D6924 7F0A1DF4 E7A60094 */  swc1  $f6, 0x94($sp)
/* 0D6928 7F0A1DF8 460A5402 */  mul.s $f16, $f10, $f10
/* 0D692C 7F0A1DFC C4A80008 */  lwc1  $f8, 8($a1)
/* 0D6930 7F0A1E00 C7B20094 */  lwc1  $f18, 0x94($sp)
/* 0D6934 7F0A1E04 E7A80098 */  swc1  $f8, 0x98($sp)
/* 0D6938 7F0A1E08 46129102 */  mul.s $f4, $f18, $f18
/* 0D693C 7F0A1E0C C7A80098 */  lwc1  $f8, 0x98($sp)
/* 0D6940 7F0A1E10 46084282 */  mul.s $f10, $f8, $f8
/* 0D6944 7F0A1E14 46048180 */  add.s $f6, $f16, $f4
/* 0D6948 7F0A1E18 0C007DF8 */  jal   sqrtf
/* 0D694C 7F0A1E1C 46065300 */   add.s $f12, $f10, $f6
/* 0D6950 7F0A1E20 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D6954 7F0A1E24 4481D000 */  mtc1  $at, $f26
/* 0D6958 7F0A1E28 C7B20090 */  lwc1  $f18, 0x90($sp)
/* 0D695C 7F0A1E2C C7A40094 */  lwc1  $f4, 0x94($sp)
/* 0D6960 7F0A1E30 4600D503 */  div.s $f20, $f26, $f0
/* 0D6964 7F0A1E34 C7AA0098 */  lwc1  $f10, 0x98($sp)
/* 0D6968 7F0A1E38 C7B600F0 */  lwc1  $f22, 0xf0($sp)
/* 0D696C 7F0A1E3C C7BC00F4 */  lwc1  $f28, 0xf4($sp)
/* 0D6970 7F0A1E40 46149402 */  mul.s $f16, $f18, $f20
/* 0D6974 7F0A1E44 00000000 */  nop   
/* 0D6978 7F0A1E48 46142202 */  mul.s $f8, $f4, $f20
/* 0D697C 7F0A1E4C 00000000 */  nop   
/* 0D6980 7F0A1E50 46145182 */  mul.s $f6, $f10, $f20
/* 0D6984 7F0A1E54 E7B00090 */  swc1  $f16, 0x90($sp)
/* 0D6988 7F0A1E58 4600B582 */  mul.s $f22, $f22, $f0
/* 0D698C 7F0A1E5C E7A80094 */  swc1  $f8, 0x94($sp)
/* 0D6990 7F0A1E60 4600E702 */  mul.s $f28, $f28, $f0
/* 0D6994 7F0A1E64 E7A60098 */  swc1  $f6, 0x98($sp)
/* 0D6998 7F0A1E68 C6120000 */  lwc1  $f18, ($s0)
/* 0D699C 7F0A1E6C E7B20084 */  swc1  $f18, 0x84($sp)
/* 0D69A0 7F0A1E70 C6100004 */  lwc1  $f16, 4($s0)
/* 0D69A4 7F0A1E74 C7A80084 */  lwc1  $f8, 0x84($sp)
/* 0D69A8 7F0A1E78 E7B00088 */  swc1  $f16, 0x88($sp)
/* 0D69AC 7F0A1E7C 46084282 */  mul.s $f10, $f8, $f8
/* 0D69B0 7F0A1E80 C6040008 */  lwc1  $f4, 8($s0)
/* 0D69B4 7F0A1E84 C7A60088 */  lwc1  $f6, 0x88($sp)
/* 0D69B8 7F0A1E88 E7A4008C */  swc1  $f4, 0x8c($sp)
/* 0D69BC 7F0A1E8C 46063482 */  mul.s $f18, $f6, $f6
/* 0D69C0 7F0A1E90 C7A4008C */  lwc1  $f4, 0x8c($sp)
/* 0D69C4 7F0A1E94 46042202 */  mul.s $f8, $f4, $f4
/* 0D69C8 7F0A1E98 46125400 */  add.s $f16, $f10, $f18
/* 0D69CC 7F0A1E9C 0C007DF8 */  jal   sqrtf
/* 0D69D0 7F0A1EA0 46104300 */   add.s $f12, $f8, $f16
/* 0D69D4 7F0A1EA4 4600D503 */  div.s $f20, $f26, $f0
/* 0D69D8 7F0A1EA8 C7A60084 */  lwc1  $f6, 0x84($sp)
/* 0D69DC 7F0A1EAC C7B20088 */  lwc1  $f18, 0x88($sp)
/* 0D69E0 7F0A1EB0 C7A8008C */  lwc1  $f8, 0x8c($sp)
/* 0D69E4 7F0A1EB4 C7B800F8 */  lwc1  $f24, 0xf8($sp)
/* 0D69E8 7F0A1EB8 46143282 */  mul.s $f10, $f6, $f20
/* 0D69EC 7F0A1EBC C7A600FC */  lwc1  $f6, 0xfc($sp)
/* 0D69F0 7F0A1EC0 46149102 */  mul.s $f4, $f18, $f20
/* 0D69F4 7F0A1EC4 00000000 */  nop   
/* 0D69F8 7F0A1EC8 46144402 */  mul.s $f16, $f8, $f20
/* 0D69FC 7F0A1ECC E7AA0084 */  swc1  $f10, 0x84($sp)
/* 0D6A00 7F0A1ED0 4600C602 */  mul.s $f24, $f24, $f0
/* 0D6A04 7F0A1ED4 E7A40088 */  swc1  $f4, 0x88($sp)
/* 0D6A08 7F0A1ED8 46003282 */  mul.s $f10, $f6, $f0
/* 0D6A0C 7F0A1EDC E7B0008C */  swc1  $f16, 0x8c($sp)
/* 0D6A10 7F0A1EE0 E7AA00FC */  swc1  $f10, 0xfc($sp)
/* 0D6A14 7F0A1EE4 C64E0008 */  lwc1  $f14, 8($s2)
/* 0D6A18 7F0A1EE8 0FC16A8C */  jal   atan2f
/* 0D6A1C 7F0A1EEC C64C0000 */   lwc1  $f12, ($s2)
/* 0D6A20 7F0A1EF0 C7B200FC */  lwc1  $f18, 0xfc($sp)
/* 0D6A24 7F0A1EF4 3C0E8008 */  lui   $t6, %hi(SHATTERED_WINDOW_PIECES_BUFFER_LEN) 
/* 0D6A28 7F0A1EF8 8DCEA160 */  lw    $t6, %lo(SHATTERED_WINDOW_PIECES_BUFFER_LEN)($t6)
/* 0D6A2C 7F0A1EFC 4616E501 */  sub.s $f20, $f28, $f22
/* 0D6A30 7F0A1F00 46000786 */  mov.s $f30, $f0
/* 0D6A34 7F0A1F04 46189681 */  sub.s $f26, $f18, $f24
/* 0D6A38 7F0A1F08 461AA102 */  mul.s $f4, $f20, $f26
/* 0D6A3C 7F0A1F0C 05C10003 */  bgez  $t6, .L7F0A1F1C
/* 0D6A40 7F0A1F10 000E7843 */   sra   $t7, $t6, 1
/* 0D6A44 7F0A1F14 25C10001 */  addiu $at, $t6, 1
/* 0D6A48 7F0A1F18 00017843 */  sra   $t7, $at, 1
.L7F0A1F1C:
/* 0D6A4C 7F0A1F1C 448F4000 */  mtc1  $t7, $f8
/* 0D6A50 7F0A1F20 00000000 */  nop   
/* 0D6A54 7F0A1F24 46804420 */  cvt.s.w $f16, $f8
/* 0D6A58 7F0A1F28 0C007DF8 */  jal   sqrtf
/* 0D6A5C 7F0A1F2C 46102303 */   div.s $f12, $f4, $f16
/* 0D6A60 7F0A1F30 4600018D */  trunc.w.s $f6, $f0
/* 0D6A64 7F0A1F34 C7A80090 */  lwc1  $f8, 0x90($sp)
/* 0D6A68 7F0A1F38 E7A000B0 */  swc1  $f0, 0xb0($sp)
/* 0D6A6C 7F0A1F3C C6320000 */  lwc1  $f18, ($s1)
/* 0D6A70 7F0A1F40 44023000 */  mfc1  $v0, $f6
/* 0D6A74 7F0A1F44 C7A60084 */  lwc1  $f6, 0x84($sp)
/* 0D6A78 7F0A1F48 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0D6A7C 7F0A1F4C 0002C843 */  sra   $t9, $v0, 1
/* 0D6A80 7F0A1F50 44995000 */  mtc1  $t9, $f10
/* 0D6A84 7F0A1F54 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0D6A88 7F0A1F58 24050047 */  li    $a1, 71
/* 0D6A8C 7F0A1F5C 468053A0 */  cvt.s.w $f14, $f10
/* 0D6A90 7F0A1F60 00003025 */  move  $a2, $zero
/* 0D6A94 7F0A1F64 00408025 */  move  $s0, $v0
/* 0D6A98 7F0A1F68 00409025 */  move  $s2, $v0
/* 0D6A9C 7F0A1F6C 460EB300 */  add.s $f12, $f22, $f14
/* 0D6AA0 7F0A1F70 460EC080 */  add.s $f2, $f24, $f14
/* 0D6AA4 7F0A1F74 46086102 */  mul.s $f4, $f12, $f8
/* 0D6AA8 7F0A1F78 46049400 */  add.s $f16, $f18, $f4
/* 0D6AAC 7F0A1F7C 46023282 */  mul.s $f10, $f6, $f2
/* 0D6AB0 7F0A1F80 C7A40094 */  lwc1  $f4, 0x94($sp)
/* 0D6AB4 7F0A1F84 46046182 */  mul.s $f6, $f12, $f4
/* 0D6AB8 7F0A1F88 46105200 */  add.s $f8, $f10, $f16
/* 0D6ABC 7F0A1F8C C7B00088 */  lwc1  $f16, 0x88($sp)
/* 0D6AC0 7F0A1F90 E7A8009C */  swc1  $f8, 0x9c($sp)
/* 0D6AC4 7F0A1F94 46028202 */  mul.s $f8, $f16, $f2
/* 0D6AC8 7F0A1F98 C6320004 */  lwc1  $f18, 4($s1)
/* 0D6ACC 7F0A1F9C 46069280 */  add.s $f10, $f18, $f6
/* 0D6AD0 7F0A1FA0 C7A60098 */  lwc1  $f6, 0x98($sp)
/* 0D6AD4 7F0A1FA4 460A4100 */  add.s $f4, $f8, $f10
/* 0D6AD8 7F0A1FA8 46066402 */  mul.s $f16, $f12, $f6
/* 0D6ADC 7F0A1FAC C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0D6AE0 7F0A1FB0 E7A400A0 */  swc1  $f4, 0xa0($sp)
/* 0D6AE4 7F0A1FB4 46025102 */  mul.s $f4, $f10, $f2
/* 0D6AE8 7F0A1FB8 C6320008 */  lwc1  $f18, 8($s1)
/* 0D6AEC 7F0A1FBC 46109200 */  add.s $f8, $f18, $f16
/* 0D6AF0 7F0A1FC0 46082180 */  add.s $f6, $f4, $f8
/* 0D6AF4 7F0A1FC4 0C002382 */  jal   sndPlaySfx
/* 0D6AF8 7F0A1FC8 E7A600A4 */   swc1  $f6, 0xa4($sp)
/* 0D6AFC 7F0A1FCC 00402025 */  move  $a0, $v0
/* 0D6B00 7F0A1FD0 0FC14E84 */  jal   sub_GAME_7F053A10
/* 0D6B04 7F0A1FD4 02202825 */   move  $a1, $s1
/* 0D6B08 7F0A1FD8 44922000 */  mtc1  $s2, $f4
/* 0D6B0C 7F0A1FDC 44909000 */  mtc1  $s0, $f18
/* 0D6B10 7F0A1FE0 00009825 */  move  $s3, $zero
/* 0D6B14 7F0A1FE4 46802220 */  cvt.s.w $f8, $f4
/* 0D6B18 7F0A1FE8 3C018005 */  lui   $at, %hi(D_80057710)
/* 0D6B1C 7F0A1FEC 468095A0 */  cvt.s.w $f22, $f18
/* 0D6B20 7F0A1FF0 E7A80068 */  swc1  $f8, 0x68($sp)
/* 0D6B24 7F0A1FF4 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0D6B28 7F0A1FF8 4606D483 */  div.s $f18, $f26, $f6
/* 0D6B2C 7F0A1FFC 4616A403 */  div.s $f16, $f20, $f22
/* 0D6B30 7F0A2000 4600828D */  trunc.w.s $f10, $f16
/* 0D6B34 7F0A2004 4600940D */  trunc.w.s $f16, $f18
/* 0D6B38 7F0A2008 44145000 */  mfc1  $s4, $f10
/* 0D6B3C 7F0A200C 44158000 */  mfc1  $s5, $f16
/* 0D6B40 7F0A2010 02808825 */  move  $s1, $s4
/* 0D6B44 7F0A2014 5AA00044 */  blezl $s5, .L7F0A2128
/* 0D6B48 7F0A2018 8FBF005C */   lw    $ra, 0x5c($sp)
/* 0D6B4C 7F0A201C C43C7710 */  lwc1  $f28, %lo(D_80057710)($at)
/* 0D6B50 7F0A2020 3C018005 */  lui   $at, %hi(D_80057714)
/* 0D6B54 7F0A2024 C43A7714 */  lwc1  $f26, %lo(D_80057714)($at)
/* 0D6B58 7F0A2028 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D6B5C 7F0A202C 4481C000 */  mtc1  $at, $f24
/* 0D6B60 7F0A2030 27B200C0 */  addiu $s2, $sp, 0xc0
.L7F0A2034:
/* 0D6B64 7F0A2034 1A800037 */  blez  $s4, .L7F0A2114
/* 0D6B68 7F0A2038 00008025 */   move  $s0, $zero
/* 0D6B6C 7F0A203C 44935000 */  mtc1  $s3, $f10
/* 0D6B70 7F0A2040 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0D6B74 7F0A2044 46805120 */  cvt.s.w $f4, $f10
/* 0D6B78 7F0A2048 46082502 */  mul.s $f20, $f4, $f8
/* 0D6B7C 7F0A204C 00000000 */  nop   
/* 0D6B80 7F0A2050 44903000 */  mtc1  $s0, $f6
.L7F0A2054:
/* 0D6B84 7F0A2054 C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 0D6B88 7F0A2058 C7B0009C */  lwc1  $f16, 0x9c($sp)
/* 0D6B8C 7F0A205C 468034A0 */  cvt.s.w $f18, $f6
/* 0D6B90 7F0A2060 C7A60084 */  lwc1  $f6, 0x84($sp)
/* 0D6B94 7F0A2064 46169002 */  mul.s $f0, $f18, $f22
/* 0D6B98 7F0A2068 00000000 */  nop   
/* 0D6B9C 7F0A206C 460A0102 */  mul.s $f4, $f0, $f10
/* 0D6BA0 7F0A2070 46048200 */  add.s $f8, $f16, $f4
/* 0D6BA4 7F0A2074 46143482 */  mul.s $f18, $f6, $f20
/* 0D6BA8 7F0A2078 C7A40094 */  lwc1  $f4, 0x94($sp)
/* 0D6BAC 7F0A207C C7B000A0 */  lwc1  $f16, 0xa0($sp)
/* 0D6BB0 7F0A2080 46040182 */  mul.s $f6, $f0, $f4
/* 0D6BB4 7F0A2084 46089280 */  add.s $f10, $f18, $f8
/* 0D6BB8 7F0A2088 C7A80088 */  lwc1  $f8, 0x88($sp)
/* 0D6BBC 7F0A208C 46068480 */  add.s $f18, $f16, $f6
/* 0D6BC0 7F0A2090 E7AA00C0 */  swc1  $f10, 0xc0($sp)
/* 0D6BC4 7F0A2094 46144282 */  mul.s $f10, $f8, $f20
/* 0D6BC8 7F0A2098 C7A60098 */  lwc1  $f6, 0x98($sp)
/* 0D6BCC 7F0A209C C7B000A4 */  lwc1  $f16, 0xa4($sp)
/* 0D6BD0 7F0A20A0 46060202 */  mul.s $f8, $f0, $f6
/* 0D6BD4 7F0A20A4 46125100 */  add.s $f4, $f10, $f18
/* 0D6BD8 7F0A20A8 C7B2008C */  lwc1  $f18, 0x8c($sp)
/* 0D6BDC 7F0A20AC 46088280 */  add.s $f10, $f16, $f8
/* 0D6BE0 7F0A20B0 E7A400C4 */  swc1  $f4, 0xc4($sp)
/* 0D6BE4 7F0A20B4 46149102 */  mul.s $f4, $f18, $f20
/* 0D6BE8 7F0A20B8 460A2180 */  add.s $f6, $f4, $f10
/* 0D6BEC 7F0A20BC 0C002914 */  jal   randomGetNext
/* 0D6BF0 7F0A20C0 E7A600C8 */   swc1  $f6, 0xc8($sp)
/* 0D6BF4 7F0A20C4 44828000 */  mtc1  $v0, $f16
/* 0D6BF8 7F0A20C8 4405F000 */  mfc1  $a1, $f30
/* 0D6BFC 7F0A20CC 02402025 */  move  $a0, $s2
/* 0D6C00 7F0A20D0 04410005 */  bgez  $v0, .L7F0A20E8
/* 0D6C04 7F0A20D4 46808220 */   cvt.s.w $f8, $f16
/* 0D6C08 7F0A20D8 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D6C0C 7F0A20DC 44819000 */  mtc1  $at, $f18
/* 0D6C10 7F0A20E0 00000000 */  nop   
/* 0D6C14 7F0A20E4 46124200 */  add.s $f8, $f8, $f18
.L7F0A20E8:
/* 0D6C18 7F0A20E8 46184102 */  mul.s $f4, $f8, $f24
/* 0D6C1C 7F0A20EC C7B000B0 */  lwc1  $f16, 0xb0($sp)
/* 0D6C20 7F0A20F0 461A2282 */  mul.s $f10, $f4, $f26
/* 0D6C24 7F0A20F4 461C5180 */  add.s $f6, $f10, $f28
/* 0D6C28 7F0A20F8 46103482 */  mul.s $f18, $f6, $f16
/* 0D6C2C 7F0A20FC 44069000 */  mfc1  $a2, $f18
/* 0D6C30 7F0A2100 0FC28858 */  jal   sub_GAME_7F0A2160
/* 0D6C34 7F0A2104 00000000 */   nop   
/* 0D6C38 7F0A2108 26100001 */  addiu $s0, $s0, 1
/* 0D6C3C 7F0A210C 5611FFD1 */  bnel  $s0, $s1, .L7F0A2054
/* 0D6C40 7F0A2110 44903000 */   mtc1  $s0, $f6
.L7F0A2114:
/* 0D6C44 7F0A2114 26730001 */  addiu $s3, $s3, 1
/* 0D6C48 7F0A2118 0275082A */  slt   $at, $s3, $s5
/* 0D6C4C 7F0A211C 1420FFC5 */  bnez  $at, .L7F0A2034
/* 0D6C50 7F0A2120 00000000 */   nop   
/* 0D6C54 7F0A2124 8FBF005C */  lw    $ra, 0x5c($sp)
.L7F0A2128:
/* 0D6C58 7F0A2128 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0D6C5C 7F0A212C D7B60018 */  ldc1  $f22, 0x18($sp)
/* 0D6C60 7F0A2130 D7B80020 */  ldc1  $f24, 0x20($sp)
/* 0D6C64 7F0A2134 D7BA0028 */  ldc1  $f26, 0x28($sp)
/* 0D6C68 7F0A2138 D7BC0030 */  ldc1  $f28, 0x30($sp)
/* 0D6C6C 7F0A213C D7BE0038 */  ldc1  $f30, 0x38($sp)
/* 0D6C70 7F0A2140 8FB00044 */  lw    $s0, 0x44($sp)
/* 0D6C74 7F0A2144 8FB10048 */  lw    $s1, 0x48($sp)
/* 0D6C78 7F0A2148 8FB2004C */  lw    $s2, 0x4c($sp)
/* 0D6C7C 7F0A214C 8FB30050 */  lw    $s3, 0x50($sp)
/* 0D6C80 7F0A2150 8FB40054 */  lw    $s4, 0x54($sp)
/* 0D6C84 7F0A2154 8FB50058 */  lw    $s5, 0x58($sp)
/* 0D6C88 7F0A2158 03E00008 */  jr    $ra
/* 0D6C8C 7F0A215C 27BD00E0 */   addiu $sp, $sp, 0xe0
)
#endif


void sub_GAME_7F0A2160(coord3d* arg0, f32 arg1, f32 arg2)
{
    u32 temp_v0;
    f32 sp50;
    f32 temp_f24;
    u8 field67;

    temp_f24 = (2.0f * (randomGetNext() * (1.0f / (f32)UINT_MAX))) - 1.0f;
    sp50 = (randomGetNext() * (1.0f / (f32)UINT_MAX) * 1.12f) - .12f;
    temp_v0 = randomGetNext();

    ptr_shattered_window_pieces[D_80040940].piece = 1;
    ptr_shattered_window_pieces[D_80040940].x = arg0->x;
    ptr_shattered_window_pieces[D_80040940].y = arg0->y;
    ptr_shattered_window_pieces[D_80040940].z = arg0->z;

    ptr_shattered_window_pieces[D_80040940].field_0x1c = temp_f24 * SCALAR_1_7F0A2160;
    ptr_shattered_window_pieces[D_80040940].field_0x20 = sp50 * SCALAR_2_7F0A2160;
    ptr_shattered_window_pieces[D_80040940].field_0x24 = ((2.0f * (temp_v0 * (1.0f / (f32)UINT_MAX))) - 1.0f) * SCALAR_1_7F0A2160;
    ptr_shattered_window_pieces[D_80040940].field_0x38 = ((randomGetNext() * (1.0f / (f32)UINT_MAX) * 0.5f) + 1.0f) * arg2;
    ptr_shattered_window_pieces[D_80040940].field_0x3a = ((randomGetNext() * (1.0f / (f32)UINT_MAX) * 0.5f) + 1.0f) * arg2;
    ptr_shattered_window_pieces[D_80040940].field_0x3c = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x48 = ((randomGetNext() * (1.0f / (f32)UINT_MAX) * 0.5f) + 1.0f) * arg2;
    ptr_shattered_window_pieces[D_80040940].field_0x4a = ((randomGetNext() * (1.0f / (f32)UINT_MAX) * 0.5f) + 1.0f) * -arg2;
    ptr_shattered_window_pieces[D_80040940].field_0x4c = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x58 = ((randomGetNext() * (1.0f / (f32)UINT_MAX) * 0.5f) + 1.0f) * -arg2;
    ptr_shattered_window_pieces[D_80040940].field_0x5a = ((randomGetNext() * (1.0f / (f32)UINT_MAX) * 0.5f) + 1.0f) * -arg2;

    ptr_shattered_window_pieces[D_80040940].field_0x5c = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x40 = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x42 = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x50 = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x52 = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x60 = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x62 = 0;
    ptr_shattered_window_pieces[D_80040940].field_0x44 = 5;
    ptr_shattered_window_pieces[D_80040940].field_0x45 = 5;
    ptr_shattered_window_pieces[D_80040940].field_0x46 = 0x7E;
    ptr_shattered_window_pieces[D_80040940].field_0x54 = 5;
    ptr_shattered_window_pieces[D_80040940].field_0x55 = 0xFB;
    ptr_shattered_window_pieces[D_80040940].field_0x56 = 0x7E;
    ptr_shattered_window_pieces[D_80040940].field_0x64 = 0xFB;
    ptr_shattered_window_pieces[D_80040940].field_0x65 = 0xFB;
    ptr_shattered_window_pieces[D_80040940].field_0x66 = 0x7E;
    ptr_shattered_window_pieces[D_80040940].field_0x67 = 0xFF;

    field67 = ptr_shattered_window_pieces[D_80040940].field_0x67;
    ptr_shattered_window_pieces[D_80040940].field_0x57 = field67;
    ptr_shattered_window_pieces[D_80040940].field_0x47 = field67;

    ptr_shattered_window_pieces[D_80040940].field_0x10 = arg1;
    ptr_shattered_window_pieces[D_80040940].field_0x14 = 0.0f;

    ptr_shattered_window_pieces[D_80040940].field_0x18 = (randomGetNext() * (1.0f / (f32)UINT_MAX)) * M_TAU_F;

    ptr_shattered_window_pieces[D_80040940].field_0x28 = (randomGetNext() * (1.0f / (f32)UINT_MAX)) * SCALAR_3_7F0A2160;
    ptr_shattered_window_pieces[D_80040940].field_0x2c = (randomGetNext() * (1.0f / (f32)UINT_MAX)) * SCALAR_3_7F0A2160;
    ptr_shattered_window_pieces[D_80040940].field_0x30 = (randomGetNext() * (1.0f / (f32)UINT_MAX)) * SCALAR_3_7F0A2160;

    D_80040940++;
    if (D_80040940 >= SHATTERED_WINDOW_PIECES_BUFFER_LEN) {
        D_80040940 = 0;
    }
}


#ifdef NONMATCHING
void update_broken_windows(void) {

}
#else

#if defined(LEFTOVERDEBUG)

GLOBAL_ASM(
.late_rodata
glabel D_80057728
.word 0x46ea6000 /*30000.0*/
glabel D_8005772C
.word 0xc6ea6000 /*-30000.0*/
glabel D_80057730
.word 0x3dcccccd /*0.1*/
glabel D_80057734
.word 0x00000000 /*0.0*/
glabel D_80057738
.word 0x00000000 /*0.0*/
glabel D_8005773C
.word 0x00000000 /*0.0*/
.text
glabel update_broken_windows
/* 0D7404 7F0A28D4 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0D7408 7F0A28D8 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0D740C 7F0A28DC 3C088008 */  lui   $t0, %hi(SHATTERED_WINDOW_PIECES_BUFFER_LEN) 
/* 0D7410 7F0A28E0 2508A160 */  addiu $t0, %lo(SHATTERED_WINDOW_PIECES_BUFFER_LEN) # addiu $t0, $t0, -0x5ea0
/* 0D7414 7F0A28E4 2841000F */  slti  $at, $v0, 0xf
/* 0D7418 7F0A28E8 10200004 */  beqz  $at, .L7F0A28FC
/* 0D741C 7F0A28EC 00001825 */   move  $v1, $zero
/* 0D7420 7F0A28F0 44822000 */  mtc1  $v0, $f4
/* 0D7424 7F0A28F4 10000004 */  b     .L7F0A2908
/* 0D7428 7F0A28F8 46802020 */   cvt.s.w $f0, $f4
.L7F0A28FC:
/* 0D742C 7F0A28FC 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0D7430 7F0A2900 44810000 */  mtc1  $at, $f0
/* 0D7434 7F0A2904 00000000 */  nop   
.L7F0A2908:
/* 0D7438 7F0A2908 8D0E0000 */  lw    $t6, ($t0)
/* 0D743C 7F0A290C 00001025 */  move  $v0, $zero
/* 0D7440 7F0A2910 3C018005 */  lui   $at, %hi(D_80057728)
/* 0D7444 7F0A2914 19C000C9 */  blez  $t6, .L7F0A2C3C
/* 0D7448 7F0A2918 3C098008 */   lui   $t1, %hi(ptr_shattered_window_pieces) 
/* 0D744C 7F0A291C C4307728 */  lwc1  $f16, %lo(D_80057728)($at)
/* 0D7450 7F0A2920 3C018005 */  lui   $at, %hi(D_8005772C)
/* 0D7454 7F0A2924 C42E772C */  lwc1  $f14, %lo(D_8005772C)($at)
/* 0D7458 7F0A2928 3C018005 */  lui   $at, %hi(D_80057730)
/* 0D745C 7F0A292C C42C7730 */  lwc1  $f12, %lo(D_80057730)($at)
/* 0D7460 7F0A2930 2529A164 */  addiu $t1, %lo(ptr_shattered_window_pieces) # addiu $t1, $t1, -0x5e9c
/* 0D7464 7F0A2934 8D2F0000 */  lw    $t7, ($t1)
.L7F0A2938:
/* 0D7468 7F0A2938 01E32021 */  addu  $a0, $t7, $v1
/* 0D746C 7F0A293C 8C850000 */  lw    $a1, ($a0)
/* 0D7470 7F0A2940 58A000B9 */  blezl $a1, .L7F0A2C28
/* 0D7474 7F0A2944 8D0C0000 */   lw    $t4, ($t0)
/* 0D7478 7F0A2948 4600018D */  trunc.w.s $f6, $f0
/* 0D747C 7F0A294C 00003825 */  move  $a3, $zero
/* 0D7480 7F0A2950 44063000 */  mfc1  $a2, $f6
/* 0D7484 7F0A2954 00000000 */  nop   
/* 0D7488 7F0A2958 00A6C821 */  addu  $t9, $a1, $a2
/* 0D748C 7F0A295C AC990000 */  sw    $t9, ($a0)
/* 0D7490 7F0A2960 8D2A0000 */  lw    $t2, ($t1)
/* 0D7494 7F0A2964 01432021 */  addu  $a0, $t2, $v1
/* 0D7498 7F0A2968 C48A0028 */  lwc1  $f10, 0x28($a0)
/* 0D749C 7F0A296C C4880010 */  lwc1  $f8, 0x10($a0)
/* 0D74A0 7F0A2970 46005482 */  mul.s $f18, $f10, $f0
/* 0D74A4 7F0A2974 46124100 */  add.s $f4, $f8, $f18
/* 0D74A8 7F0A2978 E4840010 */  swc1  $f4, 0x10($a0)
/* 0D74AC 7F0A297C 8D2B0000 */  lw    $t3, ($t1)
/* 0D74B0 7F0A2980 01632021 */  addu  $a0, $t3, $v1
/* 0D74B4 7F0A2984 C48A002C */  lwc1  $f10, 0x2c($a0)
/* 0D74B8 7F0A2988 C4860014 */  lwc1  $f6, 0x14($a0)
/* 0D74BC 7F0A298C 46005202 */  mul.s $f8, $f10, $f0
/* 0D74C0 7F0A2990 46083480 */  add.s $f18, $f6, $f8
/* 0D74C4 7F0A2994 E4920014 */  swc1  $f18, 0x14($a0)
/* 0D74C8 7F0A2998 8D2C0000 */  lw    $t4, ($t1)
/* 0D74CC 7F0A299C 01832021 */  addu  $a0, $t4, $v1
/* 0D74D0 7F0A29A0 C48A0030 */  lwc1  $f10, 0x30($a0)
/* 0D74D4 7F0A29A4 C4840018 */  lwc1  $f4, 0x18($a0)
/* 0D74D8 7F0A29A8 46005182 */  mul.s $f6, $f10, $f0
/* 0D74DC 7F0A29AC 46062200 */  add.s $f8, $f4, $f6
/* 0D74E0 7F0A29B0 E4880018 */  swc1  $f8, 0x18($a0)
/* 0D74E4 7F0A29B4 8D2D0000 */  lw    $t5, ($t1)
/* 0D74E8 7F0A29B8 01A32021 */  addu  $a0, $t5, $v1
/* 0D74EC 7F0A29BC C48A001C */  lwc1  $f10, 0x1c($a0)
/* 0D74F0 7F0A29C0 C4920004 */  lwc1  $f18, 4($a0)
/* 0D74F4 7F0A29C4 46005102 */  mul.s $f4, $f10, $f0
/* 0D74F8 7F0A29C8 46049180 */  add.s $f6, $f18, $f4
/* 0D74FC 7F0A29CC E4860004 */  swc1  $f6, 4($a0)
/* 0D7500 7F0A29D0 8D2E0000 */  lw    $t6, ($t1)
/* 0D7504 7F0A29D4 01C32021 */  addu  $a0, $t6, $v1
/* 0D7508 7F0A29D8 C48A0024 */  lwc1  $f10, 0x24($a0)
/* 0D750C 7F0A29DC C488000C */  lwc1  $f8, 0xc($a0)
/* 0D7510 7F0A29E0 46005482 */  mul.s $f18, $f10, $f0
/* 0D7514 7F0A29E4 46124100 */  add.s $f4, $f8, $f18
/* 0D7518 7F0A29E8 18C0007B */  blez  $a2, .L7F0A2BD8
/* 0D751C 7F0A29EC E484000C */   swc1  $f4, 0xc($a0)
/* 0D7520 7F0A29F0 30C40003 */  andi  $a0, $a2, 3
/* 0D7524 7F0A29F4 1080001C */  beqz  $a0, .L7F0A2A68
/* 0D7528 7F0A29F8 00802825 */   move  $a1, $a0
/* 0D752C 7F0A29FC 24E70001 */  addiu $a3, $a3, 1
/* 0D7530 7F0A2A00 10A7000E */  beq   $a1, $a3, .L7F0A2A3C
/* 0D7534 7F0A2A04 8D2F0000 */   lw    $t7, ($t1)
.L7F0A2A08:
/* 0D7538 7F0A2A08 01E32021 */  addu  $a0, $t7, $v1
/* 0D753C 7F0A2A0C C4920008 */  lwc1  $f18, 8($a0)
/* 0D7540 7F0A2A10 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D7544 7F0A2A14 24E70001 */  addiu $a3, $a3, 1
/* 0D7548 7F0A2A18 460A9280 */  add.s $f10, $f18, $f10
/* 0D754C 7F0A2A1C E48A0008 */  swc1  $f10, 8($a0)
/* 0D7550 7F0A2A20 8D380000 */  lw    $t8, ($t1)
/* 0D7554 7F0A2A24 03032021 */  addu  $a0, $t8, $v1
/* 0D7558 7F0A2A28 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D755C 7F0A2A2C 460C5281 */  sub.s $f10, $f10, $f12
/* 0D7560 7F0A2A30 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D7564 7F0A2A34 14A7FFF4 */  bne   $a1, $a3, .L7F0A2A08
/* 0D7568 7F0A2A38 8D2F0000 */   lw    $t7, ($t1)
.L7F0A2A3C:
/* 0D756C 7F0A2A3C 01E32021 */  addu  $a0, $t7, $v1
/* 0D7570 7F0A2A40 C4920008 */  lwc1  $f18, 8($a0)
/* 0D7574 7F0A2A44 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D7578 7F0A2A48 460A9280 */  add.s $f10, $f18, $f10
/* 0D757C 7F0A2A4C E48A0008 */  swc1  $f10, 8($a0)
/* 0D7580 7F0A2A50 8D380000 */  lw    $t8, ($t1)
/* 0D7584 7F0A2A54 03032021 */  addu  $a0, $t8, $v1
/* 0D7588 7F0A2A58 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D758C 7F0A2A5C 460C5281 */  sub.s $f10, $f10, $f12
/* 0D7590 7F0A2A60 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D7594 7F0A2A64 10E6005C */  beq   $a3, $a2, .L7F0A2BD8
.L7F0A2A68:
/* 0D7598 7F0A2A68 24E70004 */   addiu $a3, $a3, 4
/* 0D759C 7F0A2A6C 10E6002F */  beq   $a3, $a2, .L7F0A2B2C
/* 0D75A0 7F0A2A70 8D390000 */   lw    $t9, ($t1)
.L7F0A2A74:
/* 0D75A4 7F0A2A74 03232021 */  addu  $a0, $t9, $v1
/* 0D75A8 7F0A2A78 C4920008 */  lwc1  $f18, 8($a0)
/* 0D75AC 7F0A2A7C C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D75B0 7F0A2A80 24E70004 */  addiu $a3, $a3, 4
/* 0D75B4 7F0A2A84 460A9280 */  add.s $f10, $f18, $f10
/* 0D75B8 7F0A2A88 E48A0008 */  swc1  $f10, 8($a0)
/* 0D75BC 7F0A2A8C 8D2A0000 */  lw    $t2, ($t1)
/* 0D75C0 7F0A2A90 01432021 */  addu  $a0, $t2, $v1
/* 0D75C4 7F0A2A94 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D75C8 7F0A2A98 460C5281 */  sub.s $f10, $f10, $f12
/* 0D75CC 7F0A2A9C E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D75D0 7F0A2AA0 8D2B0000 */  lw    $t3, ($t1)
/* 0D75D4 7F0A2AA4 01632021 */  addu  $a0, $t3, $v1
/* 0D75D8 7F0A2AA8 C48A0008 */  lwc1  $f10, 8($a0)
/* 0D75DC 7F0A2AAC C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D75E0 7F0A2AB0 46125480 */  add.s $f18, $f10, $f18
/* 0D75E4 7F0A2AB4 E4920008 */  swc1  $f18, 8($a0)
/* 0D75E8 7F0A2AB8 8D2C0000 */  lw    $t4, ($t1)
/* 0D75EC 7F0A2ABC 01832021 */  addu  $a0, $t4, $v1
/* 0D75F0 7F0A2AC0 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D75F4 7F0A2AC4 460C9481 */  sub.s $f18, $f18, $f12
/* 0D75F8 7F0A2AC8 E4920020 */  swc1  $f18, 0x20($a0)
/* 0D75FC 7F0A2ACC 8D2D0000 */  lw    $t5, ($t1)
/* 0D7600 7F0A2AD0 01A32021 */  addu  $a0, $t5, $v1
/* 0D7604 7F0A2AD4 C4920008 */  lwc1  $f18, 8($a0)
/* 0D7608 7F0A2AD8 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D760C 7F0A2ADC 460A9280 */  add.s $f10, $f18, $f10
/* 0D7610 7F0A2AE0 E48A0008 */  swc1  $f10, 8($a0)
/* 0D7614 7F0A2AE4 8D2E0000 */  lw    $t6, ($t1)
/* 0D7618 7F0A2AE8 01C32021 */  addu  $a0, $t6, $v1
/* 0D761C 7F0A2AEC C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D7620 7F0A2AF0 460C5281 */  sub.s $f10, $f10, $f12
/* 0D7624 7F0A2AF4 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D7628 7F0A2AF8 8D2F0000 */  lw    $t7, ($t1)
/* 0D762C 7F0A2AFC 01E32021 */  addu  $a0, $t7, $v1
/* 0D7630 7F0A2B00 C48A0008 */  lwc1  $f10, 8($a0)
/* 0D7634 7F0A2B04 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D7638 7F0A2B08 46125480 */  add.s $f18, $f10, $f18
/* 0D763C 7F0A2B0C E4920008 */  swc1  $f18, 8($a0)
/* 0D7640 7F0A2B10 8D380000 */  lw    $t8, ($t1)
/* 0D7644 7F0A2B14 03032021 */  addu  $a0, $t8, $v1
/* 0D7648 7F0A2B18 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D764C 7F0A2B1C 460C9481 */  sub.s $f18, $f18, $f12
/* 0D7650 7F0A2B20 E4920020 */  swc1  $f18, 0x20($a0)
/* 0D7654 7F0A2B24 14E6FFD3 */  bne   $a3, $a2, .L7F0A2A74
/* 0D7658 7F0A2B28 8D390000 */   lw    $t9, ($t1)
.L7F0A2B2C:
/* 0D765C 7F0A2B2C 03232021 */  addu  $a0, $t9, $v1
/* 0D7660 7F0A2B30 C4920008 */  lwc1  $f18, 8($a0)
/* 0D7664 7F0A2B34 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D7668 7F0A2B38 460A9280 */  add.s $f10, $f18, $f10
/* 0D766C 7F0A2B3C E48A0008 */  swc1  $f10, 8($a0)
/* 0D7670 7F0A2B40 8D2A0000 */  lw    $t2, ($t1)
/* 0D7674 7F0A2B44 01432021 */  addu  $a0, $t2, $v1
/* 0D7678 7F0A2B48 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D767C 7F0A2B4C 460C5281 */  sub.s $f10, $f10, $f12
/* 0D7680 7F0A2B50 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D7684 7F0A2B54 8D2B0000 */  lw    $t3, ($t1)
/* 0D7688 7F0A2B58 01632021 */  addu  $a0, $t3, $v1
/* 0D768C 7F0A2B5C C48A0008 */  lwc1  $f10, 8($a0)
/* 0D7690 7F0A2B60 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D7694 7F0A2B64 46125480 */  add.s $f18, $f10, $f18
/* 0D7698 7F0A2B68 E4920008 */  swc1  $f18, 8($a0)
/* 0D769C 7F0A2B6C 8D2C0000 */  lw    $t4, ($t1)
/* 0D76A0 7F0A2B70 01832021 */  addu  $a0, $t4, $v1
/* 0D76A4 7F0A2B74 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D76A8 7F0A2B78 460C9481 */  sub.s $f18, $f18, $f12
/* 0D76AC 7F0A2B7C E4920020 */  swc1  $f18, 0x20($a0)
/* 0D76B0 7F0A2B80 8D2D0000 */  lw    $t5, ($t1)
/* 0D76B4 7F0A2B84 01A32021 */  addu  $a0, $t5, $v1
/* 0D76B8 7F0A2B88 C4920008 */  lwc1  $f18, 8($a0)
/* 0D76BC 7F0A2B8C C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D76C0 7F0A2B90 460A9280 */  add.s $f10, $f18, $f10
/* 0D76C4 7F0A2B94 E48A0008 */  swc1  $f10, 8($a0)
/* 0D76C8 7F0A2B98 8D2E0000 */  lw    $t6, ($t1)
/* 0D76CC 7F0A2B9C 01C32021 */  addu  $a0, $t6, $v1
/* 0D76D0 7F0A2BA0 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D76D4 7F0A2BA4 460C5281 */  sub.s $f10, $f10, $f12
/* 0D76D8 7F0A2BA8 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D76DC 7F0A2BAC 8D2F0000 */  lw    $t7, ($t1)
/* 0D76E0 7F0A2BB0 01E32021 */  addu  $a0, $t7, $v1
/* 0D76E4 7F0A2BB4 C48A0008 */  lwc1  $f10, 8($a0)
/* 0D76E8 7F0A2BB8 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D76EC 7F0A2BBC 46125480 */  add.s $f18, $f10, $f18
/* 0D76F0 7F0A2BC0 E4920008 */  swc1  $f18, 8($a0)
/* 0D76F4 7F0A2BC4 8D380000 */  lw    $t8, ($t1)
/* 0D76F8 7F0A2BC8 03032021 */  addu  $a0, $t8, $v1
/* 0D76FC 7F0A2BCC C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D7700 7F0A2BD0 460C9481 */  sub.s $f18, $f18, $f12
/* 0D7704 7F0A2BD4 E4920020 */  swc1  $f18, 0x20($a0)
.L7F0A2BD8:
/* 0D7708 7F0A2BD8 8D390000 */  lw    $t9, ($t1)
/* 0D770C 7F0A2BDC 03232021 */  addu  $a0, $t9, $v1
/* 0D7710 7F0A2BE0 8C8A0000 */  lw    $t2, ($a0)
/* 0D7714 7F0A2BE4 29410096 */  slti  $at, $t2, 0x96
/* 0D7718 7F0A2BE8 54200005 */  bnezl $at, .L7F0A2C00
/* 0D771C 7F0A2BEC C4820008 */   lwc1  $f2, 8($a0)
/* 0D7720 7F0A2BF0 AC800000 */  sw    $zero, ($a0)
/* 0D7724 7F0A2BF4 8D2B0000 */  lw    $t3, ($t1)
/* 0D7728 7F0A2BF8 01632021 */  addu  $a0, $t3, $v1
/* 0D772C 7F0A2BFC C4820008 */  lwc1  $f2, 8($a0)
.L7F0A2C00:
/* 0D7730 7F0A2C00 460E103C */  c.lt.s $f2, $f14
/* 0D7734 7F0A2C04 00000000 */  nop   
/* 0D7738 7F0A2C08 45030006 */  bc1tl .L7F0A2C24
/* 0D773C 7F0A2C0C AC800000 */   sw    $zero, ($a0)
/* 0D7740 7F0A2C10 4602803C */  c.lt.s $f16, $f2
/* 0D7744 7F0A2C14 00000000 */  nop   
/* 0D7748 7F0A2C18 45020003 */  bc1fl .L7F0A2C28
/* 0D774C 7F0A2C1C 8D0C0000 */   lw    $t4, ($t0)
/* 0D7750 7F0A2C20 AC800000 */  sw    $zero, ($a0)
.L7F0A2C24:
/* 0D7754 7F0A2C24 8D0C0000 */  lw    $t4, ($t0)
.L7F0A2C28:
/* 0D7758 7F0A2C28 24420001 */  addiu $v0, $v0, 1
/* 0D775C 7F0A2C2C 24630068 */  addiu $v1, $v1, 0x68
/* 0D7760 7F0A2C30 004C082A */  slt   $at, $v0, $t4
/* 0D7764 7F0A2C34 5420FF40 */  bnezl $at, .L7F0A2938
/* 0D7768 7F0A2C38 8D2F0000 */   lw    $t7, ($t1)
.L7F0A2C3C:
/* 0D776C 7F0A2C3C 03E00008 */  jr    $ra
/* 0D7770 7F0A2C40 00000000 */   nop   
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8004CE00
.word 0x46ea6000 /*30000.0*/
glabel D_8004CE04
.word 0xc6ea6000 /*-30000.0*/
glabel D_8004CE08
.word 0x3dcccccd /*0.1*/
glabel D_8004CE0C
.word 0x00000000 /*0.0*/

.text
glabel update_broken_windows
/* 0D4804 7F0A1E14 3C028004 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8004
/* 0D4808 7F0A1E18 8C420FF4 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0D480C 7F0A1E1C 3C088007 */  lui   $t0, %hi(SHATTERED_WINDOW_PIECES_BUFFER_LEN) # $t0, 0x8007
/* 0D4810 7F0A1E20 25088C70 */  addiu $t0, %lo(SHATTERED_WINDOW_PIECES_BUFFER_LEN) # addiu $t0, $t0, -0x7390
/* 0D4814 7F0A1E24 2841000F */  slti  $at, $v0, 0xf
/* 0D4818 7F0A1E28 10200004 */  beqz  $at, .L7F0A1E3C
/* 0D481C 7F0A1E2C 00001825 */   move  $v1, $zero
/* 0D4820 7F0A1E30 44822000 */  mtc1  $v0, $f4
/* 0D4824 7F0A1E34 10000004 */  b     .L7F0A1E48
/* 0D4828 7F0A1E38 46802020 */   cvt.s.w $f0, $f4
.L7F0A1E3C:
/* 0D482C 7F0A1E3C 3C014170 */  li    $at, 0x41700000 # 15.000000
/* 0D4830 7F0A1E40 44810000 */  mtc1  $at, $f0
/* 0D4834 7F0A1E44 00000000 */  nop   
.L7F0A1E48:
/* 0D4838 7F0A1E48 8D0E0000 */  lw    $t6, ($t0)
/* 0D483C 7F0A1E4C 00001025 */  move  $v0, $zero
/* 0D4840 7F0A1E50 3C018005 */  lui   $at, %hi(D_8004CE00) # $at, 0x8005
/* 0D4844 7F0A1E54 19C000C9 */  blez  $t6, .L7F0A217C
/* 0D4848 7F0A1E58 3C098007 */   lui   $t1, %hi(ptr_shattered_window_pieces) # $t1, 0x8007
/* 0D484C 7F0A1E5C C430CE00 */  lwc1  $f16, %lo(D_8004CE00)($at)
/* 0D4850 7F0A1E60 3C018005 */  lui   $at, %hi(D_8004CE04) # $at, 0x8005
/* 0D4854 7F0A1E64 C42ECE04 */  lwc1  $f14, %lo(D_8004CE04)($at)
/* 0D4858 7F0A1E68 3C018005 */  lui   $at, %hi(D_8004CE08) # $at, 0x8005
/* 0D485C 7F0A1E6C C42CCE08 */  lwc1  $f12, %lo(D_8004CE08)($at)
/* 0D4860 7F0A1E70 25298C74 */  addiu $t1, %lo(ptr_shattered_window_pieces) # addiu $t1, $t1, -0x738c
/* 0D4864 7F0A1E74 8D2F0000 */  lw    $t7, ($t1)
.L7F0A1E78:
/* 0D4868 7F0A1E78 01E32021 */  addu  $a0, $t7, $v1
/* 0D486C 7F0A1E7C 8C850000 */  lw    $a1, ($a0)
/* 0D4870 7F0A1E80 58A000B9 */  blezl $a1, .L7F0A2168
/* 0D4874 7F0A1E84 8D0C0000 */   lw    $t4, ($t0)
/* 0D4878 7F0A1E88 4600018D */  trunc.w.s $f6, $f0
/* 0D487C 7F0A1E8C 00003825 */  move  $a3, $zero
/* 0D4880 7F0A1E90 44063000 */  mfc1  $a2, $f6
/* 0D4884 7F0A1E94 00000000 */  nop   
/* 0D4888 7F0A1E98 00A6C821 */  addu  $t9, $a1, $a2
/* 0D488C 7F0A1E9C AC990000 */  sw    $t9, ($a0)
/* 0D4890 7F0A1EA0 8D2A0000 */  lw    $t2, ($t1)
/* 0D4894 7F0A1EA4 01432021 */  addu  $a0, $t2, $v1
/* 0D4898 7F0A1EA8 C48A0028 */  lwc1  $f10, 0x28($a0)
/* 0D489C 7F0A1EAC C4880010 */  lwc1  $f8, 0x10($a0)
/* 0D48A0 7F0A1EB0 46005482 */  mul.s $f18, $f10, $f0
/* 0D48A4 7F0A1EB4 46124100 */  add.s $f4, $f8, $f18
/* 0D48A8 7F0A1EB8 E4840010 */  swc1  $f4, 0x10($a0)
/* 0D48AC 7F0A1EBC 8D2B0000 */  lw    $t3, ($t1)
/* 0D48B0 7F0A1EC0 01632021 */  addu  $a0, $t3, $v1
/* 0D48B4 7F0A1EC4 C48A002C */  lwc1  $f10, 0x2c($a0)
/* 0D48B8 7F0A1EC8 C4860014 */  lwc1  $f6, 0x14($a0)
/* 0D48BC 7F0A1ECC 46005202 */  mul.s $f8, $f10, $f0
/* 0D48C0 7F0A1ED0 46083480 */  add.s $f18, $f6, $f8
/* 0D48C4 7F0A1ED4 E4920014 */  swc1  $f18, 0x14($a0)
/* 0D48C8 7F0A1ED8 8D2C0000 */  lw    $t4, ($t1)
/* 0D48CC 7F0A1EDC 01832021 */  addu  $a0, $t4, $v1
/* 0D48D0 7F0A1EE0 C48A0030 */  lwc1  $f10, 0x30($a0)
/* 0D48D4 7F0A1EE4 C4840018 */  lwc1  $f4, 0x18($a0)
/* 0D48D8 7F0A1EE8 46005182 */  mul.s $f6, $f10, $f0
/* 0D48DC 7F0A1EEC 46062200 */  add.s $f8, $f4, $f6
/* 0D48E0 7F0A1EF0 E4880018 */  swc1  $f8, 0x18($a0)
/* 0D48E4 7F0A1EF4 8D2D0000 */  lw    $t5, ($t1)
/* 0D48E8 7F0A1EF8 01A32021 */  addu  $a0, $t5, $v1
/* 0D48EC 7F0A1EFC C48A001C */  lwc1  $f10, 0x1c($a0)
/* 0D48F0 7F0A1F00 C4920004 */  lwc1  $f18, 4($a0)
/* 0D48F4 7F0A1F04 46005102 */  mul.s $f4, $f10, $f0
/* 0D48F8 7F0A1F08 46049180 */  add.s $f6, $f18, $f4
/* 0D48FC 7F0A1F0C E4860004 */  swc1  $f6, 4($a0)
/* 0D4900 7F0A1F10 8D2E0000 */  lw    $t6, ($t1)
/* 0D4904 7F0A1F14 01C32021 */  addu  $a0, $t6, $v1
/* 0D4908 7F0A1F18 C48A0024 */  lwc1  $f10, 0x24($a0)
/* 0D490C 7F0A1F1C C488000C */  lwc1  $f8, 0xc($a0)
/* 0D4910 7F0A1F20 46005482 */  mul.s $f18, $f10, $f0
/* 0D4914 7F0A1F24 46124100 */  add.s $f4, $f8, $f18
/* 0D4918 7F0A1F28 18C0007B */  blez  $a2, .L7F0A2118
/* 0D491C 7F0A1F2C E484000C */   swc1  $f4, 0xc($a0)
/* 0D4920 7F0A1F30 30C40003 */  andi  $a0, $a2, 3
/* 0D4924 7F0A1F34 1080001C */  beqz  $a0, .L7F0A1FA8
/* 0D4928 7F0A1F38 00802825 */   move  $a1, $a0
/* 0D492C 7F0A1F3C 24E70001 */  addiu $a3, $a3, 1
/* 0D4930 7F0A1F40 10A7000E */  beq   $a1, $a3, .L7F0A1F7C
/* 0D4934 7F0A1F44 8D2F0000 */   lw    $t7, ($t1)
.L7F0A1F48:
/* 0D4938 7F0A1F48 01E32021 */  addu  $a0, $t7, $v1
/* 0D493C 7F0A1F4C C4920008 */  lwc1  $f18, 8($a0)
/* 0D4940 7F0A1F50 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4944 7F0A1F54 24E70001 */  addiu $a3, $a3, 1
/* 0D4948 7F0A1F58 460A9280 */  add.s $f10, $f18, $f10
/* 0D494C 7F0A1F5C E48A0008 */  swc1  $f10, 8($a0)
/* 0D4950 7F0A1F60 8D380000 */  lw    $t8, ($t1)
/* 0D4954 7F0A1F64 03032021 */  addu  $a0, $t8, $v1
/* 0D4958 7F0A1F68 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D495C 7F0A1F6C 460C5281 */  sub.s $f10, $f10, $f12
/* 0D4960 7F0A1F70 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D4964 7F0A1F74 14A7FFF4 */  bne   $a1, $a3, .L7F0A1F48
/* 0D4968 7F0A1F78 8D2F0000 */   lw    $t7, ($t1)
.L7F0A1F7C:
/* 0D496C 7F0A1F7C 01E32021 */  addu  $a0, $t7, $v1
/* 0D4970 7F0A1F80 C4920008 */  lwc1  $f18, 8($a0)
/* 0D4974 7F0A1F84 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4978 7F0A1F88 460A9280 */  add.s $f10, $f18, $f10
/* 0D497C 7F0A1F8C E48A0008 */  swc1  $f10, 8($a0)
/* 0D4980 7F0A1F90 8D380000 */  lw    $t8, ($t1)
/* 0D4984 7F0A1F94 03032021 */  addu  $a0, $t8, $v1
/* 0D4988 7F0A1F98 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D498C 7F0A1F9C 460C5281 */  sub.s $f10, $f10, $f12
/* 0D4990 7F0A1FA0 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D4994 7F0A1FA4 10E6005C */  beq   $a3, $a2, .L7F0A2118
.L7F0A1FA8:
/* 0D4998 7F0A1FA8 24E70004 */   addiu $a3, $a3, 4
/* 0D499C 7F0A1FAC 10E6002F */  beq   $a3, $a2, .L7F0A206C
/* 0D49A0 7F0A1FB0 8D390000 */   lw    $t9, ($t1)
.L7F0A1FB4:
/* 0D49A4 7F0A1FB4 03232021 */  addu  $a0, $t9, $v1
/* 0D49A8 7F0A1FB8 C4920008 */  lwc1  $f18, 8($a0)
/* 0D49AC 7F0A1FBC C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D49B0 7F0A1FC0 24E70004 */  addiu $a3, $a3, 4
/* 0D49B4 7F0A1FC4 460A9280 */  add.s $f10, $f18, $f10
/* 0D49B8 7F0A1FC8 E48A0008 */  swc1  $f10, 8($a0)
/* 0D49BC 7F0A1FCC 8D2A0000 */  lw    $t2, ($t1)
/* 0D49C0 7F0A1FD0 01432021 */  addu  $a0, $t2, $v1
/* 0D49C4 7F0A1FD4 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D49C8 7F0A1FD8 460C5281 */  sub.s $f10, $f10, $f12
/* 0D49CC 7F0A1FDC E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D49D0 7F0A1FE0 8D2B0000 */  lw    $t3, ($t1)
/* 0D49D4 7F0A1FE4 01632021 */  addu  $a0, $t3, $v1
/* 0D49D8 7F0A1FE8 C48A0008 */  lwc1  $f10, 8($a0)
/* 0D49DC 7F0A1FEC C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D49E0 7F0A1FF0 46125480 */  add.s $f18, $f10, $f18
/* 0D49E4 7F0A1FF4 E4920008 */  swc1  $f18, 8($a0)
/* 0D49E8 7F0A1FF8 8D2C0000 */  lw    $t4, ($t1)
/* 0D49EC 7F0A1FFC 01832021 */  addu  $a0, $t4, $v1
/* 0D49F0 7F0A2000 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D49F4 7F0A2004 460C9481 */  sub.s $f18, $f18, $f12
/* 0D49F8 7F0A2008 E4920020 */  swc1  $f18, 0x20($a0)
/* 0D49FC 7F0A200C 8D2D0000 */  lw    $t5, ($t1)
/* 0D4A00 7F0A2010 01A32021 */  addu  $a0, $t5, $v1
/* 0D4A04 7F0A2014 C4920008 */  lwc1  $f18, 8($a0)
/* 0D4A08 7F0A2018 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4A0C 7F0A201C 460A9280 */  add.s $f10, $f18, $f10
/* 0D4A10 7F0A2020 E48A0008 */  swc1  $f10, 8($a0)
/* 0D4A14 7F0A2024 8D2E0000 */  lw    $t6, ($t1)
/* 0D4A18 7F0A2028 01C32021 */  addu  $a0, $t6, $v1
/* 0D4A1C 7F0A202C C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4A20 7F0A2030 460C5281 */  sub.s $f10, $f10, $f12
/* 0D4A24 7F0A2034 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D4A28 7F0A2038 8D2F0000 */  lw    $t7, ($t1)
/* 0D4A2C 7F0A203C 01E32021 */  addu  $a0, $t7, $v1
/* 0D4A30 7F0A2040 C48A0008 */  lwc1  $f10, 8($a0)
/* 0D4A34 7F0A2044 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D4A38 7F0A2048 46125480 */  add.s $f18, $f10, $f18
/* 0D4A3C 7F0A204C E4920008 */  swc1  $f18, 8($a0)
/* 0D4A40 7F0A2050 8D380000 */  lw    $t8, ($t1)
/* 0D4A44 7F0A2054 03032021 */  addu  $a0, $t8, $v1
/* 0D4A48 7F0A2058 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D4A4C 7F0A205C 460C9481 */  sub.s $f18, $f18, $f12
/* 0D4A50 7F0A2060 E4920020 */  swc1  $f18, 0x20($a0)
/* 0D4A54 7F0A2064 14E6FFD3 */  bne   $a3, $a2, .L7F0A1FB4
/* 0D4A58 7F0A2068 8D390000 */   lw    $t9, ($t1)
.L7F0A206C:
/* 0D4A5C 7F0A206C 03232021 */  addu  $a0, $t9, $v1
/* 0D4A60 7F0A2070 C4920008 */  lwc1  $f18, 8($a0)
/* 0D4A64 7F0A2074 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4A68 7F0A2078 460A9280 */  add.s $f10, $f18, $f10
/* 0D4A6C 7F0A207C E48A0008 */  swc1  $f10, 8($a0)
/* 0D4A70 7F0A2080 8D2A0000 */  lw    $t2, ($t1)
/* 0D4A74 7F0A2084 01432021 */  addu  $a0, $t2, $v1
/* 0D4A78 7F0A2088 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4A7C 7F0A208C 460C5281 */  sub.s $f10, $f10, $f12
/* 0D4A80 7F0A2090 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D4A84 7F0A2094 8D2B0000 */  lw    $t3, ($t1)
/* 0D4A88 7F0A2098 01632021 */  addu  $a0, $t3, $v1
/* 0D4A8C 7F0A209C C48A0008 */  lwc1  $f10, 8($a0)
/* 0D4A90 7F0A20A0 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D4A94 7F0A20A4 46125480 */  add.s $f18, $f10, $f18
/* 0D4A98 7F0A20A8 E4920008 */  swc1  $f18, 8($a0)
/* 0D4A9C 7F0A20AC 8D2C0000 */  lw    $t4, ($t1)
/* 0D4AA0 7F0A20B0 01832021 */  addu  $a0, $t4, $v1
/* 0D4AA4 7F0A20B4 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D4AA8 7F0A20B8 460C9481 */  sub.s $f18, $f18, $f12
/* 0D4AAC 7F0A20BC E4920020 */  swc1  $f18, 0x20($a0)
/* 0D4AB0 7F0A20C0 8D2D0000 */  lw    $t5, ($t1)
/* 0D4AB4 7F0A20C4 01A32021 */  addu  $a0, $t5, $v1
/* 0D4AB8 7F0A20C8 C4920008 */  lwc1  $f18, 8($a0)
/* 0D4ABC 7F0A20CC C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4AC0 7F0A20D0 460A9280 */  add.s $f10, $f18, $f10
/* 0D4AC4 7F0A20D4 E48A0008 */  swc1  $f10, 8($a0)
/* 0D4AC8 7F0A20D8 8D2E0000 */  lw    $t6, ($t1)
/* 0D4ACC 7F0A20DC 01C32021 */  addu  $a0, $t6, $v1
/* 0D4AD0 7F0A20E0 C48A0020 */  lwc1  $f10, 0x20($a0)
/* 0D4AD4 7F0A20E4 460C5281 */  sub.s $f10, $f10, $f12
/* 0D4AD8 7F0A20E8 E48A0020 */  swc1  $f10, 0x20($a0)
/* 0D4ADC 7F0A20EC 8D2F0000 */  lw    $t7, ($t1)
/* 0D4AE0 7F0A20F0 01E32021 */  addu  $a0, $t7, $v1
/* 0D4AE4 7F0A20F4 C48A0008 */  lwc1  $f10, 8($a0)
/* 0D4AE8 7F0A20F8 C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D4AEC 7F0A20FC 46125480 */  add.s $f18, $f10, $f18
/* 0D4AF0 7F0A2100 E4920008 */  swc1  $f18, 8($a0)
/* 0D4AF4 7F0A2104 8D380000 */  lw    $t8, ($t1)
/* 0D4AF8 7F0A2108 03032021 */  addu  $a0, $t8, $v1
/* 0D4AFC 7F0A210C C4920020 */  lwc1  $f18, 0x20($a0)
/* 0D4B00 7F0A2110 460C9481 */  sub.s $f18, $f18, $f12
/* 0D4B04 7F0A2114 E4920020 */  swc1  $f18, 0x20($a0)
.L7F0A2118:
/* 0D4B08 7F0A2118 8D390000 */  lw    $t9, ($t1)
/* 0D4B0C 7F0A211C 03232021 */  addu  $a0, $t9, $v1
/* 0D4B10 7F0A2120 8C8A0000 */  lw    $t2, ($a0)
/* 0D4B14 7F0A2124 29410096 */  slti  $at, $t2, 0x96
/* 0D4B18 7F0A2128 54200005 */  bnezl $at, .L7F0A2140
/* 0D4B1C 7F0A212C C4820008 */   lwc1  $f2, 8($a0)
/* 0D4B20 7F0A2130 AC800000 */  sw    $zero, ($a0)
/* 0D4B24 7F0A2134 8D2B0000 */  lw    $t3, ($t1)
/* 0D4B28 7F0A2138 01632021 */  addu  $a0, $t3, $v1
/* 0D4B2C 7F0A213C C4820008 */  lwc1  $f2, 8($a0)
.L7F0A2140:
/* 0D4B30 7F0A2140 460E103C */  c.lt.s $f2, $f14
/* 0D4B34 7F0A2144 00000000 */  nop   
/* 0D4B38 7F0A2148 45030006 */  bc1tl .L7F0A2164
/* 0D4B3C 7F0A214C AC800000 */   sw    $zero, ($a0)
/* 0D4B40 7F0A2150 4602803C */  c.lt.s $f16, $f2
/* 0D4B44 7F0A2154 00000000 */  nop   
/* 0D4B48 7F0A2158 45020003 */  bc1fl .L7F0A2168
/* 0D4B4C 7F0A215C 8D0C0000 */   lw    $t4, ($t0)
/* 0D4B50 7F0A2160 AC800000 */  sw    $zero, ($a0)
.L7F0A2164:
/* 0D4B54 7F0A2164 8D0C0000 */  lw    $t4, ($t0)
.L7F0A2168:
/* 0D4B58 7F0A2168 24420001 */  addiu $v0, $v0, 1
/* 0D4B5C 7F0A216C 24630068 */  addiu $v1, $v1, 0x68
/* 0D4B60 7F0A2170 004C082A */  slt   $at, $v0, $t4
/* 0D4B64 7F0A2174 5420FF40 */  bnezl $at, .L7F0A1E78
/* 0D4B68 7F0A2178 8D2F0000 */   lw    $t7, ($t1)
.L7F0A217C:
/* 0D4B6C 7F0A217C 03E00008 */  jr    $ra
/* 0D4B70 7F0A2180 00000000 */   nop   
)
#endif
#endif





#ifdef NONMATCHING
Gfx * sub_GAME_7F0A2C44(Gfx *arg0) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A2C44
/* 0D7774 7F0A2C44 27BDFF30 */  addiu $sp, $sp, -0xd0
/* 0D7778 7F0A2C48 3C058009 */  lui   $a1, %hi(glassoverlayimage)
/* 0D777C 7F0A2C4C 8CA5D11C */  lw    $a1, %lo(glassoverlayimage)($a1)
/* 0D7780 7F0A2C50 AFBF0044 */  sw    $ra, 0x44($sp)
/* 0D7784 7F0A2C54 AFA400D0 */  sw    $a0, 0xd0($sp)
/* 0D7788 7F0A2C58 240E0002 */  li    $t6, 2
/* 0D778C 7F0A2C5C AFBE0040 */  sw    $fp, 0x40($sp)
/* 0D7790 7F0A2C60 AFB7003C */  sw    $s7, 0x3c($sp)
/* 0D7794 7F0A2C64 AFB60038 */  sw    $s6, 0x38($sp)
/* 0D7798 7F0A2C68 AFB50034 */  sw    $s5, 0x34($sp)
/* 0D779C 7F0A2C6C AFB40030 */  sw    $s4, 0x30($sp)
/* 0D77A0 7F0A2C70 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0D77A4 7F0A2C74 AFB20028 */  sw    $s2, 0x28($sp)
/* 0D77A8 7F0A2C78 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D77AC 7F0A2C7C AFB00020 */  sw    $s0, 0x20($sp)
/* 0D77B0 7F0A2C80 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0D77B4 7F0A2C84 27A400D0 */  addiu $a0, $sp, 0xd0
/* 0D77B8 7F0A2C88 24060002 */  li    $a2, 2
/* 0D77BC 7F0A2C8C 24070001 */  li    $a3, 1
/* 0D77C0 7F0A2C90 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0D77C4 7F0A2C94 24A5000C */   addiu $a1, $a1, 0xc
/* 0D77C8 7F0A2C98 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0D77CC 7F0A2C9C 3C19BB00 */  lui   $t9, (0xBB001001 >> 16) # lui $t9, 0xbb00
/* 0D77D0 7F0A2CA0 3C080D80 */  lui   $t0, (0x0D800D80 >> 16) # lui $t0, 0xd80
/* 0D77D4 7F0A2CA4 25F80008 */  addiu $t8, $t7, 8
/* 0D77D8 7F0A2CA8 AFB800D0 */  sw    $t8, 0xd0($sp)
/* 0D77DC 7F0A2CAC 35080D80 */  ori   $t0, (0x0D800D80 & 0xFFFF) # ori $t0, $t0, 0xd80
/* 0D77E0 7F0A2CB0 37391001 */  ori   $t9, (0xBB001001 & 0xFFFF) # ori $t9, $t9, 0x1001
/* 0D77E4 7F0A2CB4 ADF90000 */  sw    $t9, ($t7)
/* 0D77E8 7F0A2CB8 ADE80004 */  sw    $t0, 4($t7)
/* 0D77EC 7F0A2CBC 8FA900D0 */  lw    $t1, 0xd0($sp)
/* 0D77F0 7F0A2CC0 3C0BBA00 */  lui   $t3, (0xBA001402 >> 16) # lui $t3, 0xba00
/* 0D77F4 7F0A2CC4 356B1402 */  ori   $t3, (0xBA001402 & 0xFFFF) # ori $t3, $t3, 0x1402
/* 0D77F8 7F0A2CC8 252A0008 */  addiu $t2, $t1, 8
/* 0D77FC 7F0A2CCC AFAA00D0 */  sw    $t2, 0xd0($sp)
/* 0D7800 7F0A2CD0 3C0C0010 */  lui   $t4, 0x10
/* 0D7804 7F0A2CD4 AD2C0004 */  sw    $t4, 4($t1)
/* 0D7808 7F0A2CD8 AD2B0000 */  sw    $t3, ($t1)
/* 0D780C 7F0A2CDC 8FAD00D0 */  lw    $t5, 0xd0($sp)
/* 0D7810 7F0A2CE0 3C0FBA00 */  lui   $t7, (0xBA001001 >> 16) # lui $t7, 0xba00
/* 0D7814 7F0A2CE4 35EF1001 */  ori   $t7, (0xBA001001 & 0xFFFF) # ori $t7, $t7, 0x1001
/* 0D7818 7F0A2CE8 25AE0008 */  addiu $t6, $t5, 8
/* 0D781C 7F0A2CEC AFAE00D0 */  sw    $t6, 0xd0($sp)
/* 0D7820 7F0A2CF0 3C180001 */  lui   $t8, 1
/* 0D7824 7F0A2CF4 ADB80004 */  sw    $t8, 4($t5)
/* 0D7828 7F0A2CF8 ADAF0000 */  sw    $t7, ($t5)
/* 0D782C 7F0A2CFC 8FB900D0 */  lw    $t9, 0xd0($sp)
/* 0D7830 7F0A2D00 3C09B600 */  lui   $t1, 0xb600
/* 0D7834 7F0A2D04 240A3000 */  li    $t2, 12288
/* 0D7838 7F0A2D08 27280008 */  addiu $t0, $t9, 8
/* 0D783C 7F0A2D0C AFA800D0 */  sw    $t0, 0xd0($sp)
/* 0D7840 7F0A2D10 AF2A0004 */  sw    $t2, 4($t9)
/* 0D7844 7F0A2D14 AF290000 */  sw    $t1, ($t9)
/* 0D7848 7F0A2D18 8FAB00D0 */  lw    $t3, 0xd0($sp)
/* 0D784C 7F0A2D1C 3C0DBA00 */  lui   $t5, (0xBA000C02 >> 16) # lui $t5, 0xba00
/* 0D7850 7F0A2D20 35AD0C02 */  ori   $t5, (0xBA000C02 & 0xFFFF) # ori $t5, $t5, 0xc02
/* 0D7854 7F0A2D24 256C0008 */  addiu $t4, $t3, 8
/* 0D7858 7F0A2D28 AFAC00D0 */  sw    $t4, 0xd0($sp)
/* 0D785C 7F0A2D2C 240E2000 */  li    $t6, 8192
/* 0D7860 7F0A2D30 AD6E0004 */  sw    $t6, 4($t3)
/* 0D7864 7F0A2D34 AD6D0000 */  sw    $t5, ($t3)
/* 0D7868 7F0A2D38 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0D786C 7F0A2D3C 3C19B700 */  lui   $t9, 0xb700
/* 0D7870 7F0A2D40 3C080006 */  lui   $t0, 6
/* 0D7874 7F0A2D44 25F80008 */  addiu $t8, $t7, 8
/* 0D7878 7F0A2D48 AFB800D0 */  sw    $t8, 0xd0($sp)
/* 0D787C 7F0A2D4C ADE80004 */  sw    $t0, 4($t7)
/* 0D7880 7F0A2D50 ADF90000 */  sw    $t9, ($t7)
/* 0D7884 7F0A2D54 8FB000D0 */  lw    $s0, 0xd0($sp)
/* 0D7888 7F0A2D58 3C0B0103 */  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
/* 0D788C 7F0A2D5C 356B0040 */  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
/* 0D7890 7F0A2D60 260A0008 */  addiu $t2, $s0, 8
/* 0D7894 7F0A2D64 AFAA00D0 */  sw    $t2, 0xd0($sp)
/* 0D7898 7F0A2D68 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0D789C 7F0A2D6C AE0B0000 */   sw    $t3, ($s0)
/* 0D78A0 7F0A2D70 0C003A2C */  jal   osVirtualToPhysical
/* 0D78A4 7F0A2D74 00402025 */   move  $a0, $v0
/* 0D78A8 7F0A2D78 AE020004 */  sw    $v0, 4($s0)
/* 0D78AC 7F0A2D7C 3C048008 */  lui   $a0, %hi(SHATTERED_WINDOW_PIECES_BUFFER_LEN)
/* 0D78B0 7F0A2D80 8C84A160 */  lw    $a0, %lo(SHATTERED_WINDOW_PIECES_BUFFER_LEN)($a0)
/* 0D78B4 7F0A2D84 00008025 */  move  $s0, $zero
/* 0D78B8 7F0A2D88 0000A025 */  move  $s4, $zero
/* 0D78BC 7F0A2D8C 18800044 */  blez  $a0, .L7F0A2EA0
/* 0D78C0 7F0A2D90 3C170420 */   lui   $s7, (0x04200030 >> 16) # lui $s7, 0x420
/* 0D78C4 7F0A2D94 3C168008 */  lui   $s6, %hi(g_CurrentPlayer)
/* 0D78C8 7F0A2D98 3C138008 */  lui   $s3, %hi(ptr_shattered_window_pieces)
/* 0D78CC 7F0A2D9C 2673A164 */  addiu $s3, %lo(ptr_shattered_window_pieces) # addiu $s3, $s3, -0x5e9c
/* 0D78D0 7F0A2DA0 26D6A0B0 */  addiu $s6, %lo(g_CurrentPlayer) # addiu $s6, $s6, -0x5f50
/* 0D78D4 7F0A2DA4 3C1EBF00 */  lui   $fp, 0xbf00
/* 0D78D8 7F0A2DA8 36F70030 */  ori   $s7, (0x04200030 & 0xFFFF) # ori $s7, $s7, 0x30
/* 0D78DC 7F0A2DAC 27B50090 */  addiu $s5, $sp, 0x90
.L7F0A2DB0:
/* 0D78E0 7F0A2DB0 8E6C0000 */  lw    $t4, ($s3)
/* 0D78E4 7F0A2DB4 01906821 */  addu  $t5, $t4, $s0
/* 0D78E8 7F0A2DB8 8DAE0000 */  lw    $t6, ($t5)
/* 0D78EC 7F0A2DBC 59C00035 */  blezl $t6, .L7F0A2E94
/* 0D78F0 7F0A2DC0 26940001 */   addiu $s4, $s4, 1
/* 0D78F4 7F0A2DC4 0FC2F5B8 */  jal   dynAllocateMatrix
/* 0D78F8 7F0A2DC8 00000000 */   nop   
/* 0D78FC 7F0A2DCC 8E6F0000 */  lw    $t7, ($s3)
/* 0D7900 7F0A2DD0 00408825 */  move  $s1, $v0
/* 0D7904 7F0A2DD4 02A03025 */  move  $a2, $s5
/* 0D7908 7F0A2DD8 01F01821 */  addu  $v1, $t7, $s0
/* 0D790C 7F0A2DDC 24640004 */  addiu $a0, $v1, 4
/* 0D7910 7F0A2DE0 0FC1624B */  jal   matrix_4x4_set_position_and_rotation_around_xyz
/* 0D7914 7F0A2DE4 24650010 */   addiu $a1, $v1, 0x10
/* 0D7918 7F0A2DE8 8EC20000 */  lw    $v0, ($s6)
/* 0D791C 7F0A2DEC C7A400C0 */  lwc1  $f4, 0xc0($sp)
/* 0D7920 7F0A2DF0 C7AA00C4 */  lwc1  $f10, 0xc4($sp)
/* 0D7924 7F0A2DF4 C4460038 */  lwc1  $f6, 0x38($v0)
/* 0D7928 7F0A2DF8 02A02025 */  move  $a0, $s5
/* 0D792C 7F0A2DFC 02202825 */  move  $a1, $s1
/* 0D7930 7F0A2E00 46062201 */  sub.s $f8, $f4, $f6
/* 0D7934 7F0A2E04 C7A400C8 */  lwc1  $f4, 0xc8($sp)
/* 0D7938 7F0A2E08 E7A800C0 */  swc1  $f8, 0xc0($sp)
/* 0D793C 7F0A2E0C C450003C */  lwc1  $f16, 0x3c($v0)
/* 0D7940 7F0A2E10 46105481 */  sub.s $f18, $f10, $f16
/* 0D7944 7F0A2E14 E7B200C4 */  swc1  $f18, 0xc4($sp)
/* 0D7948 7F0A2E18 C4460040 */  lwc1  $f6, 0x40($v0)
/* 0D794C 7F0A2E1C 46062201 */  sub.s $f8, $f4, $f6
/* 0D7950 7F0A2E20 0FC16327 */  jal   matrix_4x4_f32_to_s32
/* 0D7954 7F0A2E24 E7A800C8 */   swc1  $f8, 0xc8($sp)
/* 0D7958 7F0A2E28 8FB200D0 */  lw    $s2, 0xd0($sp)
/* 0D795C 7F0A2E2C 3C080102 */  lui   $t0, (0x01020040 >> 16) # lui $t0, 0x102
/* 0D7960 7F0A2E30 35080040 */  ori   $t0, (0x01020040 & 0xFFFF) # ori $t0, $t0, 0x40
/* 0D7964 7F0A2E34 26590008 */  addiu $t9, $s2, 8
/* 0D7968 7F0A2E38 AFB900D0 */  sw    $t9, 0xd0($sp)
/* 0D796C 7F0A2E3C 02202025 */  move  $a0, $s1
/* 0D7970 7F0A2E40 0C003A2C */  jal   osVirtualToPhysical
/* 0D7974 7F0A2E44 AE480000 */   sw    $t0, ($s2)
/* 0D7978 7F0A2E48 AE420004 */  sw    $v0, 4($s2)
/* 0D797C 7F0A2E4C 8FB100D0 */  lw    $s1, 0xd0($sp)
/* 0D7980 7F0A2E50 262A0008 */  addiu $t2, $s1, 8
/* 0D7984 7F0A2E54 AFAA00D0 */  sw    $t2, 0xd0($sp)
/* 0D7988 7F0A2E58 AE370000 */  sw    $s7, ($s1)
/* 0D798C 7F0A2E5C 8E6B0000 */  lw    $t3, ($s3)
/* 0D7990 7F0A2E60 01702021 */  addu  $a0, $t3, $s0
/* 0D7994 7F0A2E64 0C003A2C */  jal   osVirtualToPhysical
/* 0D7998 7F0A2E68 24840038 */   addiu $a0, $a0, 0x38
/* 0D799C 7F0A2E6C AE220004 */  sw    $v0, 4($s1)
/* 0D79A0 7F0A2E70 8FAC00D0 */  lw    $t4, 0xd0($sp)
/* 0D79A4 7F0A2E74 240E0A14 */  li    $t6, 2580
/* 0D79A8 7F0A2E78 3C048008 */  lui   $a0, %hi(SHATTERED_WINDOW_PIECES_BUFFER_LEN)
/* 0D79AC 7F0A2E7C 258D0008 */  addiu $t5, $t4, 8
/* 0D79B0 7F0A2E80 AFAD00D0 */  sw    $t5, 0xd0($sp)
/* 0D79B4 7F0A2E84 AD8E0004 */  sw    $t6, 4($t4)
/* 0D79B8 7F0A2E88 AD9E0000 */  sw    $fp, ($t4)
/* 0D79BC 7F0A2E8C 8C84A160 */  lw    $a0, %lo(SHATTERED_WINDOW_PIECES_BUFFER_LEN)($a0)
/* 0D79C0 7F0A2E90 26940001 */  addiu $s4, $s4, 1
.L7F0A2E94:
/* 0D79C4 7F0A2E94 0284082A */  slt   $at, $s4, $a0
/* 0D79C8 7F0A2E98 1420FFC5 */  bnez  $at, .L7F0A2DB0
/* 0D79CC 7F0A2E9C 26100068 */   addiu $s0, $s0, 0x68
.L7F0A2EA0:
/* 0D79D0 7F0A2EA0 8FAF00D0 */  lw    $t7, 0xd0($sp)
/* 0D79D4 7F0A2EA4 3C19B600 */  lui   $t9, 0xb600
/* 0D79D8 7F0A2EA8 3C080006 */  lui   $t0, 6
/* 0D79DC 7F0A2EAC 25F80008 */  addiu $t8, $t7, 8
/* 0D79E0 7F0A2EB0 AFB800D0 */  sw    $t8, 0xd0($sp)
/* 0D79E4 7F0A2EB4 ADE80004 */  sw    $t0, 4($t7)
/* 0D79E8 7F0A2EB8 ADF90000 */  sw    $t9, ($t7)
/* 0D79EC 7F0A2EBC 8FB000D0 */  lw    $s0, 0xd0($sp)
/* 0D79F0 7F0A2EC0 3C0B0103 */  lui   $t3, (0x01030040 >> 16) # lui $t3, 0x103
/* 0D79F4 7F0A2EC4 356B0040 */  ori   $t3, (0x01030040 & 0xFFFF) # ori $t3, $t3, 0x40
/* 0D79F8 7F0A2EC8 260A0008 */  addiu $t2, $s0, 8
/* 0D79FC 7F0A2ECC AFAA00D0 */  sw    $t2, 0xd0($sp)
/* 0D7A00 7F0A2ED0 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0D7A04 7F0A2ED4 AE0B0000 */   sw    $t3, ($s0)
/* 0D7A08 7F0A2ED8 AE020004 */  sw    $v0, 4($s0)
/* 0D7A0C 7F0A2EDC 8FB100D0 */  lw    $s1, 0xd0($sp)
/* 0D7A10 7F0A2EE0 3C0E0102 */  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
/* 0D7A14 7F0A2EE4 35CE0040 */  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
/* 0D7A18 7F0A2EE8 262D0008 */  addiu $t5, $s1, 8
/* 0D7A1C 7F0A2EEC AFAD00D0 */  sw    $t5, 0xd0($sp)
/* 0D7A20 7F0A2EF0 0FC1E0D5 */  jal   currentPlayerGetMatrix10C8
/* 0D7A24 7F0A2EF4 AE2E0000 */   sw    $t6, ($s1)
/* 0D7A28 7F0A2EF8 AE220004 */  sw    $v0, 4($s1)
/* 0D7A2C 7F0A2EFC 8FBF0044 */  lw    $ra, 0x44($sp)
/* 0D7A30 7F0A2F00 8FBE0040 */  lw    $fp, 0x40($sp)
/* 0D7A34 7F0A2F04 8FB7003C */  lw    $s7, 0x3c($sp)
/* 0D7A38 7F0A2F08 8FB60038 */  lw    $s6, 0x38($sp)
/* 0D7A3C 7F0A2F0C 8FB50034 */  lw    $s5, 0x34($sp)
/* 0D7A40 7F0A2F10 8FB40030 */  lw    $s4, 0x30($sp)
/* 0D7A44 7F0A2F14 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0D7A48 7F0A2F18 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D7A4C 7F0A2F1C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D7A50 7F0A2F20 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D7A54 7F0A2F24 8FA200D0 */  lw    $v0, 0xd0($sp)
/* 0D7A58 7F0A2F28 03E00008 */  jr    $ra
/* 0D7A5C 7F0A2F2C 27BD00D0 */   addiu $sp, $sp, 0xd0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A2F30(void) {

}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_80057740
.word 0x4061d000, 0x00000000 /*142.5*/
glabel D_80057748
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F0A2F30
/* 0D7A60 7F0A2F30 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0D7A64 7F0A2F34 AFB60060 */  sw    $s6, 0x60($sp)
/* 0D7A68 7F0A2F38 00C0B025 */  move  $s6, $a2
/* 0D7A6C 7F0A2F3C 44963000 */  mtc1  $s6, $f6
/* 0D7A70 7F0A2F40 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 0D7A74 7F0A2F44 44812000 */  mtc1  $at, $f4
/* 0D7A78 7F0A2F48 46803220 */  cvt.s.w $f8, $f6
/* 0D7A7C 7F0A2F4C F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0D7A80 7F0A2F50 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0D7A84 7F0A2F54 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D7A88 7F0A2F58 4481F000 */  mtc1  $at, $f30
/* 0D7A8C 7F0A2F5C 4487B000 */  mtc1  $a3, $f22
/* 0D7A90 7F0A2F60 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0D7A94 7F0A2F64 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D7A98 7F0A2F68 4481E000 */  mtc1  $at, $f28
/* 0D7A9C 7F0A2F6C F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D7AA0 7F0A2F70 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0D7AA4 7F0A2F74 AFBE0068 */  sw    $fp, 0x68($sp)
/* 0D7AA8 7F0A2F78 AFB70064 */  sw    $s7, 0x64($sp)
/* 0D7AAC 7F0A2F7C AFB5005C */  sw    $s5, 0x5c($sp)
/* 0D7AB0 7F0A2F80 AFB30054 */  sw    $s3, 0x54($sp)
/* 0D7AB4 7F0A2F84 AFB20050 */  sw    $s2, 0x50($sp)
/* 0D7AB8 7F0A2F88 AFB00048 */  sw    $s0, 0x48($sp)
/* 0D7ABC 7F0A2F8C 4481D000 */  mtc1  $at, $f26
/* 0D7AC0 7F0A2F90 4604B582 */  mul.s $f22, $f22, $f4
/* 0D7AC4 7F0A2F94 00808025 */  move  $s0, $a0
/* 0D7AC8 7F0A2F98 AFBF006C */  sw    $ra, 0x6c($sp)
/* 0D7ACC 7F0A2F9C AFB40058 */  sw    $s4, 0x58($sp)
/* 0D7AD0 7F0A2FA0 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0D7AD4 7F0A2FA4 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D7AD8 7F0A2FA8 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D7ADC 7F0A2FAC AFA5009C */  sw    $a1, 0x9c($sp)
/* 0D7AE0 7F0A2FB0 00009025 */  move  $s2, $zero
/* 0D7AE4 7F0A2FB4 241300FF */  li    $s3, 255
/* 0D7AE8 7F0A2FB8 24150030 */  li    $s5, 48
/* 0D7AEC 7F0A2FBC 24170006 */  li    $s7, 6
/* 0D7AF0 7F0A2FC0 241E0002 */  li    $fp, 2
/* 0D7AF4 7F0A2FC4 E7A80074 */  swc1  $f8, 0x74($sp)
/* 0D7AF8 7F0A2FC8 AFA00080 */  sw    $zero, 0x80($sp)
.L7F0A2FCC:
/* 0D7AFC 7F0A2FCC 8FA20080 */  lw    $v0, 0x80($sp)
/* 0D7B00 7F0A2FD0 3C018005 */  lui    $at, %hi(D_80057740)
/* 0D7B04 7F0A2FD4 D42A7740 */  ldc1  $f10, %lo(D_80057740)($at)
/* 0D7B08 7F0A2FD8 44828000 */  mtc1  $v0, $f16
/* 0D7B0C 7F0A2FDC 3C018005 */  lui    $at, %hi(D_80057748)
/* 0D7B10 7F0A2FE0 0000A025 */  move  $s4, $zero
/* 0D7B14 7F0A2FE4 468084A1 */  cvt.d.w $f18, $f16
/* 0D7B18 7F0A2FE8 46325101 */  sub.d $f4, $f10, $f18
/* 0D7B1C 7F0A2FEC C42A7748 */  lwc1  $f10, %lo(D_80057748)($at)
/* 0D7B20 7F0A2FF0 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0D7B24 7F0A2FF4 4620218D */  trunc.w.d $f6, $f4
/* 0D7B28 7F0A2FF8 44812000 */  mtc1  $at, $f4
/* 0D7B2C 7F0A2FFC 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0D7B30 7F0A3000 440F3000 */  mfc1  $t7, $f6
/* 0D7B34 7F0A3004 00000000 */  nop   
/* 0D7B38 7F0A3008 448F4000 */  mtc1  $t7, $f8
/* 0D7B3C 7F0A300C 00000000 */  nop   
/* 0D7B40 7F0A3010 46804420 */  cvt.s.w $f16, $f8
/* 0D7B44 7F0A3014 44814000 */  mtc1  $at, $f8
/* 0D7B48 7F0A3018 460A8482 */  mul.s $f18, $f16, $f10
/* 0D7B4C 7F0A301C 00000000 */  nop   
/* 0D7B50 7F0A3020 46049182 */  mul.s $f6, $f18, $f4
/* 0D7B54 7F0A3024 46083603 */  div.s $f24, $f6, $f8
.L7F0A3028:
/* 0D7B58 7F0A3028 0FC15FAB */  jal   sinf
/* 0D7B5C 7F0A302C 4600C306 */   mov.s $f12, $f24
/* 0D7B60 7F0A3030 461C0282 */  mul.s $f10, $f0, $f28
/* 0D7B64 7F0A3034 02F4C023 */  subu  $t8, $s7, $s4
/* 0D7B68 7F0A3038 44988000 */  mtc1  $t8, $f16
/* 0D7B6C 7F0A303C 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0D7B70 7F0A3040 44813000 */  mtc1  $at, $f6
/* 0D7B74 7F0A3044 4600C306 */  mov.s $f12, $f24
/* 0D7B78 7F0A3048 46808520 */  cvt.s.w $f20, $f16
/* 0D7B7C 7F0A304C 461E5482 */  mul.s $f18, $f10, $f30
/* 0D7B80 7F0A3050 C7B00074 */  lwc1  $f16, 0x74($sp)
/* 0D7B84 7F0A3054 46149102 */  mul.s $f4, $f18, $f20
/* 0D7B88 7F0A3058 46062203 */  div.s $f8, $f4, $f6
/* 0D7B8C 7F0A305C 46104282 */  mul.s $f10, $f8, $f16
/* 0D7B90 7F0A3060 4600548D */  trunc.w.s $f18, $f10
/* 0D7B94 7F0A3064 44119000 */  mfc1  $s1, $f18
/* 0D7B98 7F0A3068 00000000 */  nop   
/* 0D7B9C 7F0A306C 00114400 */  sll   $t0, $s1, 0x10
/* 0D7BA0 7F0A3070 0FC15FA8 */  jal   cosf
/* 0D7BA4 7F0A3074 00088C03 */   sra   $s1, $t0, 0x10
/* 0D7BA8 7F0A3078 461C0102 */  mul.s $f4, $f0, $f28
/* 0D7BAC 7F0A307C 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0D7BB0 7F0A3080 44818000 */  mtc1  $at, $f16
/* 0D7BB4 7F0A3084 262A0001 */  addiu $t2, $s1, 1
/* 0D7BB8 7F0A3088 A60A0000 */  sh    $t2, ($s0)
/* 0D7BBC 7F0A308C A6000002 */  sh    $zero, 2($s0)
/* 0D7BC0 7F0A3090 A6000006 */  sh    $zero, 6($s0)
/* 0D7BC4 7F0A3094 461E2182 */  mul.s $f6, $f4, $f30
/* 0D7BC8 7F0A3098 A6000008 */  sh    $zero, 8($s0)
/* 0D7BCC 7F0A309C A600000A */  sh    $zero, 0xa($s0)
/* 0D7BD0 7F0A30A0 A213000C */  sb    $s3, 0xc($s0)
/* 0D7BD4 7F0A30A4 A213000D */  sb    $s3, 0xd($s0)
/* 0D7BD8 7F0A30A8 A213000E */  sb    $s3, 0xe($s0)
/* 0D7BDC 7F0A30AC 46143202 */  mul.s $f8, $f6, $f20
/* 0D7BE0 7F0A30B0 46104283 */  div.s $f10, $f8, $f16
/* 0D7BE4 7F0A30B4 4600548D */  trunc.w.s $f18, $f10
/* 0D7BE8 7F0A30B8 440E9000 */  mfc1  $t6, $f18
/* 0D7BEC 7F0A30BC 00000000 */  nop   
/* 0D7BF0 7F0A30C0 000E7823 */  negu  $t7, $t6
/* 0D7BF4 7F0A30C4 1AC00013 */  blez  $s6, .L7F0A3114
/* 0D7BF8 7F0A30C8 A60F0004 */   sh    $t7, 4($s0)
/* 0D7BFC 7F0A30CC 0FC15FA8 */  jal   cosf
/* 0D7C00 7F0A30D0 4600C306 */   mov.s $f12, $f24
/* 0D7C04 7F0A30D4 3C0142C0 */  li    $at, 0x42C00000 # 96.000000
/* 0D7C08 7F0A30D8 44811000 */  mtc1  $at, $f2
/* 0D7C0C 7F0A30DC 4600C306 */  mov.s $f12, $f24
/* 0D7C10 7F0A30E0 46020102 */  mul.s $f4, $f0, $f2
/* 0D7C14 7F0A30E4 46041181 */  sub.s $f6, $f2, $f4
/* 0D7C18 7F0A30E8 4600320D */  trunc.w.s $f8, $f6
/* 0D7C1C 7F0A30EC 44194000 */  mfc1  $t9, $f8
/* 0D7C20 7F0A30F0 0FC15FA8 */  jal   cosf
/* 0D7C24 7F0A30F4 A219000C */   sb    $t9, 0xc($s0)
/* 0D7C28 7F0A30F8 461A0402 */  mul.s $f16, $f0, $f26
/* 0D7C2C 7F0A30FC A213000E */  sb    $s3, 0xe($s0)
/* 0D7C30 7F0A3100 4610D281 */  sub.s $f10, $f26, $f16
/* 0D7C34 7F0A3104 4600548D */  trunc.w.s $f18, $f10
/* 0D7C38 7F0A3108 44099000 */  mfc1  $t1, $f18
/* 0D7C3C 7F0A310C 10000015 */  b     .L7F0A3164
/* 0D7C40 7F0A3110 A209000D */   sb    $t1, 0xd($s0)
.L7F0A3114:
/* 0D7C44 7F0A3114 06C30014 */  bgezl $s6, .L7F0A3168
/* 0D7C48 7F0A3118 2A41000A */   slti  $at, $s2, 0xa
/* 0D7C4C 7F0A311C 0FC15FA8 */  jal   cosf
/* 0D7C50 7F0A3120 4600C306 */   mov.s $f12, $f24
/* 0D7C54 7F0A3124 461A0102 */  mul.s $f4, $f0, $f26
/* 0D7C58 7F0A3128 4600C306 */  mov.s $f12, $f24
/* 0D7C5C 7F0A312C 4604D181 */  sub.s $f6, $f26, $f4
/* 0D7C60 7F0A3130 4600320D */  trunc.w.s $f8, $f6
/* 0D7C64 7F0A3134 440B4000 */  mfc1  $t3, $f8
/* 0D7C68 7F0A3138 0FC15FA8 */  jal   cosf
/* 0D7C6C 7F0A313C A20B000D */   sb    $t3, 0xd($s0)
/* 0D7C70 7F0A3140 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0D7C74 7F0A3144 44815000 */  mtc1  $at, $f10
/* 0D7C78 7F0A3148 44818000 */  mtc1  $at, $f16
/* 0D7C7C 7F0A314C 460A0482 */  mul.s $f18, $f0, $f10
/* 0D7C80 7F0A3150 46128101 */  sub.s $f4, $f16, $f18
/* 0D7C84 7F0A3154 4600218D */  trunc.w.s $f6, $f4
/* 0D7C88 7F0A3158 440D3000 */  mfc1  $t5, $f6
/* 0D7C8C 7F0A315C 00000000 */  nop   
/* 0D7C90 7F0A3160 A20D000E */  sb    $t5, 0xe($s0)
.L7F0A3164:
/* 0D7C94 7F0A3164 2A41000A */  slti  $at, $s2, 0xa
.L7F0A3168:
/* 0D7C98 7F0A3168 10200022 */  beqz  $at, .L7F0A31F4
/* 0D7C9C 7F0A316C 26940001 */   addiu $s4, $s4, 1
/* 0D7CA0 7F0A3170 4600B20D */  trunc.w.s $f8, $f22
/* 0D7CA4 7F0A3174 44024000 */  mfc1  $v0, $f8
/* 0D7CA8 7F0A3178 00000000 */  nop   
/* 0D7CAC 7F0A317C 00021840 */  sll   $v1, $v0, 1
/* 0D7CB0 7F0A3180 2463FFFF */  addiu $v1, $v1, -1
/* 0D7CB4 7F0A3184 0072082A */  slt   $at, $v1, $s2
/* 0D7CB8 7F0A3188 54200004 */  bnezl $at, .L7F0A319C
/* 0D7CBC 7F0A318C 4616B280 */   add.s $f10, $f22, $f22
/* 0D7CC0 7F0A3190 1000004D */  b     .L7F0A32C8
/* 0D7CC4 7F0A3194 A213000F */   sb    $s3, 0xf($s0)
/* 0D7CC8 7F0A3198 4616B280 */  add.s $f10, $f22, $f22
.L7F0A319C:
/* 0D7CCC 7F0A319C 4600540D */  trunc.w.s $f16, $f10
/* 0D7CD0 7F0A31A0 44188000 */  mfc1  $t8, $f16
/* 0D7CD4 7F0A31A4 00000000 */  nop   
/* 0D7CD8 7F0A31A8 0258082A */  slt   $at, $s2, $t8
/* 0D7CDC 7F0A31AC 1020000F */  beqz  $at, .L7F0A31EC
/* 0D7CE0 7F0A31B0 0072082A */   slt   $at, $v1, $s2
/* 0D7CE4 7F0A31B4 1020000D */  beqz  $at, .L7F0A31EC
/* 0D7CE8 7F0A31B8 00000000 */   nop   
/* 0D7CEC 7F0A31BC 44829000 */  mtc1  $v0, $f18
/* 0D7CF0 7F0A31C0 3C01434F */  li    $at, 0x434F0000 # 207.000000
/* 0D7CF4 7F0A31C4 44814000 */  mtc1  $at, $f8
/* 0D7CF8 7F0A31C8 46809120 */  cvt.s.w $f4, $f18
/* 0D7CFC 7F0A31CC 4604B181 */  sub.s $f6, $f22, $f4
/* 0D7D00 7F0A31D0 46083282 */  mul.s $f10, $f6, $f8
/* 0D7D04 7F0A31D4 4600540D */  trunc.w.s $f16, $f10
/* 0D7D08 7F0A31D8 44088000 */  mfc1  $t0, $f16
/* 0D7D0C 7F0A31DC 00000000 */  nop   
/* 0D7D10 7F0A31E0 25090030 */  addiu $t1, $t0, 0x30
/* 0D7D14 7F0A31E4 10000038 */  b     .L7F0A32C8
/* 0D7D18 7F0A31E8 A209000F */   sb    $t1, 0xf($s0)
.L7F0A31EC:
/* 0D7D1C 7F0A31EC 10000036 */  b     .L7F0A32C8
/* 0D7D20 7F0A31F0 A215000F */   sb    $s5, 0xf($s0)
.L7F0A31F4:
/* 0D7D24 7F0A31F4 2A41000A */  slti  $at, $s2, 0xa
/* 0D7D28 7F0A31F8 14200033 */  bnez  $at, .L7F0A32C8
/* 0D7D2C 7F0A31FC 3C0140A0 */   li    $at, 0x40A00000 # 5.000000
/* 0D7D30 7F0A3200 44819000 */  mtc1  $at, $f18
/* 0D7D34 7F0A3204 44924000 */  mtc1  $s2, $f8
/* 0D7D38 7F0A3208 3C014110 */  li    $at, 0x41100000 # 9.000000
/* 0D7D3C 7F0A320C 4612B001 */  sub.s $f0, $f22, $f18
/* 0D7D40 7F0A3210 44812000 */  mtc1  $at, $f4
/* 0D7D44 7F0A3214 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D7D48 7F0A3218 468042A0 */  cvt.s.w $f10, $f8
/* 0D7D4C 7F0A321C 461C0082 */  mul.s $f2, $f0, $f28
/* 0D7D50 7F0A3220 46022180 */  add.s $f6, $f4, $f2
/* 0D7D54 7F0A3224 4606503E */  c.le.s $f10, $f6
/* 0D7D58 7F0A3228 00000000 */  nop   
/* 0D7D5C 7F0A322C 45020004 */  bc1fl .L7F0A3240
/* 0D7D60 7F0A3230 44818000 */   mtc1  $at, $f16
/* 0D7D64 7F0A3234 10000024 */  b     .L7F0A32C8
/* 0D7D68 7F0A3238 A213000F */   sb    $s3, 0xf($s0)
/* 0D7D6C 7F0A323C 44818000 */  mtc1  $at, $f16
.L7F0A3240:
/* 0D7D70 7F0A3240 00000000 */  nop   
/* 0D7D74 7F0A3244 46101480 */  add.s $f18, $f2, $f16
/* 0D7D78 7F0A3248 4600910D */  trunc.w.s $f4, $f18
/* 0D7D7C 7F0A324C 440B2000 */  mfc1  $t3, $f4
/* 0D7D80 7F0A3250 00000000 */  nop   
/* 0D7D84 7F0A3254 256C0009 */  addiu $t4, $t3, 9
/* 0D7D88 7F0A3258 0192082A */  slt   $at, $t4, $s2
/* 0D7D8C 7F0A325C 5420001A */  bnezl $at, .L7F0A32C8
/* 0D7D90 7F0A3260 A215000F */   sb    $s5, 0xf($s0)
/* 0D7D94 7F0A3264 4600020D */  trunc.w.s $f8, $f0
/* 0D7D98 7F0A3268 440E4000 */  mfc1  $t6, $f8
/* 0D7D9C 7F0A326C 00000000 */  nop   
/* 0D7DA0 7F0A3270 000E7840 */  sll   $t7, $t6, 1
/* 0D7DA4 7F0A3274 25F80008 */  addiu $t8, $t7, 8
/* 0D7DA8 7F0A3278 0312082A */  slt   $at, $t8, $s2
/* 0D7DAC 7F0A327C 50200012 */  beql  $at, $zero, .L7F0A32C8
/* 0D7DB0 7F0A3280 A215000F */   sb    $s5, 0xf($s0)
/* 0D7DB4 7F0A3284 4600B18D */  trunc.w.s $f6, $f22
/* 0D7DB8 7F0A3288 3C01434F */  li    $at, 0x434F0000 # 207.000000
/* 0D7DBC 7F0A328C 44812000 */  mtc1  $at, $f4
/* 0D7DC0 7F0A3290 44083000 */  mfc1  $t0, $f6
/* 0D7DC4 7F0A3294 00000000 */  nop   
/* 0D7DC8 7F0A3298 44885000 */  mtc1  $t0, $f10
/* 0D7DCC 7F0A329C 00000000 */  nop   
/* 0D7DD0 7F0A32A0 46805420 */  cvt.s.w $f16, $f10
/* 0D7DD4 7F0A32A4 4610B481 */  sub.s $f18, $f22, $f16
/* 0D7DD8 7F0A32A8 46049202 */  mul.s $f8, $f18, $f4
/* 0D7DDC 7F0A32AC 4600418D */  trunc.w.s $f6, $f8
/* 0D7DE0 7F0A32B0 440A3000 */  mfc1  $t2, $f6
/* 0D7DE4 7F0A32B4 00000000 */  nop   
/* 0D7DE8 7F0A32B8 254B0030 */  addiu $t3, $t2, 0x30
/* 0D7DEC 7F0A32BC 10000002 */  b     .L7F0A32C8
/* 0D7DF0 7F0A32C0 A20B000F */   sb    $t3, 0xf($s0)
/* 0D7DF4 7F0A32C4 A215000F */  sb    $s5, 0xf($s0)
.L7F0A32C8:
/* 0D7DF8 7F0A32C8 169EFF57 */  bne   $s4, $fp, .L7F0A3028
/* 0D7DFC 7F0A32CC 26100010 */   addiu $s0, $s0, 0x10
/* 0D7E00 7F0A32D0 8FAC0080 */  lw    $t4, 0x80($sp)
/* 0D7E04 7F0A32D4 26520001 */  addiu $s2, $s2, 1
/* 0D7E08 7F0A32D8 24010017 */  li    $at, 23
/* 0D7E0C 7F0A32DC 258D0005 */  addiu $t5, $t4, 5
/* 0D7E10 7F0A32E0 1641FF3A */  bne   $s2, $at, .L7F0A2FCC
/* 0D7E14 7F0A32E4 AFAD0080 */   sw    $t5, 0x80($sp)
/* 0D7E18 7F0A32E8 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0D7E1C 7F0A32EC D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D7E20 7F0A32F0 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D7E24 7F0A32F4 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D7E28 7F0A32F8 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0D7E2C 7F0A32FC D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0D7E30 7F0A3300 D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0D7E34 7F0A3304 8FB00048 */  lw    $s0, 0x48($sp)
/* 0D7E38 7F0A3308 8FB1004C */  lw    $s1, 0x4c($sp)
/* 0D7E3C 7F0A330C 8FB20050 */  lw    $s2, 0x50($sp)
/* 0D7E40 7F0A3310 8FB30054 */  lw    $s3, 0x54($sp)
/* 0D7E44 7F0A3314 8FB40058 */  lw    $s4, 0x58($sp)
/* 0D7E48 7F0A3318 8FB5005C */  lw    $s5, 0x5c($sp)
/* 0D7E4C 7F0A331C 8FB60060 */  lw    $s6, 0x60($sp)
/* 0D7E50 7F0A3320 8FB70064 */  lw    $s7, 0x64($sp)
/* 0D7E54 7F0A3324 8FBE0068 */  lw    $fp, 0x68($sp)
/* 0D7E58 7F0A3328 03E00008 */  jr    $ra
/* 0D7E5C 7F0A332C 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8004CE10
.word 0x4061d000
glabel D_8004CE14
.word 0x00000000 /*0.0*/
glabel D_8004CE18
.word 0x40490fdb
glabel D_8004CE1C
.word 0x40490fdb
glabel D_8004CE20
.word 0x40c90fdb

.text
glabel sub_GAME_7F0A2F30
/* 0D4E60 7F0A2470 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0D4E64 7F0A2474 AFB60060 */  sw    $s6, 0x60($sp)
/* 0D4E68 7F0A2478 00C0B025 */  move  $s6, $a2
/* 0D4E6C 7F0A247C 44963000 */  mtc1  $s6, $f6
/* 0D4E70 7F0A2480 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 0D4E74 7F0A2484 44812000 */  mtc1  $at, $f4
/* 0D4E78 7F0A2488 46803220 */  cvt.s.w $f8, $f6
/* 0D4E7C 7F0A248C F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0D4E80 7F0A2490 3C014302 */  li    $at, 0x43020000 # 130.000000
/* 0D4E84 7F0A2494 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0D4E88 7F0A2498 4481F000 */  mtc1  $at, $f30
/* 0D4E8C 7F0A249C 4487B000 */  mtc1  $a3, $f22
/* 0D4E90 7F0A24A0 F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0D4E94 7F0A24A4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0D4E98 7F0A24A8 4481E000 */  mtc1  $at, $f28
/* 0D4E9C 7F0A24AC F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0D4EA0 7F0A24B0 3C0142FE */  li    $at, 0x42FE0000 # 127.000000
/* 0D4EA4 7F0A24B4 AFBE0068 */  sw    $fp, 0x68($sp)
/* 0D4EA8 7F0A24B8 AFB70064 */  sw    $s7, 0x64($sp)
/* 0D4EAC 7F0A24BC AFB5005C */  sw    $s5, 0x5c($sp)
/* 0D4EB0 7F0A24C0 AFB30054 */  sw    $s3, 0x54($sp)
/* 0D4EB4 7F0A24C4 AFB20050 */  sw    $s2, 0x50($sp)
/* 0D4EB8 7F0A24C8 AFB00048 */  sw    $s0, 0x48($sp)
/* 0D4EBC 7F0A24CC 4481D000 */  mtc1  $at, $f26
/* 0D4EC0 7F0A24D0 4604B582 */  mul.s $f22, $f22, $f4
/* 0D4EC4 7F0A24D4 00808025 */  move  $s0, $a0
/* 0D4EC8 7F0A24D8 AFBF006C */  sw    $ra, 0x6c($sp)
/* 0D4ECC 7F0A24DC AFB40058 */  sw    $s4, 0x58($sp)
/* 0D4ED0 7F0A24E0 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0D4ED4 7F0A24E4 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0D4ED8 7F0A24E8 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D4EDC 7F0A24EC AFA5009C */  sw    $a1, 0x9c($sp)
/* 0D4EE0 7F0A24F0 00009025 */  move  $s2, $zero
/* 0D4EE4 7F0A24F4 241300FF */  li    $s3, 255
/* 0D4EE8 7F0A24F8 24150030 */  li    $s5, 48
/* 0D4EEC 7F0A24FC 24170006 */  li    $s7, 6
/* 0D4EF0 7F0A2500 241E0002 */  li    $fp, 2
/* 0D4EF4 7F0A2504 E7A80074 */  swc1  $f8, 0x74($sp)
/* 0D4EF8 7F0A2508 AFA00080 */  sw    $zero, 0x80($sp)
.L7F0A250C:
/* 0D4EFC 7F0A250C 8FA20080 */  lw    $v0, 0x80($sp)
/* 0D4F00 7F0A2510 3C018005 */  lui    $at, %hi(D_8004CE10)
/* 0D4F04 7F0A2514 D42ACE10 */  ldc1  $f10, %lo(D_8004CE10)($at)
/* 0D4F08 7F0A2518 44828000 */  mtc1  $v0, $f16
/* 0D4F0C 7F0A251C 3C018005 */  lui    $at, %hi(D_8004CE18)
/* 0D4F10 7F0A2520 0000A025 */  move  $s4, $zero
/* 0D4F14 7F0A2524 468084A1 */  cvt.d.w $f18, $f16
/* 0D4F18 7F0A2528 46325101 */  sub.d $f4, $f10, $f18
/* 0D4F1C 7F0A252C C42ACE18 */  lwc1  $f10, %lo(D_8004CE18)($at)
/* 0D4F20 7F0A2530 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0D4F24 7F0A2534 4620218D */  trunc.w.d $f6, $f4
/* 0D4F28 7F0A2538 44812000 */  mtc1  $at, $f4
/* 0D4F2C 7F0A253C 3C0143B4 */  li    $at, 0x43B40000 # 360.000000
/* 0D4F30 7F0A2540 440F3000 */  mfc1  $t7, $f6
/* 0D4F34 7F0A2544 00000000 */  nop   
/* 0D4F38 7F0A2548 448F4000 */  mtc1  $t7, $f8
/* 0D4F3C 7F0A254C 00000000 */  nop   
/* 0D4F40 7F0A2550 46804420 */  cvt.s.w $f16, $f8
/* 0D4F44 7F0A2554 44814000 */  mtc1  $at, $f8
/* 0D4F48 7F0A2558 460A8482 */  mul.s $f18, $f16, $f10
/* 0D4F4C 7F0A255C 00000000 */  nop   
/* 0D4F50 7F0A2560 46049182 */  mul.s $f6, $f18, $f4
/* 0D4F54 7F0A2564 46083603 */  div.s $f24, $f6, $f8
.L7F0A2568:
/* 0D4F58 7F0A2568 0FC1606B */  jal   sinf
/* 0D4F5C 7F0A256C 4600C306 */   mov.s $f12, $f24
/* 0D4F60 7F0A2570 461C0282 */  mul.s $f10, $f0, $f28
/* 0D4F64 7F0A2574 02F4C023 */  subu  $t8, $s7, $s4
/* 0D4F68 7F0A2578 44988000 */  mtc1  $t8, $f16
/* 0D4F6C 7F0A257C 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0D4F70 7F0A2580 44813000 */  mtc1  $at, $f6
/* 0D4F74 7F0A2584 4600C306 */  mov.s $f12, $f24
/* 0D4F78 7F0A2588 46808520 */  cvt.s.w $f20, $f16
/* 0D4F7C 7F0A258C 461E5482 */  mul.s $f18, $f10, $f30
/* 0D4F80 7F0A2590 C7B00074 */  lwc1  $f16, 0x74($sp)
/* 0D4F84 7F0A2594 46149102 */  mul.s $f4, $f18, $f20
/* 0D4F88 7F0A2598 46062203 */  div.s $f8, $f4, $f6
/* 0D4F8C 7F0A259C 46104282 */  mul.s $f10, $f8, $f16
/* 0D4F90 7F0A25A0 4600548D */  trunc.w.s $f18, $f10
/* 0D4F94 7F0A25A4 44119000 */  mfc1  $s1, $f18
/* 0D4F98 7F0A25A8 00000000 */  nop   
/* 0D4F9C 7F0A25AC 00114400 */  sll   $t0, $s1, 0x10
/* 0D4FA0 7F0A25B0 0FC16068 */  jal   cosf
/* 0D4FA4 7F0A25B4 00088C03 */   sra   $s1, $t0, 0x10
/* 0D4FA8 7F0A25B8 461C0102 */  mul.s $f4, $f0, $f28
/* 0D4FAC 7F0A25BC 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0D4FB0 7F0A25C0 44818000 */  mtc1  $at, $f16
/* 0D4FB4 7F0A25C4 262A0001 */  addiu $t2, $s1, 1
/* 0D4FB8 7F0A25C8 A60A0000 */  sh    $t2, ($s0)
/* 0D4FBC 7F0A25CC A6000002 */  sh    $zero, 2($s0)
/* 0D4FC0 7F0A25D0 A6000006 */  sh    $zero, 6($s0)
/* 0D4FC4 7F0A25D4 461E2182 */  mul.s $f6, $f4, $f30
/* 0D4FC8 7F0A25D8 A6000008 */  sh    $zero, 8($s0)
/* 0D4FCC 7F0A25DC A600000A */  sh    $zero, 0xa($s0)
/* 0D4FD0 7F0A25E0 A213000C */  sb    $s3, 0xc($s0)
/* 0D4FD4 7F0A25E4 A213000D */  sb    $s3, 0xd($s0)
/* 0D4FD8 7F0A25E8 A213000E */  sb    $s3, 0xe($s0)
/* 0D4FDC 7F0A25EC 46143202 */  mul.s $f8, $f6, $f20
/* 0D4FE0 7F0A25F0 46104283 */  div.s $f10, $f8, $f16
/* 0D4FE4 7F0A25F4 4600548D */  trunc.w.s $f18, $f10
/* 0D4FE8 7F0A25F8 440E9000 */  mfc1  $t6, $f18
/* 0D4FEC 7F0A25FC 00000000 */  nop   
/* 0D4FF0 7F0A2600 000E7823 */  negu  $t7, $t6
/* 0D4FF4 7F0A2604 1AC00013 */  blez  $s6, .L7F0A2654
/* 0D4FF8 7F0A2608 A60F0004 */   sh    $t7, 4($s0)
/* 0D4FFC 7F0A260C 0FC16068 */  jal   cosf
/* 0D5000 7F0A2610 4600C306 */   mov.s $f12, $f24
/* 0D5004 7F0A2614 3C0142C0 */  li    $at, 0x42C00000 # 96.000000
/* 0D5008 7F0A2618 44811000 */  mtc1  $at, $f2
/* 0D500C 7F0A261C 4600C306 */  mov.s $f12, $f24
/* 0D5010 7F0A2620 46020102 */  mul.s $f4, $f0, $f2
/* 0D5014 7F0A2624 46041181 */  sub.s $f6, $f2, $f4
/* 0D5018 7F0A2628 4600320D */  trunc.w.s $f8, $f6
/* 0D501C 7F0A262C 44194000 */  mfc1  $t9, $f8
/* 0D5020 7F0A2630 0FC16068 */  jal   cosf
/* 0D5024 7F0A2634 A219000C */   sb    $t9, 0xc($s0)
/* 0D5028 7F0A2638 461A0402 */  mul.s $f16, $f0, $f26
/* 0D502C 7F0A263C A213000E */  sb    $s3, 0xe($s0)
/* 0D5030 7F0A2640 4610D281 */  sub.s $f10, $f26, $f16
/* 0D5034 7F0A2644 4600548D */  trunc.w.s $f18, $f10
/* 0D5038 7F0A2648 44099000 */  mfc1  $t1, $f18
/* 0D503C 7F0A264C 10000015 */  b     .L7F0A26A4
/* 0D5040 7F0A2650 A209000D */   sb    $t1, 0xd($s0)
.L7F0A2654:
/* 0D5044 7F0A2654 06C30014 */  bgezl $s6, .L7F0A26A8
/* 0D5048 7F0A2658 2A41000A */   slti  $at, $s2, 0xa
/* 0D504C 7F0A265C 0FC16068 */  jal   cosf
/* 0D5050 7F0A2660 4600C306 */   mov.s $f12, $f24
/* 0D5054 7F0A2664 461A0102 */  mul.s $f4, $f0, $f26
/* 0D5058 7F0A2668 4600C306 */  mov.s $f12, $f24
/* 0D505C 7F0A266C 4604D181 */  sub.s $f6, $f26, $f4
/* 0D5060 7F0A2670 4600320D */  trunc.w.s $f8, $f6
/* 0D5064 7F0A2674 440B4000 */  mfc1  $t3, $f8
/* 0D5068 7F0A2678 0FC16068 */  jal   cosf
/* 0D506C 7F0A267C A20B000D */   sb    $t3, 0xd($s0)
/* 0D5070 7F0A2680 3C014200 */  li    $at, 0x42000000 # 32.000000
/* 0D5074 7F0A2684 44815000 */  mtc1  $at, $f10
/* 0D5078 7F0A2688 44818000 */  mtc1  $at, $f16
/* 0D507C 7F0A268C 460A0482 */  mul.s $f18, $f0, $f10
/* 0D5080 7F0A2690 46128101 */  sub.s $f4, $f16, $f18
/* 0D5084 7F0A2694 4600218D */  trunc.w.s $f6, $f4
/* 0D5088 7F0A2698 440D3000 */  mfc1  $t5, $f6
/* 0D508C 7F0A269C 00000000 */  nop   
/* 0D5090 7F0A26A0 A20D000E */  sb    $t5, 0xe($s0)
.L7F0A26A4:
/* 0D5094 7F0A26A4 2A41000A */  slti  $at, $s2, 0xa
.L7F0A26A8:
/* 0D5098 7F0A26A8 10200022 */  beqz  $at, .L7F0A2734
/* 0D509C 7F0A26AC 26940001 */   addiu $s4, $s4, 1
/* 0D50A0 7F0A26B0 4600B20D */  trunc.w.s $f8, $f22
/* 0D50A4 7F0A26B4 44024000 */  mfc1  $v0, $f8
/* 0D50A8 7F0A26B8 00000000 */  nop   
/* 0D50AC 7F0A26BC 00021840 */  sll   $v1, $v0, 1
/* 0D50B0 7F0A26C0 2463FFFF */  addiu $v1, $v1, -1
/* 0D50B4 7F0A26C4 0072082A */  slt   $at, $v1, $s2
/* 0D50B8 7F0A26C8 54200004 */  bnezl $at, .L7F0A26DC
/* 0D50BC 7F0A26CC 4616B280 */   add.s $f10, $f22, $f22
/* 0D50C0 7F0A26D0 1000004D */  b     .L7F0A2808
/* 0D50C4 7F0A26D4 A213000F */   sb    $s3, 0xf($s0)
/* 0D50C8 7F0A26D8 4616B280 */  add.s $f10, $f22, $f22
.L7F0A26DC:
/* 0D50CC 7F0A26DC 4600540D */  trunc.w.s $f16, $f10
/* 0D50D0 7F0A26E0 44188000 */  mfc1  $t8, $f16
/* 0D50D4 7F0A26E4 00000000 */  nop   
/* 0D50D8 7F0A26E8 0258082A */  slt   $at, $s2, $t8
/* 0D50DC 7F0A26EC 1020000F */  beqz  $at, .L7F0A272C
/* 0D50E0 7F0A26F0 0072082A */   slt   $at, $v1, $s2
/* 0D50E4 7F0A26F4 1020000D */  beqz  $at, .L7F0A272C
/* 0D50E8 7F0A26F8 00000000 */   nop   
/* 0D50EC 7F0A26FC 44829000 */  mtc1  $v0, $f18
/* 0D50F0 7F0A2700 3C01434F */  li    $at, 0x434F0000 # 207.000000
/* 0D50F4 7F0A2704 44814000 */  mtc1  $at, $f8
/* 0D50F8 7F0A2708 46809120 */  cvt.s.w $f4, $f18
/* 0D50FC 7F0A270C 4604B181 */  sub.s $f6, $f22, $f4
/* 0D5100 7F0A2710 46083282 */  mul.s $f10, $f6, $f8
/* 0D5104 7F0A2714 4600540D */  trunc.w.s $f16, $f10
/* 0D5108 7F0A2718 44088000 */  mfc1  $t0, $f16
/* 0D510C 7F0A271C 00000000 */  nop   
/* 0D5110 7F0A2720 25090030 */  addiu $t1, $t0, 0x30
/* 0D5114 7F0A2724 10000038 */  b     .L7F0A2808
/* 0D5118 7F0A2728 A209000F */   sb    $t1, 0xf($s0)
.L7F0A272C:
/* 0D511C 7F0A272C 10000036 */  b     .L7F0A2808
/* 0D5120 7F0A2730 A215000F */   sb    $s5, 0xf($s0)
.L7F0A2734:
/* 0D5124 7F0A2734 2A41000A */  slti  $at, $s2, 0xa
/* 0D5128 7F0A2738 14200033 */  bnez  $at, .L7F0A2808
/* 0D512C 7F0A273C 3C0140A0 */   li    $at, 0x40A00000 # 5.000000
/* 0D5130 7F0A2740 44819000 */  mtc1  $at, $f18
/* 0D5134 7F0A2744 44924000 */  mtc1  $s2, $f8
/* 0D5138 7F0A2748 3C014110 */  li    $at, 0x41100000 # 9.000000
/* 0D513C 7F0A274C 4612B001 */  sub.s $f0, $f22, $f18
/* 0D5140 7F0A2750 44812000 */  mtc1  $at, $f4
/* 0D5144 7F0A2754 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D5148 7F0A2758 468042A0 */  cvt.s.w $f10, $f8
/* 0D514C 7F0A275C 461C0082 */  mul.s $f2, $f0, $f28
/* 0D5150 7F0A2760 46022180 */  add.s $f6, $f4, $f2
/* 0D5154 7F0A2764 4606503E */  c.le.s $f10, $f6
/* 0D5158 7F0A2768 00000000 */  nop   
/* 0D515C 7F0A276C 45020004 */  bc1fl .L7F0A2780
/* 0D5160 7F0A2770 44818000 */   mtc1  $at, $f16
/* 0D5164 7F0A2774 10000024 */  b     .L7F0A2808
/* 0D5168 7F0A2778 A213000F */   sb    $s3, 0xf($s0)
/* 0D516C 7F0A277C 44818000 */  mtc1  $at, $f16
.L7F0A2780:
/* 0D5170 7F0A2780 00000000 */  nop   
/* 0D5174 7F0A2784 46101480 */  add.s $f18, $f2, $f16
/* 0D5178 7F0A2788 4600910D */  trunc.w.s $f4, $f18
/* 0D517C 7F0A278C 440B2000 */  mfc1  $t3, $f4
/* 0D5180 7F0A2790 00000000 */  nop   
/* 0D5184 7F0A2794 256C0009 */  addiu $t4, $t3, 9
/* 0D5188 7F0A2798 0192082A */  slt   $at, $t4, $s2
/* 0D518C 7F0A279C 5420001A */  bnezl $at, .L7F0A2808
/* 0D5190 7F0A27A0 A215000F */   sb    $s5, 0xf($s0)
/* 0D5194 7F0A27A4 4600020D */  trunc.w.s $f8, $f0
/* 0D5198 7F0A27A8 440E4000 */  mfc1  $t6, $f8
/* 0D519C 7F0A27AC 00000000 */  nop   
/* 0D51A0 7F0A27B0 000E7840 */  sll   $t7, $t6, 1
/* 0D51A4 7F0A27B4 25F80008 */  addiu $t8, $t7, 8
/* 0D51A8 7F0A27B8 0312082A */  slt   $at, $t8, $s2
/* 0D51AC 7F0A27BC 50200012 */  beql  $at, $zero, .L7F0A2808
/* 0D51B0 7F0A27C0 A215000F */   sb    $s5, 0xf($s0)
/* 0D51B4 7F0A27C4 4600B18D */  trunc.w.s $f6, $f22
/* 0D51B8 7F0A27C8 3C01434F */  li    $at, 0x434F0000 # 207.000000
/* 0D51BC 7F0A27CC 44812000 */  mtc1  $at, $f4
/* 0D51C0 7F0A27D0 44083000 */  mfc1  $t0, $f6
/* 0D51C4 7F0A27D4 00000000 */  nop   
/* 0D51C8 7F0A27D8 44885000 */  mtc1  $t0, $f10
/* 0D51CC 7F0A27DC 00000000 */  nop   
/* 0D51D0 7F0A27E0 46805420 */  cvt.s.w $f16, $f10
/* 0D51D4 7F0A27E4 4610B481 */  sub.s $f18, $f22, $f16
/* 0D51D8 7F0A27E8 46049202 */  mul.s $f8, $f18, $f4
/* 0D51DC 7F0A27EC 4600418D */  trunc.w.s $f6, $f8
/* 0D51E0 7F0A27F0 440A3000 */  mfc1  $t2, $f6
/* 0D51E4 7F0A27F4 00000000 */  nop   
/* 0D51E8 7F0A27F8 254B0030 */  addiu $t3, $t2, 0x30
/* 0D51EC 7F0A27FC 10000002 */  b     .L7F0A2808
/* 0D51F0 7F0A2800 A20B000F */   sb    $t3, 0xf($s0)
/* 0D51F4 7F0A2804 A215000F */  sb    $s5, 0xf($s0)
.L7F0A2808:
/* 0D51F8 7F0A2808 169EFF57 */  bne   $s4, $fp, .L7F0A2568
/* 0D51FC 7F0A280C 26100010 */   addiu $s0, $s0, 0x10
/* 0D5200 7F0A2810 8FAC0080 */  lw    $t4, 0x80($sp)
/* 0D5204 7F0A2814 26520001 */  addiu $s2, $s2, 1
/* 0D5208 7F0A2818 24010017 */  li    $at, 23
/* 0D520C 7F0A281C 258D0005 */  addiu $t5, $t4, 5
/* 0D5210 7F0A2820 1641FF3A */  bne   $s2, $at, .L7F0A250C
/* 0D5214 7F0A2824 AFAD0080 */   sw    $t5, 0x80($sp)
/* 0D5218 7F0A2828 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0D521C 7F0A282C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D5220 7F0A2830 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0D5224 7F0A2834 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0D5228 7F0A2838 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0D522C 7F0A283C D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0D5230 7F0A2840 D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0D5234 7F0A2844 8FB00048 */  lw    $s0, 0x48($sp)
/* 0D5238 7F0A2848 8FB1004C */  lw    $s1, 0x4c($sp)
/* 0D523C 7F0A284C 8FB20050 */  lw    $s2, 0x50($sp)
/* 0D5240 7F0A2850 8FB30054 */  lw    $s3, 0x54($sp)
/* 0D5244 7F0A2854 8FB40058 */  lw    $s4, 0x58($sp)
/* 0D5248 7F0A2858 8FB5005C */  lw    $s5, 0x5c($sp)
/* 0D524C 7F0A285C 8FB60060 */  lw    $s6, 0x60($sp)
/* 0D5250 7F0A2860 8FB70064 */  lw    $s7, 0x64($sp)
/* 0D5254 7F0A2864 8FBE0068 */  lw    $fp, 0x68($sp)
/* 0D5258 7F0A2868 03E00008 */  jr    $ra
/* 0D525C 7F0A286C 27BD0098 */   addiu $sp, $sp, 0x98
)
#endif
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A3330(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A3330
/* 0D7E60 7F0A3330 00803825 */  move  $a3, $a0
/* 0D7E64 7F0A3334 00001025 */  move  $v0, $zero
/* 0D7E68 7F0A3338 04C10003 */  bgez  $a2, .L7F0A3348
/* 0D7E6C 7F0A333C 00061843 */   sra   $v1, $a2, 1
/* 0D7E70 7F0A3340 24C10001 */  addiu $at, $a2, 1
/* 0D7E74 7F0A3344 00011843 */  sra   $v1, $at, 1
.L7F0A3348:
/* 0D7E78 7F0A3348 2463FFFE */  addiu $v1, $v1, -2
/* 0D7E7C 7F0A334C 04600026 */  bltz  $v1, .L7F0A33E8
/* 0D7E80 7F0A3350 3C0BB800 */   lui   $t3, 0xb800
/* 0D7E84 7F0A3354 3C08B100 */  lui   $t0, (0xB1000032 >> 16) # lui $t0, 0xb100
/* 0D7E88 7F0A3358 3C060430 */  lui   $a2, (0x04300040 >> 16) # lui $a2, 0x430
/* 0D7E8C 7F0A335C 34C60040 */  ori   $a2, (0x04300040 & 0xFFFF) # ori $a2, $a2, 0x40
/* 0D7E90 7F0A3360 35080032 */  ori   $t0, (0xB1000032 & 0xFFFF) # ori $t0, $t0, 0x32
/* 0D7E94 7F0A3364 24092110 */  li    $t1, 8464
.L7F0A3368:
/* 0D7E98 7F0A3368 00E02025 */  move  $a0, $a3
/* 0D7E9C 7F0A336C 28410009 */  slti  $at, $v0, 9
/* 0D7EA0 7F0A3370 AC860000 */  sw    $a2, ($a0)
/* 0D7EA4 7F0A3374 AC850004 */  sw    $a1, 4($a0)
/* 0D7EA8 7F0A3378 1420000D */  bnez  $at, .L7F0A33B0
/* 0D7EAC 7F0A337C 24E70008 */   addiu $a3, $a3, 8
/* 0D7EB0 7F0A3380 244E0003 */  addiu $t6, $v0, 3
/* 0D7EB4 7F0A3384 05C10004 */  bgez  $t6, .L7F0A3398
/* 0D7EB8 7F0A3388 31CF0003 */   andi  $t7, $t6, 3
/* 0D7EBC 7F0A338C 11E00002 */  beqz  $t7, .L7F0A3398
/* 0D7EC0 7F0A3390 00000000 */   nop   
/* 0D7EC4 7F0A3394 25EFFFFC */  addiu $t7, $t7, -4
.L7F0A3398:
/* 0D7EC8 7F0A3398 11E0000D */  beqz  $t7, .L7F0A33D0
/* 0D7ECC 7F0A339C 00E02025 */   move  $a0, $a3
/* 0D7ED0 7F0A33A0 24E70008 */  addiu $a3, $a3, 8
/* 0D7ED4 7F0A33A4 AC880000 */  sw    $t0, ($a0)
/* 0D7ED8 7F0A33A8 10000009 */  b     .L7F0A33D0
/* 0D7EDC 7F0A33AC AC890004 */   sw    $t1, 4($a0)
.L7F0A33B0:
/* 0D7EE0 7F0A33B0 28410009 */  slti  $at, $v0, 9
/* 0D7EE4 7F0A33B4 10200006 */  beqz  $at, .L7F0A33D0
/* 0D7EE8 7F0A33B8 30580001 */   andi  $t8, $v0, 1
/* 0D7EEC 7F0A33BC 17000004 */  bnez  $t8, .L7F0A33D0
/* 0D7EF0 7F0A33C0 00E02025 */   move  $a0, $a3
/* 0D7EF4 7F0A33C4 24E70008 */  addiu $a3, $a3, 8
/* 0D7EF8 7F0A33C8 AC880000 */  sw    $t0, ($a0)
/* 0D7EFC 7F0A33CC AC890004 */  sw    $t1, 4($a0)
.L7F0A33D0:
/* 0D7F00 7F0A33D0 24420001 */  addiu $v0, $v0, 1
/* 0D7F04 7F0A33D4 0002CE00 */  sll   $t9, $v0, 0x18
/* 0D7F08 7F0A33D8 00191603 */  sra   $v0, $t9, 0x18
/* 0D7F0C 7F0A33DC 0062082A */  slt   $at, $v1, $v0
/* 0D7F10 7F0A33E0 1020FFE1 */  beqz  $at, .L7F0A3368
/* 0D7F14 7F0A33E4 24A50020 */   addiu $a1, $a1, 0x20
.L7F0A33E8:
/* 0D7F18 7F0A33E8 24E20008 */  addiu $v0, $a3, 8
/* 0D7F1C 7F0A33EC ACEB0000 */  sw    $t3, ($a3)
/* 0D7F20 7F0A33F0 03E00008 */  jr    $ra
/* 0D7F24 7F0A33F4 ACE00004 */   sw    $zero, 4($a3)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A33F8(void) {

}
#else
#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8005774C
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F0A33F8
/* 0D7F28 7F0A33F8 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0D7F2C 7F0A33FC F7BE0038 */  sdc1  $f30, 0x38($sp)
/* 0D7F30 7F0A3400 4486F000 */  mtc1  $a2, $f30
/* 0D7F34 7F0A3404 AFB6005C */  sw    $s6, 0x5c($sp)
/* 0D7F38 7F0A3408 AFB00044 */  sw    $s0, 0x44($sp)
/* 0D7F3C 7F0A340C 00808025 */  move  $s0, $a0
/* 0D7F40 7F0A3410 00A0B025 */  move  $s6, $a1
/* 0D7F44 7F0A3414 AFBF0064 */  sw    $ra, 0x64($sp)
/* 0D7F48 7F0A3418 AFB70060 */  sw    $s7, 0x60($sp)
/* 0D7F4C 7F0A341C AFB50058 */  sw    $s5, 0x58($sp)
/* 0D7F50 7F0A3420 AFB40054 */  sw    $s4, 0x54($sp)
/* 0D7F54 7F0A3424 AFB30050 */  sw    $s3, 0x50($sp)
/* 0D7F58 7F0A3428 AFB2004C */  sw    $s2, 0x4c($sp)
/* 0D7F5C 7F0A342C AFB10048 */  sw    $s1, 0x48($sp)
/* 0D7F60 7F0A3430 F7BC0030 */  sdc1  $f28, 0x30($sp)
/* 0D7F64 7F0A3434 F7BA0028 */  sdc1  $f26, 0x28($sp)
/* 0D7F68 7F0A3438 F7B80020 */  sdc1  $f24, 0x20($sp)
/* 0D7F6C 7F0A343C F7B60018 */  sdc1  $f22, 0x18($sp)
/* 0D7F70 7F0A3440 10E0000F */  beqz  $a3, .L7F0A3480
/* 0D7F74 7F0A3444 F7B40010 */   sdc1  $f20, 0x10($sp)
/* 0D7F78 7F0A3448 241500B0 */  li    $s5, 176
/* 0D7F7C 7F0A344C 240E0001 */  li    $t6, 1
/* 0D7F80 7F0A3450 240F002C */  li    $t7, 44
/* 0D7F84 7F0A3454 A48E0000 */  sh    $t6, ($a0)
/* 0D7F88 7F0A3458 A4800002 */  sh    $zero, 2($a0)
/* 0D7F8C 7F0A345C A4800004 */  sh    $zero, 4($a0)
/* 0D7F90 7F0A3460 A4800006 */  sh    $zero, 6($a0)
/* 0D7F94 7F0A3464 A4800008 */  sh    $zero, 8($a0)
/* 0D7F98 7F0A3468 A480000A */  sh    $zero, 0xa($a0)
/* 0D7F9C 7F0A346C A080000C */  sb    $zero, 0xc($a0)
/* 0D7FA0 7F0A3470 A08F000D */  sb    $t7, 0xd($a0)
/* 0D7FA4 7F0A3474 A080000E */  sb    $zero, 0xe($a0)
/* 0D7FA8 7F0A3478 A095000F */  sb    $s5, 0xf($a0)
/* 0D7FAC 7F0A347C 24900010 */  addiu $s0, $a0, 0x10
.L7F0A3480:
/* 0D7FB0 7F0A3480 26D7FFF9 */  addiu $s7, $s6, -7
/* 0D7FB4 7F0A3484 2AE10007 */  slti  $at, $s7, 7
/* 0D7FB8 7F0A3488 241500B0 */  li    $s5, 176
/* 0D7FBC 7F0A348C 14200129 */  bnez  $at, .L7F0A3934
/* 0D7FC0 7F0A3490 24110007 */   li    $s1, 7
/* 0D7FC4 7F0A3494 44962000 */  mtc1  $s6, $f4
/* 0D7FC8 7F0A3498 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0D7FCC 7F0A349C 4481E000 */  mtc1  $at, $f28
/* 0D7FD0 7F0A34A0 46802020 */  cvt.s.w $f0, $f4
/* 0D7FD4 7F0A34A4 3C014230 */  li    $at, 0x42300000 # 44.000000
/* 0D7FD8 7F0A34A8 4481D000 */  mtc1  $at, $f26
/* 0D7FDC 7F0A34AC 3C014402 */  li    $at, 0x44020000 # 520.000000
/* 0D7FE0 7F0A34B0 4481C000 */  mtc1  $at, $f24
/* 0D7FE4 7F0A34B4 4480B000 */  mtc1  $zero, $f22
/* 0D7FE8 7F0A34B8 E7A0006C */  swc1  $f0, 0x6c($sp)
/* 0D7FEC 7F0A34BC 241300FF */  li    $s3, 255
/* 0D7FF0 7F0A34C0 44913000 */  mtc1  $s1, $f6
.L7F0A34C4:
/* 0D7FF4 7F0A34C4 3C018005 */  lui   $at, %hi(D_8005774C)
/* 0D7FF8 7F0A34C8 C42A774C */  lwc1  $f10, %lo(D_8005774C)($at)
/* 0D7FFC 7F0A34CC 46803220 */  cvt.s.w $f8, $f6
/* 0D8000 7F0A34D0 C7A0006C */  lwc1  $f0, 0x6c($sp)
/* 0D8004 7F0A34D4 460A4402 */  mul.s $f16, $f8, $f10
/* 0D8008 7F0A34D8 46008503 */  div.s $f20, $f16, $f0
/* 0D800C 7F0A34DC 0FC15FAB */  jal   sinf
/* 0D8010 7F0A34E0 4600A306 */   mov.s $f12, $f20
/* 0D8014 7F0A34E4 46180482 */  mul.s $f18, $f0, $f24
/* 0D8018 7F0A34E8 4600A306 */  mov.s $f12, $f20
/* 0D801C 7F0A34EC 461E9102 */  mul.s $f4, $f18, $f30
/* 0D8020 7F0A34F0 4600218D */  trunc.w.s $f6, $f4
/* 0D8024 7F0A34F4 44123000 */  mfc1  $s2, $f6
/* 0D8028 7F0A34F8 00000000 */  nop   
/* 0D802C 7F0A34FC 0012CC00 */  sll   $t9, $s2, 0x10
/* 0D8030 7F0A3500 0FC15FA8 */  jal   cosf
/* 0D8034 7F0A3504 00199403 */   sra   $s2, $t9, 0x10
/* 0D8038 7F0A3508 46180202 */  mul.s $f8, $f0, $f24
/* 0D803C 7F0A350C 264B0001 */  addiu $t3, $s2, 1
/* 0D8040 7F0A3510 A60B0000 */  sh    $t3, ($s0)
/* 0D8044 7F0A3514 A6000002 */  sh    $zero, 2($s0)
/* 0D8048 7F0A3518 A6000006 */  sh    $zero, 6($s0)
/* 0D804C 7F0A351C A6000008 */  sh    $zero, 8($s0)
/* 0D8050 7F0A3520 A600000A */  sh    $zero, 0xa($s0)
/* 0D8054 7F0A3524 461E4282 */  mul.s $f10, $f8, $f30
/* 0D8058 7F0A3528 4600A306 */  mov.s $f12, $f20
/* 0D805C 7F0A352C 4600540D */  trunc.w.s $f16, $f10
/* 0D8060 7F0A3530 440D8000 */  mfc1  $t5, $f16
/* 0D8064 7F0A3534 00000000 */  nop   
/* 0D8068 7F0A3538 000DA400 */  sll   $s4, $t5, 0x10
/* 0D806C 7F0A353C 00145403 */  sra   $t2, $s4, 0x10
/* 0D8070 7F0A3540 000D7023 */  negu  $t6, $t5
/* 0D8074 7F0A3544 0140A025 */  move  $s4, $t2
/* 0D8078 7F0A3548 0FC15FA8 */  jal   cosf
/* 0D807C 7F0A354C A60E0004 */   sh    $t6, 4($s0)
/* 0D8080 7F0A3550 46160482 */  mul.s $f18, $f0, $f22
/* 0D8084 7F0A3554 24180001 */  li    $t8, 1
/* 0D8088 7F0A3558 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D808C 7F0A355C 4612B101 */  sub.s $f4, $f22, $f18
/* 0D8090 7F0A3560 444FF800 */  cfc1  $t7, $31
/* 0D8094 7F0A3564 44D8F800 */  ctc1  $t8, $31
/* 0D8098 7F0A3568 00000000 */  nop   
/* 0D809C 7F0A356C 460021A4 */  cvt.w.s $f6, $f4
/* 0D80A0 7F0A3570 4458F800 */  cfc1  $t8, $31
/* 0D80A4 7F0A3574 00000000 */  nop   
/* 0D80A8 7F0A3578 33180078 */  andi  $t8, $t8, 0x78
/* 0D80AC 7F0A357C 53000013 */  beql  $t8, $zero, .L7F0A35CC
/* 0D80B0 7F0A3580 44183000 */   mfc1  $t8, $f6
/* 0D80B4 7F0A3584 44813000 */  mtc1  $at, $f6
/* 0D80B8 7F0A3588 24180001 */  li    $t8, 1
/* 0D80BC 7F0A358C 46062181 */  sub.s $f6, $f4, $f6
/* 0D80C0 7F0A3590 44D8F800 */  ctc1  $t8, $31
/* 0D80C4 7F0A3594 00000000 */  nop   
/* 0D80C8 7F0A3598 460031A4 */  cvt.w.s $f6, $f6
/* 0D80CC 7F0A359C 4458F800 */  cfc1  $t8, $31
/* 0D80D0 7F0A35A0 00000000 */  nop   
/* 0D80D4 7F0A35A4 33180078 */  andi  $t8, $t8, 0x78
/* 0D80D8 7F0A35A8 17000005 */  bnez  $t8, .L7F0A35C0
/* 0D80DC 7F0A35AC 00000000 */   nop   
/* 0D80E0 7F0A35B0 44183000 */  mfc1  $t8, $f6
/* 0D80E4 7F0A35B4 3C018000 */  lui   $at, 0x8000
/* 0D80E8 7F0A35B8 10000007 */  b     .L7F0A35D8
/* 0D80EC 7F0A35BC 0301C025 */   or    $t8, $t8, $at
.L7F0A35C0:
/* 0D80F0 7F0A35C0 10000005 */  b     .L7F0A35D8
/* 0D80F4 7F0A35C4 2418FFFF */   li    $t8, -1
/* 0D80F8 7F0A35C8 44183000 */  mfc1  $t8, $f6
.L7F0A35CC:
/* 0D80FC 7F0A35CC 00000000 */  nop   
/* 0D8100 7F0A35D0 0700FFFB */  bltz  $t8, .L7F0A35C0
/* 0D8104 7F0A35D4 00000000 */   nop   
.L7F0A35D8:
/* 0D8108 7F0A35D8 44CFF800 */  ctc1  $t7, $31
/* 0D810C 7F0A35DC A218000C */  sb    $t8, 0xc($s0)
/* 0D8110 7F0A35E0 0FC15FA8 */  jal   cosf
/* 0D8114 7F0A35E4 4600A306 */   mov.s $f12, $f20
/* 0D8118 7F0A35E8 461C0202 */  mul.s $f8, $f0, $f28
/* 0D811C 7F0A35EC 24080001 */  li    $t0, 1
/* 0D8120 7F0A35F0 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D8124 7F0A35F4 4608D281 */  sub.s $f10, $f26, $f8
/* 0D8128 7F0A35F8 4459F800 */  cfc1  $t9, $31
/* 0D812C 7F0A35FC 44C8F800 */  ctc1  $t0, $31
/* 0D8130 7F0A3600 00000000 */  nop   
/* 0D8134 7F0A3604 46005424 */  cvt.w.s $f16, $f10
/* 0D8138 7F0A3608 4448F800 */  cfc1  $t0, $31
/* 0D813C 7F0A360C 00000000 */  nop   
/* 0D8140 7F0A3610 31080078 */  andi  $t0, $t0, 0x78
/* 0D8144 7F0A3614 51000013 */  beql  $t0, $zero, .L7F0A3664
/* 0D8148 7F0A3618 44088000 */   mfc1  $t0, $f16
/* 0D814C 7F0A361C 44818000 */  mtc1  $at, $f16
/* 0D8150 7F0A3620 24080001 */  li    $t0, 1
/* 0D8154 7F0A3624 46105401 */  sub.s $f16, $f10, $f16
/* 0D8158 7F0A3628 44C8F800 */  ctc1  $t0, $31
/* 0D815C 7F0A362C 00000000 */  nop   
/* 0D8160 7F0A3630 46008424 */  cvt.w.s $f16, $f16
/* 0D8164 7F0A3634 4448F800 */  cfc1  $t0, $31
/* 0D8168 7F0A3638 00000000 */  nop   
/* 0D816C 7F0A363C 31080078 */  andi  $t0, $t0, 0x78
/* 0D8170 7F0A3640 15000005 */  bnez  $t0, .L7F0A3658
/* 0D8174 7F0A3644 00000000 */   nop   
/* 0D8178 7F0A3648 44088000 */  mfc1  $t0, $f16
/* 0D817C 7F0A364C 3C018000 */  lui   $at, 0x8000
/* 0D8180 7F0A3650 10000007 */  b     .L7F0A3670
/* 0D8184 7F0A3654 01014025 */   or    $t0, $t0, $at
.L7F0A3658:
/* 0D8188 7F0A3658 10000005 */  b     .L7F0A3670
/* 0D818C 7F0A365C 2408FFFF */   li    $t0, -1
/* 0D8190 7F0A3660 44088000 */  mfc1  $t0, $f16
.L7F0A3664:
/* 0D8194 7F0A3664 00000000 */  nop   
/* 0D8198 7F0A3668 0500FFFB */  bltz  $t0, .L7F0A3658
/* 0D819C 7F0A366C 00000000 */   nop   
.L7F0A3670:
/* 0D81A0 7F0A3670 44D9F800 */  ctc1  $t9, $31
/* 0D81A4 7F0A3674 A208000D */  sb    $t0, 0xd($s0)
/* 0D81A8 7F0A3678 0FC15FA8 */  jal   cosf
/* 0D81AC 7F0A367C 4600A306 */   mov.s $f12, $f20
/* 0D81B0 7F0A3680 46160482 */  mul.s $f18, $f0, $f22
/* 0D81B4 7F0A3684 240A0001 */  li    $t2, 1
/* 0D81B8 7F0A3688 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D81BC 7F0A368C 4612B101 */  sub.s $f4, $f22, $f18
/* 0D81C0 7F0A3690 4449F800 */  cfc1  $t1, $31
/* 0D81C4 7F0A3694 44CAF800 */  ctc1  $t2, $31
/* 0D81C8 7F0A3698 00000000 */  nop   
/* 0D81CC 7F0A369C 460021A4 */  cvt.w.s $f6, $f4
/* 0D81D0 7F0A36A0 444AF800 */  cfc1  $t2, $31
/* 0D81D4 7F0A36A4 00000000 */  nop   
/* 0D81D8 7F0A36A8 314A0078 */  andi  $t2, $t2, 0x78
/* 0D81DC 7F0A36AC 51400013 */  beql  $t2, $zero, .L7F0A36FC
/* 0D81E0 7F0A36B0 440A3000 */   mfc1  $t2, $f6
/* 0D81E4 7F0A36B4 44813000 */  mtc1  $at, $f6
/* 0D81E8 7F0A36B8 240A0001 */  li    $t2, 1
/* 0D81EC 7F0A36BC 46062181 */  sub.s $f6, $f4, $f6
/* 0D81F0 7F0A36C0 44CAF800 */  ctc1  $t2, $31
/* 0D81F4 7F0A36C4 00000000 */  nop   
/* 0D81F8 7F0A36C8 460031A4 */  cvt.w.s $f6, $f6
/* 0D81FC 7F0A36CC 444AF800 */  cfc1  $t2, $31
/* 0D8200 7F0A36D0 00000000 */  nop   
/* 0D8204 7F0A36D4 314A0078 */  andi  $t2, $t2, 0x78
/* 0D8208 7F0A36D8 15400005 */  bnez  $t2, .L7F0A36F0
/* 0D820C 7F0A36DC 00000000 */   nop   
/* 0D8210 7F0A36E0 440A3000 */  mfc1  $t2, $f6
/* 0D8214 7F0A36E4 3C018000 */  lui   $at, 0x8000
/* 0D8218 7F0A36E8 10000007 */  b     .L7F0A3708
/* 0D821C 7F0A36EC 01415025 */   or    $t2, $t2, $at
.L7F0A36F0:
/* 0D8220 7F0A36F0 10000005 */  b     .L7F0A3708
/* 0D8224 7F0A36F4 240AFFFF */   li    $t2, -1
/* 0D8228 7F0A36F8 440A3000 */  mfc1  $t2, $f6
.L7F0A36FC:
/* 0D822C 7F0A36FC 00000000 */  nop   
/* 0D8230 7F0A3700 0540FFFB */  bltz  $t2, .L7F0A36F0
/* 0D8234 7F0A3704 00000000 */   nop   
.L7F0A3708:
/* 0D8238 7F0A3708 44C9F800 */  ctc1  $t1, $31
/* 0D823C 7F0A370C A20A000E */  sb    $t2, 0xe($s0)
/* 0D8240 7F0A3710 A215000F */  sb    $s5, 0xf($s0)
/* 0D8244 7F0A3714 12200083 */  beqz  $s1, .L7F0A3924
/* 0D8248 7F0A3718 26100010 */   addiu $s0, $s0, 0x10
/* 0D824C 7F0A371C 0236082A */  slt   $at, $s1, $s6
/* 0D8250 7F0A3720 10200080 */  beqz  $at, .L7F0A3924
/* 0D8254 7F0A3724 240B0001 */   li    $t3, 1
/* 0D8258 7F0A3728 01726023 */  subu  $t4, $t3, $s2
/* 0D825C 7F0A372C 00146823 */  negu  $t5, $s4
/* 0D8260 7F0A3730 A60C0000 */  sh    $t4, ($s0)
/* 0D8264 7F0A3734 A6000002 */  sh    $zero, 2($s0)
/* 0D8268 7F0A3738 A60D0004 */  sh    $t5, 4($s0)
/* 0D826C 7F0A373C A6000006 */  sh    $zero, 6($s0)
/* 0D8270 7F0A3740 A6000008 */  sh    $zero, 8($s0)
/* 0D8274 7F0A3744 A600000A */  sh    $zero, 0xa($s0)
/* 0D8278 7F0A3748 A213000C */  sb    $s3, 0xc($s0)
/* 0D827C 7F0A374C A213000D */  sb    $s3, 0xd($s0)
/* 0D8280 7F0A3750 A213000E */  sb    $s3, 0xe($s0)
/* 0D8284 7F0A3754 0FC15FA8 */  jal   cosf
/* 0D8288 7F0A3758 4600A306 */   mov.s $f12, $f20
/* 0D828C 7F0A375C 46160202 */  mul.s $f8, $f0, $f22
/* 0D8290 7F0A3760 240F0001 */  li    $t7, 1
/* 0D8294 7F0A3764 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D8298 7F0A3768 4608B281 */  sub.s $f10, $f22, $f8
/* 0D829C 7F0A376C 444EF800 */  cfc1  $t6, $31
/* 0D82A0 7F0A3770 44CFF800 */  ctc1  $t7, $31
/* 0D82A4 7F0A3774 00000000 */  nop   
/* 0D82A8 7F0A3778 46005424 */  cvt.w.s $f16, $f10
/* 0D82AC 7F0A377C 444FF800 */  cfc1  $t7, $31
/* 0D82B0 7F0A3780 00000000 */  nop   
/* 0D82B4 7F0A3784 31EF0078 */  andi  $t7, $t7, 0x78
/* 0D82B8 7F0A3788 51E00013 */  beql  $t7, $zero, .L7F0A37D8
/* 0D82BC 7F0A378C 440F8000 */   mfc1  $t7, $f16
/* 0D82C0 7F0A3790 44818000 */  mtc1  $at, $f16
/* 0D82C4 7F0A3794 240F0001 */  li    $t7, 1
/* 0D82C8 7F0A3798 46105401 */  sub.s $f16, $f10, $f16
/* 0D82CC 7F0A379C 44CFF800 */  ctc1  $t7, $31
/* 0D82D0 7F0A37A0 00000000 */  nop   
/* 0D82D4 7F0A37A4 46008424 */  cvt.w.s $f16, $f16
/* 0D82D8 7F0A37A8 444FF800 */  cfc1  $t7, $31
/* 0D82DC 7F0A37AC 00000000 */  nop   
/* 0D82E0 7F0A37B0 31EF0078 */  andi  $t7, $t7, 0x78
/* 0D82E4 7F0A37B4 15E00005 */  bnez  $t7, .L7F0A37CC
/* 0D82E8 7F0A37B8 00000000 */   nop   
/* 0D82EC 7F0A37BC 440F8000 */  mfc1  $t7, $f16
/* 0D82F0 7F0A37C0 3C018000 */  lui   $at, 0x8000
/* 0D82F4 7F0A37C4 10000007 */  b     .L7F0A37E4
/* 0D82F8 7F0A37C8 01E17825 */   or    $t7, $t7, $at
.L7F0A37CC:
/* 0D82FC 7F0A37CC 10000005 */  b     .L7F0A37E4
/* 0D8300 7F0A37D0 240FFFFF */   li    $t7, -1
/* 0D8304 7F0A37D4 440F8000 */  mfc1  $t7, $f16
.L7F0A37D8:
/* 0D8308 7F0A37D8 00000000 */  nop   
/* 0D830C 7F0A37DC 05E0FFFB */  bltz  $t7, .L7F0A37CC
/* 0D8310 7F0A37E0 00000000 */   nop   
.L7F0A37E4:
/* 0D8314 7F0A37E4 44CEF800 */  ctc1  $t6, $31
/* 0D8318 7F0A37E8 A20F000C */  sb    $t7, 0xc($s0)
/* 0D831C 7F0A37EC 0FC15FA8 */  jal   cosf
/* 0D8320 7F0A37F0 4600A306 */   mov.s $f12, $f20
/* 0D8324 7F0A37F4 461C0482 */  mul.s $f18, $f0, $f28
/* 0D8328 7F0A37F8 24190001 */  li    $t9, 1
/* 0D832C 7F0A37FC 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D8330 7F0A3800 4612D101 */  sub.s $f4, $f26, $f18
/* 0D8334 7F0A3804 4458F800 */  cfc1  $t8, $31
/* 0D8338 7F0A3808 44D9F800 */  ctc1  $t9, $31
/* 0D833C 7F0A380C 00000000 */  nop   
/* 0D8340 7F0A3810 460021A4 */  cvt.w.s $f6, $f4
/* 0D8344 7F0A3814 4459F800 */  cfc1  $t9, $31
/* 0D8348 7F0A3818 00000000 */  nop   
/* 0D834C 7F0A381C 33390078 */  andi  $t9, $t9, 0x78
/* 0D8350 7F0A3820 53200013 */  beql  $t9, $zero, .L7F0A3870
/* 0D8354 7F0A3824 44193000 */   mfc1  $t9, $f6
/* 0D8358 7F0A3828 44813000 */  mtc1  $at, $f6
/* 0D835C 7F0A382C 24190001 */  li    $t9, 1
/* 0D8360 7F0A3830 46062181 */  sub.s $f6, $f4, $f6
/* 0D8364 7F0A3834 44D9F800 */  ctc1  $t9, $31
/* 0D8368 7F0A3838 00000000 */  nop   
/* 0D836C 7F0A383C 460031A4 */  cvt.w.s $f6, $f6
/* 0D8370 7F0A3840 4459F800 */  cfc1  $t9, $31
/* 0D8374 7F0A3844 00000000 */  nop   
/* 0D8378 7F0A3848 33390078 */  andi  $t9, $t9, 0x78
/* 0D837C 7F0A384C 17200005 */  bnez  $t9, .L7F0A3864
/* 0D8380 7F0A3850 00000000 */   nop   
/* 0D8384 7F0A3854 44193000 */  mfc1  $t9, $f6
/* 0D8388 7F0A3858 3C018000 */  lui   $at, 0x8000
/* 0D838C 7F0A385C 10000007 */  b     .L7F0A387C
/* 0D8390 7F0A3860 0321C825 */   or    $t9, $t9, $at
.L7F0A3864:
/* 0D8394 7F0A3864 10000005 */  b     .L7F0A387C
/* 0D8398 7F0A3868 2419FFFF */   li    $t9, -1
/* 0D839C 7F0A386C 44193000 */  mfc1  $t9, $f6
.L7F0A3870:
/* 0D83A0 7F0A3870 00000000 */  nop   
/* 0D83A4 7F0A3874 0720FFFB */  bltz  $t9, .L7F0A3864
/* 0D83A8 7F0A3878 00000000 */   nop   
.L7F0A387C:
/* 0D83AC 7F0A387C 44D8F800 */  ctc1  $t8, $31
/* 0D83B0 7F0A3880 A219000D */  sb    $t9, 0xd($s0)
/* 0D83B4 7F0A3884 0FC15FA8 */  jal   cosf
/* 0D83B8 7F0A3888 4600A306 */   mov.s $f12, $f20
/* 0D83BC 7F0A388C 46160202 */  mul.s $f8, $f0, $f22
/* 0D83C0 7F0A3890 24090001 */  li    $t1, 1
/* 0D83C4 7F0A3894 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D83C8 7F0A3898 4608B281 */  sub.s $f10, $f22, $f8
/* 0D83CC 7F0A389C 4448F800 */  cfc1  $t0, $31
/* 0D83D0 7F0A38A0 44C9F800 */  ctc1  $t1, $31
/* 0D83D4 7F0A38A4 00000000 */  nop   
/* 0D83D8 7F0A38A8 46005424 */  cvt.w.s $f16, $f10
/* 0D83DC 7F0A38AC 4449F800 */  cfc1  $t1, $31
/* 0D83E0 7F0A38B0 00000000 */  nop   
/* 0D83E4 7F0A38B4 31290078 */  andi  $t1, $t1, 0x78
/* 0D83E8 7F0A38B8 51200013 */  beql  $t1, $zero, .L7F0A3908
/* 0D83EC 7F0A38BC 44098000 */   mfc1  $t1, $f16
/* 0D83F0 7F0A38C0 44818000 */  mtc1  $at, $f16
/* 0D83F4 7F0A38C4 24090001 */  li    $t1, 1
/* 0D83F8 7F0A38C8 46105401 */  sub.s $f16, $f10, $f16
/* 0D83FC 7F0A38CC 44C9F800 */  ctc1  $t1, $31
/* 0D8400 7F0A38D0 00000000 */  nop   
/* 0D8404 7F0A38D4 46008424 */  cvt.w.s $f16, $f16
/* 0D8408 7F0A38D8 4449F800 */  cfc1  $t1, $31
/* 0D840C 7F0A38DC 00000000 */  nop   
/* 0D8410 7F0A38E0 31290078 */  andi  $t1, $t1, 0x78
/* 0D8414 7F0A38E4 15200005 */  bnez  $t1, .L7F0A38FC
/* 0D8418 7F0A38E8 00000000 */   nop   
/* 0D841C 7F0A38EC 44098000 */  mfc1  $t1, $f16
/* 0D8420 7F0A38F0 3C018000 */  lui   $at, 0x8000
/* 0D8424 7F0A38F4 10000007 */  b     .L7F0A3914
/* 0D8428 7F0A38F8 01214825 */   or    $t1, $t1, $at
.L7F0A38FC:
/* 0D842C 7F0A38FC 10000005 */  b     .L7F0A3914
/* 0D8430 7F0A3900 2409FFFF */   li    $t1, -1
/* 0D8434 7F0A3904 44098000 */  mfc1  $t1, $f16
.L7F0A3908:
/* 0D8438 7F0A3908 00000000 */  nop   
/* 0D843C 7F0A390C 0520FFFB */  bltz  $t1, .L7F0A38FC
/* 0D8440 7F0A3910 00000000 */   nop   
.L7F0A3914:
/* 0D8444 7F0A3914 44C8F800 */  ctc1  $t0, $31
/* 0D8448 7F0A3918 A209000E */  sb    $t1, 0xe($s0)
/* 0D844C 7F0A391C A215000F */  sb    $s5, 0xf($s0)
/* 0D8450 7F0A3920 26100010 */  addiu $s0, $s0, 0x10
.L7F0A3924:
/* 0D8454 7F0A3924 26310002 */  addiu $s1, $s1, 2
/* 0D8458 7F0A3928 02F1082A */  slt   $at, $s7, $s1
/* 0D845C 7F0A392C 5020FEE5 */  beql  $at, $zero, .L7F0A34C4
/* 0D8460 7F0A3930 44913000 */   mtc1  $s1, $f6
.L7F0A3934:
/* 0D8464 7F0A3934 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0D8468 7F0A3938 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0D846C 7F0A393C D7B60018 */  ldc1  $f22, 0x18($sp)
/* 0D8470 7F0A3940 D7B80020 */  ldc1  $f24, 0x20($sp)
/* 0D8474 7F0A3944 D7BA0028 */  ldc1  $f26, 0x28($sp)
/* 0D8478 7F0A3948 D7BC0030 */  ldc1  $f28, 0x30($sp)
/* 0D847C 7F0A394C D7BE0038 */  ldc1  $f30, 0x38($sp)
/* 0D8480 7F0A3950 8FB00044 */  lw    $s0, 0x44($sp)
/* 0D8484 7F0A3954 8FB10048 */  lw    $s1, 0x48($sp)
/* 0D8488 7F0A3958 8FB2004C */  lw    $s2, 0x4c($sp)
/* 0D848C 7F0A395C 8FB30050 */  lw    $s3, 0x50($sp)
/* 0D8490 7F0A3960 8FB40054 */  lw    $s4, 0x54($sp)
/* 0D8494 7F0A3964 8FB50058 */  lw    $s5, 0x58($sp)
/* 0D8498 7F0A3968 8FB6005C */  lw    $s6, 0x5c($sp)
/* 0D849C 7F0A396C 8FB70060 */  lw    $s7, 0x60($sp)
/* 0D84A0 7F0A3970 03E00008 */  jr    $ra
/* 0D84A4 7F0A3974 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_8005774C
.word 0x3fb501e2
.text
glabel sub_GAME_7F0A33F8
/* 0D5328 7F0A2938 27BDFF80 */  addiu $sp, $sp, -0x80
/* 0D532C 7F0A293C F7BE0038 */  sdc1  $f30, 0x38($sp)
/* 0D5330 7F0A2940 4486F000 */  mtc1  $a2, $f30
/* 0D5334 7F0A2944 AFB6005C */  sw    $s6, 0x5c($sp)
/* 0D5338 7F0A2948 AFB00044 */  sw    $s0, 0x44($sp)
/* 0D533C 7F0A294C 00808025 */  move  $s0, $a0
/* 0D5340 7F0A2950 00A0B025 */  move  $s6, $a1
/* 0D5344 7F0A2954 AFBF0064 */  sw    $ra, 0x64($sp)
/* 0D5348 7F0A2958 AFB70060 */  sw    $s7, 0x60($sp)
/* 0D534C 7F0A295C AFB50058 */  sw    $s5, 0x58($sp)
/* 0D5350 7F0A2960 AFB40054 */  sw    $s4, 0x54($sp)
/* 0D5354 7F0A2964 AFB30050 */  sw    $s3, 0x50($sp)
/* 0D5358 7F0A2968 AFB2004C */  sw    $s2, 0x4c($sp)
/* 0D535C 7F0A296C AFB10048 */  sw    $s1, 0x48($sp)
/* 0D5360 7F0A2970 F7BC0030 */  sdc1  $f28, 0x30($sp)
/* 0D5364 7F0A2974 F7BA0028 */  sdc1  $f26, 0x28($sp)
/* 0D5368 7F0A2978 F7B80020 */  sdc1  $f24, 0x20($sp)
/* 0D536C 7F0A297C F7B60018 */  sdc1  $f22, 0x18($sp)
/* 0D5370 7F0A2980 10E0000F */  beqz  $a3, .L7F0A29C0
/* 0D5374 7F0A2984 F7B40010 */   sdc1  $f20, 0x10($sp)
/* 0D5378 7F0A2988 241500B0 */  li    $s5, 176
/* 0D537C 7F0A298C 240E0001 */  li    $t6, 1
/* 0D5380 7F0A2990 240F002C */  li    $t7, 44
/* 0D5384 7F0A2994 A48E0000 */  sh    $t6, ($a0)
/* 0D5388 7F0A2998 A4800002 */  sh    $zero, 2($a0)
/* 0D538C 7F0A299C A4800004 */  sh    $zero, 4($a0)
/* 0D5390 7F0A29A0 A4800006 */  sh    $zero, 6($a0)
/* 0D5394 7F0A29A4 A4800008 */  sh    $zero, 8($a0)
/* 0D5398 7F0A29A8 A480000A */  sh    $zero, 0xa($a0)
/* 0D539C 7F0A29AC A080000C */  sb    $zero, 0xc($a0)
/* 0D53A0 7F0A29B0 A08F000D */  sb    $t7, 0xd($a0)
/* 0D53A4 7F0A29B4 A080000E */  sb    $zero, 0xe($a0)
/* 0D53A8 7F0A29B8 A095000F */  sb    $s5, 0xf($a0)
/* 0D53AC 7F0A29BC 24900010 */  addiu $s0, $a0, 0x10
.L7F0A29C0:
/* 0D53B0 7F0A29C0 26D7FFF9 */  addiu $s7, $s6, -7
/* 0D53B4 7F0A29C4 2AE10007 */  slti  $at, $s7, 7
/* 0D53B8 7F0A29C8 241500B0 */  li    $s5, 176
/* 0D53BC 7F0A29CC 14200129 */  bnez  $at, .L7F0A2E74
/* 0D53C0 7F0A29D0 24110007 */   li    $s1, 7
/* 0D53C4 7F0A29D4 44962000 */  mtc1  $s6, $f4
/* 0D53C8 7F0A29D8 3C0141A0 */  li    $at, 0x41A00000 # 20.000000
/* 0D53CC 7F0A29DC 4481E000 */  mtc1  $at, $f28
/* 0D53D0 7F0A29E0 46802020 */  cvt.s.w $f0, $f4
/* 0D53D4 7F0A29E4 3C014230 */  li    $at, 0x42300000 # 44.000000
/* 0D53D8 7F0A29E8 4481D000 */  mtc1  $at, $f26
/* 0D53DC 7F0A29EC 3C014402 */  li    $at, 0x44020000 # 520.000000
/* 0D53E0 7F0A29F0 4481C000 */  mtc1  $at, $f24
/* 0D53E4 7F0A29F4 4480B000 */  mtc1  $zero, $f22
/* 0D53E8 7F0A29F8 E7A0006C */  swc1  $f0, 0x6c($sp)
/* 0D53EC 7F0A29FC 241300FF */  li    $s3, 255
/* 0D53F0 7F0A2A00 44913000 */  mtc1  $s1, $f6
.L7F0A2A04:
/* 0D53F4 7F0A2A04 3C018005 */  lui   $at, %hi(D_8004CE1C) # $at, 0x8005
/* 0D53F8 7F0A2A08 C42ACE1C */  lwc1  $f10, %lo(D_8004CE1C)($at)
/* 0D53FC 7F0A2A0C 46803220 */  cvt.s.w $f8, $f6
/* 0D5400 7F0A2A10 C7A0006C */  lwc1  $f0, 0x6c($sp)
/* 0D5404 7F0A2A14 460A4402 */  mul.s $f16, $f8, $f10
/* 0D5408 7F0A2A18 46008503 */  div.s $f20, $f16, $f0
/* 0D540C 7F0A2A1C 0FC1606B */  jal   sinf
/* 0D5410 7F0A2A20 4600A306 */   mov.s $f12, $f20
/* 0D5414 7F0A2A24 46180482 */  mul.s $f18, $f0, $f24
/* 0D5418 7F0A2A28 4600A306 */  mov.s $f12, $f20
/* 0D541C 7F0A2A2C 461E9102 */  mul.s $f4, $f18, $f30
/* 0D5420 7F0A2A30 4600218D */  trunc.w.s $f6, $f4
/* 0D5424 7F0A2A34 44123000 */  mfc1  $s2, $f6
/* 0D5428 7F0A2A38 00000000 */  nop   
/* 0D542C 7F0A2A3C 0012CC00 */  sll   $t9, $s2, 0x10
/* 0D5430 7F0A2A40 0FC16068 */  jal   cosf
/* 0D5434 7F0A2A44 00199403 */   sra   $s2, $t9, 0x10
/* 0D5438 7F0A2A48 46180202 */  mul.s $f8, $f0, $f24
/* 0D543C 7F0A2A4C 264B0001 */  addiu $t3, $s2, 1
/* 0D5440 7F0A2A50 A60B0000 */  sh    $t3, ($s0)
/* 0D5444 7F0A2A54 A6000002 */  sh    $zero, 2($s0)
/* 0D5448 7F0A2A58 A6000006 */  sh    $zero, 6($s0)
/* 0D544C 7F0A2A5C A6000008 */  sh    $zero, 8($s0)
/* 0D5450 7F0A2A60 A600000A */  sh    $zero, 0xa($s0)
/* 0D5454 7F0A2A64 461E4282 */  mul.s $f10, $f8, $f30
/* 0D5458 7F0A2A68 4600A306 */  mov.s $f12, $f20
/* 0D545C 7F0A2A6C 4600540D */  trunc.w.s $f16, $f10
/* 0D5460 7F0A2A70 440D8000 */  mfc1  $t5, $f16
/* 0D5464 7F0A2A74 00000000 */  nop   
/* 0D5468 7F0A2A78 000DA400 */  sll   $s4, $t5, 0x10
/* 0D546C 7F0A2A7C 00145403 */  sra   $t2, $s4, 0x10
/* 0D5470 7F0A2A80 000D7023 */  negu  $t6, $t5
/* 0D5474 7F0A2A84 0140A025 */  move  $s4, $t2
/* 0D5478 7F0A2A88 0FC16068 */  jal   cosf
/* 0D547C 7F0A2A8C A60E0004 */   sh    $t6, 4($s0)
/* 0D5480 7F0A2A90 46160482 */  mul.s $f18, $f0, $f22
/* 0D5484 7F0A2A94 24180001 */  li    $t8, 1
/* 0D5488 7F0A2A98 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D548C 7F0A2A9C 4612B101 */  sub.s $f4, $f22, $f18
/* 0D5490 7F0A2AA0 444FF800 */  cfc1  $t7, $31
/* 0D5494 7F0A2AA4 44D8F800 */  ctc1  $t8, $31
/* 0D5498 7F0A2AA8 00000000 */  nop   
/* 0D549C 7F0A2AAC 460021A4 */  cvt.w.s $f6, $f4
/* 0D54A0 7F0A2AB0 4458F800 */  cfc1  $t8, $31
/* 0D54A4 7F0A2AB4 00000000 */  nop   
/* 0D54A8 7F0A2AB8 33180078 */  andi  $t8, $t8, 0x78
/* 0D54AC 7F0A2ABC 53000013 */  beql  $t8, $zero, .L7F0A2B0C
/* 0D54B0 7F0A2AC0 44183000 */   mfc1  $t8, $f6
/* 0D54B4 7F0A2AC4 44813000 */  mtc1  $at, $f6
/* 0D54B8 7F0A2AC8 24180001 */  li    $t8, 1
/* 0D54BC 7F0A2ACC 46062181 */  sub.s $f6, $f4, $f6
/* 0D54C0 7F0A2AD0 44D8F800 */  ctc1  $t8, $31
/* 0D54C4 7F0A2AD4 00000000 */  nop   
/* 0D54C8 7F0A2AD8 460031A4 */  cvt.w.s $f6, $f6
/* 0D54CC 7F0A2ADC 4458F800 */  cfc1  $t8, $31
/* 0D54D0 7F0A2AE0 00000000 */  nop   
/* 0D54D4 7F0A2AE4 33180078 */  andi  $t8, $t8, 0x78
/* 0D54D8 7F0A2AE8 17000005 */  bnez  $t8, .L7F0A2B00
/* 0D54DC 7F0A2AEC 00000000 */   nop   
/* 0D54E0 7F0A2AF0 44183000 */  mfc1  $t8, $f6
/* 0D54E4 7F0A2AF4 3C018000 */  lui   $at, 0x8000
/* 0D54E8 7F0A2AF8 10000007 */  b     .L7F0A2B18
/* 0D54EC 7F0A2AFC 0301C025 */   or    $t8, $t8, $at
.L7F0A2B00:
/* 0D54F0 7F0A2B00 10000005 */  b     .L7F0A2B18
/* 0D54F4 7F0A2B04 2418FFFF */   li    $t8, -1
/* 0D54F8 7F0A2B08 44183000 */  mfc1  $t8, $f6
.L7F0A2B0C:
/* 0D54FC 7F0A2B0C 00000000 */  nop   
/* 0D5500 7F0A2B10 0700FFFB */  bltz  $t8, .L7F0A2B00
/* 0D5504 7F0A2B14 00000000 */   nop   
.L7F0A2B18:
/* 0D5508 7F0A2B18 44CFF800 */  ctc1  $t7, $31
/* 0D550C 7F0A2B1C A218000C */  sb    $t8, 0xc($s0)
/* 0D5510 7F0A2B20 0FC16068 */  jal   cosf
/* 0D5514 7F0A2B24 4600A306 */   mov.s $f12, $f20
/* 0D5518 7F0A2B28 461C0202 */  mul.s $f8, $f0, $f28
/* 0D551C 7F0A2B2C 24080001 */  li    $t0, 1
/* 0D5520 7F0A2B30 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D5524 7F0A2B34 4608D281 */  sub.s $f10, $f26, $f8
/* 0D5528 7F0A2B38 4459F800 */  cfc1  $t9, $31
/* 0D552C 7F0A2B3C 44C8F800 */  ctc1  $t0, $31
/* 0D5530 7F0A2B40 00000000 */  nop   
/* 0D5534 7F0A2B44 46005424 */  cvt.w.s $f16, $f10
/* 0D5538 7F0A2B48 4448F800 */  cfc1  $t0, $31
/* 0D553C 7F0A2B4C 00000000 */  nop   
/* 0D5540 7F0A2B50 31080078 */  andi  $t0, $t0, 0x78
/* 0D5544 7F0A2B54 51000013 */  beql  $t0, $zero, .L7F0A2BA4
/* 0D5548 7F0A2B58 44088000 */   mfc1  $t0, $f16
/* 0D554C 7F0A2B5C 44818000 */  mtc1  $at, $f16
/* 0D5550 7F0A2B60 24080001 */  li    $t0, 1
/* 0D5554 7F0A2B64 46105401 */  sub.s $f16, $f10, $f16
/* 0D5558 7F0A2B68 44C8F800 */  ctc1  $t0, $31
/* 0D555C 7F0A2B6C 00000000 */  nop   
/* 0D5560 7F0A2B70 46008424 */  cvt.w.s $f16, $f16
/* 0D5564 7F0A2B74 4448F800 */  cfc1  $t0, $31
/* 0D5568 7F0A2B78 00000000 */  nop   
/* 0D556C 7F0A2B7C 31080078 */  andi  $t0, $t0, 0x78
/* 0D5570 7F0A2B80 15000005 */  bnez  $t0, .L7F0A2B98
/* 0D5574 7F0A2B84 00000000 */   nop   
/* 0D5578 7F0A2B88 44088000 */  mfc1  $t0, $f16
/* 0D557C 7F0A2B8C 3C018000 */  lui   $at, 0x8000
/* 0D5580 7F0A2B90 10000007 */  b     .L7F0A2BB0
/* 0D5584 7F0A2B94 01014025 */   or    $t0, $t0, $at
.L7F0A2B98:
/* 0D5588 7F0A2B98 10000005 */  b     .L7F0A2BB0
/* 0D558C 7F0A2B9C 2408FFFF */   li    $t0, -1
/* 0D5590 7F0A2BA0 44088000 */  mfc1  $t0, $f16
.L7F0A2BA4:
/* 0D5594 7F0A2BA4 00000000 */  nop   
/* 0D5598 7F0A2BA8 0500FFFB */  bltz  $t0, .L7F0A2B98
/* 0D559C 7F0A2BAC 00000000 */   nop   
.L7F0A2BB0:
/* 0D55A0 7F0A2BB0 44D9F800 */  ctc1  $t9, $31
/* 0D55A4 7F0A2BB4 A208000D */  sb    $t0, 0xd($s0)
/* 0D55A8 7F0A2BB8 0FC16068 */  jal   cosf
/* 0D55AC 7F0A2BBC 4600A306 */   mov.s $f12, $f20
/* 0D55B0 7F0A2BC0 46160482 */  mul.s $f18, $f0, $f22
/* 0D55B4 7F0A2BC4 240A0001 */  li    $t2, 1
/* 0D55B8 7F0A2BC8 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D55BC 7F0A2BCC 4612B101 */  sub.s $f4, $f22, $f18
/* 0D55C0 7F0A2BD0 4449F800 */  cfc1  $t1, $31
/* 0D55C4 7F0A2BD4 44CAF800 */  ctc1  $t2, $31
/* 0D55C8 7F0A2BD8 00000000 */  nop   
/* 0D55CC 7F0A2BDC 460021A4 */  cvt.w.s $f6, $f4
/* 0D55D0 7F0A2BE0 444AF800 */  cfc1  $t2, $31
/* 0D55D4 7F0A2BE4 00000000 */  nop   
/* 0D55D8 7F0A2BE8 314A0078 */  andi  $t2, $t2, 0x78
/* 0D55DC 7F0A2BEC 51400013 */  beql  $t2, $zero, .L7F0A2C3C
/* 0D55E0 7F0A2BF0 440A3000 */   mfc1  $t2, $f6
/* 0D55E4 7F0A2BF4 44813000 */  mtc1  $at, $f6
/* 0D55E8 7F0A2BF8 240A0001 */  li    $t2, 1
/* 0D55EC 7F0A2BFC 46062181 */  sub.s $f6, $f4, $f6
/* 0D55F0 7F0A2C00 44CAF800 */  ctc1  $t2, $31
/* 0D55F4 7F0A2C04 00000000 */  nop   
/* 0D55F8 7F0A2C08 460031A4 */  cvt.w.s $f6, $f6
/* 0D55FC 7F0A2C0C 444AF800 */  cfc1  $t2, $31
/* 0D5600 7F0A2C10 00000000 */  nop   
/* 0D5604 7F0A2C14 314A0078 */  andi  $t2, $t2, 0x78
/* 0D5608 7F0A2C18 15400005 */  bnez  $t2, .L7F0A2C30
/* 0D560C 7F0A2C1C 00000000 */   nop   
/* 0D5610 7F0A2C20 440A3000 */  mfc1  $t2, $f6
/* 0D5614 7F0A2C24 3C018000 */  lui   $at, 0x8000
/* 0D5618 7F0A2C28 10000007 */  b     .L7F0A2C48
/* 0D561C 7F0A2C2C 01415025 */   or    $t2, $t2, $at
.L7F0A2C30:
/* 0D5620 7F0A2C30 10000005 */  b     .L7F0A2C48
/* 0D5624 7F0A2C34 240AFFFF */   li    $t2, -1
/* 0D5628 7F0A2C38 440A3000 */  mfc1  $t2, $f6
.L7F0A2C3C:
/* 0D562C 7F0A2C3C 00000000 */  nop   
/* 0D5630 7F0A2C40 0540FFFB */  bltz  $t2, .L7F0A2C30
/* 0D5634 7F0A2C44 00000000 */   nop   
.L7F0A2C48:
/* 0D5638 7F0A2C48 44C9F800 */  ctc1  $t1, $31
/* 0D563C 7F0A2C4C A20A000E */  sb    $t2, 0xe($s0)
/* 0D5640 7F0A2C50 A215000F */  sb    $s5, 0xf($s0)
/* 0D5644 7F0A2C54 12200083 */  beqz  $s1, .L7F0A2E64
/* 0D5648 7F0A2C58 26100010 */   addiu $s0, $s0, 0x10
/* 0D564C 7F0A2C5C 0236082A */  slt   $at, $s1, $s6
/* 0D5650 7F0A2C60 10200080 */  beqz  $at, .L7F0A2E64
/* 0D5654 7F0A2C64 240B0001 */   li    $t3, 1
/* 0D5658 7F0A2C68 01726023 */  subu  $t4, $t3, $s2
/* 0D565C 7F0A2C6C 00146823 */  negu  $t5, $s4
/* 0D5660 7F0A2C70 A60C0000 */  sh    $t4, ($s0)
/* 0D5664 7F0A2C74 A6000002 */  sh    $zero, 2($s0)
/* 0D5668 7F0A2C78 A60D0004 */  sh    $t5, 4($s0)
/* 0D566C 7F0A2C7C A6000006 */  sh    $zero, 6($s0)
/* 0D5670 7F0A2C80 A6000008 */  sh    $zero, 8($s0)
/* 0D5674 7F0A2C84 A600000A */  sh    $zero, 0xa($s0)
/* 0D5678 7F0A2C88 A213000C */  sb    $s3, 0xc($s0)
/* 0D567C 7F0A2C8C A213000D */  sb    $s3, 0xd($s0)
/* 0D5680 7F0A2C90 A213000E */  sb    $s3, 0xe($s0)
/* 0D5684 7F0A2C94 0FC16068 */  jal   cosf
/* 0D5688 7F0A2C98 4600A306 */   mov.s $f12, $f20
/* 0D568C 7F0A2C9C 46160202 */  mul.s $f8, $f0, $f22
/* 0D5690 7F0A2CA0 240F0001 */  li    $t7, 1
/* 0D5694 7F0A2CA4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D5698 7F0A2CA8 4608B281 */  sub.s $f10, $f22, $f8
/* 0D569C 7F0A2CAC 444EF800 */  cfc1  $t6, $31
/* 0D56A0 7F0A2CB0 44CFF800 */  ctc1  $t7, $31
/* 0D56A4 7F0A2CB4 00000000 */  nop   
/* 0D56A8 7F0A2CB8 46005424 */  cvt.w.s $f16, $f10
/* 0D56AC 7F0A2CBC 444FF800 */  cfc1  $t7, $31
/* 0D56B0 7F0A2CC0 00000000 */  nop   
/* 0D56B4 7F0A2CC4 31EF0078 */  andi  $t7, $t7, 0x78
/* 0D56B8 7F0A2CC8 51E00013 */  beql  $t7, $zero, .L7F0A2D18
/* 0D56BC 7F0A2CCC 440F8000 */   mfc1  $t7, $f16
/* 0D56C0 7F0A2CD0 44818000 */  mtc1  $at, $f16
/* 0D56C4 7F0A2CD4 240F0001 */  li    $t7, 1
/* 0D56C8 7F0A2CD8 46105401 */  sub.s $f16, $f10, $f16
/* 0D56CC 7F0A2CDC 44CFF800 */  ctc1  $t7, $31
/* 0D56D0 7F0A2CE0 00000000 */  nop   
/* 0D56D4 7F0A2CE4 46008424 */  cvt.w.s $f16, $f16
/* 0D56D8 7F0A2CE8 444FF800 */  cfc1  $t7, $31
/* 0D56DC 7F0A2CEC 00000000 */  nop   
/* 0D56E0 7F0A2CF0 31EF0078 */  andi  $t7, $t7, 0x78
/* 0D56E4 7F0A2CF4 15E00005 */  bnez  $t7, .L7F0A2D0C
/* 0D56E8 7F0A2CF8 00000000 */   nop   
/* 0D56EC 7F0A2CFC 440F8000 */  mfc1  $t7, $f16
/* 0D56F0 7F0A2D00 3C018000 */  lui   $at, 0x8000
/* 0D56F4 7F0A2D04 10000007 */  b     .L7F0A2D24
/* 0D56F8 7F0A2D08 01E17825 */   or    $t7, $t7, $at
.L7F0A2D0C:
/* 0D56FC 7F0A2D0C 10000005 */  b     .L7F0A2D24
/* 0D5700 7F0A2D10 240FFFFF */   li    $t7, -1
/* 0D5704 7F0A2D14 440F8000 */  mfc1  $t7, $f16
.L7F0A2D18:
/* 0D5708 7F0A2D18 00000000 */  nop   
/* 0D570C 7F0A2D1C 05E0FFFB */  bltz  $t7, .L7F0A2D0C
/* 0D5710 7F0A2D20 00000000 */   nop   
.L7F0A2D24:
/* 0D5714 7F0A2D24 44CEF800 */  ctc1  $t6, $31
/* 0D5718 7F0A2D28 A20F000C */  sb    $t7, 0xc($s0)
/* 0D571C 7F0A2D2C 0FC16068 */  jal   cosf
/* 0D5720 7F0A2D30 4600A306 */   mov.s $f12, $f20
/* 0D5724 7F0A2D34 461C0482 */  mul.s $f18, $f0, $f28
/* 0D5728 7F0A2D38 24190001 */  li    $t9, 1
/* 0D572C 7F0A2D3C 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D5730 7F0A2D40 4612D101 */  sub.s $f4, $f26, $f18
/* 0D5734 7F0A2D44 4458F800 */  cfc1  $t8, $31
/* 0D5738 7F0A2D48 44D9F800 */  ctc1  $t9, $31
/* 0D573C 7F0A2D4C 00000000 */  nop   
/* 0D5740 7F0A2D50 460021A4 */  cvt.w.s $f6, $f4
/* 0D5744 7F0A2D54 4459F800 */  cfc1  $t9, $31
/* 0D5748 7F0A2D58 00000000 */  nop   
/* 0D574C 7F0A2D5C 33390078 */  andi  $t9, $t9, 0x78
/* 0D5750 7F0A2D60 53200013 */  beql  $t9, $zero, .Leu7F0A2DB0
/* 0D5754 7F0A2D64 44193000 */   mfc1  $t9, $f6
/* 0D5758 7F0A2D68 44813000 */  mtc1  $at, $f6
/* 0D575C 7F0A2D6C 24190001 */  li    $t9, 1
/* 0D5760 7F0A2D70 46062181 */  sub.s $f6, $f4, $f6
/* 0D5764 7F0A2D74 44D9F800 */  ctc1  $t9, $31
/* 0D5768 7F0A2D78 00000000 */  nop   
/* 0D576C 7F0A2D7C 460031A4 */  cvt.w.s $f6, $f6
/* 0D5770 7F0A2D80 4459F800 */  cfc1  $t9, $31
/* 0D5774 7F0A2D84 00000000 */  nop   
/* 0D5778 7F0A2D88 33390078 */  andi  $t9, $t9, 0x78
/* 0D577C 7F0A2D8C 17200005 */  bnez  $t9, .L7F0A2DA4
/* 0D5780 7F0A2D90 00000000 */   nop   
/* 0D5784 7F0A2D94 44193000 */  mfc1  $t9, $f6
/* 0D5788 7F0A2D98 3C018000 */  lui   $at, 0x8000
/* 0D578C 7F0A2D9C 10000007 */  b     .L7F0A2DBC
/* 0D5790 7F0A2DA0 0321C825 */   or    $t9, $t9, $at
.L7F0A2DA4:
/* 0D5794 7F0A2DA4 10000005 */  b     .L7F0A2DBC
/* 0D5798 7F0A2DA8 2419FFFF */   li    $t9, -1
/* 0D579C 7F0A2DAC 44193000 */  mfc1  $t9, $f6
.Leu7F0A2DB0:
/* 0D57A0 7F0A2DB0 00000000 */  nop   
/* 0D57A4 7F0A2DB4 0720FFFB */  bltz  $t9, .L7F0A2DA4
/* 0D57A8 7F0A2DB8 00000000 */   nop   
.L7F0A2DBC:
/* 0D57AC 7F0A2DBC 44D8F800 */  ctc1  $t8, $31
/* 0D57B0 7F0A2DC0 A219000D */  sb    $t9, 0xd($s0)
/* 0D57B4 7F0A2DC4 0FC16068 */  jal   cosf
/* 0D57B8 7F0A2DC8 4600A306 */   mov.s $f12, $f20
/* 0D57BC 7F0A2DCC 46160202 */  mul.s $f8, $f0, $f22
/* 0D57C0 7F0A2DD0 24090001 */  li    $t1, 1
/* 0D57C4 7F0A2DD4 3C014F00 */  li    $at, 0x4F000000 # 2147483648.000000
/* 0D57C8 7F0A2DD8 4608B281 */  sub.s $f10, $f22, $f8
/* 0D57CC 7F0A2DDC 4448F800 */  cfc1  $t0, $31
/* 0D57D0 7F0A2DE0 44C9F800 */  ctc1  $t1, $31
/* 0D57D4 7F0A2DE4 00000000 */  nop   
/* 0D57D8 7F0A2DE8 46005424 */  cvt.w.s $f16, $f10
/* 0D57DC 7F0A2DEC 4449F800 */  cfc1  $t1, $31
/* 0D57E0 7F0A2DF0 00000000 */  nop   
/* 0D57E4 7F0A2DF4 31290078 */  andi  $t1, $t1, 0x78
/* 0D57E8 7F0A2DF8 51200013 */  beql  $t1, $zero, .L7F0A2E48
/* 0D57EC 7F0A2DFC 44098000 */   mfc1  $t1, $f16
/* 0D57F0 7F0A2E00 44818000 */  mtc1  $at, $f16
/* 0D57F4 7F0A2E04 24090001 */  li    $t1, 1
/* 0D57F8 7F0A2E08 46105401 */  sub.s $f16, $f10, $f16
/* 0D57FC 7F0A2E0C 44C9F800 */  ctc1  $t1, $31
/* 0D5800 7F0A2E10 00000000 */  nop   
/* 0D5804 7F0A2E14 46008424 */  cvt.w.s $f16, $f16
/* 0D5808 7F0A2E18 4449F800 */  cfc1  $t1, $31
/* 0D580C 7F0A2E1C 00000000 */  nop   
/* 0D5810 7F0A2E20 31290078 */  andi  $t1, $t1, 0x78
/* 0D5814 7F0A2E24 15200005 */  bnez  $t1, .L7F0A2E3C
/* 0D5818 7F0A2E28 00000000 */   nop   
/* 0D581C 7F0A2E2C 44098000 */  mfc1  $t1, $f16
/* 0D5820 7F0A2E30 3C018000 */  lui   $at, 0x8000
/* 0D5824 7F0A2E34 10000007 */  b     .L7F0A2E54
/* 0D5828 7F0A2E38 01214825 */   or    $t1, $t1, $at
.L7F0A2E3C:
/* 0D582C 7F0A2E3C 10000005 */  b     .L7F0A2E54
/* 0D5830 7F0A2E40 2409FFFF */   li    $t1, -1
/* 0D5834 7F0A2E44 44098000 */  mfc1  $t1, $f16
.L7F0A2E48:
/* 0D5838 7F0A2E48 00000000 */  nop   
/* 0D583C 7F0A2E4C 0520FFFB */  bltz  $t1, .L7F0A2E3C
/* 0D5840 7F0A2E50 00000000 */   nop   
.L7F0A2E54:
/* 0D5844 7F0A2E54 44C8F800 */  ctc1  $t0, $31
/* 0D5848 7F0A2E58 A209000E */  sb    $t1, 0xe($s0)
/* 0D584C 7F0A2E5C A215000F */  sb    $s5, 0xf($s0)
/* 0D5850 7F0A2E60 26100010 */  addiu $s0, $s0, 0x10
.L7F0A2E64:
/* 0D5854 7F0A2E64 26310002 */  addiu $s1, $s1, 2
/* 0D5858 7F0A2E68 02F1082A */  slt   $at, $s7, $s1
/* 0D585C 7F0A2E6C 5020FEE5 */  beql  $at, $zero, .L7F0A2A04
/* 0D5860 7F0A2E70 44913000 */   mtc1  $s1, $f6
.L7F0A2E74:
/* 0D5864 7F0A2E74 8FBF0064 */  lw    $ra, 0x64($sp)
/* 0D5868 7F0A2E78 D7B40010 */  ldc1  $f20, 0x10($sp)
/* 0D586C 7F0A2E7C D7B60018 */  ldc1  $f22, 0x18($sp)
/* 0D5870 7F0A2E80 D7B80020 */  ldc1  $f24, 0x20($sp)
/* 0D5874 7F0A2E84 D7BA0028 */  ldc1  $f26, 0x28($sp)
/* 0D5878 7F0A2E88 D7BC0030 */  ldc1  $f28, 0x30($sp)
/* 0D587C 7F0A2E8C D7BE0038 */  ldc1  $f30, 0x38($sp)
/* 0D5880 7F0A2E90 8FB00044 */  lw    $s0, 0x44($sp)
/* 0D5884 7F0A2E94 8FB10048 */  lw    $s1, 0x48($sp)
/* 0D5888 7F0A2E98 8FB2004C */  lw    $s2, 0x4c($sp)
/* 0D588C 7F0A2E9C 8FB30050 */  lw    $s3, 0x50($sp)
/* 0D5890 7F0A2EA0 8FB40054 */  lw    $s4, 0x54($sp)
/* 0D5894 7F0A2EA4 8FB50058 */  lw    $s5, 0x58($sp)
/* 0D5898 7F0A2EA8 8FB6005C */  lw    $s6, 0x5c($sp)
/* 0D589C 7F0A2EAC 8FB70060 */  lw    $s7, 0x60($sp)
/* 0D58A0 7F0A2EB0 03E00008 */  jr    $ra
/* 0D58A4 7F0A2EB4 27BD0080 */   addiu $sp, $sp, 0x80
)
#endif
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A3978(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A3978
/* 0D84A8 7F0A3978 10E00036 */  beqz  $a3, .L7F0A3A54
/* 0D84AC 7F0A397C AFA60008 */   sw    $a2, 8($sp)
/* 0D84B0 7F0A3980 00A01025 */  move  $v0, $a1
/* 0D84B4 7F0A3984 00803025 */  move  $a2, $a0
/* 0D84B8 7F0A3988 3C090430 */  lui   $t1, (0x04300040 >> 16) # lui $t1, 0x430
/* 0D84BC 7F0A398C 24A50010 */  addiu $a1, $a1, 0x10
/* 0D84C0 7F0A3990 24840008 */  addiu $a0, $a0, 8
/* 0D84C4 7F0A3994 35290040 */  ori   $t1, (0x04300040 & 0xFFFF) # ori $t1, $t1, 0x40
/* 0D84C8 7F0A3998 24AE00E0 */  addiu $t6, $a1, 0xe0
/* 0D84CC 7F0A399C 00803825 */  move  $a3, $a0
/* 0D84D0 7F0A39A0 3C0A0404 */  lui   $t2, (0x04040010 >> 16) # lui $t2, 0x404
/* 0D84D4 7F0A39A4 ACCE0004 */  sw    $t6, 4($a2)
/* 0D84D8 7F0A39A8 ACC90000 */  sw    $t1, ($a2)
/* 0D84DC 7F0A39AC 24840008 */  addiu $a0, $a0, 8
/* 0D84E0 7F0A39B0 354A0010 */  ori   $t2, (0x04040010 & 0xFFFF) # ori $t2, $t2, 0x10
/* 0D84E4 7F0A39B4 00804025 */  move  $t0, $a0
/* 0D84E8 7F0A39B8 ACEA0000 */  sw    $t2, ($a3)
/* 0D84EC 7F0A39BC ACE20004 */  sw    $v0, 4($a3)
/* 0D84F0 7F0A39C0 3C0FB100 */  lui   $t7, (0xB1000003 >> 16) # lui $t7, 0xb100
/* 0D84F4 7F0A39C4 35EF0003 */  ori   $t7, (0xB1000003 & 0xFFFF) # ori $t7, $t7, 3
/* 0D84F8 7F0A39C8 24180042 */  li    $t8, 66
/* 0D84FC 7F0A39CC 3C0BB100 */  lui   $t3, (0xB1000042 >> 16) # lui $t3, 0xb100
/* 0D8500 7F0A39D0 24030007 */  li    $v1, 7
/* 0D8504 7F0A39D4 AD180004 */  sw    $t8, 4($t0)
/* 0D8508 7F0A39D8 AD0F0000 */  sw    $t7, ($t0)
/* 0D850C 7F0A39DC 24840008 */  addiu $a0, $a0, 8
/* 0D8510 7F0A39E0 356B0042 */  ori   $t3, (0xB1000042 & 0xFFFF) # ori $t3, $t3, 0x42
/* 0D8514 7F0A39E4 240C3140 */  li    $t4, 12608
.L7F0A39E8:
/* 0D8518 7F0A39E8 00803025 */  move  $a2, $a0
/* 0D851C 7F0A39EC 0060C825 */  move  $t9, $v1
/* 0D8520 7F0A39F0 00196940 */  sll   $t5, $t9, 5
/* 0D8524 7F0A39F4 24840008 */  addiu $a0, $a0, 8
/* 0D8528 7F0A39F8 01A57021 */  addu  $t6, $t5, $a1
/* 0D852C 7F0A39FC 00803825 */  move  $a3, $a0
/* 0D8530 7F0A3A00 2463FFFF */  addiu $v1, $v1, -1
/* 0D8534 7F0A3A04 ACCE0004 */  sw    $t6, 4($a2)
/* 0D8538 7F0A3A08 ACC90000 */  sw    $t1, ($a2)
/* 0D853C 7F0A3A0C 24840008 */  addiu $a0, $a0, 8
/* 0D8540 7F0A3A10 00037E00 */  sll   $t7, $v1, 0x18
/* 0D8544 7F0A3A14 00804025 */  move  $t0, $a0
/* 0D8548 7F0A3A18 000F1E03 */  sra   $v1, $t7, 0x18
/* 0D854C 7F0A3A1C ACE20004 */  sw    $v0, 4($a3)
/* 0D8550 7F0A3A20 ACEA0000 */  sw    $t2, ($a3)
/* 0D8554 7F0A3A24 AD0C0004 */  sw    $t4, 4($t0)
/* 0D8558 7F0A3A28 AD0B0000 */  sw    $t3, ($t0)
/* 0D855C 7F0A3A2C 0461FFEE */  bgez  $v1, .L7F0A39E8
/* 0D8560 7F0A3A30 24840008 */   addiu $a0, $a0, 8
/* 0D8564 7F0A3A34 00801025 */  move  $v0, $a0
/* 0D8568 7F0A3A38 3C19B100 */  lui   $t9, (0xB1000004 >> 16) # lui $t9, 0xb100
/* 0D856C 7F0A3A3C 37390004 */  ori   $t9, (0xB1000004 & 0xFFFF) # ori $t9, $t9, 4
/* 0D8570 7F0A3A40 240D0010 */  li    $t5, 16
/* 0D8574 7F0A3A44 AC4D0004 */  sw    $t5, 4($v0)
/* 0D8578 7F0A3A48 AC590000 */  sw    $t9, ($v0)
/* 0D857C 7F0A3A4C 10000015 */  b     .L7F0A3AA4
/* 0D8580 7F0A3A50 24840008 */   addiu $a0, $a0, 8
.L7F0A3A54:
/* 0D8584 7F0A3A54 3C090430 */  lui   $t1, (0x04300040 >> 16) # lui $t1, 0x430
/* 0D8588 7F0A3A58 3C07B100 */  lui   $a3, (0xB1000032 >> 16) # lui $a3, 0xb100
/* 0D858C 7F0A3A5C 34E70032 */  ori   $a3, (0xB1000032 & 0xFFFF) # ori $a3, $a3, 0x32
/* 0D8590 7F0A3A60 35290040 */  ori   $t1, (0x04300040 & 0xFFFF) # ori $t1, $t1, 0x40
/* 0D8594 7F0A3A64 00001825 */  move  $v1, $zero
/* 0D8598 7F0A3A68 24082110 */  li    $t0, 8464
.L7F0A3A6C:
/* 0D859C 7F0A3A6C 24630001 */  addiu $v1, $v1, 1
/* 0D85A0 7F0A3A70 00801025 */  move  $v0, $a0
/* 0D85A4 7F0A3A74 00037600 */  sll   $t6, $v1, 0x18
/* 0D85A8 7F0A3A78 24840008 */  addiu $a0, $a0, 8
/* 0D85AC 7F0A3A7C 000E1E03 */  sra   $v1, $t6, 0x18
/* 0D85B0 7F0A3A80 AC450004 */  sw    $a1, 4($v0)
/* 0D85B4 7F0A3A84 00803025 */  move  $a2, $a0
/* 0D85B8 7F0A3A88 28610008 */  slti  $at, $v1, 8
/* 0D85BC 7F0A3A8C AC490000 */  sw    $t1, ($v0)
/* 0D85C0 7F0A3A90 ACC80004 */  sw    $t0, 4($a2)
/* 0D85C4 7F0A3A94 ACC70000 */  sw    $a3, ($a2)
/* 0D85C8 7F0A3A98 24840008 */  addiu $a0, $a0, 8
/* 0D85CC 7F0A3A9C 1420FFF3 */  bnez  $at, .L7F0A3A6C
/* 0D85D0 7F0A3AA0 24A50020 */   addiu $a1, $a1, 0x20
.L7F0A3AA4:
/* 0D85D4 7F0A3AA4 3C18B800 */  lui   $t8, 0xb800
/* 0D85D8 7F0A3AA8 AC980000 */  sw    $t8, ($a0)
/* 0D85DC 7F0A3AAC 24820008 */  addiu $v0, $a0, 8
/* 0D85E0 7F0A3AB0 03E00008 */  jr    $ra
/* 0D85E4 7F0A3AB4 AC800004 */   sw    $zero, 4($a0)
)
#endif





#ifdef NONMATCHING
/**
 * Setup watch rectangles in the usual manner.
 * This is called to setup the screen select rectangles, but note
 * that the colors are overwritten in set_page_rectangle_colors.
 * Also used to initialize watch static.
 * @param vtx: Pointer to first vertex in a {@code struct WatchRectangle}.
 * @param startx:
 * @param startz:
 * @param width:
 * @param height:
 * @param horizontal_offset:
 * @param vertical_offset:
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: no
 * - identical registers: fail
 * 
 * Notes: Instruction order is just wrong until the loop starts.
 * There's an extra move instruction.
*/
struct WatchVertex *setup_watch_rectangles(struct WatchVertex *vtx, s32 startx, s32 startz, s32 width, s32 height, s32 horizontal_offset, s32 vertical_offset)
{
    s32 i;
    s32 j;
    s32 xval;
    s32 zval;
    
    xval = startx + horizontal_offset;

    if(vtx); // seems to be needed to match return and last few lines.

    for (i=0; i<2; i++, xval += width)
    {
        zval = startz + vertical_offset;

        for (j=0; j<2; j++, zval += height)
        {
            vtx->coord1.AsArray[0] = xval;
            vtx->coord1.AsArray[1] = 0;
            vtx->coord1.AsArray[2] = zval;

            vtx->coord2.AsArray[0] = 0;
            vtx->coord2.AsArray[1] = 0;
            vtx->coord2.AsArray[2] = 0;

            vtx->color.rgba[0] = 0x20;
            vtx->color.rgba[1] = 0x70;
            vtx->color.rgba[2] = 0x20;
            vtx->color.rgba[3] = 0xF0;

            vtx++;
        }
    }

    return vtx;
}
#else
GLOBAL_ASM(
.text
glabel setup_watch_rectangles
/* 0D85E8 7F0A3AB8 27BDFFF8 */  addiu $sp, $sp, -8
/* 0D85EC 7F0A3ABC 8FAE001C */  lw    $t6, 0x1c($sp)
/* 0D85F0 7F0A3AC0 AFB00004 */  sw    $s0, 4($sp)
/* 0D85F4 7F0A3AC4 24100002 */  li    $s0, 2
/* 0D85F8 7F0A3AC8 00AE4021 */  addu  $t0, $a1, $t6
/* 0D85FC 7F0A3ACC 8FA50018 */  lw    $a1, 0x18($sp)
/* 0D8600 7F0A3AD0 8FA90020 */  lw    $t1, 0x20($sp)
/* 0D8604 7F0A3AD4 00001025 */  move  $v0, $zero
/* 0D8608 7F0A3AD8 240D00F0 */  li    $t5, 240
/* 0D860C 7F0A3ADC 240C0070 */  li    $t4, 112
/* 0D8610 7F0A3AE0 240B0020 */  li    $t3, 32
.L7F0A3AE4:
/* 0D8614 7F0A3AE4 00001825 */  move  $v1, $zero
/* 0D8618 7F0A3AE8 00C95021 */  addu  $t2, $a2, $t1
.L7F0A3AEC:
/* 0D861C 7F0A3AEC 24630001 */  addiu $v1, $v1, 1
/* 0D8620 7F0A3AF0 A48A0004 */  sh    $t2, 4($a0)
/* 0D8624 7F0A3AF4 01455021 */  addu  $t2, $t2, $a1
/* 0D8628 7F0A3AF8 A4880000 */  sh    $t0, ($a0)
/* 0D862C 7F0A3AFC A4800002 */  sh    $zero, 2($a0)
/* 0D8630 7F0A3B00 A4800006 */  sh    $zero, 6($a0)
/* 0D8634 7F0A3B04 A4800008 */  sh    $zero, 8($a0)
/* 0D8638 7F0A3B08 A480000A */  sh    $zero, 0xa($a0)
/* 0D863C 7F0A3B0C A08B000C */  sb    $t3, 0xc($a0)
/* 0D8640 7F0A3B10 A08C000D */  sb    $t4, 0xd($a0)
/* 0D8644 7F0A3B14 A08B000E */  sb    $t3, 0xe($a0)
/* 0D8648 7F0A3B18 A08D000F */  sb    $t5, 0xf($a0)
/* 0D864C 7F0A3B1C 1470FFF3 */  bne   $v1, $s0, .L7F0A3AEC
/* 0D8650 7F0A3B20 24840010 */   addiu $a0, $a0, 0x10
/* 0D8654 7F0A3B24 24420001 */  addiu $v0, $v0, 1
/* 0D8658 7F0A3B28 1450FFEE */  bne   $v0, $s0, .L7F0A3AE4
/* 0D865C 7F0A3B2C 01074021 */   addu  $t0, $t0, $a3
/* 0D8660 7F0A3B30 8FB00004 */  lw    $s0, 4($sp)
/* 0D8664 7F0A3B34 27BD0008 */  addiu $sp, $sp, 8
/* 0D8668 7F0A3B38 03E00008 */  jr    $ra
/* 0D866C 7F0A3B3C 00801025 */   move  $v0, $a0
)
#endif





Gfx *sub_GAME_7F0A3B40(Gfx *gdl, s32 *arg1)
{
    gSPVertex(gdl++, arg1, 4, 0);

    // gfxdis can't parse this, but maybe?: gSPModifyVertex(gdl++, 16, 0, 0x2110);
    // manual specification:
    {								\
        Gfx *_g = (Gfx *)(gdl++);		\
        _g->words.w0 = 0xB1000032;	\
        _g->words.w1 = 0x2110;		\
    }

    return gdl;
}



// unreferenced
void unused_7F0A3B70(s32 arg0, struct rgba_u8 *arg1)
{
    arg1->r = D_80040960[arg0].r;
    arg1->g = D_80040960[arg0].g;
    arg1->b = D_80040960[arg0].b;
    arg1->a = D_80040960[arg0].a;
}





// unreferenced
void unused_7F0A3BA4(s32 arg0, struct rgba_u8 *arg1)
{
    D_80040960[arg0].r = arg1->r;
    D_80040960[arg0].g = arg1->g;
    D_80040960[arg0].b = arg1->b;
    D_80040960[arg0].a = arg1->a;
}


void sub_GAME_7F0A3BD8(void)
{
    s32 i;
    s32 start_index;

    if (1) { start_index = 0; }

    for (i = start_index; (i < UNK_8007A170_MAX) ^ 0; i++)
    {
        dword_CODE_bss_8007A170[i].unk0C = 0;
        dword_CODE_bss_8007A170[i].unk04 = 0;
        dword_CODE_bss_8007A170[i].unk00 = 0;
    }
}


#ifdef NONMATCHING
void sub_GAME_7F0A3C08(void) {

}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.late_rodata
glabel D_80057750
.word 0x40c90fdb /*6.2831855*/
glabel D_80057754
.word 0x3fb501e2 /*1.41412*/
.text
glabel sub_GAME_7F0A3C08
/* 0D8738 7F0A3C08 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0D873C 7F0A3C0C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D8740 7F0A3C10 4487A000 */  mtc1  $a3, $f20
/* 0D8744 7F0A3C14 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D8748 7F0A3C18 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D874C 7F0A3C1C 00808025 */  move  $s0, $a0
/* 0D8750 7F0A3C20 AFA50034 */  sw    $a1, 0x34($sp)
/* 0D8754 7F0A3C24 0C002914 */  jal   randomGetNext
/* 0D8758 7F0A3C28 AFA60038 */   sw    $a2, 0x38($sp)
/* 0D875C 7F0A3C2C 44822000 */  mtc1  $v0, $f4
/* 0D8760 7F0A3C30 8FA50034 */  lw    $a1, 0x34($sp)
/* 0D8764 7F0A3C34 8FA60038 */  lw    $a2, 0x38($sp)
/* 0D8768 7F0A3C38 04410005 */  bgez  $v0, .L7F0A3C50
/* 0D876C 7F0A3C3C 468021A0 */   cvt.s.w $f6, $f4
/* 0D8770 7F0A3C40 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D8774 7F0A3C44 44814000 */  mtc1  $at, $f8
/* 0D8778 7F0A3C48 00000000 */  nop   
/* 0D877C 7F0A3C4C 46083180 */  add.s $f6, $f6, $f8
.L7F0A3C50:
/* 0D8780 7F0A3C50 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D8784 7F0A3C54 44815000 */  mtc1  $at, $f10
/* 0D8788 7F0A3C58 3C018005 */  lui   $at, %hi(D_80057750)
/* 0D878C 7F0A3C5C C4327750 */  lwc1  $f18, %lo(D_80057750)($at)
/* 0D8790 7F0A3C60 460A3402 */  mul.s $f16, $f6, $f10
/* 0D8794 7F0A3C64 24010004 */  li    $at, 4
/* 0D8798 7F0A3C68 240F0001 */  li    $t7, 1
/* 0D879C 7F0A3C6C 46128102 */  mul.s $f4, $f16, $f18
/* 0D87A0 7F0A3C70 E7A4002C */  swc1  $f4, 0x2c($sp)
/* 0D87A4 7F0A3C74 AE000000 */  sw    $zero, ($s0)
/* 0D87A8 7F0A3C78 87AE0042 */  lh    $t6, 0x42($sp)
/* 0D87AC 7F0A3C7C 14C10009 */  bne   $a2, $at, .L7F0A3CA4
/* 0D87B0 7F0A3C80 A60E0006 */   sh    $t6, 6($s0)
/* 0D87B4 7F0A3C84 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D87B8 7F0A3C88 44814000 */  mtc1  $at, $f8
/* 0D87BC 7F0A3C8C A60F0004 */  sh    $t7, 4($s0)
/* 0D87C0 7F0A3C90 3C188009 */  lui   $t8, %hi(flareimage2) 
/* 0D87C4 7F0A3C94 E6080008 */  swc1  $f8, 8($s0)
/* 0D87C8 7F0A3C98 8F18D0CC */  lw    $t8, %lo(flareimage2)($t8)
/* 0D87CC 7F0A3C9C 10000029 */  b     .L7F0A3D44
/* 0D87D0 7F0A3CA0 AE18000C */   sw    $t8, 0xc($s0)
.L7F0A3CA4:
/* 0D87D4 7F0A3CA4 24010001 */  li    $at, 1
/* 0D87D8 7F0A3CA8 14C10009 */  bne   $a2, $at, .L7F0A3CD0
/* 0D87DC 7F0A3CAC 2419000B */   li    $t9, 11
/* 0D87E0 7F0A3CB0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D87E4 7F0A3CB4 44813000 */  mtc1  $at, $f6
/* 0D87E8 7F0A3CB8 A6190004 */  sh    $t9, 4($s0)
/* 0D87EC 7F0A3CBC 3C088009 */  lui   $t0, %hi(explosion_smokeimages) 
/* 0D87F0 7F0A3CC0 E6060008 */  swc1  $f6, 8($s0)
/* 0D87F4 7F0A3CC4 8D08D0C0 */  lw    $t0, %lo(explosion_smokeimages)($t0)
/* 0D87F8 7F0A3CC8 1000001E */  b     .L7F0A3D44
/* 0D87FC 7F0A3CCC AE08000C */   sw    $t0, 0xc($s0)
.L7F0A3CD0:
/* 0D8800 7F0A3CD0 24010003 */  li    $at, 3
/* 0D8804 7F0A3CD4 14C10009 */  bne   $a2, $at, .L7F0A3CFC
/* 0D8808 7F0A3CD8 24090009 */   li    $t1, 9
/* 0D880C 7F0A3CDC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D8810 7F0A3CE0 44815000 */  mtc1  $at, $f10
/* 0D8814 7F0A3CE4 A6090004 */  sh    $t1, 4($s0)
/* 0D8818 7F0A3CE8 3C0A8009 */  lui   $t2, %hi(scattered_explosions) 
/* 0D881C 7F0A3CEC E60A0008 */  swc1  $f10, 8($s0)
/* 0D8820 7F0A3CF0 8D4AD0C4 */  lw    $t2, %lo(scattered_explosions)($t2)
/* 0D8824 7F0A3CF4 10000013 */  b     .L7F0A3D44
/* 0D8828 7F0A3CF8 AE0A000C */   sw    $t2, 0xc($s0)
.L7F0A3CFC:
/* 0D882C 7F0A3CFC 24010006 */  li    $at, 6
/* 0D8830 7F0A3D00 14C10009 */  bne   $a2, $at, .L7F0A3D28
/* 0D8834 7F0A3D04 240D000B */   li    $t5, 11
/* 0D8838 7F0A3D08 44808000 */  mtc1  $zero, $f16
/* 0D883C 7F0A3D0C 240B0064 */  li    $t3, 100
/* 0D8840 7F0A3D10 A60B0004 */  sh    $t3, 4($s0)
/* 0D8844 7F0A3D14 3C0C8009 */  lui   $t4, %hi(flareimage2) 
/* 0D8848 7F0A3D18 E6100008 */  swc1  $f16, 8($s0)
/* 0D884C 7F0A3D1C 8D8CD0CC */  lw    $t4, %lo(flareimage2)($t4)
/* 0D8850 7F0A3D20 10000008 */  b     .L7F0A3D44
/* 0D8854 7F0A3D24 AE0C000C */   sw    $t4, 0xc($s0)
.L7F0A3D28:
/* 0D8858 7F0A3D28 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D885C 7F0A3D2C 44819000 */  mtc1  $at, $f18
/* 0D8860 7F0A3D30 A60D0004 */  sh    $t5, 4($s0)
/* 0D8864 7F0A3D34 3C0E8009 */  lui   $t6, %hi(explosion_smokeimages) 
/* 0D8868 7F0A3D38 E6120008 */  swc1  $f18, 8($s0)
/* 0D886C 7F0A3D3C 8DCED0C0 */  lw    $t6, %lo(explosion_smokeimages)($t6)
/* 0D8870 7F0A3D40 AE0E000C */  sw    $t6, 0xc($s0)
.L7F0A3D44:
/* 0D8874 7F0A3D44 3C188004 */  lui   $t8, %hi(D_80040960) 
/* 0D8878 7F0A3D48 27180960 */  addiu $t8, %lo(D_80040960) # addiu $t8, $t8, 0x960
/* 0D887C 7F0A3D4C 00067880 */  sll   $t7, $a2, 2
/* 0D8880 7F0A3D50 01F81021 */  addu  $v0, $t7, $t8
/* 0D8884 7F0A3D54 90590000 */  lbu   $t9, ($v0)
/* 0D8888 7F0A3D58 A2190028 */  sb    $t9, 0x28($s0)
/* 0D888C 7F0A3D5C 90480001 */  lbu   $t0, 1($v0)
/* 0D8890 7F0A3D60 A2080029 */  sb    $t0, 0x29($s0)
/* 0D8894 7F0A3D64 90490002 */  lbu   $t1, 2($v0)
/* 0D8898 7F0A3D68 A209002A */  sb    $t1, 0x2a($s0)
/* 0D889C 7F0A3D6C 904A0003 */  lbu   $t2, 3($v0)
/* 0D88A0 7F0A3D70 A20A002B */  sb    $t2, 0x2b($s0)
/* 0D88A4 7F0A3D74 C4A40000 */  lwc1  $f4, ($a1)
/* 0D88A8 7F0A3D78 E6040010 */  swc1  $f4, 0x10($s0)
/* 0D88AC 7F0A3D7C C4A80004 */  lwc1  $f8, 4($a1)
/* 0D88B0 7F0A3D80 E6080014 */  swc1  $f8, 0x14($s0)
/* 0D88B4 7F0A3D84 C4A60008 */  lwc1  $f6, 8($a1)
/* 0D88B8 7F0A3D88 0C002914 */  jal   randomGetNext
/* 0D88BC 7F0A3D8C E6060018 */   swc1  $f6, 0x18($s0)
/* 0D88C0 7F0A3D90 44825000 */  mtc1  $v0, $f10
/* 0D88C4 7F0A3D94 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D88C8 7F0A3D98 04410004 */  bgez  $v0, .L7F0A3DAC
/* 0D88CC 7F0A3D9C 46805420 */   cvt.s.w $f16, $f10
/* 0D88D0 7F0A3DA0 44819000 */  mtc1  $at, $f18
/* 0D88D4 7F0A3DA4 00000000 */  nop   
/* 0D88D8 7F0A3DA8 46128400 */  add.s $f16, $f16, $f18
.L7F0A3DAC:
/* 0D88DC 7F0A3DAC 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D88E0 7F0A3DB0 44812000 */  mtc1  $at, $f4
/* 0D88E4 7F0A3DB4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0D88E8 7F0A3DB8 44813000 */  mtc1  $at, $f6
/* 0D88EC 7F0A3DBC 46048202 */  mul.s $f8, $f16, $f4
/* 0D88F0 7F0A3DC0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D88F4 7F0A3DC4 44819000 */  mtc1  $at, $f18
/* 0D88F8 7F0A3DC8 3C018005 */  lui   $at, %hi(D_80057754)
/* 0D88FC 7F0A3DCC C4247754 */  lwc1  $f4, %lo(D_80057754)($at)
/* 0D8900 7F0A3DD0 46064282 */  mul.s $f10, $f8, $f6
/* 0D8904 7F0A3DD4 460A9400 */  add.s $f16, $f18, $f10
/* 0D8908 7F0A3DD8 4610A502 */  mul.s $f20, $f20, $f16
/* 0D890C 7F0A3DDC 00000000 */  nop   
/* 0D8910 7F0A3DE0 4604A502 */  mul.s $f20, $f20, $f4
/* 0D8914 7F0A3DE4 E6140024 */  swc1  $f20, 0x24($s0)
/* 0D8918 7F0A3DE8 0FC15FA8 */  jal   cosf
/* 0D891C 7F0A3DEC C7AC002C */   lwc1  $f12, 0x2c($sp)
/* 0D8920 7F0A3DF0 46140202 */  mul.s $f8, $f0, $f20
/* 0D8924 7F0A3DF4 E608001C */  swc1  $f8, 0x1c($s0)
/* 0D8928 7F0A3DF8 0FC15FAB */  jal   sinf
/* 0D892C 7F0A3DFC C7AC002C */   lwc1  $f12, 0x2c($sp)
/* 0D8930 7F0A3E00 46140182 */  mul.s $f6, $f0, $f20
/* 0D8934 7F0A3E04 E6060020 */  swc1  $f6, 0x20($s0)
/* 0D8938 7F0A3E08 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D893C 7F0A3E0C 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D8940 7F0A3E10 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D8944 7F0A3E14 03E00008 */  jr    $ra
/* 0D8948 7F0A3E18 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(

/* same asm, but float .rodata references other .rodata */

.text
glabel sub_GAME_7F0A3C08
/* 0D8738 7F0A3C08 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0D873C 7F0A3C0C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0D8740 7F0A3C10 4487A000 */  mtc1  $a3, $f20
/* 0D8744 7F0A3C14 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D8748 7F0A3C18 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D874C 7F0A3C1C 00808025 */  move  $s0, $a0
/* 0D8750 7F0A3C20 AFA50034 */  sw    $a1, 0x34($sp)
/* 0D8754 7F0A3C24 0C002914 */  jal   randomGetNext
/* 0D8758 7F0A3C28 AFA60038 */   sw    $a2, 0x38($sp)
/* 0D875C 7F0A3C2C 44822000 */  mtc1  $v0, $f4
/* 0D8760 7F0A3C30 8FA50034 */  lw    $a1, 0x34($sp)
/* 0D8764 7F0A3C34 8FA60038 */  lw    $a2, 0x38($sp)
/* 0D8768 7F0A3C38 04410005 */  bgez  $v0, .L7F0A3C50
/* 0D876C 7F0A3C3C 468021A0 */   cvt.s.w $f6, $f4
/* 0D8770 7F0A3C40 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D8774 7F0A3C44 44814000 */  mtc1  $at, $f8
/* 0D8778 7F0A3C48 00000000 */  nop   
/* 0D877C 7F0A3C4C 46083180 */  add.s $f6, $f6, $f8
.L7F0A3C50:
/* 0D8780 7F0A3C50 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D8784 7F0A3C54 44815000 */  mtc1  $at, $f10
/* 0D8788 7F0A3C58 3C018005 */  lui   $at, %hi(D_8004CE20)
/* 0D878C 7F0A3C5C C4327750 */  lwc1  $f18, %lo(D_8004CE20)($at)
/* 0D8790 7F0A3C60 460A3402 */  mul.s $f16, $f6, $f10
/* 0D8794 7F0A3C64 24010004 */  li    $at, 4
/* 0D8798 7F0A3C68 240F0001 */  li    $t7, 1
/* 0D879C 7F0A3C6C 46128102 */  mul.s $f4, $f16, $f18
/* 0D87A0 7F0A3C70 E7A4002C */  swc1  $f4, 0x2c($sp)
/* 0D87A4 7F0A3C74 AE000000 */  sw    $zero, ($s0)
/* 0D87A8 7F0A3C78 87AE0042 */  lh    $t6, 0x42($sp)
/* 0D87AC 7F0A3C7C 14C10009 */  bne   $a2, $at, .L7F0A3CA4
/* 0D87B0 7F0A3C80 A60E0006 */   sh    $t6, 6($s0)
/* 0D87B4 7F0A3C84 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D87B8 7F0A3C88 44814000 */  mtc1  $at, $f8
/* 0D87BC 7F0A3C8C A60F0004 */  sh    $t7, 4($s0)
/* 0D87C0 7F0A3C90 3C188009 */  lui   $t8, %hi(flareimage2) 
/* 0D87C4 7F0A3C94 E6080008 */  swc1  $f8, 8($s0)
/* 0D87C8 7F0A3C98 8F18D0CC */  lw    $t8, %lo(flareimage2)($t8)
/* 0D87CC 7F0A3C9C 10000029 */  b     .L7F0A3D44
/* 0D87D0 7F0A3CA0 AE18000C */   sw    $t8, 0xc($s0)
.L7F0A3CA4:
/* 0D87D4 7F0A3CA4 24010001 */  li    $at, 1
/* 0D87D8 7F0A3CA8 14C10009 */  bne   $a2, $at, .L7F0A3CD0
/* 0D87DC 7F0A3CAC 2419000B */   li    $t9, 11
/* 0D87E0 7F0A3CB0 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D87E4 7F0A3CB4 44813000 */  mtc1  $at, $f6
/* 0D87E8 7F0A3CB8 A6190004 */  sh    $t9, 4($s0)
/* 0D87EC 7F0A3CBC 3C088009 */  lui   $t0, %hi(explosion_smokeimages) 
/* 0D87F0 7F0A3CC0 E6060008 */  swc1  $f6, 8($s0)
/* 0D87F4 7F0A3CC4 8D08D0C0 */  lw    $t0, %lo(explosion_smokeimages)($t0)
/* 0D87F8 7F0A3CC8 1000001E */  b     .L7F0A3D44
/* 0D87FC 7F0A3CCC AE08000C */   sw    $t0, 0xc($s0)
.L7F0A3CD0:
/* 0D8800 7F0A3CD0 24010003 */  li    $at, 3
/* 0D8804 7F0A3CD4 14C10009 */  bne   $a2, $at, .L7F0A3CFC
/* 0D8808 7F0A3CD8 24090009 */   li    $t1, 9
/* 0D880C 7F0A3CDC 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D8810 7F0A3CE0 44815000 */  mtc1  $at, $f10
/* 0D8814 7F0A3CE4 A6090004 */  sh    $t1, 4($s0)
/* 0D8818 7F0A3CE8 3C0A8009 */  lui   $t2, %hi(scattered_explosions) 
/* 0D881C 7F0A3CEC E60A0008 */  swc1  $f10, 8($s0)
/* 0D8820 7F0A3CF0 8D4AD0C4 */  lw    $t2, %lo(scattered_explosions)($t2)
/* 0D8824 7F0A3CF4 10000013 */  b     .L7F0A3D44
/* 0D8828 7F0A3CF8 AE0A000C */   sw    $t2, 0xc($s0)
.L7F0A3CFC:
/* 0D882C 7F0A3CFC 24010006 */  li    $at, 6
/* 0D8830 7F0A3D00 14C10009 */  bne   $a2, $at, .L7F0A3D28
/* 0D8834 7F0A3D04 240D000B */   li    $t5, 11
/* 0D8838 7F0A3D08 44808000 */  mtc1  $zero, $f16
/* 0D883C 7F0A3D0C 240B0064 */  li    $t3, 100
/* 0D8840 7F0A3D10 A60B0004 */  sh    $t3, 4($s0)
/* 0D8844 7F0A3D14 3C0C8009 */  lui   $t4, %hi(flareimage2) 
/* 0D8848 7F0A3D18 E6100008 */  swc1  $f16, 8($s0)
/* 0D884C 7F0A3D1C 8D8CD0CC */  lw    $t4, %lo(flareimage2)($t4)
/* 0D8850 7F0A3D20 10000008 */  b     .L7F0A3D44
/* 0D8854 7F0A3D24 AE0C000C */   sw    $t4, 0xc($s0)
.L7F0A3D28:
/* 0D8858 7F0A3D28 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0D885C 7F0A3D2C 44819000 */  mtc1  $at, $f18
/* 0D8860 7F0A3D30 A60D0004 */  sh    $t5, 4($s0)
/* 0D8864 7F0A3D34 3C0E8009 */  lui   $t6, %hi(explosion_smokeimages) 
/* 0D8868 7F0A3D38 E6120008 */  swc1  $f18, 8($s0)
/* 0D886C 7F0A3D3C 8DCED0C0 */  lw    $t6, %lo(explosion_smokeimages)($t6)
/* 0D8870 7F0A3D40 AE0E000C */  sw    $t6, 0xc($s0)
.L7F0A3D44:
/* 0D8874 7F0A3D44 3C188004 */  lui   $t8, %hi(D_80040960) 
/* 0D8878 7F0A3D48 27180960 */  addiu $t8, %lo(D_80040960) # addiu $t8, $t8, 0x960
/* 0D887C 7F0A3D4C 00067880 */  sll   $t7, $a2, 2
/* 0D8880 7F0A3D50 01F81021 */  addu  $v0, $t7, $t8
/* 0D8884 7F0A3D54 90590000 */  lbu   $t9, ($v0)
/* 0D8888 7F0A3D58 A2190028 */  sb    $t9, 0x28($s0)
/* 0D888C 7F0A3D5C 90480001 */  lbu   $t0, 1($v0)
/* 0D8890 7F0A3D60 A2080029 */  sb    $t0, 0x29($s0)
/* 0D8894 7F0A3D64 90490002 */  lbu   $t1, 2($v0)
/* 0D8898 7F0A3D68 A209002A */  sb    $t1, 0x2a($s0)
/* 0D889C 7F0A3D6C 904A0003 */  lbu   $t2, 3($v0)
/* 0D88A0 7F0A3D70 A20A002B */  sb    $t2, 0x2b($s0)
/* 0D88A4 7F0A3D74 C4A40000 */  lwc1  $f4, ($a1)
/* 0D88A8 7F0A3D78 E6040010 */  swc1  $f4, 0x10($s0)
/* 0D88AC 7F0A3D7C C4A80004 */  lwc1  $f8, 4($a1)
/* 0D88B0 7F0A3D80 E6080014 */  swc1  $f8, 0x14($s0)
/* 0D88B4 7F0A3D84 C4A60008 */  lwc1  $f6, 8($a1)
/* 0D88B8 7F0A3D88 0C002914 */  jal   randomGetNext
/* 0D88BC 7F0A3D8C E6060018 */   swc1  $f6, 0x18($s0)
/* 0D88C0 7F0A3D90 44825000 */  mtc1  $v0, $f10
/* 0D88C4 7F0A3D94 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0D88C8 7F0A3D98 04410004 */  bgez  $v0, .L7F0A3DAC
/* 0D88CC 7F0A3D9C 46805420 */   cvt.s.w $f16, $f10
/* 0D88D0 7F0A3DA0 44819000 */  mtc1  $at, $f18
/* 0D88D4 7F0A3DA4 00000000 */  nop   
/* 0D88D8 7F0A3DA8 46128400 */  add.s $f16, $f16, $f18
.L7F0A3DAC:
/* 0D88DC 7F0A3DAC 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0D88E0 7F0A3DB0 44812000 */  mtc1  $at, $f4
/* 0D88E4 7F0A3DB4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0D88E8 7F0A3DB8 44813000 */  mtc1  $at, $f6
/* 0D88EC 7F0A3DBC 46048202 */  mul.s $f8, $f16, $f4
/* 0D88F0 7F0A3DC0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0D88F4 7F0A3DC4 44819000 */  mtc1  $at, $f18
/* 0D88F8 7F0A3DC8 3C018005 */  lui   $at, %hi(D_8005774C)
/* 0D88FC 7F0A3DCC C4247754 */  lwc1  $f4, %lo(D_8005774C)($at)
/* 0D8900 7F0A3DD0 46064282 */  mul.s $f10, $f8, $f6
/* 0D8904 7F0A3DD4 460A9400 */  add.s $f16, $f18, $f10
/* 0D8908 7F0A3DD8 4610A502 */  mul.s $f20, $f20, $f16
/* 0D890C 7F0A3DDC 00000000 */  nop   
/* 0D8910 7F0A3DE0 4604A502 */  mul.s $f20, $f20, $f4
/* 0D8914 7F0A3DE4 E6140024 */  swc1  $f20, 0x24($s0)
/* 0D8918 7F0A3DE8 0FC15FA8 */  jal   cosf
/* 0D891C 7F0A3DEC C7AC002C */   lwc1  $f12, 0x2c($sp)
/* 0D8920 7F0A3DF0 46140202 */  mul.s $f8, $f0, $f20
/* 0D8924 7F0A3DF4 E608001C */  swc1  $f8, 0x1c($s0)
/* 0D8928 7F0A3DF8 0FC15FAB */  jal   sinf
/* 0D892C 7F0A3DFC C7AC002C */   lwc1  $f12, 0x2c($sp)
/* 0D8930 7F0A3E00 46140182 */  mul.s $f6, $f0, $f20
/* 0D8934 7F0A3E04 E6060020 */  swc1  $f6, 0x20($s0)
/* 0D8938 7F0A3E08 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D893C 7F0A3E0C 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D8940 7F0A3E10 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0D8944 7F0A3E14 03E00008 */  jr    $ra
/* 0D8948 7F0A3E18 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A3E1C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A3E1C
/* 0D894C 7F0A3E1C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0D8950 7F0A3E20 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D8954 7F0A3E24 44866000 */  mtc1  $a2, $f12
/* 0D8958 7F0A3E28 3C108008 */  lui   $s0, %hi(dword_CODE_bss_8007A170)
/* 0D895C 7F0A3E2C 3C028008 */  lui   $v0, %hi(dword_CODE_bss_8007A170 + 0x370)
/* 0D8960 7F0A3E30 00A03025 */  move  $a2, $a1
/* 0D8964 7F0A3E34 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D8968 7F0A3E38 AFA40028 */  sw    $a0, 0x28($sp)
/* 0D896C 7F0A3E3C AFA5002C */  sw    $a1, 0x2c($sp)
/* 0D8970 7F0A3E40 AFA70034 */  sw    $a3, 0x34($sp)
/* 0D8974 7F0A3E44 2442A4E0 */  addiu $v0, %lo(dword_CODE_bss_8007A170 + 0x370) # addiu $v0, $v0, -0x5b20
/* 0D8978 7F0A3E48 2610A170 */  addiu $s0, %lo(dword_CODE_bss_8007A170) # addiu $s0, $s0, -0x5e90
/* 0D897C 7F0A3E4C 860E0004 */  lh    $t6, 4($s0)
.L7F0A3E50:
/* 0D8980 7F0A3E50 55C0000A */  bnezl $t6, .L7F0A3E7C
/* 0D8984 7F0A3E54 2610002C */   addiu $s0, $s0, 0x2c
/* 0D8988 7F0A3E58 87AF0036 */  lh    $t7, 0x36($sp)
/* 0D898C 7F0A3E5C 44076000 */  mfc1  $a3, $f12
/* 0D8990 7F0A3E60 02002025 */  move  $a0, $s0
/* 0D8994 7F0A3E64 8FA50028 */  lw    $a1, 0x28($sp)
/* 0D8998 7F0A3E68 0FC28F02 */  jal   sub_GAME_7F0A3C08
/* 0D899C 7F0A3E6C AFAF0010 */   sw    $t7, 0x10($sp)
/* 0D89A0 7F0A3E70 10000006 */  b     .L7F0A3E8C
/* 0D89A4 7F0A3E74 02001025 */   move  $v0, $s0
/* 0D89A8 7F0A3E78 2610002C */  addiu $s0, $s0, 0x2c
.L7F0A3E7C:
/* 0D89AC 7F0A3E7C 0202082B */  sltu  $at, $s0, $v0
/* 0D89B0 7F0A3E80 5420FFF3 */  bnezl $at, .L7F0A3E50
/* 0D89B4 7F0A3E84 860E0004 */   lh    $t6, 4($s0)
/* 0D89B8 7F0A3E88 00001025 */  move  $v0, $zero
.L7F0A3E8C:
/* 0D89BC 7F0A3E8C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D89C0 7F0A3E90 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D89C4 7F0A3E94 27BD0028 */  addiu $sp, $sp, 0x28
/* 0D89C8 7F0A3E98 03E00008 */  jr    $ra
/* 0D89CC 7F0A3E9C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
// not close to matching but functionally equivalent
void sub_GAME_7F0A3EA0(void)
{
    s32 i;

    for (i = 0; (i < UNK_8007A170_MAX); i++)
    {
        if (dword_CODE_bss_8007A170[i].unk04 <= 0) { continue; }

        dword_CODE_bss_8007A170[i].unk00 += g_ClockTimer;

        if ((dword_CODE_bss_8007A170[i].unk00 >= 0) && (dword_CODE_bss_8007A170[i].unk00 >= dword_CODE_bss_8007A170[i].unk04)) {
            dword_CODE_bss_8007A170[i].unk04 = 0;
        }
    }
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A3EA0
/* 0D89D0 7F0A3EA0 3C028008 */  lui   $v0, %hi(dword_CODE_bss_8007A170)
/* 0D89D4 7F0A3EA4 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007A170 + 0x370)
/* 0D89D8 7F0A3EA8 3C058005 */  lui   $a1, %hi(g_ClockTimer)
/* 0D89DC 7F0A3EAC 2463A4E0 */  addiu $v1, %lo(dword_CODE_bss_8007A170 + 0x370) # addiu $v1, $v1, -0x5b20
/* 0D89E0 7F0A3EB0 2442A170 */  addiu $v0, %lo(dword_CODE_bss_8007A170) # addiu $v0, $v0, -0x5e90
/* 0D89E4 7F0A3EB4 24A58374 */  addiu $a1, %lo(g_ClockTimer) # addiu $a1, $a1, -0x7c8c
/* 0D89E8 7F0A3EB8 844E0004 */  lh    $t6, 4($v0)
.L7F0A3EBC:
/* 0D89EC 7F0A3EBC 59C0000C */  blezl $t6, .L7F0A3EF0
/* 0D89F0 7F0A3EC0 2442002C */   addiu $v0, $v0, 0x2c
/* 0D89F4 7F0A3EC4 8C4F0000 */  lw    $t7, ($v0)
/* 0D89F8 7F0A3EC8 8CB80000 */  lw    $t8, ($a1)
/* 0D89FC 7F0A3ECC 01F8C821 */  addu  $t9, $t7, $t8
/* 0D8A00 7F0A3ED0 07200006 */  bltz  $t9, .L7F0A3EEC
/* 0D8A04 7F0A3ED4 AC590000 */   sw    $t9, ($v0)
/* 0D8A08 7F0A3ED8 84480004 */  lh    $t0, 4($v0)
/* 0D8A0C 7F0A3EDC 0328082A */  slt   $at, $t9, $t0
/* 0D8A10 7F0A3EE0 54200003 */  bnezl $at, .L7F0A3EF0
/* 0D8A14 7F0A3EE4 2442002C */   addiu $v0, $v0, 0x2c
/* 0D8A18 7F0A3EE8 A4400004 */  sh    $zero, 4($v0)
.L7F0A3EEC:
/* 0D8A1C 7F0A3EEC 2442002C */  addiu $v0, $v0, 0x2c
.L7F0A3EF0:
/* 0D8A20 7F0A3EF0 0043082B */  sltu  $at, $v0, $v1
/* 0D8A24 7F0A3EF4 5420FFF1 */  bnezl $at, .L7F0A3EBC
/* 0D8A28 7F0A3EF8 844E0004 */   lh    $t6, 4($v0)
/* 0D8A2C 7F0A3EFC 03E00008 */  jr    $ra
/* 0D8A30 7F0A3F00 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A3F04(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A3F04
/* 0D8A34 7F0A3F04 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0D8A38 7F0A3F08 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0D8A3C 7F0A3F0C AFB20028 */  sw    $s2, 0x28($sp)
/* 0D8A40 7F0A3F10 AFB10024 */  sw    $s1, 0x24($sp)
/* 0D8A44 7F0A3F14 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D8A48 7F0A3F18 AFA500BC */  sw    $a1, 0xbc($sp)
/* 0D8A4C 7F0A3F1C AFA600C0 */  sw    $a2, 0xc0($sp)
/* 0D8A50 7F0A3F20 848E0004 */  lh    $t6, 4($a0)
/* 0D8A54 7F0A3F24 00808025 */  move  $s0, $a0
/* 0D8A58 7F0A3F28 59C0017A */  blezl $t6, .L7F0A4514
/* 0D8A5C 7F0A3F2C 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0D8A60 7F0A3F30 8C8F0000 */  lw    $t7, ($a0)
/* 0D8A64 7F0A3F34 24840010 */  addiu $a0, $a0, 0x10
/* 0D8A68 7F0A3F38 05E20176 */  bltzl $t7, .L7F0A4514
/* 0D8A6C 7F0A3F3C 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0D8A70 7F0A3F40 0FC1E296 */  jal   sub_GAME_7F078A58
/* 0D8A74 7F0A3F44 8E050024 */   lw    $a1, 0x24($s0)
/* 0D8A78 7F0A3F48 10400171 */  beqz  $v0, .L7F0A4510
/* 0D8A7C 7F0A3F4C 3C198004 */   lui   $t9, %hi(D_80040980) 
/* 0D8A80 7F0A3F50 27390980 */  addiu $t9, %lo(D_80040980) # addiu $t9, $t9, 0x980
/* 0D8A84 7F0A3F54 8F210000 */  lw    $at, ($t9)
/* 0D8A88 7F0A3F58 8F290004 */  lw    $t1, 4($t9)
/* 0D8A8C 7F0A3F5C 27B800A8 */  addiu $t8, $sp, 0xa8
/* 0D8A90 7F0A3F60 AF010000 */  sw    $at, ($t8)
/* 0D8A94 7F0A3F64 AF090004 */  sw    $t1, 4($t8)
/* 0D8A98 7F0A3F68 8F29000C */  lw    $t1, 0xc($t9)
/* 0D8A9C 7F0A3F6C 8F210008 */  lw    $at, 8($t9)
/* 0D8AA0 7F0A3F70 AF09000C */  sw    $t1, 0xc($t8)
/* 0D8AA4 7F0A3F74 0FC1E111 */  jal   currentPlayerGetMatrix10D4
/* 0D8AA8 7F0A3F78 AF010008 */   sw    $at, 8($t8)
/* 0D8AAC 7F0A3F7C 8FAA00BC */  lw    $t2, 0xbc($sp)
/* 0D8AB0 7F0A3F80 24040004 */  li    $a0, 4
/* 0D8AB4 7F0A3F84 8D4B0000 */  lw    $t3, ($t2)
/* 0D8AB8 7F0A3F88 AFA200A4 */  sw    $v0, 0xa4($sp)
/* 0D8ABC 7F0A3F8C 0FC2F5B1 */  jal   dynAllocate7F0BD6C4
/* 0D8AC0 7F0A3F90 AFAB00A0 */   sw    $t3, 0xa0($sp)
/* 0D8AC4 7F0A3F94 86040006 */  lh    $a0, 6($s0)
/* 0D8AC8 7F0A3F98 00408825 */  move  $s1, $v0
/* 0D8ACC 7F0A3F9C 0FC2F285 */  jal   getRoomIndexPOS
/* 0D8AD0 7F0A3FA0 AFA40058 */   sw    $a0, 0x58($sp)
/* 0D8AD4 7F0A3FA4 920C0028 */  lbu   $t4, 0x28($s0)
/* 0D8AD8 7F0A3FA8 8FA300A4 */  lw    $v1, 0xa4($sp)
/* 0D8ADC 7F0A3FAC 00409025 */  move  $s2, $v0
/* 0D8AE0 7F0A3FB0 A3AC00B4 */  sb    $t4, 0xb4($sp)
/* 0D8AE4 7F0A3FB4 920D0029 */  lbu   $t5, 0x29($s0)
/* 0D8AE8 7F0A3FB8 27A200A8 */  addiu $v0, $sp, 0xa8
/* 0D8AEC 7F0A3FBC A3AD00B5 */  sb    $t5, 0xb5($sp)
/* 0D8AF0 7F0A3FC0 920E002A */  lbu   $t6, 0x2a($s0)
/* 0D8AF4 7F0A3FC4 A3AE00B6 */  sb    $t6, 0xb6($sp)
/* 0D8AF8 7F0A3FC8 920F002B */  lbu   $t7, 0x2b($s0)
/* 0D8AFC 7F0A3FCC A3AF00B7 */  sb    $t7, 0xb7($sp)
/* 0D8B00 7F0A3FD0 8E080000 */  lw    $t0, ($s0)
/* 0D8B04 7F0A3FD4 C6080008 */  lwc1  $f8, 8($s0)
/* 0D8B08 7F0A3FD8 44882000 */  mtc1  $t0, $f4
/* 0D8B0C 7F0A3FDC 00000000 */  nop   
/* 0D8B10 7F0A3FE0 468021A0 */  cvt.s.w $f6, $f4
/* 0D8B14 7F0A3FE4 46083282 */  mul.s $f10, $f6, $f8
/* 0D8B18 7F0A3FE8 4600540D */  trunc.w.s $f16, $f10
/* 0D8B1C 7F0A3FEC 44198000 */  mfc1  $t9, $f16
/* 0D8B20 7F0A3FF0 00000000 */  nop   
/* 0D8B24 7F0A3FF4 AFB9005C */  sw    $t9, 0x5c($sp)
/* 0D8B28 7F0A3FF8 C6120010 */  lwc1  $f18, 0x10($s0)
/* 0D8B2C 7F0A3FFC E7B20090 */  swc1  $f18, 0x90($sp)
/* 0D8B30 7F0A4000 C6040014 */  lwc1  $f4, 0x14($s0)
/* 0D8B34 7F0A4004 E7A40094 */  swc1  $f4, 0x94($sp)
/* 0D8B38 7F0A4008 C6060018 */  lwc1  $f6, 0x18($s0)
/* 0D8B3C 7F0A400C E7A60098 */  swc1  $f6, 0x98($sp)
/* 0D8B40 7F0A4010 C60A001C */  lwc1  $f10, 0x1c($s0)
/* 0D8B44 7F0A4014 C4680000 */  lwc1  $f8, ($v1)
/* 0D8B48 7F0A4018 460A4402 */  mul.s $f16, $f8, $f10
/* 0D8B4C 7F0A401C E7B00084 */  swc1  $f16, 0x84($sp)
/* 0D8B50 7F0A4020 C604001C */  lwc1  $f4, 0x1c($s0)
/* 0D8B54 7F0A4024 C4720004 */  lwc1  $f18, 4($v1)
/* 0D8B58 7F0A4028 46049182 */  mul.s $f6, $f18, $f4
/* 0D8B5C 7F0A402C E7A60088 */  swc1  $f6, 0x88($sp)
/* 0D8B60 7F0A4030 C60A001C */  lwc1  $f10, 0x1c($s0)
/* 0D8B64 7F0A4034 C4680008 */  lwc1  $f8, 8($v1)
/* 0D8B68 7F0A4038 460A4402 */  mul.s $f16, $f8, $f10
/* 0D8B6C 7F0A403C E7B0008C */  swc1  $f16, 0x8c($sp)
/* 0D8B70 7F0A4040 C6040020 */  lwc1  $f4, 0x20($s0)
/* 0D8B74 7F0A4044 C4720000 */  lwc1  $f18, ($v1)
/* 0D8B78 7F0A4048 46049182 */  mul.s $f6, $f18, $f4
/* 0D8B7C 7F0A404C E7A60078 */  swc1  $f6, 0x78($sp)
/* 0D8B80 7F0A4050 C60A0020 */  lwc1  $f10, 0x20($s0)
/* 0D8B84 7F0A4054 C4680004 */  lwc1  $f8, 4($v1)
/* 0D8B88 7F0A4058 460A4402 */  mul.s $f16, $f8, $f10
/* 0D8B8C 7F0A405C E7B0007C */  swc1  $f16, 0x7c($sp)
/* 0D8B90 7F0A4060 C6040020 */  lwc1  $f4, 0x20($s0)
/* 0D8B94 7F0A4064 C4720008 */  lwc1  $f18, 8($v1)
/* 0D8B98 7F0A4068 46049182 */  mul.s $f6, $f18, $f4
/* 0D8B9C 7F0A406C E7A60080 */  swc1  $f6, 0x80($sp)
/* 0D8BA0 7F0A4070 C60A001C */  lwc1  $f10, 0x1c($s0)
/* 0D8BA4 7F0A4074 C4680010 */  lwc1  $f8, 0x10($v1)
/* 0D8BA8 7F0A4078 460A4402 */  mul.s $f16, $f8, $f10
/* 0D8BAC 7F0A407C E7B0006C */  swc1  $f16, 0x6c($sp)
/* 0D8BB0 7F0A4080 C604001C */  lwc1  $f4, 0x1c($s0)
/* 0D8BB4 7F0A4084 C4720014 */  lwc1  $f18, 0x14($v1)
/* 0D8BB8 7F0A4088 46049182 */  mul.s $f6, $f18, $f4
/* 0D8BBC 7F0A408C E7A60070 */  swc1  $f6, 0x70($sp)
/* 0D8BC0 7F0A4090 C60A001C */  lwc1  $f10, 0x1c($s0)
/* 0D8BC4 7F0A4094 C4680018 */  lwc1  $f8, 0x18($v1)
/* 0D8BC8 7F0A4098 460A4402 */  mul.s $f16, $f8, $f10
/* 0D8BCC 7F0A409C E7B00074 */  swc1  $f16, 0x74($sp)
/* 0D8BD0 7F0A40A0 C6040020 */  lwc1  $f4, 0x20($s0)
/* 0D8BD4 7F0A40A4 C4720010 */  lwc1  $f18, 0x10($v1)
/* 0D8BD8 7F0A40A8 46049182 */  mul.s $f6, $f18, $f4
/* 0D8BDC 7F0A40AC E7A60060 */  swc1  $f6, 0x60($sp)
/* 0D8BE0 7F0A40B0 C60A0020 */  lwc1  $f10, 0x20($s0)
/* 0D8BE4 7F0A40B4 C4680014 */  lwc1  $f8, 0x14($v1)
/* 0D8BE8 7F0A40B8 460A4402 */  mul.s $f16, $f8, $f10
/* 0D8BEC 7F0A40BC E7B00064 */  swc1  $f16, 0x64($sp)
/* 0D8BF0 7F0A40C0 C6040020 */  lwc1  $f4, 0x20($s0)
/* 0D8BF4 7F0A40C4 C4720018 */  lwc1  $f18, 0x18($v1)
/* 0D8BF8 7F0A40C8 46049182 */  mul.s $f6, $f18, $f4
/* 0D8BFC 7F0A40CC E7A60068 */  swc1  $f6, 0x68($sp)
/* 0D8C00 7F0A40D0 8C410000 */  lw    $at, ($v0)
/* 0D8C04 7F0A40D4 AE210000 */  sw    $at, ($s1)
/* 0D8C08 7F0A40D8 8C4B0004 */  lw    $t3, 4($v0)
/* 0D8C0C 7F0A40DC AE2B0004 */  sw    $t3, 4($s1)
/* 0D8C10 7F0A40E0 8C410008 */  lw    $at, 8($v0)
/* 0D8C14 7F0A40E4 AE210008 */  sw    $at, 8($s1)
/* 0D8C18 7F0A40E8 8C4B000C */  lw    $t3, 0xc($v0)
/* 0D8C1C 7F0A40EC AE2B000C */  sw    $t3, 0xc($s1)
/* 0D8C20 7F0A40F0 8C410000 */  lw    $at, ($v0)
/* 0D8C24 7F0A40F4 AE210010 */  sw    $at, 0x10($s1)
/* 0D8C28 7F0A40F8 8C4E0004 */  lw    $t6, 4($v0)
/* 0D8C2C 7F0A40FC AE2E0014 */  sw    $t6, 0x14($s1)
/* 0D8C30 7F0A4100 8C410008 */  lw    $at, 8($v0)
/* 0D8C34 7F0A4104 AE210018 */  sw    $at, 0x18($s1)
/* 0D8C38 7F0A4108 8C4E000C */  lw    $t6, 0xc($v0)
/* 0D8C3C 7F0A410C AE2E001C */  sw    $t6, 0x1c($s1)
/* 0D8C40 7F0A4110 8C410000 */  lw    $at, ($v0)
/* 0D8C44 7F0A4114 AE210020 */  sw    $at, 0x20($s1)
/* 0D8C48 7F0A4118 8C580004 */  lw    $t8, 4($v0)
/* 0D8C4C 7F0A411C AE380024 */  sw    $t8, 0x24($s1)
/* 0D8C50 7F0A4120 8C410008 */  lw    $at, 8($v0)
/* 0D8C54 7F0A4124 AE210028 */  sw    $at, 0x28($s1)
/* 0D8C58 7F0A4128 8C58000C */  lw    $t8, 0xc($v0)
/* 0D8C5C 7F0A412C AE38002C */  sw    $t8, 0x2c($s1)
/* 0D8C60 7F0A4130 8C410000 */  lw    $at, ($v0)
/* 0D8C64 7F0A4134 AE210030 */  sw    $at, 0x30($s1)
/* 0D8C68 7F0A4138 8C490004 */  lw    $t1, 4($v0)
/* 0D8C6C 7F0A413C AE290034 */  sw    $t1, 0x34($s1)
/* 0D8C70 7F0A4140 8C410008 */  lw    $at, 8($v0)
/* 0D8C74 7F0A4144 AE210038 */  sw    $at, 0x38($s1)
/* 0D8C78 7F0A4148 8C49000C */  lw    $t1, 0xc($v0)
/* 0D8C7C 7F0A414C 0FC2D20F */  jal   get_room_data_float1
/* 0D8C80 7F0A4150 AE29003C */   sw    $t1, 0x3c($s1)
/* 0D8C84 7F0A4154 C7A80090 */  lwc1  $f8, 0x90($sp)
/* 0D8C88 7F0A4158 C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 0D8C8C 7F0A415C C7B20060 */  lwc1  $f18, 0x60($sp)
/* 0D8C90 7F0A4160 460A4401 */  sub.s $f16, $f8, $f10
/* 0D8C94 7F0A4164 C6480000 */  lwc1  $f8, ($s2)
/* 0D8C98 7F0A4168 46128101 */  sub.s $f4, $f16, $f18
/* 0D8C9C 7F0A416C 46002182 */  mul.s $f6, $f4, $f0
/* 0D8CA0 7F0A4170 46083281 */  sub.s $f10, $f6, $f8
/* 0D8CA4 7F0A4174 4600540D */  trunc.w.s $f16, $f10
/* 0D8CA8 7F0A4178 440D8000 */  mfc1  $t5, $f16
/* 0D8CAC 7F0A417C 0FC2D20F */  jal   get_room_data_float1
/* 0D8CB0 7F0A4180 A62D0000 */   sh    $t5, ($s1)
/* 0D8CB4 7F0A4184 C7B20094 */  lwc1  $f18, 0x94($sp)
/* 0D8CB8 7F0A4188 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0D8CBC 7F0A418C C7A80064 */  lwc1  $f8, 0x64($sp)
/* 0D8CC0 7F0A4190 46049181 */  sub.s $f6, $f18, $f4
/* 0D8CC4 7F0A4194 C6520004 */  lwc1  $f18, 4($s2)
/* 0D8CC8 7F0A4198 46083281 */  sub.s $f10, $f6, $f8
/* 0D8CCC 7F0A419C 46005402 */  mul.s $f16, $f10, $f0
/* 0D8CD0 7F0A41A0 46128101 */  sub.s $f4, $f16, $f18
/* 0D8CD4 7F0A41A4 4600218D */  trunc.w.s $f6, $f4
/* 0D8CD8 7F0A41A8 440E3000 */  mfc1  $t6, $f6
/* 0D8CDC 7F0A41AC 0FC2D20F */  jal   get_room_data_float1
/* 0D8CE0 7F0A41B0 A62E0002 */   sh    $t6, 2($s1)
/* 0D8CE4 7F0A41B4 C7A80098 */  lwc1  $f8, 0x98($sp)
/* 0D8CE8 7F0A41B8 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0D8CEC 7F0A41BC C7B20068 */  lwc1  $f18, 0x68($sp)
/* 0D8CF0 7F0A41C0 460A4401 */  sub.s $f16, $f8, $f10
/* 0D8CF4 7F0A41C4 C6480008 */  lwc1  $f8, 8($s2)
/* 0D8CF8 7F0A41C8 46128101 */  sub.s $f4, $f16, $f18
/* 0D8CFC 7F0A41CC 46002182 */  mul.s $f6, $f4, $f0
/* 0D8D00 7F0A41D0 46083281 */  sub.s $f10, $f6, $f8
/* 0D8D04 7F0A41D4 4600540D */  trunc.w.s $f16, $f10
/* 0D8D08 7F0A41D8 440F8000 */  mfc1  $t7, $f16
/* 0D8D0C 7F0A41DC 00000000 */  nop   
/* 0D8D10 7F0A41E0 A62F0004 */  sh    $t7, 4($s1)
/* 0D8D14 7F0A41E4 8FA2005C */  lw    $v0, 0x5c($sp)
/* 0D8D18 7F0A41E8 8E0A000C */  lw    $t2, 0xc($s0)
/* 0D8D1C 7F0A41EC 0002C080 */  sll   $t8, $v0, 2
/* 0D8D20 7F0A41F0 0302C023 */  subu  $t8, $t8, $v0
/* 0D8D24 7F0A41F4 0018C080 */  sll   $t8, $t8, 2
/* 0D8D28 7F0A41F8 0158C821 */  addu  $t9, $t2, $t8
/* 0D8D2C 7F0A41FC 93290004 */  lbu   $t1, 4($t9)
/* 0D8D30 7F0A4200 A620000A */  sh    $zero, 0xa($s1)
/* 0D8D34 7F0A4204 00095940 */  sll   $t3, $t1, 5
/* 0D8D38 7F0A4208 A62B0008 */  sh    $t3, 8($s1)
/* 0D8D3C 7F0A420C 0FC2D20F */  jal   get_room_data_float1
/* 0D8D40 7F0A4210 AFB80034 */   sw    $t8, 0x34($sp)
/* 0D8D44 7F0A4214 C7B20090 */  lwc1  $f18, 0x90($sp)
/* 0D8D48 7F0A4218 C7A40078 */  lwc1  $f4, 0x78($sp)
/* 0D8D4C 7F0A421C C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 0D8D50 7F0A4220 46049180 */  add.s $f6, $f18, $f4
/* 0D8D54 7F0A4224 C6520000 */  lwc1  $f18, ($s2)
/* 0D8D58 7F0A4228 46083281 */  sub.s $f10, $f6, $f8
/* 0D8D5C 7F0A422C 46005402 */  mul.s $f16, $f10, $f0
/* 0D8D60 7F0A4230 46128101 */  sub.s $f4, $f16, $f18
/* 0D8D64 7F0A4234 4600218D */  trunc.w.s $f6, $f4
/* 0D8D68 7F0A4238 440C3000 */  mfc1  $t4, $f6
/* 0D8D6C 7F0A423C 0FC2D20F */  jal   get_room_data_float1
/* 0D8D70 7F0A4240 A62C0010 */   sh    $t4, 0x10($s1)
/* 0D8D74 7F0A4244 C7A80094 */  lwc1  $f8, 0x94($sp)
/* 0D8D78 7F0A4248 C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 0D8D7C 7F0A424C C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0D8D80 7F0A4250 460A4400 */  add.s $f16, $f8, $f10
/* 0D8D84 7F0A4254 C6480004 */  lwc1  $f8, 4($s2)
/* 0D8D88 7F0A4258 46128101 */  sub.s $f4, $f16, $f18
/* 0D8D8C 7F0A425C 46002182 */  mul.s $f6, $f4, $f0
/* 0D8D90 7F0A4260 46083281 */  sub.s $f10, $f6, $f8
/* 0D8D94 7F0A4264 4600540D */  trunc.w.s $f16, $f10
/* 0D8D98 7F0A4268 44088000 */  mfc1  $t0, $f16
/* 0D8D9C 7F0A426C 0FC2D20F */  jal   get_room_data_float1
/* 0D8DA0 7F0A4270 A6280012 */   sh    $t0, 0x12($s1)
/* 0D8DA4 7F0A4274 C7B20098 */  lwc1  $f18, 0x98($sp)
/* 0D8DA8 7F0A4278 C7A40080 */  lwc1  $f4, 0x80($sp)
/* 0D8DAC 7F0A427C C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0D8DB0 7F0A4280 46049180 */  add.s $f6, $f18, $f4
/* 0D8DB4 7F0A4284 C6520008 */  lwc1  $f18, 8($s2)
/* 0D8DB8 7F0A4288 A6200018 */  sh    $zero, 0x18($s1)
/* 0D8DBC 7F0A428C A620001A */  sh    $zero, 0x1a($s1)
/* 0D8DC0 7F0A4290 46083281 */  sub.s $f10, $f6, $f8
/* 0D8DC4 7F0A4294 46005402 */  mul.s $f16, $f10, $f0
/* 0D8DC8 7F0A4298 46128101 */  sub.s $f4, $f16, $f18
/* 0D8DCC 7F0A429C 4600218D */  trunc.w.s $f6, $f4
/* 0D8DD0 7F0A42A0 44183000 */  mfc1  $t8, $f6
/* 0D8DD4 7F0A42A4 0FC2D20F */  jal   get_room_data_float1
/* 0D8DD8 7F0A42A8 A6380014 */   sh    $t8, 0x14($s1)
/* 0D8DDC 7F0A42AC C7A80090 */  lwc1  $f8, 0x90($sp)
/* 0D8DE0 7F0A42B0 C7AA0084 */  lwc1  $f10, 0x84($sp)
/* 0D8DE4 7F0A42B4 C7B20060 */  lwc1  $f18, 0x60($sp)
/* 0D8DE8 7F0A42B8 460A4400 */  add.s $f16, $f8, $f10
/* 0D8DEC 7F0A42BC C6480000 */  lwc1  $f8, ($s2)
/* 0D8DF0 7F0A42C0 46128100 */  add.s $f4, $f16, $f18
/* 0D8DF4 7F0A42C4 46002182 */  mul.s $f6, $f4, $f0
/* 0D8DF8 7F0A42C8 46083281 */  sub.s $f10, $f6, $f8
/* 0D8DFC 7F0A42CC 4600540D */  trunc.w.s $f16, $f10
/* 0D8E00 7F0A42D0 44198000 */  mfc1  $t9, $f16
/* 0D8E04 7F0A42D4 0FC2D20F */  jal   get_room_data_float1
/* 0D8E08 7F0A42D8 A6390020 */   sh    $t9, 0x20($s1)
/* 0D8E0C 7F0A42DC C7B20094 */  lwc1  $f18, 0x94($sp)
/* 0D8E10 7F0A42E0 C7A40088 */  lwc1  $f4, 0x88($sp)
/* 0D8E14 7F0A42E4 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 0D8E18 7F0A42E8 46049180 */  add.s $f6, $f18, $f4
/* 0D8E1C 7F0A42EC C6520004 */  lwc1  $f18, 4($s2)
/* 0D8E20 7F0A42F0 46083280 */  add.s $f10, $f6, $f8
/* 0D8E24 7F0A42F4 46005402 */  mul.s $f16, $f10, $f0
/* 0D8E28 7F0A42F8 46128101 */  sub.s $f4, $f16, $f18
/* 0D8E2C 7F0A42FC 4600218D */  trunc.w.s $f6, $f4
/* 0D8E30 7F0A4300 440B3000 */  mfc1  $t3, $f6
/* 0D8E34 7F0A4304 0FC2D20F */  jal   get_room_data_float1
/* 0D8E38 7F0A4308 A62B0022 */   sh    $t3, 0x22($s1)
/* 0D8E3C 7F0A430C C7A80098 */  lwc1  $f8, 0x98($sp)
/* 0D8E40 7F0A4310 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 0D8E44 7F0A4314 C7B20068 */  lwc1  $f18, 0x68($sp)
/* 0D8E48 7F0A4318 460A4400 */  add.s $f16, $f8, $f10
/* 0D8E4C 7F0A431C C6480008 */  lwc1  $f8, 8($s2)
/* 0D8E50 7F0A4320 A6200028 */  sh    $zero, 0x28($s1)
/* 0D8E54 7F0A4324 46128100 */  add.s $f4, $f16, $f18
/* 0D8E58 7F0A4328 46002182 */  mul.s $f6, $f4, $f0
/* 0D8E5C 7F0A432C 46083281 */  sub.s $f10, $f6, $f8
/* 0D8E60 7F0A4330 4600540D */  trunc.w.s $f16, $f10
/* 0D8E64 7F0A4334 440C8000 */  mfc1  $t4, $f16
/* 0D8E68 7F0A4338 00000000 */  nop   
/* 0D8E6C 7F0A433C A62C0024 */  sh    $t4, 0x24($s1)
/* 0D8E70 7F0A4340 8FA80034 */  lw    $t0, 0x34($sp)
/* 0D8E74 7F0A4344 8E0E000C */  lw    $t6, 0xc($s0)
/* 0D8E78 7F0A4348 01C87821 */  addu  $t7, $t6, $t0
/* 0D8E7C 7F0A434C 91F80005 */  lbu   $t8, 5($t7)
/* 0D8E80 7F0A4350 00185140 */  sll   $t2, $t8, 5
/* 0D8E84 7F0A4354 0FC2D20F */  jal   get_room_data_float1
/* 0D8E88 7F0A4358 A62A002A */   sh    $t2, 0x2a($s1)
/* 0D8E8C 7F0A435C C7B20090 */  lwc1  $f18, 0x90($sp)
/* 0D8E90 7F0A4360 C7A40078 */  lwc1  $f4, 0x78($sp)
/* 0D8E94 7F0A4364 C7A8006C */  lwc1  $f8, 0x6c($sp)
/* 0D8E98 7F0A4368 46049181 */  sub.s $f6, $f18, $f4
/* 0D8E9C 7F0A436C C6520000 */  lwc1  $f18, ($s2)
/* 0D8EA0 7F0A4370 46083280 */  add.s $f10, $f6, $f8
/* 0D8EA4 7F0A4374 46005402 */  mul.s $f16, $f10, $f0
/* 0D8EA8 7F0A4378 46128101 */  sub.s $f4, $f16, $f18
/* 0D8EAC 7F0A437C 4600218D */  trunc.w.s $f6, $f4
/* 0D8EB0 7F0A4380 44093000 */  mfc1  $t1, $f6
/* 0D8EB4 7F0A4384 0FC2D20F */  jal   get_room_data_float1
/* 0D8EB8 7F0A4388 A6290030 */   sh    $t1, 0x30($s1)
/* 0D8EBC 7F0A438C C7A80094 */  lwc1  $f8, 0x94($sp)
/* 0D8EC0 7F0A4390 C7AA007C */  lwc1  $f10, 0x7c($sp)
/* 0D8EC4 7F0A4394 C7B20070 */  lwc1  $f18, 0x70($sp)
/* 0D8EC8 7F0A4398 460A4401 */  sub.s $f16, $f8, $f10
/* 0D8ECC 7F0A439C C6480004 */  lwc1  $f8, 4($s2)
/* 0D8ED0 7F0A43A0 46128100 */  add.s $f4, $f16, $f18
/* 0D8ED4 7F0A43A4 46002182 */  mul.s $f6, $f4, $f0
/* 0D8ED8 7F0A43A8 46083281 */  sub.s $f10, $f6, $f8
/* 0D8EDC 7F0A43AC 4600540D */  trunc.w.s $f16, $f10
/* 0D8EE0 7F0A43B0 440D8000 */  mfc1  $t5, $f16
/* 0D8EE4 7F0A43B4 0FC2D20F */  jal   get_room_data_float1
/* 0D8EE8 7F0A43B8 A62D0032 */   sh    $t5, 0x32($s1)
/* 0D8EEC 7F0A43BC C7B20098 */  lwc1  $f18, 0x98($sp)
/* 0D8EF0 7F0A43C0 C7A40080 */  lwc1  $f4, 0x80($sp)
/* 0D8EF4 7F0A43C4 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0D8EF8 7F0A43C8 8FA40034 */  lw    $a0, 0x34($sp)
/* 0D8EFC 7F0A43CC 46049181 */  sub.s $f6, $f18, $f4
/* 0D8F00 7F0A43D0 C6520008 */  lwc1  $f18, 8($s2)
/* 0D8F04 7F0A43D4 46083280 */  add.s $f10, $f6, $f8
/* 0D8F08 7F0A43D8 46005402 */  mul.s $f16, $f10, $f0
/* 0D8F0C 7F0A43DC 46128101 */  sub.s $f4, $f16, $f18
/* 0D8F10 7F0A43E0 4600218D */  trunc.w.s $f6, $f4
/* 0D8F14 7F0A43E4 440E3000 */  mfc1  $t6, $f6
/* 0D8F18 7F0A43E8 00000000 */  nop   
/* 0D8F1C 7F0A43EC A62E0034 */  sh    $t6, 0x34($s1)
/* 0D8F20 7F0A43F0 8E08000C */  lw    $t0, 0xc($s0)
/* 0D8F24 7F0A43F4 01047821 */  addu  $t7, $t0, $a0
/* 0D8F28 7F0A43F8 91F80004 */  lbu   $t8, 4($t7)
/* 0D8F2C 7F0A43FC 240F2000 */  li    $t7, 8192
/* 0D8F30 7F0A4400 3C08B700 */  lui   $t0, 0xb700
/* 0D8F34 7F0A4404 00185140 */  sll   $t2, $t8, 5
/* 0D8F38 7F0A4408 A62A0038 */  sh    $t2, 0x38($s1)
/* 0D8F3C 7F0A440C 8E19000C */  lw    $t9, 0xc($s0)
/* 0D8F40 7F0A4410 03244821 */  addu  $t1, $t9, $a0
/* 0D8F44 7F0A4414 912B0005 */  lbu   $t3, 5($t1)
/* 0D8F48 7F0A4418 3C190103 */  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
/* 0D8F4C 7F0A441C 37390040 */  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
/* 0D8F50 7F0A4420 000B6940 */  sll   $t5, $t3, 5
/* 0D8F54 7F0A4424 A62D003A */  sh    $t5, 0x3a($s1)
/* 0D8F58 7F0A4428 8FAC00A0 */  lw    $t4, 0xa0($sp)
/* 0D8F5C 7F0A442C 258E0008 */  addiu $t6, $t4, 8
/* 0D8F60 7F0A4430 AFAE00A0 */  sw    $t6, 0xa0($sp)
/* 0D8F64 7F0A4434 AD8F0004 */  sw    $t7, 4($t4)
/* 0D8F68 7F0A4438 AD880000 */  sw    $t0, ($t4)
/* 0D8F6C 7F0A443C 8FB800A0 */  lw    $t8, 0xa0($sp)
/* 0D8F70 7F0A4440 270A0008 */  addiu $t2, $t8, 8
/* 0D8F74 7F0A4444 AFAA00A0 */  sw    $t2, 0xa0($sp)
/* 0D8F78 7F0A4448 AF190000 */  sw    $t9, ($t8)
/* 0D8F7C 7F0A444C 0FC1E0E5 */  jal   get_BONDdata_field_10E0
/* 0D8F80 7F0A4450 AFB8004C */   sw    $t8, 0x4c($sp)
/* 0D8F84 7F0A4454 0C003A2C */  jal   osVirtualToPhysical
/* 0D8F88 7F0A4458 00402025 */   move  $a0, $v0
/* 0D8F8C 7F0A445C 8FA9004C */  lw    $t1, 0x4c($sp)
/* 0D8F90 7F0A4460 AD220004 */  sw    $v0, 4($t1)
/* 0D8F94 7F0A4464 8FA50058 */  lw    $a1, 0x58($sp)
/* 0D8F98 7F0A4468 0FC2F271 */  jal   sub_GAME_7F0BC9C4
/* 0D8F9C 7F0A446C 8FA400A0 */   lw    $a0, 0xa0($sp)
/* 0D8FA0 7F0A4470 AFA200A0 */  sw    $v0, 0xa0($sp)
/* 0D8FA4 7F0A4474 8E0B000C */  lw    $t3, 0xc($s0)
/* 0D8FA8 7F0A4478 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0D8FAC 7F0A447C 240C0002 */  li    $t4, 2
/* 0D8FB0 7F0A4480 AFAC0010 */  sw    $t4, 0x10($sp)
/* 0D8FB4 7F0A4484 27A400A0 */  addiu $a0, $sp, 0xa0
/* 0D8FB8 7F0A4488 24060004 */  li    $a2, 4
/* 0D8FBC 7F0A448C 8FA700C0 */  lw    $a3, 0xc0($sp)
/* 0D8FC0 7F0A4490 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0D8FC4 7F0A4494 016D2821 */   addu  $a1, $t3, $t5
/* 0D8FC8 7F0A4498 8FB000A0 */  lw    $s0, 0xa0($sp)
/* 0D8FCC 7F0A449C 3C0F0430 */  lui   $t7, (0x04300040 >> 16) # lui $t7, 0x430
/* 0D8FD0 7F0A44A0 35EF0040 */  ori   $t7, (0x04300040 & 0xFFFF) # ori $t7, $t7, 0x40
/* 0D8FD4 7F0A44A4 26080008 */  addiu $t0, $s0, 8
/* 0D8FD8 7F0A44A8 AFA800A0 */  sw    $t0, 0xa0($sp)
/* 0D8FDC 7F0A44AC 02202025 */  move  $a0, $s1
/* 0D8FE0 7F0A44B0 0C003A2C */  jal   osVirtualToPhysical
/* 0D8FE4 7F0A44B4 AE0F0000 */   sw    $t7, ($s0)
/* 0D8FE8 7F0A44B8 AE020004 */  sw    $v0, 4($s0)
/* 0D8FEC 7F0A44BC 8FB800A0 */  lw    $t8, 0xa0($sp)
/* 0D8FF0 7F0A44C0 3C19B100 */  lui   $t9, (0xB1000032 >> 16) # lui $t9, 0xb100
/* 0D8FF4 7F0A44C4 37390032 */  ori   $t9, (0xB1000032 & 0xFFFF) # ori $t9, $t9, 0x32
/* 0D8FF8 7F0A44C8 270A0008 */  addiu $t2, $t8, 8
/* 0D8FFC 7F0A44CC AFAA00A0 */  sw    $t2, 0xa0($sp)
/* 0D9000 7F0A44D0 24092010 */  li    $t1, 8208
/* 0D9004 7F0A44D4 AF090004 */  sw    $t1, 4($t8)
/* 0D9008 7F0A44D8 AF190000 */  sw    $t9, ($t8)
/* 0D900C 7F0A44DC 8FB100A0 */  lw    $s1, 0xa0($sp)
/* 0D9010 7F0A44E0 3C0C0103 */  lui   $t4, (0x01030040 >> 16) # lui $t4, 0x103
/* 0D9014 7F0A44E4 358C0040 */  ori   $t4, (0x01030040 & 0xFFFF) # ori $t4, $t4, 0x40
/* 0D9018 7F0A44E8 262D0008 */  addiu $t5, $s1, 8
/* 0D901C 7F0A44EC AFAD00A0 */  sw    $t5, 0xa0($sp)
/* 0D9020 7F0A44F0 0FC1E0DD */  jal   currentPlayerGetProjectionMatrix
/* 0D9024 7F0A44F4 AE2C0000 */   sw    $t4, ($s1)
/* 0D9028 7F0A44F8 0C003A2C */  jal   osVirtualToPhysical
/* 0D902C 7F0A44FC 00402025 */   move  $a0, $v0
/* 0D9030 7F0A4500 AE220004 */  sw    $v0, 4($s1)
/* 0D9034 7F0A4504 8FA800BC */  lw    $t0, 0xbc($sp)
/* 0D9038 7F0A4508 8FAE00A0 */  lw    $t6, 0xa0($sp)
/* 0D903C 7F0A450C AD0E0000 */  sw    $t6, ($t0)
.L7F0A4510:
/* 0D9040 7F0A4510 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F0A4514:
/* 0D9044 7F0A4514 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D9048 7F0A4518 8FB10024 */  lw    $s1, 0x24($sp)
/* 0D904C 7F0A451C 8FB20028 */  lw    $s2, 0x28($sp)
/* 0D9050 7F0A4520 03E00008 */  jr    $ra
/* 0D9054 7F0A4524 27BD00B8 */   addiu $sp, $sp, 0xb8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A4528(Gfx *arg0, s32 arg1) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A4528
/* 0D9058 7F0A4528 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0D905C 7F0A452C AFB10018 */  sw    $s1, 0x18($sp)
/* 0D9060 7F0A4530 AFB00014 */  sw    $s0, 0x14($sp)
/* 0D9064 7F0A4534 AFB30020 */  sw    $s3, 0x20($sp)
/* 0D9068 7F0A4538 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0D906C 7F0A453C 3C108008 */  lui   $s0, %hi(dword_CODE_bss_8007A170)
/* 0D9070 7F0A4540 3C118008 */  lui   $s1, %hi(dword_CODE_bss_8007A170 + 0x370)
/* 0D9074 7F0A4544 00809025 */  move  $s2, $a0
/* 0D9078 7F0A4548 00A09825 */  move  $s3, $a1
/* 0D907C 7F0A454C AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D9080 7F0A4550 2631A4E0 */  addiu $s1, %lo(dword_CODE_bss_8007A170 + 0x370) # addiu $s1, $s1, -0x5b20
/* 0D9084 7F0A4554 2610A170 */  addiu $s0, %lo(dword_CODE_bss_8007A170) # addiu $s0, $s0, -0x5e90
/* 0D9088 7F0A4558 02002025 */  move  $a0, $s0
.L7F0A455C:
/* 0D908C 7F0A455C 02402825 */  move  $a1, $s2
/* 0D9090 7F0A4560 0FC28FC1 */  jal   sub_GAME_7F0A3F04
/* 0D9094 7F0A4564 02603025 */   move  $a2, $s3
/* 0D9098 7F0A4568 2610002C */  addiu $s0, $s0, 0x2c
/* 0D909C 7F0A456C 0211082B */  sltu  $at, $s0, $s1
/* 0D90A0 7F0A4570 5420FFFA */  bnezl $at, .L7F0A455C
/* 0D90A4 7F0A4574 02002025 */   move  $a0, $s0
/* 0D90A8 7F0A4578 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D90AC 7F0A457C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0D90B0 7F0A4580 8FB10018 */  lw    $s1, 0x18($sp)
/* 0D90B4 7F0A4584 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0D90B8 7F0A4588 8FB30020 */  lw    $s3, 0x20($sp)
/* 0D90BC 7F0A458C 03E00008 */  jr    $ra
/* 0D90C0 7F0A4590 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A4594(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A4594
/* 0D90C4 7F0A4594 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0D90C8 7F0A4598 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0D90CC 7F0A459C C4840010 */  lwc1  $f4, 0x10($a0)
/* 0D90D0 7F0A45A0 E7A4001C */  swc1  $f4, 0x1c($sp)
/* 0D90D4 7F0A45A4 C4860014 */  lwc1  $f6, 0x14($a0)
/* 0D90D8 7F0A45A8 E7A60020 */  swc1  $f6, 0x20($sp)
/* 0D90DC 7F0A45AC C4880018 */  lwc1  $f8, 0x18($a0)
/* 0D90E0 7F0A45B0 0FC1E0F1 */  jal   currentPlayerGetMatrix10CC
/* 0D90E4 7F0A45B4 E7A80024 */   swc1  $f8, 0x24($sp)
/* 0D90E8 7F0A45B8 00402025 */  move  $a0, $v0
/* 0D90EC 7F0A45BC 0FC1611D */  jal   matrix_4x4_transform_vector_in_place
/* 0D90F0 7F0A45C0 27A5001C */   addiu $a1, $sp, 0x1c
/* 0D90F4 7F0A45C4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D90F8 7F0A45C8 C7A00024 */  lwc1  $f0, 0x24($sp)
/* 0D90FC 7F0A45CC 27BD0028 */  addiu $sp, $sp, 0x28
/* 0D9100 7F0A45D0 03E00008 */  jr    $ra
/* 0D9104 7F0A45D4 46000007 */   neg.s $f0, $f0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0A45D8(void) {

}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A45D8
/* 0D9108 7F0A45D8 3C028008 */  lui   $v0, %hi(dword_CODE_bss_8007A4E0)
/* 0D910C 7F0A45DC 3C038008 */  lui   $v1, %hi(dword_CODE_bss_8007B098)
/* 0D9110 7F0A45E0 2463B098 */  addiu $v1, %lo(dword_CODE_bss_8007B098) # addiu $v1, $v1, -0x4f68
/* 0D9114 7F0A45E4 2442A4E0 */  addiu $v0, %lo(dword_CODE_bss_8007A4E0) # addiu $v0, $v0, -0x5b20
.L7F0A45E8:
/* 0D9118 7F0A45E8 2442003C */  addiu $v0, $v0, 0x3c
/* 0D911C 7F0A45EC 0043082B */  sltu  $at, $v0, $v1
/* 0D9120 7F0A45F0 1420FFFD */  bnez  $at, .L7F0A45E8
/* 0D9124 7F0A45F4 A440FFC8 */   sh    $zero, -0x38($v0)
/* 0D9128 7F0A45F8 03E00008 */  jr    $ra
/* 0D912C 7F0A45FC 00000000 */   nop   
)
#endif
#ifdef VERSION_EU
void sub_GAME_7F0A45D8(void)
{
    sub_GAME_7F0A3BD8();
}
#endif
#endif




#ifdef NONMATCHING
void sub_GAME_7F0A4600(void) {

}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A4600
/* 0D9130 7F0A4600 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0D9134 7F0A4604 AFB00020 */  sw    $s0, 0x20($sp)
/* 0D9138 7F0A4608 3C108008 */  lui   $s0, %hi(dword_CODE_bss_8007A4E0)
/* 0D913C 7F0A460C 3C028008 */  lui   $v0, %hi(dword_CODE_bss_8007B098)
/* 0D9140 7F0A4610 44876000 */  mtc1  $a3, $f12
/* 0D9144 7F0A4614 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D9148 7F0A4618 AFA40028 */  sw    $a0, 0x28($sp)
/* 0D914C 7F0A461C AFA5002C */  sw    $a1, 0x2c($sp)
/* 0D9150 7F0A4620 2442B098 */  addiu $v0, %lo(dword_CODE_bss_8007B098) # addiu $v0, $v0, -0x4f68
/* 0D9154 7F0A4624 2610A4E0 */  addiu $s0, %lo(dword_CODE_bss_8007A4E0) # addiu $s0, $s0, -0x5b20
/* 0D9158 7F0A4628 860E0004 */  lh    $t6, 4($s0)
.L7F0A462C:
/* 0D915C 7F0A462C 55C00013 */  bnezl $t6, .L7F0A467C
/* 0D9160 7F0A4630 2610003C */   addiu $s0, $s0, 0x3c
/* 0D9164 7F0A4634 87AF003E */  lh    $t7, 0x3e($sp)
/* 0D9168 7F0A4638 44076000 */  mfc1  $a3, $f12
/* 0D916C 7F0A463C 02002025 */  move  $a0, $s0
/* 0D9170 7F0A4640 8FA50028 */  lw    $a1, 0x28($sp)
/* 0D9174 7F0A4644 0FC28F02 */  jal   sub_GAME_7F0A3C08
/* 0D9178 7F0A4648 AFAF0010 */   sw    $t7, 0x10($sp)
/* 0D917C 7F0A464C 8FA3002C */  lw    $v1, 0x2c($sp)
/* 0D9180 7F0A4650 02001025 */  move  $v0, $s0
/* 0D9184 7F0A4654 C4640000 */  lwc1  $f4, ($v1)
/* 0D9188 7F0A4658 E604002C */  swc1  $f4, 0x2c($s0)
/* 0D918C 7F0A465C C4660004 */  lwc1  $f6, 4($v1)
/* 0D9190 7F0A4660 E6060030 */  swc1  $f6, 0x30($s0)
/* 0D9194 7F0A4664 C4680008 */  lwc1  $f8, 8($v1)
/* 0D9198 7F0A4668 E6080034 */  swc1  $f8, 0x34($s0)
/* 0D919C 7F0A466C C7AA0038 */  lwc1  $f10, 0x38($sp)
/* 0D91A0 7F0A4670 10000006 */  b     .L7F0A468C
/* 0D91A4 7F0A4674 E60A0038 */   swc1  $f10, 0x38($s0)
/* 0D91A8 7F0A4678 2610003C */  addiu $s0, $s0, 0x3c
.L7F0A467C:
/* 0D91AC 7F0A467C 0202082B */  sltu  $at, $s0, $v0
/* 0D91B0 7F0A4680 5420FFEA */  bnezl $at, .L7F0A462C
/* 0D91B4 7F0A4684 860E0004 */   lh    $t6, 4($s0)
/* 0D91B8 7F0A4688 00001025 */  move  $v0, $zero
.L7F0A468C:
/* 0D91BC 7F0A468C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D91C0 7F0A4690 8FB00020 */  lw    $s0, 0x20($sp)
/* 0D91C4 7F0A4694 27BD0028 */  addiu $sp, $sp, 0x28
/* 0D91C8 7F0A4698 03E00008 */  jr    $ra
/* 0D91CC 7F0A469C 00000000 */   nop   
)
#endif
#ifdef VERSION_EU
void sub_GAME_7F0A4600(void)
{
    sub_GAME_7F0A3EA0();
}
#endif
#endif




#ifdef NONMATCHING
void sub_GAME_7F0A46A0(void) {

}
#else
#ifndef VERSION_EU
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A46A0
/* 0D91D0 7F0A46A0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0D91D4 7F0A46A4 AFB30020 */  sw    $s3, 0x20($sp)
/* 0D91D8 7F0A46A8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0D91DC 7F0A46AC AFB10018 */  sw    $s1, 0x18($sp)
/* 0D91E0 7F0A46B0 AFB00014 */  sw    $s0, 0x14($sp)
/* 0D91E4 7F0A46B4 3C108008 */  lui   $s0, %hi(dword_CODE_bss_8007A4E0)
/* 0D91E8 7F0A46B8 3C138008 */  lui   $s3, %hi(dword_CODE_bss_8007B098)
/* 0D91EC 7F0A46BC 3C118005 */  lui   $s1, %hi(g_ClockTimer)
/* 0D91F0 7F0A46C0 3C128005 */  lui   $s2, %hi(g_GlobalTimerDelta)
/* 0D91F4 7F0A46C4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D91F8 7F0A46C8 2673B098 */  addiu $s3, %lo(dword_CODE_bss_8007B098) # addiu $s3, $s3, -0x4f68
/* 0D91FC 7F0A46CC 2610A4E0 */  addiu $s0, %lo(dword_CODE_bss_8007A4E0) # addiu $s0, $s0, -0x5b20
/* 0D9200 7F0A46D0 26528378 */  addiu $s2, %lo(g_GlobalTimerDelta) # addiu $s2, $s2, -0x7c88
/* 0D9204 7F0A46D4 26318374 */  addiu $s1, %lo(g_ClockTimer) # addiu $s1, $s1, -0x7c8c
/* 0D9208 7F0A46D8 860E0004 */  lh    $t6, 4($s0)
.L7F0A46DC:
/* 0D920C 7F0A46DC 59C00018 */  blezl $t6, .L7F0A4740
/* 0D9210 7F0A46E0 2610003C */   addiu $s0, $s0, 0x3c
/* 0D9214 7F0A46E4 8E0F0000 */  lw    $t7, ($s0)
/* 0D9218 7F0A46E8 8E380000 */  lw    $t8, ($s1)
/* 0D921C 7F0A46EC 01F8C821 */  addu  $t9, $t7, $t8
/* 0D9220 7F0A46F0 07200012 */  bltz  $t9, .L7F0A473C
/* 0D9224 7F0A46F4 AE190000 */   sw    $t9, ($s0)
/* 0D9228 7F0A46F8 86080004 */  lh    $t0, 4($s0)
/* 0D922C 7F0A46FC 26040010 */  addiu $a0, $s0, 0x10
/* 0D9230 7F0A4700 2605002C */  addiu $a1, $s0, 0x2c
/* 0D9234 7F0A4704 0328082A */  slt   $at, $t9, $t0
/* 0D9238 7F0A4708 5020000C */  beql  $at, $zero, .L7F0A473C
/* 0D923C 7F0A470C A6000004 */   sh    $zero, 4($s0)
/* 0D9240 7F0A4710 0FC15F62 */  jal   sub_GAME_7F057D88
/* 0D9244 7F0A4714 8E460000 */   lw    $a2, ($s2)
/* 0D9248 7F0A4718 C6040014 */  lwc1  $f4, 0x14($s0)
/* 0D924C 7F0A471C C6060038 */  lwc1  $f6, 0x38($s0)
/* 0D9250 7F0A4720 4606203C */  c.lt.s $f4, $f6
/* 0D9254 7F0A4724 00000000 */  nop   
/* 0D9258 7F0A4728 45020005 */  bc1fl .L7F0A4740
/* 0D925C 7F0A472C 2610003C */   addiu $s0, $s0, 0x3c
/* 0D9260 7F0A4730 10000002 */  b     .L7F0A473C
/* 0D9264 7F0A4734 A6000004 */   sh    $zero, 4($s0)
/* 0D9268 7F0A4738 A6000004 */  sh    $zero, 4($s0)
.L7F0A473C:
/* 0D926C 7F0A473C 2610003C */  addiu $s0, $s0, 0x3c
.L7F0A4740:
/* 0D9270 7F0A4740 0213082B */  sltu  $at, $s0, $s3
/* 0D9274 7F0A4744 5420FFE5 */  bnezl $at, .L7F0A46DC
/* 0D9278 7F0A4748 860E0004 */   lh    $t6, 4($s0)
/* 0D927C 7F0A474C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D9280 7F0A4750 8FB00014 */  lw    $s0, 0x14($sp)
/* 0D9284 7F0A4754 8FB10018 */  lw    $s1, 0x18($sp)
/* 0D9288 7F0A4758 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0D928C 7F0A475C 8FB30020 */  lw    $s3, 0x20($sp)
/* 0D9290 7F0A4760 03E00008 */  jr    $ra
/* 0D9294 7F0A4764 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif
#ifdef VERSION_EU
void sub_GAME_7F0A46A0(Gfx *arg0, s32 arg1)
{
    sub_GAME_7F0A4528(arg0, arg1);
}
#endif
#endif


#ifndef VERSION_EU

#ifdef NONMATCHING
void sub_GAME_7F0A4768(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0A4768
/* 0D9298 7F0A4768 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0D929C 7F0A476C AFB10018 */  sw    $s1, 0x18($sp)
/* 0D92A0 7F0A4770 AFB00014 */  sw    $s0, 0x14($sp)
/* 0D92A4 7F0A4774 AFB30020 */  sw    $s3, 0x20($sp)
/* 0D92A8 7F0A4778 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0D92AC 7F0A477C 3C108008 */  lui   $s0, %hi(dword_CODE_bss_8007A4E0)
/* 0D92B0 7F0A4780 3C118008 */  lui   $s1, %hi(dword_CODE_bss_8007B098)
/* 0D92B4 7F0A4784 00809025 */  move  $s2, $a0
/* 0D92B8 7F0A4788 00A09825 */  move  $s3, $a1
/* 0D92BC 7F0A478C AFBF0024 */  sw    $ra, 0x24($sp)
/* 0D92C0 7F0A4790 2631B098 */  addiu $s1, %lo(dword_CODE_bss_8007B098) # addiu $s1, $s1, -0x4f68
/* 0D92C4 7F0A4794 2610A4E0 */  addiu $s0, %lo(dword_CODE_bss_8007A4E0) # addiu $s0, $s0, -0x5b20
/* 0D92C8 7F0A4798 02002025 */  move  $a0, $s0
.L7F0A479C:
/* 0D92CC 7F0A479C 02402825 */  move  $a1, $s2
/* 0D92D0 7F0A47A0 0FC28FC1 */  jal   sub_GAME_7F0A3F04
/* 0D92D4 7F0A47A4 02603025 */   move  $a2, $s3
/* 0D92D8 7F0A47A8 2610003C */  addiu $s0, $s0, 0x3c
/* 0D92DC 7F0A47AC 0211082B */  sltu  $at, $s0, $s1
/* 0D92E0 7F0A47B0 5420FFFA */  bnezl $at, .L7F0A479C
/* 0D92E4 7F0A47B4 02002025 */   move  $a0, $s0
/* 0D92E8 7F0A47B8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0D92EC 7F0A47BC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0D92F0 7F0A47C0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0D92F4 7F0A47C4 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0D92F8 7F0A47C8 8FB30020 */  lw    $s3, 0x20($sp)
/* 0D92FC 7F0A47CC 03E00008 */  jr    $ra
/* 0D9300 7F0A47D0 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





void sub_GAME_7F0A47D4(void) {
    sub_GAME_7F0A3BD8();
    sub_GAME_7F0A45D8();
}

void update_bullet_sparks_and_dust_clouds(void) {
    // unknown
    sub_GAME_7F0A3EA0();

    // responsible for updating bullet sparks and dust clouds that spawn when shooting at other players
    // the limit is 20, after which they'll stop spawning until some are removed
    // these are 2D and always facing the camera
    sub_GAME_7F0A46A0();
}



void sub_GAME_7F0A4824(Gfx *arg0, s32 arg1) {
    sub_GAME_7F0A4528(arg0, arg1);
    sub_GAME_7F0A4768(arg0, arg1);
}


#endif 


