#ifndef RM_EMULATOR_BULLET_H
#define RM_EMULATOR_BULLET_H

#include "emulator/shape/Circle.h"
#include "Robot.h"
#include "emulator/utils/Value.h"

class Bullet {
private:
    Circle circle;
    RobotOwner owner;
    float theta;
    int attackValue;
public:
    Bullet(Point point, float theta,RobotOwner owner);

    void render();

    void move(Point vec);

    float getTheta() const;

    Point getCenter();

    RobotOwner getOwner();

    int getAttackValue() const;
};

#endif //RM_EMULATOR_BULLET_H
