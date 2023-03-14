/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Communication
*/

#ifndef COMMUNICATION_HPP_
    #define COMMUNICATION_HPP_

    #include "Network/Boost.hpp"

namespace net {

class ACommunication {
    public:
        ACommunication() = default;
        ~ACommunication() = default;

    protected:
        boost::asio::io_context _context;
};

} // namespace net

#endif /* !COMMUNICATION_HPP_ */
