/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Spawner
*/

#ifndef SPAWNER_HPP_
    #define SPAWNER_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/EntityFactory.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Alive.hpp"
    #include "ECS/Components/Temporary.hpp"
    #include "ECS/Components/Spawn.hpp"
    #include "ECS/Components/Transform.hpp"

namespace engine {
    class Spawner : public engine::Entity {
        public:
            Spawner() : engine::Entity()
            {
                ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Transform {
                        .position = {0, 0},
                        .rotation = 0,
                        .scale = 0
                });
                ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Spawn {
                        .type = 0,
                        .rate = 100,
                        .repeat = 1,
                        .timed = false,
                        .delay = 0,
                        .lifed = false,
                        .spawn = &engine::Spawner::spawn
                });
                // ecs::Coordinator::getInstance().addComponent(
                //     this->entity,
                //     ecs::Temporary {
                //         .delay = 0,
                //         .done = false
                // });
            };

            Spawner(ecs::Entity entity)
            {
                this->entity = entity;
                ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Spawn {
                        .type = 0,
                        .rate = 100,
                        .repeat = 1,
                        .timed = false,
                        .delay = 0,
                        .lifed = false,
                        .spawn = &engine::Spawner::spawn
                });
            };
            ~Spawner() = default;

            void setDelay(float delay) {
                ecs::Temporary &temp = ecs::Coordinator::getInstance().getComponent<ecs::Temporary>(this->entity);
                temp.delay = delay;
                temp.done = false;
            };

            void setPos(game::Vector2 &pos) {
                ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(this->entity);
                trans.position.x = pos.x;
                trans.position.y = pos.y;
            };

            void setType(int entityType) {
                ecs::Spawn &spawn = ecs::Coordinator::getInstance().getComponent<ecs::Spawn>(this->entity);
                spawn.type = entityType;
            };

            void setReps(unsigned int repeat) {
                ecs::Spawn &spawn = ecs::Coordinator::getInstance().getComponent<ecs::Spawn>(this->entity);
                spawn.repeat = repeat;
            };

            // void setRepType(int repeatType) {
            //     ecs::Spawn &spawn = ecs::Coordinator::getInstance().getComponent<ecs::Spawn>(this->entity);
            //     spawn.repeatType = repeatType;
            // };


            void setRate(int rate) {
                ecs::Spawn &spawn = ecs::Coordinator::getInstance().getComponent<ecs::Spawn>(this->entity);
                spawn.rate = rate;
            };

            void addDelay(float delay) {
                ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Temporary {
                        .delay = delay,
                        .done = false,
                        .isBonus = false
                });
                ecs::Spawn &spawn = ecs::Coordinator::getInstance().getComponent<ecs::Spawn>(this->entity);
                spawn.timed = true;
            };

            // void addlife(int hp) {
            //     ecs::Coordinator::getInstance().addComponent(
            //         this->entity,
            //         ecs::Alive {
            //             .hp = hp,
            //             .dead = false
            //     });
            //     ecs::Spawn &spawn = ecs::Coordinator::getInstance().getComponent<Spawn>(this->entity);
            //     spawn.lifed = true;
            // };


            static ecs::Entity spawn(ecs::Entity entity) {
                ecs::Spawn &spaw = ecs::Coordinator::getInstance().getComponent<ecs::Spawn>(entity);
                ecs::Temporary &temp = ecs::Coordinator::getInstance().getComponent<ecs::Temporary>(entity);
                ecs::Transform &transform = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);

                ecs::Entity ent = engine::EntityFactory::createEntity((engine::EntityType)spaw.type);

                ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(ent);
                trans.position = transform.position;

                if (spaw.repeat > 1) {
                    // std::cout << "reset spawn timer ---------" << std::endl;
                    //spaw.repeatType
                    temp.done = false;
                    temp.delay = spaw.delay;
                    spaw.repeat -= 1;
                }
                return (ent);
            };
    };
}// engine
#endif
