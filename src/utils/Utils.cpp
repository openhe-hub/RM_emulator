#include "Utils.h"
#include "Value.h"

int Utils::toId(RobotType type, RobotOwner owner) {
    return (owner == RobotOwner::OWNER_RED ? -1 : 2) +
           static_cast<int>(type);
}

float Utils::toPx(float meter) {
    return meter * Value::SCALE;
}
