#ifndef _MUSIC_H_
#define _MUSIC_H_
#include "ultra64.h"
#include "bondgame.h"

extern s32 music_unused;
extern s32 music1_track_num;
extern s32 music1len;
extern s32 music2_track_num;
extern s32 music2len;
extern s32 music3_track_num;
extern s32 music3len;
extern s32 music1_playing;
extern s32 music2_playing;
extern s32 music3_playing;

extern u32 hp[4];
extern u32 *ptr_sfx_buf;
extern s32 D_80063724;
extern s32 seqp_1;
extern s32 seqp_2;
extern s32 seqp_3;
extern void *ptr_musicdatatable;

extern char D_80063738[0x80];
extern char D_800637B8[0x7E];
extern s16 D_80063836;
extern s32 D_80063838;
extern s32 D_8006383C;
extern s32 D_80063840;
extern s16 musicTrack1_length;
extern s16 D_80063846;
extern s16 D_80063848;
extern s16 music1_length;
extern s16 music2_length;
extern s16 music3_length;
extern s32 music1_rate;
extern s32 music2_rate;
extern s32 music3_rate;
extern s32 D_8006385C;
extern char D_80063860[0xF8];
extern char D_80063958[0xF8];
extern char D_80063A50[0x100];
extern char D_80063B50[0x54];
extern s32 D_80063BA4;
extern s32 D_80063BA8;

#endif
