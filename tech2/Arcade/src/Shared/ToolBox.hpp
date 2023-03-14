/*
** EPITECH PROJECT, 2022
** Arcade (Workspace)
** File description:
** ToolBox
*/

#ifndef TOOLBOX_HPP_
#define TOOLBOX_HPP_

#include <iostream>
#include <array>
#include <memory>

namespace arc
{
    class ToolBox
    {
        public:
            static std::string exec(const char* cmd) {
                std::array<char, 128> buffer;
                std::string result;
                std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
                if (!pipe) {
                    throw std::runtime_error("popen() failed!");
                }
                while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
                    result += buffer.data();
                }
                return result;
            };
    };
}

#endif /* !TOOLBOX_HPP_ */
