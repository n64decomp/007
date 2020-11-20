# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

/* 00FBC0 7000EFC0 03E00008 */  jr    $ra
/* 00FBC4 7000EFC4 00000000 */   nop   

glabel _timeToSamples
/* 00FBC8 7000EFC8 8C8E0044 */  lw    $t6, 0x44($a0)
/* 00FBCC 7000EFCC 44852000 */  mtc1  $a1, $f4
/* 00FBD0 7000EFD0 3C018003 */  lui   $at, %hi(F64_80029420)
/* 00FBD4 7000EFD4 448E4000 */  mtc1  $t6, $f8
/* 00FBD8 7000EFD8 468021A0 */  cvt.s.w $f6, $f4
/* 00FBDC 7000EFDC D4249420 */  ldc1  $f4, %lo(F64_80029420)($at)
/* 00FBE0 7000EFE0 3C013FE0 */  li    $at, 0x3FE00000 # 1.750000
/* 00FBE4 7000EFE4 44813800 */  mtc1  $at, $f7
/* 00FBE8 7000EFE8 2401FFF0 */  li    $at, -16
/* 00FBEC 7000EFEC 468042A0 */  cvt.s.w $f10, $f8
/* 00FBF0 7000EFF0 460A3402 */  mul.s $f16, $f6, $f10
/* 00FBF4 7000EFF4 44803000 */  mtc1  $zero, $f6
/* 00FBF8 7000EFF8 460084A1 */  cvt.d.s $f18, $f16
/* 00FBFC 7000EFFC 46249203 */  div.d $f8, $f18, $f4
/* 00FC00 7000F000 46264280 */  add.d $f10, $f8, $f6
/* 00FC04 7000F004 46205020 */  cvt.s.d $f0, $f10
/* 00FC08 7000F008 4600040D */  trunc.w.s $f16, $f0
/* 00FC0C 7000F00C 44028000 */  mfc1  $v0, $f16
/* 00FC10 7000F010 00000000 */  nop   
/* 00FC14 7000F014 0041C024 */  and   $t8, $v0, $at
/* 00FC18 7000F018 03E00008 */  jr    $ra
/* 00FC1C 7000F01C 03001025 */   move  $v0, $t8

glabel _freePVoice
/* 00FC20 7000F020 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00FC24 7000F024 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00FC28 7000F028 AFA40018 */  sw    $a0, 0x18($sp)
/* 00FC2C 7000F02C AFA5001C */  sw    $a1, 0x1c($sp)
/* 00FC30 7000F030 0C003AA4 */  jal   alUnlink
/* 00FC34 7000F034 00A02025 */   move  $a0, $a1
/* 00FC38 7000F038 8FA50018 */  lw    $a1, 0x18($sp)
/* 00FC3C 7000F03C 8FA4001C */  lw    $a0, 0x1c($sp)
/* 00FC40 7000F040 0C003AB0 */  jal   alLink
/* 00FC44 7000F044 24A50014 */   addiu $a1, $a1, 0x14
/* 00FC48 7000F048 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00FC4C 7000F04C 27BD0018 */  addiu $sp, $sp, 0x18
/* 00FC50 7000F050 03E00008 */  jr    $ra
/* 00FC54 7000F054 00000000 */   nop   

glabel _collectPVoices
/* 00FC58 7000F058 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00FC5C 7000F05C AFBF0024 */  sw    $ra, 0x24($sp)
/* 00FC60 7000F060 AFB20020 */  sw    $s2, 0x20($sp)
/* 00FC64 7000F064 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00FC68 7000F068 AFB00018 */  sw    $s0, 0x18($sp)
/* 00FC6C 7000F06C 8C900014 */  lw    $s0, 0x14($a0)
/* 00FC70 7000F070 00808825 */  move  $s1, $a0
/* 00FC74 7000F074 24920004 */  addiu $s2, $a0, 4
/* 00FC78 7000F078 5200000A */  beql  $s0, $zero, .L7000F0A4
/* 00FC7C 7000F07C 8FBF0024 */   lw    $ra, 0x24($sp)
.L7000F080:
/* 00FC80 7000F080 0C003AA4 */  jal   alUnlink
/* 00FC84 7000F084 02002025 */   move  $a0, $s0
/* 00FC88 7000F088 02002025 */  move  $a0, $s0
/* 00FC8C 7000F08C 0C003AB0 */  jal   alLink
/* 00FC90 7000F090 02402825 */   move  $a1, $s2
/* 00FC94 7000F094 8E300014 */  lw    $s0, 0x14($s1)
/* 00FC98 7000F098 1600FFF9 */  bnez  $s0, .L7000F080
/* 00FC9C 7000F09C 00000000 */   nop   
/* 00FCA0 7000F0A0 8FBF0024 */  lw    $ra, 0x24($sp)
.L7000F0A4:
/* 00FCA4 7000F0A4 8FB00018 */  lw    $s0, 0x18($sp)
/* 00FCA8 7000F0A8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00FCAC 7000F0AC 8FB20020 */  lw    $s2, 0x20($sp)
/* 00FCB0 7000F0B0 03E00008 */  jr    $ra
/* 00FCB4 7000F0B4 27BD0028 */   addiu $sp, $sp, 0x28

