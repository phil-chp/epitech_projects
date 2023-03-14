/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SmallShipBullet
*/

#ifndef SMALLSHIPBULLET_HPP_
#define SMALLSHIPBULLET_HPP_
    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {

class SmallShipBullet : public ::engine::Projectile {
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
            ::engine::rtype::SmallShipBullet projectile;
            return projectile.entity;
        }

        static ::ecs::Entity fireShipUp(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::SmallShipBullet projectile(type, 0);
            projectile.setPos(pos);


            (void)lvl;
            return projectile.entity;
        }

        static ::ecs::Entity fireShipDown(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::SmallShipBullet projectile(type, 1);
            projectile.setPos(:: game::Vector2(pos.x + 20, pos.y));


            (void)lvl;
            return projectile.entity;
        }



        SmallShipBullet(ecs::CollisionType type = ecs::CollisionType::COL_PROJECTILE_ALLY, int ship = 0, ::game::Vector2 pos = {0, 0}) : ::engine::Projectile(pos)
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
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() *2));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 2}, {1, 2}};

            anim.container = {
                {0, {game::Rect(87*2, 310*2, 35*2, 13*2), game::Rect(121*2, 310*2, 35*2, 13*2)}},
                {1, {game::Rect(87*2, 326*2, 35*2, 13*2), game::Rect(121*2, 326*2, 35*2, 13*2)}}
            };
            anim.current = {0, 0};
            anim.delay = 0.5;
            anim.actualDelay = 0.5;
            anim.fix = false;
            anim.toSet = true;
            if (ship == 0)
                anim.setTo = {0, 0};
            else
                anim.setTo = {1, 0};
            // anim.setTo = {0, 0};
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

        ~SmallShipBullet() = default;
};
}; // rtype
} // engine

#endif /* !SMALLSHIPBULLET_HPP_ */
