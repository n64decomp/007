#include "ultra64.h"
#include "bondgame.h"
#include "game/cheat_buttons.h"
//#include "game/chraicommands.h" /* needed for ai list commands, remove when moving global ai lists to chraicommands/chrai */
// bss
char off_CODE_bss_80079E30[0x4C];



//D:8003F430
u32 dword_D_8003F430[] = {0x320028, 0x2300120, 0x4100032, 0x280130, 0x340420};
//D:8003F444
u32 dword_D_8003F444[] = {0x4200011, 0x180120, 0x240018, 0x1200410, 0x2200031};
//D:8003F458
u32 dword_D_8003F458[] = {0x4300022, 0x210032, 0x4200024, 0x120031, 0x8100022};
//D:8003F46C
u32 dword_D_8003F46C[] = {0x310810, 0x4100410, 0x310230, 0x4100810, 0x310210};
//D:8003F480
u32 dword_D_8003F480[] = {0x8200011, 0x140032, 0x2300130, 0x4100018, 0x110430};
//D:8003F494
u32 dword_D_8003F494[] = {0x1100220, 0x2200810, 0x4200014, 0x220031, 0x4200028};
//D:8003F4A8
u32 dword_D_8003F4A8[] = {0x140430, 0x1200018, 0x310810, 0x4200120, 0x120018};
//D:8003F4BC
u32 dword_D_8003F4BC[] = {0x120038, 0x2300830, 0x8100022, 0x180024, 0x2300110};
//D:8003F4D0
u32 dword_D_8003F4D0[] = {0x280032, 0x8100021, 0x120120, 0x320021, 0x8200034};
//D:8003F4E4
u32 dword_D_8003F4E4[] = {0x380210, 0x140024, 0x8100420, 0x110120, 0x1300014};
//D:8003F4F8
u32 dword_D_8003F4F8[] = {0x380012, 0x2200018, 0x2200014, 0x210110, 0x380120};
//D:8003F50C
u32 dword_D_8003F50C[] = {0x2300210, 0x280220, 0x180014, 0x110110, 0x4200012};
//D:8003F520
u32 dword_D_8003F520[] = {0x120038, 0x2200810, 0x2100820, 0x140120, 0x210430};
//D:8003F534
u32 dword_D_8003F534[] = {0x240110, 0x210012, 0x240230, 0x210830, 0x110820};
//D:8003F548
u32 dword_D_8003F548[] = {0x8200014, 0x2200410, 0x220031, 0x280110, 0x1100011};
//D:8003F55C
u32 dword_D_8003F55C[] = {0x180420, 0x110220, 0x8300034, 0x110810, 0x340810};
//D:8003F570
u32 dword_D_8003F570[] = {0x240031, 0x110018, 0x120120, 0x380028, 0x4300021};
//D:8003F584
u32 dword_D_8003F584[] = {0x4200410, 0x380220, 0x1300022, 0x1100028, 0x2200024};
//D:8003F598
u32 dword_D_8003F598[] = {0x340034, 0x1200230, 0x2100011, 0x2300018, 0x140110};
//D:8003F5AC
u32 dword_D_8003F5AC[] = {0x2100830, 0x340210, 0x310220, 0x1300034, 0x8200014};
//D:8003F5C0
u32 dword_D_8003F5C0[] = {0x320021, 0x8200034, 0x110014, 0x2100014, 0x180420};
//D:8003F5D4
u32 dword_D_8003F5D4[] = {0x4200420, 0x140021, 0x1300012, 0x4200022, 0x210820};
//D:8003F5E8
u32 dword_D_8003F5E8[] = {0x2100014, 0x110230, 0x1200014, 0x2200032, 0x8200028};
//D:8003F5FC
u32 dword_D_8003F5FC[] = {0x140210, 0x8300110, 0x4100410, 0x8100012, 0x180230};
//D:8003F610
u32 dword_D_8003F610[] = {0x240410, 0x1200011, 0x140210, 0x2100018, 0x2100038};
//D:8003F624
u32 dword_D_8003F624[] = {0x4200014, 0x8300120, 0x180012, 0x8100022, 0x8200012};
//D:8003F638
u32 dword_D_8003F638[] = {0x380220, 0x4100420, 0x280420, 0x1100018, 0x220110};
//D:8003F64C
u32 dword_D_8003F64C[] = {0x140210, 0x1200031, 0x4200038, 0x2200038, 0x1300022};
//D:8003F660
u32 dword_D_8003F660[] = {0x8300031, 0x4200110, 0x8100420, 0x2200021, 0x310220, 0x80304030, 0x80304030};
//D:8003F67C
u32 dword_D_8003F67C[] = {0x8200008, 0x1100032, 0x8200014, 0x240034, 0x8300024};
//D:8003F690
u32 dword_D_8003F690[] = {0x2100420, 0x2000800, 0x4000012, 0x220230, 0x1300022};
//D:8003F6A4
u32 dword_D_8003F6A4[] = {0x8300001, 0x2100810, 0x8000110, 0x8000034, 0x4300032};
//D:8003F6B8
u32 dword_D_8003F6B8[] = {0x4100810, 0x1000034, 0x1200210, 0x2000400, 0x8000014};
//D:8003F6CC
u32 dword_D_8003F6CC[] = {0x1100820, 0x4000400, 0x140220, 0x220810, 0x4100012};
//D:8003F6E0
u32 dword_D_8003F6E0[] = {0x4200024, 0x8300014, 0x2000410, 0x240800, 0x4100120};
//D:8003F6F4
u32 dword_D_8003F6F4[] = {0x8100004, 0x20008, 0x4200810, 0x20100, 0x2100110};
//D:8003F708
u32 dword_D_8003F708[] = {0x4300410, 0x240200, 0x120034, 0x1000400, 0x140110};
//D:8003F71C
u32 dword_D_8003F71C[] = {0x120220, 0x8000130, 0x1000032, 0x320410, 0x2100012};
//D:8003F730
u32 dword_D_8003F730[] = {0x240022, 0x40001, 0x20130, 0x10830, 0x120220};
//D:8003F744
u32 dword_D_8003F744[] = {0x320034, 0x220012, 0x1100230, 0x1200200, 0x320420};
//D:8003F758
u32 dword_D_8003F758[] = {0x340002, 0x140004, 0x40034, 0x8300004, 0x8100820};
//D:8003F76C
u32 dword_D_8003F76C[] = {0x2300230, 0x4300230, 0x10430, 0x4300420, 0x20008};
//D:8003F780
u32 dword_D_8003F780[] = {0x2200830, 0x1200830, 0x320230, 0x4300004, 0x1300230};
//D:8003F794
u32 dword_D_8003F794[] = {0x140120, 0x120110, 0x1300830, 0x4200210, 0x1200022};
//D:8003F7A8
u32 dword_D_8003F7A8[] = {0x220130, 0x10002, 0x2100024, 0x2300034, 0x8200001};
//D:8003F7BC
u32 dword_D_8003F7BC[] = {0x8000100, 0x2200410, 0x8200022, 0x2200001, 0x80430};
//D:8003F7D0
u32 dword_D_8003F7D0[] = {0x1300430, 0x8200430, 0x80810, 0x1300220, 0x4000024};
//D:8003F7E4
u32 dword_D_8003F7E4[] = {0x1200032, 0x4200210, 0x4100120, 0x80100, 0x1100830};
//D:8003F7F8
u32 dword_D_8003F7F8[] = {0x4000200, 0x80100, 0x4200220};

//D:8003F804
u32 D_8003F804 = 0x8200002;
//D:8003F808
u32 D_8003F808 = 0x2000004;

//D:8003F80C
struct struct_15 D_8003F80C[] = {
    {1, 0xA, 0, 0, dword_D_8003F430, 0, 0x31},
    {2, 0xA, 0, 0, dword_D_8003F444, 0xB0000000, 6},
    {3, 0xA, 0, 0, dword_D_8003F458, 0xB0010000, 2},
    {4, 0xA, 0, 0, dword_D_8003F46C, 0, 0x16},
    {5, 0xA, 0, 0, dword_D_8003F480, 0, 0x16},
    {6, 0xA, 0, 0, dword_D_8003F494, 0, 0x34},
    {7, 0xA, 0, 0, dword_D_8003F4A8, 0xB0370000, 0x66},
    {8, 0, 0, 0, 0, 0, 0x16},
    {9, 0, 0, 0, 0, 0, 0x16},
    {0xA, 0xA, 0, 0, dword_D_8003F4BC, 0xB0040000, 0x62},
    {0xB, 0, 0, 0, 0, 0xB0060000, 0x66},
    {0xC, 0, 0, 0, 0, 0xB0070000, 0x26},
    {0xD, 0, 0, 0, 0, 0, 0x12},
    {0xE, 0, 0, 0, 0, 0xB0080000, 2},
    {0xF, 0, 0, 0, 0, 0xB0380000, 0x66},
    {0x10, 0, 0, 0, 0, 0, 0x16},
    {0x11, 0, 0, 0, 0, 0xB00A0000, 0x12},
    {0x12, 0, 0, 0, 0, 0xB00B0000, 0x12},
    {0x13, 0, 0, 0, 0, 0xB00C0000, 0x12},
    {0x14, 0, 0, 0, 0, 0xB00D0000, 0x12},
    {0x15, 0, 0, 0, 0, 0xB00E0000, 0x12},
    {0x16, 0xA, 0, 0, dword_D_8003F4D0, 0, 4},
    {0x17, 0, 0, 0, 0, 0xB0430000, 0x64},
    {0x18, 0, 0, 0, 0, 0xB0400000, 0x66},
    {0x19, 0, 0, 0, 0, 0, 0x20},
    {0x1A, 0, 0, 0, 0, 0xB0410000, 0x72},
    {0x1B, 0, 0, 0, 0, 0xB0420000, 0x72},
    {0x1C, 0, 0, 0, 0, 0xB0390000, 1},
    {0x1D, 0, 0, 0, 0, 0xB03A0000, 0x12},
    {0x1E, 0, 0, 0, 0, 0xB03B0000, 0x12},
    {0x1F, 0, 0, 0, 0, 0xB03C0000, 0x12},
    {0x20, 0, 0, 0, 0, 0xB03D0000, 0x12},
    {0x21, 0, 0, 0, 0, 0xB03E0000, 0x12},
    {0x22, 0, 0, 0, 0, 0xB03F0000, 0x12},
    {0x23, 0xA, 0, 0, dword_D_8003F67C, 0, 0x11},
    {0x24, 0xA, 0, 0, dword_D_8003F690, 0, 0x11},
    {0x25, 0xA, 0, 0, dword_D_8003F6A4, 0, 0x11},
    {0x26, 0xA, 0, 0, dword_D_8003F6B8, 0, 0x11},
    {0x27, 0xA, 0, 0, dword_D_8003F6CC, 0, 0x11},
    {0x28, 0xA, 0, 0, dword_D_8003F6E0, 0, 0x11},
    {0x29, 0xA, 0, 0, dword_D_8003F6F4, 0, 0x11},
    {0x2A, 0xA, 0, 0, dword_D_8003F708, 0, 0x11},
    {0x2B, 0xA, 0, 0, dword_D_8003F71C, 0, 0x11},
    {0x2C, 0xA, 0, 0, dword_D_8003F730, 0, 0x11},
    {0x2D, 0xA, 0, 0, dword_D_8003F744, 0, 0x11},
    {0x2E, 0xA, 0, 0, dword_D_8003F758, 0, 0x11},
    {0x2F, 0xA, 0, 0, dword_D_8003F76C, 0, 0x11},
    {0x30, 0xA, 0, 0, dword_D_8003F780, 0, 0x11},
    {0x31, 0xA, 0, 0, dword_D_8003F794, 0, 0x11},
    {0x32, 0xA, 0, 0, dword_D_8003F7A8, 0, 0x11},
    {0x33, 0xA, 0, 0, dword_D_8003F7BC, 0, 0x11},
    {0x34, 0xA, 0, 0, dword_D_8003F7D0, 0, 0x11},
    {0x35, 0xA, 0, 0, dword_D_8003F7E4, 0, 0x11},
    {0x36, 0xA, 0, 0, dword_D_8003F7F8, 0, 0x11},
    {0x37, 0xA, 0, 0, dword_D_8003F4E4, 0, 0x11},
    {0x38, 0xA, 0, 0, dword_D_8003F4F8, 0, 0x11},
    {0x39, 0xA, 0, 0, dword_D_8003F50C, 0, 0x11},
    {0x3A, 0xA, 0, 0, dword_D_8003F520, 0, 0x11},
    {0x3B, 0xA, 0, 0, dword_D_8003F534, 0, 0x11},
    {0x3C, 0xA, 0, 0, dword_D_8003F548, 0, 0x11},
    {0x3D, 0xA, 0, 0, dword_D_8003F55C, 0, 0x11},
    {0x3E, 0xA, 0, 0, dword_D_8003F570, 0, 0x11},
    {0x3F, 0xA, 0, 0, dword_D_8003F584, 0, 0x11},
    {0x40, 0xA, 0, 0, dword_D_8003F598, 0, 0x11},
    {0x41, 0xA, 0, 0, dword_D_8003F5AC, 0, 0x11},
    {0x42, 0xA, 0, 0, dword_D_8003F5C0, 0, 0x11},
    {0x43, 0xA, 0, 0, dword_D_8003F5D4, 0, 0x11},
    {0x44, 0xA, 0, 0, dword_D_8003F5E8, 0, 0x11},
    {0x45, 0xA, 0, 0, dword_D_8003F5FC, 0, 0x11},
    {0x46, 0xA, 0, 0, dword_D_8003F610, 0, 0x11},
    {0x47, 0xA, 0, 0, dword_D_8003F624, 0, 0x11},
    {0x48, 0xA, 0, 0, dword_D_8003F638, 0, 0x11},
    {0x49, 0xA, 0, 0, dword_D_8003F64C, 0, 0x11},
    {0x4A, 0xA, 0, 0, dword_D_8003F660, 0, 0x11},
    {0}
};

//D:8003FCBC
//u32 D_8003FCBC = 0;




// rodata







