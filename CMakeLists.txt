cmake_minimum_required(VERSION 3.0.0)
project(qt-log VERSION 0.1.0)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core)

add_executable(qt-log main.cpp log_handler.cpp test.cpp)

target_link_libraries(qt-log Qt5::Core)