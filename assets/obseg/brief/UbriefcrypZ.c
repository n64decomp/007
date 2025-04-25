#include "Ubrief.h"

struct BriefStruct UbriefcrypZ = {
    {                                          /* Mission Briefing */
        getStringID(LCRYP, 0),                        /* Background */
        getStringID(LCRYP, 1),                        /* M Briefing */
        getStringID(LCRYP, 2),                        /* Q Branch */
        getStringID(LCRYP, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LCRYP, 4), DIFFICULTY_AGENT},    /* Recover the golden gun */
        {getStringID(LCRYP, 5), DIFFICULTY_AGENT},    /* Defeat Baron Samedi? */
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
