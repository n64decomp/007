#include <ultra64.h>
#include <memp.h>
#include "initanitable.h"
#include "objecthandler.h"

//bss
char dword_CODE_bss_80069170[0x2D0];
OSMesgQueue animMsgQ;
char dword_CODE_bss_80069458[0xC0];
OSMesg animMesg[8];
struct animation_table_data * ptr_animation_table;

//data
struct bondstruct_unk_animation_related D_80029D60 = {
    NULL,
    &dword_CODE_bss_80069170,
    &dword_CODE_bss_80069170
};

s32 animation_table_ptrs1[] = {
    PTR_ANIM_idle,
    PTR_ANIM_fire_standing,
    PTR_ANIM_fire_standing_fast,
    PTR_ANIM_fire_hip,
    PTR_ANIM_fire_shoulder_left,
    PTR_ANIM_fire_turn_right1,
    PTR_ANIM_fire_turn_right2,
    PTR_ANIM_fire_kneel_right_leg,
    PTR_ANIM_fire_kneel_left_leg,
    PTR_ANIM_fire_kneel_left,
    PTR_ANIM_fire_kneel_right,
    PTR_ANIM_fire_roll_left,
    PTR_ANIM_fire_roll_right1,
    PTR_ANIM_fire_roll_left_fast,
    PTR_ANIM_hit_left_shoulder,
    PTR_ANIM_hit_right_shoulder,
    PTR_ANIM_hit_left_arm,
    PTR_ANIM_hit_right_arm,
    PTR_ANIM_hit_left_hand,
    PTR_ANIM_hit_right_hand,
    PTR_ANIM_hit_left_leg,
    PTR_ANIM_hit_right_leg,
    PTR_ANIM_death_genitalia,
    PTR_ANIM_hit_neck,
    PTR_ANIM_death_neck,
    PTR_ANIM_death_stagger_back_to_wall,
    PTR_ANIM_death_forward_face_down,
    PTR_ANIM_death_forward_spin_face_up,
    PTR_ANIM_death_backward_fall_face_up1,
    PTR_ANIM_death_backward_spin_face_down_right,
    PTR_ANIM_death_backward_spin_face_up_right,
    PTR_ANIM_death_backward_spin_face_down_left,
    PTR_ANIM_death_backward_spin_face_up_left,
    PTR_ANIM_death_forward_face_down_hard,
    PTR_ANIM_death_forward_face_down_soft,
    PTR_ANIM_death_fetal_position_right,
    PTR_ANIM_death_fetal_position_left,
    PTR_ANIM_death_backward_fall_face_up2,
    PTR_ANIM_side_step_left,
    PTR_ANIM_fire_roll_right2,
    PTR_ANIM_walking,
    PTR_ANIM_sprinting,
    PTR_ANIM_running,
    PTR_ANIM_bond_eye_walk,
    PTR_ANIM_bond_eye_fire,
    PTR_ANIM_bond_watch,
    PTR_ANIM_surrendering_armed,
    PTR_ANIM_surrendering_armed_drop_weapon,
    PTR_ANIM_fire_walking,
    PTR_ANIM_fire_running,
    PTR_ANIM_null50,
    PTR_ANIM_null51,
    PTR_ANIM_fire_jump_to_side_left,
    PTR_ANIM_fire_jump_to_side_right,
    PTR_ANIM_hit_butt_long,
    PTR_ANIM_hit_butt_short,
    PTR_ANIM_death_head,
    PTR_ANIM_death_left_leg,
    PTR_ANIM_slide_right,
    PTR_ANIM_slide_left,
    PTR_ANIM_jump_backwards,
    PTR_ANIM_extending_left_hand,
    PTR_ANIM_fire_throw_grenade,
    PTR_ANIM_spotting_bond,
    PTR_ANIM_look_around,
    PTR_ANIM_fire_standing_one_handed_weapon,
    PTR_ANIM_fire_standing_draw_one_handed_weapon_fast,
    PTR_ANIM_fire_standing_draw_one_handed_weapon_slow,
    PTR_ANIM_fire_hip_one_handed_weapon_fast,
    PTR_ANIM_fire_hip_one_handed_weapon_slow,
    PTR_ANIM_fire_hip_forward_one_handed_weapon,
    PTR_ANIM_fire_standing_right_one_handed_weapon,
    PTR_ANIM_fire_step_right_one_handed_weapon,
    PTR_ANIM_fire_standing_left_one_handed_weapon_slow,
    PTR_ANIM_fire_standing_left_one_handed_weapon_fast,
    PTR_ANIM_fire_kneel_forward_one_handed_weapon_slow,
    PTR_ANIM_fire_kneel_forward_one_handed_weapon_fast,
    PTR_ANIM_fire_kneel_right_one_handed_weapon_slow,
    PTR_ANIM_fire_kneel_right_one_handed_weapon_fast,
    PTR_ANIM_fire_kneel_left_one_handed_weapon_slow,
    PTR_ANIM_fire_kneel_left_one_handed_weapon_fast,
    PTR_ANIM_fire_kneel_left_one_handed_weapon,
    PTR_ANIM_aim_walking_one_handed_weapon,
    PTR_ANIM_aim_walking_left_one_handed_weapon,
    PTR_ANIM_aim_walking_right_one_handed_weapon,
    PTR_ANIM_aim_running_one_handed_weapon,
    PTR_ANIM_aim_running_right_one_handed_weapon,
    PTR_ANIM_aim_running_left_one_handed_weapon,
    PTR_ANIM_aim_sprinting_one_handed_weapon,
    PTR_ANIM_running_one_handed_weapon,
    PTR_ANIM_sprinting_one_handed_weapon,
    PTR_ANIM_null91,
    PTR_ANIM_null92,
    PTR_ANIM_null93,
    PTR_ANIM_null94,
    PTR_ANIM_null95,
    PTR_ANIM_null96,
    PTR_ANIM_draw_one_handed_weapon_and_look_around,
    PTR_ANIM_draw_one_handed_weapon_and_stand_up,
    PTR_ANIM_aim_one_handed_weapon_left_right,
    PTR_ANIM_cock_one_handed_weapon_and_turn_around,
    PTR_ANIM_holster_one_handed_weapon_and_cross_arms,
    PTR_ANIM_cock_one_handed_weapon_turn_around_and_stand_up,
    PTR_ANIM_draw_one_handed_weapon_and_turn_around,
    PTR_ANIM_step_forward_and_hold_one_handed_weapon,
    PTR_ANIM_holster_one_handed_weapon_and_adjust_suit,
    PTR_ANIM_idle_unarmed,
    PTR_ANIM_walking_unarmed,
    PTR_ANIM_fire_walking_dual_wield,
    PTR_ANIM_fire_walking_dual_wield_hands_crossed,
    PTR_ANIM_fire_running_dual_wield,
    PTR_ANIM_fire_running_dual_wield_hands_crossed,
    PTR_ANIM_fire_sprinting_dual_wield,
    PTR_ANIM_fire_sprinting_dual_wield_hands_crossed,
    PTR_ANIM_walking_female,
    PTR_ANIM_running_female,
    PTR_ANIM_fire_kneel_dual_wield,
    PTR_ANIM_fire_kneel_dual_wield_left,
    PTR_ANIM_fire_kneel_dual_wield_right,
    PTR_ANIM_fire_kneel_dual_wield_hands_crossed,
    PTR_ANIM_fire_kneel_dual_wield_hands_crossed_left,
    PTR_ANIM_fire_kneel_dual_wield_hands_crossed_right,
    PTR_ANIM_fire_standing_dual_wield,
    PTR_ANIM_fire_standing_dual_wield_left,
    PTR_ANIM_fire_standing_dual_wield_right,
    PTR_ANIM_fire_standing_dual_wield_hands_crossed_left,
    PTR_ANIM_fire_standing_dual_wield_hands_crossed_right,
    PTR_ANIM_fire_standing_aiming_down_sights,
    PTR_ANIM_fire_kneel_aiming_down_sights,
    PTR_ANIM_hit_taser,
    PTR_ANIM_death_explosion_forward,
    PTR_ANIM_death_explosion_left1,
    PTR_ANIM_death_explosion_back_left,
    PTR_ANIM_death_explosion_back1,
    PTR_ANIM_death_explosion_right,
    PTR_ANIM_death_explosion_forward_right1,
    PTR_ANIM_death_explosion_back2,
    PTR_ANIM_death_explosion_forward_roll,
    PTR_ANIM_death_explosion_forward_face_down,
    PTR_ANIM_death_explosion_left2,
    PTR_ANIM_death_explosion_forward_right2,
    PTR_ANIM_death_explosion_forward_right2_alt,
    PTR_ANIM_death_explosion_forward_right3,
    PTR_ANIM_null143,
    PTR_ANIM_null144,
    PTR_ANIM_null145,
    PTR_ANIM_null146,
    PTR_ANIM_running_hands_up,
    PTR_ANIM_sprinting_hands_up,
    PTR_ANIM_aim_and_blow_one_handed_weapon,
    PTR_ANIM_aim_one_handed_weapon_left,
    PTR_ANIM_aim_one_handed_weapon_right,
    PTR_ANIM_conversation,
    PTR_ANIM_drop_weapon_and_show_fight_stance,
    PTR_ANIM_yawning,
    PTR_ANIM_swatting_flies,
    PTR_ANIM_scratching_leg,
    PTR_ANIM_scratching_butt,
    PTR_ANIM_adjusting_crotch,
    PTR_ANIM_sneeze,
    PTR_ANIM_conversation_cleaned,
    PTR_ANIM_conversation_listener,
    PTR_ANIM_startled_and_looking_around,
    PTR_ANIM_laughing_in_disbelief,
    PTR_ANIM_surrendering_unarmed,
    PTR_ANIM_coughing_standing,
    PTR_ANIM_coughing_kneel1,
    PTR_ANIM_coughing_kneel2,
    PTR_ANIM_standing_up,
    PTR_ANIM_null169,
    PTR_ANIM_dancing,
    PTR_ANIM_dancing_one_handed_weapon,
    PTR_ANIM_keyboard_right_hand1,
    PTR_ANIM_keyboard_right_hand2,
    PTR_ANIM_keyboard_left_hand,
    PTR_ANIM_keyboard_right_hand_tapping,
    PTR_ANIM_bond_eye_fire_alt,
    PTR_ANIM_dam_jump,
    PTR_ANIM_surface_vent_jump,
    PTR_ANIM_cradle_jump,
    PTR_ANIM_cradle_fall,
    PTR_ANIM_credits_bond_kissing,
    PTR_ANIM_credits_natalya_kissing,
    0
};

