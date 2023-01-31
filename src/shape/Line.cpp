#include "Line.h"
#include <GL/freeglut.h>

#include <utility>

Line::Line(Point p1, Point p2, Color3f color) : color(std::move(color)) {
    pts.push_back(p1);
    pts.push_back(p2);
}

void Line::render() {
    glColor3f(color.r(), color.g(), color.b());
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(pts[0].getX(), pts[0].getY());
        glVertex2f(pts[1].getX(), pts[1].getY());
    glEnd();
}
