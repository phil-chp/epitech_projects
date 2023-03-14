/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** BoundingBox
*/

#include "BoundingBox.hpp"

// Check collision between two bounding boxes
bool rl::BoundingBox::checkCollisionBoxes(BoundingBox const &box) const
{
    return (::CheckCollisionBoxes(*this, box));
}

// Check collision between two bounding boxes
bool rl::BoundingBox::checkCollisionBoxSphere(Sphere const &sphere) const
{
    return (::CheckCollisionBoxSphere(*this, sphere.position, sphere.radius));
}
