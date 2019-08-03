#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsiloZ = {
    {                                          /* Mission Briefing */
        TEXT(LSILO, 0),                        /* Background */
        TEXT(LSILO, 1),                        /* M Briefing */
        TEXT(LSILO, 2),                        /* Q Branch */
        TEXT(LSILO, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LSILO, 4), DIFFICULTY_00},       /* Plant bombs in fuel rooms */
        {TEXT(LSILO, 5), DIFFICULTY_AGENT},    /* Photograph satellite */
        {TEXT(LSILO, 6), DIFFICULTY_SECRET},   /* Obtain telemetric data */
        {TEXT(LSILO, 7), DIFFICULTY_SECRET},   /* Retrieve satellite circuitry */
        {TEXT(LSILO, 8), DIFFICULTY_AGENT},    /* Minimize scientist casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
