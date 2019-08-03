#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefdamZ = {
    {                                          /* Mission Briefing */
        TEXT(LDAM, 0),                         /* Background */
        TEXT(LDAM, 1),                         /* M Briefing */
        TEXT(LDAM, 2),                         /* Q Branch */
        TEXT(LDAM, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LDAM, 4), DIFFICULTY_SECRET},    /* Neutralize all alarms */
        {TEXT(LDAM, 5), DIFFICULTY_00},        /* Install covert modem */
        {TEXT(LDAM, 6), DIFFICULTY_00},        /* Intercept data backup */
        {TEXT(LDAM, 7), DIFFICULTY_AGENT},     /* Bungee jump from platform */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
