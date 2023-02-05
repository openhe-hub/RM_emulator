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

    static bool isNearX(float x, float targetX);

    static bool isNearY(float y, float targetY);

    static bool isNearPoint(Point point, Point targetPoint);

    static bool isNearPoint(Point point, Point targetPoint, float diffRadius);

    static bool isInRange(float x, float min, float max);

    static int testBulletOnTarget(Bullet bullet, std::vector<Robot> robots);

    static bool testBulletOnBase(Bullet bullet, Base base);

    static bool testBulletCollision(Bullet bullet);

    static bool testRobotCollision(Robot robot);
};

#endif //RM_EMULATOR_UTILS_H
