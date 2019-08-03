# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"
.include "macros.inc"

# zoinkity note: 
#	 1000	80000400	memset (blanks) 8005D2E0 - 8008E360, sets SP->803AB410, JR to 80000450
#		technically, this is used in bootcode and used prior to TLB registration

glabel _start
/* 001000 80000400 3C088006 */  lui   $t0, %hi(_csegmentSegmentEnd) # $t0, 0x8006
/* 001004 80000404 3C090003 */  lui   $t1, (0x00031080 >> 16) # lui $t1, 3
/* 001008 80000408 2508D2E0 */  addiu $t0, %lo(_csegmentSegmentEnd) # addiu $t0, $t0, -0x2d20
/* 00100C 8000040C 35291080 */  ori   $t1, (0x00031080 & 0xFFFF) # ori $t1, $t1, 0x1080
.L80000410:
/* 001010 80000410 2129FFF8 */  addi  $t1, $t1, -8
/* 001014 80000414 AD000000 */  sw    $zero, ($t0)
/* 001018 80000418 AD000004 */  sw    $zero, 4($t0)
/* 00101C 8000041C 1520FFFC */  bnez  $t1, .L80000410
/* 001020 80000420 21080008 */   addi  $t0, $t0, 8
/* 001024 80000424 3C0A8000 */  lui   $t2, %hi(_boot_function) # $t2, 0x8000
/* 001028 80000428 3C1D803B */  lui   $sp, %hi(sp_rmon) # $sp, 0x803b
/* 00102C 8000042C 254A0450 */  addiu $t2, %lo(_boot_function) # addiu $t2, $t2, 0x450
/* 001030 80000430 01400008 */  jr    $t2
/* 001034 80000434 27BDB410 */   addiu $sp, %lo(sp_rmon) # addiu $sp, $sp, -0x4bf0
/* 001038 80000438 00000000 */  nop   
/* 00103C 8000043C 00000000 */  nop   
/* 001040 80000440 00000000 */  nop   
/* 001044 80000444 00000000 */  nop   
/* 001048 80000448 00000000 */  nop   
/* 00104C 8000044C 00000000 */  nop 

#hack to get us to first function of file boot0 using vaddr of 0x80000450
 _boot_function:

.section .data
.section .rodata
.section .bss
