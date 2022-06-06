#include <ultra64.h>
#include "ramrom.h"
#include "tlb_manage.h"
#include "tlb_random.h"
#include <PR/os.h>

/**
 * @file tlb_manage.c
 * This file contains tlb management code. 
 */


/**
 * N64 (MIPS 4300) has 32 TLB entries.
 */
#define CPU_ARCH_MAX_TLB_ENTRIES 32

/**
 * TLB Entry consists of 13 unused bits, 12 bits for mask, and upper 7 bits unused.
 */
#define VAL_TO_TLB_MASK(x) (x << 13)

/**
 * TLB Entry consists of 13 unused bits, 12 bits for mask, and upper 7 bits unused.
 */
#define TLB_MASK_TO_VAL(x) (x >> 13)

/**
 * Number of entries in the TLB Management table.
 */
#define MANAGEMENT_TABLE_COUNT  128

/**
 * Number of entries in the mapping table.
 */
#define MAPPING_TABLE_COUNT  90

/**
 * Chosen by fair dice roll.
 * Guaranteed to be random.
 */
#ifndef VERSION_EU
#define TLB_RANDOM_MOD 90
#else
#define TLB_RANDOM_MOD 93
#endif

struct TlbManageTableEntry
{
    u32 contextValue;
    s32 pagenum;
    s64 RESERVED;
};

struct TlbManageMap
{
    u8 entry0;
    u8 entry1;
};

s32 g_tlbmanageCurrentTlbEntries = 0;
u32 g_tlbmanageTlbSegmentNumber = 0;

struct TlbManageTableEntry g_tlbmanageMangementTable[MANAGEMENT_TABLE_COUNT];
struct TlbManageMap g_tlbmanageMappingTable[MAPPING_TABLE_COUNT];

#ifdef VERSION_EU
/* .bss hack, probably need to extend the above array and reference last element ... */
s32 eu_bss_D_80052E54;
s16 eu_bss_D_80052E58;
s16 eu_bss_D_80052E5A;
#endif

u32 g_tlbmanageMappingTableEnd;
u8 (*g_tlbmanageTlbAllocatedBlock) [TLB_ALLOCATION_BLOCK_SIZE];

extern u8 *_gameSegmentRomStart;
extern u8 *sp_boot;

