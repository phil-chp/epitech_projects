/*
** EPITECH PROJECT, 2022
** indie (Espace de travail)
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

// Error
// ParsingError

    #include <iostream>
    #include <string>

namespace rl {
    class Error : public std::exception {
        public:
            explicit Error(std::string const &message,
                            std::string const &component = "Raylib")
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

    class ParsingError : public Error
    {
        public:
            explicit ParsingError(
                std::string const &message,
                std::string const &component = "ParsingError"
            )
                : Error(message, component)
            {}
    };
}



#endif /* !ERROR_HPP_ */
