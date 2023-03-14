/*
** EPITECH PROJECT, 2022
** RType
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
    #define IENTITY_HPP_

#include "ECS/Entity.hpp"

namespace engine {
    class IEntity {
        public:
            virtual ecs::Entity getEntity() = 0;
    };
}
#endif /* !IENTITY_HPP_ */