#ifdef NONMATCHING
int cheatButton_7F091740(u16 param_1) {

}
#else
GLOBAL_ASM(
.text
glabel cheatButton_7F091740
/* 0C6270 7F091740 AFA40000 */  sw    $a0, ($sp)
/* 0C6274 7F091744 308EFFFF */  andi  $t6, $a0, 0xffff
/* 0C6278 7F091748 01C02025 */  move  $a0, $t6
/* 0C627C 7F09174C 11C00009 */  beqz  $t6, .L7F091774
/* 0C6280 7F091750 00001825 */   move  $v1, $zero
.L7F091754:
/* 0C6284 7F091754 308F0001 */  andi  $t7, $a0, 1
/* 0C6288 7F091758 11E00002 */  beqz  $t7, .L7F091764
/* 0C628C 7F09175C 00801025 */   move  $v0, $a0
/* 0C6290 7F091760 24630001 */  addiu $v1, $v1, 1
.L7F091764:
/* 0C6294 7F091764 00022042 */  srl   $a0, $v0, 1
/* 0C6298 7F091768 3098FFFF */  andi  $t8, $a0, 0xffff
/* 0C629C 7F09176C 1700FFF9 */  bnez  $t8, .L7F091754
/* 0C62A0 7F091770 03002025 */   move  $a0, $t8
.L7F091774:
/* 0C62A4 7F091774 03E00008 */  jr    $ra
/* 0C62A8 7F091778 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void cheatButton_7F09177C(void) {

}
#else
GLOBAL_ASM(
.text
glabel cheatButton_7F09177C
/* 0C62AC 7F09177C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C62B0 7F091780 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C62B4 7F091784 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C62B8 7F091788 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C62BC 7F09178C 3C118004 */  lui   $s1, %hi(D_8003F80C)
/* 0C62C0 7F091790 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C62C4 7F091794 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C62C8 7F091798 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C62CC 7F09179C 2631F80C */  addiu $s1, %lo(D_8003F80C) # addiu $s1, $s1, -0x7f4
/* 0C62D0 7F0917A0 0FC2F7C1 */  jal   sub_GAME_7F0BDF04
/* 0C62D4 7F0917A4 0000A025 */   move  $s4, $zero
/* 0C62D8 7F0917A8 2401005A */  li    $at, 90
/* 0C62DC 7F0917AC 14410003 */  bne   $v0, $at, .L7F0917BC
/* 0C62E0 7F0917B0 00000000 */   nop   
/* 0C62E4 7F0917B4 10000008 */  b     .L7F0917D8
/* 0C62E8 7F0917B8 24130001 */   li    $s3, 1
.L7F0917BC:
/* 0C62EC 7F0917BC 0FC26919 */  jal   getPlayerCount
/* 0C62F0 7F0917C0 00000000 */   nop   
/* 0C62F4 7F0917C4 24010001 */  li    $at, 1
/* 0C62F8 7F0917C8 14410003 */  bne   $v0, $at, .L7F0917D8
/* 0C62FC 7F0917CC 24130004 */   li    $s3, 4
/* 0C6300 7F0917D0 10000001 */  b     .L7F0917D8
/* 0C6304 7F0917D4 24130002 */   li    $s3, 2
.L7F0917D8:
/* 0C6308 7F0917D8 3C0E8004 */  lui   $t6, %hi(D_8003F80C) 
/* 0C630C 7F0917DC 91CEF80C */  lbu   $t6, %lo(D_8003F80C)($t6)
/* 0C6310 7F0917E0 3C128008 */  lui   $s2, %hi(pPlayer)
/* 0C6314 7F0917E4 2652A0B0 */  addiu $s2, %lo(pPlayer) # addiu $s2, $s2, -0x5f50
/* 0C6318 7F0917E8 11C0004C */  beqz  $t6, .L7F09191C
/* 0C631C 7F0917EC 24100014 */   li    $s0, 20
/* 0C6320 7F0917F0 92250001 */  lbu   $a1, 1($s1)
.L7F0917F4:
/* 0C6324 7F0917F4 58A00044 */  blezl $a1, .L7F091908
/* 0C6328 7F0917F8 92280010 */   lbu   $t0, 0x10($s1)
/* 0C632C 7F0917FC 8E460000 */  lw    $a2, ($s2)
/* 0C6330 7F091800 90CF12B5 */  lbu   $t7, 0x12b5($a2)
/* 0C6334 7F091804 01E5082A */  slt   $at, $t7, $a1
/* 0C6338 7F091808 5420003F */  bnezl $at, .L7F091908
/* 0C633C 7F09180C 92280010 */   lbu   $t0, 0x10($s1)
/* 0C6340 7F091810 8E38000C */  lw    $t8, 0xc($s1)
/* 0C6344 7F091814 0313C824 */  and   $t9, $t8, $s3
/* 0C6348 7F091818 5320003B */  beql  $t9, $zero, .L7F091908
/* 0C634C 7F09181C 92280010 */   lbu   $t0, 0x10($s1)
/* 0C6350 7F091820 90C812B4 */  lbu   $t0, 0x12b4($a2)
/* 0C6354 7F091824 00002025 */  move  $a0, $zero
/* 0C6358 7F091828 01054823 */  subu  $t1, $t0, $a1
/* 0C635C 7F09182C 252A0014 */  addiu $t2, $t1, 0x14
/* 0C6360 7F091830 0150001A */  div   $zero, $t2, $s0
/* 0C6364 7F091834 00001010 */  mfhi  $v0
/* 0C6368 7F091838 16000002 */  bnez  $s0, .L7F091844
/* 0C636C 7F09183C 00000000 */   nop   
/* 0C6370 7F091840 0007000D */  break 7
.L7F091844:
/* 0C6374 7F091844 2401FFFF */  li    $at, -1
/* 0C6378 7F091848 16010004 */  bne   $s0, $at, .L7F09185C
/* 0C637C 7F09184C 3C018000 */   lui   $at, 0x8000
/* 0C6380 7F091850 15410002 */  bne   $t2, $at, .L7F09185C
/* 0C6384 7F091854 00000000 */   nop   
/* 0C6388 7F091858 0006000D */  break 6
.L7F09185C:
/* 0C638C 7F09185C 18A00018 */  blez  $a1, .L7F0918C0
/* 0C6390 7F091860 00000000 */   nop   
/* 0C6394 7F091864 8E230004 */  lw    $v1, 4($s1)
.L7F091868:
/* 0C6398 7F091868 00025840 */  sll   $t3, $v0, 1
/* 0C639C 7F09186C 00CB6021 */  addu  $t4, $a2, $t3
/* 0C63A0 7F091870 958D128C */  lhu   $t5, 0x128c($t4)
/* 0C63A4 7F091874 946E0000 */  lhu   $t6, ($v1)
/* 0C63A8 7F091878 244F0001 */  addiu $t7, $v0, 1
/* 0C63AC 7F09187C 15AE0010 */  bne   $t5, $t6, .L7F0918C0
/* 0C63B0 7F091880 00000000 */   nop   
/* 0C63B4 7F091884 01F0001A */  div   $zero, $t7, $s0
/* 0C63B8 7F091888 16000002 */  bnez  $s0, .L7F091894
/* 0C63BC 7F09188C 00000000 */   nop   
/* 0C63C0 7F091890 0007000D */  break 7
.L7F091894:
/* 0C63C4 7F091894 2401FFFF */  li    $at, -1
/* 0C63C8 7F091898 16010004 */  bne   $s0, $at, .L7F0918AC
/* 0C63CC 7F09189C 3C018000 */   lui   $at, 0x8000
/* 0C63D0 7F0918A0 15E10002 */  bne   $t7, $at, .L7F0918AC
/* 0C63D4 7F0918A4 00000000 */   nop   
/* 0C63D8 7F0918A8 0006000D */  break 6
.L7F0918AC:
/* 0C63DC 7F0918AC 24840001 */  addiu $a0, $a0, 1
/* 0C63E0 7F0918B0 00001010 */  mfhi  $v0
/* 0C63E4 7F0918B4 0085082A */  slt   $at, $a0, $a1
/* 0C63E8 7F0918B8 1420FFEB */  bnez  $at, .L7F091868
/* 0C63EC 7F0918BC 24630002 */   addiu $v1, $v1, 2
.L7F0918C0:
/* 0C63F0 7F0918C0 54850011 */  bnel  $a0, $a1, .L7F091908
/* 0C63F4 7F0918C4 92280010 */   lbu   $t0, 0x10($s1)
/* 0C63F8 7F0918C8 A0C012B5 */  sb    $zero, 0x12b5($a2)
/* 0C63FC 7F0918CC 0FC249EF */  jal   cheatCheckIfOn
/* 0C6400 7F0918D0 92240000 */   lbu   $a0, ($s1)
/* 0C6404 7F0918D4 10400005 */  beqz  $v0, .L7F0918EC
/* 0C6408 7F0918D8 00000000 */   nop   
/* 0C640C 7F0918DC 8E38000C */  lw    $t8, 0xc($s1)
/* 0C6410 7F0918E0 33190010 */  andi  $t9, $t8, 0x10
/* 0C6414 7F0918E4 13200005 */  beqz  $t9, .L7F0918FC
/* 0C6418 7F0918E8 00000000 */   nop   
.L7F0918EC:
/* 0C641C 7F0918EC 0FC246D9 */  jal   handle_cheats_turned_on
/* 0C6420 7F0918F0 92240000 */   lbu   $a0, ($s1)
/* 0C6424 7F0918F4 10000004 */  b     .L7F091908
/* 0C6428 7F0918F8 92280010 */   lbu   $t0, 0x10($s1)
.L7F0918FC:
/* 0C642C 7F0918FC 0FC2490E */  jal   cheatDisplayMessageActivateCheat
/* 0C6430 7F091900 92240000 */   lbu   $a0, ($s1)
/* 0C6434 7F091904 92280010 */  lbu   $t0, 0x10($s1)
.L7F091908:
/* 0C6438 7F091908 26310010 */  addiu $s1, $s1, 0x10
/* 0C643C 7F09190C 51000004 */  beql  $t0, $zero, .L7F091920
/* 0C6440 7F091910 8FBF002C */   lw    $ra, 0x2c($sp)
/* 0C6444 7F091914 5280FFB7 */  beql  $s4, $zero, .L7F0917F4
/* 0C6448 7F091918 92250001 */   lbu   $a1, 1($s1)
.L7F09191C:
/* 0C644C 7F09191C 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F091920:
/* 0C6450 7F091920 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C6454 7F091924 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C6458 7F091928 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C645C 7F09192C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C6460 7F091930 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C6464 7F091934 03E00008 */  jr    $ra
/* 0C6468 7F091938 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void cheat_buttons_mp_related(void)

}
#else
GLOBAL_ASM(
.text
glabel cheat_buttons_mp_related
/* 0C646C 7F09193C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C6470 7F091940 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6474 7F091944 0FC26C54 */  jal   get_cur_playernum
/* 0C6478 7F091948 00000000 */   nop   
/* 0C647C 7F09194C 00022600 */  sll   $a0, $v0, 0x18
/* 0C6480 7F091950 00047603 */  sra   $t6, $a0, 0x18
/* 0C6484 7F091954 01C02025 */  move  $a0, $t6
/* 0C6488 7F091958 0C0030C3 */  jal   get_controller_buttons_held
/* 0C648C 7F09195C 3405FFFF */   li    $a1, 65535
/* 0C6490 7F091960 0FC26C54 */  jal   get_cur_playernum
/* 0C6494 7F091964 A7A20026 */   sh    $v0, 0x26($sp)
/* 0C6498 7F091968 00022600 */  sll   $a0, $v0, 0x18
/* 0C649C 7F09196C 00047E03 */  sra   $t7, $a0, 0x18
/* 0C64A0 7F091970 01E02025 */  move  $a0, $t7
/* 0C64A4 7F091974 0C0030EB */  jal   get_controller_buttons_pressed
/* 0C64A8 7F091978 3405FFFF */   li    $a1, 65535
/* 0C64AC 7F09197C 97A30026 */  lhu   $v1, 0x26($sp)
/* 0C64B0 7F091980 30780030 */  andi  $t8, $v1, 0x30
/* 0C64B4 7F091984 3306FFFF */  andi  $a2, $t8, 0xffff
/* 0C64B8 7F091988 00C04827 */  not   $t1, $a2
/* 0C64BC 7F09198C 0300C827 */  not   $t9, $t8
/* 0C64C0 7F091990 00492824 */  and   $a1, $v0, $t1
/* 0C64C4 7F091994 30AAFFFF */  andi  $t2, $a1, 0xffff
/* 0C64C8 7F091998 00794024 */  and   $t0, $v1, $t9
/* 0C64CC 7F09199C A7A80026 */  sh    $t0, 0x26($sp)
/* 0C64D0 7F0919A0 11400028 */  beqz  $t2, .L7F091A44
/* 0C64D4 7F0919A4 A7A50024 */   sh    $a1, 0x24($sp)
/* 0C64D8 7F0919A8 30A4FFFF */  andi  $a0, $a1, 0xffff
/* 0C64DC 7F0919AC 0FC245D0 */  jal   cheatButton_7F091740
/* 0C64E0 7F0919B0 AFA60018 */   sw    $a2, 0x18($sp)
/* 0C64E4 7F0919B4 24010001 */  li    $at, 1
/* 0C64E8 7F0919B8 1441001E */  bne   $v0, $at, .L7F091A34
/* 0C64EC 7F0919BC 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C64F0 7F0919C0 97A40026 */  lhu   $a0, 0x26($sp)
/* 0C64F4 7F0919C4 0FC245D0 */  jal   cheatButton_7F091740
/* 0C64F8 7F0919C8 AFA70018 */   sw    $a3, 0x18($sp)
/* 0C64FC 7F0919CC 24010001 */  li    $at, 1
/* 0C6500 7F0919D0 14410018 */  bne   $v0, $at, .L7F091A34
/* 0C6504 7F0919D4 8FA70018 */   lw    $a3, 0x18($sp)
/* 0C6508 7F0919D8 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C650C 7F0919DC 2484A0B0 */  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
/* 0C6510 7F0919E0 8C820000 */  lw    $v0, ($a0)
/* 0C6514 7F0919E4 97AB0024 */  lhu   $t3, 0x24($sp)
/* 0C6518 7F0919E8 24010014 */  li    $at, 20
/* 0C651C 7F0919EC 904D12B4 */  lbu   $t5, 0x12b4($v0)
/* 0C6520 7F0919F0 01676025 */  or    $t4, $t3, $a3
/* 0C6524 7F0919F4 000D7040 */  sll   $t6, $t5, 1
/* 0C6528 7F0919F8 004E7821 */  addu  $t7, $v0, $t6
/* 0C652C 7F0919FC A5EC128C */  sh    $t4, 0x128c($t7)
/* 0C6530 7F091A00 8C820000 */  lw    $v0, ($a0)
/* 0C6534 7F091A04 905812B4 */  lbu   $t8, 0x12b4($v0)
/* 0C6538 7F091A08 27190001 */  addiu $t9, $t8, 1
/* 0C653C 7F091A0C 0321001A */  div   $zero, $t9, $at
/* 0C6540 7F091A10 00004010 */  mfhi  $t0
/* 0C6544 7F091A14 A04812B4 */  sb    $t0, 0x12b4($v0)
/* 0C6548 7F091A18 8C820000 */  lw    $v0, ($a0)
/* 0C654C 7F091A1C 904312B5 */  lbu   $v1, 0x12b5($v0)
/* 0C6550 7F091A20 28610014 */  slti  $at, $v1, 0x14
/* 0C6554 7F091A24 10200007 */  beqz  $at, .L7F091A44
/* 0C6558 7F091A28 24690001 */   addiu $t1, $v1, 1
/* 0C655C 7F091A2C 10000005 */  b     .L7F091A44
/* 0C6560 7F091A30 A04912B5 */   sb    $t1, 0x12b5($v0)
.L7F091A34:
/* 0C6564 7F091A34 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C6568 7F091A38 2484A0B0 */  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
/* 0C656C 7F091A3C 8C8A0000 */  lw    $t2, ($a0)
/* 0C6570 7F091A40 A14012B5 */  sb    $zero, 0x12b5($t2)
.L7F091A44:
/* 0C6574 7F091A44 0FC245DF */  jal   cheatButton_7F09177C
/* 0C6578 7F091A48 00000000 */   nop   
/* 0C657C 7F091A4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C6580 7F091A50 27BD0028 */  addiu $sp, $sp, 0x28
/* 0C6584 7F091A54 03E00008 */  jr    $ra
/* 0C6588 7F091A58 00000000 */   nop   
)
#endif






u32 is_cheat_index_equal_to_1C(u32 cheatindex)
{
    if (cheatindex == 0x1c) {
        return 1;
    }
    return 0;
}






