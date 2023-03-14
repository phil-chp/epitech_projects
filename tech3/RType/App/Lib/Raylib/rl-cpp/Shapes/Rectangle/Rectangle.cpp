/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Rectangle
*/

#include "Lib/Raylib/rl-cpp/Shapes/Rectangle/Rectangle.hpp"

void rl::Rectangle::draw() const
{
    // std::cout << "draw rctangle" << std::endl;
    ::DrawRectangleRec(*this, this->color);
}

bool rl::Rectangle::CheckCollisionRecs(rl::Rectangle const &rec) const
{
    return (::CheckCollisionRecs(*this, rec));
}

bool rl::Rectangle::CheckCollisionCircleRec(rl::Vector2 const &center, float radius) const
{
    return (::CheckCollisionCircleRec(center, radius, *this));
}

bool rl::Rectangle::CheckCollisionPointRec(rl::Vector2 const &point) const
{
    return (::CheckCollisionPointRec(point, *this));
}

rl::Rectangle rl::Rectangle::GetCollisionRec(rl::Rectangle const &rec) const
{
    return rl::Rectangle(::GetCollisionRec(*this, rec));
}

void rl::Rectangle::setTexture(Texture const &texture) const
{
    ::SetShapesTexture(texture, *this);
}
