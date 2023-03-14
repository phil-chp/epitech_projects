/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** Library
*/

#ifndef LIBRARY_HPP_
# define LIBRARY_HPP_

# include "Shared/Arcade.hpp"
# include <dlfcn.h>
# include <iostream>
# include <exception>
# include <string.h>
# include <map>

namespace arc
{
    namespace core
    {
        class Library
        {
            public:
                Library();
                Library(std::string);
                ~Library();

                void *get() {
                    return (this->_handle);
                }
                std::string getName() const {
                    return (this->_name);
                }

            private:
                std::string _name;
                void *_handle;
                const Library &_load(std::string libName);
        };
    }
}

#endif /* !LIBRARY_HPP_ */
