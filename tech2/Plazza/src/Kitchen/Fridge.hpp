/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** Fridge
*/

#ifndef FRIDGE_HPP_
    #define FRIDGE_HPP_

    #include "Mutex/ScopedLock.hpp"
    #include "Utils/Pizza.hpp"
    #include <iostream>
    #include <algorithm>
    #include <sstream>
    #include <mutex>

struct Ingredient {
    explicit Ingredient(std::string const &name, size_t qt = 5)
        : name(name), qt(qt)
    {};


    void operator--(void) {
        --(this->qt);
    }

    std::string name;
    size_t qt;
};

struct Fridge {
    public:
        Fridge();
        ~Fridge();

        void addIngredient(Ingredient &ingredient);
        void takeIngredient(std::string const &name, size_t qt);
        bool giveIngredients(std::vector<Ingredient> pizzaIngredient);
        bool isEnoughIngredient(std::vector<Ingredient> pizzaIngredient);
        void refill();
        void dump();
        const std::stringstream &getStatus();
        std::shared_ptr<std::mutex> &getMutex();

    private:
        std::vector<Ingredient> _ingredients;
        std::stringstream _status;
        std::shared_ptr<std::mutex> _mutex;
};

#endif /* !FRIDGE_HPP_ */
