/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "Shared/Color.hpp"
#include <iostream>
#include <vector>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

namespace arc
{
    /**
     * @brief
     * Tick
     * Contain all the logic of the game, when you simulate a tick...
     */
    struct Tick {
        Tick() {};
        Tick(std::vector<std::string> map) : _map(map) {};
        std::vector<std::string> _map;
    };

    /**
     * @brief
     *
     */
    enum LibType {
        NOLIB = -1,
        GAME,
        GRAPH,
        MENU,
    };

    /**
     * @brief
     * TransEvent
     * Description: Contain all input, event, user interraction
     */

    enum Choice {
        PREV = -1,
        NEXT = 1
    };

    enum TransEvent {
        NONE = -1,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SPECIAL,
        PAUSE,
        CLOSE,
        GRAPH_LIB_NEXT,
        GAME_LIB_NEXT,
        GRAPH_LIB_PREV,
        GAME_LIB_PREV,
        MOUSE_LEFT_CLICK,
        EXIT
    };

    /**
     * @brief
     * GraphConfig
     * Description: define with @AL @QR @AG
     * may contain all the game graphique conf
     */
    struct GraphConfig {
        // nothing to do
    };
    /**
     * @brief coord of a point (mouse fro instance)
     */
    struct Coords {
        Coords()                        : x(0),      y(0)      {};
        Coords(int copyX, int copyY)    : x(copyX),  y(copyY)  {};
        Coords(arc::Coords const &copy) : x(copy.x), y(copy.y) {};
        arc::Coords &operator=(arc::Coords const &copy) {
            x = copy.x;
            y = copy.y;
            return *this;
        }
        int x;
        int y;
    };

    struct GameMeta {
        GameMeta()
            : isMenu(false)
            , bg({})
            , pad(0)
        {};
        GameMeta(arc::GameMeta const &copy)
            : isMenu(copy.isMenu)
            , bg(copy.bg)
            , pad(copy.pad)
        {};
        arc::GameMeta &operator=(arc::GameMeta const &copy) {
            isMenu = copy.isMenu;
            bg     = copy.bg;
            pad    = copy.pad;
            return (*this);
        };

        bool isMenu;
        std::vector<std::string> bg;
        int pad;
    };

    /**
     * @brief
     *
     */
    struct InfoObject {
        InfoObject(std::string path, arc::Color color)
            : spritePath(path), color(0, 0, 0)
        {
            (void)color;
        };
        std::string spritePath;
        arc::Color color;
    };

# define MOVE_LEFT   (std::vector<int> {0, -1})
# define MOVE_RIGHT  (std::vector<int> {0,  1})
# define MOVE_UP     (std::vector<int> {-1, 0})
# define MOVE_DOWN   (std::vector<int> {1,  0})


# define DEFAULT_MENU_PATH  ("./lin/arcade_menu.so")
# define DEFAULT_LIB_PATH   ("./build/lib/")
# define GET_UNIQUE_CLASS   ("getUniqueClass")

}

#endif /* !ARCADE_HPP_ */
