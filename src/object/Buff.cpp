#include "Buff.h"
#include "../utils/Value.h"
#include "../shape/Line.h"

Buff::Buff() {
    this->outline = {Value::BUFF_SIZE, Value::BUFF_SIZE, {Value::BUFF_X, Value::BUFF_Y}, {0.7, 0.9, 0.8}};
    this->icon = {
            {60, 40, {0,   30},  {0, 0.8, 0}},
            {60, 40, {0,   -30}, {0, 0.8, 0}},
            {40, 60, {30,  0},   {0, 0.8, 0}},
            {40, 60, {-30, 0},   {0, 0.8, 0}},
    };
    this->buffTime = 0;
}

void Buff::render() {
    Point p1 = outline.getPts()[0], p2 = outline.getPts()[2];
    for (int i = 0; i <= 20; ++i) {
        Line line1 = {{p1.getX() + Value::BUFF_SIZE / 20 * (float) (i), p1.getY()},
                     {p1.getX() + Value::BUFF_SIZE / 20 * (float) (i), p2.getY()},
                     {0,                                                   1, 0}};
        Line line2 = {{p1.getX(), p1.getY()-Value::BUFF_SIZE / 20 * (float) (i)},
                     {p2.getX(), p1.getY()-Value::BUFF_SIZE / 20 * (float) (i)},
                     {0,                                                   1, 0}};
        line1.render();
        line2.render();
    }
    for (auto &item: icon) {
        item.render();
    }
}
