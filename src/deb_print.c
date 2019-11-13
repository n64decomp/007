#include "ultra64.h"
#include "deb_print.h"
#include "bondgame.h"

/**
 * @file deb_print.c
 * This file contains the stderr manager. 
 */

//im just padding
u32 D_80023300 = 0;


struct debug_processor_error_entry debug_processor_error_table[] = { 
{0x80000000, 0x80000000, "BD"},
{0x8000, 0x8000, "IP8"},
{0x4000, 0x4000, "IP7"},
{0x2000, 0x2000, "IP6"},
{0x1000, 0x1000, "IP5"},
{0x800, 0x800, "IP4"},
{0x400, 0x400, "IP3"},
{0x200, 0x200, "IP2"},
{0x100, 0x100, "IP1"},
{0x7C, 0, "Int"},
{0x7C, 4, "TLBmod"},
{0x7C, 8, "TLBload"},
{0x7C, 0xC, "TLBstore"},
{0x7C, 0x10, "Address error on load or instruction fetch"},
{0x7C, 0x14, "Address error on store"},
{0x7C, 0x18, "Bus error exception on instruction fetch"},
{0x7C, 0x1C, "Bus error exception on data reference"},
{0x7C, 0x20, "Syscall"},
{0x7C, 0x24, "Brk"},
{0x7C, 0x28, "Reserved instruction"},
{0x7C, 0x2C, "Cop unusable"},
{0x7C, 0x30, "Overflow"},
{0x7C, 0x34, "Trap"},
{0x7C, 0x38, "Virtual coherency exception on intruction fetch"},
{0x7C, 0x3C, "Fp exception"},
{0x7C, 0x5C, "Watchpoint"},
{0x7C, 0x7C, "Virtual coherency exception on data reference"},
{0, 0, ""},
{0x80000000, 0x80000000, "CU3"},
{0x40000000, 0x40000000, "CU2"},
{0x20000000, 0x20000000, "CU1"},
{0x10000000, 0x10000000, "CU0"},
{0x8000000, 0x8000000, "RP"},
{0x4000000, 0x4000000, "FR"},
{0x2000000, 0x2000000, "RE"},
{0x400000, 0x400000, "BEV"},
{0x200000, 0x200000, "TS"},
{0x100000, 0x100000, "SR"},
{0x40000, 0x40000, "CH"},
{0x20000, 0x20000, "CE"},
{0x10000, 0x10000, "DE"},
{0x8000, 0x8000, "IM8"},
{0x4000, 0x4000, "IM7"},
{0x2000, 0x2000, "IM6"},
{0x1000, 0x1000, "IM5"},
{0x800, 0x800, "IM4"},
{0x400, 0x400, "IM3"},
{0x200, 0x200, "IM2"},
{0x100, 0x100, "IM1"},
{0x80, 0x80, "KX"},
{0x40, 0x40, "SX"},
{0x20, 0x20, "UX"},
{0x18, 0x10, "USR"},
{0x18, 8, "SUP"},
{0x18, 0, "KER"},
{4, 4, "ERL"},
{2, 2, "EXL"},
{1, 1, "IE"},
{0, 0, ""},
{0x1000000, 0x1000000, "FS"},
{0x800000, 0x800000, "C"},
{0x20000, 0x20000, "Unimplemented"},
{0x10000, 0x10000, "Invalid op"},
{0x8000, 0x8000, "/ by 0.0"},
{0x4000, 0x4000, "Overflow"},
{0x2000, 0x2000, "Underflow"},
{0x1000, 0x1000, "Inexact op"},
{0x800, 0x800, "EV"},
{0x400, 0x400, "EZ"},
{0x200, 0x200, "EO"},
{0x100, 0x100, "EU"},
{0x80, 0x80, "EI"},
{0x40, 0x40, "FV"},
{0x20, 0x20, "FZ"},
{0x10, 0x10, "FO"},
{8, 8, "FU"},
{4, 4, "FI"},
{3, 0, "RN"},
{3, 1, "RZ"},
{3, 2, "RP"},
{3, 3, "RM"},
{0, 0, ""} };

void *stack_ptrs_1[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};
void *stack_ptrs_2[] = {&sp_idle, &sp_shed, &sp_main, &sp_audi, &sp_debug};
void *stack_ptrs_3[] = {&sp_rmon, &sp_idle, &sp_shed, &sp_main, &sp_audi};

char stderr_buffer[2280] = {0x0};


