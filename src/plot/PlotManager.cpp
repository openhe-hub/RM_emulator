#include "PlotManager.h"
#include "../utils/Value.h"
#include "../shape/Rectangle.h"
#include "../shape/PolyLine.h"
#include "../object/Buff.h"
#include "../object/Start.h"
#include "../object/Base.h"
#include "../object/Supply.h"
#include "../object/Robot.h"
#include <GL/freeglut.h>
#include <cmath>
#include <unistd.h>

// main render function
void renderScene();

// static map
void plotMap();

void plotSite();

void plotBarriers();

void plotBuff();

void plotBase();

void plotStart();

// test function for robot
void updateRobot(Robot &robot);

void rotateBody(Robot &robot, float theta);

void rotateGun(Robot &robot, float theta);

void moveBody(Robot &robot, Point pt);


void PlotManager::emulate(int argc, char **argv) {
    glutInit(&(argc), argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(Value::WIDTH, Value::HEIGHT);
    glutInitWindowPosition(Value::DISPLAY_X, Value::DISPLAY_Y);
    glutCreateWindow("RM Emulator");
    glutDisplayFunc(renderScene);
    glutMainLoop();
}

// main render function
void renderScene() {
    //init
    plotMap();
    Robot robot(RobotType::TYPE_SENTRY, RobotOwner::OWNER_RED);
    robot.render();
    glutSwapBuffers();
    //rotate
    rotateBody(robot, M_PI_2);
    moveBody(robot, {0, 300});
    rotateBody(robot, -M_PI / 5 * 3);
    moveBody(robot, {500, -180});
    rotateGun(robot, -M_PI / 10+M_PI_2);
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

// robot movement test
void updateRobot(Robot &robot) {
    plotMap();
    robot.render();
    glutSwapBuffers();
}

void rotateBody(Robot &robot, float theta) {
    for (int i = 0; i < 100; ++i) {
        robot.rotateBody(theta / 100);
        updateRobot(robot);
        usleep(5000);
    }
}

void rotateGun(Robot &robot, float theta) {
    for (int i = 0; i < 100; ++i) {
        robot.rotateGun(theta / 100);
        updateRobot(robot);
        usleep(5000);
    }
}

void moveBody(Robot &robot, Point pt) {
    int num = fmax(pt.getX(), pt.getY()) / Value::DELTA_DIS;
    float dx = pt.getX() / num;
    float dy = pt.getY() / num;
    for (int i = 0; i < num; ++i) {
        robot.move({dx, dy});
        updateRobot(robot);
        usleep(5000);
    }
}