s32 animation_table_ptrs2[] = {
    PTR_ANIM_helicopter_cradle,
    PTR_ANIM_plane_runway,
    PTR_ANIM_helicopter_takeoff,
    0
};


#ifdef NONMATCHING
void expand_ani_table_entries(void) {

}
#else
GLOBAL_ASM(
.text
glabel expand_ani_table_entries
/* 035530 7F000A00 8C830000 */  lw    $v1, ($a0)
/* 035534 7F000A04 3C068007 */  lui   $a2, %hi(ptr_animation_table)
/* 035538 7F000A08 00801025 */  move  $v0, $a0
/* 03553C 7F000A0C 10600017 */  beqz  $v1, .L7F000A6C
/* 035540 7F000A10 24C69538 */   addiu $a2, %lo(ptr_animation_table) # addiu $a2, $a2, -0x6ac8
/* 035544 7F000A14 8C830000 */  lw    $v1, ($a0)
/* 035548 7F000A18 24050001 */  li    $a1, 1
.L7F000A1C:
/* 03554C 7F000A1C 50A3000E */  beql  $a1, $v1, .L7F000A58
/* 035550 7F000A20 8C430004 */   lw    $v1, 4($v0)
/* 035554 7F000A24 8CCE0000 */  lw    $t6, ($a2)
/* 035558 7F000A28 006E7821 */  addu  $t7, $v1, $t6
/* 03555C 7F000A2C AC4F0000 */  sw    $t7, ($v0)
/* 035560 7F000A30 8CD90000 */  lw    $t9, ($a2)
/* 035564 7F000A34 8DF80008 */  lw    $t8, 8($t7)
/* 035568 7F000A38 03194021 */  addu  $t0, $t8, $t9
/* 03556C 7F000A3C ADE80008 */  sw    $t0, 8($t7)
/* 035570 7F000A40 8C430000 */  lw    $v1, ($v0)
/* 035574 7F000A44 8CCA0000 */  lw    $t2, ($a2)
/* 035578 7F000A48 8C690010 */  lw    $t1, 0x10($v1)
/* 03557C 7F000A4C 012A5821 */  addu  $t3, $t1, $t2
/* 035580 7F000A50 AC6B0010 */  sw    $t3, 0x10($v1)
/* 035584 7F000A54 8C430004 */  lw    $v1, 4($v0)
.L7F000A58:
/* 035588 7F000A58 24420004 */  addiu $v0, $v0, 4
/* 03558C 7F000A5C 1460FFEF */  bnez  $v1, .L7F000A1C
/* 035590 7F000A60 00000000 */   nop   
/* 035594 7F000A64 00801025 */  move  $v0, $a0
/* 035598 7F000A68 8C830000 */  lw    $v1, ($a0)
.L7F000A6C:
/* 03559C 7F000A6C 1060000D */  beqz  $v1, .L7F000AA4
/* 0355A0 7F000A70 24050001 */   li    $a1, 1
/* 0355A4 7F000A74 3C040012 */  lui   $a0, %hi(_animation_entriesSegmentRomStart) # $a0, 0x12
/* 0355A8 7F000A78 24844AC0 */  addiu $a0, %lo(_animation_entriesSegmentRomStart) # addiu $a0, $a0, 0x4ac0
/* 0355AC 7F000A7C 8C430000 */  lw    $v1, ($v0)
.L7F000A80:
/* 0355B0 7F000A80 50A30005 */  beql  $a1, $v1, .L7F000A98
/* 0355B4 7F000A84 8C430004 */   lw    $v1, 4($v0)
/* 0355B8 7F000A88 8C6C0000 */  lw    $t4, ($v1)
/* 0355BC 7F000A8C 01846821 */  addu  $t5, $t4, $a0
/* 0355C0 7F000A90 AC6D0000 */  sw    $t5, ($v1)
/* 0355C4 7F000A94 8C430004 */  lw    $v1, 4($v0)
.L7F000A98:
/* 0355C8 7F000A98 24420004 */  addiu $v0, $v0, 4
/* 0355CC 7F000A9C 1460FFF8 */  bnez  $v1, .L7F000A80
/* 0355D0 7F000AA0 00000000 */   nop   
.L7F000AA4:
/* 0355D4 7F000AA4 03E00008 */  jr    $ra
/* 0355D8 7F000AA8 00000000 */   nop   
)
#endif

