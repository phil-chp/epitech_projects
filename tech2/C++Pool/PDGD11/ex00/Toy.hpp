/*
** EPITECH PROJECT, 2022
** PDG-D11 (Workspace)
** File description:
** Toy
*/

#pragma once

#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };

        Toy();
        Toy(ToyType toyType, const std::string name, const std::string file);
        virtual ~Toy();

        ToyType     getType()  const;
        std::string getName()  const;
        std::string getAscii() const;

        void setName(const std::string &name);
        bool setAscii(const std::string &file);

    private:
        ToyType _toyType;
        std::string _name;
        Picture _picture;
};
