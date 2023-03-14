/*
** EPITECH PROJECT, 2022
** PDG-D7-AM (Workspace)
** File description:
** Borg
*/

#pragma once

#include <iostream>
#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {
    namespace Starfleet {
        class Ship;
    }
    class Ship;
}

namespace Borg {
    class Ship {
        public:
            Ship(int frequency = 0, int repair = 3);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(Destination d);
            bool move(int warp);
            bool move();
            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);
            void fire(Federation::Starfleet::Ship *target);
            void fire(Federation::Ship *target);
            void repair();

        private:
            int _side;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
            int _shield;
            int _weaponFrequency;
            short _repair;
    };
};
