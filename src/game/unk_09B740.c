#include "ultra64.h"


// data
//D:80040160
u64 random_val = 0xAB8D9F7781280783;



#ifdef NONMATCHING
void sub_GAME_7F09B740(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B740
/* 0D0270 7F09B740 3C048004 */  lui   $a0, %hi(random_val) # $a0, 0x8004
/* 0D0274 7F09B744 DC840160 */  ld    $a0, %lo(random_val)($a0)
/* 0D0278 7F09B748 3C018004 */  lui   $at, %hi(random_val) # $at, 0x8004
/* 0D027C 7F09B74C 000437FC */  dsll32 $a2, $a0, 0x1f
/* 0D0280 7F09B750 00042FF8 */  dsll  $a1, $a0, 0x1f
/* 0D0284 7F09B754 000637FA */  dsrl  $a2, $a2, 0x1f
/* 0D0288 7F09B758 0005283E */  dsrl32 $a1, $a1, 0
/* 0D028C 7F09B75C 0004233C */  dsll32 $a0, $a0, 0xc
/* 0D0290 7F09B760 00C53025 */  or    $a2, $a2, $a1
/* 0D0294 7F09B764 0004203E */  dsrl32 $a0, $a0, 0
/* 0D0298 7F09B768 00C43026 */  xor   $a2, $a2, $a0
/* 0D029C 7F09B76C 0006253A */  dsrl  $a0, $a2, 0x14
/* 0D02A0 7F09B770 30840FFF */  andi  $a0, $a0, 0xfff
/* 0D02A4 7F09B774 00862026 */  xor   $a0, $a0, $a2
/* 0D02A8 7F09B778 0004103C */  dsll32 $v0, $a0, 0
/* 0D02AC 7F09B77C FC240160 */  sd    $a0, %lo(random_val)($at)
/* 0D02B0 7F09B780 03E00008 */  jr    $ra
/* 0D02B4 7F09B784 0002103F */   dsra32 $v0, $v0, 0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09B788(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F09B788
/* 0D02B8 7F09B788 64840001 */  daddiu $a0, $a0, 1
/* 0D02BC 7F09B78C 3C018004 */  lui   $at, %hi(random_val) # $at, 0x8004
/* 0D02C0 7F09B790 FC240160 */  sd    $a0, %lo(random_val)($at)
/* 0D02C4 7F09B794 03E00008 */  jr    $ra
/* 0D02C8 7F09B798 24040000 */   li    $a0, 0
)
#endif


