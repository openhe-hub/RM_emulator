#ifndef RM_EMULATOR_BULLETMANAGER_H
#define RM_EMULATOR_BULLETMANAGER_H
#include <vector>
#include "emulator/shape/Circle.h"
#include "emulator/object/Bullet.h"
#include "emulator/object/Base.h"

class BulletManager{
private:
    std::vector<Bullet> bullets;
    void update();
public:
    void addBullet(Point center,float theta,RobotOwner owner);
    void render(std::vector<Robot> &robots,Base &redBase,Base &blueBase);
    void removeBullet();
    void removeBullet(int id);
};
#endif //RM_EMULATOR_BULLETMANAGER_H
