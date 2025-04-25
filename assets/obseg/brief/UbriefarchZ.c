#include "Ubrief.h"

struct BriefStruct UbriefarchZ = {
    {                                          /* Mission Briefing */
        getStringID(LARCH, 0),                        /* Background */
        getStringID(LARCH, 1),                        /* M Briefing */
        getStringID(LARCH, 2),                        /* Q Branch */
        getStringID(LARCH, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LARCH, 4), DIFFICULTY_AGENT},    /* Escape from interrogation room */
        {getStringID(LARCH, 5), DIFFICULTY_AGENT},    /* Find Natalya */
        {getStringID(LARCH, 6), DIFFICULTY_SECRET},   /* Recover helicopter black box */
        {getStringID(LARCH, 7), DIFFICULTY_AGENT},    /* Escape with Natalya */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
