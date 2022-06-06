
#include <stdio.h>

#define CharArrayTo16(val, index) (val[index + 1] | val[index] << 8)
#define CharArrayTo24(val, index) (val[index + 1] << 8 | val[index + 2] | val[index] << 16)
#define CharArrayTo32(val, index) (val[index + 1] << 16 | val[index + 2] << 8 | val[index + 3] | val[index] << 24)

#define isNotBoundPad(pad)  pad < 10000
#define getBoundPadNum(pad) pad - 10000
#define setBoundPadNum(pad) pad + 10000

#define M_TAU_F            6.2831855f
#define ByteToRadian(Byte) ((Byte * M_TAU_F) * (1.0f / 256.0f))
#define RadToDeg(RAD)      (float)((RAD) / M_TAU_F * 360.0f)

#define TARGET_BOND         0x0001 /* Set target to bond (ignores target argument)*/
#define TARGET_FRONT_OF_CHR 0x0002 /* Set target to front of chr*/
#define TARGET_CHR          0x0004 /* Set target type to chr_num*/
#define TARGET_PAD          0x0008 /* Set target type to pad*/
#define TARGET_COMPASS      0x0010 /* Set target to compass direction (hex) N: 0000 E: C000 S: 8000: W: 4000*/
#define TARGET_AIM_ONLY     0x0020 /* Aim at target instead of firing*/
#define TARGET_DONTTURN     0x0040 /* Limits target to 180 degrees in front of guard (cannot be used with TARGET_BOND flag)*/

// command 68 - door states
char *DOORSTATE_ToString[] = {
    " DOOR_STATE_CLOSED",  /* Closed*/
    " DOOR_STATE_OPEN",    /* Opened*/
    " DOOR_STATE_CLOSING", /* Closing*/
    " DOOR_STATE_OPENING" /* Opening*/};

// command D7 - hud flags
#define HUD_HIDE_ALL           0x00 /* Hide all*/
#define HUD_SHOW_TEXT_TOP      0x01 /* Don't hide top text*/
#define HUD_SHOW_TEXT_BOTTOM   0x02 /* Don't hide bottom text*/
#define HUD_SHOW_HUD_COUNTDOWN 0x04 /* Don't hide hud countdown*/

/* special chr num IDs */
#define CHR_BOND_CINEMA -8 /* only works when bond has a third person model (intro/exit cutscene) */
#define CHR_CLONE       -7
#define CHR_SEE_SHOT    -6 /* stored as chr->chrseeshot */
#define CHR_SEE_DIE     -5 /* stored as chr->chrseedie */
#define CHR_PRESET      -4 /* stored as chr->chrpreset1 */
#define CHR_SELF        -3

/* private chr ID, cannot be accessed with ai commands */
#define CHR_OBJECTIVE        -2    /* objective ai list chr ID */
#define CHR_FREE             -1    /* chr IDs when free'd (killed or removed from level) */
#define CHR_SPAWN_NUM_START  5000  /* default chr num for spawned guards with ai command BD/BE */
#define CHR_CLONED_NUM_START 10000 /* default chr num for cloed guards with ai command C1 */
/* Special ID for selecting PadPreset in AI list */
#define PAD_PRESET1          9000 /* stored as chr->padpreset1 */

#define isGlobalAIListID(ID)  ((ID) < 18)
#define isBGAIListID(ID)      ((ID) > 4097)
#define isChrAIListID(ID)     (!isGlobalAIListID(ID) && !isBGAIListID(ID))
#define setGlobalAIListID(ID) ((ID) + 0)
#define setChrAIListID(ID)    ((ID) + 1025)
#define setBGAIListID(ID)     ((ID) + 4097)
#define getGlobalAIListID(ID) ((ID)-0)
#define getChrAIListID(ID)    ((ID)-1025)
#define getBGAIListID(ID)     ((ID)-4097)

char *ANIMATIONS_ToString[] = {
    "ANIM_idle",
    "ANIM_fire_standing",
    "ANIM_fire_standing_fast",
    "ANIM_fire_hip",
    "ANIM_fire_shoulder_left",
    "ANIM_fire_turn_right1",
    "ANIM_fire_turn_right2",
    "ANIM_fire_kneel_right_leg",
    "ANIM_fire_kneel_left_leg",
    "ANIM_fire_kneel_left",
    "ANIM_fire_kneel_right",
    "ANIM_fire_roll_left",
    "ANIM_fire_roll_right1",
    "ANIM_fire_roll_left_fast",
    "ANIM_hit_left_shoulder",
    "ANIM_hit_right_shoulder",
    "ANIM_hit_left_arm",
    "ANIM_hit_right_arm",
    "ANIM_hit_left_hand",
    "ANIM_hit_right_hand",
    "ANIM_hit_left_leg",
    "ANIM_hit_right_leg",
    "ANIM_death_genitalia", /* Thank you Mr. Botwood", here is your award */
    "ANIM_hit_neck",
    "ANIM_death_neck",
    "ANIM_death_stagger_back_to_wall",
    "ANIM_death_forward_face_down",
    "ANIM_death_forward_spin_face_up",
    "ANIM_death_backward_fall_face_up1",
    "ANIM_death_backward_spin_face_down_right",
    "ANIM_death_backward_spin_face_up_right",
    "ANIM_death_backward_spin_face_down_left",
    "ANIM_death_backward_spin_face_up_left",
    "ANIM_death_forward_face_down_hard",
    "ANIM_death_forward_face_down_soft",
    "ANIM_death_fetal_position_right",
    "ANIM_death_fetal_position_left",
    "ANIM_death_backward_fall_face_up2",
    "ANIM_side_step_left",
    "ANIM_fire_roll_right2",
    "ANIM_walking",
    "ANIM_sprinting",
    "ANIM_running",
    "ANIM_bond_eye_walk",
    "ANIM_bond_eye_fire",
    "ANIM_bond_watch",
    "ANIM_surrendering_armed",
    "ANIM_surrendering_armed_drop_weapon",
    "ANIM_fire_walking",
    "ANIM_fire_running",
    "ANIM_null50", /* invalid slot */
    "ANIM_null51", /* invalid slot */
    "ANIM_fire_jump_to_side_left",
    "ANIM_fire_jump_to_side_right",
    "ANIM_hit_butt_long",
    "ANIM_hit_butt_short",
    "ANIM_death_head",
    "ANIM_death_left_leg",
    "ANIM_slide_right",
    "ANIM_slide_left",
    "ANIM_jump_backwards",
    "ANIM_extending_left_hand",
    "ANIM_fire_throw_grenade",
    "ANIM_spotting_bond", /* used by chr ai command guard_points_at_bond */
    "ANIM_look_around",   /* used by chr ai command GUARD_ANIM_LOOKS_AROUND_SELF  */
    "ANIM_fire_standing_one_handed_weapon",
    "ANIM_fire_standing_draw_one_handed_weapon_fast",
    "ANIM_fire_standing_draw_one_handed_weapon_slow",
    "ANIM_fire_hip_one_handed_weapon_fast",
    "ANIM_fire_hip_one_handed_weapon_slow",
    "ANIM_fire_hip_forward_one_handed_weapon",
    "ANIM_fire_standing_right_one_handed_weapon",
    "ANIM_fire_step_right_one_handed_weapon",
    "ANIM_fire_standing_left_one_handed_weapon_slow",
    "ANIM_fire_standing_left_one_handed_weapon_fast",
    "ANIM_fire_kneel_forward_one_handed_weapon_slow",
    "ANIM_fire_kneel_forward_one_handed_weapon_fast",
    "ANIM_fire_kneel_right_one_handed_weapon_slow",
    "ANIM_fire_kneel_right_one_handed_weapon_fast",
    "ANIM_fire_kneel_left_one_handed_weapon_slow",
    "ANIM_fire_kneel_left_one_handed_weapon_fast",
    "ANIM_fire_kneel_left_one_handed_weapon",
    "ANIM_aim_walking_one_handed_weapon",
    "ANIM_aim_walking_left_one_handed_weapon",
    "ANIM_aim_walking_right_one_handed_weapon",
    "ANIM_aim_running_one_handed_weapon",
    "ANIM_aim_running_right_one_handed_weapon",
    "ANIM_aim_running_left_one_handed_weapon",
    "ANIM_aim_sprinting_one_handed_weapon",
    "ANIM_running_one_handed_weapon",
    "ANIM_sprinting_one_handed_weapon",
    "ANIM_null91", /* invalid slot */
    "ANIM_null92", /* invalid slot */
    "ANIM_null93", /* invalid slot */
    "ANIM_null94", /* invalid slot */
    "ANIM_null95", /* invalid slot */
    "ANIM_null96", /* invalid slot */
    "ANIM_draw_one_handed_weapon_and_look_around",
    "ANIM_draw_one_handed_weapon_and_stand_up",
    "ANIM_aim_one_handed_weapon_left_right",
    "ANIM_cock_one_handed_weapon_and_turn_around",
    "ANIM_holster_one_handed_weapon_and_cross_arms",
    "ANIM_cock_one_handed_weapon_turn_around_and_stand_up",
    "ANIM_draw_one_handed_weapon_and_turn_around",
    "ANIM_step_foward_and_hold_one_handed_weapon",
    "ANIM_holster_one_handed_weapon_and_adjust_suit",
    "ANIM_idle_unarmed",
    "ANIM_walking_unarmed",
    "ANIM_fire_walking_dual_wield",
    "ANIM_fire_walking_dual_wield_hands_crossed",
    "ANIM_fire_running_dual_wield",
    "ANIM_fire_running_dual_wield_hands_crossed",
    "ANIM_fire_sprinting_dual_wield",
    "ANIM_fire_sprinting_dual_wield_hands_crossed",
    "ANIM_walking_female",
    "ANIM_running_female",
    "ANIM_fire_kneel_dual_wield",
    "ANIM_fire_kneel_dual_wield_left",
    "ANIM_fire_kneel_dual_wield_right",
    "ANIM_fire_kneel_dual_wield_hands_crossed",
    "ANIM_fire_kneel_dual_wield_hands_crossed_left",
    "ANIM_fire_kneel_dual_wield_hands_crossed_right",
    "ANIM_fire_standing_dual_wield",
    "ANIM_fire_standing_dual_wield_left",
    "ANIM_fire_standing_dual_wield_right",
    "ANIM_fire_standing_dual_wield_hands_crossed_left",
    "ANIM_fire_standing_dual_wield_hands_crossed_right",
    "ANIM_fire_standing_aiming_down_sights",
    "ANIM_fire_kneel_aiming_down_sights",
    "ANIM_hit_taser", /* unused tazer boy hit reaction */
    "ANIM_death_explosion_forward",
    "ANIM_death_explosion_left1",
    "ANIM_death_explosion_back_left",
    "ANIM_death_explosion_back1",
    "ANIM_death_explosion_right",
    "ANIM_death_explosion_forward_right1",
    "ANIM_death_explosion_back2",
    "ANIM_death_explosion_forward_roll",
    "ANIM_death_explosion_forward_face_down",
    "ANIM_death_explosion_left2",
    "ANIM_death_explosion_forward_right2",
    "ANIM_death_explosion_forward_right2_alt", /* copy of right2 with different fall */
    "ANIM_death_explosion_forward_right3",
    "ANIM_null143", /* invalid slot */
    "ANIM_null144", /* invalid slot */
    "ANIM_null145", /* invalid slot */
    "ANIM_null146", /* invalid slot */
    "ANIM_running_hands_up",
    "ANIM_sprinting_hands_up",
    "ANIM_aim_and_blow_one_handed_weapon",
    "ANIM_aim_one_handed_weapon_left",
    "ANIM_aim_one_handed_weapon_right",
    "ANIM_conversation",
    "ANIM_drop_weapon_and_show_fight_stance", /* orthodox stance woo */
    "ANIM_yawning",
    "ANIM_swatting_flies",
    "ANIM_scratching_leg",
    "ANIM_scratching_butt",
    "ANIM_adjusting_crotch",
    "ANIM_sneeze",
    "ANIM_conversation_cleaned", /* cleaned up copy of "ANIM_conversation (compare left wrist) */
    "ANIM_conversation_listener",
    "ANIM_startled_and_looking_around",
    "ANIM_laughing_in_disbelief",
    "ANIM_surrendering_unarmed",
    "ANIM_coughing_standing",
    "ANIM_coughing_kneel1",
    "ANIM_coughing_kneel2",
    "ANIM_standing_up",
    "ANIM_null169", /* invalid slot */
    "ANIM_dancing",
    "ANIM_dancing_one_handed_weapon",
    "ANIM_keyboard_right_hand1",
    "ANIM_keyboard_right_hand2",
    "ANIM_keyboard_left_hand",
    "ANIM_keyboard_right_hand_tapping",
    "ANIM_bond_eye_fire_alt", /* unused */
    "ANIM_dam_jump",
    "ANIM_surface_vent_jump",
    "ANIM_cradle_jump",
    "ANIM_cradle_fall",
    "ANIM_credits_bond_kissing",
    "ANIM_credits_natalya_kissing"};

char *AIRCRAFT_ANIMATION_ToString[] = {
    "AIRCRAFT_ANIMATION_helicopter_cradle",
    "AIRCRAFT_ANIMATION_plane_runway",
    "AIRCRAFT_ANIMATION_helicopter_takeoff"};

// Add 1 to ID for correct string
char *DIFFICULTY_ToString[] = {
    "DIFFICULTY_MULTI", //-1
    "DIFFICULTY_AGENT",
    "DIFFICULTY_SECRET",
    "DIFFICULTY_00",
    "DIFFICULTY_007",
};

char *ITEM_IDS_ToString[] = {
    "ITEM_UNARMED",
    "ITEM_FIST",
    "ITEM_KNIFE",
    "ITEM_THROWKNIFE",
    "ITEM_WPPK",
    "ITEM_WPPKSIL",
    "ITEM_TT33",
    "ITEM_SKORPION",
    "ITEM_AK47",
    "ITEM_UZI",
    "ITEM_MP5K",
    "ITEM_MP5KSIL",
    "ITEM_SPECTRE",
    "ITEM_M16",
    "ITEM_FNP90",
    "ITEM_SHOTGUN",
    "ITEM_AUTOSHOT",
    "ITEM_SNIPERRIFLE",
    "ITEM_RUGER",
    "ITEM_GOLDENGUN",
    "ITEM_SILVERWPPK",
    "ITEM_GOLDWPPK",
    "ITEM_LASER",
    "ITEM_WATCHLASER",
    "ITEM_GRENADELAUNCH",
    "ITEM_ROCKETLAUNCH",
    "ITEM_GRENADE",
    "ITEM_TIMEDMINE",
    "ITEM_PROXIMITYMINE",
    "ITEM_REMOTEMINE",
    "ITEM_TRIGGER",
    "ITEM_TASER",
    "ITEM_TANKSHELLS",
    "ITEM_BOMBCASE",
    "ITEM_PLASTIQUE",
    "ITEM_FLAREPISTOL",
    "ITEM_PITONGUN",
    "ITEM_BUNGEE",
    "ITEM_DOORDECODER",
    "ITEM_BOMBDEFUSER",
    "ITEM_CAMERA",
    "ITEM_LOCKEXPLODER",
    "ITEM_DOOREXPLODER",
    "ITEM_BRIEFCASE",
    "ITEM_WEAPONCASE",
    "ITEM_SAFECRACKERCASE",
    "ITEM_KEYANALYSERCASE",
    "ITEM_BUG",
    "ITEM_MICROCAMERA",
    "ITEM_BUGDETECTOR",
    "ITEM_EXPLOSIVEFLOPPY",
    "ITEM_POLARIZEDGLASSES",
    "ITEM_DARKGLASSES",
    "ITEM_CREDITCARD",
    "ITEM_GASKEYRING",
    "ITEM_DATATHIEF",
    "ITEM_WATCHIDENTIFIER",
    "ITEM_WATCHCOMMUNICATOR",
    "ITEM_WATCHGEIGERCOUNTER",
    "ITEM_WATCHMAGNETREPEL",
    "ITEM_WATCHMAGNETATTRACT",
    "ITEM_GOLDENEYEKEY",
    "ITEM_BLACKBOX",
    "ITEM_CIRCUITBOARD",
    "ITEM_CLIPBOARD",
    "ITEM_STAFFLIST",
    "ITEM_DOSSIERRED",
    "ITEM_PLANS",
    "ITEM_SPYFILE",
    "ITEM_BLUEPRINTS",
    "ITEM_MAP",
    "ITEM_AUDIOTAPE",
    "ITEM_VIDEOTAPE",
    "ITEM_DATTAPE",
    "ITEM_SPOOLTAPE",
    "ITEM_MICROFILM",
    "ITEM_MICROCODE",
    "ITEM_LECTRE",
    "ITEM_MONEY",
    "ITEM_GOLDBAR",
    "ITEM_HEROIN",
    "ITEM_KEYCARD",
    "ITEM_KEYYALE",
    "ITEM_KEYBOLT",
    "ITEM_SUIT_LF_HAND",
    "ITEM_JOYPAD",
    "ITEM_NULL86",
    "ITEM_NULL87",
    "ITEM_TOKEN",
    "ITEM_IDS_MAX"};

char *PROPDEF_TYPE_ToString[] = {
        "PROPDEF_NOTHING",
        "PROPDEF_DOOR",
        "PROPDEF_DOOR_SCALE",
        "PROPDEF_PROP",
        "PROPDEF_KEY",
        "PROPDEF_ALARM",
        "PROPDEF_CCTV",
        "PROPDEF_MAGAZINE",
        "PROPDEF_COLLECTABLE",
        "PROPDEF_GUARD",
        "PROPDEF_MONITOR",
        "PROPDEF_MULTI_MONITOR",
        "PROPDEF_RACK",
        "PROPDEF_AUTOGUN",
        "PROPDEF_LINK",
        "PROPDEF_UNK15",
        "PROPDEF_UNK16",
        "PROPDEF_HAT",
        "PROPDEF_GUARD_ATTRIBUTE",
        "PROPDEF_SWITCH",
        "PROPDEF_AMMO",
        "PROPDEF_ARMOUR",
        "PROPDEF_TAG",
        "PROPDEF_OBJECTIVE_START",
        "PROPDEF_OBJECTIVE_END",
        "PROPDEF_OBJECTIVE_DESTROY_OBJECT",
        "PROPDEF_OBJECTIVE_COMPLETE_CONDITION",
        "PROPDEF_OBJECTIVE_FAIL_CONDITION",
        "PROPDEF_OBJECTIVE_COLLECT_OBJECT",
        "PROPDEF_OBJECTIVE_DEPOSIT_OBJECT",
        "PROPDEF_OBJECTIVE_PHOTOGRAPH",
        "PROPDEF_OBJECTIVE_NULL",
        "PROPDEF_OBJECTIVE_ENTER_ROOM",
        "PROPDEF_OBJECTIVE_DEPOSIT_OBJECT_IN_ROOM",
        "PROPDEF_OBJECTIVE_COPY_ITEM",
        "PROPDEF_WATCH_MENU_OBJECTIVE_TEXT",
        "PROPDEF_GAS_RELEASING",
        "PROPDEF_RENAME",
        "PROPDEF_LOCK_DOOR",
        "PROPDEF_VEHICHLE",
        "PROPDEF_AIRCRAFT",
        "PROPDEF_UNK41",
        "PROPDEF_GLASS",
        "PROPDEF_SAFE",
        "PROPDEF_SAFE_ITEM",
        "PROPDEF_TANK",
        "PROPDEF_CAMERAPOS", // canonical name
        "PROPDEF_TINTED_GLASS",
        "PROPDEF_END",
};

