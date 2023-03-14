/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include "Kitchen/Fridge.hpp"
    #include "Utils/ToolBox.hpp"
    #include <iostream>
    #include <map>

class Kitchen {
    public:
        Kitchen();
        ~Kitchen();

        void (Kitchen::*handler)();

    private:
        void _parentHandler();
        void _childHandler();
        void sendOrder();
        std::string getKitchenInfoToString();

        pid_t _pid;
        //std::array<Cook, nbCook> _cook;
        Fridge fridge;
};


#endif /* !KITCHEN_HPP_ */
