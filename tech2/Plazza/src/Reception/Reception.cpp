/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Reception
*/

#include "Reception.hpp"

Reception::Reception()
    : _menu(pizza::defaultMenu)
    , _inventory(pizza::defaultFridge)
    , _pizzaMaxId(0)
    , _commandMaxId(0)
{
    // this->_kManager = std::make_unique<KitchenManager>();
}

//* -------------------------------- Public -------------------------------- *//

// void Reception::run()
// {
//     std::vector<Order> orders;
//     std::string userInput;

//     while (1) {
//         std::getline(std::cin, userInput);
//         if (userInput == "exit") break;
//         else if (userInput == "status") std::cout << "status\n";
//         else if (userInput != "")  {
//             orders = this->_getOrder(userInput);
//             if (orders.size() == 0) continue;

//             //! DEBUG --------------------------- //
//             for (Order order : orders) order.dump();
//             //! DEBUG --------------------------- //

//         }
//     }
// }


std::queue<Order> const &Reception::getOrders() const {
    return (this->_orders);
}

void Reception::setOrder(std::string const &userInput)
{
    std::stringstream ssOrder(userInput);
    std::vector<std::string> command;

    if (userInput.find(";") != std::string::npos) {
        std::string segment;
        while (std::getline(ssOrder, segment, ';')) {
            ToolBox::ltrim(segment);
            command.push_back(segment);
        }
    } else {
        command.push_back(userInput);
    }
    this->_parseOrder(command);
}

//* -------------------------------- Private ------------------------------- *//

void Reception::_parseOrder(std::vector<std::string> const &commands)
{
    std::vector<Order> tmp;
    for (std::string command : commands) {
        try {
            tmp.push_back(Order(command));
        } catch (const std::exception& e) {
            ReceptionError(e.what());
            tmp.clear();
        }
    }
    for (Order &ord : tmp) {
        ord.pizzaId = this->_pizzaMaxId;
        this->_pizzaMaxId += ord.qt;
        ord.commandId = this->_commandMaxId;
        this->_commandMaxId++;
        this->_orders.push(ord);
    }
}
