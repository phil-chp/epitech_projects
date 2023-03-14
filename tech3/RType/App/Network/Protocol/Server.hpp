/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include "Network/Boost.hpp"
    #include "Network/Protocol/Communication.hpp"
    #include "Network/Protocol/TCP/Server.hpp"
    #include "Network/Protocol/UDP/Server.hpp"
    #include "Network/Protocol/ClientID.hpp"
    #include "Network/Protocol/ClientManager.hpp"
    #include "Utils/ThreadPool.hpp"
    #include "Utils/SafeQueue.hpp"
    #include <thread>
    #include <chrono>

namespace net {

template <typename T, typename U>
class Server : public net::ACommunication, public net::tcp::AServer, public net::udp::AServer<T, U> {
    public:
        Server(const std::string &port)
            : net::ACommunication()
            , net::tcp::AServer(this->_context, port)
            , net::udp::AServer<T, U>(this->_context, port)
            , _networkDelay(COMM_DELAY)
        {
            this->_pool.start();
            this->_pool.queueJob([&]{
                this->startContext();
            });
        };
        ~Server() {
            this->_pool.stop();
        };

        ClientManager &getManager();
        int getClientCount() const {
            return (this->_clientManager.getClientCount());
        };

        bool isRunning() const {
            return (!this->_context.stopped());
        };

        void startContext();

        // UDP
        void send(T &str) final;
        U &receive() final;

    protected:
        // TCP
        void _startAccept() final;
        void _handleAccept(const boost::system::error_code& error) final;

        // UDP
        void _handleReceive(const boost::system::error_code &error, std::size_t bytes) final;
        void _startReceive() final;
        void _startSend(const ClientID &client) final;

        void _sendToAll(int id) final;

        ClientManager _clientManager;

        ThreadPool _pool;

        unsigned int _networkDelay;

};

} // namespace net

#endif /* !SERVER_HPP_ */
