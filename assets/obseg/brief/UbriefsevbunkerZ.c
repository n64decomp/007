#include "Ubrief.h"

struct BriefStruct UbriefsevbunkerZ = {
    {                                          /* Mission Briefing */
        getStringID(LSEV, 0),                         /* Background */
        getStringID(LSEV, 1),                         /* M Briefing */
        getStringID(LSEV, 2),                         /* Q Branch */
        getStringID(LSEV, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LSEV, 4), DIFFICULTY_SECRET},    /* Disrupt all surveillance equipment */
        {getStringID(LSEV, 5), DIFFICULTY_AGENT},     /* Copy Goldeneye key and leave original */
        {getStringID(LSEV, 6), DIFFICULTY_00},        /* Get personnel to activate computer */
        {getStringID(LSEV, 7), DIFFICULTY_00},        /* Download data from computer */
        {getStringID(LSEV, 8), DIFFICULTY_AGENT},     /* Photograph main video screen */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
