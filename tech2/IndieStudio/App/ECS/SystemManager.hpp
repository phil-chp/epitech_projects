/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** SystemManager
*/


#ifndef SYSTEMMANAGER_HPP_
    #define SYSTEMMANAGER_HPP_

    #include "ECS/Systems/ControlSystem.hpp"
    #include "ECS/Systems/RenderSystem.hpp"
    #include "ECS/Systems/RenderModelSystem.hpp"
    #include "ECS/Systems/PhysicsSystem.hpp"
    #include "ECS/Systems/HomingSystem.hpp"
    #include "ECS/Systems/BombSystem.hpp"
    #include "ECS/Systems/CollisionSystem.hpp"
    #include "ECS/Systems/TemporarySystem.hpp"
    #include "ECS/Systems/MovementSystem.hpp"
    #include "ECS/Systems/CollectibleSystem.hpp"
    #include "ECS/Systems/LifeSystem.hpp"
    #include "ECS/Systems/SpreadSystem.hpp"
    #include "ECS/Systems/PartRenderSystem.hpp"
    #include "ECS/Systems/ParticlesSystem.hpp"
    #include "ECS/Systems/Widgets/RenderButtonWidgetSystem.hpp"
    #include "ECS/Systems/Widgets/RenderPlayerWidgetSystem.hpp"
    #include "ECS/Systems/Widgets/RenderTextureWidgetSystem.hpp"
    #include "ECS/Systems/Widgets/RenderSettingsSystem.hpp"
    #include "ECS/Systems/Widgets/RenderMapWidgetSystem.hpp"
    #include "ECS/Systems/Widgets/WidgetButtonSystem.hpp"
    #include "ECS/Systems/Widgets/WidgetPlayerSystem.hpp"
    #include "ECS/Systems/Widgets/WidgetMapSystem.hpp"
    #include "ECS/Systems/Widgets/WidgetSettingsSystem.hpp"
    #include "ECS/Systems/ParallaxSystem.hpp"
    #include "ECS/Systems/ParallaxRenderSystem.hpp"
    #include "ECS/Systems/PlaySoundSystem.hpp"
    #include "ECS/Systems/SpawnSystem.hpp"
    #include "ECS/Systems/DestroySystem.hpp"
    #include "ECS/Systems/TexturedItemSystem.hpp"
    #include "ECS/Systems/AnimationSystem.hpp"
    #include <iostream>
    #include <memory>
    #include <unordered_map>

namespace ecs {
    class SystemManager {
        public:
            SystemManager() {};
            ~SystemManager() = default;

            template<typename T>
            std::shared_ptr<T> registerSystem() {
                const char *typeName = typeid(T).name();

                if (this->_systems.find(typeName) != this->_systems.end()) {
                    throw ECSError("Registering system more than once.");
                }

                std::shared_ptr<T> system = std::make_shared<T>();
                this->_systems.insert({typeName, system});
                return (system);
            }

            template<typename T>
            void setSignature(Signature signature) {
                const char *typeName = typeid(T).name();

                if (this->_systems.find(typeName) == this->_systems.end()) {
                    throw ECSError("System used before registered.");
                }

                this->_signatures.insert({typeName, signature});
            }

            void destroyEntity(Entity entity) {
                for (auto const &pair : this->_systems) {
                    std::shared_ptr<ASystem> const &system = pair.second;
                    system->entities.erase(entity);
                }
            }

            void entitySignatureChanged(Entity entity, Signature const &entitySignature) {
                for (auto const &pair : this->_systems) {
                    char const *type = pair.first;
                    std::shared_ptr<ASystem> const &system = pair.second;
                    Signature const &systemSignature = this->_signatures[type];

                    if ((entitySignature &systemSignature) == systemSignature) {
                        system->entities.insert(entity);
                    } else {
                        system->entities.erase(entity);
                    }
                }
            }

        private:
            std::unordered_map<char const *, Signature> _signatures{};
            std::unordered_map<char const *, std::shared_ptr<ASystem>> _systems{};
    };
}

#endif /* !SYSTEMMANAGER_HPP_ */
