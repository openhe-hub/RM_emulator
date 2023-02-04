#ifndef RM_EMULATOR_BULLET_H
#define RM_EMULATOR_BULLET_H
#include <vector>
#include "emulator/shape/Circle.h"

class Bullet{
private:
    std::vector<Circle> bullets;
    std::vector<float> orientation;
public:
    void addBullet(Point center,float theta);
    void render();
    void update();
};
#endif //RM_EMULATOR_BULLET_H
