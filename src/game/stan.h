#ifndef _STAN_H_
#define _STAN_H_
#include "ultra64.h"


struct StandTilePoint {
    s16 x;
    s16 y;
    s16 z;
    u16 link;
};

struct StandTileHeaderTail {
    s16 pointCount : 4; // seen lh, not lhu. Also seen with an explicit unnecessary '& 0xF' 
    s16 headerC : 4;
    s16 headerD : 4;
    s16 headerE : 4;
};

struct StandTile {
    u16 name1;
    u8 name2;
    u8 room;    // compared to 0xFF, not -1 in a function. Seen LBUs.
    s16 headerMid;

    /* 0x06 */
    // They appear to have performed the bit field work themselves here,
    //   but we provide the StandTileHeaderTail member for clarity - it should be unused I believe.
    s16 hdrTail;

    /* 0x08 */
    struct StandTilePoint points[1];
};

// RGB? I've called them 'triple' because I don't really know what RGB is
// No parens around params
#define STAN_TRIPLE_TO_PNT_INDEX(tile, tripleIndex) (tile->hdrTail >> (8 - 4*tripleIndex) & 0xF)
#define STAN_POINT_COUNT(tile) (tile->hdrTail >> 0xC & 0xF)

// May be internal only, nice here.
struct StandTileWalkCallbackRecord {
    s32 * roomBuf;
    s32 count;
    s32 bufMax;
    s32 lastRoom;
};
typedef void (*standTileWalkCallback_t)(struct StandTile*, struct StandTile*, struct StandTileWalkCallbackRecord*);
// Necessary forward declaration
void noteTileRoomIfDifferentToPrev(struct StandTile *tile, struct StandTile *unused, struct StandTileWalkCallbackRecord *data);

// Very similar but definitely different to the above?
struct StandTileLocusCallbackRecord {
    s32 * roomBuf;
    s32 count;
    s32 bufMax;
    s32 nearEdgeCount;
};
typedef s32 (*standTileLocusCallback_A_t)(struct StandTile*, struct StandTileLocusCallbackRecord*);
typedef s32 (*standTileLocusCallback_B_t)(struct StandTile*, s32, float, float, void, float*);  // 5th parameter uncertain
typedef s32 (*standTileLocusCallback_C_t)(struct StandTile**, s32, struct StandTileLocusCallbackRecord*);

typedef s32 (*tilePredicate_t)(struct StandTile*);

void stanInitDebugNoticeList(void);

#endif
