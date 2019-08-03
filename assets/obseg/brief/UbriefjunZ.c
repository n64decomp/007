#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefjunZ = {
    {                                          /* Mission Briefing */
        TEXT(LJUN, 0),                         /* Background */
        TEXT(LJUN, 1),                         /* M Briefing */
        TEXT(LJUN, 2),                         /* Q Branch */
        TEXT(LJUN, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LJUN, 4), DIFFICULTY_AGENT},     /* Destroy drone guns */
        {TEXT(LJUN, 5), DIFFICULTY_AGENT},     /* Eliminate Xenia */
        {TEXT(LJUN, 6), DIFFICULTY_SECRET},    /* Blow up ammo dump */
        {TEXT(LJUN, 7), DIFFICULTY_AGENT},     /* Escort Natalya to Janus Base */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
