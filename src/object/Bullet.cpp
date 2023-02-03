#include "Bullet.h"
#include "../utils/Value.h"
#include <cmath>

void Bullet::addBullet(Point center, float theta) {
    bullets.push_back({Value::BULLET_RADIUS, center, {1, 1, 1}});
    orientation.push_back(theta);
}

void Bullet::render() {
    update();
    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i].render();
    }
}

void Bullet::update() {
    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i].move({Value::BULLET_VELOCITY * (float) cos(orientation[i]),
                         Value::BULLET_VELOCITY * (float) sin(orientation[i])});
    }
}
