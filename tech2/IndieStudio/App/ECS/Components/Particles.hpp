/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** Particules
*/


#ifndef PARTICLES_HPP_
    #define PARTICLES_HPP_

    #include "Raylib.hpp"


namespace ecs {
    // static int i = 0;

    struct Particles {

        Particles()
            : explo(rl::Vector3(0.0f))
        {
            // std::cout << "Constructor Particles Default [" << i << "]" << std::endl;
            // ++i;
            started = false;
            done = false;
        }

        Particles(rl::Vector3 cubePos, rl::Vector4 amplitude)
            : explo(cubePos), amp(amplitude)
        {
            // std::cout << "Constructor Particles" << std::endl;
            started = false;
            done = false;
        }

        rl::Explosion explo;
        rl::Vector4 amp;

        bool started;
        bool done;
    };
}

#endif /* !PARTICULES_HPP_ */
