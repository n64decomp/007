# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


# This code is handling a TLB miss by calculating the physical address that
# corresponds to the virtual address that caused the miss, loading a 
# TLB entry from a management table, and writing the entry to the TLB. 
# After this, the instruction that caused the TLB miss can be retried.



.section .text, "ax"
glabel resolve_TLBaddress_for_InvalidHit
/* 002760 70001B60 40802800 */  mtc0  $zero, $5 
/* 002764 70001B64 00000000 */  nop   
/* 002768 70001B68 401A2000 */  mfc0  $k0, $4
/* 00276C 70001B6C 3C1B8006 */  lui   $k1, %hi(g_tlbmanageMappingTableEnd) # $k1, 0x8006
/* 002770 70001B70 277BE4A4 */  addiu $k1, %lo(g_tlbmanageMappingTableEnd) # addiu $k1, $k1, -0x1b5c
/* 002774 70001B74 8F7B0000 */  lw    $k1, ($k1)
/* 002778 70001B78 035BD021 */  addu  $k0, $k0, $k1
/* 00277C 70001B7C 8F5B0000 */  lw    $k1, ($k0)
/* 002780 70001B80 409B1000 */  mtc0  $k1, $2
/* 002784 70001B84 00000000 */  nop   
/* 002788 70001B88 277B0040 */  addiu $k1, $k1, 0x40
/* 00278C 70001B8C 409B1800 */  mtc0  $k1, $3
/* 002790 70001B90 00000000 */  nop   
/* 002794 70001B94 42000006 */  tlbwr
/* 002798 70001B98 00000000 */  nop   
/* 00279C 70001B9C 00000000 */  nop   
/* 0027A0 70001BA0 00000000 */  nop   
/* 0027A4 70001BA4 00000000 */  nop   
/* 0027A8 70001BA8 42000018 */  eret  
.size resolve_TLBaddress_for_InvalidHit, . - resolve_TLBaddress_for_InvalidHit





