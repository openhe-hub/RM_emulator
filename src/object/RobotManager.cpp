#include <iostream>
#include <GL/glut.h>
#include "RobotManager.h"
#include "../utils/Utils.h"

void RobotManager::initAll() {
    robots = {
            {RobotType::TYPE_SENTRY,   RobotOwner::OWNER_RED,  1},
            {RobotType::TYPE_HERO,     RobotOwner::OWNER_RED,  2},
            {RobotType::TYPE_INFANTRY, RobotOwner::OWNER_RED,  3},
            {RobotType::TYPE_SENTRY,   RobotOwner::OWNER_BLUE, 4},
            {RobotType::TYPE_HERO,     RobotOwner::OWNER_BLUE, 5},
            {RobotType::TYPE_INFANTRY, RobotOwner::OWNER_BLUE, 6},
    };
    isBegin = true;
}

void RobotManager::renderAll() {
    if (!isBegin) initAll();
    for (auto &robot: robots) {
        robot.render();
    }
    glutSwapBuffers();
}

void RobotManager::reportAll() {
    if (!isBegin) initAll();
    for (auto &robot: robots) {
        robot.info();
    }
    std::cout << "======================================================================================" << std::endl;
}

void RobotManager::updateRobot(RobotType type, RobotOwner owner, Point coordination) {
    robots[Utils::toId(type, owner)].moveTo({Utils::toPx(coordination.getX()),Utils::toPx(coordination.getY())});
}

void RobotManager::removeRobot(RobotType type, RobotOwner owner) {
    robots.erase(robots.begin() + Utils::toId(type, owner));
}

void RobotManager::moveRobot(RobotType type, RobotOwner owner, Point vec) {
    robots[Utils::toId(type, owner)].move({Utils::toPx(vec.getX()),Utils::toPx(vec.getY())});
}

void RobotManager::rotateRobotBody(RobotType type, RobotOwner owner, float theta) {
    robots[Utils::toId(type, owner)].rotateBody(theta);
}

void RobotManager::rotateRobotGun(RobotType type, RobotOwner owner, float theta) {
    robots[Utils::toId(type, owner)].rotateGun(theta);
}

void RobotManager::fireRobot(RobotType type, RobotOwner owner) {
    robots[Utils::toId(type, owner)].shot();
}





