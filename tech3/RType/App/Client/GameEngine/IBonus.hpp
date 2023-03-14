/*
** EPITECH PROJECT, 2022
** RType
** File description:
** IBonus
*/

#ifndef IBONUS_HPP_
#define IBONUS_HPP_
    #include "GameEngine/Entity.hpp"


namespace engine {
    class IBonus : public engine::Entity {
        public:
            virtual void apply(ecs::Entity entToApply) = 0;
            virtual void remove() = 0;
    };
}


#endif /* !IBONUS_HPP_ */
