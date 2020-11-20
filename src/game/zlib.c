#include "ultra64.h"
#include "zlib.h"
//.bss

//bss:8008D350
s32 dword_CODE_bss_8008D350;
//bss:8008D354
s32 dword_CODE_bss_8008D354;
//bss:8008D358
s32 dword_CODE_bss_8008D358;
//bss:8008D35C
s32 dword_CODE_bss_8008D35C;
//bss:8008D360
s32 dword_CODE_bss_8008D360;
//bss:8008D364
s32 dword_CODE_bss_8008D364;
//bss:8008D368
s32 dword_CODE_bss_8008D368;
//bss:8008D36C
s32 dword_CODE_bss_8008D36C;


//.data
u8 D_8004E8E0[] = {
    0x10,0x11,0x12,   0,   8,   7,   9,   6, 0xA,   5, 0xB,   4, 0xC,   3,
    0xD,   2, 0xE,   1, 0xF,   0
};

s16 D_8004E8F4[] = {
    3,     4,     5,     6,     7,     8,     9,   0xA,   0xB,   0xD,
    0xF,  0x11,  0x13,  0x17,  0x1B,  0x1F,  0x23,  0x2B,  0x33,  0x3B,
    0x43,  0x53,  0x63,  0x73,  0x83,  0xA3,  0xC3,  0xE3, 0x102,     0,
   0,     0
};

u32 D_8004E934[] = {
    0, 0, 0x1010101, 0x2020202, 0x3030303, 0x4040404, 0x5050505, 0x636300
};

s16 D_8004E954[] = {
    1 , 2, 3, 4, 5, 7, 9, 0xD, 0x11, 0x19, 0x21, 0x31, 0x41, 0x61,
    0x81, 0xC1, 0x101, 0x181, 0x201, 0x301, 0x401, 0x601, 0x801, 
    0xC01, 0x1001, 0x1801, 0x2001, 0x3001, 0x4001, 0x6001
};

u16 D_8004E990[] = {
    0, 0, 0x101, 0x202, 0x303, 0x404, 0x505, 0x606,
    0x707, 0x808, 0x909, 0xA0A, 0xB0B, 0xC0C, 0xD0D, 0
};

u16 D_8004E9B0[] = {
    0, 1, 3, 7, 0xF, 0x1F, 0x3F, 0x7F, 0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF, 0xFFFF, 0
};

s32 D_8004E9D4 = 9;
s32 D_8004E9D8 = 6;

//.rodata


