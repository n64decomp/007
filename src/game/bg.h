#ifndef _BG_H_
#define _BG_H_
#include "ultra64.h"
#include "bondgame.h"

struct levelentry
{
    s32 levelID;
    void *bg_seg_filename;
    void *bg_stan_filename;
    f32 levelscale;
    f32 visibility;
    f32 unknownfloat;
};

typedef struct s_room_info {
    s16 bitflags;
    u8 model_bin_loaded;
    u8 bitflags2;
    void * ptr_point_index;
    void * ptr_expanded_mapping_info;
    void * ptr_secondary_expanded_mapping_info;
    s32 csize_point_index_binary;
    s32 csize_primary_DL_binary;
    s32 csize_secondary_DL_binary;
    s32 usize_point_index_binary;
    s32 usize_primary_DL_binary;
    s32 usize_secondary_DL_binary;
    s32 cur_room_totalsize;
    void * ptr_unique_collision_points;
    s32 bitflags3;
    u8 room_loaded_mask;
    u8 field_35;
    s16 field_36;
    f32 minxbounds;
    f32 minybounds;
    f32 minzbounds;
    f32 maxxbounds;
    f32 maxybounds;
    f32 maxzbounds;
} s_room_info;

void bgInitDebugNoticeList(void);

s32 sub_GAME_7F0B8FD0(u8 roomA, u8 roomB);
s32 sub_GAME_7F0B4F9C(u8 room); // u8 not s32 for sub_GAME_7F0B2FE0

#endif
