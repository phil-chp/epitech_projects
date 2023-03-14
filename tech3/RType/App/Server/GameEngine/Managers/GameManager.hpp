/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** GameManager
*/

// - [x] clearEntities()
// - [ ] switchWindow() => function list // map ?
// - [ ] n = currentWindow()

// store vector<entity> * max_entities
// entities have a null state
// does having a no-component state mean that the entity is not in the system ?

#ifndef GameManager_HPP_
    #define GameManager_HPP_

    #include "ECS/Coordinator.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"
    #include "GameEngine/PollEvent.hpp"
    // #include "GameEngine/EngineButton.hpp"
    #include "GameEngine/RType/Button/PlayButton.hpp"
    #include "GameEngine/RType/Button/QuitButton.hpp"
    #include "GameEngine/Managers/LevelManager.hpp"
    #include "GameEngine/MenuParallax.hpp"
    #include "GameEngine/RLEventHandler.hpp"
    #include <iostream>
    #include <random>
    #include <stack>
    #include <map>
    #include <fstream>
    #include <string>
    #include <array>

enum WindowState {
    MENU = 0,
    // SETTINGS,
    // MAP_SELECT,
    // PLAYER_SELECT,
    GAME = 1
    // PAUSE
};

typedef void (*initFunction)();
typedef void (*loopFunction)(::engine::PollEvent &);

namespace engine {
class GameManager {
    private:
        GameManager() : _push(false), _switch(false), _quit(false), _playerNumber(1), _lvl(0) {
            this->initWindowStack();
            this->initWindowSwitcher();
            this->initWindow();
        }
        ~GameManager() = default;

    public:
        static GameManager &getInstance()
        {
            static GameManager instance;
            return (instance);
        }

        GameManager(const GameManager&) = delete;
        GameManager &operator=(const GameManager&) = delete;

        void pushWindow(WindowState windowState) {
            this->_switch = true;
            this->_push = true;
            this->_windows.push(windowState);
        }

        void popWindow() {
            this->_switch = true;
        }

        WindowState &currentWindow() {
            return (this->_windows.top());
        }

        void initWindow() {
            // this->_windows.pop();
            this->clearWindow();
            // std::cout << "after clear" << std::endl;
            this->_switchToWindow[this->_windows.top()].first();
            this->_switch = false;
            // std::cout << "END init" << std::endl;
        }

        void switchWindow() {
            this->clearWindow();
            if (this->_push) {
                this->_push = false;
            } else {
                this->_windows.pop();
            }
            this->_switchToWindow[this->_windows.top()].first();
            this->_switch = false;
        }

        void loopWindow(::engine::PollEvent &event) {
            this->_switchToWindow[this->_windows.top()].second(event);
        }

        bool isSwitching() const {
            return (this->_switch);
        }

        int _playerNumber;
        bool _quit;

    private:

        void clearWindow() {
            ecs::Coordinator::getInstance().clearEntities();
            // std::cout << "Clear Entities" << std::endl;
        }

        static void initMenu();
        static void initGame();

        static void loopMenu(::engine::PollEvent &event);
        static void loopGame(::engine::PollEvent &event);

        void initWindowStack() {
            this->_windows.push(WindowState::MENU);
            this->_windows.push(WindowState::GAME);
        }

        void initWindowSwitcher() {
            this->_switchToWindow.insert(std::make_pair(WindowState::MENU, std::make_pair(
                &GameManager::initMenu,
                &GameManager::loopMenu)));
            this->_switchToWindow.insert(std::make_pair(WindowState::GAME, std::make_pair(
                &GameManager::initGame,
                &GameManager::loopGame)));
        }

        void loadLvl() {
            engine::LevelManager::getInstance().instanciate(this->_lvl);
        }

        void setLvl(int lvl) {
            this->_lvl = lvl;
        }

        void runMap(float dt) {
            engine::LevelManager::getInstance().runMap(dt);
        }

        ecs::Entity getAmbiantShader() const {
            return engine::LevelManager::getInstance().getAmbiantShader();
        }

        ecs::Entity getTextureShader() const {
            return engine::LevelManager::getInstance().getTextureShader();
        }


        bool _push;
        std::stack<WindowState> _windows{};
        std::map<WindowState, std::pair<initFunction, loopFunction> > _switchToWindow;
        bool _switch;
        // LevelManager _lvlMan;
        int _lvl;
};
} // namespace engine

#endif /* !GameManager_HPP_ */
