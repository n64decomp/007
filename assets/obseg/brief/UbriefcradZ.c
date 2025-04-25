#include "Ubrief.h"

struct BriefStruct UbriefcradZ = {
    {                                          /* Mission Briefing */
        getStringID(LCRAD, 0),                        /* Background */
        getStringID(LCRAD, 1),                        /* M Briefing */
        getStringID(LCRAD, 2),                        /* Q Branch */
        getStringID(LCRAD, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LCRAD, 4), DIFFICULTY_AGENT},    /* Destroy control console */
        {getStringID(LCRAD, 5), DIFFICULTY_AGENT},    /* Settle the score with Trevelyan */
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
