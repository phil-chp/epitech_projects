/*
** EPITECH PROJECT, 2022
** B-YEP-400-NCE-4-1-indiestudio-anthony.ghizzo
** File description:
** Item
*/

#include "Item.hpp"


void ecs::Item::take(Entity ent) {
    this->taken = true;
    this->entity = ent;
}

//* --------------------------------- Items -------------------------------- *//

void ecs::Item::BombUpApply() {
    PlayerStat &stat = ecs::Coordinator::getInstance().getComponent<PlayerStat>(this->entity);

    if (stat.bombMax < 10) {
        stat.bombMax +=1;
    }
}

void ecs::Item::BombDownApply() {
    PlayerStat &stat = ecs::Coordinator::getInstance().getComponent<PlayerStat>(this->entity);

    if (stat.bombMax >= 2) {
        stat.bombMax -=1;
    }
}

void ecs::Item::FireUpApply() {
    PlayerStat &stat = ecs::Coordinator::getInstance().getComponent<PlayerStat>(this->entity);

    if (stat.fire < 5) {
        stat.fire +=1;
    }
}

void ecs::Item::FireDownApply() {
    PlayerStat &stat = ecs::Coordinator::getInstance().getComponent<PlayerStat>(this->entity);

    if (stat.fire >= 2) {
        stat.fire -=1;
    }
}

void ecs::Item::SpeedUpApply() {
    PlayerStat &stat = ecs::Coordinator::getInstance().getComponent<PlayerStat>(this->entity);

    if (stat.speedMax < 6) {
        stat.speedMax +=0.5;
    }
}

void ecs::Item::SpeedDownApply() {
    PlayerStat &stat = ecs::Coordinator::getInstance().getComponent<PlayerStat>(this->entity);

    if (stat.speedMax >= 3.5) {
        stat.speedMax -=0.5;
    }
}
