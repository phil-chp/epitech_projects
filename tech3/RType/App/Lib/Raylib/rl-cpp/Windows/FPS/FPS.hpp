/*
** EPITECH PROJECT, 2022
** RType
** File description:
** FPS
*/

#ifndef FPS_HPP_
# define FPS_HPP_

#include "Lib/Raylib/rl-cpp/Raylib-cpp.hpp"
#include "Lib/Raylib/rl-cpp/Drawable/IDrawable.hpp"
#include "Lib/Raylib/rl-cpp/Vectors/Vector2.hpp"

namespace rl {
    class FPS : public IDrawable {
        public:
            FPS(int targetFPS = 60)
                : pos(rl::Vector2(10, 10))
                , _targetFPS(targetFPS)
            {
                this->setTargetFPS(this->_targetFPS);
            }
            explicit FPS(Vector2 const &pos_, int targetFPS = 60) : pos(pos_), _targetFPS(targetFPS) {}
            ~FPS() = default;

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // Set target FPS (maximum)
            void setTargetFPS(int fps);
            // Get current FPS
            int getTargetFPS();
            // Get time in seconds for last frame drawn (delta time)
            float getFrameTime() const;
            // Get elapsed time in seconds since InitWindow()
            double getTime() const;
            // Draw FPS text on screen
            void draw() const override;


            Vector2 pos;
        private:
            int _targetFPS;

    };
}

#endif /* !FPS_HPP_ */
