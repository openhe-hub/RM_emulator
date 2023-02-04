#include "emulator/management/BulletManager.h"
#include "emulator/utils/Value.h"
#include <cmath>

void BulletManager::addBullet(Point center, float theta) {
    bullets.emplace_back(center,theta);
}

void BulletManager::render() {
    update();
    for (auto & bullet : bullets) {
        bullet.render();
    }
}

void BulletManager::update() {
    for (auto & bullet : bullets) {
        bullet.move({Value::BULLET_VELOCITY * (float) cos(bullet.getTheta()),
                         Value::BULLET_VELOCITY * (float) sin(bullet.getTheta())});
    }
}