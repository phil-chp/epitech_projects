/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** SDL
*/

#ifndef SDL_HPP_
# define SDL_HPP_

# include "Graph/IGraph.hpp"
# include "SDLObject.hpp"
# include <SDL2/SDL.h>
# include <SDL2/SDL_mouse.h>
# include <fstream>
# include <iomanip>

namespace arc
{
    namespace graph
    {
        class SDL
            : public IGraph
        {
            public:
                SDL();
                ~SDL();

                void initGraph(std::map<char const, arc::InfoObject> info, arc::GameMeta meta, std::vector<std::string> map) final;
                void display(arc::Tick tick) const final;
                arc::TransEvent getEvent() const final;
                arc::Coords const getMousePos() final;
                arc::LibType getSignature() const final;

            private:
                int _pad;
                SDL_Window* _window;
                SDL_Renderer* _renderer;
                std::map<char, std::shared_ptr<SDLObject>> _graphData;
                std::map<std::string, std::shared_ptr<SDLObject>> _metaData;
                std::map<SDL_Keycode, arc::TransEvent> _keyMap;
                arc::GameMeta _meta;

                void _initMeta(arc::GameMeta gameMeta);
                void _initObject(std::map<char const, arc::InfoObject> info);
                void initKeyMap();
                void animateObject(arc::graph::SDLObject &object) const;
                SDLObject getGraphObject(char const type) const;
                SDLObject getMetaObject(std::string const type) const;
        };
    }
}

extern "C" std::unique_ptr<arc::graph::IGraph> getUniqueClass();

#endif /* !SDL_HPP_ */
