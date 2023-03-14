/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Theme
*/

#ifndef THEME_HPP_
    #define THEME_HPP_

    #include "Utils/PathBuilder.hpp"
    #include "Utils/Rect.hpp"
    #include "Utils/Vector2.hpp"
    #include "GameEngine/Spawner.hpp"
    #include "GameEngine/Map/Wall.hpp"
    #include "GameEngine/Shader.hpp"
    #include <map>
    #include <queue>
    #include <iostream>
    #include <utility>

namespace engine {

    const std::map<int, std::array<engine::EntityType, 3>> shaderTypes = {
        std::make_pair<int, std::array<engine::EntityType, 3>>(0, {engine::EntityType::COLOR_SHAD , engine::EntityType::WAVE_SHAD , engine::EntityType::SPACE_PARALLAX}),
        std::make_pair<int, std::array<engine::EntityType, 3>>(1, {engine::EntityType::COLOR_SHAD , engine::EntityType::WAVE_SHAD , engine::EntityType::SPACE_PARALLAX})
    };

    class Theme {
        public:
            Theme(int lvl = 0) {
                this->ambiantShaderPtr = engine::EntityFactory::createEngineEntity(shaderTypes.at(lvl)[0]);
                this->textureShaderPtr = engine::EntityFactory::createEngineEntity(shaderTypes.at(lvl)[1]);
                this->ambiantShader = this->ambiantShaderPtr->getEntity();
                this->textureShader = this->textureShaderPtr->getEntity();
                this->parallax = engine::EntityFactory::createEntity(shaderTypes.at(lvl)[2]);
            };
            ~Theme() = default;

            void load(int lvl) {
                ecs::Coordinator &coord = ecs::Coordinator::getInstance();
                coord.destroyEntity(this->ambiantShader);
                coord.destroyEntity(this->textureShader);
                coord.destroyEntity(this->parallax);
                this->ambiantShaderPtr = engine::EntityFactory::createEngineEntity(shaderTypes.at(lvl)[0]);
                this->textureShaderPtr = engine::EntityFactory::createEngineEntity(shaderTypes.at(lvl)[1]);
                this->ambiantShader = this->ambiantShaderPtr->getEntity();
                this->textureShader = this->textureShaderPtr->getEntity();
                this->parallax = engine::EntityFactory::createEntity(shaderTypes.at(lvl)[2]);
                this->ambiantShader = engine::EntityFactory::createEntity(shaderTypes.at(lvl)[0]);
                this->textureShader = engine::EntityFactory::createEntity(shaderTypes.at(lvl)[1]);
                this->parallax = engine::EntityFactory::createEntity(shaderTypes.at(lvl)[2]);

            }

            ecs::Entity getAmbiantShader() const {
                return (this->ambiantShader);
            }
            ecs::Entity getTextureShader() const {
                return (this->textureShader);
            }
            std::shared_ptr<engine::IEntity> getAmbiantShaderPtr() {
                return (this->ambiantShaderPtr);
            }
            std::shared_ptr<engine::IEntity> getTextureShaderPtr() {
                return (this->textureShaderPtr);
            }


        private:

            std::shared_ptr<engine::IEntity> ambiantShaderPtr;
            std::shared_ptr<engine::IEntity> textureShaderPtr;
            ecs::Entity ambiantShader;
            ecs::Entity textureShader;
            ecs::Entity parallax;

    };
}
#endif