#ifdef NONMATCHING
void sub_GAME_7F0CE8B0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CE8B0
/* 1033E0 7F0CE8B0 27BDFA08 */  addiu $sp, $sp, -0x5f8
/* 1033E4 7F0CE8B4 AFB20020 */  sw    $s2, 0x20($sp)
/* 1033E8 7F0CE8B8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 1033EC 7F0CE8BC 27B105B0 */  addiu $s1, $sp, 0x5b0
/* 1033F0 7F0CE8C0 00809025 */  move  $s2, $a0
/* 1033F4 7F0CE8C4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 1033F8 7F0CE8C8 AFA505FC */  sw    $a1, 0x5fc($sp)
/* 1033FC 7F0CE8CC AFBE0038 */  sw    $fp, 0x38($sp)
/* 103400 7F0CE8D0 AFB70034 */  sw    $s7, 0x34($sp)
/* 103404 7F0CE8D4 AFB60030 */  sw    $s6, 0x30($sp)
/* 103408 7F0CE8D8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 10340C 7F0CE8DC AFB40028 */  sw    $s4, 0x28($sp)
/* 103410 7F0CE8E0 AFB30024 */  sw    $s3, 0x24($sp)
/* 103414 7F0CE8E4 AFB00018 */  sw    $s0, 0x18($sp)
/* 103418 7F0CE8E8 AFA60600 */  sw    $a2, 0x600($sp)
/* 10341C 7F0CE8EC AFA70604 */  sw    $a3, 0x604($sp)
/* 103420 7F0CE8F0 24050044 */  li    $a1, 68
/* 103424 7F0CE8F4 0C005F10 */  jal   bzero
/* 103428 7F0CE8F8 02202025 */   move  $a0, $s1
/* 10342C 7F0CE8FC 8FAE05FC */  lw    $t6, 0x5fc($sp)
/* 103430 7F0CE900 0240F025 */  move  $fp, $s2
/* 103434 7F0CE904 24070001 */  li    $a3, 1
/* 103438 7F0CE908 31C20003 */  andi  $v0, $t6, 3
/* 10343C 7F0CE90C 00021023 */  negu  $v0, $v0
/* 103440 7F0CE910 1040000D */  beqz  $v0, .L7F0CE948
/* 103444 7F0CE914 01C0F825 */   move  $ra, $t6
/* 103448 7F0CE918 004E1821 */  addu  $v1, $v0, $t6
.L7F0CE91C:
/* 10344C 7F0CE91C 8FCF0000 */  lw    $t7, ($fp)
/* 103450 7F0CE920 27FFFFFF */  addiu $ra, $ra, -1
/* 103454 7F0CE924 27DE0004 */  addiu $fp, $fp, 4
/* 103458 7F0CE928 000FC080 */  sll   $t8, $t7, 2
/* 10345C 7F0CE92C 02381021 */  addu  $v0, $s1, $t8
/* 103460 7F0CE930 8C590000 */  lw    $t9, ($v0)
/* 103464 7F0CE934 272E0001 */  addiu $t6, $t9, 1
/* 103468 7F0CE938 147FFFF8 */  bne   $v1, $ra, .L7F0CE91C
/* 10346C 7F0CE93C AC4E0000 */   sw    $t6, ($v0)
/* 103470 7F0CE940 53E0001D */  beql  $ra, $zero, .L7F0CE9B8
/* 103474 7F0CE944 8FAF05FC */   lw    $t7, 0x5fc($sp)
.L7F0CE948:
/* 103478 7F0CE948 8FCF0000 */  lw    $t7, ($fp)
/* 10347C 7F0CE94C 27FFFFFC */  addiu $ra, $ra, -4
/* 103480 7F0CE950 27DE0010 */  addiu $fp, $fp, 0x10
/* 103484 7F0CE954 000FC080 */  sll   $t8, $t7, 2
/* 103488 7F0CE958 02381021 */  addu  $v0, $s1, $t8
/* 10348C 7F0CE95C 8C590000 */  lw    $t9, ($v0)
/* 103490 7F0CE960 272E0001 */  addiu $t6, $t9, 1
/* 103494 7F0CE964 AC4E0000 */  sw    $t6, ($v0)
/* 103498 7F0CE968 8FCFFFF4 */  lw    $t7, -0xc($fp)
/* 10349C 7F0CE96C 000FC080 */  sll   $t8, $t7, 2
/* 1034A0 7F0CE970 02381021 */  addu  $v0, $s1, $t8
/* 1034A4 7F0CE974 8C590000 */  lw    $t9, ($v0)
/* 1034A8 7F0CE978 272E0001 */  addiu $t6, $t9, 1
/* 1034AC 7F0CE97C AC4E0000 */  sw    $t6, ($v0)
/* 1034B0 7F0CE980 8FCFFFF8 */  lw    $t7, -8($fp)
/* 1034B4 7F0CE984 000FC080 */  sll   $t8, $t7, 2
/* 1034B8 7F0CE988 02381021 */  addu  $v0, $s1, $t8
/* 1034BC 7F0CE98C 8C590000 */  lw    $t9, ($v0)
/* 1034C0 7F0CE990 272E0001 */  addiu $t6, $t9, 1
/* 1034C4 7F0CE994 AC4E0000 */  sw    $t6, ($v0)
/* 1034C8 7F0CE998 8FCFFFFC */  lw    $t7, -4($fp)
/* 1034CC 7F0CE99C 000FC080 */  sll   $t8, $t7, 2
/* 1034D0 7F0CE9A0 02381021 */  addu  $v0, $s1, $t8
/* 1034D4 7F0CE9A4 8C590000 */  lw    $t9, ($v0)
/* 1034D8 7F0CE9A8 272E0001 */  addiu $t6, $t9, 1
/* 1034DC 7F0CE9AC 17E0FFE6 */  bnez  $ra, .L7F0CE948
/* 1034E0 7F0CE9B0 AC4E0000 */   sw    $t6, ($v0)
/* 1034E4 7F0CE9B4 8FAF05FC */  lw    $t7, 0x5fc($sp)
.L7F0CE9B8:
/* 1034E8 7F0CE9B8 8FB805B0 */  lw    $t8, 0x5b0($sp)
/* 1034EC 7F0CE9BC 8FA50610 */  lw    $a1, 0x610($sp)
/* 1034F0 7F0CE9C0 27A305B4 */  addiu $v1, $sp, 0x5b4
/* 1034F4 7F0CE9C4 15F80007 */  bne   $t7, $t8, .L7F0CE9E4
/* 1034F8 7F0CE9C8 24020011 */   li    $v0, 17
/* 1034FC 7F0CE9CC 8FB5060C */  lw    $s5, 0x60c($sp)
/* 103500 7F0CE9D0 8FA50610 */  lw    $a1, 0x610($sp)
/* 103504 7F0CE9D4 00001025 */  move  $v0, $zero
/* 103508 7F0CE9D8 AEA00000 */  sw    $zero, ($s5)
/* 10350C 7F0CE9DC 10000138 */  b     .L7F0CEEC0
/* 103510 7F0CE9E0 ACA00000 */   sw    $zero, ($a1)
.L7F0CE9E4:
/* 103514 7F0CE9E4 8CB00000 */  lw    $s0, ($a1)
.L7F0CE9E8:
/* 103518 7F0CE9E8 8C790000 */  lw    $t9, ($v1)
/* 10351C 7F0CE9EC 57200005 */  bnezl $t9, .L7F0CEA04
/* 103520 7F0CE9F0 0207082B */   sltu  $at, $s0, $a3
/* 103524 7F0CE9F4 24E70001 */  addiu $a3, $a3, 1
/* 103528 7F0CE9F8 14E2FFFB */  bne   $a3, $v0, .L7F0CE9E8
/* 10352C 7F0CE9FC 24630004 */   addiu $v1, $v1, 4
/* 103530 7F0CEA00 0207082B */  sltu  $at, $s0, $a3
.L7F0CEA04:
/* 103534 7F0CEA04 10200002 */  beqz  $at, .L7F0CEA10
/* 103538 7F0CEA08 00E0A025 */   move  $s4, $a3
/* 10353C 7F0CEA0C 00E08025 */  move  $s0, $a3
.L7F0CEA10:
/* 103540 7F0CEA10 241F0010 */  li    $ra, 16
/* 103544 7F0CEA14 27A205F0 */  addiu $v0, $sp, 0x5f0
.L7F0CEA18:
/* 103548 7F0CEA18 8C4E0000 */  lw    $t6, ($v0)
/* 10354C 7F0CEA1C 55C00005 */  bnezl $t6, .L7F0CEA34
/* 103550 7F0CEA20 03F0082B */   sltu  $at, $ra, $s0
/* 103554 7F0CEA24 27FFFFFF */  addiu $ra, $ra, -1
/* 103558 7F0CEA28 17E0FFFB */  bnez  $ra, .L7F0CEA18
/* 10355C 7F0CEA2C 2442FFFC */   addiu $v0, $v0, -4
/* 103560 7F0CEA30 03F0082B */  sltu  $at, $ra, $s0
.L7F0CEA34:
/* 103564 7F0CEA34 10200002 */  beqz  $at, .L7F0CEA40
/* 103568 7F0CEA38 AFBF05A8 */   sw    $ra, 0x5a8($sp)
/* 10356C 7F0CEA3C 03E08025 */  move  $s0, $ra
.L7F0CEA40:
/* 103570 7F0CEA40 240F0001 */  li    $t7, 1
/* 103574 7F0CEA44 00FF082B */  sltu  $at, $a3, $ra
/* 103578 7F0CEA48 ACB00000 */  sw    $s0, ($a1)
/* 10357C 7F0CEA4C 1020000B */  beqz  $at, .L7F0CEA7C
/* 103580 7F0CEA50 00EF2004 */   sllv  $a0, $t7, $a3
/* 103584 7F0CEA54 001FC080 */  sll   $t8, $ra, 2
/* 103588 7F0CEA58 27B905B0 */  addiu $t9, $sp, 0x5b0
/* 10358C 7F0CEA5C 03192821 */  addu  $a1, $t8, $t9
.L7F0CEA60:
/* 103590 7F0CEA60 8C6E0000 */  lw    $t6, ($v1)
/* 103594 7F0CEA64 24630004 */  addiu $v1, $v1, 4
/* 103598 7F0CEA68 0065082B */  sltu  $at, $v1, $a1
/* 10359C 7F0CEA6C 008E2023 */  subu  $a0, $a0, $t6
/* 1035A0 7F0CEA70 00047840 */  sll   $t7, $a0, 1
/* 1035A4 7F0CEA74 1420FFFA */  bnez  $at, .L7F0CEA60
/* 1035A8 7F0CEA78 01E02025 */   move  $a0, $t7
.L7F0CEA7C:
/* 1035AC 7F0CEA7C 8C430000 */  lw    $v1, ($v0)
/* 1035B0 7F0CEA80 27FFFFFF */  addiu $ra, $ra, -1
/* 1035B4 7F0CEA84 00003825 */  move  $a3, $zero
/* 1035B8 7F0CEA88 00832023 */  subu  $a0, $a0, $v1
/* 1035BC 7F0CEA8C 0064C021 */  addu  $t8, $v1, $a0
/* 1035C0 7F0CEA90 AC580000 */  sw    $t8, ($v0)
/* 1035C4 7F0CEA94 AFA00080 */  sw    $zero, 0x80($sp)
/* 1035C8 7F0CEA98 27BE05B4 */  addiu $fp, $sp, 0x5b4
/* 1035CC 7F0CEA9C 27A60084 */  addiu $a2, $sp, 0x84
/* 1035D0 7F0CEAA0 13E00022 */  beqz  $ra, .L7F0CEB2C
/* 1035D4 7F0CEAA4 2442FFFC */   addiu $v0, $v0, -4
/* 1035D8 7F0CEAA8 33E80003 */  andi  $t0, $ra, 3
/* 1035DC 7F0CEAAC 00084023 */  negu  $t0, $t0
/* 1035E0 7F0CEAB0 1100000D */  beqz  $t0, .L7F0CEAE8
/* 1035E4 7F0CEAB4 011F1821 */   addu  $v1, $t0, $ra
/* 1035E8 7F0CEAB8 0003C880 */  sll   $t9, $v1, 2
/* 1035EC 7F0CEABC 27AE05B0 */  addiu $t6, $sp, 0x5b0
/* 1035F0 7F0CEAC0 032E2821 */  addu  $a1, $t9, $t6
.L7F0CEAC4:
/* 1035F4 7F0CEAC4 8FCF0000 */  lw    $t7, ($fp)
/* 1035F8 7F0CEAC8 2442FFFC */  addiu $v0, $v0, -4
/* 1035FC 7F0CEACC 24C60004 */  addiu $a2, $a2, 4
/* 103600 7F0CEAD0 00EF3821 */  addu  $a3, $a3, $t7
/* 103604 7F0CEAD4 ACC7FFFC */  sw    $a3, -4($a2)
/* 103608 7F0CEAD8 14A2FFFA */  bne   $a1, $v0, .L7F0CEAC4
/* 10360C 7F0CEADC 27DE0004 */   addiu $fp, $fp, 4
/* 103610 7F0CEAE0 27B805B0 */  addiu $t8, $sp, 0x5b0
/* 103614 7F0CEAE4 10580011 */  beq   $v0, $t8, .L7F0CEB2C
.L7F0CEAE8:
/* 103618 7F0CEAE8 27A305B0 */   addiu $v1, $sp, 0x5b0
.L7F0CEAEC:
/* 10361C 7F0CEAEC 8FD90000 */  lw    $t9, ($fp)
/* 103620 7F0CEAF0 2442FFF0 */  addiu $v0, $v0, -0x10
/* 103624 7F0CEAF4 24C60010 */  addiu $a2, $a2, 0x10
/* 103628 7F0CEAF8 00F93821 */  addu  $a3, $a3, $t9
/* 10362C 7F0CEAFC ACC7FFF0 */  sw    $a3, -0x10($a2)
/* 103630 7F0CEB00 8FCE0004 */  lw    $t6, 4($fp)
/* 103634 7F0CEB04 27DE0010 */  addiu $fp, $fp, 0x10
/* 103638 7F0CEB08 00EE3821 */  addu  $a3, $a3, $t6
/* 10363C 7F0CEB0C ACC7FFF4 */  sw    $a3, -0xc($a2)
/* 103640 7F0CEB10 8FCFFFF8 */  lw    $t7, -8($fp)
/* 103644 7F0CEB14 00EF3821 */  addu  $a3, $a3, $t7
/* 103648 7F0CEB18 ACC7FFF8 */  sw    $a3, -8($a2)
/* 10364C 7F0CEB1C 8FD8FFFC */  lw    $t8, -4($fp)
/* 103650 7F0CEB20 00F83821 */  addu  $a3, $a3, $t8
/* 103654 7F0CEB24 1443FFF1 */  bne   $v0, $v1, .L7F0CEAEC
/* 103658 7F0CEB28 ACC7FFFC */   sw    $a3, -4($a2)
.L7F0CEB2C:
/* 10365C 7F0CEB2C 0240F025 */  move  $fp, $s2
/* 103660 7F0CEB30 0000F825 */  move  $ra, $zero
/* 103664 7F0CEB34 27A6007C */  addiu $a2, $sp, 0x7c
/* 103668 7F0CEB38 27A500C4 */  addiu $a1, $sp, 0xc4
/* 10366C 7F0CEB3C 8FC70000 */  lw    $a3, ($fp)
.L7F0CEB40:
/* 103670 7F0CEB40 27DE0004 */  addiu $fp, $fp, 4
/* 103674 7F0CEB44 10E00008 */  beqz  $a3, .L7F0CEB68
/* 103678 7F0CEB48 0007C880 */   sll   $t9, $a3, 2
/* 10367C 7F0CEB4C 00D91021 */  addu  $v0, $a2, $t9
/* 103680 7F0CEB50 8C430000 */  lw    $v1, ($v0)
/* 103684 7F0CEB54 00037080 */  sll   $t6, $v1, 2
/* 103688 7F0CEB58 00AE7821 */  addu  $t7, $a1, $t6
/* 10368C 7F0CEB5C ADFF0000 */  sw    $ra, ($t7)
/* 103690 7F0CEB60 24780001 */  addiu $t8, $v1, 1
/* 103694 7F0CEB64 AC580000 */  sw    $t8, ($v0)
.L7F0CEB68:
/* 103698 7F0CEB68 8FB905FC */  lw    $t9, 0x5fc($sp)
/* 10369C 7F0CEB6C 27FF0001 */  addiu $ra, $ra, 1
/* 1036A0 7F0CEB70 03F9082B */  sltu  $at, $ra, $t9
/* 1036A4 7F0CEB74 5420FFF2 */  bnezl $at, .L7F0CEB40
/* 1036A8 7F0CEB78 8FC70000 */   lw    $a3, ($fp)
/* 1036AC 7F0CEB7C 8FAE05A8 */  lw    $t6, 0x5a8($sp)
/* 1036B0 7F0CEB80 AFA40074 */  sw    $a0, 0x74($sp)
/* 1036B4 7F0CEB84 0000F825 */  move  $ra, $zero
/* 1036B8 7F0CEB88 01D4082A */  slt   $at, $t6, $s4
/* 1036BC 7F0CEB8C AFA0007C */  sw    $zero, 0x7c($sp)
/* 1036C0 7F0CEB90 00A0F025 */  move  $fp, $a1
/* 1036C4 7F0CEB94 240CFFFF */  li    $t4, -1
/* 1036C8 7F0CEB98 00105023 */  negu  $t2, $s0
/* 1036CC 7F0CEB9C AFA00544 */  sw    $zero, 0x544($sp)
/* 1036D0 7F0CEBA0 00003025 */  move  $a2, $zero
/* 1036D4 7F0CEBA4 142000BF */  bnez  $at, .L7F0CEEA4
/* 1036D8 7F0CEBA8 00004025 */   move  $t0, $zero
/* 1036DC 7F0CEBAC 00147880 */  sll   $t7, $s4, 2
/* 1036E0 7F0CEBB0 27B805B0 */  addiu $t8, $sp, 0x5b0
/* 1036E4 7F0CEBB4 01F8C821 */  addu  $t9, $t7, $t8
/* 1036E8 7F0CEBB8 3C178009 */  lui   $s7, %hi(dword_CODE_bss_8008D360) 
/* 1036EC 7F0CEBBC 3C128009 */  lui   $s2, %hi(dword_CODE_bss_8008D36C)
/* 1036F0 7F0CEBC0 2652D36C */  addiu $s2, %lo(dword_CODE_bss_8008D36C) # addiu $s2, $s2, -0x2c94
/* 1036F4 7F0CEBC4 26F7D360 */  addiu $s7, %lo(dword_CODE_bss_8008D360) # addiu $s7, $s7, -0x2ca0
/* 1036F8 7F0CEBC8 AFB9005C */  sw    $t9, 0x5c($sp)
/* 1036FC 7F0CEBCC 8FB5060C */  lw    $s5, 0x60c($sp)
/* 103700 7F0CEBD0 27B30584 */  addiu $s3, $sp, 0x584
.L7F0CEBD4:
/* 103704 7F0CEBD4 8FAE005C */  lw    $t6, 0x5c($sp)
/* 103708 7F0CEBD8 8FB805FC */  lw    $t8, 0x5fc($sp)
/* 10370C 7F0CEBDC 000C6880 */  sll   $t5, $t4, 2
/* 103710 7F0CEBE0 8DD60000 */  lw    $s6, ($t6)
/* 103714 7F0CEBE4 27AF007C */  addiu $t7, $sp, 0x7c
/* 103718 7F0CEBE8 0018C880 */  sll   $t9, $t8, 2
/* 10371C 7F0CEBEC 02C02825 */  move  $a1, $s6
/* 103720 7F0CEBF0 12C000A4 */  beqz  $s6, .L7F0CEE84
/* 103724 7F0CEBF4 26D6FFFF */   addiu $s6, $s6, -1
/* 103728 7F0CEBF8 01AF5821 */  addu  $t3, $t5, $t7
/* 10372C 7F0CEBFC 27AE00C4 */  addiu $t6, $sp, 0xc4
/* 103730 7F0CEC00 032E7821 */  addu  $t7, $t9, $t6
/* 103734 7F0CEC04 24190001 */  li    $t9, 1
/* 103738 7F0CEC08 2698001F */  addiu $t8, $s4, 0x1f
/* 10373C 7F0CEC0C 03197004 */  sllv  $t6, $t9, $t8
/* 103740 7F0CEC10 AFAE0040 */  sw    $t6, 0x40($sp)
/* 103744 7F0CEC14 AFAF0044 */  sw    $t7, 0x44($sp)
.L7F0CEC18:
/* 103748 7F0CEC18 01501821 */  addu  $v1, $t2, $s0
/* 10374C 7F0CEC1C 0074082A */  slt   $at, $v1, $s4
/* 103750 7F0CEC20 10200047 */  beqz  $at, .L7F0CED40
/* 103754 7F0CEC24 26D10001 */   addiu $s1, $s6, 1
/* 103758 7F0CEC28 27AF0544 */  addiu $t7, $sp, 0x544
/* 10375C 7F0CEC2C 01AF4821 */  addu  $t1, $t5, $t7
/* 103760 7F0CEC30 8FB905A8 */  lw    $t9, 0x5a8($sp)
.L7F0CEC34:
/* 103764 7F0CEC34 258C0001 */  addiu $t4, $t4, 1
/* 103768 7F0CEC38 25AD0004 */  addiu $t5, $t5, 4
/* 10376C 7F0CEC3C 03234023 */  subu  $t0, $t9, $v1
/* 103770 7F0CEC40 0208082B */  sltu  $at, $s0, $t0
/* 103774 7F0CEC44 25290004 */  addiu $t1, $t1, 4
/* 103778 7F0CEC48 256B0004 */  addiu $t3, $t3, 4
/* 10377C 7F0CEC4C 10200002 */  beqz  $at, .L7F0CEC58
/* 103780 7F0CEC50 00605025 */   move  $t2, $v1
/* 103784 7F0CEC54 02004025 */  move  $t0, $s0
.L7F0CEC58:
/* 103788 7F0CEC58 028A1023 */  subu  $v0, $s4, $t2
/* 10378C 7F0CEC5C 24180001 */  li    $t8, 1
/* 103790 7F0CEC60 00582004 */  sllv  $a0, $t8, $v0
/* 103794 7F0CEC64 0224082B */  sltu  $at, $s1, $a0
/* 103798 7F0CEC68 10200013 */  beqz  $at, .L7F0CECB8
/* 10379C 7F0CEC6C 00403825 */   move  $a3, $v0
/* 1037A0 7F0CEC70 24470001 */  addiu $a3, $v0, 1
/* 1037A4 7F0CEC74 00961823 */  subu  $v1, $a0, $s6
/* 1037A8 7F0CEC78 00147080 */  sll   $t6, $s4, 2
/* 1037AC 7F0CEC7C 27AF05B0 */  addiu $t7, $sp, 0x5b0
/* 1037B0 7F0CEC80 00E8082B */  sltu  $at, $a3, $t0
/* 1037B4 7F0CEC84 2463FFFF */  addiu $v1, $v1, -1
/* 1037B8 7F0CEC88 1020000B */  beqz  $at, .L7F0CECB8
/* 1037BC 7F0CEC8C 01CF3021 */   addu  $a2, $t6, $t7
.L7F0CEC90:
/* 1037C0 7F0CEC90 8CC40004 */  lw    $a0, 4($a2)
/* 1037C4 7F0CEC94 00031040 */  sll   $v0, $v1, 1
/* 1037C8 7F0CEC98 24C60004 */  addiu $a2, $a2, 4
/* 1037CC 7F0CEC9C 0082082B */  sltu  $at, $a0, $v0
/* 1037D0 7F0CECA0 50200006 */  beql  $at, $zero, .L7F0CECBC
/* 1037D4 7F0CECA4 8E430000 */   lw    $v1, ($s2)
/* 1037D8 7F0CECA8 24E70001 */  addiu $a3, $a3, 1
/* 1037DC 7F0CECAC 00E8082B */  sltu  $at, $a3, $t0
/* 1037E0 7F0CECB0 1420FFF7 */  bnez  $at, .L7F0CEC90
/* 1037E4 7F0CECB4 00441823 */   subu  $v1, $v0, $a0
.L7F0CECB8:
/* 1037E8 7F0CECB8 8E430000 */  lw    $v1, ($s2)
.L7F0CECBC:
/* 1037EC 7F0CECBC 8EEE0000 */  lw    $t6, ($s7)
/* 1037F0 7F0CECC0 24190001 */  li    $t9, 1
/* 1037F4 7F0CECC4 00F94004 */  sllv  $t0, $t9, $a3
/* 1037F8 7F0CECC8 0003C0C0 */  sll   $t8, $v1, 3
/* 1037FC 7F0CECCC 00687821 */  addu  $t7, $v1, $t0
/* 103800 7F0CECD0 25F90001 */  addiu $t9, $t7, 1
/* 103804 7F0CECD4 030E3021 */  addu  $a2, $t8, $t6
/* 103808 7F0CECD8 AE590000 */  sw    $t9, ($s2)
/* 10380C 7F0CECDC 24C40008 */  addiu $a0, $a2, 8
/* 103810 7F0CECE0 AEA40000 */  sw    $a0, ($s5)
/* 103814 7F0CECE4 ACC00004 */  sw    $zero, 4($a2)
/* 103818 7F0CECE8 24D50004 */  addiu $s5, $a2, 4
/* 10381C 7F0CECEC 00803025 */  move  $a2, $a0
/* 103820 7F0CECF0 1180000F */  beqz  $t4, .L7F0CED30
/* 103824 7F0CECF4 AD240000 */   sw    $a0, ($t1)
/* 103828 7F0CECF8 AD7F0000 */  sw    $ra, ($t3)
/* 10382C 7F0CECFC 24F80010 */  addiu $t8, $a3, 0x10
/* 103830 7F0CED00 A3B00585 */  sb    $s0, 0x585($sp)
/* 103834 7F0CED04 A3B80584 */  sb    $t8, 0x584($sp)
/* 103838 7F0CED08 AFA40588 */  sw    $a0, 0x588($sp)
/* 10383C 7F0CED0C 8D2EFFFC */  lw    $t6, -4($t1)
/* 103840 7F0CED10 01507823 */  subu  $t7, $t2, $s0
/* 103844 7F0CED14 8E610000 */  lw    $at, ($s3)
/* 103848 7F0CED18 01FFC806 */  srlv  $t9, $ra, $t7
/* 10384C 7F0CED1C 0019C0C0 */  sll   $t8, $t9, 3
/* 103850 7F0CED20 01D87821 */  addu  $t7, $t6, $t8
/* 103854 7F0CED24 ADE10000 */  sw    $at, ($t7)
/* 103858 7F0CED28 8E780004 */  lw    $t8, 4($s3)
/* 10385C 7F0CED2C ADF80004 */  sw    $t8, 4($t7)
.L7F0CED30:
/* 103860 7F0CED30 01501821 */  addu  $v1, $t2, $s0
/* 103864 7F0CED34 0074082A */  slt   $at, $v1, $s4
/* 103868 7F0CED38 5420FFBE */  bnezl $at, .L7F0CEC34
/* 10386C 7F0CED3C 8FB905A8 */   lw    $t9, 0x5a8($sp)
.L7F0CED40:
/* 103870 7F0CED40 8FB90044 */  lw    $t9, 0x44($sp)
/* 103874 7F0CED44 240E0001 */  li    $t6, 1
/* 103878 7F0CED48 028A1823 */  subu  $v1, $s4, $t2
/* 10387C 7F0CED4C 014E2804 */  sllv  $a1, $t6, $t2
/* 103880 7F0CED50 03D9082B */  sltu  $at, $fp, $t9
/* 103884 7F0CED54 A3A30585 */  sb    $v1, 0x585($sp)
/* 103888 7F0CED58 14200004 */  bnez  $at, .L7F0CED6C
/* 10388C 7F0CED5C 24A5FFFF */   addiu $a1, $a1, -1
/* 103890 7F0CED60 240F0063 */  li    $t7, 99
/* 103894 7F0CED64 10000020 */  b     .L7F0CEDE8
/* 103898 7F0CED68 A3AF0584 */   sb    $t7, 0x584($sp)
.L7F0CED6C:
/* 10389C 7F0CED6C 8FC20000 */  lw    $v0, ($fp)
/* 1038A0 7F0CED70 8FB80600 */  lw    $t8, 0x600($sp)
/* 1038A4 7F0CED74 8FA40600 */  lw    $a0, 0x600($sp)
/* 1038A8 7F0CED78 8FAE0608 */  lw    $t6, 0x608($sp)
/* 1038AC 7F0CED7C 0058082B */  sltu  $at, $v0, $t8
/* 1038B0 7F0CED80 1020000B */  beqz  $at, .L7F0CEDB0
/* 1038B4 7F0CED84 2C410100 */   sltiu $at, $v0, 0x100
/* 1038B8 7F0CED88 10200004 */  beqz  $at, .L7F0CED9C
/* 1038BC 7F0CED8C 2419000F */   li    $t9, 15
/* 1038C0 7F0CED90 240E0010 */  li    $t6, 16
/* 1038C4 7F0CED94 10000002 */  b     .L7F0CEDA0
/* 1038C8 7F0CED98 A3AE0584 */   sb    $t6, 0x584($sp)
.L7F0CED9C:
/* 1038CC 7F0CED9C A3B90584 */  sb    $t9, 0x584($sp)
.L7F0CEDA0:
/* 1038D0 7F0CEDA0 8FCF0000 */  lw    $t7, ($fp)
/* 1038D4 7F0CEDA4 27DE0004 */  addiu $fp, $fp, 4
/* 1038D8 7F0CEDA8 1000000F */  b     .L7F0CEDE8
/* 1038DC 7F0CEDAC A7AF0588 */   sh    $t7, 0x588($sp)
.L7F0CEDB0:
/* 1038E0 7F0CEDB0 0044C023 */  subu  $t8, $v0, $a0
/* 1038E4 7F0CEDB4 030EC821 */  addu  $t9, $t8, $t6
/* 1038E8 7F0CEDB8 932F0000 */  lbu   $t7, ($t9)
/* 1038EC 7F0CEDBC 8FB80604 */  lw    $t8, 0x604($sp)
/* 1038F0 7F0CEDC0 27DE0004 */  addiu $fp, $fp, 4
/* 1038F4 7F0CEDC4 A3AF0584 */  sb    $t7, 0x584($sp)
/* 1038F8 7F0CEDC8 8FCEFFFC */  lw    $t6, -4($fp)
/* 1038FC 7F0CEDCC 000EC840 */  sll   $t9, $t6, 1
/* 103900 7F0CEDD0 00047040 */  sll   $t6, $a0, 1
/* 103904 7F0CEDD4 03197821 */  addu  $t7, $t8, $t9
/* 103908 7F0CEDD8 000EC023 */  negu  $t8, $t6
/* 10390C 7F0CEDDC 01F8C821 */  addu  $t9, $t7, $t8
/* 103910 7F0CEDE0 972E0000 */  lhu   $t6, ($t9)
/* 103914 7F0CEDE4 A7AE0588 */  sh    $t6, 0x588($sp)
.L7F0CEDE8:
/* 103918 7F0CEDE8 015F3806 */  srlv  $a3, $ra, $t2
/* 10391C 7F0CEDEC 00E8082B */  sltu  $at, $a3, $t0
/* 103920 7F0CEDF0 1020000B */  beqz  $at, .L7F0CEE20
/* 103924 7F0CEDF4 240F0001 */   li    $t7, 1
/* 103928 7F0CEDF8 006F1004 */  sllv  $v0, $t7, $v1
.L7F0CEDFC:
/* 10392C 7F0CEDFC 8E610000 */  lw    $at, ($s3)
/* 103930 7F0CEE00 0007C0C0 */  sll   $t8, $a3, 3
/* 103934 7F0CEE04 00D8C821 */  addu  $t9, $a2, $t8
/* 103938 7F0CEE08 AF210000 */  sw    $at, ($t9)
/* 10393C 7F0CEE0C 8E6F0004 */  lw    $t7, 4($s3)
/* 103940 7F0CEE10 00E23821 */  addu  $a3, $a3, $v0
/* 103944 7F0CEE14 00E8082B */  sltu  $at, $a3, $t0
/* 103948 7F0CEE18 1420FFF8 */  bnez  $at, .L7F0CEDFC
/* 10394C 7F0CEE1C AF2F0004 */   sw    $t7, 4($t9)
.L7F0CEE20:
/* 103950 7F0CEE20 8FA70040 */  lw    $a3, 0x40($sp)
/* 103954 7F0CEE24 8D620000 */  lw    $v0, ($t3)
/* 103958 7F0CEE28 03E7C024 */  and   $t8, $ra, $a3
/* 10395C 7F0CEE2C 13000005 */  beqz  $t8, .L7F0CEE44
.L7F0CEE30:
/* 103960 7F0CEE30 00077042 */   srl   $t6, $a3, 1
/* 103964 7F0CEE34 03E7F826 */  xor   $ra, $ra, $a3
/* 103968 7F0CEE38 03EEC824 */  and   $t9, $ra, $t6
/* 10396C 7F0CEE3C 1720FFFC */  bnez  $t9, .L7F0CEE30
/* 103970 7F0CEE40 01C03825 */   move  $a3, $t6
.L7F0CEE44:
/* 103974 7F0CEE44 03E7F826 */  xor   $ra, $ra, $a3
/* 103978 7F0CEE48 03E57824 */  and   $t7, $ra, $a1
/* 10397C 7F0CEE4C 11E2000B */  beq   $t7, $v0, .L7F0CEE7C
/* 103980 7F0CEE50 02C02825 */   move  $a1, $s6
.L7F0CEE54:
/* 103984 7F0CEE54 01505023 */  subu  $t2, $t2, $s0
/* 103988 7F0CEE58 24180001 */  li    $t8, 1
/* 10398C 7F0CEE5C 01587004 */  sllv  $t6, $t8, $t2
/* 103990 7F0CEE60 8D78FFFC */  lw    $t8, -4($t3)
/* 103994 7F0CEE64 25D9FFFF */  addiu $t9, $t6, -1
/* 103998 7F0CEE68 03F97824 */  and   $t7, $ra, $t9
/* 10399C 7F0CEE6C 258CFFFF */  addiu $t4, $t4, -1
/* 1039A0 7F0CEE70 25ADFFFC */  addiu $t5, $t5, -4
/* 1039A4 7F0CEE74 15F8FFF7 */  bne   $t7, $t8, .L7F0CEE54
/* 1039A8 7F0CEE78 256BFFFC */   addiu $t3, $t3, -4
.L7F0CEE7C:
/* 1039AC 7F0CEE7C 16C0FF66 */  bnez  $s6, .L7F0CEC18
/* 1039B0 7F0CEE80 26D6FFFF */   addiu $s6, $s6, -1
.L7F0CEE84:
/* 1039B4 7F0CEE84 8FAE005C */  lw    $t6, 0x5c($sp)
/* 1039B8 7F0CEE88 8FAF05A8 */  lw    $t7, 0x5a8($sp)
/* 1039BC 7F0CEE8C 26940001 */  addiu $s4, $s4, 1
/* 1039C0 7F0CEE90 25D90004 */  addiu $t9, $t6, 4
/* 1039C4 7F0CEE94 01F4082A */  slt   $at, $t7, $s4
/* 1039C8 7F0CEE98 1020FF4E */  beqz  $at, .L7F0CEBD4
/* 1039CC 7F0CEE9C AFB9005C */   sw    $t9, 0x5c($sp)
/* 1039D0 7F0CEEA0 AFB5060C */  sw    $s5, 0x60c($sp)
.L7F0CEEA4:
/* 1039D4 7F0CEEA4 8FA20074 */  lw    $v0, 0x74($sp)
/* 1039D8 7F0CEEA8 0002C02B */  sltu  $t8, $zero, $v0
/* 1039DC 7F0CEEAC 13000004 */  beqz  $t8, .L7F0CEEC0
/* 1039E0 7F0CEEB0 03001025 */   move  $v0, $t8
/* 1039E4 7F0CEEB4 8FA205A8 */  lw    $v0, 0x5a8($sp)
/* 1039E8 7F0CEEB8 384E0001 */  xori  $t6, $v0, 1
/* 1039EC 7F0CEEBC 000E102B */  sltu  $v0, $zero, $t6
.L7F0CEEC0:
/* 1039F0 7F0CEEC0 8FBF003C */  lw    $ra, 0x3c($sp)
/* 1039F4 7F0CEEC4 8FB00018 */  lw    $s0, 0x18($sp)
/* 1039F8 7F0CEEC8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1039FC 7F0CEECC 8FB20020 */  lw    $s2, 0x20($sp)
/* 103A00 7F0CEED0 8FB30024 */  lw    $s3, 0x24($sp)
/* 103A04 7F0CEED4 8FB40028 */  lw    $s4, 0x28($sp)
/* 103A08 7F0CEED8 8FB5002C */  lw    $s5, 0x2c($sp)
/* 103A0C 7F0CEEDC 8FB60030 */  lw    $s6, 0x30($sp)
/* 103A10 7F0CEEE0 8FB70034 */  lw    $s7, 0x34($sp)
/* 103A14 7F0CEEE4 8FBE0038 */  lw    $fp, 0x38($sp)
/* 103A18 7F0CEEE8 03E00008 */  jr    $ra
/* 103A1C 7F0CEEEC 27BD05F8 */   addiu $sp, $sp, 0x5f8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F0CEEF0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0CEEF0
/* 103A20 7F0CEEF0 27BDFF90 */  addiu $sp, $sp, -0x70
/* 103A24 7F0CEEF4 3C098005 */  lui   $t1, %hi(D_8004E9B0) 
/* 103A28 7F0CEEF8 2529E9B0 */  addiu $t1, %lo(D_8004E9B0) # addiu $t1, $t1, -0x1650
/* 103A2C 7F0CEEFC AFBE0038 */  sw    $fp, 0x38($sp)
/* 103A30 7F0CEF00 AFB70034 */  sw    $s7, 0x34($sp)
/* 103A34 7F0CEF04 AFB5002C */  sw    $s5, 0x2c($sp)
/* 103A38 7F0CEF08 AFB40028 */  sw    $s4, 0x28($sp)
/* 103A3C 7F0CEF0C AFB30024 */  sw    $s3, 0x24($sp)
/* 103A40 7F0CEF10 AFB1001C */  sw    $s1, 0x1c($sp)
/* 103A44 7F0CEF14 00067840 */  sll   $t7, $a2, 1
/* 103A48 7F0CEF18 0007C840 */  sll   $t9, $a3, 1
/* 103A4C 7F0CEF1C AFBF003C */  sw    $ra, 0x3c($sp)
/* 103A50 7F0CEF20 AFA7007C */  sw    $a3, 0x7c($sp)
/* 103A54 7F0CEF24 3C148009 */  lui   $s4, %hi(dword_CODE_bss_8008D364)
/* 103A58 7F0CEF28 3C118009 */  lui   $s1, %hi(dword_CODE_bss_8008D368)
/* 103A5C 7F0CEF2C 3C158009 */  lui   $s5, %hi(dword_CODE_bss_8008D35C)
/* 103A60 7F0CEF30 012F6021 */  addu  $t4, $t1, $t7
/* 103A64 7F0CEF34 01396821 */  addu  $t5, $t1, $t9
/* 103A68 7F0CEF38 3C138009 */  lui   $s3, %hi(dword_CODE_bss_8008D358)
/* 103A6C 7F0CEF3C 3C178009 */  lui   $s7, %hi(dword_CODE_bss_8008D354) 
/* 103A70 7F0CEF40 3C1E8009 */  lui   $fp, %hi(dword_CODE_bss_8008D350) 
/* 103A74 7F0CEF44 AFB60030 */  sw    $s6, 0x30($sp)
/* 103A78 7F0CEF48 AFB20020 */  sw    $s2, 0x20($sp)
/* 103A7C 7F0CEF4C AFB00018 */  sw    $s0, 0x18($sp)
/* 103A80 7F0CEF50 AFA40070 */  sw    $a0, 0x70($sp)
/* 103A84 7F0CEF54 AFA50074 */  sw    $a1, 0x74($sp)
/* 103A88 7F0CEF58 AFA60078 */  sw    $a2, 0x78($sp)
/* 103A8C 7F0CEF5C 8E94D364 */  lw    $s4, %lo(dword_CODE_bss_8008D364)($s4)
/* 103A90 7F0CEF60 8E31D368 */  lw    $s1, %lo(dword_CODE_bss_8008D368)($s1)
/* 103A94 7F0CEF64 8EB5D35C */  lw    $s5, %lo(dword_CODE_bss_8008D35C)($s5)
/* 103A98 7F0CEF68 958A0000 */  lhu   $t2, ($t4)
/* 103A9C 7F0CEF6C 95AB0000 */  lhu   $t3, ($t5)
/* 103AA0 7F0CEF70 27DED350 */  addiu $fp, %lo(dword_CODE_bss_8008D350) # addiu $fp, $fp, -0x2cb0
/* 103AA4 7F0CEF74 26F7D354 */  addiu $s7, %lo(dword_CODE_bss_8008D354) # addiu $s7, $s7, -0x2cac
/* 103AA8 7F0CEF78 2673D358 */  addiu $s3, %lo(dword_CODE_bss_8008D358) # addiu $s3, $s3, -0x2ca8
/* 103AAC 7F0CEF7C 34078000 */  li    $a3, 32768
/* 103AB0 7F0CEF80 00C0F825 */  move  $ra, $a2
.L7F0CEF84:
/* 103AB4 7F0CEF84 023F082B */  sltu  $at, $s1, $ra
.L7F0CEF88:
/* 103AB8 7F0CEF88 5020000D */  beql  $at, $zero, .L7F0CEFC0
/* 103ABC 7F0CEF8C 8FB90070 */   lw    $t9, 0x70($sp)
/* 103AC0 7F0CEF90 8FC30000 */  lw    $v1, ($fp)
.L7F0CEF94:
/* 103AC4 7F0CEF94 8E620000 */  lw    $v0, ($s3)
/* 103AC8 7F0CEF98 00627821 */  addu  $t7, $v1, $v0
/* 103ACC 7F0CEF9C 91F80000 */  lbu   $t8, ($t7)
/* 103AD0 7F0CEFA0 244E0001 */  addiu $t6, $v0, 1
/* 103AD4 7F0CEFA4 AE6E0000 */  sw    $t6, ($s3)
/* 103AD8 7F0CEFA8 0238C804 */  sllv  $t9, $t8, $s1
/* 103ADC 7F0CEFAC 26310008 */  addiu $s1, $s1, 8
/* 103AE0 7F0CEFB0 023F082B */  sltu  $at, $s1, $ra
/* 103AE4 7F0CEFB4 1420FFF7 */  bnez  $at, .L7F0CEF94
/* 103AE8 7F0CEFB8 0299A025 */   or    $s4, $s4, $t9
/* 103AEC 7F0CEFBC 8FB90070 */  lw    $t9, 0x70($sp)
.L7F0CEFC0:
/* 103AF0 7F0CEFC0 028A7824 */  and   $t7, $s4, $t2
/* 103AF4 7F0CEFC4 000FC0C0 */  sll   $t8, $t7, 3
/* 103AF8 7F0CEFC8 03193021 */  addu  $a2, $t8, $t9
/* 103AFC 7F0CEFCC 90D20000 */  lbu   $s2, ($a2)
/* 103B00 7F0CEFD0 2E410011 */  sltiu $at, $s2, 0x11
/* 103B04 7F0CEFD4 5420001E */  bnezl $at, .L7F0CF050
/* 103B08 7F0CEFD8 90C20001 */   lbu   $v0, 1($a2)
/* 103B0C 7F0CEFDC 90C20001 */  lbu   $v0, 1($a2)
.L7F0CEFE0:
/* 103B10 7F0CEFE0 2652FFF0 */  addiu $s2, $s2, -0x10
/* 103B14 7F0CEFE4 02228823 */  subu  $s1, $s1, $v0
/* 103B18 7F0CEFE8 0232082B */  sltu  $at, $s1, $s2
/* 103B1C 7F0CEFEC 1020000C */  beqz  $at, .L7F0CF020
/* 103B20 7F0CEFF0 0054A006 */   srlv  $s4, $s4, $v0
/* 103B24 7F0CEFF4 8FC30000 */  lw    $v1, ($fp)
.L7F0CEFF8:
/* 103B28 7F0CEFF8 8E620000 */  lw    $v0, ($s3)
/* 103B2C 7F0CEFFC 00627021 */  addu  $t6, $v1, $v0
/* 103B30 7F0CF000 91CF0000 */  lbu   $t7, ($t6)
/* 103B34 7F0CF004 24590001 */  addiu $t9, $v0, 1
/* 103B38 7F0CF008 AE790000 */  sw    $t9, ($s3)
/* 103B3C 7F0CF00C 022FC004 */  sllv  $t8, $t7, $s1
/* 103B40 7F0CF010 26310008 */  addiu $s1, $s1, 8
/* 103B44 7F0CF014 0232082B */  sltu  $at, $s1, $s2
/* 103B48 7F0CF018 1420FFF7 */  bnez  $at, .L7F0CEFF8
/* 103B4C 7F0CF01C 0298A025 */   or    $s4, $s4, $t8
.L7F0CF020:
/* 103B50 7F0CF020 00127040 */  sll   $t6, $s2, 1
/* 103B54 7F0CF024 012E7821 */  addu  $t7, $t1, $t6
/* 103B58 7F0CF028 95F80000 */  lhu   $t8, ($t7)
/* 103B5C 7F0CF02C 8CCF0004 */  lw    $t7, 4($a2)
/* 103B60 7F0CF030 0314C824 */  and   $t9, $t8, $s4
/* 103B64 7F0CF034 001970C0 */  sll   $t6, $t9, 3
/* 103B68 7F0CF038 01CF3021 */  addu  $a2, $t6, $t7
/* 103B6C 7F0CF03C 90D20000 */  lbu   $s2, ($a2)
/* 103B70 7F0CF040 2E410011 */  sltiu $at, $s2, 0x11
/* 103B74 7F0CF044 5020FFE6 */  beql  $at, $zero, .L7F0CEFE0
/* 103B78 7F0CF048 90C20001 */   lbu   $v0, 1($a2)
/* 103B7C 7F0CF04C 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF050:
/* 103B80 7F0CF050 24010010 */  li    $at, 16
/* 103B84 7F0CF054 0054A006 */  srlv  $s4, $s4, $v0
/* 103B88 7F0CF058 16410013 */  bne   $s2, $at, .L7F0CF0A8
/* 103B8C 7F0CF05C 02228823 */   subu  $s1, $s1, $v0
/* 103B90 7F0CF060 8EF80000 */  lw    $t8, ($s7)
/* 103B94 7F0CF064 8FD90000 */  lw    $t9, ($fp)
/* 103B98 7F0CF068 8E6E0000 */  lw    $t6, ($s3)
/* 103B9C 7F0CF06C 03152821 */  addu  $a1, $t8, $s5
/* 103BA0 7F0CF070 00A01025 */  move  $v0, $a1
/* 103BA4 7F0CF074 032E2021 */  addu  $a0, $t9, $t6
/* 103BA8 7F0CF078 00A4082B */  sltu  $at, $a1, $a0
/* 103BAC 7F0CF07C 14200006 */  bnez  $at, .L7F0CF098
/* 103BB0 7F0CF080 00447823 */   subu  $t7, $v0, $a0
/* 103BB4 7F0CF084 01E7082B */  sltu  $at, $t7, $a3
/* 103BB8 7F0CF088 50200004 */  beql  $at, $zero, .L7F0CF09C
/* 103BBC 7F0CF08C 94D80004 */   lhu   $t8, 4($a2)
.L7F0CF090:
/* 103BC0 7F0CF090 1000FFFF */  b     .L7F0CF090
/* 103BC4 7F0CF094 00000000 */   nop   
.L7F0CF098:
/* 103BC8 7F0CF098 94D80004 */  lhu   $t8, 4($a2)
.L7F0CF09C:
/* 103BCC 7F0CF09C 26B50001 */  addiu $s5, $s5, 1
/* 103BD0 7F0CF0A0 1000FFB8 */  b     .L7F0CEF84
/* 103BD4 7F0CF0A4 A0B80000 */   sb    $t8, ($a1)
.L7F0CF0A8:
/* 103BD8 7F0CF0A8 2401000F */  li    $at, 15
/* 103BDC 7F0CF0AC 124100A4 */  beq   $s2, $at, .L7F0CF340
/* 103BE0 7F0CF0B0 0232082B */   sltu  $at, $s1, $s2
/* 103BE4 7F0CF0B4 5020000D */  beql  $at, $zero, .L7F0CF0EC
/* 103BE8 7F0CF0B8 0012C840 */   sll   $t9, $s2, 1
/* 103BEC 7F0CF0BC 8FC30000 */  lw    $v1, ($fp)
.L7F0CF0C0:
/* 103BF0 7F0CF0C0 8E620000 */  lw    $v0, ($s3)
/* 103BF4 7F0CF0C4 0062C821 */  addu  $t9, $v1, $v0
/* 103BF8 7F0CF0C8 932E0000 */  lbu   $t6, ($t9)
/* 103BFC 7F0CF0CC 24580001 */  addiu $t8, $v0, 1
/* 103C00 7F0CF0D0 AE780000 */  sw    $t8, ($s3)
/* 103C04 7F0CF0D4 022E7804 */  sllv  $t7, $t6, $s1
/* 103C08 7F0CF0D8 26310008 */  addiu $s1, $s1, 8
/* 103C0C 7F0CF0DC 0232082B */  sltu  $at, $s1, $s2
/* 103C10 7F0CF0E0 1420FFF7 */  bnez  $at, .L7F0CF0C0
/* 103C14 7F0CF0E4 028FA025 */   or    $s4, $s4, $t7
/* 103C18 7F0CF0E8 0012C840 */  sll   $t9, $s2, 1
.L7F0CF0EC:
/* 103C1C 7F0CF0EC 01397021 */  addu  $t6, $t1, $t9
/* 103C20 7F0CF0F0 95CF0000 */  lhu   $t7, ($t6)
/* 103C24 7F0CF0F4 8FAE007C */  lw    $t6, 0x7c($sp)
/* 103C28 7F0CF0F8 94D90004 */  lhu   $t9, 4($a2)
/* 103C2C 7F0CF0FC 02328823 */  subu  $s1, $s1, $s2
/* 103C30 7F0CF100 01F4C024 */  and   $t8, $t7, $s4
/* 103C34 7F0CF104 022E082B */  sltu  $at, $s1, $t6
/* 103C38 7F0CF108 0254A006 */  srlv  $s4, $s4, $s2
/* 103C3C 7F0CF10C 1020000D */  beqz  $at, .L7F0CF144
/* 103C40 7F0CF110 03194021 */   addu  $t0, $t8, $t9
/* 103C44 7F0CF114 8FC30000 */  lw    $v1, ($fp)
/* 103C48 7F0CF118 01C02025 */  move  $a0, $t6
.L7F0CF11C:
/* 103C4C 7F0CF11C 8E620000 */  lw    $v0, ($s3)
/* 103C50 7F0CF120 00627821 */  addu  $t7, $v1, $v0
/* 103C54 7F0CF124 91F80000 */  lbu   $t8, ($t7)
/* 103C58 7F0CF128 244E0001 */  addiu $t6, $v0, 1
/* 103C5C 7F0CF12C AE6E0000 */  sw    $t6, ($s3)
/* 103C60 7F0CF130 0238C804 */  sllv  $t9, $t8, $s1
/* 103C64 7F0CF134 26310008 */  addiu $s1, $s1, 8
/* 103C68 7F0CF138 0224082B */  sltu  $at, $s1, $a0
/* 103C6C 7F0CF13C 1420FFF7 */  bnez  $at, .L7F0CF11C
/* 103C70 7F0CF140 0299A025 */   or    $s4, $s4, $t9
.L7F0CF144:
/* 103C74 7F0CF144 8FB90074 */  lw    $t9, 0x74($sp)
/* 103C78 7F0CF148 028B7824 */  and   $t7, $s4, $t3
/* 103C7C 7F0CF14C 000FC0C0 */  sll   $t8, $t7, 3
/* 103C80 7F0CF150 03193021 */  addu  $a2, $t8, $t9
/* 103C84 7F0CF154 90D20000 */  lbu   $s2, ($a2)
/* 103C88 7F0CF158 2E410011 */  sltiu $at, $s2, 0x11
/* 103C8C 7F0CF15C 5420001E */  bnezl $at, .L7F0CF1D8
/* 103C90 7F0CF160 90C20001 */   lbu   $v0, 1($a2)
/* 103C94 7F0CF164 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF168:
/* 103C98 7F0CF168 2652FFF0 */  addiu $s2, $s2, -0x10
/* 103C9C 7F0CF16C 02228823 */  subu  $s1, $s1, $v0
/* 103CA0 7F0CF170 0232082B */  sltu  $at, $s1, $s2
/* 103CA4 7F0CF174 1020000C */  beqz  $at, .L7F0CF1A8
/* 103CA8 7F0CF178 0054A006 */   srlv  $s4, $s4, $v0
/* 103CAC 7F0CF17C 8FC30000 */  lw    $v1, ($fp)
.L7F0CF180:
/* 103CB0 7F0CF180 8E620000 */  lw    $v0, ($s3)
/* 103CB4 7F0CF184 00627021 */  addu  $t6, $v1, $v0
/* 103CB8 7F0CF188 91CF0000 */  lbu   $t7, ($t6)
/* 103CBC 7F0CF18C 24590001 */  addiu $t9, $v0, 1
/* 103CC0 7F0CF190 AE790000 */  sw    $t9, ($s3)
/* 103CC4 7F0CF194 022FC004 */  sllv  $t8, $t7, $s1
/* 103CC8 7F0CF198 26310008 */  addiu $s1, $s1, 8
/* 103CCC 7F0CF19C 0232082B */  sltu  $at, $s1, $s2
/* 103CD0 7F0CF1A0 1420FFF7 */  bnez  $at, .L7F0CF180
/* 103CD4 7F0CF1A4 0298A025 */   or    $s4, $s4, $t8
.L7F0CF1A8:
/* 103CD8 7F0CF1A8 00127040 */  sll   $t6, $s2, 1
/* 103CDC 7F0CF1AC 012E7821 */  addu  $t7, $t1, $t6
/* 103CE0 7F0CF1B0 95F80000 */  lhu   $t8, ($t7)
/* 103CE4 7F0CF1B4 8CCF0004 */  lw    $t7, 4($a2)
/* 103CE8 7F0CF1B8 0314C824 */  and   $t9, $t8, $s4
/* 103CEC 7F0CF1BC 001970C0 */  sll   $t6, $t9, 3
/* 103CF0 7F0CF1C0 01CF3021 */  addu  $a2, $t6, $t7
/* 103CF4 7F0CF1C4 90D20000 */  lbu   $s2, ($a2)
/* 103CF8 7F0CF1C8 2E410011 */  sltiu $at, $s2, 0x11
/* 103CFC 7F0CF1CC 5020FFE6 */  beql  $at, $zero, .L7F0CF168
/* 103D00 7F0CF1D0 90C20001 */   lbu   $v0, 1($a2)
/* 103D04 7F0CF1D4 90C20001 */  lbu   $v0, 1($a2)
.L7F0CF1D8:
/* 103D08 7F0CF1D8 02228823 */  subu  $s1, $s1, $v0
/* 103D0C 7F0CF1DC 0232082B */  sltu  $at, $s1, $s2
/* 103D10 7F0CF1E0 1020000C */  beqz  $at, .L7F0CF214
/* 103D14 7F0CF1E4 0054A006 */   srlv  $s4, $s4, $v0
/* 103D18 7F0CF1E8 8FC30000 */  lw    $v1, ($fp)
.L7F0CF1EC:
/* 103D1C 7F0CF1EC 8E620000 */  lw    $v0, ($s3)
/* 103D20 7F0CF1F0 0062C021 */  addu  $t8, $v1, $v0
/* 103D24 7F0CF1F4 93190000 */  lbu   $t9, ($t8)
/* 103D28 7F0CF1F8 244F0001 */  addiu $t7, $v0, 1
/* 103D2C 7F0CF1FC AE6F0000 */  sw    $t7, ($s3)
/* 103D30 7F0CF200 02397004 */  sllv  $t6, $t9, $s1
/* 103D34 7F0CF204 26310008 */  addiu $s1, $s1, 8
/* 103D38 7F0CF208 0232082B */  sltu  $at, $s1, $s2
/* 103D3C 7F0CF20C 1420FFF7 */  bnez  $at, .L7F0CF1EC
/* 103D40 7F0CF210 028EA025 */   or    $s4, $s4, $t6
.L7F0CF214:
/* 103D44 7F0CF214 94D80004 */  lhu   $t8, 4($a2)
/* 103D48 7F0CF218 00127040 */  sll   $t6, $s2, 1
/* 103D4C 7F0CF21C 012E7821 */  addu  $t7, $t1, $t6
/* 103D50 7F0CF220 02B8C823 */  subu  $t9, $s5, $t8
/* 103D54 7F0CF224 95F80000 */  lhu   $t8, ($t7)
/* 103D58 7F0CF228 02328823 */  subu  $s1, $s1, $s2
/* 103D5C 7F0CF22C 03147024 */  and   $t6, $t8, $s4
/* 103D60 7F0CF230 032E8023 */  subu  $s0, $t9, $t6
/* 103D64 7F0CF234 0254A006 */  srlv  $s4, $s4, $s2
/* 103D68 7F0CF238 01009025 */  move  $s2, $t0
.L7F0CF23C:
/* 103D6C 7F0CF23C 02B07823 */  subu  $t7, $s5, $s0
/* 103D70 7F0CF240 01F2082B */  sltu  $at, $t7, $s2
/* 103D74 7F0CF244 14200025 */  bnez  $at, .L7F0CF2DC
/* 103D78 7F0CF248 00004025 */   move  $t0, $zero
/* 103D7C 7F0CF24C 8EE30000 */  lw    $v1, ($s7)
/* 103D80 7F0CF250 8FD80000 */  lw    $t8, ($fp)
/* 103D84 7F0CF254 8E790000 */  lw    $t9, ($s3)
/* 103D88 7F0CF258 02B2B021 */  addu  $s6, $s5, $s2
/* 103D8C 7F0CF25C 02C31021 */  addu  $v0, $s6, $v1
/* 103D90 7F0CF260 2442FFFF */  addiu $v0, $v0, -1
/* 103D94 7F0CF264 03192021 */  addu  $a0, $t8, $t9
/* 103D98 7F0CF268 0044082B */  sltu  $at, $v0, $a0
/* 103D9C 7F0CF26C 14200006 */  bnez  $at, .L7F0CF288
/* 103DA0 7F0CF270 00447023 */   subu  $t6, $v0, $a0
/* 103DA4 7F0CF274 01C7082B */  sltu  $at, $t6, $a3
/* 103DA8 7F0CF278 50200004 */  beql  $at, $zero, .L7F0CF28C
/* 103DAC 7F0CF27C 00752021 */   addu  $a0, $v1, $s5
.L7F0CF280:
/* 103DB0 7F0CF280 1000FFFF */  b     .L7F0CF280
/* 103DB4 7F0CF284 00000000 */   nop   
.L7F0CF288:
/* 103DB8 7F0CF288 00752021 */  addu  $a0, $v1, $s5
.L7F0CF28C:
/* 103DBC 7F0CF28C 00702821 */  addu  $a1, $v1, $s0
/* 103DC0 7F0CF290 02403025 */  move  $a2, $s2
/* 103DC4 7F0CF294 AFA80068 */  sw    $t0, 0x68($sp)
/* 103DC8 7F0CF298 AFAA0058 */  sw    $t2, 0x58($sp)
/* 103DCC 7F0CF29C AFAB0054 */  sw    $t3, 0x54($sp)
/* 103DD0 7F0CF2A0 AFAC0044 */  sw    $t4, 0x44($sp)
/* 103DD4 7F0CF2A4 0C004E14 */  jal   memcpy
/* 103DD8 7F0CF2A8 AFAD0040 */   sw    $t5, 0x40($sp)
/* 103DDC 7F0CF2AC 3C098005 */  lui   $t1, %hi(D_8004E9B0) 
/* 103DE0 7F0CF2B0 2529E9B0 */  addiu $t1, %lo(D_8004E9B0) # addiu $t1, $t1, -0x1650
/* 103DE4 7F0CF2B4 34078000 */  li    $a3, 32768
/* 103DE8 7F0CF2B8 8FA80068 */  lw    $t0, 0x68($sp)
/* 103DEC 7F0CF2BC 8FAA0058 */  lw    $t2, 0x58($sp)
/* 103DF0 7F0CF2C0 8FAB0054 */  lw    $t3, 0x54($sp)
/* 103DF4 7F0CF2C4 8FAC0044 */  lw    $t4, 0x44($sp)
/* 103DF8 7F0CF2C8 8FAD0040 */  lw    $t5, 0x40($sp)
/* 103DFC 7F0CF2CC 8FBF0078 */  lw    $ra, 0x78($sp)
/* 103E00 7F0CF2D0 02C0A825 */  move  $s5, $s6
/* 103E04 7F0CF2D4 10000016 */  b     .L7F0CF330
/* 103E08 7F0CF2D8 02128021 */   addu  $s0, $s0, $s2
.L7F0CF2DC:
/* 103E0C 7F0CF2DC 8EE30000 */  lw    $v1, ($s7)
/* 103E10 7F0CF2E0 8FCF0000 */  lw    $t7, ($fp)
/* 103E14 7F0CF2E4 8E780000 */  lw    $t8, ($s3)
/* 103E18 7F0CF2E8 00752821 */  addu  $a1, $v1, $s5
/* 103E1C 7F0CF2EC 00A01025 */  move  $v0, $a1
/* 103E20 7F0CF2F0 01F82021 */  addu  $a0, $t7, $t8
/* 103E24 7F0CF2F4 00A4082B */  sltu  $at, $a1, $a0
/* 103E28 7F0CF2F8 14200006 */  bnez  $at, .L7F0CF314
/* 103E2C 7F0CF2FC 0044C823 */   subu  $t9, $v0, $a0
/* 103E30 7F0CF300 0327082B */  sltu  $at, $t9, $a3
/* 103E34 7F0CF304 50200004 */  beql  $at, $zero, .L7F0CF318
/* 103E38 7F0CF308 02037021 */   addu  $t6, $s0, $v1
.L7F0CF30C:
/* 103E3C 7F0CF30C 1000FFFF */  b     .L7F0CF30C
/* 103E40 7F0CF310 00000000 */   nop   
.L7F0CF314:
/* 103E44 7F0CF314 02037021 */  addu  $t6, $s0, $v1
.L7F0CF318:
/* 103E48 7F0CF318 91CF0000 */  lbu   $t7, ($t6)
/* 103E4C 7F0CF31C 2652FFFF */  addiu $s2, $s2, -1
/* 103E50 7F0CF320 26100001 */  addiu $s0, $s0, 1
/* 103E54 7F0CF324 26B50001 */  addiu $s5, $s5, 1
/* 103E58 7F0CF328 1640FFEC */  bnez  $s2, .L7F0CF2DC
/* 103E5C 7F0CF32C A0AF0000 */   sb    $t7, ($a1)
.L7F0CF330:
/* 103E60 7F0CF330 5500FFC2 */  bnezl $t0, .L7F0CF23C
/* 103E64 7F0CF334 01009025 */   move  $s2, $t0
/* 103E68 7F0CF338 1000FF13 */  b     .L7F0CEF88
/* 103E6C 7F0CF33C 023F082B */   sltu  $at, $s1, $ra
.L7F0CF340:
/* 103E70 7F0CF340 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D35C)
/* 103E74 7F0CF344 AC35D35C */  sw    $s5, %lo(dword_CODE_bss_8008D35C)($at)
/* 103E78 7F0CF348 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D364)
/* 103E7C 7F0CF34C AC34D364 */  sw    $s4, %lo(dword_CODE_bss_8008D364)($at)
/* 103E80 7F0CF350 8FBF003C */  lw    $ra, 0x3c($sp)
/* 103E84 7F0CF354 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D368)
/* 103E88 7F0CF358 AC31D368 */  sw    $s1, %lo(dword_CODE_bss_8008D368)($at)
/* 103E8C 7F0CF35C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 103E90 7F0CF360 8FB40028 */  lw    $s4, 0x28($sp)
/* 103E94 7F0CF364 8FB5002C */  lw    $s5, 0x2c($sp)
/* 103E98 7F0CF368 8FB00018 */  lw    $s0, 0x18($sp)
/* 103E9C 7F0CF36C 8FB20020 */  lw    $s2, 0x20($sp)
/* 103EA0 7F0CF370 8FB30024 */  lw    $s3, 0x24($sp)
/* 103EA4 7F0CF374 8FB60030 */  lw    $s6, 0x30($sp)
/* 103EA8 7F0CF378 8FB70034 */  lw    $s7, 0x34($sp)
/* 103EAC 7F0CF37C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 103EB0 7F0CF380 27BD0070 */  addiu $sp, $sp, 0x70
/* 103EB4 7F0CF384 03E00008 */  jr    $ra
/* 103EB8 7F0CF388 00001025 */   move  $v0, $zero
)
#endif