char *PROP_ToString[] = {
    "PROP_ALARM1",              /* Beta Alarm / Default Multi Weapon                                  */
    "PROP_ALARM2",              /* Alarm                                                              */
    "PROP_EXPLOSIONBIT",        /* White Pyramid (Explosion Bit)                                      */
    "PROP_AMMO_CRATE1",         /* Ammo Crate (Brown w/ Edge Brace", 6x240 Black)                      */
    "PROP_AMMO_CRATE2",         /* Ammo Crate (Brown w/ Center Brace", 12x8 Black)                     */
    "PROP_AMMO_CRATE3",         /* Ammo Crate (Green w/ Center Brace", 12x8 Brown)                     */
    "PROP_AMMO_CRATE4",         /* Ammo Crate (Green w/ Edge Brace", 6x8 White)                        */
    "PROP_AMMO_CRATE5",         /* Ammo Crate (Green w/ Double Brace", 24x60 Black)                    */
    "PROP_BIN1",                /* Rusted Trash Bin                                                   */
    "PROP_BLOTTER1",            /* Desk Blotter                                                       */
    "PROP_BOOK1",               /* Red Book                                                           */
    "PROP_BOOKSHELF1",          /* Bookshelf                                                          */
    "PROP_BRIDGE_CONSOLE1A",    /* Bridge Console w/ Monitor", Navigation + Keyboard 1A                */
    "PROP_BRIDGE_CONSOLE1B",    /* Bridge Console w/ Navigation 1B                                    */
    "PROP_BRIDGE_CONSOLE2A",    /* Bridge Console w/ Navigation", Monitor + Keyboard 2A                */
    "PROP_BRIDGE_CONSOLE2B",    /* Bridge Console w/ Various Controls 2B                              */
    "PROP_BRIDGE_CONSOLE3A",    /* Bridge Console w/ Monitor", Navigation + Keyboard 3A                */
    "PROP_BRIDGE_CONSOLE3B",    /* Bridge Console w/ Monitor", Keyboard + Navigation 3B                */
    "PROP_CARD_BOX1",           /* Cardboard Box", Kapto|Enb                                           */
    "PROP_CARD_BOX2",           /* Cardboard Box", Red Arrow", Bahko                                    */
    "PROP_CARD_BOX3",           /* Cardboard Box", Scrawled Text", Bahah                                */
    "PROP_CARD_BOX4_LG",        /* Cardboard Box", Three Seams                                         */
    "PROP_CARD_BOX5_LG",        /* Cardboard Box", Two Seams", Bahah                                    */
    "PROP_CARD_BOX6_LG",        /* Cardboard Box", Bahko                                               */
    "PROP_CCTV",                /* Surveillance Camera                                                */
    "PROP_CONSOLE1",            /* Double Screen Consoles w/ Keyboards                                */
    "PROP_CONSOLE2",            /* Double Screen Consoles w/ Left Keyboard                            */
    "PROP_CONSOLE3",            /* Double Screen Consoles w/ Right Keyboard                           */
    "PROP_CONSOLE_SEVA",        /* Console w/ Keyboard                                                */
    "PROP_CONSOLE_SEVB",        /* Console w/ Monitor + Keyboard                                      */
    "PROP_CONSOLE_SEVC",        /* Console w/ Switches                                                */
    "PROP_CONSOLE_SEVD",        /* Console w/ Five Gauges                                             */
    "PROP_CONSOLE_SEV2A",       /* Console w/ Four Faders                                             */
    "PROP_CONSOLE_SEV2B",       /* Console w/ Monitor", Keyboard + Switches                            */
    "PROP_CONSOLE_SEV2C",       /* Console w/ Three Gauges                                            */
    "PROP_CONSOLE_SEV2D",       /* Console w/ Pressure Gauge                                          */
    "PROP_CONSOLE_SEV_GEA",     /* Console w/ GoldenEye Key Slot                                      */
    "PROP_CONSOLE_SEV_GEB",     /* Console w/ Faders + Pressure Gauge                                 */
    "PROP_DESK1",               /* Desk w/ Kickplate                                                  */
    "PROP_DESK2",               /* Desk                                                               */
    "PROP_DESK_LAMP2",          /* Desk Lamp                                                          */
    "PROP_DISC_READER",         /* External Hard Drive                                                */
    "PROP_DISK_DRIVE1",         /* Floppy Disc Drive                                                  */
    "PROP_FILING_CABINET1",     /* Filing Cabinet                                                     */
    "PROP_JERRY_CAN1",          /* Jerrycan (Fuel Container)                                          */
    "PROP_KEYBOARD1",           /* Computer Keyboard                                                  */
    "PROP_KIT_UNITS1",          /* Kitchen Cabinets                                                   */
    "PROP_LETTER_TRAY1",        /* Letter Tray                                                        */
    "PROP_MAINFRAME1",          /* Mainframe", Basic                                                   */
    "PROP_MAINFRAME2",          /* Mainframe", Advanced                                                */
    "PROP_METAL_CHAIR1",        /* Chair (Metal)                                                      */
    "PROP_METAL_CRATE1",        /* Metal Crate", 6 Top Corner                                          */
    "PROP_METAL_CRATE2",        /* Metal Crate", 6 Bottom Corner                                       */
    "PROP_METAL_CRATE3",        /* Metal Crate", Toxic Materials                                       */
    "PROP_METAL_CRATE4",        /* Metal Crate", Double Stripe - Class D1 Hazard                       */
    "PROP_MISSILE_RACK",        /* Naval Harpoon Missile in Containment Rack                          */
    "PROP_MISSILE_RACK2",       /* Naval Harpoon Missiles in Containment Racks x4                     */
    "PROP_OIL_DRUM1",           /* Oil Drum", Single Stripe", Ribbed                                    */
    "PROP_OIL_DRUM2",           /* Oil Drum", Single Stripe", Ribbed - Class D1 Hazard                  */
    "PROP_OIL_DRUM3",           /* Oil Drum", Single Stripe", Ribbed - Toxic Materials                  */
    "PROP_OIL_DRUM5",           /* Oil Drum", Double Stripe - Toxic Materials                          */
    "PROP_OIL_DRUM6",           /* Oil Drum - Toxic Materials                                         */
    "PROP_OIL_DRUM7",           /* Oil Drum", Double Dashes - Class D1 Hazard                          */
    "PROP_PADLOCK",             /* Padlock                                                            */
    "PROP_PHONE1",              /* Telephone                                                          */
    "PROP_RADIO_UNIT1",         /* Radio Tuner w/ 1 Knob + 2 Gauges                                   */
    "PROP_RADIO_UNIT2",         /* Radio Tuner w/ 1 Knob + 5 Gauges                                   */
    "PROP_RADIO_UNIT3",         /* Radio Tuner w/ 3 Knobs + 5 Gauges                                  */
    "PROP_RADIO_UNIT4",         /* Radio Tuner w/ 3 Knobs + 2 Gauges                                  */
    "PROP_SAT1_REFLECT",        /* GoldenEye Satellite                                                */
    "PROP_SATDISH",             /* Satellite Dish (Arkangelsk)                                        */
    "PROP_SATBOX",              /* Uplink Box                                                         */
    "PROP_STOOL1",              /* Wooden Stool                                                       */
    "PROP_SWIVEL_CHAIR1",       /* Swivel Chair                                                       */
    "PROP_TORPEDO_RACK",        /* Naval Torpedo Rack x3                                              */
    "PROP_TV1",                 /* Television Monitor                                                 */
    "PROP_TV_HOLDER",           /* Hanging Monitor Rack                                               */
    "PROP_TVSCREEN",            /* Wall Monitor Screen                                                */
    "PROP_TV4SCREEN",           /* Wall Monitor Screens", 4-in-1                                       */
    "PROP_WOOD_LG_CRATE1",      /* Wooden Crate w/ #4 Label", Bahah                                    */
    "PROP_WOOD_LG_CRATE2",      /* Wooden Crate", Darker Shading", Kapto|Enb                            */
    "PROP_WOOD_MD_CRATE3",      /* Wooden Crates x8", Bahko                                            */
    "PROP_WOOD_SM_CRATE4",      /* Wooden Crate w/ #2 Label", Bahko                                    */
    "PROP_WOOD_SM_CRATE5",      /* Wooden Crate w/ #4 Label", Darker Shading", Bahah                    */
    "PROP_WOOD_SM_CRATE6",      /* Wooden Crate w/ UP Arrow", Kapto|Enb                                */
    "PROP_WOODEN_TABLE1",       /* Wooden Table                                                       */
    "PROP_SWIPE_CARD2",         /* Keycard                                                            */
    "PROP_BORG_CRATE",          /* Blue and Gold Printed Circuit Cube (Borg Crate)                    */
    "PROP_BOXES4X4",            /* Metal Crate Stack", 4x4                                             */
    "PROP_BOXES3X4",            /* Metal Crate Stack", 3x4                                             */
    "PROP_BOXES2X4",            /* Metal Crate Stack", 2x4                                             */
    "PROP_SEC_PANEL",           /* Security Card Panel                                                */
    "PROP_ICBM_NOSE",           /* Silo Missile (ICBM)", Nose Cone Only                                */
    "PROP_ICBM",                /* Silo Missile (ICBM)                                                */
    "PROP_TUNING_CONSOLE1",     /* Dual Consoles on Castors                                           */
    "PROP_DESK_ARECIBO1",       /* Computer Work Desk                                                 */
    "PROP_LOCKER3",             /* Lockers", Single Venting                                            */
    "PROP_LOCKER4",             /* Lockers", Double Venting                                            */
    "PROP_ROOFGUN",             /* Ceiling Mounted Drone Gun                                          */
    "PROP_DEST_ENGINE",         /* Frigate Engine                                                     */
    "PROP_DEST_EXOCET",         /* Naval MK 29 Missile Launcher (Exocet)                              */
    "PROP_DEST_GUN",            /* Naval 100 mm Gun Turret (TR 100)                                   */
    "PROP_DEST_HARPOON",        /* Naval MK 141 Launch Canisters (Harpoon)                            */
    "PROP_DEST_SEAWOLF",        /* Naval MK 26 Dual Missile Launcher (Seawolf)                        */
    "PROP_WINDOW",              /* Window Glass                                                       */
    "PROP_WINDOW_LIB_LG1",      /* Window Glass", Lattice Frame", 4x10 (single-sided)                   */
    "PROP_WINDOW_LIB_SM1",      /* Window Glass", Lattice Frame", 4x3 (double-sided)                    */
    "PROP_WINDOW_COR11",        /* Window Glass", Lattice Frame", 4x4 (single-sided)                    */
    "PROP_JUNGLE3_TREE",        /* Jungle Large Tree                                                  */
    "PROP_PALM",                /* Jungle Palm Tree                                                   */
    "PROP_PALMTREE",            /* Jungle Palm Tree", Resprouting After Loss of Fronds                 */
    "PROP_PLANT2B",             /* Jungle Plant", Low Shrub                                            */
    "PROP_LABBENCH",            /* Laboratory Table w/ Sink Drains                                    */
    "PROP_GASBARREL",           /* White Bin                                                          */
    "PROP_GASBARRELS",          /* White Bins x4                                                      */
    "PROP_BODYARMOUR",          /* Body Armor                                                         */
    "PROP_BODYARMOURVEST",      /* Body Armor (Vest)                                                  */
    "PROP_GASTANK",             /* Bottling Tank                                                      */
    "PROP_GLASSWARE1",          /* Glass Cup                                                          */
    "PROP_HATCHBOLT",           /* Metallic Securing Strip (Hatch Bolt)                               */
    "PROP_BRAKEUNIT",           /* Train Brake Controller                                             */
    "PROP_AK47MAG",             /* Gun Magazine (KF7 Soviet)                                          */
    "PROP_M16MAG",              /* Gun Magazine (AR33 Assault Rifle)                                  */
    "PROP_MP5KMAG",             /* Gun Magazine (D5K Deutsche)                                        */
    "PROP_SKORPIONMAG",         /* Gun Magazine (Klobb)                                               */
    "PROP_SPECTREMAG",          /* Gun Magazine (Phantom)                                             */
    "PROP_UZIMAG",              /* Gun Magazine (ZMG (9mm))                                           */
    "PROP_SILENCER",            /* Silencer                                                           */
    "PROP_CHREXTINGUISHER",     /* Fire Extinguisher                                                  */
    "PROP_BOXCARTRIDGES",       /* Box of Shells (Shotgun Cartridges)                                 */
    "PROP_FNP90MAG",            /* Gun Magazine (RC-P90)                                              */
    "PROP_GOLDENSHELLS",        /* Box of Shells (Golden Gun Bullets)                                 */
    "PROP_MAGNUMSHELLS",        /* Box of Shells (Magnum Rounds)                                      */
    "PROP_WPPKMAG",             /* Gun Magazine (PP7)                                                 */
    "PROP_TT33MAG",             /* Gun Magazine (DD44 Dostovei)                                       */
    "PROP_SEV_DOOR",            /* Grey Containment Door w/ Caution Stripes and Window                */
    "PROP_SEV_DOOR3",           /* Grey Electronic Door w/ LEFT Arrow                                 */
    "PROP_SEV_DOOR3_WIND",      /* BETA Electronic Door w/ LEFT Arrow and Fake Window                 */
    "PROP_SEV_DOOR4_WIND",      /* Grey Electronic Door w/ LEFT Arrow and Window                      */
    "PROP_SEV_TRISLIDE",        /* Glass Door w/ Stone Frame                                          */
    "PROP_SEV_DOOR_V1",         /* Grey Electronic Door w/ UP Arrow                                   */
    "PROP_STEEL_DOOR1",         /* Silver Corrugated Door w/ Caution Stripes                          */
    "PROP_STEEL_DOOR2",         /* Rusty Door w/ Handle                                               */
    "PROP_STEEL_DOOR3",         /* Double Cross Brace Door                                            */
    "PROP_SILO_LIFT_DOOR",      /* Elevator Door                                                      */
    "PROP_STEEL_DOOR2B",        /* Rusty Door w/o Handle                                              */
    "PROP_DOOR_ROLLER1",        /* Blue Bay Door w/ Caution Stripes                                   */
    "PROP_DOOR_ROLLER2",        /* Blue Bay Door w/ Venting and Caution Stripes                       */
    "PROP_DOOR_ROLLER3",        /* Blue Bay Door w/ Venting and Caution Stripes                       */
    "PROP_DOOR_ROLLER4",        /* Cargo Bay Door w/ UP Arrow and Transportation Stripes              */
    "PROP_DOOR_ST_AREC1",       /* Blue Corrugated Door w/ Transportation Stripes                     */
    "PROP_DOOR_ST_AREC2",       /* Blue Reversed Corrugated Door w/ Transportation Stripes            */
    "PROP_DOOR_DEST1",          /* Grey Frigate Door w/ Indents and Caution Stripes                   */
    "PROP_DOOR_DEST2",          /* Grey Frigate Door w/ Indents", Caution Stripes and KEEP CLEAR Label */
    "PROP_GAS_PLANT_SW_DO1",    /* Grey Swinging Door w/ Blue Stripe                                  */
    "PROP_GAS_PLANT_SW2_DO1",   /* Grey Swinging Door", Darker                                         */
    "PROP_GAS_PLANT_SW3_DO1",   /* Grey Swinging Door", Lighter                                        */
    "PROP_GAS_PLANT_SW4_DO1",   /* Light Wooden Door (Looks Like Sand)                                */
    "PROP_GAS_PLANT_MET1_DO1",  /* Brown Electronic Door                                              */
    "PROP_GAS_PLANT_WC_CUB1",   /* Bathroom Stall Door                                                */
    "PROP_GASPLANT_CLEAR_DOOR", /* Laboratory Glass Door                                              */
    "PROP_TRAIN_DOOR",          /* Dark Wooden Door                                                   */
    "PROP_TRAIN_DOOR2",         /* Dark Wooden Door w/ Window                                         */
    "PROP_TRAIN_DOOR3",         /* Dark Wooden Door w/ Window + Shutter                               */
    "PROP_DOOR_EYELID",         /* Eyelid Door                                                        */
    "PROP_DOOR_IRIS",           /* Iris Door                                                          */
    "PROP_SEVDOORWOOD",         /* Cabin Door                                                         */
    "PROP_SEVDOORWIND",         /* Weathered Swinging Door w/ Window                                  */
    "PROP_SEVDOORNOWIND",       /* Weathered Swinging Door                                            */
    "PROP_SEVDOORMETSLIDE",     /* Brown Corrugated Electronic Door                                   */
    "PROP_CRYPTDOOR1A",         /* Stone Door w/ Prints (Set A)                                       */
    "PROP_CRYPTDOOR1B",         /* Sand Door w/ Damage (Set A)                                        */
    "PROP_CRYPTDOOR2A",         /* Stone Door w/ Prints", Darker (Set B)                               */
    "PROP_CRYPTDOOR2B",         /* Sand Door w/ Damage", Darker (Set B)                                */
    "PROP_CRYPTDOOR3",          /* Egyptian Moving Wall                                               */
    "PROP_CRYPTDOOR4",          /* Brown Sand Door (Temple)                                           */
    "PROP_VERTDOOR",            /* Blast Door (Control)                                               */
    "PROP_HATCHDOOR",           /* Train Floor Hatch                                                  */
    "PROP_DAMGATEDOOR",         /* Security Gate (Dam)                                                */
    "PROP_DAMTUNDOOR",          /* Tunnel Flood Door (Dam)                                            */
    "PROP_DAMCHAINDOOR",        /* Mesh Gate                                                          */
    "PROP_SILOTOPDOOR",         /* Launch Tube Ceiling Shutter (Silo)                                 */
    "PROP_DOORPRISON1",         /* Cell Door                                                          */
    "PROP_DOORSTATGATE",        /* Park Gate                                                          */
    "PROP_CHRKALASH",           /* KF7 Soviet                                                         */
    "PROP_CHRGRENADELAUNCH",    /* Grenade Launcher                                                   */
    "PROP_CHRKNIFE",            /* Hunting Knife                                                      */
    "PROP_CHRLASER",            /* Moonraker Laser                                                    */
    "PROP_CHRM16",              /* AR33 Assault Rifle                                                 */
    "PROP_CHRMP5K",             /* D5K Deutsche                                                       */
    "PROP_CHRRUGER",            /* Cougar Magnum                                                      */
    "PROP_CHRWPPK",             /* PP7 Special Issue                                                  */
    "PROP_CHRSHOTGUN",          /* Shotgun                                                            */
    "PROP_CHRSKORPION",         /* Klobb                                                              */
    "PROP_CHRSPECTRE",          /* Phantom                                                            */
    "PROP_CHRUZI",              /* ZMG (9mm)                                                          */
    "PROP_CHRGRENADE",          /* Hand Grenade                                                       */
    "PROP_CHRFNP90",            /* RC-P90                                                             */
    "PROP_CHRBRIEFCASE",        /* Briefcase                                                          */
    "PROP_CHRREMOTEMINE",       /* Remote Mine                                                        */
    "PROP_CHRPROXIMITYMINE",    /* Proximity Mine                                                     */
    "PROP_CHRTIMEDMINE",        /* Timed Mine                                                         */
    "PROP_CHRROCKET",           /* Rocket                                                             */
    "PROP_CHRGRENADEROUND",     /* Grenade Round                                                      */
    "PROP_CHRWPPKSIL",          /* PP7 (Silenced)                                                     */
    "PROP_CHRTT33",             /* DD44 Dostovei                                                      */
    "PROP_CHRMP5KSIL",          /* D5K (Silenced)                                                     */
    "PROP_CHRAUTOSHOT",         /* Automatic Shotgun                                                  */
    "PROP_CHRGOLDEN",           /* Golden Gun                                                         */
    "PROP_CHRTHROWKNIFE",       /* Throwing Knife                                                     */
    "PROP_CHRSNIPERRIFLE",      /* Sniper Rifle                                                       */
    "PROP_CHRROCKETLAUNCH",     /* Rocket Launcher                                                    */
    "PROP_HATFURRY",            /* Fur Hat", Blue                                                      */
    "PROP_HATFURRYBROWN",       /* Fur Hat", Brown                                                     */
    "PROP_HATFURRYBLACK",       /* Fur Hat", Black                                                     */
    "PROP_HATTBIRD",            /* Side Cap", Light Green                                              */
    "PROP_HATTBIRDBROWN",       /* Side Cap", Dark Green                                               */
    "PROP_HATHELMET",           /* Combat Helmet", Green                                               */
    "PROP_HATHELMETGREY",       /* Combat Helmet", Grey                                                */
    "PROP_HATMOON",             /* Elite Headgear                                                     */
    "PROP_HATBERET",            /* Special Forces Beret", Black                                        */
    "PROP_HATBERETBLUE",        /* Special Forces Beret", Navy                                         */
    "PROP_HATBERETRED",         /* Special Forces Beret", Burgundy                                     */
    "PROP_HATPEAKED",           /* Officer's Peaked Visor Cap                                         */
    "PROP_CHRWRISTDART",        /* Pchrwristdart (BETA)                                               */
    "PROP_CHREXPLOSIVEPEN",     /* Pchrexplosivepen (BETA)                                            */
    "PROP_CHRBOMBCASE",         /* Bomb Case (Briefcase Laying Down)                                  */
    "PROP_CHRFLAREPISTOL",      /* Pchrflarepistol (BETA Pickup)                                      */
    "PROP_CHRPITONGUN",         /* Pchrpitongun (BETA Pickup)                                         */
    "PROP_CHRFINGERGUN",        /* Pchrfingergun (BETA Pickup)                                        */
    "PROP_CHRSILVERWPPK",       /* Pchrsilverwppk (BETA Pickup)                                       */
    "PROP_CHRGOLDWPPK",         /* Pchrgoldwppk (BETA Pickup)                                         */
    "PROP_CHRDYNAMITE",         /* Pchrdynamite (BETA Pickup)                                         */
    "PROP_CHRBUNGEE",           /* Pchrbungee (BETA Pickup)                                           */
    "PROP_CHRDOORDECODER",      /* Door Decoder                                                       */
    "PROP_CHRBOMBDEFUSER",      /* Bomb Defuser                                                       */
    "PROP_CHRBUGDETECTOR",      /* Pchrbugdetector (BETA Pickup)                                      */
    "PROP_CHRSAFECRACKERCASE",  /* Safe Cracker Case (Briefcase Laying Down)                          */
    "PROP_CHRCAMERA",           /* Photo Camera (007)                                                 */
    "PROP_CHRLOCKEXPLODER",     /* Pchrlockexploder (BETA Pickup)                                     */
    "PROP_CHRDOOREXPLODER",     /* Pchrdoorexploder (BETA Pickup)                                     */
    "PROP_CHRKEYANALYSERCASE",  /* Key Analyzer Case (Briefcase Laying Down)                          */
    "PROP_CHRWEAPONCASE",       /* Weapon Case (Briefcase Standing Up)                                */
    "PROP_CHRKEYYALE",          /* Yale Key                                                           */
    "PROP_CHRKEYBOLT",          /* Bolt Key                                                           */
    "PROP_CHRBUG",              /* Covert Modem / Tracker Bug                                         */
    "PROP_CHRMICROCAMERA",      /* Micro Camera                                                       */
    "PROP_FLOPPY",              /* Floppy Disc                                                        */
    "PROP_CHRGOLDENEYEKEY",     /* GoldenEye Key                                                      */
    "PROP_CHRPOLARIZEDGLASSES", /* Polarized Glasses                                                  */
    "PROP_CHRCREDITCARD",       /* Pchrcreditcard (BETA Pickup)                                       */
    "PROP_CHRDARKGLASSES",      /* Pchrdarkglasses (BETA Pickup)                                      */
    "PROP_CHRGASKEYRING",       /* Gas Keyring                                                        */
    "PROP_CHRDATATHIEF",        /* Datathief                                                          */
    "PROP_SAFE",                /* Safe Body                                                          */
    "PROP_BOMB",                /* Pbomb (BETA Pickup)                                                */
    "PROP_CHRPLANS",            /* Plans (Briefing Folder)                                            */
    "PROP_CHRSPYFILE",          /* Pchrspyfile (BETA Pickup)                                          */
    "PROP_CHRBLUEPRINTS",       /* Pirate Blueprints                                                  */
    "PROP_CHRCIRCUITBOARD",     /* Circuitboard                                                       */
    "PROP_CHRMAP",              /* Bunker Expansion Plans                                             */
    "PROP_CHRSPOOLTAPE",        /* Pchrspooltape (BETA Pickup)                                        */
    "PROP_CHRAUDIOTAPE",        /* Audiotape                                                          */
    "PROP_CHRMICROFILM",        /* Pchrmicrofilm (BETA Pickup)                                        */
    "PROP_CHRMICROCODE",        /* Pchrmicrocode (BETA Pickup)                                        */
    "PROP_CHRLECTRE",           /* Pchrlectre (BETA Pickup)                                           */
    "PROP_CHRMONEY",            /* Pchrmoney (BETA Pickup)                                            */
    "PROP_CHRGOLDBAR",          /* Pchrgoldbar (BETA Pickup)                                          */
    "PROP_CHRHEROIN",           /* Pchrheroin (BETA Pickup)                                           */
    "PROP_CHRCLIPBOARD",        /* Clipboard                                                          */
    "PROP_CHRDOSSIERRED",       /* Red Dossier                                                        */
    "PROP_CHRSTAFFLIST",        /* Staff List                                                         */
    "PROP_CHRDATTAPE",          /* DAT                                                                */
    "PROP_CHRPLASTIQUE",        /* Plastique                                                          */
    "PROP_CHRBLACKBOX",         /* Black Box (Orange Flight Recorder)                                 */
    "PROP_CHRVIDEOTAPE",        /* CCTV Tape (GoldenEye VHS)                                          */
    "PROP_NINTENDOLOGO",        /* Nintendo Logo                                                      */
    "PROP_GOLDENEYELOGO",       /* GoldenEye Logo                                                     */
    "PROP_WALLETBOND",          /* Classified Folder w/ Royal Crest (Folder Menus)                    */
    "PROP_MILTRUCK",            /* Supply Truck                                                       */
    "PROP_JEEP",                /* Military Jeep                                                      */
    "PROP_ARTIC",               /* Red Prime Mover                                                    */
    "PROP_HELICOPTER",          /* Transport Helicopter w/ Natalya                                    */
    "PROP_TIGER",               /* Pirate Euro Chopper                                                */
    "PROP_MILCOPTER",           /* Hound Helicopter                                                   */
    "PROP_HIND",                /* Soviet Camouflage Chopper                                          */
    "PROP_ARTICTRAILER",        /* Black Trailer                                                      */
    "PROP_MOTORBIKE",           /* Motorbike                                                          */
    "PROP_TANK",                /* Tank                                                               */
    "PROP_APC",                 /* Armored Personnel Carrier                                          */
    "PROP_SPEEDBOAT",           /* Speedboat                                                          */
    "PROP_PLANE",               /* Aeroplane                                                          */
    "PROP_GUN_RUNWAY1",         /* Heavy Gun Emplacement                                              */
    "PROP_SAFEDOOR",            /* Safe Door                                                          */
    "PROP_KEY_HOLDER",          /* Key Rack                                                           */
    "PROP_HATCHSEVX",           /* Grating (Ventshaft Hatch)                                          */
    "PROP_SEVDISH",             /* Satellite Dish (Severnaya)                                         */
    "PROP_ARCHSECDOOR1",        /* Archives Moving Wall (Dark)                                        */
    "PROP_ARCHSECDOOR2",        /* Archives Moving Wall (Light)                                       */
    "PROP_GROUNDGUN",           /* Free Standing Drone Gun                                            */
    "PROP_TRAINEXTDOOR",        /* Train Exterior Door                                                */
    "PROP_CARBMW",              /* White Car #1 (BMW)                                                 */
    "PROP_CARESCORT",           /* White Car #2 (Escort)                                              */
    "PROP_CARGOLF",             /* White Car #3 (Golf)                                                */
    "PROP_CARWEIRD",            /* Red Car (Cadillac)                                                 */
    "PROP_CARZIL",              /* Ourumov's Car (ZIL)                                                */
    "PROP_SHUTTLE_DOOR_L",      /* Exhaust Bay Doors", Left Side                                       */
    "PROP_SHUTTLE_DOOR_R",      /* Exhaust Bay Doors", Right Side                                      */
    "PROP_DEPOT_GATE_ENTRY",    /* Metallic Gate w/ Red Star                                          */
    "PROP_DEPOT_DOOR_STEEL",    /* Rusty Door w/ Handle (Lo-Res)                                      */
    "PROP_GLASSWARE2",          /* Beaker w/ Blue Topper                                              */
    "PROP_GLASSWARE3",          /* Erlenmeyer Flask                                                   */
    "PROP_GLASSWARE4",          /* Set of Five Beakers                                                */
    "PROP_LANDMINE",            /* Land Mine                                                          */
    "PROP_PLANT1",              /* Jungle Plant", Withered and Dying                                   */
    "PROP_PLANT11",             /* Jungle Plant", Turning Colour                                       */
    "PROP_PLANT2",              /* Jungle Plant", Healthy and Thick                                    */
    "PROP_PLANT3",              /* Jungle Plant", Tall Leaves                                          */
    "PROP_JUNGLE5_TREE",        /* Jungle Tree", Moss Covered                                          */
    "PROP_LEGALPAGE",           /* GoldenEye Certification Screen                                     */
    "PROP_ST_PETE_ROOM_1I",     /* Roads and Buildings #1 (stretch of road)                           */
    "PROP_ST_PETE_ROOM_2I",     /* Roads and Buildings #2 (stretch of road)                           */
    "PROP_ST_PETE_ROOM_3T",     /* Roads and Buildings #3 (intersection)                              */
    "PROP_ST_PETE_ROOM_5C",     /* Roads and Buildings #4 (street corner)                             */
    "PROP_ST_PETE_ROOM_6C",     /* Roads and Buildings #5 (street corner)                             */
    "PROP_DOOR_ROLLERTRAIN",    /* Roller Door                                                        */
    "PROP_DOOR_WIN",            /* Glass Sliding Door (Aztec)                                         */
    "PROP_DOOR_AZTEC",          /* Stone Sliding Door (Aztec)                                         */
    "PROP_SHUTTLE",             /* Moonraker Shuttle                                                  */
    "PROP_DOOR_AZT_DESK",       /* Boardroom Table (Aztec Exhaust Bay)                                */
    "PROP_DOOR_AZT_DESK_TOP",   /* Boardroom Table Extension (Aztec Exhaust Bay)                      */
    "PROP_DOOR_AZT_CHAIR",      /* Boardroom Chair (Aztec Exhaust Bay)                                */
    "PROP_DOOR_MF",             /* Mainframe Door                                                     */
    "PROP_FLAG",                /* Flag Tag Token                                                     */
    "PROP_BARRICADE",           /* Road Barricade                                                     */
    "PROP_MODEMBOX",            /* Covert Modem Connection Screen                                     */
    "PROP_DOORPANEL",           /* Sliding Door Activation Switch                                     */
    "PROP_DOORCONSOLE",         /* Console w/ Activation Light                                        */
    "PROP_CHRTESTTUBE",         /* Glass Test Tube                                                    */
    "PROP_BOLLARD",             /* Bollard                                                            */
};

