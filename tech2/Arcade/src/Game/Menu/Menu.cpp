/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** Menu
*/

#include "Game/Menu/Menu.hpp"

#define DEFAULT_ASSET_PATH  ("Assets/menu/")

arc::game::Menu::Menu()
{
    // nothing todo
}

void arc::game::Menu::initGame(void)
{
    MenuData data;

    data._tick._map.push_back("              "); // M Music, S SFX
    data._tick._map.push_back("    EFGHIJ    "); // T Title
    data._tick._map.push_back("              ");
    data._tick._map.push_back("   ab ef ij   ");
    data._tick._map.push_back("   cd gh kl   "); // SDL, Ncurse, GL
    data._tick._map.push_back("              ");
    data._tick._map.push_back("   mn op qr   ");
    data._tick._map.push_back("              "); // N Nibbler, D doodlejump, P pacman
    data._tick._map.push_back("     s  t     ");
    data._tick._map.push_back("              ");

    data._meta.bg.push_back("Assets/Menu/bg/s1.bmp");
    data._meta.bg.push_back("Assets/Menu/bg/s2.bmp");
    data._meta.bg.push_back("Assets/Menu/bg/s3.bmp");
    data._meta.isMenu = true;
    data._meta.pad = 64;

    data._dic = {
        // { 'P', arc::InfoObject("Assets/Menu/settings/cursor.bmp", Color()) },
        { 'a', arc::InfoObject("Assets/Menu/game/doodlejump/p1.bmp", Color()) },
        { 'b', arc::InfoObject("Assets/Menu/game/doodlejump/p2.bmp", Color()) },
        { 'c', arc::InfoObject("Assets/Menu/game/doodlejump/p3.bmp", Color()) },
        { 'd', arc::InfoObject("Assets/Menu/game/doodlejump/p4.bmp", Color()) },
        { 'e', arc::InfoObject("Assets/Menu/game/snake/p1.bmp", Color()) },
        { 'f', arc::InfoObject("Assets/Menu/game/snake/p2.bmp", Color()) },
        { 'g', arc::InfoObject("Assets/Menu/game/snake/p3.bmp", Color()) },
        { 'h', arc::InfoObject("Assets/Menu/game/snake/p4.bmp", Color()) },
        { 'i', arc::InfoObject("Assets/Menu/game/pacman/p1.bmp", Color()) },
        { 'j', arc::InfoObject("Assets/Menu/game/pacman/p2.bmp", Color()) },
        { 'k', arc::InfoObject("Assets/Menu/game/pacman/p3.bmp", Color()) },
        { 'l', arc::InfoObject("Assets/Menu/game/pacman/p4.bmp", Color()) },
        // graph
        { 'm', arc::InfoObject("Assets/Menu/graph/opgl/p1.bmp", Color()) },
        { 'n', arc::InfoObject("Assets/Menu/graph/opgl/p2.bmp", Color()) },
        { 'o', arc::InfoObject("Assets/Menu/graph/ncurses/p1.bmp", Color()) },
        { 'p', arc::InfoObject("Assets/Menu/graph/ncurses/p2.bmp", Color()) },
        { 'q', arc::InfoObject("Assets/Menu/graph/sdl/p1.bmp", Color()) },
        { 'r', arc::InfoObject("Assets/Menu/graph/sdl/p2.bmp", Color()) },
        // music and sound
        { 's', arc::InfoObject("Assets/Menu/settings/music/p1.bmp", Color()) },
        { 't', arc::InfoObject("Assets/Menu/settings/sound/p1.bmp", Color()) },
        //title
        { 'E', arc::InfoObject("Assets/Menu/settings/title/A1.bmp", Color()) },
        { 'F', arc::InfoObject("Assets/Menu/settings/title/R.bmp", Color()) },
        { 'G', arc::InfoObject("Assets/Menu/settings/title/C.bmp", Color()) },
        { 'H', arc::InfoObject("Assets/Menu/settings/title/A2.bmp", Color()) },
        { 'I', arc::InfoObject("Assets/Menu/settings/title/D.bmp", Color()) },
        { 'J', arc::InfoObject("Assets/Menu/settings/title/E.bmp", Color()) },
        { '#', arc::InfoObject("Assets/sprite/wall.bmp", Color()) }
    };

    std::shared_ptr<MenuData> data_ptr(new MenuData(data));
    this->setData(data_ptr);
}

arc::game::Menu::~Menu()
{
    // nothing to do
}

arc::Tick arc::game::Menu::getTick(void)
{
    return this->getData().get()->_tick;
}

void arc::game::Menu::setTick(arc::Tick tick)
{
    MenuData *data = this->getData().get();
    data->_tick = tick;
}

std::map<char const, arc::InfoObject> arc::game::Menu::getDic(void)
{
    return this->getData().get()->_dic;
}

void arc::game::Menu::setDic(std::map<char const, arc::InfoObject> dic)
{
    MenuData *data = this->getData().get();
    data->_dic = dic;
}

arc::GameMeta arc::game::Menu::getMeta(void)
{
    return this->getData().get()->_meta;
}

void arc::game::Menu::setMeta(arc::GameMeta meta)
{
    MenuData *data = this->getData().get();
    data->_meta = meta;
}

arc::LibType arc::game::Menu::getSignature() const
{
    return (arc::GAME);
}

void arc::game::Menu::simulate(arc::Tick tick, arc::TransEvent event)
{
    this->setTick(this->_applyEvent(tick, event));
}

// -------------------------------- Private --------------------------------- //

arc::Tick arc::game::Menu::_applyEvent(arc::Tick tick, arc::TransEvent event)
{
    if (event == arc::UP   || event == arc::DOWN   \
    ||  event == arc::LEFT || event == arc::RIGHT) {
        return (this->_move(tick, event));
    }
    // if (event == SPECIAL)
    return (tick); // nothing for now
}

arc::Tick arc::game::Menu::_move(arc::Tick tick, arc::TransEvent event)
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

arc::Tick arc::game::Menu::_applyMove(arc::Tick tick, std::vector<int> direction)
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

bool arc::game::Menu::_canMove(arc::Tick tick, std::vector<int> player, std::vector<int> dir)
{
    return (!!(tick._map[player[0] + dir[0]][player[1] + dir[1]] == ' '));
}

std::vector<int> arc::game::Menu::_getPlayerPos(std::vector<std::string> map)
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

std::tuple<arc::LibType, std::string> arc::game::Menu::handleClick(arc::Coords coords)
{
    arc::LibType libType = (coords.y > 4 ? arc::GRAPH : arc::GAME);
    std::map<arc::LibType, std::map<std::string, std::vector<std::tuple<int, int> > > > test({
        {
            arc::GAME, {
                { "./lib/arcade_doodlejump.so", { { 3, 3 }, { 4,  4 } } },
                { "./lib/arcade_nibbler.so",    { { 6, 3 }, { 7,  4 } } },
                { "./lib/arcade_pacman.so",     { { 9, 3 }, { 10, 4 } } }
            }
        }, {
            arc::GRAPH, {
                { "./lib/arcade_sfml.so",    { { 3, 6 }, { 4,  6 } } },
                { "./lib/arcade_ncurses.so", { { 6, 6 }, { 7,  6 } } },
                { "./lib/arcade_sdl2.so",    { { 9, 6 }, { 10, 6 } } }
            }
        }
    });
    // TODO: auto is not allowed
    for (auto &lib : test[libType]) {
        // TODO: auto is not allowed
        for (auto &pos : lib.second) {
            if (coords.x >= std::get<0>(pos) && coords.y >= std::get<1>(pos)
            &&  coords.x <= std::get<0>(pos) && coords.y <= std::get<1>(pos)) {
                std::tuple<LibType, std::string> libInfo(libType, lib.first);
                return (libInfo);
            }
        }
    }
    return (std::tuple<arc::LibType, std::string>(arc::NOLIB, "bg le github"));
}

void arc::game::Menu::animate(arc::Tick, arc::TransEvent)
{
    return;
}

extern "C" {
    std::unique_ptr<arc::game::IGame> getUniqueClass() {
        return std::make_unique<arc::game::Menu>();
    }
}
