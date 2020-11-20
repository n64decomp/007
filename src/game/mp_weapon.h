#ifndef _MP_WEAPON_H_
#define _MP_WEAPON_H_
#include "ultra64.h"

struct s_mp_weapon_set
{
  s32 itemID;
  s32 propID;
  f32 size;
  s32 ammotype;
  s32 ammoamount;
  s32 allowpickup;
};

struct s_mp_weapon_set_text
{
  u16 textID;
  struct s_mp_weapon_set * weapon_set;
};

extern struct s_mp_weapon_set mp_weapon_set_slaps[];
extern struct s_mp_weapon_set mp_weapon_set_pistols[];
extern struct s_mp_weapon_set mp_weapon_set_knife[];
extern struct s_mp_weapon_set mp_weapon_set_auto[];
extern struct s_mp_weapon_set mp_weapon_set_power[];
extern struct s_mp_weapon_set mp_weapon_set_sniper[];
extern struct s_mp_weapon_set mp_weapon_set_grenade[];
extern struct s_mp_weapon_set mp_weapon_set_remote_m[];
extern struct s_mp_weapon_set mp_weapon_set_glaunch[];
extern struct s_mp_weapon_set mp_weapon_set_timed_m[];
extern struct s_mp_weapon_set mp_weapon_set_prox_m[];
extern struct s_mp_weapon_set mp_weapon_set_rockets[];
extern struct s_mp_weapon_set mp_weapon_set_lasers[];
extern struct s_mp_weapon_set mp_weapon_set_golden[];

void incrementMPWeaponSet(void);
u16* getPtrMPWeaponSetTextID(void);
struct s_mp_weapon_set* getPtrMPWeaponSetData(void);
void setMPWeaponSet(s32 arg0);
s32 getMPWeaponSet(void);

#endif
