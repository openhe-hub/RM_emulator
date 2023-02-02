#include "Utils.h"

int Utils::toId(RobotType type, RobotOwner owner) {
    return (owner == RobotOwner::OWNER_RED ? -1 : 2) +
           static_cast<int>(type);
}
