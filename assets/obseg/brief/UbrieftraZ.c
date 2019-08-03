#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbrieftraZ = {
    {                                          /* Mission Briefing */
        TEXT(LTRA, 0),                         /* Background */
        TEXT(LTRA, 1),                         /* M Briefing */
        TEXT(LTRA, 2),                         /* Q Branch */
        TEXT(LTRA, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LTRA, 4), DIFFICULTY_AGENT},     /* Destroy break units */
        {TEXT(LTRA, 5), DIFFICULTY_AGENT},     /* Rescue Natalya */
        {TEXT(LTRA, 6), DIFFICULTY_SECRET},    /* Locate Janus secret base */
        {TEXT(LTRA, 7), DIFFICULTY_00},        /* Crack Boris' password */
        {TEXT(LTRA, 8), DIFFICULTY_AGENT},     /* Escape to safety */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
