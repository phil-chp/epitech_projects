
#ifndef COMPOTEXT_HPP_
    #define COMPOTEXT_HPP_

    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"
    #include "ECS/Entity.hpp"

namespace ecs {
    template <typename T, typename K>
    class Text {

        public:
        //TODO: copy and move ctor
            Text() = default;
            Text(T text, int ID) : _text(text), listID(ID), dead(false) {};
            ~Text() = default;

            void draw(const K &);
            void swap(T) {};



            T _text;
            int listID;
            bool dead;
    };
};

#endif /* !COMPOTEXT_HPP_ */
