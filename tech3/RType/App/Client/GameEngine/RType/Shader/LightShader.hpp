/*
** EPITECH PROJECT, 2022
** RType
** File description:
** LightShader
*/

#ifndef LIGHTSHADER_HPP_
#define LIGHTSHADER_HPP_
    #include "GameEngine/Entity.hpp"
    #include "ECS/Entity.hpp"
    #include "ECS/Coordinator.hpp"
    #include "GameEngine/Managers/ShaderManager.hpp"
    #include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"
    #include "ECS/Components/RLShader.hpp"
    #include "GameEngine/Shader.hpp"

#define MAX_SPOTS   4

namespace engine {
    namespace rtype {

    struct Spot{
        Vector2 pos;
        Vector2 vel;
        float inner;
        float radius;

        // Shader locations
        unsigned int posLoc;
        unsigned int innerLoc;
        unsigned int radiusLoc;
    };

class LightShader : public Shader {
    public:
        LightShader() : Shader() {
                rl::Shader shader(ShaderManager::getInstance().getData(ShaderType::SHADER_SPOTLIGHT));

                std::map<int, float> shaderValues;

                int nbLoc = shader.getLocation("spotNb");
                int nb = 0;
                shader.setValue(nbLoc, &nb, SHADER_UNIFORM_INT);
                shaderValues[nbLoc] = nb;

                int wLoc = shader.getLocation("screenWidth");
                int hLoc = shader.getLocation("screenHeight");
                float sw = (float)GetScreenWidth();
                float sh = (float)GetScreenHeight();
                shader.setValue(wLoc, &sw, SHADER_UNIFORM_FLOAT);
                shader.setValue(hLoc, &sh, SHADER_UNIFORM_FLOAT);
                shaderValues[wLoc] = sw;
                shaderValues[hLoc] = sh;

                Spot spots[MAX_SPOTS];

                for (int i = 0; i < MAX_SPOTS; i++)
                {
                    char posName[32] = "spots[x].pos";
                    char innerName[32] = "spots[x].inner";
                    char radiusName[32] = "spots[x].radius";

                    posName[6] = '0' + i;
                    innerName[6] = '0' + i;
                    radiusName[6] = '0' + i;

                    spots[i].posLoc = shader.getLocation(posName);
                    spots[i].innerLoc = shader.getLocation(innerName);
                    spots[i].radiusLoc = shader.getLocation(radiusName);

                }

                ::game::Vector2 pos(-1000, -1000);
                ::game::Vector2 vel (0, 0);

                for (int i = 0; i < MAX_SPOTS; i++)
                {
                    spots[i].pos = {pos.x, pos.y};
                    spots[i].vel = {0, 0};
                    spots[i].inner = 100.0f;
                    spots[i].radius = 300.0f;

                    shader.setValue(spots[i].posLoc, &spots[i].pos, SHADER_UNIFORM_VEC2);
                    shader.setValue(spots[i].innerLoc, &spots[i].inner, SHADER_UNIFORM_FLOAT);
                    shader.setValue(spots[i].radiusLoc, &spots[i].radius, SHADER_UNIFORM_FLOAT);
                    shaderValues[spots[i].posLoc] = spots[i].pos.x;
                    shaderValues[spots[i].innerLoc] = spots[i].inner;
                    shaderValues[spots[i].radiusLoc] = spots[i].radius;

                }

                std::vector<ecs::Entity> entities;
                ::ecs::Coordinator::getInstance().addComponent(
                    this->entity,
                    ecs::RLShader{
                        shader,
                        ::game::Vector2(66, 34),
                        entities,
                        shaderValues,
                        &engine::rtype::LightShader::update,
                        true,
                    }
                );
                engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::LightShader>(*this));
        }
        ~LightShader() = default;

        static ::ecs::Entity construct() {
            LightShader shader;
            return (shader.entity);
        }

        void addShaderedEntity(::ecs::Entity entity) final {
            ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
            int nbLoc = shader._shader.getLocation("spotNb");
            int nb = shader._shaderValues[nbLoc];
            if (nb < MAX_SPOTS) {
                ecs::RLDrawable &drawable = ::ecs::Coordinator::getInstance().getComponent<ecs::RLDrawable>(entity);
                drawable.shadered = true;
                nb++;
                shader._shaderValues[nbLoc] = nb;
                shader._shader.setValue(nbLoc, &nb, SHADER_UNIFORM_INT);
                shader._entities.push_back(entity);
            }
        }

        void removeShaderedEntity(::ecs::Entity ent) final {
            ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
            shader._entities.erase(std::remove(shader._entities.begin(), shader._entities.end(), ent), shader._entities.end());
        }


        static void update(ecs::Entity ent, float dt) {
            ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(ent);
            int i = 0;
            for (::ecs::Entity entity : shader._entities) {
                char posName[32] = "spots[x].pos";
                posName[6] = '0' + i;
                ecs::Transform &transform = ::ecs::Coordinator::getInstance().getComponent<ecs::Transform>(entity);
                int locXPos = shader._shader.getLocation(posName);
                ::game::Vector2 pos = transform.position + shader.offset;
                shader._shaderValues[locXPos] = pos.x;
                shader._shader.setValue(locXPos, &pos, SHADER_UNIFORM_VEC2);
                ++i;
            }

        }


};
};
};

#endif /* !LIGHTSHADER_HPP_ */
