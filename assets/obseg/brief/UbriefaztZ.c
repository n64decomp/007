#include "Ubrief.h"

struct BriefStruct UbriefaztZ = {
    {                                          /* Mission Briefing */
        getStringID(LAZT, 0),                         /* Background */
        getStringID(LAZT, 1),                         /* M Briefing */
        getStringID(LAZT, 2),                         /* Q Branch */
        getStringID(LAZT, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LAZT, 4), DIFFICULTY_AGENT},     /* Reprogram shuttle guidance */
        {getStringID(LAZT, 5), DIFFICULTY_AGENT},     /* Launch shuttle */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
