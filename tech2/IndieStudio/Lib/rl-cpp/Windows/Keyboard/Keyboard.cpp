/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Keyboard
*/

#include "Keyboard.hpp"

bool rl::Keyboard::isKeyPressed(int key)
{
    return (::IsKeyPressed(key));
}

bool rl::Keyboard::isKeyDown(int key)
{
    return (::IsKeyDown(key));
}

bool rl::Keyboard::isKeyReleased(int key)
{
    return (::IsKeyReleased(key));
}

bool rl::Keyboard::isKeyUp(int key)
{
    return (::IsKeyUp(key));
}

void rl::Keyboard::setExitKey(int key)
{
    ::SetExitKey(key);
}

int rl::Keyboard::getKeyPressed()
{
    return (::GetKeyPressed());
}
