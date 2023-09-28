#include <ultra64.h>
#include <PR/libaudio.h>
#include "game/player.h"

// Address 0x7F007980 NTSC.
// Address 0x7F007900 PAL.
void cleanupplayersoundrelated(void)
{
    int i;
    int j;

    for (i = 0; i < getPlayerCount(); i++)
    {
        for (j = 0; j < 2; j++)
        {
            struct hand *hand = &g_playerPointers[i]->hands[j];
            
            if (hand->audioHandle != NULL && sndGetPlayingState(hand->audioHandle))
            {
                sndDeactivate(hand->audioHandle);
            }
        }
    }
}


