#include <ultra64.h>
#include "ramrom.h"
#include "tlb_manage.h"
#include "tlb_random.h"
#include <PR/os.h>

/**
 * @file tlb_manage.c
 * @brief TLB management code for the N64 system.
 * 
 * This file contains functions for managing the Translation Lookaside Buffer (TLB),
 * including setting up TLB entries, removing them, and loading ROM segments into
 * TLB entries.
 */

#define PAGE_SIZE 0x2000

/**
 * N64 (MIPS 4300) has 32 TLB entries.
 */
#define CPU_ARCH_MAX_TLB_ENTRIES 32

/**
 * @brief Converts a segment index to a TLB mask index.
 * 
 * TLB Entry consists of 13 unused bits, 12 bits for mask, and upper 7 bits unused.
 */
#define GET_TLB_MASK_INDEX(x) (x << 13)

/**
 * @brief Converts a TLB mask index to a segment index.
 * 
 * TLB Entry consists of 13 unused bits, 12 bits for mask, and upper 7 bits unused.
 */
#define GET_TLB_INDEX_FROM_MASK(x) (x >> 13)

/**
 * Number of entries in the TLB Management table.
 */
#define MANAGEMENT_TABLE_COUNT  128

/**
 * Number of entries in the mapping table.
 */
#ifndef VERSION_EU
#define MAPPING_TABLE_COUNT 90
#else
#define MAPPING_TABLE_COUNT 93
#endif

#define TLB_SEGMENT_COUNT MAPPING_TABLE_COUNT

/**
 * @brief Structure representing a TLB management table entry.
 * 
 * This structure holds the context value and page number for a TLB entry.
 */
struct TlbManageTableEntry
{
    u32 contextValue;
    s32 pagenum;
    s64 RESERVED;
};

/**
 * @brief Structure representing a TLB mapping table entry.
 * 
 * This structure holds the mapping information for a TLB entry, 
 * including entry identifiers.
 */
struct TlbManageMap
{
    u8 entry0;
    u8 entry1;
};


/** 
 * @brief The current number of TLB entries managed.
 */
s32 g_tlbCurrentEntryCount = 0;

/** 
 * @brief The current segment index used in TLB operations.
 */
u32 g_tlbSegmentIndex = 0;

/** 
 * @brief Table for managing TLB entries.
 */
struct TlbManageTableEntry g_tlbManagementTable[MANAGEMENT_TABLE_COUNT];

/** 
 * @brief Table for mapping TLB entries to segments.
 */
struct TlbManageMap g_tlbMappingTable[MAPPING_TABLE_COUNT];

/** 
 * @brief Marks the end of the TLB mapping table in memory.
 */
u32 g_tlbmanageMappingTableEnd;

/** 
 * @brief Pointer to the block of memory allocated for TLB operations.
 */
u8 (*g_tlbmanageTlbAllocatedBlock) [TLB_BLOCK_SIZE];

extern u8 *_gameSegmentRomStart;
extern u8 *sp_boot;


/**
 * @brief Initializes the TLB management and mapping tables.
 * 
 * This function sets up the TLB management and mapping tables, 
 * initializing each entry to its default state.
 */
void tlbmanageEstablishManagementTable(void)
{
    s32 i;
    for (i = 0; i < MANAGEMENT_TABLE_COUNT; i++)
    {
        g_tlbManagementTable[i].contextValue = 1;
        g_tlbManagementTable[i].pagenum = 0;
    }

    for (i = 0; i < MAPPING_TABLE_COUNT; i++)
    {
        g_tlbMappingTable[i].entry1 = 0;
        g_tlbMappingTable[i].entry0 = 1;
    }

    g_tlbmanageTlbAllocatedBlock = (u8(*)[TLB_BLOCK_SIZE]) (((u32)&sp_boot & ~(PAGE_SIZE - 1)) - (MAPPING_TABLE_COUNT * PAGE_SIZE));
    g_tlbmanageMappingTableEnd = ((u32)&g_tlbManagementTable) + 0xFFC08000;
}

/**
 * @brief Resets the count of current TLB entries managed.
 * 
 * This function resets the `g_tlbCurrentEntryCount` variable to zero,
 * potentially after performing certain checks or operations on TLB entries.
 */
void tlbmanageResetCurrentEntriesCount(void)
{
    s32 *entryCountPtr  = &g_tlbCurrentEntryCount;

    if (g_tlbCurrentEntryCount < 51)
    {
        if (g_tlbCurrentEntryCount < 26)
        {
            s32 tempCount  = *entryCountPtr ;
            if (tempCount )
            {
                // removed
            }
        }
    }

    g_tlbCurrentEntryCount = 0;
}


