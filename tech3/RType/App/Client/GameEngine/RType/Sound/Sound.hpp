/*
** EPITECH PROJECT, 2022
** RType
** File description:
** sound.hpp
*/

#pragma once

#include "GameEngine/Managers/SoundManager.hpp"
#include "GameEngine/Entity.hpp"
#include "ECS/Entity.hpp"

namespace engine {
    template<engine::SoundType ST>
    class Sound : public engine::Entity{
        Sound() : Entity(){
            ecs::Coordinator::getInstance().template addComponent(
                    this->entity,
                    ecs::SoundEffect {
                            .loop = false,
                            .repeat = 1,
                            .isPlaying = false,
                            .sound = engine::SoundManager::getInstance().getData(ST)
                        }
                    );
        }
        static void attach(ecs::Entity ent) {
               ecs::Coordinator::getInstance().template addComponent(
                       ent,
                       ecs::SoundEffect {
                               .loop = true,
                               .repeat = 1,
                               .isPlaying = false,
                               .sound = engine::SoundManager::getInstance().getData(ST)
                       }
               );
        }
    };
}
