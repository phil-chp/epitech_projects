/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Ray
*/

#include "Lib/Raylib/rl-cpp/Collisions/Ray/Ray.hpp"

// Draw the ray
void rl::Ray::draw() const
{
    ::DrawRay(*this, color);
}

// Get collision info between ray and sphere
rl::RayCollision rl::Ray::getCollisionSphere(rl::Sphere const &sphere) const
{
    return rl::RayCollision(::GetRayCollisionSphere(*this, sphere.position, sphere.radius));
}

// Get collision info between ray and box
rl::RayCollision rl::Ray::getCollisionBox(rl::BoundingBox const &box) const
{
    return rl::RayCollision(::GetRayCollisionBox(*this, box));
}


// Get collision info between ray and mesh
rl::RayCollision rl::Ray::getCollisionMesh(rl::Mesh const &mesh) const
{
    return (rl::RayCollision(::GetRayCollisionMesh(*this, mesh, mesh.transform)));
}

// Get collision info between ray and triangle
rl::RayCollision rl::Ray::getCollisionTriangle(rl::Triangle3D const &triangle) const
{
    return (rl::RayCollision(::GetRayCollisionTriangle(*this, triangle.v1, triangle.v2, triangle.v3)));
}


// Get collision info between ray and quad
rl::RayCollision rl::Ray::getCollisionQuad(rl::Vector3 const &p1, rl::Vector3 const &p2, rl::Vector3 const &p3, rl::Vector3 const &p4) const
{
    return (rl::RayCollision(::GetRayCollisionQuad(*this, p1, p2, p3, p4)));
}
