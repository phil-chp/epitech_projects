/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** ControlMoveSystem
*/

#include "ECS/Systems/ControlMoveSystem.hpp"

void ecs::ControlMoveSystem::update(::engine::PollEvent &event) const
{
    for (ecs::Entity const &entity : this->entities) {
        Control &control     = Coordinator::getInstance().getComponent<Control>(entity);
        RigidBody &rigidBody = Coordinator::getInstance().getComponent<RigidBody>(entity);
        MoveStat &stats      = Coordinator::getInstance().getComponent<MoveStat>(entity);

        if (!control.secondary) {
            if ((event.playerEvents[control.eventID].pressed & engine::UP) == engine::UP) {
                if (rigidBody.velocity.y > -stats.yVel) {
                    rigidBody.velocity.y = -stats.yVel;
                    rigidBody.acceleration.y = -stats.yAcc;
                }
                if (rigidBody.velocity.y < -stats.maxVelY) {
                    rigidBody.velocity.y = -stats.maxVelY;
                    rigidBody.acceleration.y = 0;
                }
            } else if ((event.playerEvents[control.eventID].pressed & engine::DOWN) == engine::DOWN) {
                if (rigidBody.velocity.y < stats.yVel) {
                    rigidBody.velocity.y = stats.yVel;
                    rigidBody.acceleration.y = stats.yAcc;
                }
                if (rigidBody.velocity.y > stats.maxVelY) {
                    rigidBody.velocity.y = stats.maxVelY;
                    rigidBody.acceleration.y = 0;
                }
            } else if ((event.playerEvents[control.eventID].released & engine::DOWN) == engine::DOWN || \
                (event.playerEvents[control.eventID].released & engine::UP) == engine::UP) {
                    rigidBody.velocity.y = 0;
                    rigidBody.acceleration.y = 0;
            }

            if ((event.playerEvents[control.eventID].pressed & engine::LEFT) == engine::LEFT) {
                if (rigidBody.velocity.x > -stats.xVel) {
                    rigidBody.velocity.x = -stats.xVel;
                    rigidBody.acceleration.x = -stats.xAcc;
                }

                if (rigidBody.velocity.x < -stats.maxVelX) {
                    rigidBody.velocity.x = -stats.maxVelX;
                    rigidBody.acceleration.x = 0;
                }
            } else if ((event.playerEvents[control.eventID].pressed & engine::RIGHT) == engine::RIGHT) {
                if (rigidBody.velocity.x < stats.xVel) {
                    rigidBody.velocity.x = stats.xVel;
                    rigidBody.acceleration.x = stats.xAcc;
                }

                if (rigidBody.velocity.x > stats.maxVelX) {
                    rigidBody.velocity.x = stats.maxVelX;
                    rigidBody.acceleration.x = 0;
                }
            } else if((event.playerEvents[control.eventID].released & engine::LEFT) == engine::LEFT || \
                (event.playerEvents[control.eventID].released & engine::RIGHT) == engine::RIGHT) {
                    rigidBody.velocity.x = 0;
                    rigidBody.acceleration.x = 0;
            }

        } else {
            if ((event.playerEvents[control.eventID].pressed & engine::SEC_UP) == engine::SEC_UP) {
                if (rigidBody.velocity.y > -stats.yVel) {
                    rigidBody.velocity.y = -stats.yVel;
                    rigidBody.acceleration.y = -stats.yAcc;
                }
                if (rigidBody.velocity.y < -stats.maxVelY) {
                    rigidBody.velocity.y = -stats.maxVelY;
                    rigidBody.acceleration.y = 0;
                }
            } else if ((event.playerEvents[control.eventID].pressed & engine::SEC_DOWN) == engine::SEC_DOWN) {
                if (rigidBody.velocity.y < stats.yVel) {
                    rigidBody.velocity.y = stats.yVel;
                    rigidBody.acceleration.y = stats.yAcc;
                }
                if (rigidBody.velocity.y > stats.maxVelY) {
                    rigidBody.velocity.y = stats.maxVelY;
                    rigidBody.acceleration.y = 0;
                }
            } else if ((event.playerEvents[control.eventID].released & engine::SEC_DOWN) == engine::SEC_DOWN || \
                (event.playerEvents[control.eventID].released & engine::SEC_UP) == engine::SEC_UP) {
                    rigidBody.velocity.y = 0;
                    rigidBody.acceleration.y = 0;
            }

            if ((event.playerEvents[control.eventID].pressed & engine::SEC_LEFT) == engine::SEC_LEFT) {
                if (rigidBody.velocity.x > -stats.xVel) {
                    rigidBody.velocity.x = -stats.xVel;
                    rigidBody.acceleration.x = -stats.xAcc;
                }

                if (rigidBody.velocity.x < -stats.maxVelX) {
                    rigidBody.velocity.x = -stats.maxVelX;
                    rigidBody.acceleration.x = 0;
                }
            } else if ((event.playerEvents[control.eventID].pressed & engine::SEC_RIGHT) == engine::SEC_RIGHT) {
                if (rigidBody.velocity.x < stats.xVel) {
                    rigidBody.velocity.x = stats.xVel;
                    rigidBody.acceleration.x = stats.xAcc;
                }

                if (rigidBody.velocity.x > stats.maxVelX) {
                    rigidBody.velocity.x = stats.maxVelX;
                    rigidBody.acceleration.x = 0;
                }
            } else if((event.playerEvents[control.eventID].released & engine::SEC_LEFT) == engine::SEC_LEFT || \
                (event.playerEvents[control.eventID].released & engine::SEC_RIGHT) == engine::SEC_RIGHT) {
                    rigidBody.velocity.x = 0;
                    rigidBody.acceleration.x = 0;
            }
        }
    }
}
