#include "emulator/shape/Point.h"
#include <cmath>

float Point::getX() const {
    return x;
}

void Point::setX(float x) {
    Point::x = x;
}

float Point::getY() const {
    return y;
}

void Point::setY(float y) {
    Point::y = y;
}

Point::Point(float x, float y) : x(x), y(y) {

}

void Point::move(float dx, float dy) {
    this->x += dx;
    this->y += dy;
}

void Point::moveTo(float _x, float _y) {
    this->x = _x;
    this->y = _y;
}

void Point::rotate(Point center, float theta) {
    float rotation_mat[2][2] = {{static_cast<float>(cos(theta)), static_cast<float>(-sin(theta))},
                                {static_cast<float>(sin(theta)), static_cast<float>(cos(theta))}};
    this->x = this->x - center.getX();
    this->y = this->y - center.getY();

    this->x = rotation_mat[0][0] * this->x + rotation_mat[0][1] * this->y;
    this->y = rotation_mat[1][0] * this->x + rotation_mat[1][1] * this->y;

    this->x = this->x + center.getX();
    this->y = this->y + center.getY();
}

Point Point::operator+(Point point) {
    return {this->x + point.getX(), this->y + point.getY()};
}

Point Point::operator-(Point point) {
    return {this->x - point.getX(), this->y - point.getY()};
}

Point Point::mid(Point point1, Point point2) {
    return {(point1.getX() + point2.getX()) / 2, (point1.getY()+ point2.getY()) / 2};
}

