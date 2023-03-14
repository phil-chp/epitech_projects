/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** MouseKeys
*/

#ifndef MOUSEKEYS_HPP_
    #define MOUSEKEYS_HPP_

namespace rl {
    enum MouseKeys {
        MOUSE_BUTTON_LEFT    = 0,       // Mouse button left
        MOUSE_BUTTON_RIGHT   = 1,       // Mouse button right
        MOUSE_BUTTON_MIDDLE  = 2,       // Mouse button middle (pressed wheel)
        MOUSE_BUTTON_SIDE    = 3,       // Mouse button side (advanced mouse device)
        MOUSE_BUTTON_EXTRA   = 4,       // Mouse button extra (advanced mouse device)
        MOUSE_BUTTON_FORWARD = 5,       // Mouse button fordward (advanced mouse device)
        MOUSE_BUTTON_BACK    = 6,       // Mouse button back (advanced mouse device)
    };
}

#endif /* !MOUSEKEYS_HPP_ */
