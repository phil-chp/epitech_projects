/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Client
*/

#include "Client.hpp"

template<>
void net::rtype::Client::_startReceive();

template<>
void net::rtype::Client::_startSend(net::rtype::ClientInfos &data);

template<>
void net::rtype::Client::send(net::rtype::ClientInfos &data)
{
    this->_startSend(data);
}

template<>
net::rtype::ServerInfos &net::rtype::Client::receive()
{
    return (this->_receivedData);
}

template<>
unsigned int net::rtype::Client::getId() {
    return (this->_id);
}

// * -------------------------------- UDP --------------------------------- * //

template<>
void net::rtype::Client::_startReceive()
{
    boost::system::error_code err;
    this->_udpSocket.receive_from(
        boost::asio::buffer(this->_recvData),
        this->_udpEndpoint, 0, err
    );

    std::string archive_data(this->_recvData.data(), 1024);
    std::stringstream ss(archive_data);
    boost::archive::binary_iarchive archive(ss);
    archive >> this->_receivedData;

    std::cerr << "Received: " << this->_receivedData << std::endl;
    if (this->_receivedData.protocol == net::RFC990::RTO02 && this->_id == -1) {
        this->_id = this->_receivedData.from;
    }

    this->_recvData.fill(0);
}

template<>
void net::rtype::Client::_startSend(net::rtype::ClientInfos &data)
{
    boost::system::error_code err;
    static std::string buffer;

    data.from = this->_id;
    std::stringstream ss;
    boost::archive::binary_oarchive archive(ss);
    archive << data;
    buffer = ss.str();

    std::cerr << "Sending: " << data << std::endl;
    this->_udpSocket.send_to(
        boost::asio::buffer(buffer),
        this->_udpEndpoint, 0, err
    );
    this->_startReceive();
}

// * -------------------------------- TCP --------------------------------- * //

template <>
void net::rtype::Client::_handleConnect(const boost::system::error_code& error)
{
    if (error) {
        throw NetworkError(error.message());
    }
    std::cerr << ">>> CONNECTED" << std::endl;
}

template<>
void net::rtype::Client::_startConnect()
{
    std::cerr << ">>> CONNECTING TO SERVER" << std::endl;
    boost::asio::async_connect(
        this->_tcpSocket,
        this->_tcpEndpoints,
        boost::bind(
            &net::rtype::Client::_handleConnect,
            this,
            boost::asio::placeholders::error
        )
    );
}

// * ---------------------------------------------------------------------- * //

template<>
void net::rtype::Client::startContext()
{
    this->_startConnect();
    this->_udpSocket.open(UDP::v4());
    this->_udpSocket.bind(UDP::endpoint(UDP::v4(), std::stoi(std::to_string(this->_tcpSocket.local_endpoint().port()))));
    try {
        this->_context.run();
    } catch(const std::exception& e) {
        throw NetworkError("Network exception: " + std::string(e.what()));
    } catch (...) {
        throw NetworkError("Network exception: unknown error");
    }
}
