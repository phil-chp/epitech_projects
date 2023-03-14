/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include "ECS/Component.hpp"
    #include <iostream>
    #include <bitset>

namespace ecs {
    using Entity = std::uint32_t;
    const Entity MAX_ENTITIES = 512;
    using Signature = std::bitset<MAX_COMPONENTS>;
}

#endif /* !ENTITY_HPP_ */
