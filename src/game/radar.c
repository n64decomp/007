#include "ultra64.h"


// rodata


#ifdef NONMATCHING
void display_red_blue_on_radar(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_8005BD20
.word 0x40490fdb /*3.1415927*/
glabel D_8005BD24
.word 0x3c8efa35 /*0.017453292*/
.text
glabel display_red_blue_on_radar
/* 0FABC0 7F0C6090 27BDFF78 */  addiu $sp, $sp, -0x88
/* 0FABC4 7F0C6094 AFBF006C */  sw    $ra, 0x6c($sp)
/* 0FABC8 7F0C6098 AFB70068 */  sw    $s7, 0x68($sp)
/* 0FABCC 7F0C609C AFB60064 */  sw    $s6, 0x64($sp)
/* 0FABD0 7F0C60A0 AFB50060 */  sw    $s5, 0x60($sp)
/* 0FABD4 7F0C60A4 AFB4005C */  sw    $s4, 0x5c($sp)
/* 0FABD8 7F0C60A8 AFB30058 */  sw    $s3, 0x58($sp)
/* 0FABDC 7F0C60AC AFB20054 */  sw    $s2, 0x54($sp)
/* 0FABE0 7F0C60B0 AFB10050 */  sw    $s1, 0x50($sp)
/* 0FABE4 7F0C60B4 AFB0004C */  sw    $s0, 0x4c($sp)
/* 0FABE8 7F0C60B8 F7BE0040 */  sdc1  $f30, 0x40($sp)
/* 0FABEC 7F0C60BC F7BC0038 */  sdc1  $f28, 0x38($sp)
/* 0FABF0 7F0C60C0 F7BA0030 */  sdc1  $f26, 0x30($sp)
/* 0FABF4 7F0C60C4 F7B80028 */  sdc1  $f24, 0x28($sp)
/* 0FABF8 7F0C60C8 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 0FABFC 7F0C60CC F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0FAC00 7F0C60D0 0FC051D6 */  jal   get_scenario
/* 0FAC04 7F0C60D4 AFA40088 */   sw    $a0, 0x88($sp)
/* 0FAC08 7F0C60D8 0FC26C54 */  jal   get_cur_playernum
/* 0FAC0C 7F0C60DC 0040A025 */   move  $s4, $v0
/* 0FAC10 7F0C60E0 0FC26919 */  jal   get_num_players
/* 0FAC14 7F0C60E4 AFA20070 */   sw    $v0, 0x70($sp)
/* 0FAC18 7F0C60E8 24010001 */  li    $at, 1
/* 0FAC1C 7F0C60EC 14410003 */  bne   $v0, $at, .L7F0C60FC
/* 0FAC20 7F0C60F0 AFA20074 */   sw    $v0, 0x74($sp)
/* 0FAC24 7F0C60F4 10000124 */  b     .L7F0C6588
/* 0FAC28 7F0C60F8 8FA20088 */   lw    $v0, 0x88($sp)
.L7F0C60FC:
/* 0FAC2C 7F0C60FC 3C178008 */  lui   $s7, %hi(ptr_BONDdata) # $s7, 0x8008
/* 0FAC30 7F0C6100 26F7A0B0 */  addiu $s7, %lo(ptr_BONDdata) # addiu $s7, $s7, -0x5f50
/* 0FAC34 7F0C6104 8EE20000 */  lw    $v0, ($s7)
/* 0FAC38 7F0C6108 8C4E29C4 */  lw    $t6, 0x29c4($v0)
/* 0FAC3C 7F0C610C 15C00004 */  bnez  $t6, .L7F0C6120
/* 0FAC40 7F0C6110 00000000 */   nop   
/* 0FAC44 7F0C6114 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0FAC48 7F0C6118 11E00003 */  beqz  $t7, .L7F0C6128
/* 0FAC4C 7F0C611C 00000000 */   nop   
.L7F0C6120:
/* 0FAC50 7F0C6120 10000119 */  b     .L7F0C6588
/* 0FAC54 7F0C6124 8FA20088 */   lw    $v0, 0x88($sp)
.L7F0C6128:
/* 0FAC58 7F0C6128 0FC249EF */  jal   sub_GAME_7F0927BC
/* 0FAC5C 7F0C612C 24040017 */   li    $a0, 23
/* 0FAC60 7F0C6130 10400003 */  beqz  $v0, .L7F0C6140
/* 0FAC64 7F0C6134 00000000 */   nop   
/* 0FAC68 7F0C6138 10000113 */  b     .L7F0C6588
/* 0FAC6C 7F0C613C 8FA20088 */   lw    $v0, 0x88($sp)
.L7F0C6140:
/* 0FAC70 7F0C6140 0C001145 */  jal   get_video2_settings_ulx
/* 0FAC74 7F0C6144 00000000 */   nop   
/* 0FAC78 7F0C6148 00028400 */  sll   $s0, $v0, 0x10
/* 0FAC7C 7F0C614C 0010C403 */  sra   $t8, $s0, 0x10
/* 0FAC80 7F0C6150 0C001127 */  jal   get_video2_settings_width
/* 0FAC84 7F0C6154 03008025 */   move  $s0, $t8
/* 0FAC88 7F0C6158 0050A821 */  addu  $s5, $v0, $s0
/* 0FAC8C 7F0C615C 0C001149 */  jal   get_video2_settings_uly
/* 0FAC90 7F0C6160 26B5FFD7 */   addiu $s5, $s5, -0x29
/* 0FAC94 7F0C6164 8FB90074 */  lw    $t9, 0x74($sp)
/* 0FAC98 7F0C6168 2456001A */  addiu $s6, $v0, 0x1a
/* 0FAC9C 7F0C616C 27A40088 */  addiu $a0, $sp, 0x88
/* 0FACA0 7F0C6170 2B210003 */  slti  $at, $t9, 3
/* 0FACA4 7F0C6174 14200006 */  bnez  $at, .L7F0C6190
/* 0FACA8 7F0C6178 3C058009 */   lui   $a1, %hi(dword_CODE_bss_8008D12C) # $a1, 0x8009
/* 0FACAC 7F0C617C 8FA90070 */  lw    $t1, 0x70($sp)
/* 0FACB0 7F0C6180 312A0001 */  andi  $t2, $t1, 1
/* 0FACB4 7F0C6184 55400003 */  bnezl $t2, .L7F0C6194
/* 0FACB8 7F0C6188 240B0002 */   li    $t3, 2
/* 0FACBC 7F0C618C 26B5000F */  addiu $s5, $s5, 0xf
.L7F0C6190:
/* 0FACC0 7F0C6190 240B0002 */  li    $t3, 2
.L7F0C6194:
/* 0FACC4 7F0C6194 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0FACC8 7F0C6198 8CA5D12C */  lw    $a1, %lo(dword_CODE_bss_8008D12C)($a1)
/* 0FACCC 7F0C619C 24060002 */  li    $a2, 2
/* 0FACD0 7F0C61A0 0FC1DB5A */  jal   likely_generate_DL_for_image_declaration
/* 0FACD4 7F0C61A4 00003825 */   move  $a3, $zero
/* 0FACD8 7F0C61A8 0FC2B366 */  jal   microcode_constructor
/* 0FACDC 7F0C61AC 8FA40088 */   lw    $a0, 0x88($sp)
/* 0FACE0 7F0C61B0 244C0008 */  addiu $t4, $v0, 8
/* 0FACE4 7F0C61B4 AFAC0088 */  sw    $t4, 0x88($sp)
/* 0FACE8 7F0C61B8 3C0DFCFF */  lui   $t5, (0xFCFFB3FF >> 16) # lui $t5, 0xfcff
/* 0FACEC 7F0C61BC 3C0EFF65 */  lui   $t6, (0xFF65FEFF >> 16) # lui $t6, 0xff65
/* 0FACF0 7F0C61C0 35CEFEFF */  ori   $t6, (0xFF65FEFF & 0xFFFF) # ori $t6, $t6, 0xfeff
/* 0FACF4 7F0C61C4 35ADB3FF */  ori   $t5, (0xFCFFB3FF & 0xFFFF) # ori $t5, $t5, 0xb3ff
/* 0FACF8 7F0C61C8 AC4D0000 */  sw    $t5, ($v0)
/* 0FACFC 7F0C61CC AC4E0004 */  sw    $t6, 4($v0)
/* 0FAD00 7F0C61D0 8FAF0088 */  lw    $t7, 0x88($sp)
/* 0FAD04 7F0C61D4 3C19FA00 */  lui   $t9, 0xfa00
/* 0FAD08 7F0C61D8 240900A0 */  li    $t1, 160
/* 0FAD0C 7F0C61DC 25F80008 */  addiu $t8, $t7, 8
/* 0FAD10 7F0C61E0 AFB80088 */  sw    $t8, 0x88($sp)
/* 0FAD14 7F0C61E4 26AC0010 */  addiu $t4, $s5, 0x10
/* 0FAD18 7F0C61E8 ADE90004 */  sw    $t1, 4($t7)
/* 0FAD1C 7F0C61EC ADF90000 */  sw    $t9, ($t7)
/* 0FAD20 7F0C61F0 8FA40088 */  lw    $a0, 0x88($sp)
/* 0FAD24 7F0C61F4 000C6880 */  sll   $t5, $t4, 2
/* 0FAD28 7F0C61F8 31AE0FFF */  andi  $t6, $t5, 0xfff
/* 0FAD2C 7F0C61FC 26D90010 */  addiu $t9, $s6, 0x10
/* 0FAD30 7F0C6200 00194880 */  sll   $t1, $t9, 2
/* 0FAD34 7F0C6204 000E7B00 */  sll   $t7, $t6, 0xc
/* 0FAD38 7F0C6208 3C01E400 */  lui   $at, 0xe400
/* 0FAD3C 7F0C620C 01E1C025 */  or    $t8, $t7, $at
/* 0FAD40 7F0C6210 312A0FFF */  andi  $t2, $t1, 0xfff
/* 0FAD44 7F0C6214 26ACFFF0 */  addiu $t4, $s5, -0x10
/* 0FAD48 7F0C6218 248B0008 */  addiu $t3, $a0, 8
/* 0FAD4C 7F0C621C AFAB0088 */  sw    $t3, 0x88($sp)
/* 0FAD50 7F0C6220 000C6880 */  sll   $t5, $t4, 2
/* 0FAD54 7F0C6224 26D9FFF0 */  addiu $t9, $s6, -0x10
/* 0FAD58 7F0C6228 00194880 */  sll   $t1, $t9, 2
/* 0FAD5C 7F0C622C 31AE0FFF */  andi  $t6, $t5, 0xfff
/* 0FAD60 7F0C6230 030A5825 */  or    $t3, $t8, $t2
/* 0FAD64 7F0C6234 31380FFF */  andi  $t8, $t1, 0xfff
/* 0FAD68 7F0C6238 000E7B00 */  sll   $t7, $t6, 0xc
/* 0FAD6C 7F0C623C 01F85025 */  or    $t2, $t7, $t8
/* 0FAD70 7F0C6240 AC8A0004 */  sw    $t2, 4($a0)
/* 0FAD74 7F0C6244 AC8B0000 */  sw    $t3, ($a0)
/* 0FAD78 7F0C6248 8FAB0088 */  lw    $t3, 0x88($sp)
/* 0FAD7C 7F0C624C 3C0E0010 */  lui   $t6, (0x00100010 >> 16) # lui $t6, 0x10
/* 0FAD80 7F0C6250 35CE0010 */  ori   $t6, (0x00100010 & 0xFFFF) # ori $t6, $t6, 0x10
/* 0FAD84 7F0C6254 256C0008 */  addiu $t4, $t3, 8
/* 0FAD88 7F0C6258 AFAC0088 */  sw    $t4, 0x88($sp)
/* 0FAD8C 7F0C625C 3C0DB400 */  lui   $t5, 0xb400
/* 0FAD90 7F0C6260 AD6D0000 */  sw    $t5, ($t3)
/* 0FAD94 7F0C6264 AD6E0004 */  sw    $t6, 4($t3)
/* 0FAD98 7F0C6268 8FB90088 */  lw    $t9, 0x88($sp)
/* 0FAD9C 7F0C626C 3C180400 */  lui   $t8, (0x04000400 >> 16) # lui $t8, 0x400
/* 0FADA0 7F0C6270 37180400 */  ori   $t8, (0x04000400 & 0xFFFF) # ori $t8, $t8, 0x400
/* 0FADA4 7F0C6274 27290008 */  addiu $t1, $t9, 8
/* 0FADA8 7F0C6278 AFA90088 */  sw    $t1, 0x88($sp)
/* 0FADAC 7F0C627C 3C0FB300 */  lui   $t7, 0xb300
/* 0FADB0 7F0C6280 AF2F0000 */  sw    $t7, ($t9)
/* 0FADB4 7F0C6284 AF380004 */  sw    $t8, 4($t9)
/* 0FADB8 7F0C6288 240B0040 */  li    $t3, 64
/* 0FADBC 7F0C628C 26CA0002 */  addiu $t2, $s6, 2
/* 0FADC0 7F0C6290 AFAA0010 */  sw    $t2, 0x10($sp)
/* 0FADC4 7F0C6294 AFAB0014 */  sw    $t3, 0x14($sp)
/* 0FADC8 7F0C6298 8FA40088 */  lw    $a0, 0x88($sp)
/* 0FADCC 7F0C629C 26A5FFFE */  addiu $a1, $s5, -2
/* 0FADD0 7F0C62A0 26C6FFFE */  addiu $a2, $s6, -2
/* 0FADD4 7F0C62A4 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0FADD8 7F0C62A8 26A70002 */   addiu $a3, $s5, 2
/* 0FADDC 7F0C62AC 24010005 */  li    $at, 5
/* 0FADE0 7F0C62B0 1281000A */  beq   $s4, $at, .L7F0C62DC
/* 0FADE4 7F0C62B4 AFA20088 */   sw    $v0, 0x88($sp)
/* 0FADE8 7F0C62B8 24010006 */  li    $at, 6
/* 0FADEC 7F0C62BC 12810007 */  beq   $s4, $at, .L7F0C62DC
/* 0FADF0 7F0C62C0 24010007 */   li    $at, 7
/* 0FADF4 7F0C62C4 12810005 */  beq   $s4, $at, .L7F0C62DC
/* 0FADF8 7F0C62C8 24010002 */   li    $at, 2
/* 0FADFC 7F0C62CC 12810003 */  beq   $s4, $at, .L7F0C62DC
/* 0FAE00 7F0C62D0 24010003 */   li    $at, 3
/* 0FAE04 7F0C62D4 16810018 */  bne   $s4, $at, .L7F0C6338
/* 0FAE08 7F0C62D8 8FA40088 */   lw    $a0, 0x88($sp)
.L7F0C62DC:
/* 0FAE0C 7F0C62DC 8FAC0070 */  lw    $t4, 0x70($sp)
/* 0FAE10 7F0C62E0 3C0E8008 */  lui   $t6, %hi(player1_player_data+0x69)
/* 0FAE14 7F0C62E4 8FA40088 */  lw    $a0, 0x88($sp)
/* 0FAE18 7F0C62E8 000C68C0 */  sll   $t5, $t4, 3
/* 0FAE1C 7F0C62EC 01AC6823 */  subu  $t5, $t5, $t4
/* 0FAE20 7F0C62F0 000D6900 */  sll   $t5, $t5, 4
/* 0FAE24 7F0C62F4 01CD7021 */  addu  $t6, $t6, $t5
/* 0FAE28 7F0C62F8 91CE9F59 */  lbu   $t6, %lo(player1_player_data+0x69)($t6)
/* 0FAE2C 7F0C62FC 26A5FFFF */  addiu $a1, $s5, -1
/* 0FAE30 7F0C6300 26C6FFFF */  addiu $a2, $s6, -1
/* 0FAE34 7F0C6304 15C00004 */  bnez  $t6, .L7F0C6318
/* 0FAE38 7F0C6308 26A70001 */   addiu $a3, $s5, 1
/* 0FAE3C 7F0C630C 3C02FF77 */  lui   $v0, (0xFF7777FF >> 16) # lui $v0, 0xff77
/* 0FAE40 7F0C6310 10000003 */  b     .L7F0C6320
/* 0FAE44 7F0C6314 344277FF */   ori   $v0, (0xFF7777FF & 0xFFFF) # ori $v0, $v0, 0x77ff
.L7F0C6318:
/* 0FAE48 7F0C6318 3C028888 */  lui   $v0, (0x8888FFFF >> 16) # lui $v0, 0x8888
/* 0FAE4C 7F0C631C 3442FFFF */  ori   $v0, (0x8888FFFF & 0xFFFF) # ori $v0, $v0, 0xffff
.L7F0C6320:
/* 0FAE50 7F0C6320 26D90001 */  addiu $t9, $s6, 1
/* 0FAE54 7F0C6324 AFB90010 */  sw    $t9, 0x10($sp)
/* 0FAE58 7F0C6328 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0FAE5C 7F0C632C AFA20014 */   sw    $v0, 0x14($sp)
/* 0FAE60 7F0C6330 1000000A */  b     .L7F0C635C
/* 0FAE64 7F0C6334 AFA20088 */   sw    $v0, 0x88($sp)
.L7F0C6338:
/* 0FAE68 7F0C6338 26C90001 */  addiu $t1, $s6, 1
/* 0FAE6C 7F0C633C 240FFFA0 */  li    $t7, -96
/* 0FAE70 7F0C6340 AFAF0014 */  sw    $t7, 0x14($sp)
/* 0FAE74 7F0C6344 AFA90010 */  sw    $t1, 0x10($sp)
/* 0FAE78 7F0C6348 26A5FFFF */  addiu $a1, $s5, -1
/* 0FAE7C 7F0C634C 26C6FFFF */  addiu $a2, $s6, -1
/* 0FAE80 7F0C6350 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0FAE84 7F0C6354 26A70001 */   addiu $a3, $s5, 1
/* 0FAE88 7F0C6358 AFA20088 */  sw    $v0, 0x88($sp)
.L7F0C635C:
/* 0FAE8C 7F0C635C 8FB80074 */  lw    $t8, 0x74($sp)
/* 0FAE90 7F0C6360 00009825 */  move  $s3, $zero
/* 0FAE94 7F0C6364 3C014334 */  li    $at, 0x43340000 # 180.000000
/* 0FAE98 7F0C6368 1B000085 */  blez  $t8, .L7F0C6580
/* 0FAE9C 7F0C636C 00000000 */   nop   
/* 0FAEA0 7F0C6370 4481F000 */  mtc1  $at, $f30
/* 0FAEA4 7F0C6374 00000000 */  nop   
/* 0FAEA8 7F0C6378 8FAA0070 */  lw    $t2, 0x70($sp)
.L7F0C637C:
/* 0FAEAC 7F0C637C 00135880 */  sll   $t3, $s3, 2
/* 0FAEB0 7F0C6380 3C048008 */  lui   $a0, %hi(ptr_BONDdata_p1)
/* 0FAEB4 7F0C6384 126A007A */  beq   $s3, $t2, .L7F0C6570
/* 0FAEB8 7F0C6388 008B2021 */   addu  $a0, $a0, $t3
/* 0FAEBC 7F0C638C 8C849EE0 */  lw    $a0, %lo(ptr_BONDdata_p1)($a0)
/* 0FAEC0 7F0C6390 8C8C00D8 */  lw    $t4, 0xd8($a0)
/* 0FAEC4 7F0C6394 55800077 */  bnezl $t4, .L7F0C6574
/* 0FAEC8 7F0C6398 8FB80074 */   lw    $t8, 0x74($sp)
/* 0FAECC 7F0C639C 8EED0000 */  lw    $t5, ($s7)
/* 0FAED0 7F0C63A0 8C8200A8 */  lw    $v0, 0xa8($a0)
/* 0FAED4 7F0C63A4 3C014180 */  li    $at, 0x41800000 # 16.000000
/* 0FAED8 7F0C63A8 8DA300A8 */  lw    $v1, 0xa8($t5)
/* 0FAEDC 7F0C63AC C45C0008 */  lwc1  $f28, 8($v0)
/* 0FAEE0 7F0C63B0 C4520010 */  lwc1  $f18, 0x10($v0)
/* 0FAEE4 7F0C63B4 C4700008 */  lwc1  $f16, 8($v1)
/* 0FAEE8 7F0C63B8 C46A0010 */  lwc1  $f10, 0x10($v1)
/* 0FAEEC 7F0C63BC 44814000 */  mtc1  $at, $f8
/* 0FAEF0 7F0C63C0 4610E501 */  sub.s $f20, $f28, $f16
/* 0FAEF4 7F0C63C4 3C01457A */  li    $at, 0x457A0000 # 4000.000000
/* 0FAEF8 7F0C63C8 44818000 */  mtc1  $at, $f16
/* 0FAEFC 7F0C63CC 460A9581 */  sub.s $f22, $f18, $f10
/* 0FAF00 7F0C63D0 240E0010 */  li    $t6, 16
/* 0FAF04 7F0C63D4 448E5000 */  mtc1  $t6, $f10
/* 0FAF08 7F0C63D8 46104683 */  div.s $f26, $f8, $f16
/* 0FAF0C 7F0C63DC 4600A306 */  mov.s $f12, $f20
/* 0FAF10 7F0C63E0 4600B386 */  mov.s $f14, $f22
/* 0FAF14 7F0C63E4 0FC16A8C */  jal   convert_angle_using_inverse
/* 0FAF18 7F0C63E8 46805620 */   cvt.s.w $f24, $f10
/* 0FAF1C 7F0C63EC 461E0182 */  mul.s $f6, $f0, $f30
/* 0FAF20 7F0C63F0 3C018006 */  lui   $at, %hi(D_8005BD20) # $at, 0x8006
/* 0FAF24 7F0C63F4 C428BD20 */  lwc1  $f8, %lo(D_8005BD20)($at)
/* 0FAF28 7F0C63F8 4614A102 */  mul.s $f4, $f20, $f20
/* 0FAF2C 7F0C63FC 8EF90000 */  lw    $t9, ($s7)
/* 0FAF30 7F0C6400 C7300148 */  lwc1  $f16, 0x148($t9)
/* 0FAF34 7F0C6404 46083283 */  div.s $f10, $f6, $f8
/* 0FAF38 7F0C6408 4616B182 */  mul.s $f6, $f22, $f22
/* 0FAF3C 7F0C640C 46062300 */  add.s $f12, $f4, $f6
/* 0FAF40 7F0C6410 46105480 */  add.s $f18, $f10, $f16
/* 0FAF44 7F0C6414 0C007DF8 */  jal   sqrtf
/* 0FAF48 7F0C6418 461E9700 */   add.s $f28, $f18, $f30
/* 0FAF4C 7F0C641C 461A0082 */  mul.s $f2, $f0, $f26
/* 0FAF50 7F0C6420 24010005 */  li    $at, 5
/* 0FAF54 7F0C6424 001348C0 */  sll   $t1, $s3, 3
/* 0FAF58 7F0C6428 01334823 */  subu  $t1, $t1, $s3
/* 0FAF5C 7F0C642C 1281000A */  beq   $s4, $at, .L7F0C6458
/* 0FAF60 7F0C6430 46001586 */   mov.s $f22, $f2
/* 0FAF64 7F0C6434 24010006 */  li    $at, 6
/* 0FAF68 7F0C6438 12810007 */  beq   $s4, $at, .L7F0C6458
/* 0FAF6C 7F0C643C 24010007 */   li    $at, 7
/* 0FAF70 7F0C6440 12810005 */  beq   $s4, $at, .L7F0C6458
/* 0FAF74 7F0C6444 24010002 */   li    $at, 2
/* 0FAF78 7F0C6448 12810003 */  beq   $s4, $at, .L7F0C6458
/* 0FAF7C 7F0C644C 24010003 */   li    $at, 3
/* 0FAF80 7F0C6450 5681001B */  bnel  $s4, $at, .L7F0C64C0
/* 0FAF84 7F0C6454 4618103C */   c.lt.s $f2, $f24
.L7F0C6458:
/* 0FAF88 7F0C6458 4618103C */  c.lt.s $f2, $f24
/* 0FAF8C 7F0C645C 3C0F8008 */  lui   $t7, %hi(player1_player_data) # $t7, 0x8008
/* 0FAF90 7F0C6460 25EF9EF0 */  addiu $t7, %lo(player1_player_data) # addiu $t7, $t7, -0x6110
/* 0FAF94 7F0C6464 00094900 */  sll   $t1, $t1, 4
/* 0FAF98 7F0C6468 4500000A */  bc1f  .L7F0C6494
/* 0FAF9C 7F0C646C 012F1021 */   addu  $v0, $t1, $t7
/* 0FAFA0 7F0C6470 90580069 */  lbu   $t8, 0x69($v0)
/* 0FAFA4 7F0C6474 3C112828 */  lui   $s1, 0x2828
/* 0FAFA8 7F0C6478 17000004 */  bnez  $t8, .L7F0C648C
/* 0FAFAC 7F0C647C 00000000 */   nop   
/* 0FAFB0 7F0C6480 3C11FF00 */  lui   $s1, (0xFF00FFFF >> 16) # lui $s1, 0xff00
/* 0FAFB4 7F0C6484 10000016 */  b     .L7F0C64E0
/* 0FAFB8 7F0C6488 363100A0 */   ori   $s1, (0xFF0000A0 & 0xFFFF) # ori $s1, $s1, 0xa0
.L7F0C648C:
/* 0FAFBC 7F0C648C 10000014 */  b     .L7F0C64E0
/* 0FAFC0 7F0C6490 3631FFFF */   ori   $s1, (0xFF00FFFF & 0xFFFF) # ori $s1, $s1, 0xffff
.L7F0C6494:
/* 0FAFC4 7F0C6494 904A0069 */  lbu   $t2, 0x69($v0)
/* 0FAFC8 7F0C6498 4600C586 */  mov.s $f22, $f24
/* 0FAFCC 7F0C649C 3C112828 */  lui   $s1, 0x2828
/* 0FAFD0 7F0C64A0 15400004 */  bnez  $t2, .L7F0C64B4
/* 0FAFD4 7F0C64A4 00000000 */   nop   
/* 0FAFD8 7F0C64A8 3C11FF00 */  lui   $s1, (0xFF00FFB0 >> 16) # lui $s1, 0xff00
/* 0FAFDC 7F0C64AC 1000000C */  b     .L7F0C64E0
/* 0FAFE0 7F0C64B0 36310060 */   ori   $s1, (0xFF000060 & 0xFFFF) # ori $s1, $s1, 0x60
.L7F0C64B4:
/* 0FAFE4 7F0C64B4 1000000A */  b     .L7F0C64E0
/* 0FAFE8 7F0C64B8 3631FFB0 */   ori   $s1, (0xFF00FFB0 & 0xFFFF) # ori $s1, $s1, 0xffb0
/* 0FAFEC 7F0C64BC 4618103C */  c.lt.s $f2, $f24
.L7F0C64C0:
/* 0FAFF0 7F0C64C0 3C11FFFF */  lui   $s1, (0xFFFF0060 >> 16) # lui $s1, 0xffff
/* 0FAFF4 7F0C64C4 36310060 */  ori   $s1, (0xFFFF0060 & 0xFFFF) # ori $s1, $s1, 0x60
/* 0FAFF8 7F0C64C8 45020005 */  bc1fl .L7F0C64E0
/* 0FAFFC 7F0C64CC 4600C586 */   mov.s $f22, $f24
/* 0FB000 7F0C64D0 3C11FFFF */  lui   $s1, (0xFFFF00A0 >> 16) # lui $s1, 0xffff
/* 0FB004 7F0C64D4 10000002 */  b     .L7F0C64E0
/* 0FB008 7F0C64D8 363100A0 */   ori   $s1, (0xFFFF00A0 & 0xFFFF) # ori $s1, $s1, 0xa0
/* 0FB00C 7F0C64DC 4600C586 */  mov.s $f22, $f24
.L7F0C64E0:
/* 0FB010 7F0C64E0 3C018006 */  lui   $at, %hi(D_8005BD24) # $at, 0x8006
/* 0FB014 7F0C64E4 C428BD24 */  lwc1  $f8, %lo(D_8005BD24)($at)
/* 0FB018 7F0C64E8 4608E502 */  mul.s $f20, $f28, $f8
/* 0FB01C 7F0C64EC 0FC15FAB */  jal   sinf
/* 0FB020 7F0C64F0 4600A306 */   mov.s $f12, $f20
/* 0FB024 7F0C64F4 46160282 */  mul.s $f10, $f0, $f22
/* 0FB028 7F0C64F8 4600A306 */  mov.s $f12, $f20
/* 0FB02C 7F0C64FC 4600540D */  trunc.w.s $f16, $f10
/* 0FB030 7F0C6500 440C8000 */  mfc1  $t4, $f16
/* 0FB034 7F0C6504 0FC15FA8 */  jal   cosf
/* 0FB038 7F0C6508 01958021 */   addu  $s0, $t4, $s5
/* 0FB03C 7F0C650C 46160482 */  mul.s $f18, $f0, $f22
/* 0FB040 7F0C6510 24090040 */  li    $t1, 64
/* 0FB044 7F0C6514 AFA90014 */  sw    $t1, 0x14($sp)
/* 0FB048 7F0C6518 8FA40088 */  lw    $a0, 0x88($sp)
/* 0FB04C 7F0C651C 2605FFFE */  addiu $a1, $s0, -2
/* 0FB050 7F0C6520 26070002 */  addiu $a3, $s0, 2
/* 0FB054 7F0C6524 4600910D */  trunc.w.s $f4, $f18
/* 0FB058 7F0C6528 440E2000 */  mfc1  $t6, $f4
/* 0FB05C 7F0C652C 00000000 */  nop   
/* 0FB060 7F0C6530 01D61021 */  addu  $v0, $t6, $s6
/* 0FB064 7F0C6534 24590002 */  addiu $t9, $v0, 2
/* 0FB068 7F0C6538 00409025 */  move  $s2, $v0
/* 0FB06C 7F0C653C AFB90010 */  sw    $t9, 0x10($sp)
/* 0FB070 7F0C6540 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0FB074 7F0C6544 2446FFFE */   addiu $a2, $v0, -2
/* 0FB078 7F0C6548 264F0001 */  addiu $t7, $s2, 1
/* 0FB07C 7F0C654C AFA20088 */  sw    $v0, 0x88($sp)
/* 0FB080 7F0C6550 AFAF0010 */  sw    $t7, 0x10($sp)
/* 0FB084 7F0C6554 00402025 */  move  $a0, $v0
/* 0FB088 7F0C6558 2605FFFF */  addiu $a1, $s0, -1
/* 0FB08C 7F0C655C 2646FFFF */  addiu $a2, $s2, -1
/* 0FB090 7F0C6560 26070001 */  addiu $a3, $s0, 1
/* 0FB094 7F0C6564 0FC2B405 */  jal   microcode_constructor_related_to_menus
/* 0FB098 7F0C6568 AFB10014 */   sw    $s1, 0x14($sp)
/* 0FB09C 7F0C656C AFA20088 */  sw    $v0, 0x88($sp)
.L7F0C6570:
/* 0FB0A0 7F0C6570 8FB80074 */  lw    $t8, 0x74($sp)
.L7F0C6574:
/* 0FB0A4 7F0C6574 26730001 */  addiu $s3, $s3, 1
/* 0FB0A8 7F0C6578 5678FF80 */  bnel  $s3, $t8, .L7F0C637C
/* 0FB0AC 7F0C657C 8FAA0070 */   lw    $t2, 0x70($sp)
.L7F0C6580:
/* 0FB0B0 7F0C6580 0FC2B3BC */  jal   combiner_bayer_lod_perspective
/* 0FB0B4 7F0C6584 8FA40088 */   lw    $a0, 0x88($sp)
.L7F0C6588:
/* 0FB0B8 7F0C6588 8FBF006C */  lw    $ra, 0x6c($sp)
/* 0FB0BC 7F0C658C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0FB0C0 7F0C6590 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 0FB0C4 7F0C6594 D7B80028 */  ldc1  $f24, 0x28($sp)
/* 0FB0C8 7F0C6598 D7BA0030 */  ldc1  $f26, 0x30($sp)
/* 0FB0CC 7F0C659C D7BC0038 */  ldc1  $f28, 0x38($sp)
/* 0FB0D0 7F0C65A0 D7BE0040 */  ldc1  $f30, 0x40($sp)
/* 0FB0D4 7F0C65A4 8FB0004C */  lw    $s0, 0x4c($sp)
/* 0FB0D8 7F0C65A8 8FB10050 */  lw    $s1, 0x50($sp)
/* 0FB0DC 7F0C65AC 8FB20054 */  lw    $s2, 0x54($sp)
/* 0FB0E0 7F0C65B0 8FB30058 */  lw    $s3, 0x58($sp)
/* 0FB0E4 7F0C65B4 8FB4005C */  lw    $s4, 0x5c($sp)
/* 0FB0E8 7F0C65B8 8FB50060 */  lw    $s5, 0x60($sp)
/* 0FB0EC 7F0C65BC 8FB60064 */  lw    $s6, 0x64($sp)
/* 0FB0F0 7F0C65C0 8FB70068 */  lw    $s7, 0x68($sp)
/* 0FB0F4 7F0C65C4 03E00008 */  jr    $ra
/* 0FB0F8 7F0C65C8 27BD0088 */   addiu $sp, $sp, 0x88
)
#endif


