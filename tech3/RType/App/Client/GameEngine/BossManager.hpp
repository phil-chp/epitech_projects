/*
** EPITECH PROJECT, 2022
** RType
** File description:
** BossManager
*/

#ifndef BOSSMANAGER_HPP_
#define BOSSMANAGER_HPP_

    #include "GameEngine/Entity.hpp"
    #include "GameEngine/EntityFactory.hpp"

namespace engine {
    const std::map<int, engine::EntityType> bossTypes = {
        std::make_pair<int, engine::EntityType>(0, engine::EntityType::BERIC),
        std::make_pair<int, engine::EntityType>(1, engine::EntityType::CONTREUNO),
        std::make_pair<int, engine::EntityType>(2, engine::EntityType::FEUR)
    };

class BossManager {
    public:


        BossManager(int lvl = 0)
        {
            this->bossPtr = engine::EntityFactory::createEngineEntity(bossTypes.at(lvl));
            this->boss = this->bossPtr->getEntity();
        }
        ~BossManager() = default;

        void load(int lvl) {
            ecs::Coordinator &coord = ecs::Coordinator::getInstance();
            coord.destroyEntity(this->boss);
            this->bossPtr = EntityFactory::createEngineEntity(bossTypes.at(lvl));
            this->boss = this->bossPtr->getEntity();
        }

        std::shared_ptr<engine::IEntity> getBossPtr() {
            return (this->bossPtr);
        }


        std::shared_ptr<engine::IEntity> bossPtr;
        ecs::Entity boss;


};
}


#endif /* !BOSSMANAGER_HPP_ */
