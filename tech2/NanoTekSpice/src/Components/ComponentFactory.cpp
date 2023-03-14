/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory()
{
}

nts::ComponentFactory::~ComponentFactory()
{
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(std::string const &chipset)
{
    if (chipset == "input")  return _CreateInput();
    if (chipset == "output") return _CreateOutput();

    // if (chipset == "true")   return _CreateTrue();
    // if (chipset == "false")  return _CreateFalse();

    // if (chipset == "clock")  return _CreateClock();
    // if (chipset == "logger") return _CreateLogger();

    if (chipset == "4081")   return _Create4081();
    // if (chipset == "4071")   return _Create4071();
    // if (chipset == "4011")   return _Create4011();
    // if (chipset == "4001")   return _Create4001();
    // if (chipset == "4030")   return _Create4030();
    // if (chipset == "4069")   return _Create4069();
    // if (chipset == "4514")   return _Create4514();
    // if (chipset == "4008")   return _Create4008();
    // if (chipset == "4040")   return _Create4040();
    // if (chipset == "4017")   return _Create4017();
    // if (chipset == "4094")   return _Create4094();
    // if (chipset == "4013")   return _Create4013();
    // if (chipset == "4512")   return _Create4512();
    // if (chipset == "4801")   return _Create4801();
    // if (chipset == "2716")   return _Create2716();
    //! TODO: ERROR "Unkown chipset given: " << chipset
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::_CreateInput() const
{
    return std::make_unique<ComponentInput>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::_CreateOutput() const
{
    return std::make_unique<ComponentOutput>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4081() const
{
    return std::make_unique<Component4081>();
}

// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4071() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4011() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4001() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4030() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4069() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4514() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4008() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4040() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4017() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4094() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4013() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4512() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create4801() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_Create2716() const {}

// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_CreateTrue() const {}
// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_CreateFalse() const {}

// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_CreateClock() const {}

// std::unique_ptr<nts::IComponent> nts::ComponentFactory::_CreateLogger() const {}
