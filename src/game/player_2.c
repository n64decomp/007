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
#define DEFAULT_C_SCREENHEIGHT  (f32)SCREEN_HEIGHT
#define DEFAULT_C_HALFHEIGHT    136.0f
#define DEFAULT_SCREENYMAXF     (f32)SCREEN_HEIGHT
#define DEFAULT_ASPECT          ASPECT_RATIO
#elif defined(VERSION_US) || defined(VERSION_JP)
#define DEFAULT_FIELD_3B8_Z     9.999998f
#define DEFAULT_HEADDAMP        0.93f
#define DEFAULT_HEADLOOKSUM_VAL 14.285716f
#define DEFAULT_VIEWPORT_V_VAL  0x1E0
#define DEFAULT_C_SCREENHEIGHT  (f32)SCREEN_HEIGHT
#define DEFAULT_C_HALFHEIGHT    120.0f
#define DEFAULT_SCREENYMAXF     (f32)SCREEN_HEIGHT
#define DEFAULT_ASPECT          ASPECT_RATIO
#endif

//newfile per EU

void default_player_perspective_and_height(void)
{
  float value  = 1.0f;

  if (0) { }

  g_playerPlayerData[PLAYER_1].player_perspective_height = value;
  g_playerPlayerData[PLAYER_1].handicap = value;
  g_playerPlayerData[PLAYER_2].player_perspective_height = value;
  g_playerPlayerData[PLAYER_2].handicap = value;
  g_playerPlayerData[PLAYER_3].player_perspective_height = value;
  g_playerPlayerData[PLAYER_3].handicap = value;
  g_playerPlayerData[PLAYER_4].player_perspective_height = value;
  g_playerPlayerData[PLAYER_4].handicap = value;
}

void reset_play_data_ptrs(void)
{
    g_playerPointers[PLAYER_1] = NULL;
    g_playerPointers[PLAYER_2] = NULL;
    g_playerPointers[PLAYER_3] = NULL;
    g_playerPointers[PLAYER_4] = NULL;
    g_CurrentPlayer = NULL;
    g_playerPerm = NULL;
    player_num = PLAYER_1;
    random_byte = 0;
    array_PLAYER_IDs[PLAYER_1] = 0;
    array_PLAYER_IDs[PLAYER_2] = 1;
    array_PLAYER_IDs[PLAYER_3] = 2;
    array_PLAYER_IDs[PLAYER_4] = 3;
}

