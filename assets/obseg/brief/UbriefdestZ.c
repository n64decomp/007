#include "Ubrief.h"

struct BriefStruct UbriefdestZ = {
    {                                          /* Mission Briefing */
        getStringID(LDEST, 0),                        /* Background */
        getStringID(LDEST, 1),                        /* M Briefing */
        getStringID(LDEST, 2),                        /* Q Branch */
        getStringID(LDEST, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LDEST, 4), DIFFICULTY_AGENT},    /* Rescue Hostages */
        {getStringID(LDEST, 5), DIFFICULTY_SECRET},   /* Disarm bridge bomb */
        {getStringID(LDEST, 6), DIFFICULTY_SECRET},   /* Disarm engine room bomb */
        {getStringID(LDEST, 7), DIFFICULTY_AGENT},    /* Plant tracking bug on helicopter */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
