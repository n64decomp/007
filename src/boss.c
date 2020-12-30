#include "ultra64.h"
#include "ramrom.h"
#include "boss.h"
#include "bondgame.h"
#include "game/debugmenu_090490.h"
#include "game/room_model_buffer.h"
#include "deb.h"
#include "game/stan.h"
#include "game/rsp.h"
#include "bondconstants.h"
/**
 * @file boss.c
 * This file contains the main game loop code. 
 */

/* data */
u32 boss_c_ptr_debug_notice_list_entry = 0;
s32 debug_and_update_stage_flag = 0;
LEVELID current_stage_num = LEVELID_TITLE;
u32 current_m_malloc_value = 0x234800;
u32 current_ma_malloc_value = 0x4B000;
s32 show_mem_use_flag = 0;
s32 show_mem_bars_flag = 0;

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

LEVELID loadedstage = LEVELID_NONE;
s32 debug_feature_flag = 0;
s32 D_80024304 = 0x20000;
s32 D_80024308 = 0;
s32 D_8002430C = 0;
s32 D_80024310 = 0;
s32 D_80024314 = 0;
s32 D_80024318 = 0;
s32 D_8002431C = 0;
s32 D_80024320 = 0;
s32 taskgrab_ramdump_num = 1;

/* rodata */

//const char aLevel_[] = "-level_";
//const char aMl0Me0Mgfx100Mvtx50Mt700Ma400_1[] = "          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400";
//const char aM[] = "-m";
//const char aM_1[] = "-m";

//***moved to mainloop
//const char aLevel__0[] = "-level_";
//const char aLevel__1[] = "-level_";
//const char aHard[] = "-hard";
//const char aHard_1[] = "-hard";
//const char aHard_2[] = "-hard";
//const char aMa[] = "-ma";
//const char aMa_0[] = "-ma";
//const char aU64_taskgrab_D_core[] = "u64.taskgrab.%d.core";

/**
 * 6930	70005D30
 *     ??? - uses "-level_", "-m" strings
 */
#define OS_USEC_TO_CYCLES(n)	(((u64)(n)*(osClockRate))/1000000LL)

void init_mainthread_data(void)
{
    OSMesg bossmsg;
    OSTimer bosstimer;
    OSMesgQueue bossmq;
    u32 temp_s0;
    u32 unused;
    s32 i;


    debInitDebugNoticeList();
    romCreateMesgQueue();
    establish_TLB_buffer_management_table();
    image_entries_load();
    mempInitDebugNoticeList();
    memaInitDebugNoticeList();
    bgInitDebugNoticeList();
    viInitDebugNoticeList();
    init_video_settings();
    init_indy_if_not_ready();
    debug_and_update_stage_flag = rmon_debug_is_final_build();
    obInitDebugNoticeList();
    rspInitDebugNoticeList();
    dynInitDebugNoticeList();
    joyInitDebugNoticeList();
    osCreateMesgQueue(&bossmq, &bossmsg, 1);

    for (i = 0; i != 4; i++)
    {
        osSetTimer(&bosstimer, OS_USEC_TO_CYCLES(100000), 0, &bossmq, &bossmsg);
        osRecvMesg(&bossmq, &bossmsg, 1);
        if (i == 1)
        {
            test_controller_presence();
        }
        else if (i >= 2)
        {
            redirect_to_ramrom_replay_and_record_handlers_if_set();
        }
    }

    if (check_token(1, "-level_") == 0)
    {
        debug_and_update_stage_flag = 1;
    }
    stanInitDebugNoticeList();
    gameInitDebugNoticeList();
    if (debug_and_update_stage_flag != 0)
    {
        strtok("          -ml0 -me0 -mgfx100 -mvtx50 -mt700 -ma400");
    }
    if (check_token(1, "-m") != 0)
    {
        current_m_malloc_value = (s32) (strtol(check_token(1, "-m"), 0, 0) << 0xa);
    }
    temp_s0 = (osVirtualToPhysical(&room_model_buffer) | 0x80000000);
    mempCheckMemflagTokens(temp_s0, (return_ptr_TLBallocatedblock() - temp_s0));
    mempResetBank(6);
    init_LnameX();
    lvInitDebugNoticeList();
    bossInitDebugNoticeList();
    textrelatedInit_REMOVED();
    debugmenuInit_REMOVED();
    default_player_perspective_and_height();
    store_osgetcount();
    null_init_main_1();
    displaylist_related();
    set_gu_scale();
    null_init_main_2();
    sub_GAME_7F000980();
    alloc_load_expand_ani_table();
    init_weapon_animation_groups_maybe();
    reset_counter_rand_body_head();
    null_init_main_3();
    sub_GAME_7F000B60();
    initGameData();
    sub_GAME_7F01D6E0();
    clear_ramrom_block_buffer_heading_ptrs();
}

/**
 * 6BF4	70005FF4
 *     1 ->"show mem use" debug memory display [800241B4]; fry AT,T6
 */
void enable_show_mem_use_flag(void) {
    show_mem_use_flag=TRUE;
}

/**
 * 6C04	70006004
 *     toggle "show mem bars" [800241B8]; fries V0,T6,T7
 */
void mem_bars_flag_toggle(void) {
    show_mem_bars_flag = show_mem_bars_flag ^ 1;
}

/**
 * 6C1C	7000601C
 *     loads primary resources and starts main program loop
 *     this is infinite.  Loops unconditionally: JAL 70006060
 */
void bossEntry(void) {
    init_mainthread_data();
    allocate_init_rsp_buffers();
    setupaudio();
    while(1){
       mainloop();
    }    
}



/**
 * 6C60	70006060
 *     main program loop
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
 *         7000676C display mem use when active	[800241B4]
 *         700067A8 display mem bars when active	[800241B8]
 *         700067C0 follows...
 *         700067D8 tests if "u64.taskgrab.#.core" activated and dumps memory
 *         70006854 follows... (700068BC - stop demos)
 */
