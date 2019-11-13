#include "ultra64.h"
#include "ramrom.h"

/**
 * @file tlb_manage.c
 * This file contains tlb management code. 
 * 
 * In particular, it:
 *   - 
 *   - 
 *   - 
 */

u32 maybe_cur_TLB_entries = 0;
u32 tlb_segment_num = 0;

char TLB_managment_table_start[0x800];
char TLB_manager_mapping_table_start[0xB4];
u32 TLB_manager_mapping_table_end;
u32 ptr_TLBallocatedblock;





/**
 * 23E0	700017E0
 * establishes 7F- TLB buffer and management table
 */
#ifdef NONMATCHING
void *establish_TLB_buffer_management_table(void)
{
    u32 temp_v1;
    s32 temp_at;
    void *temp_v1_2;
    u32 phi_v1;
    void *phi_v1_2;

    phi_v1 = &TLB_managment_table_start;
block_1:
    temp_v1 = (phi_v1 + 0x10);
    temp_v1->unk-10 = 1;
    temp_v1->unk-C = 0;
    phi_v1 = temp_v1;
    if (temp_v1 < &TLB_manager_mapping_table_start)
    {
        goto block_1;
    }
    temp_at = (TLB_manager_mapping_table_start + 2);
    *temp_at = (u8)0;
    *temp_at = 1;
    *temp_at = (u8)0;
    *temp_at = 1;
    phi_v1_2 = (void *) (TLB_manager_mapping_table_start + 4);
block_3:
    temp_v1_2 = (phi_v1_2 + 8);
    temp_v1_2->unk-5 = (u8)0;
    temp_v1_2->unk-6 = 1;
    temp_v1_2->unk-3 = (u8)0;
    temp_v1_2->unk-4 = 1;
    temp_v1_2->unk-1 = (u8)0;
    temp_v1_2->unk-2 = 1;
    temp_v1_2->unk-7 = (u8)0;
    temp_v1_2->unk-8 = 1;
    phi_v1_2 = temp_v1_2;
    if (temp_v1_2 != &TLB_manager_mapping_table_end)
    {
        goto block_3;
    }
    ptr_TLBallocatedblock = (s32) ((&sp_boot & -0x2000) + 0xfff4c000);
    (void *)0x80060000->unk-1B5C = (s32) (&TLB_managment_table_start + 0xffc08000);
    return &TLB_manager_mapping_table_end;
}
#else
GLOBAL_ASM(
glabel establish_TLB_buffer_management_table
/* 0023E0 700017E0 3C038006 */  lui   $v1, %hi(TLB_managment_table_start)
/* 0023E4 700017E4 3C028006 */  lui   $v0, %hi(TLB_manager_mapping_table_start)
/* 0023E8 700017E8 2442E3F0 */  addiu $v0, %lo(TLB_manager_mapping_table_start) # addiu $v0, $v0, -0x1c10
/* 0023EC 700017EC 2463DBF0 */  addiu $v1, %lo(TLB_managment_table_start) # addiu $v1, $v1, -0x2410
/* 0023F0 700017F0 24040001 */  li    $a0, 1
.L700017F4:
/* 0023F4 700017F4 24630010 */  addiu $v1, $v1, 0x10
/* 0023F8 700017F8 0062082B */  sltu  $at, $v1, $v0
/* 0023FC 700017FC AC64FFF0 */  sw    $a0, -0x10($v1)
/* 002400 70001800 1420FFFC */  bnez  $at, .L700017F4
/* 002404 70001804 AC60FFF4 */   sw    $zero, -0xc($v1)
/* 002408 70001808 3C018006 */  lui   $at, %hi(TLB_manager_mapping_table_start + 2)
/* 00240C 7000180C 3C038006 */  lui   $v1, %hi(TLB_manager_mapping_table_start + 4)
/* 002410 70001810 3C028006 */  lui   $v0, %hi(TLB_manager_mapping_table_end)
/* 002414 70001814 2442E4A4 */  addiu $v0, %lo(TLB_manager_mapping_table_end) # addiu $v0, $v0, -0x1b5c
/* 002418 70001818 2463E3F4 */  addiu $v1, %lo(TLB_manager_mapping_table_start + 4) # addiu $v1, $v1, -0x1c0c
/* 00241C 7000181C A020E3F1 */  sb    $zero, %lo(TLB_manager_mapping_table_start + 1)($at)
/* 002420 70001820 A024E3F0 */  sb    $a0, %lo(TLB_manager_mapping_table_start)($at)
/* 002424 70001824 A020E3F3 */  sb    $zero, %lo(TLB_manager_mapping_table_start + 3)($at)
/* 002428 70001828 A024E3F2 */  sb    $a0, %lo(TLB_manager_mapping_table_start + 2)($at)
.L7000182C:
/* 00242C 7000182C 24630008 */  addiu $v1, $v1, 8
/* 002430 70001830 A060FFFB */  sb    $zero, -5($v1)
/* 002434 70001834 A064FFFA */  sb    $a0, -6($v1)
/* 002438 70001838 A060FFFD */  sb    $zero, -3($v1)
/* 00243C 7000183C A064FFFC */  sb    $a0, -4($v1)
/* 002440 70001840 A060FFFF */  sb    $zero, -1($v1)
/* 002444 70001844 A064FFFE */  sb    $a0, -2($v1)
/* 002448 70001848 A060FFF9 */  sb    $zero, -7($v1)
/* 00244C 7000184C 1462FFF7 */  bne   $v1, $v0, .L7000182C
/* 002450 70001850 A064FFF8 */   sb    $a0, -8($v1)
/* 002454 70001854 3C0E803B */  lui   $t6, %hi(sp_boot) # $t6, 0x803b
/* 002458 70001858 25CEB400 */  addiu $t6, %lo(sp_boot) # addiu $t6, $t6, -0x4c00
/* 00245C 7000185C 2401E000 */  li    $at, -8192
/* 002460 70001860 01C17824 */  and   $t7, $t6, $at
/* 002464 70001864 3C01FFF4 */  lui   $at, (0xFFF4C000 >> 16) # lui $at, 0xfff4
/* 002468 70001868 3421C000 */  ori   $at, (0xFFF4C000 & 0xFFFF) # ori $at, $at, 0xc000
/* 00246C 7000186C 01E1C021 */  addu  $t8, $t7, $at
/* 002470 70001870 3C018006 */  lui   $at, %hi(ptr_TLBallocatedblock)
/* 002474 70001874 AC38E4A8 */  sw    $t8, %lo(ptr_TLBallocatedblock)($at)
/* 002478 70001878 3C01FFC0 */  lui   $at, (0xFFC08000 >> 16) # lui $at, 0xffc0
/* 00247C 7000187C 3C198006 */  lui   $t9, %hi(TLB_managment_table_start) 
/* 002480 70001880 2739DBF0 */  addiu $t9, %lo(TLB_managment_table_start) # addiu $t9, $t9, -0x2410
/* 002484 70001884 34218000 */  ori   $at, (0xFFC08000 & 0xFFFF) # ori $at, $at, 0x8000
/* 002488 70001888 03214021 */  addu  $t0, $t9, $at
/* 00248C 7000188C 3C018006 */  lui   $at, %hi(TLB_manager_mapping_table_end)
/* 002490 70001890 03E00008 */  jr    $ra
/* 002494 70001894 AC28E4A4 */   sw    $t0, %lo(TLB_manager_mapping_table_end)($at)
)
#endif

