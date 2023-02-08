#ifndef RM_EMULATOR_ROBOTMANAGER_H
#define RM_EMULATOR_ROBOTMANAGER_H
#include "emulator/object/Robot.h"
#include "emulator/management/BulletManager.h"
#include "emulator/object/Base.h"
#include "emulator/object/Buff.h"
#include "emulator/object/Supply.h"
#include "emulator/management/TimeManager.h"
#include <ctime>

class RobotManager{
private:
    std::vector<Robot> robots;
    BulletManager bulletManager;
    Supply redSupply,blueSupply;
    Buff buff;
    Base redBase,blueBase;
    bool isBegin= false;
    TimeManager timeManager;

    RobotManager()=default;
    ~RobotManager()=default;

    void upgradeAll();
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
    void lossHpRobot(RobotType type,RobotOwner owner,int deltaHp);

    void updateRobot(int id,Point coordination);
    void removeRobot(int id,RobotOwner owner);
    void moveRobot(int id,Point vec);
    void rotateRobotBody(int id, float theta);
    void rotateRobotGun(int id,float theta);
    void fireRobot(int id);
    void lossHpRobot(int id,int deltaHp);

    bool getIsBegin();
};
#endif //RM_EMULATOR_ROBOTMANAGER_H
