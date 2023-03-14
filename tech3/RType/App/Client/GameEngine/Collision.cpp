/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Collision
*/

#include "GameEngine/Collision.hpp"
#include "ECS/Components/Hitbox.hpp"
#include "GameEngine/GameEntities.hpp"
#include "GameEngine/RType/Bonus/RaygunBonus.hpp"
#include "GameEngine/RType/Particles/Destruction.hpp"
#include "GameEngine/RType/Shader/WaveShader.hpp"
#include "GameEngine/GameEntities.hpp"
#include "GameEngine/IBonus.hpp"
#include "GameEngine/Player.hpp"
#include "GameEngine/LinkerEntities.hpp"
#include "GameEngine/Managers/LevelManager.hpp"


//* =============================== Player ================================= *//

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_ENEMY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    ecs::Alive &alive = coord.getComponent<ecs::Alive>(ent);
    ecs::RLDrawable &drawable = coord.getComponent<ecs::RLDrawable>(ent);
    ecs::Hitbox &hitbox = ecs::Coordinator::getInstance().getComponent<ecs::Hitbox>(ent);

    if (hitbox.invFrames > 0) return;

    hitbox.invFrames += 10;

    if (alive.shield == true) {

        alive.shield = false;
        ecs::Bonus &playerBonus = ecs::Coordinator::getInstance().getComponent<ecs::Bonus>(ent);
        auto it = playerBonus.bonus.find(ecs::BonusType::SHIELD_BONUS);
        if(it != playerBonus.bonus.end()) {
            ecs::Alive &aliveShield = coord.getComponent<ecs::Alive>(playerBonus.bonus[ecs::BonusType::SHIELD_BONUS]);
            aliveShield.dead = true;
        }

    }
    else {
        engine::LevelManager &lm = engine::LevelManager::getInstance();
        engine::Shader *textureShader = (engine::Shader *) (lm.getTextureShaderPtr().get());
        engine::Shader *ambiantShader = (engine::Shader *) (lm.getAmbiantShaderPtr().get());

        engine::rtype::PlayerManager &pm = engine::rtype::PlayerManager::getInstance();
        pm.removePlayer(0);

        ambiantShader->removeShaderedEntity(ent);
        textureShader->removeShaderedEntity(ent);


        drawable.shadered = false;
        alive.dead = true;
    }
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_PROJECTILE_ALLY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_PROJECTILE_ENEMY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();
    engine::rtype::PlayerManager &pm = engine::rtype::PlayerManager::getInstance();
    ecs::Alive &alive = coord.getComponent<ecs::Alive>(ent);
    ecs::Alive &aliveOther = coord.getComponent<ecs::Alive>(other);
    ecs::RLDrawable &drawable = coord.getComponent<ecs::RLDrawable>(ent);
    ecs::Hitbox &hitbox = coord.getComponent<ecs::Hitbox>(ent);

    if (hitbox.invFrames > 0) return;

    // std::cout << "collides" << ent << std::endl;
    hitbox.invFrames += 10;

    if (alive.shield == true) {
        alive.shield = false;
        ecs::Bonus &playerBonus = coord.getComponent<ecs::Bonus>(ent);

        auto it = playerBonus.bonus.find(ecs::BonusType::SHIELD_BONUS);
        if(it != playerBonus.bonus.end()) {
            ecs::Alive &aliveShield = coord.getComponent<ecs::Alive>(playerBonus.bonus[ecs::BonusType::SHIELD_BONUS]);
            aliveShield.dead = true;
            engine::LinkerEntities::getInstance().removeEntity(playerBonus.bonus[ecs::BonusType::SHIELD_BONUS]);
        }
        engine::LinkerEntities::getInstance().removeEntity(other);
        aliveOther.dead = true;

    }
    else {
        engine::LevelManager &lm = engine::LevelManager::getInstance();
        engine::Shader *textureShader = (engine::Shader *) (lm.getTextureShaderPtr().get());
        engine::Shader *ambiantShader = (engine::Shader *) (lm.getAmbiantShaderPtr().get());

        pm.removePlayer(0);


        ambiantShader->removeShaderedEntity(ent);
        textureShader->removeShaderedEntity(ent);

        drawable.shadered = false;
        alive.dead = true;
        aliveOther.dead = true;
    }
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_WALL>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // std::cout << "collison wall" << std::endl;
    ecs::Coordinator &coord = ecs::Coordinator::getInstance();

    ecs::Transform &trans = coord.getComponent<ecs::Transform>(ent);
    ecs::RigidBody &body  = coord.getComponent<ecs::RigidBody>(ent);
    ecs::Hitbox &box      = coord.getComponent<ecs::Hitbox>(ent);

    ecs::Hitbox &otrBox   = coord.getComponent<ecs::Hitbox>(other);

    engine::AShape rect = box.bounds->getCollisionRect(otrBox.bounds);
    // std::cout << "collisionRect = {" << rect.pos.x << ", " << rect.pos.y << ", " << rect.val.a << ", " << rect.val.b << "}" << std::endl;


    float sign = 0.0;
    // std::cout << "prev pos = {" << trans.position.x << ", " << trans.position.y << "}";
    if (rect.val.b < rect.val.a) {
        if (rect.pos.y > box.bounds->pos.y)
            sign = -1.0;
        else {
            sign = 1.0;
        }trans.position.y += (rect.val.b * sign);
    } else {
        if (rect.pos.x > box.bounds->pos.x)
            sign = -1.0;
        else {
            sign = 1.0;
        }
        trans.position.x += (rect.val.a * sign);
    }
    box.bounds->moveTo(trans.position);
    // std::cout << "\tnew pos = {" << trans.position.x << ", " << trans.position.y << "}" << std::endl;;


}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_PICKUP>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    engine::IBonus *bonus = static_cast<engine::IBonus *> (engine::GameEntities::getInstance().getEntity(other).get());

    // if (playerBonus.hasBonus == true) {
    //     engine::IBonus *oldBonus = static_cast<engine::IBonus *> (engine::GameEntities::getInstance().getEntity(playerBonus.bonus).get());
    //     oldBonus->remove();
    // }

    bonus->apply(ent);
    ecs::Coordinator::getInstance().addComponent(
        other,
        ecs::Temporary {
            .delay = 50,
            .done = false,
            .isBonus = true
    });

    // playerBonus.hasBonus = true;
    // playerBonus.bonus = other;

    ecs::Hitbox &hitbox = ecs::Coordinator::getInstance().getComponent<ecs::Hitbox>(other);
    // ecs::RLDrawable &draw = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(other);
    ecs::Coordinator::getInstance().removeComponent<ecs::RLDrawable>(other);
    hitbox.colType = ecs::CollisionType::COL_NONE;
    // draw.shadered = true;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_TRIGGER>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_SHIP_ALLY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Control &control = ecs::Coordinator::getInstance().getComponent<ecs::Control>(ent);
    ecs::Control &controlOther = ecs::Coordinator::getInstance().getComponent<ecs::Control>(other);
    if (controlOther.eventID == control.eventID && (event.playerEvents[controlOther.eventID].released & engine::INTERACT) == engine::INTERACT) {
        ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(other);
        if (controlOther.secondary == false) {
            anim.toSet = true;
            anim.setTo = {0, 1};
            controlOther.secondary = true;
        }
        else {
            anim.toSet = true;
            anim.setTo = {1, 1};
            controlOther.secondary = false;
        }
    }
}




