/*
** EPITECH PROJECT, 2022
** Arcade (Workspace)
** File description:
** Switcher
*/

#ifndef SWITCHER_HPP_
# define SWITCHER_HPP_

# include "Core/Library/Library.hpp"
# include "Shared/Arcade.hpp"
# include "Graph/IGraph.hpp"
# include "Game/IGame.hpp"
# include <memory>
# include <filesystem>
# include <iostream>
# include <exception>
# include <regex>

namespace arc
{
    namespace core
    {
# define LIBS_SIZE(type)  this->_libs[type].size()
        class Switcher
        {
            public:
                Switcher(std::string gamePath, std::string graphPath);
                ~Switcher();

                void switchLib(arc::LibType type);
                std::shared_ptr<Library> loadLib(arc::LibType type);
                void setLib(arc::LibType, std::string);

            private:
                void _createRessources(std::string);
                std::shared_ptr<arc::core::Library> _getLib(arc::LibType type, std::string libName);
                void _addLib(std::string folderName, std::string libName);

                std::map<arc::LibType, std::shared_ptr<Library>> _currentLibs;

                std::vector<std::string> _ressources;
                std::map<arc::LibType, std::map<std::string, std::shared_ptr<Library> > > _libs;
        };
    }
}

#endif /* !SWITCHER_HPP_ */
