#include <ultra64.h>
#include <memp.h>
#include <fr.h>
#include <random.h>
#include "player.h"
#include "unk_092E50.h"
#include "bondview.h"
#include "lvl.h"
#include "player_2.h"

/* Define default values that are different between EU and the rest for initBONDdataforPlayer */
#ifdef VERSION_EU
#define DEFAULT_FIELD_3B8_Z     8.417509f
#define DEFAULT_HEADDAMP        0.9166f
#define DEFAULT_HEADLOOKSUM_VAL 11.990406f
#define DEFAULT_VIEWPORT_V_VAL  0x220
#define DEFAULT_C_SCREENHEIGHT  272.0f
#define DEFAULT_C_HALFHEIGHT    136.0f
#define DEFAULT_SCREENYMAXF     272.0f
#define DEFAULT_ASPECT          1.1764706f
#elif defined(VERSION_US) || defined(VERSION_JP)
#define DEFAULT_FIELD_3B8_Z     9.999998f
#define DEFAULT_HEADDAMP        0.93f
#define DEFAULT_HEADLOOKSUM_VAL 14.285716f
#define DEFAULT_VIEWPORT_V_VAL  0x1E0
#define DEFAULT_C_SCREENHEIGHT  240.0f
#define DEFAULT_C_HALFHEIGHT    120.0f
#define DEFAULT_SCREENYMAXF     240.0f
#define DEFAULT_ASPECT          1.3333334f
#endif

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