#ifndef VERSION_EU
void tlbmanageEstablishManagementTable(void)
{
    s32 i;
    for (i = 0; i < MANAGEMENT_TABLE_COUNT; i++)
    {
        g_tlbmanageMangementTable[i].contextValue = 1;
        g_tlbmanageMangementTable[i].pagenum = 0;
    }

    for (i = 0; i < MAPPING_TABLE_COUNT; i++)
    {
        g_tlbmanageMappingTable[i].entry1 = 0;
        g_tlbmanageMappingTable[i].entry0 = 1;
    }

    g_tlbmanageTlbAllocatedBlock = (u8(*)[TLB_ALLOCATION_BLOCK_SIZE]) (((u32)&sp_boot & ~0x1FFF) + 0xFFF4C000);
    g_tlbmanageMappingTableEnd = ((u32)&g_tlbmanageMangementTable) + 0xFFC08000;
}
#else
#ifdef NONMATCHING
void tlbmanageEstablishManagementTable(void)
{
    s32 i;
    for (i = 0; i < MANAGEMENT_TABLE_COUNT; i++)
    {
        g_tlbmanageMangementTable[i].contextValue = 1;
        g_tlbmanageMangementTable[i].pagenum = 0;
    }

    for (i = 0; i < MAPPING_TABLE_COUNT; i++)
    {
        g_tlbmanageMappingTable[i].entry1 = 0;
        g_tlbmanageMappingTable[i].entry0 = 1;
        //get rid of extra copy here from optimizations in EU

    g_tlbmanageTlbAllocatedBlock = (u8(*)[TLB_ALLOCATION_BLOCK_SIZE]) (((u32)&sp_boot & ~0x1FFF) + 0xFFF4C000);
    g_tlbmanageMappingTableEnd = ((u32)&g_tlbmanageMangementTable) + 0xFFC08000;
}
#else
GLOBAL_ASM(
.text
glabel tlbmanageEstablishManagementTable
/* 002860 70001C60 3C038005 */  lui   $v1, %hi(g_tlbmanageMangementTable) # $v1, 0x8005
/* 002864 70001C64 3C028005 */  lui   $v0, %hi(g_tlbmanageMappingTable) # $v0, 0x8005
/* 002868 70001C68 24422DA0 */  addiu $v0, %lo(g_tlbmanageMappingTable) # addiu $v0, $v0, 0x2da0
/* 00286C 70001C6C 246325A0 */  addiu $v1, %lo(g_tlbmanageMangementTable) # addiu $v1, $v1, 0x25a0
/* 002870 70001C70 24040001 */  li    $a0, 1
.L70001C74:
/* 002874 70001C74 24630010 */  addiu $v1, $v1, 0x10
/* 002878 70001C78 0062082B */  sltu  $at, $v1, $v0
/* 00287C 70001C7C AC64FFF0 */  sw    $a0, -0x10($v1)
/* 002880 70001C80 1420FFFC */  bnez  $at, .L70001C74
/* 002884 70001C84 AC60FFF4 */   sw    $zero, -0xc($v1)
/* 002888 70001C88 3C018005 */  lui   $at, %hi(g_tlbmanageMappingTable) # $at, 0x8005
/* 00288C 70001C8C 3C038005 */  lui   $v1, %hi(g_tlbmanageMappingTable+2) # $v1, 0x8005
/* 002890 70001C90 3C028005 */  lui   $v0, %hi(eu_bss_D_80052E5A) # $v0, 0x8005
/* 002894 70001C94 24422E5A */  addiu $v0, %lo(eu_bss_D_80052E5A) # addiu $v0, $v0, 0x2e5a
/* 002898 70001C98 24632DA2 */  addiu $v1, %lo(g_tlbmanageMappingTable+2) # addiu $v1, $v1, 0x2da2
/* 00289C 70001C9C A0202DA1 */  sb    $zero, %lo(g_tlbmanageMappingTable+1)($at)
/* 0028A0 70001CA0 A0242DA0 */  sb    $a0, %lo(g_tlbmanageMappingTable)($at)
.L70001CA4:
/* 0028A4 70001CA4 24630008 */  addiu $v1, $v1, 8
/* 0028A8 70001CA8 A060FFFB */  sb    $zero, -5($v1)
/* 0028AC 70001CAC A064FFFA */  sb    $a0, -6($v1)
/* 0028B0 70001CB0 A060FFFD */  sb    $zero, -3($v1)
/* 0028B4 70001CB4 A064FFFC */  sb    $a0, -4($v1)
/* 0028B8 70001CB8 A060FFFF */  sb    $zero, -1($v1)
/* 0028BC 70001CBC A064FFFE */  sb    $a0, -2($v1)
/* 0028C0 70001CC0 A060FFF9 */  sb    $zero, -7($v1)
/* 0028C4 70001CC4 1462FFF7 */  bne   $v1, $v0, .L70001CA4
/* 0028C8 70001CC8 A064FFF8 */   sb    $a0, -8($v1)
/* 0028CC 70001CCC 3C0E803A */  lui   $t6, %hi(sp_boot) # $t6, 0x803a
/* 0028D0 70001CD0 25CE1AB0 */  addiu $t6, %lo(sp_boot) # addiu $t6, $t6, 0x1ab0
/* 0028D4 70001CD4 2401E000 */  li    $at, -8192
/* 0028D8 70001CD8 01C17824 */  and   $t7, $t6, $at
/* 0028DC 70001CDC 3C01FFF4 */  lui   $at, (0xFFF46000 >> 16) # lui $at, 0xfff4
/* 0028E0 70001CE0 34216000 */  ori   $at, (0xFFF46000 & 0xFFFF) # ori $at, $at, 0x6000
/* 0028E4 70001CE4 01E1C021 */  addu  $t8, $t7, $at
/* 0028E8 70001CE8 3C018005 */  lui   $at, %hi(g_tlbmanageTlbAllocatedBlock) # $at, 0x8005
/* 0028EC 70001CEC AC382E60 */  sw    $t8, %lo(g_tlbmanageTlbAllocatedBlock)($at)
/* 0028F0 70001CF0 3C01FFC0 */  lui   $at, (0xFFC08000 >> 16) # lui $at, 0xffc0
/* 0028F4 70001CF4 3C198005 */  lui   $t9, %hi(g_tlbmanageMangementTable) # $t9, 0x8005
/* 0028F8 70001CF8 273925A0 */  addiu $t9, %lo(g_tlbmanageMangementTable) # addiu $t9, $t9, 0x25a0
/* 0028FC 70001CFC 34218000 */  ori   $at, (0xFFC08000 & 0xFFFF) # ori $at, $at, 0x8000
/* 002900 70001D00 03214021 */  addu  $t0, $t9, $at
/* 002904 70001D04 3C018005 */  lui   $at, %hi(g_tlbmanageMappingTableEnd)
/* 002908 70001D08 03E00008 */  jr    $ra
/* 00290C 70001D0C AC282E5C */   sw    $t0, %lo(g_tlbmanageMappingTableEnd)($at)
)
#endif
#endif

/**
 * Sets g_tlbmanageCurrentTlbEntries to zero.
 */
void tlbmanageResetCurrentEntriesCount(void)
{
    s32 *t = &g_tlbmanageCurrentTlbEntries;

    if (g_tlbmanageCurrentTlbEntries < 51)
    {
        if (g_tlbmanageCurrentTlbEntries < 26)
        {
            s32 t3 = *t;
            if (t3)
            {
                // removed
            }
        }
    }

    g_tlbmanageCurrentTlbEntries = 0;
}


/**
 * 24C0    700018C0
 * searches TLB index for an entry matching A0
 *    V0=index of match or 80000000 if not found
 *    accepts: A0=TLB pointer
 */
s32 tlbmanageGetIndexForEntry(int entry)
{
    s32 index = 0;

    while (index != CPU_ARCH_MAX_TLB_ENTRIES)
    {
        if (__osGetTLBHi(index) == entry)
        {
            return index;
        }

        index++;
    }

    return -0x80000000;
}

/**
 *  2520    70001920
 * find and remove TLB entry A0
 *    accepts: A0=TLB pointer
 *    redirects to 700018C0, 7000D3D0
 */
void tlbmanageRemoveEntry(u32 entry)
{
    s32 index = tlbmanageGetIndexForEntry(entry);

    if (index & 0x80000000)
    {
        return;
    }

    osUnmapTLB(index);
}

/**
 * 2554    70001954
 * remove index A0 TLB entry from table at 8005E3F0
 *    table format:
 *        0x0    1 if dirty
 *        0x1    chunk # (7F000000 | chunk<<D)
 */
void tlbmanageRemoveEntryByIndex(s32 index)
{
    s32 ret;

    if (g_tlbmanageMappingTable[index].entry0 == 0)
    {
        ret = tlbmanageGetIndexForEntry(VAL_TO_TLB_MASK(g_tlbmanageMappingTable[index].entry1) | 0x7F000000);

        if (!(ret & 0x80000000))
        {
            osUnmapTLB(ret);
        }

        g_tlbmanageMangementTable[g_tlbmanageMappingTable[index].entry1].contextValue = 1;
        g_tlbmanageMappingTable[index].entry0 = 1;
    }
}

/**
 * 25D8    700019D8
 * loads ROM range for 7F- TLB entries
 */
void tlbmanageTranslateLoadRomFromTlbAddress(u32 address)
{
    u32 unused_0[1];
    u32 var1;
    u32 var2;
    u32 var4;
    u32 unused_1[1];
    u32 addr_copy;
    u8 *var5; // sp 52
    u32 unused_2[1];
    u32 unused_3[1];

    addr_copy = address & 0x7FFFE000;
    g_tlbmanageCurrentTlbEntries++;
    tlbmanageRemoveEntry(addr_copy);
    g_tlbmanageTlbSegmentNumber = tlbRandomGetNext() % TLB_RANDOM_MOD;
    var4 = g_tlbmanageTlbSegmentNumber;
    tlbmanageRemoveEntryByIndex(var4);
    
    // This is treated as a TLB mask a few lines later.
    // Some (some ...) documentation implies the mask should be 12 bits, but this is only 11 (losing highest bit).
    var1 = addr_copy & 0xFFE000;
    var5 = &(*g_tlbmanageTlbAllocatedBlock)[VAL_TO_TLB_MASK(var4)];

    romCopy(var5, (void*)(((u32)&_gameSegmentRomStart) + (u32)var1), TLB_ALLOCATION_BLOCK_SIZE);

    osInvalICache((void *)0x40000000, 0x40000000);
    osInvalICache((void *)0x80000000, 0x10000000);
    var2 = TLB_MASK_TO_VAL(var1);
    g_tlbmanageMangementTable[var2].pagenum = var4;

    // Gets physical address for "var5", then sets the lowest six bits to 0x1F
    g_tlbmanageMangementTable[var2].contextValue = ((osVirtualToPhysical(var5) >> 0xC) << 6) | 0x1F;
    g_tlbmanageMappingTable[var4].entry0 = 0;
    g_tlbmanageMappingTable[var4].entry1 = var2;
}

/**
 * 26F8    70001AF8
 * V0=p->TLB memory, or alternately end of free memory [8005E4A8]
 * Returns pointer to (an array of TLB blocksize).
 */
u8 (*tlbmanageGetTlbAllocatedBlock(void))[TLB_ALLOCATION_BLOCK_SIZE]
{
    return g_tlbmanageTlbAllocatedBlock;
}
