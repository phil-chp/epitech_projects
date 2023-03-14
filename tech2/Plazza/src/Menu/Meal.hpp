/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Meal
*/

#ifndef MEAL_HPP_
    #define MEAL_HPP_

    #include "Kitchen/Fridge.hpp"
    #include <iostream>

class IMeal {
    public:
        virtual ~IMeal() = default;

        virtual std::string const &getName() const = 0;
        virtual size_t getId() const = 0;
        virtual size_t getTime() const = 0;
        virtual std::vector<Ingredient> const &getIngredient() const = 0;
        // void bake(Cook cook) = 0;
};

class AMeal : public IMeal {
    public:
        AMeal() = default;
        ~AMeal();

        std::string const &getName() const override {
            return (this->_name);
        }
        std::vector<Ingredient> const &getIngredient() const override {
            return (this->_ingredients);
        }
        virtual size_t getId() const override {
            return (this->_typeId);
        }
        virtual size_t getTime() const override {
            return (this->_time);
        }

    protected:
        std::vector<Ingredient> _ingredients;
        std::string _name;
        int _typeId;
        size_t _time;
        // mutex cookMutex;
};


// • 1-Margarita: Contains doe, tomato, gruyere                           -->Baked in 1 sec  * multiplier.
// • 2-Regina:    Contains doe, tomato, gruyere,  ham,         mushrooms  -->Baked in 2 secs * multiplier.
// • 4-Americana: Contains doe, tomato, gruyere,  steak                   -->Baked in 2 secs * multiplier.
// • 8-Fantasia:  Contains doe, tomato, eggplant, goat cheese, chief love -->Baked in 4 secs * multiplier.


class Margherita : public AMeal {
    public:
        Margherita() : AMeal() {
            this->_name = "Margherita";
            this->_typeId = 1;
            this->_ingredients.push_back(Ingredient("Doe", 1));
            this->_ingredients.push_back(Ingredient("Tomato", 1));
            this->_ingredients.push_back(Ingredient("Gruyere", 1));
            this->_time = 1;
        }
        ~Margherita();
};

class Regina : public AMeal {
    public:
        Regina() : AMeal() {
            this->_name = "Regina";
            this->_typeId = 2;
            this->_ingredients.push_back(Ingredient("Doe", 1));
            this->_ingredients.push_back(Ingredient("Tomato", 1));
            this->_ingredients.push_back(Ingredient("Ham", 1));
            this->_ingredients.push_back(Ingredient("Cheese", 1));
            this->_ingredients.push_back(Ingredient("Mushroom", 1));
            this->_time = 2;
        }
        ~Regina();
};

class Americana : public AMeal {
    public:
        Americana() : AMeal() {
            this->_name = "Americana";
            this->_typeId = 4;
            this->_ingredients.push_back(Ingredient("Doe", 1));
            this->_ingredients.push_back(Ingredient("Tomato", 1));
            this->_ingredients.push_back(Ingredient("Steak", 1));
            this->_ingredients.push_back(Ingredient("Gruyere", 1));
            this->_time = 2;
        }
        ~Americana();
};

class Fantasia : public AMeal {
    public:
        Fantasia() : AMeal() {
            this->_name = "Fantasia";
            this->_typeId = 8;
            this->_ingredients.push_back(Ingredient("Doe", 1));
            this->_ingredients.push_back(Ingredient("Tomato", 1));
            this->_ingredients.push_back(Ingredient("Eggplant", 1));
            this->_ingredients.push_back(Ingredient("Goat cheese", 1));
            this->_time = 4;
        }
        ~Fantasia();
};

// class CustomPizza : public AMeal {
//     public:
//         CustomPizza(std::string const &name, size_t id, std::vector<Ingredient const &> const &ing, size_t time)
//             : AMeal()
//         {
//             this->_name = name;
//             this->_typeId = id;
//             this->_ingredients = ing;
//             this->_time = time;
//         }
//         ~CustomPizza();
// };

#endif /* !MEAL_HPP_ */
