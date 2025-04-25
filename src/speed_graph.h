#ifndef _SPEED_GRAPH_H_
#define _SPEED_GRAPH_H_

#include <ultra64.h>

void speedgraphMarkerCommit(void);
void speedgraphMarkerHandler(s32 arg0);
Gfx *speedgraphDisplayMetrics(Gfx *gdl);
void speedgraphRenderGraph(void);

#endif
