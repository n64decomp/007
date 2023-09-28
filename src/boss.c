#include <os_extension.h>
#include <PR/os.h>
#include "bondview.h"
#include <bondconstants.h>
#include <bondgame.h>
#include "boss.h"
#include "deb.h"
#include "debugmenu.h"
#include "game/dyn.h"
#include "game/game_debug.h"
#include "game/file.h"
#include "game/file2.h"
#include "game/indy_comms.h"
#include "init.h"
#include "joy.h"
#include "game/lvl.h"
#include "game/front.h"
#include "mema.h"
#include "memp.h"
#include "music.h"
#include "game/ob.h"
#include "ramrom.h"
#include "random.h"
#include "rmon.h" /*<PR/rmon.h>*/
#include "sched.h"
#include "speed_graph.h"
#include "token.h"
#include "tlb_manage.h"
#include "fr.h"
#include "game/image.h"
#include "vi.h"
#include "game/bg.h"
#include "game/debugmenu_handler.h"
#include "game/lvl.h"
#include "game/ramromreplay.h"
#include "game/room_model_buffer.h"
#include "game/rsp.h"
#include "game/stan.h"
#include "game/textrelated.h"
#include "game/player.h"
#include "game/unk_0C0A70.h"

/**
 * EU .data, offset from start of data_seg : 0x33e0
*/

/**
 * @file boss.c
 * This file contains the main game loop code.
 */
#ifdef REFRESH_PAL
#define MAIN_LOOP_TICK_INTERVAL D_800484B4 * 0xe34ea - 0x71a75U
#else
#define MAIN_LOOP_TICK_INTERVAL 0x5eb61U
#endif

/**
 * Copied from n64devkit\ultra\usr\src\pr\demos_old\simple\gfx.h
 */
typedef union {

    struct {
        short   type;
    } gen;

    struct {
        short   type;
    } done;

    OSScMsg      app;

} GFXMsg;

// forward declarations
void bossMainloop(void);

/* data */
u32 g_BossDebugNoticeEntry = 0;
s32 g_DebugAndUpdateStageFlag = 0;
s32 g_StageNum = LEVELID_TITLE;
u32 g_CurentMMallocValue = 0x234800;
u32 g_CurentMaMallocValue = 0x4B000;
s32 g_ShowMemUseFlag = 0;
s32 g_ShowMemBarsFlag = 0;

