#include <ultra64.h>
#include <deb.h>
#include "ob.h"
#include <memp.h>
#include "game_debug.h"

// data
//D:8004EAE0
s32 D_8004EAE0[] = {0, 0, 0, 0};

void gameInit(void) {
    debTryAdd(&D_8004EAE0, "game_c_debug");
}

void reset_mem_bank_5(void) {
    obBlankResourcesInBank5();
    mempResetBank(MEMPOOL_ME);
    obBlankResourcesLoadedInBank(MEMPOOL_ME);
}

void sub_GAME_7F0D1A7C(void) {
    mempNullNextEntryInBank(MEMPOOL_ME);
    obBlankResourcesLoadedInBank(MEMPOOL_ME);
}





