#ifndef RM_EMULATOR_ROBOTMANAGER_H
#define RM_EMULATOR_ROBOTMANAGER_H
#include "Robot.h"
#include "BulletManager.h"
#include "Base.h"
#include "Buff.h"
#include "Supply.h"
#include <ctime>

class RobotManager{
private:
    std::vector<Robot> robots;
    BulletManager bullet;
    Supply redSupply,blueSupply;
    Buff buff;
    Base redBase,blueBase;

    bool isBegin= false;
    time_t start=0,curr=0;
    RobotManager()=default;
    ~RobotManager()=default;
public:
    // industry mode
    static RobotManager& getInstance(){
        static RobotManager robotManager;
        return robotManager;
    }
    RobotManager(const RobotManager&)=delete;
    RobotManager(RobotManager&&)=delete;
    RobotManager &operator=(const RobotManager&)=delete;
    RobotManager &operator=(RobotManager&&)=delete;

    void initAll();
    void renderAll();
    void reportAll();

    void updateRobot(RobotType type,RobotOwner owner,Point coordination);
    void removeRobot(RobotType type,RobotOwner owner);
    void moveRobot(RobotType type,RobotOwner owner,Point vec);
    void rotateRobotBody(RobotType type,RobotOwner owner, float theta);
    void rotateRobotGun(RobotType type,RobotOwner owner,float theta);
    void fireRobot(RobotType type,RobotOwner owner);

    void updateRobot(int id,Point coordination);
    void removeRobot(int id,RobotOwner owner);
    void moveRobot(int id,Point vec);
    void rotateRobotBody(int id, float theta);
    void rotateRobotGun(int id,float theta);
    void fireRobot(int id);
};
#endif //RM_EMULATOR_ROBOTMANAGER_H
