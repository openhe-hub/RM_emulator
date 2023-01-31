#ifndef RM_EMULATOR_POLYLINE_H
#define RM_EMULATOR_POLYLINE_H

#include <vector>
#include "../shape/Line.h"

class PolyLine {
private:
    std::vector<Line> lines;
    Color3f color;
    int width;
public:
    void setWidth(int width);
    PolyLine(std::vector<Point> pts, Color3f color);
    void render();
};

#endif //RM_EMULATOR_POLYLINE_H
