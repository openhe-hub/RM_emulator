#ifndef RM_EMULATOR_BULLETMANAGER_H
#define RM_EMULATOR_BULLETMANAGER_H
#include <vector>
#include "emulator/shape/Circle.h"
#include "emulator/object/Bullet.h"

class BulletManager{
private:
    std::vector<Bullet> bullets;
public:
    void addBullet(Point center,float theta);
    void render();
    void update();
};
#endif //RM_EMULATOR_BULLETMANAGER_H
