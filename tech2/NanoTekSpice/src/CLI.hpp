/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** CLI
*/

#ifndef CLI_HPP_
#define CLI_HPP_

#include <iostream>
#include <unordered_map>
#include "IComponent.hpp"
#include "Parser.hpp"

namespace nts {
    class CLI {
        public:
            CLI(std::string const file);
            ~CLI();

        private:
            void _exit();
            void _display() const;
            void _simulate() const;
            void _loop() const;
            void _dump() const;

            // nts::Tristate _compute(std::size_t pin);
            // void _setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin);

            void _run();
            void _initCommands();

            Parser _parser;
            bool _running;

            std::unordered_map<std::string, std::function<void(CLI &)>> _commands;

            std::unordered_map<std::string, std::string> _chipsets;
            // std::unordered_map<std::string, std::unique_ptr<IComponent>> _links;
    };
}

#endif /* !CLI_HPP_ */
