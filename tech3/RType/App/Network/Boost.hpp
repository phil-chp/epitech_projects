/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Boost
*/

#ifndef BOOST_HPP_
    #define BOOST_HPP_

    // Asio
    #include <boost/asio.hpp>
    #include <boost/bind/bind.hpp>

    // Binary communcation
    #include <boost/archive/binary_oarchive.hpp>
    #include <boost/archive/binary_iarchive.hpp>

    // Serialization
    #include <boost/serialization/access.hpp>
    #include <boost/serialization/export.hpp>
    #include <boost/serialization/string.hpp>
    #include <boost/serialization/base_object.hpp>
    #include <boost/serialization/map.hpp>
    #include <boost/serialization/array.hpp>
    #include <boost/serialization/bitset.hpp>
    #include <boost/serialization/vector.hpp>

    #include <boost/iostreams/device/array.hpp>
    #include <boost/iostreams/stream.hpp>

using UDP = boost::asio::ip::udp;
using TCP = boost::asio::ip::tcp;

#endif /* !BOOST_HPP_ */
