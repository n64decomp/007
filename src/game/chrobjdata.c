#include "ultra64.h"
#include "bondgame.h"
#include "game/chrobjdata.h"
// bss


/* global ai lists used for all levels */
// data
//D:80037070
u8 dword_D_80037070[] = { // GLIST_AIM_AT_BOND: continuously aim at bond with weapon
    guard_try_fire_or_aim_at_target(TARGET_BOND | TARGET_AIM_ONLY, 0, 0x01)
    goto_loop_infinite(0x01)
    ai_list_end
};

//D:8003707C
u8 dword_D_8003707C[] = { // GLIST_END_ROUTINE: end routine (loop forever)
    goto_loop_infinite(0x11)
    ai_list_end
};

//D:80037084
u8 dword_D_80037084[] = { // GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE: wait for bond detection (spawn clone when heard bond)
    goto_loop_start(0x01)
        if_chr_dying_or_dead(CHR_SELF, 0x11) // guard died, safely end list
        if_guard_has_stopped_moving(0x06) // guard has stopped moving, safe to continue
        goto_loop_repeat(0x01)
    label(0x06)
        if_guard_sees_bond(0x07)
        if_guard_was_shot_or_seen_bond_within_last_10_secs(0x0D)
        if_guard_heard_bond_within_last_10_secs(0x0E)
        if_guard_shot_from_bond_missed(0x10)
        if_guard_see_another_guard_shot(0x0D)
        if_guard_see_another_guard_die(0x0D)
        if_guard_playing_animation(0x03) // playing idle animation
        random_generate_greater_than(1, 0x03) // 1/255 chance of playing idle animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_IDLE_RAND_ANIM_SUBROUTINE) // play idle animation and return to list
    label(0x03)
        goto_loop_repeat(0x01)
    label(0x10) // bond shot near guard
        random_generate_greater_than(127, 0x07) // 50% chance of playing looking around animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE)
    label(0x07) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x0D) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    label(0x0E) // guard heard bond, attempt to spawn clone (only if chr has clone flag)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND)
    label(0x11) // guard has died, end routine
        jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:800370DC
