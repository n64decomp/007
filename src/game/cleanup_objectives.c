#include <ultra64.h>
#include "bondtypes.h"
#include "objective_status.h"


void cleanupObjectives(void)
{
    int i;

    for (i = 0; i < OBJECTIVES_MAX; i++)
    {
        if (objective_ptrs[i] != NULL && (objective_ptrs[i]->unkD & 1) && objectiveStatuses[i] != OBJECTIVESTATUS_FAILED)
        {
            objectiveStatuses[i] = OBJECTIVESTATUS_COMPLETE;
        }
    }
}
