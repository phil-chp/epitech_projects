/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Collision
*/

#ifndef COLLISION_HPP_
    #define COLLISION_HPP_

    #include "GameEngine/Entity.hpp"
    #include "ECS/Components/Alive.hpp"
    #include <map>


namespace engine {
    class Collision {
        public:
            template <int N, int K>
            static void collides(::ecs::Entity ent, ::ecs::Entity other, ::engine::PollEvent &event) {
                if (K == N)
                    return;
                std::cout << "Unmanaged Collision" << std::endl;
            }

            static void collide(::ecs::Entity ent, ::ecs::Entity other, int type, int otrType, ::engine::PollEvent &event);
    };


};

#endif /* !COLLISION_HPP_ */
