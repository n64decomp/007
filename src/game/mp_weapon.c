#include "ultra64.h"
#include "bondconstants.h"
#include "game/mp_weapon.h"

// data
//D:80048670
struct s_mp_weapon_set mp_weapon_set_slaps[] = 
{
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1},
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1},
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1},
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1},
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1},
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1},
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1},
    {ITEM_UNARMED, PROP_chrtt33, 1.0, AMMO_9MM, 0, 1}
};

//D:80048730
struct s_mp_weapon_set mp_weapon_set_pistols[] = 
{
    {ITEM_TT33, PROP_chrtt33, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_WPPKSIL, PROP_chrwppksil, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_WPPKSIL, PROP_chrwppksil, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_WPPKSIL, PROP_chrwppksil, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_RUGER, PROP_chrruger, 1.0, AMMO_MAGNUM, 0x32, 1},
    {ITEM_RUGER, PROP_chrruger, 1.0, AMMO_MAGNUM, 0x32, 1}
};

//D:800487F0
struct s_mp_weapon_set mp_weapon_set_knife[] = 
{
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0},
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0},
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0},
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0},
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0},
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0},
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0},
    {ITEM_THROWKNIFE, PROP_chrthrowknife, 1.0, AMMO_KNIFE, 0xA, 0}
};

//D:800488B0
struct s_mp_weapon_set mp_weapon_set_auto[] = 
{
    {ITEM_WPPKSIL, PROP_chrwppksil, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_WPPKSIL, PROP_chrwppksil, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_MP5K, PROP_chrmp5k, 1.0, AMMO_9MM, 0x64, 1},
    {ITEM_MP5K, PROP_chrmp5k, 1.0, AMMO_9MM, 0x64, 1}
};

//D:80048970
struct s_mp_weapon_set mp_weapon_set_power[] = 
{
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_RUGER, PROP_chrruger, 1.0, AMMO_MAGNUM, 0x32, 1},
    {ITEM_RUGER, PROP_chrruger, 1.0, AMMO_MAGNUM, 0x32, 1},
    {ITEM_FNP90, PROP_chrfnp90, 1.0, AMMO_9MM, 0x64, 1},
    {ITEM_FNP90, PROP_chrfnp90, 1.0, AMMO_9MM, 0x64, 1},
    {ITEM_AUTOSHOT, PROP_chrautoshot, 1.0, AMMO_SHOTGUN, 0x1E, 1},
    {ITEM_AUTOSHOT, PROP_chrautoshot, 1.0, AMMO_SHOTGUN, 0x1E, 1}
};

//D:80048A30
struct s_mp_weapon_set mp_weapon_set_sniper[] = 
{
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_RUGER, PROP_chrruger, 1.0, AMMO_MAGNUM, 0x32, 1},
    {ITEM_RUGER, PROP_chrruger, 1.0, AMMO_MAGNUM, 0x32, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.0, AMMO_9MM, 0x64, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.0, AMMO_9MM, 0x64, 1},
    {ITEM_SNIPERRIFLE, PROP_chrsniperrifle, 1.0, AMMO_RIFLE, 0x32, 1},
    {ITEM_SNIPERRIFLE, PROP_chrsniperrifle, 1.0, AMMO_RIFLE, 0x32, 1}
};

//D:80048AF0
struct s_mp_weapon_set mp_weapon_set_grenade[] = 
{
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_GRENADE, PROP_chrgrenade, 1.5, AMMO_GRENADE, 5, 0},
    {ITEM_GRENADE, PROP_chrgrenade, 1.5, AMMO_GRENADE, 5, 0}
};

//D:80048BB0
struct s_mp_weapon_set mp_weapon_set_remote_m[] = 
{
    {ITEM_WPPK, PROP_chrwppk, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_WPPK, PROP_chrwppk, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_UZI, PROP_chruzi, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_UZI, PROP_chruzi, 1.5, AMMO_9MM, 0x64, 1},
#ifdef VERSION_US
    {ITEM_M16, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_M16, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
#else
    {ITEM_M16, PROP_chrm16, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_M16, PROP_chrm16, 1.5, AMMO_RIFLE, 0x64, 1},
#endif
    {ITEM_REMOTEMINE, PROP_chrremotemine, 1.5, AMMO_REMOTEMINE, 5, 0},
    {ITEM_REMOTEMINE, PROP_chrremotemine, 1.5, AMMO_REMOTEMINE, 5, 0}
};


//D:80048C70
struct s_mp_weapon_set mp_weapon_set_glaunch[] = 
{
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_GRENADELAUNCH, PROP_chrgrenadelaunch, 1.0, AMMO_GRENADEROUND, 6, 1},
    {ITEM_GRENADELAUNCH, PROP_chrgrenadelaunch, 1.0, AMMO_GRENADEROUND, 6, 1}
};

