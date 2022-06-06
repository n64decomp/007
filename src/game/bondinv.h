#ifndef _BONDINV_H_
#define _BONDINV_H_
#include <ultra64.h>
#include <bondconstants.h>
#include "bondview.h"
#include "bondtypes.h"

void bondinvReinitInv(void);
s32 bondinvIsAliveWithFlag(void);
s32 bondinvCountTotalItemsInInv(void);

InvItem *bondinvGetItemByIndex(s32 index);
textoverride *bondinvGetTextbyObj(ObjectRecord *obj);
textoverride *bondinvGetTextbyWeaponID(ITEM_IDS weaponnum);

void bondinvCycleBackward(s32 *nextright, s32 *nextleft, s32 requireammo);
void bondinvCycleForward(s32 *nextright, s32 *nextleft, s32 requireammo);
int bondinvHasGoldenGun(void);
int bondinvAddInvItem(ITEM_IDS item);
int bondinvAddDoublesInvItem(ITEM_IDS right, ITEM_IDS left);
s32 bondinvGetAllGunsFlag(void);
void bondinvSetAllGunsFlag(s32 all_guns);
bool          bondinvHasPropInInv(PropRecord *prop);
WeaponObjRecord *bondinvRemovePropWeaponByID(ITEM_IDS weaponnum);
void bondinvRemoveItemByID(ITEM_IDS weaponnum);
#endif
