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

#ifndef ARCADE_SNAKE_HPP
#define ARCADE_SNAKE_HPP

#include "Game/IGame.hpp"
#include "Core/Wrapper/Wrapper.hpp"
#include "Shared/Arcade.hpp"
#include "Utils.hpp"
#include <vector>
#include <map>
#include <string>
#include <memory>

namespace arc
{
    namespace game
    {
        struct SnakeConfig {
            bool isFinish;
        };

        struct SnakeData {
            SnakeData(void) {};
            SnakeData(arc::Tick tick, std::map<char const, arc::InfoObject> dic, arc::GameMeta meta)
            {
                this->_meta = meta;
                this->_dic = dic;
                this->_tick = tick;
            };
            std::map<char const, arc::InfoObject> _dic;
            arc::Tick _tick;
            arc::GameMeta _meta;
        };

        class Snake
            : public IGame
            , public Wrapper<SnakeConfig, SnakeData> {
        public:
            Snake();
            ~Snake();
            // IGame
            void simulate(Tick, TransEvent) final;
            arc::LibType getSignature() const final;
            void initGame(void);
            void setFinish(bool);
            arc::GameMeta getMeta(void);
            std::tuple<arc::LibType, std::string> handleClick(arc::Coords coords);
            void animate(arc::Tick, arc::TransEvent);

            // getter and setter
            arc::Tick getTick(void);
            void setTick(arc::Tick);
            std::map<char const, arc::InfoObject> getDic(void);
            void setDic(std::map<char const, arc::InfoObject> dic);



            int len = 4;
            int nbApple = 0;
            int prevmov = 1;
            int test = 0;
            int score = 0;

        private:
            Tick _applyEvent(Tick, TransEvent);
            Tick _move(Tick, TransEvent);
            Tick _autoMove(Tick);
            Tick _applyMove(Tick, std::vector<int>);
            Tick _applyMoveBody(Tick);
            void _growBody(Tick &tick);
            bool _canMove(Tick, std::vector<int>, std::vector<int>);
            bool _winAndLose(Tick);
            void _spawnApple(Tick);
            std::vector<int> _getPlayerPos(std::vector<std::string>);
            std::vector<int> _getEndPos(std::vector<std::string>);
            std::vector<int> _getApplePos(std::vector<std::string>);
            void _getNbApple(std::vector<std::string>);
        };
    }
}

extern "C"  std::unique_ptr<arc::game::IGame> getUniqueClass();

#endif //ARCADE_SNAKE_HPP
