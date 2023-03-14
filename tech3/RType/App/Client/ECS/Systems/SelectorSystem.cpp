/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SelectorSystem
*/


#include "ECS/Systems/SelectorSystem.hpp"
#include "Utils/Vector2.hpp"
#include "GameEngine/RLEventHandler.hpp"



void ecs::SelectorSystem::update(::engine::PollEvent &event) const {
    for (ecs::Entity const &entity : this->entities) {
        Selector &selector = ecs::Coordinator::getInstance().getComponent<Selector>(entity);
        Control &control = ecs::Coordinator::getInstance().getComponent<Control>(entity);
        Button &button = ecs::Coordinator::getInstance().getComponent<Button>(selector.selected);
        if (button.isClic) {
            button.isClic = false;
            selector.selected = button.click(selector.selected);
            continue;
        }
        if (((event.playerEvents[control.eventID].pressed & engine::UP) == engine::UP) || ((event.playerEvents[control.eventID].pressed & engine::RIGHT) == engine::RIGHT)) {
            button = ecs::Coordinator::getInstance().getComponent<Button>(selector.selected);
            button.resetHover(selector.selected);
            selector.selected = button.next;
            Button &button2 = ecs::Coordinator::getInstance().getComponent<Button>(selector.selected);
            button2.hover(selector.selected);
        }
        else if (((event.playerEvents[control.eventID].pressed & engine::DOWN) == engine::DOWN) || ((event.playerEvents[control.eventID].pressed & engine::LEFT) == engine::LEFT)) {
            button = ecs::Coordinator::getInstance().getComponent<Button>(selector.selected);
            button.resetHover(selector.selected);
            selector.selected = button.prev;
            Button &button3 = ecs::Coordinator::getInstance().getComponent<Button>(selector.selected);
            button3.hover(selector.selected);
        }
        else if ((event.playerEvents[control.eventID].pressed & engine::SHOOT) == engine::SHOOT) {
            button = ecs::Coordinator::getInstance().getComponent<Button>(selector.selected);

            button.isClic = true;
        }
    }
}
