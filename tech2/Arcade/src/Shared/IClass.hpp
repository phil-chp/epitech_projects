/*
** EPITECH PROJECT, 2022
** Arcade (Workspace)
** File description:
** IClass
*/

#ifndef ICLASS_HPP_
# define ICLASS_HPP_

# include "Shared/Arcade.hpp"
# include <iostream>

namespace arc
{
    /**
     * @brief
     * IClass
     * Description: Interface for the class
     * may contain all common method and attribute for all .so
     */
    class IClass {
        public:
            virtual ~IClass() = default;
            virtual arc::LibType getSignature() const = 0;
    };
}

#endif /* !ICLASS_HPP_ */
