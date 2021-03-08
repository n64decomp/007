#include "ultra64.h"
#include "mema.h"
#include "deb.h"

s32 g_MemoryAllocationBuffer;
s32 g_MemoryAllocationBufferSize;
allocation g_MemoryAllocations[512];
void *g_MemoryAllocationDebugData = NULL;

// Swap two allocations.
void memaSwap(allocation *a, allocation *b) {
    u32 tempaddr = a->addr;
    u32 tempsize = a->size;
    a->addr = b->addr;
    a->size = b->size;
    b->addr = tempaddr;
    b->size = tempsize;
}

// Merge two allocations.
void memaMerge(allocation *a, allocation *b) {
    a->size = (a->size + b->size);
    b->addr = 0;
    b->size = 0;
}

// Do a single iteration over the allocations and attempt to
// merge adjacent ones. Return value indicates if there were
// any merges.
s32 memaIterateAndMergeInternal(allocation *allocations) {
    s32 any = FALSE;
    allocation *prev = &allocations[1];
    allocation *curr = &allocations[2];
    allocation *last = &allocations[509];
    u32 addr = 0;
    while (curr <= last) {
        if (curr->size != 0) {
            if (curr->addr < addr) {
                memaSwap(curr, prev);
            }
            if ((prev->size + addr) == curr->addr) {
                memaMerge(prev, curr);
                curr = prev;
                any = TRUE;
            }
            prev = curr;
            addr = curr->addr;
        }
        curr++;
    }
    return any;
}

// Do multiple merge iterations until there are no
// mergable pairs left.
void memaMergeAll(void) {
    while (memaIterateAndMergeInternal(&g_MemoryAllocations));
}

// Loop through all allocations and attempt to find a free one. Alternatively,
// if two can be merged, then do that and use the leftover one. If none is found,
// then use the smallest allocation in the buffer.
allocation *memaSearch(allocation *allocations) {
    allocation *curr = &allocations[2];
    allocation *best;
    u32 min;
    s32 i;
    for (i = 0; i < 508; i++) {
        while (curr <= &allocations[509]) {
            if (curr->size == 0) {
                return curr;
            }
            if ((u32)curr[1].addr < (u32)curr[0].addr) {
                memaSwap(&curr[0], &curr[1]);
            }
            if (curr[1].addr == (curr[0].size + curr[0].addr)) {
                curr[0].size += curr[1].size;
                curr[1].addr = 0;
                curr[1].size = 0;
                return &curr[1];
            }
            curr++;
        }
        curr = &allocations[2];
    }
    min = 0xFFFFFFFF;
    best = curr;
    while (curr <= &allocations[509]) {
        if (curr->size < min) {            
            best = curr;
            min = curr->size;
        }
        curr++;
    }
    return best;
}

// Register a new allocation. Start by calculating a suitable index to start search from 
// based on the relative address in the buffer. Then look forward and backwards
// for a free allocation. If none is found, then use the more advanced memaSearch method.
void memaRegisterInternal(s32 addr, s32 size) {
    s32 index = ((addr - g_MemoryAllocationBuffer) * 508) / g_MemoryAllocationBufferSize;
    allocation *curr = &g_MemoryAllocations[index + 2];
    while (curr->size != 0) {
        curr++;
    }
    if (curr->addr == -1) {
        curr = &g_MemoryAllocations[index + 2];
        while (curr->size != 0) {
            curr--;
        }
        if (curr->addr == 0) {
            curr = memaSearch(g_MemoryAllocations);
        }
    }
    curr->addr = addr;
    curr->size = size;
}

// Initialize the (removed) debug features.
void memaInit(void) {
    debTryAdd(&g_MemoryAllocationDebugData, "mema_c_debug");
}

// Initialize g_MemoryAllocations given a new buffer. The first
// and last two allocations serve as sentinels.
void memaSetBuffer(s32 buffer, s32 size) {
    allocation *curr;
    g_MemoryAllocations[0].addr = 0;
    g_MemoryAllocations[0].size = 0;
    g_MemoryAllocations[1].addr = 0;
    g_MemoryAllocations[1].size = 0;
    g_MemoryAllocations[510].addr = -1;
    g_MemoryAllocations[510].size = 0;
    g_MemoryAllocations[511].addr = -1;
    g_MemoryAllocations[511].size = 0xFFFFFFFF;
    for (curr = &g_MemoryAllocations[2]; curr <= &g_MemoryAllocations[509]; curr++) {
        curr->addr = 0;
        curr->size = 0;
    }
    g_MemoryAllocations[2].addr = g_MemoryAllocationBuffer = buffer;
    g_MemoryAllocations[2].size = g_MemoryAllocationBufferSize = size;
}

