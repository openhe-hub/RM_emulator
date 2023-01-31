#ifndef RM_EMULATOR_POINT_H
#define RM_EMULATOR_POINT_H

class Point {
private:
    float x;
    float y;
public:
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    Point(float x, float y);
    void move(float dx,float dy);
    void moveTo(float _x,float _y);
    void rotate(Point center,float theta);
    Point operator+(Point point);
    Point operator-(Point point);
};

#endif //RM_EMULATOR_POINT_H
