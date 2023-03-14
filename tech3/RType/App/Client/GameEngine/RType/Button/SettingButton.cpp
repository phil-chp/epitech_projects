/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SettingButton
*/


#include "GameEngine/RType/Button/SettingButton.hpp"
#include "GameEngine/RType/Button/PlayButton.hpp"
#include "GameEngine/RType/Button/QuitButton.hpp"
#include "GameEngine/EngineButton.hpp"
#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"


engine::rtype::SettingButton::SettingButton(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1)
{
    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ecs::Entity next = QuitButton::construct(this->entity, prev);
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {855.0, 200.0},
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
            ::rl::Text("Settings",
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                ::rl::Vector2(898, 260)),
            0
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
    // Text.setText("Settings", "Assets/Fonts/Digital-Serial-Bold.ttf", 30, {255, 255, 255});

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &SettingButton::click,
            .hover = &SettingButton::hover,
            .resetHover = &SettingButton::resetHover,
            .next = next,
            .isHover = false,
            .isClic =  false,
            .isEsc = false,
            .prev = prev,
            .dead = false,
            .listID = 0
        }

    );
}

::ecs::Entity engine::rtype::SettingButton::click(ecs::Entity entity)
{
    // ecs::Entity ent = entity;
    // bool dead = false;
    // while(!dead) {
    //     ecs::Button &button = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent);
    //     std::cout << "me " << ent << ", next " << button.next << std::endl;
    //     button.dead = true;
    //     ent = button.next;
    //     dead = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent).dead;
    // }
    // return (::engine::Button::construct());
    std::cout << "Settings" << std::endl;
    return (entity);
}


void engine::rtype::SettingButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 1};
}

void engine::rtype::SettingButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 0};
}
