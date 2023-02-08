#ifndef RM_EMULATOR_TIMEMANAGER_H
#define RM_EMULATOR_TIMEMANAGER_H

#include <ctime>
#include <cstdint>

struct Timer {
    time_t start;
    time_t curr;
    double length;
    uint8_t status;
};

class TimeManager {
private:
    Timer matchTimer;
    Timer buffTimer;
    Timer baseTimer;
public:
    uint8_t startMatchTimer();
    double getDiffSeconds(); // return how long the match has begun, in sec
};


#endif //RM_EMULATOR_TIMEMANAGER_H