void memaIterateAndMerge(void) {
    memaIterateAndMergeInternal(&g_MemoryAllocations);
}

#ifdef NONMATCHING
// Attempt to free up some memory. Start by looking through the first 16 allocations
// for a suitable one. If none is found, then look through the rest for any that are
// large enough. If this also fails, then do 8 merge iterations and then look through
// entire buffer again. If successful, return the address to the freed memory, otherwise 0.
s32 memaFree(u32 amount) {
    s32 addr;
    u32 diff;
    s32 i;
    allocation *curr = &g_MemoryAllocations[2];
    allocation *best = NULL;
    for (i = 0; i < 16; i++, curr++) {
        if (curr->size >= amount) {
            if (curr->addr == -1) {
                break;
            }
            diff = (curr->size - amount);
            if (diff < 0xFFFFFFFF) {
                best = curr;
                if ((diff < 64) || (diff < (amount / 4))) {
                    break;
                }
            }            
        }
    }
    if (best == NULL) {
        while (curr->size < amount) {
            curr++;
        }
        if (curr->addr == -1) {
            for (i = 0; i < 8; i++) {
                memaIterateAndMergeInternal(g_MemoryAllocations);
            }
            curr = &g_MemoryAllocations[2];
            while (curr->size < amount) {
                curr++;
            }
            if (curr->addr == -1) {
                return 0;
            }
        }
    }
    addr = curr->addr;
    curr->addr += amount;
    curr->size -= amount;
    if (curr->size == 0) {
        curr->addr = 0;
    }
    return addr;
}
#else
GLOBAL_ASM(
.text
glabel memaFree
/* 00AA34 70009E34 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00AA38 70009E38 AFB2001C */  sw    $s2, 0x1c($sp)
/* 00AA3C 70009E3C AFB10018 */  sw    $s1, 0x18($sp)
/* 00AA40 70009E40 00809025 */  move  $s2, $a0
/* 00AA44 70009E44 AFB50028 */  sw    $s5, 0x28($sp)
/* 00AA48 70009E48 AFB00014 */  sw    $s0, 0x14($sp)
/* 00AA4C 70009E4C 3C118006 */  lui   $s1, %hi(g_MemoryAllocations + 0x10)
/* 00AA50 70009E50 AFBF002C */  sw    $ra, 0x2c($sp)
/* 00AA54 70009E54 AFB40024 */  sw    $s4, 0x24($sp)
/* 00AA58 70009E58 AFB30020 */  sw    $s3, 0x20($sp)
/* 00AA5C 70009E5C 26313C38 */  addiu $s1, %lo(g_MemoryAllocations + 0x10) # addiu $s1, $s1, 0x3c38
/* 00AA60 70009E60 2404FFFF */  li    $a0, -1
/* 00AA64 70009E64 00002825 */  move  $a1, $zero
/* 00AA68 70009E68 00008025 */  move  $s0, $zero
/* 00AA6C 70009E6C 2415FFFF */  li    $s5, -1
/* 00AA70 70009E70 24060010 */  li    $a2, 16
.L70009E74:
/* 00AA74 70009E74 8E230004 */  lw    $v1, 4($s1)
/* 00AA78 70009E78 26100001 */  addiu $s0, $s0, 1
/* 00AA7C 70009E7C 0072082B */  sltu  $at, $v1, $s2
/* 00AA80 70009E80 1420000E */  bnez  $at, .L70009EBC
/* 00AA84 70009E84 00721023 */   subu  $v0, $v1, $s2
/* 00AA88 70009E88 8E2E0000 */  lw    $t6, ($s1)
/* 00AA8C 70009E8C 0044082B */  sltu  $at, $v0, $a0
/* 00AA90 70009E90 00127882 */  srl   $t7, $s2, 2
/* 00AA94 70009E94 12AE000B */  beq   $s5, $t6, .L70009EC4
/* 00AA98 70009E98 00000000 */   nop   
/* 00AA9C 70009E9C 10200007 */  beqz  $at, .L70009EBC
/* 00AAA0 70009EA0 2C410040 */   sltiu $at, $v0, 0x40
/* 00AAA4 70009EA4 00402025 */  move  $a0, $v0
/* 00AAA8 70009EA8 14200006 */  bnez  $at, .L70009EC4
/* 00AAAC 70009EAC 02202825 */   move  $a1, $s1
/* 00AAB0 70009EB0 004F082B */  sltu  $at, $v0, $t7
/* 00AAB4 70009EB4 14200003 */  bnez  $at, .L70009EC4
/* 00AAB8 70009EB8 00000000 */   nop   
.L70009EBC:
/* 00AABC 70009EBC 1606FFED */  bne   $s0, $a2, .L70009E74
/* 00AAC0 70009EC0 26310008 */   addiu $s1, $s1, 8
.L70009EC4:
/* 00AAC4 70009EC4 54A00027 */  bnezl $a1, .L70009F64
/* 00AAC8 70009EC8 8CA30000 */   lw    $v1, ($a1)
/* 00AACC 70009ECC 8E380004 */  lw    $t8, 4($s1)
/* 00AAD0 70009ED0 00008025 */  move  $s0, $zero
/* 00AAD4 70009ED4 24140008 */  li    $s4, 8
/* 00AAD8 70009ED8 0312082B */  sltu  $at, $t8, $s2
/* 00AADC 70009EDC 10200006 */  beqz  $at, .L70009EF8
/* 00AAE0 70009EE0 3C138006 */   lui   $s3, %hi(g_MemoryAllocations)
/* 00AAE4 70009EE4 8E39000C */  lw    $t9, 0xc($s1)
.L70009EE8:
/* 00AAE8 70009EE8 26310008 */  addiu $s1, $s1, 8
/* 00AAEC 70009EEC 0332082B */  sltu  $at, $t9, $s2
/* 00AAF0 70009EF0 5420FFFD */  bnezl $at, .L70009EE8
/* 00AAF4 70009EF4 8E39000C */   lw    $t9, 0xc($s1)
.L70009EF8:
/* 00AAF8 70009EF8 8E280000 */  lw    $t0, ($s1)
/* 00AAFC 70009EFC 26733C28 */  addiu $s3, %lo(g_MemoryAllocations) # addiu $s3, $s3, 0x3c28
/* 00AB00 70009F00 56A80017 */  bnel  $s5, $t0, .L70009F60
/* 00AB04 70009F04 02202825 */   move  $a1, $s1
/* 00AB08 70009F08 3C118006 */  lui   $s1, %hi(g_MemoryAllocations + 0x10)
/* 00AB0C 70009F0C 26313C38 */  addiu $s1, %lo(g_MemoryAllocations + 0x10) # addiu $s1, $s1, 0x3c38
.L70009F10:
/* 00AB10 70009F10 0C002694 */  jal   memaIterateAndMergeInternal
/* 00AB14 70009F14 02602025 */   move  $a0, $s3
/* 00AB18 70009F18 26100001 */  addiu $s0, $s0, 1
/* 00AB1C 70009F1C 1614FFFC */  bne   $s0, $s4, .L70009F10
/* 00AB20 70009F20 00000000 */   nop   
/* 00AB24 70009F24 8E690014 */  lw    $t1, 0x14($s3)
/* 00AB28 70009F28 0132082B */  sltu  $at, $t1, $s2
/* 00AB2C 70009F2C 50200007 */  beql  $at, $zero, .L70009F4C
/* 00AB30 70009F30 8E2B0000 */   lw    $t3, ($s1)
/* 00AB34 70009F34 8E2A000C */  lw    $t2, 0xc($s1)
.L70009F38:
/* 00AB38 70009F38 26310008 */  addiu $s1, $s1, 8
/* 00AB3C 70009F3C 0152082B */  sltu  $at, $t2, $s2
/* 00AB40 70009F40 5420FFFD */  bnezl $at, .L70009F38
/* 00AB44 70009F44 8E2A000C */   lw    $t2, 0xc($s1)
/* 00AB48 70009F48 8E2B0000 */  lw    $t3, ($s1)
.L70009F4C:
/* 00AB4C 70009F4C 56AB0004 */  bnel  $s5, $t3, .L70009F60
/* 00AB50 70009F50 02202825 */   move  $a1, $s1
/* 00AB54 70009F54 1000000B */  b     .L70009F84
/* 00AB58 70009F58 00001025 */   move  $v0, $zero
/* 00AB5C 70009F5C 02202825 */  move  $a1, $s1
.L70009F60:
/* 00AB60 70009F60 8CA30000 */  lw    $v1, ($a1)
.L70009F64:
/* 00AB64 70009F64 8CAD0004 */  lw    $t5, 4($a1)
/* 00AB68 70009F68 00726021 */  addu  $t4, $v1, $s2
/* 00AB6C 70009F6C 01B27023 */  subu  $t6, $t5, $s2
/* 00AB70 70009F70 ACAC0000 */  sw    $t4, ($a1)
/* 00AB74 70009F74 15C00002 */  bnez  $t6, .L70009F80
/* 00AB78 70009F78 ACAE0004 */   sw    $t6, 4($a1)
/* 00AB7C 70009F7C ACA00000 */  sw    $zero, ($a1)
.L70009F80:
/* 00AB80 70009F80 00601025 */  move  $v0, $v1
.L70009F84:
/* 00AB84 70009F84 8FBF002C */  lw    $ra, 0x2c($sp)
/* 00AB88 70009F88 8FB00014 */  lw    $s0, 0x14($sp)
/* 00AB8C 70009F8C 8FB10018 */  lw    $s1, 0x18($sp)
/* 00AB90 70009F90 8FB2001C */  lw    $s2, 0x1c($sp)
/* 00AB94 70009F94 8FB30020 */  lw    $s3, 0x20($sp)
/* 00AB98 70009F98 8FB40024 */  lw    $s4, 0x24($sp)
/* 00AB9C 70009F9C 8FB50028 */  lw    $s5, 0x28($sp)
/* 00ABA0 70009FA0 03E00008 */  jr    $ra
/* 00ABA4 70009FA4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif

#ifdef NONMATCHING
// Find the allocation of the given address and reduce its size by the given 
// amount. If successful, return the same address, otherwise 0.
s32 memaShrink(s32 addr, u32 amount) {
    allocation *curr = &g_MemoryAllocations[2];
    while (curr->addr != -1) {
        if ((curr->addr == addr) && (curr->size >= amount)) {
            break;
        }        
        curr++;
        if (curr->addr == -1) {
            return 0;
        }
    }
    curr->addr += amount;
    curr->size -= amount;
    if (curr->size == 0) {
        curr->addr = 0;
    }
    return addr;
}
#else
GLOBAL_ASM(
.text
glabel memaShrink
/* 00ABA8 70009FA8 3C198006 */  lui   $t9, %hi(g_MemoryAllocations + 0x10) 
/* 00ABAC 70009FAC 8F393C38 */  lw    $t9, %lo(g_MemoryAllocations + 0x10)($t9)
/* 00ABB0 70009FB0 3C188006 */  lui   $t8, %hi(g_MemoryAllocations + 0x10) 
/* 00ABB4 70009FB4 240AFFFF */  li    $t2, -1
/* 00ABB8 70009FB8 27183C38 */  addiu $t8, %lo(g_MemoryAllocations + 0x10) # addiu $t8, $t8, 0x3c38
/* 00ABBC 70009FBC 00A03825 */  move  $a3, $a1
/* 00ABC0 70009FC0 1159000C */  beq   $t2, $t9, .L70009FF4
/* 00ABC4 70009FC4 03001825 */   move  $v1, $t8
/* 00ABC8 70009FC8 8F050000 */  lw    $a1, ($t8)
.L70009FCC:
/* 00ABCC 70009FCC 54850006 */  bnel  $a0, $a1, .L70009FE8
/* 00ABD0 70009FD0 8C650008 */   lw    $a1, 8($v1)
/* 00ABD4 70009FD4 8C660004 */  lw    $a2, 4($v1)
/* 00ABD8 70009FD8 00C7082B */  sltu  $at, $a2, $a3
/* 00ABDC 70009FDC 50200008 */  beql  $at, $zero, .L7000A000
/* 00ABE0 70009FE0 00A75821 */   addu  $t3, $a1, $a3
/* 00ABE4 70009FE4 8C650008 */  lw    $a1, 8($v1)
.L70009FE8:
/* 00ABE8 70009FE8 24630008 */  addiu $v1, $v1, 8
/* 00ABEC 70009FEC 1545FFF7 */  bne   $t2, $a1, .L70009FCC
/* 00ABF0 70009FF0 00000000 */   nop   
.L70009FF4:
/* 00ABF4 70009FF4 03E00008 */  jr    $ra
/* 00ABF8 70009FF8 00001025 */   move  $v0, $zero

/* 00ABFC 70009FFC 00A75821 */  addu  $t3, $a1, $a3
.L7000A000:
/* 00AC00 7000A000 00C76023 */  subu  $t4, $a2, $a3
/* 00AC04 7000A004 AC6B0000 */  sw    $t3, ($v1)
/* 00AC08 7000A008 15800002 */  bnez  $t4, .L7000A014
/* 00AC0C 7000A00C AC6C0004 */   sw    $t4, 4($v1)
/* 00AC10 7000A010 AC600000 */  sw    $zero, ($v1)
.L7000A014:
/* 00AC14 7000A014 00801025 */  move  $v0, $a0
/* 00AC18 7000A018 03E00008 */  jr    $ra
/* 00AC1C 7000A01C 00000000 */   nop   
)
#endif

