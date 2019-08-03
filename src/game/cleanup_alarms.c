#include "ultra64.h"
#include "game/actionblock.h"
#include "game/cleanup_alarms.h"


void cleanupAlarms(void) {
    stop_alarm();
    sub_GAME_7F055EF8();
}


