/*
** EPITECH PROJECT, 2022
** PDG-D11 (Workspace)
** File description:
** Toy
*/

#ifndef TOY_HPP_
# define TOY_HPP_

#include "Picture.hpp"
#include <iostream>

class Toy final {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };

        Toy() : _toy_type(BASIC_TOY), _name("toy"), _picture(Picture()) {};
        explicit Toy(Toy const& toy)
        {
            this->_toy_type = toy._toy_type;
            this->_name = toy._name;
            this->_picture = toy._picture;
        }
        Toy(ToyType toyType, std::string const& name, std::string const& file)
            : _toy_type(toyType)
            , _name(name)
            , _picture(Picture(file)) {};
        virtual ~Toy();

        Toy& operator=(Toy const& toy)
        {
            if (this != &toy) {
                this->_toy_type = toy._toy_type;
                this->_name = toy._name;
                this->_picture = toy._picture;
            }
            return (*this);
        }

        ToyType getType() const
        {
            return this->_toy_type;
        }
        std::string getName() const
        {
            return this->_name;
        }
        std::string getAscii() const
        {
            return this->_picture.data;
        }

        void setName(std::string const& name)
        {
            this->_name = name;
        }
        bool setAscii(std::string const& file)
        {
            this->_picture.getPictureFromFile(file);
            return (this->_picture.data != "ERROR");
        }

    private:
        ToyType _toy_type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
