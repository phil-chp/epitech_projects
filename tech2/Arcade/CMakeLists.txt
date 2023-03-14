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

cmake_minimum_required(VERSION 3.17)
project(arcade)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib/)
# set(EXECUTABLE_OUTPUT_PATH ../)
# set(CMAKE_BINARY_DIR "../")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")

set(PATH_CORE   src/Core/)
set(PATH_SHARED src/Shared/)
set(PATH_GAME   src/Game/)
set(PATH_GRAPH  src/Graph/)

include_directories(src)

add_executable(arcade
        ${PATH_CORE}/Library/Library.cpp
        ${PATH_CORE}/Library/Library.hpp
        ${PATH_CORE}/Switcher/Switcher.cpp
        ${PATH_CORE}/Switcher/Switcher.hpp
        ${PATH_CORE}/Wrapper/Wrapper.cpp
        ${PATH_CORE}/Wrapper/Wrapper.hpp
        ${PATH_CORE}/Core.cpp
        ${PATH_CORE}/Core.hpp
        ${PATH_SHARED}/Arcade.hpp
        ${PATH_SHARED}/Color.hpp
        ${PATH_GAME}/IGame.hpp
        ${PATH_GRAPH}/IGraph.hpp
        src/main.cpp
)

target_link_libraries(arcade dl)

# ---> NCurses
file(GLOB SOURCE_FILES_NCURSES ${PATH_GRAPH}/LibNCurses/*.cpp)
file(GLOB HEADER_FILES_NCURSES ${PATH_GRAPH}/LibNCurses/*.hpp)
add_library(arcade_ncurses SHARED ${SOURCE_FILES_NCURSES} ${HEADER_FILES_NCURSES})
target_link_libraries(arcade_ncurses ncurses)

# ---> SDL
file(GLOB SOURCE_FILES_SDL2 ${PATH_GRAPH}/LibSDL/*.cpp)
file(GLOB HEADER_FILES_SDL2 ${PATH_GRAPH}/LibSDL/*.hpp)
add_library(arcade_sdl2 SHARED ${SOURCE_FILES_SDL2} ${HEADER_FILES_SDL2})
target_link_libraries(arcade_sdl2 SDL2)


# ---> SFML
file(GLOB SOURCE_FILES_SFML ${PATH_GRAPH}/LibSFML/*.cpp)
file(GLOB HEADER_FILES_SFML ${PATH_GRAPH}/LibSFML/*.hpp)
add_library(arcade_sfml SHARED ${SOURCE_FILES_SFML} ${HEADER_FILES_SFML})
target_link_libraries(arcade_sfml sfml-graphics sfml-window sfml-system)

# ---> Menu
file(GLOB SOURCE_FILES_MENU ${PATH_GAME}/Menu/*.cpp)
file(GLOB HEADER_FILES_MENU ${PATH_GAME}/Menu/*.hpp)
add_library(arcade_menu SHARED ${SOURCE_FILES_MENU} ${HEADER_FILES_MENU})


# ---> DoodleJump
file(GLOB SOURCE_FILES_DOODLEJUMP ${PATH_GAME}/DoodleJump/*.cpp)
file(GLOB HEADER_FILES_DOODLEJUMP ${PATH_GAME}/DoodleJump/*.hpp)
add_library(arcade_doodlejump SHARED ${SOURCE_FILES_DOODLEJUMP} ${HEADER_FILES_DOODLEJUMP})


# ---> Pac-Mac
file(GLOB SOURCE_FILES_PACMAN ${PATH_GAME}/Pacman/*.cpp)
file(GLOB HEADER_FILES_PACMAN ${PATH_GAME}/Pacman/*.hpp)
add_library(arcade_pacman SHARED ${SOURCE_FILES_PACMAN} ${HEADER_FILES_PACMAN})


# ---> Snake
file(GLOB SOURCE_FILES_SNAKE ${PATH_GAME}/Snake/*.cpp)
file(GLOB HEADER_FILES_SNAKE ${PATH_GAME}/Snake/*.hpp)
add_library(arcade_nibbler SHARED ${SOURCE_FILES_SNAKE} ${HEADER_SNAKE})
