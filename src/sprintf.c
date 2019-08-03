#include "ultra64.h"




#ifdef NONMATCHING
s32 proutSprintf(s32 arg2)
{
    return memcpy() + arg2;
}
#else
GLOBAL_ASM(
.text
glabel proutSprintf
/* 00B870 7000AC70 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00B874 7000AC74 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00B878 7000AC78 0C004E14 */  jal   memcpy
/* 00B87C 7000AC7C AFA60020 */   sw    $a2, 0x20($sp)
/* 00B880 7000AC80 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00B884 7000AC84 8FAE0020 */  lw    $t6, 0x20($sp)
/* 00B888 7000AC88 27BD0018 */  addiu $sp, $sp, 0x18
/* 00B88C 7000AC8C 03E00008 */  jr    $ra
/* 00B890 7000AC90 004E1021 */   addu  $v0, $v0, $t6
)
#endif





#ifdef NONMATCHING
s32 sprintf(s32 arg0, s32 arg1, ? arg2, ? arg3)
{
    s32 temp_ret;

    temp_ret = _Printf(&proutSprintf, arg0, arg1, &arg2);
    if (temp_ret >= 0)
    {
        *(arg0 + temp_ret) = (u8)0;
    }
    return temp_ret + -1;
}
#else
GLOBAL_ASM(
.text
glabel sprintf
/* 00B894 7000AC94 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00B898 7000AC98 AFA40020 */  sw    $a0, 0x20($sp)
/* 00B89C 7000AC9C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00B8A0 7000ACA0 AFA50024 */  sw    $a1, 0x24($sp)
/* 00B8A4 7000ACA4 AFA60028 */  sw    $a2, 0x28($sp)
/* 00B8A8 7000ACA8 AFA7002C */  sw    $a3, 0x2c($sp)
/* 00B8AC 7000ACAC 3C047001 */  lui   $a0, %hi(proutSprintf) # $a0, 0x7001
/* 00B8B0 7000ACB0 2484AC70 */  addiu $a0, %lo(proutSprintf) # addiu $a0, $a0, -0x5390
/* 00B8B4 7000ACB4 27A70028 */  addiu $a3, $sp, 0x28
/* 00B8B8 7000ACB8 8FA60024 */  lw    $a2, 0x24($sp)
/* 00B8BC 7000ACBC 0C004FD8 */  jal   _Printf
/* 00B8C0 7000ACC0 8FA50020 */   lw    $a1, 0x20($sp)
/* 00B8C4 7000ACC4 04400004 */  bltz  $v0, .L7000ACD8
/* 00B8C8 7000ACC8 00401825 */   move  $v1, $v0
/* 00B8CC 7000ACCC 8FAE0020 */  lw    $t6, 0x20($sp)
/* 00B8D0 7000ACD0 01C27821 */  addu  $t7, $t6, $v0
/* 00B8D4 7000ACD4 A1E00000 */  sb    $zero, ($t7)
.L7000ACD8:
/* 00B8D8 7000ACD8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00B8DC 7000ACDC 27BD0020 */  addiu $sp, $sp, 0x20
/* 00B8E0 7000ACE0 2462FFFF */  addiu $v0, $v1, -1
/* 00B8E4 7000ACE4 03E00008 */  jr    $ra
/* 00B8E8 7000ACE8 00000000 */   nop   
)
#endif