//split more here likely
u32 std_error_font_bitcode[] = {
0x00000000, 0x22220200, 0x55000000,  0x5F5F500, 0x27427200,
0x05124500, 0x34255300, 0x22000000, 0x24444420, 0x42222240,
0x06F6F600,   0x272000,      0x240,    0x70000,      0x200,
0x11224480, 0x25555200, 0x26222700, 0x25125700, 0x61211600,
0x33557300, 0x64611600, 0x24655200, 0x71112200, 0x25755200,
0x25531600,   0x200200,   0x200640,  0x1242100,   0x707000,
 0x4212400,  0x7120200, 0x25FF5700,  0x2557D00,  0x6575E00,
 0x7445300,  0x7555600,  0x7565700,  0x7564400,  0x7C95700,
 0x5575500,  0x7222700,  0x3111600,  0x5665500,  0x4445F00,
 0xDFF9D00,  0xF777D00,  0x7DD5700,  0x7564600,  0x7995770,
 0x7565500,  0x7461E00,  0x7222200,  0xD999600,  0xD552200,
 0xDF77500,  0xD625500,  0x5622600,  0x7125700, 0x32222230,
0x44222110, 0x62222260, 0x25000000,      0x700, 0x42200000,
  0x67D700, 0x44755700,   0x788600, 0x117DD700,   0x6FC700,
0x32722700,   0x7DD730, 0x44755500,  0x2622700,  0x2711130,
0x44766500, 0x62222700,   0xFFFF00,   0x755D00,   0x6DD600,
  0x755740,   0x799710,   0x744600,   0x775700,  0x2722300,
  0x555700,   0x552200,   0x577500,   0x562500,   0x552220,
  0x703700, 0x12242210,  0x2222220, 0x42212240,   0x5A0000 };

void *ptr_videobuffer1 = 0;
void *ptr_videobuffer2 = 0;

u32 padding_80024184[4] = 0;




/**
 * 6230	70005630
 *     write char A2 to (A0,A1) in stderr
 *     accepts: A0=xpos, A1=ypos, A2=char
 */
#ifdef NONMATCHING
void write_char_to_pos_stderr(int xpos,int ypos,u8 letter) {
  if ((letter == 9) || (letter == 10)) {
    letter = 0;
  }
  if (((letter != 0) && (letter < 0x20)) || (0x7e < letter)) {
    letter = 0x3f;
  }
  if (((-1 < xpos) && (xpos < 0x48)) && ((-1 < ypos && (ypos < 0x20)))) {
    stderr_buffer[ypos * 0x47 + xpos] = letter;
  }
  return;
}
#else
GLOBAL_ASM(
.text
glabel write_char_to_pos_stderr
/* 006230 70005630 30CE00FF */  andi  $t6, $a2, 0xff
/* 006234 70005634 AFA60008 */  sw    $a2, 8($sp)
/* 006238 70005638 24010009 */  li    $at, 9
/* 00623C 7000563C 01C03025 */  move  $a2, $t6
/* 006240 70005640 11C10004 */  beq   $t6, $at, .L70005654
/* 006244 70005644 01C01025 */   move  $v0, $t6
/* 006248 70005648 2401000A */  li    $at, 10
/* 00624C 7000564C 15C10003 */  bne   $t6, $at, .L7000565C
/* 006250 70005650 00000000 */   nop   
.L70005654:
/* 006254 70005654 00003025 */  move  $a2, $zero
/* 006258 70005658 00001025 */  move  $v0, $zero
.L7000565C:
/* 00625C 7000565C 18400002 */  blez  $v0, .L70005668
/* 006260 70005660 28410020 */   slti  $at, $v0, 0x20
/* 006264 70005664 14200003 */  bnez  $at, .L70005674
.L70005668:
/* 006268 70005668 2841007F */   slti  $at, $v0, 0x7f
/* 00626C 7000566C 14200002 */  bnez  $at, .L70005678
/* 006270 70005670 00000000 */   nop   
.L70005674:
/* 006274 70005674 2406003F */  li    $a2, 63
.L70005678:
/* 006278 70005678 0480000E */  bltz  $a0, .L700056B4
/* 00627C 7000567C 28810048 */   slti  $at, $a0, 0x48
/* 006280 70005680 1020000C */  beqz  $at, .L700056B4
/* 006284 70005684 00000000 */   nop   
/* 006288 70005688 04A0000A */  bltz  $a1, .L700056B4
/* 00628C 7000568C 28A10020 */   slti  $at, $a1, 0x20
/* 006290 70005690 10200008 */  beqz  $at, .L700056B4
/* 006294 70005694 000578C0 */   sll   $t7, $a1, 3
/* 006298 70005698 01E57821 */  addu  $t7, $t7, $a1
/* 00629C 7000569C 000F78C0 */  sll   $t7, $t7, 3
/* 0062A0 700056A0 01E57823 */  subu  $t7, $t7, $a1
/* 0062A4 700056A4 01E4C021 */  addu  $t8, $t7, $a0
/* 0062A8 700056A8 3C018002 */  lui   $at, %hi(stderr_buffer)
/* 0062AC 700056AC 00380821 */  addu  $at, $at, $t8
/* 0062B0 700056B0 A0263718 */  sb    $a2, %lo(stderr_buffer)($at)
.L700056B4:
/* 0062B4 700056B4 03E00008 */  jr    $ra
/* 0062B8 700056B8 00000000 */   nop   
)
#endif




