/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SpriteAnimation
*/

#include "ECS/Components/SpriteAnimation.hpp"

// template<>
// template<>
// ecs::SpriteAnimation::Animation(const ecs::SpriteAnimation &othr) {
//     this->current = othr.current;
//     this->delay = othr.delay;
//     this->actualDelay = othr.actualDelay;
//     this->object = othr.object;
//     this->max = othr.max;
//     this->container = othr.container;
// }

template<>
void ecs::SpriteAnimation::set(int n, unsigned int k)
{
    this->current.first = n;
    this->current.second = k;
}

template<>
void ecs::SpriteAnimation::advance()
{
    this->current.second++;
    this->current.second %= this->max[this->current.first];
}

// template<>
// ecs::SpriteAnimation ecs::SpriteAnimation::operator=(const ecs::SpriteAnimation &othr) {
//     this->current = othr.current;
//     this->delay = othr.delay;
//     this->actualDelay = othr.actualDelay;
//     this->object = othr.object;
//     this->max = othr.max;
//     this->container = othr.container;
//     return (*this);
// }
