/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Background
*/

#ifndef BACKGROUND_HPP_
    #define BACKGROUND_HPP_

    #include "Utils/Vector2.hpp"
    #include "ECS/Entity.hpp"

namespace ecs {
    template <typename T, typename K>
    class Background {

        public:
        //TODO: copy and move ctor
            Background() = default;
            Background(T background) : _background(background) {};
            ~Background() = default;

            void draw(const K &);
            void drawRec(const K &);
            void swap(T) {};


            void setSize(const game::Vector2 &size);
            const game::Vector2 getSize();

            T _background;
    };
};
#endif /* !BACKGROUND_HPP_ */
