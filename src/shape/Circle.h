#ifndef RM_EMULATOR_CIRCLE_H
#define RM_EMULATOR_CIRCLE_H
#include "Point.h"
#include "Color3f.h"

class Circle{
private:
    float radius;
    Point center;
    Color3f color;
public:
    Circle(float radius,Point center,Color3f color);
    void render();
    void move(Point vec);
};
#endif //RM_EMULATOR_CIRCLE_H
