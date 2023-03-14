/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RaygunBonus
*/

#ifndef DOUBLESHOOT_HPP_
#define DOUBLESHOOT_HPP_
    #include "GameEngine/IBonus.hpp"
    #include "GameEngine/RType/Bonus/RaygunBonus.hpp"
    #include "GameEngine/RType/Bonus/BigShipBonus.hpp"
    #include "GameEngine/RType/Bonus/SmallShipBonus.hpp"
    #include "GameEngine/RType/Bonus/ShieldBonus.hpp"


namespace engine {
    namespace rtype {
        enum BonusType {
            NONE = -1,
            RAYGUN,
            BIGSHIP,
            SMALLSHIP,
            GUIDEDMISSILE
            // TRIPLE_SHOOT,
            // SPEED_UP,
            // SPEED_DOWN,
            // LIFE_UP,
            // LIFE_DOWN,
            // SHIELD,
            // BOMB,
            // MAX_BONUS
        };


        class BonusFactory {
            public:
                BonusFactory() = default;
                ~BonusFactory() = default;
                static std::unique_ptr<IBonus> createBonus(BonusType type) {
                    switch (type) {
                        case RAYGUN:
                            return std::make_unique<RaygunBonus>();
                        default:
                            return nullptr;
                    }
                }
        };
    }
}

#endif /* !DOUBLESHOOT_HPP_ */
