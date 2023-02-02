#ifndef RM_EMULATOR_ROBOTMANAGER_H
#define RM_EMULATOR_ROBOTMANAGER_H
#include "Robot.h"

class RobotManager{
private:
    std::vector<Robot> robots;
    RobotManager()=default;
    ~RobotManager()=default;
public:
    // industry mode
    static RobotManager& getInstance(){
        static RobotManager parkingLot;
        return parkingLot;
    }
    RobotManager(const RobotManager&)=delete;
    RobotManager(RobotManager&&)=delete;
    RobotManager &operator=(const RobotManager&)=delete;
    RobotManager &operator=(RobotManager&&)=delete;

    void initAll();
    void renderAll();
    void updateRobot(int id,float x,float y);
    void removeRobot(int id);
};
#endif //RM_EMULATOR_ROBOTMANAGER_H
