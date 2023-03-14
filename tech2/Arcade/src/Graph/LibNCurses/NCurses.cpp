/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** NCurses
*/

#include "NCurses.hpp"

arc::graph::NCurses::NCurses()
    : _win(nullptr)
    , _xSize(TERMINAL_X_SIZE)
    , _ySize(TERMINAL_Y_SIZE)
{
    // Nothing to do
}

arc::graph::NCurses::~NCurses()
{
    refresh();
    if (this->_win) {
        endwin();
        delwin(this->_win);
    }
}

arc::LibType arc::graph::NCurses::getSignature() const
{
    return (arc::GRAPH);
}

void arc::graph::NCurses::initGraph(std::map<char const, InfoObject> info, arc::GameMeta meta, std::vector<std::string> map)
{
    (void)map;
    (void)meta;
    this->_initMeta(meta);
    this->_initObject(info);
    this->_initKeyMap();
    if (initscr() == nullptr) {
        throw std::runtime_error("Error: initscr failed");
    }
    if ((this->_win = newwin(12, 25, 0, 0)) == nullptr) {
        throw std::runtime_error("Error: couldn't create new window in NCurses.");
    }
    cbreak();
    noecho();
    flushinp();
    timeout(0);
    mousemask(BUTTON1_CLICKED, nullptr);
    this->_initColors(info);
    curs_set(0);
}

void arc::graph::NCurses::_initMeta(arc::GameMeta gameMeta)
{
    (void) gameMeta;
}

void arc::graph::NCurses::_initColors(std::map<char const, arc::InfoObject> info)
{
    int i = info.size() + 2; // this is a awesome tricks
    start_color();
    this->_hasColors = has_colors();
    if (!this->_hasColors) return;
    std::map<char const, InfoObject>::iterator itrInfo = info.begin();
    for (; itrInfo != info.end(); ++itrInfo) {
        init_pair(itrInfo->first, i, i);
        --i;
    }
}

void arc::graph::NCurses::display(arc::Tick tick) const
{
    size_t height = tick._map.size();

    erase();
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; tick._map[y][x]; ++x) {
            if (tick._map[y][x] != ' ') {
                NCursesObject obj = this->_getGraphObject(tick._map[y][x]);
                if (this->_hasColors) attron(COLOR_PAIR(tick._map[y][x]));
                mvprintw(y * this->_ySize, x * this->_xSize, "%c%c", obj.meta.symbol, obj.meta.symbol);
                if (this->_hasColors) attroff(COLOR_PAIR(tick._map[y][x]));
            }
        }
    }
    refresh();
}

arc::TransEvent arc::graph::NCurses::getEvent() const
{
    int key = getch();
    if (key == KEY_MOUSE) {
        MEVENT event;
        if (getmouse(&event) == OK && event.bstate & BUTTON1_CLICKED) {
            // TODO:
        }
    }
    std::map<int, TransEvent>::const_iterator itr = this->_keyMap.find(key);

    if (itr == _keyMap.end()) {
        return (SPECIAL);
    }
    return (itr->second);
}

// ******************************** PRIVATE ********************************* //

void arc::graph::NCurses::_initObject(std::map<char const, arc::InfoObject> info)
{
    std::map<char const, InfoObject>::iterator itrInfo = info.begin();

    for (; itrInfo != info.end(); ++itrInfo) {
        MetaObjectNCurses meta;
        meta.state       = false;
        meta.rotation    = 0.0f;
        meta.orientation = (short)0;
        meta.symbol      = itrInfo->first;
        meta.color       = itrInfo->second.color;

        NCursesObject object(itrInfo->first, itrInfo->second, meta);
        this->_graphData[itrInfo->first] = std::make_shared<NCursesObject>(object);
    }
}

void arc::graph::NCurses::_initKeyMap()
{
    this->_keyMap = std::map<int, TransEvent>({
        { 65,  UP },             // [^]
        { 66,  DOWN },           // [v]
        { 68,  LEFT },           // [<]
        { 67,  RIGHT },          // [>]
        { 115, SPECIAL },        // S
        { 32,  PAUSE },          // SPACE
        { 126, CLOSE },          // SUPPR
        { 110, GRAPH_LIB_NEXT }, // N
        { 109, GAME_LIB_NEXT },  // M
        { 111, GRAPH_LIB_PREV }, // O
        { 112, GAME_LIB_PREV },  // P
        { 113, EXIT }            // Q

    });
}

arc::graph::NCursesObject arc::graph::NCurses::_getGraphObject(char const type) const
{
    try {
        return (*this->_graphData.at(type).get());
    } catch (std::out_of_range &e) {
        throw std::runtime_error("Error: object not found");
    }
}

arc::Coords const arc::graph::NCurses::getMousePos()
{
    return (arc::Coords(0, 0));
}

extern "C" {
    std::unique_ptr<arc::graph::IGraph> getUniqueClass() {
        return std::make_unique<arc::graph::NCurses>();
    }
}
