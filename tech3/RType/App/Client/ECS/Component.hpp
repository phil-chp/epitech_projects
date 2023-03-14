/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
    #define COMPONENT_HPP_

    #include <iostream>
    #include <bitset>

namespace ecs {
    using Entity = std::uint32_t;
    using ComponentType = std::uint8_t; // 256 components max
    const ComponentType MAX_COMPONENTS = 64;
    using Signature = std::bitset<MAX_COMPONENTS>;
}

#endif /* !COMPONENT_HPP_ */
