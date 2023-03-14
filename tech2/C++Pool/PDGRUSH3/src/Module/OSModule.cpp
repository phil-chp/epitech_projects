/*
** EPITECH PROJECT, 2022
** PDG-Rush3 (Workspace)
** File description:
** OSModule
*/

#include "OSModule.hpp"
#include <cstring>
#include <fstream>
#include <sys/utsname.h>

OSModule::~OSModule()
{
    // do nothing;
}

OSModule::OSModule()
{
    struct utsname buffer;
    OS *os = new OS;

    if ( uname(&buffer) != 0 ) return;

    os->_kernel = buffer.sysname;
    os->_version = buffer.release;
    this->setConfig(os);}

void OSModule::refresh()
{
    struct utsname buffer;
    OS *os = new OS;

    if (uname(&buffer) != 0) return;
    os->_kernel = buffer.sysname;
    os->_version = buffer.release;
    this->setConfig(os);
}