glabel __freeParam
/* 00FCB8 7000F0B8 3C028002 */  lui   $v0, %hi(alGlobals)
/* 00FCBC 7000F0BC 8C4276E0 */  lw    $v0, %lo(alGlobals)($v0)
/* 00FCC0 7000F0C0 8C4E002C */  lw    $t6, 0x2c($v0)
/* 00FCC4 7000F0C4 AC8E0000 */  sw    $t6, ($a0)
/* 00FCC8 7000F0C8 03E00008 */  jr    $ra
/* 00FCCC 7000F0CC AC44002C */   sw    $a0, 0x2c($v0)

glabel __allocParam
/* 00FCD0 7000F0D0 3C028002 */  lui   $v0, %hi(alGlobals)
/* 00FCD4 7000F0D4 8C4276E0 */  lw    $v0, %lo(alGlobals)($v0)
/* 00FCD8 7000F0D8 00001825 */  move  $v1, $zero
/* 00FCDC 7000F0DC 8C44002C */  lw    $a0, 0x2c($v0)
/* 00FCE0 7000F0E0 10800005 */  beqz  $a0, .L7000F0F8
/* 00FCE4 7000F0E4 00000000 */   nop   
/* 00FCE8 7000F0E8 8C8E0000 */  lw    $t6, ($a0)
/* 00FCEC 7000F0EC 00801825 */  move  $v1, $a0
/* 00FCF0 7000F0F0 AC4E002C */  sw    $t6, 0x2c($v0)
/* 00FCF4 7000F0F4 AC800000 */  sw    $zero, ($a0)
.L7000F0F8:
/* 00FCF8 7000F0F8 03E00008 */  jr    $ra
/* 00FCFC 7000F0FC 00601025 */   move  $v0, $v1

/* 00FD00 7000F100 03E00008 */  jr    $ra
/* 00FD04 7000F104 00000000 */   nop   

