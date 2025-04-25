#include <ultra64.h>
#include "debugmenu_handler.h"
#include "initgamedata.h"
#include <boss.h>
#include <fr.h>

#if defined(LEFTOVERDEBUG)

// data
//D:80036BA0
u32 D_80036BA0 = 0;
//D:80036BA4
s32 g_DebugMenuOffsets[] = 
{
       8, 0x13, 0x1E, 0x2B, 
    0x32, 0x39, 0x45, 0x4D, 
    -1
};

//D:80036BC8
struct mcm_layout g_DebugMenuPositions[] = {
    {8, 5},
    {8, 6},
    {8, 7},
    {8, 8},
    {8, 9},
    {8, 0xA},
    {8, 0xB},
    {8, 0xC},

    {0x19, 5},
    {0x19, 6},
    {0x19, 7},
    {0x19, 8},
    {0x19, 9},
    {0x19, 0xA},
    {0x19, 0xB},
    {0x19, 0xC},
    {0x19, 0xD},
    {0x19, 0xE},
    {0x19, 0xF},

    {0x28, 5},
    {0x28, 6},
    {0x28, 7},
    {0x28, 8},
    {0x28, 9},
    {0x28, 0xA},
    {0x28, 0xB},
    {0x28, 0xC},
    {0x28, 0xD},
    {0x28, 0xE},
    {0x28, 0xF},

    {0x39, 5},
    {0x39, 6},
    {0x39, 7},
    {0x39, 8},
    {0x39, 9},
    {0x39, 0xA},
    {0x39, 0xB},
    {0x39, 0xC},
    {0x39, 0xD},
    {0x39, 0xE},
    {0x39, 0xF},
    {0x39, 0x10},
    {0x39, 0x11},

    {8, 0x14},
    {8, 0x15},
    {8, 0x16},
    {8, 0x17},
    {8, 0x18},
    {8, 0x19},
    {8, 0x1A},

    {0x19, 0x14},
    {0x19, 0x15},
    {0x19, 0x16},
    {0x19, 0x17},
    {0x19, 0x18},
    {0x19, 0x19},
    {0x19, 0x1A},

    {0x28, 0x14},
    {0x28, 0x15},
    {0x28, 0x16},
    {0x28, 0x17},
    {0x28, 0x18},
    {0x28, 0x19},
    {0x28, 0x1A},
    {0x28, 0x1B},
    {0x28, 0x1C},
    {0x28, 0x1D},
    {0x28, 0x1E},
    {0x28, 0x1F},

    {0x39, 0x14},
    {0x39, 0x15},
    {0x39, 0x16},
    {0x39, 0x17},
    {0x39, 0x18},
    {0x39, 0x19},
    {0x39, 0x1A},
    {0x39, 0x1B}
};

//D:80036E30
char *mcm_strings[] = {
     "move view",
     "stan view",
     "bond view",
     "level",
     "region",
     "scale",
     "play title",
     "bond die",

     "select anim",
     "gun pos",
     "flash colour",
     "hit colour",
     "music",
     "sfx",
     "invincible",
     "visible",
     "collisions",
     "all guns",
     "max ammo",

     "display speed",
     "background",
     "props",
     "stan hit",
     "stan region",
     "stan problems",
     "print man pos",
     "port close",
     "port inf",
     "port approx",
     "pr room loads",

     "show mem use",
     "show mem bars",
     "grab rgb",
     "grab jpeg",
     "grab task",
     "rnd walk",
     "record ramrom",
     "record 1",
     "record 2",
     "record 3",
     "replay ramrom",
     "save ramrom",
     "load ramrom",

     "auto y aim",
     "auto x aim",
     "007",
     "agent",
     "all",
     "fast",
     "objectives",

     "marg top",
     "marg bot",
     "marg left",
     "marg right",
     "marg reset",
     "screen size",
     "screen pos",

     "show patrols",
     "intro",
     "intro edit",
     "intro pos",
     "world pos",
     "gun key pos",
     "vis cvg",
     "chr num",
     "room blocks",
     "profile",
     "obj load",
     "weapon load",

     "joy2 sky edit",
     "joy2 hits edit",
     "joy2 detail edit",
     "explosion info",
     "magic fog",
     "gun watch pos",
     "testing man pos",
     "fog"
};

