#ifndef RM_EMULATOR_BASE_H
#define RM_EMULATOR_BASE_H

#include "../shape/Rectangle.h"

class Base {
private:
    Rectangle region;
    int hp;
    bool isRed;
public:
    Base(bool isRed);

    void render();
};

#endif //RM_EMULATOR_BASE_H
