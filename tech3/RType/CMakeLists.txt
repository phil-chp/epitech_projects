## Command for compiling:
##      clear; cmake -B build/ -S . -Wno-dev && make -C build/ -j 4 && ./build/RType
## command on mingw
##      cd .. && rm -rf build && cmake -B build/ -S . -G "MinGW Makefiles" -Wno-dev && cd build && mingw32-make -j 4 && cd ..
##

cmake_minimum_required (VERSION 3.11)
project(RType CXX)

if(APPLE)
  message(FATAL_ERROR " :)")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -O -lboost_thread -lboost_serialization") # -W -Wall -Wextra
else()
  set(CMAKE_CXX_FLAGS "")
endif()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/Modules")

file(GLOB CLIENT_ECS_SRC
  "App/Client/ECS/Coordinator.cpp"
  "App/Client/ECS/EntityManager.cpp"
  "App/Client/ECS/Components/*.cpp"
  "App/Client/ECS/Systems/*.cpp"
)
file(GLOB CLIENT_ENGINE_SRC
  "App/Client/GameEngine/*.cpp"
  "App/Client/GameEngine/Managers/*.cpp"
  "App/Client/GameEngine/RType/*.cpp"
  "App/Client/GameEngine/RType/Button/*.cpp"
)

file(GLOB SERVER_ECS_SRC
  "App/Server/ECS/Coordinator.cpp"
  "App/Server/ECS/EntityManager.cpp"
  "App/Server/ECS/Components/*.cpp"
  "App/Server/ECS/Systems/*.cpp"
)
file(GLOB SERVER_ENGINE_SRC
  "App/Server/GameEngine/*.cpp"
  "App/Server/GameEngine/Managers/*.cpp"
  "App/Server/GameEngine/RType/*.cpp"
  "App/Server/GameEngine/RType/Button/*.cpp"
)

file(GLOB LIB_SRC
  "App/Lib/Raylib/rl-cpp/Windows/Window.cpp"
  "App/Lib/Raylib/rl-cpp/Collisions/BoundingBox/BoundingBox.cpp"
  "App/Lib/Raylib/rl-cpp/Collisions/Collision/Collision.cpp"
  "App/Lib/Raylib/rl-cpp/Collisions/Ray/Ray.cpp"
  "App/Lib/Raylib/rl-cpp/Colors/Color.cpp"
  "App/Lib/Raylib/rl-cpp/Image/Image.cpp"
  "App/Lib/Raylib/rl-cpp/Models/Material/Material.cpp"
  "App/Lib/Raylib/rl-cpp/Models/Mesh/Mesh.cpp"
  "App/Lib/Raylib/rl-cpp/Models/Model/Model.cpp"
  "App/Lib/Raylib/rl-cpp/Shaders/Shader.cpp"
  "App/Lib/Raylib/rl-cpp/Shaders/Explosion/Explosion.cpp"
  "App/Lib/Raylib/rl-cpp/Shaders/Skybox/Skybox.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Circle3D/Circle3D.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Cube/Cube.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Cylinder/Cylinder.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Grid/Grid.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Line3D/Line3D.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Plane/Plane.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Point3D/Point3D.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Rectangle/Rectangle.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Sphere/Sphere.cpp"
  "App/Lib/Raylib/rl-cpp/Shapes/Triangle3D/Triangle3D.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Audio/Audio.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/AudioStream/AudioStream.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Music/Music.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Sound/Sound.cpp"
  "App/Lib/Raylib/rl-cpp/Sounds/Wave/Wave.cpp"
  "App/Lib/Raylib/rl-cpp/Texts/Text.cpp"
  "App/Lib/Raylib/rl-cpp/Textures/Texture.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Cursor/Cursor.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/FPS/FPS.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Gamepad/Gamepad.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Keyboard/Keyboard.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/Mouse/Mouse.cpp"
  "App/Lib/Raylib/rl-cpp/Windows/View/View.cpp"
)

set(SERVER_SRCS
  # ${LIB_SRC}
  # ${SERVER_ECS_SRC}
  "App/Server/servr_main.cpp"
  # ${SERVER_ENGINE_SRC}

  "App/Network/Protocol/ClientManager.cpp"
  "App/Network/RType/Server.cpp"

  # "App/Network/test/Server.cpp"
)

  set(CLIENT_SRCS
  ${LIB_SRC}
  ${CLIENT_ECS_SRC}
  "App/Client/client_main.cpp"
  ${CLIENT_ENGINE_SRC}

  "App/Network/RType/Client.cpp"

  # "App/Network/test/Client.cpp"
)

message(${CMAKE_CURRENT_BINARY_DIR})

add_executable(r-type_client ${CLIENT_SRCS})
add_executable(r-type_server ${SERVER_SRCS})

target_link_libraries(r-type_server pthread)
target_link_libraries(r-type_client pthread)

target_include_directories(r-type_server PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/App
  ${CMAKE_CURRENT_SOURCE_DIR}/App/Server
  ${CMAKE_CURRENT_SOURCE_DIR}/App/Server/ECS
)

target_include_directories(r-type_client PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/App
  ${CMAKE_CURRENT_SOURCE_DIR}/App/Client
  ${CMAKE_CURRENT_SOURCE_DIR}/App/Client/ECS
)

find_package(Boost REQUIRED)
find_package(Raylib REQUIRED)


if(Boost_FOUND)
   message("Boost_VERSION: ${Boost_VERSION}")
   include_directories(${Boost_INCLUDE_DIRS})
   target_include_directories(r-type_client PRIVATE ${Boost_INCLUDE_DIRS})
   target_include_directories(r-type_server PRIVATE ${Boost_INCLUDE_DIRS})
   target_link_libraries(r-type_client ${Boost_LIBRARIES})
   target_link_libraries(r-type_server ${Boost_LIBRARIES})
endif()

if (MINGW)
  # Nothing
elseif (UNIX)
  target_include_directories(r-type_client PRIVATE ${RAYLIB_INCLUDE_DIRS})
  target_include_directories(r-type_server PRIVATE ${RAYLIB_INCLUDE_DIRS})
  target_link_libraries(r-type_client raylib)
  target_link_libraries(r-type_server raylib)
  add_subdirectory(${raylib_SOURCE_DIR})
  # target_link_libraries(r-type_server dl)
  # target_link_libraries(r-type_server pthread)
  # target_link_libraries(r-type_server GL)
elseif (MSVC)
  target_include_directories(r-type_client PRIVATE ${RAYLIB_INCLUDE_DIRS})
  target_include_directories(r-type_server PRIVATE ${RAYLIB_INCLUDE_DIRS})
  target_link_libraries(r-type_client raylib)
  target_link_libraries(r-type_server raylib)
  add_subdirectory(${raylib_SOURCE_DIR})
else()
  message(FATAL_ERROR "You are using an unsupported OS. Only supported OS are UNIX and WINGW. Wait for future releases, we might expand this range. :)")
endif()
