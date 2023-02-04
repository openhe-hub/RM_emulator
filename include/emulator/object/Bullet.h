#ifndef RM_EMULATOR_BULLET_H
#define RM_EMULATOR_BULLET_H

#include "emulator/shape/Circle.h"
#include "Robot.h"
#include "emulator/utils/Value.h"

class Bullet {
private:
    Circle circle;
//    RobotOwner owner;
//    BulletType type;
    float theta;
    int attackValue;
public:
    Bullet(Point point, float theta);

    void render();

    void move(Point vec);

    float getTheta() const;
};

#endif //RM_EMULATOR_BULLET_H
