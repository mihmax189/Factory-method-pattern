cmake_minimum_required(VERSION 3.15)

project(app)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCES main.cpp factory.cpp reader.hpp shape.hpp factory.hpp)

add_executable(app ${SOURCES})
