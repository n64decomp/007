#include "ultra64.h"
#include "game/mainmenu.h"

void initGameData(void) {
    current_menu = -1;
    menu_update = 0;
    maybe_prev_menu = -1;
    menu_timer = 0;
    selected_stage = -1;
    briefingpage = -1;
    selected_difficulty = -1;
    screen_size = 0;
    folder_selection_screen_option_icon = 0;
    selected_folder_num = 0;
    mission_failed_or_aborted = 0;
    is_first_time_on_legal_screen = 1;
    is_first_time_on_main_menu = 1;
    prev_keypresses = 0;
    maybe_is_in_menu = 1;
    slider_007_mode_reaction = 0.0f;
    slider_007_mode_health = 1.0f;
    slider_007_mode_accuracy = 1.0f;
    slider_007_mode_damage = 1.0f;
    do_not_play_intro_movie = 0;
    randomly_selected_intro_animation = 0;
    intro_animation_count = 0;
    objinstance = 0;
    ptrobjinstance = 0;
    full_actor_intro = 0;
}


