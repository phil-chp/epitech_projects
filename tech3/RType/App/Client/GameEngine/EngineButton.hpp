/*
** EPITECH PROJECT, 2022
** RType
** File description:
** EngineButton
*/

#ifndef ENGINEBUTTON_HPP_
    #define ENGINEBUTTON_HPP_

    #include "ECS/Entity.hpp"
    #include "GameEngine/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "Utils/PathBuilder.hpp"

namespace engine {

class Button : public Entity {
    Button() : Entity() {
        ::ecs::Coordinator::getInstance().addComponent(
            this->entity,
            ecs::Transform {
                .position = {800.0, 800.0},
                .rotation = 0.0,
                .scale = 1.0
            }
        );
        ::ecs::Coordinator::getInstance().addComponent(
            this->entity,
            ecs::RLDrawable {
                SpriteManager::getInstance().getData(SpriteType::SPR_BUTTON),
                false
            }
        );
        ecs::RLDrawable &drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
        drawable.setAnimate(game::Rect(0, 0, 120, 80));
        drawable.setScale(::game::Vector2(1.2, 1.2));

        ::ecs::Coordinator::getInstance().addComponent(
            this->entity,
            ecs::Button {
                .click = &Button::click,
                .hover = &Button::hover,
                .resetHover = &Button::resetHover,
                .next = this->entity,
                .isHover = false,
                .isClic =  false,
                .isEsc = false,
                .prev = this->entity,
                .dead = false,
                .listID = 0
            }
        );
    };
    public:

    static ::ecs::Entity construct() {
        Button button;
        return (button.entity);
    }
    static ::ecs::Entity click(ecs::Entity entity) {
        return ecs::MAX_ENTITIES;
    }
    static void resetHover(ecs::Entity entity) {
    }
    static void  hover(ecs::Entity entity) {
    }
};



} // namespace engine

#endif /* !ENGINEBUTTON_HPP_ */
