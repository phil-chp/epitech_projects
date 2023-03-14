/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_

    #include "Menu/Meal.hpp"
    #include <array>
    #include <queue>
    #include <iostream>
    #include <memory>

enum Tristate {
    SLEEP,
    WAITING,
    COOKING
};

class Cook {
    public:
        explicit Cook(int cookingTime, std::shared_ptr<Fridge> &fridge);
        void cook(IMeal const &pizza);
        void startClock(IMeal const &pizza);
        Tristate const &getIsCooking();
        ~Cook();

    private:
    std::queue<IMeal> _pizzas;
    Tristate _isCooking;
    std::array<int, 2> _cookingTime;
    std::shared_ptr<Fridge> _fridge;
    int _multiCookTime;
};

#endif /* !COOK_HPP_ */
