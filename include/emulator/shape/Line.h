#ifndef RM_EMULATOR_LINE_H
#define RM_EMULATOR_LINE_H

#include <vector>
#include "Point.h"
#include "Color3f.h"

class Line {
private:
    std::vector<Point> pts;
    Color3f color;
    int width;
public:
    void setWidth(int width);
    Line(Point p1, Point p2, Color3f color);
    void render();
};

#endif //RM_EMULATOR_LINE_H
