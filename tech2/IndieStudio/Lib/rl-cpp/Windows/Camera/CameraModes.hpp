/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** CameraModes
*/

#ifndef CAMERAMODES_HPP_
    #define CAMERAMODES_HPP_

namespace rl {
    enum CameraMode {
        CAM_CUSTOM = 0,              // Custom camera
        CAM_FREE,                    // Free camera
        CAM_ORBITAL,                 // Orbital camera
        CAM_FIRST_PERSON,            // First person camera
        CAM_THIRD_PERSON             // Third person camera
    };
}
#endif /* !CAMERAMODES_HPP_ */
