/*
** EPITECH PROJECT, 2022
** Rtype
** File description:
** RType-Raygun
*/

#ifndef RTYPE_RAYGUN_HPP_
    #define RTYPE_RAYGUN_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "Utils/Vector2.hpp"


namespace engine {
namespace rtype {

    const std::vector<::game::Color> raygunColor = {
        ::game::Color(255, 0, 255, 255),
        ::game::Color(0, 0, 255, 255)
    };

class Raygun : public ::engine::Projectile {
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
            ::engine::rtype::Raygun projectile;
            return projectile.entity;
        }

        static ::ecs::Entity fire(::game::Vector2 &pos, short lvl, ::game::Vector2 target, ecs::CollisionType type) {
            ::engine::rtype::Raygun projectile(type);
            projectile.setPos(::game::Vector2(pos.x + 50, pos.y));
            // if (pos.x > target.x) {
            //     ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(projectile.entity);
            //     body.velocity.x *= -1;
            //     body.acceleration.x *= -1;
            //     ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(projectile.entity);
            //     anim.toSet = true;
            //     anim.setTo = {anim.current.first + 1, anim.current.second};
            // }
            ::engine::rtype::Raygun projectile2(type, 1);
            projectile2.setPos(::game::Vector2(pos.x + 50, pos.y + 80));
            // if (pos.x > target.x) {
            //     ecs::RigidBody &body = ecs::Coordinator::getInstance().getComponent<ecs::RigidBody>(projectile2.entity);
            //     body.velocity.x *= -1;
            //     body.acceleration.x *= -1;
            //     ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(projectile2.entity);
            //     anim.toSet = true;
            //     std::cout << "ray:" << anim.current.first << ", " << anim.current.second << std::endl;
            //     anim.setTo = {anim.current.first + 1, anim.current.second};
            // }

            (void)lvl;
            return projectile.entity;
        }



        Raygun(ecs::CollisionType type = ecs::CollisionType::COL_PROJECTILE_ALLY, int raygun = 0, ::game::Vector2 pos = {0, 0}) : ::engine::Projectile(pos)
        {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::RLDrawable {
                    SpriteManager::getInstance().getData(SpriteType::SPR_RAYGUN), false
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
            drawable._drawable.setSize(::game::Vector2(drawable._drawable.getSize() * 0.3));
            ecs::SpriteAnimation anim;
            anim.max = {{0, 2}, {1, 2}};

            anim.container = {
                {0, {game::Rect(0*0.3, 0*0.3, 145*0.3, 164*0.3), game::Rect(150*0.3, 0*0.3, 145*0.3, 164*0.3)}},
                {1, {game::Rect(0*0.3, 175*0.3, 145*0.3, 164*0.3), game::Rect(153*0.3, 175*0.3, 145*0.3, 164*0.3)}}
            };
            anim.current = {raygun, 0};
            anim.delay = 0.5;
            anim.actualDelay = 0.5;
            anim.fix = false;
            anim.toSet = true;
            anim.setTo = {raygun, 0};
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
            if (raygun == 0) {
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Bullet {
                        .update = &engine::rtype::Movement::updateSin
                    }
                );
            } else {
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::Bullet {
                        .update = &engine::rtype::Movement::updateCos
                    }
                );
            }
            engine::rtype::Propulsion propulsor(this->entity, raygunColor[raygun]);
        };

        ~Raygun() = default;
};
}; // rtype
} // engine

#endif