struct memallocstring memallocstringtable[] = {
{ LEVELID_DAM,          "-ml0 -me0 -mgfx70  -mvtx50 -mt625 -ma275"},
{ LEVELID_FACILITY,     "-ml0 -me0 -mgfx70  -mvtx50 -mt650 -ma160"},
{ LEVELID_RUNWAY,       "-ml0 -me0 -mgfx100 -mvtx50 -mt610 -ma300"},
{ LEVELID_SURFACE,      "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma300"},
{ LEVELID_BUNKER1,      "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma150"},
{ LEVELID_SILO,         "-ml0 -me0 -mgfx70  -mvtx50 -mt660 -ma150"},
{ LEVELID_FRIGATE,      "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma225"},
{ LEVELID_SURFACE2,     "-ml0 -me0 -mgfx100 -mvtx50 -mt550 -ma350"},
{ LEVELID_BUNKER2,      "-ml0 -me0 -mgfx100 -mvtx50 -mt725 -ma150"},
{ LEVELID_STATUE,       "-ml0 -me0 -mgfx70  -mvtx50 -mt750 -ma220"},
{ LEVELID_ARCHIVES,     "-ml0 -me0 -mgfx70  -mvtx50 -mt600 -ma250"},
{ LEVELID_STREETS,      "-ml0 -me0 -mgfx60  -mvtx40 -mt635 -ma290"},
{ LEVELID_DEPOT,        "-ml0 -me0 -mgfx60  -mvtx50 -mt710 -ma300"},
{ LEVELID_TRAIN,        "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma200"},
{ LEVELID_JUNGLE,       "-ml0 -me0 -mgfx70  -mvtx50 -mt500 -ma200"},
{ LEVELID_CONTROL,      "-ml0 -me0 -mgfx70  -mvtx50 -mt671 -ma200"},
{ LEVELID_CRADLE,       "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma250"},
{ LEVELID_CAVERNS,      "-ml0 -me0 -mgfx100 -mvtx50 -mt530 -ma250"},
{ LEVELID_AZTEC,        "-ml0 -me0 -mgfx60  -mvtx40 -mt855 -ma135"},
{ LEVELID_EGYPT,        "-ml0 -me0 -mgfx100 -mvtx50 -mt600 -ma250"},
{ LEVELID_CITADEL,      "-ml0 -me0 -mgfx100 -mvtx50 -mt650 -ma150"},
{ LEVELID_CUBA,         "-ml0 -me0 -mgfx100 -mvtx50 -mt300 -ma300"},
{ LEVELID_TITLE,        "-ml0 -me0 -mgfx80 -mvtx20 -mt646 -ma001"},
{ 0x5B,                 "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"},
{ 0x63,                 "-ml0 -me0 -mgfx60 -mvtx20 -mt500 -ma001"},
{ LEVELID_TEMPLE,       "-ml0 -me0 -mgfx130 -mvtx100 -mt390 -ma100"},
{ LEVELID_COMPLEX,      "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_LIBRARY,      "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_BASEMENT,     "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_STACK,        "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma100"},
{ LEVELID_CAVES,        "-ml0 -me0 -mgfx130 -mvtx100 -mt400 -ma300"},
{ LEVELID_BUNKER2_MP ,  "-ml0 -me0 -mgfx130 -mvtx100 -mt550 -ma170"},
{ LEVELID_ARCHIVES_MP , "-ml0 -me0 -mgfx80  -mvtx100 -mt550 -ma250"},
{ LEVELID_CAVERNS_MP ,  "-ml0 -me0 -mgfx130 -mvtx100 -mt440 -ma220"},
{ LEVELID_FACILITY_MP , "-ml0 -me0 -mgfx90  -mvtx100 -mt550 -ma230"},
{ LEVELID_EGYPT_MP ,    "-ml0 -me0 -mgfx110 -mvtx100 -mt350 -ma400"},
{ 0x0,                  "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400"},
{ 0x0, },
{ 0x0, },
{ 0x0, }
};

s32 g_MainStageNum = LEVELID_NONE;
s32 g_BossIsDebugMenuOpen = 0;

OSScMsg g_bossGfxDoneMsg = { OS_SC_DONE_MSG };


// extern declarations
extern struct player *g_CurrentPlayer;

/**
 * 6930    70005D30
 *     ??? - uses "-level_", "-m" strings
 */


void bossInitMainthreadData(void)
{
    OSMesg bossmsg;
    OSTimer bosstimer;
    OSMesgQueue bossmq;
    u32 temp_s0;
    u32 unused;
    s32 i;

    debInit();
    romCreateMesgQueue();
    tlbmanageEstablishManagementTable();
    image_entries_load();
    mempInit();
    memaInit();
    bgInit();
    viInit();
    viInitVideoSettings();
    indycommInit();
    g_DebugAndUpdateStageFlag = rmonGetToken();
    obInit();
    rspInit();
    dynInit();
    joyInit();
    osCreateMesgQueue(&bossmq, &bossmsg, 1);

    for (i = 0; i != MAXCONTROLLERS; i++)
    {
        osSetTimer(&bosstimer, OS_USEC_TO_CYCLES(100000), 0, &bossmq, &bossmsg);
        osRecvMesg(&bossmq, &bossmsg, OS_MESG_BLOCK);
        if (i == 1)
        {
            joyCheckStatusThreadSafe();
        }
        else if (i >= 2)
        {
            joyConsumeSamplesWrapper();
        }
    }

    if (tokenFind(1, "-level_") == 0)
    {
        g_DebugAndUpdateStageFlag = 1;
    }

    stanInit();
    gameInit();

    if (g_DebugAndUpdateStageFlag != 0)
    {
        tokenSetString("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
    }

    if (tokenFind(1, "-m") != 0)
    {
        g_CurentMMallocValue = (s32) (strtol(tokenFind(1, "-m"), 0, 0) << 0xa);
    }

    temp_s0 = (osVirtualToPhysical(&room_model_buffer) | 0x80000000);
    mempCheckMemflagTokens(temp_s0, ((u32)tlbmanageGetTlbAllocatedBlock() - (u32)temp_s0));
    mempResetBank(MEMPOOL_PERMANENT);
    langInit();
    lvInit();
    bossInit();
    textrelatedInit_REMOVED();
    debmenu7000ADA8();
    default_player_perspective_and_height();
    store_osgetcount();
    null_init_main_1();
    speedGraphDisplayListRelated();
    set_gu_scale();
    null_init_main_2();
    sub_GAME_7F000980();
    alloc_load_expand_ani_table();
    init_weapon_animation_groups_maybe();
    reset_counter_rand_body_head();
    null_init_main_3();
    init_player_gait_object();
    initGameData();
    fileResetRamRomSave();
    clear_ramrom_block_buffer_heading_ptrs();
}

/**
 * 6BF4    70005FF4
 *     1 ->"show mem use" debug memory display [800241B4]; fry AT,T6
 */
void bossEnableShowMemUseFlag(void) {
    g_ShowMemUseFlag=TRUE;
}

/**
 * 6C04    70006004
 *     toggle "show mem bars" [800241B8]; fries V0,T6,T7
 */
void bossMemBarsFlagToggle(void) {
    g_ShowMemBarsFlag = g_ShowMemBarsFlag ^ 1;
}

/**
 * 6C1C    7000601C
 *     loads primary resources and starts main program loop
 *     this is infinite.  Loops unconditionally: JAL 70006060
 */
void bossEntry(void) {
    bossInitMainthreadData();
    rspAllocateBuffers();
    musicSeqPlayerInit();
    while(1){
       bossMainloop();
    }
}

/**
 * Main program loop.
 *
 * 6C60    70006060
 *
 * Seems to have been based on devkit example at one point,
 * n64devkit\ultra\usr\src\pr\demos_old\simple\simple.c
 *
 * loop:
 *         70006090 tests memstring for "-level_##"
 *         700060DC if not title, tests memstring for "-hard#"
 *         70006160 follows...
 *         700061FC test if debug console unconnected [800241A4]
 *         700062EC follows...
 *         700062FC tests memstring for "-ma"
 *         7000633C allocates "-ma" bytes to mem bank 4
 *         7000635C reset player data pointers
 *         70006364 offsets stage number based on number of players unless main menu
 *         700063A0 parses and sets memory allocation, loads stage, etc.
 *         ...
 *         70006708 displays memory usage when active
 *         70006724 displays in-game debugger when active
 *         7000674C writes a full sync, end display list combo
 *         7000676C display mem use when active    [800241B4]
 *         700067A8 display mem bars when active    [800241B8]
 *         700067C0 follows...
 *         700067D8 tests if "u64.taskgrab.#.core" activated and dumps memory
 *         70006854 follows... (700068BC - stop demos)
 */
void bossMainloop(void)
{
    // declarations

    s32 done;
    const unsigned char *tokenFindLevel;
    GFXMsg *localGfxFrameMsg; // sp 468
    OSScMsg localGfxDoneMsg; // sp 436
    s32 stringIndex;
    s32 toggleFlag; // sp 428
    Gfx *gdl; // sp424
    Gfx *firstGdl;
    u32 nowCount;
    s32 i;
    s32 count;
    s8 joyStickXPos;
    s8 joyStickYPos;
    u16 joyButtons;
    struct player *localPlayer;
    s32 localSelectedNumPlayers;
    u32 pendingGfx = 0;
    s32 freeGfx;
    s32 mainTickElapsed;
    s32 rspReplyMsg;

    u32 unused_stackpadding_[56];

    // end declarations

    done = 0;
    reset_mem_bank_5();

    if (tokenFind(1, "-level_") != NULL)
    {
        tokenFindLevel = (const unsigned char *)tokenFind(1, "-level_");

        // quick hack strltolon, converts the two digit ASCII level to 32bit int
        // eg, "09" = 48*10 + 57 - 528 = 9
        g_StageNum = (((s32)(tokenFindLevel[0] * 10) + (s32)tokenFindLevel[1]) - 0x210);
    }

    if (g_StageNum != LEVELID_TITLE)
    {
        fileValidateSaves();
        set_selected_folder_num(0);
        set_selected_difficulty(DIFFICULTY_AGENT);
        set_solo_and_ptr_briefing(g_StageNum);

        if (tokenFind(1, "-hard"))
        {
            // convert ASCII difficulty value to int in set difficulty calls eg '1' = 49, 49-48 = 1
            set_selected_difficulty(*(const unsigned char*)tokenFind(1, "-hard") - '0');
            lvlSetSelectedDifficulty(*(const unsigned char*)tokenFind(1, "-hard") - '0');
        }
    }

    nowCount = osGetCount();
    randomSetSeed(nowCount);

    // 'done' value never changes, and control never breaks -- infinite loop
    while (!done)
    {
        localGfxFrameMsg = NULL;
        localGfxDoneMsg = g_bossGfxDoneMsg;
        toggleFlag = 0;
        pendingGfx = 0;

        test_if_recording_demos_this_stage_load(g_StageNum, lvlGetSelectedDifficulty());
        if (g_DebugAndUpdateStageFlag)
        {
            stringIndex = -1;

            if (g_StageNum != LEVELID_TITLE && get_selected_num_players() >= 2)
            {
                stringIndex = 0;

                while(memallocstringtable[stringIndex].id)
                {
                    if (memallocstringtable[stringIndex].id == (g_StageNum + 400))
                    {
                        break;
                    }

                    stringIndex++;
                }

                if (memallocstringtable[stringIndex].id == 0)
                {
                    stringIndex = -1;
                }
            }

            if (stringIndex)
            {
                // empty
            }

            if (stringIndex < 0)
            {
                stringIndex = 0;

                while(memallocstringtable[stringIndex].id)
                {
                    if (memallocstringtable[stringIndex].id == g_StageNum)
                    {
                        break;
                    }

                    stringIndex++;
                }
            }

            tokenSetString(memallocstringtable[stringIndex].string);
        }

        mempResetBank(MEMPOOL_STAGE);
        obBlankResourcesLoadedInBank(MEMPOOL_STAGE);
        if (tokenFind(1, "-ma"))
        {
            g_CurentMaMallocValue = (s32) (strtol(tokenFind(1, "-ma"), NULL, 0) * 1024);
        }

        memaReset(mempAllocBytesInBank(g_CurentMaMallocValue, MEMPOOL_STAGE), g_CurentMaMallocValue);
        reset_play_data_ptrs();

        localSelectedNumPlayers = 0;
        if (g_StageNum != LEVELID_TITLE)
        {
            localSelectedNumPlayers = 1;
            if (get_selected_num_players() >= 2)
            {
                localSelectedNumPlayers = get_selected_num_players();
            }
        }

        init_player_data_ptrs_construct_viewports(localSelectedNumPlayers);
        dynInitMemory();
        joyCheckStatusThreadSafe();
        lvlStageLoad(g_StageNum);
        viInitBuffers();
        debmenuInit();
        sub_GAME_7F0C0B4C();
        speedGraphVideoRelated_2();

        if(1); // regalloc
        if(1);

        while (osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&localGfxFrameMsg, OS_MESG_NOBLOCK) == 0)
        {
           // empty
        }

        if(1); // regalloc
        if(1);

        while (g_MainStageNum < 0 || pendingGfx != 0)
        {
            osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&localGfxFrameMsg, OS_MESG_BLOCK);

            switch (localGfxFrameMsg->gen.type)
            {
                case (OS_SC_RETRACE_MSG):
                {
#ifdef DEBUG
    /* debug logging from simple.c, I think this requires #include <ultralog.h>
    * //    if (logging)
    * //        osLogEvent(log, LOG_RETRACE, 1, pendingGfx);
    */
#endif

                    mainTickElapsed = (u32) (osGetCount() - copy_of_osgetcount_value_1);
                    if (mainTickElapsed < MAIN_LOOP_TICK_INTERVAL)
                    {
                        // nothing to do.
                    }
                    else
                    {
                        if (g_MainStageNum < 0 && pendingGfx < 2U)
                        {
                            if (get_is_ramrom_flag())
                            {
                                iterate_ramrom_entries_handle_camera_out();
                            }
                            else
                            {
                                sub_GAME_7F0C0B4C();
                            }

#if defined(VERSION_EU)
                            profileSetMarker();
                            speedGraphVideoRelated_2();
                            speedGraphDisplay(0x20000);
#else
                            video_DL_related_4();
                            speedGraphVideoRelated_2();
                            profileSetMarker(0x20000);
#endif
                            joyConsumeSamplesWrapper();
                            permit_stderr(0);

                            gdl = firstGdl = dynGetMasterDisplayList();

#ifdef DEBUGMENU
                            //ported from pd beta, official way to open debug menu
			                // If menu is open (?) or player has pressed C down + C up
			                if (g_BossIsDebugMenuOpen || joyGetButtons(0, U_CBUTTONS | D_CBUTTONS) == (U_CBUTTONS | D_CBUTTONS)) {
			                	joyStickXPos = joyGetStickX(0);
			                	joyStickYPos = joyGetStickY(0);
			                	joyButtons = joyGetButtons(0, ANY_BUTTON);
			                	g_BossIsDebugMenuOpen = debug_menu_processor(joyStickXPos, joyStickYPos, joyButtons, joyGetButtonsPressedThisFrame(0, ANY_BUTTON));
			                } else if (joyGetButtons(0, START_BUTTON) == 0) {
                                g_DebugMode = g_DebugHighlightedOption;
			                } else 
#endif
#ifndef DEBUGMENU
                            if (g_BossIsDebugMenuOpen)
#endif
                            {
			                	joyStickXPos = joyGetStickX(0);
			                	joyStickYPos = joyGetStickY(0);
			                	joyButtons = joyGetButtons(0, ANY_BUTTON);
			                	g_BossIsDebugMenuOpen = debug_menu_processor(joyStickXPos, joyStickYPos, joyButtons, joyGetButtonsPressedThisFrame(0, ANY_BUTTON));
			                }

                            lvlManageMpGame();
                            shuffle_player_ids();

                            if (g_StageNum != LEVELID_TITLE)
                            {
                                for (i = 0; i < getPlayerCount(); i++)
                                {
                                    set_cur_player(get_nth_player_from_shuffled(i));

                                    localPlayer = g_CurrentPlayer;
                                    viSetViewSize(localPlayer->viewx, localPlayer->viewy);

                                    localPlayer = g_CurrentPlayer;
                                    viSetViewPosition(localPlayer->viewleft, localPlayer->viewtop);

                                    lvlViewMoveTick();
                                }
                            }

                            gdl = lvlRender(gdl);

                            // Lets Visualise the Coverage Value used for Scilohete Anti-Ailising (edges)
                            // (done on the VI), also produces a cool looking linemode - providing AA is working.
                            if (get_debug_VisCVG_flag())
                            {
                                gDPPipeSync(gdl++); // 0xe7000000, 0x00000000
                                gDPSetCycleType(gdl++, G_CYC_1CYCLE); // 0xba001402, 0x00000000
                                gDPSetBlendColor(gdl++, 0xff, 0xff, 0xff, 0xff); // 0xf9000000, 0xffffffff
                                gDPSetPrimDepth(gdl++, 0xffff, 0xffff); // 0xee000000, 0xffffffff
                                gDPSetDepthSource(gdl++, G_ZS_PRIM); // 0xb9000201, 0x00000004
                                gDPSetRenderMode(gdl++, G_RM_VISCVG, G_RM_VISCVG2); // 0xb900031d, 0x0fa54040
                                gDPFillRectangle(gdl++, 0, 0, viGetX() - 1, viGetY() - 1);
                            }

                            gdl = debmenuDraw(gdl);

                            if (get_memusage_display_flag())
                            {
#if defined(VERSION_EU)
                                gdl = video_DL_related_4(gdl);
#else
                                gdl = speedGraphDisplay(gdl);
#endif
                            }

                            if (g_BossIsDebugMenuOpen)
                            {
                                debugmenuUpdate();
                                gdl = debugmenuRender(gdl);
                            }

                            gDPFullSync(gdl++); // 0xe9000000, 0x00000000
                            gSPEndDisplayList(gdl++); // 0xb8000000, 0x00000000

                            if (g_ShowMemUseFlag)
                            {
                                nulled_mempLoopAllMemBanks();
                                memaDumpPrePostMerge();
                                dynRemovedFunc(gdl);
                                nullsub_41(0);
                                g_ShowMemUseFlag = 0;
                            }

                            if (g_ShowMemBarsFlag)
                            {
                                dynDrawMembars(gdl);
                            }

                            freeGfx = dynGetFreeGfx2(gdl);
                            dynSwapBuffers();
                            video_related_8();

                            if ((get_debug_taskgrab_val())
                                && (joyGetButtonsPressedThisFrame(0, (A_BUTTON | B_BUTTON)))
                                && (joyGetButtons(0, (A_BUTTON | B_BUTTON)) == (A_BUTTON | B_BUTTON)))
                            {
                                static s32 taskgrab_ramdump_num = 1;
                                u8 taskGrabBuffer[28];
                                s32 taskGrabFileSize;

                                while (1)
                                {
                                    s32 unusedSprintf = sprintf(taskGrabBuffer, "u64.taskgrab.%d.core", taskgrab_ramdump_num);

                                    if (indycommHostCheckFileExists(taskGrabBuffer, &taskGrabFileSize) != NULL)
                                    {
                                        taskgrab_ramdump_num++;
                                        continue;
                                    }

                                    break;
                                }

                                indycommHostSendDump(taskGrabBuffer, (u8*)0x80000000, 0x400000);
                            }

                            rspReplyMsg = (s32)(&localGfxDoneMsg);
                            rspGfxTaskStart(firstGdl, gdl, 0, (s32*)rspReplyMsg);

                            pendingGfx++;
                            memaSingleDefragPass();
#ifdef VERSION_EU
                            eu_sub_7f0c00a4();
#endif
                            toggleFlag ^= 1;

#if defined(VERSION_EU)
                            speedGraphDisplay(0x10000);
                            if(1);
#else
                            profileSetMarker(0x10000);
#endif
                        }
                    }
                }
                break;

                case (OS_SC_DONE_MSG):
                    pendingGfx--;
                    break;

                case OS_SC_PRE_NMI_MSG:
                    pendingGfx = 4U;
                    break;
            }
        }
        
        lvlUnloadStageTextData();
        stop_demo_playback();
        mempNullNextEntryInBank(MEMPOOL_STAGE);
        obBlankResourcesLoadedInBank(MEMPOOL_STAGE);

#if defined(VERSION_EU)
        if(1);
#endif

        g_StageNum = g_MainStageNum;
        g_MainStageNum = LEVELID_NONE;
    }

