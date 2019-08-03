#ifndef _UBRIEF_H_
#define _UBRIEF_H_

#include "ultra64.h"
#include "bondgame.h"

struct BriefObjectiveStruct
{
    u16 text;
    u16 difficulty;
};

struct BriefStruct
{
    u16 brief[4];
    struct BriefObjectiveStruct objective[OBJECTIVES_MAX];
};

#endif