void memaRegister(u32 addr, u32 size) {
    memaRegisterInternal(addr, size);
}

#ifdef NONMATCHING
// ac54:    bnel    v1,v0,0xac54 ~>                  r ac54:    bnel    v0,v1,0xac54 ~>
void mema7000A040(void) {
    s32 i;
    for (i = 0; &g_MemoryAllocations[i] != &g_MemoryAllocations[508]; i += 4) {
        // Removed
    }
}
#else
GLOBAL_ASM(
.text
glabel mema7000A040
/* 00AC40 7000A040 3C038006 */  lui   $v1, %hi(g_MemoryAllocations)
/* 00AC44 7000A044 3C028006 */  lui   $v0, %hi(g_MemoryAllocations + 0xFE0)
/* 00AC48 7000A048 24424C08 */  addiu $v0, %lo(g_MemoryAllocations + 0xFE0) # addiu $v0, $v0, 0x4c08
/* 00AC4C 7000A04C 24633C28 */  addiu $v1, %lo(g_MemoryAllocations) # addiu $v1, $v1, 0x3c28
/* 00AC50 7000A050 24630020 */  addiu $v1, $v1, 0x20
.L7000A054:
/* 00AC54 7000A054 5462FFFF */  bnel  $v1, $v0, .L7000A054
/* 00AC58 7000A058 24630020 */   addiu $v1, $v1, 0x20
/* 00AC5C 7000A05C 03E00008 */  jr    $ra
/* 00AC60 7000A060 00000000 */   nop   
)
#endif

