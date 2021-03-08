#include "ultra64.h"
#include "deb.h"
#include "game/ob.h"
#include "memp.h"
#include "game/game_debug.h"

// data
//D:8004EAE0
s32 D_8004EAE0[] = {0, 0, 0, 0};

void gameInitDebugNoticeList(void) {
    debTryAdd(&D_8004EAE0, "game_c_debug");
}

void reset_mem_bank_5(void) {
    obBlankResourcesInBank5();
    mempResetBank(5);
    obBlankResourcesLoadedInBank(5);
}

void sub_GAME_7F0D1A7C(void) {
    mempNullNextEntryInBank(5);
    obBlankResourcesLoadedInBank(5);
}





