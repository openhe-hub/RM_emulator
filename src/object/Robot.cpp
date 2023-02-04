#include "emulator/object/Robot.h"
#include "emulator/shape/PolyLine.h"
#include "emulator/utils/Value.h"
#include "emulator/utils/Utils.h"
#include <iostream>
#include <iomanip>

Robot::Robot(RobotType type, RobotOwner owner, int id)
        : type(type), owner(owner), id(id), bodyTheta(0.0), gunTheta(0.0) {
    // color
    std::vector<Color3f> colors = {
            Color3f::redInfantry(),
            Color3f::redHero(),
            Color3f::redSentry(),
            Color3f::blueInfantry(),
            Color3f::blueHero(),
            Color3f::blueSentry()
    };
    Color3f color = colors[Utils::toId(type, owner)];

    // start point
    const float ROBOT_START_X[3] = {-420, -340, -236}; // infantry, hero, sentry
    const float ROBOT_START_Y[3] = {-130, -130, -40};
    float sign = owner == RobotOwner::OWNER_RED ? 1 : -1;
    center = {ROBOT_START_X[static_cast<int>(type) - 1] * sign,
              ROBOT_START_Y[static_cast<int>(type) - 1] * sign};

    // hp
    const int ROBOT_HP[3] = {100, 150, 600}; // sentry
    hp = ROBOT_HP[static_cast<int>(type) - 1];
    // exp
    const int ROBOT_EXP[3] = {25, 75, 75};
    exp = ROBOT_EXP[static_cast<int>(type) - 1];
    // level
    level = 1;
    // shape
    body = {Value::SENTRY_HEIGHT, Value::SENTRY_WIDTH, center,
            color};
    gun = {Value::GUN_WIDTH, Value::GUN_LENGTH, {center.getX() + Value::GUN_LENGTH / 2 * sign, center.getY()},
           color};
}

void Robot::render() {
    for (int i = 0; i < 4; ++i) {
        std::vector<Point> pts = body.getPts();
        pts.push_back(pts[0]);
        PolyLine outline = {pts, body.getColor()};
        outline.setWidth(4);
        outline.render();
    }
    gun.render();
}

// return fire place & gun theta
std::pair<Point, float> Robot::shot() {
    std::pair<Point, float> ret;
    ret.first = gun.getCenter();
    ret.second = gunTheta;
    return ret;
}

void Robot::rotateGun(float theta) {
    gun.rotate(theta, this->center);
    gunTheta += theta;
}

void Robot::rotateBody(float theta) {
    body.rotate(theta, this->center);
    bodyTheta += theta;
}

void Robot::move(Point point) {
    body.move(point);
    gun.move(point);
    center.move(point.getX(), point.getY());
}

void Robot::moveTo(Point destination) {
    gun.moveTo(destination + gun.getCenter() - body.getCenter());
    body.moveTo(destination);
    center.moveTo(destination.getX(), destination.getY());
}

void Robot::info() {
    std::string text[6] = {"[RED INFANTRY]", "[RED HERO]", "[RED SENTRY]",
                           "[BLUE INFANTRY]", "[BLUE HERO]", "[BLUE SENTRY]"};
    std::cout.setf(std::ios::left);
    std::cout << std::setw(20) << std::setfill(' ')
              << text[id - 1] << "\t";
    std::cout << "( x = " << std::setw(6) << std::setfill(' ') << center.getX()
              << ", y = " << std::setw(6) << std::setfill(' ') << center.getY() << " )" << "\t\t";
    std::cout
            << "hp = " << std::setw(6) << std::setfill(' ') << hp << "\t\t"
            << std::setw(6) << std::setfill(' ') << "exp = " << exp << "\t\t"
            << std::setw(6) << std::setfill(' ') << "level = " << level << "\t";
    std::cout << std::endl;
}


