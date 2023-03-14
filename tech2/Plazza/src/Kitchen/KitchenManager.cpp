/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Area di lavoro)
** File description:
** KitchenManager
*/

#include "KitchenManager.hpp"
extern std::string global___me;

KitchenManager::KitchenManager(std::shared_ptr<ComManager> cManager, size_t cooks)
    : _totalLoad(0)
    , _kitchenCount(0)
    , _maxLoad(0)
    , _nbCooks(cooks)
    , _kitchenMaxId(0)
    , _cManager(cManager)
{}

KitchenManager::~KitchenManager() {}

//* -------------------------------- Public -------------------------------- *//

void KitchenManager::addOrders(std::queue<Order> &orders)
{
    while (!orders.empty()) {
        this->_orders.push(orders.front());
        orders.pop();
    }
}

void KitchenManager::sendOrders(void)
{
    static short failedFork = 0;

    while (this->_totalLoad < this->_maxLoad && !this->_orders.empty()) {
        std::vector<KitchenData>::iterator data = std::find_if(
            this->_data.begin(), this->_data.end(),
            [](KitchenData const &data) {
                return (data.load < data.loadMax);
            }
        );
        this->_sendTo(*data);
        if (this->_orders.front().qt == 0) {
            this->_orders.pop();
        }
    }
    if (!this->_orders.empty()) {
        try {
            this->_newKitchen();//kill child
            failedFork = 0;
        } catch (KitchenError const &e) {
            if (failedFork >= 5) {
                throw KitchenError("fatal error, couldn't fork");
            }
            std::cerr << "Fork Error NB "<< std::to_string(++failedFork) << std::endl;
        }
        // TODO: check if throw is needed.
        this->sendOrders();
    }
}

//* -------------------------------- Private ------------------------------- *//

void KitchenManager::_newKitchen(void)
{
    std::string path = "/tmp/kitchen-" + (this->_kitchenMaxId++);
    pid_t pid;

    try {
        this->_cManager->addKitchen(path);
    } catch (ComError const &e) {
        throw KitchenError(e.what());
    }
    try {
        pid = ToolBox::fork();
    } catch (const std::exception &e) {
        this->_cManager->removeKitchen(path);
        throw KitchenError(e.what());
    }
    if (pid == 0) {
        global___me = "child";
        //Kitchen()
        exit(0);
        //Kitchen.run();
    } else {
        this->_data.push_back(
            KitchenData(path, this->_kitchenMaxId, this->_nbCooks)
        );
        this->_kitchenCount++;
        this->_kitchenMaxId++;
        this->_maxLoad += (this->_nbCooks * 2);
    }
}

// void KitchenManager::_killKitchen(pid_t const pid)
// {
//     (void)std::remove_if(this->_fds.begin(), this->_fds.end(),
//         [&](pid_t const i) {
//             return i == pid;
//         }
//
//     );
// }

void KitchenManager::_sendTo(KitchenData &data) {

    Order &ord(this->_orders.front());
    size_t qt = ToolBox::getMin(data.loadMax - data.load, ord.qt);

    try {
        this->_cManager->send(data.path, ord, qt);
    } catch (KitchenError const &e) {
        Errors::printError(e.what());
        return;
    }
    data.load += qt;
    this->_totalLoad += qt;
}
