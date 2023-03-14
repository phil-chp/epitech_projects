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
## Note: commande for compile
## rm -rf build/ && cmake -B build/ -S . && cd build && make
##

# set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(RL_LIB rl-cpp/)
include_directories(rl-cpp)

if (NOT raylib_FOUND)
    INCLUDE(FetchContent)
    FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
    FetchContent_GetProperties(raylib)

    if (NOT raylib_POPULATED)
        SET(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        SET(raylib_FOUND TRUE)
    endif()
endif()

if (NOT TARGET raylib)
find_package(raylib REQUIRED)
endif()

add_library(rl-cpp
    ${RL_LIB}/Collisions/BoundingBox/BoundingBox.cpp
    ${RL_LIB}/Collisions/Collision/Collision.cpp
    ${RL_LIB}/Collisions/Ray/Ray.cpp
    ${RL_LIB}/Colors/Color.cpp
    ${RL_LIB}/Image/Image.cpp
    ${RL_LIB}/Models/Material/Material.cpp
    ${RL_LIB}/Models/Mesh/Mesh.cpp
    ${RL_LIB}/Models/Model/Model.cpp
    ${RL_LIB}/Shaders/Shader.cpp
    ${RL_LIB}/Shaders/Explosion/Explosion.cpp
    ${RL_LIB}/Shaders/Skybox/Skybox.cpp
    ${RL_LIB}/Shapes/Circle3D/Circle3D.cpp
    ${RL_LIB}/Shapes/Cube/Cube.cpp
    ${RL_LIB}/Shapes/Cylinder/Cylinder.cpp
    ${RL_LIB}/Shapes/Grid/Grid.cpp
    ${RL_LIB}/Shapes/Line3D/Line3D.cpp
    ${RL_LIB}/Shapes/Plane/Plane.cpp
    ${RL_LIB}/Shapes/Point3D/Point3D.cpp
    ${RL_LIB}/Shapes/Rectangle/Rectangle.cpp
    ${RL_LIB}/Shapes/Sphere/Sphere.cpp
    ${RL_LIB}/Shapes/Triangle3D/Triangle3D.cpp
    ${RL_LIB}/Sounds/Audio/Audio.cpp
    ${RL_LIB}/Sounds/AudioStream/AudioStream.cpp
    ${RL_LIB}/Sounds/Music/Music.cpp
    ${RL_LIB}/Sounds/Sound/Sound.cpp
    ${RL_LIB}/Sounds/Wave/Wave.cpp
    ${RL_LIB}/Texts/Text.cpp
    ${RL_LIB}/Textures/Texture.cpp
    ${RL_LIB}/Windows/Cursor/Cursor.cpp
    ${RL_LIB}/Windows/FPS/FPS.cpp
    ${RL_LIB}/Windows/Gamepad/Gamepad.cpp
    ${RL_LIB}/Windows/Keyboard/Keyboard.cpp
    ${RL_LIB}/Windows/Mouse/Mouse.cpp
    ${RL_LIB}/Windows/View/View.cpp
    ${RL_LIB}/Windows/Window.cpp)


target_link_libraries(rl-cpp raylib)
target_link_libraries(rl-cpp dl)
target_link_libraries(rl-cpp pthread)

if (APPLE)
    target_link_libraries(rl-cpp "-framework IOKit")
    target_link_libraries(rl-cpp "-framework Cocoa")
    target_link_libraries(rl-cpp "-framework OpenGL")
else()
    target_link_libraries(rl-cpp GL)
endif()
# TODO: if (WINDAUBE)
