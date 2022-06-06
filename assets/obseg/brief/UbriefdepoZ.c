#include "Ubrief.h"

struct BriefStruct UbriefdepoZ = {
    {                                          /* Mission Briefing */
        TEXT(LDEPO, 0),                        /* Background */
        TEXT(LDEPO, 1),                        /* M Briefing */
        TEXT(LDEPO, 2),                        /* Q Branch */
        TEXT(LDEPO, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LDEPO, 4), DIFFICULTY_00},       /* Destroy illegal arms cache */
        {TEXT(LDEPO, 5), DIFFICULTY_SECRET},   /* Destroy computer network */
        {TEXT(LDEPO, 6), DIFFICULTY_SECRET},   /* Obtain safe key */
        {TEXT(LDEPO, 7), DIFFICULTY_SECRET},   /* Recover helicopter blueprints */
        {TEXT(LDEPO, 8), DIFFICULTY_AGENT},    /* Locate Trevelyan's train */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