// Calculate the ratio between the sum of all allocations minus
// the largest one, and the sum of all allocations.
f32 memaCalculateNonLargestToTotalRatio(void) {
    u32 tot = 0;
    u32 max = 0;
    allocation *curr = &g_MemoryAllocations[2];
    while (curr->addr != -1) {
        tot += curr->size;
        if (max < curr->size) {
            max = curr->size;
        }
        curr++;
    }
    if (tot == 0) {
        return 0.0f;
    }
    return ((f32)(tot - max) / tot);
}

#ifdef NONMATCHING
// Print a list of allocations, in descending size order. Sizes are specified in
// kilobytes, rounded to nearest integer. Up to 200 allocations can be listed.
void memaDump(void) {
    const char buffer[4096];
    const char *pos;
    s32 count = 0;
    u32 tot = 0;
    s32 lim = (1 << 31);
    allocation *curr = &g_MemoryAllocations[2];
    while (curr->addr != -1) {
        tot += curr->size;
        curr++;
    }
    pos = buffer;
    while (TRUE) {
        u32 max = 0;
        u32 acc = 0;
        curr = &g_MemoryAllocations[2];
        while (curr->addr != -1) {
            if ((curr->size < lim) && (curr->size > max)) {
                max = curr->size;
                acc++;
            }
            curr++;
        }
        if (acc == 0) {
            break;
        }
        curr = &g_MemoryAllocations[2];
        while (curr->addr != -1) {
            if (curr->size == max) {
                if (count < 200) {
                    pos += sprintf(pos, "%d ", ((curr->size + 512) / 1024));
                } else if (count == 200) {
                    pos += sprintf(pos, "...");
                }
                count++;
            }
            curr++;
        }
    }
    if (count > 200) {
        sprintf(pos, "[%d]", count);
    }
}
#else
const char aD_3[] = "%d ";
const char a___[] = "...";
const char aD_5[] = "[%d]";
GLOBAL_ASM(
.text
glabel memaDump
/* 00AD00 7000A100 27BDEF98 */  addiu $sp, $sp, -0x1068
/* 00AD04 7000A104 3C048006 */  lui   $a0, %hi(g_MemoryAllocations + 0x10)
/* 00AD08 7000A108 8C843C38 */  lw    $a0, %lo(g_MemoryAllocations + 0x10)($a0)
/* 00AD0C 7000A10C AFB5002C */  sw    $s5, 0x2c($sp)
/* 00AD10 7000A110 AFB00018 */  sw    $s0, 0x18($sp)
/* 00AD14 7000A114 2415FFFF */  li    $s5, -1
/* 00AD18 7000A118 AFB20020 */  sw    $s2, 0x20($sp)
/* 00AD1C 7000A11C 3C108006 */  lui   $s0, %hi(g_MemoryAllocations + 0x10)
/* 00AD20 7000A120 AFBF003C */  sw    $ra, 0x3c($sp)
/* 00AD24 7000A124 AFBE0038 */  sw    $fp, 0x38($sp)
/* 00AD28 7000A128 AFB70034 */  sw    $s7, 0x34($sp)
/* 00AD2C 7000A12C AFB60030 */  sw    $s6, 0x30($sp)
/* 00AD30 7000A130 AFB40028 */  sw    $s4, 0x28($sp)
/* 00AD34 7000A134 AFB30024 */  sw    $s3, 0x24($sp)
/* 00AD38 7000A138 AFB1001C */  sw    $s1, 0x1c($sp)
/* 00AD3C 7000A13C 3C038000 */  lui   $v1, 0x8000
/* 00AD40 7000A140 00009025 */  move  $s2, $zero
/* 00AD44 7000A144 26103C38 */  addiu $s0, %lo(g_MemoryAllocations + 0x10) # addiu $s0, $s0, 0x3c38
/* 00AD48 7000A148 12A40008 */  beq   $s5, $a0, .L7000A16C
/* 00AD4C 7000A14C 00001025 */   move  $v0, $zero
.L7000A150:
/* 00AD50 7000A150 8E0F0008 */  lw    $t7, 8($s0)
/* 00AD54 7000A154 8E0E0004 */  lw    $t6, 4($s0)
/* 00AD58 7000A158 26100008 */  addiu $s0, $s0, 8
/* 00AD5C 7000A15C 16AFFFFC */  bne   $s5, $t7, .L7000A150
/* 00AD60 7000A160 004E1021 */   addu  $v0, $v0, $t6
/* 00AD64 7000A164 3C108006 */  lui   $s0, %hi(g_MemoryAllocations + 0x10)
/* 00AD68 7000A168 26103C38 */  addiu $s0, %lo(g_MemoryAllocations + 0x10) # addiu $s0, $s0, 0x3c38
.L7000A16C:
/* 00AD6C 7000A16C 3C1E8003 */  lui   $fp, %hi(a___) 
/* 00AD70 7000A170 3C168003 */  lui   $s6, %hi(aD_3)
/* 00AD74 7000A174 27B10054 */  addiu $s1, $sp, 0x54
/* 00AD78 7000A178 26D691E0 */  addiu $s6, %lo(aD_3) # addiu $s6, $s6, -0x6e20
/* 00AD7C 7000A17C 27DE91E4 */  addiu $fp, %lo(a___) # addiu $fp, $fp, -0x6e1c
/* 00AD80 7000A180 00009825 */  move  $s3, $zero
/* 00AD84 7000A184 0000A025 */  move  $s4, $zero
/* 00AD88 7000A188 241700C8 */  li    $s7, 200
.L7000A18C:
/* 00AD8C 7000A18C 12A4000D */  beq   $s5, $a0, .L7000A1C4
/* 00AD90 7000A190 00000000 */   nop   
/* 00AD94 7000A194 8E020004 */  lw    $v0, 4($s0)
.L7000A198:
/* 00AD98 7000A198 0043082B */  sltu  $at, $v0, $v1
/* 00AD9C 7000A19C 10200005 */  beqz  $at, .L7000A1B4
/* 00ADA0 7000A1A0 0262082B */   sltu  $at, $s3, $v0
/* 00ADA4 7000A1A4 50200004 */  beql  $at, $zero, .L7000A1B8
/* 00ADA8 7000A1A8 8E180008 */   lw    $t8, 8($s0)
/* 00ADAC 7000A1AC 00409825 */  move  $s3, $v0
/* 00ADB0 7000A1B0 26940001 */  addiu $s4, $s4, 1
.L7000A1B4:
/* 00ADB4 7000A1B4 8E180008 */  lw    $t8, 8($s0)
.L7000A1B8:
/* 00ADB8 7000A1B8 26100008 */  addiu $s0, $s0, 8
/* 00ADBC 7000A1BC 56B8FFF6 */  bnel  $s5, $t8, .L7000A198
/* 00ADC0 7000A1C0 8E020004 */   lw    $v0, 4($s0)
.L7000A1C4:
/* 00ADC4 7000A1C4 12800022 */  beqz  $s4, .L7000A250
/* 00ADC8 7000A1C8 3C108006 */   lui   $s0, %hi(g_MemoryAllocations + 0x10)
/* 00ADCC 7000A1CC 26103C38 */  addiu $s0, %lo(g_MemoryAllocations + 0x10) # addiu $s0, $s0, 0x3c38
/* 00ADD0 7000A1D0 12A4001C */  beq   $s5, $a0, .L7000A244
/* 00ADD4 7000A1D4 0000A025 */   move  $s4, $zero
/* 00ADD8 7000A1D8 8E020004 */  lw    $v0, 4($s0)
.L7000A1DC:
/* 00ADDC 7000A1DC 2A4100C8 */  slti  $at, $s2, 0xc8
/* 00ADE0 7000A1E0 56620011 */  bnel  $s3, $v0, .L7000A228
/* 00ADE4 7000A1E4 8E080008 */   lw    $t0, 8($s0)
/* 00ADE8 7000A1E8 10200008 */  beqz  $at, .L7000A20C
/* 00ADEC 7000A1EC 02202025 */   move  $a0, $s1
/* 00ADF0 7000A1F0 24460200 */  addiu $a2, $v0, 0x200
/* 00ADF4 7000A1F4 0006CA82 */  srl   $t9, $a2, 0xa
/* 00ADF8 7000A1F8 03203025 */  move  $a2, $t9
/* 00ADFC 7000A1FC 0C002B25 */  jal   sprintf
/* 00AE00 7000A200 02C02825 */   move  $a1, $s6
/* 00AE04 7000A204 10000006 */  b     .L7000A220
/* 00AE08 7000A208 02228821 */   addu  $s1, $s1, $v0
.L7000A20C:
/* 00AE0C 7000A20C 16570004 */  bne   $s2, $s7, .L7000A220
/* 00AE10 7000A210 02202025 */   move  $a0, $s1
/* 00AE14 7000A214 0C002B25 */  jal   sprintf
/* 00AE18 7000A218 03C02825 */   move  $a1, $fp
/* 00AE1C 7000A21C 02228821 */  addu  $s1, $s1, $v0
.L7000A220:
/* 00AE20 7000A220 26520001 */  addiu $s2, $s2, 1
/* 00AE24 7000A224 8E080008 */  lw    $t0, 8($s0)
.L7000A228:
/* 00AE28 7000A228 26100008 */  addiu $s0, $s0, 8
/* 00AE2C 7000A22C 56A8FFEB */  bnel  $s5, $t0, .L7000A1DC
/* 00AE30 7000A230 8E020004 */   lw    $v0, 4($s0)
/* 00AE34 7000A234 3C108006 */  lui   $s0, %hi(g_MemoryAllocations + 0x10)
/* 00AE38 7000A238 3C048006 */  lui   $a0, %hi(g_MemoryAllocations + 0x10)
/* 00AE3C 7000A23C 8C843C38 */  lw    $a0, %lo(g_MemoryAllocations + 0x10)($a0)
/* 00AE40 7000A240 26103C38 */  addiu $s0, %lo(g_MemoryAllocations + 0x10) # addiu $s0, $s0, 0x3c38
.L7000A244:
/* 00AE44 7000A244 02601825 */  move  $v1, $s3
/* 00AE48 7000A248 1000FFD0 */  b     .L7000A18C
/* 00AE4C 7000A24C 00009825 */   move  $s3, $zero
.L7000A250:
/* 00AE50 7000A250 2A4100C9 */  slti  $at, $s2, 0xc9
/* 00AE54 7000A254 14200005 */  bnez  $at, .L7000A26C
/* 00AE58 7000A258 02202025 */   move  $a0, $s1
/* 00AE5C 7000A25C 3C058003 */  lui   $a1, %hi(aD_5)
/* 00AE60 7000A260 24A591E8 */  addiu $a1, %lo(aD_5) # addiu $a1, $a1, -0x6e18
/* 00AE64 7000A264 0C002B25 */  jal   sprintf
/* 00AE68 7000A268 02403025 */   move  $a2, $s2
.L7000A26C:
/* 00AE6C 7000A26C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 00AE70 7000A270 8FB00018 */  lw    $s0, 0x18($sp)
/* 00AE74 7000A274 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00AE78 7000A278 8FB20020 */  lw    $s2, 0x20($sp)
/* 00AE7C 7000A27C 8FB30024 */  lw    $s3, 0x24($sp)
/* 00AE80 7000A280 8FB40028 */  lw    $s4, 0x28($sp)
/* 00AE84 7000A284 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00AE88 7000A288 8FB60030 */  lw    $s6, 0x30($sp)
/* 00AE8C 7000A28C 8FB70034 */  lw    $s7, 0x34($sp)
/* 00AE90 7000A290 8FBE0038 */  lw    $fp, 0x38($sp)
/* 00AE94 7000A294 03E00008 */  jr    $ra
/* 00AE98 7000A298 27BD1068 */   addiu $sp, $sp, 0x1068
)
#endif

