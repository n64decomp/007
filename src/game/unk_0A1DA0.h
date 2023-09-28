#ifndef _UNK_0A1DA0_H_
#define _UNK_0A1DA0_H_
#include <ultra64.h>
#include <bondtypes.h>

typedef struct s_shattered_window_piece {
    s32 piece;
    f32 x;
    f32 y;
    f32 z;
    f32 field_0x10;
    f32 field_0x14;
    f32 field_0x18;
    f32 field_0x1c;
    f32 field_0x20;
    f32 field_0x24;
    f32 field_0x28;
    f32 field_0x2c;
    f32 field_0x30;
    u32 field_0x34;
    s16 field_0x38;
    s16 field_0x3a;
    s16 field_0x3c;
    s16 field_0x3e;
    s16 field_0x40;
    s16 field_0x42;
    u8 field_0x44;
    u8 field_0x45;
    u8 field_0x46;
    u8 field_0x47;
    s16 field_0x48;
    s16 field_0x4a;
    s16 field_0x4c;
    s16 field_0x4e;
    s16 field_0x50;
    s16 field_0x52;
    u8 field_0x54;
    u8 field_0x55;
    u8 field_0x56;
    u8 field_0x57;
    s16 field_0x58;
    s16 field_0x5a;
    s16 field_0x5c;
    s16 field_0x5e;
    s16 field_0x60;
    s16 field_0x62;
    u8 field_0x64;
    u8 field_0x65;
    u8 field_0x66;
    u8 field_0x67;
} s_shattered_window_piece;

typedef struct bondstruct_unk_8007A170 {
    s32 unk00;
    s16 unk04;
    s16 unk06;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1c;
    u32 unk20;
    u32 unk24;
    u32 unk28;
} bondstruct_unk_8007A170;

extern s32 SHATTERED_WINDOW_PIECES_BUFFER_LEN;
extern s_shattered_window_piece* ptr_shattered_window_pieces;
extern s32 D_80040940;

extern u32 D_80040980;
extern u32 D_80040984;
extern u32 D_80040988;
extern u32 D_8004098C;
extern u32 D_80040990;
extern u32 watch_screen_index;
extern u32 controller_options_index;
extern u32 game_options_index;

void sub_GAME_7F0A47D4(void);
void sub_GAME_7F0A47FC(void);
void update_broken_windows(void);
void sub_GAME_7F0A4528(Gfx *arg0, s32 arg1);
void sub_GAME_7F0A4824(Gfx *arg0, s32 arg1);
Gfx * sub_GAME_7F0A2C44(Gfx *arg0);

// tentative signature
void *sub_GAME_7F0A3E1C(coord3d *arg0, s32 arg1, f32 arg2, s16 arg3);
void sub_GAME_7F0A33F8(struct WatchVertex *arg0, s32 arg1, f32 arg2, s32 arg3);
Gfx *sub_GAME_7F0A3978(Gfx *gdl, void *arg1, s32 unused_arg2, s32 arg3);
Gfx *sub_GAME_7F0A3B40(Gfx *gdl, s32 *arg1);
Gfx * sub_GAME_7F0A3330(Gfx *arg0, void * arg1, s32 arg2);
void sub_GAME_7F0A2F30(s32 *arg0, s32 arg1, s32 arg2, f32 arg3);
struct WatchVertex *setup_watch_rectangles(struct WatchVertex *vtx, s32 startx, s32 startz, s32 width, s32 height, s32 horizontal_offset, s32 vertical_offset);
void sub_GAME_7F0A2160(coord3d * arg0, f32 arg1, f32 arg2);
void sub_GAME_7F0A3EA0(void);

#endif
