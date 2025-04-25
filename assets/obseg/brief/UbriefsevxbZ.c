#include "Ubrief.h"

struct BriefStruct UbriefsevxbZ = {
    {                                          /* Mission Briefing */
        getStringID(LSEVXB, 0),                       /* Background */
        getStringID(LSEVXB, 1),                       /* M Briefing */
        getStringID(LSEVXB, 2),                       /* Q Branch */
        getStringID(LSEVXB, 3)                        /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LSEVXB, 4), DIFFICULTY_00},      /* Disrupt all surveillance equipment */
        {getStringID(LSEVXB, 5), DIFFICULTY_AGENT},   /* Break communications link to bunker */
        {getStringID(LSEVXB, 6), DIFFICULTY_SECRET},  /* Disable Spetznaz support aircraft */
        {getStringID(LSEVXB, 7), DIFFICULTY_AGENT},   /* Gain entry to bunker */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
