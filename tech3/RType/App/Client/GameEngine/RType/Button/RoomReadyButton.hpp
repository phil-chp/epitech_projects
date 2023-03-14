/*
** EPITECH PROJECT, 2022
** RType
** File description:
** RoomReadyButton
*/

#ifndef ROOMREADYBUTTON_HPP_
#define ROOMREADYBUTTON_HPP_

    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/SpriteManager.hpp"
    #include "GameEngine/Managers/FontManager.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"


namespace engine {
    namespace rtype {
        class RoomReadyButton {
            private:
                RoomReadyButton();

                ::ecs::Entity entity;

            public:
                static ::ecs::Entity construct() {
                    RoomReadyButton button;
                    return (button.entity);
                }

                static ::ecs::Entity getEsc(ecs::Entity next) {
                    bool isEsc = false;
                    ::ecs::Entity tmp = next;

                    while (!isEsc) {
                        if (tmp == ::ecs::MAX_ENTITIES +1) {
                            std::cout << "Error: no ESC button found, never reached" << std::endl;
                            return tmp;
                        }
                        ::ecs::Button &button = ::ecs::Coordinator::getInstance().getComponent<::ecs::Button>(tmp);
                        if (button.isEsc) {
                            isEsc = true;
                            return (tmp);
                        }
                        tmp = button.next;
                    }

                    return (::ecs::MAX_ENTITIES + 1);
                }

                static ::ecs::Entity click(ecs::Entity);
                static void hover(ecs::Entity);
                static void resetHover(ecs::Entity);
        };
    };
};

#endif /* !ROOMREADYBUTTON_HPP_ */
