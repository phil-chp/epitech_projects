/*
** EPITECH PROJECT, 2022
** B-CCP-400-NCE-4-1-theplazza-ciro.autiero
** File description:
** Order
*/

#include "Order.hpp"

Order::Order(std::string &order)
    : pizzaId(-1), commandId(-1)
{
    std::vector<std::string> infos;
    std::stringstream ssOrder(order);
    std::string info;

    if (order.find(" ") != std::string::npos) {
        while (std::getline(ssOrder, info, ' ')) {
            ToolBox::ltrim(info);
            infos.push_back(info);
        }
    }
    if (infos.size() != 3) {
        throw ReceptionError("Bad order format.", "Order");
    }
    this->setType(infos[0]);
    this->setSize(infos[1]);
    this->setQuantity(infos[2]);
}

//* -------------------------------- Public -------------------------------- *//

void Order::dump()
{
    std::cout << "type: " << this->getType()
        << "\tsize: " << this->getSize()
        << "\tqt: " << this->getQt() << std::endl;
}

void Order::setType(std::string const &type)
{
    this->_type = type;
    if (pizza::typeMap.find(type) != pizza::typeMap.end()) {
        this->_typeValue = pizza::typeMap.at(type);
    } else {
        throw ReceptionError("Pizza type not found", "Order");
    }
}

void Order::setSize(std::string const &size)
{
    this->_size = size;
    if (pizza::sizeMap.find(size) != pizza::sizeMap.end()) {
        this->_sizeValue = pizza::sizeMap.at(size);
    } else {
        throw ReceptionError("Pizza size not found", "Order");
    }
}

void Order::setQuantity(std::string &qt)
{
    try {
        this->qt = std::stoi(qt.erase(0, 1));
        if (this->qt < 1) throw this->qt;
    } catch (const std::exception& e) {
        throw ReceptionError("Invalid pizza quantity", "Order");
    }
}

//* -------------------------------- Private ------------------------------- *//
