#include "Ubrief.h"

struct BriefStruct UbriefsevbZ = {
    {                                          /* Mission Briefing */
        getStringID(LSEVB, 0),                        /* Background */
        getStringID(LSEVB, 1),                        /* M Briefing */
        getStringID(LSEVB, 2),                        /* Q Branch */
        getStringID(LSEVB, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LSEVB, 4), DIFFICULTY_SECRET},   /* Compare staff / casualty lists */
        {getStringID(LSEVB, 5), DIFFICULTY_AGENT},    /* Recover CCTV tape */
        {getStringID(LSEVB, 6), DIFFICULTY_SECRET},   /* Disable all security cameras */
        {getStringID(LSEVB, 7), DIFFICULTY_00},       /* Recover Goldeneye operations manual */
        {getStringID(LSEVB, 8), DIFFICULTY_AGENT},    /* Escape with Natalya */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
