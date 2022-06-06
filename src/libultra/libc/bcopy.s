# asm file.
#
# TODO: this is an -O1 match, the libultra version is -O2 using IDO `as` toolchain.

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"   
glabel bcopy
/* 010570 7000F970 10C0001A */  beqz  $a2, .L7000F9DC
/* 010574 7000F974 00A03825 */   move  $a3, $a1
/* 010578 7000F978 10850018 */  beq   $a0, $a1, .L7000F9DC
/* 01057C 7000F97C 00A4082A */   slt   $at, $a1, $a0
/* 010580 7000F980 54200008 */  bnezl $at, .L7000F9A4
/* 010584 7000F984 28C10010 */   slti  $at, $a2, 0x10
/* 010588 7000F988 00861020 */  add   $v0, $a0, $a2
/* 01058C 7000F98C 00A2082A */  slt   $at, $a1, $v0
/* 010590 7000F990 50200004 */  beql  $at, $zero, .L7000F9A4
/* 010594 7000F994 28C10010 */   slti  $at, $a2, 0x10
/* 010598 7000F998 1000005B */  b     .L7000FB08
/* 01059C 7000F99C 28C10010 */   slti  $at, $a2, 0x10
/* 0105A0 7000F9A0 28C10010 */  slti  $at, $a2, 0x10
.L7000F9A4:
/* 0105A4 7000F9A4 14200005 */  bnez  $at, .L7000F9BC
/* 0105A8 7000F9A8 00000000 */   nop   
/* 0105AC 7000F9AC 30820003 */  andi  $v0, $a0, 3
/* 0105B0 7000F9B0 30A30003 */  andi  $v1, $a1, 3
/* 0105B4 7000F9B4 1043000B */  beq   $v0, $v1, .L7000F9E4
/* 0105B8 7000F9B8 00000000 */   nop   
.L7000F9BC:
/* 0105BC 7000F9BC 10C00007 */  beqz  $a2, .L7000F9DC
/* 0105C0 7000F9C0 00000000 */   nop   
/* 0105C4 7000F9C4 00861821 */  addu  $v1, $a0, $a2
.L7000F9C8:
/* 0105C8 7000F9C8 80820000 */  lb    $v0, ($a0)
/* 0105CC 7000F9CC 24840001 */  addiu $a0, $a0, 1
/* 0105D0 7000F9D0 24A50001 */  addiu $a1, $a1, 1
/* 0105D4 7000F9D4 1483FFFC */  bne   $a0, $v1, .L7000F9C8
/* 0105D8 7000F9D8 A0A2FFFF */   sb    $v0, -1($a1)
.L7000F9DC:
/* 0105DC 7000F9DC 03E00008 */  jr    $ra
/* 0105E0 7000F9E0 00E01025 */   move  $v0, $a3

