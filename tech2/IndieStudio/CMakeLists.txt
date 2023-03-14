##
## EPITECH PROJECT, 2022
## ARCADE
## authored by:
##      Vitali DROUJKO  <vitali.droujko@epitech.eu>
##      Pierre PLASSIO  <pierre.plassio@epitech.eu>
##      Philippe CHEYPE <philippe.cheype@epitech.eu>
## File description:
## CMakeLists.txt
##
## Command for compiling:
##      rm -rf build/ && cmake -B build/ -S . -Wno-dev && cd build && make
## or
##      rm -rf build/ && cmake -B build/ -S . -Wno-dev && make -C build/ -j -s && ./build/App/bomberman
##
## According to CMake standards, multiple CMake files is the
## correct way of doing things: https://cmake.org/examples/
##

cmake_minimum_required(VERSION 3.11)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
# TODO: PASS TO RELEASE OR MINSIZEREL FOR FINAL COMMIT
# set(CMAKE_BUILD_TYPE MinSizeRel)
# set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -pthread -Wno-missing-field-initializers -Wno-unused-function -Wno-narrowing")

add_subdirectory(Lib)
add_subdirectory(App)
