#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefarchZ = {
    {                                          /* Mission Briefing */
        TEXT(LARCH, 0),                        /* Background */
        TEXT(LARCH, 1),                        /* M Briefing */
        TEXT(LARCH, 2),                        /* Q Branch */
        TEXT(LARCH, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LARCH, 4), DIFFICULTY_AGENT},    /* Escape from interrogation room */
        {TEXT(LARCH, 5), DIFFICULTY_AGENT},    /* Find Natalya */
        {TEXT(LARCH, 6), DIFFICULTY_SECRET},   /* Recover helicopter black box */
        {TEXT(LARCH, 7), DIFFICULTY_AGENT},    /* Escape with Natalya */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
