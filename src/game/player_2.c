#include <ultra64.h>
#include <memp.h>
#include <fr.h>
#include <random.h>
#include "player.h"
#include "unk_092E50.h"
#include "bondview.h"
#include "lvl.h"
#include "player_2.h"


//newfile per EU

void default_player_perspective_and_height(void)
{
  float value  = 1.0f;

  if (0) { }

  g_playerPlayerData[0].player_perspective_height = value;
  g_playerPlayerData[0].handicap = value;
  g_playerPlayerData[1].player_perspective_height = value;
  g_playerPlayerData[1].handicap = value;
  g_playerPlayerData[2].player_perspective_height = value;
  g_playerPlayerData[2].handicap = value;
  g_playerPlayerData[3].player_perspective_height = value;
  g_playerPlayerData[3].handicap = value;
}

void reset_play_data_ptrs(void) 
{
    g_playerPointers[0] = 0;
    g_playerPointers[1] = 0;
    g_playerPointers[2] = 0;
    g_playerPointers[3] = 0;
    g_CurrentPlayer = 0;
    g_playerPerm = 0;
    player_num = 0;
    random_byte = 0;
    array_PLAYER_IDs[0] = 0;
    array_PLAYER_IDs[1] = 1;
    array_PLAYER_IDs[2] = 2;
    array_PLAYER_IDs[3] = 3;
}

void init_player_data_ptrs_construct_viewports(s32 playercount)
{
    s32 i;

    g_playerPointers[0] = NULL;
    g_playerPointers[1] = NULL;
    g_playerPointers[2] = NULL;
    g_playerPointers[3] = NULL;
    random_byte = (s32) (randomGetNext() & 0xFF);
    if (playercount > 0)
    {
        for (i = 0; i < playercount; i++)
        {
            initBONDdataforPlayer(i);
        }
        set_cur_player(0);
        return;
    }
    initBONDdataforPlayer(0);
    set_cur_player(0);
    set_cur_player_screen_size(viGetViewWidth(), viGetViewHeight());
    set_cur_player_viewport_size(viGetViewLeft(), viGetViewTop());
}

s32 getPlayerCount(void)
{
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (g_playerPointers[i] != NULL) {
            count++;
        }
    }
    return count;
}

