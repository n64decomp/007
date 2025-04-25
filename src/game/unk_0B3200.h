#ifndef _UNK_0B3200_H_
#define _UNK_0B3200_H_
#include <ultra64.h>
#include "bondtypes.h"

f32 calculateLineIntersectionFactor(coord2d *start1, coord2d *end1, coord2d *start2, coord2d *end2);
f32 calculatePointToLineDistance(struct coord3d *point3D, coord2d *lineStart, coord2d *lineEnd);
f32 calculateNormalizedLineIntersection(coord3d *point3D, coord2d *lineStart, coord2d *lineEnd, coord2d *direction);

#endif
