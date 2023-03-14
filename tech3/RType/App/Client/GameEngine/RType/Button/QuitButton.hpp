/*
** EPITECH PROJECT, 2022
** RType
** File description:
** QuitButton
*/

#ifndef QUITBUTTON_HPP_
    #define QUITBUTTON_HPP_

    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"


namespace engine {
    namespace rtype {
        class QuitButton {
            private:
                QuitButton(::ecs::Entity, ::ecs::Entity);
                ::ecs::Entity entity;

            public:
                static ::ecs::Entity construct(::ecs::Entity prev = ::ecs::MAX_ENTITIES + 1, ::ecs::Entity first = ::ecs::MAX_ENTITIES + 1) {
                    QuitButton button(prev, first);
                    return (button.entity);
                }

                static ::ecs::Entity click(ecs::Entity entity);
                static void hover(ecs::Entity);
                static void resetHover(ecs::Entity);

        };
    };
};

#endif
