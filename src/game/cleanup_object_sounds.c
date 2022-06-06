#include <ultra64.h>
#include <PR/libaudio.h>
#include "cleanup_objects.h"
#include "chrai.h" /* SFX_RELATED_LEN */




void cleanupObjectSounds(void) {
    s32 i;

    for (i = 0; i < SFX_RELATED_LEN; i++)
    {
        if (sfx_related[i].state != NULL)
        {
            if (sndGetPlayingState(sfx_related[i].state) != AL_STOPPED)
            {
                sndDeactivate(sfx_related[i].state);
            }
        }
    }
}
