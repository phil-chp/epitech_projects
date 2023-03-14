/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** Item
*/

#ifndef ITEM_HPP_
    #define ITEM_HPP_

    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "ECS/Components/Controlled.hpp"
    #include <memory>

namespace ecs {
    enum ItemType {
        // BONUS
        //                Normal
        BOMB_UP,                // Bombs (+1 bomb)
        SPEED_UP,               // Skates (+speed)
        FIRE_UP,                // Fire (+range)
        BOMB_DOWN,              // Bombs down (-1 bomb)
        SPEED_DOWN,             // Skates down (-speed)
        FIRE_DOWN,              // Sad fire (-range)

        KICK,                   // Kick (Kick bombs/items down a lane)
        BOX_GLOVE,              // Boxing glove (Kick bombs/items down a lane above crates)
        BLUE_GLOVE,             // Blue glove (Pick up bombs and throw them)
        //                  Rare
        BOMB_PASS,              // Bomb pass (Pass trough bombs)
        FIRE_PASS,              // Fire pass (Explosions don't damage you for n hits)
        DETONATOR,              // Detonator (detonate bombs at will, special bomb skin)
        KAMIKAZE,               // Kamikaze (Explode with current modifiers when you die)
        PENETRATION,            // Penetration (Explosion doesn't stop at first contact)
        //             Legendary
        FIRE_MAX,               // Full fire (max range)
        WALL_PASS,              // Wall pass (Pass trough crates)
        INVINCIBLE,             // Invincibility (for n seconds, rainbow sprite)
        BOMB_POWER,             // Power Bomb (single use, bomb with max range)
        // MALUS
        //                Normal
        //                  Rare
        SKULL                   // Skull (Place bombs constantly if/when posible)
    };

    struct Item {
        explicit Item(ItemType type = BOMB_UP) : type(type) , taken(false), entity(MAX_ENTITIES + 1)
        {
            switch (type) {
                case BOMB_UP:
                    this->name = "BombUp!";
                    this->apply = &ecs::Item::BombUpApply;
                    break;
                case BOMB_DOWN:
                    this->name = "BombDown";
                    this->apply = &ecs::Item::BombDownApply;
                    break;
                case SPEED_UP:
                    this->name = "SpeedUp!";
                    this->apply = &ecs::Item::SpeedUpApply;
                    break;
                case SPEED_DOWN:
                    this->name = "SpeedDown";
                    this->apply = &ecs::Item::SpeedDownApply;
                    break;
                case FIRE_UP:
                    this->name = "FireUp!";
                    this->apply = &ecs::Item::FireUpApply;
                    break;
                case FIRE_DOWN:
                    this->name = "FireDown";
                    this->apply = &ecs::Item::FireDownApply;
                    break;
                default:
                    this->name = "BombUp";
                    this->apply = &ecs::Item::BombUpApply;
                    break;
            }
        }

        void take(Entity ent);
        void dump() {
            if (this->taken) {
                std::cout << "Item: " << this->name << " taken by entity: " << this->entity << "." << std::endl;
            } else {
                std::cout << "item: " << this->name << " not taken." << std::endl;
            }
        }
        void applyEffect() {
            if (this->apply){
                (this->*apply)();
            }
        }

        std::string name;
        ItemType type;
        bool taken;
        Entity entity;
        void (ecs::Item::*apply)();

        void BombUpApply();
        void BombDownApply();
        void FireUpApply();
        void FireDownApply();
        void SpeedUpApply();
        void SpeedDownApply();
    };
}

#endif /* !ITEM_HPP_ */
