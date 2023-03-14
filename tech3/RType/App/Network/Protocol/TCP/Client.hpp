/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Client
*/

#ifndef TCPCLIENT_HPP_
    #define TCPCLIENT_HPP_

    #include "Network/Boost.hpp"
    #include "Network/Protocol/Constants.hpp"
    #include "Utils/Errors/Errors.hpp"

namespace net {
namespace tcp {

class IClient {
    public:
        virtual ~IClient() = default;

    protected:
        virtual void _startConnect() = 0;
        virtual void _handleConnect(const boost::system::error_code& error) = 0;
};

class AClient : public IClient {
    public:
        AClient(boost::asio::io_context &context, const std::string &host, const std::string &port)
            : _tcpResolver(context)
            , _tcpSocket(context)
        {
            this->_tcpEndpoints = this->_tcpResolver.resolve(host, port);
        }
        ~AClient() {
            if (this->_tcpSocket.is_open()) {
                this->_tcpSocket.shutdown(TCP::socket::shutdown_both);
                this->_tcpSocket.close();
            }
        }

    protected:
        TCP::resolver _tcpResolver;
        TCP::socket _tcpSocket;

        TCP::resolver::results_type _tcpEndpoints;
};

} // namespace tcp
} // namespace net

#endif /* !TCPCLIENT_HPP_ */