#ifdef NONMATCHING
void mainloop(void)
{
    s32 sp1DC;
    void *sp1D4;
    ? sp1B4;
    s32 sp1AC;
    s32 sp1A4;
    ? sp5C;
    ? sp58;
    void *sp48;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_ret;
    s32 temp_ret_2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s3_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    void *temp_s3_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_5;
    s32 phi_v1;
    void *phi_v0;
    s32 phi_s0;
    s32 phi_s0_2;
    s32 phi_v1_2;
    void *phi_v0_2;
    s32 phi_s0_3;
    s32 phi_s1;
    u32 phi_fp;
    s32 phi_s1_2;
    s32 phi_s3;
    s32 phi_s3_2;
    void *phi_s3_3;
    s32 phi_v0_3;
    u32 phi_fp_2;
    s32 phi_s0_4;
    s32 phi_s0_5;

    sp1DC = 0;
    reset_mem_bank_5();
    if (check_token(1, "-level_") != 0)
    {
        temp_ret = check_token(1, "-level_");
        current_stage_num = (s32) ((temp_ret->unk1 + (temp_ret->unk0 * 0xa)) + -0x210);
    }
    if (current_stage_num != 0x5a)
    {
        sub_GAME_7F01DF90();
        set_selected_folder_num(0);
        set_selected_difficulty(0);
        set_solo_and_ptr_briefing(current_stage_num);
        if (check_token(1, "-hard") != 0)
        {
            set_selected_difficulty(*check_token(1, "-hard") + -0x30);
            set_difficulty(*check_token(1, "-hard") + -0x30);
        }
    }
    increment_random_num(osGetCount());
loop_6:
    sp1D4 = NULL;
    sp1B4.unk0 = (?32) D_80024304.unk0;
    sp1B4.unk4 = (?32) D_80024304.unk4;
    sp1B4.unkC = (?32) D_80024304.unkC;
    sp1B4.unk8 = (?32) D_80024304.unk8;
    sp1B4.unk10 = (?32) D_80024304.unk10;
    sp1B4.unk14 = (?32) D_80024304.unk14;
    sp1B4.unk1C = (?32) D_80024304.unk1C;
    sp1B4.unk18 = (?32) D_80024304.unk18;
    sp1AC = 0;
    test_if_recording_demos_this_stage_load(current_stage_num, get_current_difficulty());
    if (debug_and_update_stage_flag != 0)
    {
        phi_s0_2 = -1;
        if (current_stage_num != 0x5a)
        {
            phi_s0_2 = -1;
            if (get_selected_num_players() >= 2)
            {
                phi_s0 = 0;
                if (memallocstringtable != 0)
                {
                    temp_v0 = 0x80020000 + 0x41bc;
                    phi_v1 = *temp_v0;
                    phi_v0 = temp_v0;
                    phi_s0_4 = 0;
loop_11:
                    phi_s0 = phi_s0_4;
                    if ((current_stage_num + 0x190) != phi_v1)
                    {
                        temp_v1 = phi_v0->unk8;
                        temp_s0 = phi_s0_4 + 1;
                        phi_v1 = temp_v1;
                        phi_v0 = phi_v0 + 8;
                        phi_s0 = temp_s0;
                        phi_s0_4 = temp_s0;
                        if (temp_v1 != 0)
                        {
                            goto loop_11;
                        }
                    }
                }
                phi_s0_2 = phi_s0;
                if (*(&memallocstringtable + (phi_s0 * 8)) == 0)
                {
                    phi_s0_2 = -1;
                }
            }
        }
        phi_s0_3 = phi_s0_2;
        if (phi_s0_2 < 0)
        {
            phi_s0_3 = 0;
            if (memallocstringtable != 0)
            {
                temp_v0_2 = 0x80020000 + 0x41bc;
                phi_v1_2 = *temp_v0_2;
                phi_v0_2 = temp_v0_2;
                phi_s0_5 = 0;
loop_18:
                phi_s0_3 = phi_s0_5;
                if (current_stage_num != phi_v1_2)
                {
                    temp_v1_2 = phi_v0_2->unk8;
                    temp_s0_2 = phi_s0_5 + 1;
                    phi_v1_2 = temp_v1_2;
                    phi_v0_2 = phi_v0_2 + 8;
                    phi_s0_3 = temp_s0_2;
                    phi_s0_5 = temp_s0_2;
                    if (temp_v1_2 != 0)
                    {
                        goto loop_18;
                    }
                }
            }
        }
        strtok((&memallocstringtable + (phi_s0_3 * 8))->unk4, &memallocstringtable);
    }
    mempResetBank(4);
    obBlankResourcesLoadedInBank(4);
    if (check_token(1, &aMa) != 0)
    {
        current_ma_malloc_value = (s32) (strtol(check_token(1, &aMa_0), 0, 0) << 0xa);
    }
    mempInitMallocTable(mempAllocBytesInBank(current_ma_malloc_value, 4), current_ma_malloc_value);
    reset_play_data_ptrs();
    phi_s1 = 0;
    if (current_stage_num != 0x5a)
    {
        phi_s1 = 1;
        if (get_selected_num_players() >= 2)
        {
            phi_s1 = get_selected_num_players();
        }
    }
    init_player_data_ptrs_construct_viewports(phi_s1);
    set_vtx_gfx_mem_alloc();
    test_controller_presence();
    stage_load(current_stage_num);
    init_both_video_buffers();
    debug_text_related_2();
    sub_GAME_7F0C0B4C();
    video_related_2();
    if (osRecvMesg(&gfxFrameMsgQ, &sp1D4, 0) == 0)
    {
loop_27:
        if (osRecvMesg(&gfxFrameMsgQ, &sp1D4, 0) == 0)
        {
            goto loop_27;
        }
    }
    phi_fp = 0U;
    if (loadedstage < 0)
    {
loop_29:
        osRecvMesg(&gfxFrameMsgQ, &sp1D4, 1);
        if (*sp1D4 != 1)
        {
            if (*sp1D4 != 2)
            {
                if (*sp1D4 != 5)
                {
                    phi_v0_3 = loadedstage;
                    phi_fp_2 = phi_fp;
                }
                else
                {
                    phi_v0_3 = (void *)0x80020000->unk42FC;
                    phi_fp_2 = 4U;
                }
            }
            else
            {
                phi_v0_3 = (void *)0x80020000->unk42FC;
                phi_fp_2 = phi_fp;
            }
        }
        else
        {
            if ((u32) (osGetCount() - copy_of_osgetcount_value_1) < 0x5eb61U)
            {
                phi_v0_3 = loadedstage;
                phi_fp_2 = phi_fp;
            }
            else
            {
                phi_v0_3 = (void *)0x80020000->unk42FC;
                phi_fp_2 = phi_fp;
                if ((void *)0x80020000->unk42FC < 0)
                {
                    phi_v0_3 = (void *)0x80020000->unk42FC;
                    phi_fp_2 = phi_fp;
                    if ((u32) phi_fp < 2U)
                    {
                        sp48 = &sp1B4;
                        if (get_is_ramrom_flag() != 0)
                        {
                            iterate_ramrom_entries_handle_camera_out();
                        }
                        else
                        {
                            sub_GAME_7F0C0B4C();
                        }
                        video_DL_related_4();
                        video_related_2();
                        video_related_3(0x20000);
                        redirect_to_ramrom_replay_and_record_handlers_if_set();
                        permit_stderr(0);
                        temp_ret_2 = get_ptr_displaylist();
                        sp1A4 = temp_ret_2;
                        if (debug_feature_flag != 0)
                        {
                            debug_feature_flag = debug_menu_processor((s32) (((s32) (get_cur_controller_horz_stick_pos(0) << 0x18) >> 0x18) << 0x18) >> 0x18, (s32) (((s32) (get_cur_controller_vert_stick_pos(0) << 0x18) >> 0x18) << 0x18) >> 0x18, (get_controller_buttons_held(0, 0xffff) & 0xffff) & 0xffff, get_controller_buttons_pressed(0, 0xffff) & 0xffff);
                        }
                        manage_mp_game();
                        sub_GAME_7F09B41C();
                        if (current_stage_num != 0x5a)
                        {
                            phi_s1_2 = 0;
                            if (getPlayerCount() > 0)
                            {
loop_44:
                                set_cur_player(sub_GAME_7F09B528(phi_s1_2));
                                set_video2_width_height(pPlayer->unk7F0, pPlayer->unk7F2);
                                set_video2_ulx_uly(pPlayer->viewleft, pPlayer->viewtop);
                                sub_GAME_7F0BF800();
                                temp_s1 = phi_s1_2 + 1;
                                phi_s1_2 = temp_s1;
                                if (temp_s1 < getPlayerCount())
                                {
                                    goto loop_44;
                                }
                            }
                        }
                        temp_s3 = sub_GAME_7F0BE30C(temp_ret_2);
                        phi_s3 = temp_s3;
                        if (get_debug_VisCVG_flag() != 0)
                        { // Lets Visualise the Coverage Value used for Scilohete Anti-Ailising (edges) (done on the VI), also produces a cool looking linemode - providing AA is working.
                            temp_v0_3 = temp_s3;
                            // glistp = glist //make pointer to gfx list
                            temp_s3 = temp_s3 + 8;
                            temp_v1_3 = temp_s3; //increment pointer by SizeOf(gfx) 
                            temp_v0_3->unk0 = 0xe7000000;
                            temp_v0_3->unk4 = 0;
                            //gDPPipesync(glistp++);
                            temp_s3 = temp_s3 + 8;
                            temp_a0 = temp_s3;
                            temp_s3 = temp_s3 + 8;
                            temp_v1_3->unk0 = 0xba001402;
                            temp_v1_3->unk4 = 0;
                            //gDPSetCycleType(glistp++, 2CYCLE);
                            temp_a1 = temp_s3;
                            temp_s3 = temp_s3 + 8;
                            temp_a0->unk0 = 0xf9000000;
                            temp_a0->unk4 = -1;
                            temp_a2 = temp_s3;
                            temp_s3 = temp_s3 + 8;
                            temp_a1->unk0 = 0xee000000;
                            temp_a1->unk4 = -1;
                            temp_v0_4 = temp_s3;
                            temp_s3 = temp_s3 + 8;
                            temp_a2->unk4 = 4;
                            temp_a2->unk0 = 0xb9000201;
                            //gDPSetAlphaCompare(glistp++);
                            temp_s0_3 = temp_s3;
                            temp_v0_4->unk0 = 0xb900031d;
                            temp_v0_4->unk4 = 0xfa54040;
                            //gDPSetRenderMode(glistp++, );

                            //above would most likly look like
                            //glistp = glist; 
                            //gDPPipesync(glistp++);
                            //gDPSetCycleType(glistp++, 2CYCLE);
                            // ...etc

                            temp_s0_3->unk0 = (s32) (((((get_video2_settings_txtClipH() + -1) & 0x3ff) * 4) | 0xf6000000) | (((((s32) (get_video2_settings_txtClipW(temp_a0, temp_a1, temp_a2, -1) << 0x10) >> 0x10) + -1) & 0x3ff) << 0xe));
                            temp_s0_3->unk4 = 0;
                            phi_s3 = temp_s3 + 8;
                        }
                        temp_s3_2 = read_screen_display_block_and_write_chars(phi_s3);
                        phi_s3_2 = temp_s3_2;
                        if (get_memusage_display_flag() != 0)
                        {
                            phi_s3_2 = display_speed_graph(temp_s3_2);
                        }
                        phi_s3_3 = (void *) phi_s3_2;
                        if (debug_feature_flag != 0)
                        {
                            display_debug_menu_text_onscreen();
                            phi_s3_3 = print_debug_mcm_to_stdout(phi_s3_2);
                        }
                        temp_v0_5 = phi_s3_3;
                        temp_s3_3 = phi_s3_3 + 8;
                        temp_v0_5->unk0 = 0xe9000000;
                        temp_v0_5->unk4 = 0;
                        temp_s3_3->unk0 = 0xb8000000;
                        temp_s3_3->unk4 = 0;
                        temp_s3_3 = temp_s3_3 + 8;
                        if (show_mem_use_flag != 0)
                        {
                            nulled_mempLoopAllMemBanks();
                            memaGenerateListsBeforeAfterMerge();
                            removed_debug_routine(temp_s3_3);
                            nullsub_41(0);
                            show_mem_use_flag = 0;
                        }
                        if (show_mem_bars_flag != 0)
                        {
                            draw_membars(temp_s3_3);
                        }
                        allocate_something_in_mgfx(temp_s3_3);
                        allocate_something_in_mvtx();
                        video_related_8();
                        if (get_debug_taskgrab_val() != 0)
                        {
                            if (get_controller_buttons_pressed(0, 0xc000) != 0)
                            {
                                if (get_controller_buttons_held(0, 0xc000) == 0xc000)
                                {
loop_58:
                                    sprintf(&sp5C, &aU64_taskgrab_D_core, taskgrab_ramdump_num);
                                    if (check_file_found_on_indy(&sp5C, &sp58) != 0)
                                    {
                                        taskgrab_ramdump_num = (s32) (taskgrab_ramdump_num + 1);
                                        goto loop_58;
                                    }
                                    indy_send_capture_data(&sp5C, 0x80000000, 0x400000);
                                }
                            }
                        }
                        load_rsp_microcode(sp1A4, temp_s3_3, 0, sp48);
                        mem_related_calls_sort_merge_entries();
                        sp1AC = (s32) (sp1AC ^ 1);
                        video_related_3(0x10000);
                        phi_v0_3 = loadedstage;
                        phi_fp_2 = phi_fp;
                    }
                }
            }
        }
        phi_fp = phi_fp_2;
        if (phi_v0_3 < 0)
        {
            goto loop_29;
        }
        phi_fp = phi_fp_2;
        if (phi_fp_2 != 0)
        {
            goto loop_29;
        }
    }
    unload_stage_text_data();
    stop_demo_playback();
    mempNullNextEntryInBank(4);
    obBlankResourcesLoadedInBank(4);
    current_stage_num = (?32) loadedstage;
    loadedstage = -1;
    if (sp1DC == 0)
    {
        goto loop_6;
    }
    sub_GAME_7F0D1A7C();
}
#else
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

