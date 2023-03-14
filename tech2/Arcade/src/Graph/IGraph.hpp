/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** IGraph
*/

#ifndef IGRAPH_HPP
# define IGRAPH_HPP

# include "Shared/Color.hpp"
# include "Shared/IClass.hpp"
# include "Shared/Arcade.hpp"
# include <iostream>
# include <vector>
# include <map>
# include <memory>


# define TERMINAL_X_SIZE  2
# define TERMINAL_Y_SIZE  1

namespace arc
{
    namespace graph
    {
        typedef std::vector<std::string> Map;
        class IGraph : public IClass
        {
            public:
                virtual ~IGraph() = default;
                virtual void initGraph(std::map<char const, InfoObject> info, arc::GameMeta meta, std::vector<std::string> map) = 0;
                virtual void display(arc::Tick tick) const = 0;
                virtual arc::TransEvent getEvent() const = 0;
                virtual arc::Coords const getMousePos() = 0;
        };
    }
}

#endif /* IGRAPH_HPP */
