#ifndef RM_EMULATOR_START_H
#define RM_EMULATOR_START_H

#include "emulator/shape/Rectangle.h"

class Start {
private:
    Rectangle region;
    Color3f color;
public:
    Start(bool isRed);
    void render();
};

#endif //RM_EMULATOR_START_H
