/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** SFML
*/

#ifndef SFML_HPP_
# define SFML_HPP_

# include "Graph/IGraph.hpp"
# include "SFMLObject.hpp"
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <fstream>
# include <iomanip>
# include <map>

namespace arc
{
    namespace graph
    {
        class SFML
            : public IGraph
        {
            public:
                SFML();
                ~SFML();

                void initGraph(std::map<char const, arc::InfoObject> info, arc::GameMeta meta, std::vector<std::string> map) final;
                void display(arc::Tick tick) const final;
                arc::TransEvent getEvent() const final;
                arc::Coords const getMousePos() final;
                arc::LibType getSignature() const final;

            private:
                int _pad;
                sf::RenderWindow *_window;
                std::map<char, std::shared_ptr<SFMLObject>> _graphData;
                std::map<std::string, std::shared_ptr<SFMLObject>> _metaData;
                std::map<sf::Keyboard::Key, arc::TransEvent> _keyMap;
                arc::GameMeta _meta;

                void _initMeta(arc::GameMeta gameMeta);
                void _initObject(std::map<char const, arc::InfoObject> info);
                void initKeyMap();
                void animateObject(arc::graph::SFMLObject &object) const;
                std::shared_ptr<arc::graph::SFMLObject> createObject(char const key, arc::InfoObject const &info) const;
                SFMLObject getGraphObject(char const type) const;
                SFMLObject getMetaObject(std::string const type) const;
                double GRAPHICAL_X_SIZE;
                double GRAPHICAL_Y_SIZE;
        };
    }
}

extern "C" std::unique_ptr<arc::graph::IGraph> getUniqueClass();

#endif /* !SFML_HPP_ */
