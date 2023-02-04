#ifndef RM_EMULATOR_UTILS_H
#define RM_EMULATOR_UTILS_H

#include "emulator/object/Robot.h"
#include "emulator/object/Bullet.h"
#include "emulator/object/Base.h"
#include <vector>

class Utils {
public:
    static int toId(RobotType type, RobotOwner owner);

    static float toPx(float meter);

    bool testBulletOnTarget(Bullet bullet, std::vector<Robot> robots);

    bool testBulletOnBase(Bullet bullet, Base base);

    bool testCollision(Point point);
};

#endif //RM_EMULATOR_UTILS_H
