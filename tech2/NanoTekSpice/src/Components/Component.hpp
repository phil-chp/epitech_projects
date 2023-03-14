/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "IComponent.hpp"
#include <vector>

namespace nts {
    typedef struct {
        Tristate state;
        bool used;
        IComponent *linked_component;
        size_t linked_pin;
    } Pin;

    #define Pins std::vector<Pin>

    class Component : public IComponent {
    public:
        Component();
        virtual ~Component();

        virtual void simulate(std::size_t tick) override;
        virtual Tristate compute(std::size_t pin) override;
        void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) override;

        virtual void dump() const override;


    protected:
        void setPin();
        void setUnusedPin();

        Pins pins;
    };
}

#endif /* !COMPONENT_HPP_ */
