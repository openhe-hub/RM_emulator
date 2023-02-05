#ifndef RM_EMULATOR_BASE_H
#define RM_EMULATOR_BASE_H

#include "emulator/shape/Rectangle.h"
#include "emulator/object/Robot.h"

class Base {
private:
    Rectangle region;
    RobotOwner owner;
    int hp;
    bool isRed;
public:
    Base(){}
    Base(bool isRed);
    void render();
    RobotOwner getOwner();
    void updateHp(int deltaHp);
};

#endif //RM_EMULATOR_BASE_H