//* ================================ Enemy ================================= *//

template <>
void engine::Collision::collides<ecs::CollisionType::COL_ENEMY, ecs::CollisionType::COL_PLAYER>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Alive &aliveOther = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(other);
    // aliveOther.dead = true;
    (void) ent;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_ENEMY, ecs::CollisionType::COL_PROJECTILE_ALLY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(ent);
    ecs::Transform &transform = ecs::Coordinator::getInstance().getComponent<ecs::Transform>(ent);
    ecs::Alive &aliveOther = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(other);
    engine::rtype::Destruction destroy(transform.position);
    // ecs::Coordinator::getInstance().destroyEntity();
    alive.dead = true;
    aliveOther.dead = true;
}


template <>
void engine::Collision::collides<ecs::CollisionType::COL_ENEMY, ecs::CollisionType::COL_WALL>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}

//* ========================== Enemy Projectiles =========================== *//

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PROJECTILE_ALLY, ecs::CollisionType::COL_PLAYER>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PROJECTILE_ALLY, ecs::CollisionType::COL_ENEMY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(ent);
    ecs::Alive &aliveOther = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(other);
    alive.dead = true;
    aliveOther.dead = true;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PROJECTILE_ALLY, ecs::CollisionType::COL_PROJECTILE_ENEMY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PROJECTILE_ALLY, ecs::CollisionType::COL_WALL>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(ent);
    alive.dead = true;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PROJECTILE_ALLY, ecs::CollisionType::COL_PICKUP>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}


//* ========================== Projectile Enemy =========================== *//
template <>
void engine::Collision::collides<ecs::CollisionType::COL_PROJECTILE_ENEMY, ecs::CollisionType::COL_PLAYER>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_PROJECTILE_ENEMY, ecs::CollisionType::COL_PROJECTILE_ALLY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    (void) ent;
    (void) other;
}

//* ============================== Ship Ally =============================== *//

template <>
void engine::Collision::collides<ecs::CollisionType::COL_SHIP_ALLY, ecs::CollisionType::COL_PLAYER>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    // Nothing
    engine::Collision::collides<ecs::CollisionType::COL_PLAYER, ecs::CollisionType::COL_SHIP_ALLY>(other, ent, event);
    // (void) ent;
    // (void) other;
}

template <>
void engine::Collision::collides<ecs::CollisionType::COL_WALL, ecs::CollisionType::COL_PROJECTILE_ALLY>(ecs::Entity ent, ecs::Entity other, ::engine::PollEvent &event) {
    ecs::Alive &alive = ecs::Coordinator::getInstance().getComponent<ecs::Alive>(other);
    alive.dead = true;
}

#include "GameEngine/CollisionMap.hpp"
//TODO: CHEYPE: DO NOT MOVE, otherwise "specialization after instantiation" error
//! FIXME: J'ai envie de casser un truc, vous dégoutez la vie


void engine::Collision::collide(::ecs::Entity ent, ::ecs::Entity other, int type, int otrType, ::engine::PollEvent &event) {
    if (engine::collisionMap.find({type, otrType}) != engine::collisionMap.end()) {
        engine::collisionMap.at({type, otrType})(ent, other, event);
    }
}
