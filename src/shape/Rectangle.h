#ifndef RM_EMULATOR_RECTANGLE_H
#define RM_EMULATOR_RECTANGLE_H

#include <vector>
#include "Point.h"
#include "Color3f.h"

class Rectangle {
private:
    std::vector<Point> pts;
    float height;
    float width;
    Point center;
    Color3f color;
public:
    Rectangle(float height, float width, Point center,Color3f color);

    void render();

    void move(Point dis);

    void moveTo(Point pt);

    void rotate(float theta, Point center);
};

#endif //RM_EMULATOR_RECTANGLE_H