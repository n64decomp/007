#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefaztZ = {
    {                                          /* Mission Briefing */
        TEXT(LAZT, 0),                         /* Background */
        TEXT(LAZT, 1),                         /* M Briefing */
        TEXT(LAZT, 2),                         /* Q Branch */
        TEXT(LAZT, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LAZT, 4), DIFFICULTY_AGENT},     /* Reprogram shuttle guidance */
        {TEXT(LAZT, 5), DIFFICULTY_AGENT},     /* Launch shuttle */
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
