#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefcontrolZ = {
    {                                          /* Mission Briefing */
        TEXT(LAREC, 0),                        /* Background */
        TEXT(LAREC, 1),                        /* M Briefing */
        TEXT(LAREC, 2),                        /* Q Branch */
        TEXT(LAREC, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LAREC, 4), DIFFICULTY_AGENT},    /* Protect Natalya */
        {TEXT(LAREC, 5), DIFFICULTY_AGENT},    /* Disable Goldeneye satellite */
        {TEXT(LAREC, 6), DIFFICULTY_AGENT},    /* Destroy armored mainframes */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
