#include "Ubrief.h"

struct BriefStruct UbriefcaveZ = {
    {                                          /* Mission Briefing */
        TEXT(LCAVE, 0),                        /* Background */
        TEXT(LCAVE, 1),                        /* M Briefing */
        TEXT(LCAVE, 2),                        /* Q Branch */
        TEXT(LCAVE, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LCAVE, 4), DIFFICULTY_SECRET},   /* Destroy inlet pump controls */
        {TEXT(LCAVE, 5), DIFFICULTY_SECRET},   /* Destroy outlet pump controls */
        {TEXT(LCAVE, 6), DIFFICULTY_SECRET},   /* Destroy master control console */
        {TEXT(LCAVE, 7), DIFFICULTY_00},       /* Use radio to contact Jack Wade */
      /*{TEXT(LCAVE, 8), DIFFICULTY_AGENT},*/  /* Pursue Trevelyan */
        {TEXT(LCAVE, 9), DIFFICULTY_AGENT},    /* Minimize scientist casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