void init_player_data_ptrs_construct_viewports(s32 playercount)
{
    s32 i;

    g_playerPointers[PLAYER_1] = NULL;
    g_playerPointers[PLAYER_2] = NULL;
    g_playerPointers[PLAYER_3] = NULL;
    g_playerPointers[PLAYER_4] = NULL;
    random_byte = (s32) (randomGetNext() & 0xFF);
    if (playercount > 0)
    {
        for (i = 0; i < playercount; i++)
        {
            initBONDdataforPlayer(i);
        }
        set_cur_player(PLAYER_1);
        return;
    }
    initBONDdataforPlayer(PLAYER_1);
    set_cur_player(PLAYER_1);
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
#ifdef DEBUG
    assert(players[num]==NULL); //according to assert, this file name is "player.c"
#endif
    default_hand = *((struct hand*)D_8003FDA0);
#if defined(VERSION_US) || defined(VERSION_JP)
    g_playerPointers[player_num] = mempAllocBytesInBank(0x2A80U, MEMPOOL_STAGE);
#elif defined(VERSION_EU)
    g_playerPointers[player_num] = mempAllocBytesInBank(0x2A70U, MEMPOOL_STAGE);
#endif

#ifdef DEBUG
    assert(players[num]!=NULL);
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
    g_playerPointers[player_num]->vertical_bounce_adjust = 0.0f;
    g_playerPointers[player_num]->field_94 = 0;
    g_playerPointers[player_num]->field_98 = 0.0f;
    g_playerPointers[player_num]->swaytarget = 0.0f;
    g_playerPointers[player_num]->swayoffset0 = 0.0f;
    g_playerPointers[player_num]->swayoffset2 = 0.0f;
    g_playerPointers[player_num]->crouchpos = CROUCH_STAND;
    g_playerPointers[player_num]->autocrouchpos = CROUCH_STAND;
    g_playerPointers[player_num]->ducking_height_offset = 0.0f;
    g_playerPointers[player_num]->field_A4 = 0.0f;
    g_playerPointers[player_num]->prop = NULL;
    g_playerPointers[player_num]->field_AC = 1;
    g_playerPointers[player_num]->field_D0 = 0;
    g_playerPointers[player_num]->ptr_char_objectinstance = NULL;
    g_playerPointers[player_num]->bonddead = FALSE;
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
    g_playerPointers[player_num]->movecentrerelease = FALSE;
    g_playerPointers[player_num]->lookaheadcentreenabled = TRUE;
    g_playerPointers[player_num]->automovecentreenabled = TRUE;
    g_playerPointers[player_num]->fastmovecentreenabled = FALSE;
    g_playerPointers[player_num]->automovecentre = TRUE;
    g_playerPointers[player_num]->insightaimmode = FALSE;
    g_playerPointers[player_num]->autoyaimenabled = TRUE;
    g_playerPointers[player_num]->autoaimy = 0.0f;
    g_playerPointers[player_num]->autoaim_target_y = NULL;
    g_playerPointers[player_num]->autoyaimtime60 = -1;
    g_playerPointers[player_num]->autoxaimenabled = TRUE;
    g_playerPointers[player_num]->autoaimx = 0.0f;
    g_playerPointers[player_num]->autoaim_target_x = NULL;
    g_playerPointers[player_num]->autoxaimtime60 = -1;
    g_playerPointers[player_num]->vv_theta = 0.0f;
    g_playerPointers[player_num]->speedtheta = 0.0f;
    g_playerPointers[player_num]->vv_costheta = 1.0f;
    g_playerPointers[player_num]->vv_sintheta = 0.0f;
    g_playerPointers[player_num]->vv_verta = -4.0f;
    // @bug
    // -229.1831 degrees = -4 radians
    // This doesn't matter, because bondviewApplyVertaTheta overwrites vv_verta360 with the value from vv_verta
    g_playerPointers[player_num]->vv_verta360 = -229.1831f;
    g_playerPointers[player_num]->speedverta = 0.0f;
    g_playerPointers[player_num]->vv_cosverta = 1.0f;
    g_playerPointers[player_num]->vv_sinverta = 0.0f;
    g_playerPointers[player_num]->speedsideways = 0.0f;
    g_playerPointers[player_num]->speedstrafe = 0.0f;
    g_playerPointers[player_num]->speedforwards = 0.0f;
    g_playerPointers[player_num]->speedgo = 0.0f;
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
    g_playerPointers[player_num]->timer_1C4 = 0;
    g_playerPointers[player_num]->watch_animation_state = WATCH_ANIMATION_0x0;
    g_playerPointers[player_num]->outside_watch_menu = TRUE;
    g_playerPointers[player_num]->open_close_solo_watch_menu = FALSE;
    g_playerPointers[player_num]->field_1D4 = 0.0f;
    g_playerPointers[player_num]->field_1D8 = 0.0f;
    g_playerPointers[player_num]->pause_watch_position = -25;
    g_playerPointers[player_num]->field_1E0 = 0.0f;
    g_playerPointers[player_num]->field_1E4 = 1.0f;
    g_playerPointers[player_num]->field_1E8 = 0.0f;
    g_playerPointers[player_num]->field_1EC = 0.0f;
    g_playerPointers[player_num]->field_1F0 = 0.0f;
    g_playerPointers[player_num]->field_1F4 = 1.0f;
    g_playerPointers[player_num]->pausing_flag = FALSE;
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
    g_playerPointers[player_num]->prev_buttons_pressed = 0;
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
    g_playerPointers[player_num]->bondtype = CUFF_BLUE;
    g_playerPointers[player_num]->startnewbonddie = TRUE;
    g_playerPointers[player_num]->redbloodfinished = FALSE;
    g_playerPointers[player_num]->deathanimfinished = FALSE;
    g_playerPointers[player_num]->field_42c = 2;
    g_playerPointers[player_num]->controldef = CONTROLLER_CONFIG_HONEY;
    g_playerPointers[player_num]->resetheadpos = TRUE;
    g_playerPointers[player_num]->resetheadrot = TRUE;
    g_playerPointers[player_num]->resetheadtick = TRUE;
    g_playerPointers[player_num]->headanim = 0;
    g_playerPointers[player_num]->headdamp = DEFAULT_HEADDAMP;
    g_playerPointers[player_num]->headwalkingtime60 = 0;
    g_playerPointers[player_num]->headamplitude = 1.0f;
    g_playerPointers[player_num]->sideamplitude = 1.0f;
    g_playerPointers[player_num]->headpos.f[0] = 0.0f;
    g_playerPointers[player_num]->headpos.f[1] = 0.0f;
    g_playerPointers[player_num]->headpos.f[2] = 0.0f;
    g_playerPointers[player_num]->headlook.f[0] = 0.0f;
    g_playerPointers[player_num]->headlook.f[1] = 0.0f;
    g_playerPointers[player_num]->headlook.f[2] = 1.0f;
    g_playerPointers[player_num]->headup.f[0] = 0.0f;
    g_playerPointers[player_num]->headup.f[1] = 1.0f;
    g_playerPointers[player_num]->headup.f[2] = 0.0f;
    g_playerPointers[player_num]->headpossum.f[0] = 0.0f;
    g_playerPointers[player_num]->headpossum.f[1] = 0.0f;
    g_playerPointers[player_num]->headpossum.f[2] = 0.0f;
    g_playerPointers[player_num]->headlooksum.f[0] = 0.0f;
    g_playerPointers[player_num]->headlooksum.f[1] = 0.0f;
    g_playerPointers[player_num]->headlooksum.f[2] = DEFAULT_HEADLOOKSUM_VAL;
    g_playerPointers[player_num]->headupsum.f[0] = 0.0f;
    g_playerPointers[player_num]->headupsum.f[1] = DEFAULT_HEADLOOKSUM_VAL;
    g_playerPointers[player_num]->headupsum.f[2] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset.f[0] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset.f[1] = 0.0f;
    g_playerPointers[player_num]->headbodyoffset.f[2] = 0.0f;
    g_playerPointers[player_num]->standheight = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.x = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.y = 0.0f;
    g_playerPointers[player_num]->standbodyoffset.z = 0.0f;
    g_playerPointers[player_num]->standfrac = 0.0f;
    g_playerPointers[player_num]->standlook[0].f[0] = 0.0f;
    g_playerPointers[player_num]->standlook[0].f[1] = 0.0f;
    g_playerPointers[player_num]->standlook[0].f[2] = 1.0f;
    g_playerPointers[player_num]->standlook[1].f[0] = 0.0f;
    g_playerPointers[player_num]->standlook[1].f[1] = 0.0f;
    g_playerPointers[player_num]->standlook[1].f[2] = 1.0f;
    g_playerPointers[player_num]->standup[0].f[0] = 0.0f;
    g_playerPointers[player_num]->standup[0].f[1] = 1.0f;
    g_playerPointers[player_num]->standup[0].f[2] = 0.0f;
    g_playerPointers[player_num]->standup[1].f[0] = 0.0f;
    g_playerPointers[player_num]->standup[1].f[1] = 1.0f;
    g_playerPointers[player_num]->standup[1].f[2] = 0.0f;
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
    g_playerPointers[player_num]->hand_invisible[GUNRIGHT] = 0;
    g_playerPointers[player_num]->hand_invisible[GUNLEFT] = 0;
    g_playerPointers[player_num]->hand_item[GUNRIGHT] = ITEM_UNARMED;
    g_playerPointers[player_num]->hand_item[GUNLEFT] = ITEM_UNARMED;
    g_playerPointers[player_num]->field_2A44[GUNRIGHT] = -1;
    g_playerPointers[player_num]->field_2A44[GUNLEFT] = -1;
    g_playerPointers[player_num]->lock_hand_model[GUNRIGHT] = FALSE;
    g_playerPointers[player_num]->lock_hand_model[GUNLEFT] = FALSE;
    g_playerPointers[player_num]->ptr_hand_weapon_buffer[GUNRIGHT] = NULL;
    g_playerPointers[player_num]->ptr_hand_weapon_buffer[GUNLEFT] = NULL;

    g_playerPointers[player_num]->hands[GUNRIGHT] = default_hand;
    g_playerPointers[player_num]->hands[GUNLEFT] = default_hand;

    g_playerPointers[player_num]->gunposamplitude = 1.0f;
    g_playerPointers[player_num]->gunxamplitude = 1.0f;
    g_playerPointers[player_num]->field_FC8 = 0;
    g_playerPointers[player_num]->field_FCC = 0;
    g_playerPointers[player_num]->field_FD0 = 0;
    g_playerPointers[player_num]->z_trigger_timer = 0;
    g_playerPointers[player_num]->field_FD8 = 0;
    g_playerPointers[player_num]->tileColor.rgba[0] = 0xFF;
    g_playerPointers[player_num]->tileColor.rgba[1] = 0xFF;
    g_playerPointers[player_num]->tileColor.rgba[2] = 0xFF;
    g_playerPointers[player_num]->tileColor.rgba[3] = 0;
    g_playerPointers[player_num]->resetshadecol = TRUE;
    g_playerPointers[player_num]->aimtype = 0;
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
    g_playerPointers[player_num]->field_1010.y = -M_PI_F;
    g_playerPointers[player_num]->field_1010.z = 0.0f;
    g_playerPointers[player_num]->last_z_trigger_timer = 0;
    g_playerPointers[player_num]->copiedgoldeneye = FALSE;
    g_playerPointers[player_num]->gunammooff = FALSE;
    g_playerPointers[player_num]->gunsync = 0.0f;
    g_playerPointers[player_num]->syncchange = 0.0f;
    g_playerPointers[player_num]->synccount = 0.0f;
    g_playerPointers[player_num]->syncoffset = 0;
    g_playerPointers[player_num]->field_107C = 0.0f;
    g_playerPointers[player_num]->field_1080 = 0.0f;
    g_playerPointers[player_num]->sniper_zoom = 60.0f;
    g_playerPointers[player_num]->camera_zoom = 60.0f;
    g_playerPointers[player_num]->curRoomIndex = -1;
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
    g_playerPointers[player_num]->hudmessoff = FALSE;
    g_playerPointers[player_num]->bondmesscnt = -1;
    g_playerPointers[player_num]->ptr_inventory_first_in_cycle = NULL;
    g_playerPointers[player_num]->p_itemcur = NULL;
    g_playerPointers[player_num]->equipmaxitems = FALSE;
    g_playerPointers[player_num]->equipallguns = FALSE;
    one = 1;
    g_playerPointers[player_num]->equipcuritem = ITEM_UNARMED;
    g_playerPointers[player_num]->textoverrides = NULL;
    g_playerPointers[player_num]->field_1280 = 0.0f;
    g_playerPointers[player_num]->players_cur_animation = 0;
    g_playerPointers[player_num]->field_1288 = 0.0f;
    g_playerPointers[player_num]->bondinvincible = FALSE;
    g_playerPointers[player_num]->healthDamageType = 7;
    g_playerPointers[player_num]->field_29BC = 1.0f;
    g_playerPointers[player_num]->field_29C0 = 0.0f;
    g_playerPointers[player_num]->mpmenuon = FALSE;
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
    g_playerPointers[player_num]->cur_item_weapon_getname = ITEM_FIST;
    g_playerPointers[player_num]->actual_health = 1.0f;
    g_playerPointers[player_num]->actual_armor = 1.0f;
    g_playerPointers[player_num]->cur_player_control_type_0 = CONTROLLER_CONFIG_HONEY;
    g_playerPointers[player_num]->cur_player_control_type_1 = CONTROLLER_CONFIG_HONEY;
    g_playerPointers[player_num]->cur_player_control_type_2 = 0.0f; //CONTROLLER_CONFIG_HONEY
    g_playerPointers[player_num]->neg_vspacing_for_control_type_entry = 0;
    g_playerPointers[player_num]->has_set_control_type_data = one;
    g_playerPointers[player_num]->field_2A6C = 0;
    g_playerPointers[player_num]->field_2A70 = NULL;

    g_VisibleToGuardsFlag = TRUE;
    obj_collision_flag = TRUE;
}


