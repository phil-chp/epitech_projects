/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** GridCell
*/

#ifndef GRIDCELL_HPP_
    #define GRIDCELL_HPP_

    #include "GameEngine/Square.hpp"
    #include "Lib/Raylib/rl-cpp/Windows/Windows.hpp"
    #include "ECS/Components/Hitbox.hpp"
    #include "ECS/Component.hpp"


namespace engine {
    class GridCell {
        public:
            GridCell() : coord(0, 0), surface(engine::Square({0, 0}, 0, 0)) {};
            GridCell(unsigned short x, unsigned short y, engine::Square &surface) : coord(x, y), surface(surface)
            {
            };
            ~GridCell() = default;

            void populate(std::shared_ptr<AShape> hitbox, ecs::Entity entity);

            void checkCollisions();

            size_t containerSize() const;

            void clear() {
                this->contains.clear();
            };

            void dump() const {
                // std::cout << "of surface {" << this->surface.pos.x << ", " << this->surface.pos.y << ", " << this->surface.val.a << ", " << this->surface.val.b << "}" << std::endl;
                for (auto entity : this->contains) {
                    std::cout << entity << "--   ,   --";
                }
                std::cout << std::endl;
            }

        private:
            game::Vector2 coord;
            engine::Square surface;
            std::vector<::ecs::Entity> contains;
    };
} // engine
#endif
