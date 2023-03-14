/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** ComponentFactory
*/

#ifndef COMPONENT_FACTORY_HPP_
# define COMPONENT_FACTORY_HPP_

# include "Components/ComponentInput.hpp"
# include "Components/ComponentOutput.hpp"

# include "Components/Component4081.hpp"

# include <unordered_map>
# include <iostream>
# include <memory>
# include <any>

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory();

            std::unique_ptr<IComponent> createComponent(std::string const &chipset);

        private:
            std::unique_ptr<IComponent> _CreateInput() const;
            std::unique_ptr<IComponent> _CreateOutput() const;

            std::unique_ptr<IComponent> _Create4081() const;
            // std::unique_ptr<IComponent> _Create4071() const;
            // std::unique_ptr<IComponent> _Create4011() const;
            // std::unique_ptr<IComponent> _Create4001() const;
            // std::unique_ptr<IComponent> _Create4030() const;
            // std::unique_ptr<IComponent> _Create4069() const;
            // std::unique_ptr<IComponent> _Create4514() const;
            // std::unique_ptr<IComponent> _Create4008() const;
            // std::unique_ptr<IComponent> _Create4040() const;
            // std::unique_ptr<IComponent> _Create4017() const;
            // std::unique_ptr<IComponent> _Create4094() const;
            // std::unique_ptr<IComponent> _Create4013() const;
            // std::unique_ptr<IComponent> _Create4512() const;
            // std::unique_ptr<IComponent> _Create4801() const;
            // std::unique_ptr<IComponent> _Create2716() const;

            // std::unique_ptr<IComponent> _CreateTrue() const;
            // std::unique_ptr<IComponent> _CreateFalse() const;

            // std::unique_ptr<IComponent> _CreateClock() const;

            // std::unique_ptr<IComponent> _CreateLogger() const;
    };
}

#endif /* !COMPONENT_FACTORY_HPP_ */
