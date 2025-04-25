#include <ultra64.h>
#include "bondconstants.h"
#include "random.h"

struct music_setup
{
  s16 stage_id;
  s16 main_music;
  s16 bg_sound;
  s16 xtrack;
};

// data
//D:8004EB10
struct music_setup music_setup_entries[] = {
    { LEVELID_BUNKER1,   M_BUNKER1,      0xFFFF,   M_BUNKER1X },
    { LEVELID_SILO,      M_SILO,         0xFFFF,   M_SILOX },
    { LEVELID_STATUE,    M_STATUE,       0xFFFF,   M_STATUEPART },
    { LEVELID_CONTROL,   M_CONTROL,      0xFFFF,   M_ELEVATOR_CONTROL },
    { LEVELID_ARCHIVES,  M_ARCHIVES,     0xFFFF,   M_ARCHIVESX },
    { LEVELID_TRAIN,     M_TRAIN,        0xFFFF,   M_TRAINX },
    { LEVELID_FRIGATE,   M_FRIGATE,      0xFFFF,   M_END_SOMETHING },
    { LEVELID_BUNKER2,   M_BUNKER2,      0xFFFF,   M_BUNKER2X },
    { LEVELID_AZTEC,     M_AZTEC,        0xFFFF,   M_AZTECX },
    { LEVELID_STREETS,   M_STREETS,      0xFFFF,   M_STREETSX },
    { LEVELID_DEPOT,     M_DEPOT,        0xFFFF,   M_DEPOTX },
    { LEVELID_EGYPT,     M_EGYPTIAN,     0xFFFF,   M_EGYPTX },
    { LEVELID_DAM,       M_DAM,          0xFFFF,   M_WIND },
    { LEVELID_FACILITY,  M_FACILITY,     0xFFFF,   M_FACILITYX },
    { LEVELID_RUNWAY,    M_RUNWAY,       0xFFFF,   M_RUNWAYPLANE },
    { LEVELID_SURFACE,   M_SURFACE1,     0xFFFF,   M_WIND },
    { LEVELID_JUNGLE,    M_JUNGLE,       0xFFFF,   M_JUNGLEX },
    { LEVELID_CAVERNS,   M_WATERCAVERNS, 0xFFFF,   M_ELEVATOR_WC },
    { LEVELID_CITADEL,   M_CITADEL,      0xFFFF,   0xFFFF },
    { LEVELID_CRADLE,    M_CRADLE,       0xFFFF,   M_CRADLEX },
    { LEVELID_SHO,       M_SURFACE2,     0xFFFF,   0xFFFF },
    { LEVELID_SURFACE2,  M_SURFACE2,     M_WIND,   M_SURFACE2END },
    { LEVELID_CUBA,      M_CUBA,         0xFFFF,   0xFFFF },
    { 0 }
};

//D:8004EBD0
s16 random_tracks[] = {
    M_TRAIN,
    M_DEPOT,
    M_MPTHEME,
    M_CITADEL,
    M_FACILITY,
    M_CONTROL,
    M_DAM,
    M_FRIGATE,
    M_ARCHIVES,
    M_SILO,
    M_MPTHEME2,
    M_STREETS,
    M_BUNKER1,
    M_BUNKER2,
    M_STATUE,
    M_ELEVATOR_CONTROL,
    M_CRADLE,
    M_ELEVATOR_WC,
    M_EGYPTIAN,
    M_AZTEC,
    M_WATERCAVERNS,
    M_SURFACE2,
    M_TRAINX,
    M_FACILITYX,
    M_DEPOTX,
    M_CONTROLX,
    M_WATERCAVERNSX,
    M_DAMX,
    M_FRIGATEX,
    M_ARCHIVESX,
    M_SILOX,
    M_STREETSX,
    M_BUNKER1X,
    M_BUNKER2X,
    M_JUNGLEX,
    M_STATUEX,
    M_AZTECX,
    M_EGYPTX,
    M_CRADLEX,
    M_RUNWAY,
    M_MPTHEME3,
    M_RUNWAYX,
    M_SURFACE1,
    M_NONE
};


/**
 * NTSC address 0x7F0D2720.
*/
s32 getmusictrack_or_randomtrack(s32 arg0)
{
    s32 index;
    
    for (index = 0; music_setup_entries[index].stage_id != 0; index++)
    {
        if (music_setup_entries[index].stage_id == arg0)
        {
            s32 count;
            s32 result;
            
            if (music_setup_entries[index].main_music == -1)
            {
                count = 0;
                while (random_tracks[count] != M_NONE)
                {
                    count++;
                }

                result = random_tracks[randomGetNext() % count];
                return result;
            }

            result = music_setup_entries[index].main_music;
            return result;
        }
    }

    if(1)
    {
        s32 count;
        s32 result;
        
        count = 0;
        
        while (random_tracks[count] != M_NONE)
        {
            count++;
        }
    
        result = random_tracks[randomGetNext() % count];
        return result;
    }
}





s32 musicGetBgTrackForStage(s32 stageID)
{
    s32 i;
    for (i=0; music_setup_entries[i].stage_id!=0; i++)
    {
        if (stageID == music_setup_entries[i].stage_id) 
        {
            return music_setup_entries[i].bg_sound;
        }
    }

    return -1;
}


s32 musicGetXTrackForStage(s32 stageID)
{
    s32 i;
    for (i=0; music_setup_entries[i].stage_id!=0; i++)
    {
        if (stageID == music_setup_entries[i].stage_id) 
        {
            return music_setup_entries[i].xtrack;
        }
    }

    return -1;
}
