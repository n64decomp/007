//FIXME my c code is modtly copy/paste from mips_to_c
#include "ultra64.h"
#include "bondgame.h"
#include "deb_video.h"

/**
 * @file deb_video.c
 * This file contains code to handle tlb paging. 
 * 
 * I should probably be renamed...
 */

//bss
char thread_video_manager_debugthread[0x6B0];
char tlbStack[0x2300];
OSMesgQueue thread5_MesgQ;
u32 thread5_MesgBuf;
OSThread *ptr_tlbthread_maybe;
u32 dword_CODE_bss_80063660;
u32 *current_indy_read_buf_resourceID;
u32 *ptr_indy_read_buf_string1;
u32 *ptr_indy_read_buf_string2;
char indy_read_buffer[0x60];


/**
 * 5AE0	70004EE0
 */
void init_tlb(void) {
    set_video_buffer_pointers();
    osCreateMesgQueue(&thread5_MesgQ, &thread5_MesgBuf, 1);
    osCreateThread(&thread_video_manager_debugthread, 5, &thread5_translate_7F_address, 0, &tlbStack, 0x28);
    osStartThread(&thread_video_manager_debugthread);
}





/**
 * 5B54	70004F54
 */
#ifdef NONMATCHING
void thread5_translate_7F_address(void) {

}
#else
GLOBAL_ASM(
.text
glabel thread5_translate_7F_address
/* 005B54 70004F54 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 005B58 70004F58 AFB70030 */  sw    $s7, 0x30($sp)
/* 005B5C 70004F5C 3C178006 */  lui   $s7, %hi(thread5_MesgQ) 
/* 005B60 70004F60 26F73640 */  addiu $s7, %lo(thread5_MesgQ) # addiu $s7, $s7, 0x3640
/* 005B64 70004F64 AFBF0034 */  sw    $ra, 0x34($sp)
/* 005B68 70004F68 AFA40040 */  sw    $a0, 0x40($sp)
/* 005B6C 70004F6C AFB6002C */  sw    $s6, 0x2c($sp)
/* 005B70 70004F70 AFB50028 */  sw    $s5, 0x28($sp)
/* 005B74 70004F74 AFB40024 */  sw    $s4, 0x24($sp)
/* 005B78 70004F78 AFB30020 */  sw    $s3, 0x20($sp)
/* 005B7C 70004F7C AFB2001C */  sw    $s2, 0x1c($sp)
/* 005B80 70004F80 AFB10018 */  sw    $s1, 0x18($sp)
/* 005B84 70004F84 AFB00014 */  sw    $s0, 0x14($sp)
/* 005B88 70004F88 AFA0003C */  sw    $zero, 0x3c($sp)
/* 005B8C 70004F8C 2404000C */  li    $a0, 12
/* 005B90 70004F90 02E02825 */  move  $a1, $s7
/* 005B94 70004F94 0C003714 */  jal   osSetEventMesg
/* 005B98 70004F98 24060010 */   li    $a2, 16
/* 005B9C 70004F9C 3C018006 */  lui   $at, %hi(dword_CODE_bss_80063660)
/* 005BA0 70004FA0 3C168002 */  lui   $s6, %hi(__osRunQueue)
/* 005BA4 70004FA4 AC203660 */  sw    $zero, %lo(dword_CODE_bss_80063660)($at)
/* 005BA8 70004FA8 26D67728 */  addiu $s6, %lo(__osRunQueue) # addiu $s6, $s6, 0x7728
/* 005BAC 70004FAC 2415000A */  li    $s5, 10
/* 005BB0 70004FB0 3C14FFC0 */  lui   $s4, 0xffc0
/* 005BB4 70004FB4 3C137F00 */  lui   $s3, 0x7f00
/* 005BB8 70004FB8 24120008 */  li    $s2, 8
/* 005BBC 70004FBC 27B1003C */  addiu $s1, $sp, 0x3c
.L70004FC0:
/* 005BC0 70004FC0 02E02025 */  move  $a0, $s7
.L70004FC4:
/* 005BC4 70004FC4 02202825 */  move  $a1, $s1
/* 005BC8 70004FC8 0C003774 */  jal   osRecvMesg
/* 005BCC 70004FCC 24060001 */   li    $a2, 1
/* 005BD0 70004FD0 0C00374C */  jal   osSetIntMask
/* 005BD4 70004FD4 24040001 */   li    $a0, 1
/* 005BD8 70004FD8 0C004060 */  jal   ultra_70010180
/* 005BDC 70004FDC 00408025 */   move  $s0, $v0
/* 005BE0 70004FE0 3C018006 */  lui   $at, %hi(ptr_tlbthread_maybe)
/* 005BE4 70004FE4 1040FFF6 */  beqz  $v0, .L70004FC0
/* 005BE8 70004FE8 AC22365C */   sw    $v0, %lo(ptr_tlbthread_maybe)($at)
/* 005BEC 70004FEC 8C4E0120 */  lw    $t6, 0x120($v0)
/* 005BF0 70004FF0 3C088006 */  lui   $t0, %hi(ptr_tlbthread_maybe) 
/* 005BF4 70004FF4 31CF007C */  andi  $t7, $t6, 0x7c
/* 005BF8 70004FF8 164F0018 */  bne   $s2, $t7, .L7000505C
/* 005BFC 70004FFC 00000000 */   nop   
/* 005C00 70005000 8C580124 */  lw    $t8, 0x124($v0)
/* 005C04 70005004 0314C824 */  and   $t9, $t8, $s4
/* 005C08 70005008 16790014 */  bne   $s3, $t9, .L7000505C
/* 005C0C 7000500C 00000000 */   nop   
/* 005C10 70005010 8D08365C */  lw    $t0, %lo(ptr_tlbthread_maybe)($t0)
/* 005C14 70005014 0C000676 */  jal   translate_load_rom_from_TLBaddress
/* 005C18 70005018 8D040124 */   lw    $a0, 0x124($t0)
/* 005C1C 7000501C 3C098006 */  lui   $t1, %hi(ptr_tlbthread_maybe) 
/* 005C20 70005020 8D29365C */  lw    $t1, %lo(ptr_tlbthread_maybe)($t1)
/* 005C24 70005024 3C0A8006 */  lui   $t2, %hi(ptr_tlbthread_maybe) 
/* 005C28 70005028 3C058006 */  lui   $a1, %hi(ptr_tlbthread_maybe)
/* 005C2C 7000502C A5350010 */  sh    $s5, 0x10($t1)
/* 005C30 70005030 8D4A365C */  lw    $t2, %lo(ptr_tlbthread_maybe)($t2)
/* 005C34 70005034 02C02025 */  move  $a0, $s6
/* 005C38 70005038 A5400012 */  sh    $zero, 0x12($t2)
/* 005C3C 7000503C 0C00422B */  jal   __osEnqueueThread
/* 005C40 70005040 8CA5365C */   lw    $a1, %lo(ptr_tlbthread_maybe)($a1)
/* 005C44 70005044 0C00374C */  jal   osSetIntMask
/* 005C48 70005048 02002025 */   move  $a0, $s0
/* 005C4C 7000504C 0C0042B4 */  jal   osYieldThread
/* 005C50 70005050 00000000 */   nop   
/* 005C54 70005054 1000FFDB */  b     .L70004FC4
/* 005C58 70005058 02E02025 */   move  $a0, $s7
.L7000505C:
/* 005C5C 7000505C 0C00374C */  jal   osSetIntMask
/* 005C60 70005060 02002025 */   move  $a0, $s0
.L70005064:
/* 005C64 70005064 1000FFFF */  b     .L70005064
/* 005C68 70005068 00000000 */   nop   
/* 005C6C 7000506C 00000000 */  nop   
/* 005C70 70005070 00000000 */  nop   
/* 005C74 70005074 00000000 */  nop   
/* 005C78 70005078 00000000 */  nop   
/* 005C7C 7000507C 00000000 */  nop   
/* 005C80 70005080 8FBF0034 */  lw    $ra, 0x34($sp)
/* 005C84 70005084 8FB00014 */  lw    $s0, 0x14($sp)
/* 005C88 70005088 8FB10018 */  lw    $s1, 0x18($sp)
/* 005C8C 7000508C 8FB2001C */  lw    $s2, 0x1c($sp)
/* 005C90 70005090 8FB30020 */  lw    $s3, 0x20($sp)
/* 005C94 70005094 8FB40024 */  lw    $s4, 0x24($sp)
/* 005C98 70005098 8FB50028 */  lw    $s5, 0x28($sp)
/* 005C9C 7000509C 8FB6002C */  lw    $s6, 0x2c($sp)
/* 005CA0 700050A0 8FB70030 */  lw    $s7, 0x30($sp)
/* 005CA4 700050A4 03E00008 */  jr    $ra
/* 005CA8 700050A8 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif

/**
 * 5CAC	700050AC
 *     V0= SP, A3=SP usage within function range (A1,A0) with initial SP A2
 *     accepts: A0=p->opcode.cur, A1=p->opcode.start, A2=SP w/i function, A3=p->register buffer
 */
#ifdef NONMATCHING
void debug_related_8(void) {

}
#else
GLOBAL_ASM(
.text
glabel debug_related_8
/* 005CAC 700050AC 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 005CB0 700050B0 AFA40010 */  sw    $a0, 0x10($sp)
/* 005CB4 700050B4 AFB1000C */  sw    $s1, 0xc($sp)
/* 005CB8 700050B8 AFB00008 */  sw    $s0, 8($sp)
/* 005CBC 700050BC 00C01825 */  move  $v1, $a2
/* 005CC0 700050C0 00001025 */  move  $v0, $zero
/* 005CC4 700050C4 00004025 */  move  $t0, $zero
/* 005CC8 700050C8 24040020 */  li    $a0, 32
/* 005CCC 700050CC 00004825 */  move  $t1, $zero
/* 005CD0 700050D0 00E05025 */  move  $t2, $a3
.L700050D4:
/* 005CD4 700050D4 25290004 */  addiu $t1, $t1, 4
/* 005CD8 700050D8 AD400000 */  sw    $zero, ($t2)
/* 005CDC 700050DC AD400004 */  sw    $zero, 4($t2)
/* 005CE0 700050E0 AD400008 */  sw    $zero, 8($t2)
/* 005CE4 700050E4 AD40000C */  sw    $zero, 0xc($t2)
/* 005CE8 700050E8 1524FFFA */  bne   $t1, $a0, .L700050D4
/* 005CEC 700050EC 254A0010 */   addiu $t2, $t2, 0x10
/* 005CF0 700050F0 8FA40010 */  lw    $a0, 0x10($sp)
/* 005CF4 700050F4 3C1103E0 */  lui   $s1, (0x03E00008 >> 16) # lui $s1, 0x3e0
/* 005CF8 700050F8 36310008 */  ori   $s1, (0x03E00008 & 0xFFFF) # ori $s1, $s1, 8
/* 005CFC 700050FC 0085082B */  sltu  $at, $a0, $a1
/* 005D00 70005100 1420002D */  bnez  $at, .L700051B8
/* 005D04 70005104 2410001F */   li    $s0, 31
/* 005D08 70005108 3C0DFFE0 */  lui   $t5, 0xffe0
/* 005D0C 7000510C 3C0CAFA0 */  lui   $t4, 0xafa0
/* 005D10 70005110 3C0BFFFF */  lui   $t3, 0xffff
/* 005D14 70005114 3C0A27BD */  lui   $t2, 0x27bd
/* 005D18 70005118 8C890000 */  lw    $t1, ($a0)
.L7000511C:
/* 005D1C 7000511C 2484FFFC */  addiu $a0, $a0, -4
/* 005D20 70005120 0085082B */  sltu  $at, $a0, $a1
/* 005D24 70005124 012B7824 */  and   $t7, $t1, $t3
/* 005D28 70005128 154F000B */  bne   $t2, $t7, .L70005158
/* 005D2C 7000512C 012DC024 */   and   $t8, $t1, $t5
/* 005D30 70005130 0009C400 */  sll   $t8, $t1, 0x10
/* 005D34 70005134 0018CC03 */  sra   $t9, $t8, 0x10
/* 005D38 70005138 1F20001F */  bgtz  $t9, .L700051B8
/* 005D3C 7000513C 24020001 */   li    $v0, 1
/* 005D40 70005140 00197083 */  sra   $t6, $t9, 2
/* 005D44 70005144 000E7880 */  sll   $t7, $t6, 2
/* 005D48 70005148 11000019 */  beqz  $t0, .L700051B0
/* 005D4C 7000514C 006F1823 */   subu  $v1, $v1, $t7
/* 005D50 70005150 10000019 */  b     .L700051B8
/* 005D54 70005154 00000000 */   nop   
.L70005158:
/* 005D58 70005158 15980013 */  bne   $t4, $t8, .L700051A8
/* 005D5C 7000515C 00093402 */   srl   $a2, $t1, 0x10
/* 005D60 70005160 30D9001F */  andi  $t9, $a2, 0x1f
/* 005D64 70005164 00097C00 */  sll   $t7, $t1, 0x10
/* 005D68 70005168 000FC403 */  sra   $t8, $t7, 0x10
/* 005D6C 7000516C 03203025 */  move  $a2, $t9
/* 005D70 70005170 0018C883 */  sra   $t9, $t8, 2
/* 005D74 70005174 00197080 */  sll   $t6, $t9, 2
/* 005D78 70005178 0006C080 */  sll   $t8, $a2, 2
/* 005D7C 7000517C 00F8C821 */  addu  $t9, $a3, $t8
/* 005D80 70005180 01C37821 */  addu  $t7, $t6, $v1
/* 005D84 70005184 16060002 */  bne   $s0, $a2, .L70005190
/* 005D88 70005188 AF2F0000 */   sw    $t7, ($t9)
/* 005D8C 7000518C 24080001 */  li    $t0, 1
.L70005190:
/* 005D90 70005190 10400007 */  beqz  $v0, .L700051B0
/* 005D94 70005194 00000000 */   nop   
/* 005D98 70005198 11000005 */  beqz  $t0, .L700051B0
/* 005D9C 7000519C 00000000 */   nop   
/* 005DA0 700051A0 10000005 */  b     .L700051B8
/* 005DA4 700051A4 00000000 */   nop   
.L700051A8:
/* 005DA8 700051A8 11310003 */  beq   $t1, $s1, .L700051B8
/* 005DAC 700051AC 00000000 */   nop   
.L700051B0:
/* 005DB0 700051B0 5020FFDA */  beql  $at, $zero, .L7000511C
/* 005DB4 700051B4 8C890000 */   lw    $t1, ($a0)
.L700051B8:
/* 005DB8 700051B8 10400005 */  beqz  $v0, .L700051D0
/* 005DBC 700051BC 8FB00008 */   lw    $s0, 8($sp)
/* 005DC0 700051C0 51000004 */  beql  $t0, $zero, .L700051D4
/* 005DC4 700051C4 00001025 */   move  $v0, $zero
/* 005DC8 700051C8 10000002 */  b     .L700051D4
/* 005DCC 700051CC 00601025 */   move  $v0, $v1
.L700051D0:
/* 005DD0 700051D0 00001025 */  move  $v0, $zero
.L700051D4:
/* 005DD4 700051D4 8FB1000C */  lw    $s1, 0xc($sp)
/* 005DD8 700051D8 03E00008 */  jr    $ra
/* 005DDC 700051DC 27BD0010 */   addiu $sp, $sp, 0x10
)
#endif

/**
 * 5DE0	700051E0
 *     V0=TRUE if opcode that set RA A0 was a JAL or JALR type within bounds (70000450,70020D90)
 *     accepts: A0=p->70-mapped TLB function, presumably from RA
 */
#ifdef NONMATCHING
void was_opcode_In_70000450_70020D90(u32 * function)
{
    if ((function & 3) == 0) && (function >= &_codeSegmentStart) && (&_codeSegmentEnd >= function) {
        if ((function[-2] & 0xfc00003c) == 9)
        {
            return 1;
        }
        if ((function[] & 0xfc000000) == 0xc000000)
        {
            return 1;
        }
    }
    return 0;
}
#else
GLOBAL_ASM(
.text
glabel was_opcode_In_70000450_70020D90
/* 005DE0 700051E0 308E0003 */  andi  $t6, $a0, 3
/* 005DE4 700051E4 15C00019 */  bnez  $t6, .L7000524C
/* 005DE8 700051E8 3C0F7000 */   lui   $t7, %hi(_codeSegmentStart) # $t7, 0x7000
/* 005DEC 700051EC 25EF0450 */  addiu $t7, %lo(_codeSegmentStart) # addiu $t7, $t7, 0x450
/* 005DF0 700051F0 008F082B */  sltu  $at, $a0, $t7
/* 005DF4 700051F4 14200015 */  bnez  $at, .L7000524C
/* 005DF8 700051F8 3C187002 */   lui   $t8, %hi(_codeSegmentEnd) # $t8, 0x7002
/* 005DFC 700051FC 27180D90 */  addiu $t8, %lo(_codeSegmentEnd) # addiu $t8, $t8, 0xd90
/* 005E00 70005200 0304082B */  sltu  $at, $t8, $a0
/* 005E04 70005204 54200012 */  bnezl $at, .L70005250
/* 005E08 70005208 00001025 */   move  $v0, $zero
/* 005E0C 7000520C 8C82FFF8 */  lw    $v0, -8($a0)
/* 005E10 70005210 3C01FC00 */  lui   $at, (0xFC00003C >> 16) # lui $at, 0xfc00
/* 005E14 70005214 3421003C */  ori   $at, (0xFC00003C & 0xFFFF) # ori $at, $at, 0x3c
/* 005E18 70005218 0041C824 */  and   $t9, $v0, $at
/* 005E1C 7000521C 24010009 */  li    $at, 9
/* 005E20 70005220 57210004 */  bnel  $t9, $at, .L70005234
/* 005E24 70005224 3C01FC00 */   lui   $at, 0xfc00
/* 005E28 70005228 03E00008 */  jr    $ra
/* 005E2C 7000522C 24020001 */   li    $v0, 1

/* 005E30 70005230 3C01FC00 */  lui   $at, 0xfc00
.L70005234:
/* 005E34 70005234 00414024 */  and   $t0, $v0, $at
/* 005E38 70005238 3C010C00 */  lui   $at, 0xc00
/* 005E3C 7000523C 55010004 */  bnel  $t0, $at, .L70005250
/* 005E40 70005240 00001025 */   move  $v0, $zero
/* 005E44 70005244 03E00008 */  jr    $ra
/* 005E48 70005248 24020001 */   li    $v0, 1

.L7000524C:
/* 005E4C 7000524C 00001025 */  move  $v0, $zero
.L70005250:
/* 005E50 70005250 03E00008 */  jr    $ra
/* 005E54 70005254 00000000 */   nop   
)
#endif




/**
 * 5E58	70005258
 *     V0= strlen(A0); used exclusively for scanning ind.rea.buf
 *     accepts: A0=p->string
 */
#ifdef NONMATCHING
s32 return_strlen(void *arg0)
{
    s32 temp_v1;
    s32 phi_v1;
    void *phi_a0;
    s32 phi_v1_2;

    phi_v1 = 0;
    phi_a0 = (arg0 + 1);
    phi_v1_2 = 0;
    if (*arg0 != 0)
    {
loop_1:
        temp_v1 = (phi_v1 + 1);
        phi_v1_2 = temp_v1;
        if (temp_v1 < 0x100)
        {
            phi_v1 = temp_v1;
            phi_a0 = (phi_a0 + 1);
            phi_v1_2 = temp_v1;
            if (*phi_a0 != 0)
            {
                goto loop_1;
            }
        }
    }
    return phi_v1_2;
}
#else
GLOBAL_ASM(
.text
glabel return_strlen
/* 005E58 70005258 90820000 */  lbu   $v0, ($a0)
/* 005E5C 7000525C 00001825 */  move  $v1, $zero
/* 005E60 70005260 24840001 */  addiu $a0, $a0, 1
/* 005E64 70005264 10400009 */  beqz  $v0, .L7000528C
/* 005E68 70005268 00000000 */   nop   
/* 005E6C 7000526C 24630001 */  addiu $v1, $v1, 1
.L70005270:
/* 005E70 70005270 28610100 */  slti  $at, $v1, 0x100
/* 005E74 70005274 10200005 */  beqz  $at, .L7000528C
/* 005E78 70005278 00000000 */   nop   
/* 005E7C 7000527C 90820000 */  lbu   $v0, ($a0)
/* 005E80 70005280 24840001 */  addiu $a0, $a0, 1
/* 005E84 70005284 5440FFFA */  bnezl $v0, .L70005270
/* 005E88 70005288 24630001 */   addiu $v1, $v1, 1
.L7000528C:
/* 005E8C 7000528C 03E00008 */  jr    $ra
/* 005E90 70005290 00601025 */   move  $v0, $v1
)
#endif



/**
 * 5E94	70005294
 *     V0= total size of one word, two strings at hardware A0
 *     accepts: A0=hardware address
 */
#ifdef NONMATCHING
s32 indy_file_get_address_subsequent_data(s32 arg0) {
    s32 sp18;
    s32 temp_v1;
    s32 phi_a0;

    // Node 0
    romCopy(&indy_read_buffer, arg0, 0x60);
    current_indy_read_buf_resourceID = (?32) indy_read_buffer;
    ptr_indy_read_buf_string1 = &indy_read_buffer;
    ptr_indy_read_buf_string2 = (s32) ((return_strlen(&indy_read_buffer) + ptr_indy_read_buf_string1) + 1);
    sp18 = return_strlen(ptr_indy_read_buf_string1);
    temp_v1 = (((return_strlen(ptr_indy_read_buf_string2) + arg0) + sp18) + 6);
    phi_a0 = temp_v1;
    if ((temp_v1 & 3) != 0)
    {
        // Node 1
        phi_a0 = ((temp_v1 | 3) + 1);
    }
    // Node 2
    return phi_a0;
}
#else
GLOBAL_ASM(
.text
glabel indy_file_get_address_subsequent_data
/* 005E94 70005294 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 005E98 70005298 AFA40020 */  sw    $a0, 0x20($sp)
/* 005E9C 7000529C AFBF0014 */  sw    $ra, 0x14($sp)
/* 005EA0 700052A0 3C048006 */  lui   $a0, %hi(indy_read_buffer)
/* 005EA4 700052A4 24843670 */  addiu $a0, %lo(indy_read_buffer) # addiu $a0, $a0, 0x3670
/* 005EA8 700052A8 8FA50020 */  lw    $a1, 0x20($sp)
/* 005EAC 700052AC 0C001707 */  jal   romCopy
/* 005EB0 700052B0 24060060 */   li    $a2, 96
/* 005EB4 700052B4 3C0E8006 */  lui   $t6, %hi(indy_read_buffer) 
/* 005EB8 700052B8 8DCE3670 */  lw    $t6, %lo(indy_read_buffer)($t6)
/* 005EBC 700052BC 3C028006 */  lui   $v0, %hi(ptr_indy_read_buf_string1)
/* 005EC0 700052C0 3C018006 */  lui   $at, %hi(current_indy_read_buf_resourceID)
/* 005EC4 700052C4 3C0F8006 */  lui   $t7, %hi(indy_read_buffer+4)
/* 005EC8 700052C8 24423668 */  addiu $v0, %lo(ptr_indy_read_buf_string1) # addiu $v0, $v0, 0x3668
/* 005ECC 700052CC 25E43674 */  addiu $a0, $t7, %lo(indy_read_buffer+4)
/* 005ED0 700052D0 AC2E3664 */  sw    $t6, %lo(current_indy_read_buf_resourceID)($at)
/* 005ED4 700052D4 0C001496 */  jal   return_strlen
/* 005ED8 700052D8 AC440000 */   sw    $a0, ($v0)
/* 005EDC 700052DC 3C048006 */  lui   $a0, %hi(ptr_indy_read_buf_string1)
/* 005EE0 700052E0 8C843668 */  lw    $a0, %lo(ptr_indy_read_buf_string1)($a0)
/* 005EE4 700052E4 3C018006 */  lui   $at, %hi(ptr_indy_read_buf_string2)
/* 005EE8 700052E8 0044C021 */  addu  $t8, $v0, $a0
/* 005EEC 700052EC 27190001 */  addiu $t9, $t8, 1
/* 005EF0 700052F0 0C001496 */  jal   return_strlen
/* 005EF4 700052F4 AC39366C */   sw    $t9, %lo(ptr_indy_read_buf_string2)($at)
/* 005EF8 700052F8 3C048006 */  lui   $a0, %hi(ptr_indy_read_buf_string2)
/* 005EFC 700052FC 8C84366C */  lw    $a0, %lo(ptr_indy_read_buf_string2)($a0)
/* 005F00 70005300 0C001496 */  jal   return_strlen
/* 005F04 70005304 AFA20018 */   sw    $v0, 0x18($sp)
/* 005F08 70005308 8FA80020 */  lw    $t0, 0x20($sp)
/* 005F0C 7000530C 8FAA0018 */  lw    $t2, 0x18($sp)
/* 005F10 70005310 8FBF0014 */  lw    $ra, 0x14($sp)
/* 005F14 70005314 00484821 */  addu  $t1, $v0, $t0
/* 005F18 70005318 012A1821 */  addu  $v1, $t1, $t2
/* 005F1C 7000531C 24630006 */  addiu $v1, $v1, 6
/* 005F20 70005320 306B0003 */  andi  $t3, $v1, 3
/* 005F24 70005324 11600003 */  beqz  $t3, .L70005334
/* 005F28 70005328 00602025 */   move  $a0, $v1
/* 005F2C 7000532C 34640003 */  ori   $a0, $v1, 3
/* 005F30 70005330 24840001 */  addiu $a0, $a0, 1
.L70005334:
/* 005F34 70005334 00801025 */  move  $v0, $a0
/* 005F38 70005338 03E00008 */  jr    $ra
/* 005F3C 7000533C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif



/**
 * 5F40	70005340
 *     scan for and load resourceID A0 from indy.read.buf
 *     accepts: A0=resourceID
 */
#ifdef NONMATCHING
void scan_load_resourceID_from_indy_read_buf(void) {

}
#else
GLOBAL_ASM(
.text
glabel scan_load_resourceID_from_indy_read_buf
/* 005F40 70005340 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 005F44 70005344 AFB30020 */  sw    $s3, 0x20($sp)
/* 005F48 70005348 AFB2001C */  sw    $s2, 0x1c($sp)
/* 005F4C 7000534C 3C0200E0 */  lui   $v0, 0xe0
/* 005F50 70005350 34530004 */  ori   $s3, $v0, 4
/* 005F54 70005354 AFB10018 */  sw    $s1, 0x18($sp)
/* 005F58 70005358 AFB00014 */  sw    $s0, 0x14($sp)
/* 005F5C 7000535C 3C128006 */  lui   $s2, %hi(current_indy_read_buf_resourceID)
/* 005F60 70005360 00808825 */  move  $s1, $a0
/* 005F64 70005364 AFBF0024 */  sw    $ra, 0x24($sp)
/* 005F68 70005368 02608025 */  move  $s0, $s3
/* 005F6C 7000536C 26523664 */  addiu $s2, %lo(current_indy_read_buf_resourceID) # addiu $s2, $s2, 0x3664
.L70005370:
/* 005F70 70005370 0C0014A5 */  jal   indy_file_get_address_subsequent_data
/* 005F74 70005374 02002025 */   move  $a0, $s0
/* 005F78 70005378 8E430000 */  lw    $v1, ($s2)
/* 005F7C 7000537C 0223082B */  sltu  $at, $s1, $v1
/* 005F80 70005380 14200007 */  bnez  $at, .L700053A0
/* 005F84 70005384 00000000 */   nop   
/* 005F88 70005388 14600003 */  bnez  $v1, .L70005398
/* 005F8C 7000538C 02009825 */   move  $s3, $s0
/* 005F90 70005390 10000006 */  b     .L700053AC
/* 005F94 70005394 00001025 */   move  $v0, $zero
.L70005398:
/* 005F98 70005398 1000FFF5 */  b     .L70005370
/* 005F9C 7000539C 00408025 */   move  $s0, $v0
.L700053A0:
/* 005FA0 700053A0 0C0014A5 */  jal   indy_file_get_address_subsequent_data
/* 005FA4 700053A4 02602025 */   move  $a0, $s3
/* 005FA8 700053A8 24020001 */  li    $v0, 1
.L700053AC:
/* 005FAC 700053AC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 005FB0 700053B0 8FB00014 */  lw    $s0, 0x14($sp)
/* 005FB4 700053B4 8FB10018 */  lw    $s1, 0x18($sp)
/* 005FB8 700053B8 8FB2001C */  lw    $s2, 0x1c($sp)
/* 005FBC 700053BC 8FB30020 */  lw    $s3, 0x20($sp)
/* 005FC0 700053C0 03E00008 */  jr    $ra
/* 005FC4 700053C4 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif




/**
 * 5FC8	700053C8
 *     V0= TRUE if valid indy.read.buf.resourceID	[matches 826475BE]
 */
#ifdef NONMATCHING
u32 is_valid_indy_read_buf_resourceID(void)
{
    indy_file_get_address_subsequent_data(0xe00000);
    return ((u32) (current_indy_read_buf_resourceID ^ 0x826475be) < 1U);
}
#else
GLOBAL_ASM(
.text
glabel is_valid_indy_read_buf_resourceID
/* 005FC8 700053C8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 005FCC 700053CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 005FD0 700053D0 0C0014A5 */  jal   indy_file_get_address_subsequent_data
/* 005FD4 700053D4 3C0400E0 */   lui   $a0, 0xe0
/* 005FD8 700053D8 3C028006 */  lui   $v0, %hi(current_indy_read_buf_resourceID)
/* 005FDC 700053DC 8C423664 */  lw    $v0, %lo(current_indy_read_buf_resourceID)($v0)
/* 005FE0 700053E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 005FE4 700053E4 3C018264 */  lui   $at, (0x826475BE >> 16) # lui $at, 0x8264
/* 005FE8 700053E8 342175BE */  ori   $at, (0x826475BE & 0xFFFF) # ori $at, $at, 0x75be
/* 005FEC 700053EC 00417026 */  xor   $t6, $v0, $at
/* 005FF0 700053F0 2DC20001 */  sltiu $v0, $t6, 1
/* 005FF4 700053F4 03E00008 */  jr    $ra
/* 005FF8 700053F8 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif





/**
 * 5FFC	700053FC
 *     unconditional return
 */
void debug_indy_stub(void) {
    return;
}

/**
 * 6004	70005404
 *     unconditional return
 */
void debug_indy_stub_0(void) {
    return;
}

/**
 * 600C	7000540C
 *     unconditional return
 */
void debug_indy_stub_1(void) {
    return;
}

/**
 * 6014	70005414
 *     V0= indy.read.buf.resourceID	[80063664]
 */
u32 * return_indy_read_buf_resourceID(void) {
  return current_indy_read_buf_resourceID;
}

/**
 * 6020	70005420
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 */
#ifdef NONMATCHING
s32 debug_sp_related_11(u32 arg0, u32 arg1)
{
    ? sp1C;
    ? sp8;
    s32 temp_v0;
    void *temp_t8;

    sp1C = (?32) stack_ptrs_1;
    sp1C.unk4 = (?32) stack_ptrs_1.unk4;
    sp1C.unk8 = (?32) stack_ptrs_1.unk8;
    sp1C.unkC = (?32) stack_ptrs_1.unkC;
    sp1C.unk10 = (?32) stack_ptrs_1.unk10;
    sp8 = (?32) stack_ptrs_2;
    sp8.unk4 = (?32) stack_ptrs_2.unk4;
    sp8.unk8 = (?32) stack_ptrs_2.unk8;
    sp8.unkC = (?32) stack_ptrs_2.unkC;
    sp8.unk10 = (?32) stack_ptrs_2.unk10;
    if (arg1 <= 0)
    {
        return 0;
    }
    temp_v0 = (arg1 * 4);
    if (arg1 >= 6U)
    {
        return 0;
    }
    temp_t8 = (&sp8 + temp_v0);
    if (arg0 < 0x80000000U)
    {
        return ((arg0 & 0xf0000000) | (*temp_t8 - *(&sp1C + temp_v0)));
    }
    return *temp_t8;
}
#else
GLOBAL_ASM(
.text
glabel debug_sp_related_11
/* 006020 70005420 3C0E8002 */  lui   $t6, %hi(stack_ptrs_1) 
/* 006024 70005424 25CE36DC */  addiu $t6, %lo(stack_ptrs_1) # addiu $t6, $t6, 0x36dc
/* 006028 70005428 8DC10000 */  lw    $at, ($t6)
/* 00602C 7000542C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 006030 70005430 27A7001C */  addiu $a3, $sp, 0x1c
/* 006034 70005434 ACE10000 */  sw    $at, ($a3)
/* 006038 70005438 8DD90004 */  lw    $t9, 4($t6)
/* 00603C 7000543C 3C098002 */  lui   $t1, %hi(stack_ptrs_2) 
/* 006040 70005440 252936F0 */  addiu $t1, %lo(stack_ptrs_2) # addiu $t1, $t1, 0x36f0
/* 006044 70005444 ACF90004 */  sw    $t9, 4($a3)
/* 006048 70005448 8DC10008 */  lw    $at, 8($t6)
/* 00604C 7000544C 27A80008 */  addiu $t0, $sp, 8
/* 006050 70005450 00803025 */  move  $a2, $a0
/* 006054 70005454 ACE10008 */  sw    $at, 8($a3)
/* 006058 70005458 8DD9000C */  lw    $t9, 0xc($t6)
/* 00605C 7000545C ACF9000C */  sw    $t9, 0xc($a3)
/* 006060 70005460 8DC10010 */  lw    $at, 0x10($t6)
/* 006064 70005464 ACE10010 */  sw    $at, 0x10($a3)
/* 006068 70005468 8D210000 */  lw    $at, ($t1)
/* 00606C 7000546C AD010000 */  sw    $at, ($t0)
/* 006070 70005470 8D2C0004 */  lw    $t4, 4($t1)
/* 006074 70005474 AD0C0004 */  sw    $t4, 4($t0)
/* 006078 70005478 8D210008 */  lw    $at, 8($t1)
/* 00607C 7000547C AD010008 */  sw    $at, 8($t0)
/* 006080 70005480 8D2C000C */  lw    $t4, 0xc($t1)
/* 006084 70005484 AD0C000C */  sw    $t4, 0xc($t0)
/* 006088 70005488 8D210010 */  lw    $at, 0x10($t1)
/* 00608C 7000548C 18A00004 */  blez  $a1, .L700054A0
/* 006090 70005490 AD010010 */   sw    $at, 0x10($t0)
/* 006094 70005494 2CA10006 */  sltiu $at, $a1, 6
/* 006098 70005498 14200003 */  bnez  $at, .L700054A8
/* 00609C 7000549C 00051080 */   sll   $v0, $a1, 2
.L700054A0:
/* 0060A0 700054A0 1000000E */  b     .L700054DC
/* 0060A4 700054A4 00001025 */   move  $v0, $zero
.L700054A8:
/* 0060A8 700054A8 3C018000 */  lui   $at, 0x8000
/* 0060AC 700054AC 00E26821 */  addu  $t5, $a3, $v0
/* 0060B0 700054B0 0102C021 */  addu  $t8, $t0, $v0
/* 0060B4 700054B4 00C1082B */  sltu  $at, $a2, $at
/* 0060B8 700054B8 8DA30000 */  lw    $v1, ($t5)
/* 0060BC 700054BC 14200003 */  bnez  $at, .L700054CC
/* 0060C0 700054C0 8F040000 */   lw    $a0, ($t8)
/* 0060C4 700054C4 10000005 */  b     .L700054DC
/* 0060C8 700054C8 00801025 */   move  $v0, $a0
.L700054CC:
/* 0060CC 700054CC 3C01F000 */  lui   $at, 0xf000
/* 0060D0 700054D0 00C17824 */  and   $t7, $a2, $at
/* 0060D4 700054D4 00837023 */  subu  $t6, $a0, $v1
/* 0060D8 700054D8 01EE1025 */  or    $v0, $t7, $t6
.L700054DC:
/* 0060DC 700054DC 03E00008 */  jr    $ra
/* 0060E0 700054E0 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





/**
 * 60E4	700054E4
 *     V0=hardcoded SP for debug thread A1, corrected for address range A0
 *     accepts: A0=p->address space, A1=entry#
 */
#ifdef NONMATCHING
s32 debug_sp_related_12(u32 arg0, u32 arg1) {
    u32 sp4;

    // Node 0
    sp4 = (?32) stack_ptrs_3;
    sp4.unk4 = (?32) stack_ptrs_3.unk4;
    sp4.unk8 = (?32) stack_ptrs_3.unk8;
    sp4.unkC = (?32) stack_ptrs_3.unkC;
    sp4.unk10 = (?32) stack_ptrs_3.unk10;
    if (arg1 <= 0)
    {
        // Node 2
        return;
        // (possible return value: 0)
    }
    // Node 1
    if (arg1 >= 6U)
    {
        // Node 2
        return;
        // (possible return value: 0)
    }
    // Node 3
    if (arg0 >= 0x80000000U)
    {
        // Node 4
        return;
        // (possible return value: *(&sp4 + (arg1 * 4)))
    }
    // Node 5
    return;
    // (possible return value: (arg0 & 0xf0000000))
}
#else
GLOBAL_ASM(
.text
glabel debug_sp_related_12
/* 0060E4 700054E4 3C0E8002 */  lui   $t6, %hi(stack_ptrs_3) 
/* 0060E8 700054E8 25CE3704 */  addiu $t6, %lo(stack_ptrs_3) # addiu $t6, $t6, 0x3704
/* 0060EC 700054EC 8DC10000 */  lw    $at, ($t6)
/* 0060F0 700054F0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0060F4 700054F4 27A20004 */  addiu $v0, $sp, 4
/* 0060F8 700054F8 AC410000 */  sw    $at, ($v0)
/* 0060FC 700054FC 8DD90004 */  lw    $t9, 4($t6)
/* 006100 70005500 AC590004 */  sw    $t9, 4($v0)
/* 006104 70005504 8DC10008 */  lw    $at, 8($t6)
/* 006108 70005508 AC410008 */  sw    $at, 8($v0)
/* 00610C 7000550C 8DD9000C */  lw    $t9, 0xc($t6)
/* 006110 70005510 AC59000C */  sw    $t9, 0xc($v0)
/* 006114 70005514 8DC10010 */  lw    $at, 0x10($t6)
/* 006118 70005518 18A00004 */  blez  $a1, .L7000552C
/* 00611C 7000551C AC410010 */   sw    $at, 0x10($v0)
/* 006120 70005520 2CA10006 */  sltiu $at, $a1, 6
/* 006124 70005524 14200003 */  bnez  $at, .L70005534
/* 006128 70005528 00054080 */   sll   $t0, $a1, 2
.L7000552C:
/* 00612C 7000552C 1000000A */  b     .L70005558
/* 006130 70005530 00001025 */   move  $v0, $zero
.L70005534:
/* 006134 70005534 3C018000 */  lui   $at, 0x8000
/* 006138 70005538 00484821 */  addu  $t1, $v0, $t0
/* 00613C 7000553C 0081082B */  sltu  $at, $a0, $at
/* 006140 70005540 14200003 */  bnez  $at, .L70005550
/* 006144 70005544 8D230000 */   lw    $v1, ($t1)
/* 006148 70005548 10000003 */  b     .L70005558
/* 00614C 7000554C 00601025 */   move  $v0, $v1
.L70005550:
/* 006150 70005550 3C01F000 */  lui   $at, 0xf000
/* 006154 70005554 00811024 */  and   $v0, $a0, $at
.L70005558:
/* 006158 70005558 03E00008 */  jr    $ra
/* 00615C 7000555C 27BD0018 */   addiu $sp, $sp, 0x18
)
#endif


//maybe newfile, falls on 0 address and logically does different things

/**
 * 6160	70005560
 *     V0= TRUE if F12 a normal single precision float
 *     accepts: F12= single-precision float
 */
#ifdef NONMATCHING
s32 _is_normal_single_precision_float(f32 arg0) {
    // Node 0
    if ((u32) (arg0 & 0x7fffff) >= 1U)
    {
        // Node 1
        if (0U < (u32) ((arg0 >> 0x17) & 0xff))
        {
            // Node 2
            return;
            // (possible return value: (0U < (u32) (((arg0 >> 0x17) & 0xff) ^ 0xff)))
        }
    }
    // (possible return value: ((u32) (arg0 & 0x7fffff) < 1U))
}
#else
GLOBAL_ASM(
.text
glabel _is_normal_single_precision_float
/* 006160 70005560 E7AC0000 */  swc1  $f12, ($sp)
/* 006164 70005564 8FA40000 */  lw    $a0, ($sp)
/* 006168 70005568 3C01007F */  lui   $at, (0x007FFFFF >> 16) # lui $at, 0x7f
/* 00616C 7000556C 3421FFFF */  ori   $at, (0x007FFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 006170 70005570 00811024 */  and   $v0, $a0, $at
/* 006174 70005574 2C4E0001 */  sltiu $t6, $v0, 1
/* 006178 70005578 15C00008 */  bnez  $t6, .L7000559C
/* 00617C 7000557C 01C01025 */   move  $v0, $t6
/* 006180 70005580 00041DC2 */  srl   $v1, $a0, 0x17
/* 006184 70005584 306F00FF */  andi  $t7, $v1, 0xff
/* 006188 70005588 000F102B */  sltu  $v0, $zero, $t7
/* 00618C 7000558C 10400003 */  beqz  $v0, .L7000559C
/* 006190 70005590 00000000 */   nop   
/* 006194 70005594 39E200FF */  xori  $v0, $t7, 0xff
/* 006198 70005598 0002102B */  sltu  $v0, $zero, $v0
.L7000559C:
/* 00619C 7000559C 03E00008 */  jr    $ra
/* 0061A0 700055A0 00000000 */   nop   
)
#endif




/**
 * 61A4	700055A4
 *     V0= TRUE if A1 a normal single precision float; would have set result as short at A0
 *     accepts: A0=(unused) p->target, A1=single-precision float
 */
#ifdef NONMATCHING
void is_normal_single_precision_float(s32 arg0, s32 arg1) {
    _is_normal_single_precision_float(arg1);
}
#else
GLOBAL_ASM(
.text
glabel is_normal_single_precision_float
/* 0061A4 700055A4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0061A8 700055A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0061AC 700055AC 44856000 */  mtc1  $a1, $f12
/* 0061B0 700055B0 0C001558 */  jal   _is_normal_single_precision_float
/* 0061B4 700055B4 AFA40018 */   sw    $a0, 0x18($sp)
/* 0061B8 700055B8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0061BC 700055BC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0061C0 700055C0 03E00008 */  jr    $ra
/* 0061C4 700055C4 00000000 */   nop   
)
#endif





/**
 * 61C8	700055C8
 *     removed: set normality of single-precision floats A1, A2, A3, SP+10 in table at A0
 */
#ifdef NONMATCHING
void set_normality_of_single_precision_floats(s32 arg0, s32 arg1, ? arg2, ? arg3, s32 arg6, ? arg8, ? arg9, ? argA) {
    // Node 0
    is_normal_single_precision_float(arg1, arg1);
    is_normal_single_precision_float((arg6 + 2), arg8);
    is_normal_single_precision_float((arg6 + 4), arg9);
    is_normal_single_precision_float((arg6 + 6), argA);
    return;
    // (possible return value: is_normal_single_precision_float((arg6 + 6), argA))
}
#else
GLOBAL_ASM(
.text
glabel set_normality_of_single_precision_floats
/* 0061C8 700055C8 44856000 */  mtc1  $a1, $f12
/* 0061CC 700055CC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0061D0 700055D0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0061D4 700055D4 44056000 */  mfc1  $a1, $f12
/* 0061D8 700055D8 AFA40018 */  sw    $a0, 0x18($sp)
/* 0061DC 700055DC AFA60020 */  sw    $a2, 0x20($sp)
/* 0061E0 700055E0 0C001569 */  jal   is_normal_single_precision_float
/* 0061E4 700055E4 AFA70024 */   sw    $a3, 0x24($sp)
/* 0061E8 700055E8 8FA40018 */  lw    $a0, 0x18($sp)
/* 0061EC 700055EC 8FA50020 */  lw    $a1, 0x20($sp)
/* 0061F0 700055F0 0C001569 */  jal   is_normal_single_precision_float
/* 0061F4 700055F4 24840002 */   addiu $a0, $a0, 2
/* 0061F8 700055F8 8FA40018 */  lw    $a0, 0x18($sp)
/* 0061FC 700055FC 8FA50024 */  lw    $a1, 0x24($sp)
/* 006200 70005600 0C001569 */  jal   is_normal_single_precision_float
/* 006204 70005604 24840004 */   addiu $a0, $a0, 4
/* 006208 70005608 8FA40018 */  lw    $a0, 0x18($sp)
/* 00620C 7000560C 8FA50028 */  lw    $a1, 0x28($sp)
/* 006210 70005610 0C001569 */  jal   is_normal_single_precision_float
/* 006214 70005614 24840006 */   addiu $a0, $a0, 6
/* 006218 70005618 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00621C 7000561C 27BD0018 */  addiu $sp, $sp, 0x18
/* 006220 70005620 03E00008 */  jr    $ra
/* 006224 70005624 00000000 */   nop   
)
#endif

/**
 * 6228	70005628
 *     unconditional return
 */
void debug_indy_stub_2(void) {
    return;
}


