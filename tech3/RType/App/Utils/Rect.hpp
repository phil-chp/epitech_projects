/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Rect
*/

#ifndef GAMERECT_HPP_
    #define GAMERECT_HPP_
    #include <iostream>

namespace game {

    class Rect {
        public:
            Rect() : x(0), y(0), w(0), h(0) {};
            Rect(float a, float b, float c, float d) : x(a), y(b), w(c), h(d) {};
            ~Rect() = default;

            float x;
            float y;
            float w;
            float h;
    };
};


#endif /* !GAMERECT_HPP_ */
