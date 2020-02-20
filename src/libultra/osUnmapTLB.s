# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel osUnmapTLB
/* 00DFD0 7000D3D0 40085000 */  mfc0  $t0, $10
/* 00DFD4 7000D3D4 40840000 */  mtc0  $a0, $0
/* 00DFD8 7000D3D8 3C098000 */  lui   $t1, 0x8000
/* 00DFDC 7000D3DC 40895000 */  mtc0  $t1, $10
/* 00DFE0 7000D3E0 40801000 */  mtc0  $zero, $2
/* 00DFE4 7000D3E4 40801800 */  mtc0  $zero, $3
/* 00DFE8 7000D3E8 00000000 */  nop   
/* 00DFEC 7000D3EC 42000002 */  tlbwi 
/* 00DFF0 7000D3F0 00000000 */  nop   
/* 00DFF4 7000D3F4 00000000 */  nop   
/* 00DFF8 7000D3F8 00000000 */  nop   
/* 00DFFC 7000D3FC 00000000 */  nop   
/* 00E000 7000D400 40885000 */  mtc0  $t0, $10
/* 00E004 7000D404 03E00008 */  jr    $ra
/* 00E008 7000D408 00000000 */   nop   

