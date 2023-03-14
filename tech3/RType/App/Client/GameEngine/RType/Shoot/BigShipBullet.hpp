/*
** EPITECH PROJECT, 2022
** RType
** File description:
** BigShipBullet
*/

#ifndef BIGSHIPBULLET_HPP_
#define BIGSHIPBULLET_HPP_
    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {

class BigShipBullet : public ::engine::Projectile {
    public:
        void setPos(game::Vector2 pos) {
            ::ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(this->entity);
            trans.position.x = pos.x;
            trans.position.y = pos.y;
        }

        void setAngle(float angle) {
            ::ecs::Transform &trans = ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(this->entity);
            trans.rotation = angle;
        }

        static ecs::Entity construct() {
            ::engine::rtype::BigShipBullet projectile;
            return projectile.entity;
        }

        static ::ecs::Entity fire(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::BigShipBullet projectile(type);
            projectile.setPos(::game::Vector2(pos.x + 20, pos.y + 30));


            (void)lvl;
            return projectile.entity;
        }



        BigShipBullet(ecs::CollisionType type = ecs::CollisionType::COL_PROJECTILE_ALLY, ::game::Vector2 pos = {0, 0}) : ::engine::Projectile(pos)
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_RTYPE3), false
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
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() *4));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 1}};

            anim.container = {
                {0, {game::Rect(280*4, 56*4, 19*4, 10*4)}}
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
                    .collidedWith = {},
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
                    .update = &engine::rtype::Movement::updateStraight
                }
            );

        };

        ~BigShipBullet() = default;
};
}; // rtype
} // engine

#endif /* !SMALLSHIPBULLET_HPP_ */
