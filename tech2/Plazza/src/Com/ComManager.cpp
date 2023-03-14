/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** ComManager
*/

#include "ComManager.hpp"

ComManager::ComManager()
{
    this->_pipes.push_back(NamedPipe(STDIN));
}

//* -------------------------------- Public -------------------------------- *//

std::vector<Response> &ComManager::listen()
{
    std::vector<NamedPipe> activePipes = NamedPipe::select(this->_pipes);

    this->_responses.clear();
    for (NamedPipe &pipe : activePipes) {
        pipe.setBuffer();
        this->_responses.push_back(Response(pipe.getFd(), pipe.getBuffer()));
    }
    return (this->_responses);
}

void ComManager::send(std::string const &path, Order &order, size_t qt)
{
    std::string message;
    std::vector<NamedPipe>::iterator np = std::find_if(this->_pipes.begin(), this->_pipes.end(),
        [&path](NamedPipe const &pipe) {
            return (pipe == path);
        }
    );
    std::string messBase = order.getType() + " " + order.getSize() + " ";

    for (size_t i = 0; i < qt; ++i) {
        order.qt -= 1;
        message += messBase + std::to_string(order.pizzaId++) + ";";
    }
    message.erase(message.end() - 1);
    std::cout << ">> [" << message << "]" << std::endl;
    // (*np).write(message);
}

void ComManager::addKitchen(std::string const &path)
{
    try {
        this->_pipes.push_back(NamedPipe(path));
    } catch (IPCError const &e) {
        throw ComError(e.what());
    }
}

void ComManager::removeKitchen(std::string const &path)
{
    std::vector<NamedPipe>::const_iterator np = std::find_if(
        this->_pipes.begin(), this->_pipes.end(),
        [&path](NamedPipe const &pipe) {
            return (pipe.getPath() == path);
        }
    );
    this->_pipes.erase(np);
}

//* -------------------------------- Private ------------------------------- *//
