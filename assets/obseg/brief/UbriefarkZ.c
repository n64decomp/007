#include "assets/obseg/brief/Ubrief.h"

struct BriefStruct UbriefarkZ = {
    {                                          /* Mission Briefing */
        TEXT(LARK, 0),                         /* Background */
        TEXT(LARK, 1),                         /* M Briefing */
        TEXT(LARK, 2),                         /* Q Branch */
        TEXT(LARK, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {TEXT(LARK, 4), DIFFICULTY_AGENT},     /* Gain entry to lab area */
        {TEXT(LARK, 5), DIFFICULTY_SECRET},    /* Contact double agent */
        {TEXT(LARK, 6), DIFFICULTY_AGENT},     /* Rendezvous with 006 */
        {TEXT(LARK, 7), DIFFICULTY_AGENT},     /* Destroy all tanks in bottling room */
        {TEXT(LARK, 8), DIFFICULTY_AGENT},     /* Minimize scientist casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
