/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** GameManager
*/

#include "GameManager.hpp"

// INIT ------------------------------------------------------------------------

std::array<bool, 4> _players = {false, true, true, true};
rl::Vector2 const &screenSize = {
    float(rl::Window::getInstance().getWidth()),
    float(rl::Window::getInstance().getHeight())
};

void GameManager::initMenu()
{
    rl::Vector2 buttonSize(262.0f, 106.0f);
    //TODO: implement
    //buttonSize.scale(3.0f);
    ecs::Entity entity;

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::TextureWidget {
            .texture = rl::Texture(rl::TextureManager::getInstance().getData(rl::TEXTURE_TITLE))
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 2.0f - 922 / 2, screenSize.y / 2.0f - 413 / 2 - 250),
            .rotation = rl::Vector2(0, 0)
    });

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ButtonWidget {
            .content = "Play",
            .type = ecs::buttonType::PLAY,
            .clicked = false,
            .released = false,
            .hover = false,
            .action = []() {
                GameManager::getInstance().pushWindow(WindowState::PLAYER_SELECT);
            }
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 2.0f - buttonSize.x / 2.0f, screenSize.y / 2.0f - buttonSize.y / 2.0f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(buttonSize)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::DrawableButtonWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ButtonWidget{
            .content = "Settings",
            .type = ecs::buttonType::SETTINGS,
            .clicked = false,
            .released = false,
            .hover = false,
            .action = []() {
                GameManager::getInstance().pushWindow(WindowState::SETTINGS);
            }
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 2.0f - buttonSize.x / 2.0f, screenSize.y / 2.0f - buttonSize.y / 2.0f + buttonSize.y * 1.5f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(buttonSize)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::DrawableButtonWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ButtonWidget{
            .content = "Exit",
            .type = ecs::buttonType::QUIT,
            .clicked = false,
            .released = false,
            .hover = false,
            .action = []() {
                // rl::Window::getInstance().close();
                rl::Window::getInstance().exit();
            }
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 2.0f - buttonSize.x / 2.0f, screenSize.y / 2.0f - buttonSize.y / 2.0f + buttonSize.y * 3.0f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(buttonSize)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::DrawableButtonWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Parallax{
            .scrollingBack = 0.0f,
            .scrollingMid = 0.0f,
            .scrollingFore = 0.0f
    });
}

void GameManager::initPlayerSelect()
{
    rl::Vector2 const &buttonSize = { 300.0f, 450.0f };
    ecs::Entity entity;

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::PlayerWidget{
            .keys = {
                SettingsManager::getInstance().getPlayersKey()[0][KEY_P_UP],
                SettingsManager::getInstance().getPlayersKey()[0][KEY_P_DOWN],
                SettingsManager::getInstance().getPlayersKey()[0][KEY_P_LEFT],
                SettingsManager::getInstance().getPlayersKey()[0][KEY_P_RIGHT]
            },
            .indexPlayerColor = 0,
            .playerColor = rl::RL_WHITE,
            .mode = LOGOUT,
            .content = "P1?",
            .scrollingBack = 0.0f,
            .scrollingMid = 0.0f,
            .scrollingFore = 0.0f,
            .action = []() {
                std::cout << "P1" << std::endl;
            }
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 5.0f - buttonSize.x / 2.0f, screenSize.y / 2.0f - buttonSize.y / 2.0f - buttonSize.y / 5.0f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(buttonSize)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::DrawablePlayerWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::PlayerWidget{
            .keys = {
                SettingsManager::getInstance().getPlayersKey()[1][KEY_P_UP],
                SettingsManager::getInstance().getPlayersKey()[1][KEY_P_DOWN],
                SettingsManager::getInstance().getPlayersKey()[1][KEY_P_LEFT],
                SettingsManager::getInstance().getPlayersKey()[1][KEY_P_RIGHT]
            },
            .indexPlayerColor = 1,
            .playerColor = rl::RL_BLACK,
            .mode = LOGOUT,
            .content = "P2?",
            .scrollingBack = 0.0f,
            .scrollingMid = 0.0f,
            .scrollingFore = 0.0f,
            .action = []() {
                std::cout << "P2" << std::endl;
                if (_players[1] == true)
                    _players[1] = false;
                else
                    _players[1] = true;
            }
    });

    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 5.0f * 2.0f - buttonSize.x / 2.0f, screenSize.y / 2.0f - buttonSize.y / 2.0f - buttonSize.y / 5.0f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(buttonSize)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::DrawablePlayerWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::PlayerWidget{
                .keys = {
                    SettingsManager::getInstance().getPlayersKey()[2][KEY_P_UP],
                    SettingsManager::getInstance().getPlayersKey()[2][KEY_P_DOWN],
                    SettingsManager::getInstance().getPlayersKey()[2][KEY_P_LEFT],
                    SettingsManager::getInstance().getPlayersKey()[2][KEY_P_RIGHT]
                },
                .indexPlayerColor = 2,
                .playerColor = rl::RL_RED,
                .mode = LOGOUT,
                .content = "P3?",
                .scrollingBack = 0.0f,
                .scrollingMid = 0.0f,
                .scrollingFore = 0.0f,
                .action = []() {
                    std::cout << "P3" << std::endl;
                    if (_players[2] == true)
                        _players[2] = false;
                    else
                        _players[2] = true;
                }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                .position = rl::Vector2(screenSize.x / 5.0f * 3.0f - buttonSize.x / 2.0f, screenSize.y / 2.0f - buttonSize.y / 2.0f - buttonSize.y / 5.0f),
                .rotation = rl::Vector2(0, 0),
                .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawablePlayerWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::PlayerWidget{
                .keys = {
                    SettingsManager::getInstance().getPlayersKey()[3][KEY_P_UP],
                    SettingsManager::getInstance().getPlayersKey()[3][KEY_P_DOWN],
                    SettingsManager::getInstance().getPlayersKey()[3][KEY_P_LEFT],
                    SettingsManager::getInstance().getPlayersKey()[3][KEY_P_RIGHT]
                },
                .indexPlayerColor = 3,
                .playerColor = rl::RL_GREEN,
                .mode = LOGOUT,
                .content = "P4?",
                .scrollingBack = 0.0f,
                .scrollingMid = 0.0f,
                .scrollingFore = 0.0f,
                .action = []() {
                    std::cout << "P4" << std::endl;
                    if (_players[3] == true)
                        _players[3] = false;
                    else
                        _players[3] = true;
                }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                .position = rl::Vector2(screenSize.x / 5.0f * 4.0f - buttonSize.x / 2.0f,
                                        screenSize.y / 2.0f - buttonSize.y / 2.0f - buttonSize.y / 5.0f),
                .rotation = rl::Vector2(0, 0),
                .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawablePlayerWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Parallax{
            .scrollingBack = 0.0f,
            .scrollingMid = 0.0f,
            .scrollingFore = 0.0f
    });

    // TODO: to remove, this is not how you access the game
    // placeholder for testing
    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ButtonWidget{
            .content = "Play",
            .type = ecs::buttonType::PLAY,
            .clicked = false,
            .released = false,
            .hover = false,
            .action = []() {
                GameManager::getInstance().pushWindow(WindowState::GAME);
            }
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 5.0f * 4.0f - 150.0f,
                                    screenSize.y / 2.0f - 150.0f / 2.0f + 300.0f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(300.0f, 150.0f)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::DrawableButtonWidget()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ButtonWidget{
            .content = "back",
            .type = ecs::buttonType::DEFAULT,
            .clicked = false,
            .released = false,
            .hover = false,
            .action = []() {
                GameManager::getInstance().pushWindow(WindowState::MENU);
            }
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 5.0f - 150.0f,
                                    screenSize.y / 2.0f - 150.0f / 2.0f + 300.0f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(300.0f, 150.0f)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::DrawableButtonWidget()
    );
}

//void GameManager::initMapSelect() {
//     // rl::Vector2 const &screenSize = {
//     //         float(rl::Window::getInstance().getWidth()),
//     //         float(rl::Window::getInstance().getHeight())
//     // };
//     rl::Vector2 const &buttonSize = { 1400.0f, 800.0f };
//     ecs::Entity entity;

//     entity = ecs::Coordinator::getInstance().createEntity();
//     ecs::Coordinator::getInstance().addComponent(
//             entity,
//             ecs::MapWidget {
//                     .keys = {
//                             KEY_Z,
//                             KEY_S,
//                             KEY_Q,
//                             KEY_D
//                     },
//                     .indexMapColor = 0,
//                     .mapColor = rl::RL_PURPLE,
//                     .mode = LOGIN,
//                     .content = "MAP",
//                     .action = []() {
//                         std::cout << "MAP" << std::endl;
//                     }
//             });
//     ecs::Coordinator::getInstance().addComponent(
//             entity,
//             ecs::Transform2D{
//                     .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2), rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2)),
//                     .rotation = rl::Vector2(0, 0),
//                     .scale = rl::Vector2(buttonSize)
//             });
//     ecs::Coordinator::getInstance().addComponent(
//             entity,
//             ecs::DrawableMapWidget()
//     );

    // entity = ecs::Coordinator::getInstance().createEntity();
    // ecs::Coordinator::getInstance().addComponent(
    //     entity,
    //     ecs::Parallax{
    //         .scrollingBack = 0.0f,
    //         .scrollingMid = 0.0f,
    //         .scrollingFore = 0.0f
    // });
// }

void GameManager::initSettings() {
    rl::Vector2 const &buttonSize = { 100.0f, 100.0f };
    ecs::Entity entity;

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                .type = ecs::KEY,
                .indexPlayer = 0,
                .indexKey = 0,
                .isPressed = false,
                .key = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_UP],
                .content = "UP",
                .action = []() {
                    std::cout << "UP" << std::endl;
                }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2), rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 106.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::KEY,
                    .indexPlayer = 0,
                    .indexKey = 1,
                    .isPressed = false,
                    .key = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_DOWN],
                    .content = "DOWN",
                    .action = []() {
                        std::cout << "DOWN" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2), rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 206.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::KEY,
                    .indexPlayer = 0,
                    .indexKey = 2,
                    .isPressed = true,
                    .key = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_LEFT],
                    .content = "LEFT",
                    .action = []() {
                        std::cout << "LEFT" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) - 106.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 206.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::KEY,
                    .indexPlayer = 0,
                    .indexKey = 3,
                    .isPressed = false,
                    .key = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_RIGHT],
                    .content = "RIGHT",
                    .action = []() {
                        std::cout << "RIGHT" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) + 106.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 206.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );
    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::KEY,
                    .indexPlayer = 0,
                    .indexKey = 4,
                    .isPressed = false,
                    .key = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_BOMB],
                    .content = "BOMB",
                    .action = []() {
                        std::cout << "BOMB" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) + 106.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 106.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::PLAYER_SELECT,
                    .indexPlayer = 0,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "PLAYER 1",
                    .action = []() {
                        std::cout << "PLAYER 1" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) - 97.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 110.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
   );

    // entity = ecs::Coordinator::getInstance().createEntity();

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ButtonWidget{
            .content = "Back",
            .type = ecs::buttonType::DEFAULT,
            .clicked = false,
            .released = false,
            .hover = false,
            .action = []() {
                GameManager::getInstance().popWindow();
            }
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Transform2D{
            .position = rl::Vector2(screenSize.x / 5.0f * 4.0f - 150.0f,
                                    screenSize.y / 2.0f - 150.0f / 2.0f + 300.0f),
            .rotation = rl::Vector2(0, 0),
            .scale = rl::Vector2(300.0f, 150.0f)
    });
    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ControlWidget {
            .type = ecs::PLAYER_SELECT,
            .indexPlayer = 1,
            .indexKey = 99,
            .isPressed = false,
            .key = rl::KEY_NULL,
            .content = "PLAYER 2",
            .action = []() {
                std::cout << "PLAYER 2" << std::endl;
            }
    });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) + 6.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 110.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::Parallax{
            .scrollingBack = 0.0f,
            .scrollingMid = 0.0f,
            .scrollingFore = 0.0f
    });
    ecs::Coordinator::getInstance().addComponent(
        entity,
        ecs::ControlWidget {
                .type = ecs::PLAYER_SELECT,
                .indexPlayer = 2,
                .indexKey = 99,
                .isPressed = false,
                .key = rl::KEY_NULL,
                .content = "PLAYER 3",
                .action = []() {
                    std::cout << "PLAYER 3" << std::endl;
                }
        });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) + 106.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 110.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );
    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::PLAYER_SELECT,
                    .indexPlayer = 3,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "PLAYER 4",
                    .action = []() {
                        std::cout << "PLAYER 4" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) + 206.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 110.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::TITLE,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "SOUND",
                    .action = []() {
                        std::cout << "SOUND" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2), rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 310.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::SOUND_INFO,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = std::to_string(SettingsManager::getInstance().getSoundVolume()),
                    .action = []() {
                        std::cout << "SOUND" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2), rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 250.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::SOUND,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "+",
                    .action = []() {
                        SettingsManager::getInstance().setSoundVolume(SettingsManager::getInstance().getSoundVolume() + 5);
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) +  200.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 310.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::SOUND,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "-",
                    .action = []() {
                        SettingsManager::getInstance().setSoundVolume(SettingsManager::getInstance().getSoundVolume() - 5);
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) - 150.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) - 310.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::TITLE,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "MUSIC",
                    .action = []() {
                        std::cout << "MUSIC" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2), rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 450.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::MUSIC_INFO,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = std::to_string(SettingsManager::getInstance().getMusicVolume()),
                    .action = []() {
                        std::cout << "MUSIC" << std::endl;
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2), rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 500.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::MUSIC,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "+",
                    .action = []() {
                        SettingsManager::getInstance().setMusicVolume(SettingsManager::getInstance().getMusicVolume() + 5);
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) + 200.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 510.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::MUSIC,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "-",
                    .action = []() {
                        SettingsManager::getInstance().setMusicVolume(SettingsManager::getInstance().getMusicVolume() - 5);
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) - 150.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 510.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::ControlWidget {
                    .type = ecs::EXIT,
                    .indexPlayer = 99,
                    .indexKey = 99,
                    .isPressed = false,
                    .key = rl::KEY_NULL,
                    .content = "EXIT",
                    .action = []() {
                        GameManager::getInstance().pushWindow(WindowState::MENU);
                    }
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::Transform2D{
                    .position = rl::Vector2(rl::Window::getInstance().getWidth() / 2 - (buttonSize.x / 2) + 350.0f, rl::Window::getInstance().getHeight() / 2 - (buttonSize.y / 2) + 510.0f),
                    .rotation = rl::Vector2(0, 0),
                    .scale = rl::Vector2(buttonSize)
            });
    ecs::Coordinator::getInstance().addComponent(
            entity,
            ecs::DrawableSettingsControl()
    );
}

