#include "Color3f.h"

#include <utility>

Color3f::Color3f(std::vector<float> color) : color(std::move(color)) {}

const std::vector<float> &Color3f::getColor() const {
    return color;
}

void Color3f::setColor(const std::vector<float> &color) {
    Color3f::color = color;
}

float Color3f::r() {
    return color[0];
}

float Color3f::g() {
    return color[1];
}

float Color3f::b() {
    return color[2];
}
