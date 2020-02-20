# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"

.section .data
glabel osClockRate
.dword 62500000
glabel __osShutdown
 .word 0
glabel __OSGlobalIntMask
 .word 0x3FFF01
glabel osDiskExist
 .word 0
.align 4
.section .rodata
.section .bss
glabel __osFinalRom
.word 0

.section .text, "ax"
glabel osInitialize
/* 00DC80 7000D080 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 00DC84 7000D084 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00DC88 7000D088 240E0001 */  li    $t6, 1
/* 00DC8C 7000D08C 3C018006 */  lui   $at, %hi(__osFinalRom)
/* 00DC90 7000D090 AFB00018 */  sw    $s0, 0x18($sp)
/* 00DC94 7000D094 AFA00038 */  sw    $zero, 0x38($sp)
/* 00DC98 7000D098 0C005ECC */  jal   __osGetSR
/* 00DC9C 7000D09C AC2E57E0 */   sw    $t6, %lo(__osFinalRom)($at)
/* 00DCA0 7000D0A0 00408025 */  move  $s0, $v0
/* 00DCA4 7000D0A4 3C012000 */  lui   $at, 0x2000
/* 00DCA8 7000D0A8 0C005EC8 */  jal   __osSetSR
/* 00DCAC 7000D0AC 02012025 */   or    $a0, $s0, $at
/* 00DCB0 7000D0B0 3C040100 */  lui   $a0, (0x01000800 >> 16) # lui $a0, 0x100
/* 00DCB4 7000D0B4 0C003508 */  jal   __osSetFpcCsr
/* 00DCB8 7000D0B8 34840800 */   ori   $a0, (0x01000800 & 0xFFFF) # ori $a0, $a0, 0x800
/* 00DCBC 7000D0BC 3C041FC0 */  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
/* 00DCC0 7000D0C0 348407FC */  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
/* 00DCC4 7000D0C4 0C005ED0 */  jal   __osSiRawReadIo
/* 00DCC8 7000D0C8 27A5003C */   addiu $a1, $sp, 0x3c
/* 00DCCC 7000D0CC 10400007 */  beqz  $v0, .L7000D0EC
/* 00DCD0 7000D0D0 00000000 */   nop   
.L7000D0D4:
/* 00DCD4 7000D0D4 3C041FC0 */  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
/* 00DCD8 7000D0D8 348407FC */  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
/* 00DCDC 7000D0DC 0C005ED0 */  jal   __osSiRawReadIo
/* 00DCE0 7000D0E0 27A5003C */   addiu $a1, $sp, 0x3c
/* 00DCE4 7000D0E4 1440FFFB */  bnez  $v0, .L7000D0D4
/* 00DCE8 7000D0E8 00000000 */   nop   
.L7000D0EC:
/* 00DCEC 7000D0EC 8FA5003C */  lw    $a1, 0x3c($sp)
/* 00DCF0 7000D0F0 3C041FC0 */  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
/* 00DCF4 7000D0F4 348407FC */  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
/* 00DCF8 7000D0F8 34AF0008 */  ori   $t7, $a1, 8
/* 00DCFC 7000D0FC 0C005EE4 */  jal   __osSiRawWriteIo
/* 00DD00 7000D100 01E02825 */   move  $a1, $t7
/* 00DD04 7000D104 10400009 */  beqz  $v0, .L7000D12C
/* 00DD08 7000D108 00000000 */   nop   
.L7000D10C:
/* 00DD0C 7000D10C 8FA5003C */  lw    $a1, 0x3c($sp)
/* 00DD10 7000D110 3C041FC0 */  lui   $a0, (0x1FC007FC >> 16) # lui $a0, 0x1fc0
/* 00DD14 7000D114 348407FC */  ori   $a0, (0x1FC007FC & 0xFFFF) # ori $a0, $a0, 0x7fc
/* 00DD18 7000D118 34B80008 */  ori   $t8, $a1, 8
/* 00DD1C 7000D11C 0C005EE4 */  jal   __osSiRawWriteIo
/* 00DD20 7000D120 03002825 */   move  $a1, $t8
/* 00DD24 7000D124 1440FFF9 */  bnez  $v0, .L7000D10C
/* 00DD28 7000D128 00000000 */   nop   
.L7000D12C:
/* 00DD2C 7000D12C 3C087001 */  lui   $t0, %hi(__osExceptionPreamble) # $t0, 0x7001
/* 00DD30 7000D130 25080190 */  addiu $t0, %lo(__osExceptionPreamble) # addiu $t0, $t0, 0x190
/* 00DD34 7000D134 8D010000 */  lw    $at, ($t0)
/* 00DD38 7000D138 3C198000 */  lui   $t9, 0x8000
/* 00DD3C 7000D13C 3C0D7001 */  lui   $t5, %hi(__osExceptionPreamble) # $t5, 0x7001
/* 00DD40 7000D140 AF210000 */  sw    $at, ($t9)
/* 00DD44 7000D144 8D0B0004 */  lw    $t3, 4($t0)
/* 00DD48 7000D148 25AD0190 */  addiu $t5, %lo(__osExceptionPreamble) # addiu $t5, $t5, 0x190
/* 00DD4C 7000D14C 3C0C8000 */  lui   $t4, 0x8000
/* 00DD50 7000D150 AF2B0004 */  sw    $t3, 4($t9)
/* 00DD54 7000D154 8D010008 */  lw    $at, 8($t0)
/* 00DD58 7000D158 358C0080 */  ori   $t4, (0x80000080 & 0xFFFF) # ori $t4, $t4, 0x80
/* 00DD5C 7000D15C 3C097001 */  lui   $t1, %hi(__osExceptionPreamble) # $t1, 0x7001
/* 00DD60 7000D160 AF210008 */  sw    $at, 8($t9)
/* 00DD64 7000D164 8D0B000C */  lw    $t3, 0xc($t0)
/* 00DD68 7000D168 25290190 */  addiu $t1, %lo(__osExceptionPreamble) # addiu $t1, $t1, 0x190
/* 00DD6C 7000D16C 3C0A8000 */  lui   $t2, 0x8000
/* 00DD70 7000D170 AF2B000C */  sw    $t3, 0xC($t9)
/* 00DD74 7000D174 8DA10000 */  lw    $at, 0($t5)
/* 00DD78 7000D178 354A0100 */  ori   $t2, (0x80000100 & 0xFFFF) # ori $t2, $t2, 0x100
/* 00DD7C 7000D17C 3C0E7001 */  lui   $t6, %hi(__osExceptionPreamble) # $t6, 0x7001
/* 00DD80 7000D180 AD810000 */  sw    $at, 0($t4)
/* 00DD84 7000D184 8DB80004 */  lw    $t8, 4($t5)
/* 00DD88 7000D188 25CE0190 */  addiu $t6, %lo(__osExceptionPreamble) # addiu $t6, $t6, 0x190
/* 00DD8C 7000D18C 3C0F8000 */  lui   $t7, 0x8000
/* 00DD90 7000D190 AD980004 */  sw    $t8, 4($t4)
/* 00DD94 7000D194 8DA10008 */  lw    $at, 8($t5)
/* 00DD98 7000D198 35EF0180 */  ori   $t7, (0x80000180 & 0xFFFF) # ori $t7, $t7, 0x180
/* 00DD9C 7000D19C 3C048000 */  lui   $a0, 0x8000
/* 00DDA0 7000D1A0 AD810008 */  sw    $at, 8($t4)
/* 00DDA4 7000D1A4 8DB8000C */  lw    $t8, 0xc($t5)
/* 00DDA8 7000D1A8 24050190 */  li    $a1, 400
/* 00DDAC 7000D1AC AD98000C */  sw    $t8, 0xC($t4)
/* 00DDB0 7000D1B0 8D210000 */  lw    $at, 0($t1)
/* 00DDB4 7000D1B4 AD410000 */  sw    $at, 0($t2)
/* 00DDB8 7000D1B8 8D2B0004 */  lw    $t3, 4($t1)
/* 00DDBC 7000D1BC AD4B0004 */  sw    $t3, 4($t2)
/* 00DDC0 7000D1C0 8D210008 */  lw    $at, 8($t1)
/* 00DDC4 7000D1C4 AD410008 */  sw    $at, 8($t2)
/* 00DDC8 7000D1C8 8D2B000C */  lw    $t3, 0xc($t1)
/* 00DDCC 7000D1CC AD4B000C */  sw    $t3, 0xC($t2)
/* 00DDD0 7000D1D0 8DC10000 */  lw    $at, 0($t6)
/* 00DDD4 7000D1D4 ADE10000 */  sw    $at, 0($t7)
/* 00DDD8 7000D1D8 8DD80004 */  lw    $t8, 4($t6)
/* 00DDDC 7000D1DC ADF80004 */  sw    $t8, 4($t7)
/* 00DDE0 7000D1E0 8DC10008 */  lw    $at, 8($t6)
/* 00DDE4 7000D1E4 ADE10008 */  sw    $at, 8($t7)
/* 00DDE8 7000D1E8 8DD8000C */  lw    $t8, 0xc($t6)
/* 00DDEC 7000D1EC 0C0042F4 */  jal   osWritebackDCache
/* 00DDF0 7000D1F0 ADF8000C */   sw    $t8, 0xC($t7)
/* 00DDF4 7000D1F4 3C048000 */  lui   $a0, 0x8000
/* 00DDF8 7000D1F8 0C0034D4 */  jal   osInvalICache
/* 00DDFC 7000D1FC 24050190 */   li    $a1, 400
/* 00DE00 7000D200 0C0005E0 */  jal   osMapTLBRdb
/* 00DE04 7000D204 00000000 */   nop   
/* 00DE08 7000D208 24040004 */  li    $a0, 4
/* 00DE0C 7000D20C 0C005EF8 */  jal   osPiRawReadIo
/* 00DE10 7000D210 27A50038 */   addiu $a1, $sp, 0x38
/* 00DE14 7000D214 8FA80038 */  lw    $t0, 0x38($sp)
/* 00DE18 7000D218 2401FFF0 */  li    $at, -16
/* 00DE1C 7000D21C 0101C824 */  and   $t9, $t0, $at
/* 00DE20 7000D220 13200006 */  beqz  $t9, .L7000D23C
/* 00DE24 7000D224 AFB90038 */   sw    $t9, 0x38($sp)
/* 00DE28 7000D228 3C018002 */  lui   $at, %hi(osClockRate)
/* 00DE2C 7000D22C 03205825 */  move  $t3, $t9
/* 00DE30 7000D230 240A0000 */  li    $t2, 0
/* 00DE34 7000D234 AC2A6980 */  sw    $t2, %lo(osClockRate)($at)
/* 00DE38 7000D238 AC2B6984 */  sw    $t3, %lo(osClockRate+4)($at)
.L7000D23C:
/* 00DE3C 7000D23C 3C048002 */  lui   $a0, %hi(osClockRate)
/* 00DE40 7000D240 3C058002 */  lui   $a1, %hi(osClockRate)
/* 00DE44 7000D244 8CA56984 */  lw    $a1, %lo(osClockRate+4)($a1)
/* 00DE48 7000D248 8C846980 */  lw    $a0, %lo(osClockRate)($a0)
/* 00DE4C 7000D24C 24060000 */  li    $a2, 0
/* 00DE50 7000D250 0C003B6A */  jal   __ll_mul
/* 00DE54 7000D254 24070003 */   li    $a3, 3
/* 00DE58 7000D258 AFA20020 */  sw    $v0, 0x20($sp)
/* 00DE5C 7000D25C AFA30024 */  sw    $v1, 0x24($sp)
/* 00DE60 7000D260 8FA50024 */  lw    $a1, 0x24($sp)
/* 00DE64 7000D264 8FA40020 */  lw    $a0, 0x20($sp)
/* 00DE68 7000D268 24060000 */  li    $a2, 0
/* 00DE6C 7000D26C 0C003B2A */  jal   __ull_div
/* 00DE70 7000D270 24070004 */   li    $a3, 4
/* 00DE74 7000D274 3C098000 */  lui   $t1, %hi(osResetType) 
/* 00DE78 7000D278 8D29030C */  lw    $t1, %lo(osResetType)($t1)
/* 00DE7C 7000D27C 3C018002 */  lui   $at, %hi(osClockRate)
/* 00DE80 7000D280 AC226980 */  sw    $v0, %lo(osClockRate)($at)
/* 00DE84 7000D284 15200005 */  bnez  $t1, .L7000D29C
/* 00DE88 7000D288 AC236984 */   sw    $v1, %lo(osClockRate+4)($at)
/* 00DE8C 7000D28C 3C048000 */  lui   $a0, %hi(osAppNMIBuffer)
/* 00DE90 7000D290 2484031C */  addiu $a0, %lo(osAppNMIBuffer) # addiu $a0, $a0, 0x31c
/* 00DE94 7000D294 0C005F10 */  jal   _blkclr
/* 00DE98 7000D298 24050040 */   li    $a1, 64
.L7000D29C:
/* 00DE9C 7000D29C 3C0DA460 */  lui   $t5, %hi(PI_STATUS_REG) # $t5, 0xa460
/* 00DEA0 7000D2A0 8DAC0010 */  lw    $t4, %lo(PI_STATUS_REG)($t5)
/* 00DEA4 7000D2A4 318F0003 */  andi  $t7, $t4, 3
/* 00DEA8 7000D2A8 11E00008 */  beqz  $t7, .L7000D2CC
/* 00DEAC 7000D2AC AFAC0030 */   sw    $t4, 0x30($sp)
.L7000D2B0:
/* 00DEB0 7000D2B0 3C0EA460 */  lui   $t6, %hi(PI_STATUS_REG) # $t6, 0xa460
/* 00DEB4 7000D2B4 8DD80010 */  lw    $t8, %lo(PI_STATUS_REG)($t6)
/* 00DEB8 7000D2B8 AFB80030 */  sw    $t8, 0x30($sp)
/* 00DEBC 7000D2BC 8FA80030 */  lw    $t0, 0x30($sp)
/* 00DEC0 7000D2C0 31190003 */  andi  $t9, $t0, 3
/* 00DEC4 7000D2C4 1720FFFA */  bnez  $t9, .L7000D2B0
/* 00DEC8 7000D2C8 00000000 */   nop   
.L7000D2CC:
/* 00DECC 7000D2CC 3C0AA500 */  lui   $t2, %hi(ASIC_STATUS) # $t2, 0xa500
/* 00DED0 7000D2D0 8D4B0508 */  lw    $t3, %lo(ASIC_STATUS)($t2)
/* 00DED4 7000D2D4 3169FFFF */  andi  $t1, $t3, 0xffff
/* 00DED8 7000D2D8 1520000A */  bnez  $t1, .L7000D304
/* 00DEDC 7000D2DC AFAB0034 */   sw    $t3, 0x34($sp)
/* 00DEE0 7000D2E0 240D0001 */  li    $t5, 1
/* 00DEE4 7000D2E4 3C018002 */  lui   $at, %hi(osDiskExist)
/* 00DEE8 7000D2E8 3C057001 */  lui   $a1, %hi(__osLeoInterrupt) # $a1, 0x7001
/* 00DEEC 7000D2EC AC2D6990 */  sw    $t5, %lo(osDiskExist)($at)
/* 00DEF0 7000D2F0 24A57D30 */  addiu $a1, %lo(__osLeoInterrupt) # addiu $a1, $a1, 0x7d30
/* 00DEF4 7000D2F4 0C005F38 */  jal   __osSetHWIntrRoutine
/* 00DEF8 7000D2F8 24040001 */   li    $a0, 1
/* 00DEFC 7000D2FC 10000003 */  b     .L7000D30C
/* 00DF00 7000D300 00000000 */   nop   
.L7000D304:
/* 00DF04 7000D304 3C018002 */  lui   $at, %hi(osDiskExist)
/* 00DF08 7000D308 AC206990 */  sw    $zero, %lo(osDiskExist)($at)
.L7000D30C:
/* 00DF0C 7000D30C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00DF10 7000D310 8FB00018 */  lw    $s0, 0x18($sp)
/* 00DF14 7000D314 27BD0040 */  addiu $sp, $sp, 0x40
/* 00DF18 7000D318 03E00008 */  jr    $ra
/* 00DF1C 7000D31C 00000000 */   nop   





