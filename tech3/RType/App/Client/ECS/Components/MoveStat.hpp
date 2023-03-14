/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** MoveStat
*/

#ifndef MOVESTAT_HPP_
    #define MOVESTAT_HPP_


namespace ecs {
struct MoveStat {
    float maxVelX;
    float xVel;
    float maxVelY;
    float yVel;
    float xAcc;
    float yAcc;
};
}

#endif /* !MOVESTAT_HPP_ */