void set_cur_player(s32 playernum)
{
#ifdef DEBUG
    assert(num>=0);
    assert(num<4);
    assert(players[num]!=NULL); //player.c
#endif

    player_num = playernum;
    g_CurrentPlayer = g_playerPointers[playernum];
    g_playerPerm = &g_playerPlayerData[playernum];
}


s32 get_cur_playernum(void) {
    return player_num;
}

s32 getPlayerPointerIndex(PropRecord* prop)
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
       assert(currentplayer);
    #endif
  g_CurrentPlayer->viewx = width;
  g_CurrentPlayer->viewy = height;
}

void set_cur_player_viewport_size(u32 ulx, u32 uly) {
        #ifdef XBLADEBUG
       assert(currentplayer);
    #endif
  g_CurrentPlayer->viewleft = ulx;
  g_CurrentPlayer->viewtop = uly;
}

void set_cur_player_fovy(f32 fovy) {
    #ifdef XBLADEBUG
       assert(currentplayer);
    #endif
    g_CurrentPlayer->fovy = fovy;
}

void set_cur_player_aspect(f32 aspect) {
    #ifdef XBLADEBUG
       assert(currentplayer);
    #endif
    g_CurrentPlayer->aspect = aspect;
}

f32 get_cur_player_fovy(void) {
    #ifdef XBLADEBUG
       assert(currentplayer);
    #endif
    return g_CurrentPlayer->fovy;
}


