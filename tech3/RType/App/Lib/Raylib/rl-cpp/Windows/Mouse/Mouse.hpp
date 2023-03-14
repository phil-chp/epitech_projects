/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
    #define MOUSE_HPP_

    #include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
    #include "Lib/Raylib/rl-cpp/Vectors/Vector2.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Camera/Camera3D.hpp"
    #include "Lib/Raylib/rl-cpp/Collisions/Ray/Ray.hpp"

namespace rl {
    class Mouse {
        public:

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // Check if a mouse button has been pressed once
            static bool isButtonPressed(int button);
            // Check if a mouse button is being pressed
            static bool isButtonDown(int button);
            // Check if a mouse button has been released once
            static bool isButtonReleased(int button);
            // Check if a mouse button is NOT being pressed
            static bool isButtonUp(int button);

            // Get mouse position X
            static int getPositionX();
            // Get mouse position Y
            static int getPositionY();
            // Get mouse position XY
            static Vector2 getPosition();
            // Get mouse delta between frames
            static Vector2 getDelta();
            // Get mouse wheel movement Y
            static float getWheelMove();

            // Set mouse position XY
            static void setPosition(int x, int y);
            // Set mouse offset
            static void setOffset(int offsetX, int offsetY);
            // Set mouse scaling
            static void setScale(float scaleX, float scaleY);
            // Set mouse cursor
            static void setCursor(int cursor);

            // Get a ray trace from mouse position
            static Ray getRay(Camera3D const &camera);
    };
}

#endif /* !MOUSE_HPP_ */
