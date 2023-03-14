/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** ComManager
*/

#ifndef COMMANAGER_HPP_
    #define COMMANAGER_HPP_

    #include "Utils/ToolBox.hpp"
    #include "Reception/Order.hpp"
    #include "NamedPipe/NamedPipe.hpp"
    #include <algorithm>
    #include <iostream>
    #include <vector>

    #define STDIN STDIN_FILENO
    // #define STDIN 0

struct Response {
    explicit Response(int fd, std::string const &data)
        : fd(fd), data(data)
    {}

    int fd;
    std::string data;
};

class ComManager
{
    public:
        ComManager();
        ~ComManager() = default;

        void addKitchen(std::string const &path);
        void removeKitchen(std::string const &path);
        void send(std::string const &path, Order &order, size_t qt);
        std::vector<Response> &listen();

    private:
        std::vector<NamedPipe> _pipes;
        std::vector<Response> _responses;
};

#endif /* !COMMANAGER_HPP_ */
