#ifndef _SPEED_GRAPH_H_
#define _SPEED_GRAPH_H_

#include <ultra64.h>

Gfx *speedGraphDisplay(Gfx *gdl);
void speedGraphVideoRelated_2(void);

#if defined(VERSION_EU)
void profileSetMarker(void);
Gfx *video_DL_related_4(Gfx *gdl);
#else
void profileSetMarker(s32 arg0);
void video_DL_related_4(void);
#endif


#endif
