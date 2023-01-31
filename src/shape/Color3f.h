#ifndef RM_EMULATOR_COLOR3F_H
#define RM_EMULATOR_COLOR3F_H

#include <vector>

class Color3f {
private:
    std::vector<float> color;
public:
    Color3f(){}

    Color3f(std::vector<float> color);

    Color3f(float r, float g, float b);

    const std::vector<float> &getColor() const;

    void setColor(const std::vector<float> &color);

    float r();

    float g();

    float b();
};

#endif //RM_EMULATOR_COLOR3F_H
