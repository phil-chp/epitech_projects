/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RoomReadyButton
*/

#include "GameEngine/RType/Button/RoomReadyButton.hpp"
#include "GameEngine/RType/Button/RoomBackButton.hpp"
#include "GameEngine/RType/Button/MultiButton.hpp"
#include "GameEngine/RType/Button/SettingButton.hpp"
#include "GameEngine/RType/Button/QuitButton.hpp"
#include "GameEngine/EngineButton.hpp"
#include "GameEngine/Managers/FontManager.hpp"
#include "GameEngine/Managers/GameManager.hpp"
#include "Lib/Raylib/rl-cpp/Texts/Texts.hpp"


engine::rtype::RoomReadyButton::RoomReadyButton()
{
    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ecs::Entity next = RoomBackButton::construct(this->entity, this->entity);
    ecs::Entity prev = RoomReadyButton::getEsc(next);

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {750.0, 200.0},
            .rotation = 0.0,
            .scale = 1.0
        }
    );
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::RLDrawable {
            SpriteManager::getInstance().getData(SpriteType::READY_BUTTON)
        }
    );
    ecs::RLDrawable &Drawable = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
    // Drawable._drawable.setSize(Drawable._drawable.getSize())
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::RLText(
            ::rl::Text("Player 1",
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                ::rl::Vector2(880, 200)),
            3
        )
    );

    ecs::SpriteAnimation anim;
    anim.max = {{0, 3}};
    anim.container = {
        {0, {game::Rect(0, 0, 70, 70), game::Rect(64, 0, 70, 70), game::Rect(132, 0, 70, 70)}},
    };
    anim.current = {0, 0};
    anim.delay = 0.2;
    anim.actualDelay = 0.2;
    anim.fix = true;
    anim.toSet = true;
    anim.setTo = {0 ,0};
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        anim
    );
    // ecs::RLText &Text = ecs::Coordinator::getInstance().getComponent<ecs::RLText>(entity);
    // Text.setText("PLAY", "Assets/Fonts/Digital-Serial-Bold.ttf", 30, {255, 255, 255});

    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &RoomReadyButton::click,
            .hover = &RoomReadyButton::hover,
            .resetHover = &RoomReadyButton::resetHover,
            .next = next,
            .isHover = false,
            .isClic =  false,
            .isEsc = false,
            .prev = prev,
            .dead = false,
            .listID = 3
        }
    );

}

::ecs::Entity engine::rtype::RoomReadyButton::click(ecs::Entity entity)
{
    static bool switched = false;
    ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);
    anim.toSet = true;
    if (anim.current.second < anim.max[anim.current.first] - 1) {
        anim.setTo = {anim.current.first, anim.current.second + 1};
    } else if (!switched) {
        // engine::GameManager::getInstance().pushWindow(WindowState::GAME);
        switched = true;
    }


    return entity;
}


void engine::rtype::RoomReadyButton::hover(ecs::Entity entity)
{
    ecs::RLDrawable &draw = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
    draw.setScale(::game::Vector2(1.1, 1.1));

}

void engine::rtype::RoomReadyButton::resetHover(ecs::Entity entity)
{
    ecs::RLDrawable &draw = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);

    draw.setScale(::game::Vector2(1.0, 1.0));
}
