#include "PlotManager.h"
#include "../utils/Value.h"
#include "../shape/Rectangle.h"
#include "../shape/PolyLine.h"
#include "../object/Buff.h"
#include "../object/Start.h"
#include "../object/Base.h"
#include <GL/freeglut.h>

// main render function
void renderScene();

// static map
void plotMap();

void plotSite();

void plotBarriers();

void plotBuff();

void plotBase();

void plotStart();


void PlotManager::emulate(int argc, char **argv) {
    glutInit(&(argc), argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Value::WIDTH, Value::HEIGHT);
    glutInitWindowPosition(Value::DISPLAY_X, Value::DISPLAY_Y);
    glutCreateWindow("RM Emulator");
    glutDisplayFunc(renderScene);
    glutMainLoop();
}

// main render function
void renderScene() {
    plotMap();
}

// static map
void plotMap() {
    plotSite();
    plotBarriers();
    plotBase();
    plotBuff();
    plotStart();

    glutSwapBuffers();
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
            {{{Value::BARRIER_X, -Value::MAP_HEIGHT / 2},
              {Value::BARRIER_X, -Value::MAP_HEIGHT / 2 + Value::BARRIER_LENGTH},
              {Value::BARRIER_X + 15, -Value::MAP_HEIGHT / 2 + Value::BARRIER_LENGTH + 15}},
             {1, 0, 0}},
            {{{-Value::MAP_WIDTH / 2, Value::BARRIER_Y},
              {-Value::MAP_WIDTH / 2 + Value::BARRIER_LENGTH, Value::BARRIER_Y},
              {-Value::MAP_WIDTH / 2 + Value::BARRIER_LENGTH + 15, Value::BARRIER_Y + 15}},
             {1, 0, 0}},
            {{{-Value::BARRIER_X, Value::MAP_HEIGHT / 2},
              {-Value::BARRIER_X, Value::MAP_HEIGHT / 2 - Value::BARRIER_LENGTH},
              {-Value::BARRIER_X - 15, Value::MAP_HEIGHT / 2 - Value::BARRIER_LENGTH - 15}},
             {0, 0, 1}},
            {{{Value::MAP_WIDTH / 2, -Value::BARRIER_Y},
              {Value::MAP_WIDTH / 2 - Value::BARRIER_LENGTH, -Value::BARRIER_Y},
              {Value::MAP_WIDTH / 2 - Value::BARRIER_LENGTH - 15, -Value::BARRIER_Y - 15}},
             {0, 0, 1}},
            {{{-124, -95}, {-109, -80}, {-109, -80 + Value::CENTER_BARRIER_LENGTH},
              {-94, -65 + Value::CENTER_BARRIER_LENGTH}},
             {1, 0, 0}},
            {{{124, 95}, {109, 80}, {109, 80 - Value::CENTER_BARRIER_LENGTH}, {94, 65 - Value::CENTER_BARRIER_LENGTH}},
             {0, 0, 1}}
    };
    for (auto &barrier: barries) {
        barrier.setWidth(10);
        barrier.render();
    }
}

void plotBuff() {
    std::vector<Rectangle> supplies = {
            {Value::SUPPLY_SIZE, Value::SUPPLY_SIZE, {Value::SUPPLY_X,  Value::SUPPLY_Y},  {1, 0, 0}},
            {Value::SUPPLY_SIZE, Value::SUPPLY_SIZE, {-Value::SUPPLY_X, -Value::SUPPLY_Y}, {0, 0, 1}}
    };
    for (auto &supply: supplies) {
        supply.render();
    }
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


