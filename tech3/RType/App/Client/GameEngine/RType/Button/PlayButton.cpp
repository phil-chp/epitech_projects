/*
** EPITECH PROJECT, 2022
** RType
** File description:
** PlayButton
*/

#include "GameEngine/RType/Button/PlayButton.hpp"
#include "GameEngine/RType/Button/SettingButton.hpp"
#include "GameEngine/RType/Button/SoloButton.hpp"
#include "GameEngine/RType/Button/QuitButton.hpp"
#include "GameEngine/EngineButton.hpp"
#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"


engine::rtype::PlayButton::PlayButton()
{
    // this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ecs::Entity next = SettingButton::construct(this->entity);
    ecs::Entity prev = PlayButton::getEsc(next);

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {360.0, 200.0},
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
            ::rl::Text("Play",
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                ::rl::Vector2(440, 260)),
            0
        )
    );
    // ecs::RLText &text = ecs::Coordinator::getInstance().getComponent<ecs::RLText>(entity);
    // text.position = ::game::Vector2(460, 305);


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
    anim.setTo = {0, 1};
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        anim
    );
    // ecs::RLText &Text = ecs::Coordinator::getInstance().getComponent<ecs::RLText>(entity);
    // Text.setText("PLAY", "Assets/Fonts/Digital-Serial-Bold.ttf", 30, {255, 255, 255});

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &PlayButton::click,
            .hover = &PlayButton::hover,
            .resetHover = &PlayButton::resetHover,
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

::ecs::Entity engine::rtype::PlayButton::click(ecs::Entity entity)
{
    ecs::Entity ent = entity;
    for (int i = 0; i != 3; i++) {
        ecs::Button &button = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent);
        ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(ent);
        anim.toSet = true;
        anim.setTo = {1, 1};

        ent = button.next;
    }

    return (::engine::rtype::SoloButton::construct());
    // ecs::Entity ent = entity;
    // bool esc = false;
    // // while(!dead) {
    // //     ecs::Button &button = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent);
    // //     std::cout << "me " << ent << ", next " << button.next << std::endl;
    // //     button.dead = true;
    // //     ent = button.next;
    // //     dead = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent).dead;
    // // }
    // while(!esc) {
    //     ecs::Button &button = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent);
    //     ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(ent);
    //     anim.toSet = true;
    //     anim.setTo = {1, 1};

    //     ent = button.next;
    //     esc = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent).isEsc;
    // }
    // ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(ent);
    // anim.toSet = true;
    // anim.setTo = {1, 1};
    // return (::engine::rtype::SoloButton::construct());
}


void engine::rtype::PlayButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 1};
}

void engine::rtype::PlayButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 0};
}