#ifdef NONMATCHING
void cheatCheckIfMPCheat(void) {

}
#else
GLOBAL_ASM(
.text
glabel cheatCheckIfMPCheat
/* 0C65A8 7F091A78 00047100 */  sll   $t6, $a0, 4
/* 0C65AC 7F091A7C 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C65B0 7F091A80 01EE7821 */  addu  $t7, $t7, $t6
/* 0C65B4 7F091A84 8DEFF808 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C65B8 7F091A88 24010004 */  li    $at, 4
/* 0C65BC 7F091A8C 00001025 */  move  $v0, $zero
/* 0C65C0 7F091A90 31F80004 */  andi  $t8, $t7, 4
/* 0C65C4 7F091A94 17010003 */  bne   $t8, $at, .L7F091AA4
/* 0C65C8 7F091A98 00000000 */   nop   
/* 0C65CC 7F091A9C 03E00008 */  jr    $ra
/* 0C65D0 7F091AA0 24020001 */   li    $v0, 1

.L7F091AA4:
/* 0C65D4 7F091AA4 03E00008 */  jr    $ra
/* 0C65D8 7F091AA8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void turn_on_cheat_for_players(u32 cheatindex)
{
  u32 uVar1;
  u32 playernum;
  u32 numplayers;
  u32 i;
  
  uVar1 = D_8003F80C[cheatindex];
  playernum = get_cur_playernum();
  numplayers = getPlayerCount();
  if (numplayers == 1) {
    handle_cheats_turned_on(cheatindex);
  }
  else {
    if ((uVar1 & 4) != 0)
    {
      if ((uVar1 & 0x20) == 0)
      {
        i = 0;
        if (0 < (int)numplayers)
        {
            while (i != numplayers)
            {
                set_cur_player(i);
                handle_cheats_turned_on(cheatindex);
                i = i + 1;
            };
        }
        set_cur_player(playernum);
      }
      else
      {
        handle_cheats_turned_on(cheatindex);
      }
    }
  }
  return;
}
#else
GLOBAL_ASM(
.text
glabel turn_on_cheat_for_players
/* 0C65DC 7F091AAC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C65E0 7F091AB0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C65E4 7F091AB4 3C108004 */  lui   $s0, %hi(D_8003F808)
/* 0C65E8 7F091AB8 00047100 */  sll   $t6, $a0, 4
/* 0C65EC 7F091ABC AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C65F0 7F091AC0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C65F4 7F091AC4 020E8021 */  addu  $s0, $s0, $t6
/* 0C65F8 7F091AC8 00809025 */  move  $s2, $a0
/* 0C65FC 7F091ACC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C6600 7F091AD0 0FC26C54 */  jal   get_cur_playernum
/* 0C6604 7F091AD4 8E10F808 */   lw    $s0, %lo(D_8003F808)($s0)
/* 0C6608 7F091AD8 0FC26919 */  jal   getPlayerCount
/* 0C660C 7F091ADC AFA20028 */   sw    $v0, 0x28($sp)
/* 0C6610 7F091AE0 24010001 */  li    $at, 1
/* 0C6614 7F091AE4 14410005 */  bne   $v0, $at, .L7F091AFC
/* 0C6618 7F091AE8 00408825 */   move  $s1, $v0
/* 0C661C 7F091AEC 0FC246D9 */  jal   handle_cheats_turned_on
/* 0C6620 7F091AF0 02402025 */   move  $a0, $s2
/* 0C6624 7F091AF4 10000016 */  b     .L7F091B50
/* 0C6628 7F091AF8 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F091AFC:
/* 0C662C 7F091AFC 320F0004 */  andi  $t7, $s0, 4
/* 0C6630 7F091B00 11E00012 */  beqz  $t7, .L7F091B4C
/* 0C6634 7F091B04 32180020 */   andi  $t8, $s0, 0x20
/* 0C6638 7F091B08 13000005 */  beqz  $t8, .L7F091B20
/* 0C663C 7F091B0C 00000000 */   nop   
/* 0C6640 7F091B10 0FC246D9 */  jal   handle_cheats_turned_on
/* 0C6644 7F091B14 02402025 */   move  $a0, $s2
/* 0C6648 7F091B18 1000000D */  b     .L7F091B50
/* 0C664C 7F091B1C 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F091B20:
/* 0C6650 7F091B20 18400008 */  blez  $v0, .L7F091B44
/* 0C6654 7F091B24 00008025 */   move  $s0, $zero
.L7F091B28:
/* 0C6658 7F091B28 0FC26C43 */  jal   set_cur_player
/* 0C665C 7F091B2C 02002025 */   move  $a0, $s0
/* 0C6660 7F091B30 0FC246D9 */  jal   handle_cheats_turned_on
/* 0C6664 7F091B34 02402025 */   move  $a0, $s2
/* 0C6668 7F091B38 26100001 */  addiu $s0, $s0, 1
/* 0C666C 7F091B3C 1611FFFA */  bne   $s0, $s1, .L7F091B28
/* 0C6670 7F091B40 00000000 */   nop   
.L7F091B44:
/* 0C6674 7F091B44 0FC26C43 */  jal   set_cur_player
/* 0C6678 7F091B48 8FA40028 */   lw    $a0, 0x28($sp)
.L7F091B4C:
/* 0C667C 7F091B4C 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F091B50:
/* 0C6680 7F091B50 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C6684 7F091B54 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C6688 7F091B58 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C668C 7F091B5C 03E00008 */  jr    $ra
/* 0C6690 7F091B60 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void handle_cheats_turned_on(CHEAT_IDS cheat)

{
  uint uVar1;
  bool bVar2;
  PLAYER_ID playernum;
  PLAYER_ID PVar4;
  //ulonglong uVar3;
  //BOOL BVar5;
  //BOOL BVar6;
  //BOOL BVar7;
  //BOOL BVar8;
  //BOOL BVar9;
  //u8 *text;
  s32 sVar10;
  //int amount;
  STAGENUM stageid;
  STAGENUM SVar11;
  //f32 fVar12;
  f32 scale;
  PLAYER_ID local_10;
  
  uVar1 = (&D_8003F808)[cheat * 4];
  playernum = get_cur_playernum();
  numplayers = getPlayerCount();
  if ((uVar1 & 0x10) == 0) {
    if ((uVar1 & 0x20) == 0) {
      cheatl_ARRAY_80079e30[cheat] = cheatl_ARRAY_80079e30[cheat] | (byte)(1 << (playernum & 0x1f));
    }
    else {
      cheatl_ARRAY_80079e30[cheat] = (char)(1 << (numplayers & 0x1f)) + -1;
    }
  }
  switch(cheat) {
  case CHEAT_EXTRA_MP_CHARS:
    unlock_mp_chars();
    break;
  case CHEAT_INVINCIBILITY:
    if (get_bondata_invincible_flag() == 0)
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb00f));
      set_bondata_invincible_flag(1);
    }
    break;
  case CHEAT_ALLGUNS:
    if (get_BONDdata_allguns_flag() == 0)
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb010));
      set_BONDdata_allguns_flag(1);
    }
    break;
  case CHEAT_MAXAMMO:
    display_string_in_lower_left_corner(get_textptr_for_textID(0xb011));
    set_max_ammo_for_cur_player();
    break;
  case CHEAT_REMOVE_INVINCIBILITY:
    bVar2 = false;
    if (1 < (int)numplayers) {
      local_10 = PLAYER1;
      if (0 < (int)numplayers) {
        do {
          if (local_10 != playernum) {
            set_cur_player(local_10);
            if (get_bondata_invincible_flag() != 0) {
              bVar2 = true;
              set_bondata_invincible_flag(0);
            }
          }
          set_cur_player(playernum);
          local_10 = local_10 + PLAYER2;
        } while (local_10 != numplayers);
      }
      if (bVar2) {
        play_sfx_a1(ptr_sfx_buf,0x9f,(ALSndPlayer *)0x0);
      }
    }
    break;
  case CHEAT_LINEMODE:
    set_linemode_flag(1);
    break;
  case cheats_cheat_2x_health:
    if ((pPlayer->actual_health == 1.00000000) || (pPlayer->bondhealth < 1.00000000))
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb012));
      pPlayer->bondhealth = 1.00000000;
      pPlayer->actual_health = 2.00000000;
    }
    break;
  case cheats_cheat_2x_armor:
    if ((pPlayer->actual_armor == 1.00000000) || (pPlayer->bondarmour < 1.00000000))
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb013));
      pPlayer->bondarmour = 1.00000000;
      pPlayer->actual_armor = 2.00000000;
    }
    break;
  case cheats_cheat_invisibility:
    if (get_invisible_to_guards_flag() != 0)
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb014));
      set_invisible_to_guards_flag(0);
    }
    break;
  case cheats_cheat_infinite_ammo:
    display_string_in_lower_left_corner(get_textptr_for_textID(0xb016));
    break;
  case cheats_cheat_dk_mode:
    display_string_in_lower_left_corner(get_textptr_for_textID(0xb017));
    set_DKMode(1);
    break;
  case cheats_cheat_extra_weapons:
    if (numplayers == PLAYER2)
    {
      give_cur_player_ammo(AMMO_MAGNUM, get_max_ammo_for_type(AMMO_MAGNUM));
      give_cur_player_ammo(AMMO_GGUN, get_max_ammo_for_type(AMMO_GGUN));
      give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
      if (0 < (add_item_to_inventory(ITEM_RUGER) + add_item_to_inventory(ITEM_LASER) + add_item_to_inventory(ITEM_GOLDENGUN) + add_item_to_inventory(ITEM_SILVERWPPK) + add_item_to_inventory(ITEM_GOLDWPPK)))
      {
        display_string_in_lower_left_corner(get_textptr_for_textID(0xb018));
      }
    }
    break;
  case cheats_cheat_tiny_bond:
    if ((numplayers == PLAYER2) && (pPlayersPerm->player_perspective_height == 1.00000000))
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb019));
      pPlayersPerm->player_perspective_height = 0.50000000;
      if (pPlayer->ptr_char_objectinstance != 0)
      {
        set_obj_instance_controller_scale(pPlayer->ptr_char_objectinstance,scale);
      }
    }
    break;
  case cheats_cheat_paintball:
    display_string_in_lower_left_corner(get_textptr_for_textID(0xb01a));
    break;
  case cheats_cheat_10x_health:
    if ((pPlayer->actual_health == 1.00000000) || (pPlayer->bondhealth < 1.00000000))
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb01b));
      pPlayer->bondhealth = 1.00000000;
      pPlayer->actual_health = 10.00000000;
    }
    break;
  case cheats_cheat_magnum:
    if (numplayers == PLAYER2)
    {
      add_item_to_inventory(ITEM_RUGER);
      give_cur_player_ammo(AMMO_MAGNUM, get_max_ammo_for_type(AMMO_MAGNUM));
    }
    break;
  case cheats_cheat_laser:
    if (numplayers == PLAYER2)
    {
      add_item_to_inventory(ITEM_LASER);
    }
    break;
  case cheats_cheat_goldengun:
    if (numplayers == PLAYER2) {
      add_item_to_inventory(ITEM_GOLDENGUN);
      give_cur_player_ammo(AMMO_GGUN, get_max_ammo_for_type(AMMO_GGUN));
    }
    break;
  case cheats_cheat_silverpp7:
    if (numplayers == PLAYER2)
    {
      add_item_to_inventory(ITEM_SILVERWPPK);
      give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
    }
    break;
  case cheats_cheat_goldpp7:
    if (numplayers == PLAYER2)
    {
      add_item_to_inventory(ITEM_GOLDWPPK);
      give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
    }
    break;
  case cheats_cheat_invisibility_mp:
    currentPlayerStartChrFade(300.00000000, 0.5f);
    break;
  case cheats_cheat_fast:
    if (get_debug_fast_bond_flag() == FALSE)
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb01d));
      set_debug_fast_bond_flag(TRUE);
    }
    break;
  case cheats_debug_pos:
    if (get_debug_testingmanpos_flag() == FALSE)
    {
      set_debug_testingmanpos_flag(TRUE);
    }
    break;
  case cheats_debug_fast_ani:
    if (get_animation_rate() < 4.00000000)
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb034));
      animation_speed_related(4.00000000);
    }
    break;
  case cheats_debug_slow_ani:
    if (0.25000000 < get_animation_rate())
    {
      display_string_in_lower_left_corner(get_textptr_for_textID(0xb032));
      animation_speed_related(0.25000000);
    }
    break;
  case cheats_debug_2x_rockets:
    if (numplayers == PLAYER2)
    {
      add_doubles_item_to_inventory(ITEM_ROCKETLAUNCH, ITEM_ROCKETLAUNCH);
      give_cur_player_ammo(AMMO_ROCKETS, get_max_ammo_for_type(AMMO_ROCKETS));
    }
    break;
  case cheats_debug_2x_grenade_launch:
    if (numplayers == PLAYER2)
    {
      add_doubles_item_to_inventory(ITEM_GRENADELAUNCH, ITEM_GRENADELAUNCH);
      give_cur_player_ammo(AMMO_GRENADEROUND, get_max_ammo_for_type(AMMO_GRENADEROUND));
    }
    break;
  case cheats_debug_2x_rcp90:
    if (numplayers == PLAYER2)
    {
      add_doubles_item_to_inventory(ITEM_FNP90, ITEM_FNP90);
      give_cur_player_ammo(AMMO_9MM, get_max_ammo_for_type(AMMO_9MM));
    }
    break;
  case cheats_debug_2x_throwing_knife:
    if (numplayers == PLAYER2)
    {
      add_doubles_item_to_inventory(ITEM_THROWKNIFE, ITEM_THROWKNIFE);
      give_cur_player_ammo(AMMO_KNIFE, get_max_ammo_for_type(AMMO_KNIFE));
    }
    break;
  case cheats_debug_2x_hunting_knife:
    if (numplayers == PLAYER2)
    {
      add_doubles_item_to_inventory(ITEM_KNIFE, ITEM_KNIFE);
    }
    break;
  case cheats_debug_2x_laser:
    if (numplayers == PLAYER2)
    {
      add_doubles_item_to_inventory(ITEM_LASER, ITEM_LASER);
    }
    break;
  case UNUSED_23:
  case UNUSED_24:
  case UNUSED_25:
  case UNUSED_26:
  case UNUSED_27:
  case UNUSED_28:
  case UNUSED_29:
  case UNUSED_2A:
  case UNUSED_2B:
  case UNUSED_2C:
  case UNUSED_2D:
  case UNUSED_2E:
  case UNUSED_2F:
  case UNUSED_30:
  case UNUSED_31:
  case UNUSED_32:
  case UNUSED_33:
  case UNUSED_34:
  case UNUSED_35:
  case UNLOCK_CHEATS:
    if ((-1 < selected_folder_num) && (selected_folder_num < 4)) {
      proc_7F01E760(selected_folder_num,cheat + ~cheats_debug_2x_laser);
      play_sfx_a1(ptr_sfx_buf,0x9f,(ALSndPlayer *)0x0);
    }
    break;
  case UNUSED_37:
  case UNUSED_38:
  case UNUSED_39:
  case UNUSED_3A:
  case UNUSED_3B:
  case UNUSED_3C:
  case UNUSED_3D:
  case UNUSED_3E:
  case UNUSED_3F:
  case UNUSED_40:
  case UNUSED_41:
  case UNUSED_42:
  case UNUSED_43:
  case UNUSED_44:
  case UNUSED_45:
  case UNUSED_46:
  case UNUSED_47:
  case UNUSED_48:
  case UNUSED_49:
  case UNLOCK_STAGES:
    SVar11 = cheat + ~UNLOCK_CHEATS;
    if ((-1 < (int)selected_folder_num) && (amount = 0, (int)selected_folder_num < 4)) {
      stageid = SP_STAGE_DAM;
      if (0 < (int)SVar11) {
        do {
          sVar10 = isStageUnlockedAtDifficulty(selected_folder_num,stageid,DIFFICULTY_AGENT);
          if (sVar10 == 3) {
            amount = amount + 1;
          }
          stageid = stageid + SP_STAGE_FACILITY;
        } while (stageid != SVar11);
      }
      if (SVar11 == amount + SP_STAGE_FACILITY) {
        unlock_stage_in_folder_on_difficulty
                  (selected_folder_num,(longlong)(int)(cheat + ~UNUSED_37),0,99999999);
        play_sfx_a1(ptr_sfx_buf,0x9f,(ALSndPlayer *)0x0);
      }
    }
  }
  return;
}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
/*D:800572B0*/
glabel jpt_cheats_cheat
.word cheats_cheat_extra_mp_chars
.word cheats_cheat_invincibility
.word cheats_cheat_allguns
.word cheats_cheat_max_ammo
.word cheats_debug_return_saved_ra
.word cheats_cheat_deactivate_invincibility
.word cheats_cheat_linemode
.word cheats_cheat_2x_health
.word cheats_cheat_2x_armor
.word cheats_cheat_invisibility
.word cheats_cheat_infinite_ammo
.word cheats_cheat_dk_mode
.word cheats_cheat_extra_weapons
.word cheats_cheat_tiny_bond
.word cheats_cheat_paintball
.word cheats_cheat_10x_health
.word cheats_cheat_magnum
.word cheats_cheat_laser
.word cheats_cheat_goldengun
.word cheats_cheat_silverpp7
.word cheats_cheat_goldpp7
.word cheats_cheat_invisibility_mp
.word cheats_debug_return_saved_ra
.word cheats_cheat_fast
.word cheats_debug_pos
.word cheats_debug_fast_ani
.word cheats_debug_slow_ani
.word cheats_debug_return_saved_ra
.word cheats_debug_2x_rockets
.word cheats_debug_2x_grenade_launch
.word cheats_debug_2x_rcp90
.word cheats_debug_2x_throwing_knife
.word cheats_debug_2x_hunting_knife
.word cheats_debug_2x_laser
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel

/*800573D8*/
glabel finalamount
.word 0x3d4ccccd /*0.050000001*/
.text
glabel handle_cheats_turned_on
/* 0C6694 7F091B64 00047100 */  sll   $t6, $a0, 4
/* 0C6698 7F091B68 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C669C 7F091B6C 01EE7821 */  addu  $t7, $t7, $t6
/* 0C66A0 7F091B70 8DEFF808 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C66A4 7F091B74 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0C66A8 7F091B78 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C66AC 7F091B7C AFA40040 */  sw    $a0, 0x40($sp)
/* 0C66B0 7F091B80 0FC26C54 */  jal   get_cur_playernum
/* 0C66B4 7F091B84 AFAF003C */   sw    $t7, 0x3c($sp)
/* 0C66B8 7F091B88 0FC26919 */  jal   getPlayerCount
/* 0C66BC 7F091B8C AFA20038 */   sw    $v0, 0x38($sp)
/* 0C66C0 7F091B90 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C66C4 7F091B94 8FA60040 */  lw    $a2, 0x40($sp)
/* 0C66C8 7F091B98 AFA20034 */  sw    $v0, 0x34($sp)
/* 0C66CC 7F091B9C 30780010 */  andi  $t8, $v1, 0x10
/* 0C66D0 7F091BA0 17000012 */  bnez  $t8, .L7F091BEC
/* 0C66D4 7F091BA4 30790020 */   andi  $t9, $v1, 0x20
/* 0C66D8 7F091BA8 1720000A */  bnez  $t9, .L7F091BD4
/* 0C66DC 7F091BAC 8FA50038 */   lw    $a1, 0x38($sp)
/* 0C66E0 7F091BB0 3C098008 */  lui   $t1, %hi(off_CODE_bss_80079E30) 
/* 0C66E4 7F091BB4 25299E30 */  addiu $t1, %lo(off_CODE_bss_80079E30) # addiu $t1, $t1, -0x61d0
/* 0C66E8 7F091BB8 00C91821 */  addu  $v1, $a2, $t1
/* 0C66EC 7F091BBC 906A0000 */  lbu   $t2, ($v1)
/* 0C66F0 7F091BC0 240B0001 */  li    $t3, 1
/* 0C66F4 7F091BC4 00AB6004 */  sllv  $t4, $t3, $a1
/* 0C66F8 7F091BC8 014C6825 */  or    $t5, $t2, $t4
/* 0C66FC 7F091BCC 10000007 */  b     .L7F091BEC
/* 0C6700 7F091BD0 A06D0000 */   sb    $t5, ($v1)
.L7F091BD4:
/* 0C6704 7F091BD4 240E0001 */  li    $t6, 1
/* 0C6708 7F091BD8 004E7804 */  sllv  $t7, $t6, $v0
/* 0C670C 7F091BDC 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30)
/* 0C6710 7F091BE0 00260821 */  addu  $at, $at, $a2
/* 0C6714 7F091BE4 25F8FFFF */  addiu $t8, $t7, -1
/* 0C6718 7F091BE8 A0389E30 */  sb    $t8, %lo(off_CODE_bss_80079E30)($at)
.L7F091BEC:
/* 0C671C 7F091BEC 24D9FFFF */  addiu $t9, $a2, -1
/* 0C6720 7F091BF0 2F21004A */  sltiu $at, $t9, 0x4a
/* 0C6724 7F091BF4 1020020C */  beqz  $at, .L7F092428
/* 0C6728 7F091BF8 0019C880 */   sll   $t9, $t9, 2
/* 0C672C 7F091BFC 3C018005 */  lui   $at, %hi(jpt_cheats_cheat)
/* 0C6730 7F091C00 00390821 */  addu  $at, $at, $t9
/* 0C6734 7F091C04 8C3972B0 */  lw    $t9, %lo(jpt_cheats_cheat)($at)
/* 0C6738 7F091C08 03200008 */  jr    $t9
/* 0C673C 7F091C0C 00000000 */   nop   
cheats_cheat_extra_mp_chars:
/* 0C6740 7F091C10 0FC040A0 */  jal   unlock_all_mp_chars
/* 0C6744 7F091C14 00000000 */   nop   
/* 0C6748 7F091C18 10000204 */  b     .L7F09242C
/* 0C674C 7F091C1C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invincibility:
/* 0C6750 7F091C20 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C6754 7F091C24 00000000 */   nop   
/* 0C6758 7F091C28 54400200 */  bnezl $v0, .L7F09242C
/* 0C675C 7F091C2C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6760 7F091C30 0FC30776 */  jal   get_textptr_for_textID
/* 0C6764 7F091C34 3404B00F */   li    $a0, 45071
/* 0C6768 7F091C38 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C676C 7F091C3C 00402025 */   move  $a0, $v0
/* 0C6770 7F091C40 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C6774 7F091C44 24040001 */   li    $a0, 1
/* 0C6778 7F091C48 100001F8 */  b     .L7F09242C
/* 0C677C 7F091C4C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_allguns:
/* 0C6780 7F091C50 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C6784 7F091C54 00000000 */   nop   
/* 0C6788 7F091C58 544001F4 */  bnezl $v0, .L7F09242C
/* 0C678C 7F091C5C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6790 7F091C60 0FC30776 */  jal   get_textptr_for_textID
/* 0C6794 7F091C64 3404B010 */   li    $a0, 45072
/* 0C6798 7F091C68 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C679C 7F091C6C 00402025 */   move  $a0, $v0
/* 0C67A0 7F091C70 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C67A4 7F091C74 24040001 */   li    $a0, 1
/* 0C67A8 7F091C78 100001EC */  b     .L7F09242C
/* 0C67AC 7F091C7C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_max_ammo:
/* 0C67B0 7F091C80 0FC30776 */  jal   get_textptr_for_textID
/* 0C67B4 7F091C84 3404B011 */   li    $a0, 45073
/* 0C67B8 7F091C88 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C67BC 7F091C8C 00402025 */   move  $a0, $v0
/* 0C67C0 7F091C90 0FC1A4BC */  jal   set_max_ammo_for_cur_player
/* 0C67C4 7F091C94 00000000 */   nop   
/* 0C67C8 7F091C98 100001E4 */  b     .L7F09242C
/* 0C67CC 7F091C9C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_deactivate_invincibility:
/* 0C67D0 7F091CA0 28410002 */  slti  $at, $v0, 2
/* 0C67D4 7F091CA4 142001E0 */  bnez  $at, .L7F092428
/* 0C67D8 7F091CA8 AFA0002C */   sw    $zero, 0x2c($sp)
/* 0C67DC 7F091CAC 18400015 */  blez  $v0, .L7F091D04
/* 0C67E0 7F091CB0 AFA00030 */   sw    $zero, 0x30($sp)
.L7F091CB4:
/* 0C67E4 7F091CB4 8FA50038 */  lw    $a1, 0x38($sp)
/* 0C67E8 7F091CB8 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C67EC 7F091CBC 1125000A */  beq   $t1, $a1, .L7F091CE8
/* 0C67F0 7F091CC0 00000000 */   nop   
/* 0C67F4 7F091CC4 0FC26C43 */  jal   set_cur_player
/* 0C67F8 7F091CC8 01202025 */   move  $a0, $t1
/* 0C67FC 7F091CCC 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C6800 7F091CD0 00000000 */   nop   
/* 0C6804 7F091CD4 10400004 */  beqz  $v0, .L7F091CE8
/* 0C6808 7F091CD8 00002025 */   move  $a0, $zero
/* 0C680C 7F091CDC 240B0001 */  li    $t3, 1
/* 0C6810 7F091CE0 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C6814 7F091CE4 AFAB002C */   sw    $t3, 0x2c($sp)
.L7F091CE8:
/* 0C6818 7F091CE8 0FC26C43 */  jal   set_cur_player
/* 0C681C 7F091CEC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0C6820 7F091CF0 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0C6824 7F091CF4 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0C6828 7F091CF8 254C0001 */  addiu $t4, $t2, 1
/* 0C682C 7F091CFC 158DFFED */  bne   $t4, $t5, .L7F091CB4
/* 0C6830 7F091D00 AFAC0030 */   sw    $t4, 0x30($sp)
.L7F091D04:
/* 0C6834 7F091D04 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0C6838 7F091D08 3C048006 */  lui   $a0, %hi(ptr_sfx_buf)
/* 0C683C 7F091D0C 2405009F */  li    $a1, 159
/* 0C6840 7F091D10 11C001C5 */  beqz  $t6, .L7F092428
/* 0C6844 7F091D14 00003025 */   move  $a2, $zero
/* 0C6848 7F091D18 0C002382 */  jal   play_sfx_a1
/* 0C684C 7F091D1C 8C843720 */   lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6850 7F091D20 100001C2 */  b     .L7F09242C
/* 0C6854 7F091D24 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_linemode:
/* 0C6858 7F091D28 0FC243FA */  jal   set_debug_VisCVG_flag
/* 0C685C 7F091D2C 24040001 */   li    $a0, 1
/* 0C6860 7F091D30 100001BE */  b     .L7F09242C
/* 0C6864 7F091D34 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_2x_health:
/* 0C6868 7F091D38 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C686C 7F091D3C 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C6870 7F091D40 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6874 7F091D44 44812000 */  mtc1  $at, $f4
/* 0C6878 7F091D48 C4462A3C */  lwc1  $f6, 0x2a3c($v0)
/* 0C687C 7F091D4C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6880 7F091D50 46062032 */  c.eq.s $f4, $f6
/* 0C6884 7F091D54 00000000 */  nop   
/* 0C6888 7F091D58 45010008 */  bc1t  .L7F091D7C
/* 0C688C 7F091D5C 00000000 */   nop   
/* 0C6890 7F091D60 C44800DC */  lwc1  $f8, 0xdc($v0)
/* 0C6894 7F091D64 44815000 */  mtc1  $at, $f10
/* 0C6898 7F091D68 00000000 */  nop   
/* 0C689C 7F091D6C 460A403C */  c.lt.s $f8, $f10
/* 0C68A0 7F091D70 00000000 */  nop   
/* 0C68A4 7F091D74 450201AD */  bc1fl .L7F09242C
/* 0C68A8 7F091D78 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F091D7C:
/* 0C68AC 7F091D7C 0FC30776 */  jal   get_textptr_for_textID
/* 0C68B0 7F091D80 3404B012 */   li    $a0, 45074
/* 0C68B4 7F091D84 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C68B8 7F091D88 00402025 */   move  $a0, $v0
/* 0C68BC 7F091D8C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C68C0 7F091D90 3C0F8008 */  lui   $t7, %hi(pPlayer) 
/* 0C68C4 7F091D94 8DEFA0B0 */  lw    $t7, %lo(pPlayer)($t7)
/* 0C68C8 7F091D98 44818000 */  mtc1  $at, $f16
/* 0C68CC 7F091D9C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C68D0 7F091DA0 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C68D4 7F091DA4 E5F000DC */  swc1  $f16, 0xdc($t7)
/* 0C68D8 7F091DA8 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C68DC 7F091DAC 44819000 */  mtc1  $at, $f18
/* 0C68E0 7F091DB0 1000019D */  b     .L7F092428
/* 0C68E4 7F091DB4 E7122A3C */   swc1  $f18, 0x2a3c($t8)
cheats_cheat_2x_armor:
/* 0C68E8 7F091DB8 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C68EC 7F091DBC 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C68F0 7F091DC0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C68F4 7F091DC4 44810000 */  mtc1  $at, $f0
/* 0C68F8 7F091DC8 C4442A40 */  lwc1  $f4, 0x2a40($v0)
/* 0C68FC 7F091DCC 46040032 */  c.eq.s $f0, $f4
/* 0C6900 7F091DD0 00000000 */  nop   
/* 0C6904 7F091DD4 45010006 */  bc1t  .L7F091DF0
/* 0C6908 7F091DD8 00000000 */   nop   
/* 0C690C 7F091DDC C44600E0 */  lwc1  $f6, 0xe0($v0)
/* 0C6910 7F091DE0 4600303C */  c.lt.s $f6, $f0
/* 0C6914 7F091DE4 00000000 */  nop   
/* 0C6918 7F091DE8 45020190 */  bc1fl .L7F09242C
/* 0C691C 7F091DEC 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F091DF0:
/* 0C6920 7F091DF0 0FC30776 */  jal   get_textptr_for_textID
/* 0C6924 7F091DF4 3404B013 */   li    $a0, 45075
/* 0C6928 7F091DF8 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C692C 7F091DFC 00402025 */   move  $a0, $v0
/* 0C6930 7F091E00 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C6934 7F091E04 2442A0B0 */  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
/* 0C6938 7F091E08 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C693C 7F091E0C 44814000 */  mtc1  $at, $f8
/* 0C6940 7F091E10 8C590000 */  lw    $t9, ($v0)
/* 0C6944 7F091E14 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C6948 7F091E18 44815000 */  mtc1  $at, $f10
/* 0C694C 7F091E1C E72800E0 */  swc1  $f8, 0xe0($t9)
/* 0C6950 7F091E20 8C490000 */  lw    $t1, ($v0)
/* 0C6954 7F091E24 10000180 */  b     .L7F092428
/* 0C6958 7F091E28 E52A2A40 */   swc1  $f10, 0x2a40($t1)
cheats_cheat_invisibility:
/* 0C695C 7F091E2C 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C6960 7F091E30 00000000 */   nop   
/* 0C6964 7F091E34 5040017D */  beql  $v0, $zero, .L7F09242C
/* 0C6968 7F091E38 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C696C 7F091E3C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6970 7F091E40 3404B014 */   li    $a0, 45076
/* 0C6974 7F091E44 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6978 7F091E48 00402025 */   move  $a0, $v0
/* 0C697C 7F091E4C 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C6980 7F091E50 00002025 */   move  $a0, $zero
/* 0C6984 7F091E54 10000175 */  b     .L7F09242C
/* 0C6988 7F091E58 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_infinite_ammo:
/* 0C698C 7F091E5C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6990 7F091E60 3404B016 */   li    $a0, 45078
/* 0C6994 7F091E64 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6998 7F091E68 00402025 */   move  $a0, $v0
/* 0C699C 7F091E6C 1000016F */  b     .L7F09242C
/* 0C69A0 7F091E70 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_dk_mode:
/* 0C69A4 7F091E74 0FC30776 */  jal   get_textptr_for_textID
/* 0C69A8 7F091E78 3404B017 */   li    $a0, 45079
/* 0C69AC 7F091E7C 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C69B0 7F091E80 00402025 */   move  $a0, $v0
/* 0C69B4 7F091E84 0FC249FD */  jal   set_DKMode
/* 0C69B8 7F091E88 24040001 */   li    $a0, 1
/* 0C69BC 7F091E8C 10000167 */  b     .L7F09242C
/* 0C69C0 7F091E90 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_extra_weapons:
/* 0C69C4 7F091E94 24010001 */  li    $at, 1
/* 0C69C8 7F091E98 54410164 */  bnel  $v0, $at, .L7F09242C
/* 0C69CC 7F091E9C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C69D0 7F091EA0 0FC23122 */  jal   add_item_to_inventory
/* 0C69D4 7F091EA4 24040012 */   li    $a0, 18
/* 0C69D8 7F091EA8 AFA20028 */  sw    $v0, 0x28($sp)
/* 0C69DC 7F091EAC 0FC23122 */  jal   add_item_to_inventory
/* 0C69E0 7F091EB0 24040016 */   li    $a0, 22
/* 0C69E4 7F091EB4 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C69E8 7F091EB8 24040013 */  li    $a0, 19
/* 0C69EC 7F091EBC 01625021 */  addu  $t2, $t3, $v0
/* 0C69F0 7F091EC0 0FC23122 */  jal   add_item_to_inventory
/* 0C69F4 7F091EC4 AFAA0028 */   sw    $t2, 0x28($sp)
/* 0C69F8 7F091EC8 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0C69FC 7F091ECC 24040014 */  li    $a0, 20
/* 0C6A00 7F091ED0 01826821 */  addu  $t5, $t4, $v0
/* 0C6A04 7F091ED4 0FC23122 */  jal   add_item_to_inventory
/* 0C6A08 7F091ED8 AFAD0028 */   sw    $t5, 0x28($sp)
/* 0C6A0C 7F091EDC 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C6A10 7F091EE0 24040015 */  li    $a0, 21
/* 0C6A14 7F091EE4 01C27821 */  addu  $t7, $t6, $v0
/* 0C6A18 7F091EE8 0FC23122 */  jal   add_item_to_inventory
/* 0C6A1C 7F091EEC AFAF0028 */   sw    $t7, 0x28($sp)
/* 0C6A20 7F091EF0 8FB80028 */  lw    $t8, 0x28($sp)
/* 0C6A24 7F091EF4 2404000C */  li    $a0, 12
/* 0C6A28 7F091EF8 0302C821 */  addu  $t9, $t8, $v0
/* 0C6A2C 7F091EFC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A30 7F091F00 AFB90028 */   sw    $t9, 0x28($sp)
/* 0C6A34 7F091F04 2404000C */  li    $a0, 12
/* 0C6A38 7F091F08 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A3C 7F091F0C 00402825 */   move  $a1, $v0
/* 0C6A40 7F091F10 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A44 7F091F14 2404000D */   li    $a0, 13
/* 0C6A48 7F091F18 2404000D */  li    $a0, 13
/* 0C6A4C 7F091F1C 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A50 7F091F20 00402825 */   move  $a1, $v0
/* 0C6A54 7F091F24 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6A58 7F091F28 24040001 */   li    $a0, 1
/* 0C6A5C 7F091F2C 24040001 */  li    $a0, 1
/* 0C6A60 7F091F30 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6A64 7F091F34 00402825 */   move  $a1, $v0
/* 0C6A68 7F091F38 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C6A6C 7F091F3C 5920013B */  blezl $t1, .L7F09242C
/* 0C6A70 7F091F40 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6A74 7F091F44 0FC30776 */  jal   get_textptr_for_textID
/* 0C6A78 7F091F48 3404B018 */   li    $a0, 45080
/* 0C6A7C 7F091F4C 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6A80 7F091F50 00402025 */   move  $a0, $v0
/* 0C6A84 7F091F54 10000135 */  b     .L7F09242C
/* 0C6A88 7F091F58 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_tiny_bond:
/* 0C6A8C 7F091F5C 24010001 */  li    $at, 1
/* 0C6A90 7F091F60 14410131 */  bne   $v0, $at, .L7F092428
/* 0C6A94 7F091F64 3C0B8008 */   lui   $t3, %hi(pPlayersPerm) 
/* 0C6A98 7F091F68 8D6BA0B4 */  lw    $t3, %lo(pPlayersPerm)($t3)
/* 0C6A9C 7F091F6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6AA0 7F091F70 44818000 */  mtc1  $at, $f16
/* 0C6AA4 7F091F74 C5720064 */  lwc1  $f18, 0x64($t3)
/* 0C6AA8 7F091F78 46128032 */  c.eq.s $f16, $f18
/* 0C6AAC 7F091F7C 00000000 */  nop   
/* 0C6AB0 7F091F80 4502012A */  bc1fl .L7F09242C
/* 0C6AB4 7F091F84 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6AB8 7F091F88 0FC30776 */  jal   get_textptr_for_textID
/* 0C6ABC 7F091F8C 3404B019 */   li    $a0, 45081
/* 0C6AC0 7F091F90 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6AC4 7F091F94 00402025 */   move  $a0, $v0
/* 0C6AC8 7F091F98 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C6ACC 7F091F9C 3C0A8008 */  lui   $t2, %hi(pPlayersPerm) 
/* 0C6AD0 7F091FA0 44810000 */  mtc1  $at, $f0
/* 0C6AD4 7F091FA4 8D4AA0B4 */  lw    $t2, %lo(pPlayersPerm)($t2)
/* 0C6AD8 7F091FA8 3C0C8008 */  lui   $t4, %hi(pPlayer) 
/* 0C6ADC 7F091FAC E5400064 */  swc1  $f0, 0x64($t2)
/* 0C6AE0 7F091FB0 8D8CA0B0 */  lw    $t4, %lo(pPlayer)($t4)
/* 0C6AE4 7F091FB4 8D8400D4 */  lw    $a0, 0xd4($t4)
/* 0C6AE8 7F091FB8 5080011C */  beql  $a0, $zero, .L7F09242C
/* 0C6AEC 7F091FBC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6AF0 7F091FC0 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C6AF4 7F091FC4 46002182 */  mul.s $f6, $f4, $f0
/* 0C6AF8 7F091FC8 44053000 */  mfc1  $a1, $f6
/* 0C6AFC 7F091FCC 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C6B00 7F091FD0 00000000 */   nop   
/* 0C6B04 7F091FD4 10000115 */  b     .L7F09242C
/* 0C6B08 7F091FD8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_paintball:
/* 0C6B0C 7F091FDC 0FC30776 */  jal   get_textptr_for_textID
/* 0C6B10 7F091FE0 3404B01A */   li    $a0, 45082
/* 0C6B14 7F091FE4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6B18 7F091FE8 00402025 */   move  $a0, $v0
/* 0C6B1C 7F091FEC 1000010F */  b     .L7F09242C
/* 0C6B20 7F091FF0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_10x_health:
/* 0C6B24 7F091FF4 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C6B28 7F091FF8 8C42A0B0 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C6B2C 7F091FFC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6B30 7F092000 44810000 */  mtc1  $at, $f0
/* 0C6B34 7F092004 C4482A3C */  lwc1  $f8, 0x2a3c($v0)
/* 0C6B38 7F092008 46080032 */  c.eq.s $f0, $f8
/* 0C6B3C 7F09200C 00000000 */  nop   
/* 0C6B40 7F092010 45010006 */  bc1t  .L7F09202C
/* 0C6B44 7F092014 00000000 */   nop   
/* 0C6B48 7F092018 C44A00DC */  lwc1  $f10, 0xdc($v0)
/* 0C6B4C 7F09201C 4600503C */  c.lt.s $f10, $f0
/* 0C6B50 7F092020 00000000 */  nop   
/* 0C6B54 7F092024 45020101 */  bc1fl .L7F09242C
/* 0C6B58 7F092028 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F09202C:
/* 0C6B5C 7F09202C 0FC30776 */  jal   get_textptr_for_textID
/* 0C6B60 7F092030 3404B01B */   li    $a0, 45083
/* 0C6B64 7F092034 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6B68 7F092038 00402025 */   move  $a0, $v0
/* 0C6B6C 7F09203C 3C028008 */  lui   $v0, %hi(pPlayer)
/* 0C6B70 7F092040 2442A0B0 */  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
/* 0C6B74 7F092044 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C6B78 7F092048 44818000 */  mtc1  $at, $f16
/* 0C6B7C 7F09204C 8C4D0000 */  lw    $t5, ($v0)
/* 0C6B80 7F092050 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0C6B84 7F092054 44819000 */  mtc1  $at, $f18
/* 0C6B88 7F092058 E5B000DC */  swc1  $f16, 0xdc($t5)
/* 0C6B8C 7F09205C 8C4E0000 */  lw    $t6, ($v0)
/* 0C6B90 7F092060 100000F1 */  b     .L7F092428
/* 0C6B94 7F092064 E5D22A3C */   swc1  $f18, 0x2a3c($t6)
cheats_cheat_magnum:
/* 0C6B98 7F092068 24010001 */  li    $at, 1
/* 0C6B9C 7F09206C 544100EF */  bnel  $v0, $at, .L7F09242C
/* 0C6BA0 7F092070 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BA4 7F092074 0FC23122 */  jal   add_item_to_inventory
/* 0C6BA8 7F092078 24040012 */   li    $a0, 18
/* 0C6BAC 7F09207C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6BB0 7F092080 2404000C */   li    $a0, 12
/* 0C6BB4 7F092084 2404000C */  li    $a0, 12
/* 0C6BB8 7F092088 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6BBC 7F09208C 00402825 */   move  $a1, $v0
/* 0C6BC0 7F092090 100000E6 */  b     .L7F09242C
/* 0C6BC4 7F092094 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_laser:
/* 0C6BC8 7F092098 24010001 */  li    $at, 1
/* 0C6BCC 7F09209C 544100E3 */  bnel  $v0, $at, .L7F09242C
/* 0C6BD0 7F0920A0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BD4 7F0920A4 0FC23122 */  jal   add_item_to_inventory
/* 0C6BD8 7F0920A8 24040016 */   li    $a0, 22
/* 0C6BDC 7F0920AC 100000DF */  b     .L7F09242C
/* 0C6BE0 7F0920B0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldengun:
/* 0C6BE4 7F0920B4 24010001 */  li    $at, 1
/* 0C6BE8 7F0920B8 544100DC */  bnel  $v0, $at, .L7F09242C
/* 0C6BEC 7F0920BC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6BF0 7F0920C0 0FC23122 */  jal   add_item_to_inventory
/* 0C6BF4 7F0920C4 24040013 */   li    $a0, 19
/* 0C6BF8 7F0920C8 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6BFC 7F0920CC 2404000D */   li    $a0, 13
/* 0C6C00 7F0920D0 2404000D */  li    $a0, 13
/* 0C6C04 7F0920D4 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C08 7F0920D8 00402825 */   move  $a1, $v0
/* 0C6C0C 7F0920DC 100000D3 */  b     .L7F09242C
/* 0C6C10 7F0920E0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_silverpp7:
/* 0C6C14 7F0920E4 24010001 */  li    $at, 1
/* 0C6C18 7F0920E8 544100D0 */  bnel  $v0, $at, .L7F09242C
/* 0C6C1C 7F0920EC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6C20 7F0920F0 0FC23122 */  jal   add_item_to_inventory
/* 0C6C24 7F0920F4 24040014 */   li    $a0, 20
/* 0C6C28 7F0920F8 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6C2C 7F0920FC 24040001 */   li    $a0, 1
/* 0C6C30 7F092100 24040001 */  li    $a0, 1
/* 0C6C34 7F092104 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C38 7F092108 00402825 */   move  $a1, $v0
/* 0C6C3C 7F09210C 100000C7 */  b     .L7F09242C
/* 0C6C40 7F092110 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldpp7:
/* 0C6C44 7F092114 24010001 */  li    $at, 1
/* 0C6C48 7F092118 544100C4 */  bnel  $v0, $at, .L7F09242C
/* 0C6C4C 7F09211C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6C50 7F092120 0FC23122 */  jal   add_item_to_inventory
/* 0C6C54 7F092124 24040015 */   li    $a0, 21
/* 0C6C58 7F092128 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6C5C 7F09212C 24040001 */   li    $a0, 1
/* 0C6C60 7F092130 24040001 */  li    $a0, 1
/* 0C6C64 7F092134 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6C68 7F092138 00402825 */   move  $a1, $v0
/* 0C6C6C 7F09213C 100000BB */  b     .L7F09242C
/* 0C6C70 7F092140 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invisibility_mp:
/* 0C6C74 7F092144 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C6C78 7F092148 44816000 */  mtc1  $at, $f12
/* 0C6C7C 7F09214C 3C018005 */  lui   $at, %hi(finalamount)
/* 0C6C80 7F092150 0FC20284 */  jal   currentPlayerStartChrFade
/* 0C6C84 7F092154 C42E73D8 */   lwc1  $f14, %lo(finalamount)($at)
/* 0C6C88 7F092158 100000B4 */  b     .L7F09242C
/* 0C6C8C 7F09215C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_fast:
/* 0C6C90 7F092160 0FC24406 */  jal   get_debug_fast_bond_flag
/* 0C6C94 7F092164 00000000 */   nop   
/* 0C6C98 7F092168 544000B0 */  bnezl $v0, .L7F09242C
/* 0C6C9C 7F09216C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6CA0 7F092170 0FC30776 */  jal   get_textptr_for_textID
/* 0C6CA4 7F092174 3404B01D */   li    $a0, 45085
/* 0C6CA8 7F092178 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6CAC 7F09217C 00402025 */   move  $a0, $v0
/* 0C6CB0 7F092180 0FC24409 */  jal   set_debug_fast_bond_flag
/* 0C6CB4 7F092184 24040001 */   li    $a0, 1
/* 0C6CB8 7F092188 100000A8 */  b     .L7F09242C
/* 0C6CBC 7F09218C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_pos:
/* 0C6CC0 7F092190 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0C6CC4 7F092194 00000000 */   nop   
/* 0C6CC8 7F092198 544000A4 */  bnezl $v0, .L7F09242C
/* 0C6CCC 7F09219C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6CD0 7F0921A0 0FC243E5 */  jal   set_debug_testingmanpos_flag
/* 0C6CD4 7F0921A4 24040001 */   li    $a0, 1
/* 0C6CD8 7F0921A8 100000A0 */  b     .L7F09242C
/* 0C6CDC 7F0921AC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_fast_ani:
/* 0C6CE0 7F0921B0 0FC08179 */  jal   get_animation_rate
/* 0C6CE4 7F0921B4 00000000 */   nop   
/* 0C6CE8 7F0921B8 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C6CEC 7F0921BC 44812000 */  mtc1  $at, $f4
/* 0C6CF0 7F0921C0 00000000 */  nop   
/* 0C6CF4 7F0921C4 4604003C */  c.lt.s $f0, $f4
/* 0C6CF8 7F0921C8 00000000 */  nop   
/* 0C6CFC 7F0921CC 45020097 */  bc1fl .L7F09242C
/* 0C6D00 7F0921D0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6D04 7F0921D4 0FC30776 */  jal   get_textptr_for_textID
/* 0C6D08 7F0921D8 3404B034 */   li    $a0, 45108
/* 0C6D0C 7F0921DC 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6D10 7F0921E0 00402025 */   move  $a0, $v0
/* 0C6D14 7F0921E4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C6D18 7F0921E8 44816000 */  mtc1  $at, $f12
/* 0C6D1C 7F0921EC 0FC08150 */  jal   animation_speed_related
/* 0C6D20 7F0921F0 00000000 */   nop   
/* 0C6D24 7F0921F4 1000008D */  b     .L7F09242C
/* 0C6D28 7F0921F8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_slow_ani:
/* 0C6D2C 7F0921FC 0FC08179 */  jal   get_animation_rate
/* 0C6D30 7F092200 00000000 */   nop   
/* 0C6D34 7F092204 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C6D38 7F092208 44813000 */  mtc1  $at, $f6
/* 0C6D3C 7F09220C 00000000 */  nop   
/* 0C6D40 7F092210 4600303C */  c.lt.s $f6, $f0
/* 0C6D44 7F092214 00000000 */  nop   
/* 0C6D48 7F092218 45020084 */  bc1fl .L7F09242C
/* 0C6D4C 7F09221C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6D50 7F092220 0FC30776 */  jal   get_textptr_for_textID
/* 0C6D54 7F092224 3404B032 */   li    $a0, 45106
/* 0C6D58 7F092228 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C6D5C 7F09222C 00402025 */   move  $a0, $v0
/* 0C6D60 7F092230 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C6D64 7F092234 44816000 */  mtc1  $at, $f12
/* 0C6D68 7F092238 0FC08150 */  jal   animation_speed_related
/* 0C6D6C 7F09223C 00000000 */   nop   
/* 0C6D70 7F092240 1000007A */  b     .L7F09242C
/* 0C6D74 7F092244 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rockets:
/* 0C6D78 7F092248 24010001 */  li    $at, 1
/* 0C6D7C 7F09224C 14410076 */  bne   $v0, $at, .L7F092428
/* 0C6D80 7F092250 24040019 */   li    $a0, 25
/* 0C6D84 7F092254 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6D88 7F092258 24050019 */   li    $a1, 25
/* 0C6D8C 7F09225C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6D90 7F092260 24040006 */   li    $a0, 6
/* 0C6D94 7F092264 24040006 */  li    $a0, 6
/* 0C6D98 7F092268 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6D9C 7F09226C 00402825 */   move  $a1, $v0
/* 0C6DA0 7F092270 1000006E */  b     .L7F09242C
/* 0C6DA4 7F092274 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_grenade_launch:
/* 0C6DA8 7F092278 24010001 */  li    $at, 1
/* 0C6DAC 7F09227C 1441006A */  bne   $v0, $at, .L7F092428
/* 0C6DB0 7F092280 24040018 */   li    $a0, 24
/* 0C6DB4 7F092284 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6DB8 7F092288 24050018 */   li    $a1, 24
/* 0C6DBC 7F09228C 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6DC0 7F092290 2404000B */   li    $a0, 11
/* 0C6DC4 7F092294 2404000B */  li    $a0, 11
/* 0C6DC8 7F092298 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6DCC 7F09229C 00402825 */   move  $a1, $v0
/* 0C6DD0 7F0922A0 10000062 */  b     .L7F09242C
/* 0C6DD4 7F0922A4 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rcp90:
/* 0C6DD8 7F0922A8 24010001 */  li    $at, 1
/* 0C6DDC 7F0922AC 1441005E */  bne   $v0, $at, .L7F092428
/* 0C6DE0 7F0922B0 2404000E */   li    $a0, 14
/* 0C6DE4 7F0922B4 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6DE8 7F0922B8 2405000E */   li    $a1, 14
/* 0C6DEC 7F0922BC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6DF0 7F0922C0 24040001 */   li    $a0, 1
/* 0C6DF4 7F0922C4 24040001 */  li    $a0, 1
/* 0C6DF8 7F0922C8 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6DFC 7F0922CC 00402825 */   move  $a1, $v0
/* 0C6E00 7F0922D0 10000056 */  b     .L7F09242C
/* 0C6E04 7F0922D4 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_throwing_knife:
/* 0C6E08 7F0922D8 24010001 */  li    $at, 1
/* 0C6E0C 7F0922DC 14410052 */  bne   $v0, $at, .L7F092428
/* 0C6E10 7F0922E0 24040003 */   li    $a0, 3
/* 0C6E14 7F0922E4 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E18 7F0922E8 24050003 */   li    $a1, 3
/* 0C6E1C 7F0922EC 0FC1A4B5 */  jal   get_max_ammo_for_type
/* 0C6E20 7F0922F0 2404000A */   li    $a0, 10
/* 0C6E24 7F0922F4 2404000A */  li    $a0, 10
/* 0C6E28 7F0922F8 0FC1A44C */  jal   give_cur_player_ammo
/* 0C6E2C 7F0922FC 00402825 */   move  $a1, $v0
/* 0C6E30 7F092300 1000004A */  b     .L7F09242C
/* 0C6E34 7F092304 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_hunting_knife:
/* 0C6E38 7F092308 24010001 */  li    $at, 1
/* 0C6E3C 7F09230C 14410046 */  bne   $v0, $at, .L7F092428
/* 0C6E40 7F092310 24040002 */   li    $a0, 2
/* 0C6E44 7F092314 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E48 7F092318 24050002 */   li    $a1, 2
/* 0C6E4C 7F09231C 10000043 */  b     .L7F09242C
/* 0C6E50 7F092320 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_laser:
/* 0C6E54 7F092324 24010001 */  li    $at, 1
/* 0C6E58 7F092328 1441003F */  bne   $v0, $at, .L7F092428
/* 0C6E5C 7F09232C 24040016 */   li    $a0, 22
/* 0C6E60 7F092330 0FC23143 */  jal   add_doubles_item_to_inventory
/* 0C6E64 7F092334 24050016 */   li    $a1, 22
/* 0C6E68 7F092338 1000003C */  b     .L7F09242C
/* 0C6E6C 7F09233C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlockcheat:
/* 0C6E70 7F092340 3C048003 */  lui   $a0, %hi(selected_folder_num)
/* 0C6E74 7F092344 8C84A8E8 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 0C6E78 7F092348 24C5FFDD */  addiu $a1, $a2, -0x23
/* 0C6E7C 7F09234C 04800036 */  bltz  $a0, .L7F092428
/* 0C6E80 7F092350 28810004 */   slti  $at, $a0, 4
/* 0C6E84 7F092354 50200035 */  beql  $at, $zero, .L7F09242C
/* 0C6E88 7F092358 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C6E8C 7F09235C 0FC079D8 */  jal   sub_GAME_7F01E760
/* 0C6E90 7F092360 00000000 */   nop   
/* 0C6E94 7F092364 3C048006 */  lui   $a0, %hi(ptr_sfx_buf)
/* 0C6E98 7F092368 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6E9C 7F09236C 2405009F */  li    $a1, 159
/* 0C6EA0 7F092370 0C002382 */  jal   play_sfx_a1
/* 0C6EA4 7F092374 00003025 */   move  $a2, $zero
/* 0C6EA8 7F092378 1000002C */  b     .L7F09242C
/* 0C6EAC 7F09237C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlocklevel:
/* 0C6EB0 7F092380 3C028003 */  lui   $v0, %hi(selected_folder_num)
/* 0C6EB4 7F092384 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
/* 0C6EB8 7F092388 8C440000 */  lw    $a0, ($v0)
/* 0C6EBC 7F09238C 24C8FFC9 */  addiu $t0, $a2, -0x37
/* 0C6EC0 7F092390 04800025 */  bltz  $a0, .L7F092428
/* 0C6EC4 7F092394 28810004 */   slti  $at, $a0, 4
/* 0C6EC8 7F092398 10200023 */  beqz  $at, .L7F092428
/* 0C6ECC 7F09239C 00001825 */   move  $v1, $zero
/* 0C6ED0 7F0923A0 19000014 */  blez  $t0, .L7F0923F4
/* 0C6ED4 7F0923A4 00002825 */   move  $a1, $zero
.L7F0923A8:
/* 0C6ED8 7F0923A8 3C028003 */  lui   $v0, %hi(selected_folder_num)
/* 0C6EDC 7F0923AC 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
/* 0C6EE0 7F0923B0 8C440000 */  lw    $a0, ($v0)
/* 0C6EE4 7F0923B4 00003025 */  move  $a2, $zero
/* 0C6EE8 7F0923B8 AFA30018 */  sw    $v1, 0x18($sp)
/* 0C6EEC 7F0923BC AFA5001C */  sw    $a1, 0x1c($sp)
/* 0C6EF0 7F0923C0 0FC078B0 */  jal   isStageUnlockedAtDifficulty
/* 0C6EF4 7F0923C4 AFA80020 */   sw    $t0, 0x20($sp)
/* 0C6EF8 7F0923C8 24010003 */  li    $at, 3
/* 0C6EFC 7F0923CC 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C6F00 7F0923D0 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0C6F04 7F0923D4 14410002 */  bne   $v0, $at, .L7F0923E0
/* 0C6F08 7F0923D8 8FA80020 */   lw    $t0, 0x20($sp)
/* 0C6F0C 7F0923DC 24630001 */  addiu $v1, $v1, 1
.L7F0923E0:
/* 0C6F10 7F0923E0 24A50001 */  addiu $a1, $a1, 1
/* 0C6F14 7F0923E4 14A8FFF0 */  bne   $a1, $t0, .L7F0923A8
/* 0C6F18 7F0923E8 00000000 */   nop   
/* 0C6F1C 7F0923EC 3C028003 */  lui   $v0, %hi(selected_folder_num)
/* 0C6F20 7F0923F0 2442A8E8 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x5718
.L7F0923F4:
/* 0C6F24 7F0923F4 246F0001 */  addiu $t7, $v1, 1
/* 0C6F28 7F0923F8 150F000B */  bne   $t0, $t7, .L7F092428
/* 0C6F2C 7F0923FC 2505FFFF */   addiu $a1, $t0, -1
/* 0C6F30 7F092400 3C0705F5 */  lui   $a3, (0x05F5E0FF >> 16) # lui $a3, 0x5f5
/* 0C6F34 7F092404 34E7E0FF */  ori   $a3, (0x05F5E0FF & 0xFFFF) # ori $a3, $a3, 0xe0ff
/* 0C6F38 7F092408 8C440000 */  lw    $a0, ($v0)
/* 0C6F3C 7F09240C 0FC0797E */  jal   unlock_stage_in_folder_on_difficulty
/* 0C6F40 7F092410 00003025 */   move  $a2, $zero
/* 0C6F44 7F092414 3C048006 */  lui   $a0, %hi(ptr_sfx_buf)
/* 0C6F48 7F092418 8C843720 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C6F4C 7F09241C 2405009F */  li    $a1, 159
/* 0C6F50 7F092420 0C002382 */  jal   play_sfx_a1
/* 0C6F54 7F092424 00003025 */   move  $a2, $zero
cheats_debug_return_saved_ra:
.L7F092428:
/* 0C6F58 7F092428 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F09242C:
/* 0C6F5C 7F09242C 27BD0040 */  addiu $sp, $sp, 0x40
/* 0C6F60 7F092430 03E00008 */  jr    $ra
/* 0C6F64 7F092434 00000000 */   nop   
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
/*D:800572B0*/
glabel jpt_cheats_cheat
.word cheats_cheat_extra_mp_chars
.word cheats_cheat_invincibility
.word cheats_cheat_allguns
.word cheats_cheat_max_ammo
.word cheats_debug_return_saved_ra
.word cheats_cheat_deactivate_invincibility
.word cheats_cheat_linemode
.word cheats_cheat_2x_health
.word cheats_cheat_2x_armor
.word cheats_cheat_invisibility
.word cheats_cheat_infinite_ammo
.word cheats_cheat_dk_mode
.word cheats_cheat_extra_weapons
.word cheats_cheat_tiny_bond
.word cheats_cheat_paintball
.word cheats_cheat_10x_health
.word cheats_cheat_magnum
.word cheats_cheat_laser
.word cheats_cheat_goldengun
.word cheats_cheat_silverpp7
.word cheats_cheat_goldpp7
.word cheats_cheat_invisibility_mp
.word cheats_debug_return_saved_ra
.word cheats_cheat_fast
.word cheats_debug_pos
.word cheats_debug_fast_ani
.word cheats_debug_slow_ani
.word cheats_debug_return_saved_ra
.word cheats_debug_2x_rockets
.word cheats_debug_2x_grenade_launch
.word cheats_debug_2x_rcp90
.word cheats_debug_2x_throwing_knife
.word cheats_debug_2x_hunting_knife
.word cheats_debug_2x_laser
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlockcheat
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel
.word cheats_debug_unlocklevel

/*800573D8*/
glabel finalamount
.word 0x3d4ccccd /*0.050000001*/

.text
glabel handle_cheats_turned_on
/* 0C71B4 7F092644 00047100 */  sll   $t6, $a0, 4
/* 0C71B8 7F092648 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C71BC 7F09264C 01EE7821 */  addu  $t7, $t7, $t6
/* 0C71C0 7F092650 8DEFF838 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C71C4 7F092654 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0C71C8 7F092658 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C71CC 7F09265C AFA40040 */  sw    $a0, 0x40($sp)
/* 0C71D0 7F092660 0FC26F3C */  jal   get_cur_playernum
/* 0C71D4 7F092664 AFAF003C */   sw    $t7, 0x3c($sp)
/* 0C71D8 7F092668 0FC26C01 */  jal   getPlayerCount
/* 0C71DC 7F09266C AFA20038 */   sw    $v0, 0x38($sp)
/* 0C71E0 7F092670 8FA3003C */  lw    $v1, 0x3c($sp)
/* 0C71E4 7F092674 8FA60040 */  lw    $a2, 0x40($sp)
/* 0C71E8 7F092678 AFA20034 */  sw    $v0, 0x34($sp)
/* 0C71EC 7F09267C 30780010 */  andi  $t8, $v1, 0x10
/* 0C71F0 7F092680 17000012 */  bnez  $t8, .Ljp7F0926CC
/* 0C71F4 7F092684 30790020 */   andi  $t9, $v1, 0x20
/* 0C71F8 7F092688 1720000A */  bnez  $t9, .Ljp7F0926B4
/* 0C71FC 7F09268C 8FA50038 */   lw    $a1, 0x38($sp)
/* 0C7200 7F092690 3C098008 */  lui   $t1, %hi(off_CODE_bss_80079E30) # $t1, 0x8008
/* 0C7204 7F092694 25299EA0 */  addiu $t1, %lo(off_CODE_bss_80079E30) # addiu $t1, $t1, -0x6160
/* 0C7208 7F092698 00C91821 */  addu  $v1, $a2, $t1
/* 0C720C 7F09269C 906A0000 */  lbu   $t2, ($v1)
/* 0C7210 7F0926A0 240B0001 */  li    $t3, 1
/* 0C7214 7F0926A4 00AB6004 */  sllv  $t4, $t3, $a1
/* 0C7218 7F0926A8 014C6825 */  or    $t5, $t2, $t4
/* 0C721C 7F0926AC 10000007 */  b     .Ljp7F0926CC
/* 0C7220 7F0926B0 A06D0000 */   sb    $t5, ($v1)
.Ljp7F0926B4:
/* 0C7224 7F0926B4 240E0001 */  li    $t6, 1
/* 0C7228 7F0926B8 004E7804 */  sllv  $t7, $t6, $v0
/* 0C722C 7F0926BC 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30)
/* 0C7230 7F0926C0 00260821 */  addu  $at, $at, $a2
/* 0C7234 7F0926C4 25F8FFFF */  addiu $t8, $t7, -1
/* 0C7238 7F0926C8 A0389EA0 */  sb    $t8, %lo(off_CODE_bss_80079E30)($at)
.Ljp7F0926CC:
/* 0C723C 7F0926CC 24D9FFFF */  addiu $t9, $a2, -1
/* 0C7240 7F0926D0 2F21004A */  sltiu $at, $t9, 0x4a
/* 0C7244 7F0926D4 10200234 */  beqz  $at, .Ljp7F092FA8
/* 0C7248 7F0926D8 0019C880 */   sll   $t9, $t9, 2
/* 0C724C 7F0926DC 3C018005 */  lui   $at, %hi(jpt_cheats_cheat)
/* 0C7250 7F0926E0 00390821 */  addu  $at, $at, $t9
/* 0C7254 7F0926E4 8C3972E0 */  lw    $t9, %lo(jpt_cheats_cheat)($at)
/* 0C7258 7F0926E8 03200008 */  jr    $t9
/* 0C725C 7F0926EC 00000000 */   nop   
cheats_cheat_extra_mp_chars:
/* 0C7260 7F0926F0 0FC040B0 */  jal   unlock_all_mp_chars
/* 0C7264 7F0926F4 00000000 */   nop   
/* 0C7268 7F0926F8 1000022C */  b     .Ljp7F092FAC
/* 0C726C 7F0926FC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invincibility:
/* 0C7270 7F092700 0FC229A4 */  jal   get_bondata_invincible_flag
/* 0C7274 7F092704 00000000 */   nop   
/* 0C7278 7F092708 54400228 */  bnezl $v0, .Ljp7F092FAC
/* 0C727C 7F09270C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7280 7F092710 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7284 7F092714 3404B00F */   li    $a0, 45071
/* 0C7288 7F092718 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C728C 7F09271C 00402025 */   move  $a0, $v0
/* 0C7290 7F092720 0FC229A0 */  jal   set_bondata_invincible_flag
/* 0C7294 7F092724 24040001 */   li    $a0, 1
/* 0C7298 7F092728 10000220 */  b     .Ljp7F092FAC
/* 0C729C 7F09272C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_allguns:
/* 0C72A0 7F092730 0FC232CF */  jal   get_BONDdata_allguns_flag
/* 0C72A4 7F092734 00000000 */   nop   
/* 0C72A8 7F092738 5440021C */  bnezl $v0, .Ljp7F092FAC
/* 0C72AC 7F09273C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C72B0 7F092740 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C72B4 7F092744 3404B010 */   li    $a0, 45072
/* 0C72B8 7F092748 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C72BC 7F09274C 00402025 */   move  $a0, $v0
/* 0C72C0 7F092750 0FC232CB */  jal   set_BONDdata_allguns_flag
/* 0C72C4 7F092754 24040001 */   li    $a0, 1
/* 0C72C8 7F092758 10000214 */  b     .Ljp7F092FAC
/* 0C72CC 7F09275C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_max_ammo:
/* 0C72D0 7F092760 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C72D4 7F092764 3404B011 */   li    $a0, 45073
/* 0C72D8 7F092768 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C72DC 7F09276C 00402025 */   move  $a0, $v0
/* 0C72E0 7F092770 0FC1A637 */  jal   set_max_ammo_for_cur_player
/* 0C72E4 7F092774 00000000 */   nop   
/* 0C72E8 7F092778 1000020C */  b     .Ljp7F092FAC
/* 0C72EC 7F09277C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_deactivate_invincibility:
/* 0C72F0 7F092780 28410002 */  slti  $at, $v0, 2
/* 0C72F4 7F092784 14200208 */  bnez  $at, .Ljp7F092FA8
/* 0C72F8 7F092788 AFA0002C */   sw    $zero, 0x2c($sp)
/* 0C72FC 7F09278C 18400015 */  blez  $v0, .Ljp7F0927E4
/* 0C7300 7F092790 AFA00030 */   sw    $zero, 0x30($sp)
.Ljp7F092794:
/* 0C7304 7F092794 8FA50038 */  lw    $a1, 0x38($sp)
/* 0C7308 7F092798 8FA90030 */  lw    $t1, 0x30($sp)
/* 0C730C 7F09279C 1125000A */  beq   $t1, $a1, .Ljp7F0927C8
/* 0C7310 7F0927A0 00000000 */   nop   
/* 0C7314 7F0927A4 0FC26F2B */  jal   set_cur_player
/* 0C7318 7F0927A8 01202025 */   move  $a0, $t1
/* 0C731C 7F0927AC 0FC229A4 */  jal   get_bondata_invincible_flag
/* 0C7320 7F0927B0 00000000 */   nop   
/* 0C7324 7F0927B4 10400004 */  beqz  $v0, .Ljp7F0927C8
/* 0C7328 7F0927B8 00002025 */   move  $a0, $zero
/* 0C732C 7F0927BC 240B0001 */  li    $t3, 1
/* 0C7330 7F0927C0 0FC229A0 */  jal   set_bondata_invincible_flag
/* 0C7334 7F0927C4 AFAB002C */   sw    $t3, 0x2c($sp)
.Ljp7F0927C8:
/* 0C7338 7F0927C8 0FC26F2B */  jal   set_cur_player
/* 0C733C 7F0927CC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0C7340 7F0927D0 8FAA0030 */  lw    $t2, 0x30($sp)
/* 0C7344 7F0927D4 8FAD0034 */  lw    $t5, 0x34($sp)
/* 0C7348 7F0927D8 254C0001 */  addiu $t4, $t2, 1
/* 0C734C 7F0927DC 158DFFED */  bne   $t4, $t5, .Ljp7F092794
/* 0C7350 7F0927E0 AFAC0030 */   sw    $t4, 0x30($sp)
.Ljp7F0927E4:
/* 0C7354 7F0927E4 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0C7358 7F0927E8 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C735C 7F0927EC 2405009F */  li    $a1, 159
/* 0C7360 7F0927F0 11C001ED */  beqz  $t6, .Ljp7F092FA8
/* 0C7364 7F0927F4 00003025 */   move  $a2, $zero
/* 0C7368 7F0927F8 0C002386 */  jal   play_sfx_a1
/* 0C736C 7F0927FC 8C843760 */   lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C7370 7F092800 100001EA */  b     .Ljp7F092FAC
/* 0C7374 7F092804 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_linemode:
/* 0C7378 7F092808 0FC246B2 */  jal   set_debug_VisCVG_flag
/* 0C737C 7F09280C 24040001 */   li    $a0, 1
/* 0C7380 7F092810 100001E6 */  b     .Ljp7F092FAC
/* 0C7384 7F092814 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_2x_health:
/* 0C7388 7F092818 3C028008 */  lui   $v0, %hi(pPlayer) # $v0, 0x8008
/* 0C738C 7F09281C 8C42A120 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C7390 7F092820 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7394 7F092824 44812000 */  mtc1  $at, $f4
/* 0C7398 7F092828 C4462A3C */  lwc1  $f6, 0x2a3c($v0)
/* 0C739C 7F09282C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C73A0 7F092830 46062032 */  c.eq.s $f4, $f6
/* 0C73A4 7F092834 00000000 */  nop   
/* 0C73A8 7F092838 45010008 */  bc1t  .Ljp7F09285C
/* 0C73AC 7F09283C 00000000 */   nop   
/* 0C73B0 7F092840 C44800DC */  lwc1  $f8, 0xdc($v0)
/* 0C73B4 7F092844 44815000 */  mtc1  $at, $f10
/* 0C73B8 7F092848 00000000 */  nop   
/* 0C73BC 7F09284C 460A403C */  c.lt.s $f8, $f10
/* 0C73C0 7F092850 00000000 */  nop   
/* 0C73C4 7F092854 450201D5 */  bc1fl .Ljp7F092FAC
/* 0C73C8 7F092858 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F09285C:
/* 0C73CC 7F09285C 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C73D0 7F092860 3404B012 */   li    $a0, 45074
/* 0C73D4 7F092864 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C73D8 7F092868 00402025 */   move  $a0, $v0
/* 0C73DC 7F09286C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C73E0 7F092870 3C0F8008 */  lui   $t7, %hi(pPlayer) # $t7, 0x8008
/* 0C73E4 7F092874 8DEFA120 */  lw    $t7, %lo(pPlayer)($t7)
/* 0C73E8 7F092878 44818000 */  mtc1  $at, $f16
/* 0C73EC 7F09287C 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C73F0 7F092880 3C188008 */  lui   $t8, %hi(pPlayer) # $t8, 0x8008
/* 0C73F4 7F092884 E5F000DC */  swc1  $f16, 0xdc($t7)
/* 0C73F8 7F092888 8F18A120 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C73FC 7F09288C 44819000 */  mtc1  $at, $f18
/* 0C7400 7F092890 100001C5 */  b     .Ljp7F092FA8
/* 0C7404 7F092894 E7122A3C */   swc1  $f18, 0x2a3c($t8)
cheats_cheat_2x_armor:
/* 0C7408 7F092898 3C028008 */  lui   $v0, %hi(pPlayer) # $v0, 0x8008
/* 0C740C 7F09289C 8C42A120 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C7410 7F0928A0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7414 7F0928A4 44810000 */  mtc1  $at, $f0
/* 0C7418 7F0928A8 C4442A40 */  lwc1  $f4, 0x2a40($v0)
/* 0C741C 7F0928AC 46040032 */  c.eq.s $f0, $f4
/* 0C7420 7F0928B0 00000000 */  nop   
/* 0C7424 7F0928B4 45010006 */  bc1t  .Ljp7F0928D0
/* 0C7428 7F0928B8 00000000 */   nop   
/* 0C742C 7F0928BC C44600E0 */  lwc1  $f6, 0xe0($v0)
/* 0C7430 7F0928C0 4600303C */  c.lt.s $f6, $f0
/* 0C7434 7F0928C4 00000000 */  nop   
/* 0C7438 7F0928C8 450201B8 */  bc1fl .Ljp7F092FAC
/* 0C743C 7F0928CC 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0928D0:
/* 0C7440 7F0928D0 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7444 7F0928D4 3404B013 */   li    $a0, 45075
/* 0C7448 7F0928D8 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C744C 7F0928DC 00402025 */   move  $a0, $v0
/* 0C7450 7F0928E0 3C028008 */  lui   $v0, %hi(pPlayer) # $v0, 0x8008
/* 0C7454 7F0928E4 2442A120 */  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5ee0
/* 0C7458 7F0928E8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C745C 7F0928EC 44814000 */  mtc1  $at, $f8
/* 0C7460 7F0928F0 8C590000 */  lw    $t9, ($v0)
/* 0C7464 7F0928F4 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0C7468 7F0928F8 44815000 */  mtc1  $at, $f10
/* 0C746C 7F0928FC E72800E0 */  swc1  $f8, 0xe0($t9)
/* 0C7470 7F092900 8C490000 */  lw    $t1, ($v0)
/* 0C7474 7F092904 100001A8 */  b     .Ljp7F092FA8
/* 0C7478 7F092908 E52A2A40 */   swc1  $f10, 0x2a40($t1)
cheats_cheat_invisibility:
/* 0C747C 7F09290C 0FC229AB */  jal   get_invisible_to_guards_flag
/* 0C7480 7F092910 00000000 */   nop   
/* 0C7484 7F092914 504001A5 */  beql  $v0, $zero, .Ljp7F092FAC
/* 0C7488 7F092918 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C748C 7F09291C 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7490 7F092920 3404B014 */   li    $a0, 45076
/* 0C7494 7F092924 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C7498 7F092928 00402025 */   move  $a0, $v0
/* 0C749C 7F09292C 0FC229A8 */  jal   set_invisible_to_guards_flag
/* 0C74A0 7F092930 00002025 */   move  $a0, $zero
/* 0C74A4 7F092934 1000019D */  b     .Ljp7F092FAC
/* 0C74A8 7F092938 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_infinite_ammo:
/* 0C74AC 7F09293C 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C74B0 7F092940 3404B016 */   li    $a0, 45078
/* 0C74B4 7F092944 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C74B8 7F092948 00402025 */   move  $a0, $v0
/* 0C74BC 7F09294C 10000197 */  b     .Ljp7F092FAC
/* 0C74C0 7F092950 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_dk_mode:
/* 0C74C4 7F092954 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C74C8 7F092958 3404B017 */   li    $a0, 45079
/* 0C74CC 7F09295C 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C74D0 7F092960 00402025 */   move  $a0, $v0
/* 0C74D4 7F092964 0FC24CDD */  jal   set_DKMode
/* 0C74D8 7F092968 24040001 */   li    $a0, 1
/* 0C74DC 7F09296C 1000018F */  b     .Ljp7F092FAC
/* 0C74E0 7F092970 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_extra_weapons:
/* 0C74E4 7F092974 24010001 */  li    $at, 1
/* 0C74E8 7F092978 5441018C */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C74EC 7F09297C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C74F0 7F092980 0FC2335A */  jal   add_item_to_inventory
/* 0C74F4 7F092984 24040012 */   li    $a0, 18
/* 0C74F8 7F092988 AFA20028 */  sw    $v0, 0x28($sp)
/* 0C74FC 7F09298C 0FC2335A */  jal   add_item_to_inventory
/* 0C7500 7F092990 24040016 */   li    $a0, 22
/* 0C7504 7F092994 8FAB0028 */  lw    $t3, 0x28($sp)
/* 0C7508 7F092998 24040013 */  li    $a0, 19
/* 0C750C 7F09299C 01625021 */  addu  $t2, $t3, $v0
/* 0C7510 7F0929A0 0FC2335A */  jal   add_item_to_inventory
/* 0C7514 7F0929A4 AFAA0028 */   sw    $t2, 0x28($sp)
/* 0C7518 7F0929A8 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0C751C 7F0929AC 24040014 */  li    $a0, 20
/* 0C7520 7F0929B0 01826821 */  addu  $t5, $t4, $v0
/* 0C7524 7F0929B4 0FC2335A */  jal   add_item_to_inventory
/* 0C7528 7F0929B8 AFAD0028 */   sw    $t5, 0x28($sp)
/* 0C752C 7F0929BC 8FAE0028 */  lw    $t6, 0x28($sp)
/* 0C7530 7F0929C0 24040015 */  li    $a0, 21
/* 0C7534 7F0929C4 01C27821 */  addu  $t7, $t6, $v0
/* 0C7538 7F0929C8 0FC2335A */  jal   add_item_to_inventory
/* 0C753C 7F0929CC AFAF0028 */   sw    $t7, 0x28($sp)
/* 0C7540 7F0929D0 8FB80028 */  lw    $t8, 0x28($sp)
/* 0C7544 7F0929D4 2404000C */  li    $a0, 12
/* 0C7548 7F0929D8 0302C821 */  addu  $t9, $t8, $v0
/* 0C754C 7F0929DC 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C7550 7F0929E0 AFB90028 */   sw    $t9, 0x28($sp)
/* 0C7554 7F0929E4 2404000C */  li    $a0, 12
/* 0C7558 7F0929E8 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C755C 7F0929EC 00402825 */   move  $a1, $v0
/* 0C7560 7F0929F0 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C7564 7F0929F4 2404000D */   li    $a0, 13
/* 0C7568 7F0929F8 2404000D */  li    $a0, 13
/* 0C756C 7F0929FC 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C7570 7F092A00 00402825 */   move  $a1, $v0
/* 0C7574 7F092A04 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C7578 7F092A08 24040001 */   li    $a0, 1
/* 0C757C 7F092A0C 24040001 */  li    $a0, 1
/* 0C7580 7F092A10 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C7584 7F092A14 00402825 */   move  $a1, $v0
/* 0C7588 7F092A18 8FA90028 */  lw    $t1, 0x28($sp)
/* 0C758C 7F092A1C 59200163 */  blezl $t1, .Ljp7F092FAC
/* 0C7590 7F092A20 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7594 7F092A24 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7598 7F092A28 3404B018 */   li    $a0, 45080
/* 0C759C 7F092A2C 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C75A0 7F092A30 00402025 */   move  $a0, $v0
/* 0C75A4 7F092A34 1000015D */  b     .Ljp7F092FAC
/* 0C75A8 7F092A38 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_tiny_bond:
/* 0C75AC 7F092A3C 24010001 */  li    $at, 1
/* 0C75B0 7F092A40 14410159 */  bne   $v0, $at, .Ljp7F092FA8
/* 0C75B4 7F092A44 3C0B8008 */   lui   $t3, %hi(pPlayersPerm) # $t3, 0x8008
/* 0C75B8 7F092A48 8D6BA124 */  lw    $t3, %lo(pPlayersPerm)($t3)
/* 0C75BC 7F092A4C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C75C0 7F092A50 44818000 */  mtc1  $at, $f16
/* 0C75C4 7F092A54 C5720064 */  lwc1  $f18, 0x64($t3)
/* 0C75C8 7F092A58 46128032 */  c.eq.s $f16, $f18
/* 0C75CC 7F092A5C 00000000 */  nop   
/* 0C75D0 7F092A60 45020152 */  bc1fl .Ljp7F092FAC
/* 0C75D4 7F092A64 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C75D8 7F092A68 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C75DC 7F092A6C 3404B019 */   li    $a0, 45081
/* 0C75E0 7F092A70 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C75E4 7F092A74 00402025 */   move  $a0, $v0
/* 0C75E8 7F092A78 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C75EC 7F092A7C 3C0A8008 */  lui   $t2, %hi(pPlayersPerm) # $t2, 0x8008
/* 0C75F0 7F092A80 44810000 */  mtc1  $at, $f0
/* 0C75F4 7F092A84 8D4AA124 */  lw    $t2, %lo(pPlayersPerm)($t2)
/* 0C75F8 7F092A88 3C0C8008 */  lui   $t4, %hi(pPlayer) # $t4, 0x8008
/* 0C75FC 7F092A8C E5400064 */  swc1  $f0, 0x64($t2)
/* 0C7600 7F092A90 8D8CA120 */  lw    $t4, %lo(pPlayer)($t4)
/* 0C7604 7F092A94 8D8400D4 */  lw    $a0, 0xd4($t4)
/* 0C7608 7F092A98 50800144 */  beql  $a0, $zero, .Ljp7F092FAC
/* 0C760C 7F092A9C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7610 7F092AA0 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C7614 7F092AA4 46002182 */  mul.s $f6, $f4, $f0
/* 0C7618 7F092AA8 44053000 */  mfc1  $a1, $f6
/* 0C761C 7F092AAC 0FC1B51A */  jal   set_obj_instance_controller_scale
/* 0C7620 7F092AB0 00000000 */   nop   
/* 0C7624 7F092AB4 1000013D */  b     .Ljp7F092FAC
/* 0C7628 7F092AB8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_paintball:
/* 0C762C 7F092ABC 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7630 7F092AC0 3404B01A */   li    $a0, 45082
/* 0C7634 7F092AC4 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C7638 7F092AC8 00402025 */   move  $a0, $v0
/* 0C763C 7F092ACC 10000137 */  b     .Ljp7F092FAC
/* 0C7640 7F092AD0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_10x_health:
/* 0C7644 7F092AD4 3C028008 */  lui   $v0, %hi(pPlayer) # $v0, 0x8008
/* 0C7648 7F092AD8 8C42A120 */  lw    $v0, %lo(pPlayer)($v0)
/* 0C764C 7F092ADC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7650 7F092AE0 44810000 */  mtc1  $at, $f0
/* 0C7654 7F092AE4 C4482A3C */  lwc1  $f8, 0x2a3c($v0)
/* 0C7658 7F092AE8 46080032 */  c.eq.s $f0, $f8
/* 0C765C 7F092AEC 00000000 */  nop   
/* 0C7660 7F092AF0 45010006 */  bc1t  .Ljp7F092B0C
/* 0C7664 7F092AF4 00000000 */   nop   
/* 0C7668 7F092AF8 C44A00DC */  lwc1  $f10, 0xdc($v0)
/* 0C766C 7F092AFC 4600503C */  c.lt.s $f10, $f0
/* 0C7670 7F092B00 00000000 */  nop   
/* 0C7674 7F092B04 45020129 */  bc1fl .Ljp7F092FAC
/* 0C7678 7F092B08 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F092B0C:
/* 0C767C 7F092B0C 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7680 7F092B10 3404B01B */   li    $a0, 45083
/* 0C7684 7F092B14 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C7688 7F092B18 00402025 */   move  $a0, $v0
/* 0C768C 7F092B1C 3C028008 */  lui   $v0, %hi(pPlayer) # $v0, 0x8008
/* 0C7690 7F092B20 2442A120 */  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5ee0
/* 0C7694 7F092B24 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7698 7F092B28 44818000 */  mtc1  $at, $f16
/* 0C769C 7F092B2C 8C4D0000 */  lw    $t5, ($v0)
/* 0C76A0 7F092B30 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0C76A4 7F092B34 44819000 */  mtc1  $at, $f18
/* 0C76A8 7F092B38 E5B000DC */  swc1  $f16, 0xdc($t5)
/* 0C76AC 7F092B3C 8C4E0000 */  lw    $t6, ($v0)
/* 0C76B0 7F092B40 10000119 */  b     .Ljp7F092FA8
/* 0C76B4 7F092B44 E5D22A3C */   swc1  $f18, 0x2a3c($t6)
cheats_cheat_magnum:
/* 0C76B8 7F092B48 24010001 */  li    $at, 1
/* 0C76BC 7F092B4C 54410117 */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C76C0 7F092B50 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C76C4 7F092B54 0FC2335A */  jal   add_item_to_inventory
/* 0C76C8 7F092B58 24040012 */   li    $a0, 18
/* 0C76CC 7F092B5C 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C76D0 7F092B60 2404000C */   li    $a0, 12
/* 0C76D4 7F092B64 2404000C */  li    $a0, 12
/* 0C76D8 7F092B68 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C76DC 7F092B6C 00402825 */   move  $a1, $v0
/* 0C76E0 7F092B70 1000010E */  b     .Ljp7F092FAC
/* 0C76E4 7F092B74 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_laser:
/* 0C76E8 7F092B78 24010001 */  li    $at, 1
/* 0C76EC 7F092B7C 5441010B */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C76F0 7F092B80 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C76F4 7F092B84 0FC2335A */  jal   add_item_to_inventory
/* 0C76F8 7F092B88 24040016 */   li    $a0, 22
/* 0C76FC 7F092B8C 10000107 */  b     .Ljp7F092FAC
/* 0C7700 7F092B90 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldengun:
/* 0C7704 7F092B94 24010001 */  li    $at, 1
/* 0C7708 7F092B98 54410104 */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C770C 7F092B9C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7710 7F092BA0 0FC2335A */  jal   add_item_to_inventory
/* 0C7714 7F092BA4 24040013 */   li    $a0, 19
/* 0C7718 7F092BA8 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C771C 7F092BAC 2404000D */   li    $a0, 13
/* 0C7720 7F092BB0 2404000D */  li    $a0, 13
/* 0C7724 7F092BB4 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C7728 7F092BB8 00402825 */   move  $a1, $v0
/* 0C772C 7F092BBC 100000FB */  b     .Ljp7F092FAC
/* 0C7730 7F092BC0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_silverpp7:
/* 0C7734 7F092BC4 24010001 */  li    $at, 1
/* 0C7738 7F092BC8 544100F8 */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C773C 7F092BCC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7740 7F092BD0 0FC2335A */  jal   add_item_to_inventory
/* 0C7744 7F092BD4 24040014 */   li    $a0, 20
/* 0C7748 7F092BD8 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C774C 7F092BDC 24040001 */   li    $a0, 1
/* 0C7750 7F092BE0 24040001 */  li    $a0, 1
/* 0C7754 7F092BE4 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C7758 7F092BE8 00402825 */   move  $a1, $v0
/* 0C775C 7F092BEC 100000EF */  b     .Ljp7F092FAC
/* 0C7760 7F092BF0 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_goldpp7:
/* 0C7764 7F092BF4 24010001 */  li    $at, 1
/* 0C7768 7F092BF8 544100EC */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C776C 7F092BFC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7770 7F092C00 0FC2335A */  jal   add_item_to_inventory
/* 0C7774 7F092C04 24040015 */   li    $a0, 21
/* 0C7778 7F092C08 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C777C 7F092C0C 24040001 */   li    $a0, 1
/* 0C7780 7F092C10 24040001 */  li    $a0, 1
/* 0C7784 7F092C14 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C7788 7F092C18 00402825 */   move  $a1, $v0
/* 0C778C 7F092C1C 100000E3 */  b     .Ljp7F092FAC
/* 0C7790 7F092C20 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_invisibility_mp:
/* 0C7794 7F092C24 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C7798 7F092C28 44816000 */  mtc1  $at, $f12
/* 0C779C 7F092C2C 3C018005 */  lui   $at, %hi(finalamount) # $at, 0x8005
/* 0C77A0 7F092C30 0FC20408 */  jal   currentPlayerStartChrFade
/* 0C77A4 7F092C34 C42E7408 */   lwc1  $f14, %lo(finalamount)($at)
/* 0C77A8 7F092C38 100000DC */  b     .Ljp7F092FAC
/* 0C77AC 7F092C3C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_cheat_fast:
/* 0C77B0 7F092C40 0FC246BE */  jal   get_debug_fast_bond_flag
/* 0C77B4 7F092C44 00000000 */   nop   
/* 0C77B8 7F092C48 544000D8 */  bnezl $v0, .Ljp7F092FAC
/* 0C77BC 7F092C4C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C77C0 7F092C50 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C77C4 7F092C54 3404B01D */   li    $a0, 45085
/* 0C77C8 7F092C58 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C77CC 7F092C5C 00402025 */   move  $a0, $v0
/* 0C77D0 7F092C60 0FC246C1 */  jal   set_debug_fast_bond_flag
/* 0C77D4 7F092C64 24040001 */   li    $a0, 1
/* 0C77D8 7F092C68 100000D0 */  b     .Ljp7F092FAC
/* 0C77DC 7F092C6C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_pos:
/* 0C77E0 7F092C70 0FC2469A */  jal   get_debug_testingmanpos_flag
/* 0C77E4 7F092C74 00000000 */   nop   
/* 0C77E8 7F092C78 544000CC */  bnezl $v0, .Ljp7F092FAC
/* 0C77EC 7F092C7C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C77F0 7F092C80 0FC2469D */  jal   set_debug_testingmanpos_flag
/* 0C77F4 7F092C84 24040001 */   li    $a0, 1
/* 0C77F8 7F092C88 100000C8 */  b     .Ljp7F092FAC
/* 0C77FC 7F092C8C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_fast_ani:
/* 0C7800 7F092C90 0FC081E5 */  jal   get_animation_rate
/* 0C7804 7F092C94 00000000 */   nop   
/* 0C7808 7F092C98 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C780C 7F092C9C 44812000 */  mtc1  $at, $f4
/* 0C7810 7F092CA0 00000000 */  nop   
/* 0C7814 7F092CA4 4604003C */  c.lt.s $f0, $f4
/* 0C7818 7F092CA8 00000000 */  nop   
/* 0C781C 7F092CAC 450200BF */  bc1fl .Ljp7F092FAC
/* 0C7820 7F092CB0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7824 7F092CB4 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7828 7F092CB8 3404B034 */   li    $a0, 45108
/* 0C782C 7F092CBC 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C7830 7F092CC0 00402025 */   move  $a0, $v0
/* 0C7834 7F092CC4 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 0C7838 7F092CC8 44816000 */  mtc1  $at, $f12
/* 0C783C 7F092CCC 0FC081BC */  jal   animation_speed_related
/* 0C7840 7F092CD0 00000000 */   nop   
/* 0C7844 7F092CD4 100000B5 */  b     .Ljp7F092FAC
/* 0C7848 7F092CD8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_slow_ani:
/* 0C784C 7F092CDC 0FC081E5 */  jal   get_animation_rate
/* 0C7850 7F092CE0 00000000 */   nop   
/* 0C7854 7F092CE4 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C7858 7F092CE8 44813000 */  mtc1  $at, $f6
/* 0C785C 7F092CEC 00000000 */  nop   
/* 0C7860 7F092CF0 4600303C */  c.lt.s $f6, $f0
/* 0C7864 7F092CF4 00000000 */  nop   
/* 0C7868 7F092CF8 450200AC */  bc1fl .Ljp7F092FAC
/* 0C786C 7F092CFC 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7870 7F092D00 0FC30AA2 */  jal   get_textptr_for_textID
/* 0C7874 7F092D04 3404B032 */   li    $a0, 45106
/* 0C7878 7F092D08 0FC22B10 */  jal   jp_display_string_in_lower_left_corner
/* 0C787C 7F092D0C 00402025 */   move  $a0, $v0
/* 0C7880 7F092D10 3C013E80 */  li    $at, 0x3E800000 # 0.250000
/* 0C7884 7F092D14 44816000 */  mtc1  $at, $f12
/* 0C7888 7F092D18 0FC081BC */  jal   animation_speed_related
/* 0C788C 7F092D1C 00000000 */   nop   
/* 0C7890 7F092D20 100000A2 */  b     .Ljp7F092FAC
/* 0C7894 7F092D24 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rockets:
/* 0C7898 7F092D28 24010001 */  li    $at, 1
/* 0C789C 7F092D2C 5441009F */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C78A0 7F092D30 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C78A4 7F092D34 0FC2335A */  jal   add_item_to_inventory
/* 0C78A8 7F092D38 24040019 */   li    $a0, 25
/* 0C78AC 7F092D3C 24040019 */  li    $a0, 25
/* 0C78B0 7F092D40 0FC23381 */  jal   add_doubles_item_to_inventory
/* 0C78B4 7F092D44 24050019 */   li    $a1, 25
/* 0C78B8 7F092D48 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C78BC 7F092D4C 24040006 */   li    $a0, 6
/* 0C78C0 7F092D50 24040006 */  li    $a0, 6
/* 0C78C4 7F092D54 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C78C8 7F092D58 00402825 */   move  $a1, $v0
/* 0C78CC 7F092D5C 10000093 */  b     .Ljp7F092FAC
/* 0C78D0 7F092D60 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_grenade_launch:
/* 0C78D4 7F092D64 24010001 */  li    $at, 1
/* 0C78D8 7F092D68 54410090 */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C78DC 7F092D6C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C78E0 7F092D70 0FC2335A */  jal   add_item_to_inventory
/* 0C78E4 7F092D74 24040018 */   li    $a0, 24
/* 0C78E8 7F092D78 24040018 */  li    $a0, 24
/* 0C78EC 7F092D7C 0FC23381 */  jal   add_doubles_item_to_inventory
/* 0C78F0 7F092D80 24050018 */   li    $a1, 24
/* 0C78F4 7F092D84 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C78F8 7F092D88 2404000B */   li    $a0, 11
/* 0C78FC 7F092D8C 2404000B */  li    $a0, 11
/* 0C7900 7F092D90 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C7904 7F092D94 00402825 */   move  $a1, $v0
/* 0C7908 7F092D98 10000084 */  b     .Ljp7F092FAC
/* 0C790C 7F092D9C 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_rcp90:
/* 0C7910 7F092DA0 24010001 */  li    $at, 1
/* 0C7914 7F092DA4 54410081 */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C7918 7F092DA8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C791C 7F092DAC 0FC2335A */  jal   add_item_to_inventory
/* 0C7920 7F092DB0 2404000E */   li    $a0, 14
/* 0C7924 7F092DB4 2404000E */  li    $a0, 14
/* 0C7928 7F092DB8 0FC23381 */  jal   add_doubles_item_to_inventory
/* 0C792C 7F092DBC 2405000E */   li    $a1, 14
/* 0C7930 7F092DC0 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C7934 7F092DC4 24040001 */   li    $a0, 1
/* 0C7938 7F092DC8 24040001 */  li    $a0, 1
/* 0C793C 7F092DCC 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C7940 7F092DD0 00402825 */   move  $a1, $v0
/* 0C7944 7F092DD4 10000075 */  b     .Ljp7F092FAC
/* 0C7948 7F092DD8 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_throwing_knife:
/* 0C794C 7F092DDC 24010001 */  li    $at, 1
/* 0C7950 7F092DE0 54410072 */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C7954 7F092DE4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7958 7F092DE8 0FC2335A */  jal   add_item_to_inventory
/* 0C795C 7F092DEC 24040003 */   li    $a0, 3
/* 0C7960 7F092DF0 24040003 */  li    $a0, 3
/* 0C7964 7F092DF4 0FC23381 */  jal   add_doubles_item_to_inventory
/* 0C7968 7F092DF8 24050003 */   li    $a1, 3
/* 0C796C 7F092DFC 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C7970 7F092E00 2404000A */   li    $a0, 10
/* 0C7974 7F092E04 2404000A */  li    $a0, 10
/* 0C7978 7F092E08 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C797C 7F092E0C 00402825 */   move  $a1, $v0
/* 0C7980 7F092E10 10000066 */  b     .Ljp7F092FAC
/* 0C7984 7F092E14 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_hunting_knife:
/* 0C7988 7F092E18 24010001 */  li    $at, 1
/* 0C798C 7F092E1C 14410062 */  bne   $v0, $at, .Ljp7F092FA8
/* 0C7990 7F092E20 3C0F8005 */   lui   $t7, %hi(j_text_trigger) # $t7, 0x8005
/* 0C7994 7F092E24 8DEF8500 */  lw    $t7, %lo(j_text_trigger)($t7)
/* 0C7998 7F092E28 11E00014 */  beqz  $t7, .cheats_debug_2x_hunting_knife_en
/* 0C799C 7F092E2C 00000000 */   nop   
/* 0C79A0 7F092E30 0FC2335A */  jal   add_item_to_inventory
/* 0C79A4 7F092E34 24040019 */   li    $a0, 25
/* 0C79A8 7F092E38 0FC2335A */  jal   add_item_to_inventory
/* 0C79AC 7F092E3C 24040011 */   li    $a0, 17
/* 0C79B0 7F092E40 24040011 */  li    $a0, 17
/* 0C79B4 7F092E44 0FC23381 */  jal   add_doubles_item_to_inventory
/* 0C79B8 7F092E48 24050019 */   li    $a1, 25
/* 0C79BC 7F092E4C 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C79C0 7F092E50 24040006 */   li    $a0, 6
/* 0C79C4 7F092E54 24040006 */  li    $a0, 6
/* 0C79C8 7F092E58 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C79CC 7F092E5C 00402825 */   move  $a1, $v0
/* 0C79D0 7F092E60 0FC1A630 */  jal   get_max_ammo_for_type
/* 0C79D4 7F092E64 24040003 */   li    $a0, 3
/* 0C79D8 7F092E68 24040003 */  li    $a0, 3
/* 0C79DC 7F092E6C 0FC1A5C7 */  jal   give_cur_player_ammo
/* 0C79E0 7F092E70 00402825 */   move  $a1, $v0
/* 0C79E4 7F092E74 1000004D */  b     .Ljp7F092FAC
/* 0C79E8 7F092E78 8FBF0014 */   lw    $ra, 0x14($sp)
.cheats_debug_2x_hunting_knife_en:
/* 0C79EC 7F092E7C 0FC2335A */  jal   add_item_to_inventory
/* 0C79F0 7F092E80 24040002 */   li    $a0, 2
/* 0C79F4 7F092E84 24040002 */  li    $a0, 2
/* 0C79F8 7F092E88 0FC23381 */  jal   add_doubles_item_to_inventory
/* 0C79FC 7F092E8C 24050002 */   li    $a1, 2
/* 0C7A00 7F092E90 10000046 */  b     .Ljp7F092FAC
/* 0C7A04 7F092E94 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_2x_laser:
/* 0C7A08 7F092E98 24010001 */  li    $at, 1
/* 0C7A0C 7F092E9C 54410043 */  bnel  $v0, $at, .Ljp7F092FAC
/* 0C7A10 7F092EA0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7A14 7F092EA4 0FC2335A */  jal   add_item_to_inventory
/* 0C7A18 7F092EA8 24040016 */   li    $a0, 22
/* 0C7A1C 7F092EAC 24040016 */  li    $a0, 22
/* 0C7A20 7F092EB0 0FC23381 */  jal   add_doubles_item_to_inventory
/* 0C7A24 7F092EB4 24050016 */   li    $a1, 22
/* 0C7A28 7F092EB8 1000003C */  b     .Ljp7F092FAC
/* 0C7A2C 7F092EBC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlockcheat:
/* 0C7A30 7F092EC0 3C048003 */  lui   $a0, %hi(selected_folder_num) # $a0, 0x8003
/* 0C7A34 7F092EC4 8C84A928 */  lw    $a0, %lo(selected_folder_num)($a0)
/* 0C7A38 7F092EC8 24C5FFDD */  addiu $a1, $a2, -0x23
/* 0C7A3C 7F092ECC 04800036 */  bltz  $a0, .Ljp7F092FA8
/* 0C7A40 7F092ED0 28810004 */   slti  $at, $a0, 4
/* 0C7A44 7F092ED4 50200035 */  beql  $at, $zero, .Ljp7F092FAC
/* 0C7A48 7F092ED8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7A4C 7F092EDC 0FC07A44 */  jal   sub_GAME_7F01E760
/* 0C7A50 7F092EE0 00000000 */   nop   
/* 0C7A54 7F092EE4 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C7A58 7F092EE8 8C843760 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C7A5C 7F092EEC 2405009F */  li    $a1, 159
/* 0C7A60 7F092EF0 0C002386 */  jal   play_sfx_a1
/* 0C7A64 7F092EF4 00003025 */   move  $a2, $zero
/* 0C7A68 7F092EF8 1000002C */  b     .Ljp7F092FAC
/* 0C7A6C 7F092EFC 8FBF0014 */   lw    $ra, 0x14($sp)
cheats_debug_unlocklevel:
/* 0C7A70 7F092F00 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C7A74 7F092F04 2442A928 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x56d8
/* 0C7A78 7F092F08 8C440000 */  lw    $a0, ($v0)
/* 0C7A7C 7F092F0C 24C8FFC9 */  addiu $t0, $a2, -0x37
/* 0C7A80 7F092F10 04800025 */  bltz  $a0, .Ljp7F092FA8
/* 0C7A84 7F092F14 28810004 */   slti  $at, $a0, 4
/* 0C7A88 7F092F18 10200023 */  beqz  $at, .Ljp7F092FA8
/* 0C7A8C 7F092F1C 00001825 */   move  $v1, $zero
/* 0C7A90 7F092F20 19000014 */  blez  $t0, .Ljp7F092F74
/* 0C7A94 7F092F24 00002825 */   move  $a1, $zero
.Ljp7F092F28:
/* 0C7A98 7F092F28 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C7A9C 7F092F2C 2442A928 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x56d8
/* 0C7AA0 7F092F30 8C440000 */  lw    $a0, ($v0)
/* 0C7AA4 7F092F34 00003025 */  move  $a2, $zero
/* 0C7AA8 7F092F38 AFA30018 */  sw    $v1, 0x18($sp)
/* 0C7AAC 7F092F3C AFA5001C */  sw    $a1, 0x1c($sp)
/* 0C7AB0 7F092F40 0FC0791C */  jal   isStageUnlockedAtDifficulty
/* 0C7AB4 7F092F44 AFA80020 */   sw    $t0, 0x20($sp)
/* 0C7AB8 7F092F48 24010003 */  li    $at, 3
/* 0C7ABC 7F092F4C 8FA30018 */  lw    $v1, 0x18($sp)
/* 0C7AC0 7F092F50 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0C7AC4 7F092F54 14410002 */  bne   $v0, $at, .Ljp7F092F60
/* 0C7AC8 7F092F58 8FA80020 */   lw    $t0, 0x20($sp)
/* 0C7ACC 7F092F5C 24630001 */  addiu $v1, $v1, 1
.Ljp7F092F60:
/* 0C7AD0 7F092F60 24A50001 */  addiu $a1, $a1, 1
/* 0C7AD4 7F092F64 14A8FFF0 */  bne   $a1, $t0, .Ljp7F092F28
/* 0C7AD8 7F092F68 00000000 */   nop   
/* 0C7ADC 7F092F6C 3C028003 */  lui   $v0, %hi(selected_folder_num) # $v0, 0x8003
/* 0C7AE0 7F092F70 2442A928 */  addiu $v0, %lo(selected_folder_num) # addiu $v0, $v0, -0x56d8
.Ljp7F092F74:
/* 0C7AE4 7F092F74 24780001 */  addiu $t8, $v1, 1
/* 0C7AE8 7F092F78 1518000B */  bne   $t0, $t8, .Ljp7F092FA8
/* 0C7AEC 7F092F7C 2505FFFF */   addiu $a1, $t0, -1
/* 0C7AF0 7F092F80 3C0705F5 */  lui   $a3, (0x05F5E0FF >> 16) # lui $a3, 0x5f5
/* 0C7AF4 7F092F84 34E7E0FF */  ori   $a3, (0x05F5E0FF & 0xFFFF) # ori $a3, $a3, 0xe0ff
/* 0C7AF8 7F092F88 8C440000 */  lw    $a0, ($v0)
/* 0C7AFC 7F092F8C 0FC079EA */  jal   unlock_stage_in_folder_on_difficulty
/* 0C7B00 7F092F90 00003025 */   move  $a2, $zero
/* 0C7B04 7F092F94 3C048006 */  lui   $a0, %hi(ptr_sfx_buf) # $a0, 0x8006
/* 0C7B08 7F092F98 8C843760 */  lw    $a0, %lo(ptr_sfx_buf)($a0)
/* 0C7B0C 7F092F9C 2405009F */  li    $a1, 159
/* 0C7B10 7F092FA0 0C002386 */  jal   play_sfx_a1
/* 0C7B14 7F092FA4 00003025 */   move  $a2, $zero
cheats_debug_return_saved_ra:
.Ljp7F092FA8:
/* 0C7B18 7F092FA8 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F092FAC:
/* 0C7B1C 7F092FAC 27BD0040 */  addiu $sp, $sp, 0x40
/* 0C7B20 7F092FB0 03E00008 */  jr    $ra
/* 0C7B24 7F092FB4 00000000 */   nop       
)
#endif