/**
 * 2498	70001898
 * ???; pointless conditional tests, will reset 800230D0
 */
#ifdef NONMATCHING
void mp_tlb_related(void) {
    
}
#else
GLOBAL_ASM(
glabel mp_tlb_related
/* 002498 70001898 3C038002 */  lui   $v1, %hi(maybe_cur_TLB_entries)
/* 00249C 7000189C 246330D0 */  addiu $v1, %lo(maybe_cur_TLB_entries) # addiu $v1, $v1, 0x30d0
/* 0024A0 700018A0 8C620000 */  lw    $v0, ($v1)
/* 0024A4 700018A4 28410033 */  slti  $at, $v0, 0x33
/* 0024A8 700018A8 10200003 */  beqz  $at, .L700018B8
/* 0024AC 700018AC 2841001A */   slti  $at, $v0, 0x1a
/* 0024B0 700018B0 10200001 */  beqz  $at, .L700018B8
/* 0024B4 700018B4 00000000 */   nop   
.L700018B8:
/* 0024B8 700018B8 03E00008 */  jr    $ra
/* 0024BC 700018BC AC600000 */   sw    $zero, ($v1)
)
#endif

/**
 * 24C0	700018C0
 * searches TLB index for an entry matching A0
 *	V0=index of match or 80000000 if not found
 *	accepts: A0=TLB pointer
 */
