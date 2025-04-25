#include "Ubrief.h"

struct BriefStruct UbriefdepoZ = {
    {                                          /* Mission Briefing */
        getStringID(LDEPO, 0),                        /* Background */
        getStringID(LDEPO, 1),                        /* M Briefing */
        getStringID(LDEPO, 2),                        /* Q Branch */
        getStringID(LDEPO, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LDEPO, 4), DIFFICULTY_00},       /* Destroy illegal arms cache */
        {getStringID(LDEPO, 5), DIFFICULTY_SECRET},   /* Destroy computer network */
        {getStringID(LDEPO, 6), DIFFICULTY_SECRET},   /* Obtain safe key */
        {getStringID(LDEPO, 7), DIFFICULTY_SECRET},   /* Recover helicopter blueprints */
        {getStringID(LDEPO, 8), DIFFICULTY_AGENT},    /* Locate Trevelyan's train */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
