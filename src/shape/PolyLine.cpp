#include "emulator/shape/PolyLine.h"

void PolyLine::render() {
    for (auto &line: lines) {
        line.render();
    }
}

PolyLine::PolyLine(std::vector<Point> pts, Color3f color) {
    for (int i = 0; i < pts.size() - 1; ++i) {
        lines.emplace_back(pts[i], pts[i + 1], color);
    }
}

void PolyLine::setWidth(int width) {
    PolyLine::width = width;
    for (int i = 0; i < lines.size(); ++i) {
        lines[i].setWidth(width);
    }
}
