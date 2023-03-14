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

#include "Pacman.hpp"

arc::game::Pacman::Pacman()
{
    // nothing to do
}

void arc::game::Pacman::initGame(void)
{
    PacmanData data;

    data._tick._map.push_back("############################");
    data._tick._map.push_back("#............##............#");
    data._tick._map.push_back("#.####.#####.##.#####.####.#");
    data._tick._map.push_back("#..........................#");
    data._tick._map.push_back("#.####.##.########.##.####.#");
    data._tick._map.push_back("#......##....##....##......#");
    data._tick._map.push_back("######.#####.##.#####.######");
    data._tick._map.push_back("######.#####.##.#####.######");
    data._tick._map.push_back("######.##....B.....##.######");
    data._tick._map.push_back("######.##.########.##.######");
    data._tick._map.push_back("######.##.#   E  #.##.######");
    data._tick._map.push_back("#.........# R    #.........#");
    data._tick._map.push_back("######.##.########.##.######");
    data._tick._map.push_back("######.##..........##.######");
    data._tick._map.push_back("######.##.########.##.######");
    data._tick._map.push_back("######.##.########.##.######");
    data._tick._map.push_back("#............##............#");
    data._tick._map.push_back("#.####.#####.##.#####.####.#");
    data._tick._map.push_back("#...##................##...#");
    data._tick._map.push_back("###.##.##.########.##.##.###");
    data._tick._map.push_back("#......##....##....##......#");
    data._tick._map.push_back("#.##########.##.##########.#");
    data._tick._map.push_back("#...........P..............#");
    data._tick._map.push_back("############################");

    data._dic = {
        {'#', arc::InfoObject("Assets/sprite/wall.bmp",   Color())},
        {'P', arc::InfoObject("Assets/sprite/player.bmp", Color())},
        {'E', arc::InfoObject("Assets/sprite/blue.bmp",  Color())},
        {'R', arc::InfoObject("Assets/sprite/blue.bmp",  Color())},
        {'*', arc::InfoObject("Assets/sprite/red.bmp",    Color())},
        {'B', arc::InfoObject("Assets/sprite/blue.bmp",   Color())},
        {'.', arc::InfoObject("Assets/sprite/enemy.bmp",  Color())},
    };

    data._meta.bg.push_back("Assets/Menu/bg/s1.bmp");
    data._meta.isMenu = false;
    data._meta.pad = 32;

    std::shared_ptr<arc::game::PacmanData> data_ptr(new arc::game::PacmanData(data));
    this->setData(data_ptr);

    arc::game::PacmanConfig config;
    std::shared_ptr<arc::game::PacmanConfig> config_ptr(new arc::game::PacmanConfig(config));
    this->setConfig(config_ptr);
}


arc::game::Pacman::~Pacman()
{
    // nothing to do
}

arc::Tick arc::game::Pacman::getTick(void)
{
    return this->getData().get()->_tick;
}

void arc::game::Pacman::setTick(arc::Tick tick)
{
    PacmanData *data = this->getData().get();

    data->_tick = tick;
}

std::map<char const, arc::InfoObject> arc::game::Pacman::getDic(void)
{
    return this->getData().get()->_dic;
}

void arc::game::Pacman::setDic(std::map<char const, arc::InfoObject> dic)
{
    PacmanData *data = this->getData().get();

    data->_dic = dic;
}

arc::LibType arc::game::Pacman::getSignature() const
{
    return (arc::GAME);
}

void arc::game::Pacman::simulate(arc::Tick tick, arc::TransEvent event)
{
    if (event == 0 || event == 1 || event == 2 || event == 3) {
        this->setTick(this->_applyEvent(tick, event));
    } else {
        //this->setTick(this->_autoMoveGhost(tick));
        this->setTick(this->_autoMoveGhostB(tick));
        //this->setTick(this->_autoMoveGhostR(tick));
    }
    //return (this->_applyEvent(tick, event));
}

// -------------------------------- Private --------------------------------- //

arc::Tick arc::game::Pacman::_applyEvent(arc::Tick tick, arc::TransEvent event)
{
    if (event < arc::SPECIAL) {
        return (this->_move(tick, event));
    }
    // if (event == SPECIAL)
    return (tick); // nothing for now
}

arc::Tick arc::game::Pacman::_autoMove(Tick tick) {
    if (this->test) {
        std::vector<int> playerPos = this->_getPlayerPos(tick._map);
    }
    switch (this->prevmov) {
        case 0:
            return (this->_applyMove(tick, MOVE_UP));
        case 1:
            return (this->_applyMove(tick, MOVE_DOWN));
        case 2:
            return (this->_applyMove(tick, MOVE_LEFT));
        case 3:
            return (this->_applyMove(tick, MOVE_RIGHT));
        default:
            return (tick);
    }
}

arc::Tick arc::game::Pacman::_autoMoveGhost(Tick tick)
{
    std::vector<int> playerPos = this->_getGhostPos(tick._map);
    int dir = rand() % 4;

    if (prevmovE == 0) {
        while (_canMove(tick._map, playerPos, MOVE_DOWN))
            return (this->_applyMoveGhost(tick, MOVE_DOWN));
    } else if (prevmovE == 1) {
        while (_canMove(tick._map, playerPos, MOVE_UP))
            return (this->_applyMoveGhost(tick, MOVE_UP));
    } else if (prevmovE == 2) {
        while (_canMove(tick._map, playerPos, MOVE_RIGHT))
            return (this->_applyMoveGhost(tick, MOVE_RIGHT));
    } else if (prevmovE == 3) {
        while (_canMove(tick._map, playerPos, MOVE_LEFT))
            return (this->_applyMoveGhost(tick, MOVE_LEFT));
    }
    while (dir == prevmovE)
        dir = rand() % 4;

    switch (dir) {
        case 0:
            prevmovE = dir;
            return (this->_applyMoveGhost(tick, MOVE_DOWN));
        case 1:
            prevmovE = dir;
            return (this->_applyMoveGhost(tick, MOVE_UP));
        case 2:
            prevmovE = dir;
            return (this->_applyMoveGhost(tick, MOVE_RIGHT));
        case 3:
            prevmovE = dir;
            return (this->_applyMoveGhost(tick, MOVE_LEFT));
        default:
            return (tick);
    }
}

arc::Tick arc::game::Pacman::_autoMoveGhostR(Tick tick) {
    std::vector<int> playerPos = this->_getGhostRPos(tick._map);
    int dir = rand() % 4;
    if (prevmovR == 0) {
        while (_canMove(tick._map, playerPos, MOVE_DOWN))
            return (this->_applyMoveGhost(tick, MOVE_DOWN));
    } else if (prevmovR == 1) {
        while (_canMove(tick._map, playerPos, MOVE_UP))
            return (this->_applyMoveGhost(tick, MOVE_UP));
    } else if (prevmovR == 2) {
        while (_canMove(tick._map, playerPos, MOVE_RIGHT))
            return (this->_applyMoveGhost(tick, MOVE_RIGHT));
    } else if (prevmovR == 3) {
        while (_canMove(tick._map, playerPos, MOVE_LEFT))
            return (this->_applyMoveGhost(tick, MOVE_LEFT));
    }
    while (dir == prevmovR)
        dir = rand() % 4;

    switch (dir) {
        case 0 :
            prevmovR = dir;
            return (this->_applyMoveGhost(tick, MOVE_DOWN));
        case 1 :
            prevmovR = dir;
            return (this->_applyMoveGhost(tick, MOVE_UP));
        case 2:
            prevmovR = dir;
            return (this->_applyMoveGhost(tick, MOVE_RIGHT));
        case 3:
            prevmovR = dir;
            return (this->_applyMoveGhost(tick, MOVE_LEFT));
        default:
            return (tick);
    }
}

arc::Tick arc::game::Pacman::_autoMoveGhostB(Tick tick) {
    std::vector<int> playerPos = this->_getGhostBPos(tick._map);
    int dir2  = 0;
    dir2 = rand() % 4;
    if (prevmovB == 0) {
        while (_canMove(tick._map, playerPos, MOVE_DOWN))
            return (this->_applyMoveGhost(tick, MOVE_DOWN));
    } else if (prevmovB == 1) {
        while (_canMove(tick._map, playerPos, MOVE_UP))
            return (this->_applyMoveGhost(tick, MOVE_UP));
    } else if (prevmovB == 2) {
        while (_canMove(tick._map, playerPos, MOVE_RIGHT))
            return (this->_applyMoveGhost(tick, MOVE_RIGHT));
    } else if (prevmovB == 3) {
        while (_canMove(tick._map, playerPos, MOVE_LEFT))
            return (this->_applyMoveGhost(tick, MOVE_LEFT));
    }
    while (dir2 == prevmovB)
        dir2 = rand() % 4;

    switch (dir2) {
        case 0:
            prevmovB = dir2;
            return (this->_applyMoveGhost(tick, MOVE_DOWN));
        case 1:
            prevmovB = dir2;
            return (this->_applyMoveGhost(tick, MOVE_UP));
        case 2:
            prevmovB = dir2;
            return (this->_applyMoveGhost(tick, MOVE_RIGHT));
        case 3:
            prevmovB = dir2;
            return (this->_applyMoveGhost(tick, MOVE_LEFT));
        default:
            return (tick);
    }
}

arc::Tick arc::game::Pacman::_move(arc::Tick tick, arc::TransEvent event)
{
    switch (event) {
        case (arc::UP):
            this->prevmov = 0;
            return (this->_applyMove(tick, MOVE_UP));
        case (arc::DOWN):
            this->prevmov = 1;
            return (this->_applyMove(tick, MOVE_DOWN));
        case (arc::LEFT):
            this->prevmov = 2;
            return (this->_applyMove(tick, MOVE_LEFT));
        case (arc::RIGHT):
            this->prevmov = 3;
            return (this->_applyMove(tick, MOVE_RIGHT));
        default:
            break;
    }
    return (this->_applyMove(tick, MOVE_RIGHT));
}

arc::Tick arc::game::Pacman::_applyMove(arc::Tick tick, std::vector<int> direction)
{
    std::vector<int> playerPos = this->_getPlayerPos(tick._map);

    //this->_getNbGum(tick._map);

    //TODO: probleme de wincondition
    /*if (this->nbGum == 0) {
        this->setFinish(true);
    }*/
    if (this->_canMove(tick, playerPos, direction)) {
        size_t x = playerPos[0] + direction[0];
        size_t y = playerPos[1] + direction[1];

        if (tick._map[x][y] == '*') {
            this->eatGum = true;
            //TODO : after 10s passer a false
            //changer la coulur des fantome durant les 10s et apres les 10s
        }
        if ((tick._map[x][y] == 'E' && this->eatGum == false)
        ||  (tick._map[x][y] == 'B' && this->eatGum == false)
        ||  (tick._map[x][y] == 'R' && this->eatGum == false)) {
            this->setFinish(true);
            exit(84);
        }
        tick._map[x][y] = tick._map[playerPos[0]][playerPos[1]];
        tick._map[playerPos[0]][playerPos[1]] = ' ';
    }

    return (tick);
}

void arc::game::Pacman::setFinish(bool flag)
{
    PacmanConfig *config = this->getConfig().get();
    config->isFinish = flag;
}

arc::Tick arc::game::Pacman::_applyMoveGhost(arc::Tick tick, std::vector<int> direction)
{
    std::vector<int>  ghostPos = this->_getGhostPos(tick._map);
    //std::vector<int>  ghostRPos = this->_getGhostRPos(tick._map);
    std::vector<int>  ghostBPos = this->_getGhostBPos(tick._map);

    /*if (this->_canMove(tick,  ghostPos, direction)) {
        size_t x =  ghostPos[0] + direction[0];
        size_t y =  ghostPos[1] + direction[1];

        tick._map[x][y] = tick._map[ ghostPos[0]][ ghostPos[1]];
        tick._map[ ghostPos[0]][ ghostPos[1]] = ' ';
    }*/

    if (this->_canMove(tick,  ghostBPos, direction)) {
        size_t xB = ghostBPos[0] + direction[0];
        size_t yB = ghostBPos[1] + direction[1];

        if (tick._map[xB][yB] == '.') {
            tick._map[xB][yB] = tick._map[ghostBPos[0]][ghostBPos[1]];
            tick._map[ghostBPos[0]][ghostBPos[1]] = '.';
        }
        else {
            tick._map[xB][yB] = tick._map[ghostBPos[0]][ghostBPos[1]];
            tick._map[ghostBPos[0]][ghostBPos[1]] = ' ';
        }
    }

    /*if (this->_canMove(tick,  ghostRPos, direction))
    {
        size_t xR =  ghostRPos[0] + direction[0];
        size_t yR =  ghostRPos[1] + direction[1];

        tick._map[xR][yR] = tick._map[ ghostRPos[0]][ ghostRPos[1]];
        tick._map[ ghostRPos[0]][ ghostRPos[1]] = ' ';
    }*/

    return (tick);
}

bool arc::game::Pacman::_canMove(arc::Tick tick, std::vector<int> player, std::vector<int> dir)
{
    return (!!(tick._map[player[0] + dir[0]][player[1] + dir[1]] == ' ') || !!(tick._map[player[0] + dir[0]][player[1] + dir[1]] == '.') || !!(tick._map[player[0] + dir[0]][player[1] + dir[1]] == '*'));
}

std::vector<int> arc::game::Pacman::_getPlayerPos(std::vector<std::string> map)
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

std::vector<int> arc::game::Pacman::_getGhostPos(std::vector<std::string> map)
{
    std::vector<int> defaultPos({-1, -1});

    for (int i = 0; map[i].size() != 0; i++) {
        for (int y = 0; map[i][y]; y++) {
            std::vector<int> pos({i, y});
            if (map[i][y] == 'E') return (pos);
        }
    }
    return (defaultPos); // throw error
}

std::vector<int> arc::game::Pacman::_getGhostBPos(std::vector<std::string> map)
{
    std::vector<int> defaultPos({-1, -1});

    for (int i = 0; map[i].size() != 0; i++) {
        for (int y = 0; map[i][y]; y++) {
            std::vector<int> pos({i, y});
            if (map[i][y] == 'B') return (pos);
        }
    }
    return (defaultPos); // throw error
}
std::vector<int> arc::game::Pacman::_getGhostRPos(std::vector<std::string> map)
{
    std::vector<int> defaultPos({-1, -1});

    for (int i = 0; map[i].size() != 0; i++) {
        for (int y = 0; map[i][y]; y++) {
            std::vector<int> pos({i, y});
            if (map[i][y] == 'R') return (pos);
        }
    }
    return (defaultPos); // throw error
}
void arc::game::Pacman::_getNbGum(std::vector<std::string> map)
{
    for (int i = 0; map[i].size() != 0; i++) {
        for (int y = 0; map[i][y]; y++) {
            if (map[i][y] == '.')
                this->nbGum += 1;
        }
    }
}

arc::GameMeta arc::game::Pacman::getMeta(void)
{
    return this->getData().get()->_meta;
}

std::tuple<arc::LibType, std::string> arc::game::Pacman::handleClick(arc::Coords coords)
{
    (void)coords;
    return (std::tuple<arc::LibType, std::string>(arc::NOLIB, "bg le github"));
}

void arc::game::Pacman::animate(arc::Tick tick, arc::TransEvent)
{
    this->setTick(this->_autoMove(tick));
}

extern "C" {
    std::unique_ptr<arc::game::IGame> getUniqueClass() {
        return std::make_unique<arc::game::Pacman>();
    }
}
