/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** Component
*/

#include "Components/Component.hpp"

nts::Component::Component()
{
    std::cout << "   Generic component created" << std::endl;
    this->setUnusedPin();
}

nts::Component::~Component()
{
}

void nts::Component::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    (void)pin;
    return nts::UNDEFINED;
}

void nts::Component::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin)
{
    if (pin > this->pins.size()) {
        //! TODO: ERROR pin out of range
    }
    if (this->pins[pin].used == false) {
        //! TODO: ERROR invalid pin
    }
    if (this->pins[pin].linked_component != nullptr && this->pins[pin].linked_pin != (size_t)-1) {
        return;
    }
    std::cout << "Linking: ";
    this->dump();
    std::cout << " : " << pin << " with ";
    other.dump();
    std::cout << " : " << otherPin << "\n" << std::endl;
    this->pins[pin].linked_component = &other;
    this->pins[pin].linked_pin = otherPin;
    other.setLink(otherPin, *this, pin);
}

void nts::Component::dump() const
{
}

void nts::Component::setPin()
{
    this->pins.push_back((Pin){nts::UNDEFINED, true, nullptr, (size_t)-1});
}

void nts::Component::setUnusedPin()
{
    this->pins.push_back((Pin){UNDEFINED, false, nullptr, (size_t)-1});
}
