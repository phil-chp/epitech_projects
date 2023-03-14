/*
** EPITECH PROJECT, 2022
** NanoTekSpice (Workspace)
** File description:
** Parser
*/

#include "Parser.hpp"

nts::Parser::Parser(std::string const file)
{
    std::vector<std::string> lines;

    if (file.length() == 0) {
        // "USAGE\n\t./nanotekspice <filepath>"
        //! TODO: ERROR No file given
    }
    this->_parseData(lines, file);
    this->parseFile(lines);
}

nts::Parser::~Parser()
{
}

// -------------------------------------------------------------------------- //

void nts::Parser::parseFile(std::vector<std::string> lines)
{
    size_t len(lines.size());

    _checkDelimiters(lines, len);
    for (size_t i = 0; i < len; ++i) {
        std::string key;
        std::string value;

        if (_splitValues(' ', lines[i], key, value) == true) continue;
        if (key.find(':') == std::string::npos) {
            _buildChipsets(key, value);
        } else {
            _buildLinks(key, value);
        }
    }
}

std::unordered_map<std::string, std::string> nts::Parser::getChipsets() const
{
    return this->_chipsets;
}

// std::unordered_map<std::string, nts::IComponent &> nts::Parser::getLinks() const
// {
//     return this->_links;
// }

// -------------------------------------------------------------------------- //

void nts::Parser::_buildChipsets(std::string const key, std::string const value)
{
    this->_chipsets[value] = key;
}

void nts::Parser::_buildLinks(std::string key, std::string value)
{
    std::string keyPin;
    std::string valuePin;

    _splitValues(':', key,   key,   keyPin);
    _splitValues(':', value, value, valuePin);
    if (this->_links.find(key)   == this->_links.end()
    ||  this->_links.find(value) == this->_links.end()) {
        //! TODO: ERROR Same name given to two or more chipsets
    }
    this->_links[key]   = _factory.createComponent(this->_chipsets[key]);
    this->_links[value] = _factory.createComponent(this->_chipsets[value]);
    _linkPins(key, keyPin, value, valuePin);
}

void nts::Parser::_linkPins(std::string key, std::string keyPin, std::string value, std::string valuePin)
{
    size_t keyPinI = 0;
    size_t valuePinI = 0;

    try {
        keyPinI = std::stoi(keyPin);
        valuePinI = std::stoi(valuePin);
    } catch (std::logic_error&) {
        //! TODO: ERROR non numerical pin
        return;
    }
    nts::IComponent *component(this->_links[value].get());
    this->_links[key]->setLink(keyPinI, *component, valuePinI);
}

// -------------------------------------------------------------------------- //

bool nts::Parser::_splitValues(char delim, std::string &data, std::string &key, std::string &value) const
{
    std::stringstream ss(data);

    std::getline(ss, key, delim);
    std::getline(ss, value);
    return (value.length() == 0);
}

void nts::Parser::_checkDelimiters(std::vector<std::string> lines, size_t len) const
{
    size_t delimitersFound = 0;

    for (size_t i = 0; delimitersFound < 2 && i < len; ++i) {
        if (lines[i].find(".chipsets:") != std::string::npos  \
        ||  lines[i].find(".links:")    != std::string::npos) {
            ++delimitersFound;
        }
    }
    if (delimitersFound != 2) {
        //! TODO: ERROR Missing delimitors in .nts file
    }
}

void nts::Parser::_parseData(std::vector<std::string> &lines, std::string file) const
{
    std::ostringstream oss;
    std::string line;
    std::string data;
    std::fstream fs;

    fs.open(file, std::ios::in);
    if (!fs.is_open()) {
        //! TODO: ERROR couldn't open file
    }
    oss << fs.rdbuf();
    fs.close();
    data = oss.str();

    this->_sanitizeData(data);

    std::stringstream ss(data);
    while (getline(ss, line, '\n')) {
        lines.push_back(line);
    }
}

void nts::Parser::_sanitizeData(std::string &data) const
{
    data = std::regex_replace(data, std::regex("(\\s+)?#.*\n(\n)?"), "");
    data = std::regex_replace(data, std::regex("\t"), " ");
    data = std::regex_replace(data, std::regex("\n(\\s+)?\n"), "\n");
    data = std::regex_replace(data, std::regex("(..*:)\\s+\n"), "$1\n");
}
