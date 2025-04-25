#include "Ubrief.h"

struct BriefStruct UbriefsevxZ = {
    {                                          /* Mission Briefing */
        getStringID(LSEVX, 0),                        /* Background */
        getStringID(LSEVX, 1),                        /* M Briefing */
        getStringID(LSEVX, 2),                        /* Q Branch */
        getStringID(LSEVX, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LSEVX, 4), DIFFICULTY_AGENT},    /* Power down communications dish */
        {getStringID(LSEVX, 5), DIFFICULTY_SECRET},   /* Obtain safe key */
        {getStringID(LSEVX, 6), DIFFICULTY_SECRET},   /* Steal building plans */
        {getStringID(LSEVX, 7), DIFFICULTY_AGENT},    /* Enter base via ventilation tower */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
