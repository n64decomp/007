#include <ultra64.h>
#include <memp.h>
#include "initexplosioncasing.h"
#include "explosions.h"



void alloc_explosion_smoke_casing_scorch_impact_buffers(void)
{
    s32 i;
    s32 j;

    g_NumExplosionEntries = 0;
    g_NumSmokeEntries = 0;
    g_NumParticleEntries = 0;
    g_NumScorchEntries = 0;
    g_NumImpactEntries = 0;
    g_SpExplosionDamageMult = 1.0f;

    g_ExplosionBuffer = (struct Explosion *)mempAllocBytesInBank(EXPLOSION_BUFFER_LEN * sizeof(struct Explosion), MEMPOOL_STAGE);

    for (i=0; i<EXPLOSION_BUFFER_LEN; i++)
    {
        g_ExplosionBuffer[i].prop = NULL;
        
        for (j=0; j<EXPLOSION_PARTS_LEN; j++)
        {
            g_ExplosionBuffer[i].parts[j].frame = 0;
        }
    }

    g_SmokeBuffer = (struct Smoke *)mempAllocBytesInBank(SMOKE_BUFFER_LEN * sizeof(struct Smoke), MEMPOOL_STAGE);

    for (i=0; i<SMOKE_BUFFER_LEN; i++)
    {
        g_SmokeBuffer[i].prop = NULL;
        
        for (j=0; j<SMOKE_PARTS_LEN; j++)
        {
            g_SmokeBuffer[i].parts[j].size = 0.0f;
        }
    }

    if (getPlayerCount() == 1)
    {
        // scorches are the circle burn marks left on the ground from explosions
        g_ScorchBuffer = (struct Scorch *)mempAllocBytesInBank(SCORCH_BUFFER_LEN * sizeof(struct Scorch), MEMPOOL_STAGE);

        for (i=0; i<SCORCH_BUFFER_LEN; i++)
        {
            g_ScorchBuffer[i].roomid = -1;
        }
    }

    g_BulletImpactBuffer = (struct BulletImpact *)mempAllocBytesInBank(BULLET_IMPACT_BUFFER_LEN * sizeof(struct BulletImpact), MEMPOOL_STAGE);

    for (i=0; i<BULLET_IMPACT_BUFFER_LEN; i++)
    {
        g_BulletImpactBuffer[i].room = -1;
    }

    max_particles = MAX_FLYING_PARTICLES / getPlayerCount();

    if ((lvlGetCurrentStageToLoad() == LEVELID_STREETS) || (lvlGetCurrentStageToLoad() == LEVELID_DEPOT))
    {
        max_particles = (s32) max_particles >> 1;
    }

    g_FlyingParticlesBuffer = (struct FlyingParticles *)mempAllocBytesInBank(((max_particles * sizeof(struct FlyingParticles)) + 0xF) & ~0xF, MEMPOOL_STAGE);

    for (i=0; i<max_particles; i++)
    {
        g_FlyingParticlesBuffer[i].unk00 = 0;
    }
}
