#include "Buff.h"
#include "../utils/Value.h"

Buff::Buff() {
    this->outline = {Value::BUFF_SIZE, Value::BUFF_SIZE, {Value::BUFF_X, Value::BUFF_Y}, {0.6, 0.6, 0.6}};
    this->icon = {
            {60,40,{0,30},{0,1,0}},
            {60,40,{0,-30},{0,1,0}},
            {40,60,{30,0},{0,1,0}},
            {40,60,{-30,0},{0,1,0}},
    };
    this->buffTime = 0;
}

void Buff::render() {
    outline.render();
    for (auto &item: icon) {
        item.render();
    }
}
