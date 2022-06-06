#include "Ubrief.h"

struct BriefStruct UbriefsevxbZ = {
    {                                          /* Mission Briefing */
        TEXT(LSEVXB, 0),                       /* Background */
        TEXT(LSEVXB, 1),                       /* M Briefing */
        TEXT(LSEVXB, 2),                       /* Q Branch */
        TEXT(LSEVXB, 3)                        /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LSEVXB, 4), DIFFICULTY_00},      /* Disrupt all surveillance equipment */
        {TEXT(LSEVXB, 5), DIFFICULTY_AGENT},   /* Break communications link to bunker */
        {TEXT(LSEVXB, 6), DIFFICULTY_SECRET},  /* Disable Spetznaz support aircraft */
        {TEXT(LSEVXB, 7), DIFFICULTY_AGENT},   /* Gain entry to bunker */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
