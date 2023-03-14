/*
** EPITECH PROJECT, 2022
** RType
** File description:
** MenuParallax
*/

#ifndef MENUPARALLAX_HPP_
#define MENUPARALLAX_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"


namespace engine {
namespace rtype {
    class MenuParallax : public ::engine::Entity {
        public:
            MenuParallax() : ::engine::Entity() {
                std::vector<::ecs::Entity> layers;
                int bg = SpriteType::BG_MENU1;
                for (int i = 0; i < 4; ++i) {
                    ::ecs::Entity entity = ::ecs::Coordinator::getInstance().createEntity();
                    ::ecs::Coordinator::getInstance().addComponent(
                        entity,
                        ::ecs::Transform {
                            .position = ::game::Vector2(0, 0),
                            .rotation = 0,
                            .scale = 0
                    });
                    ::ecs::Coordinator::getInstance().addComponent(
                        entity,
                        ::ecs::Scroll {
                            .xVel = (float) (-100 * i / 2),
                            .yVel = 0,
                            .pause = false
                    });
                    ::ecs::Coordinator::getInstance().addComponent(
                        entity,
                        ::ecs::RLBackground {
                            SpriteManager::getInstance().getData((engine::SpriteType)(bg + i))
                    });
                    layers.push_back(entity);
                }
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ::ecs::Parallax {
                        .layers = layers,
                        .finish = -1920,
                        .size = 1920,
                        .reps = 3
                });
            };
        private:

    };


} // rtype
} // engine

#endif /* !MENUPARALLAX_HPP_ */
