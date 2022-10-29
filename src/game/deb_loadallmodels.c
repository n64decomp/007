#include <ultra64.h>
#include <bondconstants.h>
#include <memp.h>
#include "chr.h"
#include "chr_b.h"
#include "deb_loadallmodels.h"
#include "loadobjectmodel.h"
#include "aicommands2.h"
#include "dyn.h"
#include "memp.h"

//i belong in a header, probably to another file

ChrRecord global_action_block_temp_buffer = { 0 };

WeaponProjectileModels weapon_models_for_weapon_load = {
    PROJECTILES_TYPE_KNIFE, PROJECTILES_TYPE_GRENADE, 
    PROJECTILES_TYPE_REMOTE_MINE, PROJECTILES_TYPE_PROX_MINE,
    PROJECTILES_TYPE_TIMED_MINE, PROJECTILES_TYPE_ROCKET_ROUND,
    PROJECTILES_TYPE_GLAUNCH_ROUND, 0xFFFFFFFF
};

void init_obj_register_difficulty_vals(void) {
    objectiveregisters1 = 0;
    g_AiAccuracyModifier = 1.0f;
    g_AiDamageModifier = 1.0f;
    g_AiHealthModifier = 1.0f;
    g_AiReactionSpeed = 1.0f;
    g_SeenBondRecentlyGuardCount = 0;
}


void alloc_false_GUARDdata_to_exec_global_action(void)
{
    s32 i;
    s32 count;

    g_ActiveChrs = NULL;
    g_ActiveChrsCount = 0;

    if (!g_CurrentSetup.ailists) { return; }

    count = 0;

    // Count the number of background AI lists
    i = 0;
    while (g_CurrentSetup.ailists[i].ailist)
    {
        if (g_CurrentSetup.ailists[i].ID >= 0x1000)
        {
            g_ActiveChrsCount++;
        }

        i++;
    }

    if (g_ActiveChrsCount > 0)
    {
        ChrRecord tmp;

        // Allocate BG chrs
        g_ActiveChrs = mempAllocBytesInBank(ALIGN16_a(g_ActiveChrsCount * sizeof(ChrRecord)), MEMPOOL_STAGE);

        // Initialise BG chrs
        i = 0;
        while (g_CurrentSetup.ailists[i].ailist)
        {
            if (g_CurrentSetup.ailists[i].ID >= 0x1000)
            {
                tmp = global_action_block_temp_buffer;

                g_ActiveChrs[count] = tmp;

                g_ActiveChrs[count].chrnum = 0xFE;
                g_ActiveChrs[count].ailist = g_CurrentSetup.ailists[i].ailist;
                g_ActiveChrs[count].aioffset = 0;
                g_ActiveChrs[count].aireturnlist = -1;
                g_ActiveChrs[count].actiontype = ACT_NULL;
                count++;
            }

            i++;
        }
    }
}


void debug_object_load_all_models(void)
{
    u8 *cmd = &g_CurrentSetup.ailists[0].ailist->cmd;
    s32 i = 0;
    u16 id;

    if (!cmd) { return; }

    do
    {
        while (TRUE)
        {
            if (cmd[0] == AI_EndList)
            {
                break;
            }

            switch (cmd[0])
            {
                case AI_TRYDroppingItem:
                    id = cmd[2] | (cmd[1] << 8);
                    if (modelLoad(id));
                    break;

                case AI_TRYSpawningChrAtPad:
                    load_body_head_if_not_loaded(cmd[1]);
                    if ((s8)cmd[2] >= 0 && load_body_head_if_not_loaded((s8)cmd[2]));
                    break;

                case AI_TRYSpawningChrNextToChr:
                    load_body_head_if_not_loaded(cmd[1]);
                    if ((s8)cmd[2] >= 0 && load_body_head_if_not_loaded((s8)cmd[2]));
                    break;

                case AI_TRYGiveMeItem:
                    modelLoad(cmd[2] | (cmd[1] << 8));
                    if (weaponLoadProjectileModels(cmd[3]));
                    break;

                case AI_TRYGiveMeHat:
                    modelLoad(cmd[2] | (cmd[1] << 8));
                    break;
            }

            cmd += chraiitemsize(cmd, 0);
        }

        i++;
        cmd = &g_CurrentSetup.ailists[i].ailist->cmd;
    } while (cmd);
}


void debug_weapon_load_table(void)
{
    WeaponProjectileModels tmp = weapon_models_for_weapon_load;
    s32 i;

    for (i = 0; tmp.array[i] >= 0; i++)
    {
        modelLoad(tmp.array[i]);
        if (1);
    }
}