glabel alAudioFrame
/* 00FD08 7000F108 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 00FD0C 7000F10C AFB10030 */  sw    $s1, 0x30($sp)
/* 00FD10 7000F110 3C118002 */  lui   $s1, %hi(alGlobals)
/* 00FD14 7000F114 8E3176E0 */  lw    $s1, %lo(alGlobals)($s1)
/* 00FD18 7000F118 AFBF004C */  sw    $ra, 0x4c($sp)
/* 00FD1C 7000F11C AFB70048 */  sw    $s7, 0x48($sp)
/* 00FD20 7000F120 AFB60044 */  sw    $s6, 0x44($sp)
/* 00FD24 7000F124 AFB50040 */  sw    $s5, 0x40($sp)
/* 00FD28 7000F128 AFB4003C */  sw    $s4, 0x3c($sp)
/* 00FD2C 7000F12C AFB30038 */  sw    $s3, 0x38($sp)
/* 00FD30 7000F130 AFB20034 */  sw    $s2, 0x34($sp)
/* 00FD34 7000F134 AFB0002C */  sw    $s0, 0x2c($sp)
/* 00FD38 7000F138 F7B60020 */  sdc1  $f22, 0x20($sp)
/* 00FD3C 7000F13C F7B40018 */  sdc1  $f20, 0x18($sp)
/* 00FD40 7000F140 AFA400B8 */  sw    $a0, 0xb8($sp)
/* 00FD44 7000F144 AFA500BC */  sw    $a1, 0xbc($sp)
/* 00FD48 7000F148 A7A000AA */  sh    $zero, 0xaa($sp)
/* 00FD4C 7000F14C 8E2F0000 */  lw    $t7, ($s1)
/* 00FD50 7000F150 00E09825 */  move  $s3, $a3
/* 00FD54 7000F154 0080A025 */  move  $s4, $a0
/* 00FD58 7000F158 15E00004 */  bnez  $t7, .L7000F16C
/* 00FD5C 7000F15C 00C0A825 */   move  $s5, $a2
/* 00FD60 7000F160 ACA00000 */  sw    $zero, ($a1)
/* 00FD64 7000F164 10000081 */  b     .L7000F36C
/* 00FD68 7000F168 00801025 */   move  $v0, $a0
.L7000F16C:
/* 00FD6C 7000F16C AFA000B4 */  sw    $zero, 0xb4($sp)
/* 00FD70 7000F170 8E220000 */  lw    $v0, ($s1)
/* 00FD74 7000F174 3C037FFF */  lui   $v1, (0x7FFFFFFF >> 16) # lui $v1, 0x7fff
/* 00FD78 7000F178 3463FFFF */  ori   $v1, (0x7FFFFFFF & 0xFFFF) # ori $v1, $v1, 0xffff
/* 00FD7C 7000F17C 1040000E */  beqz  $v0, .L7000F1B8
/* 00FD80 7000F180 2412FFF0 */   li    $s2, -16
/* 00FD84 7000F184 8E240020 */  lw    $a0, 0x20($s1)
/* 00FD88 7000F188 8C590010 */  lw    $t9, 0x10($v0)
.L7000F18C:
/* 00FD8C 7000F18C 03244023 */  subu  $t0, $t9, $a0
/* 00FD90 7000F190 0103082A */  slt   $at, $t0, $v1
/* 00FD94 7000F194 50200006 */  beql  $at, $zero, .L7000F1B0
/* 00FD98 7000F198 8C420000 */   lw    $v0, ($v0)
/* 00FD9C 7000F19C AFA200B4 */  sw    $v0, 0xb4($sp)
/* 00FDA0 7000F1A0 8C490010 */  lw    $t1, 0x10($v0)
/* 00FDA4 7000F1A4 8E240020 */  lw    $a0, 0x20($s1)
/* 00FDA8 7000F1A8 01241823 */  subu  $v1, $t1, $a0
/* 00FDAC 7000F1AC 8C420000 */  lw    $v0, ($v0)
.L7000F1B0:
/* 00FDB0 7000F1B0 5440FFF6 */  bnezl $v0, .L7000F18C
/* 00FDB4 7000F1B4 8C590010 */   lw    $t9, 0x10($v0)
.L7000F1B8:
/* 00FDB8 7000F1B8 8FAA00B4 */  lw    $t2, 0xb4($sp)
/* 00FDBC 7000F1BC 8E240020 */  lw    $a0, 0x20($s1)
/* 00FDC0 7000F1C0 8D420010 */  lw    $v0, 0x10($t2)
/* 00FDC4 7000F1C4 00445823 */  subu  $t3, $v0, $a0
/* 00FDC8 7000F1C8 0173082A */  slt   $at, $t3, $s3
/* 00FDCC 7000F1CC 10200038 */  beqz  $at, .L7000F2B0
/* 00FDD0 7000F1D0 AE22001C */   sw    $v0, 0x1c($s1)
/* 00FDD4 7000F1D4 3C013FE0 */  li    $at, 0x3FE00000 # 1.750000
/* 00FDD8 7000F1D8 4481B800 */  mtc1  $at, $f23
/* 00FDDC 7000F1DC 3C018003 */  lui   $at, %hi(F64_80029428)
/* 00FDE0 7000F1E0 4480B000 */  mtc1  $zero, $f22
/* 00FDE4 7000F1E4 D4349428 */  ldc1  $f20, %lo(F64_80029428)($at)
.L7000F1E8:
/* 00FDE8 7000F1E8 8E2C001C */  lw    $t4, 0x1c($s1)
/* 00FDEC 7000F1EC 3C107FFF */  lui   $s0, (0x7FFFFFFF >> 16) # lui $s0, 0x7fff
/* 00FDF0 7000F1F0 3610FFFF */  ori   $s0, (0x7FFFFFFF & 0xFFFF) # ori $s0, $s0, 0xffff
/* 00FDF4 7000F1F4 01926824 */  and   $t5, $t4, $s2
/* 00FDF8 7000F1F8 AE2D001C */  sw    $t5, 0x1c($s1)
/* 00FDFC 7000F1FC 8FA400B4 */  lw    $a0, 0xb4($sp)
/* 00FE00 7000F200 8C990008 */  lw    $t9, 8($a0)
/* 00FE04 7000F204 0320F809 */  jalr  $t9
/* 00FE08 7000F208 00000000 */  nop   
/* 00FE0C 7000F20C 8E380044 */  lw    $t8, 0x44($s1)
/* 00FE10 7000F210 44822000 */  mtc1  $v0, $f4
/* 00FE14 7000F214 8FA800B4 */  lw    $t0, 0xb4($sp)
/* 00FE18 7000F218 44984000 */  mtc1  $t8, $f8
/* 00FE1C 7000F21C 468021A0 */  cvt.s.w $f6, $f4
/* 00FE20 7000F220 8D090010 */  lw    $t1, 0x10($t0)
/* 00FE24 7000F224 468042A0 */  cvt.s.w $f10, $f8
/* 00FE28 7000F228 460A3402 */  mul.s $f16, $f6, $f10
/* 00FE2C 7000F22C 460084A1 */  cvt.d.s $f18, $f16
/* 00FE30 7000F230 46349103 */  div.d $f4, $f18, $f20
/* 00FE34 7000F234 46362200 */  add.d $f8, $f4, $f22
/* 00FE38 7000F238 46204020 */  cvt.s.d $f0, $f8
/* 00FE3C 7000F23C 4600018D */  trunc.w.s $f6, $f0
/* 00FE40 7000F240 44023000 */  mfc1  $v0, $f6
/* 00FE44 7000F244 00000000 */  nop   
/* 00FE48 7000F248 01225021 */  addu  $t2, $t1, $v0
/* 00FE4C 7000F24C AD0A0010 */  sw    $t2, 0x10($t0)
/* 00FE50 7000F250 AFA000B4 */  sw    $zero, 0xb4($sp)
/* 00FE54 7000F254 8E230000 */  lw    $v1, ($s1)
/* 00FE58 7000F258 5060000F */  beql  $v1, $zero, .L7000F298
/* 00FE5C 7000F25C 8FAF00B4 */   lw    $t7, 0xb4($sp)
/* 00FE60 7000F260 8E240020 */  lw    $a0, 0x20($s1)
/* 00FE64 7000F264 8C6B0010 */  lw    $t3, 0x10($v1)
.L7000F268:
/* 00FE68 7000F268 01646023 */  subu  $t4, $t3, $a0
/* 00FE6C 7000F26C 0190082A */  slt   $at, $t4, $s0
/* 00FE70 7000F270 50200006 */  beql  $at, $zero, .L7000F28C
/* 00FE74 7000F274 8C630000 */   lw    $v1, ($v1)
/* 00FE78 7000F278 AFA300B4 */  sw    $v1, 0xb4($sp)
/* 00FE7C 7000F27C 8C6D0010 */  lw    $t5, 0x10($v1)
/* 00FE80 7000F280 8E240020 */  lw    $a0, 0x20($s1)
/* 00FE84 7000F284 01A48023 */  subu  $s0, $t5, $a0
/* 00FE88 7000F288 8C630000 */  lw    $v1, ($v1)
.L7000F28C:
/* 00FE8C 7000F28C 5460FFF6 */  bnezl $v1, .L7000F268
/* 00FE90 7000F290 8C6B0010 */   lw    $t3, 0x10($v1)
/* 00FE94 7000F294 8FAF00B4 */  lw    $t7, 0xb4($sp)
.L7000F298:
/* 00FE98 7000F298 8E240020 */  lw    $a0, 0x20($s1)
/* 00FE9C 7000F29C 8DE20010 */  lw    $v0, 0x10($t7)
/* 00FEA0 7000F2A0 0044C823 */  subu  $t9, $v0, $a0
/* 00FEA4 7000F2A4 0333082A */  slt   $at, $t9, $s3
/* 00FEA8 7000F2A8 1420FFCF */  bnez  $at, .L7000F1E8
/* 00FEAC 7000F2AC AE22001C */   sw    $v0, 0x1c($s1)
.L7000F2B0:
/* 00FEB0 7000F2B0 8E38001C */  lw    $t8, 0x1c($s1)
/* 00FEB4 7000F2B4 2412FFF0 */  li    $s2, -16
/* 00FEB8 7000F2B8 27B700AA */  addiu $s7, $sp, 0xaa
/* 00FEBC 7000F2BC 03127024 */  and   $t6, $t8, $s2
/* 00FEC0 7000F2C0 1A600022 */  blez  $s3, .L7000F34C
/* 00FEC4 7000F2C4 AE2E001C */   sw    $t6, 0x1c($s1)
/* 00FEC8 7000F2C8 3C160700 */  lui   $s6, 0x700
.L7000F2CC:
/* 00FECC 7000F2CC 8E220048 */  lw    $v0, 0x48($s1)
/* 00FED0 7000F2D0 02608025 */  move  $s0, $s3
/* 00FED4 7000F2D4 0053082A */  slt   $at, $v0, $s3
/* 00FED8 7000F2D8 10200003 */  beqz  $at, .L7000F2E8
/* 00FEDC 7000F2DC 00000000 */   nop   
/* 00FEE0 7000F2E0 10000001 */  b     .L7000F2E8
/* 00FEE4 7000F2E4 00408025 */   move  $s0, $v0
.L7000F2E8:
/* 00FEE8 7000F2E8 AE960000 */  sw    $s6, ($s4)
/* 00FEEC 7000F2EC AE800004 */  sw    $zero, 4($s4)
/* 00FEF0 7000F2F0 8E320038 */  lw    $s2, 0x38($s1)
/* 00FEF4 7000F2F4 24050006 */  li    $a1, 6
/* 00FEF8 7000F2F8 02A03025 */  move  $a2, $s5
/* 00FEFC 7000F2FC 8E590008 */  lw    $t9, 8($s2)
/* 00FF00 7000F300 02402025 */  move  $a0, $s2
/* 00FF04 7000F304 0320F809 */  jalr  $t9
/* 00FF08 7000F308 00000000 */  nop   
/* 00FF0C 7000F30C 8E270020 */  lw    $a3, 0x20($s1)
/* 00FF10 7000F310 26890008 */  addiu $t1, $s4, 8
/* 00FF14 7000F314 AFA90010 */  sw    $t1, 0x10($sp)
/* 00FF18 7000F318 8E590004 */  lw    $t9, 4($s2)
/* 00FF1C 7000F31C 02402025 */  move  $a0, $s2
/* 00FF20 7000F320 02E02825 */  move  $a1, $s7
/* 00FF24 7000F324 0320F809 */  jalr  $t9
/* 00FF28 7000F328 02003025 */  move  $a2, $s0
/* 00FF2C 7000F32C 8E2B0020 */  lw    $t3, 0x20($s1)
/* 00FF30 7000F330 02709823 */  subu  $s3, $s3, $s0
/* 00FF34 7000F334 00104080 */  sll   $t0, $s0, 2
/* 00FF38 7000F338 01706021 */  addu  $t4, $t3, $s0
/* 00FF3C 7000F33C 0040A025 */  move  $s4, $v0
/* 00FF40 7000F340 02A8A821 */  addu  $s5, $s5, $t0
/* 00FF44 7000F344 1E60FFE1 */  bgtz  $s3, .L7000F2CC
/* 00FF48 7000F348 AE2C0020 */   sw    $t4, 0x20($s1)
.L7000F34C:
/* 00FF4C 7000F34C 8FAD00B8 */  lw    $t5, 0xb8($sp)
/* 00FF50 7000F350 8FAE00BC */  lw    $t6, 0xbc($sp)
/* 00FF54 7000F354 02202025 */  move  $a0, $s1
/* 00FF58 7000F358 028D7823 */  subu  $t7, $s4, $t5
/* 00FF5C 7000F35C 000FC0C3 */  sra   $t8, $t7, 3
/* 00FF60 7000F360 0C003C16 */  jal   _collectPVoices
/* 00FF64 7000F364 ADD80000 */   sw    $t8, ($t6)
/* 00FF68 7000F368 02801025 */  move  $v0, $s4
.L7000F36C:
/* 00FF6C 7000F36C 8FBF004C */  lw    $ra, 0x4c($sp)
/* 00FF70 7000F370 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 00FF74 7000F374 D7B60020 */  ldc1  $f22, 0x20($sp)
/* 00FF78 7000F378 8FB0002C */  lw    $s0, 0x2c($sp)
/* 00FF7C 7000F37C 8FB10030 */  lw    $s1, 0x30($sp)
/* 00FF80 7000F380 8FB20034 */  lw    $s2, 0x34($sp)
/* 00FF84 7000F384 8FB30038 */  lw    $s3, 0x38($sp)
/* 00FF88 7000F388 8FB4003C */  lw    $s4, 0x3c($sp)
/* 00FF8C 7000F38C 8FB50040 */  lw    $s5, 0x40($sp)
/* 00FF90 7000F390 8FB60044 */  lw    $s6, 0x44($sp)
/* 00FF94 7000F394 8FB70048 */  lw    $s7, 0x48($sp)
/* 00FF98 7000F398 03E00008 */  jr    $ra
/* 00FF9C 7000F39C 27BD00B8 */   addiu $sp, $sp, 0xb8

