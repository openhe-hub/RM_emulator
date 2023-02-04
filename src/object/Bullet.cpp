
#include "emulator/object/Bullet.h"

Bullet::Bullet(Point point, float theta) : theta(theta) {
    circle = {Value::BULLET_RADIUS, point, {1, 1, 1}};
}

void Bullet::render() {
    circle.render();
}

void Bullet::move(Point vec) {
    circle.move(vec);
}

float Bullet::getTheta() const {
    return theta;
}