char *CAMERAMODE_ToString[] = {
    "CAMERAMODE_NONE",
    "CAMERAMODE_INTRO",
    "CAMERAMODE_FADESWIRL",
    "CAMERAMODE_SWIRL",
    "CAMERAMODE_FP",
    "CAMERAMODE_UNK5",
    "CAMERAMODE_UNK6",
    "CAMERAMODE_POSEND",
    "CAMERAMODE_FP_NOINPUT",
    "CAMERAMODE_MP",
    "CAMERAMODE_UNK10",
};

char *INTRO_TYPE_ToString[] = {
    "INTROTYPE_SPAWN",
    "INTROTYPE_ITEM",
    "INTROTYPE_AMMO",
    "INTROTYPE_SWIRL",
    "INTROTYPE_ANIM",
    "INTROTYPE_CUFF",
    "INTROTYPE_CAMERA",
    "INTROTYPE_WATCH",
    "INTROTYPE_CREDITS",
    "INTROTYPE_END",
};

char *MISSION_STATE_IDS_ToString[] = {
    "MISSION_STATE_0",
    "MISSION_STATE_1",
    "MISSION_STATE_2",
    "MISSION_STATE_3",
    "MISSION_STATE_4",
    "MISSION_STATE_5",
    "MISSION_STATE_6"
};

char *OBJECTIVESTATUS_ToString[] = {
    "OBJECTIVESTATUS_INCOMPLETE",
    "OBJECTIVESTATUS_COMPLETE",
    "OBJECTIVESTATUS_FAILED"
};

char *GAILIST_ToString[] = {
    "GAILIST_AIM_AT_BOND",
    "GAILIST_DEAD_AI",
    "GAILIST_STANDARD_GUARD",
    "GAILIST_PLAY_IDLE_ANIMATION",
    "GAILIST_BASH_KEYBOARD",
    "GAILIST_SIMPLE_GUARD_DEAF",
    "GAILIST_ATTACK_BOND",
    "GAILIST_SIMPLE_GUARD",
    "GAILIST_RUN_TO_BOND",
    "GAILIST_SIMPLE_GUARD_ALARM_RAISER",
    "GAILIST_STARTLE_AND_RUN_TO_BOND",
    "GAILIST_TRY_CLONE_SEND_OR_RUN_TO_BOND",
    "GAILIST_STANDARD_CLONE",
    "GAILIST_PERSISTENTLY_CHASE_AND_ATTACK_BOND",
    "GAILIST_WAIT_ONE_SECOND",
    "GAILIST_END_LEVEL",
    "GAILIST_DRAW_TT33_AND_ATTCK_BOND",
    "GAILIST_REMOVE_CHR"};

