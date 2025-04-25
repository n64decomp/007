#include <ultra64.h>
#include <music.h>
#include "music_0D2720.h"
#include "watch.h"
#include "mp_music.h"
#include "lvl.h"

#ifdef VERSION_EU
#define MP_MUSIC_FRAMERATE 50
#else
#define MP_MUSIC_FRAMERATE 60
#endif

// bss
//CODE.bss:8008C600
s32 stageMusicID;
//CODE.bss:8008C604
s32 dword_CODE_bss_8008C604;

//CODE.bss:8008C608
s32 music_slot_active_0[4];

//CODE.bss:8008C618
s32 music_slot_minutes_0[4];

//CODE.bss:8008C628
s32 music_slot_seconds_0[4];


// data
//D:800484C0
s32 mission_state = MISSION_STATE_0;



u16 sub_GAME_7F0C0BF0(void)
{
    get_mTrack2Vol();
}

u16 sub_GAME_7F0C0C10(void)
{
    return call_sndGetSfxSlotFirstNaturalVolume();
}


MISSION_STATE_ID get_mission_state(void)
{
    return mission_state;
}



void set_missionstate(MISSION_STATE_ID arg0)
{
    s32 old_mission_state = mission_state;
    
    mission_state = arg0;
    
    switch (old_mission_state)
    {
        case MISSION_STATE_0:
        switch (arg0)
        {
#if defined(VERSION_US)
            case MISSION_STATE_0:
                return;
            case MISSION_STATE_1:
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                return;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4: // switch 2
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                musicTrack3ApplySeqpVol(sub_GAME_7F0C0C10());
                g_musicXTrack3Fade = 0;
                musicTrack3Play(musicGetBgTrackForStage(stageMusicID));
                return;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
#endif
            
#if defined(VERSION_JP) || defined(VERSION_EU)
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1: // switch 2
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                return;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4:
                musicTrack1ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack1Fade = 0;
                musicTrack1Play(getmusictrack_or_randomtrack(stageMusicID));
                musicTrack3ApplySeqpVol(sub_GAME_7F0C0C10());
                g_musicXTrack3Fade = 0;
                musicTrack3Play(musicGetBgTrackForStage(stageMusicID));
                return;
                break;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
#endif
        }
        
        case MISSION_STATE_1:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                break;
            case MISSION_STATE_2:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                musicTrack1FadeOut(0.5f);
                return;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                musicTrack1FadeOut(0.5f);
                return;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                musicTrack1FadeOut(0.02f);
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x3A);
                return;
        }
        
        case MISSION_STATE_2:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                musicTrack1FadeIn(0.5f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(0.5f);
                return;
            case MISSION_STATE_2:
                return;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                return;
            case MISSION_STATE_4:
                break;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_3:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                musicTrack1FadeIn(1.0f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(1.0f);
                return;
            case MISSION_STATE_2:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                return;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4:
                musicTrack1FadeIn(1.0f, sub_GAME_7F0C0BF0());
                musicTrack3FadeIn(1.0f, sub_GAME_7F0C0C10());
                musicTrack2FadeOut(1.0f);
                return;
            case MISSION_STATE_5:
                musicTrack3FadeIn(1.0f, sub_GAME_7F0C0C10());
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                return;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_4:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                break;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                musicTrack1FadeOut(0.5f);
                musicTrack3FadeOut(0.5f);
                return;
            case MISSION_STATE_4:
                break;
            case MISSION_STATE_5:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(musicGetXTrackForStage(stageMusicID));
                musicTrack1FadeOut(0.5f);
                return;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_5:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                break;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                musicTrack2ApplySeqpVol(sub_GAME_7F0C0BF0());
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x18);
                musicTrack3FadeOut(0.5f);
                return;
            case MISSION_STATE_4:
                musicTrack1FadeIn(0.5f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(0.5f);
                return;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                break;
        }
        
        case MISSION_STATE_6:
        switch (arg0)
        {
            case MISSION_STATE_0:
                musicTrack1Stop();
                musicTrack2Stop();
                musicTrack3Stop();
                return;
            case MISSION_STATE_1:
                musicTrack1FadeIn(2.0f, sub_GAME_7F0C0BF0());
                musicTrack2FadeOut(2.0f);
                return;
            case MISSION_STATE_2:
                break;
            case MISSION_STATE_3:
                break;
            case MISSION_STATE_4:
                break;
            case MISSION_STATE_5:
                break;
            case MISSION_STATE_6:
                g_musicXTrack2Fade = 0;
                musicTrack2Play(0x3A);
                return;
        }

        default:
        break;
    }
    
    while(1)
    {
        // error
    }
}




