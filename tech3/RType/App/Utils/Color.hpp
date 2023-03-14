/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Color
*/

#ifndef COLOR_HPP_
#define COLOR_HPP_

namespace game {
class Color {
    public:
        Color() = default;
        Color(int r, int g, int b, int a) : _r(r), _g(g), _b(b), _a(a) {};
        ~Color() = default;

        int _r;
        int _g;
        int _b;
        int _a;
};
}

#endif /* !COLOR_HPP_ */
