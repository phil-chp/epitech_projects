/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Color
*/

#include "Lib/Raylib/rl-cpp/Colors/Color.hpp"

void rl::Color::fade(float alpha)
{
    *this = std::move(::Fade(*this, alpha));
}

int rl::Color::toInt() const
{
    return (::ColorToInt(*this));
}

rl::Vector4 rl::Color::normalize() const
{
    return Vector4(std::move(::ColorNormalize(*this)));
}

rl::Vector3 rl::Color::toHSV() const
{
    return Vector3(std::move(::ColorToHSV(*this)));
}

void rl::Color::alphaBlend(Color const &src, Color const &tint)
{
    *this = std::move(::ColorAlphaBlend(*this, src, tint));
}

// Color getColor(unsigned int hexValue) const
// {

// }