void initBONDdataforPlayer(s32 player_num)
{
    s32 i;
    struct hand default_hand;
    s32 one;

    default_hand = *((struct hand*)D_8003FDA0);
#if defined(VERSION_US) || defined(VERSION_JP)
    g_playerPointers[player_num] = mempAllocBytesInBank(0x2A80U, 4U);
#elif defined(VERSION_EU)
    g_playerPointers[player_num] = mempAllocBytesInBank(0x2A70U, 4U);
#endif

    g_playerPointers[player_num]->unknown = 0;
    g_playerPointers[player_num]->pos.x = 0.0f;
    g_playerPointers[player_num]->pos.y = 0.0f;
    g_playerPointers[player_num]->pos.z = 0.0f;
    g_playerPointers[player_num]->pos2.x = 0.0f;
    g_playerPointers[player_num]->pos2.y = 0.0f;
    g_playerPointers[player_num]->pos2.z = 1.0f;
    g_playerPointers[player_num]->offset.x = 0.0f;
    g_playerPointers[player_num]->offset.y = 1.0f;
    g_playerPointers[player_num]->offset.z = 0.0f;
    g_playerPointers[player_num]->pos3.x = 0.0f;
    g_playerPointers[player_num]->pos3.y = 0.0f;
    g_playerPointers[player_num]->pos3.z = 0.0f;
    g_playerPointers[player_num]->room_pointer = NULL;
    g_playerPointers[player_num]->current_model_pos.x = 0.0f;
    g_playerPointers[player_num]->current_model_pos.y = 0.0f;
    g_playerPointers[player_num]->current_model_pos.z = 0.0f;
    g_playerPointers[player_num]->previous_model_pos.x = 0.0f;
    g_playerPointers[player_num]->previous_model_pos.y = 0.0f;
    g_playerPointers[player_num]->previous_model_pos.z = 0.0f;
    g_playerPointers[player_num]->current_room_pos.x = 0.0f;
    g_playerPointers[player_num]->current_room_pos.y = 0.0f;
    g_playerPointers[player_num]->current_room_pos.z = 0.0f;
    g_playerPointers[player_num]->field_6C = 0.0f;
    g_playerPointers[player_num]->field_70 = 0.0f;
    g_playerPointers[player_num]->stanHeight = 0.0f;
    g_playerPointers[player_num]->field_78 = 0.0f;
    g_playerPointers[player_num]->field_7C = 0.0f;
    g_playerPointers[player_num]->field_80 = 0.0f;
    g_playerPointers[player_num]->field_84 = 0.0f;
    g_playerPointers[player_num]->field_88 = 0.0f;
    g_playerPointers[player_num]->field_8C = 0;
    g_playerPointers[player_num]->field_90 = 0.0f;
    g_playerPointers[player_num]->field_94 = 0;
    g_playerPointers[player_num]->field_98 = 0.0f;
    g_playerPointers[player_num]->swaytarget = 0.0f;
    g_playerPointers[player_num]->field_1278 = 0.0f;
    g_playerPointers[player_num]->field_127C = 0.0f;
    g_playerPointers[player_num]->crouchpos = 2;
    g_playerPointers[player_num]->autocrouchpos = 2;
    g_playerPointers[player_num]->ducking_height_offset = 0.0f;
    g_playerPointers[player_num]->field_A4 = 0.0f;
    g_playerPointers[player_num]->prop = NULL;
    g_playerPointers[player_num]->field_AC = 1;
    g_playerPointers[player_num]->field_D0 = 0;
    g_playerPointers[player_num]->ptr_char_objectinstance = NULL;
    g_playerPointers[player_num]->bonddead = 0;
    g_playerPointers[player_num]->bondhealth = 1.0f;
    g_playerPointers[player_num]->bondarmour = 0.0f;
    g_playerPointers[player_num]->oldhealth = 1.0f;
    g_playerPointers[player_num]->oldarmour = 0.0f;
    g_playerPointers[player_num]->apparenthealth = 1.0f;
    g_playerPointers[player_num]->apparentarmour = 0.0f;
    g_playerPointers[player_num]->damageshowtime = -1;
    g_playerPointers[player_num]->healthshowtime = -1;
    g_playerPointers[player_num]->field_104 = 0;
    g_playerPointers[player_num]->field_108 = 0;
    g_playerPointers[player_num]->field_10C = 0;
    g_playerPointers[player_num]->movecentrerelease = 0;
    g_playerPointers[player_num]->lookaheadcentreenabled = 1;
    g_playerPointers[player_num]->automovecentreenabled = 1;
    g_playerPointers[player_num]->fastmovecentreenabled = 0;
    g_playerPointers[player_num]->automovecentre = 1;
    g_playerPointers[player_num]->insightaimmode = 0;
    g_playerPointers[player_num]->autoyaimenabled = 1;
    g_playerPointers[player_num]->autoaimy = 0.0f;
    g_playerPointers[player_num]->autoyaimtime = 0;
    g_playerPointers[player_num]->autoyaimtime60 = -1;
    g_playerPointers[player_num]->autoxaimenabled = 1;
    g_playerPointers[player_num]->autoaimx = 0.0f;
    g_playerPointers[player_num]->autoxaimtime = 0;
    g_playerPointers[player_num]->autoxaimtime60 = -1;
    g_playerPointers[player_num]->vv_theta = 0.0f;
    g_playerPointers[player_num]->speedtheta = 0.0f;
    g_playerPointers[player_num]->vv_costheta = 1.0f;
    g_playerPointers[player_num]->vv_sintheta = 0.0f;
    g_playerPointers[player_num]->vv_verta = -4.0f;
    g_playerPointers[player_num]->vv_verta360 = -229.1831f;
    g_playerPointers[player_num]->speedverta = 0.0f;
    g_playerPointers[player_num]->vv_cosverta = 1.0f;
    g_playerPointers[player_num]->vv_sinverta = 0.0f;
    g_playerPointers[player_num]->speedsideways = 0.0f;
    g_playerPointers[player_num]->speedstrafe = 0.0f;
    g_playerPointers[player_num]->speedforwards = 0.0f;
    g_playerPointers[player_num]->field_2A4C = 0.0f;
    g_playerPointers[player_num]->speedboost = 1.0f;
    g_playerPointers[player_num]->bondshotspeed.x = 0.0f;
    g_playerPointers[player_num]->bondshotspeed.y = 0.0f;
    g_playerPointers[player_num]->bondshotspeed.z = 0.0f;
    g_playerPointers[player_num]->bondfadetime60 = -1.0f;
    g_playerPointers[player_num]->bondfadetimemax60 = -1.0f;
    g_playerPointers[player_num]->bondfadefracold = 0.0f;
    g_playerPointers[player_num]->bondfadefracnew = 0.0f;
    g_playerPointers[player_num]->bondbreathing = 0.0f;
    g_playerPointers[player_num]->field_1A0 = 0;
    g_playerPointers[player_num]->watch_pause_time = 0;
    g_playerPointers[player_num]->field_1C4 = 0;
    g_playerPointers[player_num]->watch_animation_state = 0;
    g_playerPointers[player_num]->outside_watch_menu = 1;
    g_playerPointers[player_num]->open_close_solo_watch_menu = 0;
    g_playerPointers[player_num]->field_1D4 = 0.0f;
    g_playerPointers[player_num]->field_1D8 = 0.0f;
    g_playerPointers[player_num]->pause_watch_position = -25;
    g_playerPointers[player_num]->field_1E0 = 0.0f;
    g_playerPointers[player_num]->field_1E4 = 1.0f;
    g_playerPointers[player_num]->field_1E8 = 0.0f;
    g_playerPointers[player_num]->field_1EC = 0.0f;
    g_playerPointers[player_num]->field_1F0 = 0.0f;
    g_playerPointers[player_num]->field_1F4 = 1.0f;
    g_playerPointers[player_num]->pausing_flag = 0;
    g_playerPointers[player_num]->pause_starting_angle = 0.0f;
    g_playerPointers[player_num]->pause_related = 0.0f;
    g_playerPointers[player_num]->pause_target_angle = 0.0f;
    g_playerPointers[player_num]->field_210 = 0.0f;
    g_playerPointers[player_num]->field_214 = 0.0f;
    g_playerPointers[player_num]->field_218 = 0;
    g_playerPointers[player_num]->field_21C = 1;
    g_playerPointers[player_num]->step_in_view_watch_animation = 0;
    g_playerPointers[player_num]->pause_animation_counter = 0.0f;
    g_playerPointers[player_num]->buttons_pressed = 0;
    g_playerPointers[player_num]->field_3B6 = 0;
    g_playerPointers[player_num]->field_3B8.x = 0.0f;
    g_playerPointers[player_num]->field_3B8.y = 0.0f;
    g_playerPointers[player_num]->field_3B8.z = DEFAULT_FIELD_3B8_Z;
    g_playerPointers[player_num]->field_3C4 = 0.0f;
    g_playerPointers[player_num]->field_3C8 = 0.0f;
    g_playerPointers[player_num]->field_3CC = 1.0f;
    g_playerPointers[player_num]->colourscreenred = 0xFF;
    g_playerPointers[player_num]->colourscreengreen = 0xFF;
    g_playerPointers[player_num]->colourscreenblue = 0xFF;
    g_playerPointers[player_num]->colourscreenfrac = 0.0f;
    g_playerPointers[player_num]->colourfadetime60 = -1.0f;
    g_playerPointers[player_num]->colourfadetimemax60 = -1.0f;
    g_playerPointers[player_num]->colourfaderedold = 0xFF;
    g_playerPointers[player_num]->colourfaderednew = 0xFF;
    g_playerPointers[player_num]->colourfadegreenold = 0xFF;
    g_playerPointers[player_num]->colourfadegreennew = 0xFF;
    g_playerPointers[player_num]->colourfadeblueold = 0xFF;
    g_playerPointers[player_num]->colourfadebluenew = 0xFF;
    g_playerPointers[player_num]->colourfadefracold = 0.0f;
    g_playerPointers[player_num]->colourfadefracnew = 0.0f;
    g_playerPointers[player_num]->bondtype = 0;
    g_playerPointers[player_num]->startnewbonddie = 1;
    g_playerPointers[player_num]->redbloodfinished = 0;
    g_playerPointers[player_num]->deathanimfinished = 0;
    g_playerPointers[player_num]->field_42c = 2;
    g_playerPointers[player_num]->controldef = 0;
    g_playerPointers[player_num]->resetheadpos = 1;
    g_playerPointers[player_num]->resetheadrot = 1;
    g_playerPointers[player_num]->resetheadtick = 1;
    g_playerPointers[player_num]->headanim = 0;
    g_playerPointers[player_num]->headdamp = DEFAULT_HEADDAMP;
    g_playerPointers[player_num]->headwalkingtime60 = 0;
    g_playerPointers[player_num]->headamplitude = 1.0f;
    g_playerPointers[player_num]->sideamplitude = 1.0f;
    g_playerPointers[player_num]->headpos[0] = 0.0f;
    g_playerPointers[player_num]->headpos[1] = 0.0f;
    g_playerPointers[player_num]->headpos[2] = 0.0f;
    g_playerPointers[player_num]->headlook[0] = 0.0f;
    g_playerPointers[player_num]->headlook[1] = 0.0f;
    g_playerPointers[player_num]->headlook[2] = 1.0f;
    g_playerPointers[player_num]->headup[0] = 0.0f;
    g_playerPointers[player_num]->headup[1] = 1.0f;
    g_playerPointers[player_num]->headup[2] = 0.0f;
    g_playerPointers[player_num]->headpossum[0] = 0.0f;
    g_playerPointers[player_num]->headpossum[1] = 0.0f;
    g_playerPointers[player_num]->headpossum[2] = 0.0f;
    g_playerPointers[player_num]->headlooksum[0] = 0.0f;
    g_playerPointers[player_num]->headlooksum[1] = 0.0f;
    g_playerPointers[player_num]->headlooksum[2] = DEFAULT_HEADLOOKSUM_VAL;
    g_playerPointers[player_num]->headupsum[0] = 0.0f;
    g_playerPointers[player_num]->headupsum[1] = DEFAULT_HEADLOOKSUM_VAL;
    g_playerPointers[player_num]->headupsum[2] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset[0] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset[1] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset[2] = 0.0f;
    g_playerPointers[player_num]->standheight = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.x = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.y = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.z = 0.0f;
    g_playerPointers[player_num]->standfrac = 0.0f;
    g_playerPointers[player_num]->standlook[0][0] = 0.0f;
    g_playerPointers[player_num]->standlook[0][1] = 0.0f;
    g_playerPointers[player_num]->standlook[0][2] = 1.0f;
    g_playerPointers[player_num]->standlook[1][0] = 0.0f;
    g_playerPointers[player_num]->standlook[1][1] = 0.0f;
    g_playerPointers[player_num]->standlook[1][2] = 1.0f;
    g_playerPointers[player_num]->standup[0][0] = 0.0f;
    g_playerPointers[player_num]->standup[0][1] = 1.0f;
    g_playerPointers[player_num]->standup[0][2] = 0.0f;
    g_playerPointers[player_num]->standup[1][0] = 0.0f;
    g_playerPointers[player_num]->standup[1][1] = 1.0f;
    g_playerPointers[player_num]->standup[1][2] = 0.0f;
    g_playerPointers[player_num]->standcnt = 0;

    for (i = 0; i < 2; i++)
    {
        g_playerPointers[player_num]->viewports[i].vp.vscale[0] = 0x280;
        g_playerPointers[player_num]->viewports[i].vp.vscale[1] = DEFAULT_VIEWPORT_V_VAL;
        g_playerPointers[player_num]->viewports[i].vp.vscale[2] = 0x1FF;
        g_playerPointers[player_num]->viewports[i].vp.vscale[3] = 0;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[0] = 0x280;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[1] = DEFAULT_VIEWPORT_V_VAL;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[2] = 0x1FF;
        g_playerPointers[player_num]->viewports[i].vp.vtrans[3] = 0;
    }

    g_playerPointers[player_num]->viewx = 0x64;
    g_playerPointers[player_num]->viewy = 0x64;
    g_playerPointers[player_num]->viewleft = 0;
    g_playerPointers[player_num]->viewtop = 0;
    g_playerPointers[player_num]->hand_invisible[0] = 0;
    g_playerPointers[player_num]->hand_invisible[1] = 0;
    g_playerPointers[player_num]->hand_item[0] = 0;
    g_playerPointers[player_num]->hand_item[1] = 0;
    g_playerPointers[player_num]->field_2A44[0] = -1;
    g_playerPointers[player_num]->field_2A44[1] = -1;
    g_playerPointers[player_num]->lock_hand_model[0] = 0;
    g_playerPointers[player_num]->lock_hand_model[1] = 0;
    g_playerPointers[player_num]->ptr_hand_weapon_buffer[0] = NULL;
    g_playerPointers[player_num]->ptr_hand_weapon_buffer[1] = NULL;

    g_playerPointers[player_num]->hands[0] = default_hand;
    g_playerPointers[player_num]->hands[1] = default_hand;

    g_playerPointers[player_num]->gunposamplitude = 1.0f;
    g_playerPointers[player_num]->gunxamplitude = 1.0f;
    g_playerPointers[player_num]->field_FC8 = 0;
    g_playerPointers[player_num]->field_FCC = 0;
    g_playerPointers[player_num]->field_FD0 = 0;
    g_playerPointers[player_num]->z_trigger_timer = 0;
    g_playerPointers[player_num]->field_FD8 = 0;
    g_playerPointers[player_num]->field_FDC = 0xFF;
    g_playerPointers[player_num]->field_FDD = 0xFF;
    g_playerPointers[player_num]->field_FDE = 0xFF;
    g_playerPointers[player_num]->field_FDF = 0;
    g_playerPointers[player_num]->resetshadecol = 1;
    g_playerPointers[player_num]->field_FE4 = 0;
    g_playerPointers[player_num]->crosshair_angle.x = 0.0f;
    g_playerPointers[player_num]->crosshair_angle.y = 0.0f;
    g_playerPointers[player_num]->crosshair_x_pos = 0.0f;
    g_playerPointers[player_num]->crosshair_y_pos = 0.0f;
    g_playerPointers[player_num]->guncrossdamp = 0.9f;
    g_playerPointers[player_num]->field_FFC.x = 0.0f;
    g_playerPointers[player_num]->field_FFC.y = 0.0f;
    g_playerPointers[player_num]->gun_azimuth_angle = 0.0f;
    g_playerPointers[player_num]->gun_azimuth_turning = 0.0f;
    g_playerPointers[player_num]->gunaimdamp = 0.9f;
    g_playerPointers[player_num]->field_1010.x = 0.0f;
    g_playerPointers[player_num]->field_1010.y = -3.1415927f;
    g_playerPointers[player_num]->field_1010.z = 0.0f;
    g_playerPointers[player_num]->last_z_trigger_timer = 0;
    g_playerPointers[player_num]->copiedgoldeneye = 0;
    g_playerPointers[player_num]->ammodispflags = 0;
    g_playerPointers[player_num]->gunsync = 0.0f;
    g_playerPointers[player_num]->syncchange = 0.0f;
    g_playerPointers[player_num]->synccount = 0.0f;
    g_playerPointers[player_num]->syncoffset = 0;
    g_playerPointers[player_num]->field_107C = 0.0f;
    g_playerPointers[player_num]->field_1080 = 0.0f;
    g_playerPointers[player_num]->sniper_zoom = 60.0f;
    g_playerPointers[player_num]->camera_zoom = 60.0f;
    g_playerPointers[player_num]->field_108C = -1;
    g_playerPointers[player_num]->c_screenwidth = 320.0f;
    g_playerPointers[player_num]->c_screenheight = DEFAULT_C_SCREENHEIGHT;
    g_playerPointers[player_num]->c_screenleft = 0.0f;
    g_playerPointers[player_num]->c_screentop = 0.0f;
    g_playerPointers[player_num]->c_perspnear = 10.0f;
    g_playerPointers[player_num]->c_perspfovy = 46.0f;
    g_playerPointers[player_num]->c_perspaspect = 1.0f;
    g_playerPointers[player_num]->c_halfwidth = 160.0f;
    g_playerPointers[player_num]->c_halfheight = DEFAULT_C_HALFHEIGHT;
    g_playerPointers[player_num]->c_scalex = 1.0f;
    g_playerPointers[player_num]->c_scaley = 1.0f;
    g_playerPointers[player_num]->c_recipscalex = 1.0f;
    g_playerPointers[player_num]->c_recipscaley = 1.0f;
    g_playerPointers[player_num]->field_10C4 = NULL;
    g_playerPointers[player_num]->field_10C8 = NULL;
    g_playerPointers[player_num]->field_10CC = NULL;
    g_playerPointers[player_num]->field_10D0 = 0;
    g_playerPointers[player_num]->field_10D4 = NULL;
    g_playerPointers[player_num]->projmatrix = NULL;
    g_playerPointers[player_num]->projmatrixf = NULL;
    g_playerPointers[player_num]->field_10E0 = 0;
    g_playerPointers[player_num]->field_10E4 = 0;
    g_playerPointers[player_num]->field_10E8 = NULL;
    g_playerPointers[player_num]->field_10EC = NULL;
    g_playerPointers[player_num]->c_scalelod60 = 1.0f;
    g_playerPointers[player_num]->c_scalelod = 1.0f;
    g_playerPointers[player_num]->c_lodscalez = 1.0f;
    g_playerPointers[player_num]->c_lodscalezu32 = 0x10000;
    g_playerPointers[player_num]->screenxminf = 0.0f;
    g_playerPointers[player_num]->screenyminf = 0.0f;
    g_playerPointers[player_num]->screenxmaxf = 320.0f;
    g_playerPointers[player_num]->screenymaxf = DEFAULT_SCREENYMAXF;
    g_playerPointers[player_num]->gunsightmode = 0;
    g_playerPointers[player_num]->bloodImgBufPtrArray[0] = NULL;
    g_playerPointers[player_num]->bloodImgBufPtrArray[1] = NULL;
    g_playerPointers[player_num]->bloodImgIdx = 0;
    g_playerPointers[player_num]->zoomintime = 0.0f;
    g_playerPointers[player_num]->zoomintimemax = 0.0f;
    g_playerPointers[player_num]->zoominfovy = 60.0f;
    g_playerPointers[player_num]->zoominfovyold = 60.0f;
    g_playerPointers[player_num]->zoominfovynew = 60.0f;
    g_playerPointers[player_num]->fovy = 60.0f;
    g_playerPointers[player_num]->aspect = DEFAULT_ASPECT;
    g_playerPointers[player_num]->hudmessoff = 0;
    g_playerPointers[player_num]->bondmesscnt = -1;
    g_playerPointers[player_num]->ptr_inventory_first_in_cycle = NULL;
    g_playerPointers[player_num]->p_itemcur = NULL;
    g_playerPointers[player_num]->equipmaxitems = 0;
    g_playerPointers[player_num]->equipallguns = 0;
    one = 1;
    g_playerPointers[player_num]->equipcuritem = 0;
    g_playerPointers[player_num]->textoverrides = NULL;
    g_playerPointers[player_num]->field_1280 = 0.0f;
    g_playerPointers[player_num]->players_cur_animation = 0;
    g_playerPointers[player_num]->field_1288 = 0.0f;
    g_playerPointers[player_num]->bondinvincible = 0;
    g_playerPointers[player_num]->field_29B8 = 7;
    g_playerPointers[player_num]->field_29BC = 1.0f;
    g_playerPointers[player_num]->field_29C0 = 0.0f;
    g_playerPointers[player_num]->mpmenuon = 0;
    g_playerPointers[player_num]->damagetype = 7;
    g_playerPointers[player_num]->deathcount = 0;
    g_playerPointers[player_num]->field_29E0 = random_byte++;
    g_playerPointers[player_num]->last_kill_time[0] = -1;
    g_playerPointers[player_num]->last_kill_time[1] = -1;
    g_playerPointers[player_num]->last_kill_time[2] = -1;
    g_playerPointers[player_num]->last_kill_time[3] = -1;
    g_playerPointers[player_num]->healthdisplaytime = 0;
    g_playerPointers[player_num]->field_2A30 = 0;
    g_playerPointers[player_num]->field_2A34 = 0;
    g_playerPointers[player_num]->cur_item_weapon_getname = 1;
    g_playerPointers[player_num]->actual_health = 1.0f;
    g_playerPointers[player_num]->actual_armor = 1.0f;
    g_playerPointers[player_num]->cur_player_control_type_0 = 0;
    g_playerPointers[player_num]->cur_player_control_type_1 = 0;
    g_playerPointers[player_num]->cur_player_control_type_2 = 0.0f;
    g_playerPointers[player_num]->neg_vspacing_for_control_type_entry = 0;
    g_playerPointers[player_num]->has_set_control_type_data = one;
    g_playerPointers[player_num]->field_2A6C = 0;
    g_playerPointers[player_num]->field_2A70 = NULL;

    g_VisibleToGuardsFlag = 1;
    obj_collision_flag = 1;
}


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

