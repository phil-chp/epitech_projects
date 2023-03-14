/*
** EPITECH PROJECT, 2022
** IndieStudio (Workspace)
** File description:
** PlaySoundSystem
*/

#ifndef SOUNDSYSTEM_HPP_
    #define SOUNDSYSTEM_HPP_


#include "ECS/Components/SoundEffect.hpp"
#include "ECS/System.hpp"


namespace ecs {
class SoundSystem : public ASystem {
        public:
            SoundSystem() = default;
            ~SoundSystem() = default;

            void update(::engine::PollEvent &event) const final;
    };
}
#endif /* !SOUNDSYSTEM_HPP_ */
