/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** ClientManager
*/

#ifndef CLIENTMANAGER_HPP_
    #define CLIENTMANAGER_HPP_

    #include "Network/Protocol/ClientID.hpp"
    #include "Network/RType/NetworkInfos.hpp"
    #include "Network/Protocol/Constants.hpp"
    #include "Network/Boost.hpp"
    #include <algorithm>
    #include <iostream>
    #include <vector>
    #include <array>
    #include <stack>
    #include <map>

namespace net {

class ClientManager {
    public:
        ClientManager();
        ~ClientManager() = default;

        int addClient(const TCP::endpoint &endpoint);

        bool removeClient(int id);

        const ClientID &getClient(int id, int &err) const;
        const ClientID &getClient(const UDP::endpoint &endpoint, int &err) const;

        std::shared_ptr<net::rtype::ClientInfos> getData(int id, int &err) const;

        void setData(int id, const net::rtype::ClientInfos &data);
        void setDatas(net::rtype::ClientInfos &str);

        const std::vector<int> &getConnectedIds() const;

        int getClientCount() const;

    private:
        int _clientCount;

        std::array<ClientID, MAX_CLIENTS> _clients;
        std::array<net::rtype::ClientInfos, MAX_CLIENTS> _datas;
        std::vector<int> _usedIds;
        std::stack<int>  _freeIds;

};
}

#endif /* !CLIENTMANAGER_HPP_ */
