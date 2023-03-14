/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_

    #include <iostream>
    #include <map>
    #include <vector>

namespace pizza {
    enum Type {
        Regina    = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia  = 8
    };

    enum Size {
        S   = 1,
        M   = 2,
        L   = 4,
        XL  = 8,
        XXL = 16
    };

    std::map<std::string, Type> const typeMap = {
        {"Regina",    Regina},
        {"Margarita", Margarita},
        {"Americana", Americana},
        {"Fantasia",  Fantasia}
    };

    std::map<std::string, Size> const sizeMap = {
        {"S",   S},
        {"M",   M},
        {"L",   L},
        {"XL",  XL},
        {"XXL", XXL}
    };

    std::vector<std::string> const defaultFridge = {
        "doe",
        "tomato",
        "gruyere",
        "ham",
        "mushrooms",
        "steak",
        "eggplant",
        "goat cheese"
    };

    std::vector<std::string> const defaultMenu = {
        "Regina",
        "Margarita",
        "Americana",
        "Fantasia"
    };
}

#endif /* !PIZZA_HPP_ */
