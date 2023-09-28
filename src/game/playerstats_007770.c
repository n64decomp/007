#include <ultra64.h>

void set_favorite_weapon_for_every_player(void) {
    int right_hand;
    int left_hand;
    int player_count;
    int current_player;
    int player;

    player_count = getPlayerCount();
    current_player = get_cur_playernum();

    for (player = 0; player < player_count; player++) {
        set_cur_player(player);
        bondinvGetWeaponOfChoice(&right_hand, &left_hand);
        store_favorite_weapon_current_player(right_hand, left_hand);
    }

    set_cur_player(current_player);
}

