/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
    #define COLLISION_HPP_

    #include "Raylib-cpp.hpp"
    #include "Vectors/Vector2.hpp"
    #include "Shapes/Rectangle/Rectangle.hpp"

namespace rl {
    class Collision {
        public:

        //* Custom ---------------------------------------------------------- //

        //* Built-in -------------------------------------------------------- //

            // check collision between two rectangles
            static bool checkRecs(Rectangle const &rec1, Rectangle const &rec2);
            // check collision between two circles
            static bool checkCircles(Vector2 const &center1, float radius1, Vector2 const &center2, float radius2);
            // check collision between circle and rectangle
            static bool checkCircleRec(Vector2 const &center, float radius, Rectangle const &rec);
            // check if point is inside rectangle
            static bool checkPointRec(Vector2 const &point, Rectangle const &rec);
            // check if point is inside circle
            static bool checkPointCircle(Vector2 const &point, Vector2 const &center, float radius);
            // check if point is inside a triangle
            static bool checkPointTriangle(Vector2 const &point, Vector2 const &p1, Vector2 const &p2, Vector2 const &p3);
            // check the collision between two lines defined by two points each, returns collision point by reference
            static bool checkLines(Vector2 const &startPos1, Vector2 const &endPos1, Vector2 const &startPos2, Vector2 const &endPos2, Vector2 *collisionPoint);
            // check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]
            static bool checkPointLine(Vector2 const &point, Vector2 const &p1, Vector2 const &p2, int threshold);
    };
}

#endif /* !COLLISION_HPP_ */
