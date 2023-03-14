/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Boss
*/

#ifndef BOOS_HPP_
#define BOOS_HPP_
    #include "GameEngine/Entity.hpp"
    #include "GameEngine/EntityFactory.hpp"

namespace engine {

class Boss : public ::engine::Entity {
    public:


        Boss() : ::engine::Entity()
        {

        }
        ~Boss() = default;

        int nbReps;
        void (*action)(engine::Boss *);


};
}


#endif /* !IBOOS_HPP_ */
