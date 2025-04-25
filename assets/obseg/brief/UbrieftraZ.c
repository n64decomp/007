#include "Ubrief.h"

struct BriefStruct UbrieftraZ = {
    {                                          /* Mission Briefing */
        getStringID(LTRA, 0),                         /* Background */
        getStringID(LTRA, 1),                         /* M Briefing */
        getStringID(LTRA, 2),                         /* Q Branch */
        getStringID(LTRA, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LTRA, 4), DIFFICULTY_AGENT},     /* Destroy brake units */
        {getStringID(LTRA, 5), DIFFICULTY_AGENT},     /* Rescue Natalya */
        {getStringID(LTRA, 6), DIFFICULTY_SECRET},    /* Locate Janus secret base */
        {getStringID(LTRA, 7), DIFFICULTY_00},        /* Crack Boris' password */
        {getStringID(LTRA, 8), DIFFICULTY_AGENT},     /* Escape to safety */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