#ifdef NONMATCHING
void initBONDdataforPlayer(PLAYER_ID player)
{
    int iVar1;
    int iVar2;
    player **ppPVar3;
    int *dest;
    int *src;
    int *src_next;
    player *pPVar4;
    int array234undefined4 [234];
    int iStack4;
    f32 temp_3f36e15f8e;

    src = init_BONDdata_related_8003fda0;
    dest = array234undefined4;
    do {
        src_next = src + 3;
        *dest = *src;
        dest[1] = src[1];
        dest[2] = src[2];
        src = src_next;
        dest = dest + 3;
    } while (src_next != (int *)0x80040148);
    pPVar4 = (player *)mempAllocBytesInBank(0x2a80,4);
    ppPVar3 = g_playerPointers + player;
    *ppPVar3 = pPVar4;
    pPVar4->unknown = 0;
    (*ppPVar3)->xpos = 0.00000000;
    (*ppPVar3)->ypos = 0.00000000;
    (*ppPVar3)->zpos = 0.00000000;
    (*ppPVar3)->xpos2 = 0.00000000;
    (*ppPVar3)->ypos2 = 0.00000000;
    (*ppPVar3)->zpos2 = 1.00000000;
    (*ppPVar3)->xoffset = 0.00000000;
    (*ppPVar3)->yoffset = 1.00000000;
    (*ppPVar3)->zoffset = 0.00000000;
    (*ppPVar3)->xpos3 = 0.00000000;
    (*ppPVar3)->ypos3 = 0.00000000;
    (*ppPVar3)->zpos3 = 0.00000000;
    (*ppPVar3)->room_pointer = 0;
    (*ppPVar3)->current_model_xpos = 0.00000000;
    (*ppPVar3)->current_model_ypos = 0.00000000;
    (*ppPVar3)->current_model_zpos = 0.00000000;
    (*ppPVar3)->previous_model_xpos = 0.00000000;
    (*ppPVar3)->previous_model_ypos = 0.00000000;
    (*ppPVar3)->previous_model_zpos = 0.00000000;
    (*ppPVar3)->current_room_xpos = 0.00000000;
    (*ppPVar3)->current_room_ypos = 0.00000000;
    (*ppPVar3)->current_room_zpos = 0.00000000;
    (*ppPVar3)->field_6C = 0.00000000;
    (*ppPVar3)->field_70 = 0.00000000;
    (*ppPVar3)->stanHeight = 0.00000000;
    (*ppPVar3)->field_78 = 0.00000000;
    (*ppPVar3)->field_7C = 0.00000000;
    (*ppPVar3)->field_80 = 0.00000000;
    (*ppPVar3)->field_84 = 0.00000000;
    (*ppPVar3)->field_88 = 0.00000000;
    (*ppPVar3)->field_8C = 0;
    (*ppPVar3)->field_90 = 0.00000000;
    (*ppPVar3)->field_94 = 0;
    (*ppPVar3)->field_98 = 0.00000000;
    (*ppPVar3)->swaytarget = 0.00000000;
    (*ppPVar3)->field_1278 = 0.00000000;
    (*ppPVar3)->field_127C = 0.00000000;
    (*ppPVar3)->crouchpos = 2;
    (*ppPVar3)->autocrouchpos = 2;
    (*ppPVar3)->ducking_height_offset = 0.00000000;
    (*ppPVar3)->field_A4 = 0.00000000;
    (*ppPVar3)->prop = 0;
    (*ppPVar3)->field_AC = 1;
    (*ppPVar3)->field_D0 = 0;
    (*ppPVar3)->ptr_char_objectinstance = 0;
    (*ppPVar3)->bonddead = 0;
    (*ppPVar3)->bondhealth = 1.00000000;
    (*ppPVar3)->bondarmour = 0.00000000;
    (*ppPVar3)->oldhealth = 1.00000000;
    (*ppPVar3)->oldarmour = 0.00000000;
    (*ppPVar3)->apparenthealth = 1.00000000;
    (*ppPVar3)->apparentarmour = 0.00000000;
    (*ppPVar3)->damageshowtime = -1;
    (*ppPVar3)->healthshowtime = -1;
    (*ppPVar3)->field_104 = 0;
    (*ppPVar3)->field_108 = 0;
    (*ppPVar3)->field_10C = 0;
    (*ppPVar3)->movecentrerelease = 0;
    (*ppPVar3)->lookaheadcentreenabled = 1;
    (*ppPVar3)->automovecentreenabled = 1;
    (*ppPVar3)->fastmovecentreenabled = 0;
    (*ppPVar3)->automovecentre = 1;
    (*ppPVar3)->insightaimmode = 0;
    (*ppPVar3)->autoyaimenabled = 1;
    (*ppPVar3)->autoaimy = 0.00000000;
    (*ppPVar3)->autoyaimtime = 0;
    (*ppPVar3)->autoyaimtime60 = -1;
    (*ppPVar3)->autoxaimenabled = 1;
    (*ppPVar3)->autoaimx = 0.00000000;
    (*ppPVar3)->autoxaimtime = 0;
    (*ppPVar3)->autoxaimtime60 = -1;
    (*ppPVar3)->vv_theta = 0.00000000;
    (*ppPVar3)->speedtheta = 0.00000000;
    (*ppPVar3)->vv_costheta = 1.00000000;
    (*ppPVar3)->vv_sintheta = 0.00000000;
    (*ppPVar3)->vv_verta = -4.00000000;
    (*ppPVar3)->vv_verta360 = -229.18310547;
    (*ppPVar3)->speedverta = 0.00000000;
    (*ppPVar3)->vv_cosverta = 1.00000000;
    (*ppPVar3)->vv_sinverta = 0.00000000;
    (*ppPVar3)->speedsideways = 0.00000000;
    (*ppPVar3)->speedstrafe = 0.00000000;
    (*ppPVar3)->speedforwards = 0.00000000;
    (*ppPVar3)->field_2A4C = 0.00000000;
    (*ppPVar3)->speedboost = 1.00000000;
    (*ppPVar3)->bondshotspeed.x = 0.00000000;
    (*ppPVar3)->bondshotspeed.y = 0.00000000;
    (*ppPVar3)->bondshotspeed.z = 0.00000000;
    (*ppPVar3)->bondfadetime60 = -1.00000000;
    (*ppPVar3)->bondfadetimemax60 = -1.00000000;
    (*ppPVar3)->bondfadefracold = 0.00000000;
    (*ppPVar3)->bondfadefracnew = 0.00000000;
    (*ppPVar3)->bondbreathing = 0.00000000;
    (*ppPVar3)->field_1A0 = 0;
    (*ppPVar3)->watch_pause_time = 0;
    (*ppPVar3)->field_1C4 = 0;
    (*ppPVar3)->pause_animation_state = 0;
    (*ppPVar3)->outside_watch_menu = 1;
    (*ppPVar3)->open_close_solo_watch_menu = 0;
    (*ppPVar3)->field_1D4 = 0.00000000;
    (*ppPVar3)->field_1D8 = 0.00000000;
    (*ppPVar3)->pause_watch_position = -25.00000000;
    (*ppPVar3)->field_1E0 = 0.00000000;
    (*ppPVar3)->field_1E4 = 1.00000000;
    (*ppPVar3)->field_1E8 = 0.00000000;
    (*ppPVar3)->field_1EC = 0.00000000;
    (*ppPVar3)->field_1F0 = 0.00000000;
    (*ppPVar3)->field_1F4 = 1.00000000;
    (*ppPVar3)->pausing_flag = 0;
    (*ppPVar3)->pause_starting_angle = 0.00000000;
    (*ppPVar3)->field_208 = 0.00000000;
    (*ppPVar3)->pause_target_angle = 0.00000000;
    (*ppPVar3)->field_210 = 0.00000000;
    (*ppPVar3)->field_214 = 0.00000000;
    (*ppPVar3)->field_218 = 0;
    (*ppPVar3)->field_21C = 1;
    (*ppPVar3)->step_in_view_watch_animation = 0;
    (*ppPVar3)->pause_animation_counter = 0.00000000;
    (*ppPVar3)->buttons_pressed = 0;
    (*ppPVar3)->field_3B6 = 0;
    (*ppPVar3)->field_3B8 = 0.00000000;
    (*ppPVar3)->field_3BC = 0.00000000;
    *(float *)&(*ppPVar3)->field_3C0 = 9.99999809;
    (*ppPVar3)->field_3C4 = 0.00000000;
    (*ppPVar3)->field_3C8 = 0.00000000;
    (*ppPVar3)->field_3CC = 1.00000000;
    (*ppPVar3)->colourscreenred = 0xff;
    (*ppPVar3)->colourscreengreen = 0xff;
    (*ppPVar3)->colourscreenblue = 0xff;
    (*ppPVar3)->colourscreenfrac = 0.00000000;
    (*ppPVar3)->field_3E0 = -1.00000000;
    (*ppPVar3)->timer_for_fade = -1.00000000;
    (*ppPVar3)->colourfaderedold = 0xff;
    (*ppPVar3)->colourfaderednew = 0xff;
    (*ppPVar3)->colourfadegreenold = 0xff;
    (*ppPVar3)->colourfadegreennew = 0xff;
    (*ppPVar3)->colourfadeblueold = 0xff;
    (*ppPVar3)->colourfadebluenew = 0xff;
    (*ppPVar3)->colourfadefracold = 0.00000000;
    (*ppPVar3)->colourfadefracnew = 0.00000000;
    (*ppPVar3)->bondtype = CUFF_BLUE;
    (*ppPVar3)->startnewbonddie = 1;
    (*ppPVar3)->redbloodfinished             = 0;
    (*ppPVar3)->deathanimfinished = 0;
    (*ppPVar3)->field_42c = 2;
    (*ppPVar3)->controlstyle = 0;
    (*ppPVar3)->field_4DC = 1;
    (*ppPVar3)->field_4E0 = 1;
    (*ppPVar3)->resetheadtick = 1;
    (*ppPVar3)->headanim = 0;
    (*ppPVar3)->field_4EC = 0.93000001;
    (*ppPVar3)->headwalkingtime60 = 0;
    (*ppPVar3)->headamplitude = 1.00000000;
    (*ppPVar3)->sideamplitude = 1.00000000;
    (*ppPVar3)->headpos = 0.00000000;
    (*ppPVar3)->field_500 = 0.00000000;
    (*ppPVar3)->field_504 = 0.00000000;
    (*ppPVar3)->field_508 = 0.00000000;
    (*ppPVar3)->field_50C = 0.00000000;
    (*ppPVar3)->field_510 = 1.00000000;
    (*ppPVar3)->field_514 = 0.00000000;
    (*ppPVar3)->field_518 = 1.00000000;
    (*ppPVar3)->field_51C = 0.00000000;
    (*ppPVar3)->headpossum = 0.00000000;
    (*ppPVar3)->field_524 = 0.00000000;
    (*ppPVar3)->field_528 = 0.00000000;
    (*ppPVar3)->field_52C = 0.00000000;
    (*ppPVar3)->field_530 = 0.00000000;
    *(f32 *)&(*ppPVar3)->field_534 = 14.28571606;
    (*ppPVar3)->field_538 = 0;
    (*ppPVar3)->field_53C = 14.28571606;
    (*ppPVar3)->field_540 = 0.00000000;
    (*ppPVar3)->headbodyoffset = 0.00000000;
    (*ppPVar3)->field_548 = 0.00000000;
    (*ppPVar3)->field_54C = 0.00000000;
    (*ppPVar3)->standheight = 0.00000000;
    (*ppPVar3)->standbodyoffset.x = 0.00000000;
    (*ppPVar3)->standbodyoffset.y = 0.00000000;
    (*ppPVar3)->standbodyoffset.z = 0.00000000;
    (*ppPVar3)->standfrac = 0.00000000;
    (*ppPVar3)->field_564 = 0.00000000;
    (*ppPVar3)->field_568 = 0.00000000;
    (*ppPVar3)->field_56C = 1.00000000;
    (*ppPVar3)->field_570 = 0.00000000;
    (*ppPVar3)->field_574 = 0.00000000;
    (*ppPVar3)->field_578 = 1.00000000;
    (*ppPVar3)->field_57C = 0.00000000;
    (*ppPVar3)->field_580 = 1.00000000;
    (*ppPVar3)->field_584 = 0.00000000;
    (*ppPVar3)->field_588 = 0.00000000;
    (*ppPVar3)->field_58C = 1.00000000;
    (*ppPVar3)->field_590 = 0.00000000;
    (*ppPVar3)->standcnt = 0;
    iVar1 = 0;
    do {
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D0 + iVar1) = 0x280;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D2 + iVar1) = 0x1e0;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D4 + iVar1) = 0x1ff;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D6 + iVar1) = 0;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7D8 + iVar1) = 0x280;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7DA + iVar1) = 0x1e0;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7DC + iVar1) = 0x1ff;
        iVar2 = iVar1 + 0x10;
        *(undefined2 *)((int)&((*ppPVar3)->field_7D0).field_7DE + iVar1) = 0;
        iVar1 = iVar2;
    } while (iVar2 != 0x20);
    (*ppPVar3)->viewx = 100;
    (*ppPVar3)->viewy = 100;
    (*ppPVar3)->viewleft = 0;
    (*ppPVar3)->viewtop = 0;
    (*ppPVar3)->hand_invisible[0] = 0;
    (*ppPVar3)->hand_invisible[1] = 0;
    (*ppPVar3)->hand_item[0] = ITEM_UNARMED;
    (*ppPVar3)->hand_item[1] = ITEM_UNARMED;
    (*ppPVar3)->field_2A44[0] = -1;
    (*ppPVar3)->field_2A44[1] = -1;
    (*ppPVar3)->lock_hand_model[0] = 0;
    (*ppPVar3)->lock_hand_model[1] = 0;
    (*ppPVar3)->ptr_hand_weapon_buffer[0] = NULL;
    (*ppPVar3)->ptr_hand_weapon_buffer[1] = NULL;
    pPVar4 = *ppPVar3;
    src = array234undefined4;
    do {
        dest = src + 3;
        pPVar4->right_weapon = *src;
        pPVar4->right_weapon_attack = src[1];
        pPVar4->previous_right_weapon = src[2];
        pPVar4 = (player *)&pPVar4->zpos;
        src = dest;
    } while (dest != &iStack4);
    src = array234undefined4;
    pPVar4 = *ppPVar3;
    do {
        dest = src + 3;
        pPVar4->left_weapon = *src;
        pPVar4->left_weapon_attack = src[1];
        pPVar4->left_weapon_previous = src[2];
        src = dest;
        pPVar4 = (player *)&pPVar4->zpos;
    } while (dest != &iStack4);
    (*ppPVar3)->gunposamplitude = 1.00000000;
    (*ppPVar3)->gunxamplitude = 1.00000000;
    (*ppPVar3)->field_FC8 = 0;
    (*ppPVar3)->field_FCC = 0;
    (*ppPVar3)->field_FD0 = 0;
    (*ppPVar3)->z_trigger_timer = 0;
    (*ppPVar3)->field_FD8 = 0;
    (*ppPVar3)->field_FDC = -1;
    (*ppPVar3)->field_FDD = -1;
    (*ppPVar3)->field_FDE = -1;
    (*ppPVar3)->field_FDF = '\0';
    (*ppPVar3)->resetshadecol = 1;
    (*ppPVar3)->field_FE4 = 0;
    (*ppPVar3)->field_FE8 = 0.00000000;
    (*ppPVar3)->field_FEC = 0.00000000;
    (*ppPVar3)->field_FF0 = 0.00000000;
    (*ppPVar3)->field_FF4 = 0.00000000;
    (*ppPVar3)->guncrossdamp = 0.89999998;
    (*ppPVar3)->field_FFC = 0.00000000;
    (*ppPVar3)->field_1000 = 0.00000000;
    (*ppPVar3)->field_1004 = 0.00000000;
    (*ppPVar3)->field_1008 = 0.00000000;
    (*ppPVar3)->gunaimdamp = 0.89999998;
    (*ppPVar3)->field_1010 = 0.00000000;
    (*ppPVar3)->holds_neg_pi = -3.14159274;
    (*ppPVar3)->field_1018 = 0.00000000;
    (*ppPVar3)->last_z_trigger_timer = 0;
    (*ppPVar3)->copiedgoldeneye = 0;
    (*ppPVar3)->ammodispflags = 0;
    (*ppPVar3)->field_106C = 0.00000000;
    (*ppPVar3)->field_1070 = 0.00000000;
    (*ppPVar3)->field_1074 = 0.00000000;
    (*ppPVar3)->field_1078 = 0;
    (*ppPVar3)->field_107C = 0.00000000;
    (*ppPVar3)->field_1080 = 0.00000000;
    (*ppPVar3)->sniper_zoom = 60.00000000;
    (*ppPVar3)->camera_zoom = 60.00000000;
    (*ppPVar3)->field_108C = -1;
    (*ppPVar3)->c_screenwidth = 320.00000000;
    (*ppPVar3)->c_screenheight = 240.00000000;
    (*ppPVar3)->c_screenleft = 0.00000000;
    (*ppPVar3)->c_screentop = 0.00000000;
    (*ppPVar3)->c_perspnear = 10.00000000;
    (*ppPVar3)->c_perspfovy = 46.00000000;
    (*ppPVar3)->c_perspaspect = 1.00000000;
    (*ppPVar3)->c_halfwidth = 160.00000000;
    (*ppPVar3)->c_halfheight = 120.00000000;
    (*ppPVar3)->c_scalex = 1.00000000;
    (*ppPVar3)->c_scaley = 1.00000000;
    (*ppPVar3)->c_recipscalex = 1.00000000;
    (*ppPVar3)->c_recipscaley = 1.00000000;
    (*ppPVar3)->field_10C4 = 0;
    (*ppPVar3)->field_10C8 = 0;
    (*ppPVar3)->field_10CC = 0;
    (*ppPVar3)->field_10D0 = 0;
    (*ppPVar3)->field_10D4 = 0;
    (*ppPVar3)->projmatrix = 0;
    (*ppPVar3)->projmatrixf = 0;
    (*ppPVar3)->field_10E0 = 0;
    (*ppPVar3)->field_10E4 = 0;
    (*ppPVar3)->field_10E8 = 0;
    (*ppPVar3)->field_10EC = 0;
    (*ppPVar3)->c_scalelod60 = 1.00000000;
    (*ppPVar3)->c_scalelod = 1.00000000;
    (*ppPVar3)->c_lodscalez = 1.00000000;
    (*ppPVar3)->c_lodscalezu32 = 0x10000;
    (*ppPVar3)->screenxminf = 0.00000000;
    (*ppPVar3)->screenyminf = 0.00000000;
    (*ppPVar3)->screenxmaxf = 320.00000000;
    (*ppPVar3)->screenymaxf = 240.00000000;
    (*ppPVar3)->gunsightmode = 0;
    (*ppPVar3)->field_11B0 = 0;
    (*ppPVar3)->field_11B4 = 0;
    (*ppPVar3)->field_11B8 = 0;
    (*ppPVar3)->zoomintime = 0.00000000;
    (*ppPVar3)->zoomintimemax = 0.00000000;
    (*ppPVar3)->zoominfovy = 60.00000000;
    (*ppPVar3)->zoominfovyold = 60.00000000;
    (*ppPVar3)->zoominfovynew = 60.00000000;
    (*ppPVar3)->fovy = 60.00000000;
    (*ppPVar3)->aspect = 1.33333337;
    (*ppPVar3)->hudmessoff = 0;
    (*ppPVar3)->bondmesscnt = -1;
    (*ppPVar3)->ptr_inventory_first_in_cycle = 0;
    (*ppPVar3)->p_itemcur = 0;
    (*ppPVar3)->equipmaxitems = 0;
    (*ppPVar3)->equipallguns = 0;
    (*ppPVar3)->field_11F0 = 0;
    (*ppPVar3)->field_11F4 = 0;
    (*ppPVar3)->field_1280 = 0;
    (*ppPVar3)->players_cur_animation = 0;
    (*ppPVar3)->field_1288 = 0.00000000;
    (*ppPVar3)->bondinvincible = '\0';
    (*ppPVar3)->field_29B8 = 7;
    (*ppPVar3)->field_29BC = 1.00000000;
    (*ppPVar3)->field_29C0 = 0.00000000;
    (*ppPVar3)->mpmenuon = 0;
    (*ppPVar3)->damagetype = 7;
    (*ppPVar3)->deathcount = 0;
    (*ppPVar3)->field_29E0 = random_byte;
    random_byte = random_byte + 1;
    (*ppPVar3)->field_29E4 = -1;
    (*ppPVar3)->field_29E8 = -1;
    (*ppPVar3)->field_29EC = -1;
    (*ppPVar3)->field_29F0 = -1;
    (*ppPVar3)->healthdisplaytime = 0;
    (*ppPVar3)->field_2A30 = 0;
    (*ppPVar3)->field_2A34 = 0;
    (*ppPVar3)->cur_item_weapon_getname = 1;
    (*ppPVar3)->actual_health = 1.00000000;
    (*ppPVar3)->actual_armor = 1.00000000;
    (*ppPVar3)->cur_player_control_type_0 = 0;
    (*ppPVar3)->cur_player_control_type_1 = 0;
    (*ppPVar3)->cur_player_control_type_2 = 0.00000000;
    (*ppPVar3)->neg_vspacing_for_control_type_entry = 0;
    (*ppPVar3)->has_set_control_type_data = 1;
    (*ppPVar3)->field_2A6C = 0;
    (*ppPVar3)->field_2A70 = 0;
    visible_to_guards_flag = TRUE;
    obj_collision_flag = TRUE;
}
#else
#ifdef VERSION_US
GLOBAL_ASM(
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x411ffffe /*9.9999981*/
glabel D_80057618
.word 0x3f6e147b /*0.93000001*/
glabel D_8005761C
.word 0x4164924b /*14.285716*/
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3faaaaab /*1.3333334*/
.text
glabel initBONDdataforPlayer
/* 0CEFEC 7F09A4BC 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 0CEFF0 7F09A4C0 3C0F8004 */  lui   $t7, %hi(D_8003FD94+0xC)
/* 0CEFF4 7F09A4C4 25EFFDA0 */  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x260
/* 0CEFF8 7F09A4C8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CEFFC 7F09A4CC AFA403D0 */  sw    $a0, 0x3d0($sp)
/* 0CF000 7F09A4D0 25EB03A8 */  addiu $t3, $t7, 0x3a8
/* 0CF004 7F09A4D4 27AE0024 */  addiu $t6, $sp, 0x24
.L7F09A4D8:
/* 0CF008 7F09A4D8 8DE10000 */  lw    $at, ($t7)
/* 0CF00C 7F09A4DC 25EF000C */  addiu $t7, $t7, 0xc
/* 0CF010 7F09A4E0 25CE000C */  addiu $t6, $t6, 0xc
/* 0CF014 7F09A4E4 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0CF018 7F09A4E8 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CF01C 7F09A4EC ADC1FFF8 */  sw    $at, -8($t6)
/* 0CF020 7F09A4F0 8DE1FFFC */  lw    $at, -4($t7)
/* 0CF024 7F09A4F4 15EBFFF8 */  bne   $t7, $t3, .L7F09A4D8
/* 0CF028 7F09A4F8 ADC1FFFC */   sw    $at, -4($t6)
/* 0CF02C 7F09A4FC 24042A80 */  li    $a0, 10880
/* 0CF030 7F09A500 0C0025C8 */  jal   mempAllocBytesInBank
/* 0CF034 7F09A504 24050004 */   li    $a1, 4
/* 0CF038 7F09A508 8FAC03D0 */  lw    $t4, 0x3d0($sp)
/* 0CF03C 7F09A50C 3C198008 */  lui   $t9, %hi(g_playerPointers)
/* 0CF040 7F09A510 27399EE0 */  addiu $t9, %lo(g_playerPointers) # addiu $t9, $t9, -0x6120
/* 0CF044 7F09A514 000C6880 */  sll   $t5, $t4, 2
/* 0CF048 7F09A518 01B91821 */  addu  $v1, $t5, $t9
/* 0CF04C 7F09A51C AC620000 */  sw    $v0, ($v1)
/* 0CF050 7F09A520 AC400000 */  sw    $zero, ($v0)
/* 0CF054 7F09A524 44800000 */  mtc1  $zero, $f0
/* 0CF058 7F09A528 8C780000 */  lw    $t8, ($v1)
/* 0CF05C 7F09A52C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CF060 7F09A530 44811000 */  mtc1  $at, $f2
/* 0CF064 7F09A534 E7000004 */  swc1  $f0, 4($t8)
/* 0CF068 7F09A538 8C6B0000 */  lw    $t3, ($v1)
/* 0CF06C 7F09A53C 24040002 */  li    $a0, 2
/* 0CF070 7F09A540 24080001 */  li    $t0, 1
/* 0CF074 7F09A544 E5600008 */  swc1  $f0, 8($t3)
/* 0CF078 7F09A548 8C6F0000 */  lw    $t7, ($v1)
/* 0CF07C 7F09A54C 2409FFFF */  li    $t1, -1
/* 0CF080 7F09A550 3C01C080 */  li    $at, 0xC0800000 # -4.000000
/* 0CF084 7F09A554 E5E0000C */  swc1  $f0, 0xc($t7)
/* 0CF088 7F09A558 8C6E0000 */  lw    $t6, ($v1)
/* 0CF08C 7F09A55C 44812000 */  mtc1  $at, $f4
/* 0CF090 7F09A560 3C018005 */  lui   $at, %hi(D_80057610)
/* 0CF094 7F09A564 E5C00010 */  swc1  $f0, 0x10($t6)
/* 0CF098 7F09A568 8C6C0000 */  lw    $t4, ($v1)
/* 0CF09C 7F09A56C 240200FF */  li    $v0, 255
/* 0CF0A0 7F09A570 27AA0024 */  addiu $t2, $sp, 0x24
/* 0CF0A4 7F09A574 E5800014 */  swc1  $f0, 0x14($t4)
/* 0CF0A8 7F09A578 8C6D0000 */  lw    $t5, ($v1)
/* 0CF0AC 7F09A57C E5A20018 */  swc1  $f2, 0x18($t5)
/* 0CF0B0 7F09A580 8C790000 */  lw    $t9, ($v1)
/* 0CF0B4 7F09A584 E720001C */  swc1  $f0, 0x1c($t9)
/* 0CF0B8 7F09A588 8C780000 */  lw    $t8, ($v1)
/* 0CF0BC 7F09A58C E7020020 */  swc1  $f2, 0x20($t8)
/* 0CF0C0 7F09A590 8C6B0000 */  lw    $t3, ($v1)
/* 0CF0C4 7F09A594 E5600024 */  swc1  $f0, 0x24($t3)
/* 0CF0C8 7F09A598 8C6F0000 */  lw    $t7, ($v1)
/* 0CF0CC 7F09A59C E5E00028 */  swc1  $f0, 0x28($t7)
/* 0CF0D0 7F09A5A0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF0D4 7F09A5A4 E5C0002C */  swc1  $f0, 0x2c($t6)
/* 0CF0D8 7F09A5A8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF0DC 7F09A5AC E5800030 */  swc1  $f0, 0x30($t4)
/* 0CF0E0 7F09A5B0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF0E4 7F09A5B4 ADA00034 */  sw    $zero, 0x34($t5)
/* 0CF0E8 7F09A5B8 8C790000 */  lw    $t9, ($v1)
/* 0CF0EC 7F09A5BC E7200038 */  swc1  $f0, 0x38($t9)
/* 0CF0F0 7F09A5C0 8C780000 */  lw    $t8, ($v1)
/* 0CF0F4 7F09A5C4 E700003C */  swc1  $f0, 0x3c($t8)
/* 0CF0F8 7F09A5C8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF0FC 7F09A5CC E5600040 */  swc1  $f0, 0x40($t3)
/* 0CF100 7F09A5D0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF104 7F09A5D4 E5E00044 */  swc1  $f0, 0x44($t7)
/* 0CF108 7F09A5D8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF10C 7F09A5DC E5C00048 */  swc1  $f0, 0x48($t6)
/* 0CF110 7F09A5E0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF114 7F09A5E4 E580004C */  swc1  $f0, 0x4c($t4)
/* 0CF118 7F09A5E8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF11C 7F09A5EC E5A00050 */  swc1  $f0, 0x50($t5)
/* 0CF120 7F09A5F0 8C790000 */  lw    $t9, ($v1)
/* 0CF124 7F09A5F4 E7200054 */  swc1  $f0, 0x54($t9)
/* 0CF128 7F09A5F8 8C780000 */  lw    $t8, ($v1)
/* 0CF12C 7F09A5FC E7000058 */  swc1  $f0, 0x58($t8)
/* 0CF130 7F09A600 8C6B0000 */  lw    $t3, ($v1)
/* 0CF134 7F09A604 E560006C */  swc1  $f0, 0x6c($t3)
/* 0CF138 7F09A608 8C6F0000 */  lw    $t7, ($v1)
/* 0CF13C 7F09A60C E5E00070 */  swc1  $f0, 0x70($t7)
/* 0CF140 7F09A610 8C6E0000 */  lw    $t6, ($v1)
/* 0CF144 7F09A614 E5C00074 */  swc1  $f0, 0x74($t6)
/* 0CF148 7F09A618 8C6C0000 */  lw    $t4, ($v1)
/* 0CF14C 7F09A61C E5800078 */  swc1  $f0, 0x78($t4)
/* 0CF150 7F09A620 8C6D0000 */  lw    $t5, ($v1)
/* 0CF154 7F09A624 E5A0007C */  swc1  $f0, 0x7c($t5)
/* 0CF158 7F09A628 8C790000 */  lw    $t9, ($v1)
/* 0CF15C 7F09A62C E7200080 */  swc1  $f0, 0x80($t9)
/* 0CF160 7F09A630 8C780000 */  lw    $t8, ($v1)
/* 0CF164 7F09A634 E7000084 */  swc1  $f0, 0x84($t8)
/* 0CF168 7F09A638 8C6B0000 */  lw    $t3, ($v1)
/* 0CF16C 7F09A63C E5600088 */  swc1  $f0, 0x88($t3)
/* 0CF170 7F09A640 8C6F0000 */  lw    $t7, ($v1)
/* 0CF174 7F09A644 ADE0008C */  sw    $zero, 0x8c($t7)
/* 0CF178 7F09A648 8C6E0000 */  lw    $t6, ($v1)
/* 0CF17C 7F09A64C E5C00090 */  swc1  $f0, 0x90($t6)
/* 0CF180 7F09A650 8C6C0000 */  lw    $t4, ($v1)
/* 0CF184 7F09A654 AD800094 */  sw    $zero, 0x94($t4)
/* 0CF188 7F09A658 8C6D0000 */  lw    $t5, ($v1)
/* 0CF18C 7F09A65C E5A00098 */  swc1  $f0, 0x98($t5)
/* 0CF190 7F09A660 8C790000 */  lw    $t9, ($v1)
/* 0CF194 7F09A664 E7201274 */  swc1  $f0, 0x1274($t9)
/* 0CF198 7F09A668 8C780000 */  lw    $t8, ($v1)
/* 0CF19C 7F09A66C E7001278 */  swc1  $f0, 0x1278($t8)
/* 0CF1A0 7F09A670 8C6B0000 */  lw    $t3, ($v1)
/* 0CF1A4 7F09A674 E560127C */  swc1  $f0, 0x127c($t3)
/* 0CF1A8 7F09A678 8C6F0000 */  lw    $t7, ($v1)
/* 0CF1AC 7F09A67C ADE4009C */  sw    $a0, 0x9c($t7)
/* 0CF1B0 7F09A680 8C6E0000 */  lw    $t6, ($v1)
/* 0CF1B4 7F09A684 ADC429FC */  sw    $a0, 0x29fc($t6)
/* 0CF1B8 7F09A688 8C6C0000 */  lw    $t4, ($v1)
/* 0CF1BC 7F09A68C E58000A0 */  swc1  $f0, 0xa0($t4)
/* 0CF1C0 7F09A690 8C6D0000 */  lw    $t5, ($v1)
/* 0CF1C4 7F09A694 E5A000A4 */  swc1  $f0, 0xa4($t5)
/* 0CF1C8 7F09A698 8C790000 */  lw    $t9, ($v1)
/* 0CF1CC 7F09A69C AF2000A8 */  sw    $zero, 0xa8($t9)
/* 0CF1D0 7F09A6A0 8C780000 */  lw    $t8, ($v1)
/* 0CF1D4 7F09A6A4 AF0800AC */  sw    $t0, 0xac($t8)
/* 0CF1D8 7F09A6A8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF1DC 7F09A6AC AD6000D0 */  sw    $zero, 0xd0($t3)
/* 0CF1E0 7F09A6B0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF1E4 7F09A6B4 ADE000D4 */  sw    $zero, 0xd4($t7)
/* 0CF1E8 7F09A6B8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF1EC 7F09A6BC ADC000D8 */  sw    $zero, 0xd8($t6)
/* 0CF1F0 7F09A6C0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF1F4 7F09A6C4 E58200DC */  swc1  $f2, 0xdc($t4)
/* 0CF1F8 7F09A6C8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF1FC 7F09A6CC E5A000E0 */  swc1  $f0, 0xe0($t5)
/* 0CF200 7F09A6D0 8C790000 */  lw    $t9, ($v1)
/* 0CF204 7F09A6D4 E72200E4 */  swc1  $f2, 0xe4($t9)
/* 0CF208 7F09A6D8 8C780000 */  lw    $t8, ($v1)
/* 0CF20C 7F09A6DC E70000E8 */  swc1  $f0, 0xe8($t8)
/* 0CF210 7F09A6E0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF214 7F09A6E4 E56200EC */  swc1  $f2, 0xec($t3)
/* 0CF218 7F09A6E8 8C6F0000 */  lw    $t7, ($v1)
/* 0CF21C 7F09A6EC E5E000F0 */  swc1  $f0, 0xf0($t7)
/* 0CF220 7F09A6F0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF224 7F09A6F4 ADC900F4 */  sw    $t1, 0xf4($t6)
/* 0CF228 7F09A6F8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF22C 7F09A6FC AD8900F8 */  sw    $t1, 0xf8($t4)
/* 0CF230 7F09A700 8C6D0000 */  lw    $t5, ($v1)
/* 0CF234 7F09A704 ADA00104 */  sw    $zero, 0x104($t5)
/* 0CF238 7F09A708 8C790000 */  lw    $t9, ($v1)
/* 0CF23C 7F09A70C AF200108 */  sw    $zero, 0x108($t9)
/* 0CF240 7F09A710 8C780000 */  lw    $t8, ($v1)
/* 0CF244 7F09A714 AF00010C */  sw    $zero, 0x10c($t8)
/* 0CF248 7F09A718 8C6B0000 */  lw    $t3, ($v1)
/* 0CF24C 7F09A71C AD600110 */  sw    $zero, 0x110($t3)
/* 0CF250 7F09A720 8C6F0000 */  lw    $t7, ($v1)
/* 0CF254 7F09A724 ADE80114 */  sw    $t0, 0x114($t7)
/* 0CF258 7F09A728 8C6E0000 */  lw    $t6, ($v1)
/* 0CF25C 7F09A72C ADC80118 */  sw    $t0, 0x118($t6)
/* 0CF260 7F09A730 8C6C0000 */  lw    $t4, ($v1)
/* 0CF264 7F09A734 AD80011C */  sw    $zero, 0x11c($t4)
/* 0CF268 7F09A738 8C6D0000 */  lw    $t5, ($v1)
/* 0CF26C 7F09A73C ADA80120 */  sw    $t0, 0x120($t5)
/* 0CF270 7F09A740 8C790000 */  lw    $t9, ($v1)
/* 0CF274 7F09A744 AF200124 */  sw    $zero, 0x124($t9)
/* 0CF278 7F09A748 8C780000 */  lw    $t8, ($v1)
/* 0CF27C 7F09A74C AF080128 */  sw    $t0, 0x128($t8)
/* 0CF280 7F09A750 8C6B0000 */  lw    $t3, ($v1)
/* 0CF284 7F09A754 E560012C */  swc1  $f0, 0x12c($t3)
/* 0CF288 7F09A758 8C6F0000 */  lw    $t7, ($v1)
/* 0CF28C 7F09A75C ADE00130 */  sw    $zero, 0x130($t7)
/* 0CF290 7F09A760 8C6E0000 */  lw    $t6, ($v1)
/* 0CF294 7F09A764 ADC90134 */  sw    $t1, 0x134($t6)
/* 0CF298 7F09A768 8C6C0000 */  lw    $t4, ($v1)
/* 0CF29C 7F09A76C AD880138 */  sw    $t0, 0x138($t4)
/* 0CF2A0 7F09A770 8C6D0000 */  lw    $t5, ($v1)
/* 0CF2A4 7F09A774 E5A0013C */  swc1  $f0, 0x13c($t5)
/* 0CF2A8 7F09A778 8C790000 */  lw    $t9, ($v1)
/* 0CF2AC 7F09A77C AF200140 */  sw    $zero, 0x140($t9)
/* 0CF2B0 7F09A780 8C780000 */  lw    $t8, ($v1)
/* 0CF2B4 7F09A784 AF090144 */  sw    $t1, 0x144($t8)
/* 0CF2B8 7F09A788 8C6B0000 */  lw    $t3, ($v1)
/* 0CF2BC 7F09A78C E5600148 */  swc1  $f0, 0x148($t3)
/* 0CF2C0 7F09A790 8C6F0000 */  lw    $t7, ($v1)
/* 0CF2C4 7F09A794 E5E0014C */  swc1  $f0, 0x14c($t7)
/* 0CF2C8 7F09A798 8C6E0000 */  lw    $t6, ($v1)
/* 0CF2CC 7F09A79C E5C20150 */  swc1  $f2, 0x150($t6)
/* 0CF2D0 7F09A7A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF2D4 7F09A7A4 E5800154 */  swc1  $f0, 0x154($t4)
/* 0CF2D8 7F09A7A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF2DC 7F09A7AC E5A40158 */  swc1  $f4, 0x158($t5)
/* 0CF2E0 7F09A7B0 8C790000 */  lw    $t9, ($v1)
/* 0CF2E4 7F09A7B4 C4267610 */  lwc1  $f6, %lo(D_80057610)($at)
/* 0CF2E8 7F09A7B8 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CF2EC 7F09A7BC 44816000 */  mtc1  $at, $f12
/* 0CF2F0 7F09A7C0 E726015C */  swc1  $f6, 0x15c($t9)
/* 0CF2F4 7F09A7C4 8C780000 */  lw    $t8, ($v1)
/* 0CF2F8 7F09A7C8 3C01C1C8 */  li    $at, 0xC1C80000 # -25.000000
/* 0CF2FC 7F09A7CC 44814000 */  mtc1  $at, $f8
/* 0CF300 7F09A7D0 E7000160 */  swc1  $f0, 0x160($t8)
/* 0CF304 7F09A7D4 8C6B0000 */  lw    $t3, ($v1)
/* 0CF308 7F09A7D8 3C018005 */  lui   $at, %hi(D_80057614)
/* 0CF30C 7F09A7DC E5620164 */  swc1  $f2, 0x164($t3)
/* 0CF310 7F09A7E0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF314 7F09A7E4 E5E00168 */  swc1  $f0, 0x168($t7)
/* 0CF318 7F09A7E8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF31C 7F09A7EC E5C0016C */  swc1  $f0, 0x16c($t6)
/* 0CF320 7F09A7F0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF324 7F09A7F4 E5800170 */  swc1  $f0, 0x170($t4)
/* 0CF328 7F09A7F8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF32C 7F09A7FC E5A00174 */  swc1  $f0, 0x174($t5)
/* 0CF330 7F09A800 8C790000 */  lw    $t9, ($v1)
/* 0CF334 7F09A804 E7202A4C */  swc1  $f0, 0x2a4c($t9)
/* 0CF338 7F09A808 8C780000 */  lw    $t8, ($v1)
/* 0CF33C 7F09A80C E7020178 */  swc1  $f2, 0x178($t8)
/* 0CF340 7F09A810 8C6B0000 */  lw    $t3, ($v1)
/* 0CF344 7F09A814 E5600180 */  swc1  $f0, 0x180($t3)
/* 0CF348 7F09A818 8C6F0000 */  lw    $t7, ($v1)
/* 0CF34C 7F09A81C E5E00184 */  swc1  $f0, 0x184($t7)
/* 0CF350 7F09A820 8C6E0000 */  lw    $t6, ($v1)
/* 0CF354 7F09A824 E5C00188 */  swc1  $f0, 0x188($t6)
/* 0CF358 7F09A828 8C6C0000 */  lw    $t4, ($v1)
/* 0CF35C 7F09A82C E58C018C */  swc1  $f12, 0x18c($t4)
/* 0CF360 7F09A830 8C6D0000 */  lw    $t5, ($v1)
/* 0CF364 7F09A834 E5AC0190 */  swc1  $f12, 0x190($t5)
/* 0CF368 7F09A838 8C790000 */  lw    $t9, ($v1)
/* 0CF36C 7F09A83C E7200194 */  swc1  $f0, 0x194($t9)
/* 0CF370 7F09A840 8C780000 */  lw    $t8, ($v1)
/* 0CF374 7F09A844 E7000198 */  swc1  $f0, 0x198($t8)
/* 0CF378 7F09A848 8C6B0000 */  lw    $t3, ($v1)
/* 0CF37C 7F09A84C E560019C */  swc1  $f0, 0x19c($t3)
/* 0CF380 7F09A850 8C6F0000 */  lw    $t7, ($v1)
/* 0CF384 7F09A854 ADE001A0 */  sw    $zero, 0x1a0($t7)
/* 0CF388 7F09A858 8C6E0000 */  lw    $t6, ($v1)
/* 0CF38C 7F09A85C ADC001C0 */  sw    $zero, 0x1c0($t6)
/* 0CF390 7F09A860 8C6C0000 */  lw    $t4, ($v1)
/* 0CF394 7F09A864 AD8001C4 */  sw    $zero, 0x1c4($t4)
/* 0CF398 7F09A868 8C6D0000 */  lw    $t5, ($v1)
/* 0CF39C 7F09A86C ADA001C8 */  sw    $zero, 0x1c8($t5)
/* 0CF3A0 7F09A870 8C790000 */  lw    $t9, ($v1)
/* 0CF3A4 7F09A874 AF2801CC */  sw    $t0, 0x1cc($t9)
/* 0CF3A8 7F09A878 8C780000 */  lw    $t8, ($v1)
/* 0CF3AC 7F09A87C AF0001D0 */  sw    $zero, 0x1d0($t8)
/* 0CF3B0 7F09A880 8C6B0000 */  lw    $t3, ($v1)
/* 0CF3B4 7F09A884 E56001D4 */  swc1  $f0, 0x1d4($t3)
/* 0CF3B8 7F09A888 8C6F0000 */  lw    $t7, ($v1)
/* 0CF3BC 7F09A88C E5E001D8 */  swc1  $f0, 0x1d8($t7)
/* 0CF3C0 7F09A890 8C6E0000 */  lw    $t6, ($v1)
/* 0CF3C4 7F09A894 E5C801DC */  swc1  $f8, 0x1dc($t6)
/* 0CF3C8 7F09A898 8C6C0000 */  lw    $t4, ($v1)
/* 0CF3CC 7F09A89C E58001E0 */  swc1  $f0, 0x1e0($t4)
/* 0CF3D0 7F09A8A0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF3D4 7F09A8A4 E5A201E4 */  swc1  $f2, 0x1e4($t5)
/* 0CF3D8 7F09A8A8 8C790000 */  lw    $t9, ($v1)
/* 0CF3DC 7F09A8AC E72001E8 */  swc1  $f0, 0x1e8($t9)
/* 0CF3E0 7F09A8B0 8C780000 */  lw    $t8, ($v1)
/* 0CF3E4 7F09A8B4 E70001EC */  swc1  $f0, 0x1ec($t8)
/* 0CF3E8 7F09A8B8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF3EC 7F09A8BC E56001F0 */  swc1  $f0, 0x1f0($t3)
/* 0CF3F0 7F09A8C0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF3F4 7F09A8C4 E5E201F4 */  swc1  $f2, 0x1f4($t7)
/* 0CF3F8 7F09A8C8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF3FC 7F09A8CC ADC00200 */  sw    $zero, 0x200($t6)
/* 0CF400 7F09A8D0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF404 7F09A8D4 E5800204 */  swc1  $f0, 0x204($t4)
/* 0CF408 7F09A8D8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF40C 7F09A8DC E5A00208 */  swc1  $f0, 0x208($t5)
/* 0CF410 7F09A8E0 8C790000 */  lw    $t9, ($v1)
/* 0CF414 7F09A8E4 E720020C */  swc1  $f0, 0x20c($t9)
/* 0CF418 7F09A8E8 8C780000 */  lw    $t8, ($v1)
/* 0CF41C 7F09A8EC E7000210 */  swc1  $f0, 0x210($t8)
/* 0CF420 7F09A8F0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF424 7F09A8F4 E5600214 */  swc1  $f0, 0x214($t3)
/* 0CF428 7F09A8F8 8C6F0000 */  lw    $t7, ($v1)
/* 0CF42C 7F09A8FC ADE00218 */  sw    $zero, 0x218($t7)
/* 0CF430 7F09A900 8C6E0000 */  lw    $t6, ($v1)
/* 0CF434 7F09A904 ADC8021C */  sw    $t0, 0x21c($t6)
/* 0CF438 7F09A908 8C6C0000 */  lw    $t4, ($v1)
/* 0CF43C 7F09A90C AD800220 */  sw    $zero, 0x220($t4)
/* 0CF440 7F09A910 8C6D0000 */  lw    $t5, ($v1)
/* 0CF444 7F09A914 E5A00224 */  swc1  $f0, 0x224($t5)
/* 0CF448 7F09A918 8C790000 */  lw    $t9, ($v1)
/* 0CF44C 7F09A91C A72003B4 */  sh    $zero, 0x3b4($t9)
/* 0CF450 7F09A920 8C780000 */  lw    $t8, ($v1)
/* 0CF454 7F09A924 A70003B6 */  sh    $zero, 0x3b6($t8)
/* 0CF458 7F09A928 8C6B0000 */  lw    $t3, ($v1)
/* 0CF45C 7F09A92C E56003B8 */  swc1  $f0, 0x3b8($t3)
/* 0CF460 7F09A930 8C6F0000 */  lw    $t7, ($v1)
/* 0CF464 7F09A934 E5E003BC */  swc1  $f0, 0x3bc($t7)
/* 0CF468 7F09A938 8C6E0000 */  lw    $t6, ($v1)
/* 0CF46C 7F09A93C C42A7614 */  lwc1  $f10, %lo(D_80057614)($at)
/* 0CF470 7F09A940 E5CA03C0 */  swc1  $f10, 0x3c0($t6)
/* 0CF474 7F09A944 8C6C0000 */  lw    $t4, ($v1)
/* 0CF478 7F09A948 E58003C4 */  swc1  $f0, 0x3c4($t4)
/* 0CF47C 7F09A94C 8C6D0000 */  lw    $t5, ($v1)
/* 0CF480 7F09A950 E5A003C8 */  swc1  $f0, 0x3c8($t5)
/* 0CF484 7F09A954 8C790000 */  lw    $t9, ($v1)
/* 0CF488 7F09A958 E72203CC */  swc1  $f2, 0x3cc($t9)
/* 0CF48C 7F09A95C 8C780000 */  lw    $t8, ($v1)
/* 0CF490 7F09A960 AF0203D0 */  sw    $v0, 0x3d0($t8)
/* 0CF494 7F09A964 8C6B0000 */  lw    $t3, ($v1)
/* 0CF498 7F09A968 AD6203D4 */  sw    $v0, 0x3d4($t3)
/* 0CF49C 7F09A96C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF4A0 7F09A970 3C018005 */  lui   $at, %hi(D_80057618)
/* 0CF4A4 7F09A974 24070020 */  li    $a3, 32
/* 0CF4A8 7F09A978 ADE203D8 */  sw    $v0, 0x3d8($t7)
/* 0CF4AC 7F09A97C 8C6E0000 */  lw    $t6, ($v1)
/* 0CF4B0 7F09A980 240601FF */  li    $a2, 511
/* 0CF4B4 7F09A984 240501E0 */  li    $a1, 480
/* 0CF4B8 7F09A988 E5C003DC */  swc1  $f0, 0x3dc($t6)
/* 0CF4BC 7F09A98C 8C6C0000 */  lw    $t4, ($v1)
/* 0CF4C0 7F09A990 E58C03E0 */  swc1  $f12, 0x3e0($t4)
/* 0CF4C4 7F09A994 8C6D0000 */  lw    $t5, ($v1)
/* 0CF4C8 7F09A998 E5AC03E4 */  swc1  $f12, 0x3e4($t5)
/* 0CF4CC 7F09A99C 8C790000 */  lw    $t9, ($v1)
/* 0CF4D0 7F09A9A0 AF2203E8 */  sw    $v0, 0x3e8($t9)
/* 0CF4D4 7F09A9A4 8C780000 */  lw    $t8, ($v1)
/* 0CF4D8 7F09A9A8 AF0203EC */  sw    $v0, 0x3ec($t8)
/* 0CF4DC 7F09A9AC 8C6B0000 */  lw    $t3, ($v1)
/* 0CF4E0 7F09A9B0 AD6203F0 */  sw    $v0, 0x3f0($t3)
/* 0CF4E4 7F09A9B4 8C6F0000 */  lw    $t7, ($v1)
/* 0CF4E8 7F09A9B8 ADE203F4 */  sw    $v0, 0x3f4($t7)
/* 0CF4EC 7F09A9BC 8C6E0000 */  lw    $t6, ($v1)
/* 0CF4F0 7F09A9C0 ADC203F8 */  sw    $v0, 0x3f8($t6)
/* 0CF4F4 7F09A9C4 8C6C0000 */  lw    $t4, ($v1)
/* 0CF4F8 7F09A9C8 AD8203FC */  sw    $v0, 0x3fc($t4)
/* 0CF4FC 7F09A9CC 8C6D0000 */  lw    $t5, ($v1)
/* 0CF500 7F09A9D0 00001025 */  move  $v0, $zero
/* 0CF504 7F09A9D4 E5A00400 */  swc1  $f0, 0x400($t5)
/* 0CF508 7F09A9D8 8C790000 */  lw    $t9, ($v1)
/* 0CF50C 7F09A9DC E7200404 */  swc1  $f0, 0x404($t9)
/* 0CF510 7F09A9E0 8C780000 */  lw    $t8, ($v1)
/* 0CF514 7F09A9E4 AF00041C */  sw    $zero, 0x41c($t8)
/* 0CF518 7F09A9E8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF51C 7F09A9EC AD680420 */  sw    $t0, 0x420($t3)
/* 0CF520 7F09A9F0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF524 7F09A9F4 ADE00424 */  sw    $zero, 0x424($t7)
/* 0CF528 7F09A9F8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF52C 7F09A9FC ADC00428 */  sw    $zero, 0x428($t6)
/* 0CF530 7F09AA00 8C6C0000 */  lw    $t4, ($v1)
/* 0CF534 7F09AA04 AD84042C */  sw    $a0, 0x42c($t4)
/* 0CF538 7F09AA08 8C6D0000 */  lw    $t5, ($v1)
/* 0CF53C 7F09AA0C 24040280 */  li    $a0, 640
/* 0CF540 7F09AA10 ADA00430 */  sw    $zero, 0x430($t5)
/* 0CF544 7F09AA14 8C790000 */  lw    $t9, ($v1)
/* 0CF548 7F09AA18 AF2804DC */  sw    $t0, 0x4dc($t9)
/* 0CF54C 7F09AA1C 8C780000 */  lw    $t8, ($v1)
/* 0CF550 7F09AA20 AF0804E0 */  sw    $t0, 0x4e0($t8)
/* 0CF554 7F09AA24 8C6B0000 */  lw    $t3, ($v1)
/* 0CF558 7F09AA28 AD6804E4 */  sw    $t0, 0x4e4($t3)
/* 0CF55C 7F09AA2C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF560 7F09AA30 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 0CF564 7F09AA34 8C6E0000 */  lw    $t6, ($v1)
/* 0CF568 7F09AA38 C4327618 */  lwc1  $f18, %lo(D_80057618)($at)
/* 0CF56C 7F09AA3C 3C018005 */  lui   $at, %hi(D_8005761C)
/* 0CF570 7F09AA40 E5D204EC */  swc1  $f18, 0x4ec($t6)
/* 0CF574 7F09AA44 8C6C0000 */  lw    $t4, ($v1)
/* 0CF578 7F09AA48 AD8004F0 */  sw    $zero, 0x4f0($t4)
/* 0CF57C 7F09AA4C 8C6D0000 */  lw    $t5, ($v1)
/* 0CF580 7F09AA50 E5A204F4 */  swc1  $f2, 0x4f4($t5)
/* 0CF584 7F09AA54 8C790000 */  lw    $t9, ($v1)
/* 0CF588 7F09AA58 E72204F8 */  swc1  $f2, 0x4f8($t9)
/* 0CF58C 7F09AA5C 8C780000 */  lw    $t8, ($v1)
/* 0CF590 7F09AA60 E70004FC */  swc1  $f0, 0x4fc($t8)
/* 0CF594 7F09AA64 8C6B0000 */  lw    $t3, ($v1)
/* 0CF598 7F09AA68 E5600500 */  swc1  $f0, 0x500($t3)
/* 0CF59C 7F09AA6C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF5A0 7F09AA70 E5E00504 */  swc1  $f0, 0x504($t7)
/* 0CF5A4 7F09AA74 8C6E0000 */  lw    $t6, ($v1)
/* 0CF5A8 7F09AA78 C42C761C */  lwc1  $f12, %lo(D_8005761C)($at)
/* 0CF5AC 7F09AA7C E5C00508 */  swc1  $f0, 0x508($t6)
/* 0CF5B0 7F09AA80 8C6C0000 */  lw    $t4, ($v1)
/* 0CF5B4 7F09AA84 E580050C */  swc1  $f0, 0x50c($t4)
/* 0CF5B8 7F09AA88 8C6D0000 */  lw    $t5, ($v1)
/* 0CF5BC 7F09AA8C E5A20510 */  swc1  $f2, 0x510($t5)
/* 0CF5C0 7F09AA90 8C790000 */  lw    $t9, ($v1)
/* 0CF5C4 7F09AA94 E7200514 */  swc1  $f0, 0x514($t9)
/* 0CF5C8 7F09AA98 8C780000 */  lw    $t8, ($v1)
/* 0CF5CC 7F09AA9C E7020518 */  swc1  $f2, 0x518($t8)
/* 0CF5D0 7F09AAA0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF5D4 7F09AAA4 E560051C */  swc1  $f0, 0x51c($t3)
/* 0CF5D8 7F09AAA8 8C6F0000 */  lw    $t7, ($v1)
/* 0CF5DC 7F09AAAC E5E00520 */  swc1  $f0, 0x520($t7)
/* 0CF5E0 7F09AAB0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF5E4 7F09AAB4 E5C00524 */  swc1  $f0, 0x524($t6)
/* 0CF5E8 7F09AAB8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF5EC 7F09AABC E5800528 */  swc1  $f0, 0x528($t4)
/* 0CF5F0 7F09AAC0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF5F4 7F09AAC4 E5A0052C */  swc1  $f0, 0x52c($t5)
/* 0CF5F8 7F09AAC8 8C790000 */  lw    $t9, ($v1)
/* 0CF5FC 7F09AACC E7200530 */  swc1  $f0, 0x530($t9)
/* 0CF600 7F09AAD0 8C780000 */  lw    $t8, ($v1)
/* 0CF604 7F09AAD4 E70C0534 */  swc1  $f12, 0x534($t8)
/* 0CF608 7F09AAD8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF60C 7F09AADC E5600538 */  swc1  $f0, 0x538($t3)
/* 0CF610 7F09AAE0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF614 7F09AAE4 E5EC053C */  swc1  $f12, 0x53c($t7)
/* 0CF618 7F09AAE8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF61C 7F09AAEC E5C00540 */  swc1  $f0, 0x540($t6)
/* 0CF620 7F09AAF0 8C6C0000 */  lw    $t4, ($v1)
/* 0CF624 7F09AAF4 E5800544 */  swc1  $f0, 0x544($t4)
/* 0CF628 7F09AAF8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF62C 7F09AAFC E5A00548 */  swc1  $f0, 0x548($t5)
/* 0CF630 7F09AB00 8C790000 */  lw    $t9, ($v1)
/* 0CF634 7F09AB04 E720054C */  swc1  $f0, 0x54c($t9)
/* 0CF638 7F09AB08 8C780000 */  lw    $t8, ($v1)
/* 0CF63C 7F09AB0C E7000550 */  swc1  $f0, 0x550($t8)
/* 0CF640 7F09AB10 8C6B0000 */  lw    $t3, ($v1)
/* 0CF644 7F09AB14 E5600554 */  swc1  $f0, 0x554($t3)
/* 0CF648 7F09AB18 8C6F0000 */  lw    $t7, ($v1)
/* 0CF64C 7F09AB1C E5E00558 */  swc1  $f0, 0x558($t7)
/* 0CF650 7F09AB20 8C6E0000 */  lw    $t6, ($v1)
/* 0CF654 7F09AB24 E5C0055C */  swc1  $f0, 0x55c($t6)
/* 0CF658 7F09AB28 8C6C0000 */  lw    $t4, ($v1)
/* 0CF65C 7F09AB2C E5800560 */  swc1  $f0, 0x560($t4)
/* 0CF660 7F09AB30 8C6D0000 */  lw    $t5, ($v1)
/* 0CF664 7F09AB34 E5A00564 */  swc1  $f0, 0x564($t5)
/* 0CF668 7F09AB38 8C790000 */  lw    $t9, ($v1)
/* 0CF66C 7F09AB3C E7200568 */  swc1  $f0, 0x568($t9)
/* 0CF670 7F09AB40 8C780000 */  lw    $t8, ($v1)
/* 0CF674 7F09AB44 E702056C */  swc1  $f2, 0x56c($t8)
/* 0CF678 7F09AB48 8C6B0000 */  lw    $t3, ($v1)
/* 0CF67C 7F09AB4C E5600570 */  swc1  $f0, 0x570($t3)
/* 0CF680 7F09AB50 8C6F0000 */  lw    $t7, ($v1)
/* 0CF684 7F09AB54 E5E00574 */  swc1  $f0, 0x574($t7)
/* 0CF688 7F09AB58 8C6E0000 */  lw    $t6, ($v1)
/* 0CF68C 7F09AB5C E5C20578 */  swc1  $f2, 0x578($t6)
/* 0CF690 7F09AB60 8C6C0000 */  lw    $t4, ($v1)
/* 0CF694 7F09AB64 E580057C */  swc1  $f0, 0x57c($t4)
/* 0CF698 7F09AB68 8C6D0000 */  lw    $t5, ($v1)
/* 0CF69C 7F09AB6C E5A20580 */  swc1  $f2, 0x580($t5)
/* 0CF6A0 7F09AB70 8C790000 */  lw    $t9, ($v1)
/* 0CF6A4 7F09AB74 E7200584 */  swc1  $f0, 0x584($t9)
/* 0CF6A8 7F09AB78 8C780000 */  lw    $t8, ($v1)
/* 0CF6AC 7F09AB7C E7000588 */  swc1  $f0, 0x588($t8)
/* 0CF6B0 7F09AB80 8C6B0000 */  lw    $t3, ($v1)
/* 0CF6B4 7F09AB84 E562058C */  swc1  $f2, 0x58c($t3)
/* 0CF6B8 7F09AB88 8C6F0000 */  lw    $t7, ($v1)
/* 0CF6BC 7F09AB8C E5E00590 */  swc1  $f0, 0x590($t7)
/* 0CF6C0 7F09AB90 8C6E0000 */  lw    $t6, ($v1)
/* 0CF6C4 7F09AB94 ADC00594 */  sw    $zero, 0x594($t6)
.L7F09AB98:
/* 0CF6C8 7F09AB98 8C6C0000 */  lw    $t4, ($v1)
/* 0CF6CC 7F09AB9C 01826821 */  addu  $t5, $t4, $v0
/* 0CF6D0 7F09ABA0 A5A407D0 */  sh    $a0, 0x7d0($t5)
/* 0CF6D4 7F09ABA4 8C790000 */  lw    $t9, ($v1)
/* 0CF6D8 7F09ABA8 0322C021 */  addu  $t8, $t9, $v0
/* 0CF6DC 7F09ABAC A70507D2 */  sh    $a1, 0x7d2($t8)
/* 0CF6E0 7F09ABB0 8C6B0000 */  lw    $t3, ($v1)
/* 0CF6E4 7F09ABB4 01627821 */  addu  $t7, $t3, $v0
/* 0CF6E8 7F09ABB8 A5E607D4 */  sh    $a2, 0x7d4($t7)
/* 0CF6EC 7F09ABBC 8C6E0000 */  lw    $t6, ($v1)
/* 0CF6F0 7F09ABC0 01C26021 */  addu  $t4, $t6, $v0
/* 0CF6F4 7F09ABC4 A58007D6 */  sh    $zero, 0x7d6($t4)
/* 0CF6F8 7F09ABC8 8C6D0000 */  lw    $t5, ($v1)
/* 0CF6FC 7F09ABCC 01A2C821 */  addu  $t9, $t5, $v0
/* 0CF700 7F09ABD0 A72407D8 */  sh    $a0, 0x7d8($t9)
/* 0CF704 7F09ABD4 8C780000 */  lw    $t8, ($v1)
/* 0CF708 7F09ABD8 03025821 */  addu  $t3, $t8, $v0
/* 0CF70C 7F09ABDC A56507DA */  sh    $a1, 0x7da($t3)
/* 0CF710 7F09ABE0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF714 7F09ABE4 01E27021 */  addu  $t6, $t7, $v0
/* 0CF718 7F09ABE8 A5C607DC */  sh    $a2, 0x7dc($t6)
/* 0CF71C 7F09ABEC 8C6C0000 */  lw    $t4, ($v1)
/* 0CF720 7F09ABF0 01826821 */  addu  $t5, $t4, $v0
/* 0CF724 7F09ABF4 24420010 */  addiu $v0, $v0, 0x10
/* 0CF728 7F09ABF8 1447FFE7 */  bne   $v0, $a3, .L7F09AB98
/* 0CF72C 7F09ABFC A5A007DE */   sh    $zero, 0x7de($t5)
/* 0CF730 7F09AC00 8C790000 */  lw    $t9, ($v1)
/* 0CF734 7F09AC04 24020064 */  li    $v0, 100
/* 0CF738 7F09AC08 A72207F0 */  sh    $v0, 0x7f0($t9)
/* 0CF73C 7F09AC0C 8C780000 */  lw    $t8, ($v1)
/* 0CF740 7F09AC10 A70207F2 */  sh    $v0, 0x7f2($t8)
/* 0CF744 7F09AC14 8C6B0000 */  lw    $t3, ($v1)
/* 0CF748 7F09AC18 A56007F4 */  sh    $zero, 0x7f4($t3)
/* 0CF74C 7F09AC1C 8C6F0000 */  lw    $t7, ($v1)
/* 0CF750 7F09AC20 A5E007F6 */  sh    $zero, 0x7f6($t7)
/* 0CF754 7F09AC24 8C6E0000 */  lw    $t6, ($v1)
/* 0CF758 7F09AC28 ADC007F8 */  sw    $zero, 0x7f8($t6)
/* 0CF75C 7F09AC2C 8C6C0000 */  lw    $t4, ($v1)
/* 0CF760 7F09AC30 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 0CF764 7F09AC34 8C6D0000 */  lw    $t5, ($v1)
/* 0CF768 7F09AC38 ADA00800 */  sw    $zero, 0x800($t5)
/* 0CF76C 7F09AC3C 8C790000 */  lw    $t9, ($v1)
/* 0CF770 7F09AC40 AF200804 */  sw    $zero, 0x804($t9)
/* 0CF774 7F09AC44 8C780000 */  lw    $t8, ($v1)
/* 0CF778 7F09AC48 AF092A44 */  sw    $t1, 0x2a44($t8)
/* 0CF77C 7F09AC4C 8C6B0000 */  lw    $t3, ($v1)
/* 0CF780 7F09AC50 0140C025 */  move  $t8, $t2
/* 0CF784 7F09AC54 AD692A48 */  sw    $t1, 0x2a48($t3)
/* 0CF788 7F09AC58 8C6F0000 */  lw    $t7, ($v1)
/* 0CF78C 7F09AC5C 254B03A8 */  addiu $t3, $t2, 0x3a8
/* 0CF790 7F09AC60 ADE02A50 */  sw    $zero, 0x2a50($t7)
/* 0CF794 7F09AC64 8C6E0000 */  lw    $t6, ($v1)
/* 0CF798 7F09AC68 01407825 */  move  $t7, $t2
/* 0CF79C 7F09AC6C ADC02A54 */  sw    $zero, 0x2a54($t6)
/* 0CF7A0 7F09AC70 8C6C0000 */  lw    $t4, ($v1)
/* 0CF7A4 7F09AC74 AD800808 */  sw    $zero, 0x808($t4)
/* 0CF7A8 7F09AC78 8C6D0000 */  lw    $t5, ($v1)
/* 0CF7AC 7F09AC7C ADA0080C */  sw    $zero, 0x80c($t5)
/* 0CF7B0 7F09AC80 8C790000 */  lw    $t9, ($v1)
.L7F09AC84:
/* 0CF7B4 7F09AC84 8DE10000 */  lw    $at, ($t7)
/* 0CF7B8 7F09AC88 25EF000C */  addiu $t7, $t7, 0xc
/* 0CF7BC 7F09AC8C 2739000C */  addiu $t9, $t9, 0xc
/* 0CF7C0 7F09AC90 AF210864 */  sw    $at, 0x864($t9)
/* 0CF7C4 7F09AC94 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CF7C8 7F09AC98 AF210868 */  sw    $at, 0x868($t9)
/* 0CF7CC 7F09AC9C 8DE1FFFC */  lw    $at, -4($t7)
/* 0CF7D0 7F09ACA0 15EBFFF8 */  bne   $t7, $t3, .L7F09AC84
/* 0CF7D4 7F09ACA4 AF21086C */   sw    $at, 0x86c($t9)
/* 0CF7D8 7F09ACA8 8C6E0000 */  lw    $t6, ($v1)
/* 0CF7DC 7F09ACAC 254D03A8 */  addiu $t5, $t2, 0x3a8
.L7F09ACB0:
/* 0CF7E0 7F09ACB0 8F010000 */  lw    $at, ($t8)
/* 0CF7E4 7F09ACB4 2718000C */  addiu $t8, $t8, 0xc
/* 0CF7E8 7F09ACB8 25CE000C */  addiu $t6, $t6, 0xc
/* 0CF7EC 7F09ACBC ADC10C0C */  sw    $at, 0xc0c($t6)
/* 0CF7F0 7F09ACC0 8F01FFF8 */  lw    $at, -8($t8)
/* 0CF7F4 7F09ACC4 ADC10C10 */  sw    $at, 0xc10($t6)
/* 0CF7F8 7F09ACC8 8F01FFFC */  lw    $at, -4($t8)
/* 0CF7FC 7F09ACCC 170DFFF8 */  bne   $t8, $t5, .L7F09ACB0
/* 0CF800 7F09ACD0 ADC10C14 */   sw    $at, 0xc14($t6)
/* 0CF804 7F09ACD4 8C6B0000 */  lw    $t3, ($v1)
/* 0CF808 7F09ACD8 3C018005 */  lui   $at, %hi(D_80057620)
/* 0CF80C 7F09ACDC 240200FF */  li    $v0, 255
/* 0CF810 7F09ACE0 E5620FC0 */  swc1  $f2, 0xfc0($t3)
/* 0CF814 7F09ACE4 8C6F0000 */  lw    $t7, ($v1)
/* 0CF818 7F09ACE8 24040007 */  li    $a0, 7
/* 0CF81C 7F09ACEC E5E20FC4 */  swc1  $f2, 0xfc4($t7)
/* 0CF820 7F09ACF0 8C790000 */  lw    $t9, ($v1)
/* 0CF824 7F09ACF4 AF200FC8 */  sw    $zero, 0xfc8($t9)
/* 0CF828 7F09ACF8 8C6C0000 */  lw    $t4, ($v1)
/* 0CF82C 7F09ACFC AD800FCC */  sw    $zero, 0xfcc($t4)
/* 0CF830 7F09AD00 8C6D0000 */  lw    $t5, ($v1)
/* 0CF834 7F09AD04 C42C7620 */  lwc1  $f12, %lo(D_80057620)($at)
/* 0CF838 7F09AD08 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0CF83C 7F09AD0C ADA00FD0 */  sw    $zero, 0xfd0($t5)
/* 0CF840 7F09AD10 8C780000 */  lw    $t8, ($v1)
/* 0CF844 7F09AD14 AF000FD4 */  sw    $zero, 0xfd4($t8)
/* 0CF848 7F09AD18 8C6E0000 */  lw    $t6, ($v1)
/* 0CF84C 7F09AD1C ADC00FD8 */  sw    $zero, 0xfd8($t6)
/* 0CF850 7F09AD20 8C6B0000 */  lw    $t3, ($v1)
/* 0CF854 7F09AD24 A1620FDC */  sb    $v0, 0xfdc($t3)
/* 0CF858 7F09AD28 8C6F0000 */  lw    $t7, ($v1)
/* 0CF85C 7F09AD2C A1E20FDD */  sb    $v0, 0xfdd($t7)
/* 0CF860 7F09AD30 8C790000 */  lw    $t9, ($v1)
/* 0CF864 7F09AD34 A3220FDE */  sb    $v0, 0xfde($t9)
/* 0CF868 7F09AD38 8C6C0000 */  lw    $t4, ($v1)
/* 0CF86C 7F09AD3C 3C028008 */  lui   $v0, %hi(random_byte)
/* 0CF870 7F09AD40 2442A0BC */  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x5f44
/* 0CF874 7F09AD44 A1800FDF */  sb    $zero, 0xfdf($t4)
/* 0CF878 7F09AD48 8C6D0000 */  lw    $t5, ($v1)
/* 0CF87C 7F09AD4C ADA80FE0 */  sw    $t0, 0xfe0($t5)
/* 0CF880 7F09AD50 8C780000 */  lw    $t8, ($v1)
/* 0CF884 7F09AD54 AF000FE4 */  sw    $zero, 0xfe4($t8)
/* 0CF888 7F09AD58 8C6E0000 */  lw    $t6, ($v1)
/* 0CF88C 7F09AD5C E5C00FE8 */  swc1  $f0, 0xfe8($t6)
/* 0CF890 7F09AD60 8C6B0000 */  lw    $t3, ($v1)
/* 0CF894 7F09AD64 E5600FEC */  swc1  $f0, 0xfec($t3)
/* 0CF898 7F09AD68 8C6F0000 */  lw    $t7, ($v1)
/* 0CF89C 7F09AD6C E5E00FF0 */  swc1  $f0, 0xff0($t7)
/* 0CF8A0 7F09AD70 8C790000 */  lw    $t9, ($v1)
/* 0CF8A4 7F09AD74 E7200FF4 */  swc1  $f0, 0xff4($t9)
/* 0CF8A8 7F09AD78 8C6C0000 */  lw    $t4, ($v1)
/* 0CF8AC 7F09AD7C E58C0FF8 */  swc1  $f12, 0xff8($t4)
/* 0CF8B0 7F09AD80 8C6D0000 */  lw    $t5, ($v1)
/* 0CF8B4 7F09AD84 E5A00FFC */  swc1  $f0, 0xffc($t5)
/* 0CF8B8 7F09AD88 8C780000 */  lw    $t8, ($v1)
/* 0CF8BC 7F09AD8C E7001000 */  swc1  $f0, 0x1000($t8)
/* 0CF8C0 7F09AD90 8C6E0000 */  lw    $t6, ($v1)
/* 0CF8C4 7F09AD94 E5C01004 */  swc1  $f0, 0x1004($t6)
/* 0CF8C8 7F09AD98 8C6B0000 */  lw    $t3, ($v1)
/* 0CF8CC 7F09AD9C E5601008 */  swc1  $f0, 0x1008($t3)
/* 0CF8D0 7F09ADA0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF8D4 7F09ADA4 E5EC100C */  swc1  $f12, 0x100c($t7)
/* 0CF8D8 7F09ADA8 44816000 */  mtc1  $at, $f12
/* 0CF8DC 7F09ADAC 8C790000 */  lw    $t9, ($v1)
/* 0CF8E0 7F09ADB0 3C0143A0 */  li    $at, 0x43A00000 # 320.000000
/* 0CF8E4 7F09ADB4 44817000 */  mtc1  $at, $f14
/* 0CF8E8 7F09ADB8 3C014370 */  li    $at, 0x43700000 # 240.000000
/* 0CF8EC 7F09ADBC 44818000 */  mtc1  $at, $f16
/* 0CF8F0 7F09ADC0 E7201010 */  swc1  $f0, 0x1010($t9)
/* 0CF8F4 7F09ADC4 3C018005 */  lui   $at, %hi(D_80057624)
/* 0CF8F8 7F09ADC8 C4247624 */  lwc1  $f4, %lo(D_80057624)($at)
/* 0CF8FC 7F09ADCC 8C6C0000 */  lw    $t4, ($v1)
/* 0CF900 7F09ADD0 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0CF904 7F09ADD4 44813000 */  mtc1  $at, $f6
/* 0CF908 7F09ADD8 E5841014 */  swc1  $f4, 0x1014($t4)
/* 0CF90C 7F09ADDC 8C6D0000 */  lw    $t5, ($v1)
/* 0CF910 7F09ADE0 3C014238 */  li    $at, 0x42380000 # 46.000000
/* 0CF914 7F09ADE4 44814000 */  mtc1  $at, $f8
/* 0CF918 7F09ADE8 E5A01018 */  swc1  $f0, 0x1018($t5)
/* 0CF91C 7F09ADEC 8C780000 */  lw    $t8, ($v1)
/* 0CF920 7F09ADF0 3C014320 */  li    $at, 0x43200000 # 160.000000
/* 0CF924 7F09ADF4 44815000 */  mtc1  $at, $f10
/* 0CF928 7F09ADF8 AF00105C */  sw    $zero, 0x105c($t8)
/* 0CF92C 7F09ADFC 8C6E0000 */  lw    $t6, ($v1)
/* 0CF930 7F09AE00 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0CF934 7F09AE04 44819000 */  mtc1  $at, $f18
/* 0CF938 7F09AE08 ADC01060 */  sw    $zero, 0x1060($t6)
/* 0CF93C 7F09AE0C 8C6B0000 */  lw    $t3, ($v1)
/* 0CF940 7F09AE10 3C018005 */  lui   $at, %hi(D_80057628)
/* 0CF944 7F09AE14 AD601064 */  sw    $zero, 0x1064($t3)
/* 0CF948 7F09AE18 8C6F0000 */  lw    $t7, ($v1)
/* 0CF94C 7F09AE1C E5E0106C */  swc1  $f0, 0x106c($t7)
/* 0CF950 7F09AE20 8C790000 */  lw    $t9, ($v1)
/* 0CF954 7F09AE24 E7201070 */  swc1  $f0, 0x1070($t9)
/* 0CF958 7F09AE28 8C6C0000 */  lw    $t4, ($v1)
/* 0CF95C 7F09AE2C E5801074 */  swc1  $f0, 0x1074($t4)
/* 0CF960 7F09AE30 8C6D0000 */  lw    $t5, ($v1)
/* 0CF964 7F09AE34 ADA01078 */  sw    $zero, 0x1078($t5)
/* 0CF968 7F09AE38 8C780000 */  lw    $t8, ($v1)
/* 0CF96C 7F09AE3C E700107C */  swc1  $f0, 0x107c($t8)
/* 0CF970 7F09AE40 8C6E0000 */  lw    $t6, ($v1)
/* 0CF974 7F09AE44 E5C01080 */  swc1  $f0, 0x1080($t6)
/* 0CF978 7F09AE48 8C6B0000 */  lw    $t3, ($v1)
/* 0CF97C 7F09AE4C E56C1084 */  swc1  $f12, 0x1084($t3)
/* 0CF980 7F09AE50 8C6F0000 */  lw    $t7, ($v1)
/* 0CF984 7F09AE54 E5EC1088 */  swc1  $f12, 0x1088($t7)
/* 0CF988 7F09AE58 8C790000 */  lw    $t9, ($v1)
/* 0CF98C 7F09AE5C AF29108C */  sw    $t1, 0x108c($t9)
/* 0CF990 7F09AE60 8C6C0000 */  lw    $t4, ($v1)
/* 0CF994 7F09AE64 E58E1090 */  swc1  $f14, 0x1090($t4)
/* 0CF998 7F09AE68 8C6D0000 */  lw    $t5, ($v1)
/* 0CF99C 7F09AE6C E5B01094 */  swc1  $f16, 0x1094($t5)
/* 0CF9A0 7F09AE70 8C780000 */  lw    $t8, ($v1)
/* 0CF9A4 7F09AE74 E7001098 */  swc1  $f0, 0x1098($t8)
/* 0CF9A8 7F09AE78 8C6E0000 */  lw    $t6, ($v1)
/* 0CF9AC 7F09AE7C E5C0109C */  swc1  $f0, 0x109c($t6)
/* 0CF9B0 7F09AE80 8C6B0000 */  lw    $t3, ($v1)
/* 0CF9B4 7F09AE84 E56610A0 */  swc1  $f6, 0x10a0($t3)
/* 0CF9B8 7F09AE88 8C6F0000 */  lw    $t7, ($v1)
/* 0CF9BC 7F09AE8C E5E810A4 */  swc1  $f8, 0x10a4($t7)
/* 0CF9C0 7F09AE90 8C790000 */  lw    $t9, ($v1)
/* 0CF9C4 7F09AE94 E72210A8 */  swc1  $f2, 0x10a8($t9)
/* 0CF9C8 7F09AE98 8C6C0000 */  lw    $t4, ($v1)
/* 0CF9CC 7F09AE9C E58A10AC */  swc1  $f10, 0x10ac($t4)
/* 0CF9D0 7F09AEA0 8C6D0000 */  lw    $t5, ($v1)
/* 0CF9D4 7F09AEA4 E5B210B0 */  swc1  $f18, 0x10b0($t5)
/* 0CF9D8 7F09AEA8 8C780000 */  lw    $t8, ($v1)
/* 0CF9DC 7F09AEAC E70210B4 */  swc1  $f2, 0x10b4($t8)
/* 0CF9E0 7F09AEB0 8C6E0000 */  lw    $t6, ($v1)
/* 0CF9E4 7F09AEB4 E5C210B8 */  swc1  $f2, 0x10b8($t6)
/* 0CF9E8 7F09AEB8 8C6B0000 */  lw    $t3, ($v1)
/* 0CF9EC 7F09AEBC E56210BC */  swc1  $f2, 0x10bc($t3)
/* 0CF9F0 7F09AEC0 8C6F0000 */  lw    $t7, ($v1)
/* 0CF9F4 7F09AEC4 E5E210C0 */  swc1  $f2, 0x10c0($t7)
/* 0CF9F8 7F09AEC8 8C790000 */  lw    $t9, ($v1)
/* 0CF9FC 7F09AECC AF2010C4 */  sw    $zero, 0x10c4($t9)
/* 0CFA00 7F09AED0 8C6C0000 */  lw    $t4, ($v1)
/* 0CFA04 7F09AED4 AD8010C8 */  sw    $zero, 0x10c8($t4)
/* 0CFA08 7F09AED8 8C6D0000 */  lw    $t5, ($v1)
/* 0CFA0C 7F09AEDC ADA010CC */  sw    $zero, 0x10cc($t5)
/* 0CFA10 7F09AEE0 8C780000 */  lw    $t8, ($v1)
/* 0CFA14 7F09AEE4 AF0010D0 */  sw    $zero, 0x10d0($t8)
/* 0CFA18 7F09AEE8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFA1C 7F09AEEC ADC010D4 */  sw    $zero, 0x10d4($t6)
/* 0CFA20 7F09AEF0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFA24 7F09AEF4 AD6010D8 */  sw    $zero, 0x10d8($t3)
/* 0CFA28 7F09AEF8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFA2C 7F09AEFC ADE010DC */  sw    $zero, 0x10dc($t7)
/* 0CFA30 7F09AF00 8C790000 */  lw    $t9, ($v1)
/* 0CFA34 7F09AF04 AF2010E0 */  sw    $zero, 0x10e0($t9)
/* 0CFA38 7F09AF08 8C6C0000 */  lw    $t4, ($v1)
/* 0CFA3C 7F09AF0C 3C190001 */  lui   $t9, 1
/* 0CFA40 7F09AF10 AD8010E4 */  sw    $zero, 0x10e4($t4)
/* 0CFA44 7F09AF14 8C6D0000 */  lw    $t5, ($v1)
/* 0CFA48 7F09AF18 ADA010E8 */  sw    $zero, 0x10e8($t5)
/* 0CFA4C 7F09AF1C 8C780000 */  lw    $t8, ($v1)
/* 0CFA50 7F09AF20 AF0010EC */  sw    $zero, 0x10ec($t8)
/* 0CFA54 7F09AF24 8C6E0000 */  lw    $t6, ($v1)
/* 0CFA58 7F09AF28 E5C210F0 */  swc1  $f2, 0x10f0($t6)
/* 0CFA5C 7F09AF2C 8C6B0000 */  lw    $t3, ($v1)
/* 0CFA60 7F09AF30 E56210F4 */  swc1  $f2, 0x10f4($t3)
/* 0CFA64 7F09AF34 8C6F0000 */  lw    $t7, ($v1)
/* 0CFA68 7F09AF38 E5E210F8 */  swc1  $f2, 0x10f8($t7)
/* 0CFA6C 7F09AF3C 8C6C0000 */  lw    $t4, ($v1)
/* 0CFA70 7F09AF40 AD9910FC */  sw    $t9, 0x10fc($t4)
/* 0CFA74 7F09AF44 8C6D0000 */  lw    $t5, ($v1)
/* 0CFA78 7F09AF48 E5A01118 */  swc1  $f0, 0x1118($t5)
/* 0CFA7C 7F09AF4C 8C780000 */  lw    $t8, ($v1)
/* 0CFA80 7F09AF50 E700111C */  swc1  $f0, 0x111c($t8)
/* 0CFA84 7F09AF54 8C6E0000 */  lw    $t6, ($v1)
/* 0CFA88 7F09AF58 E5CE1120 */  swc1  $f14, 0x1120($t6)
/* 0CFA8C 7F09AF5C 8C6B0000 */  lw    $t3, ($v1)
/* 0CFA90 7F09AF60 E5701124 */  swc1  $f16, 0x1124($t3)
/* 0CFA94 7F09AF64 8C6F0000 */  lw    $t7, ($v1)
/* 0CFA98 7F09AF68 ADE01128 */  sw    $zero, 0x1128($t7)
/* 0CFA9C 7F09AF6C 8C790000 */  lw    $t9, ($v1)
/* 0CFAA0 7F09AF70 AF2011B0 */  sw    $zero, 0x11b0($t9)
/* 0CFAA4 7F09AF74 8C6C0000 */  lw    $t4, ($v1)
/* 0CFAA8 7F09AF78 AD8011B4 */  sw    $zero, 0x11b4($t4)
/* 0CFAAC 7F09AF7C 8C6D0000 */  lw    $t5, ($v1)
/* 0CFAB0 7F09AF80 ADA011B8 */  sw    $zero, 0x11b8($t5)
/* 0CFAB4 7F09AF84 8C780000 */  lw    $t8, ($v1)
/* 0CFAB8 7F09AF88 E70011BC */  swc1  $f0, 0x11bc($t8)
/* 0CFABC 7F09AF8C 8C6E0000 */  lw    $t6, ($v1)
/* 0CFAC0 7F09AF90 E5C011C0 */  swc1  $f0, 0x11c0($t6)
/* 0CFAC4 7F09AF94 8C6B0000 */  lw    $t3, ($v1)
/* 0CFAC8 7F09AF98 E56C11C4 */  swc1  $f12, 0x11c4($t3)
/* 0CFACC 7F09AF9C 8C6F0000 */  lw    $t7, ($v1)
/* 0CFAD0 7F09AFA0 E5EC11C8 */  swc1  $f12, 0x11c8($t7)
/* 0CFAD4 7F09AFA4 8C790000 */  lw    $t9, ($v1)
/* 0CFAD8 7F09AFA8 E72C11CC */  swc1  $f12, 0x11cc($t9)
/* 0CFADC 7F09AFAC 8C6C0000 */  lw    $t4, ($v1)
/* 0CFAE0 7F09AFB0 E58C11D0 */  swc1  $f12, 0x11d0($t4)
/* 0CFAE4 7F09AFB4 8C6D0000 */  lw    $t5, ($v1)
/* 0CFAE8 7F09AFB8 C4247628 */  lwc1  $f4, %lo(D_80057628)($at)
/* 0CFAEC 7F09AFBC 3C018003 */  lui   $at, %hi(g_VisibleToGuardsFlag)
/* 0CFAF0 7F09AFC0 E5A411D4 */  swc1  $f4, 0x11d4($t5)
/* 0CFAF4 7F09AFC4 8C780000 */  lw    $t8, ($v1)
/* 0CFAF8 7F09AFC8 AF0011D8 */  sw    $zero, 0x11d8($t8)
/* 0CFAFC 7F09AFCC 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB00 7F09AFD0 ADC911DC */  sw    $t1, 0x11dc($t6)
/* 0CFB04 7F09AFD4 8C6B0000 */  lw    $t3, ($v1)
/* 0CFB08 7F09AFD8 AD6011E0 */  sw    $zero, 0x11e0($t3)
/* 0CFB0C 7F09AFDC 8C6F0000 */  lw    $t7, ($v1)
/* 0CFB10 7F09AFE0 ADE011E4 */  sw    $zero, 0x11e4($t7)
/* 0CFB14 7F09AFE4 8C790000 */  lw    $t9, ($v1)
/* 0CFB18 7F09AFE8 AF2011E8 */  sw    $zero, 0x11e8($t9)
/* 0CFB1C 7F09AFEC 8C6C0000 */  lw    $t4, ($v1)
/* 0CFB20 7F09AFF0 AD8011EC */  sw    $zero, 0x11ec($t4)
/* 0CFB24 7F09AFF4 8C6D0000 */  lw    $t5, ($v1)
/* 0CFB28 7F09AFF8 ADA011F0 */  sw    $zero, 0x11f0($t5)
/* 0CFB2C 7F09AFFC 8C780000 */  lw    $t8, ($v1)
/* 0CFB30 7F09B000 AF0011F4 */  sw    $zero, 0x11f4($t8)
/* 0CFB34 7F09B004 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB38 7F09B008 E5C01280 */  swc1  $f0, 0x1280($t6)
/* 0CFB3C 7F09B00C 8C6B0000 */  lw    $t3, ($v1)
/* 0CFB40 7F09B010 AD601284 */  sw    $zero, 0x1284($t3)
/* 0CFB44 7F09B014 8C6F0000 */  lw    $t7, ($v1)
/* 0CFB48 7F09B018 E5E01288 */  swc1  $f0, 0x1288($t7)
/* 0CFB4C 7F09B01C 8C790000 */  lw    $t9, ($v1)
/* 0CFB50 7F09B020 A32012B6 */  sb    $zero, 0x12b6($t9)
/* 0CFB54 7F09B024 8C6C0000 */  lw    $t4, ($v1)
/* 0CFB58 7F09B028 AD8429B8 */  sw    $a0, 0x29b8($t4)
/* 0CFB5C 7F09B02C 8C6D0000 */  lw    $t5, ($v1)
/* 0CFB60 7F09B030 E5A229BC */  swc1  $f2, 0x29bc($t5)
/* 0CFB64 7F09B034 8C780000 */  lw    $t8, ($v1)
/* 0CFB68 7F09B038 E70029C0 */  swc1  $f0, 0x29c0($t8)
/* 0CFB6C 7F09B03C 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB70 7F09B040 ADC029C4 */  sw    $zero, 0x29c4($t6)
/* 0CFB74 7F09B044 8C6B0000 */  lw    $t3, ($v1)
/* 0CFB78 7F09B048 AD6429D4 */  sw    $a0, 0x29d4($t3)
/* 0CFB7C 7F09B04C 8C6F0000 */  lw    $t7, ($v1)
/* 0CFB80 7F09B050 ADE029D8 */  sw    $zero, 0x29d8($t7)
/* 0CFB84 7F09B054 8C6C0000 */  lw    $t4, ($v1)
/* 0CFB88 7F09B058 8C590000 */  lw    $t9, ($v0)
/* 0CFB8C 7F09B05C AD9929E0 */  sw    $t9, 0x29e0($t4)
/* 0CFB90 7F09B060 8C4D0000 */  lw    $t5, ($v0)
/* 0CFB94 7F09B064 8C6E0000 */  lw    $t6, ($v1)
/* 0CFB98 7F09B068 25B80001 */  addiu $t8, $t5, 1
/* 0CFB9C 7F09B06C AC580000 */  sw    $t8, ($v0)
/* 0CFBA0 7F09B070 ADC929E4 */  sw    $t1, 0x29e4($t6)
/* 0CFBA4 7F09B074 8C6B0000 */  lw    $t3, ($v1)
/* 0CFBA8 7F09B078 AD6929E8 */  sw    $t1, 0x29e8($t3)
/* 0CFBAC 7F09B07C 8C6F0000 */  lw    $t7, ($v1)
/* 0CFBB0 7F09B080 ADE929EC */  sw    $t1, 0x29ec($t7)
/* 0CFBB4 7F09B084 8C790000 */  lw    $t9, ($v1)
/* 0CFBB8 7F09B088 AF2929F0 */  sw    $t1, 0x29f0($t9)
/* 0CFBBC 7F09B08C 8C6C0000 */  lw    $t4, ($v1)
/* 0CFBC0 7F09B090 AD802A00 */  sw    $zero, 0x2a00($t4)
/* 0CFBC4 7F09B094 8C6D0000 */  lw    $t5, ($v1)
/* 0CFBC8 7F09B098 ADA02A30 */  sw    $zero, 0x2a30($t5)
/* 0CFBCC 7F09B09C 8C780000 */  lw    $t8, ($v1)
/* 0CFBD0 7F09B0A0 AF002A34 */  sw    $zero, 0x2a34($t8)
/* 0CFBD4 7F09B0A4 8C6E0000 */  lw    $t6, ($v1)
/* 0CFBD8 7F09B0A8 ADC82A38 */  sw    $t0, 0x2a38($t6)
/* 0CFBDC 7F09B0AC 8C6B0000 */  lw    $t3, ($v1)
/* 0CFBE0 7F09B0B0 E5622A3C */  swc1  $f2, 0x2a3c($t3)
/* 0CFBE4 7F09B0B4 8C6F0000 */  lw    $t7, ($v1)
/* 0CFBE8 7F09B0B8 E5E22A40 */  swc1  $f2, 0x2a40($t7)
/* 0CFBEC 7F09B0BC 8C790000 */  lw    $t9, ($v1)
/* 0CFBF0 7F09B0C0 AF202A58 */  sw    $zero, 0x2a58($t9)
/* 0CFBF4 7F09B0C4 8C6C0000 */  lw    $t4, ($v1)
/* 0CFBF8 7F09B0C8 AD802A5C */  sw    $zero, 0x2a5c($t4)
/* 0CFBFC 7F09B0CC 8C6D0000 */  lw    $t5, ($v1)
/* 0CFC00 7F09B0D0 E5A02A60 */  swc1  $f0, 0x2a60($t5)
/* 0CFC04 7F09B0D4 8C780000 */  lw    $t8, ($v1)
/* 0CFC08 7F09B0D8 AF002A64 */  sw    $zero, 0x2a64($t8)
/* 0CFC0C 7F09B0DC 8C6E0000 */  lw    $t6, ($v1)
/* 0CFC10 7F09B0E0 ADC82A68 */  sw    $t0, 0x2a68($t6)
/* 0CFC14 7F09B0E4 8C6B0000 */  lw    $t3, ($v1)
/* 0CFC18 7F09B0E8 AD602A6C */  sw    $zero, 0x2a6c($t3)
/* 0CFC1C 7F09B0EC 8C6F0000 */  lw    $t7, ($v1)
/* 0CFC20 7F09B0F0 ADE02A70 */  sw    $zero, 0x2a70($t7)
/* 0CFC24 7F09B0F4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CFC28 7F09B0F8 AC2864C4 */  sw    $t0, %lo(g_VisibleToGuardsFlag)($at)
/* 0CFC2C 7F09B0FC 3C018003 */  lui   $at, %hi(obj_collision_flag)
/* 0CFC30 7F09B100 AC2864C8 */  sw    $t0, %lo(obj_collision_flag)($at)
/* 0CFC34 7F09B104 03E00008 */  jr    $ra
/* 0CFC38 7F09B108 27BD03D0 */   addiu $sp, $sp, 0x3d0
)
#endif

