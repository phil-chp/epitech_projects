/*
** EPITECH PROJECT, 2022
** RType
** File description:
** EventHandler
*/

#ifndef SDLEVENTHANDLER_HPP_
    #define SDLEVENTHANDLER_HPP_

    #include "GameEngine/EventHandler.hpp"
    #include "GameEngine/PollEvent.hpp"
    #include "Lib/SDL.hpp"
    #include <map>
    #include <algorithm>
    #include <iostream>

namespace engine {
const std::map<SDL_KeyCode, Event> events = {
    std::make_pair<SDL_KeyCode, Event>(SDLK_UP, UP),
    std::make_pair<SDL_KeyCode, Event>(SDLK_DOWN, DOWN),
    std::make_pair<SDL_KeyCode, Event>(SDLK_LEFT, LEFT),
    std::make_pair<SDL_KeyCode, Event>(SDLK_RIGHT, RIGHT),
    std::make_pair<SDL_KeyCode, Event>(SDLK_SPACE, SHOOT),
    std::make_pair<SDL_KeyCode, Event>(SDLK_RETURN, SHOOT),
    std::make_pair<SDL_KeyCode, Event>(SDLK_p, MENU)
};

template<>
class EventHandler<SDL_KeyCode> {
    public:
        static PlayerEvent getEvent() {
            PlayerEvent res = {NONE, NONE};
            SDL_Event event;
            bool quit = false;
            while (!quit && SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                    res.pressed += QUIT;
                } else if (event.type == SDL_KEYDOWN) {
                    std::map<SDL_KeyCode, engine::Event>::const_iterator itr = std::find_if(events.begin(), events.end(), [event](const std::pair<SDL_KeyCode, Event> &pair) {
                        return pair.first == event.key.keysym.sym;
                    });
                    if (itr != events.end()) {
                        res.pressed += itr->second;
                    }
                }
            }
            SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
            return res;
        };
};

typedef EventHandler<SDL_KeyCode> SDLEventHandler;
};

#endif /* !SDLEVENTHANDLER_HPP_ */
