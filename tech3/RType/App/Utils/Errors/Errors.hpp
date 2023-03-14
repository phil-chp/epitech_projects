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
            std::string const &component
        )
            : _message(
                "\e[31;1m" + (component.length() > 0
                    ? "[" + component + "]\e[0m\e[31m: "
                    : "[IndieStudio]\e[0m\e[31m: ")
                + message + "\e[39m"
            )
        {}

        char const *what() const throw() {
            return this->_message.c_str();
        }

        void setMessage(std::string const &message) {
            this->_message = message;
        }
        void setLocation(const char *func, const char *file, int line) {
            this->_location = "From: " + std::string(func) + "(" + file + ":" + std::to_string(line) + ")";
        }
        // static void printError(std::string const &message) {
        //     std::cerr << "\e[31m" + message + "\e[39m" << std::endl;
        // }

    private:
        std::string _message;
        std::string _location;
};

class ECSError : public Errors
{
    public:
        explicit ECSError(
            std::string const &message = "",
            std::string const &component = "ECS"
        )
            : Errors(message, component)
        {}
};

class GraphicsError : public Errors
{
    public:
        explicit GraphicsError(
            std::string const &message = "",
            std::string const &component = "Graphics"
        )
            : Errors(message, component)
        {}
};

class NetworkError : public Errors
{
    public:
        explicit NetworkError(
            std::string const &message = "",
            std::string const &component = "Network"
        )
            : Errors(message, component)
        {}
};

#define THROW_EXCEPTION(TE, message)                  \
    {                                                 \
        TE e;                                         \
        e.setMessage(message);                        \
        e.setLocation(__func__, __FILE__, __LINE__);  \
        throw e;                                      \
    }

// THROW_EXCEPTION(NetworkError, error.message())

#endif /* !ERRORS_HPP_ */
