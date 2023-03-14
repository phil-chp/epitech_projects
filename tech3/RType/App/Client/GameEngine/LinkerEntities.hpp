/*
** EPITECH PROJECT, 2022
** RType
** File description:
** LinkerEntities
*/

#ifndef ENTITYLINKER_HPP_
#define ENTITYLINKER_HPP_
    #include "GameEngine/Entity.hpp"
    #include "GameEngine/GameEntities.hpp"


namespace engine {
    class LinkerEntities
    {
        private:
            LinkerEntities() = default;
            ~LinkerEntities() = default;

            std::map<ecs::Entity, std::vector<ecs::Entity>> _entitiesLinked;

        public:
            static LinkerEntities &getInstance()
            {
                // std::cout << "LinkerEntities" << std::endl;
                static LinkerEntities instance;
                return (instance);
            }

            void addEntity(ecs::Entity entityMain, ecs::Entity entityLinked)
            {
                // std::cout << "LinkerEntities addEntity" << std::endl;
                this->_entitiesLinked[entityMain].push_back(entityLinked);
            }

            std::vector<ecs::Entity> &getEntity(ecs::Entity entity)
            {
                return (this->_entitiesLinked[entity]);
            }

            // std::vector<std::shared_ptr<engine::IEntity>> &getEntityClass(ecs::Entity entity)
            // {
            //     std::vector<std::shared_ptr<engine::IEntity>> entities;
            //     for (ecs::Entity &it : this->_entitiesLinked[entity]) {
            //         entities.push_back(engine::GameEntities::getInstance().getEntity(it));
            //     }
            //     return (entities);
            // }

            void removeEntity(ecs::Entity entity)
            {
                // std::cout << this->_entitiesLinked[entity].size() << std::endl;
                if (this->_entitiesLinked[entity].size() > 0) {
                    for (ecs::Entity &it : this->_entitiesLinked[entity]) {
                        ecs::Coordinator::getInstance().destroyEntity(it);
                    }
                }
                // for (ecs::Entity &it : this->_entitiesLinked[entity]) {
                //     std::cout << "hey" << std::endl;
                //     ecs::Coordinator::getInstance().destroyEntity(it);
                // }
                ecs::Coordinator::getInstance().destroyEntity(entity);
            }
    };


}


#endif /* !ENTITYLINKER_HPP_ */