//D:80036F64
s32 debug_render_raster = DEB_BOND_VIEW;
//D:80036F68
s32 debug_freeze_processing = DEB_BOND_VIEW;
//D:80036F6C
s32 g_DebugMode = DEB_BOND_VIEW;
//D:80036F70
s32 g_DebugHighlightedOption = DEB_BOND_VIEW;
//D:80036F74
s32 memusage_display_flag = FALSE;
//D:80036F78
s32 debug_do_draw_bg = TRUE;
//D:80036F7C
s32 debug_do_draw_obj = TRUE;
//D:80036F80
s32 debug_unknown2 = 1;
//D:80036F84
s32 debug_stanhit_flag = FALSE;
//D:80036F88
s32 debug_stanregion_flag = FALSE;
//D:80036F8C
s32 debug_stan_problems_flag = FALSE;
//D:80036F90
s32 debug_man_pos_flag = 0;
//D:80036F94
s32 debug_prroomloads_flag = 0;
//D:80036F98
s32 debug_joy2skyedit_flag = 0;
//D:80036F9C
s32 debug_joy2hitsedit_flag = 0;
//D:80036FA0
s32 debug_joy2detailedit_flag = 0;
//D:80036FA4
s32 debug_explosioninfo_flag = 0;
#endif

#if !defined(LEFTOVERDEBUG)
/**
 * The .data debug_VisCVG_flag needs to be at address 0x800320b4, which means
 * there needs to be another .data word. Probably one of the above values,
 * but not sure which one. Declaring new word here until this is resolved.
*/
s32 eu_D_800320b0 = 0;
#endif

//D:80036FA8
s32 debug_VisCVG_flag = 0;

#if defined(LEFTOVERDEBUG)
//D:80036FAC
s32 debug_007_unlock_flag = 0;
//D:80036FB0
s32 debug_enable_agent_levels_flag = 0;
//D:80036FB4
s32 debug_enable_all_levels_flag = 0;
//D:80036FB8
s32 debug_chrnum_flag = 0;

//D:80036FBC
s32 debug_gunwatchpos_flags = 0;
//D:80036FC0
s32 debug_profile_flag = 0;
//D:80036FC4
s32 debug_enable_taskgrab_flag = 0;
//D:80036FC8
s32 g_DebugManPos = 0;
#endif

//D:80036FCC
s32 debug_fast_bond_flag = 0;

#if defined(LEFTOVERDEBUG)
//D:80036FD0
s32 debug_all_obj_complete_flag = 0 ;
//D:80036FD4
s32 debug_portal_flag = 0;

//D:80036FD8
u32 dword_D_80036FD8[] = {
    0x80500000,
    0x40000,
    0x7F000000,
    0x7F100000
};

u32 dword_D_80036FE8[] = {
    0x80600000,
    0x40000,
    0x70000000,
    0x70100000
};

//D:80036FF8
s32 show_debug_menu_flag = 0;


struct ScreenshotFlag {
    s32 flag;
};

//D:80036FFC
struct ScreenshotFlag g_DebugScreenshotFlagRgb = { 0 };
//D:80037000
struct ScreenshotFlag g_DebugScreenshotFlagJpg = { 0 };

//D:80037004
coord3d player_pos_x = {0};

#endif


/*
* Address: 0x7f090490
*/
void debugmenuUpdate(void)
{
    #if defined(LEFTOVERDEBUG)
    debmenuSetMenu(&mcm_strings, &g_DebugMenuPositions, &g_DebugMenuOffsets);
    #endif
}

#if defined(LEFTOVERDEBUG)
/*
* Address: 0x7f0904c4
*/
void debmenuHandleMoveView(void)
{
    resetDebugCameraToPlayerPosition();
    g_DebugHighlightedOption = get_highlighted_debug_option();
    debug_render_raster = debug_freeze_processing = g_DebugHighlightedOption;
}
#endif

#if defined(LEFTOVERDEBUG)
/*
* Address: 0x7f090508
*/
void debmenuHandleStanView(void)
{
    maybe_solo_intro_camera_handler();
    g_DebugHighlightedOption = get_highlighted_debug_option();
    debug_render_raster = debug_freeze_processing = g_DebugHighlightedOption;
}
#endif

