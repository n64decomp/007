#include "Ubrief.h"

struct BriefStruct UbriefpeteZ = {
    {                                          /* Mission Briefing */
        getStringID(LPETE, 0),                        /* Background */
        getStringID(LPETE, 1),                        /* M Briefing */
        getStringID(LPETE, 2),                        /* Q Branch */
        getStringID(LPETE, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LPETE, 6), DIFFICULTY_SECRET},   /* Contact Valentin */
        {getStringID(LPETE, 4), DIFFICULTY_AGENT},    /* Pursue Ourumov and Natalya */
        {getStringID(LPETE, 5), DIFFICULTY_AGENT},    /* Minimize civilian casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