#ifdef VERSION_JP
GLOBAL_ASM(
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x411ffffe /*9.9999981*/
glabel D_80057618
.word 0x3f6e147b /*0.93000001*/
glabel D_8005761C
.word 0x4164924b /*14.285716*/
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3faaaaab /*1.3333334*/
.text
glabel initBONDdataforPlayer
/* 0CFBCC 7F09B05C 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 0CFBD0 7F09B060 3C0F8004 */  lui   $t7, %hi(D_8003FD94+0xC) # $t7, 0x8004
/* 0CFBD4 7F09B064 25EFFDD0 */  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x230
/* 0CFBD8 7F09B068 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CFBDC 7F09B06C AFA403D0 */  sw    $a0, 0x3d0($sp)
/* 0CFBE0 7F09B070 25EB03A8 */  addiu $t3, $t7, 0x3a8
/* 0CFBE4 7F09B074 27AE0024 */  addiu $t6, $sp, 0x24
.L7F09B078:
/* 0CFBE8 7F09B078 8DE10000 */  lw    $at, ($t7)
/* 0CFBEC 7F09B07C 25EF000C */  addiu $t7, $t7, 0xc
/* 0CFBF0 7F09B080 25CE000C */  addiu $t6, $t6, 0xc
/* 0CFBF4 7F09B084 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0CFBF8 7F09B088 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CFBFC 7F09B08C ADC1FFF8 */  sw    $at, -8($t6)
/* 0CFC00 7F09B090 8DE1FFFC */  lw    $at, -4($t7)
/* 0CFC04 7F09B094 15EBFFF8 */  bne   $t7, $t3, .L7F09B078
/* 0CFC08 7F09B098 ADC1FFFC */   sw    $at, -4($t6)
/* 0CFC0C 7F09B09C 24042A80 */  li    $a0, 10880
/* 0CFC10 7F09B0A0 0C0025CC */  jal   mempAllocBytesInBank
/* 0CFC14 7F09B0A4 24050004 */   li    $a1, 4
/* 0CFC18 7F09B0A8 8FAC03D0 */  lw    $t4, 0x3d0($sp)
/* 0CFC1C 7F09B0AC 3C198008 */  lui   $t9, %hi(g_playerPointers) # $t9, 0x8008
/* 0CFC20 7F09B0B0 27399F50 */  addiu $t9, %lo(g_playerPointers) # addiu $t9, $t9, -0x60b0
/* 0CFC24 7F09B0B4 000C6880 */  sll   $t5, $t4, 2
/* 0CFC28 7F09B0B8 01B91821 */  addu  $v1, $t5, $t9
/* 0CFC2C 7F09B0BC AC620000 */  sw    $v0, ($v1)
/* 0CFC30 7F09B0C0 AC400000 */  sw    $zero, ($v0)
/* 0CFC34 7F09B0C4 44800000 */  mtc1  $zero, $f0
/* 0CFC38 7F09B0C8 8C780000 */  lw    $t8, ($v1)
/* 0CFC3C 7F09B0CC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CFC40 7F09B0D0 44811000 */  mtc1  $at, $f2
/* 0CFC44 7F09B0D4 E7000004 */  swc1  $f0, 4($t8)
/* 0CFC48 7F09B0D8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFC4C 7F09B0DC 24040002 */  li    $a0, 2
/* 0CFC50 7F09B0E0 24080001 */  li    $t0, 1
/* 0CFC54 7F09B0E4 E5600008 */  swc1  $f0, 8($t3)
/* 0CFC58 7F09B0E8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFC5C 7F09B0EC 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CFC60 7F09B0F0 44816000 */  mtc1  $at, $f12
/* 0CFC64 7F09B0F4 E5E0000C */  swc1  $f0, 0xc($t7)
/* 0CFC68 7F09B0F8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFC6C 7F09B0FC 2409FFFF */  li    $t1, -1
/* 0CFC70 7F09B100 3C01C080 */  li    $at, 0xC0800000 # -4.000000
/* 0CFC74 7F09B104 E5C00010 */  swc1  $f0, 0x10($t6)
/* 0CFC78 7F09B108 8C6C0000 */  lw    $t4, ($v1)
/* 0CFC7C 7F09B10C 44812000 */  mtc1  $at, $f4
/* 0CFC80 7F09B110 3C018005 */  lui   $at, %hi(D_80057610)
/* 0CFC84 7F09B114 E5800014 */  swc1  $f0, 0x14($t4)
/* 0CFC88 7F09B118 8C6D0000 */  lw    $t5, ($v1)
/* 0CFC8C 7F09B11C 240200FF */  li    $v0, 255
/* 0CFC90 7F09B120 27AA0024 */  addiu $t2, $sp, 0x24
/* 0CFC94 7F09B124 E5A20018 */  swc1  $f2, 0x18($t5)
/* 0CFC98 7F09B128 8C790000 */  lw    $t9, ($v1)
/* 0CFC9C 7F09B12C E720001C */  swc1  $f0, 0x1c($t9)
/* 0CFCA0 7F09B130 8C780000 */  lw    $t8, ($v1)
/* 0CFCA4 7F09B134 E7020020 */  swc1  $f2, 0x20($t8)
/* 0CFCA8 7F09B138 8C6B0000 */  lw    $t3, ($v1)
/* 0CFCAC 7F09B13C E5600024 */  swc1  $f0, 0x24($t3)
/* 0CFCB0 7F09B140 8C6F0000 */  lw    $t7, ($v1)
/* 0CFCB4 7F09B144 E5E00028 */  swc1  $f0, 0x28($t7)
/* 0CFCB8 7F09B148 8C6E0000 */  lw    $t6, ($v1)
/* 0CFCBC 7F09B14C E5C0002C */  swc1  $f0, 0x2c($t6)
/* 0CFCC0 7F09B150 8C6C0000 */  lw    $t4, ($v1)
/* 0CFCC4 7F09B154 E5800030 */  swc1  $f0, 0x30($t4)
/* 0CFCC8 7F09B158 8C6D0000 */  lw    $t5, ($v1)
/* 0CFCCC 7F09B15C ADA00034 */  sw    $zero, 0x34($t5)
/* 0CFCD0 7F09B160 8C790000 */  lw    $t9, ($v1)
/* 0CFCD4 7F09B164 E7200038 */  swc1  $f0, 0x38($t9)
/* 0CFCD8 7F09B168 8C780000 */  lw    $t8, ($v1)
/* 0CFCDC 7F09B16C E700003C */  swc1  $f0, 0x3c($t8)
/* 0CFCE0 7F09B170 8C6B0000 */  lw    $t3, ($v1)
/* 0CFCE4 7F09B174 E5600040 */  swc1  $f0, 0x40($t3)
/* 0CFCE8 7F09B178 8C6F0000 */  lw    $t7, ($v1)
/* 0CFCEC 7F09B17C E5E00044 */  swc1  $f0, 0x44($t7)
/* 0CFCF0 7F09B180 8C6E0000 */  lw    $t6, ($v1)
/* 0CFCF4 7F09B184 E5C00048 */  swc1  $f0, 0x48($t6)
/* 0CFCF8 7F09B188 8C6C0000 */  lw    $t4, ($v1)
/* 0CFCFC 7F09B18C E580004C */  swc1  $f0, 0x4c($t4)
/* 0CFD00 7F09B190 8C6D0000 */  lw    $t5, ($v1)
/* 0CFD04 7F09B194 E5A00050 */  swc1  $f0, 0x50($t5)
/* 0CFD08 7F09B198 8C790000 */  lw    $t9, ($v1)
/* 0CFD0C 7F09B19C E7200054 */  swc1  $f0, 0x54($t9)
/* 0CFD10 7F09B1A0 8C780000 */  lw    $t8, ($v1)
/* 0CFD14 7F09B1A4 E7000058 */  swc1  $f0, 0x58($t8)
/* 0CFD18 7F09B1A8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFD1C 7F09B1AC E560006C */  swc1  $f0, 0x6c($t3)
/* 0CFD20 7F09B1B0 8C6F0000 */  lw    $t7, ($v1)
/* 0CFD24 7F09B1B4 E5E00070 */  swc1  $f0, 0x70($t7)
/* 0CFD28 7F09B1B8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFD2C 7F09B1BC E5C00074 */  swc1  $f0, 0x74($t6)
/* 0CFD30 7F09B1C0 8C6C0000 */  lw    $t4, ($v1)
/* 0CFD34 7F09B1C4 E5800078 */  swc1  $f0, 0x78($t4)
/* 0CFD38 7F09B1C8 8C6D0000 */  lw    $t5, ($v1)
/* 0CFD3C 7F09B1CC E5A0007C */  swc1  $f0, 0x7c($t5)
/* 0CFD40 7F09B1D0 8C790000 */  lw    $t9, ($v1)
/* 0CFD44 7F09B1D4 E7200080 */  swc1  $f0, 0x80($t9)
/* 0CFD48 7F09B1D8 8C780000 */  lw    $t8, ($v1)
/* 0CFD4C 7F09B1DC E7000084 */  swc1  $f0, 0x84($t8)
/* 0CFD50 7F09B1E0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFD54 7F09B1E4 E5600088 */  swc1  $f0, 0x88($t3)
/* 0CFD58 7F09B1E8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFD5C 7F09B1EC ADE0008C */  sw    $zero, 0x8c($t7)
/* 0CFD60 7F09B1F0 8C6E0000 */  lw    $t6, ($v1)
/* 0CFD64 7F09B1F4 E5C00090 */  swc1  $f0, 0x90($t6)
/* 0CFD68 7F09B1F8 8C6C0000 */  lw    $t4, ($v1)
/* 0CFD6C 7F09B1FC AD800094 */  sw    $zero, 0x94($t4)
/* 0CFD70 7F09B200 8C6D0000 */  lw    $t5, ($v1)
/* 0CFD74 7F09B204 E5A00098 */  swc1  $f0, 0x98($t5)
/* 0CFD78 7F09B208 8C790000 */  lw    $t9, ($v1)
/* 0CFD7C 7F09B20C E7201274 */  swc1  $f0, 0x1274($t9)
/* 0CFD80 7F09B210 8C780000 */  lw    $t8, ($v1)
/* 0CFD84 7F09B214 E7001278 */  swc1  $f0, 0x1278($t8)
/* 0CFD88 7F09B218 8C6B0000 */  lw    $t3, ($v1)
/* 0CFD8C 7F09B21C E560127C */  swc1  $f0, 0x127c($t3)
/* 0CFD90 7F09B220 8C6F0000 */  lw    $t7, ($v1)
/* 0CFD94 7F09B224 ADE4009C */  sw    $a0, 0x9c($t7)
/* 0CFD98 7F09B228 8C6E0000 */  lw    $t6, ($v1)
/* 0CFD9C 7F09B22C ADC429FC */  sw    $a0, 0x29fc($t6)
/* 0CFDA0 7F09B230 8C6C0000 */  lw    $t4, ($v1)
/* 0CFDA4 7F09B234 E58000A0 */  swc1  $f0, 0xa0($t4)
/* 0CFDA8 7F09B238 8C6D0000 */  lw    $t5, ($v1)
/* 0CFDAC 7F09B23C E5A000A4 */  swc1  $f0, 0xa4($t5)
/* 0CFDB0 7F09B240 8C790000 */  lw    $t9, ($v1)
/* 0CFDB4 7F09B244 AF2000A8 */  sw    $zero, 0xa8($t9)
/* 0CFDB8 7F09B248 8C780000 */  lw    $t8, ($v1)
/* 0CFDBC 7F09B24C AF0800AC */  sw    $t0, 0xac($t8)
/* 0CFDC0 7F09B250 8C6B0000 */  lw    $t3, ($v1)
/* 0CFDC4 7F09B254 AD6000D0 */  sw    $zero, 0xd0($t3)
/* 0CFDC8 7F09B258 8C6F0000 */  lw    $t7, ($v1)
/* 0CFDCC 7F09B25C ADE000D4 */  sw    $zero, 0xd4($t7)
/* 0CFDD0 7F09B260 8C6E0000 */  lw    $t6, ($v1)
/* 0CFDD4 7F09B264 ADC000D8 */  sw    $zero, 0xd8($t6)
/* 0CFDD8 7F09B268 8C6C0000 */  lw    $t4, ($v1)
/* 0CFDDC 7F09B26C E58200DC */  swc1  $f2, 0xdc($t4)
/* 0CFDE0 7F09B270 8C6D0000 */  lw    $t5, ($v1)
/* 0CFDE4 7F09B274 E5A000E0 */  swc1  $f0, 0xe0($t5)
/* 0CFDE8 7F09B278 8C790000 */  lw    $t9, ($v1)
/* 0CFDEC 7F09B27C E72200E4 */  swc1  $f2, 0xe4($t9)
/* 0CFDF0 7F09B280 8C780000 */  lw    $t8, ($v1)
/* 0CFDF4 7F09B284 E70000E8 */  swc1  $f0, 0xe8($t8)
/* 0CFDF8 7F09B288 8C6B0000 */  lw    $t3, ($v1)
/* 0CFDFC 7F09B28C E56200EC */  swc1  $f2, 0xec($t3)
/* 0CFE00 7F09B290 8C6F0000 */  lw    $t7, ($v1)
/* 0CFE04 7F09B294 E5E000F0 */  swc1  $f0, 0xf0($t7)
/* 0CFE08 7F09B298 8C6E0000 */  lw    $t6, ($v1)
/* 0CFE0C 7F09B29C E5CC00F4 */  swc1  $f12, 0xf4($t6)
/* 0CFE10 7F09B2A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CFE14 7F09B2A4 E58C00F8 */  swc1  $f12, 0xf8($t4)
/* 0CFE18 7F09B2A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CFE1C 7F09B2AC ADA00104 */  sw    $zero, 0x104($t5)
/* 0CFE20 7F09B2B0 8C790000 */  lw    $t9, ($v1)
/* 0CFE24 7F09B2B4 AF200108 */  sw    $zero, 0x108($t9)
/* 0CFE28 7F09B2B8 8C780000 */  lw    $t8, ($v1)
/* 0CFE2C 7F09B2BC AF00010C */  sw    $zero, 0x10c($t8)
/* 0CFE30 7F09B2C0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFE34 7F09B2C4 AD600110 */  sw    $zero, 0x110($t3)
/* 0CFE38 7F09B2C8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFE3C 7F09B2CC ADE80114 */  sw    $t0, 0x114($t7)
/* 0CFE40 7F09B2D0 8C6E0000 */  lw    $t6, ($v1)
/* 0CFE44 7F09B2D4 ADC80118 */  sw    $t0, 0x118($t6)
/* 0CFE48 7F09B2D8 8C6C0000 */  lw    $t4, ($v1)
/* 0CFE4C 7F09B2DC AD80011C */  sw    $zero, 0x11c($t4)
/* 0CFE50 7F09B2E0 8C6D0000 */  lw    $t5, ($v1)
/* 0CFE54 7F09B2E4 ADA80120 */  sw    $t0, 0x120($t5)
/* 0CFE58 7F09B2E8 8C790000 */  lw    $t9, ($v1)
/* 0CFE5C 7F09B2EC AF200124 */  sw    $zero, 0x124($t9)
/* 0CFE60 7F09B2F0 8C780000 */  lw    $t8, ($v1)
/* 0CFE64 7F09B2F4 AF080128 */  sw    $t0, 0x128($t8)
/* 0CFE68 7F09B2F8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFE6C 7F09B2FC E560012C */  swc1  $f0, 0x12c($t3)
/* 0CFE70 7F09B300 8C6F0000 */  lw    $t7, ($v1)
/* 0CFE74 7F09B304 ADE00130 */  sw    $zero, 0x130($t7)
/* 0CFE78 7F09B308 8C6E0000 */  lw    $t6, ($v1)
/* 0CFE7C 7F09B30C ADC90134 */  sw    $t1, 0x134($t6)
/* 0CFE80 7F09B310 8C6C0000 */  lw    $t4, ($v1)
/* 0CFE84 7F09B314 AD880138 */  sw    $t0, 0x138($t4)
/* 0CFE88 7F09B318 8C6D0000 */  lw    $t5, ($v1)
/* 0CFE8C 7F09B31C E5A0013C */  swc1  $f0, 0x13c($t5)
/* 0CFE90 7F09B320 8C790000 */  lw    $t9, ($v1)
/* 0CFE94 7F09B324 AF200140 */  sw    $zero, 0x140($t9)
/* 0CFE98 7F09B328 8C780000 */  lw    $t8, ($v1)
/* 0CFE9C 7F09B32C AF090144 */  sw    $t1, 0x144($t8)
/* 0CFEA0 7F09B330 8C6B0000 */  lw    $t3, ($v1)
/* 0CFEA4 7F09B334 E5600148 */  swc1  $f0, 0x148($t3)
/* 0CFEA8 7F09B338 8C6F0000 */  lw    $t7, ($v1)
/* 0CFEAC 7F09B33C E5E0014C */  swc1  $f0, 0x14c($t7)
/* 0CFEB0 7F09B340 8C6E0000 */  lw    $t6, ($v1)
/* 0CFEB4 7F09B344 E5C20150 */  swc1  $f2, 0x150($t6)
/* 0CFEB8 7F09B348 8C6C0000 */  lw    $t4, ($v1)
/* 0CFEBC 7F09B34C E5800154 */  swc1  $f0, 0x154($t4)
/* 0CFEC0 7F09B350 8C6D0000 */  lw    $t5, ($v1)
/* 0CFEC4 7F09B354 E5A40158 */  swc1  $f4, 0x158($t5)
/* 0CFEC8 7F09B358 8C790000 */  lw    $t9, ($v1)
/* 0CFECC 7F09B35C C4267640 */  lwc1  $f6, %lo(D_80057610)($at)
/* 0CFED0 7F09B360 3C01C1C8 */  li    $at, 0xC1C80000 # -25.000000
/* 0CFED4 7F09B364 44814000 */  mtc1  $at, $f8
/* 0CFED8 7F09B368 E726015C */  swc1  $f6, 0x15c($t9)
/* 0CFEDC 7F09B36C 8C780000 */  lw    $t8, ($v1)
/* 0CFEE0 7F09B370 3C018005 */  lui   $at, %hi(D_80057614) # $at, 0x8005
/* 0CFEE4 7F09B374 E7000160 */  swc1  $f0, 0x160($t8)
/* 0CFEE8 7F09B378 8C6B0000 */  lw    $t3, ($v1)
/* 0CFEEC 7F09B37C E5620164 */  swc1  $f2, 0x164($t3)
/* 0CFEF0 7F09B380 8C6F0000 */  lw    $t7, ($v1)
/* 0CFEF4 7F09B384 E5E00168 */  swc1  $f0, 0x168($t7)
/* 0CFEF8 7F09B388 8C6E0000 */  lw    $t6, ($v1)
/* 0CFEFC 7F09B38C E5C0016C */  swc1  $f0, 0x16c($t6)
/* 0CFF00 7F09B390 8C6C0000 */  lw    $t4, ($v1)
/* 0CFF04 7F09B394 E5800170 */  swc1  $f0, 0x170($t4)
/* 0CFF08 7F09B398 8C6D0000 */  lw    $t5, ($v1)
/* 0CFF0C 7F09B39C E5A00174 */  swc1  $f0, 0x174($t5)
/* 0CFF10 7F09B3A0 8C790000 */  lw    $t9, ($v1)
/* 0CFF14 7F09B3A4 E7202A4C */  swc1  $f0, 0x2a4c($t9)
/* 0CFF18 7F09B3A8 8C780000 */  lw    $t8, ($v1)
/* 0CFF1C 7F09B3AC E7020178 */  swc1  $f2, 0x178($t8)
/* 0CFF20 7F09B3B0 8C6B0000 */  lw    $t3, ($v1)
/* 0CFF24 7F09B3B4 E5600180 */  swc1  $f0, 0x180($t3)
/* 0CFF28 7F09B3B8 8C6F0000 */  lw    $t7, ($v1)
/* 0CFF2C 7F09B3BC E5E00184 */  swc1  $f0, 0x184($t7)
/* 0CFF30 7F09B3C0 8C6E0000 */  lw    $t6, ($v1)
/* 0CFF34 7F09B3C4 E5C00188 */  swc1  $f0, 0x188($t6)
/* 0CFF38 7F09B3C8 8C6C0000 */  lw    $t4, ($v1)
/* 0CFF3C 7F09B3CC E58C018C */  swc1  $f12, 0x18c($t4)
/* 0CFF40 7F09B3D0 8C6D0000 */  lw    $t5, ($v1)
/* 0CFF44 7F09B3D4 E5AC0190 */  swc1  $f12, 0x190($t5)
/* 0CFF48 7F09B3D8 8C790000 */  lw    $t9, ($v1)
/* 0CFF4C 7F09B3DC E7200194 */  swc1  $f0, 0x194($t9)
/* 0CFF50 7F09B3E0 8C780000 */  lw    $t8, ($v1)
/* 0CFF54 7F09B3E4 E7000198 */  swc1  $f0, 0x198($t8)
/* 0CFF58 7F09B3E8 8C6B0000 */  lw    $t3, ($v1)
/* 0CFF5C 7F09B3EC E560019C */  swc1  $f0, 0x19c($t3)
/* 0CFF60 7F09B3F0 8C6F0000 */  lw    $t7, ($v1)
/* 0CFF64 7F09B3F4 ADE001A0 */  sw    $zero, 0x1a0($t7)
/* 0CFF68 7F09B3F8 8C6E0000 */  lw    $t6, ($v1)
/* 0CFF6C 7F09B3FC ADC001C0 */  sw    $zero, 0x1c0($t6)
/* 0CFF70 7F09B400 8C6C0000 */  lw    $t4, ($v1)
/* 0CFF74 7F09B404 AD8001C4 */  sw    $zero, 0x1c4($t4)
/* 0CFF78 7F09B408 8C6D0000 */  lw    $t5, ($v1)
/* 0CFF7C 7F09B40C ADA001C8 */  sw    $zero, 0x1c8($t5)
/* 0CFF80 7F09B410 8C790000 */  lw    $t9, ($v1)
/* 0CFF84 7F09B414 AF2801CC */  sw    $t0, 0x1cc($t9)
/* 0CFF88 7F09B418 8C780000 */  lw    $t8, ($v1)
/* 0CFF8C 7F09B41C AF0001D0 */  sw    $zero, 0x1d0($t8)
/* 0CFF90 7F09B420 8C6B0000 */  lw    $t3, ($v1)
/* 0CFF94 7F09B424 E56001D4 */  swc1  $f0, 0x1d4($t3)
/* 0CFF98 7F09B428 8C6F0000 */  lw    $t7, ($v1)
/* 0CFF9C 7F09B42C E5E001D8 */  swc1  $f0, 0x1d8($t7)
/* 0CFFA0 7F09B430 8C6E0000 */  lw    $t6, ($v1)
/* 0CFFA4 7F09B434 E5C801DC */  swc1  $f8, 0x1dc($t6)
/* 0CFFA8 7F09B438 8C6C0000 */  lw    $t4, ($v1)
/* 0CFFAC 7F09B43C E58001E0 */  swc1  $f0, 0x1e0($t4)
/* 0CFFB0 7F09B440 8C6D0000 */  lw    $t5, ($v1)
/* 0CFFB4 7F09B444 E5A201E4 */  swc1  $f2, 0x1e4($t5)
/* 0CFFB8 7F09B448 8C790000 */  lw    $t9, ($v1)
/* 0CFFBC 7F09B44C E72001E8 */  swc1  $f0, 0x1e8($t9)
/* 0CFFC0 7F09B450 8C780000 */  lw    $t8, ($v1)
/* 0CFFC4 7F09B454 E70001EC */  swc1  $f0, 0x1ec($t8)
/* 0CFFC8 7F09B458 8C6B0000 */  lw    $t3, ($v1)
/* 0CFFCC 7F09B45C E56001F0 */  swc1  $f0, 0x1f0($t3)
/* 0CFFD0 7F09B460 8C6F0000 */  lw    $t7, ($v1)
/* 0CFFD4 7F09B464 E5E201F4 */  swc1  $f2, 0x1f4($t7)
/* 0CFFD8 7F09B468 8C6E0000 */  lw    $t6, ($v1)
/* 0CFFDC 7F09B46C ADC00200 */  sw    $zero, 0x200($t6)
/* 0CFFE0 7F09B470 8C6C0000 */  lw    $t4, ($v1)
/* 0CFFE4 7F09B474 E5800204 */  swc1  $f0, 0x204($t4)
/* 0CFFE8 7F09B478 8C6D0000 */  lw    $t5, ($v1)
/* 0CFFEC 7F09B47C E5A00208 */  swc1  $f0, 0x208($t5)
/* 0CFFF0 7F09B480 8C790000 */  lw    $t9, ($v1)
/* 0CFFF4 7F09B484 E720020C */  swc1  $f0, 0x20c($t9)
/* 0CFFF8 7F09B488 8C780000 */  lw    $t8, ($v1)
/* 0CFFFC 7F09B48C E7000210 */  swc1  $f0, 0x210($t8)
/* 0D0000 7F09B490 8C6B0000 */  lw    $t3, ($v1)
/* 0D0004 7F09B494 E5600214 */  swc1  $f0, 0x214($t3)
/* 0D0008 7F09B498 8C6F0000 */  lw    $t7, ($v1)
/* 0D000C 7F09B49C ADE00218 */  sw    $zero, 0x218($t7)
/* 0D0010 7F09B4A0 8C6E0000 */  lw    $t6, ($v1)
/* 0D0014 7F09B4A4 ADC8021C */  sw    $t0, 0x21c($t6)
/* 0D0018 7F09B4A8 8C6C0000 */  lw    $t4, ($v1)
/* 0D001C 7F09B4AC AD800220 */  sw    $zero, 0x220($t4)
/* 0D0020 7F09B4B0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0024 7F09B4B4 E5A00224 */  swc1  $f0, 0x224($t5)
/* 0D0028 7F09B4B8 8C790000 */  lw    $t9, ($v1)
/* 0D002C 7F09B4BC A72003B4 */  sh    $zero, 0x3b4($t9)
/* 0D0030 7F09B4C0 8C780000 */  lw    $t8, ($v1)
/* 0D0034 7F09B4C4 A70003B6 */  sh    $zero, 0x3b6($t8)
/* 0D0038 7F09B4C8 8C6B0000 */  lw    $t3, ($v1)
/* 0D003C 7F09B4CC E56003B8 */  swc1  $f0, 0x3b8($t3)
/* 0D0040 7F09B4D0 8C6F0000 */  lw    $t7, ($v1)
/* 0D0044 7F09B4D4 E5E003BC */  swc1  $f0, 0x3bc($t7)
/* 0D0048 7F09B4D8 8C6E0000 */  lw    $t6, ($v1)
/* 0D004C 7F09B4DC C42A7644 */  lwc1  $f10, %lo(D_80057614)($at)
/* 0D0050 7F09B4E0 E5CA03C0 */  swc1  $f10, 0x3c0($t6)
/* 0D0054 7F09B4E4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0058 7F09B4E8 E58003C4 */  swc1  $f0, 0x3c4($t4)
/* 0D005C 7F09B4EC 8C6D0000 */  lw    $t5, ($v1)
/* 0D0060 7F09B4F0 E5A003C8 */  swc1  $f0, 0x3c8($t5)
/* 0D0064 7F09B4F4 8C790000 */  lw    $t9, ($v1)
/* 0D0068 7F09B4F8 E72203CC */  swc1  $f2, 0x3cc($t9)
/* 0D006C 7F09B4FC 8C780000 */  lw    $t8, ($v1)
/* 0D0070 7F09B500 AF0203D0 */  sw    $v0, 0x3d0($t8)
/* 0D0074 7F09B504 8C6B0000 */  lw    $t3, ($v1)
/* 0D0078 7F09B508 AD6203D4 */  sw    $v0, 0x3d4($t3)
/* 0D007C 7F09B50C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0080 7F09B510 3C018005 */  lui   $at, %hi(D_80057618) # $at, 0x8005
/* 0D0084 7F09B514 24070020 */  li    $a3, 32
/* 0D0088 7F09B518 ADE203D8 */  sw    $v0, 0x3d8($t7)
/* 0D008C 7F09B51C 8C6E0000 */  lw    $t6, ($v1)
/* 0D0090 7F09B520 240601FF */  li    $a2, 511
/* 0D0094 7F09B524 240501E0 */  li    $a1, 480
/* 0D0098 7F09B528 E5C003DC */  swc1  $f0, 0x3dc($t6)
/* 0D009C 7F09B52C 8C6C0000 */  lw    $t4, ($v1)
/* 0D00A0 7F09B530 E58C03E0 */  swc1  $f12, 0x3e0($t4)
/* 0D00A4 7F09B534 8C6D0000 */  lw    $t5, ($v1)
/* 0D00A8 7F09B538 E5AC03E4 */  swc1  $f12, 0x3e4($t5)
/* 0D00AC 7F09B53C 8C790000 */  lw    $t9, ($v1)
/* 0D00B0 7F09B540 AF2203E8 */  sw    $v0, 0x3e8($t9)
/* 0D00B4 7F09B544 8C780000 */  lw    $t8, ($v1)
/* 0D00B8 7F09B548 AF0203EC */  sw    $v0, 0x3ec($t8)
/* 0D00BC 7F09B54C 8C6B0000 */  lw    $t3, ($v1)
/* 0D00C0 7F09B550 AD6203F0 */  sw    $v0, 0x3f0($t3)
/* 0D00C4 7F09B554 8C6F0000 */  lw    $t7, ($v1)
/* 0D00C8 7F09B558 ADE203F4 */  sw    $v0, 0x3f4($t7)
/* 0D00CC 7F09B55C 8C6E0000 */  lw    $t6, ($v1)
/* 0D00D0 7F09B560 ADC203F8 */  sw    $v0, 0x3f8($t6)
/* 0D00D4 7F09B564 8C6C0000 */  lw    $t4, ($v1)
/* 0D00D8 7F09B568 AD8203FC */  sw    $v0, 0x3fc($t4)
/* 0D00DC 7F09B56C 8C6D0000 */  lw    $t5, ($v1)
/* 0D00E0 7F09B570 00001025 */  move  $v0, $zero
/* 0D00E4 7F09B574 E5A00400 */  swc1  $f0, 0x400($t5)
/* 0D00E8 7F09B578 8C790000 */  lw    $t9, ($v1)
/* 0D00EC 7F09B57C E7200404 */  swc1  $f0, 0x404($t9)
/* 0D00F0 7F09B580 8C780000 */  lw    $t8, ($v1)
/* 0D00F4 7F09B584 AF00041C */  sw    $zero, 0x41c($t8)
/* 0D00F8 7F09B588 8C6B0000 */  lw    $t3, ($v1)
/* 0D00FC 7F09B58C AD680420 */  sw    $t0, 0x420($t3)
/* 0D0100 7F09B590 8C6F0000 */  lw    $t7, ($v1)
/* 0D0104 7F09B594 ADE00424 */  sw    $zero, 0x424($t7)
/* 0D0108 7F09B598 8C6E0000 */  lw    $t6, ($v1)
/* 0D010C 7F09B59C ADC00428 */  sw    $zero, 0x428($t6)
/* 0D0110 7F09B5A0 8C6C0000 */  lw    $t4, ($v1)
/* 0D0114 7F09B5A4 AD84042C */  sw    $a0, 0x42c($t4)
/* 0D0118 7F09B5A8 8C6D0000 */  lw    $t5, ($v1)
/* 0D011C 7F09B5AC 24040280 */  li    $a0, 640
/* 0D0120 7F09B5B0 ADA00430 */  sw    $zero, 0x430($t5)
/* 0D0124 7F09B5B4 8C790000 */  lw    $t9, ($v1)
/* 0D0128 7F09B5B8 AF2804DC */  sw    $t0, 0x4dc($t9)
/* 0D012C 7F09B5BC 8C780000 */  lw    $t8, ($v1)
/* 0D0130 7F09B5C0 AF0804E0 */  sw    $t0, 0x4e0($t8)
/* 0D0134 7F09B5C4 8C6B0000 */  lw    $t3, ($v1)
/* 0D0138 7F09B5C8 AD6804E4 */  sw    $t0, 0x4e4($t3)
/* 0D013C 7F09B5CC 8C6F0000 */  lw    $t7, ($v1)
/* 0D0140 7F09B5D0 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 0D0144 7F09B5D4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0148 7F09B5D8 C4327648 */  lwc1  $f18, %lo(D_80057618)($at)
/* 0D014C 7F09B5DC 3C018005 */  lui   $at, %hi(D_8005761C) # $at, 0x8005
/* 0D0150 7F09B5E0 E5D204EC */  swc1  $f18, 0x4ec($t6)
/* 0D0154 7F09B5E4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0158 7F09B5E8 AD8004F0 */  sw    $zero, 0x4f0($t4)
/* 0D015C 7F09B5EC 8C6D0000 */  lw    $t5, ($v1)
/* 0D0160 7F09B5F0 E5A204F4 */  swc1  $f2, 0x4f4($t5)
/* 0D0164 7F09B5F4 8C790000 */  lw    $t9, ($v1)
/* 0D0168 7F09B5F8 E72204F8 */  swc1  $f2, 0x4f8($t9)
/* 0D016C 7F09B5FC 8C780000 */  lw    $t8, ($v1)
/* 0D0170 7F09B600 E70004FC */  swc1  $f0, 0x4fc($t8)
/* 0D0174 7F09B604 8C6B0000 */  lw    $t3, ($v1)
/* 0D0178 7F09B608 E5600500 */  swc1  $f0, 0x500($t3)
/* 0D017C 7F09B60C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0180 7F09B610 E5E00504 */  swc1  $f0, 0x504($t7)
/* 0D0184 7F09B614 8C6E0000 */  lw    $t6, ($v1)
/* 0D0188 7F09B618 C42C764C */  lwc1  $f12, %lo(D_8005761C)($at)
/* 0D018C 7F09B61C E5C00508 */  swc1  $f0, 0x508($t6)
/* 0D0190 7F09B620 8C6C0000 */  lw    $t4, ($v1)
/* 0D0194 7F09B624 E580050C */  swc1  $f0, 0x50c($t4)
/* 0D0198 7F09B628 8C6D0000 */  lw    $t5, ($v1)
/* 0D019C 7F09B62C E5A20510 */  swc1  $f2, 0x510($t5)
/* 0D01A0 7F09B630 8C790000 */  lw    $t9, ($v1)
/* 0D01A4 7F09B634 E7200514 */  swc1  $f0, 0x514($t9)
/* 0D01A8 7F09B638 8C780000 */  lw    $t8, ($v1)
/* 0D01AC 7F09B63C E7020518 */  swc1  $f2, 0x518($t8)
/* 0D01B0 7F09B640 8C6B0000 */  lw    $t3, ($v1)
/* 0D01B4 7F09B644 E560051C */  swc1  $f0, 0x51c($t3)
/* 0D01B8 7F09B648 8C6F0000 */  lw    $t7, ($v1)
/* 0D01BC 7F09B64C E5E00520 */  swc1  $f0, 0x520($t7)
/* 0D01C0 7F09B650 8C6E0000 */  lw    $t6, ($v1)
/* 0D01C4 7F09B654 E5C00524 */  swc1  $f0, 0x524($t6)
/* 0D01C8 7F09B658 8C6C0000 */  lw    $t4, ($v1)
/* 0D01CC 7F09B65C E5800528 */  swc1  $f0, 0x528($t4)
/* 0D01D0 7F09B660 8C6D0000 */  lw    $t5, ($v1)
/* 0D01D4 7F09B664 E5A0052C */  swc1  $f0, 0x52c($t5)
/* 0D01D8 7F09B668 8C790000 */  lw    $t9, ($v1)
/* 0D01DC 7F09B66C E7200530 */  swc1  $f0, 0x530($t9)
/* 0D01E0 7F09B670 8C780000 */  lw    $t8, ($v1)
/* 0D01E4 7F09B674 E70C0534 */  swc1  $f12, 0x534($t8)
/* 0D01E8 7F09B678 8C6B0000 */  lw    $t3, ($v1)
/* 0D01EC 7F09B67C E5600538 */  swc1  $f0, 0x538($t3)
/* 0D01F0 7F09B680 8C6F0000 */  lw    $t7, ($v1)
/* 0D01F4 7F09B684 E5EC053C */  swc1  $f12, 0x53c($t7)
/* 0D01F8 7F09B688 8C6E0000 */  lw    $t6, ($v1)
/* 0D01FC 7F09B68C E5C00540 */  swc1  $f0, 0x540($t6)
/* 0D0200 7F09B690 8C6C0000 */  lw    $t4, ($v1)
/* 0D0204 7F09B694 E5800544 */  swc1  $f0, 0x544($t4)
/* 0D0208 7F09B698 8C6D0000 */  lw    $t5, ($v1)
/* 0D020C 7F09B69C E5A00548 */  swc1  $f0, 0x548($t5)
/* 0D0210 7F09B6A0 8C790000 */  lw    $t9, ($v1)
/* 0D0214 7F09B6A4 E720054C */  swc1  $f0, 0x54c($t9)
/* 0D0218 7F09B6A8 8C780000 */  lw    $t8, ($v1)
/* 0D021C 7F09B6AC E7000550 */  swc1  $f0, 0x550($t8)
/* 0D0220 7F09B6B0 8C6B0000 */  lw    $t3, ($v1)
/* 0D0224 7F09B6B4 E5600554 */  swc1  $f0, 0x554($t3)
/* 0D0228 7F09B6B8 8C6F0000 */  lw    $t7, ($v1)
/* 0D022C 7F09B6BC E5E00558 */  swc1  $f0, 0x558($t7)
/* 0D0230 7F09B6C0 8C6E0000 */  lw    $t6, ($v1)
/* 0D0234 7F09B6C4 E5C0055C */  swc1  $f0, 0x55c($t6)
/* 0D0238 7F09B6C8 8C6C0000 */  lw    $t4, ($v1)
/* 0D023C 7F09B6CC E5800560 */  swc1  $f0, 0x560($t4)
/* 0D0240 7F09B6D0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0244 7F09B6D4 E5A00564 */  swc1  $f0, 0x564($t5)
/* 0D0248 7F09B6D8 8C790000 */  lw    $t9, ($v1)
/* 0D024C 7F09B6DC E7200568 */  swc1  $f0, 0x568($t9)
/* 0D0250 7F09B6E0 8C780000 */  lw    $t8, ($v1)
/* 0D0254 7F09B6E4 E702056C */  swc1  $f2, 0x56c($t8)
/* 0D0258 7F09B6E8 8C6B0000 */  lw    $t3, ($v1)
/* 0D025C 7F09B6EC E5600570 */  swc1  $f0, 0x570($t3)
/* 0D0260 7F09B6F0 8C6F0000 */  lw    $t7, ($v1)
/* 0D0264 7F09B6F4 E5E00574 */  swc1  $f0, 0x574($t7)
/* 0D0268 7F09B6F8 8C6E0000 */  lw    $t6, ($v1)
/* 0D026C 7F09B6FC E5C20578 */  swc1  $f2, 0x578($t6)
/* 0D0270 7F09B700 8C6C0000 */  lw    $t4, ($v1)
/* 0D0274 7F09B704 E580057C */  swc1  $f0, 0x57c($t4)
/* 0D0278 7F09B708 8C6D0000 */  lw    $t5, ($v1)
/* 0D027C 7F09B70C E5A20580 */  swc1  $f2, 0x580($t5)
/* 0D0280 7F09B710 8C790000 */  lw    $t9, ($v1)
/* 0D0284 7F09B714 E7200584 */  swc1  $f0, 0x584($t9)
/* 0D0288 7F09B718 8C780000 */  lw    $t8, ($v1)
/* 0D028C 7F09B71C E7000588 */  swc1  $f0, 0x588($t8)
/* 0D0290 7F09B720 8C6B0000 */  lw    $t3, ($v1)
/* 0D0294 7F09B724 E562058C */  swc1  $f2, 0x58c($t3)
/* 0D0298 7F09B728 8C6F0000 */  lw    $t7, ($v1)
/* 0D029C 7F09B72C E5E00590 */  swc1  $f0, 0x590($t7)
/* 0D02A0 7F09B730 8C6E0000 */  lw    $t6, ($v1)
/* 0D02A4 7F09B734 ADC00594 */  sw    $zero, 0x594($t6)
.L7F09B738:
/* 0D02A8 7F09B738 8C6C0000 */  lw    $t4, ($v1)
/* 0D02AC 7F09B73C 01826821 */  addu  $t5, $t4, $v0
/* 0D02B0 7F09B740 A5A407D0 */  sh    $a0, 0x7d0($t5)
/* 0D02B4 7F09B744 8C790000 */  lw    $t9, ($v1)
/* 0D02B8 7F09B748 0322C021 */  addu  $t8, $t9, $v0
/* 0D02BC 7F09B74C A70507D2 */  sh    $a1, 0x7d2($t8)
/* 0D02C0 7F09B750 8C6B0000 */  lw    $t3, ($v1)
/* 0D02C4 7F09B754 01627821 */  addu  $t7, $t3, $v0
/* 0D02C8 7F09B758 A5E607D4 */  sh    $a2, 0x7d4($t7)
/* 0D02CC 7F09B75C 8C6E0000 */  lw    $t6, ($v1)
/* 0D02D0 7F09B760 01C26021 */  addu  $t4, $t6, $v0
/* 0D02D4 7F09B764 A58007D6 */  sh    $zero, 0x7d6($t4)
/* 0D02D8 7F09B768 8C6D0000 */  lw    $t5, ($v1)
/* 0D02DC 7F09B76C 01A2C821 */  addu  $t9, $t5, $v0
/* 0D02E0 7F09B770 A72407D8 */  sh    $a0, 0x7d8($t9)
/* 0D02E4 7F09B774 8C780000 */  lw    $t8, ($v1)
/* 0D02E8 7F09B778 03025821 */  addu  $t3, $t8, $v0
/* 0D02EC 7F09B77C A56507DA */  sh    $a1, 0x7da($t3)
/* 0D02F0 7F09B780 8C6F0000 */  lw    $t7, ($v1)
/* 0D02F4 7F09B784 01E27021 */  addu  $t6, $t7, $v0
/* 0D02F8 7F09B788 A5C607DC */  sh    $a2, 0x7dc($t6)
/* 0D02FC 7F09B78C 8C6C0000 */  lw    $t4, ($v1)
/* 0D0300 7F09B790 01826821 */  addu  $t5, $t4, $v0
/* 0D0304 7F09B794 24420010 */  addiu $v0, $v0, 0x10
/* 0D0308 7F09B798 1447FFE7 */  bne   $v0, $a3, .L7F09B738
/* 0D030C 7F09B79C A5A007DE */   sh    $zero, 0x7de($t5)
/* 0D0310 7F09B7A0 8C790000 */  lw    $t9, ($v1)
/* 0D0314 7F09B7A4 24020064 */  li    $v0, 100
/* 0D0318 7F09B7A8 A72207F0 */  sh    $v0, 0x7f0($t9)
/* 0D031C 7F09B7AC 8C780000 */  lw    $t8, ($v1)
/* 0D0320 7F09B7B0 A70207F2 */  sh    $v0, 0x7f2($t8)
/* 0D0324 7F09B7B4 8C6B0000 */  lw    $t3, ($v1)
/* 0D0328 7F09B7B8 A56007F4 */  sh    $zero, 0x7f4($t3)
/* 0D032C 7F09B7BC 8C6F0000 */  lw    $t7, ($v1)
/* 0D0330 7F09B7C0 A5E007F6 */  sh    $zero, 0x7f6($t7)
/* 0D0334 7F09B7C4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0338 7F09B7C8 ADC007F8 */  sw    $zero, 0x7f8($t6)
/* 0D033C 7F09B7CC 8C6C0000 */  lw    $t4, ($v1)
/* 0D0340 7F09B7D0 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 0D0344 7F09B7D4 8C6D0000 */  lw    $t5, ($v1)
/* 0D0348 7F09B7D8 ADA00800 */  sw    $zero, 0x800($t5)
/* 0D034C 7F09B7DC 8C790000 */  lw    $t9, ($v1)
/* 0D0350 7F09B7E0 AF200804 */  sw    $zero, 0x804($t9)
/* 0D0354 7F09B7E4 8C780000 */  lw    $t8, ($v1)
/* 0D0358 7F09B7E8 AF092A44 */  sw    $t1, 0x2a44($t8)
/* 0D035C 7F09B7EC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0360 7F09B7F0 0140C025 */  move  $t8, $t2
/* 0D0364 7F09B7F4 AD692A48 */  sw    $t1, 0x2a48($t3)
/* 0D0368 7F09B7F8 8C6F0000 */  lw    $t7, ($v1)
/* 0D036C 7F09B7FC 254B03A8 */  addiu $t3, $t2, 0x3a8
/* 0D0370 7F09B800 ADE02A50 */  sw    $zero, 0x2a50($t7)
/* 0D0374 7F09B804 8C6E0000 */  lw    $t6, ($v1)
/* 0D0378 7F09B808 01407825 */  move  $t7, $t2
/* 0D037C 7F09B80C ADC02A54 */  sw    $zero, 0x2a54($t6)
/* 0D0380 7F09B810 8C6C0000 */  lw    $t4, ($v1)
/* 0D0384 7F09B814 AD800808 */  sw    $zero, 0x808($t4)
/* 0D0388 7F09B818 8C6D0000 */  lw    $t5, ($v1)
/* 0D038C 7F09B81C ADA0080C */  sw    $zero, 0x80c($t5)
/* 0D0390 7F09B820 8C790000 */  lw    $t9, ($v1)
.L7F09B824:
/* 0D0394 7F09B824 8DE10000 */  lw    $at, ($t7)
/* 0D0398 7F09B828 25EF000C */  addiu $t7, $t7, 0xc
/* 0D039C 7F09B82C 2739000C */  addiu $t9, $t9, 0xc
/* 0D03A0 7F09B830 AF210864 */  sw    $at, 0x864($t9)
/* 0D03A4 7F09B834 8DE1FFF8 */  lw    $at, -8($t7)
/* 0D03A8 7F09B838 AF210868 */  sw    $at, 0x868($t9)
/* 0D03AC 7F09B83C 8DE1FFFC */  lw    $at, -4($t7)
/* 0D03B0 7F09B840 15EBFFF8 */  bne   $t7, $t3, .L7F09B824
/* 0D03B4 7F09B844 AF21086C */   sw    $at, 0x86c($t9)
/* 0D03B8 7F09B848 8C6E0000 */  lw    $t6, ($v1)
/* 0D03BC 7F09B84C 254D03A8 */  addiu $t5, $t2, 0x3a8
.L7F09B850:
/* 0D03C0 7F09B850 8F010000 */  lw    $at, ($t8)
/* 0D03C4 7F09B854 2718000C */  addiu $t8, $t8, 0xc
/* 0D03C8 7F09B858 25CE000C */  addiu $t6, $t6, 0xc
/* 0D03CC 7F09B85C ADC10C0C */  sw    $at, 0xc0c($t6)
/* 0D03D0 7F09B860 8F01FFF8 */  lw    $at, -8($t8)
/* 0D03D4 7F09B864 ADC10C10 */  sw    $at, 0xc10($t6)
/* 0D03D8 7F09B868 8F01FFFC */  lw    $at, -4($t8)
/* 0D03DC 7F09B86C 170DFFF8 */  bne   $t8, $t5, .L7F09B850
/* 0D03E0 7F09B870 ADC10C14 */   sw    $at, 0xc14($t6)
/* 0D03E4 7F09B874 8C6B0000 */  lw    $t3, ($v1)
/* 0D03E8 7F09B878 3C018005 */  lui   $at, %hi(D_80057620) # $at, 0x8005
/* 0D03EC 7F09B87C 240200FF */  li    $v0, 255
/* 0D03F0 7F09B880 E5620FC0 */  swc1  $f2, 0xfc0($t3)
/* 0D03F4 7F09B884 8C6F0000 */  lw    $t7, ($v1)
/* 0D03F8 7F09B888 24040007 */  li    $a0, 7
/* 0D03FC 7F09B88C E5E20FC4 */  swc1  $f2, 0xfc4($t7)
/* 0D0400 7F09B890 8C790000 */  lw    $t9, ($v1)
/* 0D0404 7F09B894 AF200FC8 */  sw    $zero, 0xfc8($t9)
/* 0D0408 7F09B898 8C6C0000 */  lw    $t4, ($v1)
/* 0D040C 7F09B89C AD800FCC */  sw    $zero, 0xfcc($t4)
/* 0D0410 7F09B8A0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0414 7F09B8A4 C42C7650 */  lwc1  $f12, %lo(D_80057620)($at)
/* 0D0418 7F09B8A8 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0D041C 7F09B8AC ADA00FD0 */  sw    $zero, 0xfd0($t5)
/* 0D0420 7F09B8B0 8C780000 */  lw    $t8, ($v1)
/* 0D0424 7F09B8B4 AF000FD4 */  sw    $zero, 0xfd4($t8)
/* 0D0428 7F09B8B8 8C6E0000 */  lw    $t6, ($v1)
/* 0D042C 7F09B8BC ADC00FD8 */  sw    $zero, 0xfd8($t6)
/* 0D0430 7F09B8C0 8C6B0000 */  lw    $t3, ($v1)
/* 0D0434 7F09B8C4 A1620FDC */  sb    $v0, 0xfdc($t3)
/* 0D0438 7F09B8C8 8C6F0000 */  lw    $t7, ($v1)
/* 0D043C 7F09B8CC A1E20FDD */  sb    $v0, 0xfdd($t7)
/* 0D0440 7F09B8D0 8C790000 */  lw    $t9, ($v1)
/* 0D0444 7F09B8D4 A3220FDE */  sb    $v0, 0xfde($t9)
/* 0D0448 7F09B8D8 8C6C0000 */  lw    $t4, ($v1)
/* 0D044C 7F09B8DC 3C028008 */  lui   $v0, %hi(random_byte) # $v0, 0x8008
/* 0D0450 7F09B8E0 2442A12C */  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x5ed4
/* 0D0454 7F09B8E4 A1800FDF */  sb    $zero, 0xfdf($t4)
/* 0D0458 7F09B8E8 8C6D0000 */  lw    $t5, ($v1)
/* 0D045C 7F09B8EC ADA80FE0 */  sw    $t0, 0xfe0($t5)
/* 0D0460 7F09B8F0 8C780000 */  lw    $t8, ($v1)
/* 0D0464 7F09B8F4 AF000FE4 */  sw    $zero, 0xfe4($t8)
/* 0D0468 7F09B8F8 8C6E0000 */  lw    $t6, ($v1)
/* 0D046C 7F09B8FC E5C00FE8 */  swc1  $f0, 0xfe8($t6)
/* 0D0470 7F09B900 8C6B0000 */  lw    $t3, ($v1)
/* 0D0474 7F09B904 E5600FEC */  swc1  $f0, 0xfec($t3)
/* 0D0478 7F09B908 8C6F0000 */  lw    $t7, ($v1)
/* 0D047C 7F09B90C E5E00FF0 */  swc1  $f0, 0xff0($t7)
/* 0D0480 7F09B910 8C790000 */  lw    $t9, ($v1)
/* 0D0484 7F09B914 E7200FF4 */  swc1  $f0, 0xff4($t9)
/* 0D0488 7F09B918 8C6C0000 */  lw    $t4, ($v1)
/* 0D048C 7F09B91C E58C0FF8 */  swc1  $f12, 0xff8($t4)
/* 0D0490 7F09B920 8C6D0000 */  lw    $t5, ($v1)
/* 0D0494 7F09B924 E5A00FFC */  swc1  $f0, 0xffc($t5)
/* 0D0498 7F09B928 8C780000 */  lw    $t8, ($v1)
/* 0D049C 7F09B92C E7001000 */  swc1  $f0, 0x1000($t8)
/* 0D04A0 7F09B930 8C6E0000 */  lw    $t6, ($v1)
/* 0D04A4 7F09B934 E5C01004 */  swc1  $f0, 0x1004($t6)
/* 0D04A8 7F09B938 8C6B0000 */  lw    $t3, ($v1)
/* 0D04AC 7F09B93C E5601008 */  swc1  $f0, 0x1008($t3)
/* 0D04B0 7F09B940 8C6F0000 */  lw    $t7, ($v1)
/* 0D04B4 7F09B944 E5EC100C */  swc1  $f12, 0x100c($t7)
/* 0D04B8 7F09B948 44816000 */  mtc1  $at, $f12
/* 0D04BC 7F09B94C 8C790000 */  lw    $t9, ($v1)
/* 0D04C0 7F09B950 3C0143A0 */  li    $at, 0x43A00000 # 320.000000
/* 0D04C4 7F09B954 44817000 */  mtc1  $at, $f14
/* 0D04C8 7F09B958 3C014370 */  li    $at, 0x43700000 # 240.000000
/* 0D04CC 7F09B95C 44818000 */  mtc1  $at, $f16
/* 0D04D0 7F09B960 E7201010 */  swc1  $f0, 0x1010($t9)
/* 0D04D4 7F09B964 3C018005 */  lui   $at, %hi(D_80057624) # $at, 0x8005
/* 0D04D8 7F09B968 C4247654 */  lwc1  $f4, %lo(D_80057624)($at)
/* 0D04DC 7F09B96C 8C6C0000 */  lw    $t4, ($v1)
/* 0D04E0 7F09B970 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0D04E4 7F09B974 44813000 */  mtc1  $at, $f6
/* 0D04E8 7F09B978 E5841014 */  swc1  $f4, 0x1014($t4)
/* 0D04EC 7F09B97C 8C6D0000 */  lw    $t5, ($v1)
/* 0D04F0 7F09B980 3C014238 */  li    $at, 0x42380000 # 46.000000
/* 0D04F4 7F09B984 44814000 */  mtc1  $at, $f8
/* 0D04F8 7F09B988 E5A01018 */  swc1  $f0, 0x1018($t5)
/* 0D04FC 7F09B98C 8C780000 */  lw    $t8, ($v1)
/* 0D0500 7F09B990 3C014320 */  li    $at, 0x43200000 # 160.000000
/* 0D0504 7F09B994 44815000 */  mtc1  $at, $f10
/* 0D0508 7F09B998 AF00105C */  sw    $zero, 0x105c($t8)
/* 0D050C 7F09B99C 8C6E0000 */  lw    $t6, ($v1)
/* 0D0510 7F09B9A0 3C0142F0 */  li    $at, 0x42F00000 # 120.000000
/* 0D0514 7F09B9A4 44819000 */  mtc1  $at, $f18
/* 0D0518 7F09B9A8 ADC01060 */  sw    $zero, 0x1060($t6)
/* 0D051C 7F09B9AC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0520 7F09B9B0 3C018005 */  lui   $at, %hi(D_80057628) # $at, 0x8005
/* 0D0524 7F09B9B4 AD601064 */  sw    $zero, 0x1064($t3)
/* 0D0528 7F09B9B8 8C6F0000 */  lw    $t7, ($v1)
/* 0D052C 7F09B9BC E5E0106C */  swc1  $f0, 0x106c($t7)
/* 0D0530 7F09B9C0 8C790000 */  lw    $t9, ($v1)
/* 0D0534 7F09B9C4 E7201070 */  swc1  $f0, 0x1070($t9)
/* 0D0538 7F09B9C8 8C6C0000 */  lw    $t4, ($v1)
/* 0D053C 7F09B9CC E5801074 */  swc1  $f0, 0x1074($t4)
/* 0D0540 7F09B9D0 8C6D0000 */  lw    $t5, ($v1)
/* 0D0544 7F09B9D4 ADA01078 */  sw    $zero, 0x1078($t5)
/* 0D0548 7F09B9D8 8C780000 */  lw    $t8, ($v1)
/* 0D054C 7F09B9DC E700107C */  swc1  $f0, 0x107c($t8)
/* 0D0550 7F09B9E0 8C6E0000 */  lw    $t6, ($v1)
/* 0D0554 7F09B9E4 E5C01080 */  swc1  $f0, 0x1080($t6)
/* 0D0558 7F09B9E8 8C6B0000 */  lw    $t3, ($v1)
/* 0D055C 7F09B9EC E56C1084 */  swc1  $f12, 0x1084($t3)
/* 0D0560 7F09B9F0 8C6F0000 */  lw    $t7, ($v1)
/* 0D0564 7F09B9F4 E5EC1088 */  swc1  $f12, 0x1088($t7)
/* 0D0568 7F09B9F8 8C790000 */  lw    $t9, ($v1)
/* 0D056C 7F09B9FC AF29108C */  sw    $t1, 0x108c($t9)
/* 0D0570 7F09BA00 8C6C0000 */  lw    $t4, ($v1)
/* 0D0574 7F09BA04 E58E1090 */  swc1  $f14, 0x1090($t4)
/* 0D0578 7F09BA08 8C6D0000 */  lw    $t5, ($v1)
/* 0D057C 7F09BA0C E5B01094 */  swc1  $f16, 0x1094($t5)
/* 0D0580 7F09BA10 8C780000 */  lw    $t8, ($v1)
/* 0D0584 7F09BA14 E7001098 */  swc1  $f0, 0x1098($t8)
/* 0D0588 7F09BA18 8C6E0000 */  lw    $t6, ($v1)
/* 0D058C 7F09BA1C E5C0109C */  swc1  $f0, 0x109c($t6)
/* 0D0590 7F09BA20 8C6B0000 */  lw    $t3, ($v1)
/* 0D0594 7F09BA24 E56610A0 */  swc1  $f6, 0x10a0($t3)
/* 0D0598 7F09BA28 8C6F0000 */  lw    $t7, ($v1)
/* 0D059C 7F09BA2C E5E810A4 */  swc1  $f8, 0x10a4($t7)
/* 0D05A0 7F09BA30 8C790000 */  lw    $t9, ($v1)
/* 0D05A4 7F09BA34 E72210A8 */  swc1  $f2, 0x10a8($t9)
/* 0D05A8 7F09BA38 8C6C0000 */  lw    $t4, ($v1)
/* 0D05AC 7F09BA3C E58A10AC */  swc1  $f10, 0x10ac($t4)
/* 0D05B0 7F09BA40 8C6D0000 */  lw    $t5, ($v1)
/* 0D05B4 7F09BA44 E5B210B0 */  swc1  $f18, 0x10b0($t5)
/* 0D05B8 7F09BA48 8C780000 */  lw    $t8, ($v1)
/* 0D05BC 7F09BA4C E70210B4 */  swc1  $f2, 0x10b4($t8)
/* 0D05C0 7F09BA50 8C6E0000 */  lw    $t6, ($v1)
/* 0D05C4 7F09BA54 E5C210B8 */  swc1  $f2, 0x10b8($t6)
/* 0D05C8 7F09BA58 8C6B0000 */  lw    $t3, ($v1)
/* 0D05CC 7F09BA5C E56210BC */  swc1  $f2, 0x10bc($t3)
/* 0D05D0 7F09BA60 8C6F0000 */  lw    $t7, ($v1)
/* 0D05D4 7F09BA64 E5E210C0 */  swc1  $f2, 0x10c0($t7)
/* 0D05D8 7F09BA68 8C790000 */  lw    $t9, ($v1)
/* 0D05DC 7F09BA6C AF2010C4 */  sw    $zero, 0x10c4($t9)
/* 0D05E0 7F09BA70 8C6C0000 */  lw    $t4, ($v1)
/* 0D05E4 7F09BA74 AD8010C8 */  sw    $zero, 0x10c8($t4)
/* 0D05E8 7F09BA78 8C6D0000 */  lw    $t5, ($v1)
/* 0D05EC 7F09BA7C ADA010CC */  sw    $zero, 0x10cc($t5)
/* 0D05F0 7F09BA80 8C780000 */  lw    $t8, ($v1)
/* 0D05F4 7F09BA84 AF0010D0 */  sw    $zero, 0x10d0($t8)
/* 0D05F8 7F09BA88 8C6E0000 */  lw    $t6, ($v1)
/* 0D05FC 7F09BA8C ADC010D4 */  sw    $zero, 0x10d4($t6)
/* 0D0600 7F09BA90 8C6B0000 */  lw    $t3, ($v1)
/* 0D0604 7F09BA94 AD6010D8 */  sw    $zero, 0x10d8($t3)
/* 0D0608 7F09BA98 8C6F0000 */  lw    $t7, ($v1)
/* 0D060C 7F09BA9C ADE010DC */  sw    $zero, 0x10dc($t7)
/* 0D0610 7F09BAA0 8C790000 */  lw    $t9, ($v1)
/* 0D0614 7F09BAA4 AF2010E0 */  sw    $zero, 0x10e0($t9)
/* 0D0618 7F09BAA8 8C6C0000 */  lw    $t4, ($v1)
/* 0D061C 7F09BAAC 3C190001 */  lui   $t9, 1
/* 0D0620 7F09BAB0 AD8010E4 */  sw    $zero, 0x10e4($t4)
/* 0D0624 7F09BAB4 8C6D0000 */  lw    $t5, ($v1)
/* 0D0628 7F09BAB8 ADA010E8 */  sw    $zero, 0x10e8($t5)
/* 0D062C 7F09BABC 8C780000 */  lw    $t8, ($v1)
/* 0D0630 7F09BAC0 AF0010EC */  sw    $zero, 0x10ec($t8)
/* 0D0634 7F09BAC4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0638 7F09BAC8 E5C210F0 */  swc1  $f2, 0x10f0($t6)
/* 0D063C 7F09BACC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0640 7F09BAD0 E56210F4 */  swc1  $f2, 0x10f4($t3)
/* 0D0644 7F09BAD4 8C6F0000 */  lw    $t7, ($v1)
/* 0D0648 7F09BAD8 E5E210F8 */  swc1  $f2, 0x10f8($t7)
/* 0D064C 7F09BADC 8C6C0000 */  lw    $t4, ($v1)
/* 0D0650 7F09BAE0 AD9910FC */  sw    $t9, 0x10fc($t4)
/* 0D0654 7F09BAE4 8C6D0000 */  lw    $t5, ($v1)
/* 0D0658 7F09BAE8 E5A01118 */  swc1  $f0, 0x1118($t5)
/* 0D065C 7F09BAEC 8C780000 */  lw    $t8, ($v1)
/* 0D0660 7F09BAF0 E700111C */  swc1  $f0, 0x111c($t8)
/* 0D0664 7F09BAF4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0668 7F09BAF8 E5CE1120 */  swc1  $f14, 0x1120($t6)
/* 0D066C 7F09BAFC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0670 7F09BB00 E5701124 */  swc1  $f16, 0x1124($t3)
/* 0D0674 7F09BB04 8C6F0000 */  lw    $t7, ($v1)
/* 0D0678 7F09BB08 ADE01128 */  sw    $zero, 0x1128($t7)
/* 0D067C 7F09BB0C 8C790000 */  lw    $t9, ($v1)
/* 0D0680 7F09BB10 AF2011B0 */  sw    $zero, 0x11b0($t9)
/* 0D0684 7F09BB14 8C6C0000 */  lw    $t4, ($v1)
/* 0D0688 7F09BB18 AD8011B4 */  sw    $zero, 0x11b4($t4)
/* 0D068C 7F09BB1C 8C6D0000 */  lw    $t5, ($v1)
/* 0D0690 7F09BB20 ADA011B8 */  sw    $zero, 0x11b8($t5)
/* 0D0694 7F09BB24 8C780000 */  lw    $t8, ($v1)
/* 0D0698 7F09BB28 E70011BC */  swc1  $f0, 0x11bc($t8)
/* 0D069C 7F09BB2C 8C6E0000 */  lw    $t6, ($v1)
/* 0D06A0 7F09BB30 E5C011C0 */  swc1  $f0, 0x11c0($t6)
/* 0D06A4 7F09BB34 8C6B0000 */  lw    $t3, ($v1)
/* 0D06A8 7F09BB38 E56C11C4 */  swc1  $f12, 0x11c4($t3)
/* 0D06AC 7F09BB3C 8C6F0000 */  lw    $t7, ($v1)
/* 0D06B0 7F09BB40 E5EC11C8 */  swc1  $f12, 0x11c8($t7)
/* 0D06B4 7F09BB44 8C790000 */  lw    $t9, ($v1)
/* 0D06B8 7F09BB48 E72C11CC */  swc1  $f12, 0x11cc($t9)
/* 0D06BC 7F09BB4C 8C6C0000 */  lw    $t4, ($v1)
/* 0D06C0 7F09BB50 E58C11D0 */  swc1  $f12, 0x11d0($t4)
/* 0D06C4 7F09BB54 8C6D0000 */  lw    $t5, ($v1)
/* 0D06C8 7F09BB58 C4247658 */  lwc1  $f4, %lo(D_80057628)($at)
/* 0D06CC 7F09BB5C 3C018003 */  lui   $at, %hi(g_VisibleToGuardsFlag) # $at, 0x8003
/* 0D06D0 7F09BB60 E5A411D4 */  swc1  $f4, 0x11d4($t5)
/* 0D06D4 7F09BB64 8C780000 */  lw    $t8, ($v1)
/* 0D06D8 7F09BB68 AF0011D8 */  sw    $zero, 0x11d8($t8)
/* 0D06DC 7F09BB6C 8C6E0000 */  lw    $t6, ($v1)
/* 0D06E0 7F09BB70 ADC911DC */  sw    $t1, 0x11dc($t6)
/* 0D06E4 7F09BB74 8C6B0000 */  lw    $t3, ($v1)
/* 0D06E8 7F09BB78 AD6011E0 */  sw    $zero, 0x11e0($t3)
/* 0D06EC 7F09BB7C 8C6F0000 */  lw    $t7, ($v1)
/* 0D06F0 7F09BB80 ADE011E4 */  sw    $zero, 0x11e4($t7)
/* 0D06F4 7F09BB84 8C790000 */  lw    $t9, ($v1)
/* 0D06F8 7F09BB88 AF2011E8 */  sw    $zero, 0x11e8($t9)
/* 0D06FC 7F09BB8C 8C6C0000 */  lw    $t4, ($v1)
/* 0D0700 7F09BB90 AD8011EC */  sw    $zero, 0x11ec($t4)
/* 0D0704 7F09BB94 8C6D0000 */  lw    $t5, ($v1)
/* 0D0708 7F09BB98 ADA011F0 */  sw    $zero, 0x11f0($t5)
/* 0D070C 7F09BB9C 8C780000 */  lw    $t8, ($v1)
/* 0D0710 7F09BBA0 AF0011F4 */  sw    $zero, 0x11f4($t8)
/* 0D0714 7F09BBA4 8C6E0000 */  lw    $t6, ($v1)
/* 0D0718 7F09BBA8 E5C01280 */  swc1  $f0, 0x1280($t6)
/* 0D071C 7F09BBAC 8C6B0000 */  lw    $t3, ($v1)
/* 0D0720 7F09BBB0 AD601284 */  sw    $zero, 0x1284($t3)
/* 0D0724 7F09BBB4 8C6F0000 */  lw    $t7, ($v1)
/* 0D0728 7F09BBB8 E5E01288 */  swc1  $f0, 0x1288($t7)
/* 0D072C 7F09BBBC 8C790000 */  lw    $t9, ($v1)
/* 0D0730 7F09BBC0 A32012B6 */  sb    $zero, 0x12b6($t9)
/* 0D0734 7F09BBC4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0738 7F09BBC8 AD8429B8 */  sw    $a0, 0x29b8($t4)
/* 0D073C 7F09BBCC 8C6D0000 */  lw    $t5, ($v1)
/* 0D0740 7F09BBD0 E5A229BC */  swc1  $f2, 0x29bc($t5)
/* 0D0744 7F09BBD4 8C780000 */  lw    $t8, ($v1)
/* 0D0748 7F09BBD8 E70029C0 */  swc1  $f0, 0x29c0($t8)
/* 0D074C 7F09BBDC 8C6E0000 */  lw    $t6, ($v1)
/* 0D0750 7F09BBE0 ADC029C4 */  sw    $zero, 0x29c4($t6)
/* 0D0754 7F09BBE4 8C6B0000 */  lw    $t3, ($v1)
/* 0D0758 7F09BBE8 AD6429D4 */  sw    $a0, 0x29d4($t3)
/* 0D075C 7F09BBEC 8C6F0000 */  lw    $t7, ($v1)
/* 0D0760 7F09BBF0 ADE029D8 */  sw    $zero, 0x29d8($t7)
/* 0D0764 7F09BBF4 8C6C0000 */  lw    $t4, ($v1)
/* 0D0768 7F09BBF8 8C590000 */  lw    $t9, ($v0)
/* 0D076C 7F09BBFC AD9929E0 */  sw    $t9, 0x29e0($t4)
/* 0D0770 7F09BC00 8C4D0000 */  lw    $t5, ($v0)
/* 0D0774 7F09BC04 8C6E0000 */  lw    $t6, ($v1)
/* 0D0778 7F09BC08 25B80001 */  addiu $t8, $t5, 1
/* 0D077C 7F09BC0C AC580000 */  sw    $t8, ($v0)
/* 0D0780 7F09BC10 ADC929E4 */  sw    $t1, 0x29e4($t6)
/* 0D0784 7F09BC14 8C6B0000 */  lw    $t3, ($v1)
/* 0D0788 7F09BC18 AD6929E8 */  sw    $t1, 0x29e8($t3)
/* 0D078C 7F09BC1C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0790 7F09BC20 ADE929EC */  sw    $t1, 0x29ec($t7)
/* 0D0794 7F09BC24 8C790000 */  lw    $t9, ($v1)
/* 0D0798 7F09BC28 AF2929F0 */  sw    $t1, 0x29f0($t9)
/* 0D079C 7F09BC2C 8C6C0000 */  lw    $t4, ($v1)
/* 0D07A0 7F09BC30 AD802A00 */  sw    $zero, 0x2a00($t4)
/* 0D07A4 7F09BC34 8C6D0000 */  lw    $t5, ($v1)
/* 0D07A8 7F09BC38 ADA02A30 */  sw    $zero, 0x2a30($t5)
/* 0D07AC 7F09BC3C 8C780000 */  lw    $t8, ($v1)
/* 0D07B0 7F09BC40 AF002A34 */  sw    $zero, 0x2a34($t8)
/* 0D07B4 7F09BC44 8C6E0000 */  lw    $t6, ($v1)
/* 0D07B8 7F09BC48 ADC82A38 */  sw    $t0, 0x2a38($t6)
/* 0D07BC 7F09BC4C 8C6B0000 */  lw    $t3, ($v1)
/* 0D07C0 7F09BC50 E5622A3C */  swc1  $f2, 0x2a3c($t3)
/* 0D07C4 7F09BC54 8C6F0000 */  lw    $t7, ($v1)
/* 0D07C8 7F09BC58 E5E22A40 */  swc1  $f2, 0x2a40($t7)
/* 0D07CC 7F09BC5C 8C790000 */  lw    $t9, ($v1)
/* 0D07D0 7F09BC60 AF202A58 */  sw    $zero, 0x2a58($t9)
/* 0D07D4 7F09BC64 8C6C0000 */  lw    $t4, ($v1)
/* 0D07D8 7F09BC68 AD802A5C */  sw    $zero, 0x2a5c($t4)
/* 0D07DC 7F09BC6C 8C6D0000 */  lw    $t5, ($v1)
/* 0D07E0 7F09BC70 E5A02A60 */  swc1  $f0, 0x2a60($t5)
/* 0D07E4 7F09BC74 8C780000 */  lw    $t8, ($v1)
/* 0D07E8 7F09BC78 AF002A64 */  sw    $zero, 0x2a64($t8)
/* 0D07EC 7F09BC7C 8C6E0000 */  lw    $t6, ($v1)
/* 0D07F0 7F09BC80 ADC82A68 */  sw    $t0, 0x2a68($t6)
/* 0D07F4 7F09BC84 8C6B0000 */  lw    $t3, ($v1)
/* 0D07F8 7F09BC88 AD602A6C */  sw    $zero, 0x2a6c($t3)
/* 0D07FC 7F09BC8C 8C6F0000 */  lw    $t7, ($v1)
/* 0D0800 7F09BC90 ADE02A70 */  sw    $zero, 0x2a70($t7)
/* 0D0804 7F09BC94 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0D0808 7F09BC98 AC286504 */  sw    $t0, %lo(g_VisibleToGuardsFlag)($at)
/* 0D080C 7F09BC9C 3C018003 */  lui   $at, %hi(obj_collision_flag) # $at, 0x8003
/* 0D0810 7F09BCA0 AC286508 */  sw    $t0, %lo(obj_collision_flag)($at)
/* 0D0814 7F09BCA4 03E00008 */  jr    $ra
/* 0D0818 7F09BCA8 27BD03D0 */   addiu $sp, $sp, 0x3d0
)
#endif

