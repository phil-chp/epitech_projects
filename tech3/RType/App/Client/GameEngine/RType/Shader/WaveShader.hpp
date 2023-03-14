/*
** EPITECH PROJECT, 2022
** RType
** File description:
** WaveShader
*/

#ifndef WAVESHADER_HPP_
#define WAVESHADER_HPP_
    #include "GameEngine/Entity.hpp"
    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/ShaderManager.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"
    #include "ECS/Components/RLShader.hpp"
    #include "GameEngine/Shader.hpp"
    #include "GameEngine/GameEntities.hpp"



namespace engine {
    namespace rtype {

class WaveShader : public Shader {
    public:
        WaveShader() : Shader() {
                rl::Shader shader(ShaderManager::getInstance().getData(ShaderType::SHADER_WAVE));
                std::map<int, float> shaderValues;
                int secondsLoc = shader.getLocation("secondes");
                int freqXLoc = shader.getLocation("freqX");
                int freqYLoc = shader.getLocation("freqY");
                int ampXLoc = shader.getLocation("ampX");
                int ampYLoc = shader.getLocation("ampY");
                int speedXLoc = shader.getLocation("speedX");
                int speedYLoc = shader.getLocation("speedY");

                // Shader uniform values that can be updated at any time
                float freqX = 8.0f;
                float freqY = 10.0f;
                float ampX = 5.0f;
                float ampY = 4.0f;
                float speedX = 5.0f;
                float speedY = 4.0f;
                float seconds = 0.0f;

                shaderValues[secondsLoc] = seconds;
                shaderValues[freqXLoc] = freqX;
                shaderValues[freqYLoc] = freqY;
                shaderValues[ampXLoc] = ampX;
                shaderValues[ampYLoc] = ampY;
                shaderValues[speedXLoc] = speedX;
                shaderValues[speedYLoc] = speedY;

                float screenSize[2] = { (float)GetScreenWidth(), (float)GetScreenHeight()};
                shader.setValue(shader.getLocation("size"), &screenSize, SHADER_UNIFORM_VEC2);
                shader.setValue(freqXLoc, &freqX, SHADER_UNIFORM_FLOAT);
                shader.setValue(freqYLoc, &freqY, SHADER_UNIFORM_FLOAT);
                shader.setValue(ampXLoc, &ampX, SHADER_UNIFORM_FLOAT);
                shader.setValue(ampYLoc, &ampY, SHADER_UNIFORM_FLOAT);
                shader.setValue(speedXLoc, &speedX, SHADER_UNIFORM_FLOAT);
                shader.setValue(speedYLoc, &speedY, SHADER_UNIFORM_FLOAT);
                shader.setValue(secondsLoc, &seconds, SHADER_UNIFORM_FLOAT);

                std::vector<ecs::Entity> entities;
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::RLShader{
                        shader,
                        ::game::Vector2(0, 0),
                        entities,
                        shaderValues,
                        &engine::rtype::WaveShader::update,
                        false,
                    }
                );
                engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::WaveShader>(*this));
        }

        ~WaveShader() = default;
        static ::ecs::Entity construct() { //TODO: find why _shaders has size 0
            WaveShader shader;
            return (shader.entity);
        }

        void addShaderedEntity(::ecs::Entity entity) final{
            ecs::RLDrawable &draw = ::ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
            draw.shadered = true;
            draw.shader = this->entity;
            ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
            shader._entities.push_back(entity);
        }

        void removeShaderedEntity(::ecs::Entity ent) final {
            ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
            shader._entities.erase(std::remove(shader._entities.begin(), shader._entities.end(), ent), shader._entities.end());
        }



        static void update(ecs::Entity ent, float dt) {
            ecs::RLShader &shader = ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(ent);
            int locSeconds = shader._shader.getLocation("secondes");
            shader._shaderValues[locSeconds] += dt;
            shader._shader.setValue(locSeconds, &shader._shaderValues[locSeconds], SHADER_UNIFORM_FLOAT);
        }


};
};
};

#endif /* !WAVESHADER_HPP_ */
