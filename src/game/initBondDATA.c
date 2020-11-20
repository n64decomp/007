#include "ultra64.h"
#include "game/initBondDATA.h"

struct  BONDdata_item_control_blocks BONDdata_item_control_blocks_initdata = {        
0, 0xFFFFFFFF, 0, 0x100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 0, 0, 0, 1.0, 0, 
0, 0, 0, 1.0, 0, 0, 0, 0, 0, 0, -1.0, 0, 1.0, 0, 0, 0, 0, 0, 0, -19.999996, 0, 
19.999996, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1.0, 0, 0, -1.0, 0, 0,
-1.0, 0, 0, -1.0, 0, 1.0, 0, 0, 1.0, 0, 0, 1.0, 0, 0, 1.0, 0, 0, 0, 1.0, 1.0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000.0, 0, 0, 0, 0, 0xFF000000, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
0, 0, 0
};







#ifdef NONMATCHING
void init_player_BONDdata_stats(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8004F0E0
.word 0x3f666666
glabel fl_neg_pi
.word 0xc0490fdb
.text
glabel init_player_BONDdata_stats
/* 039C00 7F0050D0 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 039C04 7F0050D4 3C0F8003 */  lui   $t7, %hi(BONDdata_item_control_blocks_initdata) 
/* 039C08 7F0050D8 25EFA3D0 */  addiu $t7, %lo(BONDdata_item_control_blocks_initdata) # addiu $t7, $t7, -0x5c30
/* 039C0C 7F0050DC AFBF001C */  sw    $ra, 0x1c($sp)
/* 039C10 7F0050E0 AFB00018 */  sw    $s0, 0x18($sp)
/* 039C14 7F0050E4 25E803A8 */  addiu $t0, $t7, 0x3a8
/* 039C18 7F0050E8 27AE0024 */  addiu $t6, $sp, 0x24
.L7F0050EC:
/* 039C1C 7F0050EC 8DE10000 */  lw    $at, ($t7)
/* 039C20 7F0050F0 25EF000C */  addiu $t7, $t7, 0xc
/* 039C24 7F0050F4 25CE000C */  addiu $t6, $t6, 0xc
/* 039C28 7F0050F8 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 039C2C 7F0050FC 8DE1FFF8 */  lw    $at, -8($t7)
/* 039C30 7F005100 ADC1FFF8 */  sw    $at, -8($t6)
/* 039C34 7F005104 8DE1FFFC */  lw    $at, -4($t7)
/* 039C38 7F005108 15E8FFF8 */  bne   $t7, $t0, .L7F0050EC
/* 039C3C 7F00510C ADC1FFFC */   sw    $at, -4($t6)
/* 039C40 7F005110 3C048003 */  lui   $a0, %hi(size_item_buffer)
/* 039C44 7F005114 8C84245C */  lw    $a0, %lo(size_item_buffer)($a0)
/* 039C48 7F005118 0C0025C8 */  jal   mempAllocBytesInBank
/* 039C4C 7F00511C 24050004 */   li    $a1, 4
/* 039C50 7F005120 3C108008 */  lui   $s0, %hi(pPlayer)
/* 039C54 7F005124 2610A0B0 */  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
/* 039C58 7F005128 8E090000 */  lw    $t1, ($s0)
/* 039C5C 7F00512C 0FC26919 */  jal   get_num_players
/* 039C60 7F005130 AD220808 */   sw    $v0, 0x808($t1)
/* 039C64 7F005134 24010001 */  li    $at, 1
/* 039C68 7F005138 14410006 */  bne   $v0, $at, .L7F005154
/* 039C6C 7F00513C 3C048003 */   lui   $a0, %hi(size_item_buffer+0x4)
/* 039C70 7F005140 8C842460 */  lw    $a0, %lo(size_item_buffer+0x4)($a0)
/* 039C74 7F005144 0C0025C8 */  jal   mempAllocBytesInBank
/* 039C78 7F005148 24050004 */   li    $a1, 4
/* 039C7C 7F00514C 8E0A0000 */  lw    $t2, ($s0)
/* 039C80 7F005150 AD42080C */  sw    $v0, 0x80c($t2)
.L7F005154:
/* 039C84 7F005154 8E0B0000 */  lw    $t3, ($s0)
/* 039C88 7F005158 2405FFFF */  li    $a1, -1
/* 039C8C 7F00515C 27A30024 */  addiu $v1, $sp, 0x24
/* 039C90 7F005160 AD6007F8 */  sw    $zero, 0x7f8($t3)
/* 039C94 7F005164 8E0C0000 */  lw    $t4, ($s0)
/* 039C98 7F005168 246B03A8 */  addiu $t3, $v1, 0x3a8
/* 039C9C 7F00516C 00001025 */  move  $v0, $zero
/* 039CA0 7F005170 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 039CA4 7F005174 8E0D0000 */  lw    $t5, ($s0)
/* 039CA8 7F005178 00606025 */  move  $t4, $v1
/* 039CAC 7F00517C ADA00800 */  sw    $zero, 0x800($t5)
/* 039CB0 7F005180 8E190000 */  lw    $t9, ($s0)
/* 039CB4 7F005184 AF200804 */  sw    $zero, 0x804($t9)
/* 039CB8 7F005188 8E180000 */  lw    $t8, ($s0)
/* 039CBC 7F00518C AF052A44 */  sw    $a1, 0x2a44($t8)
/* 039CC0 7F005190 8E080000 */  lw    $t0, ($s0)
/* 039CC4 7F005194 247803A8 */  addiu $t8, $v1, 0x3a8
/* 039CC8 7F005198 AD052A48 */  sw    $a1, 0x2a48($t0)
/* 039CCC 7F00519C 8E0F0000 */  lw    $t7, ($s0)
/* 039CD0 7F0051A0 00604025 */  move  $t0, $v1
/* 039CD4 7F0051A4 3C038008 */  lui   $v1, %hi(pPlayersPerm)
/* 039CD8 7F0051A8 ADE02A50 */  sw    $zero, 0x2a50($t7)
/* 039CDC 7F0051AC 8E0E0000 */  lw    $t6, ($s0)
/* 039CE0 7F0051B0 2463A0B4 */  addiu $v1, %lo(pPlayersPerm) # addiu $v1, $v1, -0x5f4c
/* 039CE4 7F0051B4 ADC02A54 */  sw    $zero, 0x2a54($t6)
/* 039CE8 7F0051B8 8E090000 */  lw    $t1, ($s0)
.L7F0051BC:
/* 039CEC 7F0051BC 8D810000 */  lw    $at, ($t4)
/* 039CF0 7F0051C0 258C000C */  addiu $t4, $t4, 0xc
/* 039CF4 7F0051C4 2529000C */  addiu $t1, $t1, 0xc
/* 039CF8 7F0051C8 AD210864 */  sw    $at, 0x864($t1)
/* 039CFC 7F0051CC 8D81FFF8 */  lw    $at, -8($t4)
/* 039D00 7F0051D0 AD210868 */  sw    $at, 0x868($t1)
/* 039D04 7F0051D4 8D81FFFC */  lw    $at, -4($t4)
/* 039D08 7F0051D8 158BFFF8 */  bne   $t4, $t3, .L7F0051BC
/* 039D0C 7F0051DC AD21086C */   sw    $at, 0x86c($t1)
/* 039D10 7F0051E0 8E0D0000 */  lw    $t5, ($s0)
.L7F0051E4:
/* 039D14 7F0051E4 8D010000 */  lw    $at, ($t0)
/* 039D18 7F0051E8 2508000C */  addiu $t0, $t0, 0xc
/* 039D1C 7F0051EC 25AD000C */  addiu $t5, $t5, 0xc
/* 039D20 7F0051F0 ADA10C0C */  sw    $at, 0xc0c($t5)
/* 039D24 7F0051F4 8D01FFF8 */  lw    $at, -8($t0)
/* 039D28 7F0051F8 ADA10C10 */  sw    $at, 0xc10($t5)
/* 039D2C 7F0051FC 8D01FFFC */  lw    $at, -4($t0)
/* 039D30 7F005200 1518FFF8 */  bne   $t0, $t8, .L7F0051E4
/* 039D34 7F005204 ADA10C14 */   sw    $at, 0xc14($t5)
.L7F005208:
/* 039D38 7F005208 8E0F0000 */  lw    $t7, ($s0)
/* 039D3C 7F00520C 01E27021 */  addu  $t6, $t7, $v0
/* 039D40 7F005210 24420004 */  addiu $v0, $v0, 4
/* 039D44 7F005214 28410078 */  slti  $at, $v0, 0x78
/* 039D48 7F005218 1420FFFB */  bnez  $at, .L7F005208
/* 039D4C 7F00521C ADC01130 */   sw    $zero, 0x1130($t6)
/* 039D50 7F005220 8C6A0000 */  lw    $t2, ($v1)
/* 039D54 7F005224 24040003 */  li    $a0, 3
/* 039D58 7F005228 00041080 */  sll   $v0, $a0, 2
/* 039D5C 7F00522C AD400000 */  sw    $zero, ($t2)
/* 039D60 7F005230 8C6B0000 */  lw    $t3, ($v1)
/* 039D64 7F005234 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 039D68 7F005238 44811000 */  mtc1  $at, $f2
/* 039D6C 7F00523C AD600004 */  sw    $zero, 4($t3)
/* 039D70 7F005240 8C6C0000 */  lw    $t4, ($v1)
/* 039D74 7F005244 3C018005 */  lui   $at, %hi(D_8004F0E0)
/* 039D78 7F005248 44800000 */  mtc1  $zero, $f0
/* 039D7C 7F00524C AD800008 */  sw    $zero, 8($t4)
/* 039D80 7F005250 8C690000 */  lw    $t1, ($v1)
/* 039D84 7F005254 00002025 */  move  $a0, $zero
/* 039D88 7F005258 0122C821 */  addu  $t9, $t1, $v0
/* 039D8C 7F00525C AF200000 */  sw    $zero, ($t9)
/* 039D90 7F005260 8C780000 */  lw    $t8, ($v1)
/* 039D94 7F005264 03024021 */  addu  $t0, $t8, $v0
/* 039D98 7F005268 AD000004 */  sw    $zero, 4($t0)
/* 039D9C 7F00526C 8C6D0000 */  lw    $t5, ($v1)
/* 039DA0 7F005270 01A27821 */  addu  $t7, $t5, $v0
/* 039DA4 7F005274 ADE00008 */  sw    $zero, 8($t7)
/* 039DA8 7F005278 8C6E0000 */  lw    $t6, ($v1)
/* 039DAC 7F00527C 01C25021 */  addu  $t2, $t6, $v0
/* 039DB0 7F005280 AD40000C */  sw    $zero, 0xc($t2)
/* 039DB4 7F005284 8C6B0000 */  lw    $t3, ($v1)
/* 039DB8 7F005288 C42CF0E0 */  lwc1  $f12, %lo(D_8004F0E0)($at)
/* 039DBC 7F00528C 240200FF */  li    $v0, 255
/* 039DC0 7F005290 AD60006C */  sw    $zero, 0x6c($t3)
/* 039DC4 7F005294 8C6C0000 */  lw    $t4, ($v1)
/* 039DC8 7F005298 3C018005 */  lui   $at, %hi(fl_neg_pi)
/* 039DCC 7F00529C AD80001C */  sw    $zero, 0x1c($t4)
/* 039DD0 7F0052A0 8C690000 */  lw    $t1, ($v1)
/* 039DD4 7F0052A4 AD200020 */  sw    $zero, 0x20($t1)
/* 039DD8 7F0052A8 8E190000 */  lw    $t9, ($s0)
/* 039DDC 7F0052AC AF2029D8 */  sw    $zero, 0x29d8($t9)
/* 039DE0 7F0052B0 8E180000 */  lw    $t8, ($s0)
/* 039DE4 7F0052B4 AF0029DC */  sw    $zero, 0x29dc($t8)
/* 039DE8 7F0052B8 8E080000 */  lw    $t0, ($s0)
/* 039DEC 7F0052BC E5020FC0 */  swc1  $f2, 0xfc0($t0)
/* 039DF0 7F0052C0 8E0D0000 */  lw    $t5, ($s0)
/* 039DF4 7F0052C4 E5A20FC4 */  swc1  $f2, 0xfc4($t5)
/* 039DF8 7F0052C8 8E0F0000 */  lw    $t7, ($s0)
/* 039DFC 7F0052CC 240D0001 */  li    $t5, 1
/* 039E00 7F0052D0 ADE00FC8 */  sw    $zero, 0xfc8($t7)
/* 039E04 7F0052D4 8E0E0000 */  lw    $t6, ($s0)
/* 039E08 7F0052D8 ADC00FCC */  sw    $zero, 0xfcc($t6)
/* 039E0C 7F0052DC 8E0A0000 */  lw    $t2, ($s0)
/* 039E10 7F0052E0 AD400FD0 */  sw    $zero, 0xfd0($t2)
/* 039E14 7F0052E4 8E0B0000 */  lw    $t3, ($s0)
/* 039E18 7F0052E8 AD600FD4 */  sw    $zero, 0xfd4($t3)
/* 039E1C 7F0052EC 8E0C0000 */  lw    $t4, ($s0)
/* 039E20 7F0052F0 AD800FD8 */  sw    $zero, 0xfd8($t4)
/* 039E24 7F0052F4 8E090000 */  lw    $t1, ($s0)
/* 039E28 7F0052F8 A1220FDC */  sb    $v0, 0xfdc($t1)
/* 039E2C 7F0052FC 8E190000 */  lw    $t9, ($s0)
/* 039E30 7F005300 A3220FDD */  sb    $v0, 0xfdd($t9)
/* 039E34 7F005304 8E180000 */  lw    $t8, ($s0)
/* 039E38 7F005308 A3020FDE */  sb    $v0, 0xfde($t8)
/* 039E3C 7F00530C 8E080000 */  lw    $t0, ($s0)
/* 039E40 7F005310 A1000FDF */  sb    $zero, 0xfdf($t0)
/* 039E44 7F005314 8E0F0000 */  lw    $t7, ($s0)
/* 039E48 7F005318 ADED0FE0 */  sw    $t5, 0xfe0($t7)
/* 039E4C 7F00531C 8E0E0000 */  lw    $t6, ($s0)
/* 039E50 7F005320 ADC00FE4 */  sw    $zero, 0xfe4($t6)
/* 039E54 7F005324 8E0A0000 */  lw    $t2, ($s0)
/* 039E58 7F005328 E5400FE8 */  swc1  $f0, 0xfe8($t2)
/* 039E5C 7F00532C 8E0B0000 */  lw    $t3, ($s0)
/* 039E60 7F005330 E5600FEC */  swc1  $f0, 0xfec($t3)
/* 039E64 7F005334 8E0C0000 */  lw    $t4, ($s0)
/* 039E68 7F005338 E5800FF0 */  swc1  $f0, 0xff0($t4)
/* 039E6C 7F00533C 8E090000 */  lw    $t1, ($s0)
/* 039E70 7F005340 E5200FF4 */  swc1  $f0, 0xff4($t1)
/* 039E74 7F005344 8E190000 */  lw    $t9, ($s0)
/* 039E78 7F005348 E72C0FF8 */  swc1  $f12, 0xff8($t9)
/* 039E7C 7F00534C 8E180000 */  lw    $t8, ($s0)
/* 039E80 7F005350 E7000FFC */  swc1  $f0, 0xffc($t8)
/* 039E84 7F005354 8E080000 */  lw    $t0, ($s0)
/* 039E88 7F005358 E5001000 */  swc1  $f0, 0x1000($t0)
/* 039E8C 7F00535C 8E0D0000 */  lw    $t5, ($s0)
/* 039E90 7F005360 E5A01004 */  swc1  $f0, 0x1004($t5)
/* 039E94 7F005364 8E0F0000 */  lw    $t7, ($s0)
/* 039E98 7F005368 E5E01008 */  swc1  $f0, 0x1008($t7)
/* 039E9C 7F00536C 8E0E0000 */  lw    $t6, ($s0)
/* 039EA0 7F005370 E5CC100C */  swc1  $f12, 0x100c($t6)
/* 039EA4 7F005374 8E0A0000 */  lw    $t2, ($s0)
/* 039EA8 7F005378 E5401010 */  swc1  $f0, 0x1010($t2)
/* 039EAC 7F00537C 8E0B0000 */  lw    $t3, ($s0)
/* 039EB0 7F005380 C424F0E4 */  lwc1  $f4, %lo(fl_neg_pi)($at)
/* 039EB4 7F005384 E5641014 */  swc1  $f4, 0x1014($t3)
/* 039EB8 7F005388 8E0C0000 */  lw    $t4, ($s0)
/* 039EBC 7F00538C E5801018 */  swc1  $f0, 0x1018($t4)
/* 039EC0 7F005390 8E090000 */  lw    $t1, ($s0)
/* 039EC4 7F005394 AD201060 */  sw    $zero, 0x1060($t1)
/* 039EC8 7F005398 8E190000 */  lw    $t9, ($s0)
/* 039ECC 7F00539C AF251270 */  sw    $a1, 0x1270($t9)
/* 039ED0 7F0053A0 8E180000 */  lw    $t8, ($s0)
/* 039ED4 7F0053A4 E700106C */  swc1  $f0, 0x106c($t8)
/* 039ED8 7F0053A8 8E080000 */  lw    $t0, ($s0)
/* 039EDC 7F0053AC E5001070 */  swc1  $f0, 0x1070($t0)
/* 039EE0 7F0053B0 8E0D0000 */  lw    $t5, ($s0)
/* 039EE4 7F0053B4 E5A01074 */  swc1  $f0, 0x1074($t5)
/* 039EE8 7F0053B8 8E0F0000 */  lw    $t7, ($s0)
/* 039EEC 7F0053BC ADE01078 */  sw    $zero, 0x1078($t7)
/* 039EF0 7F0053C0 8E0E0000 */  lw    $t6, ($s0)
/* 039EF4 7F0053C4 E5C0107C */  swc1  $f0, 0x107c($t6)
/* 039EF8 7F0053C8 8E0A0000 */  lw    $t2, ($s0)
/* 039EFC 7F0053CC 0FC17260 */  jal   unknown_takes_playerhand
/* 039F00 7F0053D0 E5401080 */   swc1  $f0, 0x1080($t2)
/* 039F04 7F0053D4 0FC17260 */  jal   unknown_takes_playerhand
/* 039F08 7F0053D8 00002025 */   move  $a0, $zero
/* 039F0C 7F0053DC 0FC17260 */  jal   unknown_takes_playerhand
/* 039F10 7F0053E0 00002025 */   move  $a0, $zero
/* 039F14 7F0053E4 0FC17260 */  jal   unknown_takes_playerhand
/* 039F18 7F0053E8 24040001 */   li    $a0, 1
/* 039F1C 7F0053EC 0FC17260 */  jal   unknown_takes_playerhand
/* 039F20 7F0053F0 24040001 */   li    $a0, 1
/* 039F24 7F0053F4 0FC17260 */  jal   unknown_takes_playerhand
/* 039F28 7F0053F8 24040001 */   li    $a0, 1
/* 039F2C 7F0053FC 8E0B0000 */  lw    $t3, ($s0)
/* 039F30 7F005400 240C0002 */  li    $t4, 2
/* 039F34 7F005404 3C018003 */  lui   $at, %hi(GsniperrifleZ_stats+52)
/* 039F38 7F005408 AD601064 */  sw    $zero, 0x1064($t3)
/* 039F3C 7F00540C 8E090000 */  lw    $t1, ($s0)
/* 039F40 7F005410 AD2C1128 */  sw    $t4, 0x1128($t1)
/* 039F44 7F005414 8E190000 */  lw    $t9, ($s0)
/* 039F48 7F005418 C4262C38 */  lwc1  $f6, %lo(GsniperrifleZ_stats+52)($at)
/* 039F4C 7F00541C 3C018003 */  lui   $at, %hi(GcameraZ_stats+52)
/* 039F50 7F005420 E7261084 */  swc1  $f6, 0x1084($t9)
/* 039F54 7F005424 8E180000 */  lw    $t8, ($s0)
/* 039F58 7F005428 C42836B8 */  lwc1  $f8, %lo(GcameraZ_stats+52)($at)
/* 039F5C 7F00542C E7081088 */  swc1  $f8, 0x1088($t8)
/* 039F60 7F005430 8FBF001C */  lw    $ra, 0x1c($sp)
/* 039F64 7F005434 8FB00018 */  lw    $s0, 0x18($sp)
/* 039F68 7F005438 27BD03D0 */  addiu $sp, $sp, 0x3d0
/* 039F6C 7F00543C 03E00008 */  jr    $ra
/* 039F70 7F005440 00000000 */   nop
)
#endif