#if defined(VERSION_EU)
GLOBAL_ASM(
.late_rodata
glabel D_80057610
.word 0xc3652ee0 /*-229.18311*/
glabel D_80057614
.word 0x4106ae1e
glabel D_80057618
.word 0x3f6aa64c
glabel D_8005761C
.word 0x413fd8b4
glabel D_80057620
.word 0x3f666666 /*0.89999998*/
glabel D_80057624
.word 0xc0490fdb /*-3.1415927*/
glabel D_80057628
.word 0x3f969697
.text
glabel initBONDdataforPlayer
/* 0CC3EC 7F0999FC 27BDFC30 */  addiu $sp, $sp, -0x3d0
/* 0CC3F0 7F099A00 3C0F8004 */  lui   $t7, %hi(D_8003FD94+0xC) # $t7, 0x8004
/* 0CC3F4 7F099A04 25EF99F0 */  addiu $t7, %lo(D_8003FD94+0xC) # addiu $t7, $t7, -0x6610
/* 0CC3F8 7F099A08 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CC3FC 7F099A0C AFA403D0 */  sw    $a0, 0x3d0($sp)
/* 0CC400 7F099A10 25EB03A8 */  addiu $t3, $t7, 0x3a8
/* 0CC404 7F099A14 27AE0024 */  addiu $t6, $sp, 0x24
.L7F099A18:
/* 0CC408 7F099A18 8DE10000 */  lw    $at, ($t7)
/* 0CC40C 7F099A1C 25EF000C */  addiu $t7, $t7, 0xc
/* 0CC410 7F099A20 25CE000C */  addiu $t6, $t6, 0xc
/* 0CC414 7F099A24 ADC1FFF4 */  sw    $at, -0xc($t6)
/* 0CC418 7F099A28 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CC41C 7F099A2C ADC1FFF8 */  sw    $at, -8($t6)
/* 0CC420 7F099A30 8DE1FFFC */  lw    $at, -4($t7)
/* 0CC424 7F099A34 15EBFFF8 */  bne   $t7, $t3, .L7F099A18
/* 0CC428 7F099A38 ADC1FFFC */   sw    $at, -4($t6)
/* 0CC42C 7F099A3C 24042A70 */  li    $a0, 10864
/* 0CC430 7F099A40 0C0022E0 */  jal   mempAllocBytesInBank
/* 0CC434 7F099A44 24050004 */   li    $a1, 4
/* 0CC438 7F099A48 8FAC03D0 */  lw    $t4, 0x3d0($sp)
/* 0CC43C 7F099A4C 3C198007 */  lui   $t9, %hi(g_playerPointers) # $t9, 0x8007
/* 0CC440 7F099A50 273989F0 */  addiu $t9, %lo(g_playerPointers) # addiu $t9, $t9, -0x7610
/* 0CC444 7F099A54 000C6880 */  sll   $t5, $t4, 2
/* 0CC448 7F099A58 01B91821 */  addu  $v1, $t5, $t9
/* 0CC44C 7F099A5C AC620000 */  sw    $v0, ($v1)
/* 0CC450 7F099A60 AC400000 */  sw    $zero, ($v0)
/* 0CC454 7F099A64 44800000 */  mtc1  $zero, $f0
/* 0CC458 7F099A68 8C780000 */  lw    $t8, ($v1)
/* 0CC45C 7F099A6C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0CC460 7F099A70 44811000 */  mtc1  $at, $f2
/* 0CC464 7F099A74 E7000004 */  swc1  $f0, 4($t8)
/* 0CC468 7F099A78 8C6B0000 */  lw    $t3, ($v1)
/* 0CC46C 7F099A7C 24040002 */  li    $a0, 2
/* 0CC470 7F099A80 24080001 */  li    $t0, 1
/* 0CC474 7F099A84 E5600008 */  swc1  $f0, 8($t3)
/* 0CC478 7F099A88 8C6F0000 */  lw    $t7, ($v1)
/* 0CC47C 7F099A8C 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0CC480 7F099A90 44816000 */  mtc1  $at, $f12
/* 0CC484 7F099A94 E5E0000C */  swc1  $f0, 0xc($t7)
/* 0CC488 7F099A98 8C6E0000 */  lw    $t6, ($v1)
/* 0CC48C 7F099A9C 2409FFFF */  li    $t1, -1
/* 0CC490 7F099AA0 3C01C080 */  li    $at, 0xC0800000 # -4.000000
/* 0CC494 7F099AA4 E5C00010 */  swc1  $f0, 0x10($t6)
/* 0CC498 7F099AA8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC49C 7F099AAC 44812000 */  mtc1  $at, $f4
/* 0CC4A0 7F099AB0 3C018005 */  lui   $at, %hi(D_80057610)
/* 0CC4A4 7F099AB4 E5800014 */  swc1  $f0, 0x14($t4)
/* 0CC4A8 7F099AB8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC4AC 7F099ABC 240200FF */  li    $v0, 255
/* 0CC4B0 7F099AC0 27AA0024 */  addiu $t2, $sp, 0x24
/* 0CC4B4 7F099AC4 E5A20018 */  swc1  $f2, 0x18($t5)
/* 0CC4B8 7F099AC8 8C790000 */  lw    $t9, ($v1)
/* 0CC4BC 7F099ACC E720001C */  swc1  $f0, 0x1c($t9)
/* 0CC4C0 7F099AD0 8C780000 */  lw    $t8, ($v1)
/* 0CC4C4 7F099AD4 E7020020 */  swc1  $f2, 0x20($t8)
/* 0CC4C8 7F099AD8 8C6B0000 */  lw    $t3, ($v1)
/* 0CC4CC 7F099ADC E5600024 */  swc1  $f0, 0x24($t3)
/* 0CC4D0 7F099AE0 8C6F0000 */  lw    $t7, ($v1)
/* 0CC4D4 7F099AE4 E5E00028 */  swc1  $f0, 0x28($t7)
/* 0CC4D8 7F099AE8 8C6E0000 */  lw    $t6, ($v1)
/* 0CC4DC 7F099AEC E5C0002C */  swc1  $f0, 0x2c($t6)
/* 0CC4E0 7F099AF0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC4E4 7F099AF4 E5800030 */  swc1  $f0, 0x30($t4)
/* 0CC4E8 7F099AF8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC4EC 7F099AFC ADA00034 */  sw    $zero, 0x34($t5)
/* 0CC4F0 7F099B00 8C790000 */  lw    $t9, ($v1)
/* 0CC4F4 7F099B04 E7200038 */  swc1  $f0, 0x38($t9)
/* 0CC4F8 7F099B08 8C780000 */  lw    $t8, ($v1)
/* 0CC4FC 7F099B0C E700003C */  swc1  $f0, 0x3c($t8)
/* 0CC500 7F099B10 8C6B0000 */  lw    $t3, ($v1)
/* 0CC504 7F099B14 E5600040 */  swc1  $f0, 0x40($t3)
/* 0CC508 7F099B18 8C6F0000 */  lw    $t7, ($v1)
/* 0CC50C 7F099B1C E5E00044 */  swc1  $f0, 0x44($t7)
/* 0CC510 7F099B20 8C6E0000 */  lw    $t6, ($v1)
/* 0CC514 7F099B24 E5C00048 */  swc1  $f0, 0x48($t6)
/* 0CC518 7F099B28 8C6C0000 */  lw    $t4, ($v1)
/* 0CC51C 7F099B2C E580004C */  swc1  $f0, 0x4c($t4)
/* 0CC520 7F099B30 8C6D0000 */  lw    $t5, ($v1)
/* 0CC524 7F099B34 E5A00050 */  swc1  $f0, 0x50($t5)
/* 0CC528 7F099B38 8C790000 */  lw    $t9, ($v1)
/* 0CC52C 7F099B3C E7200054 */  swc1  $f0, 0x54($t9)
/* 0CC530 7F099B40 8C780000 */  lw    $t8, ($v1)
/* 0CC534 7F099B44 E7000058 */  swc1  $f0, 0x58($t8)
/* 0CC538 7F099B48 8C6B0000 */  lw    $t3, ($v1)
/* 0CC53C 7F099B4C E560006C */  swc1  $f0, 0x6c($t3)
/* 0CC540 7F099B50 8C6F0000 */  lw    $t7, ($v1)
/* 0CC544 7F099B54 E5E00070 */  swc1  $f0, 0x70($t7)
/* 0CC548 7F099B58 8C6E0000 */  lw    $t6, ($v1)
/* 0CC54C 7F099B5C E5C00074 */  swc1  $f0, 0x74($t6)
/* 0CC550 7F099B60 8C6C0000 */  lw    $t4, ($v1)
/* 0CC554 7F099B64 E5800078 */  swc1  $f0, 0x78($t4)
/* 0CC558 7F099B68 8C6D0000 */  lw    $t5, ($v1)
/* 0CC55C 7F099B6C E5A0007C */  swc1  $f0, 0x7c($t5)
/* 0CC560 7F099B70 8C790000 */  lw    $t9, ($v1)
/* 0CC564 7F099B74 E7200080 */  swc1  $f0, 0x80($t9)
/* 0CC568 7F099B78 8C780000 */  lw    $t8, ($v1)
/* 0CC56C 7F099B7C E7000084 */  swc1  $f0, 0x84($t8)
/* 0CC570 7F099B80 8C6B0000 */  lw    $t3, ($v1)
/* 0CC574 7F099B84 E5600088 */  swc1  $f0, 0x88($t3)
/* 0CC578 7F099B88 8C6F0000 */  lw    $t7, ($v1)
/* 0CC57C 7F099B8C ADE0008C */  sw    $zero, 0x8c($t7)
/* 0CC580 7F099B90 8C6E0000 */  lw    $t6, ($v1)
/* 0CC584 7F099B94 E5C00090 */  swc1  $f0, 0x90($t6)
/* 0CC588 7F099B98 8C6C0000 */  lw    $t4, ($v1)
/* 0CC58C 7F099B9C AD800094 */  sw    $zero, 0x94($t4)
/* 0CC590 7F099BA0 8C6D0000 */  lw    $t5, ($v1)
/* 0CC594 7F099BA4 E5A00098 */  swc1  $f0, 0x98($t5)
/* 0CC598 7F099BA8 8C790000 */  lw    $t9, ($v1)
/* 0CC59C 7F099BAC E720126C */  swc1  $f0, 0x126c($t9)
/* 0CC5A0 7F099BB0 8C780000 */  lw    $t8, ($v1)
/* 0CC5A4 7F099BB4 E7001270 */  swc1  $f0, 0x1270($t8)
/* 0CC5A8 7F099BB8 8C6B0000 */  lw    $t3, ($v1)
/* 0CC5AC 7F099BBC E5601274 */  swc1  $f0, 0x1274($t3)
/* 0CC5B0 7F099BC0 8C6F0000 */  lw    $t7, ($v1)
/* 0CC5B4 7F099BC4 ADE4009C */  sw    $a0, 0x9c($t7)
/* 0CC5B8 7F099BC8 8C6E0000 */  lw    $t6, ($v1)
/* 0CC5BC 7F099BCC ADC429F4 */  sw    $a0, 0x29f4($t6)
/* 0CC5C0 7F099BD0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC5C4 7F099BD4 E58000A0 */  swc1  $f0, 0xa0($t4)
/* 0CC5C8 7F099BD8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC5CC 7F099BDC E5A000A4 */  swc1  $f0, 0xa4($t5)
/* 0CC5D0 7F099BE0 8C790000 */  lw    $t9, ($v1)
/* 0CC5D4 7F099BE4 AF2000A8 */  sw    $zero, 0xa8($t9)
/* 0CC5D8 7F099BE8 8C780000 */  lw    $t8, ($v1)
/* 0CC5DC 7F099BEC AF0800AC */  sw    $t0, 0xac($t8)
/* 0CC5E0 7F099BF0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC5E4 7F099BF4 AD6000D0 */  sw    $zero, 0xd0($t3)
/* 0CC5E8 7F099BF8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC5EC 7F099BFC ADE000D4 */  sw    $zero, 0xd4($t7)
/* 0CC5F0 7F099C00 8C6E0000 */  lw    $t6, ($v1)
/* 0CC5F4 7F099C04 ADC000D8 */  sw    $zero, 0xd8($t6)
/* 0CC5F8 7F099C08 8C6C0000 */  lw    $t4, ($v1)
/* 0CC5FC 7F099C0C E58200DC */  swc1  $f2, 0xdc($t4)
/* 0CC600 7F099C10 8C6D0000 */  lw    $t5, ($v1)
/* 0CC604 7F099C14 E5A000E0 */  swc1  $f0, 0xe0($t5)
/* 0CC608 7F099C18 8C790000 */  lw    $t9, ($v1)
/* 0CC60C 7F099C1C E72200E4 */  swc1  $f2, 0xe4($t9)
/* 0CC610 7F099C20 8C780000 */  lw    $t8, ($v1)
/* 0CC614 7F099C24 E70000E8 */  swc1  $f0, 0xe8($t8)
/* 0CC618 7F099C28 8C6B0000 */  lw    $t3, ($v1)
/* 0CC61C 7F099C2C E56200EC */  swc1  $f2, 0xec($t3)
/* 0CC620 7F099C30 8C6F0000 */  lw    $t7, ($v1)
/* 0CC624 7F099C34 E5E000F0 */  swc1  $f0, 0xf0($t7)
/* 0CC628 7F099C38 8C6E0000 */  lw    $t6, ($v1)
/* 0CC62C 7F099C3C E5CC00F4 */  swc1  $f12, 0xf4($t6)
/* 0CC630 7F099C40 8C6C0000 */  lw    $t4, ($v1)
/* 0CC634 7F099C44 E58C00F8 */  swc1  $f12, 0xf8($t4)
/* 0CC638 7F099C48 8C6D0000 */  lw    $t5, ($v1)
/* 0CC63C 7F099C4C ADA00104 */  sw    $zero, 0x104($t5)
/* 0CC640 7F099C50 8C790000 */  lw    $t9, ($v1)
/* 0CC644 7F099C54 AF200108 */  sw    $zero, 0x108($t9)
/* 0CC648 7F099C58 8C780000 */  lw    $t8, ($v1)
/* 0CC64C 7F099C5C AF00010C */  sw    $zero, 0x10c($t8)
/* 0CC650 7F099C60 8C6B0000 */  lw    $t3, ($v1)
/* 0CC654 7F099C64 AD600110 */  sw    $zero, 0x110($t3)
/* 0CC658 7F099C68 8C6F0000 */  lw    $t7, ($v1)
/* 0CC65C 7F099C6C ADE80114 */  sw    $t0, 0x114($t7)
/* 0CC660 7F099C70 8C6E0000 */  lw    $t6, ($v1)
/* 0CC664 7F099C74 ADC80118 */  sw    $t0, 0x118($t6)
/* 0CC668 7F099C78 8C6C0000 */  lw    $t4, ($v1)
/* 0CC66C 7F099C7C AD80011C */  sw    $zero, 0x11c($t4)
/* 0CC670 7F099C80 8C6D0000 */  lw    $t5, ($v1)
/* 0CC674 7F099C84 ADA80120 */  sw    $t0, 0x120($t5)
/* 0CC678 7F099C88 8C790000 */  lw    $t9, ($v1)
/* 0CC67C 7F099C8C AF200124 */  sw    $zero, 0x124($t9)
/* 0CC680 7F099C90 8C780000 */  lw    $t8, ($v1)
/* 0CC684 7F099C94 AF080128 */  sw    $t0, 0x128($t8)
/* 0CC688 7F099C98 8C6B0000 */  lw    $t3, ($v1)
/* 0CC68C 7F099C9C E560012C */  swc1  $f0, 0x12c($t3)
/* 0CC690 7F099CA0 8C6F0000 */  lw    $t7, ($v1)
/* 0CC694 7F099CA4 ADE00130 */  sw    $zero, 0x130($t7)
/* 0CC698 7F099CA8 8C6E0000 */  lw    $t6, ($v1)
/* 0CC69C 7F099CAC ADC90134 */  sw    $t1, 0x134($t6)
/* 0CC6A0 7F099CB0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC6A4 7F099CB4 AD880138 */  sw    $t0, 0x138($t4)
/* 0CC6A8 7F099CB8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC6AC 7F099CBC E5A0013C */  swc1  $f0, 0x13c($t5)
/* 0CC6B0 7F099CC0 8C790000 */  lw    $t9, ($v1)
/* 0CC6B4 7F099CC4 AF200140 */  sw    $zero, 0x140($t9)
/* 0CC6B8 7F099CC8 8C780000 */  lw    $t8, ($v1)
/* 0CC6BC 7F099CCC AF090144 */  sw    $t1, 0x144($t8)
/* 0CC6C0 7F099CD0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC6C4 7F099CD4 E5600148 */  swc1  $f0, 0x148($t3)
/* 0CC6C8 7F099CD8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC6CC 7F099CDC E5E0014C */  swc1  $f0, 0x14c($t7)
/* 0CC6D0 7F099CE0 8C6E0000 */  lw    $t6, ($v1)
/* 0CC6D4 7F099CE4 E5C20150 */  swc1  $f2, 0x150($t6)
/* 0CC6D8 7F099CE8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC6DC 7F099CEC E5800154 */  swc1  $f0, 0x154($t4)
/* 0CC6E0 7F099CF0 8C6D0000 */  lw    $t5, ($v1)
/* 0CC6E4 7F099CF4 E5A40158 */  swc1  $f4, 0x158($t5)
/* 0CC6E8 7F099CF8 8C790000 */  lw    $t9, ($v1)
/* 0CC6EC 7F099CFC C426CCD0 */  lwc1  $f6, %lo(D_80057610)($at)
/* 0CC6F0 7F099D00 3C01C1C8 */  li    $at, 0xC1C80000 # -25.000000
/* 0CC6F4 7F099D04 44814000 */  mtc1  $at, $f8
/* 0CC6F8 7F099D08 E726015C */  swc1  $f6, 0x15c($t9)
/* 0CC6FC 7F099D0C 8C780000 */  lw    $t8, ($v1)
/* 0CC700 7F099D10 3C018005 */  lui   $at, %hi(D_80057614) # $at, 0x8005
/* 0CC704 7F099D14 E7000160 */  swc1  $f0, 0x160($t8)
/* 0CC708 7F099D18 8C6B0000 */  lw    $t3, ($v1)
/* 0CC70C 7F099D1C E5620164 */  swc1  $f2, 0x164($t3)
/* 0CC710 7F099D20 8C6F0000 */  lw    $t7, ($v1)
/* 0CC714 7F099D24 E5E00168 */  swc1  $f0, 0x168($t7)
/* 0CC718 7F099D28 8C6E0000 */  lw    $t6, ($v1)
/* 0CC71C 7F099D2C E5C0016C */  swc1  $f0, 0x16c($t6)
/* 0CC720 7F099D30 8C6C0000 */  lw    $t4, ($v1)
/* 0CC724 7F099D34 E5800170 */  swc1  $f0, 0x170($t4)
/* 0CC728 7F099D38 8C6D0000 */  lw    $t5, ($v1)
/* 0CC72C 7F099D3C E5A00174 */  swc1  $f0, 0x174($t5)
/* 0CC730 7F099D40 8C790000 */  lw    $t9, ($v1)
/* 0CC734 7F099D44 E7202A44 */  swc1  $f0, 0x2a44($t9)
/* 0CC738 7F099D48 8C780000 */  lw    $t8, ($v1)
/* 0CC73C 7F099D4C E7020178 */  swc1  $f2, 0x178($t8)
/* 0CC740 7F099D50 8C6B0000 */  lw    $t3, ($v1)
/* 0CC744 7F099D54 E5600180 */  swc1  $f0, 0x180($t3)
/* 0CC748 7F099D58 8C6F0000 */  lw    $t7, ($v1)
/* 0CC74C 7F099D5C E5E00184 */  swc1  $f0, 0x184($t7)
/* 0CC750 7F099D60 8C6E0000 */  lw    $t6, ($v1)
/* 0CC754 7F099D64 E5C00188 */  swc1  $f0, 0x188($t6)
/* 0CC758 7F099D68 8C6C0000 */  lw    $t4, ($v1)
/* 0CC75C 7F099D6C E58C018C */  swc1  $f12, 0x18c($t4)
/* 0CC760 7F099D70 8C6D0000 */  lw    $t5, ($v1)
/* 0CC764 7F099D74 E5AC0190 */  swc1  $f12, 0x190($t5)
/* 0CC768 7F099D78 8C790000 */  lw    $t9, ($v1)
/* 0CC76C 7F099D7C E7200194 */  swc1  $f0, 0x194($t9)
/* 0CC770 7F099D80 8C780000 */  lw    $t8, ($v1)
/* 0CC774 7F099D84 E7000198 */  swc1  $f0, 0x198($t8)
/* 0CC778 7F099D88 8C6B0000 */  lw    $t3, ($v1)
/* 0CC77C 7F099D8C E560019C */  swc1  $f0, 0x19c($t3)
/* 0CC780 7F099D90 8C6F0000 */  lw    $t7, ($v1)
/* 0CC784 7F099D94 ADE001A0 */  sw    $zero, 0x1a0($t7)
/* 0CC788 7F099D98 8C6E0000 */  lw    $t6, ($v1)
/* 0CC78C 7F099D9C ADC001C0 */  sw    $zero, 0x1c0($t6)
/* 0CC790 7F099DA0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC794 7F099DA4 AD8001C4 */  sw    $zero, 0x1c4($t4)
/* 0CC798 7F099DA8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC79C 7F099DAC ADA001C8 */  sw    $zero, 0x1c8($t5)
/* 0CC7A0 7F099DB0 8C790000 */  lw    $t9, ($v1)
/* 0CC7A4 7F099DB4 AF2801CC */  sw    $t0, 0x1cc($t9)
/* 0CC7A8 7F099DB8 8C780000 */  lw    $t8, ($v1)
/* 0CC7AC 7F099DBC AF0001D0 */  sw    $zero, 0x1d0($t8)
/* 0CC7B0 7F099DC0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC7B4 7F099DC4 E56001D4 */  swc1  $f0, 0x1d4($t3)
/* 0CC7B8 7F099DC8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC7BC 7F099DCC E5E001D8 */  swc1  $f0, 0x1d8($t7)
/* 0CC7C0 7F099DD0 8C6E0000 */  lw    $t6, ($v1)
/* 0CC7C4 7F099DD4 E5C801DC */  swc1  $f8, 0x1dc($t6)
/* 0CC7C8 7F099DD8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC7CC 7F099DDC E58001E0 */  swc1  $f0, 0x1e0($t4)
/* 0CC7D0 7F099DE0 8C6D0000 */  lw    $t5, ($v1)
/* 0CC7D4 7F099DE4 E5A201E4 */  swc1  $f2, 0x1e4($t5)
/* 0CC7D8 7F099DE8 8C790000 */  lw    $t9, ($v1)
/* 0CC7DC 7F099DEC E72001E8 */  swc1  $f0, 0x1e8($t9)
/* 0CC7E0 7F099DF0 8C780000 */  lw    $t8, ($v1)
/* 0CC7E4 7F099DF4 E70001EC */  swc1  $f0, 0x1ec($t8)
/* 0CC7E8 7F099DF8 8C6B0000 */  lw    $t3, ($v1)
/* 0CC7EC 7F099DFC E56001F0 */  swc1  $f0, 0x1f0($t3)
/* 0CC7F0 7F099E00 8C6F0000 */  lw    $t7, ($v1)
/* 0CC7F4 7F099E04 E5E201F4 */  swc1  $f2, 0x1f4($t7)
/* 0CC7F8 7F099E08 8C6E0000 */  lw    $t6, ($v1)
/* 0CC7FC 7F099E0C ADC00200 */  sw    $zero, 0x200($t6)
/* 0CC800 7F099E10 8C6C0000 */  lw    $t4, ($v1)
/* 0CC804 7F099E14 E5800204 */  swc1  $f0, 0x204($t4)
/* 0CC808 7F099E18 8C6D0000 */  lw    $t5, ($v1)
/* 0CC80C 7F099E1C E5A00208 */  swc1  $f0, 0x208($t5)
/* 0CC810 7F099E20 8C790000 */  lw    $t9, ($v1)
/* 0CC814 7F099E24 E720020C */  swc1  $f0, 0x20c($t9)
/* 0CC818 7F099E28 8C780000 */  lw    $t8, ($v1)
/* 0CC81C 7F099E2C E7000210 */  swc1  $f0, 0x210($t8)
/* 0CC820 7F099E30 8C6B0000 */  lw    $t3, ($v1)
/* 0CC824 7F099E34 E5600214 */  swc1  $f0, 0x214($t3)
/* 0CC828 7F099E38 8C6F0000 */  lw    $t7, ($v1)
/* 0CC82C 7F099E3C ADE00218 */  sw    $zero, 0x218($t7)
/* 0CC830 7F099E40 8C6E0000 */  lw    $t6, ($v1)
/* 0CC834 7F099E44 ADC8021C */  sw    $t0, 0x21c($t6)
/* 0CC838 7F099E48 8C6C0000 */  lw    $t4, ($v1)
/* 0CC83C 7F099E4C AD800220 */  sw    $zero, 0x220($t4)
/* 0CC840 7F099E50 8C6D0000 */  lw    $t5, ($v1)
/* 0CC844 7F099E54 E5A00224 */  swc1  $f0, 0x224($t5)
/* 0CC848 7F099E58 8C790000 */  lw    $t9, ($v1)
/* 0CC84C 7F099E5C A72003B4 */  sh    $zero, 0x3b4($t9)
/* 0CC850 7F099E60 8C780000 */  lw    $t8, ($v1)
/* 0CC854 7F099E64 A70003B6 */  sh    $zero, 0x3b6($t8)
/* 0CC858 7F099E68 8C6B0000 */  lw    $t3, ($v1)
/* 0CC85C 7F099E6C E56003B8 */  swc1  $f0, 0x3b8($t3)
/* 0CC860 7F099E70 8C6F0000 */  lw    $t7, ($v1)
/* 0CC864 7F099E74 E5E003BC */  swc1  $f0, 0x3bc($t7)
/* 0CC868 7F099E78 8C6E0000 */  lw    $t6, ($v1)
/* 0CC86C 7F099E7C C42ACCD4 */  lwc1  $f10, %lo(D_80057614)($at)
/* 0CC870 7F099E80 E5CA03C0 */  swc1  $f10, 0x3c0($t6)
/* 0CC874 7F099E84 8C6C0000 */  lw    $t4, ($v1)
/* 0CC878 7F099E88 E58003C4 */  swc1  $f0, 0x3c4($t4)
/* 0CC87C 7F099E8C 8C6D0000 */  lw    $t5, ($v1)
/* 0CC880 7F099E90 E5A003C8 */  swc1  $f0, 0x3c8($t5)
/* 0CC884 7F099E94 8C790000 */  lw    $t9, ($v1)
/* 0CC888 7F099E98 E72203CC */  swc1  $f2, 0x3cc($t9)
/* 0CC88C 7F099E9C 8C780000 */  lw    $t8, ($v1)
/* 0CC890 7F099EA0 AF0203D0 */  sw    $v0, 0x3d0($t8)
/* 0CC894 7F099EA4 8C6B0000 */  lw    $t3, ($v1)
/* 0CC898 7F099EA8 AD6203D4 */  sw    $v0, 0x3d4($t3)
/* 0CC89C 7F099EAC 8C6F0000 */  lw    $t7, ($v1)
/* 0CC8A0 7F099EB0 3C018005 */  lui   $at, %hi(D_80057618) # $at, 0x8005
/* 0CC8A4 7F099EB4 24070020 */  li    $a3, 32
/* 0CC8A8 7F099EB8 ADE203D8 */  sw    $v0, 0x3d8($t7)
/* 0CC8AC 7F099EBC 8C6E0000 */  lw    $t6, ($v1)
/* 0CC8B0 7F099EC0 240601FF */  li    $a2, 511
/* 0CC8B4 7F099EC4 24050220 */  li    $a1, 544
/* 0CC8B8 7F099EC8 E5C003DC */  swc1  $f0, 0x3dc($t6)
/* 0CC8BC 7F099ECC 8C6C0000 */  lw    $t4, ($v1)
/* 0CC8C0 7F099ED0 E58C03E0 */  swc1  $f12, 0x3e0($t4)
/* 0CC8C4 7F099ED4 8C6D0000 */  lw    $t5, ($v1)
/* 0CC8C8 7F099ED8 E5AC03E4 */  swc1  $f12, 0x3e4($t5)
/* 0CC8CC 7F099EDC 8C790000 */  lw    $t9, ($v1)
/* 0CC8D0 7F099EE0 AF2203E8 */  sw    $v0, 0x3e8($t9)
/* 0CC8D4 7F099EE4 8C780000 */  lw    $t8, ($v1)
/* 0CC8D8 7F099EE8 AF0203EC */  sw    $v0, 0x3ec($t8)
/* 0CC8DC 7F099EEC 8C6B0000 */  lw    $t3, ($v1)
/* 0CC8E0 7F099EF0 AD6203F0 */  sw    $v0, 0x3f0($t3)
/* 0CC8E4 7F099EF4 8C6F0000 */  lw    $t7, ($v1)
/* 0CC8E8 7F099EF8 ADE203F4 */  sw    $v0, 0x3f4($t7)
/* 0CC8EC 7F099EFC 8C6E0000 */  lw    $t6, ($v1)
/* 0CC8F0 7F099F00 ADC203F8 */  sw    $v0, 0x3f8($t6)
/* 0CC8F4 7F099F04 8C6C0000 */  lw    $t4, ($v1)
/* 0CC8F8 7F099F08 AD8203FC */  sw    $v0, 0x3fc($t4)
/* 0CC8FC 7F099F0C 8C6D0000 */  lw    $t5, ($v1)
/* 0CC900 7F099F10 00001025 */  move  $v0, $zero
/* 0CC904 7F099F14 E5A00400 */  swc1  $f0, 0x400($t5)
/* 0CC908 7F099F18 8C790000 */  lw    $t9, ($v1)
/* 0CC90C 7F099F1C E7200404 */  swc1  $f0, 0x404($t9)
/* 0CC910 7F099F20 8C780000 */  lw    $t8, ($v1)
/* 0CC914 7F099F24 AF00041C */  sw    $zero, 0x41c($t8)
/* 0CC918 7F099F28 8C6B0000 */  lw    $t3, ($v1)
/* 0CC91C 7F099F2C AD680420 */  sw    $t0, 0x420($t3)
/* 0CC920 7F099F30 8C6F0000 */  lw    $t7, ($v1)
/* 0CC924 7F099F34 ADE00424 */  sw    $zero, 0x424($t7)
/* 0CC928 7F099F38 8C6E0000 */  lw    $t6, ($v1)
/* 0CC92C 7F099F3C ADC00428 */  sw    $zero, 0x428($t6)
/* 0CC930 7F099F40 8C6C0000 */  lw    $t4, ($v1)
/* 0CC934 7F099F44 AD84042C */  sw    $a0, 0x42c($t4)
/* 0CC938 7F099F48 8C6D0000 */  lw    $t5, ($v1)
/* 0CC93C 7F099F4C 24040280 */  li    $a0, 640
/* 0CC940 7F099F50 ADA00430 */  sw    $zero, 0x430($t5)
/* 0CC944 7F099F54 8C790000 */  lw    $t9, ($v1)
/* 0CC948 7F099F58 AF2804DC */  sw    $t0, 0x4dc($t9)
/* 0CC94C 7F099F5C 8C780000 */  lw    $t8, ($v1)
/* 0CC950 7F099F60 AF0804E0 */  sw    $t0, 0x4e0($t8)
/* 0CC954 7F099F64 8C6B0000 */  lw    $t3, ($v1)
/* 0CC958 7F099F68 AD6804E4 */  sw    $t0, 0x4e4($t3)
/* 0CC95C 7F099F6C 8C6F0000 */  lw    $t7, ($v1)
/* 0CC960 7F099F70 ADE004E8 */  sw    $zero, 0x4e8($t7)
/* 0CC964 7F099F74 8C6E0000 */  lw    $t6, ($v1)
/* 0CC968 7F099F78 C432CCD8 */  lwc1  $f18, %lo(D_80057618)($at)
/* 0CC96C 7F099F7C 3C018005 */  lui   $at, %hi(D_8005761C) # $at, 0x8005
/* 0CC970 7F099F80 E5D204EC */  swc1  $f18, 0x4ec($t6)
/* 0CC974 7F099F84 8C6C0000 */  lw    $t4, ($v1)
/* 0CC978 7F099F88 AD8004F0 */  sw    $zero, 0x4f0($t4)
/* 0CC97C 7F099F8C 8C6D0000 */  lw    $t5, ($v1)
/* 0CC980 7F099F90 E5A204F4 */  swc1  $f2, 0x4f4($t5)
/* 0CC984 7F099F94 8C790000 */  lw    $t9, ($v1)
/* 0CC988 7F099F98 E72204F8 */  swc1  $f2, 0x4f8($t9)
/* 0CC98C 7F099F9C 8C780000 */  lw    $t8, ($v1)
/* 0CC990 7F099FA0 E70004FC */  swc1  $f0, 0x4fc($t8)
/* 0CC994 7F099FA4 8C6B0000 */  lw    $t3, ($v1)
/* 0CC998 7F099FA8 E5600500 */  swc1  $f0, 0x500($t3)
/* 0CC99C 7F099FAC 8C6F0000 */  lw    $t7, ($v1)
/* 0CC9A0 7F099FB0 E5E00504 */  swc1  $f0, 0x504($t7)
/* 0CC9A4 7F099FB4 8C6E0000 */  lw    $t6, ($v1)
/* 0CC9A8 7F099FB8 C42CCCDC */  lwc1  $f12, %lo(D_8005761C)($at)
/* 0CC9AC 7F099FBC E5C00508 */  swc1  $f0, 0x508($t6)
/* 0CC9B0 7F099FC0 8C6C0000 */  lw    $t4, ($v1)
/* 0CC9B4 7F099FC4 E580050C */  swc1  $f0, 0x50c($t4)
/* 0CC9B8 7F099FC8 8C6D0000 */  lw    $t5, ($v1)
/* 0CC9BC 7F099FCC E5A20510 */  swc1  $f2, 0x510($t5)
/* 0CC9C0 7F099FD0 8C790000 */  lw    $t9, ($v1)
/* 0CC9C4 7F099FD4 E7200514 */  swc1  $f0, 0x514($t9)
/* 0CC9C8 7F099FD8 8C780000 */  lw    $t8, ($v1)
/* 0CC9CC 7F099FDC E7020518 */  swc1  $f2, 0x518($t8)
/* 0CC9D0 7F099FE0 8C6B0000 */  lw    $t3, ($v1)
/* 0CC9D4 7F099FE4 E560051C */  swc1  $f0, 0x51c($t3)
/* 0CC9D8 7F099FE8 8C6F0000 */  lw    $t7, ($v1)
/* 0CC9DC 7F099FEC E5E00520 */  swc1  $f0, 0x520($t7)
/* 0CC9E0 7F099FF0 8C6E0000 */  lw    $t6, ($v1)
/* 0CC9E4 7F099FF4 E5C00524 */  swc1  $f0, 0x524($t6)
/* 0CC9E8 7F099FF8 8C6C0000 */  lw    $t4, ($v1)
/* 0CC9EC 7F099FFC E5800528 */  swc1  $f0, 0x528($t4)
/* 0CC9F0 7F09A000 8C6D0000 */  lw    $t5, ($v1)
/* 0CC9F4 7F09A004 E5A0052C */  swc1  $f0, 0x52c($t5)
/* 0CC9F8 7F09A008 8C790000 */  lw    $t9, ($v1)
/* 0CC9FC 7F09A00C E7200530 */  swc1  $f0, 0x530($t9)
/* 0CCA00 7F09A010 8C780000 */  lw    $t8, ($v1)
/* 0CCA04 7F09A014 E70C0534 */  swc1  $f12, 0x534($t8)
/* 0CCA08 7F09A018 8C6B0000 */  lw    $t3, ($v1)
/* 0CCA0C 7F09A01C E5600538 */  swc1  $f0, 0x538($t3)
/* 0CCA10 7F09A020 8C6F0000 */  lw    $t7, ($v1)
/* 0CCA14 7F09A024 E5EC053C */  swc1  $f12, 0x53c($t7)
/* 0CCA18 7F09A028 8C6E0000 */  lw    $t6, ($v1)
/* 0CCA1C 7F09A02C E5C00540 */  swc1  $f0, 0x540($t6)
/* 0CCA20 7F09A030 8C6C0000 */  lw    $t4, ($v1)
/* 0CCA24 7F09A034 E5800544 */  swc1  $f0, 0x544($t4)
/* 0CCA28 7F09A038 8C6D0000 */  lw    $t5, ($v1)
/* 0CCA2C 7F09A03C E5A00548 */  swc1  $f0, 0x548($t5)
/* 0CCA30 7F09A040 8C790000 */  lw    $t9, ($v1)
/* 0CCA34 7F09A044 E720054C */  swc1  $f0, 0x54c($t9)
/* 0CCA38 7F09A048 8C780000 */  lw    $t8, ($v1)
/* 0CCA3C 7F09A04C E7000550 */  swc1  $f0, 0x550($t8)
/* 0CCA40 7F09A050 8C6B0000 */  lw    $t3, ($v1)
/* 0CCA44 7F09A054 E5600554 */  swc1  $f0, 0x554($t3)
/* 0CCA48 7F09A058 8C6F0000 */  lw    $t7, ($v1)
/* 0CCA4C 7F09A05C E5E00558 */  swc1  $f0, 0x558($t7)
/* 0CCA50 7F09A060 8C6E0000 */  lw    $t6, ($v1)
/* 0CCA54 7F09A064 E5C0055C */  swc1  $f0, 0x55c($t6)
/* 0CCA58 7F09A068 8C6C0000 */  lw    $t4, ($v1)
/* 0CCA5C 7F09A06C E5800560 */  swc1  $f0, 0x560($t4)
/* 0CCA60 7F09A070 8C6D0000 */  lw    $t5, ($v1)
/* 0CCA64 7F09A074 E5A00564 */  swc1  $f0, 0x564($t5)
/* 0CCA68 7F09A078 8C790000 */  lw    $t9, ($v1)
/* 0CCA6C 7F09A07C E7200568 */  swc1  $f0, 0x568($t9)
/* 0CCA70 7F09A080 8C780000 */  lw    $t8, ($v1)
/* 0CCA74 7F09A084 E702056C */  swc1  $f2, 0x56c($t8)
/* 0CCA78 7F09A088 8C6B0000 */  lw    $t3, ($v1)
/* 0CCA7C 7F09A08C E5600570 */  swc1  $f0, 0x570($t3)
/* 0CCA80 7F09A090 8C6F0000 */  lw    $t7, ($v1)
/* 0CCA84 7F09A094 E5E00574 */  swc1  $f0, 0x574($t7)
/* 0CCA88 7F09A098 8C6E0000 */  lw    $t6, ($v1)
/* 0CCA8C 7F09A09C E5C20578 */  swc1  $f2, 0x578($t6)
/* 0CCA90 7F09A0A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CCA94 7F09A0A4 E580057C */  swc1  $f0, 0x57c($t4)
/* 0CCA98 7F09A0A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CCA9C 7F09A0AC E5A20580 */  swc1  $f2, 0x580($t5)
/* 0CCAA0 7F09A0B0 8C790000 */  lw    $t9, ($v1)
/* 0CCAA4 7F09A0B4 E7200584 */  swc1  $f0, 0x584($t9)
/* 0CCAA8 7F09A0B8 8C780000 */  lw    $t8, ($v1)
/* 0CCAAC 7F09A0BC E7000588 */  swc1  $f0, 0x588($t8)
/* 0CCAB0 7F09A0C0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCAB4 7F09A0C4 E562058C */  swc1  $f2, 0x58c($t3)
/* 0CCAB8 7F09A0C8 8C6F0000 */  lw    $t7, ($v1)
/* 0CCABC 7F09A0CC E5E00590 */  swc1  $f0, 0x590($t7)
/* 0CCAC0 7F09A0D0 8C6E0000 */  lw    $t6, ($v1)
/* 0CCAC4 7F09A0D4 ADC00594 */  sw    $zero, 0x594($t6)
.L7F09A0D8:
/* 0CCAC8 7F09A0D8 8C6C0000 */  lw    $t4, ($v1)
/* 0CCACC 7F09A0DC 01826821 */  addu  $t5, $t4, $v0
/* 0CCAD0 7F09A0E0 A5A407D0 */  sh    $a0, 0x7d0($t5)
/* 0CCAD4 7F09A0E4 8C790000 */  lw    $t9, ($v1)
/* 0CCAD8 7F09A0E8 0322C021 */  addu  $t8, $t9, $v0
/* 0CCADC 7F09A0EC A70507D2 */  sh    $a1, 0x7d2($t8)
/* 0CCAE0 7F09A0F0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCAE4 7F09A0F4 01627821 */  addu  $t7, $t3, $v0
/* 0CCAE8 7F09A0F8 A5E607D4 */  sh    $a2, 0x7d4($t7)
/* 0CCAEC 7F09A0FC 8C6E0000 */  lw    $t6, ($v1)
/* 0CCAF0 7F09A100 01C26021 */  addu  $t4, $t6, $v0
/* 0CCAF4 7F09A104 A58007D6 */  sh    $zero, 0x7d6($t4)
/* 0CCAF8 7F09A108 8C6D0000 */  lw    $t5, ($v1)
/* 0CCAFC 7F09A10C 01A2C821 */  addu  $t9, $t5, $v0
/* 0CCB00 7F09A110 A72407D8 */  sh    $a0, 0x7d8($t9)
/* 0CCB04 7F09A114 8C780000 */  lw    $t8, ($v1)
/* 0CCB08 7F09A118 03025821 */  addu  $t3, $t8, $v0
/* 0CCB0C 7F09A11C A56507DA */  sh    $a1, 0x7da($t3)
/* 0CCB10 7F09A120 8C6F0000 */  lw    $t7, ($v1)
/* 0CCB14 7F09A124 01E27021 */  addu  $t6, $t7, $v0
/* 0CCB18 7F09A128 A5C607DC */  sh    $a2, 0x7dc($t6)
/* 0CCB1C 7F09A12C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCB20 7F09A130 01826821 */  addu  $t5, $t4, $v0
/* 0CCB24 7F09A134 24420010 */  addiu $v0, $v0, 0x10
/* 0CCB28 7F09A138 1447FFE7 */  bne   $v0, $a3, .L7F09A0D8
/* 0CCB2C 7F09A13C A5A007DE */   sh    $zero, 0x7de($t5)
/* 0CCB30 7F09A140 8C790000 */  lw    $t9, ($v1)
/* 0CCB34 7F09A144 24020064 */  li    $v0, 100
/* 0CCB38 7F09A148 A72207F0 */  sh    $v0, 0x7f0($t9)
/* 0CCB3C 7F09A14C 8C780000 */  lw    $t8, ($v1)
/* 0CCB40 7F09A150 A70207F2 */  sh    $v0, 0x7f2($t8)
/* 0CCB44 7F09A154 8C6B0000 */  lw    $t3, ($v1)
/* 0CCB48 7F09A158 A56007F4 */  sh    $zero, 0x7f4($t3)
/* 0CCB4C 7F09A15C 8C6F0000 */  lw    $t7, ($v1)
/* 0CCB50 7F09A160 A5E007F6 */  sh    $zero, 0x7f6($t7)
/* 0CCB54 7F09A164 8C6E0000 */  lw    $t6, ($v1)
/* 0CCB58 7F09A168 ADC007F8 */  sw    $zero, 0x7f8($t6)
/* 0CCB5C 7F09A16C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCB60 7F09A170 AD8007FC */  sw    $zero, 0x7fc($t4)
/* 0CCB64 7F09A174 8C6D0000 */  lw    $t5, ($v1)
/* 0CCB68 7F09A178 ADA00800 */  sw    $zero, 0x800($t5)
/* 0CCB6C 7F09A17C 8C790000 */  lw    $t9, ($v1)
/* 0CCB70 7F09A180 AF200804 */  sw    $zero, 0x804($t9)
/* 0CCB74 7F09A184 8C780000 */  lw    $t8, ($v1)
/* 0CCB78 7F09A188 AF092A3C */  sw    $t1, 0x2a3c($t8)
/* 0CCB7C 7F09A18C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCB80 7F09A190 0140C025 */  move  $t8, $t2
/* 0CCB84 7F09A194 AD692A40 */  sw    $t1, 0x2a40($t3)
/* 0CCB88 7F09A198 8C6F0000 */  lw    $t7, ($v1)
/* 0CCB8C 7F09A19C 254B03A8 */  addiu $t3, $t2, 0x3a8
/* 0CCB90 7F09A1A0 ADE02A48 */  sw    $zero, 0x2a48($t7)
/* 0CCB94 7F09A1A4 8C6E0000 */  lw    $t6, ($v1)
/* 0CCB98 7F09A1A8 01407825 */  move  $t7, $t2
/* 0CCB9C 7F09A1AC ADC02A4C */  sw    $zero, 0x2a4c($t6)
/* 0CCBA0 7F09A1B0 8C6C0000 */  lw    $t4, ($v1)
/* 0CCBA4 7F09A1B4 AD800808 */  sw    $zero, 0x808($t4)
/* 0CCBA8 7F09A1B8 8C6D0000 */  lw    $t5, ($v1)
/* 0CCBAC 7F09A1BC ADA0080C */  sw    $zero, 0x80c($t5)
/* 0CCBB0 7F09A1C0 8C790000 */  lw    $t9, ($v1)
.L7F09A1C4:
/* 0CCBB4 7F09A1C4 8DE10000 */  lw    $at, ($t7)
/* 0CCBB8 7F09A1C8 25EF000C */  addiu $t7, $t7, 0xc
/* 0CCBBC 7F09A1CC 2739000C */  addiu $t9, $t9, 0xc
/* 0CCBC0 7F09A1D0 AF21085C */  sw    $at, 0x85c($t9)
/* 0CCBC4 7F09A1D4 8DE1FFF8 */  lw    $at, -8($t7)
/* 0CCBC8 7F09A1D8 AF210860 */  sw    $at, 0x860($t9)
/* 0CCBCC 7F09A1DC 8DE1FFFC */  lw    $at, -4($t7)
/* 0CCBD0 7F09A1E0 15EBFFF8 */  bne   $t7, $t3, .L7F09A1C4
/* 0CCBD4 7F09A1E4 AF210864 */   sw    $at, 0x864($t9)
/* 0CCBD8 7F09A1E8 8C6E0000 */  lw    $t6, ($v1)
/* 0CCBDC 7F09A1EC 254D03A8 */  addiu $t5, $t2, 0x3a8
.L7F09A1F0:
/* 0CCBE0 7F09A1F0 8F010000 */  lw    $at, ($t8)
/* 0CCBE4 7F09A1F4 2718000C */  addiu $t8, $t8, 0xc
/* 0CCBE8 7F09A1F8 25CE000C */  addiu $t6, $t6, 0xc
/* 0CCBEC 7F09A1FC ADC10C04 */  sw    $at, 0xc04($t6)
/* 0CCBF0 7F09A200 8F01FFF8 */  lw    $at, -8($t8)
/* 0CCBF4 7F09A204 ADC10C08 */  sw    $at, 0xc08($t6)
/* 0CCBF8 7F09A208 8F01FFFC */  lw    $at, -4($t8)
/* 0CCBFC 7F09A20C 170DFFF8 */  bne   $t8, $t5, .L7F09A1F0
/* 0CCC00 7F09A210 ADC10C0C */   sw    $at, 0xc0c($t6)
/* 0CCC04 7F09A214 8C6B0000 */  lw    $t3, ($v1)
/* 0CCC08 7F09A218 3C018005 */  lui   $at, %hi(D_80057620) # $at, 0x8005
/* 0CCC0C 7F09A21C 240200FF */  li    $v0, 255
/* 0CCC10 7F09A220 E5620FB8 */  swc1  $f2, 0xfb8($t3)
/* 0CCC14 7F09A224 8C6F0000 */  lw    $t7, ($v1)
/* 0CCC18 7F09A228 24040007 */  li    $a0, 7
/* 0CCC1C 7F09A22C E5E20FBC */  swc1  $f2, 0xfbc($t7)
/* 0CCC20 7F09A230 8C790000 */  lw    $t9, ($v1)
/* 0CCC24 7F09A234 AF200FC0 */  sw    $zero, 0xfc0($t9)
/* 0CCC28 7F09A238 8C6C0000 */  lw    $t4, ($v1)
/* 0CCC2C 7F09A23C AD800FC4 */  sw    $zero, 0xfc4($t4)
/* 0CCC30 7F09A240 8C6D0000 */  lw    $t5, ($v1)
/* 0CCC34 7F09A244 C42CCCE0 */  lwc1  $f12, %lo(D_80057620)($at)
/* 0CCC38 7F09A248 3C014270 */  li    $at, 0x42700000 # 60.000000
/* 0CCC3C 7F09A24C ADA00FC8 */  sw    $zero, 0xfc8($t5)
/* 0CCC40 7F09A250 8C780000 */  lw    $t8, ($v1)
/* 0CCC44 7F09A254 AF000FCC */  sw    $zero, 0xfcc($t8)
/* 0CCC48 7F09A258 8C6E0000 */  lw    $t6, ($v1)
/* 0CCC4C 7F09A25C ADC00FD0 */  sw    $zero, 0xfd0($t6)
/* 0CCC50 7F09A260 8C6B0000 */  lw    $t3, ($v1)
/* 0CCC54 7F09A264 A1620FD4 */  sb    $v0, 0xfd4($t3)
/* 0CCC58 7F09A268 8C6F0000 */  lw    $t7, ($v1)
/* 0CCC5C 7F09A26C A1E20FD5 */  sb    $v0, 0xfd5($t7)
/* 0CCC60 7F09A270 8C790000 */  lw    $t9, ($v1)
/* 0CCC64 7F09A274 A3220FD6 */  sb    $v0, 0xfd6($t9)
/* 0CCC68 7F09A278 8C6C0000 */  lw    $t4, ($v1)
/* 0CCC6C 7F09A27C 3C028007 */  lui   $v0, %hi(random_byte) # $v0, 0x8007
/* 0CCC70 7F09A280 24428BCC */  addiu $v0, %lo(random_byte) # addiu $v0, $v0, -0x7434
/* 0CCC74 7F09A284 A1800FD7 */  sb    $zero, 0xfd7($t4)
/* 0CCC78 7F09A288 8C6D0000 */  lw    $t5, ($v1)
/* 0CCC7C 7F09A28C ADA80FD8 */  sw    $t0, 0xfd8($t5)
/* 0CCC80 7F09A290 8C780000 */  lw    $t8, ($v1)
/* 0CCC84 7F09A294 AF000FDC */  sw    $zero, 0xfdc($t8)
/* 0CCC88 7F09A298 8C6E0000 */  lw    $t6, ($v1)
/* 0CCC8C 7F09A29C E5C00FE0 */  swc1  $f0, 0xfe0($t6)
/* 0CCC90 7F09A2A0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCC94 7F09A2A4 E5600FE4 */  swc1  $f0, 0xfe4($t3)
/* 0CCC98 7F09A2A8 8C6F0000 */  lw    $t7, ($v1)
/* 0CCC9C 7F09A2AC E5E00FE8 */  swc1  $f0, 0xfe8($t7)
/* 0CCCA0 7F09A2B0 8C790000 */  lw    $t9, ($v1)
/* 0CCCA4 7F09A2B4 E7200FEC */  swc1  $f0, 0xfec($t9)
/* 0CCCA8 7F09A2B8 8C6C0000 */  lw    $t4, ($v1)
/* 0CCCAC 7F09A2BC E58C0FF0 */  swc1  $f12, 0xff0($t4)
/* 0CCCB0 7F09A2C0 8C6D0000 */  lw    $t5, ($v1)
/* 0CCCB4 7F09A2C4 E5A00FF4 */  swc1  $f0, 0xff4($t5)
/* 0CCCB8 7F09A2C8 8C780000 */  lw    $t8, ($v1)
/* 0CCCBC 7F09A2CC E7000FF8 */  swc1  $f0, 0xff8($t8)
/* 0CCCC0 7F09A2D0 8C6E0000 */  lw    $t6, ($v1)
/* 0CCCC4 7F09A2D4 E5C00FFC */  swc1  $f0, 0xffc($t6)
/* 0CCCC8 7F09A2D8 8C6B0000 */  lw    $t3, ($v1)
/* 0CCCCC 7F09A2DC E5601000 */  swc1  $f0, 0x1000($t3)
/* 0CCCD0 7F09A2E0 8C6F0000 */  lw    $t7, ($v1)
/* 0CCCD4 7F09A2E4 E5EC1004 */  swc1  $f12, 0x1004($t7)
/* 0CCCD8 7F09A2E8 44816000 */  mtc1  $at, $f12
/* 0CCCDC 7F09A2EC 8C790000 */  lw    $t9, ($v1)
/* 0CCCE0 7F09A2F0 3C0143A0 */  li    $at, 0x43A00000 # 320.000000
/* 0CCCE4 7F09A2F4 44817000 */  mtc1  $at, $f14
/* 0CCCE8 7F09A2F8 3C014388 */  li    $at, 0x43880000 # 272.000000
/* 0CCCEC 7F09A2FC 44818000 */  mtc1  $at, $f16
/* 0CCCF0 7F09A300 E7201008 */  swc1  $f0, 0x1008($t9)
/* 0CCCF4 7F09A304 3C018005 */  lui   $at, %hi(D_80057624) # $at, 0x8005
/* 0CCCF8 7F09A308 C424CCE4 */  lwc1  $f4, %lo(D_80057624)($at)
/* 0CCCFC 7F09A30C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCD00 7F09A310 3C014120 */  li    $at, 0x41200000 # 10.000000
/* 0CCD04 7F09A314 44813000 */  mtc1  $at, $f6
/* 0CCD08 7F09A318 E584100C */  swc1  $f4, 0x100c($t4)
/* 0CCD0C 7F09A31C 8C6D0000 */  lw    $t5, ($v1)
/* 0CCD10 7F09A320 3C014238 */  li    $at, 0x42380000 # 46.000000
/* 0CCD14 7F09A324 44814000 */  mtc1  $at, $f8
/* 0CCD18 7F09A328 E5A01010 */  swc1  $f0, 0x1010($t5)
/* 0CCD1C 7F09A32C 8C780000 */  lw    $t8, ($v1)
/* 0CCD20 7F09A330 3C014320 */  li    $at, 0x43200000 # 160.000000
/* 0CCD24 7F09A334 44815000 */  mtc1  $at, $f10
/* 0CCD28 7F09A338 AF001054 */  sw    $zero, 0x1054($t8)
/* 0CCD2C 7F09A33C 8C6E0000 */  lw    $t6, ($v1)
/* 0CCD30 7F09A340 3C014308 */  li    $at, 0x43080000 # 136.000000
/* 0CCD34 7F09A344 44819000 */  mtc1  $at, $f18
/* 0CCD38 7F09A348 ADC01058 */  sw    $zero, 0x1058($t6)
/* 0CCD3C 7F09A34C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCD40 7F09A350 3C018005 */  lui   $at, %hi(D_80057628) # $at, 0x8005
/* 0CCD44 7F09A354 AD60105C */  sw    $zero, 0x105c($t3)
/* 0CCD48 7F09A358 8C6F0000 */  lw    $t7, ($v1)
/* 0CCD4C 7F09A35C E5E01064 */  swc1  $f0, 0x1064($t7)
/* 0CCD50 7F09A360 8C790000 */  lw    $t9, ($v1)
/* 0CCD54 7F09A364 E7201068 */  swc1  $f0, 0x1068($t9)
/* 0CCD58 7F09A368 8C6C0000 */  lw    $t4, ($v1)
/* 0CCD5C 7F09A36C E580106C */  swc1  $f0, 0x106c($t4)
/* 0CCD60 7F09A370 8C6D0000 */  lw    $t5, ($v1)
/* 0CCD64 7F09A374 ADA01070 */  sw    $zero, 0x1070($t5)
/* 0CCD68 7F09A378 8C780000 */  lw    $t8, ($v1)
/* 0CCD6C 7F09A37C E7001074 */  swc1  $f0, 0x1074($t8)
/* 0CCD70 7F09A380 8C6E0000 */  lw    $t6, ($v1)
/* 0CCD74 7F09A384 E5C01078 */  swc1  $f0, 0x1078($t6)
/* 0CCD78 7F09A388 8C6B0000 */  lw    $t3, ($v1)
/* 0CCD7C 7F09A38C E56C107C */  swc1  $f12, 0x107c($t3)
/* 0CCD80 7F09A390 8C6F0000 */  lw    $t7, ($v1)
/* 0CCD84 7F09A394 E5EC1080 */  swc1  $f12, 0x1080($t7)
/* 0CCD88 7F09A398 8C790000 */  lw    $t9, ($v1)
/* 0CCD8C 7F09A39C AF291084 */  sw    $t1, 0x1084($t9)
/* 0CCD90 7F09A3A0 8C6C0000 */  lw    $t4, ($v1)
/* 0CCD94 7F09A3A4 E58E1088 */  swc1  $f14, 0x1088($t4)
/* 0CCD98 7F09A3A8 8C6D0000 */  lw    $t5, ($v1)
/* 0CCD9C 7F09A3AC E5B0108C */  swc1  $f16, 0x108c($t5)
/* 0CCDA0 7F09A3B0 8C780000 */  lw    $t8, ($v1)
/* 0CCDA4 7F09A3B4 E7001090 */  swc1  $f0, 0x1090($t8)
/* 0CCDA8 7F09A3B8 8C6E0000 */  lw    $t6, ($v1)
/* 0CCDAC 7F09A3BC E5C01094 */  swc1  $f0, 0x1094($t6)
/* 0CCDB0 7F09A3C0 8C6B0000 */  lw    $t3, ($v1)
/* 0CCDB4 7F09A3C4 E5661098 */  swc1  $f6, 0x1098($t3)
/* 0CCDB8 7F09A3C8 8C6F0000 */  lw    $t7, ($v1)
/* 0CCDBC 7F09A3CC E5E8109C */  swc1  $f8, 0x109c($t7)
/* 0CCDC0 7F09A3D0 8C790000 */  lw    $t9, ($v1)
/* 0CCDC4 7F09A3D4 E72210A0 */  swc1  $f2, 0x10a0($t9)
/* 0CCDC8 7F09A3D8 8C6C0000 */  lw    $t4, ($v1)
/* 0CCDCC 7F09A3DC E58A10A4 */  swc1  $f10, 0x10a4($t4)
/* 0CCDD0 7F09A3E0 8C6D0000 */  lw    $t5, ($v1)
/* 0CCDD4 7F09A3E4 E5B210A8 */  swc1  $f18, 0x10a8($t5)
/* 0CCDD8 7F09A3E8 8C780000 */  lw    $t8, ($v1)
/* 0CCDDC 7F09A3EC E70210AC */  swc1  $f2, 0x10ac($t8)
/* 0CCDE0 7F09A3F0 8C6E0000 */  lw    $t6, ($v1)
/* 0CCDE4 7F09A3F4 E5C210B0 */  swc1  $f2, 0x10b0($t6)
/* 0CCDE8 7F09A3F8 8C6B0000 */  lw    $t3, ($v1)
/* 0CCDEC 7F09A3FC E56210B4 */  swc1  $f2, 0x10b4($t3)
/* 0CCDF0 7F09A400 8C6F0000 */  lw    $t7, ($v1)
/* 0CCDF4 7F09A404 E5E210B8 */  swc1  $f2, 0x10b8($t7)
/* 0CCDF8 7F09A408 8C790000 */  lw    $t9, ($v1)
/* 0CCDFC 7F09A40C AF2010BC */  sw    $zero, 0x10bc($t9)
/* 0CCE00 7F09A410 8C6C0000 */  lw    $t4, ($v1)
/* 0CCE04 7F09A414 AD8010C0 */  sw    $zero, 0x10c0($t4)
/* 0CCE08 7F09A418 8C6D0000 */  lw    $t5, ($v1)
/* 0CCE0C 7F09A41C ADA010C4 */  sw    $zero, 0x10c4($t5)
/* 0CCE10 7F09A420 8C780000 */  lw    $t8, ($v1)
/* 0CCE14 7F09A424 AF0010C8 */  sw    $zero, 0x10c8($t8)
/* 0CCE18 7F09A428 8C6E0000 */  lw    $t6, ($v1)
/* 0CCE1C 7F09A42C ADC010CC */  sw    $zero, 0x10cc($t6)
/* 0CCE20 7F09A430 8C6B0000 */  lw    $t3, ($v1)
/* 0CCE24 7F09A434 AD6010D0 */  sw    $zero, 0x10d0($t3)
/* 0CCE28 7F09A438 8C6F0000 */  lw    $t7, ($v1)
/* 0CCE2C 7F09A43C ADE010D4 */  sw    $zero, 0x10d4($t7)
/* 0CCE30 7F09A440 8C790000 */  lw    $t9, ($v1)
/* 0CCE34 7F09A444 AF2010D8 */  sw    $zero, 0x10d8($t9)
/* 0CCE38 7F09A448 8C6C0000 */  lw    $t4, ($v1)
/* 0CCE3C 7F09A44C 3C190001 */  lui   $t9, 1
/* 0CCE40 7F09A450 AD8010DC */  sw    $zero, 0x10dc($t4)
/* 0CCE44 7F09A454 8C6D0000 */  lw    $t5, ($v1)
/* 0CCE48 7F09A458 ADA010E0 */  sw    $zero, 0x10e0($t5)
/* 0CCE4C 7F09A45C 8C780000 */  lw    $t8, ($v1)
/* 0CCE50 7F09A460 AF0010E4 */  sw    $zero, 0x10e4($t8)
/* 0CCE54 7F09A464 8C6E0000 */  lw    $t6, ($v1)
/* 0CCE58 7F09A468 E5C210E8 */  swc1  $f2, 0x10e8($t6)
/* 0CCE5C 7F09A46C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCE60 7F09A470 E56210EC */  swc1  $f2, 0x10ec($t3)
/* 0CCE64 7F09A474 8C6F0000 */  lw    $t7, ($v1)
/* 0CCE68 7F09A478 E5E210F0 */  swc1  $f2, 0x10f0($t7)
/* 0CCE6C 7F09A47C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCE70 7F09A480 AD9910F4 */  sw    $t9, 0x10f4($t4)
/* 0CCE74 7F09A484 8C6D0000 */  lw    $t5, ($v1)
/* 0CCE78 7F09A488 E5A01110 */  swc1  $f0, 0x1110($t5)
/* 0CCE7C 7F09A48C 8C780000 */  lw    $t8, ($v1)
/* 0CCE80 7F09A490 E7001114 */  swc1  $f0, 0x1114($t8)
/* 0CCE84 7F09A494 8C6E0000 */  lw    $t6, ($v1)
/* 0CCE88 7F09A498 E5CE1118 */  swc1  $f14, 0x1118($t6)
/* 0CCE8C 7F09A49C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCE90 7F09A4A0 E570111C */  swc1  $f16, 0x111c($t3)
/* 0CCE94 7F09A4A4 8C6F0000 */  lw    $t7, ($v1)
/* 0CCE98 7F09A4A8 ADE01120 */  sw    $zero, 0x1120($t7)
/* 0CCE9C 7F09A4AC 8C790000 */  lw    $t9, ($v1)
/* 0CCEA0 7F09A4B0 AF2011A8 */  sw    $zero, 0x11a8($t9)
/* 0CCEA4 7F09A4B4 8C6C0000 */  lw    $t4, ($v1)
/* 0CCEA8 7F09A4B8 AD8011AC */  sw    $zero, 0x11ac($t4)
/* 0CCEAC 7F09A4BC 8C6D0000 */  lw    $t5, ($v1)
/* 0CCEB0 7F09A4C0 ADA011B0 */  sw    $zero, 0x11b0($t5)
/* 0CCEB4 7F09A4C4 8C780000 */  lw    $t8, ($v1)
/* 0CCEB8 7F09A4C8 E70011B4 */  swc1  $f0, 0x11b4($t8)
/* 0CCEBC 7F09A4CC 8C6E0000 */  lw    $t6, ($v1)
/* 0CCEC0 7F09A4D0 E5C011B8 */  swc1  $f0, 0x11b8($t6)
/* 0CCEC4 7F09A4D4 8C6B0000 */  lw    $t3, ($v1)
/* 0CCEC8 7F09A4D8 E56C11BC */  swc1  $f12, 0x11bc($t3)
/* 0CCECC 7F09A4DC 8C6F0000 */  lw    $t7, ($v1)
/* 0CCED0 7F09A4E0 E5EC11C0 */  swc1  $f12, 0x11c0($t7)
/* 0CCED4 7F09A4E4 8C790000 */  lw    $t9, ($v1)
/* 0CCED8 7F09A4E8 E72C11C4 */  swc1  $f12, 0x11c4($t9)
/* 0CCEDC 7F09A4EC 8C6C0000 */  lw    $t4, ($v1)
/* 0CCEE0 7F09A4F0 E58C11C8 */  swc1  $f12, 0x11c8($t4)
/* 0CCEE4 7F09A4F4 8C6D0000 */  lw    $t5, ($v1)
/* 0CCEE8 7F09A4F8 C424CCE8 */  lwc1  $f4, %lo(D_80057628)($at)
/* 0CCEEC 7F09A4FC 3C018003 */  lui   $at, %hi(g_VisibleToGuardsFlag) # $at, 0x8003
/* 0CCEF0 7F09A500 E5A411CC */  swc1  $f4, 0x11cc($t5)
/* 0CCEF4 7F09A504 8C780000 */  lw    $t8, ($v1)
/* 0CCEF8 7F09A508 AF0011D0 */  sw    $zero, 0x11d0($t8)
/* 0CCEFC 7F09A50C 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF00 7F09A510 ADC911D4 */  sw    $t1, 0x11d4($t6)
/* 0CCF04 7F09A514 8C6B0000 */  lw    $t3, ($v1)
/* 0CCF08 7F09A518 AD6011D8 */  sw    $zero, 0x11d8($t3)
/* 0CCF0C 7F09A51C 8C6F0000 */  lw    $t7, ($v1)
/* 0CCF10 7F09A520 ADE011DC */  sw    $zero, 0x11dc($t7)
/* 0CCF14 7F09A524 8C790000 */  lw    $t9, ($v1)
/* 0CCF18 7F09A528 AF2011E0 */  sw    $zero, 0x11e0($t9)
/* 0CCF1C 7F09A52C 8C6C0000 */  lw    $t4, ($v1)
/* 0CCF20 7F09A530 AD8011E4 */  sw    $zero, 0x11e4($t4)
/* 0CCF24 7F09A534 8C6D0000 */  lw    $t5, ($v1)
/* 0CCF28 7F09A538 ADA011E8 */  sw    $zero, 0x11e8($t5)
/* 0CCF2C 7F09A53C 8C780000 */  lw    $t8, ($v1)
/* 0CCF30 7F09A540 AF0011EC */  sw    $zero, 0x11ec($t8)
/* 0CCF34 7F09A544 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF38 7F09A548 E5C01278 */  swc1  $f0, 0x1278($t6)
/* 0CCF3C 7F09A54C 8C6B0000 */  lw    $t3, ($v1)
/* 0CCF40 7F09A550 AD60127C */  sw    $zero, 0x127c($t3)
/* 0CCF44 7F09A554 8C6F0000 */  lw    $t7, ($v1)
/* 0CCF48 7F09A558 E5E01280 */  swc1  $f0, 0x1280($t7)
/* 0CCF4C 7F09A55C 8C790000 */  lw    $t9, ($v1)
/* 0CCF50 7F09A560 A32012AE */  sb    $zero, 0x12ae($t9)
/* 0CCF54 7F09A564 8C6C0000 */  lw    $t4, ($v1)
/* 0CCF58 7F09A568 AD8429B0 */  sw    $a0, 0x29b0($t4)
/* 0CCF5C 7F09A56C 8C6D0000 */  lw    $t5, ($v1)
/* 0CCF60 7F09A570 E5A229B4 */  swc1  $f2, 0x29b4($t5)
/* 0CCF64 7F09A574 8C780000 */  lw    $t8, ($v1)
/* 0CCF68 7F09A578 E70029B8 */  swc1  $f0, 0x29b8($t8)
/* 0CCF6C 7F09A57C 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF70 7F09A580 ADC029BC */  sw    $zero, 0x29bc($t6)
/* 0CCF74 7F09A584 8C6B0000 */  lw    $t3, ($v1)
/* 0CCF78 7F09A588 AD6429CC */  sw    $a0, 0x29cc($t3)
/* 0CCF7C 7F09A58C 8C6F0000 */  lw    $t7, ($v1)
/* 0CCF80 7F09A590 ADE029D0 */  sw    $zero, 0x29d0($t7)
/* 0CCF84 7F09A594 8C6C0000 */  lw    $t4, ($v1)
/* 0CCF88 7F09A598 8C590000 */  lw    $t9, ($v0)
/* 0CCF8C 7F09A59C AD9929D8 */  sw    $t9, 0x29d8($t4)
/* 0CCF90 7F09A5A0 8C4D0000 */  lw    $t5, ($v0)
/* 0CCF94 7F09A5A4 8C6E0000 */  lw    $t6, ($v1)
/* 0CCF98 7F09A5A8 25B80001 */  addiu $t8, $t5, 1
/* 0CCF9C 7F09A5AC AC580000 */  sw    $t8, ($v0)
/* 0CCFA0 7F09A5B0 ADC929DC */  sw    $t1, 0x29dc($t6)
/* 0CCFA4 7F09A5B4 8C6B0000 */  lw    $t3, ($v1)
/* 0CCFA8 7F09A5B8 AD6929E0 */  sw    $t1, 0x29e0($t3)
/* 0CCFAC 7F09A5BC 8C6F0000 */  lw    $t7, ($v1)
/* 0CCFB0 7F09A5C0 ADE929E4 */  sw    $t1, 0x29e4($t7)
/* 0CCFB4 7F09A5C4 8C790000 */  lw    $t9, ($v1)
/* 0CCFB8 7F09A5C8 AF2929E8 */  sw    $t1, 0x29e8($t9)
/* 0CCFBC 7F09A5CC 8C6C0000 */  lw    $t4, ($v1)
/* 0CCFC0 7F09A5D0 AD8029F8 */  sw    $zero, 0x29f8($t4)
/* 0CCFC4 7F09A5D4 8C6D0000 */  lw    $t5, ($v1)
/* 0CCFC8 7F09A5D8 ADA02A28 */  sw    $zero, 0x2a28($t5)
/* 0CCFCC 7F09A5DC 8C780000 */  lw    $t8, ($v1)
/* 0CCFD0 7F09A5E0 AF002A2C */  sw    $zero, 0x2a2c($t8)
/* 0CCFD4 7F09A5E4 8C6E0000 */  lw    $t6, ($v1)
/* 0CCFD8 7F09A5E8 ADC82A30 */  sw    $t0, 0x2a30($t6)
/* 0CCFDC 7F09A5EC 8C6B0000 */  lw    $t3, ($v1)
/* 0CCFE0 7F09A5F0 E5622A34 */  swc1  $f2, 0x2a34($t3)
/* 0CCFE4 7F09A5F4 8C6F0000 */  lw    $t7, ($v1)
/* 0CCFE8 7F09A5F8 E5E22A38 */  swc1  $f2, 0x2a38($t7)
/* 0CCFEC 7F09A5FC 8C790000 */  lw    $t9, ($v1)
/* 0CCFF0 7F09A600 AF202A50 */  sw    $zero, 0x2a50($t9)
/* 0CCFF4 7F09A604 8C6C0000 */  lw    $t4, ($v1)
/* 0CCFF8 7F09A608 AD802A54 */  sw    $zero, 0x2a54($t4)
/* 0CCFFC 7F09A60C 8C6D0000 */  lw    $t5, ($v1)
/* 0CD000 7F09A610 E5A02A58 */  swc1  $f0, 0x2a58($t5)
/* 0CD004 7F09A614 8C780000 */  lw    $t8, ($v1)
/* 0CD008 7F09A618 AF002A5C */  sw    $zero, 0x2a5c($t8)
/* 0CD00C 7F09A61C 8C6E0000 */  lw    $t6, ($v1)
/* 0CD010 7F09A620 ADC82A60 */  sw    $t0, 0x2a60($t6)
/* 0CD014 7F09A624 8C6B0000 */  lw    $t3, ($v1)
/* 0CD018 7F09A628 AD602A64 */  sw    $zero, 0x2a64($t3)
/* 0CD01C 7F09A62C 8C6F0000 */  lw    $t7, ($v1)
/* 0CD020 7F09A630 ADE02A68 */  sw    $zero, 0x2a68($t7)
/* 0CD024 7F09A634 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CD028 7F09A638 AC281A14 */  sw    $t0, %lo(g_VisibleToGuardsFlag)($at)
/* 0CD02C 7F09A63C 3C018003 */  lui   $at, %hi(obj_collision_flag) # $at, 0x8003
/* 0CD030 7F09A640 AC281A18 */  sw    $t0, %lo(obj_collision_flag)($at)
/* 0CD034 7F09A644 03E00008 */  jr    $ra
/* 0CD038 7F09A648 27BD03D0 */   addiu $sp, $sp, 0x3d0
)
#endif

