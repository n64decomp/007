# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel osSetIntMask
/* 00E930 7000DD30 400C6000 */  mfc0  $t4, $12
/* 00E934 7000DD34 3182FF01 */  andi  $v0, $t4, 0xff01
/* 00E938 7000DD38 3C088002 */  lui   $t0, %hi(__OSGlobalIntMask) 
/* 00E93C 7000DD3C 2508698C */  addiu $t0, %lo(__OSGlobalIntMask) # addiu $t0, $t0, 0x698c
/* 00E940 7000DD40 8D0B0000 */  lw    $t3, ($t0)
/* 00E944 7000DD44 2401FFFF */  li    $at, -1
/* 00E948 7000DD48 01614026 */  xor   $t0, $t3, $at
/* 00E94C 7000DD4C 3108FF00 */  andi  $t0, $t0, 0xff00
/* 00E950 7000DD50 00481025 */  or    $v0, $v0, $t0
/* 00E954 7000DD54 3C0AA430 */  lui   $t2, %hi(MI_INTR_MASK_REG) # $t2, 0xa430
/* 00E958 7000DD58 8D4A000C */  lw    $t2, %lo(MI_INTR_MASK_REG)($t2)
/* 00E95C 7000DD5C 11400005 */  beqz  $t2, .L7000DD74
/* 00E960 7000DD60 000B4C02 */   srl   $t1, $t3, 0x10
/* 00E964 7000DD64 2401FFFF */  li    $at, -1
/* 00E968 7000DD68 01214826 */  xor   $t1, $t1, $at
/* 00E96C 7000DD6C 3129003F */  andi  $t1, $t1, 0x3f
/* 00E970 7000DD70 01495025 */  or    $t2, $t2, $t1
.L7000DD74:
/* 00E974 7000DD74 000A5400 */  sll   $t2, $t2, 0x10
/* 00E978 7000DD78 004A1025 */  or    $v0, $v0, $t2
/* 00E97C 7000DD7C 3C01003F */  lui   $at, 0x3f
/* 00E980 7000DD80 00814024 */  and   $t0, $a0, $at
/* 00E984 7000DD84 010B4024 */  and   $t0, $t0, $t3
/* 00E988 7000DD88 000843C2 */  srl   $t0, $t0, 0xf
/* 00E98C 7000DD8C 3C0A8003 */  lui   $t2, %hi(__osRcpImTable)
/* 00E990 7000DD90 01485021 */  addu  $t2, $t2, $t0
/* 00E994 7000DD94 954A93A0 */  lhu   $t2, %lo(__osRcpImTable)($t2)
/* 00E998 7000DD98 3C01A430 */  lui   $at, %hi(MI_INTR_MASK_REG) # $at, 0xa430
/* 00E99C 7000DD9C AC2A000C */  sw    $t2, %lo(MI_INTR_MASK_REG)($at)
/* 00E9A0 7000DDA0 3088FF01 */  andi  $t0, $a0, 0xff01
/* 00E9A4 7000DDA4 3169FF00 */  andi  $t1, $t3, 0xff00
/* 00E9A8 7000DDA8 01094024 */  and   $t0, $t0, $t1
/* 00E9AC 7000DDAC 3C01FFFF */  lui   $at, (0xFFFF00FF >> 16) # lui $at, 0xffff
/* 00E9B0 7000DDB0 342100FF */  ori   $at, (0xFFFF00FF & 0xFFFF) # ori $at, $at, 0xff
/* 00E9B4 7000DDB4 01816024 */  and   $t4, $t4, $at
/* 00E9B8 7000DDB8 01886025 */  or    $t4, $t4, $t0
/* 00E9BC 7000DDBC 408C6000 */  mtc0  $t4, $12
/* 00E9C0 7000DDC0 00000000 */  nop   
/* 00E9C4 7000DDC4 00000000 */  nop   
/* 00E9C8 7000DDC8 03E00008 */  jr    $ra
/* 00E9CC 7000DDCC 00000000 */   nop   

.section .rodata
glabel __osRcpImTable
	.half 0x555, 0x556, 0x559, 0x55a, 0x565, 0x566, 0x569, 0x56a
	.half 0x595, 0x596, 0x599, 0x59a, 0x5a5, 0x5a6, 0x5a9, 0x5aa
	.half 0x655, 0x656, 0x659, 0x65a, 0x665, 0x666, 0x669, 0x66a
	.half 0x695, 0x696, 0x699, 0x69a, 0x6a5, 0x6a6, 0x6a9, 0x6aa
	.half 0x955, 0x956, 0x959, 0x95a, 0x965, 0x966, 0x969, 0x96a
	.half 0x995, 0x996, 0x999, 0x99a, 0x9a5, 0x9a6, 0x9a9, 0x9aa
	.half 0xa55, 0xa56, 0xa59, 0xa5a, 0xa65, 0xa66, 0xa69, 0xa6a
	.half 0xa95, 0xa96, 0xa99, 0xa9a, 0xaa5, 0xaa6, 0xaa9, 0xaaa
