#include <ultra64.h>
#include "chr.h"


void cleanupGuardData(void)
{
    int i;

    for (i = 0; i < g_NumChrSlots; i++) {
        if (g_ChrSlots[i].model != 0) {
            disable_sounds_attached_to_player_then_something(g_ChrSlots[i].prop);
            chrpropDelist(g_ChrSlots[i].prop);
            chrpropDisable(g_ChrSlots[i].prop);
            chrpropFree(g_ChrSlots[i].prop);
        }
    }
}
