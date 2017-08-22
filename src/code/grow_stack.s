# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

/*
 int __cdecl grow_stack(int baseaddress, int stacksize)
*/
.global grow_stack
grow_stack:

.equ baseaddress, $a0
.equ stacksize, $a1

/* 0012F0 700006F0 00851021 */  addu  $v0, baseaddress, stacksize
/* 0012F4 700006F4 03E00008 */  jr    $ra
/* 0012F8 700006F8 2442FFF8 */  addiu $v0, $v0, -8
# end grow_stack
