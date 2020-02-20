# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 
glabel alEvtqFlushType
/* 0139E0 70012DE0 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0139E4 70012DE4 AFB30020 */  sw    $s3, 0x20($sp)
/* 0139E8 70012DE8 00059C00 */  sll   $s3, $a1, 0x10
/* 0139EC 70012DEC AFB2001C */  sw    $s2, 0x1c($sp)
/* 0139F0 70012DF0 00809025 */  move  $s2, $a0
/* 0139F4 70012DF4 00137403 */  sra   $t6, $s3, 0x10
/* 0139F8 70012DF8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0139FC 70012DFC 01C09825 */  move  $s3, $t6
/* 013A00 70012E00 AFB10018 */  sw    $s1, 0x18($sp)
/* 013A04 70012E04 AFB00014 */  sw    $s0, 0x14($sp)
/* 013A08 70012E08 AFA50044 */  sw    $a1, 0x44($sp)
/* 013A0C 70012E0C 0C00374C */  jal   osSetIntMask
/* 013A10 70012E10 24040001 */   li    $a0, 1
/* 013A14 70012E14 AFA2002C */  sw    $v0, 0x2c($sp)
/* 013A18 70012E18 8E500008 */  lw    $s0, 8($s2)
/* 013A1C 70012E1C 12000012 */  beqz  $s0, .L70012E68
/* 013A20 70012E20 00000000 */   nop   
.L70012E24:
/* 013A24 70012E24 860F000C */  lh    $t7, 0xc($s0)
/* 013A28 70012E28 8E110000 */  lw    $s1, ($s0)
/* 013A2C 70012E2C 166F000C */  bne   $s3, $t7, .L70012E60
/* 013A30 70012E30 00000000 */   nop   
/* 013A34 70012E34 12200005 */  beqz  $s1, .L70012E4C
/* 013A38 70012E38 00000000 */   nop   
/* 013A3C 70012E3C 8E380008 */  lw    $t8, 8($s1)
/* 013A40 70012E40 8E190008 */  lw    $t9, 8($s0)
/* 013A44 70012E44 03194021 */  addu  $t0, $t8, $t9
/* 013A48 70012E48 AE280008 */  sw    $t0, 8($s1)
.L70012E4C:
/* 013A4C 70012E4C 0C003AA4 */  jal   alUnlink
/* 013A50 70012E50 02002025 */   move  $a0, $s0
/* 013A54 70012E54 02002025 */  move  $a0, $s0
/* 013A58 70012E58 0C003AB0 */  jal   alLink
/* 013A5C 70012E5C 02402825 */   move  $a1, $s2
.L70012E60:
/* 013A60 70012E60 1620FFF0 */  bnez  $s1, .L70012E24
/* 013A64 70012E64 02208025 */   move  $s0, $s1
.L70012E68:
/* 013A68 70012E68 0C00374C */  jal   osSetIntMask
/* 013A6C 70012E6C 8FA4002C */   lw    $a0, 0x2c($sp)
/* 013A70 70012E70 8FBF0024 */  lw    $ra, 0x24($sp)
/* 013A74 70012E74 8FB00014 */  lw    $s0, 0x14($sp)
/* 013A78 70012E78 8FB10018 */  lw    $s1, 0x18($sp)
/* 013A7C 70012E7C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 013A80 70012E80 8FB30020 */  lw    $s3, 0x20($sp)
/* 013A84 70012E84 03E00008 */  jr    $ra
/* 013A88 70012E88 27BD0040 */   addiu $sp, $sp, 0x40

