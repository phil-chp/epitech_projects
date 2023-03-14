/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include "Components/ComponentFactory.hpp"
#include "IComponent.hpp"
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

namespace nts {
    class Parser {
        public:
            Parser(std::string const file);
            ~Parser();

            void parseFile(std::vector<std::string> lines);

            std::unordered_map<std::string, std::string> getChipsets() const;
            // std::unordered_map<std::string, nts::IComponent> getLinks() const;

        private:
            void _buildChipsets(std::string key, std::string value);
            void _buildLinks(std::string key, std::string value);

            void _linkPins(std::string key, std::string keyPin, std::string value, std::string valuePin);

            void _parseData(std::vector<std::string> &lines, std::string file) const;
            void _sanitizeData(std::string &data) const;

            void _checkDelimiters(std::vector<std::string> lines, size_t len) const;
            bool _splitValues(char delim, std::string &data, std::string &key, std::string &value) const;

            ComponentFactory _factory;

            std::unordered_map<std::string, std::string> _chipsets;
            std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _links;
    };
}

#endif /* !PARSER_HPP_ */
