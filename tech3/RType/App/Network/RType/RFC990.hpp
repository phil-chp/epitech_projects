/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** RFC990
*/

#ifndef RFC990_HPP_
    #define RFC990_HPP_

//*
//! RFC990 - TELNET OPTIONS - RTYPE OPTIONS
//* Re-adapted for personal use, respecting telnet options as closely as possible
//* (Defined by:
//*   Reynolds, J. and J. Postel,
//*   "Official ARPA-Internet Protocols",
//*   RFC 991, Information Sciences Institute
//* )
//*

namespace net {
enum RFC990 {  //! CUSTOM DESCRIPTION   |   ORIGINAL DESCRIPTION

    RTO00 = 0,  //  DEFAULT STATE        |   Binary Transmission
    RTO01 = 1,  //  Protocol confirm     |   Echo
    RTO02 = 2,  //  Handshake confirm    |  Reconnection

    RTO23 = 4,  //  open                 |   Send Location
    RTO25 = 8,  //  close                |   End of Record

    // RTO20 = 4,  //  gameChanges          |   Data Entry Terminal
    // RTO21 = 8,  //  sceneChanges         |   Unused
    // RTO22 = 16, //  netChanges           |   SUPDUP (Output)

};
} // namespace net

#endif /* !RFC990_HPP_ */
