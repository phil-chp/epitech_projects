/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** ClientManager
*/

#include "ClientManager.hpp"

net::ClientManager::ClientManager()
    : _clientCount(0)
{
    net::rtype::ClientInfos client;
    this->_datas.fill(client);
    for (int id = MAX_CLIENTS - 1; id >= 0; --id) {
        this->_freeIds.push(id);
    }
}

//* -------------------------------- Public -------------------------------- *//

int net::ClientManager::addClient(const TCP::endpoint &endpoint)
{
    std::cout << ">>> Client Manager: ADDING CLIENT" << std::endl;
    if (this->_clientCount >= MAX_CLIENTS) return (-1);
    int id = this->_freeIds.top();
    ClientID client(endpoint, id);

    this->_clients[id] = client;
    std::cout << "New client has id: " << this->_clients[id].id << std::endl;
    this->_usedIds.push_back(id);
    this->_freeIds.pop();
    ++(this->_clientCount);
    return (id);
}

bool net::ClientManager::removeClient(int id)
{
    if (this->_clientCount == 0) return (false);
    ClientID emptyClient;

    this->_clients[id] = emptyClient;
    this->_usedIds.erase(
        std::remove(this->_usedIds.begin(), this->_usedIds.end(), id),
        this->_usedIds.end()
    );
    this->_freeIds.push(id);
    --(this->_clientCount);
    return (true);
}

const net::ClientID &net::ClientManager::getClient(int id, int &err) const
{
    if (std::find(this->_usedIds.begin(), this->_usedIds.end(), id) != this->_usedIds.end()) {
        err = 0;
        return (this->_clients[id]);
    }
    err = 1;
    static ClientID nullID;
    return (nullID);
}

const net::ClientID &net::ClientManager::getClient(const UDP::endpoint &endpoint, int &err) const
{
    std::string host = endpoint.address().to_string();
    std::string port = std::to_string(endpoint.port());
    for (int id : this->_usedIds) {
        if (this->_clients[id].host == host && this->_clients[id].port == port) {
            err = 0;
            return (this->_clients[id]);
        }
    }
    err = 1;
    static ClientID nullID;
    return (nullID);
}

std::shared_ptr<net::rtype::ClientInfos> net::ClientManager::getData(int id, int &err) const
{
    net::rtype::ClientInfos data(this->_datas[id]);
    if (std::find(this->_usedIds.begin(), this->_usedIds.end(), id) != this->_usedIds.end()) {
        err = 0;
        return (std::make_shared<net::rtype::ClientInfos>(data));
    }
    err = 1;
    static net::rtype::ClientInfos nullData;
    return (std::make_shared<net::rtype::ClientInfos>(nullData));
}

void net::ClientManager::setData(int id, const net::rtype::ClientInfos &data)
{
    if (std::find(this->_usedIds.begin(), this->_usedIds.end(), id) != this->_usedIds.end()) {
        this->_datas[id] = data;
    }
}

void net::ClientManager::setDatas(net::rtype::ClientInfos &str)
{
    for (int id : this->_usedIds) {
        this->setData(id, str);
    }
}

const std::vector<int> &net::ClientManager::getConnectedIds() const
{
    return (this->_usedIds);
}

int net::ClientManager::getClientCount() const
{
    return (this->_clientCount);
}