/**
 * 62BC	700056BC
 *     write char A0 to stderr
 *     accepts: A0=char
 */
#ifdef NONMATCHING
void __osRdbSend(void) {

}
#else
GLOBAL_ASM(
.text
glabel __osRdbSend
/* 0062BC 700056BC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0062C0 700056C0 308600FF */  andi  $a2, $a0, 0xff
/* 0062C4 700056C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0062C8 700056C8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0062CC 700056CC AFA40028 */  sw    $a0, 0x28($sp)
/* 0062D0 700056D0 10C00039 */  beqz  $a2, .L700057B8
/* 0062D4 700056D4 00C01025 */   move  $v0, $a2
/* 0062D8 700056D8 24010009 */  li    $at, 9
/* 0062DC 700056DC 14C1000A */  bne   $a2, $at, .L70005708
/* 0062E0 700056E0 3C108002 */   lui   $s0, %hi(stderr_buffer + 0x8E0)
/* 0062E4 700056E4 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
.L700056E8:
/* 0062E8 700056E8 0C0015AF */  jal   __osRdbSend
/* 0062EC 700056EC 24040020 */   li    $a0, 32
/* 0062F0 700056F0 8E0E0000 */  lw    $t6, ($s0)
/* 0062F4 700056F4 31CF0007 */  andi  $t7, $t6, 7
/* 0062F8 700056F8 15E0FFFB */  bnez  $t7, .L700056E8
/* 0062FC 700056FC 00000000 */   nop   
/* 006300 70005700 1000002E */  b     .L700057BC
/* 006304 70005704 8FBF001C */   lw    $ra, 0x1c($sp)
.L70005708:
/* 006308 70005708 2401000A */  li    $at, 10
/* 00630C 7000570C 14410008 */  bne   $v0, $at, .L70005730
/* 006310 70005710 3C038002 */   lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006314 70005714 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006318 70005718 8C780000 */  lw    $t8, ($v1)
/* 00631C 7000571C 3C108002 */  lui   $s0, %hi(stderr_buffer + 0x8E0)
/* 006320 70005720 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006324 70005724 27190001 */  addiu $t9, $t8, 1
/* 006328 70005728 AC790000 */  sw    $t9, ($v1)
/* 00632C 7000572C AE000000 */  sw    $zero, ($s0)
.L70005730:
/* 006330 70005730 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006334 70005734 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006338 70005738 8C650000 */  lw    $a1, ($v1)
/* 00633C 7000573C 3C108002 */  lui   $s0, %hi(stderr_buffer + 0x8E0)
/* 006340 70005740 26103FF8 */  addiu $s0, %lo(stderr_buffer + 0x8E0) # addiu $s0, $s0, 0x3ff8
/* 006344 70005744 28A1001F */  slti  $at, $a1, 0x1f
/* 006348 70005748 1420000A */  bnez  $at, .L70005774
/* 00634C 7000574C 24A4FFE2 */   addiu $a0, $a1, -0x1e
/* 006350 70005750 AFA20024 */  sw    $v0, 0x24($sp)
/* 006354 70005754 0C0015F3 */  jal   scroll_stderr_oneline
/* 006358 70005758 A3A6002B */   sb    $a2, 0x2b($sp)
/* 00635C 7000575C 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006360 70005760 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006364 70005764 2408001E */  li    $t0, 30
/* 006368 70005768 8FA20024 */  lw    $v0, 0x24($sp)
/* 00636C 7000576C 93A6002B */  lbu   $a2, 0x2b($sp)
/* 006370 70005770 AC680000 */  sw    $t0, ($v1)
.L70005774:
/* 006374 70005774 2401000A */  li    $at, 10
/* 006378 70005778 50410010 */  beql  $v0, $at, .L700057BC
/* 00637C 7000577C 8FBF001C */   lw    $ra, 0x1c($sp)
/* 006380 70005780 8E040000 */  lw    $a0, ($s0)
/* 006384 70005784 0C00158C */  jal   write_char_to_pos_stderr
/* 006388 70005788 8C650000 */   lw    $a1, ($v1)
/* 00638C 7000578C 8E090000 */  lw    $t1, ($s0)
/* 006390 70005790 3C038002 */  lui   $v1, %hi(stderr_buffer + 0x8E4)
/* 006394 70005794 24633FFC */  addiu $v1, %lo(stderr_buffer + 0x8E4) # addiu $v1, $v1, 0x3ffc
/* 006398 70005798 252A0001 */  addiu $t2, $t1, 1
/* 00639C 7000579C 29410047 */  slti  $at, $t2, 0x47
/* 0063A0 700057A0 14200005 */  bnez  $at, .L700057B8
/* 0063A4 700057A4 AE0A0000 */   sw    $t2, ($s0)
/* 0063A8 700057A8 8C6C0000 */  lw    $t4, ($v1)
/* 0063AC 700057AC AE000000 */  sw    $zero, ($s0)
/* 0063B0 700057B0 258D0001 */  addiu $t5, $t4, 1
/* 0063B4 700057B4 AC6D0000 */  sw    $t5, ($v1)
.L700057B8:
/* 0063B8 700057B8 8FBF001C */  lw    $ra, 0x1c($sp)
.L700057BC:
/* 0063BC 700057BC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0063C0 700057C0 27BD0028 */  addiu $sp, $sp, 0x28
/* 0063C4 700057C4 03E00008 */  jr    $ra
/* 0063C8 700057C8 00000000 */   nop   
)
#endif




