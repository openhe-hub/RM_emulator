#include "emulator/management/BulletManager.h"
#include "emulator/utils/Value.h"
#include "emulator/utils/Utils.h"
#include <cmath>

void BulletManager::addBullet(Point center, float theta, RobotOwner owner) {
    bullets.emplace_back(center, theta, owner);
}

void BulletManager::render(std::vector<Robot> &robots, Base &redBase, Base &blueBase) {
    update();
    removeBullet(); // remove bullet on barriers
    for (int i = 0; i < bullets.size(); i++) {
        Bullet bullet = bullets[i];
        // test on target robot
        int targetId = Utils::testBulletOnTarget(bullet, robots);
        if (targetId != Value::FAIL_CODE) {
            removeBullet(i);
            robots[targetId].updateHp(-100);
            break;
        }
        // test on target Base
        if (bullet.getOwner() == RobotOwner::OWNER_RED && Utils::testBulletOnBase(bullet, blueBase)) {
            blueBase.updateHp(-100);
            removeBullet(i);
            break;
        } else if (bullet.getOwner() == RobotOwner::OWNER_BLUE && Utils::testBulletOnBase(bullet, redBase)) {
            redBase.updateHp(-100);
            removeBullet(i);
            break;
        }
        bullet.render();
    }
}

void BulletManager::update() {
    for (auto &bullet: bullets) {
        bullet.move({Value::BULLET_VELOCITY * (float) cos(bullet.getTheta()),
                     Value::BULLET_VELOCITY * (float) sin(bullet.getTheta())});
    }
}

void BulletManager::removeBullet() {
    for (int i = 0; i < bullets.size(); i++) {
        if (Utils::testBulletCollision(bullets[i])) {
            bullets.erase(bullets.begin() + i);
        }
    }
}

void BulletManager::removeBullet(int id) {
    bullets.erase(bullets.begin() + id);
}


