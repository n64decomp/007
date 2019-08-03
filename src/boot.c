#include <ultra64.h>
#include "boot.h"
#include "bondgame.h"
#include "rarezip/rarezip.h"

/**
 * @file boot.c
 * This file sets up initial tlb mapping then jumps to boot1. 
 * 
 * In particular, it:
 *   - also contains functions that grab segment addresses
 *   - will likely always be asm as it manipulates tlb directly
 */


/**
 * 1050	70000450	registers 70000000-70400000 in TLB, JR to 70000510
 *	technically, this is used in bootcode and used prior to TLB registration
 */
GLOBAL_ASM(
glabel boot
/* 001050 70000450 24020001 */  li    $v0, 1
/* 001054 70000454 24030000 */  li    $v1, 0
/* 001058 70000458 24040000 */  li    $a0, 0
/* 00105C 7000045C 3C057000 */  lui   $a1, 0x7000
/* 001060 70000460 2406001F */  li    $a2, 31
/* 001064 70000464 24070001 */  li    $a3, 1
/* 001068 70000468 3C08007F */  lui   $t0, (0x007FE000 >> 16) # lui $t0, 0x7f
/* 00106C 7000046C 3508E000 */  ori   $t0, (0x007FE000 & 0xFFFF) # ori $t0, $t0, 0xe000
/* 001070 70000470 40820000 */  mtc0  $v0, $0
/* 001074 70000474 00031B02 */  srl   $v1, $v1, 0xc
/* 001078 70000478 00031980 */  sll   $v1, $v1, 6
/* 00107C 7000047C 00661821 */  addu  $v1, $v1, $a2
/* 001080 70000480 40831000 */  mtc0  $v1, $2
/* 001084 70000484 00042302 */  srl   $a0, $a0, 0xc
/* 001088 70000488 00042180 */  sll   $a0, $a0, 6
/* 00108C 7000048C 00872021 */  addu  $a0, $a0, $a3
/* 001090 70000490 40841800 */  mtc0  $a0, $3
/* 001094 70000494 00052342 */  srl   $a0, $a1, 0xd
/* 001098 70000498 00042340 */  sll   $a0, $a0, 0xd
/* 00109C 7000049C 40845000 */  mtc0  $a0, $10
/* 0010A0 700004A0 40882800 */  mtc0  $t0, $5
/* 0010A4 700004A4 00000000 */  nop   
/* 0010A8 700004A8 42000002 */  tlbwi 
/* 0010AC 700004AC 3C0A7000 */  lui   $t2, %hi(init) # $t2, 0x7000
/* 0010B0 700004B0 254A0510 */  addiu $t2, %lo(init) # addiu $t2, $t2, 0x510
/* 0010B4 700004B4 01400008 */  jr    $t2
/* 0010B8 700004B8 00000000 */   nop
)

/**
 * Due to alignments the following functions are included here
 * these could have been assembly originally, or more likely part
 * of the code inserted by the custom makerom rare created
 */

/**
 *10BC	700004BC	V0=80020D90: target address for 21990 (USA)
 */
u32 *get_csegmentSegmentStart(void)
{
	return &_csegmentSegmentStart;
}

/**
 *10C8	700004C8	V0=21990: ROM address of main compressed block (USA)
 */
u32 *get_cdataSegmentRomStart(void)
{
	return &_cdataSegmentRomStart;
}

/**
 *10D4	700004D4	V0=33590: ROM address of 70200000 RareZip ASM [33590-34B30 ROM] (USA)
 */
u32 *get_cdataSegmentRomEnd(void)
{
	return &_cdataSegmentRomEnd;
}

/**
 *10E0	700004E0	V0=33590: ROM address of 70200000 RareZip ASM [33590-34B30 ROM] (USA)
 */
u32 *get_rarezipSegmentRomStart(void)
{
	return &_rarezipSegmentRomStart;
}

/**
 *10EC	700004EC	V0=34B30: ROM address of 7F- TLB routines (USA)
 */
u32 *get_rarezipSegmentRomEnd(void)
{
	return &_rarezipSegmentRomEnd;
}

/**
 * 10F8	700004F8	redirect to 7020141C: decompression routine
 *	accepts: A0=p->source, A1=p->target, A2=p->buffer
 *	sets A3=7020141C, then jumps to address
 */
GLOBAL_ASM(
glabel jump_decompressfile
/* 0010F8 700004F8 3C077020 */  lui   $a3, %hi(decompress_entry) # $a3, 0x7020
/* 0010FC 700004FC 24E7141C */  addiu $a3, %lo(decompress_entry) # addiu $a3, $a3, 0x141c
/* 001100 70000500 00E00008 */  jr    $a3
/* 001104 70000504 00000000 */   nop
)