#ifdef NONMATCHING
void zlib_decompressor_type0(void) {

}
#else
GLOBAL_ASM(
.text
glabel zlib_decompressor_type0
/* 103EBC 7F0CF38C 3C0B8009 */  lui   $t3, %hi(dword_CODE_bss_8008D368) 
/* 103EC0 7F0CF390 256BD368 */  addiu $t3, %lo(dword_CODE_bss_8008D368) # addiu $t3, $t3, -0x2c98
/* 103EC4 7F0CF394 8D640000 */  lw    $a0, ($t3)
/* 103EC8 7F0CF398 3C0A8009 */  lui   $t2, %hi(dword_CODE_bss_8008D364) 
/* 103ECC 7F0CF39C 254AD364 */  addiu $t2, %lo(dword_CODE_bss_8008D364) # addiu $t2, $t2, -0x2c9c
/* 103ED0 7F0CF3A0 30820007 */  andi  $v0, $a0, 7
/* 103ED4 7F0CF3A4 8D430000 */  lw    $v1, ($t2)
/* 103ED8 7F0CF3A8 3C0C8009 */  lui   $t4, %hi(dword_CODE_bss_8008D35C) 
/* 103EDC 7F0CF3AC 00822023 */  subu  $a0, $a0, $v0
/* 103EE0 7F0CF3B0 258CD35C */  addiu $t4, %lo(dword_CODE_bss_8008D35C) # addiu $t4, $t4, -0x2ca4
/* 103EE4 7F0CF3B4 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 103EE8 7F0CF3B8 2C810010 */  sltiu $at, $a0, 0x10
/* 103EEC 7F0CF3BC AFB1000C */  sw    $s1, 0xc($sp)
/* 103EF0 7F0CF3C0 AFB00008 */  sw    $s0, 8($sp)
/* 103EF4 7F0CF3C4 8D850000 */  lw    $a1, ($t4)
/* 103EF8 7F0CF3C8 1020000F */  beqz  $at, .L7F0CF408
/* 103EFC 7F0CF3CC 00431806 */   srlv  $v1, $v1, $v0
/* 103F00 7F0CF3D0 3C068009 */  lui   $a2, %hi(dword_CODE_bss_8008D350)
/* 103F04 7F0CF3D4 3C0D8009 */  lui   $t5, %hi(dword_CODE_bss_8008D358) 
/* 103F08 7F0CF3D8 25ADD358 */  addiu $t5, %lo(dword_CODE_bss_8008D358) # addiu $t5, $t5, -0x2ca8
/* 103F0C 7F0CF3DC 8CC6D350 */  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CF3E0:
/* 103F10 7F0CF3E0 8DA70000 */  lw    $a3, ($t5)
/* 103F14 7F0CF3E4 00C77021 */  addu  $t6, $a2, $a3
/* 103F18 7F0CF3E8 91CF0000 */  lbu   $t7, ($t6)
/* 103F1C 7F0CF3EC 24F90001 */  addiu $t9, $a3, 1
/* 103F20 7F0CF3F0 ADB90000 */  sw    $t9, ($t5)
/* 103F24 7F0CF3F4 008FC004 */  sllv  $t8, $t7, $a0
/* 103F28 7F0CF3F8 24840008 */  addiu $a0, $a0, 8
/* 103F2C 7F0CF3FC 2C810010 */  sltiu $at, $a0, 0x10
/* 103F30 7F0CF400 1420FFF7 */  bnez  $at, .L7F0CF3E0
/* 103F34 7F0CF404 00781825 */   or    $v1, $v1, $t8
.L7F0CF408:
/* 103F38 7F0CF408 2484FFF0 */  addiu $a0, $a0, -0x10
/* 103F3C 7F0CF40C 3C0D8009 */  lui   $t5, %hi(dword_CODE_bss_8008D358) 
/* 103F40 7F0CF410 3062FFFF */  andi  $v0, $v1, 0xffff
/* 103F44 7F0CF414 00037402 */  srl   $t6, $v1, 0x10
/* 103F48 7F0CF418 2C810010 */  sltiu $at, $a0, 0x10
/* 103F4C 7F0CF41C 25ADD358 */  addiu $t5, %lo(dword_CODE_bss_8008D358) # addiu $t5, $t5, -0x2ca8
/* 103F50 7F0CF420 1020000D */  beqz  $at, .L7F0CF458
/* 103F54 7F0CF424 01C01825 */   move  $v1, $t6
/* 103F58 7F0CF428 3C068009 */  lui   $a2, %hi(dword_CODE_bss_8008D350)
/* 103F5C 7F0CF42C 8CC6D350 */  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CF430:
/* 103F60 7F0CF430 8DA70000 */  lw    $a3, ($t5)
/* 103F64 7F0CF434 00C77821 */  addu  $t7, $a2, $a3
/* 103F68 7F0CF438 91F80000 */  lbu   $t8, ($t7)
/* 103F6C 7F0CF43C 24EE0001 */  addiu $t6, $a3, 1
/* 103F70 7F0CF440 ADAE0000 */  sw    $t6, ($t5)
/* 103F74 7F0CF444 0098C804 */  sllv  $t9, $t8, $a0
/* 103F78 7F0CF448 24840008 */  addiu $a0, $a0, 8
/* 103F7C 7F0CF44C 2C810010 */  sltiu $at, $a0, 0x10
/* 103F80 7F0CF450 1420FFF7 */  bnez  $at, .L7F0CF430
/* 103F84 7F0CF454 00791825 */   or    $v1, $v1, $t9
.L7F0CF458:
/* 103F88 7F0CF458 00403025 */  move  $a2, $v0
/* 103F8C 7F0CF45C 00037C02 */  srl   $t7, $v1, 0x10
/* 103F90 7F0CF460 01E01825 */  move  $v1, $t7
/* 103F94 7F0CF464 2484FFF0 */  addiu $a0, $a0, -0x10
/* 103F98 7F0CF468 10400027 */  beqz  $v0, .L7F0CF508
/* 103F9C 7F0CF46C 2442FFFF */   addiu $v0, $v0, -1
/* 103FA0 7F0CF470 3C108009 */  lui   $s0, %hi(dword_CODE_bss_8008D354)
/* 103FA4 7F0CF474 2610D354 */  addiu $s0, %lo(dword_CODE_bss_8008D354) # addiu $s0, $s0, -0x2cac
/* 103FA8 7F0CF478 34118000 */  li    $s1, 32768
.L7F0CF47C:
/* 103FAC 7F0CF47C 3C068009 */  lui   $a2, %hi(dword_CODE_bss_8008D350)
/* 103FB0 7F0CF480 2C810008 */  sltiu $at, $a0, 8
/* 103FB4 7F0CF484 1020000B */  beqz  $at, .L7F0CF4B4
/* 103FB8 7F0CF488 8CC6D350 */   lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CF48C:
/* 103FBC 7F0CF48C 8DA70000 */  lw    $a3, ($t5)
/* 103FC0 7F0CF490 00C7C021 */  addu  $t8, $a2, $a3
/* 103FC4 7F0CF494 93190000 */  lbu   $t9, ($t8)
/* 103FC8 7F0CF498 24EF0001 */  addiu $t7, $a3, 1
/* 103FCC 7F0CF49C ADAF0000 */  sw    $t7, ($t5)
/* 103FD0 7F0CF4A0 00997004 */  sllv  $t6, $t9, $a0
/* 103FD4 7F0CF4A4 24840008 */  addiu $a0, $a0, 8
/* 103FD8 7F0CF4A8 2C810008 */  sltiu $at, $a0, 8
/* 103FDC 7F0CF4AC 1420FFF7 */  bnez  $at, .L7F0CF48C
/* 103FE0 7F0CF4B0 006E1825 */   or    $v1, $v1, $t6
.L7F0CF4B4:
/* 103FE4 7F0CF4B4 8E180000 */  lw    $t8, ($s0)
/* 103FE8 7F0CF4B8 8DB90000 */  lw    $t9, ($t5)
/* 103FEC 7F0CF4BC 00037A02 */  srl   $t7, $v1, 8
/* 103FF0 7F0CF4C0 03053821 */  addu  $a3, $t8, $a1
/* 103FF4 7F0CF4C4 00D94821 */  addu  $t1, $a2, $t9
/* 103FF8 7F0CF4C8 00E9082B */  sltu  $at, $a3, $t1
/* 103FFC 7F0CF4CC 14200007 */  bnez  $at, .L7F0CF4EC
/* 104000 7F0CF4D0 00E04025 */   move  $t0, $a3
/* 104004 7F0CF4D4 01097023 */  subu  $t6, $t0, $t1
/* 104008 7F0CF4D8 01D1082B */  sltu  $at, $t6, $s1
/* 10400C 7F0CF4DC 50200004 */  beql  $at, $zero, .L7F0CF4F0
/* 104010 7F0CF4E0 00403025 */   move  $a2, $v0
.L7F0CF4E4:
/* 104014 7F0CF4E4 1000FFFF */  b     .L7F0CF4E4
/* 104018 7F0CF4E8 00000000 */   nop   
.L7F0CF4EC:
/* 10401C 7F0CF4EC 00403025 */  move  $a2, $v0
.L7F0CF4F0:
/* 104020 7F0CF4F0 A0E30000 */  sb    $v1, ($a3)
/* 104024 7F0CF4F4 24A50001 */  addiu $a1, $a1, 1
/* 104028 7F0CF4F8 01E01825 */  move  $v1, $t7
/* 10402C 7F0CF4FC 2484FFF8 */  addiu $a0, $a0, -8
/* 104030 7F0CF500 1440FFDE */  bnez  $v0, .L7F0CF47C
/* 104034 7F0CF504 2442FFFF */   addiu $v0, $v0, -1
.L7F0CF508:
/* 104038 7F0CF508 8FB00008 */  lw    $s0, 8($sp)
/* 10403C 7F0CF50C 8FB1000C */  lw    $s1, 0xc($sp)
/* 104040 7F0CF510 AD850000 */  sw    $a1, ($t4)
/* 104044 7F0CF514 AD430000 */  sw    $v1, ($t2)
/* 104048 7F0CF518 AD640000 */  sw    $a0, ($t3)
/* 10404C 7F0CF51C 27BD0010 */  addiu $sp, $sp, 0x10
/* 104050 7F0CF520 03E00008 */  jr    $ra
/* 104054 7F0CF524 00001025 */   move  $v0, $zero
)
#endif





