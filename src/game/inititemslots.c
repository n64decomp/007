#include <ultra64.h>
#include <memp.h>
#include "player.h"
#include "bondinv.h"
#include "inititemslots.h"

void reinit_gunheld_totaltime(void) {
    s32 i;
  
    g_CurrentPlayer->equipallguns = FALSE;
    
    for (i = 0; i != 10; i++) {
        g_CurrentPlayer->gunheldarr[i].totaltime = -1;
    }
}

void alloc_additional_item_slots(s32 additionalentries) {
  g_CurrentPlayer->equipmaxitems = additionalentries + 0x1e;
    g_CurrentPlayer->p_itemcur     = mempAllocBytesInBank((g_CurrentPlayer->equipmaxitems * 0x14 + 0xfU | 0xf) ^ 0xf, MEMPOOL_STAGE);
  bondinvReinitInv();
}
