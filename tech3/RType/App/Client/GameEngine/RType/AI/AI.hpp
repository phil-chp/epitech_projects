/*
** EPITECH PROJECT, 2022
** RType
** File description:
** AI
*/

#ifndef RTYPEAI_HPP_
#define RTYPEAI_HPP_


    #include "GameEngine/Entity.hpp"
    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/ShaderManager.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"
    #include "ECS/Components/RLShader.hpp"


namespace engine {
    namespace rtype {
        class AI {
            public:
                AI() = default;
                ~AI() = default;

                static void moveSinus(ecs::Entity entity, float dt) {
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);
                    ai.move.val.a -= dt;
                    ai.move.val.b  = sin(trans.position.x / 100) * 100;
                    body.velocity.x = ai.move.val.a;
                    body.velocity.y = ai.move.val.b;
                }

                static void moveCos(ecs::Entity entity, float dt) {
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);
                    ai.move.val.a -= dt;
                    ai.move.val.b  = cos(trans.position.x / 100) * 100;
                    body.velocity.x = ai.move.val.a;
                    body.velocity.y = ai.move.val.b;
                }

                static void moveSquare(ecs::Entity entity, float dt) {
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);
                    ai.move.val.a -= dt;
                    // int b  = sin(trans.position.x / 100);
                    int a = trans.position.x / 100;
                    ai.move.val.b  = a*a;


                    body.velocity.x = ai.move.val.a;
                    body.velocity.y = ai.move.val.b;
                    // body.velocity.dump();
                }

                static void moveCircle(ecs::Entity entity, float dt) {
                    static float alpha = 360;
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);

                    ai.move.val.a = cos(alpha) * 100;
                    ai.move.val.b = sin(alpha) * 100;
                    // body.velocity.y = ai.move.val.a;
                    // body.velocity.x = ai.move.val.b;

                    trans.position.y = ai.move.targetPoint.y + ai.move.val.a;
                    trans.position.x = ai.move.targetPoint.x + ai.move.val.b;
                    ai.move.targetPoint.x -= 150 * dt;
                    alpha -= 2 * dt;
                    if (alpha <= 0)
                        alpha = 360;
                }

                static void moveCircleV2(ecs::Entity entity, float dt) {
                    static float alpha = 360;
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);

                    ai.move.val.a = cos(alpha) * 100;
                    ai.move.val.b = sin(alpha) * 100;
                    // body.velocity.y = ai.move.val.a;
                    // body.velocity.x = ai.move.val.b;

                    trans.position.y = ai.move.targetPoint.y + ai.move.val.a;
                    trans.position.x = ai.move.targetPoint.x + ai.move.val.b;
                    alpha -= 2 * dt;
                    if (alpha <= 0)
                        alpha = 360;
                }

                static void moveTo(ecs::Entity entity, float dt) {
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);
                    if (trans.position.x == ai.move.targetPoint.x && trans.position.y == ai.move.targetPoint.y) {
                        std::cout << "OKAU" << std::endl;
                        body.velocity *= 0;
                        return;
                    }


                    if (trans.position.x > ai.move.targetPoint.x) {
                        body.velocity.x = -20;
                        if (trans.position.x - 50 <= ai.move.targetPoint.x)
                            body.velocity.x = -1;
                    }
                    else {
                        body.velocity.x = 20;
                        if (trans.position.x + 50 >= ai.move.targetPoint.x)
                            body.velocity.x = 1;
                    }

                    if (trans.position.y > ai.move.targetPoint.y) {
                        body.velocity.y = -20;
                        if (trans.position.y - 50 <= ai.move.targetPoint.y)
                            body.velocity.y = -1;
                    }
                    else {
                        body.velocity.y = 20;
                        if (trans.position.y + 50 >= ai.move.targetPoint.y)
                            body.velocity.y = 1;
                    }


                }


                static void moveUpDown(ecs::Entity entity, float dt) {
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);

                    if (trans.position.y <= 10)
                        ai.move.val.b = 100.0;

                    else if (trans.position.y >= 950)
                        ai.move.val.b = -100.0;


                    body.velocity.y = ai.move.val.b;
                    body.velocity.x -= dt;

                }

                static void move(ecs::Entity entity, float dt) {
                    ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                    ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                    ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);
                    // body.velocity.y
                    body.velocity.x = ai.move.val.a;

                }

                // static void moveEntrance(ecs::Entity entity, float dt) {
                //     ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(entity);
                //     ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                //     ecs::AI &ai = ecs::Coordinator::getInstance().getComponent<ecs::AI>(entity);

                //     if (trans.position.x <= 1600)
                //         ai.move.val.a = 0;
                //     body.velocity.x = ai.move.val.a;
                // }


        };
    }
}

#endif /* !AI_HPP_ */
