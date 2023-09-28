#ifndef _STAN_H_
#define _STAN_H_
#include <ultra64.h>

#include <bondtypes.h>

// RGB? I've called them 'triple' because I don't really know what RGB is
// No parens around params
#define STAN_TRIPLE_TO_PNT_INDEX(tile, tripleIndex) (tile->hdrTail >> (8 - 4*tripleIndex) & 0xF)
#define STAN_POINT_COUNT(tile) (tile->tail.half & 0xF)

#define STAN_MID_SPECIAL(tile) (tile->mid.half & 0xF)
#define STAN_MID_R(tile) ((tile->mid.half >> 0x04) & 0xF)
#define STAN_MID_G(tile) ((tile->mid.half >> 0x08) & 0xF)
#define STAN_MID_B(tile) ((tile->mid.half >> 0x0C) & 0xF)

#define STAN_TAIL_POINT_COUNT(tile) (tile->tail.half & 0xF)
#define STAN_TAIL_C(tile) ((tile->tail.half >> 0x04) & 0xF)
#define STAN_TAIL_D(tile) ((tile->tail.half >> 0x08) & 0xF)
#define STAN_TAIL_E(tile) ((tile->tail.half >> 0x0C) & 0xF)

struct move_bond_collision {
    struct coord3d bondCollision;
    struct coord3d sp190;
    struct coord3d sp19C;
    struct coord3d sp1A8;
};


/////////////////
// extern

extern f32 stanSavedColl_someMin;
extern PropRecord *stanSavedColl_posData;
extern struct StandTile *standTileStart;
extern s32 stanlinelog_flag;

/////////////////
// prototypes

// Necessary forward declaration
void noteTileRoomIfDifferentToPrev( StandTile *tile,  StandTile *unused,  struct StandTileWalkCallbackRecord *data);

void stanInit(void);

void sub_GAME_7F0B2D38(s8 arg0, s8 arg1, u16 arg2);
void sub_GAME_7F0AF630(s32 arg0);
void sub_GAME_7F0B1CC4(void);
Gfx * sub_GAME_7F0B2D48(Gfx *arg0);
Gfx * sub_GAME_7F0B303C(Gfx *arg0);
Gfx * sub_GAME_7F0B3034(Gfx *arg0);
Gfx * sub_GAME_7F0B312C(Gfx *arg0, s32 arg1);
Gfx * sub_GAME_7F0B3024(Gfx *ptrdl, StandTilePoint *tile_point, u32 RGBAColor);
s32 walkTilesBetweenPoints_NoCallback(StandTile **tileStack, f32 start_x, f32 start_z, f32 dest_x, f32 dest_z);
s32 stanTestPointWithinTileBoundsMaybe(StandTile *tile, f32 p_x, f32 p_z);
f32 stanGetPositionYValue(StandTile* tile, f32 p_x, f32 p_z);
s32 getCollisionEdge_maybe(coord3d *pntA, coord3d *pntB);
s32 sub_GAME_7F0B26B8(StandTile **tile, f32 target_x, f32 target_z, f32 b_z, f32 param_5);
s32 sub_GAME_7F0B20D0(StandTile** tileStack, f32 target_x, f32 target_z, f32 unknown);

s32 stanTestLineUnobstructed(StandTile **pTile, f32 p_x, f32 p_z, f32 dest_x, f32 dest_z, int objFlags, f32 unkHeight, f32 unkA, f32 unkB, f32 unkC);
StandTile* sub_GAME_7F0B2718(StandTile* srcTile, tilePredicate_t tilePred);
s32 sub_GAME_7F0B0D0C(StandTile *tile, f32 start_x, f32 start_z,  StandTile **tilePtr, f32 end_x, f32 end_z, s32 *roomBuf, s32 maxBufSize);
s32 sub_GAME_7F0B0C24(StandTile **tileStack, f32 start_x, f32 start_z, f32 dest_x, f32 dest_z, s32 *roomBuffer, s32 *rtnCountSize, s32 maxBufSize);
s32 stanTestVolume(StandTile **, f32 posX, f32 posY, f32 radius, s32 integer, f32 float1, f32 float2);
s32 getTileRoom(StandTile* tile);
PropRecord *sub_GAME_7F0B1410(StandTile *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void copy_tile_RGB_as_24bit(StandTile *tile, f32 p_x, f32 p_z, u8 *rtn);
s32 stanTileDistanceRelated(struct StandTile **arg0, f32 arg1, f32 arg2, f32 arg3, struct StandTileLocusCallbackRecord *arg4);
s32 stanGetLocusField0(struct StandTileLocusCallbackRecord *arg0);
s32 stanGetLocusCount(struct StandTileLocusCallbackRecord *arg0);
f32 distBetweenPoints2d(f32 o_x,f32 o_z,f32 p_x,f32 p_z);
bool sub_GAME_7F0B17E4(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3);
f32 sub_GAME_7F0B16C4(f32 x1, f32 z1, f32 x2, f32 z2, f32 x3, f32 z3);
void stanGetMoveBondCollisionTiles(struct StandTile **arg0, struct StandTile **arg1, struct move_bond_collision *arg2);
struct StandTile *sub_GAME_7F0AFB78(f32 *arg_x, f32 *arg_y, f32 *arg_z, f32 arg3);
s32 sub_GAME_7F0B0688(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
#endif