.text
glabel mainloop
/* 006C60 70006060 27BDFE20 */  addiu $sp, $sp, -0x1e0
/* 006C64 70006064 AFBF003C */  sw    $ra, 0x3c($sp)
/* 006C68 70006068 AFBE0038 */  sw    $fp, 0x38($sp)
/* 006C6C 7000606C AFB70034 */  sw    $s7, 0x34($sp)
/* 006C70 70006070 AFB60030 */  sw    $s6, 0x30($sp)
/* 006C74 70006074 AFB5002C */  sw    $s5, 0x2c($sp)
/* 006C78 70006078 AFB40028 */  sw    $s4, 0x28($sp)
/* 006C7C 7000607C AFB30024 */  sw    $s3, 0x24($sp)
/* 006C80 70006080 AFB20020 */  sw    $s2, 0x20($sp)
/* 006C84 70006084 AFB1001C */  sw    $s1, 0x1c($sp)
/* 006C88 70006088 AFB00018 */  sw    $s0, 0x18($sp)
/* 006C8C 7000608C 0FC34693 */  jal   reset_mem_bank_5
/* 006C90 70006090 AFA001DC */   sw    $zero, 0x1dc($sp)
/* 006C94 70006094 3C058003 */  lui   $a1, %hi(aLevel__0)
/* 006C98 70006098 24A59104 */  addiu $a1, %lo(aLevel__0) # addiu $a1, $a1, -0x6efc
/* 006C9C 7000609C 0C0029A8 */  jal   check_token
/* 006CA0 700060A0 24040001 */   li    $a0, 1
/* 006CA4 700060A4 1040000D */  beqz  $v0, .L700060DC
/* 006CA8 700060A8 24040001 */   li    $a0, 1
/* 006CAC 700060AC 3C058003 */  lui   $a1, %hi(aLevel__1)
/* 006CB0 700060B0 0C0029A8 */  jal   check_token
/* 006CB4 700060B4 24A5910C */   addiu $a1, %lo(aLevel__1) # addiu $a1, $a1, -0x6ef4
/* 006CB8 700060B8 904F0000 */  lbu   $t7, ($v0)
/* 006CBC 700060BC 904E0001 */  lbu   $t6, 1($v0)
/* 006CC0 700060C0 3C018002 */  lui   $at, %hi(current_stage_num)
/* 006CC4 700060C4 000FC080 */  sll   $t8, $t7, 2
/* 006CC8 700060C8 030FC021 */  addu  $t8, $t8, $t7
/* 006CCC 700060CC 0018C040 */  sll   $t8, $t8, 1
/* 006CD0 700060D0 01D8C821 */  addu  $t9, $t6, $t8
/* 006CD4 700060D4 2728FDF0 */  addiu $t0, $t9, -0x210
/* 006CD8 700060D8 AC2841A8 */  sw    $t0, %lo(current_stage_num)($at)
.L700060DC:
/* 006CDC 700060DC 3C098002 */  lui   $t1, %hi(current_stage_num) 
/* 006CE0 700060E0 8D2941A8 */  lw    $t1, %lo(current_stage_num)($t1)
/* 006CE4 700060E4 2401005A */  li    $at, 90
/* 006CE8 700060E8 1121001D */  beq   $t1, $at, .L70006160
/* 006CEC 700060EC 00000000 */   nop   
/* 006CF0 700060F0 0FC077E4 */  jal   sub_GAME_7F01DF90
/* 006CF4 700060F4 00000000 */   nop   
/* 006CF8 700060F8 0FC07564 */  jal   set_selected_folder_num
/* 006CFC 700060FC 00002025 */   move  $a0, $zero
/* 006D00 70006100 0FC07567 */  jal   set_selected_difficulty
/* 006D04 70006104 00002025 */   move  $a0, $zero
/* 006D08 70006108 3C048002 */  lui   $a0, %hi(current_stage_num)
/* 006D0C 7000610C 0FC0757B */  jal   set_solo_and_ptr_briefing
/* 006D10 70006110 8C8441A8 */   lw    $a0, %lo(current_stage_num)($a0)
/* 006D14 70006114 3C058003 */  lui   $a1, %hi(aHard)
/* 006D18 70006118 24A59114 */  addiu $a1, %lo(aHard) # addiu $a1, $a1, -0x6eec
/* 006D1C 7000611C 0C0029A8 */  jal   check_token
/* 006D20 70006120 24040001 */   li    $a0, 1
/* 006D24 70006124 1040000E */  beqz  $v0, .L70006160
/* 006D28 70006128 24040001 */   li    $a0, 1
/* 006D2C 7000612C 3C058003 */  lui   $a1, %hi(aHard_1)
/* 006D30 70006130 0C0029A8 */  jal   check_token
/* 006D34 70006134 24A5911C */   addiu $a1, %lo(aHard_1) # addiu $a1, $a1, -0x6ee4
/* 006D38 70006138 90440000 */  lbu   $a0, ($v0)
/* 006D3C 7000613C 0FC07567 */  jal   set_selected_difficulty
/* 006D40 70006140 2484FFD0 */   addiu $a0, $a0, -0x30
/* 006D44 70006144 3C058003 */  lui   $a1, %hi(aHard_2)
/* 006D48 70006148 24A59124 */  addiu $a1, %lo(aHard_2) # addiu $a1, $a1, -0x6edc
/* 006D4C 7000614C 0C0029A8 */  jal   check_token
/* 006D50 70006150 24040001 */   li    $a0, 1
/* 006D54 70006154 90440000 */  lbu   $a0, ($v0)
/* 006D58 70006158 0FC2FF07 */  jal   set_difficulty
/* 006D5C 7000615C 2484FFD0 */   addiu $a0, $a0, -0x30
.L70006160:
/* 006D60 70006160 0C003638 */  jal   osGetCount
/* 006D64 70006164 00000000 */   nop   
/* 006D68 70006168 0C002926 */  jal   increment_random_num
/* 006D6C 7000616C 00402025 */   move  $a0, $v0
/* 006D70 70006170 3C168003 */  lui   $s6, %hi(aU64_taskgrab_D_core)
/* 006D74 70006174 3C158008 */  lui   $s5, %hi(pPlayer)
/* 006D78 70006178 26B5A0B0 */  addiu $s5, %lo(pPlayer) # addiu $s5, $s5, -0x5f50
/* 006D7C 7000617C 26D69134 */  addiu $s6, %lo(aU64_taskgrab_D_core) # addiu $s6, $s6, -0x6ecc
/* 006D80 70006180 27B70058 */  addiu $s7, $sp, 0x58
/* 006D84 70006184 27B4005C */  addiu $s4, $sp, 0x5c
/* 006D88 70006188 8FB301A8 */  lw    $s3, 0x1a8($sp)
.L7000618C:
/* 006D8C 7000618C 3C0B8002 */  lui   $t3, %hi(D_80024304) 
/* 006D90 70006190 AFA001D4 */  sw    $zero, 0x1d4($sp)
/* 006D94 70006194 256B4304 */  addiu $t3, %lo(D_80024304) # addiu $t3, $t3, 0x4304
/* 006D98 70006198 8D610000 */  lw    $at, ($t3)
/* 006D9C 7000619C 8D6F0004 */  lw    $t7, 4($t3)
/* 006DA0 700061A0 27AA01B4 */  addiu $t2, $sp, 0x1b4
/* 006DA4 700061A4 AD410000 */  sw    $at, ($t2)
/* 006DA8 700061A8 AD4F0004 */  sw    $t7, 4($t2)
/* 006DAC 700061AC 8D6F000C */  lw    $t7, 0xc($t3)
/* 006DB0 700061B0 8D610008 */  lw    $at, 8($t3)
/* 006DB4 700061B4 0000F025 */  move  $fp, $zero
/* 006DB8 700061B8 AD4F000C */  sw    $t7, 0xc($t2)
/* 006DBC 700061BC AD410008 */  sw    $at, 8($t2)
/* 006DC0 700061C0 8D610010 */  lw    $at, 0x10($t3)
/* 006DC4 700061C4 8D6F0014 */  lw    $t7, 0x14($t3)
/* 006DC8 700061C8 00008825 */  move  $s1, $zero
/* 006DCC 700061CC AD410010 */  sw    $at, 0x10($t2)
/* 006DD0 700061D0 AD4F0014 */  sw    $t7, 0x14($t2)
/* 006DD4 700061D4 8D6F001C */  lw    $t7, 0x1c($t3)
/* 006DD8 700061D8 8D610018 */  lw    $at, 0x18($t3)
/* 006DDC 700061DC AD4F001C */  sw    $t7, 0x1c($t2)
/* 006DE0 700061E0 AD410018 */  sw    $at, 0x18($t2)
/* 006DE4 700061E4 0FC2FF04 */  jal   get_current_difficulty
/* 006DE8 700061E8 AFA001AC */   sw    $zero, 0x1ac($sp)
/* 006DEC 700061EC 3C048002 */  lui   $a0, %hi(current_stage_num)
/* 006DF0 700061F0 8C8441A8 */  lw    $a0, %lo(current_stage_num)($a0)
/* 006DF4 700061F4 0FC30190 */  jal   test_if_recording_demos_this_stage_load
/* 006DF8 700061F8 00402825 */   move  $a1, $v0
/* 006DFC 700061FC 3C0E8002 */  lui   $t6, %hi(debug_and_update_stage_flag) 
/* 006E00 70006200 8DCE41A4 */  lw    $t6, %lo(debug_and_update_stage_flag)($t6)
/* 006E04 70006204 3C188002 */  lui   $t8, %hi(current_stage_num) 
/* 006E08 70006208 11C00038 */  beqz  $t6, .L700062EC
/* 006E0C 7000620C 00000000 */   nop   
/* 006E10 70006210 8F1841A8 */  lw    $t8, %lo(current_stage_num)($t8)
/* 006E14 70006214 2401005A */  li    $at, 90
/* 006E18 70006218 2410FFFF */  li    $s0, -1
/* 006E1C 7000621C 1301001D */  beq   $t8, $at, .L70006294
/* 006E20 70006220 00000000 */   nop   
/* 006E24 70006224 0FC040A4 */  jal   get_selected_num_players
/* 006E28 70006228 00000000 */   nop   
/* 006E2C 7000622C 28410002 */  slti  $at, $v0, 2
/* 006E30 70006230 14200018 */  bnez  $at, .L70006294
/* 006E34 70006234 3C058002 */   lui   $a1, %hi(memallocstringtable)
/* 006E38 70006238 24A541BC */  addiu $a1, %lo(memallocstringtable) # addiu $a1, $a1, 0x41bc
/* 006E3C 7000623C 8CB90000 */  lw    $t9, ($a1)
/* 006E40 70006240 00008025 */  move  $s0, $zero
/* 006E44 70006244 3C048002 */  lui   $a0, %hi(current_stage_num)
/* 006E48 70006248 1320000C */  beqz  $t9, .L7000627C
/* 006E4C 7000624C 3C088002 */   lui   $t0, %hi(memallocstringtable)
/* 006E50 70006250 8C8441A8 */  lw    $a0, %lo(current_stage_num)($a0)
/* 006E54 70006254 250241BC */  addiu $v0, $t0, %lo(memallocstringtable)
/* 006E58 70006258 8C430000 */  lw    $v1, ($v0)
/* 006E5C 7000625C 24840190 */  addiu $a0, $a0, 0x190
.L70006260:
/* 006E60 70006260 50830007 */  beql  $a0, $v1, .L70006280
/* 006E64 70006264 001048C0 */   sll   $t1, $s0, 3
/* 006E68 70006268 8C430008 */  lw    $v1, 8($v0)
/* 006E6C 7000626C 26100001 */  addiu $s0, $s0, 1
/* 006E70 70006270 24420008 */  addiu $v0, $v0, 8
/* 006E74 70006274 1460FFFA */  bnez  $v1, .L70006260
/* 006E78 70006278 00000000 */   nop   
.L7000627C:
/* 006E7C 7000627C 001048C0 */  sll   $t1, $s0, 3
.L70006280:
/* 006E80 70006280 00A96821 */  addu  $t5, $a1, $t1
/* 006E84 70006284 8DAC0000 */  lw    $t4, ($t5)
/* 006E88 70006288 15800002 */  bnez  $t4, .L70006294
/* 006E8C 7000628C 00000000 */   nop   
/* 006E90 70006290 2410FFFF */  li    $s0, -1
.L70006294:
/* 006E94 70006294 3C058002 */  lui   $a1, %hi(memallocstringtable)
/* 006E98 70006298 06010010 */  bgez  $s0, .L700062DC
/* 006E9C 7000629C 24A541BC */   addiu $a1, %lo(memallocstringtable) # addiu $a1, $a1, 0x41bc
/* 006EA0 700062A0 8CAA0000 */  lw    $t2, ($a1)
/* 006EA4 700062A4 00008025 */  move  $s0, $zero
/* 006EA8 700062A8 3C048002 */  lui   $a0, %hi(current_stage_num)
/* 006EAC 700062AC 1140000B */  beqz  $t2, .L700062DC
/* 006EB0 700062B0 3C0B8002 */   lui   $t3, %hi(memallocstringtable)
/* 006EB4 700062B4 256241BC */  addiu $v0, $t3, %lo(memallocstringtable)
/* 006EB8 700062B8 8C430000 */  lw    $v1, ($v0)
/* 006EBC 700062BC 8C8441A8 */  lw    $a0, %lo(current_stage_num)($a0)
.L700062C0:
/* 006EC0 700062C0 50830007 */  beql  $a0, $v1, .L700062E0
/* 006EC4 700062C4 001078C0 */   sll   $t7, $s0, 3
/* 006EC8 700062C8 8C430008 */  lw    $v1, 8($v0)
/* 006ECC 700062CC 26100001 */  addiu $s0, $s0, 1
/* 006ED0 700062D0 24420008 */  addiu $v0, $v0, 8
/* 006ED4 700062D4 1460FFFA */  bnez  $v1, .L700062C0
/* 006ED8 700062D8 00000000 */   nop   
.L700062DC:
/* 006EDC 700062DC 001078C0 */  sll   $t7, $s0, 3
.L700062E0:
/* 006EE0 700062E0 00AF7021 */  addu  $t6, $a1, $t7
/* 006EE4 700062E4 0C002963 */  jal   strtok
/* 006EE8 700062E8 8DC40004 */   lw    $a0, 4($t6)
.L700062EC:
/* 006EEC 700062EC 0C002667 */  jal   mempResetBank
/* 006EF0 700062F0 24040004 */   li    $a0, 4
/* 006EF4 700062F4 0FC2F46F */  jal   obBlankResourcesLoadedInBank
/* 006EF8 700062F8 24040004 */   li    $a0, 4
/* 006EFC 700062FC 3C058003 */  lui   $a1, %hi(aMa)
/* 006F00 70006300 24A5912C */  addiu $a1, %lo(aMa) # addiu $a1, $a1, -0x6ed4
/* 006F04 70006304 0C0029A8 */  jal   check_token
/* 006F08 70006308 24040001 */   li    $a0, 1
/* 006F0C 7000630C 1040000B */  beqz  $v0, .L7000633C
/* 006F10 70006310 24040001 */   li    $a0, 1
/* 006F14 70006314 3C058003 */  lui   $a1, %hi(aMa_0)
/* 006F18 70006318 0C0029A8 */  jal   check_token
/* 006F1C 7000631C 24A59130 */   addiu $a1, %lo(aMa_0) # addiu $a1, $a1, -0x6ed0
/* 006F20 70006320 00402025 */  move  $a0, $v0
/* 006F24 70006324 00002825 */  move  $a1, $zero
/* 006F28 70006328 0C002A78 */  jal   strtol
/* 006F2C 7000632C 00003025 */   move  $a2, $zero
/* 006F30 70006330 0002C280 */  sll   $t8, $v0, 0xa
/* 006F34 70006334 3C018002 */  lui   $at, %hi(current_ma_malloc_value)
/* 006F38 70006338 AC3841B0 */  sw    $t8, %lo(current_ma_malloc_value)($at)
.L7000633C:
/* 006F3C 7000633C 3C048002 */  lui   $a0, %hi(current_ma_malloc_value)
/* 006F40 70006340 8C8441B0 */  lw    $a0, %lo(current_ma_malloc_value)($a0)
/* 006F44 70006344 0C0025C8 */  jal   mempAllocBytesInBank
/* 006F48 70006348 24050004 */   li    $a1, 4
/* 006F4C 7000634C 3C058002 */  lui   $a1, %hi(current_ma_malloc_value)
/* 006F50 70006350 8CA541B0 */  lw    $a1, %lo(current_ma_malloc_value)($a1)
/* 006F54 70006354 0C002766 */  jal   mempInitMallocTable
/* 006F58 70006358 00402025 */   move  $a0, $v0
/* 006F5C 7000635C 0FC268CB */  jal   reset_play_data_ptrs
/* 006F60 70006360 00000000 */   nop   
/* 006F64 70006364 3C198002 */  lui   $t9, %hi(current_stage_num) 
/* 006F68 70006368 8F3941A8 */  lw    $t9, %lo(current_stage_num)($t9)
/* 006F6C 7000636C 2401005A */  li    $at, 90
/* 006F70 70006370 13210009 */  beq   $t9, $at, .L70006398
/* 006F74 70006374 00000000 */   nop   
/* 006F78 70006378 0FC040A4 */  jal   get_selected_num_players
/* 006F7C 7000637C 24110001 */   li    $s1, 1
/* 006F80 70006380 28410002 */  slti  $at, $v0, 2
/* 006F84 70006384 14200004 */  bnez  $at, .L70006398
/* 006F88 70006388 00000000 */   nop   
/* 006F8C 7000638C 0FC040A4 */  jal   get_selected_num_players
/* 006F90 70006390 00000000 */   nop   
/* 006F94 70006394 00408825 */  move  $s1, $v0
.L70006398:
/* 006F98 70006398 0FC268E3 */  jal   init_player_data_ptrs_construct_viewports
/* 006F9C 7000639C 02202025 */   move  $a0, $s1
/* 006FA0 700063A0 0FC2F523 */  jal   set_vtx_gfx_mem_alloc
/* 006FA4 700063A4 00000000 */   nop   
/* 006FA8 700063A8 0C002DAB */  jal   test_controller_presence
/* 006FAC 700063AC 00000000 */   nop   
/* 006FB0 700063B0 3C048002 */  lui   $a0, %hi(current_stage_num)
/* 006FB4 700063B4 0FC2F6AC */  jal   stage_load
/* 006FB8 700063B8 8C8441A8 */   lw    $a0, %lo(current_stage_num)($a0)
/* 006FBC 700063BC 0C000C49 */  jal   init_both_video_buffers
/* 006FC0 700063C0 00000000 */   nop   
/* 006FC4 700063C4 0C002B6C */  jal   debug_text_related_2
/* 006FC8 700063C8 00000000 */   nop   
/* 006FCC 700063CC 0FC302D3 */  jal   sub_GAME_7F0C0B4C
/* 006FD0 700063D0 00000000 */   nop   
/* 006FD4 700063D4 0C000A04 */  jal   video_related_2
/* 006FD8 700063D8 00000000 */   nop   
/* 006FDC 700063DC 3C048006 */  lui   $a0, %hi(gfxFrameMsgQ)
/* 006FE0 700063E0 2484D9A0 */  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, -0x2660
/* 006FE4 700063E4 27A501D4 */  addiu $a1, $sp, 0x1d4
/* 006FE8 700063E8 0C003774 */  jal   osRecvMesg
/* 006FEC 700063EC 00003025 */   move  $a2, $zero
/* 006FF0 700063F0 14400007 */  bnez  $v0, .L70006410
.L700063F4:
/* 006FF4 700063F4 3C048006 */   lui   $a0, %hi(gfxFrameMsgQ)
/* 006FF8 700063F8 2484D9A0 */  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, -0x2660
/* 006FFC 700063FC 27A501D4 */  addiu $a1, $sp, 0x1d4
/* 007000 70006400 0C003774 */  jal   osRecvMesg
/* 007004 70006404 00003025 */   move  $a2, $zero
/* 007008 70006408 1040FFFA */  beqz  $v0, .L700063F4
/* 00700C 7000640C 00000000 */   nop   
.L70006410:
/* 007010 70006410 3C088002 */  lui   $t0, %hi(loadedstage) 
/* 007014 70006414 8D0842FC */  lw    $t0, %lo(loadedstage)($t0)
/* 007018 70006418 05010126 */  bgez  $t0, .L700068B4
.L7000641C:
/* 00701C 7000641C 3C048006 */   lui   $a0, %hi(gfxFrameMsgQ)
/* 007020 70006420 2484D9A0 */  addiu $a0, %lo(gfxFrameMsgQ) # addiu $a0, $a0, -0x2660
/* 007024 70006424 27A501D4 */  addiu $a1, $sp, 0x1d4
/* 007028 70006428 0C003774 */  jal   osRecvMesg
/* 00702C 7000642C 24060001 */   li    $a2, 1
/* 007030 70006430 8FA901D4 */  lw    $t1, 0x1d4($sp)
/* 007034 70006434 24010001 */  li    $at, 1
/* 007038 70006438 85230000 */  lh    $v1, ($t1)
/* 00703C 7000643C 10610009 */  beq   $v1, $at, .L70006464
/* 007040 70006440 24010002 */   li    $at, 2
/* 007044 70006444 10610112 */  beq   $v1, $at, .L70006890
/* 007048 70006448 3C028002 */   lui   $v0, %hi(loadedstage)
/* 00704C 7000644C 24010005 */  li    $at, 5
/* 007050 70006450 10610112 */  beq   $v1, $at, .L7000689C
/* 007054 70006454 3C028002 */   lui   $v0, %hi(loadedstage)
/* 007058 70006458 3C028002 */  lui   $v0, %hi(loadedstage)
/* 00705C 7000645C 10000111 */  b     .L700068A4
/* 007060 70006460 8C4242FC */   lw    $v0, %lo(loadedstage)($v0)
.L70006464:
/* 007064 70006464 0C003638 */  jal   osGetCount
/* 007068 70006468 00000000 */   nop   
/* 00706C 7000646C 3C0D8005 */  lui   $t5, %hi(copy_of_osgetcount_value_1) 
/* 007070 70006470 8DAD84B0 */  lw    $t5, %lo(copy_of_osgetcount_value_1)($t5)
/* 007074 70006474 3C010005 */  lui   $at, (0x0005EB61 >> 16) # lui $at, 5
/* 007078 70006478 3421EB61 */  ori   $at, (0x0005EB61 & 0xFFFF) # ori $at, $at, 0xeb61
/* 00707C 7000647C 004D1823 */  subu  $v1, $v0, $t5
/* 007080 70006480 0061082B */  sltu  $at, $v1, $at
/* 007084 70006484 10200004 */  beqz  $at, .L70006498
/* 007088 70006488 3C028002 */   lui   $v0, %hi(loadedstage)
/* 00708C 7000648C 3C028002 */  lui   $v0, %hi(loadedstage)
/* 007090 70006490 10000104 */  b     .L700068A4
/* 007094 70006494 8C4242FC */   lw    $v0, %lo(loadedstage)($v0)
.L70006498:
/* 007098 70006498 8C4242FC */  lw    $v0, %lo(loadedstage)($v0)
/* 00709C 7000649C 2FC10002 */  sltiu $at, $fp, 2
/* 0070A0 700064A0 04410100 */  bgez  $v0, .L700068A4
/* 0070A4 700064A4 00000000 */   nop   
/* 0070A8 700064A8 102000FE */  beqz  $at, .L700068A4
/* 0070AC 700064AC 27AC01B4 */   addiu $t4, $sp, 0x1b4
/* 0070B0 700064B0 0FC2FF23 */  jal   get_is_ramrom_flag
/* 0070B4 700064B4 AFAC0048 */   sw    $t4, 0x48($sp)
/* 0070B8 700064B8 10400005 */  beqz  $v0, .L700064D0
/* 0070BC 700064BC 00000000 */   nop   
/* 0070C0 700064C0 0FC3009A */  jal   iterate_ramrom_entries_handle_camera_out
/* 0070C4 700064C4 00000000 */   nop   
/* 0070C8 700064C8 10000003 */  b     .L700064D8
/* 0070CC 700064CC 00000000 */   nop   
.L700064D0:
/* 0070D0 700064D0 0FC302D3 */  jal   sub_GAME_7F0C0B4C
/* 0070D4 700064D4 00000000 */   nop   
.L700064D8:
/* 0070D8 700064D8 0C000B36 */  jal   video_DL_related_4
/* 0070DC 700064DC 00000000 */   nop   
/* 0070E0 700064E0 0C000A04 */  jal   video_related_2
/* 0070E4 700064E4 00000000 */   nop   
/* 0070E8 700064E8 0C000A15 */  jal   video_related_3
/* 0070EC 700064EC 3C040002 */   lui   $a0, 2
/* 0070F0 700064F0 0C002F43 */  jal   redirect_to_ramrom_replay_and_record_handlers_if_set
/* 0070F4 700064F4 00000000 */   nop   
/* 0070F8 700064F8 0C000262 */  jal   permit_stderr
/* 0070FC 700064FC 00002025 */   move  $a0, $zero
/* 007100 70006500 0FC2F59D */  jal   get_ptr_displaylist
/* 007104 70006504 00000000 */   nop   
/* 007108 70006508 3C0A8002 */  lui   $t2, %hi(debug_feature_flag) 
/* 00710C 7000650C 8D4A4300 */  lw    $t2, %lo(debug_feature_flag)($t2)
/* 007110 70006510 AFA201A4 */  sw    $v0, 0x1a4($sp)
/* 007114 70006514 00409825 */  move  $s3, $v0
/* 007118 70006518 1140001D */  beqz  $t2, .L70006590
/* 00711C 7000651C 00000000 */   nop   
/* 007120 70006520 0C00303B */  jal   get_cur_controller_horz_stick_pos
/* 007124 70006524 00002025 */   move  $a0, $zero
/* 007128 70006528 00028600 */  sll   $s0, $v0, 0x18
/* 00712C 7000652C 00105E03 */  sra   $t3, $s0, 0x18
/* 007130 70006530 01608025 */  move  $s0, $t3
/* 007134 70006534 0C00307F */  jal   get_cur_controller_vert_stick_pos
/* 007138 70006538 00002025 */   move  $a0, $zero
/* 00713C 7000653C 00028E00 */  sll   $s1, $v0, 0x18
/* 007140 70006540 00117E03 */  sra   $t7, $s1, 0x18
/* 007144 70006544 01E08825 */  move  $s1, $t7
/* 007148 70006548 00002025 */  move  $a0, $zero
/* 00714C 7000654C 0C0030C3 */  jal   get_controller_buttons_held
/* 007150 70006550 3405FFFF */   li    $a1, 65535
/* 007154 70006554 3052FFFF */  andi  $s2, $v0, 0xffff
/* 007158 70006558 00002025 */  move  $a0, $zero
/* 00715C 7000655C 0C0030EB */  jal   get_controller_buttons_pressed
/* 007160 70006560 3405FFFF */   li    $a1, 65535
/* 007164 70006564 00102600 */  sll   $a0, $s0, 0x18
/* 007168 70006568 00112E00 */  sll   $a1, $s1, 0x18
/* 00716C 7000656C 0005C603 */  sra   $t8, $a1, 0x18
/* 007170 70006570 00047603 */  sra   $t6, $a0, 0x18
/* 007174 70006574 01C02025 */  move  $a0, $t6
/* 007178 70006578 03002825 */  move  $a1, $t8
/* 00717C 7000657C 3246FFFF */  andi  $a2, $s2, 0xffff
/* 007180 70006580 0FC24168 */  jal   debug_menu_processor
/* 007184 70006584 3047FFFF */   andi  $a3, $v0, 0xffff
/* 007188 70006588 3C018002 */  lui   $at, %hi(debug_feature_flag)
/* 00718C 7000658C AC224300 */  sw    $v0, %lo(debug_feature_flag)($at)
.L70006590:
/* 007190 70006590 0FC2FAE2 */  jal   manage_mp_game
/* 007194 70006594 00000000 */   nop   
/* 007198 70006598 0FC26D07 */  jal   sub_GAME_7F09B41C
/* 00719C 7000659C 00000000 */   nop   
/* 0071A0 700065A0 3C198002 */  lui   $t9, %hi(current_stage_num) 
/* 0071A4 700065A4 8F3941A8 */  lw    $t9, %lo(current_stage_num)($t9)
/* 0071A8 700065A8 2401005A */  li    $at, 90
/* 0071AC 700065AC 13210018 */  beq   $t9, $at, .L70006610
/* 0071B0 700065B0 00000000 */   nop   
/* 0071B4 700065B4 0FC26919 */  jal   getPlayerCount
/* 0071B8 700065B8 00008825 */   move  $s1, $zero
/* 0071BC 700065BC 18400014 */  blez  $v0, .L70006610
/* 0071C0 700065C0 00000000 */   nop   
.L700065C4:
/* 0071C4 700065C4 0FC26D4A */  jal   sub_GAME_7F09B528
/* 0071C8 700065C8 02202025 */   move  $a0, $s1
/* 0071CC 700065CC 0FC26C43 */  jal   set_cur_player
/* 0071D0 700065D0 00402025 */   move  $a0, $v0
/* 0071D4 700065D4 8EB00000 */  lw    $s0, ($s5)
/* 0071D8 700065D8 860407F0 */  lh    $a0, 0x7f0($s0)
/* 0071DC 700065DC 0C00110F */  jal   set_video2_width_height
/* 0071E0 700065E0 860507F2 */   lh    $a1, 0x7f2($s0)
/* 0071E4 700065E4 8EB00000 */  lw    $s0, ($s5)
/* 0071E8 700065E8 860407F4 */  lh    $a0, 0x7f4($s0)
/* 0071EC 700065EC 0C00112F */  jal   set_video2_ulx_uly
/* 0071F0 700065F0 860507F6 */   lh    $a1, 0x7f6($s0)
/* 0071F4 700065F4 0FC2FE00 */  jal   sub_GAME_7F0BF800
/* 0071F8 700065F8 00000000 */   nop   
/* 0071FC 700065FC 0FC26919 */  jal   getPlayerCount
/* 007200 70006600 26310001 */   addiu $s1, $s1, 1
/* 007204 70006604 0222082A */  slt   $at, $s1, $v0
/* 007208 70006608 1420FFEE */  bnez  $at, .L700065C4
/* 00720C 7000660C 00000000 */   nop   
.L70006610:
/* 007210 70006610 0FC2F8C3 */  jal   sub_GAME_7F0BE30C
/* 007214 70006614 02602025 */   move  $a0, $s3
/* 007218 70006618 0FC243F7 */  jal   get_debug_VisCVG_flag
/* 00721C 7000661C 00409825 */   move  $s3, $v0
/* 007220 70006620 10400037 */  beqz  $v0, .L70006700
/* 007224 70006624 2407FFFF */   li    $a3, -1
/* 007228 70006628 02601025 */  move  $v0, $s3
/* 00722C 7000662C 26730008 */  addiu $s3, $s3, 8
/* 007230 70006630 3C08E700 */  lui   $t0, 0xe700
/* 007234 70006634 02601825 */  move  $v1, $s3
/* 007238 70006638 AC480000 */  sw    $t0, ($v0)
/* 00723C 7000663C AC400004 */  sw    $zero, 4($v0)
/* 007240 70006640 26730008 */  addiu $s3, $s3, 8
/* 007244 70006644 3C09BA00 */  lui   $t1, (0xBA001402 >> 16) # lui $t1, 0xba00
/* 007248 70006648 02602025 */  move  $a0, $s3
/* 00724C 7000664C 35291402 */  ori   $t1, (0xBA001402 & 0xFFFF) # ori $t1, $t1, 0x1402
/* 007250 70006650 26730008 */  addiu $s3, $s3, 8
/* 007254 70006654 AC690000 */  sw    $t1, ($v1)
/* 007258 70006658 AC600004 */  sw    $zero, 4($v1)
/* 00725C 7000665C 02602825 */  move  $a1, $s3
/* 007260 70006660 3C0DF900 */  lui   $t5, 0xf900
/* 007264 70006664 26730008 */  addiu $s3, $s3, 8
/* 007268 70006668 AC8D0000 */  sw    $t5, 0($a0)
/* 00726C 7000666C AC870004 */  sw    $a3, 4($a0)
/* 007270 70006670 02603025 */  move  $a2, $s3
/* 007274 70006674 3C0CEE00 */  lui   $t4, 0xee00
/* 007278 70006678 26730008 */  addiu $s3, $s3, 8
/* 00727C 7000667C ACAC0000 */  sw    $t4, ($a1)
/* 007280 70006680 ACA70004 */  sw    $a3, 4($a1)
/* 007284 70006684 3C0AB900 */  lui   $t2, (0xB9000201 >> 16) # lui $t2, 0xb900
/* 007288 70006688 02601025 */  move  $v0, $s3
/* 00728C 7000668C 354A0201 */  ori   $t2, (0xB9000201 & 0xFFFF) # ori $t2, $t2, 0x201
/* 007290 70006690 240B0004 */  li    $t3, 4
/* 007294 70006694 26730008 */  addiu $s3, $s3, 8
/* 007298 70006698 3C0FB900 */  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
/* 00729C 7000669C 3C0E0FA5 */  lui   $t6, (0x0FA54040 >> 16) # lui $t6, 0xfa5
/* 0072A0 700066A0 ACCB0004 */  sw    $t3, 4($a2)
/* 0072A4 700066A4 ACCA0000 */  sw    $t2, ($a2)
/* 0072A8 700066A8 35CE4040 */  ori   $t6, (0x0FA54040 & 0xFFFF) # ori $t6, $t6, 0x4040
/* 0072AC 700066AC 35EF031D */  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
/* 0072B0 700066B0 02608025 */  move  $s0, $s3
/* 0072B4 700066B4 AC4F0000 */  sw    $t7, ($v0)
/* 0072B8 700066B8 AC4E0004 */  sw    $t6, 4($v0)
/* 0072BC 700066BC 0C001107 */  jal   get_video2_settings_txtClipW
/* 0072C0 700066C0 26730008 */   addiu $s3, $s3, 8
/* 0072C4 700066C4 00028C00 */  sll   $s1, $v0, 0x10
/* 0072C8 700066C8 0011C403 */  sra   $t8, $s1, 0x10
/* 0072CC 700066CC 0C00110B */  jal   get_video2_settings_txtClipH
/* 0072D0 700066D0 03008825 */   move  $s1, $t8
/* 0072D4 700066D4 2459FFFF */  addiu $t9, $v0, -1
/* 0072D8 700066D8 332803FF */  andi  $t0, $t9, 0x3ff
/* 0072DC 700066DC 262CFFFF */  addiu $t4, $s1, -1
/* 0072E0 700066E0 318A03FF */  andi  $t2, $t4, 0x3ff
/* 0072E4 700066E4 00084880 */  sll   $t1, $t0, 2
/* 0072E8 700066E8 3C01F600 */  lui   $at, 0xf600
/* 0072EC 700066EC 01216825 */  or    $t5, $t1, $at
/* 0072F0 700066F0 000A5B80 */  sll   $t3, $t2, 0xe
/* 0072F4 700066F4 01AB7825 */  or    $t7, $t5, $t3
/* 0072F8 700066F8 AE0F0000 */  sw    $t7, ($s0)
/* 0072FC 700066FC AE000004 */  sw    $zero, 4($s0)
.L70006700:
/* 007300 70006700 0C002C9F */  jal   read_screen_display_block_and_write_chars
/* 007304 70006704 02602025 */   move  $a0, $s3
/* 007308 70006708 0FC243CD */  jal   get_memusage_display_flag
/* 00730C 7000670C 00409825 */   move  $s3, $v0
/* 007310 70006710 10400004 */  beqz  $v0, .L70006724
/* 007314 70006714 00000000 */   nop   
/* 007318 70006718 0C000A56 */  jal   display_speed_graph
/* 00731C 7000671C 02602025 */   move  $a0, $s3
/* 007320 70006720 00409825 */  move  $s3, $v0
.L70006724:
/* 007324 70006724 3C0E8002 */  lui   $t6, %hi(debug_feature_flag) 
/* 007328 70006728 8DCE4300 */  lw    $t6, %lo(debug_feature_flag)($t6)
/* 00732C 7000672C 51C00007 */  beql  $t6, $zero, .L7000674C
/* 007330 70006730 02601025 */   move  $v0, $s3
/* 007334 70006734 0FC24124 */  jal   display_debug_menu_text_onscreen
/* 007338 70006738 00000000 */   nop   
/* 00733C 7000673C 0FC23F9D */  jal   print_debug_mcm_to_stdout
/* 007340 70006740 02602025 */   move  $a0, $s3
/* 007344 70006744 00409825 */  move  $s3, $v0
/* 007348 70006748 02601025 */  move  $v0, $s3
.L7000674C:
/* 00734C 7000674C 26730008 */  addiu $s3, $s3, 8
/* 007350 70006750 3C18E900 */  lui   $t8, 0xe900
/* 007354 70006754 AC580000 */  sw    $t8, ($v0)
/* 007358 70006758 AC400004 */  sw    $zero, 4($v0)
/* 00735C 7000675C 02601825 */  move  $v1, $s3
/* 007360 70006760 3C19B800 */  lui   $t9, 0xb800
/* 007364 70006764 AC790000 */  sw    $t9, ($v1)
/* 007368 70006768 AC600004 */  sw    $zero, 4($v1)
/* 00736C 7000676C 3C088002 */  lui   $t0, %hi(show_mem_use_flag) 
/* 007370 70006770 8D0841B4 */  lw    $t0, %lo(show_mem_use_flag)($t0)
/* 007374 70006774 26730008 */  addiu $s3, $s3, 8
/* 007378 70006778 1100000B */  beqz  $t0, .L700067A8
/* 00737C 7000677C 00000000 */   nop   
/* 007380 70006780 0C00263C */  jal   nulled_mempLoopAllMemBanks
/* 007384 70006784 00000000 */   nop   
/* 007388 70006788 0C0028A7 */  jal   memaGenerateListsBeforeAfterMerge
/* 00738C 7000678C 00000000 */   nop   
/* 007390 70006790 0FC2F5DD */  jal   removed_debug_routine
/* 007394 70006794 02602025 */   move  $a0, $s3
/* 007398 70006798 0FC31994 */  jal   nullsub_41
/* 00739C 7000679C 00002025 */   move  $a0, $zero
/* 0073A0 700067A0 3C018002 */  lui   $at, %hi(show_mem_use_flag)
/* 0073A4 700067A4 AC2041B4 */  sw    $zero, %lo(show_mem_use_flag)($at)
.L700067A8:
/* 0073A8 700067A8 3C098002 */  lui   $t1, %hi(show_mem_bars_flag) 
/* 0073AC 700067AC 8D2941B8 */  lw    $t1, %lo(show_mem_bars_flag)($t1)
/* 0073B0 700067B0 11200003 */  beqz  $t1, .L700067C0
/* 0073B4 700067B4 00000000 */   nop   
/* 0073B8 700067B8 0FC2F604 */  jal   draw_membars
/* 0073BC 700067BC 02602025 */   move  $a0, $s3
.L700067C0:
/* 0073C0 700067C0 0FC2F5A7 */  jal   allocate_something_in_mgfx
/* 0073C4 700067C4 02602025 */   move  $a0, $s3
/* 0073C8 700067C8 0FC2F5CE */  jal   allocate_something_in_mvtx
/* 0073CC 700067CC 00000000 */   nop   
/* 0073D0 700067D0 0C000CA6 */  jal   video_related_8
/* 0073D4 700067D4 00000000 */   nop   
/* 0073D8 700067D8 0FC2441B */  jal   get_debug_taskgrab_val
/* 0073DC 700067DC 00000000 */   nop   
/* 0073E0 700067E0 1040001C */  beqz  $v0, .L70006854
/* 0073E4 700067E4 00002025 */   move  $a0, $zero
/* 0073E8 700067E8 0C0030EB */  jal   get_controller_buttons_pressed
/* 0073EC 700067EC 3405C000 */   li    $a1, 49152
/* 0073F0 700067F0 10400018 */  beqz  $v0, .L70006854
/* 0073F4 700067F4 00002025 */   move  $a0, $zero
/* 0073F8 700067F8 0C0030C3 */  jal   get_controller_buttons_held
/* 0073FC 700067FC 3405C000 */   li    $a1, 49152
/* 007400 70006800 3401C000 */  li    $at, 49152
/* 007404 70006804 14410013 */  bne   $v0, $at, .L70006854
.L70006808:
/* 007408 70006808 3C068002 */   lui   $a2, %hi(taskgrab_ramdump_num)
/* 00740C 7000680C 8CC64324 */  lw    $a2, %lo(taskgrab_ramdump_num)($a2)
/* 007410 70006810 02802025 */  move  $a0, $s4
/* 007414 70006814 0C002B25 */  jal   sprintf
/* 007418 70006818 02C02825 */   move  $a1, $s6
/* 00741C 7000681C 02802025 */  move  $a0, $s4
/* 007420 70006820 0FC34026 */  jal   check_file_found_on_indy
/* 007424 70006824 02E02825 */   move  $a1, $s7
/* 007428 70006828 10400006 */  beqz  $v0, .L70006844
/* 00742C 7000682C 3C068002 */   lui   $a2, %hi(taskgrab_ramdump_num)
/* 007430 70006830 8CC64324 */  lw    $a2, %lo(taskgrab_ramdump_num)($a2)
/* 007434 70006834 3C018002 */  lui   $at, %hi(taskgrab_ramdump_num)
/* 007438 70006838 24C60001 */  addiu $a2, $a2, 1
/* 00743C 7000683C 1000FFF2 */  b     .L70006808
/* 007440 70006840 AC264324 */   sw    $a2, %lo(taskgrab_ramdump_num)($at)
.L70006844:
/* 007444 70006844 02802025 */  move  $a0, $s4
/* 007448 70006848 3C058000 */  lui   $a1, 0x8000
/* 00744C 7000684C 0FC33FF8 */  jal   indy_send_capture_data
/* 007450 70006850 3C060040 */   lui   $a2, 0x40
.L70006854:
/* 007454 70006854 8FA401A4 */  lw    $a0, 0x1a4($sp)
/* 007458 70006858 02602825 */  move  $a1, $s3
/* 00745C 7000685C 00003025 */  move  $a2, $zero
/* 007460 70006860 0FC33F86 */  jal   load_rsp_microcode
/* 007464 70006864 8FA70048 */   lw    $a3, 0x48($sp)
/* 007468 70006868 0C002784 */  jal   mem_related_calls_sort_merge_entries
/* 00746C 7000686C 27DE0001 */   addiu $fp, $fp, 1
/* 007470 70006870 8FAC01AC */  lw    $t4, 0x1ac($sp)
/* 007474 70006874 3C040001 */  lui   $a0, 1
/* 007478 70006878 398A0001 */  xori  $t2, $t4, 1
/* 00747C 7000687C 0C000A15 */  jal   video_related_3
/* 007480 70006880 AFAA01AC */   sw    $t2, 0x1ac($sp)
/* 007484 70006884 3C028002 */  lui   $v0, %hi(loadedstage)
/* 007488 70006888 10000006 */  b     .L700068A4
/* 00748C 7000688C 8C4242FC */   lw    $v0, %lo(loadedstage)($v0)
.L70006890:
/* 007490 70006890 27DEFFFF */  addiu $fp, $fp, -1
/* 007494 70006894 10000003 */  b     .L700068A4
/* 007498 70006898 8C4242FC */   lw    $v0, %lo(loadedstage)($v0)
.L7000689C:
/* 00749C 7000689C 241E0004 */  li    $fp, 4
/* 0074A0 700068A0 8C4242FC */  lw    $v0, %lo(loadedstage)($v0)
.L700068A4:
/* 0074A4 700068A4 0440FEDD */  bltz  $v0, .L7000641C
/* 0074A8 700068A8 00000000 */   nop   
/* 0074AC 700068AC 17C0FEDB */  bnez  $fp, .L7000641C
/* 0074B0 700068B0 00000000 */   nop   
.L700068B4:
/* 0074B4 700068B4 0FC2FEC8 */  jal   unload_stage_text_data
/* 0074B8 700068B8 00000000 */   nop   
/* 0074BC 700068BC 0FC3023F */  jal   stop_demo_playback
/* 0074C0 700068C0 00000000 */   nop   
/* 0074C4 700068C4 0C002671 */  jal   mempNullNextEntryInBank
/* 0074C8 700068C8 24040004 */   li    $a0, 4
/* 0074CC 700068CC 0FC2F46F */  jal   obBlankResourcesLoadedInBank
/* 0074D0 700068D0 24040004 */   li    $a0, 4
/* 0074D4 700068D4 3C028002 */  lui   $v0, %hi(loadedstage)
/* 0074D8 700068D8 244242FC */  addiu $v0, %lo(loadedstage) # addiu $v0, $v0, 0x42fc
/* 0074DC 700068DC 8C4D0000 */  lw    $t5, ($v0)
/* 0074E0 700068E0 8FAF01DC */  lw    $t7, 0x1dc($sp)
/* 0074E4 700068E4 3C018002 */  lui   $at, %hi(current_stage_num)
/* 0074E8 700068E8 240BFFFF */  li    $t3, -1
/* 0074EC 700068EC AC2D41A8 */  sw    $t5, %lo(current_stage_num)($at)
/* 0074F0 700068F0 11E0FE26 */  beqz  $t7, .L7000618C
/* 0074F4 700068F4 AC4B0000 */   sw    $t3, ($v0)
/* 0074F8 700068F8 0FC3469F */  jal   sub_GAME_7F0D1A7C
/* 0074FC 700068FC AFB301A8 */   sw    $s3, 0x1a8($sp)
/* 007500 70006900 8FBF003C */  lw    $ra, 0x3c($sp)
/* 007504 70006904 8FB00018 */  lw    $s0, 0x18($sp)
/* 007508 70006908 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00750C 7000690C 8FB20020 */  lw    $s2, 0x20($sp)
/* 007510 70006910 8FB30024 */  lw    $s3, 0x24($sp)
/* 007514 70006914 8FB40028 */  lw    $s4, 0x28($sp)
/* 007518 70006918 8FB5002C */  lw    $s5, 0x2c($sp)
/* 00751C 7000691C 8FB60030 */  lw    $s6, 0x30($sp)
/* 007520 70006920 8FB70034 */  lw    $s7, 0x34($sp)
/* 007524 70006924 8FBE0038 */  lw    $fp, 0x38($sp)
/* 007528 70006928 03E00008 */  jr    $ra
/* 00752C 7000692C 27BD01E0 */   addiu $sp, $sp, 0x1e0
)
#endif

