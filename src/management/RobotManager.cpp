#include <iostream>
#include <GL/glut.h>
#include "emulator/management/RobotManager.h"
#include "emulator/utils/Utils.h"

void RobotManager::initAll() {
    robots = {
            {RobotType::TYPE_SENTRY,   RobotOwner::OWNER_RED,  1},
            {RobotType::TYPE_HERO,     RobotOwner::OWNER_RED,  2},
            {RobotType::TYPE_INFANTRY, RobotOwner::OWNER_RED,  3},
            {RobotType::TYPE_SENTRY,   RobotOwner::OWNER_BLUE, 4},
            {RobotType::TYPE_HERO,     RobotOwner::OWNER_BLUE, 5},
            {RobotType::TYPE_INFANTRY, RobotOwner::OWNER_BLUE, 6},
    };
    redBase = {true}, blueBase = {false};
    redSupply = {true}, blueSupply = {false};
    isBegin = true;
    time(&start);
}

void RobotManager::renderAll() {
    if (!isBegin) initAll();
    // render robots
    for (auto &robot: robots) {
        robot.render();
    }
    // render bullets
    bulletManager.render(robots, redBase, blueBase);
    glutSwapBuffers();
}

void RobotManager::reportAll() {
    if (!isBegin) initAll();

    time(&curr);
    double diff = difftime(curr, start);
    std::cout << "===================================[ " << diff
              << " s ]===================================================\n";
    if (!isBegin) initAll();
    for (auto &robot: robots) {
        robot.info();
    }
    std::cout << "========================================================"
                 "=====================================\n\n";
}

void RobotManager::updateRobot(RobotType type, RobotOwner owner, Point coordination) {
    robots[Utils::toId(type, owner)].moveTo({Utils::toPx(coordination.getX()), Utils::toPx(coordination.getY())});
}

void RobotManager::removeRobot(RobotType type, RobotOwner owner) {
    robots.erase(robots.begin() + Utils::toId(type, owner));
}

void RobotManager::moveRobot(RobotType type, RobotOwner owner, Point vec) {
    robots[Utils::toId(type, owner)].move({Utils::toPx(vec.getX()), Utils::toPx(vec.getY())});
}

void RobotManager::rotateRobotBody(RobotType type, RobotOwner owner, float theta) {
    robots[Utils::toId(type, owner)].rotateBody(theta);
}

void RobotManager::rotateRobotGun(RobotType type, RobotOwner owner, float theta) {
    robots[Utils::toId(type, owner)].rotateGun(theta);
}

void RobotManager::fireRobot(RobotType type, RobotOwner owner) {
    int id = Utils::toId(type, owner);
    std::pair<Point, float> fireInfo = robots[id].shot();
    bulletManager.addBullet(fireInfo.first, fireInfo.second, robots[id].getOwner());
}

void RobotManager::updateRobot(int id, Point coordination) {
    robots[id].moveTo({Utils::toPx(coordination.getX()), Utils::toPx(coordination.getY())});
}

void RobotManager::removeRobot(int id, RobotOwner owner) {
    robots.erase(robots.begin() + id);
}

void RobotManager::moveRobot(int id, Point vec) {
    robots[id].move({Utils::toPx(vec.getX()), Utils::toPx(vec.getY())});
}

void RobotManager::rotateRobotBody(int id, float theta) {
    robots[id].rotateBody(theta);
}

void RobotManager::rotateRobotGun(int id, float theta) {
    robots[id].rotateGun(theta);
}

void RobotManager::fireRobot(int id) {
    std::pair<Point, float> fireInfo = robots[id].shot();
    bulletManager.addBullet(fireInfo.first, fireInfo.second, robots[id].getOwner());
}

void RobotManager::lossHpRobot(RobotType type, RobotOwner owner, int deltaHp) {
    robots[Utils::toId(type, owner)].updateHp(deltaHp);
}

void RobotManager::lossHpRobot(int id, int deltaHp) {
    robots[id].updateHp(deltaHp);
}





