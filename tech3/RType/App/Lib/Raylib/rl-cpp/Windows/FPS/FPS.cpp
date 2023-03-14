/*
** EPITECH PROJECT, 2022
** RType
** File description:
** FPS
*/

#include "Lib/Raylib/rl-cpp/Windows/FPS/FPS.hpp"

void rl::FPS::setTargetFPS(int fps)
{
    this->_targetFPS = fps;
    ::SetTargetFPS(fps);
}

int rl::FPS::getTargetFPS()
{
    return (this->_targetFPS);
}

float rl::FPS::getFrameTime() const
{
    return (::GetFrameTime());
}

double rl::FPS::getTime() const
{
    return (::GetTime());
}

void rl::FPS::draw() const
{
    ::DrawFPS(this->pos.x, this->pos.y);
}