/**
 * 63CC	700057CC
 *     scroll stderr down one line
 *     accepts: A0=ypos
 */
#ifdef NONMATCHING
s32 scroll_stderr_oneline(s32 arg0) {
    void *temp_a1_2;
    void *temp_a1;

    // Node 0
    if (0 < arg0)
    {
        // Node 1
        // Node 2
        // Node 3
        temp_a1_2 = (&stderr_buffer + 3);
        stderr_buffer = (s8) stderr_buffer.unk47;
        stderr_buffer.unk1 = (s8) stderr_buffer.unk48;
        stderr_buffer.unk2 = (s8) stderr_buffer.unk49;
        // Node 4
        temp_a1 = (temp_a1_2 + 4);
        temp_a1->unk-3 = (s8) temp_a1_2->unk48;
        temp_a1->unk-2 = (s8) temp_a1_2->unk49;
        temp_a1->unk-1 = (s8) temp_a1_2->unk4A;
        temp_a1->unk-4 = (s8) temp_a1_2->unk47;
        if ((3 + 4) != 0x47)
        {
            goto loop_4;
        }
        // Node 5
        if ((&stderr_buffer + 0x47) != (stderr_buffer + 0x899))
        {
            goto loop_3;
        }
        // Node 6
        if (0 < (arg0 + -1))
        {
            goto loop_2;
        }
    }
    // (possible return value: (0 < arg0))
}
#else
GLOBAL_ASM(
.text
glabel scroll_stderr_oneline
/* 0063CC 700057CC 0004102A */  slt   $v0, $zero, $a0
/* 0063D0 700057D0 10400020 */  beqz  $v0, .L70005854
/* 0063D4 700057D4 2484FFFF */   addiu $a0, $a0, -1
/* 0063D8 700057D8 3C088002 */  lui   $t0, %hi(stderr_buffer + 0x899) 
/* 0063DC 700057DC 25083FB1 */  addiu $t0, %lo(stderr_buffer + 0x899) # addiu $t0, $t0, 0x3fb1
/* 0063E0 700057E0 24070047 */  li    $a3, 71
.L700057E4:
/* 0063E4 700057E4 3C0E8002 */  lui   $t6, %hi(stderr_buffer)
/* 0063E8 700057E8 25C63718 */  addiu $a2, $t6, %lo(stderr_buffer)
/* 0063EC 700057EC 00C01825 */  move  $v1, $a2
.L700057F0:
/* 0063F0 700057F0 90CF0047 */  lbu   $t7, 0x47($a2)
/* 0063F4 700057F4 90D80048 */  lbu   $t8, 0x48($a2)
/* 0063F8 700057F8 90D90049 */  lbu   $t9, 0x49($a2)
/* 0063FC 700057FC 24020003 */  li    $v0, 3
/* 006400 70005800 24650003 */  addiu $a1, $v1, 3
/* 006404 70005804 A0CF0000 */  sb    $t7, ($a2)
/* 006408 70005808 A0D80001 */  sb    $t8, 1($a2)
/* 00640C 7000580C A0D90002 */  sb    $t9, 2($a2)
.L70005810:
/* 006410 70005810 90AA0048 */  lbu   $t2, 0x48($a1)
/* 006414 70005814 90AB0049 */  lbu   $t3, 0x49($a1)
/* 006418 70005818 90AC004A */  lbu   $t4, 0x4a($a1)
/* 00641C 7000581C 90A90047 */  lbu   $t1, 0x47($a1)
/* 006420 70005820 24420004 */  addiu $v0, $v0, 4
/* 006424 70005824 24A50004 */  addiu $a1, $a1, 4
/* 006428 70005828 A0AAFFFD */  sb    $t2, -3($a1)
/* 00642C 7000582C A0ABFFFE */  sb    $t3, -2($a1)
/* 006430 70005830 A0ACFFFF */  sb    $t4, -1($a1)
/* 006434 70005834 1447FFF6 */  bne   $v0, $a3, .L70005810
/* 006438 70005838 A0A9FFFC */   sb    $t1, -4($a1)
/* 00643C 7000583C 24C60047 */  addiu $a2, $a2, 0x47
/* 006440 70005840 14C8FFEB */  bne   $a2, $t0, .L700057F0
/* 006444 70005844 24630047 */   addiu $v1, $v1, 0x47
/* 006448 70005848 0004102A */  slt   $v0, $zero, $a0
/* 00644C 7000584C 1440FFE5 */  bnez  $v0, .L700057E4
/* 006450 70005850 2484FFFF */   addiu $a0, $a0, -1
.L70005854:
/* 006454 70005854 03E00008 */  jr    $ra
/* 006458 70005858 00000000 */   nop   
)
#endif




