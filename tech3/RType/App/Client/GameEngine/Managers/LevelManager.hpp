/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
**
Manager
*/

#ifndef LEVELMANAGER_HPP_
    #define LEVELMANAGER_HPP_

    #include "ECS/Coordinator.hpp"
    #include "GameEngine/PollEvent.hpp"
    #include "GameEngine/Theme/Theme.hpp"
    #include "GameEngine/BossManager.hpp"

    #include "GameEngine/Map/Map.hpp"
    #include <iostream>
    #include <random>
    #include <stack>
    #include <map>
    #include <fstream>
    #include <string>
    #include <array>

namespace engine {

    class LevelManager {
            LevelManager() {};
            ~LevelManager() = default;
        public:
            static LevelManager &getInstance() {
                static LevelManager instance;
                return (instance);
            }

            void instanciate(int lvl) {
                this->map.load(lvl);
                this->theme.load(lvl);
                this->bossManager.load(lvl);
            }
            ecs::Entity getAmbiantShader() const {
                return (this->theme.getAmbiantShader());
            }
            ecs::Entity getTextureShader() const {
                return (this->theme.getTextureShader());
            }

            std::shared_ptr<engine::IEntity> getAmbiantShaderPtr() {
                return (this->theme.getAmbiantShaderPtr());
            }
            std::shared_ptr<engine::IEntity> getTextureShaderPtr() {
                return (this->theme.getTextureShaderPtr());
            }
            void runMap(float dt) {
                this->map.run(dt);
            }

            const engine::Square &getLifeZone() {
                return this->map.getLifeZone();
            }

            std::shared_ptr<engine::IEntity> getBossPtr() {
                return this->bossManager.getBossPtr();
            }

        private:
            engine::Map map;
            engine::Theme theme;
            engine::BossManager bossManager;

    };
} // engine
#endif
