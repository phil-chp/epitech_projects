/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** HostNameModule
*/

#ifndef NAMEMODULE_HPP_
#define NAMEMODULE_HPP_

#include "Configurable.hpp"
#include <string>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sys/utsname.h>
#include <stdio.h>

typedef struct Hostname {
    std::string *_userName;
    std::string *_hostName;
} Hostname;

class HostNameModule : public Configurable<Hostname>
{
    public:
        HostNameModule();
        ~HostNameModule();
        void refresh();
};

#endif /* !NAMEMODULE_HPP_ */
