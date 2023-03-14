/*
** EPITECH PROJECT, 2022
** PDG-D7-AM (Workspace)
** File description:
** Federation
*/

#pragma once

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Borg {
    class Ship;
}

namespace Federation {
    namespace Starfleet {
        class Ensign {
            public:
                Ensign(std::string name);
                ~Ensign();

            private:
                std::string _name;
        };

        class Captain {
            public:
                Captain(std::string name);
                ~Captain();
                std::string getName();
                int getAge();
                void setAge(int age);

            private:
                std::string _name;
                int _age;
        };

        class Ship {
            public:
                Ship(int length = 289,                 \
                    int width = 132,                   \
                    std::string name = "Entreprise",   \
                    short maxWarp = 6,                 \
                    int torpedo = 0);
                ~Ship();
                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Captain *captain);
                bool move(int warp, Destination d);
                bool move(Destination d);
                bool move(int warp);
                bool move();
                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);

            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                WarpSystem::Core *_core;
                Captain *_captain;
                Destination _location;
                Destination _home;
                int _shield;
                int _photonTorpedo;
        };
    };

    class Ship {
        public:
            Ship(int length, int width, std::string name);
            ~Ship();
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            bool move(int warp, Destination d);
            bool move(Destination d);
            bool move(int warp);
            bool move();
            WarpSystem::Core *getCore();

        private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_core;
            Destination _location;
            Destination _home;
    };
};
