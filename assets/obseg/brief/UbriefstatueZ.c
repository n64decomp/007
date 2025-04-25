#include "Ubrief.h"

struct BriefStruct UbriefstatueZ = {
    {                                          /* Mission Briefing */
        getStringID(LSTAT, 0),                        /* Background */
        getStringID(LSTAT, 1),                        /* M Briefing */
        getStringID(LSTAT, 2),                        /* Q Branch */
        getStringID(LSTAT, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LSTAT, 4), DIFFICULTY_AGENT},    /* Contact Valentin */
        {getStringID(LSTAT, 5), DIFFICULTY_AGENT},    /* Confront and unmask Janus */
        {getStringID(LSTAT, 6), DIFFICULTY_AGENT},    /* Locate helicopter */
        {getStringID(LSTAT, 7), DIFFICULTY_AGENT},    /* Rescue Natalya */
        {getStringID(LSTAT, 8), DIFFICULTY_AGENT},    /* Find flight recorder */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
