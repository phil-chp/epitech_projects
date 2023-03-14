/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
**      Quentin ROUVIER <quentin.rouvier@epitech.eu>
**      Anthony GHIZZO  <anthony.ghizzo@epitech.eu>
**      Adrian LORENZI  <adrian.lorenzi@epitech.eu>
** File description:
** Sokoban
*/

#include "Game/IGame.hpp"
#include "Core/Wrapper/Wrapper.hpp"
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <stdlib.h>

#define MOVE_LEFT (std::vector<int> {0, -1})
#define MOVE_RIGHT (std::vector<int> {0,  1})
#define MOVE_UP (std::vector<int> {-1, 0})
#define MOVE_DOWN (std::vector<int> {1,  0})

namespace arc
{
    namespace game
    {
        namespace snk
        {

            enum type { NORMAL, STRONG, FAST };
            enum status { WAIT, ALIVE, DEAD };
            enum gameState {RUNNING, LOSE, WIN, PAUSED};

            struct PlayerInfos {
                status stat;
                bool display;
                std::size_t count;
                std::string name;
                std::vector<std::size_t> pos;
                std::string texturePath;
                std::vector<std::size_t> color;
            };

            struct GameData {
                int score;
                int lives;
                int lvl;
                std::string alert;
                gameState state;
            };

            struct MapInfos {
                std::vector<std::size_t> size;
                std::vector<std::string> strings;
            };

            // struct InfosGraph {
            //     std::string spritePath;
            //     std::string color;
            // };

            // struct TestGraphConfig {
            //     std::map<const std::string, InfosGraph> dic;
            // };
        }
    }
}
