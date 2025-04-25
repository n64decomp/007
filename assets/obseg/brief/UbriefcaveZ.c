#include "Ubrief.h"

struct BriefStruct UbriefcaveZ = {
    {                                          /* Mission Briefing */
        getStringID(LCAVE, 0),                        /* Background */
        getStringID(LCAVE, 1),                        /* M Briefing */
        getStringID(LCAVE, 2),                        /* Q Branch */
        getStringID(LCAVE, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LCAVE, 4), DIFFICULTY_SECRET},   /* Destroy inlet pump controls */
        {getStringID(LCAVE, 5), DIFFICULTY_SECRET},   /* Destroy outlet pump controls */
        {getStringID(LCAVE, 6), DIFFICULTY_SECRET},   /* Destroy master control console */
        {getStringID(LCAVE, 7), DIFFICULTY_00},       /* Use radio to contact Jack Wade */
      /*{TEXT(LCAVE, 8), DIFFICULTY_AGENT},*/  /* Pursue Trevelyan */
        {getStringID(LCAVE, 9), DIFFICULTY_AGENT},    /* Minimize scientist casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
