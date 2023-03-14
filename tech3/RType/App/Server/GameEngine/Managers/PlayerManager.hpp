/*
** EPITECH PROJECT, 2022
** RType
** File description:
** PlayerManager
*/

#ifndef PLAYERMANAGER_HPP_
#define PLAYERMANAGER_HPP_
    #include "GameEngine/Player.hpp"

namespace engine {
namespace rtype {


class PlayerManager {
    private:
        PlayerManager() {

            _players.push_back(std::make_shared<engine::rtype::ShipPlayer<0>>());
            _players.push_back(std::make_shared<engine::rtype::ShipPlayer<1>>());
            _players.push_back(std::make_shared<engine::rtype::ShipPlayer<2>>());
            _players.push_back(std::make_shared<engine::rtype::ShipPlayer<3>>());

        }
        ~PlayerManager() = default;

    public:
        static PlayerManager &getInstance()
        {
            static PlayerManager instance;
            return (instance);
        }

        bool checkLoose() {
            if (_players.size() == 0)
                return (true);
            return (false);
        }

        ecs::Entity getPlayer(unsigned int id) {
            return _players[id]->getEntity();
        }

        void removePlayer(unsigned int id) {
            if (_players.size() == 0) {
                return;
            }
            // std::cout << "player--" << std::endl;
            _players.erase(_players.begin() + id);
        }

        std::vector<std::shared_ptr<engine::Entity>> _players;

        // std::vector<
};
}
}

#endif /* !PLAYERMANAGER_HPP_ */
