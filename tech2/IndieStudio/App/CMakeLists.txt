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

project(bomberman CXX)

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(../Lib/rl-cpp/ ./)

file(GLOB ECS_SRC
    "ECS/*.cpp"
    "ECS/Components/*.cpp"
    "ECS/Systems/*.cpp"
    "ECS/Systems/Widgets/*.cpp")
    # ÇA C'EST L'ECS STOP METTRE TOUT ET NIMP DEDANS
    # SI VOUS VOULEZ METTRE DES NV FICHIERS C'EST
    # JUSTE EN DESSOUS BORDEL DE MERDE

add_executable(bomberman
    ${ECS_SRC}
    Utils/GameManager.cpp
    Utils/SettingsManager.cpp
    main.cpp)

target_link_libraries(bomberman rl-cpp)
target_link_libraries(bomberman dl)
target_link_libraries(bomberman pthread)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(bomberman "-framework IOKit")
    target_link_libraries(bomberman "-framework Cocoa")
    target_link_libraries(bomberman "-framework OpenGL")
    # option(GLFW_BUILD_UNIVERSAL "Build GLFW as a Universal Binary" OFF)
    # option(GLFW_USE_CHDIR "Make glfwInit chdir to Contents/Resources" ON)
    # option(GLFW_USE_MENUBAR "Populate the menu bar on first window creation" ON)
    # option(GLFW_USE_RETINA "Use the full resolution of Retina displays" ON)
else()
    target_link_libraries(bomberman GL)
endif()
# TODO: if (WINDAUBE)
