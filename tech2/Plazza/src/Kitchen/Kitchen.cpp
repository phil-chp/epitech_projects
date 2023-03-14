/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen()
{
    this->_pid = ToolBox::fork();

    if (this->_pid == 0) {
        this->handler = &Kitchen::_childHandler;
    } else {
        this->handler = &Kitchen::_parentHandler;
    }
}

Kitchen::~Kitchen()
{
    std::cout << "Kitchen destroyed" << std::endl;
}

//* -------------------------------- Public -------------------------------- *//

//* -------------------------------- Private ------------------------------- *//

void Kitchen::_childHandler() {
    //le fork est pas au bon endroit :)   <--------------
}

void Kitchen::_parentHandler() {
    // communicate with child
    // and reception :) :)
}

void Kitchen::sendOrder() {

}

std::string Kitchen::getKitchenInfoToString() {
    std::string fridgeStatus = fridge.getStatus().str() + "\n";
    std::string cookStatus;
    // when the cook are in place we just get the value and get them
    //for (auto &cook : this->_cooks) {
    //    kitchenStatus += cook.getStatus() + "\n";
    //}
    return (fridgeStatus + cookStatus);
}
