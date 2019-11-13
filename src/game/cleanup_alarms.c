#include "ultra64.h"
#include "game/chrai.h"
#include "game/cleanup_alarms.h"


void cleanupAlarms(void) {
    stop_alarm();
    sub_GAME_7F055EF8();
}


