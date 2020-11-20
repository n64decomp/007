# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"


glabel osPiRawStartDma
/* 00DB90 7000CF90 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00DB94 7000CF94 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00DB98 7000CF98 AFA40028 */  sw    $a0, 0x28($sp)
/* 00DB9C 7000CF9C AFA5002C */  sw    $a1, 0x2c($sp)
/* 00DBA0 7000CFA0 AFA60030 */  sw    $a2, 0x30($sp)
/* 00DBA4 7000CFA4 AFA70034 */  sw    $a3, 0x34($sp)
/* 00DBA8 7000CFA8 AFB10018 */  sw    $s1, 0x18($sp)
/* 00DBAC 7000CFAC AFB00014 */  sw    $s0, 0x14($sp)
/* 00DBB0 7000CFB0 3C0EA460 */  lui   $t6, %hi(PI_STATUS_REG) # $t6, 0xa460
/* 00DBB4 7000CFB4 8DD00010 */  lw    $s0, %lo(PI_STATUS_REG)($t6)
/* 00DBB8 7000CFB8 320F0003 */  andi  $t7, $s0, 3
/* 00DBBC 7000CFBC 11E00006 */  beqz  $t7, .L7000CFD8
/* 00DBC0 7000CFC0 00000000 */   nop   
.L7000CFC4:
/* 00DBC4 7000CFC4 3C18A460 */  lui   $t8, %hi(PI_STATUS_REG) # $t8, 0xa460
/* 00DBC8 7000CFC8 8F100010 */  lw    $s0, %lo(PI_STATUS_REG)($t8)
/* 00DBCC 7000CFCC 32190003 */  andi  $t9, $s0, 3
/* 00DBD0 7000CFD0 1720FFFC */  bnez  $t9, .L7000CFC4
/* 00DBD4 7000CFD4 00000000 */   nop   
.L7000CFD8:
/* 00DBD8 7000CFD8 0C003A2C */  jal   osVirtualToPhysical
/* 00DBDC 7000CFDC 8FA40030 */   lw    $a0, 0x30($sp)
/* 00DBE0 7000CFE0 3C08A460 */  lui   $t0, 0xa460
/* 00DBE4 7000CFE4 AD020000 */  sw    $v0, ($t0)
/* 00DBE8 7000CFE8 3C098000 */  lui   $t1, %hi(osRomBase) 
/* 00DBEC 7000CFEC 8D290308 */  lw    $t1, %lo(osRomBase)($t1)
/* 00DBF0 7000CFF0 8FAA002C */  lw    $t2, 0x2c($sp)
/* 00DBF4 7000CFF4 3C011FFF */  lui   $at, (0x1FFFFFFF >> 16) # lui $at, 0x1fff
/* 00DBF8 7000CFF8 3421FFFF */  ori   $at, (0x1FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 00DBFC 7000CFFC 012A5825 */  or    $t3, $t1, $t2
/* 00DC00 7000D000 01616024 */  and   $t4, $t3, $at
/* 00DC04 7000D004 3C0DA460 */  lui   $t5, %hi(PI_CART_ADDR_REG) # $t5, 0xa460
/* 00DC08 7000D008 ADAC0004 */  sw    $t4, %lo(PI_CART_ADDR_REG)($t5)
/* 00DC0C 7000D00C 8FB10028 */  lw    $s1, 0x28($sp)
/* 00DC10 7000D010 12200005 */  beqz  $s1, .L7000D028
/* 00DC14 7000D014 24010001 */   li    $at, 1
/* 00DC18 7000D018 12210008 */  beq   $s1, $at, .L7000D03C
/* 00DC1C 7000D01C 00000000 */   nop   
/* 00DC20 7000D020 1000000B */  b     .L7000D050
/* 00DC24 7000D024 00000000 */   nop   
.L7000D028:
/* 00DC28 7000D028 8FAE0034 */  lw    $t6, 0x34($sp)
/* 00DC2C 7000D02C 3C18A460 */  lui   $t8, %hi(PI_WR_LEN_REG) # $t8, 0xa460
/* 00DC30 7000D030 25CFFFFF */  addiu $t7, $t6, -1
/* 00DC34 7000D034 10000008 */  b     .L7000D058
/* 00DC38 7000D038 AF0F000C */   sw    $t7, %lo(PI_WR_LEN_REG)($t8)
.L7000D03C:
/* 00DC3C 7000D03C 8FB90034 */  lw    $t9, 0x34($sp)
/* 00DC40 7000D040 3C09A460 */  lui   $t1, %hi(PI_RD_LEN_REG) # $t1, 0xa460
/* 00DC44 7000D044 2728FFFF */  addiu $t0, $t9, -1
/* 00DC48 7000D048 10000003 */  b     .L7000D058
/* 00DC4C 7000D04C AD280008 */   sw    $t0, %lo(PI_RD_LEN_REG)($t1)
.L7000D050:
/* 00DC50 7000D050 10000002 */  b     .L7000D05C
/* 00DC54 7000D054 2402FFFF */   li    $v0, -1
.L7000D058:
/* 00DC58 7000D058 00001025 */  move  $v0, $zero
.L7000D05C:
/* 00DC5C 7000D05C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00DC60 7000D060 8FB00014 */  lw    $s0, 0x14($sp)
/* 00DC64 7000D064 8FB10018 */  lw    $s1, 0x18($sp)
/* 00DC68 7000D068 03E00008 */  jr    $ra
/* 00DC6C 7000D06C 27BD0028 */   addiu $sp, $sp, 0x28
