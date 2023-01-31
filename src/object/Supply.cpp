#include "Supply.h"
#include "../utils/Value.h"
#include "../shape/Line.h"

Supply::Supply(bool isRed) : isRed(isRed) {
    float sign = isRed ? 1 : -1;
    region = {Value::SUPPLY_SIZE, Value::SUPPLY_SIZE,
              {Value::SUPPLY_X * sign, Value::SUPPLY_Y * sign}, {0.4, 0.4, 0.4}};
}

void Supply::render() {
    float size = Value::SUPPLY_SIZE;
    Point p1 = region.getPts()[0], p2 = region.getPts()[2];
    Color3f red = {1, 0, 0}, blue = {0, 0, 1};
    for (int i = 0; i < 10; ++i) {
        Line line = {{p1.getX() + size / 10 * (float) (i + 1), p1.getY()},
                     {p1.getX(), p1.getY() - size / 10 * (float) (i + 1)},
                     isRed ? red : blue};
        line.render();
    }
    for (int i = 0; i < 10; ++i) {
        Line line = {{p2.getX() - size / 10 * (float) (i + 1), p2.getY()},
                     {p2.getX(), p2.getY() + size / 10 * (float) (i + 1)},
                     isRed ? red : blue};
        line.render();
    }
}
