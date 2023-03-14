/*
** EPITECH PROJECT, 2022
** RType
** File description:
** QuitButton
*/

#include "GameEngine/RType/Button/QuitButton.hpp"
#include "GameEngine/RType/Button/PlayButton.hpp"
#include "GameEngine/RType/Button/SettingButton.hpp"
#include "GameEngine/EngineButton.hpp"
#include "GameEngine/Managers/GameManager.hpp"
#include "GameEngine/Managers/FontManager.hpp"



engine::rtype::QuitButton::QuitButton(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1, ::ecs::Entity first = ::ecs::MAX_ENTITIES + 1)
{
    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {1360.0, 200.0},
            .rotation = 0.0,
            .scale = 1.0
        }
    );
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::RLDrawable {
            SpriteManager::getInstance().getData(SpriteType::SPR_BUTTON), false
        }
    );
    ecs::RLDrawable &Drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
    Drawable._drawable.setSize(::game::Vector2(Drawable._drawable.getSize() * 2.0));
    ecs::SpriteAnimation anim;
    anim.max = {{0, 2}, {1, 2}};
    anim.container = {
        {0, {game::Rect(0, 0, 234, 158), game::Rect(0, 158, 234, 158)}},
        {1, {game::Rect(234, 0, 234, 158), game::Rect(234, 158, 234, 158)}}
    };
    anim.current = {0, 0};
    anim.delay = 0.2;
    anim.actualDelay = 0.2;
    anim.fix = true;
    anim.toSet = true;
    anim.setTo = {0 , 0};
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        anim
    );

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::RLText(
            ::rl::Text("Quit",
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                rl::Color(255, 255, 255, 255),
                game::Vector2(1442, 260)),
            0
        )
    );
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &QuitButton::click,
            .hover = &QuitButton::hover,
            .resetHover = &QuitButton::resetHover,
            .next = first,
            .isHover = false,
            .isClic = false,
            .isEsc = true,
            .prev = prev,
            .dead = false,
            .listID = 0
        }

    );
}

::ecs::Entity engine::rtype::QuitButton::click(ecs::Entity entity)
{
    engine::GameManager::getInstance()._quit = true;
    return entity;
}

void engine::rtype::QuitButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 1};
}

void engine::rtype::QuitButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 0};
}