s32 return_TLB_index_for_entry(int entry) {
    s32 index = 0;
    while (index != 0x20) {
        if (__osGetTLBHi(index) == entry) {
            return index;
        }
        index++;
    };
    return -0x80000000;
}

/**
 *  2520	70001920
 * find and remove TLB entry A0
 *	accepts: A0=TLB pointer
 *	redirects to 700018C0, 7000D3D0
 */
void find_remove_TLB_entry(u32 entry) {
    s32 index = return_TLB_index_for_entry(entry);

    if ((index & 0x80000000))
        return;

    osUnmapTLB(index);
}

/**
 * 2554	70001954
 * remove index A0 TLB entry from table at 8005E3F0
 *	table format:
 *		0x0	1 if dirty
 *		0x1	chunk # (7F000000 | chunk<<D)
 */
#ifdef NONMATCHING
void remove_TLB_entry_from_table(s32 arg0)
{
    void *sp18;
    void *temp_v1;
    ? temp_ret;

    temp_v1 = ((arg0 * 2) + &TLB_manager_mapping_table_start);
    if (*temp_v1 == 0)
    {
        sp18 = temp_v1;
        temp_ret = return_TLB_index_for_entry(((temp_v1->unk1 << 0xd) | 0x7f000000));
        if ((temp_ret << 0) >= 0)
        {
            sp18 = temp_v1;
            osUnmapTLB(temp_ret);
        }
        (0x80060000 + (temp_v1->unk1 * 0x10))->unk-2410 = 1;
        *temp_v1 = 1;
    }
}
#else
GLOBAL_ASM(
glabel remove_TLB_entry_from_table
/* 002554 70001954 3C0F8006 */  lui   $t7, %hi(TLB_manager_mapping_table_start) 
/* 002558 70001958 25EFE3F0 */  addiu $t7, %lo(TLB_manager_mapping_table_start) # addiu $t7, $t7, -0x1c10
/* 00255C 7000195C 00047040 */  sll   $t6, $a0, 1
/* 002560 70001960 01CF1821 */  addu  $v1, $t6, $t7
/* 002564 70001964 90780000 */  lbu   $t8, ($v1)
/* 002568 70001968 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 00256C 7000196C AFBF0014 */  sw    $ra, 0x14($sp)
/* 002570 70001970 57000016 */  bnezl $t8, .L700019CC
/* 002574 70001974 8FBF0014 */   lw    $ra, 0x14($sp)
/* 002578 70001978 90640001 */  lbu   $a0, 1($v1)
/* 00257C 7000197C 3C017F00 */  lui   $at, 0x7f00
/* 002580 70001980 AFA30018 */  sw    $v1, 0x18($sp)
/* 002584 70001984 0004CB40 */  sll   $t9, $a0, 0xd
/* 002588 70001988 0C000630 */  jal   return_TLB_index_for_entry
/* 00258C 7000198C 03212025 */   or    $a0, $t9, $at
/* 002590 70001990 00024800 */  sll   $t1, $v0, 0
/* 002594 70001994 8FA30018 */  lw    $v1, 0x18($sp)
/* 002598 70001998 05200004 */  bltz  $t1, .L700019AC
/* 00259C 7000199C 00402025 */   move  $a0, $v0
/* 0025A0 700019A0 0C0034F4 */  jal   osUnmapTLB
/* 0025A4 700019A4 AFA30018 */   sw    $v1, 0x18($sp)
/* 0025A8 700019A8 8FA30018 */  lw    $v1, 0x18($sp)
.L700019AC:
/* 0025AC 700019AC 906A0001 */  lbu   $t2, 1($v1)
/* 0025B0 700019B0 3C018006 */  lui   $at, %hi(TLB_managment_table_start)
/* 0025B4 700019B4 24020001 */  li    $v0, 1
/* 0025B8 700019B8 000A5900 */  sll   $t3, $t2, 4
/* 0025BC 700019BC 002B0821 */  addu  $at, $at, $t3
/* 0025C0 700019C0 AC22DBF0 */  sw    $v0, %lo(TLB_managment_table_start)($at)
/* 0025C4 700019C4 A0620000 */  sb    $v0, ($v1)
/* 0025C8 700019C8 8FBF0014 */  lw    $ra, 0x14($sp)
.L700019CC:
/* 0025CC 700019CC 27BD0020 */  addiu $sp, $sp, 0x20
/* 0025D0 700019D0 03E00008 */  jr    $ra
/* 0025D4 700019D4 00000000 */   nop   
)
#endif

