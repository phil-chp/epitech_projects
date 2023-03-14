// NetworkClient.cpp
#define _WIN32_WINNT 0x0501
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include "NetworkClient.h"
#include "Logging.h"

NetworkClient::NetworkClient(std::string host, std::string server_port, unsigned short local_port) : 
    socket(io_service, udp::endpoint(udp::v4(), local_port)), 
    service_thread(std::bind(&NetworkClient::run_service, this))
{
    receivedBytes = sentBytes = receivedMessages = sentMessages = 0;

    udp::resolver resolver(io_service);
    udp::resolver::query query(udp::v4(), host, server_port);
    server_endpoint = *resolver.resolve(query);
    Send("");
}

NetworkClient::~NetworkClient()
{
    io_service.stop();
    service_thread.join();
}

void NetworkClient::start_receive()
{
    socket.async_receive_from(boost::asio::buffer(recv_buffer), remote_endpoint,
        boost::bind(&NetworkClient::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
    );
}

void NetworkClient::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    if (!error)
    {
        std::string message(recv_buffer.data(), recv_buffer.data() + bytes_transferred);
        incomingMessages.push(message);
        receivedBytes += bytes_transferred;
        receivedMessages++;
    }
    else
    {
        LogMessage("NetworkClient::handle_receive:",error);
    }

    start_receive();
}

void NetworkClient::Send(std::string message)
{
    socket.send_to(boost::asio::buffer(message), server_endpoint);

    sentBytes += message.size();
    sentMessages++;
}

void NetworkClient::run_service()
{
    LogMessage("Client network thread started\n");
    start_receive();
    LogMessage("Client started receiving\n");
    while (!io_service.stopped()) {
        try {
            io_service.run();
        }
        catch (const std::exception& e) {
            LogMessage("Client network exception: ", e.what());
        }
        catch (...) {
            LogMessage("Unknown exception in client network thread");
        }
    }
    LogMessage("Client network thread stopped");
}
