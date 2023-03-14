/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Gamepad
*/

#include "Lib/Raylib/rl-cpp/Windows/Gamepad/Gamepad.hpp"

bool rl::Gamepad::isAvailable(int gamepad)
{
    return (::IsGamepadAvailable(gamepad));
}

std::string const rl::Gamepad::getName(int gamepad)
{
    return (std::string(::GetGamepadName(gamepad)));
}

bool rl::Gamepad::isButtonPressed(int gamepad, int button)
{
    return (::IsGamepadButtonPressed(gamepad, button));
}

bool rl::Gamepad::isButtonDown(int gamepad, int button)
{
    return (::IsGamepadButtonDown(gamepad, button));
}

bool rl::Gamepad::isButtonReleased(int gamepad, int button)
{
    return (::IsGamepadButtonReleased(gamepad, button));
}

bool rl::Gamepad::isButtonUp(int gamepad, int button)
{
    return (::IsGamepadButtonUp(gamepad, button));
}

int rl::Gamepad::setMappings(const std::string &mappings)
{
    return (::SetGamepadMappings(mappings.c_str()));
}

int rl::Gamepad::getButtonPressed()
{
    return (::GetGamepadButtonPressed());
}

int rl::Gamepad::getAxisCount(int gamepad)
{
    return (::GetGamepadAxisCount(gamepad));
}

float rl::Gamepad::getAxisMovement(int gamepad, int axis)
{
    return (::GetGamepadAxisMovement(gamepad, axis));
}