#endif



#ifdef NONMATCHING
void cheatDisplayMessageActivateCheat(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
/*D:800573DC*/
glabel jpt_800573DC
.word cheat_button_default
.word cheat_button_invincibility
.word cheat_button_all_guns
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_line_mode
.word cheat_button_default
.word cheat_button_default
.word cheat_button_unknown
.word cheat_button_infinite_ammo
.word cheat_button_dkmode
.word cheat_button_default
.word cheat_button_unknown_0
.word cheat_button_paintball
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_mp_invis
.word cheat_button_default
.word cheat_button_fast_mode
.word cheat_button_debug_mode
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/

.text
glabel cheatDisplayMessageActivateCheat
/* 0C6F68 7F092438 00047100 */  sll   $t6, $a0, 4
/* 0C6F6C 7F09243C 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C6F70 7F092440 01EE7821 */  addu  $t7, $t7, $t6
/* 0C6F74 7F092444 8DEFF808 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C6F78 7F092448 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C6F7C 7F09244C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6F80 7F092450 AFA40020 */  sw    $a0, 0x20($sp)
/* 0C6F84 7F092454 0FC26C54 */  jal   get_cur_playernum
/* 0C6F88 7F092458 AFAF001C */   sw    $t7, 0x1c($sp)
/* 0C6F8C 7F09245C 0FC26919 */  jal   getPlayerCount
/* 0C6F90 7F092460 AFA20018 */   sw    $v0, 0x18($sp)
/* 0C6F94 7F092464 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0C6F98 7F092468 8FA40020 */  lw    $a0, 0x20($sp)
/* 0C6F9C 7F09246C 30780010 */  andi  $t8, $v1, 0x10
/* 0C6FA0 7F092470 17000010 */  bnez  $t8, .L7F0924B4
/* 0C6FA4 7F092474 30790020 */   andi  $t9, $v1, 0x20
/* 0C6FA8 7F092478 1720000B */  bnez  $t9, .L7F0924A8
/* 0C6FAC 7F09247C 3C088008 */   lui   $t0, %hi(off_CODE_bss_80079E30) 
/* 0C6FB0 7F092480 8FAA0018 */  lw    $t2, 0x18($sp)
/* 0C6FB4 7F092484 25089E30 */  addiu $t0, %lo(off_CODE_bss_80079E30) # addiu $t0, $t0, -0x61d0
/* 0C6FB8 7F092488 00881821 */  addu  $v1, $a0, $t0
/* 0C6FBC 7F09248C 90690000 */  lbu   $t1, ($v1)
/* 0C6FC0 7F092490 240B0001 */  li    $t3, 1
/* 0C6FC4 7F092494 014B6004 */  sllv  $t4, $t3, $t2
/* 0C6FC8 7F092498 01806827 */  not   $t5, $t4
/* 0C6FCC 7F09249C 012D7024 */  and   $t6, $t1, $t5
/* 0C6FD0 7F0924A0 10000004 */  b     .L7F0924B4
/* 0C6FD4 7F0924A4 A06E0000 */   sb    $t6, ($v1)
.L7F0924A8:
/* 0C6FD8 7F0924A8 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30)
/* 0C6FDC 7F0924AC 00240821 */  addu  $at, $at, $a0
/* 0C6FE0 7F0924B0 A0209E30 */  sb    $zero, %lo(off_CODE_bss_80079E30)($at)
.L7F0924B4:
/* 0C6FE4 7F0924B4 248FFFFF */  addiu $t7, $a0, -1
/* 0C6FE8 7F0924B8 2DE1004A */  sltiu $at, $t7, 0x4a
/* 0C6FEC 7F0924BC 1020007C */  beqz  $at, .L7F0926B0
/* 0C6FF0 7F0924C0 000F7880 */   sll   $t7, $t7, 2
/* 0C6FF4 7F0924C4 3C018005 */  lui   $at, %hi(jpt_800573DC)
/* 0C6FF8 7F0924C8 002F0821 */  addu  $at, $at, $t7
/* 0C6FFC 7F0924CC 8C2F73DC */  lw    $t7, %lo(jpt_800573DC)($at)
/* 0C7000 7F0924D0 01E00008 */  jr    $t7
/* 0C7004 7F0924D4 00000000 */   nop   
cheat_button_invincibility:
/* 0C7008 7F0924D8 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C700C 7F0924DC 00000000 */   nop   
/* 0C7010 7F0924E0 50400074 */  beql  $v0, $zero, .L7F0926B4
/* 0C7014 7F0924E4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7018 7F0924E8 0FC30776 */  jal   get_textptr_for_textID
/* 0C701C 7F0924EC 3404B01E */   li    $a0, 45086
/* 0C7020 7F0924F0 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7024 7F0924F4 00402025 */   move  $a0, $v0
/* 0C7028 7F0924F8 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C702C 7F0924FC 00002025 */   move  $a0, $zero
/* 0C7030 7F092500 1000006C */  b     .L7F0926B4
/* 0C7034 7F092504 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_all_guns:
/* 0C7038 7F092508 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C703C 7F09250C 00000000 */   nop   
/* 0C7040 7F092510 50400068 */  beql  $v0, $zero, .L7F0926B4
/* 0C7044 7F092514 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7048 7F092518 0FC30776 */  jal   get_textptr_for_textID
/* 0C704C 7F09251C 3404B01F */   li    $a0, 45087
/* 0C7050 7F092520 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7054 7F092524 00402025 */   move  $a0, $v0
/* 0C7058 7F092528 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C705C 7F09252C 00002025 */   move  $a0, $zero
/* 0C7060 7F092530 10000060 */  b     .L7F0926B4
/* 0C7064 7F092534 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_line_mode:
/* 0C7068 7F092538 0FC243FA */  jal   set_debug_VisCVG_flag
/* 0C706C 7F09253C 00002025 */   move  $a0, $zero
/* 0C7070 7F092540 1000005C */  b     .L7F0926B4
/* 0C7074 7F092544 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown:
/* 0C7078 7F092548 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C707C 7F09254C 00000000 */   nop   
/* 0C7080 7F092550 54400058 */  bnezl $v0, .L7F0926B4
/* 0C7084 7F092554 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7088 7F092558 0FC30776 */  jal   get_textptr_for_textID
/* 0C708C 7F09255C 3404B020 */   li    $a0, 45088
/* 0C7090 7F092560 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7094 7F092564 00402025 */   move  $a0, $v0
/* 0C7098 7F092568 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C709C 7F09256C 24040001 */   li    $a0, 1
/* 0C70A0 7F092570 10000050 */  b     .L7F0926B4
/* 0C70A4 7F092574 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_infinite_ammo:
/* 0C70A8 7F092578 0FC30776 */  jal   get_textptr_for_textID
/* 0C70AC 7F09257C 3404B022 */   li    $a0, 45090
/* 0C70B0 7F092580 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C70B4 7F092584 00402025 */   move  $a0, $v0
/* 0C70B8 7F092588 1000004A */  b     .L7F0926B4
/* 0C70BC 7F09258C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_dkmode:
/* 0C70C0 7F092590 0FC30776 */  jal   get_textptr_for_textID
/* 0C70C4 7F092594 3404B023 */   li    $a0, 45091
/* 0C70C8 7F092598 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C70CC 7F09259C 00402025 */   move  $a0, $v0
/* 0C70D0 7F0925A0 0FC249FD */  jal   set_DKMode
/* 0C70D4 7F0925A4 00002025 */   move  $a0, $zero
/* 0C70D8 7F0925A8 10000042 */  b     .L7F0926B4
/* 0C70DC 7F0925AC 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown_0:
/* 0C70E0 7F0925B0 24010001 */  li    $at, 1
/* 0C70E4 7F0925B4 1441003E */  bne   $v0, $at, .L7F0926B0
/* 0C70E8 7F0925B8 3C188008 */   lui   $t8, %hi(pPlayersPerm) 
/* 0C70EC 7F0925BC 8F18A0B4 */  lw    $t8, %lo(pPlayersPerm)($t8)
/* 0C70F0 7F0925C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C70F4 7F0925C4 44812000 */  mtc1  $at, $f4
/* 0C70F8 7F0925C8 C7060064 */  lwc1  $f6, 0x64($t8)
/* 0C70FC 7F0925CC 46062032 */  c.eq.s $f4, $f6
/* 0C7100 7F0925D0 00000000 */  nop   
/* 0C7104 7F0925D4 45030037 */  bc1tl .L7F0926B4
/* 0C7108 7F0925D8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C710C 7F0925DC 0FC30776 */  jal   get_textptr_for_textID
/* 0C7110 7F0925E0 3404B024 */   li    $a0, 45092
/* 0C7114 7F0925E4 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C7118 7F0925E8 00402025 */   move  $a0, $v0
/* 0C711C 7F0925EC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7120 7F0925F0 3C198008 */  lui   $t9, %hi(pPlayersPerm) 
/* 0C7124 7F0925F4 8F39A0B4 */  lw    $t9, %lo(pPlayersPerm)($t9)
/* 0C7128 7F0925F8 44814000 */  mtc1  $at, $f8
/* 0C712C 7F0925FC 3C088008 */  lui   $t0, %hi(pPlayer) 
/* 0C7130 7F092600 E7280064 */  swc1  $f8, 0x64($t9)
/* 0C7134 7F092604 8D08A0B0 */  lw    $t0, %lo(pPlayer)($t0)
/* 0C7138 7F092608 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0C713C 7F09260C 50800029 */  beql  $a0, $zero, .L7F0926B4
/* 0C7140 7F092610 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7144 7F092614 C4800014 */  lwc1  $f0, 0x14($a0)
/* 0C7148 7F092618 46000280 */  add.s $f10, $f0, $f0
/* 0C714C 7F09261C 44055000 */  mfc1  $a1, $f10
/* 0C7150 7F092620 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C7154 7F092624 00000000 */   nop   
/* 0C7158 7F092628 10000022 */  b     .L7F0926B4
/* 0C715C 7F09262C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_paintball:
/* 0C7160 7F092630 0FC30776 */  jal   get_textptr_for_textID
/* 0C7164 7F092634 3404B025 */   li    $a0, 45093
/* 0C7168 7F092638 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C716C 7F09263C 00402025 */   move  $a0, $v0
/* 0C7170 7F092640 1000001C */  b     .L7F0926B4
/* 0C7174 7F092644 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_mp_invis:
/* 0C7178 7F092648 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C717C 7F09264C 44816000 */  mtc1  $at, $f12
/* 0C7180 7F092650 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7184 7F092654 44817000 */  mtc1  $at, $f14
/* 0C7188 7F092658 0FC20284 */  jal   currentPlayerStartChrFade
/* 0C718C 7F09265C 00000000 */   nop   
/* 0C7190 7F092660 10000014 */  b     .L7F0926B4
/* 0C7194 7F092664 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_fast_mode:
/* 0C7198 7F092668 0FC24406 */  jal   get_debug_fast_bond_flag
/* 0C719C 7F09266C 00000000 */   nop   
/* 0C71A0 7F092670 50400010 */  beql  $v0, $zero, .L7F0926B4
/* 0C71A4 7F092674 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71A8 7F092678 0FC30776 */  jal   get_textptr_for_textID
/* 0C71AC 7F09267C 3404B027 */   li    $a0, 45095
/* 0C71B0 7F092680 0FC228F2 */  jal   display_string_in_lower_left_corner
/* 0C71B4 7F092684 00402025 */   move  $a0, $v0
/* 0C71B8 7F092688 0FC24409 */  jal   set_debug_fast_bond_flag
/* 0C71BC 7F09268C 00002025 */   move  $a0, $zero
/* 0C71C0 7F092690 10000008 */  b     .L7F0926B4
/* 0C71C4 7F092694 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_debug_mode:
/* 0C71C8 7F092698 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0C71CC 7F09269C 00000000 */   nop   
/* 0C71D0 7F0926A0 50400004 */  beql  $v0, $zero, .L7F0926B4
/* 0C71D4 7F0926A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71D8 7F0926A8 0FC243E5 */  jal   set_debug_testingmanpos_flag
/* 0C71DC 7F0926AC 00002025 */   move  $a0, $zero
cheat_button_default:
.L7F0926B0:
/* 0C71E0 7F0926B0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0926B4:
/* 0C71E4 7F0926B4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C71E8 7F0926B8 03E00008 */  jr    $ra
/* 0C71EC 7F0926BC 00000000 */   nop   
)
#endif
#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
/*D:800573DC*/
glabel jpt_800573DC
.word cheat_button_default
.word cheat_button_invincibility
.word cheat_button_all_guns
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_line_mode
.word cheat_button_default
.word cheat_button_default
.word cheat_button_unknown
.word cheat_button_infinite_ammo
.word cheat_button_dkmode
.word cheat_button_default
.word cheat_button_unknown_0
.word cheat_button_paintball
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_mp_invis
.word cheat_button_default
.word cheat_button_fast_mode
.word cheat_button_debug_mode
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/

