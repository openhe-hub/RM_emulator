#include "emulator/shape/Polygon.h"

#include <utility>
#include <GL/freeglut.h>
#include "emulator/utils/Value.h"

Polygon::Polygon(std::vector<Point> pts, Color3f color)
        : pts(std::move(pts)), color(std::move(color)) {}

void Polygon::render() {
    glColor3f(color.r(), color.g(), color.b());
    glBegin(GL_POLYGON);
    for (auto &pt: pts) {
        glVertex2f(pt.getX() / Value::SCALE_WIDTH, pt.getY() / Value::SCALE_HEIGHT);
    }
    glEnd();
}

void Polygon::move(Point dis) {
    for (int i = 0; i < pts.size(); ++i) {
        pts[i] = pts[i] + dis;
    }
}


void Polygon::rotate(float theta, Point center) {
    for (int i = 0; i < pts.size(); ++i) {
        pts[i].rotate(center, theta);
    }
}