.L7000F9E4:
/* 0105E4 7000F9E4 10400018 */  beqz  $v0, .L7000FA48
/* 0105E8 7000F9E8 24010001 */   li    $at, 1
/* 0105EC 7000F9EC 1041000F */  beq   $v0, $at, .L7000FA2C
/* 0105F0 7000F9F0 24010002 */   li    $at, 2
/* 0105F4 7000F9F4 50410008 */  beql  $v0, $at, .L7000FA18
/* 0105F8 7000F9F8 84820000 */   lh    $v0, ($a0)
/* 0105FC 7000F9FC 80820000 */  lb    $v0, ($a0)
/* 010600 7000FA00 24840001 */  addiu $a0, $a0, 1
/* 010604 7000FA04 24A50001 */  addiu $a1, $a1, 1
/* 010608 7000FA08 24C6FFFF */  addiu $a2, $a2, -1
/* 01060C 7000FA0C 1000000E */  b     .L7000FA48
/* 010610 7000FA10 A0A2FFFF */   sb    $v0, -1($a1)
/* 010614 7000FA14 84820000 */  lh    $v0, ($a0)
.L7000FA18:
/* 010618 7000FA18 24840002 */  addiu $a0, $a0, 2
/* 01061C 7000FA1C 24A50002 */  addiu $a1, $a1, 2
/* 010620 7000FA20 24C6FFFE */  addiu $a2, $a2, -2
/* 010624 7000FA24 10000008 */  b     .L7000FA48
/* 010628 7000FA28 A4A2FFFE */   sh    $v0, -2($a1)
.L7000FA2C:
/* 01062C 7000FA2C 80820000 */  lb    $v0, ($a0)
/* 010630 7000FA30 84830001 */  lh    $v1, 1($a0)
/* 010634 7000FA34 24840003 */  addiu $a0, $a0, 3
/* 010638 7000FA38 24A50003 */  addiu $a1, $a1, 3
/* 01063C 7000FA3C 24C6FFFD */  addiu $a2, $a2, -3
/* 010640 7000FA40 A0A2FFFD */  sb    $v0, -3($a1)
/* 010644 7000FA44 A4A3FFFE */  sh    $v1, -2($a1)
.L7000FA48:
/* 010648 7000FA48 28C10020 */  slti  $at, $a2, 0x20
/* 01064C 7000FA4C 54200016 */  bnezl $at, .L7000FAA8
/* 010650 7000FA50 28C10010 */   slti  $at, $a2, 0x10
/* 010654 7000FA54 8C820000 */  lw    $v0, ($a0)
/* 010658 7000FA58 8C830004 */  lw    $v1, 4($a0)
/* 01065C 7000FA5C 8C880008 */  lw    $t0, 8($a0)
/* 010660 7000FA60 8C89000C */  lw    $t1, 0xc($a0)
/* 010664 7000FA64 8C8A0010 */  lw    $t2, 0x10($a0)
/* 010668 7000FA68 8C8B0014 */  lw    $t3, 0x14($a0)
/* 01066C 7000FA6C 8C8C0018 */  lw    $t4, 0x18($a0)
/* 010670 7000FA70 8C8D001C */  lw    $t5, 0x1c($a0)
/* 010674 7000FA74 24840020 */  addiu $a0, $a0, 0x20
/* 010678 7000FA78 24A50020 */  addiu $a1, $a1, 0x20
/* 01067C 7000FA7C 24C6FFE0 */  addiu $a2, $a2, -0x20
/* 010680 7000FA80 ACA2FFE0 */  sw    $v0, -0x20($a1)
/* 010684 7000FA84 ACA3FFE4 */  sw    $v1, -0x1c($a1)
/* 010688 7000FA88 ACA8FFE8 */  sw    $t0, -0x18($a1)
/* 01068C 7000FA8C ACA9FFEC */  sw    $t1, -0x14($a1)
/* 010690 7000FA90 ACAAFFF0 */  sw    $t2, -0x10($a1)
/* 010694 7000FA94 ACABFFF4 */  sw    $t3, -0xc($a1)
/* 010698 7000FA98 ACACFFF8 */  sw    $t4, -8($a1)
/* 01069C 7000FA9C 1000FFEA */  b     .L7000FA48
/* 0106A0 7000FAA0 ACADFFFC */   sw    $t5, -4($a1)
.L7000FAA4:
/* 0106A4 7000FAA4 28C10010 */  slti  $at, $a2, 0x10
.L7000FAA8:
/* 0106A8 7000FAA8 5420000E */  bnezl $at, .L7000FAE4
/* 0106AC 7000FAAC 28C10004 */   slti  $at, $a2, 4
/* 0106B0 7000FAB0 8C820000 */  lw    $v0, ($a0)
/* 0106B4 7000FAB4 8C830004 */  lw    $v1, 4($a0)
/* 0106B8 7000FAB8 8C880008 */  lw    $t0, 8($a0)
/* 0106BC 7000FABC 8C89000C */  lw    $t1, 0xc($a0)
/* 0106C0 7000FAC0 24840010 */  addiu $a0, $a0, 0x10
/* 0106C4 7000FAC4 24A50010 */  addiu $a1, $a1, 0x10
/* 0106C8 7000FAC8 24C6FFF0 */  addiu $a2, $a2, -0x10
/* 0106CC 7000FACC ACA2FFF0 */  sw    $v0, -0x10($a1)
/* 0106D0 7000FAD0 ACA3FFF4 */  sw    $v1, -0xc($a1)
/* 0106D4 7000FAD4 ACA8FFF8 */  sw    $t0, -8($a1)
/* 0106D8 7000FAD8 1000FFF2 */  b     .L7000FAA4
/* 0106DC 7000FADC ACA9FFFC */   sw    $t1, -4($a1)
.L7000FAE0:
/* 0106E0 7000FAE0 28C10004 */  slti  $at, $a2, 4
.L7000FAE4:
/* 0106E4 7000FAE4 1420FFB5 */  bnez  $at, .L7000F9BC
/* 0106E8 7000FAE8 00000000 */   nop   
/* 0106EC 7000FAEC 8C820000 */  lw    $v0, ($a0)
/* 0106F0 7000FAF0 24840004 */  addiu $a0, $a0, 4
/* 0106F4 7000FAF4 24A50004 */  addiu $a1, $a1, 4
/* 0106F8 7000FAF8 24C6FFFC */  addiu $a2, $a2, -4
/* 0106FC 7000FAFC 1000FFF8 */  b     .L7000FAE0
/* 010700 7000FB00 ACA2FFFC */   sw    $v0, -4($a1)
/* 010704 7000FB04 28C10010 */  slti  $at, $a2, 0x10
.L7000FB08:
/* 010708 7000FB08 00862020 */  add   $a0, $a0, $a2
/* 01070C 7000FB0C 14200005 */  bnez  $at, .L7000FB24
/* 010710 7000FB10 00A62820 */   add   $a1, $a1, $a2
/* 010714 7000FB14 30820003 */  andi  $v0, $a0, 3
/* 010718 7000FB18 30A30003 */  andi  $v1, $a1, 3
/* 01071C 7000FB1C 1043000D */  beq   $v0, $v1, .L7000FB54
/* 010720 7000FB20 00000000 */   nop   
.L7000FB24:
/* 010724 7000FB24 10C0FFAD */  beqz  $a2, .L7000F9DC
/* 010728 7000FB28 00000000 */   nop   
/* 01072C 7000FB2C 2484FFFF */  addiu $a0, $a0, -1
/* 010730 7000FB30 24A5FFFF */  addiu $a1, $a1, -1
/* 010734 7000FB34 00861823 */  subu  $v1, $a0, $a2
.L7000FB38:
/* 010738 7000FB38 80820000 */  lb    $v0, ($a0)
/* 01073C 7000FB3C 2484FFFF */  addiu $a0, $a0, -1
/* 010740 7000FB40 24A5FFFF */  addiu $a1, $a1, -1
/* 010744 7000FB44 1483FFFC */  bne   $a0, $v1, .L7000FB38
/* 010748 7000FB48 A0A20001 */   sb    $v0, 1($a1)
/* 01074C 7000FB4C 03E00008 */  jr    $ra
/* 010750 7000FB50 00E01025 */   move  $v0, $a3

