/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** ComponentOutput
*/

#ifndef COMPONENTOUTPUT_HPP_
#define COMPONENTOUTPUT_HPP_

#include <iostream>
#include "Components/Component.hpp"

namespace nts {
    class ComponentOutput : public Component {
    public:
        ComponentOutput();
        ~ComponentOutput();

        void simulate(std::size_t tick ) override;
        Tristate compute(std::size_t pin) override;

        void dump() const override;
    };
}

#endif /* !COMPONENTOUTPUT_HPP_ */