.text
glabel cheatDisplayMessageActivateCheat
/* 0C6F68 7F092438 00047100 */  sll   $t6, $a0, 4
/* 0C6F6C 7F09243C 3C0F8004 */  lui   $t7, %hi(D_8003F808)
/* 0C6F70 7F092440 01EE7821 */  addu  $t7, $t7, $t6
/* 0C6F74 7F092444 8DEFF808 */  lw    $t7, %lo(D_8003F808)($t7)
/* 0C6F78 7F092448 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C6F7C 7F09244C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C6F80 7F092450 AFA40020 */  sw    $a0, 0x20($sp)
/* 0C6F84 7F092454 0FC26C54 */  jal   get_cur_playernum
/* 0C6F88 7F092458 AFAF001C */   sw    $t7, 0x1c($sp)
/* 0C6F8C 7F09245C 0FC26919 */  jal   getPlayerCount
/* 0C6F90 7F092460 AFA20018 */   sw    $v0, 0x18($sp)
/* 0C6F94 7F092464 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0C6F98 7F092468 8FA40020 */  lw    $a0, 0x20($sp)
/* 0C6F9C 7F09246C 30780010 */  andi  $t8, $v1, 0x10
/* 0C6FA0 7F092470 17000010 */  bnez  $t8, .L7F0924B4
/* 0C6FA4 7F092474 30790020 */   andi  $t9, $v1, 0x20
/* 0C6FA8 7F092478 1720000B */  bnez  $t9, .L7F0924A8
/* 0C6FAC 7F09247C 3C088008 */   lui   $t0, %hi(off_CODE_bss_80079E30) 
/* 0C6FB0 7F092480 8FAA0018 */  lw    $t2, 0x18($sp)
/* 0C6FB4 7F092484 25089E30 */  addiu $t0, %lo(off_CODE_bss_80079E30) # addiu $t0, $t0, -0x61d0
/* 0C6FB8 7F092488 00881821 */  addu  $v1, $a0, $t0
/* 0C6FBC 7F09248C 90690000 */  lbu   $t1, ($v1)
/* 0C6FC0 7F092490 240B0001 */  li    $t3, 1
/* 0C6FC4 7F092494 014B6004 */  sllv  $t4, $t3, $t2
/* 0C6FC8 7F092498 01806827 */  not   $t5, $t4
/* 0C6FCC 7F09249C 012D7024 */  and   $t6, $t1, $t5
/* 0C6FD0 7F0924A0 10000004 */  b     .L7F0924B4
/* 0C6FD4 7F0924A4 A06E0000 */   sb    $t6, ($v1)
.L7F0924A8:
/* 0C6FD8 7F0924A8 3C018008 */  lui   $at, %hi(off_CODE_bss_80079E30)
/* 0C6FDC 7F0924AC 00240821 */  addu  $at, $at, $a0
/* 0C6FE0 7F0924B0 A0209E30 */  sb    $zero, %lo(off_CODE_bss_80079E30)($at)
.L7F0924B4:
/* 0C6FE4 7F0924B4 248FFFFF */  addiu $t7, $a0, -1
/* 0C6FE8 7F0924B8 2DE1004A */  sltiu $at, $t7, 0x4a
/* 0C6FEC 7F0924BC 1020007C */  beqz  $at, .L7F0926B0
/* 0C6FF0 7F0924C0 000F7880 */   sll   $t7, $t7, 2
/* 0C6FF4 7F0924C4 3C018005 */  lui   $at, %hi(jpt_800573DC)
/* 0C6FF8 7F0924C8 002F0821 */  addu  $at, $at, $t7
/* 0C6FFC 7F0924CC 8C2F73DC */  lw    $t7, %lo(jpt_800573DC)($at)
/* 0C7000 7F0924D0 01E00008 */  jr    $t7
/* 0C7004 7F0924D4 00000000 */   nop   
cheat_button_invincibility:
/* 0C7008 7F0924D8 0FC227D6 */  jal   get_bondata_invincible_flag
/* 0C700C 7F0924DC 00000000 */   nop   
/* 0C7010 7F0924E0 50400074 */  beql  $v0, $zero, .L7F0926B4
/* 0C7014 7F0924E4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7018 7F0924E8 0FC30776 */  jal   get_textptr_for_textID
/* 0C701C 7F0924EC 3404B01E */   li    $a0, 45086
/* 0C7020 7F0924F0 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C7024 7F0924F4 00402025 */   move  $a0, $v0
/* 0C7028 7F0924F8 0FC227D2 */  jal   set_bondata_invincible_flag
/* 0C702C 7F0924FC 00002025 */   move  $a0, $zero
/* 0C7030 7F092500 1000006C */  b     .L7F0926B4
/* 0C7034 7F092504 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_all_guns:
/* 0C7038 7F092508 0FC230AB */  jal   get_BONDdata_allguns_flag
/* 0C703C 7F09250C 00000000 */   nop   
/* 0C7040 7F092510 50400068 */  beql  $v0, $zero, .L7F0926B4
/* 0C7044 7F092514 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7048 7F092518 0FC30776 */  jal   get_textptr_for_textID
/* 0C704C 7F09251C 3404B01F */   li    $a0, 45087
/* 0C7050 7F092520 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C7054 7F092524 00402025 */   move  $a0, $v0
/* 0C7058 7F092528 0FC230A7 */  jal   set_BONDdata_allguns_flag
/* 0C705C 7F09252C 00002025 */   move  $a0, $zero
/* 0C7060 7F092530 10000060 */  b     .L7F0926B4
/* 0C7064 7F092534 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_line_mode:
/* 0C7068 7F092538 0FC243FA */  jal   set_debug_VisCVG_flag
/* 0C706C 7F09253C 00002025 */   move  $a0, $zero
/* 0C7070 7F092540 1000005C */  b     .L7F0926B4
/* 0C7074 7F092544 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown:
/* 0C7078 7F092548 0FC227DD */  jal   get_invisible_to_guards_flag
/* 0C707C 7F09254C 00000000 */   nop   
/* 0C7080 7F092550 54400058 */  bnezl $v0, .L7F0926B4
/* 0C7084 7F092554 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7088 7F092558 0FC30776 */  jal   get_textptr_for_textID
/* 0C708C 7F09255C 3404B020 */   li    $a0, 45088
/* 0C7090 7F092560 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C7094 7F092564 00402025 */   move  $a0, $v0
/* 0C7098 7F092568 0FC227DA */  jal   set_invisible_to_guards_flag
/* 0C709C 7F09256C 24040001 */   li    $a0, 1
/* 0C70A0 7F092570 10000050 */  b     .L7F0926B4
/* 0C70A4 7F092574 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_infinite_ammo:
/* 0C70A8 7F092578 0FC30776 */  jal   get_textptr_for_textID
/* 0C70AC 7F09257C 3404B022 */   li    $a0, 45090
/* 0C70B0 7F092580 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C70B4 7F092584 00402025 */   move  $a0, $v0
/* 0C70B8 7F092588 1000004A */  b     .L7F0926B4
/* 0C70BC 7F09258C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_dkmode:
/* 0C70C0 7F092590 0FC30776 */  jal   get_textptr_for_textID
/* 0C70C4 7F092594 3404B023 */   li    $a0, 45091
/* 0C70C8 7F092598 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C70CC 7F09259C 00402025 */   move  $a0, $v0
/* 0C70D0 7F0925A0 0FC249FD */  jal   set_DKMode
/* 0C70D4 7F0925A4 00002025 */   move  $a0, $zero
/* 0C70D8 7F0925A8 10000042 */  b     .L7F0926B4
/* 0C70DC 7F0925AC 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_unknown_0:
/* 0C70E0 7F0925B0 24010001 */  li    $at, 1
/* 0C70E4 7F0925B4 1441003E */  bne   $v0, $at, .L7F0926B0
/* 0C70E8 7F0925B8 3C188008 */   lui   $t8, %hi(pPlayersPerm) 
/* 0C70EC 7F0925BC 8F18A0B4 */  lw    $t8, %lo(pPlayersPerm)($t8)
/* 0C70F0 7F0925C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C70F4 7F0925C4 44812000 */  mtc1  $at, $f4
/* 0C70F8 7F0925C8 C7060064 */  lwc1  $f6, 0x64($t8)
/* 0C70FC 7F0925CC 46062032 */  c.eq.s $f4, $f6
/* 0C7100 7F0925D0 00000000 */  nop   
/* 0C7104 7F0925D4 45030037 */  bc1tl .L7F0926B4
/* 0C7108 7F0925D8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C710C 7F0925DC 0FC30776 */  jal   get_textptr_for_textID
/* 0C7110 7F0925E0 3404B024 */   li    $a0, 45092
/* 0C7114 7F0925E4 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C7118 7F0925E8 00402025 */   move  $a0, $v0
/* 0C711C 7F0925EC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7120 7F0925F0 3C198008 */  lui   $t9, %hi(pPlayersPerm) 
/* 0C7124 7F0925F4 8F39A0B4 */  lw    $t9, %lo(pPlayersPerm)($t9)
/* 0C7128 7F0925F8 44814000 */  mtc1  $at, $f8
/* 0C712C 7F0925FC 3C088008 */  lui   $t0, %hi(pPlayer) 
/* 0C7130 7F092600 E7280064 */  swc1  $f8, 0x64($t9)
/* 0C7134 7F092604 8D08A0B0 */  lw    $t0, %lo(pPlayer)($t0)
/* 0C7138 7F092608 8D0400D4 */  lw    $a0, 0xd4($t0)
/* 0C713C 7F09260C 50800029 */  beql  $a0, $zero, .L7F0926B4
/* 0C7140 7F092610 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C7144 7F092614 C4800014 */  lwc1  $f0, 0x14($a0)
/* 0C7148 7F092618 46000280 */  add.s $f10, $f0, $f0
/* 0C714C 7F09261C 44055000 */  mfc1  $a1, $f10
/* 0C7150 7F092620 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C7154 7F092624 00000000 */   nop   
/* 0C7158 7F092628 10000022 */  b     .L7F0926B4
/* 0C715C 7F09262C 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_paintball:
/* 0C7160 7F092630 0FC30776 */  jal   get_textptr_for_textID
/* 0C7164 7F092634 3404B025 */   li    $a0, 45093
/* 0C7168 7F092638 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C716C 7F09263C 00402025 */   move  $a0, $v0
/* 0C7170 7F092640 1000001C */  b     .L7F0926B4
/* 0C7174 7F092644 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_mp_invis:
/* 0C7178 7F092648 3C014396 */  li    $at, 0x43960000 # 300.000000
/* 0C717C 7F09264C 44816000 */  mtc1  $at, $f12
/* 0C7180 7F092650 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C7184 7F092654 44817000 */  mtc1  $at, $f14
/* 0C7188 7F092658 0FC20284 */  jal   currentPlayerStartChrFade
/* 0C718C 7F09265C 00000000 */   nop   
/* 0C7190 7F092660 10000014 */  b     .L7F0926B4
/* 0C7194 7F092664 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_fast_mode:
/* 0C7198 7F092668 0FC24406 */  jal   get_debug_fast_bond_flag
/* 0C719C 7F09266C 00000000 */   nop   
/* 0C71A0 7F092670 50400010 */  beql  $v0, $zero, .L7F0926B4
/* 0C71A4 7F092674 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71A8 7F092678 0FC30776 */  jal   get_textptr_for_textID
/* 0C71AC 7F09267C 3404B027 */   li    $a0, 45095
/* 0C71B0 7F092680 0FC228F2 */  jal   jp_display_string_in_lower_left_corner
/* 0C71B4 7F092684 00402025 */   move  $a0, $v0
/* 0C71B8 7F092688 0FC24409 */  jal   set_debug_fast_bond_flag
/* 0C71BC 7F09268C 00002025 */   move  $a0, $zero
/* 0C71C0 7F092690 10000008 */  b     .L7F0926B4
/* 0C71C4 7F092694 8FBF0014 */   lw    $ra, 0x14($sp)
cheat_button_debug_mode:
/* 0C71C8 7F092698 0FC243E2 */  jal   get_debug_testingmanpos_flag
/* 0C71CC 7F09269C 00000000 */   nop   
/* 0C71D0 7F0926A0 50400004 */  beql  $v0, $zero, .L7F0926B4
/* 0C71D4 7F0926A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C71D8 7F0926A8 0FC243E5 */  jal   set_debug_testingmanpos_flag
/* 0C71DC 7F0926AC 00002025 */   move  $a0, $zero
cheat_button_default:
.L7F0926B0:
/* 0C71E0 7F0926B0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0926B4:
/* 0C71E4 7F0926B4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C71E8 7F0926B8 03E00008 */  jr    $ra
/* 0C71EC 7F0926BC 00000000 */   nop   
)
#endif
#endif





