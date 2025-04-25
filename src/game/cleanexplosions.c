#include <ultra64.h>
#include "chrai.h"
#include "explosions.h"
#include <fr.h>

void cleanupExplosions(void)
{
    s32 i;
  
    g_NumExplosionEntries = 0;
    viShake(0.0);

    if (g_ExplosionBuffer != NULL)
    {
        for (i = 0; i<EXPLOSION_BUFFER_LEN; i++)
        {
            if (g_ExplosionBuffer[i].prop != NULL)
            {
                chrpropDelist(g_ExplosionBuffer[i].prop);
                chrpropDisable(g_ExplosionBuffer[i].prop);
                chrpropFree(g_ExplosionBuffer[i].prop);
                g_ExplosionBuffer[i].prop = NULL;
            }
        }
    }

  
    if (g_SmokeBuffer != NULL)
    {
        for (i = 0; i<SMOKE_BUFFER_LEN; i++)
        {
            if (g_SmokeBuffer[i].prop != NULL)
            {
                chrpropDelist(g_SmokeBuffer[i].prop);
                chrpropDisable(g_SmokeBuffer[i].prop);
                chrpropFree(g_SmokeBuffer[i].prop);
                g_SmokeBuffer[i].prop = NULL;
            }
        }
    }
}
