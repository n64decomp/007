#include <ultra64.h>
#include "chrai.h"
#include "explosions.h"
#include <fr.h>

void cleanupExplosions(void)
{
    s32 i;
  
    numExplosionEntries = 0;
    viShake(0.0);

    if (ptr_explosion_buf != NULL)
    {
        for (i = 0; i<EXPLOSION_BUFFER_LEN; i++)
        {
            if (ptr_explosion_buf[i].prop != NULL)
            {
                chrpropDelist(ptr_explosion_buf[i].prop);
                chrpropDisable(ptr_explosion_buf[i].prop);
                chrpropFree(ptr_explosion_buf[i].prop);
                ptr_explosion_buf[i].prop = NULL;
            }
        }
    }

  
    if (ptr_smoke_buf != NULL)
    {
        for (i = 0; i<SMOKE_BUFFER_LEN; i++)
        {
            if (ptr_smoke_buf[i].prop != NULL)
            {
                chrpropDelist(ptr_smoke_buf[i].prop);
                chrpropDisable(ptr_smoke_buf[i].prop);
                chrpropFree(ptr_smoke_buf[i].prop);
                ptr_smoke_buf[i].prop = NULL;
            }
        }
    }
}
