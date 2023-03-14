/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Gamepad
*/

#ifndef GAMEPAD_HPP_
    #define GAMEPAD_HPP_

    #include "Raylib-cpp.hpp"
    #include "GamepadKeys.hpp"
    #include <string>

namespace rl {
    class Gamepad {
        public:

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // Check if a gamepad is available
            static bool isAvailable(int gamepad);
            // Get gamepad internal name id
            static std::string const getName(int gamepad);
            // Check if a gamepad button has been pressed once
            static bool isButtonPressed(int gamepad, int button);
            // Check if a gamepad button is being pressed
            static bool isButtonDown(int gamepad, int button);
            // Check if a gamepad button has been released once
            static bool isButtonReleased(int gamepad, int button);
            // Check if a gamepad button is NOT being pressed
            static bool isButtonUp(int gamepad, int button);
            // Set internal gamepad mappings (SDL_GameControllerDB)
            static int setMappings(std::string const &mappings);
            // Get the last gamepad button pressed
            static int getButtonPressed();
            // Get gamepad axis count for a gamepad
            static int getAxisCount(int gamepad);
            // Get axis movement value for a gamepad axis
            static float getAxisMovement(int gamepad, int axis);
    };
}

#endif /* !GAMEPAD_HPP_ */
