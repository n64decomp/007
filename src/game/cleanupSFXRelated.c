#include <ultra64.h>
#include <snd.h>
#include <PR/libaudio.h>
#include "bondview.h"

void cleanupSFXRelated(void) {
    if (SFX_80036458[0] != 0)
    {
        if (sndGetPlayingState(SFX_80036458[0]) != AL_STOPPED)
        {
            sndDeactivate(SFX_80036458[0]);
        }
    }

    if (SFX_80036458[1] != 0)
    {
        if (sndGetPlayingState(SFX_80036458[1]) != AL_STOPPED)
        {
            sndDeactivate(SFX_80036458[1]);
        }
    }

}
