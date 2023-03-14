/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** WIDGET
*/

#ifndef WIDGET_HPP_
    #define WIDGET_HPP_

    #include "Raylib.hpp"
    #include <array>

#define MAX_COLOR_PLAYER 6

enum State {
    READY,
    LOGOUT,
    SELECT_PREV,
    SELECT_NEXT,
    LOGIN,
};

namespace ecs {
    /*
    struct Widget {
        bool clicked;
        virtual void action() {};
        std::string content;
    }
    */
    struct MapWidget {
        std::array<KeyboardKey, 4> keys;
        int8_t indexMapColor;
        rl::Color mapColor;
        State mode;
        std::string content;
        void (*action)();
    };


    struct PlayerWidget {
        std::array<rl::KeyboardKeys, 4> keys;
        int8_t indexPlayerColor;
        rl::Color playerColor;
        State mode;
        std::string content;
        float scrollingBack;
        float scrollingMid;
        float scrollingFore;
        void (*action)();
    };

    enum buttonType {
        DEFAULT = 0,
        PLAY,
        SETTINGS,
        QUIT
    };

    struct ButtonWidget {
        std::string content;
        buttonType type;
        bool clicked;
        bool released;
        bool hover;
        void (*action)();
    };

    struct TextureWidget {
        rl::Texture texture;
    };
}

#endif /* !WIDGET_HPP_ */
