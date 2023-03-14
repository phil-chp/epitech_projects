/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** NCurses
*/

#ifndef NCURSES_HPP_
# define NCURSES_HPP_

# include "Shared/Color.hpp"
# include "Graph/IGraph.hpp"
# include "Graph/LibNCurses/NCursesObject.hpp"
# include <ncurses.h>
# include <fstream>
# include <iomanip>

namespace arc
{
    namespace graph
    {
        class NCurses
            : public IGraph
        {
            public:
                NCurses();
                ~NCurses() override;
                void initGraph(std::map<char const, InfoObject> info, arc::GameMeta meta, std::vector<std::string> map);
                void display(arc::Tick tick) const final;
                arc::TransEvent getEvent() const final;
                arc::LibType getSignature() const final;
                arc::Coords const getMousePos();

            private:
                WINDOW *_win;
                size_t _xSize;
                size_t _ySize;
                std::map<char, std::shared_ptr<NCursesObject> > _graphData;
                std::map<std::string, std::shared_ptr<NCursesObject>> _metaData;
                std::map<int, TransEvent> _keyMap;
                bool _hasColors;
                arc::GameMeta _meta;

                NCursesObject _getGraphObject(char const type) const;
                void _initColors(std::map<char const, InfoObject> info);
                void _initObject(std::map<char const, InfoObject> info);
                void _initKeyMap(void);
                void _initMeta(arc::GameMeta gameMeta);
        };
    }
}

extern "C" std::unique_ptr<arc::graph::IGraph> getUniqueClass();

#endif /* !NCURSES_HPP_ */
