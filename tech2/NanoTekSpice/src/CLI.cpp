/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** CLI
*/

#include "CLI.hpp"

nts::CLI::CLI(std::string const file) : _parser(file), _running(true)
{
    this->_initCommands();
    this->_chipsets = _parser.getChipsets();
    // this->_links = _parser.getLinks();
    this->_run();
}

nts::CLI::~CLI()
{
}

void nts::CLI::_initCommands()
{
    _commands["exit"]     = &nts::CLI::_exit;
    _commands["display"]  = &nts::CLI::_display;
    _commands["simulate"] = &nts::CLI::_simulate;
    _commands["loop"]     = &nts::CLI::_loop;
    _commands["dump"]     = &nts::CLI::_dump;
}

void nts::CLI::_run()
{
    std::string input;

    while (this->_running) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit")
            this->_exit();
        /* TODO:
        try {
            this->_commands[input](*this);

            if (std::cin.eof()) {
                TODO: throw ExceptionEOF
            }
        } catch (std::out_of_range& const e) {
           std::cerr << "Unknown command" << std::endl;
        } catch (nts::EOF const&) {
            this->_exit();
        }
        */

        _running = false;
    }
}

// -------------------------------------------------------------------------- //

void nts::CLI::_exit()
{
    this->_running = false;
}

void nts::CLI::_display() const
{

}

void nts::CLI::_simulate() const
{
    // (_tick++)
}

void nts::CLI::_loop() const
{

}

void nts::CLI::_dump() const
{

}