u8 dword_D_800370DC[] = { // GLIST_IDLE_RAND_ANIM_SUBROUTINE: play idle animation (subroutine)
    random_generate_greater_than(50, 0x03) // generate annd compare random seed to see which animation to play
    guard_play_animation(ANIM_yawning, 0, 193, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
    goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(100, 0x03)
        guard_play_animation(ANIM_swatting_flies, 0, 294, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(150, 0x03)
        guard_play_animation(ANIM_scratching_leg, 0, 183, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(200, 0x03)
        guard_play_animation(ANIM_scratching_butt, 0, 123, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(250, 0x03)
        guard_play_animation(ANIM_adjusting_crotch, 0, 56, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        guard_play_animation(ANIM_sneeze, 0, 137, ANIM_IDLE_POSE_WHEN_COMPLETE | ANIM_PLAY_SFX, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x02)
        jump_to_return_ai_list
    ai_list_end
};

//D:8003713C
u8 dword_D_8003713C[] = { // GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE: play use keyboard animation (subroutine)
    random_generate_greater_than(60, 0x03)
    guard_play_animation(ANIM_keyboard_right_hand1, 0, 69, 0x00, ANIM_DEFAULT_INTERPOLATION)
    goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(120, 0x03)
        guard_play_animation(ANIM_keyboard_right_hand2, 0, 74, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        if_random_seed_greater_than(180, 0x03)
        guard_play_animation(ANIM_keyboard_left_hand, 0, 79, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x03)
        guard_play_animation(ANIM_keyboard_right_hand_tapping, 0, 89, 0x00, ANIM_DEFAULT_INTERPOLATION)
        goto_next(0x02) // jump to end, we're done
    label(0x02)
        jump_to_return_ai_list
    ai_list_end
};

//D:8003717C
u8 dword_D_8003717C[] = { // GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM: wait for bond detection (deaf/no clones/no idling)
    goto_loop_start(0x01) // wait for guard to stop moving before branching to next logic
        if_guard_has_stopped_moving(0x06)
        goto_loop_repeat(0x01)
    label(0x06)
        if_guard_sees_bond(0x07)
        if_guard_was_shot_or_seen_bond_within_last_10_secs(0x0D)
        if_guard_shot_from_bond_missed(0x10)
        if_guard_see_another_guard_shot(0x0D)
        if_guard_see_another_guard_die(0x0D)
        goto_loop_repeat(0x01)
    label(0x10) // bond shot near guard
        random_generate_greater_than(127, 0x07) // 50% chance of playing looking around animation
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE)
    label(0x07) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x0D) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800371B4
u8 dword_D_800371B4[] = { // GLIST_FIRE_RAND_ANIM_SUBROUTINE: fire at bond with random animation (subroutine)
    if_guard_bitfield_is_set_on(BITFIELD_DONT_POINT_AT_BOND, 0x03) // if guard already pointed at bond, goto label 03
    random_generate_greater_than(32, 0x03) // 12.5% chance of pointing to bond
    guard_points_at_bond
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // don't point again, thank you object permanence
    jump_to_return_ai_list // guard pointed at bond, return to list
    label(0x03)
        guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // set flag so we don't point at bond, only do that for first time in list
        guard_try_throwing_grenade(0x02) // attempt to throw grenade, depends on chr->grenadeprob value
    label(0x03)
        random_generate_greater_than(10, 0x03)
        guard_try_firing_roll(0x02)
    label(0x03)
        random_generate_greater_than(10, 0x03)
        guard_try_hopping_sideways(0x02)
    label(0x03)
        random_generate_greater_than(25, 0x03)
        guard_try_sidestepping(0x02)
    label(0x03)
        random_generate_greater_than(50, 0x03)
        guard_try_running_to_side(0x02)
    label(0x03)
        random_generate_greater_than(64, 0x03)
        guard_try_firing_walk(0x02) // infinite ammo death sentence ;)
    label(0x03)
        if_random_seed_greater_than(127, 0x03)
        guard_try_firing_run(0x02)
    label(0x03)
        random_generate_greater_than(127, 0x0B)
        guard_try_fire_or_aim_at_target(TARGET_BOND, 0, 0x02)
    label(0x0B)
        guard_try_fire_or_aim_at_target_kneel(TARGET_BOND, 0, 0x02)
    label(0x02) // guard did the thing, now go back home
        jump_to_return_ai_list
    ai_list_end
};

//D:8003720C
u8 dword_D_8003720C[] = { // GLIST_RUN_TO_BOND_SUBROUTINE: run to bond and fire (subroutine)
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // guard is aware of bond, so don't point at him when first spotted
    guard_try_running_to_bond_position(0x01) // goto loop if bond position is reachable
    jump_to_return_ai_list // if guard can't reach bond, return to ai list (read guard_try_running_to_bond_position command info)
    goto_loop_start(0x01)
        if_guard_has_stopped_moving(0x06)
        if_guard_sees_bond(0x07) // detected bond, goto attack list
        goto_loop_repeat(0x01)
    label(0x07)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x06)
        jump_to_return_ai_list
    ai_list_end
};

//D:80037224
u8 dword_D_80037224[] = { // GLIST_SPAWN_CLONE_OR_RUN_TO_BOND: if chr has been seen, run to bond - else spawn clone
    guard_bitfield_set_on(BITFIELD_DONT_POINT_AT_BOND) // guard is aware of bond, so don't point at him when first spotted
    if_guard_has_not_been_seen(0x0E) // if guard has yet to be seen by bond, goto 0E
    jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE) // guard has been seen, run to bond and fire
    label(0x0E)
        if_chr_does_not_exist(CHR_CLONE, 0x0E) // if clone doesn't exist, goto 0E
        jump_to_ai_list(CHR_SELF, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE) // continue idling
    label(0x0E)
        chr_try_spawning_clone(CHR_SELF, GLIST_RUN_TO_BOND_AND_FIRE, 0x03) // attempt to spawn clone with run to bond list assigned, if success goto 03
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE) // guard failed to spawn (not enough memory/guard doesn't have clone flag on), just run at bond anyway
    label(0x03) // if clone spawn was successful
        jump_to_ai_list(CHR_SELF, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE) // set original chr to sit tight while the clone does all the work, giving the illusion that bunker ii is a crowded complex
    ai_list_end
};

//D:80037248
u8 dword_D_80037248[] = { // GLIST_RUN_TO_BOND_AND_FIRE: run to bond and fire
    set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
    jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:80037250
u8 dword_D_80037250[] = { // GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM: wait for bond detection (no clones/no idling)
    goto_loop_start(0x01) // wait for guard to stop moving before branching to next logic
        if_guard_sees_bond(0x07)
        if_guard_was_shot_or_seen_bond_within_last_10_secs(0x0D)
        if_guard_heard_bond_within_last_10_secs(0x0D)
        if_guard_shot_from_bond_missed(0x0D)
        if_guard_see_another_guard_shot(0x0D)
        if_guard_see_another_guard_die(0x0D)
        goto_loop_repeat(0x01)
    label(0x07) // guard sees bond
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_FIRE_RAND_ANIM_SUBROUTINE)
    label(0x0D) // guard saw another guard shot/die or guard was shot
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    label(0x0E) // unused spawn clone reaction for hearing bond, likely made game too difficult/slow
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND)
    ai_list_end
};

//D:80037280
u8 dword_D_80037280[] = { // GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM: run to chr->padpreset1 and activate alarm
    goto_loop_start(0x01) // wait for guard to stop moving before branching to next logic
        if_guard_has_stopped_moving(0x06)
        goto_loop_repeat(0x01)
    label(0x06)
        if_guard_sees_bond(0x0F)
        if_guard_hits_missed_greater_than(0, 0x10)
        if_guard_heard_bond_within_last_10_secs(0x10)
        if_guard_see_another_guard_shot(0x10)
        if_guard_see_another_guard_die(0x10)
        goto_loop_repeat(0x01)
    label(0x10) // a guard in sight was killed/shot, heard bond or bond shot guard
        if_guard_hits_greater_than(0, 0x0F) // doesn't make sense why the guard would be mildly curious about getting shot
        guard_looks_around_self
    goto_loop_start(0x04) // wait for guard to stop moving before branching to next logic (triggered by look around animation)
        if_guard_has_stopped_moving(0x0F)
        goto_loop_repeat(0x04)
    label(0x0F)
        guard_runs_to_pad(PAD_PRESET)
    goto_loop_start(0x03) // wait for guard to stop moving (reached destination/guard was shot)
        if_guard_has_stopped_moving(0x02)
        goto_loop_repeat(0x03)
    label(0x02)
        if_chr_meters_to_pad_greater_than(CHR_SELF, 1, PAD_PRESET, 0x02) // if guard is more than 1 meter away from alarm, skip to attack ai list
        guard_try_triggering_alarm_at_pad(PAD_PRESET, 0x05)
        goto_next(0x02) // didn't activate alarm (alarm destroyed?)
    goto_loop_start(0x05) // wait for guard to finish activating alarm
        if_guard_has_stopped_moving(0x02)
        goto_loop_repeat(0x05)
    label(0x02)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800372D0
u8 dword_D_800372D0[] = { // GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE: startle character (subroutine)
    guard_looks_around_self // trigger animation
    goto_loop_start(0x01)
        if_guard_has_stopped_moving(0x02) // wait for chr to stop moving
        goto_loop_repeat(0x01)
    label(0x02) // chr stopped moving
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:800372E0
u8 dword_D_800372E0[] = { // GLIST_RUN_TO_BOND_AND_FIRE_HALT_CHR_RANDOMLY: forever chase bond and fire (halt randomly)
    label(0x28)
        guard_try_running_to_bond_position(0x1B) // goto loop if bond position is reachable
        debug_log 'n','o',' ','g','o','!','\n', debug_log_end // guard can't reach bond
    goto_loop_start(0x1B)
        if_guard_and_bond_within_line_of_sight(0x06)
        if_guard_has_stopped_moving(0x02)
        goto_loop_repeat(0x1B)
    label(0x01)
        ai_sleep
        if_guard_hits_less_than(6, 0x2D)
        if_guard_flags_is_set_on(CHRFLAG_INVINCIBLE, 0x2F)
    label(0x2D)
        if_guard_has_stopped_moving(0x06)
        if_guard_meters_to_bond_greater_than(20, 0x03) // if guard is further than 20 meters away from bond, goto 03
        goto_first(0x01)
    label(0x03)
        goto_first(0x28)
    label(0x06)
        if_guard_and_bond_within_line_of_sight(0x03)
        goto_next(0x02)
    label(0x24)
        ai_sleep
        if_guard_meters_to_bond_less_than(5, 0x03) // if guard is within 5 meters from bond, goto 03
        if_guard_has_stopped_moving(0x03)
        goto_first(0x28)
    label(0x03)
        if_guard_flags_is_set_on(CHRFLAG_INVINCIBLE, 0x2F)
    label(0x2B)
        random_generate_greater_than(10, 0x03)
        guard_try_throwing_grenade(0x02) // attempt to throw grenade, depends on chr->grenadeprob value
    label(0x03)
        if_random_seed_greater_than(50, 0x03)
        guard_try_sidestepping(0x02)
    label(0x03)
        if_random_seed_greater_than(60, 0x03)
        guard_try_firing_roll(0x02)
    label(0x03)
        if_random_seed_greater_than(80, 0x03)
        guard_try_firing_roll(0x02)
    label(0x03)
        if_random_seed_greater_than(100, 0x03)
        guard_try_firing_walk(0x02)
    label(0x03)
        if_random_seed_greater_than(150, 0x03)
        guard_try_firing_run(0x02)
    label(0x03)
        if_random_seed_greater_than(200, 0x03)
        guard_try_fire_or_aim_at_target(TARGET_BOND, 0, 0x02)
    label(0x03)
        guard_try_fire_or_aim_at_target_kneel(TARGET_BOND, 0, 0x02)
    label(0x02)
        if_guard_and_bond_within_line_of_sight(0x03)
        goto_next(0x1B)
    label(0x1B)
        ai_sleep
        random_generate_greater_than(160, 0x03)
        goto_next(0x1C)
    label(0x03)
        ai_sleep
        goto_first(0x01)
    label(0x1C)
        local_timer_reset_start
        guard_try_running_to_bond_position(0x1D)
    goto_loop_start(0x1D)
        if_guard_has_stopped_moving(0x03)
        if_local_timer_seconds_greater_than(1, 0x03)
        goto_loop_repeat(0x1D)
    label(0x03)
        guard_animation_stop
        debug_log 'w','a','i','t','\n', debug_log_end
        guard_bitfield_set_off(0x04)
        random_generate_greater_than(160, 0x03)
        guard_bitfield_set_on(0x04)
    label(0x03)
        local_timer_reset_start
    label(0x1E)
        ai_sleep
        if_guard_and_bond_within_line_of_sight(0x03)
        if_guard_shot_from_bond_missed(0x03)
        ai_sleep
        if_local_timer_seconds_less_than(10, 0x04) // if timer less than 10 seconds, goto 04
        if_guard_bitfield_is_set_on(0x04, 0x05)
        goto_first(0x28)
    label(0x05)
        goto_first(0x1C)
    label(0x04)
        goto_first(0x1E)
    label(0x03)
        goto_first(0x01)
    label(0x2F)
        if_guard_hits_less_than(6, 0x03)
        guard_flags_set_off(CHRFLAG_INVINCIBLE)
    label(0x03)
        goto_first(0x2B)
    ai_list_end
};

//D:800373D0
u8 dword_D_800373D0[] = { // GLIST_WAIT_ONE_SECOND_SUBROUTINE: wait for one second (subroutine)
    local_timer_reset_start
    goto_loop_start(0x1B)
        if_local_timer_seconds_greater_than(1, 0x03) // wait one second
        goto_loop_repeat(0x1B)
    label(0x03)
        jump_to_return_ai_list
    ai_list_end
};

//D:800373E0
u8 dword_D_800373E0[] = { // GLIST_EXIT_LEVEL: exit level
    exit_level
    jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:800373E8
u8 dword_D_800373E8[] = { // GLIST_DRAW_DD44_AND_FIRE: draw dd44 and fire
    guard_set_speed_rating(40) // fast boi watch out!
    guard_set_accuracy_rating(50)
    label(0x03)
        guard_try_facing_target(TARGET_BOND, 0, 0x03)
    label(0x03)
        local_timer_reset_start
    goto_loop_start(0x1B)
        if_local_timer_greater_than(20, 0x03) // wait 1/3 of a second
        goto_loop_repeat(0x1B)
    label(0x03)
        guard_play_animation(ANIM_fire_standing_draw_one_handed_weapon_fast, 0, 20, ANIM_LOOP_HOLD_LAST_FRAME, ANIM_DEFAULT_INTERPOLATION)
    goto_loop_start(0x1C)
        if_guard_has_stopped_moving(0x03)
        goto_loop_repeat(0x1C)
    label(0x03)
        guard_try_spawning_item(PROP_chrtt33, ITEM_TT33, 0, 0x03)
    label(0x03)
        guard_try_fire_or_aim_at_target(TARGET_BOND | TARGET_AIM_ONLY, 0, 0x03) // aim...
    label(0x03)
        guard_try_fire_or_aim_at_target_update(TARGET_BOND, 0, 0x03) // FIRE!
    label(0x03)
    goto_loop_start(0x1E) // loop until guard has stopped firing at bond
        if_guard_has_stopped_moving(0x03)
        goto_loop_repeat(0x1E)
    label(0x03)
        set_return_ai_list(GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE)
        jump_to_ai_list(CHR_SELF, GLIST_RUN_TO_BOND_SUBROUTINE)
    ai_list_end
};

//D:80037444
u8 dword_D_80037444[] = { // GLIST_REMOVE_CHR: remove chr
    chr_remove_instant(CHR_SELF) // remove self
    jump_to_ai_list(CHR_SELF, GLIST_END_ROUTINE)
    ai_list_end
};

//D:8003744C
struct struct_13 D_8003744C[] = { // global ai lists (glists)
    {dword_D_80037070, GLIST_AIM_AT_BOND},
    {dword_D_8003707C, GLIST_END_ROUTINE},
    {dword_D_80037084, GLIST_DETECT_BOND_SPAWN_CLONE_ON_HEARD_GUNFIRE},
    {dword_D_800370DC, GLIST_IDLE_RAND_ANIM_SUBROUTINE},
    {dword_D_8003713C, GLIST_KEYBOARD_RAND_ANIM_SUBROUTINE},
    {dword_D_8003717C, GLIST_DETECT_BOND_DEAF_NO_CLONE_NO_IDLE_ANIM},
    {dword_D_800371B4, GLIST_FIRE_RAND_ANIM_SUBROUTINE},
    {dword_D_80037250, GLIST_DETECT_BOND_NO_CLONE_NO_IDLE_ANIM},
    {dword_D_8003720C, GLIST_RUN_TO_BOND_SUBROUTINE},
    {dword_D_80037280, GLIST_RUN_TO_CHR_PADPRESET_AND_ACTIVATE_ALARM},
    {dword_D_800372D0, GLIST_STARTLE_CHR_AND_RUN_TO_BOND_SUBROUTINE},
    {dword_D_80037224, GLIST_SPAWN_CLONE_OR_RUN_TO_BOND},
    {dword_D_80037248, GLIST_RUN_TO_BOND_AND_FIRE},
    {dword_D_800372E0, GLIST_RUN_TO_BOND_AND_FIRE_HALT_CHR_RANDOMLY},
    {dword_D_800373D0, GLIST_WAIT_ONE_SECOND_SUBROUTINE},
    {dword_D_800373E0, GLIST_EXIT_LEVEL},
    {dword_D_800373E8, GLIST_DRAW_DD44_AND_FIRE},
    {dword_D_80037444, GLIST_REMOVE_CHR}
};
//D:800374DC
u32 D_800374DC[] = {0,0};

//D:800374E4
char * setup_text_pointers[] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, "UsetupsevbunkerZ",
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,"UsetupsiloZ",
    "UsetupsevbunkerZ","UsetupstatueZ","UsetupcontrolZ","UsetuparchZ","UsetuptraZ",
    "UsetupdestZ","UsetupsevbZ","UsetupaztZ","UsetuppeteZ","UsetupdepoZ","UsetuprefZ",
    "UsetupcrypZ","UsetupdamZ","UsetuparkZ","UsetuprunZ","UsetupsevxZ","UsetupjunZ",
    "UsetupdishZ","UsetupcaveZ","UsetupcatZ","UsetupcradZ","UsetupshoZ","UsetupsevxbZ",
    "UsetupeldZ","UsetupimpZ","UsetupashZ","UsetuplueZ","UsetupameZ","UsetupritZ",
    "UsetupoatZ","UsetupearZ","UsetupleeZ","UsetuplipZ","UsetuplenZ","UsetupwaxZ",
    "UsetuppamZ", NULL, NULL
};


//D:800375D0
struct PitemZ_header Palarm1z_header = {0, &model_object_standard_object, 0, 0, 1, 304.6402, 2, 0, 0};
//D:800375F0
struct PitemZ_header Palarm2Z_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 3, 0, 0};
//D:80037610
struct PitemZ_header PexplosionbitZ_header = {0, &model_object_standard_object, 0, 0, 1, 208.22205, 0, 0, 0};
//D:80037630
struct PitemZ_header Pammo_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 3, 0, 0};
//D:80037650
struct PitemZ_header Pammo_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 4, 0, 0};
//D:80037670
struct PitemZ_header Pammo_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 4, 0, 0};
//D:80037690
struct PitemZ_header Pammo_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 5, 0, 0};
//D:800376B0
struct PitemZ_header Pammo_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 691.83429, 5, 0, 0};
//D:800376D0
struct PitemZ_header Pbin1Z_header = {0, &model_object_standard_object, 0, 0, 1, 3027.6262, 2, 0};
//D:800376F0
struct PitemZ_header Pblotter1Z_header = {0, &model_object_standard_object, 0, 0, 1, 432.46707, 1, 0, 0};
//D:80037710
struct PitemZ_header Pbook1Z_header = {0, &model_object_standard_object, 0, 0, 1, 171.37482, 2, 0, };
//D:80037730
struct PitemZ_header Pbookshelf1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1166.7578, 0xD, 0, 0};
//D:80037750
struct PitemZ_header Pbridge_console1aZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0xF, 0, 0};
//D:80037770
struct PitemZ_header Pbridge_console1bZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 788.03992, 0x10, 0, 0};
//D:80037790
struct PitemZ_header Pbridge_console2aZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0xF, 0, 0};
//D:800377B0
struct PitemZ_header Pbridge_console2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 788.03992, 0xF, 0, 0};
//D:800377D0
struct PitemZ_header Pbridge_console3aZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0xF, 0, 0};
//D:800377F0
struct PitemZ_header Pbridge_console3bZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 788.03992, 0x10, 0, 0};
//D:80037810
struct PitemZ_header Pcard_box1Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 5, 0, 0};
//D:80037830
struct PitemZ_header Pcard_box2Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 6, 0, 0};
//D:80037850
struct PitemZ_header Pcard_box3Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 5, 0, 0};
//D:80037870
struct PitemZ_header Pcard_box4_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 4, 0, 0};
//D:80037890
struct PitemZ_header Pcard_box5_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 5, 0, 0};
//D:800378B0
struct PitemZ_header Pcard_box6_lgZ_header = {0, &model_object_standard_object, 0, 0, 1, 800.2074, 5, 0, 0};
//D:800378D0
struct PitemZ_header PcctvZ_header = {0, &prop_cctv_related, 0, 0, 0x40002, 558.90094, 6, 0};
//D:800378F0
struct PitemZ_header Pconsole1Z_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 1611.2357, 0xA, 0, 0};
//D:80037910
struct PitemZ_header Pconsole2Z_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 1611.2357, 0xA, 0, 0};
//D:80037930
struct PitemZ_header Pconsole3Z_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 1611.2357, 0xA, 0, 0};
//D:80037950
struct PitemZ_header Pconsole_sevaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xE, 0, 0};
//D:80037970
struct PitemZ_header Pconsole_sevbZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 994.23688, 0xB, 0, 0};
//D:80037990
struct PitemZ_header Pconsole_sevcZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xF, 0, 0};
//D:800379B0
struct PitemZ_header Pconsole_sevdZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:800379D0
struct PitemZ_header Pconsole_sev2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:800379F0
struct PitemZ_header Pconsole_sev2bZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 994.23688, 0xD, 0, 0};
//D:80037A10
struct PitemZ_header Pconsole_sev2cZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xF, 0, 0};
//D:80037A30
struct PitemZ_header Pconsole_sev2dZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:80037A50
struct PitemZ_header Pconsole_sev_GEaZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:80037A70
struct PitemZ_header Pconsole_sev_GEbZ_header = {0, &model_object_standard_object, 0, 0, 1, 994.23688, 0xD, 0, 0};
//D:80037A90
struct PitemZ_header Pdesk1Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 3, 0, };
//D:80037AB0
struct PitemZ_header Pdesk2Z_header = {0, &model_object_standard_object, 0, 0, 1, 957.18225, 3, 0, };
//D:80037AD0
struct PitemZ_header Pdesk_lamp2Z_header = {0, &model_object_standard_object, 0, 0, 1, 804.59833, 4, 0, 0};
//D:80037AF0
struct PitemZ_header Pdisc_readerZ_header = {0, &model_object_standard_object, 0, 0, 1, 214.33035, 6, 0, 0};
//D:80037B10
struct PitemZ_header Pdisk_drive1Z_header = {0, &model_object_standard_object, 0, 0, 1, 191.85779, 4, 0, 0};
//D:80037B30
struct PitemZ_header Pfiling_cabinet1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1055.5693, 2, 0, 0};
//D:80037B50
struct PitemZ_header Pjerry_can1Z_header = {0, &model_object_standard_object, 0, 0, 1, 366.61932, 4, 0, 0};
//D:80037B70
struct PitemZ_header Pkeyboard1Z_header = {0, &model_object_standard_object, 0, 0, 1, 278.23227, 2, 0, 0};
//D:80037B90
struct PitemZ_header Pkit_units1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1661.4763, 4, 0, 0};
//D:80037BB0
struct PitemZ_header Pletter_tray1Z_header = {0, &model_object_standard_object, 0, 0, 1, 252.06836, 1, 0, 0};
//D:80037BD0
struct PitemZ_header Pmainframe1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 7, 0, 0};
//D:80037BF0
struct PitemZ_header Pmainframe2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1119.4073, 7, 0, 0};
//D:80037C10
struct PitemZ_header Pmetal_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 639.18097, 2, 0, 0};
//D:80037C30
struct PitemZ_header Pmetal_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037C50
struct PitemZ_header Pmetal_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037C70
struct PitemZ_header Pmetal_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 2, 0, 0};
//D:80037C90
struct PitemZ_header Pmetal_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037CB0
struct PitemZ_header Pmissile_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 964.16296, 4, 0, 0};
//D:80037CD0
struct PitemZ_header Pmissile_rack2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1148.4724, 4, 0, 0};
//D:80037CF0
struct PitemZ_header Poil_drum1Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 2, 0, 0};
//D:80037D10
struct PitemZ_header Poil_drum2Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 4, 0, 0};
//D:80037D30
struct PitemZ_header Poil_drum3Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 4, 0, 0};
//D:80037D50
struct PitemZ_header Poil_drum5Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 3, 0, 0};
//D:80037D70
struct PitemZ_header Poil_drum6Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 3, 0, 0};
//D:80037D90
struct PitemZ_header Poil_drum7Z_header = {0, &model_object_standard_object, 0, 0, 1, 745.45892, 4, 0, 0};
//D:80037DB0
struct PitemZ_header PpadlockZ_header = {0, &model_object_standard_object, 0, 0, 1, 225.64145, 4, 0, 0};
//D:80037DD0
struct PitemZ_header Pphone1Z_header = {0, &model_object_standard_object, 0, 0, 1, 166.03481, 2, 0, 0};
//D:80037DF0
struct PitemZ_header Pradio_unit1Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E10
struct PitemZ_header Pradio_unit2Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E30
struct PitemZ_header Pradio_unit3Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E50
struct PitemZ_header Pradio_unit4Z_header = {0, &model_object_standard_object, 0, 0, 1, 354.59534, 5, 0, 0};
//D:80037E70
struct PitemZ_header Psat1_reflectZ_header = {0, &model_object_standard_object, 0, 0, 1, 5185.9409, 0xD, 0, 0};
//D:80037E90
struct PitemZ_header PsatdishZ_header = {0, &model_object_standard_object, 0, 0, 1, 2437.468, 2, 0, 0};
//D:80037EB0
struct PitemZ_header PsatboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 89.935875, 1, 0, 0};
//D:80037ED0
struct PitemZ_header Pstool1Z_header = {0, &model_object_standard_object, 0, 0, 1, 353.11398, 2, 0, 0};
//D:80037EF0
struct PitemZ_header Pswivel_chair1Z_header = {0, &model_object_standard_object, 0, 0, 1, 581.16394, 3, 0, 0};
//D:80037F10
struct PitemZ_header Ptorpedo_rackZ_header = {0, &model_object_standard_object, 0, 0, 1, 765.61725, 3, 0, 0};
//D:80037F30
struct PitemZ_header Ptv1Z_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 347.0235, 5, 0};
//D:80037F50
struct PitemZ_header Ptv_holderZ_header = {0, &prop_tv_holder_related, 0, 0, 0x40005, 1352.4841, 2, 0, 0};
//D:80037F70
struct PitemZ_header PtvscreenZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 211.74477, 1, 0, 0};
//D:80037F90
struct PitemZ_header Ptv4screenZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 211.74477, 1, 0, 0};
//D:80037FB0
struct PitemZ_header Pwood_lg_crate1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 3, 0, 0};
//D:80037FD0
struct PitemZ_header Pwood_lg_crate2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 2, 0, 0};
//D:80037FF0
struct PitemZ_header Pwood_md_crate3Z_header = {0, &model_object_standard_object, 0, 0, 1, 909.32666, 2, 0, 0};
//D:80038010
struct PitemZ_header Pwood_sm_crate4Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 3, 0, 0};
//D:80038030
struct PitemZ_header Pwood_sm_crate5Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 4, 0, 0};
//D:80038050
struct PitemZ_header Pwood_sm_crate6Z_header = {0, &model_object_standard_object, 0, 0, 1, 727.4613, 4, 0, 0};
//D:80038070
struct PitemZ_header Pwooden_table1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1095.1365, 2, 0, 0};
//D:80038090
struct PitemZ_header Pswipe_card2Z_header = {0, &model_object_standard_object, 0, 0, 1, 123.088844, 2, 0, 0};
//D:800380B0
struct PitemZ_header Pborg_crateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1010.363, 1, 0, 0};
//D:800380D0
struct PitemZ_header Pboxes4x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2424.8711, 7, 0, 0};
//D:800380F0
struct PitemZ_header Pboxes3x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2241.0935, 6, 0, 0};
//D:80038110
struct PitemZ_header Pboxes2x4Z_header = {0, &model_object_standard_object, 0, 0, 1, 2100.0, 6, 0, 0};
//D:80038130
struct PitemZ_header Psec_panelZ_header = {0, &model_object_standard_object, 0, 0, 1, 1567.2454, 3, 0, 0};
//D:80038150
struct PitemZ_header PICBM_noseZ_header = {0, &model_object_standard_object, 0, 0, 1, 2782.7126, 8, 0, 0};
//D:80038170
struct PitemZ_header PICBMZ_header = {0, &model_object_standard_object, 0, 0, 1, 14790.535, 0xE, 0};
//D:80038190
struct PitemZ_header Ptuning_console1Z_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 1139.5872, 0xE, 0, 0};
//D:800381B0
struct PitemZ_header Pdesk_arecibo1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1829.1477, 3, 0, 0};
//D:800381D0
struct PitemZ_header Plocker3Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 3, 0, 0};
//D:800381F0
struct PitemZ_header Plocker4Z_header = {0, &model_object_standard_object, 0, 0, 1, 916.99805, 3, 0, 0};
//D:80038210
struct PitemZ_header ProofgunZ_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80005, 1910.908, 0xE, 0, 0};
//D:80038230
struct PitemZ_header Pdest_engineZ_header = {0, &model_object_standard_object, 0, 0, 1, 6459.439, 0xA, 0, 0};
//D:80038250
struct PitemZ_header Pdest_exocetZ_header = {0, &model_object_standard_object, 0, 0, 1, 1644.8435, 8, 0, 0};
//D:80038270
struct PitemZ_header Pdest_gunZ_header = {0, &model_object_standard_object, 0, 0, 1, 2124.0735, 5, 0, 0};
//D:80038290
struct PitemZ_header Pdest_harpoonZ_header = {0, &model_object_standard_object, 0, 0, 1, 1798.7655, 5, 0, 0};
//D:800382B0
struct PitemZ_header Pdest_seawolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 2282.0623, 0xA, 0, 0};
//D:800382D0
struct PitemZ_header PwindowZ_header = {0, &model_object_standard_object, 0, 0, 1, 423.48956, 1, 0, 0};
//D:800382F0
struct PitemZ_header Pwindow_lib_lg1Z_header = {0, &model_object_standard_object, 0, 0, 1, 835.20624, 1, 0, 0};
//D:80038310
struct PitemZ_header Pwindow_lib_sm1Z_header = {0, &model_object_standard_object, 0, 0, 1, 601.28625, 1, 0, 0};
//D:80038330
struct PitemZ_header Pwindow_cor11Z_header = {0, &model_object_standard_object, 0, 0, 1, 414.53622, 1, 0, 0};
//D:80038350
struct PitemZ_header Pjungle3_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 28729.467, 5, 0, 0};
//D:80038370
struct PitemZ_header PpalmZ_header = {0, &model_object_standard_object, 0, 0, 1, 15501.406, 3, 0};
//D:80038390
struct PitemZ_header PpalmtreeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1781.4542, 2, 0, 0};
//D:800383B0
struct PitemZ_header Pplant2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1252.9539, 2, 0, 0};
//D:800383D0
struct PitemZ_header PlabbenchZ_header = {0, &model_object_standard_object, 0, 0, 1, 844.09717, 4, 0, 0};
//D:800383F0
struct PitemZ_header PgasbarrelZ_header = {0, &model_object_standard_object, 0, 0, 1, 725.94379, 2, 0, 0};
//D:80038410
struct PitemZ_header PgasbarrelsZ_header = {0, &model_object_standard_object, 0, 0, 1, 1174.1927, 2, 0, 0};
//D:80038430
struct PitemZ_header PbodyarmourZ_header = {0, &model_object_standard_object, 0, 0, 1, 246.94099, 7, 0, 0};
//D:80038450
struct PitemZ_header PbodyarmourvestZ_header = {0, &model_object_standard_object, 0, 0, 1, 241.82211, 2, 0, 0};
//D:80038470
struct PitemZ_header PgastankZ_header = {0, &model_object_standard_object, 0, 0, 1, 1130.0691, 5, 0, 0};
//D:80038490
struct PitemZ_header Pglassware1Z_header = {0, &model_object_standard_object, 0, 0, 1, 72.111031, 1, 0, 0};
//D:800384B0
struct PitemZ_header PhatchboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 2236.0679, 1, 0, 0};
//D:800384D0
struct PitemZ_header PbrakeunitZ_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 4, 0, 0};
//D:800384F0
struct PitemZ_header Pak47magZ_header = {0, &model_object_standard_object, 0, 0, 1, 107.11019, 2, 0, 0};
//D:80038510
struct PitemZ_header Pm16magZ_header = {0, &model_object_standard_object, 0, 0, 1, 87.934891, 2, 0, 0};
//D:80038530
struct PitemZ_header Pmp5kmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.547295, 2, 0, 0};
//D:80038550
struct PitemZ_header PskorpionmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 58.428444, 2, 0, 0};
//D:80038570
struct PitemZ_header PspectremagZ_header = {0, &model_object_standard_object, 0, 0, 1, 99.01432, 2, 0, 0};
//D:80038590
struct PitemZ_header PuzimagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 2, 0, 0};
//D:800385B0
struct PitemZ_header PsilencerZ_header = {0, &model_object_standard_object, 0, 0, 1, 63.915436, 3, 0, 0};
//D:800385D0
struct PitemZ_header PchrextinguisherZ_header = {0, &model_object_standard_object, 0, 0, 1, 425.50903, 2, 0, 0};
//D:800385F0
struct PitemZ_header PboxcartridgesZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 3, 0, 0};
//D:80038610
struct PitemZ_header Pfnp90magZ_header = {0, &model_object_standard_object, 0, 0, 1, 176.28201, 2, 0, 0};
//D:80038630
struct PitemZ_header PgoldenshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 3, 0, 0};
//D:80038650
struct PitemZ_header PmagnumshellsZ_header = {0, &model_object_standard_object, 0, 0, 1, 66.81916, 3, 0, 0};
//D:80038670
struct PitemZ_header PwppkmagZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 2, 0, 0};
//D:80038690
struct PitemZ_header Ptt33magZ_header = {0, &model_object_standard_object, 0, 0, 1, 74.28373, 2, 0, 0};
//D:800386B0
struct PitemZ_header Psev_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.7695, 3, 0, 0};
//D:800386D0
struct PitemZ_header Psev_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 6, 0, 0};
//D:800386F0
struct PitemZ_header Psev_door3_windZ_header = {0, &model_object_standard_object, 0, 0, 1, 1143.5603, 5, 0, 0};
//D:80038710
struct PitemZ_header Psev_door4_windZ_header = {0, &prop_door_related, 0, 0, 0x40001, 1143.5603, 8, 0, 0};
//D:80038730
struct PitemZ_header Psev_trislideZ_header = {0, &prop_door_related, 0, 0, 0x40001, 950.54327, 2, 0, 0};
//D:80038750
struct PitemZ_header Psev_door_v1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 6, 0, 0};
//D:80038770
struct PitemZ_header Psteel_door1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 4, 0, 0};
//D:80038790
struct PitemZ_header Psteel_door2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 9, 0, 0};
//D:800387B0
struct PitemZ_header Psteel_door3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 9, 0, 0};
//D:800387D0
struct PitemZ_header Psilo_lift_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 600.71082, 4, 0, 0};
//D:800387F0
struct PitemZ_header Psteel_door2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 1137.8739, 9, 0, 0};
//D:80038810
struct PitemZ_header Pdoor_roller1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038830
struct PitemZ_header Pdoor_roller2Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038850
struct PitemZ_header Pdoor_roller3Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038870
struct PitemZ_header Pdoor_roller4Z_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 4, 0, 0};
//D:80038890
struct PitemZ_header Pdoor_st_arec1Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 3, 0, 0};
//D:800388B0
struct PitemZ_header Pdoor_st_arec2Z_header = {0, &model_object_standard_object, 0, 0, 1, 763.03589, 3, 0, 0};
//D:800388D0
struct PitemZ_header Pdoor_dest1Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 3, 0, 0};
//D:800388F0
struct PitemZ_header Pdoor_dest2Z_header = {0, &model_object_standard_object, 0, 0, 1, 461.3873, 5, 0, 0};
//D:80038910
struct PitemZ_header Pgas_plant_sw_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.29706, 4, 0, 0};
//D:80038930
struct PitemZ_header Pgas_plant_sw2_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 2, 0, 0};
//D:80038950
struct PitemZ_header Pgas_plant_sw3_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 2, 0, 0};
//D:80038970
struct PitemZ_header Pgas_plant_sw4_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 1, 0, 0};
//D:80038990
struct PitemZ_header Pgas_plant_met1_do1Z_header = {0, &model_object_standard_object, 0, 0, 1, 862.88489, 5, 0, 0};
//D:800389B0
struct PitemZ_header Pgas_plant_wc_cub1Z_header = {0, &model_object_standard_object, 0, 0, 1, 783.8501, 3, 0, 0};
//D:800389D0
struct PitemZ_header Pgasplant_clear_doorZ_header = {0, &prop_door_related, 0, 0, 0x40001, 1025.0952, 2, 0, 0};
//D:800389F0
struct PitemZ_header Ptrain_doorZ_header = {0, &model_object_standard_object, 0, 0, 1, 456.99615, 3, 0, 0};
//D:80038A10
struct PitemZ_header Ptrain_door2Z_header = {0, &prop_door_related, 0, 0, 0x40001, 445.98541, 3, 0, 0};
//D:80038A30
struct PitemZ_header Ptrain_door3Z_header = {0, &prop_door_related, 0, 0, 0x40001, 445.98541, 4, 0, 0};
//D:80038A50
struct PitemZ_header Pdoor_eyelidZ_header = {0, &prop_eyelid_door_related, 0, 0, 0x30003, 3165.4348, 3, 0, 0};
//D:80038A70
struct PitemZ_header Pdoor_irisZ_header = {0, &prop_iris_door_related, 0, 0, 0xD000D, 1621.3601, 5, 0, 0};
//D:80038A90
struct PitemZ_header PsevdoorwoodZ_header = {0, &prop_door_related, 0, 0, 0x40001, 851.62671, 3, 0, 0};
//D:80038AB0
struct PitemZ_header PsevdoorwindZ_header = {0, &prop_door_related, 0, 0, 0x40001, 851.62671, 5, 0, 0};
//D:80038AD0
struct PitemZ_header PsevdoornowindZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.03766, 2, 0, 0};
//D:80038AF0
struct PitemZ_header PsevdoormetslideZ_header = {0, &model_object_standard_object, 0, 0, 1, 863.74707, 2, 0, 0};
//D:80038B10
struct PitemZ_header Pcryptdoor1aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 2, 0, 0};
//D:80038B30
struct PitemZ_header Pcryptdoor1bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 2, 0, 0};
//D:80038B50
struct PitemZ_header Pcryptdoor2aZ_header = {0, &model_object_standard_object, 0, 0, 1, 502.64923, 2, 0, 0};
//D:80038B70
struct PitemZ_header Pcryptdoor2bZ_header = {0, &model_object_standard_object, 0, 0, 1, 400.97537, 2, 0, 0};
//D:80038B90
struct PitemZ_header Pcryptdoor3Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 3, 0, 0};
//D:80038BB0
struct PitemZ_header Pcryptdoor4Z_header = {0, &model_object_standard_object, 0, 0, 1, 801.95074, 1, 0, 0};
//D:80038BD0
struct PitemZ_header PvertdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 1997.2246, 5, 0, 0};
//D:80038BF0
struct PitemZ_header PhatchdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 192.1653, 1, 0, 0};
//D:80038C10
struct PitemZ_header PdamgatedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 308.36456, 3, 0, 0};
//D:80038C30
struct PitemZ_header PdamtundoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 127.89996, 4, 0, 0};
//D:80038C50
struct PitemZ_header PdamchaindoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 171.36655, 2, 0, 0};
//D:80038C70
struct PitemZ_header PsilotopdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 2675.3958, 5, 0, 0};
//D:80038C90
struct PitemZ_header Pdoorprison1Z_header = {0, &model_object_standard_object, 0, 0, 1, 1062.0833, 1, 0, 0};
//D:80038CB0
struct PitemZ_header PdoorstatgateZ_header = {0, &model_object_standard_object, 0, 0, 1, 1503.9503, 3, 0, 0};
//D:80038CD0
struct PitemZ_header PchrkalashZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 403.53766, 8, 0, 0};
//D:80038CF0
struct PitemZ_header PchrgrenadelaunchZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 422.48355, 7, 0, 0};
//D:80038D10
struct PitemZ_header PchrknifeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 245.14619, 2, 0, 0};
//D:80038D30
struct PitemZ_header PchrlaserZ_header = {0, &prop_weapon_related, 0, 0, 0x30002, 444.66241, 8, 0, 0};
//D:80038D50
struct PitemZ_header Pchrm16Z_header = {0, &prop_weapon_related, 0, 0, 0x30002, 964.01367, 6, 0, 0};
//D:80038D70
struct PitemZ_header Pchrmp5kZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 277.32227, 9, 0, 0};
//D:80038D90
struct PitemZ_header PchrrugerZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 246.72643, 5, 0, 0};
//D:80038DB0
struct PitemZ_header PchrwppkZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 125.79879, 5, 0, 0};
//D:80038DD0
struct PitemZ_header PchrshotgunZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 488.88385, 8, 0, 0};
//D:80038DF0
struct PitemZ_header PchrskorpionZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 183.37708, 7, 0, 0};
//D:80038E10
struct PitemZ_header PchrspectreZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 351.26923, 6, 0, 0};
//D:80038E30
struct PitemZ_header PchruziZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 265.11813, 7, 0, 0};
//D:80038E50
struct PitemZ_header PchrgrenadeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 118.18749, 2, 0, 0};
//D:80038E70
struct PitemZ_header Pchrfnp90Z_header = {0, &prop_weapon_related, 0, 0, 0x30002, 470.04633, 7, 0, 0};
//D:80038E90
struct PitemZ_header PchrbriefcaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80038EB0
struct PitemZ_header PchrremotemineZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 87.434036, 2, 0, 0};
//D:80038ED0
struct PitemZ_header PchrproximitymineZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 87.196609, 2, 0, 0};
//D:80038EF0
struct PitemZ_header PchrtimedmineZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 87.245888, 3, 0, 0};
//D:80038F10
struct PitemZ_header PchrrocketZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.8634, 3, 0, 0};
//D:80038F30
struct PitemZ_header PchrgrenaderoundZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 96.976593, 1, 0, 0};
//D:80038F50
struct PitemZ_header PchrwppksilZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 219.44571, 6, 0, 0};
//D:80038F70
struct PitemZ_header Pchrtt33Z_header = {0, &prop_weapon_related, 0, 0, 0x30001, 142.11539, 5, 0, 0};
//D:80038F90
struct PitemZ_header Pchrmp5ksilZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 406.18033, 0xA, 0, 0};
//D:80038FB0
struct PitemZ_header PchrautoshotZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 375.50247, 8, 0, 0};
//D:80038FD0
struct PitemZ_header PchrgoldenZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 157.98299, 2, 0, 0};
//D:80038FF0
struct PitemZ_header PchrthrowknifeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 217.61888, 2, 0, 0};
//D:80039010
struct PitemZ_header PchrsniperrifleZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 616.93939, 5, 0, 0};
//D:80039030
struct PitemZ_header PchrrocketlaunchZ_header = {0, &prop_weapon_related, 0, 0, 0x30002, 501.55179, 6, 0, 0};
//D:80039050
struct PitemZ_header PhatfurryZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 3, 0, 0};
//D:80039070
struct PitemZ_header PhatfurrybrownZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 3, 0, 0};
//D:80039090
struct PitemZ_header PhatfurryblackZ_header = {0, &item_hat_related, 0, 0, 1, 152.53136, 3, 0, 0};
//D:800390B0
struct PitemZ_header PhattbirdZ_header = {0, &item_hat_related, 0, 0, 1, 114.45274, 1, 0, 0};
//D:800390D0
struct PitemZ_header PhattbirdbrownZ_header = {0, &item_hat_related, 0, 0, 1, 122.7013, 1, 0, 0};
//D:800390F0
struct PitemZ_header PhathelmetZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 1, 0, 0};
//D:80039110
struct PitemZ_header PhathelmetgreyZ_header = {0, &item_hat_related, 0, 0, 1, 163.84476, 1, 0, 0};
//D:80039130
struct PitemZ_header PhatmoonZ_header = {0, &item_hat_related, 0, 0, 1, 138.25751, 2, 0, 0};
//D:80039150
struct PitemZ_header PhatberetZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 1, 0, 0};
//D:80039170
struct PitemZ_header PhatberetblueZ_header = {0, &item_hat_related, 0, 0, 1, 116.16043, 2, 0, 0};
//D:80039190
struct PitemZ_header PhatberetredZ_header = {0, &item_hat_related, 0, 0, 1, 115.46455, 2, 0, 0};
//D:800391B0
struct PitemZ_header PhatpeakedZ_header = {0, &item_hat_related, 0, 0, 1, 148.39027, 1, 0, 0};
//D:800391D0
struct PitemZ_header PchrwristdartZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800391F0
struct PitemZ_header PchrexplosivepenZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039210
struct PitemZ_header PchrbombcaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80039230
struct PitemZ_header PchrflarepistolZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039250
struct PitemZ_header PchrpitongunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039270
struct PitemZ_header PchrfingergunZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039290
struct PitemZ_header PchrsilverwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800392B0
struct PitemZ_header PchrgoldwppkZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800392D0
struct PitemZ_header PchrdynamiteZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800392F0
struct PitemZ_header PchrbungeeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039310
struct PitemZ_header PchrdoordecoderZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 180.27969, 0x10, 0, 0};
//D:80039330
struct PitemZ_header PchrbombdefuserZ_header = {0, &model_object_standard_object, 0, 0, 1, 84.370705, 0xC, 0, 0};
//D:80039350
struct PitemZ_header PchrbugdetectorZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039370
struct PitemZ_header PchrsafecrackercaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80039390
struct PitemZ_header PchrcameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 52.775627, 0xB, 0, 0};
//D:800393B0
struct PitemZ_header PchrlockexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800393D0
struct PitemZ_header PchrdoorexploderZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800393F0
struct PitemZ_header PchrkeyanalysercaseZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 342.23688, 5, 0, 0};
//D:80039410
struct PitemZ_header PchrweaponcaseZ_header = {0, &model_object_standard_object, 0, 0, 1, 274.2905, 5, 0, 0};
//D:80039430
struct PitemZ_header PchrkeyyaleZ_header = {0, &model_object_standard_object, 0, 0, 1, 82.850311, 1, 0, 0};
//D:80039450
struct PitemZ_header PchrkeyboltZ_header = {0, &model_object_standard_object, 0, 0, 1, 151.85315, 1, 0, 0};
//D:80039470
struct PitemZ_header PchrbugZ_header = {0, &model_object_standard_object, 0, 0, 1, 104.7203, 6, 0, 0};
//D:80039490
struct PitemZ_header PchrmicrocameraZ_header = {0, &model_object_standard_object, 0, 0, 1, 126.49728, 7, 0, 0};
//D:800394B0
struct PitemZ_header PfloppyZ_header = {0, &model_object_standard_object, 0, 0, 1, 60.902443, 5, 0, 0};
//D:800394D0
struct PitemZ_header PchrgoldeneyekeyZ_header = {0, &model_object_standard_object, 0, 0, 1, 98.987083, 5, 0, 0};
//D:800394F0
struct PitemZ_header PchrpolarizedglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 53.776386, 2, 0, 0};
//D:80039510
struct PitemZ_header PchrcreditcardZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039530
struct PitemZ_header PchrdarkglassesZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039550
struct PitemZ_header PchrgaskeyringZ_header = {0, &model_object_standard_object, 0, 0, 1, 111.59859, 9, 0, 0};
//D:80039570
struct PitemZ_header PchrdatathiefZ_header = {0, &model_object_standard_object, 0, 0, 1, 119.78231, 3, 0, 0};
//D:80039590
struct PitemZ_header PsafeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1011.18744, 3, 0};
//D:800395B0
struct PitemZ_header PbombZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0};
//D:800395D0
struct PitemZ_header PchrplansZ_header = {0, &model_object_standard_object, 0, 0, 1, 384.74649, 5, 0, 0};
//D:800395F0
struct PitemZ_header PchrspyfileZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039610
struct PitemZ_header PchrblueprintsZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 4, 0, 0};
//D:80039630
struct PitemZ_header PchrcircuitboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 138.90285, 3, 0, 0};
//D:80039650
struct PitemZ_header PchrmapZ_header = {0, &model_object_standard_object, 0, 0, 1, 588.65448, 4, 0, 0};
//D:80039670
struct PitemZ_header PchrspooltapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039690
struct PitemZ_header PchraudiotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 97.531075, 9, 0, 0};
//D:800396B0
struct PitemZ_header PchrmicrofilmZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800396D0
struct PitemZ_header PchrmicrocodeZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:800396F0
struct PitemZ_header PchrlectreZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039710
struct PitemZ_header PchrmoneyZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039730
struct PitemZ_header PchrgoldbarZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039750
struct PitemZ_header PchrheroinZ_header = {0, &model_object_standard_object, 0, 0, 1, 288.67514, 1, 0, 0};
//D:80039770
struct PitemZ_header PchrclipboardZ_header = {0, &model_object_standard_object, 0, 0, 1, 190.41742, 3, 0, 0};
//D:80039790
struct PitemZ_header PchrdossierredZ_header = {0, &model_object_standard_object, 0, 0, 1, 183.54231, 4, 0, 0};
//D:800397B0
struct PitemZ_header PchrstafflistZ_header = {0, &model_object_standard_object, 0, 0, 1, 215.17534, 4, 0, 0};
//D:800397D0
struct PitemZ_header PchrdattapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 79.868584, 4, 0, 0};
//D:800397F0
struct PitemZ_header PchrplastiqueZ_header = {0, &model_object_standard_object, 0, 0, 1, 143.86052, 3, 0, 0};
//D:80039810
struct PitemZ_header PchrblackboxZ_header = {0, &model_object_standard_object, 0, 0, 1, 128.31796, 5, 0, 0};
//D:80039830
struct PitemZ_header PchrvideotapeZ_header = {0, &model_object_standard_object, 0, 0, 1, 122.69632, 9, 0, 0};
//D:80039850
struct PitemZ_header PnintendologoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1868.335, 1, 0, 0};
//D:80039870
struct PitemZ_header PgoldeneyelogoZ_header = {0, &model_object_standard_object, 0, 0, 1, 1287.1866, 2, 0, 0};
//D:80039890
struct PitemZ_header PwalletbondZ_header = {0, &prop_walletbond_related, 0, 0, 0x2B0001, 3504.53, 0x54, 0, 0};
//D:800398B0
struct PitemZ_header PmiltruckZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 4589.7188, 0x16, 0, 0};
//D:800398D0
struct PitemZ_header PjeepZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 2107.8105, 0x10, 0};
//D:800398F0
struct PitemZ_header ParticZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 2678.5667, 0x11, 0, };
//D:80039910
struct PitemZ_header PhelicopterZ_header = {0, &prop_flying_related, 0, 0, 0x60004, 4955.271, 0x18, 0, 0};
//D:80039930
struct PitemZ_header PtigerZ_header = {0, &prop_flying_related, 0, 0, 0x60004, 4072.0291, 0xE, 0, };
//D:80039950
struct PitemZ_header PmilcopterZ_header = {0, &prop_flying_related, 0, 0, 0x60004, 5316.9155, 0xF, 0, 0};
//D:80039970
struct PitemZ_header PhindZ_header = {0, &prop_flying_related, 0, 0, 0x60005, 5315.314, 0xB, 0};
//D:80039990
struct PitemZ_header PartictrailerZ_header = {0, &model_object_standard_object, 0, 0, 1, 4014.6265, 0xB, 0, 0};
//D:800399B0
struct PitemZ_header PmotorbikeZ_header = {0, &model_object_standard_object, 0, 0, 1, 1610.8706, 6, 0, 0};
//D:800399D0
struct PitemZ_header PtankZ_header = {0, &item_tank_related, 0, 0, 0x90005, 6290.8398, 0x18, 0};
//D:800399F0
struct PitemZ_header PapcZ_header = {0, &model_object_standard_object, 0, 0, 1, 3611.1035, 0xE, 0};
//D:80039A10
struct PitemZ_header PspeedboatZ_header = {0, &model_object_standard_object, 0, 0, 1, 1799.4586, 0xD, 0, 0};
//D:80039A30
struct PitemZ_header PplaneZ_header = {0, &prop_flying_related, 0, 0, 0x60003, 9285.4492, 0x1C, 0, };
//D:80039A50
struct PitemZ_header Pgun_runway1Z_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80005, 1927.5205, 6, 0, 0};
//D:80039A70
struct PitemZ_header PsafedoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 714.14612, 4, 0, 0};
//D:80039A90
struct PitemZ_header Pkey_holderZ_header = {0, &model_object_standard_object, 0, 0, 1, 223.87097, 7, 0, 0};
//D:80039AB0
struct PitemZ_header PhatchsevxZ_header = {0, &model_object_standard_object, 0, 0, 1, 1224.7664, 2, 0, 0};
//D:80039AD0
struct PitemZ_header PsevdishZ_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80003, 14350.1, 7, 0, 0};
//D:80039AF0
struct PitemZ_header Parchsecdoor1Z_header = {0, &model_object_standard_object, 0, 0, 1, 455.81409, 3, 0, 0};
//D:80039B10
struct PitemZ_header Parchsecdoor2Z_header = {0, &model_object_standard_object, 0, 0, 1, 496.99292, 3, 0, 0};
//D:80039B30
struct PitemZ_header PgroundgunZ_header = {0, &prop_rotating_stuff_related, 0, 0, 0x80005, 2182.6472, 4, 0, 0};
//D:80039B50
struct PitemZ_header PtrainextdoorZ_header = {0, &model_object_standard_object, 0, 0, 1, 587.70111, 5, 0, 0};
//D:80039B70
struct PitemZ_header PcarbmwZ_header = {0, &model_object_standard_object, 0, 0, 1, 553.08728, 0xB, 0, 0};
//D:80039B90
struct PitemZ_header PcarescortZ_header = {0, &model_object_standard_object, 0, 0, 1, 1110.5665, 9, 0, 0};
//D:80039BB0
struct PitemZ_header PcargolfZ_header = {0, &model_object_standard_object, 0, 0, 1, 1121.6409, 0xA, 0, 0};
//D:80039BD0
struct PitemZ_header PcarweirdZ_header = {0, &model_object_standard_object, 0, 0, 1, 984.03931, 0xD, 0, 0};
//D:80039BF0
struct PitemZ_header PcarzilZ_header = {0, &prop_car_related, 0, 0, 0xB0005, 1044.5764, 0xD, 0, 0};
//D:80039C10
struct PitemZ_header Pshuttle_door_lZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 7, 0, 0};
//D:80039C30
struct PitemZ_header Pshuttle_door_rZ_header = {0, &model_object_standard_object, 0, 0, 1, 706.56641, 8, 0, 0};
//D:80039C50
struct PitemZ_header Pdepot_gate_entryZ_header = {0, &model_object_standard_object, 0, 0, 1, 811.28949, 3, 0, 0};
//D:80039C70
struct PitemZ_header Pdepot_door_steelZ_header = {0, &model_object_standard_object, 0, 0, 1, 574.79651, 3, 0, 0};
//D:80039C90
struct PitemZ_header Pglassware2Z_header = {0, &model_object_standard_object, 0, 0, 1, 98.488579, 3, 0, 0};
//D:80039CB0
struct PitemZ_header Pglassware3Z_header = {0, &model_object_standard_object, 0, 0, 1, 137.92715, 1, 0, 0};
//D:80039CD0
struct PitemZ_header Pglassware4Z_header = {0, &model_object_standard_object, 0, 0, 1, 177.48241, 2, 0, 0};
//D:80039CF0
struct PitemZ_header PlandmineZ_header = {0, &model_object_standard_object, 0, 0, 1, 440.03009, 2, 0, 0};
//D:80039D10
struct PitemZ_header Pplant1Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 1, 0, 0};
//D:80039D30
struct PitemZ_header Pplant11Z_header = {0, &model_object_standard_object, 0, 0, 1, 2704.1086, 1, 0, 0};
//D:80039D50
struct PitemZ_header Pplant2Z_header = {0, &model_object_standard_object, 0, 0, 1, 3416.248, 2, 0, 0};
//D:80039D70
struct PitemZ_header Pplant3Z_header = {0, &model_object_standard_object, 0, 0, 1, 2986.0405, 1, 0, 0};
//D:80039D90
struct PitemZ_header Pjungle5_treeZ_header = {0, &model_object_standard_object, 0, 0, 1, 3277.6123, 4, 0, 0};
//D:80039DB0
struct PitemZ_header PlegalpageZ_header = {0, &model_object_standard_object, 0, 0, 1, 2711.7573, 5, 0, 0};
//D:80039DD0
struct PitemZ_header Pst_pete_room_1iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8437.5137, 0x17, 0, 0};
//D:80039DF0
struct PitemZ_header Pst_pete_room_2iZ_header = {0, &model_object_standard_object, 0, 0, 1, 8515.8164, 0x19, 0, 0};
//D:80039E10
struct PitemZ_header Pst_pete_room_3tZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0x1B, 0, 0};
//D:80039E30
struct PitemZ_header Pst_pete_room_5cZ_header = {0, &model_object_standard_object, 0, 0, 1, 4561.9766, 0x19, 0, 0};
//D:80039E50
struct PitemZ_header Pst_pete_room_6cZ_header = {0, &model_object_standard_object, 0, 0, 1, 5006.2896, 0x17, 0, 0};
//D:80039E70
struct PitemZ_header Pdoor_rollertrainZ_header = {0, &model_object_standard_object, 0, 0, 1, 1032.125, 2, 0, 0};
//D:80039E90
struct PitemZ_header Pdoor_winZ_header = {0, &model_object_standard_object, 0, 0, 1, 211.90215, 1, 0, 0};
//D:80039EB0
struct PitemZ_header Pdoor_aztecZ_header = {0, &model_object_standard_object, 0, 0, 1, 632.48639, 1, 0, 0};
//D:80039ED0
struct PitemZ_header PshuttleZ_header = {0, &model_object_standard_object, 0, 0, 1, 4475.1494, 9, 0, 0};
//D:80039EF0
struct PitemZ_header Pdoor_azt_deskZ_header = {0, &model_object_standard_object, 0, 0, 1, 860.41669, 2, 0, 0};
//D:80039F10
struct PitemZ_header Pdoor_azt_desk_topZ_header = {0, &model_object_standard_object, 0, 0, 1, 565.93268, 3, 0, 0};
//D:80039F30
struct PitemZ_header Pdoor_azt_chairZ_header = {0, &model_object_standard_object, 0, 0, 1, 94.510803, 3, 0, 0};
//D:80039F50
struct PitemZ_header Pdoor_mfZ_header = {0, &model_object_standard_object, 0, 0, 1, 559.70367, 7, 0, 0};
//D:80039F70
struct PitemZ_header PflagZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 862.30865, 2, 0};
//D:80039F90
struct PitemZ_header PbarricadeZ_header = {0, &model_object_standard_object, 0, 0, 1, 2047.3016, 2, 0, 0};
//D:80039FB0
struct PitemZ_header PmodemboxZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 338.28839, 4, 0, 0};
//D:80039FD0
struct PitemZ_header PdoorpanelZ_header = {0, &prop_console_four_screen_related, 0, 0, 0x40001, 338.28839, 4, 0, 0};
//D:80039FF0
struct PitemZ_header PdoorconsoleZ_header = {0, &prop_console_one_screen_related, 0, 0, 0x10001, 994.23688, 0xD, 0, 0};
//D:8003A010
struct PitemZ_header PchrtesttubeZ_header = {0, &prop_weapon_related, 0, 0, 0x30001, 136.25925, 2, 0, 0};
//D:8003A030
struct PitemZ_header Pbollardz_header = {0, &model_object_standard_object, 0, 0, 1, 628.78754, 1, 0, 0};

