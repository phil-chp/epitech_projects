/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** animations
*/

#ifndef ANIMATIONS_HPP_
    #define ANIMATIONS_HPP_

// TODO: I'm not sure where to put this so it's here for the moment
// TODO: would be nice to have them inside Assets/

enum PlayerAnimations {
    PLAYER_WALK,
    PLAYER_IDLE,
    PLAYER_DEATH
};

enum BombAnimations {
    BOMB_IDLE
    // no bomb explode, it's handled by ecs and particle/shaders
};

enum CrateAnimations {
    CRATE_BREAK // doesn't work :/
};

#endif /* !ANIMATIONS_HPP_ */
