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
{ 0x1AB,                "-ml0 -me0 -mgfx130 -mvtx100 -mt550 -ma170"},
{ 0x1A8,                "-ml0 -me0 -mgfx80  -mvtx100 -mt550 -ma250"},
{ 0x1B7,                "-ml0 -me0 -mgfx130 -mvtx100 -mt440 -ma220"},
{ 0x1B2,                "-ml0 -me0 -mgfx90  -mvtx100 -mt550 -ma230"},
{ 0x1B0,                "-ml0 -me0 -mgfx110 -mvtx100 -mt350 -ma400"},
{   0x0,                "-ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400"},
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
    mempInitDebugNoticeList();
    memaInit();
    bgInitDebugNoticeList();
    viInitDebugNoticeList();
    viInitVideoSettings();
    indycommInit();
    g_DebugAndUpdateStageFlag = rmonGetToken();
    obInitDebugNoticeList();
    rspInitDebugNoticeList();
    dynInitDebugNoticeList();
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

    stanInitDebugNoticeList();
    gameInitDebugNoticeList();

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
    mempResetBank(6);
    init_LnameX();
    lvInitDebugNoticeList();
    bossInitDebugNoticeList();
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

#if defined(LEFTOVERDEBUG)
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

        mempResetBank(4);
        obBlankResourcesLoadedInBank(4);
        if (tokenFind(1, "-ma"))
        {
            g_CurentMaMallocValue = (s32) (strtol(tokenFind(1, "-ma"), NULL, 0) * 1024);
        }

        memaSetBuffer(mempAllocBytesInBank(g_CurentMaMallocValue, 4), g_CurentMaMallocValue);
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

        // The following 4 empty blocks are to make s2/s3 match.

        if(1){} // regalloc
        do{}while(0); // regalloc

        while (osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&localGfxFrameMsg, OS_MESG_NOBLOCK) == 0)
        {
           // empty
        }

        if(1){} // regalloc
        do{}while(0); // regalloc

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

                                    lvlUpdateMpPlayerData();
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
                            memaIterateAndMerge();
#ifdef VERSION_EU
                            eu_sub_7f0c00a4();
#endif
                            toggleFlag ^= 1;

#if defined(VERSION_EU)
                            speedGraphDisplay(1);
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

                case 5:
                    pendingGfx = 4U;
                    break;
            }
        }

        lvlUnloadStageTextData();
        stop_demo_playback();
        mempNullNextEntryInBank(4);
        obBlankResourcesLoadedInBank(4);

        g_StageNum = g_MainStageNum;
        g_MainStageNum = LEVELID_NONE;
    }

    // if(gdl) also works here.
    if (!gdl)
        // removed ... or ido?
    ;

    sub_GAME_7F0D1A7C();
}

#endif
#if !defined(LEFTOVERDEBUG)


