#include "Ubrief.h"

struct BriefStruct UbriefstatueZ = {
    {                                          /* Mission Briefing */
        TEXT(LSTAT, 0),                        /* Background */
        TEXT(LSTAT, 1),                        /* M Briefing */
        TEXT(LSTAT, 2),                        /* Q Branch */
        TEXT(LSTAT, 3)                         /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LSTAT, 4), DIFFICULTY_AGENT},    /* Contact Valentin */
        {TEXT(LSTAT, 5), DIFFICULTY_AGENT},    /* Confront and unmask Janus */
        {TEXT(LSTAT, 6), DIFFICULTY_AGENT},    /* Locate helicopter */
        {TEXT(LSTAT, 7), DIFFICULTY_AGENT},    /* Rescue Natalya */
        {TEXT(LSTAT, 8), DIFFICULTY_AGENT},    /* Find flight recorder */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
