/*
** EPITECH PROJECT, 2022
** PDG-D10-PM (Workspace)
** File description:
** CommunicationDevice
*/

#pragma once

#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationAPI.hpp"

// This device will be used for communication between Houston and Mars.
// Each astrounaute who want to use the device should be regester in the
// device. A valid user name should only contain lowercase alphanumeric
// characters.
class CommunicationDevice {
    public:
        CommunicationDevice(std::istream &input, std::ostream &output);
        ~CommunicationDevice();

        void startMission(std::string const &missionName, std::string *users, size_t nbUsers);
        void send(std::string const &user, std::string const &message) const;
        void receive(std::string const &user, std::string &message) const;

    private:
        CommunicationAPI _api;
};
