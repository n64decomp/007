#include "Ubrief.h"

struct BriefStruct UbriefsiloZ = {
    {                                          /* Mission Briefing */
        getStringID(LSILO, 0),                        /* Background */
        getStringID(LSILO, 1),                        /* M Briefing */
        getStringID(LSILO, 2),                        /* Q Branch */
        getStringID(LSILO, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LSILO, 4), DIFFICULTY_00},       /* Plant bombs in fuel rooms */
        {getStringID(LSILO, 5), DIFFICULTY_AGENT},    /* Photograph satellite */
        {getStringID(LSILO, 6), DIFFICULTY_SECRET},   /* Obtain telemetric data */
        {getStringID(LSILO, 7), DIFFICULTY_SECRET},   /* Retrieve satellite circuitry */
        {getStringID(LSILO, 8), DIFFICULTY_AGENT},    /* Minimize scientist casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
