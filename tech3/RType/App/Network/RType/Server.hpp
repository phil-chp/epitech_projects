/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Server
*/

#ifndef RTYPESERVER_HPP_
    #define RTYPESERVER_HPP_

    #include "Network/Protocol/Server.hpp"
    #include "Network/RType/NetworkInfos.hpp"
    #include "Network/RType/RFC990.hpp"

namespace net {
namespace rtype {

typedef net::Server<ServerInfos, ClientInfos> Server;

} // namespace rtype
} // namespace net

#endif /* !RTYPESERVER_HPP_ */
