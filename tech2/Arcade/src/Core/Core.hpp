/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** Core
*/

#ifndef CORE_HPP
# define CORE_HPP

# include "Core/Switcher/Switcher.hpp"
# include "Shared/Color.hpp"
# include "Shared/Clock.hpp"
# include "Game/IGame.hpp"
# include "Graph/IGraph.hpp"
# include <string.h>
# include <dlfcn.h>
# include <iostream>
# include <vector>
# include <chrono>
# include <map>

namespace arc
{
    namespace core
    {
        class Core {
            public:
                Core();
                Core(std::string graphPath);
                ~Core();

                void switchLib(arc::LibType type) {
                    this->_Switcher->switchLib(type);
                };
                void run();

            private:
                std::unique_ptr<Switcher> _Switcher;
                std::unique_ptr<arc::game::IGame> _game;
                std::unique_ptr<arc::graph::IGraph> _graph;
                std::unique_ptr<arc::Clock> _Clock;
                void _handleLibrary(arc::TransEvent event);
                void _refreshLibrary(arc::LibType type);
                void _refreshGame();
                void _refreshGraph();
                void _initCore(void);
                void _handleMenuClick(void);
        };
    }
}

#endif