glabel alEvtqFlush
/* 013A8C 70012E8C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 013A90 70012E90 AFB20020 */  sw    $s2, 0x20($sp)
/* 013A94 70012E94 00809025 */  move  $s2, $a0
/* 013A98 70012E98 AFBF0024 */  sw    $ra, 0x24($sp)
/* 013A9C 70012E9C AFB1001C */  sw    $s1, 0x1c($sp)
/* 013AA0 70012EA0 AFB00018 */  sw    $s0, 0x18($sp)
/* 013AA4 70012EA4 0C00374C */  jal   osSetIntMask
/* 013AA8 70012EA8 24040001 */   li    $a0, 1
/* 013AAC 70012EAC AFA2002C */  sw    $v0, 0x2c($sp)
/* 013AB0 70012EB0 8E500008 */  lw    $s0, 8($s2)
/* 013AB4 70012EB4 12000009 */  beqz  $s0, .L70012EDC
/* 013AB8 70012EB8 00000000 */   nop   
.L70012EBC:
/* 013ABC 70012EBC 8E110000 */  lw    $s1, ($s0)
/* 013AC0 70012EC0 0C003AA4 */  jal   alUnlink
/* 013AC4 70012EC4 02002025 */   move  $a0, $s0
/* 013AC8 70012EC8 02002025 */  move  $a0, $s0
/* 013ACC 70012ECC 0C003AB0 */  jal   alLink
/* 013AD0 70012ED0 02402825 */   move  $a1, $s2
/* 013AD4 70012ED4 1620FFF9 */  bnez  $s1, .L70012EBC
/* 013AD8 70012ED8 02208025 */   move  $s0, $s1
.L70012EDC:
/* 013ADC 70012EDC 0C00374C */  jal   osSetIntMask
/* 013AE0 70012EE0 8FA4002C */   lw    $a0, 0x2c($sp)
/* 013AE4 70012EE4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 013AE8 70012EE8 8FB00018 */  lw    $s0, 0x18($sp)
/* 013AEC 70012EEC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 013AF0 70012EF0 8FB20020 */  lw    $s2, 0x20($sp)
/* 013AF4 70012EF4 03E00008 */  jr    $ra
/* 013AF8 70012EF8 27BD0038 */   addiu $sp, $sp, 0x38

