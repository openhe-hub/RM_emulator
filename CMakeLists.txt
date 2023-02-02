cmake_minimum_required(VERSION 3.23)
project(RM_Emulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OpenGL_INCLUDE_DIR})
include_directories(${GLUT_INCLUDE_DIR})

file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${CPP_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${GLUT_LIBRARY})
