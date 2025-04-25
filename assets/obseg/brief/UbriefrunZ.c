#include "Ubrief.h"

struct BriefStruct UbriefrunZ = {
    {                                          /* Mission Briefing */
        getStringID(LRUN, 0),                         /* Background */
        getStringID(LRUN, 1),                         /* M Briefing */
        getStringID(LRUN, 2),                         /* Q Branch */
        getStringID(LRUN, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LRUN, 4), DIFFICULTY_AGENT},     /* Find plane ignition key */
        {getStringID(LRUN, 5), DIFFICULTY_00},        /* Destroy heavy gun emplacements */
        {getStringID(LRUN, 6), DIFFICULTY_SECRET},    /* Destroy missile battery */
        {getStringID(LRUN, 7), DIFFICULTY_AGENT},     /* Escape in plane */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
