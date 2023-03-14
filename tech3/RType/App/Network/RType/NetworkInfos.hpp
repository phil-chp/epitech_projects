/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** TCPNetworkInfos
*/

#ifndef TCPNETWORKINFOS_HPP_
    #define TCPNETWORKINFOS_HPP_

    #include "Network/RType/RFC990.hpp"
    #include "Network/Protocol/Constants.hpp"
    #include "Client/GameEngine/PollEvent.hpp"

namespace net {
namespace rtype {

struct ClientInfos {
    ClientInfos(
        unsigned int protocol = 0,
        int from = 0,
        int to = 0
    ) : protocol(protocol), from(from), to(to), inputs({0, 0})
    {};
    ClientInfos(const net::rtype::ClientInfos &otr)
        : protocol(otr.protocol)
        , from(otr.from)
        , to(otr.to)
        , inputs({otr.inputs.pressed, otr.inputs.released})
    {
    };

    void reset() {
        this->protocol = net::RFC990::RTO00;
        this->from     = 0;
        this->to       = 0;
        this->inputs   = {0, 0};
    }

    unsigned int protocol;
    int from;
    int to;
    engine::PlayerEvent inputs;

    void operator=(const ClientInfos &otr) {
        this->protocol = otr.protocol;
        this->from     = otr.from;
        this->to       = otr.to;
        this->inputs   = otr.inputs;
    }

    friend std::ostream &operator<<(std::ostream &os, const ClientInfos &infos) {
        os << "ClientInfos: "
            << "\n  protocol: " << infos.protocol
            << "\n  from:     " << infos.from
            << "\n  to:       " << infos.to
            << "\n  inputs:   (" << infos.inputs.pressed << ", " << infos.inputs.released << ")"
            << "\n" << std::endl;
        return os;
    }

    template <typename T>
    void serialize(T &t, const unsigned int version) {
        t & protocol;
        t & from;
        t & to;
        inputs.serialize<T>(t, version);
    };
};

struct ServerInfos {
    ServerInfos(
        unsigned int protocol = 0,
        int from = 0,
        int to = 0
    ) : protocol(protocol), from(from), to(to)
    {
        this->inputs.fill({0, 0});
        this->usedIds.clear();
    };
    ServerInfos(const net::rtype::ServerInfos &otr)
        : protocol(otr.protocol)
        , from(otr.from)
        , to(otr.to)
        , usedIds(otr.usedIds)
        , inputs(otr.inputs)
    {
    };

    void reset() {
        this->protocol = net::RFC990::RTO00;
        this->from     = 0;
        this->to       = 0;
        this->inputs.fill({0, 0});
        this->usedIds.clear();
    }

    unsigned int protocol;
    int from;
    int to;
    std::array<engine::PlayerEvent, MAX_CLIENTS> inputs {{0, 0}};
    std::vector<int> usedIds;


    void operator=(const ServerInfos &otr) {
        this->protocol = otr.protocol;
        this->from     = otr.from;
        this->to       = otr.to;
        this->inputs   = otr.inputs;
        this->usedIds  = otr.usedIds;
    }

    friend std::ostream &operator<<(std::ostream &os, const ServerInfos &infos) {
        os << "ServerInfos: "
            << "\n  protocol: " << infos.protocol
            << "\n  from:     " << infos.from
            << "\n  to:       " << infos.to
            << "\n  inputs:   (1: " << infos.inputs[0].pressed << ", " << infos.inputs[0].released << ") (2: "
                                    << infos.inputs[1].pressed << ", " << infos.inputs[1].released << ") (3: "
                                    << infos.inputs[2].pressed << ", " << infos.inputs[2].released << ") (4: "
                                    << infos.inputs[3].pressed << ", " << infos.inputs[3].released << ")"
            << "\n" << std::endl;
        return os;
    }

    template <typename T>
    void serialize(T &t, const unsigned int version) {
        t & protocol;
        t & from;
        t & to;
        t & inputs;
        t & usedIds;
    };
};

} // namespace rtype
} // namespace net

#endif /* !TCPNETWORKINFOS_HPP_ */
