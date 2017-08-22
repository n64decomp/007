# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"


.global proc_700006FC
proc_700006FC:
/* 0012FC 700006FC 240E0001 */  addiu $t6, $zero, 1
/* 001300 70000700 3C018002 */  lui   $at, %hi(unknown_init_val)
/* 001304 70000704 AC2E3044 */  sw    $t6, %lo(unknown_init_val)($at) # $t6, 0x3044($at)
/* 001308 70000708 3C018002 */  lui   $at, %hi(cart_hw_address)
/* 00130C 7000070C 3C0F1000 */  lui   $t7, %hi(0x10000000)
/* 001310 70000710 03E00008 */  jr    $ra
/* 001314 70000714 AC2F3048 */  sw    $t7, %lo(cart_hw_address)($at) # $t7, 0x3048($at)
# end proc_700006FC

.section .data

#referenced by proc_700006FC
unknown_init_val:
.word 0x00000002

#referenced by proc_700006FC
cart_hw_address:
.word 0x10000000
