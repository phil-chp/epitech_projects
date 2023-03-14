/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** main
*/

#include "Utils/ToolBox.hpp"
#include "Plazza/Plazza.hpp"
#include "Errors/Errors.hpp"

int main(int ac, char **av)
{
    if (ac != 4) {
        Errors::printError("invalid number of arguments.\n");
        ToolBox::usage();
        return (84);
    }
    try {
        Plazza plazza(std::stoi(av[1]), std::stoi(av[2]), std::stoi(av[3]));
        plazza.run();
    } catch (Errors &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