    // if(gdl) also works here.
    if (!gdl)
        // removed ... or ido?
    ;

    sub_GAME_7F0D1A7C();
}


/**
 * 7530    70006930
 *     run title [0x5A->loaded stage#]; fry AT
 *     redirect to 70006950: A0=0x5A
 */
void bossRunTitleStage(void) {
    bossSetLoadedStage(LEVELID_TITLE);
}

/**
 * 7550    70006950
 *     A0->loaded stage# [800242FC]; fry AT
 *     0x5A jumps to folder select
 *     0x5B
 *     0x63
 */
void bossSetLoadedStage(LEVELID stage){
    g_MainStageNum = stage;
}

/**
 * 755C    7000695C
 *     V0= stage# [800241A8]
 */
LEVELID bossGetStageNum() {
    return g_StageNum;
}

/**
 * 7568    70006968
 *     return to title screen from stage
 */
void bossReturnTitleStage(void) {
#ifdef BUGFIX_R1
    display_objective_status_text_on_status_change();
    FUN_7f057a40();
#endif
    if ((bossGetStageNum() != LEVELID_CUBA) && (objectiveIsAllComplete() != 0x0)) {
        end_of_mission_briefing();
    }
    bossRunTitleStage();
}

/**
 * 75B4    700069B4
 *     V0=state of debug menu (1:on; 0:off) [80024300]
 */
s32 bossGetDebugParseFlag(void) {
    return g_BossIsDebugMenuOpen;
}


/**
 * 75C0    700069C0
 *     V0= p->debug.notice.list entry for boss_c_debug using data at 800241A0
 */
void bossInit(void) {
    debTryAdd(&g_BossDebugNoticeEntry, "boss_c_debug");
}
