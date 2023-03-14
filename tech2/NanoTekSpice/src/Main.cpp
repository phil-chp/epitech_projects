/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** main
*/

#include "CLI.hpp"

int main(int ac, char const **av)
{
    std::string file(ac == 2 ? av[1] : "");
    nts::CLI cli(file);
    return (0);
}