#ifdef NONMATCHING
void zlib_decompressor_type1(void)
{
    ? sp4B8;
    ? sp4B4;
    ?32 sp4B0;
    ?32 sp4AC;
    ? sp48C;
    ? sp42C;
    ? sp26C;
    ? spA4;
    ? sp34;
    ?32 sp30;
    ?32 sp2C;
    void *temp_v0;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v0_4;
    void *temp_v0_5;
    void *phi_v0;
    u32 phi_v0_2;
    u32 phi_v0_3;
    u32 phi_v0_4;
    u32 phi_v0_5;
    u32 phi_v0_6;
    void *phi_v0_7;

    phi_v0 = &sp2C;
block_1:
    temp_v0 = (phi_v0 + 0x10);
    temp_v0->unk-C = 8;
    temp_v0->unk-8 = 8;
    temp_v0->unk-4 = 8;
    temp_v0->unk-10 = 8;
    phi_v0 = temp_v0;
    if (temp_v0 != &sp26C)
    {
        goto block_1;
    }
    phi_v0_3 = temp_v0;
    if (temp_v0 < &sp42C)
    {
        phi_v0_2 = temp_v0;
block_4:
        temp_v0_2 = (phi_v0_2 + 4);
        temp_v0_2->unk-4 = 9;
        phi_v0_2 = temp_v0_2;
        phi_v0_3 = temp_v0_2;
        if (temp_v0_2 < &sp42C)
        {
            goto block_4;
        }
    }
    phi_v0_5 = phi_v0_3;
    if ((u32) phi_v0_3 < &sp48C)
    {
        phi_v0_4 = phi_v0_3;
block_7:
        temp_v0_3 = (phi_v0_4 + 4);
        temp_v0_3->unk-4 = 7;
        phi_v0_4 = temp_v0_3;
        phi_v0_5 = temp_v0_3;
        if (temp_v0_3 < &sp48C)
        {
            goto block_7;
        }
    }
    if ((u32) phi_v0_5 < &sp4AC)
    {
        phi_v0_6 = phi_v0_5;
block_10:
        temp_v0_4 = (phi_v0_6 + 4);
        temp_v0_4->unk-4 = 8;
        phi_v0_6 = temp_v0_4;
        if (temp_v0_4 < &sp4AC)
        {
            goto block_10;
        }
    }
    sp4B0 = 7;
    sub_GAME_7F0CE8B0(&sp2C, 0x120, 0x101, &D_8004E8F4, &D_8004E934, &sp4B8, &sp4B0);
    sp30 = 5;
    sp2C = 5;
    phi_v0_7 = &sp34;
block_12:
    temp_v0_5 = (phi_v0_7 + 0x10);
    temp_v0_5->unk-C = 5;
    temp_v0_5->unk-8 = 5;
    temp_v0_5->unk-4 = 5;
    temp_v0_5->unk-10 = 5;
    phi_v0_7 = temp_v0_5;
    if (temp_v0_5 != &spA4)
    {
        goto block_12;
    }
    sp4AC = 5;
    sub_GAME_7F0CE8B0(&sp2C, 0x1e, 0, &D_8004E954, &D_8004E990, &sp4B4, &sp4AC);
    sub_GAME_7F0CEEF0(sp4B8, sp4B4, sp4B0, sp4AC);
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel zlib_decompressor_type1
/* 104058 7F0CF528 27BDFB40 */  addiu $sp, $sp, -0x4c0
/* 10405C 7F0CF52C AFBF0024 */  sw    $ra, 0x24($sp)
/* 104060 7F0CF530 27A2002C */  addiu $v0, $sp, 0x2c
/* 104064 7F0CF534 27A4026C */  addiu $a0, $sp, 0x26c
/* 104068 7F0CF538 24030008 */  li    $v1, 8
.L7F0CF53C:
/* 10406C 7F0CF53C 24420010 */  addiu $v0, $v0, 0x10
/* 104070 7F0CF540 AC43FFF4 */  sw    $v1, -0xc($v0)
/* 104074 7F0CF544 AC43FFF8 */  sw    $v1, -8($v0)
/* 104078 7F0CF548 AC43FFFC */  sw    $v1, -4($v0)
/* 10407C 7F0CF54C 1444FFFB */  bne   $v0, $a0, .L7F0CF53C
/* 104080 7F0CF550 AC43FFF0 */   sw    $v1, -0x10($v0)
/* 104084 7F0CF554 27AE042C */  addiu $t6, $sp, 0x42c
/* 104088 7F0CF558 004E082B */  sltu  $at, $v0, $t6
/* 10408C 7F0CF55C 10200007 */  beqz  $at, .L7F0CF57C
/* 104090 7F0CF560 27AF048C */   addiu $t7, $sp, 0x48c
/* 104094 7F0CF564 27A5042C */  addiu $a1, $sp, 0x42c
/* 104098 7F0CF568 24040009 */  li    $a0, 9
.L7F0CF56C:
/* 10409C 7F0CF56C 24420004 */  addiu $v0, $v0, 4
/* 1040A0 7F0CF570 0045082B */  sltu  $at, $v0, $a1
/* 1040A4 7F0CF574 1420FFFD */  bnez  $at, .L7F0CF56C
/* 1040A8 7F0CF578 AC44FFFC */   sw    $a0, -4($v0)
.L7F0CF57C:
/* 1040AC 7F0CF57C 004F082B */  sltu  $at, $v0, $t7
/* 1040B0 7F0CF580 10200007 */  beqz  $at, .L7F0CF5A0
/* 1040B4 7F0CF584 27B804AC */   addiu $t8, $sp, 0x4ac
/* 1040B8 7F0CF588 27A5048C */  addiu $a1, $sp, 0x48c
/* 1040BC 7F0CF58C 24040007 */  li    $a0, 7
.L7F0CF590:
/* 1040C0 7F0CF590 24420004 */  addiu $v0, $v0, 4
/* 1040C4 7F0CF594 0045082B */  sltu  $at, $v0, $a1
/* 1040C8 7F0CF598 1420FFFD */  bnez  $at, .L7F0CF590
/* 1040CC 7F0CF59C AC44FFFC */   sw    $a0, -4($v0)
.L7F0CF5A0:
/* 1040D0 7F0CF5A0 0058082B */  sltu  $at, $v0, $t8
/* 1040D4 7F0CF5A4 10200006 */  beqz  $at, .L7F0CF5C0
/* 1040D8 7F0CF5A8 24190007 */   li    $t9, 7
/* 1040DC 7F0CF5AC 27A404AC */  addiu $a0, $sp, 0x4ac
.L7F0CF5B0:
/* 1040E0 7F0CF5B0 24420004 */  addiu $v0, $v0, 4
/* 1040E4 7F0CF5B4 0044082B */  sltu  $at, $v0, $a0
/* 1040E8 7F0CF5B8 1420FFFD */  bnez  $at, .L7F0CF5B0
/* 1040EC 7F0CF5BC AC43FFFC */   sw    $v1, -4($v0)
.L7F0CF5C0:
/* 1040F0 7F0CF5C0 3C088005 */  lui   $t0, %hi(D_8004E934) 
/* 1040F4 7F0CF5C4 2508E934 */  addiu $t0, %lo(D_8004E934) # addiu $t0, $t0, -0x16cc
/* 1040F8 7F0CF5C8 3C078005 */  lui   $a3, %hi(D_8004E8F4)
/* 1040FC 7F0CF5CC 27A904B8 */  addiu $t1, $sp, 0x4b8
/* 104100 7F0CF5D0 27AA04B0 */  addiu $t2, $sp, 0x4b0
/* 104104 7F0CF5D4 AFB904B0 */  sw    $t9, 0x4b0($sp)
/* 104108 7F0CF5D8 AFAA0018 */  sw    $t2, 0x18($sp)
/* 10410C 7F0CF5DC AFA90014 */  sw    $t1, 0x14($sp)
/* 104110 7F0CF5E0 24E7E8F4 */  addiu $a3, %lo(D_8004E8F4) # addiu $a3, $a3, -0x170c
/* 104114 7F0CF5E4 AFA80010 */  sw    $t0, 0x10($sp)
/* 104118 7F0CF5E8 27A4002C */  addiu $a0, $sp, 0x2c
/* 10411C 7F0CF5EC 24050120 */  li    $a1, 288
/* 104120 7F0CF5F0 0FC33A2C */  jal   sub_GAME_7F0CE8B0
/* 104124 7F0CF5F4 24060101 */   li    $a2, 257
/* 104128 7F0CF5F8 240B0005 */  li    $t3, 5
/* 10412C 7F0CF5FC 240C0005 */  li    $t4, 5
/* 104130 7F0CF600 AFAC0030 */  sw    $t4, 0x30($sp)
/* 104134 7F0CF604 AFAB002C */  sw    $t3, 0x2c($sp)
/* 104138 7F0CF608 27A20034 */  addiu $v0, $sp, 0x34
/* 10413C 7F0CF60C 27A400A4 */  addiu $a0, $sp, 0xa4
/* 104140 7F0CF610 24030005 */  li    $v1, 5
.L7F0CF614:
/* 104144 7F0CF614 24420010 */  addiu $v0, $v0, 0x10
/* 104148 7F0CF618 AC43FFF4 */  sw    $v1, -0xc($v0)
/* 10414C 7F0CF61C AC43FFF8 */  sw    $v1, -8($v0)
/* 104150 7F0CF620 AC43FFFC */  sw    $v1, -4($v0)
/* 104154 7F0CF624 1444FFFB */  bne   $v0, $a0, .L7F0CF614
/* 104158 7F0CF628 AC43FFF0 */   sw    $v1, -0x10($v0)
/* 10415C 7F0CF62C 3C0E8005 */  lui   $t6, %hi(D_8004E990) 
/* 104160 7F0CF630 240D0005 */  li    $t5, 5
/* 104164 7F0CF634 25CEE990 */  addiu $t6, %lo(D_8004E990) # addiu $t6, $t6, -0x1670
/* 104168 7F0CF638 3C078005 */  lui   $a3, %hi(D_8004E954)
/* 10416C 7F0CF63C 27AF04B4 */  addiu $t7, $sp, 0x4b4
/* 104170 7F0CF640 27B804AC */  addiu $t8, $sp, 0x4ac
/* 104174 7F0CF644 AFAD04AC */  sw    $t5, 0x4ac($sp)
/* 104178 7F0CF648 AFB80018 */  sw    $t8, 0x18($sp)
/* 10417C 7F0CF64C AFAF0014 */  sw    $t7, 0x14($sp)
/* 104180 7F0CF650 24E7E954 */  addiu $a3, %lo(D_8004E954) # addiu $a3, $a3, -0x16ac
/* 104184 7F0CF654 AFAE0010 */  sw    $t6, 0x10($sp)
/* 104188 7F0CF658 27A4002C */  addiu $a0, $sp, 0x2c
/* 10418C 7F0CF65C 2405001E */  li    $a1, 30
/* 104190 7F0CF660 0FC33A2C */  jal   sub_GAME_7F0CE8B0
/* 104194 7F0CF664 00003025 */   move  $a2, $zero
/* 104198 7F0CF668 8FA404B8 */  lw    $a0, 0x4b8($sp)
/* 10419C 7F0CF66C 8FA504B4 */  lw    $a1, 0x4b4($sp)
/* 1041A0 7F0CF670 8FA604B0 */  lw    $a2, 0x4b0($sp)
/* 1041A4 7F0CF674 0FC33BBC */  jal   sub_GAME_7F0CEEF0
/* 1041A8 7F0CF678 8FA704AC */   lw    $a3, 0x4ac($sp)
/* 1041AC 7F0CF67C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1041B0 7F0CF680 27BD04C0 */  addiu $sp, $sp, 0x4c0
/* 1041B4 7F0CF684 00001025 */  move  $v0, $zero
/* 1041B8 7F0CF688 03E00008 */  jr    $ra
/* 1041BC 7F0CF68C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void zlib_decompressor_type2(void) {

}
#else
GLOBAL_ASM(
.text
glabel zlib_decompressor_type2
/* 1041C0 7F0CF690 3C088009 */  lui   $t0, %hi(dword_CODE_bss_8008D368) 
/* 1041C4 7F0CF694 8D08D368 */  lw    $t0, %lo(dword_CODE_bss_8008D368)($t0)
/* 1041C8 7F0CF698 27BDFA98 */  addiu $sp, $sp, -0x568
/* 1041CC 7F0CF69C 3C098009 */  lui   $t1, %hi(dword_CODE_bss_8008D364) 
/* 1041D0 7F0CF6A0 2D010005 */  sltiu $at, $t0, 5
/* 1041D4 7F0CF6A4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 1041D8 7F0CF6A8 AFB00028 */  sw    $s0, 0x28($sp)
/* 1041DC 7F0CF6AC 1020000F */  beqz  $at, .L7F0CF6EC
/* 1041E0 7F0CF6B0 8D29D364 */   lw    $t1, %lo(dword_CODE_bss_8008D364)($t1)
/* 1041E4 7F0CF6B4 3C038009 */  lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 1041E8 7F0CF6B8 3C0A8009 */  lui   $t2, %hi(dword_CODE_bss_8008D358) 
/* 1041EC 7F0CF6BC 254AD358 */  addiu $t2, %lo(dword_CODE_bss_8008D358) # addiu $t2, $t2, -0x2ca8
/* 1041F0 7F0CF6C0 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF6C4:
/* 1041F4 7F0CF6C4 8D420000 */  lw    $v0, ($t2)
/* 1041F8 7F0CF6C8 00627021 */  addu  $t6, $v1, $v0
/* 1041FC 7F0CF6CC 91CF0000 */  lbu   $t7, ($t6)
/* 104200 7F0CF6D0 24590001 */  addiu $t9, $v0, 1
/* 104204 7F0CF6D4 AD590000 */  sw    $t9, ($t2)
/* 104208 7F0CF6D8 010FC004 */  sllv  $t8, $t7, $t0
/* 10420C 7F0CF6DC 25080008 */  addiu $t0, $t0, 8
/* 104210 7F0CF6E0 2D010005 */  sltiu $at, $t0, 5
/* 104214 7F0CF6E4 1420FFF7 */  bnez  $at, .L7F0CF6C4
/* 104218 7F0CF6E8 01384825 */   or    $t1, $t1, $t8
.L7F0CF6EC:
/* 10421C 7F0CF6EC 312E001F */  andi  $t6, $t1, 0x1f
/* 104220 7F0CF6F0 2508FFFB */  addiu $t0, $t0, -5
/* 104224 7F0CF6F4 3C0A8009 */  lui   $t2, %hi(dword_CODE_bss_8008D358) 
/* 104228 7F0CF6F8 25CF0101 */  addiu $t7, $t6, 0x101
/* 10422C 7F0CF6FC 0009C142 */  srl   $t8, $t1, 5
/* 104230 7F0CF700 2D010005 */  sltiu $at, $t0, 5
/* 104234 7F0CF704 254AD358 */  addiu $t2, %lo(dword_CODE_bss_8008D358) # addiu $t2, $t2, -0x2ca8
/* 104238 7F0CF708 AFAF053C */  sw    $t7, 0x53c($sp)
/* 10423C 7F0CF70C 1020000D */  beqz  $at, .L7F0CF744
/* 104240 7F0CF710 03004825 */   move  $t1, $t8
/* 104244 7F0CF714 3C038009 */  lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 104248 7F0CF718 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF71C:
/* 10424C 7F0CF71C 8D420000 */  lw    $v0, ($t2)
/* 104250 7F0CF720 0062C821 */  addu  $t9, $v1, $v0
/* 104254 7F0CF724 932E0000 */  lbu   $t6, ($t9)
/* 104258 7F0CF728 24580001 */  addiu $t8, $v0, 1
/* 10425C 7F0CF72C AD580000 */  sw    $t8, ($t2)
/* 104260 7F0CF730 010E7804 */  sllv  $t7, $t6, $t0
/* 104264 7F0CF734 25080008 */  addiu $t0, $t0, 8
/* 104268 7F0CF738 2D010005 */  sltiu $at, $t0, 5
/* 10426C 7F0CF73C 1420FFF7 */  bnez  $at, .L7F0CF71C
/* 104270 7F0CF740 012F4825 */   or    $t1, $t1, $t7
.L7F0CF744:
/* 104274 7F0CF744 3139001F */  andi  $t9, $t1, 0x1f
/* 104278 7F0CF748 2508FFFB */  addiu $t0, $t0, -5
/* 10427C 7F0CF74C 272E0001 */  addiu $t6, $t9, 1
/* 104280 7F0CF750 00097942 */  srl   $t7, $t1, 5
/* 104284 7F0CF754 2D010004 */  sltiu $at, $t0, 4
/* 104288 7F0CF758 AFAE0538 */  sw    $t6, 0x538($sp)
/* 10428C 7F0CF75C 1020000D */  beqz  $at, .L7F0CF794
/* 104290 7F0CF760 01E04825 */   move  $t1, $t7
/* 104294 7F0CF764 3C038009 */  lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 104298 7F0CF768 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF76C:
/* 10429C 7F0CF76C 8D420000 */  lw    $v0, ($t2)
/* 1042A0 7F0CF770 0062C021 */  addu  $t8, $v1, $v0
/* 1042A4 7F0CF774 93190000 */  lbu   $t9, ($t8)
/* 1042A8 7F0CF778 244F0001 */  addiu $t7, $v0, 1
/* 1042AC 7F0CF77C AD4F0000 */  sw    $t7, ($t2)
/* 1042B0 7F0CF780 01197004 */  sllv  $t6, $t9, $t0
/* 1042B4 7F0CF784 25080008 */  addiu $t0, $t0, 8
/* 1042B8 7F0CF788 2D010004 */  sltiu $at, $t0, 4
/* 1042BC 7F0CF78C 1420FFF7 */  bnez  $at, .L7F0CF76C
/* 1042C0 7F0CF790 012E4825 */   or    $t1, $t1, $t6
.L7F0CF794:
/* 1042C4 7F0CF794 3126000F */  andi  $a2, $t1, 0xf
/* 1042C8 7F0CF798 24C60004 */  addiu $a2, $a2, 4
/* 1042CC 7F0CF79C 0009C102 */  srl   $t8, $t1, 4
/* 1042D0 7F0CF7A0 03004825 */  move  $t1, $t8
/* 1042D4 7F0CF7A4 2508FFFC */  addiu $t0, $t0, -4
/* 1042D8 7F0CF7A8 10C0001D */  beqz  $a2, .L7F0CF820
/* 1042DC 7F0CF7AC 00002025 */   move  $a0, $zero
/* 1042E0 7F0CF7B0 3C058005 */  lui   $a1, %hi(D_8004E8E0)
/* 1042E4 7F0CF7B4 24A5E8E0 */  addiu $a1, %lo(D_8004E8E0) # addiu $a1, $a1, -0x1720
/* 1042E8 7F0CF7B8 27B00040 */  addiu $s0, $sp, 0x40
.L7F0CF7BC:
/* 1042EC 7F0CF7BC 2D010003 */  sltiu $at, $t0, 3
/* 1042F0 7F0CF7C0 1020000D */  beqz  $at, .L7F0CF7F8
/* 1042F4 7F0CF7C4 24840001 */   addiu $a0, $a0, 1
/* 1042F8 7F0CF7C8 3C038009 */  lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 1042FC 7F0CF7CC 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF7D0:
/* 104300 7F0CF7D0 8D420000 */  lw    $v0, ($t2)
/* 104304 7F0CF7D4 0062C821 */  addu  $t9, $v1, $v0
/* 104308 7F0CF7D8 932E0000 */  lbu   $t6, ($t9)
/* 10430C 7F0CF7DC 24580001 */  addiu $t8, $v0, 1
/* 104310 7F0CF7E0 AD580000 */  sw    $t8, ($t2)
/* 104314 7F0CF7E4 010E7804 */  sllv  $t7, $t6, $t0
/* 104318 7F0CF7E8 25080008 */  addiu $t0, $t0, 8
/* 10431C 7F0CF7EC 2D010003 */  sltiu $at, $t0, 3
/* 104320 7F0CF7F0 1420FFF7 */  bnez  $at, .L7F0CF7D0
/* 104324 7F0CF7F4 012F4825 */   or    $t1, $t1, $t7
.L7F0CF7F8:
/* 104328 7F0CF7F8 90AE0000 */  lbu   $t6, ($a1)
/* 10432C 7F0CF7FC 31390007 */  andi  $t9, $t1, 7
/* 104330 7F0CF800 24A50001 */  addiu $a1, $a1, 1
/* 104334 7F0CF804 000E7880 */  sll   $t7, $t6, 2
/* 104338 7F0CF808 020FC021 */  addu  $t8, $s0, $t7
/* 10433C 7F0CF80C 000970C2 */  srl   $t6, $t1, 3
/* 104340 7F0CF810 AF190000 */  sw    $t9, ($t8)
/* 104344 7F0CF814 01C04825 */  move  $t1, $t6
/* 104348 7F0CF818 1486FFE8 */  bne   $a0, $a2, .L7F0CF7BC
/* 10434C 7F0CF81C 2508FFFD */   addiu $t0, $t0, -3
.L7F0CF820:
/* 104350 7F0CF820 2C810013 */  sltiu $at, $a0, 0x13
/* 104354 7F0CF824 1020000D */  beqz  $at, .L7F0CF85C
/* 104358 7F0CF828 27B00040 */   addiu $s0, $sp, 0x40
/* 10435C 7F0CF82C 3C0F8005 */  lui   $t7, %hi(D_8004E8E0) 
/* 104360 7F0CF830 25EFE8E0 */  addiu $t7, %lo(D_8004E8E0) # addiu $t7, $t7, -0x1720
/* 104364 7F0CF834 3C028005 */  lui   $v0, %hi(D_8004E8E0+0x13)
/* 104368 7F0CF838 2442E8F3 */  addiu $v0, %lo(D_8004E8E0+0x13) # addiu $v0, $v0, -0x170d
/* 10436C 7F0CF83C 008F2821 */  addu  $a1, $a0, $t7
.L7F0CF840:
/* 104370 7F0CF840 90B90000 */  lbu   $t9, ($a1)
/* 104374 7F0CF844 24A50001 */  addiu $a1, $a1, 1
/* 104378 7F0CF848 00A2082B */  sltu  $at, $a1, $v0
/* 10437C 7F0CF84C 0019C080 */  sll   $t8, $t9, 2
/* 104380 7F0CF850 02187021 */  addu  $t6, $s0, $t8
/* 104384 7F0CF854 1420FFFA */  bnez  $at, .L7F0CF840
/* 104388 7F0CF858 ADC00000 */   sw    $zero, ($t6)
.L7F0CF85C:
/* 10438C 7F0CF85C 240F0007 */  li    $t7, 7
/* 104390 7F0CF860 27B90550 */  addiu $t9, $sp, 0x550
/* 104394 7F0CF864 27B80548 */  addiu $t8, $sp, 0x548
/* 104398 7F0CF868 AFAF0548 */  sw    $t7, 0x548($sp)
/* 10439C 7F0CF86C AFB80018 */  sw    $t8, 0x18($sp)
/* 1043A0 7F0CF870 AFB90014 */  sw    $t9, 0x14($sp)
/* 1043A4 7F0CF874 02002025 */  move  $a0, $s0
/* 1043A8 7F0CF878 24050013 */  li    $a1, 19
/* 1043AC 7F0CF87C 24060013 */  li    $a2, 19
/* 1043B0 7F0CF880 00003825 */  move  $a3, $zero
/* 1043B4 7F0CF884 AFA00010 */  sw    $zero, 0x10($sp)
/* 1043B8 7F0CF888 AFA80534 */  sw    $t0, 0x534($sp)
/* 1043BC 7F0CF88C 0FC33A2C */  jal   sub_GAME_7F0CE8B0
/* 1043C0 7F0CF890 AFA90530 */   sw    $t1, 0x530($sp)
/* 1043C4 7F0CF894 8FB90548 */  lw    $t9, 0x548($sp)
/* 1043C8 7F0CF898 8FAE053C */  lw    $t6, 0x53c($sp)
/* 1043CC 7F0CF89C 8FAF0538 */  lw    $t7, 0x538($sp)
/* 1043D0 7F0CF8A0 3C0B8005 */  lui   $t3, %hi(D_8004E9B0)
/* 1043D4 7F0CF8A4 0019C040 */  sll   $t8, $t9, 1
/* 1043D8 7F0CF8A8 3C0A8009 */  lui   $t2, %hi(dword_CODE_bss_8008D358) 
/* 1043DC 7F0CF8AC 01785821 */  addu  $t3, $t3, $t8
/* 1043E0 7F0CF8B0 01CF3821 */  addu  $a3, $t6, $t7
/* 1043E4 7F0CF8B4 254AD358 */  addiu $t2, %lo(dword_CODE_bss_8008D358) # addiu $t2, $t2, -0x2ca8
/* 1043E8 7F0CF8B8 8FA80534 */  lw    $t0, 0x534($sp)
/* 1043EC 7F0CF8BC 8FA90530 */  lw    $t1, 0x530($sp)
/* 1043F0 7F0CF8C0 956BE9B0 */  lhu   $t3, %lo(D_8004E9B0)($t3)
/* 1043F4 7F0CF8C4 00003025 */  move  $a2, $zero
/* 1043F8 7F0CF8C8 10E0008A */  beqz  $a3, .L7F0CFAF4
/* 1043FC 7F0CF8CC 00002825 */   move  $a1, $zero
/* 104400 7F0CF8D0 240D0011 */  li    $t5, 17
/* 104404 7F0CF8D4 240C0010 */  li    $t4, 16
/* 104408 7F0CF8D8 8FAE0548 */  lw    $t6, 0x548($sp)
.L7F0CF8DC:
/* 10440C 7F0CF8DC 3C038009 */  lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 104410 7F0CF8E0 010E082B */  sltu  $at, $t0, $t6
/* 104414 7F0CF8E4 5020000E */  beql  $at, $zero, .L7F0CF920
/* 104418 7F0CF8E8 8FAE0550 */   lw    $t6, 0x550($sp)
/* 10441C 7F0CF8EC 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF8F0:
/* 104420 7F0CF8F0 8D420000 */  lw    $v0, ($t2)
/* 104424 7F0CF8F4 00627821 */  addu  $t7, $v1, $v0
/* 104428 7F0CF8F8 91F90000 */  lbu   $t9, ($t7)
/* 10442C 7F0CF8FC 8FAF0548 */  lw    $t7, 0x548($sp)
/* 104430 7F0CF900 244E0001 */  addiu $t6, $v0, 1
/* 104434 7F0CF904 0119C004 */  sllv  $t8, $t9, $t0
/* 104438 7F0CF908 25080008 */  addiu $t0, $t0, 8
/* 10443C 7F0CF90C 010F082B */  sltu  $at, $t0, $t7
/* 104440 7F0CF910 01384825 */  or    $t1, $t1, $t8
/* 104444 7F0CF914 1420FFF6 */  bnez  $at, .L7F0CF8F0
/* 104448 7F0CF918 AD4E0000 */   sw    $t6, ($t2)
/* 10444C 7F0CF91C 8FAE0550 */  lw    $t6, 0x550($sp)
.L7F0CF920:
/* 104450 7F0CF920 012BC824 */  and   $t9, $t1, $t3
/* 104454 7F0CF924 0019C0C0 */  sll   $t8, $t9, 3
/* 104458 7F0CF928 030E7821 */  addu  $t7, $t8, $t6
/* 10445C 7F0CF92C AFAF054C */  sw    $t7, 0x54c($sp)
/* 104460 7F0CF930 91E40001 */  lbu   $a0, 1($t7)
/* 104464 7F0CF934 0005C880 */  sll   $t9, $a1, 2
/* 104468 7F0CF938 0219C021 */  addu  $t8, $s0, $t9
/* 10446C 7F0CF93C 00894806 */  srlv  $t1, $t1, $a0
/* 104470 7F0CF940 01044023 */  subu  $t0, $t0, $a0
/* 104474 7F0CF944 95E40004 */  lhu   $a0, 4($t7)
/* 104478 7F0CF948 2C810010 */  sltiu $at, $a0, 0x10
/* 10447C 7F0CF94C 10200005 */  beqz  $at, .L7F0CF964
/* 104480 7F0CF950 00000000 */   nop   
/* 104484 7F0CF954 00803025 */  move  $a2, $a0
/* 104488 7F0CF958 AF040000 */  sw    $a0, ($t8)
/* 10448C 7F0CF95C 10000062 */  b     .L7F0CFAE8
/* 104490 7F0CF960 24A50001 */   addiu $a1, $a1, 1
.L7F0CF964:
/* 104494 7F0CF964 148C0020 */  bne   $a0, $t4, .L7F0CF9E8
/* 104498 7F0CF968 2D010002 */   sltiu $at, $t0, 2
/* 10449C 7F0CF96C 1020000C */  beqz  $at, .L7F0CF9A0
/* 1044A0 7F0CF970 3C038009 */   lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 1044A4 7F0CF974 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CF978:
/* 1044A8 7F0CF978 8D420000 */  lw    $v0, ($t2)
/* 1044AC 7F0CF97C 00627021 */  addu  $t6, $v1, $v0
/* 1044B0 7F0CF980 91CF0000 */  lbu   $t7, ($t6)
/* 1044B4 7F0CF984 24580001 */  addiu $t8, $v0, 1
/* 1044B8 7F0CF988 AD580000 */  sw    $t8, ($t2)
/* 1044BC 7F0CF98C 010FC804 */  sllv  $t9, $t7, $t0
/* 1044C0 7F0CF990 25080008 */  addiu $t0, $t0, 8
/* 1044C4 7F0CF994 2D010002 */  sltiu $at, $t0, 2
/* 1044C8 7F0CF998 1420FFF7 */  bnez  $at, .L7F0CF978
/* 1044CC 7F0CF99C 01394825 */   or    $t1, $t1, $t9
.L7F0CF9A0:
/* 1044D0 7F0CF9A0 31240003 */  andi  $a0, $t1, 3
/* 1044D4 7F0CF9A4 24840003 */  addiu $a0, $a0, 3
/* 1044D8 7F0CF9A8 00801825 */  move  $v1, $a0
/* 1044DC 7F0CF9AC 00097082 */  srl   $t6, $t1, 2
/* 1044E0 7F0CF9B0 01C04825 */  move  $t1, $t6
/* 1044E4 7F0CF9B4 2508FFFE */  addiu $t0, $t0, -2
/* 1044E8 7F0CF9B8 1080004B */  beqz  $a0, .L7F0CFAE8
/* 1044EC 7F0CF9BC 2484FFFF */   addiu $a0, $a0, -1
/* 1044F0 7F0CF9C0 00057880 */  sll   $t7, $a1, 2
/* 1044F4 7F0CF9C4 020F1021 */  addu  $v0, $s0, $t7
.L7F0CF9C8:
/* 1044F8 7F0CF9C8 00801825 */  move  $v1, $a0
/* 1044FC 7F0CF9CC AC460000 */  sw    $a2, ($v0)
/* 104500 7F0CF9D0 24A50001 */  addiu $a1, $a1, 1
/* 104504 7F0CF9D4 24420004 */  addiu $v0, $v0, 4
/* 104508 7F0CF9D8 1480FFFB */  bnez  $a0, .L7F0CF9C8
/* 10450C 7F0CF9DC 2484FFFF */   addiu $a0, $a0, -1
/* 104510 7F0CF9E0 10000042 */  b     .L7F0CFAEC
/* 104514 7F0CF9E4 00A7082B */   sltu  $at, $a1, $a3
.L7F0CF9E8:
/* 104518 7F0CF9E8 148D0021 */  bne   $a0, $t5, .L7F0CFA70
/* 10451C 7F0CF9EC 00003025 */   move  $a2, $zero
/* 104520 7F0CF9F0 2D010003 */  sltiu $at, $t0, 3
/* 104524 7F0CF9F4 1020000C */  beqz  $at, .L7F0CFA28
/* 104528 7F0CF9F8 3C038009 */   lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 10452C 7F0CF9FC 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CFA00:
/* 104530 7F0CFA00 8D420000 */  lw    $v0, ($t2)
/* 104534 7F0CFA04 0062C821 */  addu  $t9, $v1, $v0
/* 104538 7F0CFA08 93380000 */  lbu   $t8, ($t9)
/* 10453C 7F0CFA0C 244F0001 */  addiu $t7, $v0, 1
/* 104540 7F0CFA10 AD4F0000 */  sw    $t7, ($t2)
/* 104544 7F0CFA14 01187004 */  sllv  $t6, $t8, $t0
/* 104548 7F0CFA18 25080008 */  addiu $t0, $t0, 8
/* 10454C 7F0CFA1C 2D010003 */  sltiu $at, $t0, 3
/* 104550 7F0CFA20 1420FFF7 */  bnez  $at, .L7F0CFA00
/* 104554 7F0CFA24 012E4825 */   or    $t1, $t1, $t6
.L7F0CFA28:
/* 104558 7F0CFA28 31240007 */  andi  $a0, $t1, 7
/* 10455C 7F0CFA2C 24840003 */  addiu $a0, $a0, 3
/* 104560 7F0CFA30 00801825 */  move  $v1, $a0
/* 104564 7F0CFA34 0009C8C2 */  srl   $t9, $t1, 3
/* 104568 7F0CFA38 03204825 */  move  $t1, $t9
/* 10456C 7F0CFA3C 2508FFFD */  addiu $t0, $t0, -3
/* 104570 7F0CFA40 10800029 */  beqz  $a0, .L7F0CFAE8
/* 104574 7F0CFA44 2484FFFF */   addiu $a0, $a0, -1
/* 104578 7F0CFA48 0005C080 */  sll   $t8, $a1, 2
/* 10457C 7F0CFA4C 02181021 */  addu  $v0, $s0, $t8
.L7F0CFA50:
/* 104580 7F0CFA50 00801825 */  move  $v1, $a0
/* 104584 7F0CFA54 AC400000 */  sw    $zero, ($v0)
/* 104588 7F0CFA58 24A50001 */  addiu $a1, $a1, 1
/* 10458C 7F0CFA5C 24420004 */  addiu $v0, $v0, 4
/* 104590 7F0CFA60 1480FFFB */  bnez  $a0, .L7F0CFA50
/* 104594 7F0CFA64 2484FFFF */   addiu $a0, $a0, -1
/* 104598 7F0CFA68 10000020 */  b     .L7F0CFAEC
/* 10459C 7F0CFA6C 00A7082B */   sltu  $at, $a1, $a3
.L7F0CFA70:
/* 1045A0 7F0CFA70 2D010007 */  sltiu $at, $t0, 7
/* 1045A4 7F0CFA74 1020000C */  beqz  $at, .L7F0CFAA8
/* 1045A8 7F0CFA78 3C038009 */   lui   $v1, %hi(dword_CODE_bss_8008D350)
/* 1045AC 7F0CFA7C 8C63D350 */  lw    $v1, %lo(dword_CODE_bss_8008D350)($v1)
.L7F0CFA80:
/* 1045B0 7F0CFA80 8D420000 */  lw    $v0, ($t2)
/* 1045B4 7F0CFA84 00627021 */  addu  $t6, $v1, $v0
/* 1045B8 7F0CFA88 91CF0000 */  lbu   $t7, ($t6)
/* 1045BC 7F0CFA8C 24580001 */  addiu $t8, $v0, 1
/* 1045C0 7F0CFA90 AD580000 */  sw    $t8, ($t2)
/* 1045C4 7F0CFA94 010FC804 */  sllv  $t9, $t7, $t0
/* 1045C8 7F0CFA98 25080008 */  addiu $t0, $t0, 8
/* 1045CC 7F0CFA9C 2D010007 */  sltiu $at, $t0, 7
/* 1045D0 7F0CFAA0 1420FFF7 */  bnez  $at, .L7F0CFA80
/* 1045D4 7F0CFAA4 01394825 */   or    $t1, $t1, $t9
.L7F0CFAA8:
/* 1045D8 7F0CFAA8 3124007F */  andi  $a0, $t1, 0x7f
/* 1045DC 7F0CFAAC 2484000B */  addiu $a0, $a0, 0xb
/* 1045E0 7F0CFAB0 00801825 */  move  $v1, $a0
/* 1045E4 7F0CFAB4 000971C2 */  srl   $t6, $t1, 7
/* 1045E8 7F0CFAB8 01C04825 */  move  $t1, $t6
/* 1045EC 7F0CFABC 2508FFF9 */  addiu $t0, $t0, -7
/* 1045F0 7F0CFAC0 10800009 */  beqz  $a0, .L7F0CFAE8
/* 1045F4 7F0CFAC4 2484FFFF */   addiu $a0, $a0, -1
/* 1045F8 7F0CFAC8 00057880 */  sll   $t7, $a1, 2
/* 1045FC 7F0CFACC 020F1021 */  addu  $v0, $s0, $t7
.L7F0CFAD0:
/* 104600 7F0CFAD0 00801825 */  move  $v1, $a0
/* 104604 7F0CFAD4 AC400000 */  sw    $zero, ($v0)
/* 104608 7F0CFAD8 24A50001 */  addiu $a1, $a1, 1
/* 10460C 7F0CFADC 24420004 */  addiu $v0, $v0, 4
/* 104610 7F0CFAE0 1480FFFB */  bnez  $a0, .L7F0CFAD0
/* 104614 7F0CFAE4 2484FFFF */   addiu $a0, $a0, -1
.L7F0CFAE8:
/* 104618 7F0CFAE8 00A7082B */  sltu  $at, $a1, $a3
.L7F0CFAEC:
/* 10461C 7F0CFAEC 5420FF7B */  bnezl $at, .L7F0CF8DC
/* 104620 7F0CFAF0 8FAE0548 */   lw    $t6, 0x548($sp)
.L7F0CFAF4:
/* 104624 7F0CFAF4 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D364)
/* 104628 7F0CFAF8 3C198005 */  lui   $t9, %hi(D_8004E9D4) 
/* 10462C 7F0CFAFC 8F39E9D4 */  lw    $t9, %lo(D_8004E9D4)($t9)
/* 104630 7F0CFB00 AC29D364 */  sw    $t1, %lo(dword_CODE_bss_8008D364)($at)
/* 104634 7F0CFB04 3C188005 */  lui   $t8, %hi(D_8004E934) 
/* 104638 7F0CFB08 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D368)
/* 10463C 7F0CFB0C 2718E934 */  addiu $t8, %lo(D_8004E934) # addiu $t8, $t8, -0x16cc
/* 104640 7F0CFB10 3C078005 */  lui   $a3, %hi(D_8004E8F4)
/* 104644 7F0CFB14 27AE0550 */  addiu $t6, $sp, 0x550
/* 104648 7F0CFB18 27AF0548 */  addiu $t7, $sp, 0x548
/* 10464C 7F0CFB1C AC28D368 */  sw    $t0, %lo(dword_CODE_bss_8008D368)($at)
/* 104650 7F0CFB20 AFAF0018 */  sw    $t7, 0x18($sp)
/* 104654 7F0CFB24 AFAE0014 */  sw    $t6, 0x14($sp)
/* 104658 7F0CFB28 24E7E8F4 */  addiu $a3, %lo(D_8004E8F4) # addiu $a3, $a3, -0x170c
/* 10465C 7F0CFB2C AFB80010 */  sw    $t8, 0x10($sp)
/* 104660 7F0CFB30 02002025 */  move  $a0, $s0
/* 104664 7F0CFB34 8FA5053C */  lw    $a1, 0x53c($sp)
/* 104668 7F0CFB38 24060101 */  li    $a2, 257
/* 10466C 7F0CFB3C 0FC33A2C */  jal   sub_GAME_7F0CE8B0
/* 104670 7F0CFB40 AFB90548 */   sw    $t9, 0x548($sp)
/* 104674 7F0CFB44 3C198005 */  lui   $t9, %hi(D_8004E9D8) 
/* 104678 7F0CFB48 8F39E9D8 */  lw    $t9, %lo(D_8004E9D8)($t9)
/* 10467C 7F0CFB4C 8FB8053C */  lw    $t8, 0x53c($sp)
/* 104680 7F0CFB50 3C0F8005 */  lui   $t7, %hi(D_8004E990) 
/* 104684 7F0CFB54 AFB90544 */  sw    $t9, 0x544($sp)
/* 104688 7F0CFB58 00187080 */  sll   $t6, $t8, 2
/* 10468C 7F0CFB5C 27B80544 */  addiu $t8, $sp, 0x544
/* 104690 7F0CFB60 27B9054C */  addiu $t9, $sp, 0x54c
/* 104694 7F0CFB64 25EFE990 */  addiu $t7, %lo(D_8004E990) # addiu $t7, $t7, -0x1670
/* 104698 7F0CFB68 3C078005 */  lui   $a3, %hi(D_8004E954)
/* 10469C 7F0CFB6C 24E7E954 */  addiu $a3, %lo(D_8004E954) # addiu $a3, $a3, -0x16ac
/* 1046A0 7F0CFB70 AFAF0010 */  sw    $t7, 0x10($sp)
/* 1046A4 7F0CFB74 AFB90014 */  sw    $t9, 0x14($sp)
/* 1046A8 7F0CFB78 AFB80018 */  sw    $t8, 0x18($sp)
/* 1046AC 7F0CFB7C 020E2021 */  addu  $a0, $s0, $t6
/* 1046B0 7F0CFB80 8FA50538 */  lw    $a1, 0x538($sp)
/* 1046B4 7F0CFB84 0FC33A2C */  jal   sub_GAME_7F0CE8B0
/* 1046B8 7F0CFB88 00003025 */   move  $a2, $zero
/* 1046BC 7F0CFB8C 8FA40550 */  lw    $a0, 0x550($sp)
/* 1046C0 7F0CFB90 8FA5054C */  lw    $a1, 0x54c($sp)
/* 1046C4 7F0CFB94 8FA60548 */  lw    $a2, 0x548($sp)
/* 1046C8 7F0CFB98 0FC33BBC */  jal   sub_GAME_7F0CEEF0
/* 1046CC 7F0CFB9C 8FA70544 */   lw    $a3, 0x544($sp)
/* 1046D0 7F0CFBA0 8FBF002C */  lw    $ra, 0x2c($sp)
/* 1046D4 7F0CFBA4 8FB00028 */  lw    $s0, 0x28($sp)
/* 1046D8 7F0CFBA8 27BD0568 */  addiu $sp, $sp, 0x568
/* 1046DC 7F0CFBAC 03E00008 */  jr    $ra
/* 1046E0 7F0CFBB0 00001025 */   move  $v0, $zero
)
#endif





