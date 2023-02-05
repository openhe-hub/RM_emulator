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


int Utils::testBulletOnTarget(Bullet bullet, std::vector<Robot> robots) {
    for (int i = 0; i < robots.size(); i++) {
        Robot robot = robots[i];
        if (bullet.getOwner() == robot.getOwner()) continue; // omit friend robot's attack
        if (isNearPoint(robot.getCenter(), bullet.getCenter(), Value::ROBOT_TARGET_RADIUS)) {
            return i;
        }
    }
    return Value::FAIL_CODE;
}

bool Utils::testBulletOnBase(Bullet bullet, Base base) {
    float x = bullet.getCenter().getX();
    float y = bullet.getCenter().getY();
    if (base.getOwner() == RobotOwner::OWNER_RED) {
        if (Value::BASE_X - Value::BASE_SIZE / 2 <= x
            && Value::BASE_X + Value::BASE_SIZE / 2 >= x
            && Value::BASE_Y - Value::BASE_SIZE / 2 <= y
            && Value::BASE_Y + Value::BASE_SIZE / 2 >= y) {
            return true;
        }
    }
    if (base.getOwner() == RobotOwner::OWNER_BLUE) {
        if (-Value::BASE_X - Value::BASE_SIZE / 2 <= x
            && -Value::BASE_X + Value::BASE_SIZE / 2 >= x
            && -Value::BASE_Y - Value::BASE_SIZE / 2 <= y
            && -Value::BASE_Y + Value::BASE_SIZE / 2 >= y) {
            return true;
        }
    }
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
    if ((isNearX(x, Value::BARRIER_X)
         && isInRange(y, -Value::MAP_HEIGHT / 2, -Value::MAP_HEIGHT / 2 + Value::BARRIER_LENGTH))
        || isNearPoint(bullet.getCenter(), {Value::BARRIER_X, -Value::MAP_HEIGHT / 2 + Value::BARRIER_LENGTH}, 10)) {
        return true;
    }
    // left-corner barrier2
    if ((isNearY(y, Value::BARRIER_Y)
         && isInRange(x, -Value::MAP_WIDTH / 2, -Value::MAP_WIDTH / 2 + Value::BARRIER_LENGTH))
        || isNearPoint(bullet.getCenter(), {-Value::MAP_WIDTH / 2 + Value::BARRIER_LENGTH, Value::BARRIER_Y}, 10)) {
        return true;
    }
    // right-corner barrier1
    if ((isNearX(x, -Value::BARRIER_X)
         && isInRange(y, Value::MAP_HEIGHT / 2 - Value::BARRIER_LENGTH, Value::MAP_HEIGHT / 2))
        || isNearPoint(bullet.getCenter(), {-Value::BARRIER_X, Value::MAP_HEIGHT / 2 - Value::BARRIER_LENGTH}, 10)) {
        return true;
    }
    // right-corner barrier2
    if ((isNearY(y, -Value::BARRIER_Y)
         && isInRange(x, Value::MAP_WIDTH / 2 - Value::BARRIER_LENGTH, Value::MAP_WIDTH / 2))
        || isNearPoint(bullet.getCenter(), {Value::MAP_WIDTH / 2 - Value::BARRIER_LENGTH, -Value::BARRIER_Y}, 10)) {
        return true;
    }
    // center barrier 1
    if (isNearX(x, -111) && isInRange(y, -82, -82 + Value::CENTER_BARRIER_LENGTH)) {
        return true;
    }
    // center barrier 2
    if (isNearX(x, 111) && isInRange(y, 82 - Value::CENTER_BARRIER_LENGTH, 82)) {
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
    isNearPoint(point, targetPoint, Value::TARGET_DIFF_DIS);
}

bool Utils::isNearPoint(Point point, Point targetPoint, float diffRadius) {
    return sqrt(pow((point.getX() - targetPoint.getX()), 2) +
                pow((point.getY() - targetPoint.getY()), 2))
           < diffRadius;
}


bool Utils::isInRange(float x, float min, float max) {
    return x <= max && x >= min;
}

