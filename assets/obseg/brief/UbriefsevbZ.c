#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsevbZ = {
    {                                          /* Mission Briefing */
        TEXT(LSEVB, 0),                        /* Background */
        TEXT(LSEVB, 1),                        /* M Briefing */
        TEXT(LSEVB, 2),                        /* Q Branch */
        TEXT(LSEVB, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LSEVB, 4), DIFFICULTY_SECRET},   /* Compare staff / casualty lists */
        {TEXT(LSEVB, 5), DIFFICULTY_AGENT},    /* Recover CCTV tape */
        {TEXT(LSEVB, 6), DIFFICULTY_SECRET},   /* Disable all security cameras */
        {TEXT(LSEVB, 7), DIFFICULTY_00},       /* Recover Goldeneye operations manual */
        {TEXT(LSEVB, 8), DIFFICULTY_AGENT},    /* Escape with Natalya */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
