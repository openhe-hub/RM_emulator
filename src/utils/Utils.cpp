#include "emulator/utils/Utils.h"
#include "emulator/utils/Value.h"

int Utils::toId(RobotType type, RobotOwner owner) {
    return (owner == RobotOwner::OWNER_RED ? -1 : 2) +
           static_cast<int>(type);
}

float Utils::toPx(float meter) {
    return meter * Value::SCALE;
}

bool Utils::testCollision(Point point) {
    float x = point.getX();
    float y = point.getY();
    if (x < -Value::MAP_WIDTH / 2 || x > Value::MAP_WIDTH ||
        y < -Value::MAP_HEIGHT / 2 || y > Value::MAP_HEIGHT / 2) {
        return false;
    }
    return true;
}

bool Utils::testBulletOnTarget(Bullet bullet, std::vector<Robot> robots) {
    return false;
}

bool Utils::testBulletOnBase(Bullet bullet, Base base) {
    return false;
}