#endif


void set_cur_player(s32 playernum)
{
    player_num = playernum;
    g_CurrentPlayer = g_playerPointers[playernum];
    g_playerPerm = &g_playerPlayerData[playernum];
}


s32 get_cur_playernum(void) {
    return player_num;
}


s32 sub_GAME_7F09B15C( PropRecord* prop)
{
    s32 i;

    for(i = 0; i < getPlayerCount(); i++) {
        if (g_playerPointers[i]->prop == prop) {
           return i;
        }
    }

    return -1;
}


void set_cur_player_screen_size(u32 width, u32 height) {
    #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x25a,"Assertion failed: g_CurrentPlayer");
    }
    #endif
  g_CurrentPlayer->viewx = width;
  g_CurrentPlayer->viewy = height;
}

void set_cur_player_viewport_size(u32 ulx, u32 uly) {
        #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x262,"Assertion failed: g_CurrentPlayer");
    }
    #endif
  g_CurrentPlayer->viewleft = ulx;
  g_CurrentPlayer->viewtop = uly;
}

void set_cur_player_fovy(f32 fovy) {
            #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x26a,"Assertion failed: g_CurrentPlayer");
    }
    #endif
    g_CurrentPlayer->fovy = fovy;
}

void set_cur_player_aspect(f32 aspect) {
    #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x271,"Assertion failed: g_CurrentPlayer");
    }
    #endif
    g_CurrentPlayer->aspect = aspect;
}

