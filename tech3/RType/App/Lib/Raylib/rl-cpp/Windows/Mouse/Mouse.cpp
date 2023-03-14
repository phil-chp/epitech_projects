/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Mouse
*/

#include "Lib/Raylib/rl-cpp/Windows/Mouse/Mouse.hpp"

bool rl::Mouse::isButtonPressed(int button)
{
    return (::IsMouseButtonPressed(button));
}

bool rl::Mouse::isButtonDown(int button)
{
    return (::IsMouseButtonDown(button));
}

bool rl::Mouse::isButtonReleased(int button)
{
    return (::IsMouseButtonReleased(button));
}

bool rl::Mouse::isButtonUp(int button)
{
    return (::IsMouseButtonUp(button));
}

int rl::Mouse::getPositionX()
{
    return (::GetMouseX());
}

int rl::Mouse::getPositionY()
{
    return (::GetMouseY());
}

rl::Vector2 rl::Mouse::getPosition()
{
    return (rl::Vector2(::GetMousePosition()));
}

rl::Vector2 rl::Mouse::getDelta()
{
    return (rl::Vector2(::GetMouseDelta()));
}

void rl::Mouse::setPosition(int x, int y)
{
    ::SetMousePosition(x, y);
}

void rl::Mouse::setOffset(int offsetX, int offsetY)
{
    ::SetMouseOffset(offsetX, offsetY);
}

void rl::Mouse::setScale(float scaleX, float scaleY)
{
    ::SetMouseScale(scaleX, scaleY);
}

float rl::Mouse::getWheelMove()
{
    return (::GetMouseWheelMove());
}

// TODO: Shouldn't this be in Cursor/Cursor?
void rl::Mouse::setCursor(int cursor)
{
    ::SetMouseCursor(cursor);
}

rl::Ray rl::Mouse::getRay(rl::Camera3D const &camera)
{
    return (rl::Ray(::GetMouseRay(rl::Mouse::getPosition(), camera)));
}