/**
 * 645C	7000585C
 *     print char A2 to stderr screen position (A0,A1) in video buffer 1
 *     accepts: A0=xpos, A1=ypos, A2=char
 */
#ifdef NONMATCHING
void print_to_vidbuff1(s32 arg0, s32 arg1, ? arg2, s32 arg6, s32 arg7, s32 arg8) {
    s32 temp_at;
    void *temp_a0;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;

    // Node 0
    if (arg8 == 0)
    {
        // Node 1
    }
    // Node 2
    temp_at = (arg8 < 0x7f);
    if (temp_at == 0)
    {
        // Node 3
        if (temp_at != 0)
        {
            // Node 4
            temp_a0 = (0x80020000 + (arg8 * 4));
            temp_v1 = (((arg6 * 2) + ptr_videobuffer1) + ((arg7 * get_video2_settings_txtClipW()) * 2));
            // Node 5
            if ((temp_a0->unk3F80 & 0x80000000) != 0)
            {
                // Node 6
                *temp_v1 = (u16)0xffff;
            }
            else
            {
                // Node 7
                *temp_v1 = (u16)1;
            }
            // Node 8
            temp_v1_2 = (temp_v1 + 2);
            if (((temp_a0->unk3F80 * 2) & 0x80000000) != 0)
            {
                // Node 9
                *temp_v1_2 = (u16)0xffff;
            }
            else
            {
                // Node 10
                *temp_v1_2 = (u16)1;
            }
            // Node 11
            temp_v1_3 = (temp_v1_2 + 2);
            if (((temp_a0->unk3F80 * 4) & 0x80000000) != 0)
            {
                // Node 12
                *temp_v1_3 = (u16)0xffff;
            }
            else
            {
                // Node 13
                *temp_v1_3 = (u16)1;
            }
            // Node 14
            temp_v1_4 = (temp_v1_3 + 2);
            if (((temp_a0->unk3F80 * 8) & 0x80000000) != 0)
            {
                // Node 15
                *temp_v1_4 = (u16)0xffff;
            }
            else
            {
                // Node 16
                *temp_v1_4 = (u16)1;
            }
            // Node 17
            if ((0 + 1) != 7)
            {
                goto loop_5;
            }
        }
    }
    // (possible return value: get_video2_settings_txtClipW())
}

