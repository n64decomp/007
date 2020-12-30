#include "ultra64.h"
#include "libultra/controller.h"
//0x800655a0
char _MotorStopData[256];
//800656a0
char _MotorStartData[256];
//800657a0 
u8 _motorstopbuf[32];
//800657c0
u8 _motorstartbuf[32];




#ifdef NONMATCHING
s32 osMotorStop(OSPfs *pfs)
{

}
#else
GLOBAL_ASM(
.text
glabel osMotorStop
/* 00D580 7000C980 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 00D584 7000C984 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D588 7000C988 0C005798 */  jal   __osSiGetAccess
/* 00D58C 7000C98C AFA40050 */   sw    $a0, 0x50($sp)
/* 00D590 7000C990 8FAF0050 */  lw    $t7, 0x50($sp)
/* 00D594 7000C994 240E0003 */  li    $t6, 3
/* 00D598 7000C998 3C018006 */  lui   $at, %hi(__osContLastCmd)
/* 00D59C 7000C99C A02E7CE0 */  sb    $t6, %lo(__osContLastCmd)($at)
/* 00D5A0 7000C9A0 8DF80008 */  lw    $t8, 8($t7)
/* 00D5A4 7000C9A4 3C088006 */  lui   $t0, %hi(_MotorStopData) 
/* 00D5A8 7000C9A8 250855A0 */  addiu $t0, %lo(_MotorStopData) # addiu $t0, $t0, 0x55a0
/* 00D5AC 7000C9AC 0018C980 */  sll   $t9, $t8, 6
/* 00D5B0 7000C9B0 03282821 */  addu  $a1, $t9, $t0
/* 00D5B4 7000C9B4 0C0057B4 */  jal   __osSiRawStartDma
/* 00D5B8 7000C9B8 24040001 */   li    $a0, 1
/* 00D5BC 7000C9BC 8FA90050 */  lw    $t1, 0x50($sp)
/* 00D5C0 7000C9C0 00002825 */  move  $a1, $zero
/* 00D5C4 7000C9C4 24060001 */  li    $a2, 1
/* 00D5C8 7000C9C8 0C003774 */  jal   osRecvMesg
/* 00D5CC 7000C9CC 8D240004 */   lw    $a0, 4($t1)
/* 00D5D0 7000C9D0 3C058006 */  lui   $a1, %hi(__osPfsPifRam)
/* 00D5D4 7000C9D4 24A57D70 */  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
/* 00D5D8 7000C9D8 0C0057B4 */  jal   __osSiRawStartDma
/* 00D5DC 7000C9DC 00002025 */   move  $a0, $zero
/* 00D5E0 7000C9E0 8FAA0050 */  lw    $t2, 0x50($sp)
/* 00D5E4 7000C9E4 00002825 */  move  $a1, $zero
/* 00D5E8 7000C9E8 24060001 */  li    $a2, 1
/* 00D5EC 7000C9EC 0C003774 */  jal   osRecvMesg
/* 00D5F0 7000C9F0 8D440004 */   lw    $a0, 4($t2)
/* 00D5F4 7000C9F4 8FAB0050 */  lw    $t3, 0x50($sp)
/* 00D5F8 7000C9F8 3C038006 */  lui   $v1, %hi(__osPfsPifRam)
/* 00D5FC 7000C9FC 24637D70 */  addiu $v1, %lo(__osPfsPifRam) # addiu $v1, $v1, 0x7d70
/* 00D600 7000CA00 8D640008 */  lw    $a0, 8($t3)
/* 00D604 7000CA04 27AC001C */  addiu $t4, $sp, 0x1c
/* 00D608 7000CA08 50800008 */  beql  $a0, $zero, .L7000CA2C
/* 00D60C 7000CA0C 00607825 */   move  $t7, $v1
/* 00D610 7000CA10 18800005 */  blez  $a0, .L7000CA28
/* 00D614 7000CA14 00001025 */   move  $v0, $zero
.L7000CA18:
/* 00D618 7000CA18 24420001 */  addiu $v0, $v0, 1
/* 00D61C 7000CA1C 0044082A */  slt   $at, $v0, $a0
/* 00D620 7000CA20 1420FFFD */  bnez  $at, .L7000CA18
/* 00D624 7000CA24 24630001 */   addiu $v1, $v1, 1
.L7000CA28:
/* 00D628 7000CA28 00607825 */  move  $t7, $v1
.L7000CA2C:
/* 00D62C 7000CA2C 246E0024 */  addiu $t6, $v1, 0x24
.L7000CA30:
/* 00D630 7000CA30 89E10000 */  lwl   $at, ($t7)
/* 00D634 7000CA34 99E10003 */  lwr   $at, 3($t7)
/* 00D638 7000CA38 25EF000C */  addiu $t7, $t7, 0xc
/* 00D63C 7000CA3C 258C000C */  addiu $t4, $t4, 0xc
/* 00D640 7000CA40 AD81FFF4 */  sw    $at, -0xc($t4)
/* 00D644 7000CA44 89E1FFF8 */  lwl   $at, -8($t7)
/* 00D648 7000CA48 99E1FFFB */  lwr   $at, -5($t7)
/* 00D64C 7000CA4C AD81FFF8 */  sw    $at, -8($t4)
/* 00D650 7000CA50 89E1FFFC */  lwl   $at, -4($t7)
/* 00D654 7000CA54 99E1FFFF */  lwr   $at, -1($t7)
/* 00D658 7000CA58 15EEFFF5 */  bne   $t7, $t6, .L7000CA30
/* 00D65C 7000CA5C AD81FFFC */   sw    $at, -4($t4)
/* 00D660 7000CA60 89E10000 */  lwl   $at, ($t7)
/* 00D664 7000CA64 99E10003 */  lwr   $at, 3($t7)
/* 00D668 7000CA68 AD810000 */  sw    $at, ($t4)
/* 00D66C 7000CA6C 93A2001E */  lbu   $v0, 0x1e($sp)
/* 00D670 7000CA70 93A80042 */  lbu   $t0, 0x42($sp)
/* 00D674 7000CA74 305800C0 */  andi  $t8, $v0, 0xc0
/* 00D678 7000CA78 00182103 */  sra   $a0, $t8, 4
/* 00D67C 7000CA7C 14800004 */  bnez  $a0, .L7000CA90
/* 00D680 7000CA80 00000000 */   nop   
/* 00D684 7000CA84 11000002 */  beqz  $t0, .L7000CA90
/* 00D688 7000CA88 00000000 */   nop   
/* 00D68C 7000CA8C 24040004 */  li    $a0, 4
.L7000CA90:
/* 00D690 7000CA90 0C0057A9 */  jal   __osSiRelAccess
/* 00D694 7000CA94 AFA40048 */   sw    $a0, 0x48($sp)
/* 00D698 7000CA98 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D69C 7000CA9C 8FA20048 */  lw    $v0, 0x48($sp)
/* 00D6A0 7000CAA0 27BD0050 */  addiu $sp, $sp, 0x50
/* 00D6A4 7000CAA4 03E00008 */  jr    $ra
/* 00D6A8 7000CAA8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
s32 osMotorStart(OSPfs *pfs)
{

}
#else
GLOBAL_ASM(
.text
glabel osMotorStart
/* 00D6AC 7000CAAC 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 00D6B0 7000CAB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00D6B4 7000CAB4 0C005798 */  jal   __osSiGetAccess
/* 00D6B8 7000CAB8 AFA40050 */   sw    $a0, 0x50($sp)
/* 00D6BC 7000CABC 8FAF0050 */  lw    $t7, 0x50($sp)
/* 00D6C0 7000CAC0 240E0003 */  li    $t6, 3
/* 00D6C4 7000CAC4 3C018006 */  lui   $at, %hi(__osContLastCmd)
/* 00D6C8 7000CAC8 A02E7CE0 */  sb    $t6, %lo(__osContLastCmd)($at)
/* 00D6CC 7000CACC 8DF80008 */  lw    $t8, 8($t7)
/* 00D6D0 7000CAD0 3C088006 */  lui   $t0, %hi(_MotorStartData) 
/* 00D6D4 7000CAD4 250856A0 */  addiu $t0, %lo(_MotorStartData) # addiu $t0, $t0, 0x56a0
/* 00D6D8 7000CAD8 0018C980 */  sll   $t9, $t8, 6
/* 00D6DC 7000CADC 03282821 */  addu  $a1, $t9, $t0
/* 00D6E0 7000CAE0 0C0057B4 */  jal   __osSiRawStartDma
/* 00D6E4 7000CAE4 24040001 */   li    $a0, 1
/* 00D6E8 7000CAE8 8FA90050 */  lw    $t1, 0x50($sp)
/* 00D6EC 7000CAEC 00002825 */  move  $a1, $zero
/* 00D6F0 7000CAF0 24060001 */  li    $a2, 1
/* 00D6F4 7000CAF4 0C003774 */  jal   osRecvMesg
/* 00D6F8 7000CAF8 8D240004 */   lw    $a0, 4($t1)
/* 00D6FC 7000CAFC 3C058006 */  lui   $a1, %hi(__osPfsPifRam)
/* 00D700 7000CB00 24A57D70 */  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
/* 00D704 7000CB04 0C0057B4 */  jal   __osSiRawStartDma
/* 00D708 7000CB08 00002025 */   move  $a0, $zero
/* 00D70C 7000CB0C 8FAA0050 */  lw    $t2, 0x50($sp)
/* 00D710 7000CB10 00002825 */  move  $a1, $zero
/* 00D714 7000CB14 24060001 */  li    $a2, 1
/* 00D718 7000CB18 0C003774 */  jal   osRecvMesg
/* 00D71C 7000CB1C 8D440004 */   lw    $a0, 4($t2)
/* 00D720 7000CB20 8FAB0050 */  lw    $t3, 0x50($sp)
/* 00D724 7000CB24 3C038006 */  lui   $v1, %hi(__osPfsPifRam)
/* 00D728 7000CB28 24637D70 */  addiu $v1, %lo(__osPfsPifRam) # addiu $v1, $v1, 0x7d70
/* 00D72C 7000CB2C 8D640008 */  lw    $a0, 8($t3)
/* 00D730 7000CB30 27AC001C */  addiu $t4, $sp, 0x1c
/* 00D734 7000CB34 50800008 */  beql  $a0, $zero, .L7000CB58
/* 00D738 7000CB38 00607825 */   move  $t7, $v1
/* 00D73C 7000CB3C 18800005 */  blez  $a0, .L7000CB54
/* 00D740 7000CB40 00001025 */   move  $v0, $zero
.L7000CB44:
/* 00D744 7000CB44 24420001 */  addiu $v0, $v0, 1
/* 00D748 7000CB48 0044082A */  slt   $at, $v0, $a0
/* 00D74C 7000CB4C 1420FFFD */  bnez  $at, .L7000CB44
/* 00D750 7000CB50 24630001 */   addiu $v1, $v1, 1
.L7000CB54:
/* 00D754 7000CB54 00607825 */  move  $t7, $v1
.L7000CB58:
/* 00D758 7000CB58 246E0024 */  addiu $t6, $v1, 0x24
.L7000CB5C:
/* 00D75C 7000CB5C 89E10000 */  lwl   $at, ($t7)
/* 00D760 7000CB60 99E10003 */  lwr   $at, 3($t7)
/* 00D764 7000CB64 25EF000C */  addiu $t7, $t7, 0xc
/* 00D768 7000CB68 258C000C */  addiu $t4, $t4, 0xc
/* 00D76C 7000CB6C AD81FFF4 */  sw    $at, -0xc($t4)
/* 00D770 7000CB70 89E1FFF8 */  lwl   $at, -8($t7)
/* 00D774 7000CB74 99E1FFFB */  lwr   $at, -5($t7)
/* 00D778 7000CB78 AD81FFF8 */  sw    $at, -8($t4)
/* 00D77C 7000CB7C 89E1FFFC */  lwl   $at, -4($t7)
/* 00D780 7000CB80 99E1FFFF */  lwr   $at, -1($t7)
/* 00D784 7000CB84 15EEFFF5 */  bne   $t7, $t6, .L7000CB5C
/* 00D788 7000CB88 AD81FFFC */   sw    $at, -4($t4)
/* 00D78C 7000CB8C 89E10000 */  lwl   $at, ($t7)
/* 00D790 7000CB90 99E10003 */  lwr   $at, 3($t7)
/* 00D794 7000CB94 AD810000 */  sw    $at, ($t4)
/* 00D798 7000CB98 93A2001E */  lbu   $v0, 0x1e($sp)
/* 00D79C 7000CB9C 93A80042 */  lbu   $t0, 0x42($sp)
/* 00D7A0 7000CBA0 240100EB */  li    $at, 235
/* 00D7A4 7000CBA4 305800C0 */  andi  $t8, $v0, 0xc0
/* 00D7A8 7000CBA8 00182103 */  sra   $a0, $t8, 4
/* 00D7AC 7000CBAC 14800004 */  bnez  $a0, .L7000CBC0
/* 00D7B0 7000CBB0 00000000 */   nop   
/* 00D7B4 7000CBB4 11010002 */  beq   $t0, $at, .L7000CBC0
/* 00D7B8 7000CBB8 00000000 */   nop   
/* 00D7BC 7000CBBC 24040004 */  li    $a0, 4
.L7000CBC0:
/* 00D7C0 7000CBC0 0C0057A9 */  jal   __osSiRelAccess
/* 00D7C4 7000CBC4 AFA40048 */   sw    $a0, 0x48($sp)
/* 00D7C8 7000CBC8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00D7CC 7000CBCC 8FA20048 */  lw    $v0, 0x48($sp)
/* 00D7D0 7000CBD0 27BD0050 */  addiu $sp, $sp, 0x50
/* 00D7D4 7000CBD4 03E00008 */  jr    $ra
/* 00D7D8 7000CBD8 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
void _MakeMotorData(int channel,u16 address,u8 *buffer,OSPifRam *mdata)
{

}
#else
GLOBAL_ASM(
.text
glabel _MakeMotorData
/* 00D7DC 7000CBDC 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 00D7E0 7000CBE0 AFB00018 */  sw    $s0, 0x18($sp)
/* 00D7E4 7000CBE4 00808025 */  move  $s0, $a0
/* 00D7E8 7000CBE8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00D7EC 7000CBEC AFA5005C */  sw    $a1, 0x5c($sp)
/* 00D7F0 7000CBF0 00E01825 */  move  $v1, $a3
/* 00D7F4 7000CBF4 00004025 */  move  $t0, $zero
/* 00D7F8 7000CBF8 00E01025 */  move  $v0, $a3
.L7000CBFC:
/* 00D7FC 7000CBFC 25080001 */  addiu $t0, $t0, 1
/* 00D800 7000CC00 2901000F */  slti  $at, $t0, 0xf
/* 00D804 7000CC04 24420004 */  addiu $v0, $v0, 4
/* 00D808 7000CC08 1420FFFC */  bnez  $at, .L7000CBFC
/* 00D80C 7000CC0C AC40FFFC */   sw    $zero, -4($v0)
/* 00D810 7000CC10 240E0001 */  li    $t6, 1
/* 00D814 7000CC14 ACEE003C */  sw    $t6, 0x3c($a3)
/* 00D818 7000CC18 240F00FF */  li    $t7, 255
/* 00D81C 7000CC1C 24180023 */  li    $t8, 35
/* 00D820 7000CC20 24190001 */  li    $t9, 1
/* 00D824 7000CC24 24090003 */  li    $t1, 3
/* 00D828 7000CC28 A3AF002C */  sb    $t7, 0x2c($sp)
/* 00D82C 7000CC2C A3B8002D */  sb    $t8, 0x2d($sp)
/* 00D830 7000CC30 A3B9002E */  sb    $t9, 0x2e($sp)
/* 00D834 7000CC34 A3A9002F */  sb    $t1, 0x2f($sp)
/* 00D838 7000CC38 AFA60060 */  sw    $a2, 0x60($sp)
/* 00D83C 7000CC3C AFA30054 */  sw    $v1, 0x54($sp)
/* 00D840 7000CC40 0C0057E0 */  jal   __osContAddressCrc
/* 00D844 7000CC44 97A4005E */   lhu   $a0, 0x5e($sp)
/* 00D848 7000CC48 97AA005E */  lhu   $t2, 0x5e($sp)
/* 00D84C 7000CC4C 240D00FF */  li    $t5, 255
/* 00D850 7000CC50 8FA30054 */  lw    $v1, 0x54($sp)
/* 00D854 7000CC54 000A5940 */  sll   $t3, $t2, 5
/* 00D858 7000CC58 004B6025 */  or    $t4, $v0, $t3
/* 00D85C 7000CC5C A7AC0030 */  sh    $t4, 0x30($sp)
/* 00D860 7000CC60 8FA60060 */  lw    $a2, 0x60($sp)
/* 00D864 7000CC64 A3AD0052 */  sb    $t5, 0x52($sp)
/* 00D868 7000CC68 27A2004C */  addiu $v0, $sp, 0x4c
/* 00D86C 7000CC6C 27A4002C */  addiu $a0, $sp, 0x2c
.L7000CC70:
/* 00D870 7000CC70 90CE0000 */  lbu   $t6, ($a2)
/* 00D874 7000CC74 24840001 */  addiu $a0, $a0, 1
/* 00D878 7000CC78 0082082B */  sltu  $at, $a0, $v0
/* 00D87C 7000CC7C 24C60001 */  addiu $a2, $a2, 1
/* 00D880 7000CC80 1420FFFB */  bnez  $at, .L7000CC70
/* 00D884 7000CC84 A08E0005 */   sb    $t6, 5($a0)
/* 00D888 7000CC88 12000012 */  beqz  $s0, .L7000CCD4
/* 00D88C 7000CC8C 27AF002C */   addiu $t7, $sp, 0x2c
/* 00D890 7000CC90 1A000010 */  blez  $s0, .L7000CCD4
/* 00D894 7000CC94 00004025 */   move  $t0, $zero
/* 00D898 7000CC98 32040003 */  andi  $a0, $s0, 3
/* 00D89C 7000CC9C 10800006 */  beqz  $a0, .L7000CCB8
/* 00D8A0 7000CCA0 00801025 */   move  $v0, $a0
.L7000CCA4:
/* 00D8A4 7000CCA4 25080001 */  addiu $t0, $t0, 1
/* 00D8A8 7000CCA8 A0600000 */  sb    $zero, ($v1)
/* 00D8AC 7000CCAC 1448FFFD */  bne   $v0, $t0, .L7000CCA4
/* 00D8B0 7000CCB0 24630001 */   addiu $v1, $v1, 1
/* 00D8B4 7000CCB4 11100007 */  beq   $t0, $s0, .L7000CCD4
.L7000CCB8:
/* 00D8B8 7000CCB8 25080004 */   addiu $t0, $t0, 4
/* 00D8BC 7000CCBC A0600001 */  sb    $zero, 1($v1)
/* 00D8C0 7000CCC0 A0600002 */  sb    $zero, 2($v1)
/* 00D8C4 7000CCC4 A0600003 */  sb    $zero, 3($v1)
/* 00D8C8 7000CCC8 24630004 */  addiu $v1, $v1, 4
/* 00D8CC 7000CCCC 1510FFFA */  bne   $t0, $s0, .L7000CCB8
/* 00D8D0 7000CCD0 A060FFFC */   sb    $zero, -4($v1)
.L7000CCD4:
/* 00D8D4 7000CCD4 00604825 */  move  $t1, $v1
/* 00D8D8 7000CCD8 25F90024 */  addiu $t9, $t7, 0x24
.L7000CCDC:
/* 00D8DC 7000CCDC 8DE10000 */  lw    $at, ($t7)
/* 00D8E0 7000CCE0 25EF000C */  addiu $t7, $t7, 0xc
/* 00D8E4 7000CCE4 2529000C */  addiu $t1, $t1, 0xc
/* 00D8E8 7000CCE8 A921FFF4 */  swl   $at, -0xc($t1)
/* 00D8EC 7000CCEC B921FFF7 */  swr   $at, -9($t1)
/* 00D8F0 7000CCF0 8DE1FFF8 */  lw    $at, -8($t7)
/* 00D8F4 7000CCF4 A921FFF8 */  swl   $at, -8($t1)
/* 00D8F8 7000CCF8 B921FFFB */  swr   $at, -5($t1)
/* 00D8FC 7000CCFC 8DE1FFFC */  lw    $at, -4($t7)
/* 00D900 7000CD00 A921FFFC */  swl   $at, -4($t1)
/* 00D904 7000CD04 15F9FFF5 */  bne   $t7, $t9, .L7000CCDC
/* 00D908 7000CD08 B921FFFF */   swr   $at, -1($t1)
/* 00D90C 7000CD0C 8DE10000 */  lw    $at, ($t7)
/* 00D910 7000CD10 240A00FE */  li    $t2, 254
/* 00D914 7000CD14 24630028 */  addiu $v1, $v1, 0x28
/* 00D918 7000CD18 A9210000 */  swl   $at, ($t1)
/* 00D91C 7000CD1C B9210003 */  swr   $at, 3($t1)
/* 00D920 7000CD20 A06A0000 */  sb    $t2, ($v1)
/* 00D924 7000CD24 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00D928 7000CD28 8FB00018 */  lw    $s0, 0x18($sp)
/* 00D92C 7000CD2C 27BD0058 */  addiu $sp, $sp, 0x58
/* 00D930 7000CD30 03E00008 */  jr    $ra
/* 00D934 7000CD34 00000000 */   nop   
)
#endif



