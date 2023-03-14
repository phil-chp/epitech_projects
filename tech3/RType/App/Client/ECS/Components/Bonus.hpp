/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"
    #include <map>


namespace ecs {
    enum BonusType {
        NONE_BONUS = -1,
        RAYGUN_BONUS,
        BIGSHIP_BONUS,
        SMALLSHIP_BONUS,
        SHIELD_BONUS
    };

    struct Bonus {
        bool hasBonus;
        std::map<BonusType, ecs::Entity> bonus;
    };
};
#endif /* !BONUS_HPP_ */