//D:80048D30
struct s_mp_weapon_set mp_weapon_set_timed_m[] = 
{
    {ITEM_WPPK, PROP_chrwppk, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_WPPK, PROP_chrwppk, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_UZI, PROP_chruzi, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_UZI, PROP_chruzi, 1.5, AMMO_9MM, 0x64, 1},
#ifdef VERSION_US
    {ITEM_M16, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_M16, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
#else
    {ITEM_M16, PROP_chrm16, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_M16, PROP_chrm16, 1.5, AMMO_RIFLE, 0x64, 1},
#endif
    {ITEM_TIMEDMINE, PROP_chrtimedmine, 1.5, AMMO_TIMEDMINE, 5, 0},
    {ITEM_TIMEDMINE, PROP_chrtimedmine, 1.5, AMMO_TIMEDMINE, 5, 0}
};

//D:80048DF0 
struct s_mp_weapon_set mp_weapon_set_prox_m[] = 
{
    {ITEM_WPPK, PROP_chrwppk, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_WPPK, PROP_chrwppk, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_UZI, PROP_chruzi, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_UZI, PROP_chruzi, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_M16, PROP_chrm16, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_M16, PROP_chrm16, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_PROXIMITYMINE, PROP_chrproximitymine, 1.5, AMMO_PROXMINE, 5, 0},
    {ITEM_PROXIMITYMINE, PROP_chrproximitymine, 1.5, AMMO_PROXMINE, 5, 0}
};

//D:80048EB0
struct s_mp_weapon_set mp_weapon_set_rockets[] = 
{
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_ROCKETLAUNCH, PROP_chrrocketlaunch, 1.5, AMMO_ROCKETS, 6, 1},
    {ITEM_ROCKETLAUNCH, PROP_chrrocketlaunch, 1.5, AMMO_ROCKETS, 6, 1}
};

//D:80048F70
struct s_mp_weapon_set mp_weapon_set_lasers[] = 
{
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_LASER, PROP_chrlaser, 1.5, AMMO_NONE, 0, 1},
    {ITEM_LASER, PROP_chrlaser, 1.5, AMMO_NONE, 0, 1}
};

//D:80049030
struct s_mp_weapon_set mp_weapon_set_golden[] = 
{
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_TT33, PROP_chrtt33, 3.0, AMMO_9MM, 0x32, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_SKORPION, PROP_chrskorpion, 1.5, AMMO_9MM, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_AK47, PROP_chrkalash, 1.5, AMMO_RIFLE, 0x64, 1},
    {ITEM_WPPKSIL, PROP_chrwppksil, 1.0, AMMO_9MM, 0x32, 1},
    {ITEM_GOLDENGUN, PROP_chrgolden, 1.5, AMMO_GGUN, 0xA, 1}
};

//D:800490F0
struct s_mp_weapon_set_text mp_weapon_set_text_table[] = 
{
    {TEXT(LMPWEAPONS, 0x0), mp_weapon_set_slaps},
    {TEXT(LMPWEAPONS, 0x1), mp_weapon_set_pistols},
    {TEXT(LMPWEAPONS, 0xD), mp_weapon_set_knife},
    {TEXT(LMPWEAPONS, 0x2), mp_weapon_set_auto},
    {TEXT(LMPWEAPONS, 0x3), mp_weapon_set_power},
    {TEXT(LMPWEAPONS, 0x4), mp_weapon_set_sniper},
    {TEXT(LMPWEAPONS, 0x5), mp_weapon_set_grenade},
    {TEXT(LMPWEAPONS, 0x6), mp_weapon_set_remote_m},
    {TEXT(LMPWEAPONS, 0x7), mp_weapon_set_glaunch},
    {TEXT(LMPWEAPONS, 0x8), mp_weapon_set_timed_m},
    {TEXT(LMPWEAPONS, 0x9), mp_weapon_set_prox_m},
    {TEXT(LMPWEAPONS, 0xA), mp_weapon_set_rockets},
    {TEXT(LMPWEAPONS, 0xB), mp_weapon_set_lasers},
    {TEXT(LMPWEAPONS, 0xC), mp_weapon_set_golden}
};

s32 mp_weapon_set = 0xB;


//increment mp_weapon_set by 1, capping at 0xE
void incrementMPWeaponSet(void)
{
    mp_weapon_set = (mp_weapon_set + 1) % 0xe;
}

//return pointer to selected mp_weapon_set textID
u16* getPtrMPWeaponSetTextID(void)
{
    return &mp_weapon_set_text_table[mp_weapon_set].textID;
}

//return pointer to selected mp_weapon_set data
struct s_mp_weapon_set* getPtrMPWeaponSetData(void)
{
    return mp_weapon_set_text_table[mp_weapon_set].weapon_set;
}

//set mp weapon set
void setMPWeaponSet(s32 setNUM)
{
    mp_weapon_set = setNUM;
}

//return mp weapon set
s32 getMPWeaponSet(void)
{
    return mp_weapon_set;
}
