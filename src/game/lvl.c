#include <ultra64.h>
#include <math.h>
#include <os_extension.h>
#include <PR/libaudio.h>
#include <assets/font_dl.h>
#include <deb.h>
#include <memp.h>
#include <music.h>
#include <tlb_manage.h>
#include <fr.h>
#include <snd.h>
#include <ramrom.h>
#include <random.h>
#include <joy.h>
#include <token.h>
#include "debugmenu_handler.h"
#include "lvl.h"
#include "lvl_text.h"
#include "initcheattext.h"
#include "front.h"
#include "bondinv.h"
#include "player.h"
#include "player_2.h"
#include "chrobjhandler.h"
#include "cleanup_objects.h"
#include "explosions.h"
#include "chrai.h"
#include "mp_music.h"
#include "initunk_005520.h"
#include "initmttex.h"
#include "unk_0A1DA0.h"
#include "image_bank.h"
#include "textrelated.h"
#include "initmenus.h"
#include "cheat_buttons.h"
#include "bg.h"
#include "watch.h"
#include "objective.h"
#include "mp_watch.h"
#include "unk_09B7A0.h"
#include "initunk_005450.h"
#include "initobjects.h"
#include "initguards.h"
#include "prop.h"
#include "initexplosioncasing.h"
#include "alloc_window_pieces.h"
#include "initunk_007290.h"
#include "initcheattext.h"
#include "initpathtablelinks.h"
#include "ejectedcartridges.h"
#include "inititemslots.h"
#include "initBondDATA.h"
#include "bondview.h"
#include "bondview_r.h"
#include "initBondDATAdefaults.h"
#include "viewport.h"
#include "stan.h"
#include "gun.h"
#include "unk_091080.h"
#include "mp_music.h"
#include "unk_0BC530.h"
#include "unk_092E50.h"
#include "unk_0C0A70.h"
#include "chr.h"

// bss
//CODE.bss:8008C260
u32 *ptr_font_DL;
//CODE.bss:8008C264
s32 dword_CODE_bss_8008C264;
s32 dword_CODE_bss_8008C268;
s32 dword_CODE_bss_8008C26C;
//CODE.bss:8008C270
char ramrom_data_target[0x380];
//CODE.bss:8008C5F0
s32 record_slot_num;
//CODE.bss:8008C5F4
s32 address_demo_loaded;
//CODE.bss:8008C5F8
s32 dword_CODE_bss_8008C5F8;


// data
//D:80048360
s32 lvl_c_debug_notice_list = 0;
//D:80048364
s32 g_CurrentStageToLoad = 0;
//D:80048368
f32 D_80048368 = 1.0;
//D:8004836C
s32 musictrack1_playing = 0;
//D:80048370
s32 g_ControlsLockedFlag = 0;
//D:80048374
s32 g_ClockTimer = 0;


#if defined (BUGFIX_R1)
// addresses updated, per build\ge007.j.map
// 800483a8
f32 g_JP_GlobalTimerDelta = 0;
// 800483ac
s32 g_GlobalTimer = 0;
// 800483b0
s32 D_80048380 = 0;
// 800483b4
f32 g_GlobalTimerDelta = 0;
#else
//D:80048378
f32 g_GlobalTimerDelta = 0;
//D:8004837C
s32 g_GlobalTimer = 0;
//D:80048380
s32 D_80048380 = 0;
//D:80048384
#endif
/*
* Selected difficulty mode.
* 0x80048384
*/
s32 g_SelectedDifficulty = DIFFICULTY_AGENT;

//D:80048388
s32 D_80048388 = 0;
//D:8004838C
s32 D_8004838C = 0;
//D:80048390
s32 D_80048390 = 0;
//D:80048394
s32 D_80048394 = 0;

/**
 * Address 0x80048398.
 */
s32 g_MpTime = 0x8CA0;

/**
 * Address 0x8004839C.
 */
s32 g_MpPoint = 0xA;

/**
 * Address 0x800483A0.
 */
ALSoundState * g_MpSoundStateRelated = NULL;

/**
 * Address 0x800483A4.
 */
f32 g_CurrentMultiPlayerSec = 0.0;

//D:800483A8
s32 D_800483A8 = 0;

/**
 * Address 0x800483AC.
 */
f32 g_CurrentMultiPlayerMin = 0.0;

//D:800483B0
s32 D_800483B0 = 0;

/**
 * Address 0x800483B4.
 */
f32 g_StageTimeSec = 0;

//D:800483B8
s32 D_800483B8 = 0;

/**
 * Power on time in seconds.
 * Address 0x800483BC.
 */
f32 g_PowerOnTimeSec = 0;

/**
 * Debug variable, seems to track whether user input has changed since
 * the last time the method was entered.
 * 
 * Addres 0x800483C0.
 */
s32 D_800483C0 = 1;

//D:800483C4
s32 D_800483C4 = 0xFFFFFFFF;

//D:800483C8
struct LvlMpUnknown *D_800483C8 = NULL;

/**
* Debug variable, something to do with portals.
* Address 0x800483CC.
*/
u32 g_DebugPortalsD_800483CC = 0;

/**
 * Input buffer, used in debug portal method. Might be array.
 * Address 0x800483D0.
 */
s32 g_DebugPortalsInputBuffer_0 = 0;

/**
 * Input buffer, used in debug portal method. Might be array.
 * Address 0x800483D4.
 */
s32 g_DebugPortalsInputBuffer_1 = 0;

/**
 * Input buffer, used in debug portal method. Might be array.
 * Address 0x800483D8.
 */
s32 g_DebugPortalsInputBuffer_2 = 0;

/**
 * Input buffer, used in debug portal method. Might be array.
 * Address 0x800483DC.
 */
s32 g_DebugPortalsInputBuffer_3 = 0;

/**
 * Input buffer, used in debug portal method. Might be array.
 * Address 0x800483E0.
 */
s32 g_DebugPortalsInputBuffer_4 = 0;

/**
 * Something debug related in the MP manage method.
 * Index to play sound effect.
 * Address 0x800483E4.
 */
s16 g_DebugMpGameSoundFxIndex = 0;

// unused address padding
s16 D_800483E6 = 0;


extern u8* _fontdlSegmentRomStart;
extern u8* _fontdlSegmentRomEnd;


// forward declarations

Gfx * lvlPortalDebug7F0BDF10(Gfx * arg0);

// end forward declarations

s32 sub_GAME_7F0BD8F0(void)
{
    return D_800483C0;
}

void sub_GAME_7F0BD8FC(s32 arg0)
{
    D_800483C0 = arg0;
}

void lvInitDebugNoticeList(void)
{
    s32 size;

    debTryAdd(&lvl_c_debug_notice_list, "lv_c_debug");
    size = (s32)&_fontdlSegmentRomEnd - (s32)&_fontdlSegmentRomStart;
    lvl_c_debug_notice_list = 1;
    ptr_font_DL = mempAllocBytesInBank(size, 6);
    romCopy(ptr_font_DL, &_fontdlSegmentRomStart, size);
}

/**
 * Unreferenced.
 */
void lvlPlayRandomMusicTrack1(void)
{
    musictrack1_playing = randomGetNext() % 0x3dU + M_INTRO;
    musicTrack1Play(musictrack1_playing);
}

void lvlPlayMusicTrack1(MUSIC_TRACKS track)
{
    musictrack1_playing = track;
    musicTrack1Play(musictrack1_playing);
}

void lvlMusicAppendPlaySoloDeathShort(void)
{
    musictrack1_playing = (musictrack1_playing + M_SHORT_SOLO_DEATH) % NUM_MUSIC_TRACKS;

    if (musictrack1_playing == M_NONE)
    {
        musictrack1_playing = M_SHORT_SOLO_DEATH;
    }

    musicTrack1Play(musictrack1_playing);
}

void lvlMusicAppendPlayEndTheme(void)
{
    musictrack1_playing = (musictrack1_playing + M_END_SOMETHING) % NUM_MUSIC_TRACKS;

    if (musictrack1_playing == M_NONE)
    {
        musictrack1_playing = M_END_SOMETHING;
    }

    musicTrack1Play(musictrack1_playing);
}

/**
 * Unreferenced.
 */
void lvlMusicPlayStageTrackOrRandom(void)
{
    lvlPlayMusicTrack1(getmusictrack_or_randomtrack(g_CurrentStageToLoad));
}



#ifdef NONMATCHING
/**
 * Stage load method.
 * Title screen is handled as a special case.
 * First half of method resets stage and player values (including mutliplayer values) to defaults.
 * Second part loads stage data (init guards, init guard heads, etc).
 * 
 * Address: 0x7F0BDAB0.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: yes
 * - identical registers: fail
 * 
 * notes: only regalloc issues. Problem seems to be around the do{}while / for loop on g_playerPlayerData.
 */
void lvlStageLoad(s32 stage)
{
    s32 i;
    struct player_data *player_data;
 
    g_CurrentStageToLoad = stage;

    // this if block pushes where g_CurrentStageToLoad gets loaded to the
    // top of the method. Maybe a debug log about which level is loaded.
    if(0)
    {
        #ifdef DEBUG
        // removed
        #endif
    }

    D_800483C0 = 1;
    g_ControlsLockedFlag = 0;
    g_ClockTimer = 1;

#ifdef VERSION_US
    g_GlobalTimerDelta = 1.0f;
#endif
#ifdef VERSION_JP
    g_JP_GlobalTimerDelta = 1.0f;
#endif

    D_80048380 = 0;
    g_GlobalTimer = 0;

#ifdef VERSION_JP
    g_GlobalTimerDelta = 1.f;
#endif

    D_80048388 = 0;
    D_8004838C = 0;
    D_80048390 = 0;
    D_80048394 = 0;
    g_CurrentMultiPlayerSec = 0.0f;
    D_800483B0 = 0;
    g_StageTimeSec = 0.0f;
    g_MpSoundStateRelated = 0;

    sndSetScalerApplyVolumeAllSfxSlot(1.0f);
    musicTrack1ApplySeqpVol(VOLUME_MAX);
    musicTrack2ApplySeqpVol(VOLUME_MAX);
    musicTrack3ApplySeqpVol(VOLUME_MAX);
    sub_GAME_7F0C1364();
    set_contents_of_80036078(1);
    set_mt_tex_alloc();
    sub_GAME_7F0A47D4();
    texReset();
    load_font_tables();

    /* If title screen, initialize screen and folder setup. 
    * Otherwise:
    * - enable cheats for player
    * - init watch
    * - reset some player values, like view height
    * - reset multiplayer stats
    */
    if (stage == LEVELID_TITLE)
    {
        init_menus_or_reset();
    }
    else
    {
        g_NewCheatUnlocked = 0;

        if ((g_CurrentStageToLoad != LEVELID_TITLE) && (D_80048394 == 0) && (g_ClockTimer > 0))
        {
            if (g_AppendCheatSinglePlayer != 0)
            {
                s32 s0 = 1;

                for (s0 = 1; s0 != CHEAT_INVALID; s0++)
                {
                    if (g_CheatActivated[s0] && cheatIsEnemyRockets(s0))
                    {
                        cheatButtonTurnOnCheatForPlayers(s0);
                    }
                }
            }
        }

        load_bg_file(g_CurrentStageToLoad);
        skySetStageNum(g_CurrentStageToLoad);
        init_watch_at_start_of_stage();
        sub_GAME_7F0C11FC(stage);

        // why oh why are there two pointers for the same data.
        // g_playerPlayerData should be s2
        // then copied into s4
        player_data = (struct player_data *)&g_playerPlayerData;

        for (i=0; i<4; i++, player_data++)
        {
            if (getPlayerCount() == 1)
            {
                // s4 variable
                player_data->autoaim = 0;
                player_data->sight = 0;
                player_data->handicap = 1.0f;
                player_data->player_perspective_height = 1.0f;
            }
            else
            {
                s32 s3;

                // why is this looping from g_playerPlayerData again, this inner block
                // gets executed 16 times in multiplayer.
                for (s3 = 0; s3 < 4; s3++)
                {
                    if (get_scenario() == SCENARIO_LTK)
                    {
                        g_playerPlayerData[s3].handicap = 200.0f;
                    }
                    else
                    {
                        g_playerPlayerData[s3].handicap = get_player_mp_handicap(s3);
                    }
                    
                    g_playerPlayerData[s3].player_perspective_height = get_player_mp_char_height(s3);
                }

                lvlSetMpTime(get_mp_timelimit());
                lvlSetMpPoint(get_mp_pointlimit());
                copy_aim_settings_to_playerdata();
            }

            // g_playerPlayerData s4 variable
            player_data->time_other_players_on_screen = 0;
            player_data->damage_to_backside = 0;
            player_data->min_time_between_kills = 0x7FFFFFFF;
            player_data->max_time_between_kills = 0;
            player_data->most_killed_one_life = 0;
            player_data->most_killed_one_time = 0;
            player_data->longest_inning = 0;
            player_data->shortest_inning = 0x7FFFFFFF;
            player_data->order_out_in_yolt = 0;
            player_data->flag_counter = 0;
            player_data->distance_traveled = 0.0f; // one kind of float zero
            player_data->body_armor_pickups = 0.f; // a different kind of float zero

            // g_playerPlayerData s2, different than above
            g_playerPlayerData[i].killed_p4 = 0;
            g_playerPlayerData[i].killed_p3 = 0;
            g_playerPlayerData[i].killed_p2 = 0;
            g_playerPlayerData[i].killed_p1 = 0;
        }
    }

    something_with_stage_objectives();
    mpwatchUnpauseGame();
    sub_GAME_7F09B820();
    sub_GAME_7F005450();
    zero_contents_of_80036070_74();
    init_load_objpos_table();
    reinit_between_menus();
    init_sound_effects_registers();
    init_guards();
    set_new_rand_head_bodies(stage);
    proplvreset2(stage);
    alloc_explosion_smoke_casing_scorch_impact_buffers();
    alloc_shattered_window_pieces();
    sub_GAME_7F007290();
    initCheatTextBuffer();

    if (g_CurrentStageToLoad == LEVELID_TITLE)
    {
        disableOnscreenCheatText();
    }
    else
    {
        s32 s0;
        
        init_path_table_links();
        init_ejected_cartridges();

        for (s0 = 0; s0 < getPlayerCount(); s0++)
        {
            set_cur_player(s0);
            reinit_gunheld_totaltime();
            init_player_BONDdata_stats();
            init_player_BONDdata();
            bondviewLoadSetupIntroSection();
            bondviewPlayerSpawnRelated();
            sets_a_bunch_of_BONDdata_values_to_default();
            disableOnscreenCheatText();
        }

        set_cur_player(0);
    }

    set_contents_of_80036078(0);
    zbufDeallocate();
    viSetVideoMode(1);
    D_80048368 = 1.0f;
    lvlSetControlsLockedFlag(0);
}
#endif
#ifdef VERSION_US
GLOBAL_ASM(
.text
glabel lvlStageLoad
/* 0F25E0 7F0BDAB0 3C018005 */  lui   $at, %hi(g_CurrentStageToLoad)
/* 0F25E4 7F0BDAB4 AC248364 */  sw    $a0, %lo(g_CurrentStageToLoad)($at)
/* 0F25E8 7F0BDAB8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F25EC 7F0BDABC 44816000 */  mtc1  $at, $f12
/* 0F25F0 7F0BDAC0 24020001 */  li    $v0, 1
/* 0F25F4 7F0BDAC4 3C018005 */  lui   $at, %hi(D_800483C0)
/* 0F25F8 7F0BDAC8 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F25FC 7F0BDACC AC2283C0 */  sw    $v0, %lo(D_800483C0)($at)
/* 0F2600 7F0BDAD0 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F2604 7F0BDAD4 3C018005 */  lui   $at, %hi(g_ControlsLockedFlag)
/* 0F2608 7F0BDAD8 3C118005 */  lui   $s1, %hi(g_ClockTimer)
/* 0F260C 7F0BDADC AC208370 */  sw    $zero, %lo(g_ControlsLockedFlag)($at)
/* 0F2610 7F0BDAE0 26318374 */  addiu $s1, %lo(g_ClockTimer) # addiu $s1, $s1, -0x7c8c
/* 0F2614 7F0BDAE4 AE220000 */  sw    $v0, ($s1)
/* 0F2618 7F0BDAE8 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 0F261C 7F0BDAEC E42C8378 */  swc1  $f12, %lo(g_GlobalTimerDelta)($at)
/* 0F2620 7F0BDAF0 3C018005 */  lui   $at, %hi(D_80048380)
/* 0F2624 7F0BDAF4 AC208380 */  sw    $zero, %lo(D_80048380)($at)
/* 0F2628 7F0BDAF8 3C018005 */  lui   $at, %hi(g_GlobalTimer)
/* 0F262C 7F0BDAFC AC20837C */  sw    $zero, %lo(g_GlobalTimer)($at)

/* 0F2630 7F0BDB00 3C018005 */  lui   $at, %hi(D_80048388)
/* 0F2634 7F0BDB04 AC208388 */  sw    $zero, %lo(D_80048388)($at)
/* 0F2638 7F0BDB08 3C018005 */  lui   $at, %hi(D_8004838C)
/* 0F263C 7F0BDB0C AC20838C */  sw    $zero, %lo(D_8004838C)($at)
/* 0F2640 7F0BDB10 AFB00020 */  sw    $s0, 0x20($sp)
/* 0F2644 7F0BDB14 3C018005 */  lui   $at, %hi(D_80048390)
/* 0F2648 7F0BDB18 44800000 */  mtc1  $zero, $f0
/* 0F264C 7F0BDB1C 3C108005 */  lui   $s0, %hi(D_80048394)
/* 0F2650 7F0BDB20 AC208390 */  sw    $zero, %lo(D_80048390)($at)
/* 0F2654 7F0BDB24 26108394 */  addiu $s0, %lo(D_80048394) # addiu $s0, $s0, -0x7c6c

/* 0F2658 7F0BDB28 AE000000 */  sw    $zero, ($s0)
/* 0F265C 7F0BDB2C 3C018005 */  lui   $at, %hi(g_CurrentMultiPlayerSec)
/* 0F2660 7F0BDB30 E42083A4 */  swc1  $f0, %lo(g_CurrentMultiPlayerSec)($at)
/* 0F2664 7F0BDB34 3C018005 */  lui   $at, %hi(D_800483B0)
/* 0F2668 7F0BDB38 AC2083B0 */  sw    $zero, %lo(D_800483B0)($at)
/* 0F266C 7F0BDB3C 3C018005 */  lui   $at, %hi(g_StageTimeSec)
/* 0F2670 7F0BDB40 E42083B4 */  swc1  $f0, %lo(g_StageTimeSec)($at)
/* 0F2674 7F0BDB44 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0F2678 7F0BDB48 3C018005 */  lui   $at, %hi(g_MpSoundStateRelated)
/* 0F267C 7F0BDB4C AFB40030 */  sw    $s4, 0x30($sp)
/* 0F2680 7F0BDB50 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F2684 7F0BDB54 AFB20028 */  sw    $s2, 0x28($sp)
/* 0F2688 7F0BDB58 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0F268C 7F0BDB5C AFA40038 */  sw    $a0, 0x38($sp)
/* 0F2690 7F0BDB60 0C00248E */  jal   sndSetScalerApplyVolumeAllSfxSlot
/* 0F2694 7F0BDB64 AC2083A0 */   sw    $zero, %lo(g_MpSoundStateRelated)($at)
/* 0F2698 7F0BDB68 0C001C0F */  jal   musicTrack1ApplySeqpVol
/* 0F269C 7F0BDB6C 24047FFF */   li    $a0, 32767
/* 0F26A0 7F0BDB70 0C001CF1 */  jal   musicTrack2ApplySeqpVol
/* 0F26A4 7F0BDB74 24047FFF */   li    $a0, 32767
/* 0F26A8 7F0BDB78 0C001DD3 */  jal   musicTrack3ApplySeqpVol
/* 0F26AC 7F0BDB7C 24047FFF */   li    $a0, 32767
/* 0F26B0 7F0BDB80 0FC304D9 */  jal   sub_GAME_7F0C1364
/* 0F26B4 7F0BDB84 00000000 */   nop
/* 0F26B8 7F0BDB88 0FC0154D */  jal   set_contents_of_80036078
/* 0F26BC 7F0BDB8C 24040001 */   li    $a0, 1
/* 0F26C0 7F0BDB90 0FC01CC8 */  jal   set_mt_tex_alloc
/* 0F26C4 7F0BDB94 00000000 */   nop
/* 0F26C8 7F0BDB98 0FC291F5 */  jal   sub_GAME_7F0A47D4
/* 0F26CC 7F0BDB9C 00000000 */   nop
/* 0F26D0 7F0BDBA0 0FC32FEC */  jal   texReset
/* 0F26D4 7F0BDBA4 00000000 */   nop
/* 0F26D8 7F0BDBA8 0FC2B2EB */  jal   load_font_tables
/* 0F26DC 7F0BDBAC 00000000 */   nop
/* 0F26E0 7F0BDBB0 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0F26E4 7F0BDBB4 2401005A */  li    $at, 90
/* 0F26E8 7F0BDBB8 15E10005 */  bne   $t7, $at, .L7F0BDBD0
/* 0F26EC 7F0BDBBC 00000000 */   nop
/* 0F26F0 7F0BDBC0 0FC00348 */  jal   init_menus_or_reset
/* 0F26F4 7F0BDBC4 00000000 */   nop
/* 0F26F8 7F0BDBC8 10000073 */  b     .L7F0BDD98
/* 0F26FC 7F0BDBCC 00000000 */   nop
.L7F0BDBD0:
/* 0F2700 7F0BDBD0 3C048005 */  lui   $a0, %hi(g_CurrentStageToLoad)
/* 0F2704 7F0BDBD4 8C848364 */  lw    $a0, %lo(g_CurrentStageToLoad)($a0)
/* 0F2708 7F0BDBD8 3C018007 */  lui    $at, %hi(g_NewCheatUnlocked) # -0.000000
/* 0F270C 7F0BDBDC AC209790 */  sw    $zero, %lo(g_NewCheatUnlocked)($at)
/* 0F2710 7F0BDBE0 2401005A */  li    $at, 90
/* 0F2714 7F0BDBE4 1081001C */  beq   $a0, $at, .L7F0BDC58
/* 0F2718 7F0BDBE8 00000000 */   nop
/* 0F271C 7F0BDBEC 8E180000 */  lw    $t8, ($s0)
/* 0F2720 7F0BDBF0 17000019 */  bnez  $t8, .L7F0BDC58
/* 0F2724 7F0BDBF4 00000000 */   nop
/* 0F2728 7F0BDBF8 8E390000 */  lw    $t9, ($s1)
/* 0F272C 7F0BDBFC 3C088003 */  lui   $t0, %hi(g_AppendCheatSinglePlayer)
/* 0F2730 7F0BDC00 1B200015 */  blez  $t9, .L7F0BDC58
/* 0F2734 7F0BDC04 00000000 */   nop
/* 0F2738 7F0BDC08 8D08A900 */  lw    $t0, %lo(g_AppendCheatSinglePlayer)($t0)
/* 0F273C 7F0BDC0C 3C118007 */  lui   $s1, %hi(g_CheatActivated + 1)
/* 0F2740 7F0BDC10 263196A1 */  addiu $s1, %lo(g_CheatActivated + 1) # addiu $s1, $s1, -0x695f
/* 0F2744 7F0BDC14 11000010 */  beqz  $t0, .L7F0BDC58
/* 0F2748 7F0BDC18 24100001 */   li    $s0, 1
/* 0F274C 7F0BDC1C 2412004B */  li    $s2, 75
.L7F0BDC20:
/* 0F2750 7F0BDC20 92290000 */  lbu   $t1, ($s1)
/* 0F2754 7F0BDC24 51200008 */  beql  $t1, $zero, .L7F0BDC48
/* 0F2758 7F0BDC28 26100001 */   addiu $s0, $s0, 1
/* 0F275C 7F0BDC2C 0FC24697 */  jal   cheatIsEnemyRockets
/* 0F2760 7F0BDC30 02002025 */   move  $a0, $s0
/* 0F2764 7F0BDC34 50400004 */  beql  $v0, $zero, .L7F0BDC48
/* 0F2768 7F0BDC38 26100001 */   addiu $s0, $s0, 1
/* 0F276C 7F0BDC3C 0FC246AB */  jal   cheatButtonTurnOnCheatForPlayers
/* 0F2770 7F0BDC40 02002025 */   move  $a0, $s0
/* 0F2774 7F0BDC44 26100001 */  addiu $s0, $s0, 1
.L7F0BDC48:
/* 0F2778 7F0BDC48 1612FFF5 */  bne   $s0, $s2, .L7F0BDC20
/* 0F277C 7F0BDC4C 26310001 */   addiu $s1, $s1, 1
/* 0F2780 7F0BDC50 3C048005 */  lui   $a0, %hi(g_CurrentStageToLoad)
/* 0F2784 7F0BDC54 8C848364 */  lw    $a0, %lo(g_CurrentStageToLoad)($a0)
.L7F0BDC58:
/* 0F2788 7F0BDC58 0FC2D049 */  jal   load_bg_file
/* 0F278C 7F0BDC5C 00000000 */   nop
/* 0F2790 7F0BDC60 3C048005 */  lui   $a0, %hi(g_CurrentStageToLoad)
/* 0F2794 7F0BDC64 0FC2510B */  jal   skySetStageNum
/* 0F2798 7F0BDC68 8C848364 */   lw    $a0, %lo(g_CurrentStageToLoad)($a0)
/* 0F279C 7F0BDC6C 0FC2921A */  jal   init_watch_at_start_of_stage
/* 0F27A0 7F0BDC70 00000000 */   nop
/* 0F27A4 7F0BDC74 0FC3047F */  jal   sub_GAME_7F0C11FC
/* 0F27A8 7F0BDC78 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F27AC 7F0BDC7C 3C0A8008 */  lui   $t2, %hi(g_playerPlayerData)
/* 0F27B0 7F0BDC80 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0F27B4 7F0BDC84 25529EF0 */  addiu $s2, $t2, %lo(g_playerPlayerData)
/* 0F27B8 7F0BDC88 4481A000 */  mtc1  $at, $f20
/* 0F27BC 7F0BDC8C 0240A025 */  move  $s4, $s2
/* 0F27C0 7F0BDC90 24130004 */  li    $s3, 4
.L7F0BDC94:
/* 0F27C4 7F0BDC94 0FC26919 */  jal   getPlayerCount
/* 0F27C8 7F0BDC98 00000000 */   nop
/* 0F27CC 7F0BDC9C 24010001 */  li    $at, 1
/* 0F27D0 7F0BDCA0 14410009 */  bne   $v0, $at, .L7F0BDCC8
/* 0F27D4 7F0BDCA4 00008025 */   move  $s0, $zero
/* 0F27D8 7F0BDCA8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F27DC 7F0BDCAC 44812000 */  mtc1  $at, $f4
/* 0F27E0 7F0BDCB0 44813000 */  mtc1  $at, $f6
/* 0F27E4 7F0BDCB4 A280006A */  sb    $zero, 0x6a($s4)
/* 0F27E8 7F0BDCB8 A280006B */  sb    $zero, 0x6b($s4)
/* 0F27EC 7F0BDCBC E684005C */  swc1  $f4, 0x5c($s4)
/* 0F27F0 7F0BDCC0 1000001C */  b     .L7F0BDD34
/* 0F27F4 7F0BDCC4 E6860064 */   swc1  $f6, 0x64($s4)
.L7F0BDCC8:
/* 0F27F8 7F0BDCC8 3C118008 */  lui   $s1, %hi(g_playerPlayerData)
/* 0F27FC 7F0BDCCC 26319EF0 */  addiu $s1, %lo(g_playerPlayerData) # addiu $s1, $s1, -0x6110
.L7F0BDCD0:
/* 0F2800 7F0BDCD0 0FC051D6 */  jal   get_scenario
/* 0F2804 7F0BDCD4 00000000 */   nop
/* 0F2808 7F0BDCD8 14530003 */  bne   $v0, $s3, .L7F0BDCE8
/* 0F280C 7F0BDCDC 00000000 */   nop
/* 0F2810 7F0BDCE0 10000004 */  b     .L7F0BDCF4
/* 0F2814 7F0BDCE4 E634005C */   swc1  $f20, 0x5c($s1)
.L7F0BDCE8:
/* 0F2818 7F0BDCE8 0FC040EB */  jal   get_player_mp_handicap
/* 0F281C 7F0BDCEC 02002025 */   move  $a0, $s0
/* 0F2820 7F0BDCF0 E620005C */  swc1  $f0, 0x5c($s1)
.L7F0BDCF4:
/* 0F2824 7F0BDCF4 0FC040F4 */  jal   get_player_mp_char_height
/* 0F2828 7F0BDCF8 02002025 */   move  $a0, $s0
/* 0F282C 7F0BDCFC 26100001 */  addiu $s0, $s0, 1
/* 0F2830 7F0BDD00 26310070 */  addiu $s1, $s1, 0x70
/* 0F2834 7F0BDD04 1613FFF2 */  bne   $s0, $s3, .L7F0BDCD0
/* 0F2838 7F0BDD08 E620FFF4 */   swc1  $f0, -0xc($s1)
/* 0F283C 7F0BDD0C 0FC04108 */  jal   get_mp_timelimit
/* 0F2840 7F0BDD10 00000000 */   nop
/* 0F2844 7F0BDD14 0FC2FF0A */  jal   lvlSetMpTime
/* 0F2848 7F0BDD18 00402025 */   move  $a0, $v0
/* 0F284C 7F0BDD1C 0FC04111 */  jal   get_mp_pointlimit
/* 0F2850 7F0BDD20 00000000 */   nop
/* 0F2854 7F0BDD24 0FC2FF0D */  jal   lvlSetMpPoint
/* 0F2858 7F0BDD28 00402025 */   move  $a0, $v0
/* 0F285C 7F0BDD2C 0FC04076 */  jal   copy_aim_settings_to_playerdata
/* 0F2860 7F0BDD30 00000000 */   nop
.L7F0BDD34:
/* 0F2864 7F0BDD34 44804000 */  mtc1  $zero, $f8
/* 0F2868 7F0BDD38 44805000 */  mtc1  $zero, $f10
/* 0F286C 7F0BDD3C 3C027FFF */  lui   $v0, (0x7FFFFFFF >> 16) # lui $v0, 0x7fff
/* 0F2870 7F0BDD40 3442FFFF */  ori   $v0, (0x7FFFFFFF & 0xFFFF) # ori $v0, $v0, 0xffff
/* 0F2874 7F0BDD44 AE800034 */  sw    $zero, 0x34($s4)
/* 0F2878 7F0BDD48 AE80003C */  sw    $zero, 0x3c($s4)
/* 0F287C 7F0BDD4C AE820044 */  sw    $v0, 0x44($s4)
/* 0F2880 7F0BDD50 AE800048 */  sw    $zero, 0x48($s4)
/* 0F2884 7F0BDD54 AE800054 */  sw    $zero, 0x54($s4)
/* 0F2888 7F0BDD58 AE800058 */  sw    $zero, 0x58($s4)
/* 0F288C 7F0BDD5C AE80004C */  sw    $zero, 0x4c($s4)
/* 0F2890 7F0BDD60 AE820050 */  sw    $v0, 0x50($s4)
/* 0F2894 7F0BDD64 A2800068 */  sb    $zero, 0x68($s4)
/* 0F2898 7F0BDD68 AE800060 */  sw    $zero, 0x60($s4)
/* 0F289C 7F0BDD6C E6880038 */  swc1  $f8, 0x38($s4)
/* 0F28A0 7F0BDD70 E68A0040 */  swc1  $f10, 0x40($s4)
/* 0F28A4 7F0BDD74 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer)
/* 0F28A8 7F0BDD78 256BA0B0 */  addiu $t3, %lo(g_CurrentPlayer) # addiu $t3, $t3, -0x5f50
/* 0F28AC 7F0BDD7C 26520070 */  addiu $s2, $s2, 0x70
/* 0F28B0 7F0BDD80 26940070 */  addiu $s4, $s4, 0x70
/* 0F28B4 7F0BDD84 AE40FFC0 */  sw    $zero, -0x40($s2)
/* 0F28B8 7F0BDD88 AE40FFBC */  sw    $zero, -0x44($s2)
/* 0F28BC 7F0BDD8C AE40FFB8 */  sw    $zero, -0x48($s2)
/* 0F28C0 7F0BDD90 164BFFC0 */  bne   $s2, $t3, .L7F0BDC94
/* 0F28C4 7F0BDD94 AE40FFB4 */   sw    $zero, -0x4c($s2)
.L7F0BDD98:
/* 0F28C8 7F0BDD98 0FC013B0 */  jal   something_with_stage_objectives
/* 0F28CC 7F0BDD9C 00000000 */   nop
/* 0F28D0 7F0BDDA0 0FC30802 */  jal   mpwatchUnpauseGame
/* 0F28D4 7F0BDDA4 00000000 */   nop
/* 0F28D8 7F0BDDA8 0FC26E08 */  jal   sub_GAME_7F09B820
/* 0F28DC 7F0BDDAC 00000000 */   nop
/* 0F28E0 7F0BDDB0 0FC01514 */  jal   sub_GAME_7F005450
/* 0F28E4 7F0BDDB4 00000000 */   nop
/* 0F28E8 7F0BDDB8 0FC01548 */  jal   zero_contents_of_80036070_74
/* 0F28EC 7F0BDDBC 00000000 */   nop
/* 0F28F0 7F0BDDC0 0FC00538 */  jal   init_load_objpos_table
/* 0F28F4 7F0BDDC4 00000000 */   nop
/* 0F28F8 7F0BDDC8 0FC005D4 */  jal   reinit_between_menus
/* 0F28FC 7F0BDDCC 00000000 */   nop
/* 0F2900 7F0BDDD0 0FC0052C */  jal   init_sound_effects_registers
/* 0F2904 7F0BDDD4 00000000 */   nop
/* 0F2908 7F0BDDD8 0FC00390 */  jal   init_guards
/* 0F290C 7F0BDDDC 00000000 */   nop
/* 0F2910 7F0BDDE0 0FC003D4 */  jal   set_new_rand_head_bodies
/* 0F2914 7F0BDDE4 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F2918 7F0BDDE8 0FC00EFC */  jal   proplvreset2
/* 0F291C 7F0BDDEC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F2920 7F0BDDF0 0FC01B64 */  jal   alloc_explosion_smoke_casing_scorch_impact_buffers
/* 0F2924 7F0BDDF4 00000000 */   nop
/* 0F2928 7F0BDDF8 0FC01C60 */  jal   alloc_shattered_window_pieces
/* 0F292C 7F0BDDFC 00000000 */   nop
/* 0F2930 7F0BDE00 0FC01CA4 */  jal   sub_GAME_7F007290
/* 0F2934 7F0BDE04 00000000 */   nop
/* 0F2938 7F0BDE08 0FC01CAC */  jal   initCheatTextBuffer
/* 0F293C 7F0BDE0C 00000000 */   nop
/* 0F2940 7F0BDE10 3C0C8005 */  lui   $t4, %hi(g_CurrentStageToLoad)
/* 0F2944 7F0BDE14 8D8C8364 */  lw    $t4, %lo(g_CurrentStageToLoad)($t4)
/* 0F2948 7F0BDE18 2401005A */  li    $at, 90
/* 0F294C 7F0BDE1C 15810005 */  bne   $t4, $at, .L7F0BDE34
/* 0F2950 7F0BDE20 00000000 */   nop
/* 0F2954 7F0BDE24 0FC01CBE */  jal   disableOnscreenCheatText
/* 0F2958 7F0BDE28 00000000 */   nop
/* 0F295C 7F0BDE2C 10000020 */  b     .L7F0BDEB0
/* 0F2960 7F0BDE30 00000000 */   nop
.L7F0BDE34:
/* 0F2964 7F0BDE34 0FC01A24 */  jal   init_path_table_links
/* 0F2968 7F0BDE38 00000000 */   nop
/* 0F296C 7F0BDE3C 0FC01410 */  jal   init_ejected_cartridges
/* 0F2970 7F0BDE40 00000000 */   nop
/* 0F2974 7F0BDE44 0FC26919 */  jal   getPlayerCount
/* 0F2978 7F0BDE48 00008025 */   move  $s0, $zero
/* 0F297C 7F0BDE4C 18400016 */  blez  $v0, .L7F0BDEA8
/* 0F2980 7F0BDE50 00000000 */   nop
.L7F0BDE54:
/* 0F2984 7F0BDE54 0FC26C43 */  jal   set_cur_player
/* 0F2988 7F0BDE58 02002025 */   move  $a0, $s0
/* 0F298C 7F0BDE5C 0FC0187C */  jal   reinit_gunheld_totaltime
/* 0F2990 7F0BDE60 00000000 */   nop
/* 0F2994 7F0BDE64 0FC01434 */  jal   init_player_BONDdata_stats
/* 0F2998 7F0BDE68 00000000 */   nop
/* 0F299C 7F0BDE6C 0FC1E4FB */  jal   init_player_BONDdata
/* 0F29A0 7F0BDE70 00000000 */   nop
/* 0F29A4 7F0BDE74 0FC015F1 */  jal   bondviewLoadSetupIntroSection
/* 0F29A8 7F0BDE78 00000000 */   nop
/* 0F29AC 7F0BDE7C 0FC1E62E */  jal   bondviewPlayerSpawnRelated
/* 0F29B0 7F0BDE80 00000000 */   nop
/* 0F29B4 7F0BDE84 0FC018E3 */  jal   sets_a_bunch_of_BONDdata_values_to_default
/* 0F29B8 7F0BDE88 00000000 */   nop
/* 0F29BC 7F0BDE8C 0FC01CBE */  jal   disableOnscreenCheatText
/* 0F29C0 7F0BDE90 00000000 */   nop
/* 0F29C4 7F0BDE94 0FC26919 */  jal   getPlayerCount
/* 0F29C8 7F0BDE98 26100001 */   addiu $s0, $s0, 1
/* 0F29CC 7F0BDE9C 0202082A */  slt   $at, $s0, $v0
/* 0F29D0 7F0BDEA0 1420FFEC */  bnez  $at, .L7F0BDE54
/* 0F29D4 7F0BDEA4 00000000 */   nop
.L7F0BDEA8:
/* 0F29D8 7F0BDEA8 0FC26C43 */  jal   set_cur_player
/* 0F29DC 7F0BDEAC 00002025 */   move  $a0, $zero
.L7F0BDEB0:
/* 0F29E0 7F0BDEB0 0FC0154D */  jal   set_contents_of_80036078
/* 0F29E4 7F0BDEB4 00002025 */   move  $a0, $zero
/* 0F29E8 7F0BDEB8 0FC348E0 */  jal   zbufDeallocate
/* 0F29EC 7F0BDEBC 00000000 */   nop
/* 0F29F0 7F0BDEC0 0C000EEC */  jal   viSetVideoMode
/* 0F29F4 7F0BDEC4 24040001 */   li    $a0, 1
/* 0F29F8 7F0BDEC8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F29FC 7F0BDECC 44818000 */  mtc1  $at, $f16
/* 0F2A00 7F0BDED0 3C018005 */  lui   $at, %hi(D_80048368)
/* 0F2A04 7F0BDED4 00002025 */  move  $a0, $zero
/* 0F2A08 7F0BDED8 0FC2FEFE */  jal   lvlSetControlsLockedFlag
/* 0F2A0C 7F0BDEDC E4308368 */   swc1  $f16, %lo(D_80048368)($at)
/* 0F2A10 7F0BDEE0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0F2A14 7F0BDEE4 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0F2A18 7F0BDEE8 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F2A1C 7F0BDEEC 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F2A20 7F0BDEF0 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F2A24 7F0BDEF4 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F2A28 7F0BDEF8 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F2A2C 7F0BDEFC 03E00008 */  jr    $ra
/* 0F2A30 7F0BDF00 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.text
glabel lvlStageLoad
/* 0F31D0 7F0BE660 3C018005 */  lui   $at, %hi(g_CurrentStageToLoad) # $at, 0x8005
/* 0F31D4 7F0BE664 AC248394 */  sw    $a0, %lo(g_CurrentStageToLoad)($at)
/* 0F31D8 7F0BE668 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F31DC 7F0BE66C 44816000 */  mtc1  $at, $f12
/* 0F31E0 7F0BE670 24020001 */  li    $v0, 1
/* 0F31E4 7F0BE674 3C018005 */  lui   $at, %hi(D_800483C0) # $at, 0x8005
/* 0F31E8 7F0BE678 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F31EC 7F0BE67C AC2283F4 */  sw    $v0, %lo(D_800483C0)($at)
/* 0F31F0 7F0BE680 AFB10024 */  sw    $s1, 0x24($sp)
/* 0F31F4 7F0BE684 3C018005 */  lui   $at, %hi(g_ControlsLockedFlag) # $at, 0x8005
/* 0F31F8 7F0BE688 3C118005 */  lui   $s1, %hi(g_ClockTimer) # $s1, 0x8005
/* 0F31FC 7F0BE68C AC2083A0 */  sw    $zero, %lo(g_ControlsLockedFlag)($at)
/* 0F3200 7F0BE690 263183A4 */  addiu $s1, %lo(g_ClockTimer) # addiu $s1, $s1, -0x7c5c
/* 0F3204 7F0BE694 AE220000 */  sw    $v0, ($s1)
/* 0F3208 7F0BE698 3C018005 */  lui   $at, %hi(g_JP_GlobalTimerDelta) # $at, 0x8005
/* 0F320C 7F0BE69C E42C83A8 */  swc1  $f12, %lo(g_JP_GlobalTimerDelta)($at)
/* 0F3210 7F0BE6A0 3C018005 */  lui   $at, %hi(D_80048380) # $at, 0x8005
/* 0F3214 7F0BE6A4 AC2083B0 */  sw    $zero, %lo(D_80048380)($at)
/* 0F3218 7F0BE6A8 3C018005 */  lui   $at, %hi(g_GlobalTimer) # $at, 0x8005
/* 0F321C 7F0BE6AC AC2083AC */  sw    $zero, %lo(g_GlobalTimer)($at)
/* 0F3220 7F0BE6B0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F3224 7F0BE6B4 44812000 */  mtc1  $at, $f4

/* 0F3228 7F0BE6B8 3C018005 */  lui   $at, %hi(0x800483B4) # $at, 0x8005
/* 0F322C 7F0BE6BC AFB00020 */  sw    $s0, 0x20($sp)
/* 0F3230 7F0BE6C0 E42483B4 */  swc1  $f4, %lo(0x800483B4)($at)
/* 0F3234 7F0BE6C4 3C018005 */  lui   $at, %hi(D_80048388) # $at, 0x8005
/* 0F3238 7F0BE6C8 AC2083BC */  sw    $zero, %lo(D_80048388)($at)
/* 0F323C 7F0BE6CC 3C018005 */  lui   $at, %hi(D_8004838C) # $at, 0x8005
/* 0F3240 7F0BE6D0 AC2083C0 */  sw    $zero, %lo(D_8004838C)($at)
/* 0F3244 7F0BE6D4 3C018005 */  lui   $at, %hi(D_80048390) # $at, 0x8005
/* 0F3248 7F0BE6D8 44800000 */  mtc1  $zero, $f0
/* 0F324C 7F0BE6DC 3C108005 */  lui   $s0, %hi(D_80048394) # $s0, 0x8005
/* 0F3250 7F0BE6E0 AC2083C4 */  sw    $zero, %lo(D_80048390)($at)
/* 0F3254 7F0BE6E4 261083C8 */  addiu $s0, %lo(D_80048394) # addiu $s0, $s0, -0x7c38

/* 0F3258 7F0BE6E8 AE000000 */  sw    $zero, ($s0)
/* 0F325C 7F0BE6EC 3C018005 */  lui   $at, %hi(g_CurrentMultiPlayerSec) # $at, 0x8005
/* 0F3260 7F0BE6F0 E42083D8 */  swc1  $f0, %lo(g_CurrentMultiPlayerSec)($at)
/* 0F3264 7F0BE6F4 3C018005 */  lui   $at, %hi(D_800483B0) # $at, 0x8005
/* 0F3268 7F0BE6F8 AC2083E4 */  sw    $zero, %lo(D_800483B0)($at)
/* 0F326C 7F0BE6FC 3C018005 */  lui   $at, %hi(g_StageTimeSec) # $at, 0x8005
/* 0F3270 7F0BE700 E42083E8 */  swc1  $f0, %lo(g_StageTimeSec)($at)
/* 0F3274 7F0BE704 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0F3278 7F0BE708 3C018005 */  lui   $at, %hi(g_MpSoundStateRelated) # $at, 0x8005
/* 0F327C 7F0BE70C AFB40030 */  sw    $s4, 0x30($sp)
/* 0F3280 7F0BE710 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0F3284 7F0BE714 AFB20028 */  sw    $s2, 0x28($sp)
/* 0F3288 7F0BE718 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0F328C 7F0BE71C AFA40038 */  sw    $a0, 0x38($sp)
/* 0F3290 7F0BE720 0C002492 */  jal   sndSetScalerApplyVolumeAllSfxSlot
/* 0F3294 7F0BE724 AC2083D4 */   sw    $zero, %lo(g_MpSoundStateRelated)($at)
/* 0F3298 7F0BE728 0C001C13 */  jal   musicTrack1ApplySeqpVol
/* 0F329C 7F0BE72C 24047FFF */   li    $a0, 32767
/* 0F32A0 7F0BE730 0C001CF5 */  jal   musicTrack2ApplySeqpVol
/* 0F32A4 7F0BE734 24047FFF */   li    $a0, 32767
/* 0F32A8 7F0BE738 0C001DD7 */  jal   musicTrack3ApplySeqpVol
/* 0F32AC 7F0BE73C 24047FFF */   li    $a0, 32767
/* 0F32B0 7F0BE740 0FC30805 */  jal   sub_GAME_7F0C1364
/* 0F32B4 7F0BE744 00000000 */   nop
/* 0F32B8 7F0BE748 0FC01555 */  jal   set_contents_of_80036078
/* 0F32BC 7F0BE74C 24040001 */   li    $a0, 1
/* 0F32C0 7F0BE750 0FC01CD0 */  jal   set_mt_tex_alloc
/* 0F32C4 7F0BE754 00000000 */   nop
/* 0F32C8 7F0BE758 0FC294DD */  jal   sub_GAME_7F0A47D4
/* 0F32CC 7F0BE75C 00000000 */   nop
/* 0F32D0 7F0BE760 0FC33324 */  jal   texReset
/* 0F32D4 7F0BE764 00000000 */   nop
/* 0F32D8 7F0BE768 0FC2B5D7 */  jal   load_font_tables
/* 0F32DC 7F0BE76C 00000000 */   nop
/* 0F32E0 7F0BE770 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0F32E4 7F0BE774 2401005A */  li    $at, 90
/* 0F32E8 7F0BE778 15E10005 */  bne   $t7, $at, .Ljp7F0BE790
/* 0F32EC 7F0BE77C 00000000 */   nop
/* 0F32F0 7F0BE780 0FC00348 */  jal   init_menus_or_reset
/* 0F32F4 7F0BE784 00000000 */   nop
/* 0F32F8 7F0BE788 10000073 */  b     .Ljp7F0BE958
/* 0F32FC 7F0BE78C 00000000 */   nop
.Ljp7F0BE790:
/* 0F3300 7F0BE790 3C048005 */  lui   $a0, %hi(g_CurrentStageToLoad) # $a0, 0x8005
/* 0F3304 7F0BE794 8C848394 */  lw    $a0, %lo(g_CurrentStageToLoad)($a0)
/* 0F3308 7F0BE798 3C018007 */  lui    $at, %hi(g_NewCheatUnlocked)
/* 0F330C 7F0BE79C AC2097D0 */  sw    $zero, %lo(g_NewCheatUnlocked)($at)
/* 0F3310 7F0BE7A0 2401005A */  li    $at, 90
/* 0F3314 7F0BE7A4 1081001C */  beq   $a0, $at, .Ljp7F0BE818
/* 0F3318 7F0BE7A8 00000000 */   nop
/* 0F331C 7F0BE7AC 8E180000 */  lw    $t8, ($s0)
/* 0F3320 7F0BE7B0 17000019 */  bnez  $t8, .Ljp7F0BE818
/* 0F3324 7F0BE7B4 00000000 */   nop
/* 0F3328 7F0BE7B8 8E390000 */  lw    $t9, ($s1)
/* 0F332C 7F0BE7BC 3C088003 */  lui   $t0, %hi(g_AppendCheatSinglePlayer) # $t0, 0x8003
/* 0F3330 7F0BE7C0 1B200015 */  blez  $t9, .Ljp7F0BE818
/* 0F3334 7F0BE7C4 00000000 */   nop
/* 0F3338 7F0BE7C8 8D08A940 */  lw    $t0, %lo(g_AppendCheatSinglePlayer)($t0)
/* 0F333C 7F0BE7CC 3C118007 */  lui   $s1, %hi(g_CheatActivated + 1) # $s1, 0x8007
/* 0F3340 7F0BE7D0 263196E1 */  addiu $s1, %lo(g_CheatActivated + 1) # addiu $s1, $s1, -0x691f
/* 0F3344 7F0BE7D4 11000010 */  beqz  $t0, .Ljp7F0BE818
/* 0F3348 7F0BE7D8 24100001 */   li    $s0, 1
/* 0F334C 7F0BE7DC 2412004B */  li    $s2, 75
.Ljp7F0BE7E0:
/* 0F3350 7F0BE7E0 92290000 */  lbu   $t1, ($s1)
/* 0F3354 7F0BE7E4 51200008 */  beql  $t1, $zero, .Ljp7F0BE808
/* 0F3358 7F0BE7E8 26100001 */   addiu $s0, $s0, 1
/* 0F335C 7F0BE7EC 0FC2494F */  jal   cheatIsEnemyRockets
/* 0F3360 7F0BE7F0 02002025 */   move  $a0, $s0
/* 0F3364 7F0BE7F4 50400004 */  beql  $v0, $zero, .Ljp7F0BE808
/* 0F3368 7F0BE7F8 26100001 */   addiu $s0, $s0, 1
/* 0F336C 7F0BE7FC 0FC24963 */  jal   cheatButtonTurnOnCheatForPlayers
/* 0F3370 7F0BE800 02002025 */   move  $a0, $s0
/* 0F3374 7F0BE804 26100001 */  addiu $s0, $s0, 1
.Ljp7F0BE808:
/* 0F3378 7F0BE808 1612FFF5 */  bne   $s0, $s2, .Ljp7F0BE7E0
/* 0F337C 7F0BE80C 26310001 */   addiu $s1, $s1, 1
/* 0F3380 7F0BE810 3C048005 */  lui   $a0, %hi(g_CurrentStageToLoad) # $a0, 0x8005
/* 0F3384 7F0BE814 8C848394 */  lw    $a0, %lo(g_CurrentStageToLoad)($a0)
.Ljp7F0BE818:
/* 0F3388 7F0BE818 0FC2D335 */  jal   load_bg_file
/* 0F338C 7F0BE81C 00000000 */   nop
/* 0F3390 7F0BE820 3C048005 */  lui   $a0, %hi(g_CurrentStageToLoad) # $a0, 0x8005
/* 0F3394 7F0BE824 0FC253F3 */  jal   skySetStageNum
/* 0F3398 7F0BE828 8C848394 */   lw    $a0, %lo(g_CurrentStageToLoad)($a0)
/* 0F339C 7F0BE82C 0FC29502 */  jal   init_watch_at_start_of_stage
/* 0F33A0 7F0BE830 00000000 */   nop
/* 0F33A4 7F0BE834 0FC307AB */  jal   sub_GAME_7F0C11FC
/* 0F33A8 7F0BE838 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F33AC 7F0BE83C 3C0A8008 */  lui   $t2, %hi(g_playerPlayerData)
/* 0F33B0 7F0BE840 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0F33B4 7F0BE844 25529F60 */  addiu $s2, $t2, %lo(g_playerPlayerData)
/* 0F33B8 7F0BE848 4481A000 */  mtc1  $at, $f20
/* 0F33BC 7F0BE84C 0240A025 */  move  $s4, $s2
/* 0F33C0 7F0BE850 24130004 */  li    $s3, 4
.Ljp7F0BE854:
/* 0F33C4 7F0BE854 0FC26C01 */  jal   getPlayerCount
/* 0F33C8 7F0BE858 00000000 */   nop
/* 0F33CC 7F0BE85C 24010001 */  li    $at, 1
/* 0F33D0 7F0BE860 14410009 */  bne   $v0, $at, .Ljp7F0BE888
/* 0F33D4 7F0BE864 00008025 */   move  $s0, $zero
/* 0F33D8 7F0BE868 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F33DC 7F0BE86C 44813000 */  mtc1  $at, $f6
/* 0F33E0 7F0BE870 44814000 */  mtc1  $at, $f8
/* 0F33E4 7F0BE874 A280006A */  sb    $zero, 0x6a($s4)
/* 0F33E8 7F0BE878 A280006B */  sb    $zero, 0x6b($s4)
/* 0F33EC 7F0BE87C E686005C */  swc1  $f6, 0x5c($s4)
/* 0F33F0 7F0BE880 1000001C */  b     .Ljp7F0BE8F4
/* 0F33F4 7F0BE884 E6880064 */   swc1  $f8, 0x64($s4)
.Ljp7F0BE888:
/* 0F33F8 7F0BE888 3C118008 */  lui   $s1, %hi(g_playerPlayerData) # $s1, 0x8008
/* 0F33FC 7F0BE88C 26319F60 */  addiu $s1, %lo(g_playerPlayerData) # addiu $s1, $s1, -0x60a0
.Ljp7F0BE890:
/* 0F3400 7F0BE890 0FC05202 */  jal   get_scenario
/* 0F3404 7F0BE894 00000000 */   nop
/* 0F3408 7F0BE898 14530003 */  bne   $v0, $s3, .Ljp7F0BE8A8
/* 0F340C 7F0BE89C 00000000 */   nop
/* 0F3410 7F0BE8A0 10000004 */  b     .Ljp7F0BE8B4
/* 0F3414 7F0BE8A4 E634005C */   swc1  $f20, 0x5c($s1)
.Ljp7F0BE8A8:
/* 0F3418 7F0BE8A8 0FC040FB */  jal   get_player_mp_handicap
/* 0F341C 7F0BE8AC 02002025 */   move  $a0, $s0
/* 0F3420 7F0BE8B0 E620005C */  swc1  $f0, 0x5c($s1)
.Ljp7F0BE8B4:
/* 0F3424 7F0BE8B4 0FC04104 */  jal   get_player_mp_char_height
/* 0F3428 7F0BE8B8 02002025 */   move  $a0, $s0
/* 0F342C 7F0BE8BC 26100001 */  addiu $s0, $s0, 1
/* 0F3430 7F0BE8C0 26310070 */  addiu $s1, $s1, 0x70
/* 0F3434 7F0BE8C4 1613FFF2 */  bne   $s0, $s3, .Ljp7F0BE890
/* 0F3438 7F0BE8C8 E620FFF4 */   swc1  $f0, -0xc($s1)
/* 0F343C 7F0BE8CC 0FC04118 */  jal   get_mp_timelimit
/* 0F3440 7F0BE8D0 00000000 */   nop
/* 0F3444 7F0BE8D4 0FC30224 */  jal   lvlSetMpTime
/* 0F3448 7F0BE8D8 00402025 */   move  $a0, $v0
/* 0F344C 7F0BE8DC 0FC04121 */  jal   get_mp_pointlimit
/* 0F3450 7F0BE8E0 00000000 */   nop
/* 0F3454 7F0BE8E4 0FC30227 */  jal   lvlSetMpPoint
/* 0F3458 7F0BE8E8 00402025 */   move  $a0, $v0
/* 0F345C 7F0BE8EC 0FC04086 */  jal   copy_aim_settings_to_playerdata
/* 0F3460 7F0BE8F0 00000000 */   nop
.Ljp7F0BE8F4:
/* 0F3464 7F0BE8F4 44805000 */  mtc1  $zero, $f10
/* 0F3468 7F0BE8F8 44808000 */  mtc1  $zero, $f16
/* 0F346C 7F0BE8FC 3C027FFF */  lui   $v0, (0x7FFFFFFF >> 16) # lui $v0, 0x7fff
/* 0F3470 7F0BE900 3442FFFF */  ori   $v0, (0x7FFFFFFF & 0xFFFF) # ori $v0, $v0, 0xffff
/* 0F3474 7F0BE904 AE800034 */  sw    $zero, 0x34($s4)
/* 0F3478 7F0BE908 AE80003C */  sw    $zero, 0x3c($s4)
/* 0F347C 7F0BE90C AE820044 */  sw    $v0, 0x44($s4)
/* 0F3480 7F0BE910 AE800048 */  sw    $zero, 0x48($s4)
/* 0F3484 7F0BE914 AE800054 */  sw    $zero, 0x54($s4)
/* 0F3488 7F0BE918 AE800058 */  sw    $zero, 0x58($s4)
/* 0F348C 7F0BE91C AE80004C */  sw    $zero, 0x4c($s4)
/* 0F3490 7F0BE920 AE820050 */  sw    $v0, 0x50($s4)
/* 0F3494 7F0BE924 A2800068 */  sb    $zero, 0x68($s4)
/* 0F3498 7F0BE928 AE800060 */  sw    $zero, 0x60($s4)
/* 0F349C 7F0BE92C E68A0038 */  swc1  $f10, 0x38($s4)
/* 0F34A0 7F0BE930 E6900040 */  swc1  $f16, 0x40($s4)
/* 0F34A4 7F0BE934 3C0B8008 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8008
/* 0F34A8 7F0BE938 256BA120 */  addiu $t3, %lo(g_CurrentPlayer) # addiu $t3, $t3, -0x5ee0
/* 0F34AC 7F0BE93C 26520070 */  addiu $s2, $s2, 0x70
/* 0F34B0 7F0BE940 26940070 */  addiu $s4, $s4, 0x70
/* 0F34B4 7F0BE944 AE40FFC0 */  sw    $zero, -0x40($s2)
/* 0F34B8 7F0BE948 AE40FFBC */  sw    $zero, -0x44($s2)
/* 0F34BC 7F0BE94C AE40FFB8 */  sw    $zero, -0x48($s2)
/* 0F34C0 7F0BE950 164BFFC0 */  bne   $s2, $t3, .Ljp7F0BE854
/* 0F34C4 7F0BE954 AE40FFB4 */   sw    $zero, -0x4c($s2)
.Ljp7F0BE958:
/* 0F34C8 7F0BE958 0FC013B4 */  jal   something_with_stage_objectives
/* 0F34CC 7F0BE95C 00000000 */   nop
/* 0F34D0 7F0BE960 0FC30B2E */  jal   mpwatchUnpauseGame
/* 0F34D4 7F0BE964 00000000 */   nop
/* 0F34D8 7F0BE968 0FC270F0 */  jal   sub_GAME_7F09B820
/* 0F34DC 7F0BE96C 00000000 */   nop
/* 0F34E0 7F0BE970 0FC0151C */  jal   sub_GAME_7F005450
/* 0F34E4 7F0BE974 00000000 */   nop
/* 0F34E8 7F0BE978 0FC01550 */  jal   zero_contents_of_80036070_74
/* 0F34EC 7F0BE97C 00000000 */   nop
/* 0F34F0 7F0BE980 0FC00538 */  jal   init_load_objpos_table
/* 0F34F4 7F0BE984 00000000 */   nop
/* 0F34F8 7F0BE988 0FC005D4 */  jal   reinit_between_menus
/* 0F34FC 7F0BE98C 00000000 */   nop
/* 0F3500 7F0BE990 0FC0052C */  jal   init_sound_effects_registers
/* 0F3504 7F0BE994 00000000 */   nop
/* 0F3508 7F0BE998 0FC00390 */  jal   init_guards
/* 0F350C 7F0BE99C 00000000 */   nop
/* 0F3510 7F0BE9A0 0FC003D4 */  jal   set_new_rand_head_bodies
/* 0F3514 7F0BE9A4 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F3518 7F0BE9A8 0FC00EFC */  jal   proplvreset2
/* 0F351C 7F0BE9AC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0F3520 7F0BE9B0 0FC01B6C */  jal   alloc_explosion_smoke_casing_scorch_impact_buffers
/* 0F3524 7F0BE9B4 00000000 */   nop
/* 0F3528 7F0BE9B8 0FC01C68 */  jal   alloc_shattered_window_pieces
/* 0F352C 7F0BE9BC 00000000 */   nop
/* 0F3530 7F0BE9C0 0FC01CAC */  jal   sub_GAME_7F007290
/* 0F3534 7F0BE9C4 00000000 */   nop
/* 0F3538 7F0BE9C8 0FC01CB4 */  jal   initCheatTextBuffer
/* 0F353C 7F0BE9CC 00000000 */   nop
/* 0F3540 7F0BE9D0 3C0C8005 */  lui   $t4, %hi(g_CurrentStageToLoad) # $t4, 0x8005
/* 0F3544 7F0BE9D4 8D8C8394 */  lw    $t4, %lo(g_CurrentStageToLoad)($t4)
/* 0F3548 7F0BE9D8 2401005A */  li    $at, 90
/* 0F354C 7F0BE9DC 15810005 */  bne   $t4, $at, .Ljp7F0BE9F4
/* 0F3550 7F0BE9E0 00000000 */   nop
/* 0F3554 7F0BE9E4 0FC01CC6 */  jal   disableOnscreenCheatText
/* 0F3558 7F0BE9E8 00000000 */   nop
/* 0F355C 7F0BE9EC 10000020 */  b     .Ljp7F0BEA70
/* 0F3560 7F0BE9F0 00000000 */   nop
.Ljp7F0BE9F4:
/* 0F3564 7F0BE9F4 0FC01A2C */  jal   init_path_table_links
/* 0F3568 7F0BE9F8 00000000 */   nop
/* 0F356C 7F0BE9FC 0FC01418 */  jal   init_ejected_cartridges
/* 0F3570 7F0BEA00 00000000 */   nop
/* 0F3574 7F0BEA04 0FC26C01 */  jal   getPlayerCount
/* 0F3578 7F0BEA08 00008025 */   move  $s0, $zero
/* 0F357C 7F0BEA0C 18400016 */  blez  $v0, .Ljp7F0BEA68
/* 0F3580 7F0BEA10 00000000 */   nop
.Ljp7F0BEA14:
/* 0F3584 7F0BEA14 0FC26F2B */  jal   set_cur_player
/* 0F3588 7F0BEA18 02002025 */   move  $a0, $s0
/* 0F358C 7F0BEA1C 0FC0187C */  jal   reinit_gunheld_totaltime
/* 0F3590 7F0BEA20 00000000 */   nop
/* 0F3594 7F0BEA24 0FC0143C */  jal   init_player_BONDdata_stats
/* 0F3598 7F0BEA28 00000000 */   nop
/* 0F359C 7F0BEA2C 0FC1E677 */  jal   init_player_BONDdata
/* 0F35A0 7F0BEA30 00000000 */   nop
/* 0F35A4 7F0BEA34 0FC015F9 */  jal   bondviewLoadSetupIntroSection
/* 0F35A8 7F0BEA38 00000000 */   nop
/* 0F35AC 7F0BEA3C 0FC1E7AA */  jal   bondviewPlayerSpawnRelated
/* 0F35B0 7F0BEA40 00000000 */   nop
/* 0F35B4 7F0BEA44 0FC018E3 */  jal   sets_a_bunch_of_BONDdata_values_to_default
/* 0F35B8 7F0BEA48 00000000 */   nop
/* 0F35BC 7F0BEA4C 0FC01CC6 */  jal   disableOnscreenCheatText
/* 0F35C0 7F0BEA50 00000000 */   nop
/* 0F35C4 7F0BEA54 0FC26C01 */  jal   getPlayerCount
/* 0F35C8 7F0BEA58 26100001 */   addiu $s0, $s0, 1
/* 0F35CC 7F0BEA5C 0202082A */  slt   $at, $s0, $v0
/* 0F35D0 7F0BEA60 1420FFEC */  bnez  $at, .Ljp7F0BEA14
/* 0F35D4 7F0BEA64 00000000 */   nop
.Ljp7F0BEA68:
/* 0F35D8 7F0BEA68 0FC26F2B */  jal   set_cur_player
/* 0F35DC 7F0BEA6C 00002025 */   move  $a0, $zero
.Ljp7F0BEA70:
/* 0F35E0 7F0BEA70 0FC01555 */  jal   set_contents_of_80036078
/* 0F35E4 7F0BEA74 00002025 */   move  $a0, $zero
/* 0F35E8 7F0BEA78 0FC34C18 */  jal   zbufDeallocate
/* 0F35EC 7F0BEA7C 00000000 */   nop
/* 0F35F0 7F0BEA80 0C000EEC */  jal   viSetVideoMode
/* 0F35F4 7F0BEA84 24040001 */   li    $a0, 1
/* 0F35F8 7F0BEA88 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0F35FC 7F0BEA8C 44819000 */  mtc1  $at, $f18
/* 0F3600 7F0BEA90 3C018005 */  lui   $at, %hi(D_80048368) # $at, 0x8005
/* 0F3604 7F0BEA94 00002025 */  move  $a0, $zero
/* 0F3608 7F0BEA98 0FC3020C */  jal   lvlSetControlsLockedFlag
/* 0F360C 7F0BEA9C E4328398 */   swc1  $f18, %lo(D_80048368)($at)
/* 0F3610 7F0BEAA0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0F3614 7F0BEAA4 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0F3618 7F0BEAA8 8FB00020 */  lw    $s0, 0x20($sp)
/* 0F361C 7F0BEAAC 8FB10024 */  lw    $s1, 0x24($sp)
/* 0F3620 7F0BEAB0 8FB20028 */  lw    $s2, 0x28($sp)
/* 0F3624 7F0BEAB4 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0F3628 7F0BEAB8 8FB40030 */  lw    $s4, 0x30($sp)
/* 0F362C 7F0BEABC 03E00008 */  jr    $ra
/* 0F3630 7F0BEAC0 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata

/* not sure this is the right location ... */
#const char aSetdetailDDDDDDDDD[] = "setdetail %d %d %d %d %d %d %d %d %d";
glabel aSetdetailDDDDDDDDD
.word 0x73657464
.word 0x65746169
.word 0x6c202564
.word 0x20256420
.word 0x25642025
.word 0x64202564
.word 0x20256420
.word 0x25642025
.word 0x64202564
.word 0x00000000

glabel D_800502EC
.word 0x3f99999a

.text
glabel lvlStageLoad
/* 0EF850 7F0BCE60 3C018004 */  lui   $at, %hi(g_CurrentStageToLoad) # $at, 0x8004
/* 0EF854 7F0BCE64 AC240FE4 */  sw    $a0, %lo(g_CurrentStageToLoad)($at)
/* 0EF858 7F0BCE68 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EF85C 7F0BCE6C 44816000 */  mtc1  $at, $f12
/* 0EF860 7F0BCE70 24020001 */  li    $v0, 1
/* 0EF864 7F0BCE74 3C018004 */  lui   $at, %hi(D_800483C0) # $at, 0x8004
/* 0EF868 7F0BCE78 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0EF86C 7F0BCE7C AC221044 */  sw    $v0, %lo(D_800483C0)($at)
/* 0EF870 7F0BCE80 AFB10024 */  sw    $s1, 0x24($sp)
/* 0EF874 7F0BCE84 3C018004 */  lui   $at, %hi(g_ControlsLockedFlag) # $at, 0x8004
/* 0EF878 7F0BCE88 3C118004 */  lui   $s1, %hi(g_ClockTimer) # $s1, 0x8004
/* 0EF87C 7F0BCE8C AC200FF0 */  sw    $zero, %lo(g_ControlsLockedFlag)($at)
/* 0EF880 7F0BCE90 26310FF4 */  addiu $s1, %lo(g_ClockTimer) # addiu $s1, $s1, 0xff4
/* 0EF884 7F0BCE94 AE220000 */  sw    $v0, ($s1)
/* 0EF888 7F0BCE98 3C018004 */  lui   $at, %hi(g_JP_GlobalTimerDelta) # $at, 0x8004
/* 0EF88C 7F0BCE9C E42C0FF8 */  swc1  $f12, %lo(g_JP_GlobalTimerDelta)($at)
/* 0EF890 7F0BCEA0 3C018004 */  lui   $at, %hi(D_80048380) # $at, 0x8004
/* 0EF894 7F0BCEA4 AC201000 */  sw    $zero, %lo(D_80048380)($at)
/* 0EF898 7F0BCEA8 3C018004 */  lui   $at, %hi(g_GlobalTimer) # $at, 0x8004
/* 0EF89C 7F0BCEAC AC200FFC */  sw    $zero, %lo(g_GlobalTimer)($at)
/* 0EF8A0 7F0BCEB0 3C018005 */  lui   $at, %hi(D_800502EC) # $at, 0x8005
/* 0EF8A4 7F0BCEB4 C42402EC */  lwc1  $f4, %lo(D_800502EC)($at)
/* 0EF8A8 7F0BCEB8 3C018004 */  lui   $at, %hi(D_80048380+4) # $at, 0x8004
/* 0EF8AC 7F0BCEBC AFB00020 */  sw    $s0, 0x20($sp)
/* 0EF8B0 7F0BCEC0 E4241004 */  swc1  $f4, %lo(D_80048380+4)($at)
/* 0EF8B4 7F0BCEC4 3C018004 */  lui   $at, %hi(D_80048380+0xc) # $at, 0x8004
/* 0EF8B8 7F0BCEC8 AC20100C */  sw    $zero, %lo(D_80048380+0xc)($at)
/* 0EF8BC 7F0BCECC 3C018004 */  lui   $at, %hi(D_80048380+0x10) # $at, 0x8004
/* 0EF8C0 7F0BCED0 AC201010 */  sw    $zero, %lo(D_80048380+0x10)($at)
/* 0EF8C4 7F0BCED4 3C018004 */  lui   $at, %hi(D_80048380+0x14) # $at, 0x8004
/* 0EF8C8 7F0BCED8 44800000 */  mtc1  $zero, $f0
/* 0EF8CC 7F0BCEDC 3C108004 */  lui   $s0, %hi(D_80048380+0x18) # $s0, 0x8004
/* 0EF8D0 7F0BCEE0 AC201014 */  sw    $zero, %lo(D_80048380+0x14)($at)
/* 0EF8D4 7F0BCEE4 26101018 */  addiu $s0, %lo(D_80048380+0x18) # addiu $s0, $s0, 0x1018
/* 0EF8D8 7F0BCEE8 AE000000 */  sw    $zero, ($s0)
/* 0EF8DC 7F0BCEEC 3C018004 */  lui   $at, %hi(g_CurrentMultiPlayerSec) # $at, 0x8004
/* 0EF8E0 7F0BCEF0 E4201028 */  swc1  $f0, %lo(g_CurrentMultiPlayerSec)($at)
/* 0EF8E4 7F0BCEF4 3C018004 */  lui   $at, %hi(D_800483B0) # $at, 0x8004
/* 0EF8E8 7F0BCEF8 AC201034 */  sw    $zero, %lo(D_800483B0)($at)
/* 0EF8EC 7F0BCEFC 3C018004 */  lui   $at, %hi(g_StageTimeSec) # $at, 0x8004
/* 0EF8F0 7F0BCF00 E4201038 */  swc1  $f0, %lo(g_StageTimeSec)($at)
/* 0EF8F4 7F0BCF04 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0EF8F8 7F0BCF08 3C018004 */  lui   $at, %hi(g_MpSoundStateRelated) # $at, 0x8004
/* 0EF8FC 7F0BCF0C AFB40030 */  sw    $s4, 0x30($sp)
/* 0EF900 7F0BCF10 AFB3002C */  sw    $s3, 0x2c($sp)
/* 0EF904 7F0BCF14 AFB20028 */  sw    $s2, 0x28($sp)
/* 0EF908 7F0BCF18 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0EF90C 7F0BCF1C AFA40038 */  sw    $a0, 0x38($sp)
/* 0EF910 7F0BCF20 0C0021A6 */  jal   sndSetScalerApplyVolumeAllSfxSlot
/* 0EF914 7F0BCF24 AC201024 */   sw    $zero, %lo(g_MpSoundStateRelated)($at)
/* 0EF918 7F0BCF28 0C001927 */  jal   musicTrack1ApplySeqpVol
/* 0EF91C 7F0BCF2C 24047FFF */   li    $a0, 32767
/* 0EF920 7F0BCF30 0C001A09 */  jal   musicTrack2ApplySeqpVol
/* 0EF924 7F0BCF34 24047FFF */   li    $a0, 32767
/* 0EF928 7F0BCF38 0C001AEB */  jal   musicTrack3ApplySeqpVol
/* 0EF92C 7F0BCF3C 24047FFF */   li    $a0, 32767
/* 0EF930 7F0BCF40 0FC30211 */  jal   sub_GAME_7F0C1364
/* 0EF934 7F0BCF44 00000000 */   nop   
/* 0EF938 7F0BCF48 0FC01535 */  jal   set_contents_of_80036078
/* 0EF93C 7F0BCF4C 24040001 */   li    $a0, 1
/* 0EF940 7F0BCF50 0FC01CA8 */  jal   set_mt_tex_alloc
/* 0EF944 7F0BCF54 00000000 */   nop   
/* 0EF948 7F0BCF58 0FC28EC6 */  jal   sub_GAME_7F0A45D8
/* 0EF94C 7F0BCF5C 00000000 */   nop   
/* 0EF950 7F0BCF60 0FC32D34 */  jal   texReset
/* 0EF954 7F0BCF64 00000000 */   nop   
/* 0EF958 7F0BCF68 0FC2AF9B */  jal   load_font_tables
/* 0EF95C 7F0BCF6C 00000000 */   nop   
/* 0EF960 7F0BCF70 8FAF0038 */  lw    $t7, 0x38($sp)
/* 0EF964 7F0BCF74 2401005A */  li    $at, 90
/* 0EF968 7F0BCF78 15E10005 */  bne   $t7, $at, .L7F0BCF90
/* 0EF96C 7F0BCF7C 00000000 */   nop   
/* 0EF970 7F0BCF80 0FC00348 */  jal   init_menus_or_reset
/* 0EF974 7F0BCF84 00000000 */   nop   
/* 0EF978 7F0BCF88 10000073 */  b     .L7F0BD158
/* 0EF97C 7F0BCF8C 00000000 */   nop   
.L7F0BCF90:
/* 0EF980 7F0BCF90 3C048004 */  lui   $a0, %hi(g_CurrentStageToLoad) # $a0, 0x8004
/* 0EF984 7F0BCF94 8C840FE4 */  lw    $a0, %lo(g_CurrentStageToLoad)($a0)
/* 0EF988 7F0BCF98 3C018006 */  lui    $at, %hi(g_NewCheatUnlocked) # -0.000000
/* 0EF98C 7F0BCF9C AC2086D0 */  sw    $zero, %lo(g_NewCheatUnlocked)($at)
/* 0EF990 7F0BCFA0 2401005A */  li    $at, 90
/* 0EF994 7F0BCFA4 1081001C */  beq   $a0, $at, .L7F0BD018
/* 0EF998 7F0BCFA8 00000000 */   nop   
/* 0EF99C 7F0BCFAC 8E180000 */  lw    $t8, ($s0)
/* 0EF9A0 7F0BCFB0 17000019 */  bnez  $t8, .L7F0BD018
/* 0EF9A4 7F0BCFB4 00000000 */   nop   
/* 0EF9A8 7F0BCFB8 8E390000 */  lw    $t9, ($s1)
/* 0EF9AC 7F0BCFBC 3C088002 */  lui   $t0, %hi(g_AppendCheatSinglePlayer) # $t0, 0x8002
/* 0EF9B0 7F0BCFC0 1B200015 */  blez  $t9, .L7F0BD018
/* 0EF9B4 7F0BCFC4 00000000 */   nop   
/* 0EF9B8 7F0BCFC8 8D085E50 */  lw    $t0, %lo(g_AppendCheatSinglePlayer)($t0)
/* 0EF9BC 7F0BCFCC 3C118006 */  lui   $s1, %hi(g_CheatActivated + 1) # $s1, 0x8006
/* 0EF9C0 7F0BCFD0 263185E1 */  addiu $s1, %lo(g_CheatActivated + 1) # addiu $s1, $s1, -0x7a1f
/* 0EF9C4 7F0BCFD4 11000010 */  beqz  $t0, .L7F0BD018
/* 0EF9C8 7F0BCFD8 24100001 */   li    $s0, 1
/* 0EF9CC 7F0BCFDC 2412004B */  li    $s2, 75
.L7F0BCFE0:
/* 0EF9D0 7F0BCFE0 92290000 */  lbu   $t1, ($s1)
/* 0EF9D4 7F0BCFE4 51200008 */  beql  $t1, $zero, .L7F0BD008
/* 0EF9D8 7F0BCFE8 26100001 */   addiu $s0, $s0, 1
/* 0EF9DC 7F0BCFEC 0FC243B7 */  jal   cheatIsEnemyRockets
/* 0EF9E0 7F0BCFF0 02002025 */   move  $a0, $s0
/* 0EF9E4 7F0BCFF4 50400004 */  beql  $v0, $zero, .L7F0BD008
/* 0EF9E8 7F0BCFF8 26100001 */   addiu $s0, $s0, 1
/* 0EF9EC 7F0BCFFC 0FC243CB */  jal   cheatButtonTurnOnCheatForPlayers
/* 0EF9F0 7F0BD000 02002025 */   move  $a0, $s0
/* 0EF9F4 7F0BD004 26100001 */  addiu $s0, $s0, 1
.L7F0BD008:
/* 0EF9F8 7F0BD008 1612FFF5 */  bne   $s0, $s2, .L7F0BCFE0
/* 0EF9FC 7F0BD00C 26310001 */   addiu $s1, $s1, 1
/* 0EFA00 7F0BD010 3C048004 */  lui   $a0, %hi(g_CurrentStageToLoad) # $a0, 0x8004
/* 0EFA04 7F0BD014 8C840FE4 */  lw    $a0, %lo(g_CurrentStageToLoad)($a0)
.L7F0BD018:
/* 0EFA08 7F0BD018 0FC2CD18 */  jal   load_bg_file
/* 0EFA0C 7F0BD01C 00000000 */   nop   
/* 0EFA10 7F0BD020 3C048004 */  lui   $a0, %hi(g_CurrentStageToLoad) # $a0, 0x8004
/* 0EFA14 7F0BD024 0FC24E5B */  jal   skySetStageNum
/* 0EFA18 7F0BD028 8C840FE4 */   lw    $a0, %lo(g_CurrentStageToLoad)($a0)
/* 0EFA1C 7F0BD02C 0FC28EE2 */  jal   init_watch_at_start_of_stage
/* 0EFA20 7F0BD030 00000000 */   nop   
/* 0EFA24 7F0BD034 0FC301B7 */  jal   sub_GAME_7F0C11FC
/* 0EFA28 7F0BD038 8FA40038 */   lw    $a0, 0x38($sp)
/* 0EFA2C 7F0BD03C 3C0A8007 */  lui   $t2, %hi(g_playerPlayerData)
/* 0EFA30 7F0BD040 3C014348 */  li    $at, 0x43480000 # 200.000000
/* 0EFA34 7F0BD044 25528A00 */  addiu $s2, $t2, %lo(g_playerPlayerData)
/* 0EFA38 7F0BD048 4481A000 */  mtc1  $at, $f20
/* 0EFA3C 7F0BD04C 0240A025 */  move  $s4, $s2
/* 0EFA40 7F0BD050 24130004 */  li    $s3, 4
.L7F0BD054:
/* 0EFA44 7F0BD054 0FC26669 */  jal   getPlayerCount
/* 0EFA48 7F0BD058 00000000 */   nop   
/* 0EFA4C 7F0BD05C 24010001 */  li    $at, 1
/* 0EFA50 7F0BD060 14410009 */  bne   $v0, $at, .L7F0BD088
/* 0EFA54 7F0BD064 00008025 */   move  $s0, $zero
/* 0EFA58 7F0BD068 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EFA5C 7F0BD06C 44813000 */  mtc1  $at, $f6
/* 0EFA60 7F0BD070 44814000 */  mtc1  $at, $f8
/* 0EFA64 7F0BD074 A280006A */  sb    $zero, 0x6a($s4)
/* 0EFA68 7F0BD078 A280006B */  sb    $zero, 0x6b($s4)
/* 0EFA6C 7F0BD07C E686005C */  swc1  $f6, 0x5c($s4)
/* 0EFA70 7F0BD080 1000001C */  b     .L7F0BD0F4
/* 0EFA74 7F0BD084 E6880064 */   swc1  $f8, 0x64($s4)
.L7F0BD088:
/* 0EFA78 7F0BD088 3C118007 */  lui   $s1, %hi(g_playerPlayerData) # $s1, 0x8007
/* 0EFA7C 7F0BD08C 26318A00 */  addiu $s1, %lo(g_playerPlayerData) # addiu $s1, $s1, -0x7600
.L7F0BD090:
/* 0EFA80 7F0BD090 0FC051B2 */  jal   get_scenario
/* 0EFA84 7F0BD094 00000000 */   nop   
/* 0EFA88 7F0BD098 14530003 */  bne   $v0, $s3, .L7F0BD0A8
/* 0EFA8C 7F0BD09C 00000000 */   nop   
/* 0EFA90 7F0BD0A0 10000004 */  b     .L7F0BD0B4
/* 0EFA94 7F0BD0A4 E634005C */   swc1  $f20, 0x5c($s1)
.L7F0BD0A8:
/* 0EFA98 7F0BD0A8 0FC040A7 */  jal   get_player_mp_handicap
/* 0EFA9C 7F0BD0AC 02002025 */   move  $a0, $s0
/* 0EFAA0 7F0BD0B0 E620005C */  swc1  $f0, 0x5c($s1)
.L7F0BD0B4:
/* 0EFAA4 7F0BD0B4 0FC040B0 */  jal   get_player_mp_char_height
/* 0EFAA8 7F0BD0B8 02002025 */   move  $a0, $s0
/* 0EFAAC 7F0BD0BC 26100001 */  addiu $s0, $s0, 1
/* 0EFAB0 7F0BD0C0 26310070 */  addiu $s1, $s1, 0x70
/* 0EFAB4 7F0BD0C4 1613FFF2 */  bne   $s0, $s3, .L7F0BD090
/* 0EFAB8 7F0BD0C8 E620FFF4 */   swc1  $f0, -0xc($s1)
/* 0EFABC 7F0BD0CC 0FC040C4 */  jal   get_mp_timelimit
/* 0EFAC0 7F0BD0D0 00000000 */   nop   
/* 0EFAC4 7F0BD0D4 0FC2FC27 */  jal   lvlSetMpTime
/* 0EFAC8 7F0BD0D8 00402025 */   move  $a0, $v0
/* 0EFACC 7F0BD0DC 0FC040CD */  jal   get_mp_pointlimit
/* 0EFAD0 7F0BD0E0 00000000 */   nop   
/* 0EFAD4 7F0BD0E4 0FC2FC2A */  jal   lvlSetMpPoint
/* 0EFAD8 7F0BD0E8 00402025 */   move  $a0, $v0
/* 0EFADC 7F0BD0EC 0FC04032 */  jal   copy_aim_settings_to_playerdata
/* 0EFAE0 7F0BD0F0 00000000 */   nop   
.L7F0BD0F4:
/* 0EFAE4 7F0BD0F4 44805000 */  mtc1  $zero, $f10
/* 0EFAE8 7F0BD0F8 44808000 */  mtc1  $zero, $f16
/* 0EFAEC 7F0BD0FC 3C027FFF */  lui   $v0, (0x7FFFFFFF >> 16) # lui $v0, 0x7fff
/* 0EFAF0 7F0BD100 3442FFFF */  ori   $v0, (0x7FFFFFFF & 0xFFFF) # ori $v0, $v0, 0xffff
/* 0EFAF4 7F0BD104 AE800034 */  sw    $zero, 0x34($s4)
/* 0EFAF8 7F0BD108 AE80003C */  sw    $zero, 0x3c($s4)
/* 0EFAFC 7F0BD10C AE820044 */  sw    $v0, 0x44($s4)
/* 0EFB00 7F0BD110 AE800048 */  sw    $zero, 0x48($s4)
/* 0EFB04 7F0BD114 AE800054 */  sw    $zero, 0x54($s4)
/* 0EFB08 7F0BD118 AE800058 */  sw    $zero, 0x58($s4)
/* 0EFB0C 7F0BD11C AE80004C */  sw    $zero, 0x4c($s4)
/* 0EFB10 7F0BD120 AE820050 */  sw    $v0, 0x50($s4)
/* 0EFB14 7F0BD124 A2800068 */  sb    $zero, 0x68($s4)
/* 0EFB18 7F0BD128 AE800060 */  sw    $zero, 0x60($s4)
/* 0EFB1C 7F0BD12C E68A0038 */  swc1  $f10, 0x38($s4)
/* 0EFB20 7F0BD130 E6900040 */  swc1  $f16, 0x40($s4)
/* 0EFB24 7F0BD134 3C0B8007 */  lui   $t3, %hi(g_CurrentPlayer) # $t3, 0x8007
/* 0EFB28 7F0BD138 256B8BC0 */  addiu $t3, %lo(g_CurrentPlayer) # addiu $t3, $t3, -0x7440
/* 0EFB2C 7F0BD13C 26520070 */  addiu $s2, $s2, 0x70
/* 0EFB30 7F0BD140 26940070 */  addiu $s4, $s4, 0x70
/* 0EFB34 7F0BD144 AE40FFC0 */  sw    $zero, -0x40($s2)
/* 0EFB38 7F0BD148 AE40FFBC */  sw    $zero, -0x44($s2)
/* 0EFB3C 7F0BD14C AE40FFB8 */  sw    $zero, -0x48($s2)
/* 0EFB40 7F0BD150 164BFFC0 */  bne   $s2, $t3, .L7F0BD054
/* 0EFB44 7F0BD154 AE40FFB4 */   sw    $zero, -0x4c($s2)
.L7F0BD158:
/* 0EFB48 7F0BD158 0FC01394 */  jal   something_with_stage_objectives
/* 0EFB4C 7F0BD15C 00000000 */   nop   
/* 0EFB50 7F0BD160 0FC3053A */  jal   mpwatchUnpauseGame
/* 0EFB54 7F0BD164 00000000 */   nop   
/* 0EFB58 7F0BD168 0FC26B58 */  jal   sub_GAME_7F09B820
/* 0EFB5C 7F0BD16C 00000000 */   nop   
/* 0EFB60 7F0BD170 0FC014FC */  jal   sub_GAME_7F005450
/* 0EFB64 7F0BD174 00000000 */   nop   
/* 0EFB68 7F0BD178 0FC01530 */  jal   zero_contents_of_80036070_74
/* 0EFB6C 7F0BD17C 00000000 */   nop   
/* 0EFB70 7F0BD180 0FC00538 */  jal   init_load_objpos_table
/* 0EFB74 7F0BD184 00000000 */   nop   
/* 0EFB78 7F0BD188 0FC005D4 */  jal   reinit_between_menus
/* 0EFB7C 7F0BD18C 00000000 */   nop   
/* 0EFB80 7F0BD190 0FC0052C */  jal   init_sound_effects_registers
/* 0EFB84 7F0BD194 00000000 */   nop   
/* 0EFB88 7F0BD198 0FC00390 */  jal   init_guards
/* 0EFB8C 7F0BD19C 00000000 */   nop   
/* 0EFB90 7F0BD1A0 0FC003D4 */  jal   set_new_rand_head_bodies
/* 0EFB94 7F0BD1A4 8FA40038 */   lw    $a0, 0x38($sp)
/* 0EFB98 7F0BD1A8 0FC00EDF */  jal   proplvreset2
/* 0EFB9C 7F0BD1AC 8FA40038 */   lw    $a0, 0x38($sp)
/* 0EFBA0 7F0BD1B0 0FC01B44 */  jal   alloc_explosion_smoke_casing_scorch_impact_buffers
/* 0EFBA4 7F0BD1B4 00000000 */   nop   
/* 0EFBA8 7F0BD1B8 0FC01C40 */  jal   alloc_shattered_window_pieces
/* 0EFBAC 7F0BD1BC 00000000 */   nop   
/* 0EFBB0 7F0BD1C0 0FC01C84 */  jal   sub_GAME_7F007290
/* 0EFBB4 7F0BD1C4 00000000 */   nop   
/* 0EFBB8 7F0BD1C8 0FC01C8C */  jal   initCheatTextBuffer
/* 0EFBBC 7F0BD1CC 00000000 */   nop   
/* 0EFBC0 7F0BD1D0 3C0C8004 */  lui   $t4, %hi(g_CurrentStageToLoad) # $t4, 0x8004
/* 0EFBC4 7F0BD1D4 8D8C0FE4 */  lw    $t4, %lo(g_CurrentStageToLoad)($t4)
/* 0EFBC8 7F0BD1D8 2401005A */  li    $at, 90
/* 0EFBCC 7F0BD1DC 15810005 */  bne   $t4, $at, .L7F0BD1F4
/* 0EFBD0 7F0BD1E0 00000000 */   nop   
/* 0EFBD4 7F0BD1E4 0FC01C9E */  jal   disableOnscreenCheatText
/* 0EFBD8 7F0BD1E8 00000000 */   nop   
/* 0EFBDC 7F0BD1EC 10000020 */  b     .L7F0BD270
/* 0EFBE0 7F0BD1F0 00000000 */   nop   
.L7F0BD1F4:
/* 0EFBE4 7F0BD1F4 0FC01A04 */  jal   init_path_table_links
/* 0EFBE8 7F0BD1F8 00000000 */   nop   
/* 0EFBEC 7F0BD1FC 0FC013F8 */  jal   init_ejected_cartridges
/* 0EFBF0 7F0BD200 00000000 */   nop   
/* 0EFBF4 7F0BD204 0FC26669 */  jal   getPlayerCount
/* 0EFBF8 7F0BD208 00008025 */   move  $s0, $zero
/* 0EFBFC 7F0BD20C 18400016 */  blez  $v0, .L7F0BD268
/* 0EFC00 7F0BD210 00000000 */   nop   
.L7F0BD214:
/* 0EFC04 7F0BD214 0FC26993 */  jal   set_cur_player
/* 0EFC08 7F0BD218 02002025 */   move  $a0, $s0
/* 0EFC0C 7F0BD21C 0FC0185C */  jal   reinit_gunheld_totaltime
/* 0EFC10 7F0BD220 00000000 */   nop   
/* 0EFC14 7F0BD224 0FC0141C */  jal   init_player_BONDdata_stats
/* 0EFC18 7F0BD228 00000000 */   nop   
/* 0EFC1C 7F0BD22C 0FC1E51B */  jal   init_player_BONDdata
/* 0EFC20 7F0BD230 00000000 */   nop   
/* 0EFC24 7F0BD234 0FC015D9 */  jal   bondviewLoadSetupIntroSection
/* 0EFC28 7F0BD238 00000000 */   nop   
/* 0EFC2C 7F0BD23C 0FC1E64E */  jal   bondviewPlayerSpawnRelated
/* 0EFC30 7F0BD240 00000000 */   nop   
/* 0EFC34 7F0BD244 0FC018C3 */  jal   sets_a_bunch_of_BONDdata_values_to_default
/* 0EFC38 7F0BD248 00000000 */   nop   
/* 0EFC3C 7F0BD24C 0FC01C9E */  jal   disableOnscreenCheatText
/* 0EFC40 7F0BD250 00000000 */   nop   
/* 0EFC44 7F0BD254 0FC26669 */  jal   getPlayerCount
/* 0EFC48 7F0BD258 26100001 */   addiu $s0, $s0, 1
/* 0EFC4C 7F0BD25C 0202082A */  slt   $at, $s0, $v0
/* 0EFC50 7F0BD260 1420FFEC */  bnez  $at, .L7F0BD214
/* 0EFC54 7F0BD264 00000000 */   nop   
.L7F0BD268:
/* 0EFC58 7F0BD268 0FC26993 */  jal   set_cur_player
/* 0EFC5C 7F0BD26C 00002025 */   move  $a0, $zero
.L7F0BD270:
/* 0EFC60 7F0BD270 0FC01535 */  jal   set_contents_of_80036078
/* 0EFC64 7F0BD274 00002025 */   move  $a0, $zero
/* 0EFC68 7F0BD278 0FC34628 */  jal   zbufDeallocate
/* 0EFC6C 7F0BD27C 00000000 */   nop   
/* 0EFC70 7F0BD280 0C000D80 */  jal   viSetVideoMode
/* 0EFC74 7F0BD284 24040001 */   li    $a0, 1
/* 0EFC78 7F0BD288 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0EFC7C 7F0BD28C 44819000 */  mtc1  $at, $f18
/* 0EFC80 7F0BD290 3C018004 */  lui   $at, %hi(D_80048368) # $at, 0x8004
/* 0EFC84 7F0BD294 00002025 */  move  $a0, $zero
/* 0EFC88 7F0BD298 0FC2FC0F */  jal   lvlSetControlsLockedFlag
/* 0EFC8C 7F0BD29C E4320FE8 */   swc1  $f18, %lo(D_80048368)($at)
/* 0EFC90 7F0BD2A0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0EFC94 7F0BD2A4 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0EFC98 7F0BD2A8 8FB00020 */  lw    $s0, 0x20($sp)
/* 0EFC9C 7F0BD2AC 8FB10024 */  lw    $s1, 0x24($sp)
/* 0EFCA0 7F0BD2B0 8FB20028 */  lw    $s2, 0x28($sp)
/* 0EFCA4 7F0BD2B4 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0EFCA8 7F0BD2B8 8FB40030 */  lw    $s4, 0x30($sp)
/* 0EFCAC 7F0BD2BC 03E00008 */  jr    $ra
/* 0EFCB0 7F0BD2C0 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif




s32 lvlGetCurrentStageToLoad(void)
{
    return g_CurrentStageToLoad;
}


#ifdef NONMATCHING
/**
 * Debug method. Something to do with portals. Button press
 * on controller 1 and 2 are used for control flow.
 *
 * address 0x7F0BDF10.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: wrong
 * - identical instructions: no
 * - identical registers: fail
 */
Gfx * lvlPortalDebug7F0BDF10(Gfx * arg0)
{
    s32 sp20;
    s32 temp_v1;
    s32 phi_a0;
    s32 i;
    s32 *p;

    sp20 = 0;

    if (arg0 != 0)
    {
        arg0 = bgDebugRemoved7F0B9DE4(arg0, g_DebugPortalsD_800483CC, -1);

        // decomp issue. Can't get the loads and stores to match.
        for (i = 0, p = &g_DebugPortalsInputBuffer_0; i < 4; i++)
        {
            p[i] = p[i+1];
        }

        temp_v1 = joyGetButtons(PLAYER_1, A_BUTTON) | joyGetButtons(PLAYER_2, A_BUTTON);

        if (g_DebugPortalsInputBuffer_3 != temp_v1)
        {
            D_800483C0 ^= 1;
        }

        if (g_DebugPortalsInputBuffer_0 != g_DebugPortalsInputBuffer_1)
        {
            D_800483C0 ^= 1;
        }

        g_DebugPortalsInputBuffer_4 = temp_v1;

        if (temp_v1 != 0)
        {
            phi_a0 = g_DebugPortalsD_800483CC;
        }
        else
        {
            phi_a0 = -1;
        }

        bgRemoved7F0B9DF4(phi_a0);

        return arg0;
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, L_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, L_JPAD))
    {
        sp20 = 1;

        // decomp issue:
        // this is incomplete / wrong.
        g_DebugPortalsD_800483CC = g_DebugPortalsD_800483CC - 1;
        
        if (g_DebugPortalsD_800483CC < 0)
        {
            g_DebugPortalsD_800483CC = 0;
        }
    }

    if (joyGetButtonsPressedThisFrame(PLAYER_1, R_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, R_JPAD))
    {
        sp20 = 1;
        g_DebugPortalsD_800483CC = g_DebugPortalsD_800483CC + 1;
    }

    if (
        (joyGetButtons(PLAYER_1, R_TRIG) | joyGetButtons(PLAYER_2, R_TRIG))
        && (joyGetButtons(PLAYER_1, L_TRIG) | joyGetButtons(PLAYER_2, L_TRIG)))
    {
        if (joyGetButtonsPressedThisFrame(PLAYER_1, D_JPAD) != 0)
        {
            bgSwapConnectedRooms(g_DebugPortalsD_800483CC);
        }
    }
    else if (joyGetButtons(PLAYER_1, R_TRIG) | joyGetButtons(PLAYER_2, R_TRIG))
    {
        if (
            (joyGetButtonsPressedThisFrame(PLAYER_1, D_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, D_JPAD)) 
            && (bgGetDataPortalsControlBytes1Bit1(g_DebugPortalsD_800483CC) == 0))
        {
            sp20 = 1;
            bgToggleDataPortalsContrlBytes1Bit1(g_DebugPortalsD_800483CC, 0);
        }

        if (
            (joyGetButtonsPressedThisFrame(PLAYER_1, U_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, U_JPAD))
            && (bgGetDataPortalsControlBytes1Bit1(g_DebugPortalsD_800483CC) != 0))
        {
            sp20 = 1;
            bgToggleDataPortalsContrlBytes1Bit1(g_DebugPortalsD_800483CC, 1);
        }
    }
    else if (joyGetButtons(PLAYER_1, L_TRIG) | joyGetButtons(PLAYER_2, L_TRIG))
    {
        if (
            (joyGetButtonsPressedThisFrame(PLAYER_1, D_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, D_JPAD))
            && bgGetDataPortalsControlBytes1Bit2(g_DebugPortalsD_800483CC))
        {
            sp20 = 1;
            bgClearDataPortalsControlBytes1Low2Bits(g_DebugPortalsD_800483CC);
        }

        if (
            (joyGetButtonsPressedThisFrame(PLAYER_1, U_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, U_JPAD))
            && (bgGetDataPortalsControlBytes1Bit2(g_DebugPortalsD_800483CC) == 0))
        {
            sp20 = 1;
            bgSetDataPortalsControlBytes1Bit2(g_DebugPortalsD_800483CC);
        }
    }
    else
    {
        if (joyGetButtonsPressedThisFrame(PLAYER_1, D_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, D_JPAD))
        {
            sp20 = 1;
            sub_GAME_7F0B9A7C(g_DebugPortalsD_800483CC);
        }

        if (joyGetButtonsPressedThisFrame(PLAYER_1, U_JPAD) | joyGetButtonsPressedThisFrame(PLAYER_2, U_JPAD))
        {
            sp20 = 1;
            sub_GAME_7F0B9A2C(g_DebugPortalsD_800483CC);
        }
    }

    if (sp20)
    {
        // removed?
    }

    return 0;

}
#else
GLOBAL_ASM(
.text
glabel lvlPortalDebug7F0BDF10
/* 0F2A40 7F0BDF10 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F2A44 7F0BDF14 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F2A48 7F0BDF18 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F2A4C 7F0BDF1C 1080003B */  beqz  $a0, .L7F0BE00C
/* 0F2A50 7F0BDF20 AFA00020 */   sw    $zero, 0x20($sp)
/* 0F2A54 7F0BDF24 3C058005 */  lui   $a1, %hi(g_DebugPortalsD_800483CC)
/* 0F2A58 7F0BDF28 8CA583CC */  lw    $a1, %lo(g_DebugPortalsD_800483CC)($a1)
/* 0F2A5C 7F0BDF2C 0FC2E779 */  jal   bgDebugRemoved7F0B9DE4
/* 0F2A60 7F0BDF30 2406FFFF */   li    $a2, -1
/* 0F2A64 7F0BDF34 3C0E8005 */  lui   $t6, %hi(g_DebugPortalsInputBuffer_1)
/* 0F2A68 7F0BDF38 8DCE83D4 */  lw    $t6, %lo(g_DebugPortalsInputBuffer_1)($t6)
/* 0F2A6C 7F0BDF3C 3C0F8005 */  lui   $t7, %hi(g_DebugPortalsInputBuffer_2)
/* 0F2A70 7F0BDF40 8DEF83D8 */  lw    $t7, %lo(g_DebugPortalsInputBuffer_2)($t7)
/* 0F2A74 7F0BDF44 3C018005 */  lui   $at, %hi(g_DebugPortalsInputBuffer_0)
/* 0F2A78 7F0BDF48 3C188005 */  lui   $t8, %hi(g_DebugPortalsInputBuffer_3)
/* 0F2A7C 7F0BDF4C AC2E83D0 */  sw    $t6, %lo(g_DebugPortalsInputBuffer_0)($at)
/* 0F2A80 7F0BDF50 8F1883DC */  lw    $t8, %lo(g_DebugPortalsInputBuffer_3)($t8)
/* 0F2A84 7F0BDF54 3C018005 */  lui   $at, %hi(g_DebugPortalsInputBuffer_1)
/* 0F2A88 7F0BDF58 AC2F83D4 */  sw    $t7, %lo(g_DebugPortalsInputBuffer_1)($at)
/* 0F2A8C 7F0BDF5C 3C038005 */  lui   $v1, %hi(g_DebugPortalsInputBuffer_4)
/* 0F2A90 7F0BDF60 3C018005 */  lui   $at, %hi(g_DebugPortalsInputBuffer_2)
/* 0F2A94 7F0BDF64 8C6383E0 */  lw    $v1, %lo(g_DebugPortalsInputBuffer_4)($v1)
/* 0F2A98 7F0BDF68 AC3883D8 */  sw    $t8, %lo(g_DebugPortalsInputBuffer_2)($at)
/* 0F2A9C 7F0BDF6C 3C018005 */  lui   $at, %hi(g_DebugPortalsInputBuffer_3)
/* 0F2AA0 7F0BDF70 AFA20028 */  sw    $v0, 0x28($sp)
/* 0F2AA4 7F0BDF74 00002025 */  move  $a0, $zero
/* 0F2AA8 7F0BDF78 34058000 */  li    $a1, 32768
/* 0F2AAC 7F0BDF7C 0C0030C3 */  jal   joyGetButtons
/* 0F2AB0 7F0BDF80 AC2383DC */   sw    $v1, %lo(g_DebugPortalsInputBuffer_3)($at)
/* 0F2AB4 7F0BDF84 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2AB8 7F0BDF88 24040001 */  li    $a0, 1
/* 0F2ABC 7F0BDF8C 0C0030C3 */  jal   joyGetButtons
/* 0F2AC0 7F0BDF90 34058000 */   li    $a1, 32768
/* 0F2AC4 7F0BDF94 3C198005 */  lui   $t9, %hi(g_DebugPortalsInputBuffer_3)
/* 0F2AC8 7F0BDF98 8F3983DC */  lw    $t9, %lo(g_DebugPortalsInputBuffer_3)($t9)
/* 0F2ACC 7F0BDF9C 00501825 */  or    $v1, $v0, $s0
/* 0F2AD0 7F0BDFA0 3C0B8005 */  lui   $t3, %hi(g_DebugPortalsInputBuffer_0)
/* 0F2AD4 7F0BDFA4 13230006 */  beq   $t9, $v1, .L7F0BDFC0
/* 0F2AD8 7F0BDFA8 3C0C8005 */   lui   $t4, %hi(g_DebugPortalsInputBuffer_1)
/* 0F2ADC 7F0BDFAC 3C028005 */  lui   $v0, %hi(D_800483C0)
/* 0F2AE0 7F0BDFB0 244283C0 */  addiu $v0, %lo(D_800483C0) # addiu $v0, $v0, -0x7c40
/* 0F2AE4 7F0BDFB4 8C490000 */  lw    $t1, ($v0)
/* 0F2AE8 7F0BDFB8 392A0001 */  xori  $t2, $t1, 1
/* 0F2AEC 7F0BDFBC AC4A0000 */  sw    $t2, ($v0)
.L7F0BDFC0:
/* 0F2AF0 7F0BDFC0 8D6B83D0 */  lw    $t3, %lo(g_DebugPortalsInputBuffer_0)($t3)
/* 0F2AF4 7F0BDFC4 8D8C83D4 */  lw    $t4, %lo(g_DebugPortalsInputBuffer_1)($t4)
/* 0F2AF8 7F0BDFC8 3C028005 */  lui   $v0, %hi(D_800483C0)
/* 0F2AFC 7F0BDFCC 244283C0 */  addiu $v0, %lo(D_800483C0) # addiu $v0, $v0, -0x7c40
/* 0F2B00 7F0BDFD0 116C0004 */  beq   $t3, $t4, .L7F0BDFE4
/* 0F2B04 7F0BDFD4 3C018005 */   lui   $at, %hi(g_DebugPortalsInputBuffer_4)
/* 0F2B08 7F0BDFD8 8C4E0000 */  lw    $t6, ($v0)
/* 0F2B0C 7F0BDFDC 39CF0001 */  xori  $t7, $t6, 1
/* 0F2B10 7F0BDFE0 AC4F0000 */  sw    $t7, ($v0)
.L7F0BDFE4:
/* 0F2B14 7F0BDFE4 10600004 */  beqz  $v1, .L7F0BDFF8
/* 0F2B18 7F0BDFE8 AC2383E0 */   sw    $v1, %lo(g_DebugPortalsInputBuffer_4)($at)
/* 0F2B1C 7F0BDFEC 3C048005 */  lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2B20 7F0BDFF0 10000002 */  b     .L7F0BDFFC
/* 0F2B24 7F0BDFF4 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
.L7F0BDFF8:
/* 0F2B28 7F0BDFF8 2404FFFF */  li    $a0, -1
.L7F0BDFFC:
/* 0F2B2C 7F0BDFFC 0FC2E77D */  jal   bgRemoved7F0B9DF4
/* 0F2B30 7F0BE000 00000000 */   nop
/* 0F2B34 7F0BE004 100000BC */  b     .L7F0BE2F8
/* 0F2B38 7F0BE008 8FA20028 */   lw    $v0, 0x28($sp)
.L7F0BE00C:
/* 0F2B3C 7F0BE00C 00002025 */  move  $a0, $zero
/* 0F2B40 7F0BE010 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2B44 7F0BE014 24050200 */   li    $a1, 512
/* 0F2B48 7F0BE018 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2B4C 7F0BE01C 24040001 */  li    $a0, 1
/* 0F2B50 7F0BE020 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2B54 7F0BE024 24050200 */   li    $a1, 512
/* 0F2B58 7F0BE028 0050C025 */  or    $t8, $v0, $s0
/* 0F2B5C 7F0BE02C 1300000B */  beqz  $t8, .L7F0BE05C
/* 0F2B60 7F0BE030 24050100 */   li    $a1, 256
/* 0F2B64 7F0BE034 3C048005 */  lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2B68 7F0BE038 8C8483CC */  lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2B6C 7F0BE03C 24190001 */  li    $t9, 1
/* 0F2B70 7F0BE040 3C018005 */  lui   $at, %hi(g_DebugPortalsD_800483CC)
/* 0F2B74 7F0BE044 2484FFFF */  addiu $a0, $a0, -1
/* 0F2B78 7F0BE048 AC2483CC */  sw    $a0, %lo(g_DebugPortalsD_800483CC)($at)
/* 0F2B7C 7F0BE04C 04810003 */  bgez  $a0, .L7F0BE05C
/* 0F2B80 7F0BE050 AFB90020 */   sw    $t9, 0x20($sp)
/* 0F2B84 7F0BE054 3C018005 */  lui   $at, %hi(g_DebugPortalsD_800483CC)
/* 0F2B88 7F0BE058 AC2083CC */  sw    $zero, %lo(g_DebugPortalsD_800483CC)($at)
.L7F0BE05C:
/* 0F2B8C 7F0BE05C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2B90 7F0BE060 00002025 */   move  $a0, $zero
/* 0F2B94 7F0BE064 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2B98 7F0BE068 24040001 */  li    $a0, 1
/* 0F2B9C 7F0BE06C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2BA0 7F0BE070 24050100 */   li    $a1, 256
/* 0F2BA4 7F0BE074 00504025 */  or    $t0, $v0, $s0
/* 0F2BA8 7F0BE078 11000008 */  beqz  $t0, .L7F0BE09C
/* 0F2BAC 7F0BE07C 24050010 */   li    $a1, 16
/* 0F2BB0 7F0BE080 3C048005 */  lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2BB4 7F0BE084 8C8483CC */  lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2BB8 7F0BE088 24090001 */  li    $t1, 1
/* 0F2BBC 7F0BE08C 3C018005 */  lui   $at, %hi(g_DebugPortalsD_800483CC)
/* 0F2BC0 7F0BE090 24840001 */  addiu $a0, $a0, 1
/* 0F2BC4 7F0BE094 AC2483CC */  sw    $a0, %lo(g_DebugPortalsD_800483CC)($at)
/* 0F2BC8 7F0BE098 AFA90020 */  sw    $t1, 0x20($sp)
.L7F0BE09C:
/* 0F2BCC 7F0BE09C 0C0030C3 */  jal   joyGetButtons
/* 0F2BD0 7F0BE0A0 00002025 */   move  $a0, $zero
/* 0F2BD4 7F0BE0A4 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2BD8 7F0BE0A8 24040001 */  li    $a0, 1
/* 0F2BDC 7F0BE0AC 0C0030C3 */  jal   joyGetButtons
/* 0F2BE0 7F0BE0B0 24050010 */   li    $a1, 16
/* 0F2BE4 7F0BE0B4 00505025 */  or    $t2, $v0, $s0
/* 0F2BE8 7F0BE0B8 11400012 */  beqz  $t2, .L7F0BE104
/* 0F2BEC 7F0BE0BC 00002025 */   move  $a0, $zero
/* 0F2BF0 7F0BE0C0 0C0030C3 */  jal   joyGetButtons
/* 0F2BF4 7F0BE0C4 24050020 */   li    $a1, 32
/* 0F2BF8 7F0BE0C8 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2BFC 7F0BE0CC 24040001 */  li    $a0, 1
/* 0F2C00 7F0BE0D0 0C0030C3 */  jal   joyGetButtons
/* 0F2C04 7F0BE0D4 24050020 */   li    $a1, 32
/* 0F2C08 7F0BE0D8 00505825 */  or    $t3, $v0, $s0
/* 0F2C0C 7F0BE0DC 11600009 */  beqz  $t3, .L7F0BE104
/* 0F2C10 7F0BE0E0 00002025 */   move  $a0, $zero
/* 0F2C14 7F0BE0E4 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2C18 7F0BE0E8 24050400 */   li    $a1, 1024
/* 0F2C1C 7F0BE0EC 10400081 */  beqz  $v0, .L7F0BE2F4
/* 0F2C20 7F0BE0F0 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2C24 7F0BE0F4 0FC2E6D9 */  jal   bgSwapConnectedRooms
/* 0F2C28 7F0BE0F8 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2C2C 7F0BE0FC 1000007E */  b     .L7F0BE2F8
/* 0F2C30 7F0BE100 00001025 */   move  $v0, $zero
.L7F0BE104:
/* 0F2C34 7F0BE104 00002025 */  move  $a0, $zero
/* 0F2C38 7F0BE108 0C0030C3 */  jal   joyGetButtons
/* 0F2C3C 7F0BE10C 24050010 */   li    $a1, 16
/* 0F2C40 7F0BE110 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2C44 7F0BE114 24040001 */  li    $a0, 1
/* 0F2C48 7F0BE118 0C0030C3 */  jal   joyGetButtons
/* 0F2C4C 7F0BE11C 24050010 */   li    $a1, 16
/* 0F2C50 7F0BE120 00506025 */  or    $t4, $v0, $s0
/* 0F2C54 7F0BE124 11800029 */  beqz  $t4, .L7F0BE1CC
/* 0F2C58 7F0BE128 00002025 */   move  $a0, $zero
/* 0F2C5C 7F0BE12C 00002025 */  move  $a0, $zero
/* 0F2C60 7F0BE130 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2C64 7F0BE134 24050400 */   li    $a1, 1024
/* 0F2C68 7F0BE138 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2C6C 7F0BE13C 24040001 */  li    $a0, 1
/* 0F2C70 7F0BE140 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2C74 7F0BE144 24050400 */   li    $a1, 1024
/* 0F2C78 7F0BE148 00506825 */  or    $t5, $v0, $s0
/* 0F2C7C 7F0BE14C 11A0000A */  beqz  $t5, .L7F0BE178
/* 0F2C80 7F0BE150 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2C84 7F0BE154 0FC2E6B9 */  jal   bgGetDataPortalsControlBytes1Bit1
/* 0F2C88 7F0BE158 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2C8C 7F0BE15C 14400006 */  bnez  $v0, .L7F0BE178
/* 0F2C90 7F0BE160 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2C94 7F0BE164 240E0001 */  li    $t6, 1
/* 0F2C98 7F0BE168 AFAE0020 */  sw    $t6, 0x20($sp)
/* 0F2C9C 7F0BE16C 8C8483CC */  lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2CA0 7F0BE170 0FC2E76F */  jal   bgToggleDataPortalsContrlBytes1Bit1
/* 0F2CA4 7F0BE174 00002825 */   move  $a1, $zero
.L7F0BE178:
/* 0F2CA8 7F0BE178 00002025 */  move  $a0, $zero
/* 0F2CAC 7F0BE17C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2CB0 7F0BE180 24050800 */   li    $a1, 2048
/* 0F2CB4 7F0BE184 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2CB8 7F0BE188 24040001 */  li    $a0, 1
/* 0F2CBC 7F0BE18C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2CC0 7F0BE190 24050800 */   li    $a1, 2048
/* 0F2CC4 7F0BE194 00507825 */  or    $t7, $v0, $s0
/* 0F2CC8 7F0BE198 11E00056 */  beqz  $t7, .L7F0BE2F4
/* 0F2CCC 7F0BE19C 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2CD0 7F0BE1A0 0FC2E6B9 */  jal   bgGetDataPortalsControlBytes1Bit1
/* 0F2CD4 7F0BE1A4 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2CD8 7F0BE1A8 10400052 */  beqz  $v0, .L7F0BE2F4
/* 0F2CDC 7F0BE1AC 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2CE0 7F0BE1B0 24180001 */  li    $t8, 1
/* 0F2CE4 7F0BE1B4 AFB80020 */  sw    $t8, 0x20($sp)
/* 0F2CE8 7F0BE1B8 8C8483CC */  lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2CEC 7F0BE1BC 0FC2E76F */  jal   bgToggleDataPortalsContrlBytes1Bit1
/* 0F2CF0 7F0BE1C0 24050001 */   li    $a1, 1
/* 0F2CF4 7F0BE1C4 1000004C */  b     .L7F0BE2F8
/* 0F2CF8 7F0BE1C8 00001025 */   move  $v0, $zero
.L7F0BE1CC:
/* 0F2CFC 7F0BE1CC 0C0030C3 */  jal   joyGetButtons
/* 0F2D00 7F0BE1D0 24050020 */   li    $a1, 32
/* 0F2D04 7F0BE1D4 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2D08 7F0BE1D8 24040001 */  li    $a0, 1
/* 0F2D0C 7F0BE1DC 0C0030C3 */  jal   joyGetButtons
/* 0F2D10 7F0BE1E0 24050020 */   li    $a1, 32
/* 0F2D14 7F0BE1E4 0050C825 */  or    $t9, $v0, $s0
/* 0F2D18 7F0BE1E8 13200027 */  beqz  $t9, .L7F0BE288
/* 0F2D1C 7F0BE1EC 00002025 */   move  $a0, $zero
/* 0F2D20 7F0BE1F0 00002025 */  move  $a0, $zero
/* 0F2D24 7F0BE1F4 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2D28 7F0BE1F8 24050400 */   li    $a1, 1024
/* 0F2D2C 7F0BE1FC 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2D30 7F0BE200 24040001 */  li    $a0, 1
/* 0F2D34 7F0BE204 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2D38 7F0BE208 24050400 */   li    $a1, 1024
/* 0F2D3C 7F0BE20C 00504025 */  or    $t0, $v0, $s0
/* 0F2D40 7F0BE210 11000009 */  beqz  $t0, .L7F0BE238
/* 0F2D44 7F0BE214 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2D48 7F0BE218 0FC2E6C1 */  jal   bgGetDataPortalsControlBytes1Bit2
/* 0F2D4C 7F0BE21C 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2D50 7F0BE220 10400005 */  beqz  $v0, .L7F0BE238
/* 0F2D54 7F0BE224 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2D58 7F0BE228 24090001 */  li    $t1, 1
/* 0F2D5C 7F0BE22C AFA90020 */  sw    $t1, 0x20($sp)
/* 0F2D60 7F0BE230 0FC2E6D1 */  jal   bgClearDataPortalsControlBytes1Low2Bits
/* 0F2D64 7F0BE234 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
.L7F0BE238:
/* 0F2D68 7F0BE238 00002025 */  move  $a0, $zero
/* 0F2D6C 7F0BE23C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2D70 7F0BE240 24050800 */   li    $a1, 2048
/* 0F2D74 7F0BE244 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2D78 7F0BE248 24040001 */  li    $a0, 1
/* 0F2D7C 7F0BE24C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2D80 7F0BE250 24050800 */   li    $a1, 2048
/* 0F2D84 7F0BE254 00505025 */  or    $t2, $v0, $s0
/* 0F2D88 7F0BE258 11400026 */  beqz  $t2, .L7F0BE2F4
/* 0F2D8C 7F0BE25C 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2D90 7F0BE260 0FC2E6C1 */  jal   bgGetDataPortalsControlBytes1Bit2
/* 0F2D94 7F0BE264 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2D98 7F0BE268 14400022 */  bnez  $v0, .L7F0BE2F4
/* 0F2D9C 7F0BE26C 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2DA0 7F0BE270 240B0001 */  li    $t3, 1
/* 0F2DA4 7F0BE274 AFAB0020 */  sw    $t3, 0x20($sp)
/* 0F2DA8 7F0BE278 0FC2E6C9 */  jal   bgSetDataPortalsControlBytes1Bit2
/* 0F2DAC 7F0BE27C 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
/* 0F2DB0 7F0BE280 1000001D */  b     .L7F0BE2F8
/* 0F2DB4 7F0BE284 00001025 */   move  $v0, $zero
.L7F0BE288:
/* 0F2DB8 7F0BE288 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2DBC 7F0BE28C 24050400 */   li    $a1, 1024
/* 0F2DC0 7F0BE290 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2DC4 7F0BE294 24040001 */  li    $a0, 1
/* 0F2DC8 7F0BE298 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2DCC 7F0BE29C 24050400 */   li    $a1, 1024
/* 0F2DD0 7F0BE2A0 00506025 */  or    $t4, $v0, $s0
/* 0F2DD4 7F0BE2A4 11800005 */  beqz  $t4, .L7F0BE2BC
/* 0F2DD8 7F0BE2A8 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2DDC 7F0BE2AC 240D0001 */  li    $t5, 1
/* 0F2DE0 7F0BE2B0 AFAD0020 */  sw    $t5, 0x20($sp)
/* 0F2DE4 7F0BE2B4 0FC2E69F */  jal   sub_GAME_7F0B9A7C
/* 0F2DE8 7F0BE2B8 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
.L7F0BE2BC:
/* 0F2DEC 7F0BE2BC 00002025 */  move  $a0, $zero
/* 0F2DF0 7F0BE2C0 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2DF4 7F0BE2C4 24050800 */   li    $a1, 2048
/* 0F2DF8 7F0BE2C8 3050FFFF */  andi  $s0, $v0, 0xffff
/* 0F2DFC 7F0BE2CC 24040001 */  li    $a0, 1
/* 0F2E00 7F0BE2D0 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F2E04 7F0BE2D4 24050800 */   li    $a1, 2048
/* 0F2E08 7F0BE2D8 00507025 */  or    $t6, $v0, $s0
/* 0F2E0C 7F0BE2DC 11C00005 */  beqz  $t6, .L7F0BE2F4
/* 0F2E10 7F0BE2E0 3C048005 */   lui   $a0, %hi(g_DebugPortalsD_800483CC)
/* 0F2E14 7F0BE2E4 240F0001 */  li    $t7, 1
/* 0F2E18 7F0BE2E8 AFAF0020 */  sw    $t7, 0x20($sp)
/* 0F2E1C 7F0BE2EC 0FC2E68B */  jal   sub_GAME_7F0B9A2C
/* 0F2E20 7F0BE2F0 8C8483CC */   lw    $a0, %lo(g_DebugPortalsD_800483CC)($a0)
.L7F0BE2F4:
/* 0F2E24 7F0BE2F4 00001025 */  move  $v0, $zero
.L7F0BE2F8:
/* 0F2E28 7F0BE2F8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F2E2C 7F0BE2FC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F2E30 7F0BE300 27BD0028 */  addiu $sp, $sp, 0x28
/* 0F2E34 7F0BE304 03E00008 */  jr    $ra
/* 0F2E38 7F0BE308 00000000 */   nop
)
#endif



/**
 * Graphics render method.
 * Also sets player max ammo if infinite ammo cheat is enabled.
 * 
 * Address 0x7F0BE30C (VERSION_US).
 */

Gfx* lvlRender(Gfx* DL)
{
    gSPSegment(DL++, SPSEGMENT_PHYSICAL, NULL);
    gSPSegment(DL++, SPSEGMENT_UNKNOWN, osVirtualToPhysical(ptr_font_DL));

    gSPDisplayList(DL++, &fontDL_0x040);
    gSPDisplayList(DL++, &fontDL_0x020);

    if (g_CurrentStageToLoad == LEVELID_TITLE)
    {
        DL = viClearZBufCurrentPlayer(DL);
        DL = video_related_F(DL);
        gDPSetScissor(DL++, G_SC_NON_INTERLACE, 0, 0, (s16)viGetX(), (s16)viGetY());
        DL = menu_jump_constructor_handler(DL);
    }
    else
    {
        s32 i;
        s32 pcount;

        pcount = getPlayerCount();

        gSPClipRatio(DL++, FRUSTRATIO_2);

        for(i = 0; i < pcount; i++)
        {
            set_cur_player(get_nth_player_from_shuffled(i));

            viSetViewSize(g_CurrentPlayer->viewx, g_CurrentPlayer->viewy);
            viSetViewPosition(g_CurrentPlayer->viewleft, g_CurrentPlayer->viewtop);
            viSetFovY(g_CurrentPlayer->fovy);
            viSetAspect(g_CurrentPlayer->aspect);

            DL = viClearZBufCurrentPlayer(DL);
            DL = video_related_F(DL);
            
            if (get_debug_render_raster() == DEB_MOVE_VIEW)
            {
                DL = sub_GAME_7F091580(DL);
            }

            if (get_debug_render_raster() == DEB_STAN_VIEW)
            {
                DL = sub_GAME_7F0B2D48(DL);
            }

            if (get_debug_render_raster() == DEB_BOND_VIEW)
            {
                DL = sub_GAME_7F087A08(DL);
            }

            DL = viSetupScreensForNumPlayers(DL);
            DL = skyRender(DL);
            sub_GAME_7F0B4884();
            determing_type_of_object_and_detection();
            chraiUpdateOnscreenPropCount();
            sub_GAME_7F03D78C();
            chraiCheckUseHeldItems();

            if (bond_pressed_reload_activate() && bond_interact_object())
            {
                attempt_reload_item_in_hand(GUNRIGHT);
                attempt_reload_item_in_hand(GUNLEFT);
            }

            sub_GAME_7F03D0D4();
            DL = bgLevelRender(DL);

            if (get_debug_portal_flag())
            {
                DL = lvlPortalDebug7F0BDF10(DL);
            }

            if (get_debug_stan_problems_flag())
            {
                DL = sub_GAME_7F0B303C(DL);
            }

            if (get_debug_stanhit_flag())
            {
                DL = sub_GAME_7F0B3034(DL);
                DL = write_stan_tiles_in_yellow(DL);
            }

            if (get_debug_stanregion_flag())
            {
                DL = sub_GAME_7F0B3034(DL);
                DL = sub_GAME_7F0B312C(DL, -0x7FC0);
            }

            if (tokenFind(1, "-stanshow_"))
            {
                StandTilePoint *tile1 = stanMatchTileName(tokenFind(1, "-stanshow_"));
                if (tile1)
                {
                    DL = sub_GAME_7F0B3034(DL);
                    DL = sub_GAME_7F0B3024(DL, tile1, 0xFF0000FF);
                }
            }

            if (tokenFind(2, "-stanshow_"))
            {
                StandTilePoint *tile2 = stanMatchTileName(tokenFind(2, "-stanshow_"));
                if (tile2)
                {
                    DL = sub_GAME_7F0B3034(DL);
                    DL = sub_GAME_7F0B3024(DL, tile2, 0xFF00FF);
                }
            }

            if (tokenFind(3, "-stanshow_"))
            {
                StandTilePoint *tile3 = stanMatchTileName(tokenFind(3, "-stanshow_"));
                if (tile3)
                {
                    DL = sub_GAME_7F0B3034(DL);
                    DL = sub_GAME_7F0B3024(DL, tile3, 0xFFFF);
                }
            }

            setanimationdebugflag(getDebugMode() == DEB_SELANIM);
            DL = sub_GAME_7F049B58(DL);

#if defined(VERSION_EU)
            sub_GAME_7F0A46A0(&DL, 1);
#else /* VERSION_US, VERSION_JP, unspecified */
            sub_GAME_7F0A4824(&DL, 1);
#endif
            DL = sub_GAME_7F0A2C44(DL);
            DL = sub_GAME_7F0A0034(DL);

            if (

#if defined(BUGFIX_R1)
                cheatIsActive(CHEAT_INFINITE_AMMO) != 0
                && (
                    (getCurrentPlayerWeaponId(GUNRIGHT) != ITEM_WATCHLASER)
                    || (g_CurrentPlayer->field_FCC == 0)
                )
#else /* VERSION_US */
                cheatIsActive(CHEAT_INFINITE_AMMO) != 0
#endif
                )
            {
                set_max_ammo_for_cur_player();
            }

            if (get_debug_render_raster() == DEB_BOND_VIEW)
            {
                DL = maybe_mp_interface(DL);
            }
            else
            {
                DL = bondviewRemoved7F08BCB8(DL);
            }

            DL = mp_watch_menu_display(DL);
        }
    }

    gDPSetScissor(DL++, G_SC_NON_INTERLACE, 0, 0, viGetX(), viGetY());

    return DL;
}


/**
 * Sets the modifier values for the level being loaded.
 * This covers the enemy accuracy, reaction speed, and similar values.
 * 
 * address 0x7F0BE8D0
 */
void lvlSetMultipliersForDifficulty(void)
{
    if (g_SelectedDifficulty == DIFFICULTY_AGENT)
    {
        f32 armorDiff = bondviewGetCurrentPlayerHealth() + get_BONDdata_watch_armor();
        f32 damageMultiplier = 1.0f;

        if (armorDiff <= 0.125f)
        {
            damageMultiplier = 0.5f;
        }
        else if (armorDiff <= 0.6f)
        {
            damageMultiplier = (((armorDiff - 0.125f) * 0.5f) / 0.47500002f) + 0.5f;
        }

        F_80030B14 = 2.0f;
        F_80030B18 = 2.0f;
        F_80030B1C = (0.5f * damageMultiplier);
        F_80030B20 = (0.5f * damageMultiplier);
        F_80030B24 = 2.0f;
        g_AiAccuracyModifier = DEFAULT_AGENT_AI_ACCURACY_MODIFIER;
        g_AiDamageModifier = (DEFAULT_AGENT_AI_DAMAGE_MODIFIER * damageMultiplier);
        g_AiHealthModifier = 2.0f;
        D_80040178 = (f32) (0.25f * damageMultiplier);
        difficulty = 1.5f;
        g_SoloAmmoMultiplier = DEFAULT_AGENT_SOLO_AMMO_MULTIPLIER;
        g_AiReactionSpeed = DEFAULT_AGENT_AI_REACTION_SPEED;
    }
    else if (g_SelectedDifficulty == DIFFICULTY_SECRET)
    {
        F_80030B14 = 1.0f;
        F_80030B18 = 1.0f;
        F_80030B1C = 0.75f;
        F_80030B20 = 0.75f;
        F_80030B24 = 1.0f;
        g_AiAccuracyModifier = DEFAULT_SECRET_AGENT_AI_ACCURACY_MODIFIER;
        g_AiDamageModifier = DEFAULT_SECRET_AGENT_AI_DAMAGE_MODIFIER;
        g_AiHealthModifier = 1.0f;
        D_80040178 = 0.75f;

#if defined(BUGFIX_R1)
        if (j_text_trigger)
        {
            difficulty = 1.1f;
        }
        else
        {
            difficulty = 0.75f;
        }
#else
        // VERSION_US
        difficulty = 0.75f;
#endif

        g_SoloAmmoMultiplier = DEFAULT_SECRET_AGENT_SOLO_AMMO_MULTIPLIER;
        g_AiReactionSpeed = DEFAULT_SECRET_AGENT_AI_REACTION_SPEED;
    }
    else if (g_SelectedDifficulty == DIFFICULTY_00)
    {
        F_80030B14 = 1.0f;
        F_80030B18 = 1.0f;
        F_80030B1C = 1.0f;
        F_80030B20 = 1.0f;
        F_80030B24 = 1.0f;
        g_AiAccuracyModifier = DEFAULT_00_AGENT_AI_ACCURACY_MODIFIER;
        g_AiDamageModifier = DEFAULT_00_AGENT_AI_DAMAGE_MODIFIER;
        g_AiHealthModifier = 1.0f;
        D_80040178 = 1.0f;

#if defined(BUGFIX_R1)
        if (j_text_trigger)
        {
            difficulty = 0.75f;
        }
        else
        {
            difficulty = 0.2f;
        }
#else
        // VERSION_US
        difficulty = 0.2f;
#endif

        g_SoloAmmoMultiplier = DEFAULT_00_AGENT_SOLO_AMMO_MULTIPLIER;
        g_AiReactionSpeed = DEFAULT_00_AGENT_AI_REACTION_SPEED;
    }
    else if (g_SelectedDifficulty == DIFFICULTY_007)
    {
        F_80030B14 = 1.0f;
        F_80030B18 = 1.0f;
        F_80030B1C = 1.0f;
        F_80030B20 = 1.0f;
        F_80030B24 = 1.0f;
        g_AiAccuracyModifier = DEFAULT_007_AI_ACCURACY_MODIFIER;
        g_AiDamageModifier = DEFAULT_007_AI_DAMAGE_MODIFIER;
        g_AiHealthModifier = 1.0f;
        D_80040178 = 1.0f;
        difficulty = 1.0f;
        g_SoloAmmoMultiplier = DEFAULT_007_SOLO_AMMO_MULTIPLIER;
        g_AiReactionSpeed = DEFAULT_007_AI_REACTION_SPEED;
    }
}


#ifdef NONMATCHING
/**
 * Multiplayer method.
 * Tracks you-only-live-twice kills/deaths.
 * Lots of debug code.
 * 
 * Address: 0x7F0BEB88 (NTSC).
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: fail
 * - identical instructions: fail
 * - identical registers: fail
 * 
 * notes: there is one big `if` block that is very wrong. A few places where two instructions are swapped.
 * Otherwise just lots of regalloc.
 */
void lvlManageMpGame(void)
{
    s32 current_time_copy;
    s32 sp180;
    s32 sp30;
    s32 sp2C;
    s32 time_limit_minus_60_seconds;
    s32 var_player_count2_again;
    s32 temp_t6;
    s32 temp_v0;
    s32 current_time;
    s32 var_player_count1;
    s32 var_player_count2;
    s32 mp_game_time_limit;
    s32 mp_game_time_limit_2;
    s32 temp_v1_7;
    s32 mp_alive_count;
    s32 mp_player_field424_count;
    s32 mp_player_currently_in_dying_animation;
    s32 phi_a2_5;
    s32 copy_g_clockTimer;
    s32 mp_players_over_point_limit;
    s32 phi_ra_2;
    s32 phi_ra_3;

    tlbmanageResetCurrentEntriesCount();

    if (g_ControlsLockedFlag != 0)
    {
        g_ClockTimer = 0;
    }
    else if (checkGamePaused() != 0)
    {
        g_ClockTimer = 0;
    }
    else
    {
        g_ClockTimer = speedgraphframes;
        D_80048380 += 1;
    }

    temp_v0 = g_ClockTimer;
    g_GlobalTimerDelta = (f32) temp_v0;
    g_GlobalTimer += temp_v0;

    if ((g_CurrentStageToLoad != LEVELID_TITLE) && (D_80048394 == 0) && (g_ClockTimer > 0))
    {
        if (g_AppendCheatSinglePlayer != 0)
        {
            s32 s0 = 1;

            for (s0 = 1; s0 != CHEAT_INVALID; s0++)
            {
                if (g_CheatActivated[s0] && !cheatIsEnemyRockets(s0))
                {
                    cheatButtonTurnOnCheatForPlayers(s0);
                }
            }
        }
    }

    if ((getPlayerCount() >= 2) && (g_CurrentStageToLoad != LEVELID_TITLE))
    {
        if (get_mission_state() == MISSION_STATE_6)
        {
            s32 i;
            struct player* p;

            mp_alive_count = 0;
            mp_player_field424_count = 0;

            for (i=0; i<getPlayerCount(); i++)
            {
                p = g_playerPointers[i];

                if (p->bonddead != 0)
                {
                    mp_alive_count++;
                    if (p->redbloodfinished != 0)
                    {
                        mp_player_field424_count++;
                    }
                }
            }

            if ((mp_alive_count > 0) && (mp_alive_count == mp_player_field424_count))
            {
                set_missionstate(MISSION_STATE_1);
            }
        }

        mp_game_time_limit = g_MpTime;
        if (mp_game_time_limit > 0)
        {
            current_time = D_80048394;
            time_limit_minus_60_seconds = mp_game_time_limit - 0xE10;
            temp_t6 = g_ClockTimer + current_time;
            sp180 = temp_t6;
            current_time_copy = current_time;

            if ((current_time < time_limit_minus_60_seconds) && (temp_t6 >= time_limit_minus_60_seconds))
            {
                s32 i = 0;
                for (i=0; i<getPlayerCount(); i++)
                {
                    set_cur_player(i);
                    hudmsgBottomShow("One minute left");
                }
            }

            // sound alarm when game is about to end (10 seconds before end)
            if ((sp180 >= (g_MpTime - 0x258)) && (g_MpSoundStateRelated == 0) && (lvlGetControlsLockedFlag() == 0))
            {
                sndPlaySfx(g_musicSfxBufferPtr, 0xA1, &g_MpSoundStateRelated);
            }

            // stop alarm
            if (lvlGetControlsLockedFlag() != 0)
            {
                if ((g_MpSoundStateRelated != NULL) && (sndGetPlayingState(g_MpSoundStateRelated) != 0))
                {
                    sndDeactivate(g_MpSoundStateRelated);
                }
            }

            mp_game_time_limit_2 = g_MpTime;
            if ((current_time_copy < mp_game_time_limit_2) && (sp180 >= mp_game_time_limit_2))
            {
                mpCalculateAwards(0);
            }
        }

        // when playing with a kill limit, g_MpPoint is not zero
        if ((g_MpPoint > 0) && (g_ClockTimer != 0))
        {
            s32 i;
            struct player* p;

            var_player_count1 = getPlayerCount();
            mp_players_over_point_limit = 0;
            mp_player_currently_in_dying_animation = 0;

            for (i=0; i<var_player_count1; i++)
            {
                p = g_playerPointers[i];

                if (p->bonddead != 0 &&
                    (p->redbloodfinished == 0 || p->deathanimfinished == 0 || p->colourfadetimemax60 >= 0.0f))
                {
                    mp_player_currently_in_dying_animation++;
                }

                if (get_points_for_mp_player(i) >= g_MpPoint)
                {
                    // counts players over kill limit
                    mp_players_over_point_limit++;
                }
            }

            if (mp_players_over_point_limit > 0)
            {
                if (mp_player_currently_in_dying_animation == 0)
                {
                    // end game after dying players are finished dying
                    mpCalculateAwards(0);
                }
                else
                {
                    // this will cause the game to freeze players, to stop them from moving once game ended
                    mpwatchSetStopPlayFlag();
                }
            }
        }


// decomp issue: begin very wrong section
        if ((get_scenario() == SCENARIO_YOLT) && (g_ClockTimer != 0))
        {
            s32 not_dead_count = 0;
            s32 killed_count = 0;
            s32 i;
            s32 j;

            var_player_count2 = getPlayerCount();

            //if (var_player_count2 > 0)
            //{
                for (i=0; i < var_player_count2; i++)
                {
                    if (var_player_count2 > 0)
                    {
                        var_player_count2_again = var_player_count2 & 3;

                        if (var_player_count2_again != 0)
                        {
                            for (j=0; j<var_player_count2_again; j++)
                            {
                                if (g_playerPointers[j]->bonddead == 0)
                                {
                                    not_dead_count++;
                                }

                                killed_count += g_playerPlayerData[j].killed_p1;
                            }
                        }
                        else
                        {
                            for (j=0; j<var_player_count2_again; j++)
                            {
                                if (g_playerPointers[0]->bonddead == 0)
                                {
                                    not_dead_count++;
                                }
                                if (g_playerPointers[1]->bonddead == 0)
                                {
                                    not_dead_count++;
                                }
                                if (g_playerPointers[2]->bonddead == 0)
                                {
                                    not_dead_count++;
                                }
                                if (g_playerPointers[3]->bonddead == 0)
                                {
                                    not_dead_count++;
                                }

                                killed_count =
                                    g_playerPlayerData[0].killed_p1 +
                                    g_playerPlayerData[1].killed_p1 +
                                    g_playerPlayerData[2].killed_p1 +
                                    g_playerPlayerData[3].killed_p1;
                            }
                        }
                    }

                    if (killed_count >= 2)
                    {
                        if (g_playerPlayerData[i].order_out_in_yolt == 0)
                        {
                            g_playerPlayerData[i].order_out_in_yolt = (u8) (phi_a2_5 + 1);
                        }

                        if ((g_playerPointers[i]->redbloodfinished != 0) && (g_playerPointers[i]->deathanimfinished != 0) && (g_playerPointers[i]->colourfadetimemax60 < 0.0f))
                        {
                            phi_ra_2 = phi_ra_3 + 1;
                        }
                    }
                }
            //}
            
            temp_v1_7 = var_player_count2 - 1;
            if (not_dead_count >= temp_v1_7)
            {
                mpCalculateAwards(0);
            }
            else if (killed_count >= temp_v1_7)
            {
                mpwatchSetStopPlayFlag();
            }
        } // end YOLT
// decomp issue: end very wrong section
    }

    D_80048394 = D_80048394 + g_ClockTimer;
    g_CurrentMultiPlayerSec = (f32) (D_80048394) / 60.0f;
    D_800483A8 = D_800483A8 + g_ClockTimer;
    g_CurrentMultiPlayerMin = (f32) (D_800483A8) / 60.0f;

    if (joyGetButtonsPressedThisFrame(PLAYER_1, ANY_BUTTON))
    {
        D_80048388 = 0;
        D_80048390 = 0;
        copy_g_clockTimer = g_ClockTimer;
    }
    else
    {
        D_80048390 = D_80048390 + g_ClockTimer;
        copy_g_clockTimer = g_ClockTimer;

        if (D_80048390 >= 0x708)
        {
            D_80048388 = 1;
        }
    }

    if (D_80048388 != 0)
    {
        D_8004838C += copy_g_clockTimer;
    }
    else
    {
        D_800483B0 = D_800483B0 + copy_g_clockTimer;
        g_StageTimeSec = (f32) (D_800483B0) / 60.0f;
        D_800483B8 = D_800483B8 + copy_g_clockTimer;
        g_PowerOnTimeSec = (f32) (D_800483B8) / 60.0f;
    }

    viSetUseZBuf(1);

    if (g_CurrentStageToLoad == LEVELID_TITLE)
    {
        cheat_buttons_mp_related();
        menu_init();
        something_with_LnameJ();
    }
    else
    {
        sub_GAME_7F09BBBC();
        lvlSetMultipliersForDifficulty();
        sub_GAME_7F0BC7D4();
        sub_GAME_7F092E50();
        sub_GAME_7F094438();
        update_bullet_sparks_and_dust_clouds();
        sub_GAME_7F068E6C();
        update_broken_windows();
        update_gray_flying_particles();
        handle_mp_respawn_and_some_things();
        reset_all_music_slots();
        something_with_LnameJ();

        if ((get_debug_joy2detailedit_flag() != 0) && (D_800483C8 == 0))
        {
            s32 i;
            D_800483C8 = (struct LvlMpUnknown*)mempAllocBytesInBank(0x3000, 4);
            if (D_800483C8 != 0)
            {
                for (i=0; i<3000; i++)
                {
                    D_800483C8[i].unk_0 = 0xff;
                    D_800483C8[i].unk_1 = (D_800483C8[i].unk_1 & 0xFF1F) | 0x20;
                    D_800483C8[i].unk_1 = (D_800483C8[i].unk_1 & 0xFFE3) | 4;
                }
            }
        }

        if (get_debug_portal_flag() != 0)
        {
            lvlPortalDebug7F0BDF10(0);
        }

        switch (getDebugMode())
        {
            case 4:
            {
                if (joyGetButtonsPressedThisFrame(PLAYER_1, L_CBUTTONS))
                {
                    sub_GAME_7F0AF630(-1);
                    sub_GAME_7F0B2D38(0, 0, 0);
                }

                if (joyGetButtonsPressedThisFrame(PLAYER_1, R_CBUTTONS))
                {
                    sub_GAME_7F0AF630(1);
                    sub_GAME_7F0B2D38(0, 0, 0);
                }
            }
            break;

            case 8:
            {
                if (joyGetButtonsPressedThisFrame(PLAYER_1, L_CBUTTONS))
                {
                    chrDecrementAnimationTablePointerCount();
                }

                if (joyGetButtonsPressedThisFrame(PLAYER_1, R_CBUTTONS))
                {
                    chrIncrementAnimationTablePointerCount();
                }

                if (joyGetButtonsPressedThisFrame(PLAYER_1, L_TRIG))
                {
                    chrToggleD_8002C90C();
                }

                sub_GAME_7F022EE0(0 < joyGetButtons(PLAYER_1, R_TRIG));
            }
            break;
        }

    }

    switch (getDebugMode())
    {
        case 0x38:
        {
            sp30 = viGetHorizontalOffset();
            sp2C = viGet800232A0();
            if (joyGetButtons(PLAYER_1, D_CBUTTONS))
            {
                sp2C += 1;
            }
            if (joyGetButtons(PLAYER_1, U_CBUTTONS))
            {
                sp2C += -1;
            }
            if (joyGetButtons(PLAYER_1, R_CBUTTONS))
            {
                sp30 += 1;
            }
            if (joyGetButtons(PLAYER_1, L_CBUTTONS))
            {
                sp30 += -1;
            }
            viSetHorizontalOffset(sp30);
            viSet800232A0(sp2C);
        }
        break;

        case 0xc:
        {
            if (joyGetButtonsPressedThisFrame(PLAYER_1, (L_JPAD | L_CBUTTONS)))
            {
                lvlMusicAppendPlayEndTheme();
            }

            if (joyGetButtonsPressedThisFrame(PLAYER_1, (R_JPAD | R_CBUTTONS)))
            {
                lvlMusicAppendPlaySoloDeathShort();
            }

            if (joyGetButtonsPressedThisFrame(PLAYER_1, D_JPAD))
            {
                musicTrack1Stop();
            }

            if (joyGetButtonsPressedThisFrame(PLAYER_1, B_BUTTON))
            {
                musicTrack1SaveCurrentVolumeAsTrackDefault();
            }
        }
        break;

        // decomp issue: some of the lui R_MIPS_HI16 for g_musicSfxBufferPtr and g_DebugMpGameSoundFxIndex are swapped
        case 0xd:
        {
            s16 sound_index;
            s16 *sound_index_ptr = &g_DebugMpGameSoundFxIndex;

            if (joyGetButtonsPressedThisFrame(PLAYER_1, (D_JPAD | L_JPAD | L_TRIG | L_CBUTTONS)))
            {
                sound_index = g_DebugMpGameSoundFxIndex - 1;
                *sound_index_ptr = sound_index;
                sndPlaySfx(g_musicSfxBufferPtr, sound_index, NULL);
            }

            if (joyGetButtonsPressedThisFrame(PLAYER_1, (U_JPAD | R_JPAD | R_TRIG | R_CBUTTONS)))
            {
                sound_index = g_DebugMpGameSoundFxIndex + 1;
                *sound_index_ptr = sound_index;
                sndPlaySfx(g_musicSfxBufferPtr, sound_index, NULL);
            }

            if (joyGetButtonsPressedThisFrame(PLAYER_1, D_CBUTTONS))
            {
                sndDeactivateAllSfxByFlag_1();
            }

            if (joyGetButtonsPressedThisFrame(PLAYER_1, U_CBUTTONS))
            {
                sound_index = g_DebugMpGameSoundFxIndex;
                sndPlaySfx(g_musicSfxBufferPtr, sound_index, NULL);
            }
        }
        break;

        default:
        break;
    }

}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.rdata
#const char aOneMinuteLeft[] = "One minute left";
glabel aOneMinuteLeft
.word 0x4f6e6520
.word 0x6d696e75
.word 0x7465206c
.word 0x65667400
#const char aSetdetailDDDDDDDDD[] = "setdetail %d %d %d %d %d %d %d %d %d";
glabel aSetdetailDDDDDDDDD
.word 0x73657464
.word 0x65746169
.word 0x6c202564
.word 0x20256420
.word 0x25642025
.word 0x64202564
.word 0x20256420
.word 0x25642025
.word 0x64202564
.word 0x00000000
.text
glabel lvlManageMpGame
/* 0F36B8 7F0BEB88 27BDFE68 */  addiu $sp, $sp, -0x198
/* 0F36BC 7F0BEB8C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F36C0 7F0BEB90 0C000626 */  jal   tlbmanageResetCurrentEntriesCount
/* 0F36C4 7F0BEB94 00000000 */   nop
/* 0F36C8 7F0BEB98 3C0E8005 */  lui   $t6, %hi(g_ControlsLockedFlag)
/* 0F36CC 7F0BEB9C 8DCE8370 */  lw    $t6, %lo(g_ControlsLockedFlag)($t6)
/* 0F36D0 7F0BEBA0 3C018005 */  lui   $at, %hi(g_ClockTimer)
/* 0F36D4 7F0BEBA4 11C00003 */  beqz  $t6, .L7F0BEBB4
/* 0F36D8 7F0BEBA8 00000000 */   nop
/* 0F36DC 7F0BEBAC 10000010 */  b     .L7F0BEBF0
/* 0F36E0 7F0BEBB0 AC208374 */   sw    $zero, %lo(g_ClockTimer)($at)
.L7F0BEBB4:
/* 0F36E4 7F0BEBB4 0FC31820 */  jal   checkGamePaused
/* 0F36E8 7F0BEBB8 00000000 */   nop
/* 0F36EC 7F0BEBBC 10400004 */  beqz  $v0, .L7F0BEBD0
/* 0F36F0 7F0BEBC0 3C0F8005 */   lui   $t7, %hi(speedgraphframes)
/* 0F36F4 7F0BEBC4 3C018005 */  lui   $at, %hi(g_ClockTimer)
/* 0F36F8 7F0BEBC8 10000009 */  b     .L7F0BEBF0
/* 0F36FC 7F0BEBCC AC208374 */   sw    $zero, %lo(g_ClockTimer)($at)
.L7F0BEBD0:
/* 0F3700 7F0BEBD0 8DEF8498 */  lw    $t7, %lo(speedgraphframes)($t7)
/* 0F3704 7F0BEBD4 3C028005 */  lui   $v0, %hi(D_80048380)
/* 0F3708 7F0BEBD8 3C018005 */  lui   $at, %hi(g_ClockTimer)
/* 0F370C 7F0BEBDC 24428380 */  addiu $v0, %lo(D_80048380) # addiu $v0, $v0, -0x7c80
/* 0F3710 7F0BEBE0 AC2F8374 */  sw    $t7, %lo(g_ClockTimer)($at)
/* 0F3714 7F0BEBE4 8C580000 */  lw    $t8, ($v0)
/* 0F3718 7F0BEBE8 27190001 */  addiu $t9, $t8, 1
/* 0F371C 7F0BEBEC AC590000 */  sw    $t9, ($v0)
.L7F0BEBF0:
/* 0F3720 7F0BEBF0 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0F3724 7F0BEBF4 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F3728 7F0BEBF8 3C038005 */  lui   $v1, %hi(g_GlobalTimer)
/* 0F372C 7F0BEBFC 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta)
/* 0F3730 7F0BEC00 44822000 */  mtc1  $v0, $f4
/* 0F3734 7F0BEC04 2463837C */  addiu $v1, %lo(g_GlobalTimer) # addiu $v1, $v1, -0x7c84
/* 0F3738 7F0BEC08 3C188005 */  lui   $t8, %hi(g_CurrentStageToLoad)
/* 0F373C 7F0BEC0C 468021A0 */  cvt.s.w $f6, $f4
/* 0F3740 7F0BEC10 3C198005 */  lui   $t9, %hi(D_80048394)
/* 0F3744 7F0BEC14 E4268378 */  swc1  $f6, %lo(g_GlobalTimerDelta)($at)
/* 0F3748 7F0BEC18 8C6E0000 */  lw    $t6, ($v1)
/* 0F374C 7F0BEC1C 2401005A */  li    $at, 90
/* 0F3750 7F0BEC20 01C27821 */  addu  $t7, $t6, $v0
/* 0F3754 7F0BEC24 AC6F0000 */  sw    $t7, ($v1)
/* 0F3758 7F0BEC28 8F188364 */  lw    $t8, %lo(g_CurrentStageToLoad)($t8)
/* 0F375C 7F0BEC2C 1301001D */  beq   $t8, $at, .L7F0BECA4
/* 0F3760 7F0BEC30 00000000 */   nop
/* 0F3764 7F0BEC34 8F398394 */  lw    $t9, %lo(D_80048394)($t9)
/* 0F3768 7F0BEC38 1720001A */  bnez  $t9, .L7F0BECA4
/* 0F376C 7F0BEC3C 00000000 */   nop
/* 0F3770 7F0BEC40 18400018 */  blez  $v0, .L7F0BECA4
/* 0F3774 7F0BEC44 3C0E8003 */   lui   $t6, %hi(g_AppendCheatSinglePlayer)
/* 0F3778 7F0BEC48 8DCEA900 */  lw    $t6, %lo(g_AppendCheatSinglePlayer)($t6)
/* 0F377C 7F0BEC4C 3C038007 */  lui   $v1, %hi(g_CheatActivated + 1)
/* 0F3780 7F0BEC50 246396A1 */  addiu $v1, %lo(g_CheatActivated + 1) # addiu $v1, $v1, -0x695f
/* 0F3784 7F0BEC54 11C00013 */  beqz  $t6, .L7F0BECA4
/* 0F3788 7F0BEC58 24040001 */   li    $a0, 1
.L7F0BEC5C:
/* 0F378C 7F0BEC5C 906F0000 */  lbu   $t7, ($v1)
/* 0F3790 7F0BEC60 51E0000D */  beql  $t7, $zero, .L7F0BEC98
/* 0F3794 7F0BEC64 24840001 */   addiu $a0, $a0, 1
/* 0F3798 7F0BEC68 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F379C 7F0BEC6C 0FC24697 */  jal   cheatIsEnemyRockets
/* 0F37A0 7F0BEC70 AFA40194 */   sw    $a0, 0x194($sp)
/* 0F37A4 7F0BEC74 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F37A8 7F0BEC78 14400006 */  bnez  $v0, .L7F0BEC94
/* 0F37AC 7F0BEC7C 8FA40194 */   lw    $a0, 0x194($sp)
/* 0F37B0 7F0BEC80 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F37B4 7F0BEC84 0FC246AB */  jal   cheatButtonTurnOnCheatForPlayers
/* 0F37B8 7F0BEC88 AFA40194 */   sw    $a0, 0x194($sp)
/* 0F37BC 7F0BEC8C 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F37C0 7F0BEC90 8FA40194 */  lw    $a0, 0x194($sp)
.L7F0BEC94:
/* 0F37C4 7F0BEC94 24840001 */  addiu $a0, $a0, 1
.L7F0BEC98:
/* 0F37C8 7F0BEC98 2401004B */  li    $at, 75
/* 0F37CC 7F0BEC9C 1481FFEF */  bne   $a0, $at, .L7F0BEC5C
/* 0F37D0 7F0BECA0 24630001 */   addiu $v1, $v1, 1
.L7F0BECA4:
/* 0F37D4 7F0BECA4 0FC26919 */  jal   getPlayerCount
/* 0F37D8 7F0BECA8 00000000 */   nop
/* 0F37DC 7F0BECAC 28410002 */  slti  $at, $v0, 2
/* 0F37E0 7F0BECB0 1420014B */  bnez  $at, .L7F0BF1E0
/* 0F37E4 7F0BECB4 3C188005 */   lui   $t8, %hi(g_CurrentStageToLoad)
/* 0F37E8 7F0BECB8 8F188364 */  lw    $t8, %lo(g_CurrentStageToLoad)($t8)
/* 0F37EC 7F0BECBC 2401005A */  li    $at, 90
/* 0F37F0 7F0BECC0 13010147 */  beq   $t8, $at, .L7F0BF1E0
/* 0F37F4 7F0BECC4 00000000 */   nop
/* 0F37F8 7F0BECC8 0FC3030C */  jal   get_mission_state
/* 0F37FC 7F0BECCC 00000000 */   nop
/* 0F3800 7F0BECD0 24010006 */  li    $at, 6
/* 0F3804 7F0BECD4 14410029 */  bne   $v0, $at, .L7F0BED7C
/* 0F3808 7F0BECD8 00000000 */   nop
/* 0F380C 7F0BECDC AFA00190 */  sw    $zero, 0x190($sp)
/* 0F3810 7F0BECE0 AFA0018C */  sw    $zero, 0x18c($sp)
/* 0F3814 7F0BECE4 0FC26919 */  jal   getPlayerCount
/* 0F3818 7F0BECE8 AFA00188 */   sw    $zero, 0x188($sp)
/* 0F381C 7F0BECEC 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F3820 7F0BECF0 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F3824 7F0BECF4 1840001B */  blez  $v0, .L7F0BED64
/* 0F3828 7F0BECF8 8FA60188 */   lw    $a2, 0x188($sp)
/* 0F382C 7F0BECFC 3C0E8008 */  lui   $t6, %hi(g_playerPointers)
/* 0F3830 7F0BED00 25CE9EE0 */  addiu $t6, %lo(g_playerPointers) # addiu $t6, $t6, -0x6120
/* 0F3834 7F0BED04 0003C880 */  sll   $t9, $v1, 2
/* 0F3838 7F0BED08 032E2021 */  addu  $a0, $t9, $t6
.L7F0BED0C:
/* 0F383C 7F0BED0C 8C820000 */  lw    $v0, ($a0)
/* 0F3840 7F0BED10 24630001 */  addiu $v1, $v1, 1
/* 0F3844 7F0BED14 24840004 */  addiu $a0, $a0, 4
/* 0F3848 7F0BED18 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F384C 7F0BED1C 51E00007 */  beql  $t7, $zero, .L7F0BED3C
/* 0F3850 7F0BED20 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F3854 7F0BED24 8C580424 */  lw    $t8, 0x424($v0)
/* 0F3858 7F0BED28 24A50001 */  addiu $a1, $a1, 1
/* 0F385C 7F0BED2C 53000003 */  beql  $t8, $zero, .L7F0BED3C
/* 0F3860 7F0BED30 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F3864 7F0BED34 24C60001 */  addiu $a2, $a2, 1
/* 0F3868 7F0BED38 AFA30190 */  sw    $v1, 0x190($sp)
.L7F0BED3C:
/* 0F386C 7F0BED3C AFA4001C */  sw    $a0, 0x1c($sp)
/* 0F3870 7F0BED40 AFA5018C */  sw    $a1, 0x18c($sp)
/* 0F3874 7F0BED44 0FC26919 */  jal   getPlayerCount
/* 0F3878 7F0BED48 AFA60188 */   sw    $a2, 0x188($sp)
/* 0F387C 7F0BED4C 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F3880 7F0BED50 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0F3884 7F0BED54 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F3888 7F0BED58 0062082A */  slt   $at, $v1, $v0
/* 0F388C 7F0BED5C 1420FFEB */  bnez  $at, .L7F0BED0C
/* 0F3890 7F0BED60 8FA60188 */   lw    $a2, 0x188($sp)
.L7F0BED64:
/* 0F3894 7F0BED64 18A00005 */  blez  $a1, .L7F0BED7C
/* 0F3898 7F0BED68 00000000 */   nop
/* 0F389C 7F0BED6C 14A60003 */  bne   $a1, $a2, .L7F0BED7C
/* 0F38A0 7F0BED70 00000000 */   nop
/* 0F38A4 7F0BED74 0FC3030F */  jal   set_missionstate
/* 0F38A8 7F0BED78 24040001 */   li    $a0, 1
.L7F0BED7C:
/* 0F38AC 7F0BED7C 3C038005 */  lui   $v1, %hi(g_MpTime)
/* 0F38B0 7F0BED80 8C638398 */  lw    $v1, %lo(g_MpTime)($v1)
/* 0F38B4 7F0BED84 3C028005 */  lui   $v0, %hi(D_80048394)
/* 0F38B8 7F0BED88 3C198005 */  lui   $t9, %hi(g_ClockTimer)
/* 0F38BC 7F0BED8C 18600049 */  blez  $v1, .L7F0BEEB4
/* 0F38C0 7F0BED90 00000000 */   nop
/* 0F38C4 7F0BED94 8C428394 */  lw    $v0, %lo(D_80048394)($v0)
/* 0F38C8 7F0BED98 8F398374 */  lw    $t9, %lo(g_ClockTimer)($t9)
/* 0F38CC 7F0BED9C 2464F1F0 */  addiu $a0, $v1, -0xe10
/* 0F38D0 7F0BEDA0 0044082A */  slt   $at, $v0, $a0
/* 0F38D4 7F0BEDA4 03227021 */  addu  $t6, $t9, $v0
/* 0F38D8 7F0BEDA8 AFAE0180 */  sw    $t6, 0x180($sp)
/* 0F38DC 7F0BEDAC 10200015 */  beqz  $at, .L7F0BEE04
/* 0F38E0 7F0BEDB0 AFA20184 */   sw    $v0, 0x184($sp)
/* 0F38E4 7F0BEDB4 01C4082A */  slt   $at, $t6, $a0
/* 0F38E8 7F0BEDB8 14200012 */  bnez  $at, .L7F0BEE04
/* 0F38EC 7F0BEDBC 00000000 */   nop
/* 0F38F0 7F0BEDC0 0FC26919 */  jal   getPlayerCount
/* 0F38F4 7F0BEDC4 AFA0017C */   sw    $zero, 0x17c($sp)
/* 0F38F8 7F0BEDC8 1840000E */  blez  $v0, .L7F0BEE04
/* 0F38FC 7F0BEDCC 00000000 */   nop
.L7F0BEDD0:
/* 0F3900 7F0BEDD0 0FC26C43 */  jal   set_cur_player
/* 0F3904 7F0BEDD4 8FA4017C */   lw    $a0, 0x17c($sp)
/* 0F3908 7F0BEDD8 3C048006 */  lui   $a0, %hi(aOneMinuteLeft)
/* 0F390C 7F0BEDDC 0FC228F2 */  jal   hudmsgBottomShow
/* 0F3910 7F0BEDE0 2484B704 */   addiu $a0, %lo(aOneMinuteLeft) # addiu $a0, $a0, -0x48fc
/* 0F3914 7F0BEDE4 8FAF017C */  lw    $t7, 0x17c($sp)
/* 0F3918 7F0BEDE8 25F80001 */  addiu $t8, $t7, 1
/* 0F391C 7F0BEDEC 0FC26919 */  jal   getPlayerCount
/* 0F3920 7F0BEDF0 AFB8017C */   sw    $t8, 0x17c($sp)
/* 0F3924 7F0BEDF4 8FB9017C */  lw    $t9, 0x17c($sp)
/* 0F3928 7F0BEDF8 0322082A */  slt   $at, $t9, $v0
/* 0F392C 7F0BEDFC 1420FFF4 */  bnez  $at, .L7F0BEDD0
/* 0F3930 7F0BEE00 00000000 */   nop
.L7F0BEE04:
/* 0F3934 7F0BEE04 3C0F8005 */  lui   $t7, %hi(g_MpTime)
/* 0F3938 7F0BEE08 8DEF8398 */  lw    $t7, %lo(g_MpTime)($t7)
/* 0F393C 7F0BEE0C 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F3940 7F0BEE10 3C198005 */  lui   $t9, %hi(g_MpSoundStateRelated)
/* 0F3944 7F0BEE14 25F8FDA8 */  addiu $t8, $t7, -0x258
/* 0F3948 7F0BEE18 01D8082A */  slt   $at, $t6, $t8
/* 0F394C 7F0BEE1C 1420000D */  bnez  $at, .L7F0BEE54
/* 0F3950 7F0BEE20 00000000 */   nop
/* 0F3954 7F0BEE24 8F3983A0 */  lw    $t9, %lo(g_MpSoundStateRelated)($t9)
/* 0F3958 7F0BEE28 1720000A */  bnez  $t9, .L7F0BEE54
/* 0F395C 7F0BEE2C 00000000 */   nop
/* 0F3960 7F0BEE30 0FC2FF01 */  jal   lvlGetControlsLockedFlag
/* 0F3964 7F0BEE34 00000000 */   nop
/* 0F3968 7F0BEE38 14400006 */  bnez  $v0, .L7F0BEE54
/* 0F396C 7F0BEE3C 3C048006 */   lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0F3970 7F0BEE40 3C068005 */  lui   $a2, %hi(g_MpSoundStateRelated)
/* 0F3974 7F0BEE44 24C683A0 */  addiu $a2, %lo(g_MpSoundStateRelated) # addiu $a2, $a2, -0x7c60
/* 0F3978 7F0BEE48 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F397C 7F0BEE4C 0C002382 */  jal   sndPlaySfx
/* 0F3980 7F0BEE50 240500A1 */   li    $a1, 161
.L7F0BEE54:
/* 0F3984 7F0BEE54 0FC2FF01 */  jal   lvlGetControlsLockedFlag
/* 0F3988 7F0BEE58 00000000 */   nop
/* 0F398C 7F0BEE5C 1040000A */  beqz  $v0, .L7F0BEE88
/* 0F3990 7F0BEE60 3C048005 */   lui   $a0, %hi(g_MpSoundStateRelated)
/* 0F3994 7F0BEE64 8C8483A0 */  lw    $a0, %lo(g_MpSoundStateRelated)($a0)
/* 0F3998 7F0BEE68 10800007 */  beqz  $a0, .L7F0BEE88
/* 0F399C 7F0BEE6C 00000000 */   nop
/* 0F39A0 7F0BEE70 0C00237C */  jal   sndGetPlayingState
/* 0F39A4 7F0BEE74 00000000 */   nop
/* 0F39A8 7F0BEE78 10400003 */  beqz  $v0, .L7F0BEE88
/* 0F39AC 7F0BEE7C 3C048005 */   lui   $a0, %hi(g_MpSoundStateRelated)
/* 0F39B0 7F0BEE80 0C002408 */  jal   sndDeactivate
/* 0F39B4 7F0BEE84 8C8483A0 */   lw    $a0, %lo(g_MpSoundStateRelated)($a0)
.L7F0BEE88:
/* 0F39B8 7F0BEE88 3C038005 */  lui   $v1, %hi(g_MpTime)
/* 0F39BC 7F0BEE8C 8C638398 */  lw    $v1, %lo(g_MpTime)($v1)
/* 0F39C0 7F0BEE90 8FAF0184 */  lw    $t7, 0x184($sp)
/* 0F39C4 7F0BEE94 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F39C8 7F0BEE98 01E3082A */  slt   $at, $t7, $v1
/* 0F39CC 7F0BEE9C 10200005 */  beqz  $at, .L7F0BEEB4
/* 0F39D0 7F0BEEA0 01C3082A */   slt   $at, $t6, $v1
/* 0F39D4 7F0BEEA4 14200003 */  bnez  $at, .L7F0BEEB4
/* 0F39D8 7F0BEEA8 00000000 */   nop
/* 0F39DC 7F0BEEAC 0FC3094C */  jal   mpCalculateAwards
/* 0F39E0 7F0BEEB0 00002025 */   move  $a0, $zero
.L7F0BEEB4:
/* 0F39E4 7F0BEEB4 3C188005 */  lui   $t8, %hi(g_MpPoint)
/* 0F39E8 7F0BEEB8 8F18839C */  lw    $t8, %lo(g_MpPoint)($t8)
/* 0F39EC 7F0BEEBC 3C198005 */  lui   $t9, %hi(g_ClockTimer)
/* 0F39F0 7F0BEEC0 1B00003D */  blez  $t8, .L7F0BEFB8
/* 0F39F4 7F0BEEC4 00000000 */   nop
/* 0F39F8 7F0BEEC8 8F398374 */  lw    $t9, %lo(g_ClockTimer)($t9)
/* 0F39FC 7F0BEECC 1320003A */  beqz  $t9, .L7F0BEFB8
/* 0F3A00 7F0BEED0 00000000 */   nop
/* 0F3A04 7F0BEED4 0FC26919 */  jal   getPlayerCount
/* 0F3A08 7F0BEED8 00000000 */   nop
/* 0F3A0C 7F0BEEDC 00403825 */  move  $a3, $v0
/* 0F3A10 7F0BEEE0 00002825 */  move  $a1, $zero
/* 0F3A14 7F0BEEE4 00003025 */  move  $a2, $zero
/* 0F3A18 7F0BEEE8 18400029 */  blez  $v0, .L7F0BEF90
/* 0F3A1C 7F0BEEEC 00002025 */   move  $a0, $zero
/* 0F3A20 7F0BEEF0 3C038008 */  lui   $v1, %hi(g_playerPointers)
/* 0F3A24 7F0BEEF4 44800000 */  mtc1  $zero, $f0
/* 0F3A28 7F0BEEF8 24639EE0 */  addiu $v1, %lo(g_playerPointers) # addiu $v1, $v1, -0x6120
.L7F0BEEFC:
/* 0F3A2C 7F0BEEFC 8C620000 */  lw    $v0, ($v1)
/* 0F3A30 7F0BEF00 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F3A34 7F0BEF04 51E0000E */  beql  $t7, $zero, .L7F0BEF40
/* 0F3A38 7F0BEF08 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F3A3C 7F0BEF0C 8C4E0424 */  lw    $t6, 0x424($v0)
/* 0F3A40 7F0BEF10 51C0000A */  beql  $t6, $zero, .L7F0BEF3C
/* 0F3A44 7F0BEF14 24A50001 */   addiu $a1, $a1, 1
/* 0F3A48 7F0BEF18 8C580428 */  lw    $t8, 0x428($v0)
/* 0F3A4C 7F0BEF1C 53000007 */  beql  $t8, $zero, .L7F0BEF3C
/* 0F3A50 7F0BEF20 24A50001 */   addiu $a1, $a1, 1
/* 0F3A54 7F0BEF24 C44803E4 */  lwc1  $f8, 0x3e4($v0)
/* 0F3A58 7F0BEF28 4608003E */  c.le.s $f0, $f8
/* 0F3A5C 7F0BEF2C 00000000 */  nop
/* 0F3A60 7F0BEF30 45020003 */  bc1fl .L7F0BEF40
/* 0F3A64 7F0BEF34 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F3A68 7F0BEF38 24A50001 */  addiu $a1, $a1, 1
.L7F0BEF3C:
/* 0F3A6C 7F0BEF3C AFA3001C */  sw    $v1, 0x1c($sp)
.L7F0BEF40:
/* 0F3A70 7F0BEF40 AFA40174 */  sw    $a0, 0x174($sp)
/* 0F3A74 7F0BEF44 AFA50170 */  sw    $a1, 0x170($sp)
/* 0F3A78 7F0BEF48 AFA6016C */  sw    $a2, 0x16c($sp)
/* 0F3A7C 7F0BEF4C 0FC30E36 */  jal   get_points_for_mp_player
/* 0F3A80 7F0BEF50 AFA70178 */   sw    $a3, 0x178($sp)
/* 0F3A84 7F0BEF54 3C198005 */  lui   $t9, %hi(g_MpPoint)
/* 0F3A88 7F0BEF58 8F39839C */  lw    $t9, %lo(g_MpPoint)($t9)
/* 0F3A8C 7F0BEF5C 44800000 */  mtc1  $zero, $f0
/* 0F3A90 7F0BEF60 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F3A94 7F0BEF64 0059082A */  slt   $at, $v0, $t9
/* 0F3A98 7F0BEF68 8FA40174 */  lw    $a0, 0x174($sp)
/* 0F3A9C 7F0BEF6C 8FA50170 */  lw    $a1, 0x170($sp)
/* 0F3AA0 7F0BEF70 8FA6016C */  lw    $a2, 0x16c($sp)
/* 0F3AA4 7F0BEF74 14200002 */  bnez  $at, .L7F0BEF80
/* 0F3AA8 7F0BEF78 8FA70178 */   lw    $a3, 0x178($sp)
/* 0F3AAC 7F0BEF7C 24C60001 */  addiu $a2, $a2, 1
.L7F0BEF80:
/* 0F3AB0 7F0BEF80 24840001 */  addiu $a0, $a0, 1
/* 0F3AB4 7F0BEF84 0087082A */  slt   $at, $a0, $a3
/* 0F3AB8 7F0BEF88 1420FFDC */  bnez  $at, .L7F0BEEFC
/* 0F3ABC 7F0BEF8C 24630004 */   addiu $v1, $v1, 4
.L7F0BEF90:
/* 0F3AC0 7F0BEF90 18C00009 */  blez  $a2, .L7F0BEFB8
/* 0F3AC4 7F0BEF94 00000000 */   nop
/* 0F3AC8 7F0BEF98 14A00005 */  bnez  $a1, .L7F0BEFB0
/* 0F3ACC 7F0BEF9C 00000000 */   nop
/* 0F3AD0 7F0BEFA0 0FC3094C */  jal   mpCalculateAwards
/* 0F3AD4 7F0BEFA4 00002025 */   move  $a0, $zero
/* 0F3AD8 7F0BEFA8 10000003 */  b     .L7F0BEFB8
/* 0F3ADC 7F0BEFAC 00000000 */   nop
.L7F0BEFB0:
/* 0F3AE0 7F0BEFB0 0FC30948 */  jal   mpwatchSetStopPlayFlag
/* 0F3AE4 7F0BEFB4 00000000 */   nop
.L7F0BEFB8:
/* 0F3AE8 7F0BEFB8 0FC051D6 */  jal   get_scenario
/* 0F3AEC 7F0BEFBC 00000000 */   nop
/* 0F3AF0 7F0BEFC0 24010001 */  li    $at, 1
/* 0F3AF4 7F0BEFC4 14410086 */  bne   $v0, $at, .L7F0BF1E0
/* 0F3AF8 7F0BEFC8 3C0F8005 */   lui   $t7, %hi(g_ClockTimer)
/* 0F3AFC 7F0BEFCC 8DEF8374 */  lw    $t7, %lo(g_ClockTimer)($t7)
/* 0F3B00 7F0BEFD0 11E00083 */  beqz  $t7, .L7F0BF1E0
/* 0F3B04 7F0BEFD4 00000000 */   nop
/* 0F3B08 7F0BEFD8 0FC26919 */  jal   getPlayerCount
/* 0F3B0C 7F0BEFDC 00000000 */   nop
/* 0F3B10 7F0BEFE0 44800000 */  mtc1  $zero, $f0
/* 0F3B14 7F0BEFE4 00405025 */  move  $t2, $v0
/* 0F3B18 7F0BEFE8 00006825 */  move  $t5, $zero
/* 0F3B1C 7F0BEFEC 0000F825 */  move  $ra, $zero
/* 0F3B20 7F0BEFF0 1840006E */  blez  $v0, .L7F0BF1AC
/* 0F3B24 7F0BEFF4 00006025 */   move  $t4, $zero
/* 0F3B28 7F0BEFF8 00002825 */  move  $a1, $zero
.L7F0BEFFC:
/* 0F3B2C 7F0BEFFC 00003025 */  move  $a2, $zero
/* 0F3B30 7F0BF000 18400048 */  blez  $v0, .L7F0BF124
/* 0F3B34 7F0BF004 00003825 */   move  $a3, $zero
/* 0F3B38 7F0BF008 30490003 */  andi  $t1, $v0, 3
/* 0F3B3C 7F0BF00C 11200019 */  beqz  $t1, .L7F0BF074
/* 0F3B40 7F0BF010 000C5880 */   sll   $t3, $t4, 2
/* 0F3B44 7F0BF014 3C188008 */  lui   $t8, %hi(g_playerPointers)
/* 0F3B48 7F0BF018 27189EE0 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x6120
/* 0F3B4C 7F0BF01C 00007080 */  sll   $t6, $zero, 2
/* 0F3B50 7F0BF020 0000C8C0 */  sll   $t9, $zero, 3
/* 0F3B54 7F0BF024 0320C823 */  subu  $t9, $t9, $zero
/* 0F3B58 7F0BF028 01D81821 */  addu  $v1, $t6, $t8
/* 0F3B5C 7F0BF02C 3C0E8008 */  lui   $t6, %hi(g_playerPlayerData)
/* 0F3B60 7F0BF030 0019C900 */  sll   $t9, $t9, 4
/* 0F3B64 7F0BF034 032B7821 */  addu  $t7, $t9, $t3
/* 0F3B68 7F0BF038 25CE9EF0 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x6110
/* 0F3B6C 7F0BF03C 01EE2021 */  addu  $a0, $t7, $t6
/* 0F3B70 7F0BF040 01204025 */  move  $t0, $t1
.L7F0BF044:
/* 0F3B74 7F0BF044 8C780000 */  lw    $t8, ($v1)
/* 0F3B78 7F0BF048 24E70001 */  addiu $a3, $a3, 1
/* 0F3B7C 7F0BF04C 24630004 */  addiu $v1, $v1, 4
/* 0F3B80 7F0BF050 8F1900D8 */  lw    $t9, 0xd8($t8)
/* 0F3B84 7F0BF054 57200003 */  bnezl $t9, .L7F0BF064
/* 0F3B88 7F0BF058 8C8F0024 */   lw    $t7, 0x24($a0)
/* 0F3B8C 7F0BF05C 24C60001 */  addiu $a2, $a2, 1
/* 0F3B90 7F0BF060 8C8F0024 */  lw    $t7, 0x24($a0)
.L7F0BF064:
/* 0F3B94 7F0BF064 24840070 */  addiu $a0, $a0, 0x70
/* 0F3B98 7F0BF068 1507FFF6 */  bne   $t0, $a3, .L7F0BF044
/* 0F3B9C 7F0BF06C 00AF2821 */   addu  $a1, $a1, $t7
/* 0F3BA0 7F0BF070 10E2002C */  beq   $a3, $v0, .L7F0BF124
.L7F0BF074:
/* 0F3BA4 7F0BF074 3C188008 */   lui   $t8, %hi(g_playerPointers)
/* 0F3BA8 7F0BF078 0007C8C0 */  sll   $t9, $a3, 3
/* 0F3BAC 7F0BF07C 0327C823 */  subu  $t9, $t9, $a3
/* 0F3BB0 7F0BF080 27189EE0 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x6120
/* 0F3BB4 7F0BF084 00077080 */  sll   $t6, $a3, 2
/* 0F3BB8 7F0BF088 01D81821 */  addu  $v1, $t6, $t8
/* 0F3BBC 7F0BF08C 0019C900 */  sll   $t9, $t9, 4
/* 0F3BC0 7F0BF090 032B7821 */  addu  $t7, $t9, $t3
/* 0F3BC4 7F0BF094 3C0E8008 */  lui   $t6, %hi(g_playerPlayerData)
/* 0F3BC8 7F0BF098 25CE9EF0 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x6110
/* 0F3BCC 7F0BF09C 000AC880 */  sll   $t9, $t2, 2
/* 0F3BD0 7F0BF0A0 03384021 */  addu  $t0, $t9, $t8
/* 0F3BD4 7F0BF0A4 01EE2021 */  addu  $a0, $t7, $t6
.L7F0BF0A8:
/* 0F3BD8 7F0BF0A8 8C6F0000 */  lw    $t7, ($v1)
/* 0F3BDC 7F0BF0AC 8DEE00D8 */  lw    $t6, 0xd8($t7)
/* 0F3BE0 7F0BF0B0 55C00003 */  bnezl $t6, .L7F0BF0C0
/* 0F3BE4 7F0BF0B4 8C780004 */   lw    $t8, 4($v1)
/* 0F3BE8 7F0BF0B8 24C60001 */  addiu $a2, $a2, 1
/* 0F3BEC 7F0BF0BC 8C780004 */  lw    $t8, 4($v1)
.L7F0BF0C0:
/* 0F3BF0 7F0BF0C0 8C990024 */  lw    $t9, 0x24($a0)
/* 0F3BF4 7F0BF0C4 8F0F00D8 */  lw    $t7, 0xd8($t8)
/* 0F3BF8 7F0BF0C8 00B92821 */  addu  $a1, $a1, $t9
/* 0F3BFC 7F0BF0CC 55E00003 */  bnezl $t7, .L7F0BF0DC
/* 0F3C00 7F0BF0D0 8C790008 */   lw    $t9, 8($v1)
/* 0F3C04 7F0BF0D4 24C60001 */  addiu $a2, $a2, 1
/* 0F3C08 7F0BF0D8 8C790008 */  lw    $t9, 8($v1)
.L7F0BF0DC:
/* 0F3C0C 7F0BF0DC 8C8E0094 */  lw    $t6, 0x94($a0)
/* 0F3C10 7F0BF0E0 8F3800D8 */  lw    $t8, 0xd8($t9)
/* 0F3C14 7F0BF0E4 00AE2821 */  addu  $a1, $a1, $t6
/* 0F3C18 7F0BF0E8 57000003 */  bnezl $t8, .L7F0BF0F8
/* 0F3C1C 7F0BF0EC 8C6E000C */   lw    $t6, 0xc($v1)
/* 0F3C20 7F0BF0F0 24C60001 */  addiu $a2, $a2, 1
/* 0F3C24 7F0BF0F4 8C6E000C */  lw    $t6, 0xc($v1)
.L7F0BF0F8:
/* 0F3C28 7F0BF0F8 8C8F0104 */  lw    $t7, 0x104($a0)
/* 0F3C2C 7F0BF0FC 24630010 */  addiu $v1, $v1, 0x10
/* 0F3C30 7F0BF100 8DD900D8 */  lw    $t9, 0xd8($t6)
/* 0F3C34 7F0BF104 00AF2821 */  addu  $a1, $a1, $t7
/* 0F3C38 7F0BF108 57200003 */  bnezl $t9, .L7F0BF118
/* 0F3C3C 7F0BF10C 8C980174 */   lw    $t8, 0x174($a0)
/* 0F3C40 7F0BF110 24C60001 */  addiu $a2, $a2, 1
/* 0F3C44 7F0BF114 8C980174 */  lw    $t8, 0x174($a0)
.L7F0BF118:
/* 0F3C48 7F0BF118 248401C0 */  addiu $a0, $a0, 0x1c0
/* 0F3C4C 7F0BF11C 1468FFE2 */  bne   $v1, $t0, .L7F0BF0A8
/* 0F3C50 7F0BF120 00B82821 */   addu  $a1, $a1, $t8
.L7F0BF124:
/* 0F3C54 7F0BF124 28A10002 */  slti  $at, $a1, 2
/* 0F3C58 7F0BF128 1420001C */  bnez  $at, .L7F0BF19C
/* 0F3C5C 7F0BF12C 000C78C0 */   sll   $t7, $t4, 3
/* 0F3C60 7F0BF130 01EC7823 */  subu  $t7, $t7, $t4
/* 0F3C64 7F0BF134 3C0E8008 */  lui   $t6, %hi(g_playerPlayerData)
/* 0F3C68 7F0BF138 25CE9EF0 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x6110
/* 0F3C6C 7F0BF13C 000F7900 */  sll   $t7, $t7, 4
/* 0F3C70 7F0BF140 01EE1821 */  addu  $v1, $t7, $t6
/* 0F3C74 7F0BF144 906F0068 */  lbu   $t7, 0x68($v1)
/* 0F3C78 7F0BF148 3C188008 */  lui   $t8, %hi(g_playerPointers)
/* 0F3C7C 7F0BF14C 27189EE0 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x6120
/* 0F3C80 7F0BF150 000CC880 */  sll   $t9, $t4, 2
/* 0F3C84 7F0BF154 15E00003 */  bnez  $t7, .L7F0BF164
/* 0F3C88 7F0BF158 03382021 */   addu  $a0, $t9, $t8
/* 0F3C8C 7F0BF15C 24CE0001 */  addiu $t6, $a2, 1
/* 0F3C90 7F0BF160 A06E0068 */  sb    $t6, 0x68($v1)
.L7F0BF164:
/* 0F3C94 7F0BF164 8C830000 */  lw    $v1, ($a0)
/* 0F3C98 7F0BF168 25AD0001 */  addiu $t5, $t5, 1
/* 0F3C9C 7F0BF16C 8C790424 */  lw    $t9, 0x424($v1)
/* 0F3CA0 7F0BF170 5320000B */  beql  $t9, $zero, .L7F0BF1A0
/* 0F3CA4 7F0BF174 258C0001 */   addiu $t4, $t4, 1
/* 0F3CA8 7F0BF178 8C780428 */  lw    $t8, 0x428($v1)
/* 0F3CAC 7F0BF17C 53000008 */  beql  $t8, $zero, .L7F0BF1A0
/* 0F3CB0 7F0BF180 258C0001 */   addiu $t4, $t4, 1
/* 0F3CB4 7F0BF184 C46A03E4 */  lwc1  $f10, 0x3e4($v1)
/* 0F3CB8 7F0BF188 4600503C */  c.lt.s $f10, $f0
/* 0F3CBC 7F0BF18C 00000000 */  nop
/* 0F3CC0 7F0BF190 45020003 */  bc1fl .L7F0BF1A0
/* 0F3CC4 7F0BF194 258C0001 */   addiu $t4, $t4, 1
/* 0F3CC8 7F0BF198 27FF0001 */  addiu $ra, $ra, 1
.L7F0BF19C:
/* 0F3CCC 7F0BF19C 258C0001 */  addiu $t4, $t4, 1
.L7F0BF1A0:
/* 0F3CD0 7F0BF1A0 018A082A */  slt   $at, $t4, $t2
/* 0F3CD4 7F0BF1A4 5420FF95 */  bnezl $at, .L7F0BEFFC
/* 0F3CD8 7F0BF1A8 00002825 */   move  $a1, $zero
.L7F0BF1AC:
/* 0F3CDC 7F0BF1AC 2443FFFF */  addiu $v1, $v0, -1
/* 0F3CE0 7F0BF1B0 03E3082A */  slt   $at, $ra, $v1
/* 0F3CE4 7F0BF1B4 54200006 */  bnezl $at, .L7F0BF1D0
/* 0F3CE8 7F0BF1B8 01A3082A */   slt   $at, $t5, $v1
/* 0F3CEC 7F0BF1BC 0FC3094C */  jal   mpCalculateAwards
/* 0F3CF0 7F0BF1C0 00002025 */   move  $a0, $zero
/* 0F3CF4 7F0BF1C4 10000006 */  b     .L7F0BF1E0
/* 0F3CF8 7F0BF1C8 00000000 */   nop
/* 0F3CFC 7F0BF1CC 01A3082A */  slt   $at, $t5, $v1
.L7F0BF1D0:
/* 0F3D00 7F0BF1D0 14200003 */  bnez  $at, .L7F0BF1E0
/* 0F3D04 7F0BF1D4 00000000 */   nop
/* 0F3D08 7F0BF1D8 0FC30948 */  jal   mpwatchSetStopPlayFlag
/* 0F3D0C 7F0BF1DC 00000000 */   nop
.L7F0BF1E0:
/* 0F3D10 7F0BF1E0 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0F3D14 7F0BF1E4 3C0F8005 */  lui   $t7, %hi(D_80048394)
/* 0F3D18 7F0BF1E8 8DEF8394 */  lw    $t7, %lo(D_80048394)($t7)
/* 0F3D1C 7F0BF1EC 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F3D20 7F0BF1F0 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0F3D24 7F0BF1F4 44810000 */  mtc1  $at, $f0
/* 0F3D28 7F0BF1F8 01E27021 */  addu  $t6, $t7, $v0
/* 0F3D2C 7F0BF1FC 448E8000 */  mtc1  $t6, $f16
/* 0F3D30 7F0BF200 3C018005 */  lui   $at, %hi(D_80048394)
/* 0F3D34 7F0BF204 AC2E8394 */  sw    $t6, %lo(D_80048394)($at)
/* 0F3D38 7F0BF208 468084A0 */  cvt.s.w $f18, $f16
/* 0F3D3C 7F0BF20C 3C038005 */  lui   $v1, %hi(D_800483A8)
/* 0F3D40 7F0BF210 3C018005 */  lui   $at, %hi(g_CurrentMultiPlayerSec)
/* 0F3D44 7F0BF214 246383A8 */  addiu $v1, %lo(D_800483A8) # addiu $v1, $v1, -0x7c58
/* 0F3D48 7F0BF218 00002025 */  move  $a0, $zero
/* 0F3D4C 7F0BF21C 3405FFFF */  li    $a1, 65535
/* 0F3D50 7F0BF220 46009103 */  div.s $f4, $f18, $f0
/* 0F3D54 7F0BF224 E42483A4 */  swc1  $f4, %lo(g_CurrentMultiPlayerSec)($at)
/* 0F3D58 7F0BF228 8C790000 */  lw    $t9, ($v1)
/* 0F3D5C 7F0BF22C 3C018005 */  lui   $at, %hi(g_CurrentMultiPlayerMin)
/* 0F3D60 7F0BF230 03227821 */  addu  $t7, $t9, $v0
/* 0F3D64 7F0BF234 448F3000 */  mtc1  $t7, $f6
/* 0F3D68 7F0BF238 AC6F0000 */  sw    $t7, ($v1)
/* 0F3D6C 7F0BF23C 46803220 */  cvt.s.w $f8, $f6
/* 0F3D70 7F0BF240 46004283 */  div.s $f10, $f8, $f0
/* 0F3D74 7F0BF244 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F3D78 7F0BF248 E42A83AC */   swc1  $f10, %lo(g_CurrentMultiPlayerMin)($at)
/* 0F3D7C 7F0BF24C 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0F3D80 7F0BF250 44810000 */  mtc1  $at, $f0
/* 0F3D84 7F0BF254 10400009 */  beqz  $v0, .L7F0BF27C
/* 0F3D88 7F0BF258 3C038005 */   lui   $v1, %hi(D_80048390)
/* 0F3D8C 7F0BF25C 3C038005 */  lui   $v1, %hi(D_80048390)
/* 0F3D90 7F0BF260 3C018005 */  lui   $at, %hi(D_80048388)
/* 0F3D94 7F0BF264 24638390 */  addiu $v1, %lo(D_80048390) # addiu $v1, $v1, -0x7c70
/* 0F3D98 7F0BF268 AC208388 */  sw    $zero, %lo(D_80048388)($at)
/* 0F3D9C 7F0BF26C AC600000 */  sw    $zero, ($v1)
/* 0F3DA0 7F0BF270 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0F3DA4 7F0BF274 1000000C */  b     .L7F0BF2A8
/* 0F3DA8 7F0BF278 8C428374 */   lw    $v0, %lo(g_ClockTimer)($v0)
.L7F0BF27C:
/* 0F3DAC 7F0BF27C 24638390 */  addiu $v1, $v1, %lo(D_80048390)
/* 0F3DB0 7F0BF280 3C028005 */  lui   $v0, %hi(g_ClockTimer)
/* 0F3DB4 7F0BF284 8C428374 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F3DB8 7F0BF288 8C6E0000 */  lw    $t6, ($v1)
/* 0F3DBC 7F0BF28C 240F0001 */  li    $t7, 1
/* 0F3DC0 7F0BF290 01C2C821 */  addu  $t9, $t6, $v0
/* 0F3DC4 7F0BF294 2B210708 */  slti  $at, $t9, 0x708
/* 0F3DC8 7F0BF298 14200003 */  bnez  $at, .L7F0BF2A8
/* 0F3DCC 7F0BF29C AC790000 */   sw    $t9, ($v1)
/* 0F3DD0 7F0BF2A0 3C018005 */  lui   $at, %hi(D_80048388)
/* 0F3DD4 7F0BF2A4 AC2F8388 */  sw    $t7, %lo(D_80048388)($at)
.L7F0BF2A8:
/* 0F3DD8 7F0BF2A8 3C0E8005 */  lui   $t6, %hi(D_80048388)
/* 0F3DDC 7F0BF2AC 8DCE8388 */  lw    $t6, %lo(D_80048388)($t6)
/* 0F3DE0 7F0BF2B0 3C038005 */  lui   $v1, %hi(D_8004838C)
/* 0F3DE4 7F0BF2B4 2463838C */  addiu $v1, %lo(D_8004838C) # addiu $v1, $v1, -0x7c74
/* 0F3DE8 7F0BF2B8 11C00005 */  beqz  $t6, .L7F0BF2D0
/* 0F3DEC 7F0BF2BC 00000000 */   nop
/* 0F3DF0 7F0BF2C0 8C790000 */  lw    $t9, ($v1)
/* 0F3DF4 7F0BF2C4 0322C021 */  addu  $t8, $t9, $v0
/* 0F3DF8 7F0BF2C8 10000015 */  b     .L7F0BF320
/* 0F3DFC 7F0BF2CC AC780000 */   sw    $t8, ($v1)
.L7F0BF2D0:
/* 0F3E00 7F0BF2D0 3C038005 */  lui   $v1, %hi(D_800483B0)
/* 0F3E04 7F0BF2D4 246383B0 */  addiu $v1, %lo(D_800483B0) # addiu $v1, $v1, -0x7c50
/* 0F3E08 7F0BF2D8 8C6F0000 */  lw    $t7, ($v1)
/* 0F3E0C 7F0BF2DC 3C048005 */  lui   $a0, %hi(D_800483B8)
/* 0F3E10 7F0BF2E0 3C018005 */  lui   $at, %hi(g_StageTimeSec)
/* 0F3E14 7F0BF2E4 01E2C821 */  addu  $t9, $t7, $v0
/* 0F3E18 7F0BF2E8 44998000 */  mtc1  $t9, $f16
/* 0F3E1C 7F0BF2EC AC790000 */  sw    $t9, ($v1)
/* 0F3E20 7F0BF2F0 248483B8 */  addiu $a0, %lo(D_800483B8) # addiu $a0, $a0, -0x7c48
/* 0F3E24 7F0BF2F4 468084A0 */  cvt.s.w $f18, $f16
/* 0F3E28 7F0BF2F8 46009103 */  div.s $f4, $f18, $f0
/* 0F3E2C 7F0BF2FC E42483B4 */  swc1  $f4, %lo(g_StageTimeSec)($at)
/* 0F3E30 7F0BF300 8C980000 */  lw    $t8, ($a0)
/* 0F3E34 7F0BF304 3C018005 */  lui   $at, %hi(g_PowerOnTimeSec)
/* 0F3E38 7F0BF308 03027021 */  addu  $t6, $t8, $v0
/* 0F3E3C 7F0BF30C 448E3000 */  mtc1  $t6, $f6
/* 0F3E40 7F0BF310 AC8E0000 */  sw    $t6, ($a0)
/* 0F3E44 7F0BF314 46803220 */  cvt.s.w $f8, $f6
/* 0F3E48 7F0BF318 46004283 */  div.s $f10, $f8, $f0
/* 0F3E4C 7F0BF31C E42A83BC */  swc1  $f10, %lo(g_PowerOnTimeSec)($at)
.L7F0BF320:
/* 0F3E50 7F0BF320 0C00114D */  jal   viSetUseZBuf
/* 0F3E54 7F0BF324 24040001 */   li    $a0, 1
/* 0F3E58 7F0BF328 3C198005 */  lui   $t9, %hi(g_CurrentStageToLoad)
/* 0F3E5C 7F0BF32C 8F398364 */  lw    $t9, %lo(g_CurrentStageToLoad)($t9)
/* 0F3E60 7F0BF330 2401005A */  li    $at, 90
/* 0F3E64 7F0BF334 17210009 */  bne   $t9, $at, .L7F0BF35C
/* 0F3E68 7F0BF338 00000000 */   nop
/* 0F3E6C 7F0BF33C 0FC2464F */  jal   cheat_buttons_mp_related
/* 0F3E70 7F0BF340 00000000 */   nop
/* 0F3E74 7F0BF344 0FC06987 */  jal   menu_init
/* 0F3E78 7F0BF348 00000000 */   nop
/* 0F3E7C 7F0BF34C 0FC30650 */  jal   something_with_LnameJ
/* 0F3E80 7F0BF350 00000000 */   nop
/* 0F3E84 7F0BF354 100000A9 */  b     .L7F0BF5FC
/* 0F3E88 7F0BF358 00000000 */   nop
.L7F0BF35C:
/* 0F3E8C 7F0BF35C 0FC26EEF */  jal   sub_GAME_7F09BBBC
/* 0F3E90 7F0BF360 00000000 */   nop
/* 0F3E94 7F0BF364 0FC2FA34 */  jal   lvlSetMultipliersForDifficulty
/* 0F3E98 7F0BF368 00000000 */   nop
/* 0F3E9C 7F0BF36C 0FC2F1F5 */  jal   sub_GAME_7F0BC7D4
/* 0F3EA0 7F0BF370 00000000 */   nop
/* 0F3EA4 7F0BF374 0FC24B94 */  jal   sub_GAME_7F092E50
/* 0F3EA8 7F0BF378 00000000 */   nop
/* 0F3EAC 7F0BF37C 0FC2510E */  jal   sub_GAME_7F094438
/* 0F3EB0 7F0BF380 00000000 */   nop
/* 0F3EB4 7F0BF384 0FC291FF */  jal   update_bullet_sparks_and_dust_clouds
/* 0F3EB8 7F0BF388 00000000 */   nop
/* 0F3EBC 7F0BF38C 0FC1A39B */  jal   sub_GAME_7F068E6C
/* 0F3EC0 7F0BF390 00000000 */   nop
/* 0F3EC4 7F0BF394 0FC28A35 */  jal   update_broken_windows
/* 0F3EC8 7F0BF398 00000000 */   nop
/* 0F3ECC 7F0BF39C 0FC27F4F */  jal   update_gray_flying_particles
/* 0F3ED0 7F0BF3A0 00000000 */   nop
/* 0F3ED4 7F0BF3A4 0FC0F192 */  jal   handle_mp_respawn_and_some_things
/* 0F3ED8 7F0BF3A8 00000000 */   nop
/* 0F3EDC 7F0BF3AC 0FC304F2 */  jal   reset_all_music_slots
/* 0F3EE0 7F0BF3B0 00000000 */   nop
/* 0F3EE4 7F0BF3B4 0FC30650 */  jal   something_with_LnameJ
/* 0F3EE8 7F0BF3B8 00000000 */   nop
/* 0F3EEC 7F0BF3BC 0FC243EE */  jal   get_debug_joy2detailedit_flag
/* 0F3EF0 7F0BF3C0 00000000 */   nop
/* 0F3EF4 7F0BF3C4 1040004D */  beqz  $v0, .L7F0BF4FC
/* 0F3EF8 7F0BF3C8 3C068005 */   lui   $a2, %hi(D_800483C8)
/* 0F3EFC 7F0BF3CC 24C683C8 */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c38
/* 0F3F00 7F0BF3D0 8CD80000 */  lw    $t8, ($a2)
/* 0F3F04 7F0BF3D4 24043000 */  li    $a0, 12288
/* 0F3F08 7F0BF3D8 17000048 */  bnez  $t8, .L7F0BF4FC
/* 0F3F0C 7F0BF3DC 00000000 */   nop
/* 0F3F10 7F0BF3E0 0C0025C8 */  jal   mempAllocBytesInBank
/* 0F3F14 7F0BF3E4 24050004 */   li    $a1, 4
/* 0F3F18 7F0BF3E8 3C068005 */  lui   $a2, %hi(D_800483C8)
/* 0F3F1C 7F0BF3EC 24C683C8 */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c38
/* 0F3F20 7F0BF3F0 10400042 */  beqz  $v0, .L7F0BF4FC
/* 0F3F24 7F0BF3F4 ACC20000 */   sw    $v0, ($a2)
/* 0F3F28 7F0BF3F8 00001825 */  move  $v1, $zero
/* 0F3F2C 7F0BF3FC 24052EE0 */  li    $a1, 12000
/* 0F3F30 7F0BF400 240400FF */  li    $a0, 255
.L7F0BF404:
/* 0F3F34 7F0BF404 8CCE0000 */  lw    $t6, ($a2)
/* 0F3F38 7F0BF408 01C3C821 */  addu  $t9, $t6, $v1
/* 0F3F3C 7F0BF40C A3240000 */  sb    $a0, ($t9)
/* 0F3F40 7F0BF410 8CD80000 */  lw    $t8, ($a2)
/* 0F3F44 7F0BF414 03031021 */  addu  $v0, $t8, $v1
/* 0F3F48 7F0BF418 904F0001 */  lbu   $t7, 1($v0)
/* 0F3F4C 7F0BF41C 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F3F50 7F0BF420 35D90020 */  ori   $t9, $t6, 0x20
/* 0F3F54 7F0BF424 A0590001 */  sb    $t9, 1($v0)
/* 0F3F58 7F0BF428 8CD80000 */  lw    $t8, ($a2)
/* 0F3F5C 7F0BF42C 03031021 */  addu  $v0, $t8, $v1
/* 0F3F60 7F0BF430 904F0001 */  lbu   $t7, 1($v0)
/* 0F3F64 7F0BF434 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F3F68 7F0BF438 35D90004 */  ori   $t9, $t6, 4
/* 0F3F6C 7F0BF43C A0590001 */  sb    $t9, 1($v0)
/* 0F3F70 7F0BF440 8CD80000 */  lw    $t8, ($a2)
/* 0F3F74 7F0BF444 03037821 */  addu  $t7, $t8, $v1
/* 0F3F78 7F0BF448 A1E40004 */  sb    $a0, 4($t7)
/* 0F3F7C 7F0BF44C 8CCE0000 */  lw    $t6, ($a2)
/* 0F3F80 7F0BF450 01C31021 */  addu  $v0, $t6, $v1
/* 0F3F84 7F0BF454 90590005 */  lbu   $t9, 5($v0)
/* 0F3F88 7F0BF458 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F3F8C 7F0BF45C 370F0020 */  ori   $t7, $t8, 0x20
/* 0F3F90 7F0BF460 A04F0005 */  sb    $t7, 5($v0)
/* 0F3F94 7F0BF464 8CCE0000 */  lw    $t6, ($a2)
/* 0F3F98 7F0BF468 01C31021 */  addu  $v0, $t6, $v1
/* 0F3F9C 7F0BF46C 90590005 */  lbu   $t9, 5($v0)
/* 0F3FA0 7F0BF470 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F3FA4 7F0BF474 370F0004 */  ori   $t7, $t8, 4
/* 0F3FA8 7F0BF478 A04F0005 */  sb    $t7, 5($v0)
/* 0F3FAC 7F0BF47C 8CCE0000 */  lw    $t6, ($a2)
/* 0F3FB0 7F0BF480 01C3C821 */  addu  $t9, $t6, $v1
/* 0F3FB4 7F0BF484 A3240008 */  sb    $a0, 8($t9)
/* 0F3FB8 7F0BF488 8CD80000 */  lw    $t8, ($a2)
/* 0F3FBC 7F0BF48C 03031021 */  addu  $v0, $t8, $v1
/* 0F3FC0 7F0BF490 904F0009 */  lbu   $t7, 9($v0)
/* 0F3FC4 7F0BF494 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F3FC8 7F0BF498 35D90020 */  ori   $t9, $t6, 0x20
/* 0F3FCC 7F0BF49C A0590009 */  sb    $t9, 9($v0)
/* 0F3FD0 7F0BF4A0 8CD80000 */  lw    $t8, ($a2)
/* 0F3FD4 7F0BF4A4 03031021 */  addu  $v0, $t8, $v1
/* 0F3FD8 7F0BF4A8 904F0009 */  lbu   $t7, 9($v0)
/* 0F3FDC 7F0BF4AC 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F3FE0 7F0BF4B0 35D90004 */  ori   $t9, $t6, 4
/* 0F3FE4 7F0BF4B4 A0590009 */  sb    $t9, 9($v0)
/* 0F3FE8 7F0BF4B8 8CD80000 */  lw    $t8, ($a2)
/* 0F3FEC 7F0BF4BC 03037821 */  addu  $t7, $t8, $v1
/* 0F3FF0 7F0BF4C0 A1E4000C */  sb    $a0, 0xc($t7)
/* 0F3FF4 7F0BF4C4 8CCE0000 */  lw    $t6, ($a2)
/* 0F3FF8 7F0BF4C8 01C31021 */  addu  $v0, $t6, $v1
/* 0F3FFC 7F0BF4CC 9059000D */  lbu   $t9, 0xd($v0)
/* 0F4000 7F0BF4D0 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F4004 7F0BF4D4 370F0020 */  ori   $t7, $t8, 0x20
/* 0F4008 7F0BF4D8 A04F000D */  sb    $t7, 0xd($v0)
/* 0F400C 7F0BF4DC 8CCE0000 */  lw    $t6, ($a2)
/* 0F4010 7F0BF4E0 01C31021 */  addu  $v0, $t6, $v1
/* 0F4014 7F0BF4E4 9059000D */  lbu   $t9, 0xd($v0)
/* 0F4018 7F0BF4E8 24630010 */  addiu $v1, $v1, 0x10
/* 0F401C 7F0BF4EC 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F4020 7F0BF4F0 370F0004 */  ori   $t7, $t8, 4
/* 0F4024 7F0BF4F4 1465FFC3 */  bne   $v1, $a1, .L7F0BF404
/* 0F4028 7F0BF4F8 A04F000D */   sb    $t7, 0xd($v0)
.L7F0BF4FC:
/* 0F402C 7F0BF4FC 0FC2440F */  jal   get_debug_portal_flag
/* 0F4030 7F0BF500 00000000 */   nop
/* 0F4034 7F0BF504 10400003 */  beqz  $v0, .L7F0BF514
/* 0F4038 7F0BF508 00000000 */   nop
/* 0F403C 7F0BF50C 0FC2F7C4 */  jal   lvlPortalDebug7F0BDF10
/* 0F4040 7F0BF510 00002025 */   move  $a0, $zero
.L7F0BF514:
/* 0F4044 7F0BF514 0FC243C5 */  jal   getDebugMode
/* 0F4048 7F0BF518 00000000 */   nop
/* 0F404C 7F0BF51C 24010004 */  li    $at, 4
/* 0F4050 7F0BF520 10410006 */  beq   $v0, $at, .L7F0BF53C
/* 0F4054 7F0BF524 00002025 */   move  $a0, $zero
/* 0F4058 7F0BF528 24010008 */  li    $at, 8
/* 0F405C 7F0BF52C 1041001A */  beq   $v0, $at, .L7F0BF598
/* 0F4060 7F0BF530 00002025 */   move  $a0, $zero
/* 0F4064 7F0BF534 10000031 */  b     .L7F0BF5FC
/* 0F4068 7F0BF538 00000000 */   nop
.L7F0BF53C:
/* 0F406C 7F0BF53C 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F4070 7F0BF540 24050002 */   li    $a1, 2
/* 0F4074 7F0BF544 50400008 */  beql  $v0, $zero, .L7F0BF568
/* 0F4078 7F0BF548 00002025 */   move  $a0, $zero
/* 0F407C 7F0BF54C 0FC2BD8C */  jal   sub_GAME_7F0AF630
/* 0F4080 7F0BF550 2404FFFF */   li    $a0, -1
/* 0F4084 7F0BF554 00002025 */  move  $a0, $zero
/* 0F4088 7F0BF558 00002825 */  move  $a1, $zero
/* 0F408C 7F0BF55C 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F4090 7F0BF560 00003025 */   move  $a2, $zero
/* 0F4094 7F0BF564 00002025 */  move  $a0, $zero
.L7F0BF568:
/* 0F4098 7F0BF568 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F409C 7F0BF56C 24050001 */   li    $a1, 1
/* 0F40A0 7F0BF570 10400022 */  beqz  $v0, .L7F0BF5FC
/* 0F40A4 7F0BF574 00000000 */   nop
/* 0F40A8 7F0BF578 0FC2BD8C */  jal   sub_GAME_7F0AF630
/* 0F40AC 7F0BF57C 24040001 */   li    $a0, 1
/* 0F40B0 7F0BF580 00002025 */  move  $a0, $zero
/* 0F40B4 7F0BF584 00002825 */  move  $a1, $zero
/* 0F40B8 7F0BF588 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F40BC 7F0BF58C 00003025 */   move  $a2, $zero
/* 0F40C0 7F0BF590 1000001A */  b     .L7F0BF5FC
/* 0F40C4 7F0BF594 00000000 */   nop
.L7F0BF598:
/* 0F40C8 7F0BF598 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F40CC 7F0BF59C 24050002 */   li    $a1, 2
/* 0F40D0 7F0BF5A0 50400004 */  beql  $v0, $zero, .L7F0BF5B4
/* 0F40D4 7F0BF5A4 00002025 */   move  $a0, $zero
/* 0F40D8 7F0BF5A8 0FC08B8C */  jal   chrDecrementAnimationTablePointerCount
/* 0F40DC 7F0BF5AC 00000000 */   nop
/* 0F40E0 7F0BF5B0 00002025 */  move  $a0, $zero
.L7F0BF5B4:
/* 0F40E4 7F0BF5B4 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F40E8 7F0BF5B8 24050001 */   li    $a1, 1
/* 0F40EC 7F0BF5BC 50400004 */  beql  $v0, $zero, .L7F0BF5D0
/* 0F40F0 7F0BF5C0 00002025 */   move  $a0, $zero
/* 0F40F4 7F0BF5C4 0FC08BA4 */  jal   chrIncrementAnimationTablePointerCount
/* 0F40F8 7F0BF5C8 00000000 */   nop
/* 0F40FC 7F0BF5CC 00002025 */  move  $a0, $zero
.L7F0BF5D0:
/* 0F4100 7F0BF5D0 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F4104 7F0BF5D4 24050020 */   li    $a1, 32
/* 0F4108 7F0BF5D8 50400004 */  beql  $v0, $zero, .L7F0BF5EC
/* 0F410C 7F0BF5DC 00002025 */   move  $a0, $zero
/* 0F4110 7F0BF5E0 0FC08BB2 */  jal   chrToggleD_8002C90C
/* 0F4114 7F0BF5E4 00000000 */   nop
/* 0F4118 7F0BF5E8 00002025 */  move  $a0, $zero
.L7F0BF5EC:
/* 0F411C 7F0BF5EC 0C0030C3 */  jal   joyGetButtons
/* 0F4120 7F0BF5F0 24050010 */   li    $a1, 16
/* 0F4124 7F0BF5F4 0FC08BB8 */  jal   sub_GAME_7F022EE0
/* 0F4128 7F0BF5F8 0002202B */   sltu  $a0, $zero, $v0
.L7F0BF5FC:
/* 0F412C 7F0BF5FC 0FC243C5 */  jal   getDebugMode
/* 0F4130 7F0BF600 00000000 */   nop
/* 0F4134 7F0BF604 2401000C */  li    $at, 12
/* 0F4138 7F0BF608 1041002E */  beq   $v0, $at, .L7F0BF6C4
/* 0F413C 7F0BF60C 00002025 */   move  $a0, $zero
/* 0F4140 7F0BF610 2401000D */  li    $at, 13
/* 0F4144 7F0BF614 10410048 */  beq   $v0, $at, .L7F0BF738
/* 0F4148 7F0BF618 00002025 */   move  $a0, $zero
/* 0F414C 7F0BF61C 24010038 */  li    $at, 56
/* 0F4150 7F0BF620 54410074 */  bnel  $v0, $at, .L7F0BF7F4
/* 0F4154 7F0BF624 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4158 7F0BF628 0C0010EA */  jal   viGetHorizontalOffset
/* 0F415C 7F0BF62C 00000000 */   nop
/* 0F4160 7F0BF630 0C0010E4 */  jal   viGet800232A0
/* 0F4164 7F0BF634 AFA20030 */   sw    $v0, 0x30($sp)
/* 0F4168 7F0BF638 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0F416C 7F0BF63C 00002025 */  move  $a0, $zero
/* 0F4170 7F0BF640 0C0030C3 */  jal   joyGetButtons
/* 0F4174 7F0BF644 24050004 */   li    $a1, 4
/* 0F4178 7F0BF648 10400004 */  beqz  $v0, .L7F0BF65C
/* 0F417C 7F0BF64C 00002025 */   move  $a0, $zero
/* 0F4180 7F0BF650 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0F4184 7F0BF654 25D90001 */  addiu $t9, $t6, 1
/* 0F4188 7F0BF658 AFB9002C */  sw    $t9, 0x2c($sp)
.L7F0BF65C:
/* 0F418C 7F0BF65C 0C0030C3 */  jal   joyGetButtons
/* 0F4190 7F0BF660 24050008 */   li    $a1, 8
/* 0F4194 7F0BF664 10400004 */  beqz  $v0, .L7F0BF678
/* 0F4198 7F0BF668 00002025 */   move  $a0, $zero
/* 0F419C 7F0BF66C 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0F41A0 7F0BF670 270FFFFF */  addiu $t7, $t8, -1
/* 0F41A4 7F0BF674 AFAF002C */  sw    $t7, 0x2c($sp)
.L7F0BF678:
/* 0F41A8 7F0BF678 0C0030C3 */  jal   joyGetButtons
/* 0F41AC 7F0BF67C 24050001 */   li    $a1, 1
/* 0F41B0 7F0BF680 10400004 */  beqz  $v0, .L7F0BF694
/* 0F41B4 7F0BF684 00002025 */   move  $a0, $zero
/* 0F41B8 7F0BF688 8FAE0030 */  lw    $t6, 0x30($sp)
/* 0F41BC 7F0BF68C 25D90001 */  addiu $t9, $t6, 1
/* 0F41C0 7F0BF690 AFB90030 */  sw    $t9, 0x30($sp)
.L7F0BF694:
/* 0F41C4 7F0BF694 0C0030C3 */  jal   joyGetButtons
/* 0F41C8 7F0BF698 24050002 */   li    $a1, 2
/* 0F41CC 7F0BF69C 10400003 */  beqz  $v0, .L7F0BF6AC
/* 0F41D0 7F0BF6A0 8FB80030 */   lw    $t8, 0x30($sp)
/* 0F41D4 7F0BF6A4 270FFFFF */  addiu $t7, $t8, -1
/* 0F41D8 7F0BF6A8 AFAF0030 */  sw    $t7, 0x30($sp)
.L7F0BF6AC:
/* 0F41DC 7F0BF6AC 0C0010E7 */  jal   viSetHorizontalOffset
/* 0F41E0 7F0BF6B0 8FA40030 */   lw    $a0, 0x30($sp)
/* 0F41E4 7F0BF6B4 0C0010E1 */  jal   viSet800232A0
/* 0F41E8 7F0BF6B8 8FA4002C */   lw    $a0, 0x2c($sp)
/* 0F41EC 7F0BF6BC 1000004D */  b     .L7F0BF7F4
/* 0F41F0 7F0BF6C0 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BF6C4:
/* 0F41F4 7F0BF6C4 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F41F8 7F0BF6C8 24050202 */   li    $a1, 514
/* 0F41FC 7F0BF6CC 50400004 */  beql  $v0, $zero, .L7F0BF6E0
/* 0F4200 7F0BF6D0 00002025 */   move  $a0, $zero
/* 0F4204 7F0BF6D4 0FC2F68E */  jal   lvlMusicAppendPlayEndTheme
/* 0F4208 7F0BF6D8 00000000 */   nop
/* 0F420C 7F0BF6DC 00002025 */  move  $a0, $zero
.L7F0BF6E0:
/* 0F4210 7F0BF6E0 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F4214 7F0BF6E4 24050101 */   li    $a1, 257
/* 0F4218 7F0BF6E8 50400004 */  beql  $v0, $zero, .L7F0BF6FC
/* 0F421C 7F0BF6EC 00002025 */   move  $a0, $zero
/* 0F4220 7F0BF6F0 0FC2F67B */  jal   lvlMusicAppendPlaySoloDeathShort
/* 0F4224 7F0BF6F4 00000000 */   nop
/* 0F4228 7F0BF6F8 00002025 */  move  $a0, $zero
.L7F0BF6FC:
/* 0F422C 7F0BF6FC 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F4230 7F0BF700 24050400 */   li    $a1, 1024
/* 0F4234 7F0BF704 50400004 */  beql  $v0, $zero, .L7F0BF718
/* 0F4238 7F0BF708 00002025 */   move  $a0, $zero
/* 0F423C 7F0BF70C 0C001BF4 */  jal   musicTrack1Stop
/* 0F4240 7F0BF710 00000000 */   nop
/* 0F4244 7F0BF714 00002025 */  move  $a0, $zero
.L7F0BF718:
/* 0F4248 7F0BF718 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F424C 7F0BF71C 24054000 */   li    $a1, 16384
/* 0F4250 7F0BF720 50400034 */  beql  $v0, $zero, .L7F0BF7F4
/* 0F4254 7F0BF724 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4258 7F0BF728 0C001C28 */  jal   musicTrack1SaveCurrentVolumeAsTrackDefault
/* 0F425C 7F0BF72C 00000000 */   nop
/* 0F4260 7F0BF730 10000030 */  b     .L7F0BF7F4
/* 0F4264 7F0BF734 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BF738:
/* 0F4268 7F0BF738 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F426C 7F0BF73C 24050622 */   li    $a1, 1570
/* 0F4270 7F0BF740 1040000B */  beqz  $v0, .L7F0BF770
/* 0F4274 7F0BF744 3C058005 */   lui   $a1, 0x8005
/* 0F4278 7F0BF748 84A583E4 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F427C 7F0BF74C 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0F4280 7F0BF750 3C018005 */  lui   $at, %hi(g_DebugMpGameSoundFxIndex)
/* 0F4284 7F0BF754 24A5FFFF */  addiu $a1, $a1, -1
/* 0F4288 7F0BF758 00057400 */  sll   $t6, $a1, 0x10
/* 0F428C 7F0BF75C 000E2C03 */  sra   $a1, $t6, 0x10
/* 0F4290 7F0BF760 A42583E4 */  sh    $a1, %lo(g_DebugMpGameSoundFxIndex)($at)
/* 0F4294 7F0BF764 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F4298 7F0BF768 0C002382 */  jal   sndPlaySfx
/* 0F429C 7F0BF76C 00003025 */   move  $a2, $zero
.L7F0BF770:
/* 0F42A0 7F0BF770 00002025 */  move  $a0, $zero
/* 0F42A4 7F0BF774 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F42A8 7F0BF778 24050911 */   li    $a1, 2321
/* 0F42AC 7F0BF77C 1040000B */  beqz  $v0, .L7F0BF7AC
/* 0F42B0 7F0BF780 3C058005 */   lui   $a1, 0x8005
/* 0F42B4 7F0BF784 84A583E4 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F42B8 7F0BF788 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0F42BC 7F0BF78C 3C018005 */  lui   $at, %hi(g_DebugMpGameSoundFxIndex)
/* 0F42C0 7F0BF790 24A50001 */   addiu $a1, $a1, 1
/* 0F42C4 7F0BF794 0005C400 */  sll   $t8, $a1, 0x10
/* 0F42C8 7F0BF798 00182C03 */  sra   $a1, $t8, 0x10
/* 0F42CC 7F0BF79C A42583E4 */  sh    $a1, %lo(g_DebugMpGameSoundFxIndex)($at)
/* 0F42D0 7F0BF7A0 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F42D4 7F0BF7A4 0C002382 */  jal   sndPlaySfx
/* 0F42D8 7F0BF7A8 00003025 */   move  $a2, $zero
.L7F0BF7AC:
/* 0F42DC 7F0BF7AC 00002025 */  move  $a0, $zero
/* 0F42E0 7F0BF7B0 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F42E4 7F0BF7B4 24050004 */   li    $a1, 4
/* 0F42E8 7F0BF7B8 50400004 */  beql  $v0, $zero, .L7F0BF7CC
/* 0F42EC 7F0BF7BC 00002025 */   move  $a0, $zero
/* 0F42F0 7F0BF7C0 0C002449 */  jal   sndDeactivateAllSfxByFlag_1
/* 0F42F4 7F0BF7C4 00000000 */   nop
/* 0F42F8 7F0BF7C8 00002025 */  move  $a0, $zero
.L7F0BF7CC:
/* 0F42FC 7F0BF7CC 0C0030EB */  jal   joyGetButtonsPressedThisFrame
/* 0F4300 7F0BF7D0 24050008 */   li    $a1, 8
/* 0F4304 7F0BF7D4 10400006 */  beqz  $v0, .L7F0BF7F0
/* 0F4308 7F0BF7D8 3C058005 */   lui   $a1, %hi(g_DebugMpGameSoundFxIndex)
/* 0F430C 7F0BF7DC 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr)
/* 0F4310 7F0BF7E0 8C843720 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F4314 7F0BF7E4 84A583E4 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F4318 7F0BF7E8 0C002382 */  jal   sndPlaySfx
/* 0F431C 7F0BF7EC 00003025 */   move  $a2, $zero
.L7F0BF7F0:
/* 0F4320 7F0BF7F0 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BF7F4:
/* 0F4324 7F0BF7F4 27BD0198 */  addiu $sp, $sp, 0x198
/* 0F4328 7F0BF7F8 03E00008 */  jr    $ra
/* 0F432C 7F0BF7FC 00000000 */   nop
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.rdata
#const char aSetdetailDDDDDDDDD[] = "setdetail %d %d %d %d %d %d %d %d %d";
glabel aSetdetailDDDDDDDDD
.word 0x73657464
.word 0x65746169
.word 0x6c202564
.word 0x20256420
.word 0x25642025
.word 0x64202564
.word 0x20256420
.word 0x25642025
.word 0x64202564
.word 0x00000000
.text
glabel lvlManageMpGame
/* 0F431C 7F0BF7AC 27BDFE68 */  addiu $sp, $sp, -0x198
/* 0F4320 7F0BF7B0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F4324 7F0BF7B4 0C000626 */  jal   tlbmanageResetCurrentEntriesCount
/* 0F4328 7F0BF7B8 00000000 */   nop
/* 0F432C 7F0BF7BC 3C0E8005 */  lui   $t6, %hi(g_ControlsLockedFlag) # $t6, 0x8005
/* 0F4330 7F0BF7C0 8DCE83A0 */  lw    $t6, %lo(g_ControlsLockedFlag)($t6)
/* 0F4334 7F0BF7C4 3C018005 */  lui   $at, %hi(g_ClockTimer) # $at, 0x8005
/* 0F4338 7F0BF7C8 11C00003 */  beqz  $t6, .Ljp7F0BF7D8
/* 0F433C 7F0BF7CC 00000000 */   nop
/* 0F4340 7F0BF7D0 10000010 */  b     .Ljp7F0BF814
/* 0F4344 7F0BF7D4 AC2083A4 */   sw    $zero, %lo(g_ClockTimer)($at)
.Ljp7F0BF7D8:
/* 0F4348 7F0BF7D8 0FC31B59 */  jal   checkGamePaused
/* 0F434C 7F0BF7DC 00000000 */   nop
/* 0F4350 7F0BF7E0 10400004 */  beqz  $v0, .Ljp7F0BF7F4
/* 0F4354 7F0BF7E4 3C0F8005 */   lui   $t7, %hi(speedgraphframes) # $t7, 0x8005
/* 0F4358 7F0BF7E8 3C018005 */  lui   $at, %hi(g_ClockTimer) # $at, 0x8005
/* 0F435C 7F0BF7EC 10000009 */  b     .Ljp7F0BF814
/* 0F4360 7F0BF7F0 AC2083A4 */   sw    $zero, %lo(g_ClockTimer)($at)
.Ljp7F0BF7F4:
/* 0F4364 7F0BF7F4 8DEF84C8 */  lw    $t7, %lo(speedgraphframes)($t7)
/* 0F4368 7F0BF7F8 3C028005 */  lui   $v0, %hi(D_80048380) # $v0, 0x8005
/* 0F436C 7F0BF7FC 3C018005 */  lui   $at, %hi(g_ClockTimer) # $at, 0x8005
/* 0F4370 7F0BF800 244283B0 */  addiu $v0, %lo(D_80048380) # addiu $v0, $v0, -0x7c50
/* 0F4374 7F0BF804 AC2F83A4 */  sw    $t7, %lo(g_ClockTimer)($at)
/* 0F4378 7F0BF808 8C580000 */  lw    $t8, ($v0)
/* 0F437C 7F0BF80C 27190001 */  addiu $t9, $t8, 1
/* 0F4380 7F0BF810 AC590000 */  sw    $t9, ($v0)
.Ljp7F0BF814:
/* 0F4384 7F0BF814 3C028005 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8005
/* 0F4388 7F0BF818 8C4283A4 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F438C 7F0BF81C 3C038005 */  lui   $v1, %hi(g_JP_GlobalTimerDelta) # $v1, 0x8005
/* 0F4390 7F0BF820 246383A8 */  addiu $v1, %lo(g_JP_GlobalTimerDelta) # addiu $v1, $v1, -0x7c58
/* 0F4394 7F0BF824 44822000 */  mtc1  $v0, $f4
/* 0F4398 7F0BF828 3C048005 */  lui   $a0, %hi(g_GlobalTimer) # $a0, 0x8005
/* 0F439C 7F0BF82C 3C018005 */  lui   $at, %hi(g_GlobalTimerDelta) # $at, 0x8005
/* 0F43A0 7F0BF830 468021A0 */  cvt.s.w $f6, $f4
/* 0F43A4 7F0BF834 248483AC */  addiu $a0, %lo(g_GlobalTimer) # addiu $a0, $a0, -0x7c54
/* 0F43A8 7F0BF838 3C188005 */  lui   $t8, %hi(g_CurrentStageToLoad) # $t8, 0x8005
/* 0F43AC 7F0BF83C 3C198005 */  lui   $t9, %hi(D_80048394) # $t9, 0x8005
/* 0F43B0 7F0BF840 E4660000 */  swc1  $f6, ($v1)
/* 0F43B4 7F0BF844 C4680000 */  lwc1  $f8, ($v1)
/* 0F43B8 7F0BF848 E42883B4 */  swc1  $f8, %lo(g_GlobalTimerDelta)($at)
/* 0F43BC 7F0BF84C 8C8E0000 */  lw    $t6, ($a0)
/* 0F43C0 7F0BF850 2401005A */  li    $at, 90
/* 0F43C4 7F0BF854 01C27821 */  addu  $t7, $t6, $v0
/* 0F43C8 7F0BF858 AC8F0000 */  sw    $t7, ($a0)
/* 0F43CC 7F0BF85C 8F188394 */  lw    $t8, %lo(g_CurrentStageToLoad)($t8)
/* 0F43D0 7F0BF860 1301001D */  beq   $t8, $at, .Ljp7F0BF8D8
/* 0F43D4 7F0BF864 00000000 */   nop
/* 0F43D8 7F0BF868 8F3983C8 */  lw    $t9, %lo(D_80048394)($t9)
/* 0F43DC 7F0BF86C 1720001A */  bnez  $t9, .Ljp7F0BF8D8
/* 0F43E0 7F0BF870 00000000 */   nop
/* 0F43E4 7F0BF874 18400018 */  blez  $v0, .Ljp7F0BF8D8
/* 0F43E8 7F0BF878 3C0E8003 */   lui   $t6, %hi(g_AppendCheatSinglePlayer) # $t6, 0x8003
/* 0F43EC 7F0BF87C 8DCEA940 */  lw    $t6, %lo(g_AppendCheatSinglePlayer)($t6)
/* 0F43F0 7F0BF880 3C038007 */  lui   $v1, %hi(g_CheatActivated + 1) # $v1, 0x8007
/* 0F43F4 7F0BF884 246396E1 */  addiu $v1, %lo(g_CheatActivated + 1) # addiu $v1, $v1, -0x691f
/* 0F43F8 7F0BF888 11C00013 */  beqz  $t6, .Ljp7F0BF8D8
/* 0F43FC 7F0BF88C 24040001 */   li    $a0, 1
.Ljp7F0BF890:
/* 0F4400 7F0BF890 906F0000 */  lbu   $t7, ($v1)
/* 0F4404 7F0BF894 51E0000D */  beql  $t7, $zero, .Ljp7F0BF8CC
/* 0F4408 7F0BF898 24840001 */   addiu $a0, $a0, 1
/* 0F440C 7F0BF89C AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F4410 7F0BF8A0 0FC2494F */  jal   cheatIsEnemyRockets
/* 0F4414 7F0BF8A4 AFA40194 */   sw    $a0, 0x194($sp)
/* 0F4418 7F0BF8A8 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F441C 7F0BF8AC 14400006 */  bnez  $v0, .Ljp7F0BF8C8
/* 0F4420 7F0BF8B0 8FA40194 */   lw    $a0, 0x194($sp)
/* 0F4424 7F0BF8B4 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F4428 7F0BF8B8 0FC24963 */  jal   cheatButtonTurnOnCheatForPlayers
/* 0F442C 7F0BF8BC AFA40194 */   sw    $a0, 0x194($sp)
/* 0F4430 7F0BF8C0 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F4434 7F0BF8C4 8FA40194 */  lw    $a0, 0x194($sp)
.Ljp7F0BF8C8:
/* 0F4438 7F0BF8C8 24840001 */  addiu $a0, $a0, 1
.Ljp7F0BF8CC:
/* 0F443C 7F0BF8CC 2401004B */  li    $at, 75
/* 0F4440 7F0BF8D0 1481FFEF */  bne   $a0, $at, .Ljp7F0BF890
/* 0F4444 7F0BF8D4 24630001 */   addiu $v1, $v1, 1
.Ljp7F0BF8D8:
/* 0F4448 7F0BF8D8 0FC26C01 */  jal   getPlayerCount
/* 0F444C 7F0BF8DC 00000000 */   nop
/* 0F4450 7F0BF8E0 28410002 */  slti  $at, $v0, 2
/* 0F4454 7F0BF8E4 1420014C */  bnez  $at, .Ljp7F0BFE18
/* 0F4458 7F0BF8E8 3C188005 */   lui   $t8, %hi(g_CurrentStageToLoad) # $t8, 0x8005
/* 0F445C 7F0BF8EC 8F188394 */  lw    $t8, %lo(g_CurrentStageToLoad)($t8)
/* 0F4460 7F0BF8F0 2401005A */  li    $at, 90
/* 0F4464 7F0BF8F4 13010148 */  beq   $t8, $at, .Ljp7F0BFE18
/* 0F4468 7F0BF8F8 00000000 */   nop
/* 0F446C 7F0BF8FC 0FC30630 */  jal   get_mission_state
/* 0F4470 7F0BF900 00000000 */   nop
/* 0F4474 7F0BF904 24010006 */  li    $at, 6
/* 0F4478 7F0BF908 14410029 */  bne   $v0, $at, .Ljp7F0BF9B0
/* 0F447C 7F0BF90C 00000000 */   nop
/* 0F4480 7F0BF910 AFA00190 */  sw    $zero, 0x190($sp)
/* 0F4484 7F0BF914 AFA0018C */  sw    $zero, 0x18c($sp)
/* 0F4488 7F0BF918 0FC26C01 */  jal   getPlayerCount
/* 0F448C 7F0BF91C AFA00188 */   sw    $zero, 0x188($sp)
/* 0F4490 7F0BF920 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F4494 7F0BF924 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F4498 7F0BF928 1840001B */  blez  $v0, .Ljp7F0BF998
/* 0F449C 7F0BF92C 8FA60188 */   lw    $a2, 0x188($sp)
/* 0F44A0 7F0BF930 3C0E8008 */  lui   $t6, %hi(g_playerPointers) # $t6, 0x8008
/* 0F44A4 7F0BF934 25CE9F50 */  addiu $t6, %lo(g_playerPointers) # addiu $t6, $t6, -0x60b0
/* 0F44A8 7F0BF938 0003C880 */  sll   $t9, $v1, 2
/* 0F44AC 7F0BF93C 032E2021 */  addu  $a0, $t9, $t6
.Ljp7F0BF940:
/* 0F44B0 7F0BF940 8C820000 */  lw    $v0, ($a0)
/* 0F44B4 7F0BF944 24630001 */  addiu $v1, $v1, 1
/* 0F44B8 7F0BF948 24840004 */  addiu $a0, $a0, 4
/* 0F44BC 7F0BF94C 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F44C0 7F0BF950 51E00007 */  beql  $t7, $zero, .Ljp7F0BF970
/* 0F44C4 7F0BF954 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F44C8 7F0BF958 8C580424 */  lw    $t8, 0x424($v0)
/* 0F44CC 7F0BF95C 24A50001 */  addiu $a1, $a1, 1
/* 0F44D0 7F0BF960 53000003 */  beql  $t8, $zero, .Ljp7F0BF970
/* 0F44D4 7F0BF964 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F44D8 7F0BF968 24C60001 */  addiu $a2, $a2, 1
/* 0F44DC 7F0BF96C AFA30190 */  sw    $v1, 0x190($sp)
.Ljp7F0BF970:
/* 0F44E0 7F0BF970 AFA4001C */  sw    $a0, 0x1c($sp)
/* 0F44E4 7F0BF974 AFA5018C */  sw    $a1, 0x18c($sp)
/* 0F44E8 7F0BF978 0FC26C01 */  jal   getPlayerCount
/* 0F44EC 7F0BF97C AFA60188 */   sw    $a2, 0x188($sp)
/* 0F44F0 7F0BF980 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F44F4 7F0BF984 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0F44F8 7F0BF988 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F44FC 7F0BF98C 0062082A */  slt   $at, $v1, $v0
/* 0F4500 7F0BF990 1420FFEB */  bnez  $at, .Ljp7F0BF940
/* 0F4504 7F0BF994 8FA60188 */   lw    $a2, 0x188($sp)
.Ljp7F0BF998:
/* 0F4508 7F0BF998 18A00005 */  blez  $a1, .Ljp7F0BF9B0
/* 0F450C 7F0BF99C 00000000 */   nop
/* 0F4510 7F0BF9A0 14A60003 */  bne   $a1, $a2, .Ljp7F0BF9B0
/* 0F4514 7F0BF9A4 00000000 */   nop
/* 0F4518 7F0BF9A8 0FC30633 */  jal   set_missionstate
/* 0F451C 7F0BF9AC 24040001 */   li    $a0, 1
.Ljp7F0BF9B0:
/* 0F4520 7F0BF9B0 3C038005 */  lui   $v1, %hi(g_MpTime) # $v1, 0x8005
/* 0F4524 7F0BF9B4 8C6383CC */  lw    $v1, %lo(g_MpTime)($v1)
/* 0F4528 7F0BF9B8 3C028005 */  lui   $v0, %hi(D_80048394) # $v0, 0x8005
/* 0F452C 7F0BF9BC 3C198005 */  lui   $t9, %hi(g_ClockTimer) # $t9, 0x8005
/* 0F4530 7F0BF9C0 1860004A */  blez  $v1, .Ljp7F0BFAEC
/* 0F4534 7F0BF9C4 00000000 */   nop
/* 0F4538 7F0BF9C8 8C4283C8 */  lw    $v0, %lo(D_80048394)($v0)
/* 0F453C 7F0BF9CC 8F3983A4 */  lw    $t9, %lo(g_ClockTimer)($t9)
/* 0F4540 7F0BF9D0 2464F1F0 */  addiu $a0, $v1, -0xe10
/* 0F4544 7F0BF9D4 0044082A */  slt   $at, $v0, $a0
/* 0F4548 7F0BF9D8 03227021 */  addu  $t6, $t9, $v0
/* 0F454C 7F0BF9DC AFAE0180 */  sw    $t6, 0x180($sp)
/* 0F4550 7F0BF9E0 10200016 */  beqz  $at, .Ljp7F0BFA3C
/* 0F4554 7F0BF9E4 AFA20184 */   sw    $v0, 0x184($sp)
/* 0F4558 7F0BF9E8 01C4082A */  slt   $at, $t6, $a0
/* 0F455C 7F0BF9EC 14200013 */  bnez  $at, .Ljp7F0BFA3C
/* 0F4560 7F0BF9F0 00000000 */   nop
/* 0F4564 7F0BF9F4 0FC26C01 */  jal   getPlayerCount
/* 0F4568 7F0BF9F8 AFA0017C */   sw    $zero, 0x17c($sp)
/* 0F456C 7F0BF9FC 1840000F */  blez  $v0, .Ljp7F0BFA3C
/* 0F4570 7F0BFA00 00000000 */   nop
.Ljp7F0BFA04:
/* 0F4574 7F0BFA04 0FC26F2B */  jal   set_cur_player
/* 0F4578 7F0BFA08 8FA4017C */   lw    $a0, 0x17c($sp)
/* 0F457C 7F0BFA0C 0FC30AA2 */  jal   langGet
/* 0F4580 7F0BFA10 3404B044 */   li    $a0, 45124
/* 0F4584 7F0BFA14 0FC22B10 */  jal   jp_hudmsgBottomShow
/* 0F4588 7F0BFA18 00402025 */   move  $a0, $v0
/* 0F458C 7F0BFA1C 8FAF017C */  lw    $t7, 0x17c($sp)
/* 0F4590 7F0BFA20 25F80001 */  addiu $t8, $t7, 1
/* 0F4594 7F0BFA24 0FC26C01 */  jal   getPlayerCount
/* 0F4598 7F0BFA28 AFB8017C */   sw    $t8, 0x17c($sp)
/* 0F459C 7F0BFA2C 8FB9017C */  lw    $t9, 0x17c($sp)
/* 0F45A0 7F0BFA30 0322082A */  slt   $at, $t9, $v0
/* 0F45A4 7F0BFA34 1420FFF3 */  bnez  $at, .Ljp7F0BFA04
/* 0F45A8 7F0BFA38 00000000 */   nop
.Ljp7F0BFA3C:
/* 0F45AC 7F0BFA3C 3C0F8005 */  lui   $t7, %hi(g_MpTime) # $t7, 0x8005
/* 0F45B0 7F0BFA40 8DEF83CC */  lw    $t7, %lo(g_MpTime)($t7)
/* 0F45B4 7F0BFA44 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F45B8 7F0BFA48 3C198005 */  lui   $t9, %hi(g_MpSoundStateRelated) # $t9, 0x8005
/* 0F45BC 7F0BFA4C 25F8FDA8 */  addiu $t8, $t7, -0x258
/* 0F45C0 7F0BFA50 01D8082A */  slt   $at, $t6, $t8
/* 0F45C4 7F0BFA54 1420000D */  bnez  $at, .Ljp7F0BFA8C
/* 0F45C8 7F0BFA58 00000000 */   nop
/* 0F45CC 7F0BFA5C 8F3983D4 */  lw    $t9, %lo(g_MpSoundStateRelated)($t9)
/* 0F45D0 7F0BFA60 1720000A */  bnez  $t9, .Ljp7F0BFA8C
/* 0F45D4 7F0BFA64 00000000 */   nop
/* 0F45D8 7F0BFA68 0FC3021B */  jal   lvlGetControlsLockedFlag
/* 0F45DC 7F0BFA6C 00000000 */   nop
/* 0F45E0 7F0BFA70 14400006 */  bnez  $v0, .Ljp7F0BFA8C
/* 0F45E4 7F0BFA74 3C048006 */   lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8006
/* 0F45E8 7F0BFA78 3C068005 */  lui   $a2, %hi(g_MpSoundStateRelated) # $a2, 0x8005
/* 0F45EC 7F0BFA7C 24C683D4 */  addiu $a2, %lo(g_MpSoundStateRelated) # addiu $a2, $a2, -0x7c2c
/* 0F45F0 7F0BFA80 8C843760 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F45F4 7F0BFA84 0C002386 */  jal   sndPlaySfx
/* 0F45F8 7F0BFA88 240500A1 */   li    $a1, 161
.Ljp7F0BFA8C:
/* 0F45FC 7F0BFA8C 0FC3021B */  jal   lvlGetControlsLockedFlag
/* 0F4600 7F0BFA90 00000000 */   nop
/* 0F4604 7F0BFA94 1040000A */  beqz  $v0, .Ljp7F0BFAC0
/* 0F4608 7F0BFA98 3C048005 */   lui   $a0, %hi(g_MpSoundStateRelated) # $a0, 0x8005
/* 0F460C 7F0BFA9C 8C8483D4 */  lw    $a0, %lo(g_MpSoundStateRelated)($a0)
/* 0F4610 7F0BFAA0 10800007 */  beqz  $a0, .Ljp7F0BFAC0
/* 0F4614 7F0BFAA4 00000000 */   nop
/* 0F4618 7F0BFAA8 0C002380 */  jal   sndGetPlayingState
/* 0F461C 7F0BFAAC 00000000 */   nop
/* 0F4620 7F0BFAB0 10400003 */  beqz  $v0, .Ljp7F0BFAC0
/* 0F4624 7F0BFAB4 3C048005 */   lui   $a0, %hi(g_MpSoundStateRelated) # $a0, 0x8005
/* 0F4628 7F0BFAB8 0C00240C */  jal   sndDeactivate
/* 0F462C 7F0BFABC 8C8483D4 */   lw    $a0, %lo(g_MpSoundStateRelated)($a0)
.Ljp7F0BFAC0:
/* 0F4630 7F0BFAC0 3C038005 */  lui   $v1, %hi(g_MpTime) # $v1, 0x8005
/* 0F4634 7F0BFAC4 8C6383CC */  lw    $v1, %lo(g_MpTime)($v1)
/* 0F4638 7F0BFAC8 8FAF0184 */  lw    $t7, 0x184($sp)
/* 0F463C 7F0BFACC 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F4640 7F0BFAD0 01E3082A */  slt   $at, $t7, $v1
/* 0F4644 7F0BFAD4 10200005 */  beqz  $at, .Ljp7F0BFAEC
/* 0F4648 7F0BFAD8 01C3082A */   slt   $at, $t6, $v1
/* 0F464C 7F0BFADC 14200003 */  bnez  $at, .Ljp7F0BFAEC
/* 0F4650 7F0BFAE0 00000000 */   nop
/* 0F4654 7F0BFAE4 0FC30C78 */  jal   mpCalculateAwards
/* 0F4658 7F0BFAE8 00002025 */   move  $a0, $zero
.Ljp7F0BFAEC:
/* 0F465C 7F0BFAEC 3C188005 */  lui   $t8, %hi(g_MpPoint) # $t8, 0x8005
/* 0F4660 7F0BFAF0 8F1883D0 */  lw    $t8, %lo(g_MpPoint)($t8)
/* 0F4664 7F0BFAF4 3C198005 */  lui   $t9, %hi(g_ClockTimer) # $t9, 0x8005
/* 0F4668 7F0BFAF8 1B00003D */  blez  $t8, .Ljp7F0BFBF0
/* 0F466C 7F0BFAFC 00000000 */   nop
/* 0F4670 7F0BFB00 8F3983A4 */  lw    $t9, %lo(g_ClockTimer)($t9)
/* 0F4674 7F0BFB04 1320003A */  beqz  $t9, .Ljp7F0BFBF0
/* 0F4678 7F0BFB08 00000000 */   nop
/* 0F467C 7F0BFB0C 0FC26C01 */  jal   getPlayerCount
/* 0F4680 7F0BFB10 00000000 */   nop
/* 0F4684 7F0BFB14 00403825 */  move  $a3, $v0
/* 0F4688 7F0BFB18 00002825 */  move  $a1, $zero
/* 0F468C 7F0BFB1C 00003025 */  move  $a2, $zero
/* 0F4690 7F0BFB20 18400029 */  blez  $v0, .Ljp7F0BFBC8
/* 0F4694 7F0BFB24 00002025 */   move  $a0, $zero
/* 0F4698 7F0BFB28 3C038008 */  lui   $v1, %hi(g_playerPointers) # $v1, 0x8008
/* 0F469C 7F0BFB2C 44800000 */  mtc1  $zero, $f0
/* 0F46A0 7F0BFB30 24639F50 */  addiu $v1, %lo(g_playerPointers) # addiu $v1, $v1, -0x60b0
.Ljp7F0BFB34:
/* 0F46A4 7F0BFB34 8C620000 */  lw    $v0, ($v1)
/* 0F46A8 7F0BFB38 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F46AC 7F0BFB3C 51E0000E */  beql  $t7, $zero, .Ljp7F0BFB78
/* 0F46B0 7F0BFB40 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F46B4 7F0BFB44 8C4E0424 */  lw    $t6, 0x424($v0)
/* 0F46B8 7F0BFB48 51C0000A */  beql  $t6, $zero, .Ljp7F0BFB74
/* 0F46BC 7F0BFB4C 24A50001 */   addiu $a1, $a1, 1
/* 0F46C0 7F0BFB50 8C580428 */  lw    $t8, 0x428($v0)
/* 0F46C4 7F0BFB54 53000007 */  beql  $t8, $zero, .Ljp7F0BFB74
/* 0F46C8 7F0BFB58 24A50001 */   addiu $a1, $a1, 1
/* 0F46CC 7F0BFB5C C44A03E4 */  lwc1  $f10, 0x3e4($v0)
/* 0F46D0 7F0BFB60 460A003E */  c.le.s $f0, $f10
/* 0F46D4 7F0BFB64 00000000 */  nop
/* 0F46D8 7F0BFB68 45020003 */  bc1fl .Ljp7F0BFB78
/* 0F46DC 7F0BFB6C AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F46E0 7F0BFB70 24A50001 */  addiu $a1, $a1, 1
.Ljp7F0BFB74:
/* 0F46E4 7F0BFB74 AFA3001C */  sw    $v1, 0x1c($sp)
.Ljp7F0BFB78:
/* 0F46E8 7F0BFB78 AFA40174 */  sw    $a0, 0x174($sp)
/* 0F46EC 7F0BFB7C AFA50170 */  sw    $a1, 0x170($sp)
/* 0F46F0 7F0BFB80 AFA6016C */  sw    $a2, 0x16c($sp)
/* 0F46F4 7F0BFB84 0FC31162 */  jal   get_points_for_mp_player
/* 0F46F8 7F0BFB88 AFA70178 */   sw    $a3, 0x178($sp)
/* 0F46FC 7F0BFB8C 3C198005 */  lui   $t9, %hi(g_MpPoint) # $t9, 0x8005
/* 0F4700 7F0BFB90 8F3983D0 */  lw    $t9, %lo(g_MpPoint)($t9)
/* 0F4704 7F0BFB94 44800000 */  mtc1  $zero, $f0
/* 0F4708 7F0BFB98 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F470C 7F0BFB9C 0059082A */  slt   $at, $v0, $t9
/* 0F4710 7F0BFBA0 8FA40174 */  lw    $a0, 0x174($sp)
/* 0F4714 7F0BFBA4 8FA50170 */  lw    $a1, 0x170($sp)
/* 0F4718 7F0BFBA8 8FA6016C */  lw    $a2, 0x16c($sp)
/* 0F471C 7F0BFBAC 14200002 */  bnez  $at, .Ljp7F0BFBB8
/* 0F4720 7F0BFBB0 8FA70178 */   lw    $a3, 0x178($sp)
/* 0F4724 7F0BFBB4 24C60001 */  addiu $a2, $a2, 1
.Ljp7F0BFBB8:
/* 0F4728 7F0BFBB8 24840001 */  addiu $a0, $a0, 1
/* 0F472C 7F0BFBBC 0087082A */  slt   $at, $a0, $a3
/* 0F4730 7F0BFBC0 1420FFDC */  bnez  $at, .Ljp7F0BFB34
/* 0F4734 7F0BFBC4 24630004 */   addiu $v1, $v1, 4
.Ljp7F0BFBC8:
/* 0F4738 7F0BFBC8 18C00009 */  blez  $a2, .Ljp7F0BFBF0
/* 0F473C 7F0BFBCC 00000000 */   nop
/* 0F4740 7F0BFBD0 14A00005 */  bnez  $a1, .Ljp7F0BFBE8
/* 0F4744 7F0BFBD4 00000000 */   nop
/* 0F4748 7F0BFBD8 0FC30C78 */  jal   mpCalculateAwards
/* 0F474C 7F0BFBDC 00002025 */   move  $a0, $zero
/* 0F4750 7F0BFBE0 10000003 */  b     .Ljp7F0BFBF0
/* 0F4754 7F0BFBE4 00000000 */   nop
.Ljp7F0BFBE8:
/* 0F4758 7F0BFBE8 0FC30C74 */  jal   mpwatchSetStopPlayFlag
/* 0F475C 7F0BFBEC 00000000 */   nop
.Ljp7F0BFBF0:
/* 0F4760 7F0BFBF0 0FC05202 */  jal   get_scenario
/* 0F4764 7F0BFBF4 00000000 */   nop
/* 0F4768 7F0BFBF8 24010001 */  li    $at, 1
/* 0F476C 7F0BFBFC 14410086 */  bne   $v0, $at, .Ljp7F0BFE18
/* 0F4770 7F0BFC00 3C0F8005 */   lui   $t7, %hi(g_ClockTimer) # $t7, 0x8005
/* 0F4774 7F0BFC04 8DEF83A4 */  lw    $t7, %lo(g_ClockTimer)($t7)
/* 0F4778 7F0BFC08 11E00083 */  beqz  $t7, .Ljp7F0BFE18
/* 0F477C 7F0BFC0C 00000000 */   nop
/* 0F4780 7F0BFC10 0FC26C01 */  jal   getPlayerCount
/* 0F4784 7F0BFC14 00000000 */   nop
/* 0F4788 7F0BFC18 44800000 */  mtc1  $zero, $f0
/* 0F478C 7F0BFC1C 00405025 */  move  $t2, $v0
/* 0F4790 7F0BFC20 00006825 */  move  $t5, $zero
/* 0F4794 7F0BFC24 0000F825 */  move  $ra, $zero
/* 0F4798 7F0BFC28 1840006E */  blez  $v0, .Ljp7F0BFDE4
/* 0F479C 7F0BFC2C 00006025 */   move  $t4, $zero
/* 0F47A0 7F0BFC30 00002825 */  move  $a1, $zero
.Ljp7F0BFC34:
/* 0F47A4 7F0BFC34 00003025 */  move  $a2, $zero
/* 0F47A8 7F0BFC38 18400048 */  blez  $v0, .Ljp7F0BFD5C
/* 0F47AC 7F0BFC3C 00003825 */   move  $a3, $zero
/* 0F47B0 7F0BFC40 30490003 */  andi  $t1, $v0, 3
/* 0F47B4 7F0BFC44 11200019 */  beqz  $t1, .Ljp7F0BFCAC
/* 0F47B8 7F0BFC48 000C5880 */   sll   $t3, $t4, 2
/* 0F47BC 7F0BFC4C 3C188008 */  lui   $t8, %hi(g_playerPointers) # $t8, 0x8008
/* 0F47C0 7F0BFC50 27189F50 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x60b0
/* 0F47C4 7F0BFC54 00007080 */  sll   $t6, $zero, 2
/* 0F47C8 7F0BFC58 0000C8C0 */  sll   $t9, $zero, 3
/* 0F47CC 7F0BFC5C 0320C823 */  subu  $t9, $t9, $zero
/* 0F47D0 7F0BFC60 01D81821 */  addu  $v1, $t6, $t8
/* 0F47D4 7F0BFC64 3C0E8008 */  lui   $t6, %hi(g_playerPlayerData) # $t6, 0x8008
/* 0F47D8 7F0BFC68 0019C900 */  sll   $t9, $t9, 4
/* 0F47DC 7F0BFC6C 032B7821 */  addu  $t7, $t9, $t3
/* 0F47E0 7F0BFC70 25CE9F60 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x60a0
/* 0F47E4 7F0BFC74 01EE2021 */  addu  $a0, $t7, $t6
/* 0F47E8 7F0BFC78 01204025 */  move  $t0, $t1
.Ljp7F0BFC7C:
/* 0F47EC 7F0BFC7C 8C780000 */  lw    $t8, ($v1)
/* 0F47F0 7F0BFC80 24E70001 */  addiu $a3, $a3, 1
/* 0F47F4 7F0BFC84 24630004 */  addiu $v1, $v1, 4
/* 0F47F8 7F0BFC88 8F1900D8 */  lw    $t9, 0xd8($t8)
/* 0F47FC 7F0BFC8C 57200003 */  bnezl $t9, .Ljp7F0BFC9C
/* 0F4800 7F0BFC90 8C8F0024 */   lw    $t7, 0x24($a0)
/* 0F4804 7F0BFC94 24C60001 */  addiu $a2, $a2, 1
/* 0F4808 7F0BFC98 8C8F0024 */  lw    $t7, 0x24($a0)
.Ljp7F0BFC9C:
/* 0F480C 7F0BFC9C 24840070 */  addiu $a0, $a0, 0x70
/* 0F4810 7F0BFCA0 1507FFF6 */  bne   $t0, $a3, .Ljp7F0BFC7C
/* 0F4814 7F0BFCA4 00AF2821 */   addu  $a1, $a1, $t7
/* 0F4818 7F0BFCA8 10E2002C */  beq   $a3, $v0, .Ljp7F0BFD5C
.Ljp7F0BFCAC:
/* 0F481C 7F0BFCAC 3C188008 */   lui   $t8, %hi(g_playerPointers) # $t8, 0x8008
/* 0F4820 7F0BFCB0 0007C8C0 */  sll   $t9, $a3, 3
/* 0F4824 7F0BFCB4 0327C823 */  subu  $t9, $t9, $a3
/* 0F4828 7F0BFCB8 27189F50 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x60b0
/* 0F482C 7F0BFCBC 00077080 */  sll   $t6, $a3, 2
/* 0F4830 7F0BFCC0 01D81821 */  addu  $v1, $t6, $t8
/* 0F4834 7F0BFCC4 0019C900 */  sll   $t9, $t9, 4
/* 0F4838 7F0BFCC8 032B7821 */  addu  $t7, $t9, $t3
/* 0F483C 7F0BFCCC 3C0E8008 */  lui   $t6, %hi(g_playerPlayerData) # $t6, 0x8008
/* 0F4840 7F0BFCD0 25CE9F60 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x60a0
/* 0F4844 7F0BFCD4 000AC880 */  sll   $t9, $t2, 2
/* 0F4848 7F0BFCD8 03384021 */  addu  $t0, $t9, $t8
/* 0F484C 7F0BFCDC 01EE2021 */  addu  $a0, $t7, $t6
.Ljp7F0BFCE0:
/* 0F4850 7F0BFCE0 8C6F0000 */  lw    $t7, ($v1)
/* 0F4854 7F0BFCE4 8DEE00D8 */  lw    $t6, 0xd8($t7)
/* 0F4858 7F0BFCE8 55C00003 */  bnezl $t6, .Ljp7F0BFCF8
/* 0F485C 7F0BFCEC 8C780004 */   lw    $t8, 4($v1)
/* 0F4860 7F0BFCF0 24C60001 */  addiu $a2, $a2, 1
/* 0F4864 7F0BFCF4 8C780004 */  lw    $t8, 4($v1)
.Ljp7F0BFCF8:
/* 0F4868 7F0BFCF8 8C990024 */  lw    $t9, 0x24($a0)
/* 0F486C 7F0BFCFC 8F0F00D8 */  lw    $t7, 0xd8($t8)
/* 0F4870 7F0BFD00 00B92821 */  addu  $a1, $a1, $t9
/* 0F4874 7F0BFD04 55E00003 */  bnezl $t7, .Ljp7F0BFD14
/* 0F4878 7F0BFD08 8C790008 */   lw    $t9, 8($v1)
/* 0F487C 7F0BFD0C 24C60001 */  addiu $a2, $a2, 1
/* 0F4880 7F0BFD10 8C790008 */  lw    $t9, 8($v1)
.Ljp7F0BFD14:
/* 0F4884 7F0BFD14 8C8E0094 */  lw    $t6, 0x94($a0)
/* 0F4888 7F0BFD18 8F3800D8 */  lw    $t8, 0xd8($t9)
/* 0F488C 7F0BFD1C 00AE2821 */  addu  $a1, $a1, $t6
/* 0F4890 7F0BFD20 57000003 */  bnezl $t8, .Ljp7F0BFD30
/* 0F4894 7F0BFD24 8C6E000C */   lw    $t6, 0xc($v1)
/* 0F4898 7F0BFD28 24C60001 */  addiu $a2, $a2, 1
/* 0F489C 7F0BFD2C 8C6E000C */  lw    $t6, 0xc($v1)
.Ljp7F0BFD30:
/* 0F48A0 7F0BFD30 8C8F0104 */  lw    $t7, 0x104($a0)
/* 0F48A4 7F0BFD34 24630010 */  addiu $v1, $v1, 0x10
/* 0F48A8 7F0BFD38 8DD900D8 */  lw    $t9, 0xd8($t6)
/* 0F48AC 7F0BFD3C 00AF2821 */  addu  $a1, $a1, $t7
/* 0F48B0 7F0BFD40 57200003 */  bnezl $t9, .Ljp7F0BFD50
/* 0F48B4 7F0BFD44 8C980174 */   lw    $t8, 0x174($a0)
/* 0F48B8 7F0BFD48 24C60001 */  addiu $a2, $a2, 1
/* 0F48BC 7F0BFD4C 8C980174 */  lw    $t8, 0x174($a0)
.Ljp7F0BFD50:
/* 0F48C0 7F0BFD50 248401C0 */  addiu $a0, $a0, 0x1c0
/* 0F48C4 7F0BFD54 1468FFE2 */  bne   $v1, $t0, .Ljp7F0BFCE0
/* 0F48C8 7F0BFD58 00B82821 */   addu  $a1, $a1, $t8
.Ljp7F0BFD5C:
/* 0F48CC 7F0BFD5C 28A10002 */  slti  $at, $a1, 2
/* 0F48D0 7F0BFD60 1420001C */  bnez  $at, .Ljp7F0BFDD4
/* 0F48D4 7F0BFD64 000C78C0 */   sll   $t7, $t4, 3
/* 0F48D8 7F0BFD68 01EC7823 */  subu  $t7, $t7, $t4
/* 0F48DC 7F0BFD6C 3C0E8008 */  lui   $t6, %hi(g_playerPlayerData) # $t6, 0x8008
/* 0F48E0 7F0BFD70 25CE9F60 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x60a0
/* 0F48E4 7F0BFD74 000F7900 */  sll   $t7, $t7, 4
/* 0F48E8 7F0BFD78 01EE1821 */  addu  $v1, $t7, $t6
/* 0F48EC 7F0BFD7C 906F0068 */  lbu   $t7, 0x68($v1)
/* 0F48F0 7F0BFD80 3C188008 */  lui   $t8, %hi(g_playerPointers) # $t8, 0x8008
/* 0F48F4 7F0BFD84 27189F50 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x60b0
/* 0F48F8 7F0BFD88 000CC880 */  sll   $t9, $t4, 2
/* 0F48FC 7F0BFD8C 15E00003 */  bnez  $t7, .Ljp7F0BFD9C
/* 0F4900 7F0BFD90 03382021 */   addu  $a0, $t9, $t8
/* 0F4904 7F0BFD94 24CE0001 */  addiu $t6, $a2, 1
/* 0F4908 7F0BFD98 A06E0068 */  sb    $t6, 0x68($v1)
.Ljp7F0BFD9C:
/* 0F490C 7F0BFD9C 8C830000 */  lw    $v1, ($a0)
/* 0F4910 7F0BFDA0 25AD0001 */  addiu $t5, $t5, 1
/* 0F4914 7F0BFDA4 8C790424 */  lw    $t9, 0x424($v1)
/* 0F4918 7F0BFDA8 5320000B */  beql  $t9, $zero, .Ljp7F0BFDD8
/* 0F491C 7F0BFDAC 258C0001 */   addiu $t4, $t4, 1
/* 0F4920 7F0BFDB0 8C780428 */  lw    $t8, 0x428($v1)
/* 0F4924 7F0BFDB4 53000008 */  beql  $t8, $zero, .Ljp7F0BFDD8
/* 0F4928 7F0BFDB8 258C0001 */   addiu $t4, $t4, 1
/* 0F492C 7F0BFDBC C47003E4 */  lwc1  $f16, 0x3e4($v1)
/* 0F4930 7F0BFDC0 4600803C */  c.lt.s $f16, $f0
/* 0F4934 7F0BFDC4 00000000 */  nop
/* 0F4938 7F0BFDC8 45020003 */  bc1fl .Ljp7F0BFDD8
/* 0F493C 7F0BFDCC 258C0001 */   addiu $t4, $t4, 1
/* 0F4940 7F0BFDD0 27FF0001 */  addiu $ra, $ra, 1
.Ljp7F0BFDD4:
/* 0F4944 7F0BFDD4 258C0001 */  addiu $t4, $t4, 1
.Ljp7F0BFDD8:
/* 0F4948 7F0BFDD8 018A082A */  slt   $at, $t4, $t2
/* 0F494C 7F0BFDDC 5420FF95 */  bnezl $at, .Ljp7F0BFC34
/* 0F4950 7F0BFDE0 00002825 */   move  $a1, $zero
.Ljp7F0BFDE4:
/* 0F4954 7F0BFDE4 2443FFFF */  addiu $v1, $v0, -1
/* 0F4958 7F0BFDE8 03E3082A */  slt   $at, $ra, $v1
/* 0F495C 7F0BFDEC 54200006 */  bnezl $at, .Ljp7F0BFE08
/* 0F4960 7F0BFDF0 01A3082A */   slt   $at, $t5, $v1
/* 0F4964 7F0BFDF4 0FC30C78 */  jal   mpCalculateAwards
/* 0F4968 7F0BFDF8 00002025 */   move  $a0, $zero
/* 0F496C 7F0BFDFC 10000006 */  b     .Ljp7F0BFE18
/* 0F4970 7F0BFE00 00000000 */   nop
/* 0F4974 7F0BFE04 01A3082A */  slt   $at, $t5, $v1
.Ljp7F0BFE08:
/* 0F4978 7F0BFE08 14200003 */  bnez  $at, .Ljp7F0BFE18
/* 0F497C 7F0BFE0C 00000000 */   nop
/* 0F4980 7F0BFE10 0FC30C74 */  jal   mpwatchSetStopPlayFlag
/* 0F4984 7F0BFE14 00000000 */   nop
.Ljp7F0BFE18:
/* 0F4988 7F0BFE18 3C028005 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8005
/* 0F498C 7F0BFE1C 3C0F8005 */  lui   $t7, %hi(D_80048394) # $t7, 0x8005
/* 0F4990 7F0BFE20 8DEF83C8 */  lw    $t7, %lo(D_80048394)($t7)
/* 0F4994 7F0BFE24 8C4283A4 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F4998 7F0BFE28 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0F499C 7F0BFE2C 44810000 */  mtc1  $at, $f0
/* 0F49A0 7F0BFE30 01E27021 */  addu  $t6, $t7, $v0
/* 0F49A4 7F0BFE34 448E9000 */  mtc1  $t6, $f18
/* 0F49A8 7F0BFE38 3C018005 */  lui   $at, %hi(D_80048394) # $at, 0x8005
/* 0F49AC 7F0BFE3C AC2E83C8 */  sw    $t6, %lo(D_80048394)($at)
/* 0F49B0 7F0BFE40 46809120 */  cvt.s.w $f4, $f18
/* 0F49B4 7F0BFE44 3C038005 */  lui   $v1, %hi(D_800483A8) # $v1, 0x8005
/* 0F49B8 7F0BFE48 3C018005 */  lui   $at, %hi(g_CurrentMultiPlayerSec) # $at, 0x8005
/* 0F49BC 7F0BFE4C 246383DC */  addiu $v1, %lo(D_800483A8) # addiu $v1, $v1, -0x7c24
/* 0F49C0 7F0BFE50 00002025 */  move  $a0, $zero
/* 0F49C4 7F0BFE54 3405FFFF */  li    $a1, 65535
/* 0F49C8 7F0BFE58 46002183 */  div.s $f6, $f4, $f0
/* 0F49CC 7F0BFE5C E42683D8 */  swc1  $f6, %lo(g_CurrentMultiPlayerSec)($at)
/* 0F49D0 7F0BFE60 8C790000 */  lw    $t9, ($v1)
/* 0F49D4 7F0BFE64 3C018005 */  lui   $at, %hi(g_CurrentMultiPlayerMin) # $at, 0x8005
/* 0F49D8 7F0BFE68 03227821 */  addu  $t7, $t9, $v0
/* 0F49DC 7F0BFE6C 448F4000 */  mtc1  $t7, $f8
/* 0F49E0 7F0BFE70 AC6F0000 */  sw    $t7, ($v1)
/* 0F49E4 7F0BFE74 468042A0 */  cvt.s.w $f10, $f8
/* 0F49E8 7F0BFE78 46005403 */  div.s $f16, $f10, $f0
/* 0F49EC 7F0BFE7C 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F49F0 7F0BFE80 E43083E0 */   swc1  $f16, %lo(g_CurrentMultiPlayerMin)($at)
/* 0F49F4 7F0BFE84 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0F49F8 7F0BFE88 44810000 */  mtc1  $at, $f0
/* 0F49FC 7F0BFE8C 10400009 */  beqz  $v0, .Ljp7F0BFEB4
/* 0F4A00 7F0BFE90 3C038005 */   lui   $v1, %hi(D_80048390)
/* 0F4A04 7F0BFE94 3C038005 */  lui   $v1, %hi(D_80048390) # $v1, 0x8005
/* 0F4A08 7F0BFE98 3C018005 */  lui   $at, %hi(D_80048388) # $at, 0x8005
/* 0F4A0C 7F0BFE9C 246383C4 */  addiu $v1, %lo(D_80048390) # addiu $v1, $v1, -0x7c3c
/* 0F4A10 7F0BFEA0 AC2083BC */  sw    $zero, %lo(D_80048388)($at)
/* 0F4A14 7F0BFEA4 AC600000 */  sw    $zero, ($v1)
/* 0F4A18 7F0BFEA8 3C028005 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8005
/* 0F4A1C 7F0BFEAC 1000000C */  b     .Ljp7F0BFEE0
/* 0F4A20 7F0BFEB0 8C4283A4 */   lw    $v0, %lo(g_ClockTimer)($v0)
.Ljp7F0BFEB4:
/* 0F4A24 7F0BFEB4 246383C4 */  addiu $v1, $v1, %lo(D_80048390)
/* 0F4A28 7F0BFEB8 3C028005 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8005
/* 0F4A2C 7F0BFEBC 8C4283A4 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F4A30 7F0BFEC0 8C6E0000 */  lw    $t6, ($v1)
/* 0F4A34 7F0BFEC4 240F0001 */  li    $t7, 1
/* 0F4A38 7F0BFEC8 01C2C821 */  addu  $t9, $t6, $v0
/* 0F4A3C 7F0BFECC 2B210708 */  slti  $at, $t9, 0x708
/* 0F4A40 7F0BFED0 14200003 */  bnez  $at, .Ljp7F0BFEE0
/* 0F4A44 7F0BFED4 AC790000 */   sw    $t9, ($v1)
/* 0F4A48 7F0BFED8 3C018005 */  lui   $at, %hi(D_80048388) # $at, 0x8005
/* 0F4A4C 7F0BFEDC AC2F83BC */  sw    $t7, %lo(D_80048388)($at)
.Ljp7F0BFEE0:
/* 0F4A50 7F0BFEE0 3C0E8005 */  lui   $t6, %hi(D_80048388) # $t6, 0x8005
/* 0F4A54 7F0BFEE4 8DCE83BC */  lw    $t6, %lo(D_80048388)($t6)
/* 0F4A58 7F0BFEE8 3C038005 */  lui   $v1, %hi(D_8004838C) # $v1, 0x8005
/* 0F4A5C 7F0BFEEC 246383C0 */  addiu $v1, %lo(D_8004838C) # addiu $v1, $v1, -0x7c40
/* 0F4A60 7F0BFEF0 11C00005 */  beqz  $t6, .Ljp7F0BFF08
/* 0F4A64 7F0BFEF4 00000000 */   nop
/* 0F4A68 7F0BFEF8 8C790000 */  lw    $t9, ($v1)
/* 0F4A6C 7F0BFEFC 0322C021 */  addu  $t8, $t9, $v0
/* 0F4A70 7F0BFF00 10000015 */  b     .Ljp7F0BFF58
/* 0F4A74 7F0BFF04 AC780000 */   sw    $t8, ($v1)
.Ljp7F0BFF08:
/* 0F4A78 7F0BFF08 3C038005 */  lui   $v1, %hi(D_800483B0) # $v1, 0x8005
/* 0F4A7C 7F0BFF0C 246383E4 */  addiu $v1, %lo(D_800483B0) # addiu $v1, $v1, -0x7c1c
/* 0F4A80 7F0BFF10 8C6F0000 */  lw    $t7, ($v1)
/* 0F4A84 7F0BFF14 3C048005 */  lui   $a0, %hi(D_800483B8) # $a0, 0x8005
/* 0F4A88 7F0BFF18 3C018005 */  lui   $at, %hi(g_StageTimeSec) # $at, 0x8005
/* 0F4A8C 7F0BFF1C 01E2C821 */  addu  $t9, $t7, $v0
/* 0F4A90 7F0BFF20 44999000 */  mtc1  $t9, $f18
/* 0F4A94 7F0BFF24 AC790000 */  sw    $t9, ($v1)
/* 0F4A98 7F0BFF28 248483EC */  addiu $a0, %lo(D_800483B8) # addiu $a0, $a0, -0x7c14
/* 0F4A9C 7F0BFF2C 46809120 */  cvt.s.w $f4, $f18
/* 0F4AA0 7F0BFF30 46002183 */  div.s $f6, $f4, $f0
/* 0F4AA4 7F0BFF34 E42683E8 */  swc1  $f6, %lo(g_StageTimeSec)($at)
/* 0F4AA8 7F0BFF38 8C980000 */  lw    $t8, ($a0)
/* 0F4AAC 7F0BFF3C 3C018005 */  lui   $at, %hi(g_PowerOnTimeSec) # $at, 0x8005
/* 0F4AB0 7F0BFF40 03027021 */  addu  $t6, $t8, $v0
/* 0F4AB4 7F0BFF44 448E4000 */  mtc1  $t6, $f8
/* 0F4AB8 7F0BFF48 AC8E0000 */  sw    $t6, ($a0)
/* 0F4ABC 7F0BFF4C 468042A0 */  cvt.s.w $f10, $f8
/* 0F4AC0 7F0BFF50 46005403 */  div.s $f16, $f10, $f0
/* 0F4AC4 7F0BFF54 E43083F0 */  swc1  $f16, %lo(g_PowerOnTimeSec)($at)
.Ljp7F0BFF58:
/* 0F4AC8 7F0BFF58 0C00114D */  jal   viSetUseZBuf
/* 0F4ACC 7F0BFF5C 24040001 */   li    $a0, 1
/* 0F4AD0 7F0BFF60 3C198005 */  lui   $t9, %hi(g_CurrentStageToLoad) # $t9, 0x8005
/* 0F4AD4 7F0BFF64 8F398394 */  lw    $t9, %lo(g_CurrentStageToLoad)($t9)
/* 0F4AD8 7F0BFF68 2401005A */  li    $at, 90
/* 0F4ADC 7F0BFF6C 17210009 */  bne   $t9, $at, .Ljp7F0BFF94
/* 0F4AE0 7F0BFF70 00000000 */   nop
/* 0F4AE4 7F0BFF74 0FC24907 */  jal   cheat_buttons_mp_related
/* 0F4AE8 7F0BFF78 00000000 */   nop
/* 0F4AEC 7F0BFF7C 0FC069F4 */  jal   menu_init
/* 0F4AF0 7F0BFF80 00000000 */   nop
/* 0F4AF4 7F0BFF84 0FC3097C */  jal   something_with_LnameJ
/* 0F4AF8 7F0BFF88 00000000 */   nop
/* 0F4AFC 7F0BFF8C 100000A9 */  b     .Ljp7F0C0234
/* 0F4B00 7F0BFF90 00000000 */   nop
.Ljp7F0BFF94:
/* 0F4B04 7F0BFF94 0FC271D7 */  jal   sub_GAME_7F09BBBC
/* 0F4B08 7F0BFF98 00000000 */   nop
/* 0F4B0C 7F0BFF9C 0FC2FD2D */  jal   lvlSetMultipliersForDifficulty
/* 0F4B10 7F0BFFA0 00000000 */   nop
/* 0F4B14 7F0BFFA4 0FC2F4E1 */  jal   sub_GAME_7F0BC7D4
/* 0F4B18 7F0BFFA8 00000000 */   nop
/* 0F4B1C 7F0BFFAC 0FC24E7C */  jal   sub_GAME_7F092E50
/* 0F4B20 7F0BFFB0 00000000 */   nop
/* 0F4B24 7F0BFFB4 0FC253F6 */  jal   sub_GAME_7F094438
/* 0F4B28 7F0BFFB8 00000000 */   nop
/* 0F4B2C 7F0BFFBC 0FC294E7 */  jal   update_bullet_sparks_and_dust_clouds
/* 0F4B30 7F0BFFC0 00000000 */   nop
/* 0F4B34 7F0BFFC4 0FC1A516 */  jal   sub_GAME_7F068E6C
/* 0F4B38 7F0BFFC8 00000000 */   nop
/* 0F4B3C 7F0BFFCC 0FC28D1D */  jal   update_broken_windows
/* 0F4B40 7F0BFFD0 00000000 */   nop
/* 0F4B44 7F0BFFD4 0FC28238 */  jal   update_gray_flying_particles
/* 0F4B48 7F0BFFD8 00000000 */   nop
/* 0F4B4C 7F0BFFDC 0FC0F252 */  jal   handle_mp_respawn_and_some_things
/* 0F4B50 7F0BFFE0 00000000 */   nop
/* 0F4B54 7F0BFFE4 0FC3081E */  jal   reset_all_music_slots
/* 0F4B58 7F0BFFE8 00000000 */   nop
/* 0F4B5C 7F0BFFEC 0FC3097C */  jal   something_with_LnameJ
/* 0F4B60 7F0BFFF0 00000000 */   nop
/* 0F4B64 7F0BFFF4 0FC246A6 */  jal   get_debug_joy2detailedit_flag
/* 0F4B68 7F0BFFF8 00000000 */   nop
/* 0F4B6C 7F0BFFFC 1040004D */  beqz  $v0, .Ljp7F0C0134
/* 0F4B70 7F0C0000 3C068005 */   lui   $a2, %hi(D_800483C8) # $a2, 0x8005
/* 0F4B74 7F0C0004 24C683FC */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c04
/* 0F4B78 7F0C0008 8CD80000 */  lw    $t8, ($a2)
/* 0F4B7C 7F0C000C 24043000 */  li    $a0, 12288
/* 0F4B80 7F0C0010 17000048 */  bnez  $t8, .Ljp7F0C0134
/* 0F4B84 7F0C0014 00000000 */   nop
/* 0F4B88 7F0C0018 0C0025CC */  jal   mempAllocBytesInBank
/* 0F4B8C 7F0C001C 24050004 */   li    $a1, 4
/* 0F4B90 7F0C0020 3C068005 */  lui   $a2, %hi(D_800483C8) # $a2, 0x8005
/* 0F4B94 7F0C0024 24C683FC */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, -0x7c04
/* 0F4B98 7F0C0028 10400042 */  beqz  $v0, .Ljp7F0C0134
/* 0F4B9C 7F0C002C ACC20000 */   sw    $v0, ($a2)
/* 0F4BA0 7F0C0030 00001825 */  move  $v1, $zero
/* 0F4BA4 7F0C0034 24052EE0 */  li    $a1, 12000
/* 0F4BA8 7F0C0038 240400FF */  li    $a0, 255
.Ljp7F0C003C:
/* 0F4BAC 7F0C003C 8CCE0000 */  lw    $t6, ($a2)
/* 0F4BB0 7F0C0040 01C3C821 */  addu  $t9, $t6, $v1
/* 0F4BB4 7F0C0044 A3240000 */  sb    $a0, ($t9)
/* 0F4BB8 7F0C0048 8CD80000 */  lw    $t8, ($a2)
/* 0F4BBC 7F0C004C 03031021 */  addu  $v0, $t8, $v1
/* 0F4BC0 7F0C0050 904F0001 */  lbu   $t7, 1($v0)
/* 0F4BC4 7F0C0054 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F4BC8 7F0C0058 35D90020 */  ori   $t9, $t6, 0x20
/* 0F4BCC 7F0C005C A0590001 */  sb    $t9, 1($v0)
/* 0F4BD0 7F0C0060 8CD80000 */  lw    $t8, ($a2)
/* 0F4BD4 7F0C0064 03031021 */  addu  $v0, $t8, $v1
/* 0F4BD8 7F0C0068 904F0001 */  lbu   $t7, 1($v0)
/* 0F4BDC 7F0C006C 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F4BE0 7F0C0070 35D90004 */  ori   $t9, $t6, 4
/* 0F4BE4 7F0C0074 A0590001 */  sb    $t9, 1($v0)
/* 0F4BE8 7F0C0078 8CD80000 */  lw    $t8, ($a2)
/* 0F4BEC 7F0C007C 03037821 */  addu  $t7, $t8, $v1
/* 0F4BF0 7F0C0080 A1E40004 */  sb    $a0, 4($t7)
/* 0F4BF4 7F0C0084 8CCE0000 */  lw    $t6, ($a2)
/* 0F4BF8 7F0C0088 01C31021 */  addu  $v0, $t6, $v1
/* 0F4BFC 7F0C008C 90590005 */  lbu   $t9, 5($v0)
/* 0F4C00 7F0C0090 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F4C04 7F0C0094 370F0020 */  ori   $t7, $t8, 0x20
/* 0F4C08 7F0C0098 A04F0005 */  sb    $t7, 5($v0)
/* 0F4C0C 7F0C009C 8CCE0000 */  lw    $t6, ($a2)
/* 0F4C10 7F0C00A0 01C31021 */  addu  $v0, $t6, $v1
/* 0F4C14 7F0C00A4 90590005 */  lbu   $t9, 5($v0)
/* 0F4C18 7F0C00A8 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F4C1C 7F0C00AC 370F0004 */  ori   $t7, $t8, 4
/* 0F4C20 7F0C00B0 A04F0005 */  sb    $t7, 5($v0)
/* 0F4C24 7F0C00B4 8CCE0000 */  lw    $t6, ($a2)
/* 0F4C28 7F0C00B8 01C3C821 */  addu  $t9, $t6, $v1
/* 0F4C2C 7F0C00BC A3240008 */  sb    $a0, 8($t9)
/* 0F4C30 7F0C00C0 8CD80000 */  lw    $t8, ($a2)
/* 0F4C34 7F0C00C4 03031021 */  addu  $v0, $t8, $v1
/* 0F4C38 7F0C00C8 904F0009 */  lbu   $t7, 9($v0)
/* 0F4C3C 7F0C00CC 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F4C40 7F0C00D0 35D90020 */  ori   $t9, $t6, 0x20
/* 0F4C44 7F0C00D4 A0590009 */  sb    $t9, 9($v0)
/* 0F4C48 7F0C00D8 8CD80000 */  lw    $t8, ($a2)
/* 0F4C4C 7F0C00DC 03031021 */  addu  $v0, $t8, $v1
/* 0F4C50 7F0C00E0 904F0009 */  lbu   $t7, 9($v0)
/* 0F4C54 7F0C00E4 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F4C58 7F0C00E8 35D90004 */  ori   $t9, $t6, 4
/* 0F4C5C 7F0C00EC A0590009 */  sb    $t9, 9($v0)
/* 0F4C60 7F0C00F0 8CD80000 */  lw    $t8, ($a2)
/* 0F4C64 7F0C00F4 03037821 */  addu  $t7, $t8, $v1
/* 0F4C68 7F0C00F8 A1E4000C */  sb    $a0, 0xc($t7)
/* 0F4C6C 7F0C00FC 8CCE0000 */  lw    $t6, ($a2)
/* 0F4C70 7F0C0100 01C31021 */  addu  $v0, $t6, $v1
/* 0F4C74 7F0C0104 9059000D */  lbu   $t9, 0xd($v0)
/* 0F4C78 7F0C0108 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F4C7C 7F0C010C 370F0020 */  ori   $t7, $t8, 0x20
/* 0F4C80 7F0C0110 A04F000D */  sb    $t7, 0xd($v0)
/* 0F4C84 7F0C0114 8CCE0000 */  lw    $t6, ($a2)
/* 0F4C88 7F0C0118 01C31021 */  addu  $v0, $t6, $v1
/* 0F4C8C 7F0C011C 9059000D */  lbu   $t9, 0xd($v0)
/* 0F4C90 7F0C0120 24630010 */  addiu $v1, $v1, 0x10
/* 0F4C94 7F0C0124 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F4C98 7F0C0128 370F0004 */  ori   $t7, $t8, 4
/* 0F4C9C 7F0C012C 1465FFC3 */  bne   $v1, $a1, .Ljp7F0C003C
/* 0F4CA0 7F0C0130 A04F000D */   sb    $t7, 0xd($v0)
.Ljp7F0C0134:
/* 0F4CA4 7F0C0134 0FC246C7 */  jal   get_debug_portal_flag
/* 0F4CA8 7F0C0138 00000000 */   nop
/* 0F4CAC 7F0C013C 10400003 */  beqz  $v0, .Ljp7F0C014C
/* 0F4CB0 7F0C0140 00000000 */   nop
/* 0F4CB4 7F0C0144 0FC2FAB4 */  jal   lvlPortalDebug7F0BDF10
/* 0F4CB8 7F0C0148 00002025 */   move  $a0, $zero
.Ljp7F0C014C:
/* 0F4CBC 7F0C014C 0FC2467D */  jal   getDebugMode
/* 0F4CC0 7F0C0150 00000000 */   nop
/* 0F4CC4 7F0C0154 24010004 */  li    $at, 4
/* 0F4CC8 7F0C0158 10410006 */  beq   $v0, $at, .Ljp7F0C0174
/* 0F4CCC 7F0C015C 00002025 */   move  $a0, $zero
/* 0F4CD0 7F0C0160 24010008 */  li    $at, 8
/* 0F4CD4 7F0C0164 1041001A */  beq   $v0, $at, .Ljp7F0C01D0
/* 0F4CD8 7F0C0168 00002025 */   move  $a0, $zero
/* 0F4CDC 7F0C016C 10000031 */  b     .Ljp7F0C0234
/* 0F4CE0 7F0C0170 00000000 */   nop
.Ljp7F0C0174:
/* 0F4CE4 7F0C0174 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4CE8 7F0C0178 24050002 */   li    $a1, 2
/* 0F4CEC 7F0C017C 50400008 */  beql  $v0, $zero, .Ljp7F0C01A0
/* 0F4CF0 7F0C0180 00002025 */   move  $a0, $zero
/* 0F4CF4 7F0C0184 0FC2C078 */  jal   sub_GAME_7F0AF630
/* 0F4CF8 7F0C0188 2404FFFF */   li    $a0, -1
/* 0F4CFC 7F0C018C 00002025 */  move  $a0, $zero
/* 0F4D00 7F0C0190 00002825 */  move  $a1, $zero
/* 0F4D04 7F0C0194 0FC2CE3A */  jal   sub_GAME_7F0B2D38
/* 0F4D08 7F0C0198 00003025 */   move  $a2, $zero
/* 0F4D0C 7F0C019C 00002025 */  move  $a0, $zero
.Ljp7F0C01A0:
/* 0F4D10 7F0C01A0 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4D14 7F0C01A4 24050001 */   li    $a1, 1
/* 0F4D18 7F0C01A8 10400022 */  beqz  $v0, .Ljp7F0C0234
/* 0F4D1C 7F0C01AC 00000000 */   nop
/* 0F4D20 7F0C01B0 0FC2C078 */  jal   sub_GAME_7F0AF630
/* 0F4D24 7F0C01B4 24040001 */   li    $a0, 1
/* 0F4D28 7F0C01B8 00002025 */  move  $a0, $zero
/* 0F4D2C 7F0C01BC 00002825 */  move  $a1, $zero
/* 0F4D30 7F0C01C0 0FC2CE3A */  jal   sub_GAME_7F0B2D38
/* 0F4D34 7F0C01C4 00003025 */   move  $a2, $zero
/* 0F4D38 7F0C01C8 1000001A */  b     .Ljp7F0C0234
/* 0F4D3C 7F0C01CC 00000000 */   nop
.Ljp7F0C01D0:
/* 0F4D40 7F0C01D0 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4D44 7F0C01D4 24050002 */   li    $a1, 2
/* 0F4D48 7F0C01D8 50400004 */  beql  $v0, $zero, .Ljp7F0C01EC
/* 0F4D4C 7F0C01DC 00002025 */   move  $a0, $zero
/* 0F4D50 7F0C01E0 0FC08C46 */  jal   chrDecrementAnimationTablePointerCount
/* 0F4D54 7F0C01E4 00000000 */   nop
/* 0F4D58 7F0C01E8 00002025 */  move  $a0, $zero
.Ljp7F0C01EC:
/* 0F4D5C 7F0C01EC 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4D60 7F0C01F0 24050001 */   li    $a1, 1
/* 0F4D64 7F0C01F4 50400004 */  beql  $v0, $zero, .Ljp7F0C0208
/* 0F4D68 7F0C01F8 00002025 */   move  $a0, $zero
/* 0F4D6C 7F0C01FC 0FC08C5E */  jal   chrIncrementAnimationTablePointerCount
/* 0F4D70 7F0C0200 00000000 */   nop
/* 0F4D74 7F0C0204 00002025 */  move  $a0, $zero
.Ljp7F0C0208:
/* 0F4D78 7F0C0208 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4D7C 7F0C020C 24050020 */   li    $a1, 32
/* 0F4D80 7F0C0210 50400004 */  beql  $v0, $zero, .Ljp7F0C0224
/* 0F4D84 7F0C0214 00002025 */   move  $a0, $zero
/* 0F4D88 7F0C0218 0FC08C6C */  jal   chrToggleD_8002C90C
/* 0F4D8C 7F0C021C 00000000 */   nop
/* 0F4D90 7F0C0220 00002025 */  move  $a0, $zero
.Ljp7F0C0224:
/* 0F4D94 7F0C0224 0C0030DC */  jal   joyGetButtons
/* 0F4D98 7F0C0228 24050010 */   li    $a1, 16
/* 0F4D9C 7F0C022C 0FC08C72 */  jal   sub_GAME_7F022EE0
/* 0F4DA0 7F0C0230 0002202B */   sltu  $a0, $zero, $v0
.Ljp7F0C0234:
/* 0F4DA4 7F0C0234 0FC2467D */  jal   getDebugMode
/* 0F4DA8 7F0C0238 00000000 */   nop
/* 0F4DAC 7F0C023C 2401000C */  li    $at, 12
/* 0F4DB0 7F0C0240 1041002E */  beq   $v0, $at, .Ljp7F0C02FC
/* 0F4DB4 7F0C0244 00002025 */   move  $a0, $zero
/* 0F4DB8 7F0C0248 2401000D */  li    $at, 13
/* 0F4DBC 7F0C024C 10410048 */  beq   $v0, $at, .Ljp7F0C0370
/* 0F4DC0 7F0C0250 00002025 */   move  $a0, $zero
/* 0F4DC4 7F0C0254 24010038 */  li    $at, 56
/* 0F4DC8 7F0C0258 54410074 */  bnel  $v0, $at, .Ljp7F0C042C
/* 0F4DCC 7F0C025C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4DD0 7F0C0260 0C0010EA */  jal   viGetHorizontalOffset
/* 0F4DD4 7F0C0264 00000000 */   nop
/* 0F4DD8 7F0C0268 0C0010E4 */  jal   viGet800232A0
/* 0F4DDC 7F0C026C AFA20030 */   sw    $v0, 0x30($sp)
/* 0F4DE0 7F0C0270 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0F4DE4 7F0C0274 00002025 */  move  $a0, $zero
/* 0F4DE8 7F0C0278 0C0030DC */  jal   joyGetButtons
/* 0F4DEC 7F0C027C 24050004 */   li    $a1, 4
/* 0F4DF0 7F0C0280 10400004 */  beqz  $v0, .Ljp7F0C0294
/* 0F4DF4 7F0C0284 00002025 */   move  $a0, $zero
/* 0F4DF8 7F0C0288 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0F4DFC 7F0C028C 25D90001 */  addiu $t9, $t6, 1
/* 0F4E00 7F0C0290 AFB9002C */  sw    $t9, 0x2c($sp)
.Ljp7F0C0294:
/* 0F4E04 7F0C0294 0C0030DC */  jal   joyGetButtons
/* 0F4E08 7F0C0298 24050008 */   li    $a1, 8
/* 0F4E0C 7F0C029C 10400004 */  beqz  $v0, .Ljp7F0C02B0
/* 0F4E10 7F0C02A0 00002025 */   move  $a0, $zero
/* 0F4E14 7F0C02A4 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0F4E18 7F0C02A8 270FFFFF */  addiu $t7, $t8, -1
/* 0F4E1C 7F0C02AC AFAF002C */  sw    $t7, 0x2c($sp)
.Ljp7F0C02B0:
/* 0F4E20 7F0C02B0 0C0030DC */  jal   joyGetButtons
/* 0F4E24 7F0C02B4 24050001 */   li    $a1, 1
/* 0F4E28 7F0C02B8 10400004 */  beqz  $v0, .Ljp7F0C02CC
/* 0F4E2C 7F0C02BC 00002025 */   move  $a0, $zero
/* 0F4E30 7F0C02C0 8FAE0030 */  lw    $t6, 0x30($sp)
/* 0F4E34 7F0C02C4 25D90001 */  addiu $t9, $t6, 1
/* 0F4E38 7F0C02C8 AFB90030 */  sw    $t9, 0x30($sp)
.Ljp7F0C02CC:
/* 0F4E3C 7F0C02CC 0C0030DC */  jal   joyGetButtons
/* 0F4E40 7F0C02D0 24050002 */   li    $a1, 2
/* 0F4E44 7F0C02D4 10400003 */  beqz  $v0, .Ljp7F0C02E4
/* 0F4E48 7F0C02D8 8FB80030 */   lw    $t8, 0x30($sp)
/* 0F4E4C 7F0C02DC 270FFFFF */  addiu $t7, $t8, -1
/* 0F4E50 7F0C02E0 AFAF0030 */  sw    $t7, 0x30($sp)
.Ljp7F0C02E4:
/* 0F4E54 7F0C02E4 0C0010E7 */  jal   viSetHorizontalOffset
/* 0F4E58 7F0C02E8 8FA40030 */   lw    $a0, 0x30($sp)
/* 0F4E5C 7F0C02EC 0C0010E1 */  jal   viSet800232A0
/* 0F4E60 7F0C02F0 8FA4002C */   lw    $a0, 0x2c($sp)
/* 0F4E64 7F0C02F4 1000004D */  b     .Ljp7F0C042C
/* 0F4E68 7F0C02F8 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C02FC:
/* 0F4E6C 7F0C02FC 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4E70 7F0C0300 24050202 */   li    $a1, 514
/* 0F4E74 7F0C0304 50400004 */  beql  $v0, $zero, .Ljp7F0C0318
/* 0F4E78 7F0C0308 00002025 */   move  $a0, $zero
/* 0F4E7C 7F0C030C 0FC2F97A */  jal   lvlMusicAppendPlayEndTheme
/* 0F4E80 7F0C0310 00000000 */   nop
/* 0F4E84 7F0C0314 00002025 */  move  $a0, $zero
.Ljp7F0C0318:
/* 0F4E88 7F0C0318 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4E8C 7F0C031C 24050101 */   li    $a1, 257
/* 0F4E90 7F0C0320 50400004 */  beql  $v0, $zero, .Ljp7F0C0334
/* 0F4E94 7F0C0324 00002025 */   move  $a0, $zero
/* 0F4E98 7F0C0328 0FC2F967 */  jal   lvlMusicAppendPlaySoloDeathShort
/* 0F4E9C 7F0C032C 00000000 */   nop
/* 0F4EA0 7F0C0330 00002025 */  move  $a0, $zero
.Ljp7F0C0334:
/* 0F4EA4 7F0C0334 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4EA8 7F0C0338 24050400 */   li    $a1, 1024
/* 0F4EAC 7F0C033C 50400004 */  beql  $v0, $zero, .Ljp7F0C0350
/* 0F4EB0 7F0C0340 00002025 */   move  $a0, $zero
/* 0F4EB4 7F0C0344 0C001BF8 */  jal   musicTrack1Stop
/* 0F4EB8 7F0C0348 00000000 */   nop
/* 0F4EBC 7F0C034C 00002025 */  move  $a0, $zero
.Ljp7F0C0350:
/* 0F4EC0 7F0C0350 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4EC4 7F0C0354 24054000 */   li    $a1, 16384
/* 0F4EC8 7F0C0358 50400034 */  beql  $v0, $zero, .Ljp7F0C042C
/* 0F4ECC 7F0C035C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4ED0 7F0C0360 0C001C2C */  jal   musicTrack1SaveCurrentVolumeAsTrackDefault
/* 0F4ED4 7F0C0364 00000000 */   nop
/* 0F4ED8 7F0C0368 10000030 */  b     .Ljp7F0C042C
/* 0F4EDC 7F0C036C 8FBF0014 */   lw    $ra, 0x14($sp)
.Ljp7F0C0370:
/* 0F4EE0 7F0C0370 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4EE4 7F0C0374 24050622 */   li    $a1, 1570
/* 0F4EE8 7F0C0378 1040000B */  beqz  $v0, .Ljp7F0C03A8
/* 0F4EEC 7F0C037C 3C058005 */   lui   $a1, 0x8005
/* 0F4EF0 7F0C0380 84A58418 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F4EF4 7F0C0384 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8006
/* 0F4EF8 7F0C0388 3C018005 */  lui   $at, %hi(g_DebugMpGameSoundFxIndex) # $at, 0x8005
/* 0F4EFC 7F0C038C 24A5FFFF */  addiu $a1, $a1, -1
/* 0F4F00 7F0C0390 00057400 */  sll   $t6, $a1, 0x10
/* 0F4F04 7F0C0394 000E2C03 */  sra   $a1, $t6, 0x10
/* 0F4F08 7F0C0398 A4258418 */  sh    $a1, %lo(g_DebugMpGameSoundFxIndex)($at)
/* 0F4F0C 7F0C039C 8C843760 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F4F10 7F0C03A0 0C002386 */  jal   sndPlaySfx
/* 0F4F14 7F0C03A4 00003025 */   move  $a2, $zero
.Ljp7F0C03A8:
/* 0F4F18 7F0C03A8 00002025 */  move  $a0, $zero
/* 0F4F1C 7F0C03AC 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4F20 7F0C03B0 24050911 */   li    $a1, 2321
/* 0F4F24 7F0C03B4 1040000B */  beqz  $v0, .Ljp7F0C03E4
/* 0F4F28 7F0C03B8 3C058005 */   lui   $a1, 0x8005
/* 0F4F2C 7F0C03BC 84A58418 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F4F30 7F0C03C0 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8006
/* 0F4F34 7F0C03C4 3C018005 */  lui   $at, %hi(g_DebugMpGameSoundFxIndex) # $at, 0x8005
/* 0F4F38 7F0C03C8 24A50001 */  addiu $a1, $a1, 1
/* 0F4F3C 7F0C03CC 0005C400 */  sll   $t8, $a1, 0x10
/* 0F4F40 7F0C03D0 00182C03 */  sra   $a1, $t8, 0x10
/* 0F4F44 7F0C03D4 A4258418 */  sh    $a1, %lo(g_DebugMpGameSoundFxIndex)($at)
/* 0F4F48 7F0C03D8 8C843760 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F4F4C 7F0C03DC 0C002386 */  jal   sndPlaySfx
/* 0F4F50 7F0C03E0 00003025 */   move  $a2, $zero
.Ljp7F0C03E4:
/* 0F4F54 7F0C03E4 00002025 */  move  $a0, $zero
/* 0F4F58 7F0C03E8 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4F5C 7F0C03EC 24050004 */   li    $a1, 4
/* 0F4F60 7F0C03F0 50400004 */  beql  $v0, $zero, .Ljp7F0C0404
/* 0F4F64 7F0C03F4 00002025 */   move  $a0, $zero
/* 0F4F68 7F0C03F8 0C00244D */  jal   sndDeactivateAllSfxByFlag_1
/* 0F4F6C 7F0C03FC 00000000 */   nop
/* 0F4F70 7F0C0400 00002025 */  move  $a0, $zero
.Ljp7F0C0404:
/* 0F4F74 7F0C0404 0C003104 */  jal   joyGetButtonsPressedThisFrame
/* 0F4F78 7F0C0408 24050008 */   li    $a1, 8
/* 0F4F7C 7F0C040C 10400006 */  beqz  $v0, .Ljp7F0C0428
/* 0F4F80 7F0C0410 3C058005 */   lui   $a1, %hi(g_DebugMpGameSoundFxIndex) # $a1, 0x8005
/* 0F4F84 7F0C0414 3C048006 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8006
/* 0F4F88 7F0C0418 8C843760 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F4F8C 7F0C041C 84A58418 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F4F90 7F0C0420 0C002386 */  jal   sndPlaySfx
/* 0F4F94 7F0C0424 00003025 */   move  $a2, $zero
.Ljp7F0C0428:
/* 0F4F98 7F0C0428 8FBF0014 */  lw    $ra, 0x14($sp)
.Ljp7F0C042C:
/* 0F4F9C 7F0C042C 27BD0198 */  addiu $sp, $sp, 0x198
/* 0F4FA0 7F0C0430 03E00008 */  jr    $ra
/* 0F4FA4 7F0C0434 00000000 */   nop
)
#endif

#ifdef VERSION_EU
GLOBAL_ASM(
.late_rodata
glabel D_80050308
.word 0x3f99999a
.text
glabel lvlManageMpGame
/* 0F099C 7F0BDFAC 27BDFE68 */  addiu $sp, $sp, -0x198
/* 0F09A0 7F0BDFB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F09A4 7F0BDFB4 0C000744 */  jal   tlbmanageResetCurrentEntriesCount
/* 0F09A8 7F0BDFB8 00000000 */   nop   
/* 0F09AC 7F0BDFBC 3C0E8004 */  lui   $t6, %hi(g_ControlsLockedFlag) # $t6, 0x8004
/* 0F09B0 7F0BDFC0 8DCE0FF0 */  lw    $t6, %lo(g_ControlsLockedFlag)($t6)
/* 0F09B4 7F0BDFC4 3C018004 */  lui   $at, %hi(g_ClockTimer) # $at, 0x8004
/* 0F09B8 7F0BDFC8 11C00003 */  beqz  $t6, .L7F0BDFD8
/* 0F09BC 7F0BDFCC 00000000 */   nop   
/* 0F09C0 7F0BDFD0 10000010 */  b     .L7F0BE014
/* 0F09C4 7F0BDFD4 AC200FF4 */   sw    $zero, %lo(g_ClockTimer)($at)
.L7F0BDFD8:
/* 0F09C8 7F0BDFD8 0FC31565 */  jal   checkGamePaused
/* 0F09CC 7F0BDFDC 00000000 */   nop   
/* 0F09D0 7F0BDFE0 10400004 */  beqz  $v0, .L7F0BDFF4
/* 0F09D4 7F0BDFE4 3C0F8004 */   lui   $t7, %hi(speedgraphframes) # $t7, 0x8004
/* 0F09D8 7F0BDFE8 3C018004 */  lui   $at, %hi(g_ClockTimer) # $at, 0x8004
/* 0F09DC 7F0BDFEC 10000009 */  b     .L7F0BE014
/* 0F09E0 7F0BDFF0 AC200FF4 */   sw    $zero, %lo(g_ClockTimer)($at)
.L7F0BDFF4:
/* 0F09E4 7F0BDFF4 8DEF1118 */  lw    $t7, %lo(speedgraphframes)($t7)
/* 0F09E8 7F0BDFF8 3C028004 */  lui   $v0, %hi(D_80048380) # $v0, 0x8004
/* 0F09EC 7F0BDFFC 3C018004 */  lui   $at, %hi(g_ClockTimer) # $at, 0x8004
/* 0F09F0 7F0BE000 24421000 */  addiu $v0, %lo(D_80048380) # addiu $v0, $v0, 0x1000
/* 0F09F4 7F0BE004 AC2F0FF4 */  sw    $t7, %lo(g_ClockTimer)($at)
/* 0F09F8 7F0BE008 8C580000 */  lw    $t8, ($v0)
/* 0F09FC 7F0BE00C 27190001 */  addiu $t9, $t8, 1
/* 0F0A00 7F0BE010 AC590000 */  sw    $t9, ($v0)
.L7F0BE014:
/* 0F0A04 7F0BE014 3C028004 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8004
/* 0F0A08 7F0BE018 8C420FF4 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F0A0C 7F0BE01C 3C038004 */  lui   $v1, %hi(g_JP_GlobalTimerDelta) # $v1, 0x8004
/* 0F0A10 7F0BE020 24630FF8 */  addiu $v1, %lo(g_JP_GlobalTimerDelta) # addiu $v1, $v1, 0xff8
/* 0F0A14 7F0BE024 44822000 */  mtc1  $v0, $f4
/* 0F0A18 7F0BE028 3C018005 */  lui   $at, %hi(D_80050308) # $at, 0x8005
/* 0F0A1C 7F0BE02C 3C048004 */  lui   $a0, %hi(g_GlobalTimer) # $a0, 0x8004
/* 0F0A20 7F0BE030 468021A0 */  cvt.s.w $f6, $f4
/* 0F0A24 7F0BE034 24840FFC */  addiu $a0, %lo(g_GlobalTimer) # addiu $a0, $a0, 0xffc
/* 0F0A28 7F0BE038 3C188004 */  lui   $t8, %hi(g_CurrentStageToLoad) # $t8, 0x8004
/* 0F0A2C 7F0BE03C 3C198004 */  lui   $t9, %hi(D_80048394) # $t9, 0x8004
/* 0F0A30 7F0BE040 E4660000 */  swc1  $f6, ($v1)
/* 0F0A34 7F0BE044 C42A0308 */  lwc1  $f10, %lo(D_80050308)($at)
/* 0F0A38 7F0BE048 C4680000 */  lwc1  $f8, ($v1)
/* 0F0A3C 7F0BE04C 3C018004 */  lui   $at, %hi(g_GlobalTimerDelta) # $at, 0x8004
/* 0F0A40 7F0BE050 460A4402 */  mul.s $f16, $f8, $f10
/* 0F0A44 7F0BE054 E4301004 */  swc1  $f16, %lo(g_GlobalTimerDelta)($at)
/* 0F0A48 7F0BE058 8C8E0000 */  lw    $t6, ($a0)
/* 0F0A4C 7F0BE05C 2401005A */  li    $at, 90
/* 0F0A50 7F0BE060 01C27821 */  addu  $t7, $t6, $v0
/* 0F0A54 7F0BE064 AC8F0000 */  sw    $t7, ($a0)
/* 0F0A58 7F0BE068 8F180FE4 */  lw    $t8, %lo(g_CurrentStageToLoad)($t8)
/* 0F0A5C 7F0BE06C 1301001D */  beq   $t8, $at, .L7F0BE0E4
/* 0F0A60 7F0BE070 00000000 */   nop   
/* 0F0A64 7F0BE074 8F391018 */  lw    $t9, %lo(D_80048394)($t9)
/* 0F0A68 7F0BE078 1720001A */  bnez  $t9, .L7F0BE0E4
/* 0F0A6C 7F0BE07C 00000000 */   nop   
/* 0F0A70 7F0BE080 18400018 */  blez  $v0, .L7F0BE0E4
/* 0F0A74 7F0BE084 3C0E8002 */   lui   $t6, %hi(g_AppendCheatSinglePlayer) # $t6, 0x8002
/* 0F0A78 7F0BE088 8DCE5E50 */  lw    $t6, %lo(g_AppendCheatSinglePlayer)($t6)
/* 0F0A7C 7F0BE08C 3C038006 */  lui   $v1, %hi(g_CheatActivated + 1) # $v1, 0x8006
/* 0F0A80 7F0BE090 246385E1 */  addiu $v1, %lo(g_CheatActivated + 1) # addiu $v1, $v1, -0x7a1f
/* 0F0A84 7F0BE094 11C00013 */  beqz  $t6, .L7F0BE0E4
/* 0F0A88 7F0BE098 24040001 */   li    $a0, 1
.Leu7F0BE09C:
/* 0F0A8C 7F0BE09C 906F0000 */  lbu   $t7, ($v1)
/* 0F0A90 7F0BE0A0 51E0000D */  beql  $t7, $zero, .L7F0BE0D8
/* 0F0A94 7F0BE0A4 24840001 */   addiu $a0, $a0, 1
/* 0F0A98 7F0BE0A8 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F0A9C 7F0BE0AC 0FC243B7 */  jal   cheatIsEnemyRockets
/* 0F0AA0 7F0BE0B0 AFA40194 */   sw    $a0, 0x194($sp)
/* 0F0AA4 7F0BE0B4 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F0AA8 7F0BE0B8 14400006 */  bnez  $v0, .L7F0BE0D4
/* 0F0AAC 7F0BE0BC 8FA40194 */   lw    $a0, 0x194($sp)
/* 0F0AB0 7F0BE0C0 AFA3001C */  sw    $v1, 0x1c($sp)
/* 0F0AB4 7F0BE0C4 0FC243CB */  jal   cheatButtonTurnOnCheatForPlayers
/* 0F0AB8 7F0BE0C8 AFA40194 */   sw    $a0, 0x194($sp)
/* 0F0ABC 7F0BE0CC 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F0AC0 7F0BE0D0 8FA40194 */  lw    $a0, 0x194($sp)
.L7F0BE0D4:
/* 0F0AC4 7F0BE0D4 24840001 */  addiu $a0, $a0, 1
.L7F0BE0D8:
/* 0F0AC8 7F0BE0D8 2401004B */  li    $at, 75
/* 0F0ACC 7F0BE0DC 1481FFEF */  bne   $a0, $at, .Leu7F0BE09C
/* 0F0AD0 7F0BE0E0 24630001 */   addiu $v1, $v1, 1
.L7F0BE0E4:
/* 0F0AD4 7F0BE0E4 0FC26669 */  jal   getPlayerCount
/* 0F0AD8 7F0BE0E8 00000000 */   nop   
/* 0F0ADC 7F0BE0EC 28410002 */  slti  $at, $v0, 2
/* 0F0AE0 7F0BE0F0 1420014C */  bnez  $at, .L7F0BE624
/* 0F0AE4 7F0BE0F4 3C188004 */   lui   $t8, %hi(g_CurrentStageToLoad) # $t8, 0x8004
/* 0F0AE8 7F0BE0F8 8F180FE4 */  lw    $t8, %lo(g_CurrentStageToLoad)($t8)
/* 0F0AEC 7F0BE0FC 2401005A */  li    $at, 90
/* 0F0AF0 7F0BE100 13010148 */  beq   $t8, $at, .L7F0BE624
/* 0F0AF4 7F0BE104 00000000 */   nop   
/* 0F0AF8 7F0BE108 0FC3003C */  jal   get_mission_state
/* 0F0AFC 7F0BE10C 00000000 */   nop   
/* 0F0B00 7F0BE110 24010006 */  li    $at, 6
/* 0F0B04 7F0BE114 14410029 */  bne   $v0, $at, .L7F0BE1BC
/* 0F0B08 7F0BE118 00000000 */   nop   
/* 0F0B0C 7F0BE11C AFA00190 */  sw    $zero, 0x190($sp)
/* 0F0B10 7F0BE120 AFA0018C */  sw    $zero, 0x18c($sp)
/* 0F0B14 7F0BE124 0FC26669 */  jal   getPlayerCount
/* 0F0B18 7F0BE128 AFA00188 */   sw    $zero, 0x188($sp)
/* 0F0B1C 7F0BE12C 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F0B20 7F0BE130 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F0B24 7F0BE134 1840001B */  blez  $v0, .L7F0BE1A4
/* 0F0B28 7F0BE138 8FA60188 */   lw    $a2, 0x188($sp)
/* 0F0B2C 7F0BE13C 3C0E8007 */  lui   $t6, %hi(g_playerPointers) # $t6, 0x8007
/* 0F0B30 7F0BE140 25CE89F0 */  addiu $t6, %lo(g_playerPointers) # addiu $t6, $t6, -0x7610
/* 0F0B34 7F0BE144 0003C880 */  sll   $t9, $v1, 2
/* 0F0B38 7F0BE148 032E2021 */  addu  $a0, $t9, $t6
.L7F0BE14C:
/* 0F0B3C 7F0BE14C 8C820000 */  lw    $v0, ($a0)
/* 0F0B40 7F0BE150 24630001 */  addiu $v1, $v1, 1
/* 0F0B44 7F0BE154 24840004 */  addiu $a0, $a0, 4
/* 0F0B48 7F0BE158 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F0B4C 7F0BE15C 51E00007 */  beql  $t7, $zero, .L7F0BE17C
/* 0F0B50 7F0BE160 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F0B54 7F0BE164 8C580424 */  lw    $t8, 0x424($v0)
/* 0F0B58 7F0BE168 24A50001 */  addiu $a1, $a1, 1
/* 0F0B5C 7F0BE16C 53000003 */  beql  $t8, $zero, .L7F0BE17C
/* 0F0B60 7F0BE170 AFA30190 */   sw    $v1, 0x190($sp)
/* 0F0B64 7F0BE174 24C60001 */  addiu $a2, $a2, 1
/* 0F0B68 7F0BE178 AFA30190 */  sw    $v1, 0x190($sp)
.L7F0BE17C:
/* 0F0B6C 7F0BE17C AFA4001C */  sw    $a0, 0x1c($sp)
/* 0F0B70 7F0BE180 AFA5018C */  sw    $a1, 0x18c($sp)
/* 0F0B74 7F0BE184 0FC26669 */  jal   getPlayerCount
/* 0F0B78 7F0BE188 AFA60188 */   sw    $a2, 0x188($sp)
/* 0F0B7C 7F0BE18C 8FA30190 */  lw    $v1, 0x190($sp)
/* 0F0B80 7F0BE190 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0F0B84 7F0BE194 8FA5018C */  lw    $a1, 0x18c($sp)
/* 0F0B88 7F0BE198 0062082A */  slt   $at, $v1, $v0
/* 0F0B8C 7F0BE19C 1420FFEB */  bnez  $at, .L7F0BE14C
/* 0F0B90 7F0BE1A0 8FA60188 */   lw    $a2, 0x188($sp)
.L7F0BE1A4:
/* 0F0B94 7F0BE1A4 18A00005 */  blez  $a1, .L7F0BE1BC
/* 0F0B98 7F0BE1A8 00000000 */   nop   
/* 0F0B9C 7F0BE1AC 14A60003 */  bne   $a1, $a2, .L7F0BE1BC
/* 0F0BA0 7F0BE1B0 00000000 */   nop   
/* 0F0BA4 7F0BE1B4 0FC3003F */  jal   set_missionstate
/* 0F0BA8 7F0BE1B8 24040001 */   li    $a0, 1
.L7F0BE1BC:
/* 0F0BAC 7F0BE1BC 3C038004 */  lui   $v1, %hi(g_MpTime) # $v1, 0x8004
/* 0F0BB0 7F0BE1C0 8C63101C */  lw    $v1, %lo(g_MpTime)($v1)
/* 0F0BB4 7F0BE1C4 3C028004 */  lui   $v0, %hi(D_80048394) # $v0, 0x8004
/* 0F0BB8 7F0BE1C8 3C198004 */  lui   $t9, %hi(g_ClockTimer) # $t9, 0x8004
/* 0F0BBC 7F0BE1CC 1860004A */  blez  $v1, .Leu7F0BE2F8
/* 0F0BC0 7F0BE1D0 00000000 */   nop   
/* 0F0BC4 7F0BE1D4 8C421018 */  lw    $v0, %lo(D_80048394)($v0)
/* 0F0BC8 7F0BE1D8 8F390FF4 */  lw    $t9, %lo(g_ClockTimer)($t9)
/* 0F0BCC 7F0BE1DC 2464F448 */  addiu $a0, $v1, -0xbb8
/* 0F0BD0 7F0BE1E0 0044082A */  slt   $at, $v0, $a0
/* 0F0BD4 7F0BE1E4 03227021 */  addu  $t6, $t9, $v0
/* 0F0BD8 7F0BE1E8 AFAE0180 */  sw    $t6, 0x180($sp)
/* 0F0BDC 7F0BE1EC 10200016 */  beqz  $at, .L7F0BE248
/* 0F0BE0 7F0BE1F0 AFA20184 */   sw    $v0, 0x184($sp)
/* 0F0BE4 7F0BE1F4 01C4082A */  slt   $at, $t6, $a0
/* 0F0BE8 7F0BE1F8 14200013 */  bnez  $at, .L7F0BE248
/* 0F0BEC 7F0BE1FC 00000000 */   nop   
/* 0F0BF0 7F0BE200 0FC26669 */  jal   getPlayerCount
/* 0F0BF4 7F0BE204 AFA0017C */   sw    $zero, 0x17c($sp)
/* 0F0BF8 7F0BE208 1840000F */  blez  $v0, .L7F0BE248
/* 0F0BFC 7F0BE20C 00000000 */   nop   
.L7F0BE210:
/* 0F0C00 7F0BE210 0FC26993 */  jal   set_cur_player
/* 0F0C04 7F0BE214 8FA4017C */   lw    $a0, 0x17c($sp)
/* 0F0C08 7F0BE218 0FC304AE */  jal   langGet
/* 0F0C0C 7F0BE21C 3404B044 */   li    $a0, 45124
/* 0F0C10 7F0BE220 0FC229B5 */  jal   jp_hudmsgBottomShow
/* 0F0C14 7F0BE224 00402025 */   move  $a0, $v0
/* 0F0C18 7F0BE228 8FAF017C */  lw    $t7, 0x17c($sp)
/* 0F0C1C 7F0BE22C 25F80001 */  addiu $t8, $t7, 1
/* 0F0C20 7F0BE230 0FC26669 */  jal   getPlayerCount
/* 0F0C24 7F0BE234 AFB8017C */   sw    $t8, 0x17c($sp)
/* 0F0C28 7F0BE238 8FB9017C */  lw    $t9, 0x17c($sp)
/* 0F0C2C 7F0BE23C 0322082A */  slt   $at, $t9, $v0
/* 0F0C30 7F0BE240 1420FFF3 */  bnez  $at, .L7F0BE210
/* 0F0C34 7F0BE244 00000000 */   nop   
.L7F0BE248:
/* 0F0C38 7F0BE248 3C0F8004 */  lui   $t7, %hi(g_MpTime) # $t7, 0x8004
/* 0F0C3C 7F0BE24C 8DEF101C */  lw    $t7, %lo(g_MpTime)($t7)
/* 0F0C40 7F0BE250 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F0C44 7F0BE254 3C198004 */  lui   $t9, %hi(g_MpSoundStateRelated) # $t9, 0x8004
/* 0F0C48 7F0BE258 25F8FE0C */  addiu $t8, $t7, -0x1f4
/* 0F0C4C 7F0BE25C 01D8082A */  slt   $at, $t6, $t8
/* 0F0C50 7F0BE260 1420000D */  bnez  $at, .L7F0BE298
/* 0F0C54 7F0BE264 00000000 */   nop   
/* 0F0C58 7F0BE268 8F391024 */  lw    $t9, %lo(g_MpSoundStateRelated)($t9)
/* 0F0C5C 7F0BE26C 1720000A */  bnez  $t9, .L7F0BE298
/* 0F0C60 7F0BE270 00000000 */   nop   
/* 0F0C64 7F0BE274 0FC2FC1E */  jal   lvlGetControlsLockedFlag
/* 0F0C68 7F0BE278 00000000 */   nop   
/* 0F0C6C 7F0BE27C 14400006 */  bnez  $v0, .L7F0BE298
/* 0F0C70 7F0BE280 3C048005 */   lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0F0C74 7F0BE284 3C068004 */  lui   $a2, %hi(g_MpSoundStateRelated) # $a2, 0x8004
/* 0F0C78 7F0BE288 24C61024 */  addiu $a2, %lo(g_MpSoundStateRelated) # addiu $a2, $a2, 0x1024
/* 0F0C7C 7F0BE28C 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F0C80 7F0BE290 0C00209A */  jal   sndPlaySfx
/* 0F0C84 7F0BE294 240500A1 */   li    $a1, 161
.L7F0BE298:
/* 0F0C88 7F0BE298 0FC2FC1E */  jal   lvlGetControlsLockedFlag
/* 0F0C8C 7F0BE29C 00000000 */   nop   
/* 0F0C90 7F0BE2A0 1040000A */  beqz  $v0, .L7F0BE2CC
/* 0F0C94 7F0BE2A4 3C048004 */   lui   $a0, %hi(g_MpSoundStateRelated) # $a0, 0x8004
/* 0F0C98 7F0BE2A8 8C841024 */  lw    $a0, %lo(g_MpSoundStateRelated)($a0)
/* 0F0C9C 7F0BE2AC 10800007 */  beqz  $a0, .L7F0BE2CC
/* 0F0CA0 7F0BE2B0 00000000 */   nop   
/* 0F0CA4 7F0BE2B4 0C002094 */  jal   sndGetPlayingState
/* 0F0CA8 7F0BE2B8 00000000 */   nop   
/* 0F0CAC 7F0BE2BC 10400003 */  beqz  $v0, .L7F0BE2CC
/* 0F0CB0 7F0BE2C0 3C048004 */   lui   $a0, %hi(g_MpSoundStateRelated) # $a0, 0x8004
/* 0F0CB4 7F0BE2C4 0C002120 */  jal   sndDeactivate
/* 0F0CB8 7F0BE2C8 8C841024 */   lw    $a0, %lo(g_MpSoundStateRelated)($a0)
.L7F0BE2CC:
/* 0F0CBC 7F0BE2CC 3C038004 */  lui   $v1, %hi(g_MpTime) # $v1, 0x8004
/* 0F0CC0 7F0BE2D0 8C63101C */  lw    $v1, %lo(g_MpTime)($v1)
/* 0F0CC4 7F0BE2D4 8FAF0184 */  lw    $t7, 0x184($sp)
/* 0F0CC8 7F0BE2D8 8FAE0180 */  lw    $t6, 0x180($sp)
/* 0F0CCC 7F0BE2DC 01E3082A */  slt   $at, $t7, $v1
/* 0F0CD0 7F0BE2E0 10200005 */  beqz  $at, .Leu7F0BE2F8
/* 0F0CD4 7F0BE2E4 01C3082A */   slt   $at, $t6, $v1
/* 0F0CD8 7F0BE2E8 14200003 */  bnez  $at, .Leu7F0BE2F8
/* 0F0CDC 7F0BE2EC 00000000 */   nop   
/* 0F0CE0 7F0BE2F0 0FC30684 */  jal   mpCalculateAwards
/* 0F0CE4 7F0BE2F4 00002025 */   move  $a0, $zero
.Leu7F0BE2F8:
/* 0F0CE8 7F0BE2F8 3C188004 */  lui   $t8, %hi(g_MpPoint) # $t8, 0x8004
/* 0F0CEC 7F0BE2FC 8F181020 */  lw    $t8, %lo(g_MpPoint)($t8)
/* 0F0CF0 7F0BE300 3C198004 */  lui   $t9, %hi(g_ClockTimer) # $t9, 0x8004
/* 0F0CF4 7F0BE304 1B00003D */  blez  $t8, .L7F0BE3FC
/* 0F0CF8 7F0BE308 00000000 */   nop   
/* 0F0CFC 7F0BE30C 8F390FF4 */  lw    $t9, %lo(g_ClockTimer)($t9)
/* 0F0D00 7F0BE310 1320003A */  beqz  $t9, .L7F0BE3FC
/* 0F0D04 7F0BE314 00000000 */   nop   
/* 0F0D08 7F0BE318 0FC26669 */  jal   getPlayerCount
/* 0F0D0C 7F0BE31C 00000000 */   nop   
/* 0F0D10 7F0BE320 00403825 */  move  $a3, $v0
/* 0F0D14 7F0BE324 00002825 */  move  $a1, $zero
/* 0F0D18 7F0BE328 00003025 */  move  $a2, $zero
/* 0F0D1C 7F0BE32C 18400029 */  blez  $v0, .L7F0BE3D4
/* 0F0D20 7F0BE330 00002025 */   move  $a0, $zero
/* 0F0D24 7F0BE334 3C038007 */  lui   $v1, %hi(g_playerPointers) # $v1, 0x8007
/* 0F0D28 7F0BE338 44800000 */  mtc1  $zero, $f0
/* 0F0D2C 7F0BE33C 246389F0 */  addiu $v1, %lo(g_playerPointers) # addiu $v1, $v1, -0x7610
.L7F0BE340:
/* 0F0D30 7F0BE340 8C620000 */  lw    $v0, ($v1)
/* 0F0D34 7F0BE344 8C4F00D8 */  lw    $t7, 0xd8($v0)
/* 0F0D38 7F0BE348 51E0000E */  beql  $t7, $zero, .L7F0BE384
/* 0F0D3C 7F0BE34C AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F0D40 7F0BE350 8C4E0424 */  lw    $t6, 0x424($v0)
/* 0F0D44 7F0BE354 51C0000A */  beql  $t6, $zero, .L7F0BE380
/* 0F0D48 7F0BE358 24A50001 */   addiu $a1, $a1, 1
/* 0F0D4C 7F0BE35C 8C580428 */  lw    $t8, 0x428($v0)
/* 0F0D50 7F0BE360 53000007 */  beql  $t8, $zero, .L7F0BE380
/* 0F0D54 7F0BE364 24A50001 */   addiu $a1, $a1, 1
/* 0F0D58 7F0BE368 C45203E4 */  lwc1  $f18, 0x3e4($v0)
/* 0F0D5C 7F0BE36C 4612003E */  c.le.s $f0, $f18
/* 0F0D60 7F0BE370 00000000 */  nop   
/* 0F0D64 7F0BE374 45020003 */  bc1fl .L7F0BE384
/* 0F0D68 7F0BE378 AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F0D6C 7F0BE37C 24A50001 */  addiu $a1, $a1, 1
.L7F0BE380:
/* 0F0D70 7F0BE380 AFA3001C */  sw    $v1, 0x1c($sp)
.L7F0BE384:
/* 0F0D74 7F0BE384 AFA40174 */  sw    $a0, 0x174($sp)
/* 0F0D78 7F0BE388 AFA50170 */  sw    $a1, 0x170($sp)
/* 0F0D7C 7F0BE38C AFA6016C */  sw    $a2, 0x16c($sp)
/* 0F0D80 7F0BE390 0FC30B6E */  jal   get_points_for_mp_player
/* 0F0D84 7F0BE394 AFA70178 */   sw    $a3, 0x178($sp)
/* 0F0D88 7F0BE398 3C198004 */  lui   $t9, %hi(g_MpPoint) # $t9, 0x8004
/* 0F0D8C 7F0BE39C 8F391020 */  lw    $t9, %lo(g_MpPoint)($t9)
/* 0F0D90 7F0BE3A0 44800000 */  mtc1  $zero, $f0
/* 0F0D94 7F0BE3A4 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F0D98 7F0BE3A8 0059082A */  slt   $at, $v0, $t9
/* 0F0D9C 7F0BE3AC 8FA40174 */  lw    $a0, 0x174($sp)
/* 0F0DA0 7F0BE3B0 8FA50170 */  lw    $a1, 0x170($sp)
/* 0F0DA4 7F0BE3B4 8FA6016C */  lw    $a2, 0x16c($sp)
/* 0F0DA8 7F0BE3B8 14200002 */  bnez  $at, .L7F0BE3C4
/* 0F0DAC 7F0BE3BC 8FA70178 */   lw    $a3, 0x178($sp)
/* 0F0DB0 7F0BE3C0 24C60001 */  addiu $a2, $a2, 1
.L7F0BE3C4:
/* 0F0DB4 7F0BE3C4 24840001 */  addiu $a0, $a0, 1
/* 0F0DB8 7F0BE3C8 0087082A */  slt   $at, $a0, $a3
/* 0F0DBC 7F0BE3CC 1420FFDC */  bnez  $at, .L7F0BE340
/* 0F0DC0 7F0BE3D0 24630004 */   addiu $v1, $v1, 4
.L7F0BE3D4:
/* 0F0DC4 7F0BE3D4 18C00009 */  blez  $a2, .L7F0BE3FC
/* 0F0DC8 7F0BE3D8 00000000 */   nop   
/* 0F0DCC 7F0BE3DC 14A00005 */  bnez  $a1, .L7F0BE3F4
/* 0F0DD0 7F0BE3E0 00000000 */   nop   
/* 0F0DD4 7F0BE3E4 0FC30684 */  jal   mpCalculateAwards
/* 0F0DD8 7F0BE3E8 00002025 */   move  $a0, $zero
/* 0F0DDC 7F0BE3EC 10000003 */  b     .L7F0BE3FC
/* 0F0DE0 7F0BE3F0 00000000 */   nop   
.L7F0BE3F4:
/* 0F0DE4 7F0BE3F4 0FC30680 */  jal   mpwatchSetStopPlayFlag
/* 0F0DE8 7F0BE3F8 00000000 */   nop   
.L7F0BE3FC:
/* 0F0DEC 7F0BE3FC 0FC051B2 */  jal   get_scenario
/* 0F0DF0 7F0BE400 00000000 */   nop   
/* 0F0DF4 7F0BE404 24010001 */  li    $at, 1
/* 0F0DF8 7F0BE408 14410086 */  bne   $v0, $at, .L7F0BE624
/* 0F0DFC 7F0BE40C 3C0F8004 */   lui   $t7, %hi(g_ClockTimer) # $t7, 0x8004
/* 0F0E00 7F0BE410 8DEF0FF4 */  lw    $t7, %lo(g_ClockTimer)($t7)
/* 0F0E04 7F0BE414 11E00083 */  beqz  $t7, .L7F0BE624
/* 0F0E08 7F0BE418 00000000 */   nop   
/* 0F0E0C 7F0BE41C 0FC26669 */  jal   getPlayerCount
/* 0F0E10 7F0BE420 00000000 */   nop   
/* 0F0E14 7F0BE424 44800000 */  mtc1  $zero, $f0
/* 0F0E18 7F0BE428 00405025 */  move  $t2, $v0
/* 0F0E1C 7F0BE42C 00006825 */  move  $t5, $zero
/* 0F0E20 7F0BE430 0000F825 */  move  $ra, $zero
/* 0F0E24 7F0BE434 1840006E */  blez  $v0, .L7F0BE5F0
/* 0F0E28 7F0BE438 00006025 */   move  $t4, $zero
/* 0F0E2C 7F0BE43C 00002825 */  move  $a1, $zero
.L7F0BE440:
/* 0F0E30 7F0BE440 00003025 */  move  $a2, $zero
/* 0F0E34 7F0BE444 18400048 */  blez  $v0, .L7F0BE568
/* 0F0E38 7F0BE448 00003825 */   move  $a3, $zero
/* 0F0E3C 7F0BE44C 30490003 */  andi  $t1, $v0, 3
/* 0F0E40 7F0BE450 11200019 */  beqz  $t1, .L7F0BE4B8
/* 0F0E44 7F0BE454 000C5880 */   sll   $t3, $t4, 2
/* 0F0E48 7F0BE458 3C188007 */  lui   $t8, %hi(g_playerPointers) # $t8, 0x8007
/* 0F0E4C 7F0BE45C 271889F0 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x7610
/* 0F0E50 7F0BE460 00007080 */  sll   $t6, $zero, 2
/* 0F0E54 7F0BE464 0000C8C0 */  sll   $t9, $zero, 3
/* 0F0E58 7F0BE468 0320C823 */  subu  $t9, $t9, $zero
/* 0F0E5C 7F0BE46C 01D81821 */  addu  $v1, $t6, $t8
/* 0F0E60 7F0BE470 3C0E8007 */  lui   $t6, %hi(g_playerPlayerData) # $t6, 0x8007
/* 0F0E64 7F0BE474 0019C900 */  sll   $t9, $t9, 4
/* 0F0E68 7F0BE478 032B7821 */  addu  $t7, $t9, $t3
/* 0F0E6C 7F0BE47C 25CE8A00 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x7600
/* 0F0E70 7F0BE480 01EE2021 */  addu  $a0, $t7, $t6
/* 0F0E74 7F0BE484 01204025 */  move  $t0, $t1
.L7F0BE488:
/* 0F0E78 7F0BE488 8C780000 */  lw    $t8, ($v1)
/* 0F0E7C 7F0BE48C 24E70001 */  addiu $a3, $a3, 1
/* 0F0E80 7F0BE490 24630004 */  addiu $v1, $v1, 4
/* 0F0E84 7F0BE494 8F1900D8 */  lw    $t9, 0xd8($t8)
/* 0F0E88 7F0BE498 57200003 */  bnezl $t9, .L7F0BE4A8
/* 0F0E8C 7F0BE49C 8C8F0024 */   lw    $t7, 0x24($a0)
/* 0F0E90 7F0BE4A0 24C60001 */  addiu $a2, $a2, 1
/* 0F0E94 7F0BE4A4 8C8F0024 */  lw    $t7, 0x24($a0)
.L7F0BE4A8:
/* 0F0E98 7F0BE4A8 24840070 */  addiu $a0, $a0, 0x70
/* 0F0E9C 7F0BE4AC 1507FFF6 */  bne   $t0, $a3, .L7F0BE488
/* 0F0EA0 7F0BE4B0 00AF2821 */   addu  $a1, $a1, $t7
/* 0F0EA4 7F0BE4B4 10E2002C */  beq   $a3, $v0, .L7F0BE568
.L7F0BE4B8:
/* 0F0EA8 7F0BE4B8 3C188007 */   lui   $t8, %hi(g_playerPointers) # $t8, 0x8007
/* 0F0EAC 7F0BE4BC 0007C8C0 */  sll   $t9, $a3, 3
/* 0F0EB0 7F0BE4C0 0327C823 */  subu  $t9, $t9, $a3
/* 0F0EB4 7F0BE4C4 271889F0 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x7610
/* 0F0EB8 7F0BE4C8 00077080 */  sll   $t6, $a3, 2
/* 0F0EBC 7F0BE4CC 01D81821 */  addu  $v1, $t6, $t8
/* 0F0EC0 7F0BE4D0 0019C900 */  sll   $t9, $t9, 4
/* 0F0EC4 7F0BE4D4 032B7821 */  addu  $t7, $t9, $t3
/* 0F0EC8 7F0BE4D8 3C0E8007 */  lui   $t6, %hi(g_playerPlayerData) # $t6, 0x8007
/* 0F0ECC 7F0BE4DC 25CE8A00 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x7600
/* 0F0ED0 7F0BE4E0 000AC880 */  sll   $t9, $t2, 2
/* 0F0ED4 7F0BE4E4 03384021 */  addu  $t0, $t9, $t8
/* 0F0ED8 7F0BE4E8 01EE2021 */  addu  $a0, $t7, $t6
.L7F0BE4EC:
/* 0F0EDC 7F0BE4EC 8C6F0000 */  lw    $t7, ($v1)
/* 0F0EE0 7F0BE4F0 8DEE00D8 */  lw    $t6, 0xd8($t7)
/* 0F0EE4 7F0BE4F4 55C00003 */  bnezl $t6, .L7F0BE504
/* 0F0EE8 7F0BE4F8 8C780004 */   lw    $t8, 4($v1)
/* 0F0EEC 7F0BE4FC 24C60001 */  addiu $a2, $a2, 1
/* 0F0EF0 7F0BE500 8C780004 */  lw    $t8, 4($v1)
.L7F0BE504:
/* 0F0EF4 7F0BE504 8C990024 */  lw    $t9, 0x24($a0)
/* 0F0EF8 7F0BE508 8F0F00D8 */  lw    $t7, 0xd8($t8)
/* 0F0EFC 7F0BE50C 00B92821 */  addu  $a1, $a1, $t9
/* 0F0F00 7F0BE510 55E00003 */  bnezl $t7, .L7F0BE520
/* 0F0F04 7F0BE514 8C790008 */   lw    $t9, 8($v1)
/* 0F0F08 7F0BE518 24C60001 */  addiu $a2, $a2, 1
/* 0F0F0C 7F0BE51C 8C790008 */  lw    $t9, 8($v1)
.L7F0BE520:
/* 0F0F10 7F0BE520 8C8E0094 */  lw    $t6, 0x94($a0)
/* 0F0F14 7F0BE524 8F3800D8 */  lw    $t8, 0xd8($t9)
/* 0F0F18 7F0BE528 00AE2821 */  addu  $a1, $a1, $t6
/* 0F0F1C 7F0BE52C 57000003 */  bnezl $t8, .L7F0BE53C
/* 0F0F20 7F0BE530 8C6E000C */   lw    $t6, 0xc($v1)
/* 0F0F24 7F0BE534 24C60001 */  addiu $a2, $a2, 1
/* 0F0F28 7F0BE538 8C6E000C */  lw    $t6, 0xc($v1)
.L7F0BE53C:
/* 0F0F2C 7F0BE53C 8C8F0104 */  lw    $t7, 0x104($a0)
/* 0F0F30 7F0BE540 24630010 */  addiu $v1, $v1, 0x10
/* 0F0F34 7F0BE544 8DD900D8 */  lw    $t9, 0xd8($t6)
/* 0F0F38 7F0BE548 00AF2821 */  addu  $a1, $a1, $t7
/* 0F0F3C 7F0BE54C 57200003 */  bnezl $t9, .L7F0BE55C
/* 0F0F40 7F0BE550 8C980174 */   lw    $t8, 0x174($a0)
/* 0F0F44 7F0BE554 24C60001 */  addiu $a2, $a2, 1
/* 0F0F48 7F0BE558 8C980174 */  lw    $t8, 0x174($a0)
.L7F0BE55C:
/* 0F0F4C 7F0BE55C 248401C0 */  addiu $a0, $a0, 0x1c0
/* 0F0F50 7F0BE560 1468FFE2 */  bne   $v1, $t0, .L7F0BE4EC
/* 0F0F54 7F0BE564 00B82821 */   addu  $a1, $a1, $t8
.L7F0BE568:
/* 0F0F58 7F0BE568 28A10002 */  slti  $at, $a1, 2
/* 0F0F5C 7F0BE56C 1420001C */  bnez  $at, .L7F0BE5E0
/* 0F0F60 7F0BE570 000C78C0 */   sll   $t7, $t4, 3
/* 0F0F64 7F0BE574 01EC7823 */  subu  $t7, $t7, $t4
/* 0F0F68 7F0BE578 3C0E8007 */  lui   $t6, %hi(g_playerPlayerData) # $t6, 0x8007
/* 0F0F6C 7F0BE57C 25CE8A00 */  addiu $t6, %lo(g_playerPlayerData) # addiu $t6, $t6, -0x7600
/* 0F0F70 7F0BE580 000F7900 */  sll   $t7, $t7, 4
/* 0F0F74 7F0BE584 01EE1821 */  addu  $v1, $t7, $t6
/* 0F0F78 7F0BE588 906F0068 */  lbu   $t7, 0x68($v1)
/* 0F0F7C 7F0BE58C 3C188007 */  lui   $t8, %hi(g_playerPointers) # $t8, 0x8007
/* 0F0F80 7F0BE590 271889F0 */  addiu $t8, %lo(g_playerPointers) # addiu $t8, $t8, -0x7610
/* 0F0F84 7F0BE594 000CC880 */  sll   $t9, $t4, 2
/* 0F0F88 7F0BE598 15E00003 */  bnez  $t7, .L7F0BE5A8
/* 0F0F8C 7F0BE59C 03382021 */   addu  $a0, $t9, $t8
/* 0F0F90 7F0BE5A0 24CE0001 */  addiu $t6, $a2, 1
/* 0F0F94 7F0BE5A4 A06E0068 */  sb    $t6, 0x68($v1)
.L7F0BE5A8:
/* 0F0F98 7F0BE5A8 8C830000 */  lw    $v1, ($a0)
/* 0F0F9C 7F0BE5AC 25AD0001 */  addiu $t5, $t5, 1
/* 0F0FA0 7F0BE5B0 8C790424 */  lw    $t9, 0x424($v1)
/* 0F0FA4 7F0BE5B4 5320000B */  beql  $t9, $zero, .L7F0BE5E4
/* 0F0FA8 7F0BE5B8 258C0001 */   addiu $t4, $t4, 1
/* 0F0FAC 7F0BE5BC 8C780428 */  lw    $t8, 0x428($v1)
/* 0F0FB0 7F0BE5C0 53000008 */  beql  $t8, $zero, .L7F0BE5E4
/* 0F0FB4 7F0BE5C4 258C0001 */   addiu $t4, $t4, 1
/* 0F0FB8 7F0BE5C8 C46403E4 */  lwc1  $f4, 0x3e4($v1)
/* 0F0FBC 7F0BE5CC 4600203C */  c.lt.s $f4, $f0
/* 0F0FC0 7F0BE5D0 00000000 */  nop   
/* 0F0FC4 7F0BE5D4 45020003 */  bc1fl .L7F0BE5E4
/* 0F0FC8 7F0BE5D8 258C0001 */   addiu $t4, $t4, 1
/* 0F0FCC 7F0BE5DC 27FF0001 */  addiu $ra, $ra, 1
.L7F0BE5E0:
/* 0F0FD0 7F0BE5E0 258C0001 */  addiu $t4, $t4, 1
.L7F0BE5E4:
/* 0F0FD4 7F0BE5E4 018A082A */  slt   $at, $t4, $t2
/* 0F0FD8 7F0BE5E8 5420FF95 */  bnezl $at, .L7F0BE440
/* 0F0FDC 7F0BE5EC 00002825 */   move  $a1, $zero
.L7F0BE5F0:
/* 0F0FE0 7F0BE5F0 2443FFFF */  addiu $v1, $v0, -1
/* 0F0FE4 7F0BE5F4 03E3082A */  slt   $at, $ra, $v1
/* 0F0FE8 7F0BE5F8 54200006 */  bnezl $at, .L7F0BE614
/* 0F0FEC 7F0BE5FC 01A3082A */   slt   $at, $t5, $v1
/* 0F0FF0 7F0BE600 0FC30684 */  jal   mpCalculateAwards
/* 0F0FF4 7F0BE604 00002025 */   move  $a0, $zero
/* 0F0FF8 7F0BE608 10000006 */  b     .L7F0BE624
/* 0F0FFC 7F0BE60C 00000000 */   nop   
/* 0F1000 7F0BE610 01A3082A */  slt   $at, $t5, $v1
.L7F0BE614:
/* 0F1004 7F0BE614 14200003 */  bnez  $at, .L7F0BE624
/* 0F1008 7F0BE618 00000000 */   nop   
/* 0F100C 7F0BE61C 0FC30680 */  jal   mpwatchSetStopPlayFlag
/* 0F1010 7F0BE620 00000000 */   nop   
.L7F0BE624:
/* 0F1014 7F0BE624 3C028004 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8004
/* 0F1018 7F0BE628 3C0F8004 */  lui   $t7, %hi(D_80048394) # $t7, 0x8004
/* 0F101C 7F0BE62C 8DEF1018 */  lw    $t7, %lo(D_80048394)($t7)
/* 0F1020 7F0BE630 8C420FF4 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F1024 7F0BE634 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 0F1028 7F0BE638 44810000 */  mtc1  $at, $f0
/* 0F102C 7F0BE63C 01E27021 */  addu  $t6, $t7, $v0
/* 0F1030 7F0BE640 448E3000 */  mtc1  $t6, $f6
/* 0F1034 7F0BE644 3C018004 */  lui   $at, %hi(D_80048394) # $at, 0x8004
/* 0F1038 7F0BE648 AC2E1018 */  sw    $t6, %lo(D_80048394)($at)
/* 0F103C 7F0BE64C 46803220 */  cvt.s.w $f8, $f6
/* 0F1040 7F0BE650 3C038004 */  lui   $v1, %hi(D_800483A8) # $v1, 0x8004
/* 0F1044 7F0BE654 3C018004 */  lui   $at, %hi(g_CurrentMultiPlayerSec) # $at, 0x8004
/* 0F1048 7F0BE658 2463102C */  addiu $v1, %lo(D_800483A8) # addiu $v1, $v1, 0x102c
/* 0F104C 7F0BE65C 00002025 */  move  $a0, $zero
/* 0F1050 7F0BE660 3405FFFF */  li    $a1, 65535
/* 0F1054 7F0BE664 46004283 */  div.s $f10, $f8, $f0
/* 0F1058 7F0BE668 E42A1028 */  swc1  $f10, %lo(g_CurrentMultiPlayerSec)($at)
/* 0F105C 7F0BE66C 8C790000 */  lw    $t9, ($v1)
/* 0F1060 7F0BE670 3C018004 */  lui   $at, %hi(g_CurrentMultiPlayerMin) # $at, 0x8004
/* 0F1064 7F0BE674 03227821 */  addu  $t7, $t9, $v0
/* 0F1068 7F0BE678 448F8000 */  mtc1  $t7, $f16
/* 0F106C 7F0BE67C AC6F0000 */  sw    $t7, ($v1)
/* 0F1070 7F0BE680 468084A0 */  cvt.s.w $f18, $f16
/* 0F1074 7F0BE684 46009103 */  div.s $f4, $f18, $f0
/* 0F1078 7F0BE688 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F107C 7F0BE68C E4241030 */   swc1  $f4, %lo(g_CurrentMultiPlayerMin)($at)
/* 0F1080 7F0BE690 3C014248 */  li    $at, 0x42480000 # 50.000000
/* 0F1084 7F0BE694 44810000 */  mtc1  $at, $f0
/* 0F1088 7F0BE698 10400009 */  beqz  $v0, .L7F0BE6C0
/* 0F108C 7F0BE69C 3C038004 */   lui   $v1, %hi(D_80048390)
/* 0F1090 7F0BE6A0 3C038004 */  lui   $v1, %hi(D_80048390) # $v1, 0x8004
/* 0F1094 7F0BE6A4 3C018004 */  lui   $at, %hi(D_80048388) # $at, 0x8004
/* 0F1098 7F0BE6A8 24631014 */  addiu $v1, %lo(D_80048390) # addiu $v1, $v1, 0x1014
/* 0F109C 7F0BE6AC AC20100C */  sw    $zero, %lo(D_80048388)($at)
/* 0F10A0 7F0BE6B0 AC600000 */  sw    $zero, ($v1)
/* 0F10A4 7F0BE6B4 3C028004 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8004
/* 0F10A8 7F0BE6B8 1000000C */  b     .L7F0BE6EC
/* 0F10AC 7F0BE6BC 8C420FF4 */   lw    $v0, %lo(g_ClockTimer)($v0)
.L7F0BE6C0:
/* 0F10B0 7F0BE6C0 24631014 */  addiu $v1, $v1, %lo(D_80048390)
/* 0F10B4 7F0BE6C4 3C028004 */  lui   $v0, %hi(g_ClockTimer) # $v0, 0x8004
/* 0F10B8 7F0BE6C8 8C420FF4 */  lw    $v0, %lo(g_ClockTimer)($v0)
/* 0F10BC 7F0BE6CC 8C6E0000 */  lw    $t6, ($v1)
/* 0F10C0 7F0BE6D0 240F0001 */  li    $t7, 1
/* 0F10C4 7F0BE6D4 01C2C821 */  addu  $t9, $t6, $v0
/* 0F10C8 7F0BE6D8 2B2105DC */  slti  $at, $t9, 0x5dc
/* 0F10CC 7F0BE6DC 14200003 */  bnez  $at, .L7F0BE6EC
/* 0F10D0 7F0BE6E0 AC790000 */   sw    $t9, ($v1)
/* 0F10D4 7F0BE6E4 3C018004 */  lui   $at, %hi(D_80048388) # $at, 0x8004
/* 0F10D8 7F0BE6E8 AC2F100C */  sw    $t7, %lo(D_80048388)($at)
.L7F0BE6EC:
/* 0F10DC 7F0BE6EC 3C0E8004 */  lui   $t6, %hi(D_80048388) # $t6, 0x8004
/* 0F10E0 7F0BE6F0 8DCE100C */  lw    $t6, %lo(D_80048388)($t6)
/* 0F10E4 7F0BE6F4 3C038004 */  lui   $v1, %hi(D_8004838C) # $v1, 0x8004
/* 0F10E8 7F0BE6F8 24631010 */  addiu $v1, %lo(D_8004838C) # addiu $v1, $v1, 0x1010
/* 0F10EC 7F0BE6FC 11C00005 */  beqz  $t6, .L7F0BE714
/* 0F10F0 7F0BE700 00000000 */   nop   
/* 0F10F4 7F0BE704 8C790000 */  lw    $t9, ($v1)
/* 0F10F8 7F0BE708 0322C021 */  addu  $t8, $t9, $v0
/* 0F10FC 7F0BE70C 10000015 */  b     .L7F0BE764
/* 0F1100 7F0BE710 AC780000 */   sw    $t8, ($v1)
.L7F0BE714:
/* 0F1104 7F0BE714 3C038004 */  lui   $v1, %hi(D_800483B0) # $v1, 0x8004
/* 0F1108 7F0BE718 24631034 */  addiu $v1, %lo(D_800483B0) # addiu $v1, $v1, 0x1034
/* 0F110C 7F0BE71C 8C6F0000 */  lw    $t7, ($v1)
/* 0F1110 7F0BE720 3C048004 */  lui   $a0, %hi(D_800483B8) # $a0, 0x8004
/* 0F1114 7F0BE724 3C018004 */  lui   $at, %hi(g_StageTimeSec) # $at, 0x8004
/* 0F1118 7F0BE728 01E2C821 */  addu  $t9, $t7, $v0
/* 0F111C 7F0BE72C 44993000 */  mtc1  $t9, $f6
/* 0F1120 7F0BE730 AC790000 */  sw    $t9, ($v1)
/* 0F1124 7F0BE734 2484103C */  addiu $a0, %lo(D_800483B8) # addiu $a0, $a0, 0x103c
/* 0F1128 7F0BE738 46803220 */  cvt.s.w $f8, $f6
/* 0F112C 7F0BE73C 46004283 */  div.s $f10, $f8, $f0
/* 0F1130 7F0BE740 E42A1038 */  swc1  $f10, %lo(g_StageTimeSec)($at)
/* 0F1134 7F0BE744 8C980000 */  lw    $t8, ($a0)
/* 0F1138 7F0BE748 3C018004 */  lui   $at, %hi(g_PowerOnTimeSec) # $at, 0x8004
/* 0F113C 7F0BE74C 03027021 */  addu  $t6, $t8, $v0
/* 0F1140 7F0BE750 448E8000 */  mtc1  $t6, $f16
/* 0F1144 7F0BE754 AC8E0000 */  sw    $t6, ($a0)
/* 0F1148 7F0BE758 468084A0 */  cvt.s.w $f18, $f16
/* 0F114C 7F0BE75C 46009103 */  div.s $f4, $f18, $f0
/* 0F1150 7F0BE760 E4241040 */  swc1  $f4, %lo(g_PowerOnTimeSec)($at)
.L7F0BE764:
/* 0F1154 7F0BE764 0C000FE1 */  jal   viSetUseZBuf
/* 0F1158 7F0BE768 24040001 */   li    $a0, 1
/* 0F115C 7F0BE76C 3C198004 */  lui   $t9, %hi(g_CurrentStageToLoad) # $t9, 0x8004
/* 0F1160 7F0BE770 8F390FE4 */  lw    $t9, %lo(g_CurrentStageToLoad)($t9)
/* 0F1164 7F0BE774 2401005A */  li    $at, 90
/* 0F1168 7F0BE778 17210009 */  bne   $t9, $at, .L7F0BE7A0
/* 0F116C 7F0BE77C 00000000 */   nop   
/* 0F1170 7F0BE780 0FC2436F */  jal   cheat_buttons_mp_related
/* 0F1174 7F0BE784 00000000 */   nop   
/* 0F1178 7F0BE788 0FC06920 */  jal   menu_init
/* 0F117C 7F0BE78C 00000000 */   nop   
/* 0F1180 7F0BE790 0FC30388 */  jal   something_with_LnameJ
/* 0F1184 7F0BE794 00000000 */   nop   
/* 0F1188 7F0BE798 100000A9 */  b     .L7F0BEA40
/* 0F118C 7F0BE79C 00000000 */   nop   
.L7F0BE7A0:
/* 0F1190 7F0BE7A0 0FC26C3F */  jal   sub_GAME_7F09BBBC
/* 0F1194 7F0BE7A4 00000000 */   nop   
/* 0F1198 7F0BE7A8 0FC2F72D */  jal   lvlSetMultipliersForDifficulty
/* 0F119C 7F0BE7AC 00000000 */   nop   
/* 0F11A0 7F0BE7B0 0FC2EEF5 */  jal   sub_GAME_7F0BC7D4
/* 0F11A4 7F0BE7B4 00000000 */   nop   
/* 0F11A8 7F0BE7B8 0FC248E4 */  jal   sub_GAME_7F092E50
/* 0F11AC 7F0BE7BC 00000000 */   nop   
/* 0F11B0 7F0BE7C0 0FC24E5E */  jal   sub_GAME_7F094438
/* 0F11B4 7F0BE7C4 00000000 */   nop   
/* 0F11B8 7F0BE7C8 0FC28ECE */  jal   sub_GAME_7F0A4600
/* 0F11BC 7F0BE7CC 00000000 */   nop   
/* 0F11C0 7F0BE7D0 0FC1A580 */  jal   sub_GAME_7F068E6C
/* 0F11C4 7F0BE7D4 00000000 */   nop   
/* 0F11C8 7F0BE7D8 0FC28785 */  jal   update_broken_windows
/* 0F11CC 7F0BE7DC 00000000 */   nop   
/* 0F11D0 7F0BE7E0 0FC27CA0 */  jal   update_gray_flying_particles
/* 0F11D4 7F0BE7E4 00000000 */   nop   
/* 0F11D8 7F0BE7E8 0FC0F1C2 */  jal   handle_mp_respawn_and_some_things
/* 0F11DC 7F0BE7EC 00000000 */   nop   
/* 0F11E0 7F0BE7F0 0FC3022A */  jal   reset_all_music_slots
/* 0F11E4 7F0BE7F4 00000000 */   nop   
/* 0F11E8 7F0BE7F8 0FC30388 */  jal   something_with_LnameJ
/* 0F11EC 7F0BE7FC 00000000 */   nop   
/* 0F11F0 7F0BE800 0FC24116 */  jal   get_debug_joy2detailedit_flag
/* 0F11F4 7F0BE804 00000000 */   nop   
/* 0F11F8 7F0BE808 1040004D */  beqz  $v0, .L7F0BE940
/* 0F11FC 7F0BE80C 3C068004 */   lui   $a2, %hi(D_800483C8) # $a2, 0x8004
/* 0F1200 7F0BE810 24C6104C */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, 0x104c
/* 0F1204 7F0BE814 8CD80000 */  lw    $t8, ($a2)
/* 0F1208 7F0BE818 24043000 */  li    $a0, 12288
/* 0F120C 7F0BE81C 17000048 */  bnez  $t8, .L7F0BE940
/* 0F1210 7F0BE820 00000000 */   nop   
/* 0F1214 7F0BE824 0C0022E0 */  jal   mempAllocBytesInBank
/* 0F1218 7F0BE828 24050004 */   li    $a1, 4
/* 0F121C 7F0BE82C 3C068004 */  lui   $a2, %hi(D_800483C8) # $a2, 0x8004
/* 0F1220 7F0BE830 24C6104C */  addiu $a2, %lo(D_800483C8) # addiu $a2, $a2, 0x104c
/* 0F1224 7F0BE834 10400042 */  beqz  $v0, .L7F0BE940
/* 0F1228 7F0BE838 ACC20000 */   sw    $v0, ($a2)
/* 0F122C 7F0BE83C 00001825 */  move  $v1, $zero
/* 0F1230 7F0BE840 24052EE0 */  li    $a1, 12000
/* 0F1234 7F0BE844 240400FF */  li    $a0, 255
.L7F0BE848:
/* 0F1238 7F0BE848 8CCE0000 */  lw    $t6, ($a2)
/* 0F123C 7F0BE84C 01C3C821 */  addu  $t9, $t6, $v1
/* 0F1240 7F0BE850 A3240000 */  sb    $a0, ($t9)
/* 0F1244 7F0BE854 8CD80000 */  lw    $t8, ($a2)
/* 0F1248 7F0BE858 03031021 */  addu  $v0, $t8, $v1
/* 0F124C 7F0BE85C 904F0001 */  lbu   $t7, 1($v0)
/* 0F1250 7F0BE860 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F1254 7F0BE864 35D90020 */  ori   $t9, $t6, 0x20
/* 0F1258 7F0BE868 A0590001 */  sb    $t9, 1($v0)
/* 0F125C 7F0BE86C 8CD80000 */  lw    $t8, ($a2)
/* 0F1260 7F0BE870 03031021 */  addu  $v0, $t8, $v1
/* 0F1264 7F0BE874 904F0001 */  lbu   $t7, 1($v0)
/* 0F1268 7F0BE878 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F126C 7F0BE87C 35D90004 */  ori   $t9, $t6, 4
/* 0F1270 7F0BE880 A0590001 */  sb    $t9, 1($v0)
/* 0F1274 7F0BE884 8CD80000 */  lw    $t8, ($a2)
/* 0F1278 7F0BE888 03037821 */  addu  $t7, $t8, $v1
/* 0F127C 7F0BE88C A1E40004 */  sb    $a0, 4($t7)
/* 0F1280 7F0BE890 8CCE0000 */  lw    $t6, ($a2)
/* 0F1284 7F0BE894 01C31021 */  addu  $v0, $t6, $v1
/* 0F1288 7F0BE898 90590005 */  lbu   $t9, 5($v0)
/* 0F128C 7F0BE89C 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F1290 7F0BE8A0 370F0020 */  ori   $t7, $t8, 0x20
/* 0F1294 7F0BE8A4 A04F0005 */  sb    $t7, 5($v0)
/* 0F1298 7F0BE8A8 8CCE0000 */  lw    $t6, ($a2)
/* 0F129C 7F0BE8AC 01C31021 */  addu  $v0, $t6, $v1
/* 0F12A0 7F0BE8B0 90590005 */  lbu   $t9, 5($v0)
/* 0F12A4 7F0BE8B4 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F12A8 7F0BE8B8 370F0004 */  ori   $t7, $t8, 4
/* 0F12AC 7F0BE8BC A04F0005 */  sb    $t7, 5($v0)
/* 0F12B0 7F0BE8C0 8CCE0000 */  lw    $t6, ($a2)
/* 0F12B4 7F0BE8C4 01C3C821 */  addu  $t9, $t6, $v1
/* 0F12B8 7F0BE8C8 A3240008 */  sb    $a0, 8($t9)
/* 0F12BC 7F0BE8CC 8CD80000 */  lw    $t8, ($a2)
/* 0F12C0 7F0BE8D0 03031021 */  addu  $v0, $t8, $v1
/* 0F12C4 7F0BE8D4 904F0009 */  lbu   $t7, 9($v0)
/* 0F12C8 7F0BE8D8 31EEFF1F */  andi  $t6, $t7, 0xff1f
/* 0F12CC 7F0BE8DC 35D90020 */  ori   $t9, $t6, 0x20
/* 0F12D0 7F0BE8E0 A0590009 */  sb    $t9, 9($v0)
/* 0F12D4 7F0BE8E4 8CD80000 */  lw    $t8, ($a2)
/* 0F12D8 7F0BE8E8 03031021 */  addu  $v0, $t8, $v1
/* 0F12DC 7F0BE8EC 904F0009 */  lbu   $t7, 9($v0)
/* 0F12E0 7F0BE8F0 31EEFFE3 */  andi  $t6, $t7, 0xffe3
/* 0F12E4 7F0BE8F4 35D90004 */  ori   $t9, $t6, 4
/* 0F12E8 7F0BE8F8 A0590009 */  sb    $t9, 9($v0)
/* 0F12EC 7F0BE8FC 8CD80000 */  lw    $t8, ($a2)
/* 0F12F0 7F0BE900 03037821 */  addu  $t7, $t8, $v1
/* 0F12F4 7F0BE904 A1E4000C */  sb    $a0, 0xc($t7)
/* 0F12F8 7F0BE908 8CCE0000 */  lw    $t6, ($a2)
/* 0F12FC 7F0BE90C 01C31021 */  addu  $v0, $t6, $v1
/* 0F1300 7F0BE910 9059000D */  lbu   $t9, 0xd($v0)
/* 0F1304 7F0BE914 3338FF1F */  andi  $t8, $t9, 0xff1f
/* 0F1308 7F0BE918 370F0020 */  ori   $t7, $t8, 0x20
/* 0F130C 7F0BE91C A04F000D */  sb    $t7, 0xd($v0)
/* 0F1310 7F0BE920 8CCE0000 */  lw    $t6, ($a2)
/* 0F1314 7F0BE924 01C31021 */  addu  $v0, $t6, $v1
/* 0F1318 7F0BE928 9059000D */  lbu   $t9, 0xd($v0)
/* 0F131C 7F0BE92C 24630010 */  addiu $v1, $v1, 0x10
/* 0F1320 7F0BE930 3338FFE3 */  andi  $t8, $t9, 0xffe3
/* 0F1324 7F0BE934 370F0004 */  ori   $t7, $t8, 4
/* 0F1328 7F0BE938 1465FFC3 */  bne   $v1, $a1, .L7F0BE848
/* 0F132C 7F0BE93C A04F000D */   sb    $t7, 0xd($v0)
.L7F0BE940:
/* 0F1330 7F0BE940 0FC2413C */  jal   get_debug_portal_flag
/* 0F1334 7F0BE944 00000000 */   nop   
/* 0F1338 7F0BE948 10400003 */  beqz  $v0, .L7F0BE958
/* 0F133C 7F0BE94C 00000000 */   nop   
/* 0F1340 7F0BE950 0FC2F4B4 */  jal   lvlPortalDebug7F0BDF10
/* 0F1344 7F0BE954 00002025 */   move  $a0, $zero
.L7F0BE958:
/* 0F1348 7F0BE958 0FC240FC */  jal   getDebugMode
/* 0F134C 7F0BE95C 00000000 */   nop   
/* 0F1350 7F0BE960 24010004 */  li    $at, 4
/* 0F1354 7F0BE964 10410006 */  beq   $v0, $at, .L7F0BE980
/* 0F1358 7F0BE968 00002025 */   move  $a0, $zero
/* 0F135C 7F0BE96C 24010008 */  li    $at, 8
/* 0F1360 7F0BE970 1041001A */  beq   $v0, $at, .L7F0BE9DC
/* 0F1364 7F0BE974 00002025 */   move  $a0, $zero
/* 0F1368 7F0BE978 10000031 */  b     .L7F0BEA40
/* 0F136C 7F0BE97C 00000000 */   nop   
.L7F0BE980:
/* 0F1370 7F0BE980 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F1374 7F0BE984 24050002 */   li    $a1, 2
/* 0F1378 7F0BE988 50400008 */  beql  $v0, $zero, .L7F0BE9AC
/* 0F137C 7F0BE98C 00002025 */   move  $a0, $zero
/* 0F1380 7F0BE990 0FC2BA3C */  jal   sub_GAME_7F0AF630
/* 0F1384 7F0BE994 2404FFFF */   li    $a0, -1
/* 0F1388 7F0BE998 00002025 */  move  $a0, $zero
/* 0F138C 7F0BE99C 00002825 */  move  $a1, $zero
/* 0F1390 7F0BE9A0 0FC2C7FE */  jal   sub_GAME_7F0B2D38
/* 0F1394 7F0BE9A4 00003025 */   move  $a2, $zero
/* 0F1398 7F0BE9A8 00002025 */  move  $a0, $zero
.L7F0BE9AC:
/* 0F139C 7F0BE9AC 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F13A0 7F0BE9B0 24050001 */   li    $a1, 1
/* 0F13A4 7F0BE9B4 10400022 */  beqz  $v0, .L7F0BEA40
/* 0F13A8 7F0BE9B8 00000000 */   nop   
/* 0F13AC 7F0BE9BC 0FC2BA3C */  jal   sub_GAME_7F0AF630
/* 0F13B0 7F0BE9C0 24040001 */   li    $a0, 1
/* 0F13B4 7F0BE9C4 00002025 */  move  $a0, $zero
/* 0F13B8 7F0BE9C8 00002825 */  move  $a1, $zero
/* 0F13BC 7F0BE9CC 0FC2C7FE */  jal   sub_GAME_7F0B2D38
/* 0F13C0 7F0BE9D0 00003025 */   move  $a2, $zero
/* 0F13C4 7F0BE9D4 1000001A */  b     .L7F0BEA40
/* 0F13C8 7F0BE9D8 00000000 */   nop   
.L7F0BE9DC:
/* 0F13CC 7F0BE9DC 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F13D0 7F0BE9E0 24050002 */   li    $a1, 2
/* 0F13D4 7F0BE9E4 50400004 */  beql  $v0, $zero, .L7F0BE9F8
/* 0F13D8 7F0BE9E8 00002025 */   move  $a0, $zero
/* 0F13DC 7F0BE9EC 0FC08B7E */  jal   chrDecrementAnimationTablePointerCount
/* 0F13E0 7F0BE9F0 00000000 */   nop   
/* 0F13E4 7F0BE9F4 00002025 */  move  $a0, $zero
.L7F0BE9F8:
/* 0F13E8 7F0BE9F8 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F13EC 7F0BE9FC 24050001 */   li    $a1, 1
/* 0F13F0 7F0BEA00 50400004 */  beql  $v0, $zero, .L7F0BEA14
/* 0F13F4 7F0BEA04 00002025 */   move  $a0, $zero
/* 0F13F8 7F0BEA08 0FC08B96 */  jal   chrIncrementAnimationTablePointerCount
/* 0F13FC 7F0BEA0C 00000000 */   nop   
/* 0F1400 7F0BEA10 00002025 */  move  $a0, $zero
.L7F0BEA14:
/* 0F1404 7F0BEA14 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F1408 7F0BEA18 24050020 */   li    $a1, 32
/* 0F140C 7F0BEA1C 50400004 */  beql  $v0, $zero, .L7F0BEA30
/* 0F1410 7F0BEA20 00002025 */   move  $a0, $zero
/* 0F1414 7F0BEA24 0FC08BA4 */  jal   chrToggleD_8002C90C
/* 0F1418 7F0BEA28 00000000 */   nop   
/* 0F141C 7F0BEA2C 00002025 */  move  $a0, $zero
.L7F0BEA30:
/* 0F1420 7F0BEA30 0C002C20 */  jal   joyGetButtons
/* 0F1424 7F0BEA34 24050010 */   li    $a1, 16
/* 0F1428 7F0BEA38 0FC08BAA */  jal   sub_GAME_7F022EE0
/* 0F142C 7F0BEA3C 0002202B */   sltu  $a0, $zero, $v0
.L7F0BEA40:
/* 0F1430 7F0BEA40 0FC240FC */  jal   getDebugMode
/* 0F1434 7F0BEA44 00000000 */   nop   
/* 0F1438 7F0BEA48 2401000C */  li    $at, 12
/* 0F143C 7F0BEA4C 1041002E */  beq   $v0, $at, .L7F0BEB08
/* 0F1440 7F0BEA50 00002025 */   move  $a0, $zero
/* 0F1444 7F0BEA54 2401000D */  li    $at, 13
/* 0F1448 7F0BEA58 10410048 */  beq   $v0, $at, .L7F0BEB7C
/* 0F144C 7F0BEA5C 00002025 */   move  $a0, $zero
/* 0F1450 7F0BEA60 24010038 */  li    $at, 56
/* 0F1454 7F0BEA64 54410074 */  bnel  $v0, $at, .L7F0BEC38
/* 0F1458 7F0BEA68 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F145C 7F0BEA6C 0C000F7E */  jal   viGetHorizontalOffset
/* 0F1460 7F0BEA70 00000000 */   nop   
/* 0F1464 7F0BEA74 0C000F78 */  jal   viGet800232A0
/* 0F1468 7F0BEA78 AFA20030 */   sw    $v0, 0x30($sp)
/* 0F146C 7F0BEA7C AFA2002C */  sw    $v0, 0x2c($sp)
/* 0F1470 7F0BEA80 00002025 */  move  $a0, $zero
/* 0F1474 7F0BEA84 0C002C20 */  jal   joyGetButtons
/* 0F1478 7F0BEA88 24050004 */   li    $a1, 4
/* 0F147C 7F0BEA8C 10400004 */  beqz  $v0, .L7F0BEAA0
/* 0F1480 7F0BEA90 00002025 */   move  $a0, $zero
/* 0F1484 7F0BEA94 8FAE002C */  lw    $t6, 0x2c($sp)
/* 0F1488 7F0BEA98 25D90001 */  addiu $t9, $t6, 1
/* 0F148C 7F0BEA9C AFB9002C */  sw    $t9, 0x2c($sp)
.L7F0BEAA0:
/* 0F1490 7F0BEAA0 0C002C20 */  jal   joyGetButtons
/* 0F1494 7F0BEAA4 24050008 */   li    $a1, 8
/* 0F1498 7F0BEAA8 10400004 */  beqz  $v0, .L7F0BEABC
/* 0F149C 7F0BEAAC 00002025 */   move  $a0, $zero
/* 0F14A0 7F0BEAB0 8FB8002C */  lw    $t8, 0x2c($sp)
/* 0F14A4 7F0BEAB4 270FFFFF */  addiu $t7, $t8, -1
/* 0F14A8 7F0BEAB8 AFAF002C */  sw    $t7, 0x2c($sp)
.L7F0BEABC:
/* 0F14AC 7F0BEABC 0C002C20 */  jal   joyGetButtons
/* 0F14B0 7F0BEAC0 24050001 */   li    $a1, 1
/* 0F14B4 7F0BEAC4 10400004 */  beqz  $v0, .L7F0BEAD8
/* 0F14B8 7F0BEAC8 00002025 */   move  $a0, $zero
/* 0F14BC 7F0BEACC 8FAE0030 */  lw    $t6, 0x30($sp)
/* 0F14C0 7F0BEAD0 25D90001 */  addiu $t9, $t6, 1
/* 0F14C4 7F0BEAD4 AFB90030 */  sw    $t9, 0x30($sp)
.L7F0BEAD8:
/* 0F14C8 7F0BEAD8 0C002C20 */  jal   joyGetButtons
/* 0F14CC 7F0BEADC 24050002 */   li    $a1, 2
/* 0F14D0 7F0BEAE0 10400003 */  beqz  $v0, .L7F0BEAF0
/* 0F14D4 7F0BEAE4 8FB80030 */   lw    $t8, 0x30($sp)
/* 0F14D8 7F0BEAE8 270FFFFF */  addiu $t7, $t8, -1
/* 0F14DC 7F0BEAEC AFAF0030 */  sw    $t7, 0x30($sp)
.L7F0BEAF0:
/* 0F14E0 7F0BEAF0 0C000F7B */  jal   viSetHorizontalOffset
/* 0F14E4 7F0BEAF4 8FA40030 */   lw    $a0, 0x30($sp)
/* 0F14E8 7F0BEAF8 0C000F75 */  jal   viSet800232A0
/* 0F14EC 7F0BEAFC 8FA4002C */   lw    $a0, 0x2c($sp)
/* 0F14F0 7F0BEB00 1000004D */  b     .L7F0BEC38
/* 0F14F4 7F0BEB04 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BEB08:
/* 0F14F8 7F0BEB08 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F14FC 7F0BEB0C 24050202 */   li    $a1, 514
/* 0F1500 7F0BEB10 50400004 */  beql  $v0, $zero, .L7F0BEB24
/* 0F1504 7F0BEB14 00002025 */   move  $a0, $zero
/* 0F1508 7F0BEB18 0FC2F37A */  jal   lvlMusicAppendPlayEndTheme
/* 0F150C 7F0BEB1C 00000000 */   nop   
/* 0F1510 7F0BEB20 00002025 */  move  $a0, $zero
.L7F0BEB24:
/* 0F1514 7F0BEB24 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F1518 7F0BEB28 24050101 */   li    $a1, 257
/* 0F151C 7F0BEB2C 50400004 */  beql  $v0, $zero, .L7F0BEB40
/* 0F1520 7F0BEB30 00002025 */   move  $a0, $zero
/* 0F1524 7F0BEB34 0FC2F367 */  jal   lvlMusicAppendPlaySoloDeathShort
/* 0F1528 7F0BEB38 00000000 */   nop   
/* 0F152C 7F0BEB3C 00002025 */  move  $a0, $zero
.L7F0BEB40:
/* 0F1530 7F0BEB40 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F1534 7F0BEB44 24050400 */   li    $a1, 1024
/* 0F1538 7F0BEB48 50400004 */  beql  $v0, $zero, .L7F0BEB5C
/* 0F153C 7F0BEB4C 00002025 */   move  $a0, $zero
/* 0F1540 7F0BEB50 0C00190C */  jal   musicTrack1Stop
/* 0F1544 7F0BEB54 00000000 */   nop   
/* 0F1548 7F0BEB58 00002025 */  move  $a0, $zero
.L7F0BEB5C:
/* 0F154C 7F0BEB5C 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F1550 7F0BEB60 24054000 */   li    $a1, 16384
/* 0F1554 7F0BEB64 50400034 */  beql  $v0, $zero, .L7F0BEC38
/* 0F1558 7F0BEB68 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F155C 7F0BEB6C 0C001940 */  jal   musicTrack1SaveCurrentVolumeAsTrackDefault
/* 0F1560 7F0BEB70 00000000 */   nop   
/* 0F1564 7F0BEB74 10000030 */  b     .L7F0BEC38
/* 0F1568 7F0BEB78 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0BEB7C:
/* 0F156C 7F0BEB7C 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F1570 7F0BEB80 24050622 */   li    $a1, 1570
/* 0F1574 7F0BEB84 1040000B */  beqz  $v0, .L7F0BEBB4
/* 0F1578 7F0BEB88 3C058004 */   lui   $a1, %hi(g_DebugMpGameSoundFxIndex) # $a1, 0x8004
/* 0F157C 7F0BEB8C 84A51068 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F1580 7F0BEB90 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0F1584 7F0BEB94 3C018004 */  lui   $at, %hi(g_DebugMpGameSoundFxIndex) # $at, 0x8004
/* 0F1588 7F0BEB98 24A5FFFF */  addiu $a1, 0xffff # addiu $a1, $a1, -1
/* 0F158C 7F0BEB9C 00057400 */  sll   $t6, $a1, 0x10
/* 0F1590 7F0BEBA0 000E2C03 */  sra   $a1, $t6, 0x10
/* 0F1594 7F0BEBA4 A4251068 */  sh    $a1, %lo(g_DebugMpGameSoundFxIndex)($at)
/* 0F1598 7F0BEBA8 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F159C 7F0BEBAC 0C00209A */  jal   sndPlaySfx
/* 0F15A0 7F0BEBB0 00003025 */   move  $a2, $zero
.L7F0BEBB4:
/* 0F15A4 7F0BEBB4 00002025 */  move  $a0, $zero
/* 0F15A8 7F0BEBB8 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F15AC 7F0BEBBC 24050911 */   li    $a1, 2321
/* 0F15B0 7F0BEBC0 1040000B */  beqz  $v0, .L7F0BEBF0
/* 0F15B4 7F0BEBC4 3C058004 */   lui   $a1, %hi(g_DebugMpGameSoundFxIndex) # $a1, 0x8004
/* 0F15B8 7F0BEBC8 84A51068 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F15BC 7F0BEBCC 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0F15C0 7F0BEBD0 3C018004 */  lui   $at, %hi(g_DebugMpGameSoundFxIndex) # $at, 0x8004
/* 0F15C4 7F0BEBD4 24A50001 */  addiu $a1, 1 # addiu $a1, $a1, 1
/* 0F15C8 7F0BEBD8 0005C400 */  sll   $t8, $a1, 0x10
/* 0F15CC 7F0BEBDC 00182C03 */  sra   $a1, $t8, 0x10
/* 0F15D0 7F0BEBE0 A4251068 */  sh    $a1, %lo(g_DebugMpGameSoundFxIndex)($at)
/* 0F15D4 7F0BEBE4 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F15D8 7F0BEBE8 0C00209A */  jal   sndPlaySfx
/* 0F15DC 7F0BEBEC 00003025 */   move  $a2, $zero
.L7F0BEBF0:
/* 0F15E0 7F0BEBF0 00002025 */  move  $a0, $zero
/* 0F15E4 7F0BEBF4 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F15E8 7F0BEBF8 24050004 */   li    $a1, 4
/* 0F15EC 7F0BEBFC 50400004 */  beql  $v0, $zero, .L7F0BEC10
/* 0F15F0 7F0BEC00 00002025 */   move  $a0, $zero
/* 0F15F4 7F0BEC04 0C002161 */  jal   sndDeactivateAllSfxByFlag_1
/* 0F15F8 7F0BEC08 00000000 */   nop   
/* 0F15FC 7F0BEC0C 00002025 */  move  $a0, $zero
.L7F0BEC10:
/* 0F1600 7F0BEC10 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0F1604 7F0BEC14 24050008 */   li    $a1, 8
/* 0F1608 7F0BEC18 10400006 */  beqz  $v0, .L7F0BEC34
/* 0F160C 7F0BEC1C 3C058004 */   lui   $a1, %hi(g_DebugMpGameSoundFxIndex) # $a1, 0x8004
/* 0F1610 7F0BEC20 3C048005 */  lui   $a0, %hi(g_musicSfxBufferPtr) # $a0, 0x8005
/* 0F1614 7F0BEC24 8C846900 */  lw    $a0, %lo(g_musicSfxBufferPtr)($a0)
/* 0F1618 7F0BEC28 84A51068 */  lh    $a1, %lo(g_DebugMpGameSoundFxIndex)($a1)
/* 0F161C 7F0BEC2C 0C00209A */  jal   sndPlaySfx
/* 0F1620 7F0BEC30 00003025 */   move  $a2, $zero
.L7F0BEC34:
/* 0F1624 7F0BEC34 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BEC38:
/* 0F1628 7F0BEC38 27BD0198 */  addiu $sp, $sp, 0x198
/* 0F162C 7F0BEC3C 03E00008 */  jr    $ra
/* 0F1630 7F0BEC40 00000000 */   nop   
)
#endif

#endif


#ifdef NONMATCHING
/**
 * Multiplayer related. Has some debug code which passes in controller input.
 * 
 * Updates distance_traveled and possibly (depending on scenario) have_token_or_goldengun.
 * 
 * Address 0x7F0BF800.
 * 
 * decomp status:
 * - compiles: yes
 * - stack resize: ok
 * - identical instructions: yes
 * - identical registers: fail
 * 
 * notes: only regalloc issues near the sqrtf call.
 */
void lvlUpdateMpPlayerData(void)
{
    s8 local_player_number;
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_v0;

    local_player_number = get_cur_playernum();
    cheat_buttons_mp_related();
    temp_v0 = get_debug_freeze_processing();

    switch (temp_v0)
    {
        case 0:
        {
            if ((getDebugMode() == DEB_MOVE_VIEW) || ((getDebugMode() == DEB_INTRO_EDIT) && (D_80036ABC < 0)))
            {
                sub_GAME_7F091080(joyGetStickX(local_player_number), joyGetStickY(local_player_number), joyGetButtons(local_player_number, ANY_BUTTON));
            }
            else
            {
                sub_GAME_7F091080(joyGetStickX(local_player_number), joyGetStickY(local_player_number), 0);
            }
        }
        break;

        case 1:
        {
            if (getDebugMode() == DEB_STAN_VIEW)
            {
                sub_GAME_7F0B2D38(joyGetStickX(local_player_number), joyGetStickY(local_player_number), joyGetButtons(local_player_number, ANY_BUTTON));
            }
            else
            {
                sub_GAME_7F0B2D38(joyGetStickX(local_player_number), joyGetStickY(local_player_number), 0);
            }
        }
        break;

        case 2:
        {
            if (getDebugMode() == DEB_BOND_VIEW)
            {
                bondviewMovePlayerUpdateViewport(joyGetStickX(local_player_number), joyGetStickY(local_player_number), joyGetButtons(local_player_number, ANY_BUTTON));
            }
            else
            {
                bondviewMovePlayerUpdateViewport(joyGetStickX(local_player_number), joyGetStickY(local_player_number), 0);
            }

            sub_GAME_7F0C2E80();
        }
        break;
    }

    // decomp issue: `g_CurrentPlayer->prop` and `g_CurrentPlayer` registers are swapped.
    temp_f0 = g_CurrentPlayer->prop->position.x - g_CurrentPlayer->bondprevpos.x;
    temp_f2 = g_CurrentPlayer->prop->position.z - g_CurrentPlayer->bondprevpos.z;

    g_playerPerm->distance_traveled += sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));

    if (get_scenario() == SCENARIO_TLD)
    {
        if (bondinvIsAliveWithFlag())
        {
            if (getCurrentPlayerWeaponId(GUNRIGHT) != ITEM_TOKEN)
            {
                currentPlayerEquipWeaponWrapper(GUNRIGHT, ITEM_TOKEN);

                if (g_CurrentPlayer->hands[GUNRIGHT].when_detonating_mines_is_0 == 2)
                {
                    g_CurrentPlayer->hands[GUNRIGHT].when_detonating_mines_is_0 = 5;
                }
            }

            g_playerPerm->flag_counter += g_ClockTimer;
            g_playerPerm->have_token_or_goldengun = 1;
        }
        else
        {
            g_playerPerm->have_token_or_goldengun = 0;
        }

        return;
    }

    if (get_scenario() == SCENARIO_MWTGG)
    {
        if (bondinvHasGoldenGun())
        {
            g_playerPerm->have_token_or_goldengun = 1;
        }
        else
        {
            g_playerPerm->have_token_or_goldengun = 0;
        }

        return;
    }
}
#else

#if defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel lvlUpdateMpPlayerData
/* 0F4330 7F0BF800 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F4334 7F0BF804 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F4338 7F0BF808 0FC26C54 */  jal   get_cur_playernum
/* 0F433C 7F0BF80C 00000000 */   nop
/* 0F4340 7F0BF810 0FC2464F */  jal   cheat_buttons_mp_related
/* 0F4344 7F0BF814 A3A2002F */   sb    $v0, 0x2f($sp)
/* 0F4348 7F0BF818 0FC243C2 */  jal   get_debug_freeze_processing
/* 0F434C 7F0BF81C 00000000 */   nop
/* 0F4350 7F0BF820 10400007 */  beqz  $v0, .L7F0BF840
/* 0F4354 7F0BF824 24010001 */   li    $at, 1
/* 0F4358 7F0BF828 1041002D */  beq   $v0, $at, .L7F0BF8E0
/* 0F435C 7F0BF82C 24010002 */   li    $at, 2
/* 0F4360 7F0BF830 1041004C */  beq   $v0, $at, .L7F0BF964
/* 0F4364 7F0BF834 00000000 */   nop
/* 0F4368 7F0BF838 1000006B */  b     .L7F0BF9E8
/* 0F436C 7F0BF83C 00000000 */   nop
.L7F0BF840:
/* 0F4370 7F0BF840 0FC243C5 */  jal   getDebugMode
/* 0F4374 7F0BF844 00000000 */   nop
/* 0F4378 7F0BF848 10400009 */  beqz  $v0, .L7F0BF870
/* 0F437C 7F0BF84C 00000000 */   nop
/* 0F4380 7F0BF850 0FC243C5 */  jal   getDebugMode
/* 0F4384 7F0BF854 00000000 */   nop
/* 0F4388 7F0BF858 2401003B */  li    $at, 59
/* 0F438C 7F0BF85C 14410013 */  bne   $v0, $at, .L7F0BF8AC
/* 0F4390 7F0BF860 3C0E8003 */   lui   $t6, %hi(D_80036ABC)
/* 0F4394 7F0BF864 8DCE6ABC */  lw    $t6, %lo(D_80036ABC)($t6)
/* 0F4398 7F0BF868 05C10010 */  bgez  $t6, .L7F0BF8AC
/* 0F439C 7F0BF86C 00000000 */   nop
.L7F0BF870:
/* 0F43A0 7F0BF870 0C00303B */  jal   joyGetStickX
/* 0F43A4 7F0BF874 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43A8 7F0BF878 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F43AC 7F0BF87C 0C00307F */  jal   joyGetStickY
/* 0F43B0 7F0BF880 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43B4 7F0BF884 A3A20019 */  sb    $v0, 0x19($sp)
/* 0F43B8 7F0BF888 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F43BC 7F0BF88C 0C0030C3 */  jal   joyGetButtons
/* 0F43C0 7F0BF890 3405FFFF */   li    $a1, 65535
/* 0F43C4 7F0BF894 83A40018 */  lb    $a0, 0x18($sp)
/* 0F43C8 7F0BF898 83A50019 */  lb    $a1, 0x19($sp)
/* 0F43CC 7F0BF89C 0FC24420 */  jal   sub_GAME_7F091080
/* 0F43D0 7F0BF8A0 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F43D4 7F0BF8A4 10000050 */  b     .L7F0BF9E8
/* 0F43D8 7F0BF8A8 00000000 */   nop
.L7F0BF8AC:
/* 0F43DC 7F0BF8AC 0C00303B */  jal   joyGetStickX
/* 0F43E0 7F0BF8B0 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43E4 7F0BF8B4 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F43E8 7F0BF8B8 0C00307F */  jal   joyGetStickY
/* 0F43EC 7F0BF8BC 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F43F0 7F0BF8C0 00022E00 */  sll   $a1, $v0, 0x18
/* 0F43F4 7F0BF8C4 00057E03 */  sra   $t7, $a1, 0x18
/* 0F43F8 7F0BF8C8 01E02825 */  move  $a1, $t7
/* 0F43FC 7F0BF8CC 83A40018 */  lb    $a0, 0x18($sp)
/* 0F4400 7F0BF8D0 0FC24420 */  jal   sub_GAME_7F091080
/* 0F4404 7F0BF8D4 00003025 */   move  $a2, $zero
/* 0F4408 7F0BF8D8 10000043 */  b     .L7F0BF9E8
/* 0F440C 7F0BF8DC 00000000 */   nop
.L7F0BF8E0:
/* 0F4410 7F0BF8E0 0FC243C5 */  jal   getDebugMode
/* 0F4414 7F0BF8E4 00000000 */   nop
/* 0F4418 7F0BF8E8 24010001 */  li    $at, 1
/* 0F441C 7F0BF8EC 14410010 */  bne   $v0, $at, .L7F0BF930
/* 0F4420 7F0BF8F0 00000000 */   nop
/* 0F4424 7F0BF8F4 0C00303B */  jal   joyGetStickX
/* 0F4428 7F0BF8F8 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F442C 7F0BF8FC A3A20018 */  sb    $v0, 0x18($sp)
/* 0F4430 7F0BF900 0C00307F */  jal   joyGetStickY
/* 0F4434 7F0BF904 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F4438 7F0BF908 A3A20019 */  sb    $v0, 0x19($sp)
/* 0F443C 7F0BF90C 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F4440 7F0BF910 0C0030C3 */  jal   joyGetButtons
/* 0F4444 7F0BF914 3405FFFF */   li    $a1, 65535
/* 0F4448 7F0BF918 83A40018 */  lb    $a0, 0x18($sp)
/* 0F444C 7F0BF91C 83A50019 */  lb    $a1, 0x19($sp)
/* 0F4450 7F0BF920 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F4454 7F0BF924 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F4458 7F0BF928 1000002F */  b     .L7F0BF9E8
/* 0F445C 7F0BF92C 00000000 */   nop
.L7F0BF930:
/* 0F4460 7F0BF930 0C00303B */  jal   joyGetStickX
/* 0F4464 7F0BF934 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F4468 7F0BF938 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F446C 7F0BF93C 0C00307F */  jal   joyGetStickY
/* 0F4470 7F0BF940 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F4474 7F0BF944 00022E00 */  sll   $a1, $v0, 0x18
/* 0F4478 7F0BF948 0005C603 */  sra   $t8, $a1, 0x18
/* 0F447C 7F0BF94C 03002825 */  move  $a1, $t8
/* 0F4480 7F0BF950 83A40018 */  lb    $a0, 0x18($sp)
/* 0F4484 7F0BF954 0FC2CB4E */  jal   sub_GAME_7F0B2D38
/* 0F4488 7F0BF958 00003025 */   move  $a2, $zero
/* 0F448C 7F0BF95C 10000022 */  b     .L7F0BF9E8
/* 0F4490 7F0BF960 00000000 */   nop
.L7F0BF964:
/* 0F4494 7F0BF964 0FC243C5 */  jal   getDebugMode
/* 0F4498 7F0BF968 00000000 */   nop
/* 0F449C 7F0BF96C 24010002 */  li    $at, 2
/* 0F44A0 7F0BF970 14410010 */  bne   $v0, $at, .L7F0BF9B4
/* 0F44A4 7F0BF974 00000000 */   nop
/* 0F44A8 7F0BF978 0C00303B */  jal   joyGetStickX
/* 0F44AC 7F0BF97C 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44B0 7F0BF980 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F44B4 7F0BF984 0C00307F */  jal   joyGetStickY
/* 0F44B8 7F0BF988 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44BC 7F0BF98C A3A20019 */  sb    $v0, 0x19($sp)
/* 0F44C0 7F0BF990 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F44C4 7F0BF994 0C0030C3 */  jal   joyGetButtons
/* 0F44C8 7F0BF998 3405FFFF */   li    $a1, 65535
/* 0F44CC 7F0BF99C 83A40018 */  lb    $a0, 0x18($sp)
/* 0F44D0 7F0BF9A0 83A50019 */  lb    $a1, 0x19($sp)
/* 0F44D4 7F0BF9A4 0FC21BE7 */  jal   bondviewMovePlayerUpdateViewport
/* 0F44D8 7F0BF9A8 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F44DC 7F0BF9AC 1000000C */  b     .L7F0BF9E0
/* 0F44E0 7F0BF9B0 00000000 */   nop
.L7F0BF9B4:
/* 0F44E4 7F0BF9B4 0C00303B */  jal   joyGetStickX
/* 0F44E8 7F0BF9B8 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44EC 7F0BF9BC A3A20018 */  sb    $v0, 0x18($sp)
/* 0F44F0 7F0BF9C0 0C00307F */  jal   joyGetStickY
/* 0F44F4 7F0BF9C4 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F44F8 7F0BF9C8 00022E00 */  sll   $a1, $v0, 0x18
/* 0F44FC 7F0BF9CC 0005CE03 */  sra   $t9, $a1, 0x18
/* 0F4500 7F0BF9D0 03202825 */  move  $a1, $t9
/* 0F4504 7F0BF9D4 83A40018 */  lb    $a0, 0x18($sp)
/* 0F4508 7F0BF9D8 0FC21BE7 */  jal   bondviewMovePlayerUpdateViewport
/* 0F450C 7F0BF9DC 00003025 */   move  $a2, $zero
.L7F0BF9E0:
/* 0F4510 7F0BF9E0 0FC30BA0 */  jal   sub_GAME_7F0C2E80
/* 0F4514 7F0BF9E4 00000000 */   nop
.L7F0BF9E8:
/* 0F4518 7F0BF9E8 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0F451C 7F0BF9EC 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0F4520 7F0BF9F0 8C4300A8 */  lw    $v1, 0xa8($v0)
/* 0F4524 7F0BF9F4 C4460408 */  lwc1  $f6, 0x408($v0)
/* 0F4528 7F0BF9F8 C44A0410 */  lwc1  $f10, 0x410($v0)
/* 0F452C 7F0BF9FC C4640008 */  lwc1  $f4, 8($v1)
/* 0F4530 7F0BFA00 C4680010 */  lwc1  $f8, 0x10($v1)
/* 0F4534 7F0BFA04 46062001 */  sub.s $f0, $f4, $f6
/* 0F4538 7F0BFA08 460A4081 */  sub.s $f2, $f8, $f10
/* 0F453C 7F0BFA0C 46000402 */  mul.s $f16, $f0, $f0
/* 0F4540 7F0BFA10 00000000 */  nop
/* 0F4544 7F0BFA14 46021482 */  mul.s $f18, $f2, $f2
/* 0F4548 7F0BFA18 0C007DF8 */  jal   sqrtf
/* 0F454C 7F0BFA1C 46128300 */   add.s $f12, $f16, $f18
/* 0F4550 7F0BFA20 3C028008 */  lui   $v0, %hi(g_playerPerm)
/* 0F4554 7F0BFA24 8C42A0B4 */  lw    $v0, %lo(g_playerPerm)($v0)
/* 0F4558 7F0BFA28 C4440038 */  lwc1  $f4, 0x38($v0)
/* 0F455C 7F0BFA2C 46002180 */  add.s $f6, $f4, $f0
/* 0F4560 7F0BFA30 0FC051D6 */  jal   get_scenario
/* 0F4564 7F0BFA34 E4460038 */   swc1  $f6, 0x38($v0)
/* 0F4568 7F0BFA38 24010002 */  li    $at, 2
/* 0F456C 7F0BFA3C 14410024 */  bne   $v0, $at, .L7F0BFAD0
/* 0F4570 7F0BFA40 00000000 */   nop
/* 0F4574 7F0BFA44 0FC233E0 */  jal   bondinvIsAliveWithFlag
/* 0F4578 7F0BFA48 00000000 */   nop
/* 0F457C 7F0BFA4C 1040001C */  beqz  $v0, .L7F0BFAC0
/* 0F4580 7F0BFA50 00000000 */   nop
/* 0F4584 7F0BFA54 0FC17674 */  jal   getCurrentPlayerWeaponId
/* 0F4588 7F0BFA58 00002025 */   move  $a0, $zero
/* 0F458C 7F0BFA5C 24010058 */  li    $at, 88
/* 0F4590 7F0BFA60 1041000B */  beq   $v0, $at, .L7F0BFA90
/* 0F4594 7F0BFA64 00002025 */   move  $a0, $zero
/* 0F4598 7F0BFA68 0FC17645 */  jal   currentPlayerEquipWeaponWrapper
/* 0F459C 7F0BFA6C 24050058 */   li    $a1, 88
/* 0F45A0 7F0BFA70 3C028008 */  lui   $v0, %hi(g_CurrentPlayer)
/* 0F45A4 7F0BFA74 8C42A0B0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0F45A8 7F0BFA78 24010002 */  li    $at, 2
/* 0F45AC 7F0BFA7C 24090005 */  li    $t1, 5
/* 0F45B0 7F0BFA80 8C480894 */  lw    $t0, 0x894($v0)
/* 0F45B4 7F0BFA84 15010002 */  bne   $t0, $at, .L7F0BFA90
/* 0F45B8 7F0BFA88 00000000 */   nop
/* 0F45BC 7F0BFA8C AC490894 */  sw    $t1, 0x894($v0)
.L7F0BFA90:
/* 0F45C0 7F0BFA90 3C038008 */  lui   $v1, %hi(g_playerPerm)
/* 0F45C4 7F0BFA94 2463A0B4 */  addiu $v1, %lo(g_playerPerm) # addiu $v1, $v1, -0x5f4c
/* 0F45C8 7F0BFA98 8C620000 */  lw    $v0, ($v1)
/* 0F45CC 7F0BFA9C 3C0B8005 */  lui   $t3, %hi(g_ClockTimer)
/* 0F45D0 7F0BFAA0 8D6B8374 */  lw    $t3, %lo(g_ClockTimer)($t3)
/* 0F45D4 7F0BFAA4 8C4A0060 */  lw    $t2, 0x60($v0)
/* 0F45D8 7F0BFAA8 240D0001 */  li    $t5, 1
/* 0F45DC 7F0BFAAC 014B6021 */  addu  $t4, $t2, $t3
/* 0F45E0 7F0BFAB0 AC4C0060 */  sw    $t4, 0x60($v0)
/* 0F45E4 7F0BFAB4 8C6E0000 */  lw    $t6, ($v1)
/* 0F45E8 7F0BFAB8 10000015 */  b     .L7F0BFB10
/* 0F45EC 7F0BFABC A1CD0069 */   sb    $t5, 0x69($t6)
.L7F0BFAC0:
/* 0F45F0 7F0BFAC0 3C0F8008 */  lui   $t7, %hi(g_playerPerm)
/* 0F45F4 7F0BFAC4 8DEFA0B4 */  lw    $t7, %lo(g_playerPerm)($t7)
/* 0F45F8 7F0BFAC8 10000011 */  b     .L7F0BFB10
/* 0F45FC 7F0BFACC A1E00069 */   sb    $zero, 0x69($t7)
.L7F0BFAD0:
/* 0F4600 7F0BFAD0 0FC051D6 */  jal   get_scenario
/* 0F4604 7F0BFAD4 00000000 */   nop
/* 0F4608 7F0BFAD8 24010003 */  li    $at, 3
/* 0F460C 7F0BFADC 5441000D */  bnel  $v0, $at, .L7F0BFB14
/* 0F4610 7F0BFAE0 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4614 7F0BFAE4 0FC233F0 */  jal   bondinvHasGoldenGun
/* 0F4618 7F0BFAE8 00000000 */   nop
/* 0F461C 7F0BFAEC 10400006 */  beqz  $v0, .L7F0BFB08
/* 0F4620 7F0BFAF0 3C088008 */   lui   $t0, %hi(g_playerPerm)
/* 0F4624 7F0BFAF4 3C198008 */  lui   $t9, %hi(g_playerPerm)
/* 0F4628 7F0BFAF8 8F39A0B4 */  lw    $t9, %lo(g_playerPerm)($t9)
/* 0F462C 7F0BFAFC 24180001 */  li    $t8, 1
/* 0F4630 7F0BFB00 10000003 */  b     .L7F0BFB10
/* 0F4634 7F0BFB04 A3380069 */   sb    $t8, 0x69($t9)
.L7F0BFB08:
/* 0F4638 7F0BFB08 8D08A0B4 */  lw    $t0, %lo(g_playerPerm)($t0)
/* 0F463C 7F0BFB0C A1000069 */  sb    $zero, 0x69($t0)
.L7F0BFB10:
/* 0F4640 7F0BFB10 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BFB14:
/* 0F4644 7F0BFB14 27BD0030 */  addiu $sp, $sp, 0x30
/* 0F4648 7F0BFB18 03E00008 */  jr    $ra
/* 0F464C 7F0BFB1C 00000000 */   nop
)
#endif

#if !defined(LEFTOVERDEBUG)
GLOBAL_ASM(
.text
glabel lvlUpdateMpPlayerData
/* 0F1634 7F0BEC44 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F1638 7F0BEC48 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F163C 7F0BEC4C 0FC269A4 */  jal   get_cur_playernum
/* 0F1640 7F0BEC50 00000000 */   nop   
/* 0F1644 7F0BEC54 0FC2436F */  jal   cheat_buttons_mp_related
/* 0F1648 7F0BEC58 A3A2002F */   sb    $v0, 0x2f($sp)
/* 0F164C 7F0BEC5C 0FC240FA */  jal   get_debug_freeze_processing
/* 0F1650 7F0BEC60 00000000 */   nop   
/* 0F1654 7F0BEC64 10400007 */  beqz  $v0, .L7F0BEC84
/* 0F1658 7F0BEC68 24010001 */   li    $at, 1
/* 0F165C 7F0BEC6C 1041002D */  beq   $v0, $at, .L7F0BED24
/* 0F1660 7F0BEC70 24010002 */   li    $at, 2
/* 0F1664 7F0BEC74 1041004C */  beq   $v0, $at, .L7F0BEDA8
/* 0F1668 7F0BEC78 00000000 */   nop   
/* 0F166C 7F0BEC7C 1000006B */  b     .L7F0BEE2C
/* 0F1670 7F0BEC80 00000000 */   nop   
.L7F0BEC84:
/* 0F1674 7F0BEC84 0FC240FC */  jal   getDebugMode
/* 0F1678 7F0BEC88 00000000 */   nop   
/* 0F167C 7F0BEC8C 10400009 */  beqz  $v0, .L7F0BECB4
/* 0F1680 7F0BEC90 00000000 */   nop   
/* 0F1684 7F0BEC94 0FC240FC */  jal   getDebugMode
/* 0F1688 7F0BEC98 00000000 */   nop   
/* 0F168C 7F0BEC9C 2401003B */  li    $at, 59
/* 0F1690 7F0BECA0 14410013 */  bne   $v0, $at, .L7F0BECF0
/* 0F1694 7F0BECA4 3C0E8003 */   lui   $t6, %hi(D_80036ABC) # $t6, 0x8003
/* 0F1698 7F0BECA8 8DCE2004 */  lw    $t6, %lo(D_80036ABC)($t6)
/* 0F169C 7F0BECAC 05C10010 */  bgez  $t6, .L7F0BECF0
/* 0F16A0 7F0BECB0 00000000 */   nop   
.L7F0BECB4:
/* 0F16A4 7F0BECB4 0C002B98 */  jal   joyGetStickX
/* 0F16A8 7F0BECB8 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F16AC 7F0BECBC A3A20018 */  sb    $v0, 0x18($sp)
/* 0F16B0 7F0BECC0 0C002BDC */  jal   joyGetStickY
/* 0F16B4 7F0BECC4 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F16B8 7F0BECC8 A3A20019 */  sb    $v0, 0x19($sp)
/* 0F16BC 7F0BECCC 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F16C0 7F0BECD0 0C002C20 */  jal   joyGetButtons
/* 0F16C4 7F0BECD4 3405FFFF */   li    $a1, 65535
/* 0F16C8 7F0BECD8 83A40018 */  lb    $a0, 0x18($sp)
/* 0F16CC 7F0BECDC 83A50019 */  lb    $a1, 0x19($sp)
/* 0F16D0 7F0BECE0 0FC24140 */  jal   sub_GAME_7F091080
/* 0F16D4 7F0BECE4 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F16D8 7F0BECE8 10000050 */  b     .L7F0BEE2C
/* 0F16DC 7F0BECEC 00000000 */   nop   
.L7F0BECF0:
/* 0F16E0 7F0BECF0 0C002B98 */  jal   joyGetStickX
/* 0F16E4 7F0BECF4 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F16E8 7F0BECF8 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F16EC 7F0BECFC 0C002BDC */  jal   joyGetStickY
/* 0F16F0 7F0BED00 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F16F4 7F0BED04 00022E00 */  sll   $a1, $v0, 0x18
/* 0F16F8 7F0BED08 00057E03 */  sra   $t7, $a1, 0x18
/* 0F16FC 7F0BED0C 01E02825 */  move  $a1, $t7
/* 0F1700 7F0BED10 83A40018 */  lb    $a0, 0x18($sp)
/* 0F1704 7F0BED14 0FC24140 */  jal   sub_GAME_7F091080
/* 0F1708 7F0BED18 00003025 */   move  $a2, $zero
/* 0F170C 7F0BED1C 10000043 */  b     .L7F0BEE2C
/* 0F1710 7F0BED20 00000000 */   nop   
.L7F0BED24:
/* 0F1714 7F0BED24 0FC240FC */  jal   getDebugMode
/* 0F1718 7F0BED28 00000000 */   nop   
/* 0F171C 7F0BED2C 24010001 */  li    $at, 1
/* 0F1720 7F0BED30 14410010 */  bne   $v0, $at, .L7F0BED74
/* 0F1724 7F0BED34 00000000 */   nop   
/* 0F1728 7F0BED38 0C002B98 */  jal   joyGetStickX
/* 0F172C 7F0BED3C 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F1730 7F0BED40 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F1734 7F0BED44 0C002BDC */  jal   joyGetStickY
/* 0F1738 7F0BED48 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F173C 7F0BED4C A3A20019 */  sb    $v0, 0x19($sp)
/* 0F1740 7F0BED50 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F1744 7F0BED54 0C002C20 */  jal   joyGetButtons
/* 0F1748 7F0BED58 3405FFFF */   li    $a1, 65535
/* 0F174C 7F0BED5C 83A40018 */  lb    $a0, 0x18($sp)
/* 0F1750 7F0BED60 83A50019 */  lb    $a1, 0x19($sp)
/* 0F1754 7F0BED64 0FC2C7FE */  jal   sub_GAME_7F0B2D38
/* 0F1758 7F0BED68 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F175C 7F0BED6C 1000002F */  b     .L7F0BEE2C
/* 0F1760 7F0BED70 00000000 */   nop   
.L7F0BED74:
/* 0F1764 7F0BED74 0C002B98 */  jal   joyGetStickX
/* 0F1768 7F0BED78 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F176C 7F0BED7C A3A20018 */  sb    $v0, 0x18($sp)
/* 0F1770 7F0BED80 0C002BDC */  jal   joyGetStickY
/* 0F1774 7F0BED84 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F1778 7F0BED88 00022E00 */  sll   $a1, $v0, 0x18
/* 0F177C 7F0BED8C 0005C603 */  sra   $t8, $a1, 0x18
/* 0F1780 7F0BED90 03002825 */  move  $a1, $t8
/* 0F1784 7F0BED94 83A40018 */  lb    $a0, 0x18($sp)
/* 0F1788 7F0BED98 0FC2C7FE */  jal   sub_GAME_7F0B2D38
/* 0F178C 7F0BED9C 00003025 */   move  $a2, $zero
/* 0F1790 7F0BEDA0 10000022 */  b     .L7F0BEE2C
/* 0F1794 7F0BEDA4 00000000 */   nop   
.L7F0BEDA8:
/* 0F1798 7F0BEDA8 0FC240FC */  jal   getDebugMode
/* 0F179C 7F0BEDAC 00000000 */   nop   
/* 0F17A0 7F0BEDB0 24010002 */  li    $at, 2
/* 0F17A4 7F0BEDB4 14410010 */  bne   $v0, $at, .L7F0BEDF8
/* 0F17A8 7F0BEDB8 00000000 */   nop   
/* 0F17AC 7F0BEDBC 0C002B98 */  jal   joyGetStickX
/* 0F17B0 7F0BEDC0 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F17B4 7F0BEDC4 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F17B8 7F0BEDC8 0C002BDC */  jal   joyGetStickY
/* 0F17BC 7F0BEDCC 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F17C0 7F0BEDD0 A3A20019 */  sb    $v0, 0x19($sp)
/* 0F17C4 7F0BEDD4 83A4002F */  lb    $a0, 0x2f($sp)
/* 0F17C8 7F0BEDD8 0C002C20 */  jal   joyGetButtons
/* 0F17CC 7F0BEDDC 3405FFFF */   li    $a1, 65535
/* 0F17D0 7F0BEDE0 83A40018 */  lb    $a0, 0x18($sp)
/* 0F17D4 7F0BEDE4 83A50019 */  lb    $a1, 0x19($sp)
/* 0F17D8 7F0BEDE8 0FC21C2F */  jal   bondviewMovePlayerUpdateViewport
/* 0F17DC 7F0BEDEC 3046FFFF */   andi  $a2, $v0, 0xffff
/* 0F17E0 7F0BEDF0 1000000C */  b     .L7F0BEE24
/* 0F17E4 7F0BEDF4 00000000 */   nop   
.L7F0BEDF8:
/* 0F17E8 7F0BEDF8 0C002B98 */  jal   joyGetStickX
/* 0F17EC 7F0BEDFC 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F17F0 7F0BEE00 A3A20018 */  sb    $v0, 0x18($sp)
/* 0F17F4 7F0BEE04 0C002BDC */  jal   joyGetStickY
/* 0F17F8 7F0BEE08 83A4002F */   lb    $a0, 0x2f($sp)
/* 0F17FC 7F0BEE0C 00022E00 */  sll   $a1, $v0, 0x18
/* 0F1800 7F0BEE10 0005CE03 */  sra   $t9, $a1, 0x18
/* 0F1804 7F0BEE14 03202825 */  move  $a1, $t9
/* 0F1808 7F0BEE18 83A40018 */  lb    $a0, 0x18($sp)
/* 0F180C 7F0BEE1C 0FC21C2F */  jal   bondviewMovePlayerUpdateViewport
/* 0F1810 7F0BEE20 00003025 */   move  $a2, $zero
.L7F0BEE24:
/* 0F1814 7F0BEE24 0FC308D8 */  jal   sub_GAME_7F0C2E80
/* 0F1818 7F0BEE28 00000000 */   nop   
.L7F0BEE2C:
/* 0F181C 7F0BEE2C 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0F1820 7F0BEE30 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0F1824 7F0BEE34 8C4300A8 */  lw    $v1, 0xa8($v0)
/* 0F1828 7F0BEE38 C4460408 */  lwc1  $f6, 0x408($v0)
/* 0F182C 7F0BEE3C C44A0410 */  lwc1  $f10, 0x410($v0)
/* 0F1830 7F0BEE40 C4640008 */  lwc1  $f4, 8($v1)
/* 0F1834 7F0BEE44 C4680010 */  lwc1  $f8, 0x10($v1)
/* 0F1838 7F0BEE48 46062001 */  sub.s $f0, $f4, $f6
/* 0F183C 7F0BEE4C 460A4081 */  sub.s $f2, $f8, $f10
/* 0F1840 7F0BEE50 46000402 */  mul.s $f16, $f0, $f0
/* 0F1844 7F0BEE54 00000000 */  nop   
/* 0F1848 7F0BEE58 46021482 */  mul.s $f18, $f2, $f2
/* 0F184C 7F0BEE5C 0C007614 */  jal   sqrtf
/* 0F1850 7F0BEE60 46128300 */   add.s $f12, $f16, $f18
/* 0F1854 7F0BEE64 3C028007 */  lui   $v0, %hi(g_playerPerm) # $v0, 0x8007
/* 0F1858 7F0BEE68 8C428BC4 */  lw    $v0, %lo(g_playerPerm)($v0)
/* 0F185C 7F0BEE6C C4440038 */  lwc1  $f4, 0x38($v0)
/* 0F1860 7F0BEE70 46002180 */  add.s $f6, $f4, $f0
/* 0F1864 7F0BEE74 0FC051B2 */  jal   get_scenario
/* 0F1868 7F0BEE78 E4460038 */   swc1  $f6, 0x38($v0)
/* 0F186C 7F0BEE7C 24010002 */  li    $at, 2
/* 0F1870 7F0BEE80 14410024 */  bne   $v0, $at, .L7F0BEF14
/* 0F1874 7F0BEE84 00000000 */   nop   
/* 0F1878 7F0BEE88 0FC234D9 */  jal   bondinvIsAliveWithFlag
/* 0F187C 7F0BEE8C 00000000 */   nop   
/* 0F1880 7F0BEE90 1040001C */  beqz  $v0, .L7F0BEF04
/* 0F1884 7F0BEE94 00000000 */   nop   
/* 0F1888 7F0BEE98 0FC177A2 */  jal   getCurrentPlayerWeaponId
/* 0F188C 7F0BEE9C 00002025 */   move  $a0, $zero
/* 0F1890 7F0BEEA0 24010058 */  li    $at, 88
/* 0F1894 7F0BEEA4 1041000B */  beq   $v0, $at, .L7F0BEED4
/* 0F1898 7F0BEEA8 00002025 */   move  $a0, $zero
/* 0F189C 7F0BEEAC 0FC17773 */  jal   currentPlayerEquipWeaponWrapper
/* 0F18A0 7F0BEEB0 24050058 */   li    $a1, 88
/* 0F18A4 7F0BEEB4 3C028007 */  lui   $v0, %hi(g_CurrentPlayer) # $v0, 0x8007
/* 0F18A8 7F0BEEB8 8C428BC0 */  lw    $v0, %lo(g_CurrentPlayer)($v0)
/* 0F18AC 7F0BEEBC 24010002 */  li    $at, 2
/* 0F18B0 7F0BEEC0 24090005 */  li    $t1, 5
/* 0F18B4 7F0BEEC4 8C48088C */  lw    $t0, 0x88c($v0)
/* 0F18B8 7F0BEEC8 15010002 */  bne   $t0, $at, .L7F0BEED4
/* 0F18BC 7F0BEECC 00000000 */   nop   
/* 0F18C0 7F0BEED0 AC49088C */  sw    $t1, 0x88c($v0)
.L7F0BEED4:
/* 0F18C4 7F0BEED4 3C038007 */  lui   $v1, %hi(g_playerPerm) # $v1, 0x8007
/* 0F18C8 7F0BEED8 24638BC4 */  addiu $v1, %lo(g_playerPerm) # addiu $v1, $v1, -0x743c
/* 0F18CC 7F0BEEDC 8C620000 */  lw    $v0, ($v1)
/* 0F18D0 7F0BEEE0 3C0B8004 */  lui   $t3, %hi(g_ClockTimer) # $t3, 0x8004
/* 0F18D4 7F0BEEE4 8D6B0FF4 */  lw    $t3, %lo(g_ClockTimer)($t3)
/* 0F18D8 7F0BEEE8 8C4A0060 */  lw    $t2, 0x60($v0)
/* 0F18DC 7F0BEEEC 240D0001 */  li    $t5, 1
/* 0F18E0 7F0BEEF0 014B6021 */  addu  $t4, $t2, $t3
/* 0F18E4 7F0BEEF4 AC4C0060 */  sw    $t4, 0x60($v0)
/* 0F18E8 7F0BEEF8 8C6E0000 */  lw    $t6, ($v1)
/* 0F18EC 7F0BEEFC 10000015 */  b     .L7F0BEF54
/* 0F18F0 7F0BEF00 A1CD0069 */   sb    $t5, 0x69($t6)
.L7F0BEF04:
/* 0F18F4 7F0BEF04 3C0F8007 */  lui   $t7, %hi(g_playerPerm) # $t7, 0x8007
/* 0F18F8 7F0BEF08 8DEF8BC4 */  lw    $t7, %lo(g_playerPerm)($t7)
/* 0F18FC 7F0BEF0C 10000011 */  b     .L7F0BEF54
/* 0F1900 7F0BEF10 A1E00069 */   sb    $zero, 0x69($t7)
.L7F0BEF14:
/* 0F1904 7F0BEF14 0FC051B2 */  jal   get_scenario
/* 0F1908 7F0BEF18 00000000 */   nop   
/* 0F190C 7F0BEF1C 24010003 */  li    $at, 3
/* 0F1910 7F0BEF20 5441000D */  bnel  $v0, $at, .L7F0BEF58
/* 0F1914 7F0BEF24 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F1918 7F0BEF28 0FC234E9 */  jal   bondinvHasGoldenGun
/* 0F191C 7F0BEF2C 00000000 */   nop   
/* 0F1920 7F0BEF30 10400006 */  beqz  $v0, .L7F0BEF4C
/* 0F1924 7F0BEF34 3C088007 */   lui   $t0, %hi(g_playerPerm) # $t0, 0x8007
/* 0F1928 7F0BEF38 3C198007 */  lui   $t9, %hi(g_playerPerm) # $t9, 0x8007
/* 0F192C 7F0BEF3C 8F398BC4 */  lw    $t9, %lo(g_playerPerm)($t9)
/* 0F1930 7F0BEF40 24180001 */  li    $t8, 1
/* 0F1934 7F0BEF44 10000003 */  b     .L7F0BEF54
/* 0F1938 7F0BEF48 A3380069 */   sb    $t8, 0x69($t9)
.L7F0BEF4C:
/* 0F193C 7F0BEF4C 8D088BC4 */  lw    $t0, %lo(g_playerPerm)($t0)
/* 0F1940 7F0BEF50 A1000069 */  sb    $zero, 0x69($t0)
.L7F0BEF54:
/* 0F1944 7F0BEF54 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0BEF58:
/* 0F1948 7F0BEF58 27BD0030 */  addiu $sp, $sp, 0x30
/* 0F194C 7F0BEF5C 03E00008 */  jr    $ra
/* 0F1950 7F0BEF60 00000000 */   nop   
)
#endif
#endif





void lvlUnloadStageTextData(void)
{
    if (g_MpSoundStateRelated != NULL)
    {
        if (sndGetPlayingState(g_MpSoundStateRelated) != AL_STOPPED)
        {
            sndDeactivate(g_MpSoundStateRelated);
        }
    }

    if (g_CurrentStageToLoad != LEVELID_TITLE)
    {
        blank_text_bank(get_textbank_number_for_stagenum(g_CurrentStageToLoad));
        sub_GAME_7F007770();
    }

    cheatDisableAllCheats();
    cleanupGuardData();
    cleanupObjectSounds();
    cleanupExplosions();
    cleanup_window_pieces();
    cleanup_REMOVED_();
    cleanupAlarms();
    cleanupObjects(g_CurrentStageToLoad);
    cleanupObjectives();
    cleanupSFXRelated();
    cleanupplayersoundrelated();
    sub_GAME_7F0C1268();
    sub_GAME_7F0B47E0();
}


void lvlSetControlsLockedFlag(s32 arg0)
{
    #if defined(BUGFIX_R1)
    if ((arg0 != 0) && (g_ControlsLockedFlag == 0))
    {
        joyRumblePakStop();
    }
    #endif

    g_ControlsLockedFlag = arg0;
}


s32 lvlGetControlsLockedFlag(void)
{
    return g_ControlsLockedFlag;
}


DIFFICULTY lvlGetSelectedDifficulty(void)
{
    return g_SelectedDifficulty;
}


void lvlSetSelectedDifficulty(DIFFICULTY arg0)
{
    g_SelectedDifficulty = arg0;
}

void lvlSetMpTime(s32 arg0)
{
    g_MpTime = arg0;
}


void lvlSetMpPoint(s32 arg0)
{
    g_MpPoint = arg0;
}


f32 lvlGetCurrentMultiPlayerSec(void)
{
    return g_CurrentMultiPlayerSec;
}


f32 lvlGetCurrentMultiPlayerMin(void)
{
    return g_CurrentMultiPlayerMin;
}


/**
 * Unreferenced.
 */
f32 lvlGetStageTimeSec(void)
{
    return g_StageTimeSec;
}


/**
 * Unreferenced.
 */
f32 lvlGetPowerOnTimeSec(void)
{
    return g_PowerOnTimeSec;
}


