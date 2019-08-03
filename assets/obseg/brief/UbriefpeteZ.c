#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefpeteZ = {
    {                                          /* Mission Briefing */
        TEXT(LPETE, 0),                        /* Background */
        TEXT(LPETE, 1),                        /* M Briefing */
        TEXT(LPETE, 2),                        /* Q Branch */
        TEXT(LPETE, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LPETE, 6), DIFFICULTY_SECRET},   /* Contact Valentin */
        {TEXT(LPETE, 4), DIFFICULTY_AGENT},    /* Pursue Ourumov and Natalya */
        {TEXT(LPETE, 5), DIFFICULTY_AGENT},    /* Minimize civilian casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
