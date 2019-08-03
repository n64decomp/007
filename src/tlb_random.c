#include "ultra64.h"

/**
 * @file tlb_random.c
 * This file contains code to get a random tlb value. 
 * 
 */

u64 tlb_random_seed = 0xAB8D9F7781280783;

/**
 * 2710	70001B10
 * V0= random value for TLB random entries [800230E0]
 */
#ifdef NONMATCHING
u32 return_tlb_random_value(void)
{
  tlb_random_seed =
       ((tlb_random_seed << 0x3f) >> 0x1f | (tlb_random_seed << 0x1f) >> 0x20) ^
       (tlb_random_seed << 0x2c) >> 0x20;
  tlb_random_seed = tlb_random_seed >> 0x14 & 0xfff ^ tlb_random_seed;
  return (u32)tlb_random_seed;
}
#else
GLOBAL_ASM(
.text
glabel return_tlb_random_value
/* 002710 70001B10 3C048002 */  lui   $a0, %hi(tlb_random_seed) # $a0, 0x8002
/* 002714 70001B14 DC8430E0 */  ld    $a0, %lo(tlb_random_seed)($a0)
/* 002718 70001B18 3C018002 */  lui   $at, %hi(tlb_random_seed) # $at, 0x8002
/* 00271C 70001B1C 000437FC */  dsll32 $a2, $a0, 0x1f
/* 002720 70001B20 00042FF8 */  dsll  $a1, $a0, 0x1f
/* 002724 70001B24 000637FA */  dsrl  $a2, $a2, 0x1f
/* 002728 70001B28 0005283E */  dsrl32 $a1, $a1, 0
/* 00272C 70001B2C 0004233C */  dsll32 $a0, $a0, 0xc
/* 002730 70001B30 00C53025 */  or    $a2, $a2, $a1
/* 002734 70001B34 0004203E */  dsrl32 $a0, $a0, 0
/* 002738 70001B38 00C43026 */  xor   $a2, $a2, $a0
/* 00273C 70001B3C 0006253A */  dsrl  $a0, $a2, 0x14
/* 002740 70001B40 30840FFF */  andi  $a0, $a0, 0xfff
/* 002744 70001B44 00862026 */  xor   $a0, $a0, $a2
/* 002748 70001B48 0004103C */  dsll32 $v0, $a0, 0
/* 00274C 70001B4C FC2430E0 */  sd    $a0, %lo(tlb_random_seed)($at)
/* 002750 70001B50 03E00008 */  jr    $ra
/* 002754 70001B54 0002103F */   dsra32 $v0, $v0, 0
)
#endif
