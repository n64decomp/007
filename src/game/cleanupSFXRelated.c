#include "ultra64.h"
#include "game/bond.h"

void cleanupSFXRelated(void) {
    if (SFX_80036458 != 0)
    {
        if (sfxGetArg0Unk3F(SFX_80036458) != 0)
        {
            sfxDeactivate(SFX_80036458);
        }
    }

    if (SFX_8003645C != 0)
    {
        if (sfxGetArg0Unk3F(SFX_8003645C) != 0)
        {
            sfxDeactivate(SFX_8003645C);
        }
    }

}