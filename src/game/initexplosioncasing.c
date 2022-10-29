#include <ultra64.h>
#include <memp.h>
#include "initexplosioncasing.h"
#include "explosions.h"



void alloc_explosion_smoke_casing_scorch_impact_buffers(void)
{
    s32 i;
    s32 j;

    numExplosionEntries = 0;
    numSmokeEntries = 0;
    numParticleEntries = 0;
    numScorchEntries = 0;
    numImpactEntries = 0;
    D_80040178 = 1.0f;

    ptr_explosion_buf = (struct Explosion*)mempAllocBytesInBank(EXPLOSION_BUFFER_LEN * sizeof(struct Explosion), 4);

    for (i=0; i<EXPLOSION_BUFFER_LEN; i++)
    {
        ptr_explosion_buf[i].prop = NULL;
        
        for (j=0; j<EXPLOSION_PARTS_LEN; j++)
        {
            ptr_explosion_buf[i].parts[j].frame = 0;
        }
    }

    ptr_smoke_buf = (struct Smoke*)mempAllocBytesInBank(SMOKE_BUFFER_LEN * sizeof(struct Smoke), 4);

    for (i=0; i<SMOKE_BUFFER_LEN; i++)
    {
        ptr_smoke_buf[i].prop = NULL;
        
        for (j=0; j<SMOKE_PARTS_LEN; j++)
        {
            ptr_smoke_buf[i].parts[j].size = 0.0f;
        }
    }

    if (getPlayerCount() == 1)
    {
        // scorches are the circle burn marks left on the ground from explosions
        ptr_scorch_buf = (struct Scorch*)mempAllocBytesInBank(SCORCH_BUFFER_LEN * sizeof(struct Scorch), 4);

        for (i=0; i<SCORCH_BUFFER_LEN; i++)
        {
            ptr_scorch_buf[i].roomid = -1;
        }
    }

    ptr_bullet_impact_buf = (struct BulletImpact*)mempAllocBytesInBank(BULLET_IMPACT_BUFFER_LEN * sizeof(struct BulletImpact), 4);

    for (i=0; i<BULLET_IMPACT_BUFFER_LEN; i++)
    {
        ptr_bullet_impact_buf[i].unk00 = -1;
    }

    max_particles = MAX_FLYING_PARTICLES / getPlayerCount();

    if ((lvlGetCurrentStageToLoad() == LEVELID_STREETS) || (lvlGetCurrentStageToLoad() == LEVELID_DEPOT))
    {
        max_particles = (s32) max_particles >> 1;
    }

    ptr_flying_particles_buf = (struct FlyingParticles*)mempAllocBytesInBank(((max_particles * sizeof(struct FlyingParticles)) + 0xF) & ~0xF, 4);

    for (i=0; i<max_particles; i++)
    {
        ptr_flying_particles_buf[i].unk00 = 0;
    }
}
