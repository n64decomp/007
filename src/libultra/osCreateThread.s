# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"


.section .text, "ax" 

glabel osCreateThread
/* 00E030 7000D430 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00E034 7000D434 AFA40028 */  sw    $a0, 0x28($sp)
/* 00E038 7000D438 AFA5002C */  sw    $a1, 0x2c($sp)
/* 00E03C 7000D43C 8FAE002C */  lw    $t6, 0x2c($sp)
/* 00E040 7000D440 8FAF0028 */  lw    $t7, 0x28($sp)
/* 00E044 7000D444 AFBF001C */  sw    $ra, 0x1c($sp)
/* 00E048 7000D448 AFA60030 */  sw    $a2, 0x30($sp)
/* 00E04C 7000D44C AFA70034 */  sw    $a3, 0x34($sp)
/* 00E050 7000D450 AFB00018 */  sw    $s0, 0x18($sp)
/* 00E054 7000D454 ADEE0014 */  sw    $t6, 0x14($t7)
/* 00E058 7000D458 8FB90028 */  lw    $t9, 0x28($sp)
/* 00E05C 7000D45C 8FB8003C */  lw    $t8, 0x3c($sp)
/* 00E060 7000D460 AF380004 */  sw    $t8, 4($t9)
/* 00E064 7000D464 8FA80028 */  lw    $t0, 0x28($sp)
/* 00E068 7000D468 AD000000 */  sw    $zero, ($t0)
/* 00E06C 7000D46C 8FA90028 */  lw    $t1, 0x28($sp)
/* 00E070 7000D470 AD200008 */  sw    $zero, 8($t1)
/* 00E074 7000D474 8FAB0028 */  lw    $t3, 0x28($sp)
/* 00E078 7000D478 8FAA0030 */  lw    $t2, 0x30($sp)
/* 00E07C 7000D47C AD6A011C */  sw    $t2, 0x11c($t3)
/* 00E080 7000D480 8FAC0034 */  lw    $t4, 0x34($sp)
/* 00E084 7000D484 8FAD0028 */  lw    $t5, 0x28($sp)
/* 00E088 7000D488 01807825 */  move  $t7, $t4
/* 00E08C 7000D48C 000C77C3 */  sra   $t6, $t4, 0x1f
/* 00E090 7000D490 ADAE0038 */  sw    $t6, 0x38($t5)
/* 00E094 7000D494 ADAF003C */  sw    $t7, 0x3c($t5)
/* 00E098 7000D498 8FB80038 */  lw    $t8, 0x38($sp)
/* 00E09C 7000D49C 8FB90028 */  lw    $t9, 0x28($sp)
/* 00E0A0 7000D4A0 3C0C7001 */  lui   $t4, %hi(__osCleanupThread) # $t4, 0x7001
/* 00E0A4 7000D4A4 03004825 */  move  $t1, $t8
/* 00E0A8 7000D4A8 2D210010 */  sltiu $at, $t1, 0x10
/* 00E0AC 7000D4AC 001847C3 */  sra   $t0, $t8, 0x1f
/* 00E0B0 7000D4B0 01015023 */  subu  $t2, $t0, $at
/* 00E0B4 7000D4B4 252BFFF0 */  addiu $t3, $t1, -0x10
/* 00E0B8 7000D4B8 AF2B00F4 */  sw    $t3, 0xf4($t9)
/* 00E0BC 7000D4BC AF2A00F0 */  sw    $t2, 0xf0($t9)
/* 00E0C0 7000D4C0 8FAD0028 */  lw    $t5, 0x28($sp)
/* 00E0C4 7000D4C4 258C0A80 */  addiu $t4, %lo(__osCleanupThread) # addiu $t4, $t4, 0xa80
/* 00E0C8 7000D4C8 01807825 */  move  $t7, $t4
/* 00E0CC 7000D4CC 000C77C3 */  sra   $t6, $t4, 0x1f
/* 00E0D0 7000D4D0 ADAE0100 */  sw    $t6, 0x100($t5)
/* 00E0D4 7000D4D4 ADAF0104 */  sw    $t7, 0x104($t5)
/* 00E0D8 7000D4D8 8FA90028 */  lw    $t1, 0x28($sp)
/* 00E0DC 7000D4DC 3C18003F */  lui   $t8, (0x003FFF01 >> 16) # lui $t8, 0x3f
/* 00E0E0 7000D4E0 3718FF01 */  ori   $t8, (0x003FFF01 & 0xFFFF) # ori $t8, $t8, 0xff01
/* 00E0E4 7000D4E4 AFB80020 */  sw    $t8, 0x20($sp)
/* 00E0E8 7000D4E8 3408FF03 */  li    $t0, 65283
/* 00E0EC 7000D4EC AD280118 */  sw    $t0, 0x118($t1)
/* 00E0F0 7000D4F0 8FAA0020 */  lw    $t2, 0x20($sp)
/* 00E0F4 7000D4F4 8FAC0028 */  lw    $t4, 0x28($sp)
/* 00E0F8 7000D4F8 3C01003F */  lui   $at, 0x3f
/* 00E0FC 7000D4FC 01415824 */  and   $t3, $t2, $at
/* 00E100 7000D500 000BCC02 */  srl   $t9, $t3, 0x10
/* 00E104 7000D504 AD990128 */  sw    $t9, 0x128($t4)
/* 00E108 7000D508 8FAF0028 */  lw    $t7, 0x28($sp)
/* 00E10C 7000D50C 3C0E0100 */  lui   $t6, (0x01000800 >> 16) # lui $t6, 0x100
/* 00E110 7000D510 35CE0800 */  ori   $t6, (0x01000800 & 0xFFFF) # ori $t6, $t6, 0x800
/* 00E114 7000D514 ADEE012C */  sw    $t6, 0x12c($t7)
/* 00E118 7000D518 8FAD0028 */  lw    $t5, 0x28($sp)
/* 00E11C 7000D51C 24180001 */  li    $t8, 1
/* 00E120 7000D520 ADA00018 */  sw    $zero, 0x18($t5)
/* 00E124 7000D524 8FA80028 */  lw    $t0, 0x28($sp)
/* 00E128 7000D528 A5180010 */  sh    $t8, 0x10($t0)
/* 00E12C 7000D52C 8FA90028 */  lw    $t1, 0x28($sp)
/* 00E130 7000D530 0C00617C */  jal   __osDisableInt
/* 00E134 7000D534 A5200012 */   sh    $zero, 0x12($t1)
/* 00E138 7000D538 3C0A8002 */  lui   $t2, %hi(__osActiveQueue) 
/* 00E13C 7000D53C 8D4A772C */  lw    $t2, %lo(__osActiveQueue)($t2)
/* 00E140 7000D540 8FAB0028 */  lw    $t3, 0x28($sp)
/* 00E144 7000D544 00408025 */  move  $s0, $v0
/* 00E148 7000D548 3C018002 */  lui   $at, %hi(__osActiveQueue)
/* 00E14C 7000D54C AD6A000C */  sw    $t2, 0xc($t3)
/* 00E150 7000D550 8FB90028 */  lw    $t9, 0x28($sp)
/* 00E154 7000D554 02002025 */  move  $a0, $s0
/* 00E158 7000D558 0C006184 */  jal   __osRestoreInt
/* 00E15C 7000D55C AC39772C */   sw    $t9, %lo(__osActiveQueue)($at)
/* 00E160 7000D560 8FBF001C */  lw    $ra, 0x1c($sp)
/* 00E164 7000D564 8FB00018 */  lw    $s0, 0x18($sp)
/* 00E168 7000D568 27BD0028 */  addiu $sp, $sp, 0x28
/* 00E16C 7000D56C 03E00008 */  jr    $ra
/* 00E170 7000D570 00000000 */   nop   
