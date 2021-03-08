#include "ultra64.h"
#include "bondgame.h"
#include "ramrom.h"
#include "deb.h"
#include "str.h"
#include "memp.h"

struct deblistentry
{
    struct deblistentry *next;
    u32 data;
    const char *name;
    s32 unused;
};

u8 g_DebBuffer[0x400];
u32 g_DebDebugData[] = {0, 0};
struct deblistentry *g_DebList = NULL;
s32 D_800232EC[] = {0, 0, 0};
u8 *g_DebMemPos = g_DebBuffer;

struct deblistentry *debFind(const char *name)
{
    struct deblistentry *entry = g_DebList;
    while (entry != NULL) {
        if (strcmp(entry->name, name) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

u8 *debAllocate(s32 size) {
    u8 **pos = &g_DebMemPos;
    u8 *curr = *pos;
    u8 *prev = curr;
    curr += size;
    if (curr > (g_DebBuffer + 0x400)) {
        curr -= size;
        *pos = curr;
        return mempAllocBytesInBank(size, 6);
    } else {
        *pos = curr;
    }
    return prev;
}

void debAdd(const char *name, u32 data) {
    struct deblistentry *entry = debAllocate(sizeof(struct deblistentry));
    entry->next = g_DebList;
    entry->data = data;
    entry->name = name;
    g_DebList = entry;
}

void debInit(void) {
    debTryAdd(&g_DebDebugData, "deb_c_debug");
    init_tlb();
}

void debTryAdd(void* data, const char *name) {
    if (debFind(name) == NULL) {
        debAdd(name, data);
    }
}

void deb70004E98(void) {
    struct deblistentry *entry = g_DebList;
    while (entry != NULL) {
        // Removed
        entry = entry->next; 
    }
}

/**
 * Removed
 */
void deb70004EBC(void) {
    // Removed
}

/**
 * Removed
 */
void deb70004EC4(s32 arg0, s32 arg1, s32 arg2) {
    // Removed
}
