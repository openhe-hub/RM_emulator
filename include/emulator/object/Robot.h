#ifndef RM_EMULATOR_ROBOT_H
#define RM_EMULATOR_ROBOT_H

#include "emulator/shape/Rectangle.h"

enum class RobotType {
    TYPE_SENTRY = 1, TYPE_HERO = 2, TYPE_INFANTRY = 3
};

enum class RobotOwner {
    OWNER_RED = 1, OWNER_BLUE = 2
};

class Robot {
private:
    RobotType type;
    RobotOwner owner;
    Rectangle body;
    Rectangle gun;
    Point center;

    int id;
    int hp;
    int exp;
    int level;
//    int energy;
//    int bulletCount;
    float gunTheta, bodyTheta;
public:
    Robot(){}

    Robot(RobotType type,RobotOwner owner,int id);

    void render();

    std::pair<Point,float> shot();

    void rotateGun(float theta);

    void rotateBody(float theta);

    void move(Point point);

    void moveTo(Point destination);

    void info();
};

#endif //RM_EMULATOR_ROBOT_H
