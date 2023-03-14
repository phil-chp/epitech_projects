/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include "Network/Boost.hpp"
    #include "Network/Protocol/Communication.hpp"
    #include "Network/Protocol/TCP/Client.hpp"
    #include "Network/Protocol/UDP/Client.hpp"
    #include "Utils/ThreadPool.hpp"
    #include "Utils/SafeQueue.hpp"

namespace net {

template <typename T, typename U>
class Client : public net::ACommunication, public net::tcp::AClient, public net::udp::AClient<T, U> {
    public:
        Client(const std::string &host, const std::string &port)
            : net::ACommunication()
            , net::tcp::AClient(this->_context, host, port)
            , net::udp::AClient<T, U>(this->_context, host, port)
            , _networkDelay(COMM_DELAY)
            , _id(-1)
        {
            this->_pool.start();
            this->startContext();
        }
        ~Client() {
            this->_pool.stop();
        };

        bool isRunning() const {
            return (!this->_context.stopped());
        };
        void startContext();

        // UDP
        void send(T &str) final;
        U &receive() final;

        unsigned int getId() final;

        void close() {
            this->_pool.stop();
            this->_udpSocket.close();
            this->_tcpSocket.close();
            this->_context.stop();
        }

    protected:
        // TCP
        void _startConnect() final;
        void _handleConnect(const boost::system::error_code& error) final;

        // UDP
        void _startSend(T &buffer) final;
        void _startReceive() final;

        ThreadPool _pool;
        unsigned int _networkDelay;
        int _id;
};

} // namespace net

#endif /* !CLIENT_HPP_ */
