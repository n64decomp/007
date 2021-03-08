#include "ultra64.h"
#include "ramrom.h"
#include "tlb_manage.h"
#include "tlb_random.h"
#include "PR/os_cache.h"

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
#define TLB_RANDOM_MOD 90

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
u32 g_tlbmanageMappingTableEnd;
u8 (*g_tlbmanageTlbAllocatedBlock) [TLB_ALLOCATION_BLOCK_SIZE];

extern u8 *_gameSegmentRomStart;
extern u8 *_tlbbufSegmentStart;
extern u8 *sp_boot;

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
