/*
** EPITECH PROJECT, 2022
** plazza-boostrap
** File description:
** main
*/

#include "ScopedLock.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <mutex>

#define ITERATIONS  1000000ULL

void incrementCounter(std::mutex &mutex, size_t &n)
{
    // std::unique_lock<std::mutex> lock(mutex, std::defer_lock);
    ScopedLock scopedLock(mutex);
    for (size_t i = 0; i < ITERATIONS; ++i) {
        n++;
    }
}

bool errorCase(int ac, char **av, int &t)
{
    if (ac != 2) {
        Errors::printError("Expected one argument for thread count");
        return (true);
    }
    t = atoi(av[1]);
    return (false);
}

int main(int ac, char **av)
{
    std::vector<std::thread> thread;
    std::mutex mutex;
    size_t n = 0;
    int t = 0;

    if (errorCase(ac, av, t)) return (84);
    for (int i = 0; i < t; ++i) {
        thread.push_back(std::thread(incrementCounter, std::ref(mutex), std::ref(n)));
    }
    std::cout << "n: " << n << " / " << ITERATIONS * t << std::endl;
    for (int i = 0; i < t; ++i) {
        thread[i].join();
    }
    return (0);
}
