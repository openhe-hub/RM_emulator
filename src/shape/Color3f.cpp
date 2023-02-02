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

Color3f::Color3f(float r, float g, float b) {
    color.push_back(r);
    color.push_back(g);
    color.push_back(b);
}

Color3f Color3f::red() {
    return {1, 0, 0};
}

Color3f Color3f::blue() {
    return {0, 0, 1};
}

Color3f Color3f::redInfantry() {
    return {0.6, 0, 0};
}

Color3f Color3f::redHero() {
    return {0.8, 0.2, 0.5};
}

Color3f Color3f::redSentry() {
    return red();
}

Color3f Color3f::blueInfantry() {
    return {0.2, 0.5, 0.5};
}

Color3f Color3f::blueHero() {
    return {0, 0.7, 0.7};
}

Color3f Color3f::blueSentry() {
    return blue();
}