/* looks vaguely like this, couldn't quite get there */
PROP sub_GAME_7F09B244(ITEM_IDS arg0)
{
    PROP ret = -1;
    switch (arg0)
    {
        case ITEM_KNIFE:         return PROP_CHRKNIFE;         /* weapon_multi_hunting_knife */
        case ITEM_WPPK:          return PROP_CHRWPPK;          /* weapon_multi_pp7 */
        case ITEM_SKORPION:      return PROP_CHRSKORPION;      /* weapon_multi_klobb */
        case ITEM_AK47:          return PROP_CHRKALASH;        /* weapon_multi_kf7 */
        case ITEM_UZI:           return PROP_CHRUZI;           /* weapon_multi_zmg */
        case ITEM_MP5K:          return PROP_CHRMP5K;          /* weapon_multi_d5k */
        case ITEM_SPECTRE:       return PROP_CHRSPECTRE;       /* weapon_multi_phantom */
        case ITEM_M16:           return PROP_CHRM16;           /* weapon_multi_ar33 */
        case ITEM_FNP90:         return PROP_CHRFNP90;         /* weapon_multi_rcp90 */
        case ITEM_SHOTGUN:       return PROP_CHRSHOTGUN;       /* weapon_multi_shotgun */
        case ITEM_GRENADELAUNCH: return PROP_CHRGRENADELAUNCH; /* weapon_multi_grenade_laun */
        case ITEM_GRENADE:       return PROP_CHRGRENADE;       /* weapon_multi_hand */
        case ITEM_REMOTEMINE:    return PROP_CHRREMOTEMINE;    /* weapon_multi_remote */
        case ITEM_PROXIMITYMINE: return PROP_CHRPROXIMITYMINE; /* weapon_multi_prox */
        case ITEM_TIMEDMINE:     return PROP_CHRTIMEDMINE;     /* weapon_multi_timed */
        case ITEM_RUGER:         return PROP_CHRRUGER;         /* weapon_multi_cougar */
        case ITEM_LASER:         return PROP_CHRLASER;         /* weapon_multi_moonraker */
        case ITEM_SNIPERRIFLE:   return PROP_CHRSNIPERRIFLE;   /* weapon_multi_sniper */
        case ITEM_MP5KSIL:       return PROP_CHRMP5KSIL;       /* weapon_multi_d5k_silent */
        case ITEM_TT33:          return PROP_CHRTT33;          /* weapon_multi_dd44 */
        case ITEM_WPPKSIL:       return PROP_CHRWPPKSIL;       /* weapon_multi_pp7_silent */
        case ITEM_THROWKNIFE:    return PROP_CHRTHROWKNIFE;    /* weapon_multi_throwing_knife */
        case ITEM_AUTOSHOT:      return PROP_CHRAUTOSHOT;      /* weapon_multi_auto_shot */
        case ITEM_ROCKETLAUNCH:  return PROP_CHRROCKETLAUNCH;  /* weapon_multi_rocket_launch */
        case ITEM_GOLDENGUN:     return PROP_CHRGOLDEN;        /* weapon_multi_goldengun */
        case ITEM_SILVERWPPK:    return PROP_CHRWPPK;          /* weapon_multi_pp7_special1 */
        case ITEM_GOLDWPPK:      return PROP_CHRWPPK;          /* weapon_multi_pp7_special2 */
        case ITEM_TOKEN:         ret = PROP_FLAG;
        /* weapon_multi_none */
        case ITEM_UNARMED:
        case ITEM_FIST:
        default:
            return ret;
    }
    return ret;
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


void sub_GAME_7F09B368(enum GUNHAND hand)
{
    chrSetWeaponFlag4(g_CurrentPlayer->prop->chr, hand);
}


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
.word weapon_multi_none
.word weapon_multi_grenade_laun
.word weapon_multi_rocket_launch
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

