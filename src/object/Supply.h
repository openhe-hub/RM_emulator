#ifndef RM_EMULATOR_SUPPLY_H
#define RM_EMULATOR_SUPPLY_H
#include "../shape/Rectangle.h"
class Supply{
private:
    bool isRed;
    Rectangle region;
public:
    Supply(bool isRed);
    void render();
};
#endif //RM_EMULATOR_SUPPLY_H
