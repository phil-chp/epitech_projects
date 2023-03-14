/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RLBackground
*/

#include "ECS/Components/RLBackground.hpp"

template<>
void ecs::RLBackground::draw(const game::Vector2 &position)
{
    _background.position = position;
    _background.draw();
}

template<>
void ecs::RLBackground::drawRec(const game::Vector2 &position)
{

    this->_background.position = position;
    this->_background.drawAnim();
}

template<>
void ecs::RLBackground::setSize(const game::Vector2 &size)
{
    _background.setSize(size);
}

template<>
const game::Vector2 ecs::RLBackground::getSize()
{
    return (::game::Vector2(_background.getWidth(), _background.getHeight()));
}
