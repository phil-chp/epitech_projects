/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** main
*/

#include "Network/RType/Server.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: ./" << av[0] << " <port>" << std::endl;
        return (84);
    }
    net::rtype::Server server(av[1]);
    while (true) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "quit") {
            std::cout << "quit!" << std::endl;
            break;
        }
    }
    return (0);
}
