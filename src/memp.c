#include <ultra64.h>
#include <deb.h>
#include "memp.h"
#include "game/lvl_text.h"

/**
 * EU .data, offset from start of data_seg : 0x3640
*/

/**
 * @file memp.c
 * This file contains code for memp.
 */

//bss
MemoryPool g_mempPools[MEMPOOL_COUNT];

//data
void *ptr_memp_c_debug_debug_notice_list = 0;
s32 needmemallocation = 0;
s32 D_80024408 = 0;
s32 D_8002440C = 0;
s32 D_80024410 = 0;

//overloaded
struct s_mempMVALS sdefaultmvals = {
    MEMPOOL_MF + 1,    0,  // MEMPOOL_MF
    MEMPOOL_ML + 1,    82, // MEMPOOL_ML
    MEMPOOL_ME + 1,    15, // MEMPOOL_ME
    0,                 0   // MEMPOOL_END
};

void mempInit(void)
{
    debTryAdd(&ptr_memp_c_debug_debug_notice_list, "memp_c_debug");
}

const char *tokenFind(s32 arg0, const char *arg1);
long int strtol(const char *str, char **endptr, int base);
void mempCheckMemflagTokens(s32 poolAreaStart, s32 poolAreaSize)
{
    s_mempMVALS poolSizes;

    //set pool 0 to what boss wants (room_model_buffer)
    //pool 0 = TotalPoolArea
    g_mempPools[MEMPOOL_TOTAL].start = poolAreaStart;
    g_mempPools[MEMPOOL_TOTAL].end = poolAreaStart + poolAreaSize;

    poolSizes = sdefaultmvals;

    if (tokenFind(1, "-mf"))
    {
        poolSizes.mf = strtol(tokenFind(1, "-mf"), NULL, 0);
    }
    if (tokenFind(1, "-ml"))
    {
        poolSizes.ml = strtol(tokenFind(1, "-ml"), NULL, 0);
    }
    if (tokenFind(1, "-me"))
    {
        poolSizes.me = strtol(tokenFind(1, "-me"), NULL, 0);
    }
    if (poolSizes.me == 0)
    {
        poolSizes.mf = 0;
        poolSizes.me = ((j_text_trigger ? 308 : 296) * 1024);
        poolSizes.ml = poolAreaSize - poolSizes.me;
    }

    mempSetBankStarts((s32*)&poolSizes);
}

void mempSetBankStarts(s32 poolSizes[MEMPOOL_COUNT+1])
{
    s32 i;
    s32 bankstarts[MEMPOOL_COUNT] = {0};
    s32 mempLen;
    s32 mempRequested;
    s32 mempStart;

    //set MF, ML, ME first
    i = 0;
    do
    {
        // assign the "xxxIndex" the value of xxx+1 then skip "Indices", 0=2=mf, 2=4=ml, 4=6=me, 6=8=end
        bankstarts[poolSizes[i]] = poolSizes[i+1];
        i += 2;
    } while (poolSizes[i] != 0); //while sizes not = 0 (bank 7 = 0)
    //  0 1 2 3            4           5     6
    // {0,0,0,0,poolAreaSize - 303104, 0, 303104}

    //for each bankstart, add current to next
    for (i = MEMPOOL_TOTAL; i < MEMPOOL_COUNT - 1; i++)
    {
        bankstarts[i + 1] += bankstarts[i];
    }
    // {0,0,0,0,poolAreaSize - 303104, poolAreaSize - 303104, poolAreaSize}


    mempRequested = bankstarts[MEMPOOL_COUNT - 1]; //total accumulated size of banks = poolAreaSize
    mempLen  = (g_mempPools[MEMPOOL_TOTAL].end - g_mempPools[MEMPOOL_TOTAL].start);

    //for each bankstart, multiply by total pool size, then divide by size of banks 1-7
    //spread each bank evenly
    for (i = MEMPOOL_TOTAL; i < MEMPOOL_COUNT; i++)
    {
        bankstarts[i] = ((s64)bankstarts[i] * mempLen) / mempRequested;
    }
    // {0,0,0,0,poolAreaSize - 303104, poolAreaSize - 303104, poolAreaSize}

    for (i = MEMPOOL_TOTAL; i < MEMPOOL_COUNT; i++)
    {
        bankstarts[i] = ALIGN16_b(bankstarts[i]);
    }
    // {0,0,0,0,poolAreaSize - 303104, poolAreaSize - 303104, poolAreaSize}


    mempStart = g_mempPools[MEMPOOL_TOTAL].start;
    //for each bank 1-7, add new start position
    for (i = MEMPOOL_TOTAL; i < MEMPOOL_COUNT - 1; i++)
    {
        g_mempPools[i + 1].start = bankstarts[i] + mempStart;
        g_mempPools[i + 1].pos   = 0;
        g_mempPools[i + 1].end   = bankstarts[i + 1] + mempStart;
    }
    /*
                           rel-start              size
    g_memPools[TOTAL]      0                      poolArea
    g_memPools[MF]         0                      0
    g_memPools[2]          0                      0
    g_memPools[ML]         0                      0
    g_memPools[STAGE]      0                      poolAreaSize - 303104
    g_memPools[ME]         poolAreaSize - 303104  0
    g_memPools[PERMANENT]  poolAreaSize - 303104  303104
    */
}

