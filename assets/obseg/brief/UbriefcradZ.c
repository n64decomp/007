#include "Ubrief.h"

struct BriefStruct UbriefcradZ = {
    {                                          /* Mission Briefing */
        TEXT(LCRAD, 0),                        /* Background */
        TEXT(LCRAD, 1),                        /* M Briefing */
        TEXT(LCRAD, 2),                        /* Q Branch */
        TEXT(LCRAD, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LCRAD, 4), DIFFICULTY_AGENT},    /* Destroy control console */
        {TEXT(LCRAD, 5), DIFFICULTY_AGENT},    /* Settle the score with Trevelyan */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
