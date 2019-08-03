#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefsevbunkerZ = {
    {                                          /* Mission Briefing */
        TEXT(LSEV, 0),                         /* Background */
        TEXT(LSEV, 1),                         /* M Briefing */
        TEXT(LSEV, 2),                         /* Q Branch */
        TEXT(LSEV, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LSEV, 4), DIFFICULTY_SECRET},    /* Disrupt all surveillance equipment */
        {TEXT(LSEV, 5), DIFFICULTY_AGENT},     /* Copy Goldeneye key and leave original */
        {TEXT(LSEV, 6), DIFFICULTY_00},        /* Get personnel to activate computer */
        {TEXT(LSEV, 7), DIFFICULTY_00},        /* Download data from computer */
        {TEXT(LSEV, 8), DIFFICULTY_AGENT},     /* Photograph main video screen */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
