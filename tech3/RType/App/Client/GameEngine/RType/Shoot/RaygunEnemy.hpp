/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** RType-RaygunEnemy
*/

#ifndef RTYPE_RAYGUN_ENEMY_HPP_
    #define RTYPE_RAYGUN_ENEMY_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {


class RaygunEnemy : public ::engine::Projectile {
    public:
        void setPos(game::Vector2 pos) {
            ::ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(this->entity);
            trans.position.x = pos.x;
            trans.position.y = pos.y;
        }

        void setAngle(float angle) {
            ::ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(this->entity);
            trans.rotation = angle; // TODO: faudrait prendre ca en compte un jour :)
        }

        static ecs::Entity construct() {
            ::engine::rtype::RaygunEnemy projectile;
            return projectile.entity;
        }

        static ::ecs::Entity fire(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::RaygunEnemy projectile(type);
            projectile.setPos(::game::Vector2(pos.x - 100, pos.y));


            (void)lvl;
            return projectile.entity;
        }



        RaygunEnemy(ecs::CollisionType type = ecs::CollisionType::COL_PROJECTILE_ENEMY, ::game::Vector2 pos = {0, 0}) : ::engine::Projectile(pos)
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_RAYGUN), false
                }
            );

            ecs::CollisionType col = ecs::CollisionType::COL_PROJECTILE_ENEMY;


            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Alive {
                    .hp = 100,
                    .dead = false,
                    .shield = false
                }
            );

            ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
            ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(this->entity);
            body.velocity.x = -200;
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 0.2));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 2}, {1, 2}};

            anim.container = {
                {0, {game::Rect(0*0.2, 0*0.2, 145*0.2, 164*0.2), game::Rect(150*0.2, 0*0.2, 145*0.2, 164*0.2)}},
                {1, {game::Rect(0*0.2, 175*0.2, 145*0.2, 164*0.2), game::Rect(153*0.2, 175*0.2, 145*0.2, 164*0.2)}}
            };
            anim.current = {0, 0};
            anim.delay = 0.5;
            anim.actualDelay = 0.5;
            anim.fix = false;
            anim.toSet = true;
            anim.setTo = {0, 0};
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                anim
            );

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Hitbox {
                    .type = ecs::HitBoxType::BOX_SQUARE,
                    .bounds = std::make_shared<engine::Square>(
                        engine::Square(
                            pos,
                            anim.container.at(anim.current.first)[anim.current.second].w,
                            anim.container.at(anim.current.first)[anim.current.second].h
                    )),
                    .collidesWith = {},
                    .colType = col,
                    .invFrames = 0,
                    .rect = rl::Rectangle(
                        0,
                        0,
                        anim.container.at(anim.current.first)[anim.current.second].w,
                        anim.container.at(anim.current.first)[anim.current.second].h
            )});

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Bullet {
                    .update = &engine::rtype::Movement::updateSin
                }
            );

        };

        ~RaygunEnemy() = default;
};
}; // rtype
} // engine

#endif
