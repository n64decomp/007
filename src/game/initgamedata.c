#include <ultra64.h>
#include "front.h"
#include <bondconstants.h>
 /**
  * initGameData
  * 
  **/
void initGameData(void) {
    current_menu = MENU_INVALID;
    menu_update = MENU_LEGAL_SCREEN;
    maybe_prev_menu = MENU_INVALID;
    g_MenuTimer = 0;
    selected_stage = LEVELID_NONE;
    briefingpage = BRIEFING_INVALID;
    selected_difficulty = DIFFICULTY_MULTI;
    screen_size = SCREEN_SIZE_320x240;
    folder_selection_screen_option_icon = 0;
    selected_folder_num = FOLDER1;
    mission_failed_or_aborted = FALSE;
    is_first_time_on_legal_screen = TRUE;
    is_first_time_on_main_menu = TRUE;
    prev_keypresses = FALSE;
    maybe_is_in_menu = TRUE;
    slider_007_mode_reaction = 0.0f;
    slider_007_mode_health = 1.0f;
    slider_007_mode_accuracy = 1.0f;
    slider_007_mode_damage = 1.0f;
    intro_character_index = 0;
    randomly_selected_intro_animation = ANIM_idle;
    intro_animation_count = 0;
    cast_model = NULL;
    cast_model_weapon = NULL;
    full_actor_intro = FALSE;
}