f32 get_cur_player_fovy(void) {
    #ifdef XBLADEBUG
        if (g_CurrentPlayer == NULL) {
        assertPrint_8291E690(".\\ported\\player.cpp",0x278,"Assertion failed: g_CurrentPlayer");
    }
    #endif
    return g_CurrentPlayer->fovy;
}






#ifdef NONMATCHING
void sub_GAME_7F09B244(void) {

}
#else
GLOBAL_ASM(
.late_rodata
/*D:8005762C*/
glabel jpt_weapon_multi
.word weapon_multi_none
.word weapon_multi_none
.word weapon_multi_hunting_knife
.word weapon_multi_throwing_knife
.word weapon_multi_pp7
.word weapon_multi_pp7_silent
.word weapon_multi_dd44
.word weapon_multi_klobb
.word weapon_multi_kf7
.word weapon_multi_zmg
.word weapon_multi_d5k
.word weapon_multi_d5k_silent
.word weapon_multi_phantom
.word weapon_multi_ar33
.word weapon_multi_rcp90
.word weapon_multi_shotgun
.word weapon_multi_auto_shot
.word weapon_multi_sniper
.word weapon_multi_cougar
.word weapon_multi_goldengun
.word weapon_multi_pp7_special1
.word weapon_multi_pp7_special2
.word weapon_multi_moonraker
/*.word weapon_multi_none*/
/*.word weapon_multi_grenade_laun*/
/*.word weapon_multi_rocket_launch*/
/*.word weapon_multi_hand*/
/*.word weapon_multi_timed*/
/*.word weapon_multi_prox*/
/*.word weapon_multi_remote*/
/*.word weapon_multi_none*/
/*.word weapon_multi_none*/

.text
glabel sub_GAME_7F09B244
/* 0CFD74 7F09B244 28810020 */  slti  $at, $a0, 0x20
/* 0CFD78 7F09B248 14200006 */  bnez  $at, .L7F09B264
/* 0CFD7C 7F09B24C 2403FFFF */   li    $v1, -1
/* 0CFD80 7F09B250 24010058 */  li    $at, 88
/* 0CFD84 7F09B254 50810042 */  beql  $a0, $at, .L7F09B360
/* 0CFD88 7F09B258 2403014D */   li    $v1, 333
/* 0CFD8C 7F09B25C 03E00008 */  jr    $ra
/* 0CFD90 7F09B260 00601025 */   move  $v0, $v1

.L7F09B264:
/* 0CFD94 7F09B264 2C810020 */  sltiu $at, $a0, 0x20
/* 0CFD98 7F09B268 1020003D */  beqz  $at, .L7F09B360
/* 0CFD9C 7F09B26C 00047080 */   sll   $t6, $a0, 2
/* 0CFDA0 7F09B270 3C018005 */  lui   $at, %hi(jpt_weapon_multi)
/* 0CFDA4 7F09B274 002E0821 */  addu  $at, $at, $t6
/* 0CFDA8 7F09B278 8C2E762C */  lw    $t6, %lo(jpt_weapon_multi)($at)
/* 0CFDAC 7F09B27C 01C00008 */  jr    $t6
/* 0CFDB0 7F09B280 00000000 */   nop
weapon_multi_hunting_knife:
/* 0CFDB4 7F09B284 03E00008 */  jr    $ra
/* 0CFDB8 7F09B288 240200BA */   li    $v0, 186

weapon_multi_pp7:
/* 0CFDBC 7F09B28C 03E00008 */  jr    $ra
/* 0CFDC0 7F09B290 240200BF */   li    $v0, 191

weapon_multi_klobb:
/* 0CFDC4 7F09B294 03E00008 */  jr    $ra
/* 0CFDC8 7F09B298 240200C1 */   li    $v0, 193

weapon_multi_kf7:
/* 0CFDCC 7F09B29C 03E00008 */  jr    $ra
/* 0CFDD0 7F09B2A0 240200B8 */   li    $v0, 184

weapon_multi_zmg:
/* 0CFDD4 7F09B2A4 03E00008 */  jr    $ra
/* 0CFDD8 7F09B2A8 240200C3 */   li    $v0, 195

weapon_multi_d5k:
/* 0CFDDC 7F09B2AC 03E00008 */  jr    $ra
/* 0CFDE0 7F09B2B0 240200BD */   li    $v0, 189

weapon_multi_phantom:
/* 0CFDE4 7F09B2B4 03E00008 */  jr    $ra
/* 0CFDE8 7F09B2B8 240200C2 */   li    $v0, 194

weapon_multi_ar33:
/* 0CFDEC 7F09B2BC 03E00008 */  jr    $ra
/* 0CFDF0 7F09B2C0 240200BC */   li    $v0, 188

weapon_multi_rcp90:
/* 0CFDF4 7F09B2C4 03E00008 */  jr    $ra
/* 0CFDF8 7F09B2C8 240200C5 */   li    $v0, 197

weapon_multi_shotgun:
/* 0CFDFC 7F09B2CC 03E00008 */  jr    $ra
/* 0CFE00 7F09B2D0 240200C0 */   li    $v0, 192

weapon_multi_grenade_laun:
/* 0CFE04 7F09B2D4 03E00008 */  jr    $ra
/* 0CFE08 7F09B2D8 240200B9 */   li    $v0, 185

weapon_multi_hand:
/* 0CFE0C 7F09B2DC 03E00008 */  jr    $ra
/* 0CFE10 7F09B2E0 240200C4 */   li    $v0, 196

weapon_multi_remote:
/* 0CFE14 7F09B2E4 03E00008 */  jr    $ra
/* 0CFE18 7F09B2E8 240200C7 */   li    $v0, 199

weapon_multi_prox:
/* 0CFE1C 7F09B2EC 03E00008 */  jr    $ra
/* 0CFE20 7F09B2F0 240200C8 */   li    $v0, 200

weapon_multi_timed:
/* 0CFE24 7F09B2F4 03E00008 */  jr    $ra
/* 0CFE28 7F09B2F8 240200C9 */   li    $v0, 201

weapon_multi_cougar:
/* 0CFE2C 7F09B2FC 03E00008 */  jr    $ra
/* 0CFE30 7F09B300 240200BE */   li    $v0, 190

weapon_multi_moonraker:
/* 0CFE34 7F09B304 03E00008 */  jr    $ra
/* 0CFE38 7F09B308 240200BB */   li    $v0, 187

weapon_multi_sniper:
/* 0CFE3C 7F09B30C 03E00008 */  jr    $ra
/* 0CFE40 7F09B310 240200D2 */   li    $v0, 210

weapon_multi_d5k_silent:
/* 0CFE44 7F09B314 03E00008 */  jr    $ra
/* 0CFE48 7F09B318 240200CE */   li    $v0, 206

weapon_multi_dd44:
/* 0CFE4C 7F09B31C 03E00008 */  jr    $ra
/* 0CFE50 7F09B320 240200CD */   li    $v0, 205

weapon_multi_pp7_silent:
/* 0CFE54 7F09B324 03E00008 */  jr    $ra
/* 0CFE58 7F09B328 240200CC */   li    $v0, 204

weapon_multi_throwing_knife:
/* 0CFE5C 7F09B32C 03E00008 */  jr    $ra
/* 0CFE60 7F09B330 240200D1 */   li    $v0, 209

weapon_multi_auto_shot:
/* 0CFE64 7F09B334 03E00008 */  jr    $ra
/* 0CFE68 7F09B338 240200CF */   li    $v0, 207

weapon_multi_rocket_launch:
/* 0CFE6C 7F09B33C 03E00008 */  jr    $ra
/* 0CFE70 7F09B340 240200D3 */   li    $v0, 211

weapon_multi_goldengun:
/* 0CFE74 7F09B344 03E00008 */  jr    $ra
/* 0CFE78 7F09B348 240200D0 */   li    $v0, 208

weapon_multi_pp7_special1:
/* 0CFE7C 7F09B34C 03E00008 */  jr    $ra
/* 0CFE80 7F09B350 240200BF */   li    $v0, 191

weapon_multi_pp7_special2:
/* 0CFE84 7F09B354 03E00008 */  jr    $ra
/* 0CFE88 7F09B358 240200BF */   li    $v0, 191

/* 0CFE8C 7F09B35C 2403014D */  li    $v1, 333
weapon_multi_none:
.L7F09B360:
/* 0CFE90 7F09B360 03E00008 */  jr    $ra
/* 0CFE94 7F09B364 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F09B368(s32 arg0) {
    // Node 0
    return chrSetWeaponFlag4(g_CurrentPlayer->unkA8->unk4, arg0);
}

#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word weapon_multi_none
.word weapon_multi_grenade_laun
.word weapon_multi_rocket_launch
/*.word weapon_multi_hand*/
/*.word weapon_multi_timed*/
/*.word weapon_multi_prox*/
/*.word weapon_multi_remote*/
/*.word weapon_multi_none*/
/*.word weapon_multi_none*/
.text
glabel sub_GAME_7F09B368
/* 0CFE98 7F09B368 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0CFE9C 7F09B36C 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0CFEA0 7F09B370 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0CFEA4 7F09B374 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0CFEA8 7F09B378 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0CFEAC 7F09B37C 00802825 */  move  $a1, $a0
/* 0CFEB0 7F09B380 0FC1487A */  jal   chrSetWeaponFlag4
/* 0CFEB4 7F09B384 8DE40004 */   lw    $a0, 4($t7)
/* 0CFEB8 7F09B388 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0CFEBC 7F09B38C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0CFEC0 7F09B390 03E00008 */  jr    $ra
/* 0CFEC4 7F09B394 00000000 */   nop
)
#endif





