/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

    #include "Utils/ToolBox.hpp"
    #include "Com/ComManager.hpp"
    #include "NamedPipe/NamedPipe.hpp"
    #include "Reception/Order.hpp"
    #include <iostream>
    #include <vector>
    #include <memory>
    #include <queue>

struct KitchenData {
    KitchenData(std::string const &path, size_t id, size_t maxCooks)
        : path(path)
        , id(id)
        , maxCook(maxCooks)
        , load(0)
        , loadMax(2 * maxCooks)
    {}

    std::string path;
    size_t id;
    size_t maxCook;
    size_t load;
    size_t loadMax;
};

class KitchenManager {
    public:
        explicit KitchenManager(std::shared_ptr<ComManager> cManager, size_t cooks);
        ~KitchenManager();

        std::vector<KitchenData> const &getBuffer() const {
            return (this->_data);
        }
        size_t getKitchenCount() const {
            return (this->_kitchenCount);
        }

        void addOrders(std::queue<Order> &orders);
        void sendOrders(void);

    private:
        void _newKitchen(void);
        // void _killKitchen(pid_t const pid);
        void _sendTo(KitchenData &data);

        size_t _totalLoad;
        size_t _kitchenCount;
        size_t _maxLoad;
        size_t _nbCooks;
        size_t _kitchenMaxId;

        std::shared_ptr<ComManager> _cManager;
        std::vector<KitchenData> _data;
        std::queue<Order> _orders;
};

#endif /* !KITCHEN_HPP_ */