#if defined(LEFTOVERDEBUG)
/*
* Address: 0x7f09054c
*/
void debmenuHandleBondView(void)
{
    maybe_solo_intro_camera_handler();
    g_DebugHighlightedOption = get_highlighted_debug_option();
    debug_render_raster = debug_freeze_processing = g_DebugHighlightedOption;
}
#endif

#if defined(LEFTOVERDEBUG)
/*
* Address: 0x7f090590
*/
void removed_do_debug_profile_flag_false(void) {
    return;
}
#endif

#if defined(LEFTOVERDEBUG)
/*
* Address: 0x7f090598
*/
void removed_do_debug_profile_flag_true(void) {
    return;
}
#endif





#if defined(LEFTOVERDEBUG)
/**
 * Address 0x7F0905A0 NTSC
*/
s32 debug_menu_processor(s8 stick_h, s8 stick_v, u16 button_held, u16 button_pressed)
{
    s32 i1;
    s32 i2;
    s32 sp54;
    struct PropRecord *playerprop;
    s32 varv0;
    s32 padding_0;
    s32 padding_1;
    s32 padding_2;
    struct ScreenshotFlag *pscreehshotFlagRgb = &g_DebugScreenshotFlagRgb;
    struct ScreenshotFlag *pscreehshotFlagJpg = &g_DebugScreenshotFlagJpg;
    s32 padding_5;
    s32* p32;
    s32 padding_7;
    f32 tempx;
    f32 tempz;
    f32 tempy;

    if(pscreehshotFlagRgb == NULL);
    
    if (pscreehshotFlagRgb->flag && pscreehshotFlagRgb->flag++ == 3)
    {
        indyGrabRgb32bit();
        pscreehshotFlagRgb->flag = 0;
        viSetColorMode16Bit();
        osViBlack(0U);
    }

    if (pscreehshotFlagJpg->flag && pscreehshotFlagJpg->flag++ == 3)
    {
        indyGrabJpg32bit();
        pscreehshotFlagJpg->flag = 0;
        viSetColorMode16Bit();
        osViBlack(0U);
    }

    if (!show_debug_menu_flag)
    {
        varv0 = (button_held & U_CBUTTONS) && (button_held & D_CBUTTONS);
        
        show_debug_menu_flag = varv0;

        if (varv0)
        {
            stop_recording_ramrom(button_held);
        }

        return show_debug_menu_flag;
    }
    else
    {        
        if (g_DebugMode != -2)
        {
            g_DebugHighlightedOption = g_DebugMode;
            g_DebugMode = -2;
        }
        
        if ((button_pressed & L_JPAD))
        {
            gotoLeftDebugOption();
            g_DebugMode = -2;
        }

        if ((button_pressed & R_JPAD))
        {
            gotoRightDebugOption();
            g_DebugMode = -2;
        }

        if ((button_pressed & U_JPAD))
        {
            gotoAboveDebugOption();
            g_DebugMode = -2;
        }

        if ((button_pressed & D_JPAD))
        {
            gotoBelowDebugOption();
            g_DebugMode = -2;
        }
        
        if ((button_pressed & (START_BUTTON | A_BUTTON)))
        {
            switch (get_highlighted_debug_option()) {
                
            case DEB_MOVE_VIEW: // move view
                debmenuHandleMoveView();
                break;
                
            case DEB_STAN_VIEW: // stan view
                debmenuHandleStanView();
                break;
                
            case DEB_BOND_VIEW: // bond view
                debmenuHandleBondView();
                break;
                
            case DEB_LEVEL: // level
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_REGION: // region
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_SCALE: // scale
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_SELANIM: // select anim
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_GUNPOS: // gun pos
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_FLASHCOLOR: // flash colour
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_HITCOLOR: // hit colour
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;

#ifdef XBLADEBUG
            case DEB_MARGTOP: //marg top
            /*
                printf("Margins: %5.2f.0F %5.2f.0F %5.2f.0F %5.2f.0F\n",
                    bgTimesAddViewRelatedMaybe(1.0,0.0,0),
                    bgTimesAddViewRelatedMaybe(1.0,(((button_pressed & 1) >> 5 & 1 ^ 1) - ((button_pressed & 2) >> 5 & 1 ^ 1)) * 4.0,1),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,2),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,3));
            //*/
            case DEB_MARGBOT: //marg bot
            /*
                printf("Margins: %5.2f.0F %5.2f.0F %5.2f.0F %5.2f.0F\n",
                    bgTimesAddViewRelatedMaybe(1.0,0.0,0),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,1),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,2),
                    bgTimesAddViewRelatedMaybe(1.0,(((button_pressed & 1) >> 5 & 1 ^ 1) - ((button_pressed & 2) >> 5 & 1 ^ 1)) * 4.0,3));
            //*/
            case DEB_MARGLEFT: //marg left
            /*
                printf("Margins: %5.2f.0F %5.2f.0F %5.2f.0F %5.2f.0F\n",
                    bgTimesAddViewRelatedMaybe(1.0,(((button_pressed & 1) >> 5 & 1 ^ 1) - ((button_pressed & 2) >> 5 & 1 ^ 1)) * 4.0,0),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,1),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,2),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,3));
            //*/
            case DEB_MARGRIGHT: //marg right
            /*
                printf("Margins: %5.2f.0F %5.2f.0F %5.2f.0F %5.2f.0F\n",
                    bgTimesAddViewRelatedMaybe(1.0,0.0,0),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,1),
                    bgTimesAddViewRelatedMaybe(1.0,(((button_pressed & 1) >> 5 & 1 ^ 1) - ((button_pressed & 2) >> 5 & 1 ^ 1)) * 4.0,2),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,3));
            //*/
            case DEB_MARGRESET: //marg reset
            /*
                printf("Margins: %5.2f.0F %5.2f.0F %5.2f.0F %5.2f.0F\n",
                    bgTimesAddViewRelatedMaybe(1.0,0.0,0),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,1),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,2),
                    bgTimesAddViewRelatedMaybe(1.0,0.0,3));
            //*/
                break;
#endif
            case DEB_SCREENSIZE: // screen size
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_SCREENPOS: // screen pos
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_MUSIC: // music
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_PORTCLOSE: // port close   
            case DEB_PORT_INF: // port inf
            case DEB_PORT_APPROX: // port approx
                debug_portal_flag ^= 1;
                break;
                
            case DEB_SFX: // sfx
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_INVINCIBLE: // invincible
                set_bondata_invincible_flag(get_bondata_invincible_flag() == 0);
                break;
                
            case DEB_VISIBILE: // visible
                bondviewSetVisibleToGuardsFlag(bondviewGetVisibleToGuardsFlag() == 0);
                break;
                
            case DEB_COLLISIONS: // collisions
                set_obj_collision_flag(get_obj_collision_flag() == FALSE);
                break;
                
            case DEB_ALLGUNS: // all guns
            {
                for (i1 = 0; i1 < getPlayerCount(); i1++)
                {
                    set_cur_player(i1);
                    bondinvSetAllGunsFlag(bondinvGetAllGunsFlag() == 0);
                }
                break;
            }
                
            case DEB_MAXAMMO: // max ammo
            {
                sp54 = get_cur_playernum();
                for (i2 = 0; i2 < getPlayerCount(); i2++)
                {
                    set_cur_player(i2);
                    set_max_ammo_for_cur_player();
                }
                set_cur_player(sp54);
                break;
            }
                
            case DEB_DISPSPEED: // display speed
                memusage_display_flag ^= 1;
                if (memusage_display_flag == 0)
                {
                    debmenuReset();
                }
                break;
                
            case DEB_BG: // background
                debug_do_draw_bg ^= 1;
                break;
                
            case DEB_PROPS: // props
                debug_do_draw_obj ^= 1;
                break;
                
            case DEB_STANHIT: // stan hit
                debug_stanhit_flag ^= 1;
                break;
                
            case DEB_STANREGION: // stan region
                debug_stanregion_flag ^= 1;
                break;
                
            case DEB_STANPROBLEMS: // stan problems
                debug_stan_problems_flag ^= 1;
                break;
                
            case DEB_PRTMANPOS: // print man pos
                debug_man_pos_flag ^= 1;
                break;
                
            case DEB_TESTINGMANPOS: // testing man pos
                g_DebugManPos ^= 1;
                break;
                
            case DEB_PLAYTITLE: // play title
                bossSetLoadedStage(LEVELID_TITLE);
                break;
                
            case DEB_BONDDIE: // bond die
                bondviewKillCurrentPlayer();
                break;
                
            case DEB_PRROOMLOADS: // pr room loads
                debug_prroomloads_flag ^= 1;
                break;
                
            case DEB_SHOWMEMUSE: // show mem use
                bossEnableShowMemUseFlag();
                break;
                
            case DEB_SHOWMEMBARS: // show mem bars
                bossMemBarsFlagToggle();
                break;
                
            case DEB_GRABRGB: // grab rgb
                pscreehshotFlagRgb->flag = 1;
                osViBlack(1);
                viSetColorMode32Bit();
                break;
                
            case DEB_GRABJPG: // grab jpeg
                pscreehshotFlagJpg->flag = 1;
                osViBlack(1);
                viSetColorMode32Bit();
                break;
                
            case DEB_TASKGRAB: // grab task
                debug_enable_taskgrab_flag ^= 1;
                break;
                
            case DEB_RNDWALK: //rnd walk
              break;
                
            case DEB_RECRAMROM: // record ramrom
                setRamRomRecordSlot(0);
                break;
                
            case DEB_RECORD1: // record 1
                setRamRomRecordSlot(1);
                break;
                
            case DEB_RECORD2: // record 2
                setRamRomRecordSlot(2);
                break;
                
            case DEB_RECORD3: // record 3
                setRamRomRecordSlot(3);
                break;
                
            case DEB_REPLAYRAMROM: // replay ramrom
                replay_recorded_ramrom_from_indy();
                break;
                
            case DEB_SAVERAMROM: // save ramrom
                save_ramrom_to_devtool();
                break;
                
            case DEB_LOADRAMROM: // load ramrom
                load_ramrom_from_devtool();
                break;
                
            case DEB_AUTOAIMY: // auto y aim
                set_BONDdata_autoaim_y(get_BONDdata_autoaim_y() == 0);
                break;
                
            case DEB_AUTOAIMX: // auto x aim
                set_BONDdata_autoaim_x(get_BONDdata_autoaim_x() == 0);
                break;
                
            case DEB_007: // 007
                debug_007_unlock_flag ^= 1;
                break;
                
            case DEB_AGENT: // agent
                debug_enable_agent_levels_flag ^= 1;
                break;
                
            case DEB_ALL: // all
                debug_enable_all_levels_flag ^= 1;
                break;
                
            case DEB_FAST: // fast
                debug_fast_bond_flag ^= 1;
                break;
                
            case DEB_OBJECTIVES: // objectives
                debug_all_obj_complete_flag ^= 1;
                break;
                
            case DEB_SHOWPATROLS: // show patrols
                set_show_patrols_flag(get_show_patrols_flag() == FALSE);
                break;
                
            case DEB_INTRO: // intro
                bondviewSetCameraMode(CAMERAMODE_SWIRL);
                break;
                
            case DEB_INTRO_POS: // intro pos
                if (debug_render_raster == DEB_MOVE_VIEW)
                {
                    initializeDebugCameraPosition();
                }
                break;
                
            case DEB_WORLD_POS: // world pos
                if (debug_render_raster == DEB_MOVE_VIEW)
                {
                    updateDebugCameraWorldPosition();
                }
                else
                {
                    playerprop = get_curplayer_positiondata();
                    if (playerprop)
                    {
                        
                        tempx = playerprop->pos.f[0] - player_pos_x.x;
                        tempy = playerprop->pos.f[1] - player_pos_x.y;
                        tempz = playerprop->pos.f[2] - player_pos_x.z;
                        sqrtf(((tempx) * (tempx)) + 
                              ((tempy) * (tempy)) + 
                              ((tempz) * (tempz)));
                        player_pos_x.x = (f32) playerprop->pos.f[0];
                        player_pos_x.y = (f32) playerprop->pos.f[1];
                        player_pos_x.z = (f32) playerprop->pos.f[2];

                        #ifdef ENABLE_LOG
                        osSyncPrintf("%s%sbond world pos=%f,%f,%f dist from prev=%f\n",
                                     "",
                                     "",
                                     playerprop->pos.f[0],
                                     playerprop->pos.f[1],
                                     playerprop->pos.f[2],
                                     sqrtf(((tempx) * (tempx)) +
                                           ((tempy) * (tempy)) +
                                           ((tempz) * (tempz))));
                        #endif
                    }
                }
                break;
                
            case DEB_GUNKEYPOS: // gun key pos
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_CHRNUM: // chr num
                debug_chrnum_flag ^= 1;
                break;
                
            case DEB_VISCVG: // vis cvg
                debug_VisCVG_flag ^= 1;
                break;
                
            case DEB_JOY2SKYEDIT: // joy2 sky edit
                debug_joy2skyedit_flag ^= 1;
                break;
                
            case DEB_JOY2HITSEDIT: // joy2 hits edit
                debug_joy2hitsedit_flag ^= 1;
                break;
                
            case DEB_JOY2DETAILEDIT: // joy2 detail edit
                debug_joy2detailedit_flag ^= 1;
                break;
                
            case DEB_EXPLOSIONINFO: // explosion info
                debug_explosioninfo_flag ^= 1;
                break;
                
            case DEB_MAGICFOG: // magic fog
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_FOG: // fog
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
                
            case DEB_GUNWATCHPOS: // gun watch pos
                debug_gunwatchpos_flags ^= 1;
                break;
                
            case DEB_ROOMBLOCKS: // room blocks
                removed_debug_roomblocks_feature();
                break;
                
            case DEB_PROFILE: // profile
            {
                debug_profile_flag ^= 1;
                if (debug_profile_flag)
                {
                    removed_do_debug_profile_flag_false();
                }
                else
                {
                    removed_do_debug_profile_flag_true();
                }
                break;
            }
                
            case DEB_OBJLOAD: // obj load
                debug_object_load_all_models();
                break;
                
            case DEB_WEAPONLOAD: // weapon load
                debug_weapon_load_table();
                break;
                
            case DEB_INTRO_EDIT: // intro edit
                g_DebugHighlightedOption = get_highlighted_debug_option();
                break;
            }
        }
        
        if ((button_pressed & (R_CBUTTONS | L_CBUTTONS)))
        {
            switch (get_highlighted_debug_option()) // switch 2; jump table: jpt_80055830
            {
                case DEB_MARGTOP: // marg top
                case DEB_MARGBOT: // marg bot
                case DEB_MARGLEFT: // marg left
                case DEB_MARGRIGHT: // marg right
                case DEB_MARGRESET: // marg reset
                    break;
            }
        }

        p32 = &show_debug_menu_flag;
        if (button_pressed & START_BUTTON)
        {
            if (*p32 == 1)
            {
                debmenuReset();
            }
            
            show_debug_menu_flag = 0;
        }
        
        return show_debug_menu_flag;
    }
}
#else
s32 debug_menu_processor(s8 stick_h, s8 stick_v, u16 button_held, u16 button_pressed)
{
    return 0;
}
#endif


