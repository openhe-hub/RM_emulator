#ifndef RM_EMULATOR_POLYGON_H
#define RM_EMULATOR_POLYGON_H

#include <vector>
#include "Point.h"
#include "Color3f.h"

class Polygon {
private:
    std::vector<Point> pts;
    Color3f color;
public:
    Polygon() {}

    Polygon(std::vector<Point> pts, Color3f color);

    void render();

    void move(Point dis);

    void rotate(float theta, Point center);
};

#endif //RM_EMULATOR_POLYGON_H
