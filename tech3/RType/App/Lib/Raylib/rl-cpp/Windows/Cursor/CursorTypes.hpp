/*
** EPITECH PROJECT, 2022
** RType
** File description:
** CursorTypes
*/

#ifndef CURSORTYPES_HPP_
    #define CURSORTYPES_HPP_

// TODO: Check if it's better to implement cursor inside mouse or separate
namespace rl {
    enum CursorTypes {
        MOUSE_CURSOR_DEFAULT       = 0,     // Default pointer shape
        MOUSE_CURSOR_ARROW         = 1,     // Arrow shape
        MOUSE_CURSOR_IBEAM         = 2,     // Text writing cursor shape
        MOUSE_CURSOR_CROSSHAIR     = 3,     // Cross shape
        MOUSE_CURSOR_POINTING_HAND = 4,     // Pointing hand cursor
        MOUSE_CURSOR_RESIZE_EW     = 5,     // Horizontal resize/move arrow shape
        MOUSE_CURSOR_RESIZE_NS     = 6,     // Vertical resize/move arrow shape
        MOUSE_CURSOR_RESIZE_NWSE   = 7,     // Top-left to bottom-right diagonal resize/move arrow shape
        MOUSE_CURSOR_RESIZE_NESW   = 8,     // The top-right to bottom-left diagonal resize/move arrow shape
        MOUSE_CURSOR_RESIZE_ALL    = 9,     // The omni-directional resize/move cursor shape
        MOUSE_CURSOR_NOT_ALLOWED   = 10     // The operation-not-allowed shape
    };
}

#endif /* !CURSORTYPES_HPP_ */
