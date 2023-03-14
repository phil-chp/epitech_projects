/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** ToolBox
*/

#ifndef TOOLBOX_HPP_
    #define TOOLBOX_HPP_

    #include "NamedPipe/NamedPipe.hpp"
    #include <unistd.h>
    #include <iostream>
    #include <algorithm>
    #include <sys/types.h>
    #include <signal.h>
    #include <fstream>

class ToolBox {
    public:
        //* ----------------------- Trim whitespace ------------------------ *//
        static inline void ltrim(std::string &s) {
            s.erase(s.begin(),
                std::find_if(s.begin(), s.end(),
                    [](unsigned char ch) {
                        return !std::isspace(ch);
                    }
                )
            );
        }
        static inline void rtrim(std::string &s) {
            s.erase(
                std::find_if(s.rbegin(), s.rend(),
                    [](unsigned char ch) {
                        return !std::isspace(ch);
                    }
                ).base(), s.end()
            );
        }
        static inline void trim(std::string &s) {
            ltrim(s);
            rtrim(s);
        }

        //* ---------------------------- Usage ----------------------------- *//
        static inline void usage() {
            std::cout << "USAGE\n\t./plazza <multiplier> <cooksNb> <ingredientDelay>\n"
            << "DESCRIPTION\n\tmultiplier\tThe multiplier the pizza cooking time.\n"
            << "\tcooksNb\t\tThe number of cooks per kitchen.\n"
            << "\tingredientDelay\tThe delay it takes for ingredients to refill in kitchens." << std::endl;
        }

        //* ----------------------------- Fork ----------------------------- *//
        static pid_t fork() {
            pid_t pid = ::fork();

            if (pid == -1) {
                throw Errors("failed", "Fork");
            }
            return (pid);
        }

        //* ----------------------------- Misc ----------------------------- *//
        static size_t getMin(size_t a, size_t b) {
            return (a < b ? a : b);
        }
};

#endif /* !TOOLBOX_HPP_ */
