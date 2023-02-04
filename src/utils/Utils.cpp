#include "emulator/utils/Utils.h"
#include "emulator/utils/Value.h"
#include <cmath>

int Utils::toId(RobotType type, RobotOwner owner) {
    return (owner == RobotOwner::OWNER_RED ? -1 : 2) +
           static_cast<int>(type);
}

float Utils::toPx(float meter) {
    return meter * Value::SCALE;
}


bool Utils::testBulletOnTarget(Bullet bullet, std::vector<Robot> robots) {
    return false;
}

bool Utils::testBulletOnBase(Bullet bullet, Base base) {
    return false;
}

bool Utils::testBulletCollision(Bullet bullet) {
    float x = bullet.getCenter().getX();
    float y = bullet.getCenter().getY();
    // outside
    if (x < -Value::MAP_WIDTH / 2 || x > Value::MAP_WIDTH / 2 ||
        y < -Value::MAP_HEIGHT / 2 || y > Value::MAP_HEIGHT / 2) {
        return true;
    }
    // left-corner barrier1
    if (isNearX(x, Value::BARRIER_X)
        && isInRange(y, -Value::MAP_HEIGHT / 2, -Value::MAP_HEIGHT / 2 + Value::BARRIER_LENGTH)) {
        return true;
    }
    // left-corner barrier2
    if (isNearY(y, Value::BARRIER_Y)
        && isInRange(x, -Value::MAP_WIDTH / 2, -Value::MAP_WIDTH / 2 + Value::BARRIER_LENGTH)) {
        return true;
    }
    // right-corner barrier1
    if (isNearX(x, -Value::BARRIER_X)
        && isInRange(y, Value::MAP_HEIGHT / 2 - Value::BARRIER_LENGTH, Value::MAP_HEIGHT / 2)) {
        return true;
    }
    // right-corner barrier2
    if (isNearY(y, -Value::BARRIER_Y)
        && isInRange(x, Value::MAP_WIDTH / 2 - Value::BARRIER_LENGTH, Value::MAP_WIDTH / 2)) {
        return true;
    }
    // center barrier 1
    if (isNearX(x,-111)&& isInRange(y,-82,-82+Value::CENTER_BARRIER_LENGTH)){
        return true;
    }
    // center barrier 2
    if (isNearX(x,111)&& isInRange(y,82-Value::CENTER_BARRIER_LENGTH,82)){
        return true;
    }
    return false;
}

bool Utils::testRobotCollision(Robot robot) {
    return false;
}

bool Utils::isNearX(float x, float targetX) {
    return fabs(x - targetX) < Value::TARGET_DIFF_DIS;
}

bool Utils::isNearY(float y, float targetY) {
    return fabs(y - targetY) < Value::TARGET_DIFF_DIS;
}

bool Utils::isNearPoint(Point point, Point targetPoint) {
    return sqrt(pow((point.getX() - targetPoint.getX()), 2) +
                pow((point.getY() - targetPoint.getY()), 2))
           < Value::TARGET_DIFF_DIS;
}

bool Utils::isInRange(float x, float min, float max) {
    return x <= max && x >= min;
}
