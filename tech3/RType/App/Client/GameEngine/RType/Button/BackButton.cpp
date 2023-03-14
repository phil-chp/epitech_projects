/*
** EPITECH PROJECT, 2022
** RType
** File description:
** BackButton
*/


#include "GameEngine/RType/Button/BackButton.hpp"
#include "GameEngine/RType/Button/PlayButton.hpp"
#include "GameEngine/RType/Button/SettingButton.hpp"
#include "GameEngine/EngineButton.hpp"
#include "GameEngine/Managers/GameManager.hpp"
#include "GameEngine/Managers/FontManager.hpp"

#include "ECS/Systems/ButtonSystem.hpp"
#include "ECS/Coordinator.hpp"




engine::rtype::BackButton::BackButton(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1, ::ecs::Entity first = ::ecs::MAX_ENTITIES + 1)
{
    this->entity = ::ecs::Coordinator::getInstance().createEntity();
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Transform {
            .position = {1360.0, 500.0},
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
    // ecs::RLDrawable &draw = ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(this->entity);
    // draw.setSize(game::Vector2(117, 79));
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
            ::rl::Text(std::string("Back"),
                ::rl::Font(FontManager::getInstance().getData(FontType::FONT_BOLD)),
                35,
                ::rl::Color(255, 255, 255, 255),
                ::rl::Vector2(1440, 560)),
            1
        )
    );
    ::ecs::Coordinator::getInstance().addComponent(
        this->entity,
        ecs::Button {
            .click = &BackButton::click,
            .hover = &BackButton::hover,
            .resetHover = &BackButton::resetHover,
            .next = first,
            .isHover = false,
            .isClic = false,
            .isEsc = true,
            .prev = prev,
            .dead = false,
            .listID = 1
        }

    );
}

::ecs::Entity engine::rtype::BackButton::click(ecs::Entity entity)
{
    ecs::Entity ent = entity;
    bool dead = false;

    while(!dead) {
        ecs::Button &button = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent);
        button.dead = true;
        ent = button.next;
        dead = ecs::Coordinator::getInstance().getComponent<ecs::Button>(ent).dead;
    }
    ecs::Entity back = ::ecs::MAX_ENTITIES + 1;
    for (ecs::Entity const &e : ecs::Coordinator::getInstance().getSystem(ecs::SysType::BUTTON_SYSTEM)->entities) {
        ecs::Button &butt = ecs::Coordinator::getInstance().getComponent<ecs::Button>(e);
        ecs::SpriteAnimation &anim = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(e);
        if (butt.listID == 0) {
            anim.toSet = true;
            anim.setTo = {0 , 0};
            back = e;
        }
    }
    ecs::SpriteAnimation &animate = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(back);
    animate.toSet = true;
    animate.setTo = {0 , 1};
    if (back < ::ecs::MAX_ENTITIES)
       return back;
    else
        return (engine::rtype::PlayButton::construct());
}

void engine::rtype::BackButton::hover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 1};
}

void engine::rtype::BackButton::resetHover(ecs::Entity entity)
{
    ecs::SpriteAnimation &animation = ecs::Coordinator::getInstance().getComponent<ecs::SpriteAnimation>(entity);

    animation.toSet = true;
    animation.setTo = {0, 0};
}
