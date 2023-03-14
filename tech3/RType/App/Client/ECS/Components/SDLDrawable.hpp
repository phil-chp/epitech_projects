/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SDLDrawable
*/

#ifndef SDLDRAWABLE_HPP_
    #define SDLDRAWABLE_HPP_

    #include "ECS/Components/Drawable.hpp"
    #include "Lib/SDL/Sprite.hpp"

namespace ecs {
    typedef Drawable<::lib::sdl::Sprite, game::Vector2> SDLDrawable;
};
#endif /* !SDLDRAWABLE_HPP_ */