.L7000FB54:
/* 010754 7000FB54 10400018 */  beqz  $v0, .L7000FBB8
/* 010758 7000FB58 24010003 */   li    $at, 3
/* 01075C 7000FB5C 1041000F */  beq   $v0, $at, .L7000FB9C
/* 010760 7000FB60 24010002 */   li    $at, 2
/* 010764 7000FB64 50410008 */  beql  $v0, $at, .L7000FB88
/* 010768 7000FB68 8482FFFE */   lh    $v0, -2($a0)
/* 01076C 7000FB6C 8082FFFF */  lb    $v0, -1($a0)
/* 010770 7000FB70 2484FFFF */  addiu $a0, $a0, -1
/* 010774 7000FB74 24A5FFFF */  addiu $a1, $a1, -1
/* 010778 7000FB78 24C6FFFF */  addiu $a2, $a2, -1
/* 01077C 7000FB7C 1000000E */  b     .L7000FBB8
/* 010780 7000FB80 A0A20000 */   sb    $v0, ($a1)
/* 010784 7000FB84 8482FFFE */  lh    $v0, -2($a0)
.L7000FB88:
/* 010788 7000FB88 2484FFFE */  addiu $a0, $a0, -2
/* 01078C 7000FB8C 24A5FFFE */  addiu $a1, $a1, -2
/* 010790 7000FB90 24C6FFFE */  addiu $a2, $a2, -2
/* 010794 7000FB94 10000008 */  b     .L7000FBB8
/* 010798 7000FB98 A4A20000 */   sh    $v0, ($a1)
.L7000FB9C:
/* 01079C 7000FB9C 8082FFFF */  lb    $v0, -1($a0)
/* 0107A0 7000FBA0 8483FFFD */  lh    $v1, -3($a0)
/* 0107A4 7000FBA4 2484FFFD */  addiu $a0, $a0, -3
/* 0107A8 7000FBA8 24A5FFFD */  addiu $a1, $a1, -3
/* 0107AC 7000FBAC 24C6FFFD */  addiu $a2, $a2, -3
/* 0107B0 7000FBB0 A0A20002 */  sb    $v0, 2($a1)
/* 0107B4 7000FBB4 A4A30000 */  sh    $v1, ($a1)
.L7000FBB8:
/* 0107B8 7000FBB8 28C10020 */  slti  $at, $a2, 0x20
/* 0107BC 7000FBBC 54200016 */  bnezl $at, .L7000FC18
/* 0107C0 7000FBC0 28C10010 */   slti  $at, $a2, 0x10
/* 0107C4 7000FBC4 8C82FFFC */  lw    $v0, -4($a0)
/* 0107C8 7000FBC8 8C83FFF8 */  lw    $v1, -8($a0)
/* 0107CC 7000FBCC 8C88FFF4 */  lw    $t0, -0xc($a0)
/* 0107D0 7000FBD0 8C89FFF0 */  lw    $t1, -0x10($a0)
/* 0107D4 7000FBD4 8C8AFFEC */  lw    $t2, -0x14($a0)
/* 0107D8 7000FBD8 8C8BFFE8 */  lw    $t3, -0x18($a0)
/* 0107DC 7000FBDC 8C8CFFE4 */  lw    $t4, -0x1c($a0)
/* 0107E0 7000FBE0 8C8DFFE0 */  lw    $t5, -0x20($a0)
/* 0107E4 7000FBE4 2484FFE0 */  addiu $a0, $a0, -0x20
/* 0107E8 7000FBE8 24A5FFE0 */  addiu $a1, $a1, -0x20
/* 0107EC 7000FBEC 24C6FFE0 */  addiu $a2, $a2, -0x20
/* 0107F0 7000FBF0 ACA2001C */  sw    $v0, 0x1c($a1)
/* 0107F4 7000FBF4 ACA30018 */  sw    $v1, 0x18($a1)
/* 0107F8 7000FBF8 ACA80014 */  sw    $t0, 0x14($a1)
/* 0107FC 7000FBFC ACA90010 */  sw    $t1, 0x10($a1)
/* 010800 7000FC00 ACAA000C */  sw    $t2, 0xc($a1)
/* 010804 7000FC04 ACAB0008 */  sw    $t3, 8($a1)
/* 010808 7000FC08 ACAC0004 */  sw    $t4, 4($a1)
/* 01080C 7000FC0C 1000FFEA */  b     .L7000FBB8
/* 010810 7000FC10 ACAD0000 */   sw    $t5, ($a1)
.L7000FC14:
/* 010814 7000FC14 28C10010 */  slti  $at, $a2, 0x10
.L7000FC18:
/* 010818 7000FC18 5420000E */  bnezl $at, .L7000FC54
/* 01081C 7000FC1C 28C10004 */   slti  $at, $a2, 4
/* 010820 7000FC20 8C82FFFC */  lw    $v0, -4($a0)
/* 010824 7000FC24 8C83FFF8 */  lw    $v1, -8($a0)
/* 010828 7000FC28 8C88FFF4 */  lw    $t0, -0xc($a0)
/* 01082C 7000FC2C 8C89FFF0 */  lw    $t1, -0x10($a0)
/* 010830 7000FC30 2484FFF0 */  addiu $a0, $a0, -0x10
/* 010834 7000FC34 24A5FFF0 */  addiu $a1, $a1, -0x10
/* 010838 7000FC38 24C6FFF0 */  addiu $a2, $a2, -0x10
/* 01083C 7000FC3C ACA2000C */  sw    $v0, 0xc($a1)
/* 010840 7000FC40 ACA30008 */  sw    $v1, 8($a1)
/* 010844 7000FC44 ACA80004 */  sw    $t0, 4($a1)
/* 010848 7000FC48 1000FFF2 */  b     .L7000FC14
/* 01084C 7000FC4C ACA90000 */   sw    $t1, ($a1)
.L7000FC50:
/* 010850 7000FC50 28C10004 */  slti  $at, $a2, 4
.L7000FC54:
/* 010854 7000FC54 1420FFB3 */  bnez  $at, .L7000FB24
/* 010858 7000FC58 00000000 */   nop   
/* 01085C 7000FC5C 8C82FFFC */  lw    $v0, -4($a0)
/* 010860 7000FC60 2484FFFC */  addiu $a0, $a0, -4
/* 010864 7000FC64 24A5FFFC */  addiu $a1, $a1, -4
/* 010868 7000FC68 24C6FFFC */  addiu $a2, $a2, -4
/* 01086C 7000FC6C 1000FFF8 */  b     .L7000FC50
/* 010870 7000FC70 ACA20000 */   sw    $v0, ($a1)

