#include "Ubrief.h"

struct BriefStruct UbriefcontrolZ = {
    {                                          /* Mission Briefing */
        getStringID(LAREC, 0),                        /* Background */
        getStringID(LAREC, 1),                        /* M Briefing */
        getStringID(LAREC, 2),                        /* Q Branch */
        getStringID(LAREC, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LAREC, 4), DIFFICULTY_AGENT},    /* Protect Natalya */
        {getStringID(LAREC, 5), DIFFICULTY_AGENT},    /* Disable Goldeneye satellite */
        {getStringID(LAREC, 6), DIFFICULTY_AGENT},    /* Destroy armored mainframes */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
