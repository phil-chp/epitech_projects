/*
** EPITECH PROJECT, 2022
** Arcade (Workspace) ADRIAN LE FRANCAIS
** File description:
** Switcher
*/

#include "Core/Switcher/Switcher.hpp"
#include "Core/Library/Library.hpp"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

/**
 * @brief Construct a new arc::core::Switcher::Switcher object
 *
 * @param gamePath
 * @param graphPath
 */
arc::core::Switcher::Switcher(std::string gamePath, std::string graphPath)
{
    this->_createRessources(DEFAULT_LIB_PATH);

    for (size_t i = 0; i < this->_ressources.size(); ++i) {
        this->_addLib(this->_ressources[i], this->_ressources[i]);
    }
    this->setLib(arc::GAME, gamePath);
    this->setLib(arc::GRAPH, graphPath);
}

/**
 * @brief Destroy the Switcher instance
 *
 */
arc::core::Switcher::~Switcher()
{
    // nothing to do
}

/**
 * @brief switch the context of current lib.
 *
 * @param type
 * @param libName
 */

void arc::core::Switcher::switchLib(arc::LibType type)
{
    std::shared_ptr<Library> lib = this->_currentLibs[type];

    if (lib == nullptr) {
        throw std::runtime_error("Current lib is broken");
    }

    // TODO: AUTO IS BANNED replace with the correct ::iterator
    for (auto it = this->_libs[type].begin(); it != this->_libs[type].end(); ++it) {
        if (it->first.substr(6) == lib->getName()) {
            if (++it == this->_libs[type].end()) {
                it = this->_libs[type].begin();
                return this->setLib(type, it->first);
            } else {
                return this->setLib(type, (it++)->first);
            }
        }
    }
}
// ***************************** IMPLEMENTATION ***************************** //

std::shared_ptr<arc::core::Library> arc::core::Switcher::_getLib(arc::LibType type, std::string libName)
{
    if (this->_libs[type][libName].get() == nullptr) {
        return nullptr;
    }
    return (this->_libs[type][libName]);
}

/**
 * @briefs
 *
 * @param name
 * @param path
 */
void arc::core::Switcher::_addLib(std::string name, std::string path)
{
    (void)path;
    std::shared_ptr<Library> lib = std::make_shared<Library>(name);

    try {
        std::unique_ptr<arc::IClass> (*__generateLib__)() = (std::unique_ptr<arc::IClass>(*)())dlsym(lib->get(), GET_UNIQUE_CLASS);
        std::unique_ptr<arc::IClass> classLib = __generateLib__();
        arc::LibType type = (arc::LibType)classLib->getSignature();
        this->_libs[type]["./lib/" + name] = lib;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * @brief create all ressources, all folders...
 *
 * @param path
 */
void arc::core::Switcher::_createRessources(std::string path)
{
    std::regex reg(".*\\.so$");
    std::string value;
    // recover all ".so" file in the path and put it in the vector ressources
    // TODO: AUTO IS BANNED replace with the correct ::iterator
    for (auto &p : std::filesystem::directory_iterator(path)) {
        if (std::regex_match(p.path().string(), reg)) {
            this->_ressources.push_back(p.path().filename().string());
        }
    }
}

std::shared_ptr<arc::core::Library> arc::core::Switcher::loadLib(arc::LibType type) { // rename methode
    return this->_currentLibs[type];
};

/* Implementation */

/**
 * @brief set the current library
 *
 * @param type
 * @param libPath
 */
void arc::core::Switcher::setLib(arc::LibType type, std::string libPath)
{
    std::shared_ptr<Library> lib = this->_getLib(type, libPath);

    if (lib == nullptr) {
        throw std::runtime_error("No library found");
    }
    this->_currentLibs[type] = lib;
}
