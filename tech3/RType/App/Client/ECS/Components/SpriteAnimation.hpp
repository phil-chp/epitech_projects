/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** SpriteAnimation
*/

#ifndef SPRITE_ANIMATION_HPP_
    #define SPRITE_ANIMATION_HPP_

    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include <vector>
    #include "ECS/Components/Animation.hpp"
    #include "ECS/Components/RLDrawable.hpp"

namespace ecs {
    typedef ecs::Animation<ecs::RLDrawable, std::vector<::game::Rect>> SpriteAnimation; // rtype
} // ecs

#endif /* !SPRITE_ANIMATION_HPP_ */