/**
 * A320	70009720
 *     V0=p->A0 bytes of memory allocated in bank A1; fries: AT,V0,V1,A0,A1,A2,A3,T0,T2,T5,T6,T7,T8,T9
 *     accepts: A0=size, A1=bank
 */
#ifdef NONMATCHING
// https://decomp.me/scratch/cdPCZ
// Non-matching - maybe asm?
void *mempAllocBytesInBank(s32 bytes, u8 heap)
{
#    ifdef DEBUG
    if ((heap < 0) || (4 < heap))
    {
        osSyncPrintf(__FILE__, __LINE__, "mempAllocBytesInBank from invalid heap %d!", heap);
    }
#    endif
    for (;;)
    {
        u8 *allocation = g_mempPools[heap].pos;

        if (g_mempPools[heap].pos == 0) // uninitialized
        {
            for (;;);
        }
        else
        {
            if (g_mempPools[heap].pos > g_mempPools[heap].end) // overflow
            {
                nulled_mempLoopAllMemBanks();
                for (;;);
            }

            if (g_mempPools[heap].pos + bytes > g_mempPools[heap].end) // Overflow, try pool 6
            {
                heap = MEMPOOL_PERMANENT;

                if (g_mempPools[MEMPOOL_PERMANENT].pos + bytes <= g_mempPools[MEMPOOL_PERMANENT].end) // good
                {
                    u32 v0 = needmemallocation;
                    if (1);
                    needmemallocation = TRUE;

                    if (v0 == 0);
                }
                else // overflow
                {
                    nulled_mempLoopAllMemBanks();
                    for (;;);
                }
            }
            else // good, allocate the mem and exit
            {
                g_mempPools[heap].pos += bytes;
                g_mempPools[heap].prevpos = allocation;

                if (1);

                return allocation;
            }
        }
    }
}
#else
GLOBAL_ASM(
.text
glabel mempAllocBytesInBank
/* 00A320 70009720 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A324 70009724 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00A328 70009728 30A700FF */  andi  $a3, $a1, 0xff
/* 00A32C 7000972C 3C058006 */  lui   $a1, %hi(g_mempPools)
/* 00A330 70009730 3C0A8002 */  lui   $t2, %hi(needmemallocation)
/* 00A334 70009734 254A4404 */  addiu $t2, %lo(needmemallocation) # addiu $t2, $t2, 0x4404
/* 00A338 70009738 24A53BB0 */  addiu $a1, %lo(g_mempPools) # addiu $a1, $a1, 0x3bb0
/* 00A33C 7000973C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A340 70009740 00803025 */  move  $a2, $a0
/* 00A344 70009744 0007C100 */  sll   $t8, $a3, 4
.L70009748:
/* 00A348 70009748 00B81821 */  addu  $v1, $a1, $t8
/* 00A34C 7000974C 8C620004 */  lw    $v0, 4($v1)
/* 00A350 70009750 14400006 */  bnez  $v0, .L7000976C
/* 00A354 70009754 00404025 */   move  $t0, $v0
/* 00A358 70009758 24190001 */  li    $t9, 1
/* 00A35C 7000975C 3C018002 */  lui   $at, %hi(needmemallocation)
/* 00A360 70009760 AC394404 */  sw    $t9, %lo(needmemallocation)($at)
.L70009764:
/* 00A364 70009764 1000FFFF */  b     .L70009764
/* 00A368 70009768 00000000 */   nop
.L7000976C:
/* 00A36C 7000976C 8C640008 */  lw    $a0, 8($v1)
/* 00A370 70009770 00466821 */  addu  $t5, $v0, $a2
/* 00A374 70009774 0082082B */  sltu  $at, $a0, $v0
/* 00A378 70009778 50200006 */  beql  $at, $zero, .L70009794
/* 00A37C 7000977C 008D082B */   sltu  $at, $a0, $t5
/* 00A380 70009780 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A384 70009784 24070006 */   li    $a3, 6
.L70009788:
/* 00A388 70009788 1000FFFF */  b     .L70009788
/* 00A38C 7000978C 00000000 */   nop
/* 00A390 70009790 008D082B */  sltu  $at, $a0, $t5
.L70009794:
/* 00A394 70009794 50200014 */  beql  $at, $zero, .L700097E8
/* 00A398 70009798 00466821 */   addu  $t5, $v0, $a2
/* 00A39C 7000979C 8CAF0064 */  lw    $t7, 0x64($a1)
/* 00A3A0 700097A0 8CAE0068 */  lw    $t6, 0x68($a1)
/* 00A3A4 700097A4 24070006 */  li    $a3, 6
/* 00A3A8 700097A8 01E6C021 */  addu  $t8, $t7, $a2
/* 00A3AC 700097AC 01D8082B */  sltu  $at, $t6, $t8
/* 00A3B0 700097B0 14200008 */  bnez  $at, .L700097D4
/* 00A3B4 700097B4 00000000 */   nop
/* 00A3B8 700097B8 8D420000 */  lw    $v0, ($t2)
/* 00A3BC 700097BC 24190001 */  li    $t9, 1
/* 00A3C0 700097C0 AD590000 */  sw    $t9, ($t2)
/* 00A3C4 700097C4 5440FFE0 */  bnezl $v0, .L70009748
/* 00A3C8 700097C8 0007C100 */   sll   $t8, $a3, 4
/* 00A3CC 700097CC 1000FFDE */  b     .L70009748
/* 00A3D0 700097D0 0007C100 */   sll   $t8, $a3, 4
.L700097D4:
/* 00A3D4 700097D4 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A3D8 700097D8 00000000 */   nop
.L700097DC:
/* 00A3DC 700097DC 1000FFFF */  b     .L700097DC
/* 00A3E0 700097E0 00000000 */   nop
/* 00A3E4 700097E4 00466821 */  addu  $t5, $v0, $a2
.L700097E8:
/* 00A3E8 700097E8 AC6D0004 */  sw    $t5, 4($v1)
/* 00A3EC 700097EC AC68000C */  sw    $t0, 0xc($v1)
/* 00A3F0 700097F0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A3F4 700097F4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A3F8 700097F8 01001025 */  move  $v0, $t0
/* 00A3FC 700097FC 03E00008 */  jr    $ra
/* 00A400 70009800 00000000 */   nop
)
#endif

