/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
# define ICOMPONENT_HPP_

# include <iostream>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE      = true,
        FALSE     = false
    };

    class IComponent {
    public :
        virtual ~IComponent() = default;

        virtual void simulate(std::size_t tick ) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;

        virtual void dump() const = 0;
    };
}

#endif /* ICOMPONENT_HPP_ */
