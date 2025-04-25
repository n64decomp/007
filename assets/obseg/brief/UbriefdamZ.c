#include "Ubrief.h"

struct BriefStruct UbriefdamZ = {
    {                                          /* Mission Briefing */
        getStringID(LDAM, 0),                         /* Background */
        getStringID(LDAM, 1),                         /* M Briefing */
        getStringID(LDAM, 2),                         /* Q Branch */
        getStringID(LDAM, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LDAM, 4), DIFFICULTY_SECRET},    /* Neutralize all alarms */
        {getStringID(LDAM, 5), DIFFICULTY_00},        /* Install covert modem */
        {getStringID(LDAM, 6), DIFFICULTY_00},        /* Intercept data backup */
        {getStringID(LDAM, 7), DIFFICULTY_AGENT},     /* Bungee jump from platform */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
