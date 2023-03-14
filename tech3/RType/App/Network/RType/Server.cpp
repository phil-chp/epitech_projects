/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Server
*/

#include "Network/RType/Server.hpp"

template<>
void net::rtype::Server::_startReceive();

template<>
void net::rtype::Server::_sendToAll(int exclId);

template<>
void net::rtype::Server::_startAccept();

template<>
void net::rtype::Server::send(net::rtype::ServerInfos &data)
{
    this->_sendData = data;
    this->_sendToAll(-1);
}

template<>
net::rtype::ClientInfos &net::rtype::Server::receive()
{
    return (this->_receivedData);
}

// * -------------------------------- UDP --------------------------------- * //

template<>
void net::rtype::Server::_handleReceive(const boost::system::error_code &error, std::size_t bytes)
{
    if (error && error != boost::asio::error::message_size) {
        throw NetworkError(error.message());
    }
    int err = 0;
    ClientID client = this->_clientManager.getClient(this->_udpEndpoint, err);
    if (err) throw NetworkError("ClientManager: client not found");

    std::string archiveData(this->_recvData.data(), bytes);
    std::stringstream ss(archiveData);
    try {
        boost::archive::binary_iarchive archive(ss);
        archive >> this->_receivedData;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        this->_receivedData.reset();
    }

    std::cerr << "Received: " << this->_receivedData << std::endl;
    if (this->_receivedData.from == -1) {
        this->_receivedData.from = client.id;
    }
    this->_clientManager.setData(client.id, this->_receivedData);
    this->_recvData.fill(0);
    this->_sendToAll(client.id);
}

template<>
void net::rtype::Server::_startReceive()
{
    this->_udpSocket.async_receive_from(
        boost::asio::buffer(this->_recvData),
        this->_udpEndpoint,
        boost::bind(
            &net::rtype::Server::_handleReceive,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

template<>
void net::rtype::Server::_startSend(const ClientID &client)
{
    static std::string buffer;
    boost::system::error_code err;
    std::cerr << ">>> Sending: " << this->_sendData << std::endl;

    std::stringstream ss;
    boost::archive::binary_oarchive archive(ss);
    archive << this->_sendData;
    buffer = ss.str();

    this->_udpSocket.async_send_to(
        boost::asio::buffer(buffer),
        client.udpEndpoint,
        [this, client](const boost::system::error_code &/* error */, std::size_t /* bytes */) {
            // std::cout << "Sending: " << this->_sendData << std::endl;
            this->_startReceive();
        }
    );
    if (err) {
        throw NetworkError(err.message());
    }
}

template<>
void net::rtype::Server::_sendToAll(int exclId)
{
    static net::rtype::ServerInfos serverInfo;
    std::shared_ptr<net::rtype::ClientInfos> clientInfo;
    ClientID client;
    int err = 0;

    serverInfo.from = exclId;
    serverInfo.usedIds = this->_clientManager.getConnectedIds();

    for (int id : serverInfo.usedIds) {
        clientInfo = this->_clientManager.getData(id, err);
        if (err) {
            throw NetworkError("ClientManager couldn't get buffer");
        }
        serverInfo.protocol = (id == exclId ? net::RFC990::RTO02 : net::RFC990::RTO01);
        serverInfo.to = id;
        serverInfo.inputs[id] = clientInfo->inputs;
        this->_sendData = serverInfo;
        client = this->_clientManager.getClient(id, err);
        if (err) {
            throw NetworkError("ClientManager couldn't get client");
        }
        this->_startSend(client);
    }
}

// * -------------------------------- TCP --------------------------------- * //


template<>
void net::rtype::Server::_handleAccept(const boost::system::error_code& error)
{
    if (error) {
        throw NetworkError(error.message());
    }
    int clientCount = this->getClientCount();

    if (clientCount < MAX_CLIENTS) {
        int id = this->_clientManager.addClient(this->_tcpSocket.remote_endpoint());
        if (id == -1) {
            throw NetworkError("ClientManager: couldn't add client");
        }
        std::cout << "Currently " << clientCount + 1 << " clients connected" << std::endl;
        std::cout << "Client joined: "
            << this->_tcpSocket.remote_endpoint().address().to_string() << ":"
            << this->_tcpSocket.remote_endpoint().port() << ", client id = " << id << std::endl;
    }
    this->_tcpSocket = TCP::socket(this->_context);
    this->_startAccept();
}

template<>
void net::rtype::Server::_startAccept()
{
    std::cout << ">>> WAITING FOR CLIENT JOIN" << std::endl;
    this->_tcpAcceptor.async_accept(
        this->_tcpSocket,
        boost::bind(
            &net::rtype::Server::_handleAccept,
            this,
            boost::asio::placeholders::error
        )
    );
}

// * ---------------------------------------------------------------------- * //

template<>
void net::rtype::Server::startContext()
{
    this->_startAccept();
    this->_startReceive();
    try {
        boost::asio::signal_set signals(this->_context, SIGINT, SIGTERM);
        signals.async_wait([&](auto, auto){
            std::cout << "Signal interrupt catched: shutting down server." << std::endl;
            this->_context.stop();
        });
        this->_context.run();
    } catch(const std::exception& e) {
        throw NetworkError("Server network exception: " + std::string(e.what()));
    } catch (...) {
        throw NetworkError("Server network exception: unknown error");
    }
}
