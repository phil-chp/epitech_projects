/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
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
    #include "Raylib.hpp"
    #include <iostream>
    #include <random>
    #include <stack>
    #include <map>
    #include "Noise.hpp"
    #include <fstream>
    #include <string>
    #include <array>

enum WindowState {
    MENU = 0,
    SETTINGS,
    MAP_SELECT,
    PLAYER_SELECT,
    GAME,
    PAUSE
};

typedef void (*initFunction)();
typedef void (*loopFunction)(float);


class GameManager {
    private:
        GameManager() : _push(false), _switch(false) {
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
            this->_switchToWindow[this->_windows.top()].first();
            this->_switch = false;
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

        void loopWindow(float dt) {
            this->_switchToWindow[this->_windows.top()].second(dt);
        }

        bool isSwitching() const {
            return (this->_switch);
        }

    private:
        static std::string getContentFile(const std::string &fileName) {
            std::ifstream file(fileName);
            std::stringstream buffer;
            buffer << file.rdbuf();
            return (buffer.str());
        }
        static std::pair<int, int> getMapDim(const std::string &str) {
            std::pair<int, int> widthHeight;
            std::stringstream ss(str);
            std::string line;
            while (std::getline(ss, line)) {
                if (line.size() > (unsigned)widthHeight.first)
                    widthHeight.first = line.size();
                widthHeight.second++;
            }
            return (widthHeight);
        }

        void clearWindow() {
            ecs::Coordinator::getInstance().clearEntities();
        }

        static void initMenu();
        static void initSettings();
        //static void initMapSelect();
        static void initPlayerSelect();
        static void initGame();
        // static void initPause();

        static void loopMenu(float dt);
        static void loopSettings(float dt);
        static void loopMapSelect(float dt);
        static void loopPlayerSelect(float dt);
        static void loopGame(float dt);
        // static void loopPause(float dt);

        void initWindowStack() {
            this->_windows.push(GAME);
            // this->_windows.push(MAP_SELECT);
            this->_windows.push(PLAYER_SELECT);
            this->_windows.push(MENU);
        }

        void initWindowSwitcher() {
            this->_switchToWindow.insert(std::make_pair(MENU, std::make_pair(
                &GameManager::initMenu,
                &GameManager::loopMenu)));
             this->_switchToWindow.insert(std::make_pair(SETTINGS, std::make_pair(
                &GameManager::initSettings,
                &GameManager::loopSettings)));
            // this->_switchToWindow.insert(std::make_pair(MAP_SELECT, std::make_pair(
            //      &GameManager::initMapSelect,
            //      &GameManager::loopMapSelect)));
            this->_switchToWindow.insert(std::make_pair(PLAYER_SELECT, std::make_pair(
                &GameManager::initPlayerSelect,
                &GameManager::loopPlayerSelect)));
            this->_switchToWindow.insert(std::make_pair(GAME, std::make_pair(
                &GameManager::initGame,
                &GameManager::loopGame)));
            // this->_switchToWindow.insert(std::make_pair(PAUSE, std::make_pair(
            //     &GameManager::initPause,
            //     &GameManager::loopPause)));
        }

        bool _push;
        std::stack<WindowState> _windows{};
        std::map<WindowState, std::pair<initFunction, loopFunction> > _switchToWindow;
        bool _switch;
};

#endif /* !GameManager_HPP_ */
