/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** Fridge copy
*/

#include "Fridge.hpp"

Fridge::Fridge() {
    //init _ingredients aux valeurs de bases du sujet
    this->_mutex = std::make_shared<std::mutex>();
}

Fridge::~Fridge() {}

//* -------------------------------- Public -------------------------------- *//

void Fridge::addIngredient(Ingredient &ingredient) {
    this->_ingredients.push_back(ingredient);
}

// void removeIngredient(Ingredient *ingredient, size_t qt) {
//     this->_ingredients.erase(ingredient->name);
// }

void Fridge::takeIngredient(std::string const &name, size_t qt) {
    std::for_each(this->_ingredients.begin(), this->_ingredients.end(),
        [&name, &qt](Ingredient &ingredient) {
            if (ingredient.name == name) {
                ingredient.qt -= qt;
            }
        }
    );
}

bool Fridge::giveIngredients(std::vector<Ingredient> pizzaIngredients) {

    // very ugly and c-like i know i know but normally this function should get every ingrendients
    // ScopedLock lock(this->_mutex);

    if (!this->isEnoughIngredient(pizzaIngredients)) return false;


    // 0 -> fin(find_if)
    // for_each(
    //     list.begin(),
    //     list.find_if(
    //         list.begin(),
    //         list.end(),
    //         [&pizzaIngredient](Ingredient &ing){ return (pizzaIngredient.name == ing.name)}
    //     ),
    //     [](){}
    // );

    // for (Ingredient &fridgeIngredient : this->_ingredients) {

    std::for_each(
        pizzaIngredients.begin(),
        pizzaIngredients.end(),
        [&ingredients = this->_ingredients](Ingredient &pIng) -> void {
            --(*std::find_if(
                ingredients.begin(),
                ingredients.end(),
                [&pIng](Ingredient const &fIng) -> bool {return (fIng.name == pIng.name);}
            ));
        }
    );
    return true;
}

bool Fridge::isEnoughIngredient(std::vector<Ingredient> pizzaIngredients) {
    for (Ingredient &fridgeIngredient : this->_ingredients) {
        for (Ingredient &pizzaIngredient : pizzaIngredients) {
            if (fridgeIngredient.name == pizzaIngredient.name) {
                if (fridgeIngredient.qt < pizzaIngredient.qt)
                    return false;
                break;
            }
        }
    }
    return true;
}

void Fridge::refill() {
    std::for_each(this->_ingredients.begin(), this->_ingredients.end(),
        [](Ingredient &ingredient) {
            ingredient.qt += 1;
        }
    );
}

void Fridge::dump() {
    std::cout << "Ingredients inside the fridge:" << std::endl;
    std::for_each(this->_ingredients.begin(), this->_ingredients.end(),
        [](Ingredient const &ingredient) {
            std::cout << "\t" << ingredient.name << " x" << ingredient.qt << std::endl;
        }
    );
}

const std::stringstream &Fridge::getStatus() {
    this->_status.clear();

    std::for_each(this->_ingredients.begin(), this->_ingredients.end(),
        [this](Ingredient const &ingredient) {
            this->_status << ingredient.name << ":" << ingredient.qt << "\n";
        }
    );
    return (this->_status);
}

std::shared_ptr<std::mutex> &Fridge::getMutex() {
    return this->_mutex;
}
