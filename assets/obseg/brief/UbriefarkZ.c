#include "Ubrief.h"

struct BriefStruct UbriefarkZ = {
    {                                          /* Mission Briefing */
        getStringID(LARK, 0),                         /* Background */
        getStringID(LARK, 1),                         /* M Briefing */
        getStringID(LARK, 2),                         /* Q Branch */
        getStringID(LARK, 3)                          /* Moneypenny */
    },
    {                                          /* Objectives (Text and Difficult) */
        {getStringID(LARK, 4), DIFFICULTY_AGENT},     /* Gain entry to lab area */
        {getStringID(LARK, 5), DIFFICULTY_SECRET},    /* Contact double agent */
        {getStringID(LARK, 6), DIFFICULTY_AGENT},     /* Rendezvous with 006 */
        {getStringID(LARK, 7), DIFFICULTY_AGENT},     /* Destroy all tanks in bottling room */
        {getStringID(LARK, 8), DIFFICULTY_AGENT},     /* Minimize scientist casualties */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0},                                /* Not assigned */
        {0, 0}                                 /* Not assigned */
    }
};
