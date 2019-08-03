#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefdestZ = {
    {                                          /* Mission Briefing */
        TEXT(LDEST, 0),                        /* Background */
        TEXT(LDEST, 1),                        /* M Briefing */
        TEXT(LDEST, 2),                        /* Q Branch */
        TEXT(LDEST, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LDEST, 4), DIFFICULTY_AGENT},    /* Rescue Hostages */
        {TEXT(LDEST, 5), DIFFICULTY_SECRET},   /* Disarm bridge bomb */
        {TEXT(LDEST, 6), DIFFICULTY_SECRET},   /* Disarm engine room bomb */
        {TEXT(LDEST, 7), DIFFICULTY_AGENT},    /* Plant tracking bug on helicopter */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
