#include "ultra64.h"



#ifdef NONMATCHING
void alloc_explosion_smoke_casing_scorch_impact_buffers(void) {

}
#else
GLOBAL_ASM(
.text
glabel alloc_explosion_smoke_casing_scorch_impact_buffers
/* 03B8C0 7F006D90 3C018004 */  lui   $at, %hi(D_80040170)
/* 03B8C4 7F006D94 AC200170 */  sw    $zero, %lo(D_80040170)($at)
/* 03B8C8 7F006D98 3C018004 */  lui   $at, %hi(D_80040174)
/* 03B8CC 7F006D9C AC200174 */  sw    $zero, %lo(D_80040174)($at)
/* 03B8D0 7F006DA0 3C018004 */  lui   $at, %hi(D_8004017C+0x684)
/* 03B8D4 7F006DA4 AC200800 */  sw    $zero, %lo(D_8004017C+0x684)($at)
/* 03B8D8 7F006DA8 3C018004 */  lui   $at, %hi(D_8004017C+0x688)
/* 03B8DC 7F006DAC AC200804 */  sw    $zero, %lo(D_8004017C+0x688)($at)
/* 03B8E0 7F006DB0 3C018004 */  lui   $at, %hi(D_8004017C+0x68C)
/* 03B8E4 7F006DB4 AC200808 */  sw    $zero, %lo(D_8004017C+0x68C)($at)
/* 03B8E8 7F006DB8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 03B8EC 7F006DBC 44812000 */  mtc1  $at, $f4
/* 03B8F0 7F006DC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03B8F4 7F006DC4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03B8F8 7F006DC8 3C018004 */  lui   $at, %hi(D_80040178)
/* 03B8FC 7F006DCC 24041740 */  li    $a0, 5952
/* 03B900 7F006DD0 24050004 */  li    $a1, 4
/* 03B904 7F006DD4 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03B908 7F006DD8 E4240178 */   swc1  $f4, %lo(D_80040178)($at)
/* 03B90C 7F006DDC 3C038008 */  lui   $v1, %hi(ptr_explosion_buf)
/* 03B910 7F006DE0 2463A144 */  addiu $v1, %lo(ptr_explosion_buf) # addiu $v1, $v1, -0x5ebc
/* 03B914 7F006DE4 AC620000 */  sw    $v0, ($v1)
/* 03B918 7F006DE8 00002025 */  move  $a0, $zero
/* 03B91C 7F006DEC 00003025 */  move  $a2, $zero
/* 03B920 7F006DF0 240503C0 */  li    $a1, 960
.L7F006DF4:
/* 03B924 7F006DF4 8C6E0000 */  lw    $t6, ($v1)
/* 03B928 7F006DF8 00001025 */  move  $v0, $zero
/* 03B92C 7F006DFC 01C67821 */  addu  $t7, $t6, $a2
/* 03B930 7F006E00 ADE00000 */  sw    $zero, ($t7)
.L7F006E04:
/* 03B934 7F006E04 8C780000 */  lw    $t8, ($v1)
/* 03B938 7F006E08 0004C940 */  sll   $t9, $a0, 5
/* 03B93C 7F006E0C 0324C823 */  subu  $t9, $t9, $a0
/* 03B940 7F006E10 0019C940 */  sll   $t9, $t9, 5
/* 03B944 7F006E14 03194021 */  addu  $t0, $t8, $t9
/* 03B948 7F006E18 01024821 */  addu  $t1, $t0, $v0
/* 03B94C 7F006E1C A520001C */  sh    $zero, 0x1c($t1)
/* 03B950 7F006E20 8C6A0000 */  lw    $t2, ($v1)
/* 03B954 7F006E24 00045940 */  sll   $t3, $a0, 5
/* 03B958 7F006E28 01645823 */  subu  $t3, $t3, $a0
/* 03B95C 7F006E2C 000B5940 */  sll   $t3, $t3, 5
/* 03B960 7F006E30 014B6021 */  addu  $t4, $t2, $t3
/* 03B964 7F006E34 01826821 */  addu  $t5, $t4, $v0
/* 03B968 7F006E38 A5A00034 */  sh    $zero, 0x34($t5)
/* 03B96C 7F006E3C 8C6E0000 */  lw    $t6, ($v1)
/* 03B970 7F006E40 00047940 */  sll   $t7, $a0, 5
/* 03B974 7F006E44 01E47823 */  subu  $t7, $t7, $a0
/* 03B978 7F006E48 000F7940 */  sll   $t7, $t7, 5
/* 03B97C 7F006E4C 01CFC021 */  addu  $t8, $t6, $t7
/* 03B980 7F006E50 0302C821 */  addu  $t9, $t8, $v0
/* 03B984 7F006E54 A720004C */  sh    $zero, 0x4c($t9)
/* 03B988 7F006E58 8C680000 */  lw    $t0, ($v1)
/* 03B98C 7F006E5C 00044940 */  sll   $t1, $a0, 5
/* 03B990 7F006E60 01244823 */  subu  $t1, $t1, $a0
/* 03B994 7F006E64 00094940 */  sll   $t1, $t1, 5
/* 03B998 7F006E68 01095021 */  addu  $t2, $t0, $t1
/* 03B99C 7F006E6C 01425821 */  addu  $t3, $t2, $v0
/* 03B9A0 7F006E70 24420060 */  addiu $v0, $v0, 0x60
/* 03B9A4 7F006E74 1445FFE3 */  bne   $v0, $a1, .L7F006E04
/* 03B9A8 7F006E78 A5600064 */   sh    $zero, 0x64($t3)
/* 03B9AC 7F006E7C 24840001 */  addiu $a0, $a0, 1
/* 03B9B0 7F006E80 28810006 */  slti  $at, $a0, 6
/* 03B9B4 7F006E84 1420FFDB */  bnez  $at, .L7F006DF4
/* 03B9B8 7F006E88 24C603E0 */   addiu $a2, $a2, 0x3e0
/* 03B9BC 7F006E8C 24041FE0 */  li    $a0, 8160
/* 03B9C0 7F006E90 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03B9C4 7F006E94 24050004 */   li    $a1, 4
/* 03B9C8 7F006E98 3C038008 */  lui   $v1, %hi(ptr_smoke_buf)
/* 03B9CC 7F006E9C 2463A140 */  addiu $v1, %lo(ptr_smoke_buf) # addiu $v1, $v1, -0x5ec0
/* 03B9D0 7F006EA0 44800000 */  mtc1  $zero, $f0
/* 03B9D4 7F006EA4 AC620000 */  sw    $v0, ($v1)
/* 03B9D8 7F006EA8 00002025 */  move  $a0, $zero
/* 03B9DC 7F006EAC 00003025 */  move  $a2, $zero
/* 03B9E0 7F006EB0 24050190 */  li    $a1, 400
.L7F006EB4:
/* 03B9E4 7F006EB4 8C6C0000 */  lw    $t4, ($v1)
/* 03B9E8 7F006EB8 00047880 */  sll   $t7, $a0, 2
/* 03B9EC 7F006EBC 01E47823 */  subu  $t7, $t7, $a0
/* 03B9F0 7F006EC0 000F7880 */  sll   $t7, $t7, 2
/* 03B9F4 7F006EC4 01866821 */  addu  $t5, $t4, $a2
/* 03B9F8 7F006EC8 ADA00000 */  sw    $zero, ($t5)
/* 03B9FC 7F006ECC 01E47821 */  addu  $t7, $t7, $a0
/* 03BA00 7F006ED0 8C6E0000 */  lw    $t6, ($v1)
/* 03BA04 7F006ED4 000F7880 */  sll   $t7, $t7, 2
/* 03BA08 7F006ED8 01E47823 */  subu  $t7, $t7, $a0
/* 03BA0C 7F006EDC 00044080 */  sll   $t0, $a0, 2
/* 03BA10 7F006EE0 01044023 */  subu  $t0, $t0, $a0
/* 03BA14 7F006EE4 000F78C0 */  sll   $t7, $t7, 3
/* 03BA18 7F006EE8 00084080 */  sll   $t0, $t0, 2
/* 03BA1C 7F006EEC 01CFC021 */  addu  $t8, $t6, $t7
/* 03BA20 7F006EF0 E7000014 */  swc1  $f0, 0x14($t8)
/* 03BA24 7F006EF4 01044021 */  addu  $t0, $t0, $a0
/* 03BA28 7F006EF8 8C790000 */  lw    $t9, ($v1)
/* 03BA2C 7F006EFC 00084080 */  sll   $t0, $t0, 2
/* 03BA30 7F006F00 01044023 */  subu  $t0, $t0, $a0
/* 03BA34 7F006F04 000840C0 */  sll   $t0, $t0, 3
/* 03BA38 7F006F08 03284821 */  addu  $t1, $t9, $t0
/* 03BA3C 7F006F0C E520003C */  swc1  $f0, 0x3c($t1)
/* 03BA40 7F006F10 24020050 */  li    $v0, 80
.L7F006F14:
/* 03BA44 7F006F14 00045880 */  sll   $t3, $a0, 2
/* 03BA48 7F006F18 01645823 */  subu  $t3, $t3, $a0
/* 03BA4C 7F006F1C 000B5880 */  sll   $t3, $t3, 2
/* 03BA50 7F006F20 01645821 */  addu  $t3, $t3, $a0
/* 03BA54 7F006F24 8C6A0000 */  lw    $t2, ($v1)
/* 03BA58 7F006F28 000B5880 */  sll   $t3, $t3, 2
/* 03BA5C 7F006F2C 01645823 */  subu  $t3, $t3, $a0
/* 03BA60 7F006F30 00047880 */  sll   $t7, $a0, 2
/* 03BA64 7F006F34 000B58C0 */  sll   $t3, $t3, 3
/* 03BA68 7F006F38 01E47823 */  subu  $t7, $t7, $a0
/* 03BA6C 7F006F3C 014B6021 */  addu  $t4, $t2, $t3
/* 03BA70 7F006F40 000F7880 */  sll   $t7, $t7, 2
/* 03BA74 7F006F44 01826821 */  addu  $t5, $t4, $v0
/* 03BA78 7F006F48 01E47821 */  addu  $t7, $t7, $a0
/* 03BA7C 7F006F4C E5A00014 */  swc1  $f0, 0x14($t5)
/* 03BA80 7F006F50 8C6E0000 */  lw    $t6, ($v1)
/* 03BA84 7F006F54 000F7880 */  sll   $t7, $t7, 2
/* 03BA88 7F006F58 01E47823 */  subu  $t7, $t7, $a0
/* 03BA8C 7F006F5C 000F78C0 */  sll   $t7, $t7, 3
/* 03BA90 7F006F60 00044880 */  sll   $t1, $a0, 2
/* 03BA94 7F006F64 01244823 */  subu  $t1, $t1, $a0
/* 03BA98 7F006F68 01CFC021 */  addu  $t8, $t6, $t7
/* 03BA9C 7F006F6C 0302C821 */  addu  $t9, $t8, $v0
/* 03BAA0 7F006F70 00094880 */  sll   $t1, $t1, 2
/* 03BAA4 7F006F74 01244821 */  addu  $t1, $t1, $a0
/* 03BAA8 7F006F78 E720003C */  swc1  $f0, 0x3c($t9)
/* 03BAAC 7F006F7C 8C680000 */  lw    $t0, ($v1)
/* 03BAB0 7F006F80 00094880 */  sll   $t1, $t1, 2
/* 03BAB4 7F006F84 01244823 */  subu  $t1, $t1, $a0
/* 03BAB8 7F006F88 000948C0 */  sll   $t1, $t1, 3
/* 03BABC 7F006F8C 00046880 */  sll   $t5, $a0, 2
/* 03BAC0 7F006F90 01A46823 */  subu  $t5, $t5, $a0
/* 03BAC4 7F006F94 01095021 */  addu  $t2, $t0, $t1
/* 03BAC8 7F006F98 01425821 */  addu  $t3, $t2, $v0
/* 03BACC 7F006F9C 000D6880 */  sll   $t5, $t5, 2
/* 03BAD0 7F006FA0 01A46821 */  addu  $t5, $t5, $a0
/* 03BAD4 7F006FA4 E5600064 */  swc1  $f0, 0x64($t3)
/* 03BAD8 7F006FA8 8C6C0000 */  lw    $t4, ($v1)
/* 03BADC 7F006FAC 000D6880 */  sll   $t5, $t5, 2
/* 03BAE0 7F006FB0 01A46823 */  subu  $t5, $t5, $a0
/* 03BAE4 7F006FB4 000D68C0 */  sll   $t5, $t5, 3
/* 03BAE8 7F006FB8 018D7021 */  addu  $t6, $t4, $t5
/* 03BAEC 7F006FBC 01C27821 */  addu  $t7, $t6, $v0
/* 03BAF0 7F006FC0 244200A0 */  addiu $v0, $v0, 0xa0
/* 03BAF4 7F006FC4 1445FFD3 */  bne   $v0, $a1, .L7F006F14
/* 03BAF8 7F006FC8 E5E0008C */   swc1  $f0, 0x8c($t7)
/* 03BAFC 7F006FCC 24840001 */  addiu $a0, $a0, 1
/* 03BB00 7F006FD0 28810014 */  slti  $at, $a0, 0x14
/* 03BB04 7F006FD4 1420FFB7 */  bnez  $at, .L7F006EB4
/* 03BB08 7F006FD8 24C60198 */   addiu $a2, $a2, 0x198
/* 03BB0C 7F006FDC 0FC26919 */  jal   get_num_players
/* 03BB10 7F006FE0 00000000 */   nop   
/* 03BB14 7F006FE4 24010001 */  li    $at, 1
/* 03BB18 7F006FE8 14410017 */  bne   $v0, $at, .L7F007048
/* 03BB1C 7F006FEC 240406E0 */   li    $a0, 1760
/* 03BB20 7F006FF0 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03BB24 7F006FF4 24050004 */   li    $a1, 4
/* 03BB28 7F006FF8 3C058008 */  lui   $a1, %hi(ptr_scorch_buf)
/* 03BB2C 7F006FFC 24A5A150 */  addiu $a1, %lo(ptr_scorch_buf) # addiu $a1, $a1, -0x5eb0
/* 03BB30 7F007000 ACA20000 */  sw    $v0, ($a1)
/* 03BB34 7F007004 240206E0 */  li    $v0, 1760
/* 03BB38 7F007008 00001825 */  move  $v1, $zero
/* 03BB3C 7F00700C 2406FFFF */  li    $a2, -1
.L7F007010:
/* 03BB40 7F007010 8CB80000 */  lw    $t8, ($a1)
/* 03BB44 7F007014 0303C821 */  addu  $t9, $t8, $v1
/* 03BB48 7F007018 A7260000 */  sh    $a2, ($t9)
/* 03BB4C 7F00701C 8CA80000 */  lw    $t0, ($a1)
/* 03BB50 7F007020 01034821 */  addu  $t1, $t0, $v1
/* 03BB54 7F007024 A5260058 */  sh    $a2, 0x58($t1)
/* 03BB58 7F007028 8CAA0000 */  lw    $t2, ($a1)
/* 03BB5C 7F00702C 01435821 */  addu  $t3, $t2, $v1
/* 03BB60 7F007030 A56600B0 */  sh    $a2, 0xb0($t3)
/* 03BB64 7F007034 8CAC0000 */  lw    $t4, ($a1)
/* 03BB68 7F007038 01836821 */  addu  $t5, $t4, $v1
/* 03BB6C 7F00703C 24630160 */  addiu $v1, $v1, 0x160
/* 03BB70 7F007040 1462FFF3 */  bne   $v1, $v0, .L7F007010
/* 03BB74 7F007044 A5A60108 */   sh    $a2, 0x108($t5)
.L7F007048:
/* 03BB78 7F007048 24041F40 */  li    $a0, 8000
/* 03BB7C 7F00704C 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03BB80 7F007050 24050004 */   li    $a1, 4
/* 03BB84 7F007054 3C058008 */  lui   $a1, %hi(ptr_bullet_impact_buf)
/* 03BB88 7F007058 24A5A154 */  addiu $a1, %lo(ptr_bullet_impact_buf) # addiu $a1, $a1, -0x5eac
/* 03BB8C 7F00705C ACA20000 */  sw    $v0, ($a1)
/* 03BB90 7F007060 2406FFFF */  li    $a2, -1
/* 03BB94 7F007064 00001825 */  move  $v1, $zero
.L7F007068:
/* 03BB98 7F007068 8CAE0000 */  lw    $t6, ($a1)
/* 03BB9C 7F00706C 01C37821 */  addu  $t7, $t6, $v1
/* 03BBA0 7F007070 24630050 */  addiu $v1, $v1, 0x50
/* 03BBA4 7F007074 28611F40 */  slti  $at, $v1, 0x1f40
/* 03BBA8 7F007078 1420FFFB */  bnez  $at, .L7F007068
/* 03BBAC 7F00707C A5E60000 */   sh    $a2, ($t7)
/* 03BBB0 7F007080 0FC26919 */  jal   get_num_players
/* 03BBB4 7F007084 00000000 */   nop   
/* 03BBB8 7F007088 241800C8 */  li    $t8, 200
/* 03BBBC 7F00708C 0302001A */  div   $zero, $t8, $v0
/* 03BBC0 7F007090 3C068008 */  lui   $a2, %hi(max_casings)
/* 03BBC4 7F007094 24C6A148 */  addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
/* 03BBC8 7F007098 14400002 */  bnez  $v0, .L7F0070A4
/* 03BBCC 7F00709C 00000000 */   nop   
/* 03BBD0 7F0070A0 0007000D */  break 7
.L7F0070A4:
/* 03BBD4 7F0070A4 2401FFFF */  li    $at, -1
/* 03BBD8 7F0070A8 14410004 */  bne   $v0, $at, .L7F0070BC
/* 03BBDC 7F0070AC 3C018000 */   lui   $at, 0x8000
/* 03BBE0 7F0070B0 17010002 */  bne   $t8, $at, .L7F0070BC
/* 03BBE4 7F0070B4 00000000 */   nop   
/* 03BBE8 7F0070B8 0006000D */  break 6
.L7F0070BC:
/* 03BBEC 7F0070BC 0000C812 */  mflo  $t9
/* 03BBF0 7F0070C0 ACD90000 */  sw    $t9, ($a2)
/* 03BBF4 7F0070C4 0FC2F7C1 */  jal   sub_GAME_7F0BDF04
/* 03BBF8 7F0070C8 00000000 */   nop   
/* 03BBFC 7F0070CC 3C068008 */  lui   $a2, %hi(max_casings)
/* 03BC00 7F0070D0 2401001D */  li    $at, 29
/* 03BC04 7F0070D4 10410007 */  beq   $v0, $at, .L7F0070F4
/* 03BC08 7F0070D8 24C6A148 */   addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
/* 03BC0C 7F0070DC 0FC2F7C1 */  jal   sub_GAME_7F0BDF04
/* 03BC10 7F0070E0 00000000 */   nop   
/* 03BC14 7F0070E4 3C068008 */  lui   $a2, %hi(max_casings)
/* 03BC18 7F0070E8 2401001E */  li    $at, 30
/* 03BC1C 7F0070EC 14410004 */  bne   $v0, $at, .L7F007100
/* 03BC20 7F0070F0 24C6A148 */   addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
.L7F0070F4:
/* 03BC24 7F0070F4 8CC80000 */  lw    $t0, ($a2)
/* 03BC28 7F0070F8 00084843 */  sra   $t1, $t0, 1
/* 03BC2C 7F0070FC ACC90000 */  sw    $t1, ($a2)
.L7F007100:
/* 03BC30 7F007100 8CC40000 */  lw    $a0, ($a2)
/* 03BC34 7F007104 2401FFF0 */  li    $at, -16
/* 03BC38 7F007108 24050004 */  li    $a1, 4
/* 03BC3C 7F00710C 00045100 */  sll   $t2, $a0, 4
/* 03BC40 7F007110 01445023 */  subu  $t2, $t2, $a0
/* 03BC44 7F007114 000A50C0 */  sll   $t2, $t2, 3
/* 03BC48 7F007118 2544000F */  addiu $a0, $t2, 0xf
/* 03BC4C 7F00711C 00815824 */  and   $t3, $a0, $at
/* 03BC50 7F007120 0C0025C8 */  jal   allocate_bytes_in_bank
/* 03BC54 7F007124 01602025 */   move  $a0, $t3
/* 03BC58 7F007128 3C068008 */  lui   $a2, %hi(max_casings)
/* 03BC5C 7F00712C 24C6A148 */  addiu $a2, %lo(max_casings) # addiu $a2, $a2, -0x5eb8
/* 03BC60 7F007130 8CCC0000 */  lw    $t4, ($a2)
/* 03BC64 7F007134 3C038008 */  lui   $v1, %hi(ptr_ejected_casing_buf)
/* 03BC68 7F007138 2463A14C */  addiu $v1, %lo(ptr_ejected_casing_buf) # addiu $v1, $v1, -0x5eb4
/* 03BC6C 7F00713C AC620000 */  sw    $v0, ($v1)
/* 03BC70 7F007140 1980000B */  blez  $t4, .L7F007170
/* 03BC74 7F007144 00002025 */   move  $a0, $zero
/* 03BC78 7F007148 00001025 */  move  $v0, $zero
/* 03BC7C 7F00714C 8C6D0000 */  lw    $t5, ($v1)
.L7F007150:
/* 03BC80 7F007150 24840001 */  addiu $a0, $a0, 1
/* 03BC84 7F007154 01A27021 */  addu  $t6, $t5, $v0
/* 03BC88 7F007158 ADC00000 */  sw    $zero, ($t6)
/* 03BC8C 7F00715C 8CCF0000 */  lw    $t7, ($a2)
/* 03BC90 7F007160 24420078 */  addiu $v0, $v0, 0x78
/* 03BC94 7F007164 008F082A */  slt   $at, $a0, $t7
/* 03BC98 7F007168 5420FFF9 */  bnezl $at, .L7F007150
/* 03BC9C 7F00716C 8C6D0000 */   lw    $t5, ($v1)
.L7F007170:
/* 03BCA0 7F007170 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03BCA4 7F007174 27BD0018 */  addiu $sp, $sp, 0x18
/* 03BCA8 7F007178 03E00008 */  jr    $ra
/* 03BCAC 7F00717C 00000000 */   nop   
)
#endif


