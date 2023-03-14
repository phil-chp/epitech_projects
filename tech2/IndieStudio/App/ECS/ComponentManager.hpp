/*
** EPITECH PROJECT, 2022
** Indie-Studio (Workspace)
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
    #define COMPONENTMANAGER_HPP_

    #include "Component.hpp"
    #include "ComponentArray.hpp"
    #include "Entity.hpp"
    #include "Components/Alive.hpp"
    #include "Components/Bomb.hpp"
    #include "Components/Controlled.hpp"
    #include "Components/Drawable.hpp"
    #include "Components/DrawableModel.hpp"
    #include "Components/Gravity.hpp"
    #include "Components/Homing.hpp"
    #include "Components/RigidBody.hpp"
    #include "Components/Item.hpp"
    #include "Components/Scalable.hpp"
    #include "Components/Transform.hpp"
    #include "Components/Temporary.hpp"
    #include "Components/Damage.hpp"
    #include "Components/Spread.hpp"
    #include "Components/Particles.hpp"
    #include "Components/Widget.hpp"
    #include "Components/DrawableButtonWidget.hpp"
    #include "Components/DrawablePlayerWidget.hpp"
    #include "Components/DrawableMapWidget.hpp"
    #include "Components/DrawableSettingsControl.hpp"
    #include "Components/Parallax.hpp"
    #include "Components/SoundEffect.hpp"
    #include "Components/PlayerStat.hpp"
    #include "Components/ControlWidget.hpp"
    #include "Components/Spawn.hpp"
    #include <unordered_map>
    #include <memory>

namespace ecs {
    class ComponentManager {
        public:
            template<typename T>
            void registerComponent() {
                const char *typeName = typeid(T).name();

                if (this->_componentTypes.find(typeName) != this->_componentTypes.end()) {
                    throw ECSError("Registering component type more than once.");
                }
                this->_componentTypes.insert({
                    typeName,
                    this->_nextComponentType
                });
                this->_componentArrays.insert({
                    typeName,
                    std::make_shared<ComponentArray<T> >()
                });
                ++this->_nextComponentType;
            }

            template<typename T>
            ComponentType getComponentType() {
                const char *typeName = typeid(T).name();

                if (this->_componentTypes.find(typeName) == this->_componentTypes.end()) {
                    throw ECSError("Component not registered before use.");
                }
                return this->_componentTypes[typeName];
            }

            template<typename T>
            void addComponent(Entity entity, T component) {
                getComponentArray<T>()->insertData(entity, component);
            }

            template<typename T>
            void removeComponent(Entity entity) {
                getComponentArray<T>()->removeData(entity);
            }

            template<typename T>
            T &getComponent(Entity entity) {
                return (getComponentArray<T>()->getData(entity));
            }

            void destroyEntity(Entity entity) {
                for (auto const &pair : this->_componentArrays) {
                    std::shared_ptr<IComponentArray> const&component = pair.second;

                    component->destroyEntity(entity);
                }
            }

        private:
            std::unordered_map<const char *, ComponentType> _componentTypes{};
            std::unordered_map<const char *, std::shared_ptr<IComponentArray>> _componentArrays{};
            ComponentType _nextComponentType{};

            template<typename T>
            std::shared_ptr<ComponentArray<T>> getComponentArray() {
                const char *typeName = typeid(T).name();

                if (this->_componentTypes.find(typeName) == this->_componentTypes.end()) {
                    throw ECSError("Component not registered before use.");
                }
                return (std::static_pointer_cast<ComponentArray<T>>(
                    this->_componentArrays[typeName]
                ));
            }
    };
}

#endif /* !COMPONENTMANAGER_HPP_ */
