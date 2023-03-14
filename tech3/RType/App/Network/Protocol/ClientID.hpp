/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** ClientID
*/

#ifndef CLIENTID_HPP_
    #define CLIENTID_HPP_

    #include "Network/Boost.hpp"

namespace net {

struct ClientID {
    public:
        ClientID()
            : host("")
            , port("")
            , id(0)
        {};
        ClientID(const ClientID &otr)
        {
            this->udpEndpoint = otr.udpEndpoint;
            this->tcpEndpoint = otr.tcpEndpoint;
            this->id = otr.id;
            this->host = otr.host;
            this->port = otr.port;
        };
        ClientID(const TCP::endpoint &endpoint, unsigned int id)
            : host(endpoint.address().to_string())
            , port(std::to_string(endpoint.port()))
            , id(id)
            , tcpEndpoint(endpoint)
        {
            boost::system::error_code ec;
            boost::asio::ip::address ipAddress = boost::asio::ip::address::from_string(this->host, ec);
            this->udpEndpoint = UDP::endpoint(ipAddress, std::stoi(this->port));
        };

        ClientID &operator=(const ClientID &otr) {
            this->udpEndpoint = otr.udpEndpoint;
            this->tcpEndpoint = otr.tcpEndpoint;
            this->id   = otr.id;
            this->host = otr.host;
            this->port = otr.port;
            return *this;
        }
        // bool operator==(UDP::endpoint endpoint) {
        //     return (this->host == endpoint.address().to_string() && this->port == std::to_string(endpoint.port()));
        // }

        std::string who() const {
            return (this->host + ":" + this->port);
        }

        std::string host;
        std::string port;

        int id;

        TCP::endpoint tcpEndpoint;
        UDP::endpoint udpEndpoint;

};

} // namespace net

#endif /* !CLIENTID_HPP_ */
