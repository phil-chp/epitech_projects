/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** ComponentInput
*/

#ifndef COMPONENTINPUT_HPP_
#define COMPONENTINPUT_HPP_

#include <iostream>
#include "Components/Component.hpp"

namespace nts {
    class ComponentInput : public Component {
    public:
        ComponentInput();
        ~ComponentInput();

        void simulate(std::size_t tick ) override;
        Tristate compute(std::size_t pin) override;

        void dump() const override;
    };
}

#endif /* !COMPONENTINPUT_HPP_ */
