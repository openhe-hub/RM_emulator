#include "Base.h"
#include "../utils/Value.h"
#include "../shape/Polygon.h"

void Base::render() {
    region.render();
    if (isRed) {
        Polygon polygon = {{region.getPts()[1],
                                   Point::mid(region.getPts()[0], region.getPts()[3]),
                                      Point::mid(region.getPts()[3], region.getPts()[2])},
                           {1,     0, 0}};
        polygon.render();
    } else {
        Polygon polygon = {{region.getPts()[3],
                                   Point::mid(region.getPts()[0], region.getPts()[1]),
                                      Point::mid(region.getPts()[1], region.getPts()[2])},
                           {0,     0, 1}};
        polygon.render();
    }
}

Base::Base(bool isRed) : isRed(isRed) {
    float sign = isRed ? 1 : -1;
    region = {Value::BASE_SIZE, Value::BASE_SIZE, {Value::BASE_X * sign, Value::BASE_Y * sign}, {0.3, 0.3, 0.3}};
}
