/*
** EPITECH PROJECT, 2022
** Arcade (Workspace)
** File description:
** Core
*/

#include "Core/Core.hpp"

arc::core::Core::Core()
    : _game(nullptr), _graph(nullptr)
{
    // nothing to do here
}

arc::core::Core::Core(std::string graphPath)
    : _game(nullptr), _graph(nullptr)
{
    this->_Clock = std::make_unique<arc::Clock>();
    this->_Switcher = std::make_unique<Switcher>("./lib/arcade_menu.so", graphPath);
}

arc::core::Core::~Core()
{
    // Nothing to do here
}

void arc::core::Core::_initCore(void)
{
    this->_refreshLibrary(arc::GAME);
    this->_refreshLibrary(arc::GRAPH);
}

void arc::core::Core::_refreshGame()
{
    std::unique_ptr<arc::game::IGame> (*__generateGame__)() =   \
        (std::unique_ptr<arc::game::IGame>(*)())dlsym(this->_Switcher->loadLib(arc::GAME)->get(), GET_UNIQUE_CLASS);
    this->_game = __generateGame__();
    this->_game->initGame();
}

void arc::core::Core::_refreshGraph()
{
    std::unique_ptr<arc::graph::IGraph> (*__generateGraph__)() =    \
        (std::unique_ptr<arc::graph::IGraph>(*)())dlsym(this->_Switcher->loadLib(arc::GRAPH)->get(), GET_UNIQUE_CLASS);

    this->_graph = __generateGraph__();
    arc::Tick tick(this->_game->getTick());
    arc::GameMeta meta = this->_game->getMeta();
    this->_graph->initGraph(this->_game->getDic(), meta, tick._map);
}

void arc::core::Core::_refreshLibrary(arc::LibType type)
{
    switch (type) {
        case arc::GAME:
            this->_refreshGame();
            break;
        case arc::GRAPH:
            this->_refreshGraph();
            break;
        default:
            throw new std::runtime_error("Unknown library type");
    }
}

void arc::core::Core::_handleMenuClick(void)
{
    arc::Coords coords = this->_graph->getMousePos();
    std::tuple<arc::LibType, std::string> libInfo = this->_game->handleClick(coords);

    if (std::get<0>(libInfo) != arc::LibType::NOLIB) {
        this->_Switcher->setLib(std::get<0>(libInfo), std::get<1>(libInfo));
        if (std::get<0>(libInfo) == arc::GAME)
            this->_refreshLibrary(arc::GAME);
        this->_refreshLibrary(arc::GRAPH);
    }
}

void arc::core::Core::_handleLibrary(arc::TransEvent event)
{
    switch (event) {
        case arc::GRAPH_LIB_NEXT:
            this->_Switcher->switchLib(arc::GRAPH);
            this->_refreshLibrary(arc::GRAPH);
            break;
        case arc::GRAPH_LIB_PREV:
            this->_Switcher->switchLib(arc::GRAPH);
            this->_refreshLibrary(arc::GRAPH);
            break;
        case arc::GAME_LIB_NEXT:
            this->_Switcher->switchLib(arc::GAME);
            this->_refreshLibrary(arc::GAME);
            break;
        case arc::GAME_LIB_PREV:
            this->_Switcher->switchLib(arc::GAME);
            break;
        case arc::MOUSE_LEFT_CLICK:
            this->_handleMenuClick();
            break;
        case arc::EXIT:
            this->_Switcher->setLib(arc::LibType::GAME, "./lib/arcade_menu.so");
            this->_Switcher->setLib(arc::LibType::GRAPH, "./lib/arcade_sdl2.so");
            this->_refreshLibrary(arc::GAME);
            this->_refreshLibrary(arc::GRAPH);
            break;
        default:
            break;
    }
}

void arc::core::Core::run(void)
{
    arc::TransEvent event = arc::TransEvent::SPECIAL;
    this->_initCore();
    int i = 0;

    while (event != arc::TransEvent::CLOSE) {
        arc::Tick tick = this->_game->getTick();
        this->_game->simulate(tick, event);
        if (this->_Clock->isCycleDone(true)) {
            this->_game->animate(tick, event);
        }
        this->_graph->display(this->_game->getTick()._map);
        event = this->_graph->getEvent();
        this->_handleLibrary(event);
        i += 1;
    }
}
