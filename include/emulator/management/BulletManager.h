#ifndef RM_EMULATOR_BULLETMANAGER_H
#define RM_EMULATOR_BULLETMANAGER_H
#include <vector>
#include "emulator/shape/Circle.h"
#include "emulator/object/Bullet.h"

class BulletManager{
private:
    std::vector<Bullet> bullets;
    void removeBullet();
    void update();
public:
    void addBullet(Point center,float theta);
    void render();

};
#endif //RM_EMULATOR_BULLETMANAGER_H
