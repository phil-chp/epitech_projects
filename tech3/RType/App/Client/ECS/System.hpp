/*
** EPITECH PROJECT, 2022
** RType
** File description:
** System
*/

#ifndef SYSTEM_HPP_
    #define SYSTEM_HPP_

    #include "ECS/Entity.hpp"
    #include "ECS/Component.hpp"
    #include "GameEngine/PollEvent.hpp"
    #include <algorithm>
    #include <set>

namespace ecs {
    class ISystem {
        public:
            virtual void update(::engine::PollEvent &) const = 0;
    };

    class ASystem : public ISystem {
        public:
            std::set<Entity> entities;
    };
}

#endif /* !SYSTEM_HPP_ */