glabel alEvtqPostEvent
/* 013AFC 70012EFC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 013B00 70012F00 AFBF0014 */  sw    $ra, 0x14($sp)
/* 013B04 70012F04 AFA40030 */  sw    $a0, 0x30($sp)
/* 013B08 70012F08 AFA50034 */  sw    $a1, 0x34($sp)
/* 013B0C 70012F0C AFA00020 */  sw    $zero, 0x20($sp)
/* 013B10 70012F10 24040001 */  li    $a0, 1
/* 013B14 70012F14 0C00374C */  jal   osSetIntMask
/* 013B18 70012F18 AFA60038 */   sw    $a2, 0x38($sp)
/* 013B1C 70012F1C 8FAE0030 */  lw    $t6, 0x30($sp)
/* 013B20 70012F20 8FA70038 */  lw    $a3, 0x38($sp)
/* 013B24 70012F24 00402825 */  move  $a1, $v0
/* 013B28 70012F28 8DC80000 */  lw    $t0, ($t6)
/* 013B2C 70012F2C 15000005 */  bnez  $t0, .L70012F44
/* 013B30 70012F30 01002025 */   move  $a0, $t0
/* 013B34 70012F34 0C00374C */  jal   osSetIntMask
/* 013B38 70012F38 00402025 */   move  $a0, $v0
/* 013B3C 70012F3C 10000035 */  b     .L70013014
/* 013B40 70012F40 8FBF0014 */   lw    $ra, 0x14($sp)
.L70012F44:
/* 013B44 70012F44 AFA5001C */  sw    $a1, 0x1c($sp)
/* 013B48 70012F48 AFA70038 */  sw    $a3, 0x38($sp)
/* 013B4C 70012F4C 0C003AA4 */  jal   alUnlink
/* 013B50 70012F50 AFA8002C */   sw    $t0, 0x2c($sp)
/* 013B54 70012F54 8FA8002C */  lw    $t0, 0x2c($sp)
/* 013B58 70012F58 8FA40034 */  lw    $a0, 0x34($sp)
/* 013B5C 70012F5C 24060010 */  li    $a2, 16
/* 013B60 70012F60 0C0075A4 */  jal   alCopy
/* 013B64 70012F64 2505000C */   addiu $a1, $t0, 0xc
/* 013B68 70012F68 8FA70038 */  lw    $a3, 0x38($sp)
/* 013B6C 70012F6C 3C017FFF */  lui   $at, (0x7FFFFFFF >> 16) # lui $at, 0x7fff
/* 013B70 70012F70 3421FFFF */  ori   $at, (0x7FFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 013B74 70012F74 14E10003 */  bne   $a3, $at, .L70012F84
/* 013B78 70012F78 8FA8002C */   lw    $t0, 0x2c($sp)
/* 013B7C 70012F7C 240FFFFF */  li    $t7, -1
/* 013B80 70012F80 AFAF0020 */  sw    $t7, 0x20($sp)
.L70012F84:
/* 013B84 70012F84 8FA20030 */  lw    $v0, 0x30($sp)
/* 013B88 70012F88 2401FFF8 */  li    $at, -8
/* 013B8C 70012F8C 8FB80020 */  lw    $t8, 0x20($sp)
/* 013B90 70012F90 1041001D */  beq   $v0, $at, .L70013008
/* 013B94 70012F94 24450008 */   addiu $a1, $v0, 8
.L70012F98:
/* 013B98 70012F98 8CA20000 */  lw    $v0, ($a1)
/* 013B9C 70012F9C 5440000B */  bnezl $v0, .L70012FCC
/* 013BA0 70012FA0 8C430008 */   lw    $v1, 8($v0)
/* 013BA4 70012FA4 53000004 */  beql  $t8, $zero, .L70012FB8
/* 013BA8 70012FA8 AD070008 */   sw    $a3, 8($t0)
/* 013BAC 70012FAC 10000002 */  b     .L70012FB8
/* 013BB0 70012FB0 AD000008 */   sw    $zero, 8($t0)
/* 013BB4 70012FB4 AD070008 */  sw    $a3, 8($t0)
.L70012FB8:
/* 013BB8 70012FB8 0C003AB0 */  jal   alLink
/* 013BBC 70012FBC 01002025 */   move  $a0, $t0
/* 013BC0 70012FC0 10000011 */  b     .L70013008
/* 013BC4 70012FC4 00000000 */   nop   
/* 013BC8 70012FC8 8C430008 */  lw    $v1, 8($v0)
.L70012FCC:
/* 013BCC 70012FCC 00403025 */  move  $a2, $v0
/* 013BD0 70012FD0 00E3082A */  slt   $at, $a3, $v1
/* 013BD4 70012FD4 5020000A */  beql  $at, $zero, .L70013000
/* 013BD8 70012FD8 00402825 */   move  $a1, $v0
/* 013BDC 70012FDC AD070008 */  sw    $a3, 8($t0)
/* 013BE0 70012FE0 8CD90008 */  lw    $t9, 8($a2)
/* 013BE4 70012FE4 01002025 */  move  $a0, $t0
/* 013BE8 70012FE8 03274823 */  subu  $t1, $t9, $a3
/* 013BEC 70012FEC 0C003AB0 */  jal   alLink
/* 013BF0 70012FF0 ACC90008 */   sw    $t1, 8($a2)
/* 013BF4 70012FF4 10000004 */  b     .L70013008
/* 013BF8 70012FF8 00000000 */   nop   
/* 013BFC 70012FFC 00402825 */  move  $a1, $v0
.L70013000:
/* 013C00 70013000 1440FFE5 */  bnez  $v0, .L70012F98
/* 013C04 70013004 00E33823 */   subu  $a3, $a3, $v1
.L70013008:
/* 013C08 70013008 0C00374C */  jal   osSetIntMask
/* 013C0C 7001300C 8FA4001C */   lw    $a0, 0x1c($sp)
/* 013C10 70013010 8FBF0014 */  lw    $ra, 0x14($sp)
.L70013014:
/* 013C14 70013014 27BD0030 */  addiu $sp, $sp, 0x30
/* 013C18 70013018 03E00008 */  jr    $ra
/* 013C1C 7001301C 00000000 */   nop   

glabel alEvtqNextEvent
/* 013C20 70013020 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 013C24 70013024 AFBF001C */  sw    $ra, 0x1c($sp)
/* 013C28 70013028 AFA40030 */  sw    $a0, 0x30($sp)
/* 013C2C 7001302C AFB00018 */  sw    $s0, 0x18($sp)
/* 013C30 70013030 AFA50034 */  sw    $a1, 0x34($sp)
/* 013C34 70013034 0C00374C */  jal   osSetIntMask
/* 013C38 70013038 24040001 */   li    $a0, 1
/* 013C3C 7001303C 8FAE0030 */  lw    $t6, 0x30($sp)
/* 013C40 70013040 AFA20024 */  sw    $v0, 0x24($sp)
/* 013C44 70013044 8FB80034 */  lw    $t8, 0x34($sp)
/* 013C48 70013048 8DD00008 */  lw    $s0, 8($t6)
/* 013C4C 7001304C 00001825 */  move  $v1, $zero
/* 013C50 70013050 5200000D */  beql  $s0, $zero, .L70013088
/* 013C54 70013054 240FFFFF */   li    $t7, -1
/* 013C58 70013058 0C003AA4 */  jal   alUnlink
/* 013C5C 7001305C 02002025 */   move  $a0, $s0
/* 013C60 70013060 2604000C */  addiu $a0, $s0, 0xc
/* 013C64 70013064 8FA50034 */  lw    $a1, 0x34($sp)
/* 013C68 70013068 0C0075A4 */  jal   alCopy
/* 013C6C 7001306C 24060010 */   li    $a2, 16
/* 013C70 70013070 02002025 */  move  $a0, $s0
/* 013C74 70013074 0C003AB0 */  jal   alLink
/* 013C78 70013078 8FA50030 */   lw    $a1, 0x30($sp)
/* 013C7C 7001307C 10000003 */  b     .L7001308C
/* 013C80 70013080 8E030008 */   lw    $v1, 8($s0)
/* 013C84 70013084 240FFFFF */  li    $t7, -1
.L70013088:
/* 013C88 70013088 A70F0000 */  sh    $t7, ($t8)
.L7001308C:
/* 013C8C 7001308C 8FA40024 */  lw    $a0, 0x24($sp)
/* 013C90 70013090 0C00374C */  jal   osSetIntMask
/* 013C94 70013094 AFA30028 */   sw    $v1, 0x28($sp)
/* 013C98 70013098 8FBF001C */  lw    $ra, 0x1c($sp)
/* 013C9C 7001309C 8FA20028 */  lw    $v0, 0x28($sp)
/* 013CA0 700130A0 8FB00018 */  lw    $s0, 0x18($sp)
/* 013CA4 700130A4 03E00008 */  jr    $ra
/* 013CA8 700130A8 27BD0030 */   addiu $sp, $sp, 0x30

glabel alEvtqNew
/* 013CAC 700130AC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 013CB0 700130B0 AFB30020 */  sw    $s3, 0x20($sp)
/* 013CB4 700130B4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 013CB8 700130B8 AFB00014 */  sw    $s0, 0x14($sp)
/* 013CBC 700130BC AFBF0024 */  sw    $ra, 0x24($sp)
/* 013CC0 700130C0 AFB10018 */  sw    $s1, 0x18($sp)
/* 013CC4 700130C4 00809025 */  move  $s2, $a0
/* 013CC8 700130C8 00C09825 */  move  $s3, $a2
/* 013CCC 700130CC AC800010 */  sw    $zero, 0x10($a0)
/* 013CD0 700130D0 AC800008 */  sw    $zero, 8($a0)
/* 013CD4 700130D4 AC80000C */  sw    $zero, 0xc($a0)
/* 013CD8 700130D8 AC800000 */  sw    $zero, ($a0)
/* 013CDC 700130DC AC800004 */  sw    $zero, 4($a0)
/* 013CE0 700130E0 18C00008 */  blez  $a2, .L70013104
/* 013CE4 700130E4 00008025 */   move  $s0, $zero
/* 013CE8 700130E8 00A08825 */  move  $s1, $a1
.L700130EC:
/* 013CEC 700130EC 02202025 */  move  $a0, $s1
/* 013CF0 700130F0 0C003AB0 */  jal   alLink
/* 013CF4 700130F4 02402825 */   move  $a1, $s2
/* 013CF8 700130F8 26100001 */  addiu $s0, $s0, 1
/* 013CFC 700130FC 1613FFFB */  bne   $s0, $s3, .L700130EC
/* 013D00 70013100 2631001C */   addiu $s1, $s1, 0x1c
.L70013104:
/* 013D04 70013104 8FBF0024 */  lw    $ra, 0x24($sp)
/* 013D08 70013108 8FB00014 */  lw    $s0, 0x14($sp)
/* 013D0C 7001310C 8FB10018 */  lw    $s1, 0x18($sp)
/* 013D10 70013110 8FB2001C */  lw    $s2, 0x1c($sp)
/* 013D14 70013114 8FB30020 */  lw    $s3, 0x20($sp)
/* 013D18 70013118 03E00008 */  jr    $ra
/* 013D1C 7001311C 27BD0028 */   addiu $sp, $sp, 0x28
