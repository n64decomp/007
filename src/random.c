#include "ultra64.h"

/**
 * @file random.c
 * This file contains code to get a random value and set the next seed.
 * The methods here are the same as in tlb_random and chrObjRandom (but different globals).
 */

u64 g_randomSeed = 0xAB8D9F7781280783;

#ifdef NONMATCHING
/**
 * Iterates the current random seed and returns a 32 bit value.
 * Same assembly instructions as tlbRandomGetNext and chrObjRandomGetNext, but different globals.
 */ 
s32 randomGetNext(void) {
    // best -O1 guess
    // g_randomSeed ^= (((((g_randomSeed << 0x3f) >> 0x1f) | ((g_randomSeed << 0x1f) >> 0x20)) ^ ((g_randomSeed << 0x2c) >> 0x20)) >> 0x14) & 0xfff;
    // return (s32)(g_randomSeed);

    // best -O2 guess
    // u64 t = ((g_randomSeed << 0x3f) >> 0x1f);
    // t |= ((g_randomSeed << 0x1f) >> 0x20);
    // t ^= ((g_randomSeed << 0x2c) >> 0x20);
    // t = g_randomSeed ^ ((t >> 0x14) & 0xfff);
    // g_randomSeed = t;
    // return (s32)(t);
}
#else
GLOBAL_ASM(
.text
glabel randomGetNext
/* 00B050 7000A450 3C048002 */  lui   $a0, %hi(g_randomSeed)
/* 00B054 7000A454 DC844460 */  ld    $a0, %lo(g_randomSeed)($a0)
/* 00B058 7000A458 3C018002 */  lui   $at, %hi(g_randomSeed)
/* 00B05C 7000A45C 000437FC */  dsll32 $a2, $a0, 0x1f
/* 00B060 7000A460 00042FF8 */  dsll  $a1, $a0, 0x1f
/* 00B064 7000A464 000637FA */  dsrl  $a2, $a2, 0x1f
/* 00B068 7000A468 0005283E */  dsrl32 $a1, $a1, 0
/* 00B06C 7000A46C 0004233C */  dsll32 $a0, $a0, 0xc
/* 00B070 7000A470 00C53025 */  or    $a2, $a2, $a1
/* 00B074 7000A474 0004203E */  dsrl32 $a0, $a0, 0
/* 00B078 7000A478 00C43026 */  xor   $a2, $a2, $a0
/* 00B07C 7000A47C 0006253A */  dsrl  $a0, $a2, 0x14
/* 00B080 7000A480 30840FFF */  andi  $a0, $a0, 0xfff
/* 00B084 7000A484 00862026 */  xor   $a0, $a0, $a2
/* 00B088 7000A488 0004103C */  dsll32 $v0, $a0, 0
/* 00B08C 7000A48C FC244460 */  sd    $a0, %lo(g_randomSeed)($at)
/* 00B090 7000A490 03E00008 */  jr    $ra
/* 00B094 7000A494 0002103F */   dsra32 $v0, $v0, 0
)
#endif



#ifdef NONMATCHING
/**
 * This sets the global random seed. This is called from boss mainloop by randomSetSeed(osGetCount()),
 * so the argument may just be 32bit.
 * 
 * Assembly assigns zero to $a0 at the end of the function, which seems odd.
 * 
 * Same assembly instructions as chrObjRandomSetSeed.
 */ 
void randomSetSeed(u32 param_1) {
    g_randomSeed = param_1 + 1;
}
#else
GLOBAL_ASM(
.text
glabel randomSetSeed
/* 00B098 7000A498 64840001 */  daddiu $a0, $a0, 1
/* 00B09C 7000A49C 3C018002 */  lui   $at, %hi(g_randomSeed)
/* 00B0A0 7000A4A0 FC244460 */  sd    $a0, %lo(g_randomSeed)($at)
/* 00B0A4 7000A4A4 03E00008 */  jr    $ra
/* 00B0A8 7000A4A8 24040000 */   li    $a0, 0
)
#endif



#ifdef NONMATCHING
/**
 * Iterates the parameter as if it were the random seed and returns the next 32 bit random value.
 * This uses the same logic as randomGetNext.
 */ 
s32 randomGetNextFrom(u64 *param_1) {
    // best -O1 guess
    // *param_1 ^= (((((*param_1 << 0x3f) >> 0x1f) | ((*param_1 << 0x1f) >> 0x20)) ^ ((*param_1 << 0x2c) >> 0x20)) >> 0x14) & 0xfff;
    // return (s32)(*param_1);

    // best -O2 guess
    // u64 t = ((*param_1 << 0x3f) >> 0x1f);
    // t |= ((*param_1 << 0x1f) >> 0x20);
    // t ^= ((*param_1 << 0x2c) >> 0x20);
    // t = *param_1 ^ ((t >> 0x14) & 0xfff);
    // *param_1 = t;
    // return (s32)(t);
}
#else
GLOBAL_ASM(
.text
glabel randomGetNextFrom
/* 00B0AC 7000A4AC DC870000 */  ld    $a3, ($a0)
/* 00B0B0 7000A4B0 000737FC */  dsll32 $a2, $a3, 0x1f
/* 00B0B4 7000A4B4 00072FF8 */  dsll  $a1, $a3, 0x1f
/* 00B0B8 7000A4B8 000637FA */  dsrl  $a2, $a2, 0x1f
/* 00B0BC 7000A4BC 0005283E */  dsrl32 $a1, $a1, 0
/* 00B0C0 7000A4C0 00073B3C */  dsll32 $a3, $a3, 0xc
/* 00B0C4 7000A4C4 00C53025 */  or    $a2, $a2, $a1
/* 00B0C8 7000A4C8 0007383E */  dsrl32 $a3, $a3, 0
/* 00B0CC 7000A4CC 00C73026 */  xor   $a2, $a2, $a3
/* 00B0D0 7000A4D0 00063D3A */  dsrl  $a3, $a2, 0x14
/* 00B0D4 7000A4D4 30E70FFF */  andi  $a3, $a3, 0xfff
/* 00B0D8 7000A4D8 00E63826 */  xor   $a3, $a3, $a2
/* 00B0DC 7000A4DC 0007103C */  dsll32 $v0, $a3, 0
/* 00B0E0 7000A4E0 FC870000 */  sd    $a3, ($a0)
/* 00B0E4 7000A4E4 03E00008 */  jr    $ra
/* 00B0E8 7000A4E8 0002103F */   dsra32 $v0, $v0, 0
)
#endif



