#include "emulator/object/Base.h"
#include "emulator/utils/Value.h"
#include "emulator/shape/Polygon.h"
#include <iostream>
#include <iomanip>

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
    owner = isRed ? RobotOwner::OWNER_RED : RobotOwner::OWNER_BLUE;
    hp = 1500;
    shieldHp = 1500;
    isInvincible = true;
    isShieldAvailable = true;
}

RobotOwner Base::getOwner() {
    return owner;
}

void Base::updateHp(int deltaHp) {
    if (isInvincible) {
        return;
    } else if (isShieldAvailable) {
        shieldHp += deltaHp;
    } else {
        hp += deltaHp;
    }
}

void Base::info() {
    std::string text = isRed ? "[RED BASE]" : "[BLUE BASE]";
    std::cout.setf(std::ios::left);
    std::cout << std::setw(20) << std::setfill(' ')
              << text << "\t";
    std::cout << "staus = [ " << (isInvincible ? "invincible" : "assaultable")
              << " , " << (isShieldAvailable ? "shield" : "none") << " ]" << "\t\t";
    std::cout
            << "hp = " << std::setw(6) << std::setfill(' ') << hp << "\t\t"
            << "shield_hp = " << std::setw(6) << std::setfill(' ') << hp << "\t\t";
    std::cout << std::endl;
}
