# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

#include "regdef.h"
#include "asm.h"
#include <R4300.h>

.include "macros.inc"


.section .text, "ax"

/**
 * 29B0	70001BB0
 * initTLBPrepareContext
 * C0_WIRED: If set 2 or 3, TLB entries can be wired downwards
 * C0_CONTEXT: If 0 then exceptions cause the virtual address to be written in the context
 */
glabel initTLBPrepareContext
/* 0027B0 70001BB0 24080002 */  li    $t0, 2
/* 0027B4 70001BB4 40883000 */  mtc0  $t0, $6 #C0_WIRED
/* 0027B8 70001BB8 24080000 */  li    $t0, 0
/* 0027BC 70001BBC 40882000 */  mtc0  $t0, $4 #C0_CONTEXT
/* 0027C0 70001BC0 03E00008 */  jr    $ra
/* 0027C4 70001BC4 00000000 */   nop  
.size initTLBPrepareContext, . - initTLBPrepareContext