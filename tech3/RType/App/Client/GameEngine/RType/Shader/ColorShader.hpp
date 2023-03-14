/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ColorShader
*/

#ifndef COLORSHADER_HPP_
#define COLORSHADER_HPP_

    #include "GameEngine/Entity.hpp"
    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/ShaderManager.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"
    #include "ECS/Components/RLShader.hpp"
    #include "GameEngine/Shader.hpp"
    #include "Utils/Random.hpp"


namespace engine {
    namespace rtype {

    struct Vec4 {
        float x;
        float y;
        float w;
        float h;
    };

class ColorShader : public Shader {
    public:
        ColorShader() : Shader() {
                rl::Shader shader(ShaderManager::getInstance().getData(ShaderType::SHADER_COLOR));
                std::map<int, float> shaderValues;
                int timeLoc = shader.getLocation("time");
                int colALoc = shader.getLocation("colorA");
                int colBLoc = shader.getLocation("colorB");


                float totalTime = 0.0f;
                // Shader uniform values that can be updated at any time

                Vec4 colA = {0.8, 0.8, 0.8, 0.2};
                Vec4 colB = {1.0, 1.0, 1.0, 0.2};


                shaderValues[timeLoc] = totalTime;
                shaderValues[colALoc] = colA.x;
                shaderValues[colBLoc] = colB.x;
                // shader.setValue(shader.getLocation("size"), &screenSize, SHADER_UNIFORM_VEC2);
                shader.setValue(timeLoc, &shaderValues[timeLoc], SHADER_UNIFORM_FLOAT);
                shader.setValue(colALoc, &colA, SHADER_UNIFORM_VEC4);
                shader.setValue(colBLoc, &colB, SHADER_UNIFORM_VEC4);


                std::vector<ecs::Entity> entities;
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::RLShader{
                        shader,
                        ::game::Vector2(0, 0),
                        entities,
                        shaderValues,
                        &engine::rtype::ColorShader::update,
                        true,
                    }
                );
                engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::ColorShader>(*this));

        }

        ~ColorShader() = default;
        static ::ecs::Entity construct() {
            ColorShader shader;
            return (shader.entity);
        }

        void addShaderedEntity(::ecs::Entity entity) final {
            ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);

            int colALoc = shader._shader.getLocation("colorA");
            float a = ::game::Random::getRandomValue(0, 1);
            float b = ::game::Random::getRandomValue(0, 1);
            float c = ::game::Random::getRandomValue(0, 1);
            Vec4 colA = {a, b, c, 0.2};

            int colBLoc = shader._shader.getLocation("colorB");
            float d = ::game::Random::getRandomValue(0, 1);
            float e = ::game::Random::getRandomValue(0, 1);
            float f = ::game::Random::getRandomValue(0, 1);
            Vec4 colB = {d, e, f, 0.2};

            shader._shaderValues[colALoc] = colA.x;
            shader._shaderValues[colBLoc] = colB.x;

            shader._shader.setValue(colALoc, &colA, SHADER_UNIFORM_VEC4);
            shader._shader.setValue(colBLoc, &colB, SHADER_UNIFORM_VEC4);

            std::cout << "changed color" << std::endl;



            // ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
            // shader._entities.push_back(entity);
        }

        void removeShaderedEntity(::ecs::Entity ent) final {
            // ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
            // shader._entities.erase(std::remove(shader._entities.begin(), shader._entities.end(), ent), shader._entities.end());
        }

        static void update(ecs::Entity ent, float dt) {
            ecs::RLShader &shader = ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(ent);
            int locTime = shader._shader.getLocation("time");
            shader._shaderValues[locTime] += dt;
            shader._shader.setValue(locTime, &shader._shaderValues[locTime], SHADER_UNIFORM_FLOAT);
        }


};
};
};


#endif /* !COLORSHADER_HPP_ */