s32 get_debug_render_raster(void) {
#if defined(LEFTOVERDEBUG)
    return debug_render_raster;
#else
    return 2;
#endif
}

s32 get_debug_freeze_processing(void) {
#if defined(LEFTOVERDEBUG)
    return debug_freeze_processing;
#else
    return 2;
#endif
}

s32 getDebugMode(void) {
#if defined(LEFTOVERDEBUG)
    return g_DebugMode;
#else
    return 2;
#endif
}

void setDebugMode(void) {
#if defined(LEFTOVERDEBUG)
    g_DebugMode = g_DebugHighlightedOption;
#endif
}

s32 get_memusage_display_flag(void) {
#if defined(LEFTOVERDEBUG)
    return memusage_display_flag;
#else
    return 0;
#endif
}

s32 get_debug_do_draw_bg(void) {
#if defined(LEFTOVERDEBUG)
    return debug_do_draw_bg;
#else
    return 1;
#endif
}

s32 get_debug_do_draw_obj(void) {
#if defined(LEFTOVERDEBUG)
    return debug_do_draw_obj;
#else
    return 1;
#endif
}

s32 get_debug_stanhit_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_stanhit_flag;
#else
    return 0;
#endif
}

s32 get_debug_stanregion_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_stanregion_flag;
#else
    return 0;
