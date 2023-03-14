/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** NetworkManager
*/

#ifndef NETWORKMANAGER_HPP_
    #define NETWORKMANAGER_HPP_

    #include "Network/RType/Client.hpp"

namespace engine {

class NetworkManager {
    private:
        NetworkManager(const std::string &host, const std::string &port)
            : _client(std::make_shared<net::rtype::Client>(host, port))
        {};
        ~NetworkManager() = default;

    public:
        static NetworkManager &getInstance(const std::string &host = "0", const std::string &port = "0") {
            static NetworkManager instance(host, port);
            return (instance);
        }

        NetworkManager(const NetworkManager&) = delete;
        NetworkManager &operator=(const NetworkManager&) = delete;

        void send(net::rtype::ClientInfos &infos) {
            this->_client->send(infos);
        }

        net::rtype::ServerInfos receive() {
            return (this->_client->receive());
        }

        int getId() {
            return (this->_client->getId());
        }

        bool isOnline() {
            return (this->_client->getId() != 0);
        }

    private:
        std::shared_ptr<net::rtype::Client> _client;
};

} // namespace engine

#endif /* !NETWORKMANAGER_HPP_ */
