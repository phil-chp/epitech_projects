/*
** EPITECH PROJECT, 2022
** RType
** File description:
** EventHandler
*/

#ifndef RLEVENTHANDLER_HPP_
    #define RLEVENTHANDLER_HPP_

    #include "GameEngine/EventHandler.hpp"
    #include "GameEngine/PollEvent.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"
    #include <map>
    #include <algorithm>
    #include <iostream>

namespace engine {
const std::map<::rl::KeyboardKeys, Event> events = {
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_Z, UP),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_S, DOWN),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_Q, LEFT),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_D, RIGHT),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_UP, SEC_UP),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_DOWN, SEC_DOWN),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_LEFT, SEC_LEFT),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_RIGHT, SEC_RIGHT),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_SPACE, SHOOT),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_E, INTERACT),
    // std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_, SHOOT),
    std::make_pair<::rl::KeyboardKeys, Event>(::rl::KeyboardKeys::KEY_P, MENU)
};

template<>
class EventHandler<::rl::KeyboardKeys> {
    public:
        static PlayerEvent getEvent() {
            PlayerEvent res = {NONE, NONE};
            // RL_Event event;
            bool quit = false;
            if (::rl::Window::getInstance().shouldClose() || ::rl::Window::getInstance().shouldExit()) {
                quit = true;
                res.pressed += QUIT;
                return res;
            }
            if (!::rl::Keyboard::isKeyDown(::rl::Keyboard::isKeyDown(::rl::KeyboardKeys::KEY_NULL))) {
                for (auto pair : events) {
                    if (::rl::Keyboard::isKeyDown(pair.first)) {
                        res.pressed += pair.second;
                    }
                }
            }
            if (!::rl::Keyboard::isKeyReleased(::rl::Keyboard::isKeyDown(::rl::KeyboardKeys::KEY_NULL))) {
                for (auto pair : events) {
                    if (::rl::Keyboard::isKeyReleased(pair.first)) {
                        res.released += pair.second;
                    }
                }
            }
            // std::map<::rl::KeyboardKeys, engine::Event>::const_iterator itr = std::find_if(events.begin(), events.end(), [event](const std::pair<::rl::KeyboardKeys, Event> &pair) {
            //     return ::rl::Keyboard::isKeyDown(pair.first);
            // });
            // if (itr != events.end()) {
            //     res.pressed += itr->second;
            // }
            // }
            // RL_FlushEvents(RL_FIRSTEVENT, RL_LASTEVENT);
            return res;
        };
};

typedef EventHandler<::rl::KeyboardKeys> RLEventHandler;
};

#endif /* !RLEVENTHANDLER_HPP_ */
