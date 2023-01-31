#include "Rectangle.h"
#include <GL/freeglut.h>

Rectangle::Rectangle(float height, float width, Point center, Color3f color)
        : height(height), width(width), center(center), color(color) {
    float dx[4] = {-1, 1, 1, -1};
    float dy[4] = {1, 1, -1, -1};
    for (int i = 0; i < 4; ++i) {
        pts.emplace_back(center.getX() + dx[i] * width / 2, center.getY() + dy[i] * height / 2);
    }
}

void Rectangle::move(Point dis) {
    for (int i = 0; i < 4; ++i) {
        pts[i] = pts[i] + dis;
    }
}

void Rectangle::moveTo(Point pt) {
    move(pt - center);
}

void Rectangle::rotate(float theta, Point _center) {
    for (int i = 0; i < 4; ++i) {
        pts[i].rotate(_center, theta);
    }
}

void Rectangle::render() {
    glColor3f(color.r(), color.g(), color.b());
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; ++i) {
        glVertex2f(pts[i].getX(), pts[i].getY());
    }
    glEnd();
}
