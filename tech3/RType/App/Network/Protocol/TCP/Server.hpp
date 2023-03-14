/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Server
*/

#ifndef TCPSERVER_HPP_
    #define TCPSERVER_HPP_

    #include "Network/Boost.hpp"
    #include "Network/Protocol/Constants.hpp"
    #include "Utils/Errors/Errors.hpp"
    #include <thread>

namespace net {
namespace tcp {

class IServer {
    public:
        virtual ~IServer() = default;

    protected:
        virtual void _startAccept() = 0;
        virtual void _handleAccept(const boost::system::error_code& error) = 0;
};

class AServer : public IServer {
    public:
        AServer(boost::asio::io_context &context, const std::string &port)
            : _tcpAcceptor(context, TCP::endpoint(TCP::v4(), std::stoi(port)))
            , _tcpSocket(context)
        {}
        ~AServer() {
            this->_tcpSocket.close();
        }

    protected:
        TCP::acceptor _tcpAcceptor;
        TCP::socket _tcpSocket;
};

} // namespace tcp
} // namespace net

#endif /* !TCPSERVER_HPP_ */
