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

#include "Snake.hpp"

arc::game::Snake::Snake()
{
    // nothing to do
}

void arc::game::Snake::initGame(void) {

    SnakeData data;

    data._tick._map.push_back("#####################");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#                   #");
    data._tick._map.push_back("#####################");

    data._dic = {
            {'#', arc::InfoObject("Assets/sprite/wall.bmp", Color(255, 0, 0))},
            {'H', arc::InfoObject("Assets/sprite/player.bmp", Color(0, 255, 0))},
            {'B', arc::InfoObject("Assets/sprite/enemy.bmp", Color(0, 0, 255))},
            {'A', arc::InfoObject("Assets/sprite/blue.bmp", Color(255, 255, 0))},
    };

    data._meta.bg.push_back("Assets/Menu/bg/s1.bmp");
    data._meta.isMenu = false;
    data._meta.pad = 32;

    arc::game::SnakeConfig config;
    std::shared_ptr<arc::game::SnakeConfig> config_ptr(new arc::game::SnakeConfig(config));
    this->setConfig(config_ptr);

    std::shared_ptr<arc::game::SnakeData> data_ptr(new arc::game::SnakeData(data));
    this->setData(data_ptr);
}

arc::game::Snake::~Snake()
{
    // nothing to do
}


arc::Tick arc::game::Snake::getTick(void)
{
    return this->getData().get()->_tick;
}

void arc::game::Snake::setTick(arc::Tick tick)
{
    SnakeData *data = this->getData().get();
    data->_tick = tick;
}

std::map<char const, arc::InfoObject> arc::game::Snake::getDic(void)
{
    return this->getData().get()->_dic;
}

void arc::game::Snake::setDic(std::map<char const, arc::InfoObject> dic)
{
    SnakeData *data = this->getData().get();
    data->_dic = dic;
}

arc::LibType arc::game::Snake::getSignature() const
{
    return (arc::GAME);
}

void arc::game::Snake::simulate(arc::Tick tick, arc::TransEvent event)
{
    if (event == arc::UP   || event == arc::DOWN   \
    ||  event == arc::LEFT || event == arc::RIGHT) {
        this->setTick(this->_applyEvent(tick, event));
    }
}

// -------------------------------- Private --------------------------------- //

arc::Tick arc::game::Snake::_applyEvent(arc::Tick tick, arc::TransEvent event)
{
    if (event < arc::SPECIAL) {
        return (this->_move(tick, event));
    }
    // if (event == SPECIAL)
    return (tick); // nothing for now
}

arc::Tick arc::game::Snake::_move(Tick tick, TransEvent event) {

    switch (event) {
        case arc::UP:
            this->prevmov = 0;
            return (this->_applyMoveBody(tick));
        case (arc::DOWN):
            this->prevmov = 2;
            return (this->_applyMoveBody(tick));
        case (arc::LEFT):
            this->prevmov = 3;
            return (this->_applyMoveBody(tick));
        case (arc::RIGHT):
            this->prevmov = 1;
            return (this->_applyMoveBody(tick));
        default:
            return (tick);
    }
}

struct snake {
    int x = 5, y = 5;
}s[100];

struct apple {
    int x = rand() % 8, y = rand() % 8;
}a;

void arc::game::Snake::setFinish(bool flag)
{
    SnakeConfig *config = this->getConfig().get();
    config->isFinish = flag;
}

arc::Tick arc::game::Snake::_applyMoveBody(Tick tick) {

    if (this->test) {
        std::vector<int> playerPos = this->_getPlayerPos(tick._map);
    }
    tick._map[s[this->len - 1].x][s[this->len - 1].y] = ' ';
    srand((unsigned)time(0));

    if (this->test == 0) {
        tick._map[a.x][a.y] = 'A';
        this->test += 1;
        this->nbApple += 1;
    }
    if (s[0].y == 0 || s[0].y == (int)tick._map[0].length() - 1
        || s[0].x == 0 || s[0].x == (int)tick._map.size() - 1
        || s[0].x == 'B' || s[0].y == 'B') {
        this->setFinish(true);
        exit(84);
    }
    for (int i = this->len; i > 0 ; i--) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    switch (this->prevmov) {
        case 0:
            s[0].x -= 1;
            break;
        case 1:
            s[0].y += 1;
            break;
        case 2:
            s[0].x += 1;
            break;
        case 3:
            s[0].y -= 1;
            break;
    }

    for (int i = 0; i < this->len; ++i) {
        if (i == 0)
            tick._map[s[i].x][s[i].y] = 'H';
        else
            tick._map[s[i].x][s[i].y] = 'B';

    }

    if (this->nbApple != 0) {
        if (s[0].x == a.x && s[0].y == a.y) {
            this->len += 1;
            this->score += 1;
            this->nbApple -= 1;

            int lenx = tick._map.size() - 4;
            int leny = tick._map[0].length() - 4;
            toto:
            a.x = (rand() % (lenx - 1 + 1 )) + 1;
            a.y = (rand() % (leny - 1 + 1 )) + 1;

            for (int i = 0; i < this->len; ++i) {
                if (a.y == s[i].y && a.x == s[i].x) {
                    goto toto;
                }
            }

            tick._map[a.x][a.y] = 'A';
            this->nbApple += 1;
        }
    }
    if (s[0].x == '#' || s[0].y == '#')
        exit(0);

    return (tick);
}

arc::Tick arc::game::Snake::_autoMove(Tick tick) {
    if (this->test) {
        std::vector<int> playerPos = this->_getPlayerPos(tick._map);
    }
    switch (this->prevmov) {
        case 0:
            return (this->_applyMoveBody(tick));
        case 1:
            return (this->_applyMoveBody(tick));
        case 2:
            return (this->_applyMoveBody(tick));
        case 3:
            return (this->_applyMoveBody(tick));
        default:
            return (tick);
    }
}

std::vector<int> arc::game::Snake::_getPlayerPos(std::vector<std::string> map)
{
    std::vector<int> defaultPos({-1, -1});

    for (int i = 0; map[i].size() != 0; i++) {
        for (int y = 0; map[i][y]; y++) {
            std::vector<int> pos({i, y});
            if (map[i][y] == 'H') return (pos);
        }
    }
    return (defaultPos); // throw error
}

void arc::game::Snake::_getNbApple(std::vector<std::string> map)
{
    for (int i = 0; map[i].size() != 0; i++) {
        for (int y = 0; map[i][y]; y++) {
            std::vector<int> pos({i, y});
            if (map[i][y] == 'A')
                this->nbApple += 1;
        }
    }
}

arc::GameMeta arc::game::Snake::getMeta(void)
{
    return this->getData().get()->_meta;
}

std::tuple<arc::LibType, std::string> arc::game::Snake::handleClick(arc::Coords coords)
{
    (void)coords;
    return (std::tuple<arc::LibType, std::string>(arc::NOLIB, "bg le github"));
}

void arc::game::Snake::animate(arc::Tick tick , arc::TransEvent)
{
    this->setTick(this->_autoMove(tick));
}

extern "C" {
    std::unique_ptr<arc::game::IGame> getUniqueClass() {
        return std::make_unique<arc::game::Snake>();
    }
}
