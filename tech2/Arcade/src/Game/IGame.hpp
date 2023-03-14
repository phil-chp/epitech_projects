/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** IGame
*/

#ifndef IGAME_HPP
# define IGAME_HPP

# include "Shared/IClass.hpp"
# include "Shared/Arcade.hpp"
# include <string>
# include <vector>
# include <fstream>
# include <map>

namespace arc
{
    namespace game
    {
        class IGame : public IClass
        {
            public:
                virtual ~IGame() = default;
                virtual arc::Tick getTick(void) = 0;
                virtual std::map<char const, arc::InfoObject> getDic(void) = 0;
                virtual arc::GameMeta getMeta(void) = 0;
                virtual void initGame(void) = 0;
                virtual void simulate(arc::Tick, arc::TransEvent) = 0;
                virtual std::tuple<arc::LibType, std::string> handleClick(arc::Coords coords) = 0;
                virtual void animate(arc::Tick, arc::TransEvent) = 0;
        };
    };
}

#endif /* IGAME_HPP */
