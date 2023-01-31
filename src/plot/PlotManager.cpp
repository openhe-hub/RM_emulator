#include "PlotManager.h"
#include "../utils/Value.h"
#include <GL/freeglut.h>

// main render function
void renderScene();

void PlotManager::emulate(int argc, char **argv) {
    glutInit(&(argc), argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Value::MAP_WIDTH,Value::MAP_HEIGHT);
    glutInitWindowPosition(Value::DISPLAY_X, Value::DISPLAY_Y);
    glutCreateWindow("RM Emulator");
    glutDisplayFunc(renderScene);
    glutMainLoop();
}

void renderScene(){

}

