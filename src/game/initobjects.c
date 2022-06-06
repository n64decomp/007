#include <ultra64.h>
#include <memp.h>
#include "bg.h"
#include "initobjects.h"
#include "chrai.h"
#include "chrobjhandler.h"
//this file may very well be a few different sub files

struct object_animation_controller g_InitialMonitorAnimController = {&monAnim00Bond, 0, 0xFFFF, 0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 1.0, 0.0};
struct object_animation_controller g_InitialUnknownAnimController = {&monAnim34, 0, 0xFFFF, 0, 0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1.0};
struct object_animation_controller g_InitialTaserAnimController = {&monAnim35Taser, 0, 0xFFFF, 0, 0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.5, 0.0, 0.0, 0.5, 0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1.0};

f32 unused_8002a3bc = 0.0f;
f32 scale_1_0_item_related = 1.0f;

// forward declarations

void alloc_lookup_buffers();
void write_monitor_ani_control_blocks();
void initialize_temp_mine_table();

// end forward declarations


/**
 * Address 0x7F0014B0.
*/
void init_sound_effects_registers(void)
{
    s32 i;

    for (i=0; i<SFX_RELATED_LEN; i++)
    {
        sfx_related[i].state = AL_STOPPED;
    }

}


/**
 * Address 0x7F0014E0.
*/
void init_load_objpos_table(void)
{
    s32 i;

    difficulty = 1.0f;
    ptr_obj_pos_list_current_entry = 
        ptr_obj_pos_list_first_entry = NULL;
    g_OnScreenPropCount = 0;
    g_OnScreenPropList[0] = NULL;
    g_LastOnScreenProp = (PropRecord *) g_OnScreenPropList;
    ptr_obj_pos_list_final_entry = pos_data_entry;

    for (i=0; i<(POS_DATA_ENTRY_LEN-1); i++)
    {
        pos_data_entry[i].prev = &pos_data_entry[i+1];
    }

    alloc_lookup_buffers();
}


/**
 * Address 0x7F0015D0.
*/
void alloc_lookup_buffers(void)
{
    s32 j;
    s32 i;

    ptr_list_object_lookup_indices = (s16*)mempAllocBytesInBank(PTR_LIST_OBJECT_LOOKUP_INDICES_LEN * sizeof(s16), 4);
    ptr_room_lookup_buffer_maybe = (s16*)mempAllocBytesInBank((((MaxNumRooms * 4) + 0xF) | 0xF) ^ 0xF, 4);
    dword_CODE_bss_8007161C = (s16*)mempAllocBytesInBank(BSS_8007161C_LEN * sizeof(struct unk_8007161c), 4);

    ptr_list_object_lookup_indices[0] = -1;

    for (i=0; i<MaxNumRooms; i++)
    {
        ptr_room_lookup_buffer_maybe[i] = -1;
    }

    for (i=0; i<BSS_8007161C_LEN; i++)
    {
        dword_CODE_bss_8007161C[i].data[0] = -2;

        for (j=1; j<BSS_8007161C_DATA_LEN; j++)
        {
            dword_CODE_bss_8007161C[i].data[j] = -1;
        }
    }
}



/**
 * Address 0x7F001750.
*/
void reinit_between_menus(void)
{
    s32 i;

    write_monitor_ani_control_blocks();
    initialize_temp_mine_table();
    alarm_timer = 0;
    ptr_alarm_sfx = 0;
    toxic_gas_sound_timer = 0.0f;
    activate_gas_sound_timer = 0;
    D_80030AD0.f[0] = 0.0f;
    D_80030AD0.f[1] = 0.0f;
    D_80030AD0.f[2] = 0.0f;
    D_80030ADC = 0;
    D_80030AE0 = 0.0f;
    ptr_gas_sound = 0;
    clock_drawn_flag = 1;
    clock_enable = 0;
    clock_time = 0.0f;
    D_80030AF4 = 0;

    for (i=0; i<PROJECTILEDATA_START_ADDRESS_LEN; i++)
    {
        ProjectileData_start_address[i].unk10 = 0;
    }

    D_80030AF8 = 0;

    for (i=0; i<BSS_80072E70_DATA_LEN; i++)
    {
        dword_CODE_bss_80072E70[i].unk10 = 0;
    }
    
    D_80030AFC = 0;

    for (i=0; i<BSS_80073370_DATA_LEN; i++)
    {
        dword_CODE_bss_80073370[i].unk10 = 0;
    }

    for (i=0; i<BSS_80073DC0_DATA_LEN; i++)
    {
        dword_CODE_bss_80073DC0[i].unk00 = 0x80000000;
        dword_CODE_bss_80073DC0[i].unk98 = 0;
        dword_CODE_bss_80073DC0[i].unk9C = 0;
    }

    for (i=0; i<BSS_80075030_DATA_LEN; i++)
    {
        dword_CODE_bss_80075030[i].unk00 = 1;
    }

    g_LevelLoadPropSwitch = NULL;
    g_LevelLoadPropLockDoor = NULL;
    g_LevelLoadPropSafeItem = NULL;
    D_80030B0C = 0;
    bodypartshot = -1;
    F_80030B14 = 1.0f;
    F_80030B18 = 1.0f;
    F_80030B1C = 1.0f;
    F_80030B20 = 1.0f;
    F_80030B24 = 1.0f;
    g_SoloAmmoMultiplier = 1.0f;
}

/**
 * Called from proplvreset2 when PROPDEF type is PROPDEF_SWITCH.
 * Address 0x7F001910.
*/
void initSetLevelLoadPropSwitch(struct ObjectRecord *arg0)
{
    *((struct ObjectRecord **)&arg0->flags2) = g_LevelLoadPropSwitch;
    g_LevelLoadPropSwitch = arg0;
}


/**
 * Called from proplvreset2 when PROPDEF type is PROPDEF_LOCK_DOOR.
 * Address 0x7F001928.
*/
void initSetLevelLoadPropLockDoor(struct ObjectRecord *arg0)
{
    *((struct ObjectRecord **)&arg0->flags2) = g_LevelLoadPropLockDoor;
    g_LevelLoadPropLockDoor = arg0;
}


/**
 * Called from proplvreset2 when PROPDEF type is PROPDEF_SAFE_ITEM.
 * Address 0x7F001940.
*/
void initSetLevelLoadPropSafeItem(struct ObjectRecord *arg0)
{
    arg0->prop = g_LevelLoadPropSafeItem;
    g_LevelLoadPropSafeItem = arg0;
}


/**
 * Address 0x7F001958.
*/
void write_monitor_ani_control_blocks(void)
{
    struct object_animation_controller spEC;
    struct object_animation_controller sp78;
    struct object_animation_controller sp4;

    spEC = g_InitialMonitorAnimController;
    g_MonitorAnimController = spEC;

    sp78 = g_InitialUnknownAnimController;
    g_UnknownAnimController = sp78;

    sp4 = g_InitialTaserAnimController;
    g_TaserAnimController = sp4;

}


void initialize_temp_mine_table(void)
{
    s32 i;

    for (i=0; i<30; i++)
    {
        temp_mine_table[i] = 0;
    }
}

