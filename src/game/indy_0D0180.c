#include "ultra64.h"
#include "game/indy_0D0180.h"

// data
//D:8004EAC0
s32 D_8004EAC0 = 0;
//D:8004EAC4
s32 D_8004EAC4 = 0x103;
//D:8004EAC8
s32 indy_ready = 0;
//D:8004EACC
s32 D_8004EACC = 0x0;
//D:8004EAD0
s32 D_8004EAD0 = 0x0;


#ifdef NONMATCHING
void sub_GAME_7F0D0180(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0180
/* 104CB0 7F0D0180 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 104CB4 7F0D0184 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104CB8 7F0D0188 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104CBC 7F0D018C 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104CC0 7F0D0190 00001025 */  move  $v0, $zero
/* 104CC4 7F0D0194 24420004 */  addiu $v0, $v0, 4
.L7F0D0198:
/* 104CC8 7F0D0198 5443FFFF */  bnel  $v0, $v1, .L7F0D0198
/* 104CCC 7F0D019C 24420004 */   addiu $v0, $v0, 4
/* 104CD0 7F0D01A0 0C0033B0 */  jal   rmon_debug_stub_0
/* 104CD4 7F0D01A4 00000000 */   nop   
/* 104CD8 7F0D01A8 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104CDC 7F0D01AC 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104CE0 7F0D01B0 00001025 */  move  $v0, $zero
/* 104CE4 7F0D01B4 24420004 */  addiu $v0, $v0, 4
.L7F0D01B8:
/* 104CE8 7F0D01B8 5443FFFF */  bnel  $v0, $v1, .L7F0D01B8
/* 104CEC 7F0D01BC 24420004 */   addiu $v0, $v0, 4
/* 104CF0 7F0D01C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104CF4 7F0D01C4 27BD0018 */  addiu $sp, $sp, 0x18
/* 104CF8 7F0D01C8 03E00008 */  jr    $ra
/* 104CFC 7F0D01CC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D01D0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D01D0
/* 104D00 7F0D01D0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 104D04 7F0D01D4 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104D08 7F0D01D8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104D0C 7F0D01DC 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104D10 7F0D01E0 00001025 */  move  $v0, $zero
/* 104D14 7F0D01E4 24420004 */  addiu $v0, $v0, 4
.L7F0D01E8:
/* 104D18 7F0D01E8 5443FFFF */  bnel  $v0, $v1, .L7F0D01E8
/* 104D1C 7F0D01EC 24420004 */   addiu $v0, $v0, 4
/* 104D20 7F0D01F0 0C0033AE */  jal   rmon_debug_stub
/* 104D24 7F0D01F4 00000000 */   nop   
/* 104D28 7F0D01F8 3C030001 */  lui   $v1, (0x000186A0 >> 16) # lui $v1, 1
/* 104D2C 7F0D01FC 346386A0 */  ori   $v1, (0x000186A0 & 0xFFFF) # ori $v1, $v1, 0x86a0
/* 104D30 7F0D0200 00001025 */  move  $v0, $zero
/* 104D34 7F0D0204 24420004 */  addiu $v0, $v0, 4
.L7F0D0208:
/* 104D38 7F0D0208 5443FFFF */  bnel  $v0, $v1, .L7F0D0208
/* 104D3C 7F0D020C 24420004 */   addiu $v0, $v0, 4
/* 104D40 7F0D0210 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104D44 7F0D0214 27BD0018 */  addiu $sp, $sp, 0x18
/* 104D48 7F0D0218 03E00008 */  jr    $ra
/* 104D4C 7F0D021C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0220(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0220
/* 104D50 7F0D0220 27BDFAC0 */  addiu $sp, $sp, -0x540
/* 104D54 7F0D0224 27A20040 */  addiu $v0, $sp, 0x40
/* 104D58 7F0D0228 308F0007 */  andi  $t7, $a0, 7
/* 104D5C 7F0D022C AFBF0014 */  sw    $ra, 0x14($sp)
/* 104D60 7F0D0230 AFA40540 */  sw    $a0, 0x540($sp)
/* 104D64 7F0D0234 00A03025 */  move  $a2, $a1
/* 104D68 7F0D0238 00401825 */  move  $v1, $v0
/* 104D6C 7F0D023C 11E0002B */  beqz  $t7, .L7F0D02EC
/* 104D70 7F0D0240 00403825 */   move  $a3, $v0
/* 104D74 7F0D0244 2CA10501 */  sltiu $at, $a1, 0x501
/* 104D78 7F0D0248 14200003 */  bnez  $at, .L7F0D0258
/* 104D7C 7F0D024C 30580007 */   andi  $t8, $v0, 7
/* 104D80 7F0D0250 1000003D */  b     .L7F0D0348
/* 104D84 7F0D0254 00001025 */   move  $v0, $zero
.L7F0D0258:
/* 104D88 7F0D0258 13000003 */  beqz  $t8, .L7F0D0268
/* 104D8C 7F0D025C 3C088005 */   lui   $t0, %hi(D_8004EAC4) # $t0, 0x8005
/* 104D90 7F0D0260 27A70044 */  addiu $a3, $sp, 0x44
/* 104D94 7F0D0264 00E01825 */  move  $v1, $a3
.L7F0D0268:
/* 104D98 7F0D0268 00662021 */  addu  $a0, $v1, $a2
/* 104D9C 7F0D026C 0064082B */  sltu  $at, $v1, $a0
/* 104DA0 7F0D0270 10200007 */  beqz  $at, .L7F0D0290
/* 104DA4 7F0D0274 8FA20540 */   lw    $v0, 0x540($sp)
.L7F0D0278:
/* 104DA8 7F0D0278 90590000 */  lbu   $t9, ($v0)
/* 104DAC 7F0D027C 24630001 */  addiu $v1, $v1, 1
/* 104DB0 7F0D0280 0064082B */  sltu  $at, $v1, $a0
/* 104DB4 7F0D0284 24420001 */  addiu $v0, $v0, 1
/* 104DB8 7F0D0288 1420FFFB */  bnez  $at, .L7F0D0278
/* 104DBC 7F0D028C A079FFFF */   sb    $t9, -1($v1)
.L7F0D0290:
/* 104DC0 7F0D0290 8D08EAC4 */  lw    $t0, %lo(D_8004EAC4)($t0)
/* 104DC4 7F0D0294 24C50003 */  addiu $a1, $a2, 3
/* 104DC8 7F0D0298 2401FFFC */  li    $at, -4
/* 104DCC 7F0D029C 31090020 */  andi  $t1, $t0, 0x20
/* 104DD0 7F0D02A0 1120000D */  beqz  $t1, .L7F0D02D8
/* 104DD4 7F0D02A4 00A15024 */   and   $t2, $a1, $at
/* 104DD8 7F0D02A8 10C0000B */  beqz  $a2, .L7F0D02D8
/* 104DDC 7F0D02AC 00001025 */   move  $v0, $zero
/* 104DE0 7F0D02B0 30C40003 */  andi  $a0, $a2, 3
/* 104DE4 7F0D02B4 10800005 */  beqz  $a0, .L7F0D02CC
/* 104DE8 7F0D02B8 00801825 */   move  $v1, $a0
/* 104DEC 7F0D02BC 24420001 */  addiu $v0, $v0, 1
.L7F0D02C0:
/* 104DF0 7F0D02C0 5462FFFF */  bnel  $v1, $v0, .L7F0D02C0
/* 104DF4 7F0D02C4 24420001 */   addiu $v0, $v0, 1
/* 104DF8 7F0D02C8 10460003 */  beq   $v0, $a2, .L7F0D02D8
.L7F0D02CC:
/* 104DFC 7F0D02CC 24420004 */   addiu $v0, $v0, 4
.L7F0D02D0:
/* 104E00 7F0D02D0 5446FFFF */  bnel  $v0, $a2, .L7F0D02D0
/* 104E04 7F0D02D4 24420004 */   addiu $v0, $v0, 4
.L7F0D02D8:
/* 104E08 7F0D02D8 00E02025 */  move  $a0, $a3
/* 104E0C 7F0D02DC 0FC34074 */  jal   sub_GAME_7F0D01D0
/* 104E10 7F0D02E0 01402825 */   move  $a1, $t2
/* 104E14 7F0D02E4 10000018 */  b     .L7F0D0348
/* 104E18 7F0D02E8 24020001 */   li    $v0, 1
.L7F0D02EC:
/* 104E1C 7F0D02EC 3C0B8005 */  lui   $t3, %hi(D_8004EAC4) # $t3, 0x8005
/* 104E20 7F0D02F0 8D6BEAC4 */  lw    $t3, %lo(D_8004EAC4)($t3)
/* 104E24 7F0D02F4 24C50003 */  addiu $a1, $a2, 3
/* 104E28 7F0D02F8 2401FFFC */  li    $at, -4
/* 104E2C 7F0D02FC 316C0020 */  andi  $t4, $t3, 0x20
/* 104E30 7F0D0300 1180000D */  beqz  $t4, .L7F0D0338
/* 104E34 7F0D0304 00A16824 */   and   $t5, $a1, $at
/* 104E38 7F0D0308 10C0000B */  beqz  $a2, .L7F0D0338
/* 104E3C 7F0D030C 00001025 */   move  $v0, $zero
/* 104E40 7F0D0310 30C40003 */  andi  $a0, $a2, 3
/* 104E44 7F0D0314 10800005 */  beqz  $a0, .L7F0D032C
/* 104E48 7F0D0318 00801825 */   move  $v1, $a0
/* 104E4C 7F0D031C 24420001 */  addiu $v0, $v0, 1
.L7F0D0320:
/* 104E50 7F0D0320 5462FFFF */  bnel  $v1, $v0, .L7F0D0320
/* 104E54 7F0D0324 24420001 */   addiu $v0, $v0, 1
/* 104E58 7F0D0328 10460003 */  beq   $v0, $a2, .L7F0D0338
.L7F0D032C:
/* 104E5C 7F0D032C 24420004 */   addiu $v0, $v0, 4
.L7F0D0330:
/* 104E60 7F0D0330 5446FFFF */  bnel  $v0, $a2, .L7F0D0330
/* 104E64 7F0D0334 24420004 */   addiu $v0, $v0, 4
.L7F0D0338:
/* 104E68 7F0D0338 8FA40540 */  lw    $a0, 0x540($sp)
/* 104E6C 7F0D033C 0FC34074 */  jal   sub_GAME_7F0D01D0
/* 104E70 7F0D0340 01A02825 */   move  $a1, $t5
/* 104E74 7F0D0344 24020001 */  li    $v0, 1
.L7F0D0348:
/* 104E78 7F0D0348 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104E7C 7F0D034C 27BD0540 */  addiu $sp, $sp, 0x540
/* 104E80 7F0D0350 03E00008 */  jr    $ra
/* 104E84 7F0D0354 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0358(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0358
/* 104E88 7F0D0358 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 104E8C 7F0D035C AFBF0014 */  sw    $ra, 0x14($sp)
/* 104E90 7F0D0360 AFA60020 */  sw    $a2, 0x20($sp)
/* 104E94 7F0D0364 0FC34088 */  jal   sub_GAME_7F0D0220
/* 104E98 7F0D0368 AFA70024 */   sw    $a3, 0x24($sp)
/* 104E9C 7F0D036C 8FA40020 */  lw    $a0, 0x20($sp)
/* 104EA0 7F0D0370 0FC34088 */  jal   sub_GAME_7F0D0220
/* 104EA4 7F0D0374 8FA50024 */   lw    $a1, 0x24($sp)
/* 104EA8 7F0D0378 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104EAC 7F0D037C 27BD0018 */  addiu $sp, $sp, 0x18
/* 104EB0 7F0D0380 24020001 */  li    $v0, 1
/* 104EB4 7F0D0384 03E00008 */  jr    $ra
/* 104EB8 7F0D0388 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D038C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D038C
/* 104EBC 7F0D038C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 104EC0 7F0D0390 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 104EC4 7F0D0394 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104EC8 7F0D0398 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 104ECC 7F0D039C 240F0001 */  li    $t7, 1
/* 104ED0 7F0D03A0 24180014 */  li    $t8, 20
/* 104ED4 7F0D03A4 AFA40028 */  sw    $a0, 0x28($sp)
/* 104ED8 7F0D03A8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 104EDC 7F0D03AC AFAE001C */  sw    $t6, 0x1c($sp)
/* 104EE0 7F0D03B0 AFAF0020 */  sw    $t7, 0x20($sp)
/* 104EE4 7F0D03B4 AFB80024 */  sw    $t8, 0x24($sp)
/* 104EE8 7F0D03B8 24050014 */  li    $a1, 20
/* 104EEC 7F0D03BC 0FC34088 */  jal   sub_GAME_7F0D0220
/* 104EF0 7F0D03C0 27A4001C */   addiu $a0, $sp, 0x1c
/* 104EF4 7F0D03C4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104EF8 7F0D03C8 27BD0030 */  addiu $sp, $sp, 0x30
/* 104EFC 7F0D03CC 03E00008 */  jr    $ra
/* 104F00 7F0D03D0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D03D4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D03D4
/* 104F04 7F0D03D4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 104F08 7F0D03D8 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 104F0C 7F0D03DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 104F10 7F0D03E0 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 104F14 7F0D03E4 240F0002 */  li    $t7, 2
/* 104F18 7F0D03E8 24180014 */  li    $t8, 20
/* 104F1C 7F0D03EC AFA40028 */  sw    $a0, 0x28($sp)
/* 104F20 7F0D03F0 AFA5002C */  sw    $a1, 0x2c($sp)
/* 104F24 7F0D03F4 AFAE001C */  sw    $t6, 0x1c($sp)
/* 104F28 7F0D03F8 AFAF0020 */  sw    $t7, 0x20($sp)
/* 104F2C 7F0D03FC AFB80024 */  sw    $t8, 0x24($sp)
/* 104F30 7F0D0400 24050014 */  li    $a1, 20
/* 104F34 7F0D0404 0FC34088 */  jal   sub_GAME_7F0D0220
/* 104F38 7F0D0408 27A4001C */   addiu $a0, $sp, 0x1c
/* 104F3C 7F0D040C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104F40 7F0D0410 27BD0030 */  addiu $sp, $sp, 0x30
/* 104F44 7F0D0414 03E00008 */  jr    $ra
/* 104F48 7F0D0418 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D041C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D041C
/* 104F4C 7F0D041C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 104F50 7F0D0420 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 104F54 7F0D0424 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104F58 7F0D0428 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 104F5C 7F0D042C 240F0014 */  li    $t7, 20
/* 104F60 7F0D0430 AFA40028 */  sw    $a0, 0x28($sp)
/* 104F64 7F0D0434 AFA5002C */  sw    $a1, 0x2c($sp)
/* 104F68 7F0D0438 AFAE001C */  sw    $t6, 0x1c($sp)
/* 104F6C 7F0D043C AFA00020 */  sw    $zero, 0x20($sp)
/* 104F70 7F0D0440 AFAF0024 */  sw    $t7, 0x24($sp)
/* 104F74 7F0D0444 24050014 */  li    $a1, 20
/* 104F78 7F0D0448 0FC34088 */  jal   sub_GAME_7F0D0220
/* 104F7C 7F0D044C 27A4001C */   addiu $a0, $sp, 0x1c
/* 104F80 7F0D0450 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104F84 7F0D0454 27BD0030 */  addiu $sp, $sp, 0x30
/* 104F88 7F0D0458 03E00008 */  jr    $ra
/* 104F8C 7F0D045C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0460(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0460
/* 104F90 7F0D0460 27BDFED0 */  addiu $sp, $sp, -0x130
/* 104F94 7F0D0464 AFA50134 */  sw    $a1, 0x134($sp)
/* 104F98 7F0D0468 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 104F9C 7F0D046C AFA5002C */  sw    $a1, 0x2c($sp)
/* 104FA0 7F0D0470 AFBF0014 */  sw    $ra, 0x14($sp)
/* 104FA4 7F0D0474 AFA60138 */  sw    $a2, 0x138($sp)
/* 104FA8 7F0D0478 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 104FAC 7F0D047C 240F0003 */  li    $t7, 3
/* 104FB0 7F0D0480 24180114 */  li    $t8, 276
/* 104FB4 7F0D0484 AFA40028 */  sw    $a0, 0x28($sp)
/* 104FB8 7F0D0488 00C02825 */  move  $a1, $a2
/* 104FBC 7F0D048C AFAE001C */  sw    $t6, 0x1c($sp)
/* 104FC0 7F0D0490 AFAF0020 */  sw    $t7, 0x20($sp)
/* 104FC4 7F0D0494 AFB80024 */  sw    $t8, 0x24($sp)
/* 104FC8 7F0D0498 24060100 */  li    $a2, 256
/* 104FCC 7F0D049C 0C0029E8 */  jal   something_with_strings
/* 104FD0 7F0D04A0 27A40030 */   addiu $a0, $sp, 0x30
/* 104FD4 7F0D04A4 A3A0012F */  sb    $zero, 0x12f($sp)
/* 104FD8 7F0D04A8 27A4001C */  addiu $a0, $sp, 0x1c
/* 104FDC 7F0D04AC 0FC34088 */  jal   sub_GAME_7F0D0220
/* 104FE0 7F0D04B0 24050114 */   li    $a1, 276
/* 104FE4 7F0D04B4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 104FE8 7F0D04B8 27BD0130 */  addiu $sp, $sp, 0x130
/* 104FEC 7F0D04BC 03E00008 */  jr    $ra
/* 104FF0 7F0D04C0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D04C4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D04C4
/* 104FF4 7F0D04C4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 104FF8 7F0D04C8 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 104FFC 7F0D04CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 105000 7F0D04D0 AFA50034 */  sw    $a1, 0x34($sp)
/* 105004 7F0D04D4 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105008 7F0D04D8 240F0004 */  li    $t7, 4
/* 10500C 7F0D04DC 24180018 */  li    $t8, 24
/* 105010 7F0D04E0 AFA40024 */  sw    $a0, 0x24($sp)
/* 105014 7F0D04E4 AFA50028 */  sw    $a1, 0x28($sp)
/* 105018 7F0D04E8 AFAE0018 */  sw    $t6, 0x18($sp)
/* 10501C 7F0D04EC AFAF001C */  sw    $t7, 0x1c($sp)
/* 105020 7F0D04F0 AFB80020 */  sw    $t8, 0x20($sp)
/* 105024 7F0D04F4 AFA6002C */  sw    $a2, 0x2c($sp)
/* 105028 7F0D04F8 24050018 */  li    $a1, 24
/* 10502C 7F0D04FC 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105030 7F0D0500 27A40018 */   addiu $a0, $sp, 0x18
/* 105034 7F0D0504 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105038 7F0D0508 27BD0030 */  addiu $sp, $sp, 0x30
/* 10503C 7F0D050C 03E00008 */  jr    $ra
/* 105040 7F0D0510 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0514(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0514
/* 105044 7F0D0514 27BDFED0 */  addiu $sp, $sp, -0x130
/* 105048 7F0D0518 AFA50134 */  sw    $a1, 0x134($sp)
/* 10504C 7F0D051C 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105050 7F0D0520 AFA5002C */  sw    $a1, 0x2c($sp)
/* 105054 7F0D0524 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105058 7F0D0528 AFA60138 */  sw    $a2, 0x138($sp)
/* 10505C 7F0D052C 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105060 7F0D0530 240F0005 */  li    $t7, 5
/* 105064 7F0D0534 24180114 */  li    $t8, 276
/* 105068 7F0D0538 AFA40028 */  sw    $a0, 0x28($sp)
/* 10506C 7F0D053C 00C02825 */  move  $a1, $a2
/* 105070 7F0D0540 AFAE001C */  sw    $t6, 0x1c($sp)
/* 105074 7F0D0544 AFAF0020 */  sw    $t7, 0x20($sp)
/* 105078 7F0D0548 AFB80024 */  sw    $t8, 0x24($sp)
/* 10507C 7F0D054C 24060100 */  li    $a2, 256
/* 105080 7F0D0550 0C0029E8 */  jal   something_with_strings
/* 105084 7F0D0554 27A40030 */   addiu $a0, $sp, 0x30
/* 105088 7F0D0558 A3A0012F */  sb    $zero, 0x12f($sp)
/* 10508C 7F0D055C 27A4001C */  addiu $a0, $sp, 0x1c
/* 105090 7F0D0560 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105094 7F0D0564 24050114 */   li    $a1, 276
/* 105098 7F0D0568 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10509C 7F0D056C 27BD0130 */  addiu $sp, $sp, 0x130
/* 1050A0 7F0D0570 03E00008 */  jr    $ra
/* 1050A4 7F0D0574 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0578(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0578
/* 1050A8 7F0D0578 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 1050AC 7F0D057C 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 1050B0 7F0D0580 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1050B4 7F0D0584 AFA40038 */  sw    $a0, 0x38($sp)
/* 1050B8 7F0D0588 AFA5003C */  sw    $a1, 0x3c($sp)
/* 1050BC 7F0D058C 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1050C0 7F0D0590 240F0006 */  li    $t7, 6
/* 1050C4 7F0D0594 2418001C */  li    $t8, 28
/* 1050C8 7F0D0598 AFA40028 */  sw    $a0, 0x28($sp)
/* 1050CC 7F0D059C AFA5002C */  sw    $a1, 0x2c($sp)
/* 1050D0 7F0D05A0 AFAE001C */  sw    $t6, 0x1c($sp)
/* 1050D4 7F0D05A4 AFAF0020 */  sw    $t7, 0x20($sp)
/* 1050D8 7F0D05A8 AFB80024 */  sw    $t8, 0x24($sp)
/* 1050DC 7F0D05AC AFA60030 */  sw    $a2, 0x30($sp)
/* 1050E0 7F0D05B0 AFA70034 */  sw    $a3, 0x34($sp)
/* 1050E4 7F0D05B4 2405001C */  li    $a1, 28
/* 1050E8 7F0D05B8 0FC34088 */  jal   sub_GAME_7F0D0220
/* 1050EC 7F0D05BC 27A4001C */   addiu $a0, $sp, 0x1c
/* 1050F0 7F0D05C0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1050F4 7F0D05C4 27BD0038 */  addiu $sp, $sp, 0x38
/* 1050F8 7F0D05C8 03E00008 */  jr    $ra
/* 1050FC 7F0D05CC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D05D0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D05D0
/* 105100 7F0D05D0 27BDFED0 */  addiu $sp, $sp, -0x130
/* 105104 7F0D05D4 AFA50134 */  sw    $a1, 0x134($sp)
/* 105108 7F0D05D8 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 10510C 7F0D05DC AFA50028 */  sw    $a1, 0x28($sp)
/* 105110 7F0D05E0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105114 7F0D05E4 AFA40130 */  sw    $a0, 0x130($sp)
/* 105118 7F0D05E8 AFA60138 */  sw    $a2, 0x138($sp)
/* 10511C 7F0D05EC 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105120 7F0D05F0 240F0007 */  li    $t7, 7
/* 105124 7F0D05F4 24180118 */  li    $t8, 280
/* 105128 7F0D05F8 AFA40024 */  sw    $a0, 0x24($sp)
/* 10512C 7F0D05FC 00C02825 */  move  $a1, $a2
/* 105130 7F0D0600 AFA7013C */  sw    $a3, 0x13c($sp)
/* 105134 7F0D0604 AFAE0018 */  sw    $t6, 0x18($sp)
/* 105138 7F0D0608 AFAF001C */  sw    $t7, 0x1c($sp)
/* 10513C 7F0D060C AFB80020 */  sw    $t8, 0x20($sp)
/* 105140 7F0D0610 24060100 */  li    $a2, 256
/* 105144 7F0D0614 0C0029E8 */  jal   something_with_strings
/* 105148 7F0D0618 27A4002C */   addiu $a0, $sp, 0x2c
/* 10514C 7F0D061C 8FA9013C */  lw    $t1, 0x13c($sp)
/* 105150 7F0D0620 A3A0012B */  sb    $zero, 0x12b($sp)
/* 105154 7F0D0624 27A40018 */  addiu $a0, $sp, 0x18
/* 105158 7F0D0628 24050118 */  li    $a1, 280
/* 10515C 7F0D062C 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105160 7F0D0630 AFA9012C */   sw    $t1, 0x12c($sp)
/* 105164 7F0D0634 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105168 7F0D0638 27BD0130 */  addiu $sp, $sp, 0x130
/* 10516C 7F0D063C 03E00008 */  jr    $ra
/* 105170 7F0D0640 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0644(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0644
/* 105174 7F0D0644 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105178 7F0D0648 AFA70044 */  sw    $a3, 0x44($sp)
/* 10517C 7F0D064C 8FA70048 */  lw    $a3, 0x48($sp)
/* 105180 7F0D0650 2401FFFC */  li    $at, -4
/* 105184 7F0D0654 8FAC0044 */  lw    $t4, 0x44($sp)
/* 105188 7F0D0658 24F80003 */  addiu $t8, $a3, 3
/* 10518C 7F0D065C 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105190 7F0D0660 0301C824 */  and   $t9, $t8, $at
/* 105194 7F0D0664 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105198 7F0D0668 AFA40038 */  sw    $a0, 0x38($sp)
/* 10519C 7F0D066C AFA5003C */  sw    $a1, 0x3c($sp)
/* 1051A0 7F0D0670 AFA60040 */  sw    $a2, 0x40($sp)
/* 1051A4 7F0D0674 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1051A8 7F0D0678 240F0008 */  li    $t7, 8
/* 1051AC 7F0D067C 27280020 */  addiu $t0, $t9, 0x20
/* 1051B0 7F0D0680 AFA40024 */  sw    $a0, 0x24($sp)
/* 1051B4 7F0D0684 AFA50028 */  sw    $a1, 0x28($sp)
/* 1051B8 7F0D0688 AFA6002C */  sw    $a2, 0x2c($sp)
/* 1051BC 7F0D068C AFAE0018 */  sw    $t6, 0x18($sp)
/* 1051C0 7F0D0690 AFAF001C */  sw    $t7, 0x1c($sp)
/* 1051C4 7F0D0694 AFA80020 */  sw    $t0, 0x20($sp)
/* 1051C8 7F0D0698 8FA6004C */  lw    $a2, 0x4c($sp)
/* 1051CC 7F0D069C 24050020 */  li    $a1, 32
/* 1051D0 7F0D06A0 27A40018 */  addiu $a0, $sp, 0x18
/* 1051D4 7F0D06A4 AFA70034 */  sw    $a3, 0x34($sp)
/* 1051D8 7F0D06A8 0FC340D6 */  jal   sub_GAME_7F0D0358
/* 1051DC 7F0D06AC AFAC0030 */   sw    $t4, 0x30($sp)
/* 1051E0 7F0D06B0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1051E4 7F0D06B4 27BD0038 */  addiu $sp, $sp, 0x38
/* 1051E8 7F0D06B8 03E00008 */  jr    $ra
/* 1051EC 7F0D06BC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D06C0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D06C0
/* 1051F0 7F0D06C0 27BDFED0 */  addiu $sp, $sp, -0x130
/* 1051F4 7F0D06C4 24F90003 */  addiu $t9, $a3, 3
/* 1051F8 7F0D06C8 2401FFFC */  li    $at, -4
/* 1051FC 7F0D06CC AFA50134 */  sw    $a1, 0x134($sp)
/* 105200 7F0D06D0 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105204 7F0D06D4 03214024 */  and   $t0, $t9, $at
/* 105208 7F0D06D8 AFA5002C */  sw    $a1, 0x2c($sp)
/* 10520C 7F0D06DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 105210 7F0D06E0 AFA40130 */  sw    $a0, 0x130($sp)
/* 105214 7F0D06E4 AFA60138 */  sw    $a2, 0x138($sp)
/* 105218 7F0D06E8 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 10521C 7F0D06EC 240F0009 */  li    $t7, 9
/* 105220 7F0D06F0 25090114 */  addiu $t1, $t0, 0x114
/* 105224 7F0D06F4 AFA40028 */  sw    $a0, 0x28($sp)
/* 105228 7F0D06F8 00C02825 */  move  $a1, $a2
/* 10522C 7F0D06FC AFA7013C */  sw    $a3, 0x13c($sp)
/* 105230 7F0D0700 AFAE001C */  sw    $t6, 0x1c($sp)
/* 105234 7F0D0704 AFAF0020 */  sw    $t7, 0x20($sp)
/* 105238 7F0D0708 AFA90024 */  sw    $t1, 0x24($sp)
/* 10523C 7F0D070C 24060100 */  li    $a2, 256
/* 105240 7F0D0710 0C0029E8 */  jal   something_with_strings
/* 105244 7F0D0714 27A40030 */   addiu $a0, $sp, 0x30
/* 105248 7F0D0718 A3A0012F */  sb    $zero, 0x12f($sp)
/* 10524C 7F0D071C 27A4001C */  addiu $a0, $sp, 0x1c
/* 105250 7F0D0720 24050114 */  li    $a1, 276
/* 105254 7F0D0724 8FA60140 */  lw    $a2, 0x140($sp)
/* 105258 7F0D0728 0FC340D6 */  jal   sub_GAME_7F0D0358
/* 10525C 7F0D072C 8FA7013C */   lw    $a3, 0x13c($sp)
/* 105260 7F0D0730 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105264 7F0D0734 27BD0130 */  addiu $sp, $sp, 0x130
/* 105268 7F0D0738 03E00008 */  jr    $ra
/* 10526C 7F0D073C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0740(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0740
/* 105270 7F0D0740 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105274 7F0D0744 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105278 7F0D0748 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10527C 7F0D074C AFA50034 */  sw    $a1, 0x34($sp)
/* 105280 7F0D0750 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105284 7F0D0754 240F000A */  li    $t7, 10
/* 105288 7F0D0758 24180018 */  li    $t8, 24
/* 10528C 7F0D075C AFA40024 */  sw    $a0, 0x24($sp)
/* 105290 7F0D0760 AFA50028 */  sw    $a1, 0x28($sp)
/* 105294 7F0D0764 AFAE0018 */  sw    $t6, 0x18($sp)
/* 105298 7F0D0768 AFAF001C */  sw    $t7, 0x1c($sp)
/* 10529C 7F0D076C AFB80020 */  sw    $t8, 0x20($sp)
/* 1052A0 7F0D0770 AFA6002C */  sw    $a2, 0x2c($sp)
/* 1052A4 7F0D0774 24050018 */  li    $a1, 24
/* 1052A8 7F0D0778 0FC34088 */  jal   sub_GAME_7F0D0220
/* 1052AC 7F0D077C 27A40018 */   addiu $a0, $sp, 0x18
/* 1052B0 7F0D0780 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1052B4 7F0D0784 27BD0030 */  addiu $sp, $sp, 0x30
/* 1052B8 7F0D0788 03E00008 */  jr    $ra
/* 1052BC 7F0D078C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0790(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0790
/* 1052C0 7F0D0790 27BDFEC8 */  addiu $sp, $sp, -0x138
/* 1052C4 7F0D0794 AFA5013C */  sw    $a1, 0x13c($sp)
/* 1052C8 7F0D0798 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 1052CC 7F0D079C AFA5002C */  sw    $a1, 0x2c($sp)
/* 1052D0 7F0D07A0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1052D4 7F0D07A4 AFA40138 */  sw    $a0, 0x138($sp)
/* 1052D8 7F0D07A8 AFA60140 */  sw    $a2, 0x140($sp)
/* 1052DC 7F0D07AC 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1052E0 7F0D07B0 240F000F */  li    $t7, 15
/* 1052E4 7F0D07B4 2418011C */  li    $t8, 284
/* 1052E8 7F0D07B8 AFA40028 */  sw    $a0, 0x28($sp)
/* 1052EC 7F0D07BC 00C02825 */  move  $a1, $a2
/* 1052F0 7F0D07C0 AFA70144 */  sw    $a3, 0x144($sp)
/* 1052F4 7F0D07C4 AFAE001C */  sw    $t6, 0x1c($sp)
/* 1052F8 7F0D07C8 AFAF0020 */  sw    $t7, 0x20($sp)
/* 1052FC 7F0D07CC AFB80024 */  sw    $t8, 0x24($sp)
/* 105300 7F0D07D0 24060100 */  li    $a2, 256
/* 105304 7F0D07D4 0C0029E8 */  jal   something_with_strings
/* 105308 7F0D07D8 27A40030 */   addiu $a0, $sp, 0x30
/* 10530C 7F0D07DC 8FA90144 */  lw    $t1, 0x144($sp)
/* 105310 7F0D07E0 8FAA0148 */  lw    $t2, 0x148($sp)
/* 105314 7F0D07E4 A3A0012F */  sb    $zero, 0x12f($sp)
/* 105318 7F0D07E8 27A4001C */  addiu $a0, $sp, 0x1c
/* 10531C 7F0D07EC 2405011C */  li    $a1, 284
/* 105320 7F0D07F0 AFA90130 */  sw    $t1, 0x130($sp)
/* 105324 7F0D07F4 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105328 7F0D07F8 AFAA0134 */   sw    $t2, 0x134($sp)
/* 10532C 7F0D07FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105330 7F0D0800 27BD0138 */  addiu $sp, $sp, 0x138
/* 105334 7F0D0804 03E00008 */  jr    $ra
/* 105338 7F0D0808 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D080C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D080C
/* 10533C 7F0D080C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105340 7F0D0810 8FA90048 */  lw    $t1, 0x48($sp)
/* 105344 7F0D0814 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105348 7F0D0818 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10534C 7F0D081C AFA40038 */  sw    $a0, 0x38($sp)
/* 105350 7F0D0820 AFA5003C */  sw    $a1, 0x3c($sp)
/* 105354 7F0D0824 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105358 7F0D0828 240F0010 */  li    $t7, 16
/* 10535C 7F0D082C 24180020 */  li    $t8, 32
/* 105360 7F0D0830 AFA40024 */  sw    $a0, 0x24($sp)
/* 105364 7F0D0834 AFA50028 */  sw    $a1, 0x28($sp)
/* 105368 7F0D0838 AFAE0018 */  sw    $t6, 0x18($sp)
/* 10536C 7F0D083C AFAF001C */  sw    $t7, 0x1c($sp)
/* 105370 7F0D0840 AFB80020 */  sw    $t8, 0x20($sp)
/* 105374 7F0D0844 AFA6002C */  sw    $a2, 0x2c($sp)
/* 105378 7F0D0848 AFA70030 */  sw    $a3, 0x30($sp)
/* 10537C 7F0D084C 24050020 */  li    $a1, 32
/* 105380 7F0D0850 27A40018 */  addiu $a0, $sp, 0x18
/* 105384 7F0D0854 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105388 7F0D0858 AFA90034 */   sw    $t1, 0x34($sp)
/* 10538C 7F0D085C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105390 7F0D0860 27BD0038 */  addiu $sp, $sp, 0x38
/* 105394 7F0D0864 03E00008 */  jr    $ra
/* 105398 7F0D0868 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D086C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D086C
/* 10539C 7F0D086C 27BDFEC8 */  addiu $sp, $sp, -0x138
/* 1053A0 7F0D0870 AFA5013C */  sw    $a1, 0x13c($sp)
/* 1053A4 7F0D0874 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 1053A8 7F0D0878 AFA5002C */  sw    $a1, 0x2c($sp)
/* 1053AC 7F0D087C AFBF0014 */  sw    $ra, 0x14($sp)
/* 1053B0 7F0D0880 AFA40138 */  sw    $a0, 0x138($sp)
/* 1053B4 7F0D0884 AFA60140 */  sw    $a2, 0x140($sp)
/* 1053B8 7F0D0888 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1053BC 7F0D088C 240F000D */  li    $t7, 13
/* 1053C0 7F0D0890 2418011C */  li    $t8, 284
/* 1053C4 7F0D0894 AFA40028 */  sw    $a0, 0x28($sp)
/* 1053C8 7F0D0898 00C02825 */  move  $a1, $a2
/* 1053CC 7F0D089C AFA70144 */  sw    $a3, 0x144($sp)
/* 1053D0 7F0D08A0 AFAE001C */  sw    $t6, 0x1c($sp)
/* 1053D4 7F0D08A4 AFAF0020 */  sw    $t7, 0x20($sp)
/* 1053D8 7F0D08A8 AFB80024 */  sw    $t8, 0x24($sp)
/* 1053DC 7F0D08AC 24060100 */  li    $a2, 256
/* 1053E0 7F0D08B0 0C0029E8 */  jal   something_with_strings
/* 1053E4 7F0D08B4 27A40030 */   addiu $a0, $sp, 0x30
/* 1053E8 7F0D08B8 8FA90144 */  lw    $t1, 0x144($sp)
/* 1053EC 7F0D08BC 8FAA0148 */  lw    $t2, 0x148($sp)
/* 1053F0 7F0D08C0 A3A0012F */  sb    $zero, 0x12f($sp)
/* 1053F4 7F0D08C4 27A4001C */  addiu $a0, $sp, 0x1c
/* 1053F8 7F0D08C8 2405011C */  li    $a1, 284
/* 1053FC 7F0D08CC AFA90130 */  sw    $t1, 0x130($sp)
/* 105400 7F0D08D0 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105404 7F0D08D4 AFAA0134 */   sw    $t2, 0x134($sp)
/* 105408 7F0D08D8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10540C 7F0D08DC 27BD0138 */  addiu $sp, $sp, 0x138
/* 105410 7F0D08E0 03E00008 */  jr    $ra
/* 105414 7F0D08E4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D08E8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D08E8
/* 105418 7F0D08E8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 10541C 7F0D08EC 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105420 7F0D08F0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105424 7F0D08F4 AFA50034 */  sw    $a1, 0x34($sp)
/* 105428 7F0D08F8 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 10542C 7F0D08FC 240F000E */  li    $t7, 14
/* 105430 7F0D0900 24180018 */  li    $t8, 24
/* 105434 7F0D0904 AFA40024 */  sw    $a0, 0x24($sp)
/* 105438 7F0D0908 AFA50028 */  sw    $a1, 0x28($sp)
/* 10543C 7F0D090C AFAE0018 */  sw    $t6, 0x18($sp)
/* 105440 7F0D0910 AFAF001C */  sw    $t7, 0x1c($sp)
/* 105444 7F0D0914 AFB80020 */  sw    $t8, 0x20($sp)
/* 105448 7F0D0918 AFA6002C */  sw    $a2, 0x2c($sp)
/* 10544C 7F0D091C 24050018 */  li    $a1, 24
/* 105450 7F0D0920 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105454 7F0D0924 27A40018 */   addiu $a0, $sp, 0x18
/* 105458 7F0D0928 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10545C 7F0D092C 27BD0030 */  addiu $sp, $sp, 0x30
/* 105460 7F0D0930 03E00008 */  jr    $ra
/* 105464 7F0D0934 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0938(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0938
/* 105468 7F0D0938 27BDFBD0 */  addiu $sp, $sp, -0x430
/* 10546C 7F0D093C AFA50434 */  sw    $a1, 0x434($sp)
/* 105470 7F0D0940 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105474 7F0D0944 AFA5002C */  sw    $a1, 0x2c($sp)
/* 105478 7F0D0948 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10547C 7F0D094C AFA60438 */  sw    $a2, 0x438($sp)
/* 105480 7F0D0950 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105484 7F0D0954 240F000B */  li    $t7, 11
/* 105488 7F0D0958 24180414 */  li    $t8, 1044
/* 10548C 7F0D095C AFA40028 */  sw    $a0, 0x28($sp)
/* 105490 7F0D0960 00C02825 */  move  $a1, $a2
/* 105494 7F0D0964 AFAE001C */  sw    $t6, 0x1c($sp)
/* 105498 7F0D0968 AFAF0020 */  sw    $t7, 0x20($sp)
/* 10549C 7F0D096C AFB80024 */  sw    $t8, 0x24($sp)
/* 1054A0 7F0D0970 24060400 */  li    $a2, 1024
/* 1054A4 7F0D0974 0C0029E8 */  jal   something_with_strings
/* 1054A8 7F0D0978 27A40030 */   addiu $a0, $sp, 0x30
/* 1054AC 7F0D097C A3A0042F */  sb    $zero, 0x42f($sp)
/* 1054B0 7F0D0980 27A4001C */  addiu $a0, $sp, 0x1c
/* 1054B4 7F0D0984 0FC34088 */  jal   sub_GAME_7F0D0220
/* 1054B8 7F0D0988 24050414 */   li    $a1, 1044
/* 1054BC 7F0D098C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1054C0 7F0D0990 27BD0430 */  addiu $sp, $sp, 0x430
/* 1054C4 7F0D0994 03E00008 */  jr    $ra
/* 1054C8 7F0D0998 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D099C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D099C
/* 1054CC 7F0D099C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1054D0 7F0D09A0 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 1054D4 7F0D09A4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1054D8 7F0D09A8 AFA50034 */  sw    $a1, 0x34($sp)
/* 1054DC 7F0D09AC 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 1054E0 7F0D09B0 240F000C */  li    $t7, 12
/* 1054E4 7F0D09B4 24180018 */  li    $t8, 24
/* 1054E8 7F0D09B8 AFA40024 */  sw    $a0, 0x24($sp)
/* 1054EC 7F0D09BC AFA50028 */  sw    $a1, 0x28($sp)
/* 1054F0 7F0D09C0 AFAE0018 */  sw    $t6, 0x18($sp)
/* 1054F4 7F0D09C4 AFAF001C */  sw    $t7, 0x1c($sp)
/* 1054F8 7F0D09C8 AFB80020 */  sw    $t8, 0x20($sp)
/* 1054FC 7F0D09CC AFA6002C */  sw    $a2, 0x2c($sp)
/* 105500 7F0D09D0 24050018 */  li    $a1, 24
/* 105504 7F0D09D4 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105508 7F0D09D8 27A40018 */   addiu $a0, $sp, 0x18
/* 10550C 7F0D09DC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105510 7F0D09E0 27BD0030 */  addiu $sp, $sp, 0x30
/* 105514 7F0D09E4 03E00008 */  jr    $ra
/* 105518 7F0D09E8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D09EC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D09EC
/* 10551C 7F0D09EC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105520 7F0D09F0 3C0E9ABF */  lui   $t6, (0x9ABF1623 >> 16) # lui $t6, 0x9abf
/* 105524 7F0D09F4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105528 7F0D09F8 AFA50034 */  sw    $a1, 0x34($sp)
/* 10552C 7F0D09FC 35CE1623 */  ori   $t6, (0x9ABF1623 & 0xFFFF) # ori $t6, $t6, 0x1623
/* 105530 7F0D0A00 240F000A */  li    $t7, 10
/* 105534 7F0D0A04 24180018 */  li    $t8, 24
/* 105538 7F0D0A08 AFA40024 */  sw    $a0, 0x24($sp)
/* 10553C 7F0D0A0C AFA50028 */  sw    $a1, 0x28($sp)
/* 105540 7F0D0A10 AFAE0018 */  sw    $t6, 0x18($sp)
/* 105544 7F0D0A14 AFAF001C */  sw    $t7, 0x1c($sp)
/* 105548 7F0D0A18 AFB80020 */  sw    $t8, 0x20($sp)
/* 10554C 7F0D0A1C AFA6002C */  sw    $a2, 0x2c($sp)
/* 105550 7F0D0A20 24050018 */  li    $a1, 24
/* 105554 7F0D0A24 0FC34088 */  jal   sub_GAME_7F0D0220
/* 105558 7F0D0A28 27A40018 */   addiu $a0, $sp, 0x18
/* 10555C 7F0D0A2C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105560 7F0D0A30 27BD0030 */  addiu $sp, $sp, 0x30
/* 105564 7F0D0A34 03E00008 */  jr    $ra
/* 105568 7F0D0A38 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indy__res_cmd_initialize(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indy__res_cmd_initialize
/* 10556C 7F0D0A3C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105570 7F0D0A40 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105574 7F0D0A44 24040014 */  li    $a0, 20
/* 105578 7F0D0A48 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 10557C 7F0D0A4C 24050014 */   li    $a1, 20
/* 105580 7F0D0A50 24040014 */  li    $a0, 20
/* 105584 7F0D0A54 0FC34107 */  jal   sub_GAME_7F0D041C
/* 105588 7F0D0A58 24050014 */   li    $a1, 20
/* 10558C 7F0D0A5C 00002025 */  move  $a0, $zero
/* 105590 7F0D0A60 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 105594 7F0D0A64 00002825 */   move  $a1, $zero
/* 105598 7F0D0A68 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10559C 7F0D0A6C 27BD0018 */  addiu $sp, $sp, 0x18
/* 1055A0 7F0D0A70 24020001 */  li    $v0, 1
/* 1055A4 7F0D0A74 03E00008 */  jr    $ra
/* 1055A8 7F0D0A78 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0A7C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0A7C
/* 1055AC 7F0D0A7C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1055B0 7F0D0A80 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1055B4 7F0D0A84 AFA40018 */  sw    $a0, 0x18($sp)
/* 1055B8 7F0D0A88 24040114 */  li    $a0, 276
/* 1055BC 7F0D0A8C 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 1055C0 7F0D0A90 24050114 */   li    $a1, 276
/* 1055C4 7F0D0A94 24040014 */  li    $a0, 20
/* 1055C8 7F0D0A98 24050014 */  li    $a1, 20
/* 1055CC 7F0D0A9C 0FC34118 */  jal   sub_GAME_7F0D0460
/* 1055D0 7F0D0AA0 8FA60018 */   lw    $a2, 0x18($sp)
/* 1055D4 7F0D0AA4 00002025 */  move  $a0, $zero
/* 1055D8 7F0D0AA8 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 1055DC 7F0D0AAC 00002825 */   move  $a1, $zero
/* 1055E0 7F0D0AB0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1055E4 7F0D0AB4 27BD0018 */  addiu $sp, $sp, 0x18
/* 1055E8 7F0D0AB8 24020001 */  li    $v0, 1
/* 1055EC 7F0D0ABC 03E00008 */  jr    $ra
/* 1055F0 7F0D0AC0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0AC4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0AC4
/* 1055F4 7F0D0AC4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1055F8 7F0D0AC8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1055FC 7F0D0ACC AFA40018 */  sw    $a0, 0x18($sp)
/* 105600 7F0D0AD0 24040018 */  li    $a0, 24
/* 105604 7F0D0AD4 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105608 7F0D0AD8 24050018 */   li    $a1, 24
/* 10560C 7F0D0ADC 24040014 */  li    $a0, 20
/* 105610 7F0D0AE0 24050014 */  li    $a1, 20
/* 105614 7F0D0AE4 0FC34131 */  jal   sub_GAME_7F0D04C4
/* 105618 7F0D0AE8 8FA60018 */   lw    $a2, 0x18($sp)
/* 10561C 7F0D0AEC 00002025 */  move  $a0, $zero
/* 105620 7F0D0AF0 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 105624 7F0D0AF4 00002825 */   move  $a1, $zero
/* 105628 7F0D0AF8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10562C 7F0D0AFC 27BD0018 */  addiu $sp, $sp, 0x18
/* 105630 7F0D0B00 24020001 */  li    $v0, 1
/* 105634 7F0D0B04 03E00008 */  jr    $ra
/* 105638 7F0D0B08 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0B0C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0B0C
/* 10563C 7F0D0B0C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105640 7F0D0B10 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105644 7F0D0B14 AFA40018 */  sw    $a0, 0x18($sp)
/* 105648 7F0D0B18 24040114 */  li    $a0, 276
/* 10564C 7F0D0B1C 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105650 7F0D0B20 24050114 */   li    $a1, 276
/* 105654 7F0D0B24 24040014 */  li    $a0, 20
/* 105658 7F0D0B28 24050014 */  li    $a1, 20
/* 10565C 7F0D0B2C 0FC34145 */  jal   sub_GAME_7F0D0514
/* 105660 7F0D0B30 8FA60018 */   lw    $a2, 0x18($sp)
/* 105664 7F0D0B34 00002025 */  move  $a0, $zero
/* 105668 7F0D0B38 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 10566C 7F0D0B3C 00002825 */   move  $a1, $zero
/* 105670 7F0D0B40 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105674 7F0D0B44 27BD0018 */  addiu $sp, $sp, 0x18
/* 105678 7F0D0B48 24020001 */  li    $v0, 1
/* 10567C 7F0D0B4C 03E00008 */  jr    $ra
/* 105680 7F0D0B50 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0B54(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0B54
/* 105684 7F0D0B54 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105688 7F0D0B58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10568C 7F0D0B5C AFA40018 */  sw    $a0, 0x18($sp)
/* 105690 7F0D0B60 AFA5001C */  sw    $a1, 0x1c($sp)
/* 105694 7F0D0B64 2405001C */  li    $a1, 28
/* 105698 7F0D0B68 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 10569C 7F0D0B6C 2404001C */   li    $a0, 28
/* 1056A0 7F0D0B70 24040014 */  li    $a0, 20
/* 1056A4 7F0D0B74 24050014 */  li    $a1, 20
/* 1056A8 7F0D0B78 8FA60018 */  lw    $a2, 0x18($sp)
/* 1056AC 7F0D0B7C 0FC3415E */  jal   sub_GAME_7F0D0578
/* 1056B0 7F0D0B80 8FA7001C */   lw    $a3, 0x1c($sp)
/* 1056B4 7F0D0B84 00002025 */  move  $a0, $zero
/* 1056B8 7F0D0B88 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 1056BC 7F0D0B8C 00002825 */   move  $a1, $zero
/* 1056C0 7F0D0B90 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1056C4 7F0D0B94 27BD0018 */  addiu $sp, $sp, 0x18
/* 1056C8 7F0D0B98 24020001 */  li    $v0, 1
/* 1056CC 7F0D0B9C 03E00008 */  jr    $ra
/* 1056D0 7F0D0BA0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0BA4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0BA4
/* 1056D4 7F0D0BA4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1056D8 7F0D0BA8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1056DC 7F0D0BAC AFA40018 */  sw    $a0, 0x18($sp)
/* 1056E0 7F0D0BB0 AFA5001C */  sw    $a1, 0x1c($sp)
/* 1056E4 7F0D0BB4 24050118 */  li    $a1, 280
/* 1056E8 7F0D0BB8 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 1056EC 7F0D0BBC 24040118 */   li    $a0, 280
/* 1056F0 7F0D0BC0 24040014 */  li    $a0, 20
/* 1056F4 7F0D0BC4 24050014 */  li    $a1, 20
/* 1056F8 7F0D0BC8 8FA60018 */  lw    $a2, 0x18($sp)
/* 1056FC 7F0D0BCC 0FC34174 */  jal   sub_GAME_7F0D05D0
/* 105700 7F0D0BD0 8FA7001C */   lw    $a3, 0x1c($sp)
/* 105704 7F0D0BD4 00002025 */  move  $a0, $zero
/* 105708 7F0D0BD8 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 10570C 7F0D0BDC 00002825 */   move  $a1, $zero
/* 105710 7F0D0BE0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105714 7F0D0BE4 27BD0018 */  addiu $sp, $sp, 0x18
/* 105718 7F0D0BE8 24020001 */  li    $v0, 1
/* 10571C 7F0D0BEC 03E00008 */  jr    $ra
/* 105720 7F0D0BF0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0BF4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0BF4
/* 105724 7F0D0BF4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 105728 7F0D0BF8 AFA40020 */  sw    $a0, 0x20($sp)
/* 10572C 7F0D0BFC 24C40003 */  addiu $a0, $a2, 3
/* 105730 7F0D0C00 2401FFFC */  li    $at, -4
/* 105734 7F0D0C04 AFBF001C */  sw    $ra, 0x1c($sp)
/* 105738 7F0D0C08 AFA50024 */  sw    $a1, 0x24($sp)
/* 10573C 7F0D0C0C 00817024 */  and   $t6, $a0, $at
/* 105740 7F0D0C10 AFA60028 */  sw    $a2, 0x28($sp)
/* 105744 7F0D0C14 AFA7002C */  sw    $a3, 0x2c($sp)
/* 105748 7F0D0C18 25C40020 */  addiu $a0, $t6, 0x20
/* 10574C 7F0D0C1C 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105750 7F0D0C20 24050020 */   li    $a1, 32
/* 105754 7F0D0C24 8FAF0028 */  lw    $t7, 0x28($sp)
/* 105758 7F0D0C28 8FB8002C */  lw    $t8, 0x2c($sp)
/* 10575C 7F0D0C2C 24040014 */  li    $a0, 20
/* 105760 7F0D0C30 24050014 */  li    $a1, 20
/* 105764 7F0D0C34 8FA60020 */  lw    $a2, 0x20($sp)
/* 105768 7F0D0C38 8FA70024 */  lw    $a3, 0x24($sp)
/* 10576C 7F0D0C3C AFAF0010 */  sw    $t7, 0x10($sp)
/* 105770 7F0D0C40 0FC34191 */  jal   sub_GAME_7F0D0644
/* 105774 7F0D0C44 AFB80014 */   sw    $t8, 0x14($sp)
/* 105778 7F0D0C48 00002025 */  move  $a0, $zero
/* 10577C 7F0D0C4C 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 105780 7F0D0C50 00002825 */   move  $a1, $zero
/* 105784 7F0D0C54 8FBF001C */  lw    $ra, 0x1c($sp)
/* 105788 7F0D0C58 27BD0020 */  addiu $sp, $sp, 0x20
/* 10578C 7F0D0C5C 24020001 */  li    $v0, 1
/* 105790 7F0D0C60 03E00008 */  jr    $ra
/* 105794 7F0D0C64 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indy__res_cmd_send_capture_data(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indy__res_cmd_send_capture_data
/* 105798 7F0D0C68 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 10579C 7F0D0C6C AFA40020 */  sw    $a0, 0x20($sp)
/* 1057A0 7F0D0C70 24A40003 */  addiu $a0, $a1, 3
/* 1057A4 7F0D0C74 2401FFFC */  li    $at, -4
/* 1057A8 7F0D0C78 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1057AC 7F0D0C7C AFA50024 */  sw    $a1, 0x24($sp)
/* 1057B0 7F0D0C80 00817024 */  and   $t6, $a0, $at
/* 1057B4 7F0D0C84 AFA60028 */  sw    $a2, 0x28($sp)
/* 1057B8 7F0D0C88 25C40114 */  addiu $a0, $t6, 0x114
/* 1057BC 7F0D0C8C 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 1057C0 7F0D0C90 24050114 */   li    $a1, 276
/* 1057C4 7F0D0C94 8FAF0028 */  lw    $t7, 0x28($sp)
/* 1057C8 7F0D0C98 24040014 */  li    $a0, 20
/* 1057CC 7F0D0C9C 24050014 */  li    $a1, 20
/* 1057D0 7F0D0CA0 8FA60020 */  lw    $a2, 0x20($sp)
/* 1057D4 7F0D0CA4 8FA70024 */  lw    $a3, 0x24($sp)
/* 1057D8 7F0D0CA8 0FC341B0 */  jal   sub_GAME_7F0D06C0
/* 1057DC 7F0D0CAC AFAF0010 */   sw    $t7, 0x10($sp)
/* 1057E0 7F0D0CB0 00002025 */  move  $a0, $zero
/* 1057E4 7F0D0CB4 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 1057E8 7F0D0CB8 00002825 */   move  $a1, $zero
/* 1057EC 7F0D0CBC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1057F0 7F0D0CC0 27BD0020 */  addiu $sp, $sp, 0x20
/* 1057F4 7F0D0CC4 24020001 */  li    $v0, 1
/* 1057F8 7F0D0CC8 03E00008 */  jr    $ra
/* 1057FC 7F0D0CCC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0CD0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0CD0
/* 105800 7F0D0CD0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105804 7F0D0CD4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105808 7F0D0CD8 AFA40018 */  sw    $a0, 0x18($sp)
/* 10580C 7F0D0CDC 24040018 */  li    $a0, 24
/* 105810 7F0D0CE0 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105814 7F0D0CE4 24050018 */   li    $a1, 24
/* 105818 7F0D0CE8 24040014 */  li    $a0, 20
/* 10581C 7F0D0CEC 24050014 */  li    $a1, 20
/* 105820 7F0D0CF0 0FC341D0 */  jal   sub_GAME_7F0D0740
/* 105824 7F0D0CF4 8FA60018 */   lw    $a2, 0x18($sp)
/* 105828 7F0D0CF8 00002025 */  move  $a0, $zero
/* 10582C 7F0D0CFC 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 105830 7F0D0D00 00002825 */   move  $a1, $zero
/* 105834 7F0D0D04 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105838 7F0D0D08 27BD0018 */  addiu $sp, $sp, 0x18
/* 10583C 7F0D0D0C 24020001 */  li    $v0, 1
/* 105840 7F0D0D10 03E00008 */  jr    $ra
/* 105844 7F0D0D14 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void post_indy__res_cmd_request_ramrom_file(void) {

}
#else
GLOBAL_ASM(
.text
glabel post_indy__res_cmd_request_ramrom_file
/* 105848 7F0D0D18 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 10584C 7F0D0D1C AFBF001C */  sw    $ra, 0x1c($sp)
/* 105850 7F0D0D20 AFA40020 */  sw    $a0, 0x20($sp)
/* 105854 7F0D0D24 AFA50024 */  sw    $a1, 0x24($sp)
/* 105858 7F0D0D28 AFA60028 */  sw    $a2, 0x28($sp)
/* 10585C 7F0D0D2C 2405011C */  li    $a1, 284
/* 105860 7F0D0D30 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105864 7F0D0D34 2404011C */   li    $a0, 284
/* 105868 7F0D0D38 8FAE0024 */  lw    $t6, 0x24($sp)
/* 10586C 7F0D0D3C 24040014 */  li    $a0, 20
/* 105870 7F0D0D40 24050014 */  li    $a1, 20
/* 105874 7F0D0D44 8FA60020 */  lw    $a2, 0x20($sp)
/* 105878 7F0D0D48 8FA70028 */  lw    $a3, 0x28($sp)
/* 10587C 7F0D0D4C 0FC341E4 */  jal   sub_GAME_7F0D0790
/* 105880 7F0D0D50 AFAE0010 */   sw    $t6, 0x10($sp)
/* 105884 7F0D0D54 00002025 */  move  $a0, $zero
/* 105888 7F0D0D58 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 10588C 7F0D0D5C 00002825 */   move  $a1, $zero
/* 105890 7F0D0D60 8FBF001C */  lw    $ra, 0x1c($sp)
/* 105894 7F0D0D64 27BD0020 */  addiu $sp, $sp, 0x20
/* 105898 7F0D0D68 24020001 */  li    $v0, 1
/* 10589C 7F0D0D6C 03E00008 */  jr    $ra
/* 1058A0 7F0D0D70 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0D74(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0D74
/* 1058A4 7F0D0D74 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1058A8 7F0D0D78 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1058AC 7F0D0D7C AFA40020 */  sw    $a0, 0x20($sp)
/* 1058B0 7F0D0D80 AFA50024 */  sw    $a1, 0x24($sp)
/* 1058B4 7F0D0D84 AFA60028 */  sw    $a2, 0x28($sp)
/* 1058B8 7F0D0D88 24050020 */  li    $a1, 32
/* 1058BC 7F0D0D8C 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 1058C0 7F0D0D90 24040020 */   li    $a0, 32
/* 1058C4 7F0D0D94 8FAE0028 */  lw    $t6, 0x28($sp)
/* 1058C8 7F0D0D98 24040014 */  li    $a0, 20
/* 1058CC 7F0D0D9C 24050014 */  li    $a1, 20
/* 1058D0 7F0D0DA0 8FA60020 */  lw    $a2, 0x20($sp)
/* 1058D4 7F0D0DA4 8FA70024 */  lw    $a3, 0x24($sp)
/* 1058D8 7F0D0DA8 0FC34203 */  jal   sub_GAME_7F0D080C
/* 1058DC 7F0D0DAC AFAE0010 */   sw    $t6, 0x10($sp)
/* 1058E0 7F0D0DB0 00002025 */  move  $a0, $zero
/* 1058E4 7F0D0DB4 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 1058E8 7F0D0DB8 00002825 */   move  $a1, $zero
/* 1058EC 7F0D0DBC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1058F0 7F0D0DC0 27BD0020 */  addiu $sp, $sp, 0x20
/* 1058F4 7F0D0DC4 24020001 */  li    $v0, 1
/* 1058F8 7F0D0DC8 03E00008 */  jr    $ra
/* 1058FC 7F0D0DCC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0DD0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0DD0
/* 105900 7F0D0DD0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 105904 7F0D0DD4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 105908 7F0D0DD8 AFA40020 */  sw    $a0, 0x20($sp)
/* 10590C 7F0D0DDC AFA50024 */  sw    $a1, 0x24($sp)
/* 105910 7F0D0DE0 AFA60028 */  sw    $a2, 0x28($sp)
/* 105914 7F0D0DE4 2405011C */  li    $a1, 284
/* 105918 7F0D0DE8 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 10591C 7F0D0DEC 2404011C */   li    $a0, 284
/* 105920 7F0D0DF0 8FAE0024 */  lw    $t6, 0x24($sp)
/* 105924 7F0D0DF4 24040014 */  li    $a0, 20
/* 105928 7F0D0DF8 24050014 */  li    $a1, 20
/* 10592C 7F0D0DFC 8FA60020 */  lw    $a2, 0x20($sp)
/* 105930 7F0D0E00 8FA70028 */  lw    $a3, 0x28($sp)
/* 105934 7F0D0E04 0FC3421B */  jal   sub_GAME_7F0D086C
/* 105938 7F0D0E08 AFAE0010 */   sw    $t6, 0x10($sp)
/* 10593C 7F0D0E0C 00002025 */  move  $a0, $zero
/* 105940 7F0D0E10 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 105944 7F0D0E14 00002825 */   move  $a1, $zero
/* 105948 7F0D0E18 8FBF001C */  lw    $ra, 0x1c($sp)
/* 10594C 7F0D0E1C 27BD0020 */  addiu $sp, $sp, 0x20
/* 105950 7F0D0E20 24020001 */  li    $v0, 1
/* 105954 7F0D0E24 03E00008 */  jr    $ra
/* 105958 7F0D0E28 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0E2C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0E2C
/* 10595C 7F0D0E2C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105960 7F0D0E30 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105964 7F0D0E34 AFA40018 */  sw    $a0, 0x18($sp)
/* 105968 7F0D0E38 24040018 */  li    $a0, 24
/* 10596C 7F0D0E3C 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105970 7F0D0E40 24050018 */   li    $a1, 24
/* 105974 7F0D0E44 24040014 */  li    $a0, 20
/* 105978 7F0D0E48 24050014 */  li    $a1, 20
/* 10597C 7F0D0E4C 0FC3423A */  jal   sub_GAME_7F0D08E8
/* 105980 7F0D0E50 8FA60018 */   lw    $a2, 0x18($sp)
/* 105984 7F0D0E54 00002025 */  move  $a0, $zero
/* 105988 7F0D0E58 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 10598C 7F0D0E5C 00002825 */   move  $a1, $zero
/* 105990 7F0D0E60 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105994 7F0D0E64 27BD0018 */  addiu $sp, $sp, 0x18
/* 105998 7F0D0E68 24020001 */  li    $v0, 1
/* 10599C 7F0D0E6C 03E00008 */  jr    $ra
/* 1059A0 7F0D0E70 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0E74(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0E74
/* 1059A4 7F0D0E74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1059A8 7F0D0E78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1059AC 7F0D0E7C AFA40018 */  sw    $a0, 0x18($sp)
/* 1059B0 7F0D0E80 24040414 */  li    $a0, 1044
/* 1059B4 7F0D0E84 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 1059B8 7F0D0E88 24050414 */   li    $a1, 1044
/* 1059BC 7F0D0E8C 24040014 */  li    $a0, 20
/* 1059C0 7F0D0E90 24050014 */  li    $a1, 20
/* 1059C4 7F0D0E94 0FC3424E */  jal   sub_GAME_7F0D0938
/* 1059C8 7F0D0E98 8FA60018 */   lw    $a2, 0x18($sp)
/* 1059CC 7F0D0E9C 00002025 */  move  $a0, $zero
/* 1059D0 7F0D0EA0 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 1059D4 7F0D0EA4 00002825 */   move  $a1, $zero
/* 1059D8 7F0D0EA8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1059DC 7F0D0EAC 27BD0018 */  addiu $sp, $sp, 0x18
/* 1059E0 7F0D0EB0 24020001 */  li    $v0, 1
/* 1059E4 7F0D0EB4 03E00008 */  jr    $ra
/* 1059E8 7F0D0EB8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0EBC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0EBC
/* 1059EC 7F0D0EBC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1059F0 7F0D0EC0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1059F4 7F0D0EC4 AFA40018 */  sw    $a0, 0x18($sp)
/* 1059F8 7F0D0EC8 24040018 */  li    $a0, 24
/* 1059FC 7F0D0ECC 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105A00 7F0D0ED0 24050018 */   li    $a1, 24
/* 105A04 7F0D0ED4 24040014 */  li    $a0, 20
/* 105A08 7F0D0ED8 24050014 */  li    $a1, 20
/* 105A0C 7F0D0EDC 0FC34267 */  jal   sub_GAME_7F0D099C
/* 105A10 7F0D0EE0 8FA60018 */   lw    $a2, 0x18($sp)
/* 105A14 7F0D0EE4 00002025 */  move  $a0, $zero
/* 105A18 7F0D0EE8 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 105A1C 7F0D0EEC 00002825 */   move  $a1, $zero
/* 105A20 7F0D0EF0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105A24 7F0D0EF4 27BD0018 */  addiu $sp, $sp, 0x18
/* 105A28 7F0D0EF8 24020001 */  li    $v0, 1
/* 105A2C 7F0D0EFC 03E00008 */  jr    $ra
/* 105A30 7F0D0F00 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0F04(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0F04
/* 105A34 7F0D0F04 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105A38 7F0D0F08 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105A3C 7F0D0F0C AFA40018 */  sw    $a0, 0x18($sp)
/* 105A40 7F0D0F10 24040018 */  li    $a0, 24
/* 105A44 7F0D0F14 0FC340E3 */  jal   sub_GAME_7F0D038C
/* 105A48 7F0D0F18 24050018 */   li    $a1, 24
/* 105A4C 7F0D0F1C 24040014 */  li    $a0, 20
/* 105A50 7F0D0F20 24050014 */  li    $a1, 20
/* 105A54 7F0D0F24 0FC3427B */  jal   sub_GAME_7F0D09EC
/* 105A58 7F0D0F28 8FA60018 */   lw    $a2, 0x18($sp)
/* 105A5C 7F0D0F2C 00002025 */  move  $a0, $zero
/* 105A60 7F0D0F30 0FC340F5 */  jal   sub_GAME_7F0D03D4
/* 105A64 7F0D0F34 00002825 */   move  $a1, $zero
/* 105A68 7F0D0F38 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105A6C 7F0D0F3C 27BD0018 */  addiu $sp, $sp, 0x18
/* 105A70 7F0D0F40 24020001 */  li    $v0, 1
/* 105A74 7F0D0F44 03E00008 */  jr    $ra
/* 105A78 7F0D0F48 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D0F4C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D0F4C
/* 105A7C 7F0D0F4C 27BDFBC0 */  addiu $sp, $sp, -0x440
/* 105A80 7F0D0F50 27A20040 */  addiu $v0, $sp, 0x40
/* 105A84 7F0D0F54 308F0007 */  andi  $t7, $a0, 7
/* 105A88 7F0D0F58 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105A8C 7F0D0F5C AFA40440 */  sw    $a0, 0x440($sp)
/* 105A90 7F0D0F60 00A03025 */  move  $a2, $a1
/* 105A94 7F0D0F64 00401825 */  move  $v1, $v0
/* 105A98 7F0D0F68 11E00031 */  beqz  $t7, .L7F0D1030
/* 105A9C 7F0D0F6C 00403825 */   move  $a3, $v0
/* 105AA0 7F0D0F70 2CA10401 */  sltiu $at, $a1, 0x401
/* 105AA4 7F0D0F74 14200003 */  bnez  $at, .L7F0D0F84
/* 105AA8 7F0D0F78 30580007 */   andi  $t8, $v0, 7
/* 105AAC 7F0D0F7C 10000046 */  b     .L7F0D1098
/* 105AB0 7F0D0F80 00001025 */   move  $v0, $zero
.L7F0D0F84:
/* 105AB4 7F0D0F84 13000003 */  beqz  $t8, .L7F0D0F94
/* 105AB8 7F0D0F88 24C50003 */   addiu $a1, $a2, 3
/* 105ABC 7F0D0F8C 27A30044 */  addiu $v1, $sp, 0x44
/* 105AC0 7F0D0F90 00603825 */  move  $a3, $v1
.L7F0D0F94:
/* 105AC4 7F0D0F94 2401FFFC */  li    $at, -4
/* 105AC8 7F0D0F98 00A1C824 */  and   $t9, $a1, $at
/* 105ACC 7F0D0F9C 03202825 */  move  $a1, $t9
/* 105AD0 7F0D0FA0 00E02025 */  move  $a0, $a3
/* 105AD4 7F0D0FA4 AFA3003C */  sw    $v1, 0x3c($sp)
/* 105AD8 7F0D0FA8 0FC34060 */  jal   sub_GAME_7F0D0180
/* 105ADC 7F0D0FAC AFA60444 */   sw    $a2, 0x444($sp)
/* 105AE0 7F0D0FB0 8FA3003C */  lw    $v1, 0x3c($sp)
/* 105AE4 7F0D0FB4 8FA60444 */  lw    $a2, 0x444($sp)
/* 105AE8 7F0D0FB8 8FA20440 */  lw    $v0, 0x440($sp)
/* 105AEC 7F0D0FBC 3C098005 */  lui   $t1, %hi(D_8004EAC4) # $t1, 0x8005
/* 105AF0 7F0D0FC0 00662021 */  addu  $a0, $v1, $a2
/* 105AF4 7F0D0FC4 0064082B */  sltu  $at, $v1, $a0
/* 105AF8 7F0D0FC8 10200007 */  beqz  $at, .L7F0D0FE8
/* 105AFC 7F0D0FCC 00000000 */   nop   
.L7F0D0FD0:
/* 105B00 7F0D0FD0 90680000 */  lbu   $t0, ($v1)
/* 105B04 7F0D0FD4 24630001 */  addiu $v1, $v1, 1
/* 105B08 7F0D0FD8 0064082B */  sltu  $at, $v1, $a0
/* 105B0C 7F0D0FDC 24420001 */  addiu $v0, $v0, 1
/* 105B10 7F0D0FE0 1420FFFB */  bnez  $at, .L7F0D0FD0
/* 105B14 7F0D0FE4 A048FFFF */   sb    $t0, -1($v0)
.L7F0D0FE8:
/* 105B18 7F0D0FE8 8D29EAC4 */  lw    $t1, %lo(D_8004EAC4)($t1)
/* 105B1C 7F0D0FEC 312A0010 */  andi  $t2, $t1, 0x10
/* 105B20 7F0D0FF0 1140000D */  beqz  $t2, .L7F0D1028
/* 105B24 7F0D0FF4 00000000 */   nop   
/* 105B28 7F0D0FF8 10C0000B */  beqz  $a2, .L7F0D1028
/* 105B2C 7F0D0FFC 00001025 */   move  $v0, $zero
/* 105B30 7F0D1000 30C40003 */  andi  $a0, $a2, 3
/* 105B34 7F0D1004 10800005 */  beqz  $a0, .L7F0D101C
/* 105B38 7F0D1008 00801825 */   move  $v1, $a0
/* 105B3C 7F0D100C 24420001 */  addiu $v0, $v0, 1
.L7F0D1010:
/* 105B40 7F0D1010 5462FFFF */  bnel  $v1, $v0, .L7F0D1010
/* 105B44 7F0D1014 24420001 */   addiu $v0, $v0, 1
/* 105B48 7F0D1018 10460003 */  beq   $v0, $a2, .L7F0D1028
.L7F0D101C:
/* 105B4C 7F0D101C 24420004 */   addiu $v0, $v0, 4
.L7F0D1020:
/* 105B50 7F0D1020 5446FFFF */  bnel  $v0, $a2, .L7F0D1020
/* 105B54 7F0D1024 24420004 */   addiu $v0, $v0, 4
.L7F0D1028:
/* 105B58 7F0D1028 1000001B */  b     .L7F0D1098
/* 105B5C 7F0D102C 24020001 */   li    $v0, 1
.L7F0D1030:
/* 105B60 7F0D1030 24C50003 */  addiu $a1, $a2, 3
/* 105B64 7F0D1034 2401FFFC */  li    $at, -4
/* 105B68 7F0D1038 00A15824 */  and   $t3, $a1, $at
/* 105B6C 7F0D103C 01602825 */  move  $a1, $t3
/* 105B70 7F0D1040 8FA40440 */  lw    $a0, 0x440($sp)
/* 105B74 7F0D1044 0FC34060 */  jal   sub_GAME_7F0D0180
/* 105B78 7F0D1048 AFA60444 */   sw    $a2, 0x444($sp)
/* 105B7C 7F0D104C 3C0C8005 */  lui   $t4, %hi(D_8004EAC4) # $t4, 0x8005
/* 105B80 7F0D1050 8D8CEAC4 */  lw    $t4, %lo(D_8004EAC4)($t4)
/* 105B84 7F0D1054 8FA60444 */  lw    $a2, 0x444($sp)
/* 105B88 7F0D1058 318D0010 */  andi  $t5, $t4, 0x10
/* 105B8C 7F0D105C 51A0000E */  beql  $t5, $zero, .L7F0D1098
/* 105B90 7F0D1060 24020001 */   li    $v0, 1
/* 105B94 7F0D1064 10C0000B */  beqz  $a2, .L7F0D1094
/* 105B98 7F0D1068 00001025 */   move  $v0, $zero
/* 105B9C 7F0D106C 30C40003 */  andi  $a0, $a2, 3
/* 105BA0 7F0D1070 10800005 */  beqz  $a0, .L7F0D1088
/* 105BA4 7F0D1074 00801825 */   move  $v1, $a0
/* 105BA8 7F0D1078 24420001 */  addiu $v0, $v0, 1
.L7F0D107C:
/* 105BAC 7F0D107C 5462FFFF */  bnel  $v1, $v0, .L7F0D107C
/* 105BB0 7F0D1080 24420001 */   addiu $v0, $v0, 1
/* 105BB4 7F0D1084 10460003 */  beq   $v0, $a2, .L7F0D1094
.L7F0D1088:
/* 105BB8 7F0D1088 24420004 */   addiu $v0, $v0, 4
.L7F0D108C:
/* 105BBC 7F0D108C 5446FFFF */  bnel  $v0, $a2, .L7F0D108C
/* 105BC0 7F0D1090 24420004 */   addiu $v0, $v0, 4
.L7F0D1094:
/* 105BC4 7F0D1094 24020001 */  li    $v0, 1
.L7F0D1098:
/* 105BC8 7F0D1098 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105BCC 7F0D109C 27BD0440 */  addiu $sp, $sp, 0x440
/* 105BD0 7F0D10A0 03E00008 */  jr    $ra
/* 105BD4 7F0D10A4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D10A8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D10A8
/* 105BD8 7F0D10A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105BDC 7F0D10AC AFA5001C */  sw    $a1, 0x1c($sp)
/* 105BE0 7F0D10B0 24A50003 */  addiu $a1, $a1, 3
/* 105BE4 7F0D10B4 2401FFFC */  li    $at, -4
/* 105BE8 7F0D10B8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105BEC 7F0D10BC 00A17024 */  and   $t6, $a1, $at
/* 105BF0 7F0D10C0 AFA60020 */  sw    $a2, 0x20($sp)
/* 105BF4 7F0D10C4 AFA70024 */  sw    $a3, 0x24($sp)
/* 105BF8 7F0D10C8 0FC34060 */  jal   sub_GAME_7F0D0180
/* 105BFC 7F0D10CC 01C02825 */   move  $a1, $t6
/* 105C00 7F0D10D0 8FA50024 */  lw    $a1, 0x24($sp)
/* 105C04 7F0D10D4 2401FFFC */  li    $at, -4
/* 105C08 7F0D10D8 8FA40020 */  lw    $a0, 0x20($sp)
/* 105C0C 7F0D10DC 24A50003 */  addiu $a1, $a1, 3
/* 105C10 7F0D10E0 00A17824 */  and   $t7, $a1, $at
/* 105C14 7F0D10E4 0FC34060 */  jal   sub_GAME_7F0D0180
/* 105C18 7F0D10E8 01E02825 */   move  $a1, $t7
/* 105C1C 7F0D10EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105C20 7F0D10F0 27BD0018 */  addiu $sp, $sp, 0x18
/* 105C24 7F0D10F4 24020001 */  li    $v0, 1
/* 105C28 7F0D10F8 03E00008 */  jr    $ra
/* 105C2C 7F0D10FC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1100(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1100
/* 105C30 7F0D1100 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105C34 7F0D1104 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105C38 7F0D1108 AFA40030 */  sw    $a0, 0x30($sp)
/* 105C3C 7F0D110C AFA50034 */  sw    $a1, 0x34($sp)
/* 105C40 7F0D1110 24050014 */  li    $a1, 20
/* 105C44 7F0D1114 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 105C48 7F0D1118 27A4001C */   addiu $a0, $sp, 0x1c
/* 105C4C 7F0D111C 8FAE001C */  lw    $t6, 0x1c($sp)
/* 105C50 7F0D1120 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105C54 7F0D1124 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105C58 7F0D1128 11C10003 */  beq   $t6, $at, .L7F0D1138
/* 105C5C 7F0D112C 8FA20030 */   lw    $v0, 0x30($sp)
/* 105C60 7F0D1130 1000001A */  b     .L7F0D119C
/* 105C64 7F0D1134 00001025 */   move  $v0, $zero
.L7F0D1138:
/* 105C68 7F0D1138 8FAF0020 */  lw    $t7, 0x20($sp)
/* 105C6C 7F0D113C 24010001 */  li    $at, 1
/* 105C70 7F0D1140 8FB80024 */  lw    $t8, 0x24($sp)
/* 105C74 7F0D1144 51E10004 */  beql  $t7, $at, .L7F0D1158
/* 105C78 7F0D1148 24010014 */   li    $at, 20
/* 105C7C 7F0D114C 10000013 */  b     .L7F0D119C
/* 105C80 7F0D1150 00001025 */   move  $v0, $zero
/* 105C84 7F0D1154 24010014 */  li    $at, 20
.L7F0D1158:
/* 105C88 7F0D1158 13010003 */  beq   $t8, $at, .L7F0D1168
/* 105C8C 7F0D115C 00000000 */   nop   
/* 105C90 7F0D1160 1000000E */  b     .L7F0D119C
/* 105C94 7F0D1164 00001025 */   move  $v0, $zero
.L7F0D1168:
/* 105C98 7F0D1168 10400005 */  beqz  $v0, .L7F0D1180
/* 105C9C 7F0D116C 8FB90028 */   lw    $t9, 0x28($sp)
/* 105CA0 7F0D1170 53220004 */  beql  $t9, $v0, .L7F0D1184
/* 105CA4 7F0D1174 8FA8002C */   lw    $t0, 0x2c($sp)
/* 105CA8 7F0D1178 10000008 */  b     .L7F0D119C
/* 105CAC 7F0D117C 00001025 */   move  $v0, $zero
.L7F0D1180:
/* 105CB0 7F0D1180 8FA8002C */  lw    $t0, 0x2c($sp)
.L7F0D1184:
/* 105CB4 7F0D1184 8FA90034 */  lw    $t1, 0x34($sp)
/* 105CB8 7F0D1188 24020001 */  li    $v0, 1
/* 105CBC 7F0D118C 11090003 */  beq   $t0, $t1, .L7F0D119C
/* 105CC0 7F0D1190 00000000 */   nop   
/* 105CC4 7F0D1194 10000001 */  b     .L7F0D119C
/* 105CC8 7F0D1198 00001025 */   move  $v0, $zero
.L7F0D119C:
/* 105CCC 7F0D119C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105CD0 7F0D11A0 27BD0030 */  addiu $sp, $sp, 0x30
/* 105CD4 7F0D11A4 03E00008 */  jr    $ra
/* 105CD8 7F0D11A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D11AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D11AC
/* 105CDC 7F0D11AC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105CE0 7F0D11B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105CE4 7F0D11B4 AFA40030 */  sw    $a0, 0x30($sp)
/* 105CE8 7F0D11B8 AFA50034 */  sw    $a1, 0x34($sp)
/* 105CEC 7F0D11BC 24050014 */  li    $a1, 20
/* 105CF0 7F0D11C0 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 105CF4 7F0D11C4 27A4001C */   addiu $a0, $sp, 0x1c
/* 105CF8 7F0D11C8 8FAE001C */  lw    $t6, 0x1c($sp)
/* 105CFC 7F0D11CC 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105D00 7F0D11D0 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105D04 7F0D11D4 11C10003 */  beq   $t6, $at, .L7F0D11E4
/* 105D08 7F0D11D8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 105D0C 7F0D11DC 10000018 */  b     .L7F0D1240
/* 105D10 7F0D11E0 00001025 */   move  $v0, $zero
.L7F0D11E4:
/* 105D14 7F0D11E4 8FAF0020 */  lw    $t7, 0x20($sp)
/* 105D18 7F0D11E8 24010002 */  li    $at, 2
/* 105D1C 7F0D11EC 8FB80024 */  lw    $t8, 0x24($sp)
/* 105D20 7F0D11F0 51E10004 */  beql  $t7, $at, .L7F0D1204
/* 105D24 7F0D11F4 24010014 */   li    $at, 20
/* 105D28 7F0D11F8 10000011 */  b     .L7F0D1240
/* 105D2C 7F0D11FC 00001025 */   move  $v0, $zero
/* 105D30 7F0D1200 24010014 */  li    $at, 20
.L7F0D1204:
/* 105D34 7F0D1204 13010003 */  beq   $t8, $at, .L7F0D1214
/* 105D38 7F0D1208 8FB90028 */   lw    $t9, 0x28($sp)
/* 105D3C 7F0D120C 1000000C */  b     .L7F0D1240
/* 105D40 7F0D1210 00001025 */   move  $v0, $zero
.L7F0D1214:
/* 105D44 7F0D1214 8FA80030 */  lw    $t0, 0x30($sp)
/* 105D48 7F0D1218 8FA9002C */  lw    $t1, 0x2c($sp)
/* 105D4C 7F0D121C 8FAA0034 */  lw    $t2, 0x34($sp)
/* 105D50 7F0D1220 13280003 */  beq   $t9, $t0, .L7F0D1230
/* 105D54 7F0D1224 00000000 */   nop   
/* 105D58 7F0D1228 10000005 */  b     .L7F0D1240
/* 105D5C 7F0D122C 00001025 */   move  $v0, $zero
.L7F0D1230:
/* 105D60 7F0D1230 112A0003 */  beq   $t1, $t2, .L7F0D1240
/* 105D64 7F0D1234 24020001 */   li    $v0, 1
/* 105D68 7F0D1238 10000001 */  b     .L7F0D1240
/* 105D6C 7F0D123C 00001025 */   move  $v0, $zero
.L7F0D1240:
/* 105D70 7F0D1240 03E00008 */  jr    $ra
/* 105D74 7F0D1244 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1248(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1248
/* 105D78 7F0D1248 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105D7C 7F0D124C AFBF0014 */  sw    $ra, 0x14($sp)
/* 105D80 7F0D1250 AFA40030 */  sw    $a0, 0x30($sp)
/* 105D84 7F0D1254 AFA50034 */  sw    $a1, 0x34($sp)
/* 105D88 7F0D1258 AFA60038 */  sw    $a2, 0x38($sp)
/* 105D8C 7F0D125C 24050018 */  li    $a1, 24
/* 105D90 7F0D1260 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 105D94 7F0D1264 27A40018 */   addiu $a0, $sp, 0x18
/* 105D98 7F0D1268 8FAE0018 */  lw    $t6, 0x18($sp)
/* 105D9C 7F0D126C 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105DA0 7F0D1270 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105DA4 7F0D1274 11C10003 */  beq   $t6, $at, .L7F0D1284
/* 105DA8 7F0D1278 8FAF001C */   lw    $t7, 0x1c($sp)
/* 105DAC 7F0D127C 10000019 */  b     .L7F0D12E4
/* 105DB0 7F0D1280 00001025 */   move  $v0, $zero
.L7F0D1284:
/* 105DB4 7F0D1284 24010004 */  li    $at, 4
/* 105DB8 7F0D1288 11E10003 */  beq   $t7, $at, .L7F0D1298
/* 105DBC 7F0D128C 8FB80020 */   lw    $t8, 0x20($sp)
/* 105DC0 7F0D1290 10000014 */  b     .L7F0D12E4
/* 105DC4 7F0D1294 00001025 */   move  $v0, $zero
.L7F0D1298:
/* 105DC8 7F0D1298 24010018 */  li    $at, 24
/* 105DCC 7F0D129C 13010003 */  beq   $t8, $at, .L7F0D12AC
/* 105DD0 7F0D12A0 8FB90024 */   lw    $t9, 0x24($sp)
/* 105DD4 7F0D12A4 1000000F */  b     .L7F0D12E4
/* 105DD8 7F0D12A8 00001025 */   move  $v0, $zero
.L7F0D12AC:
/* 105DDC 7F0D12AC 8FA80030 */  lw    $t0, 0x30($sp)
/* 105DE0 7F0D12B0 8FA90028 */  lw    $t1, 0x28($sp)
/* 105DE4 7F0D12B4 8FAA0034 */  lw    $t2, 0x34($sp)
/* 105DE8 7F0D12B8 13280003 */  beq   $t9, $t0, .L7F0D12C8
/* 105DEC 7F0D12BC 00000000 */   nop   
/* 105DF0 7F0D12C0 10000008 */  b     .L7F0D12E4
/* 105DF4 7F0D12C4 00001025 */   move  $v0, $zero
.L7F0D12C8:
/* 105DF8 7F0D12C8 112A0003 */  beq   $t1, $t2, .L7F0D12D8
/* 105DFC 7F0D12CC 8FAB002C */   lw    $t3, 0x2c($sp)
/* 105E00 7F0D12D0 10000004 */  b     .L7F0D12E4
/* 105E04 7F0D12D4 00001025 */   move  $v0, $zero
.L7F0D12D8:
/* 105E08 7F0D12D8 8FAC0038 */  lw    $t4, 0x38($sp)
/* 105E0C 7F0D12DC 24020001 */  li    $v0, 1
/* 105E10 7F0D12E0 AD8B0000 */  sw    $t3, ($t4)
.L7F0D12E4:
/* 105E14 7F0D12E4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105E18 7F0D12E8 27BD0030 */  addiu $sp, $sp, 0x30
/* 105E1C 7F0D12EC 03E00008 */  jr    $ra
/* 105E20 7F0D12F0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D12F4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D12F4
/* 105E24 7F0D12F4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105E28 7F0D12F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105E2C 7F0D12FC AFA40038 */  sw    $a0, 0x38($sp)
/* 105E30 7F0D1300 AFA5003C */  sw    $a1, 0x3c($sp)
/* 105E34 7F0D1304 AFA60040 */  sw    $a2, 0x40($sp)
/* 105E38 7F0D1308 AFA70044 */  sw    $a3, 0x44($sp)
/* 105E3C 7F0D130C 2405001C */  li    $a1, 28
/* 105E40 7F0D1310 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 105E44 7F0D1314 27A4001C */   addiu $a0, $sp, 0x1c
/* 105E48 7F0D1318 8FAE001C */  lw    $t6, 0x1c($sp)
/* 105E4C 7F0D131C 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105E50 7F0D1320 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105E54 7F0D1324 11C10003 */  beq   $t6, $at, .L7F0D1334
/* 105E58 7F0D1328 8FAF0020 */   lw    $t7, 0x20($sp)
/* 105E5C 7F0D132C 1000001C */  b     .L7F0D13A0
/* 105E60 7F0D1330 00001025 */   move  $v0, $zero
.L7F0D1334:
/* 105E64 7F0D1334 24010006 */  li    $at, 6
/* 105E68 7F0D1338 11E10003 */  beq   $t7, $at, .L7F0D1348
/* 105E6C 7F0D133C 8FB80024 */   lw    $t8, 0x24($sp)
/* 105E70 7F0D1340 10000017 */  b     .L7F0D13A0
/* 105E74 7F0D1344 00001025 */   move  $v0, $zero
.L7F0D1348:
/* 105E78 7F0D1348 2401001C */  li    $at, 28
/* 105E7C 7F0D134C 13010003 */  beq   $t8, $at, .L7F0D135C
/* 105E80 7F0D1350 8FB90028 */   lw    $t9, 0x28($sp)
/* 105E84 7F0D1354 10000012 */  b     .L7F0D13A0
/* 105E88 7F0D1358 00001025 */   move  $v0, $zero
.L7F0D135C:
/* 105E8C 7F0D135C 8FA80038 */  lw    $t0, 0x38($sp)
/* 105E90 7F0D1360 8FA9002C */  lw    $t1, 0x2c($sp)
/* 105E94 7F0D1364 8FAA003C */  lw    $t2, 0x3c($sp)
/* 105E98 7F0D1368 13280003 */  beq   $t9, $t0, .L7F0D1378
/* 105E9C 7F0D136C 00000000 */   nop   
/* 105EA0 7F0D1370 1000000B */  b     .L7F0D13A0
/* 105EA4 7F0D1374 00001025 */   move  $v0, $zero
.L7F0D1378:
/* 105EA8 7F0D1378 112A0003 */  beq   $t1, $t2, .L7F0D1388
/* 105EAC 7F0D137C 8FAB0030 */   lw    $t3, 0x30($sp)
/* 105EB0 7F0D1380 10000007 */  b     .L7F0D13A0
/* 105EB4 7F0D1384 00001025 */   move  $v0, $zero
.L7F0D1388:
/* 105EB8 7F0D1388 8FAC0040 */  lw    $t4, 0x40($sp)
/* 105EBC 7F0D138C 24020001 */  li    $v0, 1
/* 105EC0 7F0D1390 AD8B0000 */  sw    $t3, ($t4)
/* 105EC4 7F0D1394 8FAE0044 */  lw    $t6, 0x44($sp)
/* 105EC8 7F0D1398 8FAD0034 */  lw    $t5, 0x34($sp)
/* 105ECC 7F0D139C ADCD0000 */  sw    $t5, ($t6)
.L7F0D13A0:
/* 105ED0 7F0D13A0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105ED4 7F0D13A4 27BD0038 */  addiu $sp, $sp, 0x38
/* 105ED8 7F0D13A8 03E00008 */  jr    $ra
/* 105EDC 7F0D13AC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D13B0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D13B0
/* 105EE0 7F0D13B0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 105EE4 7F0D13B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105EE8 7F0D13B8 AFA40038 */  sw    $a0, 0x38($sp)
/* 105EEC 7F0D13BC AFA5003C */  sw    $a1, 0x3c($sp)
/* 105EF0 7F0D13C0 AFA60040 */  sw    $a2, 0x40($sp)
/* 105EF4 7F0D13C4 AFA70044 */  sw    $a3, 0x44($sp)
/* 105EF8 7F0D13C8 24050020 */  li    $a1, 32
/* 105EFC 7F0D13CC 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 105F00 7F0D13D0 27A40018 */   addiu $a0, $sp, 0x18
/* 105F04 7F0D13D4 8FAE0018 */  lw    $t6, 0x18($sp)
/* 105F08 7F0D13D8 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105F0C 7F0D13DC 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105F10 7F0D13E0 11C10003 */  beq   $t6, $at, .L7F0D13F0
/* 105F14 7F0D13E4 8FAF001C */   lw    $t7, 0x1c($sp)
/* 105F18 7F0D13E8 10000027 */  b     .L7F0D1488
/* 105F1C 7F0D13EC 00001025 */   move  $v0, $zero
.L7F0D13F0:
/* 105F20 7F0D13F0 24010008 */  li    $at, 8
/* 105F24 7F0D13F4 11E10003 */  beq   $t7, $at, .L7F0D1404
/* 105F28 7F0D13F8 8FB90034 */   lw    $t9, 0x34($sp)
/* 105F2C 7F0D13FC 10000022 */  b     .L7F0D1488
/* 105F30 7F0D1400 00001025 */   move  $v0, $zero
.L7F0D1404:
/* 105F34 7F0D1404 8FB80020 */  lw    $t8, 0x20($sp)
/* 105F38 7F0D1408 2402FFFC */  li    $v0, -4
/* 105F3C 7F0D140C 27280003 */  addiu $t0, $t9, 3
/* 105F40 7F0D1410 01024824 */  and   $t1, $t0, $v0
/* 105F44 7F0D1414 252A0020 */  addiu $t2, $t1, 0x20
/* 105F48 7F0D1418 130A0003 */  beq   $t8, $t2, .L7F0D1428
/* 105F4C 7F0D141C 8FAB0024 */   lw    $t3, 0x24($sp)
/* 105F50 7F0D1420 10000019 */  b     .L7F0D1488
/* 105F54 7F0D1424 00001025 */   move  $v0, $zero
.L7F0D1428:
/* 105F58 7F0D1428 8FAC0038 */  lw    $t4, 0x38($sp)
/* 105F5C 7F0D142C 8FAD0028 */  lw    $t5, 0x28($sp)
/* 105F60 7F0D1430 8FAE003C */  lw    $t6, 0x3c($sp)
/* 105F64 7F0D1434 116C0003 */  beq   $t3, $t4, .L7F0D1444
/* 105F68 7F0D1438 00000000 */   nop   
/* 105F6C 7F0D143C 10000012 */  b     .L7F0D1488
/* 105F70 7F0D1440 00001025 */   move  $v0, $zero
.L7F0D1444:
/* 105F74 7F0D1444 11AE0003 */  beq   $t5, $t6, .L7F0D1454
/* 105F78 7F0D1448 8FAF002C */   lw    $t7, 0x2c($sp)
/* 105F7C 7F0D144C 1000000E */  b     .L7F0D1488
/* 105F80 7F0D1450 00001025 */   move  $v0, $zero
.L7F0D1454:
/* 105F84 7F0D1454 8FB90040 */  lw    $t9, 0x40($sp)
/* 105F88 7F0D1458 AF2F0000 */  sw    $t7, ($t9)
/* 105F8C 7F0D145C 8FA90044 */  lw    $t1, 0x44($sp)
/* 105F90 7F0D1460 8FA80030 */  lw    $t0, 0x30($sp)
/* 105F94 7F0D1464 AD280000 */  sw    $t0, ($t1)
/* 105F98 7F0D1468 8FB80034 */  lw    $t8, 0x34($sp)
/* 105F9C 7F0D146C 8FAA0048 */  lw    $t2, 0x48($sp)
/* 105FA0 7F0D1470 270B0003 */  addiu $t3, $t8, 3
/* 105FA4 7F0D1474 AD580000 */  sw    $t8, ($t2)
/* 105FA8 7F0D1478 8FA4004C */  lw    $a0, 0x4c($sp)
/* 105FAC 7F0D147C 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 105FB0 7F0D1480 01622824 */   and   $a1, $t3, $v0
/* 105FB4 7F0D1484 24020001 */  li    $v0, 1
.L7F0D1488:
/* 105FB8 7F0D1488 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105FBC 7F0D148C 27BD0038 */  addiu $sp, $sp, 0x38
/* 105FC0 7F0D1490 03E00008 */  jr    $ra
/* 105FC4 7F0D1494 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1498(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1498
/* 105FC8 7F0D1498 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 105FCC 7F0D149C AFBF0014 */  sw    $ra, 0x14($sp)
/* 105FD0 7F0D14A0 AFA40030 */  sw    $a0, 0x30($sp)
/* 105FD4 7F0D14A4 AFA50034 */  sw    $a1, 0x34($sp)
/* 105FD8 7F0D14A8 AFA60038 */  sw    $a2, 0x38($sp)
/* 105FDC 7F0D14AC 24050018 */  li    $a1, 24
/* 105FE0 7F0D14B0 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 105FE4 7F0D14B4 27A40018 */   addiu $a0, $sp, 0x18
/* 105FE8 7F0D14B8 8FAE0018 */  lw    $t6, 0x18($sp)
/* 105FEC 7F0D14BC 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 105FF0 7F0D14C0 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 105FF4 7F0D14C4 11C10003 */  beq   $t6, $at, .L7F0D14D4
/* 105FF8 7F0D14C8 8FAF001C */   lw    $t7, 0x1c($sp)
/* 105FFC 7F0D14CC 10000019 */  b     .L7F0D1534
/* 106000 7F0D14D0 00001025 */   move  $v0, $zero
.L7F0D14D4:
/* 106004 7F0D14D4 2401000A */  li    $at, 10
/* 106008 7F0D14D8 11E10003 */  beq   $t7, $at, .L7F0D14E8
/* 10600C 7F0D14DC 8FB80020 */   lw    $t8, 0x20($sp)
/* 106010 7F0D14E0 10000014 */  b     .L7F0D1534
/* 106014 7F0D14E4 00001025 */   move  $v0, $zero
.L7F0D14E8:
/* 106018 7F0D14E8 24010018 */  li    $at, 24
/* 10601C 7F0D14EC 13010003 */  beq   $t8, $at, .L7F0D14FC
/* 106020 7F0D14F0 8FB90024 */   lw    $t9, 0x24($sp)
/* 106024 7F0D14F4 1000000F */  b     .L7F0D1534
/* 106028 7F0D14F8 00001025 */   move  $v0, $zero
.L7F0D14FC:
/* 10602C 7F0D14FC 8FA80030 */  lw    $t0, 0x30($sp)
/* 106030 7F0D1500 8FA90028 */  lw    $t1, 0x28($sp)
/* 106034 7F0D1504 8FAA0034 */  lw    $t2, 0x34($sp)
/* 106038 7F0D1508 13280003 */  beq   $t9, $t0, .L7F0D1518
/* 10603C 7F0D150C 00000000 */   nop   
/* 106040 7F0D1510 10000008 */  b     .L7F0D1534
/* 106044 7F0D1514 00001025 */   move  $v0, $zero
.L7F0D1518:
/* 106048 7F0D1518 112A0003 */  beq   $t1, $t2, .L7F0D1528
/* 10604C 7F0D151C 8FAB002C */   lw    $t3, 0x2c($sp)
/* 106050 7F0D1520 10000004 */  b     .L7F0D1534
/* 106054 7F0D1524 00001025 */   move  $v0, $zero
.L7F0D1528:
/* 106058 7F0D1528 8FAC0038 */  lw    $t4, 0x38($sp)
/* 10605C 7F0D152C 24020001 */  li    $v0, 1
/* 106060 7F0D1530 AD8B0000 */  sw    $t3, ($t4)
.L7F0D1534:
/* 106064 7F0D1534 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106068 7F0D1538 27BD0030 */  addiu $sp, $sp, 0x30
/* 10606C 7F0D153C 03E00008 */  jr    $ra
/* 106070 7F0D1540 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1544(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1544
/* 106074 7F0D1544 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 106078 7F0D1548 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10607C 7F0D154C AFA40038 */  sw    $a0, 0x38($sp)
/* 106080 7F0D1550 AFA5003C */  sw    $a1, 0x3c($sp)
/* 106084 7F0D1554 AFA60040 */  sw    $a2, 0x40($sp)
/* 106088 7F0D1558 AFA70044 */  sw    $a3, 0x44($sp)
/* 10608C 7F0D155C 24050020 */  li    $a1, 32
/* 106090 7F0D1560 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 106094 7F0D1564 27A40018 */   addiu $a0, $sp, 0x18
/* 106098 7F0D1568 8FAE0018 */  lw    $t6, 0x18($sp)
/* 10609C 7F0D156C 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 1060A0 7F0D1570 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 1060A4 7F0D1574 11C10003 */  beq   $t6, $at, .L7F0D1584
/* 1060A8 7F0D1578 8FAF001C */   lw    $t7, 0x1c($sp)
/* 1060AC 7F0D157C 1000001F */  b     .L7F0D15FC
/* 1060B0 7F0D1580 00001025 */   move  $v0, $zero
.L7F0D1584:
/* 1060B4 7F0D1584 24010010 */  li    $at, 16
/* 1060B8 7F0D1588 11E10003 */  beq   $t7, $at, .L7F0D1598
/* 1060BC 7F0D158C 8FB80020 */   lw    $t8, 0x20($sp)
/* 1060C0 7F0D1590 1000001A */  b     .L7F0D15FC
/* 1060C4 7F0D1594 00001025 */   move  $v0, $zero
.L7F0D1598:
/* 1060C8 7F0D1598 24010020 */  li    $at, 32
/* 1060CC 7F0D159C 13010003 */  beq   $t8, $at, .L7F0D15AC
/* 1060D0 7F0D15A0 8FB90024 */   lw    $t9, 0x24($sp)
/* 1060D4 7F0D15A4 10000015 */  b     .L7F0D15FC
/* 1060D8 7F0D15A8 00001025 */   move  $v0, $zero
.L7F0D15AC:
/* 1060DC 7F0D15AC 8FA80038 */  lw    $t0, 0x38($sp)
/* 1060E0 7F0D15B0 8FA90028 */  lw    $t1, 0x28($sp)
/* 1060E4 7F0D15B4 8FAA003C */  lw    $t2, 0x3c($sp)
/* 1060E8 7F0D15B8 13280003 */  beq   $t9, $t0, .L7F0D15C8
/* 1060EC 7F0D15BC 00000000 */   nop   
/* 1060F0 7F0D15C0 1000000E */  b     .L7F0D15FC
/* 1060F4 7F0D15C4 00001025 */   move  $v0, $zero
.L7F0D15C8:
/* 1060F8 7F0D15C8 112A0003 */  beq   $t1, $t2, .L7F0D15D8
/* 1060FC 7F0D15CC 8FAB002C */   lw    $t3, 0x2c($sp)
/* 106100 7F0D15D0 1000000A */  b     .L7F0D15FC
/* 106104 7F0D15D4 00001025 */   move  $v0, $zero
.L7F0D15D8:
/* 106108 7F0D15D8 8FAC0040 */  lw    $t4, 0x40($sp)
/* 10610C 7F0D15DC 24020001 */  li    $v0, 1
/* 106110 7F0D15E0 AD8B0000 */  sw    $t3, ($t4)
/* 106114 7F0D15E4 8FAE0044 */  lw    $t6, 0x44($sp)
/* 106118 7F0D15E8 8FAD0030 */  lw    $t5, 0x30($sp)
/* 10611C 7F0D15EC ADCD0000 */  sw    $t5, ($t6)
/* 106120 7F0D15F0 8FB80048 */  lw    $t8, 0x48($sp)
/* 106124 7F0D15F4 8FAF0034 */  lw    $t7, 0x34($sp)
/* 106128 7F0D15F8 AF0F0000 */  sw    $t7, ($t8)
.L7F0D15FC:
/* 10612C 7F0D15FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106130 7F0D1600 27BD0038 */  addiu $sp, $sp, 0x38
/* 106134 7F0D1604 03E00008 */  jr    $ra
/* 106138 7F0D1608 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D160C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D160C
/* 10613C 7F0D160C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 106140 7F0D1610 AFBF0014 */  sw    $ra, 0x14($sp)
/* 106144 7F0D1614 AFA40030 */  sw    $a0, 0x30($sp)
/* 106148 7F0D1618 AFA50034 */  sw    $a1, 0x34($sp)
/* 10614C 7F0D161C AFA60038 */  sw    $a2, 0x38($sp)
/* 106150 7F0D1620 24050018 */  li    $a1, 24
/* 106154 7F0D1624 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 106158 7F0D1628 27A40018 */   addiu $a0, $sp, 0x18
/* 10615C 7F0D162C 8FAE0018 */  lw    $t6, 0x18($sp)
/* 106160 7F0D1630 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 106164 7F0D1634 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 106168 7F0D1638 11C10003 */  beq   $t6, $at, .L7F0D1648
/* 10616C 7F0D163C 8FAF001C */   lw    $t7, 0x1c($sp)
/* 106170 7F0D1640 10000019 */  b     .L7F0D16A8
/* 106174 7F0D1644 00001025 */   move  $v0, $zero
.L7F0D1648:
/* 106178 7F0D1648 2401000E */  li    $at, 14
/* 10617C 7F0D164C 11E10003 */  beq   $t7, $at, .L7F0D165C
/* 106180 7F0D1650 8FB80020 */   lw    $t8, 0x20($sp)
/* 106184 7F0D1654 10000014 */  b     .L7F0D16A8
/* 106188 7F0D1658 00001025 */   move  $v0, $zero
.L7F0D165C:
/* 10618C 7F0D165C 24010018 */  li    $at, 24
/* 106190 7F0D1660 13010003 */  beq   $t8, $at, .L7F0D1670
/* 106194 7F0D1664 8FB90024 */   lw    $t9, 0x24($sp)
/* 106198 7F0D1668 1000000F */  b     .L7F0D16A8
/* 10619C 7F0D166C 00001025 */   move  $v0, $zero
.L7F0D1670:
/* 1061A0 7F0D1670 8FA80030 */  lw    $t0, 0x30($sp)
/* 1061A4 7F0D1674 8FA90028 */  lw    $t1, 0x28($sp)
/* 1061A8 7F0D1678 8FAA0034 */  lw    $t2, 0x34($sp)
/* 1061AC 7F0D167C 13280003 */  beq   $t9, $t0, .L7F0D168C
/* 1061B0 7F0D1680 00000000 */   nop   
/* 1061B4 7F0D1684 10000008 */  b     .L7F0D16A8
/* 1061B8 7F0D1688 00001025 */   move  $v0, $zero
.L7F0D168C:
/* 1061BC 7F0D168C 112A0003 */  beq   $t1, $t2, .L7F0D169C
/* 1061C0 7F0D1690 8FAB002C */   lw    $t3, 0x2c($sp)
/* 1061C4 7F0D1694 10000004 */  b     .L7F0D16A8
/* 1061C8 7F0D1698 00001025 */   move  $v0, $zero
.L7F0D169C:
/* 1061CC 7F0D169C 8FAC0038 */  lw    $t4, 0x38($sp)
/* 1061D0 7F0D16A0 24020001 */  li    $v0, 1
/* 1061D4 7F0D16A4 AD8B0000 */  sw    $t3, ($t4)
.L7F0D16A8:
/* 1061D8 7F0D16A8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1061DC 7F0D16AC 27BD0030 */  addiu $sp, $sp, 0x30
/* 1061E0 7F0D16B0 03E00008 */  jr    $ra
/* 1061E4 7F0D16B4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D16B8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D16B8
/* 1061E8 7F0D16B8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1061EC 7F0D16BC AFBF0014 */  sw    $ra, 0x14($sp)
/* 1061F0 7F0D16C0 AFA40030 */  sw    $a0, 0x30($sp)
/* 1061F4 7F0D16C4 AFA50034 */  sw    $a1, 0x34($sp)
/* 1061F8 7F0D16C8 AFA60038 */  sw    $a2, 0x38($sp)
/* 1061FC 7F0D16CC 24050018 */  li    $a1, 24
/* 106200 7F0D16D0 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 106204 7F0D16D4 27A40018 */   addiu $a0, $sp, 0x18
/* 106208 7F0D16D8 8FAE0018 */  lw    $t6, 0x18($sp)
/* 10620C 7F0D16DC 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 106210 7F0D16E0 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 106214 7F0D16E4 11C10003 */  beq   $t6, $at, .L7F0D16F4
/* 106218 7F0D16E8 8FAF001C */   lw    $t7, 0x1c($sp)
/* 10621C 7F0D16EC 10000019 */  b     .L7F0D1754
/* 106220 7F0D16F0 00001025 */   move  $v0, $zero
.L7F0D16F4:
/* 106224 7F0D16F4 2401000C */  li    $at, 12
/* 106228 7F0D16F8 11E10003 */  beq   $t7, $at, .L7F0D1708
/* 10622C 7F0D16FC 8FB80020 */   lw    $t8, 0x20($sp)
/* 106230 7F0D1700 10000014 */  b     .L7F0D1754
/* 106234 7F0D1704 00001025 */   move  $v0, $zero
.L7F0D1708:
/* 106238 7F0D1708 24010018 */  li    $at, 24
/* 10623C 7F0D170C 13010003 */  beq   $t8, $at, .L7F0D171C
/* 106240 7F0D1710 8FB90024 */   lw    $t9, 0x24($sp)
/* 106244 7F0D1714 1000000F */  b     .L7F0D1754
/* 106248 7F0D1718 00001025 */   move  $v0, $zero
.L7F0D171C:
/* 10624C 7F0D171C 8FA80030 */  lw    $t0, 0x30($sp)
/* 106250 7F0D1720 8FA90028 */  lw    $t1, 0x28($sp)
/* 106254 7F0D1724 8FAA0034 */  lw    $t2, 0x34($sp)
/* 106258 7F0D1728 13280003 */  beq   $t9, $t0, .L7F0D1738
/* 10625C 7F0D172C 00000000 */   nop   
/* 106260 7F0D1730 10000008 */  b     .L7F0D1754
/* 106264 7F0D1734 00001025 */   move  $v0, $zero
.L7F0D1738:
/* 106268 7F0D1738 112A0003 */  beq   $t1, $t2, .L7F0D1748
/* 10626C 7F0D173C 8FAB002C */   lw    $t3, 0x2c($sp)
/* 106270 7F0D1740 10000004 */  b     .L7F0D1754
/* 106274 7F0D1744 00001025 */   move  $v0, $zero
.L7F0D1748:
/* 106278 7F0D1748 8FAC0038 */  lw    $t4, 0x38($sp)
/* 10627C 7F0D174C 24020001 */  li    $v0, 1
/* 106280 7F0D1750 AD8B0000 */  sw    $t3, ($t4)
.L7F0D1754:
/* 106284 7F0D1754 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106288 7F0D1758 27BD0030 */  addiu $sp, $sp, 0x30
/* 10628C 7F0D175C 03E00008 */  jr    $ra
/* 106290 7F0D1760 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1764(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1764
/* 106294 7F0D1764 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 106298 7F0D1768 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10629C 7F0D176C AFA40018 */  sw    $a0, 0x18($sp)
/* 1062A0 7F0D1770 24040018 */  li    $a0, 24
/* 1062A4 7F0D1774 0FC34440 */  jal   sub_GAME_7F0D1100
/* 1062A8 7F0D1778 24050018 */   li    $a1, 24
/* 1062AC 7F0D177C 24040014 */  li    $a0, 20
/* 1062B0 7F0D1780 24050014 */  li    $a1, 20
/* 1062B4 7F0D1784 0FC34492 */  jal   sub_GAME_7F0D1248
/* 1062B8 7F0D1788 8FA60018 */   lw    $a2, 0x18($sp)
/* 1062BC 7F0D178C 00002025 */  move  $a0, $zero
/* 1062C0 7F0D1790 0FC3446B */  jal   sub_GAME_7F0D11AC
/* 1062C4 7F0D1794 00002825 */   move  $a1, $zero
/* 1062C8 7F0D1798 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1062CC 7F0D179C 27BD0018 */  addiu $sp, $sp, 0x18
/* 1062D0 7F0D17A0 24020001 */  li    $v0, 1
/* 1062D4 7F0D17A4 03E00008 */  jr    $ra
/* 1062D8 7F0D17A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D17AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D17AC
/* 1062DC 7F0D17AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1062E0 7F0D17B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1062E4 7F0D17B4 AFA40018 */  sw    $a0, 0x18($sp)
/* 1062E8 7F0D17B8 AFA5001C */  sw    $a1, 0x1c($sp)
/* 1062EC 7F0D17BC 2405001C */  li    $a1, 28
/* 1062F0 7F0D17C0 0FC34440 */  jal   sub_GAME_7F0D1100
/* 1062F4 7F0D17C4 2404001C */   li    $a0, 28
/* 1062F8 7F0D17C8 24040014 */  li    $a0, 20
/* 1062FC 7F0D17CC 24050014 */  li    $a1, 20
/* 106300 7F0D17D0 8FA60018 */  lw    $a2, 0x18($sp)
/* 106304 7F0D17D4 0FC344BD */  jal   sub_GAME_7F0D12F4
/* 106308 7F0D17D8 8FA7001C */   lw    $a3, 0x1c($sp)
/* 10630C 7F0D17DC 00002025 */  move  $a0, $zero
/* 106310 7F0D17E0 0FC3446B */  jal   sub_GAME_7F0D11AC
/* 106314 7F0D17E4 00002825 */   move  $a1, $zero
/* 106318 7F0D17E8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10631C 7F0D17EC 27BD0018 */  addiu $sp, $sp, 0x18
/* 106320 7F0D17F0 24020001 */  li    $v0, 1
/* 106324 7F0D17F4 03E00008 */  jr    $ra
/* 106328 7F0D17F8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D17FC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D17FC
/* 10632C 7F0D17FC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 106330 7F0D1800 AFBF001C */  sw    $ra, 0x1c($sp)
/* 106334 7F0D1804 AFA40020 */  sw    $a0, 0x20($sp)
/* 106338 7F0D1808 AFA50024 */  sw    $a1, 0x24($sp)
/* 10633C 7F0D180C AFA60028 */  sw    $a2, 0x28($sp)
/* 106340 7F0D1810 AFA7002C */  sw    $a3, 0x2c($sp)
/* 106344 7F0D1814 24050020 */  li    $a1, 32
/* 106348 7F0D1818 0FC34440 */  jal   sub_GAME_7F0D1100
/* 10634C 7F0D181C 00002025 */   move  $a0, $zero
/* 106350 7F0D1820 8FAE0028 */  lw    $t6, 0x28($sp)
/* 106354 7F0D1824 8FAF002C */  lw    $t7, 0x2c($sp)
/* 106358 7F0D1828 24040014 */  li    $a0, 20
/* 10635C 7F0D182C 24050014 */  li    $a1, 20
/* 106360 7F0D1830 8FA60020 */  lw    $a2, 0x20($sp)
/* 106364 7F0D1834 8FA70024 */  lw    $a3, 0x24($sp)
/* 106368 7F0D1838 AFAE0010 */  sw    $t6, 0x10($sp)
/* 10636C 7F0D183C 0FC344EC */  jal   sub_GAME_7F0D13B0
/* 106370 7F0D1840 AFAF0014 */   sw    $t7, 0x14($sp)
/* 106374 7F0D1844 00002025 */  move  $a0, $zero
/* 106378 7F0D1848 0FC3446B */  jal   sub_GAME_7F0D11AC
/* 10637C 7F0D184C 00002825 */   move  $a1, $zero
/* 106380 7F0D1850 8FBF001C */  lw    $ra, 0x1c($sp)
/* 106384 7F0D1854 27BD0020 */  addiu $sp, $sp, 0x20
/* 106388 7F0D1858 24020001 */  li    $v0, 1
/* 10638C 7F0D185C 03E00008 */  jr    $ra
/* 106390 7F0D1860 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1864(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1864
/* 106394 7F0D1864 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 106398 7F0D1868 AFBF0014 */  sw    $ra, 0x14($sp)
/* 10639C 7F0D186C AFA40018 */  sw    $a0, 0x18($sp)
/* 1063A0 7F0D1870 24040018 */  li    $a0, 24
/* 1063A4 7F0D1874 0FC34440 */  jal   sub_GAME_7F0D1100
/* 1063A8 7F0D1878 24050018 */   li    $a1, 24
/* 1063AC 7F0D187C 24040014 */  li    $a0, 20
/* 1063B0 7F0D1880 24050014 */  li    $a1, 20
/* 1063B4 7F0D1884 0FC34526 */  jal   sub_GAME_7F0D1498
/* 1063B8 7F0D1888 8FA60018 */   lw    $a2, 0x18($sp)
/* 1063BC 7F0D188C 00002025 */  move  $a0, $zero
/* 1063C0 7F0D1890 0FC3446B */  jal   sub_GAME_7F0D11AC
/* 1063C4 7F0D1894 00002825 */   move  $a1, $zero
/* 1063C8 7F0D1898 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1063CC 7F0D189C 27BD0018 */  addiu $sp, $sp, 0x18
/* 1063D0 7F0D18A0 24020001 */  li    $v0, 1
/* 1063D4 7F0D18A4 03E00008 */  jr    $ra
/* 1063D8 7F0D18A8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D18AC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D18AC
/* 1063DC 7F0D18AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1063E0 7F0D18B0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1063E4 7F0D18B4 AFA40020 */  sw    $a0, 0x20($sp)
/* 1063E8 7F0D18B8 AFA50024 */  sw    $a1, 0x24($sp)
/* 1063EC 7F0D18BC AFA60028 */  sw    $a2, 0x28($sp)
/* 1063F0 7F0D18C0 24050020 */  li    $a1, 32
/* 1063F4 7F0D18C4 0FC34440 */  jal   sub_GAME_7F0D1100
/* 1063F8 7F0D18C8 24040020 */   li    $a0, 32
/* 1063FC 7F0D18CC 8FAE0028 */  lw    $t6, 0x28($sp)
/* 106400 7F0D18D0 24040014 */  li    $a0, 20
/* 106404 7F0D18D4 24050014 */  li    $a1, 20
/* 106408 7F0D18D8 8FA60020 */  lw    $a2, 0x20($sp)
/* 10640C 7F0D18DC 8FA70024 */  lw    $a3, 0x24($sp)
/* 106410 7F0D18E0 0FC34551 */  jal   sub_GAME_7F0D1544
/* 106414 7F0D18E4 AFAE0010 */   sw    $t6, 0x10($sp)
/* 106418 7F0D18E8 00002025 */  move  $a0, $zero
/* 10641C 7F0D18EC 0FC3446B */  jal   sub_GAME_7F0D11AC
/* 106420 7F0D18F0 00002825 */   move  $a1, $zero
/* 106424 7F0D18F4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 106428 7F0D18F8 27BD0020 */  addiu $sp, $sp, 0x20
/* 10642C 7F0D18FC 24020001 */  li    $v0, 1
/* 106430 7F0D1900 03E00008 */  jr    $ra
/* 106434 7F0D1904 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1908(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1908
/* 106438 7F0D1908 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 10643C 7F0D190C AFBF0014 */  sw    $ra, 0x14($sp)
/* 106440 7F0D1910 AFA40018 */  sw    $a0, 0x18($sp)
/* 106444 7F0D1914 24040018 */  li    $a0, 24
/* 106448 7F0D1918 0FC34440 */  jal   sub_GAME_7F0D1100
/* 10644C 7F0D191C 24050018 */   li    $a1, 24
/* 106450 7F0D1920 24040014 */  li    $a0, 20
/* 106454 7F0D1924 24050014 */  li    $a1, 20
/* 106458 7F0D1928 0FC34583 */  jal   sub_GAME_7F0D160C
/* 10645C 7F0D192C 8FA60018 */   lw    $a2, 0x18($sp)
/* 106460 7F0D1930 00002025 */  move  $a0, $zero
/* 106464 7F0D1934 0FC3446B */  jal   sub_GAME_7F0D11AC
/* 106468 7F0D1938 00002825 */   move  $a1, $zero
/* 10646C 7F0D193C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 106470 7F0D1940 27BD0018 */  addiu $sp, $sp, 0x18
/* 106474 7F0D1944 24020001 */  li    $v0, 1
/* 106478 7F0D1948 03E00008 */  jr    $ra
/* 10647C 7F0D194C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1950(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1950
/* 106480 7F0D1950 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 106484 7F0D1954 AFBF0014 */  sw    $ra, 0x14($sp)
/* 106488 7F0D1958 AFA40018 */  sw    $a0, 0x18($sp)
/* 10648C 7F0D195C 24040018 */  li    $a0, 24
/* 106490 7F0D1960 0FC34440 */  jal   sub_GAME_7F0D1100
/* 106494 7F0D1964 24050018 */   li    $a1, 24
/* 106498 7F0D1968 24040014 */  li    $a0, 20
/* 10649C 7F0D196C 24050014 */  li    $a1, 20
/* 1064A0 7F0D1970 0FC345AE */  jal   sub_GAME_7F0D16B8
/* 1064A4 7F0D1974 8FA60018 */   lw    $a2, 0x18($sp)
/* 1064A8 7F0D1978 00002025 */  move  $a0, $zero
/* 1064AC 7F0D197C 0FC3446B */  jal   sub_GAME_7F0D11AC
/* 1064B0 7F0D1980 00002825 */   move  $a1, $zero
/* 1064B4 7F0D1984 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1064B8 7F0D1988 27BD0018 */  addiu $sp, $sp, 0x18
/* 1064BC 7F0D198C 24020001 */  li    $v0, 1
/* 1064C0 7F0D1990 03E00008 */  jr    $ra
/* 1064C4 7F0D1994 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0D1998(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0D1998
/* 1064C8 7F0D1998 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 1064CC 7F0D199C AFBF0014 */  sw    $ra, 0x14($sp)
/* 1064D0 7F0D19A0 AFA40030 */  sw    $a0, 0x30($sp)
/* 1064D4 7F0D19A4 AFA50034 */  sw    $a1, 0x34($sp)
/* 1064D8 7F0D19A8 24050014 */  li    $a1, 20
/* 1064DC 7F0D19AC 0FC343D3 */  jal   sub_GAME_7F0D0F4C
/* 1064E0 7F0D19B0 27A4001C */   addiu $a0, $sp, 0x1c
/* 1064E4 7F0D19B4 8FAE001C */  lw    $t6, 0x1c($sp)
/* 1064E8 7F0D19B8 3C019ABF */  lui   $at, (0x9ABF1623 >> 16) # lui $at, 0x9abf
/* 1064EC 7F0D19BC 34211623 */  ori   $at, (0x9ABF1623 & 0xFFFF) # ori $at, $at, 0x1623
/* 1064F0 7F0D19C0 8FA20030 */  lw    $v0, 0x30($sp)
/* 1064F4 7F0D19C4 11C10003 */  beq   $t6, $at, .L7F0D19D4
/* 1064F8 7F0D19C8 8FA30034 */   lw    $v1, 0x34($sp)
/* 1064FC 7F0D19CC 1000000E */  b     .L7F0D1A08
/* 106500 7F0D19D0 00001025 */   move  $v0, $zero
.L7F0D19D4:
/* 106504 7F0D19D4 10400005 */  beqz  $v0, .L7F0D19EC
/* 106508 7F0D19D8 8FAF0028 */   lw    $t7, 0x28($sp)
/* 10650C 7F0D19DC 11E20003 */  beq   $t7, $v0, .L7F0D19EC
/* 106510 7F0D19E0 00000000 */   nop   
/* 106514 7F0D19E4 10000008 */  b     .L7F0D1A08
/* 106518 7F0D19E8 00001025 */   move  $v0, $zero
.L7F0D19EC:
/* 10651C 7F0D19EC 10600005 */  beqz  $v1, .L7F0D1A04
/* 106520 7F0D19F0 8FB8002C */   lw    $t8, 0x2c($sp)
/* 106524 7F0D19F4 53030004 */  beql  $t8, $v1, .L7F0D1A08
/* 106528 7F0D19F8 24020001 */   li    $v0, 1
/* 10652C 7F0D19FC 10000002 */  b     .L7F0D1A08
/* 106530 7F0D1A00 00001025 */   move  $v0, $zero
.L7F0D1A04:
/* 106534 7F0D1A04 24020001 */  li    $v0, 1
.L7F0D1A08:
/* 106538 7F0D1A08 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10653C 7F0D1A0C 27BD0030 */  addiu $sp, $sp, 0x30
/* 106540 7F0D1A10 03E00008 */  jr    $ra
/* 106544 7F0D1A14 00000000 */   nop   
)
#endif