/**
 * 7530	70006930
 *     run title [0x5A->loaded stage#]; fry AT
 *     redirect to 70006950: A0=0x5A
 */
void run_title_stage(void) {
    set_loaded_stage(LEVELID_TITLE);
}

/**
 * 7550	70006950
 *     A0->loaded stage# [800242FC]; fry AT
 *     0x5A jumps to folder select
 *     0x5B 
 *     0x63 
 */
void set_loaded_stage(LEVELID stage){
    loadedstage = stage;
}

/**
 * 755C	7000695C
 *     V0= stage# [800241A8]
 */
LEVELID get_stage_num(){
    return current_stage_num;
}

/**
 * 7568	70006968
 *     return to title screen from stage
 */
void return_to_title_from_level_end(void) {
#ifdef VERSION_JP
    display_objective_status_text_on_status_change();
    FUN_7f057a40();
#endif
    if ((get_stage_num() != LEVELID_CUBA) && (check_objectives_complete() != 0x0)) {
        end_of_mission_briefing();
    }
    run_title_stage();
}

/**
 * 75B4	700069B4
 *     V0=state of debug menu (1:on; 0:off) [80024300]
 */
s32 get_debug_parse_flag(void) {
    return debug_feature_flag;
}

/**
 * 75C0	700069C0
 *     V0= p->debug.notice.list entry for boss_c_debug using data at 800241A0
 */
void bossInitDebugNoticeList(void) {
    debCheckAddDebugNoticeListEntry(&boss_c_ptr_debug_notice_list_entry, "boss_c_debug");
}


