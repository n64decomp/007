#include "Ubrief.h"

struct BriefStruct UbriefcrypZ = {
    {                                          /* Mission Briefing */
        TEXT(LCRYP, 0),                        /* Background */
        TEXT(LCRYP, 1),                        /* M Briefing */
        TEXT(LCRYP, 2),                        /* Q Branch */
        TEXT(LCRYP, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LCRYP, 4), DIFFICULTY_AGENT},    /* Recover the golden gun */
        {TEXT(LCRYP, 5), DIFFICULTY_AGENT},    /* Defeat Baron Samedi? */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