#ifdef NONMATCHING
// NOTE: i think the return value from
// something_with_generating_object is supposed
// to be returned here?
void sub_GAME_7F09B398(GUNHAND hand) {
    struct ChrRecord* temp_v0;
    ITEM_IDS weaponNum;
    s32 weaponIdMaybe;

    temp_v0 = g_CurrentPlayer->prop->chr;
    if (!temp_v0->handle_positiondata[hand]) {
        weaponNum = getCurrentPlayerWeaponId(hand);
        weaponIdMaybe = sub_GAME_7F09B244(weaponNum);
        if (weaponIdMaybe >= 0) {
            something_with_generating_object(temp_v0, weaponIdMaybe, weaponNum, hand == GUNRIGHT ? 0 : 0x10000000, 0, 0);
        }
    }
}
#else
GLOBAL_ASM(
.late_rodata
/*hack for jtbl*/
.word weapon_multi_hand
.word weapon_multi_timed
.word weapon_multi_prox
.word weapon_multi_remote
.word weapon_multi_none
.word weapon_multi_none

.text
glabel sub_GAME_7F09B398
/* 0CFEC8 7F09B398 3C0E8008 */  lui   $t6, %hi(g_CurrentPlayer)
/* 0CFECC 7F09B39C 8DCEA0B0 */  lw    $t6, %lo(g_CurrentPlayer)($t6)
/* 0CFED0 7F09B3A0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0CFED4 7F09B3A4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0CFED8 7F09B3A8 8DCF00A8 */  lw    $t7, 0xa8($t6)
/* 0CFEDC 7F09B3AC 00041880 */  sll   $v1, $a0, 2
/* 0CFEE0 7F09B3B0 8DE20004 */  lw    $v0, 4($t7)
/* 0CFEE4 7F09B3B4 0043C021 */  addu  $t8, $v0, $v1
/* 0CFEE8 7F09B3B8 8F190160 */  lw    $t9, 0x160($t8)
/* 0CFEEC 7F09B3BC 57200014 */  bnezl $t9, .L7F09B410
/* 0CFEF0 7F09B3C0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0CFEF4 7F09B3C4 AFA20034 */  sw    $v0, 0x34($sp)
/* 0CFEF8 7F09B3C8 0FC17674 */  jal   getCurrentPlayerWeaponId
/* 0CFEFC 7F09B3CC AFA30024 */   sw    $v1, 0x24($sp)
/* 0CFF00 7F09B3D0 AFA20030 */  sw    $v0, 0x30($sp)
/* 0CFF04 7F09B3D4 0FC26C91 */  jal   sub_GAME_7F09B244
/* 0CFF08 7F09B3D8 00402025 */   move  $a0, $v0
/* 0CFF0C 7F09B3DC 8FA30024 */  lw    $v1, 0x24($sp)
/* 0CFF10 7F09B3E0 0440000A */  bltz  $v0, .L7F09B40C
/* 0CFF14 7F09B3E4 00402825 */   move  $a1, $v0
/* 0CFF18 7F09B3E8 14600003 */  bnez  $v1, .L7F09B3F8
/* 0CFF1C 7F09B3EC 8FA40034 */   lw    $a0, 0x34($sp)
/* 0CFF20 7F09B3F0 10000002 */  b     .L7F09B3FC
/* 0CFF24 7F09B3F4 00003825 */   move  $a3, $zero
.L7F09B3F8:
/* 0CFF28 7F09B3F8 3C071000 */  lui   $a3, 0x1000
.L7F09B3FC:
/* 0CFF2C 7F09B3FC 8FA60030 */  lw    $a2, 0x30($sp)
/* 0CFF30 7F09B400 AFA00010 */  sw    $zero, 0x10($sp)
/* 0CFF34 7F09B404 0FC14885 */  jal   something_with_generating_object
/* 0CFF38 7F09B408 AFA00014 */   sw    $zero, 0x14($sp)
.L7F09B40C:
/* 0CFF3C 7F09B40C 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F09B410:
/* 0CFF40 7F09B410 27BD0038 */  addiu $sp, $sp, 0x38
/* 0CFF44 7F09B414 03E00008 */  jr    $ra
/* 0CFF48 7F09B418 00000000 */   nop
)
#endif





void shuffle_player_ids(void) {
    s32 i;
    u32 random;
    PLAYER_ID temp;

    for (i = 0; i < 4; i ++) {
        array_PLAYER_IDs[i] = i;
    }

    for (i = 0; i < 3; i ++) {
        random = randomGetNext();
        temp = array_PLAYER_IDs[i];
        array_PLAYER_IDs[i] = array_PLAYER_IDs[i + random % (4 - i)];
        array_PLAYER_IDs[i + random % (4 - i)] = temp;
    }
}





s32 sub_GAME_7F09B4D8(s32 current_player_num) {
    s32 i;
    s32 position = 0;

    for (i = 0; i < 4; i++) {
        if (current_player_num != array_PLAYER_IDs[i])
        {
            if (g_playerPointers[array_PLAYER_IDs[i]] != NULL)
            {
                position++;
            }
        }
        else
        {
            break;
        }
    }

    return position;
}






s32 get_nth_player_from_shuffled(PLAYER_ID id)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        if (g_playerPointers[array_PLAYER_IDs[i]] != NULL) {
            if (id == 0) {
               return array_PLAYER_IDs[i];
            }
            id--;
        }
    }

    return 0;
}