#ifdef NONMATCHING
void select_zlib_decompression_routine(void *arg0, s32 arg2)
{
    s32 temp_v1;
    u32 temp_a1;
    u32 temp_v1_2;
    u32 temp_t3;
    u32 temp_v1_3;
    u32 temp_a1_2;
    s32 temp_v0;
    s32 phi_v1;
    u32 phi_a1;
    s32 phi_v1_2;
    u32 phi_v1_3;
    u32 phi_a1_2;
    u32 phi_v1_4;
    s32 phi_a2;
    u32 phi_a1_3;
    u32 phi_a1_4;

    phi_a1 = dword_CODE_bss_8008D364;
    phi_v1_2 = dword_CODE_bss_8008D368;
    phi_a2 = arg2;
    if (dword_CODE_bss_8008D368 == 0)
    {
        phi_v1 = dword_CODE_bss_8008D368;
        phi_a1_3 = dword_CODE_bss_8008D364;
block_2:
        dword_CODE_bss_8008D358 = (s32) (dword_CODE_bss_8008D358 + 1);
        temp_v1 = (phi_v1 + 8);
        temp_a1 = (phi_a1_3 | (*(dword_CODE_bss_8008D350 + dword_CODE_bss_8008D358) << phi_v1));
        phi_v1 = temp_v1;
        phi_a1 = temp_a1;
        phi_v1_2 = temp_v1;
        phi_a1_3 = temp_a1;
        phi_a2 = dword_CODE_bss_8008D350;
        if (temp_v1 == 0)
        {
            goto block_2;
        }
    }
    temp_v1_2 = (phi_v1_2 + -1);
    temp_t3 = ((u32) phi_a1 >> 1);
    *arg0 = (s32) (phi_a1 & 1);
    phi_a1_2 = temp_t3;
    phi_v1_4 = temp_v1_2;
    if (temp_v1_2 < 2U)
    {
        phi_v1_3 = temp_v1_2;
        phi_a1_4 = temp_t3;
block_5:
        dword_CODE_bss_8008D358 = (s32) (dword_CODE_bss_8008D358 + 1);
        temp_v1_3 = (phi_v1_3 + 8);
        temp_a1_2 = (phi_a1_4 | (*(dword_CODE_bss_8008D350 + dword_CODE_bss_8008D358) << phi_v1_3));
        phi_v1_3 = temp_v1_3;
        phi_a1_2 = temp_a1_2;
        phi_v1_4 = temp_v1_3;
        phi_a2 = dword_CODE_bss_8008D350;
        phi_a1_4 = temp_a1_2;
        if (temp_v1_3 < 2U)
        {
            goto block_5;
        }
    }
    temp_v0 = (phi_a1_2 & 3);
    dword_CODE_bss_8008D364 = (u32) ((u32) phi_a1_2 >> 2);
    dword_CODE_bss_8008D368 = (s32) (phi_v1_4 + -2);
    if (temp_v0 == 2)
    {
        return zlib_decompressor_type2(&dword_CODE_bss_8008D358, phi_a1_2, phi_a2, arg0);
    }
    if (temp_v0 == 0)
    {
        return zlib_decompressor_type0(&dword_CODE_bss_8008D358, phi_a1_2, phi_a2, arg0);
    }
    if (temp_v0 == 1)
    {
        return zlib_decompressor_type1(&dword_CODE_bss_8008D358, phi_a1_2, phi_a2, arg0);
    }
    return 2;
}
#else
GLOBAL_ASM(
.text
glabel select_zlib_decompression_routine
/* 1046E4 7F0CFBB4 3C098009 */  lui   $t1, %hi(dword_CODE_bss_8008D368) 
/* 1046E8 7F0CFBB8 2529D368 */  addiu $t1, %lo(dword_CODE_bss_8008D368) # addiu $t1, $t1, -0x2c98
/* 1046EC 7F0CFBBC 8D230000 */  lw    $v1, ($t1)
/* 1046F0 7F0CFBC0 3C088009 */  lui   $t0, %hi(dword_CODE_bss_8008D364) 
/* 1046F4 7F0CFBC4 2508D364 */  addiu $t0, %lo(dword_CODE_bss_8008D364) # addiu $t0, $t0, -0x2c9c
/* 1046F8 7F0CFBC8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1046FC 7F0CFBCC AFBF0014 */  sw    $ra, 0x14($sp)
/* 104700 7F0CFBD0 00803825 */  move  $a3, $a0
/* 104704 7F0CFBD4 1460000E */  bnez  $v1, .L7F0CFC10
/* 104708 7F0CFBD8 8D050000 */   lw    $a1, ($t0)
/* 10470C 7F0CFBDC 3C068009 */  lui   $a2, %hi(dword_CODE_bss_8008D350)
/* 104710 7F0CFBE0 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008D358)
/* 104714 7F0CFBE4 2484D358 */  addiu $a0, %lo(dword_CODE_bss_8008D358) # addiu $a0, $a0, -0x2ca8
/* 104718 7F0CFBE8 8CC6D350 */  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CFBEC:
/* 10471C 7F0CFBEC 8C820000 */  lw    $v0, ($a0)
/* 104720 7F0CFBF0 00C27021 */  addu  $t6, $a2, $v0
/* 104724 7F0CFBF4 91CF0000 */  lbu   $t7, ($t6)
/* 104728 7F0CFBF8 24590001 */  addiu $t9, $v0, 1
/* 10472C 7F0CFBFC AC990000 */  sw    $t9, ($a0)
/* 104730 7F0CFC00 006FC004 */  sllv  $t8, $t7, $v1
/* 104734 7F0CFC04 24630008 */  addiu $v1, $v1, 8
/* 104738 7F0CFC08 1060FFF8 */  beqz  $v1, .L7F0CFBEC
/* 10473C 7F0CFC0C 00B82825 */   or    $a1, $a1, $t8
.L7F0CFC10:
/* 104740 7F0CFC10 2463FFFF */  addiu $v1, $v1, -1
/* 104744 7F0CFC14 3C048009 */  lui   $a0, %hi(dword_CODE_bss_8008D358)
/* 104748 7F0CFC18 30AA0001 */  andi  $t2, $a1, 1
/* 10474C 7F0CFC1C 00055842 */  srl   $t3, $a1, 1
/* 104750 7F0CFC20 2C610002 */  sltiu $at, $v1, 2
/* 104754 7F0CFC24 2484D358 */  addiu $a0, %lo(dword_CODE_bss_8008D358) # addiu $a0, $a0, -0x2ca8
/* 104758 7F0CFC28 ACEA0000 */  sw    $t2, ($a3)
/* 10475C 7F0CFC2C 1020000D */  beqz  $at, .L7F0CFC64
/* 104760 7F0CFC30 01602825 */   move  $a1, $t3
/* 104764 7F0CFC34 3C068009 */  lui   $a2, %hi(dword_CODE_bss_8008D350)
/* 104768 7F0CFC38 8CC6D350 */  lw    $a2, %lo(dword_CODE_bss_8008D350)($a2)
.L7F0CFC3C:
/* 10476C 7F0CFC3C 8C820000 */  lw    $v0, ($a0)
/* 104770 7F0CFC40 00C26021 */  addu  $t4, $a2, $v0
/* 104774 7F0CFC44 918D0000 */  lbu   $t5, ($t4)
/* 104778 7F0CFC48 244F0001 */  addiu $t7, $v0, 1
/* 10477C 7F0CFC4C AC8F0000 */  sw    $t7, ($a0)
/* 104780 7F0CFC50 006D7004 */  sllv  $t6, $t5, $v1
/* 104784 7F0CFC54 24630008 */  addiu $v1, $v1, 8
/* 104788 7F0CFC58 2C610002 */  sltiu $at, $v1, 2
/* 10478C 7F0CFC5C 1420FFF7 */  bnez  $at, .L7F0CFC3C
/* 104790 7F0CFC60 00AE2825 */   or    $a1, $a1, $t6
.L7F0CFC64:
/* 104794 7F0CFC64 30A20003 */  andi  $v0, $a1, 3
/* 104798 7F0CFC68 0005C082 */  srl   $t8, $a1, 2
/* 10479C 7F0CFC6C 2463FFFE */  addiu $v1, $v1, -2
/* 1047A0 7F0CFC70 24010002 */  li    $at, 2
/* 1047A4 7F0CFC74 AD180000 */  sw    $t8, ($t0)
/* 1047A8 7F0CFC78 14410005 */  bne   $v0, $at, .L7F0CFC90
/* 1047AC 7F0CFC7C AD230000 */   sw    $v1, ($t1)
/* 1047B0 7F0CFC80 0FC33DA4 */  jal   zlib_decompressor_type2
/* 1047B4 7F0CFC84 00000000 */   nop   
/* 1047B8 7F0CFC88 1000000F */  b     .L7F0CFCC8
/* 1047BC 7F0CFC8C 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0CFC90:
/* 1047C0 7F0CFC90 14400005 */  bnez  $v0, .L7F0CFCA8
/* 1047C4 7F0CFC94 24010001 */   li    $at, 1
/* 1047C8 7F0CFC98 0FC33CE3 */  jal   zlib_decompressor_type0
/* 1047CC 7F0CFC9C 00000000 */   nop   
/* 1047D0 7F0CFCA0 10000009 */  b     .L7F0CFCC8
/* 1047D4 7F0CFCA4 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0CFCA8:
/* 1047D8 7F0CFCA8 54410006 */  bnel  $v0, $at, .L7F0CFCC4
/* 1047DC 7F0CFCAC 24020002 */   li    $v0, 2
/* 1047E0 7F0CFCB0 0FC33D4A */  jal   zlib_decompressor_type1
/* 1047E4 7F0CFCB4 00000000 */   nop   
/* 1047E8 7F0CFCB8 10000003 */  b     .L7F0CFCC8
/* 1047EC 7F0CFCBC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 1047F0 7F0CFCC0 24020002 */  li    $v0, 2
.L7F0CFCC4:
/* 1047F4 7F0CFCC4 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0CFCC8:
/* 1047F8 7F0CFCC8 27BD0018 */  addiu $sp, $sp, 0x18
/* 1047FC 7F0CFCCC 03E00008 */  jr    $ra
/* 104800 7F0CFCD0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void loop_to_decompress_entire_file(void)
{
    s32 sp34;
    ? temp_ret;
    u32 temp_t7;
    u32 phi_s1;
    u32 phi_v1;

    dword_CODE_bss_8008D35C = 0;
    dword_CODE_bss_8008D368 = 0U;
    dword_CODE_bss_8008D364 = 0;
    phi_s1 = 0U;
block_1:
    dword_CODE_bss_8008D36C = 0U;
    temp_ret = select_zlib_decompression_routine(&sp34);
    if (temp_ret != 0)
    {
        return temp_ret;
    }
    phi_s1 = phi_s1;
    if ((u32) phi_s1 < (u32) dword_CODE_bss_8008D36C)
    {
        phi_s1 = dword_CODE_bss_8008D36C;
    }
    if (sp34 == 0)
    {
        goto block_1;
    }
    phi_v1 = dword_CODE_bss_8008D368;
    if ((u32) dword_CODE_bss_8008D368 >= 8U)
    {
block_7:
        temp_t7 = (phi_v1 + -8);
        dword_CODE_bss_8008D368 = temp_t7;
        dword_CODE_bss_8008D358 = (s32) (dword_CODE_bss_8008D358 + -1);
        phi_v1 = temp_t7;
        if (temp_t7 >= 8U)
        {
            goto block_7;
        }
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel loop_to_decompress_entire_file
/* 104804 7F0CFCD4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 104808 7F0CFCD8 AFB2001C */  sw    $s2, 0x1c($sp)
/* 10480C 7F0CFCDC 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D35C)
/* 104810 7F0CFCE0 3C128009 */  lui   $s2, %hi(dword_CODE_bss_8008D368)
/* 104814 7F0CFCE4 AC20D35C */  sw    $zero, %lo(dword_CODE_bss_8008D35C)($at)
/* 104818 7F0CFCE8 2652D368 */  addiu $s2, %lo(dword_CODE_bss_8008D368) # addiu $s2, $s2, -0x2c98
/* 10481C 7F0CFCEC AFB00014 */  sw    $s0, 0x14($sp)
/* 104820 7F0CFCF0 AFB30020 */  sw    $s3, 0x20($sp)
/* 104824 7F0CFCF4 AFB10018 */  sw    $s1, 0x18($sp)
/* 104828 7F0CFCF8 AE400000 */  sw    $zero, ($s2)
/* 10482C 7F0CFCFC 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008D364)
/* 104830 7F0CFD00 3C108009 */  lui   $s0, %hi(dword_CODE_bss_8008D36C)
/* 104834 7F0CFD04 AFBF0024 */  sw    $ra, 0x24($sp)
/* 104838 7F0CFD08 AC20D364 */  sw    $zero, %lo(dword_CODE_bss_8008D364)($at)
/* 10483C 7F0CFD0C 00008825 */  move  $s1, $zero
/* 104840 7F0CFD10 2610D36C */  addiu $s0, %lo(dword_CODE_bss_8008D36C) # addiu $s0, $s0, -0x2c94
/* 104844 7F0CFD14 27B30034 */  addiu $s3, $sp, 0x34
/* 104848 7F0CFD18 AE000000 */  sw    $zero, ($s0)
.L7F0CFD1C:
/* 10484C 7F0CFD1C 0FC33EED */  jal   select_zlib_decompression_routine
/* 104850 7F0CFD20 02602025 */   move  $a0, $s3
/* 104854 7F0CFD24 10400003 */  beqz  $v0, .L7F0CFD34
/* 104858 7F0CFD28 8FAE0034 */   lw    $t6, 0x34($sp)
/* 10485C 7F0CFD2C 10000018 */  b     .L7F0CFD90
/* 104860 7F0CFD30 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F0CFD34:
/* 104864 7F0CFD34 8E020000 */  lw    $v0, ($s0)
/* 104868 7F0CFD38 0222082B */  sltu  $at, $s1, $v0
/* 10486C 7F0CFD3C 10200002 */  beqz  $at, .L7F0CFD48
/* 104870 7F0CFD40 00000000 */   nop   
/* 104874 7F0CFD44 00408825 */  move  $s1, $v0
.L7F0CFD48:
/* 104878 7F0CFD48 51C0FFF4 */  beql  $t6, $zero, .L7F0CFD1C
/* 10487C 7F0CFD4C AE000000 */   sw    $zero, ($s0)
/* 104880 7F0CFD50 8E430000 */  lw    $v1, ($s2)
/* 104884 7F0CFD54 3C028009 */  lui   $v0, %hi(dword_CODE_bss_8008D358)
/* 104888 7F0CFD58 2442D358 */  addiu $v0, %lo(dword_CODE_bss_8008D358) # addiu $v0, $v0, -0x2ca8
/* 10488C 7F0CFD5C 2C610008 */  sltiu $at, $v1, 8
/* 104890 7F0CFD60 5420000A */  bnezl $at, .L7F0CFD8C
/* 104894 7F0CFD64 00001025 */   move  $v0, $zero
.L7F0CFD68:
/* 104898 7F0CFD68 8C580000 */  lw    $t8, ($v0)
/* 10489C 7F0CFD6C 246FFFF8 */  addiu $t7, $v1, -8
/* 1048A0 7F0CFD70 2DE10008 */  sltiu $at, $t7, 8
/* 1048A4 7F0CFD74 2719FFFF */  addiu $t9, $t8, -1
/* 1048A8 7F0CFD78 AE4F0000 */  sw    $t7, ($s2)
/* 1048AC 7F0CFD7C AC590000 */  sw    $t9, ($v0)
/* 1048B0 7F0CFD80 1020FFF9 */  beqz  $at, .L7F0CFD68
/* 1048B4 7F0CFD84 01E01825 */   move  $v1, $t7
/* 1048B8 7F0CFD88 00001025 */  move  $v0, $zero
.L7F0CFD8C:
/* 1048BC 7F0CFD8C 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F0CFD90:
/* 1048C0 7F0CFD90 8FB00014 */  lw    $s0, 0x14($sp)
/* 1048C4 7F0CFD94 8FB10018 */  lw    $s1, 0x18($sp)
/* 1048C8 7F0CFD98 8FB2001C */  lw    $s2, 0x1c($sp)
/* 1048CC 7F0CFD9C 8FB30020 */  lw    $s3, 0x20($sp)
/* 1048D0 7F0CFDA0 03E00008 */  jr    $ra
/* 1048D4 7F0CFDA4 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif



