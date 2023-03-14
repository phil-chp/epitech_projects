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

#ifndef ARCADE_PACMAN_HPP
# define ARCADE_PACMAN_HPP

# include "Game/IGame.hpp"
# include "Shared/Arcade.hpp"
# include "Core/Wrapper/Wrapper.hpp"
# include "Utils.hpp"
# include <vector>
# include <map>
# include <memory>

namespace arc
{
    namespace game
    {
        struct PacmanConfig {
            bool isFinish;
        };

        struct PacmanData {
            PacmanData(void) {};
            PacmanData(arc::Tick tick, std::map<char const, arc::InfoObject> dic, arc::GameMeta meta)
            {
                this->_meta = meta;
                this->_dic = dic;
                this->_tick = tick;
            };
            std::map<char const, arc::InfoObject> _dic;
            arc::Tick _tick;
            arc::GameMeta _meta;
        };

        class Pacman : public IGame, public Wrapper<PacmanConfig, PacmanData> {
        public:
            Pacman();
            ~Pacman();
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

            int nbApple = 0;
            int nbGum = 1;
            int len = 4;
            int prevmovR = 3;
            int prevmovB = 3;
            int prevmovE = 3;
            int prevmov = 2;
            int test = 0;
            bool eatGum = false;
            int score = 0;

        private:
            Tick _applyEvent(Tick, TransEvent);
            Tick _move(Tick, TransEvent);
            Tick _autoMoveGhost(Tick);
            Tick _autoMoveGhostB(Tick);
            Tick _autoMoveGhostR(Tick);
            Tick _autoMove(Tick);
            Tick _applyMove(Tick, std::vector<int>);
            Tick _applyMoveBody(Tick, std::vector<int>);
            Tick _applyMoveGhost(Tick, std::vector<int>);
            Tick _applyMoveGhostE(Tick, std::vector<int>);
            void _growBody(Tick &tick);
            bool _canMove(Tick, std::vector<int>, std::vector<int>);
            bool _winAndLose(Tick);
            std::vector<int> _getPlayerPos(std::vector<std::string>);
            std::vector<int> _getGhostPos(std::vector<std::string>);
            std::vector<int> _getGhostRPos(std::vector<std::string>);
            std::vector<int> _getGhostBPos(std::vector<std::string>);
            void _getNbGum(std::vector<std::string>);
        };
    }
}

extern "C"  std::unique_ptr<arc::game::IGame> getUniqueClass();

#endif //ARCADE_PACMAN_HPP
