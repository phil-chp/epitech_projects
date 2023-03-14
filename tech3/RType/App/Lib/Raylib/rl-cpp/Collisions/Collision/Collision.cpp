/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Collision
*/

#include "Lib/Raylib/rl-cpp/Collisions/Collision/Collision.hpp"

static bool checkRecs(Rectangle const &rec1, Rectangle const &rec2)
{
    return (::CheckCollisionRecs(rec1, rec2));
}

static bool checkCircles(Vector2 const &center1, float radius1, Vector2 const &center2, float radius2)
{
    return (::CheckCollisionCircles(center1, radius1, center2, radius2));
}

static bool checkCircleRec(Vector2 const &center, float radius, Rectangle const &rec)
{
    return (::CheckCollisionCircleRec(center, radius, rec));
}

static bool checkPointRec(Vector2 const &point, Rectangle const &rec)
{
    return (::CheckCollisionPointRec(point, rec));
}

static bool checkPointCircle(Vector2 const &point, Vector2 const &center, float radius)
{
    return (::CheckCollisionPointCircle(point, center, radius));
}

static bool checkPointTriangle(Vector2 const &point, Vector2 const &p1, Vector2 const &p2, Vector2 const &p3)
{
    return (::CheckCollisionPointTriangle(point, p1, p2, p3));
}

static bool checkLines(Vector2 const &startPos1,
                       Vector2 const &endPos1,
                       Vector2 const &startPos2,
                       Vector2 const &endPos2,
                       Vector2 *collisionPoint)
{
    return (::CheckCollisionLines(startPos1, endPos1, startPos2, endPos2, collisionPoint));
}

static bool checkPointLine(Vector2 const &point, Vector2 const &p1, Vector2 const &p2, int threshold)
{
    return (::CheckCollisionPointLine(point, p1, p2, threshold));
}