//D:8003A050
struct prop_pos_data word_D_8003A050[2] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003}
};
//D:8003A05C
struct item_related prop_cctv_related = {2, 0, word_D_8003A050, 6, 0};

//D:8003A068
struct prop_pos_data word_D_8003A068[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A06E                     .half 0

//D:8003A070
struct item_related prop_console_one_screen_related = {1, 0, word_D_8003A068, 3, 0};

//D:8003A07C
struct prop_pos_data word_D_8003A07C[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A082                     .half 0

//D:8003A084
struct item_related prop_console_four_screen_related = {1, 0, word_D_8003A07C, 3, 0};

//D:8003A090
struct prop_pos_data word_D_8003A090[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A0AE                     .half 0

//D:8003A0B0
struct item_related prop_tv_holder_related = {5, 0, word_D_8003A090, 0xF, 0};

//D:8003A0BC
struct prop_pos_data word_D_8003A0BC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003A0E0
struct item_related prop_rotating_stuff_related = {6, 0, word_D_8003A0BC, 0x12, 0};

//D:8003A0EC
struct prop_pos_data word_D_8003A0EC[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006}
};
//D:8003A0FE                     .half 0
//D:8003A100
struct item_related prop_eyelid_door_related = {3, 0, word_D_8003A0EC, 9, 0};

//D:8003A10C
struct prop_pos_data word_D_8003A10C[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012},
    {0x0002, 0x0015, 0x0015},
    {0x0002, 0x0018, 0x0018},
    {0x0002, 0x001B, 0x001B},
    {0x0002, 0x001E, 0x001E},
    {0x0002, 0x0021, 0x0021},
    {0x0002, 0x0024, 0x0024}
};
//D:8003A15C
struct item_related prop_iris_door_related = {0xD, 0, word_D_8003A10C, 0x27, 0};

//D:8003A168
struct prop_pos_data word_D_8003A168[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A16E                     .half 0
//D:8003A170
struct item_related prop_walletbond_related = {1, 0, word_D_8003A168, 3, 0};

//D:8003A17C
struct prop_pos_data word_D_8003A17C[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A19C
struct item_related prop_car_related = {5, 0, word_D_8003A17C, 0xF, 0};

//D:8003A1A8
struct prop_pos_data word_D_8003A1A8[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0015, 0x0003, 0x0003},
    {0x0015, 0x0004, 0x0004},
    {0x0015, 0x0005, 0x0005}
};
//D:8003A1C6                     .half 0
//D:8003A1C8
struct item_related prop_flying_related = {5, 0, word_D_8003A1A8, 3, 0};

//D:8003A1D4
struct prop_pos_data word_D_8003A1D4[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003A1DA                     .half 0
//D:8003A1DC
struct item_related prop_door_related = {1, 0, word_D_8003A1D4, 3, 0};

//D:8003A1E8
struct prop_pos_data word_D_8003A1E8[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003A206                     .half 0
//D:8003A208
struct item_related item_tank_related = {5, 0, word_D_8003A1E8, 0xF, 0};

//D:8003A214
struct prop_pos_data word_D_8003A214[] = {
    {0x0015, 0x0000, 0x0000},
};
//D:8003A21A                     .half 0
//D:8003A21C
struct item_related item_hat_related = {1, 0, word_D_8003A214, 0, 0};
const u8 spacer_string[] = "\00\00\00\00\00\00\00\00";
//D:8003A228                     .globl PitemZ_entries
struct p_itementry PitemZ_entries[] = {
    {&Palarm1z_header, "Palarm1Z", 0.1},
    {&Palarm2Z_header, "Palarm2Z", 0.1},
    {&PexplosionbitZ_header, "PexplosionbitZ", 0.1},
    {&Pammo_crate1Z_header, "Pammo_crate1Z", 0.1},
    {&Pammo_crate2Z_header, "Pammo_crate2Z", 0.1},
    {&Pammo_crate3Z_header, "Pammo_crate3Z", 0.1},
    {&Pammo_crate4Z_header, "Pammo_crate4Z", 0.1},
    {&Pammo_crate5Z_header, "Pammo_crate5Z", 0.1},
    {&Pbin1Z_header, "Pbin1Z", 0.1},
    {&Pblotter1Z_header, "Pblotter1Z", 0.1},
    {&Pbook1Z_header, "Pbook1Z", 0.1},
    {&Pbookshelf1Z_header, "Pbookshelf1Z", 0.1},
    {&Pbridge_console1aZ_header, "Pbridge_console1aZ", 0.1},
    {&Pbridge_console1bZ_header, "Pbridge_console1bZ", 0.1},
    {&Pbridge_console2aZ_header, "Pbridge_console2aZ", 0.1},
    {&Pbridge_console2bZ_header, "Pbridge_console2bZ", 0.1},
    {&Pbridge_console3aZ_header, "Pbridge_console3aZ", 0.1},
    {&Pbridge_console3bZ_header, "Pbridge_console3bZ", 0.1},
    {&Pcard_box1Z_header, "Pcard_box1Z", 0.1},
    {&Pcard_box2Z_header, "Pcard_box2Z", 0.1},
    {&Pcard_box3Z_header, "Pcard_box3Z", 0.1},
    {&Pcard_box4_lgZ_header, "Pcard_box4_lgZ", 0.1},
    {&Pcard_box5_lgZ_header, "Pcard_box5_lgZ", 0.1},
    {&Pcard_box6_lgZ_header, "Pcard_box6_lgZ", 0.1},
    {&PcctvZ_header, "PcctvZ", 0.1},
    {&Pconsole1Z_header, "Pconsole1Z", 0.1},
    {&Pconsole2Z_header, "Pconsole2Z", 0.1},
    {&Pconsole3Z_header, "Pconsole3Z", 0.1},
    {&Pconsole_sevaZ_header, "Pconsole_sevaZ", 0.1},
    {&Pconsole_sevbZ_header, "Pconsole_sevbZ", 0.1},
    {&Pconsole_sevcZ_header, "Pconsole_sevcZ", 0.1},
    {&Pconsole_sevdZ_header, "Pconsole_sevdZ", 0.1},
    {&Pconsole_sev2aZ_header, "Pconsole_sev2aZ", 0.1},
    {&Pconsole_sev2bZ_header, "Pconsole_sev2bZ", 0.1},
    {&Pconsole_sev2cZ_header, "Pconsole_sev2cZ", 0.1},
    {&Pconsole_sev2dZ_header, "Pconsole_sev2dZ", 0.1},
    {&Pconsole_sev_GEaZ_header, "Pconsole_sev_GEaZ", 0.1},
    {&Pconsole_sev_GEbZ_header, "Pconsole_sev_GEbZ", 0.1},
    {&Pdesk1Z_header, "Pdesk1Z", 0.1},
    {&Pdesk2Z_header, "Pdesk2Z", 0.1},
    {&Pdesk_lamp2Z_header, "Pdesk_lamp2Z", 0.1},
    {&Pdisc_readerZ_header, "Pdisc_readerZ", 0.1},
    {&Pdisk_drive1Z_header, "Pdisk_drive1Z", 0.1},
    {&Pfiling_cabinet1Z_header, "Pfiling_cabinet1Z", 0.1},
    {&Pjerry_can1Z_header, "Pjerry_can1Z", 0.1},
    {&Pkeyboard1Z_header, "Pkeyboard1Z", 0.1},
    {&Pkit_units1Z_header, "Pkit_units1Z", 0.1},
    {&Pletter_tray1Z_header, "Pletter_tray1Z", 0.1},
    {&Pmainframe1Z_header, "Pmainframe1Z", 0.1},
    {&Pmainframe2Z_header, "Pmainframe2Z", 0.1},
    {&Pmetal_chair1Z_header, "Pmetal_chair1Z", 0.1},
    {&Pmetal_crate1Z_header, "Pmetal_crate1Z", 0.1},
    {&Pmetal_crate2Z_header, "Pmetal_crate2Z", 0.1},
    {&Pmetal_crate3Z_header, "Pmetal_crate3Z", 0.1},
    {&Pmetal_crate4Z_header, "Pmetal_crate4Z", 0.1},
    {&Pmissile_rackZ_header, "Pmissile_rackZ", 0.1},
    {&Pmissile_rack2Z_header, "Pmissile_rack2Z", 0.1},
    {&Poil_drum1Z_header, "Poil_drum1Z", 0.1},
    {&Poil_drum2Z_header, "Poil_drum2Z", 0.1},
    {&Poil_drum3Z_header, "Poil_drum3Z", 0.1},
    {&Poil_drum5Z_header, "Poil_drum5Z", 0.1},
    {&Poil_drum6Z_header, "Poil_drum6Z", 0.1},
    {&Poil_drum7Z_header, "Poil_drum7Z", 0.1},
    {&PpadlockZ_header, "PpadlockZ", 0.1},
    {&Pphone1Z_header, "Pphone1Z", 0.1},
    {&Pradio_unit1Z_header, "Pradio_unit1Z", 0.1},
    {&Pradio_unit2Z_header, "Pradio_unit2Z", 0.1},
    {&Pradio_unit3Z_header, "Pradio_unit3Z", 0.1},
    {&Pradio_unit4Z_header, "Pradio_unit4Z", 0.1},
    {&Psat1_reflectZ_header, "Psat1_reflectZ", 0.1},
    {&PsatdishZ_header, "PsatdishZ", 0.1},
    {&PsatboxZ_header, "PsatboxZ", 0.1},
    {&Pstool1Z_header, "Pstool1Z", 0.1},
    {&Pswivel_chair1Z_header, "Pswivel_chair1Z", 0.1},
    {&Ptorpedo_rackZ_header, "Ptorpedo_rackZ", 0.1},
    {&Ptv1Z_header, "Ptv1Z", 0.1},
    {&Ptv_holderZ_header, "Ptv_holderZ", 0.1},
    {&PtvscreenZ_header, "PtvscreenZ", 0.1},
    {&Ptv4screenZ_header, "Ptv4screenZ", 0.1},
    {&Pwood_lg_crate1Z_header, "Pwood_lg_crate1Z", 0.1},
    {&Pwood_lg_crate2Z_header, "Pwood_lg_crate2Z", 0.1},
    {&Pwood_md_crate3Z_header, "Pwood_md_crate3Z", 0.1},
    {&Pwood_sm_crate4Z_header, "Pwood_sm_crate4Z", 0.1},
    {&Pwood_sm_crate5Z_header, "Pwood_sm_crate5Z", 0.1},
    {&Pwood_sm_crate6Z_header, "Pwood_sm_crate6Z", 0.1},
    {&Pwooden_table1Z_header, "Pwooden_table1Z", 0.1},
    {&Pswipe_card2Z_header, "Pswipe_card2Z", 0.1},
    {&Pborg_crateZ_header, "Pborg_crateZ", 0.1},
    {&Pboxes4x4Z_header, "Pboxes4x4Z", 0.1},
    {&Pboxes3x4Z_header, "Pboxes3x4Z", 0.1},
    {&Pboxes2x4Z_header, "Pboxes2x4Z", 0.1},
    {&Psec_panelZ_header, "Psec_panelZ", 0.1},
    {&PICBM_noseZ_header, "PICBM_noseZ", 0.1},
    {&PICBMZ_header, "PICBMZ", 0.1},
    {&Ptuning_console1Z_header, "Ptuning_console1Z", 0.1},
    {&Pdesk_arecibo1Z_header, "Pdesk_arecibo1Z", 0.1},
    {&Plocker3Z_header, "Plocker3Z", 0.1},
    {&Plocker4Z_header, "Plocker4Z", 0.1},
    {&ProofgunZ_header, "ProofgunZ", 0.1},
    {&Pdest_engineZ_header, "Pdest_engineZ", 0.1},
    {&Pdest_exocetZ_header, "Pdest_exocetZ", 0.1},
    {&Pdest_gunZ_header, "Pdest_gunZ", 0.1},
    {&Pdest_harpoonZ_header, "Pdest_harpoonZ", 0.1},
    {&Pdest_seawolfZ_header, "Pdest_seawolfZ", 0.1},
    {&PwindowZ_header, "PwindowZ", 0.1},
    {&Pwindow_lib_lg1Z_header, "Pwindow_lib_lg1Z", 0.1},
    {&Pwindow_lib_sm1Z_header, "Pwindow_lib_sm1Z", 0.1},
    {&Pwindow_cor11Z_header, "Pwindow_cor11Z", 0.1},
    {&Pjungle3_treeZ_header, "Pjungle3_treeZ", 0.1},
    {&PpalmZ_header, "PpalmZ", 0.1},
    {&PpalmtreeZ_header, "PpalmtreeZ", 0.1},
    {&Pplant2bZ_header, "Pplant2bZ", 0.1},
    {&PlabbenchZ_header, "PlabbenchZ", 0.1},
    {&PgasbarrelZ_header, "PgasbarrelZ", 0.1},
    {&PgasbarrelsZ_header, "PgasbarrelsZ", 0.1},
    {&PbodyarmourZ_header, "PbodyarmourZ", 0.1},
    {&PbodyarmourvestZ_header, "PbodyarmourvestZ", 0.1},
    {&PgastankZ_header, "PgastankZ", 0.1},
    {&Pglassware1Z_header, "Pglassware1Z", 0.1},
    {&PhatchboltZ_header, "PhatchboltZ", 0.1},
    {&PbrakeunitZ_header, "PbrakeunitZ", 0.1},
    {&Pak47magZ_header, "Pak47magZ", 0.1},
    {&Pm16magZ_header, "Pm16magZ", 0.1},
    {&Pmp5kmagZ_header, "Pmp5kmagZ", 0.1},
    {&PskorpionmagZ_header, "PskorpionmagZ", 0.1},
    {&PspectremagZ_header, "PspectremagZ", 0.1},
    {&PuzimagZ_header, "PuzimagZ", 0.1},
    {&PsilencerZ_header, "PsilencerZ", 0.1},
    {&PchrextinguisherZ_header, "PchrextinguisherZ", 0.1},
    {&PboxcartridgesZ_header, "PboxcartridgesZ", 0.1},
    {&Pfnp90magZ_header, "Pfnp90magZ", 0.1},
    {&PgoldenshellsZ_header, "PgoldenshellsZ", 0.1},
    {&PmagnumshellsZ_header, "PmagnumshellsZ", 0.1},
    {&PwppkmagZ_header, "PwppkmagZ", 0.1},
    {&Ptt33magZ_header, "Ptt33magZ", 0.1},
    {&Psev_doorZ_header, "Psev_doorZ", 1.0},
    {&Psev_door3Z_header, "Psev_door3Z", 1.0},
    {&Psev_door3_windZ_header, "Psev_door3_windZ", 1.0},
    {&Psev_door4_windZ_header, "Psev_door4_windZ", 1.0},
    {&Psev_trislideZ_header, "Psev_trislideZ", 1.0},
    {&Psev_door_v1Z_header, "Psev_door_v1Z", 1.0},
    {&Psteel_door1Z_header, "Psteel_door1Z", 1.0},
    {&Psteel_door2Z_header, "Psteel_door2Z", 1.0},
    {&Psteel_door3Z_header, "Psteel_door3Z", 1.0},
    {&Psilo_lift_doorZ_header, "Psilo_lift_doorZ", 1.0},
    {&Psteel_door2bZ_header, "Psteel_door2bZ", 1.0},
    {&Pdoor_roller1Z_header, "Pdoor_roller1Z", 1.0},
    {&Pdoor_roller2Z_header, "Pdoor_roller2Z", 1.0},
    {&Pdoor_roller3Z_header, "Pdoor_roller3Z", 1.0},
    {&Pdoor_roller4Z_header, "Pdoor_roller4Z", 1.0},
    {&Pdoor_st_arec1Z_header, "Pdoor_st_arec1Z", 1.0},
    {&Pdoor_st_arec2Z_header, "Pdoor_st_arec2Z", 1.0},
    {&Pdoor_dest1Z_header, "Pdoor_dest1Z", 1.0},
    {&Pdoor_dest2Z_header, "Pdoor_dest2Z", 1.0},
    {&Pgas_plant_sw_do1Z_header, "Pgas_plant_sw_do1Z", 1.0},
    {&Pgas_plant_sw2_do1Z_header, "Pgas_plant_sw2_do1Z", 1.0},
    {&Pgas_plant_sw3_do1Z_header, "Pgas_plant_sw3_do1Z", 1.0},
    {&Pgas_plant_sw4_do1Z_header, "Pgas_plant_sw4_do1Z", 1.0},
    {&Pgas_plant_met1_do1Z_header, "Pgas_plant_met1_do1Z", 1.0},
    {&Pgas_plant_wc_cub1Z_header, "Pgas_plant_wc_cub1Z", 1.0},
    {&Pgasplant_clear_doorZ_header, "Pgasplant_clear_doorZ", 1.0},
    {&Ptrain_doorZ_header, "Ptrain_doorZ", 1.0},
    {&Ptrain_door2Z_header, "Ptrain_door2Z", 1.0},
    {&Ptrain_door3Z_header, "Ptrain_door3Z", 1.0},
    {&Pdoor_eyelidZ_header, "Pdoor_eyelidZ", 1.0},
    {&Pdoor_irisZ_header, "Pdoor_irisZ", 1.0},
    {&PsevdoorwoodZ_header, "PsevdoorwoodZ", 1.0},
    {&PsevdoorwindZ_header, "PsevdoorwindZ", 1.0},
    {&PsevdoornowindZ_header, "PsevdoornowindZ", 1.0},
    {&PsevdoormetslideZ_header, "PsevdoormetslideZ", 1.0},
    {&Pcryptdoor1aZ_header, "Pcryptdoor1aZ", 1.0},
    {&Pcryptdoor1bZ_header, "Pcryptdoor1bZ", 1.0},
    {&Pcryptdoor2aZ_header, "Pcryptdoor2aZ", 1.0},
    {&Pcryptdoor2bZ_header, "Pcryptdoor2bZ", 1.0},
    {&Pcryptdoor3Z_header, "Pcryptdoor3Z", 1.0},
    {&Pcryptdoor4Z_header, "Pcryptdoor4Z", 1.0},
    {&PvertdoorZ_header, "PvertdoorZ", 1.0},
    {&PhatchdoorZ_header, "PhatchdoorZ", 1.0},
    {&PdamgatedoorZ_header, "PdamgatedoorZ", 1.0},
    {&PdamtundoorZ_header, "PdamtundoorZ", 1.0},
    {&PdamchaindoorZ_header, "PdamchaindoorZ", 1.0},
    {&PsilotopdoorZ_header, "PsilotopdoorZ", 1.0},
    {&Pdoorprison1Z_header, "Pdoorprison1Z", 1.0},
    {&PdoorstatgateZ_header, "PdoorstatgateZ", 1.0},
    {&PchrkalashZ_header, "PchrkalashZ", 0.1},
    {&PchrgrenadelaunchZ_header, "PchrgrenadelaunchZ", 0.1},
    {&PchrknifeZ_header, "PchrknifeZ", 0.1},
    {&PchrlaserZ_header, "PchrlaserZ", 0.1},
    {&Pchrm16Z_header, "Pchrm16Z", 0.1},
    {&Pchrmp5kZ_header, "Pchrmp5kZ", 0.1},
    {&PchrrugerZ_header, "PchrrugerZ", 0.1},
    {&PchrwppkZ_header, "PchrwppkZ", 0.1},
    {&PchrshotgunZ_header, "PchrshotgunZ", 0.1},
    {&PchrskorpionZ_header, "PchrskorpionZ", 0.1},
    {&PchrspectreZ_header, "PchrspectreZ", 0.1},
    {&PchruziZ_header, "PchruziZ", 0.1},
    {&PchrgrenadeZ_header, "PchrgrenadeZ", 0.1},
    {&Pchrfnp90Z_header, "Pchrfnp90Z", 0.1},
    {&PchrbriefcaseZ_header, "PchrbriefcaseZ", 0.1},
    {&PchrremotemineZ_header, "PchrremotemineZ", 0.1},
    {&PchrproximitymineZ_header, "PchrproximitymineZ", 0.1},
    {&PchrtimedmineZ_header, "PchrtimedmineZ", 0.1},
    {&PchrrocketZ_header, "PchrrocketZ", 0.1},
    {&PchrgrenaderoundZ_header, "PchrgrenaderoundZ", 0.1},
    {&PchrwppksilZ_header, "PchrwppksilZ", 0.1},
    {&Pchrtt33Z_header, "Pchrtt33Z", 0.1},
    {&Pchrmp5ksilZ_header, "Pchrmp5ksilZ", 0.1},
    {&PchrautoshotZ_header, "PchrautoshotZ", 0.1},
    {&PchrgoldenZ_header, "PchrgoldenZ", 0.1},
    {&PchrthrowknifeZ_header, "PchrthrowknifeZ", 0.1},
    {&PchrsniperrifleZ_header, "PchrsniperrifleZ", 0.1},
    {&PchrrocketlaunchZ_header, "PchrrocketlaunchZ", 0.1},
    {&PhatfurryZ_header, "PhatfurryZ", 0.1},
    {&PhatfurrybrownZ_header, "PhatfurrybrownZ", 0.1},
    {&PhatfurryblackZ_header, "PhatfurryblackZ", 0.1},
    {&PhattbirdZ_header, "PhattbirdZ", 0.1},
    {&PhattbirdbrownZ_header, "PhattbirdbrownZ", 0.1},
    {&PhathelmetZ_header, "PhathelmetZ", 0.1},
    {&PhathelmetgreyZ_header, "PhathelmetgreyZ", 0.1},
    {&PhatmoonZ_header, "PhatmoonZ", 0.1},
    {&PhatberetZ_header, "PhatberetZ", 0.1},
    {&PhatberetblueZ_header, "PhatberetblueZ", 0.1},
    {&PhatberetredZ_header, "PhatberetredZ", 0.1},
    {&PhatpeakedZ_header, "PhatpeakedZ", 0.1},
    {&PchrwristdartZ_header, "PchrwristdartZ", 0.1},
    {&PchrexplosivepenZ_header, "PchrexplosivepenZ", 0.1},
    {&PchrbombcaseZ_header, "PchrbombcaseZ", 0.1},
    {&PchrflarepistolZ_header, "PchrflarepistolZ", 0.1},
    {&PchrpitongunZ_header, "PchrpitongunZ", 0.1},
    {&PchrfingergunZ_header, "PchrfingergunZ", 0.1},
    {&PchrsilverwppkZ_header, "PchrsilverwppkZ", 0.1},
    {&PchrgoldwppkZ_header, "PchrgoldwppkZ", 0.1},
    {&PchrdynamiteZ_header, "PchrdynamiteZ", 0.1},
    {&PchrbungeeZ_header, "PchrbungeeZ", 0.1},
    {&PchrdoordecoderZ_header, "PchrdoordecoderZ", 0.1},
    {&PchrbombdefuserZ_header, "PchrbombdefuserZ", 0.1},
    {&PchrbugdetectorZ_header, "PchrbugdetectorZ", 0.1},
    {&PchrsafecrackercaseZ_header, "PchrsafecrackercaseZ", 0.1},
    {&PchrcameraZ_header, "PchrcameraZ", 0.1},
    {&PchrlockexploderZ_header, "PchrlockexploderZ", 0.1},
    {&PchrdoorexploderZ_header, "PchrdoorexploderZ", 0.1},
    {&PchrkeyanalysercaseZ_header, "PchrkeyanalysercaseZ", 0.1},
    {&PchrweaponcaseZ_header, "PchrweaponcaseZ", 0.1},
    {&PchrkeyyaleZ_header, "PchrkeyyaleZ", 0.1},
    {&PchrkeyboltZ_header, "PchrkeyboltZ", 0.1},
    {&PchrbugZ_header, "PchrbugZ", 0.1},
    {&PchrmicrocameraZ_header, "PchrmicrocameraZ", 0.1},
    {&PfloppyZ_header, "PfloppyZ", 0.1},
    {&PchrgoldeneyekeyZ_header, "PchrgoldeneyekeyZ", 0.1},
    {&PchrpolarizedglassesZ_header, "PchrpolarizedglassesZ", 0.1},
    {&PchrcreditcardZ_header, "PchrcreditcardZ", 0.1},
    {&PchrdarkglassesZ_header, "PchrdarkglassesZ", 0.1},
    {&PchrgaskeyringZ_header, "PchrgaskeyringZ", 0.1},
    {&PchrdatathiefZ_header, "PchrdatathiefZ", 0.1},
    {&PsafeZ_header, "PsafeZ", 0.1},
    {&PbombZ_header, "PbombZ", 0.1},
    {&PchrplansZ_header, "PchrplansZ", 0.1},
    {&PchrspyfileZ_header, "PchrspyfileZ", 0.1},
    {&PchrblueprintsZ_header, "PchrblueprintsZ", 0.1},
    {&PchrcircuitboardZ_header, "PchrcircuitboardZ", 0.1},
    {&PchrmapZ_header, "PchrmapZ", 0.1},
    {&PchrspooltapeZ_header, "PchrspooltapeZ", 0.1},
    {&PchraudiotapeZ_header, "PchraudiotapeZ", 0.1},
    {&PchrmicrofilmZ_header, "PchrmicrofilmZ", 0.1},
    {&PchrmicrocodeZ_header, "PchrmicrocodeZ", 0.1},
    {&PchrlectreZ_header, "PchrlectreZ", 0.1},
    {&PchrmoneyZ_header, "PchrmoneyZ", 0.1},
    {&PchrgoldbarZ_header, "PchrgoldbarZ", 0.1},
    {&PchrheroinZ_header, "PchrheroinZ", 0.1},
    {&PchrclipboardZ_header, "PchrclipboardZ", 0.1},
    {&PchrdossierredZ_header, "PchrdossierredZ", 0.1},
    {&PchrstafflistZ_header, "PchrstafflistZ", 0.1},
    {&PchrdattapeZ_header, "PchrdattapeZ", 0.1},
    {&PchrplastiqueZ_header, "PchrplastiqueZ", 0.1},
    {&PchrblackboxZ_header, "PchrblackboxZ", 0.1},
    {&PchrvideotapeZ_header, "PchrvideotapeZ", 0.1},
    {&PnintendologoZ_header, "PnintendologoZ", 0.1},
    {&PgoldeneyelogoZ_header, "PgoldeneyelogoZ", 0.1},
    {&PwalletbondZ_header, "PwalletbondZ", 0.1},
    {&PmiltruckZ_header, "PmiltruckZ", 0.1},
    {&PjeepZ_header, "PjeepZ", 0.1},
    {&ParticZ_header, "ParticZ", 0.1},
    {&PhelicopterZ_header, "PhelicopterZ", 0.1},
    {&PtigerZ_header, "PtigerZ", 0.1},
    {&PmilcopterZ_header, "PmilcopterZ", 0.1},
    {&PhindZ_header, "PhindZ", 0.1},
    {&PartictrailerZ_header, "PartictrailerZ", 0.1},
    {&PmotorbikeZ_header, "PmotorbikeZ", 0.1},
    {&PtankZ_header, "PtankZ", 0.1},
    {&PapcZ_header, "PapcZ", 0.1},
    {&PspeedboatZ_header, "PspeedboatZ", 0.1},
    {&PplaneZ_header, "PplaneZ", 0.1},
    {&Pgun_runway1Z_header, "Pgun_runway1Z", 0.1},
    {&PsafedoorZ_header, "PsafedoorZ", 1.0},
    {&Pkey_holderZ_header, "Pkey_holderZ", 1.0},
    {&PhatchsevxZ_header, "PhatchsevxZ", 1.0},
    {&PsevdishZ_header, "PsevdishZ", 1.0},
    {&Parchsecdoor1Z_header, "Parchsecdoor1Z", 1.0},
    {&Parchsecdoor2Z_header, "Parchsecdoor2Z", 1.0},
    {&PgroundgunZ_header, "PgroundgunZ", 0.1},
    {&PtrainextdoorZ_header, "PtrainextdoorZ", 1.0},
    {&PcarbmwZ_header, "PcarbmwZ", 0.1},
    {&PcarescortZ_header, "PcarescortZ", 0.1},
    {&PcargolfZ_header, "PcargolfZ", 0.1},
    {&PcarweirdZ_header, "PcarweirdZ", 0.1},
    {&PcarzilZ_header, "PcarzilZ", 0.1},
    {&Pshuttle_door_lZ_header, "Pshuttle_door_lZ", 1.0},
    {&Pshuttle_door_rZ_header, "Pshuttle_door_rZ", 1.0},
    {&Pdepot_gate_entryZ_header, "Pdepot_gate_entryZ", 0.1},
    {&Pdepot_door_steelZ_header, "Pdepot_door_steelZ", 0.1},
    {&Pglassware2Z_header, "Pglassware2Z", 0.1},
    {&Pglassware3Z_header, "Pglassware3Z", 0.1},
    {&Pglassware4Z_header, "Pglassware4Z", 0.1},
    {&PlandmineZ_header, "PlandmineZ", 0.1},
    {&Pplant1Z_header, "Pplant1Z", 0.1},
    {&Pplant11Z_header, "Pplant11Z", 0.1},
    {&Pplant2Z_header, "Pplant2Z", 0.1},
    {&Pplant3Z_header, "Pplant3Z", 0.1},
    {&Pjungle5_treeZ_header, "Pjungle5_treeZ", 0.1},
    {&PlegalpageZ_header, "PlegalpageZ", 0.1},
    {&Pst_pete_room_1iZ_header, "Pst_pete_room_1iZ", 0.1},
    {&Pst_pete_room_2iZ_header, "Pst_pete_room_2iZ", 0.1},
    {&Pst_pete_room_3tZ_header, "Pst_pete_room_3tZ", 0.1},
    {&Pst_pete_room_5cZ_header, "Pst_pete_room_5cZ", 0.1},
    {&Pst_pete_room_6cZ_header, "Pst_pete_room_6cZ", 0.1},
    {&Pdoor_rollertrainZ_header, "Pdoor_rollertrainZ", 1.0},
    {&Pdoor_winZ_header, "Pdoor_winZ", 1.0},
    {&Pdoor_aztecZ_header, "Pdoor_aztecZ", 1.0},
    {&PshuttleZ_header, "PshuttleZ", 0.1},
    {&Pdoor_azt_deskZ_header, "Pdoor_azt_deskZ", 1.0},
    {&Pdoor_azt_desk_topZ_header, "Pdoor_azt_desk_topZ", 1.0},
    {&Pdoor_azt_chairZ_header, "Pdoor_azt_chairZ", 1.0},
    {&Pdoor_mfZ_header, "Pdoor_mfZ", 1.0},
    {&PflagZ_header, "PflagZ", 0.1},
    {&PbarricadeZ_header, "PbarricadeZ", 0.1},
    {&PmodemboxZ_header, "PmodemboxZ", 0.1},
    {&PdoorpanelZ_header, "PdoorpanelZ", 0.1},
    {&PdoorconsoleZ_header, "PdoorconsoleZ", 0.1},
    {&PchrtesttubeZ_header, "PchrtesttubeZ", 0.1},
    {&Pbollardz_header, "PbollardZ", 0.1},
    {0, "", 1.0}
};

//D:8003b224
u32 object_explosion_details[] = {
    0x0006315c, 0x7b6cdbff, 0x5126fb59, 0x7ca70006,
    0x2afecb3e, 0x73f4278f, 0x6d3a44c8, 0x00050000,
    0x00000000, 0x00000000, 0x0000000b, 0xb9b03eba,
    0xad6275c8, 0xb70ff06e, 0x000b17d9, 0xdfcc57cd,
    0x82547345, 0xe011000b, 0x3779ed72, 0x688df67b,
    0x37e54f89, 0x000be277, 0x0474dd1e, 0x0c48486c,
    0xf87d000b, 0x7c3f16bc, 0x44a91a58, 0xe4129297,
    0x00003dc2, 0x16b6e30d, 0xbcabc592, 0xf9b50002,
    0x719c7024, 0x9ee0c175, 0xa5ddc933, 0x00028e16,
    0xbbca05c0, 0x1a7381be, 0xf8210000, 0x00000000,
    0x00000000, 0x00000000, 0x00082716, 0xf5440d35,
    0xc20e83d7, 0x7d730008, 0x81a1b772, 0x1b57437a,
    0x85fab6c1, 0x000827eb, 0x5a7abd1a, 0x27eb5a7a,
    0xbd1a0008, 0x98de8c36, 0xddd5f74b, 0x4f0a1f14,
    0x000834f5, 0xf199a9f2, 0x3d27c707, 0xb9ad0008,
    0x678fdb91, 0x2a2e8d91, 0x6eee925e, 0x0004d82f,
    0xf4d7546f, 0xd6c787d9, 0x01430004, 0x100eadf2,
    0x1fdd45f1, 0x4772f8c6, 0x0004ef0b, 0x71bbb7f7,
    0xbfa303b8, 0xe44e0004, 0xdfd1676a, 0x8597e8ac,
    0xe2109a4d, 0x0004ab48, 0xdd9b4343, 0x04b80dcc,
    0x3b3d0004, 0x836b6bbf, 0x9dbb3db7, 0x59577341,
    0x00070000, 0x00000000, 0x00000000, 0x00000009,
    0xb1cc19e2, 0x0ea5b1cc, 0x19e20ea5, 0x0009f093,
    0xb2df1409, 0x271ee0b3, 0x418a0009, 0x3ac20102,
    0xbf013ac2, 0x0102bf01, 0x00093ac6, 0xe449a56e,
    0xa4cfeda0, 0x17190009, 0x9bcfc333, 0x63844298,
    0xd4557bfa, 0x0009839e, 0x0ba71466, 0xdb6dd1b3,
    0x12330009, 0x3f677a70, 0x83de7052, 0x07d236ff,
    0x0009a409, 0x692de286, 0xc63c82d0, 0x5d070009,
    0xd6ca1866, 0x839cbc6a, 0x86ad4dc6, 0x000996fc,
    0xa1efa9e6, 0xb9d2a3c5, 0xa0450009, 0x7d2be7dc,
    0x55db378e, 0x4765b09c, 0x0009e2af, 0x2d4371fe,
    0xe39093b3, 0x57e30009, 0x9367098a, 0x3b68d6f8,
    0x4eaf7b83, 0x000f0000, 0x00000000, 0x00000000,
    0x0000000f, 0x00000000, 0x00000000, 0x00000000,
    0x0007993d, 0xa2b25028, 0x825e25b8, 0xd8ef0006,
    0x6553024d, 0xfd22d469, 0x18e432f6, 0x0006f742,
    0x0cb58ed2, 0x60216ad5, 0xaa880004, 0x06d882ef,
    0x5b194147, 0x5ae1374e, 0x0004284d, 0x3e7c9330,
    0xcf1e013f, 0x4e290006, 0xe339c0b6, 0xe5fc7054,
    0x83a8c118, 0x0004b49f, 0x00024ef6, 0x88490002,
    0x070b0002, 0x2d56a1ee, 0x41058ae6, 0x6a2a60dd,
    0x000979b2, 0xbc78b9b9, 0xc76a97a1, 0x3da30009,
    0x3292ddc3, 0x926512a6, 0xe935b9bc, 0x000304db,
    0x3cfddb5c, 0x3b2950b7, 0x83d10004, 0xbe6408ad,
    0x150d6aed, 0x542e63b3, 0x0004d7e5, 0x13695acc,
    0x535a2105, 0x1bf70004, 0x72223cee, 0x1a15122a,
    0xadec5ef3, 0x0004927f, 0x10b05125, 0x7f4ebbc5,
    0x8088000b, 0xe89d7502, 0x9003469d, 0x19f0a5e6,
    0x000b3771, 0xc00280ff, 0xdbf61705, 0x497a000e,
    0xa954afde, 0xbb6cd4a6, 0x9883fa27, 0x000ede9f,
    0xcef06346, 0x80fba382, 0x14d1000e, 0x448ed4cc,
    0xc1b5442f, 0xc1d1ee05, 0x000ec7c0, 0xf918095e,
    0xece206d4, 0xc64d000e, 0xc49116ec, 0xdea75a19,
    0x9de7ff28, 0x000ee889, 0x2da62775, 0x153cbae6,
    0xcb1b0000, 0x2d56a1ee, 0x41058ae6, 0x6a2a60dd,
    0x0006e5e6, 0x8fb7d5fe, 0xe959d656, 0xfb820007,
    0x58763a4f, 0xd115a10d, 0x265d2c02, 0x0007787e,
    0xc128d96a, 0x60c918e7, 0x99ad0007, 0x879a90e4,
    0xc20f35fe, 0xc80791d8, 0x000740ae, 0x62b6d240,
    0xac8d47c5, 0x17d10000, 0x00000000, 0x00000000,
    0x00000000, 0x000715c6, 0xb37d118a, 0x4e615d02,
    0x7d500006, 0x15c6b37d, 0x118a4e61, 0x5d027d50,
    0x00030000, 0x00000000, 0x00000000, 0x00000003,
    0x24698ae5, 0x524fe5f6, 0xbe4ac865, 0x00052957,
    0x1b2227c7, 0x96630ddf, 0x411f0007, 0x15c6b37d,
    0x118a4e61, 0x5d027d50, 0x00040000, 0x00000000,
    0x00000000, 0x00000006, 0xf8f4f1e0, 0x473f41dd,
    0xa510c9c6, 0x00080000, 0x00000000, 0x00000000,
    0x00000004, 0x7a512382, 0x9b3629e5, 0x5921017a,
    0x00048666, 0x3dd9e619, 0x6134cc94, 0x1a5c0004,
    0x7f3931c5, 0x9ac370ab, 0x0551b069, 0x0003d727,
    0x7ab2786b, 0xf5ad3fc4, 0xd6ce0003, 0x4548d59e,
    0x1edce88d, 0xe9e4af76, 0x0003262f, 0x491bfd57,
    0x6715e7ed, 0x2626000f, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000004, 0xbcae0bd1, 0x0ff73a30, 0x724083b7,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000006, 0xb2c6170a,
    0x0a236bbe, 0xb59382db, 0x0005275b, 0x8ad3002c,
    0x27b58ad3, 0x002c0005, 0x00000000, 0x00000000,
    0x00000000, 0x000833a1, 0x8a014d42, 0xd9cbb865,
    0xb3360004, 0x8c0678fc, 0x8f9a4df5, 0x4d5322f9,
    0x000399e9, 0x0107ef5e, 0x0560e6df, 0x4b360003,
    0x31e70023, 0xb2aea2d7, 0xe54090b2, 0x00080000,
    0x00000000, 0x00000000, 0x0000000d, 0x00000000,
    0x00000000, 0x00000000, 0x000833a1, 0x8a014d42,
    0xd9cbb865, 0xb3360008, 0x33a18a01, 0x4d42d9cb,
    0xb865b336, 0x000833a1, 0x8a014d42, 0xd9cbb865,
    0xb3360008, 0x33a18a01, 0x4d42d9cb, 0xb865b336,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000002, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00060000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000c0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x000d0000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00030000, 0x00000000, 0x00000000,
    0x0000000d, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x000d0000,
    0x00000000, 0x00000000, 0x0000000d, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000006, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000006, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000000,
    0x00040000, 0x00000000, 0x00000000, 0x00000004,
    0x00000000, 0x00000000, 0x00000000, 0x00040000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000,
    0x00000000, 0x00000000, 0x000d0000, 0x00000000,
    0x00000000, 0x00000004, 0x00000000, 0x00000000,
    0x00000000, 0x00040000, 0x00000000, 0x00000000,
    0x00000004, 0x00000000, 0x00000000, 0x00000000,
    0x00040000, 0x00000000, 0x00000000, 0x00000004,
    0x00000000, 0x00000000, 0x00000000, 0x00040000,
    0x00000000, 0x00000000, 0x00000004, 0x00000000,
    0x00000000, 0x00000000, 0x00040000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000007, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x0000000d, 0x00000000, 0x00000000,
    0x00000000, 0x000d0000, 0x00000000, 0x00000000,
    0x0000000d, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x0000000d,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x000d0000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000006, 0x00000000, 0x00000000, 0x00000000,
    0x00060000, 0x00000000, 0x00000000, 0x00000009,
    0x00000000, 0x00000000, 0x00000000, 0x000d0000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x0000ffff, 0xffffffff,
    0xffffffff, 0xffff0000, 0x00000000
};


//D:8003C4D0
struct prop_pos_data word_D_8003C4D0[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C4D6                     .half 0
//D:8003C4D8
struct item_related model_object_standard_object = {1, 0, word_D_8003C4D0, 3, 0};
//D:8003C4E4
s32 D_8003C4E4 = 0;
//D:8003C4E8
s32 D_8003C4E8 = 0;
//D:8003C4EC
s32 D_8003C4EC = 0;

//D:8003C4F0
struct prop_pos_data word_D_8003C4F0[] = {
    {0x0015, 0x0000, 0x0000},
    {0x0015, 0x0001, 0x0001}
};
//D:8003C4FC
struct item_related prop_weapon_related = {2, 0, word_D_8003C4F0, 0, 0};
//D:8003C508
s32 D_8003C508 = 0;
//D:8003C50C
s32 D_8003C50C = 0;

//D:8003C510
struct prop_pos_data dword_D_8003C510[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x000C},
    {0x0002, 0x000C, 0x0009},
    {0x0002, 0x000F, 0x0012},
    {0x0002, 0x0012, 0x000F},
    {0x0002, 0x0015, 0x0018},
    {0x0002, 0x0018, 0x0015},
    {0x0002, 0x001B, 0x001E},
    {0x0002, 0x001E, 0x001B},
    {0x0002, 0x0021, 0x0024},
    {0x0002, 0x0024, 0x0021},
    {0x0002, 0x0027, 0x002A},
    {0x0002, 0x002A, 0x0027}
};


//item_related struct
//D:8003C570
struct item_related dword_D_8003C570 = {0x10, 0x0000, dword_D_8003C510, 0x2D, 0x0000};

//D:8003C57C
s32 D_8003C57C = 0;


//D:8003C580
struct player_gait_header player_gait_hdr = {0, 1, 0, &player_gait_obj, NULL, 0, 0, &player_gait_pos_hdr_1};
//D:8003C598
struct player_gait_pos_header player_gait_pos_hdr_1 = {0, 2, 0, &player_gait_pos_1, (struct player_gait_pos_header *)&player_gait_hdr, 0, 0, &player_gait_pos_hdr_2};
//D:8003C5B0
struct player_gait_pos_header player_gait_pos_hdr_2 = {0, 2, 0, &player_gait_pos_2, &player_gait_pos_hdr_1, 0, 0, &player_gait_pos_hdr_3};
//D:8003C5C8
struct player_gait_pos_header player_gait_pos_hdr_3 = {0, 2, 0, &player_gait_pos_3, &player_gait_pos_hdr_2, 0, 0, 0};
//D:8003C5E0
struct player_gait_object_entry player_gait_obj = {1, &player_gait_pos_hdr_1, 0, 0};
//D:8003C5F0
struct player_gait_position_entry player_gait_pos_1 = {0.0, 0.0, 0.0, 0x0001, 0x0002, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_2, 0};
//D:8003C60C
struct player_gait_position_entry player_gait_pos_2 = {1.177982, 41.14437, 0, 0x0002, 0x0003, 0xFFFF, 0xFFFF, &player_gait_pos_hdr_3, 0};
//D:8003C628
struct player_gait_position_entry player_gait_pos_3 = {-2.576027, 480.42902, 0, 0x0003, 0x0000, 0xFFFF, 0xFFFF, NULL, 0};


//D:8003C644
s32 D_8003C644 = 0;
//D:8003C648
s32 D_8003C648 = 0;
//D:8003C64C
s32 D_8003C64C = 0;


//D:8003C650
struct object_header player_gait_object = {0, &dword_D_8003C570,0,0, 4, 41.16123,0,0,0,0};


//D:8003C670
struct prop_pos_data dword_D_8003C670[] = {
    {0x0401, 0x0000, 0x0000},
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x000C},
    {0x0002, 0x000C, 0x0009},
    {0x0002, 0x000F, 0x0012},
    {0x0002, 0x0012, 0x000F},
    {0x0002, 0x0015, 0x0018},
    {0x0002, 0x0018, 0x0015},
    {0x0002, 0x001B, 0x001E},
    {0x0002, 0x001E, 0x001B},
    {0x0002, 0x0021, 0x0024},
    {0x0002, 0x0024, 0x0021},
    {0x0002, 0x0027, 0x002A},
    {0x0002, 0x002A, 0x0027},
    {0x0015, 0x002D, 0x002D},
    {0x0015, 0x002E, 0x002E},
    {0x0015, 0x002F, 0x002F},
};

//D:8003C6E4
struct item_related model_suit_lf_hand = {0x13, 0x0000, dword_D_8003C670, 0x2D, 0x0000};

//D:8003C6F0
struct prop_pos_data dword_D_8003C6F0[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0015, 0x000F, 0x000F},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C}
};
//D:8003C714
struct item_related weapon_gun_standard_gun = {0x6, 0x0000, dword_D_8003C6F0, 0xF, 0x0000};

//D:8003C720
struct prop_pos_data dword_D_8003C720[] = {
    {0x0002, 0x0000, 0x0000}
};
//D:8003C728
struct item_related weapon_gun_unassigned = {0x1, 0x0000, dword_D_8003C720, 0x3, 0x0000};

//D:8003C734
s32 D_8003C734 = 0;
//D:8003C738
s32 D_8003C738 = 0;
//D:8003C73C
s32 D_8003C73C = 0;
//D:8003C740
struct prop_pos_data dword_D_8003C740[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F},
    {0x0002, 0x0012, 0x0012}
};
//D:8003C76C
struct item_related weapon_gun_revolver = {0x7, 0x0000, dword_D_8003C740, 0x15, 0x0000};

