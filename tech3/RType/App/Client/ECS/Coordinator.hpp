/*
** EPITECH PROJECT, 2022
** RType
** File description:
** Coordinator
*/

#ifndef COORDINATOR_HPP_
    #define COORDINATOR_HPP_

    #include "ECS/EntityManager.hpp"
    #include "ECS/ComponentManager.hpp"
    #include "ECS/SystemManager.hpp"
    #include <iostream>
    #include <memory>
    #include <map>

namespace ecs {
    enum SysType {
        DRAW_SYSTEM,
        MOVEMENT_SYSTEM,
        SELECTOR_SYSTEM,
        CONTROL_MOVE_SYSTEM,
        BOUND_SYSTEM,
        SCROLL_SYSTEM,
        PARALLAX_SYSTEM,
        PARALLAX_DRAW_SYSTEM,
        BUTTON_SYSTEM,
        DRAW_TEXT_SYSTEM,
        ANIMATE_SYSTEM,
        SHOOT_SYSTEM,
        COLLISION_SYSTEM,
        AI_SYSTEM,
        TEMPORARY_SYSTEM,
        SPAWN_SYSTEM,
        LIFE_SYSTEM,
        UI_RENDER_SYSTEM,
        SOUND_SYSTEM,
        PARTICLES_SYSTEM,
        SHADER_SYSTEM,
        BULLET_SYSTEM
    };

    class Coordinator {
        private:
            Coordinator();
            ~Coordinator() = default;

        public:
            static Coordinator &getInstance()
            {
                static Coordinator instance;
                return (instance);
            }

            Coordinator(const Coordinator &) = delete;
            Coordinator & operator=(const Coordinator &) = delete;

            Entity createEntity() {
                return this->_entityManager->createEntity();
            }

            void destroyEntity(Entity entity) {
                this->_entityManager->destroyEntity(entity);
                this->_componentManager->destroyEntity(entity);
                this->_systemManager->destroyEntity(entity);
            }

            void clearEntities() {
                this->_entityManager->clearEntities();
            }

            template<typename T>
            void registerComponent() {
                this->_componentManager->registerComponent<T>();
            }

            template<typename T>
            void addComponent(Entity entity, T component) {
                this->_componentManager->addComponent<T>(entity, component);

                Signature signature = this->_entityManager->getSignature(entity);
                signature.set(this->_componentManager->getComponentType<T>(), true);
                this->_entityManager->setSignature(entity, signature);

                this->_systemManager->entitySignatureChanged(entity, signature);
            }

            template<typename T>
            void removeComponent(Entity entity) {
                this->_componentManager->removeComponent<T>(entity);

                Signature signature = this->_entityManager->getSignature(entity);
                signature.set(this->_componentManager->getComponentType<T>(), false);
                this->_entityManager->setSignature(entity, signature);

                this    ->_systemManager->entitySignatureChanged(entity, signature);
            }

            template<typename T>
            T &getComponent(Entity entity) {
                return (this->_componentManager->getComponent<T>(entity));
            }

            template<typename T>
            ComponentType getComponentType() {
                return (this->_componentManager->getComponentType<T>());
            }


            template<typename T>
            std::shared_ptr<T> registerSystem() {
                return (_systemManager->registerSystem<T>());
            }

            template<typename T>
            void setSystemSignature(Signature signature) {
                this->_systemManager->setSignature<T>(signature);
            }

            std::shared_ptr<ASystem> getSystem(SysType sysType) const {
                try {
                     return (this->_systems.at(sysType));
                } catch (std::exception &e) {
                    std::cerr << e.what() << std::endl;
                }
                return nullptr;
            }

        private:
            std::shared_ptr<ComponentManager>            _componentManager;
            std::shared_ptr<EntityManager>               _entityManager;
            std::shared_ptr<SystemManager>               _systemManager;
            std::map<SysType, std::shared_ptr<ASystem>>  _systems;
    };
}

#endif /* !COORDINATOR_HPP_ */
