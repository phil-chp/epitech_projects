/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RLDrawable
*/

#include "ECS/Components/RLDrawable.hpp"


template<>
void ecs::RLDrawable::drawRec(const game::Vector2 &position)
{
    this->_drawable.position = position;
    this->_drawable.drawAnim();
}

template<>
void ecs::RLDrawable::draw(const game::Vector2 &position)
{
    this->_drawable.position = position;
    this->_drawable.draw();
}


template<>
void ecs::RLDrawable::setScale(const game::Vector2 &scale)
{
    _drawable.setScale(scale);
}

template<>
const game::Vector2 ecs::RLDrawable::getScale()
{
    rl::Vector2 scale = _drawable.getScale();
    return (game::Vector2(scale.x, scale.y));
}

template<>
void ecs::RLDrawable::setAnimate(const game::Rect &animate)
{
    _drawable.animRect = animate;
}

template<>
const game::Rect ecs::RLDrawable::getAnimate()
{
    return (_drawable.animRect);
}

template<>
void ecs::RLDrawable::setSize(const game::Vector2 &size)
{
    _drawable.setSize(size);
}

template<>
const game::Vector2 ecs::RLDrawable::getSize()
{
    return (::game::Vector2(_drawable.getWidth(), _drawable.getHeight()));
}
