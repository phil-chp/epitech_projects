/*
** EPITECH PROJECT, 2022
** PDG-D11 (Workspace)
** File description:
** Picture
*/

#include "Picture.hpp"

// ------------------------------ Subroutines ------------------------------- //

Picture::~Picture()
{
}

// -------------------------------- Methods --------------------------------- //

bool Picture::getPictureFromFile(std::string const& file)
{
    std::ostringstream ss;
    std::fstream fs;

    fs.open(file, std::ios::in);
    if (!fs.is_open()) {
        this->data = "ERROR";
        return false;
    }
    ss << fs.rdbuf();
    this->data = ss.str();
    fs.close();
    return true;
}
