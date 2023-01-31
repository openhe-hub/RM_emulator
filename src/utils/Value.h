#ifndef RM_EMULATOR_VALUE_H
#define RM_EMULATOR_VALUE_H
class Value{
public:
    // map
    constexpr static float MAP_WIDTH=600.;
    constexpr static float MAP_HEIGHT=400.;
    constexpr static float SCALE=50.;  // real size(m)*scale = emulator size(px)
    // display
    constexpr static float DISPLAY_X=100.;
    constexpr static float DISPLAY_Y=100.;
};
#endif //RM_EMULATOR_VALUE_H
