#include <ultra64.h>
#include "chrai.h"
#include "cleanup_alarms.h"


void cleanupAlarms(void) {
    alarmDeactivate();
    check_deactivate_gas_sound();
}


