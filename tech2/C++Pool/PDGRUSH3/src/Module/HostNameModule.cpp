/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** HostNameModule
*/

#include "HostNameModule.hpp"

HostNameModule::~HostNameModule()
{
    // do nothing
}

#include <sstream>

HostNameModule::HostNameModule()
{
    Hostname *hn = new Hostname;

    std::string *hostname = new std::string(getenv("HOSTNAME"));
    if (hostname->empty())
        *hostname = "Unknown";
    std::string *username = new std::string(getenv("USER"));
    if (username->empty())
        *username = "Unknown";
    hn->_userName = username;
    hn->_hostName = hostname;
    this->setConfig(hn);
}

void HostNameModule::refresh()
{
    Hostname *hn = new Hostname;

    std::string *hostname = new std::string(getenv("HOST"));
    if (hostname->empty())
        *hostname = "Unknown";
    std::string *username = new std::string(getenv("USER"));
    if (username->empty())
        *username = "Unknown";
    hn->_userName = username;
    hn->_hostName = hostname;
    this->setConfig(hn);
}