#ifdef NONMATCHING
s32 osMotorInit(OSMesgQueue *mq,OSPfs *pfs,int channel) {
    s32 sp2C;
    ? sp30;
    ? sp50;
    u32 temp_v0;
    ? temp_ret;
    void *temp_v1;
    s32 temp_v0_2;

    // Node 0
    arg1->unk4 = arg0;
    arg1->unk8 = arg2;
    *arg1 = 0;
    arg1->unk65 = (u8)0x80;
    // Node 1
    temp_v0 = (&sp30 + 1);
    temp_v0->unk-1 = (u8)0x80;
    if (temp_v0 < &sp50)
    {
        goto loop_1;
    }
    // Node 2
    temp_ret = __osContRamWrite(arg2, 0x400, &sp30, 0);
    if (temp_ret == 2)
    {
        // Node 3
        __osContRamWrite(arg16, arg2, 0x400, &sp30, 0);
    }
    // Node 4
    if (temp_ret != 0)
    {
        // Node 5
    }
    else
    {
        // Node 6
        if (__osContRamRead(arg16, arg2, 0x400, &sp30) != 0)
        {
            // Node 7
            return;
            // (possible return value: __osContRamRead(arg16, arg2, 0x400, &sp30))
        }
        // Node 8
        if (sp4F != 0x80)
        {
            // Node 9
        }
        else
        {
            // Node 10
            // Node 11
            temp_v1 = (&_motorstopbuf + 4);
            _motorstartbuf.unk1 = (u8)1;
            temp_v1->unk-3 = (u8)0;
            _motorstartbuf.unk2 = (u8)1;
            temp_v1->unk-2 = (u8)0;
            _motorstartbuf.unk3 = (u8)1;
            temp_v1->unk-1 = (u8)0;
            (&_motorstartbuf + 4)->unk-4 = (u8)1;
            temp_v1->unk-4 = (u8)0;
            if (temp_v1 != &_motorstartbuf)
            {
                goto loop_11;
            }
            // Node 12
            temp_v0_2 = (arg2 << 6);
            sp2C = temp_v0_2;
            _MakeMotorData(arg2, 0x600, &_motorstartbuf, (temp_v0_2 + &_MotorStartData));
            _MakeMotorData(arg2, 0x600, &_motorstopbuf, (sp2C + &_MotorStopData));
        }
    }
    // Node 13
    return;
    // (possible return value: 0)
}
#else
GLOBAL_ASM(
.text
glabel osMotorInit
/* 00D938 7000CD38 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 00D93C 7000CD3C AFB00020 */  sw    $s0, 0x20($sp)
/* 00D940 7000CD40 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00D944 7000CD44 24070080 */  li    $a3, 128
/* 00D948 7000CD48 00C08025 */  move  $s0, $a2
/* 00D94C 7000CD4C ACA40004 */  sw    $a0, 4($a1)
/* 00D950 7000CD50 ACA60008 */  sw    $a2, 8($a1)
/* 00D954 7000CD54 ACA00000 */  sw    $zero, ($a1)
/* 00D958 7000CD58 A0A70065 */  sb    $a3, 0x65($a1)
/* 00D95C 7000CD5C 27A20030 */  addiu $v0, $sp, 0x30
/* 00D960 7000CD60 27A30050 */  addiu $v1, $sp, 0x50
.L7000CD64:
/* 00D964 7000CD64 24420001 */  addiu $v0, $v0, 1
/* 00D968 7000CD68 0043082B */  sltu  $at, $v0, $v1
/* 00D96C 7000CD6C 1420FFFD */  bnez  $at, .L7000CD64
/* 00D970 7000CD70 A047FFFF */   sb    $a3, -1($v0)
/* 00D974 7000CD74 02002825 */  move  $a1, $s0
/* 00D978 7000CD78 24060400 */  li    $a2, 1024
/* 00D97C 7000CD7C 27A70030 */  addiu $a3, $sp, 0x30
/* 00D980 7000CD80 AFA00010 */  sw    $zero, 0x10($sp)
/* 00D984 7000CD84 0C005840 */  jal   __osContRamWrite
/* 00D988 7000CD88 AFA40058 */   sw    $a0, 0x58($sp)
/* 00D98C 7000CD8C 24010002 */  li    $at, 2
/* 00D990 7000CD90 14410008 */  bne   $v0, $at, .L7000CDB4
/* 00D994 7000CD94 00401825 */   move  $v1, $v0
/* 00D998 7000CD98 8FA40058 */  lw    $a0, 0x58($sp)
/* 00D99C 7000CD9C 02002825 */  move  $a1, $s0
/* 00D9A0 7000CDA0 24060400 */  li    $a2, 1024
/* 00D9A4 7000CDA4 27A70030 */  addiu $a3, $sp, 0x30
/* 00D9A8 7000CDA8 0C005840 */  jal   __osContRamWrite
/* 00D9AC 7000CDAC AFA00010 */   sw    $zero, 0x10($sp)
/* 00D9B0 7000CDB0 00401825 */  move  $v1, $v0
.L7000CDB4:
/* 00D9B4 7000CDB4 10400003 */  beqz  $v0, .L7000CDC4
/* 00D9B8 7000CDB8 8FA40058 */   lw    $a0, 0x58($sp)
/* 00D9BC 7000CDBC 10000033 */  b     .L7000CE8C
/* 00D9C0 7000CDC0 00601025 */   move  $v0, $v1
.L7000CDC4:
/* 00D9C4 7000CDC4 02002825 */  move  $a1, $s0
/* 00D9C8 7000CDC8 24060400 */  li    $a2, 1024
/* 00D9CC 7000CDCC 0C00592C */  jal   __osContRamRead
/* 00D9D0 7000CDD0 27A70030 */   addiu $a3, $sp, 0x30
/* 00D9D4 7000CDD4 10400003 */  beqz  $v0, .L7000CDE4
/* 00D9D8 7000CDD8 93AE004F */   lbu   $t6, 0x4f($sp)
/* 00D9DC 7000CDDC 1000002C */  b     .L7000CE90
/* 00D9E0 7000CDE0 8FBF0024 */   lw    $ra, 0x24($sp)
.L7000CDE4:
/* 00D9E4 7000CDE4 24010080 */  li    $at, 128
/* 00D9E8 7000CDE8 11C10003 */  beq   $t6, $at, .L7000CDF8
/* 00D9EC 7000CDEC 3C048006 */   lui   $a0, %hi(_motorstartbuf)
/* 00D9F0 7000CDF0 10000026 */  b     .L7000CE8C
/* 00D9F4 7000CDF4 2402000B */   li    $v0, 11
.L7000CDF8:
/* 00D9F8 7000CDF8 3C038006 */  lui   $v1, %hi(_motorstopbuf)
/* 00D9FC 7000CDFC 3C058006 */  lui   $a1, %hi(_motorstartbuf)
/* 00DA00 7000CE00 24A557C0 */  addiu $a1, %lo(_motorstartbuf) # addiu $a1, $a1, 0x57c0
/* 00DA04 7000CE04 246357A0 */  addiu $v1, %lo(_motorstopbuf) # addiu $v1, $v1, 0x57a0
/* 00DA08 7000CE08 248457C0 */  addiu $a0, %lo(_motorstartbuf) # addiu $a0, $a0, 0x57c0
/* 00DA0C 7000CE0C 24020001 */  li    $v0, 1
.L7000CE10:
/* 00DA10 7000CE10 24630004 */  addiu $v1, $v1, 4
/* 00DA14 7000CE14 A0820001 */  sb    $v0, 1($a0)
/* 00DA18 7000CE18 A060FFFD */  sb    $zero, -3($v1)
/* 00DA1C 7000CE1C A0820002 */  sb    $v0, 2($a0)
/* 00DA20 7000CE20 A060FFFE */  sb    $zero, -2($v1)
/* 00DA24 7000CE24 A0820003 */  sb    $v0, 3($a0)
/* 00DA28 7000CE28 A060FFFF */  sb    $zero, -1($v1)
/* 00DA2C 7000CE2C 24840004 */  addiu $a0, $a0, 4
/* 00DA30 7000CE30 A082FFFC */  sb    $v0, -4($a0)
/* 00DA34 7000CE34 1465FFF6 */  bne   $v1, $a1, .L7000CE10
/* 00DA38 7000CE38 A060FFFC */   sb    $zero, -4($v1)
/* 00DA3C 7000CE3C 3C0F8006 */  lui   $t7, %hi(_MotorStartData) 
/* 00DA40 7000CE40 25EF56A0 */  addiu $t7, %lo(_MotorStartData) # addiu $t7, $t7, 0x56a0
/* 00DA44 7000CE44 3C068006 */  lui   $a2, %hi(_motorstartbuf)
/* 00DA48 7000CE48 00101180 */  sll   $v0, $s0, 6
/* 00DA4C 7000CE4C 004F3821 */  addu  $a3, $v0, $t7
/* 00DA50 7000CE50 AFA2002C */  sw    $v0, 0x2c($sp)
/* 00DA54 7000CE54 24C657C0 */  addiu $a2, %lo(_motorstartbuf) # addiu $a2, $a2, 0x57c0
/* 00DA58 7000CE58 02002025 */  move  $a0, $s0
/* 00DA5C 7000CE5C 0C0032F7 */  jal   _MakeMotorData
/* 00DA60 7000CE60 24050600 */   li    $a1, 1536
/* 00DA64 7000CE64 8FA2002C */  lw    $v0, 0x2c($sp)
/* 00DA68 7000CE68 3C188006 */  lui   $t8, %hi(_MotorStopData) 
/* 00DA6C 7000CE6C 271855A0 */  addiu $t8, %lo(_MotorStopData) # addiu $t8, $t8, 0x55a0
/* 00DA70 7000CE70 3C068006 */  lui   $a2, %hi(_motorstopbuf)
/* 00DA74 7000CE74 24C657A0 */  addiu $a2, %lo(_motorstopbuf) # addiu $a2, $a2, 0x57a0
/* 00DA78 7000CE78 02002025 */  move  $a0, $s0
/* 00DA7C 7000CE7C 24050600 */  li    $a1, 1536
/* 00DA80 7000CE80 0C0032F7 */  jal   _MakeMotorData
/* 00DA84 7000CE84 00583821 */   addu  $a3, $v0, $t8
/* 00DA88 7000CE88 00001025 */  move  $v0, $zero
.L7000CE8C:
/* 00DA8C 7000CE8C 8FBF0024 */  lw    $ra, 0x24($sp)
.L7000CE90:
/* 00DA90 7000CE90 8FB00020 */  lw    $s0, 0x20($sp)
/* 00DA94 7000CE94 27BD0058 */  addiu $sp, $sp, 0x58
/* 00DA98 7000CE98 03E00008 */  jr    $ra
/* 00DA9C 7000CE9C 00000000 */   nop   
)
#endif
