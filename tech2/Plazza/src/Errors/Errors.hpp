/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
    #define ERRORS_HPP_

    #include <iostream>
    #include <string>

class Errors : public std::exception {
    public:
        explicit Errors(
            std::string const &message,
            std::string const &component = "Plazza"
        )
            : _message("\e[31m" + message + "\e[39m")
        {
            (void)component;
        }

        char const *what() const throw() {
            return this->_message.c_str();
        }

        static void printError(std::string const &message) {
            std::cerr << "\e[31m" + message + "\e[39m" << std::endl;
        }

    private:
        std::string _message;
};

class ComError : public Errors
{
    public:
        explicit ComError(
            std::string const &message,
            std::string const &component = "Communication Manager"
        )
            : Errors(message, component)
        {}
};

class KitchenError : public Errors
{
    public:
        explicit KitchenError(
            std::string const &message,
            std::string const &component = "Kitchen Manager"
        )
            : Errors(message, component)
        {}
};

class IPCError : public Errors
{
    public:
        explicit IPCError(
            std::string const &message,
            std::string const &component = "NamedPipe"
        )
            : Errors(message, component)
        {}
};

class ReceptionError : public Errors
{
    public:
        explicit ReceptionError(
            std::string const &message,
            std::string const &component = "Reception"
        )
            : Errors(message, component)
        {}
};

#endif /* !ERRORS_HPP_ */
