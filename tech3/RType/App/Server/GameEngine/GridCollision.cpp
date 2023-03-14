/*
** EPITECH PROJECT, 2022
** RType
** File description:
** GridSystem
*/

#include "GameEngine/GridCollision.hpp"
#include "ECS/Coordinator.hpp"

// template<unsigned int W, unsigned int H>
// std::vector<engine::GridCell> engine::GridSystem<W, H>::getNeighbours(unsigned short x, unsigned short y) {
//     std::vector<engine::GridCell> neighbours;
//     if (x > 1) {
//         neighbours.push_back(grid[y][x - 1]);
//     }
//     if (x < W - 1) {
//         neighbours.push_back(grid[y][x + 1]);
//     }
//     if (y > 1) {
//         neighbours.push_back(grid[y - 1][x]);
//     }
//     if (x < H - 1) {
//         neighbours.push_back(grid[y + 1][x]);
//     }
//     return (neighbours);
// }

// template<unsigned int W, unsigned int H>
// std::vector<engine::GridCell> engine::GridSystem<W, H>::getNeighbours(engine::GridCell &cell) {
//     std::vector<engine::GridCell> neighbours;
//     if (cell.coord.x > 1) {
//         neighbours.push_back(grid[cell.coord.y][cell.coord.x - 1]);
//     }
//     if (cell.coord.x < W - 1) {
//         neighbours.push_back(grid[cell.coord.y][cell.coord.x + 1]);
//     }
//     if (cell.coord.y > 1) {
//         neighbours.push_back(grid[cell.coord.y - 1][cell.coord.x]);
//     }
//     if (cell.coord.x < H - 1) {
//         neighbours.push_back(grid[cell.coord.y + 1][cell.coord.x]);
//     }
//     return neighbours;
// }

engine::GridSystem::GridSystem(unsigned short w, unsigned short h)
    : w(w), h(h)
{
    int width  = 1920 / this->w;
    int height = 1080 / this->h;
    for (unsigned short y = 0; y < this->h; ++y) {
        std::vector<engine::GridCell> tmp;
        for (unsigned short x = 0; x < this->w; ++x) {
            engine::Square square({(float) x * width,(float) y * height}, width, height);
            tmp.push_back(GridCell(x, y, square));
        }
        grid.push_back(tmp);
    }
};

void engine::GridSystem::populateCells(std::set<ecs::Entity> entities) {
    // std::cout << entities.size() << std::endl;
    for (ecs::Entity const &entity : entities) {
        ecs::Hitbox &hitbox = ecs::Coordinator::getInstance().getComponent<ecs::Hitbox>(entity);
        // std::cout << "-----checking surface {" << hitbox.bounds->pos.x << ", " << hitbox.bounds->pos.y << ", " << hitbox.bounds->val.a << ", " << hitbox.bounds->val.b << "}" << std::endl;
        for (std::vector<engine::GridCell> &line : grid) {
            for (engine::GridCell &cell : line) {
                cell.populate(hitbox.bounds, entity);
            }
        }
    }
}

void engine::GridSystem::getCollisions() {

    for (std::vector<engine::GridCell> &line : grid) {
        for (engine::GridCell &cell : line) {
            if (cell.containerSize() > 1) {
                cell.checkCollisions();
            }
            cell.clear();
        }
    }
}
