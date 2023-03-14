/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
    #define DRAWABLE_HPP_

    #include "Raylib.hpp"

namespace ecs {
    struct Drawable {
        void drawShadow(rl::Vector3 &pos, rl::Vector3 &size) {
            DrawCubeV(
                rl::Vector3(pos.x, 0, pos.z),
                rl::Vector3(
                    size.x * (9.5 + pos.y - size.y / 2) / 10,
                    0,
                    size.z * (9.5 + pos.y - size.y / 2) / 10
                ),
                rl::Color{0, 0, 0, (unsigned char)(round(255 - 20 * pos.y) > 0 ? round(255 - 20 * pos.y) : 0)}
            );
        }
        void draw(rl::Vector3 &pos, rl::Vector3 &size) {
            // DrawCubeV(pos, size, color);
            drawable.position = pos;
            drawable.size = size;
            drawable.draw();
            if (this->shadow)
                drawShadow(pos, size); 
            drawable.drawTexture(texture);
        }

        rl::Cube drawable;
        rl::Texture texture;

        // rl::Color color;
        bool shadow;
    };
}

#endif /* !DRAWABLE_HPP_ */
