#include "Line.h"
#include <GL/freeglut.h>
#include "../utils/Value.h"

#include <utility>

Line::Line(Point p1, Point p2, Color3f color) : color(std::move(color)) {
    pts.push_back(p1);
    pts.push_back(p2);
    this->width = 3;
}

void Line::render() {
    glColor3f(color.r(), color.g(), color.b());
    glLineWidth((GLfloat)width);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glBegin(GL_LINES);
    glVertex2f(pts[0].getX() / Value::SCALE_WIDTH, pts[0].getY() / Value::SCALE_HEIGHT);
    glVertex2f(pts[1].getX() / Value::SCALE_WIDTH, pts[1].getY() / Value::SCALE_HEIGHT);
    glEnd();
}

void Line::setWidth(int width) {
    Line::width = width;
}
