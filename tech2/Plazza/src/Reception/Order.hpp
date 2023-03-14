/*
** EPITECH PROJECT, 2022
** B-CCP-400-NCE-4-1-theplazza-ciro.autiero
** File description:
** Order
*/

#ifndef ORDER_HPP_
    #define ORDER_HPP_

    #include "Utils/Pizza.hpp"
    #include "Utils/ToolBox.hpp"
    #include <vector>
    #include <sstream>

class Order {
    public:
        explicit Order(std::string &order);
        ~Order() = default;

        void dump();

        pizza::Type getTypeValue() const { return (this->_typeValue); }
        std::string getType() const      { return (this->_type);      }
        pizza::Size getSizeValue() const { return (this->_sizeValue); }
        std::string getSize() const      { return (this->_size);      }
        size_t getQt() const             { return (this->qt);         }

        void operator--(void) {
            --(this->qt);
        }

        void setType(std::string const &type);
        void setSize(std::string const &size);
        void setQuantity(std::string &qt);

        size_t pizzaId;
        size_t commandId;
        size_t qt;

    private:
        pizza::Type _typeValue;
        std::string _type;
        pizza::Size _sizeValue;
        std::string _size;

};
#endif /* !ORDER_HPP_ */
