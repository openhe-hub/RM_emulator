#ifndef RM_EMULATOR_VALUE_H
#define RM_EMULATOR_VALUE_H

class Value {
public:
    // map
    // real size(m)*scale = emulator size(px), scale=80
    // emulator size(px)/SCALE_HEIGHT or SCALE_WIDTH = OpenGL Sys
    constexpr static float MAP_WIDTH = 960.;
    constexpr static float MAP_HEIGHT = 640.;
    constexpr static float BOARDER_SIZE = 20.;
    constexpr static float HEIGHT = MAP_HEIGHT + 2 * BOARDER_SIZE; // 1000
    constexpr static float WIDTH = MAP_WIDTH + 2 * BOARDER_SIZE;   // 680
    constexpr static float SCALE_HEIGHT = HEIGHT / 2;              // 500
    constexpr static float SCALE_WIDTH = WIDTH / 2;                // 340

    // base
    constexpr static float BASE_X = -360;
    constexpr static float BASE_Y = -200;
    constexpr static float BASE_SIZE = 80;

    // buff
    constexpr static float SUPPLY_X = -440;
    constexpr static float SUPPLY_Y = 280;
    constexpr static float SUPPLY_SIZE = 80;
    constexpr static float BUFF_X = 0;
    constexpr static float BUFF_Y = 0;
    constexpr static float BUFF_SIZE = 160;

    // start
    constexpr static float START_X = -236;
    constexpr static float START_Y = -40;
    constexpr static float START_SIZE = 72;

    // barriers
    constexpr static float BARRIER_LENGTH = 123.68;
    constexpr static float CENTER_BARRIER_LENGTH = 250;
    constexpr static float BARRIER_X = -236.23;
    constexpr static float BARRIER_Y = -84.4;


    // display
    constexpr static float DISPLAY_X = 100.;
    constexpr static float DISPLAY_Y = 100.;

};

#endif //RM_EMULATOR_VALUE_H
