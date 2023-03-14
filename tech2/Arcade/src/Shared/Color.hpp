/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** Color
*/

#ifndef COLOR_HPP
# define COLOR_HPP
# include <iostream>
# include <map>
namespace arc
{
    class Color {
        public:
            Color(char const r = 0, char const g = 0, char const b = 0)
                : r(r), g(g), b(b)
            {};
            ~Color() {};
            char r;
            char g;
            char b;
    };
}

#endif /* !COLOR_HPP */
