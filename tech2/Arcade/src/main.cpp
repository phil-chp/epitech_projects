/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** Wrapper
*/

#include "Game/IGame.hpp"
#include "Graph/IGraph.hpp"
#include "Core/Core.hpp"
#include "Game/Sokoban/Sokoban.hpp"
#include "Core/Library/Library.hpp"
#include "Core/Switcher/Switcher.hpp"
#include "Shared/Arcade.hpp"
#include <iostream>
#include <string>
#include <vector>

void usage(void)
{
    std::cout << "./arcade <library_path>" << std::endl;
    return;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        usage();
        exit(84);
    }
    arc::core::Core core(av[1]);
    core.run();
    return (0);
}
