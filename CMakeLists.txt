cmake_minimum_required(VERSION 3.23)
project(RM_Emulator)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OpenGL_INCLUDE_DIR})
include_directories(${GLUT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${GLUT_LIBRARY})
