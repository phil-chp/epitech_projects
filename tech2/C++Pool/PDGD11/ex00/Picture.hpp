/*
** EPITECH PROJECT, 2022
** PDG-D11 (Workspace)
** File description:
** Picture
*/

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class Picture {
    public:
        Picture(const std::string &file);
        Picture();
        virtual ~Picture();

        bool getPictureFromFile(const std::string &file);

        std::string data;
};
