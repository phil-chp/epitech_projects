/*
** EPITECH PROJECT, 2022
** RType
** File description:
** GridCell
*/

#include "GameEngine/GridCell.hpp"
#include "ECS/Coordinator.hpp"

void engine::GridCell::populate(std::shared_ptr<engine::AShape> hitbox, ecs::Entity entity) {
    // std::cout << "Cell surface {" << this->surface.pos.x << ", " << this->surface.pos.y << ", " << this->surface.val.a << ", " << this->surface.val.b << "}" << std::endl;
    if (this->surface.collides(hitbox)) {
        contains.push_back(entity);
        // std::cout << "Put entity " << entity << " in cell " << this->coord.x << ", " << this->coord.y << "}" << std::endl;
        // std::cout << "ent surface {" << hitbox->pos.x << ", " << hitbox->pos.y << ", " << hitbox->val.a << ", " << hitbox->val.b << "}" << std::endl;
        // std::cout << "Cell surface {" << this->surface.pos.x << ", " << this->surface.pos.y << ", " << this->surface.val.a << ", " << this->surface.val.b << "}" << std::endl;
    }
}

void engine::GridCell::checkCollisions() {
    // std::cout << "checkCollision" << std::endl;
    for (size_t i = 0; i < this->containerSize() - 1; ++i) {
        ecs::Hitbox &hitbox = ecs::Coordinator::getInstance().getComponent<ecs::Hitbox>(this->contains[i]);
        for (size_t j = i + 1; j < this->containerSize(); ++j) {
            ecs::Hitbox &othrHit = ecs::Coordinator::getInstance().getComponent<ecs::Hitbox>(this->contains[j]);
            if (hitbox.bounds->collides(othrHit.bounds)) {
                if (std::find(hitbox.collidesWith.begin(), hitbox.collidesWith.end(), this->contains[j])==hitbox.collidesWith.end())
                    hitbox.collidesWith.push_back(this->contains[j]);
                // othrHit.collidesWith.push_back(this->contains[i]);
                // std::cout << "hit between " << this->contains[j] << " and " << this->contains[i] << std::endl;
            }
        }
    }
}

size_t engine::GridCell::containerSize() const {
    return contains.size();
}