//D:8003C778
s32 D_8003C778 = 0;
//D:8003C77C
s32 D_8003C77C = 0;
//D:8003C780
struct prop_pos_data dword_D_8003C780[] = {
    {0x0002, 0x0000, 0x0000},
    {0x0002, 0x0003, 0x0003},
    {0x0002, 0x0006, 0x0006},
    {0x0002, 0x0009, 0x0009},
    {0x0015, 0x0012, 0x0012},
    {0x0002, 0x000C, 0x000C},
    {0x0002, 0x000F, 0x000F}
};
//D:8003C7AC
struct item_related weapon_gun_kf7 = {0x7, 0x0000, dword_D_8003C780, 0x12, 0x0000};

//D:8003C7B8
s32 D_8003C7B8 = 0;
//D:8003C7BC
s32 D_8003C7BC = 0;

//D:8003C7C0
struct Gitemheader GwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xC, 0, 0};
//D:8003C7E0
struct Gitemheader GwppksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.66476, 0, 0xC, 0, 0};
//D:8003C800
struct Gitemheader Gtt33Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 438.16788, 0, 0xF, 0, 0};
//D:8003C820
struct Gitemheader GskorpianZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 390.40039, 0, 0xC, 0, 0};
//D:8003C840
struct Gitemheader Gak47Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 941.9339, 0, 0x12, 0, 0};
//D:8003C860
struct Gitemheader GuziZ_struct = {0, &weapon_gun_kf7, 0, 0x24, 5, 436.95404, 0, 0xC, 0, 0};
//D:8003C880
struct Gitemheader Gmp5kZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 499.24536, 0, 9, 0, 0};
//D:8003C8A0
struct Gitemheader Gmp5ksilZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 655.97717, 0, 9, 0, 0};
//D:8003C8C0
struct Gitemheader Gm16Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 1096.2413, 0, 8, 0, 0};
//D:8003C8E0
struct Gitemheader Gfnp90Z_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 460.81909, 0, 0xA, 0, 0};
//D:8003C900
struct Gitemheader G8003C900_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 238.62167, 0, 4, 0, 0};
//D:8003C920
struct Gitemheader GrugerZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 6, 553.44312, 0, 0xE, 0, 0};
//D:8003C940
struct Gitemheader GgoldengunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 5, 384.92172, 0, 0xB, 0, 0};
//D:8003C960
struct Gitemheader GshotgunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 4, 919.33038, 0, 0xD, 0, 0};
//D:8003C980
struct Gitemheader GautoshotZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 840.15125, 0, 0x10, 0, 0};
//D:8003C9A0
struct Gitemheader GgrenadelaunchZ_struct = {0, &weapon_gun_revolver, 0, 0x24, 5, 768.33496, 0, 0xF, 0, 0};
//D:8003C9C0
struct Gitemheader GspectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 598.42865, 0, 0xB, 0, 0};
//D:8003C9E0
struct Gitemheader GlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 442.81848, 0, 0xD, 0, 0};
//D:8003CA00
struct Gitemheader GrocketlaunchZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 566.51208, 0, 0xA, 0, 0};
//D:8003CA20
struct Gitemheader GknifeZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 376.97263, 0, 9, 0, 0};
//D:8003CA40
struct Gitemheader GthrowknifeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 373.31387, 0, 9, 0, 0};
//D:8003CA60
struct Gitemheader GtaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 182.78622, 0, 0x11, 0, 0};
//D:8003CA80
struct Gitemheader GremotemineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 50.999378, 0, 3, 0, 0};
//D:8003CAA0
struct Gitemheader GproximitymineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 51.00029, 0, 3, 0, 0};
//D:8003CAC0
struct Gitemheader GtimedmineZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 49.368877, 0, 4, 0, 0};
//D:8003CAE0
struct Gitemheader GtriggerZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003CB00
struct Gitemheader GgrenadeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 427.27081, 0, 5, 0, 0};
//D:8003CB20
struct Gitemheader GfistZ_header = {0, &weapon_gun_standard_gun, 0, 0x24, 3, 243.84764, 0, 0xE, 0, 0};
//D:8003CB40
struct Gitemheader GsniperrifleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 808.03253, 0, 7, 0, 0};
//D:8003CB60
struct Gitemheader GcartridgeZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 14.128822, 0, 2, 0, 0};
//D:8003CB80
struct Gitemheader GcartrifleZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBA0
struct Gitemheader GcartblueZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 30.122747, 0, 2, 0, 0};
//D:8003CBC0
struct Gitemheader GcartshellZ_struct = {0, &weapon_gun_unassigned, 0, 0, 1, 29.8451, 0, 2, 0, 0};
//D:8003CBE0
struct Gitemheader GjoypadZ_struct = {0, &weapon_gun_controller, 0, 0xE, 0xD, 523.96826, 0, 4, 0, 0};
//D:8003CC00
struct Gitemheader G8003CC00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC20
struct Gitemheader G8003CC20_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC40
struct Gitemheader GbombcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CC60
struct Gitemheader GflarepistolZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CC80
struct Gitemheader GpitongunZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCA0
struct Gitemheader G8003CCA0_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CCC0
struct Gitemheader GsilverwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CCE0
struct Gitemheader GgoldwppkZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 6, 293.60767, 0, 0xB, 0, 0};
//D:8003CD00
struct Gitemheader G8003CD00_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD20
struct Gitemheader GbungeeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CD40
struct Gitemheader GdoordecoderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.850407, 0, 0x10, 0, 0};
//D:8003CD60
struct Gitemheader GbombdefuserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 84.370705, 0, 0xC, 0, 0};
//D:8003CD80
struct Gitemheader GbugdetectorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CDA0
struct Gitemheader GsafecrackercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CDC0
struct Gitemheader GcameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 52.775627, 0, 0xB, 0, 0};
//D:8003CDE0
struct Gitemheader GlockexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE00
struct Gitemheader GdoorexploderZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CE20
struct Gitemheader GkeyanalysercaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE40
struct Gitemheader GweaponcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003CE60
struct Gitemheader GkeycardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 123.088844, 0, 2, 0, 0};
//D:8003CE80
struct Gitemheader GkeyyaleZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 414.25156, 0, 1, 0, 0};
//D:8003CEA0
struct Gitemheader GkeyboltZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 759.26581, 0, 1, 0, 0};
//D:8003CEC0
struct Gitemheader GbugZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 106.2163, 0, 6, 0, 0};
//D:8003CEE0
struct Gitemheader GmicrocameraZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 70.039436, 0, 7, 0, 0};
//D:8003CF00
struct Gitemheader GexplosivefloppyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 60.902443, 0, 5, 0, 0};
//D:8003CF20
struct Gitemheader GgoldeneyekeyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 98.987083, 0, 5, 0, 0};
//D:8003CF40
struct Gitemheader GpolarizedglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 53.776386, 0, 2, 0, 0};
//D:8003CF60
struct Gitemheader GcreditcardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CF80
struct Gitemheader GdarkglassesZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003CFA0
struct Gitemheader GwatchidentifierZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFC0
struct Gitemheader GwatchcommunicatorZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003CFE0
struct Gitemheader GwatchlaserZ_struct = {0, &weapon_gun_standard_gun, 0, 0x24, 4, 283.9006, 0, 0x16, 0, 0};
//D:8003D000
struct Gitemheader GwatchgeigercounterZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D020
struct Gitemheader GwatchmagnetrepelZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 384.9288, 0, 9, 0, 0};
//D:8003D040
struct Gitemheader GwatchmagnetattractZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1D, 3, 384.9288, 0, 9, 0, 0};
//D:8003D060
struct Gitemheader GgaskeyringZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 111.59859, 0, 9, 0, 0};
//D:8003D080
struct Gitemheader GdatathiefZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 119.78231, 0, 3, 0, 0};
//D:8003D0A0
struct Gitemheader GbriefcaseZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 116.11074, 0, 6, 0, 0};
//D:8003D0C0
struct Gitemheader GblackboxZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 128.31796, 0, 5, 0, 0};
//D:8003D0E0
struct Gitemheader GplastiqueZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 255.35242, 0, 3, 0, 0};
//D:8003D100
struct Gitemheader GvideotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 122.69632, 0, 9, 0, 0};
//D:8003D120
struct Gitemheader GclipboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 190.41742, 0, 3, 0, 0};
//D:8003D140
struct Gitemheader GstafflistZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 215.17534, 0, 4, 0, 0};
//D:8003D160
struct Gitemheader GdossierredZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 183.54231, 0, 4, 0, 0};
//D:8003D180
struct Gitemheader GaudiotapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 97.531075, 0, 9, 0, 0};
//D:8003D1A0
struct Gitemheader GdattapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 79.868584, 0, 4, 0, 0};
//D:8003D1C0
struct Gitemheader GplansZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 81.950996, 0, 5, 0, 0};
//D:8003D1E0
struct Gitemheader GspyfileZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D200
struct Gitemheader GblueprintsZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 125.3834, 0, 4, 0, 0};
//D:8003D220
struct Gitemheader GcircuitboardZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 138.90285, 0, 3, 0, 0};
//D:8003D240
struct Gitemheader GmapZ_struct = {0, &weapon_gun_standard_gun, 0, 0x23, 3, 125.3834, 0, 4, 0, 0};
//D:8003D260
struct Gitemheader GspooltapeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D280
struct Gitemheader GmicrofilmZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2A0
struct Gitemheader GmicrocodeZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2C0
struct Gitemheader GlectreZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D2E0
struct Gitemheader GmoneyZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D300
struct Gitemheader GgoldbarZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};
//D:8003D320
struct Gitemheader GheroinZ_struct = {0, &weapon_gun_standard_gun, 0, 0x1C, 3, 134.8334, 0, 2, 0, 0};

