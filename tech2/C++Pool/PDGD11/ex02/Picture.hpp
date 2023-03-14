/*
** EPITECH PROJECT, 2022
** PDG-D11 (Workspace)
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
# define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>

class Picture final {
    public:
        Picture() : data("") {};
        explicit Picture(std::string const& file) : data("") {
            getPictureFromFile(file);
        };
        virtual ~Picture();

        bool getPictureFromFile(std::string const& file);

        std::string data;
};

#endif /* !PICTURE_HPP_ */
