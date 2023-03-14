/*
** EPITECH PROJECT, 2022
** RType
** File description:
** ComponentArray
*/

#ifndef COMPONENTARRAY_HPP_
    #define COMPONENTARRAY_HPP_

    #include "ECS/Entity.hpp"
    #include <algorithm>
    #include <memory>
    #include <unordered_map>

namespace ecs {
    class IComponentArray {
        public:
            virtual ~IComponentArray() = default;
            virtual void destroyEntity(Entity entity) = 0;
    };

    template<typename T>
    class ComponentArray: public IComponentArray {
        public:
            ComponentArray() : mSize(0) {}
            ~ComponentArray() = default;

            void insertData(Entity entity, T component) {
                if (this->_entityToIndexMap.find(entity) != this->_entityToIndexMap.end()) {
                    throw ECSError("Component added to same entity more than once.");
                }

                size_t newIndex = mSize;
                this->_entityToIndexMap[entity] = newIndex;
                this->_indexToEntityMap[newIndex] = entity;
                this->_componentArray[newIndex] = component;
                ++mSize;
            }

            void removeData(Entity entity) {
                if (this->_entityToIndexMap.find(entity) == this->_entityToIndexMap.end()) {
                    throw ECSError("Removing non-existent component.");
                }
                size_t indexOfRemovedEntity = this->_entityToIndexMap[entity];
                size_t indexOfLastElement = mSize - 1;
                this->_componentArray[indexOfRemovedEntity] = this->_componentArray[indexOfLastElement];

                Entity entityOfLastElement = this->_indexToEntityMap[indexOfLastElement];
                this->_entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
                this->_indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

                this->_entityToIndexMap.erase(entity);
                this->_indexToEntityMap.erase(indexOfLastElement);

                --mSize;
            }

            T &getData(Entity entity) {
                if (this->_entityToIndexMap.find(entity) == this->_entityToIndexMap.end()) {
                    throw ECSError("Retrieving non-existent component.");
                }
                return (this->_componentArray[this->_entityToIndexMap[entity]]);
            }

            void destroyEntity(Entity entity) final {
                if (this->_entityToIndexMap.find(entity) != this->_entityToIndexMap.end()) {
                    this->removeData(entity);
                }
            }

        private:
            std::array<T, MAX_ENTITIES> _componentArray;
            std::unordered_map<Entity, size_t> _entityToIndexMap;
            std::unordered_map<size_t, Entity> _indexToEntityMap;
            size_t mSize;
    };
}

#endif /* !COMPONENTARRAY_HPP_ */