//D:8003D340
u32 dword_D_8003D340[] = {0x20000,         2,   0x30003,   0x20006,
                          0x60002,   0x90009,   0x2000C,   0xC0002,
                          0xF000F,   0x20012,  0x120002,  0x150015,
                          0x20018,  0x180002,  0x1B001B,   0x2001E,
                          0x1E0002,  0x210021,   0x20024,  0x240000};

//D:8003D390
struct model_data weapon_gun_controller = {0xD0000, dword_D_8003D340, 0x270000};
//D:8003D39C
s32 D_8003D39C = 0;

u32 dword_D_8003D3A0[] = {0x4010000,         2,         0,   0x20003,
                          0x30002,   0x60006,   0x20009,   0xC0002,
                          0xC0009,   0x2000F,  0x120002,  0x12000F,
                          0x20015,  0x180002,  0x180015,   0x2001B,
                          0x1E0002,  0x1E001B,   0x20021,  0x240002,
                          0x240021,   0x20027,  0x2A0002,  0x2A0027};


//D:8003D400
     struct model_data model_guard_character = {0x100000, dword_D_8003D3A0, 0x2D0000};
//D:8003D40C
s32 D_8003D40C = 0;

//D:8003D410
struct object_header CcamguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0};
//D:8003D430
struct object_header CgreyguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xD, 0, 0};
//D:8003D450
struct object_header ColiveguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0x10, 0, 0};
//D:8003D470
struct object_header CrusguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xD, 0, 0};
//D:8003D490
struct object_header CtrevguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x12, 0, 0};
//D:8003D4B0
struct object_header CborisZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1223.1553, 0, 0x15, 0, 0};
//D:8003D4D0
struct object_header CorumovZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1347.004, 0, 0x15, 0, 0};
//D:8003D4F0
struct object_header CtrevelyanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0};
//D:8003D510
struct object_header CboilertrevZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1263.2534, 0, 0x10, 0, 0};
//D:8003D530
struct object_header CvalentinZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1208.6277, 0, 0x10, 0, 0};
//D:8003D550
struct object_header CxeniaZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1285.4487, 0, 0x13, 0, 0};
//D:8003D570
struct object_header CbaronsamediZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.5995, 0, 0x19, 0, 0};
//D:8003D590
struct object_header CjawsZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1550.059, 0, 0x14, 0, 0};
//D:8003D5B0
struct object_header CmaydayZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.657, 0, 0x10, 0, 0};
//D:8003D5D0
struct object_header CoddjobZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1082.4603, 0, 0x12, 0, 0};
//D:8003D5F0
struct object_header CnatalyaZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1226.1493, 0, 0x10, 0, 0};
//D:8003D610
struct object_header CarmourguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x11, 0, 0};
//D:8003D630
struct object_header CcommguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0};
//D:8003D650
struct object_header CgreatguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0xB, 0, 0};
//D:8003D670
struct object_header CnavyguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xF, 0, 0};
//D:8003D690
struct object_header CsnowguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1261.1731, 0, 0x11, 0, 0};
//D:8003D6B0
struct object_header CbluewomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1148.2167, 0, 0xD, 0, 0};
//D:8003D6D0
struct object_header CfattechwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1149.4025, 0, 0xC, 0, 0};
//D:8003D6F0
struct object_header CtechwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1158.2109, 0, 0xC, 0, 0};
//D:8003D710
struct object_header CjeanwomanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xF, 0, 0};
//D:8003D730
struct object_header CgreymanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1293.0195, 0, 0xF, 0, 0};
//D:8003D750
struct object_header CbluemanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0};
//D:8003D770
struct object_header CredmanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xF, 0, 0};
//D:8003D790
struct object_header CcardimanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0xE, 0, 0};
//D:8003D7B0
struct object_header CcheckmanZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.6892, 0, 0x10, 0, 0};
//D:8003D7D0
struct object_header CtechmanZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1292.6892, 0, 0xC, 0, 0};
//D:8003D7F0
struct object_header CpilotZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0x18, 0, 0};
//D:8003D810
struct object_header Cgreatguard2Z_struct = {0, &model_guard_character, 0, 7, 0x14, 1283.0787, 0, 0x10, 0, 0};
//D:8003D830
struct object_header CbluecamguardZ_struct = {0, &model_guard_character, 0, 7, 0x14, 1260.4969, 0, 0xE, 0, 0};
//D:8003D850
struct object_header CmoonguardZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1260.4969, 0, 0xD, 0, 0};
//D:8003D870
struct object_header CmoonfemaleZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1124.0725, 0, 0xB, 0, 0};
//D:8003D890
struct object_header CboilerbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1273.6262, 0, 0xD, 0, 0};
//D:8003D8B0
struct object_header CsuitbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1292.3391, 0, 0xE, 0, 0};
//D:8003D8D0
struct object_header CtimberbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1282.7715, 0, 0x10, 0, 0};
//D:8003D8F0
struct object_header CsnowbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1299.1359, 0, 0xE, 0, 0};
//D:8003D910
struct object_header CdjbondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1285.0543, 0, 0xD, 0, 0};
//D:8003D930
struct object_header Csuit_lf_handz_struct = {0, &model_suit_lf_hand, 0, 0xA, 9, 12231.949, 0, 0x16, 0, 0};
//D:8003D950
struct object_header CheadkarlZ_struct = {0, NULL, 0, 2, 1, 218.15375, 0, 6, 0, 0};
//D:8003D970
struct object_header CheadalanZ_struct = {0, NULL, 0, 2, 1, 215.03685, 0, 4, 0, 0};
//D:8003D990
struct object_header CheadpeteZ_struct = {0, NULL, 0, 2, 1, 216.28949, 0, 4, 0, 0};
//D:8003D9B0
struct object_header CheadmartinZ_struct = {0, NULL, 0, 2, 1, 222.34796, 0, 6, 0, 0};
//D:8003D9D0
struct object_header stru_D_8003D9D0 = {0, NULL, 0, 2, 1, 220.2446, 0, 5, 0, 0};
//D:8003D9F0
struct object_header stru_D_8003D9F0 = {0, NULL, 0, 2, 1, 201.51955, 0, 5, 0, 0};
//D:8003DA10
struct object_header stru_D_8003DA10 = {0, NULL, 0, 2, 1, 212.62949, 0, 5, 0, 0};
//D:8003DA30
struct object_header stru_D_8003DA30 = {0, NULL, 0, 2, 1, 218.35564, 0, 4, 0, 0};
//D:8003DA50
struct object_header stru_D_8003DA50 = {0, NULL, 0, 2, 1, 192.53412, 0, 4, 0, 0};
//D:8003DA70
struct object_header stru_D_8003DA70 = {0, NULL, 0, 2, 1, 218.35564, 0, 4, 0, 0};
//D:8003DA90
struct object_header stru_D_8003DA90 = {0, NULL, 0, 2, 1, 227.52234, 0, 4, 0, 0};
//D:8003DAB0
struct object_header stru_D_8003DAB0 = {0, NULL, 0, 2, 1, 228.29831, 0, 4, 0, 0};
//D:8003DAD0
struct object_header stru_D_8003DAD0 = {0, NULL, 0, 2, 1, 235.64778, 0, 6, 0, 0};
//D:8003DAF0
struct object_header stru_D_8003DAF0 = {0, NULL, 0, 2, 1, 218.35564, 0, 5, 0, 0};
//D:8003DB10
struct object_header stru_D_8003DB10 = {0, NULL, 0, 2, 1, 240.50017, 0, 4, 0, 0};
//D:8003DB30
struct object_header stru_D_8003DB30 = {0, NULL, 0, 2, 1, 234.83342, 0, 4, 0, 0};
//D:8003DB50
struct object_header stru_D_8003DB50 = {0, NULL, 0, 2, 1, 228.24614, 0, 4, 0, 0};
//D:8003DB70
struct object_header stru_D_8003DB70 = {0, NULL, 0, 2, 1, 228.55029, 0, 4, 0, 0};
//D:8003DB90
struct object_header stru_D_8003DB90 = {0, NULL, 0, 2, 1, 212.62949, 0, 2, 0, 0};
//D:8003DBB0
struct object_header stru_D_8003DBB0 = {0, NULL, 0, 2, 1, 219.82707, 0, 6, 0, 0};
//D:8003DBD0
struct object_header stru_D_8003DBD0 = {0, NULL, 0, 2, 1, 193.20615, 0, 5, 0, 0};
//D:8003DBF0
struct object_header stru_D_8003DBF0 = {0, NULL, 0, 2, 1, 235.64778, 0, 4, 0, 0};
//D:8003DC10
struct object_header stru_D_8003DC10 = {0, NULL, 0, 2, 1, 223.18559, 0, 4, 0, 0};
//D:8003DC30
struct object_header stru_D_8003DC30 = {0, NULL, 0, 2, 1, 218.35564, 0, 5, 0, 0};
//D:8003DC50
struct object_header stru_D_8003DC50 = {0, NULL, 0, 2, 1, 193.20615, 0, 4, 0, 0};
//D:8003DC70
struct object_header stru_D_8003DC70 = {0, NULL, 0, 2, 1, 235.64778, 0, 5, 0, 0};
//D:8003DC90
struct object_header stru_D_8003DC90 = {0, NULL, 0, 2, 1, 193.20615, 0, 3, 0, 0};
//D:8003DCB0
struct object_header stru_D_8003DCB0 = {0, NULL, 0, 2, 1, 224.83139, 0, 3, 0, 0};
//D:8003DCD0
struct object_header stru_D_8003DCD0 = {0, NULL, 0, 2, 1, 219.97256, 0, 3, 0, 0};
//D:8003DCF0
struct object_header stru_D_8003DCF0 = {0, NULL, 0, 2, 1, 203.44904, 0, 3, 0, 0};
//D:8003DD10
struct object_header stru_D_8003DD10 = {0, NULL, 0, 2, 1, 196.83067, 0, 3, 0, 0};
//D:8003DD30
struct object_header stru_D_8003DD30 = {0, NULL, 0, 2, 1, 176.67717, 0, 1, 0, 0};
//D:8003DD50
struct object_header stru_D_8003DD50 = {0, NULL, 0, 2, 1, 190.61967, 0, 4, 0, 0};
//D:8003DD70
struct object_header CheadbrosnansuitZ_struct = {0, NULL, 0, 2, 1, 212.45657, 0, 5, 0, 0};
//D:8003DD90
struct object_header CheadbrosnantimberZ_struct = {0, NULL, 0, 2, 1, 179.28358, 0, 4, 0, 0};
//D:8003DDB0
struct object_header CheadbrosnansnowZ_struct = {0, NULL, 0, 2, 1, 225.0605, 0, 6, 0, 0};
//D:8003DDD0
struct object_header CheadbrosnanZ_struct = {0, NULL, 0, 2, 1, 189.48112, 0, 5, 0, 0};
//D:8003DDF0
struct object_header CspicebondZ_struct = {0, &model_guard_character, 0, 7, 0x15, 1208.6448, 0, 0x11, 0, 0};
const char padding_chars_for_strings[] = "\00\00\00\00\00\00\00\00\00\00\00";
struct c_itementry c_item_entries[] = {
    {&CcamguardZ_struct, "CcamguardZ", 1.0, 1.0, 0x1000000},
    {&CgreyguardZ_struct, "CgreyguardZ", 1.0, 1.0, 0x1000000},
    {&ColiveguardZ_struct, "ColiveguardZ", 1.0, 1.0, 0x1000000},
    {&CrusguardZ_struct, "CrusguardZ", 1.0, 1.0, 0x1000000},
    {&CtrevguardZ_struct, "CtrevguardZ", 1.0, 1.0, 0x1000000},
    {&CdjbondZ_struct, "CdjbondZ", 1.0, 1.0446, 0x1000000},
    {&CborisZ_struct, "CborisZ", 1.0, 0.9702, 0x1010000},
    {&CorumovZ_struct, "CorumovZ", 1.0, 1.0778, 0x1010000},
    {&CtrevelyanZ_struct, "CtrevelyanZ", 1.0, 1.0, 0x1010000},
    {&CboilertrevZ_struct, "CboilertrevZ", 1.0, 1.0, 0x1010000},
    {&CvalentinZ_struct, "CvalentinZ", 1.0, 0.93239999, 0x1010000},
    {&CxeniaZ_struct, "CxeniaZ", 1.0, 1.0, 0x10000},
    {&CbaronsamediZ_struct, "CbaronsamediZ", 1.0, 1.0, 0x1010000},
    {&CjawsZ_struct, "CjawsZ", 1.0, 1.199, 0x1010000},
    {&CmaydayZ_struct, "CmaydayZ", 1.0, 1.0, 0x10000},
    {&CoddjobZ_struct, "CoddjobZ", 1.0, 0.78780001, 0x1010000},
    {&CnatalyaZ_struct, "CnatalyaZ", 1.0, 0.96609998, 0x10000},
    {&CarmourguardZ_struct, "CarmourguardZ", 1.0, 1.0, 0x1000000},
    {&CcommguardZ_struct, "CcommguardZ", 1.0, 1.0, 0x1000000},
    {&CgreatguardZ_struct, "CgreatguardZ", 1.0, 1.0, 0x1000000},
    {&CnavyguardZ_struct, "CnavyguardZ", 1.0, 1.0, 0x1000000},
    {&CsnowguardZ_struct, "CsnowguardZ", 1.0, 1.0, 0x1010000},
    {&CboilerbondZ_struct, "CboilerbondZ", 1.0, 1.0403, 0x1000000},
    {&CsuitbondZ_struct, "CsuitbondZ", 1.0, 1.058, 0x1000000},
    {&CtimberbondZ_struct, "CtimberbondZ", 1.0, 1.0438, 0x1000000},
    {&CsnowbondZ_struct, "CsnowbondZ", 1.0, 1.0438, 0x1000000},
    {&CbluewomanZ_struct, "CbluewomanZ", 1.0, 0.88529998, 0},
    {&CfattechwomanZ_struct, "CfattechwomanZ", 1.0, 0.88529998, 0},
    {&CtechwomanZ_struct, "CtechwomanZ", 1.0, 0.91600001, 0},
    {&CjeanwomanZ_struct, "CjeanwomanZ", 1.0, 0.88529998, 0},
    {&CgreymanZ_struct, "CgreymanZ", 1.0, 1.0, 0x1000000},
    {&CbluemanZ_struct, "CbluemanZ", 1.0, 1.0, 0x1000000},
    {&CredmanZ_struct, "CredmanZ", 1.0, 1.0, 0x1000000},
    {&CcardimanZ_struct, "CcardimanZ", 1.0, 1.0, 0x1000000},
    {&CcheckmanZ_struct, "CcheckmanZ", 1.0, 1.0, 0x1000000},
    {&CtechmanZ_struct, "CtechmanZ", 1.0, 1.0, 0x1000000},
    {&CpilotZ_struct, "CpilotZ", 1.0, 1.0, 0x1010000},
    {&Cgreatguard2Z_struct, "Cgreatguard2Z", 1.0, 1.0, 0x1000000},
    {&CbluecamguardZ_struct, "CbluecamguardZ", 1.0, 1.0, 0x1000000},
    {&CmoonguardZ_struct, "CmoonguardZ", 1.0, 1.0, 0x1000000},
    {&CmoonfemaleZ_struct, "CmoonfemaleZ", 1.0, 0.88529998, 0},
    {&Csuit_lf_handz_struct, "Csuit_lf_handZ", 0.1, 1.0, 0x1000000},
    {&CheadkarlZ_struct, "CheadkarlZ", 1.0, 1.0, 0x1010000},
    {&CheadalanZ_struct, "CheadalanZ", 1.0, 1.0, 0x1010000},
    {&CheadpeteZ_struct, "CheadpeteZ", 1.0, 1.0, 0x1010000},
    {&CheadmartinZ_struct, "CheadmartinZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003D9D0, "CheadmarkZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003D9F0, "CheadduncanZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA30, "CheadshaunZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA50, "CheaddwayneZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA10, "CheadbZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA70, "CheaddaveZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DA90, "CheadgrantZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DAB0, "CheaddesZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DAD0, "CheadchrisZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DAF0, "CheadleeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB10, "CheadneilZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB30, "CheadjimZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB50, "CheadrobinZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB70, "CheadstevehZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DB90, "CheadbalaclavaZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DBB0, "CheadbikeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DBD0, "CheadgrahamZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DBF0, "CheadsteveeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC10, "CheadjoelZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC30, "CheadscottZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC50, "CheadjoeZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC70, "CheadkenZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DC90, "Cheadjoe2Z", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DCB0, "CheadmishkinZ", 1.0, 1.0, 0x1010000},
    {&stru_D_8003DCD0, "CheadsallyZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DCF0, "CheadmarionZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DD10, "CheadmandyZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DD30, "CheadvivienZ", 1.0, 1.0, 0x10000},
    {&stru_D_8003DD50, "CheadbrosnanboilerZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnansuitZ_struct, "CheadbrosnansuitZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnantimberZ_struct, "CheadbrosnantimberZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnansnowZ_struct, "CheadbrosnansnowZ", 1.0, 1.0, 0x1010000},
    {&CheadbrosnanZ_struct, "CheadbrosnanZ", 1.0, 1.0, 0x1010000},
    {&CspicebondZ_struct, "CspicebondZ", 0.94999999, 0.96609998, 0x10000},
};


//D:8003E450
u32 D_8003E450 = 0;
u32 D_8003E454 = 0;
//D:8003E458
f32 D_8003E458 = 1.0;
//D:8003E45C
u32 D_8003E45C = 0;
//D:8003E460
u32 D_8003E460 = 0;

//D:8003E464
struct headHat headHat_array_8003E464[] = 
{
  {
    -0.076300003, 0.77999997, -1.2696, 1.1694109, 1.120654, 1.05959
  },
  {
    -0.25760001, -0.47319999, -1.5686001, 1.132916, 1.0, 1.080207
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.039999999, 0.74000001, -0.63999999, 1.132795, 1.167207, 1.035167
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.033500001, 0.24959999, 0.16599999, 1.115045, 0.94169998, 1.042492
  },
  {
    -0.070299998, 0.4919, -0.83359998, 1.072812, 1.088326, 0.926121
  },
  {
    -0.1, 0.42750001, -0.48249999, 1.033368, 0.96552098, 0.929905
  },
  {
    0.18000001, 0.0, 0.0, 1.072214, 1.0, 1.0
  },
  {
    0.237, 0.977, -0.44, 1.178463, 1.14061, 1.143465
  },
  {
    -0.090300001, 0.23190001, 0.12639999, 0.99080002, 1.02, 0.8466
  },
  {
    0.0, 0.1485, 0.3793, 1.1548001, 0.99190003, 0.95139998
  },
  {
    -0.14820001, 0.44100001, 0.1727, 1.050034, 1.0, 1.05445
  },
  {
    -0.4941, -0.26409999, -0.18000001, 0.90368301, 0.72551203, 1.001314
  },
  {
    0.1318, 0.30100101, 1.572699, 0.98799503, 1.0, 1.05445
  },
  {
    0.0, 0.73019999, 0.71740001, 1.1923, 1.1834, 1.091924
  },
  {
    -0.0942, -0.74190003, 0.94260001, 0.98659998, 0.91689998, 0.94760001
  },
  {
    0.0535, 0.61510003, 1.076, 1.05092, 0.90002, 1.122508
  },
  {
    -0.079999998, 0.1085, -0.56629997, 1.192598, 1.079134, 1.199971
  },
  {
    -0.35640001, -0.28709999, -0.36950001, 1.035176, 0.838543, 1.121092
  },
  {
    0.065300003, -0.4664, 0.72000003, 1.050106, 1.0, 1.11042
  },
  {
    -0.079999998, 0.4885, 0.093699999, 1.158567, 1.2356189, 1.194388
  },
  {
    -0.0942, -0.3017, 0.59450001, 1.0671999, 1.0218, 1.0174
  },
  {
    0.12, -0.1515, 0.95370001, 1.124017, 0.966048, 1.206121
  },
  {
    -0.19310001, 0.2334, -0.64850003, 1.1800359, 1.0401829, 1.154537
  },
  {
    -0.36230001, -0.133, -0.486, 1.0536211, 1.0, 1.1495841
  },
  {
    0.0955, 0.68099999, 0.78799999, 1.0152, 1.1926, 1.1308
  },
  {
    -0.0823, 0.36700001, 0.37400001, 1.311748, 1.115972, 1.166244
  },
  {
    -0.0942, 0.1768, 0.5248, 1.0470001, 1.0218, 0.99800003
  },
  {
    0.0, -0.0964, 0.82999998, 1.1109999, 0.85180199, 1.180503
  },
  {
    -0.1832, 0.32120001, -1.2381001, 1.125683, 1.091681, 0.98079097
  },
  {
    -0.55049998, -0.60839999, -1.189499, 1.023566, 0.8326, 1.0637
  },
  {
    0.076800004, 0.32120001, -0.118101, 1.059677, 1.091681, 1.000479
  },
  {
    0.0, 0.29890001, -0.67299998, 1.1367, 1.0526, 0.99227399
  },
  {
    -0.0942, 0.032000002, -0.29699999, 1.0402, 0.92860001, 0.88690001
  },
  {
    0.0, 0.26879999, 0.057399999, 1.041842, 0.81959999, 0.99637401
  },
  {
    0.079700001, 0.3511, 0.0, 1.0, 1.0, 1.0835
  },
  {
    0.14, 0.1965, -0.058398999, 1.012674, 0.96799999, 1.098917
  },
  {
    0.1629, 0.78799999, 1.0746, 0.92205501, 1.0688, 1.055297
  },
  {
    -0.074500002, 0.8477, 0.71810001, 1.154819, 1.177258, 1.031684
  },
  {
    -0.0145, 0.047699999, 0.89810002, 1.0404, 1.0, 0.94309998
  },
  {
    0.32550001, 0.36770001, 0.93809998, 1.044217, 0.97841102, 1.127771
  },
  {
    -0.1832, -0.058800001, -1.5781, 1.095929, 0.96300697, 0.92348999
  },
  {
    -0.4411, -0.64840001, -1.839099, 1.059271, 0.8326, 0.96849501
  },
  {
    0.19679999, -0.3188, -0.43810099, 1.070675, 1.053777, 0.88628101
  },
  {
    0.0, 0.29890001, -0.83139998, 1.1154, 1.0328, 1.0036
  },
  {
    -0.0942, -0.1275, -0.52109998, 1.0402, 0.92180002, 0.8617
  },
  {
    0.079999998, -0.2383, -0.22940101, 1.063022, 0.80879998, 0.90789998
  },
  {
    0.1165, 0.58780003, -1.3096, 1.136481, 1.0409, 1.065612
  },
  {
    -0.070600003, 0.0152, -1.2391, 1.002256, 0.76669598, 1.029659
  },
  {
    0.2218, 0.0, 0.0, 1.0852, 1.0, 1.0
  },
  {
    0.063000001, 0.7561, -0.45269999, 1.2085, 1.1014, 1.0664001
  },
  {
    0.065499999, -0.1097, -0.3497, 1.0404, 0.90915602, 0.94940001
  },
  {
    0.0, 0.336, 0.082999997, 1.150862, 0.94169998, 1.0
  },
  {
    -0.054200001, 0.27079999, -0.082099997, 1.0367, 1.0367, 1.0367
  },
  {
    0.34119999, -0.55879998, -0.3044, 1.113436, 0.96799999, 1.076647
  },
  {
    0.0495, 0.63980001, 1.2178, 0.95099998, 1.1126, 1.0413001
  },
  {
    0.0, 0.53640002, 0.75220001, 1.1976, 1.1463, 1.1374
  },
  {
    -0.0145, -0.64749998, 1.0477999, 0.95289999, 0.92180002, 0.90579998
  },
  {
    0.16, 0.61830002, 1.128299, 1.083438, 0.91670603, 1.0666929
  },
  {
    -0.2586, 0.93580002, -0.2463, 1.1057, 1.0116, 1.0927
  },
  {
    -0.1788, -0.31310001, -0.55299997, 1.1071, 1.0, 1.071945
  },
  {
    0.0955, 0.16230001, 0.50150001, 1.0506001, 1.0, 1.1032
  },
  {
    0.081200004, 0.2269, 0.50700003, 1.1071, 1.178908, 1.189239
  },
  {
    -0.0145, -0.68440002, 0.54070002, 1.0470001, 0.92699999, 1.027078
  },
  {
    0.0, -0.0164, 0.66399997, 1.2108999, 1.0, 1.0729001
  },
  {
    -0.1487, 0.88779998, -0.41060001, 1.110018, 0.98460901, 1.110518
  },
  {
    0.0012000001, -0.61879998, -0.34439901, 1.099178, 0.916071, 1.054984
  },
  {
    0.0429, 0.2149, 0.4298, 1.0455, 1.0688, 1.1514
  },
  {
    0.0012000001, -0.0188, 0.65560102, 1.1957231, 1.079964, 1.200996
  },
  {
    -0.0145, -0.48769999, 0.44909999, 1.003074, 1.0, 0.98259997
  },
  {
    0.0, 0.396, 0.8362, 1.1622, 0.91339999, 1.066853
  },
  {
    -0.29030001, 1.0714999, -0.3504, 1.125893, 1.127159, 1.177758
  },
  {
    0.0, -0.079999998, -0.373, 1.099718, 1.0, 1.0947551
  },
  {
    0.0, 0.78799999, 0.64469999, 1.0, 1.0, 1.0963
  },
  {
    -0.074699998, 1.5436, 0.1979, 1.1497999, 1.1835999, 1.0791
  },
  {
    -0.090300001, -0.1085, 0.68959999, 1.024099, 1.0, 0.98965299
  },
  {
    0.0, 0.63230002, 0.7913, 1.1081001, 0.93440002, 1.0779999
  },
  {
    0.12, 0.40000001, 0.039999999, 1.022947, 0.92226201, 1.004824
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0429, 0.75889999, 1.2895, 0.94440001, 1.0, 1.0551
  },
  {
    0.0, 0.546, 0.79729998, 1.1483001, 1.1267999, 1.1388
  },
  {
    0.065099999, -0.54320002, 1.1224999, 0.93949997, 0.92699999, 0.93040001
  },
  {
    0.1265, 0.36359999, 1.079, 1.1109999, 1.0, 1.1166
  },
  {
    -0.278, 1.272301, -0.55269998, 1.24701, 1.0737129, 1.118222
  },
  {
    -0.23639999, 0.58200002, -0.30950001, 1.225595, 1.077682, 1.066005
  },
  {
    -0.0845, 0.68099999, 0.64469999, 1.1204081, 1.1927, 1.1308
  },
  {
    -0.1364, 1.021999, 0.5905, 1.153587, 1.226897, 1.2252491
  },
  {
    -0.2534, 0.57560003, 0.3856, 1.0405, 1.0405, 1.0585999
  },
  {
    -0.1265, 0.6081, 0.71200001, 1.222, 1.0, 1.111666
  },
  {
    -0.4637, 1.3971, -0.49270001, 1.1752, 1.0116, 1.1762
  },
  {
    -0.2976, -0.1049, -0.49649999, 1.2345999, 0.86470801, 1.077117
  },
  {
    -0.1151, 0.7353, 0.57309997, 1.0759, 1.0, 1.1308
  },
  {
    -0.189, 0.99910003, 0.2396, 1.2269, 1.2039, 1.1698999
  },
  {
    -0.2534, -0.0647, 0.30070001, 1.0470001, 0.92699999, 1.0124
  },
  {
    -0.1265, 0.61260003, 0.76700002, 1.2108999, 1.0, 1.096216
  },
  {
    -0.51429999, 1.0894001, -0.082099997, 1.1003, 1.0316, 1.0278
  },
  {
    -0.53280002, -0.13060001, -0.25999999, 1.080464, 1.0, 1.019003
  },
  {
    -0.1969, 0.45930001, 0.64469999, 0.96219999, 1.0, 1.0895
  },
  {
    -0.32690001, 1.1438, 0.46720001, 1.1339, 1.1339, 1.0436
  },
  {
    -0.29879999, 0.0, 0.41429999, 0.96219999, 1.0, 0.95630002
  },
  {
    -0.17640001, 0.39500001, 0.86699998, 1.0972, 0.94625998, 1.0529979
  },
  {
    0.02, 0.56910002, -0.25299999, 1.1205291, 0.999475, 1.072994
  },
  {
    -0.0823, -0.3784, -0.38249999, 1.077682, 1.0, 1.066239
  },
  {
    0.02, -0.1909, 0.90700001, 1.049657, 0.999475, 1.072994
  },
  {
    0.0, 0.60549998, 0.47510001, 1.1236, 1.1236, 1.1236
  },
  {
    -0.0942, 0.077600002, 0.5248, 1.0403, 0.95950001, 0.98580003
  },
  {
    0.0, 0.20550001, 0.8951, 1.1519721, 0.92378497, 1.0316401
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0836, -0.66259998, 0.14210001, 0.95139998, 1.090098, 0.92760003
  },
  {
    0.1141, -1.1931, -0.25400001, 0.98102301, 0.83667898, 0.88798702
  },
  {
    0.1481, -0.15360001, 1.1461999, 0.91399997, 1.0, 0.94489998
  },
  {
    0.0, -0.53250003, 0.3563, 1.0727, 1.0526, 1.0228
  },
  {
    -0.0942, -0.6857, 1.1224999, 0.95959997, 0.92860001, 0.88690001
  },
  {
    0.079999998, -0.7396, 0.963, 1.1032, 0.875673, 0.97771698
  },
  {
    -0.29030001, 1.0714999, -0.3504, 1.125893, 1.127159, 1.177758
  },
  {
    0.0, -0.079999998, -0.373, 1.099718, 1.0, 1.0947551
  },
  {
    0.0, 0.78799999, 0.64469999, 1.0, 1.0, 1.0963
  },
  {
    -0.074699998, 1.5436, 0.1979, 1.1497999, 1.1835999, 1.0791
  },
  {
    -0.090300001, -0.1085, 0.68959999, 1.024099, 1.0, 0.98965299
  },
  {
    0.0, 0.63230002, 0.7913, 1.1081001, 0.93440002, 1.0779999
  },
  {
    -0.13699999, 0.286001, -0.32229999, 1.142894, 0.89638299, 1.15
  },
  {
    -0.16680001, -0.1365, -0.43650001, 1.1452, 1.0, 1.061306
  },
  {
    0.1376, 0.0, 0.71600002, 1.05312, 1.0, 1.0687751
  },
  {
    -0.074699998, 0.9393, 0.2658, 1.1815, 1.1216, 1.0822999
  },
  {
    -0.103, -0.2269, 0.5722, 0.99080002, 1.02, 1.0034
  },
  {
    0.0, 0.1373, 0.79430002, 1.1813999, 0.86186302, 1.0998
  },
  {
    0.12, 0.40000001, 0.039999999, 1.022947, 0.92226201, 1.004824
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0429, 0.75889999, 1.2895, 0.94440001, 1.0, 1.0551
  },
  {
    0.0, 0.546, 0.79729998, 1.1483001, 1.1267999, 1.1388
  },
  {
    0.065099999, -0.54320002, 1.1224999, 0.93949997, 0.92699999, 0.93040001
  },
  {
    0.1265, 0.36359999, 1.079, 1.1109999, 1.0, 1.1166
  },
  {
    0.0836, -0.66259998, 0.14210001, 0.95139998, 1.090098, 0.92760003
  },
  {
    0.1141, -1.1931, -0.25400001, 0.98102301, 0.83667898, 0.88798702
  },
  {
    0.1481, -0.15360001, 1.1461999, 0.91399997, 1.0, 0.94489998
  },
  {
    0.0, -0.53250003, 0.3563, 1.0727, 1.0526, 1.0228
  },
  {
    -0.0942, -0.6857, 1.1224999, 0.95959997, 0.92860001, 0.88690001
  },
  {
    0.079999998, -0.7396, 0.963, 1.1032, 0.875673, 0.97771698
  },
  {
    -0.29030001, 1.0714999, -0.3504, 1.125893, 1.127159, 1.177758
  },
  {
    0.0, -0.079999998, -0.373, 1.099718, 1.0, 1.0947551
  },
  {
    0.0, 0.78799999, 0.64469999, 1.0, 1.0, 1.0963
  },
  {
    -0.074699998, 1.5436, 0.1979, 1.1497999, 1.1835999, 1.0791
  },
  {
    -0.090300001, -0.1085, 0.68959999, 1.024099, 1.0, 0.98965299
  },
  {
    0.0, 0.63230002, 0.7913, 1.1081001, 0.93440002, 1.0779999
  },
  {
    0.0836, -0.66259998, 0.14210001, 0.95139998, 1.090098, 0.92760003
  },
  {
    0.1141, -1.1931, -0.25400001, 0.98102301, 0.83667898, 0.88798702
  },
  {
    0.1481, -0.15360001, 1.1461999, 0.91399997, 1.0, 0.94489998
  },
  {
    0.0, -0.53250003, 0.3563, 1.0727, 1.0526, 1.0228
  },
  {
    -0.0942, -0.6857, 1.1224999, 0.95959997, 0.92860001, 0.88690001
  },
  {
    0.079999998, -0.7396, 0.963, 1.1032, 0.875673, 0.97771698
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  },
  {
    0.0, 0.0, 0.0, 1.0, 1.0, 1.0
  }
};