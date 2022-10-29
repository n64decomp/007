#include <ultra64.h>
#include "zlib.h"

//this definately isn't proper way this data was represented, but works for now
// rodata
//D:8005BF80
const u8 rz_header_bytes[40] = {
    0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00,
    0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00, 0x11, 0x72, 0x00, 0x00
};




#ifdef NONMATCHING
//
u32 decompressdata(u8 *src, u8 *dst, struct huft *hlist)
{
    rz_inbuf = src;
    rz_outbuf = dst;
    rz_hlist = hlist;
    if ((src[0] != rz_header_bytes[0]) || (src[1] != rz_header_bytes[5]))
    {
        if (src[1] != rz_header_bytes[8])
        {

        }
        if (src[2] != rz_header_bytes[0x18])
        {

        }
    }
    rz_inbuf = (s32) (rz_inbuf + 2);
    rz_wp = 0;
    rz_inptr = 0;
    zlib_inflate();
    return rz_wp;
}
#else
GLOBAL_ASM(
.text
glabel decompressdata
/* 103320 7F0CE7F0 3C078009 */  lui   $a3, %hi(rz_inbuf)
/* 103324 7F0CE7F4 24E7D350 */  addiu $a3, %lo(rz_inbuf) # addiu $a3, $a3, -0x2cb0
/* 103328 7F0CE7F8 ACE40000 */  sw    $a0, ($a3)
/* 10332C 7F0CE7FC 3C018009 */  lui   $at, %hi(rz_outbuf)
/* 103330 7F0CE800 AC25D354 */  sw    $a1, %lo(rz_outbuf)($at)
/* 103334 7F0CE804 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 103338 7F0CE808 3C018009 */  lui   $at, %hi(rz_hlist)
/* 10333C 7F0CE80C AFBF0014 */  sw    $ra, 0x14($sp)
/* 103340 7F0CE810 AC26D360 */  sw    $a2, %lo(rz_hlist)($at)
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
/* 103394 7F0CE864 3C018009 */  lui   $at, %hi(rz_wp)
/* 103398 7F0CE868 258D0002 */  addiu $t5, $t4, 2
/* 10339C 7F0CE86C ACED0000 */  sw    $t5, ($a3)
/* 1033A0 7F0CE870 AC20D35C */  sw    $zero, %lo(rz_wp)($at)
/* 1033A4 7F0CE874 3C018009 */  lui   $at, %hi(rz_inptr)
/* 1033A8 7F0CE878 0FC33F35 */  jal   zlib_inflate
/* 1033AC 7F0CE87C AC20D358 */   sw    $zero, %lo(rz_inptr)($at)
/* 1033B0 7F0CE880 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1033B4 7F0CE884 3C028009 */  lui   $v0, %hi(rz_wp)
/* 1033B8 7F0CE888 8C42D35C */  lw    $v0, %lo(rz_wp)($v0)
/* 1033BC 7F0CE88C 03E00008 */  jr    $ra
/* 1033C0 7F0CE890 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif






s32 rzipGetSomething(void) {
    return (rz_inbuf + rz_inptr);
}



