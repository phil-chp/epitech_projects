/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** Entity
*/

#ifndef ENG_ENTITY_HPP_
    #define ENG_ENTITY_HPP_

    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/IEntity.hpp"



namespace engine {

    class Entity : public ::engine::IEntity {
        public:
            Entity() {
                this->entity = ::ecs::Coordinator::getInstance().createEntity();
            }

            ecs::Entity getEntity() override {
                return (this->entity);
            }
            ::ecs::Entity entity;
    };
}

#endif /* !ENG_ENTITY_HPP_ */