glabel alSynNew
/* 00FFA0 7000F3A0 27BDFF88 */  addiu $sp, $sp, -0x78
/* 00FFA4 7000F3A4 AFBF0044 */  sw    $ra, 0x44($sp)
/* 00FFA8 7000F3A8 AFBE0040 */  sw    $fp, 0x40($sp)
/* 00FFAC 7000F3AC AFB7003C */  sw    $s7, 0x3c($sp)
/* 00FFB0 7000F3B0 AFB60038 */  sw    $s6, 0x38($sp)
/* 00FFB4 7000F3B4 AFB50034 */  sw    $s5, 0x34($sp)
/* 00FFB8 7000F3B8 AFB40030 */  sw    $s4, 0x30($sp)
/* 00FFBC 7000F3BC AFB3002C */  sw    $s3, 0x2c($sp)
/* 00FFC0 7000F3C0 AFB20028 */  sw    $s2, 0x28($sp)
/* 00FFC4 7000F3C4 AFB10024 */  sw    $s1, 0x24($sp)
/* 00FFC8 7000F3C8 AFB00020 */  sw    $s0, 0x20($sp)
/* 00FFCC 7000F3CC 8CB70014 */  lw    $s7, 0x14($a1)
/* 00FFD0 7000F3D0 AC800000 */  sw    $zero, ($a0)
/* 00FFD4 7000F3D4 8CAE0004 */  lw    $t6, 4($a1)
/* 00FFD8 7000F3D8 AC800020 */  sw    $zero, 0x20($a0)
/* 00FFDC 7000F3DC AC80001C */  sw    $zero, 0x1c($a0)
/* 00FFE0 7000F3E0 AC8E003C */  sw    $t6, 0x3c($a0)
/* 00FFE4 7000F3E4 8CAF0018 */  lw    $t7, 0x18($a1)
/* 00FFE8 7000F3E8 241800A0 */  li    $t8, 160
/* 00FFEC 7000F3EC AC980048 */  sw    $t8, 0x48($a0)
/* 00FFF0 7000F3F0 AC8F0044 */  sw    $t7, 0x44($a0)
/* 00FFF4 7000F3F4 8CB90010 */  lw    $t9, 0x10($a1)
/* 00FFF8 7000F3F8 0080B025 */  move  $s6, $a0
/* 00FFFC 7000F3FC 00A0F025 */  move  $fp, $a1
/* 010000 7000F400 2408001C */  li    $t0, 28
/* 010004 7000F404 AC990024 */  sw    $t9, 0x24($a0)
/* 010008 7000F408 AFA80010 */  sw    $t0, 0x10($sp)
/* 01000C 7000F40C 00002025 */  move  $a0, $zero
/* 010010 7000F410 00002825 */  move  $a1, $zero
/* 010014 7000F414 24070001 */  li    $a3, 1
/* 010018 7000F418 0C003AD4 */  jal   alHeapDBAlloc
/* 01001C 7000F41C 02E03025 */   move  $a2, $s7
/* 010020 7000F420 AFA2005C */  sw    $v0, 0x5c($sp)
/* 010024 7000F424 0C006448 */  jal   alSaveNew
/* 010028 7000F428 00402025 */   move  $a0, $v0
/* 01002C 7000F42C 8FA9005C */  lw    $t1, 0x5c($sp)
/* 010030 7000F430 240A004C */  li    $t2, 76
/* 010034 7000F434 00002025 */  move  $a0, $zero
/* 010038 7000F438 AEC90038 */  sw    $t1, 0x38($s6)
/* 01003C 7000F43C AFAA0010 */  sw    $t2, 0x10($sp)
/* 010040 7000F440 00002825 */  move  $a1, $zero
/* 010044 7000F444 02E03025 */  move  $a2, $s7
/* 010048 7000F448 0C003AD4 */  jal   alHeapDBAlloc
/* 01004C 7000F44C 24070001 */   li    $a3, 1
/* 010050 7000F450 240B0001 */  li    $t3, 1
/* 010054 7000F454 AEC20034 */  sw    $v0, 0x34($s6)
/* 010058 7000F458 AECB0040 */  sw    $t3, 0x40($s6)
/* 01005C 7000F45C 8FC70004 */  lw    $a3, 4($fp)
/* 010060 7000F460 240C0004 */  li    $t4, 4
/* 010064 7000F464 AFAC0010 */  sw    $t4, 0x10($sp)
/* 010068 7000F468 00002025 */  move  $a0, $zero
/* 01006C 7000F46C 00002825 */  move  $a1, $zero
/* 010070 7000F470 0C003AD4 */  jal   alHeapDBAlloc
/* 010074 7000F474 02E03025 */   move  $a2, $s7
/* 010078 7000F478 8EC40034 */  lw    $a0, 0x34($s6)
/* 01007C 7000F47C 00402825 */  move  $a1, $v0
/* 010080 7000F480 0C00646E */  jal   alAuxBusNew
/* 010084 7000F484 8FC60004 */   lw    $a2, 4($fp)
/* 010088 7000F488 240D0020 */  li    $t5, 32
/* 01008C 7000F48C AFAD0010 */  sw    $t5, 0x10($sp)
/* 010090 7000F490 00002025 */  move  $a0, $zero
/* 010094 7000F494 00002825 */  move  $a1, $zero
/* 010098 7000F498 02E03025 */  move  $a2, $s7
/* 01009C 7000F49C 0C003AD4 */  jal   alHeapDBAlloc
/* 0100A0 7000F4A0 24070001 */   li    $a3, 1
/* 0100A4 7000F4A4 AEC20030 */  sw    $v0, 0x30($s6)
/* 0100A8 7000F4A8 8FC70004 */  lw    $a3, 4($fp)
/* 0100AC 7000F4AC 240E0004 */  li    $t6, 4
/* 0100B0 7000F4B0 AFAE0010 */  sw    $t6, 0x10($sp)
/* 0100B4 7000F4B4 00002025 */  move  $a0, $zero
/* 0100B8 7000F4B8 00002825 */  move  $a1, $zero
/* 0100BC 7000F4BC 0C003AD4 */  jal   alHeapDBAlloc
/* 0100C0 7000F4C0 02E03025 */   move  $a2, $s7
/* 0100C4 7000F4C4 8EC40030 */  lw    $a0, 0x30($s6)
/* 0100C8 7000F4C8 00402825 */  move  $a1, $v0
/* 0100CC 7000F4CC 0C006459 */  jal   alMainBusNew
/* 0100D0 7000F4D0 8FC60004 */   lw    $a2, 4($fp)
/* 0100D4 7000F4D4 93CF001C */  lbu   $t7, 0x1c($fp)
/* 0100D8 7000F4D8 02C02025 */  move  $a0, $s6
/* 0100DC 7000F4DC 03C03025 */  move  $a2, $fp
/* 0100E0 7000F4E0 11E00006 */  beqz  $t7, .L7000F4FC
/* 0100E4 7000F4E4 24050002 */   li    $a1, 2
/* 0100E8 7000F4E8 00002825 */  move  $a1, $zero
/* 0100EC 7000F4EC 0C006630 */  jal   alSynAllocFX
/* 0100F0 7000F4F0 02E03825 */   move  $a3, $s7
/* 0100F4 7000F4F4 10000005 */  b     .L7000F50C
/* 0100F8 7000F4F8 AEC00004 */   sw    $zero, 4($s6)
.L7000F4FC:
/* 0100FC 7000F4FC 8EC40030 */  lw    $a0, 0x30($s6)
/* 010100 7000F500 0C006658 */  jal   alMainBusParam
/* 010104 7000F504 8EC60034 */   lw    $a2, 0x34($s6)
/* 010108 7000F508 AEC00004 */  sw    $zero, 4($s6)
.L7000F50C:
/* 01010C 7000F50C AEC00008 */  sw    $zero, 8($s6)
/* 010110 7000F510 AEC00014 */  sw    $zero, 0x14($s6)
/* 010114 7000F514 AEC00018 */  sw    $zero, 0x18($s6)
/* 010118 7000F518 AEC0000C */  sw    $zero, 0xc($s6)
/* 01011C 7000F51C AEC00010 */  sw    $zero, 0x10($s6)
/* 010120 7000F520 8FC70004 */  lw    $a3, 4($fp)
/* 010124 7000F524 241800DC */  li    $t8, 220
/* 010128 7000F528 AFB80010 */  sw    $t8, 0x10($sp)
/* 01012C 7000F52C 00002025 */  move  $a0, $zero
/* 010130 7000F530 00002825 */  move  $a1, $zero
/* 010134 7000F534 0C003AD4 */  jal   alHeapDBAlloc
/* 010138 7000F538 02E03025 */   move  $a2, $s7
/* 01013C 7000F53C 8FD90004 */  lw    $t9, 4($fp)
/* 010140 7000F540 0000A025 */  move  $s4, $zero
/* 010144 7000F544 00408025 */  move  $s0, $v0
/* 010148 7000F548 1B20002F */  blez  $t9, .L7000F608
/* 01014C 7000F54C 26C50004 */   addiu $a1, $s6, 4
/* 010150 7000F550 2451008C */  addiu $s1, $v0, 0x8c
/* 010154 7000F554 24520058 */  addiu $s2, $v0, 0x58
/* 010158 7000F558 24530010 */  addiu $s3, $v0, 0x10
/* 01015C 7000F55C AFA50048 */  sw    $a1, 0x48($sp)
.L7000F560:
/* 010160 7000F560 8FA50048 */  lw    $a1, 0x48($sp)
/* 010164 7000F564 0200A825 */  move  $s5, $s0
/* 010168 7000F568 0C003AB0 */  jal   alLink
/* 01016C 7000F56C 02002025 */   move  $a0, $s0
/* 010170 7000F570 AE000008 */  sw    $zero, 8($s0)
/* 010174 7000F574 8EC50024 */  lw    $a1, 0x24($s6)
/* 010178 7000F578 02602025 */  move  $a0, $s3
/* 01017C 7000F57C 0C0064A5 */  jal   alLoadNew
/* 010180 7000F580 02E03025 */   move  $a2, $s7
/* 010184 7000F584 02602025 */  move  $a0, $s3
/* 010188 7000F588 24050001 */  li    $a1, 1
/* 01018C 7000F58C 0C0066AC */  jal   alLoadParam
/* 010190 7000F590 00003025 */   move  $a2, $zero
/* 010194 7000F594 02402025 */  move  $a0, $s2
/* 010198 7000F598 0C006483 */  jal   alResampleNew
/* 01019C 7000F59C 02E02825 */   move  $a1, $s7
/* 0101A0 7000F5A0 02402025 */  move  $a0, $s2
/* 0101A4 7000F5A4 24050001 */  li    $a1, 1
/* 0101A8 7000F5A8 0C006980 */  jal   alResampleParam
/* 0101AC 7000F5AC 02603025 */   move  $a2, $s3
/* 0101B0 7000F5B0 02202025 */  move  $a0, $s1
/* 0101B4 7000F5B4 0C0064CF */  jal   alEnvmixerNew
/* 0101B8 7000F5B8 02E02825 */   move  $a1, $s7
/* 0101BC 7000F5BC 02202025 */  move  $a0, $s1
/* 0101C0 7000F5C0 24050001 */  li    $a1, 1
/* 0101C4 7000F5C4 0C006A85 */  jal   alEnvmixerParam
/* 0101C8 7000F5C8 02403025 */   move  $a2, $s2
/* 0101CC 7000F5CC 8EC40034 */  lw    $a0, 0x34($s6)
/* 0101D0 7000F5D0 24050002 */  li    $a1, 2
/* 0101D4 7000F5D4 0C006D38 */  jal   alAuxBusParam
/* 0101D8 7000F5D8 02203025 */   move  $a2, $s1
/* 0101DC 7000F5DC 26A8008C */  addiu $t0, $s5, 0x8c
/* 0101E0 7000F5E0 AEA8000C */  sw    $t0, 0xc($s5)
/* 0101E4 7000F5E4 8FC90004 */  lw    $t1, 4($fp)
/* 0101E8 7000F5E8 26940001 */  addiu $s4, $s4, 1
/* 0101EC 7000F5EC 261000DC */  addiu $s0, $s0, 0xdc
/* 0101F0 7000F5F0 0289082A */  slt   $at, $s4, $t1
/* 0101F4 7000F5F4 263100DC */  addiu $s1, $s1, 0xdc
/* 0101F8 7000F5F8 265200DC */  addiu $s2, $s2, 0xdc
/* 0101FC 7000F5FC 1420FFD8 */  bnez  $at, .L7000F560
/* 010200 7000F600 267300DC */   addiu $s3, $s3, 0xdc
/* 010204 7000F604 0000A025 */  move  $s4, $zero
.L7000F608:
/* 010208 7000F608 8FA4005C */  lw    $a0, 0x5c($sp)
/* 01020C 7000F60C 24050001 */  li    $a1, 1
/* 010210 7000F610 0C006D7C */  jal   alSaveParam
/* 010214 7000F614 8EC60030 */   lw    $a2, 0x30($s6)
/* 010218 7000F618 8FC70008 */  lw    $a3, 8($fp)
/* 01021C 7000F61C 240A001C */  li    $t2, 28
/* 010220 7000F620 AFAA0010 */  sw    $t2, 0x10($sp)
/* 010224 7000F624 00002025 */  move  $a0, $zero
/* 010228 7000F628 00002825 */  move  $a1, $zero
/* 01022C 7000F62C 0C003AD4 */  jal   alHeapDBAlloc
/* 010230 7000F630 02E03025 */   move  $a2, $s7
/* 010234 7000F634 AEC0002C */  sw    $zero, 0x2c($s6)
/* 010238 7000F638 8FCB0008 */  lw    $t3, 8($fp)
/* 01023C 7000F63C 00401825 */  move  $v1, $v0
/* 010240 7000F640 5960000B */  blezl $t3, .L7000F670
/* 010244 7000F644 AED70028 */   sw    $s7, 0x28($s6)
/* 010248 7000F648 8ECC002C */  lw    $t4, 0x2c($s6)
.L7000F64C:
/* 01024C 7000F64C 26940001 */  addiu $s4, $s4, 1
/* 010250 7000F650 AC6C0000 */  sw    $t4, ($v1)
/* 010254 7000F654 AEC3002C */  sw    $v1, 0x2c($s6)
/* 010258 7000F658 8FCD0008 */  lw    $t5, 8($fp)
/* 01025C 7000F65C 2463001C */  addiu $v1, $v1, 0x1c
/* 010260 7000F660 028D082A */  slt   $at, $s4, $t5
/* 010264 7000F664 5420FFF9 */  bnezl $at, .L7000F64C
/* 010268 7000F668 8ECC002C */   lw    $t4, 0x2c($s6)
/* 01026C 7000F66C AED70028 */  sw    $s7, 0x28($s6)
.L7000F670:
/* 010270 7000F670 8FBF0044 */  lw    $ra, 0x44($sp)
/* 010274 7000F674 8FBE0040 */  lw    $fp, 0x40($sp)
/* 010278 7000F678 8FB7003C */  lw    $s7, 0x3c($sp)
/* 01027C 7000F67C 8FB60038 */  lw    $s6, 0x38($sp)
/* 010280 7000F680 8FB50034 */  lw    $s5, 0x34($sp)
/* 010284 7000F684 8FB40030 */  lw    $s4, 0x30($sp)
/* 010288 7000F688 8FB3002C */  lw    $s3, 0x2c($sp)
/* 01028C 7000F68C 8FB20028 */  lw    $s2, 0x28($sp)
/* 010290 7000F690 8FB10024 */  lw    $s1, 0x24($sp)
/* 010294 7000F694 8FB00020 */  lw    $s0, 0x20($sp)
/* 010298 7000F698 03E00008 */  jr    $ra
/* 01029C 7000F69C 27BD0078 */   addiu $sp, $sp, 0x78

.section .rodata
glabel F64_80029420
.double 1000000.0
glabel F64_80029428
.double 1000000.0
