#include "emulator/plot/PlotManager.h"
#include "emulator/management/RobotManager.h"
#include <unistd.h>
#include <thread>
#include <cmath>


int main(int argc, char *argv[]) {
    RobotManager &robotManager = RobotManager::getInstance();
//    robotManager.initAll();
    std::thread plotThread([argc, argv] {
        PlotManager plotManager;
        plotManager.emulate(argc, argv);
    });
    std::thread updateThread([&robotManager] {
//        robotManager.updateRobot(2, {1, 1.6});
//        robotManager.rotateRobotGun(2, -0.2);
//        while (true) {
//            robotManager.rotateRobotGun(RobotType::TYPE_INFANTRY, RobotOwner::OWNER_RED, 0.05);
//            robotManager.fireRobot(RobotType::TYPE_INFANTRY, RobotOwner::OWNER_RED);
//            robotManager.reportAll();
//            sleep(1);
//        }
    });
    plotThread.join();
    updateThread.join();
    return 0;
}
