/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** RType-Projectile
*/

#ifndef RTYEP_PROJECTILE_HPP_
    #define RTYEP_PROJECTILE_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {

class Projectile : public ::engine::Projectile {
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
            ::engine::rtype::Projectile projectile;
            return projectile.entity;
        }

        static ::ecs::Entity fire(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::Projectile projectile(type);
            // Son de tir
            projectile.setPos(pos);
            if (pos.x > target.x) {
                ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(projectile.entity);
                body.velocity.x *= -1;
                body.acceleration.x *= -1;
                ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(projectile.entity);
                anim.toSet = true;
                anim.setTo = {anim.current.first + 1, anim.current.second};
            }
            (void)lvl;
            return projectile.entity;
        }

        Projectile(ecs::CollisionType type = ecs::CollisionType::COL_PROJECTILE_ALLY, ::game::Vector2 pos = {0, 0}) : ::engine::Projectile(pos)
        {

            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_SHOOT1), false
                }
            );

            ecs::CollisionType col;
            if (type == ecs::CollisionType::COL_PROJECTILE_ALLY)
                col = ecs::CollisionType::COL_PROJECTILE_ALLY;
            else
                col = ecs::CollisionType::COL_PROJECTILE_ENEMY;


            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Alive {
                    .hp = 100,
                    .dead = false,
                    .shield = false
                }
            );

            ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 4.0));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}, {8, 2}, {9, 2}};

            anim.container = {
                {0, {game::Rect(248*4, 103*4, 17*4, 12*4), game::Rect(231*4, 103*4, 17*4, 12*4)}},
                {1, {game::Rect(267*4, 103*4, 17*4, 12*4), game::Rect(284*4, 103*4, 17*4, 12*4)}},
                {2, {game::Rect(233*4, 120*4, 33*4, 12*4), game::Rect(200*4, 120*4, 33*4, 12*4)}},
                {3, {game::Rect(267*4, 120*4, 33*4, 12*4), game::Rect(300*4, 120*4, 33*4, 12*4)}},
                {4, {game::Rect(217*4, 136*4, 48*4, 13*4), game::Rect(169*4, 136*4, 48*4, 13*4)}},
                {5, {game::Rect(267*4, 136*4, 48*4, 13*4), game::Rect(315*4, 136*4, 48*4, 13*4)}},
                {6, {game::Rect(200*4, 154*4, 65*4, 14*4), game::Rect(135*4, 154*4, 65*4, 14*4)}},
                {7, {game::Rect(267*4, 154*4, 65*4, 14*4), game::Rect(332*4, 154*4, 65*4, 14*4)}},
                {8, {game::Rect(184*4, 170*4, 81*4, 16*4), game::Rect(103*4, 170*4, 81*4, 16*4)}},
                {9, {game::Rect(267*4, 170*4, 81*4, 16*4), game::Rect(348*4, 170*4, 81*4, 16*4)}}
            };
            anim.current = {0, 0};
            anim.delay = 0.5;
            anim.actualDelay = 0.5;
            anim.fix = false;
            anim.toSet = true;
            anim.setTo = {0,0};
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
                            anim.container.at(anim.current.first)[anim.current.second].w * 0.95,
                            anim.container.at(anim.current.first)[anim.current.second].h * 0.95
                    )),
                    .collidesWith = {},
                    .collidedWith = {},
                    .colType = col,
                    .invFrames = 0,
                    .rect = rl::Rectangle(
                        0,
                        0,
                        anim.container.at(anim.current.first)[anim.current.second].w * 0.95,
                        anim.container.at(anim.current.first)[anim.current.second].h * 0.95
            )});
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Bullet {
                    .update = &engine::rtype::Movement::updateStraight
                }
            );
        };

        ~Projectile() = default;
};
}; // rtype
} // engine

#endif
