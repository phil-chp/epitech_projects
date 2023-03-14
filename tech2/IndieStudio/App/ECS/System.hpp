/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** System
*/

#ifndef SYSTEM_HPP_
    #define SYSTEM_HPP_

    #include "ECS/Entity.hpp"
    #include "ECS/Component.hpp"
    #include "Utils/SettingsManager.hpp"
    #include "Raylib.hpp"
    #include <algorithm>
    #include <set>

namespace ecs {
    class ISystem {
        public:
            virtual void update(float dt) const = 0;
    };

    class ASystem : public ISystem {
        public:
            std::set<Entity> entities;
    };
}

#endif /* !SYSTEM_HPP_ */
