#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "ultra64.h"
#include "bondgame.h"

struct animation_something
{
  s32 anonymous_0;
  s32 field_4;
  s32 field_8;
  f32 field_C;
  s32 field_10;
  s32 field_14;
  f32 field_18;
  struct struck_animation_table *field_1C;
  s32 field_20;
  struct struck_animation_table *field_24;
  s32 field_28;
};

struct struck_animation_table
{
  s32 anonymous_0;
  s32 anonymous_1;
  f32 anonymous_2;
  f32 anonymous_3;
  s32 anonymous_4;
  f32 anonymous_5;
  f32 anonymous_6;
};

struct explosion_death_animation
{
  s32 anonymous_0;
  s32 anonymous_1;
  f32 anonymous_2;
  f32 anonymous_3;
  f32 anonymous_4;
  f32 anonymous_5;
  f32 anonymous_6;
};

struct explosion_animation
{
  void *explosion_death_animation;
  s32 count;
};

struct weapon_firing_animation_table
{
  s32 anonymous_0;
  f32 anonymous_1;
  f32 anonymous_2;
  f32 anonymous_3;
  f32 anonymous_4;
  f32 anonymous_5;
  f32 anonymous_6;
  f32 anonymous_7;
  f32 anonymous_8;
  f32 anonymous_9;
  f32 anonymous_10;
  f32 anonymous_11;
  f32 anonymous_12;
  f32 anonymous_13;
  f32 anonymous_14;
  f32 anonymous_15;
  f32 anonymous_16;
  f32 anonymous_17;
};

extern struct animation_something D_8002C914;


extern struct struck_animation_table D_8002CE54[];
extern struct struck_animation_table D_8002DF10[];
extern struct struck_animation_table D_8002CEE0[];
extern struct struck_animation_table D_8002DF64[];
extern struct struck_animation_table D_8002CF6C[];
extern struct struck_animation_table D_8002DFB8[];
extern struct struck_animation_table D_8002D014[];
extern struct struck_animation_table D_8002E028[];
extern struct struck_animation_table D_8002D0A0[];
extern struct struck_animation_table D_8002E07C[];
extern struct struck_animation_table D_8002D12C[];
extern struct struck_animation_table D_8002E0D0[];
extern struct struck_animation_table D_8002D1D4[];
extern struct struck_animation_table D_8002E140[];
extern struct struck_animation_table D_8002D3B0[];
extern struct struck_animation_table D_8002E23C[];
extern struct struck_animation_table D_8002D6DC[];
extern struct struck_animation_table D_8002E300[];
extern struct struck_animation_table D_8002D768[];
extern struct struck_animation_table D_8002E354[];
extern struct struck_animation_table D_8002D7F4[];
extern struct struck_animation_table D_8002E3A8[];
extern struct struck_animation_table D_8002D880[];
extern struct struck_animation_table D_8002E418[];
extern struct struck_animation_table D_8002D90C[];
extern struct struck_animation_table D_8002E46C[];
extern struct struck_animation_table D_8002D998[];
extern struct struck_animation_table D_8002E4C0[];
extern struct struck_animation_table D_8002DA24[];
extern struct struck_animation_table D_8002E530[];
extern struct struck_animation_table D_8002DCE0[];
extern struct struck_animation_table D_8002E5BC[];

extern struct weapon_firing_animation_table rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table rifle_firing_animation_group5[];
extern struct weapon_firing_animation_table rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table rifle_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table pistol_firing_animation_group6[];
extern struct weapon_firing_animation_table pistol_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group5[];
extern struct weapon_firing_animation_table doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table doubles_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_groupA[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table crouched_doubles_firing_animation_group3[];


extern struct weapon_firing_animation_table D_80030078;
extern struct weapon_firing_animation_table D_800300C0;
extern struct weapon_firing_animation_table D_80030108;
extern struct weapon_firing_animation_table D_80030150;
extern struct weapon_firing_animation_table D_80030198;
extern struct weapon_firing_animation_table D_800301E0;
extern struct weapon_firing_animation_table D_80030228;
extern struct weapon_firing_animation_table D_80030270;
extern struct weapon_firing_animation_table D_800302B8;
extern struct weapon_firing_animation_table D_80030300;
extern struct weapon_firing_animation_table D_80030348;
extern struct weapon_firing_animation_table D_80030390;
extern struct weapon_firing_animation_table D_800303D8;
extern struct weapon_firing_animation_table D_80030420;
extern struct weapon_firing_animation_table D_80030468;
extern struct weapon_firing_animation_table D_800304B0;
extern struct weapon_firing_animation_table D_800304F8;
extern struct weapon_firing_animation_table D_80030540;
extern struct weapon_firing_animation_table D_80030588;
extern struct weapon_firing_animation_table D_800305D0;
extern struct weapon_firing_animation_table D_80030618;
extern struct weapon_firing_animation_table D_80030660;
extern struct weapon_firing_animation_table D_800306A8;
extern struct weapon_firing_animation_table D_800306F0;
extern struct weapon_firing_animation_table D_80030738;
extern struct weapon_firing_animation_table D_80030780;
extern struct weapon_firing_animation_table D_800307C8;
extern struct weapon_firing_animation_table D_80030810;
extern struct weapon_firing_animation_table D_80030858;
extern struct weapon_firing_animation_table D_800308A0;
extern struct weapon_firing_animation_table D_800308E8;
extern struct weapon_firing_animation_table D_80030930;

extern f32 animation_rate;
extern s32 D_8002C904;
extern s32 D_8002C908;
extern s32 D_8002C90C;
extern s32 D_8002C910;

extern s32 D_8002CC58;
extern s32 show_patrols_flag;
extern s32 player1_guardID;
extern s32 ptr_guard_data;
extern s32 num_guards;
extern s32 D_8002CC6C[];
extern s32 D_8002CCA8;
extern s32 D_8002CCAC;
extern s32 D_8002CCB0;
extern s32 D_8002CCB4;
extern u8 D_8002CCB8;
extern s32 num_bodies;
extern s32 num_male_heads;
extern s32 num_female_heads;
extern s32 list_of_bodies[];
extern s32 random_male_heads[];
extern s32 random_female_heads[];
#endif
