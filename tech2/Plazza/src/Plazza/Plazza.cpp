/*
** EPITECH PROJECT, 2022
** Plazza (Workspace)
** File description:
** Plazza
*/

#include "Plazza.hpp"
std::string global___me = "";

Plazza::Plazza(int multiplier, int cooks, int ingredientDelay)
    : _multiplier(multiplier)
    , _cooks(cooks)
    , _ingredientDelay(ingredientDelay)
    , _reception(std::make_unique<Reception>())
    , _cManager(std::make_shared<ComManager>())
    , _kManager(std::make_unique<KitchenManager>(this->_cManager, cooks))
{ global___me = "Parent";}

//* -------------------------------- Public -------------------------------- *//

void Plazza::run()
{
    while (1) {
        std::vector<Response> &comms = this->_cManager->listen();

        if (comms.size() == 0) continue;
        if (comms[0].fd == STDIN) {
            this->_reception->setOrder((*comms.erase(comms.begin())).data);
            std::queue<Order> orders = this->_reception->getOrders();
            this->_kManager->addOrders(orders);
            try {
                this->_kManager->sendOrders();
            } catch (Errors const &e) {
                throw Errors(e.what());
            }
        }
        // for (Response &comm : comms) {
        // Response pas fd mais path
        // envoyer response au kManager
            // reduire la load des cuisines trouvées à partir du path
        // envoyer resposes a reception
            // valide les uniques ids des pizzas dans la commande
            // commande valide si valid_ids.size() == range
        // }
    }
}

//* -------------------------------- Private ------------------------------- *//