#pragma region lengths
#define AI_GotoNext_LENGTH                                       2
#define AI_GotoFirst_LENGTH                                      2
#define AI_Label_LENGTH                                          2
#define AI_Yield_LENGTH                                          1
#define AI_EndList_LENGTH                                        /*canonical name*/ 1
#define AI_SetChrAiList_LENGTH                                   4
#define AI_SetReturnAiList_LENGTH                                3
#define AI_Return_LENGTH                                         1
#define AI_Stop_LENGTH                                           1
#define AI_Kneel_LENGTH                                          1
#define AI_PlayAnimation_LENGTH                                  9
#define AI_IFPlayingAnimation_LENGTH                             2
#define AI_PointAtBond_LENGTH                                    1
#define AI_LookSurprised_LENGTH                                  1
#define AI_TRYSidestepping_LENGTH                                2
#define AI_TRYSideHopping_LENGTH                                 2
#define AI_TRYSideRunning_LENGTH                                 2
#define AI_TRYFiringWalk_LENGTH                                  2
#define AI_TRYFiringRun_LENGTH                                   2
#define AI_TRYFiringRoll_LENGTH                                  2
#define AI_TRYFireOrAimAtTarget_LENGTH                           6
#define AI_TRYFireOrAimAtTargetKneel_LENGTH                      6
#define AI_IFImFiring_LENGTH                                     2
#define AI_IFImFiringAndLockedForward_LENGTH                     2
#define AI_TRYFireOrAimAtTargetUpdate_LENGTH                     6
#define AI_TRYFacingTarget_LENGTH                                6
#define AI_HitChrWithItem_LENGTH                                 4
#define AI_ChrHitChr_LENGTH                                      4
#define AI_TRYThrowingGrenade_LENGTH                             2
#define AI_TRYDroppingItem_LENGTH                                5
#define AI_RunToPad_LENGTH                                       3
#define AI_RunToPadPreset_LENGTH                                 1
#define AI_WalkToPad_LENGTH                                      3
#define AI_SprintToPad_LENGTH                                    3
#define AI_StartPatrol_LENGTH                                    2
#define AI_Surrender_LENGTH                                      1
#define AI_RemoveMe_LENGTH                                       1
#define AI_ChrRemoveInstant_LENGTH                               2
#define AI_TRYTriggeringAlarmAtPad_LENGTH                        4
#define AI_AlarmOn_LENGTH                                        1
#define AI_AlarmOff_LENGTH                                       1
#define AI_TRYRunFromBond_LENGTH                                 2
#define AI_TRYRunToBond_LENGTH                                   2
#define AI_TRYWalkToBond_LENGTH                                  2
#define AI_TRYSprintToBond_LENGTH                                2
#define AI_TRYFindCover_LENGTH                                   2
#define AI_TRYRunToChr_LENGTH                                    3
#define AI_TRYWalkToChr_LENGTH                                   3
#define AI_TRYSprintToChr_LENGTH                                 3
#define AI_IFImOnPatrolOrStopped_LENGTH                          2
#define AI_IFChrDyingOrDead_LENGTH                               3
#define AI_IFChrDoesNotExist_LENGTH                              3
#define AI_IFISeeBond_LENGTH                                     2
#define AI_SetNewRandom_LENGTH                                   1
#define AI_IFRandomLessThan_LENGTH                               3
#define AI_IFRandomGreaterThan_LENGTH                            3
#define AI_IFICanHearAlarm_LENGTH                                2
#define AI_IFAlarmIsOn_LENGTH                                    2
#define AI_IFGasIsLeaking_LENGTH                                 2
#define AI_IFIHeardBond_LENGTH                                   2
#define AI_IFISeeSomeoneShot_LENGTH                              2
#define AI_IFISeeSomeoneDie_LENGTH                               2
#define AI_IFICouldSeeBond_LENGTH                                2
#define AI_IFICouldSeeBondsStan_LENGTH                           2
#define AI_IFIWasShotRecently_LENGTH                             2
#define AI_IFIHeardBondRecently_LENGTH                           2
#define AI_IFImInRoomWithChr_LENGTH                              3
#define AI_IFIveNotBeenSeen_LENGTH                               2
#define AI_IFImOnScreen_LENGTH                                   2
#define AI_IFMyRoomIsOnScreen_LENGTH                             2
#define AI_IFRoomWithPadIsOnScreen_LENGTH                        4
#define AI_IFImTargetedByBond_LENGTH                             2
#define AI_IFBondMissedMe_LENGTH                                 2
#define AI_IFMyAngleToBondLessThan_LENGTH                        3
#define AI_IFMyAngleToBondGreaterThan_LENGTH                     3
#define AI_IFMyAngleFromBondLessThan_LENGTH                      3
#define AI_IFMyAngleFromBondGreaterThan_LENGTH                   3
#define AI_IFMyDistanceToBondLessThanDecimeter_LENGTH            4
#define AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH         4
#define AI_IFChrDistanceToPadLessThanDecimeter_LENGTH            7
#define AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH         7
#define AI_IFMyDistanceToChrLessThanDecimeter_LENGTH             5
#define AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH          5
#define AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH 4
#define AI_IFBondDistanceToPadLessThanDecimeter_LENGTH           6
#define AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH        6
#define AI_IFChrInRoomWithPad_LENGTH                             5
#define AI_IFBondInRoomWithPad_LENGTH                            4
#define AI_IFBondCollectedObject_LENGTH                          3
#define AI_IFItemIsStationaryWithinLevel_LENGTH                  3
#define AI_IFItemIsAttachedToObject_LENGTH                       4
#define AI_IFBondHasItemEquipped_LENGTH                          3
#define AI_IFObjectExists_LENGTH                                 3
#define AI_IFObjectNotDestroyed_LENGTH                           3
#define AI_IFObjectWasActivated_LENGTH                           3
#define AI_IFBondUsedGadgetOnObject_LENGTH                       3
#define AI_ActivateObject_LENGTH                                 2
#define AI_DestroyObject_LENGTH                                  2
#define AI_DropObject_LENGTH                              2
#define AI_ChrDropAllConcealedItems_LENGTH                       2
#define AI_ChrDropAllHeldItems_LENGTH                            2
#define AI_BondCollectObject_LENGTH                              2
#define AI_ChrEquipObject_LENGTH                                 3
#define AI_MoveObject_LENGTH                                     4
#define AI_DoorOpen_LENGTH                                       2
#define AI_DoorClose_LENGTH                                      2
#define AI_IFDoorStateEqual_LENGTH                               4
#define AI_IFDoorHasBeenOpenedBefore_LENGTH                      3
#define AI_DoorSetLock_LENGTH                                    3
#define AI_DoorUnsetLock_LENGTH                                  3
#define AI_IFDoorLockEqual_LENGTH                                4
#define AI_IFObjectiveNumComplete_LENGTH                         3
#define AI_TRYUnknown6e_LENGTH                                   3
#define AI_TRYUnknown6f_LENGTH                                   3
#define AI_IFGameDifficultyLessThan_LENGTH                       3
#define AI_IFGameDifficultyGreaterThan_LENGTH                    3
#define AI_IFMissionTimeLessThan_LENGTH                          4
#define AI_IFMissionTimeGreaterThan_LENGTH                       4
#define AI_IFSystemPowerTimeLessThan_LENGTH                      4
#define AI_IFSystemPowerTimeGreaterThan_LENGTH                   4
#define AI_IFLevelIdLessThan_LENGTH                              3
#define AI_IFLevelIdGreaterThan_LENGTH                           3
#define AI_IFMyNumArghsLessThan_LENGTH                           3
#define AI_IFMyNumArghsGreaterThan_LENGTH                        3
#define AI_IFMyNumCloseArghsLessThan_LENGTH                      3
#define AI_IFMyNumCloseArghsGreaterThan_LENGTH                   3
#define AI_IFChrHealthLessThan_LENGTH                            4
#define AI_IFChrHealthGreaterThan_LENGTH                         4
#define AI_IFChrWasDamagedSinceLastCheck_LENGTH                  3
#define AI_IFBondHealthLessThan_LENGTH                           3
#define AI_IFBondHealthGreaterThan_LENGTH                        3
#define AI_SetMyMorale_LENGTH                                    2
#define AI_AddToMyMorale_LENGTH                                  2
#define AI_SubtractFromMyMorale_LENGTH                           2
#define AI_IFMyMoraleLessThan_LENGTH                             3
#define AI_IFMyMoraleLessThanRandom_LENGTH                       2
#define AI_SetMyAlertness_LENGTH                                 2
#define AI_AddToMyAlertness_LENGTH                               2
#define AI_SubtractFromMyAlertness_LENGTH                        2
#define AI_IFMyAlertnessLessThan_LENGTH                          3
#define AI_IFMyAlertnessLessThanRandom_LENGTH                    2
#define AI_SetMyHearingScale_LENGTH                              3
#define AI_SetMyVisionRange_LENGTH                               2
#define AI_SetMyGrenadeProbability_LENGTH                        2
#define AI_SetMyChrNum_LENGTH                                    2
#define AI_SetMyHealthTotal_LENGTH                               3
#define AI_SetMyArmour_LENGTH                                    3
#define AI_SetMySpeedRating_LENGTH                               2
#define AI_SetMyArghRating_LENGTH                                2
#define AI_SetMyAccuracyRating_LENGTH                            2
#define AI_SetMyFlags2_LENGTH                                    2
#define AI_UnsetMyFlags2_LENGTH                                  2
#define AI_IFMyFlags2Has_LENGTH                                  3
#define AI_SetChrBitfield_LENGTH                                 3
#define AI_UnsetChrBitfield_LENGTH                               3
#define AI_IFChrBitfieldHas_LENGTH                               4
#define AI_SetObjectiveBitfield_LENGTH                           5
#define AI_UnsetObjectiveBitfield_LENGTH                         5
#define AI_IFObjectiveBitfieldHas_LENGTH                         6
#define AI_SetMychrflags_LENGTH                                  5
#define AI_UnsetMychrflags_LENGTH                                5
#define AI_IFMychrflagsHas_LENGTH                                6
#define AI_SetChrchrflags_LENGTH                                 6
#define AI_UnsetChrchrflags_LENGTH                               6
#define AI_IFChrchrflagsHas_LENGTH                               7
#define AI_SetObjectFlags_LENGTH                                 6
#define AI_UnsetObjectFlags_LENGTH                               6
#define AI_IFObjectFlagsHas_LENGTH                               7
#define AI_SetObjectFlags2_LENGTH                                6
#define AI_UnsetObjectFlags2_LENGTH                              6
#define AI_IFObjectFlags2Has_LENGTH                              7
#define AI_SetMyChrPreset_LENGTH                                 2
#define AI_SetChrChrPreset_LENGTH                                3
#define AI_SetMyPadPreset_LENGTH                                 3
#define AI_SetChrPadPreset_LENGTH                                4
#define AI_MyTimerStart_LENGTH                                   1
#define AI_MyTimerReset_LENGTH                                   1
#define AI_MyTimerPause_LENGTH                                   1
#define AI_MyTimerResume_LENGTH                                  1
#define AI_IFMyTimerIsNotRunning_LENGTH                          2
#define AI_IFMyTimerLessThanTicks_LENGTH                         5
#define AI_IFMyTimerGreaterThanTicks_LENGTH                      5
#define AI_HudCountdownShow_LENGTH                               1
#define AI_HudCountdownHide_LENGTH                               1
#define AI_HudCountdownSet_LENGTH                                3
#define AI_HudCountdownStop_LENGTH                               1
#define AI_HudCountdownStart_LENGTH                              1
#define AI_IFHudCountdownIsNotRunning_LENGTH                     2
#define AI_IFHudCountdownLessThan_LENGTH                         4
#define AI_IFHudCountdownGreaterThan_LENGTH                      4
#define AI_TRYSpawningChrAtPad_LENGTH                            12
#define AI_TRYSpawningChrNextToChr_LENGTH                        11
#define AI_TRYGiveMeItem_LENGTH                                  9
#define AI_TRYGiveMeHat_LENGTH                                   8
#define AI_TRYCloningChr_LENGTH                                  5
#define AI_TextPrintBottom_LENGTH                                3
#define AI_TextPrintTop_LENGTH                                   3
#define AI_SfxPlay_LENGTH                                        4
#define AI_SfxEmitFromObject_LENGTH                              5
#define AI_SfxEmitFromPad_LENGTH                                 6
#define AI_SfxSetChannelVolume_LENGTH                            6
#define AI_SfxFadeChannelVolume_LENGTH                           6
#define AI_SfxStopChannel_LENGTH                                 2
#define AI_IFSfxChannelVolumeLessThan_LENGTH                     5
#define AI_VehicleStartPath_LENGTH                               2
#define AI_VehicleSpeed_LENGTH                                   5
#define AI_AircraftRotorSpeed_LENGTH                             5
#define AI_IFCameraIsInIntro_LENGTH                              2
#define AI_IFCameraIsInBondSwirl_LENGTH                          2
#define AI_TvChangeScreenBank_LENGTH                             4
#define AI_IFBondInTank_LENGTH                                   /*canonical name*/ 2
#define AI_EndLevel_LENGTH                                       /* canonical name */ 1
#define AI_CameraReturnToBond_LENGTH                             1
#define AI_CameraLookAtBondFromPad_LENGTH                        3
#define AI_CameraSwitch_LENGTH                                   6
#define AI_IFBondYPosLessThan_LENGTH                             4
#define AI_BondDisableControl_LENGTH                             2
#define AI_BondEnableControl_LENGTH                              1
#define AI_TRYTeleportingChrToPad_LENGTH                         5
#define AI_ScreenFadeToBlack_LENGTH                              1
#define AI_ScreenFadeFromBlack_LENGTH                            1
#define AI_IFScreenFadeCompleted_LENGTH                          2
#define AI_HideAllChrs_LENGTH                                    1
#define AI_ShowAllChrs_LENGTH                                    1
#define AI_DoorOpenInstant_LENGTH                                2
#define AI_ChrRemoveItemInHand_LENGTH                            3
#define AI_IfNumberOfActivePlayersLessThan_LENGTH                3
#define AI_IFBondItemTotalAmmoLessThan_LENGTH                    4
#define AI_BondEquipItem_LENGTH                                  2
#define AI_BondEquipItemCinema_LENGTH                            2
#define AI_BondSetLockedVelocity_LENGTH                          3
#define AI_IFObjectInRoomWithPad_LENGTH                          5
#define AI_SwitchSky_LENGTH                                      1
#define AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH           1
#define AI_IFBondIsDead_LENGTH                                   2
#define AI_BondDisableDamageAndPickups_LENGTH                    1
#define AI_BondHideWeapons_LENGTH                                1
#define AI_CameraOrbitPad_LENGTH                                 13
#define AI_CreditsRoll_LENGTH                                    1
#define AI_IFCreditsHasCompleted_LENGTH                          2
#define AI_IFObjectiveAllCompleted_LENGTH                        2
#define AI_IFFolderActorIsEqual_LENGTH                           3
#define AI_IFBondDamageAndPickupsDisabled_LENGTH                 2
#define AI_MusicPlaySlot_LENGTH                                  4
#define AI_MusicStopSlot_LENGTH                                  2
#define AI_TriggerExplosionsAroundBond_LENGTH                    1
#define AI_IFKilledCiviliansGreaterThan_LENGTH                   3
#define AI_IFChrWasShotSinceLastCheck_LENGTH                     3
#define AI_BondKilledInAction_LENGTH                             1
#define AI_RaiseArms_LENGTH                                      1
#define AI_GasLeakAndFadeFog_LENGTH                              1
#define AI_ObjectRocketLaunch_LENGTH                             2
#pragma endregion

int AI_CMD_LENGTHS_ToInt[] = {
    AI_GotoNext_LENGTH,
    AI_GotoFirst_LENGTH,
    AI_Label_LENGTH,
    AI_Yield_LENGTH,
    AI_EndList_LENGTH,
    AI_SetChrAiList_LENGTH,
    AI_SetReturnAiList_LENGTH,
    AI_Return_LENGTH,
    AI_Stop_LENGTH,
    AI_Kneel_LENGTH,
    AI_PlayAnimation_LENGTH,
    AI_IFPlayingAnimation_LENGTH,
    AI_PointAtBond_LENGTH,
    AI_LookSurprised_LENGTH,
    AI_TRYSidestepping_LENGTH,
    AI_TRYSideHopping_LENGTH,
    AI_TRYSideRunning_LENGTH,
    AI_TRYFiringWalk_LENGTH,
    AI_TRYFiringRun_LENGTH,
    AI_TRYFiringRoll_LENGTH,
    AI_TRYFireOrAimAtTarget_LENGTH,
    AI_TRYFireOrAimAtTargetKneel_LENGTH,
    AI_TRYFireOrAimAtTargetUpdate_LENGTH,
    AI_TRYFacingTarget_LENGTH,
    AI_HitChrWithItem_LENGTH,
    AI_ChrHitChr_LENGTH,
    AI_TRYThrowingGrenade_LENGTH,
    AI_TRYDroppingItem_LENGTH,
    AI_RunToPad_LENGTH,
    AI_RunToPadPreset_LENGTH,
    AI_WalkToPad_LENGTH,
    AI_SprintToPad_LENGTH,
    AI_StartPatrol_LENGTH,
    AI_Surrender_LENGTH,
    AI_RemoveMe_LENGTH,
    AI_ChrRemoveInstant_LENGTH,
    AI_TRYTriggeringAlarmAtPad_LENGTH,
    AI_AlarmOn_LENGTH,
    AI_AlarmOff_LENGTH,
    AI_TRYRunFromBond_LENGTH,
    AI_TRYRunToBond_LENGTH,
    AI_TRYWalkToBond_LENGTH,
    AI_TRYSprintToBond_LENGTH,
    AI_TRYFindCover_LENGTH,
    AI_TRYRunToChr_LENGTH,
    AI_TRYWalkToChr_LENGTH,
    AI_TRYSprintToChr_LENGTH,
    AI_IFImOnPatrolOrStopped_LENGTH,
    AI_IFChrDyingOrDead_LENGTH,
    AI_IFChrDoesNotExist_LENGTH,
    AI_IFISeeBond_LENGTH,
    AI_SetNewRandom_LENGTH,
    AI_IFRandomLessThan_LENGTH,
    AI_IFRandomGreaterThan_LENGTH,
    AI_IFICanHearAlarm_LENGTH,
    AI_IFAlarmIsOn_LENGTH,
    AI_IFGasIsLeaking_LENGTH,
    AI_IFIHeardBond_LENGTH,
    AI_IFISeeSomeoneShot_LENGTH,
    AI_IFISeeSomeoneDie_LENGTH,
    AI_IFICouldSeeBond_LENGTH,
    AI_IFICouldSeeBondsStan_LENGTH,
    AI_IFIWasShotRecently_LENGTH,
    AI_IFIHeardBondRecently_LENGTH,
    AI_IFImInRoomWithChr_LENGTH,
    AI_IFIveNotBeenSeen_LENGTH,
    AI_IFImOnScreen_LENGTH,
    AI_IFMyRoomIsOnScreen_LENGTH,
    AI_IFRoomWithPadIsOnScreen_LENGTH,
    AI_IFImTargetedByBond_LENGTH,
    AI_IFBondMissedMe_LENGTH,
    AI_IFMyAngleToBondLessThan_LENGTH,
    AI_IFMyAngleToBondGreaterThan_LENGTH,
    AI_IFMyAngleFromBondLessThan_LENGTH,
    AI_IFMyAngleFromBondGreaterThan_LENGTH,
    AI_IFMyDistanceToBondLessThanDecimeter_LENGTH,
    AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH,
    AI_IFChrDistanceToPadLessThanDecimeter_LENGTH,
    AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH,
    AI_IFMyDistanceToChrLessThanDecimeter_LENGTH,
    AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH,
    AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH,
    AI_IFBondDistanceToPadLessThanDecimeter_LENGTH,
    AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH,
    AI_IFChrInRoomWithPad_LENGTH,
    AI_IFBondInRoomWithPad_LENGTH,
    AI_IFBondCollectedObject_LENGTH,
    AI_IFItemIsStationaryWithinLevel_LENGTH,
    AI_IFItemIsAttachedToObject_LENGTH,
    AI_IFBondHasItemEquipped_LENGTH,
    AI_IFObjectExists_LENGTH,
    AI_IFObjectNotDestroyed_LENGTH,
    AI_IFObjectWasActivated_LENGTH,
    AI_IFBondUsedGadgetOnObject_LENGTH,
    AI_ActivateObject_LENGTH,
    AI_DestroyObject_LENGTH,
    AI_DropObject_LENGTH,
    AI_ChrDropAllConcealedItems_LENGTH,
    AI_ChrDropAllHeldItems_LENGTH,
    AI_BondCollectObject_LENGTH,
    AI_ChrEquipObject_LENGTH,
    AI_MoveObject_LENGTH,
    AI_DoorOpen_LENGTH,
    AI_DoorClose_LENGTH,
    AI_IFDoorStateEqual_LENGTH,
    AI_IFDoorHasBeenOpenedBefore_LENGTH,
    AI_DoorSetLock_LENGTH,
    AI_DoorUnsetLock_LENGTH,
    AI_IFDoorLockEqual_LENGTH,
    AI_IFObjectiveNumComplete_LENGTH,
    AI_TRYUnknown6e_LENGTH,
    AI_TRYUnknown6f_LENGTH,
    AI_IFGameDifficultyLessThan_LENGTH,
    AI_IFGameDifficultyGreaterThan_LENGTH,
    AI_IFMissionTimeLessThan_LENGTH,
    AI_IFMissionTimeGreaterThan_LENGTH,
    AI_IFSystemPowerTimeLessThan_LENGTH,
    AI_IFSystemPowerTimeGreaterThan_LENGTH,
    AI_IFLevelIdLessThan_LENGTH,
    AI_IFLevelIdGreaterThan_LENGTH,
    AI_IFMyNumArghsLessThan_LENGTH,
    AI_IFMyNumArghsGreaterThan_LENGTH,
    AI_IFMyNumCloseArghsLessThan_LENGTH,
    AI_IFMyNumCloseArghsGreaterThan_LENGTH,
    AI_IFChrHealthLessThan_LENGTH,
    AI_IFChrHealthGreaterThan_LENGTH,
    AI_IFChrWasDamagedSinceLastCheck_LENGTH,
    AI_IFBondHealthLessThan_LENGTH,
    AI_IFBondHealthGreaterThan_LENGTH,
    AI_SetMyMorale_LENGTH,
    AI_AddToMyMorale_LENGTH,
    AI_SubtractFromMyMorale_LENGTH,
    AI_IFMyMoraleLessThan_LENGTH,
    AI_IFMyMoraleLessThanRandom_LENGTH,
    AI_SetMyAlertness_LENGTH,
    AI_AddToMyAlertness_LENGTH,
    AI_SubtractFromMyAlertness_LENGTH,
    AI_IFMyAlertnessLessThan_LENGTH,
    AI_IFMyAlertnessLessThanRandom_LENGTH,
    AI_SetMyHearingScale_LENGTH,
    AI_SetMyVisionRange_LENGTH,
    AI_SetMyGrenadeProbability_LENGTH,
    AI_SetMyChrNum_LENGTH,
    AI_SetMyHealthTotal_LENGTH,
    AI_SetMyArmour_LENGTH,
    AI_SetMySpeedRating_LENGTH,
    AI_SetMyArghRating_LENGTH,
    AI_SetMyAccuracyRating_LENGTH,
    AI_SetMyFlags2_LENGTH,
    AI_UnsetMyFlags2_LENGTH,
    AI_IFMyFlags2Has_LENGTH,
    AI_SetChrBitfield_LENGTH,
    AI_UnsetChrBitfield_LENGTH,
    AI_IFChrBitfieldHas_LENGTH,
    AI_SetObjectiveBitfield_LENGTH,
    AI_UnsetObjectiveBitfield_LENGTH,
    AI_IFObjectiveBitfieldHas_LENGTH,
    AI_SetMychrflags_LENGTH,
    AI_UnsetMychrflags_LENGTH,
    AI_IFMychrflagsHas_LENGTH,
    AI_SetChrchrflags_LENGTH,
    AI_UnsetChrchrflags_LENGTH,
    AI_IFChrchrflagsHas_LENGTH,
    AI_SetObjectFlags_LENGTH,
    AI_UnsetObjectFlags_LENGTH,
    AI_IFObjectFlagsHas_LENGTH,
    AI_SetObjectFlags2_LENGTH,
    AI_UnsetObjectFlags2_LENGTH,
    AI_IFObjectFlags2Has_LENGTH,
    AI_SetMyChrPreset_LENGTH,
    AI_SetChrChrPreset_LENGTH,
    AI_SetMyPadPreset_LENGTH,
    AI_SetChrPadPreset_LENGTH,
    0,
    AI_MyTimerStart_LENGTH,
    AI_MyTimerReset_LENGTH,
    AI_MyTimerPause_LENGTH,
    AI_MyTimerResume_LENGTH,
    AI_IFMyTimerIsNotRunning_LENGTH,
    AI_IFMyTimerLessThanTicks_LENGTH,
    AI_IFMyTimerGreaterThanTicks_LENGTH,
    AI_HudCountdownShow_LENGTH,
    AI_HudCountdownHide_LENGTH,
    AI_HudCountdownSet_LENGTH,
    AI_HudCountdownStop_LENGTH,
    AI_HudCountdownStart_LENGTH,
    AI_IFHudCountdownIsNotRunning_LENGTH,
    AI_IFHudCountdownLessThan_LENGTH,
    AI_IFHudCountdownGreaterThan_LENGTH,
    AI_TRYSpawningChrAtPad_LENGTH,
    AI_TRYSpawningChrNextToChr_LENGTH,
    AI_TRYGiveMeItem_LENGTH,
    AI_TRYGiveMeHat_LENGTH,
    AI_TRYCloningChr_LENGTH,
    AI_TextPrintBottom_LENGTH,
    AI_TextPrintTop_LENGTH,
    AI_SfxPlay_LENGTH,
    AI_SfxEmitFromObject_LENGTH,
    AI_SfxEmitFromPad_LENGTH,
    AI_SfxSetChannelVolume_LENGTH,
    AI_SfxFadeChannelVolume_LENGTH,
    AI_SfxStopChannel_LENGTH,
    AI_IFSfxChannelVolumeLessThan_LENGTH,
    AI_VehicleStartPath_LENGTH,
    AI_VehicleSpeed_LENGTH,
    AI_AircraftRotorSpeed_LENGTH,
    AI_IFCameraIsInIntro_LENGTH,
    AI_IFCameraIsInBondSwirl_LENGTH,
    AI_TvChangeScreenBank_LENGTH,
    AI_IFBondInTank_LENGTH,
    AI_EndLevel_LENGTH,
    AI_CameraReturnToBond_LENGTH,
    AI_CameraLookAtBondFromPad_LENGTH,
    AI_CameraSwitch_LENGTH,
    AI_IFBondYPosLessThan_LENGTH,
    AI_BondDisableControl_LENGTH,
    AI_BondEnableControl_LENGTH,
    AI_TRYTeleportingChrToPad_LENGTH,
    AI_ScreenFadeToBlack_LENGTH,
    AI_ScreenFadeFromBlack_LENGTH,
    AI_IFScreenFadeCompleted_LENGTH,
    AI_HideAllChrs_LENGTH,
    AI_ShowAllChrs_LENGTH,
    AI_DoorOpenInstant_LENGTH,
    AI_ChrRemoveItemInHand_LENGTH,
    AI_IfNumberOfActivePlayersLessThan_LENGTH,
    AI_IFBondItemTotalAmmoLessThan_LENGTH,
    AI_BondEquipItem_LENGTH,
    AI_BondEquipItemCinema_LENGTH,
    AI_BondSetLockedVelocity_LENGTH,
    AI_IFObjectInRoomWithPad_LENGTH,
    AI_IFImFiringAndLockedForward_LENGTH,
    AI_IFImFiring_LENGTH,
    AI_SwitchSky_LENGTH,
    AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH,
    AI_IFBondIsDead_LENGTH,
    AI_BondDisableDamageAndPickups_LENGTH,
    AI_BondHideWeapons_LENGTH,
    AI_CameraOrbitPad_LENGTH,
    AI_CreditsRoll_LENGTH,
    AI_IFCreditsHasCompleted_LENGTH,
    AI_IFObjectiveAllCompleted_LENGTH,
    AI_IFFolderActorIsEqual_LENGTH,
    AI_IFBondDamageAndPickupsDisabled_LENGTH,
    AI_MusicPlaySlot_LENGTH,
    AI_MusicStopSlot_LENGTH,
    AI_TriggerExplosionsAroundBond_LENGTH,
    AI_IFKilledCiviliansGreaterThan_LENGTH,
    AI_IFChrWasShotSinceLastCheck_LENGTH,
    AI_BondKilledInAction_LENGTH,
    AI_RaiseArms_LENGTH,
    AI_GasLeakAndFadeFog_LENGTH,
    AI_ObjectRocketLaunch_LENGTH};

