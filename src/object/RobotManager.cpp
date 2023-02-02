#include "RobotManager.h"

void RobotManager::initAll() {
    robots = {
            {RobotType::TYPE_SENTRY,   RobotOwner::OWNER_RED,  1},
            {RobotType::TYPE_HERO,     RobotOwner::OWNER_RED,  2},
            {RobotType::TYPE_INFANTRY, RobotOwner::OWNER_RED,  3},
            {RobotType::TYPE_SENTRY,   RobotOwner::OWNER_BLUE, 4},
            {RobotType::TYPE_HERO,     RobotOwner::OWNER_BLUE, 5},
            {RobotType::TYPE_INFANTRY, RobotOwner::OWNER_BLUE, 6},
    };
}

void RobotManager::renderAll() {
    for (auto &robot: robots) {
        robot.render();
    }
}

void RobotManager::updateRobot(int id, float x, float y) {

}

void RobotManager::removeRobot(int id) {

}