#ifdef NONMATCHING
// Mostly regalloc
// https://decomp.me/scratch/IkY1t 98.98%
s32 mempAddEntryOfSizeToBank(u8* ptrdata, u32 newsize, u8 bank)
{
    s32 oldsize;
    s32 diffsize;

    if (needmemallocation && (ptrdata == (u8*)g_mempPools[6].prevpos)) {
        bank = 6;
    }

    if (g_mempPools[bank].pos == 0) {
        while(TRUE) {}
    }

    if (ptrdata != (u8*)g_mempPools[bank].prevpos) {
        return 2;
    }

    oldsize = (g_mempPools[bank].pos - g_mempPools[bank].prevpos);
    diffsize = (newsize - oldsize);

    if (diffsize <= 0) {
        g_mempPools[bank].pos += diffsize;
        return 1;
    }

    if (g_mempPools[bank].pos > g_mempPools[bank].end) {
        nulled_mempLoopAllMemBanks();
        while(TRUE) {}
    }

    if (g_mempPools[bank].pos + diffsize > g_mempPools[bank].end) {
        nulled_mempLoopAllMemBanks();
        while(TRUE) {}
    }

    g_mempPools[bank].pos += diffsize;

    return 1;
}
#else
GLOBAL_ASM(
.text
glabel mempAddEntryOfSizeToBank
/* 00A404 70009804 3C0F8002 */  lui   $t7, %hi(needmemallocation)
/* 00A408 70009808 8DEF4404 */  lw    $t7, %lo(needmemallocation)($t7)
/* 00A40C 7000980C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00A410 70009810 AFA60020 */  sw    $a2, 0x20($sp)
/* 00A414 70009814 30CE00FF */  andi  $t6, $a2, 0xff
/* 00A418 70009818 01C03025 */  move  $a2, $t6
/* 00A41C 7000981C AFBF0014 */  sw    $ra, 0x14($sp)
/* 00A420 70009820 AFA5001C */  sw    $a1, 0x1c($sp)
/* 00A424 70009824 11E00006 */  beqz  $t7, .L70009840
/* 00A428 70009828 00803825 */   move  $a3, $a0
/* 00A42C 7000982C 3C188006 */  lui   $t8, %hi(g_mempPools+0x6C)
/* 00A430 70009830 8F183C1C */  lw    $t8, %lo(g_mempPools+0x6C)($t8)
/* 00A434 70009834 14980002 */  bne   $a0, $t8, .L70009840
/* 00A438 70009838 00000000 */   nop
/* 00A43C 7000983C 24060006 */  li    $a2, 6
.L70009840:
/* 00A440 70009840 3C0A8006 */  lui   $t2, %hi(g_mempPools)
/* 00A444 70009844 254A3BB0 */  addiu $t2, %lo(g_mempPools) # addiu $t2, $t2, 0x3bb0
/* 00A448 70009848 0006C900 */  sll   $t9, $a2, 4
/* 00A44C 7000984C 032A2821 */  addu  $a1, $t9, $t2
/* 00A450 70009850 8CA40004 */  lw    $a0, 4($a1)
/* 00A454 70009854 54800004 */  bnezl $a0, .L70009868
/* 00A458 70009858 8CA6000C */   lw    $a2, 0xc($a1)
.L7000985C:
/* 00A45C 7000985C 1000FFFF */  b     .L7000985C
/* 00A460 70009860 00000000 */   nop
/* 00A464 70009864 8CA6000C */  lw    $a2, 0xc($a1)
.L70009868:
/* 00A468 70009868 8FAB001C */  lw    $t3, 0x1c($sp)
/* 00A46C 7000986C 50E60004 */  beql  $a3, $a2, .L70009880
/* 00A470 70009870 00861023 */   subu  $v0, $a0, $a2
/* 00A474 70009874 1000001A */  b     .L700098E0
/* 00A478 70009878 24020002 */   li    $v0, 2
/* 00A47C 7000987C 00861023 */  subu  $v0, $a0, $a2
.L70009880:
/* 00A480 70009880 01621823 */  subu  $v1, $t3, $v0
/* 00A484 70009884 1C600004 */  bgtz  $v1, .L70009898
/* 00A488 70009888 00836021 */   addu  $t4, $a0, $v1
/* 00A48C 7000988C ACAC0004 */  sw    $t4, 4($a1)
/* 00A490 70009890 10000013 */  b     .L700098E0
/* 00A494 70009894 24020001 */   li    $v0, 1
.L70009898:
/* 00A498 70009898 8CA20008 */  lw    $v0, 8($a1)
/* 00A49C 7000989C 00836821 */  addu  $t5, $a0, $v1
/* 00A4A0 700098A0 0044082B */  sltu  $at, $v0, $a0
/* 00A4A4 700098A4 50200006 */  beql  $at, $zero, .L700098C0
/* 00A4A8 700098A8 004D082B */   sltu  $at, $v0, $t5
/* 00A4AC 700098AC 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A4B0 700098B0 24060006 */   li    $a2, 6
.L700098B4:
/* 00A4B4 700098B4 1000FFFF */  b     .L700098B4
/* 00A4B8 700098B8 00000000 */   nop
/* 00A4BC 700098BC 004D082B */  sltu  $at, $v0, $t5
.L700098C0:
/* 00A4C0 700098C0 10200005 */  beqz  $at, .L700098D8
/* 00A4C4 700098C4 00837021 */   addu  $t6, $a0, $v1
/* 00A4C8 700098C8 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 00A4CC 700098CC 24060006 */   li    $a2, 6
.L700098D0:
/* 00A4D0 700098D0 1000FFFF */  b     .L700098D0
/* 00A4D4 700098D4 00000000 */   nop
.L700098D8:
/* 00A4D8 700098D8 ACAE0004 */  sw    $t6, 4($a1)
/* 00A4DC 700098DC 24020001 */  li    $v0, 1
.L700098E0:
/* 00A4E0 700098E0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00A4E4 700098E4 27BD0018 */  addiu $sp, $sp, 0x18
/* 00A4E8 700098E8 03E00008 */  jr    $ra
/* 00A4EC 700098EC 00000000 */   nop
)
#endif

void nulled_mempLoopAllMemBanks(void) {
    u8 bank;
    for (bank = MEMPOOL_MF; bank < MEMPOOL_COUNT; bank++)
    {
    }
}

s32 mempGetBankSizeLeft(u8 bank) {
    if (needmemallocation) {
        bank = MEMPOOL_PERMANENT;
    }

    if ((bank == MEMPOOL_STAGE) && (g_mempPools[MEMPOOL_STAGE].start == g_mempPools[MEMPOOL_STAGE].end))
    {
        bank = MEMPOOL_PERMANENT;
    }

    return g_mempPools[bank].end - g_mempPools[bank].pos;
}

// Last three bits contains the bank, the rest contains the size.
u32 mempAllocPackedBytesInBank(u32 sizeandbank) {
    return mempAllocBytesInBank((sizeandbank >> 3), (sizeandbank & 7));
}

void mempResetBank(u8 bank) {
    g_mempPools[bank].prevpos = 0;
    g_mempPools[bank].pos = g_mempPools[bank].start;
}

void mempNullNextEntryInBank(u8 bank) {
    nulled_mempLoopAllMemBanks();
    if (g_mempPools[bank].pos != 0) {
        g_mempPools[bank].pos = 0;
    }
}
