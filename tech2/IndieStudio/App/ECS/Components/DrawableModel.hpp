/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Drawable
*/

#ifndef DRAWABLE_MODEL_HPP_
    #define DRAWABLE_MODEL_HPP_

    #define _USE_MATH_DEFINES // must include this!

    #include "Raylib.hpp"
    #include <cmath>

namespace ecs {
    struct DrawableModel {
        void draw(rl::Vector3 const &pos, rl::Vector3 &rotation, float scale_) {
            model.position = pos;
            model.scale = factor * scale_;
            model.transform = MatrixRotateXYZ(rl::Vector3(DEG2RAD * 90.0f, DEG2RAD * rotation.y, 0.0f));

            model.draw();
        }

        rl::Model model;
        float factor;
        rl::ModelType type;
    };
}

#endif /* !DRAWABLE_MODEL_HPP_ */
