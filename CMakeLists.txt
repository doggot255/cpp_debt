cmake_minimum_required(VERSION 3.24)
project(curse)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/**/*.cpp")

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})
