#include "ultra64.h"

/**
 * @file osMapTLB.c
 * This file contains code thatsets TLB indexed entry 0 to mirror 1KB of rdram from 80000000 to C0000000. 
 * 
 * In particular, it:
 *   - should be made into an assembly file
 */

/**
 * 	 2380	70001780
 * sets TLB indexed entry 0 to mirror 1KB of rdram from 80000000 to C0000000
 *	uncached, dirty, valid, global
 */
#ifdef NONMATCHING
void osMapTLBRdb(void) {
    //i should probably remain as assembly, maybe even moved to a .s
}
#else
GLOBAL_ASM(
.text
glabel osMapTLBRdb
/* 002380 70001780 40085000 */  mfc0  $t0, $10
/* 002384 70001784 24090000 */  li    $t1, 0
/* 002388 70001788 40890000 */  mtc0  $t1, $0
/* 00238C 7000178C 40802800 */  mtc0  $zero, $5
/* 002390 70001790 240A0017 */  li    $t2, 23
/* 002394 70001794 3C09C000 */  lui   $t1, 0xc000
/* 002398 70001798 40895000 */  mtc0  $t1, $10
/* 00239C 7000179C 3C098000 */  lui   $t1, 0x8000
/* 0023A0 700017A0 00095982 */  srl   $t3, $t1, 6
/* 0023A4 700017A4 016A5825 */  or    $t3, $t3, $t2
/* 0023A8 700017A8 408B1000 */  mtc0  $t3, $2
/* 0023AC 700017AC 24090001 */  li    $t1, 1
/* 0023B0 700017B0 40891800 */  mtc0  $t1, $3
/* 0023B4 700017B4 00000000 */  nop   
/* 0023B8 700017B8 42000002 */  tlbwi 
/* 0023BC 700017BC 00000000 */  nop   
/* 0023C0 700017C0 00000000 */  nop   
/* 0023C4 700017C4 00000000 */  nop   
/* 0023C8 700017C8 00000000 */  nop   
/* 0023CC 700017CC 40885000 */  mtc0  $t0, $10
/* 0023D0 700017D0 03E00008 */  jr    $ra
/* 0023D4 700017D4 00000000 */   nop   
)
#endif
