#include <ultra64.h>
#include "ramrom.h"
#include <macro.h>

/**
 * @file ramrom.c
 * This file contains code to handle reading and writing rom addresses.
 */


OSIoMesg memoryMesgMB;
OSMesg memoryMesg;
OSMesgQueue memoryMesgQueue;

/**
 * 6760	70005B60
 * external
 * romCreateMesgQueue
 * creates a message queue
 */
void romCreateMesgQueue(void)
{
    osCreateMesgQueue(&memoryMesgQueue, &memoryMesg, 1);
}

/**
 * 6790	70005B90
 * doRomCopy
 * invalidate cache and do pi dma
 */
void doRomCopy(void *target, void *source, u32 size)
{
    osInvalDCache(target, size);
    osPiStartDma(&memoryMesgMB, OS_MESG_PRI_NORMAL, OS_READ, source, target, size, &memoryMesgQueue);
}

/**
 * 67F0	70005BF0
 * romReceiveMesg
 * receives a message queue
 */
void romReceiveMesg(void)
{
    osRecvMesg(&memoryMesgQueue, NULL, OS_MESG_BLOCK);
}

/**
 * 681C	70005C1C
 * external
 * romCopy
 * copy from rom to ram
 */
void romCopy(void *target, void *source, u32 size)
{
    doRomCopy(target, source, size);
    romReceiveMesg();
}

/**
 * 6844	70005C44
 * external
 * romCopyAligned
 * aligns data, does a romCopy(), then returns aligned pointer to target
 */
s32 romCopyAligned(void *target, void *source, s32 length)
{
    s32 target_offset;
    s32 *target_aligned;
    s32 *source_aligned;
    s32 *source_offset;

    source_aligned = align_addr_even((s32)source);
    source_offset = (s32)source - (s32)source_aligned;
    target_aligned = ALIGN16_a((s32)target);
    target_offset = source_offset;
    romCopy(target_aligned, source_aligned, ALIGN16_a((s32)source_offset + length));
    return ((s32)target_aligned + target_offset);
}

/**
 * 68A8	70005CA8
 * doRomWrite
 * actually writes to rom (buffer on Indy)
 */
void doRomWrite(void *source, void *target, u32 size)
{
    osWritebackDCache(source, size);
    osPiStartDma(&memoryMesgMB, OS_MESG_PRI_NORMAL, OS_WRITE, target, source, size, &memoryMesgQueue);
}

/**
 * 6908	70005D08
 * external
 * romWrite
 * let's write to the rom (buffer on Indy)
 */
void romWrite(void *source, void *target, u32 size)
{
    doRomWrite(source, target, size);
    romReceiveMesg();
}
