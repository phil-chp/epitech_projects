/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Keyboard
*/


#ifndef KEYBOARD_HPP_
    #define KEYBOARD_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Keyboard/KeyboardKeys.hpp"
    #include <iostream>
    #include <vector>
    #include <map>

namespace rl {
    class Keyboard {
        public:

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // Check if a key has been pressed once
            static bool isKeyPressed(int key);
            // Check if a key is being pressed
            static bool isKeyDown(int key);
            // Check if a key has been released once
            static bool isKeyReleased(int key);
            // Check if a key is NOT being pressed
            static bool isKeyUp(int key);
            // Set a custom key to exit program (default is ESC)
            static void setExitKey(int key);
            // Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
            static int getKeyPressed();
    };
}

#endif /* !KEYBOARD_HPP_ */
