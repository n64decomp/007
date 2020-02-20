# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax"  
glabel osViSetSpecialFeatures
/* 0103B0 7000F7B0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0103B4 7000F7B4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0103B8 7000F7B8 AFA40028 */  sw    $a0, 0x28($sp)
/* 0103BC 7000F7BC 0C00617C */  jal   __osDisableInt
/* 0103C0 7000F7C0 AFB00018 */   sw    $s0, 0x18($sp)
/* 0103C4 7000F7C4 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0103C8 7000F7C8 00408025 */  move  $s0, $v0
/* 0103CC 7000F7CC 31CF0001 */  andi  $t7, $t6, 1
/* 0103D0 7000F7D0 11E00006 */  beqz  $t7, .L7000F7EC
/* 0103D4 7000F7D4 00000000 */   nop   
/* 0103D8 7000F7D8 3C188003 */  lui   $t8, %hi(__osViNext) 
/* 0103DC 7000F7DC 8F188044 */  lw    $t8, %lo(__osViNext)($t8)
/* 0103E0 7000F7E0 8F19000C */  lw    $t9, 0xc($t8)
/* 0103E4 7000F7E4 37280008 */  ori   $t0, $t9, 8
/* 0103E8 7000F7E8 AF08000C */  sw    $t0, 0xc($t8)
.L7000F7EC:
/* 0103EC 7000F7EC 8FA90028 */  lw    $t1, 0x28($sp)
/* 0103F0 7000F7F0 312A0002 */  andi  $t2, $t1, 2
/* 0103F4 7000F7F4 11400007 */  beqz  $t2, .L7000F814
/* 0103F8 7000F7F8 00000000 */   nop   
/* 0103FC 7000F7FC 3C0B8003 */  lui   $t3, %hi(__osViNext) 
/* 010400 7000F800 8D6B8044 */  lw    $t3, %lo(__osViNext)($t3)
/* 010404 7000F804 2401FFF7 */  li    $at, -9
/* 010408 7000F808 8D6C000C */  lw    $t4, 0xc($t3)
/* 01040C 7000F80C 01816824 */  and   $t5, $t4, $at
/* 010410 7000F810 AD6D000C */  sw    $t5, 0xc($t3)
.L7000F814:
/* 010414 7000F814 8FAE0028 */  lw    $t6, 0x28($sp)
/* 010418 7000F818 31CF0004 */  andi  $t7, $t6, 4
/* 01041C 7000F81C 11E00006 */  beqz  $t7, .L7000F838
/* 010420 7000F820 00000000 */   nop   
/* 010424 7000F824 3C198003 */  lui   $t9, %hi(__osViNext) 
/* 010428 7000F828 8F398044 */  lw    $t9, %lo(__osViNext)($t9)
/* 01042C 7000F82C 8F28000C */  lw    $t0, 0xc($t9)
/* 010430 7000F830 35180004 */  ori   $t8, $t0, 4
/* 010434 7000F834 AF38000C */  sw    $t8, 0xc($t9)
.L7000F838:
/* 010438 7000F838 8FA90028 */  lw    $t1, 0x28($sp)
/* 01043C 7000F83C 312A0008 */  andi  $t2, $t1, 8
/* 010440 7000F840 11400007 */  beqz  $t2, .L7000F860
/* 010444 7000F844 00000000 */   nop   
/* 010448 7000F848 3C0C8003 */  lui   $t4, %hi(__osViNext) 
/* 01044C 7000F84C 8D8C8044 */  lw    $t4, %lo(__osViNext)($t4)
/* 010450 7000F850 2401FFFB */  li    $at, -5
/* 010454 7000F854 8D8D000C */  lw    $t5, 0xc($t4)
/* 010458 7000F858 01A15824 */  and   $t3, $t5, $at
/* 01045C 7000F85C AD8B000C */  sw    $t3, 0xc($t4)
.L7000F860:
/* 010460 7000F860 8FAE0028 */  lw    $t6, 0x28($sp)
/* 010464 7000F864 31CF0010 */  andi  $t7, $t6, 0x10
/* 010468 7000F868 11E00006 */  beqz  $t7, .L7000F884
/* 01046C 7000F86C 00000000 */   nop   
/* 010470 7000F870 3C088003 */  lui   $t0, %hi(__osViNext) 
/* 010474 7000F874 8D088044 */  lw    $t0, %lo(__osViNext)($t0)
/* 010478 7000F878 8D18000C */  lw    $t8, 0xc($t0)
/* 01047C 7000F87C 37190010 */  ori   $t9, $t8, 0x10
/* 010480 7000F880 AD19000C */  sw    $t9, 0xc($t0)
.L7000F884:
/* 010484 7000F884 8FA90028 */  lw    $t1, 0x28($sp)
/* 010488 7000F888 312A0020 */  andi  $t2, $t1, 0x20
/* 01048C 7000F88C 11400007 */  beqz  $t2, .L7000F8AC
/* 010490 7000F890 00000000 */   nop   
/* 010494 7000F894 3C0D8003 */  lui   $t5, %hi(__osViNext) 
/* 010498 7000F898 8DAD8044 */  lw    $t5, %lo(__osViNext)($t5)
/* 01049C 7000F89C 2401FFEF */  li    $at, -17
/* 0104A0 7000F8A0 8DAB000C */  lw    $t3, 0xc($t5)
/* 0104A4 7000F8A4 01616024 */  and   $t4, $t3, $at
/* 0104A8 7000F8A8 ADAC000C */  sw    $t4, 0xc($t5)
.L7000F8AC:
/* 0104AC 7000F8AC 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0104B0 7000F8B0 31CF0040 */  andi  $t7, $t6, 0x40
/* 0104B4 7000F8B4 11E0000D */  beqz  $t7, .L7000F8EC
/* 0104B8 7000F8B8 00000000 */   nop   
/* 0104BC 7000F8BC 3C188003 */  lui   $t8, %hi(__osViNext) 
/* 0104C0 7000F8C0 8F188044 */  lw    $t8, %lo(__osViNext)($t8)
/* 0104C4 7000F8C4 3C010001 */  lui   $at, 1
/* 0104C8 7000F8C8 3C098003 */  lui   $t1, %hi(__osViNext) 
/* 0104CC 7000F8CC 8F19000C */  lw    $t9, 0xc($t8)
/* 0104D0 7000F8D0 03214025 */  or    $t0, $t9, $at
/* 0104D4 7000F8D4 AF08000C */  sw    $t0, 0xc($t8)
/* 0104D8 7000F8D8 8D298044 */  lw    $t1, %lo(__osViNext)($t1)
/* 0104DC 7000F8DC 2401FCFF */  li    $at, -769
/* 0104E0 7000F8E0 8D2A000C */  lw    $t2, 0xc($t1)
/* 0104E4 7000F8E4 01415824 */  and   $t3, $t2, $at
/* 0104E8 7000F8E8 AD2B000C */  sw    $t3, 0xc($t1)
.L7000F8EC:
/* 0104EC 7000F8EC 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0104F0 7000F8F0 318D0080 */  andi  $t5, $t4, 0x80
/* 0104F4 7000F8F4 11A00010 */  beqz  $t5, .L7000F938
/* 0104F8 7000F8F8 00000000 */   nop   
/* 0104FC 7000F8FC 3C0E8003 */  lui   $t6, %hi(__osViNext) 
/* 010500 7000F900 8DCE8044 */  lw    $t6, %lo(__osViNext)($t6)
/* 010504 7000F904 3C01FFFE */  lui   $at, (0xFFFEFFFF >> 16) # lui $at, 0xfffe
/* 010508 7000F908 3421FFFF */  ori   $at, (0xFFFEFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 01050C 7000F90C 8DCF000C */  lw    $t7, 0xc($t6)
/* 010510 7000F910 3C088003 */  lui   $t0, %hi(__osViNext) 
/* 010514 7000F914 01E1C824 */  and   $t9, $t7, $at
/* 010518 7000F918 ADD9000C */  sw    $t9, 0xc($t6)
/* 01051C 7000F91C 8D088044 */  lw    $t0, %lo(__osViNext)($t0)
/* 010520 7000F920 8D0A0008 */  lw    $t2, 8($t0)
/* 010524 7000F924 8D18000C */  lw    $t8, 0xc($t0)
/* 010528 7000F928 8D4B0004 */  lw    $t3, 4($t2)
/* 01052C 7000F92C 31690300 */  andi  $t1, $t3, 0x300
/* 010530 7000F930 03096025 */  or    $t4, $t8, $t1
/* 010534 7000F934 AD0C000C */  sw    $t4, 0xc($t0)
.L7000F938:
/* 010538 7000F938 3C0D8003 */  lui   $t5, %hi(__osViNext) 
/* 01053C 7000F93C 8DAD8044 */  lw    $t5, %lo(__osViNext)($t5)
/* 010540 7000F940 02002025 */  move  $a0, $s0
/* 010544 7000F944 95AF0000 */  lhu   $t7, ($t5)
/* 010548 7000F948 35F90008 */  ori   $t9, $t7, 8
/* 01054C 7000F94C 0C006184 */  jal   __osRestoreInt
/* 010550 7000F950 A5B90000 */   sh    $t9, ($t5)
/* 010554 7000F954 8FBF001C */  lw    $ra, 0x1c($sp)
/* 010558 7000F958 8FB00018 */  lw    $s0, 0x18($sp)
/* 01055C 7000F95C 27BD0028 */  addiu $sp, $sp, 0x28
/* 010560 7000F960 03E00008 */  jr    $ra
/* 010564 7000F964 00000000 */   nop   
