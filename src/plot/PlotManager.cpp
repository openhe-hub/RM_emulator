#include "PlotManager.h"
#include "../utils/Value.h"
#include "../shape/Rectangle.h"
#include "../shape/PolyLine.h"
#include "../object/Buff.h"
#include "../object/Start.h"
#include "../object/Base.h"
#include "../object/Supply.h"
#include "../object/Robot.h"
#include "../object/RobotManager.h"
#include <GL/freeglut.h>
#include <iostream>

// main render function
void renderScene();

void timerCallback(int id);

// static map
void plotMap();

void plotSite();

void plotBarriers();

void plotBuff();

void plotBase();

void plotStart();


void PlotManager::emulate(int argc, char **argv) {
    glutInit(&(argc), argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(Value::WIDTH, Value::HEIGHT);
    glutInitWindowPosition(Value::DISPLAY_X, Value::DISPLAY_Y);
    glutCreateWindow("RM Emulator");
    glutDisplayFunc(renderScene);
    glutTimerFunc(10, timerCallback, 1);
    glutMainLoop();
}

void timerCallback(int id) {
    RobotManager &robotManager = RobotManager::getInstance();
    plotMap();
    robotManager.renderAll();
    glutPostRedisplay();
    glutTimerFunc(10, timerCallback, 1);
}

void renderScene() {
}

// static map
void plotMap() {
    plotSite();
    plotBarriers();
    plotBase();
    plotBuff();
    plotStart();
}

void plotSite() {
    glClearColor(0.7, 0.9, 0.8, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    std::vector<Rectangle> boarders = {
            {Value::HEIGHT,       Value::BOARDER_SIZE, {-Value::MAP_WIDTH / 2 - Value::BOARDER_SIZE / 2, 0},
                    {.3, .3, .3}},
            {Value::HEIGHT,       Value::BOARDER_SIZE, {Value::MAP_WIDTH / 2 + Value::BOARDER_SIZE / 2,  0},
                    {.3, .3, .3}},
            {Value::BOARDER_SIZE, Value::MAP_WIDTH,    {0,                                               Value::MAP_HEIGHT /
                                                                                                         2 +
                                                                                                         Value::BOARDER_SIZE /
                                                                                                         2},
                    {.3, .3, .3}},
            {Value::BOARDER_SIZE, Value::MAP_WIDTH,    {0,                                               -Value::MAP_HEIGHT /
                                                                                                         2 -
                                                                                                         Value::BOARDER_SIZE /
                                                                                                         2},
                    {.3, .3, .3}}
    };
    for (auto &boarder: boarders) {
        boarder.render();
    }
}

void plotBarriers() {
    // base barriers
    std::vector<PolyLine> barries = {
            {{{Value::BARRIER_X,      -Value::MAP_HEIGHT / 2},
                                            {Value::BARRIER_X,                              -Value::MAP_HEIGHT / 2 +
                                                                                            Value::BARRIER_LENGTH},
                                                                                                  {Value::BARRIER_X +
                                                                                                   13,   -Value::MAP_HEIGHT /
                                                                                                         2 +
                                                                                                         Value::BARRIER_LENGTH +
                                                                                                         15}},
                    {1, 0, 0}},
            {{{-Value::MAP_WIDTH / 2, Value::BARRIER_Y},
                                            {-Value::MAP_WIDTH / 2 + Value::BARRIER_LENGTH, Value::BARRIER_Y},
                                                                                                  {-Value::MAP_WIDTH /
                                                                                                   2 +
                                                                                                   Value::BARRIER_LENGTH +
                                                                                                   15,   Value::BARRIER_Y +
                                                                                                         13}},
                    {1, 0, 0}},
            {{{-Value::BARRIER_X,     Value::MAP_HEIGHT / 2},
                                            {-Value::BARRIER_X,                             Value::MAP_HEIGHT / 2 -
                                                                                            Value::BARRIER_LENGTH},
                                                                                                  {-Value::BARRIER_X -
                                                                                                   13,   Value::MAP_HEIGHT /
                                                                                                         2 -
                                                                                                         Value::BARRIER_LENGTH -
                                                                                                         15}},
                    {0, 0, 1}},
            {{{Value::MAP_WIDTH / 2,  -Value::BARRIER_Y},
                                            {Value::MAP_WIDTH / 2 - Value::BARRIER_LENGTH,  -Value::BARRIER_Y},
                                                                                                  {Value::MAP_WIDTH /
                                                                                                   2 -
                                                                                                   Value::BARRIER_LENGTH -
                                                                                                   15,   -Value::BARRIER_Y -
                                                                                                         13}},
                    {0, 0, 1}},
            {{{-124,                  -95}, {-111,                                          -82}, {-111, -82 +
                                                                                                         Value::CENTER_BARRIER_LENGTH},
                     {-96, -67 + Value::CENTER_BARRIER_LENGTH}},
                    {1, 0, 0}},
            {{{124,                   95},  {111,                                           82},  {111,  82 -
                                                                                                         Value::CENTER_BARRIER_LENGTH},
                     {96,  67 - Value::CENTER_BARRIER_LENGTH}},
                    {0, 0, 1}}
    };
    for (auto &barrier: barries) {
        barrier.setWidth(10);
        barrier.render();
    }
}

void plotBuff() {
    Supply redSupply(true), blueSupply(false);
    redSupply.render();
    blueSupply.render();

    Buff buff;
    buff.render();
}

void plotBase() {
    Base redBase(true), blueBase(false);
    redBase.render();
    blueBase.render();
}

void plotStart() {
    Start start1(true), start2(false);
    start1.render();
    start2.render();
}


