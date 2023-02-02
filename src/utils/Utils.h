#ifndef RM_EMULATOR_UTILS_H
#define RM_EMULATOR_UTILS_H

#include "../object/Robot.h"

class Utils {
public:
    static int toId(RobotType type, RobotOwner owner);
};

#endif //RM_EMULATOR_UTILS_H
