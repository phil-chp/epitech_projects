/*
** EPITECH PROJECT, 2022
** IndieStudio (Workspace)
** File description:
** PlaySoundSystem
*/

#ifndef PLAYSOUNDSYSTEM_HPP_
    #define PLAYSOUNDSYSTEM_HPP_

    #include "ECS/System.hpp"
    #include "ECS/Coordinator.hpp"
    #include "Raylib.hpp"

namespace ecs {
    class PlaySoundSystem : public ecs::ASystem {
        public:
            PlaySoundSystem() = default;
            ~PlaySoundSystem() = default;

            void update(float dt) const final;
    };
}

#endif /* !PLAYSOUNDSYSTEM_HPP_ */
