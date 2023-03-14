/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** SpawnSystem
*/

#ifndef SPAWNSYSTEM_HPP_
    #define SPAWNSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Components/Spawn.hpp"
    #include "ECS/Components/RigidBody.hpp"
    #include "ECS/Components/Transform.hpp"
    #include "ECS/Coordinator.hpp"

namespace ecs {
class SpawnSystem : public ASystem {
        public:
            SpawnSystem() = default;
            ~SpawnSystem() = default;

            void update(::engine::PollEvent &event) const final;
    };
}
#endif /* !SPAWNSYSTEM_HPP_ */
