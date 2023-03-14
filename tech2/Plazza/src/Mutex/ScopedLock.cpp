/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** ScopedLock
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(std::shared_ptr<std::mutex> &mutex, bool trylock = false)
{
    this->_mutex = mutex;
    if (trylock)
            this->_mutex.try_lock();
    else
        this->_mutex.lock();
}

ScopedLock::~ScopedLock()
{
    this->_mutex.unlock();
}