#include "Ubrief.h"

struct BriefStruct UbriefsevxZ = {
    {                                          /* Mission Briefing */
        TEXT(LSEVX, 0),                        /* Background */
        TEXT(LSEVX, 1),                        /* M Briefing */
        TEXT(LSEVX, 2),                        /* Q Branch */
        TEXT(LSEVX, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LSEVX, 4), DIFFICULTY_AGENT},    /* Power down communications dish */
        {TEXT(LSEVX, 5), DIFFICULTY_SECRET},   /* Obtain safe key */
        {TEXT(LSEVX, 6), DIFFICULTY_SECRET},   /* Steal building plans */
        {TEXT(LSEVX, 7), DIFFICULTY_AGENT},    /* Enter base via ventilation tower */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
