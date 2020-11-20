#include "ultra64.h"
#include "bondgame.h"
#include "ramrom.h"
#include "deb.h"

/**
 * @file deb.c
 * This file contains debug related code. 
 * 
 * In particular, it seems to handle debug_notice_list
 */

/* bss */
extern char dword_CODE_bss_80060890[0x400];



/* data */
u32 D_800232E0[] = {0, 0};
u32 debug_notice_list[] = {0, 0, 0, 0};
char * debug_notice_list_data = &dword_CODE_bss_80060890;





/**
 * 5920	70004D20
 *     V0=p->match in debug.notice.list [800232E8] or NULL if not found
 *     accepts: A0=p->name, A1=p->data
 */
#ifdef NONMATCHING
void *debCheckIfDNLEntryExists(s32 arg0)
{
    void *temp_s0;
    void *phi_s0;

    phi_s0 = debug_notice_list;
    if (debug_notice_list != 0)
    {
loop_1:
        if (something_with_strings_0(phi_s0->unk8, arg0) == 0)
        {
            return phi_s0;
        }
        temp_s0 = phi_s0->unk0;
        phi_s0 = temp_s0;
        if (temp_s0 != 0)
        {
            goto loop_1;
        }
    }
    return NULL;
}
#else
GLOBAL_ASM(
.text
glabel debCheckIfDNLEntryExists
/* 005920 70004D20 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 005924 70004D24 AFB00014 */  sw    $s0, 0x14($sp)
/* 005928 70004D28 3C108002 */  lui   $s0, %hi(debug_notice_list)
/* 00592C 70004D2C 8E1032E8 */  lw    $s0, %lo(debug_notice_list)($s0)
/* 005930 70004D30 AFB10018 */  sw    $s1, 0x18($sp)
/* 005934 70004D34 00808825 */  move  $s1, $a0
/* 005938 70004D38 1200000B */  beqz  $s0, .L70004D68
/* 00593C 70004D3C AFBF001C */   sw    $ra, 0x1c($sp)
/* 005940 70004D40 8E040008 */  lw    $a0, 8($s0)
.L70004D44:
/* 005944 70004D44 0C002A13 */  jal   something_with_strings_0
/* 005948 70004D48 02202825 */   move  $a1, $s1
/* 00594C 70004D4C 54400004 */  bnezl $v0, .L70004D60
/* 005950 70004D50 8E100000 */   lw    $s0, ($s0)
/* 005954 70004D54 10000005 */  b     .L70004D6C
/* 005958 70004D58 02001025 */   move  $v0, $s0
/* 00595C 70004D5C 8E100000 */  lw    $s0, ($s0)
.L70004D60:
/* 005960 70004D60 5600FFF8 */  bnezl $s0, .L70004D44
/* 005964 70004D64 8E040008 */   lw    $a0, 8($s0)
.L70004D68:
/* 005968 70004D68 00001025 */  move  $v0, $zero
.L70004D6C:
/* 00596C 70004D6C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 005970 70004D70 8FB00014 */  lw    $s0, 0x14($sp)
/* 005974 70004D74 8FB10018 */  lw    $s1, 0x18($sp)
/* 005978 70004D78 03E00008 */  jr    $ra
/* 00597C 70004D7C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif

/**
 * 5980	70004D80
 *     V0=p->entry of size A0 allocated in debug.notice.list; entry allocated in block 6 on failure
 *     accepts: A0=size
 */
#ifdef NONMATCHING
u32 debAllocateDNLEntry(s32 arg0)
{
    u32 temp_v0;

    temp_v0 = (debug_notice_list_data + arg0);
    if (&tlbthread >= temp_v0)
    {
        debug_notice_list_data = temp_v0;
        return debug_notice_list_data;
    }
    debug_notice_list_data = (u32) (temp_v0 - arg0);
    return mempAllocBytesInBank(6);
}
#else
GLOBAL_ASM(
.text
glabel debAllocateDNLEntry
/* 005980 70004D80 3C028002 */  lui   $v0, %hi(debug_notice_list_data)
/* 005984 70004D84 8C4232F8 */  lw    $v0, %lo(debug_notice_list_data)($v0)
/* 005988 70004D88 3C0E8006 */  lui   $t6, %hi(tlbthread) 
/* 00598C 70004D8C 25CE0C90 */  addiu $t6, %lo(tlbthread) # addiu $t6, $t6, 0xc90
/* 005990 70004D90 00401825 */  move  $v1, $v0
/* 005994 70004D94 00441021 */  addu  $v0, $v0, $a0
/* 005998 70004D98 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00599C 70004D9C 01C2082B */  sltu  $at, $t6, $v0
/* 0059A0 70004DA0 10200008 */  beqz  $at, .L70004DC4
/* 0059A4 70004DA4 AFBF0014 */   sw    $ra, 0x14($sp)
/* 0059A8 70004DA8 00441023 */  subu  $v0, $v0, $a0
/* 0059AC 70004DAC 3C018002 */  lui   $at, %hi(debug_notice_list_data)
/* 0059B0 70004DB0 AC2232F8 */  sw    $v0, %lo(debug_notice_list_data)($at)
/* 0059B4 70004DB4 0C0025C8 */  jal   mempAllocBytesInBank
/* 0059B8 70004DB8 24050006 */   li    $a1, 6
/* 0059BC 70004DBC 10000005 */  b     .L70004DD4
/* 0059C0 70004DC0 8FBF0014 */   lw    $ra, 0x14($sp)
.L70004DC4:
/* 0059C4 70004DC4 3C018002 */  lui   $at, %hi(debug_notice_list_data)
/* 0059C8 70004DC8 AC2232F8 */  sw    $v0, %lo(debug_notice_list_data)($at)
/* 0059CC 70004DCC 00601025 */  move  $v0, $v1
/* 0059D0 70004DD0 8FBF0014 */  lw    $ra, 0x14($sp)
.L70004DD4:
/* 0059D4 70004DD4 27BD0018 */  addiu $sp, $sp, 0x18
/* 0059D8 70004DD8 03E00008 */  jr    $ra
/* 0059DC 70004DDC 00000000 */   nop   
)
#endif




/**
 * 59E0	70004DE0
 *     V0=p->new entry added in debug.notice.list
 *     accepts: A0=p->name, A1=p->data
 */
#ifdef NONMATCHING
void debAllocateAndAddDNLEntry(s32 arg0, s32 arg1)
{
    ? temp_ret;

    temp_ret = debAllocateDNLEntry(0x10);
    *temp_ret = (s32) debug_notice_list;
    temp_ret->unk4 = arg1;
    temp_ret->unk8 = arg0;
    debug_notice_list = temp_ret;
}
#else
GLOBAL_ASM(
.text
glabel debAllocateAndAddDNLEntry
/* 0059E0 70004DE0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0059E4 70004DE4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0059E8 70004DE8 AFA40018 */  sw    $a0, 0x18($sp)
/* 0059EC 70004DEC AFA5001C */  sw    $a1, 0x1c($sp)
/* 0059F0 70004DF0 0C001360 */  jal   debAllocateDNLEntry
/* 0059F4 70004DF4 24040010 */   li    $a0, 16
/* 0059F8 70004DF8 3C038002 */  lui   $v1, %hi(debug_notice_list)
/* 0059FC 70004DFC 246332E8 */  addiu $v1, %lo(debug_notice_list) # addiu $v1, $v1, 0x32e8
/* 005A00 70004E00 8C6E0000 */  lw    $t6, ($v1)
/* 005A04 70004E04 AC4E0000 */  sw    $t6, ($v0)
/* 005A08 70004E08 8FAF001C */  lw    $t7, 0x1c($sp)
/* 005A0C 70004E0C AC4F0004 */  sw    $t7, 4($v0)
/* 005A10 70004E10 8FB80018 */  lw    $t8, 0x18($sp)
/* 005A14 70004E14 AC580008 */  sw    $t8, 8($v0)
/* 005A18 70004E18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 005A1C 70004E1C AC620000 */  sw    $v0, ($v1)
/* 005A20 70004E20 27BD0018 */  addiu $sp, $sp, 0x18
/* 005A24 70004E24 03E00008 */  jr    $ra
/* 005A28 70004E28 00000000 */   nop   
)
#endif




/**
 * 5A2C	70004E2C
 *     V0= p->debug.notice.list entry for boss_c_debug using data at 800241A0
 */
void debInitDebugNoticeList(void)
{
    debCheckAddDebugNoticeListEntry(&D_800232E0, "deb_c_debug");
    init_tlb();
}


/**
 * 5A60	70004E60
 *     V0=p->debug.notice.list entry for name A1 and data A0; generates if not found
 *     accepts: A0=p->data, A1=p->name
 */
void debCheckAddDebugNoticeListEntry(void* data, char * string)
{
    if (debCheckIfDNLEntryExists(string) == 0)
    {
        debAllocateAndAddDNLEntry(string, data);
    }
}



/**
 * 5A98	70004E98
 *     V0=0; scan debug.notice.list until a NULL pointer
 *     likely this would have executed some function for each entry...
 */
#ifdef NONMATCHING
void *debScanDNLEntries_NEUTERED(void)
{
    void *temp_v0;
    void *phi_v0;

    phi_v0 = debug_notice_list;
    if (debug_notice_list != 0)
    {
loop_1:
        temp_v0 = *phi_v0;
        phi_v0 = temp_v0;
        if (temp_v0 != 0)
        {
            goto loop_1;
        }
    }
    return debug_notice_list;
}
#else
GLOBAL_ASM(
.text
glabel debScanDNLEntries_NEUTERED
/* 005A98 70004E98 3C028002 */  lui   $v0, %hi(debug_notice_list)
/* 005A9C 70004E9C 8C4232E8 */  lw    $v0, %lo(debug_notice_list)($v0)
/* 005AA0 70004EA0 10400004 */  beqz  $v0, .L70004EB4
/* 005AA4 70004EA4 00000000 */   nop   
/* 005AA8 70004EA8 8C420000 */  lw    $v0, ($v0)
.L70004EAC:
/* 005AAC 70004EAC 5440FFFF */  bnezl $v0, .L70004EAC
/* 005AB0 70004EB0 8C420000 */   lw    $v0, ($v0)
.L70004EB4:
/* 005AB4 70004EB4 03E00008 */  jr    $ra
/* 005AB8 70004EB8 00000000 */   nop   
)
#endif



/**
 * 5ABC	70004EBC
 *     unconditional return
 */
void debRemoved70004EBC(void)
{
    return;
}

/**
 * 5AC4	70004EC4
 *     A0->SP+0, A1->SP+4, A2->SP+8
 */
void debRemoved70004EC4(s32 arg0, s32 arg1, s32 arg2)
{
    return;
}


