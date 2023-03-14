/*
** EPITECH PROJECT, 2022
** RType
** File description:
** SmallShipManager
*/

#ifndef SMALLSHIPMANAGER_HPP_
#define SMALLSHIPMANAGER_HPP_

    #include "GameEngine/Projectile.hpp"
    #include "GameEngine/RType/Particles/Propulsion.hpp"
    #include "GameEngine/RType/Shoot/Movement.hpp"
    #include "GameEngine/Square.hpp"
    #include "GameEngine/RType/Shoot/SmallShipBullet.hpp"
    #include "Utils/Vector2.hpp"
    #include "GameEngine/RType/Shoot/SmallShip.hpp"
    #include "GameEngine/LinkerEntities.hpp"


namespace engine {
namespace rtype {
class SmallShipManager : public engine::Entity {
    public:
        SmallShipManager(::ecs::Entity ent, unsigned int playerId = 0, ::game::Vector2 pos = {50, 200}) : engine::Entity(), shipUp(playerId, ::game::Vector2(pos.x + 50, pos.y - 50), 0), shipDown(playerId, ::game::Vector2(pos.x + 50, pos.y + 90), 1), linkedEntity(ent) {
            ::ecs::Coordinator::getInstance().addComponent(
                this->entity,
                ecs::Alive {
                    .hp = 1,
                    .dead = false,
                    .shield = false
                }
            );
            engine::LinkerEntities::getInstance().addEntity(ent, this->entity);
            engine::LinkerEntities::getInstance().addEntity(ent, shipUp.entity);
            engine::LinkerEntities::getInstance().addEntity(ent, shipDown.entity);
            engine::LinkerEntities::getInstance().addEntity(this->entity, shipUp.entity);
            engine::LinkerEntities::getInstance().addEntity(this->entity, shipDown.entity);
            engine::GameEntities::getInstance().addEntity(std::make_shared<engine::rtype::SmallShipManager>(*this));
        }
        ~SmallShipManager() = default;

        void updatePosition() {
            ::ecs::Transform &transform = ::ecs::Coordinator::getInstance().getComponent<::ecs::Transform>(linkedEntity);
            shipUp.setPos(::game::Vector2(transform.position.x + 50, transform.position.y - 50));
            shipDown.setPos(::game::Vector2(transform.position.x + 50, transform.position.y + 90));
        }

        engine::rtype::SmallShip shipUp;
        engine::rtype::SmallShip shipDown;
        ecs::Entity linkedEntity;

};
} // namespace rtype
} // namespace engine

#endif /* !SMALLSHIPMANAGER_HPP_ */
