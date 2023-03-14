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
            std::string const &component = "IndieStudio"
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

class ECSError : public Errors
{
    public:
        explicit ECSError(
            std::string const &message,
            std::string const &component = "ECS"
        )
            : Errors(message, component)
        {}
};

class RayLibError : public Errors
{
    public:
        explicit RayLibError(
            std::string const &message,
            std::string const &component = "RayLib"
        )
            : Errors(message, component)
        {}
};

class NoiseError : public Errors
{
    public:
        explicit NoiseError(
            std::string const &message,
            std::string const &component = "Noise"
        )
            : Errors(message, component)
        {}
};


#endif /* !ERRORS_HPP_ */
