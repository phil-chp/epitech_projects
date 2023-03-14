/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Cook
*/

#include "Cook.hpp"

// good luck guys im sorry as fuck

Cook::Cook(int cookingTime, std::shared_ptr<Fridge> &fridge)
{
    this->_multiCookTime = cookingTime;
    this->_isCooking = SLEEP;
    this->_cookingTime[0] = 0;
    this->_cookingTime[1] = 0;

    this->_fridge = fridge;
}

void Cook::cook(IMeal const &pizza) {
    while (!this->_fridge.giveIngredients(pizza.getIngredient())) {} // loop until they can do the pizza

    // when he got the ingredient start time

    this->startClock(pizza);
}

void Cook::startClock(IMeal const &pizza) {
    bool index = false;
    if (this->_cookingTime[index] == 0) index = true;

    this->_cookingTime[index] = 69 // start time
}

Tristate const &Cook::getIsCooking() {
    return this->_isCooking; // to let know the state of the cooker lol
}


Cook::~Cook()
{
}
