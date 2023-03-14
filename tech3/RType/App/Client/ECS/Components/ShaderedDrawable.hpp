/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Shader
*/

#ifndef SHADER_COMP_HPP_
#define SHADER_COMP_HPP_

    #include <vector>
    #include "ECS/Entity.hpp"
    #include "Utils/Vector2.hpp"
    #include <map>

namespace ecs {
    template <typename T>
    struct ShaderedDrawable {

        void update(ecs::Entity, float dt);
        void draw();

        T _shader;
        ::game::Vector2 offset;
        std::vector<ecs::Entity> _entities;
        std::map<int, float> _shaderValues;
        void (*upd) (ecs::Entity, float dt);
        bool background;
    };
}

#endif /* ! SHADER_COMP_HPP_ */