// Dump a list of allocations before and after a full
// merge pass.
void memaDumpPrePostMerge(void) {
    s32 i;    
    memaDump();
    for (i = 0; i < 508; i++) {
        memaIterateAndMergeInternal(&g_MemoryAllocations);
    }
    memaDump();
}

void mema7000A2F8(void (*func)(u32, allocation*)) {
    allocation *curr = &g_MemoryAllocations[2];
    while (curr->addr != -1) {
        func((curr->addr + curr->size), curr);
        curr++;
    }
}

// Return the size of the largest allocation, after
// a full merge pass.
u32 memaGetLargestAllocSize(void) {
    allocation *curr;
    u32 max = 0;
    memaMergeAll();
    curr = &g_MemoryAllocations[2];
    while (curr->addr != -1) {
        if (max < curr->size) {
            max = curr->size;
        }
        curr++;
    }
    if (max != 0) {
        return max;
    }
    return 0;
}

#ifdef NONMATCHING
// Resize an existing allocation. Either by shrinking the old one, or
// by registering a new allocation containing the remaining bytes.
s32 memaResize(s32 addr, u32 newsize, u32 oldsize) {
    if (newsize < oldsize) {
        if (memaShrink((addr + newsize), (oldsize - newsize)) == 0) {
            return 0;
        } else {
            return 1;
        }
    }
    else {
        if (newsize > oldsize) {
            memaRegister((addr + oldsize), (newsize - oldsize));
        }
        return 1;
    }
}
#else
GLOBAL_ASM(
.text
glabel memaResize
/* 00AFDC 7000A3DC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00AFE0 7000A3E0 00A6082B */  sltu  $at, $a1, $a2
/* 00AFE4 7000A3E4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 00AFE8 7000A3E8 AFA40018 */  sw    $a0, 0x18($sp)
/* 00AFEC 7000A3EC 1020000A */  beqz  $at, .L7000A418
/* 00AFF0 7000A3F0 00A03825 */   move  $a3, $a1
/* 00AFF4 7000A3F4 00852021 */  addu  $a0, $a0, $a1
/* 00AFF8 7000A3F8 0C0027EA */  jal   memaShrink
/* 00AFFC 7000A3FC 00C52823 */   subu  $a1, $a2, $a1
/* 00B000 7000A400 14400003 */  bnez  $v0, .L7000A410
/* 00B004 7000A404 00000000 */   nop   
/* 00B008 7000A408 1000000A */  b     .L7000A434
/* 00B00C 7000A40C 00001025 */   move  $v0, $zero
.L7000A410:
/* 00B010 7000A410 10000008 */  b     .L7000A434
/* 00B014 7000A414 24020001 */   li    $v0, 1
.L7000A418:
/* 00B018 7000A418 00C7082B */  sltu  $at, $a2, $a3
/* 00B01C 7000A41C 10200004 */  beqz  $at, .L7000A430
/* 00B020 7000A420 8FA90018 */   lw    $t1, 0x18($sp)
/* 00B024 7000A424 01262021 */  addu  $a0, $t1, $a2
/* 00B028 7000A428 0C002808 */  jal   memaRegister
/* 00B02C 7000A42C 00E62823 */   subu  $a1, $a3, $a2
.L7000A430:
/* 00B030 7000A430 24020001 */  li    $v0, 1
.L7000A434:
/* 00B034 7000A434 8FBF0014 */  lw    $ra, 0x14($sp)
/* 00B038 7000A438 27BD0018 */  addiu $sp, $sp, 0x18
/* 00B03C 7000A43C 03E00008 */  jr    $ra
/* 00B040 7000A440 00000000 */   nop   
)
#endif