#else
GLOBAL_ASM(
.text
glabel print_to_vidbuff1
/* 00645C 7000585C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006460 70005860 AFBF0014 */  sw    $ra, 0x14($sp)
/* 006464 70005864 AFA40018 */  sw    $a0, 0x18($sp)
/* 006468 70005868 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00646C 7000586C 0C001107 */  jal   get_video2_settings_txtClipW
/* 006470 70005870 AFA60020 */   sw    $a2, 0x20($sp)
/* 006474 70005874 93A50023 */  lbu   $a1, 0x23($sp)
/* 006478 70005878 54A00003 */  bnezl $a1, .L70005888
/* 00647C 7000587C 28A10020 */   slti  $at, $a1, 0x20
/* 006480 70005880 24050020 */  li    $a1, 32
/* 006484 70005884 28A10020 */  slti  $at, $a1, 0x20
.L70005888:
/* 006488 70005888 1420003A */  bnez  $at, .L70005974
/* 00648C 7000588C 28A1007F */   slti  $at, $a1, 0x7f
/* 006490 70005890 10200038 */  beqz  $at, .L70005974
/* 006494 70005894 8FAE0018 */   lw    $t6, 0x18($sp)
/* 006498 70005898 8FAB001C */  lw    $t3, 0x1c($sp)
/* 00649C 7000589C 3C188002 */  lui   $t8, %hi(ptr_videobuffer1) 
/* 0064A0 700058A0 8F18417C */  lw    $t8, %lo(ptr_videobuffer1)($t8)
/* 0064A4 700058A4 01620019 */  multu $t3, $v0
/* 0064A8 700058A8 000E7840 */  sll   $t7, $t6, 1
/* 0064AC 700058AC 00057080 */  sll   $t6, $a1, 2
/* 0064B0 700058B0 3C048002 */  lui   $a0, %hi(stderr_buffer+0x868)
/* 0064B4 700058B4 008E2021 */  addu  $a0, $a0, $t6
/* 0064B8 700058B8 01F8C821 */  addu  $t9, $t7, $t8
/* 0064BC 700058BC 8C843F80 */  lw    $a0, %lo(stderr_buffer+0x868)($a0)
/* 0064C0 700058C0 3C058000 */  lui   $a1, 0x8000
/* 0064C4 700058C4 00004025 */  move  $t0, $zero
/* 0064C8 700058C8 00024840 */  sll   $t1, $v0, 1
/* 0064CC 700058CC 00006012 */  mflo  $t4
/* 0064D0 700058D0 000C6840 */  sll   $t5, $t4, 1
/* 0064D4 700058D4 032D1821 */  addu  $v1, $t9, $t5
/* 0064D8 700058D8 240A0007 */  li    $t2, 7
/* 0064DC 700058DC 24070001 */  li    $a3, 1
/* 0064E0 700058E0 3406FFFF */  li    $a2, 65535
.L700058E4:
/* 0064E4 700058E4 00857824 */  and   $t7, $a0, $a1
/* 0064E8 700058E8 11E00003 */  beqz  $t7, .L700058F8
/* 0064EC 700058EC 0004C040 */   sll   $t8, $a0, 1
/* 0064F0 700058F0 10000002 */  b     .L700058FC
/* 0064F4 700058F4 A4660000 */   sh    $a2, ($v1)
.L700058F8:
/* 0064F8 700058F8 A4670000 */  sh    $a3, ($v1)
.L700058FC:
/* 0064FC 700058FC 03055824 */  and   $t3, $t8, $a1
/* 006500 70005900 24630002 */  addiu $v1, $v1, 2
/* 006504 70005904 11600003 */  beqz  $t3, .L70005914
/* 006508 70005908 03002025 */   move  $a0, $t8
/* 00650C 7000590C 10000002 */  b     .L70005918
/* 006510 70005910 A4660000 */   sh    $a2, ($v1)
.L70005914:
/* 006514 70005914 A4670000 */  sh    $a3, ($v1)
.L70005918:
/* 006518 70005918 00046040 */  sll   $t4, $a0, 1
/* 00651C 7000591C 0185C824 */  and   $t9, $t4, $a1
/* 006520 70005920 01802025 */  move  $a0, $t4
/* 006524 70005924 13200003 */  beqz  $t9, .L70005934
/* 006528 70005928 24630002 */   addiu $v1, $v1, 2
/* 00652C 7000592C 10000002 */  b     .L70005938
/* 006530 70005930 A4660000 */   sh    $a2, ($v1)
.L70005934:
/* 006534 70005934 A4670000 */  sh    $a3, ($v1)
.L70005938:
/* 006538 70005938 00046840 */  sll   $t5, $a0, 1
/* 00653C 7000593C 01A57024 */  and   $t6, $t5, $a1
/* 006540 70005940 01A02025 */  move  $a0, $t5
/* 006544 70005944 11C00003 */  beqz  $t6, .L70005954
/* 006548 70005948 24630002 */   addiu $v1, $v1, 2
/* 00654C 7000594C 10000002 */  b     .L70005958
/* 006550 70005950 A4660000 */   sh    $a2, ($v1)
.L70005954:
/* 006554 70005954 A4670000 */  sh    $a3, ($v1)
.L70005958:
/* 006558 70005958 24630002 */  addiu $v1, $v1, 2
/* 00655C 7000595C 25080001 */  addiu $t0, $t0, 1
/* 006560 70005960 00047840 */  sll   $t7, $a0, 1
/* 006564 70005964 00691821 */  addu  $v1, $v1, $t1
/* 006568 70005968 01E02025 */  move  $a0, $t7
/* 00656C 7000596C 150AFFDD */  bne   $t0, $t2, .L700058E4
/* 006570 70005970 2463FFF8 */   addiu $v1, $v1, -8
.L70005974:
/* 006574 70005974 8FBF0014 */  lw    $ra, 0x14($sp)
/* 006578 70005978 27BD0018 */  addiu $sp, $sp, 0x18
/* 00657C 7000597C 03E00008 */  jr    $ra
/* 006580 70005980 00000000 */   nop   
)
#endif




