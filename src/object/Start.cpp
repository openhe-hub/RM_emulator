#include "Start.h"

#include <utility>
#include "../shape/Line.h"
#include "../utils/Value.h"

void Start::render() {
    float dx[8] = {0, 1, -1, 0, 0, -1, 1, 0};
    float dy[8] = {-1, 0, 0, -1, 1, 0, 0, 1};
    for (int i = 0; i < 4; ++i) {
        Point pt = region.getPts()[i];
        Line line1 = {{pt.getX() + dx[2 * i] * 20,
                       pt.getY() + dy[2 * i] * 20}, pt, color};
        Line line2 = {{pt.getX() + dx[2 * i + 1] * 20,
                       pt.getY() + dy[2 * i + 1] * 20}, pt, color};
        line1.render();
        line2.render();
    }
}

Start::Start(bool isRed) {
    float sign = isRed ? 1 : -1;
    region = {Value::START_SIZE, Value::START_SIZE,
              {sign * Value::START_X, sign * Value::START_Y},
              {0, 0, 0}};
    Color3f red = {1, 0, 0}, blue = {0, 0, 1};
    color = isRed ? red : blue;
}