#ifdef NONMATCHING
void cheatDisableAllCheats(void) {
    s32 sp30;
    s32 temp_s4;
    s32 temp_s0;
    s32 temp_s3;
    s32 phi_s3;
    void *phi_s1;
    s32 phi_s0;

    // Node 0
    temp_s4 = getPlayerCount();
    sp30 = get_cur_playernum();
    if (temp_s4 > 0)
    {
        // Node 1
        phi_s3 = 0;
loop_2:
        // Node 2
        set_cur_player(phi_s3);
        phi_s1 = &D_8003F80C+0x10;
        phi_s0 = 1;
loop_3:
        // Node 3
        if ((phi_s1->unk-4 & 0x40) != 0)
        {
            // Node 4
            if (cheatCheckIfOn(phi_s0) != 0)
            {
                // Node 5
                cheatDisplayMessageActivateCheat(phi_s0);
            }
        }
        // Node 6
        temp_s0 = (phi_s0 + 1);
        phi_s1 = (phi_s1 + 0x10);
        phi_s0 = temp_s0;
        if (temp_s0 != 0x4b)
        {
            goto loop_3;
        }
        // Node 7
        temp_s3 = (phi_s3 + 1);
        phi_s3 = temp_s3;
        if (temp_s3 != temp_s4)
        {
            goto loop_2;
        }
    }
    // Node 8
    return set_cur_player(sp30);
}
#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
.text
glabel cheatDisableAllCheats
/* 0C71F0 7F0926C0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0C71F4 7F0926C4 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C71F8 7F0926C8 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C71FC 7F0926CC AFB30024 */  sw    $s3, 0x24($sp)
/* 0C7200 7F0926D0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C7204 7F0926D4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C7208 7F0926D8 0FC26919 */  jal   getPlayerCount
/* 0C720C 7F0926DC AFB00018 */   sw    $s0, 0x18($sp)
/* 0C7210 7F0926E0 0FC26C54 */  jal   get_cur_playernum
/* 0C7214 7F0926E4 0040A025 */   move  $s4, $v0
/* 0C7218 7F0926E8 AFA20030 */  sw    $v0, 0x30($sp)
/* 0C721C 7F0926EC 1A800017 */  blez  $s4, .L7F09274C
/* 0C7220 7F0926F0 00009825 */   move  $s3, $zero
/* 0C7224 7F0926F4 2412004B */  li    $s2, 75
.L7F0926F8:
/* 0C7228 7F0926F8 0FC26C43 */  jal   set_cur_player
/* 0C722C 7F0926FC 02602025 */   move  $a0, $s3
/* 0C7230 7F092700 3C118004 */  lui   $s1, %hi(D_8003F80C+0x10)
/* 0C7234 7F092704 2631F81C */  addiu $s1, %lo(D_8003F80C+0x10) # addiu $s1, $s1, -0x7e4
/* 0C7238 7F092708 24100001 */  li    $s0, 1
.L7F09270C:
/* 0C723C 7F09270C 8E2EFFFC */  lw    $t6, -4($s1)
/* 0C7240 7F092710 31CF0040 */  andi  $t7, $t6, 0x40
/* 0C7244 7F092714 51E00008 */  beql  $t7, $zero, .L7F092738
/* 0C7248 7F092718 26100001 */   addiu $s0, $s0, 1
/* 0C724C 7F09271C 0FC249EF */  jal   cheatCheckIfOn
/* 0C7250 7F092720 02002025 */   move  $a0, $s0
/* 0C7254 7F092724 50400004 */  beql  $v0, $zero, .L7F092738
/* 0C7258 7F092728 26100001 */   addiu $s0, $s0, 1
/* 0C725C 7F09272C 0FC2490E */  jal   cheatDisplayMessageActivateCheat
/* 0C7260 7F092730 02002025 */   move  $a0, $s0
/* 0C7264 7F092734 26100001 */  addiu $s0, $s0, 1
.L7F092738:
/* 0C7268 7F092738 1612FFF4 */  bne   $s0, $s2, .L7F09270C
/* 0C726C 7F09273C 26310010 */   addiu $s1, $s1, 0x10
/* 0C7270 7F092740 26730001 */  addiu $s3, $s3, 1
/* 0C7274 7F092744 1674FFEC */  bne   $s3, $s4, .L7F0926F8
/* 0C7278 7F092748 00000000 */   nop   
.L7F09274C:
/* 0C727C 7F09274C 0FC26C43 */  jal   set_cur_player
/* 0C7280 7F092750 8FA40030 */   lw    $a0, 0x30($sp)
/* 0C7284 7F092754 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C7288 7F092758 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C728C 7F09275C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C7290 7F092760 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C7294 7F092764 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C7298 7F092768 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C729C 7F09276C 03E00008 */  jr    $ra
/* 0C72A0 7F092770 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
void cheatGetMenuTextPointer(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default
/*.word cheat_button_default*/
/*.word cheat_button_default*/
/*.word cheat_button_default*/
.text
glabel cheatGetMenuTextPointer
/* 0C72A4 7F092774 00047100 */  sll   $t6, $a0, 4
/* 0C72A8 7F092778 3C028004 */  lui   $v0, %hi(D_8003F804)
/* 0C72AC 7F09277C 004E1021 */  addu  $v0, $v0, $t6
/* 0C72B0 7F092780 9442F804 */  lhu   $v0, %lo(D_8003F804)($v0)
/* 0C72B4 7F092784 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C72B8 7F092788 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C72BC 7F09278C 10400005 */  beqz  $v0, .L7F0927A4
/* 0C72C0 7F092790 00000000 */   nop   
/* 0C72C4 7F092794 0FC30776 */  jal   get_textptr_for_textID
/* 0C72C8 7F092798 00402025 */   move  $a0, $v0
/* 0C72CC 7F09279C 10000004 */  b     .L7F0927B0
/* 0C72D0 7F0927A0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0927A4:
/* 0C72D4 7F0927A4 0FC30776 */  jal   get_textptr_for_textID
/* 0C72D8 7F0927A8 3404B028 */   li    $a0, 45096
/* 0C72DC 7F0927AC 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0927B0:
/* 0C72E0 7F0927B0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C72E4 7F0927B4 03E00008 */  jr    $ra
/* 0C72E8 7F0927B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void cheatCheckIfOn(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*ugh hack for jtbl*/
.word cheat_button_default
.word cheat_button_default
.word cheat_button_default

