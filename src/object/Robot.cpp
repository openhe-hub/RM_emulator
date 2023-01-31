#include "Robot.h"
#include "../shape/Rectangle.h"
#include "../shape/PolyLine.h"
#include "../utils/Value.h"

Robot::Robot(RobotType type, RobotOwner owner) : type(type), owner(owner) {
    Color3f color;
    if (owner == RobotOwner::OWNER_RED) {
        color = {1, 0, 0};
    } else {
        color = {0, 0, 1};
    }
    center = {Value::START_X, Value::START_Y};
    body = {Value::SENTRY_HEIGHT, Value::SENTRY_WIDTH, center,
            color};
    gun = {Value::GUN_WIDTH, Value::GUN_LENGTH, {Value::START_X + Value::GUN_LENGTH / 2, Value::START_Y},
           color};
    bodyTheta = 0.0f;
    gunTheta = 0.0f;
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
    center.move(point.getX(),point.getY());
}

void Robot::moveTo(Point destination) {
    body.moveTo(destination);
    gun.moveTo(destination);
    center.moveTo(destination.getX(),destination.getY());
}
