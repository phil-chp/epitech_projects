/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** SDL
*/

#include "SDL.hpp"

arc::graph::SDL::SDL()
    : _pad(32)
    , _window(nullptr)
    , _renderer(nullptr)
    , _graphData({})
    , _metaData({})
    , _keyMap({})
    , _meta({})
{
}

arc::graph::SDL::~SDL()
{
    if (this->_renderer) {
        SDL_DestroyRenderer(this->_renderer);
    }
    if (this->_window) {
        SDL_DestroyWindow(this->_window);
    }
    // this
    SDL_Quit();
}

arc::LibType arc::graph::SDL::getSignature() const
{
    return (arc::GRAPH);
}

void arc::graph::SDL::initGraph(
    std::map<char const, arc::InfoObject> info,
    arc::GameMeta meta,
    std::vector<std::string> map
) {
    SDL_Init(SDL_INIT_VIDEO);
    this->_window = SDL_CreateWindow(
        "window",

        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        (map[0].length() * meta.pad),
        (map.size() * meta.pad),
        SDL_WINDOW_SHOWN
    );

    if (_window == nullptr) {
        throw std::runtime_error("Couldn't open SDL window");
    }
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 255);
    this->_initMeta(meta);
    this->_initObject(info);
    this->initKeyMap();
}

void arc::graph::SDL::_initMeta(arc::GameMeta gameMeta)
{
    this->_metaData.clear();
    this->_meta.pad = gameMeta.pad;
    this->_meta.isMenu = gameMeta.isMenu;
    if (gameMeta.bg.size() != 0) {
        // TODO: auto is not allowed, add correct type with ::iterator
        for (auto &elem : gameMeta.bg) {
            arc::graph::MetaObjectSDL meta;
            meta.color = SDL_Color{255, 255, 255, 255};
            meta.animate = 0;
            meta.state = true;
            meta.rotation = 0.0f;
            meta.orientation = 0;
            meta.width = 1000;
            meta.height = 700;
            meta.rect = {0, 0, 1000, 700 };
            meta.surface = nullptr;
            meta.texture = nullptr;
            arc::graph::SDLObject object(elem, this->_renderer, meta);
            this->_metaData[elem] = std::make_shared<SDLObject>(object);
            this->_meta.bg.push_back(elem);
        }
    }
}

void arc::graph::SDL::_initObject(std::map<char const, arc::InfoObject> info)
{
    std::map<char const, InfoObject>::iterator itrInfo = info.begin();

    this->_graphData.clear();
    for (; itrInfo != info.end(); ++itrInfo) {
        arc::graph::MetaObjectSDL meta;
        meta.color = SDL_Color{255, 255, 255, 255};
        meta.animate = 0;
        meta.state = true;
        meta.rotation = 0.0f;
        meta.orientation = 0;
        meta.width = this->_meta.pad ;
        meta.height = this->_meta.pad ;
        meta.rect = {0, 0, this->_meta.pad , this->_meta.pad };
        meta.surface = nullptr;
        meta.texture = nullptr;
        arc::graph::SDLObject object(itrInfo->second.spritePath, this->_renderer, meta);
        this->_graphData[itrInfo->first] = (std::make_shared<SDLObject>(object));
    }
}

void arc::graph::SDL::initKeyMap()
{
    this->_keyMap = std::map<SDL_Keycode, TransEvent>({
        { SDLK_UP,  UP},            // [^]
        { SDLK_DOWN, DOWN },        // [v]
        { SDLK_LEFT, LEFT },        // [<]
        { SDLK_RIGHT, RIGHT },      // [>]
        { SDLK_s,  SPECIAL},        // S
        { SDLK_SPACE, PAUSE},       // [SPACE]
        { SDLK_DELETE, CLOSE},      // [SUPPR]
        { SDLK_n, GRAPH_LIB_NEXT},  // N
        { SDLK_m, GAME_LIB_NEXT},   // P
        { SDLK_o, GRAPH_LIB_PREV }, // O
        { SDLK_p, GAME_LIB_PREV },  // P
        { SDLK_q, EXIT }            // Q
    });
}

arc::Coords const arc::graph::SDL::getMousePos()
{
    arc::Coords coords;
    int x, y;

    SDL_GetMouseState(&x, &y);
    coords.x = (x - x % this->_meta.pad) / this->_meta.pad;
    coords.y = (y - y % this->_meta.pad) / this->_meta.pad;
    return (coords);
}

void arc::graph::SDL::animateObject(arc::graph::SDLObject &obj) const
{
    obj.meta.animate += 1;
    if (obj.meta.animate > 2)
        obj.meta.animate = 0;
    obj.meta.rect.x = this->_pad * obj.meta.animate;
}

void arc::graph::SDL::display(arc::Tick tick) const
{
    size_t height = tick._map.size();
    int ysize = 0;
    int xsize = 0;

    SDL_RenderClear(this->_renderer);
    if (this->_meta.bg.size() != 0) {
        for (std::string const &elem : this->_meta.bg) {
            arc::graph::SDLObject obj(this->getMetaObject(elem));
            SDL_Rect rect({ 0, 0, obj.meta.width, obj.meta.height });
            SDL_RenderCopy(this->_renderer, obj.meta.texture, &rect, &obj.meta.rect);
        }
    }


    for (size_t x = 0; x < height; ++x, ysize += this->_meta.pad) {
        for (size_t y = 0; tick._map[x][y]; ++y, xsize += this->_meta.pad) {
            if (tick._map[x][y]== ' ') continue;
            arc::graph::SDLObject obj(this->getGraphObject(tick._map[x][y]));
            SDL_Rect rect({ xsize, ysize, obj.meta.width, obj.meta.height });
            SDL_RenderCopy(this->_renderer, obj.meta.texture, &obj.meta.rect, &rect);
        }
        xsize = 0;
    }
    SDL_RenderPresent(this->_renderer);
}

arc::graph::SDLObject arc::graph::SDL::getGraphObject(char const type) const
{
    try {
        return (*this->_graphData.at(type).get());
    } catch (std::out_of_range &e) {
        throw std::runtime_error("GraphObject could not be getted");
    }
}

arc::graph::SDLObject arc::graph::SDL::getMetaObject(std::string const type) const
{
    try {
        return (*this->_metaData.at(type).get());
    } catch (std::out_of_range &e) {
        throw std::runtime_error("GraphObject could not be getted");
    }
}

arc::TransEvent arc::graph::SDL::getEvent() const
{
    std::map<SDL_Keycode, TransEvent>::const_iterator itr;
    SDL_Event event;

    // ------------------------------------ //
    int x, y;
    SDL_PumpEvents();
    if ((SDL_GetMouseState(&x, &y) & SDL_BUTTON_LMASK) != 0) {
        return (arc::MOUSE_LEFT_CLICK);
    }
    // ------------------------------------//

    SDL_PollEvent(&event);
    if (this->_meta.isMenu == false && event.type == SDL_KEYDOWN) {
        itr = this->_keyMap.find(event.key.keysym.sym);
        if (itr == _keyMap.end()) return (arc::SPECIAL);
        return (itr->second);
    } else if (event.type == SDL_WINDOWEVENT) {
        if (event.window.event == SDL_WINDOWEVENT_CLOSE) return (arc::CLOSE);
    }
    return (arc::SPECIAL);
}

extern "C" {
    std::unique_ptr<arc::graph::IGraph> getUniqueClass() {
        return std::make_unique<arc::graph::SDL>();
    }
}
