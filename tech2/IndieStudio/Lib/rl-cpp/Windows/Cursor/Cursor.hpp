/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Cursor
*/

#ifndef CURSOR_HPP_
    #define CURSOR_HPP_

    #include "Raylib-cpp.hpp"

namespace rl {
    class Cursor {
        public:
            Cursor() : _isHidden(false), _isActive(true) {}

            ~Cursor() = default;

        //* Custom ---------------------------------------------------------- //

            // Checks if cursor is visible, active and on screen
            bool isAccessible() const;

        //* Built-in -------------------------------------------------------- //

            // Shows cursor
            void show();
            // Hides cursor
            void hide();
            // Check if cursor is not visible
            bool isHidden() const;
            // Enables cursor (unlock cursor)
            void enable();
            // Disables cursor (lock cursor)
            void disable();
            // Check if cursor is on the screen
            bool isActive() const;
            // Check if cursor is on the screen
            bool isOnScreen() const;

        private:
            bool _isHidden;
            bool _isActive;

    };
}

#endif /* !CURSOR_HPP_ */
