#ifndef _INITOBJECTS_H_
#define _INITOBJECTS_H_
#include <ultra64.h>

#include <bondtypes.h>

void init_load_objpos_table(void);
void reinit_between_menus(void);
void init_sound_effects_registers(void);
void sub_GAME_7F001910(struct ObjectRecord *arg0);

#endif
