#include <ultra64.h>
#include <bondtypes.h>
#include "stan.h"




#ifdef NONMATCHING
typedef coord3d_s32 {
    s32 x;
    s32 y;
    s32 z;
};
s32 init_pathtable_something( coord3d_s32 *tilepos, u8 *tilename, StandTilePoint *tilestack)
{
    coord3d coord;

   
    tilestack = stanMatchTileName(tilename);
    if ((tilestack == 0) || (isPointInsideTriStandTileUnscaled_Maybe(tilestack, tilepos->x, tilepos->z) == 0))
    {
        tilestack = sub_GAME_7F0AFB78(coord.x, coord.y, coord.z, 0);
        if ((tilestack != 0) && (walkTilesBetweenPoints_NoCallback(tilestack, tilepos->x, tilepos->z, tilepos->x, tilepos->z) != 0))
        {
            return 2;
        }
        tilestack = 0;
        return 0;
    }
    return 1;
}
#else
GLOBAL_ASM(
.text
glabel init_pathtable_something
/* 03B2F0 7F0067C0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 03B2F4 7F0067C4 AFB0001C */  sw    $s0, 0x1c($sp)
/* 03B2F8 7F0067C8 00808025 */  move  $s0, $a0
/* 03B2FC 7F0067CC AFBF0024 */  sw    $ra, 0x24($sp)
/* 03B300 7F0067D0 AFB10020 */  sw    $s1, 0x20($sp)
/* 03B304 7F0067D4 00C08825 */  move  $s1, $a2
/* 03B308 7F0067D8 0FC2CB96 */  jal   stanMatchTileName
/* 03B30C 7F0067DC 00A02025 */   move  $a0, $a1
/* 03B310 7F0067E0 10400007 */  beqz  $v0, .L7F006800
/* 03B314 7F0067E4 AE220000 */   sw    $v0, ($s1)
/* 03B318 7F0067E8 00402025 */  move  $a0, $v0
/* 03B31C 7F0067EC 8E050000 */  lw    $a1, ($s0)
/* 03B320 7F0067F0 0FC2C0DB */  jal   isPointInsideTriStandTileUnscaled_Maybe
/* 03B324 7F0067F4 8E060008 */   lw    $a2, 8($s0)
/* 03B328 7F0067F8 5440001D */  bnezl $v0, .L7F006870
/* 03B32C 7F0067FC 24020001 */   li    $v0, 1
.L7F006800:
/* 03B330 7F006800 C6040000 */  lwc1  $f4, ($s0)
/* 03B334 7F006804 27A4002C */  addiu $a0, $sp, 0x2c
/* 03B338 7F006808 27A50030 */  addiu $a1, $sp, 0x30
/* 03B33C 7F00680C E7A4002C */  swc1  $f4, 0x2c($sp)
/* 03B340 7F006810 C6060004 */  lwc1  $f6, 4($s0)
/* 03B344 7F006814 27A60034 */  addiu $a2, $sp, 0x34
/* 03B348 7F006818 24070000 */  li    $a3, 0
/* 03B34C 7F00681C E7A60030 */  swc1  $f6, 0x30($sp)
/* 03B350 7F006820 C6080008 */  lwc1  $f8, 8($s0)
/* 03B354 7F006824 0FC2BEDE */  jal   sub_GAME_7F0AFB78
/* 03B358 7F006828 E7A80034 */   swc1  $f8, 0x34($sp)
/* 03B35C 7F00682C 1040000C */  beqz  $v0, .L7F006860
/* 03B360 7F006830 AE220000 */   sw    $v0, ($s1)
/* 03B364 7F006834 C60A0008 */  lwc1  $f10, 8($s0)
/* 03B368 7F006838 8E070000 */  lw    $a3, ($s0)
/* 03B36C 7F00683C 02202025 */  move  $a0, $s1
/* 03B370 7F006840 8FA5002C */  lw    $a1, 0x2c($sp)
/* 03B374 7F006844 8FA60034 */  lw    $a2, 0x34($sp)
/* 03B378 7F006848 0FC2C2F9 */  jal   walkTilesBetweenPoints_NoCallback
/* 03B37C 7F00684C E7AA0010 */   swc1  $f10, 0x10($sp)
/* 03B380 7F006850 50400004 */  beql  $v0, $zero, .L7F006864
/* 03B384 7F006854 AE200000 */   sw    $zero, ($s1)
/* 03B388 7F006858 10000005 */  b     .L7F006870
/* 03B38C 7F00685C 24020002 */   li    $v0, 2
.L7F006860:
/* 03B390 7F006860 AE200000 */  sw    $zero, ($s1)
.L7F006864:
/* 03B394 7F006864 10000002 */  b     .L7F006870
/* 03B398 7F006868 00001025 */   move  $v0, $zero
/* 03B39C 7F00686C 24020001 */  li    $v0, 1
.L7F006870:
/* 03B3A0 7F006870 8FBF0024 */  lw    $ra, 0x24($sp)
/* 03B3A4 7F006874 8FB0001C */  lw    $s0, 0x1c($sp)
/* 03B3A8 7F006878 8FB10020 */  lw    $s1, 0x20($sp)
/* 03B3AC 7F00687C 03E00008 */  jr    $ra
/* 03B3B0 7F006880 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

 
