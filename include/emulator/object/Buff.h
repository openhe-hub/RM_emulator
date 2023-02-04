#ifndef RM_EMULATOR_BUFF_H
#define RM_EMULATOR_BUFF_H

#include <vector>
#include "emulator/shape/Rectangle.h"
#include "emulator/shape/Polygon.h"

class Buff {
private:
    Rectangle outline;
    std::vector<Rectangle> icon;
    float buffTime;
public:
    Buff();

    void render();
};

#endif //RM_EMULATOR_BUFF_H
