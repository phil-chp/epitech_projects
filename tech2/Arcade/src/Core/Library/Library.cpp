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

#include "Core/Library/Library.hpp"

arc::core::Library::Library()
{
    // nothing to do
}

arc::core::Library::Library(std::string name)
{
    this->_name = name;
    this->_load(DEFAULT_LIB_PATH + name);
}

arc::core::Library::~Library()
{
    // nothing to do
}

const arc::core::Library &arc::core::Library::_load(std::string path)
{
    void *handle = dlopen(path.c_str(), RTLD_LAZY);
    if (handle == nullptr) {
        std::cerr << "Error: " << dlerror() << std::endl;
        exit(84);
    }
    this->_handle = handle;
    const Library &lib = *this;
    return (lib);
}
