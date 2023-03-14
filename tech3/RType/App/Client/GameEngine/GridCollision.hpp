/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** GridCollision
*/

#ifndef GRIDCOLLISION_HPP_
    #define GRIDCOLLISION_HPP_

    #include <iostream>
    #include <set>
    #include "GameEngine/GridCell.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Rect.hpp"

    #define XGRIDSIZE 8
    #define YGRIDSIZE 8

namespace engine {
    class GridSystem {
        public:
            static GridSystem &getInstance(unsigned short w = XGRIDSIZE, unsigned short h = YGRIDSIZE)
            {
                static GridSystem instance(w, h);
                return (instance);
            };

            // std::vector<GridCell> getNeighbours(unsigned short x, unsigned short y);
            // std::vector<engine::GridCell> getNeighbours(engine::GridCell &cell);

            void populateCells(std::set<ecs::Entity> entities);

            void getCollisions();

            void dump() const {
                std::cout << "---------------------GRID------------------" << std::endl;
                for (auto line : grid) {
                    std::cout << "********" << std::endl;
                    for (auto cell : line) {
                        cell.dump();
                    }
                }
            };

            ~GridSystem() = default;
        private:
            GridSystem(unsigned short w = XGRIDSIZE, unsigned short h = YGRIDSIZE);

            unsigned short w;
            unsigned short h;
            std::vector<std::vector<engine::GridCell>> grid;
    };
} // engine
#endif
