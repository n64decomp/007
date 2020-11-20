#include "ultra64.h"

/**
 * @file debug_getlastRA.c
 * This file contains code to get last return address on stack.
 */


/**
 * 6710	70005B10
 *     V0=value of RA previously saved to the stack or -1 if impossible to retrieve
 *     Searches backward from caller for last instance of RA saved to stack.
 */
#ifdef NONMATCHING
s32 return_last_RA_saved_to_stack(undefined4 param_1) {
  uint uVar1;
  uint *unaff_retaddr;
  s32 auStackX0 [4];
  
  while( true ) {
    uVar1 = *unaff_retaddr >> 0x10;
    if (uVar1 == 0x27bd) {
      return -1;
    }
    if (uVar1 == 0xafbf) break;
    unaff_retaddr = unaff_retaddr + -1;
  }
  return *(s32 *)((int)auStackX0 + (int)(short)*unaff_retaddr);
}
#else
GLOBAL_ASM(
.text
glabel return_last_RA_saved_to_stack
/* 006710 70005B10 03E02025 */  move  $a0, $ra
/* 006714 70005B14 2402FFFF */  li    $v0, -1
glabel .L70005B18
/* 006718 70005B18 8C880000 */  lw    $t0, ($a0)
/* 00671C 70005B1C 240A27BD */  li    $t2, 10173
/* 006720 70005B20 00084C02 */  srl   $t1, $t0, 0x10
/* 006724 70005B24 112A000A */  beq   $t1, $t2, .L70005B50
/* 006728 70005B28 00000000 */   nop   
/* 00672C 70005B2C 340AAFBF */  li    $t2, 44991
/* 006730 70005B30 512A0004 */  beql  $t1, $t2, .L70005B44
/* 006734 70005B34 00085400 */   sll   $t2, $t0, 0x10
/* 006738 70005B38 080016C6 */  j     .L70005B18
/* 00673C 70005B3C 2484FFFC */   addiu $a0, $a0, -4
/* 006740 70005B40 00085400 */  sll   $t2, $t0, 0x10
.L70005B44:
/* 006744 70005B44 000A5403 */  sra   $t2, $t2, 0x10
/* 006748 70005B48 015D5020 */  add   $t2, $t2, $sp
/* 00674C 70005B4C 8D420000 */  lw    $v0, ($t2)
.L70005B50:
/* 006750 70005B50 03E00008 */  jr    $ra
/* 006754 70005B54 00000000 */   nop   
)
#endif