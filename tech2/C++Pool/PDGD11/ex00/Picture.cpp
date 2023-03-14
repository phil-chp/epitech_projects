/*
** EPITECH PROJECT, 2022
** PDG-D11 (Workspace)
** File description:
** Picture
*/

#include "Picture.hpp"

// ------------------------------ Subroutines ------------------------------- //

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string &file) : data("")
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

// -------------------------------- Methods --------------------------------- //

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ostringstream ss;
    std::fstream fs;

    fs.open(file, std::ios::in);
    if (!fs.is_open()) {
        data = "ERROR";
        return (false);
    }
    ss << fs.rdbuf();
    data = ss.str();
    fs.close();
    return (true);
}
