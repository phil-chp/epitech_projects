/*
** EPITECH PROJECT, 2022
** RType
** File description:
** JoinButton
*/

#include "GameEngine/RType/Button/JoinButton.hpp"
#include "GameEngine/RType/Button/HostButton.hpp"
#include "GameEngine/RType/Button/RoomReadyButton.hpp"


#include "GameEngine/RType/Button/MultiButton.hpp"
#include "GameEngine/RType/Button/SettingButton.hpp"
#include "GameEngine/RType/Button/QuitButton.hpp"
#include "GameEngine/EngineButton.hpp"
#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"


engine::rtype::JoinButton::JoinButton()
{
    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ecs::Entity next = HostButton::construct(this->entity);
    ecs::Entity prev = JoinButton::getEsc(next);

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {350.0, 800.0},
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
            ::rl::Text("Join",
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                ::rl::Vector2(430, 860)),
            2
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
    anim.setTo = {0,1};
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        anim
    );
    // ecs::RLText &Text = ecs::Coordinator::getInstance().getComponent<ecs::RLText>(entity);
    // Text.setText("PLAY", "Assets/Fonts/Digital-Serial-Bold.ttf", 30, {255, 255, 255});

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &JoinButton::click,
            .hover = &JoinButton::hover,
            .resetHover = &JoinButton::resetHover,
            .next = next,
            .isHover = false,
            .isClic =  false,
            .isEsc = false,
            .prev = prev,
            .dead = false,
            .listID = 2
        }
    );

}

::ecs::Entity engine::rtype::JoinButton::click(ecs::Entity entity)
{
    std::string ip;
    std::cout << "Enter an Ip of a room: ";
    std::cin >> ip;

    ecs::Entity ent = entity;
    bool dead = false;
    for (ecs::Entity const &e : ecs::Coordinator::getInstance().getSystem(ecs::SysType::BUTTON_SYSTEM)->entities) {
        ecs::Button &butt = ecs::Coordinator::getInstance().getComponent<ecs::Button>(e);
        if (butt.listID < 3) {
            butt.dead = true;
        }
    }

    return (engine::rtype::RoomReadyButton::construct());
}


void engine::rtype::JoinButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 1};
}

void engine::rtype::JoinButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 0};
}
