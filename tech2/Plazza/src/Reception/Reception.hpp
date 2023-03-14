/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

    #include "Utils/Pizza.hpp"
    #include "Reception/Order.hpp"
    #include "Com/ComManager.hpp"
    #include <sstream>
    #include <queue>
    #include <mutex>
    #include <thread>

class Reception {
    public:
        Reception();
        ~Reception() = default;

        void run();
        std::queue<Order> const &getOrders() const;
        void setOrder(std::string const &order);

    private:
        void _parseOrder(std::vector<std::string> const &commands);

        std::vector<std::string> _menu;
        std::vector<std::string> _inventory;
        std::queue<Order> _orders;
        size_t _pizzaMaxId;
        size_t _commandMaxId;
};

#endif /* !RECEPTION_HPP_ */
