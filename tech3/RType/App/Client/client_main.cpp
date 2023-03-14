/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** main
*/

#include "ECS/Coordinator.hpp"
#include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"
#include "GameEngine/EngineButton.hpp"
#include "GameEngine/RLEventHandler.hpp"
#include "GameEngine/Managers/GameManager.hpp"
#include "GameEngine/Managers/NetworkManager.hpp"
#include "GameEngine/Initializor.hpp"
#include "GameEngine/GridCollision.hpp"
#include "GameEngine/Square.hpp"
#include "GameEngine/Circle.hpp"
#include "ECS/Components/Hitbox.hpp"
#include "GameEngine/Map/Map.hpp"
#include "Network/RType/Client.hpp"
#include <iostream>
#include <memory>
#include <fcntl.h>
#include <cstring>
#include <string>
#include <filesystem>
#include <thread>
#include <chrono>

static void rtype()
{
    if (rl::Keyboard::isKeyPressed(rl::KEY_F11) || rl::Keyboard::isKeyPressed(rl::KEY_F4))
        rl::Window::getInstance().toggleFullscreen();


    engine::PollEvent pollEvent;
    // RL_FlushEvents(RL_FIRSTEVENT, RL_LASTEVENT);
    while (!pollEvent.quit) {
        auto startTime = std::chrono::high_resolution_clock::now();
        pollEvent.playerEvents = {0, 0, 0, 0};

        engine::GameManager::getInstance().run(pollEvent);

        auto stopTime = std::chrono::high_resolution_clock::now();
        pollEvent.dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
    }
}

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cerr << "Usage: ./" << av[0] << " <host>  <port>" << std::endl;
        return (84);
    }

    rl::Window::getInstance();
    SetTraceLogLevel(::LOG_WARNING);

    engine::Initializor::init();
    ecs::Coordinator::getInstance();
    engine::GameManager::getInstance();
    engine::NetworkManager::getInstance(av[1], av[2]);

    engine::GridSystem &grid = engine::GridSystem::getInstance(XGRIDSIZE, YGRIDSIZE);
    srand(time(NULL));
    rtype();
    std::cout << "End game" << std::endl;
    ::engine::Initializor::destroyer();

    rl::Window::getInstance().close();
    return (0);
}