extern u8* _animation_dataSegmentRomStart;
extern u8* _animation_dataSegmentStart;
extern u8* _animation_dataSegmentEnd;
#ifdef NONMATCHING
void alloc_load_expand_ani_table(void) {
    //u32 sp18;
    u32 size;
    //void *temp_v0;

    osCreateMesgQueue(&animMsgQ, &animMesg, 8);
    sub_GAME_7F0009E0(&D_80029D60, &animMsgQ, &dword_CODE_bss_80069458);
    size = ((u32)_animation_dataSegmentEnd - (u32)_animation_dataSegmentStart);
    //sp18 = size;
    //temp_v0 = mempAllocBytesInBank(size, 6U);
    ptr_animation_table =  mempAllocBytesInBank(size, 6U);
    romCopy(ptr_animation_table, &_animation_dataSegmentRomStart, size);
    expand_ani_table_entries(&animation_table_ptrs1);
    expand_ani_table_entries(&animation_table_ptrs2);
}
#else
GLOBAL_ASM(
.text
glabel alloc_load_expand_ani_table
/* 0355DC 7F000AAC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0355E0 7F000AB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0355E4 7F000AB4 3C048007 */  lui   $a0, %hi(animMsgQ)
/* 0355E8 7F000AB8 3C058007 */  lui   $a1, %hi(animMesg)
/* 0355EC 7F000ABC 24A59518 */  addiu $a1, %lo(animMesg) # addiu $a1, $a1, -0x6ae8
/* 0355F0 7F000AC0 24849440 */  addiu $a0, %lo(animMsgQ) # addiu $a0, $a0, -0x6bc0
/* 0355F4 7F000AC4 0C0035B4 */  jal   osCreateMesgQueue
/* 0355F8 7F000AC8 24060008 */   li    $a2, 8
/* 0355FC 7F000ACC 3C048003 */  lui   $a0, %hi(D_80029D60)
/* 035600 7F000AD0 3C058007 */  lui   $a1, %hi(animMsgQ)
/* 035604 7F000AD4 3C068007 */  lui   $a2, %hi(dword_CODE_bss_80069458)
/* 035608 7F000AD8 24C69458 */  addiu $a2, %lo(dword_CODE_bss_80069458) # addiu $a2, $a2, -0x6ba8
/* 03560C 7F000ADC 24A59440 */  addiu $a1, %lo(animMsgQ) # addiu $a1, $a1, -0x6bc0
/* 035610 7F000AE0 0FC00278 */  jal   sub_GAME_7F0009E0
/* 035614 7F000AE4 24849D60 */   addiu $a0, %lo(D_80029D60) # addiu $a0, $a0, -0x62a0
/* 035618 7F000AE8 3C0E0001 */  lui   $t6, %hi(0x0000E7E0) # $t6, 1
/* 03561C 7F000AEC 3C0F0000 */  lui   $t7, 0
/* 035620 7F000AF0 25EF0000 */  addiu $t7, $t7, 0
/* 035624 7F000AF4 25CEE7E0 */  addiu $t6, %lo(0x0000E7E0) # addiu $t6, $t6, -0x1820
/* 035628 7F000AF8 01CF3023 */  subu  $a2, $t6, $t7
/* 03562C 7F000AFC 00C02025 */  move  $a0, $a2
/* 035630 7F000B00 AFA60018 */  sw    $a2, 0x18($sp)
/* 035634 7F000B04 0C0025C8 */  jal   mempAllocBytesInBank
/* 035638 7F000B08 24050006 */   li    $a1, 6
/* 03563C 7F000B0C 3C038007 */  lui   $v1, %hi(ptr_animation_table)
/* 035640 7F000B10 24639538 */  addiu $v1, %lo(ptr_animation_table) # addiu $v1, $v1, -0x6ac8
/* 035644 7F000B14 3C050029 */  lui   $a1, %hi(_animation_dataSegmentRomStart) # $a1, 0x29
/* 035648 7F000B18 AC620000 */  sw    $v0, ($v1)
/* 03564C 7F000B1C 8FA60018 */  lw    $a2, 0x18($sp)
/* 035650 7F000B20 24A5E980 */  addiu $a1, %lo(_animation_dataSegmentRomStart) # addiu $a1, $a1, -0x1680
/* 035654 7F000B24 0C001707 */  jal   romCopy
/* 035658 7F000B28 00402025 */   move  $a0, $v0
/* 03565C 7F000B2C 3C048003 */  lui   $a0, %hi(animation_table_ptrs1)
/* 035660 7F000B30 0FC00280 */  jal   expand_ani_table_entries
/* 035664 7F000B34 24849D6C */   addiu $a0, %lo(animation_table_ptrs1) # addiu $a0, $a0, -0x6294
/* 035668 7F000B38 3C048003 */  lui   $a0, %hi(animation_table_ptrs2)
/* 03566C 7F000B3C 0FC00280 */  jal   expand_ani_table_entries
/* 035670 7F000B40 2484A04C */   addiu $a0, %lo(animation_table_ptrs2) # addiu $a0, $a0, -0x5fb4
/* 035674 7F000B44 8FBF0014 */  lw    $ra, 0x14($sp)
/* 035678 7F000B48 27BD0020 */  addiu $sp, $sp, 0x20
/* 03567C 7F000B4C 03E00008 */  jr    $ra
/* 035680 7F000B50 00000000 */   nop   
)
#endif