/**
 * 25D8	700019D8
 * loads ROM range for 7F- TLB entries
 */
#ifdef NONMATCHING
void translate_load_rom_from_TLBaddress(s32 arg0) {
    u32 sp24;
    u32 sp28;
    u32 temp_hi;
    u32 temp_t1;
    u32 temp_t3;
    void *temp_a2;
    ? temp_ret;
    void *temp_v1;

    // Node 0
    maybe_cur_TLB_entries = (s32) (maybe_cur_TLB_entries + 1);
    find_remove_TLB_entry((arg0 & 0x7fffe000));
    temp_hi = (return_tlb_random_value() % 0x5aU);
    tlb_segment_num = temp_hi;
    remove_TLB_entry_from_table(temp_hi);
    temp_t1 = (sp28 & 0xffe000);
    sp24 = temp_t1;
    romCopy((ptr_TLBallocatedblock + (temp_hi << 0xd)), (temp_t1 + &_rarezipSegmentRomEnd), 0x2000);
    osInvalICache(0x40000000, 0x40000000);
    osInvalICache(0x80000000, 0x10000000);
    temp_t3 = (sp24 >> 0xd);
    temp_a2 = ((temp_t3 * 0x10) + &TLB_managment_table_start);
    temp_a2->unk4 = temp_hi;
    sp28 = temp_t3;
    temp_ret = osVirtualToPhysical(sp34, sp24, temp_a2);
    temp_v1 = ((temp_hi * 2) + &TLB_manager_mapping_table_start);
    *temp_v1 = (u8)0;
    temp_v1->unk1 = sp28;
    *sp20 = (s32) (((temp_ret >> 0xc) << 6) | 0x1f);
    return temp_ret;
}
#else
GLOBAL_ASM(
glabel translate_load_rom_from_TLBaddress
/* 0025D8 700019D8 3C028002 */  lui   $v0, %hi(maybe_cur_TLB_entries)
/* 0025DC 700019DC 244230D0 */  addiu $v0, %lo(maybe_cur_TLB_entries) # addiu $v0, $v0, 0x30d0
/* 0025E0 700019E0 8C4E0000 */  lw    $t6, ($v0)
/* 0025E4 700019E4 3C017FFF */  lui   $at, (0x7FFFE000 >> 16) # lui $at, 0x7fff
/* 0025E8 700019E8 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0025EC 700019EC 3421E000 */  ori   $at, (0x7FFFE000 & 0xFFFF) # ori $at, $at, 0xe000
/* 0025F0 700019F0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0025F4 700019F4 00812024 */  and   $a0, $a0, $at
/* 0025F8 700019F8 25CF0001 */  addiu $t7, $t6, 1
/* 0025FC 700019FC AFB00018 */  sw    $s0, 0x18($sp)
/* 002600 70001A00 AC4F0000 */  sw    $t7, ($v0)
/* 002604 70001A04 0C000648 */  jal   find_remove_TLB_entry
/* 002608 70001A08 AFA40028 */   sw    $a0, 0x28($sp)
/* 00260C 70001A0C 0C0006C4 */  jal   return_tlb_random_value
/* 002610 70001A10 00000000 */   nop   
/* 002614 70001A14 2401005A */  li    $at, 90
/* 002618 70001A18 0041001B */  divu  $zero, $v0, $at
/* 00261C 70001A1C 00002010 */  mfhi  $a0
/* 002620 70001A20 3C038002 */  lui   $v1, %hi(tlb_segment_num)
/* 002624 70001A24 246330D4 */  addiu $v1, %lo(tlb_segment_num) # addiu $v1, $v1, 0x30d4
/* 002628 70001A28 AC640000 */  sw    $a0, ($v1)
/* 00262C 70001A2C 0C000655 */  jal   remove_TLB_entry_from_table
/* 002630 70001A30 00808025 */   move  $s0, $a0
/* 002634 70001A34 8FA20028 */  lw    $v0, 0x28($sp)
/* 002638 70001A38 3C198006 */  lui   $t9, %hi(ptr_TLBallocatedblock) 
/* 00263C 70001A3C 8F39E4A8 */  lw    $t9, %lo(ptr_TLBallocatedblock)($t9)
/* 002640 70001A40 3C0100FF */  lui   $at, (0x00FFE000 >> 16) # lui $at, 0xff
/* 002644 70001A44 3421E000 */  ori   $at, (0x00FFE000 & 0xFFFF) # ori $at, $at, 0xe000
/* 002648 70001A48 00104340 */  sll   $t0, $s0, 0xd
/* 00264C 70001A4C 3C0A0003 */  lui   $t2, %hi(_gameSegmentRomStart) # $t2, 3
/* 002650 70001A50 00414824 */  and   $t1, $v0, $at
/* 002654 70001A54 254A4B30 */  addiu $t2, %lo(_gameSegmentRomStart) # addiu $t2, $t2, 0x4b30
/* 002658 70001A58 03282021 */  addu  $a0, $t9, $t0
/* 00265C 70001A5C AFA40034 */  sw    $a0, 0x34($sp)
/* 002660 70001A60 012A2821 */  addu  $a1, $t1, $t2
/* 002664 70001A64 01201025 */  move  $v0, $t1
/* 002668 70001A68 AFA90024 */  sw    $t1, 0x24($sp)
/* 00266C 70001A6C 0C001707 */  jal   romCopy
/* 002670 70001A70 24062000 */   li    $a2, 8192
/* 002674 70001A74 3C044000 */  lui   $a0, 0x4000
/* 002678 70001A78 0C0034D4 */  jal   osInvalICache
/* 00267C 70001A7C 3C054000 */   lui   $a1, 0x4000
/* 002680 70001A80 3C048000 */  lui   $a0, 0x8000
/* 002684 70001A84 0C0034D4 */  jal   osInvalICache
/* 002688 70001A88 3C051000 */   lui   $a1, 0x1000
/* 00268C 70001A8C 8FA50024 */  lw    $a1, 0x24($sp)
/* 002690 70001A90 3C0D8006 */  lui   $t5, %hi(TLB_managment_table_start) 
/* 002694 70001A94 25ADDBF0 */  addiu $t5, %lo(TLB_managment_table_start) # addiu $t5, $t5, -0x2410
/* 002698 70001A98 00055B42 */  srl   $t3, $a1, 0xd
/* 00269C 70001A9C 000B6100 */  sll   $t4, $t3, 4
/* 0026A0 70001AA0 018D3021 */  addu  $a2, $t4, $t5
/* 0026A4 70001AA4 ACD00004 */  sw    $s0, 4($a2)
/* 0026A8 70001AA8 AFA60020 */  sw    $a2, 0x20($sp)
/* 0026AC 70001AAC AFAB0028 */  sw    $t3, 0x28($sp)
/* 0026B0 70001AB0 0C003A2C */  jal   osVirtualToPhysical
/* 0026B4 70001AB4 8FA40034 */   lw    $a0, 0x34($sp)
/* 0026B8 70001AB8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0026BC 70001ABC 00027302 */  srl   $t6, $v0, 0xc
/* 0026C0 70001AC0 0010C840 */  sll   $t9, $s0, 1
/* 0026C4 70001AC4 3C088006 */  lui   $t0, %hi(TLB_manager_mapping_table_start) 
/* 0026C8 70001AC8 8FA50028 */  lw    $a1, 0x28($sp)
/* 0026CC 70001ACC 8FA60020 */  lw    $a2, 0x20($sp)
/* 0026D0 70001AD0 000E7980 */  sll   $t7, $t6, 6
/* 0026D4 70001AD4 2508E3F0 */  addiu $t0, %lo(TLB_manager_mapping_table_start) # addiu $t0, $t0, -0x1c10
/* 0026D8 70001AD8 35F8001F */  ori   $t8, $t7, 0x1f
/* 0026DC 70001ADC 03281821 */  addu  $v1, $t9, $t0
/* 0026E0 70001AE0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0026E4 70001AE4 A0600000 */  sb    $zero, ($v1)
/* 0026E8 70001AE8 27BD0050 */  addiu $sp, $sp, 0x50
/* 0026EC 70001AEC A0650001 */  sb    $a1, 1($v1)
/* 0026F0 70001AF0 03E00008 */  jr    $ra
/* 0026F4 70001AF4 ACD80000 */   sw    $t8, ($a2)
)
#endif

/**
 * 26F8	70001AF8
 * V0=p->TLB memory, or alternately end of free memory [8005E4A8]
 */
u32 * return_ptr_TLBallocatedblock(void)
{
    return ptr_TLBallocatedblock;
}