.text
glabel cheatCheckIfOn
/* 0C72EC 7F0927BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C72F0 7F0927C0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C72F4 7F0927C4 0FC26C54 */  jal   get_cur_playernum
/* 0C72F8 7F0927C8 AFA40018 */   sw    $a0, 0x18($sp)
/* 0C72FC 7F0927CC 8FAE0018 */  lw    $t6, 0x18($sp)
/* 0C7300 7F0927D0 3C0F8008 */  lui   $t7, %hi(off_CODE_bss_80079E30)
/* 0C7304 7F0927D4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C7308 7F0927D8 01EE7821 */  addu  $t7, $t7, $t6
/* 0C730C 7F0927DC 91EF9E30 */  lbu   $t7, %lo(off_CODE_bss_80079E30)($t7)
/* 0C7310 7F0927E0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C7314 7F0927E4 004F1007 */  srav  $v0, $t7, $v0
/* 0C7318 7F0927E8 30580001 */  andi  $t8, $v0, 1
/* 0C731C 7F0927EC 03E00008 */  jr    $ra
/* 0C7320 7F0927F0 03001025 */   move  $v0, $t8
)
#endif





#ifdef NONMATCHING
void set_DKMode(void) {

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80057504
.word 0x3f4ccccd /*0.80000001*/
.text
glabel set_DKMode
/* 0C7324 7F0927F4 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C7328 7F0927F8 AFB10024 */  sw    $s1, 0x24($sp)
/* 0C732C 7F0927FC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C7330 7F092800 AFB00020 */  sw    $s0, 0x20($sp)
/* 0C7334 7F092804 3C118003 */  lui   $s1, %hi(ptr_guard_data)
/* 0C7338 7F092808 00808025 */  move  $s0, $a0
/* 0C733C 7F09280C AFB20028 */  sw    $s2, 0x28($sp)
/* 0C7340 7F092810 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0C7344 7F092814 0FC07D4C */  jal   get_numguards
/* 0C7348 7F092818 8E31CC64 */   lw    $s1, %lo(ptr_guard_data)($s1)
/* 0C734C 7F09281C 12000004 */  beqz  $s0, .L7F092830
/* 0C7350 7F092820 00409025 */   move  $s2, $v0
/* 0C7354 7F092824 3C018005 */  lui   $at, %hi(D_80057504)
/* 0C7358 7F092828 10000004 */  b     .L7F09283C
/* 0C735C 7F09282C C4347504 */   lwc1  $f20, %lo(D_80057504)($at)
.L7F092830:
/* 0C7360 7F092830 3C013FA0 */  li    $at, 0x3FA00000 # 1.250000
/* 0C7364 7F092834 4481A000 */  mtc1  $at, $f20
/* 0C7368 7F092838 00000000 */  nop   
.L7F09283C:
/* 0C736C 7F09283C 1840000C */  blez  $v0, .L7F092870
/* 0C7370 7F092840 00008025 */   move  $s0, $zero
.L7F092844:
/* 0C7374 7F092844 8E24001C */  lw    $a0, 0x1c($s1)
/* 0C7378 7F092848 50800007 */  beql  $a0, $zero, .L7F092868
/* 0C737C 7F09284C 26100001 */   addiu $s0, $s0, 1
/* 0C7380 7F092850 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C7384 7F092854 46142182 */  mul.s $f6, $f4, $f20
/* 0C7388 7F092858 44053000 */  mfc1  $a1, $f6
/* 0C738C 7F09285C 0FC1B39E */  jal   set_obj_instance_controller_scale
/* 0C7390 7F092860 00000000 */   nop   
/* 0C7394 7F092864 26100001 */  addiu $s0, $s0, 1
.L7F092868:
/* 0C7398 7F092868 1612FFF6 */  bne   $s0, $s2, .L7F092844
/* 0C739C 7F09286C 263101DC */   addiu $s1, $s1, 0x1dc
.L7F092870:
/* 0C73A0 7F092870 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C73A4 7F092874 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0C73A8 7F092878 8FB00020 */  lw    $s0, 0x20($sp)
/* 0C73AC 7F09287C 8FB10024 */  lw    $s1, 0x24($sp)
/* 0C73B0 7F092880 8FB20028 */  lw    $s2, 0x28($sp)
/* 0C73B4 7F092884 03E00008 */  jr    $ra
/* 0C73B8 7F092888 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80057504
.word 0x3f4ccccd /*0.80000001*/
.text
glabel set_DKMode
/* 0C7EE4 7F093374 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C7EE8 7F093378 AFB00020 */  sw    $s0, 0x20($sp)
/* 0C7EEC 7F09337C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C7EF0 7F093380 AFB10024 */  sw    $s1, 0x24($sp)
/* 0C7EF4 7F093384 3C108003 */  lui   $s0, %hi(ptr_guard_data) # $s0, 0x8003
/* 0C7EF8 7F093388 00808825 */  move  $s1, $a0
/* 0C7EFC 7F09338C AFB20028 */  sw    $s2, 0x28($sp)
/* 0C7F00 7F093390 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0C7F04 7F093394 0FC07DB8 */  jal   get_numguards
/* 0C7F08 7F093398 8E10CCA4 */   lw    $s0, %lo(ptr_guard_data)($s0)
/* 0C7F0C 7F09339C 12200004 */  beqz  $s1, .L7F0933B0
/* 0C7F10 7F0933A0 00409025 */   move  $s2, $v0
/* 0C7F14 7F0933A4 3C018005 */  lui   $at, %hi(D_80057504) # $at, 0x8005
/* 0C7F18 7F0933A8 10000004 */  b     .L7F0933BC
/* 0C7F1C 7F0933AC C4347534 */   lwc1  $f20, %lo(D_80057504)($at)
.L7F0933B0:
/* 0C7F20 7F0933B0 3C013FA0 */  li    $at, 0x3FA00000 # 1.250000
/* 0C7F24 7F0933B4 4481A000 */  mtc1  $at, $f20
/* 0C7F28 7F0933B8 00000000 */  nop   
.L7F0933BC:
/* 0C7F2C 7F0933BC 18400012 */  blez  $v0, .L7F093408
/* 0C7F30 7F0933C0 00008825 */   move  $s1, $zero
.L7F0933C4:
/* 0C7F34 7F0933C4 8E0E001C */  lw    $t6, 0x1c($s0)
/* 0C7F38 7F0933C8 51C0000D */  beql  $t6, $zero, .L7F093400
/* 0C7F3C 7F0933CC 26310001 */   addiu $s1, $s1, 1
/* 0C7F40 7F0933D0 8204000F */  lb    $a0, 0xf($s0)
/* 0C7F44 7F0933D4 0FC0827B */  jal   jp_only_7F0209EC
/* 0C7F48 7F0933D8 82050006 */   lb    $a1, 6($s0)
/* 0C7F4C 7F0933DC 50400008 */  beql  $v0, $zero, .L7F093400
/* 0C7F50 7F0933E0 26310001 */   addiu $s1, $s1, 1
/* 0C7F54 7F0933E4 8E04001C */  lw    $a0, 0x1c($s0)
/* 0C7F58 7F0933E8 C4840014 */  lwc1  $f4, 0x14($a0)
/* 0C7F5C 7F0933EC 46142182 */  mul.s $f6, $f4, $f20
/* 0C7F60 7F0933F0 44053000 */  mfc1  $a1, $f6
/* 0C7F64 7F0933F4 0FC1B51A */  jal   set_obj_instance_controller_scale
/* 0C7F68 7F0933F8 00000000 */   nop   
/* 0C7F6C 7F0933FC 26310001 */  addiu $s1, $s1, 1
.L7F093400:
/* 0C7F70 7F093400 1632FFF0 */  bne   $s1, $s2, .L7F0933C4
/* 0C7F74 7F093404 261001DC */   addiu $s0, $s0, 0x1dc
.L7F093408:
/* 0C7F78 7F093408 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C7F7C 7F09340C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0C7F80 7F093410 8FB00020 */  lw    $s0, 0x20($sp)
/* 0C7F84 7F093414 8FB10024 */  lw    $s1, 0x24($sp)
/* 0C7F88 7F093418 8FB20028 */  lw    $s2, 0x28($sp)
/* 0C7F8C 7F09341C 03E00008 */  jr    $ra
/* 0C7F90 7F093420 27BD0030 */   addiu $sp, $sp, 0x30     
)
#endif

#endif

