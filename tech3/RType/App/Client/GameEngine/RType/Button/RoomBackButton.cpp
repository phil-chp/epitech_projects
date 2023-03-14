/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RoomBackButton
*/


#include "GameEngine/RType/Button/RoomBackButton.hpp"
#include "GameEngine/RType/Button/PlayButton.hpp"
#include "GameEngine/RType/Button/SettingButton.hpp"
#include "GameEngine/EngineButton.hpp"
#include "GameEngine/Managers/GameManager.hpp"
#include "ECS/Systems/ButtonSystem.hpp"
#include "ECS/Systems/DrawTextSystem.hpp"
#include "GameEngine/Managers/FontManager.hpp"
#include "ECS/Components/RLText.hpp"

#include "ECS/Coordinator.hpp"


engine::rtype::RoomBackButton::RoomBackButton(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1, ::ecs::Entity first = ::ecs::MAX_ENTITIES + 1)
{

    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {1360.0, 700.0},
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
            // ::rl::Text(::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
            //     ::rl::Window::getInstance().getRenderer(),
            //     std::string("Back"),
            //     game::Vector2(1430, 785),
            //     {255, 255, 255, 255}),
            ::rl::Text("Back",
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                game::Vector2(1430, 760)),
            3
        )
    );
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &RoomBackButton::click,
            .hover = &RoomBackButton::hover,
            .resetHover = &RoomBackButton::resetHover,
            .next = first,
            .isHover = false,
            .isClic = false,
            .isEsc = true,
            .prev = prev,
            .dead = false,
            .listID = 3
        }

    );
    ecs::Entity ent = ::ecs::Coordinator::getInstance().createEntity();
    ::ecs::Coordinator::getInstance().addComponent(
        ent,
        ecs::Transform {
            .position = {800.0, 700.0},
            .rotation = 0.0,
            .scale = 1.0
        }
    );
    ::ecs::Coordinator::getInstance().addComponent(
        ent,
        ecs::RLText(
            ::rl::Text(
                std::string("Ip: "),
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                game::Vector2(800, 700)),
            3
        )
    );
}

::ecs::Entity engine::rtype::RoomBackButton::click(ecs::Entity entity)
{
    ecs::Entity ent = entity;
    bool dead = false;

    while(!dead) {
        ecs::Button &button = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent);
        button.dead = true;
        ent = button.next;
        dead = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent).dead;
    }
    for (ecs::Entity const &e : ecs::Coordinator::getInstance().getSystem(ecs::SysType::DRAW_TEXT_SYSTEM)->entities) {
        ecs::RLText &text = ecs::Coordinator::getInstance().getComponent<ecs::RLText>(e);
        if (text.listID > 2)
            text.dead = true;
    }

    return (engine::rtype::PlayButton::construct());
}

void engine::rtype::RoomBackButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 1};
}

void engine::rtype::RoomBackButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 0};
}
