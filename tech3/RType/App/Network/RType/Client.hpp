/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Client
*/

#ifndef RTYPECLIENT_HPP_
    #define RTYPECLIENT_HPP_

    #include "Network/Protocol/Client.hpp"
    #include "Network/RType/NetworkInfos.hpp"
    #include "Network/RType/RFC990.hpp"

namespace net {
namespace rtype {

typedef net::Client<ClientInfos, ServerInfos> Client;

} // namespace rtype
} // namespace net

#endif /* !RTYPECLIENT_HPP_ */
