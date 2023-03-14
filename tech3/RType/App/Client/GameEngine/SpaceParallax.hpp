/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Parallax
*/

#ifndef ENGINE_PARALLAX_HPP_
    #define ENGINE_PARALLAX_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"


namespace engine {
namespace rtype {
    class SpaceParallax : public ::engine::Entity {
        public:

            static ecs::Entity construct() {
                SpaceParallax spaceParallax;
                return (spaceParallax.entity);
            }
            SpaceParallax() : ::engine::Entity() {
                std::vector<::ecs::Entity> layers;
                int bg = SpriteType::BG_LAYER1;
                ::game::Vector2 size(2048 * 1.2, 1024 * 1.2);
                for (int i = 0; i < 4; ++i) {
                    ::ecs::Entity entity = ::ecs::Coordinator::getInstance().createEntity();
                    ::ecs::Coordinator::getInstance().addComponent(
                        entity,
                        ::ecs::Transform {
                            .position = ::game::Vector2(0, (1080 - size.y) / 2),
                            .rotation = 0,
                            .scale = 0
                    });
                    ::ecs::Coordinator::getInstance().addComponent(
                        entity,
                        ::ecs::Scroll {
                            .xVel = (float)  -25 + (-75 * i / 2),
                            .yVel = 0.0,
                            .pause = false
                    });
                    ::ecs::Coordinator::getInstance().addComponent(
                        entity,
                        ::ecs::RLBackground {
                            SpriteManager::getInstance().getData((engine::SpriteType)(bg + i))
                    });


                    ecs::RLBackground &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLBackground>(entity);
                    drawable.setSize(size);
                    // drawable.setScale(size);

                    // std::cout << drawable._background.getSize().x << ", " << drawable._background.getSize().y << std::endl;

                    layers.push_back(entity);

                }
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ::ecs::Parallax {
                        .layers = layers,
                        .finish = (int)-size.x,
                        .size = (int)size.x,
                        .reps = 3
                });
            };
        private:

    };


} // rtype
} // engine

#endif