/**
 * 6584	70005984
 *     set pointers to video buffers 1 & 2 to A0 and A1, respectively
 *     sets values to uncached addresses
 *     A0 | A0000000 -> 8002417C
 *     A1 | A0000000 -> 80024180
 */
#ifdef NONMATCHING
void set_ptr_video_buffers(s32 arg0, s32 arg1) {
    ptr_videobuffer1 = (s32) (arg0 | 0xa0000000);
    ptr_videobuffer2 = (s32) (arg1 | 0xa0000000);
}

#else
GLOBAL_ASM(
.text
glabel set_ptr_video_buffers
/* 006584 70005984 3C02A000 */  lui   $v0, 0xa000
/* 006588 70005988 00827025 */  or    $t6, $a0, $v0
/* 00658C 7000598C 3C018002 */  lui   $at, %hi(ptr_videobuffer1)
/* 006590 70005990 AC2E417C */  sw    $t6, %lo(ptr_videobuffer1)($at)
/* 006594 70005994 3C018002 */  lui   $at, %hi(ptr_videobuffer2)
/* 006598 70005998 00A27825 */  or    $t7, $a1, $v0
/* 00659C 7000599C 03E00008 */  jr    $ra
/* 0065A0 700059A0 AC2F4180 */   sw    $t7, %lo(ptr_videobuffer2)($at)
)
#endif



/**
 * 65A4	700059A4
 *     set pointers to video buffers 1 & 2
 *     calls 70005984: A0=803B5000, A1=803DA800
 */
void set_video_buffer_pointers(void) {
    set_ptr_video_buffers(&cfb_16_a, &cfb_16_b);
}





/**
 * 65D0	700059D0
 *     write stderr to video buffer A0
 *     accepts: A0=p->video buffer
 */
