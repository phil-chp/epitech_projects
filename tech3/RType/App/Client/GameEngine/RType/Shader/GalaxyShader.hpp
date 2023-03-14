// /*
// ** EPITECH PROJECT, 2022
// ** RType
// ** File description:
// ** GalaxyShader
// */

// #ifndef GALAXSHADER_HPP_
// #define GALAXSHADER_HPP_
//     #include "GameEngine/Entity.hpp"
//     #include "ECS/Entity.hpp"
//     #include "ECS/Coordinator.hpp"
//     #include "GameEngine/Managers/ShaderManager.hpp"
//     #include "Lib/Raylib/rl-cpp/Shaders/Shaders.hpp"
//     #include "ECS/Components/RLShader.hpp"
//     #include "GameEngine/Shader.hpp"
//     #include "GameEngine/GameEntities.hpp"


// namespace engine {
//     namespace rtype {
// class GalaxyShader : public Shader {
//     public:
//         GalaxyShader() : Shader() {
//             rl::Shader shader(ShaderManager::getInstance().getData(ShaderType::SHADER_GALAXY));
//             std::map<int, float> shaderValues;
//             // int timeLoc = shader.getLocation("iTime");
//             // int resolutionLoc = shader.getLocation("iResolution");


//             float totalTime = 2.0f;
//             // shaderValues[timeLoc] = totalTime;
//             // float screenSize[2] = { (float)GetScreenWidth(), (float)GetScreenHeight()};
//             // Shader uniform values that can be updated at any time



//             // shader.setValue(timeLoc, &totalTime, SHADER_UNIFORM_FLOAT);
//             // shader.setValue(resolutionLoc, &screenSize, SHADER_UNIFORM_VEC2);


//             std::vector<ecs::Entity> entities;
//             ::ecs::Coordinator::getInstance().addComponent(
//                 this->entity,
//                 ecs::RLShader{
//                     shader,
//                     ::game::Vector2(0, 0),
//                     entities,
//                     shaderValues,
//                     &engine::rtype::GalaxyShader::update,
//                     true,
//                 }
//             );
//             engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::GalaxyShader>(*this));

//         }
//         ~GalaxyShader() = default;
//         static ::ecs::Entity construct() {
//             GalaxyShader shader;
//             return (shader.entity);
//         }

//         void addShaderedEntity(::ecs::Entity entity) final{
//             ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
//             shader._entities.push_back(entity);
//         }

//         void removeShaderedEntity(::ecs::Entity ent) final {
//             ecs::RLShader &shader = ::ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(this->entity);
//             shader._entities.erase(std::remove(shader._entities.begin(), shader._entities.end(), ent), shader._entities.end());
//         }

//         static void update(ecs::Entity ent, float dt) {
//             // ecs::RLShader &shader = ecs::Coordinator::getInstance().getComponent<ecs::RLShader>(ent);
//             // int locTime = shader._shader.getLocation("iTime");
//             // shader._shaderValues[locTime] += dt;
//             // shader._shader.setValue(locTime, &shader._shaderValues[locTime], SHADER_UNIFORM_FLOAT);
//         }


// };
// };
// };


// #endif /* !RAINSHADER_HPP_ */
