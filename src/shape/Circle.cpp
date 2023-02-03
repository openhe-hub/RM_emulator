#include "Circle.h"
#include "../utils/Value.h"
#include <GL/glut.h>
#include <cmath>

void Circle::render() {
    glColor3f(color.r(), color.g(), color.b());
    glBegin(GL_POLYGON);
    for (float i = 0; i < 400; ++i) {
        glVertex2f((radius * cos(2 * M_PI / 400 * i) + center.getX())/Value::SCALE_WIDTH,
                   (radius * sin(2 * M_PI / 400 * i) + center.getY())/Value::SCALE_HEIGHT);
    }
    glEnd();
}

Circle::Circle(float radius, Point center, Color3f color)
        : radius(radius), center(center), color(color) {}

void Circle::move(Point vec) {
    center = center + vec;
}
