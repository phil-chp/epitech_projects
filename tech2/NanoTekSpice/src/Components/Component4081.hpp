/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include <iostream>
#include "Components/Component.hpp"

namespace nts {
    class Component4081 : public Component {
    public:
        Component4081();
        ~Component4081();

        void simulate(std::size_t tick ) override;
        Tristate compute(std::size_t pin) override;

        void dump() const override;
    };
}

#endif /* !COMPONENT4081_HPP_ */
