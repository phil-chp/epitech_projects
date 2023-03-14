/*
** EPITECH PROJECT, 2022
** RType (Workspace)
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

    #include "Utils/PathBuilder.hpp"
    #include "Utils/Rect.hpp"
    #include "Utils/Vector2.hpp"
    #include "GameEngine/Spawner.hpp"
    #include "GameEngine/Map/Wall.hpp"
    #include "GameEngine/Square.hpp"
    #include <map>
    #include <queue>
    #include <iostream>
    #include <utility>

namespace engine {

    // std::map<unsigned int, std::string> levels {
    //     std::make_pair<unsigned int, std::string>(
    //         0, game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "Default.rt"})),
    //     std::make_pair<unsigned int, std::string>(
    //         1, game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level1.rt"})),
    //     std::make_pair<unsigned int, std::string>(
    //         2, game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level2.rt"}))
    // };

    struct SpawnElement {
        int distance;
        int entityType;
        // int boxType;
        game::Vector2 pos;
        unsigned int repeat;
        // int repeatType;
        float delay;
    };

    class Map {
        public:
            Map() : distance(0), deadBackLine(-1000), deadFrontLine(2920), spawnLine(2220), lifeZone(engine::Square(::game::Vector2(-500, -200), 2920, 1480)) {
                // std::cout << "Map" << std::endl;
                // levels.insert(
                //     std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                //         0,
                //         std::pair<std::string, std::string>(
                //             game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "Default.map"}),
                //             game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "Default.fill"})
                //         )
                //     )
                // );
                levels.insert(
                    std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                        0,
                        std::pair<std::string, std::string>(
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level0.map"}),
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level0.fill"})
                            // game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level1.map"}),
                            // game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level1.fill"})
                        )
                    )
                );
                levels.insert(
                    std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                        1,
                        std::pair<std::string, std::string>(
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level2.map"}),
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level2.fill"})
                        )
                    )
                );
                levels.insert(
                    std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                        2,
                        std::pair<std::string, std::string>(
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level3.map"}),
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level3.fill"})
                        )
                    )
                );
                levels.insert(
                    std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                        3,
                        std::pair<std::string, std::string>(
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level4.map"}),
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level4.fill"})
                        )
                    )
                );
                // levels.insert(
                //     std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                //         4,
                //         std::pair<std::string, std::string>(
                //             game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level5.map"}),
                //             game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level5.fill"})
                //         )
                //     )
                // );
                levels.insert(
                    std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                        5,
                        std::pair<std::string, std::string>(
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level6.map"}),
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level6.fill"})
                        )
                    )
                );
                levels.insert(
                    std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                        6,
                        std::pair<std::string, std::string>(
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level7.map"}),
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level7.fill"})
                        )
                    )
                );
                levels.insert(
                    std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                        7,
                        std::pair<std::string, std::string>(
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level8.map"}),
                            game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", "level8.fill"})
                        )
                    )
                );
            };

            ~Map() = default;

            // static Map &getInstance()
            // {
            //     static Map instance;
            //     return (instance);
            // }

            void load(unsigned int lvl) {
                this->distance = 0;
                FILE *infile;

                infile = fopen (levels.at(lvl).second.c_str(), "r");
                if (infile == NULL) {
                    std::cout << "path failed" << std::endl;
                    std::cout << levels.at(lvl).second.c_str() << std::endl;

                    // throw
                }
                engine::SpawnElement elem;
                while (!this->toSpawn.empty()) {
                    this->toSpawn.pop();
                }
                while(fread(&elem, sizeof(engine::SpawnElement), 1, infile) != 0) {
                    this->toSpawn.push(elem);
                }
                fclose(infile);


                infile = fopen (levels.at(lvl).first.c_str(), "r");
                if (infile == NULL) {
                    std::cout << "path failed" << std::endl;
                    std::cout << levels.at(lvl).first.c_str() << std::endl;

                    // throw
                }
                std::pair<int, int> wall;
                while (!this->walls.empty()) {
                    this->walls.pop();
                }
                while(fread(&wall, sizeof(std::pair<int, int>), 1, infile) != 0) {
                    this->walls.push(wall);
                }
                fclose(infile);
            }

            void run(float dt) {
                static int check = 0;
                static int wTrig = WALLXSIZE;
                this->distance +=  100 * dt; // * baseScroll speed
                if (this->distance >= check) {
                    // std::cout << "reached " << this->distance << std::endl;
                    check += 100;
                }
                if (this->distance > wTrig && !this->walls.empty()) {
                    std::pair<int, int> pair = this->walls.front();
                    ::game::Vector2 pos(1920, 0);

                    engine::Wall upWall(pos, pair.first);

                    pos.y = 1080 - 100 * pair.second;
                    engine::Wall downWall(pos, pair.second);
                    // std::cout << "spawned walls" << std::endl;

                    wTrig += WALLXSIZE;
                    this->walls.pop();
                }
                // std::cout << this->distance << std::endl;
                while(!toSpawn.empty()) {
                    engine::SpawnElement &elem = toSpawn.front();
                    if (elem.distance <= this->spawnLine + this->distance ) {
                        engine::Spawner spawner;
                        if (elem.delay > 0) {
                            spawner.addDelay(elem.delay);
                        }
                        spawner.setPos(elem.pos);
                        spawner.setType(elem.entityType);
                        spawner.setReps(elem.repeat);
                        // std::cout << elem.repeat << std::endl;
                        // spawner.setRepType(elem.repeatType);
                        this->toSpawn.pop();
                    } else {
                        break;
                    }
                }
            }

            //TODO Noise
            const engine::Square &getLifeZone() const {
                return (this->lifeZone);
            };

            unsigned int generate(size_t size, size_t length, std::string const &mapName, std::string const &bossPath /*Noise FCT*/ ) {
                std::string mapPath = game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", mapName + ".map"});
                std::string fillPath = game::PathBuilder::getPath(std::vector<std::string>{"Assets", "Map", mapName + ".fill"});
                auto it = std::find_if(this->levels.begin(), this->levels.end(), [&mapPath, &fillPath](std::pair<unsigned int, std::pair<std::string, std::string>> pair) {
                    return (pair.second.first == mapPath && pair.second.second == fillPath);
                });
                if (it != this->levels.end()) {
                    return it->first;
                }
                int key = levels.size();

                std::vector<std::pair<int, int>> walls;
                // std::vector<std::string> map;
                // map.reserve(11); // unnecessary ?
                // for (int i = 0; i < 11; ++i) {
                //     std::string line(size, '.');
                //     map.push_back(line);
                // }
                std::vector<SpawnElement> spawns;
                this->fill(spawns, length); // TODO: HTF do i do this ??
                this->populate(walls, size, length);

                levels.insert(std::make_pair<unsigned int, std::pair<std::string, std::string>>(
                    key,
                    std::pair<std::string, std::string>(mapPath, fillPath)
                ));

                FILE *outfile;

                outfile = fopen (mapPath.c_str(), "w");
                for (auto wall : walls) {
                    fwrite(&wall, sizeof(std::pair<int, int>), 1, outfile);
                }
                fclose (outfile);

                outfile = fopen (fillPath.c_str(), "w");
                for (auto spawn : spawns) {
                    fwrite(&spawn, sizeof(SpawnElement), 1, outfile);
                }
                fclose(outfile);
                return key;
            }

            void debugMap(std::string const &mapPath) {
                FILE *infile;

                infile = fopen (mapPath.c_str(), "r");
                std::vector<std::pair<int, int>> pairs;
                std::pair<int, int> pair;
                while(fread(&pair, sizeof(std::pair<int, int>), 1, infile) != 0) {
                    pairs.push_back(pair);
                }

                fclose(infile);

                std::vector<std::string> map;
                map.reserve(11); // unnecessary ?
                for (int i = 0; i < 11; ++i) {
                    std::string line(pairs.size(), '.');
                    map.push_back(line);
                }
                for (size_t  i = 0; i < pairs.size(); ++i) {
                    for (int k = 0; k < pairs[i].first; ++k) {
                        map[k][i] = '#';
                    }
                    for (int k = 1; k <= pairs[i].second; ++k) {
                        map[map.size() - k][i] = '#';
                    }
                }
                for (std::string const &line : map) {
                    std::cout << line << std::endl;
                }
            }

            void debugFill(std::string const &fillPath) {
                FILE *infile;

                infile = fopen (fillPath.c_str(), "r");
                std::vector<SpawnElement> spawns;
                SpawnElement elem;
                while(fread(&elem, sizeof(engine::SpawnElement), 1, infile) != 0) {
                    spawns.push_back(elem);
                }
                fclose(infile);

                for (SpawnElement const &elem : spawns) {
                    std::cout << "--------Element--------" << std::endl;
                    std::cout << "\ttype = " << elem.entityType << std::endl;
                    std::cout << "\tdistance = " << elem.distance << std::endl;
                    std::cout << "\tdelay = " << elem.delay << std::endl;
                    std::cout << "\trepeat = " << elem.repeat << std::endl;
                    std::cout << "\tpos = {" << elem.pos.x << ", " << elem.pos.y << "}" << std::endl;
                }
            }

            void debugAll() {
                for (auto level : this->levels) {
                    this->debugMap(level.second.first);
                    std::cout << "--" <<std::endl;
                    // this->debugFill(level.second.second);
                }
            }

            float distance;
            float deadBackLine;
            float deadFrontLine;
            // float deadUpLine;
            // float deadDownLine;
            float spawnLine;
            engine::Square lifeZone;
            // ::game::Rect lifeSquare;
            std::queue<SpawnElement> toSpawn;
            std::queue<std::pair<int, int>> walls;

        private:
            std::map<unsigned int, std::pair<std::string, std::string>> levels;

            void fill(std::vector<SpawnElement> &spawns, size_t length) {
                for (size_t i = 0; i < length; ++i) {
                    while(rand() % 100 < 60) {
                        if (rand() % 100 < 20) {
                            SpawnElement element;
                            element.distance = i * 100;
                            element.pos = ::game::Vector2(this->spawnLine, /*random*/ rand() % 1000);
                            element.delay = 3.f;
                            element.repeat = rand() % 6;
                            // element.repeatType = 1;
                            element.entityType = 14;
                            spawns.push_back(element);
                            // std::cout << "added spawn" << std::endl;
                        }
                    }

                }

            }

            void populate(std::vector<std::pair<int, int>> &walls, size_t mapSize, size_t mapLength) {
                walls.push_back(std::pair<int, int>(1, 1));

                for (size_t y = 1; y < mapLength; ++y) {
                    int up = walls.back().first + (1 - rand() % 3);
                    if (up < 0) {
                        up = 0;
                    }
                    int down = walls.back().second + (1 - rand() % 3);
                    if (down < 0) {
                        down = 0;
                    }
                    if (up + down >= mapSize - 3) {
                        (up > down) ? (up -= 3) : (down -= 3);
                    }
                    walls.push_back(std::pair<int, int>(up, down));
                }
            }
    };
}//engine

#endif
