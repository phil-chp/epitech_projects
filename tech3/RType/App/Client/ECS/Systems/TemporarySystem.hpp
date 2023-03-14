/*
** EPITECH PROJECT, 2022
** RType
** File description:
** TemporarySystem
*/

#ifndef TEMP_SYSTEM_HPP_
    #define TEMP_SYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Temporary.hpp"

namespace ecs {
    class TemporarySystem : public ASystem {
        public:
            TemporarySystem() = default;
            ~TemporarySystem() = default;

            void update(::engine::PollEvent &event) const final;
    };
}// ecs
#endif
