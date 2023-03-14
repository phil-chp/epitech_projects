/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Server
*/

#ifndef UDPSERVER_HPP_
    #define UDPSERVER_HPP_

    #include "Network/Boost.hpp"
    #include "Network/Protocol/ClientID.hpp"
    #include "Network/Protocol/Constants.hpp"
    #include "Utils/Errors/Errors.hpp"
    #include <thread>

namespace net {
namespace udp {

template <typename T, typename U>
class IServer {
    public:
        virtual ~IServer() = default;

        virtual void send(T &data) = 0;
        virtual U &receive() = 0;

    protected:
        virtual void _handleReceive(const boost::system::error_code &error, std::size_t bytes) = 0;
        virtual void _startReceive() = 0;
        virtual void _startSend(const ClientID &client) = 0;

        virtual void _sendToAll(int id) = 0;
};

template <typename T, typename U>
class AServer : public IServer<T, U> {
    public:
        AServer(boost::asio::io_context &context, const std::string &port)
            : _udpSocket(context, UDP::endpoint(UDP::v4(), std::stoi(port)))
        {
        }
        ~AServer() {
            this->_udpSocket.close();
        }


    protected:
        UDP::socket _udpSocket;

        T _sendData;
        std::array<char, 1024> _recvData {0};
        U _receivedData;

        UDP::endpoint _udpEndpoint;
};

} // namespace udp
} // namespace net

#endif /* !UDPSERVER_HPP_ */
