/*
** EPITECH PROJECT, 2022
** ARCADE
** authored by:
**      Vitali DROUJKO  <vitali.droujko@epitech.eu>
**      Pierre PLASSIO  <pierre.plassio@epitech.eu>
**      Philippe CHEYPE <philippe.cheype@epitech.eu>
** File description:
** SFML
*/

#include "SFML.hpp"

arc::graph::SFML::SFML()
    : _pad(32)
    , _window(nullptr)
    , _graphData({})
    , _metaData({})
    , _keyMap({})
    , _meta({})
{
}

arc::graph::SFML::~SFML()
{
    if (this->_window) {
        this->_window->close();
        delete this->_window;
    }
}

void arc::graph::SFML::initGraph(
    std::map<char const, arc::InfoObject> info,
    arc::GameMeta meta,
    std::vector<std::string> map)
{
    this->_pad = meta.pad;
    sf::VideoMode mode((map[0].length() * meta.pad), (map.size() * meta.pad));
    this->_window = new sf::RenderWindow(mode, "window");

    if (this->_window == nullptr) {
        throw std::runtime_error("Couldn't open SFML window");
    }
    this->_initMeta(meta);
    this->_initObject(info);
    this->initKeyMap();
}

void arc::graph::SFML::_initMeta(arc::GameMeta gameMeta)
{
    this->_metaData.clear();
    this->_meta.pad = gameMeta.pad;
    if (gameMeta.bg.size() != 0) {
        // TODO: auto is not allowed, add correct type with ::iterator
        for (auto &elem : gameMeta.bg) {
            arc::graph::MetaObjectSFML meta;
            meta.color = sf::Color({255, 255, 255, 255});
            meta.animate = 0;
            meta.state = true;
            meta.rotation = 0.0f;
            meta.orientation = 0;
            meta.width = 600;
            meta.height = 800;
            if (meta.texture == nullptr) {
                throw std::runtime_error("Couldn't open SFML texture");
            }
            arc::graph::SFMLObject object(elem, this->_window, meta);

        }
        this->_meta.isMenu = gameMeta.isMenu;
    }
}

void arc::graph::SFML::_initObject(std::map<char const, arc::InfoObject> info)
{
    std::map<char const, InfoObject>::iterator itrInfo = info.begin();

    this->_graphData.clear();
    for (; itrInfo != info.end(); ++itrInfo) {
        arc::graph::MetaObjectSFML meta;
        meta.color = sf::Color({255, 255, 255, 255});
        meta.animate = 0;
        meta.state = true;
        meta.rotation = 0.0f;
        meta.orientation = 0;
        meta.width = this->_meta.pad;
        meta.height = this->_meta.pad;
        meta.texture = nullptr;

        arc::graph::SFMLObject object(itrInfo->second.spritePath, this->_window, meta);
        this->_graphData[itrInfo->first] = std::make_shared<SFMLObject>(object);
    }
}

void arc::graph::SFML::initKeyMap()
{
    this->_keyMap = std::map<sf::Keyboard::Key, TransEvent>({
        { sf::Keyboard::Up,  UP},            // [^]
        { sf::Keyboard::Down, DOWN },        // [v]
        { sf::Keyboard::Left, LEFT },        // [<]
        { sf::Keyboard::Right, RIGHT },      // [>]
        { sf::Keyboard::S,  SPECIAL},        // S
        { sf::Keyboard::Space, PAUSE},       // SPACE
        { sf::Keyboard::Delete, CLOSE},      // SUPPR
        { sf::Keyboard::N, GRAPH_LIB_NEXT},  // N
        { sf::Keyboard::P, GAME_LIB_NEXT},   // P
        { sf::Keyboard::O, GRAPH_LIB_PREV }, // O
        { sf::Keyboard::P, GAME_LIB_PREV },  // P
        { sf::Keyboard::Q, EXIT }            // Q
    });
}

arc::Coords const arc::graph::SFML::getMousePos()
{
    arc::Coords coords;
    sf::Vector2i vector (sf::Mouse::getPosition());
    coords.x = (vector.x - vector.x % this->_pad) / this->_pad;
    coords.y = (vector.y - vector.y % this->_pad) / this->_pad - 2;
    return (coords);
}

void arc::graph::SFML::animateObject(arc::graph::SFMLObject &obj) const
{
    (void)obj;
    // obj.meta.animate += 1;
    // if (obj.meta.animate > 2)
    //     obj.meta.animate = 0;
    // obj.meta.rect.setTexture = this->_meta.pad * obj.meta.animate;
}

void arc::graph::SFML::display(arc::Tick tick) const
{
    size_t height = tick._map.size();
    int ysize = 0;
    int xsize = 0;

    this->_window->clear(sf::Color::Black);
    if (this->_meta.bg.size() != 0) {
        for (std::string const &elem : this->_meta.bg) {
            arc::graph::SFMLObject obj(this->getMetaObject(elem));
            this->_window->draw(obj.meta.sprite);
        }
    }

    for (size_t x = 0; x < height; ++x, ysize += this->_meta.pad) {
        for (size_t y = 0; tick._map[x][y]; ++y, xsize += this->_meta.pad) {
            if (tick._map[x][y]== ' ') continue;
            arc::graph::SFMLObject obj(this->getGraphObject(tick._map[x][y]));
            obj.meta.sprite.setPosition(xsize, ysize);
            obj.meta.sprite.setColor(sf::Color::White);
            this->_window->draw(obj.meta.sprite);
        }
        xsize = 0;
    }
    this->_window->display();
}

arc::graph::SFMLObject arc::graph::SFML::getGraphObject(char const type) const
{
    try {
        return (*this->_graphData.at(type).get());
    } catch (std::out_of_range &e) {
        throw std::runtime_error("GraphObject could not be getted");
    }
}

arc::graph::SFMLObject arc::graph::SFML::getMetaObject(std::string const type) const
{
    try {
        return (*this->_metaData.at(type).get());
    } catch (std::out_of_range &e) {
        throw std::runtime_error("GraphObject could not be getted");
    }
}

arc::LibType arc::graph::SFML::getSignature() const
{
    return (arc::GRAPH);
}

arc::TransEvent arc::graph::SFML::getEvent() const
{
    std::map<sf::Keyboard::Key, TransEvent>::const_iterator itr;
    sf::Event event;

    sf::Vector2i vector (sf::Mouse::getPosition());
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return (arc::MOUSE_LEFT_CLICK);
    }

    this->_window->pollEvent(event);
    if (this->_meta.isMenu == false && event.type == sf::Event::KeyPressed) {
        itr = this->_keyMap.find(event.key.code);
        if (itr == _keyMap.end()) return (arc::SPECIAL);
        return (itr->second);
    } else if (event.type == sf::Event::Closed) {
        return (arc::CLOSE);
    }
    return (arc::SPECIAL);
}

extern "C" {
    std::unique_ptr<arc::graph::IGraph> getUniqueClass() {
        return std::make_unique<arc::graph::SFML>();
    }
}