PROP getPropForHeldItem(ITEM_IDS arg0)
{
    PROP ret = -1;
    switch (arg0)
    {
        case ITEM_KNIFE:         ret = PROP_CHRKNIFE;         break; /* weapon_multi_hunting_knife */
        case ITEM_WPPK:          ret = PROP_CHRWPPK;          break; /* weapon_multi_pp7 */
        case ITEM_SKORPION:      ret = PROP_CHRSKORPION;      break; /* weapon_multi_klobb */
        case ITEM_AK47:          ret = PROP_CHRKALASH;        break; /* weapon_multi_kf7 */
        case ITEM_UZI:           ret = PROP_CHRUZI;           break; /* weapon_multi_zmg */
        case ITEM_MP5K:          ret = PROP_CHRMP5K;          break; /* weapon_multi_d5k */
        case ITEM_SPECTRE:       ret = PROP_CHRSPECTRE;       break; /* weapon_multi_phantom */
        case ITEM_M16:           ret = PROP_CHRM16;           break; /* weapon_multi_ar33 */
        case ITEM_FNP90:         ret = PROP_CHRFNP90;         break; /* weapon_multi_rcp90 */
        case ITEM_SHOTGUN:       ret = PROP_CHRSHOTGUN;       break; /* weapon_multi_shotgun */
        case ITEM_GRENADELAUNCH: ret = PROP_CHRGRENADELAUNCH; break; /* weapon_multi_grenade_laun */
        case ITEM_GRENADE:       ret = PROP_CHRGRENADE;       break; /* weapon_multi_hand */
        case ITEM_REMOTEMINE:    ret = PROP_CHRREMOTEMINE;    break; /* weapon_multi_remote */
        case ITEM_PROXIMITYMINE: ret = PROP_CHRPROXIMITYMINE; break; /* weapon_multi_prox */
        case ITEM_TIMEDMINE:     ret = PROP_CHRTIMEDMINE;     break; /* weapon_multi_timed */
        case ITEM_RUGER:         ret = PROP_CHRRUGER;         break; /* weapon_multi_cougar */
        case ITEM_LASER:         ret = PROP_CHRLASER;         break; /* weapon_multi_moonraker */
        case ITEM_SNIPERRIFLE:   ret = PROP_CHRSNIPERRIFLE;   break; /* weapon_multi_sniper */
        case ITEM_MP5KSIL:       ret = PROP_CHRMP5KSIL;       break; /* weapon_multi_d5k_silent */
        case ITEM_TT33:          ret = PROP_CHRTT33;          break; /* weapon_multi_dd44 */
        case ITEM_WPPKSIL:       ret = PROP_CHRWPPKSIL;       break; /* weapon_multi_pp7_silent */
        case ITEM_THROWKNIFE:    ret = PROP_CHRTHROWKNIFE;    break; /* weapon_multi_throwing_knife */
        case ITEM_AUTOSHOT:      ret = PROP_CHRAUTOSHOT;      break; /* weapon_multi_auto_shot */
        case ITEM_ROCKETLAUNCH:  ret = PROP_CHRROCKETLAUNCH;  break; /* weapon_multi_rocket_launch */
        case ITEM_GOLDENGUN:     ret = PROP_CHRGOLDEN;        break; /* weapon_multi_goldengun */
        case ITEM_SILVERWPPK:    ret = PROP_CHRWPPK;          break; /* weapon_multi_pp7_special1 */
        case ITEM_GOLDWPPK:      ret = PROP_CHRWPPK;          break; /* weapon_multi_pp7_special2 */
        case ITEM_TOKEN:         ret = PROP_FLAG;             break;
        case ITEM_UNARMED:       break;
        case ITEM_TASER:         break;
    }
    return ret;
}


void sub_GAME_7F09B368(enum GUNHAND hand)
{
    chrSetWeaponFlag4(g_CurrentPlayer->prop->chr, hand);
}

void sub_GAME_7F09B398(enum GUNHAND hand)
{
    ChrRecord *chr;
    enum ITEM_IDS wepid;
    enum PROP prop;
    s32 flags;

    chr = g_CurrentPlayer->prop->chr;

    if (chr->weapons_held[hand] == NULL)
    {
        wepid = getCurrentPlayerWeaponId(hand);
        prop = getPropForHeldItem(wepid);
        if (prop >= 0)
        {
            flags = ((hand * 4) == 0)
                  ? 0
                  : PROPFLAG_WEAPON_LEFTHANDED;
            something_with_generating_object(chr, prop, wepid, flags, NULL, NULL);
        }
    }
}

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
