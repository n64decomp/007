#include "Ubrief.h"

struct BriefStruct UbriefjunZ = {
    {                                          /* Mission Briefing */
        getStringID(LJUN, 0),                         /* Background */
        getStringID(LJUN, 1),                         /* M Briefing */
        getStringID(LJUN, 2),                         /* Q Branch */
        getStringID(LJUN, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LJUN, 4), DIFFICULTY_AGENT},     /* Destroy drone guns */
        {getStringID(LJUN, 5), DIFFICULTY_AGENT},     /* Eliminate Xenia */
        {getStringID(LJUN, 6), DIFFICULTY_SECRET},    /* Blow up ammo dump */
        {getStringID(LJUN, 7), DIFFICULTY_AGENT},     /* Escort Natalya to Janus Base */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