void sub_GAME_7F0C11FC(s32 stagenum)
{
    musicTrack1Stop();
    musicTrack2Stop();
    musicTrack3Stop();
    mission_state = MISSION_STATE_0;
    stageMusicID = stagenum;

    if (musicGetBgTrackForStage(stageMusicID) < 0)
    {
        set_missionstate(MISSION_STATE_1);
    }
    else
    {
        set_missionstate(MISSION_STATE_4);
    }

    return;
}

void set_missionstate_zero(void)
{
    set_missionstate(MISSION_STATE_0);
}

void sub_GAME_7F0C1288(void)
{
    if (musicGetBgTrackForStage(stageMusicID) < 0)
    {
        set_missionstate(MISSION_STATE_2);
    }
    else
    {
        set_missionstate(MISSION_STATE_5);
    }
}

void sub_GAME_7F0C12CC(void)
{
    if (musicGetBgTrackForStage(stageMusicID) < 0)
    {
        set_missionstate(MISSION_STATE_1);
    }
    else
    {
        set_missionstate(MISSION_STATE_4);
    }
}

void sub_GAME_7F0C1310(void)
{
    dword_CODE_bss_8008C604 = mission_state;
    set_missionstate(MISSION_STATE_3);
}

void sub_GAME_7F0C1340(void)
{
    set_missionstate(dword_CODE_bss_8008C604);
}

void sub_GAME_7F0C1364(void)
{
    s32 i;

    for (i=0; i<4; i++)
    {
        music_slot_active_0[i] = 0;
        music_slot_minutes_0[i] = 0;
        music_slot_seconds_0[i] = 0;
    }
}






void reset_all_music_slots(void)
{
    s32 i;
    s32 var_t2;

    var_t2 = 0;

    for (i=0; i<4; i++)
    {
        if (music_slot_active_0[i] || music_slot_minutes_0[i] > 0)
        {
            if (music_slot_minutes_0[i] >= g_ClockTimer)
            {
                music_slot_minutes_0[i] -= g_ClockTimer;
            }
            else
            {
                music_slot_minutes_0[i] = 0;
            }

            if (music_slot_seconds_0[i])
            {
                if (music_slot_seconds_0[i] >= g_ClockTimer)
                {
                    music_slot_seconds_0[i] -= g_ClockTimer;
                }
                else
                {
                    music_slot_seconds_0[i] = 0;
                }

                if (music_slot_seconds_0[i])
                {
                    if ((music_slot_active_0[i]) || (music_slot_minutes_0[i]))
                    {
                        var_t2 = 1;
                    }
                }
                else
                {
                    music_slot_active_0[i] = 0;
                }
            }
        }
    }

    if (g_ClockTimer != 0)
    {
        if ((get_mission_state() == MISSION_STATE_2) || (get_mission_state() == MISSION_STATE_5))
        {
            if (var_t2 == 0)
            {
                sub_GAME_7F0C12CC();
            }
        }
        else if (var_t2 != 0)
        {
            sub_GAME_7F0C1288();
        }
    }
    
}





void musicPlaySlot(s32 slot, s32 min, s32 sec)
{
#ifdef DEBUG
    osSyncPrintf("ai_ifmusicqueueemptyjumpf : %s, State=%x (getlvleveltime60=%f)\n", MUSIC_TRACK_ToString[slot], (music_slot_active_0)[slot], getlvleveltime60);
#endif
    if ((music_slot_active_0)[slot] == FALSE)
    {
        (music_slot_active_0)[slot] = TRUE;
        (music_slot_minutes_0)[slot] = min * MP_MUSIC_FRAMERATE;
        (music_slot_seconds_0)[slot] = sec * MP_MUSIC_FRAMERATE;
    }
}

void musicStopSlot(s32 slot)
{
    s32 i;

    if (-1 < slot)
    {
        (music_slot_active_0)[slot] = 0;
        return;
    }

    for (i=0; i<4; i++)
    {
        music_slot_active_0[i] = 0;
        music_slot_minutes_0[i] = 0;
        music_slot_seconds_0[i] = 0;
    }
}

