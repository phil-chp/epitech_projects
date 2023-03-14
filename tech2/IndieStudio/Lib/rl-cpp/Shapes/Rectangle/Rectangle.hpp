/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_

    #include "Raylib-cpp.hpp"
    #include "Colors/Color.hpp"
    #include "Colors/Colors.hpp"
    #include "Vectors/Vector2.hpp"
    #include "Drawable/IDrawable.hpp"

namespace rl {
    class Rectangle : public IDrawable, public ::Rectangle {
        public:
            Rectangle(float x, float y, float w, float h, Color tint = RL_RED) : ::Rectangle{x, y, w, h}, color(tint) {}
            Rectangle(Vector2 const &pos, Vector2 const &size, Color tint = RL_RED) : ::Rectangle{pos.x, pos.y, size.x, size.y}, color(tint) {}
            explicit Rectangle(::Rectangle const &rectangle) : ::Rectangle{rectangle}, color(RL_RED) {};

            void operator=(::Rectangle const &rectangle) {
                this->x = rectangle.x;
                this->y = rectangle.y;
                this->width = rectangle.width;
                this->height = rectangle.height;
            }

            ~Rectangle() = default;

        //* Custom ---------------------------------------------------------- //

            void setPosition(Vector2 const &position) {
                this->x = position.x;
                this->y = position.y;
            }
            void setSize(Vector2 const &size) {
                this->width = size.x;
                this->height = size.y;
            }
            Vector2 getPosition() {
                return Vector2(this->x, this->y);
            }
            Vector2 getSize() {
                return Vector2(this->width, this->height);
            }

        //* Built-in -------------------------------------------------------- //

            // Draw a color-filled rectangle
            void draw() const override;
            // Check collision between two rectangles
            bool CheckCollisionRecs(Rectangle const &rec1) const;
            // Check collision between circle and rectangle
            bool CheckCollisionCircleRec(Vector2 const &center, float radius) const;
            // Check if point is inside rectangle
            bool CheckCollisionPointRec(Vector2 const &point) const;
            // Get collision rectangle for two rectangles collision
            Rectangle GetCollisionRec(Rectangle const &rec1) const;
            // Set texture rectangle for drawing
            void setTexture(Texture const &texture) const;

            Color color;

    };
}

#endif /* !RECTANGLE_HPP_ */