GLOBAL_ASM(



.rdata
glabel aLevel__0
.word 0x2d6c6576, 0x656c5f00 /*"-level_"*/
glabel aLevel__1
.word 0x2d6c6576, 0x656c5f00 /*"-level_"*/
glabel aHard
.word 0x2d686172, 0x64000000 /*"-hard"*/
glabel aHard_1
.word 0x2d686172, 0x64000000 /*"-hard"*/
glabel aHard_2
.word 0x2d686172, 0x64000000 /*"-hard"*/
glabel aMa
.word 0x2d6d6100 /*"-ma"*/
glabel aMa_0
.word 0x2d6d6100 /*"-ma"*/
glabel aU64_taskgrab_D_core
.word 0x7536342e, 0x7461736b, 0x67726162, 0x2e25642e, 0x636f7265, 0x00000000 /*"u64.taskgrab.%d.core"*/


.data
glabel taskgrab_ramdump_num
.word 0x1

.text
glabel bossMainloop
/* 006080 70005480 27BDFE20 */  addiu $sp, $sp, -0x1e0
/* 006084 70005484 AFBF003C */  sw    $ra, 0x3c($sp)
/* 006088 70005488 AFBE0038 */  sw    $fp, 0x38($sp)
/* 00608C 7000548C AFB70034 */  sw    $s7, 0x34($sp)
/* 006090 70005490 AFB60030 */  sw    $s6, 0x30($sp)
/* 006094 70005494 AFB5002C */  sw    $s5, 0x2c($sp)
/* 006098 70005498 AFB40028 */  sw    $s4, 0x28($sp)
/* 00609C 7000549C AFB30024 */  sw    $s3, 0x24($sp)
/* 0060A0 700054A0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0060A4 700054A4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0060A8 700054A8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0060AC 700054AC 0FC343DB */  jal   reset_mem_bank_5
/* 0060B0 700054B0 AFA001DC */   sw    $zero, 0x1dc($sp)
/* 0060B4 700054B4 3C058002 */  lui   $a1, %hi(aLevel__0) # $a1, 0x8002
/* 0060B8 700054B8 24A547D4 */  addiu $a1, %lo(aLevel__0) # addiu $a1, $a1, 0x47d4
/* 0060BC 700054BC 0C0026C0 */  jal   tokenFind
/* 0060C0 700054C0 24040001 */   li    $a0, 1
/* 0060C4 700054C4 1040000D */  beqz  $v0, .L700054FC
/* 0060C8 700054C8 24040001 */   li    $a0, 1
/* 0060CC 700054CC 3C058002 */  lui   $a1, %hi(aLevel__1) # $a1, 0x8002
/* 0060D0 700054D0 0C0026C0 */  jal   tokenFind
/* 0060D4 700054D4 24A547DC */   addiu $a1, %lo(aLevel__1) # addiu $a1, $a1, 0x47dc
/* 0060D8 700054D8 904F0000 */  lbu   $t7, ($v0)
/* 0060DC 700054DC 904E0001 */  lbu   $t6, 1($v0)
/* 0060E0 700054E0 3C018002 */  lui   $at, %hi(g_StageNum) # $at, 0x8002
/* 0060E4 700054E4 000FC080 */  sll   $t8, $t7, 2
/* 0060E8 700054E8 030FC021 */  addu  $t8, $t8, $t7
/* 0060EC 700054EC 0018C040 */  sll   $t8, $t8, 1
/* 0060F0 700054F0 01D8C821 */  addu  $t9, $t6, $t8
/* 0060F4 700054F4 2728FDF0 */  addiu $t0, $t9, -0x210
/* 0060F8 700054F8 AC282038 */  sw    $t0, %lo(g_StageNum)($at)
.L700054FC:
/* 0060FC 700054FC 3C098002 */  lui   $t1, %hi(g_StageNum) # $t1, 0x8002
/* 006100 70005500 8D292038 */  lw    $t1, %lo(g_StageNum)($t1)
/* 006104 70005504 2401005A */  li    $at, 90
/* 006108 70005508 1121001D */  beq   $t1, $at, .L70005580
/* 00610C 7000550C 00000000 */   nop   
/* 006110 70005510 0FC0777C */  jal   fileValidateSaves
/* 006114 70005514 00000000 */   nop   
/* 006118 70005518 0FC074F9 */  jal   set_selected_folder_num
/* 00611C 7000551C 00002025 */   move  $a0, $zero
/* 006120 70005520 0FC074FC */  jal   set_selected_difficulty
/* 006124 70005524 00002025 */   move  $a0, $zero
/* 006128 70005528 3C048002 */  lui   $a0, %hi(g_StageNum) # $a0, 0x8002
/* 00612C 7000552C 0FC07510 */  jal   set_solo_and_ptr_briefing
/* 006130 70005530 8C842038 */   lw    $a0, %lo(g_StageNum)($a0)
/* 006134 70005534 3C058002 */  lui   $a1, %hi(aHard) # $a1, 0x8002
/* 006138 70005538 24A547E4 */  addiu $a1, %lo(aHard) # addiu $a1, $a1, 0x47e4
/* 00613C 7000553C 0C0026C0 */  jal   tokenFind
/* 006140 70005540 24040001 */   li    $a0, 1
/* 006144 70005544 1040000E */  beqz  $v0, .L70005580
/* 006148 70005548 24040001 */   li    $a0, 1
/* 00614C 7000554C 3C058002 */  lui   $a1, %hi(aHard_1) # $a1, 0x8002
/* 006150 70005550 0C0026C0 */  jal   tokenFind
/* 006154 70005554 24A547EC */   addiu $a1, %lo(aHard_1) # addiu $a1, $a1, 0x47ec
/* 006158 70005558 90440000 */  lbu   $a0, ($v0)
/* 00615C 7000555C 0FC074FC */  jal   set_selected_difficulty
/* 006160 70005560 2484FFD0 */   addiu $a0, $a0, -0x30
/* 006164 70005564 3C058002 */  lui   $a1, %hi(aHard_2) # $a1, 0x8002
/* 006168 70005568 24A547F4 */  addiu $a1, %lo(aHard_2) # addiu $a1, $a1, 0x47f4
/* 00616C 7000556C 0C0026C0 */  jal   tokenFind
/* 006170 70005570 24040001 */   li    $a0, 1
/* 006174 70005574 90440000 */  lbu   $a0, ($v0)
/* 006178 70005578 0FC2FC24 */  jal   lvlSetSelectedDifficulty
/* 00617C 7000557C 2484FFD0 */   addiu $a0, $a0, -0x30
.L70005580:
/* 006180 70005580 0C003190 */  jal   osGetCount
/* 006184 70005584 00000000 */   nop   
/* 006188 70005588 0C00263E */  jal   randomSetSeed
/* 00618C 7000558C 00402025 */   move  $a0, $v0
/* 006190 70005590 3C168002 */  lui   $s6, %hi(aU64_taskgrab_D_core) # $s6, 0x8002
/* 006194 70005594 3C158007 */  lui   $s5, %hi(g_CurrentPlayer) # $s5, 0x8007
/* 006198 70005598 26B58BC0 */  addiu $s5, %lo(g_CurrentPlayer) # addiu $s5, $s5, -0x7440
/* 00619C 7000559C 26D64804 */  addiu $s6, %lo(aU64_taskgrab_D_core) # addiu $s6, $s6, 0x4804
/* 0061A0 700055A0 27B70058 */  addiu $s7, $sp, 0x58
/* 0061A4 700055A4 27B4005C */  addiu $s4, $sp, 0x5c
/* 0061A8 700055A8 8FB301A8 */  lw    $s3, 0x1a8($sp)
.L700055AC:
/* 0061AC 700055AC 3C0B8002 */  lui   $t3, %hi(g_bossGfxDoneMsg) # $t3, 0x8002
/* 0061B0 700055B0 AFA001D4 */  sw    $zero, 0x1d4($sp)
/* 0061B4 700055B4 256B2194 */  addiu $t3, %lo(g_bossGfxDoneMsg) # addiu $t3, $t3, 0x2194
/* 0061B8 700055B8 8D610000 */  lw    $at, ($t3)
/* 0061BC 700055BC 8D6F0004 */  lw    $t7, 4($t3)
/* 0061C0 700055C0 27AA01B4 */  addiu $t2, $sp, 0x1b4
/* 0061C4 700055C4 AD410000 */  sw    $at, ($t2)
/* 0061C8 700055C8 AD4F0004 */  sw    $t7, 4($t2)
/* 0061CC 700055CC 8D6F000C */  lw    $t7, 0xc($t3)
/* 0061D0 700055D0 8D610008 */  lw    $at, 8($t3)
/* 0061D4 700055D4 0000F025 */  move  $fp, $zero
/* 0061D8 700055D8 AD4F000C */  sw    $t7, 0xc($t2)
/* 0061DC 700055DC AD410008 */  sw    $at, 8($t2)
/* 0061E0 700055E0 8D610010 */  lw    $at, 0x10($t3)
/* 0061E4 700055E4 8D6F0014 */  lw    $t7, 0x14($t3)
/* 0061E8 700055E8 00008825 */  move  $s1, $zero
/* 0061EC 700055EC AD410010 */  sw    $at, 0x10($t2)
/* 0061F0 700055F0 AD4F0014 */  sw    $t7, 0x14($t2)
/* 0061F4 700055F4 8D6F001C */  lw    $t7, 0x1c($t3)
/* 0061F8 700055F8 8D610018 */  lw    $at, 0x18($t3)
/* 0061FC 700055FC AD4F001C */  sw    $t7, 0x1c($t2)
/* 006200 70005600 AD410018 */  sw    $at, 0x18($t2)
/* 006204 70005604 0FC2FC21 */  jal   lvlGetSelectedDifficulty
/* 006208 70005608 AFA001AC */   sw    $zero, 0x1ac($sp)
/* 00620C 7000560C 3C048002 */  lui   $a0, %hi(g_StageNum) # $a0, 0x8002
/* 006210 70005610 8C842038 */  lw    $a0, %lo(g_StageNum)($a0)
/* 006214 70005614 0FC2FEB0 */  jal   test_if_recording_demos_this_stage_load
/* 006218 70005618 00402825 */   move  $a1, $v0
/* 00621C 7000561C 3C0E8002 */  lui   $t6, %hi(g_DebugAndUpdateStageFlag) # $t6, 0x8002
/* 006220 70005620 8DCE2034 */  lw    $t6, %lo(g_DebugAndUpdateStageFlag)($t6)
/* 006224 70005624 3C188002 */  lui   $t8, %hi(g_StageNum) # $t8, 0x8002
/* 006228 70005628 11C00038 */  beqz  $t6, .L7000570C
/* 00622C 7000562C 00000000 */   nop   
/* 006230 70005630 8F182038 */  lw    $t8, %lo(g_StageNum)($t8)
/* 006234 70005634 2401005A */  li    $at, 90
/* 006238 70005638 2410FFFF */  li    $s0, -1
/* 00623C 7000563C 1301001D */  beq   $t8, $at, .L700056B4
/* 006240 70005640 00000000 */   nop   
/* 006244 70005644 0FC04060 */  jal   get_selected_num_players
/* 006248 70005648 00000000 */   nop   
/* 00624C 7000564C 28410002 */  slti  $at, $v0, 2
/* 006250 70005650 14200018 */  bnez  $at, .L700056B4
/* 006254 70005654 3C058002 */   lui   $a1, %hi(memallocstringtable) # $a1, 0x8002
/* 006258 70005658 24A5204C */  addiu $a1, %lo(memallocstringtable) # addiu $a1, $a1, 0x204c
/* 00625C 7000565C 8CB90000 */  lw    $t9, ($a1)
/* 006260 70005660 00008025 */  move  $s0, $zero
/* 006264 70005664 3C048002 */  lui   $a0, %hi(g_StageNum) # $a0, 0x8002
/* 006268 70005668 1320000C */  beqz  $t9, .L7000569C
/* 00626C 7000566C 3C088002 */   lui   $t0, %hi(memallocstringtable) # $t0, 0x8002
/* 006270 70005670 8C842038 */  lw    $a0, %lo(g_StageNum)($a0)
/* 006274 70005674 2502204C */  addiu $v0, $t0, %lo(memallocstringtable) # addiu $v0, $t0, 0x204C
/* 006278 70005678 8C430000 */  lw    $v1, ($v0)
/* 00627C 7000567C 24840190 */  addiu $a0, $a0, 0x190
.L70005680:
/* 006280 70005680 50830007 */  beql  $a0, $v1, .L700056A0
/* 006284 70005684 001048C0 */   sll   $t1, $s0, 3
/* 006288 70005688 8C430008 */  lw    $v1, 8($v0)
/* 00628C 7000568C 26100001 */  addiu $s0, $s0, 1
/* 006290 70005690 24420008 */  addiu $v0, $v0, 8
/* 006294 70005694 1460FFFA */  bnez  $v1, .L70005680
/* 006298 70005698 00000000 */   nop   
.L7000569C:
/* 00629C 7000569C 001048C0 */  sll   $t1, $s0, 3
.L700056A0:
/* 0062A0 700056A0 00A96821 */  addu  $t5, $a1, $t1
/* 0062A4 700056A4 8DAC0000 */  lw    $t4, ($t5)
/* 0062A8 700056A8 15800002 */  bnez  $t4, .L700056B4
/* 0062AC 700056AC 00000000 */   nop   
/* 0062B0 700056B0 2410FFFF */  li    $s0, -1
.L700056B4:
/* 0062B4 700056B4 3C058002 */  lui   $a1, %hi(memallocstringtable) # $a1, 0x8002
/* 0062B8 700056B8 06010010 */  bgez  $s0, .L700056FC
/* 0062BC 700056BC 24A5204C */   addiu $a1, %lo(memallocstringtable) # addiu $a1, $a1, 0x204c
/* 0062C0 700056C0 8CAA0000 */  lw    $t2, ($a1)
/* 0062C4 700056C4 00008025 */  move  $s0, $zero
/* 0062C8 700056C8 3C048002 */  lui   $a0, %hi(g_StageNum) # $a0, 0x8002
/* 0062CC 700056CC 1140000B */  beqz  $t2, .L700056FC
/* 0062D0 700056D0 3C0B8002 */   lui   $t3, 0x8002
/* 0062D4 700056D4 2562204C */  addiu $v0, $t3, 0x204c
/* 0062D8 700056D8 8C430000 */  lw    $v1, ($v0)
/* 0062DC 700056DC 8C842038 */  lw    $a0, %lo(g_StageNum)($a0)
.L700056E0:
/* 0062E0 700056E0 50830007 */  beql  $a0, $v1, .L70005700
/* 0062E4 700056E4 001078C0 */   sll   $t7, $s0, 3
/* 0062E8 700056E8 8C430008 */  lw    $v1, 8($v0)
/* 0062EC 700056EC 26100001 */  addiu $s0, $s0, 1
/* 0062F0 700056F0 24420008 */  addiu $v0, $v0, 8
/* 0062F4 700056F4 1460FFFA */  bnez  $v1, .L700056E0
/* 0062F8 700056F8 00000000 */   nop   
.L700056FC:
/* 0062FC 700056FC 001078C0 */  sll   $t7, $s0, 3
.L70005700:
/* 006300 70005700 00AF7021 */  addu  $t6, $a1, $t7
/* 006304 70005704 0C00267B */  jal   tokenSetString
/* 006308 70005708 8DC40004 */   lw    $a0, 4($t6)
.L7000570C:
/* 00630C 7000570C 0C00237F */  jal   mempResetBank
/* 006310 70005710 24040004 */   li    $a0, 4
/* 006314 70005714 0FC2F15D */  jal   obBlankResourcesLoadedInBank
/* 006318 70005718 24040004 */   li    $a0, 4
/* 00631C 7000571C 3C058002 */  lui   $a1, %hi(aMa) # $a1, 0x8002
/* 006320 70005720 24A547FC */  addiu $a1, %lo(aMa) # addiu $a1, $a1, 0x47fc
/* 006324 70005724 0C0026C0 */  jal   tokenFind
/* 006328 70005728 24040001 */   li    $a0, 1
/* 00632C 7000572C 1040000B */  beqz  $v0, .L7000575C
/* 006330 70005730 24040001 */   li    $a0, 1
/* 006334 70005734 3C058002 */  lui   $a1, %hi(aMa_0) # $a1, 0x8002
/* 006338 70005738 0C0026C0 */  jal   tokenFind
/* 00633C 7000573C 24A54800 */   addiu $a1, %lo(aMa_0) # addiu $a1, $a1, 0x4800
/* 006340 70005740 00402025 */  move  $a0, $v0
/* 006344 70005744 00002825 */  move  $a1, $zero
/* 006348 70005748 0C002790 */  jal   strtol
/* 00634C 7000574C 00003025 */   move  $a2, $zero
/* 006350 70005750 0002C280 */  sll   $t8, $v0, 0xa
/* 006354 70005754 3C018002 */  lui   $at, %hi(g_CurentMaMallocValue) # $at, 0x8002
/* 006358 70005758 AC382040 */  sw    $t8, %lo(g_CurentMaMallocValue)($at)
.L7000575C:
/* 00635C 7000575C 3C048002 */  lui   $a0, %hi(g_CurentMaMallocValue) # $a0, 0x8002
/* 006360 70005760 8C842040 */  lw    $a0, %lo(g_CurentMaMallocValue)($a0)
/* 006364 70005764 0C0022E0 */  jal   mempAllocBytesInBank
/* 006368 70005768 24050004 */   li    $a1, 4
/* 00636C 7000576C 3C058002 */  lui   $a1, %hi(g_CurentMaMallocValue) # $a1, 0x8002
/* 006370 70005770 8CA52040 */  lw    $a1, %lo(g_CurentMaMallocValue)($a1)
/* 006374 70005774 0C00247E */  jal   memaSetBuffer
/* 006378 70005778 00402025 */   move  $a0, $v0
/* 00637C 7000577C 0FC2661B */  jal   reset_play_data_ptrs
/* 006380 70005780 00000000 */   nop   
/* 006384 70005784 3C198002 */  lui   $t9, %hi(g_StageNum) # $t9, 0x8002
/* 006388 70005788 8F392038 */  lw    $t9, %lo(g_StageNum)($t9)
/* 00638C 7000578C 2401005A */  li    $at, 90
/* 006390 70005790 13210009 */  beq   $t9, $at, .L700057B8
/* 006394 70005794 00000000 */   nop   
/* 006398 70005798 0FC04060 */  jal   get_selected_num_players
/* 00639C 7000579C 24110001 */   li    $s1, 1
/* 0063A0 700057A0 28410002 */  slti  $at, $v0, 2
/* 0063A4 700057A4 14200004 */  bnez  $at, .L700057B8
/* 0063A8 700057A8 00000000 */   nop   
/* 0063AC 700057AC 0FC04060 */  jal   get_selected_num_players
/* 0063B0 700057B0 00000000 */   nop   
/* 0063B4 700057B4 00408825 */  move  $s1, $v0
.L700057B8:
/* 0063B8 700057B8 0FC26633 */  jal   init_player_data_ptrs_construct_viewports
/* 0063BC 700057BC 02202025 */   move  $a0, $s1
/* 0063C0 700057C0 0FC2F20F */  jal   dynInitMemory
/* 0063C4 700057C4 00000000 */   nop   
/* 0063C8 700057C8 0C0028F3 */  jal   joyCheckStatusThreadSafe
/* 0063CC 700057CC 00000000 */   nop   
/* 0063D0 700057D0 3C048002 */  lui   $a0, %hi(g_StageNum) # $a0, 0x8002
/* 0063D4 700057D4 0FC2F398 */  jal   lvlStageLoad
/* 0063D8 700057D8 8C842038 */   lw    $a0, %lo(g_StageNum)($a0)
/* 0063DC 700057DC 0C000B26 */  jal   viInitBuffers
/* 0063E0 700057E0 00000000 */   nop   
/* 0063E4 700057E4 0C00287A */  jal   debmenuInit
/* 0063E8 700057E8 00000000 */   nop   
/* 0063EC 700057EC 0FC30001 */  jal   sub_GAME_7F0C0B4C
/* 0063F0 700057F0 00000000 */   nop   
/* 0063F4 700057F4 0C000AEC */  jal   speedGraphVideoRelated_2
/* 0063F8 700057F8 00000000 */   nop   
/* 0063FC 700057FC 3C048005 */  lui   $a0, %hi(gfxFrameMsgQ) # $a0, 0x8005
/* 006400 70005800 24841D60 */  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, 0x1d60
/* 006404 70005804 27A501D4 */  addiu $a1, $sp, 0x1d4
/* 006408 70005808 0C0031F4 */  jal   osRecvMesg
/* 00640C 7000580C 00003025 */   move  $a2, $zero
/* 006410 70005810 14400007 */  bnez  $v0, .L70005830
.L70005814:
/* 006414 70005814 3C048005 */   lui   $a0, %hi(gfxFrameMsgQ) # $a0, 0x8005
/* 006418 70005818 24841D60 */  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, 0x1d60
/* 00641C 7000581C 27A501D4 */  addiu $a1, $sp, 0x1d4
/* 006420 70005820 0C0031F4 */  jal   osRecvMesg
/* 006424 70005824 00003025 */   move  $a2, $zero
/* 006428 70005828 1040FFFA */  beqz  $v0, .L70005814
/* 00642C 7000582C 00000000 */   nop   
.L70005830:
/* 006430 70005830 3C088002 */  lui   $t0, %hi(g_MainStageNum) # $t0, 0x8002
/* 006434 70005834 8D08218C */  lw    $t0, %lo(g_MainStageNum)($t0)
/* 006438 70005838 05010130 */  bgez  $t0, .L70005CFC
.L7000583C:
/* 00643C 7000583C 3C048005 */   lui   $a0, %hi(gfxFrameMsgQ) # $a0, 0x8005
/* 006440 70005840 24841D60 */  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, 0x1d60
/* 006444 70005844 27A501D4 */  addiu $a1, $sp, 0x1d4
/* 006448 70005848 0C0031F4 */  jal   osRecvMesg
/* 00644C 7000584C 24060001 */   li    $a2, 1
/* 006450 70005850 8FA901D4 */  lw    $t1, 0x1d4($sp)
/* 006454 70005854 24010001 */  li    $at, 1
/* 006458 70005858 85230000 */  lh    $v1, ($t1)
/* 00645C 7000585C 10610009 */  beq   $v1, $at, .L70005884
/* 006460 70005860 24010002 */   li    $at, 2
/* 006464 70005864 1061011C */  beq   $v1, $at, .L70005CD8
/* 006468 70005868 3C028002 */   lui   $v0, 0x8002
/* 00646C 7000586C 24010005 */  li    $at, 5
/* 006470 70005870 1061011C */  beq   $v1, $at, .L70005CE4
/* 006474 70005874 3C028002 */   lui   $v0, 0x8002
/* 006478 70005878 3C028002 */  lui   $v0, %hi(g_MainStageNum) # $v0, 0x8002
/* 00647C 7000587C 1000011B */  b     .L70005CEC
/* 006480 70005880 8C42218C */   lw    $v0, %lo(g_MainStageNum)($v0)
.L70005884:
/* 006484 70005884 0C003190 */  jal   osGetCount
/* 006488 70005888 00000000 */   nop   
/* 00648C 7000588C 3C0C8004 */  lui   $t4, %hi(D_800484B4) # $t4, 0x8004
/* 006490 70005890 8D8C113C */  lw    $t4, %lo(D_800484B4)($t4)
/* 006494 70005894 3C01000E */  lui   $at, (0x000E34EA >> 16) # lui $at, 0xe
/* 006498 70005898 342134EA */  ori   $at, (0x000E34EA & 0xFFFF) # ori $at, $at, 0x34ea
/* 00649C 7000589C 01810019 */  multu $t4, $at
/* 0064A0 700058A0 3C0D8004 */  lui   $t5, %hi(copy_of_osgetcount_value_1) # $t5, 0x8004
/* 0064A4 700058A4 8DAD1138 */  lw    $t5, %lo(copy_of_osgetcount_value_1)($t5)
/* 0064A8 700058A8 3C01FFF8 */  lui   $at, (0xFFF8E58B >> 16) # lui $at, 0xfff8
/* 0064AC 700058AC 3421E58B */  ori   $at, (0xFFF8E58B & 0xFFFF) # ori $at, $at, 0xe58b
/* 0064B0 700058B0 004D1823 */  subu  $v1, $v0, $t5
/* 0064B4 700058B4 3C028002 */  lui   $v0, 0x8002
/* 0064B8 700058B8 00005012 */  mflo  $t2
/* 0064BC 700058BC 01415821 */  addu  $t3, $t2, $at
/* 0064C0 700058C0 006B082B */  sltu  $at, $v1, $t3
/* 0064C4 700058C4 10200004 */  beqz  $at, .L700058D8
/* 0064C8 700058C8 00000000 */   nop   
/* 0064CC 700058CC 3C028002 */  lui   $v0, %hi(g_MainStageNum) # $v0, 0x8002
/* 0064D0 700058D0 10000106 */  b     .L70005CEC
/* 0064D4 700058D4 8C42218C */   lw    $v0, %lo(g_MainStageNum)($v0)
.L700058D8:
/* 0064D8 700058D8 8C42218C */  lw    $v0, 0x218c($v0)
/* 0064DC 700058DC 2FC10002 */  sltiu $at, $fp, 2
/* 0064E0 700058E0 04410102 */  bgez  $v0, .L70005CEC
/* 0064E4 700058E4 00000000 */   nop   
/* 0064E8 700058E8 10200100 */  beqz  $at, .L70005CEC
/* 0064EC 700058EC 27AF01B4 */   addiu $t7, $sp, 0x1b4
/* 0064F0 700058F0 0FC2FC43 */  jal   get_is_ramrom_flag
/* 0064F4 700058F4 AFAF0048 */   sw    $t7, 0x48($sp)
/* 0064F8 700058F8 10400005 */  beqz  $v0, .L70005910
/* 0064FC 700058FC 00000000 */   nop   
/* 006500 70005900 0FC2FDBA */  jal   iterate_ramrom_entries_handle_camera_out
/* 006504 70005904 00000000 */   nop   
/* 006508 70005908 10000003 */  b     .L70005918
/* 00650C 7000590C 00000000 */   nop   
.L70005910:
/* 006510 70005910 0FC30001 */  jal   sub_GAME_7F0C0B4C
/* 006514 70005914 00000000 */   nop   
.L70005918:
/* 006518 70005918 0C000AEE */  jal   profileSetMarker
/* 00651C 7000591C 00000000 */   nop   
/* 006520 70005920 0C000AEC */  jal   speedGraphVideoRelated_2
/* 006524 70005924 00000000 */   nop   
/* 006528 70005928 0C000AF0 */  jal   speedGraphDisplay
/* 00652C 7000592C 3C040002 */   lui   $a0, %hi(0x20004) # $a0, 2
/* 006530 70005930 0C002AA0 */  jal   joyConsumeSamplesWrapper
/* 006534 70005934 00000000 */   nop   
/* 006538 70005938 0C000262 */  jal   permit_stderr
/* 00653C 7000593C 00002025 */   move  $a0, $zero
/* 006540 70005940 0FC2F289 */  jal   dynGetMasterDisplayList
/* 006544 70005944 00000000 */   nop   
/* 006548 70005948 3C0E8002 */  lui   $t6, %hi(g_BossIsDebugMenuOpen) # $t6, 0x8002
/* 00654C 7000594C 8DCE2190 */  lw    $t6, %lo(g_BossIsDebugMenuOpen)($t6)
/* 006550 70005950 AFA201A4 */  sw    $v0, 0x1a4($sp)
/* 006554 70005954 00409825 */  move  $s3, $v0
/* 006558 70005958 11C0001D */  beqz  $t6, .L700059D0
/* 00655C 7000595C 00000000 */   nop   
/* 006560 70005960 0C002B98 */  jal   joyGetStickX
/* 006564 70005964 00002025 */   move  $a0, $zero
/* 006568 70005968 00028600 */  sll   $s0, $v0, 0x18
/* 00656C 7000596C 0010C603 */  sra   $t8, $s0, 0x18
/* 006570 70005970 03008025 */  move  $s0, $t8
/* 006574 70005974 0C002BDC */  jal   joyGetStickY
/* 006578 70005978 00002025 */   move  $a0, $zero
/* 00657C 7000597C 00028E00 */  sll   $s1, $v0, 0x18
/* 006580 70005980 0011CE03 */  sra   $t9, $s1, 0x18
/* 006584 70005984 03208825 */  move  $s1, $t9
/* 006588 70005988 00002025 */  move  $a0, $zero
/* 00658C 7000598C 0C002C20 */  jal   joyGetButtons
/* 006590 70005990 3405FFFF */   li    $a1, 65535
/* 006594 70005994 3052FFFF */  andi  $s2, $v0, 0xffff
/* 006598 70005998 00002025 */  move  $a0, $zero
/* 00659C 7000599C 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 0065A0 700059A0 3405FFFF */   li    $a1, 65535
/* 0065A4 700059A4 00102600 */  sll   $a0, $s0, 0x18
/* 0065A8 700059A8 00112E00 */  sll   $a1, $s1, 0x18
/* 0065AC 700059AC 00054E03 */  sra   $t1, $a1, 0x18
/* 0065B0 700059B0 00044603 */  sra   $t0, $a0, 0x18
/* 0065B4 700059B4 01002025 */  move  $a0, $t0
/* 0065B8 700059B8 01202825 */  move  $a1, $t1
/* 0065BC 700059BC 3246FFFF */  andi  $a2, $s2, 0xffff
/* 0065C0 700059C0 0FC240F2 */  jal  debug_menu_processor
/* 0065C4 700059C4 3047FFFF */   andi  $a3, $v0, 0xffff
/* 0065C8 700059C8 3C018002 */  lui   $at, %hi(g_BossIsDebugMenuOpen) # $at, 0x8002
/* 0065CC 700059CC AC222190 */  sw    $v0, %lo(g_BossIsDebugMenuOpen)($at)
.L700059D0:
/* 0065D0 700059D0 0FC2F7EB */  jal   lvlManageMpGame
/* 0065D4 700059D4 00000000 */   nop   
/* 0065D8 700059D8 0FC26A57 */  jal   shuffle_player_ids
/* 0065DC 700059DC 00000000 */   nop   
/* 0065E0 700059E0 3C0D8002 */  lui   $t5, %hi(g_StageNum) # $t5, 0x8002
/* 0065E4 700059E4 8DAD2038 */  lw    $t5, %lo(g_StageNum)($t5)
/* 0065E8 700059E8 2401005A */  li    $at, 90
/* 0065EC 700059EC 11A10018 */  beq   $t5, $at, .L70005A50
/* 0065F0 700059F0 00000000 */   nop   
/* 0065F4 700059F4 0FC26669 */  jal   getPlayerCount
/* 0065F8 700059F8 00008825 */   move  $s1, $zero
/* 0065FC 700059FC 18400014 */  blez  $v0, .L70005A50
/* 006600 70005A00 00000000 */   nop   
.L70005A04:
/* 006604 70005A04 0FC26A9A */  jal   get_nth_player_from_shuffled
/* 006608 70005A08 02202025 */   move  $a0, $s1
/* 00660C 70005A0C 0FC26993 */  jal   set_cur_player
/* 006610 70005A10 00402025 */   move  $a0, $v0
/* 006614 70005A14 8EB00000 */  lw    $s0, ($s5)
/* 006618 70005A18 860407F0 */  lh    $a0, 0x7f0($s0)
/* 00661C 70005A1C 0C000FA3 */  jal   viSetViewSize
/* 006620 70005A20 860507F2 */   lh    $a1, 0x7f2($s0)
/* 006624 70005A24 8EB00000 */  lw    $s0, ($s5)
/* 006628 70005A28 860407F4 */  lh    $a0, 0x7f4($s0)
/* 00662C 70005A2C 0C000FC3 */  jal   viSetViewPosition
/* 006630 70005A30 860507F6 */   lh    $a1, 0x7f6($s0)
/* 006634 70005A34 0FC2FB11 */  jal   lvlUpdateMpPlayerData
/* 006638 70005A38 00000000 */   nop   
/* 00663C 70005A3C 0FC26669 */  jal   getPlayerCount
/* 006640 70005A40 26310001 */   addiu $s1, $s1, 1
/* 006644 70005A44 0222082A */  slt   $at, $s1, $v0
/* 006648 70005A48 1420FFEE */  bnez  $at, .L70005A04
/* 00664C 70005A4C 00000000 */   nop   
.L70005A50:
/* 006650 70005A50 0FC2F5B3 */  jal   lvlRender
/* 006654 70005A54 02602025 */   move  $a0, $s3
/* 006658 70005A58 0FC2411C */  jal   get_debug_VisCVG_flag
/* 00665C 70005A5C 00409825 */   move  $s3, $v0
/* 006660 70005A60 10400037 */  beqz  $v0, .L70005B40 /*NOP this so vis-cvg are always drawn*/
/* 006664 70005A64 2407FFFF */   li    $a3, -1
/* 006668 70005A68 02601025 */  move  $v0, $s3
/* 00666C 70005A6C 26730008 */  addiu $s3, $s3, 8
/* 006670 70005A70 3C0CE700 */  lui   $t4, 0xe700
/* 006674 70005A74 02601825 */  move  $v1, $s3
/* 006678 70005A78 AC4C0000 */  sw    $t4, ($v0)
/* 00667C 70005A7C AC400004 */  sw    $zero, 4($v0)
/* 006680 70005A80 26730008 */  addiu $s3, $s3, 8
/* 006684 70005A84 3C0ABA00 */  lui   $t2, (0xBA001402 >> 16) # lui $t2, 0xba00
/* 006688 70005A88 02602025 */  move  $a0, $s3
/* 00668C 70005A8C 354A1402 */  ori   $t2, (0xBA001402 & 0xFFFF) # ori $t2, $t2, 0x1402
/* 006690 70005A90 26730008 */  addiu $s3, $s3, 8
/* 006694 70005A94 AC6A0000 */  sw    $t2, ($v1)
/* 006698 70005A98 AC600004 */  sw    $zero, 4($v1)
/* 00669C 70005A9C 02602825 */  move  $a1, $s3
/* 0066A0 70005AA0 3C0BF900 */  lui   $t3, 0xf900
/* 0066A4 70005AA4 26730008 */  addiu $s3, $s3, 8
/* 0066A8 70005AA8 AC8B0000 */  sw    $t3, ($a0)
/* 0066AC 70005AAC AC870004 */  sw    $a3, %lo(0x20004)($a0)
/* 0066B0 70005AB0 02603025 */  move  $a2, $s3
/* 0066B4 70005AB4 3C0FEE00 */  lui   $t7, 0xee00
/* 0066B8 70005AB8 26730008 */  addiu $s3, $s3, 8
/* 0066BC 70005ABC ACAF0000 */  sw    $t7, ($a1)
/* 0066C0 70005AC0 ACA70004 */  sw    $a3, 4($a1)
/* 0066C4 70005AC4 3C0EB900 */  lui   $t6, (0xB9000201 >> 16) # lui $t6, 0xb900
/* 0066C8 70005AC8 02601025 */  move  $v0, $s3
/* 0066CC 70005ACC 35CE0201 */  ori   $t6, (0xB9000201 & 0xFFFF) # ori $t6, $t6, 0x201
/* 0066D0 70005AD0 24180004 */  li    $t8, 4
/* 0066D4 70005AD4 26730008 */  addiu $s3, $s3, 8
/* 0066D8 70005AD8 3C19B900 */  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
/* 0066DC 70005ADC 3C080FA5 */  lui   $t0, (0x0FA54040 >> 16) # lui $t0, 0xfa5
/* 0066E0 70005AE0 ACD80004 */  sw    $t8, 4($a2)
/* 0066E4 70005AE4 ACCE0000 */  sw    $t6, ($a2)
/* 0066E8 70005AE8 35084040 */  ori   $t0, (0x0FA54040 & 0xFFFF) # ori $t0, $t0, 0x4040
/* 0066EC 70005AEC 3739031D */  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
/* 0066F0 70005AF0 02608025 */  move  $s0, $s3
/* 0066F4 70005AF4 AC590000 */  sw    $t9, ($v0)
/* 0066F8 70005AF8 AC480004 */  sw    $t0, 4($v0)
/* 0066FC 70005AFC 0C000F9B */  jal   viGetX
/* 006700 70005B00 26730008 */   addiu $s3, $s3, 8
/* 006704 70005B04 00028C00 */  sll   $s1, $v0, 0x10
/* 006708 70005B08 00114C03 */  sra   $t1, $s1, 0x10
/* 00670C 70005B0C 0C000F9F */  jal   viGetY
/* 006710 70005B10 01208825 */   move  $s1, $t1
/* 006714 70005B14 244DFFFF */  addiu $t5, $v0, -1
/* 006718 70005B18 31AC03FF */  andi  $t4, $t5, 0x3ff
/* 00671C 70005B1C 262FFFFF */  addiu $t7, $s1, -1
/* 006720 70005B20 31EE03FF */  andi  $t6, $t7, 0x3ff
/* 006724 70005B24 000C5080 */  sll   $t2, $t4, 2
/* 006728 70005B28 3C01F600 */  lui   $at, 0xf600
/* 00672C 70005B2C 01415825 */  or    $t3, $t2, $at
/* 006730 70005B30 000EC380 */  sll   $t8, $t6, 0xe
/* 006734 70005B34 0178C825 */  or    $t9, $t3, $t8
/* 006738 70005B38 AE190000 */  sw    $t9, ($s0)/*NOP this so vis_cvg are always drawn*/
/* 00673C 70005B3C AE000004 */  sw    $zero, 4($s0)/*NOP this so vis_cvg are always drawn*/
.L70005B40:
/* 006740 70005B40 0C00289B */  jal   debmenuDraw
/* 006744 70005B44 02602025 */   move  $a0, $s3
/* 006748 70005B48 0FC24100 */  jal   get_memusage_display_flag
/* 00674C 70005B4C 00409825 */   move  $s3, $v0
/* 006750 70005B50 10400004 */  beqz  $v0, .L70005B64
/* 006754 70005B54 00000000 */   nop   
/* 006758 70005B58 0C000AF2 */  jal   video_DL_related_4
/* 00675C 70005B5C 02602025 */   move  $a0, $s3
/* 006760 70005B60 00409825 */  move  $s3, $v0
.L70005B64:
/* 006764 70005B64 3C088002 */  lui   $t0, %hi(g_BossIsDebugMenuOpen) # $t0, 0x8002
/* 006768 70005B68 8D082190 */  lw    $t0, %lo(g_BossIsDebugMenuOpen)($t0)
/* 00676C 70005B6C 51000007 */  beql  $t0, $zero, .L70005B8C
/* 006770 70005B70 02601025 */   move  $v0, $s3
/* 006774 70005B74 0FC240F0 */  jal   debugmenuUpdate
/* 006778 70005B78 00000000 */   nop   
/* 00677C 70005B7C 0FC240DE */  jal   debugmenuRender
/* 006780 70005B80 02602025 */   move  $a0, $s3
/* 006784 70005B84 00409825 */  move  $s3, $v0
/* 006788 70005B88 02601025 */  move  $v0, $s3
.L70005B8C:
/* 00678C 70005B8C 26730008 */  addiu $s3, $s3, 8
/* 006790 70005B90 3C09E900 */  lui   $t1, 0xe900
/* 006794 70005B94 AC490000 */  sw    $t1, ($v0)
/* 006798 70005B98 AC400004 */  sw    $zero, 4($v0)
/* 00679C 70005B9C 02601825 */  move  $v1, $s3
/* 0067A0 70005BA0 3C0DB800 */  lui   $t5, 0xb800
/* 0067A4 70005BA4 AC6D0000 */  sw    $t5, ($v1)
/* 0067A8 70005BA8 AC600004 */  sw    $zero, 4($v1)
/* 0067AC 70005BAC 3C0C8002 */  lui   $t4, %hi(g_ShowMemUseFlag) # $t4, 0x8002
/* 0067B0 70005BB0 8D8C2044 */  lw    $t4, %lo(g_ShowMemUseFlag)($t4)
/* 0067B4 70005BB4 26730008 */  addiu $s3, $s3, 8
/* 0067B8 70005BB8 1180000B */  beqz  $t4, .L70005BE8
/* 0067BC 70005BBC 00000000 */   nop   
/* 0067C0 70005BC0 0C002354 */  jal   nulled_mempLoopAllMemBanks
/* 0067C4 70005BC4 00000000 */   nop   
/* 0067C8 70005BC8 0C0025BF */  jal   memaDumpPrePostMerge
/* 0067CC 70005BCC 00000000 */   nop   
/* 0067D0 70005BD0 0FC2F2C9 */  jal   dynRemovedFunc
/* 0067D4 70005BD4 02602025 */   move  $a0, $s3
/* 0067D8 70005BD8 0FC316DC */  jal   nullsub_41
/* 0067DC 70005BDC 00002025 */   move  $a0, $zero
/* 0067E0 70005BE0 3C018002 */  lui   $at, %hi(g_ShowMemUseFlag) # $at, 0x8002
/* 0067E4 70005BE4 AC202044 */  sw    $zero, %lo(g_ShowMemUseFlag)($at)
.L70005BE8:
/* 0067E8 70005BE8 3C0A8002 */  lui   $t2, %hi(g_ShowMemBarsFlag) # $t2, 0x8002
/* 0067EC 70005BEC 8D4A2048 */  lw    $t2, %lo(g_ShowMemBarsFlag)($t2)
/* 0067F0 70005BF0 11400003 */  beqz  $t2, .L70005C00
/* 0067F4 70005BF4 00000000 */   nop   
/* 0067F8 70005BF8 0FC2F2F0 */  jal   dynDrawMembars
/* 0067FC 70005BFC 02602025 */   move  $a0, $s3
.L70005C00:
/* 006800 70005C00 0FC2F293 */  jal   dynGetFreeGfx2
/* 006804 70005C04 02602025 */   move  $a0, $s3
/* 006808 70005C08 0FC2F2BA */  jal   dynSwapBuffers
/* 00680C 70005C0C 00000000 */   nop   
/* 006810 70005C10 0C000B83 */  jal   video_related_8
/* 006814 70005C14 00000000 */   nop   
/* 006818 70005C18 0FC2412E */  jal   get_debug_taskgrab_val
/* 00681C 70005C1C 00000000 */   nop   
/* 006820 70005C20 1040001C */  beqz  $v0, .L70005C94
/* 006824 70005C24 00002025 */   move  $a0, $zero
/* 006828 70005C28 0C002C48 */  jal   joyGetButtonsPressedThisFrame
/* 00682C 70005C2C 3405C000 */   li    $a1, 49152
/* 006830 70005C30 10400018 */  beqz  $v0, .L70005C94
/* 006834 70005C34 00002025 */   move  $a0, $zero
/* 006838 70005C38 0C002C20 */  jal   joyGetButtons
/* 00683C 70005C3C 3405C000 */   li    $a1, 49152
/* 006840 70005C40 3401C000 */  li    $at, 49152
/* 006844 70005C44 14410013 */  bne   $v0, $at, .L70005C94
.L70005C48:
/* 006848 70005C48 3C068002 */   lui   $a2, %hi(taskgrab_ramdump_num) # $a2, 0x8002
/* 00684C 70005C4C 8CC621B4 */  lw    $a2, %lo(taskgrab_ramdump_num)($a2)
/* 006850 70005C50 02802025 */  move  $a0, $s4
/* 006854 70005C54 0C00283D */  jal   sprintf
/* 006858 70005C58 02C02825 */   move  $a1, $s6
/* 00685C 70005C5C 02802025 */  move  $a0, $s4
/* 006860 70005C60 0FC33D6E */  jal   indycommHostCheckFileExists
/* 006864 70005C64 02E02825 */   move  $a1, $s7
/* 006868 70005C68 10400006 */  beqz  $v0, .L70005C84
/* 00686C 70005C6C 3C068002 */   lui   $a2, %hi(taskgrab_ramdump_num) # $a2, 0x8002
/* 006870 70005C70 8CC621B4 */  lw    $a2, %lo(taskgrab_ramdump_num)($a2)
/* 006874 70005C74 3C018002 */  lui   $at, %hi(taskgrab_ramdump_num) # $at, 0x8002
/* 006878 70005C78 24C60001 */  addiu $a2, $a2, 1
/* 00687C 70005C7C 1000FFF2 */  b     .L70005C48
/* 006880 70005C80 AC2621B4 */   sw    $a2, %lo(taskgrab_ramdump_num)($at)
.L70005C84:
/* 006884 70005C84 02802025 */  move  $a0, $s4
/* 006888 70005C88 3C058000 */  lui   $a1, 0x8000
/* 00688C 70005C8C 0FC33D40 */  jal   indycommHostSendDump
/* 006890 70005C90 3C060040 */   lui   $a2, 0x40
.L70005C94:
/* 006894 70005C94 8FA401A4 */  lw    $a0, 0x1a4($sp)
/* 006898 70005C98 02602825 */  move  $a1, $s3
/* 00689C 70005C9C 00003025 */  move  $a2, $zero
/* 0068A0 70005CA0 0FC33CCE */  jal   rspGfxTaskStart
/* 0068A4 70005CA4 8FA70048 */   lw    $a3, 0x48($sp)
/* 0068A8 70005CA8 0C00249C */  jal   memaIterateAndMerge
/* 0068AC 70005CAC 27DE0001 */   addiu $fp, $fp, 1
/* 0068B0 70005CB0 0FC30029 */  jal   eu_sub_7f0c00a4
/* 0068B4 70005CB4 00000000 */   nop   
/* 0068B8 70005CB8 8FAF01AC */  lw    $t7, 0x1ac($sp)
/* 0068BC 70005CBC 3C040001 */  lui   $a0, 1
/* 0068C0 70005CC0 39EE0001 */  xori  $t6, $t7, 1
/* 0068C4 70005CC4 0C000AF0 */  jal   speedGraphDisplay
/* 0068C8 70005CC8 AFAE01AC */   sw    $t6, 0x1ac($sp)
/* 0068CC 70005CCC 3C028002 */  lui   $v0, %hi(g_MainStageNum) # $v0, 0x8002
/* 0068D0 70005CD0 10000006 */  b     .L70005CEC
/* 0068D4 70005CD4 8C42218C */   lw    $v0, %lo(g_MainStageNum)($v0)
.L70005CD8:
/* 0068D8 70005CD8 27DEFFFF */  addiu $fp, $fp, -1
/* 0068DC 70005CDC 10000003 */  b     .L70005CEC
/* 0068E0 70005CE0 8C42218C */   lw    $v0, 0x218c($v0)
.L70005CE4:
/* 0068E4 70005CE4 241E0004 */  li    $fp, 4
/* 0068E8 70005CE8 8C42218C */  lw    $v0, 0x218c($v0)
.L70005CEC:
/* 0068EC 70005CEC 0440FED3 */  bltz  $v0, .L7000583C
/* 0068F0 70005CF0 00000000 */   nop   
/* 0068F4 70005CF4 17C0FED1 */  bnez  $fp, .L7000583C
/* 0068F8 70005CF8 00000000 */   nop   
.L70005CFC:
/* 0068FC 70005CFC 0FC2FBD9 */  jal   lvlUnloadStageTextData
/* 006900 70005D00 00000000 */   nop   
/* 006904 70005D04 0FC2FF5F */  jal   stop_demo_playback
/* 006908 70005D08 00000000 */   nop   
/* 00690C 70005D0C 0C002389 */  jal   mempNullNextEntryInBank
/* 006910 70005D10 24040004 */   li    $a0, 4
/* 006914 70005D14 0FC2F15D */  jal   obBlankResourcesLoadedInBank
/* 006918 70005D18 24040004 */   li    $a0, 4
/* 00691C 70005D1C 3C028002 */  lui   $v0, %hi(g_MainStageNum) # $v0, 0x8002
/* 006920 70005D20 2442218C */  addiu $v0, %lo(g_MainStageNum) # addiu $v0, $v0, 0x218c
/* 006924 70005D24 8C4B0000 */  lw    $t3, ($v0)
/* 006928 70005D28 8FB901DC */  lw    $t9, 0x1dc($sp)
/* 00692C 70005D2C 3C018002 */  lui   $at, %hi(g_StageNum) # $at, 0x8002
/* 006930 70005D30 2418FFFF */  li    $t8, -1
/* 006934 70005D34 AC2B2038 */  sw    $t3, %lo(g_StageNum)($at)
/* 006938 70005D38 1320FE1C */  beqz  $t9, .L700055AC
/* 00693C 70005D3C AC580000 */   sw    $t8, ($v0)
/* 006940 70005D40 0FC343E7 */  jal   sub_GAME_7F0D1A7C
/* 006944 70005D44 AFB301A8 */   sw    $s3, 0x1a8($sp)
/* 006948 70005D48 8FBF003C */  lw    $ra, 0x3c($sp)
/* 00694C 70005D4C 8FB00018 */  lw    $s0, 0x18($sp)
/* 006950 70005D50 8FB1001C */  lw    $s1, 0x1c($sp)
/* 006954 70005D54 8FB20020 */  lw    $s2, 0x20($sp)
/* 006958 70005D58 8FB30024 */  lw    $s3, 0x24($sp)
/* 00695C 70005D5C 8FB40028 */  lw    $s4, 0x28($sp)
/* 006960 70005D60 8FB5002C */  lw    $s5, 0x2c($sp)
/* 006964 70005D64 8FB60030 */  lw    $s6, 0x30($sp)
/* 006968 70005D68 8FB70034 */  lw    $s7, 0x34($sp)
/* 00696C 70005D6C 8FBE0038 */  lw    $fp, 0x38($sp)
/* 006970 70005D70 03E00008 */  jr    $ra
/* 006974 70005D74 27BD01E0 */   addiu $sp, $sp, 0x1e0
)
#endif

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
void bossInitDebugNoticeList(void) {
    debTryAdd(&g_BossDebugNoticeEntry, "boss_c_debug");
}