typedef enum AI_CMD
{
    AI_GotoNext,
    AI_GotoFirst,
    AI_Label,
    AI_Yield,
    AI_EndList,
    AI_SetChrAiList,
    AI_SetReturnAiList,
    AI_Return,
    AI_Stop,
    AI_Kneel,
    AI_PlayAnimation,
    AI_IFPlayingAnimation,
    AI_PointAtBond,
    AI_LookSurprised,
    AI_TRYSidestepping,
    AI_TRYSideHopping,
    AI_TRYSideRunning,
    AI_TRYFiringWalk,
    AI_TRYFiringRun,
    AI_TRYFiringRoll,
    AI_TRYFireOrAimAtTarget,
    AI_TRYFireOrAimAtTargetKneel,
    AI_TRYFireOrAimAtTargetUpdate,
    AI_TRYFacingTarget,
    AI_HitChrWithItem,
    AI_ChrHitChr,
    AI_TRYThrowingGrenade,
    AI_TRYDroppingItem,
    AI_RunToPad,
    AI_RunToPadPreset,
    AI_WalkToPad,
    AI_SprintToPad,
    AI_StartPatrol,
    AI_Surrender,
    AI_RemoveMe,
    AI_ChrRemoveInstant,
    AI_TRYTriggeringAlarmAtPad,
    AI_AlarmOn,
    AI_AlarmOff,
    AI_TRYRunFromBond,
    AI_TRYRunToBond,
    AI_TRYWalkToBond,
    AI_TRYSprintToBond,
    AI_TRYFindCover,
    AI_TRYRunToChr,
    AI_TRYWalkToChr,
    AI_TRYSprintToChr,
    AI_IFImOnPatrolOrStopped,
    AI_IFChrDyingOrDead,
    AI_IFChrDoesNotExist,
    AI_IFISeeBond,
    AI_SetNewRandom,
    AI_IFRandomLessThan,
    AI_IFRandomGreaterThan,
    AI_IFICanHearAlarm,
    AI_IFAlarmIsOn,
    AI_IFGasIsLeaking,
    AI_IFIHeardBond,
    AI_IFISeeSomeoneShot,
    AI_IFISeeSomeoneDie,
    AI_IFICouldSeeBond,
    AI_IFICouldSeeBondsStan,
    AI_IFIWasShotRecently,
    AI_IFIHeardBondRecently,
    AI_IFImInRoomWithChr,
    AI_IFIveNotBeenSeen,
    AI_IFImOnScreen,
    AI_IFMyRoomIsOnScreen,
    AI_IFRoomWithPadIsOnScreen,
    AI_IFImTargetedByBond,
    AI_IFBondMissedMe,
    AI_IFMyAngleToBondLessThan,
    AI_IFMyAngleToBondGreaterThan,
    AI_IFMyAngleFromBondLessThan,
    AI_IFMyAngleFromBondGreaterThan,
    AI_IFMyDistanceToBondLessThanDecimeter,
    AI_IFMyDistanceToBondGreaterThanDecimeter,
    AI_IFChrDistanceToPadLessThanDecimeter,
    AI_IFChrDistanceToPadGreaterThanDecimeter,
    AI_IFMyDistanceToChrLessThanDecimeter,
    AI_IFMyDistanceToChrGreaterThanDecimeter,
    AI_TRYSettingMyPresetToChrWithinDistanceDecimeter,
    AI_IFBondDistanceToPadLessThanDecimeter,
    AI_IFBondDistanceToPadGreaterThanDecimeter,
    AI_IFChrInRoomWithPad,
    AI_IFBondInRoomWithPad,
    AI_IFBondCollectedObject,
    AI_IFItemIsStationaryWithinLevel,
    AI_IFItemIsAttachedToObject,
    AI_IFBondHasItemEquipped,
    AI_IFObjectExists,
    AI_IFObjectNotDestroyed,
    AI_IFObjectWasActivated,
    AI_IFBondUsedGadgetOnObject,
    AI_ActivateObject,
    AI_DestroyObject,
    AI_DropObject,
    AI_ChrDropAllConcealedItems,
    AI_ChrDropAllHeldItems,
    AI_BondCollectObject,
    AI_ChrEquipObject,
    AI_MoveObject,
    AI_DoorOpen,
    AI_DoorClose,
    AI_IFDoorStateEqual,
    AI_IFDoorHasBeenOpenedBefore,
    AI_DoorSetLock,
    AI_DoorUnsetLock,
    AI_IFDoorLockEqual,
    AI_IFObjectiveNumComplete,
    AI_TRYUnknown6e,
    AI_TRYUnknown6f,
    AI_IFGameDifficultyLessThan,
    AI_IFGameDifficultyGreaterThan,
    AI_IFMissionTimeLessThan,
    AI_IFMissionTimeGreaterThan,
    AI_IFSystemPowerTimeLessThan,
    AI_IFSystemPowerTimeGreaterThan,
    AI_IFLevelIdLessThan,
    AI_IFLevelIdGreaterThan,
    AI_IFMyNumArghsLessThan,
    AI_IFMyNumArghsGreaterThan,
    AI_IFMyNumCloseArghsLessThan,
    AI_IFMyNumCloseArghsGreaterThan,
    AI_IFChrHealthLessThan,
    AI_IFChrHealthGreaterThan,
    AI_IFChrWasDamagedSinceLastCheck,
    AI_IFBondHealthLessThan,
    AI_IFBondHealthGreaterThan,
    AI_SetMyMorale,
    AI_AddToMyMorale,
    AI_SubtractFromMyMorale,
    AI_IFMyMoraleLessThan,
    AI_IFMyMoraleLessThanRandom,
    AI_SetMyAlertness,
    AI_AddToMyAlertness,
    AI_SubtractFromMyAlertness,
    AI_IFMyAlertnessLessThan,
    AI_IFMyAlertnessLessThanRandom,
    AI_SetMyHearingScale,
    AI_SetMyVisionRange,
    AI_SetMyGrenadeProbability,
    AI_SetMyChrNum,
    AI_SetMyHealthTotal,
    AI_SetMyArmour,
    AI_SetMySpeedRating,
    AI_SetMyArghRating,
    AI_SetMyAccuracyRating,
    AI_SetMyFlags2,
    AI_UnsetMyFlags2,
    AI_IFMyFlags2Has,
    AI_SetChrBitfield,
    AI_UnsetChrBitfield,
    AI_IFChrBitfieldHas,
    AI_SetObjectiveBitfield,
    AI_UnsetObjectiveBitfield,
    AI_IFObjectiveBitfieldHas,
    AI_SetMychrflags,
    AI_UnsetMychrflags,
    AI_IFMychrflagsHas,
    AI_SetChrchrflags,
    AI_UnsetChrchrflags,
    AI_IFChrchrflagsHas,
    AI_SetObjectFlags,
    AI_UnsetObjectFlags,
    AI_IFObjectFlagsHas,
    AI_SetObjectFlags2,
    AI_UnsetObjectFlags2,
    AI_IFObjectFlags2Has,
    AI_SetMyChrPreset,
    AI_SetChrChrPreset,
    AI_SetMyPadPreset,
    AI_SetChrPadPreset,
    AI_PRINT,
    AI_MyTimerStart,
    AI_MyTimerReset,
    AI_MyTimerPause,
    AI_MyTimerResume,
    AI_IFMyTimerIsNotRunning,
    AI_IFMyTimerLessThanTicks,
    AI_IFMyTimerGreaterThanTicks,
    AI_HudCountdownShow,
    AI_HudCountdownHide,
    AI_HudCountdownSet,
    AI_HudCountdownStop,
    AI_HudCountdownStart,
    AI_IFHudCountdownIsNotRunning,
    AI_IFHudCountdownLessThan,
    AI_IFHudCountdownGreaterThan,
    AI_TRYSpawningChrAtPad,
    AI_TRYSpawningChrNextToChr,
    AI_TRYGiveMeItem,
    AI_TRYGiveMeHat,
    AI_TRYCloningChr,
    AI_TextPrintBottom,
    AI_TextPrintTop,
    AI_SfxPlay,
    AI_SfxEmitFromObject,
    AI_SfxEmitFromPad,
    AI_SfxSetChannelVolume,
    AI_SfxFadeChannelVolume,
    AI_SfxStopChannel,
    AI_IFSfxChannelVolumeLessThan,
    AI_VehicleStartPath,
    AI_VehicleSpeed,
    AI_AircraftRotorSpeed,
    AI_IFCameraIsInIntro,
    AI_IFCameraIsInBondSwirl,
    AI_TvChangeScreenBank,
    AI_IFBondInTank,
    AI_EndLevel,
    AI_CameraReturnToBond,
    AI_CameraLookAtBondFromPad,
    AI_CameraSwitch,
    AI_IFBondYPosLessThan,
    AI_BondDisableControl,
    AI_BondEnableControl,
    AI_TRYTeleportingChrToPad,
    AI_ScreenFadeToBlack,
    AI_ScreenFadeFromBlack,
    AI_IFScreenFadeCompleted,
    AI_HideAllChrs,
    AI_ShowAllChrs,
    AI_DoorOpenInstant,
    AI_ChrRemoveItemInHand,
    AI_IfNumberOfActivePlayersLessThan,
    AI_IFBondItemTotalAmmoLessThan,
    AI_BondEquipItem,
    AI_BondEquipItemCinema,
    AI_BondSetLockedVelocity,
    AI_IFObjectInRoomWithPad,
    AI_IFImFiringAndLockedForward,
    AI_IFImFiring,
    AI_SwitchSky,
    AI_TriggerFadeAndExitLevelOnButtonPress,
    AI_IFBondIsDead,
    AI_BondDisableDamageAndPickups,
    AI_BondHideWeapons,
    AI_CameraOrbitPad,
    AI_CreditsRoll,
    AI_IFCreditsHasCompleted,
    AI_IFObjectiveAllCompleted,
    AI_IFFolderActorIsEqual,
    AI_IFBondDamageAndPickupsDisabled,
    AI_MusicPlaySlot,
    AI_MusicStopSlot,
    AI_TriggerExplosionsAroundBond,
    AI_IFKilledCiviliansGreaterThan,
    AI_IFChrWasShotSinceLastCheck,
    AI_BondKilledInAction,
    AI_RaiseArms,
    AI_GasLeakAndFadeFog,
    AI_ObjectRocketLaunch,
    AI_CMD_COUNT
} AI_CMD;

char *AI_CMD_ToString[] = {
    "GotoNext",
    "GotoFirst",
    "Label",
    "Yield",
    "EndList",
    "SetChrAiList",
    "SetReturnAiList",
    "Return",
    "Stop",
    "Kneel",
    "PlayAnimation",
    "IFPlayingAnimation",
    "PointAtBond",
    "LookSurprised",
    "TRYSidestepping",
    "TRYSideHopping",
    "TRYSideRunning",
    "TRYFiringWalk",
    "TRYFiringRun",
    "TRYFiringRoll",
    "TRYFireOrAimAtTarget",
    "TRYFireOrAimAtTargetKneel",
    "TRYFireOrAimAtTargetUpdate",
    "TRYFacingTarget",
    "HitChrWithItem",
    "ChrHitChr",
    "TRYThrowingGrenade",
    "TRYDroppingItem",
    "RunToPad",
    "RunToPadPreset",
    "WalkToPad",
    "SprintToPad",
    "StartPatrol",
    "Surrender",
    "RemoveMe",
    "ChrRemoveInstant",
    "TRYTriggeringAlarmAtPad",
    "AlarmOn",
    "AlarmOff",
    "TRYRunFromBond",
    "TRYRunToBond",
    "TRYWalkToBond",
    "TRYSprintToBond",
    "TRYFindCover",
    "TRYRunToChr",
    "TRYWalkToChr",
    "TRYSprintToChr",
    "IFImOnPatrolOrStopped",
    "IFChrDyingOrDead",
    "IFChrDoesNotExist",
    "IFISeeBond",
    "SetNewRandom",
    "IFRandomLessThan",
    "IFRandomGreaterThan",
    "IFICanHearAlarm",
    "IFAlarmIsOn",
    "IFGasIsLeaking",
    "IFIHeardBond",
    "IFISeeSomeoneShot",
    "IFISeeSomeoneDie",
    "IFICouldSeeBond",
    "IFICouldSeeBondsStan",
    "IFIWasShotRecently",
    "IFIHeardBondRecently",
    "IFImInRoomWithChr",
    "IFIveNotBeenSeen",
    "IFImOnScreen",
    "IFMyRoomIsOnScreen",
    "IFRoomWithPadIsOnScreen",
    "IFImTargetedByBond",
    "IFBondMissedMe",
    "IFMyAngleToBondLessThan",
    "IFMyAngleToBondGreaterThan",
    "IFMyAngleFromBondLessThan",
    "IFMyAngleFromBondGreaterThan",
    "IFMyDistanceToBondLessThanDecimeter",
    "IFMyDistanceToBondGreaterThanDecimeter",
    "IFChrDistanceToPadLessThanDecimeter",
    "IFChrDistanceToPadGreaterThanDecimeter",
    "IFMyDistanceToChrLessThanDecimeter",
    "IFMyDistanceToChrGreaterThanDecimeter",
    "TRYSettingMyPresetToChrWithinDistanceDecimeter",
    "IFBondDistanceToPadLessThanDecimeter",
    "IFBondDistanceToPadGreaterThanDecimeter",
    "IFChrInRoomWithPad",
    "IFBondInRoomWithPad",
    "IFBondCollectedObject",
    "IFItemIsStationaryWithinLevel",
    "IFItemIsAttachedToObject",
    "IFBondHasItemEquipped",
    "IFObjectExists",
    "IFObjectNotDestroyed",
    "IFObjectWasActivated",
    "IFBondUsedGadgetOnObject",
    "ActivateObject",
    "DestroyObject",
    "DropObject",
    "ChrDropAllConcealedItems",
    "ChrDropAllHeldItems",
    "BondCollectObject",
    "ChrEquipObject",
    "MoveObject",
    "DoorOpen",
    "DoorClose",
    "IFDoorStateEqual",
    "IFDoorHasBeenOpenedBefore",
    "DoorSetLock",
    "DoorUnsetLock",
    "IFDoorLockEqual",
    "IFObjectiveNumComplete",
    "TRYUnknown6e",
    "TRYUnknown6f",
    "IFGameDifficultyLessThan",
    "IFGameDifficultyGreaterThan",
    "IFMissionTimeLessThan",
    "IFMissionTimeGreaterThan",
    "IFSystemPowerTimeLessThan",
    "IFSystemPowerTimeGreaterThan",
    "IFLevelIdLessThan",
    "IFLevelIdGreaterThan",
    "IFMyNumArghsLessThan",
    "IFMyNumArghsGreaterThan",
    "IFMyNumCloseArghsLessThan",
    "IFMyNumCloseArghsGreaterThan",
    "IFChrHealthLessThan",
    "IFChrHealthGreaterThan",
    "IFChrWasDamagedSinceLastCheck",
    "IFBondHealthLessThan",
    "IFBondHealthGreaterThan",
    "SetMyMorale",
    "AddToMyMorale",
    "SubtractFromMyMorale",
    "IFMyMoraleLessThan",
    "IFMyMoraleLessThanRandom",
    "SetMyAlertness",
    "AddToMyAlertness",
    "SubtractFromMyAlertness",
    "IFMyAlertnessLessThan",
    "IFMyAlertnessLessThanRandom",
    "SetMyHearingScale",
    "SetMyVisionRange",
    "SetMyGrenadeProbability",
    "SetMyChrNum",
    "SetMyHealthTotal",
    "SetMyArmour",
    "SetMySpeedRating",
    "SetMyArghRating",
    "SetMyAccuracyRating",
    "SetMyFlags2",
    "UnsetMyFlags2",
    "IFMyFlags2Has",
    "SetChrBitfield",
    "UnsetChrBitfield",
    "IFChrBitfieldHas",
    "SetObjectiveBitfield",
    "UnsetObjectiveBitfield",
    "IFObjectiveBitfieldHas",
    "SetMychrflags",
    "UnsetMychrflags",
    "IFMychrflagsHas",
    "SetChrchrflags",
    "UnsetChrchrflags",
    "IFChrchrflagsHas",
    "SetObjectFlags",
    "UnsetObjectFlags",
    "IFObjectFlagsHas",
    "SetObjectFlags2",
    "UnsetObjectFlags2",
    "IFObjectFlags2Has",
    "SetMyChrPreset",
    "SetChrChrPreset",
    "SetMyPadPreset",
    "SetChrPadPreset",
    "PRINT",
    "MyTimerStart",
    "MyTimerReset",
    "MyTimerPause",
    "MyTimerResume",
    "IFMyTimerIsNotRunning",
    "IFMyTimerLessThanTicks",
    "IFMyTimerGreaterThanTicks",
    "HudCountdownShow",
    "HudCountdownHide",
    "HudCountdownSet",
    "HudCountdownStop",
    "HudCountdownStart",
    "IFHudCountdownIsNotRunning",
    "IFHudCountdownLessThan",
    "IFHudCountdownGreaterThan",
    "TRYSpawningChrAtPad",
    "TRYSpawningChrNextToChr",
    "TRYGiveMeItem",
    "TRYGiveMeHat",
    "TRYCloningChr",
    "TextPrintBottom",
    "TextPrintTop",
    "SfxPlay",
    "SfxEmitFromObject",
    "SfxEmitFromPad",
    "SfxSetChannelVolume",
    "SfxFadeChannelVolume",
    "SfxStopChannel",
    "IFSfxChannelVolumeLessThan",
    "VehicleStartPath",
    "VehicleSpeed",
    "AircraftRotorSpeed",
    "IFCameraIsInIntro",
    "IFCameraIsInBondSwirl",
    "TvChangeScreenBank",
    "IFBondInTank",
    "EndLevel",
    "CameraReturnToBond",
    "CameraLookAtBondFromPad",
    "CameraSwitch",
    "IFBondYPosLessThan",
    "BondDisableControl",
    "BondEnableControl",
    "TRYTeleportingChrToPad",
    "ScreenFadeToBlack",
    "ScreenFadeFromBlack",
    "IFScreenFadeCompleted",
    "HideAllChrs",
    "ShowAllChrs",
    "DoorOpenInstant",
    "ChrRemoveItemInHand",
    "IfNumberOfActivePlayersLessThan",
    "IFBondItemTotalAmmoLessThan",
    "BondEquipItem",
    "BondEquipItemCinema",
    "BondSetLockedVelocity",
    "IFObjectInRoomWithPad",
    "IFImFiringAndLockedForward",
    "IFImFiring",
    "SwitchSky",
    "TriggerFadeAndExitLevelOnButtonPress",
    "IFBondIsDead",
    "BondDisableDamageAndPickups",
    "BondHideWeapons",
    "CameraOrbitPad",
    "CreditsRoll",
    "IFCreditsHasCompleted",
    "IFObjectiveAllCompleted",
    "IFFolderActorIsEqual",
    "IFBondDamageAndPickupsDisabled",
    "MusicPlaySlot",
    "MusicStopSlot",
    "TriggerExplosionsAroundBond",
    "IFKilledCiviliansGreaterThan",
    "IFChrWasShotSinceLastCheck",
    "BondKilledInAction",
    "RaiseArms",
    "GasLeakAndFadeFog",
    "ObjectRocketLaunch"};


