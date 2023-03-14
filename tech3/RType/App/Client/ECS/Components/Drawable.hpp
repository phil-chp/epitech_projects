/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
    #define DRAWABLE_HPP_

    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include "ECS/Entity.hpp"

namespace ecs {
    template <typename T, typename K>
    class Drawable {

        public:
            Drawable() = default;
            Drawable(T drawable, bool shadered = false, ecs::Entity shader = -1) : _drawable(drawable), shadered(shadered), shader(shader) {};
            ~Drawable() = default;

            void draw(const K &);
            void drawRec(const K &);

            void setScale(const game::Vector2 &scale);
            const game::Vector2 getScale();

            void setAnimate(const game::Rect &animate);
            const game::Rect getAnimate();

            void setSize(const game::Vector2 &size);
            const game::Vector2 getSize();

            T _drawable;
            bool shadered;
            ecs::Entity shader;
    };
};
#endif /* !DRAWABLE_HPP_ */
