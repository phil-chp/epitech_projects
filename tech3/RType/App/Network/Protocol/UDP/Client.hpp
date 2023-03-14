/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Client
*/

#ifndef UDPCLIENT_HPP_
    #define UDPCLIENT_HPP_

    #include "Network/Boost.hpp"
    #include "Utils/Errors/Errors.hpp"
    #include "Network/Protocol/Constants.hpp"
    #include <array>

namespace net {
namespace udp {

template <typename T, typename U>
class IClient {
    public:
        virtual ~IClient() = default;

        virtual void send(T &str) = 0;
        virtual U &receive() = 0;

        virtual unsigned int getId() = 0;

    protected:
        virtual void _startSend(T &data) = 0;
        virtual void _startReceive() = 0;
};

template <typename T, typename U>
class AClient : public IClient<T, U> {
    public:
        AClient(boost::asio::io_context &context, const std::string &host, const std::string &port)
            : _udpResolver(context)
            , _udpSocket(context)
        {
            this->_udpEndpoint = *this->_udpResolver.resolve(host, port);
        }
        ~AClient() {
            if (this->_udpSocket.is_open()) {
                this->_udpSocket.shutdown(UDP::socket::shutdown_both);
                this->_udpSocket.close();
            }
        }


    protected:
        UDP::resolver _udpResolver;
        UDP::socket _udpSocket;

        T _sendData;
        std::array<char, 1024> _recvData {0};
        U _receivedData;

        UDP::endpoint _udpEndpoint;
};

} // namespace udp
} // namespace net

#endif /* !UDPCLIENT_HPP_ */