#endif
}

s32 get_debug_stan_problems_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_stan_problems_flag;
#else
    return 0;
#endif
}

s32 get_debug_man_pos_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_man_pos_flag;
#else
    return 0;
#endif
}

s32 get_debug_testingmanpos_flag(void) {
#if defined(LEFTOVERDEBUG)
    return g_DebugManPos;
#else
    return 0;
#endif
}

void set_debug_testingmanpos_flag(s32 flag) {
#if defined(LEFTOVERDEBUG)
    g_DebugManPos = flag;
#endif
}

s32 get_debug_joy2skyedit_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_joy2skyedit_flag;
#else
    return 0;
#endif
}

s32 get_debug_joy2hitsedit_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_joy2hitsedit_flag;
#else
    return 0;
#endif
}

s32 get_debug_joy2detailedit_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_joy2detailedit_flag;
#else
    return 0;
#endif
}

s32 get_debug_explosioninfo_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_explosioninfo_flag;
#else
    return 0;
#endif
}

s32 debugIsRoomStateDebugEnabled(void) {
#if defined(LEFTOVERDEBUG)
    return debug_prroomloads_flag;
#else
    return 0;
#endif
}

// Get Current Status of VisCVG (True/False)
s32 get_debug_VisCVG_flag(void) {
    return debug_VisCVG_flag;
}

