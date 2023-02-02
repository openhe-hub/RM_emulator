#include "Robot.h"
#include "../shape/Rectangle.h"
#include "../shape/PolyLine.h"
#include "../utils/Value.h"
#include "../utils/Utils.h"
#include <iostream>

Robot::Robot(RobotType type, RobotOwner owner, int id)
        : type(type), owner(owner), id(id), bodyTheta(0.0), gunTheta(0.0) {
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
    const float ROBOT_START_Y[3] = {-130, -130, -40};  // infantry, hero, sentry
    float sign = owner == RobotOwner::OWNER_RED ? 1 : -1;
    center = {ROBOT_START_X[static_cast<int>(type) - 1] * sign,
              ROBOT_START_Y[static_cast<int>(type) - 1] * sign};
    //
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

void Robot::shot() {

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
    body.moveTo(destination);
    gun.moveTo(destination);
    center.moveTo(destination.getX(), destination.getY());
}