#ifdef NONMATCHING
void write_stderr_to_buffer(void) {

}
#else
GLOBAL_ASM(
.text
glabel write_stderr_to_buffer
/* 0065D0 700059D0 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0065D4 700059D4 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0065D8 700059D8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0065DC 700059DC 00808025 */  move  $s0, $a0
/* 0065E0 700059E0 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0065E4 700059E4 AFB70034 */  sw    $s7, 0x34($sp)
/* 0065E8 700059E8 AFB60030 */  sw    $s6, 0x30($sp)
/* 0065EC 700059EC AFB5002C */  sw    $s5, 0x2c($sp)
/* 0065F0 700059F0 AFB40028 */  sw    $s4, 0x28($sp)
/* 0065F4 700059F4 AFB30024 */  sw    $s3, 0x24($sp)
/* 0065F8 700059F8 AFB20020 */  sw    $s2, 0x20($sp)
/* 0065FC 700059FC 0C001669 */  jal   set_video_buffer_pointers
/* 006600 70005A00 AFB1001C */   sw    $s1, 0x1c($sp)
/* 006604 70005A04 3C01A000 */  lui   $at, 0xa000
/* 006608 70005A08 02017025 */  or    $t6, $s0, $at
/* 00660C 70005A0C 3C018002 */  lui   $at, %hi(ptr_videobuffer1)
/* 006610 70005A10 0C001107 */  jal   get_video2_settings_txtClipW
/* 006614 70005A14 AC2E417C */   sw    $t6, %lo(ptr_videobuffer1)($at)
/* 006618 70005A18 2450FFF3 */  addiu $s0, $v0, -0xd
/* 00661C 70005A1C 06010003 */  bgez  $s0, .L70005A2C
/* 006620 70005A20 00107883 */   sra   $t7, $s0, 2
/* 006624 70005A24 26010003 */  addiu $at, $s0, 3
/* 006628 70005A28 00017883 */  sra   $t7, $at, 2
.L70005A2C:
/* 00662C 70005A2C 0C00110B */  jal   get_video2_settings_txtClipH
/* 006630 70005A30 01E08025 */   move  $s0, $t7
/* 006634 70005A34 2443FFF6 */  addiu $v1, $v0, -0xa
/* 006638 70005A38 24010007 */  li    $at, 7
/* 00663C 70005A3C 0061001A */  div   $zero, $v1, $at
/* 006640 70005A40 00001812 */  mflo  $v1
/* 006644 70005A44 247EFFFF */  addiu $fp, $v1, -1
/* 006648 70005A48 1BC00023 */  blez  $fp, .L70005AD8
/* 00664C 70005A4C 0000A825 */   move  $s5, $zero
/* 006650 70005A50 2616FFFB */  addiu $s6, $s0, -5
/* 006654 70005A54 2417001F */  li    $s7, 31
/* 006658 70005A58 24140130 */  li    $s4, 304
.L70005A5C:
/* 00665C 70005A5C 1AC00018 */  blez  $s6, .L70005AC0
/* 006660 70005A60 00008080 */   sll   $s0, $zero, 2
/* 006664 70005A64 0015C8C0 */  sll   $t9, $s5, 3
/* 006668 70005A68 0335C821 */  addu  $t9, $t9, $s5
/* 00666C 70005A6C 0019C8C0 */  sll   $t9, $t9, 3
/* 006670 70005A70 001590C0 */  sll   $s2, $s5, 3
/* 006674 70005A74 3C098002 */  lui   $t1, %hi(stderr_buffer) 
/* 006678 70005A78 25293718 */  addiu $t1, %lo(stderr_buffer) # addiu $t1, $t1, 0x3718
/* 00667C 70005A7C 02559023 */  subu  $s2, $s2, $s5
/* 006680 70005A80 0335C823 */  subu  $t9, $t9, $s5
/* 006684 70005A84 00169880 */  sll   $s3, $s6, 2
/* 006688 70005A88 26730014 */  addiu $s3, $s3, 0x14
/* 00668C 70005A8C 03298821 */  addu  $s1, $t9, $t1
/* 006690 70005A90 26520007 */  addiu $s2, $s2, 7
/* 006694 70005A94 26100014 */  addiu $s0, $s0, 0x14
/* 006698 70005A98 02002025 */  move  $a0, $s0
.L70005A9C:
/* 00669C 70005A9C 02402825 */  move  $a1, $s2
/* 0066A0 70005AA0 0C001617 */  jal   print_to_vidbuff1
/* 0066A4 70005AA4 92260000 */   lbu   $a2, ($s1)
/* 0066A8 70005AA8 26100004 */  addiu $s0, $s0, 4
/* 0066AC 70005AAC 0213082A */  slt   $at, $s0, $s3
/* 0066B0 70005AB0 10200003 */  beqz  $at, .L70005AC0
/* 0066B4 70005AB4 26310001 */   addiu $s1, $s1, 1
/* 0066B8 70005AB8 5614FFF8 */  bnel  $s0, $s4, .L70005A9C
/* 0066BC 70005ABC 02002025 */   move  $a0, $s0
.L70005AC0:
/* 0066C0 70005AC0 26B50001 */  addiu $s5, $s5, 1
/* 0066C4 70005AC4 02BE082A */  slt   $at, $s5, $fp
/* 0066C8 70005AC8 50200004 */  beql  $at, $zero, .L70005ADC
/* 0066CC 70005ACC 8FBF003C */   lw    $ra, 0x3c($sp)
/* 0066D0 70005AD0 16B7FFE2 */  bne   $s5, $s7, .L70005A5C
/* 0066D4 70005AD4 00000000 */   nop   
.L70005AD8:
/* 0066D8 70005AD8 8FBF003C */  lw    $ra, 0x3c($sp)
.L70005ADC:
/* 0066DC 70005ADC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0066E0 70005AE0 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0066E4 70005AE4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0066E8 70005AE8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0066EC 70005AEC 8FB40028 */  lw    $s4, 0x28($sp)
/* 0066F0 70005AF0 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0066F4 70005AF4 8FB60030 */  lw    $s6, 0x30($sp)
/* 0066F8 70005AF8 8FB70034 */  lw    $s7, 0x34($sp)
/* 0066FC 70005AFC 8FBE0038 */  lw    $fp, 0x38($sp)
/* 006700 70005B00 03E00008 */  jr    $ra
/* 006704 70005B04 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif
