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

#include "Game/DoodleJump/DoodleJump.hpp"

arc::game::DoodleJump::DoodleJump()
{
    // nothing to do
}

//  create initGame
void arc::game::DoodleJump::initGame(void)
{
    DoodleJumpData data;

    data._tick._map.clear();
    data._tick._map.push_back("###################");
    data._tick._map.push_back("#              #  #");
    data._tick._map.push_back("#  E      ######  #");
    data._tick._map.push_back("####              #");
    data._tick._map.push_back("####              #");
    data._tick._map.push_back("####    P         #");
    data._tick._map.push_back("####              #");
    data._tick._map.push_back("#       #    ######");
    data._tick._map.push_back("#       #    #   ##");
    data._tick._map.push_back("#      ###   #   ##");
    data._tick._map.push_back("#            #   ##");
    data._tick._map.push_back("#                ##");
    data._tick._map.push_back("###  ###     ######");
    data._tick._map.push_back("##E           E   #");
    data._tick._map.push_back("###################");

    data._meta.bg.clear();
    data._meta.bg.push_back("Assets/Menu/bg/s1.bmp");
    data._meta.isMenu = false;
    data._meta.pad = 32;

    data._dic.clear();
    data._dic = {
        { '#', arc::InfoObject("Assets/sprite/wall.bmp",   Color()) },
        { 'P', arc::InfoObject("Assets/sprite/player.bmp", Color()) },
        { 'E', arc::InfoObject("Assets/sprite/enemy.bmp",  Color()) },
    };

    std::shared_ptr<DoodleJumpData> data_ptr(new DoodleJumpData(data));
    this->setData(data_ptr);
}

arc::game::DoodleJump::~DoodleJump()
{
    // nothing to do
}

arc::Tick arc::game::DoodleJump::getTick(void)
{
    return this->getData().get()->_tick;
}

void arc::game::DoodleJump::setTick(arc::Tick tick)
{
    DoodleJumpData *data = this->getData().get();
    data->_tick = tick;
}

std::map<char const, arc::InfoObject> arc::game::DoodleJump::getDic(void)
{
    return this->getData().get()->_dic;
}

void arc::game::DoodleJump::setDic(std::map<char const, arc::InfoObject> dic)
{
    DoodleJumpData *data = this->getData().get();
    data->_dic = dic;
}

arc::LibType arc::game::DoodleJump::getSignature() const
{
    return (arc::GAME);
}

void arc::game::DoodleJump::simulate(arc::Tick tick, arc::TransEvent event)
{
    this->setTick(this->_applyEvent(tick, event));
    // return (this->_applyEvent(tick, event));
}

// -------------------------------- Private --------------------------------- //

arc::Tick arc::game::DoodleJump::_applyEvent(arc::Tick tick, arc::TransEvent event)
{
    if (event < arc::SPECIAL) {
        return (this->_move(tick, event));
    }
    // if (event == SPECIAL)
    return (tick); // nothing for now
}

arc::Tick arc::game::DoodleJump::_move(arc::Tick tick, arc::TransEvent event)
{
    switch (event) {
        case (arc::UP):
            return (this->_applyMove(tick, MOVE_UP));
        case (arc::DOWN):
            return (this->_applyMove(tick, MOVE_DOWN));
        case (arc::LEFT):
            return (this->_applyMove(tick, MOVE_LEFT));
        case (arc::RIGHT):
            return (this->_applyMove(tick, MOVE_RIGHT));
        default:
            break;
    }
    return (this->_applyMove(tick, MOVE_RIGHT));
}

arc::Tick arc::game::DoodleJump::_applyMove(arc::Tick tick, std::vector<int> direction)
{
    std::vector<int> playerPos = this->_getPlayerPos(tick._map);

    if (this->_canMove(tick, playerPos, direction)) {
        size_t x = playerPos[0] + direction[0];
        size_t y = playerPos[1] + direction[1];

        tick._map[x][y] = tick._map[playerPos[0]][playerPos[1]];
        tick._map[playerPos[0]][playerPos[1]] = ' ';
    }
    return (tick);
}

bool arc::game::DoodleJump::_canMove(arc::Tick tick, std::vector<int> player, std::vector<int> dir)
{
    return (!!(tick._map[player[0] + dir[0]][player[1] + dir[1]] == ' '));
}

std::vector<int> arc::game::DoodleJump::_getPlayerPos(std::vector<std::string> map)
{
    std::vector<int> defaultPos({-1, -1});

    for (int i = 0; map[i].size() != 0; i++) {
        for (int y = 0; map[i][y]; y++) {
            std::vector<int> pos({i, y});
            if (map[i][y] == 'P') return (pos);
        }
    }
    return (defaultPos); // throw error
}

arc::GameMeta arc::game::DoodleJump::getMeta(void)
{
    return this->getData().get()->_meta;
}

std::tuple<arc::LibType, std::string> arc::game::DoodleJump::handleClick(arc::Coords coords)
{
    (void)coords;
    return (std::tuple<arc::LibType, std::string>(arc::NOLIB, "bg le github"));
}

void arc::game::DoodleJump::animate(arc::Tick, arc::TransEvent)
{
    return;
}

extern "C" {
    std::unique_ptr<arc::game::IGame> getUniqueClass() {
        return std::make_unique<arc::game::DoodleJump>();
    }
}
