#include "plot/PlotManager.h"
#include "object/RobotManager.h"
#include <unistd.h>
#include <thread>


int main(int argc, char *argv[]) {
    RobotManager &robotManager = RobotManager::getInstance();
    robotManager.initAll();
    std::thread plotThread([argc, argv] {
        PlotManager plotManager;
        plotManager.emulate(argc, argv);
    });
    std::thread updateThread([] {
        while (true) {
            RobotManager &robotManager = RobotManager::getInstance();
            robotManager.rotateRobotGun(RobotType::TYPE_INFANTRY, RobotOwner::OWNER_RED, 0.1);
            robotManager.fireRobot(RobotType::TYPE_INFANTRY, RobotOwner::OWNER_RED);
            robotManager.reportAll();
            sleep(1);
        }
    });
    plotThread.join();
    updateThread.join();
    return 0;
}
