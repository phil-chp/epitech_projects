/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RLDrawable
*/

#ifndef RLDRAWABLE_HPP_
    #define RLDRAWABLE_HPP_

    #include "ECS/Components/Drawable.hpp"
    #include "Lib/Raylib/rl-cpp/Textures/Textures.hpp"

namespace ecs {
    typedef Drawable<::rl::Texture, ::game::Vector2> RLDrawable;
};
#endif /* !RLDRAWABLE_HPP_ */
