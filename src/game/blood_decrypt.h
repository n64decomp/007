#ifndef _BLOOD_DECRYPT_H_
#define _BLOOD_DECRYPT_H_

#include <ultra64.h>

u8 *decrypt_bleeding_animation_data(u8 *arg0, u8 arg1, u8 arg2, u8 *arg3, u8 *arg4);

void sub_GAME_7F01D16C(u8*, s32, s32, u8*);
void sub_GAME_7F01D02C(u8*, s32, u8*);
void sub_GAME_7F01CEEC(u8*, s32, u8*);
void sub_GAME_7F01CC94(u8*, u16, u8*);

#endif

