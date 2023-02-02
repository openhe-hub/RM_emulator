#ifndef RM_EMULATOR_ROBOTMANAGER_H
#define RM_EMULATOR_ROBOTMANAGER_H
#include "Robot.h"

class RobotManager{
private:
    std::vector<Robot> robots;
    bool isBegin= false;
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
    void fireRobot(RobotType type,RobotOwner);
};
#endif //RM_EMULATOR_ROBOTMANAGER_H
