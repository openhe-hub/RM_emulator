#include "emulator/management/TimeManager.h"
#include "emulator/utils/Value.h"

uint8_t TimeManager::startMatchTimer() {
    time(&matchTimer.start);
    matchTimer.status = Value::TIMER_STARTED;
    return matchTimer.status;
}

double TimeManager::getDiffSeconds() {
    time(&matchTimer.curr);
    return difftime(matchTimer.curr, matchTimer.start);
}
