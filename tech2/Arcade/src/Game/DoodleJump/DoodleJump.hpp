/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** DoodleJump
*/

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
        struct DoodleJumpConfig {
            // nothing to do
        };

        struct DoodleJumpData {
            DoodleJumpData(void) {};
            DoodleJumpData(arc::Tick tick, std::map<char const, arc::InfoObject> dic, arc::GameMeta meta)
            {
                this->_meta = meta;
                this->_dic = dic;
                this->_tick = tick;
            };
            std::map<char const, arc::InfoObject> _dic;
            arc::Tick _tick;
            arc::GameMeta _meta;
        };

        class DoodleJump
            : public IGame
            , public Wrapper<DoodleJumpConfig, DoodleJumpData>
        {
            public:
                DoodleJump();
                ~DoodleJump();
                // IGame
                void simulate(Tick, TransEvent) final;
                arc::LibType getSignature() const final;
                void initGame(void);
                arc::GameMeta getMeta(void);
                std::tuple<arc::LibType, std::string> handleClick(arc::Coords coords);
                void animate(arc::Tick, arc::TransEvent);

                //getter and setter
                arc::Tick getTick(void);
                void setTick(arc::Tick);
                std::map<char const, arc::InfoObject> getDic(void);
                void setDic(std::map<char const, arc::InfoObject> dic);

            private:
                Tick _applyEvent(Tick, TransEvent);
                Tick _move(Tick, TransEvent);
                Tick _applyMove(Tick, std::vector<int>);
                bool _canMove(Tick, std::vector<int>, std::vector<int>);
                std::vector<int> _getPlayerPos(std::vector<std::string>);
        };
    };
};


extern "C"  std::unique_ptr<arc::game::IGame> getUniqueClass();