// Set VisCVG (True/False)
void set_debug_VisCVG_flag(s32 flag) {
    debug_VisCVG_flag = flag;
}


s32 get_debug_007_unlock_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_007_unlock_flag;
#else
    return 0;
#endif
}

s32 get_debug_enable_agent_levels_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_enable_agent_levels_flag;
#else
    return 0;
#endif
}

s32 get_debug_enable_all_levels_flag(void) {
#if defined(LEFTOVERDEBUG)
    return debug_enable_all_levels_flag;
#else
    return 0;
#endif
}





#if !defined(LEFTOVERDEBUG)
s32 get_debug_chrnum_flag(void) {
    return 0;
}
s32 get_debug_gunwatchpos_flag(void) {
    return 0;
}
s32  get_debug_profile_flag(void) {
    return 0;
}
s32 get_debug_taskgrab_val(void) {
    return 0;
}
void func_7F0904C0(void)
{
    // removed
}
void func_7F0904C8(void)
{
    // removed
}
s32 get_debug_fast_bond_flag(void) {
    return debug_fast_bond_flag;
}
void set_debug_fast_bond_flag(s32 flag) {
    debug_fast_bond_flag = flag;
}
s32 get_debug_all_obj_complete_flag(void) {
    return 0;
}
s32 get_debug_portal_flag(void) {
    return 0;
}
void func_7F0904F8(s32 arg0)
{
    // removed
}
#endif


#if defined(LEFTOVERDEBUG)
s32 get_debug_fast_bond_flag(void) {
    return debug_fast_bond_flag;
}
#endif

#if defined(LEFTOVERDEBUG)
void set_debug_fast_bond_flag(s32 flag) {
    debug_fast_bond_flag = flag;
}
#endif

#if defined(LEFTOVERDEBUG)
s32 get_debug_all_obj_complete_flag(void) {
    return debug_all_obj_complete_flag;
}
#endif

#if defined(LEFTOVERDEBUG)
s32 get_debug_portal_flag(void) {
    return debug_portal_flag;
}
#endif

#if defined(LEFTOVERDEBUG)
s32 get_debug_chrnum_flag(void) {
    return debug_chrnum_flag;
}
#endif

#if defined(LEFTOVERDEBUG)
s32 get_debug_gunwatchpos_flag(void) {
    return debug_gunwatchpos_flags;
}
#endif

#if defined(LEFTOVERDEBUG)
s32  get_debug_profile_flag(void) {
    return debug_profile_flag;
}
#endif

#if defined(LEFTOVERDEBUG)
s32 get_debug_taskgrab_val(void) {
    return debug_enable_taskgrab_flag;
}
#endif



