/*
** EPITECH PROJECT, 2022
** RType
** File description:
** MultiButton
*/


#include "GameEngine/RType/Button/MultiButton.hpp"
#include "GameEngine/RType/Button/JoinButton.hpp"
#include "GameEngine/RType/Button/SoloButton.hpp"
#include "GameEngine/RType/Button/QuitButton.hpp"
#include "GameEngine/RType/Button/BackButton.hpp"
#include "GameEngine/Managers/FontManager.hpp"
#include "GameEngine/EngineButton.hpp"
#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"


engine::rtype::MultiButton::MultiButton(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1)
{
    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ecs::Entity next = engine::rtype::BackButton::construct(this->entity, prev);
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {855.0, 500.0},
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
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::RLText(
            ::rl::Text("Multi",
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                ::rl::Vector2(935, 560)),
            1
        )
    );
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
    anim.setTo = {0,0};
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        anim
    );
    // ecs::RLText &Text = ecs::Coordinator::getInstance().getComponent<ecs::RLText>(entity);
    // Text.setText("Multis", "Assets/Fonts/Digital-Serial-Bold.ttf", 30, {255, 255, 255});

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &MultiButton::click,
            .hover = &MultiButton::hover,
            .resetHover = &MultiButton::resetHover,
            .next = next,
            .isHover = false,
            .isClic =  false,
            .isEsc = false,
            .prev = prev,
            .dead = false,
            .listID = 1
        }
    );
}

::ecs::Entity engine::rtype::MultiButton::click(ecs::Entity entity)
{
    ecs::Entity ent = entity;
    for (int i = 0; i != 3; i++) {
        ecs::Button &button = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent);
        ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(ent);
        anim.toSet = true;
        anim.setTo = {1, 1};

        ent = button.next;
    }
    return (::engine::rtype::JoinButton::construct());
    // return (entity);
}


void engine::rtype::MultiButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 1};
}

void engine::rtype::MultiButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 0};
}