/**
 * @brief Searches for a TLB entry matching the given index.
 * 
 * This function searches through the TLB entries to find one that matches the given entry value.
 * If found, it returns the index of the entry; otherwise, it returns -0x80000000.
 * 
 * @param entry The TLB entry to search for.
 * @return The index of the matching TLB entry, or -0x80000000 if not found.
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
 * @brief Finds and removes a TLB entry.
 * 
 * This function finds the TLB entry matching the given entry value and removes it.
 * 
 * @param entry The TLB entry to remove.
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
 * @brief Removes a TLB entry from the management table by index.
 * 
 * This function removes the TLB entry at the specified index from the management table.
 * 
 * @param index The index of the TLB entry to remove.
 */
void tlbmanageRemoveEntryByIndex(s32 index)
{
    s32 tlbIndex;

    if (g_tlbMappingTable[index].entry0 == 0)
    {
        tlbIndex = tlbmanageGetIndexForEntry(GET_TLB_MASK_INDEX(g_tlbMappingTable[index].entry1) | 0x7F000000);

        if (!(tlbIndex & 0x80000000))
        {
            osUnmapTLB(tlbIndex);
        }

        g_tlbManagementTable[g_tlbMappingTable[index].entry1].contextValue = 1;
        g_tlbMappingTable[index].entry0 = 1;
    }
}

/**
 * @brief Translates and loads a ROM segment into a TLB entry.
 * 
 * This function handles the translation and loading of a ROM segment into the TLB,
 * managing the corresponding TLB entry for the given address.
 * 
 * @param address The address to load the ROM segment from.
 */
void tlbmanageTranslateLoadRomFromTlbAddress(u32 address)
{
    u32 savedStatusRegister[1]; //speculative
    u32 maskedAddress;
    u32 tlbIndex;
    u32 tlbSegmentIndex;
    u32 originalPageMask[1]; //speculative
    u32 alignedAddress;
    u8 *tlbEntryPointer;
    u32 savedEntryHi[1]; //speculative
    u32 savedEntryLo[1]; //speculative

    // Save current CPU status (speculative)
    //savedStatusRegister[0] = osSetIntMask(OS_IM_NONE);

    // Align the address to the TLB page size
    alignedAddress = address & 0x7FFFE000;
    g_tlbCurrentEntryCount++;

    // Remove the current TLB entry for the aligned address
    tlbmanageRemoveEntry(alignedAddress);

    // Generate the next TLB segment index to be used
    g_tlbSegmentIndex = tlbRandomGetNext() % TLB_SEGMENT_COUNT;
    tlbSegmentIndex = g_tlbSegmentIndex;

    // Save original page mask and EntryHi/Lo values (speculative)
    //originalPageMask[0] = getTLBPageMask(tlbSegmentIndex);
    //savedEntryHi[0] = osGetTLBEntryHi(tlbSegmentIndex);
    //savedEntryLo[0] = osGetTLBEntryLo(tlbSegmentIndex);

    // Remove the current TLB entry at this index
    tlbmanageRemoveEntryByIndex(tlbSegmentIndex);
    
    // Mask the aligned address to the appropriate page mask size
    maskedAddress = alignedAddress & 0xFFE000;
    tlbEntryPointer = &(*g_tlbmanageTlbAllocatedBlock)[GET_TLB_MASK_INDEX(tlbSegmentIndex)];

    // Copy the ROM data into the TLB memory block
    romCopy(tlbEntryPointer, (void*)(((u32)&_gameSegmentRomStart) + (u32)maskedAddress), TLB_BLOCK_SIZE);

    // Invalidate the instruction cache and data cache
    osInvalICache((void *)0x40000000, 0x40000000);
    osInvalICache((void *)0x80000000, 0x10000000);

    // Convert masked address to TLB index
    tlbIndex = GET_TLB_INDEX_FROM_MASK(maskedAddress);
    g_tlbManagementTable[tlbIndex].pagenum = tlbSegmentIndex;

    // Set the TLB management entry with physical address and context value
    g_tlbManagementTable[tlbIndex].contextValue = ((osVirtualToPhysical(tlbEntryPointer) >> 0xC) << 6) | 0x1F;
    g_tlbMappingTable[tlbSegmentIndex].entry0 = 0;
    g_tlbMappingTable[tlbSegmentIndex].entry1 = tlbIndex;

    // Restore original page mask and EntryHi/Lo values (speculative)
    //setTLBPageMask(tlbSegmentIndex, originalPageMask[0]);
    //osSetTLBEntryHi(tlbSegmentIndex, savedEntryHi[0]);
    //osSetTLBEntryLo(tlbSegmentIndex, savedEntryLo[0]);

    // Restore the previous CPU status (speculative)
    //osSetIntMask(savedStatusRegister[0]);
}

/**
 * @brief Returns a pointer to the TLB memory block.
 * 
 * This function returns a pointer to the block of memory allocated for TLB operations,
 * which may be used to manage TLB entries.
 * 
 * @return A pointer to an array of TLB blocks.
 */
u8 (*tlbmanageGetTlbAllocatedBlock(void))[TLB_BLOCK_SIZE]
{
    return g_tlbmanageTlbAllocatedBlock;
}
