/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** CONTROLWIDGET
*/

#ifndef CONTROLWIDGET_HPP_
    #define CONTROLWIDGET_HPP_

    #include "Raylib.hpp"
    #include <vector>
    #include <array>

namespace ecs {
    enum controlWidgetType {
        KEY,
        TITLE,
        SOUND,
        MUSIC,
        PLAYER_SELECT,
        SOUND_INFO,
        MUSIC_INFO,
        EXIT,
    };
    struct ControlWidget {
        // disgusting but mandatory to finish the project
        controlWidgetType type;
        uint8_t indexPlayer;
        uint8_t indexKey;
        bool isPressed;
        rl::KeyboardKeys key;
        std::string content;
        void (*action)();
    };
}

#endif /* !CONTROLWIDGET_HPP_ */