void GameManager::initGame()
{
    std::default_random_engine generator;
    ecs::Entity entity;

    std::uniform_real_distribution<float> randPosition(-8.0f, 8.0f);
    std::uniform_real_distribution<float> randColor(0, 255);


    rl::SoundManager::getInstance().getData(rl::SOUND_BATTLE_COUNTDOWN).play();
    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(-6, 1.6, -6),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(0.75f)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Gravity{
            .force = rl::Vector3(0, -9.807, 0)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::PLAYER,
            .grounded = false,
            .movable = true,
            .mass = 10
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::DrawableModel{
            .model = rl::Model(rl::MODEL_PLAYER_WHITE),
            .factor = 5.0f,
            .type = rl::MODEL_PLAYER_WHITE
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Alive{
            .dead = _players[0],
            .health = 1,
            .armor = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::PlayerStat{
            .speedMax = 3,
            .fire = 1,
            .bombMax = 1,
            .bombOut = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Controlled{
            // Movement
            // .up       = KEY_SPACE,
            .left     = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_LEFT],
            .right    = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_RIGHT],
            .front    = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_UP],
            .back     = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_DOWN],

            // Actions
            .place    = SettingsManager::getInstance().getPlayersKey()[0][KEY_P_BOMB],
            // .interact = KEY_Q,

            // // Stats
            // .bombs    = 3,
            // .fire     = 2,
            // .speed    = 8,
            // .bombOut  = 0,
    });

    // PLAYER 2

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(6, 1.6, 6),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(0.75f)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Gravity{
            .force = rl::Vector3(0, -9.807, 0)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::PLAYER,
            .grounded = false,
            .movable = true,
            .mass = 10
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::DrawableModel{
            .model = rl::Model(rl::MODEL_PLAYER_BLACK),
            .factor = 5.0f,
                .type = rl::MODEL_PLAYER_BLACK
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Alive{
            .dead = _players[1],
            .health = 1,
            .armor = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::PlayerStat{
            .speedMax = 3,
            .fire = 1,
            .bombMax = 1,
            .bombOut = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Controlled{
            // Movement
            // .up       = KEY_SPACE,
            .left     = SettingsManager::getInstance().getPlayersKey()[1][KEY_P_LEFT],
            .right    = SettingsManager::getInstance().getPlayersKey()[1][KEY_P_RIGHT],
            .front    = SettingsManager::getInstance().getPlayersKey()[1][KEY_P_UP],
            .back     = SettingsManager::getInstance().getPlayersKey()[1][KEY_P_DOWN],

            // Actions
            .place    = SettingsManager::getInstance().getPlayersKey()[1][KEY_P_BOMB],
            // .interact = KEY_Q,

            // // Stats
            // .bombs    = 3,
            // .fire     = 2,
            // .speed    = 8,
            // .bombOut  = 0,
    });

    // PLAYER 3

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(6, 1.6, -6),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(0.75f)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Gravity{
            .force = rl::Vector3(0, -9.807, 0)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::PLAYER,
            .grounded = false,
            .movable = true,
            .mass = 10
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::DrawableModel{
            .model = rl::Model(rl::MODEL_PLAYER_RED),
            .factor = 5.0f,
                .type = rl::MODEL_PLAYER_RED
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Alive{
            .dead = _players[2],
            .health = 1,
            .armor = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::PlayerStat{
            .speedMax = 3,
            .fire = 1,
            .bombMax = 1,
            .bombOut = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Controlled{
            // Movement
            // .up       = KEY_SPACE,
            .left     = SettingsManager::getInstance().getPlayersKey()[2][KEY_P_LEFT],
            .right    = SettingsManager::getInstance().getPlayersKey()[2][KEY_P_RIGHT],
            .front    = SettingsManager::getInstance().getPlayersKey()[2][KEY_P_UP],
            .back     = SettingsManager::getInstance().getPlayersKey()[2][KEY_P_DOWN],

            // Actions
            .place    = SettingsManager::getInstance().getPlayersKey()[2][KEY_P_BOMB],
            // .interact = KEY_Q,

            // // Stats
            // .bombs    = 3,
            // .fire     = 2,
            // .speed    = 8,
            // .bombOut  = 0,
    });

    // PLAYER 4

    entity = ecs::Coordinator::getInstance().createEntity();
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(-6, 1.6, 6),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(0.75f)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Gravity{
            .force = rl::Vector3(0, -9.807, 0)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::PLAYER,
            .grounded = false,
            .movable = true,
            .mass = 10
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::DrawableModel{
            .model = rl::Model(rl::MODEL_PLAYER_BLUE),
            .factor = 5.0f,
                .type = rl::MODEL_PLAYER_BLUE
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Alive{
            .dead = _players[3],
            .health = 1,
            .armor = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::PlayerStat{
            .speedMax = 3,
            .fire = 1,
            .bombMax = 1,
            .bombOut = 0
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Controlled{
            // Movement
            // .up       = KEY_SPACE,
            .left     = SettingsManager::getInstance().getPlayersKey()[3][KEY_P_LEFT],
            .right    = SettingsManager::getInstance().getPlayersKey()[3][KEY_P_RIGHT],
            .front    = SettingsManager::getInstance().getPlayersKey()[3][KEY_P_UP],
            .back     = SettingsManager::getInstance().getPlayersKey()[3][KEY_P_DOWN],

            // Actions
            .place    = SettingsManager::getInstance().getPlayersKey()[3][KEY_P_BOMB],
            // .interact = KEY_Q,

            // // Stats
            // .bombs    = 3,
            // .fire     = 2,
            // .speed    = 8,
            // .bombOut  = 0,
    });



    // MAP ---------------------------------------------------------------------

    entity = ecs::Coordinator::getInstance().createEntity(); // GROUND
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(0, -1, 0),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(14, 2, 14)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::SOLID,
            .grounded = true,
            .movable = false,
            .mass = 6
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Drawable{
            .drawable = rl::Cube(rl::Vector3(0.0f), rl::Vector3(0.0f)),
            .texture = rl::Texture(rl::TEXTURE_GROUND),
            .shadow = false
    });

    entity = ecs::Coordinator::getInstance().createEntity(); // RIGHT WALL
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(7, 10, 0),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(1, 20, 15)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::SOLID,
            .grounded = true,
            .movable = false,
            .mass = 6
    });

    entity = ecs::Coordinator::getInstance().createEntity(); // LEFT WALL
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(-7, 10, 0),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(1, 20, 15)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::SOLID,
            .grounded = true,
            .movable = false,
            .mass = 6
    });

    entity = ecs::Coordinator::getInstance().createEntity(); // BOTTOM WAL
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(0, 10, 7),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(15, 20, 1)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::SOLID,
            .grounded = true,
            .movable = false,
            .mass = 6
    });

    entity = ecs::Coordinator::getInstance().createEntity(); // TOP WALL
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::Transform3D{
                .position = rl::Vector3(0, 10, -7),
                .rotation = rl::Vector3(0.0f),
                .scale = rl::Vector3(15, 20, 1)
    });
    ecs::Coordinator::getInstance().addComponent(
        entity, ecs::RigidBody{
            .velocity = rl::Vector3(0.0f),
            .acceleration = rl::Vector3(0.0f),
            .type = ecs::CollisionType::SOLID,
            .grounded = true,
            .movable = false,
            .mass = 10
    });

    // ITEMS -------------------------------------------------------------------

    // entity = ecs::Coordinator::getInstance().createEntity();

    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Item {
    //         .name = "BombUp",
    //         .type = ecs::ItemType::BOMB_UP,
    //         .taken = false,
    //         .entity = ecs::MAX_ENTITIES + 1,
    //         .apply = &ecs::Item::BombUpApply
    //     }
    // );
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Alive {
    //         .dead = false,
    //         .health = 1,
    //         .armor = 0
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Transform3D{
    //         .position = rl::Vector3(randPosition(generator), 0.6, randPosition(generator)),
    //         .rotation = rl::Vector3(0.0f),
    //         .scale = rl::Vector3(0.4, 0.4, 0.4)
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Drawable{
    //         .drawable = rl::Cube(rl::Vector3(0.0f), rl::Vector3(0.0f)),
    //         .texture = rl::Texture(rl::TEXTURE_MISSING),
    //         .shadow = false
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::RigidBody{
    //         .velocity = rl::Vector3(0.0f),
    //         .acceleration = rl::Vector3(0.0f),
    //         .type = ecs::CollisionType::ITEM,
    //         .grounded = true,
    //         .movable = false,
    //         .mass = 10
    // });
    // entity = ecs::Coordinator::getInstance().createEntity();

    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Item {
    //         .name = "BombDown",
    //         .type = ecs::ItemType::BOMB_DOWN,
    //         .taken = false,
    //         .entity = ecs::MAX_ENTITIES + 1,
    //         .apply = &ecs::Item::BombDownApply
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Alive {
    //         .dead = false,
    //         .health = 1,
    //         .armor = 0
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Transform3D{
    //         .position = rl::Vector3(randPosition(generator), 0.6, randPosition(generator)),
    //         .rotation = rl::Vector3(0.0f),
    //         .scale = rl::Vector3(0.4, 0.4, 0.4)
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Drawable{
    //         .drawable = rl::Cube(rl::Vector3(0.0f), rl::Vector3(0.0f), rl::Color(randColor(generator), randColor(generator), randColor(generator), 255)),
    //         .texture = rl::Texture(rl::TEXTURE_MISSING),
    //         .shadow = false
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::RigidBody{
    //         .velocity = rl::Vector3(0.0f),
    //         .acceleration = rl::Vector3(0.0f),
    //         .type = ecs::CollisionType::ITEM,
    //         .grounded = true,
    //         .movable = false,
    //         .mass = 10
    // });
    // entity = ecs::Coordinator::getInstance().createEntity();

    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Item {
    //         .name = "SpeedUp",
    //         .type = ecs::ItemType::SPEED_UP,
    //         .taken = false,
    //         .entity = ecs::MAX_ENTITIES + 1,
    //         .apply = &ecs::Item::BombUpApply
    //     }
    // );
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Alive {
    //         .dead = false,
    //         .health = 1,
    //         .armor = 0
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Transform3D{
    //         .position = rl::Vector3(randPosition(generator), 0.6, randPosition(generator)),
    //         .rotation = rl::Vector3(0.0f),
    //         .scale = rl::Vector3(0.4, 0.4, 0.4)
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Drawable{
    //         .drawable = rl::Cube(rl::Vector3(0.0f), rl::Vector3(0.0f)),
    //         .texture = rl::Texture(rl::TEXTURE_MISSING),
    //         .shadow = false
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::RigidBody{
    //         .velocity = rl::Vector3(0.0f),
    //         .acceleration = rl::Vector3(0.0f),
    //         .type = ecs::CollisionType::ITEM,
    //         .grounded = true,
    //         .movable = false,
    //         .mass = 10
    // });
    // entity = ecs::Coordinator::getInstance().createEntity();

    // ecs::Coordinator::getInstance().addComponent(
    //     entity,ecs::Item {
    //         .name = "FireUp",
    //         .type = ecs::ItemType::FIRE_UP,
    //         .taken = false,
    //         .entity = ecs::MAX_ENTITIES + 1,
    //         .apply = &ecs::Item::FireUpApply
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Alive {
    //         .dead = false,
    //         .health = 1,
    //         .armor = 0
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Transform3D{
    //         .position = rl::Vector3(randPosition(generator), 0.6, randPosition(generator)),
    //         .rotation = rl::Vector3(0.0f),
    //         .scale = rl::Vector3(0.4, 0.4, 0.4)
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::Drawable{
    //         .drawable = rl::Cube(rl::Vector3(0.0f), rl::Vector3(0.0f)),
    //         .texture = rl::Texture(rl::TEXTURE_MISSING),
    //         .shadow = false
    // });
    // ecs::Coordinator::getInstance().addComponent(
    //     entity, ecs::RigidBody{
    //         .velocity = rl::Vector3(0.0f),
    //         .acceleration = rl::Vector3(0.0f),
    //         .type = ecs::CollisionType::ITEM,
    //         .grounded = true,
    //         .movable = false,
    //         .mass = 10
    // });

    // CRATES ------------------------------------------------------------------

    std::string map = getContentFile("Assets/maps/default_map.txt");
    std::pair<int, int> dim = getMapDim(map);
    map.erase(std::remove(map.begin(), map.end(), '\n'), map.end());
    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<float> vec = Noise::GenerateNoiseMap(dim.first, dim.second, seed);
    int i = 0, j = 0;

    for (size_t y = 0; y < vec.size(); y++, i++) {
        if (i == dim.first) {
            i = 0;
            j++;
        }
        if (vec[y] < 0.4f) continue;
        if (map[y] != 'P' && map[y] != 'B') {
            entity = ecs::Coordinator::getInstance().createEntity();

            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::Transform3D {
                    .position = rl::Vector3(i - dim.first / 2, 0.5, j - dim.first / 2),
                    .rotation = rl::Vector3(0.0f),
                    .scale = rl::Vector3(0.95f)
            });
            //à remettre plus tard mais la c a 0 tt facon
            // ecs::Coordinator::getInstance().addComponent(
            //     entity, ecs::Gravity {
            //         .force = rl::Vector3(0.0f)
            // });
            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::RigidBody{
                    .velocity = rl::Vector3(0.0f),
                    .acceleration = rl::Vector3(0.0f),
                    .type = ecs::CollisionType::CRATE,
                    .grounded = false,
                    .movable = false,
                    .mass = 6
            });
            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::Alive {
                    .dead = false,
                    .health = 1,
                    .armor = 0
            });
            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::DrawableModel{
                   .model = rl::Model(rl::MODEL_CRATE),
                   .factor = 1.0f,
                    .type = rl::MODEL_CRATE
            });
            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::Spawn {
                   .type = 1,
                   .rate = 50
            });
        }
    }

    // PILLARS -----------------------------------------------------------------

    i = 0, j = 0;
    for (size_t y = 0; y <= vec.size(); y++, i++) {
         if (i == dim.first) {
            i = 0;
            j++;
        }
        // std::cout << "map:" << map[y] << std::endl;
        if (map[y] == 'B') {
            // std::cout << "B" << std::endl;
            entity = ecs::Coordinator::getInstance().createEntity();

            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::Transform3D {
                        .position = rl::Vector3(i - 6, 0.5, j - 6),
                        .rotation = rl::Vector3(0.0f),
                        .scale = rl::Vector3(0.95f)
            });
            //à remettre plus tard mais la c a 0 tt facon
            // ecs::Coordinator::getInstance().addComponent(
            //     entity, ecs::Gravity {
            //         .force = rl::Vector3(0.0f)
            // });
            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::RigidBody{
                    .velocity = rl::Vector3(0.0f),
                    .acceleration = rl::Vector3(0.0f),
                    .type = ecs::CollisionType::SOLID,
                    .grounded = false,
                    .movable = false,
                    .mass = 6
            });
            ecs::Coordinator::getInstance().addComponent(
                entity, ecs::DrawableModel{
                    .model = rl::Model(rl::MODEL_PILLAR),
                    .factor = 1.0f,
                    .type = rl::MODEL_PILLAR
            });
        }
    }
    rl::SoundManager::getInstance().getData(rl::SOUND_BATTLE_START).play();
}

// void GameManager::initPause();

// LOOPS -----------------------------------------------------------------------

void GameManager::loopMenu(float dt)
{
    ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_WIDGET_SYSTEM)->update(dt);

    rl::Window::getInstance().updateCamera();
    rl::Window::getInstance().beginDrawing();
    {
        ClearBackground(RL_WHITE);
        rl::Window::getInstance().beginMode2D();
        {
            ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_RENDER_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::RENDER_TEXTURE_WIDGET_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_RENDER_WIDGET_SYSTEM)->update(dt);
        }
        rl::Window::getInstance().endMode2D();
    }
    rl::Window::getInstance().endDrawing();
}


// void GameManager::loopMapSelect(float dt);

void GameManager::loopPlayerSelect(float dt)
{
    ecs::Coordinator::getInstance().getSystem(ecs::PLAYER_WIDGET_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_WIDGET_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_SYSTEM)->update(dt);

    rl::Window::getInstance().updateCamera();
    rl::Window::getInstance().beginDrawing();
    {
        rl::Window::getInstance().clearBackground();
        rl::Window::getInstance().beginMode2D();
        {
            ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_RENDER_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::PLAYER_RENDER_WIDGET_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_RENDER_WIDGET_SYSTEM)->update(dt);
        }
        rl::Window::getInstance().endMode2D();
    }
    rl::Window::getInstance().endDrawing();
}

void GameManager::loopSettings(float dt)
{
    ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::SETTINGS_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_WIDGET_SYSTEM)->update(dt);

    rl::Window::getInstance().updateCamera();
    rl::Window::getInstance().beginDrawing();
    {
        rl::Window::getInstance().clearBackground();
        rl::Window::getInstance().beginMode2D();
        {
            ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_RENDER_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_RENDER_WIDGET_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::SETTINGS_RENDER_SYSTEM)->update(dt);
        }
        rl::Window::getInstance().endMode2D();
    }
    rl::Window::getInstance().endDrawing();
}

void GameManager::loopMapSelect(float dt)
{
    ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::MAP_WIDGET_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_WIDGET_SYSTEM)->update(dt);

    rl::Window::getInstance().updateCamera();
    rl::Window::getInstance().beginDrawing();
    {
        rl::Window::getInstance().clearBackground();
        rl::Window::getInstance().beginMode2D();
        {
            ecs::Coordinator::getInstance().getSystem(ecs::PARALLAX_RENDER_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::MAP_RENDER_WIDGET_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::BUTTON_RENDER_WIDGET_SYSTEM)->update(dt);
        }
        rl::Window::getInstance().endMode2D();
    }
    rl::Window::getInstance().endDrawing();
}

void GameManager::loopGame(float dt)
{
    static rl::Skybox skybox(
        rl::Skybox(std::make_pair(
            std::string("Assets/shaders/glsl330/skybox.vs"),
            std::string("Assets/shaders/glsl330/skybox.fs")
        ), std::make_pair(
            std::string("Assets/shaders/glsl330/cubemap.vs"),
            std::string("Assets/shaders/glsl330/cubemap.fs")
        ), "Assets/textures/skybox.hdr", true));

    ecs::Coordinator::getInstance().getSystem(ecs::CONTROL_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::MOVEMENT_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::COLLISION_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::COLLECTIBLE_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::PHYSICS_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::TEMPORARY_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::SPREAD_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::LIFE_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::BOMB_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::SPAWN_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::DESTROY_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::TEXTURED_ITEM_SYSTEM)->update(dt);
    ecs::Coordinator::getInstance().getSystem(ecs::PARTICLES_SYSTEM)->update(dt);

    rl::Window::getInstance().updateCamera();
    rl::Window::getInstance().beginDrawing();
    {
        ClearBackground(RL_SKYBLUE);
        rl::Window::getInstance().beginMode3D();
        {
            skybox.draw();
            ecs::Coordinator::getInstance().getSystem(ecs::ANIMATION_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::RENDER_MODEL_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::RENDER_SYSTEM)->update(dt);
            ecs::Coordinator::getInstance().getSystem(ecs::PART_RENDER_SYSTEM)->update(dt);
            // rl::Window::getInstance().drawGrid();
        }
        rl::Window::getInstance().endMode3D();
        rl::Window::getInstance().drawFPS();
    }
    rl::Window::getInstance().endDrawing();
}

// void GameManager::loopPause();