#define MAX 10

int  top = -1;
char stack[MAX];

/*PUSH FUNCTION*/
int  push(int item)
{
    if (top == (MAX - 1))
    {
        return 0;
    }
    else
    {
        ++top;
        stack[top] = item;
        return 1;
    }
}

/*POP */
int pop()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        --top;
        return stack[top + 1];
    }
}

/*Sniff */
int sniff()
{
    if (top == -1)
    {
        return 0;
    }
    else
    {
        return stack[top];
    }
}

void displayStack()
{
    int i;

    printf("\nThe label Stack is: ");

    if (top == -1)
    {
        printf("empty");
    }
    else
    {
        for (i = top; i >= 0; --i)
        {
            printf("\n%3d", stack[i]);
        }
    }

    printf("\n---------------\n\n");
}

/**
 * @brief Parse AI list and print out C Macros
 * @param AiList: Bytestream for ai
 * @param ID: List ID
 */
void ai(unsigned char *AiList, short ID)
{
    for (int Offset = 0;;)
    {
        char tabs[MAX + 1];
        for (int k = 0; k < MAX; k++)
        {
            tabs[k] = 0;
        }
        for (int k = 0; k < top + 2 && k < MAX; k++)
        {
            tabs[k] = '\t';
        }

        switch (AiList[Offset])
        {
            case AI_GotoNext: // BYTE(LABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n\n");
                Offset += AI_GotoNext_LENGTH;
                break;
            }
            case AI_GotoFirst: // BYTE(LABEL)
            {
                if (AiList[Offset + 1] == sniff())
                {
                    pop();
                    for (int k = top + 2; k < MAX; k++)
                    {
                        tabs[k] = 0;
                    }
                    printf("%sLOOP(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                }

                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n\n");
                Offset += AI_GotoFirst_LENGTH;
                break;
            }
            case AI_Label: // BYTE(ID)
            {
                if (AiList[Offset + 2] == AI_Yield)
                {
                    if (AiList[Offset + 3] != AI_GotoFirst)
                    {
                        push(AiList[Offset + 1]);
                        printf("\n%sDO(", tabs);
                        printf("lbl%d", AiList[Offset + 1]);
                        Offset += AI_Yield_LENGTH;
                    }
                    else
                    {
                        printf("\n%sYIELD_FOREVER(", tabs);
                        printf("lbl%d", AiList[Offset + 1]);
                        Offset += AI_Yield_LENGTH + AI_GotoFirst_LENGTH;
                    }
                }
                else
                {
                    printf("\n%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("lbl%d", AiList[Offset + 1]);
                }
                printf(")\n");
                Offset += AI_Label_LENGTH;
                break;
            }
            case AI_Yield: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Yield_LENGTH;
                break;
            }
            case AI_EndList /*canonical name*/: // /*NONE*/
            {
                printf("\n%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n\n");
                return;
            }
            case AI_SetChrAiList: // BYTE(CHR_NUM), DBYTE(AI_LIST_ID)
            {
                unsigned short AI_LIST_ID = CharArrayTo16(AiList, (Offset + 1 + 1)); /* This is the only way to match despite assetrs below */
                signed char    CHR_NUM    = AiList[Offset + 1];

                if (CHR_NUM == CHR_SELF)
                {
                    if (AiList[Offset - AI_SetReturnAiList_LENGTH] == AI_SetReturnAiList &&
                        CharArrayTo16(AiList, Offset + 1 - AI_SetReturnAiList_LENGTH) == ID)
                    {
                        printf("%sCALL(", tabs);
                    }
                    else
                    {
                        printf("%sJumpTo(", tabs);
                    }
                }
                else if (CHR_NUM == CHR_BOND_CINEMA)
                {
                    printf("%sSetBondsAiList(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,", CHR_NUM);
                }

                if (isGlobalAIListID(AI_LIST_ID))
                {
                    printf("%s", GAILIST_ToString[AI_LIST_ID]);
                }
                else if (isBGAIListID(AI_LIST_ID))
                {
                    printf("setBGAIListID(%d)", getBGAIListID(AI_LIST_ID));
                }
                else
                {
                    printf("setChrAIListID(%d)", getChrAIListID(AI_LIST_ID));
                }
                printf(")\n");
                Offset += AI_SetChrAiList_LENGTH;
                break;
            }
            case AI_SetReturnAiList: // DBYTE(AI_LIST_ID)
            {
                unsigned short AI_LIST_ID = CharArrayTo16(AiList, (Offset + 1));

                if (!(AiList[Offset + AI_SetReturnAiList_LENGTH] == AI_SetChrAiList &&
                      AI_LIST_ID == ID &&
                      (signed char)AiList[Offset + AI_SetReturnAiList_LENGTH + 1] == CHR_SELF))
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d", AI_LIST_ID);
                    printf(")\n");
                }
                Offset += AI_SetReturnAiList_LENGTH;
                break;
            }
            case AI_Return: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Return_LENGTH;
                ;
                break;
            }
            case AI_Stop: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Stop_LENGTH;
                break;
            }
            case AI_Kneel: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Kneel_LENGTH;
                break;
            }
            case AI_PlayAnimation: // DBYTE(ANIMATION_ID), DBYTE(START_TIME30),DBYTE(END_TIME30), BYTE(BITFIELD), BYTE(INTERPOL_TIME60)
            {
                int startframe, anim_id, zero, endframe;

                anim_id    = CharArrayTo16(AiList, Offset + 1 + 0);
                startframe = CharArrayTo16(AiList, Offset + 1 + 2);
                endframe   = CharArrayTo16(AiList, Offset + 1 + 4);
                if (startframe == -1 && endframe == -1 && AiList[Offset + 1 + 6] == 6 && AiList[Offset + 1 + 7] == 16)
                {
                    printf("%sPlayAnimationSimple(", tabs);
                    printf("%d", anim_id);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,%d,%d,%d", anim_id, startframe, endframe, AiList[Offset + 1 + 6], AiList[Offset + 1 + 7]);
                }
                printf(")\n");
                Offset += AI_PlayAnimation_LENGTH;
                break;
            }
            case AI_IFPlayingAnimation: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFPlayingAnimation_LENGTH;
                break;
            }
            case AI_PointAtBond: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_PointAtBond_LENGTH;
                break;
            }
            case AI_LookSurprised: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_LookSurprised_LENGTH;
                break;
            }
            case AI_IFImOnPatrolOrStopped: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImOnPatrolOrStopped_LENGTH;
                break;
            }
            case AI_IFChrDyingOrDead: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                signed char chr = AiList[Offset + 1];
                if (chr == CHR_SELF)
                {
                    printf("%sIFImDyingOrDead(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,", chr);
                }
                printf("lbl%d", AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrDyingOrDead_LENGTH;
                break;
            }
            case AI_IFChrDoesNotExist: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                signed char chr = AiList[Offset + 1];
                if (chr == CHR_SELF)
                {
                    printf("%sIFIDoNotExist(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,", chr);
                }
                printf("lbl%d", AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrDoesNotExist_LENGTH;
                break;
            }
            case AI_IFISeeBond: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFISeeBond_LENGTH;
                break;
            }
            case AI_TRYSidestepping: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSidestepping_LENGTH;
                break;
            }
            case AI_TRYSideHopping: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSideHopping_LENGTH;

                break;
            }
            case AI_TRYSideRunning: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSideRunning_LENGTH;
                break;
            }
            case AI_TRYFiringWalk: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFiringWalk_LENGTH;
                break;
            }
            case AI_TRYFiringRun: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFiringRun_LENGTH;
                break;
            }
            case AI_TRYFiringRoll: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFiringRoll_LENGTH;
                break;
            }
            case AI_TRYFireOrAimAtTarget: // DBYTE(BITFIELD), DBYTE(TARGET), BYTE(GOTOLABEL)
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFireAtBond(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFireAtPad(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 33)
                {
                    printf("%sTRYAimAtBond(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 36)
                {
                    printf("%sTRYAimAtPad(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFireOrAimAtTarget_LENGTH;
                break;
            }
            case AI_TRYFireOrAimAtTargetKneel: // DBYTE(BITFIELD), DBYTE(TARGET), BYTE(GOTOLABEL)
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFireAtBondKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFireAtPadKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 33)
                {
                    printf("%sTRYAimAtBondKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 36)
                {
                    printf("%sTRYAimAtPadKneeling(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFireOrAimAtTargetKneel_LENGTH;
                break;
            }
            case AI_IFImFiringAndLockedForward: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImFiringAndLockedForward_LENGTH;
                break;
            }
            case AI_IFImFiring: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImFiring_LENGTH;
                break;
            }
            case AI_TRYFireOrAimAtTargetUpdate: // DBYTE(BITFIELD), DBYTE(TARGET), BYTE(GOTOLABEL)
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFireAtBondUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFireAtPadUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 33)
                {
                    printf("%sTRYAimAtBondUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 36)
                {
                    printf("%sTRYAimAtPadUpdate(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFireOrAimAtTargetUpdate_LENGTH;
                break;
            }
            case AI_TRYFacingTarget: // DBYTE(BITFIELD),DBYTE(TARGET),BYTE(GOTOLABEL)
            {
                int targetid   = CharArrayTo16(AiList, Offset + 1 + 2);
                int targettype = CharArrayTo16(AiList, Offset + 1 + 0);

                if (targettype == 1)
                {
                    printf("%sTRYFacingBond(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else if (targettype == 4)
                {
                    printf("%sTRYFacingPad(", tabs);
                    printf("lbl%d", AiList[Offset + 5]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,lbl%d", targettype, targetid, AiList[Offset + 5]);
                }
                printf(")\n");
                Offset += AI_TRYFacingTarget_LENGTH;
                break;
            }
            case AI_HitChrWithItem: // BYTE(CHR_NUM),BYTE(PART_NUM),BYTE(ITEM_NUM)
            {
                if (AiList[Offset + 1] == CHR_SELF)
                {
                    printf("%sHitMeWithItem(", tabs);
                    printf("%d,%d", AiList[Offset + 2], AiList[Offset + 1 + 2]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,%d", AiList[Offset + 1], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                }
                printf(")\n");

                Offset += AI_HitChrWithItem_LENGTH;
                break;
            }
            case AI_ChrHitChr: // BYTE(CHR_NUM),BYTE(CHR_NUM_TARGET),BYTE(PART_NUM)
            {
                if ((signed char)AiList[Offset + 1] == CHR_SELF)
                {
                    printf("%sIHitChr(", tabs);
                    printf("%d,%d", AiList[Offset + 2], AiList[Offset + 1 + 2]);
                }
                else if ((signed char)AiList[Offset + 2] == CHR_SELF)
                {
                    printf("%sChrHitMe(", tabs);
                    printf("%d,%d", AiList[Offset + 1], AiList[Offset + 1 + 2]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,%d,%d", AiList[Offset + 1], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                }
                printf(")\n");

                Offset += AI_ChrHitChr_LENGTH;
                break;
            }
            case AI_TRYThrowingGrenade: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_TRYThrowingGrenade_LENGTH;
                break;
            }
            case AI_TRYDroppingItem: // DBYTE(PROP_NUM),BYTE(ITEM_NUM),BYTE(GOTOLABEL)
            {
                unsigned short modelnum = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", modelnum, AiList[Offset + 1 + 2], AiList[Offset + 1 + 3]);
                printf(")\n");
                Offset += AI_TRYDroppingItem_LENGTH;
                break;
            }
            case AI_Surrender: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_Surrender_LENGTH;
                break;
            }
            case AI_RemoveMe: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_RemoveMe_LENGTH;
                break;
            }
            case AI_ChrRemoveInstant: // BYTE(CHR_NUM)
            {
                if ((signed char)AiList[Offset + 1] == CHR_SELF)
                {
                    printf("%sRemoveMeInstantly(", tabs);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d", AiList[Offset + 1]);
                }
                printf(")\n");
                Offset += AI_ChrRemoveInstant_LENGTH;
                break;
            }
            case AI_TRYTriggeringAlarmAtPad: // DBYTE(PAD),BYTE(GOTOLABEL)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d", AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_TRYTriggeringAlarmAtPad_LENGTH;
                break;
            }
            case AI_AlarmOn:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_AlarmOn_LENGTH;
                break;
            }
            case AI_AlarmOff:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_AlarmOff_LENGTH;
                break;
            }
            case AI_TRYRunFromBond: // BYTE(GOTOLABEL)
            {                       // run from bond

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYRunFromBond_LENGTH;
                break;
            }
            case AI_TRYRunToBond: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYRunToBond_LENGTH;
                break;
            }
            case AI_TRYWalkToBond: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_TRYWalkToBond_LENGTH;
                break;
            }
            case AI_TRYSprintToBond: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYSprintToBond_LENGTH;
                break;
            }
            case AI_TRYFindCover: // BYTE(GOTOLABEL)
            {                     // Find Cover
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_TRYFindCover_LENGTH;
                break;
            }
            case AI_TRYRunToChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYRunToChr_LENGTH;
                break;
            }
            case AI_TRYWalkToChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYWalkToChr_LENGTH;
                break;
            }
            case AI_TRYSprintToChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYSprintToChr_LENGTH;
                break;
            }
            case AI_SetNewRandom:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_SetNewRandom_LENGTH;
                break;
            }
            case AI_IFRandomLessThan: // BYTE(BYTE), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFRandomLessThan_LENGTH;
                break;
            }
            case AI_IFRandomGreaterThan: // BYTE(BYTE), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFRandomGreaterThan_LENGTH;
                break;
            }
            case AI_RunToPad: // DBYTE(PAD)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_RunToPad_LENGTH;
                break;
            }
            case AI_RunToPadPreset: // /*NONE*/
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_RunToPadPreset_LENGTH;
                break;
            }
            case AI_WalkToPad: // DBYTE(PAD)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_WalkToPad_LENGTH;
                break;
            }
            case AI_SprintToPad: // DBYTE(PAD)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_SprintToPad_LENGTH;
                break;
            }
            case AI_StartPatrol: // BYTE(PATH_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_StartPatrol_LENGTH;
                break;
            }
            case AI_IFICanHearAlarm: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFICanHearAlarm_LENGTH;
                break;
            }
            case AI_IFAlarmIsOn: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFAlarmIsOn_LENGTH;
                break;
            }
            case AI_IFGasIsLeaking: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFGasIsLeaking_LENGTH;
                break;
            }
            case AI_IFIHeardBond: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIHeardBond_LENGTH;
                break;
            }
            case AI_IFISeeSomeoneShot: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFISeeSomeoneShot_LENGTH;
                break;
            }
            case AI_IFISeeSomeoneDie: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFISeeSomeoneDie_LENGTH;
                break;
            }
            case AI_IFICouldSeeBond: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFICouldSeeBond_LENGTH;
                break;
            }
            case AI_IFICouldSeeBondsStan: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFICouldSeeBondsStan_LENGTH;
                break;
            }
            case AI_IFIWasShotRecently: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIWasShotRecently_LENGTH;
                break;
            }
            case AI_IFIHeardBondRecently: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIHeardBondRecently_LENGTH;
                break;
            }
            case AI_IFImInRoomWithChr: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFImInRoomWithChr_LENGTH;
                break;
            }
            case AI_IFIveNotBeenSeen:// BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFIveNotBeenSeen_LENGTH;
                break;
            }
            case AI_IFImOnScreen:// BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImOnScreen_LENGTH;
                break;
            }
            case AI_IFMyRoomIsOnScreen:// BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyRoomIsOnScreen_LENGTH;
                break;
            }
            case AI_IFRoomWithPadIsOnScreen: // DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 3]);
                Offset += AI_IFRoomWithPadIsOnScreen_LENGTH;
                break;
            }
            case AI_IFImTargetedByBond: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFImTargetedByBond_LENGTH;
                break;
            }
            case AI_IFBondMissedMe: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFBondMissedMe_LENGTH;
                break;
            }
            case AI_IFMyAngleToBondLessThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleToBondLessThan_LENGTH;
                break;
            }
            case AI_IFMyAngleToBondGreaterThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleToBondGreaterThan_LENGTH;
                break;
            }
            case AI_IFMyAngleFromBondLessThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleFromBondLessThan_LENGTH;
                break;
            }
            case AI_IFMyAngleFromBondGreaterThan: // BYTE(ANGLE), BYTE(GOTOLABEL)
            {
                printf("%s%sDeg(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", RadToDeg(ByteToRadian((AiList[Offset + 1 + 0]))), AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAngleFromBondGreaterThan_LENGTH;
                break;
            }
            case AI_IFMyDistanceToBondLessThanDecimeter: // DBYTE(DISTANCE), BYTE(GOTOLABEL)
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFMyDistanceToBondLessThanMeter");
                printf("%f,lbl%d", distance / 100, AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFMyDistanceToBondLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFMyDistanceToBondGreaterThanDecimeter: // DBYTE(DISTANCE), BYTE(GOTOLABEL)
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFMyDistanceToBondGreaterThanMeter");
                printf("%f,lbl%d", distance / 100, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFMyDistanceToBondGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_IFChrDistanceToPadLessThanDecimeter: // BYTE(CHR_NUM), DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 3);
                float          value = CharArrayTo16(AiList, Offset + 1 + 1) * 10.0f;

                if ((signed char)AiList[Offset + 1 + 0] == CHR_SELF)
                {
                    printf("%sIFMyDistanceToPadLessThanMeter(", tabs);
                    printf("%f,", value / 100);
                }
                else
                {
                    printf("%sIFChrDistanceToPadLessThanMeter(", tabs);
                    printf("%d,%f,", AiList[Offset + 1 + 0], value / 100);
                }
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d", AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFChrDistanceToPadLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFChrDistanceToPadGreaterThanDecimeter: // BYTE(CHR_NUM), DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 3);
                float          value = CharArrayTo16(AiList, Offset + 1 + 1) * 10.0f;

                if ((signed char)AiList[Offset + 1 + 0] == CHR_SELF)
                {
                    printf("%sIFMyDistanceToPadGreaterThanMeter(", tabs);
                    printf("%f,", value / 100);
                }
                else
                {
                    printf("%sIFChrDistanceToPadGreaterThanMeter(", tabs);
                    printf("%d,%f,", AiList[Offset + 1 + 0], value / 100);
                }
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d", AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFChrDistanceToPadGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_IFMyDistanceToChrLessThanDecimeter: // DBYTE(DISTANCE), BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                float cutoff = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "AIFMyDistanceToChrLessThanMeter");
                printf("%f,%d,lbl%d", cutoff / 100, AiList[Offset + 3], AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyDistanceToChrLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFMyDistanceToChrGreaterThanDecimeter: // DBYTE(DISTANCE), BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                float cutoff = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "AIFMyDistanceToChrGreaterThanMeter");
                printf("%f,%d,lbl%d", cutoff / 100, AiList[Offset + 3], AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyDistanceToChrGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_TRYSettingMyPresetToChrWithinDistanceDecimeter: // DBYTE(DISTANCE), BYTE(GOTOLABEL)
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "TRYSettingMyPresetToChrWithinDistanceMeter");
                printf("%f,lbl%d", distance / 100, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_TRYSettingMyPresetToChrWithinDistanceDecimeter_LENGTH;
                break;
            }
            case AI_IFBondDistanceToPadLessThanDecimeter: // DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 2);
                float          value = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFBondDistanceToPadLessThanMeter");
                printf("%f,", value / 100);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 5]);
                Offset += AI_IFBondDistanceToPadLessThanDecimeter_LENGTH;
                break;
            }
            case AI_IFBondDistanceToPadGreaterThanDecimeter: // DBYTE(DISTANCE), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 1 + 2);
                float          value = CharArrayTo16(AiList, Offset + 1 + 0) * 10.0f;

                printf("%s%s(", tabs, "IFBondDistanceToPadGreaterThanMeter");
                printf("%f,", value / 100);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 5]);
                Offset += AI_IFBondDistanceToPadGreaterThanDecimeter_LENGTH;
                break;
            }
            case AI_IFChrInRoomWithPad: // BYTE(CHR_NUM), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1 + 0]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 4]);
                Offset += AI_IFChrInRoomWithPad_LENGTH;
                break;
            }
            case AI_IFBondInRoomWithPad: // DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("lbl%d)\n", AiList[Offset + 3]);
                Offset += AI_IFBondInRoomWithPad_LENGTH;
                break;
            }
            case AI_IFBondCollectedObject: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondCollectedObject_LENGTH;
                break;
            }
            case AI_IFItemIsStationaryWithinLevel: // BYTE(ITEM_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFItemIsStationaryWithinLevel_LENGTH;
                break;
            }
            case AI_IFItemIsAttachedToObject: // BYTE(ITEM_NUM), BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFItemIsAttachedToObject_LENGTH;
                break;
            }
            case AI_IFBondHasItemEquipped: // BYTE(ITEM_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondHasItemEquipped_LENGTH;
                break;
            }
            case AI_IFObjectExists: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFObjectExists_LENGTH;
                break;
            }
            case AI_IFObjectNotDestroyed:// BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFObjectNotDestroyed_LENGTH;
                break;
            }
            case AI_IFObjectWasActivated:// BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFObjectWasActivated_LENGTH;
                break;
            }
            case AI_IFBondUsedGadgetOnObject:// BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFBondUsedGadgetOnObject_LENGTH;
                break;
            }
            case AI_ActivateObject: // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_ActivateObject_LENGTH;
                break;
            }
            case AI_DestroyObject:  // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_DestroyObject_LENGTH;
                break;
            }
            case AI_DropObject: // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DropObject_LENGTH;
                break;
            }
            case AI_ChrDropAllConcealedItems: // BYTE(CHR_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_ChrDropAllConcealedItems_LENGTH;
                break;
            }
            case AI_ChrDropAllHeldItems: // BYTE(CHR_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_ChrDropAllHeldItems_LENGTH;
                break;
            }
            case AI_BondCollectObject: // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_BondCollectObject_LENGTH;
                break;
            }
            case AI_ChrEquipObject: // BYTE(OBJECT_TAG), BYTE(CHR_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_ChrEquipObject_LENGTH;
                break;
            }
            case AI_MoveObject: // BYTE(OBJECT_TAG), DBYTE(PAD)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                Offset += AI_MoveObject_LENGTH;
                break;
            }
            case AI_DoorOpen: // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DoorOpen_LENGTH;
                break;
            }
            case AI_DoorClose: // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DoorClose_LENGTH;
                break;
            }
            case AI_IFDoorStateEqual: // BYTE(OBJECT_TAG), BYTE(DOOR_STATE), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%s,lbl%d", AiList[Offset + 1], DOORSTATE_ToString[AiList[Offset + 2] >> 1], AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFDoorStateEqual_LENGTH;
                break;
            }
            case AI_IFDoorHasBeenOpenedBefore: // BYTE(OBJECT_TAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFDoorHasBeenOpenedBefore_LENGTH;
                break;
            }
            case AI_DoorSetLock: // BYTE(OBJECT_TAG), BYTE(LOCK_FLAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_DoorSetLock_LENGTH;
                break;
            }
            case AI_DoorUnsetLock: // BYTE(OBJECT_TAG), BYTE(LOCK_FLAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_DoorUnsetLock_LENGTH;
                break;
            }
            case AI_IFDoorLockEqual: // BYTE(OBJECT_TAG), BYTE(LOCK_FLAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFDoorLockEqual_LENGTH;
                break;
            }
            case AI_IFObjectiveNumComplete: // BYTE(OBJ_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFObjectiveNumComplete_LENGTH;
                break;
            }
            case AI_TRYUnknown6e: // BYTE(UNKNOWN_FLAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYUnknown6e_LENGTH;
                break;
            }
            case AI_TRYUnknown6f: // BYTE(UNKNOWN_FLAG), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_TRYUnknown6f_LENGTH;
                break;
            }
            case AI_IFMyNumArghsLessThan: // BYTE(HIT_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumArghsLessThan_LENGTH;
                break;
            }
            case AI_IFMyNumArghsGreaterThan: // BYTE(HIT_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumArghsGreaterThan_LENGTH;
                break;
            }
            case AI_IFMyNumCloseArghsLessThan: // BYTE(MISSED_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumCloseArghsLessThan_LENGTH;
                break;
            }
            case AI_IFMyNumCloseArghsGreaterThan: // BYTE(MISSED_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyNumCloseArghsGreaterThan_LENGTH;
                break;
            }
            case AI_IFChrHealthLessThan: // BYTE(CHR_NUM), BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                float value = (AiList[Offset + 1 + 1]) * 0.1f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f,lbl%d", AiList[Offset + 1], value * 10, AiList[Offset + 3]);
                printf(")\n");

                Offset += AI_IFChrHealthLessThan_LENGTH;
                break;
            }
            case AI_IFChrHealthGreaterThan: // BYTE(CHR_NUM), BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                float value = (AiList[Offset + 1 + 1]) * 0.1f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f,lbl%d", AiList[Offset + 1], value * 10, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFChrHealthGreaterThan_LENGTH;
                break;
            }
            case AI_IFChrWasDamagedSinceLastCheck: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrWasDamagedSinceLastCheck_LENGTH;
                break;
            }
            case AI_IFBondHealthLessThan: // BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                float val = (AiList[Offset + 1 + 0]) / 255.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", val * 255, AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondHealthLessThan_LENGTH;
                break;
            }
            case AI_IFBondHealthGreaterThan: // BYTE(HEALTH), BYTE(GOTOLABEL)
            {
                float val = (AiList[Offset + 1 + 0]) / 255.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", val * 255, AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFBondHealthGreaterThan_LENGTH;
                break;
            }
            case AI_IFGameDifficultyLessThan: // BYTE(DIFICULTY_ID), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFGameDifficultyLessThan_LENGTH;
                break;
            }
            case AI_IFGameDifficultyGreaterThan: // BYTE(DIFICULTY_ID), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFGameDifficultyGreaterThan_LENGTH;
                break;
            }
            case AI_IFMissionTimeLessThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFMissionTimeLessThan_LENGTH;
                break;
            }
            case AI_IFMissionTimeGreaterThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFMissionTimeGreaterThan_LENGTH;
                break;
            }
            case AI_IFSystemPowerTimeLessThan: // DBYTE(MINUTES), BYTE(GOTOLABEL)
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFSystemPowerTimeLessThan_LENGTH;
                break;
            }
            case AI_IFSystemPowerTimeGreaterThan: // DBYTE(MINUTES), BYTE(GOTOLABEL)
            {
                float target = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", target, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFSystemPowerTimeGreaterThan_LENGTH;
                break;
            }
            case AI_IFLevelIdLessThan: // BYTE(LEVEL_ID), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFLevelIdLessThan_LENGTH;
                break;
            }
            case AI_IFLevelIdGreaterThan: // BYTE(LEVEL_ID), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFLevelIdGreaterThan_LENGTH;
                break;
            }
            case AI_SetMyMorale:// BYTE(CHRBYTE)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyMorale_LENGTH;
                break;
            }
            case AI_AddToMyMorale:// BYTE(CHRBYTE)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");

                Offset += AI_AddToMyMorale_LENGTH;
                break;
            }
            case AI_SubtractFromMyMorale:// BYTE(CHRBYTE)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SubtractFromMyMorale_LENGTH;
                break;
            }
            case AI_IFMyMoraleLessThan: // BYTE(CHRBYTE), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");

                Offset += AI_IFMyMoraleLessThan_LENGTH;
                break;
            }
            case AI_IFMyMoraleLessThanRandom:// BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyMoraleLessThanRandom_LENGTH;
                break;
            }
            case AI_SetMyAlertness: // BYTE(CHRBYTE)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyAlertness_LENGTH;
                break;
            }
            case AI_AddToMyAlertness: // BYTE(CHRBYTE)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_AddToMyAlertness_LENGTH;
                break;
            }
            case AI_SubtractFromMyAlertness: // BYTE(CHRBYTE)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SubtractFromMyAlertness_LENGTH;
                break;
            }
            case AI_IFMyAlertnessLessThan: // BYTE(CHRBYTE), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyAlertnessLessThan_LENGTH;
                break;
            }
            case AI_IFMyAlertnessLessThanRandom: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyAlertnessLessThanRandom_LENGTH;
                break;
            }
            case AI_SetMyHearingScale: // DBYTE(HEARING_SCALE)
            {
                float distance = CharArrayTo16(AiList, Offset + 1 + 0) / 1000.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", distance * 1000);
                printf(")\n");
                Offset += AI_SetMyHearingScale_LENGTH;
                break;
            }
            case AI_SetMyVisionRange:// BYTE(VISION_RANGE)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyVisionRange_LENGTH;
                break;
            }
            case AI_SetMyGrenadeProbability: // BYTE(GRENADE_PROB)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyGrenadeProbability_LENGTH;
                break;
            }
            case AI_SetMyChrNum: // BYTE(CHR_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyChrNum_LENGTH;
                break;
            }
            case AI_SetMyHealthTotal: // DBYTE(HEALTH)
            {
                float amount = CharArrayTo16(AiList, Offset + 1 + 0) * 0.1f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", amount * 10);
                printf(")\n");
                Offset += AI_SetMyHealthTotal_LENGTH;
                break;
            }
            case AI_SetMyArmour: // DBYTE(AMOUNT)
            {
                float amount = CharArrayTo16(AiList, Offset + 1 + 0) * 0.1f; /*if (cheatIsActive(CHEAT_ENEMYSHIELDS)) { amount = amount < 8 ? 8 : amount; } */

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", amount * 10);
                printf(")\n");
                Offset += AI_SetMyArmour_LENGTH;
                break;
            }
            case AI_SetMySpeedRating: // BYTE(SPEED_RATING)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMySpeedRating_LENGTH;
                break;
            }
            case AI_SetMyArghRating: // BYTE(ARGH_RATING)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyArghRating_LENGTH;
                break;
            }
            case AI_SetMyAccuracyRating: // BYTE(ACCURACY_RATING)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyAccuracyRating_LENGTH;
                break;
            }
            case AI_SetMyFlags2:// BYTE(BITS)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyFlags2_LENGTH;
                break;
            }
            case AI_UnsetMyFlags2:// BYTE(BITS)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_UnsetMyFlags2_LENGTH;
                break;
            }
            case AI_IFMyFlags2Has:// BYTE(BITS) BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFMyFlags2Has_LENGTH;
                break;
            }
            case AI_SetChrBitfield:// BYTE(CHR_NUM), BYTE(BITS)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_SetChrBitfield_LENGTH;
                break;
            }
            case AI_UnsetChrBitfield:// BYTE(CHR_NUM), BYTE(BITS)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_UnsetChrBitfield_LENGTH;
                break;
            }
            case AI_IFChrBitfieldHas: // BYTE(CHR_NUM), BYTE(BITS), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFChrBitfieldHas_LENGTH;
                break;
            }
            case AI_SetObjectiveBitfield: // QBYTE(BITFIELD)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_SetObjectiveBitfield_LENGTH;
                break;
            }
            case AI_UnsetObjectiveBitfield: // QBYTE(BITFIELD)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_UnsetObjectiveBitfield_LENGTH;
                break;
            }
            case AI_IFObjectiveBitfieldHas:// QBYTE(BITS), BYTE(GOTOLABEL)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x,lbl%d", flags, AiList[Offset + 5]);
                printf(")\n");
                Offset += AI_IFObjectiveBitfieldHas_LENGTH;
                break;
            }
            case AI_SetMychrflags:// QBYTE(CHRFLAGS)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_SetMychrflags_LENGTH;
                break;
            }
            case AI_UnsetMychrflags:// QBYTE(CHRFLAGS)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x", flags);
                printf(")\n");
                Offset += AI_UnsetMychrflags_LENGTH;
                break;
            }
            case AI_IFMychrflagsHas: // QBYTE(CHRFLAGS), BYTE(GOTOLABEL)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("0x%x,lbl%d", flags, AiList[Offset + 5]);
                printf(")\n");
                Offset += AI_IFMychrflagsHas_LENGTH;
                break;
            }
            case AI_SetChrchrflags: // BYTE(CHR_NUM), QBYTE(CHRFLAGS)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_SetChrchrflags_LENGTH;
                break;
            }
            case AI_UnsetChrchrflags: // BYTE(CHR_NUM), QBYTE(CHRFLAGS)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_UnsetChrchrflags_LENGTH;
                break;
            }
            case AI_IFChrchrflagsHas: // BYTE(CHR_NUM), QBYTE(CHRFLAGS), BYTE(GOTOLABEL)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], flags, AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFChrchrflagsHas_LENGTH;
                break;
            }
            case AI_SetObjectFlags: // BYTE(OBJECT_TAG), QBYTE(BITFIELD)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_SetObjectFlags_LENGTH;
                break;
            }
            case AI_UnsetObjectFlags: // BYTE(OBJECT_TAG), QBYTE(BITFIELD)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_UnsetObjectFlags_LENGTH;
                break;
            }
            case AI_IFObjectFlagsHas: // BYTE(OBJECT_TAG), QBYTE(BITS), BYTE(GOTOLABEL)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], flags, AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFObjectFlagsHas_LENGTH;
                break;
            }
            case AI_SetObjectFlags2: // BYTE(OBJECT_TAG), QBYTE(BITS)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_SetObjectFlags2_LENGTH;
                break;
            }
            case AI_UnsetObjectFlags2: // BYTE(OBJECT_TAG), QBYTE(BITS)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x", AiList[Offset + 1], flags);
                printf(")\n");
                Offset += AI_UnsetObjectFlags2_LENGTH;
                break;
            }
            case AI_IFObjectFlags2Has: // BYTE(OBJECT_TAG), QBYTE(BITFIELD), BYTE(GOTOLABEL)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", AiList[Offset + 1], flags, AiList[Offset + 6]);
                printf(")\n");
                Offset += AI_IFObjectFlags2Has_LENGTH;
                break;
            }
            case AI_SetMyChrPreset: // BYTE(CHR_PRESET)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_SetMyChrPreset_LENGTH;
                break;
            }
            case AI_SetChrChrPreset: // BYTE(CHR_NUM), BYTE(CHR_PRESET)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_SetChrChrPreset_LENGTH;
                break;
            }
            case AI_SetMyPadPreset: // DBYTE(PAD_PRESET)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_SetMyPadPreset_LENGTH;
                break;
            }
            case AI_SetChrPadPreset: // BYTE(CHR_NUM), DBYTE(PAD_PRESET)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s(%d,", AI_CMD_ToString[AiList[Offset]], AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d)", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_SetChrPadPreset_LENGTH;
                break;
            }
            case AI_PRINT:
            {
                int j = 1;
                printf("%sPRINT(\"", tabs);

                for (; AiList[Offset + j] != 0; j++)
                {
                    if (AiList[Offset + j] == '\n')
                    {
                        printf("\\n");
                    }
                    else
                    {
                        printf("%c", AiList[Offset + j]);
                    }
                }
                Offset += j + 1;
                printf("\")\n");
                break;
            }
            case AI_MyTimerStart:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerStart_LENGTH;
                break;
            }
            case AI_MyTimerReset:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerReset_LENGTH;
                break;
            }
            case AI_MyTimerPause:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerPause_LENGTH;
                break;
            }
            case AI_MyTimerResume:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_MyTimerResume_LENGTH;
                break;
            }
            case AI_IFMyTimerIsNotRunning: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFMyTimerIsNotRunning_LENGTH;
                break;
            }
            case AI_IFMyTimerLessThanTicks: // TBYTE(TICKS), BYTE(GOTOLABEL)
            {
                float valf = ((unsigned)CharArrayTo24(AiList, Offset + 1 + 0));

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", valf, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyTimerLessThanTicks_LENGTH;
                break;
            }
            case AI_IFMyTimerGreaterThanTicks: // TBYTE(TICKS), BYTE(GOTOLABEL)
            {
                float valf = ((unsigned)CharArrayTo24(AiList, Offset + 1 + 0));

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", valf, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFMyTimerGreaterThanTicks_LENGTH;
                break;
            }
            case AI_HudCountdownShow:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownShow_LENGTH;
                break;
            }
            case AI_HudCountdownHide:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownHide_LENGTH;
                break;
            }
            case AI_HudCountdownSet: // DBYTE(SECONDS)
            {
                float seconds = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f", seconds);
                printf(")\n");
                Offset += AI_HudCountdownSet_LENGTH;
                break;
            }
            case AI_HudCountdownStop:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownStop_LENGTH;
                break;
            }
            case AI_HudCountdownStart:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HudCountdownStart_LENGTH;
                break;
            }
            case AI_IFHudCountdownIsNotRunning: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFHudCountdownIsNotRunning_LENGTH;
                break;
            }
            case AI_IFHudCountdownLessThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                float value = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", value, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFHudCountdownLessThan_LENGTH;
                break;
            }
            case AI_IFHudCountdownGreaterThan: // DBYTE(SECONDS), BYTE(GOTOLABEL)
            {
                float value = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,lbl%d", value, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFHudCountdownGreaterThan_LENGTH;
                break;
            }
            case AI_TRYSpawningChrAtPad: // BYTE(BODY_NUM), BYTE(HEAD_NUM), DBYTE(PAD), DBYTE(AI_LIST_ID), QBYTE(BITFIELD), BYTE(GOTOLABEL)
            {
                unsigned short pad      = CharArrayTo16(AiList, Offset + 1 + 2);
                int            flags    = CharArrayTo32(AiList, Offset + 1 + 6);
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 4);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("%d,0x%x,%d,lbl%d", ailistid, flags, AiList[Offset + 10], AiList[Offset + 11]);
                printf(")\n");
                Offset += AI_TRYSpawningChrAtPad_LENGTH;
                break;
            }
            case AI_TRYSpawningChrNextToChr: // BYTE(BODY_NUM), BYTE(HEAD_NUM), BYTE(CHR_NUM_TARGET), DBYTE(AI_LIST_ID), QBYTE(BITFIELD), BYTE(GOTOLABEL)
            {
                int            flags    = CharArrayTo32(AiList, Offset + 1 + 5);
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 3);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d,%d,0x%x,lbl%d", AiList[Offset + 1], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2], ailistid, flags, AiList[Offset + 10]);
                printf(")\n");
                Offset += AI_TRYSpawningChrNextToChr_LENGTH;
                break;
            }
            case AI_TRYGiveMeItem: // DBYTE(PROP_NUM), BYTE(ITEM_NUM), QBYTE(PROPFLAG), BYTE(GOTOLABEL)
            {
                int flags = CharArrayTo32(AiList, Offset + 1 + 3);
                int model = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,0x%x,lbl%d", model, AiList[Offset + 1 + 2], flags, AiList[Offset + 8]);
                printf(")\n");
                Offset += AI_TRYGiveMeItem_LENGTH;
                break;
            }
            case AI_TRYGiveMeHat: // DBYTE(PROP_NUM), QBYTE(PROP_BITFIELD), BYTE(GOTOLABEL)
            {
                int flags    = CharArrayTo32(AiList, Offset + 1 + 2);
                int modelnum = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,0x%x,lbl%d", modelnum, flags, AiList[Offset + 7]);
                printf(")\n");
                Offset += AI_TRYGiveMeHat_LENGTH;
                break;
            }
            case AI_TRYCloningChr: // BYTE(CHR_NUM), DBYTE(AI_LIST_ID), BYTE(GOTOLABEL)
            {
                unsigned short ailistid = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", AiList[Offset + 4], ailistid, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_TRYCloningChr_LENGTH;
                break;
            }
            case AI_TextPrintBottom:// DBYTE(TEXT_SLOT)
            {
                printf("//USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", 0, CharArrayTo16(AiList, Offset + 1 + 0));
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("TEXT(%d,%d)", (CharArrayTo16(AiList, Offset + 1 + 0)) / 1024, (CharArrayTo16(AiList, Offset + 1 + 0)) % 1024);
                printf(")\n");
                Offset += AI_TextPrintBottom_LENGTH;
                break;
            }
            case AI_TextPrintTop:// DBYTE(TEXT_SLOT)
            {
                printf("//USING HUD MESSAGE Stringy = %d, ai->txt = %d\n", 0, CharArrayTo16(AiList, Offset + 1 + 0));
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("TEXT(%d,%d)", (CharArrayTo16(AiList, Offset + 1 + 0)) / 1024, (CharArrayTo16(AiList, Offset + 1 + 0)) % 1024);
                printf(")\n");
                Offset += AI_TextPrintTop_LENGTH;
                break;
            }
            case AI_SfxPlay: // DBYTE(SOUND_NUM), BYTE(CHANNEL_NUM)
            {
                short audio_id = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", audio_id, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_SfxPlay_LENGTH;
                break;
            }
            case AI_SfxStopChannel: // BYTE(CHANNEL_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_SfxStopChannel_LENGTH;
                break;
            }
            case AI_SfxSetChannelVolume: // BYTE(CHANNEL_NUM), DBYTE(TARGET_VOLUME), DBYTE(TRANSITION_TIME60)
            {
                short          vol   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,%d", AiList[Offset + 1], vol, sfxID);
                printf(")\n");
                Offset += AI_SfxSetChannelVolume_LENGTH;
                break;
            }
            case AI_SfxFadeChannelVolume: // BYTE(CHANNEL_NUM), DBYTE(TARGET_VOLUME), DBYTE(TRANSITION_TIME60)
            {
                short          vol   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,%d", AiList[Offset + 1], vol, sfxID);
                printf(")\n");

                Offset += AI_SfxFadeChannelVolume_LENGTH;
                break;
            }
            case AI_SfxEmitFromObject: // BYTE(CHANNEL_NUM), BYTE(OBJECT_TAG), DBYTE(VOL_DECAY_TIME60)
            {
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,%d", AiList[Offset + 1], AiList[Offset + 2], sfxID);
                printf(")\n");
                Offset += AI_SfxEmitFromObject_LENGTH;
                break;
            }
            case AI_SfxEmitFromPad: // BYTE(CHANNEL_NUM), DBYTE(PAD), DBYTE(VOL_DECAY_TIME60)
            {
                unsigned short pad   = CharArrayTo16(AiList, Offset + 2 + 0);
                unsigned short sfxID = CharArrayTo16(AiList, Offset + 2 + 2);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);

                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf("%d", sfxID);
                printf(")\n");
                Offset += AI_SfxEmitFromPad_LENGTH;
                break;
            }
            case AI_IFSfxChannelVolumeLessThan: // BYTE(CHANNEL_NUM), DBYTE(VOLUME), BYTE(GOTOLABEL)
            {
                short vol = CharArrayTo16(AiList, Offset + 2 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d, %d,lbl%d", AiList[Offset + 1], vol, AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFSfxChannelVolumeLessThan_LENGTH;
                break;
            }
            case AI_VehicleStartPath: // BYTE(PATH_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                Offset += AI_VehicleStartPath_LENGTH;
                break;
            }
            case AI_VehicleSpeed: // DBYTE(TOP_SPEED), DBYTE(ACCELERATION_TIME60)
            {
                float speedtime = CharArrayTo16(AiList, Offset + 1 + 2);
                float speedaim  = CharArrayTo16(AiList, Offset + 1 + 0) * 100.0f / 15360.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f", CharArrayTo16(AiList, Offset + 1 + 0), speedtime);
                printf(")\n");
                Offset += AI_VehicleSpeed_LENGTH;
                break;
            }
            case AI_AircraftRotorSpeed: // DBYTE(ROTOR_SPEED), DBYTE(ACCELERATION_TIME60)
            {
                float speedtime = CharArrayTo16(AiList, Offset + 1 + 2);
                float speedaim  = CharArrayTo16(AiList, Offset + 1 + 0) * M_TAU_F / 3600.0f;

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%f", CharArrayTo16(AiList, Offset + 1 + 0), speedtime);
                printf(")\n");
                Offset += AI_AircraftRotorSpeed_LENGTH;
                break;
            }
            case AI_IFCameraIsInIntro: // BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                Offset += AI_IFCameraIsInIntro_LENGTH;
                break;
            }
            case AI_IFCameraIsInBondSwirl:// BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                Offset += AI_IFCameraIsInBondSwirl_LENGTH;
                break;
            }
            case AI_TvChangeScreenBank: // BYTE(OBJECT_TAG), BYTE(SCREEN_INDEX), BYTE(SCREEN_BANK)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,$d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_TvChangeScreenBank_LENGTH;
                break;
            }
            case AI_IFBondInTank: // canonical name
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1 + 0]);
                printf(")\n");

                Offset += AI_IFBondInTank_LENGTH;
                break;
            }
            case AI_EndLevel: // canonical name
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_EndLevel_LENGTH;
                break;
            }
            case AI_CameraReturnToBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_CameraReturnToBond_LENGTH;
                break;
            }
            case AI_CameraLookAtBondFromPad: // DBYTE(PAD)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);

                if (isNotBoundPad(pad))
                {
                    printf("%d", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }
                printf(")\n");
                Offset += AI_CameraLookAtBondFromPad_LENGTH;
                break;
            }
            case AI_CameraSwitch: // BYTE(OBJECT_TAG), DBYTE(LOOK_AT_BOND_FLAG), DBYTE(UNUSED_FLAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d", AiList[Offset + 1 + 0], CharArrayTo16(AiList, Offset + 1 + 1), CharArrayTo16(AiList, Offset + 1 + 3));
                printf(")\n");
                Offset += AI_CameraSwitch_LENGTH;
                break;
            }
            case AI_IFBondYPosLessThan: // DBYTE(Y_POS), BYTE(GOTOLABEL)
            {
                float bondpos = (short)CharArrayTo16(AiList, Offset + 1 + 0);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%f,%d", bondpos, AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFBondYPosLessThan_LENGTH;
                break;
            }
            case AI_BondDisableControl: // BYTE(BITFIELD)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_BondDisableControl_LENGTH;
                break;
            }
            case AI_BondEnableControl:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondEnableControl_LENGTH;
                break;
            }
            case AI_TRYTeleportingChrToPad: // BYTE(CHR_NUM), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                int pad = CharArrayTo16(AiList, Offset + 1 + 1);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("lbl%d", AiList[Offset + 4]);
                printf(")\n");

                Offset += AI_TRYTeleportingChrToPad_LENGTH;
                break;
            }
            case AI_ScreenFadeToBlack:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_ScreenFadeToBlack_LENGTH;
                break;
            }
            case AI_ScreenFadeFromBlack:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_ScreenFadeFromBlack_LENGTH;
                break;
            }
            case AI_IFScreenFadeCompleted:// BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFScreenFadeCompleted_LENGTH;
                break;
            }
            case AI_HideAllChrs:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_HideAllChrs_LENGTH;
                break;
            }
            case AI_ShowAllChrs:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_ShowAllChrs_LENGTH;
                break;
            }
            case AI_DoorOpenInstant: // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_DoorOpenInstant_LENGTH;
                break;
            }
            case AI_ChrRemoveItemInHand: // BYTE(CHR_NUM), BYTE(HAND_INDEX)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%s", AiList[Offset + 1], AiList[Offset + 2] == 0 ? "GUNRIGHT" : "GUNLEFT");
                printf(")\n");
                Offset += AI_ChrRemoveItemInHand_LENGTH;
                break;
            }
            case AI_IfNumberOfActivePlayersLessThan: // BYTE(NUMBER), BYTE(GOTOLABEL)
            {
                if (AiList[Offset + 1] == 2)
                {
                    printf("%sIFSinglePlayer(", tabs);
                    printf("lbl%d", AiList[Offset + 2]);
                }
                else
                {
                    printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                    printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                }
                printf(")\n");
                Offset += AI_IfNumberOfActivePlayersLessThan_LENGTH;
                break;
            }
            case AI_IFBondItemTotalAmmoLessThan: // BYTE(ITEM_NUM), BYTE(AMMO_TOTAL), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2], AiList[Offset + 3]);
                printf(")\n");
                Offset += AI_IFBondItemTotalAmmoLessThan_LENGTH;
                break;
            }
            case AI_BondEquipItem: // BYTE(ITEM_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_BondEquipItem_LENGTH;
                break;
            }
            case AI_BondEquipItemCinema: // BYTE(ITEM_NUM)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_BondEquipItemCinema_LENGTH;
                break;
            }
            case AI_BondSetLockedVelocity: // BYTE(X_SPEED60), BYTE(Z_SPEED60)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_BondSetLockedVelocity_LENGTH;
                break;
            }
            case AI_IFObjectInRoomWithPad: // BYTE(OBJECT_TAG), DBYTE(PAD), BYTE(GOTOLABEL)
            {
                unsigned short pad = CharArrayTo16(AiList, Offset + 1 + 1);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,", AiList[Offset + 1]);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("lbl%d", AiList[Offset + 4]);
                printf(")\n");
                Offset += AI_IFObjectInRoomWithPad_LENGTH;
                break;
            }
            case AI_SwitchSky:
            { // SWITCHENVIRONMENT
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_SwitchSky_LENGTH;
                break;
            }
            case AI_TriggerFadeAndExitLevelOnButtonPress:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_TriggerFadeAndExitLevelOnButtonPress_LENGTH;
                break;
            }
            case AI_IFBondIsDead:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFBondIsDead_LENGTH;
                break;
            }
            case AI_BondDisableDamageAndPickups:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondDisableDamageAndPickups_LENGTH;
                break;
            }
            case AI_BondHideWeapons:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondHideWeapons_LENGTH;
                break;
            }
            case AI_CameraOrbitPad: 
            {
                int pad;
                int speed60;
                int camDististance;
                int targetHeight;
                int camHeight;
                int start;
                camDististance = CharArrayTo16(AiList, Offset + 1 + 0);
                camHeight      = (short)CharArrayTo16(AiList, Offset + 1 + 2);
                speed60        = (short)CharArrayTo16(AiList, Offset + 1 + 4);
                pad            = CharArrayTo16(AiList, Offset + 1 + 6);
                targetHeight   = (short)CharArrayTo16(AiList, Offset + 1 + 8);
                start          = CharArrayTo16(AiList, Offset + 1 + 10);

                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d,", camDististance, camHeight, speed60);
                if (isNotBoundPad(pad))
                {
                    printf("%d,", pad);
                }
                else
                {
                    printf("setBoundPadNum(%d),", getBoundPadNum(pad));
                }

                printf("%d,%d", targetHeight, start);
                printf(")\n");
                Offset += AI_CameraOrbitPad_LENGTH;
                break;
            }
            case AI_CreditsRoll:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_CreditsRoll_LENGTH;
                break;
            }
            case AI_IFCreditsHasCompleted:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFCreditsHasCompleted_LENGTH;
                break;
            }
            case AI_IFObjectiveAllCompleted:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFObjectiveAllCompleted_LENGTH;
                break;
            }
            case AI_IFFolderActorIsEqual: // BYTE(BOND_ACTOR_INDEX), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFFolderActorIsEqual_LENGTH;
                break;
            }
            case AI_IFBondDamageAndPickupsDisabled:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("lbl%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_IFBondDamageAndPickupsDisabled_LENGTH;
                break;
            }
            case AI_MusicPlaySlot: // BYTE(MUSIC_SLOT), BYTE(SECONDS_STOPPED_DURATION), BYTE(SECONDS_TOTAL_DURATION)
            {
                printf("//ai: enery tune on (%d, %d, %d)\n", AiList[Offset + 1 + 0], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,%d,%d", AiList[Offset + 1 + 0], AiList[Offset + 1 + 1], AiList[Offset + 1 + 2]);
                printf(")\n");
                Offset += AI_MusicPlaySlot_LENGTH;
                break;
            }
            case AI_MusicStopSlot:
            {
                printf("//ai: enery tune off (%d)\n", AiList[Offset + 1 + 0]);
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1 + 0]);
                printf(")\n");
                Offset += AI_MusicStopSlot_LENGTH;
                break;
            }
            case AI_TriggerExplosionsAroundBond:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_TriggerExplosionsAroundBond_LENGTH;
                break;
            }
            case AI_IFKilledCiviliansGreaterThan:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFKilledCiviliansGreaterThan_LENGTH;
                break;
            }
            case AI_IFChrWasShotSinceLastCheck: // BYTE(CHR_NUM), BYTE(GOTOLABEL)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d,lbl%d", AiList[Offset + 1], AiList[Offset + 2]);
                printf(")\n");
                Offset += AI_IFChrWasShotSinceLastCheck_LENGTH;
                break;
            }
            case AI_BondKilledInAction:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_BondKilledInAction_LENGTH;
                break;
            }
            case AI_RaiseArms:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_RaiseArms_LENGTH;
                break;
            }
            case AI_GasLeakAndFadeFog:
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf(")\n");
                Offset += AI_GasLeakAndFadeFog_LENGTH;
                break;
            }
            case AI_ObjectRocketLaunch: // BYTE(OBJECT_TAG)
            {
                printf("%s%s(", tabs, AI_CMD_ToString[AiList[Offset]]);
                printf("%d", AiList[Offset + 1]);
                printf(")\n");
                Offset += AI_ObjectRocketLaunch_LENGTH;
                break;
            } //============================================================================================================

            default:
                /*
                 * No Command found, advance ailist by 1.
                 * This is attempting to handle situations where the command
                 * type is invalid by passing over them and continuing
                 * execution.
                 * chraiitemsize returns 1 which is pointless really
                 * could have done it here without a jump
                 *
                 * Outcome:crash
                 */
                {
                    Offset++;
                }
        } // switch
    }
}
enum chrAIListIDs
{
    chrai_0 = setChrAIListID(0),
    chrai_1,
    chrai_2,
    chrai_3,
    chrai_4,
    chrai_5,
    chrai_6,
    chrai_7,
    chrai_8,
    chrai_9,
    chrai_10,
    chrai_11,
    chrai_12,
    chrai_13,
    chrai_14,
    chrai_15,
    chrai_16,
    chrai_17,
    chrai_18
};
int main()
{
    unsigned char
          ai_0[] = {0x02, 0x03, 0x03, 0xeb, 0x36, 0x55, 0x00, 0xd0, 0x2a, 0x01, 0x03, 0x02, 0x2a, 0xec, 0xd7, 0x00, 0xda, 0x02, 0x08, 0x03, 0xdc, 0x2a, 0x01, 0x08, 0x02, 0x2a, 0xf1, 0x2a, 0x05, 0xfd, 0x00, 0x0f, 0x02, 0x2a, 0xdd, 0xea, 0x59, 0x18, 0x2a, 0x59, 0x19, 0x2a, 0x59, 0x04, 0x2a, 0x59, 0x05, 0x2a, 0x59, 0x06, 0x2a, 0x59, 0x07, 0x2a, 0x59, 0x08, 0x2a, 0x59, 0x09, 0x2a, 0x59, 0x0a, 0x2a, 0x59, 0x0b, 0x2a, 0x59, 0x0c, 0x2a, 0x59, 0x0d, 0x2a, 0x59, 0x0e, 0x2a, 0x59, 0x0f, 0x2a, 0x59, 0x10, 0x2a, 0x59, 0x11, 0x2a, 0x59, 0x12, 0x2a, 0x59, 0x13, 0x2a, 0x59, 0x16, 0x2a, 0x59, 0x14, 0x2a, 0x59, 0x15, 0x2a, 0xe4, 0x04, 0x02, 0x2a, 0xed, 0x03, 0x03, 0x03, 0xd5, 0x05, 0x00, 0x02, 0x00, 0x00, 0xd9, 0xf8, 0x00, 0xab, 0x2a, 0x02, 0x2a, 0x05, 0xf8, 0x04, 0x12, 0xa1, 0x00, 0x00, 0x00, 0x04, 0x00, 0xd9, 0x00, 0x00, 0xaa, 0x2a, 0x02, 0x2a, 0x05, 0x00, 0x04, 0x13, 0xdb, 0xf4, 0x00, 0x00, 0xff, 0x05, 0xfd, 0x00, 0x01, 0x02, 0x36, 0x05, 0xfd, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00};
    short ID     = 1;

    // char          str[999];
    // printf("Enter a string: ");
    // gets(str);

    if (isChrAIListID(ID))
    {
        printf("u8 chrAI_%d[] = {\n #define THIS chrai_%d\n", getChrAIListID(ID), getChrAIListID(ID));
    }
    else
    {
        printf("u8 bgAi_%d[] = {\n #define THIS bgai_%d\n", getBGAIListID(ID), getBGAIListID(ID));
    }
    ai(ai_0, ID);
    // un-closed loops
    if (top != -1) displayStack();

    printf("#undef THIS \n};\n");

    return 0;
}
