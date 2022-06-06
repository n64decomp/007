#include "Ubrief.h"

struct BriefStruct UbriefrunZ = {
    {                                          /* Mission Briefing */
        TEXT(LRUN, 0),                         /* Background */
        TEXT(LRUN, 1),                         /* M Briefing */
        TEXT(LRUN, 2),                         /* Q Branch */
        TEXT(LRUN, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LRUN, 4), DIFFICULTY_AGENT},     /* Find plane ignition key */
        {TEXT(LRUN, 5), DIFFICULTY_00},        /* Destroy heavy gun emplacements */
        {TEXT(LRUN, 6), DIFFICULTY_SECRET},    /* Destroy missile battery */
        {TEXT(LRUN, 7), DIFFICULTY_AGENT},     /* Escape in plane */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
